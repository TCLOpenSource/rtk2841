/**
* @file Mac5-DesignSpec_vd_ifd_input_108
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VD_IFD_INPUT_108_REG_H_
#define _RBUS_VD_IFD_INPUT_108_REG_H_

#include "rbus_types.h"



//  VD_IFD_INPUT_108 Register Address
#define  VD_IFD_INPUT_108_input_flt_tap_0_1                                      0x18018000
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_reg_addr                             "0xB8018000"
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_reg                                  0xB8018000
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_inst_addr                            "0x0000"
#define  set_VD_IFD_INPUT_108_input_flt_tap_0_1_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_0_1_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_0_1_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_0_1_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_input_flt_tap0_shift                 (16)
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_input_flt_tap1_shift                 (0)
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_input_flt_tap0_mask                  (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_input_flt_tap1_mask                  (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_input_flt_tap0(data)                 (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_input_flt_tap1(data)                 (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_get_input_flt_tap0(data)             ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_0_1_get_input_flt_tap1(data)             (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_2_3                                      0x18018004
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_reg_addr                             "0xB8018004"
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_reg                                  0xB8018004
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_inst_addr                            "0x0001"
#define  set_VD_IFD_INPUT_108_input_flt_tap_2_3_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_2_3_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_2_3_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_2_3_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_input_flt_tap2_shift                 (16)
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_input_flt_tap3_shift                 (0)
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_input_flt_tap2_mask                  (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_input_flt_tap3_mask                  (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_input_flt_tap2(data)                 (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_input_flt_tap3(data)                 (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_get_input_flt_tap2(data)             ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_2_3_get_input_flt_tap3(data)             (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_4_5                                      0x18018008
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_reg_addr                             "0xB8018008"
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_reg                                  0xB8018008
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_inst_addr                            "0x0002"
#define  set_VD_IFD_INPUT_108_input_flt_tap_4_5_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_4_5_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_4_5_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_4_5_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_input_flt_tap4_shift                 (16)
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_input_flt_tap5_shift                 (0)
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_input_flt_tap4_mask                  (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_input_flt_tap5_mask                  (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_input_flt_tap4(data)                 (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_input_flt_tap5(data)                 (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_get_input_flt_tap4(data)             ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_4_5_get_input_flt_tap5(data)             (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_6_7                                      0x1801800C
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_reg_addr                             "0xB801800C"
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_reg                                  0xB801800C
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_inst_addr                            "0x0003"
#define  set_VD_IFD_INPUT_108_input_flt_tap_6_7_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_6_7_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_6_7_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_6_7_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_input_flt_tap6_shift                 (16)
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_input_flt_tap7_shift                 (0)
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_input_flt_tap6_mask                  (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_input_flt_tap7_mask                  (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_input_flt_tap6(data)                 (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_input_flt_tap7(data)                 (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_get_input_flt_tap6(data)             ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_6_7_get_input_flt_tap7(data)             (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_8_9                                      0x18018010
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_reg_addr                             "0xB8018010"
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_reg                                  0xB8018010
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_inst_addr                            "0x0004"
#define  set_VD_IFD_INPUT_108_input_flt_tap_8_9_reg(data)                        (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_8_9_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_8_9_reg                              (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_8_9_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_input_flt_tap8_shift                 (16)
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_input_flt_tap9_shift                 (0)
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_input_flt_tap8_mask                  (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_input_flt_tap9_mask                  (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_input_flt_tap8(data)                 (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_input_flt_tap9(data)                 (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_get_input_flt_tap8(data)             ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_8_9_get_input_flt_tap9(data)             (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_10_11                                    0x18018014
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_reg_addr                           "0xB8018014"
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_reg                                0xB8018014
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_inst_addr                          "0x0005"
#define  set_VD_IFD_INPUT_108_input_flt_tap_10_11_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_10_11_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_10_11_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_10_11_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_input_flt_tap10_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_input_flt_tap11_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_input_flt_tap10_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_input_flt_tap11_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_input_flt_tap10(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_input_flt_tap11(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_get_input_flt_tap10(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_10_11_get_input_flt_tap11(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_12_13                                    0x18018018
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_reg_addr                           "0xB8018018"
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_reg                                0xB8018018
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_inst_addr                          "0x0006"
#define  set_VD_IFD_INPUT_108_input_flt_tap_12_13_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_12_13_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_12_13_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_12_13_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_input_flt_tap12_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_input_flt_tap13_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_input_flt_tap12_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_input_flt_tap13_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_input_flt_tap12(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_input_flt_tap13(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_get_input_flt_tap12(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_12_13_get_input_flt_tap13(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_14_15                                    0x1801801C
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_reg_addr                           "0xB801801C"
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_reg                                0xB801801C
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_inst_addr                          "0x0007"
#define  set_VD_IFD_INPUT_108_input_flt_tap_14_15_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_14_15_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_14_15_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_14_15_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_input_flt_tap14_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_input_flt_tap15_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_input_flt_tap14_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_input_flt_tap15_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_input_flt_tap14(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_input_flt_tap15(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_get_input_flt_tap14(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_14_15_get_input_flt_tap15(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_16_17                                    0x18018020
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_reg_addr                           "0xB8018020"
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_reg                                0xB8018020
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_inst_addr                          "0x0008"
#define  set_VD_IFD_INPUT_108_input_flt_tap_16_17_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_16_17_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_16_17_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_16_17_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_input_flt_tap16_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_input_flt_tap17_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_input_flt_tap16_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_input_flt_tap17_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_input_flt_tap16(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_input_flt_tap17(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_get_input_flt_tap16(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_16_17_get_input_flt_tap17(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_18_19                                    0x18018024
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_reg_addr                           "0xB8018024"
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_reg                                0xB8018024
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_inst_addr                          "0x0009"
#define  set_VD_IFD_INPUT_108_input_flt_tap_18_19_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_18_19_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_18_19_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_18_19_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_input_flt_tap18_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_input_flt_tap19_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_input_flt_tap18_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_input_flt_tap19_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_input_flt_tap18(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_input_flt_tap19(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_get_input_flt_tap18(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_18_19_get_input_flt_tap19(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_20_21                                    0x18018028
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_reg_addr                           "0xB8018028"
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_reg                                0xB8018028
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_inst_addr                          "0x000A"
#define  set_VD_IFD_INPUT_108_input_flt_tap_20_21_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_20_21_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_20_21_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_20_21_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_input_flt_tap20_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_input_flt_tap21_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_input_flt_tap20_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_input_flt_tap21_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_input_flt_tap20(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_input_flt_tap21(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_get_input_flt_tap20(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_20_21_get_input_flt_tap21(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_22_23                                    0x1801802C
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_reg_addr                           "0xB801802C"
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_reg                                0xB801802C
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_inst_addr                          "0x000B"
#define  set_VD_IFD_INPUT_108_input_flt_tap_22_23_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_22_23_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_22_23_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_22_23_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_input_flt_tap22_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_input_flt_tap23_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_input_flt_tap22_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_input_flt_tap23_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_input_flt_tap22(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_input_flt_tap23(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_get_input_flt_tap22(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_22_23_get_input_flt_tap23(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_24_25                                    0x18018030
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_reg_addr                           "0xB8018030"
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_reg                                0xB8018030
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_inst_addr                          "0x000C"
#define  set_VD_IFD_INPUT_108_input_flt_tap_24_25_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_24_25_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_24_25_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_24_25_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_input_flt_tap24_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_input_flt_tap25_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_input_flt_tap24_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_input_flt_tap25_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_input_flt_tap24(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_input_flt_tap25(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_get_input_flt_tap24(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_24_25_get_input_flt_tap25(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_26_27                                    0x18018034
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_reg_addr                           "0xB8018034"
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_reg                                0xB8018034
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_inst_addr                          "0x000D"
#define  set_VD_IFD_INPUT_108_input_flt_tap_26_27_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_26_27_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_26_27_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_26_27_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_input_flt_tap26_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_input_flt_tap27_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_input_flt_tap26_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_input_flt_tap27_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_input_flt_tap26(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_input_flt_tap27(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_get_input_flt_tap26(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_26_27_get_input_flt_tap27(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_28_29                                    0x18018038
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_reg_addr                           "0xB8018038"
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_reg                                0xB8018038
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_inst_addr                          "0x000E"
#define  set_VD_IFD_INPUT_108_input_flt_tap_28_29_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_28_29_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_28_29_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_28_29_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_input_flt_tap28_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_input_flt_tap29_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_input_flt_tap28_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_input_flt_tap29_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_input_flt_tap28(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_input_flt_tap29(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_get_input_flt_tap28(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_28_29_get_input_flt_tap29(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_30_31                                    0x1801803C
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_reg_addr                           "0xB801803C"
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_reg                                0xB801803C
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_inst_addr                          "0x000F"
#define  set_VD_IFD_INPUT_108_input_flt_tap_30_31_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_30_31_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_30_31_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_30_31_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_input_flt_tap30_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_input_flt_tap31_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_input_flt_tap30_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_input_flt_tap31_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_input_flt_tap30(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_input_flt_tap31(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_get_input_flt_tap30(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_30_31_get_input_flt_tap31(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_32_33                                    0x18018040
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_reg_addr                           "0xB8018040"
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_reg                                0xB8018040
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_inst_addr                          "0x0010"
#define  set_VD_IFD_INPUT_108_input_flt_tap_32_33_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_32_33_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_32_33_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_32_33_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_input_flt_tap32_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_input_flt_tap33_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_input_flt_tap32_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_input_flt_tap33_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_input_flt_tap32(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_input_flt_tap33(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_get_input_flt_tap32(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_32_33_get_input_flt_tap33(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_34_35                                    0x18018044
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_reg_addr                           "0xB8018044"
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_reg                                0xB8018044
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_inst_addr                          "0x0011"
#define  set_VD_IFD_INPUT_108_input_flt_tap_34_35_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_34_35_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_34_35_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_34_35_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_input_flt_tap34_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_input_flt_tap35_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_input_flt_tap34_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_input_flt_tap35_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_input_flt_tap34(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_input_flt_tap35(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_get_input_flt_tap34(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_34_35_get_input_flt_tap35(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_36_37                                    0x18018048
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_reg_addr                           "0xB8018048"
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_reg                                0xB8018048
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_inst_addr                          "0x0012"
#define  set_VD_IFD_INPUT_108_input_flt_tap_36_37_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_36_37_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_36_37_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_36_37_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_input_flt_tap36_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_input_flt_tap37_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_input_flt_tap36_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_input_flt_tap37_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_input_flt_tap36(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_input_flt_tap37(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_get_input_flt_tap36(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_36_37_get_input_flt_tap37(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_38_39                                    0x1801804C
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_reg_addr                           "0xB801804C"
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_reg                                0xB801804C
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_inst_addr                          "0x0013"
#define  set_VD_IFD_INPUT_108_input_flt_tap_38_39_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_38_39_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_38_39_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_38_39_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_input_flt_tap38_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_input_flt_tap39_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_input_flt_tap38_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_input_flt_tap39_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_input_flt_tap38(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_input_flt_tap39(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_get_input_flt_tap38(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_38_39_get_input_flt_tap39(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_40_41                                    0x18018050
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_reg_addr                           "0xB8018050"
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_reg                                0xB8018050
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_inst_addr                          "0x0014"
#define  set_VD_IFD_INPUT_108_input_flt_tap_40_41_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_40_41_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_40_41_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_40_41_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_input_flt_tap40_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_input_flt_tap41_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_input_flt_tap40_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_input_flt_tap41_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_input_flt_tap40(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_input_flt_tap41(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_get_input_flt_tap40(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_40_41_get_input_flt_tap41(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_42_43                                    0x18018054
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_reg_addr                           "0xB8018054"
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_reg                                0xB8018054
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_inst_addr                          "0x0015"
#define  set_VD_IFD_INPUT_108_input_flt_tap_42_43_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_42_43_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_42_43_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_42_43_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_input_flt_tap42_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_input_flt_tap43_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_input_flt_tap42_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_input_flt_tap43_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_input_flt_tap42(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_input_flt_tap43(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_get_input_flt_tap42(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_42_43_get_input_flt_tap43(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_44_45                                    0x18018058
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_reg_addr                           "0xB8018058"
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_reg                                0xB8018058
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_inst_addr                          "0x0016"
#define  set_VD_IFD_INPUT_108_input_flt_tap_44_45_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_44_45_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_44_45_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_44_45_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_input_flt_tap44_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_input_flt_tap45_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_input_flt_tap44_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_input_flt_tap45_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_input_flt_tap44(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_input_flt_tap45(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_get_input_flt_tap44(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_44_45_get_input_flt_tap45(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_46_47                                    0x1801805C
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_reg_addr                           "0xB801805C"
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_reg                                0xB801805C
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_inst_addr                          "0x0017"
#define  set_VD_IFD_INPUT_108_input_flt_tap_46_47_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_46_47_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_46_47_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_46_47_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_input_flt_tap46_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_input_flt_tap47_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_input_flt_tap46_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_input_flt_tap47_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_input_flt_tap46(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_input_flt_tap47(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_get_input_flt_tap46(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_46_47_get_input_flt_tap47(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_48_49                                    0x18018060
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_reg_addr                           "0xB8018060"
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_reg                                0xB8018060
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_inst_addr                          "0x0018"
#define  set_VD_IFD_INPUT_108_input_flt_tap_48_49_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_48_49_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_48_49_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_48_49_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_input_flt_tap48_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_input_flt_tap49_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_input_flt_tap48_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_input_flt_tap49_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_input_flt_tap48(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_input_flt_tap49(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_get_input_flt_tap48(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_48_49_get_input_flt_tap49(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_50_51                                    0x18018064
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_reg_addr                           "0xB8018064"
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_reg                                0xB8018064
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_inst_addr                          "0x0019"
#define  set_VD_IFD_INPUT_108_input_flt_tap_50_51_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_50_51_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_50_51_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_50_51_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_input_flt_tap50_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_input_flt_tap51_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_input_flt_tap50_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_input_flt_tap51_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_input_flt_tap50(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_input_flt_tap51(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_get_input_flt_tap50(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_50_51_get_input_flt_tap51(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_52_53                                    0x18018068
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_reg_addr                           "0xB8018068"
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_reg                                0xB8018068
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_inst_addr                          "0x001A"
#define  set_VD_IFD_INPUT_108_input_flt_tap_52_53_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_52_53_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_52_53_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_52_53_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_input_flt_tap52_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_input_flt_tap53_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_input_flt_tap52_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_input_flt_tap53_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_input_flt_tap52(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_input_flt_tap53(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_get_input_flt_tap52(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_52_53_get_input_flt_tap53(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_54_55                                    0x1801806C
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_reg_addr                           "0xB801806C"
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_reg                                0xB801806C
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_inst_addr                          "0x001B"
#define  set_VD_IFD_INPUT_108_input_flt_tap_54_55_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_54_55_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_54_55_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_54_55_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_input_flt_tap54_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_input_flt_tap55_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_input_flt_tap54_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_input_flt_tap55_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_input_flt_tap54(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_input_flt_tap55(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_get_input_flt_tap54(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_54_55_get_input_flt_tap55(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_56_57                                    0x18018070
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_reg_addr                           "0xB8018070"
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_reg                                0xB8018070
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_inst_addr                          "0x001C"
#define  set_VD_IFD_INPUT_108_input_flt_tap_56_57_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_56_57_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_56_57_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_56_57_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_input_flt_tap56_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_input_flt_tap57_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_input_flt_tap56_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_input_flt_tap57_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_input_flt_tap56(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_input_flt_tap57(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_get_input_flt_tap56(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_56_57_get_input_flt_tap57(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_58_59                                    0x18018074
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_reg_addr                           "0xB8018074"
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_reg                                0xB8018074
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_inst_addr                          "0x001D"
#define  set_VD_IFD_INPUT_108_input_flt_tap_58_59_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_58_59_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_58_59_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_58_59_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_input_flt_tap58_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_input_flt_tap59_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_input_flt_tap58_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_input_flt_tap59_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_input_flt_tap58(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_input_flt_tap59(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_get_input_flt_tap58(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_58_59_get_input_flt_tap59(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_60_61                                    0x18018078
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_reg_addr                           "0xB8018078"
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_reg                                0xB8018078
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_inst_addr                          "0x001E"
#define  set_VD_IFD_INPUT_108_input_flt_tap_60_61_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_60_61_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_60_61_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_60_61_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_input_flt_tap60_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_input_flt_tap61_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_input_flt_tap60_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_input_flt_tap61_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_input_flt_tap60(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_input_flt_tap61(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_get_input_flt_tap60(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_60_61_get_input_flt_tap61(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_62_63                                    0x1801807C
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_reg_addr                           "0xB801807C"
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_reg                                0xB801807C
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_inst_addr                          "0x001F"
#define  set_VD_IFD_INPUT_108_input_flt_tap_62_63_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_62_63_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_62_63_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_62_63_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_input_flt_tap62_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_input_flt_tap63_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_input_flt_tap62_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_input_flt_tap63_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_input_flt_tap62(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_input_flt_tap63(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_get_input_flt_tap62(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_62_63_get_input_flt_tap63(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_64_65                                    0x18018080
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_reg_addr                           "0xB8018080"
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_reg                                0xB8018080
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_inst_addr                          "0x0020"
#define  set_VD_IFD_INPUT_108_input_flt_tap_64_65_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_64_65_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_64_65_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_64_65_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_input_flt_tap64_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_input_flt_tap65_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_input_flt_tap64_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_input_flt_tap65_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_input_flt_tap64(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_input_flt_tap65(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_get_input_flt_tap64(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_64_65_get_input_flt_tap65(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_66_67                                    0x18018084
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_reg_addr                           "0xB8018084"
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_reg                                0xB8018084
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_inst_addr                          "0x0021"
#define  set_VD_IFD_INPUT_108_input_flt_tap_66_67_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_66_67_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_66_67_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_66_67_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_input_flt_tap66_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_input_flt_tap67_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_input_flt_tap66_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_input_flt_tap67_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_input_flt_tap66(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_input_flt_tap67(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_get_input_flt_tap66(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_66_67_get_input_flt_tap67(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_68_69                                    0x18018088
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_reg_addr                           "0xB8018088"
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_reg                                0xB8018088
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_inst_addr                          "0x0022"
#define  set_VD_IFD_INPUT_108_input_flt_tap_68_69_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_68_69_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_68_69_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_68_69_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_input_flt_tap68_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_input_flt_tap69_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_input_flt_tap68_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_input_flt_tap69_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_input_flt_tap68(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_input_flt_tap69(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_get_input_flt_tap68(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_68_69_get_input_flt_tap69(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_tap_70_71                                    0x1801808C
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_reg_addr                           "0xB801808C"
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_reg                                0xB801808C
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_inst_addr                          "0x0023"
#define  set_VD_IFD_INPUT_108_input_flt_tap_70_71_reg(data)                      (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_70_71_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_tap_70_71_reg                            (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_tap_70_71_reg))
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_input_flt_tap70_shift              (16)
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_input_flt_tap71_shift              (0)
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_input_flt_tap70_mask               (0x1FFF0000)
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_input_flt_tap71_mask               (0x00001FFF)
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_input_flt_tap70(data)              (0x1FFF0000&((data)<<16))
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_input_flt_tap71(data)              (0x00001FFF&(data))
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_get_input_flt_tap70(data)          ((0x1FFF0000&(data))>>16)
#define  VD_IFD_INPUT_108_input_flt_tap_70_71_get_input_flt_tap71(data)          (0x00001FFF&(data))

#define  VD_IFD_INPUT_108_input_flt_en                                           0x18018090
#define  VD_IFD_INPUT_108_input_flt_en_reg_addr                                  "0xB8018090"
#define  VD_IFD_INPUT_108_input_flt_en_reg                                       0xB8018090
#define  VD_IFD_INPUT_108_input_flt_en_inst_addr                                 "0x0024"
#define  set_VD_IFD_INPUT_108_input_flt_en_reg(data)                             (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_en_reg)=data)
#define  get_VD_IFD_INPUT_108_input_flt_en_reg                                   (*((volatile unsigned int*)VD_IFD_INPUT_108_input_flt_en_reg))
#define  VD_IFD_INPUT_108_input_flt_en_input_flt_en_shift                        (0)
#define  VD_IFD_INPUT_108_input_flt_en_input_flt_en_mask                         (0x00000001)
#define  VD_IFD_INPUT_108_input_flt_en_input_flt_en(data)                        (0x00000001&(data))
#define  VD_IFD_INPUT_108_input_flt_en_get_input_flt_en(data)                    (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VD_IFD_INPUT_108 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap1:13;
    };
}vd_ifd_input_108_input_flt_tap_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap3:13;
    };
}vd_ifd_input_108_input_flt_tap_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap5:13;
    };
}vd_ifd_input_108_input_flt_tap_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap6:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap7:13;
    };
}vd_ifd_input_108_input_flt_tap_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap8:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap9:13;
    };
}vd_ifd_input_108_input_flt_tap_8_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap10:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap11:13;
    };
}vd_ifd_input_108_input_flt_tap_10_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap12:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap13:13;
    };
}vd_ifd_input_108_input_flt_tap_12_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap14:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap15:13;
    };
}vd_ifd_input_108_input_flt_tap_14_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap16:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap17:13;
    };
}vd_ifd_input_108_input_flt_tap_16_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap18:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap19:13;
    };
}vd_ifd_input_108_input_flt_tap_18_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap20:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap21:13;
    };
}vd_ifd_input_108_input_flt_tap_20_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap22:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap23:13;
    };
}vd_ifd_input_108_input_flt_tap_22_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap24:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap25:13;
    };
}vd_ifd_input_108_input_flt_tap_24_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap26:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap27:13;
    };
}vd_ifd_input_108_input_flt_tap_26_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap28:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap29:13;
    };
}vd_ifd_input_108_input_flt_tap_28_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap30:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap31:13;
    };
}vd_ifd_input_108_input_flt_tap_30_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap32:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap33:13;
    };
}vd_ifd_input_108_input_flt_tap_32_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap34:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap35:13;
    };
}vd_ifd_input_108_input_flt_tap_34_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap36:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap37:13;
    };
}vd_ifd_input_108_input_flt_tap_36_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap38:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap39:13;
    };
}vd_ifd_input_108_input_flt_tap_38_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap40:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap41:13;
    };
}vd_ifd_input_108_input_flt_tap_40_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap42:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap43:13;
    };
}vd_ifd_input_108_input_flt_tap_42_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap44:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap45:13;
    };
}vd_ifd_input_108_input_flt_tap_44_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap46:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap47:13;
    };
}vd_ifd_input_108_input_flt_tap_46_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap48:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap49:13;
    };
}vd_ifd_input_108_input_flt_tap_48_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap50:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap51:13;
    };
}vd_ifd_input_108_input_flt_tap_50_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap52:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap53:13;
    };
}vd_ifd_input_108_input_flt_tap_52_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap54:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap55:13;
    };
}vd_ifd_input_108_input_flt_tap_54_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap56:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap57:13;
    };
}vd_ifd_input_108_input_flt_tap_56_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap58:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap59:13;
    };
}vd_ifd_input_108_input_flt_tap_58_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap60:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap61:13;
    };
}vd_ifd_input_108_input_flt_tap_60_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap62:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap63:13;
    };
}vd_ifd_input_108_input_flt_tap_62_63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap64:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap65:13;
    };
}vd_ifd_input_108_input_flt_tap_64_65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap66:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap67:13;
    };
}vd_ifd_input_108_input_flt_tap_66_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap68:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap69:13;
    };
}vd_ifd_input_108_input_flt_tap_68_69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap70:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  input_flt_tap71:13;
    };
}vd_ifd_input_108_input_flt_tap_70_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  input_flt_en:1;
    };
}vd_ifd_input_108_input_flt_en_RBUS;

#else //apply LITTLE_ENDIAN

//======VD_IFD_INPUT_108 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap0:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap2:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap5:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap4:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap7:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap6:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_6_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap9:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap8:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_8_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap11:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap10:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_10_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap13:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap12:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_12_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap15:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap14:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_14_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap17:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap16:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_16_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap19:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap18:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_18_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap21:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap20:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_20_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap23:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap22:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_22_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap25:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap24:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_24_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap27:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap26:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_26_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap29:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap28:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_28_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap31:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap30:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_30_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap33:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap32:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_32_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap35:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap34:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_34_35_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap37:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap36:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_36_37_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap39:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap38:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_38_39_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap41:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap40:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_40_41_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap43:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap42:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_42_43_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap45:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap44:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_44_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap47:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap46:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_46_47_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap49:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap48:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_48_49_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap51:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap50:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_50_51_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap53:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap52:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_52_53_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap55:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap54:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_54_55_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap57:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap56:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_56_57_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap59:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap58:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_58_59_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap61:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap60:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_60_61_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap63:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap62:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_62_63_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap65:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap64:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_64_65_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap67:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap66:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_66_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap69:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap68:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_68_69_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_tap71:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  input_flt_tap70:13;
        RBus_UInt32  res2:3;
    };
}vd_ifd_input_108_input_flt_tap_70_71_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_flt_en:1;
        RBus_UInt32  res1:31;
    };
}vd_ifd_input_108_input_flt_en_RBUS;




#endif 


#endif 
