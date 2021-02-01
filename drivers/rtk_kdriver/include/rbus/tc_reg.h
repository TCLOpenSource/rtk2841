/**
* @file Mac5_DesignSpec_HDR_TC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TC_REG_H_
#define _RBUS_TC_REG_H_

#include "rbus_types.h"



//  TC Register Address
#define  TC_TChdr_enable                                                         0x1806BB00
#define  TC_TChdr_enable_reg_addr                                                "0xB806BB00"
#define  TC_TChdr_enable_reg                                                     0xB806BB00
#define  TC_TChdr_enable_inst_addr                                               "0x0000"
#define  set_TC_TChdr_enable_reg(data)                                           (*((volatile unsigned int*)TC_TChdr_enable_reg)=data)
#define  get_TC_TChdr_enable_reg                                                 (*((volatile unsigned int*)TC_TChdr_enable_reg))
#define  TC_TChdr_enable_tc_certification_bitout_shift                           (2)
#define  TC_TChdr_enable_certification_enable_shift                              (1)
#define  TC_TChdr_enable_tc_enable_shift                                         (0)
#define  TC_TChdr_enable_tc_certification_bitout_mask                            (0x00000004)
#define  TC_TChdr_enable_certification_enable_mask                               (0x00000002)
#define  TC_TChdr_enable_tc_enable_mask                                          (0x00000001)
#define  TC_TChdr_enable_tc_certification_bitout(data)                           (0x00000004&((data)<<2))
#define  TC_TChdr_enable_certification_enable(data)                              (0x00000002&((data)<<1))
#define  TC_TChdr_enable_tc_enable(data)                                         (0x00000001&(data))
#define  TC_TChdr_enable_get_tc_certification_bitout(data)                       ((0x00000004&(data))>>2)
#define  TC_TChdr_enable_get_certification_enable(data)                          ((0x00000002&(data))>>1)
#define  TC_TChdr_enable_get_tc_enable(data)                                     (0x00000001&(data))

#define  TC_TChdr_Range_Adaptation_Ctrl0                                         0x1806BB04
#define  TC_TChdr_Range_Adaptation_Ctrl0_reg_addr                                "0xB806BB04"
#define  TC_TChdr_Range_Adaptation_Ctrl0_reg                                     0xB806BB04
#define  TC_TChdr_Range_Adaptation_Ctrl0_inst_addr                               "0x0001"
#define  set_TC_TChdr_Range_Adaptation_Ctrl0_reg(data)                           (*((volatile unsigned int*)TC_TChdr_Range_Adaptation_Ctrl0_reg)=data)
#define  get_TC_TChdr_Range_Adaptation_Ctrl0_reg                                 (*((volatile unsigned int*)TC_TChdr_Range_Adaptation_Ctrl0_reg))
#define  TC_TChdr_Range_Adaptation_Ctrl0_footroom_int_shift                      (0)
#define  TC_TChdr_Range_Adaptation_Ctrl0_footroom_int_mask                       (0x000003FF)
#define  TC_TChdr_Range_Adaptation_Ctrl0_footroom_int(data)                      (0x000003FF&(data))
#define  TC_TChdr_Range_Adaptation_Ctrl0_get_footroom_int(data)                  (0x000003FF&(data))

#define  TC_TChdr_Range_Adaptation_Ctrl1                                         0x1806BB08
#define  TC_TChdr_Range_Adaptation_Ctrl1_reg_addr                                "0xB806BB08"
#define  TC_TChdr_Range_Adaptation_Ctrl1_reg                                     0xB806BB08
#define  TC_TChdr_Range_Adaptation_Ctrl1_inst_addr                               "0x0002"
#define  set_TC_TChdr_Range_Adaptation_Ctrl1_reg(data)                           (*((volatile unsigned int*)TC_TChdr_Range_Adaptation_Ctrl1_reg)=data)
#define  get_TC_TChdr_Range_Adaptation_Ctrl1_reg                                 (*((volatile unsigned int*)TC_TChdr_Range_Adaptation_Ctrl1_reg))
#define  TC_TChdr_Range_Adaptation_Ctrl1_c_headroom_int_shift                    (16)
#define  TC_TChdr_Range_Adaptation_Ctrl1_l_headroom_int_shift                    (0)
#define  TC_TChdr_Range_Adaptation_Ctrl1_c_headroom_int_mask                     (0x03FF0000)
#define  TC_TChdr_Range_Adaptation_Ctrl1_l_headroom_int_mask                     (0x000003FF)
#define  TC_TChdr_Range_Adaptation_Ctrl1_c_headroom_int(data)                    (0x03FF0000&((data)<<16))
#define  TC_TChdr_Range_Adaptation_Ctrl1_l_headroom_int(data)                    (0x000003FF&(data))
#define  TC_TChdr_Range_Adaptation_Ctrl1_get_c_headroom_int(data)                ((0x03FF0000&(data))>>16)
#define  TC_TChdr_Range_Adaptation_Ctrl1_get_l_headroom_int(data)                (0x000003FF&(data))

#define  TC_TChdr_Range_Adaptation_Ctrl2                                         0x1806BB0C
#define  TC_TChdr_Range_Adaptation_Ctrl2_reg_addr                                "0xB806BB0C"
#define  TC_TChdr_Range_Adaptation_Ctrl2_reg                                     0xB806BB0C
#define  TC_TChdr_Range_Adaptation_Ctrl2_inst_addr                               "0x0003"
#define  set_TC_TChdr_Range_Adaptation_Ctrl2_reg(data)                           (*((volatile unsigned int*)TC_TChdr_Range_Adaptation_Ctrl2_reg)=data)
#define  get_TC_TChdr_Range_Adaptation_Ctrl2_reg                                 (*((volatile unsigned int*)TC_TChdr_Range_Adaptation_Ctrl2_reg))
#define  TC_TChdr_Range_Adaptation_Ctrl2_inv_chroma_limited_range_ratio_int_shift (16)
#define  TC_TChdr_Range_Adaptation_Ctrl2_inv_y_limited_range_ratio_int_shift     (0)
#define  TC_TChdr_Range_Adaptation_Ctrl2_inv_chroma_limited_range_ratio_int_mask (0x07FF0000)
#define  TC_TChdr_Range_Adaptation_Ctrl2_inv_y_limited_range_ratio_int_mask      (0x000007FF)
#define  TC_TChdr_Range_Adaptation_Ctrl2_inv_chroma_limited_range_ratio_int(data) (0x07FF0000&((data)<<16))
#define  TC_TChdr_Range_Adaptation_Ctrl2_inv_y_limited_range_ratio_int(data)     (0x000007FF&(data))
#define  TC_TChdr_Range_Adaptation_Ctrl2_get_inv_chroma_limited_range_ratio_int(data) ((0x07FF0000&(data))>>16)
#define  TC_TChdr_Range_Adaptation_Ctrl2_get_inv_y_limited_range_ratio_int(data) (0x000007FF&(data))

#define  TC_TChdr_L_Compute                                                      0x1806BB10
#define  TC_TChdr_L_Compute_reg_addr                                             "0xB806BB10"
#define  TC_TChdr_L_Compute_reg                                                  0xB806BB10
#define  TC_TChdr_L_Compute_inst_addr                                            "0x0004"
#define  set_TC_TChdr_L_Compute_reg(data)                                        (*((volatile unsigned int*)TC_TChdr_L_Compute_reg)=data)
#define  get_TC_TChdr_L_Compute_reg                                              (*((volatile unsigned int*)TC_TChdr_L_Compute_reg))
#define  TC_TChdr_L_Compute_alpha_b_shift                                        (16)
#define  TC_TChdr_L_Compute_alpha_a_shift                                        (0)
#define  TC_TChdr_L_Compute_alpha_b_mask                                         (0x1FFF0000)
#define  TC_TChdr_L_Compute_alpha_a_mask                                         (0x00001FFF)
#define  TC_TChdr_L_Compute_alpha_b(data)                                        (0x1FFF0000&((data)<<16))
#define  TC_TChdr_L_Compute_alpha_a(data)                                        (0x00001FFF&(data))
#define  TC_TChdr_L_Compute_get_alpha_b(data)                                    ((0x1FFF0000&(data))>>16)
#define  TC_TChdr_L_Compute_get_alpha_a(data)                                    (0x00001FFF&(data))

#define  TC_TChdr_C_LUT_CTRL0                                                    0x1806BB14
#define  TC_TChdr_C_LUT_CTRL0_reg_addr                                           "0xB806BB14"
#define  TC_TChdr_C_LUT_CTRL0_reg                                                0xB806BB14
#define  TC_TChdr_C_LUT_CTRL0_inst_addr                                          "0x0005"
#define  set_TC_TChdr_C_LUT_CTRL0_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_C_LUT_CTRL0_reg)=data)
#define  get_TC_TChdr_C_LUT_CTRL0_reg                                            (*((volatile unsigned int*)TC_TChdr_C_LUT_CTRL0_reg))
#define  TC_TChdr_C_LUT_CTRL0_c_lut_rw_sel_shift                                 (0)
#define  TC_TChdr_C_LUT_CTRL0_c_lut_rw_sel_mask                                  (0x00000003)
#define  TC_TChdr_C_LUT_CTRL0_c_lut_rw_sel(data)                                 (0x00000003&(data))
#define  TC_TChdr_C_LUT_CTRL0_get_c_lut_rw_sel(data)                             (0x00000003&(data))

#define  TC_TChdr_C_LUT_CTRL1                                                    0x1806BB18
#define  TC_TChdr_C_LUT_CTRL1_reg_addr                                           "0xB806BB18"
#define  TC_TChdr_C_LUT_CTRL1_reg                                                0xB806BB18
#define  TC_TChdr_C_LUT_CTRL1_inst_addr                                          "0x0006"
#define  set_TC_TChdr_C_LUT_CTRL1_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_C_LUT_CTRL1_reg)=data)
#define  get_TC_TChdr_C_LUT_CTRL1_reg                                            (*((volatile unsigned int*)TC_TChdr_C_LUT_CTRL1_reg))
#define  TC_TChdr_C_LUT_CTRL1_c_lut_write_en_shift                               (7)
#define  TC_TChdr_C_LUT_CTRL1_c_lut_read_en_shift                                (6)
#define  TC_TChdr_C_LUT_CTRL1_c_lut_rw_addr_shift                                (0)
#define  TC_TChdr_C_LUT_CTRL1_c_lut_write_en_mask                                (0x00000080)
#define  TC_TChdr_C_LUT_CTRL1_c_lut_read_en_mask                                 (0x00000040)
#define  TC_TChdr_C_LUT_CTRL1_c_lut_rw_addr_mask                                 (0x0000003F)
#define  TC_TChdr_C_LUT_CTRL1_c_lut_write_en(data)                               (0x00000080&((data)<<7))
#define  TC_TChdr_C_LUT_CTRL1_c_lut_read_en(data)                                (0x00000040&((data)<<6))
#define  TC_TChdr_C_LUT_CTRL1_c_lut_rw_addr(data)                                (0x0000003F&(data))
#define  TC_TChdr_C_LUT_CTRL1_get_c_lut_write_en(data)                           ((0x00000080&(data))>>7)
#define  TC_TChdr_C_LUT_CTRL1_get_c_lut_read_en(data)                            ((0x00000040&(data))>>6)
#define  TC_TChdr_C_LUT_CTRL1_get_c_lut_rw_addr(data)                            (0x0000003F&(data))

#define  TC_TChdr_C_LUT_WR_DATA                                                  0x1806BB1C
#define  TC_TChdr_C_LUT_WR_DATA_reg_addr                                         "0xB806BB1C"
#define  TC_TChdr_C_LUT_WR_DATA_reg                                              0xB806BB1C
#define  TC_TChdr_C_LUT_WR_DATA_inst_addr                                        "0x0007"
#define  set_TC_TChdr_C_LUT_WR_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_C_LUT_WR_DATA_reg)=data)
#define  get_TC_TChdr_C_LUT_WR_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_C_LUT_WR_DATA_reg))
#define  TC_TChdr_C_LUT_WR_DATA_c_wr_lut_data0_shift                             (16)
#define  TC_TChdr_C_LUT_WR_DATA_c_wr_lut_data1_shift                             (0)
#define  TC_TChdr_C_LUT_WR_DATA_c_wr_lut_data0_mask                              (0x07FF0000)
#define  TC_TChdr_C_LUT_WR_DATA_c_wr_lut_data1_mask                              (0x000007FF)
#define  TC_TChdr_C_LUT_WR_DATA_c_wr_lut_data0(data)                             (0x07FF0000&((data)<<16))
#define  TC_TChdr_C_LUT_WR_DATA_c_wr_lut_data1(data)                             (0x000007FF&(data))
#define  TC_TChdr_C_LUT_WR_DATA_get_c_wr_lut_data0(data)                         ((0x07FF0000&(data))>>16)
#define  TC_TChdr_C_LUT_WR_DATA_get_c_wr_lut_data1(data)                         (0x000007FF&(data))

#define  TC_TChdr_C_LUT_RD_DATA                                                  0x1806BB20
#define  TC_TChdr_C_LUT_RD_DATA_reg_addr                                         "0xB806BB20"
#define  TC_TChdr_C_LUT_RD_DATA_reg                                              0xB806BB20
#define  TC_TChdr_C_LUT_RD_DATA_inst_addr                                        "0x0008"
#define  set_TC_TChdr_C_LUT_RD_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_C_LUT_RD_DATA_reg)=data)
#define  get_TC_TChdr_C_LUT_RD_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_C_LUT_RD_DATA_reg))
#define  TC_TChdr_C_LUT_RD_DATA_c_rd_lut_data0_shift                             (16)
#define  TC_TChdr_C_LUT_RD_DATA_c_rd_lut_data1_shift                             (0)
#define  TC_TChdr_C_LUT_RD_DATA_c_rd_lut_data0_mask                              (0x07FF0000)
#define  TC_TChdr_C_LUT_RD_DATA_c_rd_lut_data1_mask                              (0x000007FF)
#define  TC_TChdr_C_LUT_RD_DATA_c_rd_lut_data0(data)                             (0x07FF0000&((data)<<16))
#define  TC_TChdr_C_LUT_RD_DATA_c_rd_lut_data1(data)                             (0x000007FF&(data))
#define  TC_TChdr_C_LUT_RD_DATA_get_c_rd_lut_data0(data)                         ((0x07FF0000&(data))>>16)
#define  TC_TChdr_C_LUT_RD_DATA_get_c_rd_lut_data1(data)                         (0x000007FF&(data))

#define  TC_TChdr_S_LUT_CTRL0                                                    0x1806BB24
#define  TC_TChdr_S_LUT_CTRL0_reg_addr                                           "0xB806BB24"
#define  TC_TChdr_S_LUT_CTRL0_reg                                                0xB806BB24
#define  TC_TChdr_S_LUT_CTRL0_inst_addr                                          "0x0009"
#define  set_TC_TChdr_S_LUT_CTRL0_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_S_LUT_CTRL0_reg)=data)
#define  get_TC_TChdr_S_LUT_CTRL0_reg                                            (*((volatile unsigned int*)TC_TChdr_S_LUT_CTRL0_reg))
#define  TC_TChdr_S_LUT_CTRL0_s_lut_rw_sel_shift                                 (0)
#define  TC_TChdr_S_LUT_CTRL0_s_lut_rw_sel_mask                                  (0x00000003)
#define  TC_TChdr_S_LUT_CTRL0_s_lut_rw_sel(data)                                 (0x00000003&(data))
#define  TC_TChdr_S_LUT_CTRL0_get_s_lut_rw_sel(data)                             (0x00000003&(data))

#define  TC_TChdr_S_LUT_CTRL1                                                    0x1806BB28
#define  TC_TChdr_S_LUT_CTRL1_reg_addr                                           "0xB806BB28"
#define  TC_TChdr_S_LUT_CTRL1_reg                                                0xB806BB28
#define  TC_TChdr_S_LUT_CTRL1_inst_addr                                          "0x000A"
#define  set_TC_TChdr_S_LUT_CTRL1_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_S_LUT_CTRL1_reg)=data)
#define  get_TC_TChdr_S_LUT_CTRL1_reg                                            (*((volatile unsigned int*)TC_TChdr_S_LUT_CTRL1_reg))
#define  TC_TChdr_S_LUT_CTRL1_s_lut_write_en_shift                               (7)
#define  TC_TChdr_S_LUT_CTRL1_s_lut_read_en_shift                                (6)
#define  TC_TChdr_S_LUT_CTRL1_s_lut_rw_addr_shift                                (0)
#define  TC_TChdr_S_LUT_CTRL1_s_lut_write_en_mask                                (0x00000080)
#define  TC_TChdr_S_LUT_CTRL1_s_lut_read_en_mask                                 (0x00000040)
#define  TC_TChdr_S_LUT_CTRL1_s_lut_rw_addr_mask                                 (0x0000003F)
#define  TC_TChdr_S_LUT_CTRL1_s_lut_write_en(data)                               (0x00000080&((data)<<7))
#define  TC_TChdr_S_LUT_CTRL1_s_lut_read_en(data)                                (0x00000040&((data)<<6))
#define  TC_TChdr_S_LUT_CTRL1_s_lut_rw_addr(data)                                (0x0000003F&(data))
#define  TC_TChdr_S_LUT_CTRL1_get_s_lut_write_en(data)                           ((0x00000080&(data))>>7)
#define  TC_TChdr_S_LUT_CTRL1_get_s_lut_read_en(data)                            ((0x00000040&(data))>>6)
#define  TC_TChdr_S_LUT_CTRL1_get_s_lut_rw_addr(data)                            (0x0000003F&(data))

#define  TC_TChdr_S_LUT_WR_DATA                                                  0x1806BB2C
#define  TC_TChdr_S_LUT_WR_DATA_reg_addr                                         "0xB806BB2C"
#define  TC_TChdr_S_LUT_WR_DATA_reg                                              0xB806BB2C
#define  TC_TChdr_S_LUT_WR_DATA_inst_addr                                        "0x000B"
#define  set_TC_TChdr_S_LUT_WR_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_S_LUT_WR_DATA_reg)=data)
#define  get_TC_TChdr_S_LUT_WR_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_S_LUT_WR_DATA_reg))
#define  TC_TChdr_S_LUT_WR_DATA_s_wr_lut_data0_shift                             (16)
#define  TC_TChdr_S_LUT_WR_DATA_s_wr_lut_data1_shift                             (0)
#define  TC_TChdr_S_LUT_WR_DATA_s_wr_lut_data0_mask                              (0x03FF0000)
#define  TC_TChdr_S_LUT_WR_DATA_s_wr_lut_data1_mask                              (0x000003FF)
#define  TC_TChdr_S_LUT_WR_DATA_s_wr_lut_data0(data)                             (0x03FF0000&((data)<<16))
#define  TC_TChdr_S_LUT_WR_DATA_s_wr_lut_data1(data)                             (0x000003FF&(data))
#define  TC_TChdr_S_LUT_WR_DATA_get_s_wr_lut_data0(data)                         ((0x03FF0000&(data))>>16)
#define  TC_TChdr_S_LUT_WR_DATA_get_s_wr_lut_data1(data)                         (0x000003FF&(data))

#define  TC_TChdr_S_LUT_RD_DATA                                                  0x1806BB30
#define  TC_TChdr_S_LUT_RD_DATA_reg_addr                                         "0xB806BB30"
#define  TC_TChdr_S_LUT_RD_DATA_reg                                              0xB806BB30
#define  TC_TChdr_S_LUT_RD_DATA_inst_addr                                        "0x000C"
#define  set_TC_TChdr_S_LUT_RD_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_S_LUT_RD_DATA_reg)=data)
#define  get_TC_TChdr_S_LUT_RD_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_S_LUT_RD_DATA_reg))
#define  TC_TChdr_S_LUT_RD_DATA_s_rd_lut_data0_shift                             (16)
#define  TC_TChdr_S_LUT_RD_DATA_s_rd_lut_data1_shift                             (0)
#define  TC_TChdr_S_LUT_RD_DATA_s_rd_lut_data0_mask                              (0x03FF0000)
#define  TC_TChdr_S_LUT_RD_DATA_s_rd_lut_data1_mask                              (0x000003FF)
#define  TC_TChdr_S_LUT_RD_DATA_s_rd_lut_data0(data)                             (0x03FF0000&((data)<<16))
#define  TC_TChdr_S_LUT_RD_DATA_s_rd_lut_data1(data)                             (0x000003FF&(data))
#define  TC_TChdr_S_LUT_RD_DATA_get_s_rd_lut_data0(data)                         ((0x03FF0000&(data))>>16)
#define  TC_TChdr_S_LUT_RD_DATA_get_s_rd_lut_data1(data)                         (0x000003FF&(data))

#define  TC_TChdr_I_LUT_CTRL0                                                    0x1806BB34
#define  TC_TChdr_I_LUT_CTRL0_reg_addr                                           "0xB806BB34"
#define  TC_TChdr_I_LUT_CTRL0_reg                                                0xB806BB34
#define  TC_TChdr_I_LUT_CTRL0_inst_addr                                          "0x000D"
#define  set_TC_TChdr_I_LUT_CTRL0_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_I_LUT_CTRL0_reg)=data)
#define  get_TC_TChdr_I_LUT_CTRL0_reg                                            (*((volatile unsigned int*)TC_TChdr_I_LUT_CTRL0_reg))
#define  TC_TChdr_I_LUT_CTRL0_i_lut_rw_sel_shift                                 (0)
#define  TC_TChdr_I_LUT_CTRL0_i_lut_rw_sel_mask                                  (0x00000003)
#define  TC_TChdr_I_LUT_CTRL0_i_lut_rw_sel(data)                                 (0x00000003&(data))
#define  TC_TChdr_I_LUT_CTRL0_get_i_lut_rw_sel(data)                             (0x00000003&(data))

#define  TC_TChdr_I_LUT_CTRL1                                                    0x1806BB38
#define  TC_TChdr_I_LUT_CTRL1_reg_addr                                           "0xB806BB38"
#define  TC_TChdr_I_LUT_CTRL1_reg                                                0xB806BB38
#define  TC_TChdr_I_LUT_CTRL1_inst_addr                                          "0x000E"
#define  set_TC_TChdr_I_LUT_CTRL1_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_I_LUT_CTRL1_reg)=data)
#define  get_TC_TChdr_I_LUT_CTRL1_reg                                            (*((volatile unsigned int*)TC_TChdr_I_LUT_CTRL1_reg))
#define  TC_TChdr_I_LUT_CTRL1_i_lut_write_en_shift                               (7)
#define  TC_TChdr_I_LUT_CTRL1_i_lut_read_en_shift                                (6)
#define  TC_TChdr_I_LUT_CTRL1_i_lut_rw_addr_shift                                (0)
#define  TC_TChdr_I_LUT_CTRL1_i_lut_write_en_mask                                (0x00000080)
#define  TC_TChdr_I_LUT_CTRL1_i_lut_read_en_mask                                 (0x00000040)
#define  TC_TChdr_I_LUT_CTRL1_i_lut_rw_addr_mask                                 (0x0000003F)
#define  TC_TChdr_I_LUT_CTRL1_i_lut_write_en(data)                               (0x00000080&((data)<<7))
#define  TC_TChdr_I_LUT_CTRL1_i_lut_read_en(data)                                (0x00000040&((data)<<6))
#define  TC_TChdr_I_LUT_CTRL1_i_lut_rw_addr(data)                                (0x0000003F&(data))
#define  TC_TChdr_I_LUT_CTRL1_get_i_lut_write_en(data)                           ((0x00000080&(data))>>7)
#define  TC_TChdr_I_LUT_CTRL1_get_i_lut_read_en(data)                            ((0x00000040&(data))>>6)
#define  TC_TChdr_I_LUT_CTRL1_get_i_lut_rw_addr(data)                            (0x0000003F&(data))

#define  TC_TChdr_I_LUT_WR_DATA                                                  0x1806BB3C
#define  TC_TChdr_I_LUT_WR_DATA_reg_addr                                         "0xB806BB3C"
#define  TC_TChdr_I_LUT_WR_DATA_reg                                              0xB806BB3C
#define  TC_TChdr_I_LUT_WR_DATA_inst_addr                                        "0x000F"
#define  set_TC_TChdr_I_LUT_WR_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_I_LUT_WR_DATA_reg)=data)
#define  get_TC_TChdr_I_LUT_WR_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_I_LUT_WR_DATA_reg))
#define  TC_TChdr_I_LUT_WR_DATA_i_wr_lut_data0_shift                             (16)
#define  TC_TChdr_I_LUT_WR_DATA_i_wr_lut_data1_shift                             (0)
#define  TC_TChdr_I_LUT_WR_DATA_i_wr_lut_data0_mask                              (0x00FF0000)
#define  TC_TChdr_I_LUT_WR_DATA_i_wr_lut_data1_mask                              (0x000000FF)
#define  TC_TChdr_I_LUT_WR_DATA_i_wr_lut_data0(data)                             (0x00FF0000&((data)<<16))
#define  TC_TChdr_I_LUT_WR_DATA_i_wr_lut_data1(data)                             (0x000000FF&(data))
#define  TC_TChdr_I_LUT_WR_DATA_get_i_wr_lut_data0(data)                         ((0x00FF0000&(data))>>16)
#define  TC_TChdr_I_LUT_WR_DATA_get_i_wr_lut_data1(data)                         (0x000000FF&(data))

#define  TC_TChdr_I_LUT_RD_DATA                                                  0x1806BB40
#define  TC_TChdr_I_LUT_RD_DATA_reg_addr                                         "0xB806BB40"
#define  TC_TChdr_I_LUT_RD_DATA_reg                                              0xB806BB40
#define  TC_TChdr_I_LUT_RD_DATA_inst_addr                                        "0x0010"
#define  set_TC_TChdr_I_LUT_RD_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_I_LUT_RD_DATA_reg)=data)
#define  get_TC_TChdr_I_LUT_RD_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_I_LUT_RD_DATA_reg))
#define  TC_TChdr_I_LUT_RD_DATA_i_rd_lut_data0_shift                             (16)
#define  TC_TChdr_I_LUT_RD_DATA_i_rd_lut_data1_shift                             (0)
#define  TC_TChdr_I_LUT_RD_DATA_i_rd_lut_data0_mask                              (0x00FF0000)
#define  TC_TChdr_I_LUT_RD_DATA_i_rd_lut_data1_mask                              (0x000000FF)
#define  TC_TChdr_I_LUT_RD_DATA_i_rd_lut_data0(data)                             (0x00FF0000&((data)<<16))
#define  TC_TChdr_I_LUT_RD_DATA_i_rd_lut_data1(data)                             (0x000000FF&(data))
#define  TC_TChdr_I_LUT_RD_DATA_get_i_rd_lut_data0(data)                         ((0x00FF0000&(data))>>16)
#define  TC_TChdr_I_LUT_RD_DATA_get_i_rd_lut_data1(data)                         (0x000000FF&(data))

#define  TC_TChdr_P_LUT_CTRL0                                                    0x1806BB44
#define  TC_TChdr_P_LUT_CTRL0_reg_addr                                           "0xB806BB44"
#define  TC_TChdr_P_LUT_CTRL0_reg                                                0xB806BB44
#define  TC_TChdr_P_LUT_CTRL0_inst_addr                                          "0x0011"
#define  set_TC_TChdr_P_LUT_CTRL0_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL0_reg)=data)
#define  get_TC_TChdr_P_LUT_CTRL0_reg                                            (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL0_reg))
#define  TC_TChdr_P_LUT_CTRL0_p_lut_acc_sel_shift                                (2)
#define  TC_TChdr_P_LUT_CTRL0_p_lut_rw_sel_shift                                 (0)
#define  TC_TChdr_P_LUT_CTRL0_p_lut_acc_sel_mask                                 (0x00000004)
#define  TC_TChdr_P_LUT_CTRL0_p_lut_rw_sel_mask                                  (0x00000003)
#define  TC_TChdr_P_LUT_CTRL0_p_lut_acc_sel(data)                                (0x00000004&((data)<<2))
#define  TC_TChdr_P_LUT_CTRL0_p_lut_rw_sel(data)                                 (0x00000003&(data))
#define  TC_TChdr_P_LUT_CTRL0_get_p_lut_acc_sel(data)                            ((0x00000004&(data))>>2)
#define  TC_TChdr_P_LUT_CTRL0_get_p_lut_rw_sel(data)                             (0x00000003&(data))

#define  TC_TChdr_P_LUT_CTRL1                                                    0x1806BB48
#define  TC_TChdr_P_LUT_CTRL1_reg_addr                                           "0xB806BB48"
#define  TC_TChdr_P_LUT_CTRL1_reg                                                0xB806BB48
#define  TC_TChdr_P_LUT_CTRL1_inst_addr                                          "0x0012"
#define  set_TC_TChdr_P_LUT_CTRL1_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL1_reg)=data)
#define  get_TC_TChdr_P_LUT_CTRL1_reg                                            (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL1_reg))
#define  TC_TChdr_P_LUT_CTRL1_p_lut_write_en_shift                               (1)
#define  TC_TChdr_P_LUT_CTRL1_p_lut_read_en_shift                                (0)
#define  TC_TChdr_P_LUT_CTRL1_p_lut_write_en_mask                                (0x00000002)
#define  TC_TChdr_P_LUT_CTRL1_p_lut_read_en_mask                                 (0x00000001)
#define  TC_TChdr_P_LUT_CTRL1_p_lut_write_en(data)                               (0x00000002&((data)<<1))
#define  TC_TChdr_P_LUT_CTRL1_p_lut_read_en(data)                                (0x00000001&(data))
#define  TC_TChdr_P_LUT_CTRL1_get_p_lut_write_en(data)                           ((0x00000002&(data))>>1)
#define  TC_TChdr_P_LUT_CTRL1_get_p_lut_read_en(data)                            (0x00000001&(data))

#define  TC_TChdr_P_LUT_CTRL2                                                    0x1806BB4C
#define  TC_TChdr_P_LUT_CTRL2_reg_addr                                           "0xB806BB4C"
#define  TC_TChdr_P_LUT_CTRL2_reg                                                0xB806BB4C
#define  TC_TChdr_P_LUT_CTRL2_inst_addr                                          "0x0013"
#define  set_TC_TChdr_P_LUT_CTRL2_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL2_reg)=data)
#define  get_TC_TChdr_P_LUT_CTRL2_reg                                            (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL2_reg))
#define  TC_TChdr_P_LUT_CTRL2_p_lut_acc_ready_shift                              (31)
#define  TC_TChdr_P_LUT_CTRL2_p_lut_rw_addr_shift                                (0)
#define  TC_TChdr_P_LUT_CTRL2_p_lut_acc_ready_mask                               (0x80000000)
#define  TC_TChdr_P_LUT_CTRL2_p_lut_rw_addr_mask                                 (0x0000003F)
#define  TC_TChdr_P_LUT_CTRL2_p_lut_acc_ready(data)                              (0x80000000&((data)<<31))
#define  TC_TChdr_P_LUT_CTRL2_p_lut_rw_addr(data)                                (0x0000003F&(data))
#define  TC_TChdr_P_LUT_CTRL2_get_p_lut_acc_ready(data)                          ((0x80000000&(data))>>31)
#define  TC_TChdr_P_LUT_CTRL2_get_p_lut_rw_addr(data)                            (0x0000003F&(data))

#define  TC_TChdr_P_LUT_CTRL3                                                    0x1806BB50
#define  TC_TChdr_P_LUT_CTRL3_reg_addr                                           "0xB806BB50"
#define  TC_TChdr_P_LUT_CTRL3_reg                                                0xB806BB50
#define  TC_TChdr_P_LUT_CTRL3_inst_addr                                          "0x0014"
#define  set_TC_TChdr_P_LUT_CTRL3_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL3_reg)=data)
#define  get_TC_TChdr_P_LUT_CTRL3_reg                                            (*((volatile unsigned int*)TC_TChdr_P_LUT_CTRL3_reg))
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut0_rd_acc_shift                             (5)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut0_wr_acc_shift                             (4)
#define  TC_TChdr_P_LUT_CTRL3_p_hw_lut0_rd_acc_shift                             (3)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut1_rd_acc_shift                             (2)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut1_wr_acc_shift                             (1)
#define  TC_TChdr_P_LUT_CTRL3_p_hw_lut1_rd_acc_shift                             (0)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut0_rd_acc_mask                              (0x00000020)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut0_wr_acc_mask                              (0x00000010)
#define  TC_TChdr_P_LUT_CTRL3_p_hw_lut0_rd_acc_mask                              (0x00000008)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut1_rd_acc_mask                              (0x00000004)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut1_wr_acc_mask                              (0x00000002)
#define  TC_TChdr_P_LUT_CTRL3_p_hw_lut1_rd_acc_mask                              (0x00000001)
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut0_rd_acc(data)                             (0x00000020&((data)<<5))
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut0_wr_acc(data)                             (0x00000010&((data)<<4))
#define  TC_TChdr_P_LUT_CTRL3_p_hw_lut0_rd_acc(data)                             (0x00000008&((data)<<3))
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut1_rd_acc(data)                             (0x00000004&((data)<<2))
#define  TC_TChdr_P_LUT_CTRL3_p_fw_lut1_wr_acc(data)                             (0x00000002&((data)<<1))
#define  TC_TChdr_P_LUT_CTRL3_p_hw_lut1_rd_acc(data)                             (0x00000001&(data))
#define  TC_TChdr_P_LUT_CTRL3_get_p_fw_lut0_rd_acc(data)                         ((0x00000020&(data))>>5)
#define  TC_TChdr_P_LUT_CTRL3_get_p_fw_lut0_wr_acc(data)                         ((0x00000010&(data))>>4)
#define  TC_TChdr_P_LUT_CTRL3_get_p_hw_lut0_rd_acc(data)                         ((0x00000008&(data))>>3)
#define  TC_TChdr_P_LUT_CTRL3_get_p_fw_lut1_rd_acc(data)                         ((0x00000004&(data))>>2)
#define  TC_TChdr_P_LUT_CTRL3_get_p_fw_lut1_wr_acc(data)                         ((0x00000002&(data))>>1)
#define  TC_TChdr_P_LUT_CTRL3_get_p_hw_lut1_rd_acc(data)                         (0x00000001&(data))

#define  TC_TChdr_P_LUT_WR_DATA                                                  0x1806BB54
#define  TC_TChdr_P_LUT_WR_DATA_reg_addr                                         "0xB806BB54"
#define  TC_TChdr_P_LUT_WR_DATA_reg                                              0xB806BB54
#define  TC_TChdr_P_LUT_WR_DATA_inst_addr                                        "0x0015"
#define  set_TC_TChdr_P_LUT_WR_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_P_LUT_WR_DATA_reg)=data)
#define  get_TC_TChdr_P_LUT_WR_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_P_LUT_WR_DATA_reg))
#define  TC_TChdr_P_LUT_WR_DATA_p_wr_lut_data0_shift                             (16)
#define  TC_TChdr_P_LUT_WR_DATA_p_wr_lut_data1_shift                             (0)
#define  TC_TChdr_P_LUT_WR_DATA_p_wr_lut_data0_mask                              (0x3FFF0000)
#define  TC_TChdr_P_LUT_WR_DATA_p_wr_lut_data1_mask                              (0x00003FFF)
#define  TC_TChdr_P_LUT_WR_DATA_p_wr_lut_data0(data)                             (0x3FFF0000&((data)<<16))
#define  TC_TChdr_P_LUT_WR_DATA_p_wr_lut_data1(data)                             (0x00003FFF&(data))
#define  TC_TChdr_P_LUT_WR_DATA_get_p_wr_lut_data0(data)                         ((0x3FFF0000&(data))>>16)
#define  TC_TChdr_P_LUT_WR_DATA_get_p_wr_lut_data1(data)                         (0x00003FFF&(data))

#define  TC_TChdr_P_LUT_RD_DATA                                                  0x1806BB58
#define  TC_TChdr_P_LUT_RD_DATA_reg_addr                                         "0xB806BB58"
#define  TC_TChdr_P_LUT_RD_DATA_reg                                              0xB806BB58
#define  TC_TChdr_P_LUT_RD_DATA_inst_addr                                        "0x0016"
#define  set_TC_TChdr_P_LUT_RD_DATA_reg(data)                                    (*((volatile unsigned int*)TC_TChdr_P_LUT_RD_DATA_reg)=data)
#define  get_TC_TChdr_P_LUT_RD_DATA_reg                                          (*((volatile unsigned int*)TC_TChdr_P_LUT_RD_DATA_reg))
#define  TC_TChdr_P_LUT_RD_DATA_p_rd_lut_data0_shift                             (16)
#define  TC_TChdr_P_LUT_RD_DATA_p_rd_lut_data1_shift                             (0)
#define  TC_TChdr_P_LUT_RD_DATA_p_rd_lut_data0_mask                              (0x3FFF0000)
#define  TC_TChdr_P_LUT_RD_DATA_p_rd_lut_data1_mask                              (0x00003FFF)
#define  TC_TChdr_P_LUT_RD_DATA_p_rd_lut_data0(data)                             (0x3FFF0000&((data)<<16))
#define  TC_TChdr_P_LUT_RD_DATA_p_rd_lut_data1(data)                             (0x00003FFF&(data))
#define  TC_TChdr_P_LUT_RD_DATA_get_p_rd_lut_data0(data)                         ((0x3FFF0000&(data))>>16)
#define  TC_TChdr_P_LUT_RD_DATA_get_p_rd_lut_data1(data)                         (0x00003FFF&(data))

#define  TC_TChdr_T_Compute0                                                     0x1806BB5C
#define  TC_TChdr_T_Compute0_reg_addr                                            "0xB806BB5C"
#define  TC_TChdr_T_Compute0_reg                                                 0xB806BB5C
#define  TC_TChdr_T_Compute0_inst_addr                                           "0x0017"
#define  set_TC_TChdr_T_Compute0_reg(data)                                       (*((volatile unsigned int*)TC_TChdr_T_Compute0_reg)=data)
#define  get_TC_TChdr_T_Compute0_reg                                             (*((volatile unsigned int*)TC_TChdr_T_Compute0_reg))
#define  TC_TChdr_T_Compute0_oct1_shift                                          (16)
#define  TC_TChdr_T_Compute0_oct0_shift                                          (0)
#define  TC_TChdr_T_Compute0_oct1_mask                                           (0x03FF0000)
#define  TC_TChdr_T_Compute0_oct0_mask                                           (0x000003FF)
#define  TC_TChdr_T_Compute0_oct1(data)                                          (0x03FF0000&((data)<<16))
#define  TC_TChdr_T_Compute0_oct0(data)                                          (0x000003FF&(data))
#define  TC_TChdr_T_Compute0_get_oct1(data)                                      ((0x03FF0000&(data))>>16)
#define  TC_TChdr_T_Compute0_get_oct0(data)                                      (0x000003FF&(data))

#define  TC_TChdr_T_Compute1                                                     0x1806BB60
#define  TC_TChdr_T_Compute1_reg_addr                                            "0xB806BB60"
#define  TC_TChdr_T_Compute1_reg                                                 0xB806BB60
#define  TC_TChdr_T_Compute1_inst_addr                                           "0x0018"
#define  set_TC_TChdr_T_Compute1_reg(data)                                       (*((volatile unsigned int*)TC_TChdr_T_Compute1_reg)=data)
#define  get_TC_TChdr_T_Compute1_reg                                             (*((volatile unsigned int*)TC_TChdr_T_Compute1_reg))
#define  TC_TChdr_T_Compute1_oct2_shift                                          (0)
#define  TC_TChdr_T_Compute1_oct2_mask                                           (0x000003FF)
#define  TC_TChdr_T_Compute1_oct2(data)                                          (0x000003FF&(data))
#define  TC_TChdr_T_Compute1_get_oct2(data)                                      (0x000003FF&(data))

#define  TC_TChdr_M_Compute0                                                     0x1806BB64
#define  TC_TChdr_M_Compute0_reg_addr                                            "0xB806BB64"
#define  TC_TChdr_M_Compute0_reg                                                 0xB806BB64
#define  TC_TChdr_M_Compute0_inst_addr                                           "0x0019"
#define  set_TC_TChdr_M_Compute0_reg(data)                                       (*((volatile unsigned int*)TC_TChdr_M_Compute0_reg)=data)
#define  get_TC_TChdr_M_Compute0_reg                                             (*((volatile unsigned int*)TC_TChdr_M_Compute0_reg))
#define  TC_TChdr_M_Compute0_oct4_shift                                          (16)
#define  TC_TChdr_M_Compute0_oct3_shift                                          (0)
#define  TC_TChdr_M_Compute0_oct4_mask                                           (0x03FF0000)
#define  TC_TChdr_M_Compute0_oct3_mask                                           (0x000003FF)
#define  TC_TChdr_M_Compute0_oct4(data)                                          (0x03FF0000&((data)<<16))
#define  TC_TChdr_M_Compute0_oct3(data)                                          (0x000003FF&(data))
#define  TC_TChdr_M_Compute0_get_oct4(data)                                      ((0x03FF0000&(data))>>16)
#define  TC_TChdr_M_Compute0_get_oct3(data)                                      (0x000003FF&(data))

#define  TC_TChdr_M_Compute1                                                     0x1806BB68
#define  TC_TChdr_M_Compute1_reg_addr                                            "0xB806BB68"
#define  TC_TChdr_M_Compute1_reg                                                 0xB806BB68
#define  TC_TChdr_M_Compute1_inst_addr                                           "0x001A"
#define  set_TC_TChdr_M_Compute1_reg(data)                                       (*((volatile unsigned int*)TC_TChdr_M_Compute1_reg)=data)
#define  get_TC_TChdr_M_Compute1_reg                                             (*((volatile unsigned int*)TC_TChdr_M_Compute1_reg))
#define  TC_TChdr_M_Compute1_oct6_shift                                          (16)
#define  TC_TChdr_M_Compute1_oct5_shift                                          (0)
#define  TC_TChdr_M_Compute1_oct6_mask                                           (0x03FF0000)
#define  TC_TChdr_M_Compute1_oct5_mask                                           (0x000003FF)
#define  TC_TChdr_M_Compute1_oct6(data)                                          (0x03FF0000&((data)<<16))
#define  TC_TChdr_M_Compute1_oct5(data)                                          (0x000003FF&(data))
#define  TC_TChdr_M_Compute1_get_oct6(data)                                      ((0x03FF0000&(data))>>16)
#define  TC_TChdr_M_Compute1_get_oct5(data)                                      (0x000003FF&(data))

#define  TC_TChdr_D_LUT_STEP                                                     0x1806BB6C
#define  TC_TChdr_D_LUT_STEP_reg_addr                                            "0xB806BB6C"
#define  TC_TChdr_D_LUT_STEP_reg                                                 0xB806BB6C
#define  TC_TChdr_D_LUT_STEP_inst_addr                                           "0x001B"
#define  set_TC_TChdr_D_LUT_STEP_reg(data)                                       (*((volatile unsigned int*)TC_TChdr_D_LUT_STEP_reg)=data)
#define  get_TC_TChdr_D_LUT_STEP_reg                                             (*((volatile unsigned int*)TC_TChdr_D_LUT_STEP_reg))
#define  TC_TChdr_D_LUT_STEP_dlut_step3_shift                                    (12)
#define  TC_TChdr_D_LUT_STEP_dlut_step2_shift                                    (8)
#define  TC_TChdr_D_LUT_STEP_dlut_step1_shift                                    (4)
#define  TC_TChdr_D_LUT_STEP_dlut_step0_shift                                    (0)
#define  TC_TChdr_D_LUT_STEP_dlut_step3_mask                                     (0x0000F000)
#define  TC_TChdr_D_LUT_STEP_dlut_step2_mask                                     (0x00000F00)
#define  TC_TChdr_D_LUT_STEP_dlut_step1_mask                                     (0x000000F0)
#define  TC_TChdr_D_LUT_STEP_dlut_step0_mask                                     (0x0000000F)
#define  TC_TChdr_D_LUT_STEP_dlut_step3(data)                                    (0x0000F000&((data)<<12))
#define  TC_TChdr_D_LUT_STEP_dlut_step2(data)                                    (0x00000F00&((data)<<8))
#define  TC_TChdr_D_LUT_STEP_dlut_step1(data)                                    (0x000000F0&((data)<<4))
#define  TC_TChdr_D_LUT_STEP_dlut_step0(data)                                    (0x0000000F&(data))
#define  TC_TChdr_D_LUT_STEP_get_dlut_step3(data)                                ((0x0000F000&(data))>>12)
#define  TC_TChdr_D_LUT_STEP_get_dlut_step2(data)                                ((0x00000F00&(data))>>8)
#define  TC_TChdr_D_LUT_STEP_get_dlut_step1(data)                                ((0x000000F0&(data))>>4)
#define  TC_TChdr_D_LUT_STEP_get_dlut_step0(data)                                (0x0000000F&(data))

#define  TC_TChdr_D_LUT_THRESHOLD0                                               0x1806BB70
#define  TC_TChdr_D_LUT_THRESHOLD0_reg_addr                                      "0xB806BB70"
#define  TC_TChdr_D_LUT_THRESHOLD0_reg                                           0xB806BB70
#define  TC_TChdr_D_LUT_THRESHOLD0_inst_addr                                     "0x001C"
#define  set_TC_TChdr_D_LUT_THRESHOLD0_reg(data)                                 (*((volatile unsigned int*)TC_TChdr_D_LUT_THRESHOLD0_reg)=data)
#define  get_TC_TChdr_D_LUT_THRESHOLD0_reg                                       (*((volatile unsigned int*)TC_TChdr_D_LUT_THRESHOLD0_reg))
#define  TC_TChdr_D_LUT_THRESHOLD0_dlut_threshold1_shift                         (16)
#define  TC_TChdr_D_LUT_THRESHOLD0_dlut_threshold0_shift                         (0)
#define  TC_TChdr_D_LUT_THRESHOLD0_dlut_threshold1_mask                          (0x1FFF0000)
#define  TC_TChdr_D_LUT_THRESHOLD0_dlut_threshold0_mask                          (0x00001FFF)
#define  TC_TChdr_D_LUT_THRESHOLD0_dlut_threshold1(data)                         (0x1FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_THRESHOLD0_dlut_threshold0(data)                         (0x00001FFF&(data))
#define  TC_TChdr_D_LUT_THRESHOLD0_get_dlut_threshold1(data)                     ((0x1FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_THRESHOLD0_get_dlut_threshold0(data)                     (0x00001FFF&(data))

#define  TC_TChdr_D_LUT_THRESHOLD1                                               0x1806BB74
#define  TC_TChdr_D_LUT_THRESHOLD1_reg_addr                                      "0xB806BB74"
#define  TC_TChdr_D_LUT_THRESHOLD1_reg                                           0xB806BB74
#define  TC_TChdr_D_LUT_THRESHOLD1_inst_addr                                     "0x001D"
#define  set_TC_TChdr_D_LUT_THRESHOLD1_reg(data)                                 (*((volatile unsigned int*)TC_TChdr_D_LUT_THRESHOLD1_reg)=data)
#define  get_TC_TChdr_D_LUT_THRESHOLD1_reg                                       (*((volatile unsigned int*)TC_TChdr_D_LUT_THRESHOLD1_reg))
#define  TC_TChdr_D_LUT_THRESHOLD1_dlut_threshold2_shift                         (0)
#define  TC_TChdr_D_LUT_THRESHOLD1_dlut_threshold2_mask                          (0x00001FFF)
#define  TC_TChdr_D_LUT_THRESHOLD1_dlut_threshold2(data)                         (0x00001FFF&(data))
#define  TC_TChdr_D_LUT_THRESHOLD1_get_dlut_threshold2(data)                     (0x00001FFF&(data))

#define  TC_TChdr_D_LUT_CTRL0                                                    0x1806BB78
#define  TC_TChdr_D_LUT_CTRL0_reg_addr                                           "0xB806BB78"
#define  TC_TChdr_D_LUT_CTRL0_reg                                                0xB806BB78
#define  TC_TChdr_D_LUT_CTRL0_inst_addr                                          "0x001E"
#define  set_TC_TChdr_D_LUT_CTRL0_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_D_LUT_CTRL0_reg)=data)
#define  get_TC_TChdr_D_LUT_CTRL0_reg                                            (*((volatile unsigned int*)TC_TChdr_D_LUT_CTRL0_reg))
#define  TC_TChdr_D_LUT_CTRL0_d_lut_rw_sel_shift                                 (0)
#define  TC_TChdr_D_LUT_CTRL0_d_lut_rw_sel_mask                                  (0x00000003)
#define  TC_TChdr_D_LUT_CTRL0_d_lut_rw_sel(data)                                 (0x00000003&(data))
#define  TC_TChdr_D_LUT_CTRL0_get_d_lut_rw_sel(data)                             (0x00000003&(data))

#define  TC_TChdr_D_LUT_CTRL1                                                    0x1806BB7C
#define  TC_TChdr_D_LUT_CTRL1_reg_addr                                           "0xB806BB7C"
#define  TC_TChdr_D_LUT_CTRL1_reg                                                0xB806BB7C
#define  TC_TChdr_D_LUT_CTRL1_inst_addr                                          "0x001F"
#define  set_TC_TChdr_D_LUT_CTRL1_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_D_LUT_CTRL1_reg)=data)
#define  get_TC_TChdr_D_LUT_CTRL1_reg                                            (*((volatile unsigned int*)TC_TChdr_D_LUT_CTRL1_reg))
#define  TC_TChdr_D_LUT_CTRL1_d_lut_write_en_shift                               (7)
#define  TC_TChdr_D_LUT_CTRL1_d_lut_read_en_shift                                (6)
#define  TC_TChdr_D_LUT_CTRL1_d_lut_rw_addr_shift                                (0)
#define  TC_TChdr_D_LUT_CTRL1_d_lut_write_en_mask                                (0x00000080)
#define  TC_TChdr_D_LUT_CTRL1_d_lut_read_en_mask                                 (0x00000040)
#define  TC_TChdr_D_LUT_CTRL1_d_lut_rw_addr_mask                                 (0x0000003F)
#define  TC_TChdr_D_LUT_CTRL1_d_lut_write_en(data)                               (0x00000080&((data)<<7))
#define  TC_TChdr_D_LUT_CTRL1_d_lut_read_en(data)                                (0x00000040&((data)<<6))
#define  TC_TChdr_D_LUT_CTRL1_d_lut_rw_addr(data)                                (0x0000003F&(data))
#define  TC_TChdr_D_LUT_CTRL1_get_d_lut_write_en(data)                           ((0x00000080&(data))>>7)
#define  TC_TChdr_D_LUT_CTRL1_get_d_lut_read_en(data)                            ((0x00000040&(data))>>6)
#define  TC_TChdr_D_LUT_CTRL1_get_d_lut_rw_addr(data)                            (0x0000003F&(data))

#define  TC_TChdr_D_LUT_WR_DATA0                                                 0x1806BB80
#define  TC_TChdr_D_LUT_WR_DATA0_reg_addr                                        "0xB806BB80"
#define  TC_TChdr_D_LUT_WR_DATA0_reg                                             0xB806BB80
#define  TC_TChdr_D_LUT_WR_DATA0_inst_addr                                       "0x0020"
#define  set_TC_TChdr_D_LUT_WR_DATA0_reg(data)                                   (*((volatile unsigned int*)TC_TChdr_D_LUT_WR_DATA0_reg)=data)
#define  get_TC_TChdr_D_LUT_WR_DATA0_reg                                         (*((volatile unsigned int*)TC_TChdr_D_LUT_WR_DATA0_reg))
#define  TC_TChdr_D_LUT_WR_DATA0_d_wr_lut_data0_shift                            (16)
#define  TC_TChdr_D_LUT_WR_DATA0_d_wr_lut_data1_shift                            (0)
#define  TC_TChdr_D_LUT_WR_DATA0_d_wr_lut_data0_mask                             (0x0FFF0000)
#define  TC_TChdr_D_LUT_WR_DATA0_d_wr_lut_data1_mask                             (0x00000FFF)
#define  TC_TChdr_D_LUT_WR_DATA0_d_wr_lut_data0(data)                            (0x0FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_WR_DATA0_d_wr_lut_data1(data)                            (0x00000FFF&(data))
#define  TC_TChdr_D_LUT_WR_DATA0_get_d_wr_lut_data0(data)                        ((0x0FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_WR_DATA0_get_d_wr_lut_data1(data)                        (0x00000FFF&(data))

#define  TC_TChdr_D_LUT_WR_DATA1                                                 0x1806BB84
#define  TC_TChdr_D_LUT_WR_DATA1_reg_addr                                        "0xB806BB84"
#define  TC_TChdr_D_LUT_WR_DATA1_reg                                             0xB806BB84
#define  TC_TChdr_D_LUT_WR_DATA1_inst_addr                                       "0x0021"
#define  set_TC_TChdr_D_LUT_WR_DATA1_reg(data)                                   (*((volatile unsigned int*)TC_TChdr_D_LUT_WR_DATA1_reg)=data)
#define  get_TC_TChdr_D_LUT_WR_DATA1_reg                                         (*((volatile unsigned int*)TC_TChdr_D_LUT_WR_DATA1_reg))
#define  TC_TChdr_D_LUT_WR_DATA1_d_wr_lut_data2_shift                            (16)
#define  TC_TChdr_D_LUT_WR_DATA1_d_wr_lut_data3_shift                            (0)
#define  TC_TChdr_D_LUT_WR_DATA1_d_wr_lut_data2_mask                             (0x0FFF0000)
#define  TC_TChdr_D_LUT_WR_DATA1_d_wr_lut_data3_mask                             (0x00000FFF)
#define  TC_TChdr_D_LUT_WR_DATA1_d_wr_lut_data2(data)                            (0x0FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_WR_DATA1_d_wr_lut_data3(data)                            (0x00000FFF&(data))
#define  TC_TChdr_D_LUT_WR_DATA1_get_d_wr_lut_data2(data)                        ((0x0FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_WR_DATA1_get_d_wr_lut_data3(data)                        (0x00000FFF&(data))

#define  TC_TChdr_D_LUT_WR_DATA2                                                 0x1806BB88
#define  TC_TChdr_D_LUT_WR_DATA2_reg_addr                                        "0xB806BB88"
#define  TC_TChdr_D_LUT_WR_DATA2_reg                                             0xB806BB88
#define  TC_TChdr_D_LUT_WR_DATA2_inst_addr                                       "0x0022"
#define  set_TC_TChdr_D_LUT_WR_DATA2_reg(data)                                   (*((volatile unsigned int*)TC_TChdr_D_LUT_WR_DATA2_reg)=data)
#define  get_TC_TChdr_D_LUT_WR_DATA2_reg                                         (*((volatile unsigned int*)TC_TChdr_D_LUT_WR_DATA2_reg))
#define  TC_TChdr_D_LUT_WR_DATA2_d_wr_lut_data4_shift                            (16)
#define  TC_TChdr_D_LUT_WR_DATA2_d_wr_lut_data5_shift                            (0)
#define  TC_TChdr_D_LUT_WR_DATA2_d_wr_lut_data4_mask                             (0x0FFF0000)
#define  TC_TChdr_D_LUT_WR_DATA2_d_wr_lut_data5_mask                             (0x00000FFF)
#define  TC_TChdr_D_LUT_WR_DATA2_d_wr_lut_data4(data)                            (0x0FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_WR_DATA2_d_wr_lut_data5(data)                            (0x00000FFF&(data))
#define  TC_TChdr_D_LUT_WR_DATA2_get_d_wr_lut_data4(data)                        ((0x0FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_WR_DATA2_get_d_wr_lut_data5(data)                        (0x00000FFF&(data))

#define  TC_TChdr_D_LUT_RD_DATA0                                                 0x1806BB8C
#define  TC_TChdr_D_LUT_RD_DATA0_reg_addr                                        "0xB806BB8C"
#define  TC_TChdr_D_LUT_RD_DATA0_reg                                             0xB806BB8C
#define  TC_TChdr_D_LUT_RD_DATA0_inst_addr                                       "0x0023"
#define  set_TC_TChdr_D_LUT_RD_DATA0_reg(data)                                   (*((volatile unsigned int*)TC_TChdr_D_LUT_RD_DATA0_reg)=data)
#define  get_TC_TChdr_D_LUT_RD_DATA0_reg                                         (*((volatile unsigned int*)TC_TChdr_D_LUT_RD_DATA0_reg))
#define  TC_TChdr_D_LUT_RD_DATA0_d_rd_lut_data0_shift                            (16)
#define  TC_TChdr_D_LUT_RD_DATA0_d_rd_lut_data1_shift                            (0)
#define  TC_TChdr_D_LUT_RD_DATA0_d_rd_lut_data0_mask                             (0x0FFF0000)
#define  TC_TChdr_D_LUT_RD_DATA0_d_rd_lut_data1_mask                             (0x00000FFF)
#define  TC_TChdr_D_LUT_RD_DATA0_d_rd_lut_data0(data)                            (0x0FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_RD_DATA0_d_rd_lut_data1(data)                            (0x00000FFF&(data))
#define  TC_TChdr_D_LUT_RD_DATA0_get_d_rd_lut_data0(data)                        ((0x0FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_RD_DATA0_get_d_rd_lut_data1(data)                        (0x00000FFF&(data))

#define  TC_TChdr_D_LUT_RD_DATA1                                                 0x1806BB90
#define  TC_TChdr_D_LUT_RD_DATA1_reg_addr                                        "0xB806BB90"
#define  TC_TChdr_D_LUT_RD_DATA1_reg                                             0xB806BB90
#define  TC_TChdr_D_LUT_RD_DATA1_inst_addr                                       "0x0024"
#define  set_TC_TChdr_D_LUT_RD_DATA1_reg(data)                                   (*((volatile unsigned int*)TC_TChdr_D_LUT_RD_DATA1_reg)=data)
#define  get_TC_TChdr_D_LUT_RD_DATA1_reg                                         (*((volatile unsigned int*)TC_TChdr_D_LUT_RD_DATA1_reg))
#define  TC_TChdr_D_LUT_RD_DATA1_d_rd_lut_data2_shift                            (16)
#define  TC_TChdr_D_LUT_RD_DATA1_d_rd_lut_data3_shift                            (0)
#define  TC_TChdr_D_LUT_RD_DATA1_d_rd_lut_data2_mask                             (0x0FFF0000)
#define  TC_TChdr_D_LUT_RD_DATA1_d_rd_lut_data3_mask                             (0x00000FFF)
#define  TC_TChdr_D_LUT_RD_DATA1_d_rd_lut_data2(data)                            (0x0FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_RD_DATA1_d_rd_lut_data3(data)                            (0x00000FFF&(data))
#define  TC_TChdr_D_LUT_RD_DATA1_get_d_rd_lut_data2(data)                        ((0x0FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_RD_DATA1_get_d_rd_lut_data3(data)                        (0x00000FFF&(data))

#define  TC_TChdr_D_LUT_RD_DATA2                                                 0x1806BB94
#define  TC_TChdr_D_LUT_RD_DATA2_reg_addr                                        "0xB806BB94"
#define  TC_TChdr_D_LUT_RD_DATA2_reg                                             0xB806BB94
#define  TC_TChdr_D_LUT_RD_DATA2_inst_addr                                       "0x0025"
#define  set_TC_TChdr_D_LUT_RD_DATA2_reg(data)                                   (*((volatile unsigned int*)TC_TChdr_D_LUT_RD_DATA2_reg)=data)
#define  get_TC_TChdr_D_LUT_RD_DATA2_reg                                         (*((volatile unsigned int*)TC_TChdr_D_LUT_RD_DATA2_reg))
#define  TC_TChdr_D_LUT_RD_DATA2_d_rd_lut_data4_shift                            (16)
#define  TC_TChdr_D_LUT_RD_DATA2_d_rd_lut_data5_shift                            (0)
#define  TC_TChdr_D_LUT_RD_DATA2_d_rd_lut_data4_mask                             (0x0FFF0000)
#define  TC_TChdr_D_LUT_RD_DATA2_d_rd_lut_data5_mask                             (0x00000FFF)
#define  TC_TChdr_D_LUT_RD_DATA2_d_rd_lut_data4(data)                            (0x0FFF0000&((data)<<16))
#define  TC_TChdr_D_LUT_RD_DATA2_d_rd_lut_data5(data)                            (0x00000FFF&(data))
#define  TC_TChdr_D_LUT_RD_DATA2_get_d_rd_lut_data4(data)                        ((0x0FFF0000&(data))>>16)
#define  TC_TChdr_D_LUT_RD_DATA2_get_d_rd_lut_data5(data)                        (0x00000FFF&(data))

#define  TC_TChdr_Double_Buffer_CTRL                                             0x1806BB98
#define  TC_TChdr_Double_Buffer_CTRL_reg_addr                                    "0xB806BB98"
#define  TC_TChdr_Double_Buffer_CTRL_reg                                         0xB806BB98
#define  TC_TChdr_Double_Buffer_CTRL_inst_addr                                   "0x0026"
#define  set_TC_TChdr_Double_Buffer_CTRL_reg(data)                               (*((volatile unsigned int*)TC_TChdr_Double_Buffer_CTRL_reg)=data)
#define  get_TC_TChdr_Double_Buffer_CTRL_reg                                     (*((volatile unsigned int*)TC_TChdr_Double_Buffer_CTRL_reg))
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_en_shift                              (2)
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_read_sel_shift                        (1)
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_apply_shift                           (0)
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_en_mask                               (0x00000004)
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_read_sel_mask                         (0x00000002)
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_apply_mask                            (0x00000001)
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_en(data)                              (0x00000004&((data)<<2))
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_read_sel(data)                        (0x00000002&((data)<<1))
#define  TC_TChdr_Double_Buffer_CTRL_tc_db_apply(data)                           (0x00000001&(data))
#define  TC_TChdr_Double_Buffer_CTRL_get_tc_db_en(data)                          ((0x00000004&(data))>>2)
#define  TC_TChdr_Double_Buffer_CTRL_get_tc_db_read_sel(data)                    ((0x00000002&(data))>>1)
#define  TC_TChdr_Double_Buffer_CTRL_get_tc_db_apply(data)                       (0x00000001&(data))

#define  TC_TChdr_CD_LUT_MBIST                                                   0x1806BB9C
#define  TC_TChdr_CD_LUT_MBIST_reg_addr                                          "0xB806BB9C"
#define  TC_TChdr_CD_LUT_MBIST_reg                                               0xB806BB9C
#define  TC_TChdr_CD_LUT_MBIST_inst_addr                                         "0x0027"
#define  set_TC_TChdr_CD_LUT_MBIST_reg(data)                                     (*((volatile unsigned int*)TC_TChdr_CD_LUT_MBIST_reg)=data)
#define  get_TC_TChdr_CD_LUT_MBIST_reg                                           (*((volatile unsigned int*)TC_TChdr_CD_LUT_MBIST_reg))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_ls_shift                              (31)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_rme_shift                             (30)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_rm_shift                              (26)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_7_shift                     (15)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_6_shift                     (14)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_5_shift                     (13)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_4_shift                     (12)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_3_shift                     (11)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_2_shift                     (10)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_1_shift                     (9)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_0_shift                     (8)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_7_shift                 (7)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_6_shift                 (6)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_5_shift                 (5)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_4_shift                 (4)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_3_shift                 (3)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_2_shift                 (2)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_1_shift                 (1)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_0_shift                 (0)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_ls_mask                               (0x80000000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_rme_mask                              (0x40000000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_rm_mask                               (0x3C000000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_7_mask                      (0x00008000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_6_mask                      (0x00004000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_5_mask                      (0x00002000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_4_mask                      (0x00001000)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_3_mask                      (0x00000800)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_2_mask                      (0x00000400)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_1_mask                      (0x00000200)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_0_mask                      (0x00000100)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_7_mask                  (0x00000080)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_6_mask                  (0x00000040)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_5_mask                  (0x00000020)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_4_mask                  (0x00000010)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_3_mask                  (0x00000008)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_2_mask                  (0x00000004)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_1_mask                  (0x00000002)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_0_mask                  (0x00000001)
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_ls(data)                              (0x80000000&((data)<<31))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_rme(data)                             (0x40000000&((data)<<30))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_rm(data)                              (0x3C000000&((data)<<26))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_7(data)                     (0x00008000&((data)<<15))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_6(data)                     (0x00004000&((data)<<14))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_5(data)                     (0x00002000&((data)<<13))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_4(data)                     (0x00001000&((data)<<12))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_3(data)                     (0x00000800&((data)<<11))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_2(data)                     (0x00000400&((data)<<10))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_1(data)                     (0x00000200&((data)<<9))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_bist_fail_0(data)                     (0x00000100&((data)<<8))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_7(data)                 (0x00000080&((data)<<7))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_6(data)                 (0x00000040&((data)<<6))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_5(data)                 (0x00000020&((data)<<5))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_4(data)                 (0x00000010&((data)<<4))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_3(data)                 (0x00000008&((data)<<3))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_2(data)                 (0x00000004&((data)<<2))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_1(data)                 (0x00000002&((data)<<1))
#define  TC_TChdr_CD_LUT_MBIST_tchdr_cdlut_drf_bist_fail_0(data)                 (0x00000001&(data))
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_ls(data)                          ((0x80000000&(data))>>31)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_rme(data)                         ((0x40000000&(data))>>30)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_rm(data)                          ((0x3C000000&(data))>>26)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_7(data)                 ((0x00008000&(data))>>15)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_6(data)                 ((0x00004000&(data))>>14)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_5(data)                 ((0x00002000&(data))>>13)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_4(data)                 ((0x00001000&(data))>>12)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_3(data)                 ((0x00000800&(data))>>11)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_2(data)                 ((0x00000400&(data))>>10)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_1(data)                 ((0x00000200&(data))>>9)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_bist_fail_0(data)                 ((0x00000100&(data))>>8)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_7(data)             ((0x00000080&(data))>>7)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_6(data)             ((0x00000040&(data))>>6)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_5(data)             ((0x00000020&(data))>>5)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_4(data)             ((0x00000010&(data))>>4)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_3(data)             ((0x00000008&(data))>>3)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_2(data)             ((0x00000004&(data))>>2)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_1(data)             ((0x00000002&(data))>>1)
#define  TC_TChdr_CD_LUT_MBIST_get_tchdr_cdlut_drf_bist_fail_0(data)             (0x00000001&(data))

#define  TC_TChdr_P_LUT_MBIST                                                    0x1806BBA0
#define  TC_TChdr_P_LUT_MBIST_reg_addr                                           "0xB806BBA0"
#define  TC_TChdr_P_LUT_MBIST_reg                                                0xB806BBA0
#define  TC_TChdr_P_LUT_MBIST_inst_addr                                          "0x0028"
#define  set_TC_TChdr_P_LUT_MBIST_reg(data)                                      (*((volatile unsigned int*)TC_TChdr_P_LUT_MBIST_reg)=data)
#define  get_TC_TChdr_P_LUT_MBIST_reg                                            (*((volatile unsigned int*)TC_TChdr_P_LUT_MBIST_reg))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_ls_shift                                (31)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_rme_shift                               (30)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_rm_shift                                (26)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_3_shift                       (11)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_2_shift                       (10)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_1_shift                       (9)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_0_shift                       (8)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_3_shift                   (3)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_2_shift                   (2)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_1_shift                   (1)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_0_shift                   (0)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_ls_mask                                 (0x80000000)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_rme_mask                                (0x40000000)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_rm_mask                                 (0x3C000000)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_3_mask                        (0x00000800)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_2_mask                        (0x00000400)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_1_mask                        (0x00000200)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_0_mask                        (0x00000100)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_3_mask                    (0x00000008)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_2_mask                    (0x00000004)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_1_mask                    (0x00000002)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_0_mask                    (0x00000001)
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_ls(data)                                (0x80000000&((data)<<31))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_rme(data)                               (0x40000000&((data)<<30))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_rm(data)                                (0x3C000000&((data)<<26))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_3(data)                       (0x00000800&((data)<<11))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_2(data)                       (0x00000400&((data)<<10))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_1(data)                       (0x00000200&((data)<<9))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_bist_fail_0(data)                       (0x00000100&((data)<<8))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_3(data)                   (0x00000008&((data)<<3))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_2(data)                   (0x00000004&((data)<<2))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_1(data)                   (0x00000002&((data)<<1))
#define  TC_TChdr_P_LUT_MBIST_tchdr_plut_drf_bist_fail_0(data)                   (0x00000001&(data))
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_ls(data)                            ((0x80000000&(data))>>31)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_rme(data)                           ((0x40000000&(data))>>30)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_rm(data)                            ((0x3C000000&(data))>>26)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_bist_fail_3(data)                   ((0x00000800&(data))>>11)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_bist_fail_2(data)                   ((0x00000400&(data))>>10)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_bist_fail_1(data)                   ((0x00000200&(data))>>9)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_bist_fail_0(data)                   ((0x00000100&(data))>>8)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_drf_bist_fail_3(data)               ((0x00000008&(data))>>3)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_drf_bist_fail_2(data)               ((0x00000004&(data))>>2)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_drf_bist_fail_1(data)               ((0x00000002&(data))>>1)
#define  TC_TChdr_P_LUT_MBIST_get_tchdr_plut_drf_bist_fail_0(data)               (0x00000001&(data))

#define  TC_TChdr_SI_LUT_MBIST                                                   0x1806BBA4
#define  TC_TChdr_SI_LUT_MBIST_reg_addr                                          "0xB806BBA4"
#define  TC_TChdr_SI_LUT_MBIST_reg                                               0xB806BBA4
#define  TC_TChdr_SI_LUT_MBIST_inst_addr                                         "0x0029"
#define  set_TC_TChdr_SI_LUT_MBIST_reg(data)                                     (*((volatile unsigned int*)TC_TChdr_SI_LUT_MBIST_reg)=data)
#define  get_TC_TChdr_SI_LUT_MBIST_reg                                           (*((volatile unsigned int*)TC_TChdr_SI_LUT_MBIST_reg))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_ls_shift                              (31)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_rme_shift                             (30)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_rm_shift                              (26)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_3_shift                     (7)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_2_shift                     (6)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_1_shift                     (5)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_0_shift                     (4)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_3_shift                 (3)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_2_shift                 (2)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_1_shift                 (1)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_0_shift                 (0)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_ls_mask                               (0x80000000)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_rme_mask                              (0x40000000)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_rm_mask                               (0x3C000000)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_3_mask                      (0x00000080)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_2_mask                      (0x00000040)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_1_mask                      (0x00000020)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_0_mask                      (0x00000010)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_3_mask                  (0x00000008)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_2_mask                  (0x00000004)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_1_mask                  (0x00000002)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_0_mask                  (0x00000001)
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_ls(data)                              (0x80000000&((data)<<31))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_rme(data)                             (0x40000000&((data)<<30))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_rm(data)                              (0x3C000000&((data)<<26))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_3(data)                     (0x00000080&((data)<<7))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_2(data)                     (0x00000040&((data)<<6))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_1(data)                     (0x00000020&((data)<<5))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_bist_fail_0(data)                     (0x00000010&((data)<<4))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_3(data)                 (0x00000008&((data)<<3))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_2(data)                 (0x00000004&((data)<<2))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_1(data)                 (0x00000002&((data)<<1))
#define  TC_TChdr_SI_LUT_MBIST_tchdr_silut_drf_bist_fail_0(data)                 (0x00000001&(data))
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_ls(data)                          ((0x80000000&(data))>>31)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_rme(data)                         ((0x40000000&(data))>>30)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_rm(data)                          ((0x3C000000&(data))>>26)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_bist_fail_3(data)                 ((0x00000080&(data))>>7)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_bist_fail_2(data)                 ((0x00000040&(data))>>6)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_bist_fail_1(data)                 ((0x00000020&(data))>>5)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_bist_fail_0(data)                 ((0x00000010&(data))>>4)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_drf_bist_fail_3(data)             ((0x00000008&(data))>>3)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_drf_bist_fail_2(data)             ((0x00000004&(data))>>2)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_drf_bist_fail_1(data)             ((0x00000002&(data))>>1)
#define  TC_TChdr_SI_LUT_MBIST_get_tchdr_silut_drf_bist_fail_0(data)             (0x00000001&(data))

#define  TC_TC_DMAto3Dtable_CTRL                                                 0x1806BBB0
#define  TC_TC_DMAto3Dtable_CTRL_reg_addr                                        "0xB806BBB0"
#define  TC_TC_DMAto3Dtable_CTRL_reg                                             0xB806BBB0
#define  TC_TC_DMAto3Dtable_CTRL_inst_addr                                       "0x002A"
#define  set_TC_TC_DMAto3Dtable_CTRL_reg(data)                                   (*((volatile unsigned int*)TC_TC_DMAto3Dtable_CTRL_reg)=data)
#define  get_TC_TC_DMAto3Dtable_CTRL_reg                                         (*((volatile unsigned int*)TC_TC_DMAto3Dtable_CTRL_reg))
#define  TC_TC_DMAto3Dtable_CTRL_clut_dmato3dtable_en_shift                      (0)
#define  TC_TC_DMAto3Dtable_CTRL_clut_dmato3dtable_en_mask                       (0x00000001)
#define  TC_TC_DMAto3Dtable_CTRL_clut_dmato3dtable_en(data)                      (0x00000001&(data))
#define  TC_TC_DMAto3Dtable_CTRL_get_clut_dmato3dtable_en(data)                  (0x00000001&(data))

#define  TC_TC_DUMMY                                                             0x1806BBB4
#define  TC_TC_DUMMY_reg_addr                                                    "0xB806BBB4"
#define  TC_TC_DUMMY_reg                                                         0xB806BBB4
#define  TC_TC_DUMMY_inst_addr                                                   "0x002B"
#define  set_TC_TC_DUMMY_reg(data)                                               (*((volatile unsigned int*)TC_TC_DUMMY_reg)=data)
#define  get_TC_TC_DUMMY_reg                                                     (*((volatile unsigned int*)TC_TC_DUMMY_reg))
#define  TC_TC_DUMMY_dummy_31_16_shift                                           (16)
#define  TC_TC_DUMMY_dummy_d0_shift                                              (0)
#define  TC_TC_DUMMY_dummy_31_16_mask                                            (0xFFFF0000)
#define  TC_TC_DUMMY_dummy_d0_mask                                               (0x0000FFFF)
#define  TC_TC_DUMMY_dummy_31_16(data)                                           (0xFFFF0000&((data)<<16))
#define  TC_TC_DUMMY_dummy_d0(data)                                              (0x0000FFFF&(data))
#define  TC_TC_DUMMY_get_dummy_31_16(data)                                       ((0xFFFF0000&(data))>>16)
#define  TC_TC_DUMMY_get_dummy_d0(data)                                          (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  tc_certification_bitout:1;
        RBus_UInt32  certification_enable:1;
        RBus_UInt32  tc_enable:1;
    };
}tc_tchdr_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  footroom_int:10;
    };
}tc_tchdr_range_adaptation_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  c_headroom_int:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  l_headroom_int:10;
    };
}tc_tchdr_range_adaptation_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  inv_chroma_limited_range_ratio_int:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  inv_y_limited_range_ratio_int:11;
    };
}tc_tchdr_range_adaptation_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha_b:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha_a:13;
    };
}tc_tchdr_l_compute_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  c_lut_rw_sel:2;
    };
}tc_tchdr_c_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  c_lut_write_en:1;
        RBus_UInt32  c_lut_read_en:1;
        RBus_UInt32  c_lut_rw_addr:6;
    };
}tc_tchdr_c_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  c_wr_lut_data0:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  c_wr_lut_data1:11;
    };
}tc_tchdr_c_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  c_rd_lut_data0:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  c_rd_lut_data1:11;
    };
}tc_tchdr_c_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  s_lut_rw_sel:2;
    };
}tc_tchdr_s_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  s_lut_write_en:1;
        RBus_UInt32  s_lut_read_en:1;
        RBus_UInt32  s_lut_rw_addr:6;
    };
}tc_tchdr_s_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s_wr_lut_data0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s_wr_lut_data1:10;
    };
}tc_tchdr_s_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s_rd_lut_data0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s_rd_lut_data1:10;
    };
}tc_tchdr_s_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  i_lut_rw_sel:2;
    };
}tc_tchdr_i_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  i_lut_write_en:1;
        RBus_UInt32  i_lut_read_en:1;
        RBus_UInt32  i_lut_rw_addr:6;
    };
}tc_tchdr_i_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_wr_lut_data0:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  i_wr_lut_data1:8;
    };
}tc_tchdr_i_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i_rd_lut_data0:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  i_rd_lut_data1:8;
    };
}tc_tchdr_i_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  p_lut_acc_sel:1;
        RBus_UInt32  p_lut_rw_sel:2;
    };
}tc_tchdr_p_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  p_lut_write_en:1;
        RBus_UInt32  p_lut_read_en:1;
    };
}tc_tchdr_p_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_lut_acc_ready:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  p_lut_rw_addr:6;
    };
}tc_tchdr_p_lut_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  p_fw_lut0_rd_acc:1;
        RBus_UInt32  p_fw_lut0_wr_acc:1;
        RBus_UInt32  p_hw_lut0_rd_acc:1;
        RBus_UInt32  p_fw_lut1_rd_acc:1;
        RBus_UInt32  p_fw_lut1_wr_acc:1;
        RBus_UInt32  p_hw_lut1_rd_acc:1;
    };
}tc_tchdr_p_lut_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p_wr_lut_data0:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  p_wr_lut_data1:14;
    };
}tc_tchdr_p_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  p_rd_lut_data0:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  p_rd_lut_data1:14;
    };
}tc_tchdr_p_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  oct1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  oct0:10;
    };
}tc_tchdr_t_compute0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  oct2:10;
    };
}tc_tchdr_t_compute1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  oct4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  oct3:10;
    };
}tc_tchdr_m_compute0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  oct6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  oct5:10;
    };
}tc_tchdr_m_compute1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dlut_step3:4;
        RBus_UInt32  dlut_step2:4;
        RBus_UInt32  dlut_step1:4;
        RBus_UInt32  dlut_step0:4;
    };
}tc_tchdr_d_lut_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dlut_threshold1:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlut_threshold0:13;
    };
}tc_tchdr_d_lut_threshold0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  dlut_threshold2:13;
    };
}tc_tchdr_d_lut_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  d_lut_rw_sel:2;
    };
}tc_tchdr_d_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  d_lut_write_en:1;
        RBus_UInt32  d_lut_read_en:1;
        RBus_UInt32  d_lut_rw_addr:6;
    };
}tc_tchdr_d_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_wr_lut_data0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  d_wr_lut_data1:12;
    };
}tc_tchdr_d_lut_wr_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_wr_lut_data2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  d_wr_lut_data3:12;
    };
}tc_tchdr_d_lut_wr_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_wr_lut_data4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  d_wr_lut_data5:12;
    };
}tc_tchdr_d_lut_wr_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_rd_lut_data0:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  d_rd_lut_data1:12;
    };
}tc_tchdr_d_lut_rd_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_rd_lut_data2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  d_rd_lut_data3:12;
    };
}tc_tchdr_d_lut_rd_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_rd_lut_data4:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  d_rd_lut_data5:12;
    };
}tc_tchdr_d_lut_rd_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  tc_db_en:1;
        RBus_UInt32  tc_db_read_sel:1;
        RBus_UInt32  tc_db_apply:1;
    };
}tc_tchdr_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tchdr_cdlut_ls:1;
        RBus_UInt32  tchdr_cdlut_rme:1;
        RBus_UInt32  tchdr_cdlut_rm:4;
        RBus_UInt32  res1:10;
        RBus_UInt32  tchdr_cdlut_bist_fail_7:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_6:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_5:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_4:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_3:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_2:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_1:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_0:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_7:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_6:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_5:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_4:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_3:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_2:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_1:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_0:1;
    };
}tc_tchdr_cd_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tchdr_plut_ls:1;
        RBus_UInt32  tchdr_plut_rme:1;
        RBus_UInt32  tchdr_plut_rm:4;
        RBus_UInt32  res1:14;
        RBus_UInt32  tchdr_plut_bist_fail_3:1;
        RBus_UInt32  tchdr_plut_bist_fail_2:1;
        RBus_UInt32  tchdr_plut_bist_fail_1:1;
        RBus_UInt32  tchdr_plut_bist_fail_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  tchdr_plut_drf_bist_fail_3:1;
        RBus_UInt32  tchdr_plut_drf_bist_fail_2:1;
        RBus_UInt32  tchdr_plut_drf_bist_fail_1:1;
        RBus_UInt32  tchdr_plut_drf_bist_fail_0:1;
    };
}tc_tchdr_p_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tchdr_silut_ls:1;
        RBus_UInt32  tchdr_silut_rme:1;
        RBus_UInt32  tchdr_silut_rm:4;
        RBus_UInt32  res1:18;
        RBus_UInt32  tchdr_silut_bist_fail_3:1;
        RBus_UInt32  tchdr_silut_bist_fail_2:1;
        RBus_UInt32  tchdr_silut_bist_fail_1:1;
        RBus_UInt32  tchdr_silut_bist_fail_0:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_3:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_2:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_1:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_0:1;
    };
}tc_tchdr_si_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  clut_dmato3dtable_en:1;
    };
}tc_tc_dmato3dtable_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1806bbb4_31_16:16;
        RBus_UInt32  dummy_d0:16;
    };
}tc_tc_dummy_RBUS;

#else //apply LITTLE_ENDIAN

//======TC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tc_enable:1;
        RBus_UInt32  certification_enable:1;
        RBus_UInt32  tc_certification_bitout:1;
        RBus_UInt32  res1:29;
    };
}tc_tchdr_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  footroom_int:10;
        RBus_UInt32  res1:22;
    };
}tc_tchdr_range_adaptation_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_headroom_int:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  c_headroom_int:10;
        RBus_UInt32  res2:6;
    };
}tc_tchdr_range_adaptation_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_y_limited_range_ratio_int:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  inv_chroma_limited_range_ratio_int:11;
        RBus_UInt32  res2:5;
    };
}tc_tchdr_range_adaptation_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alpha_a:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha_b:13;
        RBus_UInt32  res2:3;
    };
}tc_tchdr_l_compute_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_lut_rw_sel:2;
        RBus_UInt32  res1:30;
    };
}tc_tchdr_c_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_lut_rw_addr:6;
        RBus_UInt32  c_lut_read_en:1;
        RBus_UInt32  c_lut_write_en:1;
        RBus_UInt32  res1:24;
    };
}tc_tchdr_c_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_wr_lut_data1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  c_wr_lut_data0:11;
        RBus_UInt32  res2:5;
    };
}tc_tchdr_c_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_rd_lut_data1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  c_rd_lut_data0:11;
        RBus_UInt32  res2:5;
    };
}tc_tchdr_c_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_lut_rw_sel:2;
        RBus_UInt32  res1:30;
    };
}tc_tchdr_s_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_lut_rw_addr:6;
        RBus_UInt32  s_lut_read_en:1;
        RBus_UInt32  s_lut_write_en:1;
        RBus_UInt32  res1:24;
    };
}tc_tchdr_s_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_wr_lut_data1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s_wr_lut_data0:10;
        RBus_UInt32  res2:6;
    };
}tc_tchdr_s_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_rd_lut_data1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s_rd_lut_data0:10;
        RBus_UInt32  res2:6;
    };
}tc_tchdr_s_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_lut_rw_sel:2;
        RBus_UInt32  res1:30;
    };
}tc_tchdr_i_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_lut_rw_addr:6;
        RBus_UInt32  i_lut_read_en:1;
        RBus_UInt32  i_lut_write_en:1;
        RBus_UInt32  res1:24;
    };
}tc_tchdr_i_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_wr_lut_data1:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  i_wr_lut_data0:8;
        RBus_UInt32  res2:8;
    };
}tc_tchdr_i_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_rd_lut_data1:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  i_rd_lut_data0:8;
        RBus_UInt32  res2:8;
    };
}tc_tchdr_i_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_lut_rw_sel:2;
        RBus_UInt32  p_lut_acc_sel:1;
        RBus_UInt32  res1:29;
    };
}tc_tchdr_p_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_lut_read_en:1;
        RBus_UInt32  p_lut_write_en:1;
        RBus_UInt32  res1:30;
    };
}tc_tchdr_p_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_lut_rw_addr:6;
        RBus_UInt32  res1:25;
        RBus_UInt32  p_lut_acc_ready:1;
    };
}tc_tchdr_p_lut_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_hw_lut1_rd_acc:1;
        RBus_UInt32  p_fw_lut1_wr_acc:1;
        RBus_UInt32  p_fw_lut1_rd_acc:1;
        RBus_UInt32  p_hw_lut0_rd_acc:1;
        RBus_UInt32  p_fw_lut0_wr_acc:1;
        RBus_UInt32  p_fw_lut0_rd_acc:1;
        RBus_UInt32  res1:26;
    };
}tc_tchdr_p_lut_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_wr_lut_data1:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  p_wr_lut_data0:14;
        RBus_UInt32  res2:2;
    };
}tc_tchdr_p_lut_wr_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_rd_lut_data1:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  p_rd_lut_data0:14;
        RBus_UInt32  res2:2;
    };
}tc_tchdr_p_lut_rd_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oct0:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  oct1:10;
        RBus_UInt32  res2:6;
    };
}tc_tchdr_t_compute0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oct2:10;
        RBus_UInt32  res1:22;
    };
}tc_tchdr_t_compute1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oct3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  oct4:10;
        RBus_UInt32  res2:6;
    };
}tc_tchdr_m_compute0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oct5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  oct6:10;
        RBus_UInt32  res2:6;
    };
}tc_tchdr_m_compute1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlut_step0:4;
        RBus_UInt32  dlut_step1:4;
        RBus_UInt32  dlut_step2:4;
        RBus_UInt32  dlut_step3:4;
        RBus_UInt32  res1:16;
    };
}tc_tchdr_d_lut_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlut_threshold0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlut_threshold1:13;
        RBus_UInt32  res2:3;
    };
}tc_tchdr_d_lut_threshold0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlut_threshold2:13;
        RBus_UInt32  res1:19;
    };
}tc_tchdr_d_lut_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_lut_rw_sel:2;
        RBus_UInt32  res1:30;
    };
}tc_tchdr_d_lut_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_lut_rw_addr:6;
        RBus_UInt32  d_lut_read_en:1;
        RBus_UInt32  d_lut_write_en:1;
        RBus_UInt32  res1:24;
    };
}tc_tchdr_d_lut_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_wr_lut_data1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  d_wr_lut_data0:12;
        RBus_UInt32  res2:4;
    };
}tc_tchdr_d_lut_wr_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_wr_lut_data3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  d_wr_lut_data2:12;
        RBus_UInt32  res2:4;
    };
}tc_tchdr_d_lut_wr_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_wr_lut_data5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  d_wr_lut_data4:12;
        RBus_UInt32  res2:4;
    };
}tc_tchdr_d_lut_wr_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_rd_lut_data1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  d_rd_lut_data0:12;
        RBus_UInt32  res2:4;
    };
}tc_tchdr_d_lut_rd_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_rd_lut_data3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  d_rd_lut_data2:12;
        RBus_UInt32  res2:4;
    };
}tc_tchdr_d_lut_rd_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_rd_lut_data5:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  d_rd_lut_data4:12;
        RBus_UInt32  res2:4;
    };
}tc_tchdr_d_lut_rd_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tc_db_apply:1;
        RBus_UInt32  tc_db_read_sel:1;
        RBus_UInt32  tc_db_en:1;
        RBus_UInt32  res1:29;
    };
}tc_tchdr_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_0:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_1:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_2:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_3:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_4:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_5:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_6:1;
        RBus_UInt32  tchdr_cdlut_drf_bist_fail_7:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_0:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_1:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_2:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_3:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_4:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_5:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_6:1;
        RBus_UInt32  tchdr_cdlut_bist_fail_7:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  tchdr_cdlut_rm:4;
        RBus_UInt32  tchdr_cdlut_rme:1;
        RBus_UInt32  tchdr_cdlut_ls:1;
    };
}tc_tchdr_cd_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tchdr_plut_drf_bist_fail_0:1;
        RBus_UInt32  tchdr_plut_drf_bist_fail_1:1;
        RBus_UInt32  tchdr_plut_drf_bist_fail_2:1;
        RBus_UInt32  tchdr_plut_drf_bist_fail_3:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  tchdr_plut_bist_fail_0:1;
        RBus_UInt32  tchdr_plut_bist_fail_1:1;
        RBus_UInt32  tchdr_plut_bist_fail_2:1;
        RBus_UInt32  tchdr_plut_bist_fail_3:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  tchdr_plut_rm:4;
        RBus_UInt32  tchdr_plut_rme:1;
        RBus_UInt32  tchdr_plut_ls:1;
    };
}tc_tchdr_p_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tchdr_silut_drf_bist_fail_0:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_1:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_2:1;
        RBus_UInt32  tchdr_silut_drf_bist_fail_3:1;
        RBus_UInt32  tchdr_silut_bist_fail_0:1;
        RBus_UInt32  tchdr_silut_bist_fail_1:1;
        RBus_UInt32  tchdr_silut_bist_fail_2:1;
        RBus_UInt32  tchdr_silut_bist_fail_3:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  tchdr_silut_rm:4;
        RBus_UInt32  tchdr_silut_rme:1;
        RBus_UInt32  tchdr_silut_ls:1;
    };
}tc_tchdr_si_lut_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clut_dmato3dtable_en:1;
        RBus_UInt32  res1:31;
    };
}tc_tc_dmato3dtable_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_d0:16;
        RBus_UInt32  dummy1806bbb4_31_16:16;
    };
}tc_tc_dummy_RBUS;




#endif 


#endif 
