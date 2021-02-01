/**
* @file rbusC3DLUTReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_C3DLUT_REG_H_
#define _RBUS_C3DLUT_REG_H_

#include "rbus_types.h"



//  C3DLUT Register Address
#define  C3DLUT_C3DLUT_LUT_CTRL                                                  0x18028A00
#define  C3DLUT_C3DLUT_LUT_CTRL_reg_addr                                         "0xB8028A00"
#define  C3DLUT_C3DLUT_LUT_CTRL_reg                                              0xB8028A00
#define  C3DLUT_C3DLUT_LUT_CTRL_inst_addr                                        "0x0000"
#define  set_C3DLUT_C3DLUT_LUT_CTRL_reg(data)                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_CTRL_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_CTRL_reg                                          (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_CTRL_reg))
#define  C3DLUT_C3DLUT_LUT_CTRL_c3dlut_ctrl_shift                                (0)
#define  C3DLUT_C3DLUT_LUT_CTRL_c3dlut_ctrl_mask                                 (0x00000003)
#define  C3DLUT_C3DLUT_LUT_CTRL_c3dlut_ctrl(data)                                (0x00000003&(data))
#define  C3DLUT_C3DLUT_LUT_CTRL_get_c3dlut_ctrl(data)                            (0x00000003&(data))

#define  C3DLUT_C3DLUT_LUT_CTRL0                                                 0x18028A04
#define  C3DLUT_C3DLUT_LUT_CTRL0_reg_addr                                        "0xB8028A04"
#define  C3DLUT_C3DLUT_LUT_CTRL0_reg                                             0xB8028A04
#define  C3DLUT_C3DLUT_LUT_CTRL0_inst_addr                                       "0x0001"
#define  set_C3DLUT_C3DLUT_LUT_CTRL0_reg(data)                                   (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_CTRL0_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_CTRL0_reg                                         (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_CTRL0_reg))
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_rw_sel_shift                                (29)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_write_en_shift                              (28)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_read_en_shift                               (27)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_rw_adr_shift                                (0)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_rw_sel_mask                                 (0x60000000)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_write_en_mask                               (0x10000000)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_read_en_mask                                (0x08000000)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_rw_adr_mask                                 (0x000003FF)
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_rw_sel(data)                                (0x60000000&((data)<<29))
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_write_en(data)                              (0x10000000&((data)<<28))
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_read_en(data)                               (0x08000000&((data)<<27))
#define  C3DLUT_C3DLUT_LUT_CTRL0_lut_rw_adr(data)                                (0x000003FF&(data))
#define  C3DLUT_C3DLUT_LUT_CTRL0_get_lut_rw_sel(data)                            ((0x60000000&(data))>>29)
#define  C3DLUT_C3DLUT_LUT_CTRL0_get_lut_write_en(data)                          ((0x10000000&(data))>>28)
#define  C3DLUT_C3DLUT_LUT_CTRL0_get_lut_read_en(data)                           ((0x08000000&(data))>>27)
#define  C3DLUT_C3DLUT_LUT_CTRL0_get_lut_rw_adr(data)                            (0x000003FF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_1                                             0x18028A08
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_reg_addr                                    "0xB8028A08"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_reg                                         0xB8028A08
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_inst_addr                                   "0x0002"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_1_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_1_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_1_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_1_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_lut_wr_data_d0_1_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_lut_wr_data_d1_1_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_lut_wr_data_d0_1_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_lut_wr_data_d1_1_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_lut_wr_data_d0_1(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_lut_wr_data_d1_1(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_get_lut_wr_data_d0_1(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_1_get_lut_wr_data_d1_1(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_2                                             0x18028A0C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_reg_addr                                    "0xB8028A0C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_reg                                         0xB8028A0C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_inst_addr                                   "0x0003"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_2_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_2_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_2_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_2_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_lut_wr_data_d2_1_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_lut_wr_data_d2_1_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_lut_wr_data_d2_1(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_2_get_lut_wr_data_d2_1(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_3                                             0x18028A10
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_reg_addr                                    "0xB8028A10"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_reg                                         0xB8028A10
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_inst_addr                                   "0x0004"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_3_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_3_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_3_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_3_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_lut_wr_data_d0_2_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_lut_wr_data_d1_2_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_lut_wr_data_d0_2_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_lut_wr_data_d1_2_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_lut_wr_data_d0_2(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_lut_wr_data_d1_2(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_get_lut_wr_data_d0_2(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_3_get_lut_wr_data_d1_2(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_4                                             0x18028A14
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_reg_addr                                    "0xB8028A14"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_reg                                         0xB8028A14
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_inst_addr                                   "0x0005"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_4_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_4_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_4_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_4_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_lut_wr_data_d2_2_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_lut_wr_data_d2_2_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_lut_wr_data_d2_2(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_4_get_lut_wr_data_d2_2(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_5                                             0x18028A18
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_reg_addr                                    "0xB8028A18"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_reg                                         0xB8028A18
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_inst_addr                                   "0x0006"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_5_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_5_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_5_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_5_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_lut_wr_data_d0_3_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_lut_wr_data_d1_3_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_lut_wr_data_d0_3_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_lut_wr_data_d1_3_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_lut_wr_data_d0_3(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_lut_wr_data_d1_3(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_get_lut_wr_data_d0_3(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_5_get_lut_wr_data_d1_3(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_6                                             0x18028A1C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_reg_addr                                    "0xB8028A1C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_reg                                         0xB8028A1C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_inst_addr                                   "0x0007"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_6_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_6_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_6_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_6_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_lut_wr_data_d2_3_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_lut_wr_data_d2_3_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_lut_wr_data_d2_3(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_6_get_lut_wr_data_d2_3(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_7                                             0x18028A20
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_reg_addr                                    "0xB8028A20"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_reg                                         0xB8028A20
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_inst_addr                                   "0x0008"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_7_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_7_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_7_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_7_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_lut_wr_data_d0_4_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_lut_wr_data_d1_4_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_lut_wr_data_d0_4_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_lut_wr_data_d1_4_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_lut_wr_data_d0_4(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_lut_wr_data_d1_4(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_get_lut_wr_data_d0_4(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_7_get_lut_wr_data_d1_4(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_8                                             0x18028A24
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_reg_addr                                    "0xB8028A24"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_reg                                         0xB8028A24
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_inst_addr                                   "0x0009"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_8_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_8_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_8_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_8_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_lut_wr_data_d2_4_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_lut_wr_data_d2_4_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_lut_wr_data_d2_4(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_8_get_lut_wr_data_d2_4(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_9                                             0x18028A28
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_reg_addr                                    "0xB8028A28"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_reg                                         0xB8028A28
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_inst_addr                                   "0x000A"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_9_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_9_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_9_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_9_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_lut_wr_data_d0_5_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_lut_wr_data_d1_5_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_lut_wr_data_d0_5_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_lut_wr_data_d1_5_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_lut_wr_data_d0_5(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_lut_wr_data_d1_5(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_get_lut_wr_data_d0_5(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_9_get_lut_wr_data_d1_5(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_10                                            0x18028A2C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_reg_addr                                   "0xB8028A2C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_reg                                        0xB8028A2C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_inst_addr                                  "0x000B"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_10_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_10_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_10_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_10_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_lut_wr_data_d2_5_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_lut_wr_data_d2_5_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_lut_wr_data_d2_5(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_10_get_lut_wr_data_d2_5(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_11                                            0x18028A30
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_reg_addr                                   "0xB8028A30"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_reg                                        0xB8028A30
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_inst_addr                                  "0x000C"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_11_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_11_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_11_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_11_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_lut_wr_data_d0_6_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_lut_wr_data_d1_6_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_lut_wr_data_d0_6_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_lut_wr_data_d1_6_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_lut_wr_data_d0_6(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_lut_wr_data_d1_6(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_get_lut_wr_data_d0_6(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_11_get_lut_wr_data_d1_6(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_12                                            0x18028A34
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_reg_addr                                   "0xB8028A34"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_reg                                        0xB8028A34
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_inst_addr                                  "0x000D"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_12_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_12_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_12_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_12_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_lut_wr_data_d2_6_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_lut_wr_data_d2_6_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_lut_wr_data_d2_6(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_12_get_lut_wr_data_d2_6(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_13                                            0x18028A38
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_reg_addr                                   "0xB8028A38"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_reg                                        0xB8028A38
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_inst_addr                                  "0x000E"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_13_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_13_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_13_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_13_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_lut_wr_data_d0_7_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_lut_wr_data_d1_7_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_lut_wr_data_d0_7_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_lut_wr_data_d1_7_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_lut_wr_data_d0_7(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_lut_wr_data_d1_7(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_get_lut_wr_data_d0_7(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_13_get_lut_wr_data_d1_7(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_14                                            0x18028A3C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_reg_addr                                   "0xB8028A3C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_reg                                        0xB8028A3C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_inst_addr                                  "0x000F"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_14_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_14_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_14_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_14_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_lut_wr_data_d2_7_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_lut_wr_data_d2_7_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_lut_wr_data_d2_7(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_14_get_lut_wr_data_d2_7(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_15                                            0x18028A40
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_reg_addr                                   "0xB8028A40"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_reg                                        0xB8028A40
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_inst_addr                                  "0x0010"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_15_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_15_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_15_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_15_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_lut_wr_data_d0_8_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_lut_wr_data_d1_8_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_lut_wr_data_d0_8_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_lut_wr_data_d1_8_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_lut_wr_data_d0_8(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_lut_wr_data_d1_8(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_get_lut_wr_data_d0_8(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_15_get_lut_wr_data_d1_8(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_16                                            0x18028A44
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_reg_addr                                   "0xB8028A44"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_reg                                        0xB8028A44
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_inst_addr                                  "0x0011"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_16_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_16_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_16_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_16_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_lut_wr_data_d2_8_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_lut_wr_data_d2_8_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_lut_wr_data_d2_8(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_16_get_lut_wr_data_d2_8(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_17                                            0x18028A48
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_reg_addr                                   "0xB8028A48"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_reg                                        0xB8028A48
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_inst_addr                                  "0x0012"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_17_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_17_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_17_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_17_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_lut_wr_data_d0_9_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_lut_wr_data_d1_9_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_lut_wr_data_d0_9_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_lut_wr_data_d1_9_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_lut_wr_data_d0_9(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_lut_wr_data_d1_9(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_get_lut_wr_data_d0_9(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_17_get_lut_wr_data_d1_9(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_18                                            0x18028A4C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_reg_addr                                   "0xB8028A4C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_reg                                        0xB8028A4C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_inst_addr                                  "0x0013"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_18_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_18_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_18_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_18_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_lut_wr_data_d2_9_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_lut_wr_data_d2_9_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_lut_wr_data_d2_9(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_18_get_lut_wr_data_d2_9(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_19                                            0x18028A50
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_reg_addr                                   "0xB8028A50"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_reg                                        0xB8028A50
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_inst_addr                                  "0x0014"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_19_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_19_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_19_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_19_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_lut_wr_data_d0_10_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_lut_wr_data_d1_10_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_lut_wr_data_d0_10_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_lut_wr_data_d1_10_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_lut_wr_data_d0_10(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_lut_wr_data_d1_10(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_get_lut_wr_data_d0_10(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_19_get_lut_wr_data_d1_10(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_20                                            0x18028A54
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_reg_addr                                   "0xB8028A54"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_reg                                        0xB8028A54
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_inst_addr                                  "0x0015"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_20_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_20_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_20_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_20_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_lut_wr_data_d2_10_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_lut_wr_data_d2_10_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_lut_wr_data_d2_10(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_20_get_lut_wr_data_d2_10(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_21                                            0x18028A58
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_reg_addr                                   "0xB8028A58"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_reg                                        0xB8028A58
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_inst_addr                                  "0x0016"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_21_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_21_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_21_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_21_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_lut_wr_data_d0_11_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_lut_wr_data_d1_11_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_lut_wr_data_d0_11_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_lut_wr_data_d1_11_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_lut_wr_data_d0_11(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_lut_wr_data_d1_11(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_get_lut_wr_data_d0_11(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_21_get_lut_wr_data_d1_11(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_22                                            0x18028A5C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_reg_addr                                   "0xB8028A5C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_reg                                        0xB8028A5C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_inst_addr                                  "0x0017"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_22_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_22_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_22_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_22_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_lut_wr_data_d2_11_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_lut_wr_data_d2_11_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_lut_wr_data_d2_11(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_22_get_lut_wr_data_d2_11(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_23                                            0x18028A60
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_reg_addr                                   "0xB8028A60"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_reg                                        0xB8028A60
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_inst_addr                                  "0x0018"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_23_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_23_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_23_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_23_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_lut_wr_data_d0_12_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_lut_wr_data_d1_12_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_lut_wr_data_d0_12_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_lut_wr_data_d1_12_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_lut_wr_data_d0_12(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_lut_wr_data_d1_12(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_get_lut_wr_data_d0_12(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_23_get_lut_wr_data_d1_12(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_24                                            0x18028A64
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_reg_addr                                   "0xB8028A64"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_reg                                        0xB8028A64
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_inst_addr                                  "0x0019"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_24_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_24_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_24_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_24_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_lut_wr_data_d2_12_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_lut_wr_data_d2_12_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_lut_wr_data_d2_12(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_24_get_lut_wr_data_d2_12(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_25                                            0x18028A68
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_reg_addr                                   "0xB8028A68"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_reg                                        0xB8028A68
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_inst_addr                                  "0x001A"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_25_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_25_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_25_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_25_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_lut_wr_data_d0_13_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_lut_wr_data_d1_13_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_lut_wr_data_d0_13_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_lut_wr_data_d1_13_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_lut_wr_data_d0_13(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_lut_wr_data_d1_13(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_get_lut_wr_data_d0_13(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_25_get_lut_wr_data_d1_13(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_26                                            0x18028A6C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_reg_addr                                   "0xB8028A6C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_reg                                        0xB8028A6C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_inst_addr                                  "0x001B"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_26_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_26_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_26_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_26_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_lut_wr_data_d2_13_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_lut_wr_data_d2_13_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_lut_wr_data_d2_13(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_26_get_lut_wr_data_d2_13(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_27                                            0x18028A70
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_reg_addr                                   "0xB8028A70"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_reg                                        0xB8028A70
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_inst_addr                                  "0x001C"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_27_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_27_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_27_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_27_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_lut_wr_data_d0_14_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_lut_wr_data_d1_14_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_lut_wr_data_d0_14_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_lut_wr_data_d1_14_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_lut_wr_data_d0_14(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_lut_wr_data_d1_14(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_get_lut_wr_data_d0_14(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_27_get_lut_wr_data_d1_14(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_28                                            0x18028A74
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_reg_addr                                   "0xB8028A74"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_reg                                        0xB8028A74
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_inst_addr                                  "0x001D"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_28_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_28_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_28_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_28_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_lut_wr_data_d2_14_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_lut_wr_data_d2_14_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_lut_wr_data_d2_14(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_28_get_lut_wr_data_d2_14(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_29                                            0x18028A78
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_reg_addr                                   "0xB8028A78"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_reg                                        0xB8028A78
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_inst_addr                                  "0x001E"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_29_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_29_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_29_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_29_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_lut_wr_data_d0_15_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_lut_wr_data_d1_15_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_lut_wr_data_d0_15_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_lut_wr_data_d1_15_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_lut_wr_data_d0_15(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_lut_wr_data_d1_15(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_get_lut_wr_data_d0_15(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_29_get_lut_wr_data_d1_15(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_30                                            0x18028A7C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_reg_addr                                   "0xB8028A7C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_reg                                        0xB8028A7C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_inst_addr                                  "0x001F"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_30_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_30_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_30_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_30_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_lut_wr_data_d2_15_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_lut_wr_data_d2_15_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_lut_wr_data_d2_15(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_30_get_lut_wr_data_d2_15(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_31                                            0x18028A80
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_reg_addr                                   "0xB8028A80"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_reg                                        0xB8028A80
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_inst_addr                                  "0x0020"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_31_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_31_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_31_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_31_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_lut_wr_data_d0_16_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_lut_wr_data_d1_16_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_lut_wr_data_d0_16_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_lut_wr_data_d1_16_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_lut_wr_data_d0_16(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_lut_wr_data_d1_16(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_get_lut_wr_data_d0_16(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_31_get_lut_wr_data_d1_16(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_32                                            0x18028A84
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_reg_addr                                   "0xB8028A84"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_reg                                        0xB8028A84
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_inst_addr                                  "0x0021"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_32_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_32_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_32_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_32_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_lut_wr_data_d2_16_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_lut_wr_data_d2_16_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_lut_wr_data_d2_16(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_32_get_lut_wr_data_d2_16(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_33                                            0x18028A88
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_reg_addr                                   "0xB8028A88"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_reg                                        0xB8028A88
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_inst_addr                                  "0x0022"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_33_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_33_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_33_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_33_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_lut_wr_data_d0_17_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_lut_wr_data_d1_17_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_lut_wr_data_d0_17_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_lut_wr_data_d1_17_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_lut_wr_data_d0_17(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_lut_wr_data_d1_17(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_get_lut_wr_data_d0_17(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_33_get_lut_wr_data_d1_17(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_WR_DATA_34                                            0x18028A8C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_reg_addr                                   "0xB8028A8C"
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_reg                                        0xB8028A8C
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_inst_addr                                  "0x0023"
#define  set_C3DLUT_C3DLUT_LUT_WR_DATA_34_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_34_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_WR_DATA_34_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_WR_DATA_34_reg))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_lut_wr_data_d2_17_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_lut_wr_data_d2_17_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_lut_wr_data_d2_17(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_WR_DATA_34_get_lut_wr_data_d2_17(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_1                                             0x18028A90
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_reg_addr                                    "0xB8028A90"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_reg                                         0xB8028A90
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_inst_addr                                   "0x0024"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_1_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_1_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_1_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_1_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_lut_rd_data_d0_1_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_lut_rd_data_d1_1_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_lut_rd_data_d0_1_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_lut_rd_data_d1_1_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_lut_rd_data_d0_1(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_lut_rd_data_d1_1(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_get_lut_rd_data_d0_1(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_1_get_lut_rd_data_d1_1(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_2                                             0x18028A94
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_reg_addr                                    "0xB8028A94"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_reg                                         0xB8028A94
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_inst_addr                                   "0x0025"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_2_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_2_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_2_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_2_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_lut_rd_data_d2_1_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_lut_rd_data_d2_1_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_lut_rd_data_d2_1(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_2_get_lut_rd_data_d2_1(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_3                                             0x18028A98
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_reg_addr                                    "0xB8028A98"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_reg                                         0xB8028A98
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_inst_addr                                   "0x0026"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_3_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_3_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_3_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_3_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_lut_rd_data_d0_2_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_lut_rd_data_d1_2_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_lut_rd_data_d0_2_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_lut_rd_data_d1_2_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_lut_rd_data_d0_2(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_lut_rd_data_d1_2(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_get_lut_rd_data_d0_2(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_3_get_lut_rd_data_d1_2(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_4                                             0x18028A9C
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_reg_addr                                    "0xB8028A9C"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_reg                                         0xB8028A9C
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_inst_addr                                   "0x0027"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_4_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_4_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_4_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_4_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_lut_rd_data_d2_2_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_lut_rd_data_d2_2_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_lut_rd_data_d2_2(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_4_get_lut_rd_data_d2_2(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_5                                             0x18028AA0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_reg_addr                                    "0xB8028AA0"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_reg                                         0xB8028AA0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_inst_addr                                   "0x0028"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_5_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_5_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_5_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_5_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_lut_rd_data_d0_3_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_lut_rd_data_d1_3_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_lut_rd_data_d0_3_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_lut_rd_data_d1_3_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_lut_rd_data_d0_3(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_lut_rd_data_d1_3(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_get_lut_rd_data_d0_3(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_5_get_lut_rd_data_d1_3(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_6                                             0x18028AA4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_reg_addr                                    "0xB8028AA4"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_reg                                         0xB8028AA4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_inst_addr                                   "0x0029"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_6_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_6_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_6_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_6_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_lut_rd_data_d2_3_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_lut_rd_data_d2_3_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_lut_rd_data_d2_3(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_6_get_lut_rd_data_d2_3(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_7                                             0x18028AA8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_reg_addr                                    "0xB8028AA8"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_reg                                         0xB8028AA8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_inst_addr                                   "0x002A"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_7_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_7_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_7_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_7_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_lut_rd_data_d0_4_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_lut_rd_data_d1_4_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_lut_rd_data_d0_4_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_lut_rd_data_d1_4_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_lut_rd_data_d0_4(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_lut_rd_data_d1_4(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_get_lut_rd_data_d0_4(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_7_get_lut_rd_data_d1_4(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_8                                             0x18028AAC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_reg_addr                                    "0xB8028AAC"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_reg                                         0xB8028AAC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_inst_addr                                   "0x002B"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_8_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_8_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_8_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_8_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_lut_rd_data_d2_4_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_lut_rd_data_d2_4_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_lut_rd_data_d2_4(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_8_get_lut_rd_data_d2_4(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_9                                             0x18028AB0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_reg_addr                                    "0xB8028AB0"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_reg                                         0xB8028AB0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_inst_addr                                   "0x002C"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_9_reg(data)                               (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_9_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_9_reg                                     (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_9_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_lut_rd_data_d0_5_shift                      (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_lut_rd_data_d1_5_shift                      (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_lut_rd_data_d0_5_mask                       (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_lut_rd_data_d1_5_mask                       (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_lut_rd_data_d0_5(data)                      (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_lut_rd_data_d1_5(data)                      (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_get_lut_rd_data_d0_5(data)                  ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_9_get_lut_rd_data_d1_5(data)                  (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_10                                            0x18028AB4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_reg_addr                                   "0xB8028AB4"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_reg                                        0xB8028AB4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_inst_addr                                  "0x002D"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_10_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_10_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_10_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_10_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_lut_rd_data_d2_5_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_lut_rd_data_d2_5_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_lut_rd_data_d2_5(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_10_get_lut_rd_data_d2_5(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_11                                            0x18028AB8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_reg_addr                                   "0xB8028AB8"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_reg                                        0xB8028AB8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_inst_addr                                  "0x002E"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_11_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_11_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_11_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_11_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_lut_rd_data_d0_6_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_lut_rd_data_d1_6_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_lut_rd_data_d0_6_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_lut_rd_data_d1_6_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_lut_rd_data_d0_6(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_lut_rd_data_d1_6(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_get_lut_rd_data_d0_6(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_11_get_lut_rd_data_d1_6(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_12                                            0x18028ABC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_reg_addr                                   "0xB8028ABC"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_reg                                        0xB8028ABC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_inst_addr                                  "0x002F"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_12_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_12_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_12_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_12_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_lut_rd_data_d2_6_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_lut_rd_data_d2_6_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_lut_rd_data_d2_6(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_12_get_lut_rd_data_d2_6(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_13                                            0x18028AC0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_reg_addr                                   "0xB8028AC0"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_reg                                        0xB8028AC0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_inst_addr                                  "0x0030"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_13_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_13_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_13_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_13_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_lut_rd_data_d0_7_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_lut_rd_data_d1_7_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_lut_rd_data_d0_7_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_lut_rd_data_d1_7_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_lut_rd_data_d0_7(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_lut_rd_data_d1_7(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_get_lut_rd_data_d0_7(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_13_get_lut_rd_data_d1_7(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_14                                            0x18028AC4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_reg_addr                                   "0xB8028AC4"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_reg                                        0xB8028AC4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_inst_addr                                  "0x0031"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_14_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_14_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_14_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_14_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_lut_rd_data_d2_7_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_lut_rd_data_d2_7_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_lut_rd_data_d2_7(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_14_get_lut_rd_data_d2_7(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_15                                            0x18028AC8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_reg_addr                                   "0xB8028AC8"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_reg                                        0xB8028AC8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_inst_addr                                  "0x0032"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_15_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_15_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_15_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_15_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_lut_rd_data_d0_8_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_lut_rd_data_d1_8_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_lut_rd_data_d0_8_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_lut_rd_data_d1_8_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_lut_rd_data_d0_8(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_lut_rd_data_d1_8(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_get_lut_rd_data_d0_8(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_15_get_lut_rd_data_d1_8(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_16                                            0x18028ACC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_reg_addr                                   "0xB8028ACC"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_reg                                        0xB8028ACC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_inst_addr                                  "0x0033"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_16_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_16_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_16_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_16_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_lut_rd_data_d2_8_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_lut_rd_data_d2_8_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_lut_rd_data_d2_8(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_16_get_lut_rd_data_d2_8(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_17                                            0x18028AD0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_reg_addr                                   "0xB8028AD0"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_reg                                        0xB8028AD0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_inst_addr                                  "0x0034"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_17_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_17_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_17_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_17_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_lut_rd_data_d0_9_shift                     (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_lut_rd_data_d1_9_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_lut_rd_data_d0_9_mask                      (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_lut_rd_data_d1_9_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_lut_rd_data_d0_9(data)                     (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_lut_rd_data_d1_9(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_get_lut_rd_data_d0_9(data)                 ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_17_get_lut_rd_data_d1_9(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_18                                            0x18028AD4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_reg_addr                                   "0xB8028AD4"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_reg                                        0xB8028AD4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_inst_addr                                  "0x0035"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_18_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_18_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_18_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_18_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_lut_rd_data_d2_9_shift                     (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_lut_rd_data_d2_9_mask                      (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_lut_rd_data_d2_9(data)                     (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_18_get_lut_rd_data_d2_9(data)                 (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_19                                            0x18028AD8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_reg_addr                                   "0xB8028AD8"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_reg                                        0xB8028AD8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_inst_addr                                  "0x0036"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_19_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_19_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_19_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_19_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_lut_rd_data_d0_10_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_lut_rd_data_d1_10_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_lut_rd_data_d0_10_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_lut_rd_data_d1_10_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_lut_rd_data_d0_10(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_lut_rd_data_d1_10(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_get_lut_rd_data_d0_10(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_19_get_lut_rd_data_d1_10(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_20                                            0x18028ADC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_reg_addr                                   "0xB8028ADC"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_reg                                        0xB8028ADC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_inst_addr                                  "0x0037"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_20_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_20_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_20_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_20_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_lut_rd_data_d2_10_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_lut_rd_data_d2_10_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_lut_rd_data_d2_10(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_20_get_lut_rd_data_d2_10(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_21                                            0x18028AE0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_reg_addr                                   "0xB8028AE0"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_reg                                        0xB8028AE0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_inst_addr                                  "0x0038"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_21_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_21_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_21_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_21_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_lut_rd_data_d0_11_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_lut_rd_data_d1_11_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_lut_rd_data_d0_11_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_lut_rd_data_d1_11_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_lut_rd_data_d0_11(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_lut_rd_data_d1_11(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_get_lut_rd_data_d0_11(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_21_get_lut_rd_data_d1_11(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_22                                            0x18028AE4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_reg_addr                                   "0xB8028AE4"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_reg                                        0xB8028AE4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_inst_addr                                  "0x0039"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_22_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_22_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_22_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_22_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_lut_rd_data_d2_11_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_lut_rd_data_d2_11_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_lut_rd_data_d2_11(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_22_get_lut_rd_data_d2_11(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_23                                            0x18028AE8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_reg_addr                                   "0xB8028AE8"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_reg                                        0xB8028AE8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_inst_addr                                  "0x003A"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_23_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_23_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_23_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_23_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_lut_rd_data_d0_12_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_lut_rd_data_d1_12_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_lut_rd_data_d0_12_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_lut_rd_data_d1_12_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_lut_rd_data_d0_12(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_lut_rd_data_d1_12(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_get_lut_rd_data_d0_12(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_23_get_lut_rd_data_d1_12(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_24                                            0x18028AEC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_reg_addr                                   "0xB8028AEC"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_reg                                        0xB8028AEC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_inst_addr                                  "0x003B"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_24_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_24_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_24_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_24_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_lut_rd_data_d2_12_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_lut_rd_data_d2_12_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_lut_rd_data_d2_12(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_24_get_lut_rd_data_d2_12(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_25                                            0x18028AF0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_reg_addr                                   "0xB8028AF0"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_reg                                        0xB8028AF0
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_inst_addr                                  "0x003C"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_25_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_25_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_25_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_25_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_lut_rd_data_d0_13_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_lut_rd_data_d1_13_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_lut_rd_data_d0_13_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_lut_rd_data_d1_13_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_lut_rd_data_d0_13(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_lut_rd_data_d1_13(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_get_lut_rd_data_d0_13(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_25_get_lut_rd_data_d1_13(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_26                                            0x18028AF4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_reg_addr                                   "0xB8028AF4"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_reg                                        0xB8028AF4
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_inst_addr                                  "0x003D"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_26_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_26_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_26_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_26_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_lut_rd_data_d2_13_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_lut_rd_data_d2_13_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_lut_rd_data_d2_13(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_26_get_lut_rd_data_d2_13(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_27                                            0x18028AF8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_reg_addr                                   "0xB8028AF8"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_reg                                        0xB8028AF8
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_inst_addr                                  "0x003E"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_27_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_27_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_27_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_27_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_lut_rd_data_d0_14_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_lut_rd_data_d1_14_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_lut_rd_data_d0_14_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_lut_rd_data_d1_14_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_lut_rd_data_d0_14(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_lut_rd_data_d1_14(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_get_lut_rd_data_d0_14(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_27_get_lut_rd_data_d1_14(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_28                                            0x18028AFC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_reg_addr                                   "0xB8028AFC"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_reg                                        0xB8028AFC
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_inst_addr                                  "0x003F"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_28_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_28_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_28_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_28_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_lut_rd_data_d2_14_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_lut_rd_data_d2_14_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_lut_rd_data_d2_14(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_28_get_lut_rd_data_d2_14(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_29                                            0x18028B00
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_reg_addr                                   "0xB8028B00"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_reg                                        0xB8028B00
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_inst_addr                                  "0x0040"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_29_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_29_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_29_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_29_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_lut_rd_data_d0_15_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_lut_rd_data_d1_15_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_lut_rd_data_d0_15_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_lut_rd_data_d1_15_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_lut_rd_data_d0_15(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_lut_rd_data_d1_15(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_get_lut_rd_data_d0_15(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_29_get_lut_rd_data_d1_15(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_30                                            0x18028B04
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_reg_addr                                   "0xB8028B04"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_reg                                        0xB8028B04
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_inst_addr                                  "0x0041"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_30_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_30_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_30_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_30_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_lut_rd_data_d2_15_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_lut_rd_data_d2_15_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_lut_rd_data_d2_15(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_30_get_lut_rd_data_d2_15(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_31                                            0x18028B08
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_reg_addr                                   "0xB8028B08"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_reg                                        0xB8028B08
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_inst_addr                                  "0x0042"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_31_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_31_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_31_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_31_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_lut_rd_data_d0_16_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_lut_rd_data_d1_16_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_lut_rd_data_d0_16_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_lut_rd_data_d1_16_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_lut_rd_data_d0_16(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_lut_rd_data_d1_16(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_get_lut_rd_data_d0_16(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_31_get_lut_rd_data_d1_16(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_32                                            0x18028B0C
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_reg_addr                                   "0xB8028B0C"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_reg                                        0xB8028B0C
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_inst_addr                                  "0x0043"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_32_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_32_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_32_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_32_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_lut_rd_data_d2_16_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_lut_rd_data_d2_16_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_lut_rd_data_d2_16(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_32_get_lut_rd_data_d2_16(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_33                                            0x18028B10
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_reg_addr                                   "0xB8028B10"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_reg                                        0xB8028B10
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_inst_addr                                  "0x0044"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_33_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_33_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_33_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_33_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_lut_rd_data_d0_17_shift                    (16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_lut_rd_data_d1_17_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_lut_rd_data_d0_17_mask                     (0xFFFF0000)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_lut_rd_data_d1_17_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_lut_rd_data_d0_17(data)                    (0xFFFF0000&((data)<<16))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_lut_rd_data_d1_17(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_get_lut_rd_data_d0_17(data)                ((0xFFFF0000&(data))>>16)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_33_get_lut_rd_data_d1_17(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_RD_DATA_34                                            0x18028B14
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_reg_addr                                   "0xB8028B14"
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_reg                                        0xB8028B14
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_inst_addr                                  "0x0045"
#define  set_C3DLUT_C3DLUT_LUT_RD_DATA_34_reg(data)                              (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_34_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_RD_DATA_34_reg                                    (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_RD_DATA_34_reg))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_lut_rd_data_d2_17_shift                    (0)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_lut_rd_data_d2_17_mask                     (0x0000FFFF)
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_lut_rd_data_d2_17(data)                    (0x0000FFFF&(data))
#define  C3DLUT_C3DLUT_LUT_RD_DATA_34_get_lut_rd_data_d2_17(data)                (0x0000FFFF&(data))

#define  C3DLUT_C3DLUT_LUT_MBIST                                                 0x18028B18
#define  C3DLUT_C3DLUT_LUT_MBIST_reg_addr                                        "0xB8028B18"
#define  C3DLUT_C3DLUT_LUT_MBIST_reg                                             0xB8028B18
#define  C3DLUT_C3DLUT_LUT_MBIST_inst_addr                                       "0x0046"
#define  set_C3DLUT_C3DLUT_LUT_MBIST_reg(data)                                   (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_MBIST_reg)=data)
#define  get_C3DLUT_C3DLUT_LUT_MBIST_reg                                         (*((volatile unsigned int*)C3DLUT_C3DLUT_LUT_MBIST_reg))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_ls_shift                               (31)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_rme_shift                              (30)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_rm_shift                               (26)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_7_shift                      (15)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_6_shift                      (14)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_5_shift                      (13)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_4_shift                      (12)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_3_shift                      (11)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_2_shift                      (10)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_1_shift                      (9)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_0_shift                      (8)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_7_shift                  (7)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_6_shift                  (6)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_5_shift                  (5)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_4_shift                  (4)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_3_shift                  (3)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_2_shift                  (2)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_1_shift                  (1)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_0_shift                  (0)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_ls_mask                                (0x80000000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_rme_mask                               (0x40000000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_rm_mask                                (0x3C000000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_7_mask                       (0x00008000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_6_mask                       (0x00004000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_5_mask                       (0x00002000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_4_mask                       (0x00001000)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_3_mask                       (0x00000800)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_2_mask                       (0x00000400)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_1_mask                       (0x00000200)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_0_mask                       (0x00000100)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_7_mask                   (0x00000080)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_6_mask                   (0x00000040)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_5_mask                   (0x00000020)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_4_mask                   (0x00000010)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_3_mask                   (0x00000008)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_2_mask                   (0x00000004)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_1_mask                   (0x00000002)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_0_mask                   (0x00000001)
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_ls(data)                               (0x80000000&((data)<<31))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_rme(data)                              (0x40000000&((data)<<30))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_rm(data)                               (0x3C000000&((data)<<26))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_7(data)                      (0x00008000&((data)<<15))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_6(data)                      (0x00004000&((data)<<14))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_5(data)                      (0x00002000&((data)<<13))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_4(data)                      (0x00001000&((data)<<12))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_3(data)                      (0x00000800&((data)<<11))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_2(data)                      (0x00000400&((data)<<10))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_1(data)                      (0x00000200&((data)<<9))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_bist_fail_0(data)                      (0x00000100&((data)<<8))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_7(data)                  (0x00000080&((data)<<7))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_6(data)                  (0x00000040&((data)<<6))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_5(data)                  (0x00000020&((data)<<5))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_4(data)                  (0x00000010&((data)<<4))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_3(data)                  (0x00000008&((data)<<3))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_2(data)                  (0x00000004&((data)<<2))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_1(data)                  (0x00000002&((data)<<1))
#define  C3DLUT_C3DLUT_LUT_MBIST_d_3d_lut_drf_bist_fail_0(data)                  (0x00000001&(data))
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_ls(data)                           ((0x80000000&(data))>>31)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_rme(data)                          ((0x40000000&(data))>>30)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_rm(data)                           ((0x3C000000&(data))>>26)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_7(data)                  ((0x00008000&(data))>>15)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_6(data)                  ((0x00004000&(data))>>14)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_5(data)                  ((0x00002000&(data))>>13)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_4(data)                  ((0x00001000&(data))>>12)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_3(data)                  ((0x00000800&(data))>>11)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_2(data)                  ((0x00000400&(data))>>10)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_1(data)                  ((0x00000200&(data))>>9)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_bist_fail_0(data)                  ((0x00000100&(data))>>8)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_7(data)              ((0x00000080&(data))>>7)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_6(data)              ((0x00000040&(data))>>6)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_5(data)              ((0x00000020&(data))>>5)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_4(data)              ((0x00000010&(data))>>4)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_3(data)              ((0x00000008&(data))>>3)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_2(data)              ((0x00000004&(data))>>2)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_1(data)              ((0x00000002&(data))>>1)
#define  C3DLUT_C3DLUT_LUT_MBIST_get_d_3d_lut_drf_bist_fail_0(data)              (0x00000001&(data))

#define  C3DLUT_C3DLUT_dummy1                                                    0x18028B1C
#define  C3DLUT_C3DLUT_dummy1_reg_addr                                           "0xB8028B1C"
#define  C3DLUT_C3DLUT_dummy1_reg                                                0xB8028B1C
#define  C3DLUT_C3DLUT_dummy1_inst_addr                                          "0x0047"
#define  set_C3DLUT_C3DLUT_dummy1_reg(data)                                      (*((volatile unsigned int*)C3DLUT_C3DLUT_dummy1_reg)=data)
#define  get_C3DLUT_C3DLUT_dummy1_reg                                            (*((volatile unsigned int*)C3DLUT_C3DLUT_dummy1_reg))
#define  C3DLUT_C3DLUT_dummy1_dummy1_shift                                       (0)
#define  C3DLUT_C3DLUT_dummy1_dummy1_mask                                        (0xFFFFFFFF)
#define  C3DLUT_C3DLUT_dummy1_dummy1(data)                                       (0xFFFFFFFF&(data))
#define  C3DLUT_C3DLUT_dummy1_get_dummy1(data)                                   (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======C3DLUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  c3dlut_ctrl:2;
    };
}c3dlut_c3dlut_lut_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lut_rw_sel:2;
        RBus_UInt32  lut_write_en:1;
        RBus_UInt32  lut_read_en:1;
        RBus_UInt32  res2:17;
        RBus_UInt32  lut_rw_adr:10;
    };
}c3dlut_c3dlut_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_1:16;
        RBus_UInt32  lut_wr_data_d1_1:16;
    };
}c3dlut_c3dlut_lut_wr_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_1:16;
    };
}c3dlut_c3dlut_lut_wr_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_2:16;
        RBus_UInt32  lut_wr_data_d1_2:16;
    };
}c3dlut_c3dlut_lut_wr_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_2:16;
    };
}c3dlut_c3dlut_lut_wr_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_3:16;
        RBus_UInt32  lut_wr_data_d1_3:16;
    };
}c3dlut_c3dlut_lut_wr_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_3:16;
    };
}c3dlut_c3dlut_lut_wr_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_4:16;
        RBus_UInt32  lut_wr_data_d1_4:16;
    };
}c3dlut_c3dlut_lut_wr_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_4:16;
    };
}c3dlut_c3dlut_lut_wr_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_5:16;
        RBus_UInt32  lut_wr_data_d1_5:16;
    };
}c3dlut_c3dlut_lut_wr_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_5:16;
    };
}c3dlut_c3dlut_lut_wr_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_6:16;
        RBus_UInt32  lut_wr_data_d1_6:16;
    };
}c3dlut_c3dlut_lut_wr_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_6:16;
    };
}c3dlut_c3dlut_lut_wr_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_7:16;
        RBus_UInt32  lut_wr_data_d1_7:16;
    };
}c3dlut_c3dlut_lut_wr_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_7:16;
    };
}c3dlut_c3dlut_lut_wr_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_8:16;
        RBus_UInt32  lut_wr_data_d1_8:16;
    };
}c3dlut_c3dlut_lut_wr_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_8:16;
    };
}c3dlut_c3dlut_lut_wr_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_9:16;
        RBus_UInt32  lut_wr_data_d1_9:16;
    };
}c3dlut_c3dlut_lut_wr_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_9:16;
    };
}c3dlut_c3dlut_lut_wr_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_10:16;
        RBus_UInt32  lut_wr_data_d1_10:16;
    };
}c3dlut_c3dlut_lut_wr_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_10:16;
    };
}c3dlut_c3dlut_lut_wr_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_11:16;
        RBus_UInt32  lut_wr_data_d1_11:16;
    };
}c3dlut_c3dlut_lut_wr_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_11:16;
    };
}c3dlut_c3dlut_lut_wr_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_12:16;
        RBus_UInt32  lut_wr_data_d1_12:16;
    };
}c3dlut_c3dlut_lut_wr_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_12:16;
    };
}c3dlut_c3dlut_lut_wr_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_13:16;
        RBus_UInt32  lut_wr_data_d1_13:16;
    };
}c3dlut_c3dlut_lut_wr_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_13:16;
    };
}c3dlut_c3dlut_lut_wr_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_14:16;
        RBus_UInt32  lut_wr_data_d1_14:16;
    };
}c3dlut_c3dlut_lut_wr_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_14:16;
    };
}c3dlut_c3dlut_lut_wr_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_15:16;
        RBus_UInt32  lut_wr_data_d1_15:16;
    };
}c3dlut_c3dlut_lut_wr_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_15:16;
    };
}c3dlut_c3dlut_lut_wr_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_16:16;
        RBus_UInt32  lut_wr_data_d1_16:16;
    };
}c3dlut_c3dlut_lut_wr_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_16:16;
    };
}c3dlut_c3dlut_lut_wr_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d0_17:16;
        RBus_UInt32  lut_wr_data_d1_17:16;
    };
}c3dlut_c3dlut_lut_wr_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_wr_data_d2_17:16;
    };
}c3dlut_c3dlut_lut_wr_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_1:16;
        RBus_UInt32  lut_rd_data_d1_1:16;
    };
}c3dlut_c3dlut_lut_rd_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_1:16;
    };
}c3dlut_c3dlut_lut_rd_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_2:16;
        RBus_UInt32  lut_rd_data_d1_2:16;
    };
}c3dlut_c3dlut_lut_rd_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_2:16;
    };
}c3dlut_c3dlut_lut_rd_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_3:16;
        RBus_UInt32  lut_rd_data_d1_3:16;
    };
}c3dlut_c3dlut_lut_rd_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_3:16;
    };
}c3dlut_c3dlut_lut_rd_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_4:16;
        RBus_UInt32  lut_rd_data_d1_4:16;
    };
}c3dlut_c3dlut_lut_rd_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_4:16;
    };
}c3dlut_c3dlut_lut_rd_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_5:16;
        RBus_UInt32  lut_rd_data_d1_5:16;
    };
}c3dlut_c3dlut_lut_rd_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_5:16;
    };
}c3dlut_c3dlut_lut_rd_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_6:16;
        RBus_UInt32  lut_rd_data_d1_6:16;
    };
}c3dlut_c3dlut_lut_rd_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_6:16;
    };
}c3dlut_c3dlut_lut_rd_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_7:16;
        RBus_UInt32  lut_rd_data_d1_7:16;
    };
}c3dlut_c3dlut_lut_rd_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_7:16;
    };
}c3dlut_c3dlut_lut_rd_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_8:16;
        RBus_UInt32  lut_rd_data_d1_8:16;
    };
}c3dlut_c3dlut_lut_rd_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_8:16;
    };
}c3dlut_c3dlut_lut_rd_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_9:16;
        RBus_UInt32  lut_rd_data_d1_9:16;
    };
}c3dlut_c3dlut_lut_rd_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_9:16;
    };
}c3dlut_c3dlut_lut_rd_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_10:16;
        RBus_UInt32  lut_rd_data_d1_10:16;
    };
}c3dlut_c3dlut_lut_rd_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_10:16;
    };
}c3dlut_c3dlut_lut_rd_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_11:16;
        RBus_UInt32  lut_rd_data_d1_11:16;
    };
}c3dlut_c3dlut_lut_rd_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_11:16;
    };
}c3dlut_c3dlut_lut_rd_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_12:16;
        RBus_UInt32  lut_rd_data_d1_12:16;
    };
}c3dlut_c3dlut_lut_rd_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_12:16;
    };
}c3dlut_c3dlut_lut_rd_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_13:16;
        RBus_UInt32  lut_rd_data_d1_13:16;
    };
}c3dlut_c3dlut_lut_rd_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_13:16;
    };
}c3dlut_c3dlut_lut_rd_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_14:16;
        RBus_UInt32  lut_rd_data_d1_14:16;
    };
}c3dlut_c3dlut_lut_rd_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_14:16;
    };
}c3dlut_c3dlut_lut_rd_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_15:16;
        RBus_UInt32  lut_rd_data_d1_15:16;
    };
}c3dlut_c3dlut_lut_rd_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_15:16;
    };
}c3dlut_c3dlut_lut_rd_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_16:16;
        RBus_UInt32  lut_rd_data_d1_16:16;
    };
}c3dlut_c3dlut_lut_rd_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_16:16;
    };
}c3dlut_c3dlut_lut_rd_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d0_17:16;
        RBus_UInt32  lut_rd_data_d1_17:16;
    };
}c3dlut_c3dlut_lut_rd_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lut_rd_data_d2_17:16;
    };
}c3dlut_c3dlut_lut_rd_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_3d_lut_ls:1;
        RBus_UInt32  d_3d_lut_rme:1;
        RBus_UInt32  d_3d_lut_rm:4;
        RBus_UInt32  res1:10;
        RBus_UInt32  d_3d_lut_bist_fail_7:1;
        RBus_UInt32  d_3d_lut_bist_fail_6:1;
        RBus_UInt32  d_3d_lut_bist_fail_5:1;
        RBus_UInt32  d_3d_lut_bist_fail_4:1;
        RBus_UInt32  d_3d_lut_bist_fail_3:1;
        RBus_UInt32  d_3d_lut_bist_fail_2:1;
        RBus_UInt32  d_3d_lut_bist_fail_1:1;
        RBus_UInt32  d_3d_lut_bist_fail_0:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_7:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_6:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_5:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_4:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_3:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_2:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_1:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_0:1;
    };
}c3dlut_c3dlut_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}c3dlut_c3dlut_dummy1_RBUS;

#else //apply LITTLE_ENDIAN

//======C3DLUT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c3dlut_ctrl:2;
        RBus_UInt32  res1:30;
    };
}c3dlut_c3dlut_lut_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rw_adr:10;
        RBus_UInt32  res1:17;
        RBus_UInt32  lut_read_en:1;
        RBus_UInt32  lut_write_en:1;
        RBus_UInt32  lut_rw_sel:2;
        RBus_UInt32  res2:1;
    };
}c3dlut_c3dlut_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_1:16;
        RBus_UInt32  lut_wr_data_d0_1:16;
    };
}c3dlut_c3dlut_lut_wr_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_1:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_2:16;
        RBus_UInt32  lut_wr_data_d0_2:16;
    };
}c3dlut_c3dlut_lut_wr_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_2:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_3:16;
        RBus_UInt32  lut_wr_data_d0_3:16;
    };
}c3dlut_c3dlut_lut_wr_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_3:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_4:16;
        RBus_UInt32  lut_wr_data_d0_4:16;
    };
}c3dlut_c3dlut_lut_wr_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_4:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_5:16;
        RBus_UInt32  lut_wr_data_d0_5:16;
    };
}c3dlut_c3dlut_lut_wr_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_5:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_6:16;
        RBus_UInt32  lut_wr_data_d0_6:16;
    };
}c3dlut_c3dlut_lut_wr_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_6:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_7:16;
        RBus_UInt32  lut_wr_data_d0_7:16;
    };
}c3dlut_c3dlut_lut_wr_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_7:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_8:16;
        RBus_UInt32  lut_wr_data_d0_8:16;
    };
}c3dlut_c3dlut_lut_wr_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_8:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_9:16;
        RBus_UInt32  lut_wr_data_d0_9:16;
    };
}c3dlut_c3dlut_lut_wr_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_9:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_10:16;
        RBus_UInt32  lut_wr_data_d0_10:16;
    };
}c3dlut_c3dlut_lut_wr_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_10:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_11:16;
        RBus_UInt32  lut_wr_data_d0_11:16;
    };
}c3dlut_c3dlut_lut_wr_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_11:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_12:16;
        RBus_UInt32  lut_wr_data_d0_12:16;
    };
}c3dlut_c3dlut_lut_wr_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_12:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_13:16;
        RBus_UInt32  lut_wr_data_d0_13:16;
    };
}c3dlut_c3dlut_lut_wr_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_13:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_14:16;
        RBus_UInt32  lut_wr_data_d0_14:16;
    };
}c3dlut_c3dlut_lut_wr_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_14:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_15:16;
        RBus_UInt32  lut_wr_data_d0_15:16;
    };
}c3dlut_c3dlut_lut_wr_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_15:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_16:16;
        RBus_UInt32  lut_wr_data_d0_16:16;
    };
}c3dlut_c3dlut_lut_wr_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_16:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d1_17:16;
        RBus_UInt32  lut_wr_data_d0_17:16;
    };
}c3dlut_c3dlut_lut_wr_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_wr_data_d2_17:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_wr_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_1:16;
        RBus_UInt32  lut_rd_data_d0_1:16;
    };
}c3dlut_c3dlut_lut_rd_data_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_1:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_2:16;
        RBus_UInt32  lut_rd_data_d0_2:16;
    };
}c3dlut_c3dlut_lut_rd_data_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_2:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_3:16;
        RBus_UInt32  lut_rd_data_d0_3:16;
    };
}c3dlut_c3dlut_lut_rd_data_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_3:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_4:16;
        RBus_UInt32  lut_rd_data_d0_4:16;
    };
}c3dlut_c3dlut_lut_rd_data_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_4:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_5:16;
        RBus_UInt32  lut_rd_data_d0_5:16;
    };
}c3dlut_c3dlut_lut_rd_data_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_5:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_6:16;
        RBus_UInt32  lut_rd_data_d0_6:16;
    };
}c3dlut_c3dlut_lut_rd_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_6:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_7:16;
        RBus_UInt32  lut_rd_data_d0_7:16;
    };
}c3dlut_c3dlut_lut_rd_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_7:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_8:16;
        RBus_UInt32  lut_rd_data_d0_8:16;
    };
}c3dlut_c3dlut_lut_rd_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_8:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_9:16;
        RBus_UInt32  lut_rd_data_d0_9:16;
    };
}c3dlut_c3dlut_lut_rd_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_9:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_10:16;
        RBus_UInt32  lut_rd_data_d0_10:16;
    };
}c3dlut_c3dlut_lut_rd_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_10:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_11:16;
        RBus_UInt32  lut_rd_data_d0_11:16;
    };
}c3dlut_c3dlut_lut_rd_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_11:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_12:16;
        RBus_UInt32  lut_rd_data_d0_12:16;
    };
}c3dlut_c3dlut_lut_rd_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_12:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_13:16;
        RBus_UInt32  lut_rd_data_d0_13:16;
    };
}c3dlut_c3dlut_lut_rd_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_13:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_14:16;
        RBus_UInt32  lut_rd_data_d0_14:16;
    };
}c3dlut_c3dlut_lut_rd_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_14:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_15:16;
        RBus_UInt32  lut_rd_data_d0_15:16;
    };
}c3dlut_c3dlut_lut_rd_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_15:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_16:16;
        RBus_UInt32  lut_rd_data_d0_16:16;
    };
}c3dlut_c3dlut_lut_rd_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_16:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d1_17:16;
        RBus_UInt32  lut_rd_data_d0_17:16;
    };
}c3dlut_c3dlut_lut_rd_data_33_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut_rd_data_d2_17:16;
        RBus_UInt32  res1:16;
    };
}c3dlut_c3dlut_lut_rd_data_34_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_3d_lut_drf_bist_fail_0:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_1:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_2:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_3:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_4:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_5:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_6:1;
        RBus_UInt32  d_3d_lut_drf_bist_fail_7:1;
        RBus_UInt32  d_3d_lut_bist_fail_0:1;
        RBus_UInt32  d_3d_lut_bist_fail_1:1;
        RBus_UInt32  d_3d_lut_bist_fail_2:1;
        RBus_UInt32  d_3d_lut_bist_fail_3:1;
        RBus_UInt32  d_3d_lut_bist_fail_4:1;
        RBus_UInt32  d_3d_lut_bist_fail_5:1;
        RBus_UInt32  d_3d_lut_bist_fail_6:1;
        RBus_UInt32  d_3d_lut_bist_fail_7:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  d_3d_lut_rm:4;
        RBus_UInt32  d_3d_lut_rme:1;
        RBus_UInt32  d_3d_lut_ls:1;
    };
}c3dlut_c3dlut_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1:32;
    };
}c3dlut_c3dlut_dummy1_RBUS;




#endif 


#endif 
