/**
* @file rbusIBReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_IB_REG_H_
#define _RBUS_IB_REG_H_

#include "rbus_types.h"



//  IB Register Address
#define  IB_IB_SEQ_BOUND_0                                                       0x1803F000
#define  IB_IB_SEQ_BOUND_0_reg_addr                                              "0xB803F000"
#define  IB_IB_SEQ_BOUND_0_reg                                                   0xB803F000
#define  IB_IB_SEQ_BOUND_0_inst_addr                                             "0x0000"
#define  set_IB_IB_SEQ_BOUND_0_reg(data)                                         (*((volatile unsigned int*)IB_IB_SEQ_BOUND_0_reg)=data)
#define  get_IB_IB_SEQ_BOUND_0_reg                                               (*((volatile unsigned int*)IB_IB_SEQ_BOUND_0_reg))
#define  IB_IB_SEQ_BOUND_0_address_shift                                         (20)
#define  IB_IB_SEQ_BOUND_0_address_mask                                          (0xFFF00000)
#define  IB_IB_SEQ_BOUND_0_address(data)                                         (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_BOUND_0_get_address(data)                                     ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_BOUND_1                                                       0x1803F004
#define  IB_IB_SEQ_BOUND_1_reg_addr                                              "0xB803F004"
#define  IB_IB_SEQ_BOUND_1_reg                                                   0xB803F004
#define  IB_IB_SEQ_BOUND_1_inst_addr                                             "0x0001"
#define  set_IB_IB_SEQ_BOUND_1_reg(data)                                         (*((volatile unsigned int*)IB_IB_SEQ_BOUND_1_reg)=data)
#define  get_IB_IB_SEQ_BOUND_1_reg                                               (*((volatile unsigned int*)IB_IB_SEQ_BOUND_1_reg))
#define  IB_IB_SEQ_BOUND_1_address_shift                                         (20)
#define  IB_IB_SEQ_BOUND_1_address_mask                                          (0xFFF00000)
#define  IB_IB_SEQ_BOUND_1_address(data)                                         (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_BOUND_1_get_address(data)                                     ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_BOUND_2                                                       0x1803F008
#define  IB_IB_SEQ_BOUND_2_reg_addr                                              "0xB803F008"
#define  IB_IB_SEQ_BOUND_2_reg                                                   0xB803F008
#define  IB_IB_SEQ_BOUND_2_inst_addr                                             "0x0002"
#define  set_IB_IB_SEQ_BOUND_2_reg(data)                                         (*((volatile unsigned int*)IB_IB_SEQ_BOUND_2_reg)=data)
#define  get_IB_IB_SEQ_BOUND_2_reg                                               (*((volatile unsigned int*)IB_IB_SEQ_BOUND_2_reg))
#define  IB_IB_SEQ_BOUND_2_address_shift                                         (20)
#define  IB_IB_SEQ_BOUND_2_address_mask                                          (0xFFF00000)
#define  IB_IB_SEQ_BOUND_2_address(data)                                         (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_BOUND_2_get_address(data)                                     ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_DC1_BOUND_0                                                   0x1803F00C
#define  IB_IB_SEQ_DC1_BOUND_0_reg_addr                                          "0xB803F00C"
#define  IB_IB_SEQ_DC1_BOUND_0_reg                                               0xB803F00C
#define  IB_IB_SEQ_DC1_BOUND_0_inst_addr                                         "0x0003"
#define  set_IB_IB_SEQ_DC1_BOUND_0_reg(data)                                     (*((volatile unsigned int*)IB_IB_SEQ_DC1_BOUND_0_reg)=data)
#define  get_IB_IB_SEQ_DC1_BOUND_0_reg                                           (*((volatile unsigned int*)IB_IB_SEQ_DC1_BOUND_0_reg))
#define  IB_IB_SEQ_DC1_BOUND_0_address_shift                                     (20)
#define  IB_IB_SEQ_DC1_BOUND_0_address_mask                                      (0xFFF00000)
#define  IB_IB_SEQ_DC1_BOUND_0_address(data)                                     (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_DC1_BOUND_0_get_address(data)                                 ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_DC1_BOUND_1                                                   0x1803F010
#define  IB_IB_SEQ_DC1_BOUND_1_reg_addr                                          "0xB803F010"
#define  IB_IB_SEQ_DC1_BOUND_1_reg                                               0xB803F010
#define  IB_IB_SEQ_DC1_BOUND_1_inst_addr                                         "0x0004"
#define  set_IB_IB_SEQ_DC1_BOUND_1_reg(data)                                     (*((volatile unsigned int*)IB_IB_SEQ_DC1_BOUND_1_reg)=data)
#define  get_IB_IB_SEQ_DC1_BOUND_1_reg                                           (*((volatile unsigned int*)IB_IB_SEQ_DC1_BOUND_1_reg))
#define  IB_IB_SEQ_DC1_BOUND_1_address_shift                                     (20)
#define  IB_IB_SEQ_DC1_BOUND_1_address_mask                                      (0xFFF00000)
#define  IB_IB_SEQ_DC1_BOUND_1_address(data)                                     (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_DC1_BOUND_1_get_address(data)                                 ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_DC1_BOUND_2                                                   0x1803F014
#define  IB_IB_SEQ_DC1_BOUND_2_reg_addr                                          "0xB803F014"
#define  IB_IB_SEQ_DC1_BOUND_2_reg                                               0xB803F014
#define  IB_IB_SEQ_DC1_BOUND_2_inst_addr                                         "0x0005"
#define  set_IB_IB_SEQ_DC1_BOUND_2_reg(data)                                     (*((volatile unsigned int*)IB_IB_SEQ_DC1_BOUND_2_reg)=data)
#define  get_IB_IB_SEQ_DC1_BOUND_2_reg                                           (*((volatile unsigned int*)IB_IB_SEQ_DC1_BOUND_2_reg))
#define  IB_IB_SEQ_DC1_BOUND_2_address_shift                                     (20)
#define  IB_IB_SEQ_DC1_BOUND_2_address_mask                                      (0xFFF00000)
#define  IB_IB_SEQ_DC1_BOUND_2_address(data)                                     (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_DC1_BOUND_2_get_address(data)                                 ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_DC2_BOUND_0                                                   0x1803F018
#define  IB_IB_SEQ_DC2_BOUND_0_reg_addr                                          "0xB803F018"
#define  IB_IB_SEQ_DC2_BOUND_0_reg                                               0xB803F018
#define  IB_IB_SEQ_DC2_BOUND_0_inst_addr                                         "0x0006"
#define  set_IB_IB_SEQ_DC2_BOUND_0_reg(data)                                     (*((volatile unsigned int*)IB_IB_SEQ_DC2_BOUND_0_reg)=data)
#define  get_IB_IB_SEQ_DC2_BOUND_0_reg                                           (*((volatile unsigned int*)IB_IB_SEQ_DC2_BOUND_0_reg))
#define  IB_IB_SEQ_DC2_BOUND_0_address_shift                                     (20)
#define  IB_IB_SEQ_DC2_BOUND_0_address_mask                                      (0xFFF00000)
#define  IB_IB_SEQ_DC2_BOUND_0_address(data)                                     (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_DC2_BOUND_0_get_address(data)                                 ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_DC2_BOUND_1                                                   0x1803F01C
#define  IB_IB_SEQ_DC2_BOUND_1_reg_addr                                          "0xB803F01C"
#define  IB_IB_SEQ_DC2_BOUND_1_reg                                               0xB803F01C
#define  IB_IB_SEQ_DC2_BOUND_1_inst_addr                                         "0x0007"
#define  set_IB_IB_SEQ_DC2_BOUND_1_reg(data)                                     (*((volatile unsigned int*)IB_IB_SEQ_DC2_BOUND_1_reg)=data)
#define  get_IB_IB_SEQ_DC2_BOUND_1_reg                                           (*((volatile unsigned int*)IB_IB_SEQ_DC2_BOUND_1_reg))
#define  IB_IB_SEQ_DC2_BOUND_1_address_shift                                     (20)
#define  IB_IB_SEQ_DC2_BOUND_1_address_mask                                      (0xFFF00000)
#define  IB_IB_SEQ_DC2_BOUND_1_address(data)                                     (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_DC2_BOUND_1_get_address(data)                                 ((0xFFF00000&(data))>>20)

#define  IB_IB_SEQ_DC2_BOUND_2                                                   0x1803F020
#define  IB_IB_SEQ_DC2_BOUND_2_reg_addr                                          "0xB803F020"
#define  IB_IB_SEQ_DC2_BOUND_2_reg                                               0xB803F020
#define  IB_IB_SEQ_DC2_BOUND_2_inst_addr                                         "0x0008"
#define  set_IB_IB_SEQ_DC2_BOUND_2_reg(data)                                     (*((volatile unsigned int*)IB_IB_SEQ_DC2_BOUND_2_reg)=data)
#define  get_IB_IB_SEQ_DC2_BOUND_2_reg                                           (*((volatile unsigned int*)IB_IB_SEQ_DC2_BOUND_2_reg))
#define  IB_IB_SEQ_DC2_BOUND_2_address_shift                                     (20)
#define  IB_IB_SEQ_DC2_BOUND_2_address_mask                                      (0xFFF00000)
#define  IB_IB_SEQ_DC2_BOUND_2_address(data)                                     (0xFFF00000&((data)<<20))
#define  IB_IB_SEQ_DC2_BOUND_2_get_address(data)                                 ((0xFFF00000&(data))>>20)

#define  IB_IB_BLK_BOUND                                                         0x1803F024
#define  IB_IB_BLK_BOUND_reg_addr                                                "0xB803F024"
#define  IB_IB_BLK_BOUND_reg                                                     0xB803F024
#define  IB_IB_BLK_BOUND_inst_addr                                               "0x0009"
#define  set_IB_IB_BLK_BOUND_reg(data)                                           (*((volatile unsigned int*)IB_IB_BLK_BOUND_reg)=data)
#define  get_IB_IB_BLK_BOUND_reg                                                 (*((volatile unsigned int*)IB_IB_BLK_BOUND_reg))
#define  IB_IB_BLK_BOUND_bound_index_0_shift                                     (24)
#define  IB_IB_BLK_BOUND_bound_index_1_shift                                     (16)
#define  IB_IB_BLK_BOUND_bound_index_2_shift                                     (8)
#define  IB_IB_BLK_BOUND_bound_index_0_mask                                      (0x7F000000)
#define  IB_IB_BLK_BOUND_bound_index_1_mask                                      (0x007F0000)
#define  IB_IB_BLK_BOUND_bound_index_2_mask                                      (0x00007F00)
#define  IB_IB_BLK_BOUND_bound_index_0(data)                                     (0x7F000000&((data)<<24))
#define  IB_IB_BLK_BOUND_bound_index_1(data)                                     (0x007F0000&((data)<<16))
#define  IB_IB_BLK_BOUND_bound_index_2(data)                                     (0x00007F00&((data)<<8))
#define  IB_IB_BLK_BOUND_get_bound_index_0(data)                                 ((0x7F000000&(data))>>24)
#define  IB_IB_BLK_BOUND_get_bound_index_1(data)                                 ((0x007F0000&(data))>>16)
#define  IB_IB_BLK_BOUND_get_bound_index_2(data)                                 ((0x00007F00&(data))>>8)

#define  IB_IB_SEQ_REGION_SET                                                    0x1803F028
#define  IB_IB_SEQ_REGION_SET_reg_addr                                           "0xB803F028"
#define  IB_IB_SEQ_REGION_SET_reg                                                0xB803F028
#define  IB_IB_SEQ_REGION_SET_inst_addr                                          "0x000A"
#define  set_IB_IB_SEQ_REGION_SET_reg(data)                                      (*((volatile unsigned int*)IB_IB_SEQ_REGION_SET_reg)=data)
#define  get_IB_IB_SEQ_REGION_SET_reg                                            (*((volatile unsigned int*)IB_IB_SEQ_REGION_SET_reg))
#define  IB_IB_SEQ_REGION_SET_region_0_mode_shift                                (28)
#define  IB_IB_SEQ_REGION_SET_region_0_slice_basis_shift                         (24)
#define  IB_IB_SEQ_REGION_SET_region_1_mode_shift                                (20)
#define  IB_IB_SEQ_REGION_SET_region_1_slice_basis_shift                         (16)
#define  IB_IB_SEQ_REGION_SET_region_2_mode_shift                                (12)
#define  IB_IB_SEQ_REGION_SET_region_2_slice_basis_shift                         (8)
#define  IB_IB_SEQ_REGION_SET_region_3_mode_shift                                (4)
#define  IB_IB_SEQ_REGION_SET_region_3_slice_basis_shift                         (0)
#define  IB_IB_SEQ_REGION_SET_region_0_mode_mask                                 (0x70000000)
#define  IB_IB_SEQ_REGION_SET_region_0_slice_basis_mask                          (0x07000000)
#define  IB_IB_SEQ_REGION_SET_region_1_mode_mask                                 (0x00700000)
#define  IB_IB_SEQ_REGION_SET_region_1_slice_basis_mask                          (0x00070000)
#define  IB_IB_SEQ_REGION_SET_region_2_mode_mask                                 (0x00007000)
#define  IB_IB_SEQ_REGION_SET_region_2_slice_basis_mask                          (0x00000700)
#define  IB_IB_SEQ_REGION_SET_region_3_mode_mask                                 (0x00000070)
#define  IB_IB_SEQ_REGION_SET_region_3_slice_basis_mask                          (0x00000007)
#define  IB_IB_SEQ_REGION_SET_region_0_mode(data)                                (0x70000000&((data)<<28))
#define  IB_IB_SEQ_REGION_SET_region_0_slice_basis(data)                         (0x07000000&((data)<<24))
#define  IB_IB_SEQ_REGION_SET_region_1_mode(data)                                (0x00700000&((data)<<20))
#define  IB_IB_SEQ_REGION_SET_region_1_slice_basis(data)                         (0x00070000&((data)<<16))
#define  IB_IB_SEQ_REGION_SET_region_2_mode(data)                                (0x00007000&((data)<<12))
#define  IB_IB_SEQ_REGION_SET_region_2_slice_basis(data)                         (0x00000700&((data)<<8))
#define  IB_IB_SEQ_REGION_SET_region_3_mode(data)                                (0x00000070&((data)<<4))
#define  IB_IB_SEQ_REGION_SET_region_3_slice_basis(data)                         (0x00000007&(data))
#define  IB_IB_SEQ_REGION_SET_get_region_0_mode(data)                            ((0x70000000&(data))>>28)
#define  IB_IB_SEQ_REGION_SET_get_region_0_slice_basis(data)                     ((0x07000000&(data))>>24)
#define  IB_IB_SEQ_REGION_SET_get_region_1_mode(data)                            ((0x00700000&(data))>>20)
#define  IB_IB_SEQ_REGION_SET_get_region_1_slice_basis(data)                     ((0x00070000&(data))>>16)
#define  IB_IB_SEQ_REGION_SET_get_region_2_mode(data)                            ((0x00007000&(data))>>12)
#define  IB_IB_SEQ_REGION_SET_get_region_2_slice_basis(data)                     ((0x00000700&(data))>>8)
#define  IB_IB_SEQ_REGION_SET_get_region_3_mode(data)                            ((0x00000070&(data))>>4)
#define  IB_IB_SEQ_REGION_SET_get_region_3_slice_basis(data)                     (0x00000007&(data))

#define  IB_IB_BLK_REGION_SET                                                    0x1803F02C
#define  IB_IB_BLK_REGION_SET_reg_addr                                           "0xB803F02C"
#define  IB_IB_BLK_REGION_SET_reg                                                0xB803F02C
#define  IB_IB_BLK_REGION_SET_inst_addr                                          "0x000B"
#define  set_IB_IB_BLK_REGION_SET_reg(data)                                      (*((volatile unsigned int*)IB_IB_BLK_REGION_SET_reg)=data)
#define  get_IB_IB_BLK_REGION_SET_reg                                            (*((volatile unsigned int*)IB_IB_BLK_REGION_SET_reg))
#define  IB_IB_BLK_REGION_SET_region_0_mode_shift                                (28)
#define  IB_IB_BLK_REGION_SET_region_0_slice_basis_shift                         (24)
#define  IB_IB_BLK_REGION_SET_region_1_mode_shift                                (20)
#define  IB_IB_BLK_REGION_SET_region_1_slice_basis_shift                         (16)
#define  IB_IB_BLK_REGION_SET_region_2_mode_shift                                (12)
#define  IB_IB_BLK_REGION_SET_region_2_slice_basis_shift                         (8)
#define  IB_IB_BLK_REGION_SET_region_3_mode_shift                                (4)
#define  IB_IB_BLK_REGION_SET_region_3_slice_basis_shift                         (0)
#define  IB_IB_BLK_REGION_SET_region_0_mode_mask                                 (0x70000000)
#define  IB_IB_BLK_REGION_SET_region_0_slice_basis_mask                          (0x07000000)
#define  IB_IB_BLK_REGION_SET_region_1_mode_mask                                 (0x00700000)
#define  IB_IB_BLK_REGION_SET_region_1_slice_basis_mask                          (0x00070000)
#define  IB_IB_BLK_REGION_SET_region_2_mode_mask                                 (0x00007000)
#define  IB_IB_BLK_REGION_SET_region_2_slice_basis_mask                          (0x00000700)
#define  IB_IB_BLK_REGION_SET_region_3_mode_mask                                 (0x00000070)
#define  IB_IB_BLK_REGION_SET_region_3_slice_basis_mask                          (0x00000007)
#define  IB_IB_BLK_REGION_SET_region_0_mode(data)                                (0x70000000&((data)<<28))
#define  IB_IB_BLK_REGION_SET_region_0_slice_basis(data)                         (0x07000000&((data)<<24))
#define  IB_IB_BLK_REGION_SET_region_1_mode(data)                                (0x00700000&((data)<<20))
#define  IB_IB_BLK_REGION_SET_region_1_slice_basis(data)                         (0x00070000&((data)<<16))
#define  IB_IB_BLK_REGION_SET_region_2_mode(data)                                (0x00007000&((data)<<12))
#define  IB_IB_BLK_REGION_SET_region_2_slice_basis(data)                         (0x00000700&((data)<<8))
#define  IB_IB_BLK_REGION_SET_region_3_mode(data)                                (0x00000070&((data)<<4))
#define  IB_IB_BLK_REGION_SET_region_3_slice_basis(data)                         (0x00000007&(data))
#define  IB_IB_BLK_REGION_SET_get_region_0_mode(data)                            ((0x70000000&(data))>>28)
#define  IB_IB_BLK_REGION_SET_get_region_0_slice_basis(data)                     ((0x07000000&(data))>>24)
#define  IB_IB_BLK_REGION_SET_get_region_1_mode(data)                            ((0x00700000&(data))>>20)
#define  IB_IB_BLK_REGION_SET_get_region_1_slice_basis(data)                     ((0x00070000&(data))>>16)
#define  IB_IB_BLK_REGION_SET_get_region_2_mode(data)                            ((0x00007000&(data))>>12)
#define  IB_IB_BLK_REGION_SET_get_region_2_slice_basis(data)                     ((0x00000700&(data))>>8)
#define  IB_IB_BLK_REGION_SET_get_region_3_mode(data)                            ((0x00000070&(data))>>4)
#define  IB_IB_BLK_REGION_SET_get_region_3_slice_basis(data)                     (0x00000007&(data))

#define  IB_IB_TIME_STEP                                                         0x1803F030
#define  IB_IB_TIME_STEP_reg_addr                                                "0xB803F030"
#define  IB_IB_TIME_STEP_reg                                                     0xB803F030
#define  IB_IB_TIME_STEP_inst_addr                                               "0x000C"
#define  set_IB_IB_TIME_STEP_reg(data)                                           (*((volatile unsigned int*)IB_IB_TIME_STEP_reg)=data)
#define  get_IB_IB_TIME_STEP_reg                                                 (*((volatile unsigned int*)IB_IB_TIME_STEP_reg))
#define  IB_IB_TIME_STEP_manual_margin_shift                                     (24)
#define  IB_IB_TIME_STEP_dummy_23_15_shift                                       (15)
#define  IB_IB_TIME_STEP_pri_out_dis_shift                                       (14)
#define  IB_IB_TIME_STEP_blk_to_dc12_invert_shift                                (13)
#define  IB_IB_TIME_STEP_fast_read_dis_shift                                     (12)
#define  IB_IB_TIME_STEP_di_sram_en_shift                                        (11)
#define  IB_IB_TIME_STEP_old_wdata_mode_shift                                    (10)
#define  IB_IB_TIME_STEP_old_rdata_mode_shift                                    (9)
#define  IB_IB_TIME_STEP_old_add_mode_shift                                      (8)
#define  IB_IB_TIME_STEP_pri_min_dis_shift                                       (7)
#define  IB_IB_TIME_STEP_pri_down_dis_shift                                      (6)
#define  IB_IB_TIME_STEP_debug_sel_shift                                         (5)
#define  IB_IB_TIME_STEP_multi_write_dis_shift                                   (4)
#define  IB_IB_TIME_STEP_time_step_shift                                         (0)
#define  IB_IB_TIME_STEP_manual_margin_mask                                      (0xFF000000)
#define  IB_IB_TIME_STEP_dummy_23_15_mask                                        (0x00FF8000)
#define  IB_IB_TIME_STEP_pri_out_dis_mask                                        (0x00004000)
#define  IB_IB_TIME_STEP_blk_to_dc12_invert_mask                                 (0x00002000)
#define  IB_IB_TIME_STEP_fast_read_dis_mask                                      (0x00001000)
#define  IB_IB_TIME_STEP_di_sram_en_mask                                         (0x00000800)
#define  IB_IB_TIME_STEP_old_wdata_mode_mask                                     (0x00000400)
#define  IB_IB_TIME_STEP_old_rdata_mode_mask                                     (0x00000200)
#define  IB_IB_TIME_STEP_old_add_mode_mask                                       (0x00000100)
#define  IB_IB_TIME_STEP_pri_min_dis_mask                                        (0x00000080)
#define  IB_IB_TIME_STEP_pri_down_dis_mask                                       (0x00000040)
#define  IB_IB_TIME_STEP_debug_sel_mask                                          (0x00000020)
#define  IB_IB_TIME_STEP_multi_write_dis_mask                                    (0x00000010)
#define  IB_IB_TIME_STEP_time_step_mask                                          (0x0000000F)
#define  IB_IB_TIME_STEP_manual_margin(data)                                     (0xFF000000&((data)<<24))
#define  IB_IB_TIME_STEP_dummy_23_15(data)                                       (0x00FF8000&((data)<<15))
#define  IB_IB_TIME_STEP_pri_out_dis(data)                                       (0x00004000&((data)<<14))
#define  IB_IB_TIME_STEP_blk_to_dc12_invert(data)                                (0x00002000&((data)<<13))
#define  IB_IB_TIME_STEP_fast_read_dis(data)                                     (0x00001000&((data)<<12))
#define  IB_IB_TIME_STEP_di_sram_en(data)                                        (0x00000800&((data)<<11))
#define  IB_IB_TIME_STEP_old_wdata_mode(data)                                    (0x00000400&((data)<<10))
#define  IB_IB_TIME_STEP_old_rdata_mode(data)                                    (0x00000200&((data)<<9))
#define  IB_IB_TIME_STEP_old_add_mode(data)                                      (0x00000100&((data)<<8))
#define  IB_IB_TIME_STEP_pri_min_dis(data)                                       (0x00000080&((data)<<7))
#define  IB_IB_TIME_STEP_pri_down_dis(data)                                      (0x00000040&((data)<<6))
#define  IB_IB_TIME_STEP_debug_sel(data)                                         (0x00000020&((data)<<5))
#define  IB_IB_TIME_STEP_multi_write_dis(data)                                   (0x00000010&((data)<<4))
#define  IB_IB_TIME_STEP_time_step(data)                                         (0x0000000F&(data))
#define  IB_IB_TIME_STEP_get_manual_margin(data)                                 ((0xFF000000&(data))>>24)
#define  IB_IB_TIME_STEP_get_dummy_23_15(data)                                   ((0x00FF8000&(data))>>15)
#define  IB_IB_TIME_STEP_get_pri_out_dis(data)                                   ((0x00004000&(data))>>14)
#define  IB_IB_TIME_STEP_get_blk_to_dc12_invert(data)                            ((0x00002000&(data))>>13)
#define  IB_IB_TIME_STEP_get_fast_read_dis(data)                                 ((0x00001000&(data))>>12)
#define  IB_IB_TIME_STEP_get_di_sram_en(data)                                    ((0x00000800&(data))>>11)
#define  IB_IB_TIME_STEP_get_old_wdata_mode(data)                                ((0x00000400&(data))>>10)
#define  IB_IB_TIME_STEP_get_old_rdata_mode(data)                                ((0x00000200&(data))>>9)
#define  IB_IB_TIME_STEP_get_old_add_mode(data)                                  ((0x00000100&(data))>>8)
#define  IB_IB_TIME_STEP_get_pri_min_dis(data)                                   ((0x00000080&(data))>>7)
#define  IB_IB_TIME_STEP_get_pri_down_dis(data)                                  ((0x00000040&(data))>>6)
#define  IB_IB_TIME_STEP_get_debug_sel(data)                                     ((0x00000020&(data))>>5)
#define  IB_IB_TIME_STEP_get_multi_write_dis(data)                               ((0x00000010&(data))>>4)
#define  IB_IB_TIME_STEP_get_time_step(data)                                     (0x0000000F&(data))

#define  IB_IB_CTI_SPACE                                                         0x1803F034
#define  IB_IB_CTI_SPACE_reg_addr                                                "0xB803F034"
#define  IB_IB_CTI_SPACE_reg                                                     0xB803F034
#define  IB_IB_CTI_SPACE_inst_addr                                               "0x000D"
#define  set_IB_IB_CTI_SPACE_reg(data)                                           (*((volatile unsigned int*)IB_IB_CTI_SPACE_reg)=data)
#define  get_IB_IB_CTI_SPACE_reg                                                 (*((volatile unsigned int*)IB_IB_CTI_SPACE_reg))
#define  IB_IB_CTI_SPACE_space_magin_shift                                       (0)
#define  IB_IB_CTI_SPACE_space_magin_mask                                        (0x0000000F)
#define  IB_IB_CTI_SPACE_space_magin(data)                                       (0x0000000F&(data))
#define  IB_IB_CTI_SPACE_get_space_magin(data)                                   (0x0000000F&(data))

#define  IB_IB_INPUT_ADDCMD0                                                     0x1803F060
#define  IB_IB_INPUT_ADDCMD0_reg_addr                                            "0xB803F060"
#define  IB_IB_INPUT_ADDCMD0_reg                                                 0xB803F060
#define  IB_IB_INPUT_ADDCMD0_inst_addr                                           "0x000E"
#define  set_IB_IB_INPUT_ADDCMD0_reg(data)                                       (*((volatile unsigned int*)IB_IB_INPUT_ADDCMD0_reg)=data)
#define  get_IB_IB_INPUT_ADDCMD0_reg                                             (*((volatile unsigned int*)IB_IB_INPUT_ADDCMD0_reg))
#define  IB_IB_INPUT_ADDCMD0_addcmd_31_0_shift                                   (0)
#define  IB_IB_INPUT_ADDCMD0_addcmd_31_0_mask                                    (0xFFFFFFFF)
#define  IB_IB_INPUT_ADDCMD0_addcmd_31_0(data)                                   (0xFFFFFFFF&(data))
#define  IB_IB_INPUT_ADDCMD0_get_addcmd_31_0(data)                               (0xFFFFFFFF&(data))

#define  IB_IB_INPUT_ADDCMD1                                                     0x1803F064
#define  IB_IB_INPUT_ADDCMD1_reg_addr                                            "0xB803F064"
#define  IB_IB_INPUT_ADDCMD1_reg                                                 0xB803F064
#define  IB_IB_INPUT_ADDCMD1_inst_addr                                           "0x000F"
#define  set_IB_IB_INPUT_ADDCMD1_reg(data)                                       (*((volatile unsigned int*)IB_IB_INPUT_ADDCMD1_reg)=data)
#define  get_IB_IB_INPUT_ADDCMD1_reg                                             (*((volatile unsigned int*)IB_IB_INPUT_ADDCMD1_reg))
#define  IB_IB_INPUT_ADDCMD1_command_index_shift                                 (18)
#define  IB_IB_INPUT_ADDCMD1_addcmd_49_32_shift                                  (0)
#define  IB_IB_INPUT_ADDCMD1_command_index_mask                                  (0xFFFC0000)
#define  IB_IB_INPUT_ADDCMD1_addcmd_49_32_mask                                   (0x0003FFFF)
#define  IB_IB_INPUT_ADDCMD1_command_index(data)                                 (0xFFFC0000&((data)<<18))
#define  IB_IB_INPUT_ADDCMD1_addcmd_49_32(data)                                  (0x0003FFFF&(data))
#define  IB_IB_INPUT_ADDCMD1_get_command_index(data)                             ((0xFFFC0000&(data))>>18)
#define  IB_IB_INPUT_ADDCMD1_get_addcmd_49_32(data)                              (0x0003FFFF&(data))

#define  IB_IB_OUTPUT_DC1_ADDCMD0                                                0x1803F068
#define  IB_IB_OUTPUT_DC1_ADDCMD0_reg_addr                                       "0xB803F068"
#define  IB_IB_OUTPUT_DC1_ADDCMD0_reg                                            0xB803F068
#define  IB_IB_OUTPUT_DC1_ADDCMD0_inst_addr                                      "0x0010"
#define  set_IB_IB_OUTPUT_DC1_ADDCMD0_reg(data)                                  (*((volatile unsigned int*)IB_IB_OUTPUT_DC1_ADDCMD0_reg)=data)
#define  get_IB_IB_OUTPUT_DC1_ADDCMD0_reg                                        (*((volatile unsigned int*)IB_IB_OUTPUT_DC1_ADDCMD0_reg))
#define  IB_IB_OUTPUT_DC1_ADDCMD0_addcmd_31_0_shift                              (0)
#define  IB_IB_OUTPUT_DC1_ADDCMD0_addcmd_31_0_mask                               (0xFFFFFFFF)
#define  IB_IB_OUTPUT_DC1_ADDCMD0_addcmd_31_0(data)                              (0xFFFFFFFF&(data))
#define  IB_IB_OUTPUT_DC1_ADDCMD0_get_addcmd_31_0(data)                          (0xFFFFFFFF&(data))

#define  IB_IB_OUTPUT_DC1_ADDCMD1                                                0x1803F06C
#define  IB_IB_OUTPUT_DC1_ADDCMD1_reg_addr                                       "0xB803F06C"
#define  IB_IB_OUTPUT_DC1_ADDCMD1_reg                                            0xB803F06C
#define  IB_IB_OUTPUT_DC1_ADDCMD1_inst_addr                                      "0x0011"
#define  set_IB_IB_OUTPUT_DC1_ADDCMD1_reg(data)                                  (*((volatile unsigned int*)IB_IB_OUTPUT_DC1_ADDCMD1_reg)=data)
#define  get_IB_IB_OUTPUT_DC1_ADDCMD1_reg                                        (*((volatile unsigned int*)IB_IB_OUTPUT_DC1_ADDCMD1_reg))
#define  IB_IB_OUTPUT_DC1_ADDCMD1_command_index_shift                            (18)
#define  IB_IB_OUTPUT_DC1_ADDCMD1_addcmd_49_32_shift                             (0)
#define  IB_IB_OUTPUT_DC1_ADDCMD1_command_index_mask                             (0xFFFC0000)
#define  IB_IB_OUTPUT_DC1_ADDCMD1_addcmd_49_32_mask                              (0x0003FFFF)
#define  IB_IB_OUTPUT_DC1_ADDCMD1_command_index(data)                            (0xFFFC0000&((data)<<18))
#define  IB_IB_OUTPUT_DC1_ADDCMD1_addcmd_49_32(data)                             (0x0003FFFF&(data))
#define  IB_IB_OUTPUT_DC1_ADDCMD1_get_command_index(data)                        ((0xFFFC0000&(data))>>18)
#define  IB_IB_OUTPUT_DC1_ADDCMD1_get_addcmd_49_32(data)                         (0x0003FFFF&(data))

#define  IB_IB_OUTPUT_DC2_ADDCMD0                                                0x1803F070
#define  IB_IB_OUTPUT_DC2_ADDCMD0_reg_addr                                       "0xB803F070"
#define  IB_IB_OUTPUT_DC2_ADDCMD0_reg                                            0xB803F070
#define  IB_IB_OUTPUT_DC2_ADDCMD0_inst_addr                                      "0x0012"
#define  set_IB_IB_OUTPUT_DC2_ADDCMD0_reg(data)                                  (*((volatile unsigned int*)IB_IB_OUTPUT_DC2_ADDCMD0_reg)=data)
#define  get_IB_IB_OUTPUT_DC2_ADDCMD0_reg                                        (*((volatile unsigned int*)IB_IB_OUTPUT_DC2_ADDCMD0_reg))
#define  IB_IB_OUTPUT_DC2_ADDCMD0_addcmd_31_0_shift                              (0)
#define  IB_IB_OUTPUT_DC2_ADDCMD0_addcmd_31_0_mask                               (0xFFFFFFFF)
#define  IB_IB_OUTPUT_DC2_ADDCMD0_addcmd_31_0(data)                              (0xFFFFFFFF&(data))
#define  IB_IB_OUTPUT_DC2_ADDCMD0_get_addcmd_31_0(data)                          (0xFFFFFFFF&(data))

#define  IB_IB_OUTPUT_DC2_ADDCMD1                                                0x1803F074
#define  IB_IB_OUTPUT_DC2_ADDCMD1_reg_addr                                       "0xB803F074"
#define  IB_IB_OUTPUT_DC2_ADDCMD1_reg                                            0xB803F074
#define  IB_IB_OUTPUT_DC2_ADDCMD1_inst_addr                                      "0x0013"
#define  set_IB_IB_OUTPUT_DC2_ADDCMD1_reg(data)                                  (*((volatile unsigned int*)IB_IB_OUTPUT_DC2_ADDCMD1_reg)=data)
#define  get_IB_IB_OUTPUT_DC2_ADDCMD1_reg                                        (*((volatile unsigned int*)IB_IB_OUTPUT_DC2_ADDCMD1_reg))
#define  IB_IB_OUTPUT_DC2_ADDCMD1_command_index_shift                            (18)
#define  IB_IB_OUTPUT_DC2_ADDCMD1_addcmd_49_32_shift                             (0)
#define  IB_IB_OUTPUT_DC2_ADDCMD1_command_index_mask                             (0xFFFC0000)
#define  IB_IB_OUTPUT_DC2_ADDCMD1_addcmd_49_32_mask                              (0x0003FFFF)
#define  IB_IB_OUTPUT_DC2_ADDCMD1_command_index(data)                            (0xFFFC0000&((data)<<18))
#define  IB_IB_OUTPUT_DC2_ADDCMD1_addcmd_49_32(data)                             (0x0003FFFF&(data))
#define  IB_IB_OUTPUT_DC2_ADDCMD1_get_command_index(data)                        ((0xFFFC0000&(data))>>18)
#define  IB_IB_OUTPUT_DC2_ADDCMD1_get_addcmd_49_32(data)                         (0x0003FFFF&(data))

#define  IB_IB_ERROR_STATUS                                                      0x1803F0F0
#define  IB_IB_ERROR_STATUS_reg_addr                                             "0xB803F0F0"
#define  IB_IB_ERROR_STATUS_reg                                                  0xB803F0F0
#define  IB_IB_ERROR_STATUS_inst_addr                                            "0x0014"
#define  set_IB_IB_ERROR_STATUS_reg(data)                                        (*((volatile unsigned int*)IB_IB_ERROR_STATUS_reg)=data)
#define  get_IB_IB_ERROR_STATUS_reg                                              (*((volatile unsigned int*)IB_IB_ERROR_STATUS_reg))
#define  IB_IB_ERROR_STATUS_error_status_clr_shift                               (31)
#define  IB_IB_ERROR_STATUS_dummy_30_shift                                       (30)
#define  IB_IB_ERROR_STATUS_dc1_st_in_disram_shift                               (29)
#define  IB_IB_ERROR_STATUS_dc1_end_in_disram_shift                              (28)
#define  IB_IB_ERROR_STATUS_dc2_st_in_disram_shift                               (27)
#define  IB_IB_ERROR_STATUS_dc2_end_in_disram_shift                              (26)
#define  IB_IB_ERROR_STATUS_region_error_shift                                   (25)
#define  IB_IB_ERROR_STATUS_wdout_dc2_underflow_shift                            (24)
#define  IB_IB_ERROR_STATUS_wdata_dc2_underflow_shift                            (23)
#define  IB_IB_ERROR_STATUS_wdata_dc2_overflow_shift                             (22)
#define  IB_IB_ERROR_STATUS_wdout_dc1_underflow_shift                            (21)
#define  IB_IB_ERROR_STATUS_wdata_dc1_underflow_shift                            (20)
#define  IB_IB_ERROR_STATUS_wdata_dc1_overflow_shift                             (19)
#define  IB_IB_ERROR_STATUS_rdout_dc2_underflow_shift                            (18)
#define  IB_IB_ERROR_STATUS_rdata_dc2_underflow_shift                            (17)
#define  IB_IB_ERROR_STATUS_rdata_dc2_overflow_shift                             (16)
#define  IB_IB_ERROR_STATUS_rdout_dc1_underflow_shift                            (15)
#define  IB_IB_ERROR_STATUS_rdata_dc1_underflow_shift                            (14)
#define  IB_IB_ERROR_STATUS_rdata_dc1_overflow_shift                             (13)
#define  IB_IB_ERROR_STATUS_cmd_dc2_underflow_shift                              (12)
#define  IB_IB_ERROR_STATUS_cmd_dc2_overflow_shift                               (11)
#define  IB_IB_ERROR_STATUS_cmd_dc1_underflow_shift                              (10)
#define  IB_IB_ERROR_STATUS_cmd_dc1_overflow_shift                               (9)
#define  IB_IB_ERROR_STATUS_wdone_underflow_shift                                (8)
#define  IB_IB_ERROR_STATUS_wdone_overflow_shift                                 (7)
#define  IB_IB_ERROR_STATUS_winfo_underflow_shift                                (6)
#define  IB_IB_ERROR_STATUS_winfo_overflow_shift                                 (5)
#define  IB_IB_ERROR_STATUS_rinfo_underflow_shift                                (4)
#define  IB_IB_ERROR_STATUS_rinfo_overflow_shift                                 (3)
#define  IB_IB_ERROR_STATUS_seq_saddr_odd_shift                                  (2)
#define  IB_IB_ERROR_STATUS_seq_blen_odd_shift                                   (1)
#define  IB_IB_ERROR_STATUS_seq_blen_zero_shift                                  (0)
#define  IB_IB_ERROR_STATUS_error_status_clr_mask                                (0x80000000)
#define  IB_IB_ERROR_STATUS_dummy_30_mask                                        (0x40000000)
#define  IB_IB_ERROR_STATUS_dc1_st_in_disram_mask                                (0x20000000)
#define  IB_IB_ERROR_STATUS_dc1_end_in_disram_mask                               (0x10000000)
#define  IB_IB_ERROR_STATUS_dc2_st_in_disram_mask                                (0x08000000)
#define  IB_IB_ERROR_STATUS_dc2_end_in_disram_mask                               (0x04000000)
#define  IB_IB_ERROR_STATUS_region_error_mask                                    (0x02000000)
#define  IB_IB_ERROR_STATUS_wdout_dc2_underflow_mask                             (0x01000000)
#define  IB_IB_ERROR_STATUS_wdata_dc2_underflow_mask                             (0x00800000)
#define  IB_IB_ERROR_STATUS_wdata_dc2_overflow_mask                              (0x00400000)
#define  IB_IB_ERROR_STATUS_wdout_dc1_underflow_mask                             (0x00200000)
#define  IB_IB_ERROR_STATUS_wdata_dc1_underflow_mask                             (0x00100000)
#define  IB_IB_ERROR_STATUS_wdata_dc1_overflow_mask                              (0x00080000)
#define  IB_IB_ERROR_STATUS_rdout_dc2_underflow_mask                             (0x00040000)
#define  IB_IB_ERROR_STATUS_rdata_dc2_underflow_mask                             (0x00020000)
#define  IB_IB_ERROR_STATUS_rdata_dc2_overflow_mask                              (0x00010000)
#define  IB_IB_ERROR_STATUS_rdout_dc1_underflow_mask                             (0x00008000)
#define  IB_IB_ERROR_STATUS_rdata_dc1_underflow_mask                             (0x00004000)
#define  IB_IB_ERROR_STATUS_rdata_dc1_overflow_mask                              (0x00002000)
#define  IB_IB_ERROR_STATUS_cmd_dc2_underflow_mask                               (0x00001000)
#define  IB_IB_ERROR_STATUS_cmd_dc2_overflow_mask                                (0x00000800)
#define  IB_IB_ERROR_STATUS_cmd_dc1_underflow_mask                               (0x00000400)
#define  IB_IB_ERROR_STATUS_cmd_dc1_overflow_mask                                (0x00000200)
#define  IB_IB_ERROR_STATUS_wdone_underflow_mask                                 (0x00000100)
#define  IB_IB_ERROR_STATUS_wdone_overflow_mask                                  (0x00000080)
#define  IB_IB_ERROR_STATUS_winfo_underflow_mask                                 (0x00000040)
#define  IB_IB_ERROR_STATUS_winfo_overflow_mask                                  (0x00000020)
#define  IB_IB_ERROR_STATUS_rinfo_underflow_mask                                 (0x00000010)
#define  IB_IB_ERROR_STATUS_rinfo_overflow_mask                                  (0x00000008)
#define  IB_IB_ERROR_STATUS_seq_saddr_odd_mask                                   (0x00000004)
#define  IB_IB_ERROR_STATUS_seq_blen_odd_mask                                    (0x00000002)
#define  IB_IB_ERROR_STATUS_seq_blen_zero_mask                                   (0x00000001)
#define  IB_IB_ERROR_STATUS_error_status_clr(data)                               (0x80000000&((data)<<31))
#define  IB_IB_ERROR_STATUS_dummy_30(data)                                       (0x40000000&((data)<<30))
#define  IB_IB_ERROR_STATUS_dc1_st_in_disram(data)                               (0x20000000&((data)<<29))
#define  IB_IB_ERROR_STATUS_dc1_end_in_disram(data)                              (0x10000000&((data)<<28))
#define  IB_IB_ERROR_STATUS_dc2_st_in_disram(data)                               (0x08000000&((data)<<27))
#define  IB_IB_ERROR_STATUS_dc2_end_in_disram(data)                              (0x04000000&((data)<<26))
#define  IB_IB_ERROR_STATUS_region_error(data)                                   (0x02000000&((data)<<25))
#define  IB_IB_ERROR_STATUS_wdout_dc2_underflow(data)                            (0x01000000&((data)<<24))
#define  IB_IB_ERROR_STATUS_wdata_dc2_underflow(data)                            (0x00800000&((data)<<23))
#define  IB_IB_ERROR_STATUS_wdata_dc2_overflow(data)                             (0x00400000&((data)<<22))
#define  IB_IB_ERROR_STATUS_wdout_dc1_underflow(data)                            (0x00200000&((data)<<21))
#define  IB_IB_ERROR_STATUS_wdata_dc1_underflow(data)                            (0x00100000&((data)<<20))
#define  IB_IB_ERROR_STATUS_wdata_dc1_overflow(data)                             (0x00080000&((data)<<19))
#define  IB_IB_ERROR_STATUS_rdout_dc2_underflow(data)                            (0x00040000&((data)<<18))
#define  IB_IB_ERROR_STATUS_rdata_dc2_underflow(data)                            (0x00020000&((data)<<17))
#define  IB_IB_ERROR_STATUS_rdata_dc2_overflow(data)                             (0x00010000&((data)<<16))
#define  IB_IB_ERROR_STATUS_rdout_dc1_underflow(data)                            (0x00008000&((data)<<15))
#define  IB_IB_ERROR_STATUS_rdata_dc1_underflow(data)                            (0x00004000&((data)<<14))
#define  IB_IB_ERROR_STATUS_rdata_dc1_overflow(data)                             (0x00002000&((data)<<13))
#define  IB_IB_ERROR_STATUS_cmd_dc2_underflow(data)                              (0x00001000&((data)<<12))
#define  IB_IB_ERROR_STATUS_cmd_dc2_overflow(data)                               (0x00000800&((data)<<11))
#define  IB_IB_ERROR_STATUS_cmd_dc1_underflow(data)                              (0x00000400&((data)<<10))
#define  IB_IB_ERROR_STATUS_cmd_dc1_overflow(data)                               (0x00000200&((data)<<9))
#define  IB_IB_ERROR_STATUS_wdone_underflow(data)                                (0x00000100&((data)<<8))
#define  IB_IB_ERROR_STATUS_wdone_overflow(data)                                 (0x00000080&((data)<<7))
#define  IB_IB_ERROR_STATUS_winfo_underflow(data)                                (0x00000040&((data)<<6))
#define  IB_IB_ERROR_STATUS_winfo_overflow(data)                                 (0x00000020&((data)<<5))
#define  IB_IB_ERROR_STATUS_rinfo_underflow(data)                                (0x00000010&((data)<<4))
#define  IB_IB_ERROR_STATUS_rinfo_overflow(data)                                 (0x00000008&((data)<<3))
#define  IB_IB_ERROR_STATUS_seq_saddr_odd(data)                                  (0x00000004&((data)<<2))
#define  IB_IB_ERROR_STATUS_seq_blen_odd(data)                                   (0x00000002&((data)<<1))
#define  IB_IB_ERROR_STATUS_seq_blen_zero(data)                                  (0x00000001&(data))
#define  IB_IB_ERROR_STATUS_get_error_status_clr(data)                           ((0x80000000&(data))>>31)
#define  IB_IB_ERROR_STATUS_get_dummy_30(data)                                   ((0x40000000&(data))>>30)
#define  IB_IB_ERROR_STATUS_get_dc1_st_in_disram(data)                           ((0x20000000&(data))>>29)
#define  IB_IB_ERROR_STATUS_get_dc1_end_in_disram(data)                          ((0x10000000&(data))>>28)
#define  IB_IB_ERROR_STATUS_get_dc2_st_in_disram(data)                           ((0x08000000&(data))>>27)
#define  IB_IB_ERROR_STATUS_get_dc2_end_in_disram(data)                          ((0x04000000&(data))>>26)
#define  IB_IB_ERROR_STATUS_get_region_error(data)                               ((0x02000000&(data))>>25)
#define  IB_IB_ERROR_STATUS_get_wdout_dc2_underflow(data)                        ((0x01000000&(data))>>24)
#define  IB_IB_ERROR_STATUS_get_wdata_dc2_underflow(data)                        ((0x00800000&(data))>>23)
#define  IB_IB_ERROR_STATUS_get_wdata_dc2_overflow(data)                         ((0x00400000&(data))>>22)
#define  IB_IB_ERROR_STATUS_get_wdout_dc1_underflow(data)                        ((0x00200000&(data))>>21)
#define  IB_IB_ERROR_STATUS_get_wdata_dc1_underflow(data)                        ((0x00100000&(data))>>20)
#define  IB_IB_ERROR_STATUS_get_wdata_dc1_overflow(data)                         ((0x00080000&(data))>>19)
#define  IB_IB_ERROR_STATUS_get_rdout_dc2_underflow(data)                        ((0x00040000&(data))>>18)
#define  IB_IB_ERROR_STATUS_get_rdata_dc2_underflow(data)                        ((0x00020000&(data))>>17)
#define  IB_IB_ERROR_STATUS_get_rdata_dc2_overflow(data)                         ((0x00010000&(data))>>16)
#define  IB_IB_ERROR_STATUS_get_rdout_dc1_underflow(data)                        ((0x00008000&(data))>>15)
#define  IB_IB_ERROR_STATUS_get_rdata_dc1_underflow(data)                        ((0x00004000&(data))>>14)
#define  IB_IB_ERROR_STATUS_get_rdata_dc1_overflow(data)                         ((0x00002000&(data))>>13)
#define  IB_IB_ERROR_STATUS_get_cmd_dc2_underflow(data)                          ((0x00001000&(data))>>12)
#define  IB_IB_ERROR_STATUS_get_cmd_dc2_overflow(data)                           ((0x00000800&(data))>>11)
#define  IB_IB_ERROR_STATUS_get_cmd_dc1_underflow(data)                          ((0x00000400&(data))>>10)
#define  IB_IB_ERROR_STATUS_get_cmd_dc1_overflow(data)                           ((0x00000200&(data))>>9)
#define  IB_IB_ERROR_STATUS_get_wdone_underflow(data)                            ((0x00000100&(data))>>8)
#define  IB_IB_ERROR_STATUS_get_wdone_overflow(data)                             ((0x00000080&(data))>>7)
#define  IB_IB_ERROR_STATUS_get_winfo_underflow(data)                            ((0x00000040&(data))>>6)
#define  IB_IB_ERROR_STATUS_get_winfo_overflow(data)                             ((0x00000020&(data))>>5)
#define  IB_IB_ERROR_STATUS_get_rinfo_underflow(data)                            ((0x00000010&(data))>>4)
#define  IB_IB_ERROR_STATUS_get_rinfo_overflow(data)                             ((0x00000008&(data))>>3)
#define  IB_IB_ERROR_STATUS_get_seq_saddr_odd(data)                              ((0x00000004&(data))>>2)
#define  IB_IB_ERROR_STATUS_get_seq_blen_odd(data)                               ((0x00000002&(data))>>1)
#define  IB_IB_ERROR_STATUS_get_seq_blen_zero(data)                              (0x00000001&(data))

#define  IB_IB_ERROR_TRAP_STATUS                                                 0x1803F0F4
#define  IB_IB_ERROR_TRAP_STATUS_reg_addr                                        "0xB803F0F4"
#define  IB_IB_ERROR_TRAP_STATUS_reg                                             0xB803F0F4
#define  IB_IB_ERROR_TRAP_STATUS_inst_addr                                       "0x0015"
#define  set_IB_IB_ERROR_TRAP_STATUS_reg(data)                                   (*((volatile unsigned int*)IB_IB_ERROR_TRAP_STATUS_reg)=data)
#define  get_IB_IB_ERROR_TRAP_STATUS_reg                                         (*((volatile unsigned int*)IB_IB_ERROR_TRAP_STATUS_reg))
#define  IB_IB_ERROR_TRAP_STATUS_trap_status_clr_shift                           (31)
#define  IB_IB_ERROR_TRAP_STATUS_trap_case_shift                                 (20)
#define  IB_IB_ERROR_TRAP_STATUS_addcmd_hi_shift                                 (0)
#define  IB_IB_ERROR_TRAP_STATUS_trap_status_clr_mask                            (0x80000000)
#define  IB_IB_ERROR_TRAP_STATUS_trap_case_mask                                  (0x7FF00000)
#define  IB_IB_ERROR_TRAP_STATUS_addcmd_hi_mask                                  (0x000FFFFF)
#define  IB_IB_ERROR_TRAP_STATUS_trap_status_clr(data)                           (0x80000000&((data)<<31))
#define  IB_IB_ERROR_TRAP_STATUS_trap_case(data)                                 (0x7FF00000&((data)<<20))
#define  IB_IB_ERROR_TRAP_STATUS_addcmd_hi(data)                                 (0x000FFFFF&(data))
#define  IB_IB_ERROR_TRAP_STATUS_get_trap_status_clr(data)                       ((0x80000000&(data))>>31)
#define  IB_IB_ERROR_TRAP_STATUS_get_trap_case(data)                             ((0x7FF00000&(data))>>20)
#define  IB_IB_ERROR_TRAP_STATUS_get_addcmd_hi(data)                             (0x000FFFFF&(data))

#define  IB_IB_ERROR_TRAP_STATUS2                                                0x1803F0F8
#define  IB_IB_ERROR_TRAP_STATUS2_reg_addr                                       "0xB803F0F8"
#define  IB_IB_ERROR_TRAP_STATUS2_reg                                            0xB803F0F8
#define  IB_IB_ERROR_TRAP_STATUS2_inst_addr                                      "0x0016"
#define  set_IB_IB_ERROR_TRAP_STATUS2_reg(data)                                  (*((volatile unsigned int*)IB_IB_ERROR_TRAP_STATUS2_reg)=data)
#define  get_IB_IB_ERROR_TRAP_STATUS2_reg                                        (*((volatile unsigned int*)IB_IB_ERROR_TRAP_STATUS2_reg))
#define  IB_IB_ERROR_TRAP_STATUS2_addcmd_lo_shift                                (0)
#define  IB_IB_ERROR_TRAP_STATUS2_addcmd_lo_mask                                 (0xFFFFFFFF)
#define  IB_IB_ERROR_TRAP_STATUS2_addcmd_lo(data)                                (0xFFFFFFFF&(data))
#define  IB_IB_ERROR_TRAP_STATUS2_get_addcmd_lo(data)                            (0xFFFFFFFF&(data))

#define  IB_IB_BIST_MODE                                                         0x1803F080
#define  IB_IB_BIST_MODE_reg_addr                                                "0xB803F080"
#define  IB_IB_BIST_MODE_reg                                                     0xB803F080
#define  IB_IB_BIST_MODE_inst_addr                                               "0x0017"
#define  set_IB_IB_BIST_MODE_reg(data)                                           (*((volatile unsigned int*)IB_IB_BIST_MODE_reg)=data)
#define  get_IB_IB_BIST_MODE_reg                                                 (*((volatile unsigned int*)IB_IB_BIST_MODE_reg))
#define  IB_IB_BIST_MODE_ib_bist_mode_shift                                      (0)
#define  IB_IB_BIST_MODE_ib_bist_mode_mask                                       (0x00000001)
#define  IB_IB_BIST_MODE_ib_bist_mode(data)                                      (0x00000001&(data))
#define  IB_IB_BIST_MODE_get_ib_bist_mode(data)                                  (0x00000001&(data))

#define  IB_IB_BIST_DONE                                                         0x1803F084
#define  IB_IB_BIST_DONE_reg_addr                                                "0xB803F084"
#define  IB_IB_BIST_DONE_reg                                                     0xB803F084
#define  IB_IB_BIST_DONE_inst_addr                                               "0x0018"
#define  set_IB_IB_BIST_DONE_reg(data)                                           (*((volatile unsigned int*)IB_IB_BIST_DONE_reg)=data)
#define  get_IB_IB_BIST_DONE_reg                                                 (*((volatile unsigned int*)IB_IB_BIST_DONE_reg))
#define  IB_IB_BIST_DONE_ib_bist_done_shift                                      (0)
#define  IB_IB_BIST_DONE_ib_bist_done_mask                                       (0x00000001)
#define  IB_IB_BIST_DONE_ib_bist_done(data)                                      (0x00000001&(data))
#define  IB_IB_BIST_DONE_get_ib_bist_done(data)                                  (0x00000001&(data))

#define  IB_IB_BIST_FAIL_GROUP                                                   0x1803F088
#define  IB_IB_BIST_FAIL_GROUP_reg_addr                                          "0xB803F088"
#define  IB_IB_BIST_FAIL_GROUP_reg                                               0xB803F088
#define  IB_IB_BIST_FAIL_GROUP_inst_addr                                         "0x0019"
#define  set_IB_IB_BIST_FAIL_GROUP_reg(data)                                     (*((volatile unsigned int*)IB_IB_BIST_FAIL_GROUP_reg)=data)
#define  get_IB_IB_BIST_FAIL_GROUP_reg                                           (*((volatile unsigned int*)IB_IB_BIST_FAIL_GROUP_reg))
#define  IB_IB_BIST_FAIL_GROUP_ib_bist_fail_group_shift                          (0)
#define  IB_IB_BIST_FAIL_GROUP_ib_bist_fail_group_mask                           (0x00000001)
#define  IB_IB_BIST_FAIL_GROUP_ib_bist_fail_group(data)                          (0x00000001&(data))
#define  IB_IB_BIST_FAIL_GROUP_get_ib_bist_fail_group(data)                      (0x00000001&(data))

#define  IB_IB_BIST_FAIL                                                         0x1803F08C
#define  IB_IB_BIST_FAIL_reg_addr                                                "0xB803F08C"
#define  IB_IB_BIST_FAIL_reg                                                     0xB803F08C
#define  IB_IB_BIST_FAIL_inst_addr                                               "0x001A"
#define  set_IB_IB_BIST_FAIL_reg(data)                                           (*((volatile unsigned int*)IB_IB_BIST_FAIL_reg)=data)
#define  get_IB_IB_BIST_FAIL_reg                                                 (*((volatile unsigned int*)IB_IB_BIST_FAIL_reg))
#define  IB_IB_BIST_FAIL_ib_bist_fail_3_shift                                    (3)
#define  IB_IB_BIST_FAIL_ib_bist_fail_2_shift                                    (2)
#define  IB_IB_BIST_FAIL_ib_bist_fail_1_shift                                    (1)
#define  IB_IB_BIST_FAIL_ib_bist_fail_0_shift                                    (0)
#define  IB_IB_BIST_FAIL_ib_bist_fail_3_mask                                     (0x00000008)
#define  IB_IB_BIST_FAIL_ib_bist_fail_2_mask                                     (0x00000004)
#define  IB_IB_BIST_FAIL_ib_bist_fail_1_mask                                     (0x00000002)
#define  IB_IB_BIST_FAIL_ib_bist_fail_0_mask                                     (0x00000001)
#define  IB_IB_BIST_FAIL_ib_bist_fail_3(data)                                    (0x00000008&((data)<<3))
#define  IB_IB_BIST_FAIL_ib_bist_fail_2(data)                                    (0x00000004&((data)<<2))
#define  IB_IB_BIST_FAIL_ib_bist_fail_1(data)                                    (0x00000002&((data)<<1))
#define  IB_IB_BIST_FAIL_ib_bist_fail_0(data)                                    (0x00000001&(data))
#define  IB_IB_BIST_FAIL_get_ib_bist_fail_3(data)                                ((0x00000008&(data))>>3)
#define  IB_IB_BIST_FAIL_get_ib_bist_fail_2(data)                                ((0x00000004&(data))>>2)
#define  IB_IB_BIST_FAIL_get_ib_bist_fail_1(data)                                ((0x00000002&(data))>>1)
#define  IB_IB_BIST_FAIL_get_ib_bist_fail_0(data)                                (0x00000001&(data))

#define  IB_IB_DRF_MODE                                                          0x1803F090
#define  IB_IB_DRF_MODE_reg_addr                                                 "0xB803F090"
#define  IB_IB_DRF_MODE_reg                                                      0xB803F090
#define  IB_IB_DRF_MODE_inst_addr                                                "0x001B"
#define  set_IB_IB_DRF_MODE_reg(data)                                            (*((volatile unsigned int*)IB_IB_DRF_MODE_reg)=data)
#define  get_IB_IB_DRF_MODE_reg                                                  (*((volatile unsigned int*)IB_IB_DRF_MODE_reg))
#define  IB_IB_DRF_MODE_ib_drf_mode_shift                                        (0)
#define  IB_IB_DRF_MODE_ib_drf_mode_mask                                         (0x00000001)
#define  IB_IB_DRF_MODE_ib_drf_mode(data)                                        (0x00000001&(data))
#define  IB_IB_DRF_MODE_get_ib_drf_mode(data)                                    (0x00000001&(data))

#define  IB_IB_DRF_RESUME                                                        0x1803F094
#define  IB_IB_DRF_RESUME_reg_addr                                               "0xB803F094"
#define  IB_IB_DRF_RESUME_reg                                                    0xB803F094
#define  IB_IB_DRF_RESUME_inst_addr                                              "0x001C"
#define  set_IB_IB_DRF_RESUME_reg(data)                                          (*((volatile unsigned int*)IB_IB_DRF_RESUME_reg)=data)
#define  get_IB_IB_DRF_RESUME_reg                                                (*((volatile unsigned int*)IB_IB_DRF_RESUME_reg))
#define  IB_IB_DRF_RESUME_ib_drf_resume_shift                                    (0)
#define  IB_IB_DRF_RESUME_ib_drf_resume_mask                                     (0x00000001)
#define  IB_IB_DRF_RESUME_ib_drf_resume(data)                                    (0x00000001&(data))
#define  IB_IB_DRF_RESUME_get_ib_drf_resume(data)                                (0x00000001&(data))

#define  IB_IB_DRF_DONE                                                          0x1803F098
#define  IB_IB_DRF_DONE_reg_addr                                                 "0xB803F098"
#define  IB_IB_DRF_DONE_reg                                                      0xB803F098
#define  IB_IB_DRF_DONE_inst_addr                                                "0x001D"
#define  set_IB_IB_DRF_DONE_reg(data)                                            (*((volatile unsigned int*)IB_IB_DRF_DONE_reg)=data)
#define  get_IB_IB_DRF_DONE_reg                                                  (*((volatile unsigned int*)IB_IB_DRF_DONE_reg))
#define  IB_IB_DRF_DONE_ib_drf_done_shift                                        (0)
#define  IB_IB_DRF_DONE_ib_drf_done_mask                                         (0x00000001)
#define  IB_IB_DRF_DONE_ib_drf_done(data)                                        (0x00000001&(data))
#define  IB_IB_DRF_DONE_get_ib_drf_done(data)                                    (0x00000001&(data))

#define  IB_IB_DRF_PAUSE                                                         0x1803F09C
#define  IB_IB_DRF_PAUSE_reg_addr                                                "0xB803F09C"
#define  IB_IB_DRF_PAUSE_reg                                                     0xB803F09C
#define  IB_IB_DRF_PAUSE_inst_addr                                               "0x001E"
#define  set_IB_IB_DRF_PAUSE_reg(data)                                           (*((volatile unsigned int*)IB_IB_DRF_PAUSE_reg)=data)
#define  get_IB_IB_DRF_PAUSE_reg                                                 (*((volatile unsigned int*)IB_IB_DRF_PAUSE_reg))
#define  IB_IB_DRF_PAUSE_ib_drf_pause_shift                                      (0)
#define  IB_IB_DRF_PAUSE_ib_drf_pause_mask                                       (0x00000001)
#define  IB_IB_DRF_PAUSE_ib_drf_pause(data)                                      (0x00000001&(data))
#define  IB_IB_DRF_PAUSE_get_ib_drf_pause(data)                                  (0x00000001&(data))

#define  IB_IB_DRF_FAIL_GROUP                                                    0x1803F0A0
#define  IB_IB_DRF_FAIL_GROUP_reg_addr                                           "0xB803F0A0"
#define  IB_IB_DRF_FAIL_GROUP_reg                                                0xB803F0A0
#define  IB_IB_DRF_FAIL_GROUP_inst_addr                                          "0x001F"
#define  set_IB_IB_DRF_FAIL_GROUP_reg(data)                                      (*((volatile unsigned int*)IB_IB_DRF_FAIL_GROUP_reg)=data)
#define  get_IB_IB_DRF_FAIL_GROUP_reg                                            (*((volatile unsigned int*)IB_IB_DRF_FAIL_GROUP_reg))
#define  IB_IB_DRF_FAIL_GROUP_ib_drf_fail_group_shift                            (0)
#define  IB_IB_DRF_FAIL_GROUP_ib_drf_fail_group_mask                             (0x00000001)
#define  IB_IB_DRF_FAIL_GROUP_ib_drf_fail_group(data)                            (0x00000001&(data))
#define  IB_IB_DRF_FAIL_GROUP_get_ib_drf_fail_group(data)                        (0x00000001&(data))

#define  IB_IB_DRF_FAIL                                                          0x1803F0A4
#define  IB_IB_DRF_FAIL_reg_addr                                                 "0xB803F0A4"
#define  IB_IB_DRF_FAIL_reg                                                      0xB803F0A4
#define  IB_IB_DRF_FAIL_inst_addr                                                "0x0020"
#define  set_IB_IB_DRF_FAIL_reg(data)                                            (*((volatile unsigned int*)IB_IB_DRF_FAIL_reg)=data)
#define  get_IB_IB_DRF_FAIL_reg                                                  (*((volatile unsigned int*)IB_IB_DRF_FAIL_reg))
#define  IB_IB_DRF_FAIL_ib_drf_fail_3_shift                                      (3)
#define  IB_IB_DRF_FAIL_ib_drf_fail_2_shift                                      (2)
#define  IB_IB_DRF_FAIL_ib_drf_fail_1_shift                                      (1)
#define  IB_IB_DRF_FAIL_ib_drf_fail_0_shift                                      (0)
#define  IB_IB_DRF_FAIL_ib_drf_fail_3_mask                                       (0x00000008)
#define  IB_IB_DRF_FAIL_ib_drf_fail_2_mask                                       (0x00000004)
#define  IB_IB_DRF_FAIL_ib_drf_fail_1_mask                                       (0x00000002)
#define  IB_IB_DRF_FAIL_ib_drf_fail_0_mask                                       (0x00000001)
#define  IB_IB_DRF_FAIL_ib_drf_fail_3(data)                                      (0x00000008&((data)<<3))
#define  IB_IB_DRF_FAIL_ib_drf_fail_2(data)                                      (0x00000004&((data)<<2))
#define  IB_IB_DRF_FAIL_ib_drf_fail_1(data)                                      (0x00000002&((data)<<1))
#define  IB_IB_DRF_FAIL_ib_drf_fail_0(data)                                      (0x00000001&(data))
#define  IB_IB_DRF_FAIL_get_ib_drf_fail_3(data)                                  ((0x00000008&(data))>>3)
#define  IB_IB_DRF_FAIL_get_ib_drf_fail_2(data)                                  ((0x00000004&(data))>>2)
#define  IB_IB_DRF_FAIL_get_ib_drf_fail_1(data)                                  ((0x00000002&(data))>>1)
#define  IB_IB_DRF_FAIL_get_ib_drf_fail_0(data)                                  (0x00000001&(data))

#define  IB_IB_MEM_CTRL                                                          0x1803F0A8
#define  IB_IB_MEM_CTRL_reg_addr                                                 "0xB803F0A8"
#define  IB_IB_MEM_CTRL_reg                                                      0xB803F0A8
#define  IB_IB_MEM_CTRL_inst_addr                                                "0x0021"
#define  set_IB_IB_MEM_CTRL_reg(data)                                            (*((volatile unsigned int*)IB_IB_MEM_CTRL_reg)=data)
#define  get_IB_IB_MEM_CTRL_reg                                                  (*((volatile unsigned int*)IB_IB_MEM_CTRL_reg))
#define  IB_IB_MEM_CTRL_ls_shift                                                 (6)
#define  IB_IB_MEM_CTRL_testrwm_shift                                            (5)
#define  IB_IB_MEM_CTRL_rme_shift                                                (4)
#define  IB_IB_MEM_CTRL_rm_shift                                                 (0)
#define  IB_IB_MEM_CTRL_ls_mask                                                  (0x00000040)
#define  IB_IB_MEM_CTRL_testrwm_mask                                             (0x00000020)
#define  IB_IB_MEM_CTRL_rme_mask                                                 (0x00000010)
#define  IB_IB_MEM_CTRL_rm_mask                                                  (0x0000000F)
#define  IB_IB_MEM_CTRL_ls(data)                                                 (0x00000040&((data)<<6))
#define  IB_IB_MEM_CTRL_testrwm(data)                                            (0x00000020&((data)<<5))
#define  IB_IB_MEM_CTRL_rme(data)                                                (0x00000010&((data)<<4))
#define  IB_IB_MEM_CTRL_rm(data)                                                 (0x0000000F&(data))
#define  IB_IB_MEM_CTRL_get_ls(data)                                             ((0x00000040&(data))>>6)
#define  IB_IB_MEM_CTRL_get_testrwm(data)                                        ((0x00000020&(data))>>5)
#define  IB_IB_MEM_CTRL_get_rme(data)                                            ((0x00000010&(data))>>4)
#define  IB_IB_MEM_CTRL_get_rm(data)                                             (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======IB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_bound_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_dc1_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_dc1_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_dc1_bound_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_dc2_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_dc2_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  address:12;
        RBus_UInt32  res1:20;
    };
}ib_ib_seq_dc2_bound_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  bound_index_0:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  bound_index_1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bound_index_2:7;
        RBus_UInt32  res4:8;
    };
}ib_ib_blk_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  region_0_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  region_0_slice_basis:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  region_1_mode:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  region_1_slice_basis:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  region_2_mode:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  region_2_slice_basis:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  region_3_mode:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  region_3_slice_basis:3;
    };
}ib_ib_seq_region_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  region_0_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  region_0_slice_basis:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  region_1_mode:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  region_1_slice_basis:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  region_2_mode:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  region_2_slice_basis:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  region_3_mode:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  region_3_slice_basis:3;
    };
}ib_ib_blk_region_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  manual_margin:8;
        RBus_UInt32  dummy1803f030_23_15:9;
        RBus_UInt32  pri_out_dis:1;
        RBus_UInt32  blk_to_dc12_invert:1;
        RBus_UInt32  fast_read_dis:1;
        RBus_UInt32  di_sram_en:1;
        RBus_UInt32  old_wdata_mode:1;
        RBus_UInt32  old_rdata_mode:1;
        RBus_UInt32  old_add_mode:1;
        RBus_UInt32  pri_min_dis:1;
        RBus_UInt32  pri_down_dis:1;
        RBus_UInt32  debug_sel:1;
        RBus_UInt32  multi_write_dis:1;
        RBus_UInt32  time_step:4;
    };
}ib_ib_time_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  space_magin:4;
    };
}ib_ib_cti_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_31_0:32;
    };
}ib_ib_input_addcmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_index:14;
        RBus_UInt32  addcmd_49_32:18;
    };
}ib_ib_input_addcmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_31_0:32;
    };
}ib_ib_output_dc1_addcmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_index:14;
        RBus_UInt32  addcmd_49_32:18;
    };
}ib_ib_output_dc1_addcmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_31_0:32;
    };
}ib_ib_output_dc2_addcmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  command_index:14;
        RBus_UInt32  addcmd_49_32:18;
    };
}ib_ib_output_dc2_addcmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_status_clr:1;
        RBus_UInt32  dummy1803f0f0_30:1;
        RBus_UInt32  dc1_st_in_disram:1;
        RBus_UInt32  dc1_end_in_disram:1;
        RBus_UInt32  dc2_st_in_disram:1;
        RBus_UInt32  dc2_end_in_disram:1;
        RBus_UInt32  region_error:1;
        RBus_UInt32  wdout_dc2_underflow:1;
        RBus_UInt32  wdata_dc2_underflow:1;
        RBus_UInt32  wdata_dc2_overflow:1;
        RBus_UInt32  wdout_dc1_underflow:1;
        RBus_UInt32  wdata_dc1_underflow:1;
        RBus_UInt32  wdata_dc1_overflow:1;
        RBus_UInt32  rdout_dc2_underflow:1;
        RBus_UInt32  rdata_dc2_underflow:1;
        RBus_UInt32  rdata_dc2_overflow:1;
        RBus_UInt32  rdout_dc1_underflow:1;
        RBus_UInt32  rdata_dc1_underflow:1;
        RBus_UInt32  rdata_dc1_overflow:1;
        RBus_UInt32  cmd_dc2_underflow:1;
        RBus_UInt32  cmd_dc2_overflow:1;
        RBus_UInt32  cmd_dc1_underflow:1;
        RBus_UInt32  cmd_dc1_overflow:1;
        RBus_UInt32  wdone_underflow:1;
        RBus_UInt32  wdone_overflow:1;
        RBus_UInt32  winfo_underflow:1;
        RBus_UInt32  winfo_overflow:1;
        RBus_UInt32  rinfo_underflow:1;
        RBus_UInt32  rinfo_overflow:1;
        RBus_UInt32  seq_saddr_odd:1;
        RBus_UInt32  seq_blen_odd:1;
        RBus_UInt32  seq_blen_zero:1;
    };
}ib_ib_error_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_status_clr:1;
        RBus_UInt32  trap_case:11;
        RBus_UInt32  addcmd_hi:20;
    };
}ib_ib_error_trap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}ib_ib_error_trap_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_bist_mode:1;
    };
}ib_ib_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_bist_done:1;
    };
}ib_ib_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_bist_fail_group:1;
    };
}ib_ib_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ib_bist_fail_3:1;
        RBus_UInt32  ib_bist_fail_2:1;
        RBus_UInt32  ib_bist_fail_1:1;
        RBus_UInt32  ib_bist_fail_0:1;
    };
}ib_ib_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_drf_mode:1;
    };
}ib_ib_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_drf_resume:1;
    };
}ib_ib_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_drf_done:1;
    };
}ib_ib_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_drf_pause:1;
    };
}ib_ib_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  ib_drf_fail_group:1;
    };
}ib_ib_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ib_drf_fail_3:1;
        RBus_UInt32  ib_drf_fail_2:1;
        RBus_UInt32  ib_drf_fail_1:1;
        RBus_UInt32  ib_drf_fail_0:1;
    };
}ib_ib_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ls:1;
        RBus_UInt32  testrwm:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}ib_ib_mem_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======IB register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_bound_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_dc1_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_dc1_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_dc1_bound_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_dc2_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_dc2_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  address:12;
    };
}ib_ib_seq_dc2_bound_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  bound_index_2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  bound_index_1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bound_index_0:7;
        RBus_UInt32  res4:1;
    };
}ib_ib_blk_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  region_3_slice_basis:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  region_3_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  region_2_slice_basis:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  region_2_mode:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  region_1_slice_basis:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  region_1_mode:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  region_0_slice_basis:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  region_0_mode:3;
        RBus_UInt32  res8:1;
    };
}ib_ib_seq_region_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  region_3_slice_basis:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  region_3_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  region_2_slice_basis:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  region_2_mode:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  region_1_slice_basis:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  region_1_mode:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  region_0_slice_basis:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  region_0_mode:3;
        RBus_UInt32  res8:1;
    };
}ib_ib_blk_region_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_step:4;
        RBus_UInt32  multi_write_dis:1;
        RBus_UInt32  debug_sel:1;
        RBus_UInt32  pri_down_dis:1;
        RBus_UInt32  pri_min_dis:1;
        RBus_UInt32  old_add_mode:1;
        RBus_UInt32  old_rdata_mode:1;
        RBus_UInt32  old_wdata_mode:1;
        RBus_UInt32  di_sram_en:1;
        RBus_UInt32  fast_read_dis:1;
        RBus_UInt32  blk_to_dc12_invert:1;
        RBus_UInt32  pri_out_dis:1;
        RBus_UInt32  dummy1803f030_23_15:9;
        RBus_UInt32  manual_margin:8;
    };
}ib_ib_time_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  space_magin:4;
        RBus_UInt32  res1:28;
    };
}ib_ib_cti_space_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_31_0:32;
    };
}ib_ib_input_addcmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_49_32:18;
        RBus_UInt32  command_index:14;
    };
}ib_ib_input_addcmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_31_0:32;
    };
}ib_ib_output_dc1_addcmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_49_32:18;
        RBus_UInt32  command_index:14;
    };
}ib_ib_output_dc1_addcmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_31_0:32;
    };
}ib_ib_output_dc2_addcmd0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_49_32:18;
        RBus_UInt32  command_index:14;
    };
}ib_ib_output_dc2_addcmd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_blen_zero:1;
        RBus_UInt32  seq_blen_odd:1;
        RBus_UInt32  seq_saddr_odd:1;
        RBus_UInt32  rinfo_overflow:1;
        RBus_UInt32  rinfo_underflow:1;
        RBus_UInt32  winfo_overflow:1;
        RBus_UInt32  winfo_underflow:1;
        RBus_UInt32  wdone_overflow:1;
        RBus_UInt32  wdone_underflow:1;
        RBus_UInt32  cmd_dc1_overflow:1;
        RBus_UInt32  cmd_dc1_underflow:1;
        RBus_UInt32  cmd_dc2_overflow:1;
        RBus_UInt32  cmd_dc2_underflow:1;
        RBus_UInt32  rdata_dc1_overflow:1;
        RBus_UInt32  rdata_dc1_underflow:1;
        RBus_UInt32  rdout_dc1_underflow:1;
        RBus_UInt32  rdata_dc2_overflow:1;
        RBus_UInt32  rdata_dc2_underflow:1;
        RBus_UInt32  rdout_dc2_underflow:1;
        RBus_UInt32  wdata_dc1_overflow:1;
        RBus_UInt32  wdata_dc1_underflow:1;
        RBus_UInt32  wdout_dc1_underflow:1;
        RBus_UInt32  wdata_dc2_overflow:1;
        RBus_UInt32  wdata_dc2_underflow:1;
        RBus_UInt32  wdout_dc2_underflow:1;
        RBus_UInt32  region_error:1;
        RBus_UInt32  dc2_end_in_disram:1;
        RBus_UInt32  dc2_st_in_disram:1;
        RBus_UInt32  dc1_end_in_disram:1;
        RBus_UInt32  dc1_st_in_disram:1;
        RBus_UInt32  dummy1803f0f0_30:1;
        RBus_UInt32  error_status_clr:1;
    };
}ib_ib_error_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:20;
        RBus_UInt32  trap_case:11;
        RBus_UInt32  trap_status_clr:1;
    };
}ib_ib_error_trap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}ib_ib_error_trap_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_bist_done:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_bist_fail_group:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_bist_fail_0:1;
        RBus_UInt32  ib_bist_fail_1:1;
        RBus_UInt32  ib_bist_fail_2:1;
        RBus_UInt32  ib_bist_fail_3:1;
        RBus_UInt32  res1:28;
    };
}ib_ib_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_drf_done:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}ib_ib_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_drf_fail_0:1;
        RBus_UInt32  ib_drf_fail_1:1;
        RBus_UInt32  ib_drf_fail_2:1;
        RBus_UInt32  ib_drf_fail_3:1;
        RBus_UInt32  res1:28;
    };
}ib_ib_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  testrwm:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:25;
    };
}ib_ib_mem_ctrl_RBUS;




#endif 


#endif 
