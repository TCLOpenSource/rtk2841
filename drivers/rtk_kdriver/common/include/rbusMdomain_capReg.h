/**
* @file rbusMdomain_capReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MDOMAIN_CAP_REG_H_
#define _RBUS_MDOMAIN_CAP_REG_H_

//#include "rbusTypes.h"
#include "rbusTypes.h"



//  MDOMAIN_CAP Register Address
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num                                            0x18027200
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_reg_addr                                   "0xB8027200"
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_reg                                        0xB8027200
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_inst_addr                                  "0x0000"
#define  set_MDOMAIN_CAP_DDR_In1WTLVL_Num_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1WTLVL_Num_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1WTLVL_Num_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1WTLVL_Num_reg))
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_in1_wtlvl_shift                            (16)
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_in1_write_num_shift                        (0)
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_in1_wtlvl_mask                             (0x01FF0000)
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_in1_write_num_mask                         (0x0000FFFF)
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_in1_wtlvl(data)                            (0x01FF0000&((data)<<16))
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_in1_write_num(data)                        (0x0000FFFF&(data))
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_get_in1_wtlvl(data)                        ((0x01FF0000&(data))>>16)
#define  MDOMAIN_CAP_DDR_In1WTLVL_Num_get_in1_write_num(data)                    (0x0000FFFF&(data))

#define  MDOMAIN_CAP_DDR_In1WrLen_Rem                                            0x18027204
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_reg_addr                                   "0xB8027204"
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_reg                                        0xB8027204
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_inst_addr                                  "0x0001"
#define  set_MDOMAIN_CAP_DDR_In1WrLen_Rem_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1WrLen_Rem_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1WrLen_Rem_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1WrLen_Rem_reg))
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_in1_wrlen_shift                            (8)
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_in1_write_remain_shift                     (0)
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_in1_wrlen_mask                             (0x0000FF00)
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_in1_write_remain_mask                      (0x000000FF)
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_in1_wrlen(data)                            (0x0000FF00&((data)<<8))
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_in1_write_remain(data)                     (0x000000FF&(data))
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_get_in1_wrlen(data)                        ((0x0000FF00&(data))>>8)
#define  MDOMAIN_CAP_DDR_In1WrLen_Rem_get_in1_write_remain(data)                 (0x000000FF&(data))

#define  MDOMAIN_CAP_DDR_In1Addr                                                 0x18027208
#define  MDOMAIN_CAP_DDR_In1Addr_reg_addr                                        "0xB8027208"
#define  MDOMAIN_CAP_DDR_In1Addr_reg                                             0xB8027208
#define  MDOMAIN_CAP_DDR_In1Addr_inst_addr                                       "0x0002"
#define  set_MDOMAIN_CAP_DDR_In1Addr_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1Addr_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1Addr_reg                                         (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1Addr_reg))
#define  MDOMAIN_CAP_DDR_In1Addr_in1_wr_mem_start_shift                          (3)
#define  MDOMAIN_CAP_DDR_In1Addr_in1_wr_mem_start_mask                           (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In1Addr_in1_wr_mem_start(data)                          (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In1Addr_get_in1_wr_mem_start(data)                      ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In1LineStep                                             0x1802720C
#define  MDOMAIN_CAP_DDR_In1LineStep_reg_addr                                    "0xB802720C"
#define  MDOMAIN_CAP_DDR_In1LineStep_reg                                         0xB802720C
#define  MDOMAIN_CAP_DDR_In1LineStep_inst_addr                                   "0x0003"
#define  set_MDOMAIN_CAP_DDR_In1LineStep_reg(data)                               (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1LineStep_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1LineStep_reg                                     (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1LineStep_reg))
#define  MDOMAIN_CAP_DDR_In1LineStep_in1_line_step_shift                         (3)
#define  MDOMAIN_CAP_DDR_In1LineStep_in1_line_step_mask                          (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In1LineStep_in1_line_step(data)                         (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In1LineStep_get_in1_line_step(data)                     ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In1BlkStep                                              0x18027210
#define  MDOMAIN_CAP_DDR_In1BlkStep_reg_addr                                     "0xB8027210"
#define  MDOMAIN_CAP_DDR_In1BlkStep_reg                                          0xB8027210
#define  MDOMAIN_CAP_DDR_In1BlkStep_inst_addr                                    "0x0004"
#define  set_MDOMAIN_CAP_DDR_In1BlkStep_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1BlkStep_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1BlkStep_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1BlkStep_reg))
#define  MDOMAIN_CAP_DDR_In1BlkStep_in1_block_step_shift                         (3)
#define  MDOMAIN_CAP_DDR_In1BlkStep_in1_block_step_mask                          (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In1BlkStep_in1_block_step(data)                         (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In1BlkStep_get_in1_block_step(data)                     ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In1_2ndAddr                                             0x18027214
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_reg_addr                                    "0xB8027214"
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_reg                                         0xB8027214
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_inst_addr                                   "0x0005"
#define  set_MDOMAIN_CAP_DDR_In1_2ndAddr_reg(data)                               (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1_2ndAddr_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1_2ndAddr_reg                                     (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1_2ndAddr_reg))
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_in1_sec_bl_shift                            (3)
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_in1_sec_bl_mask                             (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_in1_sec_bl(data)                            (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In1_2ndAddr_get_in1_sec_bl(data)                        ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In1_3rdAddr                                             0x18027218
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_reg_addr                                    "0xB8027218"
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_reg                                         0xB8027218
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_inst_addr                                   "0x0006"
#define  set_MDOMAIN_CAP_DDR_In1_3rdAddr_reg(data)                               (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1_3rdAddr_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1_3rdAddr_reg                                     (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1_3rdAddr_reg))
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_in1_third_bl_shift                          (3)
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_in1_third_bl_mask                           (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_in1_third_bl(data)                          (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In1_3rdAddr_get_in1_third_bl(data)                      ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In1LineNum                                              0x1802721C
#define  MDOMAIN_CAP_DDR_In1LineNum_reg_addr                                     "0xB802721C"
#define  MDOMAIN_CAP_DDR_In1LineNum_reg                                          0xB802721C
#define  MDOMAIN_CAP_DDR_In1LineNum_inst_addr                                    "0x0007"
#define  set_MDOMAIN_CAP_DDR_In1LineNum_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1LineNum_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1LineNum_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1LineNum_reg))
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_zero_shift                               (17)
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_frame_access_mode_shift                  (16)
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_line_number_shift                        (0)
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_zero_mask                                (0x00020000)
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_frame_access_mode_mask                   (0x00010000)
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_line_number_mask                         (0x00001FFF)
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_zero(data)                               (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_frame_access_mode(data)                  (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_DDR_In1LineNum_in1_line_number(data)                        (0x00001FFF&(data))
#define  MDOMAIN_CAP_DDR_In1LineNum_get_in1_zero(data)                           ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_DDR_In1LineNum_get_in1_frame_access_mode(data)              ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_DDR_In1LineNum_get_in1_line_number(data)                    (0x00001FFF&(data))

#define  MDOMAIN_CAP_DDR_In1Ctrl                                                 0x18027220
#define  MDOMAIN_CAP_DDR_In1Ctrl_reg_addr                                        "0xB8027220"
#define  MDOMAIN_CAP_DDR_In1Ctrl_reg                                             0xB8027220
#define  MDOMAIN_CAP_DDR_In1Ctrl_inst_addr                                       "0x0008"
#define  set_MDOMAIN_CAP_DDR_In1Ctrl_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1Ctrl_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1Ctrl_reg                                         (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1Ctrl_reg))
#define  MDOMAIN_CAP_DDR_In1Ctrl_dispm_ddr_checksum_en_shift                     (31)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_unfreeze_wait_shift                         (21)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_auto_unfreeze_shift                         (20)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_freeze_control_shift                        (17)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_bad_edit_suppression_shift                  (16)
#define  MDOMAIN_CAP_DDR_In1Ctrl_dispm_dbg_sel_shift                             (12)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_l_flag_inv_shift                            (11)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_rm_r_vs_en_shift                            (10)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_shift                        (8)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_merge_enable_shift                          (6)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_shift                         (5)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_block_free_shift                            (4)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_single_buffer_select_shift                  (2)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_freeze_enable_shift                         (1)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_en_vs_rst_shift                             (0)
#define  MDOMAIN_CAP_DDR_In1Ctrl_dispm_ddr_checksum_en_mask                      (0x80000000)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_unfreeze_wait_mask                          (0x00E00000)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_auto_unfreeze_mask                          (0x00100000)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_freeze_control_mask                         (0x00020000)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_bad_edit_suppression_mask                   (0x00010000)
#define  MDOMAIN_CAP_DDR_In1Ctrl_dispm_dbg_sel_mask                              (0x0000F000)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_l_flag_inv_mask                             (0x00000800)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_rm_r_vs_en_mask                             (0x00000400)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en_mask                         (0x00000100)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_merge_enable_mask                           (0x00000040)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable_mask                          (0x00000020)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_block_free_mask                             (0x00000010)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_single_buffer_select_mask                   (0x0000000C)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_freeze_enable_mask                          (0x00000002)
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_en_vs_rst_mask                              (0x00000001)
#define  MDOMAIN_CAP_DDR_In1Ctrl_dispm_ddr_checksum_en(data)                     (0x80000000&((data)<<31))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_unfreeze_wait(data)                         (0x00E00000&((data)<<21))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_auto_unfreeze(data)                         (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_freeze_control(data)                        (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_bad_edit_suppression(data)                  (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_DDR_In1Ctrl_dispm_dbg_sel(data)                             (0x0000F000&((data)<<12))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_l_flag_inv(data)                            (0x00000800&((data)<<11))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_rm_r_vs_en(data)                            (0x00000400&((data)<<10))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_v_flip_3buf_en(data)                        (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_merge_enable(data)                          (0x00000040&((data)<<6))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_double_enable(data)                         (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_block_free(data)                            (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_single_buffer_select(data)                  (0x0000000C&((data)<<2))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_freeze_enable(data)                         (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_DDR_In1Ctrl_in1_en_vs_rst(data)                             (0x00000001&(data))
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_dispm_ddr_checksum_en(data)                 ((0x80000000&(data))>>31)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_unfreeze_wait(data)                     ((0x00E00000&(data))>>21)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_auto_unfreeze(data)                     ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_freeze_control(data)                    ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_bad_edit_suppression(data)              ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_dispm_dbg_sel(data)                         ((0x0000F000&(data))>>12)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_l_flag_inv(data)                        ((0x00000800&(data))>>11)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_rm_r_vs_en(data)                        ((0x00000400&(data))>>10)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_v_flip_3buf_en(data)                    ((0x00000100&(data))>>8)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_merge_enable(data)                      ((0x00000040&(data))>>6)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_double_enable(data)                     ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_block_free(data)                        ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_single_buffer_select(data)              ((0x0000000C&(data))>>2)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_freeze_enable(data)                     ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_DDR_In1Ctrl_get_in1_en_vs_rst(data)                         (0x00000001&(data))

#define  MDOMAIN_CAP_DDR_In1Status                                               0x18027224
#define  MDOMAIN_CAP_DDR_In1Status_reg_addr                                      "0xB8027224"
#define  MDOMAIN_CAP_DDR_In1Status_reg                                           0xB8027224
#define  MDOMAIN_CAP_DDR_In1Status_inst_addr                                     "0x0009"
#define  set_MDOMAIN_CAP_DDR_In1Status_reg(data)                                 (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1Status_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In1Status_reg                                       (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In1Status_reg))
#define  MDOMAIN_CAP_DDR_In1Status_in1_block_select_shift                        (6)
#define  MDOMAIN_CAP_DDR_In1Status_in1_freeze_ok_shift                           (5)
#define  MDOMAIN_CAP_DDR_In1Status_in1_field_polarity_error_shift                (4)
#define  MDOMAIN_CAP_DDR_In1Status_in1_field_polarity_status_shift               (0)
#define  MDOMAIN_CAP_DDR_In1Status_in1_block_select_mask                         (0x000000C0)
#define  MDOMAIN_CAP_DDR_In1Status_in1_freeze_ok_mask                            (0x00000020)
#define  MDOMAIN_CAP_DDR_In1Status_in1_field_polarity_error_mask                 (0x00000010)
#define  MDOMAIN_CAP_DDR_In1Status_in1_field_polarity_status_mask                (0x0000000F)
#define  MDOMAIN_CAP_DDR_In1Status_in1_block_select(data)                        (0x000000C0&((data)<<6))
#define  MDOMAIN_CAP_DDR_In1Status_in1_freeze_ok(data)                           (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_DDR_In1Status_in1_field_polarity_error(data)                (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_DDR_In1Status_in1_field_polarity_status(data)               (0x0000000F&(data))
#define  MDOMAIN_CAP_DDR_In1Status_get_in1_block_select(data)                    ((0x000000C0&(data))>>6)
#define  MDOMAIN_CAP_DDR_In1Status_get_in1_freeze_ok(data)                       ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_DDR_In1Status_get_in1_field_polarity_error(data)            ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_DDR_In1Status_get_in1_field_polarity_status(data)           (0x0000000F&(data))

#define  MDOMAIN_CAP_Cap_In1_enable                                              0x18027228
#define  MDOMAIN_CAP_Cap_In1_enable_reg_addr                                     "0xB8027228"
#define  MDOMAIN_CAP_Cap_In1_enable_reg                                          0xB8027228
#define  MDOMAIN_CAP_Cap_In1_enable_inst_addr                                    "0x000A"
#define  set_MDOMAIN_CAP_Cap_In1_enable_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_Cap_In1_enable_reg)=data)
#define  get_MDOMAIN_CAP_Cap_In1_enable_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_Cap_In1_enable_reg))
#define  MDOMAIN_CAP_Cap_In1_enable_in1_cap_enable_shift                         (0)
#define  MDOMAIN_CAP_Cap_In1_enable_in1_cap_enable_mask                          (0x00000001)
#define  MDOMAIN_CAP_Cap_In1_enable_in1_cap_enable(data)                         (0x00000001&(data))
#define  MDOMAIN_CAP_Cap_In1_enable_get_in1_cap_enable(data)                     (0x00000001&(data))

#define  MDOMAIN_CAP_DDR_In2WTLVL                                                0x18027240
#define  MDOMAIN_CAP_DDR_In2WTLVL_reg_addr                                       "0xB8027240"
#define  MDOMAIN_CAP_DDR_In2WTLVL_reg                                            0xB8027240
#define  MDOMAIN_CAP_DDR_In2WTLVL_inst_addr                                      "0x000B"
#define  set_MDOMAIN_CAP_DDR_In2WTLVL_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2WTLVL_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2WTLVL_reg                                        (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2WTLVL_reg))
#define  MDOMAIN_CAP_DDR_In2WTLVL_in2_wtlvl_shift                                (16)
#define  MDOMAIN_CAP_DDR_In2WTLVL_in2_write_num_shift                            (0)
#define  MDOMAIN_CAP_DDR_In2WTLVL_in2_wtlvl_mask                                 (0x00FF0000)
#define  MDOMAIN_CAP_DDR_In2WTLVL_in2_write_num_mask                             (0x0000FFFF)
#define  MDOMAIN_CAP_DDR_In2WTLVL_in2_wtlvl(data)                                (0x00FF0000&((data)<<16))
#define  MDOMAIN_CAP_DDR_In2WTLVL_in2_write_num(data)                            (0x0000FFFF&(data))
#define  MDOMAIN_CAP_DDR_In2WTLVL_get_in2_wtlvl(data)                            ((0x00FF0000&(data))>>16)
#define  MDOMAIN_CAP_DDR_In2WTLVL_get_in2_write_num(data)                        (0x0000FFFF&(data))

#define  MDOMAIN_CAP_DDR_In2WrLen_Rem                                            0x18027244
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_reg_addr                                   "0xB8027244"
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_reg                                        0xB8027244
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_inst_addr                                  "0x000C"
#define  set_MDOMAIN_CAP_DDR_In2WrLen_Rem_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2WrLen_Rem_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2WrLen_Rem_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2WrLen_Rem_reg))
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_in2_wrlen_shift                            (8)
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_in2_write_remain_shift                     (0)
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_in2_wrlen_mask                             (0x00007F00)
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_in2_write_remain_mask                      (0x0000007F)
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_in2_wrlen(data)                            (0x00007F00&((data)<<8))
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_in2_write_remain(data)                     (0x0000007F&(data))
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_get_in2_wrlen(data)                        ((0x00007F00&(data))>>8)
#define  MDOMAIN_CAP_DDR_In2WrLen_Rem_get_in2_write_remain(data)                 (0x0000007F&(data))

#define  MDOMAIN_CAP_DDR_In2Addr                                                 0x18027248
#define  MDOMAIN_CAP_DDR_In2Addr_reg_addr                                        "0xB8027248"
#define  MDOMAIN_CAP_DDR_In2Addr_reg                                             0xB8027248
#define  MDOMAIN_CAP_DDR_In2Addr_inst_addr                                       "0x000D"
#define  set_MDOMAIN_CAP_DDR_In2Addr_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2Addr_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2Addr_reg                                         (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2Addr_reg))
#define  MDOMAIN_CAP_DDR_In2Addr_in2_wr_mem_start_shift                          (3)
#define  MDOMAIN_CAP_DDR_In2Addr_in2_wr_mem_start_mask                           (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In2Addr_in2_wr_mem_start(data)                          (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In2Addr_get_in2_wr_mem_start(data)                      ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In2LineStep                                             0x1802724C
#define  MDOMAIN_CAP_DDR_In2LineStep_reg_addr                                    "0xB802724C"
#define  MDOMAIN_CAP_DDR_In2LineStep_reg                                         0xB802724C
#define  MDOMAIN_CAP_DDR_In2LineStep_inst_addr                                   "0x000E"
#define  set_MDOMAIN_CAP_DDR_In2LineStep_reg(data)                               (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2LineStep_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2LineStep_reg                                     (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2LineStep_reg))
#define  MDOMAIN_CAP_DDR_In2LineStep_in2_line_step_shift                         (3)
#define  MDOMAIN_CAP_DDR_In2LineStep_in2_line_step_mask                          (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In2LineStep_in2_line_step(data)                         (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In2LineStep_get_in2_line_step(data)                     ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In2BlkStep                                              0x18027250
#define  MDOMAIN_CAP_DDR_In2BlkStep_reg_addr                                     "0xB8027250"
#define  MDOMAIN_CAP_DDR_In2BlkStep_reg                                          0xB8027250
#define  MDOMAIN_CAP_DDR_In2BlkStep_inst_addr                                    "0x000F"
#define  set_MDOMAIN_CAP_DDR_In2BlkStep_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2BlkStep_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2BlkStep_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2BlkStep_reg))
#define  MDOMAIN_CAP_DDR_In2BlkStep_in2_block_step_shift                         (3)
#define  MDOMAIN_CAP_DDR_In2BlkStep_in2_block_step_mask                          (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In2BlkStep_in2_block_step(data)                         (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In2BlkStep_get_in2_block_step(data)                     ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In2_2ndAddr                                             0x18027254
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_reg_addr                                    "0xB8027254"
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_reg                                         0xB8027254
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_inst_addr                                   "0x0010"
#define  set_MDOMAIN_CAP_DDR_In2_2ndAddr_reg(data)                               (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2_2ndAddr_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2_2ndAddr_reg                                     (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2_2ndAddr_reg))
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_in2_sec_bl_shift                            (3)
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_in2_sec_bl_mask                             (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_in2_sec_bl(data)                            (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In2_2ndAddr_get_in2_sec_bl(data)                        ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In2_3rdAddr                                             0x18027258
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_reg_addr                                    "0xB8027258"
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_reg                                         0xB8027258
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_inst_addr                                   "0x0011"
#define  set_MDOMAIN_CAP_DDR_In2_3rdAddr_reg(data)                               (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2_3rdAddr_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2_3rdAddr_reg                                     (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2_3rdAddr_reg))
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_in2_third_bl_shift                          (3)
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_in2_third_bl_mask                           (0xFFFFFFF8)
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_in2_third_bl(data)                          (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_DDR_In2_3rdAddr_get_in2_third_bl(data)                      ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DDR_In2LineNum                                              0x1802725C
#define  MDOMAIN_CAP_DDR_In2LineNum_reg_addr                                     "0xB802725C"
#define  MDOMAIN_CAP_DDR_In2LineNum_reg                                          0xB802725C
#define  MDOMAIN_CAP_DDR_In2LineNum_inst_addr                                    "0x0012"
#define  set_MDOMAIN_CAP_DDR_In2LineNum_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2LineNum_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2LineNum_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2LineNum_reg))
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_zero_shift                               (17)
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_frame_access_mode_shift                  (16)
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_line_number_shift                        (0)
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_zero_mask                                (0x00020000)
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_frame_access_mode_mask                   (0x00010000)
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_line_number_mask                         (0x00001FFF)
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_zero(data)                               (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_frame_access_mode(data)                  (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_DDR_In2LineNum_in2_line_number(data)                        (0x00001FFF&(data))
#define  MDOMAIN_CAP_DDR_In2LineNum_get_in2_zero(data)                           ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_DDR_In2LineNum_get_in2_frame_access_mode(data)              ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_DDR_In2LineNum_get_in2_line_number(data)                    (0x00001FFF&(data))

#define  MDOMAIN_CAP_DDR_In2Ctrl                                                 0x18027260
#define  MDOMAIN_CAP_DDR_In2Ctrl_reg_addr                                        "0xB8027260"
#define  MDOMAIN_CAP_DDR_In2Ctrl_reg                                             0xB8027260
#define  MDOMAIN_CAP_DDR_In2Ctrl_inst_addr                                       "0x0013"
#define  set_MDOMAIN_CAP_DDR_In2Ctrl_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2Ctrl_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2Ctrl_reg                                         (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2Ctrl_reg))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_sub_use_main_block_en_shift                 (24)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_unfreeze_wait_shift                         (21)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_auto_unfreeze_shift                         (20)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_freeze_control_shift                        (17)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_bad_edit_suppression_shift                  (16)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_v_flip_3buf_en_shift                        (8)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_merge_enable_shift                          (6)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_double_enable_shift                         (5)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_block_free_shift                            (4)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_single_buffer_select_shift                  (2)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_freeze_enable_shift                         (1)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_en_vs_rst_shift                             (0)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_sub_use_main_block_en_mask                  (0x01000000)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_unfreeze_wait_mask                          (0x00E00000)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_auto_unfreeze_mask                          (0x00100000)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_freeze_control_mask                         (0x00020000)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_bad_edit_suppression_mask                   (0x00010000)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_v_flip_3buf_en_mask                         (0x00000100)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_merge_enable_mask                           (0x00000040)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_double_enable_mask                          (0x00000020)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_block_free_mask                             (0x00000010)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_single_buffer_select_mask                   (0x0000000C)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_freeze_enable_mask                          (0x00000002)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_en_vs_rst_mask                              (0x00000001)
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_sub_use_main_block_en(data)                 (0x01000000&((data)<<24))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_unfreeze_wait(data)                         (0x00E00000&((data)<<21))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_auto_unfreeze(data)                         (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_freeze_control(data)                        (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_bad_edit_suppression(data)                  (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_v_flip_3buf_en(data)                        (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_merge_enable(data)                          (0x00000040&((data)<<6))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_double_enable(data)                         (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_block_free(data)                            (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_single_buffer_select(data)                  (0x0000000C&((data)<<2))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_freeze_enable(data)                         (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_DDR_In2Ctrl_in2_en_vs_rst(data)                             (0x00000001&(data))
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_sub_use_main_block_en(data)             ((0x01000000&(data))>>24)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_unfreeze_wait(data)                     ((0x00E00000&(data))>>21)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_auto_unfreeze(data)                     ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_freeze_control(data)                    ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_bad_edit_suppression(data)              ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_v_flip_3buf_en(data)                    ((0x00000100&(data))>>8)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_merge_enable(data)                      ((0x00000040&(data))>>6)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_double_enable(data)                     ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_block_free(data)                        ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_single_buffer_select(data)              ((0x0000000C&(data))>>2)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_freeze_enable(data)                     ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_DDR_In2Ctrl_get_in2_en_vs_rst(data)                         (0x00000001&(data))

#define  MDOMAIN_CAP_Cap_In2_enable                                              0x18027264
#define  MDOMAIN_CAP_Cap_In2_enable_reg_addr                                     "0xB8027264"
#define  MDOMAIN_CAP_Cap_In2_enable_reg                                          0xB8027264
#define  MDOMAIN_CAP_Cap_In2_enable_inst_addr                                    "0x0014"
#define  set_MDOMAIN_CAP_Cap_In2_enable_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_Cap_In2_enable_reg)=data)
#define  get_MDOMAIN_CAP_Cap_In2_enable_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_Cap_In2_enable_reg))
#define  MDOMAIN_CAP_Cap_In2_enable_in2_cap_enable_shift                         (0)
#define  MDOMAIN_CAP_Cap_In2_enable_in2_cap_enable_mask                          (0x00000001)
#define  MDOMAIN_CAP_Cap_In2_enable_in2_cap_enable(data)                         (0x00000001&(data))
#define  MDOMAIN_CAP_Cap_In2_enable_get_in2_cap_enable(data)                     (0x00000001&(data))

#define  MDOMAIN_CAP_DDR_In2Status                                               0x18027268
#define  MDOMAIN_CAP_DDR_In2Status_reg_addr                                      "0xB8027268"
#define  MDOMAIN_CAP_DDR_In2Status_reg                                           0xB8027268
#define  MDOMAIN_CAP_DDR_In2Status_inst_addr                                     "0x0015"
#define  set_MDOMAIN_CAP_DDR_In2Status_reg(data)                                 (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2Status_reg)=data)
#define  get_MDOMAIN_CAP_DDR_In2Status_reg                                       (*((volatile unsigned int*)MDOMAIN_CAP_DDR_In2Status_reg))
#define  MDOMAIN_CAP_DDR_In2Status_in2_block_select_shift                        (6)
#define  MDOMAIN_CAP_DDR_In2Status_in2_freeze_ok_shift                           (5)
#define  MDOMAIN_CAP_DDR_In2Status_in2_field_polarity_error_shift                (4)
#define  MDOMAIN_CAP_DDR_In2Status_in2_field_polarity_status_shift               (0)
#define  MDOMAIN_CAP_DDR_In2Status_in2_block_select_mask                         (0x000000C0)
#define  MDOMAIN_CAP_DDR_In2Status_in2_freeze_ok_mask                            (0x00000020)
#define  MDOMAIN_CAP_DDR_In2Status_in2_field_polarity_error_mask                 (0x00000010)
#define  MDOMAIN_CAP_DDR_In2Status_in2_field_polarity_status_mask                (0x0000000F)
#define  MDOMAIN_CAP_DDR_In2Status_in2_block_select(data)                        (0x000000C0&((data)<<6))
#define  MDOMAIN_CAP_DDR_In2Status_in2_freeze_ok(data)                           (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_DDR_In2Status_in2_field_polarity_error(data)                (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_DDR_In2Status_in2_field_polarity_status(data)               (0x0000000F&(data))
#define  MDOMAIN_CAP_DDR_In2Status_get_in2_block_select(data)                    ((0x000000C0&(data))>>6)
#define  MDOMAIN_CAP_DDR_In2Status_get_in2_freeze_ok(data)                       ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_DDR_In2Status_get_in2_field_polarity_error(data)            ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_DDR_In2Status_get_in2_field_polarity_status(data)           (0x0000000F&(data))

#define  MDOMAIN_CAP_cap_reg_doublbuffer                                         0x1802726C
#define  MDOMAIN_CAP_cap_reg_doublbuffer_reg_addr                                "0xB802726C"
#define  MDOMAIN_CAP_cap_reg_doublbuffer_reg                                     0xB802726C
#define  MDOMAIN_CAP_cap_reg_doublbuffer_inst_addr                               "0x0016"
#define  set_MDOMAIN_CAP_cap_reg_doublbuffer_reg(data)                           (*((volatile unsigned int*)MDOMAIN_CAP_cap_reg_doublbuffer_reg)=data)
#define  get_MDOMAIN_CAP_cap_reg_doublbuffer_reg                                 (*((volatile unsigned int*)MDOMAIN_CAP_cap_reg_doublbuffer_reg))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_apply_shift                     (18)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_sel_shift                       (17)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_en_shift                        (16)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_apply_shift                     (2)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_sel_shift                       (1)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_en_shift                        (0)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_apply_mask                      (0x00040000)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_sel_mask                        (0x00020000)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_en_mask                         (0x00010000)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_apply_mask                      (0x00000004)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_sel_mask                        (0x00000002)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_en_mask                         (0x00000001)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_apply(data)                     (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_sel(data)                       (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap2_db_en(data)                        (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_apply(data)                     (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_sel(data)                       (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_cap1_db_en(data)                        (0x00000001&(data))
#define  MDOMAIN_CAP_cap_reg_doublbuffer_get_cap2_db_apply(data)                 ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_get_cap2_db_sel(data)                   ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_get_cap2_db_en(data)                    ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_get_cap1_db_apply(data)                 ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_get_cap1_db_sel(data)                   ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_cap_reg_doublbuffer_get_cap1_db_en(data)                    (0x00000001&(data))

#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus                                          0x18027270
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg_addr                                 "0xB8027270"
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg                                      0xB8027270
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_inst_addr                                "0x0017"
#define  set_MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg(data)                            (*((volatile unsigned int*)MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg)=data)
#define  get_MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg                                  (*((volatile unsigned int*)MDOMAIN_CAP_Cap_DDR_FIFOStatus_reg))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_cap_first_wr_flag_shift              (21)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_cap_last_wr_flag_shift               (20)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifofull_shift                       (19)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoempty_shift                      (18)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifouf_shift                         (17)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoof_shift                         (16)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_cap_first_wr_flag_shift              (5)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_cap_last_wr_flag_shift               (4)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifofull_shift                       (3)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoempty_shift                      (2)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifouf_shift                         (1)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoof_shift                         (0)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_cap_first_wr_flag_mask               (0x00200000)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_cap_last_wr_flag_mask                (0x00100000)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifofull_mask                        (0x00080000)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoempty_mask                       (0x00040000)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifouf_mask                          (0x00020000)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoof_mask                          (0x00010000)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_cap_first_wr_flag_mask               (0x00000020)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_cap_last_wr_flag_mask                (0x00000010)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifofull_mask                        (0x00000008)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoempty_mask                       (0x00000004)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifouf_mask                          (0x00000002)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoof_mask                          (0x00000001)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_cap_first_wr_flag(data)              (0x00200000&((data)<<21))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_cap_last_wr_flag(data)               (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifofull(data)                       (0x00080000&((data)<<19))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoempty(data)                      (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifouf(data)                         (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in1_fifoof(data)                         (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_cap_first_wr_flag(data)              (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_cap_last_wr_flag(data)               (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifofull(data)                       (0x00000008&((data)<<3))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoempty(data)                      (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifouf(data)                         (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_in2_fifoof(data)                         (0x00000001&(data))
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in1_cap_first_wr_flag(data)          ((0x00200000&(data))>>21)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in1_cap_last_wr_flag(data)           ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in1_fifofull(data)                   ((0x00080000&(data))>>19)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in1_fifoempty(data)                  ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in1_fifouf(data)                     ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in1_fifoof(data)                     ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in2_cap_first_wr_flag(data)          ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in2_cap_last_wr_flag(data)           ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in2_fifofull(data)                   ((0x00000008&(data))>>3)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in2_fifoempty(data)                  ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in2_fifouf(data)                     ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_Cap_DDR_FIFOStatus_get_in2_fifoof(data)                     (0x00000001&(data))

#define  MDOMAIN_CAP_Cap_help_debug_status                                       0x18027274
#define  MDOMAIN_CAP_Cap_help_debug_status_reg_addr                              "0xB8027274"
#define  MDOMAIN_CAP_Cap_help_debug_status_reg                                   0xB8027274
#define  MDOMAIN_CAP_Cap_help_debug_status_inst_addr                             "0x0018"
#define  set_MDOMAIN_CAP_Cap_help_debug_status_reg(data)                         (*((volatile unsigned int*)MDOMAIN_CAP_Cap_help_debug_status_reg)=data)
#define  get_MDOMAIN_CAP_Cap_help_debug_status_reg                               (*((volatile unsigned int*)MDOMAIN_CAP_Cap_help_debug_status_reg))
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_drop_shift                        (18)
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_over_size_shift                   (17)
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_under_size_shift                  (16)
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_drop_shift                        (2)
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_over_size_shift                   (1)
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_under_size_shift                  (0)
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_drop_mask                         (0x00040000)
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_over_size_mask                    (0x00020000)
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_under_size_mask                   (0x00010000)
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_drop_mask                         (0x00000004)
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_over_size_mask                    (0x00000002)
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_under_size_mask                   (0x00000001)
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_drop(data)                        (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_over_size(data)                   (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_Cap_help_debug_status_in1_under_size(data)                  (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_drop(data)                        (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_over_size(data)                   (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_Cap_help_debug_status_in2_under_size(data)                  (0x00000001&(data))
#define  MDOMAIN_CAP_Cap_help_debug_status_get_in1_drop(data)                    ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_Cap_help_debug_status_get_in1_over_size(data)               ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_Cap_help_debug_status_get_in1_under_size(data)              ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_Cap_help_debug_status_get_in2_drop(data)                    ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_Cap_help_debug_status_get_in2_over_size(data)               ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_Cap_help_debug_status_get_in2_under_size(data)              (0x00000001&(data))

#define  MDOMAIN_CAP_CapMain_BoundaryAddr1                                       0x18027278
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_reg_addr                              "0xB8027278"
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_reg                                   0xB8027278
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_inst_addr                             "0x0019"
#define  set_MDOMAIN_CAP_CapMain_BoundaryAddr1_reg(data)                         (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_BoundaryAddr1_reg)=data)
#define  get_MDOMAIN_CAP_CapMain_BoundaryAddr1_reg                               (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_BoundaryAddr1_reg))
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_in1_cap_downlimit_adr_shift           (3)
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_in1_cap_downlimit_adr_mask            (0xFFFFFFF8)
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_in1_cap_downlimit_adr(data)           (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_CapMain_BoundaryAddr1_get_in1_cap_downlimit_adr(data)       ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_CapMain_BoundaryAddr2                                       0x1802727C
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_reg_addr                              "0xB802727C"
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_reg                                   0xB802727C
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_inst_addr                             "0x001A"
#define  set_MDOMAIN_CAP_CapMain_BoundaryAddr2_reg(data)                         (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_BoundaryAddr2_reg)=data)
#define  get_MDOMAIN_CAP_CapMain_BoundaryAddr2_reg                               (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_BoundaryAddr2_reg))
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_in1_cap_uplimit_adr_shift             (3)
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_in1_cap_uplimit_adr_mask              (0xFFFFFFF8)
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_in1_cap_uplimit_adr(data)             (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_CapMain_BoundaryAddr2_get_in1_cap_uplimit_adr(data)         ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status                              0x18027280
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_reg_addr                     "0xB8027280"
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_reg                          0xB8027280
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_inst_addr                    "0x001B"
#define  set_MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_reg(data)                (*((volatile unsigned int*)MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_reg)=data)
#define  get_MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_reg                      (*((volatile unsigned int*)MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_reg))
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_in1_cap_downlimit_ov_shift   (1)
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_in1_cap_uplimit_ov_shift     (0)
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_in1_cap_downlimit_ov_mask    (0x00000002)
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_in1_cap_uplimit_ov_mask      (0x00000001)
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_in1_cap_downlimit_ov(data)   (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_in1_cap_uplimit_ov(data)     (0x00000001&(data))
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_get_in1_cap_downlimit_ov(data) ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_DI1Cap_WRRD_BoundaryAdd_Status_get_in1_cap_uplimit_ov(data) (0x00000001&(data))

#define  MDOMAIN_CAP_CapSub_BoundaryAddr1                                        0x18027284
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_reg_addr                               "0xB8027284"
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_reg                                    0xB8027284
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_inst_addr                              "0x001C"
#define  set_MDOMAIN_CAP_CapSub_BoundaryAddr1_reg(data)                          (*((volatile unsigned int*)MDOMAIN_CAP_CapSub_BoundaryAddr1_reg)=data)
#define  get_MDOMAIN_CAP_CapSub_BoundaryAddr1_reg                                (*((volatile unsigned int*)MDOMAIN_CAP_CapSub_BoundaryAddr1_reg))
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_in2_cap_downlimit_adr_shift            (3)
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_in2_cap_downlimit_adr_mask             (0xFFFFFFF8)
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_in2_cap_downlimit_adr(data)            (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_CapSub_BoundaryAddr1_get_in2_cap_downlimit_adr(data)        ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_CapSub_BoundaryAddr2                                        0x18027288
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_reg_addr                               "0xB8027288"
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_reg                                    0xB8027288
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_inst_addr                              "0x001D"
#define  set_MDOMAIN_CAP_CapSub_BoundaryAddr2_reg(data)                          (*((volatile unsigned int*)MDOMAIN_CAP_CapSub_BoundaryAddr2_reg)=data)
#define  get_MDOMAIN_CAP_CapSub_BoundaryAddr2_reg                                (*((volatile unsigned int*)MDOMAIN_CAP_CapSub_BoundaryAddr2_reg))
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_in2_cap_uplimit_adr_shift              (3)
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_in2_cap_uplimit_adr_mask               (0xFFFFFFF8)
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_in2_cap_uplimit_adr(data)              (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_CapSub_BoundaryAddr2_get_in2_cap_uplimit_adr(data)          ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status                              0x1802728C
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_reg_addr                     "0xB802728C"
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_reg                          0xB802728C
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_inst_addr                    "0x001E"
#define  set_MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_reg(data)                (*((volatile unsigned int*)MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_reg)=data)
#define  get_MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_reg                      (*((volatile unsigned int*)MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_reg))
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_in2_cap_downlimit_ov_shift   (1)
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_in2_cap_uplimit_ov_shift     (0)
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_in2_cap_downlimit_ov_mask    (0x00000002)
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_in2_cap_uplimit_ov_mask      (0x00000001)
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_in2_cap_downlimit_ov(data)   (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_in2_cap_uplimit_ov(data)     (0x00000001&(data))
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_get_in2_cap_downlimit_ov(data) ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_DI2Cap_WRRD_BoundaryAdd_Status_get_in2_cap_uplimit_ov(data) (0x00000001&(data))

#define  MDOMAIN_CAP_Cap_IE_WD_CTRL                                              0x18027290
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_reg_addr                                     "0xB8027290"
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_reg                                          0xB8027290
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_inst_addr                                    "0x001F"
#define  set_MDOMAIN_CAP_Cap_IE_WD_CTRL_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_Cap_IE_WD_CTRL_reg)=data)
#define  get_MDOMAIN_CAP_Cap_IE_WD_CTRL_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_Cap_IE_WD_CTRL_reg))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_first_wr_wde_shift                   (22)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_first_wr_ie_shift                    (21)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_fifoerr_ie_shift                         (20)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_last_wr_ie_shift                     (19)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_fifoerr_wde_shift                        (18)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_last_wr_wde_shift                    (17)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_wd_to_main_shift                             (16)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_first_wr_wde_shift                   (6)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_first_wr_ie_shift                    (5)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_fifoerr_ie_shift                         (4)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_last_wr_ie_shift                     (3)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_fifoerr_wde_shift                        (2)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_last_wr_wde_shift                    (1)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_wd_to_sub_shift                              (0)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_first_wr_wde_mask                    (0x00400000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_first_wr_ie_mask                     (0x00200000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_fifoerr_ie_mask                          (0x00100000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_last_wr_ie_mask                      (0x00080000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_fifoerr_wde_mask                         (0x00040000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_last_wr_wde_mask                     (0x00020000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_wd_to_main_mask                              (0x00010000)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_first_wr_wde_mask                    (0x00000040)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_first_wr_ie_mask                     (0x00000020)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_fifoerr_ie_mask                          (0x00000010)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_last_wr_ie_mask                      (0x00000008)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_fifoerr_wde_mask                         (0x00000004)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_last_wr_wde_mask                     (0x00000002)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_wd_to_sub_mask                               (0x00000001)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_first_wr_wde(data)                   (0x00400000&((data)<<22))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_first_wr_ie(data)                    (0x00200000&((data)<<21))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_fifoerr_ie(data)                         (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_last_wr_ie(data)                     (0x00080000&((data)<<19))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_fifoerr_wde(data)                        (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in1_cap_last_wr_wde(data)                    (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_wd_to_main(data)                             (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_first_wr_wde(data)                   (0x00000040&((data)<<6))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_first_wr_ie(data)                    (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_fifoerr_ie(data)                         (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_last_wr_ie(data)                     (0x00000008&((data)<<3))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_fifoerr_wde(data)                        (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_in2_cap_last_wr_wde(data)                    (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_wd_to_sub(data)                              (0x00000001&(data))
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in1_cap_first_wr_wde(data)               ((0x00400000&(data))>>22)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in1_cap_first_wr_ie(data)                ((0x00200000&(data))>>21)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in1_fifoerr_ie(data)                     ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in1_cap_last_wr_ie(data)                 ((0x00080000&(data))>>19)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in1_fifoerr_wde(data)                    ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in1_cap_last_wr_wde(data)                ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_wd_to_main(data)                         ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in2_cap_first_wr_wde(data)               ((0x00000040&(data))>>6)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in2_cap_first_wr_ie(data)                ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in2_fifoerr_ie(data)                     ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in2_cap_last_wr_ie(data)                 ((0x00000008&(data))>>3)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in2_fifoerr_wde(data)                    ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_in2_cap_last_wr_wde(data)                ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_Cap_IE_WD_CTRL_get_wd_to_sub(data)                          (0x00000001&(data))

#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL                                    0x18027294
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg_addr                           "0xB8027294"
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg                                0xB8027294
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_inst_addr                          "0x0020"
#define  set_MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg(data)                      (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg)=data)
#define  get_MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg                            (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_reg))
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_in1_sbs_vsd_en_shift               (0)
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_in1_sbs_vsd_en_mask                (0x00000001)
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_in1_sbs_vsd_en(data)               (0x00000001&(data))
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_CTRL_get_in1_sbs_vsd_en(data)           (0x00000001&(data))

#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET                                  0x18027298
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg_addr                         "0xB8027298"
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg                              0xB8027298
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_inst_addr                        "0x0021"
#define  set_MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg(data)                    (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg)=data)
#define  get_MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg                          (*((volatile unsigned int*)MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_reg))
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_in1_lr_offset_shift              (3)
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_in1_lr_offset_mask               (0xFFFFFFF8)
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_in1_lr_offset(data)              (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_CAP_CapMain_SBS_VSD_CAP_OFFSET_get_in1_lr_offset(data)          ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_CAP_DISPM_CRC_CTRL                                              0x180272A0
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_reg_addr                                     "0xB80272A0"
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_reg                                          0xB80272A0
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_inst_addr                                    "0x0022"
#define  set_MDOMAIN_CAP_DISPM_CRC_CTRL_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_DISPM_CRC_CTRL_reg)=data)
#define  get_MDOMAIN_CAP_DISPM_CRC_CTRL_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_DISPM_CRC_CTRL_reg))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_crc_comp_error_int_shift                     (14)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_dynamic_crc_cmp_en_shift                     (13)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_crc_bit_sel_shift                            (10)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_3d_en_shift                         (7)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_conti_shift                         (5)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_start_shift                         (4)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_3d_en_shift                          (3)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_conti_shift                          (1)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_start_shift                          (0)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_crc_comp_error_int_mask                      (0x00004000)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_dynamic_crc_cmp_en_mask                      (0x00002000)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_crc_bit_sel_mask                             (0x00000C00)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_3d_en_mask                          (0x00000080)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_conti_mask                          (0x00000020)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_start_mask                          (0x00000010)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_3d_en_mask                           (0x00000008)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_conti_mask                           (0x00000002)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_start_mask                           (0x00000001)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_crc_comp_error_int(data)                     (0x00004000&((data)<<14))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_dynamic_crc_cmp_en(data)                     (0x00002000&((data)<<13))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_crc_bit_sel(data)                            (0x00000C00&((data)<<10))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_3d_en(data)                         (0x00000080&((data)<<7))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_conti(data)                         (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_disp_crc_start(data)                         (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_3d_en(data)                          (0x00000008&((data)<<3))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_conti(data)                          (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_cap_crc_start(data)                          (0x00000001&(data))
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_crc_comp_error_int(data)                 ((0x00004000&(data))>>14)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_dynamic_crc_cmp_en(data)                 ((0x00002000&(data))>>13)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_crc_bit_sel(data)                        ((0x00000C00&(data))>>10)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_disp_crc_3d_en(data)                     ((0x00000080&(data))>>7)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_disp_crc_conti(data)                     ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_disp_crc_start(data)                     ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_cap_crc_3d_en(data)                      ((0x00000008&(data))>>3)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_cap_crc_conti(data)                      ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_DISPM_CRC_CTRL_get_cap_crc_start(data)                      (0x00000001&(data))

#define  MDOMAIN_CAP_DISPM_CRC_STATUS                                            0x180272A4
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_reg_addr                                   "0xB80272A4"
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_reg                                        0xB80272A4
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_inst_addr                                  "0x0023"
#define  set_MDOMAIN_CAP_DISPM_CRC_STATUS_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_DISPM_CRC_STATUS_reg)=data)
#define  get_MDOMAIN_CAP_DISPM_CRC_STATUS_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_DISPM_CRC_STATUS_reg))
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_match_buffer_shift                         (16)
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_crc_comp_error_flag_shift                  (0)
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_match_buffer_mask                          (0x00030000)
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_crc_comp_error_flag_mask                   (0x00000001)
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_match_buffer(data)                         (0x00030000&((data)<<16))
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_crc_comp_error_flag(data)                  (0x00000001&(data))
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_get_match_buffer(data)                     ((0x00030000&(data))>>16)
#define  MDOMAIN_CAP_DISPM_CRC_STATUS_get_crc_comp_error_flag(data)              (0x00000001&(data))

#define  MDOMAIN_CAP_CRC_mask                                                    0x180272A8
#define  MDOMAIN_CAP_CRC_mask_reg_addr                                           "0xB80272A8"
#define  MDOMAIN_CAP_CRC_mask_reg                                                0xB80272A8
#define  MDOMAIN_CAP_CRC_mask_inst_addr                                          "0x0024"
#define  set_MDOMAIN_CAP_CRC_mask_reg(data)                                      (*((volatile unsigned int*)MDOMAIN_CAP_CRC_mask_reg)=data)
#define  get_MDOMAIN_CAP_CRC_mask_reg                                            (*((volatile unsigned int*)MDOMAIN_CAP_CRC_mask_reg))
#define  MDOMAIN_CAP_CRC_mask_crc_mask_shift                                     (0)
#define  MDOMAIN_CAP_CRC_mask_crc_mask_mask                                      (0xFFFFFFFF)
#define  MDOMAIN_CAP_CRC_mask_crc_mask(data)                                     (0xFFFFFFFF&(data))
#define  MDOMAIN_CAP_CRC_mask_get_crc_mask(data)                                 (0xFFFFFFFF&(data))

#define  MDOMAIN_CAP_Cap_L_CRC_Result                                            0x180272AC
#define  MDOMAIN_CAP_Cap_L_CRC_Result_reg_addr                                   "0xB80272AC"
#define  MDOMAIN_CAP_Cap_L_CRC_Result_reg                                        0xB80272AC
#define  MDOMAIN_CAP_Cap_L_CRC_Result_inst_addr                                  "0x0025"
#define  set_MDOMAIN_CAP_Cap_L_CRC_Result_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_Cap_L_CRC_Result_reg)=data)
#define  get_MDOMAIN_CAP_Cap_L_CRC_Result_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_Cap_L_CRC_Result_reg))
#define  MDOMAIN_CAP_Cap_L_CRC_Result_cap_l_crc_result_shift                     (0)
#define  MDOMAIN_CAP_Cap_L_CRC_Result_cap_l_crc_result_mask                      (0xFFFFFFFF)
#define  MDOMAIN_CAP_Cap_L_CRC_Result_cap_l_crc_result(data)                     (0xFFFFFFFF&(data))
#define  MDOMAIN_CAP_Cap_L_CRC_Result_get_cap_l_crc_result(data)                 (0xFFFFFFFF&(data))

#define  MDOMAIN_CAP_Cap_R_CRC_Result                                            0x180272B0
#define  MDOMAIN_CAP_Cap_R_CRC_Result_reg_addr                                   "0xB80272B0"
#define  MDOMAIN_CAP_Cap_R_CRC_Result_reg                                        0xB80272B0
#define  MDOMAIN_CAP_Cap_R_CRC_Result_inst_addr                                  "0x0026"
#define  set_MDOMAIN_CAP_Cap_R_CRC_Result_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_Cap_R_CRC_Result_reg)=data)
#define  get_MDOMAIN_CAP_Cap_R_CRC_Result_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_Cap_R_CRC_Result_reg))
#define  MDOMAIN_CAP_Cap_R_CRC_Result_cap_r_crc_result_shift                     (0)
#define  MDOMAIN_CAP_Cap_R_CRC_Result_cap_r_crc_result_mask                      (0xFFFFFFFF)
#define  MDOMAIN_CAP_Cap_R_CRC_Result_cap_r_crc_result(data)                     (0xFFFFFFFF&(data))
#define  MDOMAIN_CAP_Cap_R_CRC_Result_get_cap_r_crc_result(data)                 (0xFFFFFFFF&(data))

#define  MDOMAIN_CAP_Disp_L_CRC_Result                                           0x180272B4
#define  MDOMAIN_CAP_Disp_L_CRC_Result_reg_addr                                  "0xB80272B4"
#define  MDOMAIN_CAP_Disp_L_CRC_Result_reg                                       0xB80272B4
#define  MDOMAIN_CAP_Disp_L_CRC_Result_inst_addr                                 "0x0027"
#define  set_MDOMAIN_CAP_Disp_L_CRC_Result_reg(data)                             (*((volatile unsigned int*)MDOMAIN_CAP_Disp_L_CRC_Result_reg)=data)
#define  get_MDOMAIN_CAP_Disp_L_CRC_Result_reg                                   (*((volatile unsigned int*)MDOMAIN_CAP_Disp_L_CRC_Result_reg))
#define  MDOMAIN_CAP_Disp_L_CRC_Result_disp_l_crc_result_shift                   (0)
#define  MDOMAIN_CAP_Disp_L_CRC_Result_disp_l_crc_result_mask                    (0xFFFFFFFF)
#define  MDOMAIN_CAP_Disp_L_CRC_Result_disp_l_crc_result(data)                   (0xFFFFFFFF&(data))
#define  MDOMAIN_CAP_Disp_L_CRC_Result_get_disp_l_crc_result(data)               (0xFFFFFFFF&(data))

#define  MDOMAIN_CAP_Display_R_CRC_Result                                        0x180272B8
#define  MDOMAIN_CAP_Display_R_CRC_Result_reg_addr                               "0xB80272B8"
#define  MDOMAIN_CAP_Display_R_CRC_Result_reg                                    0xB80272B8
#define  MDOMAIN_CAP_Display_R_CRC_Result_inst_addr                              "0x0028"
#define  set_MDOMAIN_CAP_Display_R_CRC_Result_reg(data)                          (*((volatile unsigned int*)MDOMAIN_CAP_Display_R_CRC_Result_reg)=data)
#define  get_MDOMAIN_CAP_Display_R_CRC_Result_reg                                (*((volatile unsigned int*)MDOMAIN_CAP_Display_R_CRC_Result_reg))
#define  MDOMAIN_CAP_Display_R_CRC_Result_disp_r_crc_result_shift                (0)
#define  MDOMAIN_CAP_Display_R_CRC_Result_disp_r_crc_result_mask                 (0xFFFFFFFF)
#define  MDOMAIN_CAP_Display_R_CRC_Result_disp_r_crc_result(data)                (0xFFFFFFFF&(data))
#define  MDOMAIN_CAP_Display_R_CRC_Result_get_disp_r_crc_result(data)            (0xFFFFFFFF&(data))

#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL                                           0x180272C0
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg_addr                                  "0xB80272C0"
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg                                       0xB80272C0
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_inst_addr                                 "0x0029"
#define  set_MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg(data)                             (*((volatile unsigned int*)MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg)=data)
#define  get_MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg                                   (*((volatile unsigned int*)MDOMAIN_CAP_CAP_DMA_rate_CTRL_reg))
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_in1_rate_en_shift                         (0)
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_in1_rate_en_mask                          (0x00000001)
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_in1_rate_en(data)                         (0x00000001&(data))
#define  MDOMAIN_CAP_CAP_DMA_rate_CTRL_get_in1_rate_en(data)                     (0x00000001&(data))

#define  MDOMAIN_CAP_Capture_rate                                                0x180272C4
#define  MDOMAIN_CAP_Capture_rate_reg_addr                                       "0xB80272C4"
#define  MDOMAIN_CAP_Capture_rate_reg                                            0xB80272C4
#define  MDOMAIN_CAP_Capture_rate_inst_addr                                      "0x002A"
#define  set_MDOMAIN_CAP_Capture_rate_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_CAP_Capture_rate_reg)=data)
#define  get_MDOMAIN_CAP_Capture_rate_reg                                        (*((volatile unsigned int*)MDOMAIN_CAP_Capture_rate_reg))
#define  MDOMAIN_CAP_Capture_rate_in1_rate_shift                                 (0)
#define  MDOMAIN_CAP_Capture_rate_in1_rate_mask                                  (0xFFFFFFFF)
#define  MDOMAIN_CAP_Capture_rate_in1_rate(data)                                 (0xFFFFFFFF&(data))
#define  MDOMAIN_CAP_Capture_rate_get_in1_rate(data)                             (0xFFFFFFFF&(data))

#define  MDOMAIN_CAP_Capture_byte_swap                                           0x180272C8
#define  MDOMAIN_CAP_Capture_byte_swap_reg_addr                                  "0xB80272C8"
#define  MDOMAIN_CAP_Capture_byte_swap_reg                                       0xB80272C8
#define  MDOMAIN_CAP_Capture_byte_swap_inst_addr                                 "0x002B"
#define  set_MDOMAIN_CAP_Capture_byte_swap_reg(data)                             (*((volatile unsigned int*)MDOMAIN_CAP_Capture_byte_swap_reg)=data)
#define  get_MDOMAIN_CAP_Capture_byte_swap_reg                                   (*((volatile unsigned int*)MDOMAIN_CAP_Capture_byte_swap_reg))
#define  MDOMAIN_CAP_Capture_byte_swap_in2_8byte_swap_shift                      (19)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_4byte_swap_shift                      (18)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_2byte_swap_shift                      (17)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_1byte_swap_shift                      (16)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_8byte_swap_shift                      (3)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_4byte_swap_shift                      (2)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_2byte_swap_shift                      (1)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_1byte_swap_shift                      (0)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_8byte_swap_mask                       (0x00080000)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_4byte_swap_mask                       (0x00040000)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_2byte_swap_mask                       (0x00020000)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_1byte_swap_mask                       (0x00010000)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_8byte_swap_mask                       (0x00000008)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_4byte_swap_mask                       (0x00000004)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_2byte_swap_mask                       (0x00000002)
#define  MDOMAIN_CAP_Capture_byte_swap_in1_1byte_swap_mask                       (0x00000001)
#define  MDOMAIN_CAP_Capture_byte_swap_in2_8byte_swap(data)                      (0x00080000&((data)<<19))
#define  MDOMAIN_CAP_Capture_byte_swap_in2_4byte_swap(data)                      (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_Capture_byte_swap_in2_2byte_swap(data)                      (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_Capture_byte_swap_in2_1byte_swap(data)                      (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_Capture_byte_swap_in1_8byte_swap(data)                      (0x00000008&((data)<<3))
#define  MDOMAIN_CAP_Capture_byte_swap_in1_4byte_swap(data)                      (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_Capture_byte_swap_in1_2byte_swap(data)                      (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_Capture_byte_swap_in1_1byte_swap(data)                      (0x00000001&(data))
#define  MDOMAIN_CAP_Capture_byte_swap_get_in2_8byte_swap(data)                  ((0x00080000&(data))>>19)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in2_4byte_swap(data)                  ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in2_2byte_swap(data)                  ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in2_1byte_swap(data)                  ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in1_8byte_swap(data)                  ((0x00000008&(data))>>3)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in1_4byte_swap(data)                  ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in1_2byte_swap(data)                  ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_Capture_byte_swap_get_in1_1byte_swap(data)                  (0x00000001&(data))

#define  MDOMAIN_CAP_Main_SDNR_cxxto64                                           0x180272CC
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_reg_addr                                  "0xB80272CC"
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_reg                                       0xB80272CC
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_inst_addr                                 "0x002C"
#define  set_MDOMAIN_CAP_Main_SDNR_cxxto64_reg(data)                             (*((volatile unsigned int*)MDOMAIN_CAP_Main_SDNR_cxxto64_reg)=data)
#define  get_MDOMAIN_CAP_Main_SDNR_cxxto64_reg                                   (*((volatile unsigned int*)MDOMAIN_CAP_Main_SDNR_cxxto64_reg))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_out_bit_shift                             (28)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_sort_fmt_shift                            (27)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_rgb565_en_shift                           (26)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_rgb_to_argb_en_shift                      (25)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_argb_swap_shift                           (24)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_argb_dummy_data_shift                     (16)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_out_bit_mask                              (0x10000000)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_sort_fmt_mask                             (0x08000000)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_rgb565_en_mask                            (0x04000000)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_rgb_to_argb_en_mask                       (0x02000000)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_argb_swap_mask                            (0x01000000)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_argb_dummy_data_mask                      (0x00FF0000)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_out_bit(data)                             (0x10000000&((data)<<28))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_sort_fmt(data)                            (0x08000000&((data)<<27))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_rgb565_en(data)                           (0x04000000&((data)<<26))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_rgb_to_argb_en(data)                      (0x02000000&((data)<<25))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_argb_swap(data)                           (0x01000000&((data)<<24))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_argb_dummy_data(data)                     (0x00FF0000&((data)<<16))
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_get_out_bit(data)                         ((0x10000000&(data))>>28)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_get_sort_fmt(data)                        ((0x08000000&(data))>>27)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_get_rgb565_en(data)                       ((0x04000000&(data))>>26)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_get_rgb_to_argb_en(data)                  ((0x02000000&(data))>>25)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_get_argb_swap(data)                       ((0x01000000&(data))>>24)
#define  MDOMAIN_CAP_Main_SDNR_cxxto64_get_argb_dummy_data(data)                 ((0x00FF0000&(data))>>16)

#define  MDOMAIN_CAP_Sub_SDNR_cxxto64                                            0x180272D0
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_reg_addr                                   "0xB80272D0"
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_reg                                        0xB80272D0
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_inst_addr                                  "0x002D"
#define  set_MDOMAIN_CAP_Sub_SDNR_cxxto64_reg(data)                              (*((volatile unsigned int*)MDOMAIN_CAP_Sub_SDNR_cxxto64_reg)=data)
#define  get_MDOMAIN_CAP_Sub_SDNR_cxxto64_reg                                    (*((volatile unsigned int*)MDOMAIN_CAP_Sub_SDNR_cxxto64_reg))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_out_bit_shift                          (28)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_sort_fmt_shift                         (27)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_rgb565_en_shift                        (26)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_rgb_to_argb_en_shift                   (25)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_argb_swap_shift                        (24)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_argb_dummy_data_shift                  (16)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_out_bit_mask                           (0x10000000)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_sort_fmt_mask                          (0x08000000)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_rgb565_en_mask                         (0x04000000)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_rgb_to_argb_en_mask                    (0x02000000)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_argb_swap_mask                         (0x01000000)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_argb_dummy_data_mask                   (0x00FF0000)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_out_bit(data)                          (0x10000000&((data)<<28))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_sort_fmt(data)                         (0x08000000&((data)<<27))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_rgb565_en(data)                        (0x04000000&((data)<<26))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_rgb_to_argb_en(data)                   (0x02000000&((data)<<25))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_argb_swap(data)                        (0x01000000&((data)<<24))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_sub_argb_dummy_data(data)                  (0x00FF0000&((data)<<16))
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_get_sub_out_bit(data)                      ((0x10000000&(data))>>28)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_get_sub_sort_fmt(data)                     ((0x08000000&(data))>>27)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_get_sub_rgb565_en(data)                    ((0x04000000&(data))>>26)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_get_sub_rgb_to_argb_en(data)               ((0x02000000&(data))>>25)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_get_sub_argb_swap(data)                    ((0x01000000&(data))>>24)
#define  MDOMAIN_CAP_Sub_SDNR_cxxto64_get_sub_argb_dummy_data(data)              ((0x00FF0000&(data))>>16)

#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL                                      0x180272D4
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_reg_addr                             "0xB80272D4"
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_reg                                  0xB80272D4
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_inst_addr                            "0x002E"
#define  set_MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_reg(data)                        (*((volatile unsigned int*)MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_reg)=data)
#define  get_MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_reg                              (*((volatile unsigned int*)MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_reg))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_fsync_ovf_en_shift                (20)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_fsync_udf_en_shift                (19)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_ovf_en_shift                (18)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_to_main_shift               (17)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_to_sub_shift                (16)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_fsync_ovf_en_shift               (10)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_fsync_udf_en_shift               (9)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_ibuff_ovf_en_shift               (8)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_fsync_ovf_en_mask                 (0x00100000)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_fsync_udf_en_mask                 (0x00080000)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_ovf_en_mask                 (0x00040000)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_to_main_mask                (0x00020000)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_to_sub_mask                 (0x00010000)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_fsync_ovf_en_mask                (0x00000400)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_fsync_udf_en_mask                (0x00000200)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_ibuff_ovf_en_mask                (0x00000100)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_fsync_ovf_en(data)                (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_fsync_udf_en(data)                (0x00080000&((data)<<19))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_ovf_en(data)                (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_to_main(data)               (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_wd_ibuff_to_sub(data)                (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_fsync_ovf_en(data)               (0x00000400&((data)<<10))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_fsync_udf_en(data)               (0x00000200&((data)<<9))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_irq_ibuff_ovf_en(data)               (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_wd_fsync_ovf_en(data)            ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_wd_fsync_udf_en(data)            ((0x00080000&(data))>>19)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_wd_ibuff_ovf_en(data)            ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_wd_ibuff_to_main(data)           ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_wd_ibuff_to_sub(data)            ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_irq_fsync_ovf_en(data)           ((0x00000400&(data))>>10)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_irq_fsync_udf_en(data)           ((0x00000200&(data))>>9)
#define  MDOMAIN_CAP_ICH1_IBUFF_STATUS_CTRL_get_irq_ibuff_ovf_en(data)           ((0x00000100&(data))>>8)

#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL                                      0x180272D8
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_reg_addr                             "0xB80272D8"
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_reg                                  0xB80272D8
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_inst_addr                            "0x002F"
#define  set_MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_reg(data)                        (*((volatile unsigned int*)MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_reg)=data)
#define  get_MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_reg                              (*((volatile unsigned int*)MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_reg))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_fsync_ovf_en_sub_shift            (20)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_fsync_udf_en_sub_shift            (19)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_ovf_en_sub_shift            (18)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_to_main_sub_shift           (17)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_to_sub_sub_shift            (16)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_fsync_ovf_en_sub_shift           (10)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_fsync_udf_en_sub_shift           (9)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_ibuff_ovf_en_sub_shift           (8)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_fsync_ovf_en_sub_mask             (0x00100000)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_fsync_udf_en_sub_mask             (0x00080000)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_ovf_en_sub_mask             (0x00040000)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_to_main_sub_mask            (0x00020000)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_to_sub_sub_mask             (0x00010000)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_fsync_ovf_en_sub_mask            (0x00000400)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_fsync_udf_en_sub_mask            (0x00000200)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_ibuff_ovf_en_sub_mask            (0x00000100)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_fsync_ovf_en_sub(data)            (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_fsync_udf_en_sub(data)            (0x00080000&((data)<<19))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_ovf_en_sub(data)            (0x00040000&((data)<<18))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_to_main_sub(data)           (0x00020000&((data)<<17))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_wd_ibuff_to_sub_sub(data)            (0x00010000&((data)<<16))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_fsync_ovf_en_sub(data)           (0x00000400&((data)<<10))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_fsync_udf_en_sub(data)           (0x00000200&((data)<<9))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_irq_ibuff_ovf_en_sub(data)           (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_wd_fsync_ovf_en_sub(data)        ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_wd_fsync_udf_en_sub(data)        ((0x00080000&(data))>>19)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_wd_ibuff_ovf_en_sub(data)        ((0x00040000&(data))>>18)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_wd_ibuff_to_main_sub(data)       ((0x00020000&(data))>>17)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_wd_ibuff_to_sub_sub(data)        ((0x00010000&(data))>>16)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_irq_fsync_ovf_en_sub(data)       ((0x00000400&(data))>>10)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_irq_fsync_udf_en_sub(data)       ((0x00000200&(data))>>9)
#define  MDOMAIN_CAP_ICH2_IBUFF_STATUS_CTRL_get_irq_ibuff_ovf_en_sub(data)       ((0x00000100&(data))>>8)

#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS                                          0x180272DC
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg_addr                                 "0xB80272DC"
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg                                      0xB80272DC
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_inst_addr                                "0x0030"
#define  set_MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg(data)                            (*((volatile unsigned int*)MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg)=data)
#define  get_MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg                                  (*((volatile unsigned int*)MDOMAIN_CAP_ICH12_IBUFF_STATUS_reg))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_ovf_sub_shift                   (13)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_udf_sub_shift                   (12)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_ibuff_ovf_sub_shift                      (10)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_ovf_sub_shift                      (9)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_udf_sub_shift                      (8)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_ovf_shift                       (5)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_udf_shift                       (4)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_ibuff_ovf_shift                          (2)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_ovf_shift                          (1)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_udf_shift                          (0)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_ovf_sub_mask                    (0x00002000)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_udf_sub_mask                    (0x00001000)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_ibuff_ovf_sub_mask                       (0x00000400)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_ovf_sub_mask                       (0x00000200)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_udf_sub_mask                       (0x00000100)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_ovf_mask                        (0x00000020)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_udf_mask                        (0x00000010)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_ibuff_ovf_mask                           (0x00000004)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_ovf_mask                           (0x00000002)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_udf_mask                           (0x00000001)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_ovf_sub(data)                   (0x00002000&((data)<<13))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_udf_sub(data)                   (0x00001000&((data)<<12))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_ibuff_ovf_sub(data)                      (0x00000400&((data)<<10))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_ovf_sub(data)                      (0x00000200&((data)<<9))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_udf_sub(data)                      (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_ovf(data)                       (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_q_sbs_lr_udf(data)                       (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_ibuff_ovf(data)                          (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_ovf(data)                          (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_fsync_udf(data)                          (0x00000001&(data))
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_q_sbs_lr_ovf_sub(data)               ((0x00002000&(data))>>13)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_q_sbs_lr_udf_sub(data)               ((0x00001000&(data))>>12)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_ibuff_ovf_sub(data)                  ((0x00000400&(data))>>10)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_fsync_ovf_sub(data)                  ((0x00000200&(data))>>9)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_fsync_udf_sub(data)                  ((0x00000100&(data))>>8)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_q_sbs_lr_ovf(data)                   ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_q_sbs_lr_udf(data)                   ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_ibuff_ovf(data)                      ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_fsync_ovf(data)                      ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_ICH12_IBUFF_STATUS_get_fsync_udf(data)                      (0x00000001&(data))

#define  MDOMAIN_CAP_main_cmp_resolution                                         0x180272E0
#define  MDOMAIN_CAP_main_cmp_resolution_reg_addr                                "0xB80272E0"
#define  MDOMAIN_CAP_main_cmp_resolution_reg                                     0xB80272E0
#define  MDOMAIN_CAP_main_cmp_resolution_inst_addr                               "0x0031"
#define  set_MDOMAIN_CAP_main_cmp_resolution_reg(data)                           (*((volatile unsigned int*)MDOMAIN_CAP_main_cmp_resolution_reg)=data)
#define  get_MDOMAIN_CAP_main_cmp_resolution_reg                                 (*((volatile unsigned int*)MDOMAIN_CAP_main_cmp_resolution_reg))
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_segment_shift                       (24)
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_width_shift                         (16)
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_height_shift                        (0)
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_segment_mask                        (0x03000000)
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_width_mask                          (0x00FF0000)
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_height_mask                         (0x0000FFFF)
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_segment(data)                       (0x03000000&((data)<<24))
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_width(data)                         (0x00FF0000&((data)<<16))
#define  MDOMAIN_CAP_main_cmp_resolution_cmp_height(data)                        (0x0000FFFF&(data))
#define  MDOMAIN_CAP_main_cmp_resolution_get_cmp_segment(data)                   ((0x03000000&(data))>>24)
#define  MDOMAIN_CAP_main_cmp_resolution_get_cmp_width(data)                     ((0x00FF0000&(data))>>16)
#define  MDOMAIN_CAP_main_cmp_resolution_get_cmp_height(data)                    (0x0000FFFF&(data))

#define  MDOMAIN_CAP_main_comp_setting                                           0x180272E4
#define  MDOMAIN_CAP_main_comp_setting_reg_addr                                  "0xB80272E4"
#define  MDOMAIN_CAP_main_comp_setting_reg                                       0xB80272E4
#define  MDOMAIN_CAP_main_comp_setting_inst_addr                                 "0x0032"
#define  set_MDOMAIN_CAP_main_comp_setting_reg(data)                             (*((volatile unsigned int*)MDOMAIN_CAP_main_comp_setting_reg)=data)
#define  get_MDOMAIN_CAP_main_comp_setting_reg                                   (*((volatile unsigned int*)MDOMAIN_CAP_main_comp_setting_reg))
#define  MDOMAIN_CAP_main_comp_setting_cmp_a_ch_mark_shift                       (31)
#define  MDOMAIN_CAP_main_comp_setting_cmp_444to422_en_shift                     (30)
#define  MDOMAIN_CAP_main_comp_setting_cmp_rgb_yc_sel_shift                      (29)
#define  MDOMAIN_CAP_main_comp_setting_cmp_channel_bits_shift                    (28)
#define  MDOMAIN_CAP_main_comp_setting_compression_en_shift                      (20)
#define  MDOMAIN_CAP_main_comp_setting_max_pixel_bits_shift                      (12)
#define  MDOMAIN_CAP_main_comp_setting_short_term_bits_shift                     (6)
#define  MDOMAIN_CAP_main_comp_setting_frame_bits_shift                          (0)
#define  MDOMAIN_CAP_main_comp_setting_cmp_a_ch_mark_mask                        (0x80000000)
#define  MDOMAIN_CAP_main_comp_setting_cmp_444to422_en_mask                      (0x40000000)
#define  MDOMAIN_CAP_main_comp_setting_cmp_rgb_yc_sel_mask                       (0x20000000)
#define  MDOMAIN_CAP_main_comp_setting_cmp_channel_bits_mask                     (0x10000000)
#define  MDOMAIN_CAP_main_comp_setting_compression_en_mask                       (0x00100000)
#define  MDOMAIN_CAP_main_comp_setting_max_pixel_bits_mask                       (0x0003F000)
#define  MDOMAIN_CAP_main_comp_setting_short_term_bits_mask                      (0x00000FC0)
#define  MDOMAIN_CAP_main_comp_setting_frame_bits_mask                           (0x0000003F)
#define  MDOMAIN_CAP_main_comp_setting_cmp_a_ch_mark(data)                       (0x80000000&((data)<<31))
#define  MDOMAIN_CAP_main_comp_setting_cmp_444to422_en(data)                     (0x40000000&((data)<<30))
#define  MDOMAIN_CAP_main_comp_setting_cmp_rgb_yc_sel(data)                      (0x20000000&((data)<<29))
#define  MDOMAIN_CAP_main_comp_setting_cmp_channel_bits(data)                    (0x10000000&((data)<<28))
#define  MDOMAIN_CAP_main_comp_setting_compression_en(data)                      (0x00100000&((data)<<20))
#define  MDOMAIN_CAP_main_comp_setting_max_pixel_bits(data)                      (0x0003F000&((data)<<12))
#define  MDOMAIN_CAP_main_comp_setting_short_term_bits(data)                     (0x00000FC0&((data)<<6))
#define  MDOMAIN_CAP_main_comp_setting_frame_bits(data)                          (0x0000003F&(data))
#define  MDOMAIN_CAP_main_comp_setting_get_cmp_a_ch_mark(data)                   ((0x80000000&(data))>>31)
#define  MDOMAIN_CAP_main_comp_setting_get_cmp_444to422_en(data)                 ((0x40000000&(data))>>30)
#define  MDOMAIN_CAP_main_comp_setting_get_cmp_rgb_yc_sel(data)                  ((0x20000000&(data))>>29)
#define  MDOMAIN_CAP_main_comp_setting_get_cmp_channel_bits(data)                ((0x10000000&(data))>>28)
#define  MDOMAIN_CAP_main_comp_setting_get_compression_en(data)                  ((0x00100000&(data))>>20)
#define  MDOMAIN_CAP_main_comp_setting_get_max_pixel_bits(data)                  ((0x0003F000&(data))>>12)
#define  MDOMAIN_CAP_main_comp_setting_get_short_term_bits(data)                 ((0x00000FC0&(data))>>6)
#define  MDOMAIN_CAP_main_comp_setting_get_frame_bits(data)                      (0x0000003F&(data))

#define  MDOMAIN_CAP_main_threshold                                              0x180272E8
#define  MDOMAIN_CAP_main_threshold_reg_addr                                     "0xB80272E8"
#define  MDOMAIN_CAP_main_threshold_reg                                          0xB80272E8
#define  MDOMAIN_CAP_main_threshold_inst_addr                                    "0x0033"
#define  set_MDOMAIN_CAP_main_threshold_reg(data)                                (*((volatile unsigned int*)MDOMAIN_CAP_main_threshold_reg)=data)
#define  get_MDOMAIN_CAP_main_threshold_reg                                      (*((volatile unsigned int*)MDOMAIN_CAP_main_threshold_reg))
#define  MDOMAIN_CAP_main_threshold_delta_down_shift                             (8)
#define  MDOMAIN_CAP_main_threshold_delta_up_shift                               (0)
#define  MDOMAIN_CAP_main_threshold_delta_down_mask                              (0x0000FF00)
#define  MDOMAIN_CAP_main_threshold_delta_up_mask                                (0x000000FF)
#define  MDOMAIN_CAP_main_threshold_delta_down(data)                             (0x0000FF00&((data)<<8))
#define  MDOMAIN_CAP_main_threshold_delta_up(data)                               (0x000000FF&(data))
#define  MDOMAIN_CAP_main_threshold_get_delta_down(data)                         ((0x0000FF00&(data))>>8)
#define  MDOMAIN_CAP_main_threshold_get_delta_up(data)                           (0x000000FF&(data))

#define  MDOMAIN_CAP_main_compress                                               0x180272EC
#define  MDOMAIN_CAP_main_compress_reg_addr                                      "0xB80272EC"
#define  MDOMAIN_CAP_main_compress_reg                                           0xB80272EC
#define  MDOMAIN_CAP_main_compress_inst_addr                                     "0x0034"
#define  set_MDOMAIN_CAP_main_compress_reg(data)                                 (*((volatile unsigned int*)MDOMAIN_CAP_main_compress_reg)=data)
#define  get_MDOMAIN_CAP_main_compress_reg                                       (*((volatile unsigned int*)MDOMAIN_CAP_main_compress_reg))
#define  MDOMAIN_CAP_main_compress_comp_debug_mux_shift                          (16)
#define  MDOMAIN_CAP_main_compress_not_segement_status_clr_shift                 (9)
#define  MDOMAIN_CAP_main_compress_pixel_num_status_clr_shift                    (8)
#define  MDOMAIN_CAP_main_compress_over_bits_status_clr_shift                    (7)
#define  MDOMAIN_CAP_main_compress_comp_irq_shift                                (6)
#define  MDOMAIN_CAP_main_compress_comp_irq_en_shift                             (3)
#define  MDOMAIN_CAP_main_compress_comp_status_shift                             (0)
#define  MDOMAIN_CAP_main_compress_comp_debug_mux_mask                           (0x00FF0000)
#define  MDOMAIN_CAP_main_compress_not_segement_status_clr_mask                  (0x00000200)
#define  MDOMAIN_CAP_main_compress_pixel_num_status_clr_mask                     (0x00000100)
#define  MDOMAIN_CAP_main_compress_over_bits_status_clr_mask                     (0x00000080)
#define  MDOMAIN_CAP_main_compress_comp_irq_mask                                 (0x00000040)
#define  MDOMAIN_CAP_main_compress_comp_irq_en_mask                              (0x00000038)
#define  MDOMAIN_CAP_main_compress_comp_status_mask                              (0x00000007)
#define  MDOMAIN_CAP_main_compress_comp_debug_mux(data)                          (0x00FF0000&((data)<<16))
#define  MDOMAIN_CAP_main_compress_not_segement_status_clr(data)                 (0x00000200&((data)<<9))
#define  MDOMAIN_CAP_main_compress_pixel_num_status_clr(data)                    (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_main_compress_over_bits_status_clr(data)                    (0x00000080&((data)<<7))
#define  MDOMAIN_CAP_main_compress_comp_irq(data)                                (0x00000040&((data)<<6))
#define  MDOMAIN_CAP_main_compress_comp_irq_en(data)                             (0x00000038&((data)<<3))
#define  MDOMAIN_CAP_main_compress_comp_status(data)                             (0x00000007&(data))
#define  MDOMAIN_CAP_main_compress_get_comp_debug_mux(data)                      ((0x00FF0000&(data))>>16)
#define  MDOMAIN_CAP_main_compress_get_not_segement_status_clr(data)             ((0x00000200&(data))>>9)
#define  MDOMAIN_CAP_main_compress_get_pixel_num_status_clr(data)                ((0x00000100&(data))>>8)
#define  MDOMAIN_CAP_main_compress_get_over_bits_status_clr(data)                ((0x00000080&(data))>>7)
#define  MDOMAIN_CAP_main_compress_get_comp_irq(data)                            ((0x00000040&(data))>>6)
#define  MDOMAIN_CAP_main_compress_get_comp_irq_en(data)                         ((0x00000038&(data))>>3)
#define  MDOMAIN_CAP_main_compress_get_comp_status(data)                         (0x00000007&(data))

#define  MDOMAIN_CAP_Smooth_tog_ctrl_0                                           0x180272F0
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_reg_addr                                  "0xB80272F0"
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_reg                                       0xB80272F0
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_inst_addr                                 "0x0035"
#define  set_MDOMAIN_CAP_Smooth_tog_ctrl_0_reg(data)                             (*((volatile unsigned int*)MDOMAIN_CAP_Smooth_tog_ctrl_0_reg)=data)
#define  get_MDOMAIN_CAP_Smooth_tog_ctrl_0_reg                                   (*((volatile unsigned int*)MDOMAIN_CAP_Smooth_tog_ctrl_0_reg))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispd_fs_3d_en_sub_shift                  (9)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispi_fs_3d_en_sub_shift                  (8)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispd_fs_3d_en_shift                      (5)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispi_fs_3d_en_shift                      (4)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dummy_shift_2                               (2)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dummy_shift_1                               (1)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_main_sub_db_sel_shift                     (0)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispd_fs_3d_en_sub_mask                   (0x00000200)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispi_fs_3d_en_sub_mask                   (0x00000100)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispd_fs_3d_en_mask                       (0x00000020)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispi_fs_3d_en_mask                       (0x00000010)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dummy_mask_2                                (0x00000004)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dummy_mask_1                                (0x00000002)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_main_sub_db_sel_mask                      (0x00000001)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispd_fs_3d_en_sub(data)                  (0x00000200&((data)<<9))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispi_fs_3d_en_sub(data)                  (0x00000100&((data)<<8))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispd_fs_3d_en(data)                      (0x00000020&((data)<<5))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dispi_fs_3d_en(data)                      (0x00000010&((data)<<4))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dummy_2(data)                               (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_dummy_1(data)                               (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_main_sub_db_sel(data)                     (0x00000001&(data))
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_dispd_fs_3d_en_sub(data)              ((0x00000200&(data))>>9)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_dispi_fs_3d_en_sub(data)              ((0x00000100&(data))>>8)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_dispd_fs_3d_en(data)                  ((0x00000020&(data))>>5)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_dispi_fs_3d_en(data)                  ((0x00000010&(data))>>4)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_dummy_2(data)                           ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_dummy_1(data)                           ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_Smooth_tog_ctrl_0_get_main_sub_db_sel(data)                 (0x00000001&(data))

#define  MDOMAIN_CAP_Smooth_tog_status_0                                         0x180272F4
#define  MDOMAIN_CAP_Smooth_tog_status_0_reg_addr                                "0xB80272F4"
#define  MDOMAIN_CAP_Smooth_tog_status_0_reg                                     0xB80272F4
#define  MDOMAIN_CAP_Smooth_tog_status_0_inst_addr                               "0x0036"
#define  set_MDOMAIN_CAP_Smooth_tog_status_0_reg(data)                           (*((volatile unsigned int*)MDOMAIN_CAP_Smooth_tog_status_0_reg)=data)
#define  get_MDOMAIN_CAP_Smooth_tog_status_0_reg                                 (*((volatile unsigned int*)MDOMAIN_CAP_Smooth_tog_status_0_reg))
#define  MDOMAIN_CAP_Smooth_tog_status_0_md_reg_is_db_sub_shift                  (3)
#define  MDOMAIN_CAP_Smooth_tog_status_0_im_reg_is_db_sub_shift                  (2)
#define  MDOMAIN_CAP_Smooth_tog_status_0_md_reg_is_db_shift                      (1)
#define  MDOMAIN_CAP_Smooth_tog_status_0_im_reg_is_db_shift                      (0)
#define  MDOMAIN_CAP_Smooth_tog_status_0_md_reg_is_db_sub_mask                   (0x00000008)
#define  MDOMAIN_CAP_Smooth_tog_status_0_im_reg_is_db_sub_mask                   (0x00000004)
#define  MDOMAIN_CAP_Smooth_tog_status_0_md_reg_is_db_mask                       (0x00000002)
#define  MDOMAIN_CAP_Smooth_tog_status_0_im_reg_is_db_mask                       (0x00000001)
#define  MDOMAIN_CAP_Smooth_tog_status_0_md_reg_is_db_sub(data)                  (0x00000008&((data)<<3))
#define  MDOMAIN_CAP_Smooth_tog_status_0_im_reg_is_db_sub(data)                  (0x00000004&((data)<<2))
#define  MDOMAIN_CAP_Smooth_tog_status_0_md_reg_is_db(data)                      (0x00000002&((data)<<1))
#define  MDOMAIN_CAP_Smooth_tog_status_0_im_reg_is_db(data)                      (0x00000001&(data))
#define  MDOMAIN_CAP_Smooth_tog_status_0_get_md_reg_is_db_sub(data)              ((0x00000008&(data))>>3)
#define  MDOMAIN_CAP_Smooth_tog_status_0_get_im_reg_is_db_sub(data)              ((0x00000004&(data))>>2)
#define  MDOMAIN_CAP_Smooth_tog_status_0_get_md_reg_is_db(data)                  ((0x00000002&(data))>>1)
#define  MDOMAIN_CAP_Smooth_tog_status_0_get_im_reg_is_db(data)                  (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MDOMAIN_CAP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  in1_wtlvl:9;
        RBus_UInt32  in1_write_num:16;
    };
}mdomain_cap_ddr_in1wtlvl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  in1_wrlen:8;
        RBus_UInt32  in1_write_remain:8;
    };
}mdomain_cap_ddr_in1wrlen_rem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_wr_mem_start:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in1addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_line_step:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in1linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_block_step:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in1blkstep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_sec_bl:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in1_2ndaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_third_bl:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in1_3rdaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  in1_zero:1;
        RBus_UInt32  in1_frame_access_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  in1_line_number:13;
    };
}mdomain_cap_ddr_in1linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispm_ddr_checksum_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  in1_unfreeze_wait:3;
        RBus_UInt32  in1_auto_unfreeze:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  in1_freeze_control:1;
        RBus_UInt32  in1_bad_edit_suppression:1;
        RBus_UInt32  dispm_dbg_sel:4;
        RBus_UInt32  in1_l_flag_inv:1;
        RBus_UInt32  in1_rm_r_vs_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  in1_v_flip_3buf_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  in1_merge_enable:1;
        RBus_UInt32  in1_double_enable:1;
        RBus_UInt32  in1_block_free:1;
        RBus_UInt32  in1_single_buffer_select:2;
        RBus_UInt32  in1_freeze_enable:1;
        RBus_UInt32  in1_en_vs_rst:1;
    };
}mdomain_cap_ddr_in1ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  in1_block_select:2;
        RBus_UInt32  in1_freeze_ok:1;
        RBus_UInt32  in1_field_polarity_error:1;
        RBus_UInt32  in1_field_polarity_status:4;
    };
}mdomain_cap_ddr_in1status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  in1_cap_enable:1;
    };
}mdomain_cap_cap_in1_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  in2_wtlvl:8;
        RBus_UInt32  in2_write_num:16;
    };
}mdomain_cap_ddr_in2wtlvl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  in2_wrlen:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  in2_write_remain:7;
    };
}mdomain_cap_ddr_in2wrlen_rem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_wr_mem_start:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in2addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_line_step:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in2linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_block_step:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in2blkstep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_sec_bl:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in2_2ndaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_third_bl:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_ddr_in2_3rdaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  in2_zero:1;
        RBus_UInt32  in2_frame_access_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  in2_line_number:13;
    };
}mdomain_cap_ddr_in2linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  in2_sub_use_main_block_en:1;
        RBus_UInt32  in2_unfreeze_wait:3;
        RBus_UInt32  in2_auto_unfreeze:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  in2_freeze_control:1;
        RBus_UInt32  in2_bad_edit_suppression:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  in2_v_flip_3buf_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  in2_merge_enable:1;
        RBus_UInt32  in2_double_enable:1;
        RBus_UInt32  in2_block_free:1;
        RBus_UInt32  in2_single_buffer_select:2;
        RBus_UInt32  in2_freeze_enable:1;
        RBus_UInt32  in2_en_vs_rst:1;
    };
}mdomain_cap_ddr_in2ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  in2_cap_enable:1;
    };
}mdomain_cap_cap_in2_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  in2_block_select:2;
        RBus_UInt32  in2_freeze_ok:1;
        RBus_UInt32  in2_field_polarity_error:1;
        RBus_UInt32  in2_field_polarity_status:4;
    };
}mdomain_cap_ddr_in2status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cap2_db_apply:1;
        RBus_UInt32  cap2_db_sel:1;
        RBus_UInt32  cap2_db_en:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  cap1_db_apply:1;
        RBus_UInt32  cap1_db_sel:1;
        RBus_UInt32  cap1_db_en:1;
    };
}mdomain_cap_cap_reg_doublbuffer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  in1_cap_first_wr_flag:1;
        RBus_UInt32  in1_cap_last_wr_flag:1;
        RBus_UInt32  in1_fifofull:1;
        RBus_UInt32  in1_fifoempty:1;
        RBus_UInt32  in1_fifouf:1;
        RBus_UInt32  in1_fifoof:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  in2_cap_first_wr_flag:1;
        RBus_UInt32  in2_cap_last_wr_flag:1;
        RBus_UInt32  in2_fifofull:1;
        RBus_UInt32  in2_fifoempty:1;
        RBus_UInt32  in2_fifouf:1;
        RBus_UInt32  in2_fifoof:1;
    };
}mdomain_cap_cap_ddr_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  in1_drop:1;
        RBus_UInt32  in1_over_size:1;
        RBus_UInt32  in1_under_size:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  in2_drop:1;
        RBus_UInt32  in2_over_size:1;
        RBus_UInt32  in2_under_size:1;
    };
}mdomain_cap_cap_help_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_cap_downlimit_adr:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_capmain_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_cap_uplimit_adr:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_capmain_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  in1_cap_downlimit_ov:1;
        RBus_UInt32  in1_cap_uplimit_ov:1;
    };
}mdomain_cap_di1cap_wrrd_boundaryadd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_cap_downlimit_adr:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_capsub_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_cap_uplimit_adr:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_capsub_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  in2_cap_downlimit_ov:1;
        RBus_UInt32  in2_cap_uplimit_ov:1;
    };
}mdomain_cap_di2cap_wrrd_boundaryadd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  in1_cap_first_wr_wde:1;
        RBus_UInt32  in1_cap_first_wr_ie:1;
        RBus_UInt32  in1_fifoerr_ie:1;
        RBus_UInt32  in1_cap_last_wr_ie:1;
        RBus_UInt32  in1_fifoerr_wde:1;
        RBus_UInt32  in1_cap_last_wr_wde:1;
        RBus_UInt32  wd_to_main:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  in2_cap_first_wr_wde:1;
        RBus_UInt32  in2_cap_first_wr_ie:1;
        RBus_UInt32  in2_fifoerr_ie:1;
        RBus_UInt32  in2_cap_last_wr_ie:1;
        RBus_UInt32  in2_fifoerr_wde:1;
        RBus_UInt32  in2_cap_last_wr_wde:1;
        RBus_UInt32  wd_to_sub:1;
    };
}mdomain_cap_cap_ie_wd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  in1_sbs_vsd_en:1;
    };
}mdomain_cap_capmain_sbs_vsd_cap_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_lr_offset:29;
        RBus_UInt32  res1:3;
    };
}mdomain_cap_capmain_sbs_vsd_cap_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  crc_comp_error_int:1;
        RBus_UInt32  dynamic_crc_cmp_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  crc_bit_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  disp_crc_3d_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  disp_crc_conti:1;
        RBus_UInt32  disp_crc_start:1;
        RBus_UInt32  cap_crc_3d_en:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  cap_crc_conti:1;
        RBus_UInt32  cap_crc_start:1;
    };
}mdomain_cap_dispm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  match_buffer:2;
        RBus_UInt32  res2:15;
        RBus_UInt32  crc_comp_error_flag:1;
    };
}mdomain_cap_dispm_crc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_mask:32;
    };
}mdomain_cap_crc_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l_crc_result:32;
    };
}mdomain_cap_cap_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r_crc_result:32;
    };
}mdomain_cap_cap_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_l_crc_result:32;
    };
}mdomain_cap_disp_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_r_crc_result:32;
    };
}mdomain_cap_display_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  in1_rate_en:1;
    };
}mdomain_cap_cap_dma_rate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_rate:32;
    };
}mdomain_cap_capture_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  in2_8byte_swap:1;
        RBus_UInt32  in2_4byte_swap:1;
        RBus_UInt32  in2_2byte_swap:1;
        RBus_UInt32  in2_1byte_swap:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  in1_8byte_swap:1;
        RBus_UInt32  in1_4byte_swap:1;
        RBus_UInt32  in1_2byte_swap:1;
        RBus_UInt32  in1_1byte_swap:1;
    };
}mdomain_cap_capture_byte_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  rgb565_en:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  res2:16;
    };
}mdomain_cap_main_sdnr_cxxto64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sub_out_bit:1;
        RBus_UInt32  sub_sort_fmt:1;
        RBus_UInt32  sub_rgb565_en:1;
        RBus_UInt32  sub_rgb_to_argb_en:1;
        RBus_UInt32  sub_argb_swap:1;
        RBus_UInt32  sub_argb_dummy_data:8;
        RBus_UInt32  res2:16;
    };
}mdomain_cap_sub_sdnr_cxxto64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  wd_fsync_ovf_en:1;
        RBus_UInt32  wd_fsync_udf_en:1;
        RBus_UInt32  wd_ibuff_ovf_en:1;
        RBus_UInt32  wd_ibuff_to_main:1;
        RBus_UInt32  wd_ibuff_to_sub:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  irq_fsync_ovf_en:1;
        RBus_UInt32  irq_fsync_udf_en:1;
        RBus_UInt32  irq_ibuff_ovf_en:1;
        RBus_UInt32  res3:8;
    };
}mdomain_cap_ich1_ibuff_status_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  wd_fsync_ovf_en_sub:1;
        RBus_UInt32  wd_fsync_udf_en_sub:1;
        RBus_UInt32  wd_ibuff_ovf_en_sub:1;
        RBus_UInt32  wd_ibuff_to_main_sub:1;
        RBus_UInt32  wd_ibuff_to_sub_sub:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  irq_fsync_ovf_en_sub:1;
        RBus_UInt32  irq_fsync_udf_en_sub:1;
        RBus_UInt32  irq_ibuff_ovf_en_sub:1;
        RBus_UInt32  res3:8;
    };
}mdomain_cap_ich2_ibuff_status_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  q_sbs_lr_ovf_sub:1;
        RBus_UInt32  q_sbs_lr_udf_sub:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ibuff_ovf_sub:1;
        RBus_UInt32  fsync_ovf_sub:1;
        RBus_UInt32  fsync_udf_sub:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  q_sbs_lr_ovf:1;
        RBus_UInt32  q_sbs_lr_udf:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  ibuff_ovf:1;
        RBus_UInt32  fsync_ovf:1;
        RBus_UInt32  fsync_udf:1;
    };
}mdomain_cap_ich12_ibuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cmp_segment:2;
        RBus_UInt32  cmp_width:8;
        RBus_UInt32  cmp_height:16;
    };
}mdomain_cap_main_cmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_a_ch_mark:1;
        RBus_UInt32  cmp_444to422_en:1;
        RBus_UInt32  cmp_rgb_yc_sel:1;
        RBus_UInt32  cmp_channel_bits:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  compression_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  max_pixel_bits:6;
        RBus_UInt32  short_term_bits:6;
        RBus_UInt32  frame_bits:6;
    };
}mdomain_cap_main_comp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  delta_down:8;
        RBus_UInt32  delta_up:8;
    };
}mdomain_cap_main_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  comp_debug_mux:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  not_segement_status_clr:1;
        RBus_UInt32  pixel_num_status_clr:1;
        RBus_UInt32  over_bits_status_clr:1;
        RBus_UInt32  comp_irq:1;
        RBus_UInt32  comp_irq_en:3;
        RBus_UInt32  comp_status:3;
    };
}mdomain_cap_main_compress_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  dispd_fs_3d_en_sub:1;
        RBus_UInt32  dispi_fs_3d_en_sub:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dispd_fs_3d_en:1;
        RBus_UInt32  dispi_fs_3d_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dummy180272f0_2:1;
        RBus_UInt32  dummy180272f0_1:1;
        RBus_UInt32  main_sub_db_sel:1;
    };
}mdomain_cap_smooth_tog_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  md_reg_is_db_sub:1;
        RBus_UInt32  im_reg_is_db_sub:1;
        RBus_UInt32  md_reg_is_db:1;
        RBus_UInt32  im_reg_is_db:1;
    };
}mdomain_cap_smooth_tog_status_0_RBUS;

#else //apply LITTLE_ENDIAN

//======MDOMAIN_CAP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_write_num:16;
        RBus_UInt32  in1_wtlvl:9;
        RBus_UInt32  res1:7;
    };
}mdomain_cap_ddr_in1wtlvl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_write_remain:8;
        RBus_UInt32  in1_wrlen:8;
        RBus_UInt32  res1:16;
    };
}mdomain_cap_ddr_in1wrlen_rem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_wr_mem_start:29;
    };
}mdomain_cap_ddr_in1addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_line_step:29;
    };
}mdomain_cap_ddr_in1linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_block_step:29;
    };
}mdomain_cap_ddr_in1blkstep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_sec_bl:29;
    };
}mdomain_cap_ddr_in1_2ndaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_third_bl:29;
    };
}mdomain_cap_ddr_in1_3rdaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_line_number:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_frame_access_mode:1;
        RBus_UInt32  in1_zero:1;
        RBus_UInt32  res2:14;
    };
}mdomain_cap_ddr_in1linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_en_vs_rst:1;
        RBus_UInt32  in1_freeze_enable:1;
        RBus_UInt32  in1_single_buffer_select:2;
        RBus_UInt32  in1_block_free:1;
        RBus_UInt32  in1_double_enable:1;
        RBus_UInt32  in1_merge_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  in1_v_flip_3buf_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  in1_rm_r_vs_en:1;
        RBus_UInt32  in1_l_flag_inv:1;
        RBus_UInt32  dispm_dbg_sel:4;
        RBus_UInt32  in1_bad_edit_suppression:1;
        RBus_UInt32  in1_freeze_control:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  in1_auto_unfreeze:1;
        RBus_UInt32  in1_unfreeze_wait:3;
        RBus_UInt32  res4:7;
        RBus_UInt32  dispm_ddr_checksum_en:1;
    };
}mdomain_cap_ddr_in1ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_field_polarity_status:4;
        RBus_UInt32  in1_field_polarity_error:1;
        RBus_UInt32  in1_freeze_ok:1;
        RBus_UInt32  in1_block_select:2;
        RBus_UInt32  res1:24;
    };
}mdomain_cap_ddr_in1status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_cap_enable:1;
        RBus_UInt32  res1:31;
    };
}mdomain_cap_cap_in1_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_write_num:16;
        RBus_UInt32  in2_wtlvl:8;
        RBus_UInt32  res1:8;
    };
}mdomain_cap_ddr_in2wtlvl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_write_remain:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  in2_wrlen:7;
        RBus_UInt32  res2:17;
    };
}mdomain_cap_ddr_in2wrlen_rem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_wr_mem_start:29;
    };
}mdomain_cap_ddr_in2addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_line_step:29;
    };
}mdomain_cap_ddr_in2linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_block_step:29;
    };
}mdomain_cap_ddr_in2blkstep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_sec_bl:29;
    };
}mdomain_cap_ddr_in2_2ndaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_third_bl:29;
    };
}mdomain_cap_ddr_in2_3rdaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_line_number:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_frame_access_mode:1;
        RBus_UInt32  in2_zero:1;
        RBus_UInt32  res2:14;
    };
}mdomain_cap_ddr_in2linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_en_vs_rst:1;
        RBus_UInt32  in2_freeze_enable:1;
        RBus_UInt32  in2_single_buffer_select:2;
        RBus_UInt32  in2_block_free:1;
        RBus_UInt32  in2_double_enable:1;
        RBus_UInt32  in2_merge_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  in2_v_flip_3buf_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  in2_bad_edit_suppression:1;
        RBus_UInt32  in2_freeze_control:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  in2_auto_unfreeze:1;
        RBus_UInt32  in2_unfreeze_wait:3;
        RBus_UInt32  in2_sub_use_main_block_en:1;
        RBus_UInt32  res4:7;
    };
}mdomain_cap_ddr_in2ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_cap_enable:1;
        RBus_UInt32  res1:31;
    };
}mdomain_cap_cap_in2_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_field_polarity_status:4;
        RBus_UInt32  in2_field_polarity_error:1;
        RBus_UInt32  in2_freeze_ok:1;
        RBus_UInt32  in2_block_select:2;
        RBus_UInt32  res1:24;
    };
}mdomain_cap_ddr_in2status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap1_db_en:1;
        RBus_UInt32  cap1_db_sel:1;
        RBus_UInt32  cap1_db_apply:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  cap2_db_en:1;
        RBus_UInt32  cap2_db_sel:1;
        RBus_UInt32  cap2_db_apply:1;
        RBus_UInt32  res2:13;
    };
}mdomain_cap_cap_reg_doublbuffer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_fifoof:1;
        RBus_UInt32  in2_fifouf:1;
        RBus_UInt32  in2_fifoempty:1;
        RBus_UInt32  in2_fifofull:1;
        RBus_UInt32  in2_cap_last_wr_flag:1;
        RBus_UInt32  in2_cap_first_wr_flag:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  in1_fifoof:1;
        RBus_UInt32  in1_fifouf:1;
        RBus_UInt32  in1_fifoempty:1;
        RBus_UInt32  in1_fifofull:1;
        RBus_UInt32  in1_cap_last_wr_flag:1;
        RBus_UInt32  in1_cap_first_wr_flag:1;
        RBus_UInt32  res2:10;
    };
}mdomain_cap_cap_ddr_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_under_size:1;
        RBus_UInt32  in2_over_size:1;
        RBus_UInt32  in2_drop:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  in1_under_size:1;
        RBus_UInt32  in1_over_size:1;
        RBus_UInt32  in1_drop:1;
        RBus_UInt32  res2:13;
    };
}mdomain_cap_cap_help_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_cap_downlimit_adr:29;
    };
}mdomain_cap_capmain_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_cap_uplimit_adr:29;
    };
}mdomain_cap_capmain_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_cap_uplimit_ov:1;
        RBus_UInt32  in1_cap_downlimit_ov:1;
        RBus_UInt32  res1:30;
    };
}mdomain_cap_di1cap_wrrd_boundaryadd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_cap_downlimit_adr:29;
    };
}mdomain_cap_capsub_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in2_cap_uplimit_adr:29;
    };
}mdomain_cap_capsub_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in2_cap_uplimit_ov:1;
        RBus_UInt32  in2_cap_downlimit_ov:1;
        RBus_UInt32  res1:30;
    };
}mdomain_cap_di2cap_wrrd_boundaryadd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wd_to_sub:1;
        RBus_UInt32  in2_cap_last_wr_wde:1;
        RBus_UInt32  in2_fifoerr_wde:1;
        RBus_UInt32  in2_cap_last_wr_ie:1;
        RBus_UInt32  in2_fifoerr_ie:1;
        RBus_UInt32  in2_cap_first_wr_ie:1;
        RBus_UInt32  in2_cap_first_wr_wde:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  wd_to_main:1;
        RBus_UInt32  in1_cap_last_wr_wde:1;
        RBus_UInt32  in1_fifoerr_wde:1;
        RBus_UInt32  in1_cap_last_wr_ie:1;
        RBus_UInt32  in1_fifoerr_ie:1;
        RBus_UInt32  in1_cap_first_wr_ie:1;
        RBus_UInt32  in1_cap_first_wr_wde:1;
        RBus_UInt32  res2:9;
    };
}mdomain_cap_cap_ie_wd_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_sbs_vsd_en:1;
        RBus_UInt32  res1:31;
    };
}mdomain_cap_capmain_sbs_vsd_cap_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  in1_lr_offset:29;
    };
}mdomain_cap_capmain_sbs_vsd_cap_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_crc_start:1;
        RBus_UInt32  cap_crc_conti:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_crc_3d_en:1;
        RBus_UInt32  disp_crc_start:1;
        RBus_UInt32  disp_crc_conti:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp_crc_3d_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  crc_bit_sel:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  dynamic_crc_cmp_en:1;
        RBus_UInt32  crc_comp_error_int:1;
        RBus_UInt32  res5:17;
    };
}mdomain_cap_dispm_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_comp_error_flag:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  match_buffer:2;
        RBus_UInt32  res2:14;
    };
}mdomain_cap_dispm_crc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_mask:32;
    };
}mdomain_cap_crc_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l_crc_result:32;
    };
}mdomain_cap_cap_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r_crc_result:32;
    };
}mdomain_cap_cap_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_l_crc_result:32;
    };
}mdomain_cap_disp_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_r_crc_result:32;
    };
}mdomain_cap_display_r_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_rate_en:1;
        RBus_UInt32  res1:31;
    };
}mdomain_cap_cap_dma_rate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_rate:32;
    };
}mdomain_cap_capture_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in1_1byte_swap:1;
        RBus_UInt32  in1_2byte_swap:1;
        RBus_UInt32  in1_4byte_swap:1;
        RBus_UInt32  in1_8byte_swap:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  in2_1byte_swap:1;
        RBus_UInt32  in2_2byte_swap:1;
        RBus_UInt32  in2_4byte_swap:1;
        RBus_UInt32  in2_8byte_swap:1;
        RBus_UInt32  res2:12;
    };
}mdomain_cap_capture_byte_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  rgb565_en:1;
        RBus_UInt32  sort_fmt:1;
        RBus_UInt32  out_bit:1;
        RBus_UInt32  res2:3;
    };
}mdomain_cap_main_sdnr_cxxto64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sub_argb_dummy_data:8;
        RBus_UInt32  sub_argb_swap:1;
        RBus_UInt32  sub_rgb_to_argb_en:1;
        RBus_UInt32  sub_rgb565_en:1;
        RBus_UInt32  sub_sort_fmt:1;
        RBus_UInt32  sub_out_bit:1;
        RBus_UInt32  res2:3;
    };
}mdomain_cap_sub_sdnr_cxxto64_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  irq_ibuff_ovf_en:1;
        RBus_UInt32  irq_fsync_udf_en:1;
        RBus_UInt32  irq_fsync_ovf_en:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  wd_ibuff_to_sub:1;
        RBus_UInt32  wd_ibuff_to_main:1;
        RBus_UInt32  wd_ibuff_ovf_en:1;
        RBus_UInt32  wd_fsync_udf_en:1;
        RBus_UInt32  wd_fsync_ovf_en:1;
        RBus_UInt32  res3:11;
    };
}mdomain_cap_ich1_ibuff_status_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  irq_ibuff_ovf_en_sub:1;
        RBus_UInt32  irq_fsync_udf_en_sub:1;
        RBus_UInt32  irq_fsync_ovf_en_sub:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  wd_ibuff_to_sub_sub:1;
        RBus_UInt32  wd_ibuff_to_main_sub:1;
        RBus_UInt32  wd_ibuff_ovf_en_sub:1;
        RBus_UInt32  wd_fsync_udf_en_sub:1;
        RBus_UInt32  wd_fsync_ovf_en_sub:1;
        RBus_UInt32  res3:11;
    };
}mdomain_cap_ich2_ibuff_status_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_udf:1;
        RBus_UInt32  fsync_ovf:1;
        RBus_UInt32  ibuff_ovf:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  q_sbs_lr_udf:1;
        RBus_UInt32  q_sbs_lr_ovf:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  fsync_udf_sub:1;
        RBus_UInt32  fsync_ovf_sub:1;
        RBus_UInt32  ibuff_ovf_sub:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  q_sbs_lr_udf_sub:1;
        RBus_UInt32  q_sbs_lr_ovf_sub:1;
        RBus_UInt32  res4:18;
    };
}mdomain_cap_ich12_ibuff_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_height:16;
        RBus_UInt32  cmp_width:8;
        RBus_UInt32  cmp_segment:2;
        RBus_UInt32  res1:6;
    };
}mdomain_cap_main_cmp_resolution_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_bits:6;
        RBus_UInt32  short_term_bits:6;
        RBus_UInt32  max_pixel_bits:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  compression_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  cmp_channel_bits:1;
        RBus_UInt32  cmp_rgb_yc_sel:1;
        RBus_UInt32  cmp_444to422_en:1;
        RBus_UInt32  cmp_a_ch_mark:1;
    };
}mdomain_cap_main_comp_setting_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta_up:8;
        RBus_UInt32  delta_down:8;
        RBus_UInt32  res1:16;
    };
}mdomain_cap_main_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_status:3;
        RBus_UInt32  comp_irq_en:3;
        RBus_UInt32  comp_irq:1;
        RBus_UInt32  over_bits_status_clr:1;
        RBus_UInt32  pixel_num_status_clr:1;
        RBus_UInt32  not_segement_status_clr:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  comp_debug_mux:8;
        RBus_UInt32  res2:8;
    };
}mdomain_cap_main_compress_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_sub_db_sel:1;
        RBus_UInt32  dummy180272f0_1:1;
        RBus_UInt32  dummy180272f0_2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dispi_fs_3d_en:1;
        RBus_UInt32  dispd_fs_3d_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dispi_fs_3d_en_sub:1;
        RBus_UInt32  dispd_fs_3d_en_sub:1;
        RBus_UInt32  res3:22;
    };
}mdomain_cap_smooth_tog_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  im_reg_is_db:1;
        RBus_UInt32  md_reg_is_db:1;
        RBus_UInt32  im_reg_is_db_sub:1;
        RBus_UInt32  md_reg_is_db_sub:1;
        RBus_UInt32  res1:28;
    };
}mdomain_cap_smooth_tog_status_0_RBUS;




#endif


#endif
