/**
* @file rbusVD_IFD_INPUTReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VD_IFD_INPUT_REG_H_
#define _RBUS_VD_IFD_INPUT_REG_H_

#include "rbus_types.h"



//  VD_IFD_INPUT Register Address
#define  VD_IFD_INPUT_input_flt_tap_0_1                                          0x18018000
#define  VD_IFD_INPUT_input_flt_tap_0_1_reg_addr                                 "0xB8018000"
#define  VD_IFD_INPUT_input_flt_tap_0_1_reg                                      0xB8018000
#define  VD_IFD_INPUT_input_flt_tap_0_1_inst_addr                                "0x0000"
#define  set_VD_IFD_INPUT_input_flt_tap_0_1_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_0_1_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_0_1_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_0_1_reg))
#define  VD_IFD_INPUT_input_flt_tap_0_1_input_flt_tap0_shift                     (16)
#define  VD_IFD_INPUT_input_flt_tap_0_1_input_flt_tap1_shift                     (0)
#define  VD_IFD_INPUT_input_flt_tap_0_1_input_flt_tap0_mask                      (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_0_1_input_flt_tap1_mask                      (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_0_1_input_flt_tap0(data)                     (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_0_1_input_flt_tap1(data)                     (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_0_1_get_input_flt_tap0(data)                 ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_0_1_get_input_flt_tap1(data)                 (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_2_3                                          0x18018004
#define  VD_IFD_INPUT_input_flt_tap_2_3_reg_addr                                 "0xB8018004"
#define  VD_IFD_INPUT_input_flt_tap_2_3_reg                                      0xB8018004
#define  VD_IFD_INPUT_input_flt_tap_2_3_inst_addr                                "0x0001"
#define  set_VD_IFD_INPUT_input_flt_tap_2_3_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_2_3_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_2_3_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_2_3_reg))
#define  VD_IFD_INPUT_input_flt_tap_2_3_input_flt_tap2_shift                     (16)
#define  VD_IFD_INPUT_input_flt_tap_2_3_input_flt_tap3_shift                     (0)
#define  VD_IFD_INPUT_input_flt_tap_2_3_input_flt_tap2_mask                      (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_2_3_input_flt_tap3_mask                      (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_2_3_input_flt_tap2(data)                     (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_2_3_input_flt_tap3(data)                     (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_2_3_get_input_flt_tap2(data)                 ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_2_3_get_input_flt_tap3(data)                 (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_4_5                                          0x18018008
#define  VD_IFD_INPUT_input_flt_tap_4_5_reg_addr                                 "0xB8018008"
#define  VD_IFD_INPUT_input_flt_tap_4_5_reg                                      0xB8018008
#define  VD_IFD_INPUT_input_flt_tap_4_5_inst_addr                                "0x0002"
#define  set_VD_IFD_INPUT_input_flt_tap_4_5_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_4_5_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_4_5_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_4_5_reg))
#define  VD_IFD_INPUT_input_flt_tap_4_5_input_flt_tap4_shift                     (16)
#define  VD_IFD_INPUT_input_flt_tap_4_5_input_flt_tap5_shift                     (0)
#define  VD_IFD_INPUT_input_flt_tap_4_5_input_flt_tap4_mask                      (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_4_5_input_flt_tap5_mask                      (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_4_5_input_flt_tap4(data)                     (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_4_5_input_flt_tap5(data)                     (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_4_5_get_input_flt_tap4(data)                 ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_4_5_get_input_flt_tap5(data)                 (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_6_7                                          0x1801800C
#define  VD_IFD_INPUT_input_flt_tap_6_7_reg_addr                                 "0xB801800C"
#define  VD_IFD_INPUT_input_flt_tap_6_7_reg                                      0xB801800C
#define  VD_IFD_INPUT_input_flt_tap_6_7_inst_addr                                "0x0003"
#define  set_VD_IFD_INPUT_input_flt_tap_6_7_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_6_7_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_6_7_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_6_7_reg))
#define  VD_IFD_INPUT_input_flt_tap_6_7_input_flt_tap6_shift                     (16)
#define  VD_IFD_INPUT_input_flt_tap_6_7_input_flt_tap7_shift                     (0)
#define  VD_IFD_INPUT_input_flt_tap_6_7_input_flt_tap6_mask                      (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_6_7_input_flt_tap7_mask                      (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_6_7_input_flt_tap6(data)                     (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_6_7_input_flt_tap7(data)                     (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_6_7_get_input_flt_tap6(data)                 ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_6_7_get_input_flt_tap7(data)                 (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_8_9                                          0x18018010
#define  VD_IFD_INPUT_input_flt_tap_8_9_reg_addr                                 "0xB8018010"
#define  VD_IFD_INPUT_input_flt_tap_8_9_reg                                      0xB8018010
#define  VD_IFD_INPUT_input_flt_tap_8_9_inst_addr                                "0x0004"
#define  set_VD_IFD_INPUT_input_flt_tap_8_9_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_8_9_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_8_9_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_8_9_reg))
#define  VD_IFD_INPUT_input_flt_tap_8_9_input_flt_tap8_shift                     (16)
#define  VD_IFD_INPUT_input_flt_tap_8_9_input_flt_tap9_shift                     (0)
#define  VD_IFD_INPUT_input_flt_tap_8_9_input_flt_tap8_mask                      (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_8_9_input_flt_tap9_mask                      (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_8_9_input_flt_tap8(data)                     (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_8_9_input_flt_tap9(data)                     (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_8_9_get_input_flt_tap8(data)                 ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_8_9_get_input_flt_tap9(data)                 (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_10_11                                        0x18018014
#define  VD_IFD_INPUT_input_flt_tap_10_11_reg_addr                               "0xB8018014"
#define  VD_IFD_INPUT_input_flt_tap_10_11_reg                                    0xB8018014
#define  VD_IFD_INPUT_input_flt_tap_10_11_inst_addr                              "0x0005"
#define  set_VD_IFD_INPUT_input_flt_tap_10_11_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_10_11_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_10_11_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_10_11_reg))
#define  VD_IFD_INPUT_input_flt_tap_10_11_input_flt_tap10_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_10_11_input_flt_tap11_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_10_11_input_flt_tap10_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_10_11_input_flt_tap11_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_10_11_input_flt_tap10(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_10_11_input_flt_tap11(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_10_11_get_input_flt_tap10(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_10_11_get_input_flt_tap11(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_12_13                                        0x18018018
#define  VD_IFD_INPUT_input_flt_tap_12_13_reg_addr                               "0xB8018018"
#define  VD_IFD_INPUT_input_flt_tap_12_13_reg                                    0xB8018018
#define  VD_IFD_INPUT_input_flt_tap_12_13_inst_addr                              "0x0006"
#define  set_VD_IFD_INPUT_input_flt_tap_12_13_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_12_13_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_12_13_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_12_13_reg))
#define  VD_IFD_INPUT_input_flt_tap_12_13_input_flt_tap12_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_12_13_input_flt_tap13_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_12_13_input_flt_tap12_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_12_13_input_flt_tap13_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_12_13_input_flt_tap12(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_12_13_input_flt_tap13(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_12_13_get_input_flt_tap12(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_12_13_get_input_flt_tap13(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_14_15                                        0x1801801C
#define  VD_IFD_INPUT_input_flt_tap_14_15_reg_addr                               "0xB801801C"
#define  VD_IFD_INPUT_input_flt_tap_14_15_reg                                    0xB801801C
#define  VD_IFD_INPUT_input_flt_tap_14_15_inst_addr                              "0x0007"
#define  set_VD_IFD_INPUT_input_flt_tap_14_15_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_14_15_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_14_15_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_14_15_reg))
#define  VD_IFD_INPUT_input_flt_tap_14_15_input_flt_tap14_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_14_15_input_flt_tap15_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_14_15_input_flt_tap14_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_14_15_input_flt_tap15_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_14_15_input_flt_tap14(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_14_15_input_flt_tap15(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_14_15_get_input_flt_tap14(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_14_15_get_input_flt_tap15(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_16_17                                        0x18018020
#define  VD_IFD_INPUT_input_flt_tap_16_17_reg_addr                               "0xB8018020"
#define  VD_IFD_INPUT_input_flt_tap_16_17_reg                                    0xB8018020
#define  VD_IFD_INPUT_input_flt_tap_16_17_inst_addr                              "0x0008"
#define  set_VD_IFD_INPUT_input_flt_tap_16_17_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_16_17_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_16_17_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_16_17_reg))
#define  VD_IFD_INPUT_input_flt_tap_16_17_input_flt_tap16_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_16_17_input_flt_tap17_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_16_17_input_flt_tap16_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_16_17_input_flt_tap17_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_16_17_input_flt_tap16(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_16_17_input_flt_tap17(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_16_17_get_input_flt_tap16(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_16_17_get_input_flt_tap17(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_18_19                                        0x18018024
#define  VD_IFD_INPUT_input_flt_tap_18_19_reg_addr                               "0xB8018024"
#define  VD_IFD_INPUT_input_flt_tap_18_19_reg                                    0xB8018024
#define  VD_IFD_INPUT_input_flt_tap_18_19_inst_addr                              "0x0009"
#define  set_VD_IFD_INPUT_input_flt_tap_18_19_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_18_19_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_18_19_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_18_19_reg))
#define  VD_IFD_INPUT_input_flt_tap_18_19_input_flt_tap18_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_18_19_input_flt_tap19_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_18_19_input_flt_tap18_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_18_19_input_flt_tap19_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_18_19_input_flt_tap18(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_18_19_input_flt_tap19(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_18_19_get_input_flt_tap18(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_18_19_get_input_flt_tap19(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_20_21                                        0x18018028
#define  VD_IFD_INPUT_input_flt_tap_20_21_reg_addr                               "0xB8018028"
#define  VD_IFD_INPUT_input_flt_tap_20_21_reg                                    0xB8018028
#define  VD_IFD_INPUT_input_flt_tap_20_21_inst_addr                              "0x000A"
#define  set_VD_IFD_INPUT_input_flt_tap_20_21_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_20_21_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_20_21_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_20_21_reg))
#define  VD_IFD_INPUT_input_flt_tap_20_21_input_flt_tap20_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_20_21_input_flt_tap21_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_20_21_input_flt_tap20_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_20_21_input_flt_tap21_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_20_21_input_flt_tap20(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_20_21_input_flt_tap21(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_20_21_get_input_flt_tap20(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_20_21_get_input_flt_tap21(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_22_23                                        0x1801802C
#define  VD_IFD_INPUT_input_flt_tap_22_23_reg_addr                               "0xB801802C"
#define  VD_IFD_INPUT_input_flt_tap_22_23_reg                                    0xB801802C
#define  VD_IFD_INPUT_input_flt_tap_22_23_inst_addr                              "0x000B"
#define  set_VD_IFD_INPUT_input_flt_tap_22_23_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_22_23_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_22_23_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_22_23_reg))
#define  VD_IFD_INPUT_input_flt_tap_22_23_input_flt_tap22_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_22_23_input_flt_tap23_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_22_23_input_flt_tap22_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_22_23_input_flt_tap23_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_22_23_input_flt_tap22(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_22_23_input_flt_tap23(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_22_23_get_input_flt_tap22(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_22_23_get_input_flt_tap23(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_24_25                                        0x18018030
#define  VD_IFD_INPUT_input_flt_tap_24_25_reg_addr                               "0xB8018030"
#define  VD_IFD_INPUT_input_flt_tap_24_25_reg                                    0xB8018030
#define  VD_IFD_INPUT_input_flt_tap_24_25_inst_addr                              "0x000C"
#define  set_VD_IFD_INPUT_input_flt_tap_24_25_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_24_25_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_24_25_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_24_25_reg))
#define  VD_IFD_INPUT_input_flt_tap_24_25_input_flt_tap24_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_24_25_input_flt_tap25_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_24_25_input_flt_tap24_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_24_25_input_flt_tap25_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_24_25_input_flt_tap24(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_24_25_input_flt_tap25(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_24_25_get_input_flt_tap24(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_24_25_get_input_flt_tap25(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_26_27                                        0x18018034
#define  VD_IFD_INPUT_input_flt_tap_26_27_reg_addr                               "0xB8018034"
#define  VD_IFD_INPUT_input_flt_tap_26_27_reg                                    0xB8018034
#define  VD_IFD_INPUT_input_flt_tap_26_27_inst_addr                              "0x000D"
#define  set_VD_IFD_INPUT_input_flt_tap_26_27_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_26_27_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_26_27_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_26_27_reg))
#define  VD_IFD_INPUT_input_flt_tap_26_27_input_flt_tap26_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_26_27_input_flt_tap27_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_26_27_input_flt_tap26_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_26_27_input_flt_tap27_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_26_27_input_flt_tap26(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_26_27_input_flt_tap27(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_26_27_get_input_flt_tap26(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_26_27_get_input_flt_tap27(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_28_29                                        0x18018038
#define  VD_IFD_INPUT_input_flt_tap_28_29_reg_addr                               "0xB8018038"
#define  VD_IFD_INPUT_input_flt_tap_28_29_reg                                    0xB8018038
#define  VD_IFD_INPUT_input_flt_tap_28_29_inst_addr                              "0x000E"
#define  set_VD_IFD_INPUT_input_flt_tap_28_29_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_28_29_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_28_29_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_28_29_reg))
#define  VD_IFD_INPUT_input_flt_tap_28_29_input_flt_tap28_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_28_29_input_flt_tap29_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_28_29_input_flt_tap28_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_28_29_input_flt_tap29_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_28_29_input_flt_tap28(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_28_29_input_flt_tap29(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_28_29_get_input_flt_tap28(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_28_29_get_input_flt_tap29(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_30_31                                        0x1801803C
#define  VD_IFD_INPUT_input_flt_tap_30_31_reg_addr                               "0xB801803C"
#define  VD_IFD_INPUT_input_flt_tap_30_31_reg                                    0xB801803C
#define  VD_IFD_INPUT_input_flt_tap_30_31_inst_addr                              "0x000F"
#define  set_VD_IFD_INPUT_input_flt_tap_30_31_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_30_31_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_30_31_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_30_31_reg))
#define  VD_IFD_INPUT_input_flt_tap_30_31_input_flt_tap30_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_30_31_input_flt_tap31_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_30_31_input_flt_tap30_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_30_31_input_flt_tap31_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_30_31_input_flt_tap30(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_30_31_input_flt_tap31(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_30_31_get_input_flt_tap30(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_30_31_get_input_flt_tap31(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_32_33                                        0x18018040
#define  VD_IFD_INPUT_input_flt_tap_32_33_reg_addr                               "0xB8018040"
#define  VD_IFD_INPUT_input_flt_tap_32_33_reg                                    0xB8018040
#define  VD_IFD_INPUT_input_flt_tap_32_33_inst_addr                              "0x0010"
#define  set_VD_IFD_INPUT_input_flt_tap_32_33_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_32_33_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_32_33_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_32_33_reg))
#define  VD_IFD_INPUT_input_flt_tap_32_33_input_flt_tap32_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_32_33_input_flt_tap33_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_32_33_input_flt_tap32_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_32_33_input_flt_tap33_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_32_33_input_flt_tap32(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_32_33_input_flt_tap33(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_32_33_get_input_flt_tap32(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_32_33_get_input_flt_tap33(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_34_35                                        0x18018044
#define  VD_IFD_INPUT_input_flt_tap_34_35_reg_addr                               "0xB8018044"
#define  VD_IFD_INPUT_input_flt_tap_34_35_reg                                    0xB8018044
#define  VD_IFD_INPUT_input_flt_tap_34_35_inst_addr                              "0x0011"
#define  set_VD_IFD_INPUT_input_flt_tap_34_35_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_34_35_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_34_35_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_34_35_reg))
#define  VD_IFD_INPUT_input_flt_tap_34_35_input_flt_tap34_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_34_35_input_flt_tap35_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_34_35_input_flt_tap34_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_34_35_input_flt_tap35_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_34_35_input_flt_tap34(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_34_35_input_flt_tap35(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_34_35_get_input_flt_tap34(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_34_35_get_input_flt_tap35(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_36_37                                        0x18018048
#define  VD_IFD_INPUT_input_flt_tap_36_37_reg_addr                               "0xB8018048"
#define  VD_IFD_INPUT_input_flt_tap_36_37_reg                                    0xB8018048
#define  VD_IFD_INPUT_input_flt_tap_36_37_inst_addr                              "0x0012"
#define  set_VD_IFD_INPUT_input_flt_tap_36_37_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_36_37_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_36_37_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_36_37_reg))
#define  VD_IFD_INPUT_input_flt_tap_36_37_input_flt_tap36_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_36_37_input_flt_tap37_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_36_37_input_flt_tap36_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_36_37_input_flt_tap37_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_36_37_input_flt_tap36(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_36_37_input_flt_tap37(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_36_37_get_input_flt_tap36(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_36_37_get_input_flt_tap37(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_38_39                                        0x1801804C
#define  VD_IFD_INPUT_input_flt_tap_38_39_reg_addr                               "0xB801804C"
#define  VD_IFD_INPUT_input_flt_tap_38_39_reg                                    0xB801804C
#define  VD_IFD_INPUT_input_flt_tap_38_39_inst_addr                              "0x0013"
#define  set_VD_IFD_INPUT_input_flt_tap_38_39_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_38_39_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_38_39_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_38_39_reg))
#define  VD_IFD_INPUT_input_flt_tap_38_39_input_flt_tap38_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_38_39_input_flt_tap39_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_38_39_input_flt_tap38_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_38_39_input_flt_tap39_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_38_39_input_flt_tap38(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_38_39_input_flt_tap39(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_38_39_get_input_flt_tap38(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_38_39_get_input_flt_tap39(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_40_41                                        0x18018050
#define  VD_IFD_INPUT_input_flt_tap_40_41_reg_addr                               "0xB8018050"
#define  VD_IFD_INPUT_input_flt_tap_40_41_reg                                    0xB8018050
#define  VD_IFD_INPUT_input_flt_tap_40_41_inst_addr                              "0x0014"
#define  set_VD_IFD_INPUT_input_flt_tap_40_41_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_40_41_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_40_41_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_40_41_reg))
#define  VD_IFD_INPUT_input_flt_tap_40_41_input_flt_tap40_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_40_41_input_flt_tap41_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_40_41_input_flt_tap40_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_40_41_input_flt_tap41_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_40_41_input_flt_tap40(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_40_41_input_flt_tap41(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_40_41_get_input_flt_tap40(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_40_41_get_input_flt_tap41(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_42_43                                        0x18018054
#define  VD_IFD_INPUT_input_flt_tap_42_43_reg_addr                               "0xB8018054"
#define  VD_IFD_INPUT_input_flt_tap_42_43_reg                                    0xB8018054
#define  VD_IFD_INPUT_input_flt_tap_42_43_inst_addr                              "0x0015"
#define  set_VD_IFD_INPUT_input_flt_tap_42_43_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_42_43_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_42_43_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_42_43_reg))
#define  VD_IFD_INPUT_input_flt_tap_42_43_input_flt_tap42_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_42_43_input_flt_tap43_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_42_43_input_flt_tap42_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_42_43_input_flt_tap43_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_42_43_input_flt_tap42(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_42_43_input_flt_tap43(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_42_43_get_input_flt_tap42(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_42_43_get_input_flt_tap43(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_44_45                                        0x18018058
#define  VD_IFD_INPUT_input_flt_tap_44_45_reg_addr                               "0xB8018058"
#define  VD_IFD_INPUT_input_flt_tap_44_45_reg                                    0xB8018058
#define  VD_IFD_INPUT_input_flt_tap_44_45_inst_addr                              "0x0016"
#define  set_VD_IFD_INPUT_input_flt_tap_44_45_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_44_45_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_44_45_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_44_45_reg))
#define  VD_IFD_INPUT_input_flt_tap_44_45_input_flt_tap44_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_44_45_input_flt_tap45_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_44_45_input_flt_tap44_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_44_45_input_flt_tap45_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_44_45_input_flt_tap44(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_44_45_input_flt_tap45(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_44_45_get_input_flt_tap44(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_44_45_get_input_flt_tap45(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_46_47                                        0x1801805C
#define  VD_IFD_INPUT_input_flt_tap_46_47_reg_addr                               "0xB801805C"
#define  VD_IFD_INPUT_input_flt_tap_46_47_reg                                    0xB801805C
#define  VD_IFD_INPUT_input_flt_tap_46_47_inst_addr                              "0x0017"
#define  set_VD_IFD_INPUT_input_flt_tap_46_47_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_46_47_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_46_47_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_46_47_reg))
#define  VD_IFD_INPUT_input_flt_tap_46_47_input_flt_tap46_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_46_47_input_flt_tap47_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_46_47_input_flt_tap46_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_46_47_input_flt_tap47_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_46_47_input_flt_tap46(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_46_47_input_flt_tap47(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_46_47_get_input_flt_tap46(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_46_47_get_input_flt_tap47(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_48_49                                        0x18018060
#define  VD_IFD_INPUT_input_flt_tap_48_49_reg_addr                               "0xB8018060"
#define  VD_IFD_INPUT_input_flt_tap_48_49_reg                                    0xB8018060
#define  VD_IFD_INPUT_input_flt_tap_48_49_inst_addr                              "0x0018"
#define  set_VD_IFD_INPUT_input_flt_tap_48_49_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_48_49_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_48_49_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_48_49_reg))
#define  VD_IFD_INPUT_input_flt_tap_48_49_input_flt_tap48_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_48_49_input_flt_tap49_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_48_49_input_flt_tap48_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_48_49_input_flt_tap49_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_48_49_input_flt_tap48(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_48_49_input_flt_tap49(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_48_49_get_input_flt_tap48(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_48_49_get_input_flt_tap49(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_50_51                                        0x18018064
#define  VD_IFD_INPUT_input_flt_tap_50_51_reg_addr                               "0xB8018064"
#define  VD_IFD_INPUT_input_flt_tap_50_51_reg                                    0xB8018064
#define  VD_IFD_INPUT_input_flt_tap_50_51_inst_addr                              "0x0019"
#define  set_VD_IFD_INPUT_input_flt_tap_50_51_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_50_51_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_50_51_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_50_51_reg))
#define  VD_IFD_INPUT_input_flt_tap_50_51_input_flt_tap50_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_50_51_input_flt_tap51_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_50_51_input_flt_tap50_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_50_51_input_flt_tap51_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_50_51_input_flt_tap50(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_50_51_input_flt_tap51(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_50_51_get_input_flt_tap50(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_50_51_get_input_flt_tap51(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_52_53                                        0x18018068
#define  VD_IFD_INPUT_input_flt_tap_52_53_reg_addr                               "0xB8018068"
#define  VD_IFD_INPUT_input_flt_tap_52_53_reg                                    0xB8018068
#define  VD_IFD_INPUT_input_flt_tap_52_53_inst_addr                              "0x001A"
#define  set_VD_IFD_INPUT_input_flt_tap_52_53_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_52_53_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_52_53_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_52_53_reg))
#define  VD_IFD_INPUT_input_flt_tap_52_53_input_flt_tap52_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_52_53_input_flt_tap53_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_52_53_input_flt_tap52_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_52_53_input_flt_tap53_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_52_53_input_flt_tap52(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_52_53_input_flt_tap53(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_52_53_get_input_flt_tap52(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_52_53_get_input_flt_tap53(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_54_55                                        0x1801806C
#define  VD_IFD_INPUT_input_flt_tap_54_55_reg_addr                               "0xB801806C"
#define  VD_IFD_INPUT_input_flt_tap_54_55_reg                                    0xB801806C
#define  VD_IFD_INPUT_input_flt_tap_54_55_inst_addr                              "0x001B"
#define  set_VD_IFD_INPUT_input_flt_tap_54_55_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_54_55_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_54_55_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_54_55_reg))
#define  VD_IFD_INPUT_input_flt_tap_54_55_input_flt_tap54_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_54_55_input_flt_tap55_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_54_55_input_flt_tap54_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_54_55_input_flt_tap55_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_54_55_input_flt_tap54(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_54_55_input_flt_tap55(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_54_55_get_input_flt_tap54(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_54_55_get_input_flt_tap55(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_56_57                                        0x18018070
#define  VD_IFD_INPUT_input_flt_tap_56_57_reg_addr                               "0xB8018070"
#define  VD_IFD_INPUT_input_flt_tap_56_57_reg                                    0xB8018070
#define  VD_IFD_INPUT_input_flt_tap_56_57_inst_addr                              "0x001C"
#define  set_VD_IFD_INPUT_input_flt_tap_56_57_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_56_57_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_56_57_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_56_57_reg))
#define  VD_IFD_INPUT_input_flt_tap_56_57_input_flt_tap56_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_56_57_input_flt_tap57_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_56_57_input_flt_tap56_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_56_57_input_flt_tap57_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_56_57_input_flt_tap56(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_56_57_input_flt_tap57(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_56_57_get_input_flt_tap56(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_56_57_get_input_flt_tap57(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_58_59                                        0x18018074
#define  VD_IFD_INPUT_input_flt_tap_58_59_reg_addr                               "0xB8018074"
#define  VD_IFD_INPUT_input_flt_tap_58_59_reg                                    0xB8018074
#define  VD_IFD_INPUT_input_flt_tap_58_59_inst_addr                              "0x001D"
#define  set_VD_IFD_INPUT_input_flt_tap_58_59_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_58_59_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_58_59_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_58_59_reg))
#define  VD_IFD_INPUT_input_flt_tap_58_59_input_flt_tap58_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_58_59_input_flt_tap59_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_58_59_input_flt_tap58_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_58_59_input_flt_tap59_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_58_59_input_flt_tap58(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_58_59_input_flt_tap59(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_58_59_get_input_flt_tap58(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_58_59_get_input_flt_tap59(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_60_61                                        0x18018078
#define  VD_IFD_INPUT_input_flt_tap_60_61_reg_addr                               "0xB8018078"
#define  VD_IFD_INPUT_input_flt_tap_60_61_reg                                    0xB8018078
#define  VD_IFD_INPUT_input_flt_tap_60_61_inst_addr                              "0x001E"
#define  set_VD_IFD_INPUT_input_flt_tap_60_61_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_60_61_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_60_61_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_60_61_reg))
#define  VD_IFD_INPUT_input_flt_tap_60_61_input_flt_tap60_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_60_61_input_flt_tap61_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_60_61_input_flt_tap60_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_60_61_input_flt_tap61_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_60_61_input_flt_tap60(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_60_61_input_flt_tap61(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_60_61_get_input_flt_tap60(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_60_61_get_input_flt_tap61(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_62_63                                        0x1801807C
#define  VD_IFD_INPUT_input_flt_tap_62_63_reg_addr                               "0xB801807C"
#define  VD_IFD_INPUT_input_flt_tap_62_63_reg                                    0xB801807C
#define  VD_IFD_INPUT_input_flt_tap_62_63_inst_addr                              "0x001F"
#define  set_VD_IFD_INPUT_input_flt_tap_62_63_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_62_63_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_62_63_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_62_63_reg))
#define  VD_IFD_INPUT_input_flt_tap_62_63_input_flt_tap62_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_62_63_input_flt_tap63_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_62_63_input_flt_tap62_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_62_63_input_flt_tap63_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_62_63_input_flt_tap62(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_62_63_input_flt_tap63(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_62_63_get_input_flt_tap62(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_62_63_get_input_flt_tap63(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_64_65                                        0x18018080
#define  VD_IFD_INPUT_input_flt_tap_64_65_reg_addr                               "0xB8018080"
#define  VD_IFD_INPUT_input_flt_tap_64_65_reg                                    0xB8018080
#define  VD_IFD_INPUT_input_flt_tap_64_65_inst_addr                              "0x0020"
#define  set_VD_IFD_INPUT_input_flt_tap_64_65_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_64_65_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_64_65_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_64_65_reg))
#define  VD_IFD_INPUT_input_flt_tap_64_65_input_flt_tap64_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_64_65_input_flt_tap65_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_64_65_input_flt_tap64_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_64_65_input_flt_tap65_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_64_65_input_flt_tap64(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_64_65_input_flt_tap65(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_64_65_get_input_flt_tap64(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_64_65_get_input_flt_tap65(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_66_67                                        0x18018084
#define  VD_IFD_INPUT_input_flt_tap_66_67_reg_addr                               "0xB8018084"
#define  VD_IFD_INPUT_input_flt_tap_66_67_reg                                    0xB8018084
#define  VD_IFD_INPUT_input_flt_tap_66_67_inst_addr                              "0x0021"
#define  set_VD_IFD_INPUT_input_flt_tap_66_67_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_66_67_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_66_67_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_66_67_reg))
#define  VD_IFD_INPUT_input_flt_tap_66_67_input_flt_tap66_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_66_67_input_flt_tap67_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_66_67_input_flt_tap66_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_66_67_input_flt_tap67_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_66_67_input_flt_tap66(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_66_67_input_flt_tap67(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_66_67_get_input_flt_tap66(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_66_67_get_input_flt_tap67(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_68_69                                        0x18018088
#define  VD_IFD_INPUT_input_flt_tap_68_69_reg_addr                               "0xB8018088"
#define  VD_IFD_INPUT_input_flt_tap_68_69_reg                                    0xB8018088
#define  VD_IFD_INPUT_input_flt_tap_68_69_inst_addr                              "0x0022"
#define  set_VD_IFD_INPUT_input_flt_tap_68_69_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_68_69_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_68_69_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_68_69_reg))
#define  VD_IFD_INPUT_input_flt_tap_68_69_input_flt_tap68_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_68_69_input_flt_tap69_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_68_69_input_flt_tap68_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_68_69_input_flt_tap69_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_68_69_input_flt_tap68(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_68_69_input_flt_tap69(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_68_69_get_input_flt_tap68(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_68_69_get_input_flt_tap69(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_tap_70_71                                        0x1801808C
#define  VD_IFD_INPUT_input_flt_tap_70_71_reg_addr                               "0xB801808C"
#define  VD_IFD_INPUT_input_flt_tap_70_71_reg                                    0xB801808C
#define  VD_IFD_INPUT_input_flt_tap_70_71_inst_addr                              "0x0023"
#define  set_VD_IFD_INPUT_input_flt_tap_70_71_reg(data)                          (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_70_71_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_tap_70_71_reg                                (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_tap_70_71_reg))
#define  VD_IFD_INPUT_input_flt_tap_70_71_input_flt_tap70_shift                  (16)
#define  VD_IFD_INPUT_input_flt_tap_70_71_input_flt_tap71_shift                  (0)
#define  VD_IFD_INPUT_input_flt_tap_70_71_input_flt_tap70_mask                   (0x1FFF0000)
#define  VD_IFD_INPUT_input_flt_tap_70_71_input_flt_tap71_mask                   (0x00001FFF)
#define  VD_IFD_INPUT_input_flt_tap_70_71_input_flt_tap70(data)                  (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_input_flt_tap_70_71_input_flt_tap71(data)                  (0x00001FFF&(data))
#define  VD_IFD_INPUT_input_flt_tap_70_71_get_input_flt_tap70(data)              ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_input_flt_tap_70_71_get_input_flt_tap71(data)              (0x00001FFF&(data))

#define  VD_IFD_INPUT_input_flt_en                                               0x18018090
#define  VD_IFD_INPUT_input_flt_en_reg_addr                                      "0xB8018090"
#define  VD_IFD_INPUT_input_flt_en_reg                                           0xB8018090
#define  VD_IFD_INPUT_input_flt_en_inst_addr                                     "0x0024"
#define  set_VD_IFD_INPUT_input_flt_en_reg(data)                                 (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_en_reg)=data)
#define  get_VD_IFD_INPUT_input_flt_en_reg                                       (*((volatile unsigned int*)VD_IFD_INPUT_input_flt_en_reg))
#define  VD_IFD_INPUT_input_flt_en_input_flt_en_shift                            (0)
#define  VD_IFD_INPUT_input_flt_en_input_flt_en_mask                             (0x00000001)
#define  VD_IFD_INPUT_input_flt_en_input_flt_en(data)                            (0x00000001&(data))
#define  VD_IFD_INPUT_input_flt_en_get_input_flt_en(data)                        (0x00000001&(data))

#define  VD_IFD_INPUT_input_filter_set                                           0x18018094
#define  VD_IFD_INPUT_input_filter_set_reg_addr                                  "0xB8018094"
#define  VD_IFD_INPUT_input_filter_set_reg                                       0xB8018094
#define  VD_IFD_INPUT_input_filter_set_inst_addr                                 "0x0025"
#define  set_VD_IFD_INPUT_input_filter_set_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_input_filter_set_reg)=data)
#define  get_VD_IFD_INPUT_input_filter_set_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_input_filter_set_reg))
#define  VD_IFD_INPUT_input_filter_set_adc_fifo_in_sel_shift                     (8)
#define  VD_IFD_INPUT_input_filter_set_adc_clk_sel_shift                         (4)
#define  VD_IFD_INPUT_input_filter_set_input_dn_filter_sel_shift                 (0)
#define  VD_IFD_INPUT_input_filter_set_adc_fifo_in_sel_mask                      (0x00000100)
#define  VD_IFD_INPUT_input_filter_set_adc_clk_sel_mask                          (0x00000030)
#define  VD_IFD_INPUT_input_filter_set_input_dn_filter_sel_mask                  (0x00000007)
#define  VD_IFD_INPUT_input_filter_set_adc_fifo_in_sel(data)                     (0x00000100&((data)<<8))
#define  VD_IFD_INPUT_input_filter_set_adc_clk_sel(data)                         (0x00000030&((data)<<4))
#define  VD_IFD_INPUT_input_filter_set_input_dn_filter_sel(data)                 (0x00000007&(data))
#define  VD_IFD_INPUT_input_filter_set_get_adc_fifo_in_sel(data)                 ((0x00000100&(data))>>8)
#define  VD_IFD_INPUT_input_filter_set_get_adc_clk_sel(data)                     ((0x00000030&(data))>>4)
#define  VD_IFD_INPUT_input_filter_set_get_input_dn_filter_sel(data)             (0x00000007&(data))

#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR                                          0x18018098
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg_addr                                 "0xB8018098"
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg                                      0xB8018098
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_inst_addr                                "0x0026"
#define  set_VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg(data)                            (*((volatile unsigned int*)VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg)=data)
#define  get_VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg                                  (*((volatile unsigned int*)VD_IFD_INPUT_IFD_ADC_CLK_POLAR_reg))
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_ls_adcclk_polar_shift                    (1)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_clk54_polar_shift                        (0)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_ls_adcclk_polar_mask                     (0x00000002)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_clk54_polar_mask                         (0x00000001)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_ls_adcclk_polar(data)                    (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_clk54_polar(data)                        (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_get_ls_adcclk_polar(data)                ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_IFD_ADC_CLK_POLAR_get_clk54_polar(data)                    (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_cp_test_enable                                         0x1801809C
#define  VD_IFD_INPUT_IFD_cp_test_enable_reg_addr                                "0xB801809C"
#define  VD_IFD_INPUT_IFD_cp_test_enable_reg                                     0xB801809C
#define  VD_IFD_INPUT_IFD_cp_test_enable_inst_addr                               "0x0027"
#define  set_VD_IFD_INPUT_IFD_cp_test_enable_reg(data)                           (*((volatile unsigned int*)VD_IFD_INPUT_IFD_cp_test_enable_reg)=data)
#define  get_VD_IFD_INPUT_IFD_cp_test_enable_reg                                 (*((volatile unsigned int*)VD_IFD_INPUT_IFD_cp_test_enable_reg))
#define  VD_IFD_INPUT_IFD_cp_test_enable_cp_test_enable_shift                    (0)
#define  VD_IFD_INPUT_IFD_cp_test_enable_cp_test_enable_mask                     (0x00000001)
#define  VD_IFD_INPUT_IFD_cp_test_enable_cp_test_enable(data)                    (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_cp_test_enable_get_cp_test_enable(data)                (0x00000001&(data))

#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1                                           0x180180A0
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg_addr                                  "0xB80180A0"
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg                                       0xB80180A0
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_inst_addr                                 "0x0028"
#define  set_VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg)=data)
#define  get_VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL1_reg))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad4_input_delay_shift                     (24)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad3_input_delay_shift                     (16)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad2_input_delay_shift                     (8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad1_input_delay_shift                     (0)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad4_input_delay_mask                      (0x1F000000)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad3_input_delay_mask                      (0x001F0000)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad2_input_delay_mask                      (0x00001F00)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad1_input_delay_mask                      (0x0000001F)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad4_input_delay(data)                     (0x1F000000&((data)<<24))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad3_input_delay(data)                     (0x001F0000&((data)<<16))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad2_input_delay(data)                     (0x00001F00&((data)<<8))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_ad1_input_delay(data)                     (0x0000001F&(data))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad4_input_delay(data)                 ((0x1F000000&(data))>>24)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad3_input_delay(data)                 ((0x001F0000&(data))>>16)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad2_input_delay(data)                 ((0x00001F00&(data))>>8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL1_get_ad1_input_delay(data)                 (0x0000001F&(data))

#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2                                           0x180180A4
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg_addr                                  "0xB80180A4"
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg                                       0xB80180A4
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_inst_addr                                 "0x0029"
#define  set_VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg)=data)
#define  get_VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_VD_IN_DELAY_SEL2_reg))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_cvbs_tve_mux_shift                        (31)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_ad5_input_delay_shift                     (8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_sel_shift                              (2)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_yc_switch_shift                        (1)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_in_one_adc_shift                       (0)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_cvbs_tve_mux_mask                         (0x80000000)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_ad5_input_delay_mask                      (0x00001F00)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_sel_mask                               (0x0000000C)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_yc_switch_mask                         (0x00000002)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_in_one_adc_mask                        (0x00000001)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_cvbs_tve_mux(data)                        (0x80000000&((data)<<31))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_ad5_input_delay(data)                     (0x00001F00&((data)<<8))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_sel(data)                              (0x0000000C&((data)<<2))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_yc_switch(data)                        (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_sv_in_one_adc(data)                       (0x00000001&(data))
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_cvbs_tve_mux(data)                    ((0x80000000&(data))>>31)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_ad5_input_delay(data)                 ((0x00001F00&(data))>>8)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_sv_sel(data)                          ((0x0000000C&(data))>>2)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_sv_yc_switch(data)                    ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_VD_IN_DELAY_SEL2_get_sv_in_one_adc(data)                   (0x00000001&(data))

#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL                                            0x180180A8
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg_addr                                   "0xB80180A8"
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg                                        0xB80180A8
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_inst_addr                                  "0x002A"
#define  set_VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg(data)                              (*((volatile unsigned int*)VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg)=data)
#define  get_VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg                                    (*((volatile unsigned int*)VD_IFD_INPUT_VD_ADC_LSB_CTRL_reg))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_scart_input_delay_108_shift                (24)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppb_input_delay_108_shift                 (20)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppg_input_delay_108_shift                 (16)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppr_input_delay_108_shift                 (12)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_vdadc_input_delay_108_shift                (8)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc3_lsb_force0_num_shift                  (6)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc2_lsb_force0_num_shift                  (4)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc1_lsb_force0_num_shift                  (2)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc0_lsb_force0_num_shift                  (0)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_scart_input_delay_108_mask                 (0x0F000000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppb_input_delay_108_mask                  (0x00F00000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppg_input_delay_108_mask                  (0x000F0000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppr_input_delay_108_mask                  (0x0000F000)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_vdadc_input_delay_108_mask                 (0x00000F00)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc3_lsb_force0_num_mask                   (0x000000C0)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc2_lsb_force0_num_mask                   (0x00000030)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc1_lsb_force0_num_mask                   (0x0000000C)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc0_lsb_force0_num_mask                   (0x00000003)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_scart_input_delay_108(data)                (0x0F000000&((data)<<24))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppb_input_delay_108(data)                 (0x00F00000&((data)<<20))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppg_input_delay_108(data)                 (0x000F0000&((data)<<16))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_yppr_input_delay_108(data)                 (0x0000F000&((data)<<12))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_vdadc_input_delay_108(data)                (0x00000F00&((data)<<8))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc3_lsb_force0_num(data)                  (0x000000C0&((data)<<6))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc2_lsb_force0_num(data)                  (0x00000030&((data)<<4))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc1_lsb_force0_num(data)                  (0x0000000C&((data)<<2))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_adc0_lsb_force0_num(data)                  (0x00000003&(data))
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_scart_input_delay_108(data)            ((0x0F000000&(data))>>24)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_yppb_input_delay_108(data)             ((0x00F00000&(data))>>20)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_yppg_input_delay_108(data)             ((0x000F0000&(data))>>16)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_yppr_input_delay_108(data)             ((0x0000F000&(data))>>12)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_vdadc_input_delay_108(data)            ((0x00000F00&(data))>>8)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc3_lsb_force0_num(data)              ((0x000000C0&(data))>>6)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc2_lsb_force0_num(data)              ((0x00000030&(data))>>4)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc1_lsb_force0_num(data)              ((0x0000000C&(data))>>2)
#define  VD_IFD_INPUT_VD_ADC_LSB_CTRL_get_adc0_lsb_force0_num(data)              (0x00000003&(data))

#define  VD_IFD_INPUT_VD_INOUT_CTRL                                              0x180180AC
#define  VD_IFD_INPUT_VD_INOUT_CTRL_reg_addr                                     "0xB80180AC"
#define  VD_IFD_INPUT_VD_INOUT_CTRL_reg                                          0xB80180AC
#define  VD_IFD_INPUT_VD_INOUT_CTRL_inst_addr                                    "0x002B"
#define  set_VD_IFD_INPUT_VD_INOUT_CTRL_reg(data)                                (*((volatile unsigned int*)VD_IFD_INPUT_VD_INOUT_CTRL_reg)=data)
#define  get_VD_IFD_INPUT_VD_INOUT_CTRL_reg                                      (*((volatile unsigned int*)VD_IFD_INPUT_VD_INOUT_CTRL_reg))
#define  VD_IFD_INPUT_VD_INOUT_CTRL_fe_fil_sel_shift                             (4)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_adc27_mod_shift                              (0)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_fe_fil_sel_mask                              (0x00000070)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_adc27_mod_mask                               (0x00000001)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_fe_fil_sel(data)                             (0x00000070&((data)<<4))
#define  VD_IFD_INPUT_VD_INOUT_CTRL_adc27_mod(data)                              (0x00000001&(data))
#define  VD_IFD_INPUT_VD_INOUT_CTRL_get_fe_fil_sel(data)                         ((0x00000070&(data))>>4)
#define  VD_IFD_INPUT_VD_INOUT_CTRL_get_adc27_mod(data)                          (0x00000001&(data))

#define  VD_IFD_INPUT_CRC_EN                                                     0x180180B0
#define  VD_IFD_INPUT_CRC_EN_reg_addr                                            "0xB80180B0"
#define  VD_IFD_INPUT_CRC_EN_reg                                                 0xB80180B0
#define  VD_IFD_INPUT_CRC_EN_inst_addr                                           "0x002C"
#define  set_VD_IFD_INPUT_CRC_EN_reg(data)                                       (*((volatile unsigned int*)VD_IFD_INPUT_CRC_EN_reg)=data)
#define  get_VD_IFD_INPUT_CRC_EN_reg                                             (*((volatile unsigned int*)VD_IFD_INPUT_CRC_EN_reg))
#define  VD_IFD_INPUT_CRC_EN_crc_108mhz_en_shift                                 (0)
#define  VD_IFD_INPUT_CRC_EN_crc_108mhz_en_mask                                  (0x00000001)
#define  VD_IFD_INPUT_CRC_EN_crc_108mhz_en(data)                                 (0x00000001&(data))
#define  VD_IFD_INPUT_CRC_EN_get_crc_108mhz_en(data)                             (0x00000001&(data))

#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1                                         0x180180B4
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg_addr                                "0xB80180B4"
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg                                     0xB80180B4
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_inst_addr                               "0x002D"
#define  set_VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg(data)                           (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg)=data)
#define  get_VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg                                 (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT1_reg))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_crc_108mhz_result_1_shift               (0)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_crc_108mhz_result_1_mask                (0xFFFFFFFF)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_crc_108mhz_result_1(data)               (0xFFFFFFFF&(data))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT1_get_crc_108mhz_result_1(data)           (0xFFFFFFFF&(data))

#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2                                         0x180180B8
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg_addr                                "0xB80180B8"
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg                                     0xB80180B8
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_inst_addr                               "0x002E"
#define  set_VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg(data)                           (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg)=data)
#define  get_VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg                                 (*((volatile unsigned int*)VD_IFD_INPUT_CRC_108MHZ_RESULT2_reg))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_crc_108mhz_result_2_shift               (0)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_crc_108mhz_result_2_mask                (0xFFFFFFFF)
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_crc_108mhz_result_2(data)               (0xFFFFFFFF&(data))
#define  VD_IFD_INPUT_CRC_108MHZ_RESULT2_get_crc_108mhz_result_2(data)           (0xFFFFFFFF&(data))

#define  VD_IFD_INPUT_INPUT_DEBUG                                                0x180180BC
#define  VD_IFD_INPUT_INPUT_DEBUG_reg_addr                                       "0xB80180BC"
#define  VD_IFD_INPUT_INPUT_DEBUG_reg                                            0xB80180BC
#define  VD_IFD_INPUT_INPUT_DEBUG_inst_addr                                      "0x002F"
#define  set_VD_IFD_INPUT_INPUT_DEBUG_reg(data)                                  (*((volatile unsigned int*)VD_IFD_INPUT_INPUT_DEBUG_reg)=data)
#define  get_VD_IFD_INPUT_INPUT_DEBUG_reg                                        (*((volatile unsigned int*)VD_IFD_INPUT_INPUT_DEBUG_reg))
#define  VD_IFD_INPUT_INPUT_DEBUG_input_debug_sel_shift                          (0)
#define  VD_IFD_INPUT_INPUT_DEBUG_input_debug_sel_mask                           (0x00000003)
#define  VD_IFD_INPUT_INPUT_DEBUG_input_debug_sel(data)                          (0x00000003&(data))
#define  VD_IFD_INPUT_INPUT_DEBUG_get_input_debug_sel(data)                      (0x00000003&(data))

#define  VD_IFD_INPUT_IF_PATTERNGEN                                              0x180180C0
#define  VD_IFD_INPUT_IF_PATTERNGEN_reg_addr                                     "0xB80180C0"
#define  VD_IFD_INPUT_IF_PATTERNGEN_reg                                          0xB80180C0
#define  VD_IFD_INPUT_IF_PATTERNGEN_inst_addr                                    "0x0030"
#define  set_VD_IFD_INPUT_IF_PATTERNGEN_reg(data)                                (*((volatile unsigned int*)VD_IFD_INPUT_IF_PATTERNGEN_reg)=data)
#define  get_VD_IFD_INPUT_IF_PATTERNGEN_reg                                      (*((volatile unsigned int*)VD_IFD_INPUT_IF_PATTERNGEN_reg))
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_nco_shift                      (4)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_mod_sel_shift                  (1)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_en_shift                       (0)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_nco_mask                       (0x000FFFF0)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_mod_sel_mask                   (0x00000002)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_en_mask                        (0x00000001)
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_nco(data)                      (0x000FFFF0&((data)<<4))
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_mod_sel(data)                  (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_IF_PATTERNGEN_if_patterngen_en(data)                       (0x00000001&(data))
#define  VD_IFD_INPUT_IF_PATTERNGEN_get_if_patterngen_nco(data)                  ((0x000FFFF0&(data))>>4)
#define  VD_IFD_INPUT_IF_PATTERNGEN_get_if_patterngen_mod_sel(data)              ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_IF_PATTERNGEN_get_if_patterngen_en(data)                   (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS                                      0x180180D0
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg_addr                             "0xB80180D0"
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg                                  0xB80180D0
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_inst_addr                            "0x0031"
#define  set_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg)=data)
#define  get_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_reg))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_clr_shift         (20)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_clr_shift        (19)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_clr_shift              (18)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_shift             (17)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_shift            (16)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_clr_shift            (4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_clr_shift           (3)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_clr_shift                 (2)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_shift                (1)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_shift               (0)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_clr_mask          (0x00100000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_clr_mask         (0x00080000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_clr_mask               (0x00040000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_mask              (0x00020000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_mask             (0x00010000)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_clr_mask             (0x00000010)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_clr_mask            (0x00000008)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_clr_mask                  (0x00000004)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_mask                 (0x00000002)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_mask                (0x00000001)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full_clr(data)         (0x00100000&((data)<<20))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty_clr(data)        (0x00080000&((data)<<19))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_clr(data)              (0x00040000&((data)<<18))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_full(data)             (0x00020000&((data)<<17))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_pg_empty(data)            (0x00010000&((data)<<16))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full_clr(data)            (0x00000010&((data)<<4))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty_clr(data)           (0x00000008&((data)<<3))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_clr(data)                 (0x00000004&((data)<<2))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_full(data)                (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_input_fifo_empty(data)               (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_full_clr(data)     ((0x00100000&(data))>>20)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_empty_clr(data)    ((0x00080000&(data))>>19)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_clr(data)          ((0x00040000&(data))>>18)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_full(data)         ((0x00020000&(data))>>17)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_pg_empty(data)        ((0x00010000&(data))>>16)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_full_clr(data)        ((0x00000010&(data))>>4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_empty_clr(data)       ((0x00000008&(data))>>3)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_clr(data)             ((0x00000004&(data))>>2)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_full(data)            ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS_get_input_fifo_empty(data)           (0x00000001&(data))

#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1                                      0x180180D4
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg_addr                             "0xB80180D4"
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg                                  0xB80180D4
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_inst_addr                            "0x0032"
#define  set_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg)=data)
#define  get_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_reg))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_full_shift                  (28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_empty_shift                 (27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_full_shift                  (26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_empty_shift                 (25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_adc_sync_fifo_clr_shift              (24)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_full_shift           (23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_empty_shift          (22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_full_shift         (21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_empty_shift        (20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_full_shift         (19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_empty_shift        (18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_full_shift         (17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_empty_shift        (16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_full_shift           (15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_empty_shift          (14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_full_shift           (13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_empty_shift          (12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vd_fifo_clr_shift                    (8)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_full_shift                  (7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_empty_shift                 (6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_full_shift                  (5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_empty_shift                 (4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_full_shift                  (3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_empty_shift                 (2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_full_shift                  (1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_empty_shift                 (0)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_full_mask                   (0x10000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_empty_mask                  (0x08000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_full_mask                   (0x04000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_empty_mask                  (0x02000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_adc_sync_fifo_clr_mask               (0x01000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_full_mask            (0x00800000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_empty_mask           (0x00400000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_full_mask          (0x00200000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_empty_mask         (0x00100000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_full_mask          (0x00080000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_empty_mask         (0x00040000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_full_mask          (0x00020000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_empty_mask         (0x00010000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_full_mask            (0x00008000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_empty_mask           (0x00004000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_full_mask            (0x00002000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_empty_mask           (0x00001000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vd_fifo_clr_mask                     (0x00000100)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_full_mask                   (0x00000080)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_empty_mask                  (0x00000040)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_full_mask                   (0x00000020)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_empty_mask                  (0x00000010)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_full_mask                   (0x00000008)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_empty_mask                  (0x00000004)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_full_mask                   (0x00000002)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_empty_mask                  (0x00000001)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_full(data)                  (0x10000000&((data)<<28))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad_debug_empty(data)                 (0x08000000&((data)<<27))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_full(data)                  (0x04000000&((data)<<26))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad5_fifo_empty(data)                 (0x02000000&((data)<<25))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_adc_sync_fifo_clr(data)              (0x01000000&((data)<<24))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_full(data)           (0x00800000&((data)<<23))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vdadc_sync_fifo_empty(data)          (0x00400000&((data)<<22))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_full(data)         (0x00200000&((data)<<21))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_blu_sync_fifo_empty(data)        (0x00100000&((data)<<20))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_full(data)         (0x00080000&((data)<<19))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_grn_sync_fifo_empty(data)        (0x00040000&((data)<<18))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_full(data)         (0x00020000&((data)<<17))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ypp_red_sync_fifo_empty(data)        (0x00010000&((data)<<16))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_full(data)           (0x00008000&((data)<<15))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_scart_sync_fifo_empty(data)          (0x00004000&((data)<<14))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_full(data)           (0x00002000&((data)<<13))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ycref_sync_fifo_empty(data)          (0x00001000&((data)<<12))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_vd_fifo_clr(data)                    (0x00000100&((data)<<8))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_full(data)                  (0x00000080&((data)<<7))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad1_fifo_empty(data)                 (0x00000040&((data)<<6))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_full(data)                  (0x00000020&((data)<<5))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad2_fifo_empty(data)                 (0x00000010&((data)<<4))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_full(data)                  (0x00000008&((data)<<3))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad3_fifo_empty(data)                 (0x00000004&((data)<<2))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_full(data)                  (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_ad4_fifo_empty(data)                 (0x00000001&(data))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad_debug_full(data)              ((0x10000000&(data))>>28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad_debug_empty(data)             ((0x08000000&(data))>>27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad5_fifo_full(data)              ((0x04000000&(data))>>26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad5_fifo_empty(data)             ((0x02000000&(data))>>25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_adc_sync_fifo_clr(data)          ((0x01000000&(data))>>24)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_vdadc_sync_fifo_full(data)       ((0x00800000&(data))>>23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_vdadc_sync_fifo_empty(data)      ((0x00400000&(data))>>22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_blu_sync_fifo_full(data)     ((0x00200000&(data))>>21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_blu_sync_fifo_empty(data)    ((0x00100000&(data))>>20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_grn_sync_fifo_full(data)     ((0x00080000&(data))>>19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_grn_sync_fifo_empty(data)    ((0x00040000&(data))>>18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_red_sync_fifo_full(data)     ((0x00020000&(data))>>17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ypp_red_sync_fifo_empty(data)    ((0x00010000&(data))>>16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_scart_sync_fifo_full(data)       ((0x00008000&(data))>>15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_scart_sync_fifo_empty(data)      ((0x00004000&(data))>>14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ycref_sync_fifo_full(data)       ((0x00002000&(data))>>13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ycref_sync_fifo_empty(data)      ((0x00001000&(data))>>12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_vd_fifo_clr(data)                ((0x00000100&(data))>>8)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad1_fifo_full(data)              ((0x00000080&(data))>>7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad1_fifo_empty(data)             ((0x00000040&(data))>>6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad2_fifo_full(data)              ((0x00000020&(data))>>5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad2_fifo_empty(data)             ((0x00000010&(data))>>4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad3_fifo_full(data)              ((0x00000008&(data))>>3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad3_fifo_empty(data)             ((0x00000004&(data))>>2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad4_fifo_full(data)              ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS1_get_ad4_fifo_empty(data)             (0x00000001&(data))

#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2                                      0x180180D8
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg_addr                             "0xB80180D8"
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg                                  0xB80180D8
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_inst_addr                            "0x0033"
#define  set_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg)=data)
#define  get_VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_reg))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_full_clr_shift              (28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_empty_clr_shift             (27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_full_clr_shift              (26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_empty_clr_shift             (25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_full_clr_shift       (23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_empty_clr_shift      (22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_full_clr_shift     (21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_empty_clr_shift    (20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_full_clr_shift     (19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_empty_clr_shift    (18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_full_clr_shift     (17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_empty_clr_shift    (16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_full_clr_shift       (15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_empty_clr_shift      (14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_full_clr_shift       (13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_empty_clr_shift      (12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_full_clr_shift              (7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_empty_clr_shift             (6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_full_clr_shift              (5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_empty_clr_shift             (4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_full_clr_shift              (3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_empty_clr_shift             (2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_full_clr_shift              (1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_empty_clr_shift             (0)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_full_clr_mask               (0x10000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_empty_clr_mask              (0x08000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_full_clr_mask               (0x04000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_empty_clr_mask              (0x02000000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_full_clr_mask        (0x00800000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_empty_clr_mask       (0x00400000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_full_clr_mask      (0x00200000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_empty_clr_mask     (0x00100000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_full_clr_mask      (0x00080000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_empty_clr_mask     (0x00040000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_full_clr_mask      (0x00020000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_empty_clr_mask     (0x00010000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_full_clr_mask        (0x00008000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_empty_clr_mask       (0x00004000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_full_clr_mask        (0x00002000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_empty_clr_mask       (0x00001000)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_full_clr_mask               (0x00000080)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_empty_clr_mask              (0x00000040)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_full_clr_mask               (0x00000020)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_empty_clr_mask              (0x00000010)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_full_clr_mask               (0x00000008)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_empty_clr_mask              (0x00000004)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_full_clr_mask               (0x00000002)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_empty_clr_mask              (0x00000001)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_full_clr(data)              (0x10000000&((data)<<28))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad_debug_empty_clr(data)             (0x08000000&((data)<<27))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_full_clr(data)              (0x04000000&((data)<<26))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad5_fifo_empty_clr(data)             (0x02000000&((data)<<25))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_full_clr(data)       (0x00800000&((data)<<23))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_vdadc_sync_fifo_empty_clr(data)      (0x00400000&((data)<<22))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_full_clr(data)     (0x00200000&((data)<<21))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_blu_sync_fifo_empty_clr(data)    (0x00100000&((data)<<20))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_full_clr(data)     (0x00080000&((data)<<19))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_grn_sync_fifo_empty_clr(data)    (0x00040000&((data)<<18))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_full_clr(data)     (0x00020000&((data)<<17))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ypp_red_sync_fifo_empty_clr(data)    (0x00010000&((data)<<16))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_full_clr(data)       (0x00008000&((data)<<15))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_scart_sync_fifo_empty_clr(data)      (0x00004000&((data)<<14))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_full_clr(data)       (0x00002000&((data)<<13))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ycref_sync_fifo_empty_clr(data)      (0x00001000&((data)<<12))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_full_clr(data)              (0x00000080&((data)<<7))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad1_fifo_empty_clr(data)             (0x00000040&((data)<<6))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_full_clr(data)              (0x00000020&((data)<<5))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad2_fifo_empty_clr(data)             (0x00000010&((data)<<4))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_full_clr(data)              (0x00000008&((data)<<3))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad3_fifo_empty_clr(data)             (0x00000004&((data)<<2))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_full_clr(data)              (0x00000002&((data)<<1))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_ad4_fifo_empty_clr(data)             (0x00000001&(data))
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad_debug_full_clr(data)          ((0x10000000&(data))>>28)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad_debug_empty_clr(data)         ((0x08000000&(data))>>27)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad5_fifo_full_clr(data)          ((0x04000000&(data))>>26)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad5_fifo_empty_clr(data)         ((0x02000000&(data))>>25)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_vdadc_sync_fifo_full_clr(data)   ((0x00800000&(data))>>23)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_vdadc_sync_fifo_empty_clr(data)  ((0x00400000&(data))>>22)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_blu_sync_fifo_full_clr(data) ((0x00200000&(data))>>21)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_blu_sync_fifo_empty_clr(data) ((0x00100000&(data))>>20)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_grn_sync_fifo_full_clr(data) ((0x00080000&(data))>>19)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_grn_sync_fifo_empty_clr(data) ((0x00040000&(data))>>18)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_red_sync_fifo_full_clr(data) ((0x00020000&(data))>>17)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ypp_red_sync_fifo_empty_clr(data) ((0x00010000&(data))>>16)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_scart_sync_fifo_full_clr(data)   ((0x00008000&(data))>>15)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_scart_sync_fifo_empty_clr(data)  ((0x00004000&(data))>>14)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ycref_sync_fifo_full_clr(data)   ((0x00002000&(data))>>13)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ycref_sync_fifo_empty_clr(data)  ((0x00001000&(data))>>12)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad1_fifo_full_clr(data)          ((0x00000080&(data))>>7)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad1_fifo_empty_clr(data)         ((0x00000040&(data))>>6)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad2_fifo_full_clr(data)          ((0x00000020&(data))>>5)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad2_fifo_empty_clr(data)         ((0x00000010&(data))>>4)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad3_fifo_full_clr(data)          ((0x00000008&(data))>>3)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad3_fifo_empty_clr(data)         ((0x00000004&(data))>>2)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad4_fifo_full_clr(data)          ((0x00000002&(data))>>1)
#define  VD_IFD_INPUT_VD_INPUT_FIFO_STATUS2_get_ad4_fifo_empty_clr(data)         (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3                                     0x180180DC
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg_addr                            "0xB80180DC"
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg                                 0xB80180DC
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_inst_addr                           "0x0034"
#define  set_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg(data)                       (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg)=data)
#define  get_VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg                             (*((volatile unsigned int*)VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_reg))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_depth_shift            (8)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_thr_shift              (4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_en_shift               (0)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_depth_mask             (0x00000300)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_thr_mask               (0x00000070)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_en_mask                (0x00000001)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_depth(data)            (0x00000300&((data)<<8))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_thr(data)              (0x00000070&((data)<<4))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_fifo_recover_en(data)               (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_get_fifo_recover_depth(data)        ((0x00000300&(data))>>8)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_get_fifo_recover_thr(data)          ((0x00000070&(data))>>4)
#define  VD_IFD_INPUT_IFD_INPUT_FIFO_STATUS3_get_fifo_recover_en(data)           (0x00000001&(data))

#define  VD_IFD_INPUT_IFD_FIFO_CRC                                               0x180180E0
#define  VD_IFD_INPUT_IFD_FIFO_CRC_reg_addr                                      "0xB80180E0"
#define  VD_IFD_INPUT_IFD_FIFO_CRC_reg                                           0xB80180E0
#define  VD_IFD_INPUT_IFD_FIFO_CRC_inst_addr                                     "0x0035"
#define  set_VD_IFD_INPUT_IFD_FIFO_CRC_reg(data)                                 (*((volatile unsigned int*)VD_IFD_INPUT_IFD_FIFO_CRC_reg)=data)
#define  get_VD_IFD_INPUT_IFD_FIFO_CRC_reg                                       (*((volatile unsigned int*)VD_IFD_INPUT_IFD_FIFO_CRC_reg))
#define  VD_IFD_INPUT_IFD_FIFO_CRC_fifo_crc_en_shift                             (0)
#define  VD_IFD_INPUT_IFD_FIFO_CRC_fifo_crc_en_mask                              (0x00000001)
#define  VD_IFD_INPUT_IFD_FIFO_CRC_fifo_crc_en(data)                             (0x00000001&(data))
#define  VD_IFD_INPUT_IFD_FIFO_CRC_get_fifo_crc_en(data)                         (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VD_IFD_INPUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap1:13;
    };
}vd_ifd_input_input_flt_tap_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap3:13;
    };
}vd_ifd_input_input_flt_tap_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap5:13;
    };
}vd_ifd_input_input_flt_tap_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap6:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap7:13;
    };
}vd_ifd_input_input_flt_tap_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap8:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap9:13;
    };
}vd_ifd_input_input_flt_tap_8_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap10:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap11:13;
    };
}vd_ifd_input_input_flt_tap_10_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap12:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap13:13;
    };
}vd_ifd_input_input_flt_tap_12_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap14:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap15:13;
    };
}vd_ifd_input_input_flt_tap_14_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap16:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap17:13;
    };
}vd_ifd_input_input_flt_tap_16_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap18:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap19:13;
    };
}vd_ifd_input_input_flt_tap_18_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap20:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap21:13;
    };
}vd_ifd_input_input_flt_tap_20_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap22:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap23:13;
    };
}vd_ifd_input_input_flt_tap_22_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap24:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap25:13;
    };
}vd_ifd_input_input_flt_tap_24_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap26:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap27:13;
    };
}vd_ifd_input_input_flt_tap_26_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap28:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap29:13;
    };
}vd_ifd_input_input_flt_tap_28_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap30:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap31:13;
    };
}vd_ifd_input_input_flt_tap_30_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap32:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap33:13;
    };
}vd_ifd_input_input_flt_tap_32_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap34:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap35:13;
    };
}vd_ifd_input_input_flt_tap_34_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap36:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap37:13;
    };
}vd_ifd_input_input_flt_tap_36_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap38:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap39:13;
    };
}vd_ifd_input_input_flt_tap_38_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap40:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap41:13;
    };
}vd_ifd_input_input_flt_tap_40_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap42:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap43:13;
    };
}vd_ifd_input_input_flt_tap_42_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap44:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap45:13;
    };
}vd_ifd_input_input_flt_tap_44_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap46:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap47:13;
    };
}vd_ifd_input_input_flt_tap_46_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap48:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap49:13;
    };
}vd_ifd_input_input_flt_tap_48_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap50:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap51:13;
    };
}vd_ifd_input_input_flt_tap_50_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap52:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap53:13;
    };
}vd_ifd_input_input_flt_tap_52_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap54:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap55:13;
    };
}vd_ifd_input_input_flt_tap_54_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap56:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap57:13;
    };
}vd_ifd_input_input_flt_tap_56_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap58:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap59:13;
    };
}vd_ifd_input_input_flt_tap_58_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap60:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap61:13;
    };
}vd_ifd_input_input_flt_tap_60_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap62:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap63:13;
    };
}vd_ifd_input_input_flt_tap_62_63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap64:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap65:13;
    };
}vd_ifd_input_input_flt_tap_64_65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap66:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap67:13;
    };
}vd_ifd_input_input_flt_tap_66_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap68:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap69:13;
    };
}vd_ifd_input_input_flt_tap_68_69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap70:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap71:13;
    };
}vd_ifd_input_input_flt_tap_70_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  input_flt_en:1;
    };
}vd_ifd_input_input_flt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  adc_fifo_in_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_clk_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  input_dn_filter_sel:3;
    };
}vd_ifd_input_input_filter_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ls_adcclk_polar:1;
        RBus_UInt32  clk54_polar:1;
    };
}vd_ifd_input_ifd_adc_clk_polar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cp_test_enable:1;
    };
}vd_ifd_input_ifd_cp_test_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ad4_input_delay:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ad3_input_delay:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ad2_input_delay:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  ad1_input_delay:5;
    };
}vd_ifd_input_vd_in_delay_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cvbs_tve_mux:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  ad5_input_delay:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  sv_sel:2;
        RBus_UInt32  sv_yc_switch:1;
        RBus_UInt32  sv_in_one_adc:1;
    };
}vd_ifd_input_vd_in_delay_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  scart_input_delay_108:4;
        RBus_UInt32  yppb_input_delay_108:4;
        RBus_UInt32  yppg_input_delay_108:4;
        RBus_UInt32  yppr_input_delay_108:4;
        RBus_UInt32  vdadc_input_delay_108:4;
        RBus_UInt32  adc3_lsb_force0_num:2;
        RBus_UInt32  adc2_lsb_force0_num:2;
        RBus_UInt32  adc1_lsb_force0_num:2;
        RBus_UInt32  adc0_lsb_force0_num:2;
    };
}vd_ifd_input_vd_adc_lsb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  fe_fil_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  adc27_mod:1;
    };
}vd_ifd_input_vd_inout_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  crc_108mhz_en:1;
    };
}vd_ifd_input_crc_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_1:32;
    };
}vd_ifd_input_crc_108mhz_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_2:32;
    };
}vd_ifd_input_crc_108mhz_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  input_debug_sel:2;
    };
}vd_ifd_input_input_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  if_patterngen_nco:16;
        RBus_UInt32  res2:2;
        RBus_UInt32  if_patterngen_mod_sel:1;
        RBus_UInt32  if_patterngen_en:1;
    };
}vd_ifd_input_if_patterngen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  input_fifo_pg_full_clr:1;
        RBus_UInt32  input_fifo_pg_empty_clr:1;
        RBus_UInt32  input_fifo_pg_clr:1;
        RBus_UInt32  input_fifo_pg_full:1;
        RBus_UInt32  input_fifo_pg_empty:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  input_fifo_full_clr:1;
        RBus_UInt32  input_fifo_empty_clr:1;
        RBus_UInt32  input_fifo_clr:1;
        RBus_UInt32  input_fifo_full:1;
        RBus_UInt32  input_fifo_empty:1;
    };
}vd_ifd_input_ifd_input_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ad_debug_full:1;
        RBus_UInt32  ad_debug_empty:1;
        RBus_UInt32  ad5_fifo_full:1;
        RBus_UInt32  ad5_fifo_empty:1;
        RBus_UInt32  adc_sync_fifo_clr:1;
        RBus_UInt32  vdadc_sync_fifo_full:1;
        RBus_UInt32  vdadc_sync_fifo_empty:1;
        RBus_UInt32  ypp_blu_sync_fifo_full:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty:1;
        RBus_UInt32  ypp_grn_sync_fifo_full:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty:1;
        RBus_UInt32  ypp_red_sync_fifo_full:1;
        RBus_UInt32  ypp_red_sync_fifo_empty:1;
        RBus_UInt32  scart_sync_fifo_full:1;
        RBus_UInt32  scart_sync_fifo_empty:1;
        RBus_UInt32  ycref_sync_fifo_full:1;
        RBus_UInt32  ycref_sync_fifo_empty:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  vd_fifo_clr:1;
        RBus_UInt32  ad1_fifo_full:1;
        RBus_UInt32  ad1_fifo_empty:1;
        RBus_UInt32  ad2_fifo_full:1;
        RBus_UInt32  ad2_fifo_empty:1;
        RBus_UInt32  ad3_fifo_full:1;
        RBus_UInt32  ad3_fifo_empty:1;
        RBus_UInt32  ad4_fifo_full:1;
        RBus_UInt32  ad4_fifo_empty:1;
    };
}vd_ifd_input_vd_input_fifo_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ad_debug_full_clr:1;
        RBus_UInt32  ad_debug_empty_clr:1;
        RBus_UInt32  ad5_fifo_full_clr:1;
        RBus_UInt32  ad5_fifo_empty_clr:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vdadc_sync_fifo_full_clr:1;
        RBus_UInt32  vdadc_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_empty_clr:1;
        RBus_UInt32  scart_sync_fifo_full_clr:1;
        RBus_UInt32  scart_sync_fifo_empty_clr:1;
        RBus_UInt32  ycref_sync_fifo_full_clr:1;
        RBus_UInt32  ycref_sync_fifo_empty_clr:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  ad1_fifo_full_clr:1;
        RBus_UInt32  ad1_fifo_empty_clr:1;
        RBus_UInt32  ad2_fifo_full_clr:1;
        RBus_UInt32  ad2_fifo_empty_clr:1;
        RBus_UInt32  ad3_fifo_full_clr:1;
        RBus_UInt32  ad3_fifo_empty_clr:1;
        RBus_UInt32  ad4_fifo_full_clr:1;
        RBus_UInt32  ad4_fifo_empty_clr:1;
    };
}vd_ifd_input_vd_input_fifo_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  fifo_recover_depth:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  fifo_recover_thr:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  fifo_recover_en:1;
    };
}vd_ifd_input_ifd_input_fifo_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  fifo_crc_en:1;
    };
}vd_ifd_input_ifd_fifo_crc_RBUS;

#else //apply LITTLE_ENDIAN

//======VD_IFD_INPUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap0:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap2:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap5:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap4:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap7:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap6:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap9:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap8:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_8_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap11:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap10:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_10_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap13:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap12:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_12_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap15:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap14:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_14_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap17:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap16:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_16_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap19:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap18:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_18_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap21:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap20:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_20_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap23:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap22:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_22_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap25:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap24:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_24_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap27:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap26:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_26_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap29:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap28:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_28_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap31:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap30:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_30_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap33:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap32:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_32_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap35:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap34:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_34_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap37:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap36:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_36_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap39:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap38:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_38_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap41:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap40:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_40_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap43:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap42:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_42_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap45:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap44:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_44_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap47:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap46:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_46_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap49:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap48:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_48_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap51:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap50:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_50_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap53:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap52:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_52_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap55:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap54:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_54_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap57:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap56:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_56_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap59:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap58:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_58_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap61:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap60:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_60_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap63:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap62:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_62_63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap65:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap64:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_64_65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap67:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap66:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_66_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap69:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap68:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_68_69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap71:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap70:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_input_flt_tap_70_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_en:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_input_flt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_dn_filter_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  adc_clk_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  adc_fifo_in_sel:1;
        RBus_UInt32  res3:23;
    };
}vd_ifd_input_input_filter_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk54_polar:1;
        RBus_UInt32  ls_adcclk_polar:1;
        RBus_UInt32  res1:30;
    };
}vd_ifd_input_ifd_adc_clk_polar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_test_enable:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_ifd_cp_test_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad1_input_delay:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ad2_input_delay:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ad3_input_delay:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ad4_input_delay:5;
        RBus_UInt32  res4:3;
    };
}vd_ifd_input_vd_in_delay_sel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_in_one_adc:1;
        RBus_UInt32  sv_yc_switch:1;
        RBus_UInt32  sv_sel:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  ad5_input_delay:5;
        RBus_UInt32  res2:18;
        RBus_UInt32  cvbs_tve_mux:1;
    };
}vd_ifd_input_vd_in_delay_sel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc0_lsb_force0_num:2;
        RBus_UInt32  adc1_lsb_force0_num:2;
        RBus_UInt32  adc2_lsb_force0_num:2;
        RBus_UInt32  adc3_lsb_force0_num:2;
        RBus_UInt32  vdadc_input_delay_108:4;
        RBus_UInt32  yppr_input_delay_108:4;
        RBus_UInt32  yppg_input_delay_108:4;
        RBus_UInt32  yppb_input_delay_108:4;
        RBus_UInt32  scart_input_delay_108:4;
        RBus_UInt32  res1:4;
    };
}vd_ifd_input_vd_adc_lsb_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc27_mod:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fe_fil_sel:3;
        RBus_UInt32  res2:25;
    };
}vd_ifd_input_vd_inout_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_en:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_crc_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_1:32;
    };
}vd_ifd_input_crc_108mhz_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_108mhz_result_2:32;
    };
}vd_ifd_input_crc_108mhz_result2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_debug_sel:2;
        RBus_UInt32  res1:30;
    };
}vd_ifd_input_input_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  if_patterngen_en:1;
        RBus_UInt32  if_patterngen_mod_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  if_patterngen_nco:16;
        RBus_UInt32  res2:12;
    };
}vd_ifd_input_if_patterngen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_fifo_empty:1;
        RBus_UInt32  input_fifo_full:1;
        RBus_UInt32  input_fifo_clr:1;
        RBus_UInt32  input_fifo_empty_clr:1;
        RBus_UInt32  input_fifo_full_clr:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  input_fifo_pg_empty:1;
        RBus_UInt32  input_fifo_pg_full:1;
        RBus_UInt32  input_fifo_pg_clr:1;
        RBus_UInt32  input_fifo_pg_empty_clr:1;
        RBus_UInt32  input_fifo_pg_full_clr:1;
        RBus_UInt32  res2:11;
    };
}vd_ifd_input_ifd_input_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_fifo_empty:1;
        RBus_UInt32  ad4_fifo_full:1;
        RBus_UInt32  ad3_fifo_empty:1;
        RBus_UInt32  ad3_fifo_full:1;
        RBus_UInt32  ad2_fifo_empty:1;
        RBus_UInt32  ad2_fifo_full:1;
        RBus_UInt32  ad1_fifo_empty:1;
        RBus_UInt32  ad1_fifo_full:1;
        RBus_UInt32  vd_fifo_clr:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ycref_sync_fifo_empty:1;
        RBus_UInt32  ycref_sync_fifo_full:1;
        RBus_UInt32  scart_sync_fifo_empty:1;
        RBus_UInt32  scart_sync_fifo_full:1;
        RBus_UInt32  ypp_red_sync_fifo_empty:1;
        RBus_UInt32  ypp_red_sync_fifo_full:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty:1;
        RBus_UInt32  ypp_grn_sync_fifo_full:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty:1;
        RBus_UInt32  ypp_blu_sync_fifo_full:1;
        RBus_UInt32  vdadc_sync_fifo_empty:1;
        RBus_UInt32  vdadc_sync_fifo_full:1;
        RBus_UInt32  adc_sync_fifo_clr:1;
        RBus_UInt32  ad5_fifo_empty:1;
        RBus_UInt32  ad5_fifo_full:1;
        RBus_UInt32  ad_debug_empty:1;
        RBus_UInt32  ad_debug_full:1;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_vd_input_fifo_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad4_fifo_empty_clr:1;
        RBus_UInt32  ad4_fifo_full_clr:1;
        RBus_UInt32  ad3_fifo_empty_clr:1;
        RBus_UInt32  ad3_fifo_full_clr:1;
        RBus_UInt32  ad2_fifo_empty_clr:1;
        RBus_UInt32  ad2_fifo_full_clr:1;
        RBus_UInt32  ad1_fifo_empty_clr:1;
        RBus_UInt32  ad1_fifo_full_clr:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  ycref_sync_fifo_empty_clr:1;
        RBus_UInt32  ycref_sync_fifo_full_clr:1;
        RBus_UInt32  scart_sync_fifo_empty_clr:1;
        RBus_UInt32  scart_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_red_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_grn_sync_fifo_full_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_empty_clr:1;
        RBus_UInt32  ypp_blu_sync_fifo_full_clr:1;
        RBus_UInt32  vdadc_sync_fifo_empty_clr:1;
        RBus_UInt32  vdadc_sync_fifo_full_clr:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ad5_fifo_empty_clr:1;
        RBus_UInt32  ad5_fifo_full_clr:1;
        RBus_UInt32  ad_debug_empty_clr:1;
        RBus_UInt32  ad_debug_full_clr:1;
        RBus_UInt32  res3:3;
    };
}vd_ifd_input_vd_input_fifo_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_recover_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fifo_recover_thr:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  fifo_recover_depth:2;
        RBus_UInt32  res3:22;
    };
}vd_ifd_input_ifd_input_fifo_status3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_crc_en:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_ifd_fifo_crc_RBUS;




#endif 


#endif 
