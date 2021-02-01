/**
* @file Mac5-DesignSpec-AE
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_AE_REG_H_
#define _RBUS_AE_REG_H_

#include "rbus_types.h"



//  AE Register Address
#define  AE_ADSP_ADE_SRC_0                                                       0x18002000
#define  AE_ADSP_ADE_SRC_0_reg_addr                                              "0xB8002000"
#define  AE_ADSP_ADE_SRC_0_reg                                                   0xB8002000
#define  AE_ADSP_ADE_SRC_0_inst_addr                                             "0x0000"
#define  set_AE_ADSP_ADE_SRC_0_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_0_reg)=data)
#define  get_AE_ADSP_ADE_SRC_0_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_0_reg))
#define  AE_ADSP_ADE_SRC_0_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_0_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_0_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_0_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_1                                                       0x18002004
#define  AE_ADSP_ADE_SRC_1_reg_addr                                              "0xB8002004"
#define  AE_ADSP_ADE_SRC_1_reg                                                   0xB8002004
#define  AE_ADSP_ADE_SRC_1_inst_addr                                             "0x0001"
#define  set_AE_ADSP_ADE_SRC_1_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_1_reg)=data)
#define  get_AE_ADSP_ADE_SRC_1_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_1_reg))
#define  AE_ADSP_ADE_SRC_1_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_1_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_1_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_1_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_2                                                       0x18002008
#define  AE_ADSP_ADE_SRC_2_reg_addr                                              "0xB8002008"
#define  AE_ADSP_ADE_SRC_2_reg                                                   0xB8002008
#define  AE_ADSP_ADE_SRC_2_inst_addr                                             "0x0002"
#define  set_AE_ADSP_ADE_SRC_2_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_2_reg)=data)
#define  get_AE_ADSP_ADE_SRC_2_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_2_reg))
#define  AE_ADSP_ADE_SRC_2_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_2_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_2_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_2_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_3                                                       0x1800200C
#define  AE_ADSP_ADE_SRC_3_reg_addr                                              "0xB800200C"
#define  AE_ADSP_ADE_SRC_3_reg                                                   0xB800200C
#define  AE_ADSP_ADE_SRC_3_inst_addr                                             "0x0003"
#define  set_AE_ADSP_ADE_SRC_3_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_3_reg)=data)
#define  get_AE_ADSP_ADE_SRC_3_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_3_reg))
#define  AE_ADSP_ADE_SRC_3_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_3_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_3_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_3_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_4                                                       0x18002010
#define  AE_ADSP_ADE_SRC_4_reg_addr                                              "0xB8002010"
#define  AE_ADSP_ADE_SRC_4_reg                                                   0xB8002010
#define  AE_ADSP_ADE_SRC_4_inst_addr                                             "0x0004"
#define  set_AE_ADSP_ADE_SRC_4_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_4_reg)=data)
#define  get_AE_ADSP_ADE_SRC_4_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_4_reg))
#define  AE_ADSP_ADE_SRC_4_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_4_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_4_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_4_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_5                                                       0x18002014
#define  AE_ADSP_ADE_SRC_5_reg_addr                                              "0xB8002014"
#define  AE_ADSP_ADE_SRC_5_reg                                                   0xB8002014
#define  AE_ADSP_ADE_SRC_5_inst_addr                                             "0x0005"
#define  set_AE_ADSP_ADE_SRC_5_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_5_reg)=data)
#define  get_AE_ADSP_ADE_SRC_5_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_5_reg))
#define  AE_ADSP_ADE_SRC_5_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_5_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_5_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_5_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_6                                                       0x18002018
#define  AE_ADSP_ADE_SRC_6_reg_addr                                              "0xB8002018"
#define  AE_ADSP_ADE_SRC_6_reg                                                   0xB8002018
#define  AE_ADSP_ADE_SRC_6_inst_addr                                             "0x0006"
#define  set_AE_ADSP_ADE_SRC_6_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_6_reg)=data)
#define  get_AE_ADSP_ADE_SRC_6_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_6_reg))
#define  AE_ADSP_ADE_SRC_6_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_6_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_6_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_6_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SRC_7                                                       0x1800201C
#define  AE_ADSP_ADE_SRC_7_reg_addr                                              "0xB800201C"
#define  AE_ADSP_ADE_SRC_7_reg                                                   0xB800201C
#define  AE_ADSP_ADE_SRC_7_inst_addr                                             "0x0007"
#define  set_AE_ADSP_ADE_SRC_7_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_SRC_7_reg)=data)
#define  get_AE_ADSP_ADE_SRC_7_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_SRC_7_reg))
#define  AE_ADSP_ADE_SRC_7_src_shift                                             (0)
#define  AE_ADSP_ADE_SRC_7_src_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_SRC_7_src(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_SRC_7_get_src(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_0                                                       0x18002020
#define  AE_ADSP_ADE_DST_0_reg_addr                                              "0xB8002020"
#define  AE_ADSP_ADE_DST_0_reg                                                   0xB8002020
#define  AE_ADSP_ADE_DST_0_inst_addr                                             "0x0008"
#define  set_AE_ADSP_ADE_DST_0_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_0_reg)=data)
#define  get_AE_ADSP_ADE_DST_0_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_0_reg))
#define  AE_ADSP_ADE_DST_0_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_0_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_0_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_0_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_1                                                       0x18002024
#define  AE_ADSP_ADE_DST_1_reg_addr                                              "0xB8002024"
#define  AE_ADSP_ADE_DST_1_reg                                                   0xB8002024
#define  AE_ADSP_ADE_DST_1_inst_addr                                             "0x0009"
#define  set_AE_ADSP_ADE_DST_1_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_1_reg)=data)
#define  get_AE_ADSP_ADE_DST_1_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_1_reg))
#define  AE_ADSP_ADE_DST_1_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_1_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_1_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_1_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_2                                                       0x18002028
#define  AE_ADSP_ADE_DST_2_reg_addr                                              "0xB8002028"
#define  AE_ADSP_ADE_DST_2_reg                                                   0xB8002028
#define  AE_ADSP_ADE_DST_2_inst_addr                                             "0x000A"
#define  set_AE_ADSP_ADE_DST_2_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_2_reg)=data)
#define  get_AE_ADSP_ADE_DST_2_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_2_reg))
#define  AE_ADSP_ADE_DST_2_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_2_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_2_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_2_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_3                                                       0x1800202C
#define  AE_ADSP_ADE_DST_3_reg_addr                                              "0xB800202C"
#define  AE_ADSP_ADE_DST_3_reg                                                   0xB800202C
#define  AE_ADSP_ADE_DST_3_inst_addr                                             "0x000B"
#define  set_AE_ADSP_ADE_DST_3_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_3_reg)=data)
#define  get_AE_ADSP_ADE_DST_3_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_3_reg))
#define  AE_ADSP_ADE_DST_3_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_3_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_3_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_3_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_4                                                       0x18002030
#define  AE_ADSP_ADE_DST_4_reg_addr                                              "0xB8002030"
#define  AE_ADSP_ADE_DST_4_reg                                                   0xB8002030
#define  AE_ADSP_ADE_DST_4_inst_addr                                             "0x000C"
#define  set_AE_ADSP_ADE_DST_4_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_4_reg)=data)
#define  get_AE_ADSP_ADE_DST_4_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_4_reg))
#define  AE_ADSP_ADE_DST_4_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_4_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_4_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_4_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_5                                                       0x18002034
#define  AE_ADSP_ADE_DST_5_reg_addr                                              "0xB8002034"
#define  AE_ADSP_ADE_DST_5_reg                                                   0xB8002034
#define  AE_ADSP_ADE_DST_5_inst_addr                                             "0x000D"
#define  set_AE_ADSP_ADE_DST_5_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_5_reg)=data)
#define  get_AE_ADSP_ADE_DST_5_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_5_reg))
#define  AE_ADSP_ADE_DST_5_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_5_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_5_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_5_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_6                                                       0x18002038
#define  AE_ADSP_ADE_DST_6_reg_addr                                              "0xB8002038"
#define  AE_ADSP_ADE_DST_6_reg                                                   0xB8002038
#define  AE_ADSP_ADE_DST_6_inst_addr                                             "0x000E"
#define  set_AE_ADSP_ADE_DST_6_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_6_reg)=data)
#define  get_AE_ADSP_ADE_DST_6_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_6_reg))
#define  AE_ADSP_ADE_DST_6_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_6_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_6_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_6_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_DST_7                                                       0x1800203C
#define  AE_ADSP_ADE_DST_7_reg_addr                                              "0xB800203C"
#define  AE_ADSP_ADE_DST_7_reg                                                   0xB800203C
#define  AE_ADSP_ADE_DST_7_inst_addr                                             "0x000F"
#define  set_AE_ADSP_ADE_DST_7_reg(data)                                         (*((volatile unsigned int*)AE_ADSP_ADE_DST_7_reg)=data)
#define  get_AE_ADSP_ADE_DST_7_reg                                               (*((volatile unsigned int*)AE_ADSP_ADE_DST_7_reg))
#define  AE_ADSP_ADE_DST_7_dst_shift                                             (0)
#define  AE_ADSP_ADE_DST_7_dst_mask                                              (0x7FFFFFFF)
#define  AE_ADSP_ADE_DST_7_dst(data)                                             (0x7FFFFFFF&(data))
#define  AE_ADSP_ADE_DST_7_get_dst(data)                                         (0x7FFFFFFF&(data))

#define  AE_ADSP_ADE_SIZE_0                                                      0x18002040
#define  AE_ADSP_ADE_SIZE_0_reg_addr                                             "0xB8002040"
#define  AE_ADSP_ADE_SIZE_0_reg                                                  0xB8002040
#define  AE_ADSP_ADE_SIZE_0_inst_addr                                            "0x0010"
#define  set_AE_ADSP_ADE_SIZE_0_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_0_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_0_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_0_reg))
#define  AE_ADSP_ADE_SIZE_0_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_0_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_0_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_0_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_0_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_0_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_0_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_0_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_0_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_0_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_0_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_0_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_1                                                      0x18002044
#define  AE_ADSP_ADE_SIZE_1_reg_addr                                             "0xB8002044"
#define  AE_ADSP_ADE_SIZE_1_reg                                                  0xB8002044
#define  AE_ADSP_ADE_SIZE_1_inst_addr                                            "0x0011"
#define  set_AE_ADSP_ADE_SIZE_1_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_1_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_1_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_1_reg))
#define  AE_ADSP_ADE_SIZE_1_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_1_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_1_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_1_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_1_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_1_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_1_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_1_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_1_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_1_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_1_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_1_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_2                                                      0x18002048
#define  AE_ADSP_ADE_SIZE_2_reg_addr                                             "0xB8002048"
#define  AE_ADSP_ADE_SIZE_2_reg                                                  0xB8002048
#define  AE_ADSP_ADE_SIZE_2_inst_addr                                            "0x0012"
#define  set_AE_ADSP_ADE_SIZE_2_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_2_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_2_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_2_reg))
#define  AE_ADSP_ADE_SIZE_2_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_2_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_2_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_2_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_2_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_2_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_2_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_2_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_2_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_2_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_2_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_2_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_3                                                      0x1800204C
#define  AE_ADSP_ADE_SIZE_3_reg_addr                                             "0xB800204C"
#define  AE_ADSP_ADE_SIZE_3_reg                                                  0xB800204C
#define  AE_ADSP_ADE_SIZE_3_inst_addr                                            "0x0013"
#define  set_AE_ADSP_ADE_SIZE_3_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_3_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_3_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_3_reg))
#define  AE_ADSP_ADE_SIZE_3_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_3_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_3_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_3_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_3_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_3_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_3_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_3_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_3_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_3_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_3_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_3_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_4                                                      0x18002050
#define  AE_ADSP_ADE_SIZE_4_reg_addr                                             "0xB8002050"
#define  AE_ADSP_ADE_SIZE_4_reg                                                  0xB8002050
#define  AE_ADSP_ADE_SIZE_4_inst_addr                                            "0x0014"
#define  set_AE_ADSP_ADE_SIZE_4_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_4_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_4_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_4_reg))
#define  AE_ADSP_ADE_SIZE_4_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_4_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_4_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_4_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_4_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_4_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_4_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_4_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_4_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_4_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_4_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_4_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_5                                                      0x18002054
#define  AE_ADSP_ADE_SIZE_5_reg_addr                                             "0xB8002054"
#define  AE_ADSP_ADE_SIZE_5_reg                                                  0xB8002054
#define  AE_ADSP_ADE_SIZE_5_inst_addr                                            "0x0015"
#define  set_AE_ADSP_ADE_SIZE_5_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_5_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_5_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_5_reg))
#define  AE_ADSP_ADE_SIZE_5_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_5_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_5_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_5_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_5_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_5_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_5_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_5_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_5_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_5_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_5_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_5_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_6                                                      0x18002058
#define  AE_ADSP_ADE_SIZE_6_reg_addr                                             "0xB8002058"
#define  AE_ADSP_ADE_SIZE_6_reg                                                  0xB8002058
#define  AE_ADSP_ADE_SIZE_6_inst_addr                                            "0x0016"
#define  set_AE_ADSP_ADE_SIZE_6_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_6_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_6_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_6_reg))
#define  AE_ADSP_ADE_SIZE_6_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_6_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_6_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_6_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_6_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_6_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_6_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_6_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_6_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_6_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_6_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_6_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_SIZE_7                                                      0x1800205C
#define  AE_ADSP_ADE_SIZE_7_reg_addr                                             "0xB800205C"
#define  AE_ADSP_ADE_SIZE_7_reg                                                  0xB800205C
#define  AE_ADSP_ADE_SIZE_7_inst_addr                                            "0x0017"
#define  set_AE_ADSP_ADE_SIZE_7_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_7_reg)=data)
#define  get_AE_ADSP_ADE_SIZE_7_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_SIZE_7_reg))
#define  AE_ADSP_ADE_SIZE_7_valid_shift                                          (15)
#define  AE_ADSP_ADE_SIZE_7_dir_shift                                            (14)
#define  AE_ADSP_ADE_SIZE_7_size_shift                                           (0)
#define  AE_ADSP_ADE_SIZE_7_valid_mask                                           (0x00008000)
#define  AE_ADSP_ADE_SIZE_7_dir_mask                                             (0x00004000)
#define  AE_ADSP_ADE_SIZE_7_size_mask                                            (0x00003FFF)
#define  AE_ADSP_ADE_SIZE_7_valid(data)                                          (0x00008000&((data)<<15))
#define  AE_ADSP_ADE_SIZE_7_dir(data)                                            (0x00004000&((data)<<14))
#define  AE_ADSP_ADE_SIZE_7_size(data)                                           (0x00003FFF&(data))
#define  AE_ADSP_ADE_SIZE_7_get_valid(data)                                      ((0x00008000&(data))>>15)
#define  AE_ADSP_ADE_SIZE_7_get_dir(data)                                        ((0x00004000&(data))>>14)
#define  AE_ADSP_ADE_SIZE_7_get_size(data)                                       (0x00003FFF&(data))

#define  AE_ADSP_ADE_STATUS                                                      0x18002060
#define  AE_ADSP_ADE_STATUS_reg_addr                                             "0xB8002060"
#define  AE_ADSP_ADE_STATUS_reg                                                  0xB8002060
#define  AE_ADSP_ADE_STATUS_inst_addr                                            "0x0018"
#define  set_AE_ADSP_ADE_STATUS_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_STATUS_reg)=data)
#define  get_AE_ADSP_ADE_STATUS_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_STATUS_reg))
#define  AE_ADSP_ADE_STATUS_done_7_shift                                         (7)
#define  AE_ADSP_ADE_STATUS_done_6_shift                                         (6)
#define  AE_ADSP_ADE_STATUS_done_5_shift                                         (5)
#define  AE_ADSP_ADE_STATUS_done_4_shift                                         (4)
#define  AE_ADSP_ADE_STATUS_done_3_shift                                         (3)
#define  AE_ADSP_ADE_STATUS_done_2_shift                                         (2)
#define  AE_ADSP_ADE_STATUS_done_1_shift                                         (1)
#define  AE_ADSP_ADE_STATUS_done_0_shift                                         (0)
#define  AE_ADSP_ADE_STATUS_done_7_mask                                          (0x00000080)
#define  AE_ADSP_ADE_STATUS_done_6_mask                                          (0x00000040)
#define  AE_ADSP_ADE_STATUS_done_5_mask                                          (0x00000020)
#define  AE_ADSP_ADE_STATUS_done_4_mask                                          (0x00000010)
#define  AE_ADSP_ADE_STATUS_done_3_mask                                          (0x00000008)
#define  AE_ADSP_ADE_STATUS_done_2_mask                                          (0x00000004)
#define  AE_ADSP_ADE_STATUS_done_1_mask                                          (0x00000002)
#define  AE_ADSP_ADE_STATUS_done_0_mask                                          (0x00000001)
#define  AE_ADSP_ADE_STATUS_done_7(data)                                         (0x00000080&((data)<<7))
#define  AE_ADSP_ADE_STATUS_done_6(data)                                         (0x00000040&((data)<<6))
#define  AE_ADSP_ADE_STATUS_done_5(data)                                         (0x00000020&((data)<<5))
#define  AE_ADSP_ADE_STATUS_done_4(data)                                         (0x00000010&((data)<<4))
#define  AE_ADSP_ADE_STATUS_done_3(data)                                         (0x00000008&((data)<<3))
#define  AE_ADSP_ADE_STATUS_done_2(data)                                         (0x00000004&((data)<<2))
#define  AE_ADSP_ADE_STATUS_done_1(data)                                         (0x00000002&((data)<<1))
#define  AE_ADSP_ADE_STATUS_done_0(data)                                         (0x00000001&(data))
#define  AE_ADSP_ADE_STATUS_get_done_7(data)                                     ((0x00000080&(data))>>7)
#define  AE_ADSP_ADE_STATUS_get_done_6(data)                                     ((0x00000040&(data))>>6)
#define  AE_ADSP_ADE_STATUS_get_done_5(data)                                     ((0x00000020&(data))>>5)
#define  AE_ADSP_ADE_STATUS_get_done_4(data)                                     ((0x00000010&(data))>>4)
#define  AE_ADSP_ADE_STATUS_get_done_3(data)                                     ((0x00000008&(data))>>3)
#define  AE_ADSP_ADE_STATUS_get_done_2(data)                                     ((0x00000004&(data))>>2)
#define  AE_ADSP_ADE_STATUS_get_done_1(data)                                     ((0x00000002&(data))>>1)
#define  AE_ADSP_ADE_STATUS_get_done_0(data)                                     (0x00000001&(data))

#define  AE_ADSP_ADE_CNTL                                                        0x18002064
#define  AE_ADSP_ADE_CNTL_reg_addr                                               "0xB8002064"
#define  AE_ADSP_ADE_CNTL_reg                                                    0xB8002064
#define  AE_ADSP_ADE_CNTL_inst_addr                                              "0x0019"
#define  set_AE_ADSP_ADE_CNTL_reg(data)                                          (*((volatile unsigned int*)AE_ADSP_ADE_CNTL_reg)=data)
#define  get_AE_ADSP_ADE_CNTL_reg                                                (*((volatile unsigned int*)AE_ADSP_ADE_CNTL_reg))
#define  AE_ADSP_ADE_CNTL_write_en1_shift                                        (17)
#define  AE_ADSP_ADE_CNTL_max_xfer_shift                                         (11)
#define  AE_ADSP_ADE_CNTL_write_en3_shift                                        (5)
#define  AE_ADSP_ADE_CNTL_dmem_req_en_shift                                      (4)
#define  AE_ADSP_ADE_CNTL_write_en4_shift                                        (3)
#define  AE_ADSP_ADE_CNTL_stop_shift                                             (2)
#define  AE_ADSP_ADE_CNTL_write_en5_shift                                        (1)
#define  AE_ADSP_ADE_CNTL_go_shift                                               (0)
#define  AE_ADSP_ADE_CNTL_write_en1_mask                                         (0x00020000)
#define  AE_ADSP_ADE_CNTL_max_xfer_mask                                          (0x0001F800)
#define  AE_ADSP_ADE_CNTL_write_en3_mask                                         (0x00000020)
#define  AE_ADSP_ADE_CNTL_dmem_req_en_mask                                       (0x00000010)
#define  AE_ADSP_ADE_CNTL_write_en4_mask                                         (0x00000008)
#define  AE_ADSP_ADE_CNTL_stop_mask                                              (0x00000004)
#define  AE_ADSP_ADE_CNTL_write_en5_mask                                         (0x00000002)
#define  AE_ADSP_ADE_CNTL_go_mask                                                (0x00000001)
#define  AE_ADSP_ADE_CNTL_write_en1(data)                                        (0x00020000&((data)<<17))
#define  AE_ADSP_ADE_CNTL_max_xfer(data)                                         (0x0001F800&((data)<<11))
#define  AE_ADSP_ADE_CNTL_write_en3(data)                                        (0x00000020&((data)<<5))
#define  AE_ADSP_ADE_CNTL_dmem_req_en(data)                                      (0x00000010&((data)<<4))
#define  AE_ADSP_ADE_CNTL_write_en4(data)                                        (0x00000008&((data)<<3))
#define  AE_ADSP_ADE_CNTL_stop(data)                                             (0x00000004&((data)<<2))
#define  AE_ADSP_ADE_CNTL_write_en5(data)                                        (0x00000002&((data)<<1))
#define  AE_ADSP_ADE_CNTL_go(data)                                               (0x00000001&(data))
#define  AE_ADSP_ADE_CNTL_get_write_en1(data)                                    ((0x00020000&(data))>>17)
#define  AE_ADSP_ADE_CNTL_get_max_xfer(data)                                     ((0x0001F800&(data))>>11)
#define  AE_ADSP_ADE_CNTL_get_write_en3(data)                                    ((0x00000020&(data))>>5)
#define  AE_ADSP_ADE_CNTL_get_dmem_req_en(data)                                  ((0x00000010&(data))>>4)
#define  AE_ADSP_ADE_CNTL_get_write_en4(data)                                    ((0x00000008&(data))>>3)
#define  AE_ADSP_ADE_CNTL_get_stop(data)                                         ((0x00000004&(data))>>2)
#define  AE_ADSP_ADE_CNTL_get_write_en5(data)                                    ((0x00000002&(data))>>1)
#define  AE_ADSP_ADE_CNTL_get_go(data)                                           (0x00000001&(data))

#define  AE_ADSP_ADE_INT                                                         0x18002068
#define  AE_ADSP_ADE_INT_reg_addr                                                "0xB8002068"
#define  AE_ADSP_ADE_INT_reg                                                     0xB8002068
#define  AE_ADSP_ADE_INT_inst_addr                                               "0x001A"
#define  set_AE_ADSP_ADE_INT_reg(data)                                           (*((volatile unsigned int*)AE_ADSP_ADE_INT_reg)=data)
#define  get_AE_ADSP_ADE_INT_reg                                                 (*((volatile unsigned int*)AE_ADSP_ADE_INT_reg))
#define  AE_ADSP_ADE_INT_int_done_shift                                          (0)
#define  AE_ADSP_ADE_INT_int_done_mask                                           (0x00000001)
#define  AE_ADSP_ADE_INT_int_done(data)                                          (0x00000001&(data))
#define  AE_ADSP_ADE_INT_get_int_done(data)                                      (0x00000001&(data))

#define  AE_ADSP_ADE_INT_EN                                                      0x1800206C
#define  AE_ADSP_ADE_INT_EN_reg_addr                                             "0xB800206C"
#define  AE_ADSP_ADE_INT_EN_reg                                                  0xB800206C
#define  AE_ADSP_ADE_INT_EN_inst_addr                                            "0x001B"
#define  set_AE_ADSP_ADE_INT_EN_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_ADE_INT_EN_reg)=data)
#define  get_AE_ADSP_ADE_INT_EN_reg                                              (*((volatile unsigned int*)AE_ADSP_ADE_INT_EN_reg))
#define  AE_ADSP_ADE_INT_EN_int_done_en_shift                                    (0)
#define  AE_ADSP_ADE_INT_EN_int_done_en_mask                                     (0x00000001)
#define  AE_ADSP_ADE_INT_EN_int_done_en(data)                                    (0x00000001&(data))
#define  AE_ADSP_ADE_INT_EN_get_int_done_en(data)                                (0x00000001&(data))

#define  AE_ADSP_ADE_TIMER_MSB_0                                                 0x18002300
#define  AE_ADSP_ADE_TIMER_MSB_0_reg_addr                                        "0xB8002300"
#define  AE_ADSP_ADE_TIMER_MSB_0_reg                                             0xB8002300
#define  AE_ADSP_ADE_TIMER_MSB_0_inst_addr                                       "0x001C"
#define  set_AE_ADSP_ADE_TIMER_MSB_0_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_0_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_0_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_0_reg))
#define  AE_ADSP_ADE_TIMER_MSB_0_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_0_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_0_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_0_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_1                                                 0x18002304
#define  AE_ADSP_ADE_TIMER_MSB_1_reg_addr                                        "0xB8002304"
#define  AE_ADSP_ADE_TIMER_MSB_1_reg                                             0xB8002304
#define  AE_ADSP_ADE_TIMER_MSB_1_inst_addr                                       "0x001D"
#define  set_AE_ADSP_ADE_TIMER_MSB_1_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_1_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_1_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_1_reg))
#define  AE_ADSP_ADE_TIMER_MSB_1_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_1_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_1_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_1_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_2                                                 0x18002308
#define  AE_ADSP_ADE_TIMER_MSB_2_reg_addr                                        "0xB8002308"
#define  AE_ADSP_ADE_TIMER_MSB_2_reg                                             0xB8002308
#define  AE_ADSP_ADE_TIMER_MSB_2_inst_addr                                       "0x001E"
#define  set_AE_ADSP_ADE_TIMER_MSB_2_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_2_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_2_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_2_reg))
#define  AE_ADSP_ADE_TIMER_MSB_2_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_2_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_2_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_2_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_3                                                 0x1800230C
#define  AE_ADSP_ADE_TIMER_MSB_3_reg_addr                                        "0xB800230C"
#define  AE_ADSP_ADE_TIMER_MSB_3_reg                                             0xB800230C
#define  AE_ADSP_ADE_TIMER_MSB_3_inst_addr                                       "0x001F"
#define  set_AE_ADSP_ADE_TIMER_MSB_3_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_3_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_3_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_3_reg))
#define  AE_ADSP_ADE_TIMER_MSB_3_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_3_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_3_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_3_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_4                                                 0x18002310
#define  AE_ADSP_ADE_TIMER_MSB_4_reg_addr                                        "0xB8002310"
#define  AE_ADSP_ADE_TIMER_MSB_4_reg                                             0xB8002310
#define  AE_ADSP_ADE_TIMER_MSB_4_inst_addr                                       "0x0020"
#define  set_AE_ADSP_ADE_TIMER_MSB_4_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_4_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_4_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_4_reg))
#define  AE_ADSP_ADE_TIMER_MSB_4_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_4_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_4_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_4_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_5                                                 0x18002314
#define  AE_ADSP_ADE_TIMER_MSB_5_reg_addr                                        "0xB8002314"
#define  AE_ADSP_ADE_TIMER_MSB_5_reg                                             0xB8002314
#define  AE_ADSP_ADE_TIMER_MSB_5_inst_addr                                       "0x0021"
#define  set_AE_ADSP_ADE_TIMER_MSB_5_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_5_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_5_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_5_reg))
#define  AE_ADSP_ADE_TIMER_MSB_5_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_5_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_5_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_5_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_6                                                 0x18002318
#define  AE_ADSP_ADE_TIMER_MSB_6_reg_addr                                        "0xB8002318"
#define  AE_ADSP_ADE_TIMER_MSB_6_reg                                             0xB8002318
#define  AE_ADSP_ADE_TIMER_MSB_6_inst_addr                                       "0x0022"
#define  set_AE_ADSP_ADE_TIMER_MSB_6_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_6_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_6_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_6_reg))
#define  AE_ADSP_ADE_TIMER_MSB_6_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_6_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_6_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_6_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_MSB_7                                                 0x1800231C
#define  AE_ADSP_ADE_TIMER_MSB_7_reg_addr                                        "0xB800231C"
#define  AE_ADSP_ADE_TIMER_MSB_7_reg                                             0xB800231C
#define  AE_ADSP_ADE_TIMER_MSB_7_inst_addr                                       "0x0023"
#define  set_AE_ADSP_ADE_TIMER_MSB_7_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_7_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_MSB_7_reg                                         (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_MSB_7_reg))
#define  AE_ADSP_ADE_TIMER_MSB_7_cnt_shift                                       (0)
#define  AE_ADSP_ADE_TIMER_MSB_7_cnt_mask                                        (0x000000FF)
#define  AE_ADSP_ADE_TIMER_MSB_7_cnt(data)                                       (0x000000FF&(data))
#define  AE_ADSP_ADE_TIMER_MSB_7_get_cnt(data)                                   (0x000000FF&(data))

#define  AE_ADSP_ADE_TIMER_0                                                     0x18002320
#define  AE_ADSP_ADE_TIMER_0_reg_addr                                            "0xB8002320"
#define  AE_ADSP_ADE_TIMER_0_reg                                                 0xB8002320
#define  AE_ADSP_ADE_TIMER_0_inst_addr                                           "0x0024"
#define  set_AE_ADSP_ADE_TIMER_0_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_0_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_0_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_0_reg))
#define  AE_ADSP_ADE_TIMER_0_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_0_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_0_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_0_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_1                                                     0x18002324
#define  AE_ADSP_ADE_TIMER_1_reg_addr                                            "0xB8002324"
#define  AE_ADSP_ADE_TIMER_1_reg                                                 0xB8002324
#define  AE_ADSP_ADE_TIMER_1_inst_addr                                           "0x0025"
#define  set_AE_ADSP_ADE_TIMER_1_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_1_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_1_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_1_reg))
#define  AE_ADSP_ADE_TIMER_1_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_1_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_1_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_1_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_2                                                     0x18002328
#define  AE_ADSP_ADE_TIMER_2_reg_addr                                            "0xB8002328"
#define  AE_ADSP_ADE_TIMER_2_reg                                                 0xB8002328
#define  AE_ADSP_ADE_TIMER_2_inst_addr                                           "0x0026"
#define  set_AE_ADSP_ADE_TIMER_2_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_2_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_2_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_2_reg))
#define  AE_ADSP_ADE_TIMER_2_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_2_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_2_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_2_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_3                                                     0x1800232C
#define  AE_ADSP_ADE_TIMER_3_reg_addr                                            "0xB800232C"
#define  AE_ADSP_ADE_TIMER_3_reg                                                 0xB800232C
#define  AE_ADSP_ADE_TIMER_3_inst_addr                                           "0x0027"
#define  set_AE_ADSP_ADE_TIMER_3_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_3_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_3_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_3_reg))
#define  AE_ADSP_ADE_TIMER_3_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_3_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_3_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_3_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_4                                                     0x18002330
#define  AE_ADSP_ADE_TIMER_4_reg_addr                                            "0xB8002330"
#define  AE_ADSP_ADE_TIMER_4_reg                                                 0xB8002330
#define  AE_ADSP_ADE_TIMER_4_inst_addr                                           "0x0028"
#define  set_AE_ADSP_ADE_TIMER_4_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_4_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_4_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_4_reg))
#define  AE_ADSP_ADE_TIMER_4_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_4_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_4_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_4_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_5                                                     0x18002334
#define  AE_ADSP_ADE_TIMER_5_reg_addr                                            "0xB8002334"
#define  AE_ADSP_ADE_TIMER_5_reg                                                 0xB8002334
#define  AE_ADSP_ADE_TIMER_5_inst_addr                                           "0x0029"
#define  set_AE_ADSP_ADE_TIMER_5_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_5_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_5_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_5_reg))
#define  AE_ADSP_ADE_TIMER_5_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_5_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_5_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_5_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_6                                                     0x18002338
#define  AE_ADSP_ADE_TIMER_6_reg_addr                                            "0xB8002338"
#define  AE_ADSP_ADE_TIMER_6_reg                                                 0xB8002338
#define  AE_ADSP_ADE_TIMER_6_inst_addr                                           "0x002A"
#define  set_AE_ADSP_ADE_TIMER_6_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_6_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_6_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_6_reg))
#define  AE_ADSP_ADE_TIMER_6_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_6_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_6_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_6_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_ADE_TIMER_7                                                     0x1800233C
#define  AE_ADSP_ADE_TIMER_7_reg_addr                                            "0xB800233C"
#define  AE_ADSP_ADE_TIMER_7_reg                                                 0xB800233C
#define  AE_ADSP_ADE_TIMER_7_inst_addr                                           "0x002B"
#define  set_AE_ADSP_ADE_TIMER_7_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_7_reg)=data)
#define  get_AE_ADSP_ADE_TIMER_7_reg                                             (*((volatile unsigned int*)AE_ADSP_ADE_TIMER_7_reg))
#define  AE_ADSP_ADE_TIMER_7_cnt_shift                                           (0)
#define  AE_ADSP_ADE_TIMER_7_cnt_mask                                            (0xFFFFFFFF)
#define  AE_ADSP_ADE_TIMER_7_cnt(data)                                           (0xFFFFFFFF&(data))
#define  AE_ADSP_ADE_TIMER_7_get_cnt(data)                                       (0xFFFFFFFF&(data))

#define  AE_ADSP_AEE_THLD                                                        0x18002078
#define  AE_ADSP_AEE_THLD_reg_addr                                               "0xB8002078"
#define  AE_ADSP_AEE_THLD_reg                                                    0xB8002078
#define  AE_ADSP_AEE_THLD_inst_addr                                              "0x002C"
#define  set_AE_ADSP_AEE_THLD_reg(data)                                          (*((volatile unsigned int*)AE_ADSP_AEE_THLD_reg)=data)
#define  get_AE_ADSP_AEE_THLD_reg                                                (*((volatile unsigned int*)AE_ADSP_AEE_THLD_reg))
#define  AE_ADSP_AEE_THLD_max_xfer_shift                                         (13)
#define  AE_ADSP_AEE_THLD_threshold_shift                                        (3)
#define  AE_ADSP_AEE_THLD_max_xfer_mask                                          (0x0007E000)
#define  AE_ADSP_AEE_THLD_threshold_mask                                         (0x000001F8)
#define  AE_ADSP_AEE_THLD_max_xfer(data)                                         (0x0007E000&((data)<<13))
#define  AE_ADSP_AEE_THLD_threshold(data)                                        (0x000001F8&((data)<<3))
#define  AE_ADSP_AEE_THLD_get_max_xfer(data)                                     ((0x0007E000&(data))>>13)
#define  AE_ADSP_AEE_THLD_get_threshold(data)                                    ((0x000001F8&(data))>>3)

#define  AE_ADSP_AEE_VBIT_CNT                                                    0x1800207C
#define  AE_ADSP_AEE_VBIT_CNT_reg_addr                                           "0xB800207C"
#define  AE_ADSP_AEE_VBIT_CNT_reg                                                0xB800207C
#define  AE_ADSP_AEE_VBIT_CNT_inst_addr                                          "0x002D"
#define  set_AE_ADSP_AEE_VBIT_CNT_reg(data)                                      (*((volatile unsigned int*)AE_ADSP_AEE_VBIT_CNT_reg)=data)
#define  get_AE_ADSP_AEE_VBIT_CNT_reg                                            (*((volatile unsigned int*)AE_ADSP_AEE_VBIT_CNT_reg))
#define  AE_ADSP_AEE_VBIT_CNT_bit_cnt_shift                                      (0)
#define  AE_ADSP_AEE_VBIT_CNT_bit_cnt_mask                                       (0x00003FFF)
#define  AE_ADSP_AEE_VBIT_CNT_bit_cnt(data)                                      (0x00003FFF&(data))
#define  AE_ADSP_AEE_VBIT_CNT_get_bit_cnt(data)                                  (0x00003FFF&(data))

#define  AE_ADSP_AEE_USED_CNT                                                    0x18002080
#define  AE_ADSP_AEE_USED_CNT_reg_addr                                           "0xB8002080"
#define  AE_ADSP_AEE_USED_CNT_reg                                                0xB8002080
#define  AE_ADSP_AEE_USED_CNT_inst_addr                                          "0x002E"
#define  set_AE_ADSP_AEE_USED_CNT_reg(data)                                      (*((volatile unsigned int*)AE_ADSP_AEE_USED_CNT_reg)=data)
#define  get_AE_ADSP_AEE_USED_CNT_reg                                            (*((volatile unsigned int*)AE_ADSP_AEE_USED_CNT_reg))
#define  AE_ADSP_AEE_USED_CNT_used_cnt_shift                                     (0)
#define  AE_ADSP_AEE_USED_CNT_used_cnt_mask                                      (0xFFFFFFFF)
#define  AE_ADSP_AEE_USED_CNT_used_cnt(data)                                     (0xFFFFFFFF&(data))
#define  AE_ADSP_AEE_USED_CNT_get_used_cnt(data)                                 (0xFFFFFFFF&(data))

#define  AE_ADSP_AEE_CTRL                                                        0x18002084
#define  AE_ADSP_AEE_CTRL_reg_addr                                               "0xB8002084"
#define  AE_ADSP_AEE_CTRL_reg                                                    0xB8002084
#define  AE_ADSP_AEE_CTRL_inst_addr                                              "0x002F"
#define  set_AE_ADSP_AEE_CTRL_reg(data)                                          (*((volatile unsigned int*)AE_ADSP_AEE_CTRL_reg)=data)
#define  get_AE_ADSP_AEE_CTRL_reg                                                (*((volatile unsigned int*)AE_ADSP_AEE_CTRL_reg))
#define  AE_ADSP_AEE_CTRL_write_en1_shift                                        (4)
#define  AE_ADSP_AEE_CTRL_stop_shift                                             (3)
#define  AE_ADSP_AEE_CTRL_write_en2_shift                                        (2)
#define  AE_ADSP_AEE_CTRL_dir_shift                                              (1)
#define  AE_ADSP_AEE_CTRL_go_shift                                               (0)
#define  AE_ADSP_AEE_CTRL_write_en1_mask                                         (0x00000010)
#define  AE_ADSP_AEE_CTRL_stop_mask                                              (0x00000008)
#define  AE_ADSP_AEE_CTRL_write_en2_mask                                         (0x00000004)
#define  AE_ADSP_AEE_CTRL_dir_mask                                               (0x00000002)
#define  AE_ADSP_AEE_CTRL_go_mask                                                (0x00000001)
#define  AE_ADSP_AEE_CTRL_write_en1(data)                                        (0x00000010&((data)<<4))
#define  AE_ADSP_AEE_CTRL_stop(data)                                             (0x00000008&((data)<<3))
#define  AE_ADSP_AEE_CTRL_write_en2(data)                                        (0x00000004&((data)<<2))
#define  AE_ADSP_AEE_CTRL_dir(data)                                              (0x00000002&((data)<<1))
#define  AE_ADSP_AEE_CTRL_go(data)                                               (0x00000001&(data))
#define  AE_ADSP_AEE_CTRL_get_write_en1(data)                                    ((0x00000010&(data))>>4)
#define  AE_ADSP_AEE_CTRL_get_stop(data)                                         ((0x00000008&(data))>>3)
#define  AE_ADSP_AEE_CTRL_get_write_en2(data)                                    ((0x00000004&(data))>>2)
#define  AE_ADSP_AEE_CTRL_get_dir(data)                                          ((0x00000002&(data))>>1)
#define  AE_ADSP_AEE_CTRL_get_go(data)                                           (0x00000001&(data))

#define  AE_ADSP_AEE_INT                                                         0x18002088
#define  AE_ADSP_AEE_INT_reg_addr                                                "0xB8002088"
#define  AE_ADSP_AEE_INT_reg                                                     0xB8002088
#define  AE_ADSP_AEE_INT_inst_addr                                               "0x0030"
#define  set_AE_ADSP_AEE_INT_reg(data)                                           (*((volatile unsigned int*)AE_ADSP_AEE_INT_reg)=data)
#define  get_AE_ADSP_AEE_INT_reg                                                 (*((volatile unsigned int*)AE_ADSP_AEE_INT_reg))
#define  AE_ADSP_AEE_INT_int4_shift                                              (4)
#define  AE_ADSP_AEE_INT_int3_shift                                              (3)
#define  AE_ADSP_AEE_INT_int2_shift                                              (2)
#define  AE_ADSP_AEE_INT_int1_shift                                              (1)
#define  AE_ADSP_AEE_INT_write_data_shift                                        (0)
#define  AE_ADSP_AEE_INT_int4_mask                                               (0x00000010)
#define  AE_ADSP_AEE_INT_int3_mask                                               (0x00000008)
#define  AE_ADSP_AEE_INT_int2_mask                                               (0x00000004)
#define  AE_ADSP_AEE_INT_int1_mask                                               (0x00000002)
#define  AE_ADSP_AEE_INT_write_data_mask                                         (0x00000001)
#define  AE_ADSP_AEE_INT_int4(data)                                              (0x00000010&((data)<<4))
#define  AE_ADSP_AEE_INT_int3(data)                                              (0x00000008&((data)<<3))
#define  AE_ADSP_AEE_INT_int2(data)                                              (0x00000004&((data)<<2))
#define  AE_ADSP_AEE_INT_int1(data)                                              (0x00000002&((data)<<1))
#define  AE_ADSP_AEE_INT_write_data(data)                                        (0x00000001&(data))
#define  AE_ADSP_AEE_INT_get_int4(data)                                          ((0x00000010&(data))>>4)
#define  AE_ADSP_AEE_INT_get_int3(data)                                          ((0x00000008&(data))>>3)
#define  AE_ADSP_AEE_INT_get_int2(data)                                          ((0x00000004&(data))>>2)
#define  AE_ADSP_AEE_INT_get_int1(data)                                          ((0x00000002&(data))>>1)
#define  AE_ADSP_AEE_INT_get_write_data(data)                                    (0x00000001&(data))

#define  AE_ADSP_AEE_INT_EN                                                      0x1800208C
#define  AE_ADSP_AEE_INT_EN_reg_addr                                             "0xB800208C"
#define  AE_ADSP_AEE_INT_EN_reg                                                  0xB800208C
#define  AE_ADSP_AEE_INT_EN_inst_addr                                            "0x0031"
#define  set_AE_ADSP_AEE_INT_EN_reg(data)                                        (*((volatile unsigned int*)AE_ADSP_AEE_INT_EN_reg)=data)
#define  get_AE_ADSP_AEE_INT_EN_reg                                              (*((volatile unsigned int*)AE_ADSP_AEE_INT_EN_reg))
#define  AE_ADSP_AEE_INT_EN_int4_en_shift                                        (4)
#define  AE_ADSP_AEE_INT_EN_int3_en_shift                                        (3)
#define  AE_ADSP_AEE_INT_EN_int2_en_shift                                        (2)
#define  AE_ADSP_AEE_INT_EN_int1_en_shift                                        (1)
#define  AE_ADSP_AEE_INT_EN_write_data_shift                                     (0)
#define  AE_ADSP_AEE_INT_EN_int4_en_mask                                         (0x00000010)
#define  AE_ADSP_AEE_INT_EN_int3_en_mask                                         (0x00000008)
#define  AE_ADSP_AEE_INT_EN_int2_en_mask                                         (0x00000004)
#define  AE_ADSP_AEE_INT_EN_int1_en_mask                                         (0x00000002)
#define  AE_ADSP_AEE_INT_EN_write_data_mask                                      (0x00000001)
#define  AE_ADSP_AEE_INT_EN_int4_en(data)                                        (0x00000010&((data)<<4))
#define  AE_ADSP_AEE_INT_EN_int3_en(data)                                        (0x00000008&((data)<<3))
#define  AE_ADSP_AEE_INT_EN_int2_en(data)                                        (0x00000004&((data)<<2))
#define  AE_ADSP_AEE_INT_EN_int1_en(data)                                        (0x00000002&((data)<<1))
#define  AE_ADSP_AEE_INT_EN_write_data(data)                                     (0x00000001&(data))
#define  AE_ADSP_AEE_INT_EN_get_int4_en(data)                                    ((0x00000010&(data))>>4)
#define  AE_ADSP_AEE_INT_EN_get_int3_en(data)                                    ((0x00000008&(data))>>3)
#define  AE_ADSP_AEE_INT_EN_get_int2_en(data)                                    ((0x00000004&(data))>>2)
#define  AE_ADSP_AEE_INT_EN_get_int1_en(data)                                    ((0x00000002&(data))>>1)
#define  AE_ADSP_AEE_INT_EN_get_write_data(data)                                 (0x00000001&(data))

#define  AE_ADSP_AEE_RING_LIMIT                                                  0x18002094
#define  AE_ADSP_AEE_RING_LIMIT_reg_addr                                         "0xB8002094"
#define  AE_ADSP_AEE_RING_LIMIT_reg                                              0xB8002094
#define  AE_ADSP_AEE_RING_LIMIT_inst_addr                                        "0x0032"
#define  set_AE_ADSP_AEE_RING_LIMIT_reg(data)                                    (*((volatile unsigned int*)AE_ADSP_AEE_RING_LIMIT_reg)=data)
#define  get_AE_ADSP_AEE_RING_LIMIT_reg                                          (*((volatile unsigned int*)AE_ADSP_AEE_RING_LIMIT_reg))
#define  AE_ADSP_AEE_RING_LIMIT_ring_limit_shift                                 (3)
#define  AE_ADSP_AEE_RING_LIMIT_ring_limit_mask                                  (0x7FFFFFF8)
#define  AE_ADSP_AEE_RING_LIMIT_ring_limit(data)                                 (0x7FFFFFF8&((data)<<3))
#define  AE_ADSP_AEE_RING_LIMIT_get_ring_limit(data)                             ((0x7FFFFFF8&(data))>>3)

#define  AE_ADSP_AEE_RING_BASE                                                   0x18002098
#define  AE_ADSP_AEE_RING_BASE_reg_addr                                          "0xB8002098"
#define  AE_ADSP_AEE_RING_BASE_reg                                               0xB8002098
#define  AE_ADSP_AEE_RING_BASE_inst_addr                                         "0x0033"
#define  set_AE_ADSP_AEE_RING_BASE_reg(data)                                     (*((volatile unsigned int*)AE_ADSP_AEE_RING_BASE_reg)=data)
#define  get_AE_ADSP_AEE_RING_BASE_reg                                           (*((volatile unsigned int*)AE_ADSP_AEE_RING_BASE_reg))
#define  AE_ADSP_AEE_RING_BASE_ring_base_shift                                   (3)
#define  AE_ADSP_AEE_RING_BASE_ring_base_mask                                    (0x7FFFFFF8)
#define  AE_ADSP_AEE_RING_BASE_ring_base(data)                                   (0x7FFFFFF8&((data)<<3))
#define  AE_ADSP_AEE_RING_BASE_get_ring_base(data)                               ((0x7FFFFFF8&(data))>>3)

#define  AE_ADSP_AEE_RING_RP                                                     0x1800209C
#define  AE_ADSP_AEE_RING_RP_reg_addr                                            "0xB800209C"
#define  AE_ADSP_AEE_RING_RP_reg                                                 0xB800209C
#define  AE_ADSP_AEE_RING_RP_inst_addr                                           "0x0034"
#define  set_AE_ADSP_AEE_RING_RP_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_AEE_RING_RP_reg)=data)
#define  get_AE_ADSP_AEE_RING_RP_reg                                             (*((volatile unsigned int*)AE_ADSP_AEE_RING_RP_reg))
#define  AE_ADSP_AEE_RING_RP_ring_rp_shift                                       (0)
#define  AE_ADSP_AEE_RING_RP_ring_rp_mask                                        (0x7FFFFFFF)
#define  AE_ADSP_AEE_RING_RP_ring_rp(data)                                       (0x7FFFFFFF&(data))
#define  AE_ADSP_AEE_RING_RP_get_ring_rp(data)                                   (0x7FFFFFFF&(data))

#define  AE_ADSP_AEE_RING_WP                                                     0x180020A0
#define  AE_ADSP_AEE_RING_WP_reg_addr                                            "0xB80020A0"
#define  AE_ADSP_AEE_RING_WP_reg                                                 0xB80020A0
#define  AE_ADSP_AEE_RING_WP_inst_addr                                           "0x0035"
#define  set_AE_ADSP_AEE_RING_WP_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_AEE_RING_WP_reg)=data)
#define  get_AE_ADSP_AEE_RING_WP_reg                                             (*((volatile unsigned int*)AE_ADSP_AEE_RING_WP_reg))
#define  AE_ADSP_AEE_RING_WP_ring_wp_shift                                       (0)
#define  AE_ADSP_AEE_RING_WP_ring_wp_mask                                        (0x7FFFFFFF)
#define  AE_ADSP_AEE_RING_WP_ring_wp(data)                                       (0x7FFFFFFF&(data))
#define  AE_ADSP_AEE_RING_WP_get_ring_wp(data)                                   (0x7FFFFFFF&(data))

#define  AE_ADSP_AEE_RING_CP                                                     0x180020A4
#define  AE_ADSP_AEE_RING_CP_reg_addr                                            "0xB80020A4"
#define  AE_ADSP_AEE_RING_CP_reg                                                 0xB80020A4
#define  AE_ADSP_AEE_RING_CP_inst_addr                                           "0x0036"
#define  set_AE_ADSP_AEE_RING_CP_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_AEE_RING_CP_reg)=data)
#define  get_AE_ADSP_AEE_RING_CP_reg                                             (*((volatile unsigned int*)AE_ADSP_AEE_RING_CP_reg))
#define  AE_ADSP_AEE_RING_CP_ring_cp_shift                                       (0)
#define  AE_ADSP_AEE_RING_CP_ring_cp_mask                                        (0x7FFFFFFF)
#define  AE_ADSP_AEE_RING_CP_ring_cp(data)                                       (0x7FFFFFFF&(data))
#define  AE_ADSP_AEE_RING_CP_get_ring_cp(data)                                   (0x7FFFFFFF&(data))

#define  AE_ADSP_AEE_SEARCH_LIMIT                                                0x180020C8
#define  AE_ADSP_AEE_SEARCH_LIMIT_reg_addr                                       "0xB80020C8"
#define  AE_ADSP_AEE_SEARCH_LIMIT_reg                                            0xB80020C8
#define  AE_ADSP_AEE_SEARCH_LIMIT_inst_addr                                      "0x0037"
#define  set_AE_ADSP_AEE_SEARCH_LIMIT_reg(data)                                  (*((volatile unsigned int*)AE_ADSP_AEE_SEARCH_LIMIT_reg)=data)
#define  get_AE_ADSP_AEE_SEARCH_LIMIT_reg                                        (*((volatile unsigned int*)AE_ADSP_AEE_SEARCH_LIMIT_reg))
#define  AE_ADSP_AEE_SEARCH_LIMIT_limit_shift                                    (0)
#define  AE_ADSP_AEE_SEARCH_LIMIT_limit_mask                                     (0x0000FFFF)
#define  AE_ADSP_AEE_SEARCH_LIMIT_limit(data)                                    (0x0000FFFF&(data))
#define  AE_ADSP_AEE_SEARCH_LIMIT_get_limit(data)                                (0x0000FFFF&(data))

#define  AE_ADSP_AEE_CRC_INIT                                                    0x180020AC
#define  AE_ADSP_AEE_CRC_INIT_reg_addr                                           "0xB80020AC"
#define  AE_ADSP_AEE_CRC_INIT_reg                                                0xB80020AC
#define  AE_ADSP_AEE_CRC_INIT_inst_addr                                          "0x0038"
#define  set_AE_ADSP_AEE_CRC_INIT_reg(data)                                      (*((volatile unsigned int*)AE_ADSP_AEE_CRC_INIT_reg)=data)
#define  get_AE_ADSP_AEE_CRC_INIT_reg                                            (*((volatile unsigned int*)AE_ADSP_AEE_CRC_INIT_reg))
#define  AE_ADSP_AEE_CRC_INIT_crc_init_shift                                     (0)
#define  AE_ADSP_AEE_CRC_INIT_crc_init_mask                                      (0x0000FFFF)
#define  AE_ADSP_AEE_CRC_INIT_crc_init(data)                                     (0x0000FFFF&(data))
#define  AE_ADSP_AEE_CRC_INIT_get_crc_init(data)                                 (0x0000FFFF&(data))

#define  AE_ADSP_AEE_CRC_CNTL                                                    0x180020B0
#define  AE_ADSP_AEE_CRC_CNTL_reg_addr                                           "0xB80020B0"
#define  AE_ADSP_AEE_CRC_CNTL_reg                                                0xB80020B0
#define  AE_ADSP_AEE_CRC_CNTL_inst_addr                                          "0x0039"
#define  set_AE_ADSP_AEE_CRC_CNTL_reg(data)                                      (*((volatile unsigned int*)AE_ADSP_AEE_CRC_CNTL_reg)=data)
#define  get_AE_ADSP_AEE_CRC_CNTL_reg                                            (*((volatile unsigned int*)AE_ADSP_AEE_CRC_CNTL_reg))
#define  AE_ADSP_AEE_CRC_CNTL_write_en4_shift                                    (7)
#define  AE_ADSP_AEE_CRC_CNTL_crc_mode_shift                                     (6)
#define  AE_ADSP_AEE_CRC_CNTL_write_en1_shift                                    (5)
#define  AE_ADSP_AEE_CRC_CNTL_crc_reset_shift                                    (4)
#define  AE_ADSP_AEE_CRC_CNTL_write_en2_shift                                    (3)
#define  AE_ADSP_AEE_CRC_CNTL_crc_cont_shift                                     (2)
#define  AE_ADSP_AEE_CRC_CNTL_write_en3_shift                                    (1)
#define  AE_ADSP_AEE_CRC_CNTL_crc_on_shift                                       (0)
#define  AE_ADSP_AEE_CRC_CNTL_write_en4_mask                                     (0x00000080)
#define  AE_ADSP_AEE_CRC_CNTL_crc_mode_mask                                      (0x00000040)
#define  AE_ADSP_AEE_CRC_CNTL_write_en1_mask                                     (0x00000020)
#define  AE_ADSP_AEE_CRC_CNTL_crc_reset_mask                                     (0x00000010)
#define  AE_ADSP_AEE_CRC_CNTL_write_en2_mask                                     (0x00000008)
#define  AE_ADSP_AEE_CRC_CNTL_crc_cont_mask                                      (0x00000004)
#define  AE_ADSP_AEE_CRC_CNTL_write_en3_mask                                     (0x00000002)
#define  AE_ADSP_AEE_CRC_CNTL_crc_on_mask                                        (0x00000001)
#define  AE_ADSP_AEE_CRC_CNTL_write_en4(data)                                    (0x00000080&((data)<<7))
#define  AE_ADSP_AEE_CRC_CNTL_crc_mode(data)                                     (0x00000040&((data)<<6))
#define  AE_ADSP_AEE_CRC_CNTL_write_en1(data)                                    (0x00000020&((data)<<5))
#define  AE_ADSP_AEE_CRC_CNTL_crc_reset(data)                                    (0x00000010&((data)<<4))
#define  AE_ADSP_AEE_CRC_CNTL_write_en2(data)                                    (0x00000008&((data)<<3))
#define  AE_ADSP_AEE_CRC_CNTL_crc_cont(data)                                     (0x00000004&((data)<<2))
#define  AE_ADSP_AEE_CRC_CNTL_write_en3(data)                                    (0x00000002&((data)<<1))
#define  AE_ADSP_AEE_CRC_CNTL_crc_on(data)                                       (0x00000001&(data))
#define  AE_ADSP_AEE_CRC_CNTL_get_write_en4(data)                                ((0x00000080&(data))>>7)
#define  AE_ADSP_AEE_CRC_CNTL_get_crc_mode(data)                                 ((0x00000040&(data))>>6)
#define  AE_ADSP_AEE_CRC_CNTL_get_write_en1(data)                                ((0x00000020&(data))>>5)
#define  AE_ADSP_AEE_CRC_CNTL_get_crc_reset(data)                                ((0x00000010&(data))>>4)
#define  AE_ADSP_AEE_CRC_CNTL_get_write_en2(data)                                ((0x00000008&(data))>>3)
#define  AE_ADSP_AEE_CRC_CNTL_get_crc_cont(data)                                 ((0x00000004&(data))>>2)
#define  AE_ADSP_AEE_CRC_CNTL_get_write_en3(data)                                ((0x00000002&(data))>>1)
#define  AE_ADSP_AEE_CRC_CNTL_get_crc_on(data)                                   (0x00000001&(data))

#define  AE_ADSP_AEE_CRC_LENGTH                                                  0x180020B4
#define  AE_ADSP_AEE_CRC_LENGTH_reg_addr                                         "0xB80020B4"
#define  AE_ADSP_AEE_CRC_LENGTH_reg                                              0xB80020B4
#define  AE_ADSP_AEE_CRC_LENGTH_inst_addr                                        "0x003A"
#define  set_AE_ADSP_AEE_CRC_LENGTH_reg(data)                                    (*((volatile unsigned int*)AE_ADSP_AEE_CRC_LENGTH_reg)=data)
#define  get_AE_ADSP_AEE_CRC_LENGTH_reg                                          (*((volatile unsigned int*)AE_ADSP_AEE_CRC_LENGTH_reg))
#define  AE_ADSP_AEE_CRC_LENGTH_crc_length_shift                                 (0)
#define  AE_ADSP_AEE_CRC_LENGTH_crc_length_mask                                  (0x0000FFFF)
#define  AE_ADSP_AEE_CRC_LENGTH_crc_length(data)                                 (0x0000FFFF&(data))
#define  AE_ADSP_AEE_CRC_LENGTH_get_crc_length(data)                             (0x0000FFFF&(data))

#define  AE_ADSP_AEE_CRC_RESULT                                                  0x180020B8
#define  AE_ADSP_AEE_CRC_RESULT_reg_addr                                         "0xB80020B8"
#define  AE_ADSP_AEE_CRC_RESULT_reg                                              0xB80020B8
#define  AE_ADSP_AEE_CRC_RESULT_inst_addr                                        "0x003B"
#define  set_AE_ADSP_AEE_CRC_RESULT_reg(data)                                    (*((volatile unsigned int*)AE_ADSP_AEE_CRC_RESULT_reg)=data)
#define  get_AE_ADSP_AEE_CRC_RESULT_reg                                          (*((volatile unsigned int*)AE_ADSP_AEE_CRC_RESULT_reg))
#define  AE_ADSP_AEE_CRC_RESULT_crc_result_shift                                 (0)
#define  AE_ADSP_AEE_CRC_RESULT_crc_result_mask                                  (0x0000FFFF)
#define  AE_ADSP_AEE_CRC_RESULT_crc_result(data)                                 (0x0000FFFF&(data))
#define  AE_ADSP_AEE_CRC_RESULT_get_crc_result(data)                             (0x0000FFFF&(data))

#define  AE_ADSP_AEE_BIT_CNT                                                     0x180020BC
#define  AE_ADSP_AEE_BIT_CNT_reg_addr                                            "0xB80020BC"
#define  AE_ADSP_AEE_BIT_CNT_reg                                                 0xB80020BC
#define  AE_ADSP_AEE_BIT_CNT_inst_addr                                           "0x003C"
#define  set_AE_ADSP_AEE_BIT_CNT_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_AEE_BIT_CNT_reg)=data)
#define  get_AE_ADSP_AEE_BIT_CNT_reg                                             (*((volatile unsigned int*)AE_ADSP_AEE_BIT_CNT_reg))
#define  AE_ADSP_AEE_BIT_CNT_crc_bit_cnt_shift                                   (0)
#define  AE_ADSP_AEE_BIT_CNT_crc_bit_cnt_mask                                    (0xFFFFFFFF)
#define  AE_ADSP_AEE_BIT_CNT_crc_bit_cnt(data)                                   (0xFFFFFFFF&(data))
#define  AE_ADSP_AEE_BIT_CNT_get_crc_bit_cnt(data)                               (0xFFFFFFFF&(data))

#define  AE_ADSP_AEE_CRC_ACC                                                     0x180020C0
#define  AE_ADSP_AEE_CRC_ACC_reg_addr                                            "0xB80020C0"
#define  AE_ADSP_AEE_CRC_ACC_reg                                                 0xB80020C0
#define  AE_ADSP_AEE_CRC_ACC_inst_addr                                           "0x003D"
#define  set_AE_ADSP_AEE_CRC_ACC_reg(data)                                       (*((volatile unsigned int*)AE_ADSP_AEE_CRC_ACC_reg)=data)
#define  get_AE_ADSP_AEE_CRC_ACC_reg                                             (*((volatile unsigned int*)AE_ADSP_AEE_CRC_ACC_reg))
#define  AE_ADSP_AEE_CRC_ACC_acc_shift                                           (0)
#define  AE_ADSP_AEE_CRC_ACC_acc_mask                                            (0x0000FFFF)
#define  AE_ADSP_AEE_CRC_ACC_acc(data)                                           (0x0000FFFF&(data))
#define  AE_ADSP_AEE_CRC_ACC_get_acc(data)                                       (0x0000FFFF&(data))

#define  AE_ADSP_AEE_CRC_ACC_CNT                                                 0x180020C4
#define  AE_ADSP_AEE_CRC_ACC_CNT_reg_addr                                        "0xB80020C4"
#define  AE_ADSP_AEE_CRC_ACC_CNT_reg                                             0xB80020C4
#define  AE_ADSP_AEE_CRC_ACC_CNT_inst_addr                                       "0x003E"
#define  set_AE_ADSP_AEE_CRC_ACC_CNT_reg(data)                                   (*((volatile unsigned int*)AE_ADSP_AEE_CRC_ACC_CNT_reg)=data)
#define  get_AE_ADSP_AEE_CRC_ACC_CNT_reg                                         (*((volatile unsigned int*)AE_ADSP_AEE_CRC_ACC_CNT_reg))
#define  AE_ADSP_AEE_CRC_ACC_CNT_acc_cnt_shift                                   (0)
#define  AE_ADSP_AEE_CRC_ACC_CNT_acc_cnt_mask                                    (0x0000000F)
#define  AE_ADSP_AEE_CRC_ACC_CNT_acc_cnt(data)                                   (0x0000000F&(data))
#define  AE_ADSP_AEE_CRC_ACC_CNT_get_acc_cnt(data)                               (0x0000000F&(data))

#define  AE_aee_ogg_mode                                                         0x180020D0
#define  AE_aee_ogg_mode_reg_addr                                                "0xB80020D0"
#define  AE_aee_ogg_mode_reg                                                     0xB80020D0
#define  AE_aee_ogg_mode_inst_addr                                               "0x003F"
#define  set_AE_aee_ogg_mode_reg(data)                                           (*((volatile unsigned int*)AE_aee_ogg_mode_reg)=data)
#define  get_AE_aee_ogg_mode_reg                                                 (*((volatile unsigned int*)AE_aee_ogg_mode_reg))
#define  AE_aee_ogg_mode_aee_audio_mode_shift                                    (0)
#define  AE_aee_ogg_mode_aee_audio_mode_mask                                     (0x00000003)
#define  AE_aee_ogg_mode_aee_audio_mode(data)                                    (0x00000003&(data))
#define  AE_aee_ogg_mode_get_aee_audio_mode(data)                                (0x00000003&(data))

#define  AE_ae_debug                                                             0x180020D8
#define  AE_ae_debug_reg_addr                                                    "0xB80020D8"
#define  AE_ae_debug_reg                                                         0xB80020D8
#define  AE_ae_debug_inst_addr                                                   "0x0040"
#define  set_AE_ae_debug_reg(data)                                               (*((volatile unsigned int*)AE_ae_debug_reg)=data)
#define  get_AE_ae_debug_reg                                                     (*((volatile unsigned int*)AE_ae_debug_reg))
#define  AE_ae_debug_ae_dbg_en_shift                                             (12)
#define  AE_ae_debug_ae_dbg_sel1_shift                                           (6)
#define  AE_ae_debug_ae_dbg_sel0_shift                                           (0)
#define  AE_ae_debug_ae_dbg_en_mask                                              (0x00001000)
#define  AE_ae_debug_ae_dbg_sel1_mask                                            (0x00000FC0)
#define  AE_ae_debug_ae_dbg_sel0_mask                                            (0x0000003F)
#define  AE_ae_debug_ae_dbg_en(data)                                             (0x00001000&((data)<<12))
#define  AE_ae_debug_ae_dbg_sel1(data)                                           (0x00000FC0&((data)<<6))
#define  AE_ae_debug_ae_dbg_sel0(data)                                           (0x0000003F&(data))
#define  AE_ae_debug_get_ae_dbg_en(data)                                         ((0x00001000&(data))>>12)
#define  AE_ae_debug_get_ae_dbg_sel1(data)                                       ((0x00000FC0&(data))>>6)
#define  AE_ae_debug_get_ae_dbg_sel0(data)                                       (0x0000003F&(data))

#define  AE_ae_dummy                                                             0x18002154
#define  AE_ae_dummy_reg_addr                                                    "0xB8002154"
#define  AE_ae_dummy_reg                                                         0xB8002154
#define  AE_ae_dummy_inst_addr                                                   "0x0041"
#define  set_AE_ae_dummy_reg(data)                                               (*((volatile unsigned int*)AE_ae_dummy_reg)=data)
#define  get_AE_ae_dummy_reg                                                     (*((volatile unsigned int*)AE_ae_dummy_reg))
#define  AE_ae_dummy_dummy_31_0_shift                                            (0)
#define  AE_ae_dummy_dummy_31_0_mask                                             (0xFFFFFFFF)
#define  AE_ae_dummy_dummy_31_0(data)                                            (0xFFFFFFFF&(data))
#define  AE_ae_dummy_get_dummy_31_0(data)                                        (0xFFFFFFFF&(data))

#define  AE_ae_src_rst                                                           0x18002164
#define  AE_ae_src_rst_reg_addr                                                  "0xB8002164"
#define  AE_ae_src_rst_reg                                                       0xB8002164
#define  AE_ae_src_rst_inst_addr                                                 "0x0042"
#define  set_AE_ae_src_rst_reg(data)                                             (*((volatile unsigned int*)AE_ae_src_rst_reg)=data)
#define  get_AE_ae_src_rst_reg                                                   (*((volatile unsigned int*)AE_ae_src_rst_reg))
#define  AE_ae_src_rst_rst_shift                                                 (0)
#define  AE_ae_src_rst_rst_mask                                                  (0x00000001)
#define  AE_ae_src_rst_rst(data)                                                 (0x00000001&(data))
#define  AE_ae_src_rst_get_rst(data)                                             (0x00000001&(data))

#define  AE_acpu_status                                                          0x180022A0
#define  AE_acpu_status_reg_addr                                                 "0xB80022A0"
#define  AE_acpu_status_reg                                                      0xB80022A0
#define  AE_acpu_status_inst_addr                                                "0x0043"
#define  set_AE_acpu_status_reg(data)                                            (*((volatile unsigned int*)AE_acpu_status_reg)=data)
#define  get_AE_acpu_status_reg                                                  (*((volatile unsigned int*)AE_acpu_status_reg))
#define  AE_acpu_status_sleep_mode_status_shift                                  (0)
#define  AE_acpu_status_sleep_mode_status_mask                                   (0x00000001)
#define  AE_acpu_status_sleep_mode_status(data)                                  (0x00000001&(data))
#define  AE_acpu_status_get_sleep_mode_status(data)                              (0x00000001&(data))

#define  AE_mbist_acpu_0                                                         0x18002200
#define  AE_mbist_acpu_0_reg_addr                                                "0xB8002200"
#define  AE_mbist_acpu_0_reg                                                     0xB8002200
#define  AE_mbist_acpu_0_inst_addr                                               "0x0044"
#define  set_AE_mbist_acpu_0_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_0_reg)=data)
#define  get_AE_mbist_acpu_0_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_0_reg))
#define  AE_mbist_acpu_0_ls_acpu_shift                                           (25)
#define  AE_mbist_acpu_0_rme_acpu_shift                                          (24)
#define  AE_mbist_acpu_0_ls_acpu_mask                                            (0x02000000)
#define  AE_mbist_acpu_0_rme_acpu_mask                                           (0x01000000)
#define  AE_mbist_acpu_0_ls_acpu(data)                                           (0x02000000&((data)<<25))
#define  AE_mbist_acpu_0_rme_acpu(data)                                          (0x01000000&((data)<<24))
#define  AE_mbist_acpu_0_get_ls_acpu(data)                                       ((0x02000000&(data))>>25)
#define  AE_mbist_acpu_0_get_rme_acpu(data)                                      ((0x01000000&(data))>>24)

#define  AE_mbist_acpu_1                                                         0x18002204
#define  AE_mbist_acpu_1_reg_addr                                                "0xB8002204"
#define  AE_mbist_acpu_1_reg                                                     0xB8002204
#define  AE_mbist_acpu_1_inst_addr                                               "0x0045"
#define  set_AE_mbist_acpu_1_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_1_reg)=data)
#define  get_AE_mbist_acpu_1_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_1_reg))
#define  AE_mbist_acpu_1_rm_dcache_tag_shift                                     (20)
#define  AE_mbist_acpu_1_rm_icache_lru_shift                                     (16)
#define  AE_mbist_acpu_1_rm_icache_tag_shift                                     (12)
#define  AE_mbist_acpu_1_rm_btb_data_shift                                       (8)
#define  AE_mbist_acpu_1_rm_btb_tag_shift                                        (4)
#define  AE_mbist_acpu_1_rm_pht_shift                                            (0)
#define  AE_mbist_acpu_1_rm_dcache_tag_mask                                      (0x00F00000)
#define  AE_mbist_acpu_1_rm_icache_lru_mask                                      (0x000F0000)
#define  AE_mbist_acpu_1_rm_icache_tag_mask                                      (0x0000F000)
#define  AE_mbist_acpu_1_rm_btb_data_mask                                        (0x00000F00)
#define  AE_mbist_acpu_1_rm_btb_tag_mask                                         (0x000000F0)
#define  AE_mbist_acpu_1_rm_pht_mask                                             (0x0000000F)
#define  AE_mbist_acpu_1_rm_dcache_tag(data)                                     (0x00F00000&((data)<<20))
#define  AE_mbist_acpu_1_rm_icache_lru(data)                                     (0x000F0000&((data)<<16))
#define  AE_mbist_acpu_1_rm_icache_tag(data)                                     (0x0000F000&((data)<<12))
#define  AE_mbist_acpu_1_rm_btb_data(data)                                       (0x00000F00&((data)<<8))
#define  AE_mbist_acpu_1_rm_btb_tag(data)                                        (0x000000F0&((data)<<4))
#define  AE_mbist_acpu_1_rm_pht(data)                                            (0x0000000F&(data))
#define  AE_mbist_acpu_1_get_rm_dcache_tag(data)                                 ((0x00F00000&(data))>>20)
#define  AE_mbist_acpu_1_get_rm_icache_lru(data)                                 ((0x000F0000&(data))>>16)
#define  AE_mbist_acpu_1_get_rm_icache_tag(data)                                 ((0x0000F000&(data))>>12)
#define  AE_mbist_acpu_1_get_rm_btb_data(data)                                   ((0x00000F00&(data))>>8)
#define  AE_mbist_acpu_1_get_rm_btb_tag(data)                                    ((0x000000F0&(data))>>4)
#define  AE_mbist_acpu_1_get_rm_pht(data)                                        (0x0000000F&(data))

#define  AE_mbisr_acpu_0                                                         0x18002208
#define  AE_mbisr_acpu_0_reg_addr                                                "0xB8002208"
#define  AE_mbisr_acpu_0_reg                                                     0xB8002208
#define  AE_mbisr_acpu_0_inst_addr                                               "0x0046"
#define  set_AE_mbisr_acpu_0_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_0_reg)=data)
#define  get_AE_mbisr_acpu_0_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_0_reg))
#define  AE_mbisr_acpu_0_rm_icache_data_shift                                    (20)
#define  AE_mbisr_acpu_0_rm_dcache_data_shift                                    (16)
#define  AE_mbisr_acpu_0_rm_dmem0_shift                                          (12)
#define  AE_mbisr_acpu_0_rm_dmem1_shift                                          (8)
#define  AE_mbisr_acpu_0_rm_imem_shift                                           (4)
#define  AE_mbisr_acpu_0_rm_icache_data_mask                                     (0x00F00000)
#define  AE_mbisr_acpu_0_rm_dcache_data_mask                                     (0x000F0000)
#define  AE_mbisr_acpu_0_rm_dmem0_mask                                           (0x0000F000)
#define  AE_mbisr_acpu_0_rm_dmem1_mask                                           (0x00000F00)
#define  AE_mbisr_acpu_0_rm_imem_mask                                            (0x000000F0)
#define  AE_mbisr_acpu_0_rm_icache_data(data)                                    (0x00F00000&((data)<<20))
#define  AE_mbisr_acpu_0_rm_dcache_data(data)                                    (0x000F0000&((data)<<16))
#define  AE_mbisr_acpu_0_rm_dmem0(data)                                          (0x0000F000&((data)<<12))
#define  AE_mbisr_acpu_0_rm_dmem1(data)                                          (0x00000F00&((data)<<8))
#define  AE_mbisr_acpu_0_rm_imem(data)                                           (0x000000F0&((data)<<4))
#define  AE_mbisr_acpu_0_get_rm_icache_data(data)                                ((0x00F00000&(data))>>20)
#define  AE_mbisr_acpu_0_get_rm_dcache_data(data)                                ((0x000F0000&(data))>>16)
#define  AE_mbisr_acpu_0_get_rm_dmem0(data)                                      ((0x0000F000&(data))>>12)
#define  AE_mbisr_acpu_0_get_rm_dmem1(data)                                      ((0x00000F00&(data))>>8)
#define  AE_mbisr_acpu_0_get_rm_imem(data)                                       ((0x000000F0&(data))>>4)

#define  AE_mbist_acpu_2                                                         0x18002210
#define  AE_mbist_acpu_2_reg_addr                                                "0xB8002210"
#define  AE_mbist_acpu_2_reg                                                     0xB8002210
#define  AE_mbist_acpu_2_inst_addr                                               "0x0047"
#define  set_AE_mbist_acpu_2_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_2_reg)=data)
#define  get_AE_mbist_acpu_2_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_2_reg))
#define  AE_mbist_acpu_2_acpu_bist_mode_shift                                    (0)
#define  AE_mbist_acpu_2_acpu_bist_mode_mask                                     (0x00000001)
#define  AE_mbist_acpu_2_acpu_bist_mode(data)                                    (0x00000001&(data))
#define  AE_mbist_acpu_2_get_acpu_bist_mode(data)                                (0x00000001&(data))

#define  AE_mbist_acpu_3                                                         0x18002214
#define  AE_mbist_acpu_3_reg_addr                                                "0xB8002214"
#define  AE_mbist_acpu_3_reg                                                     0xB8002214
#define  AE_mbist_acpu_3_inst_addr                                               "0x0048"
#define  set_AE_mbist_acpu_3_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_3_reg)=data)
#define  get_AE_mbist_acpu_3_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_3_reg))
#define  AE_mbist_acpu_3_acpu_bist_done_shift                                    (0)
#define  AE_mbist_acpu_3_acpu_bist_done_mask                                     (0x00000001)
#define  AE_mbist_acpu_3_acpu_bist_done(data)                                    (0x00000001&(data))
#define  AE_mbist_acpu_3_get_acpu_bist_done(data)                                (0x00000001&(data))

#define  AE_mbist_acpu_4                                                         0x18002218
#define  AE_mbist_acpu_4_reg_addr                                                "0xB8002218"
#define  AE_mbist_acpu_4_reg                                                     0xB8002218
#define  AE_mbist_acpu_4_inst_addr                                               "0x0049"
#define  set_AE_mbist_acpu_4_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_4_reg)=data)
#define  get_AE_mbist_acpu_4_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_4_reg))
#define  AE_mbist_acpu_4_acpu_bist_fail_group_shift                              (0)
#define  AE_mbist_acpu_4_acpu_bist_fail_group_mask                               (0x00000001)
#define  AE_mbist_acpu_4_acpu_bist_fail_group(data)                              (0x00000001&(data))
#define  AE_mbist_acpu_4_get_acpu_bist_fail_group(data)                          (0x00000001&(data))

#define  AE_mbist_acpu_5                                                         0x1800221C
#define  AE_mbist_acpu_5_reg_addr                                                "0xB800221C"
#define  AE_mbist_acpu_5_reg                                                     0xB800221C
#define  AE_mbist_acpu_5_inst_addr                                               "0x004A"
#define  set_AE_mbist_acpu_5_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_5_reg)=data)
#define  get_AE_mbist_acpu_5_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_5_reg))
#define  AE_mbist_acpu_5_bist_fail5_shift                                        (5)
#define  AE_mbist_acpu_5_bist_fail4_shift                                        (4)
#define  AE_mbist_acpu_5_bist_fail3_shift                                        (3)
#define  AE_mbist_acpu_5_bist_fail2_shift                                        (2)
#define  AE_mbist_acpu_5_bist_fail1_shift                                        (1)
#define  AE_mbist_acpu_5_bist_fail0_shift                                        (0)
#define  AE_mbist_acpu_5_bist_fail5_mask                                         (0x00000020)
#define  AE_mbist_acpu_5_bist_fail4_mask                                         (0x00000010)
#define  AE_mbist_acpu_5_bist_fail3_mask                                         (0x00000008)
#define  AE_mbist_acpu_5_bist_fail2_mask                                         (0x00000004)
#define  AE_mbist_acpu_5_bist_fail1_mask                                         (0x00000002)
#define  AE_mbist_acpu_5_bist_fail0_mask                                         (0x00000001)
#define  AE_mbist_acpu_5_bist_fail5(data)                                        (0x00000020&((data)<<5))
#define  AE_mbist_acpu_5_bist_fail4(data)                                        (0x00000010&((data)<<4))
#define  AE_mbist_acpu_5_bist_fail3(data)                                        (0x00000008&((data)<<3))
#define  AE_mbist_acpu_5_bist_fail2(data)                                        (0x00000004&((data)<<2))
#define  AE_mbist_acpu_5_bist_fail1(data)                                        (0x00000002&((data)<<1))
#define  AE_mbist_acpu_5_bist_fail0(data)                                        (0x00000001&(data))
#define  AE_mbist_acpu_5_get_bist_fail5(data)                                    ((0x00000020&(data))>>5)
#define  AE_mbist_acpu_5_get_bist_fail4(data)                                    ((0x00000010&(data))>>4)
#define  AE_mbist_acpu_5_get_bist_fail3(data)                                    ((0x00000008&(data))>>3)
#define  AE_mbist_acpu_5_get_bist_fail2(data)                                    ((0x00000004&(data))>>2)
#define  AE_mbist_acpu_5_get_bist_fail1(data)                                    ((0x00000002&(data))>>1)
#define  AE_mbist_acpu_5_get_bist_fail0(data)                                    (0x00000001&(data))

#define  AE_mbist_acpu_6                                                         0x18002220
#define  AE_mbist_acpu_6_reg_addr                                                "0xB8002220"
#define  AE_mbist_acpu_6_reg                                                     0xB8002220
#define  AE_mbist_acpu_6_inst_addr                                               "0x004B"
#define  set_AE_mbist_acpu_6_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_6_reg)=data)
#define  get_AE_mbist_acpu_6_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_6_reg))
#define  AE_mbist_acpu_6_drf_mode_shift                                          (0)
#define  AE_mbist_acpu_6_drf_mode_mask                                           (0x00000001)
#define  AE_mbist_acpu_6_drf_mode(data)                                          (0x00000001&(data))
#define  AE_mbist_acpu_6_get_drf_mode(data)                                      (0x00000001&(data))

#define  AE_mbist_acpu_7                                                         0x18002224
#define  AE_mbist_acpu_7_reg_addr                                                "0xB8002224"
#define  AE_mbist_acpu_7_reg                                                     0xB8002224
#define  AE_mbist_acpu_7_inst_addr                                               "0x004C"
#define  set_AE_mbist_acpu_7_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_7_reg)=data)
#define  get_AE_mbist_acpu_7_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_7_reg))
#define  AE_mbist_acpu_7_drf_resume_shift                                        (0)
#define  AE_mbist_acpu_7_drf_resume_mask                                         (0x00000001)
#define  AE_mbist_acpu_7_drf_resume(data)                                        (0x00000001&(data))
#define  AE_mbist_acpu_7_get_drf_resume(data)                                    (0x00000001&(data))

#define  AE_mbist_acpu_8                                                         0x18002228
#define  AE_mbist_acpu_8_reg_addr                                                "0xB8002228"
#define  AE_mbist_acpu_8_reg                                                     0xB8002228
#define  AE_mbist_acpu_8_inst_addr                                               "0x004D"
#define  set_AE_mbist_acpu_8_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_8_reg)=data)
#define  get_AE_mbist_acpu_8_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_8_reg))
#define  AE_mbist_acpu_8_drf_done_shift                                          (0)
#define  AE_mbist_acpu_8_drf_done_mask                                           (0x00000001)
#define  AE_mbist_acpu_8_drf_done(data)                                          (0x00000001&(data))
#define  AE_mbist_acpu_8_get_drf_done(data)                                      (0x00000001&(data))

#define  AE_mbist_acpu_9                                                         0x1800222C
#define  AE_mbist_acpu_9_reg_addr                                                "0xB800222C"
#define  AE_mbist_acpu_9_reg                                                     0xB800222C
#define  AE_mbist_acpu_9_inst_addr                                               "0x004E"
#define  set_AE_mbist_acpu_9_reg(data)                                           (*((volatile unsigned int*)AE_mbist_acpu_9_reg)=data)
#define  get_AE_mbist_acpu_9_reg                                                 (*((volatile unsigned int*)AE_mbist_acpu_9_reg))
#define  AE_mbist_acpu_9_drf_pause_shift                                         (0)
#define  AE_mbist_acpu_9_drf_pause_mask                                          (0x00000001)
#define  AE_mbist_acpu_9_drf_pause(data)                                         (0x00000001&(data))
#define  AE_mbist_acpu_9_get_drf_pause(data)                                     (0x00000001&(data))

#define  AE_mbist_acpu_10                                                        0x18002230
#define  AE_mbist_acpu_10_reg_addr                                               "0xB8002230"
#define  AE_mbist_acpu_10_reg                                                    0xB8002230
#define  AE_mbist_acpu_10_inst_addr                                              "0x004F"
#define  set_AE_mbist_acpu_10_reg(data)                                          (*((volatile unsigned int*)AE_mbist_acpu_10_reg)=data)
#define  get_AE_mbist_acpu_10_reg                                                (*((volatile unsigned int*)AE_mbist_acpu_10_reg))
#define  AE_mbist_acpu_10_drf_fail_group_shift                                   (0)
#define  AE_mbist_acpu_10_drf_fail_group_mask                                    (0x00000001)
#define  AE_mbist_acpu_10_drf_fail_group(data)                                   (0x00000001&(data))
#define  AE_mbist_acpu_10_get_drf_fail_group(data)                               (0x00000001&(data))

#define  AE_mbist_acpu_11                                                        0x18002234
#define  AE_mbist_acpu_11_reg_addr                                               "0xB8002234"
#define  AE_mbist_acpu_11_reg                                                    0xB8002234
#define  AE_mbist_acpu_11_inst_addr                                              "0x0050"
#define  set_AE_mbist_acpu_11_reg(data)                                          (*((volatile unsigned int*)AE_mbist_acpu_11_reg)=data)
#define  get_AE_mbist_acpu_11_reg                                                (*((volatile unsigned int*)AE_mbist_acpu_11_reg))
#define  AE_mbist_acpu_11_drf_fail5_shift                                        (5)
#define  AE_mbist_acpu_11_drf_fail4_shift                                        (4)
#define  AE_mbist_acpu_11_drf_fail3_shift                                        (3)
#define  AE_mbist_acpu_11_drf_fail2_shift                                        (2)
#define  AE_mbist_acpu_11_drf_fail1_shift                                        (1)
#define  AE_mbist_acpu_11_drf_fail0_shift                                        (0)
#define  AE_mbist_acpu_11_drf_fail5_mask                                         (0x00000020)
#define  AE_mbist_acpu_11_drf_fail4_mask                                         (0x00000010)
#define  AE_mbist_acpu_11_drf_fail3_mask                                         (0x00000008)
#define  AE_mbist_acpu_11_drf_fail2_mask                                         (0x00000004)
#define  AE_mbist_acpu_11_drf_fail1_mask                                         (0x00000002)
#define  AE_mbist_acpu_11_drf_fail0_mask                                         (0x00000001)
#define  AE_mbist_acpu_11_drf_fail5(data)                                        (0x00000020&((data)<<5))
#define  AE_mbist_acpu_11_drf_fail4(data)                                        (0x00000010&((data)<<4))
#define  AE_mbist_acpu_11_drf_fail3(data)                                        (0x00000008&((data)<<3))
#define  AE_mbist_acpu_11_drf_fail2(data)                                        (0x00000004&((data)<<2))
#define  AE_mbist_acpu_11_drf_fail1(data)                                        (0x00000002&((data)<<1))
#define  AE_mbist_acpu_11_drf_fail0(data)                                        (0x00000001&(data))
#define  AE_mbist_acpu_11_get_drf_fail5(data)                                    ((0x00000020&(data))>>5)
#define  AE_mbist_acpu_11_get_drf_fail4(data)                                    ((0x00000010&(data))>>4)
#define  AE_mbist_acpu_11_get_drf_fail3(data)                                    ((0x00000008&(data))>>3)
#define  AE_mbist_acpu_11_get_drf_fail2(data)                                    ((0x00000004&(data))>>2)
#define  AE_mbist_acpu_11_get_drf_fail1(data)                                    ((0x00000002&(data))>>1)
#define  AE_mbist_acpu_11_get_drf_fail0(data)                                    (0x00000001&(data))

#define  AE_mbisr_acpu_1                                                         0x18002238
#define  AE_mbisr_acpu_1_reg_addr                                                "0xB8002238"
#define  AE_mbisr_acpu_1_reg                                                     0xB8002238
#define  AE_mbisr_acpu_1_inst_addr                                               "0x0051"
#define  set_AE_mbisr_acpu_1_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_1_reg)=data)
#define  get_AE_mbisr_acpu_1_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_1_reg))
#define  AE_mbisr_acpu_1_bisr3_second_run_en_shift                               (3)
#define  AE_mbisr_acpu_1_bisr2_second_run_en_shift                               (2)
#define  AE_mbisr_acpu_1_bisr1_second_run_en_shift                               (1)
#define  AE_mbisr_acpu_1_bisr0_second_run_en_shift                               (0)
#define  AE_mbisr_acpu_1_bisr3_second_run_en_mask                                (0x00000008)
#define  AE_mbisr_acpu_1_bisr2_second_run_en_mask                                (0x00000004)
#define  AE_mbisr_acpu_1_bisr1_second_run_en_mask                                (0x00000002)
#define  AE_mbisr_acpu_1_bisr0_second_run_en_mask                                (0x00000001)
#define  AE_mbisr_acpu_1_bisr3_second_run_en(data)                               (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_1_bisr2_second_run_en(data)                               (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_1_bisr1_second_run_en(data)                               (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_1_bisr0_second_run_en(data)                               (0x00000001&(data))
#define  AE_mbisr_acpu_1_get_bisr3_second_run_en(data)                           ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_1_get_bisr2_second_run_en(data)                           ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_1_get_bisr1_second_run_en(data)                           ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_1_get_bisr0_second_run_en(data)                           (0x00000001&(data))

#define  AE_mbisr_acpu_2                                                         0x1800223C
#define  AE_mbisr_acpu_2_reg_addr                                                "0xB800223C"
#define  AE_mbisr_acpu_2_reg                                                     0xB800223C
#define  AE_mbisr_acpu_2_inst_addr                                               "0x0052"
#define  set_AE_mbisr_acpu_2_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_2_reg)=data)
#define  get_AE_mbisr_acpu_2_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_2_reg))
#define  AE_mbisr_acpu_2_bisr3_fail_group_shift                                  (3)
#define  AE_mbisr_acpu_2_bisr2_fail_group_shift                                  (2)
#define  AE_mbisr_acpu_2_bisr1_fail_group_shift                                  (1)
#define  AE_mbisr_acpu_2_bisr0_fail_group_shift                                  (0)
#define  AE_mbisr_acpu_2_bisr3_fail_group_mask                                   (0x00000008)
#define  AE_mbisr_acpu_2_bisr2_fail_group_mask                                   (0x00000004)
#define  AE_mbisr_acpu_2_bisr1_fail_group_mask                                   (0x00000002)
#define  AE_mbisr_acpu_2_bisr0_fail_group_mask                                   (0x00000001)
#define  AE_mbisr_acpu_2_bisr3_fail_group(data)                                  (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_2_bisr2_fail_group(data)                                  (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_2_bisr1_fail_group(data)                                  (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_2_bisr0_fail_group(data)                                  (0x00000001&(data))
#define  AE_mbisr_acpu_2_get_bisr3_fail_group(data)                              ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_2_get_bisr2_fail_group(data)                              ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_2_get_bisr1_fail_group(data)                              ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_2_get_bisr0_fail_group(data)                              (0x00000001&(data))

#define  AE_mbisr_acpu_3                                                         0x18002240
#define  AE_mbisr_acpu_3_reg_addr                                                "0xB8002240"
#define  AE_mbisr_acpu_3_reg                                                     0xB8002240
#define  AE_mbisr_acpu_3_inst_addr                                               "0x0053"
#define  set_AE_mbisr_acpu_3_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_3_reg)=data)
#define  get_AE_mbisr_acpu_3_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_3_reg))
#define  AE_mbisr_acpu_3_bisr3_fail_0_shift                                      (4)
#define  AE_mbisr_acpu_3_bisr2_fail_1_shift                                      (3)
#define  AE_mbisr_acpu_3_bisr2_fail_0_shift                                      (2)
#define  AE_mbisr_acpu_3_bisr1_fail_0_shift                                      (1)
#define  AE_mbisr_acpu_3_bisr0_fail_0_shift                                      (0)
#define  AE_mbisr_acpu_3_bisr3_fail_0_mask                                       (0x00000010)
#define  AE_mbisr_acpu_3_bisr2_fail_1_mask                                       (0x00000008)
#define  AE_mbisr_acpu_3_bisr2_fail_0_mask                                       (0x00000004)
#define  AE_mbisr_acpu_3_bisr1_fail_0_mask                                       (0x00000002)
#define  AE_mbisr_acpu_3_bisr0_fail_0_mask                                       (0x00000001)
#define  AE_mbisr_acpu_3_bisr3_fail_0(data)                                      (0x00000010&((data)<<4))
#define  AE_mbisr_acpu_3_bisr2_fail_1(data)                                      (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_3_bisr2_fail_0(data)                                      (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_3_bisr1_fail_0(data)                                      (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_3_bisr0_fail_0(data)                                      (0x00000001&(data))
#define  AE_mbisr_acpu_3_get_bisr3_fail_0(data)                                  ((0x00000010&(data))>>4)
#define  AE_mbisr_acpu_3_get_bisr2_fail_1(data)                                  ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_3_get_bisr2_fail_0(data)                                  ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_3_get_bisr1_fail_0(data)                                  ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_3_get_bisr0_fail_0(data)                                  (0x00000001&(data))

#define  AE_mbisr_acpu_4                                                         0x18002244
#define  AE_mbisr_acpu_4_reg_addr                                                "0xB8002244"
#define  AE_mbisr_acpu_4_reg                                                     0xB8002244
#define  AE_mbisr_acpu_4_inst_addr                                               "0x0054"
#define  set_AE_mbisr_acpu_4_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_4_reg)=data)
#define  get_AE_mbisr_acpu_4_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_4_reg))
#define  AE_mbisr_acpu_4_bisr3_drf_mode_shift                                    (3)
#define  AE_mbisr_acpu_4_bisr2_drf_mode_shift                                    (2)
#define  AE_mbisr_acpu_4_bisr1_drf_mode_shift                                    (1)
#define  AE_mbisr_acpu_4_bisr0_drf_mode_shift                                    (0)
#define  AE_mbisr_acpu_4_bisr3_drf_mode_mask                                     (0x00000008)
#define  AE_mbisr_acpu_4_bisr2_drf_mode_mask                                     (0x00000004)
#define  AE_mbisr_acpu_4_bisr1_drf_mode_mask                                     (0x00000002)
#define  AE_mbisr_acpu_4_bisr0_drf_mode_mask                                     (0x00000001)
#define  AE_mbisr_acpu_4_bisr3_drf_mode(data)                                    (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_4_bisr2_drf_mode(data)                                    (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_4_bisr1_drf_mode(data)                                    (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_4_bisr0_drf_mode(data)                                    (0x00000001&(data))
#define  AE_mbisr_acpu_4_get_bisr3_drf_mode(data)                                ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_4_get_bisr2_drf_mode(data)                                ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_4_get_bisr1_drf_mode(data)                                ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_4_get_bisr0_drf_mode(data)                                (0x00000001&(data))

#define  AE_mbisr_acpu_5                                                         0x18002248
#define  AE_mbisr_acpu_5_reg_addr                                                "0xB8002248"
#define  AE_mbisr_acpu_5_reg                                                     0xB8002248
#define  AE_mbisr_acpu_5_inst_addr                                               "0x0055"
#define  set_AE_mbisr_acpu_5_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_5_reg)=data)
#define  get_AE_mbisr_acpu_5_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_5_reg))
#define  AE_mbisr_acpu_5_drf_3_resume_shift                                      (3)
#define  AE_mbisr_acpu_5_drf_2_resume_shift                                      (2)
#define  AE_mbisr_acpu_5_drf_1_resume_shift                                      (1)
#define  AE_mbisr_acpu_5_drf_0_resume_shift                                      (0)
#define  AE_mbisr_acpu_5_drf_3_resume_mask                                       (0x00000008)
#define  AE_mbisr_acpu_5_drf_2_resume_mask                                       (0x00000004)
#define  AE_mbisr_acpu_5_drf_1_resume_mask                                       (0x00000002)
#define  AE_mbisr_acpu_5_drf_0_resume_mask                                       (0x00000001)
#define  AE_mbisr_acpu_5_drf_3_resume(data)                                      (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_5_drf_2_resume(data)                                      (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_5_drf_1_resume(data)                                      (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_5_drf_0_resume(data)                                      (0x00000001&(data))
#define  AE_mbisr_acpu_5_get_drf_3_resume(data)                                  ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_5_get_drf_2_resume(data)                                  ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_5_get_drf_1_resume(data)                                  ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_5_get_drf_0_resume(data)                                  (0x00000001&(data))

#define  AE_mbisr_acpu_6                                                         0x1800224C
#define  AE_mbisr_acpu_6_reg_addr                                                "0xB800224C"
#define  AE_mbisr_acpu_6_reg                                                     0xB800224C
#define  AE_mbisr_acpu_6_inst_addr                                               "0x0056"
#define  set_AE_mbisr_acpu_6_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_6_reg)=data)
#define  get_AE_mbisr_acpu_6_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_6_reg))
#define  AE_mbisr_acpu_6_bisr3_drf_done_shift                                    (3)
#define  AE_mbisr_acpu_6_bisr2_drf_done_shift                                    (2)
#define  AE_mbisr_acpu_6_bisr1_drf_done_shift                                    (1)
#define  AE_mbisr_acpu_6_bisr0_drf_done_shift                                    (0)
#define  AE_mbisr_acpu_6_bisr3_drf_done_mask                                     (0x00000008)
#define  AE_mbisr_acpu_6_bisr2_drf_done_mask                                     (0x00000004)
#define  AE_mbisr_acpu_6_bisr1_drf_done_mask                                     (0x00000002)
#define  AE_mbisr_acpu_6_bisr0_drf_done_mask                                     (0x00000001)
#define  AE_mbisr_acpu_6_bisr3_drf_done(data)                                    (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_6_bisr2_drf_done(data)                                    (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_6_bisr1_drf_done(data)                                    (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_6_bisr0_drf_done(data)                                    (0x00000001&(data))
#define  AE_mbisr_acpu_6_get_bisr3_drf_done(data)                                ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_6_get_bisr2_drf_done(data)                                ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_6_get_bisr1_drf_done(data)                                ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_6_get_bisr0_drf_done(data)                                (0x00000001&(data))

#define  AE_mbisr_acpu_7                                                         0x18002250
#define  AE_mbisr_acpu_7_reg_addr                                                "0xB8002250"
#define  AE_mbisr_acpu_7_reg                                                     0xB8002250
#define  AE_mbisr_acpu_7_inst_addr                                               "0x0057"
#define  set_AE_mbisr_acpu_7_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_7_reg)=data)
#define  get_AE_mbisr_acpu_7_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_7_reg))
#define  AE_mbisr_acpu_7_bisr3_drf_fail_group_shift                              (3)
#define  AE_mbisr_acpu_7_bisr2_drf_fail_group_shift                              (2)
#define  AE_mbisr_acpu_7_bisr1_drf_fail_group_shift                              (1)
#define  AE_mbisr_acpu_7_bisr0_drf_fail_group_shift                              (0)
#define  AE_mbisr_acpu_7_bisr3_drf_fail_group_mask                               (0x00000008)
#define  AE_mbisr_acpu_7_bisr2_drf_fail_group_mask                               (0x00000004)
#define  AE_mbisr_acpu_7_bisr1_drf_fail_group_mask                               (0x00000002)
#define  AE_mbisr_acpu_7_bisr0_drf_fail_group_mask                               (0x00000001)
#define  AE_mbisr_acpu_7_bisr3_drf_fail_group(data)                              (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_7_bisr2_drf_fail_group(data)                              (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_7_bisr1_drf_fail_group(data)                              (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_7_bisr0_drf_fail_group(data)                              (0x00000001&(data))
#define  AE_mbisr_acpu_7_get_bisr3_drf_fail_group(data)                          ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_7_get_bisr2_drf_fail_group(data)                          ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_7_get_bisr1_drf_fail_group(data)                          ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_7_get_bisr0_drf_fail_group(data)                          (0x00000001&(data))

#define  AE_mbisr_acpu_8                                                         0x18002254
#define  AE_mbisr_acpu_8_reg_addr                                                "0xB8002254"
#define  AE_mbisr_acpu_8_reg                                                     0xB8002254
#define  AE_mbisr_acpu_8_inst_addr                                               "0x0058"
#define  set_AE_mbisr_acpu_8_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_8_reg)=data)
#define  get_AE_mbisr_acpu_8_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_8_reg))
#define  AE_mbisr_acpu_8_drf_3_pause_shift                                       (3)
#define  AE_mbisr_acpu_8_drf_2_pause_shift                                       (2)
#define  AE_mbisr_acpu_8_drf_1_pause_shift                                       (1)
#define  AE_mbisr_acpu_8_drf_0_pause_shift                                       (0)
#define  AE_mbisr_acpu_8_drf_3_pause_mask                                        (0x00000008)
#define  AE_mbisr_acpu_8_drf_2_pause_mask                                        (0x00000004)
#define  AE_mbisr_acpu_8_drf_1_pause_mask                                        (0x00000002)
#define  AE_mbisr_acpu_8_drf_0_pause_mask                                        (0x00000001)
#define  AE_mbisr_acpu_8_drf_3_pause(data)                                       (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_8_drf_2_pause(data)                                       (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_8_drf_1_pause(data)                                       (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_8_drf_0_pause(data)                                       (0x00000001&(data))
#define  AE_mbisr_acpu_8_get_drf_3_pause(data)                                   ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_8_get_drf_2_pause(data)                                   ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_8_get_drf_1_pause(data)                                   ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_8_get_drf_0_pause(data)                                   (0x00000001&(data))

#define  AE_mbisr_acpu_9                                                         0x18002258
#define  AE_mbisr_acpu_9_reg_addr                                                "0xB8002258"
#define  AE_mbisr_acpu_9_reg                                                     0xB8002258
#define  AE_mbisr_acpu_9_inst_addr                                               "0x0059"
#define  set_AE_mbisr_acpu_9_reg(data)                                           (*((volatile unsigned int*)AE_mbisr_acpu_9_reg)=data)
#define  get_AE_mbisr_acpu_9_reg                                                 (*((volatile unsigned int*)AE_mbisr_acpu_9_reg))
#define  AE_mbisr_acpu_9_drf_3_repaired_shift                                    (31)
#define  AE_mbisr_acpu_9_drf_2_repaired_shift                                    (30)
#define  AE_mbisr_acpu_9_drf_1_repaired_shift                                    (29)
#define  AE_mbisr_acpu_9_drf_0_repaired_shift                                    (28)
#define  AE_mbisr_acpu_9_drf_3_fail_0_shift                                      (4)
#define  AE_mbisr_acpu_9_drf_2_fail_1_shift                                      (3)
#define  AE_mbisr_acpu_9_drf_2_fail_0_shift                                      (2)
#define  AE_mbisr_acpu_9_drf_1_fail_0_shift                                      (1)
#define  AE_mbisr_acpu_9_drf_0_fail_0_shift                                      (0)
#define  AE_mbisr_acpu_9_drf_3_repaired_mask                                     (0x80000000)
#define  AE_mbisr_acpu_9_drf_2_repaired_mask                                     (0x40000000)
#define  AE_mbisr_acpu_9_drf_1_repaired_mask                                     (0x20000000)
#define  AE_mbisr_acpu_9_drf_0_repaired_mask                                     (0x10000000)
#define  AE_mbisr_acpu_9_drf_3_fail_0_mask                                       (0x00000010)
#define  AE_mbisr_acpu_9_drf_2_fail_1_mask                                       (0x00000008)
#define  AE_mbisr_acpu_9_drf_2_fail_0_mask                                       (0x00000004)
#define  AE_mbisr_acpu_9_drf_1_fail_0_mask                                       (0x00000002)
#define  AE_mbisr_acpu_9_drf_0_fail_0_mask                                       (0x00000001)
#define  AE_mbisr_acpu_9_drf_3_repaired(data)                                    (0x80000000&((data)<<31))
#define  AE_mbisr_acpu_9_drf_2_repaired(data)                                    (0x40000000&((data)<<30))
#define  AE_mbisr_acpu_9_drf_1_repaired(data)                                    (0x20000000&((data)<<29))
#define  AE_mbisr_acpu_9_drf_0_repaired(data)                                    (0x10000000&((data)<<28))
#define  AE_mbisr_acpu_9_drf_3_fail_0(data)                                      (0x00000010&((data)<<4))
#define  AE_mbisr_acpu_9_drf_2_fail_1(data)                                      (0x00000008&((data)<<3))
#define  AE_mbisr_acpu_9_drf_2_fail_0(data)                                      (0x00000004&((data)<<2))
#define  AE_mbisr_acpu_9_drf_1_fail_0(data)                                      (0x00000002&((data)<<1))
#define  AE_mbisr_acpu_9_drf_0_fail_0(data)                                      (0x00000001&(data))
#define  AE_mbisr_acpu_9_get_drf_3_repaired(data)                                ((0x80000000&(data))>>31)
#define  AE_mbisr_acpu_9_get_drf_2_repaired(data)                                ((0x40000000&(data))>>30)
#define  AE_mbisr_acpu_9_get_drf_1_repaired(data)                                ((0x20000000&(data))>>29)
#define  AE_mbisr_acpu_9_get_drf_0_repaired(data)                                ((0x10000000&(data))>>28)
#define  AE_mbisr_acpu_9_get_drf_3_fail_0(data)                                  ((0x00000010&(data))>>4)
#define  AE_mbisr_acpu_9_get_drf_2_fail_1(data)                                  ((0x00000008&(data))>>3)
#define  AE_mbisr_acpu_9_get_drf_2_fail_0(data)                                  ((0x00000004&(data))>>2)
#define  AE_mbisr_acpu_9_get_drf_1_fail_0(data)                                  ((0x00000002&(data))>>1)
#define  AE_mbisr_acpu_9_get_drf_0_fail_0(data)                                  (0x00000001&(data))

#define  AE_ae_bist_0                                                            0x18002260
#define  AE_ae_bist_0_reg_addr                                                   "0xB8002260"
#define  AE_ae_bist_0_reg                                                        0xB8002260
#define  AE_ae_bist_0_inst_addr                                                  "0x005A"
#define  set_AE_ae_bist_0_reg(data)                                              (*((volatile unsigned int*)AE_ae_bist_0_reg)=data)
#define  get_AE_ae_bist_0_reg                                                    (*((volatile unsigned int*)AE_ae_bist_0_reg))
#define  AE_ae_bist_0_rmeb_aee_shift                                             (28)
#define  AE_ae_bist_0_rmb_aee_shift                                              (24)
#define  AE_ae_bist_0_rmea_aee_shift                                             (20)
#define  AE_ae_bist_0_rma_aee_shift                                              (16)
#define  AE_ae_bist_0_rmeb_ade_shift                                             (12)
#define  AE_ae_bist_0_rmb_ade_shift                                              (8)
#define  AE_ae_bist_0_rmea_ade_shift                                             (4)
#define  AE_ae_bist_0_rma_ade_shift                                              (0)
#define  AE_ae_bist_0_rmeb_aee_mask                                              (0x10000000)
#define  AE_ae_bist_0_rmb_aee_mask                                               (0x0F000000)
#define  AE_ae_bist_0_rmea_aee_mask                                              (0x00100000)
#define  AE_ae_bist_0_rma_aee_mask                                               (0x000F0000)
#define  AE_ae_bist_0_rmeb_ade_mask                                              (0x00001000)
#define  AE_ae_bist_0_rmb_ade_mask                                               (0x00000F00)
#define  AE_ae_bist_0_rmea_ade_mask                                              (0x00000010)
#define  AE_ae_bist_0_rma_ade_mask                                               (0x0000000F)
#define  AE_ae_bist_0_rmeb_aee(data)                                             (0x10000000&((data)<<28))
#define  AE_ae_bist_0_rmb_aee(data)                                              (0x0F000000&((data)<<24))
#define  AE_ae_bist_0_rmea_aee(data)                                             (0x00100000&((data)<<20))
#define  AE_ae_bist_0_rma_aee(data)                                              (0x000F0000&((data)<<16))
#define  AE_ae_bist_0_rmeb_ade(data)                                             (0x00001000&((data)<<12))
#define  AE_ae_bist_0_rmb_ade(data)                                              (0x00000F00&((data)<<8))
#define  AE_ae_bist_0_rmea_ade(data)                                             (0x00000010&((data)<<4))
#define  AE_ae_bist_0_rma_ade(data)                                              (0x0000000F&(data))
#define  AE_ae_bist_0_get_rmeb_aee(data)                                         ((0x10000000&(data))>>28)
#define  AE_ae_bist_0_get_rmb_aee(data)                                          ((0x0F000000&(data))>>24)
#define  AE_ae_bist_0_get_rmea_aee(data)                                         ((0x00100000&(data))>>20)
#define  AE_ae_bist_0_get_rma_aee(data)                                          ((0x000F0000&(data))>>16)
#define  AE_ae_bist_0_get_rmeb_ade(data)                                         ((0x00001000&(data))>>12)
#define  AE_ae_bist_0_get_rmb_ade(data)                                          ((0x00000F00&(data))>>8)
#define  AE_ae_bist_0_get_rmea_ade(data)                                         ((0x00000010&(data))>>4)
#define  AE_ae_bist_0_get_rma_ade(data)                                          (0x0000000F&(data))

#define  AE_ae_bist_2                                                            0x1800226C
#define  AE_ae_bist_2_reg_addr                                                   "0xB800226C"
#define  AE_ae_bist_2_reg                                                        0xB800226C
#define  AE_ae_bist_2_inst_addr                                                  "0x005B"
#define  set_AE_ae_bist_2_reg(data)                                              (*((volatile unsigned int*)AE_ae_bist_2_reg)=data)
#define  get_AE_ae_bist_2_reg                                                    (*((volatile unsigned int*)AE_ae_bist_2_reg))
#define  AE_ae_bist_2_mode_aee_shift                                             (1)
#define  AE_ae_bist_2_mode_ade_shift                                             (0)
#define  AE_ae_bist_2_mode_aee_mask                                              (0x00000002)
#define  AE_ae_bist_2_mode_ade_mask                                              (0x00000001)
#define  AE_ae_bist_2_mode_aee(data)                                             (0x00000002&((data)<<1))
#define  AE_ae_bist_2_mode_ade(data)                                             (0x00000001&(data))
#define  AE_ae_bist_2_get_mode_aee(data)                                         ((0x00000002&(data))>>1)
#define  AE_ae_bist_2_get_mode_ade(data)                                         (0x00000001&(data))

#define  AE_ae_bist_3                                                            0x18002270
#define  AE_ae_bist_3_reg_addr                                                   "0xB8002270"
#define  AE_ae_bist_3_reg                                                        0xB8002270
#define  AE_ae_bist_3_inst_addr                                                  "0x005C"
#define  set_AE_ae_bist_3_reg(data)                                              (*((volatile unsigned int*)AE_ae_bist_3_reg)=data)
#define  get_AE_ae_bist_3_reg                                                    (*((volatile unsigned int*)AE_ae_bist_3_reg))
#define  AE_ae_bist_3_done_aee_shift                                             (1)
#define  AE_ae_bist_3_done_ade_shift                                             (0)
#define  AE_ae_bist_3_done_aee_mask                                              (0x00000002)
#define  AE_ae_bist_3_done_ade_mask                                              (0x00000001)
#define  AE_ae_bist_3_done_aee(data)                                             (0x00000002&((data)<<1))
#define  AE_ae_bist_3_done_ade(data)                                             (0x00000001&(data))
#define  AE_ae_bist_3_get_done_aee(data)                                         ((0x00000002&(data))>>1)
#define  AE_ae_bist_3_get_done_ade(data)                                         (0x00000001&(data))

#define  AE_ae_bist_4                                                            0x18002274
#define  AE_ae_bist_4_reg_addr                                                   "0xB8002274"
#define  AE_ae_bist_4_reg                                                        0xB8002274
#define  AE_ae_bist_4_inst_addr                                                  "0x005D"
#define  set_AE_ae_bist_4_reg(data)                                              (*((volatile unsigned int*)AE_ae_bist_4_reg)=data)
#define  get_AE_ae_bist_4_reg                                                    (*((volatile unsigned int*)AE_ae_bist_4_reg))
#define  AE_ae_bist_4_fail_aee_shift                                             (1)
#define  AE_ae_bist_4_fail_ade_shift                                             (0)
#define  AE_ae_bist_4_fail_aee_mask                                              (0x00000002)
#define  AE_ae_bist_4_fail_ade_mask                                              (0x00000001)
#define  AE_ae_bist_4_fail_aee(data)                                             (0x00000002&((data)<<1))
#define  AE_ae_bist_4_fail_ade(data)                                             (0x00000001&(data))
#define  AE_ae_bist_4_get_fail_aee(data)                                         ((0x00000002&(data))>>1)
#define  AE_ae_bist_4_get_fail_ade(data)                                         (0x00000001&(data))

#define  AE_ae_drf_0                                                             0x18002278
#define  AE_ae_drf_0_reg_addr                                                    "0xB8002278"
#define  AE_ae_drf_0_reg                                                         0xB8002278
#define  AE_ae_drf_0_inst_addr                                                   "0x005E"
#define  set_AE_ae_drf_0_reg(data)                                               (*((volatile unsigned int*)AE_ae_drf_0_reg)=data)
#define  get_AE_ae_drf_0_reg                                                     (*((volatile unsigned int*)AE_ae_drf_0_reg))
#define  AE_ae_drf_0_mode_aee_shift                                              (1)
#define  AE_ae_drf_0_mode_ade_shift                                              (0)
#define  AE_ae_drf_0_mode_aee_mask                                               (0x00000002)
#define  AE_ae_drf_0_mode_ade_mask                                               (0x00000001)
#define  AE_ae_drf_0_mode_aee(data)                                              (0x00000002&((data)<<1))
#define  AE_ae_drf_0_mode_ade(data)                                              (0x00000001&(data))
#define  AE_ae_drf_0_get_mode_aee(data)                                          ((0x00000002&(data))>>1)
#define  AE_ae_drf_0_get_mode_ade(data)                                          (0x00000001&(data))

#define  AE_ae_drf_1                                                             0x1800227C
#define  AE_ae_drf_1_reg_addr                                                    "0xB800227C"
#define  AE_ae_drf_1_reg                                                         0xB800227C
#define  AE_ae_drf_1_inst_addr                                                   "0x005F"
#define  set_AE_ae_drf_1_reg(data)                                               (*((volatile unsigned int*)AE_ae_drf_1_reg)=data)
#define  get_AE_ae_drf_1_reg                                                     (*((volatile unsigned int*)AE_ae_drf_1_reg))
#define  AE_ae_drf_1_done_aee_shift                                              (1)
#define  AE_ae_drf_1_done_ade_shift                                              (0)
#define  AE_ae_drf_1_done_aee_mask                                               (0x00000002)
#define  AE_ae_drf_1_done_ade_mask                                               (0x00000001)
#define  AE_ae_drf_1_done_aee(data)                                              (0x00000002&((data)<<1))
#define  AE_ae_drf_1_done_ade(data)                                              (0x00000001&(data))
#define  AE_ae_drf_1_get_done_aee(data)                                          ((0x00000002&(data))>>1)
#define  AE_ae_drf_1_get_done_ade(data)                                          (0x00000001&(data))

#define  AE_ae_drf_2                                                             0x18002280
#define  AE_ae_drf_2_reg_addr                                                    "0xB8002280"
#define  AE_ae_drf_2_reg                                                         0xB8002280
#define  AE_ae_drf_2_inst_addr                                                   "0x0060"
#define  set_AE_ae_drf_2_reg(data)                                               (*((volatile unsigned int*)AE_ae_drf_2_reg)=data)
#define  get_AE_ae_drf_2_reg                                                     (*((volatile unsigned int*)AE_ae_drf_2_reg))
#define  AE_ae_drf_2_fail_aee_shift                                              (1)
#define  AE_ae_drf_2_fail_ade_shift                                              (0)
#define  AE_ae_drf_2_fail_aee_mask                                               (0x00000002)
#define  AE_ae_drf_2_fail_ade_mask                                               (0x00000001)
#define  AE_ae_drf_2_fail_aee(data)                                              (0x00000002&((data)<<1))
#define  AE_ae_drf_2_fail_ade(data)                                              (0x00000001&(data))
#define  AE_ae_drf_2_get_fail_aee(data)                                          ((0x00000002&(data))>>1)
#define  AE_ae_drf_2_get_fail_ade(data)                                          (0x00000001&(data))

#define  AE_ae_drf_3                                                             0x18002284
#define  AE_ae_drf_3_reg_addr                                                    "0xB8002284"
#define  AE_ae_drf_3_reg                                                         0xB8002284
#define  AE_ae_drf_3_inst_addr                                                   "0x0061"
#define  set_AE_ae_drf_3_reg(data)                                               (*((volatile unsigned int*)AE_ae_drf_3_reg)=data)
#define  get_AE_ae_drf_3_reg                                                     (*((volatile unsigned int*)AE_ae_drf_3_reg))
#define  AE_ae_drf_3_pause_aee_shift                                             (1)
#define  AE_ae_drf_3_pause_ade_shift                                             (0)
#define  AE_ae_drf_3_pause_aee_mask                                              (0x00000002)
#define  AE_ae_drf_3_pause_ade_mask                                              (0x00000001)
#define  AE_ae_drf_3_pause_aee(data)                                             (0x00000002&((data)<<1))
#define  AE_ae_drf_3_pause_ade(data)                                             (0x00000001&(data))
#define  AE_ae_drf_3_get_pause_aee(data)                                         ((0x00000002&(data))>>1)
#define  AE_ae_drf_3_get_pause_ade(data)                                         (0x00000001&(data))

#define  AE_ae_drf_4                                                             0x18002288
#define  AE_ae_drf_4_reg_addr                                                    "0xB8002288"
#define  AE_ae_drf_4_reg                                                         0xB8002288
#define  AE_ae_drf_4_inst_addr                                                   "0x0062"
#define  set_AE_ae_drf_4_reg(data)                                               (*((volatile unsigned int*)AE_ae_drf_4_reg)=data)
#define  get_AE_ae_drf_4_reg                                                     (*((volatile unsigned int*)AE_ae_drf_4_reg))
#define  AE_ae_drf_4_resume_aee_shift                                            (1)
#define  AE_ae_drf_4_resume_ade_shift                                            (0)
#define  AE_ae_drf_4_resume_aee_mask                                             (0x00000002)
#define  AE_ae_drf_4_resume_ade_mask                                             (0x00000001)
#define  AE_ae_drf_4_resume_aee(data)                                            (0x00000002&((data)<<1))
#define  AE_ae_drf_4_resume_ade(data)                                            (0x00000001&(data))
#define  AE_ae_drf_4_get_resume_aee(data)                                        ((0x00000002&(data))>>1)
#define  AE_ae_drf_4_get_resume_ade(data)                                        (0x00000001&(data))

#define  AE_ae_bist                                                              0x1800228C
#define  AE_ae_bist_reg_addr                                                     "0xB800228C"
#define  AE_ae_bist_reg                                                          0xB800228C
#define  AE_ae_bist_inst_addr                                                    "0x0063"
#define  set_AE_ae_bist_reg(data)                                                (*((volatile unsigned int*)AE_ae_bist_reg)=data)
#define  get_AE_ae_bist_reg                                                      (*((volatile unsigned int*)AE_ae_bist_reg))
#define  AE_ae_bist_ls_aee_shift                                                 (1)
#define  AE_ae_bist_ls_ade_shift                                                 (0)
#define  AE_ae_bist_ls_aee_mask                                                  (0x00000002)
#define  AE_ae_bist_ls_ade_mask                                                  (0x00000001)
#define  AE_ae_bist_ls_aee(data)                                                 (0x00000002&((data)<<1))
#define  AE_ae_bist_ls_ade(data)                                                 (0x00000001&(data))
#define  AE_ae_bist_get_ls_aee(data)                                             ((0x00000002&(data))>>1)
#define  AE_ae_bist_get_ls_ade(data)                                             (0x00000001&(data))

#define  AE_aee_sf                                                               0x18002290
#define  AE_aee_sf_reg_addr                                                      "0xB8002290"
#define  AE_aee_sf_reg                                                           0xB8002290
#define  AE_aee_sf_inst_addr                                                     "0x0064"
#define  set_AE_aee_sf_reg(data)                                                 (*((volatile unsigned int*)AE_aee_sf_reg)=data)
#define  get_AE_aee_sf_reg                                                       (*((volatile unsigned int*)AE_aee_sf_reg))
#define  AE_aee_sf_tx_mode_shift                                                 (13)
#define  AE_aee_sf_tx_start_shift                                                (12)
#define  AE_aee_sf_tx_work_shift                                                 (8)
#define  AE_aee_sf_rx_gated_shift                                                (6)
#define  AE_aee_sf_rx_mode_shift                                                 (5)
#define  AE_aee_sf_rx_start_shift                                                (4)
#define  AE_aee_sf_rx_done_shift                                                 (1)
#define  AE_aee_sf_rx_err_shift                                                  (0)
#define  AE_aee_sf_tx_mode_mask                                                  (0x00002000)
#define  AE_aee_sf_tx_start_mask                                                 (0x00001000)
#define  AE_aee_sf_tx_work_mask                                                  (0x00000100)
#define  AE_aee_sf_rx_gated_mask                                                 (0x00000040)
#define  AE_aee_sf_rx_mode_mask                                                  (0x00000020)
#define  AE_aee_sf_rx_start_mask                                                 (0x00000010)
#define  AE_aee_sf_rx_done_mask                                                  (0x00000002)
#define  AE_aee_sf_rx_err_mask                                                   (0x00000001)
#define  AE_aee_sf_tx_mode(data)                                                 (0x00002000&((data)<<13))
#define  AE_aee_sf_tx_start(data)                                                (0x00001000&((data)<<12))
#define  AE_aee_sf_tx_work(data)                                                 (0x00000100&((data)<<8))
#define  AE_aee_sf_rx_gated(data)                                                (0x00000040&((data)<<6))
#define  AE_aee_sf_rx_mode(data)                                                 (0x00000020&((data)<<5))
#define  AE_aee_sf_rx_start(data)                                                (0x00000010&((data)<<4))
#define  AE_aee_sf_rx_done(data)                                                 (0x00000002&((data)<<1))
#define  AE_aee_sf_rx_err(data)                                                  (0x00000001&(data))
#define  AE_aee_sf_get_tx_mode(data)                                             ((0x00002000&(data))>>13)
#define  AE_aee_sf_get_tx_start(data)                                            ((0x00001000&(data))>>12)
#define  AE_aee_sf_get_tx_work(data)                                             ((0x00000100&(data))>>8)
#define  AE_aee_sf_get_rx_gated(data)                                            ((0x00000040&(data))>>6)
#define  AE_aee_sf_get_rx_mode(data)                                             ((0x00000020&(data))>>5)
#define  AE_aee_sf_get_rx_start(data)                                            ((0x00000010&(data))>>4)
#define  AE_aee_sf_get_rx_done(data)                                             ((0x00000002&(data))>>1)
#define  AE_aee_sf_get_rx_err(data)                                              (0x00000001&(data))

#define  AE_ade_sf                                                               0x18002294
#define  AE_ade_sf_reg_addr                                                      "0xB8002294"
#define  AE_ade_sf_reg                                                           0xB8002294
#define  AE_ade_sf_inst_addr                                                     "0x0065"
#define  set_AE_ade_sf_reg(data)                                                 (*((volatile unsigned int*)AE_ade_sf_reg)=data)
#define  get_AE_ade_sf_reg                                                       (*((volatile unsigned int*)AE_ade_sf_reg))
#define  AE_ade_sf_tx_mode_shift                                                 (13)
#define  AE_ade_sf_tx_start_shift                                                (12)
#define  AE_ade_sf_tx_work_shift                                                 (8)
#define  AE_ade_sf_rx_gated_shift                                                (6)
#define  AE_ade_sf_rx_mode_shift                                                 (5)
#define  AE_ade_sf_rx_start_shift                                                (4)
#define  AE_ade_sf_rx_done_shift                                                 (1)
#define  AE_ade_sf_rx_err_shift                                                  (0)
#define  AE_ade_sf_tx_mode_mask                                                  (0x00002000)
#define  AE_ade_sf_tx_start_mask                                                 (0x00001000)
#define  AE_ade_sf_tx_work_mask                                                  (0x00000100)
#define  AE_ade_sf_rx_gated_mask                                                 (0x00000040)
#define  AE_ade_sf_rx_mode_mask                                                  (0x00000020)
#define  AE_ade_sf_rx_start_mask                                                 (0x00000010)
#define  AE_ade_sf_rx_done_mask                                                  (0x00000002)
#define  AE_ade_sf_rx_err_mask                                                   (0x00000001)
#define  AE_ade_sf_tx_mode(data)                                                 (0x00002000&((data)<<13))
#define  AE_ade_sf_tx_start(data)                                                (0x00001000&((data)<<12))
#define  AE_ade_sf_tx_work(data)                                                 (0x00000100&((data)<<8))
#define  AE_ade_sf_rx_gated(data)                                                (0x00000040&((data)<<6))
#define  AE_ade_sf_rx_mode(data)                                                 (0x00000020&((data)<<5))
#define  AE_ade_sf_rx_start(data)                                                (0x00000010&((data)<<4))
#define  AE_ade_sf_rx_done(data)                                                 (0x00000002&((data)<<1))
#define  AE_ade_sf_rx_err(data)                                                  (0x00000001&(data))
#define  AE_ade_sf_get_tx_mode(data)                                             ((0x00002000&(data))>>13)
#define  AE_ade_sf_get_tx_start(data)                                            ((0x00001000&(data))>>12)
#define  AE_ade_sf_get_tx_work(data)                                             ((0x00000100&(data))>>8)
#define  AE_ade_sf_get_rx_gated(data)                                            ((0x00000040&(data))>>6)
#define  AE_ade_sf_get_rx_mode(data)                                             ((0x00000020&(data))>>5)
#define  AE_ade_sf_get_rx_start(data)                                            ((0x00000010&(data))>>4)
#define  AE_ade_sf_get_rx_done(data)                                             ((0x00000002&(data))>>1)
#define  AE_ade_sf_get_rx_err(data)                                              (0x00000001&(data))

#define  AE_wrapper_cfg1                                                         0x18002400
#define  AE_wrapper_cfg1_reg_addr                                                "0xB8002400"
#define  AE_wrapper_cfg1_reg                                                     0xB8002400
#define  AE_wrapper_cfg1_inst_addr                                               "0x0066"
#define  set_AE_wrapper_cfg1_reg(data)                                           (*((volatile unsigned int*)AE_wrapper_cfg1_reg)=data)
#define  get_AE_wrapper_cfg1_reg                                                 (*((volatile unsigned int*)AE_wrapper_cfg1_reg))
#define  AE_wrapper_cfg1_wlast_sel_shift                                         (31)
#define  AE_wrapper_cfg1_wr_outstand_num_shift                                   (4)
#define  AE_wrapper_cfg1_rd_outstand_num_shift                                   (0)
#define  AE_wrapper_cfg1_wlast_sel_mask                                          (0x80000000)
#define  AE_wrapper_cfg1_wr_outstand_num_mask                                    (0x00000070)
#define  AE_wrapper_cfg1_rd_outstand_num_mask                                    (0x00000007)
#define  AE_wrapper_cfg1_wlast_sel(data)                                         (0x80000000&((data)<<31))
#define  AE_wrapper_cfg1_wr_outstand_num(data)                                   (0x00000070&((data)<<4))
#define  AE_wrapper_cfg1_rd_outstand_num(data)                                   (0x00000007&(data))
#define  AE_wrapper_cfg1_get_wlast_sel(data)                                     ((0x80000000&(data))>>31)
#define  AE_wrapper_cfg1_get_wr_outstand_num(data)                               ((0x00000070&(data))>>4)
#define  AE_wrapper_cfg1_get_rd_outstand_num(data)                               (0x00000007&(data))

#define  AE_ocpdbg_ctrl                                                          0x18002404
#define  AE_ocpdbg_ctrl_reg_addr                                                 "0xB8002404"
#define  AE_ocpdbg_ctrl_reg                                                      0xB8002404
#define  AE_ocpdbg_ctrl_inst_addr                                                "0x0067"
#define  set_AE_ocpdbg_ctrl_reg(data)                                            (*((volatile unsigned int*)AE_ocpdbg_ctrl_reg)=data)
#define  get_AE_ocpdbg_ctrl_reg                                                  (*((volatile unsigned int*)AE_ocpdbg_ctrl_reg))
#define  AE_ocpdbg_ctrl_stop_dbg_ocp_shift                                       (1)
#define  AE_ocpdbg_ctrl_fetch_dbg_entry_ocp_shift                                (0)
#define  AE_ocpdbg_ctrl_stop_dbg_ocp_mask                                        (0x00000002)
#define  AE_ocpdbg_ctrl_fetch_dbg_entry_ocp_mask                                 (0x00000001)
#define  AE_ocpdbg_ctrl_stop_dbg_ocp(data)                                       (0x00000002&((data)<<1))
#define  AE_ocpdbg_ctrl_fetch_dbg_entry_ocp(data)                                (0x00000001&(data))
#define  AE_ocpdbg_ctrl_get_stop_dbg_ocp(data)                                   ((0x00000002&(data))>>1)
#define  AE_ocpdbg_ctrl_get_fetch_dbg_entry_ocp(data)                            (0x00000001&(data))

#define  AE_ocpdbg_status1                                                       0x18002408
#define  AE_ocpdbg_status1_reg_addr                                              "0xB8002408"
#define  AE_ocpdbg_status1_reg                                                   0xB8002408
#define  AE_ocpdbg_status1_inst_addr                                             "0x0068"
#define  set_AE_ocpdbg_status1_reg(data)                                         (*((volatile unsigned int*)AE_ocpdbg_status1_reg)=data)
#define  get_AE_ocpdbg_status1_reg                                               (*((volatile unsigned int*)AE_ocpdbg_status1_reg))
#define  AE_ocpdbg_status1_valid_entry_cnt_ocp_shift                             (0)
#define  AE_ocpdbg_status1_valid_entry_cnt_ocp_mask                              (0x0000001F)
#define  AE_ocpdbg_status1_valid_entry_cnt_ocp(data)                             (0x0000001F&(data))
#define  AE_ocpdbg_status1_get_valid_entry_cnt_ocp(data)                         (0x0000001F&(data))

#define  AE_ocpdbg_status2                                                       0x1800240C
#define  AE_ocpdbg_status2_reg_addr                                              "0xB800240C"
#define  AE_ocpdbg_status2_reg                                                   0xB800240C
#define  AE_ocpdbg_status2_inst_addr                                             "0x0069"
#define  set_AE_ocpdbg_status2_reg(data)                                         (*((volatile unsigned int*)AE_ocpdbg_status2_reg)=data)
#define  get_AE_ocpdbg_status2_reg                                               (*((volatile unsigned int*)AE_ocpdbg_status2_reg))
#define  AE_ocpdbg_status2_ocpdbg_addr_shift                                     (0)
#define  AE_ocpdbg_status2_ocpdbg_addr_mask                                      (0xFFFFFFFF)
#define  AE_ocpdbg_status2_ocpdbg_addr(data)                                     (0xFFFFFFFF&(data))
#define  AE_ocpdbg_status2_get_ocpdbg_addr(data)                                 (0xFFFFFFFF&(data))

#define  AE_ocpdbg_status3                                                       0x18002500
#define  AE_ocpdbg_status3_reg_addr                                              "0xB8002500"
#define  AE_ocpdbg_status3_reg                                                   0xB8002500
#define  AE_ocpdbg_status3_inst_addr                                             "0x006A"
#define  set_AE_ocpdbg_status3_reg(data)                                         (*((volatile unsigned int*)AE_ocpdbg_status3_reg)=data)
#define  get_AE_ocpdbg_status3_reg                                               (*((volatile unsigned int*)AE_ocpdbg_status3_reg))
#define  AE_ocpdbg_status3_ocpdbg_write_shift                                    (12)
#define  AE_ocpdbg_status3_ocpdbg_byte_en_shift                                  (4)
#define  AE_ocpdbg_status3_ocpdbg_tag_id_shift                                   (0)
#define  AE_ocpdbg_status3_ocpdbg_write_mask                                     (0x00001000)
#define  AE_ocpdbg_status3_ocpdbg_byte_en_mask                                   (0x00000FF0)
#define  AE_ocpdbg_status3_ocpdbg_tag_id_mask                                    (0x0000000F)
#define  AE_ocpdbg_status3_ocpdbg_write(data)                                    (0x00001000&((data)<<12))
#define  AE_ocpdbg_status3_ocpdbg_byte_en(data)                                  (0x00000FF0&((data)<<4))
#define  AE_ocpdbg_status3_ocpdbg_tag_id(data)                                   (0x0000000F&(data))
#define  AE_ocpdbg_status3_get_ocpdbg_write(data)                                ((0x00001000&(data))>>12)
#define  AE_ocpdbg_status3_get_ocpdbg_byte_en(data)                              ((0x00000FF0&(data))>>4)
#define  AE_ocpdbg_status3_get_ocpdbg_tag_id(data)                               (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======AE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  src:31;
    };
}ae_adsp_ade_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dst:31;
    };
}ae_adsp_ade_dst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  valid:1;
        RBus_UInt32  dir:1;
        RBus_UInt32  size:14;
    };
}ae_adsp_ade_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  done_7:1;
        RBus_UInt32  done_6:1;
        RBus_UInt32  done_5:1;
        RBus_UInt32  done_4:1;
        RBus_UInt32  done_3:1;
        RBus_UInt32  done_2:1;
        RBus_UInt32  done_1:1;
        RBus_UInt32  done_0:1;
    };
}ae_adsp_ade_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  max_xfer:6;
        RBus_UInt32  res2:5;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  dmem_req_en:1;
        RBus_UInt32  write_en4:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_en5:1;
        RBus_UInt32  go:1;
    };
}ae_adsp_ade_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  int_done:1;
    };
}ae_adsp_ade_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  int_done_en:1;
    };
}ae_adsp_ade_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cnt:8;
    };
}ae_adsp_ade_timer_msb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}ae_adsp_ade_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  max_xfer:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  threshold:6;
        RBus_UInt32  res3:3;
    };
}ae_adsp_aee_thld_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  bit_cnt:14;
    };
}ae_adsp_aee_vbit_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  used_cnt:32;
    };
}ae_adsp_aee_used_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  dir:1;
        RBus_UInt32  go:1;
    };
}ae_adsp_aee_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  int4:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  write_data:1;
    };
}ae_adsp_aee_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  int4_en:1;
        RBus_UInt32  int3_en:1;
        RBus_UInt32  int2_en:1;
        RBus_UInt32  int1_en:1;
        RBus_UInt32  write_data:1;
    };
}ae_adsp_aee_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ring_limit:28;
        RBus_UInt32  res2:3;
    };
}ae_adsp_aee_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ring_base:28;
        RBus_UInt32  res2:3;
    };
}ae_adsp_aee_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ring_rp:31;
    };
}ae_adsp_aee_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ring_wp:31;
    };
}ae_adsp_aee_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ring_cp:31;
    };
}ae_adsp_aee_ring_cp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  limit:16;
    };
}ae_adsp_aee_search_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_init:16;
    };
}ae_adsp_aee_crc_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_en4:1;
        RBus_UInt32  crc_mode:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  crc_reset:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  crc_cont:1;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  crc_on:1;
    };
}ae_adsp_aee_crc_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_length:16;
    };
}ae_adsp_aee_crc_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_result:16;
    };
}ae_adsp_aee_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_bit_cnt:32;
    };
}ae_adsp_aee_bit_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  acc:16;
    };
}ae_adsp_aee_crc_acc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  acc_cnt:4;
    };
}ae_adsp_aee_crc_acc_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  aee_audio_mode:2;
    };
}ae_aee_ogg_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ae_dbg_en:1;
        RBus_UInt32  ae_dbg_sel1:6;
        RBus_UInt32  ae_dbg_sel0:6;
    };
}ae_ae_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18002154_31_0:32;
    };
}ae_ae_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  rst:1;
    };
}ae_ae_src_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sleep_mode_status:1;
    };
}ae_acpu_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ls_acpu:1;
        RBus_UInt32  rme_acpu:1;
        RBus_UInt32  res2:24;
    };
}ae_mbist_acpu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rm_dcache_tag:4;
        RBus_UInt32  rm_icache_lru:4;
        RBus_UInt32  rm_icache_tag:4;
        RBus_UInt32  rm_btb_data:4;
        RBus_UInt32  rm_btb_tag:4;
        RBus_UInt32  rm_pht:4;
    };
}ae_mbist_acpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rm_icache_data:4;
        RBus_UInt32  rm_dcache_data:4;
        RBus_UInt32  rm_dmem0:4;
        RBus_UInt32  rm_dmem1:4;
        RBus_UInt32  rm_imem:4;
        RBus_UInt32  res2:4;
    };
}ae_mbisr_acpu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  acpu_bist_mode:1;
    };
}ae_mbist_acpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  acpu_bist_done:1;
    };
}ae_mbist_acpu_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  acpu_bist_fail_group:1;
    };
}ae_mbist_acpu_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  bist_fail5:1;
        RBus_UInt32  bist_fail4:1;
        RBus_UInt32  bist_fail3:1;
        RBus_UInt32  bist_fail2:1;
        RBus_UInt32  bist_fail1:1;
        RBus_UInt32  bist_fail0:1;
    };
}ae_mbist_acpu_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_mode:1;
    };
}ae_mbist_acpu_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resume:1;
    };
}ae_mbist_acpu_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_done:1;
    };
}ae_mbist_acpu_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pause:1;
    };
}ae_mbist_acpu_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_fail_group:1;
    };
}ae_mbist_acpu_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  drf_fail5:1;
        RBus_UInt32  drf_fail4:1;
        RBus_UInt32  drf_fail3:1;
        RBus_UInt32  drf_fail2:1;
        RBus_UInt32  drf_fail1:1;
        RBus_UInt32  drf_fail0:1;
    };
}ae_mbist_acpu_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bisr3_second_run_en:1;
        RBus_UInt32  bisr2_second_run_en:1;
        RBus_UInt32  bisr1_second_run_en:1;
        RBus_UInt32  bisr0_second_run_en:1;
    };
}ae_mbisr_acpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bisr3_fail_group:1;
        RBus_UInt32  bisr2_fail_group:1;
        RBus_UInt32  bisr1_fail_group:1;
        RBus_UInt32  bisr0_fail_group:1;
    };
}ae_mbisr_acpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  bisr3_fail_0:1;
        RBus_UInt32  bisr2_fail_1:1;
        RBus_UInt32  bisr2_fail_0:1;
        RBus_UInt32  bisr1_fail_0:1;
        RBus_UInt32  bisr0_fail_0:1;
    };
}ae_mbisr_acpu_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bisr3_drf_mode:1;
        RBus_UInt32  bisr2_drf_mode:1;
        RBus_UInt32  bisr1_drf_mode:1;
        RBus_UInt32  bisr0_drf_mode:1;
    };
}ae_mbisr_acpu_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  drf_3_resume:1;
        RBus_UInt32  drf_2_resume:1;
        RBus_UInt32  drf_1_resume:1;
        RBus_UInt32  drf_0_resume:1;
    };
}ae_mbisr_acpu_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bisr3_drf_done:1;
        RBus_UInt32  bisr2_drf_done:1;
        RBus_UInt32  bisr1_drf_done:1;
        RBus_UInt32  bisr0_drf_done:1;
    };
}ae_mbisr_acpu_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  bisr3_drf_fail_group:1;
        RBus_UInt32  bisr2_drf_fail_group:1;
        RBus_UInt32  bisr1_drf_fail_group:1;
        RBus_UInt32  bisr0_drf_fail_group:1;
    };
}ae_mbisr_acpu_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  drf_3_pause:1;
        RBus_UInt32  drf_2_pause:1;
        RBus_UInt32  drf_1_pause:1;
        RBus_UInt32  drf_0_pause:1;
    };
}ae_mbisr_acpu_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_3_repaired:1;
        RBus_UInt32  drf_2_repaired:1;
        RBus_UInt32  drf_1_repaired:1;
        RBus_UInt32  drf_0_repaired:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  drf_3_fail_0:1;
        RBus_UInt32  drf_2_fail_1:1;
        RBus_UInt32  drf_2_fail_0:1;
        RBus_UInt32  drf_1_fail_0:1;
        RBus_UInt32  drf_0_fail_0:1;
    };
}ae_mbisr_acpu_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  rmeb_aee:1;
        RBus_UInt32  rmb_aee:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  rmea_aee:1;
        RBus_UInt32  rma_aee:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  rmeb_ade:1;
        RBus_UInt32  rmb_ade:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  rmea_ade:1;
        RBus_UInt32  rma_ade:4;
    };
}ae_ae_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mode_aee:1;
        RBus_UInt32  mode_ade:1;
    };
}ae_ae_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  done_aee:1;
        RBus_UInt32  done_ade:1;
    };
}ae_ae_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  fail_aee:1;
        RBus_UInt32  fail_ade:1;
    };
}ae_ae_bist_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mode_aee:1;
        RBus_UInt32  mode_ade:1;
    };
}ae_ae_drf_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  done_aee:1;
        RBus_UInt32  done_ade:1;
    };
}ae_ae_drf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  fail_aee:1;
        RBus_UInt32  fail_ade:1;
    };
}ae_ae_drf_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  pause_aee:1;
        RBus_UInt32  pause_ade:1;
    };
}ae_ae_drf_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  resume_aee:1;
        RBus_UInt32  resume_ade:1;
    };
}ae_ae_drf_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ls_aee:1;
        RBus_UInt32  ls_ade:1;
    };
}ae_ae_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  tx_mode:1;
        RBus_UInt32  tx_start:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tx_work:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rx_gated:1;
        RBus_UInt32  rx_mode:1;
        RBus_UInt32  rx_start:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  rx_done:1;
        RBus_UInt32  rx_err:1;
    };
}ae_aee_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  tx_mode:1;
        RBus_UInt32  tx_start:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tx_work:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rx_gated:1;
        RBus_UInt32  rx_mode:1;
        RBus_UInt32  rx_start:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  rx_done:1;
        RBus_UInt32  rx_err:1;
    };
}ae_ade_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wlast_sel:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  wr_outstand_num:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  rd_outstand_num:3;
    };
}ae_wrapper_cfg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  stop_dbg_ocp:1;
        RBus_UInt32  fetch_dbg_entry_ocp:1;
    };
}ae_ocpdbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  valid_entry_cnt_ocp:5;
    };
}ae_ocpdbg_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ocpdbg_addr:32;
    };
}ae_ocpdbg_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ocpdbg_write:1;
        RBus_UInt32  ocpdbg_byte_en:8;
        RBus_UInt32  ocpdbg_tag_id:4;
    };
}ae_ocpdbg_status3_RBUS;

#else //apply LITTLE_ENDIAN

//======AE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src:31;
        RBus_UInt32  res1:1;
    };
}ae_adsp_ade_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dst:31;
        RBus_UInt32  res1:1;
    };
}ae_adsp_ade_dst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  size:14;
        RBus_UInt32  dir:1;
        RBus_UInt32  valid:1;
        RBus_UInt32  res1:16;
    };
}ae_adsp_ade_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done_0:1;
        RBus_UInt32  done_1:1;
        RBus_UInt32  done_2:1;
        RBus_UInt32  done_3:1;
        RBus_UInt32  done_4:1;
        RBus_UInt32  done_5:1;
        RBus_UInt32  done_6:1;
        RBus_UInt32  done_7:1;
        RBus_UInt32  res1:24;
    };
}ae_adsp_ade_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  go:1;
        RBus_UInt32  write_en5:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_en4:1;
        RBus_UInt32  dmem_req_en:1;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  max_xfer:6;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  res2:14;
    };
}ae_adsp_ade_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_done:1;
        RBus_UInt32  res1:31;
    };
}ae_adsp_ade_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_done_en:1;
        RBus_UInt32  res1:31;
    };
}ae_adsp_ade_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:8;
        RBus_UInt32  res1:24;
    };
}ae_adsp_ade_timer_msb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}ae_adsp_ade_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  threshold:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  max_xfer:6;
        RBus_UInt32  res3:13;
    };
}ae_adsp_aee_thld_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_cnt:14;
        RBus_UInt32  res1:18;
    };
}ae_adsp_aee_vbit_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  used_cnt:32;
    };
}ae_adsp_aee_used_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  go:1;
        RBus_UInt32  dir:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  res1:27;
    };
}ae_adsp_aee_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int1:1;
        RBus_UInt32  int2:1;
        RBus_UInt32  int3:1;
        RBus_UInt32  int4:1;
        RBus_UInt32  res1:27;
    };
}ae_adsp_aee_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int1_en:1;
        RBus_UInt32  int2_en:1;
        RBus_UInt32  int3_en:1;
        RBus_UInt32  int4_en:1;
        RBus_UInt32  res1:27;
    };
}ae_adsp_aee_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:28;
        RBus_UInt32  res2:1;
    };
}ae_adsp_aee_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:28;
        RBus_UInt32  res2:1;
    };
}ae_adsp_aee_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:31;
        RBus_UInt32  res1:1;
    };
}ae_adsp_aee_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:31;
        RBus_UInt32  res1:1;
    };
}ae_adsp_aee_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_cp:31;
        RBus_UInt32  res1:1;
    };
}ae_adsp_aee_ring_cp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit:16;
        RBus_UInt32  res1:16;
    };
}ae_adsp_aee_search_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_init:16;
        RBus_UInt32  res1:16;
    };
}ae_adsp_aee_crc_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_on:1;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  crc_cont:1;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  crc_reset:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  crc_mode:1;
        RBus_UInt32  write_en4:1;
        RBus_UInt32  res1:24;
    };
}ae_adsp_aee_crc_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_length:16;
        RBus_UInt32  res1:16;
    };
}ae_adsp_aee_crc_length_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:16;
        RBus_UInt32  res1:16;
    };
}ae_adsp_aee_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_bit_cnt:32;
    };
}ae_adsp_aee_bit_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc:16;
        RBus_UInt32  res1:16;
    };
}ae_adsp_aee_crc_acc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acc_cnt:4;
        RBus_UInt32  res1:28;
    };
}ae_adsp_aee_crc_acc_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aee_audio_mode:2;
        RBus_UInt32  res1:30;
    };
}ae_aee_ogg_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ae_dbg_sel0:6;
        RBus_UInt32  ae_dbg_sel1:6;
        RBus_UInt32  ae_dbg_en:1;
        RBus_UInt32  res1:19;
    };
}ae_ae_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18002154_31_0:32;
    };
}ae_ae_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst:1;
        RBus_UInt32  res1:31;
    };
}ae_ae_src_rst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sleep_mode_status:1;
        RBus_UInt32  res1:31;
    };
}ae_acpu_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rme_acpu:1;
        RBus_UInt32  ls_acpu:1;
        RBus_UInt32  res2:6;
    };
}ae_mbist_acpu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_pht:4;
        RBus_UInt32  rm_btb_tag:4;
        RBus_UInt32  rm_btb_data:4;
        RBus_UInt32  rm_icache_tag:4;
        RBus_UInt32  rm_icache_lru:4;
        RBus_UInt32  rm_dcache_tag:4;
        RBus_UInt32  res1:8;
    };
}ae_mbist_acpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rm_imem:4;
        RBus_UInt32  rm_dmem1:4;
        RBus_UInt32  rm_dmem0:4;
        RBus_UInt32  rm_dcache_data:4;
        RBus_UInt32  rm_icache_data:4;
        RBus_UInt32  res2:8;
    };
}ae_mbisr_acpu_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_bist_done:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_bist_fail_group:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail0:1;
        RBus_UInt32  bist_fail1:1;
        RBus_UInt32  bist_fail2:1;
        RBus_UInt32  bist_fail3:1;
        RBus_UInt32  bist_fail4:1;
        RBus_UInt32  bist_fail5:1;
        RBus_UInt32  res1:26;
    };
}ae_mbist_acpu_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_mode:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resume:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_done:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pause:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}ae_mbist_acpu_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail0:1;
        RBus_UInt32  drf_fail1:1;
        RBus_UInt32  drf_fail2:1;
        RBus_UInt32  drf_fail3:1;
        RBus_UInt32  drf_fail4:1;
        RBus_UInt32  drf_fail5:1;
        RBus_UInt32  res1:26;
    };
}ae_mbist_acpu_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr0_second_run_en:1;
        RBus_UInt32  bisr1_second_run_en:1;
        RBus_UInt32  bisr2_second_run_en:1;
        RBus_UInt32  bisr3_second_run_en:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr0_fail_group:1;
        RBus_UInt32  bisr1_fail_group:1;
        RBus_UInt32  bisr2_fail_group:1;
        RBus_UInt32  bisr3_fail_group:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr0_fail_0:1;
        RBus_UInt32  bisr1_fail_0:1;
        RBus_UInt32  bisr2_fail_0:1;
        RBus_UInt32  bisr2_fail_1:1;
        RBus_UInt32  bisr3_fail_0:1;
        RBus_UInt32  res1:27;
    };
}ae_mbisr_acpu_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr0_drf_mode:1;
        RBus_UInt32  bisr1_drf_mode:1;
        RBus_UInt32  bisr2_drf_mode:1;
        RBus_UInt32  bisr3_drf_mode:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_0_resume:1;
        RBus_UInt32  drf_1_resume:1;
        RBus_UInt32  drf_2_resume:1;
        RBus_UInt32  drf_3_resume:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr0_drf_done:1;
        RBus_UInt32  bisr1_drf_done:1;
        RBus_UInt32  bisr2_drf_done:1;
        RBus_UInt32  bisr3_drf_done:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr0_drf_fail_group:1;
        RBus_UInt32  bisr1_drf_fail_group:1;
        RBus_UInt32  bisr2_drf_fail_group:1;
        RBus_UInt32  bisr3_drf_fail_group:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_0_pause:1;
        RBus_UInt32  drf_1_pause:1;
        RBus_UInt32  drf_2_pause:1;
        RBus_UInt32  drf_3_pause:1;
        RBus_UInt32  res1:28;
    };
}ae_mbisr_acpu_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_0_fail_0:1;
        RBus_UInt32  drf_1_fail_0:1;
        RBus_UInt32  drf_2_fail_0:1;
        RBus_UInt32  drf_2_fail_1:1;
        RBus_UInt32  drf_3_fail_0:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  drf_0_repaired:1;
        RBus_UInt32  drf_1_repaired:1;
        RBus_UInt32  drf_2_repaired:1;
        RBus_UInt32  drf_3_repaired:1;
    };
}ae_mbisr_acpu_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rma_ade:4;
        RBus_UInt32  rmea_ade:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rmb_ade:4;
        RBus_UInt32  rmeb_ade:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rma_aee:4;
        RBus_UInt32  rmea_aee:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rmb_aee:4;
        RBus_UInt32  rmeb_aee:1;
        RBus_UInt32  res4:3;
    };
}ae_ae_bist_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_ade:1;
        RBus_UInt32  mode_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_bist_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done_ade:1;
        RBus_UInt32  done_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail_ade:1;
        RBus_UInt32  fail_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_bist_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_ade:1;
        RBus_UInt32  mode_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_drf_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  done_ade:1;
        RBus_UInt32  done_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_drf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fail_ade:1;
        RBus_UInt32  fail_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_drf_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pause_ade:1;
        RBus_UInt32  pause_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_drf_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  resume_ade:1;
        RBus_UInt32  resume_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_drf_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_ade:1;
        RBus_UInt32  ls_aee:1;
        RBus_UInt32  res1:30;
    };
}ae_ae_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_err:1;
        RBus_UInt32  rx_done:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rx_start:1;
        RBus_UInt32  rx_mode:1;
        RBus_UInt32  rx_gated:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tx_work:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tx_start:1;
        RBus_UInt32  tx_mode:1;
        RBus_UInt32  res4:18;
    };
}ae_aee_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_err:1;
        RBus_UInt32  rx_done:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rx_start:1;
        RBus_UInt32  rx_mode:1;
        RBus_UInt32  rx_gated:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tx_work:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tx_start:1;
        RBus_UInt32  tx_mode:1;
        RBus_UInt32  res4:18;
    };
}ae_ade_sf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_outstand_num:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  wr_outstand_num:3;
        RBus_UInt32  res2:24;
        RBus_UInt32  wlast_sel:1;
    };
}ae_wrapper_cfg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fetch_dbg_entry_ocp:1;
        RBus_UInt32  stop_dbg_ocp:1;
        RBus_UInt32  res1:30;
    };
}ae_ocpdbg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid_entry_cnt_ocp:5;
        RBus_UInt32  res1:27;
    };
}ae_ocpdbg_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ocpdbg_addr:32;
    };
}ae_ocpdbg_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ocpdbg_tag_id:4;
        RBus_UInt32  ocpdbg_byte_en:8;
        RBus_UInt32  ocpdbg_write:1;
        RBus_UInt32  res1:19;
    };
}ae_ocpdbg_status3_RBUS;




#endif 


#endif 
