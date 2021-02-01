/**
* @file Mac5-DesignSpec-D-Domain_Panel_Compensation_OverDrive
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OD_REG_H_
#define _RBUS_OD_REG_H_

#include "rbus_types.h"



//  OD Register Address
#define  OD_OD_CTRL                                                              0x1802CA00
#define  OD_OD_CTRL_reg_addr                                                     "0xB802CA00"
#define  OD_OD_CTRL_reg                                                          0xB802CA00
#define  OD_OD_CTRL_inst_addr                                                    "0x0000"
#define  set_OD_OD_CTRL_reg(data)                                                (*((volatile unsigned int*)OD_OD_CTRL_reg)=data)
#define  get_OD_OD_CTRL_reg                                                      (*((volatile unsigned int*)OD_OD_CTRL_reg))
#define  OD_OD_CTRL_dummy_31_2_shift                                             (2)
#define  OD_OD_CTRL_od_fun_sel_shift                                             (1)
#define  OD_OD_CTRL_od_en_shift                                                  (0)
#define  OD_OD_CTRL_dummy_31_2_mask                                              (0xFFFFFFFC)
#define  OD_OD_CTRL_od_fun_sel_mask                                              (0x00000002)
#define  OD_OD_CTRL_od_en_mask                                                   (0x00000001)
#define  OD_OD_CTRL_dummy_31_2(data)                                             (0xFFFFFFFC&((data)<<2))
#define  OD_OD_CTRL_od_fun_sel(data)                                             (0x00000002&((data)<<1))
#define  OD_OD_CTRL_od_en(data)                                                  (0x00000001&(data))
#define  OD_OD_CTRL_get_dummy_31_2(data)                                         ((0xFFFFFFFC&(data))>>2)
#define  OD_OD_CTRL_get_od_fun_sel(data)                                         ((0x00000002&(data))>>1)
#define  OD_OD_CTRL_get_od_en(data)                                              (0x00000001&(data))

#define  OD_OD_CTRL1                                                             0x1802CA04
#define  OD_OD_CTRL1_reg_addr                                                    "0xB802CA04"
#define  OD_OD_CTRL1_reg                                                         0xB802CA04
#define  OD_OD_CTRL1_inst_addr                                                   "0x0001"
#define  set_OD_OD_CTRL1_reg(data)                                               (*((volatile unsigned int*)OD_OD_CTRL1_reg)=data)
#define  get_OD_OD_CTRL1_reg                                                     (*((volatile unsigned int*)OD_OD_CTRL1_reg))
#define  OD_OD_CTRL1_db_apply_shift                                              (26)
#define  OD_OD_CTRL1_db_read_level_shift                                         (25)
#define  OD_OD_CTRL1_od_en_dbf_en_shift                                          (24)
#define  OD_OD_CTRL1_od_freeze_shift                                             (21)
#define  OD_OD_CTRL1_force_pre_out_shift                                         (20)
#define  OD_OD_CTRL1_compress_ctrl_shift                                         (19)
#define  OD_OD_CTRL1_od_cur_src_sel_shift                                        (17)
#define  OD_OD_CTRL1_rounding_en_shift                                           (16)
#define  OD_OD_CTRL1_od_delta_gain_shift                                         (8)
#define  OD_OD_CTRL1_od_disp_res_shift                                           (4)
#define  OD_OD_CTRL1_od_pdest_en_shift                                           (0)
#define  OD_OD_CTRL1_db_apply_mask                                               (0x04000000)
#define  OD_OD_CTRL1_db_read_level_mask                                          (0x02000000)
#define  OD_OD_CTRL1_od_en_dbf_en_mask                                           (0x01000000)
#define  OD_OD_CTRL1_od_freeze_mask                                              (0x00200000)
#define  OD_OD_CTRL1_force_pre_out_mask                                          (0x00100000)
#define  OD_OD_CTRL1_compress_ctrl_mask                                          (0x00080000)
#define  OD_OD_CTRL1_od_cur_src_sel_mask                                         (0x00020000)
#define  OD_OD_CTRL1_rounding_en_mask                                            (0x00010000)
#define  OD_OD_CTRL1_od_delta_gain_mask                                          (0x00007F00)
#define  OD_OD_CTRL1_od_disp_res_mask                                            (0x00000030)
#define  OD_OD_CTRL1_od_pdest_en_mask                                            (0x00000001)
#define  OD_OD_CTRL1_db_apply(data)                                              (0x04000000&((data)<<26))
#define  OD_OD_CTRL1_db_read_level(data)                                         (0x02000000&((data)<<25))
#define  OD_OD_CTRL1_od_en_dbf_en(data)                                          (0x01000000&((data)<<24))
#define  OD_OD_CTRL1_od_freeze(data)                                             (0x00200000&((data)<<21))
#define  OD_OD_CTRL1_force_pre_out(data)                                         (0x00100000&((data)<<20))
#define  OD_OD_CTRL1_compress_ctrl(data)                                         (0x00080000&((data)<<19))
#define  OD_OD_CTRL1_od_cur_src_sel(data)                                        (0x00020000&((data)<<17))
#define  OD_OD_CTRL1_rounding_en(data)                                           (0x00010000&((data)<<16))
#define  OD_OD_CTRL1_od_delta_gain(data)                                         (0x00007F00&((data)<<8))
#define  OD_OD_CTRL1_od_disp_res(data)                                           (0x00000030&((data)<<4))
#define  OD_OD_CTRL1_od_pdest_en(data)                                           (0x00000001&(data))
#define  OD_OD_CTRL1_get_db_apply(data)                                          ((0x04000000&(data))>>26)
#define  OD_OD_CTRL1_get_db_read_level(data)                                     ((0x02000000&(data))>>25)
#define  OD_OD_CTRL1_get_od_en_dbf_en(data)                                      ((0x01000000&(data))>>24)
#define  OD_OD_CTRL1_get_od_freeze(data)                                         ((0x00200000&(data))>>21)
#define  OD_OD_CTRL1_get_force_pre_out(data)                                     ((0x00100000&(data))>>20)
#define  OD_OD_CTRL1_get_compress_ctrl(data)                                     ((0x00080000&(data))>>19)
#define  OD_OD_CTRL1_get_od_cur_src_sel(data)                                    ((0x00020000&(data))>>17)
#define  OD_OD_CTRL1_get_rounding_en(data)                                       ((0x00010000&(data))>>16)
#define  OD_OD_CTRL1_get_od_delta_gain(data)                                     ((0x00007F00&(data))>>8)
#define  OD_OD_CTRL1_get_od_disp_res(data)                                       ((0x00000030&(data))>>4)
#define  OD_OD_CTRL1_get_od_pdest_en(data)                                       (0x00000001&(data))

#define  OD_OD_LUT_ADDR                                                          0x1802CA08
#define  OD_OD_LUT_ADDR_reg_addr                                                 "0xB802CA08"
#define  OD_OD_LUT_ADDR_reg                                                      0xB802CA08
#define  OD_OD_LUT_ADDR_inst_addr                                                "0x0002"
#define  set_OD_OD_LUT_ADDR_reg(data)                                            (*((volatile unsigned int*)OD_OD_LUT_ADDR_reg)=data)
#define  get_OD_OD_LUT_ADDR_reg                                                  (*((volatile unsigned int*)OD_OD_LUT_ADDR_reg))
#define  OD_OD_LUT_ADDR_table_type_shift                                         (18)
#define  OD_OD_LUT_ADDR_od_lut_ax_en_shift                                       (16)
#define  OD_OD_LUT_ADDR_od_lut_ax_mode_shift                                     (15)
#define  OD_OD_LUT_ADDR_od_lut_adr_mode_shift                                    (14)
#define  OD_OD_LUT_ADDR_od_lut_sel_shift                                         (12)
#define  OD_OD_LUT_ADDR_od_lut_row_addr_shift                                    (6)
#define  OD_OD_LUT_ADDR_od_lut_column_addr_shift                                 (0)
#define  OD_OD_LUT_ADDR_table_type_mask                                          (0x00040000)
#define  OD_OD_LUT_ADDR_od_lut_ax_en_mask                                        (0x00010000)
#define  OD_OD_LUT_ADDR_od_lut_ax_mode_mask                                      (0x00008000)
#define  OD_OD_LUT_ADDR_od_lut_adr_mode_mask                                     (0x00004000)
#define  OD_OD_LUT_ADDR_od_lut_sel_mask                                          (0x00003000)
#define  OD_OD_LUT_ADDR_od_lut_row_addr_mask                                     (0x000007C0)
#define  OD_OD_LUT_ADDR_od_lut_column_addr_mask                                  (0x0000001F)
#define  OD_OD_LUT_ADDR_table_type(data)                                         (0x00040000&((data)<<18))
#define  OD_OD_LUT_ADDR_od_lut_ax_en(data)                                       (0x00010000&((data)<<16))
#define  OD_OD_LUT_ADDR_od_lut_ax_mode(data)                                     (0x00008000&((data)<<15))
#define  OD_OD_LUT_ADDR_od_lut_adr_mode(data)                                    (0x00004000&((data)<<14))
#define  OD_OD_LUT_ADDR_od_lut_sel(data)                                         (0x00003000&((data)<<12))
#define  OD_OD_LUT_ADDR_od_lut_row_addr(data)                                    (0x000007C0&((data)<<6))
#define  OD_OD_LUT_ADDR_od_lut_column_addr(data)                                 (0x0000001F&(data))
#define  OD_OD_LUT_ADDR_get_table_type(data)                                     ((0x00040000&(data))>>18)
#define  OD_OD_LUT_ADDR_get_od_lut_ax_en(data)                                   ((0x00010000&(data))>>16)
#define  OD_OD_LUT_ADDR_get_od_lut_ax_mode(data)                                 ((0x00008000&(data))>>15)
#define  OD_OD_LUT_ADDR_get_od_lut_adr_mode(data)                                ((0x00004000&(data))>>14)
#define  OD_OD_LUT_ADDR_get_od_lut_sel(data)                                     ((0x00003000&(data))>>12)
#define  OD_OD_LUT_ADDR_get_od_lut_row_addr(data)                                ((0x000007C0&(data))>>6)
#define  OD_OD_LUT_ADDR_get_od_lut_column_addr(data)                             (0x0000001F&(data))

#define  OD_OD_LUT_DATA                                                          0x1802CA0C
#define  OD_OD_LUT_DATA_reg_addr                                                 "0xB802CA0C"
#define  OD_OD_LUT_DATA_reg                                                      0xB802CA0C
#define  OD_OD_LUT_DATA_inst_addr                                                "0x0003"
#define  set_OD_OD_LUT_DATA_reg(data)                                            (*((volatile unsigned int*)OD_OD_LUT_DATA_reg)=data)
#define  get_OD_OD_LUT_DATA_reg                                                  (*((volatile unsigned int*)OD_OD_LUT_DATA_reg))
#define  OD_OD_LUT_DATA_od_lut_data_shift                                        (0)
#define  OD_OD_LUT_DATA_od_lut_data_mask                                         (0x0000FFFF)
#define  OD_OD_LUT_DATA_od_lut_data(data)                                        (0x0000FFFF&(data))
#define  OD_OD_LUT_DATA_get_od_lut_data(data)                                    (0x0000FFFF&(data))

#define  OD_od_Noise_reduction_ctrl                                              0x1802CA30
#define  OD_od_Noise_reduction_ctrl_reg_addr                                     "0xB802CA30"
#define  OD_od_Noise_reduction_ctrl_reg                                          0xB802CA30
#define  OD_od_Noise_reduction_ctrl_inst_addr                                    "0x0004"
#define  set_OD_od_Noise_reduction_ctrl_reg(data)                                (*((volatile unsigned int*)OD_od_Noise_reduction_ctrl_reg)=data)
#define  get_OD_od_Noise_reduction_ctrl_reg                                      (*((volatile unsigned int*)OD_od_Noise_reduction_ctrl_reg))
#define  OD_od_Noise_reduction_ctrl_od_nr_mode_shift                             (27)
#define  OD_od_Noise_reduction_ctrl_od_b_nr_en_shift                             (26)
#define  OD_od_Noise_reduction_ctrl_od_g_nr_en_shift                             (25)
#define  OD_od_Noise_reduction_ctrl_od_r_nr_en_shift                             (24)
#define  OD_od_Noise_reduction_ctrl_od_b_nr_thd_shift                            (16)
#define  OD_od_Noise_reduction_ctrl_od_g_nr_thd_shift                            (8)
#define  OD_od_Noise_reduction_ctrl_od_r_nr_thd_shift                            (0)
#define  OD_od_Noise_reduction_ctrl_od_nr_mode_mask                              (0x08000000)
#define  OD_od_Noise_reduction_ctrl_od_b_nr_en_mask                              (0x04000000)
#define  OD_od_Noise_reduction_ctrl_od_g_nr_en_mask                              (0x02000000)
#define  OD_od_Noise_reduction_ctrl_od_r_nr_en_mask                              (0x01000000)
#define  OD_od_Noise_reduction_ctrl_od_b_nr_thd_mask                             (0x003F0000)
#define  OD_od_Noise_reduction_ctrl_od_g_nr_thd_mask                             (0x00003F00)
#define  OD_od_Noise_reduction_ctrl_od_r_nr_thd_mask                             (0x0000003F)
#define  OD_od_Noise_reduction_ctrl_od_nr_mode(data)                             (0x08000000&((data)<<27))
#define  OD_od_Noise_reduction_ctrl_od_b_nr_en(data)                             (0x04000000&((data)<<26))
#define  OD_od_Noise_reduction_ctrl_od_g_nr_en(data)                             (0x02000000&((data)<<25))
#define  OD_od_Noise_reduction_ctrl_od_r_nr_en(data)                             (0x01000000&((data)<<24))
#define  OD_od_Noise_reduction_ctrl_od_b_nr_thd(data)                            (0x003F0000&((data)<<16))
#define  OD_od_Noise_reduction_ctrl_od_g_nr_thd(data)                            (0x00003F00&((data)<<8))
#define  OD_od_Noise_reduction_ctrl_od_r_nr_thd(data)                            (0x0000003F&(data))
#define  OD_od_Noise_reduction_ctrl_get_od_nr_mode(data)                         ((0x08000000&(data))>>27)
#define  OD_od_Noise_reduction_ctrl_get_od_b_nr_en(data)                         ((0x04000000&(data))>>26)
#define  OD_od_Noise_reduction_ctrl_get_od_g_nr_en(data)                         ((0x02000000&(data))>>25)
#define  OD_od_Noise_reduction_ctrl_get_od_r_nr_en(data)                         ((0x01000000&(data))>>24)
#define  OD_od_Noise_reduction_ctrl_get_od_b_nr_thd(data)                        ((0x003F0000&(data))>>16)
#define  OD_od_Noise_reduction_ctrl_get_od_g_nr_thd(data)                        ((0x00003F00&(data))>>8)
#define  OD_od_Noise_reduction_ctrl_get_od_r_nr_thd(data)                        (0x0000003F&(data))

#define  OD_D_CRC_CTRL1                                                          0x1802CB44
#define  OD_D_CRC_CTRL1_reg_addr                                                 "0xB802CB44"
#define  OD_D_CRC_CTRL1_reg                                                      0xB802CB44
#define  OD_D_CRC_CTRL1_inst_addr                                                "0x0005"
#define  set_OD_D_CRC_CTRL1_reg(data)                                            (*((volatile unsigned int*)OD_D_CRC_CTRL1_reg)=data)
#define  get_OD_D_CRC_CTRL1_reg                                                  (*((volatile unsigned int*)OD_D_CRC_CTRL1_reg))
#define  OD_D_CRC_CTRL1_crc_1_conti_shift                                        (1)
#define  OD_D_CRC_CTRL1_crc_1_start_shift                                        (0)
#define  OD_D_CRC_CTRL1_crc_1_conti_mask                                         (0x00000002)
#define  OD_D_CRC_CTRL1_crc_1_start_mask                                         (0x00000001)
#define  OD_D_CRC_CTRL1_crc_1_conti(data)                                        (0x00000002&((data)<<1))
#define  OD_D_CRC_CTRL1_crc_1_start(data)                                        (0x00000001&(data))
#define  OD_D_CRC_CTRL1_get_crc_1_conti(data)                                    ((0x00000002&(data))>>1)
#define  OD_D_CRC_CTRL1_get_crc_1_start(data)                                    (0x00000001&(data))

#define  OD_CRC_RESULT1                                                          0x1802CB48
#define  OD_CRC_RESULT1_reg_addr                                                 "0xB802CB48"
#define  OD_CRC_RESULT1_reg                                                      0xB802CB48
#define  OD_CRC_RESULT1_inst_addr                                                "0x0006"
#define  set_OD_CRC_RESULT1_reg(data)                                            (*((volatile unsigned int*)OD_CRC_RESULT1_reg)=data)
#define  get_OD_CRC_RESULT1_reg                                                  (*((volatile unsigned int*)OD_CRC_RESULT1_reg))
#define  OD_CRC_RESULT1_crc_1_result_shift                                       (0)
#define  OD_CRC_RESULT1_crc_1_result_mask                                        (0xFFFFFFFF)
#define  OD_CRC_RESULT1_crc_1_result(data)                                       (0xFFFFFFFF&(data))
#define  OD_CRC_RESULT1_get_crc_1_result(data)                                   (0xFFFFFFFF&(data))

#define  OD_AccessData_CTRL_PC                                                   0x1802CB54
#define  OD_AccessData_CTRL_PC_reg_addr                                          "0xB802CB54"
#define  OD_AccessData_CTRL_PC_reg                                               0xB802CB54
#define  OD_AccessData_CTRL_PC_inst_addr                                         "0x0007"
#define  set_OD_AccessData_CTRL_PC_reg(data)                                     (*((volatile unsigned int*)OD_AccessData_CTRL_PC_reg)=data)
#define  get_OD_AccessData_CTRL_PC_reg                                           (*((volatile unsigned int*)OD_AccessData_CTRL_PC_reg))
#define  OD_AccessData_CTRL_PC_l_flag_enable_shift                               (8)
#define  OD_AccessData_CTRL_PC_w_en_ctrl_shift                                   (4)
#define  OD_AccessData_CTRL_PC_access_write_en_shift                             (2)
#define  OD_AccessData_CTRL_PC_access_read_en_shift                              (0)
#define  OD_AccessData_CTRL_PC_l_flag_enable_mask                                (0x00000100)
#define  OD_AccessData_CTRL_PC_w_en_ctrl_mask                                    (0x000000F0)
#define  OD_AccessData_CTRL_PC_access_write_en_mask                              (0x00000004)
#define  OD_AccessData_CTRL_PC_access_read_en_mask                               (0x00000001)
#define  OD_AccessData_CTRL_PC_l_flag_enable(data)                               (0x00000100&((data)<<8))
#define  OD_AccessData_CTRL_PC_w_en_ctrl(data)                                   (0x000000F0&((data)<<4))
#define  OD_AccessData_CTRL_PC_access_write_en(data)                             (0x00000004&((data)<<2))
#define  OD_AccessData_CTRL_PC_access_read_en(data)                              (0x00000001&(data))
#define  OD_AccessData_CTRL_PC_get_l_flag_enable(data)                           ((0x00000100&(data))>>8)
#define  OD_AccessData_CTRL_PC_get_w_en_ctrl(data)                               ((0x000000F0&(data))>>4)
#define  OD_AccessData_CTRL_PC_get_access_write_en(data)                         ((0x00000004&(data))>>2)
#define  OD_AccessData_CTRL_PC_get_access_read_en(data)                          (0x00000001&(data))

#define  OD_AccessData_PosCtrl_PC                                                0x1802CB58
#define  OD_AccessData_PosCtrl_PC_reg_addr                                       "0xB802CB58"
#define  OD_AccessData_PosCtrl_PC_reg                                            0xB802CB58
#define  OD_AccessData_PosCtrl_PC_inst_addr                                      "0x0008"
#define  set_OD_AccessData_PosCtrl_PC_reg(data)                                  (*((volatile unsigned int*)OD_AccessData_PosCtrl_PC_reg)=data)
#define  get_OD_AccessData_PosCtrl_PC_reg                                        (*((volatile unsigned int*)OD_AccessData_PosCtrl_PC_reg))
#define  OD_AccessData_PosCtrl_PC_access_starty_shift                            (16)
#define  OD_AccessData_PosCtrl_PC_access_startx_shift                            (0)
#define  OD_AccessData_PosCtrl_PC_access_starty_mask                             (0x0FFF0000)
#define  OD_AccessData_PosCtrl_PC_access_startx_mask                             (0x00000FFF)
#define  OD_AccessData_PosCtrl_PC_access_starty(data)                            (0x0FFF0000&((data)<<16))
#define  OD_AccessData_PosCtrl_PC_access_startx(data)                            (0x00000FFF&(data))
#define  OD_AccessData_PosCtrl_PC_get_access_starty(data)                        ((0x0FFF0000&(data))>>16)
#define  OD_AccessData_PosCtrl_PC_get_access_startx(data)                        (0x00000FFF&(data))

#define  OD_WriteData_DATA_PC                                                    0x1802CB5C
#define  OD_WriteData_DATA_PC_reg_addr                                           "0xB802CB5C"
#define  OD_WriteData_DATA_PC_reg                                                0xB802CB5C
#define  OD_WriteData_DATA_PC_inst_addr                                          "0x0009"
#define  set_OD_WriteData_DATA_PC_reg(data)                                      (*((volatile unsigned int*)OD_WriteData_DATA_PC_reg)=data)
#define  get_OD_WriteData_DATA_PC_reg                                            (*((volatile unsigned int*)OD_WriteData_DATA_PC_reg))
#define  OD_WriteData_DATA_PC_access_v_wdat_shift                                (20)
#define  OD_WriteData_DATA_PC_access_u_wdat_shift                                (10)
#define  OD_WriteData_DATA_PC_access_y_wdat_shift                                (0)
#define  OD_WriteData_DATA_PC_access_v_wdat_mask                                 (0x3FF00000)
#define  OD_WriteData_DATA_PC_access_u_wdat_mask                                 (0x000FFC00)
#define  OD_WriteData_DATA_PC_access_y_wdat_mask                                 (0x000003FF)
#define  OD_WriteData_DATA_PC_access_v_wdat(data)                                (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_PC_access_u_wdat(data)                                (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_PC_access_y_wdat(data)                                (0x000003FF&(data))
#define  OD_WriteData_DATA_PC_get_access_v_wdat(data)                            ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_PC_get_access_u_wdat(data)                            ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_PC_get_access_y_wdat(data)                            (0x000003FF&(data))

#define  OD_WriteData_DATA_1_PC                                                  0x1802CB60
#define  OD_WriteData_DATA_1_PC_reg_addr                                         "0xB802CB60"
#define  OD_WriteData_DATA_1_PC_reg                                              0xB802CB60
#define  OD_WriteData_DATA_1_PC_inst_addr                                        "0x000A"
#define  set_OD_WriteData_DATA_1_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_1_PC_reg)=data)
#define  get_OD_WriteData_DATA_1_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_1_PC_reg))
#define  OD_WriteData_DATA_1_PC_access_v1_wdat_shift                             (20)
#define  OD_WriteData_DATA_1_PC_access_u1_wdat_shift                             (10)
#define  OD_WriteData_DATA_1_PC_access_y1_wdat_shift                             (0)
#define  OD_WriteData_DATA_1_PC_access_v1_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_1_PC_access_u1_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_1_PC_access_y1_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_1_PC_access_v1_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_1_PC_access_u1_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_1_PC_access_y1_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_1_PC_get_access_v1_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_1_PC_get_access_u1_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_1_PC_get_access_y1_wdat(data)                         (0x000003FF&(data))

#define  OD_WriteData_DATA_2_PC                                                  0x1802CB64
#define  OD_WriteData_DATA_2_PC_reg_addr                                         "0xB802CB64"
#define  OD_WriteData_DATA_2_PC_reg                                              0xB802CB64
#define  OD_WriteData_DATA_2_PC_inst_addr                                        "0x000B"
#define  set_OD_WriteData_DATA_2_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_2_PC_reg)=data)
#define  get_OD_WriteData_DATA_2_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_2_PC_reg))
#define  OD_WriteData_DATA_2_PC_access_v2_wdat_shift                             (20)
#define  OD_WriteData_DATA_2_PC_access_u2_wdat_shift                             (10)
#define  OD_WriteData_DATA_2_PC_access_y2_wdat_shift                             (0)
#define  OD_WriteData_DATA_2_PC_access_v2_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_2_PC_access_u2_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_2_PC_access_y2_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_2_PC_access_v2_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_2_PC_access_u2_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_2_PC_access_y2_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_2_PC_get_access_v2_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_2_PC_get_access_u2_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_2_PC_get_access_y2_wdat(data)                         (0x000003FF&(data))

#define  OD_WriteData_DATA_3_PC                                                  0x1802CB68
#define  OD_WriteData_DATA_3_PC_reg_addr                                         "0xB802CB68"
#define  OD_WriteData_DATA_3_PC_reg                                              0xB802CB68
#define  OD_WriteData_DATA_3_PC_inst_addr                                        "0x000C"
#define  set_OD_WriteData_DATA_3_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_3_PC_reg)=data)
#define  get_OD_WriteData_DATA_3_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_3_PC_reg))
#define  OD_WriteData_DATA_3_PC_access_v3_wdat_shift                             (20)
#define  OD_WriteData_DATA_3_PC_access_u3_wdat_shift                             (10)
#define  OD_WriteData_DATA_3_PC_access_y3_wdat_shift                             (0)
#define  OD_WriteData_DATA_3_PC_access_v3_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_3_PC_access_u3_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_3_PC_access_y3_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_3_PC_access_v3_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_3_PC_access_u3_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_3_PC_access_y3_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_3_PC_get_access_v3_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_3_PC_get_access_u3_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_3_PC_get_access_y3_wdat(data)                         (0x000003FF&(data))

#define  OD_WriteData_DATA_4_PC                                                  0x1802CB6C
#define  OD_WriteData_DATA_4_PC_reg_addr                                         "0xB802CB6C"
#define  OD_WriteData_DATA_4_PC_reg                                              0xB802CB6C
#define  OD_WriteData_DATA_4_PC_inst_addr                                        "0x000D"
#define  set_OD_WriteData_DATA_4_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_4_PC_reg)=data)
#define  get_OD_WriteData_DATA_4_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_4_PC_reg))
#define  OD_WriteData_DATA_4_PC_access_v4_wdat_shift                             (20)
#define  OD_WriteData_DATA_4_PC_access_u4_wdat_shift                             (10)
#define  OD_WriteData_DATA_4_PC_access_y4_wdat_shift                             (0)
#define  OD_WriteData_DATA_4_PC_access_v4_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_4_PC_access_u4_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_4_PC_access_y4_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_4_PC_access_v4_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_4_PC_access_u4_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_4_PC_access_y4_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_4_PC_get_access_v4_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_4_PC_get_access_u4_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_4_PC_get_access_y4_wdat(data)                         (0x000003FF&(data))

#define  OD_WriteData_DATA_5_PC                                                  0x1802CB70
#define  OD_WriteData_DATA_5_PC_reg_addr                                         "0xB802CB70"
#define  OD_WriteData_DATA_5_PC_reg                                              0xB802CB70
#define  OD_WriteData_DATA_5_PC_inst_addr                                        "0x000E"
#define  set_OD_WriteData_DATA_5_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_5_PC_reg)=data)
#define  get_OD_WriteData_DATA_5_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_5_PC_reg))
#define  OD_WriteData_DATA_5_PC_access_v5_wdat_shift                             (20)
#define  OD_WriteData_DATA_5_PC_access_u5_wdat_shift                             (10)
#define  OD_WriteData_DATA_5_PC_access_y5_wdat_shift                             (0)
#define  OD_WriteData_DATA_5_PC_access_v5_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_5_PC_access_u5_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_5_PC_access_y5_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_5_PC_access_v5_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_5_PC_access_u5_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_5_PC_access_y5_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_5_PC_get_access_v5_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_5_PC_get_access_u5_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_5_PC_get_access_y5_wdat(data)                         (0x000003FF&(data))

#define  OD_WriteData_DATA_6_PC                                                  0x1802CB74
#define  OD_WriteData_DATA_6_PC_reg_addr                                         "0xB802CB74"
#define  OD_WriteData_DATA_6_PC_reg                                              0xB802CB74
#define  OD_WriteData_DATA_6_PC_inst_addr                                        "0x000F"
#define  set_OD_WriteData_DATA_6_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_6_PC_reg)=data)
#define  get_OD_WriteData_DATA_6_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_6_PC_reg))
#define  OD_WriteData_DATA_6_PC_access_v6_wdat_shift                             (20)
#define  OD_WriteData_DATA_6_PC_access_u6_wdat_shift                             (10)
#define  OD_WriteData_DATA_6_PC_access_y6_wdat_shift                             (0)
#define  OD_WriteData_DATA_6_PC_access_v6_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_6_PC_access_u6_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_6_PC_access_y6_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_6_PC_access_v6_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_6_PC_access_u6_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_6_PC_access_y6_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_6_PC_get_access_v6_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_6_PC_get_access_u6_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_6_PC_get_access_y6_wdat(data)                         (0x000003FF&(data))

#define  OD_WriteData_DATA_7_PC                                                  0x1802CB78
#define  OD_WriteData_DATA_7_PC_reg_addr                                         "0xB802CB78"
#define  OD_WriteData_DATA_7_PC_reg                                              0xB802CB78
#define  OD_WriteData_DATA_7_PC_inst_addr                                        "0x0010"
#define  set_OD_WriteData_DATA_7_PC_reg(data)                                    (*((volatile unsigned int*)OD_WriteData_DATA_7_PC_reg)=data)
#define  get_OD_WriteData_DATA_7_PC_reg                                          (*((volatile unsigned int*)OD_WriteData_DATA_7_PC_reg))
#define  OD_WriteData_DATA_7_PC_access_v7_wdat_shift                             (20)
#define  OD_WriteData_DATA_7_PC_access_u7_wdat_shift                             (10)
#define  OD_WriteData_DATA_7_PC_access_y7_wdat_shift                             (0)
#define  OD_WriteData_DATA_7_PC_access_v7_wdat_mask                              (0x3FF00000)
#define  OD_WriteData_DATA_7_PC_access_u7_wdat_mask                              (0x000FFC00)
#define  OD_WriteData_DATA_7_PC_access_y7_wdat_mask                              (0x000003FF)
#define  OD_WriteData_DATA_7_PC_access_v7_wdat(data)                             (0x3FF00000&((data)<<20))
#define  OD_WriteData_DATA_7_PC_access_u7_wdat(data)                             (0x000FFC00&((data)<<10))
#define  OD_WriteData_DATA_7_PC_access_y7_wdat(data)                             (0x000003FF&(data))
#define  OD_WriteData_DATA_7_PC_get_access_v7_wdat(data)                         ((0x3FF00000&(data))>>20)
#define  OD_WriteData_DATA_7_PC_get_access_u7_wdat(data)                         ((0x000FFC00&(data))>>10)
#define  OD_WriteData_DATA_7_PC_get_access_y7_wdat(data)                         (0x000003FF&(data))

#define  OD_ReadData_DATA_Y1_PC                                                  0x1802CB94
#define  OD_ReadData_DATA_Y1_PC_reg_addr                                         "0xB802CB94"
#define  OD_ReadData_DATA_Y1_PC_reg                                              0xB802CB94
#define  OD_ReadData_DATA_Y1_PC_inst_addr                                        "0x0011"
#define  set_OD_ReadData_DATA_Y1_PC_reg(data)                                    (*((volatile unsigned int*)OD_ReadData_DATA_Y1_PC_reg)=data)
#define  get_OD_ReadData_DATA_Y1_PC_reg                                          (*((volatile unsigned int*)OD_ReadData_DATA_Y1_PC_reg))
#define  OD_ReadData_DATA_Y1_PC_access_y01_shift                                 (16)
#define  OD_ReadData_DATA_Y1_PC_access_y00_shift                                 (0)
#define  OD_ReadData_DATA_Y1_PC_access_y01_mask                                  (0x03FF0000)
#define  OD_ReadData_DATA_Y1_PC_access_y00_mask                                  (0x000003FF)
#define  OD_ReadData_DATA_Y1_PC_access_y01(data)                                 (0x03FF0000&((data)<<16))
#define  OD_ReadData_DATA_Y1_PC_access_y00(data)                                 (0x000003FF&(data))
#define  OD_ReadData_DATA_Y1_PC_get_access_y01(data)                             ((0x03FF0000&(data))>>16)
#define  OD_ReadData_DATA_Y1_PC_get_access_y00(data)                             (0x000003FF&(data))

#define  OD_ReadData_DATA_Y2_PC                                                  0x1802CB98
#define  OD_ReadData_DATA_Y2_PC_reg_addr                                         "0xB802CB98"
#define  OD_ReadData_DATA_Y2_PC_reg                                              0xB802CB98
#define  OD_ReadData_DATA_Y2_PC_inst_addr                                        "0x0012"
#define  set_OD_ReadData_DATA_Y2_PC_reg(data)                                    (*((volatile unsigned int*)OD_ReadData_DATA_Y2_PC_reg)=data)
#define  get_OD_ReadData_DATA_Y2_PC_reg                                          (*((volatile unsigned int*)OD_ReadData_DATA_Y2_PC_reg))
#define  OD_ReadData_DATA_Y2_PC_access_y11_shift                                 (16)
#define  OD_ReadData_DATA_Y2_PC_access_y10_shift                                 (0)
#define  OD_ReadData_DATA_Y2_PC_access_y11_mask                                  (0x03FF0000)
#define  OD_ReadData_DATA_Y2_PC_access_y10_mask                                  (0x000003FF)
#define  OD_ReadData_DATA_Y2_PC_access_y11(data)                                 (0x03FF0000&((data)<<16))
#define  OD_ReadData_DATA_Y2_PC_access_y10(data)                                 (0x000003FF&(data))
#define  OD_ReadData_DATA_Y2_PC_get_access_y11(data)                             ((0x03FF0000&(data))>>16)
#define  OD_ReadData_DATA_Y2_PC_get_access_y10(data)                             (0x000003FF&(data))

#define  OD_ReadData_DATA_C1_PC                                                  0x1802CB9C
#define  OD_ReadData_DATA_C1_PC_reg_addr                                         "0xB802CB9C"
#define  OD_ReadData_DATA_C1_PC_reg                                              0xB802CB9C
#define  OD_ReadData_DATA_C1_PC_inst_addr                                        "0x0013"
#define  set_OD_ReadData_DATA_C1_PC_reg(data)                                    (*((volatile unsigned int*)OD_ReadData_DATA_C1_PC_reg)=data)
#define  get_OD_ReadData_DATA_C1_PC_reg                                          (*((volatile unsigned int*)OD_ReadData_DATA_C1_PC_reg))
#define  OD_ReadData_DATA_C1_PC_access_v00_shift                                 (16)
#define  OD_ReadData_DATA_C1_PC_access_u00_shift                                 (0)
#define  OD_ReadData_DATA_C1_PC_access_v00_mask                                  (0x03FF0000)
#define  OD_ReadData_DATA_C1_PC_access_u00_mask                                  (0x000003FF)
#define  OD_ReadData_DATA_C1_PC_access_v00(data)                                 (0x03FF0000&((data)<<16))
#define  OD_ReadData_DATA_C1_PC_access_u00(data)                                 (0x000003FF&(data))
#define  OD_ReadData_DATA_C1_PC_get_access_v00(data)                             ((0x03FF0000&(data))>>16)
#define  OD_ReadData_DATA_C1_PC_get_access_u00(data)                             (0x000003FF&(data))

#define  OD_ReadData_DATA_C2_PC                                                  0x1802CBA0
#define  OD_ReadData_DATA_C2_PC_reg_addr                                         "0xB802CBA0"
#define  OD_ReadData_DATA_C2_PC_reg                                              0xB802CBA0
#define  OD_ReadData_DATA_C2_PC_inst_addr                                        "0x0014"
#define  set_OD_ReadData_DATA_C2_PC_reg(data)                                    (*((volatile unsigned int*)OD_ReadData_DATA_C2_PC_reg)=data)
#define  get_OD_ReadData_DATA_C2_PC_reg                                          (*((volatile unsigned int*)OD_ReadData_DATA_C2_PC_reg))
#define  OD_ReadData_DATA_C2_PC_access_v01_shift                                 (16)
#define  OD_ReadData_DATA_C2_PC_access_u01_shift                                 (0)
#define  OD_ReadData_DATA_C2_PC_access_v01_mask                                  (0x03FF0000)
#define  OD_ReadData_DATA_C2_PC_access_u01_mask                                  (0x000003FF)
#define  OD_ReadData_DATA_C2_PC_access_v01(data)                                 (0x03FF0000&((data)<<16))
#define  OD_ReadData_DATA_C2_PC_access_u01(data)                                 (0x000003FF&(data))
#define  OD_ReadData_DATA_C2_PC_get_access_v01(data)                             ((0x03FF0000&(data))>>16)
#define  OD_ReadData_DATA_C2_PC_get_access_u01(data)                             (0x000003FF&(data))

#define  OD_ReadData_DATA_C3_PC                                                  0x1802CBA4
#define  OD_ReadData_DATA_C3_PC_reg_addr                                         "0xB802CBA4"
#define  OD_ReadData_DATA_C3_PC_reg                                              0xB802CBA4
#define  OD_ReadData_DATA_C3_PC_inst_addr                                        "0x0015"
#define  set_OD_ReadData_DATA_C3_PC_reg(data)                                    (*((volatile unsigned int*)OD_ReadData_DATA_C3_PC_reg)=data)
#define  get_OD_ReadData_DATA_C3_PC_reg                                          (*((volatile unsigned int*)OD_ReadData_DATA_C3_PC_reg))
#define  OD_ReadData_DATA_C3_PC_access_v10_shift                                 (16)
#define  OD_ReadData_DATA_C3_PC_access_u10_shift                                 (0)
#define  OD_ReadData_DATA_C3_PC_access_v10_mask                                  (0x03FF0000)
#define  OD_ReadData_DATA_C3_PC_access_u10_mask                                  (0x000003FF)
#define  OD_ReadData_DATA_C3_PC_access_v10(data)                                 (0x03FF0000&((data)<<16))
#define  OD_ReadData_DATA_C3_PC_access_u10(data)                                 (0x000003FF&(data))
#define  OD_ReadData_DATA_C3_PC_get_access_v10(data)                             ((0x03FF0000&(data))>>16)
#define  OD_ReadData_DATA_C3_PC_get_access_u10(data)                             (0x000003FF&(data))

#define  OD_ReadData_DATA_C4_PC                                                  0x1802CBA8
#define  OD_ReadData_DATA_C4_PC_reg_addr                                         "0xB802CBA8"
#define  OD_ReadData_DATA_C4_PC_reg                                              0xB802CBA8
#define  OD_ReadData_DATA_C4_PC_inst_addr                                        "0x0016"
#define  set_OD_ReadData_DATA_C4_PC_reg(data)                                    (*((volatile unsigned int*)OD_ReadData_DATA_C4_PC_reg)=data)
#define  get_OD_ReadData_DATA_C4_PC_reg                                          (*((volatile unsigned int*)OD_ReadData_DATA_C4_PC_reg))
#define  OD_ReadData_DATA_C4_PC_access_v11_shift                                 (16)
#define  OD_ReadData_DATA_C4_PC_access_u11_shift                                 (0)
#define  OD_ReadData_DATA_C4_PC_access_v11_mask                                  (0x03FF0000)
#define  OD_ReadData_DATA_C4_PC_access_u11_mask                                  (0x000003FF)
#define  OD_ReadData_DATA_C4_PC_access_v11(data)                                 (0x03FF0000&((data)<<16))
#define  OD_ReadData_DATA_C4_PC_access_u11(data)                                 (0x000003FF&(data))
#define  OD_ReadData_DATA_C4_PC_get_access_v11(data)                             ((0x03FF0000&(data))>>16)
#define  OD_ReadData_DATA_C4_PC_get_access_u11(data)                             (0x000003FF&(data))

#define  OD_OD_BIST                                                              0x1802CBB0
#define  OD_OD_BIST_reg_addr                                                     "0xB802CBB0"
#define  OD_OD_BIST_reg                                                          0xB802CBB0
#define  OD_OD_BIST_inst_addr                                                    "0x0017"
#define  set_OD_OD_BIST_reg(data)                                                (*((volatile unsigned int*)OD_OD_BIST_reg)=data)
#define  get_OD_OD_BIST_reg                                                      (*((volatile unsigned int*)OD_OD_BIST_reg))
#define  OD_OD_BIST_rm_3_shift                                                   (20)
#define  OD_OD_BIST_rm_2_shift                                                   (16)
#define  OD_OD_BIST_rm_1_shift                                                   (12)
#define  OD_OD_BIST_rm_0_shift                                                   (8)
#define  OD_OD_BIST_rme_3_shift                                                  (7)
#define  OD_OD_BIST_rme_2_shift                                                  (6)
#define  OD_OD_BIST_rme_1_shift                                                  (5)
#define  OD_OD_BIST_rme_0_shift                                                  (4)
#define  OD_OD_BIST_ls_3_shift                                                   (3)
#define  OD_OD_BIST_ls_2_shift                                                   (2)
#define  OD_OD_BIST_ls_1_shift                                                   (1)
#define  OD_OD_BIST_ls_0_shift                                                   (0)
#define  OD_OD_BIST_rm_3_mask                                                    (0x00F00000)
#define  OD_OD_BIST_rm_2_mask                                                    (0x000F0000)
#define  OD_OD_BIST_rm_1_mask                                                    (0x0000F000)
#define  OD_OD_BIST_rm_0_mask                                                    (0x00000F00)
#define  OD_OD_BIST_rme_3_mask                                                   (0x00000080)
#define  OD_OD_BIST_rme_2_mask                                                   (0x00000040)
#define  OD_OD_BIST_rme_1_mask                                                   (0x00000020)
#define  OD_OD_BIST_rme_0_mask                                                   (0x00000010)
#define  OD_OD_BIST_ls_3_mask                                                    (0x00000008)
#define  OD_OD_BIST_ls_2_mask                                                    (0x00000004)
#define  OD_OD_BIST_ls_1_mask                                                    (0x00000002)
#define  OD_OD_BIST_ls_0_mask                                                    (0x00000001)
#define  OD_OD_BIST_rm_3(data)                                                   (0x00F00000&((data)<<20))
#define  OD_OD_BIST_rm_2(data)                                                   (0x000F0000&((data)<<16))
#define  OD_OD_BIST_rm_1(data)                                                   (0x0000F000&((data)<<12))
#define  OD_OD_BIST_rm_0(data)                                                   (0x00000F00&((data)<<8))
#define  OD_OD_BIST_rme_3(data)                                                  (0x00000080&((data)<<7))
#define  OD_OD_BIST_rme_2(data)                                                  (0x00000040&((data)<<6))
#define  OD_OD_BIST_rme_1(data)                                                  (0x00000020&((data)<<5))
#define  OD_OD_BIST_rme_0(data)                                                  (0x00000010&((data)<<4))
#define  OD_OD_BIST_ls_3(data)                                                   (0x00000008&((data)<<3))
#define  OD_OD_BIST_ls_2(data)                                                   (0x00000004&((data)<<2))
#define  OD_OD_BIST_ls_1(data)                                                   (0x00000002&((data)<<1))
#define  OD_OD_BIST_ls_0(data)                                                   (0x00000001&(data))
#define  OD_OD_BIST_get_rm_3(data)                                               ((0x00F00000&(data))>>20)
#define  OD_OD_BIST_get_rm_2(data)                                               ((0x000F0000&(data))>>16)
#define  OD_OD_BIST_get_rm_1(data)                                               ((0x0000F000&(data))>>12)
#define  OD_OD_BIST_get_rm_0(data)                                               ((0x00000F00&(data))>>8)
#define  OD_OD_BIST_get_rme_3(data)                                              ((0x00000080&(data))>>7)
#define  OD_OD_BIST_get_rme_2(data)                                              ((0x00000040&(data))>>6)
#define  OD_OD_BIST_get_rme_1(data)                                              ((0x00000020&(data))>>5)
#define  OD_OD_BIST_get_rme_0(data)                                              ((0x00000010&(data))>>4)
#define  OD_OD_BIST_get_ls_3(data)                                               ((0x00000008&(data))>>3)
#define  OD_OD_BIST_get_ls_2(data)                                               ((0x00000004&(data))>>2)
#define  OD_OD_BIST_get_ls_1(data)                                               ((0x00000002&(data))>>1)
#define  OD_OD_BIST_get_ls_0(data)                                               (0x00000001&(data))

#define  OD_OD_BIST_1                                                            0x1802CBB4
#define  OD_OD_BIST_1_reg_addr                                                   "0xB802CBB4"
#define  OD_OD_BIST_1_reg                                                        0xB802CBB4
#define  OD_OD_BIST_1_inst_addr                                                  "0x0018"
#define  set_OD_OD_BIST_1_reg(data)                                              (*((volatile unsigned int*)OD_OD_BIST_1_reg)=data)
#define  get_OD_OD_BIST_1_reg                                                    (*((volatile unsigned int*)OD_OD_BIST_1_reg))
#define  OD_OD_BIST_1_od_drf_fail_5_shift                                        (11)
#define  OD_OD_BIST_1_od_bist_fail_5_shift                                       (10)
#define  OD_OD_BIST_1_od_drf_fail_4_shift                                        (9)
#define  OD_OD_BIST_1_od_bist_fail_4_shift                                       (8)
#define  OD_OD_BIST_1_od_drf_fail_3_shift                                        (7)
#define  OD_OD_BIST_1_od_bist_fail_3_shift                                       (6)
#define  OD_OD_BIST_1_od_drf_fail_2_shift                                        (5)
#define  OD_OD_BIST_1_od_bist_fail_2_shift                                       (4)
#define  OD_OD_BIST_1_od_drf_fail_1_shift                                        (3)
#define  OD_OD_BIST_1_od_bist_fail_1_shift                                       (2)
#define  OD_OD_BIST_1_od_drf_fail_0_shift                                        (1)
#define  OD_OD_BIST_1_od_bist_fail_0_shift                                       (0)
#define  OD_OD_BIST_1_od_drf_fail_5_mask                                         (0x00000800)
#define  OD_OD_BIST_1_od_bist_fail_5_mask                                        (0x00000400)
#define  OD_OD_BIST_1_od_drf_fail_4_mask                                         (0x00000200)
#define  OD_OD_BIST_1_od_bist_fail_4_mask                                        (0x00000100)
#define  OD_OD_BIST_1_od_drf_fail_3_mask                                         (0x00000080)
#define  OD_OD_BIST_1_od_bist_fail_3_mask                                        (0x00000040)
#define  OD_OD_BIST_1_od_drf_fail_2_mask                                         (0x00000020)
#define  OD_OD_BIST_1_od_bist_fail_2_mask                                        (0x00000010)
#define  OD_OD_BIST_1_od_drf_fail_1_mask                                         (0x00000008)
#define  OD_OD_BIST_1_od_bist_fail_1_mask                                        (0x00000004)
#define  OD_OD_BIST_1_od_drf_fail_0_mask                                         (0x00000002)
#define  OD_OD_BIST_1_od_bist_fail_0_mask                                        (0x00000001)
#define  OD_OD_BIST_1_od_drf_fail_5(data)                                        (0x00000800&((data)<<11))
#define  OD_OD_BIST_1_od_bist_fail_5(data)                                       (0x00000400&((data)<<10))
#define  OD_OD_BIST_1_od_drf_fail_4(data)                                        (0x00000200&((data)<<9))
#define  OD_OD_BIST_1_od_bist_fail_4(data)                                       (0x00000100&((data)<<8))
#define  OD_OD_BIST_1_od_drf_fail_3(data)                                        (0x00000080&((data)<<7))
#define  OD_OD_BIST_1_od_bist_fail_3(data)                                       (0x00000040&((data)<<6))
#define  OD_OD_BIST_1_od_drf_fail_2(data)                                        (0x00000020&((data)<<5))
#define  OD_OD_BIST_1_od_bist_fail_2(data)                                       (0x00000010&((data)<<4))
#define  OD_OD_BIST_1_od_drf_fail_1(data)                                        (0x00000008&((data)<<3))
#define  OD_OD_BIST_1_od_bist_fail_1(data)                                       (0x00000004&((data)<<2))
#define  OD_OD_BIST_1_od_drf_fail_0(data)                                        (0x00000002&((data)<<1))
#define  OD_OD_BIST_1_od_bist_fail_0(data)                                       (0x00000001&(data))
#define  OD_OD_BIST_1_get_od_drf_fail_5(data)                                    ((0x00000800&(data))>>11)
#define  OD_OD_BIST_1_get_od_bist_fail_5(data)                                   ((0x00000400&(data))>>10)
#define  OD_OD_BIST_1_get_od_drf_fail_4(data)                                    ((0x00000200&(data))>>9)
#define  OD_OD_BIST_1_get_od_bist_fail_4(data)                                   ((0x00000100&(data))>>8)
#define  OD_OD_BIST_1_get_od_drf_fail_3(data)                                    ((0x00000080&(data))>>7)
#define  OD_OD_BIST_1_get_od_bist_fail_3(data)                                   ((0x00000040&(data))>>6)
#define  OD_OD_BIST_1_get_od_drf_fail_2(data)                                    ((0x00000020&(data))>>5)
#define  OD_OD_BIST_1_get_od_bist_fail_2(data)                                   ((0x00000010&(data))>>4)
#define  OD_OD_BIST_1_get_od_drf_fail_1(data)                                    ((0x00000008&(data))>>3)
#define  OD_OD_BIST_1_get_od_bist_fail_1(data)                                   ((0x00000004&(data))>>2)
#define  OD_OD_BIST_1_get_od_drf_fail_0(data)                                    ((0x00000002&(data))>>1)
#define  OD_OD_BIST_1_get_od_bist_fail_0(data)                                   (0x00000001&(data))

#define  OD_OD_BIST_3                                                            0x1802CBBC
#define  OD_OD_BIST_3_reg_addr                                                   "0xB802CBBC"
#define  OD_OD_BIST_3_reg                                                        0xB802CBBC
#define  OD_OD_BIST_3_inst_addr                                                  "0x0019"
#define  set_OD_OD_BIST_3_reg(data)                                              (*((volatile unsigned int*)OD_OD_BIST_3_reg)=data)
#define  get_OD_OD_BIST_3_reg                                                    (*((volatile unsigned int*)OD_OD_BIST_3_reg))
#define  OD_OD_BIST_3_rm_5_shift                                                 (12)
#define  OD_OD_BIST_3_rm_4_shift                                                 (8)
#define  OD_OD_BIST_3_rme_5_shift                                                (5)
#define  OD_OD_BIST_3_rme_4_shift                                                (4)
#define  OD_OD_BIST_3_ls_5_shift                                                 (1)
#define  OD_OD_BIST_3_ls_4_shift                                                 (0)
#define  OD_OD_BIST_3_rm_5_mask                                                  (0x0000F000)
#define  OD_OD_BIST_3_rm_4_mask                                                  (0x00000F00)
#define  OD_OD_BIST_3_rme_5_mask                                                 (0x00000020)
#define  OD_OD_BIST_3_rme_4_mask                                                 (0x00000010)
#define  OD_OD_BIST_3_ls_5_mask                                                  (0x00000002)
#define  OD_OD_BIST_3_ls_4_mask                                                  (0x00000001)
#define  OD_OD_BIST_3_rm_5(data)                                                 (0x0000F000&((data)<<12))
#define  OD_OD_BIST_3_rm_4(data)                                                 (0x00000F00&((data)<<8))
#define  OD_OD_BIST_3_rme_5(data)                                                (0x00000020&((data)<<5))
#define  OD_OD_BIST_3_rme_4(data)                                                (0x00000010&((data)<<4))
#define  OD_OD_BIST_3_ls_5(data)                                                 (0x00000002&((data)<<1))
#define  OD_OD_BIST_3_ls_4(data)                                                 (0x00000001&(data))
#define  OD_OD_BIST_3_get_rm_5(data)                                             ((0x0000F000&(data))>>12)
#define  OD_OD_BIST_3_get_rm_4(data)                                             ((0x00000F00&(data))>>8)
#define  OD_OD_BIST_3_get_rme_5(data)                                            ((0x00000020&(data))>>5)
#define  OD_OD_BIST_3_get_rme_4(data)                                            ((0x00000010&(data))>>4)
#define  OD_OD_BIST_3_get_ls_5(data)                                             ((0x00000002&(data))>>1)
#define  OD_OD_BIST_3_get_ls_4(data)                                             (0x00000001&(data))

#define  OD_YMODE_CTRL                                                           0x1802CBC0
#define  OD_YMODE_CTRL_reg_addr                                                  "0xB802CBC0"
#define  OD_YMODE_CTRL_reg                                                       0xB802CBC0
#define  OD_YMODE_CTRL_inst_addr                                                 "0x001A"
#define  set_OD_YMODE_CTRL_reg(data)                                             (*((volatile unsigned int*)OD_YMODE_CTRL_reg)=data)
#define  get_OD_YMODE_CTRL_reg                                                   (*((volatile unsigned int*)OD_YMODE_CTRL_reg))
#define  OD_YMODE_CTRL_b_coeff_shift                                             (20)
#define  OD_YMODE_CTRL_g_coeff_shift                                             (12)
#define  OD_YMODE_CTRL_r_coeff_shift                                             (4)
#define  OD_YMODE_CTRL_od_ymode_debug_en_shift                                   (2)
#define  OD_YMODE_CTRL_od_ymode_sat_en_shift                                     (1)
#define  OD_YMODE_CTRL_od_ymode_en_shift                                         (0)
#define  OD_YMODE_CTRL_b_coeff_mask                                              (0x0FF00000)
#define  OD_YMODE_CTRL_g_coeff_mask                                              (0x000FF000)
#define  OD_YMODE_CTRL_r_coeff_mask                                              (0x00000FF0)
#define  OD_YMODE_CTRL_od_ymode_debug_en_mask                                    (0x00000004)
#define  OD_YMODE_CTRL_od_ymode_sat_en_mask                                      (0x00000002)
#define  OD_YMODE_CTRL_od_ymode_en_mask                                          (0x00000001)
#define  OD_YMODE_CTRL_b_coeff(data)                                             (0x0FF00000&((data)<<20))
#define  OD_YMODE_CTRL_g_coeff(data)                                             (0x000FF000&((data)<<12))
#define  OD_YMODE_CTRL_r_coeff(data)                                             (0x00000FF0&((data)<<4))
#define  OD_YMODE_CTRL_od_ymode_debug_en(data)                                   (0x00000004&((data)<<2))
#define  OD_YMODE_CTRL_od_ymode_sat_en(data)                                     (0x00000002&((data)<<1))
#define  OD_YMODE_CTRL_od_ymode_en(data)                                         (0x00000001&(data))
#define  OD_YMODE_CTRL_get_b_coeff(data)                                         ((0x0FF00000&(data))>>20)
#define  OD_YMODE_CTRL_get_g_coeff(data)                                         ((0x000FF000&(data))>>12)
#define  OD_YMODE_CTRL_get_r_coeff(data)                                         ((0x00000FF0&(data))>>4)
#define  OD_YMODE_CTRL_get_od_ymode_debug_en(data)                               ((0x00000004&(data))>>2)
#define  OD_YMODE_CTRL_get_od_ymode_sat_en(data)                                 ((0x00000002&(data))>>1)
#define  OD_YMODE_CTRL_get_od_ymode_en(data)                                     (0x00000001&(data))

#define  OD_YMODE_SAT                                                            0x1802CBC4
#define  OD_YMODE_SAT_reg_addr                                                   "0xB802CBC4"
#define  OD_YMODE_SAT_reg                                                        0xB802CBC4
#define  OD_YMODE_SAT_inst_addr                                                  "0x001B"
#define  set_OD_YMODE_SAT_reg(data)                                              (*((volatile unsigned int*)OD_YMODE_SAT_reg)=data)
#define  get_OD_YMODE_SAT_reg                                                    (*((volatile unsigned int*)OD_YMODE_SAT_reg))
#define  OD_YMODE_SAT_sat_b_diff_th_shift                                        (28)
#define  OD_YMODE_SAT_sat_g_diff_th_shift                                        (24)
#define  OD_YMODE_SAT_sat_r_diff_th_shift                                        (20)
#define  OD_YMODE_SAT_dummy_19_10_shift                                          (10)
#define  OD_YMODE_SAT_sat_y_diff_neg_en_shift                                    (9)
#define  OD_YMODE_SAT_sat_y_diff_pos_en_shift                                    (8)
#define  OD_YMODE_SAT_sat_offset_gain_shift                                      (4)
#define  OD_YMODE_SAT_sat_offset_clamp_en_shift                                  (3)
#define  OD_YMODE_SAT_sat_b_en_shift                                             (2)
#define  OD_YMODE_SAT_sat_g_en_shift                                             (1)
#define  OD_YMODE_SAT_sat_r_en_shift                                             (0)
#define  OD_YMODE_SAT_sat_b_diff_th_mask                                         (0xF0000000)
#define  OD_YMODE_SAT_sat_g_diff_th_mask                                         (0x0F000000)
#define  OD_YMODE_SAT_sat_r_diff_th_mask                                         (0x00F00000)
#define  OD_YMODE_SAT_dummy_19_10_mask                                           (0x000FFC00)
#define  OD_YMODE_SAT_sat_y_diff_neg_en_mask                                     (0x00000200)
#define  OD_YMODE_SAT_sat_y_diff_pos_en_mask                                     (0x00000100)
#define  OD_YMODE_SAT_sat_offset_gain_mask                                       (0x00000070)
#define  OD_YMODE_SAT_sat_offset_clamp_en_mask                                   (0x00000008)
#define  OD_YMODE_SAT_sat_b_en_mask                                              (0x00000004)
#define  OD_YMODE_SAT_sat_g_en_mask                                              (0x00000002)
#define  OD_YMODE_SAT_sat_r_en_mask                                              (0x00000001)
#define  OD_YMODE_SAT_sat_b_diff_th(data)                                        (0xF0000000&((data)<<28))
#define  OD_YMODE_SAT_sat_g_diff_th(data)                                        (0x0F000000&((data)<<24))
#define  OD_YMODE_SAT_sat_r_diff_th(data)                                        (0x00F00000&((data)<<20))
#define  OD_YMODE_SAT_dummy_19_10(data)                                          (0x000FFC00&((data)<<10))
#define  OD_YMODE_SAT_sat_y_diff_neg_en(data)                                    (0x00000200&((data)<<9))
#define  OD_YMODE_SAT_sat_y_diff_pos_en(data)                                    (0x00000100&((data)<<8))
#define  OD_YMODE_SAT_sat_offset_gain(data)                                      (0x00000070&((data)<<4))
#define  OD_YMODE_SAT_sat_offset_clamp_en(data)                                  (0x00000008&((data)<<3))
#define  OD_YMODE_SAT_sat_b_en(data)                                             (0x00000004&((data)<<2))
#define  OD_YMODE_SAT_sat_g_en(data)                                             (0x00000002&((data)<<1))
#define  OD_YMODE_SAT_sat_r_en(data)                                             (0x00000001&(data))
#define  OD_YMODE_SAT_get_sat_b_diff_th(data)                                    ((0xF0000000&(data))>>28)
#define  OD_YMODE_SAT_get_sat_g_diff_th(data)                                    ((0x0F000000&(data))>>24)
#define  OD_YMODE_SAT_get_sat_r_diff_th(data)                                    ((0x00F00000&(data))>>20)
#define  OD_YMODE_SAT_get_dummy_19_10(data)                                      ((0x000FFC00&(data))>>10)
#define  OD_YMODE_SAT_get_sat_y_diff_neg_en(data)                                ((0x00000200&(data))>>9)
#define  OD_YMODE_SAT_get_sat_y_diff_pos_en(data)                                ((0x00000100&(data))>>8)
#define  OD_YMODE_SAT_get_sat_offset_gain(data)                                  ((0x00000070&(data))>>4)
#define  OD_YMODE_SAT_get_sat_offset_clamp_en(data)                              ((0x00000008&(data))>>3)
#define  OD_YMODE_SAT_get_sat_b_en(data)                                         ((0x00000004&(data))>>2)
#define  OD_YMODE_SAT_get_sat_g_en(data)                                         ((0x00000002&(data))>>1)
#define  OD_YMODE_SAT_get_sat_r_en(data)                                         (0x00000001&(data))

#define  OD_YMODE_SAT_Y_R                                                        0x1802CBC8
#define  OD_YMODE_SAT_Y_R_reg_addr                                               "0xB802CBC8"
#define  OD_YMODE_SAT_Y_R_reg                                                    0xB802CBC8
#define  OD_YMODE_SAT_Y_R_inst_addr                                              "0x001C"
#define  set_OD_YMODE_SAT_Y_R_reg(data)                                          (*((volatile unsigned int*)OD_YMODE_SAT_Y_R_reg)=data)
#define  get_OD_YMODE_SAT_Y_R_reg                                                (*((volatile unsigned int*)OD_YMODE_SAT_Y_R_reg))
#define  OD_YMODE_SAT_Y_R_offset_hi_th_r_shift                                   (24)
#define  OD_YMODE_SAT_Y_R_offset_lo_th_r_shift                                   (16)
#define  OD_YMODE_SAT_Y_R_y_diff_hi_th_r_shift                                   (8)
#define  OD_YMODE_SAT_Y_R_y_diff_lo_th_r_shift                                   (0)
#define  OD_YMODE_SAT_Y_R_offset_hi_th_r_mask                                    (0x3F000000)
#define  OD_YMODE_SAT_Y_R_offset_lo_th_r_mask                                    (0x003F0000)
#define  OD_YMODE_SAT_Y_R_y_diff_hi_th_r_mask                                    (0x0000FF00)
#define  OD_YMODE_SAT_Y_R_y_diff_lo_th_r_mask                                    (0x000000FF)
#define  OD_YMODE_SAT_Y_R_offset_hi_th_r(data)                                   (0x3F000000&((data)<<24))
#define  OD_YMODE_SAT_Y_R_offset_lo_th_r(data)                                   (0x003F0000&((data)<<16))
#define  OD_YMODE_SAT_Y_R_y_diff_hi_th_r(data)                                   (0x0000FF00&((data)<<8))
#define  OD_YMODE_SAT_Y_R_y_diff_lo_th_r(data)                                   (0x000000FF&(data))
#define  OD_YMODE_SAT_Y_R_get_offset_hi_th_r(data)                               ((0x3F000000&(data))>>24)
#define  OD_YMODE_SAT_Y_R_get_offset_lo_th_r(data)                               ((0x003F0000&(data))>>16)
#define  OD_YMODE_SAT_Y_R_get_y_diff_hi_th_r(data)                               ((0x0000FF00&(data))>>8)
#define  OD_YMODE_SAT_Y_R_get_y_diff_lo_th_r(data)                               (0x000000FF&(data))

#define  OD_YMODE_SAT_Y_G                                                        0x1802CBCC
#define  OD_YMODE_SAT_Y_G_reg_addr                                               "0xB802CBCC"
#define  OD_YMODE_SAT_Y_G_reg                                                    0xB802CBCC
#define  OD_YMODE_SAT_Y_G_inst_addr                                              "0x001D"
#define  set_OD_YMODE_SAT_Y_G_reg(data)                                          (*((volatile unsigned int*)OD_YMODE_SAT_Y_G_reg)=data)
#define  get_OD_YMODE_SAT_Y_G_reg                                                (*((volatile unsigned int*)OD_YMODE_SAT_Y_G_reg))
#define  OD_YMODE_SAT_Y_G_offset_hi_th_g_shift                                   (24)
#define  OD_YMODE_SAT_Y_G_offset_lo_th_g_shift                                   (16)
#define  OD_YMODE_SAT_Y_G_y_diff_hi_th_g_shift                                   (8)
#define  OD_YMODE_SAT_Y_G_y_diff_lo_th_g_shift                                   (0)
#define  OD_YMODE_SAT_Y_G_offset_hi_th_g_mask                                    (0x3F000000)
#define  OD_YMODE_SAT_Y_G_offset_lo_th_g_mask                                    (0x003F0000)
#define  OD_YMODE_SAT_Y_G_y_diff_hi_th_g_mask                                    (0x0000FF00)
#define  OD_YMODE_SAT_Y_G_y_diff_lo_th_g_mask                                    (0x000000FF)
#define  OD_YMODE_SAT_Y_G_offset_hi_th_g(data)                                   (0x3F000000&((data)<<24))
#define  OD_YMODE_SAT_Y_G_offset_lo_th_g(data)                                   (0x003F0000&((data)<<16))
#define  OD_YMODE_SAT_Y_G_y_diff_hi_th_g(data)                                   (0x0000FF00&((data)<<8))
#define  OD_YMODE_SAT_Y_G_y_diff_lo_th_g(data)                                   (0x000000FF&(data))
#define  OD_YMODE_SAT_Y_G_get_offset_hi_th_g(data)                               ((0x3F000000&(data))>>24)
#define  OD_YMODE_SAT_Y_G_get_offset_lo_th_g(data)                               ((0x003F0000&(data))>>16)
#define  OD_YMODE_SAT_Y_G_get_y_diff_hi_th_g(data)                               ((0x0000FF00&(data))>>8)
#define  OD_YMODE_SAT_Y_G_get_y_diff_lo_th_g(data)                               (0x000000FF&(data))

#define  OD_YMODE_SAT_Y_B                                                        0x1802CBD0
#define  OD_YMODE_SAT_Y_B_reg_addr                                               "0xB802CBD0"
#define  OD_YMODE_SAT_Y_B_reg                                                    0xB802CBD0
#define  OD_YMODE_SAT_Y_B_inst_addr                                              "0x001E"
#define  set_OD_YMODE_SAT_Y_B_reg(data)                                          (*((volatile unsigned int*)OD_YMODE_SAT_Y_B_reg)=data)
#define  get_OD_YMODE_SAT_Y_B_reg                                                (*((volatile unsigned int*)OD_YMODE_SAT_Y_B_reg))
#define  OD_YMODE_SAT_Y_B_offset_hi_th_b_shift                                   (24)
#define  OD_YMODE_SAT_Y_B_offset_lo_th_b_shift                                   (16)
#define  OD_YMODE_SAT_Y_B_y_diff_hi_th_b_shift                                   (8)
#define  OD_YMODE_SAT_Y_B_y_diff_lo_th_b_shift                                   (0)
#define  OD_YMODE_SAT_Y_B_offset_hi_th_b_mask                                    (0x3F000000)
#define  OD_YMODE_SAT_Y_B_offset_lo_th_b_mask                                    (0x003F0000)
#define  OD_YMODE_SAT_Y_B_y_diff_hi_th_b_mask                                    (0x0000FF00)
#define  OD_YMODE_SAT_Y_B_y_diff_lo_th_b_mask                                    (0x000000FF)
#define  OD_YMODE_SAT_Y_B_offset_hi_th_b(data)                                   (0x3F000000&((data)<<24))
#define  OD_YMODE_SAT_Y_B_offset_lo_th_b(data)                                   (0x003F0000&((data)<<16))
#define  OD_YMODE_SAT_Y_B_y_diff_hi_th_b(data)                                   (0x0000FF00&((data)<<8))
#define  OD_YMODE_SAT_Y_B_y_diff_lo_th_b(data)                                   (0x000000FF&(data))
#define  OD_YMODE_SAT_Y_B_get_offset_hi_th_b(data)                               ((0x3F000000&(data))>>24)
#define  OD_YMODE_SAT_Y_B_get_offset_lo_th_b(data)                               ((0x003F0000&(data))>>16)
#define  OD_YMODE_SAT_Y_B_get_y_diff_hi_th_b(data)                               ((0x0000FF00&(data))>>8)
#define  OD_YMODE_SAT_Y_B_get_y_diff_lo_th_b(data)                               (0x000000FF&(data))

#define  OD_YMODE_SAT_Y_SLOPE                                                    0x1802CBD4
#define  OD_YMODE_SAT_Y_SLOPE_reg_addr                                           "0xB802CBD4"
#define  OD_YMODE_SAT_Y_SLOPE_reg                                                0xB802CBD4
#define  OD_YMODE_SAT_Y_SLOPE_inst_addr                                          "0x001F"
#define  set_OD_YMODE_SAT_Y_SLOPE_reg(data)                                      (*((volatile unsigned int*)OD_YMODE_SAT_Y_SLOPE_reg)=data)
#define  get_OD_YMODE_SAT_Y_SLOPE_reg                                            (*((volatile unsigned int*)OD_YMODE_SAT_Y_SLOPE_reg))
#define  OD_YMODE_SAT_Y_SLOPE_offset_slope_g_shift                               (16)
#define  OD_YMODE_SAT_Y_SLOPE_offset_slope_r_shift                               (0)
#define  OD_YMODE_SAT_Y_SLOPE_offset_slope_g_mask                                (0x3FFF0000)
#define  OD_YMODE_SAT_Y_SLOPE_offset_slope_r_mask                                (0x00003FFF)
#define  OD_YMODE_SAT_Y_SLOPE_offset_slope_g(data)                               (0x3FFF0000&((data)<<16))
#define  OD_YMODE_SAT_Y_SLOPE_offset_slope_r(data)                               (0x00003FFF&(data))
#define  OD_YMODE_SAT_Y_SLOPE_get_offset_slope_g(data)                           ((0x3FFF0000&(data))>>16)
#define  OD_YMODE_SAT_Y_SLOPE_get_offset_slope_r(data)                           (0x00003FFF&(data))

#define  OD_YMODE_SAT_Y_SLOPE_2                                                  0x1802CBD8
#define  OD_YMODE_SAT_Y_SLOPE_2_reg_addr                                         "0xB802CBD8"
#define  OD_YMODE_SAT_Y_SLOPE_2_reg                                              0xB802CBD8
#define  OD_YMODE_SAT_Y_SLOPE_2_inst_addr                                        "0x0020"
#define  set_OD_YMODE_SAT_Y_SLOPE_2_reg(data)                                    (*((volatile unsigned int*)OD_YMODE_SAT_Y_SLOPE_2_reg)=data)
#define  get_OD_YMODE_SAT_Y_SLOPE_2_reg                                          (*((volatile unsigned int*)OD_YMODE_SAT_Y_SLOPE_2_reg))
#define  OD_YMODE_SAT_Y_SLOPE_2_dummy_31_14_shift                                (14)
#define  OD_YMODE_SAT_Y_SLOPE_2_offset_slope_b_shift                             (0)
#define  OD_YMODE_SAT_Y_SLOPE_2_dummy_31_14_mask                                 (0xFFFFC000)
#define  OD_YMODE_SAT_Y_SLOPE_2_offset_slope_b_mask                              (0x00003FFF)
#define  OD_YMODE_SAT_Y_SLOPE_2_dummy_31_14(data)                                (0xFFFFC000&((data)<<14))
#define  OD_YMODE_SAT_Y_SLOPE_2_offset_slope_b(data)                             (0x00003FFF&(data))
#define  OD_YMODE_SAT_Y_SLOPE_2_get_dummy_31_14(data)                            ((0xFFFFC000&(data))>>14)
#define  OD_YMODE_SAT_Y_SLOPE_2_get_offset_slope_b(data)                         (0x00003FFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802ca00_31_2:30;
        RBus_UInt32  od_fun_sel:1;
        RBus_UInt32  od_en:1;
    };
}od_od_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  od_en_dbf_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_freeze:1;
        RBus_UInt32  force_pre_out:1;
        RBus_UInt32  compress_ctrl:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  od_cur_src_sel:1;
        RBus_UInt32  rounding_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  od_delta_gain:7;
        RBus_UInt32  res5:2;
        RBus_UInt32  od_disp_res:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  od_pdest_en:1;
    };
}od_od_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  table_type:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_lut_ax_en:1;
        RBus_UInt32  od_lut_ax_mode:1;
        RBus_UInt32  od_lut_adr_mode:1;
        RBus_UInt32  od_lut_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  od_lut_row_addr:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  od_lut_column_addr:5;
    };
}od_od_lut_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  od_lut_data:16;
    };
}od_od_lut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  od_nr_mode:1;
        RBus_UInt32  od_b_nr_en:1;
        RBus_UInt32  od_g_nr_en:1;
        RBus_UInt32  od_r_nr_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_b_nr_thd:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  od_g_nr_thd:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  od_r_nr_thd:6;
    };
}od_od_noise_reduction_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  crc_1_conti:1;
        RBus_UInt32  crc_1_start:1;
    };
}od_d_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_1_result:32;
    };
}od_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  l_flag_enable:1;
        RBus_UInt32  w_en_ctrl:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  access_write_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  access_read_en:1;
    };
}od_accessdata_ctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  access_starty:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  access_startx:12;
    };
}od_accessdata_posctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v_wdat:10;
        RBus_UInt32  access_u_wdat:10;
        RBus_UInt32  access_y_wdat:10;
    };
}od_writedata_data_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v1_wdat:10;
        RBus_UInt32  access_u1_wdat:10;
        RBus_UInt32  access_y1_wdat:10;
    };
}od_writedata_data_1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v2_wdat:10;
        RBus_UInt32  access_u2_wdat:10;
        RBus_UInt32  access_y2_wdat:10;
    };
}od_writedata_data_2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v3_wdat:10;
        RBus_UInt32  access_u3_wdat:10;
        RBus_UInt32  access_y3_wdat:10;
    };
}od_writedata_data_3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v4_wdat:10;
        RBus_UInt32  access_u4_wdat:10;
        RBus_UInt32  access_y4_wdat:10;
    };
}od_writedata_data_4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v5_wdat:10;
        RBus_UInt32  access_u5_wdat:10;
        RBus_UInt32  access_y5_wdat:10;
    };
}od_writedata_data_5_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v6_wdat:10;
        RBus_UInt32  access_u6_wdat:10;
        RBus_UInt32  access_y6_wdat:10;
    };
}od_writedata_data_6_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  access_v7_wdat:10;
        RBus_UInt32  access_u7_wdat:10;
        RBus_UInt32  access_y7_wdat:10;
    };
}od_writedata_data_7_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_y00:10;
    };
}od_readdata_data_y1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_y10:10;
    };
}od_readdata_data_y2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u00:10;
    };
}od_readdata_data_c1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u01:10;
    };
}od_readdata_data_c2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u10:10;
    };
}od_readdata_data_c3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  access_u11:10;
    };
}od_readdata_data_c4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_0:1;
    };
}od_od_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  od_drf_fail_5:1;
        RBus_UInt32  od_bist_fail_5:1;
        RBus_UInt32  od_drf_fail_4:1;
        RBus_UInt32  od_bist_fail_4:1;
        RBus_UInt32  od_drf_fail_3:1;
        RBus_UInt32  od_bist_fail_3:1;
        RBus_UInt32  od_drf_fail_2:1;
        RBus_UInt32  od_bist_fail_2:1;
        RBus_UInt32  od_drf_fail_1:1;
        RBus_UInt32  od_bist_fail_1:1;
        RBus_UInt32  od_drf_fail_0:1;
        RBus_UInt32  od_bist_fail_0:1;
    };
}od_od_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ls_5:1;
        RBus_UInt32  ls_4:1;
    };
}od_od_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  b_coeff:8;
        RBus_UInt32  g_coeff:8;
        RBus_UInt32  r_coeff:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_ymode_debug_en:1;
        RBus_UInt32  od_ymode_sat_en:1;
        RBus_UInt32  od_ymode_en:1;
    };
}od_ymode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_b_diff_th:4;
        RBus_UInt32  sat_g_diff_th:4;
        RBus_UInt32  sat_r_diff_th:4;
        RBus_UInt32  dummy1802cbc4_19_10:10;
        RBus_UInt32  sat_y_diff_neg_en:1;
        RBus_UInt32  sat_y_diff_pos_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sat_offset_gain:3;
        RBus_UInt32  sat_offset_clamp_en:1;
        RBus_UInt32  sat_b_en:1;
        RBus_UInt32  sat_g_en:1;
        RBus_UInt32  sat_r_en:1;
    };
}od_ymode_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_hi_th_r:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  offset_lo_th_r:6;
        RBus_UInt32  y_diff_hi_th_r:8;
        RBus_UInt32  y_diff_lo_th_r:8;
    };
}od_ymode_sat_y_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_hi_th_g:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  offset_lo_th_g:6;
        RBus_UInt32  y_diff_hi_th_g:8;
        RBus_UInt32  y_diff_lo_th_g:8;
    };
}od_ymode_sat_y_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_hi_th_b:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  offset_lo_th_b:6;
        RBus_UInt32  y_diff_hi_th_b:8;
        RBus_UInt32  y_diff_lo_th_b:8;
    };
}od_ymode_sat_y_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_slope_g:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  offset_slope_r:14;
    };
}od_ymode_sat_y_slope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802cbd8_31_14:18;
        RBus_UInt32  offset_slope_b:14;
    };
}od_ymode_sat_y_slope_2_RBUS;

#else //apply LITTLE_ENDIAN

//======OD register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_en:1;
        RBus_UInt32  od_fun_sel:1;
        RBus_UInt32  dummy1802ca00_31_2:30;
    };
}od_od_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_pdest_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  od_disp_res:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_delta_gain:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  rounding_en:1;
        RBus_UInt32  od_cur_src_sel:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  compress_ctrl:1;
        RBus_UInt32  force_pre_out:1;
        RBus_UInt32  od_freeze:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  od_en_dbf_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  res6:5;
    };
}od_od_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_lut_column_addr:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  od_lut_row_addr:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  od_lut_sel:2;
        RBus_UInt32  od_lut_adr_mode:1;
        RBus_UInt32  od_lut_ax_mode:1;
        RBus_UInt32  od_lut_ax_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  table_type:1;
        RBus_UInt32  res4:13;
    };
}od_od_lut_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_lut_data:16;
        RBus_UInt32  res1:16;
    };
}od_od_lut_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_r_nr_thd:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  od_g_nr_thd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  od_b_nr_thd:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  od_r_nr_en:1;
        RBus_UInt32  od_g_nr_en:1;
        RBus_UInt32  od_b_nr_en:1;
        RBus_UInt32  od_nr_mode:1;
        RBus_UInt32  res4:4;
    };
}od_od_noise_reduction_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_1_start:1;
        RBus_UInt32  crc_1_conti:1;
        RBus_UInt32  res1:30;
    };
}od_d_crc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_1_result:32;
    };
}od_crc_result1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_read_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  access_write_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  w_en_ctrl:4;
        RBus_UInt32  l_flag_enable:1;
        RBus_UInt32  res3:23;
    };
}od_accessdata_ctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_startx:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  access_starty:12;
        RBus_UInt32  res2:4;
    };
}od_accessdata_posctrl_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y_wdat:10;
        RBus_UInt32  access_u_wdat:10;
        RBus_UInt32  access_v_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y1_wdat:10;
        RBus_UInt32  access_u1_wdat:10;
        RBus_UInt32  access_v1_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y2_wdat:10;
        RBus_UInt32  access_u2_wdat:10;
        RBus_UInt32  access_v2_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y3_wdat:10;
        RBus_UInt32  access_u3_wdat:10;
        RBus_UInt32  access_v3_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y4_wdat:10;
        RBus_UInt32  access_u4_wdat:10;
        RBus_UInt32  access_v4_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y5_wdat:10;
        RBus_UInt32  access_u5_wdat:10;
        RBus_UInt32  access_v5_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_5_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y6_wdat:10;
        RBus_UInt32  access_u6_wdat:10;
        RBus_UInt32  access_v6_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_6_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y7_wdat:10;
        RBus_UInt32  access_u7_wdat:10;
        RBus_UInt32  access_v7_wdat:10;
        RBus_UInt32  res1:2;
    };
}od_writedata_data_7_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y01:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_y1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_y11:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_y2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v00:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c1_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v01:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c2_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v10:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c3_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  access_v11:10;
        RBus_UInt32  res2:6;
    };
}od_readdata_data_c4_pc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_0:1;
        RBus_UInt32  ls_1:1;
        RBus_UInt32  ls_2:1;
        RBus_UInt32  ls_3:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  res1:8;
    };
}od_od_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_bist_fail_0:1;
        RBus_UInt32  od_drf_fail_0:1;
        RBus_UInt32  od_bist_fail_1:1;
        RBus_UInt32  od_drf_fail_1:1;
        RBus_UInt32  od_bist_fail_2:1;
        RBus_UInt32  od_drf_fail_2:1;
        RBus_UInt32  od_bist_fail_3:1;
        RBus_UInt32  od_drf_fail_3:1;
        RBus_UInt32  od_bist_fail_4:1;
        RBus_UInt32  od_drf_fail_4:1;
        RBus_UInt32  od_bist_fail_5:1;
        RBus_UInt32  od_drf_fail_5:1;
        RBus_UInt32  res1:20;
    };
}od_od_bist_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ls_4:1;
        RBus_UInt32  ls_5:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  res3:16;
    };
}od_od_bist_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  od_ymode_en:1;
        RBus_UInt32  od_ymode_sat_en:1;
        RBus_UInt32  od_ymode_debug_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_coeff:8;
        RBus_UInt32  g_coeff:8;
        RBus_UInt32  b_coeff:8;
        RBus_UInt32  res2:4;
    };
}od_ymode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sat_r_en:1;
        RBus_UInt32  sat_g_en:1;
        RBus_UInt32  sat_b_en:1;
        RBus_UInt32  sat_offset_clamp_en:1;
        RBus_UInt32  sat_offset_gain:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  sat_y_diff_pos_en:1;
        RBus_UInt32  sat_y_diff_neg_en:1;
        RBus_UInt32  dummy1802cbc4_19_10:10;
        RBus_UInt32  sat_r_diff_th:4;
        RBus_UInt32  sat_g_diff_th:4;
        RBus_UInt32  sat_b_diff_th:4;
    };
}od_ymode_sat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_diff_lo_th_r:8;
        RBus_UInt32  y_diff_hi_th_r:8;
        RBus_UInt32  offset_lo_th_r:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_hi_th_r:6;
        RBus_UInt32  res2:2;
    };
}od_ymode_sat_y_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_diff_lo_th_g:8;
        RBus_UInt32  y_diff_hi_th_g:8;
        RBus_UInt32  offset_lo_th_g:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_hi_th_g:6;
        RBus_UInt32  res2:2;
    };
}od_ymode_sat_y_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_diff_lo_th_b:8;
        RBus_UInt32  y_diff_hi_th_b:8;
        RBus_UInt32  offset_lo_th_b:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_hi_th_b:6;
        RBus_UInt32  res2:2;
    };
}od_ymode_sat_y_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offset_slope_r:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_slope_g:14;
        RBus_UInt32  res2:2;
    };
}od_ymode_sat_y_slope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offset_slope_b:14;
        RBus_UInt32  dummy1802cbd8_31_14:18;
    };
}od_ymode_sat_y_slope_2_RBUS;




#endif 


#endif 
