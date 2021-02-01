/**
* @file rbusDHDR_v_composerReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DHDR_V_COMPOSER_REG_H_
#define _RBUS_DHDR_V_COMPOSER_REG_H_

#include "rbus/rbusTypes.h"



//  DHDR_V_COMPOSER Register Address
#define  DHDR_V_COMPOSER_Composer                                                0x1806B000
#define  DHDR_V_COMPOSER_Composer_reg_addr                                       "0xB806B000"
#define  DHDR_V_COMPOSER_Composer_reg                                            0xB806B000
#define  DHDR_V_COMPOSER_Composer_inst_addr                                      "0x0000"
#define  set_DHDR_V_COMPOSER_Composer_reg(data)                                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_reg                                        (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_reg))
#define  DHDR_V_COMPOSER_Composer_vdr_bit_depth_shift                            (16)
#define  DHDR_V_COMPOSER_Composer_el_bit_depth_shift                             (12)
#define  DHDR_V_COMPOSER_Composer_bl_bit_depth_shift                             (8)
#define  DHDR_V_COMPOSER_Composer_coefficient_log2_denom_shift                   (0)
#define  DHDR_V_COMPOSER_Composer_vdr_bit_depth_mask                             (0x001F0000)
#define  DHDR_V_COMPOSER_Composer_el_bit_depth_mask                              (0x0000F000)
#define  DHDR_V_COMPOSER_Composer_bl_bit_depth_mask                              (0x00000F00)
#define  DHDR_V_COMPOSER_Composer_coefficient_log2_denom_mask                    (0x0000001F)
#define  DHDR_V_COMPOSER_Composer_vdr_bit_depth(data)                            (0x001F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_el_bit_depth(data)                             (0x0000F000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_bl_bit_depth(data)                             (0x00000F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_coefficient_log2_denom(data)                   (0x0000001F&(data))
#define  DHDR_V_COMPOSER_Composer_get_vdr_bit_depth(data)                        ((0x001F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_get_el_bit_depth(data)                         ((0x0000F000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_get_bl_bit_depth(data)                         ((0x00000F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_get_coefficient_log2_denom(data)               (0x0000001F&(data))

#define  DHDR_V_COMPOSER_Composer_BL                                             0x1806B004
#define  DHDR_V_COMPOSER_Composer_BL_reg_addr                                    "0xB806B004"
#define  DHDR_V_COMPOSER_Composer_BL_reg                                         0xB806B004
#define  DHDR_V_COMPOSER_Composer_BL_inst_addr                                   "0x0001"
#define  set_DHDR_V_COMPOSER_Composer_BL_reg(data)                               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_reg                                     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_reg))
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp2_shift                       (20)
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp1_shift                       (16)
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp0_shift                       (12)
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp2_shift                      (8)
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp1_shift                      (4)
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp0_shift                      (0)
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp2_mask                        (0x00F00000)
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp1_mask                        (0x000F0000)
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp0_mask                        (0x0000F000)
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp2_mask                       (0x00000300)
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp1_mask                       (0x00000030)
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp0_mask                       (0x00000003)
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp2(data)                       (0x00F00000&((data)<<20))
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp1(data)                       (0x000F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_num_pivots_cmp0(data)                       (0x0000F000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp2(data)                      (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp1(data)                      (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_BL_mapping_idc_cmp0(data)                      (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_BL_get_num_pivots_cmp2(data)                   ((0x00F00000&(data))>>20)
#define  DHDR_V_COMPOSER_Composer_BL_get_num_pivots_cmp1(data)                   ((0x000F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_get_num_pivots_cmp0(data)                   ((0x0000F000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_BL_get_mapping_idc_cmp2(data)                  ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_get_mapping_idc_cmp1(data)                  ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_BL_get_mapping_idc_cmp0(data)                  (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01                          0x1806B008
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_reg_addr                 "0xB806B008"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_reg                      0xB806B008
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_inst_addr                "0x0002"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_pivot_value_cmp0_pivot_1_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_pivot_value_cmp0_pivot_0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_pivot_value_cmp0_pivot_1_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_pivot_value_cmp0_pivot_0_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_pivot_value_cmp0_pivot_1(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_pivot_value_cmp0_pivot_0(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_get_pivot_value_cmp0_pivot_1(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P01_get_pivot_value_cmp0_pivot_0(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23                          0x1806B00C
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_reg_addr                 "0xB806B00C"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_reg                      0xB806B00C
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_inst_addr                "0x0003"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_pivot_value_cmp0_pivot_3_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_pivot_value_cmp0_pivot_2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_pivot_value_cmp0_pivot_3_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_pivot_value_cmp0_pivot_2_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_pivot_value_cmp0_pivot_3(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_pivot_value_cmp0_pivot_2(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_get_pivot_value_cmp0_pivot_3(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P23_get_pivot_value_cmp0_pivot_2(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45                          0x1806B010
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_reg_addr                 "0xB806B010"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_reg                      0xB806B010
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_inst_addr                "0x0004"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_pivot_value_cmp0_pivot_5_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_pivot_value_cmp0_pivot_4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_pivot_value_cmp0_pivot_5_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_pivot_value_cmp0_pivot_4_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_pivot_value_cmp0_pivot_5(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_pivot_value_cmp0_pivot_4(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_get_pivot_value_cmp0_pivot_5(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P45_get_pivot_value_cmp0_pivot_4(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67                          0x1806B014
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_reg_addr                 "0xB806B014"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_reg                      0xB806B014
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_inst_addr                "0x0005"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_pivot_value_cmp0_pivot_7_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_pivot_value_cmp0_pivot_6_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_pivot_value_cmp0_pivot_7_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_pivot_value_cmp0_pivot_6_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_pivot_value_cmp0_pivot_7(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_pivot_value_cmp0_pivot_6(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_get_pivot_value_cmp0_pivot_7(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P67_get_pivot_value_cmp0_pivot_6(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8                           0x1806B018
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_reg_addr                  "0xB806B018"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_reg                       0xB806B018
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_inst_addr                 "0x0006"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_reg(data)             (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_reg                   (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_pivot_value_cmp0_pivot_8_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_pivot_value_cmp0_pivot_8_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_pivot_value_cmp0_pivot_8(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp0_P8_get_pivot_value_cmp0_pivot_8(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01                          0x1806B01C
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_reg_addr                 "0xB806B01C"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_reg                      0xB806B01C
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_inst_addr                "0x0007"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_pivot_value_cmp1_pivot_1_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_pivot_value_cmp1_pivot_0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_pivot_value_cmp1_pivot_1_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_pivot_value_cmp1_pivot_0_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_pivot_value_cmp1_pivot_1(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_pivot_value_cmp1_pivot_0(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_get_pivot_value_cmp1_pivot_1(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P01_get_pivot_value_cmp1_pivot_0(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23                          0x1806B020
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_reg_addr                 "0xB806B020"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_reg                      0xB806B020
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_inst_addr                "0x0008"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_pivot_value_cmp1_pivot_3_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_pivot_value_cmp1_pivot_2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_pivot_value_cmp1_pivot_3_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_pivot_value_cmp1_pivot_2_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_pivot_value_cmp1_pivot_3(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_pivot_value_cmp1_pivot_2(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_get_pivot_value_cmp1_pivot_3(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P23_get_pivot_value_cmp1_pivot_2(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45                          0x1806B024
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_reg_addr                 "0xB806B024"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_reg                      0xB806B024
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_inst_addr                "0x0009"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_pivot_value_cmp1_pivot_4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_pivot_value_cmp1_pivot_4_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_pivot_value_cmp1_pivot_4(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp1_P45_get_pivot_value_cmp1_pivot_4(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01                          0x1806B028
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_reg_addr                 "0xB806B028"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_reg                      0xB806B028
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_inst_addr                "0x000A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_pivot_value_cmp2_pivot_1_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_pivot_value_cmp2_pivot_0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_pivot_value_cmp2_pivot_1_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_pivot_value_cmp2_pivot_0_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_pivot_value_cmp2_pivot_1(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_pivot_value_cmp2_pivot_0(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_get_pivot_value_cmp2_pivot_1(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P01_get_pivot_value_cmp2_pivot_0(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23                          0x1806B02C
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_reg_addr                 "0xB806B02C"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_reg                      0xB806B02C
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_inst_addr                "0x000B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_pivot_value_cmp2_pivot_3_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_pivot_value_cmp2_pivot_2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_pivot_value_cmp2_pivot_3_mask (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_pivot_value_cmp2_pivot_2_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_pivot_value_cmp2_pivot_3(data) (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_pivot_value_cmp2_pivot_2(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_get_pivot_value_cmp2_pivot_3(data) ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P23_get_pivot_value_cmp2_pivot_2(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45                          0x1806B030
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_reg_addr                 "0xB806B030"
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_reg                      0xB806B030
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_inst_addr                "0x000C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_reg(data)            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_reg                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_pivot_value_cmp2_pivot_4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_pivot_value_cmp2_pivot_4_mask (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_pivot_value_cmp2_pivot_4(data) (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pivot_Val_Cmp2_P45_get_pivot_value_cmp2_pivot_4(data) (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma                        0x1806B034
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_reg_addr               "0xB806B034"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_reg                    0xB806B034
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_inst_addr              "0x000D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot7_shift (28)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot6_shift (24)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot5_shift (20)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot4_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot3_shift (12)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot2_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot1_shift (4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot7_mask (0x30000000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot6_mask (0x03000000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot5_mask (0x00300000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot4_mask (0x00030000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot3_mask (0x00003000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot2_mask (0x00000300)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot1_mask (0x00000030)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot0_mask (0x00000003)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot7(data) (0x30000000&((data)<<28))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot6(data) (0x03000000&((data)<<24))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot5(data) (0x00300000&((data)<<20))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot4(data) (0x00030000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot3(data) (0x00003000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot2(data) (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot1(data) (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_poly_order_cmp0_pivot0(data) (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot7(data) ((0x30000000&(data))>>28)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot6(data) ((0x03000000&(data))>>24)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot5(data) ((0x00300000&(data))>>20)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot4(data) ((0x00030000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot3(data) ((0x00003000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot2(data) ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot1(data) ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Luma_get_poly_order_cmp0_pivot0(data) (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1                     0x1806B038
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_reg_addr            "0xB806B038"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_reg                 0xB806B038
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_inst_addr           "0x000E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_reg(data)       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_reg             (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot3_shift (12)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot2_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot1_shift (4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot3_mask (0x00003000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot2_mask (0x00000300)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot1_mask (0x00000030)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot0_mask (0x00000003)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot3(data) (0x00003000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot2(data) (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot1(data) (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_poly_order_cmp1_pivot0(data) (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_get_poly_order_cmp1_pivot3(data) ((0x00003000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_get_poly_order_cmp1_pivot2(data) ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_get_poly_order_cmp1_pivot1(data) ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma1_get_poly_order_cmp1_pivot0(data) (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2                     0x1806B03C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_reg_addr            "0xB806B03C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_reg                 0xB806B03C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_inst_addr           "0x000F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_reg(data)       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_reg             (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot3_shift (12)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot2_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot1_shift (4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot3_mask (0x00003000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot2_mask (0x00000300)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot1_mask (0x00000030)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot0_mask (0x00000003)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot3(data) (0x00003000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot2(data) (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot1(data) (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_poly_order_cmp2_pivot0(data) (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_get_poly_order_cmp2_pivot3(data) ((0x00003000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_get_poly_order_cmp2_pivot2(data) ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_get_poly_order_cmp2_pivot1(data) ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Order_Chroma2_get_poly_order_cmp2_pivot0(data) (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0                  0x1806B040
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_reg_addr         "0xB806B040"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_reg              0xB806B040
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_inst_addr        "0x0010"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_poly_coef_int_cmp0_pivot0_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_get_poly_coef_int_cmp0_pivot0_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_get_poly_coef_int_cmp0_pivot0_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P0_get_poly_coef_int_cmp0_pivot0_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1                  0x1806B044
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_reg_addr         "0xB806B044"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_reg              0xB806B044
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_inst_addr        "0x0011"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_poly_coef_int_cmp0_pivot1_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_get_poly_coef_int_cmp0_pivot1_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_get_poly_coef_int_cmp0_pivot1_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P1_get_poly_coef_int_cmp0_pivot1_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2                  0x1806B048
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_reg_addr         "0xB806B048"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_reg              0xB806B048
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_inst_addr        "0x0012"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_poly_coef_int_cmp0_pivot2_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_get_poly_coef_int_cmp0_pivot2_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_get_poly_coef_int_cmp0_pivot2_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P2_get_poly_coef_int_cmp0_pivot2_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3                  0x1806B04C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_reg_addr         "0xB806B04C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_reg              0xB806B04C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_inst_addr        "0x0013"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_poly_coef_int_cmp0_pivot3_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_get_poly_coef_int_cmp0_pivot3_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_get_poly_coef_int_cmp0_pivot3_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P3_get_poly_coef_int_cmp0_pivot3_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4                  0x1806B050
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_reg_addr         "0xB806B050"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_reg              0xB806B050
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_inst_addr        "0x0014"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_poly_coef_int_cmp0_pivot4_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_get_poly_coef_int_cmp0_pivot4_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_get_poly_coef_int_cmp0_pivot4_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P4_get_poly_coef_int_cmp0_pivot4_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5                  0x1806B054
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_reg_addr         "0xB806B054"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_reg              0xB806B054
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_inst_addr        "0x0015"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_poly_coef_int_cmp0_pivot5_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_get_poly_coef_int_cmp0_pivot5_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_get_poly_coef_int_cmp0_pivot5_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P5_get_poly_coef_int_cmp0_pivot5_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6                  0x1806B058
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_reg_addr         "0xB806B058"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_reg              0xB806B058
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_inst_addr        "0x0016"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_poly_coef_int_cmp0_pivot6_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_get_poly_coef_int_cmp0_pivot6_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_get_poly_coef_int_cmp0_pivot6_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P6_get_poly_coef_int_cmp0_pivot6_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7                  0x1806B05C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_reg_addr         "0xB806B05C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_reg              0xB806B05C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_inst_addr        "0x0017"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_poly_coef_int_cmp0_pivot7_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_get_poly_coef_int_cmp0_pivot7_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_get_poly_coef_int_cmp0_pivot7_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp0_P7_get_poly_coef_int_cmp0_pivot7_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0                  0x1806B060
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_reg_addr         "0xB806B060"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_reg              0xB806B060
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_inst_addr        "0x0018"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_poly_coef_int_cmp1_pivot0_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_get_poly_coef_int_cmp1_pivot0_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_get_poly_coef_int_cmp1_pivot0_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P0_get_poly_coef_int_cmp1_pivot0_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1                  0x1806B064
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_reg_addr         "0xB806B064"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_reg              0xB806B064
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_inst_addr        "0x0019"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_poly_coef_int_cmp1_pivot1_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_get_poly_coef_int_cmp1_pivot1_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_get_poly_coef_int_cmp1_pivot1_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P1_get_poly_coef_int_cmp1_pivot1_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2                  0x1806B068
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_reg_addr         "0xB806B068"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_reg              0xB806B068
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_inst_addr        "0x001A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_poly_coef_int_cmp1_pivot2_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_get_poly_coef_int_cmp1_pivot2_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_get_poly_coef_int_cmp1_pivot2_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P2_get_poly_coef_int_cmp1_pivot2_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3                  0x1806B06C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_reg_addr         "0xB806B06C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_reg              0xB806B06C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_inst_addr        "0x001B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_poly_coef_int_cmp1_pivot3_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_get_poly_coef_int_cmp1_pivot3_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_get_poly_coef_int_cmp1_pivot3_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp1_P3_get_poly_coef_int_cmp1_pivot3_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0                  0x1806B070
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_reg_addr         "0xB806B070"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_reg              0xB806B070
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_inst_addr        "0x001C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_poly_coef_int_cmp2_pivot0_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_get_poly_coef_int_cmp2_pivot0_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_get_poly_coef_int_cmp2_pivot0_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P0_get_poly_coef_int_cmp2_pivot0_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1                  0x1806B074
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_reg_addr         "0xB806B074"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_reg              0xB806B074
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_inst_addr        "0x001D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_poly_coef_int_cmp2_pivot1_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_get_poly_coef_int_cmp2_pivot1_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_get_poly_coef_int_cmp2_pivot1_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P1_get_poly_coef_int_cmp2_pivot1_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2                  0x1806B078
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_reg_addr         "0xB806B078"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_reg              0xB806B078
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_inst_addr        "0x001E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_poly_coef_int_cmp2_pivot2_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_get_poly_coef_int_cmp2_pivot2_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_get_poly_coef_int_cmp2_pivot2_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P2_get_poly_coef_int_cmp2_pivot2_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3                  0x1806B07C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_reg_addr         "0xB806B07C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_reg              0xB806B07C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_inst_addr        "0x001F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_reg(data)    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_reg          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i2_shift (16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i1_shift (8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i2_mask (0x007F0000)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i1_mask (0x00007F00)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i0_mask (0x0000007F)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i2(data) (0x007F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i1(data) (0x00007F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_poly_coef_int_cmp2_pivot3_i0(data) (0x0000007F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_get_poly_coef_int_cmp2_pivot3_i2(data) ((0x007F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_get_poly_coef_int_cmp2_pivot3_i1(data) ((0x00007F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_INT_Cmp2_P3_get_poly_coef_int_cmp2_pivot3_i0(data) (0x0000007F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0                   0x1806B080
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_reg_addr          "0xB806B080"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_reg               0xB806B080
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_inst_addr         "0x0020"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_poly_coef_cmp0_pivot0_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_poly_coef_cmp0_pivot0_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_poly_coef_cmp0_pivot0_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I0_get_poly_coef_cmp0_pivot0_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1                   0x1806B084
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_reg_addr          "0xB806B084"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_reg               0xB806B084
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_inst_addr         "0x0021"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_poly_coef_cmp0_pivot0_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_poly_coef_cmp0_pivot0_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_poly_coef_cmp0_pivot0_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I1_get_poly_coef_cmp0_pivot0_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2                   0x1806B088
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_reg_addr          "0xB806B088"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_reg               0xB806B088
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_inst_addr         "0x0022"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_poly_coef_cmp0_pivot0_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_poly_coef_cmp0_pivot0_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_poly_coef_cmp0_pivot0_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P0_I2_get_poly_coef_cmp0_pivot0_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0                   0x1806B08C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_reg_addr          "0xB806B08C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_reg               0xB806B08C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_inst_addr         "0x0023"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_poly_coef_cmp0_pivot1_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_poly_coef_cmp0_pivot1_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_poly_coef_cmp0_pivot1_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I0_get_poly_coef_cmp0_pivot1_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1                   0x1806B090
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_reg_addr          "0xB806B090"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_reg               0xB806B090
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_inst_addr         "0x0024"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_poly_coef_cmp0_pivot1_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_poly_coef_cmp0_pivot1_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_poly_coef_cmp0_pivot1_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I1_get_poly_coef_cmp0_pivot1_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2                   0x1806B094
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_reg_addr          "0xB806B094"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_reg               0xB806B094
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_inst_addr         "0x0025"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_poly_coef_cmp0_pivot1_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_poly_coef_cmp0_pivot1_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_poly_coef_cmp0_pivot1_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P1_I2_get_poly_coef_cmp0_pivot1_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0                   0x1806B098
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_reg_addr          "0xB806B098"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_reg               0xB806B098
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_inst_addr         "0x0026"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_poly_coef_cmp0_pivot2_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_poly_coef_cmp0_pivot2_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_poly_coef_cmp0_pivot2_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I0_get_poly_coef_cmp0_pivot2_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1                   0x1806B09C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_reg_addr          "0xB806B09C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_reg               0xB806B09C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_inst_addr         "0x0027"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_poly_coef_cmp0_pivot2_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_poly_coef_cmp0_pivot2_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_poly_coef_cmp0_pivot2_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I1_get_poly_coef_cmp0_pivot2_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2                   0x1806B0A0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_reg_addr          "0xB806B0A0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_reg               0xB806B0A0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_inst_addr         "0x0028"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_poly_coef_cmp0_pivot2_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_poly_coef_cmp0_pivot2_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_poly_coef_cmp0_pivot2_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P2_I2_get_poly_coef_cmp0_pivot2_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0                   0x1806B0A4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_reg_addr          "0xB806B0A4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_reg               0xB806B0A4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_inst_addr         "0x0029"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_poly_coef_cmp0_pivot3_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_poly_coef_cmp0_pivot3_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_poly_coef_cmp0_pivot3_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I0_get_poly_coef_cmp0_pivot3_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1                   0x1806B0A8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_reg_addr          "0xB806B0A8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_reg               0xB806B0A8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_inst_addr         "0x002A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_poly_coef_cmp0_pivot3_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_poly_coef_cmp0_pivot3_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_poly_coef_cmp0_pivot3_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I1_get_poly_coef_cmp0_pivot3_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2                   0x1806B0AC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_reg_addr          "0xB806B0AC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_reg               0xB806B0AC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_inst_addr         "0x002B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_poly_coef_cmp0_pivot3_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_poly_coef_cmp0_pivot3_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_poly_coef_cmp0_pivot3_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P3_I2_get_poly_coef_cmp0_pivot3_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0                   0x1806B0B0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_reg_addr          "0xB806B0B0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_reg               0xB806B0B0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_inst_addr         "0x002C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_poly_coef_cmp0_pivot4_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_poly_coef_cmp0_pivot4_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_poly_coef_cmp0_pivot4_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I0_get_poly_coef_cmp0_pivot4_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1                   0x1806B0B4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_reg_addr          "0xB806B0B4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_reg               0xB806B0B4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_inst_addr         "0x002D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_poly_coef_cmp0_pivot4_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_poly_coef_cmp0_pivot4_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_poly_coef_cmp0_pivot4_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I1_get_poly_coef_cmp0_pivot4_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2                   0x1806B0B8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_reg_addr          "0xB806B0B8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_reg               0xB806B0B8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_inst_addr         "0x002E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_poly_coef_cmp0_pivot4_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_poly_coef_cmp0_pivot4_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_poly_coef_cmp0_pivot4_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P4_I2_get_poly_coef_cmp0_pivot4_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0                   0x1806B0BC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_reg_addr          "0xB806B0BC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_reg               0xB806B0BC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_inst_addr         "0x002F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_poly_coef_cmp0_pivot5_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_poly_coef_cmp0_pivot5_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_poly_coef_cmp0_pivot5_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I0_get_poly_coef_cmp0_pivot5_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1                   0x1806B0C0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_reg_addr          "0xB806B0C0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_reg               0xB806B0C0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_inst_addr         "0x0030"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_poly_coef_cmp0_pivot5_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_poly_coef_cmp0_pivot5_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_poly_coef_cmp0_pivot5_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I1_get_poly_coef_cmp0_pivot5_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2                   0x1806B0C4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_reg_addr          "0xB806B0C4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_reg               0xB806B0C4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_inst_addr         "0x0031"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_poly_coef_cmp0_pivot5_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_poly_coef_cmp0_pivot5_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_poly_coef_cmp0_pivot5_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P5_I2_get_poly_coef_cmp0_pivot5_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0                   0x1806B0C8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_reg_addr          "0xB806B0C8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_reg               0xB806B0C8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_inst_addr         "0x0032"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_poly_coef_cmp0_pivot6_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_poly_coef_cmp0_pivot6_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_poly_coef_cmp0_pivot6_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I0_get_poly_coef_cmp0_pivot6_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1                   0x1806B0CC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_reg_addr          "0xB806B0CC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_reg               0xB806B0CC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_inst_addr         "0x0033"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_poly_coef_cmp0_pivot6_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_poly_coef_cmp0_pivot6_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_poly_coef_cmp0_pivot6_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I1_get_poly_coef_cmp0_pivot6_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2                   0x1806B0D0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_reg_addr          "0xB806B0D0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_reg               0xB806B0D0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_inst_addr         "0x0034"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_poly_coef_cmp0_pivot6_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_poly_coef_cmp0_pivot6_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_poly_coef_cmp0_pivot6_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P6_I2_get_poly_coef_cmp0_pivot6_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0                   0x1806B0D4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_reg_addr          "0xB806B0D4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_reg               0xB806B0D4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_inst_addr         "0x0035"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_poly_coef_cmp0_pivot7_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_poly_coef_cmp0_pivot7_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_poly_coef_cmp0_pivot7_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I0_get_poly_coef_cmp0_pivot7_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1                   0x1806B0D8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_reg_addr          "0xB806B0D8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_reg               0xB806B0D8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_inst_addr         "0x0036"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_poly_coef_cmp0_pivot7_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_poly_coef_cmp0_pivot7_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_poly_coef_cmp0_pivot7_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I1_get_poly_coef_cmp0_pivot7_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2                   0x1806B0DC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_reg_addr          "0xB806B0DC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_reg               0xB806B0DC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_inst_addr         "0x0037"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_poly_coef_cmp0_pivot7_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_poly_coef_cmp0_pivot7_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_poly_coef_cmp0_pivot7_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp0_P7_I2_get_poly_coef_cmp0_pivot7_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0                   0x1806B0E0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_reg_addr          "0xB806B0E0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_reg               0xB806B0E0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_inst_addr         "0x0038"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_poly_coef_cmp1_pivot0_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_poly_coef_cmp1_pivot0_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_poly_coef_cmp1_pivot0_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I0_get_poly_coef_cmp1_pivot0_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1                   0x1806B0E4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_reg_addr          "0xB806B0E4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_reg               0xB806B0E4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_inst_addr         "0x0039"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_poly_coef_cmp1_pivot0_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_poly_coef_cmp1_pivot0_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_poly_coef_cmp1_pivot0_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I1_get_poly_coef_cmp1_pivot0_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2                   0x1806B0E8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_reg_addr          "0xB806B0E8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_reg               0xB806B0E8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_inst_addr         "0x003A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_poly_coef_cmp1_pivot0_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_poly_coef_cmp1_pivot0_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_poly_coef_cmp1_pivot0_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P0_I2_get_poly_coef_cmp1_pivot0_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0                   0x1806B0EC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_reg_addr          "0xB806B0EC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_reg               0xB806B0EC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_inst_addr         "0x003B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_poly_coef_cmp1_pivot1_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_poly_coef_cmp1_pivot1_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_poly_coef_cmp1_pivot1_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I0_get_poly_coef_cmp1_pivot1_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1                   0x1806B0F0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_reg_addr          "0xB806B0F0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_reg               0xB806B0F0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_inst_addr         "0x003C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_poly_coef_cmp1_pivot1_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_poly_coef_cmp1_pivot1_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_poly_coef_cmp1_pivot1_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I1_get_poly_coef_cmp1_pivot1_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2                   0x1806B0F4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_reg_addr          "0xB806B0F4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_reg               0xB806B0F4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_inst_addr         "0x003D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_poly_coef_cmp1_pivot1_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_poly_coef_cmp1_pivot1_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_poly_coef_cmp1_pivot1_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P1_I2_get_poly_coef_cmp1_pivot1_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0                   0x1806B0F8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_reg_addr          "0xB806B0F8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_reg               0xB806B0F8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_inst_addr         "0x003E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_poly_coef_cmp1_pivot2_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_poly_coef_cmp1_pivot2_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_poly_coef_cmp1_pivot2_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I0_get_poly_coef_cmp1_pivot2_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1                   0x1806B0FC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_reg_addr          "0xB806B0FC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_reg               0xB806B0FC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_inst_addr         "0x003F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_poly_coef_cmp1_pivot2_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_poly_coef_cmp1_pivot2_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_poly_coef_cmp1_pivot2_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I1_get_poly_coef_cmp1_pivot2_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2                   0x1806B100
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_reg_addr          "0xB806B100"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_reg               0xB806B100
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_inst_addr         "0x0040"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_poly_coef_cmp1_pivot2_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_poly_coef_cmp1_pivot2_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_poly_coef_cmp1_pivot2_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P2_I2_get_poly_coef_cmp1_pivot2_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0                   0x1806B104
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_reg_addr          "0xB806B104"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_reg               0xB806B104
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_inst_addr         "0x0041"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_poly_coef_cmp1_pivot3_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_poly_coef_cmp1_pivot3_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_poly_coef_cmp1_pivot3_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I0_get_poly_coef_cmp1_pivot3_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1                   0x1806B108
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_reg_addr          "0xB806B108"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_reg               0xB806B108
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_inst_addr         "0x0042"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_poly_coef_cmp1_pivot3_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_poly_coef_cmp1_pivot3_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_poly_coef_cmp1_pivot3_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I1_get_poly_coef_cmp1_pivot3_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2                   0x1806B10C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_reg_addr          "0xB806B10C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_reg               0xB806B10C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_inst_addr         "0x0043"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_poly_coef_cmp1_pivot3_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_poly_coef_cmp1_pivot3_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_poly_coef_cmp1_pivot3_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp1_P3_I2_get_poly_coef_cmp1_pivot3_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0                   0x1806B110
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_reg_addr          "0xB806B110"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_reg               0xB806B110
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_inst_addr         "0x0044"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_poly_coef_cmp2_pivot0_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_poly_coef_cmp2_pivot0_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_poly_coef_cmp2_pivot0_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I0_get_poly_coef_cmp2_pivot0_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1                   0x1806B114
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_reg_addr          "0xB806B114"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_reg               0xB806B114
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_inst_addr         "0x0045"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_poly_coef_cmp2_pivot0_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_poly_coef_cmp2_pivot0_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_poly_coef_cmp2_pivot0_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I1_get_poly_coef_cmp2_pivot0_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2                   0x1806B118
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_reg_addr          "0xB806B118"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_reg               0xB806B118
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_inst_addr         "0x0046"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_poly_coef_cmp2_pivot0_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_poly_coef_cmp2_pivot0_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_poly_coef_cmp2_pivot0_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P0_I2_get_poly_coef_cmp2_pivot0_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0                   0x1806B11C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_reg_addr          "0xB806B11C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_reg               0xB806B11C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_inst_addr         "0x0047"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_poly_coef_cmp2_pivot1_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_poly_coef_cmp2_pivot1_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_poly_coef_cmp2_pivot1_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I0_get_poly_coef_cmp2_pivot1_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1                   0x1806B120
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_reg_addr          "0xB806B120"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_reg               0xB806B120
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_inst_addr         "0x0048"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_poly_coef_cmp2_pivot1_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_poly_coef_cmp2_pivot1_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_poly_coef_cmp2_pivot1_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I1_get_poly_coef_cmp2_pivot1_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2                   0x1806B124
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_reg_addr          "0xB806B124"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_reg               0xB806B124
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_inst_addr         "0x0049"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_poly_coef_cmp2_pivot1_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_poly_coef_cmp2_pivot1_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_poly_coef_cmp2_pivot1_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P1_I2_get_poly_coef_cmp2_pivot1_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0                   0x1806B128
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_reg_addr          "0xB806B128"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_reg               0xB806B128
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_inst_addr         "0x004A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_poly_coef_cmp2_pivot2_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_poly_coef_cmp2_pivot2_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_poly_coef_cmp2_pivot2_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I0_get_poly_coef_cmp2_pivot2_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1                   0x1806B12C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_reg_addr          "0xB806B12C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_reg               0xB806B12C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_inst_addr         "0x004B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_poly_coef_cmp2_pivot2_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_poly_coef_cmp2_pivot2_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_poly_coef_cmp2_pivot2_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I1_get_poly_coef_cmp2_pivot2_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2                   0x1806B130
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_reg_addr          "0xB806B130"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_reg               0xB806B130
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_inst_addr         "0x004C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_poly_coef_cmp2_pivot2_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_poly_coef_cmp2_pivot2_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_poly_coef_cmp2_pivot2_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P2_I2_get_poly_coef_cmp2_pivot2_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0                   0x1806B134
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_reg_addr          "0xB806B134"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_reg               0xB806B134
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_inst_addr         "0x004D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_poly_coef_cmp2_pivot3_i0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_poly_coef_cmp2_pivot3_i0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_poly_coef_cmp2_pivot3_i0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I0_get_poly_coef_cmp2_pivot3_i0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1                   0x1806B138
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_reg_addr          "0xB806B138"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_reg               0xB806B138
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_inst_addr         "0x004E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_poly_coef_cmp2_pivot3_i1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_poly_coef_cmp2_pivot3_i1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_poly_coef_cmp2_pivot3_i1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I1_get_poly_coef_cmp2_pivot3_i1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2                   0x1806B13C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_reg_addr          "0xB806B13C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_reg               0xB806B13C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_inst_addr         "0x004F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_poly_coef_cmp2_pivot3_i2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_poly_coef_cmp2_pivot3_i2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_poly_coef_cmp2_pivot3_i2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_Poly_Coef_Cmp2_P3_I2_get_poly_coef_cmp2_pivot3_i2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order                              0x1806B140
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_reg_addr                     "0xB806B140"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_reg                          0xB806B140
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_inst_addr                    "0x0050"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_reg(data)                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_reg                      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_mmr_order_cmp2_shift         (4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_mmr_order_cmp1_shift         (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_mmr_order_cmp2_mask          (0x00000030)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_mmr_order_cmp1_mask          (0x00000003)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_mmr_order_cmp2(data)         (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_mmr_order_cmp1(data)         (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_get_mmr_order_cmp2(data)     ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Order_get_mmr_order_cmp1(data)     (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0                    0x1806B144
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_reg_addr           "0xB806B144"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_reg                0xB806B144
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_inst_addr          "0x0051"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_mmr_coef_int_cmp1_coef0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_mmr_coef_int_cmp1_coef0_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_mmr_coef_int_cmp1_coef0(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_0_get_mmr_coef_int_cmp1_coef0(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1                    0x1806B148
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_reg_addr           "0xB806B148"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_reg                0xB806B148
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_inst_addr          "0x0052"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_mmr_coef_int_cmp1_coef1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_mmr_coef_int_cmp1_coef1_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_mmr_coef_int_cmp1_coef1(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_1_get_mmr_coef_int_cmp1_coef1(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2                    0x1806B14C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_reg_addr           "0xB806B14C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_reg                0xB806B14C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_inst_addr          "0x0053"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_mmr_coef_int_cmp1_coef2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_mmr_coef_int_cmp1_coef2_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_mmr_coef_int_cmp1_coef2(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_2_get_mmr_coef_int_cmp1_coef2(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3                    0x1806B150
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_reg_addr           "0xB806B150"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_reg                0xB806B150
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_inst_addr          "0x0054"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_mmr_coef_int_cmp1_coef3_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_mmr_coef_int_cmp1_coef3_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_mmr_coef_int_cmp1_coef3(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_3_get_mmr_coef_int_cmp1_coef3(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4                    0x1806B154
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_reg_addr           "0xB806B154"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_reg                0xB806B154
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_inst_addr          "0x0055"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_mmr_coef_int_cmp1_coef4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_mmr_coef_int_cmp1_coef4_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_mmr_coef_int_cmp1_coef4(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_4_get_mmr_coef_int_cmp1_coef4(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5                    0x1806B158
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_reg_addr           "0xB806B158"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_reg                0xB806B158
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_inst_addr          "0x0056"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_mmr_coef_int_cmp1_coef5_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_mmr_coef_int_cmp1_coef5_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_mmr_coef_int_cmp1_coef5(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_5_get_mmr_coef_int_cmp1_coef5(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6                    0x1806B15C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_reg_addr           "0xB806B15C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_reg                0xB806B15C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_inst_addr          "0x0057"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_mmr_coef_int_cmp1_coef6_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_mmr_coef_int_cmp1_coef6_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_mmr_coef_int_cmp1_coef6(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_6_get_mmr_coef_int_cmp1_coef6(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7                    0x1806B160
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_reg_addr           "0xB806B160"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_reg                0xB806B160
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_inst_addr          "0x0058"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_mmr_coef_int_cmp1_coef7_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_mmr_coef_int_cmp1_coef7_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_mmr_coef_int_cmp1_coef7(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_7_get_mmr_coef_int_cmp1_coef7(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8                    0x1806B164
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_reg_addr           "0xB806B164"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_reg                0xB806B164
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_inst_addr          "0x0059"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_mmr_coef_int_cmp1_coef8_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_mmr_coef_int_cmp1_coef8_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_mmr_coef_int_cmp1_coef8(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_8_get_mmr_coef_int_cmp1_coef8(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9                    0x1806B168
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_reg_addr           "0xB806B168"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_reg                0xB806B168
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_inst_addr          "0x005A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_mmr_coef_int_cmp1_coef9_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_mmr_coef_int_cmp1_coef9_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_mmr_coef_int_cmp1_coef9(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_9_get_mmr_coef_int_cmp1_coef9(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10                   0x1806B16C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_reg_addr          "0xB806B16C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_reg               0xB806B16C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_inst_addr         "0x005B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_mmr_coef_int_cmp1_coef10_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_mmr_coef_int_cmp1_coef10_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_mmr_coef_int_cmp1_coef10(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_10_get_mmr_coef_int_cmp1_coef10(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11                   0x1806B170
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_reg_addr          "0xB806B170"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_reg               0xB806B170
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_inst_addr         "0x005C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_mmr_coef_int_cmp1_coef11_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_mmr_coef_int_cmp1_coef11_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_mmr_coef_int_cmp1_coef11(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_11_get_mmr_coef_int_cmp1_coef11(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12                   0x1806B174
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_reg_addr          "0xB806B174"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_reg               0xB806B174
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_inst_addr         "0x005D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_mmr_coef_int_cmp1_coef12_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_mmr_coef_int_cmp1_coef12_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_mmr_coef_int_cmp1_coef12(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_12_get_mmr_coef_int_cmp1_coef12(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13                   0x1806B178
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_reg_addr          "0xB806B178"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_reg               0xB806B178
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_inst_addr         "0x005E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_mmr_coef_int_cmp1_coef13_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_mmr_coef_int_cmp1_coef13_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_mmr_coef_int_cmp1_coef13(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_13_get_mmr_coef_int_cmp1_coef13(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14                   0x1806B17C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_reg_addr          "0xB806B17C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_reg               0xB806B17C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_inst_addr         "0x005F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_mmr_coef_int_cmp1_coef14_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_mmr_coef_int_cmp1_coef14_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_mmr_coef_int_cmp1_coef14(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_14_get_mmr_coef_int_cmp1_coef14(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15                   0x1806B180
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_reg_addr          "0xB806B180"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_reg               0xB806B180
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_inst_addr         "0x0060"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_mmr_coef_int_cmp1_coef15_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_mmr_coef_int_cmp1_coef15_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_mmr_coef_int_cmp1_coef15(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_15_get_mmr_coef_int_cmp1_coef15(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16                   0x1806B184
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_reg_addr          "0xB806B184"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_reg               0xB806B184
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_inst_addr         "0x0061"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_mmr_coef_int_cmp1_coef16_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_mmr_coef_int_cmp1_coef16_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_mmr_coef_int_cmp1_coef16(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_16_get_mmr_coef_int_cmp1_coef16(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17                   0x1806B188
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_reg_addr          "0xB806B188"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_reg               0xB806B188
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_inst_addr         "0x0062"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_mmr_coef_int_cmp1_coef17_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_mmr_coef_int_cmp1_coef17_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_mmr_coef_int_cmp1_coef17(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_17_get_mmr_coef_int_cmp1_coef17(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18                   0x1806B18C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_reg_addr          "0xB806B18C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_reg               0xB806B18C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_inst_addr         "0x0063"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_mmr_coef_int_cmp1_coef18_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_mmr_coef_int_cmp1_coef18_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_mmr_coef_int_cmp1_coef18(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_18_get_mmr_coef_int_cmp1_coef18(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19                   0x1806B190
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_reg_addr          "0xB806B190"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_reg               0xB806B190
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_inst_addr         "0x0064"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_mmr_coef_int_cmp1_coef19_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_mmr_coef_int_cmp1_coef19_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_mmr_coef_int_cmp1_coef19(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_19_get_mmr_coef_int_cmp1_coef19(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20                   0x1806B194
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_reg_addr          "0xB806B194"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_reg               0xB806B194
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_inst_addr         "0x0065"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_mmr_coef_int_cmp1_coef20_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_mmr_coef_int_cmp1_coef20_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_mmr_coef_int_cmp1_coef20(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_20_get_mmr_coef_int_cmp1_coef20(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21                   0x1806B198
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_reg_addr          "0xB806B198"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_reg               0xB806B198
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_inst_addr         "0x0066"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_mmr_coef_int_cmp1_coef21_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_mmr_coef_int_cmp1_coef21_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_mmr_coef_int_cmp1_coef21(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_INT_21_get_mmr_coef_int_cmp1_coef21(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0                    0x1806B19C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_reg_addr           "0xB806B19C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_reg                0xB806B19C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_inst_addr          "0x0067"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_mmr_coef_int_cmp2_coef0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_mmr_coef_int_cmp2_coef0_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_mmr_coef_int_cmp2_coef0(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_0_get_mmr_coef_int_cmp2_coef0(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1                    0x1806B1A0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_reg_addr           "0xB806B1A0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_reg                0xB806B1A0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_inst_addr          "0x0068"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_mmr_coef_int_cmp2_coef1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_mmr_coef_int_cmp2_coef1_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_mmr_coef_int_cmp2_coef1(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_1_get_mmr_coef_int_cmp2_coef1(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2                    0x1806B1A4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_reg_addr           "0xB806B1A4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_reg                0xB806B1A4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_inst_addr          "0x0069"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_mmr_coef_int_cmp2_coef2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_mmr_coef_int_cmp2_coef2_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_mmr_coef_int_cmp2_coef2(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_2_get_mmr_coef_int_cmp2_coef2(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3                    0x1806B1A8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_reg_addr           "0xB806B1A8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_reg                0xB806B1A8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_inst_addr          "0x006A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_mmr_coef_int_cmp2_coef3_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_mmr_coef_int_cmp2_coef3_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_mmr_coef_int_cmp2_coef3(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_3_get_mmr_coef_int_cmp2_coef3(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4                    0x1806B1AC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_reg_addr           "0xB806B1AC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_reg                0xB806B1AC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_inst_addr          "0x006B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_mmr_coef_int_cmp2_coef4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_mmr_coef_int_cmp2_coef4_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_mmr_coef_int_cmp2_coef4(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_4_get_mmr_coef_int_cmp2_coef4(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5                    0x1806B1B0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_reg_addr           "0xB806B1B0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_reg                0xB806B1B0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_inst_addr          "0x006C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_mmr_coef_int_cmp2_coef5_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_mmr_coef_int_cmp2_coef5_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_mmr_coef_int_cmp2_coef5(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_5_get_mmr_coef_int_cmp2_coef5(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6                    0x1806B1B4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_reg_addr           "0xB806B1B4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_reg                0xB806B1B4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_inst_addr          "0x006D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_mmr_coef_int_cmp2_coef6_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_mmr_coef_int_cmp2_coef6_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_mmr_coef_int_cmp2_coef6(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_6_get_mmr_coef_int_cmp2_coef6(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7                    0x1806B1B8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_reg_addr           "0xB806B1B8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_reg                0xB806B1B8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_inst_addr          "0x006E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_mmr_coef_int_cmp2_coef7_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_mmr_coef_int_cmp2_coef7_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_mmr_coef_int_cmp2_coef7(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_7_get_mmr_coef_int_cmp2_coef7(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8                    0x1806B1BC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_reg_addr           "0xB806B1BC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_reg                0xB806B1BC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_inst_addr          "0x006F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_mmr_coef_int_cmp2_coef8_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_mmr_coef_int_cmp2_coef8_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_mmr_coef_int_cmp2_coef8(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_8_get_mmr_coef_int_cmp2_coef8(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9                    0x1806B1C0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_reg_addr           "0xB806B1C0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_reg                0xB806B1C0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_inst_addr          "0x0070"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_reg(data)      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_reg            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_mmr_coef_int_cmp2_coef9_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_mmr_coef_int_cmp2_coef9_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_mmr_coef_int_cmp2_coef9(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_9_get_mmr_coef_int_cmp2_coef9(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10                   0x1806B1C4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_reg_addr          "0xB806B1C4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_reg               0xB806B1C4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_inst_addr         "0x0071"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_mmr_coef_int_cmp2_coef10_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_mmr_coef_int_cmp2_coef10_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_mmr_coef_int_cmp2_coef10(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_10_get_mmr_coef_int_cmp2_coef10(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11                   0x1806B1C8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_reg_addr          "0xB806B1C8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_reg               0xB806B1C8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_inst_addr         "0x0072"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_mmr_coef_int_cmp2_coef11_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_mmr_coef_int_cmp2_coef11_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_mmr_coef_int_cmp2_coef11(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_11_get_mmr_coef_int_cmp2_coef11(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12                   0x1806B1CC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_reg_addr          "0xB806B1CC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_reg               0xB806B1CC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_inst_addr         "0x0073"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_mmr_coef_int_cmp2_coef12_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_mmr_coef_int_cmp2_coef12_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_mmr_coef_int_cmp2_coef12(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_12_get_mmr_coef_int_cmp2_coef12(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13                   0x1806B1D0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_reg_addr          "0xB806B1D0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_reg               0xB806B1D0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_inst_addr         "0x0074"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_mmr_coef_int_cmp2_coef13_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_mmr_coef_int_cmp2_coef13_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_mmr_coef_int_cmp2_coef13(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_13_get_mmr_coef_int_cmp2_coef13(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14                   0x1806B1D4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_reg_addr          "0xB806B1D4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_reg               0xB806B1D4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_inst_addr         "0x0075"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_mmr_coef_int_cmp2_coef14_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_mmr_coef_int_cmp2_coef14_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_mmr_coef_int_cmp2_coef14(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_14_get_mmr_coef_int_cmp2_coef14(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15                   0x1806B1D8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_reg_addr          "0xB806B1D8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_reg               0xB806B1D8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_inst_addr         "0x0076"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_mmr_coef_int_cmp2_coef15_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_mmr_coef_int_cmp2_coef15_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_mmr_coef_int_cmp2_coef15(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_15_get_mmr_coef_int_cmp2_coef15(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16                   0x1806B1DC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_reg_addr          "0xB806B1DC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_reg               0xB806B1DC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_inst_addr         "0x0077"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_mmr_coef_int_cmp2_coef16_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_mmr_coef_int_cmp2_coef16_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_mmr_coef_int_cmp2_coef16(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_16_get_mmr_coef_int_cmp2_coef16(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17                   0x1806B1E0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_reg_addr          "0xB806B1E0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_reg               0xB806B1E0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_inst_addr         "0x0078"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_mmr_coef_int_cmp2_coef17_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_mmr_coef_int_cmp2_coef17_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_mmr_coef_int_cmp2_coef17(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_17_get_mmr_coef_int_cmp2_coef17(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18                   0x1806B1E4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_reg_addr          "0xB806B1E4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_reg               0xB806B1E4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_inst_addr         "0x0079"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_mmr_coef_int_cmp2_coef18_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_mmr_coef_int_cmp2_coef18_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_mmr_coef_int_cmp2_coef18(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_18_get_mmr_coef_int_cmp2_coef18(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19                   0x1806B1E8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_reg_addr          "0xB806B1E8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_reg               0xB806B1E8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_inst_addr         "0x007A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_mmr_coef_int_cmp2_coef19_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_mmr_coef_int_cmp2_coef19_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_mmr_coef_int_cmp2_coef19(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_19_get_mmr_coef_int_cmp2_coef19(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20                   0x1806B1EC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_reg_addr          "0xB806B1EC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_reg               0xB806B1EC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_inst_addr         "0x007B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_mmr_coef_int_cmp2_coef20_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_mmr_coef_int_cmp2_coef20_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_mmr_coef_int_cmp2_coef20(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_20_get_mmr_coef_int_cmp2_coef20(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21                   0x1806B1F0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_reg_addr          "0xB806B1F0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_reg               0xB806B1F0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_inst_addr         "0x007C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_reg(data)     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_reg           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_mmr_coef_int_cmp2_coef21_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_mmr_coef_int_cmp2_coef21_mask (0x0001FFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_mmr_coef_int_cmp2_coef21(data) (0x0001FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_INT_21_get_mmr_coef_int_cmp2_coef21(data) (0x0001FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0                        0x1806B1F4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_reg_addr               "0xB806B1F4"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_reg                    0xB806B1F4
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_inst_addr              "0x007D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_mmr_coef_cmp1_coef0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_mmr_coef_cmp1_coef0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_mmr_coef_cmp1_coef0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_0_get_mmr_coef_cmp1_coef0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1                        0x1806B1F8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_reg_addr               "0xB806B1F8"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_reg                    0xB806B1F8
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_inst_addr              "0x007E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_mmr_coef_cmp1_coef1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_mmr_coef_cmp1_coef1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_mmr_coef_cmp1_coef1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_1_get_mmr_coef_cmp1_coef1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2                        0x1806B1FC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_reg_addr               "0xB806B1FC"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_reg                    0xB806B1FC
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_inst_addr              "0x007F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_mmr_coef_cmp1_coef2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_mmr_coef_cmp1_coef2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_mmr_coef_cmp1_coef2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_2_get_mmr_coef_cmp1_coef2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3                        0x1806B200
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_reg_addr               "0xB806B200"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_reg                    0xB806B200
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_inst_addr              "0x0080"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_mmr_coef_cmp1_coef3_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_mmr_coef_cmp1_coef3_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_mmr_coef_cmp1_coef3(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_3_get_mmr_coef_cmp1_coef3(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4                        0x1806B204
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_reg_addr               "0xB806B204"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_reg                    0xB806B204
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_inst_addr              "0x0081"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_mmr_coef_cmp1_coef4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_mmr_coef_cmp1_coef4_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_mmr_coef_cmp1_coef4(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_4_get_mmr_coef_cmp1_coef4(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5                        0x1806B208
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_reg_addr               "0xB806B208"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_reg                    0xB806B208
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_inst_addr              "0x0082"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_mmr_coef_cmp1_coef5_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_mmr_coef_cmp1_coef5_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_mmr_coef_cmp1_coef5(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_5_get_mmr_coef_cmp1_coef5(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6                        0x1806B20C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_reg_addr               "0xB806B20C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_reg                    0xB806B20C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_inst_addr              "0x0083"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_mmr_coef_cmp1_coef6_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_mmr_coef_cmp1_coef6_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_mmr_coef_cmp1_coef6(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_6_get_mmr_coef_cmp1_coef6(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7                        0x1806B210
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_reg_addr               "0xB806B210"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_reg                    0xB806B210
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_inst_addr              "0x0084"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_mmr_coef_cmp1_coef7_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_mmr_coef_cmp1_coef7_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_mmr_coef_cmp1_coef7(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_7_get_mmr_coef_cmp1_coef7(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8                        0x1806B214
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_reg_addr               "0xB806B214"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_reg                    0xB806B214
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_inst_addr              "0x0085"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_mmr_coef_cmp1_coef8_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_mmr_coef_cmp1_coef8_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_mmr_coef_cmp1_coef8(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_8_get_mmr_coef_cmp1_coef8(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9                        0x1806B218
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_reg_addr               "0xB806B218"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_reg                    0xB806B218
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_inst_addr              "0x0086"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_mmr_coef_cmp1_coef9_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_mmr_coef_cmp1_coef9_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_mmr_coef_cmp1_coef9(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_9_get_mmr_coef_cmp1_coef9(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10                       0x1806B21C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_reg_addr              "0xB806B21C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_reg                   0xB806B21C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_inst_addr             "0x0087"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_mmr_coef_cmp1_coef10_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_mmr_coef_cmp1_coef10_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_mmr_coef_cmp1_coef10(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_10_get_mmr_coef_cmp1_coef10(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11                       0x1806B220
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_reg_addr              "0xB806B220"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_reg                   0xB806B220
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_inst_addr             "0x0088"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_mmr_coef_cmp1_coef11_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_mmr_coef_cmp1_coef11_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_mmr_coef_cmp1_coef11(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_11_get_mmr_coef_cmp1_coef11(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12                       0x1806B224
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_reg_addr              "0xB806B224"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_reg                   0xB806B224
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_inst_addr             "0x0089"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_mmr_coef_cmp1_coef12_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_mmr_coef_cmp1_coef12_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_mmr_coef_cmp1_coef12(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_12_get_mmr_coef_cmp1_coef12(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13                       0x1806B228
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_reg_addr              "0xB806B228"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_reg                   0xB806B228
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_inst_addr             "0x008A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_mmr_coef_cmp1_coef13_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_mmr_coef_cmp1_coef13_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_mmr_coef_cmp1_coef13(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_13_get_mmr_coef_cmp1_coef13(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14                       0x1806B22C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_reg_addr              "0xB806B22C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_reg                   0xB806B22C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_inst_addr             "0x008B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_mmr_coef_cmp1_coef14_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_mmr_coef_cmp1_coef14_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_mmr_coef_cmp1_coef14(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_14_get_mmr_coef_cmp1_coef14(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15                       0x1806B230
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_reg_addr              "0xB806B230"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_reg                   0xB806B230
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_inst_addr             "0x008C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_mmr_coef_cmp1_coef15_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_mmr_coef_cmp1_coef15_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_mmr_coef_cmp1_coef15(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_15_get_mmr_coef_cmp1_coef15(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16                       0x1806B234
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_reg_addr              "0xB806B234"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_reg                   0xB806B234
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_inst_addr             "0x008D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_mmr_coef_cmp1_coef16_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_mmr_coef_cmp1_coef16_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_mmr_coef_cmp1_coef16(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_16_get_mmr_coef_cmp1_coef16(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17                       0x1806B238
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_reg_addr              "0xB806B238"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_reg                   0xB806B238
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_inst_addr             "0x008E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_mmr_coef_cmp1_coef17_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_mmr_coef_cmp1_coef17_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_mmr_coef_cmp1_coef17(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_17_get_mmr_coef_cmp1_coef17(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18                       0x1806B23C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_reg_addr              "0xB806B23C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_reg                   0xB806B23C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_inst_addr             "0x008F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_mmr_coef_cmp1_coef18_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_mmr_coef_cmp1_coef18_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_mmr_coef_cmp1_coef18(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_18_get_mmr_coef_cmp1_coef18(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19                       0x1806B240
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_reg_addr              "0xB806B240"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_reg                   0xB806B240
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_inst_addr             "0x0090"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_mmr_coef_cmp1_coef19_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_mmr_coef_cmp1_coef19_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_mmr_coef_cmp1_coef19(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_19_get_mmr_coef_cmp1_coef19(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20                       0x1806B244
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_reg_addr              "0xB806B244"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_reg                   0xB806B244
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_inst_addr             "0x0091"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_mmr_coef_cmp1_coef20_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_mmr_coef_cmp1_coef20_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_mmr_coef_cmp1_coef20(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_20_get_mmr_coef_cmp1_coef20(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21                       0x1806B248
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_reg_addr              "0xB806B248"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_reg                   0xB806B248
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_inst_addr             "0x0092"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_mmr_coef_cmp1_coef21_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_mmr_coef_cmp1_coef21_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_mmr_coef_cmp1_coef21(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp1_Coef_21_get_mmr_coef_cmp1_coef21(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0                        0x1806B24C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_reg_addr               "0xB806B24C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_reg                    0xB806B24C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_inst_addr              "0x0093"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_mmr_coef_cmp2_coef0_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_mmr_coef_cmp2_coef0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_mmr_coef_cmp2_coef0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_0_get_mmr_coef_cmp2_coef0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1                        0x1806B250
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_reg_addr               "0xB806B250"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_reg                    0xB806B250
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_inst_addr              "0x0094"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_mmr_coef_cmp2_coef1_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_mmr_coef_cmp2_coef1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_mmr_coef_cmp2_coef1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_1_get_mmr_coef_cmp2_coef1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2                        0x1806B254
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_reg_addr               "0xB806B254"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_reg                    0xB806B254
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_inst_addr              "0x0095"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_mmr_coef_cmp2_coef2_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_mmr_coef_cmp2_coef2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_mmr_coef_cmp2_coef2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_2_get_mmr_coef_cmp2_coef2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3                        0x1806B258
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_reg_addr               "0xB806B258"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_reg                    0xB806B258
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_inst_addr              "0x0096"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_mmr_coef_cmp2_coef3_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_mmr_coef_cmp2_coef3_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_mmr_coef_cmp2_coef3(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_3_get_mmr_coef_cmp2_coef3(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4                        0x1806B25C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_reg_addr               "0xB806B25C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_reg                    0xB806B25C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_inst_addr              "0x0097"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_mmr_coef_cmp2_coef4_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_mmr_coef_cmp2_coef4_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_mmr_coef_cmp2_coef4(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_4_get_mmr_coef_cmp2_coef4(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5                        0x1806B260
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_reg_addr               "0xB806B260"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_reg                    0xB806B260
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_inst_addr              "0x0098"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_mmr_coef_cmp2_coef5_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_mmr_coef_cmp2_coef5_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_mmr_coef_cmp2_coef5(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_5_get_mmr_coef_cmp2_coef5(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6                        0x1806B264
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_reg_addr               "0xB806B264"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_reg                    0xB806B264
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_inst_addr              "0x0099"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_mmr_coef_cmp2_coef6_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_mmr_coef_cmp2_coef6_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_mmr_coef_cmp2_coef6(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_6_get_mmr_coef_cmp2_coef6(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7                        0x1806B268
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_reg_addr               "0xB806B268"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_reg                    0xB806B268
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_inst_addr              "0x009A"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_mmr_coef_cmp2_coef7_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_mmr_coef_cmp2_coef7_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_mmr_coef_cmp2_coef7(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_7_get_mmr_coef_cmp2_coef7(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8                        0x1806B26C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_reg_addr               "0xB806B26C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_reg                    0xB806B26C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_inst_addr              "0x009B"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_mmr_coef_cmp2_coef8_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_mmr_coef_cmp2_coef8_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_mmr_coef_cmp2_coef8(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_8_get_mmr_coef_cmp2_coef8(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9                        0x1806B270
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_reg_addr               "0xB806B270"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_reg                    0xB806B270
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_inst_addr              "0x009C"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_reg(data)          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_reg                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_mmr_coef_cmp2_coef9_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_mmr_coef_cmp2_coef9_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_mmr_coef_cmp2_coef9(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_9_get_mmr_coef_cmp2_coef9(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10                       0x1806B274
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_reg_addr              "0xB806B274"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_reg                   0xB806B274
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_inst_addr             "0x009D"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_mmr_coef_cmp2_coef10_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_mmr_coef_cmp2_coef10_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_mmr_coef_cmp2_coef10(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_10_get_mmr_coef_cmp2_coef10(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11                       0x1806B278
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_reg_addr              "0xB806B278"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_reg                   0xB806B278
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_inst_addr             "0x009E"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_mmr_coef_cmp2_coef11_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_mmr_coef_cmp2_coef11_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_mmr_coef_cmp2_coef11(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_11_get_mmr_coef_cmp2_coef11(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12                       0x1806B27C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_reg_addr              "0xB806B27C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_reg                   0xB806B27C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_inst_addr             "0x009F"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_mmr_coef_cmp2_coef12_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_mmr_coef_cmp2_coef12_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_mmr_coef_cmp2_coef12(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_12_get_mmr_coef_cmp2_coef12(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13                       0x1806B280
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_reg_addr              "0xB806B280"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_reg                   0xB806B280
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_inst_addr             "0x00A0"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_mmr_coef_cmp2_coef13_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_mmr_coef_cmp2_coef13_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_mmr_coef_cmp2_coef13(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_13_get_mmr_coef_cmp2_coef13(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14                       0x1806B284
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_reg_addr              "0xB806B284"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_reg                   0xB806B284
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_inst_addr             "0x00A1"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_mmr_coef_cmp2_coef14_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_mmr_coef_cmp2_coef14_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_mmr_coef_cmp2_coef14(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_14_get_mmr_coef_cmp2_coef14(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15                       0x1806B288
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_reg_addr              "0xB806B288"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_reg                   0xB806B288
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_inst_addr             "0x00A2"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_mmr_coef_cmp2_coef15_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_mmr_coef_cmp2_coef15_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_mmr_coef_cmp2_coef15(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_15_get_mmr_coef_cmp2_coef15(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16                       0x1806B28C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_reg_addr              "0xB806B28C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_reg                   0xB806B28C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_inst_addr             "0x00A3"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_mmr_coef_cmp2_coef16_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_mmr_coef_cmp2_coef16_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_mmr_coef_cmp2_coef16(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_16_get_mmr_coef_cmp2_coef16(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17                       0x1806B290
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_reg_addr              "0xB806B290"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_reg                   0xB806B290
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_inst_addr             "0x00A4"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_mmr_coef_cmp2_coef17_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_mmr_coef_cmp2_coef17_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_mmr_coef_cmp2_coef17(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_17_get_mmr_coef_cmp2_coef17(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18                       0x1806B294
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_reg_addr              "0xB806B294"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_reg                   0xB806B294
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_inst_addr             "0x00A5"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_mmr_coef_cmp2_coef18_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_mmr_coef_cmp2_coef18_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_mmr_coef_cmp2_coef18(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_18_get_mmr_coef_cmp2_coef18(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19                       0x1806B298
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_reg_addr              "0xB806B298"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_reg                   0xB806B298
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_inst_addr             "0x00A6"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_mmr_coef_cmp2_coef19_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_mmr_coef_cmp2_coef19_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_mmr_coef_cmp2_coef19(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_19_get_mmr_coef_cmp2_coef19(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20                       0x1806B29C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_reg_addr              "0xB806B29C"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_reg                   0xB806B29C
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_inst_addr             "0x00A7"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_mmr_coef_cmp2_coef20_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_mmr_coef_cmp2_coef20_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_mmr_coef_cmp2_coef20(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_20_get_mmr_coef_cmp2_coef20(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21                       0x1806B2A0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_reg_addr              "0xB806B2A0"
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_reg                   0xB806B2A0
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_inst_addr             "0x00A8"
#define  set_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_reg(data)         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_reg               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_mmr_coef_cmp2_coef21_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_mmr_coef_cmp2_coef21_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_mmr_coef_cmp2_coef21(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Pred_MMR_Cmp2_Coef_21_get_mmr_coef_cmp2_coef21(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_Up                                          0x1806B2A4
#define  DHDR_V_COMPOSER_Composer_BL_Up_reg_addr                                 "0xB806B2A4"
#define  DHDR_V_COMPOSER_Composer_BL_Up_reg                                      0xB806B2A4
#define  DHDR_V_COMPOSER_Composer_BL_Up_inst_addr                                "0x00A9"
#define  set_DHDR_V_COMPOSER_Composer_BL_Up_reg(data)                            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Up_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_Up_reg                                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_Up_reg))
#define  DHDR_V_COMPOSER_Composer_BL_Up_spatial_resampling_filter_flag_shift     (0)
#define  DHDR_V_COMPOSER_Composer_BL_Up_spatial_resampling_filter_flag_mask      (0x00000001)
#define  DHDR_V_COMPOSER_Composer_BL_Up_spatial_resampling_filter_flag(data)     (0x00000001&(data))
#define  DHDR_V_COMPOSER_Composer_BL_Up_get_spatial_resampling_filter_flag(data) (0x00000001&(data))

#define  DHDR_V_COMPOSER_Composer_EL_RS                                          0x1806B2A8
#define  DHDR_V_COMPOSER_Composer_EL_RS_reg_addr                                 "0xB806B2A8"
#define  DHDR_V_COMPOSER_Composer_EL_RS_reg                                      0xB806B2A8
#define  DHDR_V_COMPOSER_Composer_EL_RS_inst_addr                                "0x00AA"
#define  set_DHDR_V_COMPOSER_Composer_EL_RS_reg(data)                            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RS_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_RS_reg                                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RS_reg))
#define  DHDR_V_COMPOSER_Composer_EL_RS_el_spatial_resampling_filter_flag_shift  (0)
#define  DHDR_V_COMPOSER_Composer_EL_RS_el_spatial_resampling_filter_flag_mask   (0x00000001)
#define  DHDR_V_COMPOSER_Composer_EL_RS_el_spatial_resampling_filter_flag(data)  (0x00000001&(data))
#define  DHDR_V_COMPOSER_Composer_EL_RS_get_el_spatial_resampling_filter_flag(data) (0x00000001&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ                                          0x1806B2AC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_reg_addr                                 "0xB806B2AC"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_reg                                      0xB806B2AC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_inst_addr                                "0x00AB"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_reg(data)                            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_reg                                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_disable_residual_flag_shift              (1)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_nlq_method_idc_shift                     (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_disable_residual_flag_mask               (0x00000002)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_nlq_method_idc_mask                      (0x00000001)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_disable_residual_flag(data)              (0x00000002&((data)<<1))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_nlq_method_idc(data)                     (0x00000001&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_get_disable_residual_flag(data)          ((0x00000002&(data))>>1)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_get_nlq_method_idc(data)                 (0x00000001&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01                                0x1806B2B0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_reg_addr                       "0xB806B2B0"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_reg                            0xB806B2B0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_inst_addr                      "0x00AC"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_reg(data)                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_reg                        (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_nlq_offset_cmp1_shift          (16)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_nlq_offset_cmp0_shift          (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_nlq_offset_cmp1_mask           (0x03FF0000)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_nlq_offset_cmp0_mask           (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_nlq_offset_cmp1(data)          (0x03FF0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_nlq_offset_cmp0(data)          (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_get_nlq_offset_cmp1(data)      ((0x03FF0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_01_get_nlq_offset_cmp0(data)      (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2                                 0x1806B2B4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_reg_addr                        "0xB806B2B4"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_reg                             0xB806B2B4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_inst_addr                       "0x00AD"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_reg(data)                   (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_reg                         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_nlq_offset_cmp2_shift           (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_nlq_offset_cmp2_mask            (0x000003FF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_nlq_offset_cmp2(data)           (0x000003FF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_offset_2_get_nlq_offset_cmp2(data)       (0x000003FF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0                              0x1806B2B8
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_reg_addr                     "0xB806B2B8"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_reg                          0xB806B2B8
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_inst_addr                    "0x00AE"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_reg(data)                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_reg                      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_linear_deadzone_slope_cmp0_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_linear_deadzone_slope_cmp0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_linear_deadzone_slope_cmp0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_0_get_linear_deadzone_slope_cmp0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1                              0x1806B2BC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_reg_addr                     "0xB806B2BC"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_reg                          0xB806B2BC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_inst_addr                    "0x00AF"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_reg(data)                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_reg                      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_linear_deadzone_slope_cmp1_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_linear_deadzone_slope_cmp1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_linear_deadzone_slope_cmp1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_1_get_linear_deadzone_slope_cmp1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2                              0x1806B2C0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_reg_addr                     "0xB806B2C0"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_reg                          0xB806B2C0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_inst_addr                    "0x00B0"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_reg(data)                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_reg                      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_linear_deadzone_slope_cmp2_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_linear_deadzone_slope_cmp2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_linear_deadzone_slope_cmp2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Slop_2_get_linear_deadzone_slope_cmp2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0                                0x1806B2C4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_reg_addr                       "0xB806B2C4"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_reg                            0xB806B2C4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_inst_addr                      "0x00B1"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_reg(data)                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_reg                        (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_linear_deadzone_threshold_cmp0_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_linear_deadzone_threshold_cmp0_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_linear_deadzone_threshold_cmp0(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_0_get_linear_deadzone_threshold_cmp0(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1                                0x1806B2C8
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_reg_addr                       "0xB806B2C8"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_reg                            0xB806B2C8
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_inst_addr                      "0x00B2"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_reg(data)                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_reg                        (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_linear_deadzone_threshold_cmp1_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_linear_deadzone_threshold_cmp1_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_linear_deadzone_threshold_cmp1(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_1_get_linear_deadzone_threshold_cmp1(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2                                0x1806B2CC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_reg_addr                       "0xB806B2CC"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_reg                            0xB806B2CC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_inst_addr                      "0x00B3"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_reg(data)                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_reg                        (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_linear_deadzone_threshold_cmp2_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_linear_deadzone_threshold_cmp2_mask (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_linear_deadzone_threshold_cmp2(data) (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Th_2_get_linear_deadzone_threshold_cmp2(data) (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0                               0x1806B2D0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_reg_addr                      "0xB806B2D0"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_reg                           0xB806B2D0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_inst_addr                     "0x00B4"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_reg(data)                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_reg                       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_vdr_in_max_cmp0_shift         (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_vdr_in_max_cmp0_mask          (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_vdr_in_max_cmp0(data)         (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_0_get_vdr_in_max_cmp0(data)     (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1                               0x1806B2D4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_reg_addr                      "0xB806B2D4"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_reg                           0xB806B2D4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_inst_addr                     "0x00B5"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_reg(data)                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_reg                       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_vdr_in_max_cmp1_shift         (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_vdr_in_max_cmp1_mask          (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_vdr_in_max_cmp1(data)         (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_1_get_vdr_in_max_cmp1(data)     (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2                               0x1806B2D8
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_reg_addr                      "0xB806B2D8"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_reg                           0xB806B2D8
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_inst_addr                     "0x00B6"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_reg(data)                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_reg                       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_vdr_in_max_cmp2_shift         (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_vdr_in_max_cmp2_mask          (0x007FFFFF)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_vdr_in_max_cmp2(data)         (0x007FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_Max_2_get_vdr_in_max_cmp2(data)     (0x007FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop                            0x1806B2DC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_reg_addr                   "0xB806B2DC"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_reg                        0xB806B2DC
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_inst_addr                  "0x00B7"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_reg(data)              (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_reg                    (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp2_shift (8)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp1_shift (4)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp0_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp2_mask (0x00000300)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp1_mask (0x00000030)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp0_mask (0x00000003)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp2(data) (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp1(data) (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_linear_deadzone_slope_int_cmp0(data) (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_get_linear_deadzone_slope_int_cmp2(data) ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_get_linear_deadzone_slope_int_cmp1(data) ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Slop_get_linear_deadzone_slope_int_cmp0(data) (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th                              0x1806B2E0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_reg_addr                     "0xB806B2E0"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_reg                          0xB806B2E0
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_inst_addr                    "0x00B8"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_reg(data)                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_reg                      (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp2_shift (8)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp1_shift (4)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp0_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp2_mask (0x00000300)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp1_mask (0x00000030)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp0_mask (0x00000003)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp2(data) (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp1(data) (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_linear_deadzone_threshold_int_cmp0(data) (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_get_linear_deadzone_threshold_int_cmp2(data) ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_get_linear_deadzone_threshold_int_cmp1(data) ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Th_get_linear_deadzone_threshold_int_cmp0(data) (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max                             0x1806B2E4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_reg_addr                    "0xB806B2E4"
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_reg                         0xB806B2E4
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_inst_addr                   "0x00B9"
#define  set_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_reg(data)               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_reg                     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_reg))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp2_shift   (8)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp1_shift   (4)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp0_shift   (0)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp2_mask    (0x00000300)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp1_mask    (0x00000030)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp0_mask    (0x00000003)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp2(data)   (0x00000300&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp1(data)   (0x00000030&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_vdr_in_max_int_cmp0(data)   (0x00000003&(data))
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_get_vdr_in_max_int_cmp2(data) ((0x00000300&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_get_vdr_in_max_int_cmp1(data) ((0x00000030&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_EL_IQ_Coef_INT_Max_get_vdr_in_max_int_cmp0(data) (0x00000003&(data))

#define  DHDR_V_COMPOSER_Composer_BL_RME                                         0x1806B2E8
#define  DHDR_V_COMPOSER_Composer_BL_RME_reg_addr                                "0xB806B2E8"
#define  DHDR_V_COMPOSER_Composer_BL_RME_reg                                     0xB806B2E8
#define  DHDR_V_COMPOSER_Composer_BL_RME_inst_addr                               "0x00BA"
#define  set_DHDR_V_COMPOSER_Composer_BL_RME_reg(data)                           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_RME_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_RME_reg                                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_RME_reg))
#define  DHDR_V_COMPOSER_Composer_BL_RME_composer_bl_ls_shift                    (29)
#define  DHDR_V_COMPOSER_Composer_BL_RME_composer_bl_rme_shift                   (0)
#define  DHDR_V_COMPOSER_Composer_BL_RME_composer_bl_ls_mask                     (0xE0000000)
#define  DHDR_V_COMPOSER_Composer_BL_RME_composer_bl_rme_mask                    (0x00000007)
#define  DHDR_V_COMPOSER_Composer_BL_RME_composer_bl_ls(data)                    (0xE0000000&((data)<<29))
#define  DHDR_V_COMPOSER_Composer_BL_RME_composer_bl_rme(data)                   (0x00000007&(data))
#define  DHDR_V_COMPOSER_Composer_BL_RME_get_composer_bl_ls(data)                ((0xE0000000&(data))>>29)
#define  DHDR_V_COMPOSER_Composer_BL_RME_get_composer_bl_rme(data)               (0x00000007&(data))

#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0                                       0x1806B2EC
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_reg_addr                              "0xB806B2EC"
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_reg                                   0xB806B2EC
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_inst_addr                             "0x00BB"
#define  set_DHDR_V_COMPOSER_Composer_BL_RM_Y0_reg(data)                         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_RM_Y0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_RM_Y0_reg                               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_RM_Y0_reg))
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_composer_bl_rm_y1_shift               (4)
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_composer_bl_rm_y0_shift               (0)
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_composer_bl_rm_y1_mask                (0x000000F0)
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_composer_bl_rm_y0_mask                (0x0000000F)
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_composer_bl_rm_y1(data)               (0x000000F0&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_composer_bl_rm_y0(data)               (0x0000000F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_get_composer_bl_rm_y1(data)           ((0x000000F0&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_BL_RM_Y0_get_composer_bl_rm_y0(data)           (0x0000000F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_RM_UV                                       0x1806B2F4
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_reg_addr                              "0xB806B2F4"
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_reg                                   0xB806B2F4
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_inst_addr                             "0x00BC"
#define  set_DHDR_V_COMPOSER_Composer_BL_RM_UV_reg(data)                         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_RM_UV_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_RM_UV_reg                               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_RM_UV_reg))
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_composer_bl_rm_uv0_shift              (0)
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_composer_bl_rm_uv0_mask               (0x0000000F)
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_composer_bl_rm_uv0(data)              (0x0000000F&(data))
#define  DHDR_V_COMPOSER_Composer_BL_RM_UV_get_composer_bl_rm_uv0(data)          (0x0000000F&(data))

#define  DHDR_V_COMPOSER_Composer_BL_bist_fail                                   0x1806B2F8
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_reg_addr                          "0xB806B2F8"
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_reg                               0xB806B2F8
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_inst_addr                         "0x00BD"
#define  set_DHDR_V_COMPOSER_Composer_BL_bist_fail_reg(data)                     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_bist_fail_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_bist_fail_reg                           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_bist_fail_reg))
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group2_shift (31)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group1_shift (30)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group0_shift (29)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_shift       (0)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group2_mask (0x80000000)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group1_mask (0x40000000)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group0_mask (0x20000000)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_mask        (0x001FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group2(data) (0x80000000&((data)<<31))
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group1(data) (0x40000000&((data)<<30))
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail_group0(data) (0x20000000&((data)<<29))
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_composer_bl_bist_fail(data)       (0x001FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_get_composer_bl_bist_fail_group2(data) ((0x80000000&(data))>>31)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_get_composer_bl_bist_fail_group1(data) ((0x40000000&(data))>>30)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_get_composer_bl_bist_fail_group0(data) ((0x20000000&(data))>>29)
#define  DHDR_V_COMPOSER_Composer_BL_bist_fail_get_composer_bl_bist_fail(data)   (0x001FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail                               0x1806B2FC
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_reg_addr                      "0xB806B2FC"
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_reg                           0xB806B2FC
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_inst_addr                     "0x00BE"
#define  set_DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_reg(data)                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_reg                       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_reg))
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group2_shift (31)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group1_shift (30)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group0_shift (29)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_shift (0)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group2_mask (0x80000000)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group1_mask (0x40000000)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group0_mask (0x20000000)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_mask (0x001FFFFF)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group2(data) (0x80000000&((data)<<31))
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group1(data) (0x40000000&((data)<<30))
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail_group0(data) (0x20000000&((data)<<29))
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_composer_bl_drf_bist_fail(data) (0x001FFFFF&(data))
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_get_composer_bl_drf_bist_fail_group2(data) ((0x80000000&(data))>>31)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_get_composer_bl_drf_bist_fail_group1(data) ((0x40000000&(data))>>30)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_get_composer_bl_drf_bist_fail_group0(data) ((0x20000000&(data))>>29)
#define  DHDR_V_COMPOSER_Composer_BL_drf_bist_fail_get_composer_bl_drf_bist_fail(data) (0x001FFFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_RME                                         0x1806B300
#define  DHDR_V_COMPOSER_Composer_EL_RME_reg_addr                                "0xB806B300"
#define  DHDR_V_COMPOSER_Composer_EL_RME_reg                                     0xB806B300
#define  DHDR_V_COMPOSER_Composer_EL_RME_inst_addr                               "0x00BF"
#define  set_DHDR_V_COMPOSER_Composer_EL_RME_reg(data)                           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RME_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_RME_reg                                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RME_reg))
#define  DHDR_V_COMPOSER_Composer_EL_RME_composer_el_rme_shift                   (0)
#define  DHDR_V_COMPOSER_Composer_EL_RME_composer_el_rme_mask                    (0x0007FFFF)
#define  DHDR_V_COMPOSER_Composer_EL_RME_composer_el_rme(data)                   (0x0007FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_RME_get_composer_el_rme(data)               (0x0007FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0                                       0x1806B304
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_reg_addr                              "0xB806B304"
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_reg                                   0xB806B304
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_inst_addr                             "0x00C0"
#define  set_DHDR_V_COMPOSER_Composer_EL_RM_Y0_reg(data)                         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RM_Y0_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_RM_Y0_reg                               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RM_Y0_reg))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_7_shift                (28)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_6_shift                (24)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_5_shift                (20)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_4_shift                (16)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_3_shift                (12)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_2_shift                (8)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_1_shift                (4)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_0_shift                (0)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_7_mask                 (0xF0000000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_6_mask                 (0x0F000000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_5_mask                 (0x00F00000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_4_mask                 (0x000F0000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_3_mask                 (0x0000F000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_2_mask                 (0x00000F00)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_1_mask                 (0x000000F0)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_0_mask                 (0x0000000F)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_7(data)                (0xF0000000&((data)<<28))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_6(data)                (0x0F000000&((data)<<24))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_5(data)                (0x00F00000&((data)<<20))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_4(data)                (0x000F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_3(data)                (0x0000F000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_2(data)                (0x00000F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_1(data)                (0x000000F0&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_composer_el_rm_0(data)                (0x0000000F&(data))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_7(data)            ((0xF0000000&(data))>>28)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_6(data)            ((0x0F000000&(data))>>24)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_5(data)            ((0x00F00000&(data))>>20)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_4(data)            ((0x000F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_3(data)            ((0x0000F000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_2(data)            ((0x00000F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_1(data)            ((0x000000F0&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y0_get_composer_el_rm_0(data)            (0x0000000F&(data))

#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1                                       0x1806B308
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_reg_addr                              "0xB806B308"
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_reg                                   0xB806B308
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_inst_addr                             "0x00C1"
#define  set_DHDR_V_COMPOSER_Composer_EL_RM_Y1_reg(data)                         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RM_Y1_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_RM_Y1_reg                               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RM_Y1_reg))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_11_shift               (12)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_10_shift               (8)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_9_shift                (4)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_8_shift                (0)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_11_mask                (0x0000F000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_10_mask                (0x00000F00)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_9_mask                 (0x000000F0)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_8_mask                 (0x0000000F)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_11(data)               (0x0000F000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_10(data)               (0x00000F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_9(data)                (0x000000F0&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_composer_el_rm_8(data)                (0x0000000F&(data))
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_get_composer_el_rm_11(data)           ((0x0000F000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_get_composer_el_rm_10(data)           ((0x00000F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_get_composer_el_rm_9(data)            ((0x000000F0&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_EL_RM_Y1_get_composer_el_rm_8(data)            (0x0000000F&(data))

#define  DHDR_V_COMPOSER_Composer_EL_RM_UV                                       0x1806B30C
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_reg_addr                              "0xB806B30C"
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_reg                                   0xB806B30C
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_inst_addr                             "0x00C2"
#define  set_DHDR_V_COMPOSER_Composer_EL_RM_UV_reg(data)                         (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RM_UV_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_RM_UV_reg                               (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_RM_UV_reg))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_18_shift               (24)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_17_shift               (20)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_16_shift               (16)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_15_shift               (12)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_14_shift               (8)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_13_shift               (4)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_12_shift               (0)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_18_mask                (0x0F000000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_17_mask                (0x00F00000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_16_mask                (0x000F0000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_15_mask                (0x0000F000)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_14_mask                (0x00000F00)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_13_mask                (0x000000F0)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_12_mask                (0x0000000F)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_18(data)               (0x0F000000&((data)<<24))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_17(data)               (0x00F00000&((data)<<20))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_16(data)               (0x000F0000&((data)<<16))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_15(data)               (0x0000F000&((data)<<12))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_14(data)               (0x00000F00&((data)<<8))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_13(data)               (0x000000F0&((data)<<4))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_composer_el_rm_12(data)               (0x0000000F&(data))
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_18(data)           ((0x0F000000&(data))>>24)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_17(data)           ((0x00F00000&(data))>>20)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_16(data)           ((0x000F0000&(data))>>16)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_15(data)           ((0x0000F000&(data))>>12)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_14(data)           ((0x00000F00&(data))>>8)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_13(data)           ((0x000000F0&(data))>>4)
#define  DHDR_V_COMPOSER_Composer_EL_RM_UV_get_composer_el_rm_12(data)           (0x0000000F&(data))

#define  DHDR_V_COMPOSER_Composer_EL_bist_fail                                   0x1806B310
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_reg_addr                          "0xB806B310"
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_reg                               0xB806B310
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_inst_addr                         "0x00C3"
#define  set_DHDR_V_COMPOSER_Composer_EL_bist_fail_reg(data)                     (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_bist_fail_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_bist_fail_reg                           (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_bist_fail_reg))
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_composer_el_bist_fail_shift       (0)
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_composer_el_bist_fail_mask        (0x0007FFFF)
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_composer_el_bist_fail(data)       (0x0007FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_bist_fail_get_composer_el_bist_fail(data)   (0x0007FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail                               0x1806B314
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_reg_addr                      "0xB806B314"
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_reg                           0xB806B314
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_inst_addr                     "0x00C4"
#define  set_DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_reg(data)                 (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_reg                       (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_reg))
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_composer_el_drf_bist_fail_shift (0)
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_composer_el_drf_bist_fail_mask (0x0007FFFF)
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_composer_el_drf_bist_fail(data) (0x0007FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_drf_bist_fail_get_composer_el_drf_bist_fail(data) (0x0007FFFF&(data))

#define  DHDR_V_COMPOSER_Composer_db_ctrl                                        0x1806B318
#define  DHDR_V_COMPOSER_Composer_db_ctrl_reg_addr                               "0xB806B318"
#define  DHDR_V_COMPOSER_Composer_db_ctrl_reg                                    0xB806B318
#define  DHDR_V_COMPOSER_Composer_db_ctrl_inst_addr                              "0x00C5"
#define  set_DHDR_V_COMPOSER_Composer_db_ctrl_reg(data)                          (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_db_ctrl_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_db_ctrl_reg                                (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_db_ctrl_reg))
#define  DHDR_V_COMPOSER_Composer_db_ctrl_composer_db_en_shift                   (2)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_composer_db_apply_shift                (1)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_db_read_shift                          (0)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_composer_db_en_mask                    (0x00000004)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_composer_db_apply_mask                 (0x00000002)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_db_read_mask                           (0x00000001)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_composer_db_en(data)                   (0x00000004&((data)<<2))
#define  DHDR_V_COMPOSER_Composer_db_ctrl_composer_db_apply(data)                (0x00000002&((data)<<1))
#define  DHDR_V_COMPOSER_Composer_db_ctrl_db_read(data)                          (0x00000001&(data))
#define  DHDR_V_COMPOSER_Composer_db_ctrl_get_composer_db_en(data)               ((0x00000004&(data))>>2)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_get_composer_db_apply(data)            ((0x00000002&(data))>>1)
#define  DHDR_V_COMPOSER_Composer_db_ctrl_get_db_read(data)                      (0x00000001&(data))

#define  DHDR_V_COMPOSER_Composer_EL_LS                                          0x1806B31C
#define  DHDR_V_COMPOSER_Composer_EL_LS_reg_addr                                 "0xB806B31C"
#define  DHDR_V_COMPOSER_Composer_EL_LS_reg                                      0xB806B31C
#define  DHDR_V_COMPOSER_Composer_EL_LS_inst_addr                                "0x00C6"
#define  set_DHDR_V_COMPOSER_Composer_EL_LS_reg(data)                            (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_LS_reg)=data)
#define  get_DHDR_V_COMPOSER_Composer_EL_LS_reg                                  (*((volatile unsigned int*)DHDR_V_COMPOSER_Composer_EL_LS_reg))
#define  DHDR_V_COMPOSER_Composer_EL_LS_composer_el_ls_shift                     (0)
#define  DHDR_V_COMPOSER_Composer_EL_LS_composer_el_ls_mask                      (0x0007FFFF)
#define  DHDR_V_COMPOSER_Composer_EL_LS_composer_el_ls(data)                     (0x0007FFFF&(data))
#define  DHDR_V_COMPOSER_Composer_EL_LS_get_composer_el_ls(data)                 (0x0007FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DHDR_V_COMPOSER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  vdr_bit_depth:5;
        RBus_UInt32  el_bit_depth:4;
        RBus_UInt32  bl_bit_depth:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  coefficient_log2_denom:5;
    };
}dhdr_v_composer_composer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  num_pivots_cmp2:4;
        RBus_UInt32  num_pivots_cmp1:4;
        RBus_UInt32  num_pivots_cmp0:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  mapping_idc_cmp2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  mapping_idc_cmp1:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  mapping_idc_cmp0:2;
    };
}dhdr_v_composer_composer_bl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp0_pivot_0:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_3:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp0_pivot_2:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_5:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp0_pivot_4:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_7:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp0_pivot_6:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pivot_value_cmp0_pivot_8:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp1_pivot_1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp1_pivot_0:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp1_p01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp1_pivot_3:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp1_pivot_2:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp1_p23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pivot_value_cmp1_pivot_4:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp1_p45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp2_pivot_1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp2_pivot_0:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp2_p01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp2_pivot_3:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  pivot_value_cmp2_pivot_2:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp2_p23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  pivot_value_cmp2_pivot_4:10;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp2_p45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  poly_order_cmp0_pivot7:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  poly_order_cmp0_pivot6:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  poly_order_cmp0_pivot5:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  poly_order_cmp0_pivot4:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  poly_order_cmp0_pivot3:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  poly_order_cmp0_pivot2:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  poly_order_cmp0_pivot1:2;
        RBus_UInt32  res8:2;
        RBus_UInt32  poly_order_cmp0_pivot0:2;
    };
}dhdr_v_composer_composer_bl_pred_poly_order_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  poly_order_cmp1_pivot3:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  poly_order_cmp1_pivot2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  poly_order_cmp1_pivot1:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  poly_order_cmp1_pivot0:2;
    };
}dhdr_v_composer_composer_bl_pred_poly_order_chroma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  poly_order_cmp2_pivot3:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  poly_order_cmp2_pivot2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  poly_order_cmp2_pivot1:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  poly_order_cmp2_pivot0:2;
    };
}dhdr_v_composer_composer_bl_pred_poly_order_chroma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot0_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot0_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot0_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot1_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot1_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot1_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot2_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot2_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot2_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot3_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot3_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot3_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot4_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot4_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot4_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot5_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot5_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot5_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot6_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot6_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot6_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp0_pivot7_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot7_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot7_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp1_pivot0_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot0_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot0_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp1_pivot1_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot1_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot1_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp1_pivot2_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot2_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot2_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp1_pivot3_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot3_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot3_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp2_pivot0_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot0_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot0_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp2_pivot1_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot1_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot1_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp2_pivot2_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot2_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot2_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_int_cmp2_pivot3_i2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot3_i1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot3_i0:7;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot0_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p0_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot0_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p0_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot0_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p0_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot1_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p1_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot1_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p1_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot1_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p1_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot2_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p2_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot2_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p2_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot2_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p2_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot3_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p3_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot3_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p3_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot3_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p3_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot4_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p4_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot4_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p4_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot4_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p4_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot5_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p5_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot5_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p5_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot5_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p5_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot6_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p6_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot6_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p6_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot6_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p6_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot7_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p7_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot7_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p7_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp0_pivot7_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p7_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot0_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p0_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot0_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p0_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot0_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p0_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot1_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p1_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot1_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p1_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot1_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p1_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot2_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p2_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot2_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p2_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot2_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p2_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot3_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p3_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot3_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p3_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp1_pivot3_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p3_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot0_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p0_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot0_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p0_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot0_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p0_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot1_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p1_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot1_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p1_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot1_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p1_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot2_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p2_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot2_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p2_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot2_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p2_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot3_i0:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p3_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot3_i1:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p3_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  poly_coef_cmp2_pivot3_i2:23;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p3_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mmr_order_cmp2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mmr_order_cmp1:2;
    };
}dhdr_v_composer_composer_bl_pred_mmr_order_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef0:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef1:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef2:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef3:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef4:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef5:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef6:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef7:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef8:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef9:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef10:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef11:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef12:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef13:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef14:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef15:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef16:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef17:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef18:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef19:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef20:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp1_coef21:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef0:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef1:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef2:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef3:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef4:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef5:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef6:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef7:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef8:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef9:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef10:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef11:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef12:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef13:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef14:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef15:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef16:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef17:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef18:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef19:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef20:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  mmr_coef_int_cmp2_coef21:17;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef0:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef1:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef2:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef3:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef4:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef5:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef6:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef7:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef8:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef9:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef10:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef11:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef12:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef13:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef14:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef15:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef16:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef17:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef18:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef19:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef20:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp1_coef21:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef0:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef1:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef2:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef3:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef4:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef5:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef6:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef7:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef8:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef9:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef10:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef11:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef12:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef13:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef14:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef15:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef16:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef17:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef18:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef19:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef20:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  mmr_coef_cmp2_coef21:23;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spatial_resampling_filter_flag:1;
    };
}dhdr_v_composer_composer_bl_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  el_spatial_resampling_filter_flag:1;
    };
}dhdr_v_composer_composer_el_rs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  disable_residual_flag:1;
        RBus_UInt32  nlq_method_idc:1;
    };
}dhdr_v_composer_composer_el_iq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  nlq_offset_cmp1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  nlq_offset_cmp0:10;
    };
}dhdr_v_composer_composer_el_iq_offset_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  nlq_offset_cmp2:10;
    };
}dhdr_v_composer_composer_el_iq_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  linear_deadzone_slope_cmp0:23;
    };
}dhdr_v_composer_composer_el_iq_coef_slop_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  linear_deadzone_slope_cmp1:23;
    };
}dhdr_v_composer_composer_el_iq_coef_slop_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  linear_deadzone_slope_cmp2:23;
    };
}dhdr_v_composer_composer_el_iq_coef_slop_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  linear_deadzone_threshold_cmp0:23;
    };
}dhdr_v_composer_composer_el_iq_coef_th_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  linear_deadzone_threshold_cmp1:23;
    };
}dhdr_v_composer_composer_el_iq_coef_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  linear_deadzone_threshold_cmp2:23;
    };
}dhdr_v_composer_composer_el_iq_coef_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  vdr_in_max_cmp0:23;
    };
}dhdr_v_composer_composer_el_iq_coef_max_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  vdr_in_max_cmp1:23;
    };
}dhdr_v_composer_composer_el_iq_coef_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  vdr_in_max_cmp2:23;
    };
}dhdr_v_composer_composer_el_iq_coef_max_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  linear_deadzone_slope_int_cmp2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  linear_deadzone_slope_int_cmp1:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  linear_deadzone_slope_int_cmp0:2;
    };
}dhdr_v_composer_composer_el_iq_coef_int_slop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  linear_deadzone_threshold_int_cmp2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  linear_deadzone_threshold_int_cmp1:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  linear_deadzone_threshold_int_cmp0:2;
    };
}dhdr_v_composer_composer_el_iq_coef_int_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  vdr_in_max_int_cmp2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  vdr_in_max_int_cmp1:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  vdr_in_max_int_cmp0:2;
    };
}dhdr_v_composer_composer_el_iq_coef_int_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_ls:3;
        RBus_UInt32  res1:26;
        RBus_UInt32  composer_bl_rme:3;
    };
}dhdr_v_composer_composer_bl_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  composer_bl_rm_y1:4;
        RBus_UInt32  composer_bl_rm_y0:4;
    };
}dhdr_v_composer_composer_bl_rm_y0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dhdr_v_composer_composer_bl_rm_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  composer_bl_rm_uv0:4;
    };
}dhdr_v_composer_composer_bl_rm_uv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_bist_fail_group2:1;
        RBus_UInt32  composer_bl_bist_fail_group1:1;
        RBus_UInt32  composer_bl_bist_fail_group0:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  composer_bl_bist_fail:21;
    };
}dhdr_v_composer_composer_bl_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_drf_bist_fail_group2:1;
        RBus_UInt32  composer_bl_drf_bist_fail_group1:1;
        RBus_UInt32  composer_bl_drf_bist_fail_group0:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  composer_bl_drf_bist_fail:21;
    };
}dhdr_v_composer_composer_bl_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_rme:19;
    };
}dhdr_v_composer_composer_el_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_rm_7:4;
        RBus_UInt32  composer_el_rm_6:4;
        RBus_UInt32  composer_el_rm_5:4;
        RBus_UInt32  composer_el_rm_4:4;
        RBus_UInt32  composer_el_rm_3:4;
        RBus_UInt32  composer_el_rm_2:4;
        RBus_UInt32  composer_el_rm_1:4;
        RBus_UInt32  composer_el_rm_0:4;
    };
}dhdr_v_composer_composer_el_rm_y0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  composer_el_rm_11:4;
        RBus_UInt32  composer_el_rm_10:4;
        RBus_UInt32  composer_el_rm_9:4;
        RBus_UInt32  composer_el_rm_8:4;
    };
}dhdr_v_composer_composer_el_rm_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  composer_el_rm_18:4;
        RBus_UInt32  composer_el_rm_17:4;
        RBus_UInt32  composer_el_rm_16:4;
        RBus_UInt32  composer_el_rm_15:4;
        RBus_UInt32  composer_el_rm_14:4;
        RBus_UInt32  composer_el_rm_13:4;
        RBus_UInt32  composer_el_rm_12:4;
    };
}dhdr_v_composer_composer_el_rm_uv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_bist_fail:19;
    };
}dhdr_v_composer_composer_el_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_drf_bist_fail:19;
    };
}dhdr_v_composer_composer_el_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  composer_db_en:1;
        RBus_UInt32  composer_db_apply:1;
        RBus_UInt32  db_read:1;
    };
}dhdr_v_composer_composer_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_ls:19;
    };
}dhdr_v_composer_composer_el_ls_RBUS;

#else //apply LITTLE_ENDIAN

//======DHDR_V_COMPOSER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coefficient_log2_denom:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  bl_bit_depth:4;
        RBus_UInt32  el_bit_depth:4;
        RBus_UInt32  vdr_bit_depth:5;
        RBus_UInt32  res2:11;
    };
}dhdr_v_composer_composer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mapping_idc_cmp0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  mapping_idc_cmp1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mapping_idc_cmp2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  num_pivots_cmp0:4;
        RBus_UInt32  num_pivots_cmp1:4;
        RBus_UInt32  num_pivots_cmp2:4;
        RBus_UInt32  res4:8;
    };
}dhdr_v_composer_composer_bl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp0_pivot_0:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_1:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp0_pivot_2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_3:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp0_pivot_4:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_5:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp0_pivot_6:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp0_pivot_7:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp0_pivot_8:10;
        RBus_UInt32  res1:22;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp0_p8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp1_pivot_0:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp1_pivot_1:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp1_p01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp1_pivot_2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp1_pivot_3:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp1_p23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp1_pivot_4:10;
        RBus_UInt32  res1:22;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp1_p45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp2_pivot_0:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp2_pivot_1:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp2_p01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp2_pivot_2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pivot_value_cmp2_pivot_3:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp2_p23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pivot_value_cmp2_pivot_4:10;
        RBus_UInt32  res1:22;
    };
}dhdr_v_composer_composer_bl_pivot_val_cmp2_p45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_order_cmp0_pivot0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  poly_order_cmp0_pivot1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  poly_order_cmp0_pivot2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  poly_order_cmp0_pivot3:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  poly_order_cmp0_pivot4:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  poly_order_cmp0_pivot5:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  poly_order_cmp0_pivot6:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  poly_order_cmp0_pivot7:2;
        RBus_UInt32  res8:2;
    };
}dhdr_v_composer_composer_bl_pred_poly_order_luma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_order_cmp1_pivot0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  poly_order_cmp1_pivot1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  poly_order_cmp1_pivot2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  poly_order_cmp1_pivot3:2;
        RBus_UInt32  res4:18;
    };
}dhdr_v_composer_composer_bl_pred_poly_order_chroma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_order_cmp2_pivot0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  poly_order_cmp2_pivot1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  poly_order_cmp2_pivot2:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  poly_order_cmp2_pivot3:2;
        RBus_UInt32  res4:18;
    };
}dhdr_v_composer_composer_bl_pred_poly_order_chroma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot0_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot0_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot0_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot1_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot1_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot1_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot2_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot2_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot2_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot3_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot3_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot3_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot4_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot4_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot4_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot5_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot5_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot5_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot6_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot6_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot6_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp0_pivot7_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot7_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp0_pivot7_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp0_p7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp1_pivot0_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot0_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot0_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp1_pivot1_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot1_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot1_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp1_pivot2_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot2_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot2_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp1_pivot3_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot3_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp1_pivot3_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp1_p3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp2_pivot0_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot0_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot0_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp2_pivot1_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot1_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot1_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp2_pivot2_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot2_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot2_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_int_cmp2_pivot3_i0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot3_i1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  poly_coef_int_cmp2_pivot3_i2:7;
        RBus_UInt32  res3:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_int_cmp2_p3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot0_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p0_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot0_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p0_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot0_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p0_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot1_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p1_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot1_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p1_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot1_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p1_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot2_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p2_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot2_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p2_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot2_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p2_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot3_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p3_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot3_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p3_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot3_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p3_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot4_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p4_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot4_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p4_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot4_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p4_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot5_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p5_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot5_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p5_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot5_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p5_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot6_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p6_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot6_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p6_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot6_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p6_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot7_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p7_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot7_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p7_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp0_pivot7_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp0_p7_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot0_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p0_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot0_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p0_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot0_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p0_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot1_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p1_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot1_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p1_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot1_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p1_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot2_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p2_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot2_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p2_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot2_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p2_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot3_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p3_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot3_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p3_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp1_pivot3_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp1_p3_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot0_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p0_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot0_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p0_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot0_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p0_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot1_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p1_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot1_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p1_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot1_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p1_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot2_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p2_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot2_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p2_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot2_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p2_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot3_i0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p3_i0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot3_i1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p3_i1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poly_coef_cmp2_pivot3_i2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_poly_coef_cmp2_p3_i2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_order_cmp1:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  mmr_order_cmp2:2;
        RBus_UInt32  res2:26;
    };
}dhdr_v_composer_composer_bl_pred_mmr_order_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef0:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef1:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef2:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef3:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef4:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef5:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef6:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef7:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef8:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef9:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef10:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef11:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef12:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef13:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef14:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef15:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef16:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef17:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef18:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef19:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef20:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp1_coef21:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_int_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef0:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef1:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef2:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef3:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef4:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef5:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef6:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef7:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef8:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef9:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef10:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef11:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef12:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef13:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef14:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef15:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef16:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef17:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef18:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef19:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef20:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_int_cmp2_coef21:17;
        RBus_UInt32  res1:15;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_int_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef3:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef4:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef5:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef6:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef7:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef8:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef9:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef10:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef11:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef12:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef13:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef14:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef15:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef16:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef17:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef18:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef19:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef20:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp1_coef21:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp1_coef_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef3:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef4:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef5:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef6:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef7:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef8:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef9:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef10:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef11:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef12:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef13:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef14:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef15:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef16:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef17:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef18:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef19:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef20:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mmr_coef_cmp2_coef21:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_bl_pred_mmr_cmp2_coef_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spatial_resampling_filter_flag:1;
        RBus_UInt32  res1:31;
    };
}dhdr_v_composer_composer_bl_up_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  el_spatial_resampling_filter_flag:1;
        RBus_UInt32  res1:31;
    };
}dhdr_v_composer_composer_el_rs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nlq_method_idc:1;
        RBus_UInt32  disable_residual_flag:1;
        RBus_UInt32  res1:30;
    };
}dhdr_v_composer_composer_el_iq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nlq_offset_cmp0:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  nlq_offset_cmp1:10;
        RBus_UInt32  res2:6;
    };
}dhdr_v_composer_composer_el_iq_offset_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nlq_offset_cmp2:10;
        RBus_UInt32  res1:22;
    };
}dhdr_v_composer_composer_el_iq_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_slope_cmp0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_slop_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_slope_cmp1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_slop_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_slope_cmp2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_slop_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_threshold_cmp0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_th_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_threshold_cmp1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_threshold_cmp2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdr_in_max_cmp0:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_max_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdr_in_max_cmp1:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_max_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdr_in_max_cmp2:23;
        RBus_UInt32  res1:9;
    };
}dhdr_v_composer_composer_el_iq_coef_max_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_slope_int_cmp0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  linear_deadzone_slope_int_cmp1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  linear_deadzone_slope_int_cmp2:2;
        RBus_UInt32  res3:22;
    };
}dhdr_v_composer_composer_el_iq_coef_int_slop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linear_deadzone_threshold_int_cmp0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  linear_deadzone_threshold_int_cmp1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  linear_deadzone_threshold_int_cmp2:2;
        RBus_UInt32  res3:22;
    };
}dhdr_v_composer_composer_el_iq_coef_int_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdr_in_max_int_cmp0:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  vdr_in_max_int_cmp1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  vdr_in_max_int_cmp2:2;
        RBus_UInt32  res3:22;
    };
}dhdr_v_composer_composer_el_iq_coef_int_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_rme:3;
        RBus_UInt32  res1:26;
        RBus_UInt32  composer_bl_ls:3;
    };
}dhdr_v_composer_composer_bl_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_rm_y0:4;
        RBus_UInt32  composer_bl_rm_y1:4;
        RBus_UInt32  res1:24;
    };
}dhdr_v_composer_composer_bl_rm_y0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}dhdr_v_composer_composer_bl_rm_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_rm_uv0:4;
        RBus_UInt32  res1:28;
    };
}dhdr_v_composer_composer_bl_rm_uv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_bist_fail:21;
        RBus_UInt32  res1:8;
        RBus_UInt32  composer_bl_bist_fail_group0:1;
        RBus_UInt32  composer_bl_bist_fail_group1:1;
        RBus_UInt32  composer_bl_bist_fail_group2:1;
    };
}dhdr_v_composer_composer_bl_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_drf_bist_fail:21;
        RBus_UInt32  res1:8;
        RBus_UInt32  composer_bl_drf_bist_fail_group0:1;
        RBus_UInt32  composer_bl_drf_bist_fail_group1:1;
        RBus_UInt32  composer_bl_drf_bist_fail_group2:1;
    };
}dhdr_v_composer_composer_bl_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_rme:19;
        RBus_UInt32  res1:13;
    };
}dhdr_v_composer_composer_el_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_rm_0:4;
        RBus_UInt32  composer_el_rm_1:4;
        RBus_UInt32  composer_el_rm_2:4;
        RBus_UInt32  composer_el_rm_3:4;
        RBus_UInt32  composer_el_rm_4:4;
        RBus_UInt32  composer_el_rm_5:4;
        RBus_UInt32  composer_el_rm_6:4;
        RBus_UInt32  composer_el_rm_7:4;
    };
}dhdr_v_composer_composer_el_rm_y0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_rm_8:4;
        RBus_UInt32  composer_el_rm_9:4;
        RBus_UInt32  composer_el_rm_10:4;
        RBus_UInt32  composer_el_rm_11:4;
        RBus_UInt32  res1:16;
    };
}dhdr_v_composer_composer_el_rm_y1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_rm_12:4;
        RBus_UInt32  composer_el_rm_13:4;
        RBus_UInt32  composer_el_rm_14:4;
        RBus_UInt32  composer_el_rm_15:4;
        RBus_UInt32  composer_el_rm_16:4;
        RBus_UInt32  composer_el_rm_17:4;
        RBus_UInt32  composer_el_rm_18:4;
        RBus_UInt32  res1:4;
    };
}dhdr_v_composer_composer_el_rm_uv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_bist_fail:19;
        RBus_UInt32  res1:13;
    };
}dhdr_v_composer_composer_el_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_drf_bist_fail:19;
        RBus_UInt32  res1:13;
    };
}dhdr_v_composer_composer_el_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_read:1;
        RBus_UInt32  composer_db_apply:1;
        RBus_UInt32  composer_db_en:1;
        RBus_UInt32  res1:29;
    };
}dhdr_v_composer_composer_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_ls:19;
        RBus_UInt32  res1:13;
    };
}dhdr_v_composer_composer_el_ls_RBUS;




#endif 


#endif 
