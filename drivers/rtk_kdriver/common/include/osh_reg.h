/**
* @file rbusOshReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OSH_REG_H_
#define _RBUS_OSH_REG_H_

#include "rbus_types.h"



//  OSH Register Address
#define  OSH_OSD_SPLIT_HEADER_EN                                                 0x18029800
#define  OSH_OSD_SPLIT_HEADER_EN_reg_addr                                        "0xB8029800"
#define  OSH_OSD_SPLIT_HEADER_EN_reg                                             0xB8029800
#define  OSH_OSD_SPLIT_HEADER_EN_inst_addr                                       "0x0000"
#define  set_OSH_OSD_SPLIT_HEADER_EN_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_EN_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_EN_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_EN_reg))
#define  OSH_OSD_SPLIT_HEADER_EN_header_h_sta_shift                              (16)
#define  OSH_OSD_SPLIT_HEADER_EN_header_en_shift                                 (0)
#define  OSH_OSD_SPLIT_HEADER_EN_header_h_sta_mask                               (0x1FFF0000)
#define  OSH_OSD_SPLIT_HEADER_EN_header_en_mask                                  (0x00000001)
#define  OSH_OSD_SPLIT_HEADER_EN_header_h_sta(data)                              (0x1FFF0000&((data)<<16))
#define  OSH_OSD_SPLIT_HEADER_EN_header_en(data)                                 (0x00000001&(data))
#define  OSH_OSD_SPLIT_HEADER_EN_get_header_h_sta(data)                          ((0x1FFF0000&(data))>>16)
#define  OSH_OSD_SPLIT_HEADER_EN_get_header_en(data)                             (0x00000001&(data))

#define  OSH_OSD_SPLIT_empty_pixel                                               0x18029804
#define  OSH_OSD_SPLIT_empty_pixel_reg_addr                                      "0xB8029804"
#define  OSH_OSD_SPLIT_empty_pixel_reg                                           0xB8029804
#define  OSH_OSD_SPLIT_empty_pixel_inst_addr                                     "0x0001"
#define  set_OSH_OSD_SPLIT_empty_pixel_reg(data)                                 (*((volatile unsigned int*)OSH_OSD_SPLIT_empty_pixel_reg)=data)
#define  get_OSH_OSD_SPLIT_empty_pixel_reg                                       (*((volatile unsigned int*)OSH_OSD_SPLIT_empty_pixel_reg))
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_a_shift                            (24)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_r_shift                            (16)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_g_shift                            (8)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_b_shift                            (0)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_a_mask                             (0xFF000000)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_r_mask                             (0x00FF0000)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_g_mask                             (0x0000FF00)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_b_mask                             (0x000000FF)
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_a(data)                            (0xFF000000&((data)<<24))
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_r(data)                            (0x00FF0000&((data)<<16))
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_g(data)                            (0x0000FF00&((data)<<8))
#define  OSH_OSD_SPLIT_empty_pixel_data_empty_b(data)                            (0x000000FF&(data))
#define  OSH_OSD_SPLIT_empty_pixel_get_data_empty_a(data)                        ((0xFF000000&(data))>>24)
#define  OSH_OSD_SPLIT_empty_pixel_get_data_empty_r(data)                        ((0x00FF0000&(data))>>16)
#define  OSH_OSD_SPLIT_empty_pixel_get_data_empty_g(data)                        ((0x0000FF00&(data))>>8)
#define  OSH_OSD_SPLIT_empty_pixel_get_data_empty_b(data)                        (0x000000FF&(data))

#define  OSH_OSD_SPLIT_HEADER_00                                                 0x18029810
#define  OSH_OSD_SPLIT_HEADER_00_reg_addr                                        "0xB8029810"
#define  OSH_OSD_SPLIT_HEADER_00_reg                                             0xB8029810
#define  OSH_OSD_SPLIT_HEADER_00_inst_addr                                       "0x0002"
#define  set_OSH_OSD_SPLIT_HEADER_00_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_00_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_00_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_00_reg))
#define  OSH_OSD_SPLIT_HEADER_00_header0_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_00_header0_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_00_header0(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_00_get_header0(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_01                                                 0x18029814
#define  OSH_OSD_SPLIT_HEADER_01_reg_addr                                        "0xB8029814"
#define  OSH_OSD_SPLIT_HEADER_01_reg                                             0xB8029814
#define  OSH_OSD_SPLIT_HEADER_01_inst_addr                                       "0x0003"
#define  set_OSH_OSD_SPLIT_HEADER_01_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_01_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_01_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_01_reg))
#define  OSH_OSD_SPLIT_HEADER_01_header1_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_01_header1_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_01_header1(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_01_get_header1(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_02                                                 0x18029818
#define  OSH_OSD_SPLIT_HEADER_02_reg_addr                                        "0xB8029818"
#define  OSH_OSD_SPLIT_HEADER_02_reg                                             0xB8029818
#define  OSH_OSD_SPLIT_HEADER_02_inst_addr                                       "0x0004"
#define  set_OSH_OSD_SPLIT_HEADER_02_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_02_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_02_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_02_reg))
#define  OSH_OSD_SPLIT_HEADER_02_header2_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_02_header2_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_02_header2(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_02_get_header2(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_03                                                 0x1802981C
#define  OSH_OSD_SPLIT_HEADER_03_reg_addr                                        "0xB802981C"
#define  OSH_OSD_SPLIT_HEADER_03_reg                                             0xB802981C
#define  OSH_OSD_SPLIT_HEADER_03_inst_addr                                       "0x0005"
#define  set_OSH_OSD_SPLIT_HEADER_03_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_03_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_03_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_03_reg))
#define  OSH_OSD_SPLIT_HEADER_03_header3_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_03_header3_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_03_header3(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_03_get_header3(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_04                                                 0x18029820
#define  OSH_OSD_SPLIT_HEADER_04_reg_addr                                        "0xB8029820"
#define  OSH_OSD_SPLIT_HEADER_04_reg                                             0xB8029820
#define  OSH_OSD_SPLIT_HEADER_04_inst_addr                                       "0x0006"
#define  set_OSH_OSD_SPLIT_HEADER_04_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_04_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_04_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_04_reg))
#define  OSH_OSD_SPLIT_HEADER_04_header4_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_04_header4_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_04_header4(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_04_get_header4(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_05                                                 0x18029824
#define  OSH_OSD_SPLIT_HEADER_05_reg_addr                                        "0xB8029824"
#define  OSH_OSD_SPLIT_HEADER_05_reg                                             0xB8029824
#define  OSH_OSD_SPLIT_HEADER_05_inst_addr                                       "0x0007"
#define  set_OSH_OSD_SPLIT_HEADER_05_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_05_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_05_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_05_reg))
#define  OSH_OSD_SPLIT_HEADER_05_header5_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_05_header5_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_05_header5(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_05_get_header5(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_06                                                 0x18029828
#define  OSH_OSD_SPLIT_HEADER_06_reg_addr                                        "0xB8029828"
#define  OSH_OSD_SPLIT_HEADER_06_reg                                             0xB8029828
#define  OSH_OSD_SPLIT_HEADER_06_inst_addr                                       "0x0008"
#define  set_OSH_OSD_SPLIT_HEADER_06_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_06_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_06_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_06_reg))
#define  OSH_OSD_SPLIT_HEADER_06_header6_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_06_header6_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_06_header6(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_06_get_header6(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_07                                                 0x1802982C
#define  OSH_OSD_SPLIT_HEADER_07_reg_addr                                        "0xB802982C"
#define  OSH_OSD_SPLIT_HEADER_07_reg                                             0xB802982C
#define  OSH_OSD_SPLIT_HEADER_07_inst_addr                                       "0x0009"
#define  set_OSH_OSD_SPLIT_HEADER_07_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_07_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_07_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_07_reg))
#define  OSH_OSD_SPLIT_HEADER_07_header7_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_07_header7_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_07_header7(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_07_get_header7(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_08                                                 0x18029830
#define  OSH_OSD_SPLIT_HEADER_08_reg_addr                                        "0xB8029830"
#define  OSH_OSD_SPLIT_HEADER_08_reg                                             0xB8029830
#define  OSH_OSD_SPLIT_HEADER_08_inst_addr                                       "0x000A"
#define  set_OSH_OSD_SPLIT_HEADER_08_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_08_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_08_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_08_reg))
#define  OSH_OSD_SPLIT_HEADER_08_header8_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_08_header8_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_08_header8(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_08_get_header8(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_09                                                 0x18029834
#define  OSH_OSD_SPLIT_HEADER_09_reg_addr                                        "0xB8029834"
#define  OSH_OSD_SPLIT_HEADER_09_reg                                             0xB8029834
#define  OSH_OSD_SPLIT_HEADER_09_inst_addr                                       "0x000B"
#define  set_OSH_OSD_SPLIT_HEADER_09_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_09_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_09_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_09_reg))
#define  OSH_OSD_SPLIT_HEADER_09_header9_shift                                   (0)
#define  OSH_OSD_SPLIT_HEADER_09_header9_mask                                    (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_09_header9(data)                                   (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_09_get_header9(data)                               (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_10                                                 0x18029838
#define  OSH_OSD_SPLIT_HEADER_10_reg_addr                                        "0xB8029838"
#define  OSH_OSD_SPLIT_HEADER_10_reg                                             0xB8029838
#define  OSH_OSD_SPLIT_HEADER_10_inst_addr                                       "0x000C"
#define  set_OSH_OSD_SPLIT_HEADER_10_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_10_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_10_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_10_reg))
#define  OSH_OSD_SPLIT_HEADER_10_header10_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_10_header10_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_10_header10(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_10_get_header10(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_11                                                 0x1802983C
#define  OSH_OSD_SPLIT_HEADER_11_reg_addr                                        "0xB802983C"
#define  OSH_OSD_SPLIT_HEADER_11_reg                                             0xB802983C
#define  OSH_OSD_SPLIT_HEADER_11_inst_addr                                       "0x000D"
#define  set_OSH_OSD_SPLIT_HEADER_11_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_11_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_11_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_11_reg))
#define  OSH_OSD_SPLIT_HEADER_11_header11_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_11_header11_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_11_header11(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_11_get_header11(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_12                                                 0x18029840
#define  OSH_OSD_SPLIT_HEADER_12_reg_addr                                        "0xB8029840"
#define  OSH_OSD_SPLIT_HEADER_12_reg                                             0xB8029840
#define  OSH_OSD_SPLIT_HEADER_12_inst_addr                                       "0x000E"
#define  set_OSH_OSD_SPLIT_HEADER_12_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_12_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_12_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_12_reg))
#define  OSH_OSD_SPLIT_HEADER_12_header12_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_12_header12_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_12_header12(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_12_get_header12(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_13                                                 0x18029844
#define  OSH_OSD_SPLIT_HEADER_13_reg_addr                                        "0xB8029844"
#define  OSH_OSD_SPLIT_HEADER_13_reg                                             0xB8029844
#define  OSH_OSD_SPLIT_HEADER_13_inst_addr                                       "0x000F"
#define  set_OSH_OSD_SPLIT_HEADER_13_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_13_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_13_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_13_reg))
#define  OSH_OSD_SPLIT_HEADER_13_header13_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_13_header13_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_13_header13(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_13_get_header13(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_14                                                 0x18029848
#define  OSH_OSD_SPLIT_HEADER_14_reg_addr                                        "0xB8029848"
#define  OSH_OSD_SPLIT_HEADER_14_reg                                             0xB8029848
#define  OSH_OSD_SPLIT_HEADER_14_inst_addr                                       "0x0010"
#define  set_OSH_OSD_SPLIT_HEADER_14_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_14_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_14_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_14_reg))
#define  OSH_OSD_SPLIT_HEADER_14_header14_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_14_header14_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_14_header14(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_14_get_header14(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_15                                                 0x1802984C
#define  OSH_OSD_SPLIT_HEADER_15_reg_addr                                        "0xB802984C"
#define  OSH_OSD_SPLIT_HEADER_15_reg                                             0xB802984C
#define  OSH_OSD_SPLIT_HEADER_15_inst_addr                                       "0x0011"
#define  set_OSH_OSD_SPLIT_HEADER_15_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_15_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_15_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_15_reg))
#define  OSH_OSD_SPLIT_HEADER_15_header15_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_15_header15_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_15_header15(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_15_get_header15(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_16                                                 0x18029850
#define  OSH_OSD_SPLIT_HEADER_16_reg_addr                                        "0xB8029850"
#define  OSH_OSD_SPLIT_HEADER_16_reg                                             0xB8029850
#define  OSH_OSD_SPLIT_HEADER_16_inst_addr                                       "0x0012"
#define  set_OSH_OSD_SPLIT_HEADER_16_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_16_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_16_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_16_reg))
#define  OSH_OSD_SPLIT_HEADER_16_header16_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_16_header16_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_16_header16(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_16_get_header16(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_17                                                 0x18029854
#define  OSH_OSD_SPLIT_HEADER_17_reg_addr                                        "0xB8029854"
#define  OSH_OSD_SPLIT_HEADER_17_reg                                             0xB8029854
#define  OSH_OSD_SPLIT_HEADER_17_inst_addr                                       "0x0013"
#define  set_OSH_OSD_SPLIT_HEADER_17_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_17_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_17_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_17_reg))
#define  OSH_OSD_SPLIT_HEADER_17_header17_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_17_header17_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_17_header17(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_17_get_header17(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_18                                                 0x18029858
#define  OSH_OSD_SPLIT_HEADER_18_reg_addr                                        "0xB8029858"
#define  OSH_OSD_SPLIT_HEADER_18_reg                                             0xB8029858
#define  OSH_OSD_SPLIT_HEADER_18_inst_addr                                       "0x0014"
#define  set_OSH_OSD_SPLIT_HEADER_18_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_18_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_18_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_18_reg))
#define  OSH_OSD_SPLIT_HEADER_18_header18_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_18_header18_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_18_header18(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_18_get_header18(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_19                                                 0x1802985C
#define  OSH_OSD_SPLIT_HEADER_19_reg_addr                                        "0xB802985C"
#define  OSH_OSD_SPLIT_HEADER_19_reg                                             0xB802985C
#define  OSH_OSD_SPLIT_HEADER_19_inst_addr                                       "0x0015"
#define  set_OSH_OSD_SPLIT_HEADER_19_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_19_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_19_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_19_reg))
#define  OSH_OSD_SPLIT_HEADER_19_header19_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_19_header19_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_19_header19(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_19_get_header19(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_20                                                 0x18029860
#define  OSH_OSD_SPLIT_HEADER_20_reg_addr                                        "0xB8029860"
#define  OSH_OSD_SPLIT_HEADER_20_reg                                             0xB8029860
#define  OSH_OSD_SPLIT_HEADER_20_inst_addr                                       "0x0016"
#define  set_OSH_OSD_SPLIT_HEADER_20_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_20_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_20_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_20_reg))
#define  OSH_OSD_SPLIT_HEADER_20_header20_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_20_header20_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_20_header20(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_20_get_header20(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_21                                                 0x18029864
#define  OSH_OSD_SPLIT_HEADER_21_reg_addr                                        "0xB8029864"
#define  OSH_OSD_SPLIT_HEADER_21_reg                                             0xB8029864
#define  OSH_OSD_SPLIT_HEADER_21_inst_addr                                       "0x0017"
#define  set_OSH_OSD_SPLIT_HEADER_21_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_21_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_21_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_21_reg))
#define  OSH_OSD_SPLIT_HEADER_21_header21_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_21_header21_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_21_header21(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_21_get_header21(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_22                                                 0x18029868
#define  OSH_OSD_SPLIT_HEADER_22_reg_addr                                        "0xB8029868"
#define  OSH_OSD_SPLIT_HEADER_22_reg                                             0xB8029868
#define  OSH_OSD_SPLIT_HEADER_22_inst_addr                                       "0x0018"
#define  set_OSH_OSD_SPLIT_HEADER_22_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_22_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_22_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_22_reg))
#define  OSH_OSD_SPLIT_HEADER_22_header22_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_22_header22_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_22_header22(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_22_get_header22(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_HEADER_23                                                 0x1802986C
#define  OSH_OSD_SPLIT_HEADER_23_reg_addr                                        "0xB802986C"
#define  OSH_OSD_SPLIT_HEADER_23_reg                                             0xB802986C
#define  OSH_OSD_SPLIT_HEADER_23_inst_addr                                       "0x0019"
#define  set_OSH_OSD_SPLIT_HEADER_23_reg(data)                                   (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_23_reg)=data)
#define  get_OSH_OSD_SPLIT_HEADER_23_reg                                         (*((volatile unsigned int*)OSH_OSD_SPLIT_HEADER_23_reg))
#define  OSH_OSD_SPLIT_HEADER_23_header23_shift                                  (0)
#define  OSH_OSD_SPLIT_HEADER_23_header23_mask                                   (0xFFFFFFFF)
#define  OSH_OSD_SPLIT_HEADER_23_header23(data)                                  (0xFFFFFFFF&(data))
#define  OSH_OSD_SPLIT_HEADER_23_get_header23(data)                              (0xFFFFFFFF&(data))

#define  OSH_OSD_SPLIT_db_ctrl                                                   0x18029870
#define  OSH_OSD_SPLIT_db_ctrl_reg_addr                                          "0xB8029870"
#define  OSH_OSD_SPLIT_db_ctrl_reg                                               0xB8029870
#define  OSH_OSD_SPLIT_db_ctrl_inst_addr                                         "0x001A"
#define  set_OSH_OSD_SPLIT_db_ctrl_reg(data)                                     (*((volatile unsigned int*)OSH_OSD_SPLIT_db_ctrl_reg)=data)
#define  get_OSH_OSD_SPLIT_db_ctrl_reg                                           (*((volatile unsigned int*)OSH_OSD_SPLIT_db_ctrl_reg))
#define  OSH_OSD_SPLIT_db_ctrl_db_read_shift                                     (2)
#define  OSH_OSD_SPLIT_db_ctrl_db_en_shift                                       (1)
#define  OSH_OSD_SPLIT_db_ctrl_db_load_shift                                     (0)
#define  OSH_OSD_SPLIT_db_ctrl_db_read_mask                                      (0x00000004)
#define  OSH_OSD_SPLIT_db_ctrl_db_en_mask                                        (0x00000002)
#define  OSH_OSD_SPLIT_db_ctrl_db_load_mask                                      (0x00000001)
#define  OSH_OSD_SPLIT_db_ctrl_db_read(data)                                     (0x00000004&((data)<<2))
#define  OSH_OSD_SPLIT_db_ctrl_db_en(data)                                       (0x00000002&((data)<<1))
#define  OSH_OSD_SPLIT_db_ctrl_db_load(data)                                     (0x00000001&(data))
#define  OSH_OSD_SPLIT_db_ctrl_get_db_read(data)                                 ((0x00000004&(data))>>2)
#define  OSH_OSD_SPLIT_db_ctrl_get_db_en(data)                                   ((0x00000002&(data))>>1)
#define  OSH_OSD_SPLIT_db_ctrl_get_db_load(data)                                 (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OSH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  header_h_sta:13;
        RBus_UInt32  res2:15;
        RBus_UInt32  header_en:1;
    };
}osh_osd_split_header_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_empty_a:8;
        RBus_UInt32  data_empty_r:8;
        RBus_UInt32  data_empty_g:8;
        RBus_UInt32  data_empty_b:8;
    };
}osh_osd_split_empty_pixel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header0:32;
    };
}osh_osd_split_header_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header1:32;
    };
}osh_osd_split_header_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header2:32;
    };
}osh_osd_split_header_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header3:32;
    };
}osh_osd_split_header_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header4:32;
    };
}osh_osd_split_header_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header5:32;
    };
}osh_osd_split_header_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header6:32;
    };
}osh_osd_split_header_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header7:32;
    };
}osh_osd_split_header_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header8:32;
    };
}osh_osd_split_header_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header9:32;
    };
}osh_osd_split_header_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header10:32;
    };
}osh_osd_split_header_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header11:32;
    };
}osh_osd_split_header_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header12:32;
    };
}osh_osd_split_header_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header13:32;
    };
}osh_osd_split_header_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header14:32;
    };
}osh_osd_split_header_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header15:32;
    };
}osh_osd_split_header_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header16:32;
    };
}osh_osd_split_header_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header17:32;
    };
}osh_osd_split_header_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header18:32;
    };
}osh_osd_split_header_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header19:32;
    };
}osh_osd_split_header_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header20:32;
    };
}osh_osd_split_header_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header21:32;
    };
}osh_osd_split_header_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header22:32;
    };
}osh_osd_split_header_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header23:32;
    };
}osh_osd_split_header_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
    };
}osh_osd_split_db_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======OSH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  header_h_sta:13;
        RBus_UInt32  res2:3;
    };
}osh_osd_split_header_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_empty_b:8;
        RBus_UInt32  data_empty_g:8;
        RBus_UInt32  data_empty_r:8;
        RBus_UInt32  data_empty_a:8;
    };
}osh_osd_split_empty_pixel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header0:32;
    };
}osh_osd_split_header_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header1:32;
    };
}osh_osd_split_header_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header2:32;
    };
}osh_osd_split_header_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header3:32;
    };
}osh_osd_split_header_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header4:32;
    };
}osh_osd_split_header_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header5:32;
    };
}osh_osd_split_header_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header6:32;
    };
}osh_osd_split_header_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header7:32;
    };
}osh_osd_split_header_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header8:32;
    };
}osh_osd_split_header_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header9:32;
    };
}osh_osd_split_header_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header10:32;
    };
}osh_osd_split_header_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header11:32;
    };
}osh_osd_split_header_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header12:32;
    };
}osh_osd_split_header_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header13:32;
    };
}osh_osd_split_header_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header14:32;
    };
}osh_osd_split_header_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header15:32;
    };
}osh_osd_split_header_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header16:32;
    };
}osh_osd_split_header_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header17:32;
    };
}osh_osd_split_header_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header18:32;
    };
}osh_osd_split_header_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header19:32;
    };
}osh_osd_split_header_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header20:32;
    };
}osh_osd_split_header_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header21:32;
    };
}osh_osd_split_header_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header22:32;
    };
}osh_osd_split_header_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  header23:32;
    };
}osh_osd_split_header_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:29;
    };
}osh_osd_split_db_ctrl_RBUS;




#endif 


#endif 
