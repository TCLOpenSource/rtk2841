/**
* @file Mac5-DesignSpec-VDE
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VDE_REG_H_
#define _RBUS_VDE_REG_H_

#include "rbus_types.h"



//  VDE Register Address
#define  VDE_VC_DMA_SRC_0                                                        0x18001000
#define  VDE_VC_DMA_SRC_0_reg_addr                                               "0xB8001000"
#define  VDE_VC_DMA_SRC_0_reg                                                    0xB8001000
#define  VDE_VC_DMA_SRC_0_inst_addr                                              "0x0000"
#define  set_VDE_VC_DMA_SRC_0_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_0_reg)=data)
#define  get_VDE_VC_DMA_SRC_0_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_0_reg))
#define  VDE_VC_DMA_SRC_0_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_0_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_0_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_0_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_1                                                        0x18001004
#define  VDE_VC_DMA_SRC_1_reg_addr                                               "0xB8001004"
#define  VDE_VC_DMA_SRC_1_reg                                                    0xB8001004
#define  VDE_VC_DMA_SRC_1_inst_addr                                              "0x0001"
#define  set_VDE_VC_DMA_SRC_1_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_1_reg)=data)
#define  get_VDE_VC_DMA_SRC_1_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_1_reg))
#define  VDE_VC_DMA_SRC_1_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_1_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_1_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_1_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_2                                                        0x18001008
#define  VDE_VC_DMA_SRC_2_reg_addr                                               "0xB8001008"
#define  VDE_VC_DMA_SRC_2_reg                                                    0xB8001008
#define  VDE_VC_DMA_SRC_2_inst_addr                                              "0x0002"
#define  set_VDE_VC_DMA_SRC_2_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_2_reg)=data)
#define  get_VDE_VC_DMA_SRC_2_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_2_reg))
#define  VDE_VC_DMA_SRC_2_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_2_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_2_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_2_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_3                                                        0x1800100C
#define  VDE_VC_DMA_SRC_3_reg_addr                                               "0xB800100C"
#define  VDE_VC_DMA_SRC_3_reg                                                    0xB800100C
#define  VDE_VC_DMA_SRC_3_inst_addr                                              "0x0003"
#define  set_VDE_VC_DMA_SRC_3_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_3_reg)=data)
#define  get_VDE_VC_DMA_SRC_3_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_3_reg))
#define  VDE_VC_DMA_SRC_3_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_3_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_3_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_3_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_4                                                        0x18001010
#define  VDE_VC_DMA_SRC_4_reg_addr                                               "0xB8001010"
#define  VDE_VC_DMA_SRC_4_reg                                                    0xB8001010
#define  VDE_VC_DMA_SRC_4_inst_addr                                              "0x0004"
#define  set_VDE_VC_DMA_SRC_4_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_4_reg)=data)
#define  get_VDE_VC_DMA_SRC_4_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_4_reg))
#define  VDE_VC_DMA_SRC_4_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_4_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_4_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_4_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_5                                                        0x18001014
#define  VDE_VC_DMA_SRC_5_reg_addr                                               "0xB8001014"
#define  VDE_VC_DMA_SRC_5_reg                                                    0xB8001014
#define  VDE_VC_DMA_SRC_5_inst_addr                                              "0x0005"
#define  set_VDE_VC_DMA_SRC_5_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_5_reg)=data)
#define  get_VDE_VC_DMA_SRC_5_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_5_reg))
#define  VDE_VC_DMA_SRC_5_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_5_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_5_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_5_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_6                                                        0x18001018
#define  VDE_VC_DMA_SRC_6_reg_addr                                               "0xB8001018"
#define  VDE_VC_DMA_SRC_6_reg                                                    0xB8001018
#define  VDE_VC_DMA_SRC_6_inst_addr                                              "0x0006"
#define  set_VDE_VC_DMA_SRC_6_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_6_reg)=data)
#define  get_VDE_VC_DMA_SRC_6_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_6_reg))
#define  VDE_VC_DMA_SRC_6_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_6_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_6_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_6_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SRC_7                                                        0x1800101C
#define  VDE_VC_DMA_SRC_7_reg_addr                                               "0xB800101C"
#define  VDE_VC_DMA_SRC_7_reg                                                    0xB800101C
#define  VDE_VC_DMA_SRC_7_inst_addr                                              "0x0007"
#define  set_VDE_VC_DMA_SRC_7_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_SRC_7_reg)=data)
#define  get_VDE_VC_DMA_SRC_7_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_SRC_7_reg))
#define  VDE_VC_DMA_SRC_7_src_shift                                              (3)
#define  VDE_VC_DMA_SRC_7_src_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_SRC_7_src(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_SRC_7_get_src(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_0                                                        0x18001020
#define  VDE_VC_DMA_DST_0_reg_addr                                               "0xB8001020"
#define  VDE_VC_DMA_DST_0_reg                                                    0xB8001020
#define  VDE_VC_DMA_DST_0_inst_addr                                              "0x0008"
#define  set_VDE_VC_DMA_DST_0_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_0_reg)=data)
#define  get_VDE_VC_DMA_DST_0_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_0_reg))
#define  VDE_VC_DMA_DST_0_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_0_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_0_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_0_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_1                                                        0x18001024
#define  VDE_VC_DMA_DST_1_reg_addr                                               "0xB8001024"
#define  VDE_VC_DMA_DST_1_reg                                                    0xB8001024
#define  VDE_VC_DMA_DST_1_inst_addr                                              "0x0009"
#define  set_VDE_VC_DMA_DST_1_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_1_reg)=data)
#define  get_VDE_VC_DMA_DST_1_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_1_reg))
#define  VDE_VC_DMA_DST_1_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_1_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_1_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_1_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_2                                                        0x18001028
#define  VDE_VC_DMA_DST_2_reg_addr                                               "0xB8001028"
#define  VDE_VC_DMA_DST_2_reg                                                    0xB8001028
#define  VDE_VC_DMA_DST_2_inst_addr                                              "0x000A"
#define  set_VDE_VC_DMA_DST_2_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_2_reg)=data)
#define  get_VDE_VC_DMA_DST_2_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_2_reg))
#define  VDE_VC_DMA_DST_2_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_2_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_2_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_2_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_3                                                        0x1800102C
#define  VDE_VC_DMA_DST_3_reg_addr                                               "0xB800102C"
#define  VDE_VC_DMA_DST_3_reg                                                    0xB800102C
#define  VDE_VC_DMA_DST_3_inst_addr                                              "0x000B"
#define  set_VDE_VC_DMA_DST_3_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_3_reg)=data)
#define  get_VDE_VC_DMA_DST_3_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_3_reg))
#define  VDE_VC_DMA_DST_3_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_3_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_3_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_3_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_4                                                        0x18001030
#define  VDE_VC_DMA_DST_4_reg_addr                                               "0xB8001030"
#define  VDE_VC_DMA_DST_4_reg                                                    0xB8001030
#define  VDE_VC_DMA_DST_4_inst_addr                                              "0x000C"
#define  set_VDE_VC_DMA_DST_4_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_4_reg)=data)
#define  get_VDE_VC_DMA_DST_4_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_4_reg))
#define  VDE_VC_DMA_DST_4_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_4_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_4_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_4_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_5                                                        0x18001034
#define  VDE_VC_DMA_DST_5_reg_addr                                               "0xB8001034"
#define  VDE_VC_DMA_DST_5_reg                                                    0xB8001034
#define  VDE_VC_DMA_DST_5_inst_addr                                              "0x000D"
#define  set_VDE_VC_DMA_DST_5_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_5_reg)=data)
#define  get_VDE_VC_DMA_DST_5_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_5_reg))
#define  VDE_VC_DMA_DST_5_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_5_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_5_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_5_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_6                                                        0x18001038
#define  VDE_VC_DMA_DST_6_reg_addr                                               "0xB8001038"
#define  VDE_VC_DMA_DST_6_reg                                                    0xB8001038
#define  VDE_VC_DMA_DST_6_inst_addr                                              "0x000E"
#define  set_VDE_VC_DMA_DST_6_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_6_reg)=data)
#define  get_VDE_VC_DMA_DST_6_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_6_reg))
#define  VDE_VC_DMA_DST_6_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_6_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_6_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_6_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_DST_7                                                        0x1800103C
#define  VDE_VC_DMA_DST_7_reg_addr                                               "0xB800103C"
#define  VDE_VC_DMA_DST_7_reg                                                    0xB800103C
#define  VDE_VC_DMA_DST_7_inst_addr                                              "0x000F"
#define  set_VDE_VC_DMA_DST_7_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DST_7_reg)=data)
#define  get_VDE_VC_DMA_DST_7_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DST_7_reg))
#define  VDE_VC_DMA_DST_7_dst_shift                                              (3)
#define  VDE_VC_DMA_DST_7_dst_mask                                               (0xFFFFFFF8)
#define  VDE_VC_DMA_DST_7_dst(data)                                              (0xFFFFFFF8&((data)<<3))
#define  VDE_VC_DMA_DST_7_get_dst(data)                                          ((0xFFFFFFF8&(data))>>3)

#define  VDE_VC_DMA_SIZE_0                                                       0x18001040
#define  VDE_VC_DMA_SIZE_0_reg_addr                                              "0xB8001040"
#define  VDE_VC_DMA_SIZE_0_reg                                                   0xB8001040
#define  VDE_VC_DMA_SIZE_0_inst_addr                                             "0x0010"
#define  set_VDE_VC_DMA_SIZE_0_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_0_reg)=data)
#define  get_VDE_VC_DMA_SIZE_0_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_0_reg))
#define  VDE_VC_DMA_SIZE_0_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_0_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_0_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_0_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_0_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_0_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_0_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_0_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_0_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_0_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_0_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_0_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_0_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_0_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_0_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_0_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_1                                                       0x18001044
#define  VDE_VC_DMA_SIZE_1_reg_addr                                              "0xB8001044"
#define  VDE_VC_DMA_SIZE_1_reg                                                   0xB8001044
#define  VDE_VC_DMA_SIZE_1_inst_addr                                             "0x0011"
#define  set_VDE_VC_DMA_SIZE_1_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_1_reg)=data)
#define  get_VDE_VC_DMA_SIZE_1_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_1_reg))
#define  VDE_VC_DMA_SIZE_1_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_1_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_1_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_1_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_1_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_1_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_1_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_1_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_1_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_1_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_1_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_1_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_1_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_1_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_1_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_1_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_2                                                       0x18001048
#define  VDE_VC_DMA_SIZE_2_reg_addr                                              "0xB8001048"
#define  VDE_VC_DMA_SIZE_2_reg                                                   0xB8001048
#define  VDE_VC_DMA_SIZE_2_inst_addr                                             "0x0012"
#define  set_VDE_VC_DMA_SIZE_2_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_2_reg)=data)
#define  get_VDE_VC_DMA_SIZE_2_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_2_reg))
#define  VDE_VC_DMA_SIZE_2_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_2_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_2_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_2_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_2_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_2_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_2_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_2_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_2_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_2_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_2_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_2_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_2_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_2_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_2_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_2_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_3                                                       0x1800104C
#define  VDE_VC_DMA_SIZE_3_reg_addr                                              "0xB800104C"
#define  VDE_VC_DMA_SIZE_3_reg                                                   0xB800104C
#define  VDE_VC_DMA_SIZE_3_inst_addr                                             "0x0013"
#define  set_VDE_VC_DMA_SIZE_3_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_3_reg)=data)
#define  get_VDE_VC_DMA_SIZE_3_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_3_reg))
#define  VDE_VC_DMA_SIZE_3_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_3_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_3_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_3_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_3_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_3_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_3_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_3_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_3_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_3_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_3_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_3_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_3_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_3_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_3_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_3_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_4                                                       0x18001050
#define  VDE_VC_DMA_SIZE_4_reg_addr                                              "0xB8001050"
#define  VDE_VC_DMA_SIZE_4_reg                                                   0xB8001050
#define  VDE_VC_DMA_SIZE_4_inst_addr                                             "0x0014"
#define  set_VDE_VC_DMA_SIZE_4_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_4_reg)=data)
#define  get_VDE_VC_DMA_SIZE_4_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_4_reg))
#define  VDE_VC_DMA_SIZE_4_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_4_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_4_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_4_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_4_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_4_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_4_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_4_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_4_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_4_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_4_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_4_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_4_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_4_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_4_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_4_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_5                                                       0x18001054
#define  VDE_VC_DMA_SIZE_5_reg_addr                                              "0xB8001054"
#define  VDE_VC_DMA_SIZE_5_reg                                                   0xB8001054
#define  VDE_VC_DMA_SIZE_5_inst_addr                                             "0x0015"
#define  set_VDE_VC_DMA_SIZE_5_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_5_reg)=data)
#define  get_VDE_VC_DMA_SIZE_5_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_5_reg))
#define  VDE_VC_DMA_SIZE_5_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_5_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_5_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_5_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_5_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_5_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_5_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_5_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_5_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_5_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_5_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_5_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_5_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_5_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_5_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_5_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_6                                                       0x18001058
#define  VDE_VC_DMA_SIZE_6_reg_addr                                              "0xB8001058"
#define  VDE_VC_DMA_SIZE_6_reg                                                   0xB8001058
#define  VDE_VC_DMA_SIZE_6_inst_addr                                             "0x0016"
#define  set_VDE_VC_DMA_SIZE_6_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_6_reg)=data)
#define  get_VDE_VC_DMA_SIZE_6_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_6_reg))
#define  VDE_VC_DMA_SIZE_6_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_6_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_6_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_6_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_6_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_6_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_6_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_6_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_6_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_6_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_6_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_6_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_6_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_6_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_6_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_6_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_SIZE_7                                                       0x1800105C
#define  VDE_VC_DMA_SIZE_7_reg_addr                                              "0xB800105C"
#define  VDE_VC_DMA_SIZE_7_reg                                                   0xB800105C
#define  VDE_VC_DMA_SIZE_7_inst_addr                                             "0x0017"
#define  set_VDE_VC_DMA_SIZE_7_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_SIZE_7_reg)=data)
#define  get_VDE_VC_DMA_SIZE_7_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_SIZE_7_reg))
#define  VDE_VC_DMA_SIZE_7_valid_shift                                           (15)
#define  VDE_VC_DMA_SIZE_7_dir_shift                                             (14)
#define  VDE_VC_DMA_SIZE_7_size_shift                                            (3)
#define  VDE_VC_DMA_SIZE_7_dma_type_shift                                        (0)
#define  VDE_VC_DMA_SIZE_7_valid_mask                                            (0x00008000)
#define  VDE_VC_DMA_SIZE_7_dir_mask                                              (0x00004000)
#define  VDE_VC_DMA_SIZE_7_size_mask                                             (0x00003FF8)
#define  VDE_VC_DMA_SIZE_7_dma_type_mask                                         (0x00000001)
#define  VDE_VC_DMA_SIZE_7_valid(data)                                           (0x00008000&((data)<<15))
#define  VDE_VC_DMA_SIZE_7_dir(data)                                             (0x00004000&((data)<<14))
#define  VDE_VC_DMA_SIZE_7_size(data)                                            (0x00003FF8&((data)<<3))
#define  VDE_VC_DMA_SIZE_7_dma_type(data)                                        (0x00000001&(data))
#define  VDE_VC_DMA_SIZE_7_get_valid(data)                                       ((0x00008000&(data))>>15)
#define  VDE_VC_DMA_SIZE_7_get_dir(data)                                         ((0x00004000&(data))>>14)
#define  VDE_VC_DMA_SIZE_7_get_size(data)                                        ((0x00003FF8&(data))>>3)
#define  VDE_VC_DMA_SIZE_7_get_dma_type(data)                                    (0x00000001&(data))

#define  VDE_VC_DMA_BLK_0                                                        0x18001090
#define  VDE_VC_DMA_BLK_0_reg_addr                                               "0xB8001090"
#define  VDE_VC_DMA_BLK_0_reg                                                    0xB8001090
#define  VDE_VC_DMA_BLK_0_inst_addr                                              "0x0018"
#define  set_VDE_VC_DMA_BLK_0_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_0_reg)=data)
#define  get_VDE_VC_DMA_BLK_0_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_0_reg))
#define  VDE_VC_DMA_BLK_0_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_0_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_0_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_0_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_0_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_0_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_0_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_0_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_0_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_0_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_0_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_0_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_0_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_0_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_0_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_0_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_1                                                        0x18001094
#define  VDE_VC_DMA_BLK_1_reg_addr                                               "0xB8001094"
#define  VDE_VC_DMA_BLK_1_reg                                                    0xB8001094
#define  VDE_VC_DMA_BLK_1_inst_addr                                              "0x0019"
#define  set_VDE_VC_DMA_BLK_1_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_1_reg)=data)
#define  get_VDE_VC_DMA_BLK_1_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_1_reg))
#define  VDE_VC_DMA_BLK_1_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_1_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_1_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_1_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_1_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_1_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_1_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_1_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_1_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_1_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_1_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_1_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_1_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_1_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_1_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_1_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_2                                                        0x18001098
#define  VDE_VC_DMA_BLK_2_reg_addr                                               "0xB8001098"
#define  VDE_VC_DMA_BLK_2_reg                                                    0xB8001098
#define  VDE_VC_DMA_BLK_2_inst_addr                                              "0x001A"
#define  set_VDE_VC_DMA_BLK_2_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_2_reg)=data)
#define  get_VDE_VC_DMA_BLK_2_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_2_reg))
#define  VDE_VC_DMA_BLK_2_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_2_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_2_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_2_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_2_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_2_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_2_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_2_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_2_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_2_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_2_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_2_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_2_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_2_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_2_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_2_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_3                                                        0x1800109C
#define  VDE_VC_DMA_BLK_3_reg_addr                                               "0xB800109C"
#define  VDE_VC_DMA_BLK_3_reg                                                    0xB800109C
#define  VDE_VC_DMA_BLK_3_inst_addr                                              "0x001B"
#define  set_VDE_VC_DMA_BLK_3_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_3_reg)=data)
#define  get_VDE_VC_DMA_BLK_3_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_3_reg))
#define  VDE_VC_DMA_BLK_3_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_3_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_3_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_3_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_3_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_3_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_3_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_3_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_3_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_3_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_3_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_3_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_3_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_3_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_3_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_3_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_4                                                        0x180010A0
#define  VDE_VC_DMA_BLK_4_reg_addr                                               "0xB80010A0"
#define  VDE_VC_DMA_BLK_4_reg                                                    0xB80010A0
#define  VDE_VC_DMA_BLK_4_inst_addr                                              "0x001C"
#define  set_VDE_VC_DMA_BLK_4_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_4_reg)=data)
#define  get_VDE_VC_DMA_BLK_4_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_4_reg))
#define  VDE_VC_DMA_BLK_4_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_4_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_4_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_4_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_4_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_4_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_4_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_4_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_4_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_4_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_4_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_4_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_4_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_4_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_4_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_4_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_5                                                        0x180010A4
#define  VDE_VC_DMA_BLK_5_reg_addr                                               "0xB80010A4"
#define  VDE_VC_DMA_BLK_5_reg                                                    0xB80010A4
#define  VDE_VC_DMA_BLK_5_inst_addr                                              "0x001D"
#define  set_VDE_VC_DMA_BLK_5_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_5_reg)=data)
#define  get_VDE_VC_DMA_BLK_5_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_5_reg))
#define  VDE_VC_DMA_BLK_5_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_5_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_5_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_5_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_5_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_5_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_5_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_5_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_5_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_5_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_5_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_5_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_5_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_5_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_5_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_5_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_6                                                        0x180010A8
#define  VDE_VC_DMA_BLK_6_reg_addr                                               "0xB80010A8"
#define  VDE_VC_DMA_BLK_6_reg                                                    0xB80010A8
#define  VDE_VC_DMA_BLK_6_inst_addr                                              "0x001E"
#define  set_VDE_VC_DMA_BLK_6_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_6_reg)=data)
#define  get_VDE_VC_DMA_BLK_6_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_6_reg))
#define  VDE_VC_DMA_BLK_6_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_6_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_6_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_6_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_6_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_6_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_6_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_6_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_6_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_6_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_6_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_6_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_6_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_6_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_6_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_6_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLK_7                                                        0x180010AC
#define  VDE_VC_DMA_BLK_7_reg_addr                                               "0xB80010AC"
#define  VDE_VC_DMA_BLK_7_reg                                                    0xB80010AC
#define  VDE_VC_DMA_BLK_7_inst_addr                                              "0x001F"
#define  set_VDE_VC_DMA_BLK_7_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_BLK_7_reg)=data)
#define  get_VDE_VC_DMA_BLK_7_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_BLK_7_reg))
#define  VDE_VC_DMA_BLK_7_blk_h_shift                                            (26)
#define  VDE_VC_DMA_BLK_7_blk_w_shift                                            (22)
#define  VDE_VC_DMA_BLK_7_blk_y_shift                                            (10)
#define  VDE_VC_DMA_BLK_7_blk_x_shift                                            (0)
#define  VDE_VC_DMA_BLK_7_blk_h_mask                                             (0xFC000000)
#define  VDE_VC_DMA_BLK_7_blk_w_mask                                             (0x03C00000)
#define  VDE_VC_DMA_BLK_7_blk_y_mask                                             (0x003FFC00)
#define  VDE_VC_DMA_BLK_7_blk_x_mask                                             (0x000003FF)
#define  VDE_VC_DMA_BLK_7_blk_h(data)                                            (0xFC000000&((data)<<26))
#define  VDE_VC_DMA_BLK_7_blk_w(data)                                            (0x03C00000&((data)<<22))
#define  VDE_VC_DMA_BLK_7_blk_y(data)                                            (0x003FFC00&((data)<<10))
#define  VDE_VC_DMA_BLK_7_blk_x(data)                                            (0x000003FF&(data))
#define  VDE_VC_DMA_BLK_7_get_blk_h(data)                                        ((0xFC000000&(data))>>26)
#define  VDE_VC_DMA_BLK_7_get_blk_w(data)                                        ((0x03C00000&(data))>>22)
#define  VDE_VC_DMA_BLK_7_get_blk_y(data)                                        ((0x003FFC00&(data))>>10)
#define  VDE_VC_DMA_BLK_7_get_blk_x(data)                                        (0x000003FF&(data))

#define  VDE_VC_DMA_BLKINFO_0                                                    0x180010B0
#define  VDE_VC_DMA_BLKINFO_0_reg_addr                                           "0xB80010B0"
#define  VDE_VC_DMA_BLKINFO_0_reg                                                0xB80010B0
#define  VDE_VC_DMA_BLKINFO_0_inst_addr                                          "0x0020"
#define  set_VDE_VC_DMA_BLKINFO_0_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_0_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_0_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_0_reg))
#define  VDE_VC_DMA_BLKINFO_0_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_0_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_0_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_0_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_0_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_0_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_0_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_0_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_0_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_0_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_0_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_0_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_0_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_0_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_0_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_0_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_0_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_0_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_0_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_0_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_1                                                    0x180010B4
#define  VDE_VC_DMA_BLKINFO_1_reg_addr                                           "0xB80010B4"
#define  VDE_VC_DMA_BLKINFO_1_reg                                                0xB80010B4
#define  VDE_VC_DMA_BLKINFO_1_inst_addr                                          "0x0021"
#define  set_VDE_VC_DMA_BLKINFO_1_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_1_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_1_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_1_reg))
#define  VDE_VC_DMA_BLKINFO_1_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_1_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_1_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_1_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_1_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_1_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_1_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_1_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_1_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_1_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_1_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_1_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_1_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_1_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_1_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_1_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_1_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_1_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_1_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_1_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_2                                                    0x180010B8
#define  VDE_VC_DMA_BLKINFO_2_reg_addr                                           "0xB80010B8"
#define  VDE_VC_DMA_BLKINFO_2_reg                                                0xB80010B8
#define  VDE_VC_DMA_BLKINFO_2_inst_addr                                          "0x0022"
#define  set_VDE_VC_DMA_BLKINFO_2_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_2_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_2_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_2_reg))
#define  VDE_VC_DMA_BLKINFO_2_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_2_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_2_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_2_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_2_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_2_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_2_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_2_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_2_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_2_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_2_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_2_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_2_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_2_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_2_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_2_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_2_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_2_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_2_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_2_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_3                                                    0x180010BC
#define  VDE_VC_DMA_BLKINFO_3_reg_addr                                           "0xB80010BC"
#define  VDE_VC_DMA_BLKINFO_3_reg                                                0xB80010BC
#define  VDE_VC_DMA_BLKINFO_3_inst_addr                                          "0x0023"
#define  set_VDE_VC_DMA_BLKINFO_3_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_3_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_3_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_3_reg))
#define  VDE_VC_DMA_BLKINFO_3_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_3_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_3_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_3_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_3_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_3_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_3_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_3_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_3_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_3_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_3_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_3_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_3_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_3_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_3_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_3_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_3_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_3_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_3_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_3_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_4                                                    0x180010C0
#define  VDE_VC_DMA_BLKINFO_4_reg_addr                                           "0xB80010C0"
#define  VDE_VC_DMA_BLKINFO_4_reg                                                0xB80010C0
#define  VDE_VC_DMA_BLKINFO_4_inst_addr                                          "0x0024"
#define  set_VDE_VC_DMA_BLKINFO_4_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_4_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_4_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_4_reg))
#define  VDE_VC_DMA_BLKINFO_4_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_4_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_4_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_4_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_4_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_4_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_4_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_4_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_4_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_4_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_4_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_4_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_4_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_4_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_4_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_4_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_4_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_4_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_4_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_4_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_5                                                    0x180010C4
#define  VDE_VC_DMA_BLKINFO_5_reg_addr                                           "0xB80010C4"
#define  VDE_VC_DMA_BLKINFO_5_reg                                                0xB80010C4
#define  VDE_VC_DMA_BLKINFO_5_inst_addr                                          "0x0025"
#define  set_VDE_VC_DMA_BLKINFO_5_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_5_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_5_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_5_reg))
#define  VDE_VC_DMA_BLKINFO_5_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_5_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_5_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_5_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_5_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_5_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_5_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_5_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_5_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_5_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_5_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_5_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_5_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_5_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_5_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_5_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_5_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_5_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_5_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_5_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_6                                                    0x180010C8
#define  VDE_VC_DMA_BLKINFO_6_reg_addr                                           "0xB80010C8"
#define  VDE_VC_DMA_BLKINFO_6_reg                                                0xB80010C8
#define  VDE_VC_DMA_BLKINFO_6_inst_addr                                          "0x0026"
#define  set_VDE_VC_DMA_BLKINFO_6_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_6_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_6_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_6_reg))
#define  VDE_VC_DMA_BLKINFO_6_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_6_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_6_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_6_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_6_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_6_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_6_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_6_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_6_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_6_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_6_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_6_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_6_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_6_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_6_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_6_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_6_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_6_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_6_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_6_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_BLKINFO_7                                                    0x180010CC
#define  VDE_VC_DMA_BLKINFO_7_reg_addr                                           "0xB80010CC"
#define  VDE_VC_DMA_BLKINFO_7_reg                                                0xB80010CC
#define  VDE_VC_DMA_BLKINFO_7_inst_addr                                          "0x0027"
#define  set_VDE_VC_DMA_BLKINFO_7_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_7_reg)=data)
#define  get_VDE_VC_DMA_BLKINFO_7_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_BLKINFO_7_reg))
#define  VDE_VC_DMA_BLKINFO_7_field_mode_shift                                   (24)
#define  VDE_VC_DMA_BLKINFO_7_pic_index_shift                                    (17)
#define  VDE_VC_DMA_BLKINFO_7_chroma_shift                                       (16)
#define  VDE_VC_DMA_BLKINFO_7_row_offset_shift                                   (11)
#define  VDE_VC_DMA_BLKINFO_7_chroma_pitch_shift                                 (0)
#define  VDE_VC_DMA_BLKINFO_7_field_mode_mask                                    (0x01000000)
#define  VDE_VC_DMA_BLKINFO_7_pic_index_mask                                     (0x00FE0000)
#define  VDE_VC_DMA_BLKINFO_7_chroma_mask                                        (0x00010000)
#define  VDE_VC_DMA_BLKINFO_7_row_offset_mask                                    (0x0000F800)
#define  VDE_VC_DMA_BLKINFO_7_chroma_pitch_mask                                  (0x000007FF)
#define  VDE_VC_DMA_BLKINFO_7_field_mode(data)                                   (0x01000000&((data)<<24))
#define  VDE_VC_DMA_BLKINFO_7_pic_index(data)                                    (0x00FE0000&((data)<<17))
#define  VDE_VC_DMA_BLKINFO_7_chroma(data)                                       (0x00010000&((data)<<16))
#define  VDE_VC_DMA_BLKINFO_7_row_offset(data)                                   (0x0000F800&((data)<<11))
#define  VDE_VC_DMA_BLKINFO_7_chroma_pitch(data)                                 (0x000007FF&(data))
#define  VDE_VC_DMA_BLKINFO_7_get_field_mode(data)                               ((0x01000000&(data))>>24)
#define  VDE_VC_DMA_BLKINFO_7_get_pic_index(data)                                ((0x00FE0000&(data))>>17)
#define  VDE_VC_DMA_BLKINFO_7_get_chroma(data)                                   ((0x00010000&(data))>>16)
#define  VDE_VC_DMA_BLKINFO_7_get_row_offset(data)                               ((0x0000F800&(data))>>11)
#define  VDE_VC_DMA_BLKINFO_7_get_chroma_pitch(data)                             (0x000007FF&(data))

#define  VDE_VC_DMA_CNTL                                                         0x18001064
#define  VDE_VC_DMA_CNTL_reg_addr                                                "0xB8001064"
#define  VDE_VC_DMA_CNTL_reg                                                     0xB8001064
#define  VDE_VC_DMA_CNTL_inst_addr                                               "0x0028"
#define  set_VDE_VC_DMA_CNTL_reg(data)                                           (*((volatile unsigned int*)VDE_VC_DMA_CNTL_reg)=data)
#define  get_VDE_VC_DMA_CNTL_reg                                                 (*((volatile unsigned int*)VDE_VC_DMA_CNTL_reg))
#define  VDE_VC_DMA_CNTL_write_enable1_shift                                     (17)
#define  VDE_VC_DMA_CNTL_max_xfer_shift                                          (11)
#define  VDE_VC_DMA_CNTL_write_enable3_shift                                     (5)
#define  VDE_VC_DMA_CNTL_dmem_req_en_shift                                       (4)
#define  VDE_VC_DMA_CNTL_write_enable4_shift                                     (3)
#define  VDE_VC_DMA_CNTL_stop_shift                                              (2)
#define  VDE_VC_DMA_CNTL_write_enable5_shift                                     (1)
#define  VDE_VC_DMA_CNTL_go_shift                                                (0)
#define  VDE_VC_DMA_CNTL_write_enable1_mask                                      (0x00020000)
#define  VDE_VC_DMA_CNTL_max_xfer_mask                                           (0x0001F800)
#define  VDE_VC_DMA_CNTL_write_enable3_mask                                      (0x00000020)
#define  VDE_VC_DMA_CNTL_dmem_req_en_mask                                        (0x00000010)
#define  VDE_VC_DMA_CNTL_write_enable4_mask                                      (0x00000008)
#define  VDE_VC_DMA_CNTL_stop_mask                                               (0x00000004)
#define  VDE_VC_DMA_CNTL_write_enable5_mask                                      (0x00000002)
#define  VDE_VC_DMA_CNTL_go_mask                                                 (0x00000001)
#define  VDE_VC_DMA_CNTL_write_enable1(data)                                     (0x00020000&((data)<<17))
#define  VDE_VC_DMA_CNTL_max_xfer(data)                                          (0x0001F800&((data)<<11))
#define  VDE_VC_DMA_CNTL_write_enable3(data)                                     (0x00000020&((data)<<5))
#define  VDE_VC_DMA_CNTL_dmem_req_en(data)                                       (0x00000010&((data)<<4))
#define  VDE_VC_DMA_CNTL_write_enable4(data)                                     (0x00000008&((data)<<3))
#define  VDE_VC_DMA_CNTL_stop(data)                                              (0x00000004&((data)<<2))
#define  VDE_VC_DMA_CNTL_write_enable5(data)                                     (0x00000002&((data)<<1))
#define  VDE_VC_DMA_CNTL_go(data)                                                (0x00000001&(data))
#define  VDE_VC_DMA_CNTL_get_write_enable1(data)                                 ((0x00020000&(data))>>17)
#define  VDE_VC_DMA_CNTL_get_max_xfer(data)                                      ((0x0001F800&(data))>>11)
#define  VDE_VC_DMA_CNTL_get_write_enable3(data)                                 ((0x00000020&(data))>>5)
#define  VDE_VC_DMA_CNTL_get_dmem_req_en(data)                                   ((0x00000010&(data))>>4)
#define  VDE_VC_DMA_CNTL_get_write_enable4(data)                                 ((0x00000008&(data))>>3)
#define  VDE_VC_DMA_CNTL_get_stop(data)                                          ((0x00000004&(data))>>2)
#define  VDE_VC_DMA_CNTL_get_write_enable5(data)                                 ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_CNTL_get_go(data)                                            (0x00000001&(data))

#define  VDE_VC_DMA_INT                                                          0x18001068
#define  VDE_VC_DMA_INT_reg_addr                                                 "0xB8001068"
#define  VDE_VC_DMA_INT_reg                                                      0xB8001068
#define  VDE_VC_DMA_INT_inst_addr                                                "0x0029"
#define  set_VDE_VC_DMA_INT_reg(data)                                            (*((volatile unsigned int*)VDE_VC_DMA_INT_reg)=data)
#define  get_VDE_VC_DMA_INT_reg                                                  (*((volatile unsigned int*)VDE_VC_DMA_INT_reg))
#define  VDE_VC_DMA_INT_int_done_shift                                           (0)
#define  VDE_VC_DMA_INT_int_done_mask                                            (0x00000001)
#define  VDE_VC_DMA_INT_int_done(data)                                           (0x00000001&(data))
#define  VDE_VC_DMA_INT_get_int_done(data)                                       (0x00000001&(data))

#define  VDE_VC_DMA_INT_EN                                                       0x1800106C
#define  VDE_VC_DMA_INT_EN_reg_addr                                              "0xB800106C"
#define  VDE_VC_DMA_INT_EN_reg                                                   0xB800106C
#define  VDE_VC_DMA_INT_EN_inst_addr                                             "0x002A"
#define  set_VDE_VC_DMA_INT_EN_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_INT_EN_reg)=data)
#define  get_VDE_VC_DMA_INT_EN_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_INT_EN_reg))
#define  VDE_VC_DMA_INT_EN_int_done_en_shift                                     (0)
#define  VDE_VC_DMA_INT_EN_int_done_en_mask                                      (0x00000001)
#define  VDE_VC_DMA_INT_EN_int_done_en(data)                                     (0x00000001&(data))
#define  VDE_VC_DMA_INT_EN_get_int_done_en(data)                                 (0x00000001&(data))

#define  VDE_VC_DMA_STATUS                                                       0x18001060
#define  VDE_VC_DMA_STATUS_reg_addr                                              "0xB8001060"
#define  VDE_VC_DMA_STATUS_reg                                                   0xB8001060
#define  VDE_VC_DMA_STATUS_inst_addr                                             "0x002B"
#define  set_VDE_VC_DMA_STATUS_reg(data)                                         (*((volatile unsigned int*)VDE_VC_DMA_STATUS_reg)=data)
#define  get_VDE_VC_DMA_STATUS_reg                                               (*((volatile unsigned int*)VDE_VC_DMA_STATUS_reg))
#define  VDE_VC_DMA_STATUS_done_7_shift                                          (7)
#define  VDE_VC_DMA_STATUS_done_6_shift                                          (6)
#define  VDE_VC_DMA_STATUS_done_5_shift                                          (5)
#define  VDE_VC_DMA_STATUS_done_4_shift                                          (4)
#define  VDE_VC_DMA_STATUS_done_3_shift                                          (3)
#define  VDE_VC_DMA_STATUS_done_2_shift                                          (2)
#define  VDE_VC_DMA_STATUS_done_1_shift                                          (1)
#define  VDE_VC_DMA_STATUS_done_0_shift                                          (0)
#define  VDE_VC_DMA_STATUS_done_7_mask                                           (0x00000080)
#define  VDE_VC_DMA_STATUS_done_6_mask                                           (0x00000040)
#define  VDE_VC_DMA_STATUS_done_5_mask                                           (0x00000020)
#define  VDE_VC_DMA_STATUS_done_4_mask                                           (0x00000010)
#define  VDE_VC_DMA_STATUS_done_3_mask                                           (0x00000008)
#define  VDE_VC_DMA_STATUS_done_2_mask                                           (0x00000004)
#define  VDE_VC_DMA_STATUS_done_1_mask                                           (0x00000002)
#define  VDE_VC_DMA_STATUS_done_0_mask                                           (0x00000001)
#define  VDE_VC_DMA_STATUS_done_7(data)                                          (0x00000080&((data)<<7))
#define  VDE_VC_DMA_STATUS_done_6(data)                                          (0x00000040&((data)<<6))
#define  VDE_VC_DMA_STATUS_done_5(data)                                          (0x00000020&((data)<<5))
#define  VDE_VC_DMA_STATUS_done_4(data)                                          (0x00000010&((data)<<4))
#define  VDE_VC_DMA_STATUS_done_3(data)                                          (0x00000008&((data)<<3))
#define  VDE_VC_DMA_STATUS_done_2(data)                                          (0x00000004&((data)<<2))
#define  VDE_VC_DMA_STATUS_done_1(data)                                          (0x00000002&((data)<<1))
#define  VDE_VC_DMA_STATUS_done_0(data)                                          (0x00000001&(data))
#define  VDE_VC_DMA_STATUS_get_done_7(data)                                      ((0x00000080&(data))>>7)
#define  VDE_VC_DMA_STATUS_get_done_6(data)                                      ((0x00000040&(data))>>6)
#define  VDE_VC_DMA_STATUS_get_done_5(data)                                      ((0x00000020&(data))>>5)
#define  VDE_VC_DMA_STATUS_get_done_4(data)                                      ((0x00000010&(data))>>4)
#define  VDE_VC_DMA_STATUS_get_done_3(data)                                      ((0x00000008&(data))>>3)
#define  VDE_VC_DMA_STATUS_get_done_2(data)                                      ((0x00000004&(data))>>2)
#define  VDE_VC_DMA_STATUS_get_done_1(data)                                      ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_STATUS_get_done_0(data)                                      (0x00000001&(data))

#define  VDE_VC_DMA_DEBUG                                                        0x18001080
#define  VDE_VC_DMA_DEBUG_reg_addr                                               "0xB8001080"
#define  VDE_VC_DMA_DEBUG_reg                                                    0xB8001080
#define  VDE_VC_DMA_DEBUG_inst_addr                                              "0x002C"
#define  set_VDE_VC_DMA_DEBUG_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_DEBUG_reg)=data)
#define  get_VDE_VC_DMA_DEBUG_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_DEBUG_reg))
#define  VDE_VC_DMA_DEBUG_write_enable3_shift                                    (11)
#define  VDE_VC_DMA_DEBUG_sel1_shift                                             (7)
#define  VDE_VC_DMA_DEBUG_write_enable2_shift                                    (6)
#define  VDE_VC_DMA_DEBUG_sel0_shift                                             (2)
#define  VDE_VC_DMA_DEBUG_write_enable1_shift                                    (1)
#define  VDE_VC_DMA_DEBUG_enable_shift                                           (0)
#define  VDE_VC_DMA_DEBUG_write_enable3_mask                                     (0x00000800)
#define  VDE_VC_DMA_DEBUG_sel1_mask                                              (0x00000780)
#define  VDE_VC_DMA_DEBUG_write_enable2_mask                                     (0x00000040)
#define  VDE_VC_DMA_DEBUG_sel0_mask                                              (0x0000003C)
#define  VDE_VC_DMA_DEBUG_write_enable1_mask                                     (0x00000002)
#define  VDE_VC_DMA_DEBUG_enable_mask                                            (0x00000001)
#define  VDE_VC_DMA_DEBUG_write_enable3(data)                                    (0x00000800&((data)<<11))
#define  VDE_VC_DMA_DEBUG_sel1(data)                                             (0x00000780&((data)<<7))
#define  VDE_VC_DMA_DEBUG_write_enable2(data)                                    (0x00000040&((data)<<6))
#define  VDE_VC_DMA_DEBUG_sel0(data)                                             (0x0000003C&((data)<<2))
#define  VDE_VC_DMA_DEBUG_write_enable1(data)                                    (0x00000002&((data)<<1))
#define  VDE_VC_DMA_DEBUG_enable(data)                                           (0x00000001&(data))
#define  VDE_VC_DMA_DEBUG_get_write_enable3(data)                                ((0x00000800&(data))>>11)
#define  VDE_VC_DMA_DEBUG_get_sel1(data)                                         ((0x00000780&(data))>>7)
#define  VDE_VC_DMA_DEBUG_get_write_enable2(data)                                ((0x00000040&(data))>>6)
#define  VDE_VC_DMA_DEBUG_get_sel0(data)                                         ((0x0000003C&(data))>>2)
#define  VDE_VC_DMA_DEBUG_get_write_enable1(data)                                ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_DEBUG_get_enable(data)                                       (0x00000001&(data))

#define  VDE_VC_DMA_TIMER                                                        0x18001084
#define  VDE_VC_DMA_TIMER_reg_addr                                               "0xB8001084"
#define  VDE_VC_DMA_TIMER_reg                                                    0xB8001084
#define  VDE_VC_DMA_TIMER_inst_addr                                              "0x002D"
#define  set_VDE_VC_DMA_TIMER_reg(data)                                          (*((volatile unsigned int*)VDE_VC_DMA_TIMER_reg)=data)
#define  get_VDE_VC_DMA_TIMER_reg                                                (*((volatile unsigned int*)VDE_VC_DMA_TIMER_reg))
#define  VDE_VC_DMA_TIMER_write_enable1_shift                                    (5)
#define  VDE_VC_DMA_TIMER_delay_timer_shift                                      (0)
#define  VDE_VC_DMA_TIMER_write_enable1_mask                                     (0x00000020)
#define  VDE_VC_DMA_TIMER_delay_timer_mask                                       (0x0000001F)
#define  VDE_VC_DMA_TIMER_write_enable1(data)                                    (0x00000020&((data)<<5))
#define  VDE_VC_DMA_TIMER_delay_timer(data)                                      (0x0000001F&(data))
#define  VDE_VC_DMA_TIMER_get_write_enable1(data)                                ((0x00000020&(data))>>5)
#define  VDE_VC_DMA_TIMER_get_delay_timer(data)                                  (0x0000001F&(data))

#define  VDE_VC_SLEEP_CTRL                                                       0x18001088
#define  VDE_VC_SLEEP_CTRL_reg_addr                                              "0xB8001088"
#define  VDE_VC_SLEEP_CTRL_reg                                                   0xB8001088
#define  VDE_VC_SLEEP_CTRL_inst_addr                                             "0x002E"
#define  set_VDE_VC_SLEEP_CTRL_reg(data)                                         (*((volatile unsigned int*)VDE_VC_SLEEP_CTRL_reg)=data)
#define  get_VDE_VC_SLEEP_CTRL_reg                                               (*((volatile unsigned int*)VDE_VC_SLEEP_CTRL_reg))
#define  VDE_VC_SLEEP_CTRL_ext_sleepreq_r_shift                                  (0)
#define  VDE_VC_SLEEP_CTRL_ext_sleepreq_r_mask                                   (0x00000001)
#define  VDE_VC_SLEEP_CTRL_ext_sleepreq_r(data)                                  (0x00000001&(data))
#define  VDE_VC_SLEEP_CTRL_get_ext_sleepreq_r(data)                              (0x00000001&(data))

#define  VDE_VC_SLEEP_STATUS                                                     0x1800108C
#define  VDE_VC_SLEEP_STATUS_reg_addr                                            "0xB800108C"
#define  VDE_VC_SLEEP_STATUS_reg                                                 0xB800108C
#define  VDE_VC_SLEEP_STATUS_inst_addr                                           "0x002F"
#define  set_VDE_VC_SLEEP_STATUS_reg(data)                                       (*((volatile unsigned int*)VDE_VC_SLEEP_STATUS_reg)=data)
#define  get_VDE_VC_SLEEP_STATUS_reg                                             (*((volatile unsigned int*)VDE_VC_SLEEP_STATUS_reg))
#define  VDE_VC_SLEEP_STATUS_sl_sleepsys_r_shift                                 (0)
#define  VDE_VC_SLEEP_STATUS_sl_sleepsys_r_mask                                  (0x00000001)
#define  VDE_VC_SLEEP_STATUS_sl_sleepsys_r(data)                                 (0x00000001&(data))
#define  VDE_VC_SLEEP_STATUS_get_sl_sleepsys_r(data)                             (0x00000001&(data))

#define  VDE_VC_DMA_bist_rm                                                      0x180010D0
#define  VDE_VC_DMA_bist_rm_reg_addr                                             "0xB80010D0"
#define  VDE_VC_DMA_bist_rm_reg                                                  0xB80010D0
#define  VDE_VC_DMA_bist_rm_inst_addr                                            "0x0030"
#define  set_VDE_VC_DMA_bist_rm_reg(data)                                        (*((volatile unsigned int*)VDE_VC_DMA_bist_rm_reg)=data)
#define  get_VDE_VC_DMA_bist_rm_reg                                              (*((volatile unsigned int*)VDE_VC_DMA_bist_rm_reg))
#define  VDE_VC_DMA_bist_rm_ls_shift                                             (13)
#define  VDE_VC_DMA_bist_rm_rmea_shift                                           (12)
#define  VDE_VC_DMA_bist_rm_rma_3_shift                                          (11)
#define  VDE_VC_DMA_bist_rm_rma_2_shift                                          (10)
#define  VDE_VC_DMA_bist_rm_rma_1_shift                                          (9)
#define  VDE_VC_DMA_bist_rm_rma_0_shift                                          (8)
#define  VDE_VC_DMA_bist_rm_rmeb_shift                                           (4)
#define  VDE_VC_DMA_bist_rm_rmb_3_shift                                          (3)
#define  VDE_VC_DMA_bist_rm_rmb_2_shift                                          (2)
#define  VDE_VC_DMA_bist_rm_rmb_1_shift                                          (1)
#define  VDE_VC_DMA_bist_rm_rmb_0_shift                                          (0)
#define  VDE_VC_DMA_bist_rm_ls_mask                                              (0x00002000)
#define  VDE_VC_DMA_bist_rm_rmea_mask                                            (0x00001000)
#define  VDE_VC_DMA_bist_rm_rma_3_mask                                           (0x00000800)
#define  VDE_VC_DMA_bist_rm_rma_2_mask                                           (0x00000400)
#define  VDE_VC_DMA_bist_rm_rma_1_mask                                           (0x00000200)
#define  VDE_VC_DMA_bist_rm_rma_0_mask                                           (0x00000100)
#define  VDE_VC_DMA_bist_rm_rmeb_mask                                            (0x00000010)
#define  VDE_VC_DMA_bist_rm_rmb_3_mask                                           (0x00000008)
#define  VDE_VC_DMA_bist_rm_rmb_2_mask                                           (0x00000004)
#define  VDE_VC_DMA_bist_rm_rmb_1_mask                                           (0x00000002)
#define  VDE_VC_DMA_bist_rm_rmb_0_mask                                           (0x00000001)
#define  VDE_VC_DMA_bist_rm_ls(data)                                             (0x00002000&((data)<<13))
#define  VDE_VC_DMA_bist_rm_rmea(data)                                           (0x00001000&((data)<<12))
#define  VDE_VC_DMA_bist_rm_rma_3(data)                                          (0x00000800&((data)<<11))
#define  VDE_VC_DMA_bist_rm_rma_2(data)                                          (0x00000400&((data)<<10))
#define  VDE_VC_DMA_bist_rm_rma_1(data)                                          (0x00000200&((data)<<9))
#define  VDE_VC_DMA_bist_rm_rma_0(data)                                          (0x00000100&((data)<<8))
#define  VDE_VC_DMA_bist_rm_rmeb(data)                                           (0x00000010&((data)<<4))
#define  VDE_VC_DMA_bist_rm_rmb_3(data)                                          (0x00000008&((data)<<3))
#define  VDE_VC_DMA_bist_rm_rmb_2(data)                                          (0x00000004&((data)<<2))
#define  VDE_VC_DMA_bist_rm_rmb_1(data)                                          (0x00000002&((data)<<1))
#define  VDE_VC_DMA_bist_rm_rmb_0(data)                                          (0x00000001&(data))
#define  VDE_VC_DMA_bist_rm_get_ls(data)                                         ((0x00002000&(data))>>13)
#define  VDE_VC_DMA_bist_rm_get_rmea(data)                                       ((0x00001000&(data))>>12)
#define  VDE_VC_DMA_bist_rm_get_rma_3(data)                                      ((0x00000800&(data))>>11)
#define  VDE_VC_DMA_bist_rm_get_rma_2(data)                                      ((0x00000400&(data))>>10)
#define  VDE_VC_DMA_bist_rm_get_rma_1(data)                                      ((0x00000200&(data))>>9)
#define  VDE_VC_DMA_bist_rm_get_rma_0(data)                                      ((0x00000100&(data))>>8)
#define  VDE_VC_DMA_bist_rm_get_rmeb(data)                                       ((0x00000010&(data))>>4)
#define  VDE_VC_DMA_bist_rm_get_rmb_3(data)                                      ((0x00000008&(data))>>3)
#define  VDE_VC_DMA_bist_rm_get_rmb_2(data)                                      ((0x00000004&(data))>>2)
#define  VDE_VC_DMA_bist_rm_get_rmb_1(data)                                      ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_bist_rm_get_rmb_0(data)                                      (0x00000001&(data))

#define  VDE_mbist_vcpu_rm                                                       0x180010D4
#define  VDE_mbist_vcpu_rm_reg_addr                                              "0xB80010D4"
#define  VDE_mbist_vcpu_rm_reg                                                   0xB80010D4
#define  VDE_mbist_vcpu_rm_inst_addr                                             "0x0031"
#define  set_VDE_mbist_vcpu_rm_reg(data)                                         (*((volatile unsigned int*)VDE_mbist_vcpu_rm_reg)=data)
#define  get_VDE_mbist_vcpu_rm_reg                                               (*((volatile unsigned int*)VDE_mbist_vcpu_rm_reg))
#define  VDE_mbist_vcpu_rm_ls_shift                                              (29)
#define  VDE_mbist_vcpu_rm_rme_vcpu_shift                                        (28)
#define  VDE_mbist_vcpu_rm_rm_dc_data_shift                                      (24)
#define  VDE_mbist_vcpu_rm_rm_dc_tag_shift                                       (20)
#define  VDE_mbist_vcpu_rm_rm_dw_data_shift                                      (16)
#define  VDE_mbist_vcpu_rm_rm_ic_data1_shift                                     (12)
#define  VDE_mbist_vcpu_rm_rm_ic_data0_shift                                     (8)
#define  VDE_mbist_vcpu_rm_rm_ic_tag1_shift                                      (4)
#define  VDE_mbist_vcpu_rm_rm_ic_tag0_shift                                      (0)
#define  VDE_mbist_vcpu_rm_ls_mask                                               (0x20000000)
#define  VDE_mbist_vcpu_rm_rme_vcpu_mask                                         (0x10000000)
#define  VDE_mbist_vcpu_rm_rm_dc_data_mask                                       (0x0F000000)
#define  VDE_mbist_vcpu_rm_rm_dc_tag_mask                                        (0x00F00000)
#define  VDE_mbist_vcpu_rm_rm_dw_data_mask                                       (0x000F0000)
#define  VDE_mbist_vcpu_rm_rm_ic_data1_mask                                      (0x0000F000)
#define  VDE_mbist_vcpu_rm_rm_ic_data0_mask                                      (0x00000F00)
#define  VDE_mbist_vcpu_rm_rm_ic_tag1_mask                                       (0x000000F0)
#define  VDE_mbist_vcpu_rm_rm_ic_tag0_mask                                       (0x0000000F)
#define  VDE_mbist_vcpu_rm_ls(data)                                              (0x20000000&((data)<<29))
#define  VDE_mbist_vcpu_rm_rme_vcpu(data)                                        (0x10000000&((data)<<28))
#define  VDE_mbist_vcpu_rm_rm_dc_data(data)                                      (0x0F000000&((data)<<24))
#define  VDE_mbist_vcpu_rm_rm_dc_tag(data)                                       (0x00F00000&((data)<<20))
#define  VDE_mbist_vcpu_rm_rm_dw_data(data)                                      (0x000F0000&((data)<<16))
#define  VDE_mbist_vcpu_rm_rm_ic_data1(data)                                     (0x0000F000&((data)<<12))
#define  VDE_mbist_vcpu_rm_rm_ic_data0(data)                                     (0x00000F00&((data)<<8))
#define  VDE_mbist_vcpu_rm_rm_ic_tag1(data)                                      (0x000000F0&((data)<<4))
#define  VDE_mbist_vcpu_rm_rm_ic_tag0(data)                                      (0x0000000F&(data))
#define  VDE_mbist_vcpu_rm_get_ls(data)                                          ((0x20000000&(data))>>29)
#define  VDE_mbist_vcpu_rm_get_rme_vcpu(data)                                    ((0x10000000&(data))>>28)
#define  VDE_mbist_vcpu_rm_get_rm_dc_data(data)                                  ((0x0F000000&(data))>>24)
#define  VDE_mbist_vcpu_rm_get_rm_dc_tag(data)                                   ((0x00F00000&(data))>>20)
#define  VDE_mbist_vcpu_rm_get_rm_dw_data(data)                                  ((0x000F0000&(data))>>16)
#define  VDE_mbist_vcpu_rm_get_rm_ic_data1(data)                                 ((0x0000F000&(data))>>12)
#define  VDE_mbist_vcpu_rm_get_rm_ic_data0(data)                                 ((0x00000F00&(data))>>8)
#define  VDE_mbist_vcpu_rm_get_rm_ic_tag1(data)                                  ((0x000000F0&(data))>>4)
#define  VDE_mbist_vcpu_rm_get_rm_ic_tag0(data)                                  (0x0000000F&(data))

#define  VDE_VC_DMA_bist_mode                                                    0x180010D8
#define  VDE_VC_DMA_bist_mode_reg_addr                                           "0xB80010D8"
#define  VDE_VC_DMA_bist_mode_reg                                                0xB80010D8
#define  VDE_VC_DMA_bist_mode_inst_addr                                          "0x0032"
#define  set_VDE_VC_DMA_bist_mode_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_bist_mode_reg)=data)
#define  get_VDE_VC_DMA_bist_mode_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_bist_mode_reg))
#define  VDE_VC_DMA_bist_mode_vde_bist_mode_shift                                (1)
#define  VDE_VC_DMA_bist_mode_vcpu_bist_mode_shift                               (0)
#define  VDE_VC_DMA_bist_mode_vde_bist_mode_mask                                 (0x00000002)
#define  VDE_VC_DMA_bist_mode_vcpu_bist_mode_mask                                (0x00000001)
#define  VDE_VC_DMA_bist_mode_vde_bist_mode(data)                                (0x00000002&((data)<<1))
#define  VDE_VC_DMA_bist_mode_vcpu_bist_mode(data)                               (0x00000001&(data))
#define  VDE_VC_DMA_bist_mode_get_vde_bist_mode(data)                            ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_bist_mode_get_vcpu_bist_mode(data)                           (0x00000001&(data))

#define  VDE_VC_DMA_bist_done                                                    0x180010DC
#define  VDE_VC_DMA_bist_done_reg_addr                                           "0xB80010DC"
#define  VDE_VC_DMA_bist_done_reg                                                0xB80010DC
#define  VDE_VC_DMA_bist_done_inst_addr                                          "0x0033"
#define  set_VDE_VC_DMA_bist_done_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_bist_done_reg)=data)
#define  get_VDE_VC_DMA_bist_done_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_bist_done_reg))
#define  VDE_VC_DMA_bist_done_vde_bist_done_shift                                (1)
#define  VDE_VC_DMA_bist_done_vcpu_bist_done_shift                               (0)
#define  VDE_VC_DMA_bist_done_vde_bist_done_mask                                 (0x00000002)
#define  VDE_VC_DMA_bist_done_vcpu_bist_done_mask                                (0x00000001)
#define  VDE_VC_DMA_bist_done_vde_bist_done(data)                                (0x00000002&((data)<<1))
#define  VDE_VC_DMA_bist_done_vcpu_bist_done(data)                               (0x00000001&(data))
#define  VDE_VC_DMA_bist_done_get_vde_bist_done(data)                            ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_bist_done_get_vcpu_bist_done(data)                           (0x00000001&(data))

#define  VDE_VC_DMA_bist_fail_group                                              0x180010E0
#define  VDE_VC_DMA_bist_fail_group_reg_addr                                     "0xB80010E0"
#define  VDE_VC_DMA_bist_fail_group_reg                                          0xB80010E0
#define  VDE_VC_DMA_bist_fail_group_inst_addr                                    "0x0034"
#define  set_VDE_VC_DMA_bist_fail_group_reg(data)                                (*((volatile unsigned int*)VDE_VC_DMA_bist_fail_group_reg)=data)
#define  get_VDE_VC_DMA_bist_fail_group_reg                                      (*((volatile unsigned int*)VDE_VC_DMA_bist_fail_group_reg))
#define  VDE_VC_DMA_bist_fail_group_vde_bist_fail_group_shift                    (1)
#define  VDE_VC_DMA_bist_fail_group_vcpu_bist_fail_group_shift                   (0)
#define  VDE_VC_DMA_bist_fail_group_vde_bist_fail_group_mask                     (0x00000002)
#define  VDE_VC_DMA_bist_fail_group_vcpu_bist_fail_group_mask                    (0x00000001)
#define  VDE_VC_DMA_bist_fail_group_vde_bist_fail_group(data)                    (0x00000002&((data)<<1))
#define  VDE_VC_DMA_bist_fail_group_vcpu_bist_fail_group(data)                   (0x00000001&(data))
#define  VDE_VC_DMA_bist_fail_group_get_vde_bist_fail_group(data)                ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_bist_fail_group_get_vcpu_bist_fail_group(data)               (0x00000001&(data))

#define  VDE_VC_DMA_vde_bist_fail                                                0x180010E4
#define  VDE_VC_DMA_vde_bist_fail_reg_addr                                       "0xB80010E4"
#define  VDE_VC_DMA_vde_bist_fail_reg                                            0xB80010E4
#define  VDE_VC_DMA_vde_bist_fail_inst_addr                                      "0x0035"
#define  set_VDE_VC_DMA_vde_bist_fail_reg(data)                                  (*((volatile unsigned int*)VDE_VC_DMA_vde_bist_fail_reg)=data)
#define  get_VDE_VC_DMA_vde_bist_fail_reg                                        (*((volatile unsigned int*)VDE_VC_DMA_vde_bist_fail_reg))
#define  VDE_VC_DMA_vde_bist_fail_vde_bist_fail0_shift                           (0)
#define  VDE_VC_DMA_vde_bist_fail_vde_bist_fail0_mask                            (0x00000001)
#define  VDE_VC_DMA_vde_bist_fail_vde_bist_fail0(data)                           (0x00000001&(data))
#define  VDE_VC_DMA_vde_bist_fail_get_vde_bist_fail0(data)                       (0x00000001&(data))

#define  VDE_VC_DMA_vcpu_bist_fail                                               0x180010E8
#define  VDE_VC_DMA_vcpu_bist_fail_reg_addr                                      "0xB80010E8"
#define  VDE_VC_DMA_vcpu_bist_fail_reg                                           0xB80010E8
#define  VDE_VC_DMA_vcpu_bist_fail_inst_addr                                     "0x0036"
#define  set_VDE_VC_DMA_vcpu_bist_fail_reg(data)                                 (*((volatile unsigned int*)VDE_VC_DMA_vcpu_bist_fail_reg)=data)
#define  get_VDE_VC_DMA_vcpu_bist_fail_reg                                       (*((volatile unsigned int*)VDE_VC_DMA_vcpu_bist_fail_reg))
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail5_shift                         (5)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail4_shift                         (4)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail3_shift                         (3)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail2_shift                         (2)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail1_shift                         (1)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail0_shift                         (0)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail5_mask                          (0x00000020)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail4_mask                          (0x00000010)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail3_mask                          (0x00000008)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail2_mask                          (0x00000004)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail1_mask                          (0x00000002)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail0_mask                          (0x00000001)
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail5(data)                         (0x00000020&((data)<<5))
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail4(data)                         (0x00000010&((data)<<4))
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail3(data)                         (0x00000008&((data)<<3))
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail2(data)                         (0x00000004&((data)<<2))
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail1(data)                         (0x00000002&((data)<<1))
#define  VDE_VC_DMA_vcpu_bist_fail_vcpu_bist_fail0(data)                         (0x00000001&(data))
#define  VDE_VC_DMA_vcpu_bist_fail_get_vcpu_bist_fail5(data)                     ((0x00000020&(data))>>5)
#define  VDE_VC_DMA_vcpu_bist_fail_get_vcpu_bist_fail4(data)                     ((0x00000010&(data))>>4)
#define  VDE_VC_DMA_vcpu_bist_fail_get_vcpu_bist_fail3(data)                     ((0x00000008&(data))>>3)
#define  VDE_VC_DMA_vcpu_bist_fail_get_vcpu_bist_fail2(data)                     ((0x00000004&(data))>>2)
#define  VDE_VC_DMA_vcpu_bist_fail_get_vcpu_bist_fail1(data)                     ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_vcpu_bist_fail_get_vcpu_bist_fail0(data)                     (0x00000001&(data))

#define  VDE_VC_DMA_drf_mode                                                     0x180010EC
#define  VDE_VC_DMA_drf_mode_reg_addr                                            "0xB80010EC"
#define  VDE_VC_DMA_drf_mode_reg                                                 0xB80010EC
#define  VDE_VC_DMA_drf_mode_inst_addr                                           "0x0037"
#define  set_VDE_VC_DMA_drf_mode_reg(data)                                       (*((volatile unsigned int*)VDE_VC_DMA_drf_mode_reg)=data)
#define  get_VDE_VC_DMA_drf_mode_reg                                             (*((volatile unsigned int*)VDE_VC_DMA_drf_mode_reg))
#define  VDE_VC_DMA_drf_mode_vde_drf_mode_shift                                  (1)
#define  VDE_VC_DMA_drf_mode_vcpu_drf_mode_shift                                 (0)
#define  VDE_VC_DMA_drf_mode_vde_drf_mode_mask                                   (0x00000002)
#define  VDE_VC_DMA_drf_mode_vcpu_drf_mode_mask                                  (0x00000001)
#define  VDE_VC_DMA_drf_mode_vde_drf_mode(data)                                  (0x00000002&((data)<<1))
#define  VDE_VC_DMA_drf_mode_vcpu_drf_mode(data)                                 (0x00000001&(data))
#define  VDE_VC_DMA_drf_mode_get_vde_drf_mode(data)                              ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_drf_mode_get_vcpu_drf_mode(data)                             (0x00000001&(data))

#define  VDE_VC_DMA_drf_resume                                                   0x180010F0
#define  VDE_VC_DMA_drf_resume_reg_addr                                          "0xB80010F0"
#define  VDE_VC_DMA_drf_resume_reg                                               0xB80010F0
#define  VDE_VC_DMA_drf_resume_inst_addr                                         "0x0038"
#define  set_VDE_VC_DMA_drf_resume_reg(data)                                     (*((volatile unsigned int*)VDE_VC_DMA_drf_resume_reg)=data)
#define  get_VDE_VC_DMA_drf_resume_reg                                           (*((volatile unsigned int*)VDE_VC_DMA_drf_resume_reg))
#define  VDE_VC_DMA_drf_resume_vde_drf_resume_shift                              (1)
#define  VDE_VC_DMA_drf_resume_vcpu_drf_resume_shift                             (0)
#define  VDE_VC_DMA_drf_resume_vde_drf_resume_mask                               (0x00000002)
#define  VDE_VC_DMA_drf_resume_vcpu_drf_resume_mask                              (0x00000001)
#define  VDE_VC_DMA_drf_resume_vde_drf_resume(data)                              (0x00000002&((data)<<1))
#define  VDE_VC_DMA_drf_resume_vcpu_drf_resume(data)                             (0x00000001&(data))
#define  VDE_VC_DMA_drf_resume_get_vde_drf_resume(data)                          ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_drf_resume_get_vcpu_drf_resume(data)                         (0x00000001&(data))

#define  VDE_VC_DMA_drf_done                                                     0x180010F4
#define  VDE_VC_DMA_drf_done_reg_addr                                            "0xB80010F4"
#define  VDE_VC_DMA_drf_done_reg                                                 0xB80010F4
#define  VDE_VC_DMA_drf_done_inst_addr                                           "0x0039"
#define  set_VDE_VC_DMA_drf_done_reg(data)                                       (*((volatile unsigned int*)VDE_VC_DMA_drf_done_reg)=data)
#define  get_VDE_VC_DMA_drf_done_reg                                             (*((volatile unsigned int*)VDE_VC_DMA_drf_done_reg))
#define  VDE_VC_DMA_drf_done_vde_drf_done_shift                                  (1)
#define  VDE_VC_DMA_drf_done_vcpu_drf_done_shift                                 (0)
#define  VDE_VC_DMA_drf_done_vde_drf_done_mask                                   (0x00000002)
#define  VDE_VC_DMA_drf_done_vcpu_drf_done_mask                                  (0x00000001)
#define  VDE_VC_DMA_drf_done_vde_drf_done(data)                                  (0x00000002&((data)<<1))
#define  VDE_VC_DMA_drf_done_vcpu_drf_done(data)                                 (0x00000001&(data))
#define  VDE_VC_DMA_drf_done_get_vde_drf_done(data)                              ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_drf_done_get_vcpu_drf_done(data)                             (0x00000001&(data))

#define  VDE_VC_DMA_drf_pause                                                    0x180010F8
#define  VDE_VC_DMA_drf_pause_reg_addr                                           "0xB80010F8"
#define  VDE_VC_DMA_drf_pause_reg                                                0xB80010F8
#define  VDE_VC_DMA_drf_pause_inst_addr                                          "0x003A"
#define  set_VDE_VC_DMA_drf_pause_reg(data)                                      (*((volatile unsigned int*)VDE_VC_DMA_drf_pause_reg)=data)
#define  get_VDE_VC_DMA_drf_pause_reg                                            (*((volatile unsigned int*)VDE_VC_DMA_drf_pause_reg))
#define  VDE_VC_DMA_drf_pause_vde_drf_pause_shift                                (1)
#define  VDE_VC_DMA_drf_pause_vcpu_drf_pause_shift                               (0)
#define  VDE_VC_DMA_drf_pause_vde_drf_pause_mask                                 (0x00000002)
#define  VDE_VC_DMA_drf_pause_vcpu_drf_pause_mask                                (0x00000001)
#define  VDE_VC_DMA_drf_pause_vde_drf_pause(data)                                (0x00000002&((data)<<1))
#define  VDE_VC_DMA_drf_pause_vcpu_drf_pause(data)                               (0x00000001&(data))
#define  VDE_VC_DMA_drf_pause_get_vde_drf_pause(data)                            ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_drf_pause_get_vcpu_drf_pause(data)                           (0x00000001&(data))

#define  VDE_VC_DMA_drf_fail_group                                               0x180010FC
#define  VDE_VC_DMA_drf_fail_group_reg_addr                                      "0xB80010FC"
#define  VDE_VC_DMA_drf_fail_group_reg                                           0xB80010FC
#define  VDE_VC_DMA_drf_fail_group_inst_addr                                     "0x003B"
#define  set_VDE_VC_DMA_drf_fail_group_reg(data)                                 (*((volatile unsigned int*)VDE_VC_DMA_drf_fail_group_reg)=data)
#define  get_VDE_VC_DMA_drf_fail_group_reg                                       (*((volatile unsigned int*)VDE_VC_DMA_drf_fail_group_reg))
#define  VDE_VC_DMA_drf_fail_group_vde_drf_fail_group_shift                      (1)
#define  VDE_VC_DMA_drf_fail_group_vcpu_drf_fail_group_shift                     (0)
#define  VDE_VC_DMA_drf_fail_group_vde_drf_fail_group_mask                       (0x00000002)
#define  VDE_VC_DMA_drf_fail_group_vcpu_drf_fail_group_mask                      (0x00000001)
#define  VDE_VC_DMA_drf_fail_group_vde_drf_fail_group(data)                      (0x00000002&((data)<<1))
#define  VDE_VC_DMA_drf_fail_group_vcpu_drf_fail_group(data)                     (0x00000001&(data))
#define  VDE_VC_DMA_drf_fail_group_get_vde_drf_fail_group(data)                  ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_drf_fail_group_get_vcpu_drf_fail_group(data)                 (0x00000001&(data))

#define  VDE_VC_DMA_vde_drf_bist_fail                                            0x18001100
#define  VDE_VC_DMA_vde_drf_bist_fail_reg_addr                                   "0xB8001100"
#define  VDE_VC_DMA_vde_drf_bist_fail_reg                                        0xB8001100
#define  VDE_VC_DMA_vde_drf_bist_fail_inst_addr                                  "0x003C"
#define  set_VDE_VC_DMA_vde_drf_bist_fail_reg(data)                              (*((volatile unsigned int*)VDE_VC_DMA_vde_drf_bist_fail_reg)=data)
#define  get_VDE_VC_DMA_vde_drf_bist_fail_reg                                    (*((volatile unsigned int*)VDE_VC_DMA_vde_drf_bist_fail_reg))
#define  VDE_VC_DMA_vde_drf_bist_fail_vde_drf_bist_fail0_shift                   (0)
#define  VDE_VC_DMA_vde_drf_bist_fail_vde_drf_bist_fail0_mask                    (0x00000001)
#define  VDE_VC_DMA_vde_drf_bist_fail_vde_drf_bist_fail0(data)                   (0x00000001&(data))
#define  VDE_VC_DMA_vde_drf_bist_fail_get_vde_drf_bist_fail0(data)               (0x00000001&(data))

#define  VDE_VC_DMA_vcpu_drf_bist_fail1                                          0x18001104
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_reg_addr                                 "0xB8001104"
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_reg                                      0xB8001104
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_inst_addr                                "0x003D"
#define  set_VDE_VC_DMA_vcpu_drf_bist_fail1_reg(data)                            (*((volatile unsigned int*)VDE_VC_DMA_vcpu_drf_bist_fail1_reg)=data)
#define  get_VDE_VC_DMA_vcpu_drf_bist_fail1_reg                                  (*((volatile unsigned int*)VDE_VC_DMA_vcpu_drf_bist_fail1_reg))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail5_shift                (5)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail4_shift                (4)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail3_shift                (3)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail2_shift                (2)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail1_shift                (1)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail0_shift                (0)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail5_mask                 (0x00000020)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail4_mask                 (0x00000010)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail3_mask                 (0x00000008)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail2_mask                 (0x00000004)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail1_mask                 (0x00000002)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail0_mask                 (0x00000001)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail5(data)                (0x00000020&((data)<<5))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail4(data)                (0x00000010&((data)<<4))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail3(data)                (0x00000008&((data)<<3))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail2(data)                (0x00000004&((data)<<2))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail1(data)                (0x00000002&((data)<<1))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_vcpu_drf_bist_fail0(data)                (0x00000001&(data))
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_get_vcpu_drf_bist_fail5(data)            ((0x00000020&(data))>>5)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_get_vcpu_drf_bist_fail4(data)            ((0x00000010&(data))>>4)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_get_vcpu_drf_bist_fail3(data)            ((0x00000008&(data))>>3)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_get_vcpu_drf_bist_fail2(data)            ((0x00000004&(data))>>2)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_get_vcpu_drf_bist_fail1(data)            ((0x00000002&(data))>>1)
#define  VDE_VC_DMA_vcpu_drf_bist_fail1_get_vcpu_drf_bist_fail0(data)            (0x00000001&(data))

#define  VDE_VCPU_bisr_en                                                        0x18001110
#define  VDE_VCPU_bisr_en_reg_addr                                               "0xB8001110"
#define  VDE_VCPU_bisr_en_reg                                                    0xB8001110
#define  VDE_VCPU_bisr_en_inst_addr                                              "0x003E"
#define  set_VDE_VCPU_bisr_en_reg(data)                                          (*((volatile unsigned int*)VDE_VCPU_bisr_en_reg)=data)
#define  get_VDE_VCPU_bisr_en_reg                                                (*((volatile unsigned int*)VDE_VCPU_bisr_en_reg))
#define  VDE_VCPU_bisr_en_vcpu_bisr_second_run_en_shift                          (0)
#define  VDE_VCPU_bisr_en_vcpu_bisr_second_run_en_mask                           (0x00000001)
#define  VDE_VCPU_bisr_en_vcpu_bisr_second_run_en(data)                          (0x00000001&(data))
#define  VDE_VCPU_bisr_en_get_vcpu_bisr_second_run_en(data)                      (0x00000001&(data))

#define  VDE_VCPU_bisr_fail_g                                                    0x18001114
#define  VDE_VCPU_bisr_fail_g_reg_addr                                           "0xB8001114"
#define  VDE_VCPU_bisr_fail_g_reg                                                0xB8001114
#define  VDE_VCPU_bisr_fail_g_inst_addr                                          "0x003F"
#define  set_VDE_VCPU_bisr_fail_g_reg(data)                                      (*((volatile unsigned int*)VDE_VCPU_bisr_fail_g_reg)=data)
#define  get_VDE_VCPU_bisr_fail_g_reg                                            (*((volatile unsigned int*)VDE_VCPU_bisr_fail_g_reg))
#define  VDE_VCPU_bisr_fail_g_vcpu_bisr_fail_group_shift                         (0)
#define  VDE_VCPU_bisr_fail_g_vcpu_bisr_fail_group_mask                          (0x00000001)
#define  VDE_VCPU_bisr_fail_g_vcpu_bisr_fail_group(data)                         (0x00000001&(data))
#define  VDE_VCPU_bisr_fail_g_get_vcpu_bisr_fail_group(data)                     (0x00000001&(data))

#define  VDE_VCPU_bisr_fail                                                      0x18001118
#define  VDE_VCPU_bisr_fail_reg_addr                                             "0xB8001118"
#define  VDE_VCPU_bisr_fail_reg                                                  0xB8001118
#define  VDE_VCPU_bisr_fail_inst_addr                                            "0x0040"
#define  set_VDE_VCPU_bisr_fail_reg(data)                                        (*((volatile unsigned int*)VDE_VCPU_bisr_fail_reg)=data)
#define  get_VDE_VCPU_bisr_fail_reg                                              (*((volatile unsigned int*)VDE_VCPU_bisr_fail_reg))
#define  VDE_VCPU_bisr_fail_vcpu_bisr_fail_0_shift                               (0)
#define  VDE_VCPU_bisr_fail_vcpu_bisr_fail_0_mask                                (0x00000001)
#define  VDE_VCPU_bisr_fail_vcpu_bisr_fail_0(data)                               (0x00000001&(data))
#define  VDE_VCPU_bisr_fail_get_vcpu_bisr_fail_0(data)                           (0x00000001&(data))

#define  VDE_VCPU_bisr_drf_en                                                    0x18001120
#define  VDE_VCPU_bisr_drf_en_reg_addr                                           "0xB8001120"
#define  VDE_VCPU_bisr_drf_en_reg                                                0xB8001120
#define  VDE_VCPU_bisr_drf_en_inst_addr                                          "0x0041"
#define  set_VDE_VCPU_bisr_drf_en_reg(data)                                      (*((volatile unsigned int*)VDE_VCPU_bisr_drf_en_reg)=data)
#define  get_VDE_VCPU_bisr_drf_en_reg                                            (*((volatile unsigned int*)VDE_VCPU_bisr_drf_en_reg))
#define  VDE_VCPU_bisr_drf_en_vcpu_bisr_drf_mode_shift                           (0)
#define  VDE_VCPU_bisr_drf_en_vcpu_bisr_drf_mode_mask                            (0x00000001)
#define  VDE_VCPU_bisr_drf_en_vcpu_bisr_drf_mode(data)                           (0x00000001&(data))
#define  VDE_VCPU_bisr_drf_en_get_vcpu_bisr_drf_mode(data)                       (0x00000001&(data))

#define  VDE_VCPU_bisr_drf_resume                                                0x18001124
#define  VDE_VCPU_bisr_drf_resume_reg_addr                                       "0xB8001124"
#define  VDE_VCPU_bisr_drf_resume_reg                                            0xB8001124
#define  VDE_VCPU_bisr_drf_resume_inst_addr                                      "0x0042"
#define  set_VDE_VCPU_bisr_drf_resume_reg(data)                                  (*((volatile unsigned int*)VDE_VCPU_bisr_drf_resume_reg)=data)
#define  get_VDE_VCPU_bisr_drf_resume_reg                                        (*((volatile unsigned int*)VDE_VCPU_bisr_drf_resume_reg))
#define  VDE_VCPU_bisr_drf_resume_vcpu_bisr_drf_resume_shift                     (0)
#define  VDE_VCPU_bisr_drf_resume_vcpu_bisr_drf_resume_mask                      (0x00000001)
#define  VDE_VCPU_bisr_drf_resume_vcpu_bisr_drf_resume(data)                     (0x00000001&(data))
#define  VDE_VCPU_bisr_drf_resume_get_vcpu_bisr_drf_resume(data)                 (0x00000001&(data))

#define  VDE_VCPU_bisr_drf_done                                                  0x18001128
#define  VDE_VCPU_bisr_drf_done_reg_addr                                         "0xB8001128"
#define  VDE_VCPU_bisr_drf_done_reg                                              0xB8001128
#define  VDE_VCPU_bisr_drf_done_inst_addr                                        "0x0043"
#define  set_VDE_VCPU_bisr_drf_done_reg(data)                                    (*((volatile unsigned int*)VDE_VCPU_bisr_drf_done_reg)=data)
#define  get_VDE_VCPU_bisr_drf_done_reg                                          (*((volatile unsigned int*)VDE_VCPU_bisr_drf_done_reg))
#define  VDE_VCPU_bisr_drf_done_vcpu_bisr_drf_done_shift                         (0)
#define  VDE_VCPU_bisr_drf_done_vcpu_bisr_drf_done_mask                          (0x00000001)
#define  VDE_VCPU_bisr_drf_done_vcpu_bisr_drf_done(data)                         (0x00000001&(data))
#define  VDE_VCPU_bisr_drf_done_get_vcpu_bisr_drf_done(data)                     (0x00000001&(data))

#define  VDE_VCPU_bisr_drf_fail_g                                                0x1800112C
#define  VDE_VCPU_bisr_drf_fail_g_reg_addr                                       "0xB800112C"
#define  VDE_VCPU_bisr_drf_fail_g_reg                                            0xB800112C
#define  VDE_VCPU_bisr_drf_fail_g_inst_addr                                      "0x0044"
#define  set_VDE_VCPU_bisr_drf_fail_g_reg(data)                                  (*((volatile unsigned int*)VDE_VCPU_bisr_drf_fail_g_reg)=data)
#define  get_VDE_VCPU_bisr_drf_fail_g_reg                                        (*((volatile unsigned int*)VDE_VCPU_bisr_drf_fail_g_reg))
#define  VDE_VCPU_bisr_drf_fail_g_vcpu_bisr_drf_fail_group_shift                 (0)
#define  VDE_VCPU_bisr_drf_fail_g_vcpu_bisr_drf_fail_group_mask                  (0x00000001)
#define  VDE_VCPU_bisr_drf_fail_g_vcpu_bisr_drf_fail_group(data)                 (0x00000001&(data))
#define  VDE_VCPU_bisr_drf_fail_g_get_vcpu_bisr_drf_fail_group(data)             (0x00000001&(data))

#define  VDE_VCPU_bisr_drf_fail                                                  0x18001130
#define  VDE_VCPU_bisr_drf_fail_reg_addr                                         "0xB8001130"
#define  VDE_VCPU_bisr_drf_fail_reg                                              0xB8001130
#define  VDE_VCPU_bisr_drf_fail_inst_addr                                        "0x0045"
#define  set_VDE_VCPU_bisr_drf_fail_reg(data)                                    (*((volatile unsigned int*)VDE_VCPU_bisr_drf_fail_reg)=data)
#define  get_VDE_VCPU_bisr_drf_fail_reg                                          (*((volatile unsigned int*)VDE_VCPU_bisr_drf_fail_reg))
#define  VDE_VCPU_bisr_drf_fail_vcpu_bisr_repaired_shift                         (31)
#define  VDE_VCPU_bisr_drf_fail_vcpu_bisr_fail_0_shift                           (0)
#define  VDE_VCPU_bisr_drf_fail_vcpu_bisr_repaired_mask                          (0x80000000)
#define  VDE_VCPU_bisr_drf_fail_vcpu_bisr_fail_0_mask                            (0x00000001)
#define  VDE_VCPU_bisr_drf_fail_vcpu_bisr_repaired(data)                         (0x80000000&((data)<<31))
#define  VDE_VCPU_bisr_drf_fail_vcpu_bisr_fail_0(data)                           (0x00000001&(data))
#define  VDE_VCPU_bisr_drf_fail_get_vcpu_bisr_repaired(data)                     ((0x80000000&(data))>>31)
#define  VDE_VCPU_bisr_drf_fail_get_vcpu_bisr_fail_0(data)                       (0x00000001&(data))

#define  VDE_VCPU_bisr_drf_pause                                                 0x18001134
#define  VDE_VCPU_bisr_drf_pause_reg_addr                                        "0xB8001134"
#define  VDE_VCPU_bisr_drf_pause_reg                                             0xB8001134
#define  VDE_VCPU_bisr_drf_pause_inst_addr                                       "0x0046"
#define  set_VDE_VCPU_bisr_drf_pause_reg(data)                                   (*((volatile unsigned int*)VDE_VCPU_bisr_drf_pause_reg)=data)
#define  get_VDE_VCPU_bisr_drf_pause_reg                                         (*((volatile unsigned int*)VDE_VCPU_bisr_drf_pause_reg))
#define  VDE_VCPU_bisr_drf_pause_vcpu_bisr_drf_pause_shift                       (0)
#define  VDE_VCPU_bisr_drf_pause_vcpu_bisr_drf_pause_mask                        (0x00000001)
#define  VDE_VCPU_bisr_drf_pause_vcpu_bisr_drf_pause(data)                       (0x00000001&(data))
#define  VDE_VCPU_bisr_drf_pause_get_vcpu_bisr_drf_pause(data)                   (0x00000001&(data))

#define  VDE_VDE_SELF_TEST                                                       0x18001140
#define  VDE_VDE_SELF_TEST_reg_addr                                              "0xB8001140"
#define  VDE_VDE_SELF_TEST_reg                                                   0xB8001140
#define  VDE_VDE_SELF_TEST_inst_addr                                             "0x0047"
#define  set_VDE_VDE_SELF_TEST_reg(data)                                         (*((volatile unsigned int*)VDE_VDE_SELF_TEST_reg)=data)
#define  get_VDE_VDE_SELF_TEST_reg                                               (*((volatile unsigned int*)VDE_VDE_SELF_TEST_reg))
#define  VDE_VDE_SELF_TEST_sf_rx_mode_shift                                      (4)
#define  VDE_VDE_SELF_TEST_sf_rx_start_shift                                     (3)
#define  VDE_VDE_SELF_TEST_sf_rx_gated_shift                                     (2)
#define  VDE_VDE_SELF_TEST_sf_tx_mode_shift                                      (1)
#define  VDE_VDE_SELF_TEST_sf_tx_start_shift                                     (0)
#define  VDE_VDE_SELF_TEST_sf_rx_mode_mask                                       (0x00000010)
#define  VDE_VDE_SELF_TEST_sf_rx_start_mask                                      (0x00000008)
#define  VDE_VDE_SELF_TEST_sf_rx_gated_mask                                      (0x00000004)
#define  VDE_VDE_SELF_TEST_sf_tx_mode_mask                                       (0x00000002)
#define  VDE_VDE_SELF_TEST_sf_tx_start_mask                                      (0x00000001)
#define  VDE_VDE_SELF_TEST_sf_rx_mode(data)                                      (0x00000010&((data)<<4))
#define  VDE_VDE_SELF_TEST_sf_rx_start(data)                                     (0x00000008&((data)<<3))
#define  VDE_VDE_SELF_TEST_sf_rx_gated(data)                                     (0x00000004&((data)<<2))
#define  VDE_VDE_SELF_TEST_sf_tx_mode(data)                                      (0x00000002&((data)<<1))
#define  VDE_VDE_SELF_TEST_sf_tx_start(data)                                     (0x00000001&(data))
#define  VDE_VDE_SELF_TEST_get_sf_rx_mode(data)                                  ((0x00000010&(data))>>4)
#define  VDE_VDE_SELF_TEST_get_sf_rx_start(data)                                 ((0x00000008&(data))>>3)
#define  VDE_VDE_SELF_TEST_get_sf_rx_gated(data)                                 ((0x00000004&(data))>>2)
#define  VDE_VDE_SELF_TEST_get_sf_tx_mode(data)                                  ((0x00000002&(data))>>1)
#define  VDE_VDE_SELF_TEST_get_sf_tx_start(data)                                 (0x00000001&(data))

#define  VDE_VDE_SELF_TEST_RO                                                    0x18001144
#define  VDE_VDE_SELF_TEST_RO_reg_addr                                           "0xB8001144"
#define  VDE_VDE_SELF_TEST_RO_reg                                                0xB8001144
#define  VDE_VDE_SELF_TEST_RO_inst_addr                                          "0x0048"
#define  set_VDE_VDE_SELF_TEST_RO_reg(data)                                      (*((volatile unsigned int*)VDE_VDE_SELF_TEST_RO_reg)=data)
#define  get_VDE_VDE_SELF_TEST_RO_reg                                            (*((volatile unsigned int*)VDE_VDE_SELF_TEST_RO_reg))
#define  VDE_VDE_SELF_TEST_RO_sf_rx_done_ro_shift                                (2)
#define  VDE_VDE_SELF_TEST_RO_sf_rx_err_ro_shift                                 (1)
#define  VDE_VDE_SELF_TEST_RO_sf_tx_work_ro_shift                                (0)
#define  VDE_VDE_SELF_TEST_RO_sf_rx_done_ro_mask                                 (0x00000004)
#define  VDE_VDE_SELF_TEST_RO_sf_rx_err_ro_mask                                  (0x00000002)
#define  VDE_VDE_SELF_TEST_RO_sf_tx_work_ro_mask                                 (0x00000001)
#define  VDE_VDE_SELF_TEST_RO_sf_rx_done_ro(data)                                (0x00000004&((data)<<2))
#define  VDE_VDE_SELF_TEST_RO_sf_rx_err_ro(data)                                 (0x00000002&((data)<<1))
#define  VDE_VDE_SELF_TEST_RO_sf_tx_work_ro(data)                                (0x00000001&(data))
#define  VDE_VDE_SELF_TEST_RO_get_sf_rx_done_ro(data)                            ((0x00000004&(data))>>2)
#define  VDE_VDE_SELF_TEST_RO_get_sf_rx_err_ro(data)                             ((0x00000002&(data))>>1)
#define  VDE_VDE_SELF_TEST_RO_get_sf_tx_work_ro(data)                            (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VDE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src:29;
        RBus_UInt32  res1:3;
    };
}vde_vc_dma_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dst:29;
        RBus_UInt32  res1:3;
    };
}vde_vc_dma_dst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  valid:1;
        RBus_UInt32  dir:1;
        RBus_UInt32  size:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_type:1;
    };
}vde_vc_dma_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blk_h:6;
        RBus_UInt32  blk_w:4;
        RBus_UInt32  blk_y:12;
        RBus_UInt32  blk_x:10;
    };
}vde_vc_dma_blk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  field_mode:1;
        RBus_UInt32  pic_index:7;
        RBus_UInt32  chroma:1;
        RBus_UInt32  row_offset:5;
        RBus_UInt32  chroma_pitch:11;
    };
}vde_vc_dma_blkinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  max_xfer:6;
        RBus_UInt32  res2:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  dmem_req_en:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  go:1;
    };
}vde_vc_dma_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  int_done:1;
    };
}vde_vc_dma_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  int_done_en:1;
    };
}vde_vc_dma_int_en_RBUS;

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
}vde_vc_dma_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  sel1:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sel0:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  enable:1;
    };
}vde_vc_dma_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  delay_timer:5;
    };
}vde_vc_dma_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ext_sleepreq_r:1;
    };
}vde_vc_sleep_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  sl_sleepsys_r:1;
    };
}vde_vc_sleep_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ls:1;
        RBus_UInt32  rmea:1;
        RBus_UInt32  rma_3:1;
        RBus_UInt32  rma_2:1;
        RBus_UInt32  rma_1:1;
        RBus_UInt32  rma_0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rmeb:1;
        RBus_UInt32  rmb_3:1;
        RBus_UInt32  rmb_2:1;
        RBus_UInt32  rmb_1:1;
        RBus_UInt32  rmb_0:1;
    };
}vde_vc_dma_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ls:1;
        RBus_UInt32  rme_vcpu:1;
        RBus_UInt32  rm_dc_data:4;
        RBus_UInt32  rm_dc_tag:4;
        RBus_UInt32  rm_dw_data:4;
        RBus_UInt32  rm_ic_data1:4;
        RBus_UInt32  rm_ic_data0:4;
        RBus_UInt32  rm_ic_tag1:4;
        RBus_UInt32  rm_ic_tag0:4;
    };
}vde_mbist_vcpu_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_bist_mode:1;
        RBus_UInt32  vcpu_bist_mode:1;
    };
}vde_vc_dma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_bist_done:1;
        RBus_UInt32  vcpu_bist_done:1;
    };
}vde_vc_dma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_bist_fail_group:1;
        RBus_UInt32  vcpu_bist_fail_group:1;
    };
}vde_vc_dma_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vde_bist_fail0:1;
    };
}vde_vc_dma_vde_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vcpu_bist_fail5:1;
        RBus_UInt32  vcpu_bist_fail4:1;
        RBus_UInt32  vcpu_bist_fail3:1;
        RBus_UInt32  vcpu_bist_fail2:1;
        RBus_UInt32  vcpu_bist_fail1:1;
        RBus_UInt32  vcpu_bist_fail0:1;
    };
}vde_vc_dma_vcpu_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_drf_mode:1;
        RBus_UInt32  vcpu_drf_mode:1;
    };
}vde_vc_dma_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_drf_resume:1;
        RBus_UInt32  vcpu_drf_resume:1;
    };
}vde_vc_dma_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_drf_done:1;
        RBus_UInt32  vcpu_drf_done:1;
    };
}vde_vc_dma_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_drf_pause:1;
        RBus_UInt32  vcpu_drf_pause:1;
    };
}vde_vc_dma_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vde_drf_fail_group:1;
        RBus_UInt32  vcpu_drf_fail_group:1;
    };
}vde_vc_dma_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vde_drf_bist_fail0:1;
    };
}vde_vc_dma_vde_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vcpu_drf_bist_fail5:1;
        RBus_UInt32  vcpu_drf_bist_fail4:1;
        RBus_UInt32  vcpu_drf_bist_fail3:1;
        RBus_UInt32  vcpu_drf_bist_fail2:1;
        RBus_UInt32  vcpu_drf_bist_fail1:1;
        RBus_UInt32  vcpu_drf_bist_fail0:1;
    };
}vde_vc_dma_vcpu_drf_bist_fail1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_second_run_en:1;
    };
}vde_vcpu_bisr_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_fail_group:1;
    };
}vde_vcpu_bisr_fail_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_fail_0:1;
    };
}vde_vcpu_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_drf_mode:1;
    };
}vde_vcpu_bisr_drf_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_drf_resume:1;
    };
}vde_vcpu_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_drf_done:1;
    };
}vde_vcpu_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_drf_fail_group:1;
    };
}vde_vcpu_bisr_drf_fail_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_repaired:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  vcpu_bisr_fail_0:1;
    };
}vde_vcpu_bisr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vcpu_bisr_drf_pause:1;
    };
}vde_vcpu_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sf_rx_mode:1;
        RBus_UInt32  sf_rx_start:1;
        RBus_UInt32  sf_rx_gated:1;
        RBus_UInt32  sf_tx_mode:1;
        RBus_UInt32  sf_tx_start:1;
    };
}vde_vde_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  sf_rx_done_ro:1;
        RBus_UInt32  sf_rx_err_ro:1;
        RBus_UInt32  sf_tx_work_ro:1;
    };
}vde_vde_self_test_ro_RBUS;

#else //apply LITTLE_ENDIAN

//======VDE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  src:29;
    };
}vde_vc_dma_src_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dst:29;
    };
}vde_vc_dma_dst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_type:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  size:11;
        RBus_UInt32  dir:1;
        RBus_UInt32  valid:1;
        RBus_UInt32  res2:16;
    };
}vde_vc_dma_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blk_x:10;
        RBus_UInt32  blk_y:12;
        RBus_UInt32  blk_w:4;
        RBus_UInt32  blk_h:6;
    };
}vde_vc_dma_blk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_pitch:11;
        RBus_UInt32  row_offset:5;
        RBus_UInt32  chroma:1;
        RBus_UInt32  pic_index:7;
        RBus_UInt32  field_mode:1;
        RBus_UInt32  res1:7;
    };
}vde_vc_dma_blkinfo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  go:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  stop:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  dmem_req_en:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  max_xfer:6;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res2:14;
    };
}vde_vc_dma_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_done:1;
        RBus_UInt32  res1:31;
    };
}vde_vc_dma_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_done_en:1;
        RBus_UInt32  res1:31;
    };
}vde_vc_dma_int_en_RBUS;

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
}vde_vc_dma_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sel0:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sel1:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:20;
    };
}vde_vc_dma_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_timer:5;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res1:26;
    };
}vde_vc_dma_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ext_sleepreq_r:1;
        RBus_UInt32  res1:31;
    };
}vde_vc_sleep_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sl_sleepsys_r:1;
        RBus_UInt32  res1:31;
    };
}vde_vc_sleep_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rmb_0:1;
        RBus_UInt32  rmb_1:1;
        RBus_UInt32  rmb_2:1;
        RBus_UInt32  rmb_3:1;
        RBus_UInt32  rmeb:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rma_0:1;
        RBus_UInt32  rma_1:1;
        RBus_UInt32  rma_2:1;
        RBus_UInt32  rma_3:1;
        RBus_UInt32  rmea:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res2:18;
    };
}vde_vc_dma_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_ic_tag0:4;
        RBus_UInt32  rm_ic_tag1:4;
        RBus_UInt32  rm_ic_data0:4;
        RBus_UInt32  rm_ic_data1:4;
        RBus_UInt32  rm_dw_data:4;
        RBus_UInt32  rm_dc_tag:4;
        RBus_UInt32  rm_dc_data:4;
        RBus_UInt32  rme_vcpu:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:2;
    };
}vde_mbist_vcpu_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bist_mode:1;
        RBus_UInt32  vde_bist_mode:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bist_done:1;
        RBus_UInt32  vde_bist_done:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bist_fail_group:1;
        RBus_UInt32  vde_bist_fail_group:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vde_bist_fail0:1;
        RBus_UInt32  res1:31;
    };
}vde_vc_dma_vde_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bist_fail0:1;
        RBus_UInt32  vcpu_bist_fail1:1;
        RBus_UInt32  vcpu_bist_fail2:1;
        RBus_UInt32  vcpu_bist_fail3:1;
        RBus_UInt32  vcpu_bist_fail4:1;
        RBus_UInt32  vcpu_bist_fail5:1;
        RBus_UInt32  res1:26;
    };
}vde_vc_dma_vcpu_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_drf_mode:1;
        RBus_UInt32  vde_drf_mode:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_drf_resume:1;
        RBus_UInt32  vde_drf_resume:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_drf_done:1;
        RBus_UInt32  vde_drf_done:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_drf_pause:1;
        RBus_UInt32  vde_drf_pause:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_drf_fail_group:1;
        RBus_UInt32  vde_drf_fail_group:1;
        RBus_UInt32  res1:30;
    };
}vde_vc_dma_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vde_drf_bist_fail0:1;
        RBus_UInt32  res1:31;
    };
}vde_vc_dma_vde_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_drf_bist_fail0:1;
        RBus_UInt32  vcpu_drf_bist_fail1:1;
        RBus_UInt32  vcpu_drf_bist_fail2:1;
        RBus_UInt32  vcpu_drf_bist_fail3:1;
        RBus_UInt32  vcpu_drf_bist_fail4:1;
        RBus_UInt32  vcpu_drf_bist_fail5:1;
        RBus_UInt32  res1:26;
    };
}vde_vc_dma_vcpu_drf_bist_fail1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_second_run_en:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_fail_group:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_fail_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_fail_0:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_drf_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_drf_done:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_drf_fail_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_fail_0:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  vcpu_bisr_repaired:1;
    };
}vde_vcpu_bisr_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcpu_bisr_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}vde_vcpu_bisr_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_start:1;
        RBus_UInt32  sf_tx_mode:1;
        RBus_UInt32  sf_rx_gated:1;
        RBus_UInt32  sf_rx_start:1;
        RBus_UInt32  sf_rx_mode:1;
        RBus_UInt32  res1:27;
    };
}vde_vde_self_test_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_work_ro:1;
        RBus_UInt32  sf_rx_err_ro:1;
        RBus_UInt32  sf_rx_done_ro:1;
        RBus_UInt32  res1:29;
    };
}vde_vde_self_test_ro_RBUS;




#endif 


#endif 
