/**
* @file Mac5-DesignSpec-TP
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TP_REG_H_
#define _RBUS_TP_REG_H_

#include "rbus_types.h"



//  TP Register Address
#define  TP_TP_TF0_CNTL                                                          0x18014000
#define  TP_TP_TF0_CNTL_reg_addr                                                 "0xB8014000"
#define  TP_TP_TF0_CNTL_reg                                                      0xB8014000
#define  TP_TP_TF0_CNTL_inst_addr                                                "0x0000"
#define  set_TP_TP_TF0_CNTL_reg(data)                                            (*((volatile unsigned int*)TP_TP_TF0_CNTL_reg)=data)
#define  get_TP_TP_TF0_CNTL_reg                                                  (*((volatile unsigned int*)TP_TP_TF0_CNTL_reg))
#define  TP_TP_TF0_CNTL_two_bit_shift                                            (31)
#define  TP_TP_TF0_CNTL_two_bit_reverse_shift                                    (30)
#define  TP_TP_TF0_CNTL_two_bit_sel_h_shift                                      (29)
#define  TP_TP_TF0_CNTL_two_bit_sel_l_shift                                      (28)
#define  TP_TP_TF0_CNTL_src_sel_h_shift                                          (25)
#define  TP_TP_TF0_CNTL_src_sel_l_shift                                          (24)
#define  TP_TP_TF0_CNTL_dir_dma_shift                                            (23)
#define  TP_TP_TF0_CNTL_ci_mode_shift                                            (18)
#define  TP_TP_TF0_CNTL_tp_err_fix_en_shift                                      (17)
#define  TP_TP_TF0_CNTL_strm_id_en_shift                                         (16)
#define  TP_TP_TF0_CNTL_buf_rdy_ctl_shift                                        (15)
#define  TP_TP_TF0_CNTL_psc_en_shift                                             (14)
#define  TP_TP_TF0_CNTL_pes_en_shift                                             (13)
#define  TP_TP_TF0_CNTL_tsc_en_shift                                             (12)
#define  TP_TP_TF0_CNTL_tb_shift                                                 (11)
#define  TP_TP_TF0_CNTL_busy_shift                                               (10)
#define  TP_TP_TF0_CNTL_mode_shift                                               (9)
#define  TP_TP_TF0_CNTL_du_en_shift                                              (8)
#define  TP_TP_TF0_CNTL_de_en_shift                                              (7)
#define  TP_TP_TF0_CNTL_xt_en_shift                                              (6)
#define  TP_TP_TF0_CNTL_pid_en_shift                                             (5)
#define  TP_TP_TF0_CNTL_null_en_shift                                            (4)
#define  TP_TP_TF0_CNTL_trerr_en_shift                                           (3)
#define  TP_TP_TF0_CNTL_sync_en_shift                                            (2)
#define  TP_TP_TF0_CNTL_rst_en_shift                                             (1)
#define  TP_TP_TF0_CNTL_write_data_shift                                         (0)
#define  TP_TP_TF0_CNTL_two_bit_mask                                             (0x80000000)
#define  TP_TP_TF0_CNTL_two_bit_reverse_mask                                     (0x40000000)
#define  TP_TP_TF0_CNTL_two_bit_sel_h_mask                                       (0x20000000)
#define  TP_TP_TF0_CNTL_two_bit_sel_l_mask                                       (0x10000000)
#define  TP_TP_TF0_CNTL_src_sel_h_mask                                           (0x02000000)
#define  TP_TP_TF0_CNTL_src_sel_l_mask                                           (0x01000000)
#define  TP_TP_TF0_CNTL_dir_dma_mask                                             (0x00800000)
#define  TP_TP_TF0_CNTL_ci_mode_mask                                             (0x00040000)
#define  TP_TP_TF0_CNTL_tp_err_fix_en_mask                                       (0x00020000)
#define  TP_TP_TF0_CNTL_strm_id_en_mask                                          (0x00010000)
#define  TP_TP_TF0_CNTL_buf_rdy_ctl_mask                                         (0x00008000)
#define  TP_TP_TF0_CNTL_psc_en_mask                                              (0x00004000)
#define  TP_TP_TF0_CNTL_pes_en_mask                                              (0x00002000)
#define  TP_TP_TF0_CNTL_tsc_en_mask                                              (0x00001000)
#define  TP_TP_TF0_CNTL_tb_mask                                                  (0x00000800)
#define  TP_TP_TF0_CNTL_busy_mask                                                (0x00000400)
#define  TP_TP_TF0_CNTL_mode_mask                                                (0x00000200)
#define  TP_TP_TF0_CNTL_du_en_mask                                               (0x00000100)
#define  TP_TP_TF0_CNTL_de_en_mask                                               (0x00000080)
#define  TP_TP_TF0_CNTL_xt_en_mask                                               (0x00000040)
#define  TP_TP_TF0_CNTL_pid_en_mask                                              (0x00000020)
#define  TP_TP_TF0_CNTL_null_en_mask                                             (0x00000010)
#define  TP_TP_TF0_CNTL_trerr_en_mask                                            (0x00000008)
#define  TP_TP_TF0_CNTL_sync_en_mask                                             (0x00000004)
#define  TP_TP_TF0_CNTL_rst_en_mask                                              (0x00000002)
#define  TP_TP_TF0_CNTL_write_data_mask                                          (0x00000001)
#define  TP_TP_TF0_CNTL_two_bit(data)                                            (0x80000000&((data)<<31))
#define  TP_TP_TF0_CNTL_two_bit_reverse(data)                                    (0x40000000&((data)<<30))
#define  TP_TP_TF0_CNTL_two_bit_sel_h(data)                                      (0x20000000&((data)<<29))
#define  TP_TP_TF0_CNTL_two_bit_sel_l(data)                                      (0x10000000&((data)<<28))
#define  TP_TP_TF0_CNTL_src_sel_h(data)                                          (0x02000000&((data)<<25))
#define  TP_TP_TF0_CNTL_src_sel_l(data)                                          (0x01000000&((data)<<24))
#define  TP_TP_TF0_CNTL_dir_dma(data)                                            (0x00800000&((data)<<23))
#define  TP_TP_TF0_CNTL_ci_mode(data)                                            (0x00040000&((data)<<18))
#define  TP_TP_TF0_CNTL_tp_err_fix_en(data)                                      (0x00020000&((data)<<17))
#define  TP_TP_TF0_CNTL_strm_id_en(data)                                         (0x00010000&((data)<<16))
#define  TP_TP_TF0_CNTL_buf_rdy_ctl(data)                                        (0x00008000&((data)<<15))
#define  TP_TP_TF0_CNTL_psc_en(data)                                             (0x00004000&((data)<<14))
#define  TP_TP_TF0_CNTL_pes_en(data)                                             (0x00002000&((data)<<13))
#define  TP_TP_TF0_CNTL_tsc_en(data)                                             (0x00001000&((data)<<12))
#define  TP_TP_TF0_CNTL_tb(data)                                                 (0x00000800&((data)<<11))
#define  TP_TP_TF0_CNTL_busy(data)                                               (0x00000400&((data)<<10))
#define  TP_TP_TF0_CNTL_mode(data)                                               (0x00000200&((data)<<9))
#define  TP_TP_TF0_CNTL_du_en(data)                                              (0x00000100&((data)<<8))
#define  TP_TP_TF0_CNTL_de_en(data)                                              (0x00000080&((data)<<7))
#define  TP_TP_TF0_CNTL_xt_en(data)                                              (0x00000040&((data)<<6))
#define  TP_TP_TF0_CNTL_pid_en(data)                                             (0x00000020&((data)<<5))
#define  TP_TP_TF0_CNTL_null_en(data)                                            (0x00000010&((data)<<4))
#define  TP_TP_TF0_CNTL_trerr_en(data)                                           (0x00000008&((data)<<3))
#define  TP_TP_TF0_CNTL_sync_en(data)                                            (0x00000004&((data)<<2))
#define  TP_TP_TF0_CNTL_rst_en(data)                                             (0x00000002&((data)<<1))
#define  TP_TP_TF0_CNTL_write_data(data)                                         (0x00000001&(data))
#define  TP_TP_TF0_CNTL_get_two_bit(data)                                        ((0x80000000&(data))>>31)
#define  TP_TP_TF0_CNTL_get_two_bit_reverse(data)                                ((0x40000000&(data))>>30)
#define  TP_TP_TF0_CNTL_get_two_bit_sel_h(data)                                  ((0x20000000&(data))>>29)
#define  TP_TP_TF0_CNTL_get_two_bit_sel_l(data)                                  ((0x10000000&(data))>>28)
#define  TP_TP_TF0_CNTL_get_src_sel_h(data)                                      ((0x02000000&(data))>>25)
#define  TP_TP_TF0_CNTL_get_src_sel_l(data)                                      ((0x01000000&(data))>>24)
#define  TP_TP_TF0_CNTL_get_dir_dma(data)                                        ((0x00800000&(data))>>23)
#define  TP_TP_TF0_CNTL_get_ci_mode(data)                                        ((0x00040000&(data))>>18)
#define  TP_TP_TF0_CNTL_get_tp_err_fix_en(data)                                  ((0x00020000&(data))>>17)
#define  TP_TP_TF0_CNTL_get_strm_id_en(data)                                     ((0x00010000&(data))>>16)
#define  TP_TP_TF0_CNTL_get_buf_rdy_ctl(data)                                    ((0x00008000&(data))>>15)
#define  TP_TP_TF0_CNTL_get_psc_en(data)                                         ((0x00004000&(data))>>14)
#define  TP_TP_TF0_CNTL_get_pes_en(data)                                         ((0x00002000&(data))>>13)
#define  TP_TP_TF0_CNTL_get_tsc_en(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP_TF0_CNTL_get_tb(data)                                             ((0x00000800&(data))>>11)
#define  TP_TP_TF0_CNTL_get_busy(data)                                           ((0x00000400&(data))>>10)
#define  TP_TP_TF0_CNTL_get_mode(data)                                           ((0x00000200&(data))>>9)
#define  TP_TP_TF0_CNTL_get_du_en(data)                                          ((0x00000100&(data))>>8)
#define  TP_TP_TF0_CNTL_get_de_en(data)                                          ((0x00000080&(data))>>7)
#define  TP_TP_TF0_CNTL_get_xt_en(data)                                          ((0x00000040&(data))>>6)
#define  TP_TP_TF0_CNTL_get_pid_en(data)                                         ((0x00000020&(data))>>5)
#define  TP_TP_TF0_CNTL_get_null_en(data)                                        ((0x00000010&(data))>>4)
#define  TP_TP_TF0_CNTL_get_trerr_en(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP_TF0_CNTL_get_sync_en(data)                                        ((0x00000004&(data))>>2)
#define  TP_TP_TF0_CNTL_get_rst_en(data)                                         ((0x00000002&(data))>>1)
#define  TP_TP_TF0_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  TP_TP_TF0_STRM_ID_0                                                     0x18014004
#define  TP_TP_TF0_STRM_ID_0_reg_addr                                            "0xB8014004"
#define  TP_TP_TF0_STRM_ID_0_reg                                                 0xB8014004
#define  TP_TP_TF0_STRM_ID_0_inst_addr                                           "0x0001"
#define  set_TP_TP_TF0_STRM_ID_0_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_0_reg)=data)
#define  get_TP_TP_TF0_STRM_ID_0_reg                                             (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_0_reg))
#define  TP_TP_TF0_STRM_ID_0_set3_shift                                          (24)
#define  TP_TP_TF0_STRM_ID_0_set2_shift                                          (16)
#define  TP_TP_TF0_STRM_ID_0_set1_shift                                          (8)
#define  TP_TP_TF0_STRM_ID_0_set0_shift                                          (0)
#define  TP_TP_TF0_STRM_ID_0_set3_mask                                           (0xFF000000)
#define  TP_TP_TF0_STRM_ID_0_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF0_STRM_ID_0_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF0_STRM_ID_0_set0_mask                                           (0x000000FF)
#define  TP_TP_TF0_STRM_ID_0_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF0_STRM_ID_0_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF0_STRM_ID_0_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF0_STRM_ID_0_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF0_STRM_ID_0_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF0_STRM_ID_0_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF0_STRM_ID_0_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF0_STRM_ID_0_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF0_STRM_ID_1                                                     0x18014008
#define  TP_TP_TF0_STRM_ID_1_reg_addr                                            "0xB8014008"
#define  TP_TP_TF0_STRM_ID_1_reg                                                 0xB8014008
#define  TP_TP_TF0_STRM_ID_1_inst_addr                                           "0x0002"
#define  set_TP_TP_TF0_STRM_ID_1_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_1_reg)=data)
#define  get_TP_TP_TF0_STRM_ID_1_reg                                             (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_1_reg))
#define  TP_TP_TF0_STRM_ID_1_set3_shift                                          (24)
#define  TP_TP_TF0_STRM_ID_1_set2_shift                                          (16)
#define  TP_TP_TF0_STRM_ID_1_set1_shift                                          (8)
#define  TP_TP_TF0_STRM_ID_1_set0_shift                                          (0)
#define  TP_TP_TF0_STRM_ID_1_set3_mask                                           (0xFF000000)
#define  TP_TP_TF0_STRM_ID_1_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF0_STRM_ID_1_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF0_STRM_ID_1_set0_mask                                           (0x000000FF)
#define  TP_TP_TF0_STRM_ID_1_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF0_STRM_ID_1_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF0_STRM_ID_1_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF0_STRM_ID_1_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF0_STRM_ID_1_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF0_STRM_ID_1_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF0_STRM_ID_1_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF0_STRM_ID_1_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF0_STRM_ID_2                                                     0x1801400C
#define  TP_TP_TF0_STRM_ID_2_reg_addr                                            "0xB801400C"
#define  TP_TP_TF0_STRM_ID_2_reg                                                 0xB801400C
#define  TP_TP_TF0_STRM_ID_2_inst_addr                                           "0x0003"
#define  set_TP_TP_TF0_STRM_ID_2_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_2_reg)=data)
#define  get_TP_TP_TF0_STRM_ID_2_reg                                             (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_2_reg))
#define  TP_TP_TF0_STRM_ID_2_set3_shift                                          (24)
#define  TP_TP_TF0_STRM_ID_2_set2_shift                                          (16)
#define  TP_TP_TF0_STRM_ID_2_set1_shift                                          (8)
#define  TP_TP_TF0_STRM_ID_2_set0_shift                                          (0)
#define  TP_TP_TF0_STRM_ID_2_set3_mask                                           (0xFF000000)
#define  TP_TP_TF0_STRM_ID_2_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF0_STRM_ID_2_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF0_STRM_ID_2_set0_mask                                           (0x000000FF)
#define  TP_TP_TF0_STRM_ID_2_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF0_STRM_ID_2_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF0_STRM_ID_2_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF0_STRM_ID_2_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF0_STRM_ID_2_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF0_STRM_ID_2_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF0_STRM_ID_2_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF0_STRM_ID_2_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF0_STRM_ID_3                                                     0x18014010
#define  TP_TP_TF0_STRM_ID_3_reg_addr                                            "0xB8014010"
#define  TP_TP_TF0_STRM_ID_3_reg                                                 0xB8014010
#define  TP_TP_TF0_STRM_ID_3_inst_addr                                           "0x0004"
#define  set_TP_TP_TF0_STRM_ID_3_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_3_reg)=data)
#define  get_TP_TP_TF0_STRM_ID_3_reg                                             (*((volatile unsigned int*)TP_TP_TF0_STRM_ID_3_reg))
#define  TP_TP_TF0_STRM_ID_3_set3_shift                                          (24)
#define  TP_TP_TF0_STRM_ID_3_set2_shift                                          (16)
#define  TP_TP_TF0_STRM_ID_3_set1_shift                                          (8)
#define  TP_TP_TF0_STRM_ID_3_set0_shift                                          (0)
#define  TP_TP_TF0_STRM_ID_3_set3_mask                                           (0xFF000000)
#define  TP_TP_TF0_STRM_ID_3_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF0_STRM_ID_3_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF0_STRM_ID_3_set0_mask                                           (0x000000FF)
#define  TP_TP_TF0_STRM_ID_3_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF0_STRM_ID_3_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF0_STRM_ID_3_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF0_STRM_ID_3_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF0_STRM_ID_3_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF0_STRM_ID_3_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF0_STRM_ID_3_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF0_STRM_ID_3_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF0_STRM_VAL                                                      0x18014014
#define  TP_TP_TF0_STRM_VAL_reg_addr                                             "0xB8014014"
#define  TP_TP_TF0_STRM_VAL_reg                                                  0xB8014014
#define  TP_TP_TF0_STRM_VAL_inst_addr                                            "0x0005"
#define  set_TP_TP_TF0_STRM_VAL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF0_STRM_VAL_reg)=data)
#define  get_TP_TP_TF0_STRM_VAL_reg                                              (*((volatile unsigned int*)TP_TP_TF0_STRM_VAL_reg))
#define  TP_TP_TF0_STRM_VAL_val_set33_shift                                      (15)
#define  TP_TP_TF0_STRM_VAL_val_set32_shift                                      (14)
#define  TP_TP_TF0_STRM_VAL_val_set31_shift                                      (13)
#define  TP_TP_TF0_STRM_VAL_val_set30_shift                                      (12)
#define  TP_TP_TF0_STRM_VAL_val_set23_shift                                      (11)
#define  TP_TP_TF0_STRM_VAL_val_set22_shift                                      (10)
#define  TP_TP_TF0_STRM_VAL_val_set21_shift                                      (9)
#define  TP_TP_TF0_STRM_VAL_val_set20_shift                                      (8)
#define  TP_TP_TF0_STRM_VAL_val_set13_shift                                      (7)
#define  TP_TP_TF0_STRM_VAL_val_set12_shift                                      (6)
#define  TP_TP_TF0_STRM_VAL_val_set11_shift                                      (5)
#define  TP_TP_TF0_STRM_VAL_val_set10_shift                                      (4)
#define  TP_TP_TF0_STRM_VAL_val_set03_shift                                      (3)
#define  TP_TP_TF0_STRM_VAL_val_set02_shift                                      (2)
#define  TP_TP_TF0_STRM_VAL_val_set01_shift                                      (1)
#define  TP_TP_TF0_STRM_VAL_val_set00_shift                                      (0)
#define  TP_TP_TF0_STRM_VAL_val_set33_mask                                       (0x00008000)
#define  TP_TP_TF0_STRM_VAL_val_set32_mask                                       (0x00004000)
#define  TP_TP_TF0_STRM_VAL_val_set31_mask                                       (0x00002000)
#define  TP_TP_TF0_STRM_VAL_val_set30_mask                                       (0x00001000)
#define  TP_TP_TF0_STRM_VAL_val_set23_mask                                       (0x00000800)
#define  TP_TP_TF0_STRM_VAL_val_set22_mask                                       (0x00000400)
#define  TP_TP_TF0_STRM_VAL_val_set21_mask                                       (0x00000200)
#define  TP_TP_TF0_STRM_VAL_val_set20_mask                                       (0x00000100)
#define  TP_TP_TF0_STRM_VAL_val_set13_mask                                       (0x00000080)
#define  TP_TP_TF0_STRM_VAL_val_set12_mask                                       (0x00000040)
#define  TP_TP_TF0_STRM_VAL_val_set11_mask                                       (0x00000020)
#define  TP_TP_TF0_STRM_VAL_val_set10_mask                                       (0x00000010)
#define  TP_TP_TF0_STRM_VAL_val_set03_mask                                       (0x00000008)
#define  TP_TP_TF0_STRM_VAL_val_set02_mask                                       (0x00000004)
#define  TP_TP_TF0_STRM_VAL_val_set01_mask                                       (0x00000002)
#define  TP_TP_TF0_STRM_VAL_val_set00_mask                                       (0x00000001)
#define  TP_TP_TF0_STRM_VAL_val_set33(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF0_STRM_VAL_val_set32(data)                                      (0x00004000&((data)<<14))
#define  TP_TP_TF0_STRM_VAL_val_set31(data)                                      (0x00002000&((data)<<13))
#define  TP_TP_TF0_STRM_VAL_val_set30(data)                                      (0x00001000&((data)<<12))
#define  TP_TP_TF0_STRM_VAL_val_set23(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF0_STRM_VAL_val_set22(data)                                      (0x00000400&((data)<<10))
#define  TP_TP_TF0_STRM_VAL_val_set21(data)                                      (0x00000200&((data)<<9))
#define  TP_TP_TF0_STRM_VAL_val_set20(data)                                      (0x00000100&((data)<<8))
#define  TP_TP_TF0_STRM_VAL_val_set13(data)                                      (0x00000080&((data)<<7))
#define  TP_TP_TF0_STRM_VAL_val_set12(data)                                      (0x00000040&((data)<<6))
#define  TP_TP_TF0_STRM_VAL_val_set11(data)                                      (0x00000020&((data)<<5))
#define  TP_TP_TF0_STRM_VAL_val_set10(data)                                      (0x00000010&((data)<<4))
#define  TP_TP_TF0_STRM_VAL_val_set03(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF0_STRM_VAL_val_set02(data)                                      (0x00000004&((data)<<2))
#define  TP_TP_TF0_STRM_VAL_val_set01(data)                                      (0x00000002&((data)<<1))
#define  TP_TP_TF0_STRM_VAL_val_set00(data)                                      (0x00000001&(data))
#define  TP_TP_TF0_STRM_VAL_get_val_set33(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF0_STRM_VAL_get_val_set32(data)                                  ((0x00004000&(data))>>14)
#define  TP_TP_TF0_STRM_VAL_get_val_set31(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP_TF0_STRM_VAL_get_val_set30(data)                                  ((0x00001000&(data))>>12)
#define  TP_TP_TF0_STRM_VAL_get_val_set23(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF0_STRM_VAL_get_val_set22(data)                                  ((0x00000400&(data))>>10)
#define  TP_TP_TF0_STRM_VAL_get_val_set21(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP_TF0_STRM_VAL_get_val_set20(data)                                  ((0x00000100&(data))>>8)
#define  TP_TP_TF0_STRM_VAL_get_val_set13(data)                                  ((0x00000080&(data))>>7)
#define  TP_TP_TF0_STRM_VAL_get_val_set12(data)                                  ((0x00000040&(data))>>6)
#define  TP_TP_TF0_STRM_VAL_get_val_set11(data)                                  ((0x00000020&(data))>>5)
#define  TP_TP_TF0_STRM_VAL_get_val_set10(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP_TF0_STRM_VAL_get_val_set03(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF0_STRM_VAL_get_val_set02(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP_TF0_STRM_VAL_get_val_set01(data)                                  ((0x00000002&(data))>>1)
#define  TP_TP_TF0_STRM_VAL_get_val_set00(data)                                  (0x00000001&(data))

#define  TP_TP_TF0_CNT                                                           0x18014018
#define  TP_TP_TF0_CNT_reg_addr                                                  "0xB8014018"
#define  TP_TP_TF0_CNT_reg                                                       0xB8014018
#define  TP_TP_TF0_CNT_inst_addr                                                 "0x0006"
#define  set_TP_TP_TF0_CNT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF0_CNT_reg)=data)
#define  get_TP_TP_TF0_CNT_reg                                                   (*((volatile unsigned int*)TP_TP_TF0_CNT_reg))
#define  TP_TP_TF0_CNT_cnt_shift                                                 (0)
#define  TP_TP_TF0_CNT_cnt_mask                                                  (0x00FFFFFF)
#define  TP_TP_TF0_CNT_cnt(data)                                                 (0x00FFFFFF&(data))
#define  TP_TP_TF0_CNT_get_cnt(data)                                             (0x00FFFFFF&(data))

#define  TP_TP_TF0_DRP_CNT                                                       0x1801401C
#define  TP_TP_TF0_DRP_CNT_reg_addr                                              "0xB801401C"
#define  TP_TP_TF0_DRP_CNT_reg                                                   0xB801401C
#define  TP_TP_TF0_DRP_CNT_inst_addr                                             "0x0007"
#define  set_TP_TP_TF0_DRP_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF0_DRP_CNT_reg)=data)
#define  get_TP_TP_TF0_DRP_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF0_DRP_CNT_reg))
#define  TP_TP_TF0_DRP_CNT_drp_cnt_shift                                         (0)
#define  TP_TP_TF0_DRP_CNT_drp_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF0_DRP_CNT_drp_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF0_DRP_CNT_get_drp_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF0_ERR_CNT                                                       0x18014020
#define  TP_TP_TF0_ERR_CNT_reg_addr                                              "0xB8014020"
#define  TP_TP_TF0_ERR_CNT_reg                                                   0xB8014020
#define  TP_TP_TF0_ERR_CNT_inst_addr                                             "0x0008"
#define  set_TP_TP_TF0_ERR_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF0_ERR_CNT_reg)=data)
#define  get_TP_TP_TF0_ERR_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF0_ERR_CNT_reg))
#define  TP_TP_TF0_ERR_CNT_err_cnt_shift                                         (0)
#define  TP_TP_TF0_ERR_CNT_err_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF0_ERR_CNT_err_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF0_ERR_CNT_get_err_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF0_FRMCFG                                                        0x18014024
#define  TP_TP_TF0_FRMCFG_reg_addr                                               "0xB8014024"
#define  TP_TP_TF0_FRMCFG_reg                                                    0xB8014024
#define  TP_TP_TF0_FRMCFG_inst_addr                                              "0x0009"
#define  set_TP_TP_TF0_FRMCFG_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF0_FRMCFG_reg)=data)
#define  get_TP_TP_TF0_FRMCFG_reg                                                (*((volatile unsigned int*)TP_TP_TF0_FRMCFG_reg))
#define  TP_TP_TF0_FRMCFG_sync_byte_shift                                        (24)
#define  TP_TP_TF0_FRMCFG_dropno_shift                                           (20)
#define  TP_TP_TF0_FRMCFG_lockno_shift                                           (16)
#define  TP_TP_TF0_FRMCFG_packet_size_shift                                      (14)
#define  TP_TP_TF0_FRMCFG_data_order_shift                                       (13)
#define  TP_TP_TF0_FRMCFG_frm_en_shift                                           (12)
#define  TP_TP_TF0_FRMCFG_forcedrop_shift                                        (11)
#define  TP_TP_TF0_FRMCFG_syncmode_shift                                         (6)
#define  TP_TP_TF0_FRMCFG_serial_shift                                           (5)
#define  TP_TP_TF0_FRMCFG_datapin_shift                                          (4)
#define  TP_TP_TF0_FRMCFG_sync_byte_mask                                         (0xFF000000)
#define  TP_TP_TF0_FRMCFG_dropno_mask                                            (0x00F00000)
#define  TP_TP_TF0_FRMCFG_lockno_mask                                            (0x000F0000)
#define  TP_TP_TF0_FRMCFG_packet_size_mask                                       (0x0000C000)
#define  TP_TP_TF0_FRMCFG_data_order_mask                                        (0x00002000)
#define  TP_TP_TF0_FRMCFG_frm_en_mask                                            (0x00001000)
#define  TP_TP_TF0_FRMCFG_forcedrop_mask                                         (0x00000800)
#define  TP_TP_TF0_FRMCFG_syncmode_mask                                          (0x000007C0)
#define  TP_TP_TF0_FRMCFG_serial_mask                                            (0x00000020)
#define  TP_TP_TF0_FRMCFG_datapin_mask                                           (0x00000010)
#define  TP_TP_TF0_FRMCFG_sync_byte(data)                                        (0xFF000000&((data)<<24))
#define  TP_TP_TF0_FRMCFG_dropno(data)                                           (0x00F00000&((data)<<20))
#define  TP_TP_TF0_FRMCFG_lockno(data)                                           (0x000F0000&((data)<<16))
#define  TP_TP_TF0_FRMCFG_packet_size(data)                                      (0x0000C000&((data)<<14))
#define  TP_TP_TF0_FRMCFG_data_order(data)                                       (0x00002000&((data)<<13))
#define  TP_TP_TF0_FRMCFG_frm_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF0_FRMCFG_forcedrop(data)                                        (0x00000800&((data)<<11))
#define  TP_TP_TF0_FRMCFG_syncmode(data)                                         (0x000007C0&((data)<<6))
#define  TP_TP_TF0_FRMCFG_serial(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF0_FRMCFG_datapin(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF0_FRMCFG_get_sync_byte(data)                                    ((0xFF000000&(data))>>24)
#define  TP_TP_TF0_FRMCFG_get_dropno(data)                                       ((0x00F00000&(data))>>20)
#define  TP_TP_TF0_FRMCFG_get_lockno(data)                                       ((0x000F0000&(data))>>16)
#define  TP_TP_TF0_FRMCFG_get_packet_size(data)                                  ((0x0000C000&(data))>>14)
#define  TP_TP_TF0_FRMCFG_get_data_order(data)                                   ((0x00002000&(data))>>13)
#define  TP_TP_TF0_FRMCFG_get_frm_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF0_FRMCFG_get_forcedrop(data)                                    ((0x00000800&(data))>>11)
#define  TP_TP_TF0_FRMCFG_get_syncmode(data)                                     ((0x000007C0&(data))>>6)
#define  TP_TP_TF0_FRMCFG_get_serial(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF0_FRMCFG_get_datapin(data)                                      ((0x00000010&(data))>>4)

#define  TP_TP_TF0_INT                                                           0x18014028
#define  TP_TP_TF0_INT_reg_addr                                                  "0xB8014028"
#define  TP_TP_TF0_INT_reg                                                       0xB8014028
#define  TP_TP_TF0_INT_inst_addr                                                 "0x000A"
#define  set_TP_TP_TF0_INT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF0_INT_reg)=data)
#define  get_TP_TP_TF0_INT_reg                                                   (*((volatile unsigned int*)TP_TP_TF0_INT_reg))
#define  TP_TP_TF0_INT_adf_pcr_in_shift                                          (4)
#define  TP_TP_TF0_INT_overflow_shift                                            (3)
#define  TP_TP_TF0_INT_drop_shift                                                (2)
#define  TP_TP_TF0_INT_sync_shift                                                (1)
#define  TP_TP_TF0_INT_write_data_shift                                          (0)
#define  TP_TP_TF0_INT_adf_pcr_in_mask                                           (0x00000010)
#define  TP_TP_TF0_INT_overflow_mask                                             (0x00000008)
#define  TP_TP_TF0_INT_drop_mask                                                 (0x00000004)
#define  TP_TP_TF0_INT_sync_mask                                                 (0x00000002)
#define  TP_TP_TF0_INT_write_data_mask                                           (0x00000001)
#define  TP_TP_TF0_INT_adf_pcr_in(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF0_INT_overflow(data)                                            (0x00000008&((data)<<3))
#define  TP_TP_TF0_INT_drop(data)                                                (0x00000004&((data)<<2))
#define  TP_TP_TF0_INT_sync(data)                                                (0x00000002&((data)<<1))
#define  TP_TP_TF0_INT_write_data(data)                                          (0x00000001&(data))
#define  TP_TP_TF0_INT_get_adf_pcr_in(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF0_INT_get_overflow(data)                                        ((0x00000008&(data))>>3)
#define  TP_TP_TF0_INT_get_drop(data)                                            ((0x00000004&(data))>>2)
#define  TP_TP_TF0_INT_get_sync(data)                                            ((0x00000002&(data))>>1)
#define  TP_TP_TF0_INT_get_write_data(data)                                      (0x00000001&(data))

#define  TP_TP_TF0_INT_EN                                                        0x1801402C
#define  TP_TP_TF0_INT_EN_reg_addr                                               "0xB801402C"
#define  TP_TP_TF0_INT_EN_reg                                                    0xB801402C
#define  TP_TP_TF0_INT_EN_inst_addr                                              "0x000B"
#define  set_TP_TP_TF0_INT_EN_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF0_INT_EN_reg)=data)
#define  get_TP_TP_TF0_INT_EN_reg                                                (*((volatile unsigned int*)TP_TP_TF0_INT_EN_reg))
#define  TP_TP_TF0_INT_EN_adf_pcr_in_en_shift                                    (4)
#define  TP_TP_TF0_INT_EN_overflow_en_shift                                      (3)
#define  TP_TP_TF0_INT_EN_drop_en_shift                                          (2)
#define  TP_TP_TF0_INT_EN_sync_en_shift                                          (1)
#define  TP_TP_TF0_INT_EN_write_data_shift                                       (0)
#define  TP_TP_TF0_INT_EN_adf_pcr_in_en_mask                                     (0x00000010)
#define  TP_TP_TF0_INT_EN_overflow_en_mask                                       (0x00000008)
#define  TP_TP_TF0_INT_EN_drop_en_mask                                           (0x00000004)
#define  TP_TP_TF0_INT_EN_sync_en_mask                                           (0x00000002)
#define  TP_TP_TF0_INT_EN_write_data_mask                                        (0x00000001)
#define  TP_TP_TF0_INT_EN_adf_pcr_in_en(data)                                    (0x00000010&((data)<<4))
#define  TP_TP_TF0_INT_EN_overflow_en(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF0_INT_EN_drop_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF0_INT_EN_sync_en(data)                                          (0x00000002&((data)<<1))
#define  TP_TP_TF0_INT_EN_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF0_INT_EN_get_adf_pcr_in_en(data)                                ((0x00000010&(data))>>4)
#define  TP_TP_TF0_INT_EN_get_overflow_en(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF0_INT_EN_get_drop_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF0_INT_EN_get_sync_en(data)                                      ((0x00000002&(data))>>1)
#define  TP_TP_TF0_INT_EN_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF1_CNTL                                                          0x18014030
#define  TP_TP_TF1_CNTL_reg_addr                                                 "0xB8014030"
#define  TP_TP_TF1_CNTL_reg                                                      0xB8014030
#define  TP_TP_TF1_CNTL_inst_addr                                                "0x000C"
#define  set_TP_TP_TF1_CNTL_reg(data)                                            (*((volatile unsigned int*)TP_TP_TF1_CNTL_reg)=data)
#define  get_TP_TP_TF1_CNTL_reg                                                  (*((volatile unsigned int*)TP_TP_TF1_CNTL_reg))
#define  TP_TP_TF1_CNTL_two_bit_shift                                            (31)
#define  TP_TP_TF1_CNTL_two_bit_reverse_shift                                    (30)
#define  TP_TP_TF1_CNTL_two_bit_sel_h_shift                                      (29)
#define  TP_TP_TF1_CNTL_two_bit_sel_l_shift                                      (28)
#define  TP_TP_TF1_CNTL_src_sel_h_shift                                          (25)
#define  TP_TP_TF1_CNTL_src_sel_l_shift                                          (24)
#define  TP_TP_TF1_CNTL_dir_dma_shift                                            (23)
#define  TP_TP_TF1_CNTL_ci_mode_shift                                            (18)
#define  TP_TP_TF1_CNTL_tp_err_fix_en_shift                                      (17)
#define  TP_TP_TF1_CNTL_strm_id_en_shift                                         (16)
#define  TP_TP_TF1_CNTL_buf_rdy_ctl_shift                                        (15)
#define  TP_TP_TF1_CNTL_psc_en_shift                                             (14)
#define  TP_TP_TF1_CNTL_pes_en_shift                                             (13)
#define  TP_TP_TF1_CNTL_tsc_en_shift                                             (12)
#define  TP_TP_TF1_CNTL_tb_shift                                                 (11)
#define  TP_TP_TF1_CNTL_busy_shift                                               (10)
#define  TP_TP_TF1_CNTL_mode_shift                                               (9)
#define  TP_TP_TF1_CNTL_du_en_shift                                              (8)
#define  TP_TP_TF1_CNTL_de_en_shift                                              (7)
#define  TP_TP_TF1_CNTL_xt_en_shift                                              (6)
#define  TP_TP_TF1_CNTL_pid_en_shift                                             (5)
#define  TP_TP_TF1_CNTL_null_en_shift                                            (4)
#define  TP_TP_TF1_CNTL_trerr_en_shift                                           (3)
#define  TP_TP_TF1_CNTL_sync_en_shift                                            (2)
#define  TP_TP_TF1_CNTL_rst_en_shift                                             (1)
#define  TP_TP_TF1_CNTL_write_data_shift                                         (0)
#define  TP_TP_TF1_CNTL_two_bit_mask                                             (0x80000000)
#define  TP_TP_TF1_CNTL_two_bit_reverse_mask                                     (0x40000000)
#define  TP_TP_TF1_CNTL_two_bit_sel_h_mask                                       (0x20000000)
#define  TP_TP_TF1_CNTL_two_bit_sel_l_mask                                       (0x10000000)
#define  TP_TP_TF1_CNTL_src_sel_h_mask                                           (0x02000000)
#define  TP_TP_TF1_CNTL_src_sel_l_mask                                           (0x01000000)
#define  TP_TP_TF1_CNTL_dir_dma_mask                                             (0x00800000)
#define  TP_TP_TF1_CNTL_ci_mode_mask                                             (0x00040000)
#define  TP_TP_TF1_CNTL_tp_err_fix_en_mask                                       (0x00020000)
#define  TP_TP_TF1_CNTL_strm_id_en_mask                                          (0x00010000)
#define  TP_TP_TF1_CNTL_buf_rdy_ctl_mask                                         (0x00008000)
#define  TP_TP_TF1_CNTL_psc_en_mask                                              (0x00004000)
#define  TP_TP_TF1_CNTL_pes_en_mask                                              (0x00002000)
#define  TP_TP_TF1_CNTL_tsc_en_mask                                              (0x00001000)
#define  TP_TP_TF1_CNTL_tb_mask                                                  (0x00000800)
#define  TP_TP_TF1_CNTL_busy_mask                                                (0x00000400)
#define  TP_TP_TF1_CNTL_mode_mask                                                (0x00000200)
#define  TP_TP_TF1_CNTL_du_en_mask                                               (0x00000100)
#define  TP_TP_TF1_CNTL_de_en_mask                                               (0x00000080)
#define  TP_TP_TF1_CNTL_xt_en_mask                                               (0x00000040)
#define  TP_TP_TF1_CNTL_pid_en_mask                                              (0x00000020)
#define  TP_TP_TF1_CNTL_null_en_mask                                             (0x00000010)
#define  TP_TP_TF1_CNTL_trerr_en_mask                                            (0x00000008)
#define  TP_TP_TF1_CNTL_sync_en_mask                                             (0x00000004)
#define  TP_TP_TF1_CNTL_rst_en_mask                                              (0x00000002)
#define  TP_TP_TF1_CNTL_write_data_mask                                          (0x00000001)
#define  TP_TP_TF1_CNTL_two_bit(data)                                            (0x80000000&((data)<<31))
#define  TP_TP_TF1_CNTL_two_bit_reverse(data)                                    (0x40000000&((data)<<30))
#define  TP_TP_TF1_CNTL_two_bit_sel_h(data)                                      (0x20000000&((data)<<29))
#define  TP_TP_TF1_CNTL_two_bit_sel_l(data)                                      (0x10000000&((data)<<28))
#define  TP_TP_TF1_CNTL_src_sel_h(data)                                          (0x02000000&((data)<<25))
#define  TP_TP_TF1_CNTL_src_sel_l(data)                                          (0x01000000&((data)<<24))
#define  TP_TP_TF1_CNTL_dir_dma(data)                                            (0x00800000&((data)<<23))
#define  TP_TP_TF1_CNTL_ci_mode(data)                                            (0x00040000&((data)<<18))
#define  TP_TP_TF1_CNTL_tp_err_fix_en(data)                                      (0x00020000&((data)<<17))
#define  TP_TP_TF1_CNTL_strm_id_en(data)                                         (0x00010000&((data)<<16))
#define  TP_TP_TF1_CNTL_buf_rdy_ctl(data)                                        (0x00008000&((data)<<15))
#define  TP_TP_TF1_CNTL_psc_en(data)                                             (0x00004000&((data)<<14))
#define  TP_TP_TF1_CNTL_pes_en(data)                                             (0x00002000&((data)<<13))
#define  TP_TP_TF1_CNTL_tsc_en(data)                                             (0x00001000&((data)<<12))
#define  TP_TP_TF1_CNTL_tb(data)                                                 (0x00000800&((data)<<11))
#define  TP_TP_TF1_CNTL_busy(data)                                               (0x00000400&((data)<<10))
#define  TP_TP_TF1_CNTL_mode(data)                                               (0x00000200&((data)<<9))
#define  TP_TP_TF1_CNTL_du_en(data)                                              (0x00000100&((data)<<8))
#define  TP_TP_TF1_CNTL_de_en(data)                                              (0x00000080&((data)<<7))
#define  TP_TP_TF1_CNTL_xt_en(data)                                              (0x00000040&((data)<<6))
#define  TP_TP_TF1_CNTL_pid_en(data)                                             (0x00000020&((data)<<5))
#define  TP_TP_TF1_CNTL_null_en(data)                                            (0x00000010&((data)<<4))
#define  TP_TP_TF1_CNTL_trerr_en(data)                                           (0x00000008&((data)<<3))
#define  TP_TP_TF1_CNTL_sync_en(data)                                            (0x00000004&((data)<<2))
#define  TP_TP_TF1_CNTL_rst_en(data)                                             (0x00000002&((data)<<1))
#define  TP_TP_TF1_CNTL_write_data(data)                                         (0x00000001&(data))
#define  TP_TP_TF1_CNTL_get_two_bit(data)                                        ((0x80000000&(data))>>31)
#define  TP_TP_TF1_CNTL_get_two_bit_reverse(data)                                ((0x40000000&(data))>>30)
#define  TP_TP_TF1_CNTL_get_two_bit_sel_h(data)                                  ((0x20000000&(data))>>29)
#define  TP_TP_TF1_CNTL_get_two_bit_sel_l(data)                                  ((0x10000000&(data))>>28)
#define  TP_TP_TF1_CNTL_get_src_sel_h(data)                                      ((0x02000000&(data))>>25)
#define  TP_TP_TF1_CNTL_get_src_sel_l(data)                                      ((0x01000000&(data))>>24)
#define  TP_TP_TF1_CNTL_get_dir_dma(data)                                        ((0x00800000&(data))>>23)
#define  TP_TP_TF1_CNTL_get_ci_mode(data)                                        ((0x00040000&(data))>>18)
#define  TP_TP_TF1_CNTL_get_tp_err_fix_en(data)                                  ((0x00020000&(data))>>17)
#define  TP_TP_TF1_CNTL_get_strm_id_en(data)                                     ((0x00010000&(data))>>16)
#define  TP_TP_TF1_CNTL_get_buf_rdy_ctl(data)                                    ((0x00008000&(data))>>15)
#define  TP_TP_TF1_CNTL_get_psc_en(data)                                         ((0x00004000&(data))>>14)
#define  TP_TP_TF1_CNTL_get_pes_en(data)                                         ((0x00002000&(data))>>13)
#define  TP_TP_TF1_CNTL_get_tsc_en(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP_TF1_CNTL_get_tb(data)                                             ((0x00000800&(data))>>11)
#define  TP_TP_TF1_CNTL_get_busy(data)                                           ((0x00000400&(data))>>10)
#define  TP_TP_TF1_CNTL_get_mode(data)                                           ((0x00000200&(data))>>9)
#define  TP_TP_TF1_CNTL_get_du_en(data)                                          ((0x00000100&(data))>>8)
#define  TP_TP_TF1_CNTL_get_de_en(data)                                          ((0x00000080&(data))>>7)
#define  TP_TP_TF1_CNTL_get_xt_en(data)                                          ((0x00000040&(data))>>6)
#define  TP_TP_TF1_CNTL_get_pid_en(data)                                         ((0x00000020&(data))>>5)
#define  TP_TP_TF1_CNTL_get_null_en(data)                                        ((0x00000010&(data))>>4)
#define  TP_TP_TF1_CNTL_get_trerr_en(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP_TF1_CNTL_get_sync_en(data)                                        ((0x00000004&(data))>>2)
#define  TP_TP_TF1_CNTL_get_rst_en(data)                                         ((0x00000002&(data))>>1)
#define  TP_TP_TF1_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  TP_TP_TF1_STRM_ID_0                                                     0x18014034
#define  TP_TP_TF1_STRM_ID_0_reg_addr                                            "0xB8014034"
#define  TP_TP_TF1_STRM_ID_0_reg                                                 0xB8014034
#define  TP_TP_TF1_STRM_ID_0_inst_addr                                           "0x000D"
#define  set_TP_TP_TF1_STRM_ID_0_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_0_reg)=data)
#define  get_TP_TP_TF1_STRM_ID_0_reg                                             (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_0_reg))
#define  TP_TP_TF1_STRM_ID_0_set3_shift                                          (24)
#define  TP_TP_TF1_STRM_ID_0_set2_shift                                          (16)
#define  TP_TP_TF1_STRM_ID_0_set1_shift                                          (8)
#define  TP_TP_TF1_STRM_ID_0_set0_shift                                          (0)
#define  TP_TP_TF1_STRM_ID_0_set3_mask                                           (0xFF000000)
#define  TP_TP_TF1_STRM_ID_0_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF1_STRM_ID_0_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF1_STRM_ID_0_set0_mask                                           (0x000000FF)
#define  TP_TP_TF1_STRM_ID_0_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF1_STRM_ID_0_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF1_STRM_ID_0_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF1_STRM_ID_0_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF1_STRM_ID_0_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF1_STRM_ID_0_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF1_STRM_ID_0_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF1_STRM_ID_0_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF1_STRM_ID_1                                                     0x18014038
#define  TP_TP_TF1_STRM_ID_1_reg_addr                                            "0xB8014038"
#define  TP_TP_TF1_STRM_ID_1_reg                                                 0xB8014038
#define  TP_TP_TF1_STRM_ID_1_inst_addr                                           "0x000E"
#define  set_TP_TP_TF1_STRM_ID_1_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_1_reg)=data)
#define  get_TP_TP_TF1_STRM_ID_1_reg                                             (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_1_reg))
#define  TP_TP_TF1_STRM_ID_1_set3_shift                                          (24)
#define  TP_TP_TF1_STRM_ID_1_set2_shift                                          (16)
#define  TP_TP_TF1_STRM_ID_1_set1_shift                                          (8)
#define  TP_TP_TF1_STRM_ID_1_set0_shift                                          (0)
#define  TP_TP_TF1_STRM_ID_1_set3_mask                                           (0xFF000000)
#define  TP_TP_TF1_STRM_ID_1_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF1_STRM_ID_1_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF1_STRM_ID_1_set0_mask                                           (0x000000FF)
#define  TP_TP_TF1_STRM_ID_1_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF1_STRM_ID_1_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF1_STRM_ID_1_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF1_STRM_ID_1_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF1_STRM_ID_1_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF1_STRM_ID_1_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF1_STRM_ID_1_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF1_STRM_ID_1_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF1_STRM_ID_2                                                     0x1801403C
#define  TP_TP_TF1_STRM_ID_2_reg_addr                                            "0xB801403C"
#define  TP_TP_TF1_STRM_ID_2_reg                                                 0xB801403C
#define  TP_TP_TF1_STRM_ID_2_inst_addr                                           "0x000F"
#define  set_TP_TP_TF1_STRM_ID_2_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_2_reg)=data)
#define  get_TP_TP_TF1_STRM_ID_2_reg                                             (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_2_reg))
#define  TP_TP_TF1_STRM_ID_2_set3_shift                                          (24)
#define  TP_TP_TF1_STRM_ID_2_set2_shift                                          (16)
#define  TP_TP_TF1_STRM_ID_2_set1_shift                                          (8)
#define  TP_TP_TF1_STRM_ID_2_set0_shift                                          (0)
#define  TP_TP_TF1_STRM_ID_2_set3_mask                                           (0xFF000000)
#define  TP_TP_TF1_STRM_ID_2_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF1_STRM_ID_2_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF1_STRM_ID_2_set0_mask                                           (0x000000FF)
#define  TP_TP_TF1_STRM_ID_2_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF1_STRM_ID_2_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF1_STRM_ID_2_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF1_STRM_ID_2_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF1_STRM_ID_2_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF1_STRM_ID_2_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF1_STRM_ID_2_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF1_STRM_ID_2_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF1_STRM_ID_3                                                     0x18014040
#define  TP_TP_TF1_STRM_ID_3_reg_addr                                            "0xB8014040"
#define  TP_TP_TF1_STRM_ID_3_reg                                                 0xB8014040
#define  TP_TP_TF1_STRM_ID_3_inst_addr                                           "0x0010"
#define  set_TP_TP_TF1_STRM_ID_3_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_3_reg)=data)
#define  get_TP_TP_TF1_STRM_ID_3_reg                                             (*((volatile unsigned int*)TP_TP_TF1_STRM_ID_3_reg))
#define  TP_TP_TF1_STRM_ID_3_set3_shift                                          (24)
#define  TP_TP_TF1_STRM_ID_3_set2_shift                                          (16)
#define  TP_TP_TF1_STRM_ID_3_set1_shift                                          (8)
#define  TP_TP_TF1_STRM_ID_3_set0_shift                                          (0)
#define  TP_TP_TF1_STRM_ID_3_set3_mask                                           (0xFF000000)
#define  TP_TP_TF1_STRM_ID_3_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF1_STRM_ID_3_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF1_STRM_ID_3_set0_mask                                           (0x000000FF)
#define  TP_TP_TF1_STRM_ID_3_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF1_STRM_ID_3_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF1_STRM_ID_3_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF1_STRM_ID_3_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF1_STRM_ID_3_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF1_STRM_ID_3_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF1_STRM_ID_3_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF1_STRM_ID_3_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF1_STRM_VAL                                                      0x18014044
#define  TP_TP_TF1_STRM_VAL_reg_addr                                             "0xB8014044"
#define  TP_TP_TF1_STRM_VAL_reg                                                  0xB8014044
#define  TP_TP_TF1_STRM_VAL_inst_addr                                            "0x0011"
#define  set_TP_TP_TF1_STRM_VAL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF1_STRM_VAL_reg)=data)
#define  get_TP_TP_TF1_STRM_VAL_reg                                              (*((volatile unsigned int*)TP_TP_TF1_STRM_VAL_reg))
#define  TP_TP_TF1_STRM_VAL_val_set33_shift                                      (15)
#define  TP_TP_TF1_STRM_VAL_val_set32_shift                                      (14)
#define  TP_TP_TF1_STRM_VAL_val_set31_shift                                      (13)
#define  TP_TP_TF1_STRM_VAL_val_set30_shift                                      (12)
#define  TP_TP_TF1_STRM_VAL_val_set23_shift                                      (11)
#define  TP_TP_TF1_STRM_VAL_val_set22_shift                                      (10)
#define  TP_TP_TF1_STRM_VAL_val_set21_shift                                      (9)
#define  TP_TP_TF1_STRM_VAL_val_set20_shift                                      (8)
#define  TP_TP_TF1_STRM_VAL_val_set13_shift                                      (7)
#define  TP_TP_TF1_STRM_VAL_val_set12_shift                                      (6)
#define  TP_TP_TF1_STRM_VAL_val_set11_shift                                      (5)
#define  TP_TP_TF1_STRM_VAL_val_set10_shift                                      (4)
#define  TP_TP_TF1_STRM_VAL_val_set03_shift                                      (3)
#define  TP_TP_TF1_STRM_VAL_val_set02_shift                                      (2)
#define  TP_TP_TF1_STRM_VAL_val_set01_shift                                      (1)
#define  TP_TP_TF1_STRM_VAL_val_set00_shift                                      (0)
#define  TP_TP_TF1_STRM_VAL_val_set33_mask                                       (0x00008000)
#define  TP_TP_TF1_STRM_VAL_val_set32_mask                                       (0x00004000)
#define  TP_TP_TF1_STRM_VAL_val_set31_mask                                       (0x00002000)
#define  TP_TP_TF1_STRM_VAL_val_set30_mask                                       (0x00001000)
#define  TP_TP_TF1_STRM_VAL_val_set23_mask                                       (0x00000800)
#define  TP_TP_TF1_STRM_VAL_val_set22_mask                                       (0x00000400)
#define  TP_TP_TF1_STRM_VAL_val_set21_mask                                       (0x00000200)
#define  TP_TP_TF1_STRM_VAL_val_set20_mask                                       (0x00000100)
#define  TP_TP_TF1_STRM_VAL_val_set13_mask                                       (0x00000080)
#define  TP_TP_TF1_STRM_VAL_val_set12_mask                                       (0x00000040)
#define  TP_TP_TF1_STRM_VAL_val_set11_mask                                       (0x00000020)
#define  TP_TP_TF1_STRM_VAL_val_set10_mask                                       (0x00000010)
#define  TP_TP_TF1_STRM_VAL_val_set03_mask                                       (0x00000008)
#define  TP_TP_TF1_STRM_VAL_val_set02_mask                                       (0x00000004)
#define  TP_TP_TF1_STRM_VAL_val_set01_mask                                       (0x00000002)
#define  TP_TP_TF1_STRM_VAL_val_set00_mask                                       (0x00000001)
#define  TP_TP_TF1_STRM_VAL_val_set33(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF1_STRM_VAL_val_set32(data)                                      (0x00004000&((data)<<14))
#define  TP_TP_TF1_STRM_VAL_val_set31(data)                                      (0x00002000&((data)<<13))
#define  TP_TP_TF1_STRM_VAL_val_set30(data)                                      (0x00001000&((data)<<12))
#define  TP_TP_TF1_STRM_VAL_val_set23(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF1_STRM_VAL_val_set22(data)                                      (0x00000400&((data)<<10))
#define  TP_TP_TF1_STRM_VAL_val_set21(data)                                      (0x00000200&((data)<<9))
#define  TP_TP_TF1_STRM_VAL_val_set20(data)                                      (0x00000100&((data)<<8))
#define  TP_TP_TF1_STRM_VAL_val_set13(data)                                      (0x00000080&((data)<<7))
#define  TP_TP_TF1_STRM_VAL_val_set12(data)                                      (0x00000040&((data)<<6))
#define  TP_TP_TF1_STRM_VAL_val_set11(data)                                      (0x00000020&((data)<<5))
#define  TP_TP_TF1_STRM_VAL_val_set10(data)                                      (0x00000010&((data)<<4))
#define  TP_TP_TF1_STRM_VAL_val_set03(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF1_STRM_VAL_val_set02(data)                                      (0x00000004&((data)<<2))
#define  TP_TP_TF1_STRM_VAL_val_set01(data)                                      (0x00000002&((data)<<1))
#define  TP_TP_TF1_STRM_VAL_val_set00(data)                                      (0x00000001&(data))
#define  TP_TP_TF1_STRM_VAL_get_val_set33(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF1_STRM_VAL_get_val_set32(data)                                  ((0x00004000&(data))>>14)
#define  TP_TP_TF1_STRM_VAL_get_val_set31(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP_TF1_STRM_VAL_get_val_set30(data)                                  ((0x00001000&(data))>>12)
#define  TP_TP_TF1_STRM_VAL_get_val_set23(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF1_STRM_VAL_get_val_set22(data)                                  ((0x00000400&(data))>>10)
#define  TP_TP_TF1_STRM_VAL_get_val_set21(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP_TF1_STRM_VAL_get_val_set20(data)                                  ((0x00000100&(data))>>8)
#define  TP_TP_TF1_STRM_VAL_get_val_set13(data)                                  ((0x00000080&(data))>>7)
#define  TP_TP_TF1_STRM_VAL_get_val_set12(data)                                  ((0x00000040&(data))>>6)
#define  TP_TP_TF1_STRM_VAL_get_val_set11(data)                                  ((0x00000020&(data))>>5)
#define  TP_TP_TF1_STRM_VAL_get_val_set10(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP_TF1_STRM_VAL_get_val_set03(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF1_STRM_VAL_get_val_set02(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP_TF1_STRM_VAL_get_val_set01(data)                                  ((0x00000002&(data))>>1)
#define  TP_TP_TF1_STRM_VAL_get_val_set00(data)                                  (0x00000001&(data))

#define  TP_TP_TF1_CNT                                                           0x18014048
#define  TP_TP_TF1_CNT_reg_addr                                                  "0xB8014048"
#define  TP_TP_TF1_CNT_reg                                                       0xB8014048
#define  TP_TP_TF1_CNT_inst_addr                                                 "0x0012"
#define  set_TP_TP_TF1_CNT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF1_CNT_reg)=data)
#define  get_TP_TP_TF1_CNT_reg                                                   (*((volatile unsigned int*)TP_TP_TF1_CNT_reg))
#define  TP_TP_TF1_CNT_cnt_shift                                                 (0)
#define  TP_TP_TF1_CNT_cnt_mask                                                  (0x00FFFFFF)
#define  TP_TP_TF1_CNT_cnt(data)                                                 (0x00FFFFFF&(data))
#define  TP_TP_TF1_CNT_get_cnt(data)                                             (0x00FFFFFF&(data))

#define  TP_TP_TF1_DRP_CNT                                                       0x1801404C
#define  TP_TP_TF1_DRP_CNT_reg_addr                                              "0xB801404C"
#define  TP_TP_TF1_DRP_CNT_reg                                                   0xB801404C
#define  TP_TP_TF1_DRP_CNT_inst_addr                                             "0x0013"
#define  set_TP_TP_TF1_DRP_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF1_DRP_CNT_reg)=data)
#define  get_TP_TP_TF1_DRP_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF1_DRP_CNT_reg))
#define  TP_TP_TF1_DRP_CNT_drp_cnt_shift                                         (0)
#define  TP_TP_TF1_DRP_CNT_drp_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF1_DRP_CNT_drp_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF1_DRP_CNT_get_drp_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF1_ERR_CNT                                                       0x18014050
#define  TP_TP_TF1_ERR_CNT_reg_addr                                              "0xB8014050"
#define  TP_TP_TF1_ERR_CNT_reg                                                   0xB8014050
#define  TP_TP_TF1_ERR_CNT_inst_addr                                             "0x0014"
#define  set_TP_TP_TF1_ERR_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF1_ERR_CNT_reg)=data)
#define  get_TP_TP_TF1_ERR_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF1_ERR_CNT_reg))
#define  TP_TP_TF1_ERR_CNT_err_cnt_shift                                         (0)
#define  TP_TP_TF1_ERR_CNT_err_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF1_ERR_CNT_err_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF1_ERR_CNT_get_err_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF1_FRMCFG                                                        0x18014054
#define  TP_TP_TF1_FRMCFG_reg_addr                                               "0xB8014054"
#define  TP_TP_TF1_FRMCFG_reg                                                    0xB8014054
#define  TP_TP_TF1_FRMCFG_inst_addr                                              "0x0015"
#define  set_TP_TP_TF1_FRMCFG_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF1_FRMCFG_reg)=data)
#define  get_TP_TP_TF1_FRMCFG_reg                                                (*((volatile unsigned int*)TP_TP_TF1_FRMCFG_reg))
#define  TP_TP_TF1_FRMCFG_sync_byte_shift                                        (24)
#define  TP_TP_TF1_FRMCFG_dropno_shift                                           (20)
#define  TP_TP_TF1_FRMCFG_lockno_shift                                           (16)
#define  TP_TP_TF1_FRMCFG_packet_size_shift                                      (14)
#define  TP_TP_TF1_FRMCFG_data_order_shift                                       (13)
#define  TP_TP_TF1_FRMCFG_frm_en_shift                                           (12)
#define  TP_TP_TF1_FRMCFG_forcedrop_shift                                        (11)
#define  TP_TP_TF1_FRMCFG_syncmode_shift                                         (6)
#define  TP_TP_TF1_FRMCFG_serial_shift                                           (5)
#define  TP_TP_TF1_FRMCFG_datapin_shift                                          (4)
#define  TP_TP_TF1_FRMCFG_sync_byte_mask                                         (0xFF000000)
#define  TP_TP_TF1_FRMCFG_dropno_mask                                            (0x00F00000)
#define  TP_TP_TF1_FRMCFG_lockno_mask                                            (0x000F0000)
#define  TP_TP_TF1_FRMCFG_packet_size_mask                                       (0x0000C000)
#define  TP_TP_TF1_FRMCFG_data_order_mask                                        (0x00002000)
#define  TP_TP_TF1_FRMCFG_frm_en_mask                                            (0x00001000)
#define  TP_TP_TF1_FRMCFG_forcedrop_mask                                         (0x00000800)
#define  TP_TP_TF1_FRMCFG_syncmode_mask                                          (0x000007C0)
#define  TP_TP_TF1_FRMCFG_serial_mask                                            (0x00000020)
#define  TP_TP_TF1_FRMCFG_datapin_mask                                           (0x00000010)
#define  TP_TP_TF1_FRMCFG_sync_byte(data)                                        (0xFF000000&((data)<<24))
#define  TP_TP_TF1_FRMCFG_dropno(data)                                           (0x00F00000&((data)<<20))
#define  TP_TP_TF1_FRMCFG_lockno(data)                                           (0x000F0000&((data)<<16))
#define  TP_TP_TF1_FRMCFG_packet_size(data)                                      (0x0000C000&((data)<<14))
#define  TP_TP_TF1_FRMCFG_data_order(data)                                       (0x00002000&((data)<<13))
#define  TP_TP_TF1_FRMCFG_frm_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF1_FRMCFG_forcedrop(data)                                        (0x00000800&((data)<<11))
#define  TP_TP_TF1_FRMCFG_syncmode(data)                                         (0x000007C0&((data)<<6))
#define  TP_TP_TF1_FRMCFG_serial(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF1_FRMCFG_datapin(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF1_FRMCFG_get_sync_byte(data)                                    ((0xFF000000&(data))>>24)
#define  TP_TP_TF1_FRMCFG_get_dropno(data)                                       ((0x00F00000&(data))>>20)
#define  TP_TP_TF1_FRMCFG_get_lockno(data)                                       ((0x000F0000&(data))>>16)
#define  TP_TP_TF1_FRMCFG_get_packet_size(data)                                  ((0x0000C000&(data))>>14)
#define  TP_TP_TF1_FRMCFG_get_data_order(data)                                   ((0x00002000&(data))>>13)
#define  TP_TP_TF1_FRMCFG_get_frm_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF1_FRMCFG_get_forcedrop(data)                                    ((0x00000800&(data))>>11)
#define  TP_TP_TF1_FRMCFG_get_syncmode(data)                                     ((0x000007C0&(data))>>6)
#define  TP_TP_TF1_FRMCFG_get_serial(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF1_FRMCFG_get_datapin(data)                                      ((0x00000010&(data))>>4)

#define  TP_TP_TF1_INT                                                           0x18014058
#define  TP_TP_TF1_INT_reg_addr                                                  "0xB8014058"
#define  TP_TP_TF1_INT_reg                                                       0xB8014058
#define  TP_TP_TF1_INT_inst_addr                                                 "0x0016"
#define  set_TP_TP_TF1_INT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF1_INT_reg)=data)
#define  get_TP_TP_TF1_INT_reg                                                   (*((volatile unsigned int*)TP_TP_TF1_INT_reg))
#define  TP_TP_TF1_INT_adf_pcr_in_shift                                          (4)
#define  TP_TP_TF1_INT_overflow_shift                                            (3)
#define  TP_TP_TF1_INT_drop_shift                                                (2)
#define  TP_TP_TF1_INT_sync_shift                                                (1)
#define  TP_TP_TF1_INT_write_data_shift                                          (0)
#define  TP_TP_TF1_INT_adf_pcr_in_mask                                           (0x00000010)
#define  TP_TP_TF1_INT_overflow_mask                                             (0x00000008)
#define  TP_TP_TF1_INT_drop_mask                                                 (0x00000004)
#define  TP_TP_TF1_INT_sync_mask                                                 (0x00000002)
#define  TP_TP_TF1_INT_write_data_mask                                           (0x00000001)
#define  TP_TP_TF1_INT_adf_pcr_in(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF1_INT_overflow(data)                                            (0x00000008&((data)<<3))
#define  TP_TP_TF1_INT_drop(data)                                                (0x00000004&((data)<<2))
#define  TP_TP_TF1_INT_sync(data)                                                (0x00000002&((data)<<1))
#define  TP_TP_TF1_INT_write_data(data)                                          (0x00000001&(data))
#define  TP_TP_TF1_INT_get_adf_pcr_in(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF1_INT_get_overflow(data)                                        ((0x00000008&(data))>>3)
#define  TP_TP_TF1_INT_get_drop(data)                                            ((0x00000004&(data))>>2)
#define  TP_TP_TF1_INT_get_sync(data)                                            ((0x00000002&(data))>>1)
#define  TP_TP_TF1_INT_get_write_data(data)                                      (0x00000001&(data))

#define  TP_TP_TF1_INT_EN                                                        0x1801405C
#define  TP_TP_TF1_INT_EN_reg_addr                                               "0xB801405C"
#define  TP_TP_TF1_INT_EN_reg                                                    0xB801405C
#define  TP_TP_TF1_INT_EN_inst_addr                                              "0x0017"
#define  set_TP_TP_TF1_INT_EN_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF1_INT_EN_reg)=data)
#define  get_TP_TP_TF1_INT_EN_reg                                                (*((volatile unsigned int*)TP_TP_TF1_INT_EN_reg))
#define  TP_TP_TF1_INT_EN_adf_pcr_in_en_shift                                    (4)
#define  TP_TP_TF1_INT_EN_overflow_en_shift                                      (3)
#define  TP_TP_TF1_INT_EN_drop_en_shift                                          (2)
#define  TP_TP_TF1_INT_EN_sync_en_shift                                          (1)
#define  TP_TP_TF1_INT_EN_write_data_shift                                       (0)
#define  TP_TP_TF1_INT_EN_adf_pcr_in_en_mask                                     (0x00000010)
#define  TP_TP_TF1_INT_EN_overflow_en_mask                                       (0x00000008)
#define  TP_TP_TF1_INT_EN_drop_en_mask                                           (0x00000004)
#define  TP_TP_TF1_INT_EN_sync_en_mask                                           (0x00000002)
#define  TP_TP_TF1_INT_EN_write_data_mask                                        (0x00000001)
#define  TP_TP_TF1_INT_EN_adf_pcr_in_en(data)                                    (0x00000010&((data)<<4))
#define  TP_TP_TF1_INT_EN_overflow_en(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF1_INT_EN_drop_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF1_INT_EN_sync_en(data)                                          (0x00000002&((data)<<1))
#define  TP_TP_TF1_INT_EN_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF1_INT_EN_get_adf_pcr_in_en(data)                                ((0x00000010&(data))>>4)
#define  TP_TP_TF1_INT_EN_get_overflow_en(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF1_INT_EN_get_drop_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF1_INT_EN_get_sync_en(data)                                      ((0x00000002&(data))>>1)
#define  TP_TP_TF1_INT_EN_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF2_CNTL                                                          0x18014060
#define  TP_TP_TF2_CNTL_reg_addr                                                 "0xB8014060"
#define  TP_TP_TF2_CNTL_reg                                                      0xB8014060
#define  TP_TP_TF2_CNTL_inst_addr                                                "0x0018"
#define  set_TP_TP_TF2_CNTL_reg(data)                                            (*((volatile unsigned int*)TP_TP_TF2_CNTL_reg)=data)
#define  get_TP_TP_TF2_CNTL_reg                                                  (*((volatile unsigned int*)TP_TP_TF2_CNTL_reg))
#define  TP_TP_TF2_CNTL_two_bit_shift                                            (31)
#define  TP_TP_TF2_CNTL_two_bit_reverse_shift                                    (30)
#define  TP_TP_TF2_CNTL_two_bit_sel_h_shift                                      (29)
#define  TP_TP_TF2_CNTL_two_bit_sel_l_shift                                      (28)
#define  TP_TP_TF2_CNTL_src_sel_h_shift                                          (25)
#define  TP_TP_TF2_CNTL_src_sel_l_shift                                          (24)
#define  TP_TP_TF2_CNTL_dir_dma_shift                                            (23)
#define  TP_TP_TF2_CNTL_ci_mode_shift                                            (18)
#define  TP_TP_TF2_CNTL_tp_err_fix_en_shift                                      (17)
#define  TP_TP_TF2_CNTL_strm_id_en_shift                                         (16)
#define  TP_TP_TF2_CNTL_buf_rdy_ctl_shift                                        (15)
#define  TP_TP_TF2_CNTL_psc_en_shift                                             (14)
#define  TP_TP_TF2_CNTL_pes_en_shift                                             (13)
#define  TP_TP_TF2_CNTL_tsc_en_shift                                             (12)
#define  TP_TP_TF2_CNTL_tb_shift                                                 (11)
#define  TP_TP_TF2_CNTL_busy_shift                                               (10)
#define  TP_TP_TF2_CNTL_mode_shift                                               (9)
#define  TP_TP_TF2_CNTL_du_en_shift                                              (8)
#define  TP_TP_TF2_CNTL_de_en_shift                                              (7)
#define  TP_TP_TF2_CNTL_xt_en_shift                                              (6)
#define  TP_TP_TF2_CNTL_pid_en_shift                                             (5)
#define  TP_TP_TF2_CNTL_null_en_shift                                            (4)
#define  TP_TP_TF2_CNTL_trerr_en_shift                                           (3)
#define  TP_TP_TF2_CNTL_sync_en_shift                                            (2)
#define  TP_TP_TF2_CNTL_rst_en_shift                                             (1)
#define  TP_TP_TF2_CNTL_write_data_shift                                         (0)
#define  TP_TP_TF2_CNTL_two_bit_mask                                             (0x80000000)
#define  TP_TP_TF2_CNTL_two_bit_reverse_mask                                     (0x40000000)
#define  TP_TP_TF2_CNTL_two_bit_sel_h_mask                                       (0x20000000)
#define  TP_TP_TF2_CNTL_two_bit_sel_l_mask                                       (0x10000000)
#define  TP_TP_TF2_CNTL_src_sel_h_mask                                           (0x02000000)
#define  TP_TP_TF2_CNTL_src_sel_l_mask                                           (0x01000000)
#define  TP_TP_TF2_CNTL_dir_dma_mask                                             (0x00800000)
#define  TP_TP_TF2_CNTL_ci_mode_mask                                             (0x00040000)
#define  TP_TP_TF2_CNTL_tp_err_fix_en_mask                                       (0x00020000)
#define  TP_TP_TF2_CNTL_strm_id_en_mask                                          (0x00010000)
#define  TP_TP_TF2_CNTL_buf_rdy_ctl_mask                                         (0x00008000)
#define  TP_TP_TF2_CNTL_psc_en_mask                                              (0x00004000)
#define  TP_TP_TF2_CNTL_pes_en_mask                                              (0x00002000)
#define  TP_TP_TF2_CNTL_tsc_en_mask                                              (0x00001000)
#define  TP_TP_TF2_CNTL_tb_mask                                                  (0x00000800)
#define  TP_TP_TF2_CNTL_busy_mask                                                (0x00000400)
#define  TP_TP_TF2_CNTL_mode_mask                                                (0x00000200)
#define  TP_TP_TF2_CNTL_du_en_mask                                               (0x00000100)
#define  TP_TP_TF2_CNTL_de_en_mask                                               (0x00000080)
#define  TP_TP_TF2_CNTL_xt_en_mask                                               (0x00000040)
#define  TP_TP_TF2_CNTL_pid_en_mask                                              (0x00000020)
#define  TP_TP_TF2_CNTL_null_en_mask                                             (0x00000010)
#define  TP_TP_TF2_CNTL_trerr_en_mask                                            (0x00000008)
#define  TP_TP_TF2_CNTL_sync_en_mask                                             (0x00000004)
#define  TP_TP_TF2_CNTL_rst_en_mask                                              (0x00000002)
#define  TP_TP_TF2_CNTL_write_data_mask                                          (0x00000001)
#define  TP_TP_TF2_CNTL_two_bit(data)                                            (0x80000000&((data)<<31))
#define  TP_TP_TF2_CNTL_two_bit_reverse(data)                                    (0x40000000&((data)<<30))
#define  TP_TP_TF2_CNTL_two_bit_sel_h(data)                                      (0x20000000&((data)<<29))
#define  TP_TP_TF2_CNTL_two_bit_sel_l(data)                                      (0x10000000&((data)<<28))
#define  TP_TP_TF2_CNTL_src_sel_h(data)                                          (0x02000000&((data)<<25))
#define  TP_TP_TF2_CNTL_src_sel_l(data)                                          (0x01000000&((data)<<24))
#define  TP_TP_TF2_CNTL_dir_dma(data)                                            (0x00800000&((data)<<23))
#define  TP_TP_TF2_CNTL_ci_mode(data)                                            (0x00040000&((data)<<18))
#define  TP_TP_TF2_CNTL_tp_err_fix_en(data)                                      (0x00020000&((data)<<17))
#define  TP_TP_TF2_CNTL_strm_id_en(data)                                         (0x00010000&((data)<<16))
#define  TP_TP_TF2_CNTL_buf_rdy_ctl(data)                                        (0x00008000&((data)<<15))
#define  TP_TP_TF2_CNTL_psc_en(data)                                             (0x00004000&((data)<<14))
#define  TP_TP_TF2_CNTL_pes_en(data)                                             (0x00002000&((data)<<13))
#define  TP_TP_TF2_CNTL_tsc_en(data)                                             (0x00001000&((data)<<12))
#define  TP_TP_TF2_CNTL_tb(data)                                                 (0x00000800&((data)<<11))
#define  TP_TP_TF2_CNTL_busy(data)                                               (0x00000400&((data)<<10))
#define  TP_TP_TF2_CNTL_mode(data)                                               (0x00000200&((data)<<9))
#define  TP_TP_TF2_CNTL_du_en(data)                                              (0x00000100&((data)<<8))
#define  TP_TP_TF2_CNTL_de_en(data)                                              (0x00000080&((data)<<7))
#define  TP_TP_TF2_CNTL_xt_en(data)                                              (0x00000040&((data)<<6))
#define  TP_TP_TF2_CNTL_pid_en(data)                                             (0x00000020&((data)<<5))
#define  TP_TP_TF2_CNTL_null_en(data)                                            (0x00000010&((data)<<4))
#define  TP_TP_TF2_CNTL_trerr_en(data)                                           (0x00000008&((data)<<3))
#define  TP_TP_TF2_CNTL_sync_en(data)                                            (0x00000004&((data)<<2))
#define  TP_TP_TF2_CNTL_rst_en(data)                                             (0x00000002&((data)<<1))
#define  TP_TP_TF2_CNTL_write_data(data)                                         (0x00000001&(data))
#define  TP_TP_TF2_CNTL_get_two_bit(data)                                        ((0x80000000&(data))>>31)
#define  TP_TP_TF2_CNTL_get_two_bit_reverse(data)                                ((0x40000000&(data))>>30)
#define  TP_TP_TF2_CNTL_get_two_bit_sel_h(data)                                  ((0x20000000&(data))>>29)
#define  TP_TP_TF2_CNTL_get_two_bit_sel_l(data)                                  ((0x10000000&(data))>>28)
#define  TP_TP_TF2_CNTL_get_src_sel_h(data)                                      ((0x02000000&(data))>>25)
#define  TP_TP_TF2_CNTL_get_src_sel_l(data)                                      ((0x01000000&(data))>>24)
#define  TP_TP_TF2_CNTL_get_dir_dma(data)                                        ((0x00800000&(data))>>23)
#define  TP_TP_TF2_CNTL_get_ci_mode(data)                                        ((0x00040000&(data))>>18)
#define  TP_TP_TF2_CNTL_get_tp_err_fix_en(data)                                  ((0x00020000&(data))>>17)
#define  TP_TP_TF2_CNTL_get_strm_id_en(data)                                     ((0x00010000&(data))>>16)
#define  TP_TP_TF2_CNTL_get_buf_rdy_ctl(data)                                    ((0x00008000&(data))>>15)
#define  TP_TP_TF2_CNTL_get_psc_en(data)                                         ((0x00004000&(data))>>14)
#define  TP_TP_TF2_CNTL_get_pes_en(data)                                         ((0x00002000&(data))>>13)
#define  TP_TP_TF2_CNTL_get_tsc_en(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP_TF2_CNTL_get_tb(data)                                             ((0x00000800&(data))>>11)
#define  TP_TP_TF2_CNTL_get_busy(data)                                           ((0x00000400&(data))>>10)
#define  TP_TP_TF2_CNTL_get_mode(data)                                           ((0x00000200&(data))>>9)
#define  TP_TP_TF2_CNTL_get_du_en(data)                                          ((0x00000100&(data))>>8)
#define  TP_TP_TF2_CNTL_get_de_en(data)                                          ((0x00000080&(data))>>7)
#define  TP_TP_TF2_CNTL_get_xt_en(data)                                          ((0x00000040&(data))>>6)
#define  TP_TP_TF2_CNTL_get_pid_en(data)                                         ((0x00000020&(data))>>5)
#define  TP_TP_TF2_CNTL_get_null_en(data)                                        ((0x00000010&(data))>>4)
#define  TP_TP_TF2_CNTL_get_trerr_en(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP_TF2_CNTL_get_sync_en(data)                                        ((0x00000004&(data))>>2)
#define  TP_TP_TF2_CNTL_get_rst_en(data)                                         ((0x00000002&(data))>>1)
#define  TP_TP_TF2_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  TP_TP_TF2_STRM_ID_0                                                     0x18014064
#define  TP_TP_TF2_STRM_ID_0_reg_addr                                            "0xB8014064"
#define  TP_TP_TF2_STRM_ID_0_reg                                                 0xB8014064
#define  TP_TP_TF2_STRM_ID_0_inst_addr                                           "0x0019"
#define  set_TP_TP_TF2_STRM_ID_0_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_0_reg)=data)
#define  get_TP_TP_TF2_STRM_ID_0_reg                                             (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_0_reg))
#define  TP_TP_TF2_STRM_ID_0_set3_shift                                          (24)
#define  TP_TP_TF2_STRM_ID_0_set2_shift                                          (16)
#define  TP_TP_TF2_STRM_ID_0_set1_shift                                          (8)
#define  TP_TP_TF2_STRM_ID_0_set0_shift                                          (0)
#define  TP_TP_TF2_STRM_ID_0_set3_mask                                           (0xFF000000)
#define  TP_TP_TF2_STRM_ID_0_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF2_STRM_ID_0_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF2_STRM_ID_0_set0_mask                                           (0x000000FF)
#define  TP_TP_TF2_STRM_ID_0_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF2_STRM_ID_0_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF2_STRM_ID_0_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF2_STRM_ID_0_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF2_STRM_ID_0_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF2_STRM_ID_0_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF2_STRM_ID_0_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF2_STRM_ID_0_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF2_STRM_ID_1                                                     0x18014068
#define  TP_TP_TF2_STRM_ID_1_reg_addr                                            "0xB8014068"
#define  TP_TP_TF2_STRM_ID_1_reg                                                 0xB8014068
#define  TP_TP_TF2_STRM_ID_1_inst_addr                                           "0x001A"
#define  set_TP_TP_TF2_STRM_ID_1_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_1_reg)=data)
#define  get_TP_TP_TF2_STRM_ID_1_reg                                             (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_1_reg))
#define  TP_TP_TF2_STRM_ID_1_set3_shift                                          (24)
#define  TP_TP_TF2_STRM_ID_1_set2_shift                                          (16)
#define  TP_TP_TF2_STRM_ID_1_set1_shift                                          (8)
#define  TP_TP_TF2_STRM_ID_1_set0_shift                                          (0)
#define  TP_TP_TF2_STRM_ID_1_set3_mask                                           (0xFF000000)
#define  TP_TP_TF2_STRM_ID_1_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF2_STRM_ID_1_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF2_STRM_ID_1_set0_mask                                           (0x000000FF)
#define  TP_TP_TF2_STRM_ID_1_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF2_STRM_ID_1_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF2_STRM_ID_1_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF2_STRM_ID_1_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF2_STRM_ID_1_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF2_STRM_ID_1_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF2_STRM_ID_1_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF2_STRM_ID_1_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF2_STRM_ID_2                                                     0x1801406C
#define  TP_TP_TF2_STRM_ID_2_reg_addr                                            "0xB801406C"
#define  TP_TP_TF2_STRM_ID_2_reg                                                 0xB801406C
#define  TP_TP_TF2_STRM_ID_2_inst_addr                                           "0x001B"
#define  set_TP_TP_TF2_STRM_ID_2_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_2_reg)=data)
#define  get_TP_TP_TF2_STRM_ID_2_reg                                             (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_2_reg))
#define  TP_TP_TF2_STRM_ID_2_set3_shift                                          (24)
#define  TP_TP_TF2_STRM_ID_2_set2_shift                                          (16)
#define  TP_TP_TF2_STRM_ID_2_set1_shift                                          (8)
#define  TP_TP_TF2_STRM_ID_2_set0_shift                                          (0)
#define  TP_TP_TF2_STRM_ID_2_set3_mask                                           (0xFF000000)
#define  TP_TP_TF2_STRM_ID_2_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF2_STRM_ID_2_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF2_STRM_ID_2_set0_mask                                           (0x000000FF)
#define  TP_TP_TF2_STRM_ID_2_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF2_STRM_ID_2_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF2_STRM_ID_2_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF2_STRM_ID_2_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF2_STRM_ID_2_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF2_STRM_ID_2_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF2_STRM_ID_2_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF2_STRM_ID_2_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF2_STRM_ID_3                                                     0x18014070
#define  TP_TP_TF2_STRM_ID_3_reg_addr                                            "0xB8014070"
#define  TP_TP_TF2_STRM_ID_3_reg                                                 0xB8014070
#define  TP_TP_TF2_STRM_ID_3_inst_addr                                           "0x001C"
#define  set_TP_TP_TF2_STRM_ID_3_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_3_reg)=data)
#define  get_TP_TP_TF2_STRM_ID_3_reg                                             (*((volatile unsigned int*)TP_TP_TF2_STRM_ID_3_reg))
#define  TP_TP_TF2_STRM_ID_3_set3_shift                                          (24)
#define  TP_TP_TF2_STRM_ID_3_set2_shift                                          (16)
#define  TP_TP_TF2_STRM_ID_3_set1_shift                                          (8)
#define  TP_TP_TF2_STRM_ID_3_set0_shift                                          (0)
#define  TP_TP_TF2_STRM_ID_3_set3_mask                                           (0xFF000000)
#define  TP_TP_TF2_STRM_ID_3_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF2_STRM_ID_3_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF2_STRM_ID_3_set0_mask                                           (0x000000FF)
#define  TP_TP_TF2_STRM_ID_3_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF2_STRM_ID_3_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF2_STRM_ID_3_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF2_STRM_ID_3_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF2_STRM_ID_3_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF2_STRM_ID_3_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF2_STRM_ID_3_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF2_STRM_ID_3_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF2_STRM_VAL                                                      0x18014074
#define  TP_TP_TF2_STRM_VAL_reg_addr                                             "0xB8014074"
#define  TP_TP_TF2_STRM_VAL_reg                                                  0xB8014074
#define  TP_TP_TF2_STRM_VAL_inst_addr                                            "0x001D"
#define  set_TP_TP_TF2_STRM_VAL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF2_STRM_VAL_reg)=data)
#define  get_TP_TP_TF2_STRM_VAL_reg                                              (*((volatile unsigned int*)TP_TP_TF2_STRM_VAL_reg))
#define  TP_TP_TF2_STRM_VAL_val_set33_shift                                      (15)
#define  TP_TP_TF2_STRM_VAL_val_set32_shift                                      (14)
#define  TP_TP_TF2_STRM_VAL_val_set31_shift                                      (13)
#define  TP_TP_TF2_STRM_VAL_val_set30_shift                                      (12)
#define  TP_TP_TF2_STRM_VAL_val_set23_shift                                      (11)
#define  TP_TP_TF2_STRM_VAL_val_set22_shift                                      (10)
#define  TP_TP_TF2_STRM_VAL_val_set21_shift                                      (9)
#define  TP_TP_TF2_STRM_VAL_val_set20_shift                                      (8)
#define  TP_TP_TF2_STRM_VAL_val_set13_shift                                      (7)
#define  TP_TP_TF2_STRM_VAL_val_set12_shift                                      (6)
#define  TP_TP_TF2_STRM_VAL_val_set11_shift                                      (5)
#define  TP_TP_TF2_STRM_VAL_val_set10_shift                                      (4)
#define  TP_TP_TF2_STRM_VAL_val_set03_shift                                      (3)
#define  TP_TP_TF2_STRM_VAL_val_set02_shift                                      (2)
#define  TP_TP_TF2_STRM_VAL_val_set01_shift                                      (1)
#define  TP_TP_TF2_STRM_VAL_val_set00_shift                                      (0)
#define  TP_TP_TF2_STRM_VAL_val_set33_mask                                       (0x00008000)
#define  TP_TP_TF2_STRM_VAL_val_set32_mask                                       (0x00004000)
#define  TP_TP_TF2_STRM_VAL_val_set31_mask                                       (0x00002000)
#define  TP_TP_TF2_STRM_VAL_val_set30_mask                                       (0x00001000)
#define  TP_TP_TF2_STRM_VAL_val_set23_mask                                       (0x00000800)
#define  TP_TP_TF2_STRM_VAL_val_set22_mask                                       (0x00000400)
#define  TP_TP_TF2_STRM_VAL_val_set21_mask                                       (0x00000200)
#define  TP_TP_TF2_STRM_VAL_val_set20_mask                                       (0x00000100)
#define  TP_TP_TF2_STRM_VAL_val_set13_mask                                       (0x00000080)
#define  TP_TP_TF2_STRM_VAL_val_set12_mask                                       (0x00000040)
#define  TP_TP_TF2_STRM_VAL_val_set11_mask                                       (0x00000020)
#define  TP_TP_TF2_STRM_VAL_val_set10_mask                                       (0x00000010)
#define  TP_TP_TF2_STRM_VAL_val_set03_mask                                       (0x00000008)
#define  TP_TP_TF2_STRM_VAL_val_set02_mask                                       (0x00000004)
#define  TP_TP_TF2_STRM_VAL_val_set01_mask                                       (0x00000002)
#define  TP_TP_TF2_STRM_VAL_val_set00_mask                                       (0x00000001)
#define  TP_TP_TF2_STRM_VAL_val_set33(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF2_STRM_VAL_val_set32(data)                                      (0x00004000&((data)<<14))
#define  TP_TP_TF2_STRM_VAL_val_set31(data)                                      (0x00002000&((data)<<13))
#define  TP_TP_TF2_STRM_VAL_val_set30(data)                                      (0x00001000&((data)<<12))
#define  TP_TP_TF2_STRM_VAL_val_set23(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF2_STRM_VAL_val_set22(data)                                      (0x00000400&((data)<<10))
#define  TP_TP_TF2_STRM_VAL_val_set21(data)                                      (0x00000200&((data)<<9))
#define  TP_TP_TF2_STRM_VAL_val_set20(data)                                      (0x00000100&((data)<<8))
#define  TP_TP_TF2_STRM_VAL_val_set13(data)                                      (0x00000080&((data)<<7))
#define  TP_TP_TF2_STRM_VAL_val_set12(data)                                      (0x00000040&((data)<<6))
#define  TP_TP_TF2_STRM_VAL_val_set11(data)                                      (0x00000020&((data)<<5))
#define  TP_TP_TF2_STRM_VAL_val_set10(data)                                      (0x00000010&((data)<<4))
#define  TP_TP_TF2_STRM_VAL_val_set03(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF2_STRM_VAL_val_set02(data)                                      (0x00000004&((data)<<2))
#define  TP_TP_TF2_STRM_VAL_val_set01(data)                                      (0x00000002&((data)<<1))
#define  TP_TP_TF2_STRM_VAL_val_set00(data)                                      (0x00000001&(data))
#define  TP_TP_TF2_STRM_VAL_get_val_set33(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF2_STRM_VAL_get_val_set32(data)                                  ((0x00004000&(data))>>14)
#define  TP_TP_TF2_STRM_VAL_get_val_set31(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP_TF2_STRM_VAL_get_val_set30(data)                                  ((0x00001000&(data))>>12)
#define  TP_TP_TF2_STRM_VAL_get_val_set23(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF2_STRM_VAL_get_val_set22(data)                                  ((0x00000400&(data))>>10)
#define  TP_TP_TF2_STRM_VAL_get_val_set21(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP_TF2_STRM_VAL_get_val_set20(data)                                  ((0x00000100&(data))>>8)
#define  TP_TP_TF2_STRM_VAL_get_val_set13(data)                                  ((0x00000080&(data))>>7)
#define  TP_TP_TF2_STRM_VAL_get_val_set12(data)                                  ((0x00000040&(data))>>6)
#define  TP_TP_TF2_STRM_VAL_get_val_set11(data)                                  ((0x00000020&(data))>>5)
#define  TP_TP_TF2_STRM_VAL_get_val_set10(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP_TF2_STRM_VAL_get_val_set03(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF2_STRM_VAL_get_val_set02(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP_TF2_STRM_VAL_get_val_set01(data)                                  ((0x00000002&(data))>>1)
#define  TP_TP_TF2_STRM_VAL_get_val_set00(data)                                  (0x00000001&(data))

#define  TP_TP_TF2_CNT                                                           0x18014078
#define  TP_TP_TF2_CNT_reg_addr                                                  "0xB8014078"
#define  TP_TP_TF2_CNT_reg                                                       0xB8014078
#define  TP_TP_TF2_CNT_inst_addr                                                 "0x001E"
#define  set_TP_TP_TF2_CNT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF2_CNT_reg)=data)
#define  get_TP_TP_TF2_CNT_reg                                                   (*((volatile unsigned int*)TP_TP_TF2_CNT_reg))
#define  TP_TP_TF2_CNT_cnt_shift                                                 (0)
#define  TP_TP_TF2_CNT_cnt_mask                                                  (0x00FFFFFF)
#define  TP_TP_TF2_CNT_cnt(data)                                                 (0x00FFFFFF&(data))
#define  TP_TP_TF2_CNT_get_cnt(data)                                             (0x00FFFFFF&(data))

#define  TP_TP_TF2_DRP_CNT                                                       0x1801407C
#define  TP_TP_TF2_DRP_CNT_reg_addr                                              "0xB801407C"
#define  TP_TP_TF2_DRP_CNT_reg                                                   0xB801407C
#define  TP_TP_TF2_DRP_CNT_inst_addr                                             "0x001F"
#define  set_TP_TP_TF2_DRP_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF2_DRP_CNT_reg)=data)
#define  get_TP_TP_TF2_DRP_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF2_DRP_CNT_reg))
#define  TP_TP_TF2_DRP_CNT_drp_cnt_shift                                         (0)
#define  TP_TP_TF2_DRP_CNT_drp_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF2_DRP_CNT_drp_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF2_DRP_CNT_get_drp_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF2_ERR_CNT                                                       0x18014080
#define  TP_TP_TF2_ERR_CNT_reg_addr                                              "0xB8014080"
#define  TP_TP_TF2_ERR_CNT_reg                                                   0xB8014080
#define  TP_TP_TF2_ERR_CNT_inst_addr                                             "0x0020"
#define  set_TP_TP_TF2_ERR_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF2_ERR_CNT_reg)=data)
#define  get_TP_TP_TF2_ERR_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF2_ERR_CNT_reg))
#define  TP_TP_TF2_ERR_CNT_err_cnt_shift                                         (0)
#define  TP_TP_TF2_ERR_CNT_err_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF2_ERR_CNT_err_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF2_ERR_CNT_get_err_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF2_FRMCFG                                                        0x18014084
#define  TP_TP_TF2_FRMCFG_reg_addr                                               "0xB8014084"
#define  TP_TP_TF2_FRMCFG_reg                                                    0xB8014084
#define  TP_TP_TF2_FRMCFG_inst_addr                                              "0x0021"
#define  set_TP_TP_TF2_FRMCFG_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF2_FRMCFG_reg)=data)
#define  get_TP_TP_TF2_FRMCFG_reg                                                (*((volatile unsigned int*)TP_TP_TF2_FRMCFG_reg))
#define  TP_TP_TF2_FRMCFG_sync_byte_shift                                        (24)
#define  TP_TP_TF2_FRMCFG_dropno_shift                                           (20)
#define  TP_TP_TF2_FRMCFG_lockno_shift                                           (16)
#define  TP_TP_TF2_FRMCFG_packet_size_shift                                      (14)
#define  TP_TP_TF2_FRMCFG_data_order_shift                                       (13)
#define  TP_TP_TF2_FRMCFG_frm_en_shift                                           (12)
#define  TP_TP_TF2_FRMCFG_forcedrop_shift                                        (11)
#define  TP_TP_TF2_FRMCFG_syncmode_shift                                         (6)
#define  TP_TP_TF2_FRMCFG_serial_shift                                           (5)
#define  TP_TP_TF2_FRMCFG_datapin_shift                                          (4)
#define  TP_TP_TF2_FRMCFG_sync_byte_mask                                         (0xFF000000)
#define  TP_TP_TF2_FRMCFG_dropno_mask                                            (0x00F00000)
#define  TP_TP_TF2_FRMCFG_lockno_mask                                            (0x000F0000)
#define  TP_TP_TF2_FRMCFG_packet_size_mask                                       (0x0000C000)
#define  TP_TP_TF2_FRMCFG_data_order_mask                                        (0x00002000)
#define  TP_TP_TF2_FRMCFG_frm_en_mask                                            (0x00001000)
#define  TP_TP_TF2_FRMCFG_forcedrop_mask                                         (0x00000800)
#define  TP_TP_TF2_FRMCFG_syncmode_mask                                          (0x000007C0)
#define  TP_TP_TF2_FRMCFG_serial_mask                                            (0x00000020)
#define  TP_TP_TF2_FRMCFG_datapin_mask                                           (0x00000010)
#define  TP_TP_TF2_FRMCFG_sync_byte(data)                                        (0xFF000000&((data)<<24))
#define  TP_TP_TF2_FRMCFG_dropno(data)                                           (0x00F00000&((data)<<20))
#define  TP_TP_TF2_FRMCFG_lockno(data)                                           (0x000F0000&((data)<<16))
#define  TP_TP_TF2_FRMCFG_packet_size(data)                                      (0x0000C000&((data)<<14))
#define  TP_TP_TF2_FRMCFG_data_order(data)                                       (0x00002000&((data)<<13))
#define  TP_TP_TF2_FRMCFG_frm_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF2_FRMCFG_forcedrop(data)                                        (0x00000800&((data)<<11))
#define  TP_TP_TF2_FRMCFG_syncmode(data)                                         (0x000007C0&((data)<<6))
#define  TP_TP_TF2_FRMCFG_serial(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF2_FRMCFG_datapin(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF2_FRMCFG_get_sync_byte(data)                                    ((0xFF000000&(data))>>24)
#define  TP_TP_TF2_FRMCFG_get_dropno(data)                                       ((0x00F00000&(data))>>20)
#define  TP_TP_TF2_FRMCFG_get_lockno(data)                                       ((0x000F0000&(data))>>16)
#define  TP_TP_TF2_FRMCFG_get_packet_size(data)                                  ((0x0000C000&(data))>>14)
#define  TP_TP_TF2_FRMCFG_get_data_order(data)                                   ((0x00002000&(data))>>13)
#define  TP_TP_TF2_FRMCFG_get_frm_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF2_FRMCFG_get_forcedrop(data)                                    ((0x00000800&(data))>>11)
#define  TP_TP_TF2_FRMCFG_get_syncmode(data)                                     ((0x000007C0&(data))>>6)
#define  TP_TP_TF2_FRMCFG_get_serial(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF2_FRMCFG_get_datapin(data)                                      ((0x00000010&(data))>>4)

#define  TP_TP_TF2_INT                                                           0x18014088
#define  TP_TP_TF2_INT_reg_addr                                                  "0xB8014088"
#define  TP_TP_TF2_INT_reg                                                       0xB8014088
#define  TP_TP_TF2_INT_inst_addr                                                 "0x0022"
#define  set_TP_TP_TF2_INT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF2_INT_reg)=data)
#define  get_TP_TP_TF2_INT_reg                                                   (*((volatile unsigned int*)TP_TP_TF2_INT_reg))
#define  TP_TP_TF2_INT_adf_pcr_in_shift                                          (4)
#define  TP_TP_TF2_INT_overflow_shift                                            (3)
#define  TP_TP_TF2_INT_drop_shift                                                (2)
#define  TP_TP_TF2_INT_sync_shift                                                (1)
#define  TP_TP_TF2_INT_write_data_shift                                          (0)
#define  TP_TP_TF2_INT_adf_pcr_in_mask                                           (0x00000010)
#define  TP_TP_TF2_INT_overflow_mask                                             (0x00000008)
#define  TP_TP_TF2_INT_drop_mask                                                 (0x00000004)
#define  TP_TP_TF2_INT_sync_mask                                                 (0x00000002)
#define  TP_TP_TF2_INT_write_data_mask                                           (0x00000001)
#define  TP_TP_TF2_INT_adf_pcr_in(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF2_INT_overflow(data)                                            (0x00000008&((data)<<3))
#define  TP_TP_TF2_INT_drop(data)                                                (0x00000004&((data)<<2))
#define  TP_TP_TF2_INT_sync(data)                                                (0x00000002&((data)<<1))
#define  TP_TP_TF2_INT_write_data(data)                                          (0x00000001&(data))
#define  TP_TP_TF2_INT_get_adf_pcr_in(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF2_INT_get_overflow(data)                                        ((0x00000008&(data))>>3)
#define  TP_TP_TF2_INT_get_drop(data)                                            ((0x00000004&(data))>>2)
#define  TP_TP_TF2_INT_get_sync(data)                                            ((0x00000002&(data))>>1)
#define  TP_TP_TF2_INT_get_write_data(data)                                      (0x00000001&(data))

#define  TP_TP_TF2_INT_EN                                                        0x1801408C
#define  TP_TP_TF2_INT_EN_reg_addr                                               "0xB801408C"
#define  TP_TP_TF2_INT_EN_reg                                                    0xB801408C
#define  TP_TP_TF2_INT_EN_inst_addr                                              "0x0023"
#define  set_TP_TP_TF2_INT_EN_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF2_INT_EN_reg)=data)
#define  get_TP_TP_TF2_INT_EN_reg                                                (*((volatile unsigned int*)TP_TP_TF2_INT_EN_reg))
#define  TP_TP_TF2_INT_EN_adf_pcr_in_en_shift                                    (4)
#define  TP_TP_TF2_INT_EN_overflow_en_shift                                      (3)
#define  TP_TP_TF2_INT_EN_drop_en_shift                                          (2)
#define  TP_TP_TF2_INT_EN_sync_en_shift                                          (1)
#define  TP_TP_TF2_INT_EN_write_data_shift                                       (0)
#define  TP_TP_TF2_INT_EN_adf_pcr_in_en_mask                                     (0x00000010)
#define  TP_TP_TF2_INT_EN_overflow_en_mask                                       (0x00000008)
#define  TP_TP_TF2_INT_EN_drop_en_mask                                           (0x00000004)
#define  TP_TP_TF2_INT_EN_sync_en_mask                                           (0x00000002)
#define  TP_TP_TF2_INT_EN_write_data_mask                                        (0x00000001)
#define  TP_TP_TF2_INT_EN_adf_pcr_in_en(data)                                    (0x00000010&((data)<<4))
#define  TP_TP_TF2_INT_EN_overflow_en(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF2_INT_EN_drop_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF2_INT_EN_sync_en(data)                                          (0x00000002&((data)<<1))
#define  TP_TP_TF2_INT_EN_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF2_INT_EN_get_adf_pcr_in_en(data)                                ((0x00000010&(data))>>4)
#define  TP_TP_TF2_INT_EN_get_overflow_en(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF2_INT_EN_get_drop_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF2_INT_EN_get_sync_en(data)                                      ((0x00000002&(data))>>1)
#define  TP_TP_TF2_INT_EN_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF3_CNTL                                                          0x18014320
#define  TP_TP_TF3_CNTL_reg_addr                                                 "0xB8014320"
#define  TP_TP_TF3_CNTL_reg                                                      0xB8014320
#define  TP_TP_TF3_CNTL_inst_addr                                                "0x0024"
#define  set_TP_TP_TF3_CNTL_reg(data)                                            (*((volatile unsigned int*)TP_TP_TF3_CNTL_reg)=data)
#define  get_TP_TP_TF3_CNTL_reg                                                  (*((volatile unsigned int*)TP_TP_TF3_CNTL_reg))
#define  TP_TP_TF3_CNTL_two_bit_shift                                            (31)
#define  TP_TP_TF3_CNTL_two_bit_reverse_shift                                    (30)
#define  TP_TP_TF3_CNTL_two_bit_sel_h_shift                                      (29)
#define  TP_TP_TF3_CNTL_two_bit_sel_l_shift                                      (28)
#define  TP_TP_TF3_CNTL_src_sel_h_shift                                          (25)
#define  TP_TP_TF3_CNTL_src_sel_l_shift                                          (24)
#define  TP_TP_TF3_CNTL_dir_dma_shift                                            (23)
#define  TP_TP_TF3_CNTL_ci_mode_shift                                            (18)
#define  TP_TP_TF3_CNTL_tp_err_fix_en_shift                                      (17)
#define  TP_TP_TF3_CNTL_strm_id_en_shift                                         (16)
#define  TP_TP_TF3_CNTL_buf_rdy_ctl_shift                                        (15)
#define  TP_TP_TF3_CNTL_psc_en_shift                                             (14)
#define  TP_TP_TF3_CNTL_pes_en_shift                                             (13)
#define  TP_TP_TF3_CNTL_tsc_en_shift                                             (12)
#define  TP_TP_TF3_CNTL_tb_shift                                                 (11)
#define  TP_TP_TF3_CNTL_busy_shift                                               (10)
#define  TP_TP_TF3_CNTL_mode_shift                                               (9)
#define  TP_TP_TF3_CNTL_du_en_shift                                              (8)
#define  TP_TP_TF3_CNTL_de_en_shift                                              (7)
#define  TP_TP_TF3_CNTL_xt_en_shift                                              (6)
#define  TP_TP_TF3_CNTL_pid_en_shift                                             (5)
#define  TP_TP_TF3_CNTL_null_en_shift                                            (4)
#define  TP_TP_TF3_CNTL_trerr_en_shift                                           (3)
#define  TP_TP_TF3_CNTL_sync_en_shift                                            (2)
#define  TP_TP_TF3_CNTL_rst_en_shift                                             (1)
#define  TP_TP_TF3_CNTL_write_data_shift                                         (0)
#define  TP_TP_TF3_CNTL_two_bit_mask                                             (0x80000000)
#define  TP_TP_TF3_CNTL_two_bit_reverse_mask                                     (0x40000000)
#define  TP_TP_TF3_CNTL_two_bit_sel_h_mask                                       (0x20000000)
#define  TP_TP_TF3_CNTL_two_bit_sel_l_mask                                       (0x10000000)
#define  TP_TP_TF3_CNTL_src_sel_h_mask                                           (0x02000000)
#define  TP_TP_TF3_CNTL_src_sel_l_mask                                           (0x01000000)
#define  TP_TP_TF3_CNTL_dir_dma_mask                                             (0x00800000)
#define  TP_TP_TF3_CNTL_ci_mode_mask                                             (0x00040000)
#define  TP_TP_TF3_CNTL_tp_err_fix_en_mask                                       (0x00020000)
#define  TP_TP_TF3_CNTL_strm_id_en_mask                                          (0x00010000)
#define  TP_TP_TF3_CNTL_buf_rdy_ctl_mask                                         (0x00008000)
#define  TP_TP_TF3_CNTL_psc_en_mask                                              (0x00004000)
#define  TP_TP_TF3_CNTL_pes_en_mask                                              (0x00002000)
#define  TP_TP_TF3_CNTL_tsc_en_mask                                              (0x00001000)
#define  TP_TP_TF3_CNTL_tb_mask                                                  (0x00000800)
#define  TP_TP_TF3_CNTL_busy_mask                                                (0x00000400)
#define  TP_TP_TF3_CNTL_mode_mask                                                (0x00000200)
#define  TP_TP_TF3_CNTL_du_en_mask                                               (0x00000100)
#define  TP_TP_TF3_CNTL_de_en_mask                                               (0x00000080)
#define  TP_TP_TF3_CNTL_xt_en_mask                                               (0x00000040)
#define  TP_TP_TF3_CNTL_pid_en_mask                                              (0x00000020)
#define  TP_TP_TF3_CNTL_null_en_mask                                             (0x00000010)
#define  TP_TP_TF3_CNTL_trerr_en_mask                                            (0x00000008)
#define  TP_TP_TF3_CNTL_sync_en_mask                                             (0x00000004)
#define  TP_TP_TF3_CNTL_rst_en_mask                                              (0x00000002)
#define  TP_TP_TF3_CNTL_write_data_mask                                          (0x00000001)
#define  TP_TP_TF3_CNTL_two_bit(data)                                            (0x80000000&((data)<<31))
#define  TP_TP_TF3_CNTL_two_bit_reverse(data)                                    (0x40000000&((data)<<30))
#define  TP_TP_TF3_CNTL_two_bit_sel_h(data)                                      (0x20000000&((data)<<29))
#define  TP_TP_TF3_CNTL_two_bit_sel_l(data)                                      (0x10000000&((data)<<28))
#define  TP_TP_TF3_CNTL_src_sel_h(data)                                          (0x02000000&((data)<<25))
#define  TP_TP_TF3_CNTL_src_sel_l(data)                                          (0x01000000&((data)<<24))
#define  TP_TP_TF3_CNTL_dir_dma(data)                                            (0x00800000&((data)<<23))
#define  TP_TP_TF3_CNTL_ci_mode(data)                                            (0x00040000&((data)<<18))
#define  TP_TP_TF3_CNTL_tp_err_fix_en(data)                                      (0x00020000&((data)<<17))
#define  TP_TP_TF3_CNTL_strm_id_en(data)                                         (0x00010000&((data)<<16))
#define  TP_TP_TF3_CNTL_buf_rdy_ctl(data)                                        (0x00008000&((data)<<15))
#define  TP_TP_TF3_CNTL_psc_en(data)                                             (0x00004000&((data)<<14))
#define  TP_TP_TF3_CNTL_pes_en(data)                                             (0x00002000&((data)<<13))
#define  TP_TP_TF3_CNTL_tsc_en(data)                                             (0x00001000&((data)<<12))
#define  TP_TP_TF3_CNTL_tb(data)                                                 (0x00000800&((data)<<11))
#define  TP_TP_TF3_CNTL_busy(data)                                               (0x00000400&((data)<<10))
#define  TP_TP_TF3_CNTL_mode(data)                                               (0x00000200&((data)<<9))
#define  TP_TP_TF3_CNTL_du_en(data)                                              (0x00000100&((data)<<8))
#define  TP_TP_TF3_CNTL_de_en(data)                                              (0x00000080&((data)<<7))
#define  TP_TP_TF3_CNTL_xt_en(data)                                              (0x00000040&((data)<<6))
#define  TP_TP_TF3_CNTL_pid_en(data)                                             (0x00000020&((data)<<5))
#define  TP_TP_TF3_CNTL_null_en(data)                                            (0x00000010&((data)<<4))
#define  TP_TP_TF3_CNTL_trerr_en(data)                                           (0x00000008&((data)<<3))
#define  TP_TP_TF3_CNTL_sync_en(data)                                            (0x00000004&((data)<<2))
#define  TP_TP_TF3_CNTL_rst_en(data)                                             (0x00000002&((data)<<1))
#define  TP_TP_TF3_CNTL_write_data(data)                                         (0x00000001&(data))
#define  TP_TP_TF3_CNTL_get_two_bit(data)                                        ((0x80000000&(data))>>31)
#define  TP_TP_TF3_CNTL_get_two_bit_reverse(data)                                ((0x40000000&(data))>>30)
#define  TP_TP_TF3_CNTL_get_two_bit_sel_h(data)                                  ((0x20000000&(data))>>29)
#define  TP_TP_TF3_CNTL_get_two_bit_sel_l(data)                                  ((0x10000000&(data))>>28)
#define  TP_TP_TF3_CNTL_get_src_sel_h(data)                                      ((0x02000000&(data))>>25)
#define  TP_TP_TF3_CNTL_get_src_sel_l(data)                                      ((0x01000000&(data))>>24)
#define  TP_TP_TF3_CNTL_get_dir_dma(data)                                        ((0x00800000&(data))>>23)
#define  TP_TP_TF3_CNTL_get_ci_mode(data)                                        ((0x00040000&(data))>>18)
#define  TP_TP_TF3_CNTL_get_tp_err_fix_en(data)                                  ((0x00020000&(data))>>17)
#define  TP_TP_TF3_CNTL_get_strm_id_en(data)                                     ((0x00010000&(data))>>16)
#define  TP_TP_TF3_CNTL_get_buf_rdy_ctl(data)                                    ((0x00008000&(data))>>15)
#define  TP_TP_TF3_CNTL_get_psc_en(data)                                         ((0x00004000&(data))>>14)
#define  TP_TP_TF3_CNTL_get_pes_en(data)                                         ((0x00002000&(data))>>13)
#define  TP_TP_TF3_CNTL_get_tsc_en(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP_TF3_CNTL_get_tb(data)                                             ((0x00000800&(data))>>11)
#define  TP_TP_TF3_CNTL_get_busy(data)                                           ((0x00000400&(data))>>10)
#define  TP_TP_TF3_CNTL_get_mode(data)                                           ((0x00000200&(data))>>9)
#define  TP_TP_TF3_CNTL_get_du_en(data)                                          ((0x00000100&(data))>>8)
#define  TP_TP_TF3_CNTL_get_de_en(data)                                          ((0x00000080&(data))>>7)
#define  TP_TP_TF3_CNTL_get_xt_en(data)                                          ((0x00000040&(data))>>6)
#define  TP_TP_TF3_CNTL_get_pid_en(data)                                         ((0x00000020&(data))>>5)
#define  TP_TP_TF3_CNTL_get_null_en(data)                                        ((0x00000010&(data))>>4)
#define  TP_TP_TF3_CNTL_get_trerr_en(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP_TF3_CNTL_get_sync_en(data)                                        ((0x00000004&(data))>>2)
#define  TP_TP_TF3_CNTL_get_rst_en(data)                                         ((0x00000002&(data))>>1)
#define  TP_TP_TF3_CNTL_get_write_data(data)                                     (0x00000001&(data))

#define  TP_TP_TF3_STRM_ID_0                                                     0x18014324
#define  TP_TP_TF3_STRM_ID_0_reg_addr                                            "0xB8014324"
#define  TP_TP_TF3_STRM_ID_0_reg                                                 0xB8014324
#define  TP_TP_TF3_STRM_ID_0_inst_addr                                           "0x0025"
#define  set_TP_TP_TF3_STRM_ID_0_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_0_reg)=data)
#define  get_TP_TP_TF3_STRM_ID_0_reg                                             (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_0_reg))
#define  TP_TP_TF3_STRM_ID_0_set3_shift                                          (24)
#define  TP_TP_TF3_STRM_ID_0_set2_shift                                          (16)
#define  TP_TP_TF3_STRM_ID_0_set1_shift                                          (8)
#define  TP_TP_TF3_STRM_ID_0_set0_shift                                          (0)
#define  TP_TP_TF3_STRM_ID_0_set3_mask                                           (0xFF000000)
#define  TP_TP_TF3_STRM_ID_0_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF3_STRM_ID_0_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF3_STRM_ID_0_set0_mask                                           (0x000000FF)
#define  TP_TP_TF3_STRM_ID_0_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF3_STRM_ID_0_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF3_STRM_ID_0_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF3_STRM_ID_0_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF3_STRM_ID_0_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF3_STRM_ID_0_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF3_STRM_ID_0_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF3_STRM_ID_0_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF3_STRM_ID_1                                                     0x18014328
#define  TP_TP_TF3_STRM_ID_1_reg_addr                                            "0xB8014328"
#define  TP_TP_TF3_STRM_ID_1_reg                                                 0xB8014328
#define  TP_TP_TF3_STRM_ID_1_inst_addr                                           "0x0026"
#define  set_TP_TP_TF3_STRM_ID_1_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_1_reg)=data)
#define  get_TP_TP_TF3_STRM_ID_1_reg                                             (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_1_reg))
#define  TP_TP_TF3_STRM_ID_1_set3_shift                                          (24)
#define  TP_TP_TF3_STRM_ID_1_set2_shift                                          (16)
#define  TP_TP_TF3_STRM_ID_1_set1_shift                                          (8)
#define  TP_TP_TF3_STRM_ID_1_set0_shift                                          (0)
#define  TP_TP_TF3_STRM_ID_1_set3_mask                                           (0xFF000000)
#define  TP_TP_TF3_STRM_ID_1_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF3_STRM_ID_1_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF3_STRM_ID_1_set0_mask                                           (0x000000FF)
#define  TP_TP_TF3_STRM_ID_1_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF3_STRM_ID_1_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF3_STRM_ID_1_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF3_STRM_ID_1_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF3_STRM_ID_1_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF3_STRM_ID_1_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF3_STRM_ID_1_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF3_STRM_ID_1_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF3_STRM_ID_2                                                     0x1801432C
#define  TP_TP_TF3_STRM_ID_2_reg_addr                                            "0xB801432C"
#define  TP_TP_TF3_STRM_ID_2_reg                                                 0xB801432C
#define  TP_TP_TF3_STRM_ID_2_inst_addr                                           "0x0027"
#define  set_TP_TP_TF3_STRM_ID_2_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_2_reg)=data)
#define  get_TP_TP_TF3_STRM_ID_2_reg                                             (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_2_reg))
#define  TP_TP_TF3_STRM_ID_2_set3_shift                                          (24)
#define  TP_TP_TF3_STRM_ID_2_set2_shift                                          (16)
#define  TP_TP_TF3_STRM_ID_2_set1_shift                                          (8)
#define  TP_TP_TF3_STRM_ID_2_set0_shift                                          (0)
#define  TP_TP_TF3_STRM_ID_2_set3_mask                                           (0xFF000000)
#define  TP_TP_TF3_STRM_ID_2_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF3_STRM_ID_2_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF3_STRM_ID_2_set0_mask                                           (0x000000FF)
#define  TP_TP_TF3_STRM_ID_2_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF3_STRM_ID_2_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF3_STRM_ID_2_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF3_STRM_ID_2_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF3_STRM_ID_2_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF3_STRM_ID_2_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF3_STRM_ID_2_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF3_STRM_ID_2_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF3_STRM_ID_3                                                     0x18014330
#define  TP_TP_TF3_STRM_ID_3_reg_addr                                            "0xB8014330"
#define  TP_TP_TF3_STRM_ID_3_reg                                                 0xB8014330
#define  TP_TP_TF3_STRM_ID_3_inst_addr                                           "0x0028"
#define  set_TP_TP_TF3_STRM_ID_3_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_3_reg)=data)
#define  get_TP_TP_TF3_STRM_ID_3_reg                                             (*((volatile unsigned int*)TP_TP_TF3_STRM_ID_3_reg))
#define  TP_TP_TF3_STRM_ID_3_set3_shift                                          (24)
#define  TP_TP_TF3_STRM_ID_3_set2_shift                                          (16)
#define  TP_TP_TF3_STRM_ID_3_set1_shift                                          (8)
#define  TP_TP_TF3_STRM_ID_3_set0_shift                                          (0)
#define  TP_TP_TF3_STRM_ID_3_set3_mask                                           (0xFF000000)
#define  TP_TP_TF3_STRM_ID_3_set2_mask                                           (0x00FF0000)
#define  TP_TP_TF3_STRM_ID_3_set1_mask                                           (0x0000FF00)
#define  TP_TP_TF3_STRM_ID_3_set0_mask                                           (0x000000FF)
#define  TP_TP_TF3_STRM_ID_3_set3(data)                                          (0xFF000000&((data)<<24))
#define  TP_TP_TF3_STRM_ID_3_set2(data)                                          (0x00FF0000&((data)<<16))
#define  TP_TP_TF3_STRM_ID_3_set1(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TF3_STRM_ID_3_set0(data)                                          (0x000000FF&(data))
#define  TP_TP_TF3_STRM_ID_3_get_set3(data)                                      ((0xFF000000&(data))>>24)
#define  TP_TP_TF3_STRM_ID_3_get_set2(data)                                      ((0x00FF0000&(data))>>16)
#define  TP_TP_TF3_STRM_ID_3_get_set1(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TF3_STRM_ID_3_get_set0(data)                                      (0x000000FF&(data))

#define  TP_TP_TF3_STRM_VAL                                                      0x18014334
#define  TP_TP_TF3_STRM_VAL_reg_addr                                             "0xB8014334"
#define  TP_TP_TF3_STRM_VAL_reg                                                  0xB8014334
#define  TP_TP_TF3_STRM_VAL_inst_addr                                            "0x0029"
#define  set_TP_TP_TF3_STRM_VAL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF3_STRM_VAL_reg)=data)
#define  get_TP_TP_TF3_STRM_VAL_reg                                              (*((volatile unsigned int*)TP_TP_TF3_STRM_VAL_reg))
#define  TP_TP_TF3_STRM_VAL_val_set33_shift                                      (15)
#define  TP_TP_TF3_STRM_VAL_val_set32_shift                                      (14)
#define  TP_TP_TF3_STRM_VAL_val_set31_shift                                      (13)
#define  TP_TP_TF3_STRM_VAL_val_set30_shift                                      (12)
#define  TP_TP_TF3_STRM_VAL_val_set23_shift                                      (11)
#define  TP_TP_TF3_STRM_VAL_val_set22_shift                                      (10)
#define  TP_TP_TF3_STRM_VAL_val_set21_shift                                      (9)
#define  TP_TP_TF3_STRM_VAL_val_set20_shift                                      (8)
#define  TP_TP_TF3_STRM_VAL_val_set13_shift                                      (7)
#define  TP_TP_TF3_STRM_VAL_val_set12_shift                                      (6)
#define  TP_TP_TF3_STRM_VAL_val_set11_shift                                      (5)
#define  TP_TP_TF3_STRM_VAL_val_set10_shift                                      (4)
#define  TP_TP_TF3_STRM_VAL_val_set03_shift                                      (3)
#define  TP_TP_TF3_STRM_VAL_val_set02_shift                                      (2)
#define  TP_TP_TF3_STRM_VAL_val_set01_shift                                      (1)
#define  TP_TP_TF3_STRM_VAL_val_set00_shift                                      (0)
#define  TP_TP_TF3_STRM_VAL_val_set33_mask                                       (0x00008000)
#define  TP_TP_TF3_STRM_VAL_val_set32_mask                                       (0x00004000)
#define  TP_TP_TF3_STRM_VAL_val_set31_mask                                       (0x00002000)
#define  TP_TP_TF3_STRM_VAL_val_set30_mask                                       (0x00001000)
#define  TP_TP_TF3_STRM_VAL_val_set23_mask                                       (0x00000800)
#define  TP_TP_TF3_STRM_VAL_val_set22_mask                                       (0x00000400)
#define  TP_TP_TF3_STRM_VAL_val_set21_mask                                       (0x00000200)
#define  TP_TP_TF3_STRM_VAL_val_set20_mask                                       (0x00000100)
#define  TP_TP_TF3_STRM_VAL_val_set13_mask                                       (0x00000080)
#define  TP_TP_TF3_STRM_VAL_val_set12_mask                                       (0x00000040)
#define  TP_TP_TF3_STRM_VAL_val_set11_mask                                       (0x00000020)
#define  TP_TP_TF3_STRM_VAL_val_set10_mask                                       (0x00000010)
#define  TP_TP_TF3_STRM_VAL_val_set03_mask                                       (0x00000008)
#define  TP_TP_TF3_STRM_VAL_val_set02_mask                                       (0x00000004)
#define  TP_TP_TF3_STRM_VAL_val_set01_mask                                       (0x00000002)
#define  TP_TP_TF3_STRM_VAL_val_set00_mask                                       (0x00000001)
#define  TP_TP_TF3_STRM_VAL_val_set33(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF3_STRM_VAL_val_set32(data)                                      (0x00004000&((data)<<14))
#define  TP_TP_TF3_STRM_VAL_val_set31(data)                                      (0x00002000&((data)<<13))
#define  TP_TP_TF3_STRM_VAL_val_set30(data)                                      (0x00001000&((data)<<12))
#define  TP_TP_TF3_STRM_VAL_val_set23(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF3_STRM_VAL_val_set22(data)                                      (0x00000400&((data)<<10))
#define  TP_TP_TF3_STRM_VAL_val_set21(data)                                      (0x00000200&((data)<<9))
#define  TP_TP_TF3_STRM_VAL_val_set20(data)                                      (0x00000100&((data)<<8))
#define  TP_TP_TF3_STRM_VAL_val_set13(data)                                      (0x00000080&((data)<<7))
#define  TP_TP_TF3_STRM_VAL_val_set12(data)                                      (0x00000040&((data)<<6))
#define  TP_TP_TF3_STRM_VAL_val_set11(data)                                      (0x00000020&((data)<<5))
#define  TP_TP_TF3_STRM_VAL_val_set10(data)                                      (0x00000010&((data)<<4))
#define  TP_TP_TF3_STRM_VAL_val_set03(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF3_STRM_VAL_val_set02(data)                                      (0x00000004&((data)<<2))
#define  TP_TP_TF3_STRM_VAL_val_set01(data)                                      (0x00000002&((data)<<1))
#define  TP_TP_TF3_STRM_VAL_val_set00(data)                                      (0x00000001&(data))
#define  TP_TP_TF3_STRM_VAL_get_val_set33(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF3_STRM_VAL_get_val_set32(data)                                  ((0x00004000&(data))>>14)
#define  TP_TP_TF3_STRM_VAL_get_val_set31(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP_TF3_STRM_VAL_get_val_set30(data)                                  ((0x00001000&(data))>>12)
#define  TP_TP_TF3_STRM_VAL_get_val_set23(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF3_STRM_VAL_get_val_set22(data)                                  ((0x00000400&(data))>>10)
#define  TP_TP_TF3_STRM_VAL_get_val_set21(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP_TF3_STRM_VAL_get_val_set20(data)                                  ((0x00000100&(data))>>8)
#define  TP_TP_TF3_STRM_VAL_get_val_set13(data)                                  ((0x00000080&(data))>>7)
#define  TP_TP_TF3_STRM_VAL_get_val_set12(data)                                  ((0x00000040&(data))>>6)
#define  TP_TP_TF3_STRM_VAL_get_val_set11(data)                                  ((0x00000020&(data))>>5)
#define  TP_TP_TF3_STRM_VAL_get_val_set10(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP_TF3_STRM_VAL_get_val_set03(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF3_STRM_VAL_get_val_set02(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP_TF3_STRM_VAL_get_val_set01(data)                                  ((0x00000002&(data))>>1)
#define  TP_TP_TF3_STRM_VAL_get_val_set00(data)                                  (0x00000001&(data))

#define  TP_TP_TF3_CNT                                                           0x18014338
#define  TP_TP_TF3_CNT_reg_addr                                                  "0xB8014338"
#define  TP_TP_TF3_CNT_reg                                                       0xB8014338
#define  TP_TP_TF3_CNT_inst_addr                                                 "0x002A"
#define  set_TP_TP_TF3_CNT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF3_CNT_reg)=data)
#define  get_TP_TP_TF3_CNT_reg                                                   (*((volatile unsigned int*)TP_TP_TF3_CNT_reg))
#define  TP_TP_TF3_CNT_cnt_shift                                                 (0)
#define  TP_TP_TF3_CNT_cnt_mask                                                  (0x00FFFFFF)
#define  TP_TP_TF3_CNT_cnt(data)                                                 (0x00FFFFFF&(data))
#define  TP_TP_TF3_CNT_get_cnt(data)                                             (0x00FFFFFF&(data))

#define  TP_TP_TF3_DRP_CNT                                                       0x1801433C
#define  TP_TP_TF3_DRP_CNT_reg_addr                                              "0xB801433C"
#define  TP_TP_TF3_DRP_CNT_reg                                                   0xB801433C
#define  TP_TP_TF3_DRP_CNT_inst_addr                                             "0x002B"
#define  set_TP_TP_TF3_DRP_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF3_DRP_CNT_reg)=data)
#define  get_TP_TP_TF3_DRP_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF3_DRP_CNT_reg))
#define  TP_TP_TF3_DRP_CNT_drp_cnt_shift                                         (0)
#define  TP_TP_TF3_DRP_CNT_drp_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF3_DRP_CNT_drp_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF3_DRP_CNT_get_drp_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF3_ERR_CNT                                                       0x18014340
#define  TP_TP_TF3_ERR_CNT_reg_addr                                              "0xB8014340"
#define  TP_TP_TF3_ERR_CNT_reg                                                   0xB8014340
#define  TP_TP_TF3_ERR_CNT_inst_addr                                             "0x002C"
#define  set_TP_TP_TF3_ERR_CNT_reg(data)                                         (*((volatile unsigned int*)TP_TP_TF3_ERR_CNT_reg)=data)
#define  get_TP_TP_TF3_ERR_CNT_reg                                               (*((volatile unsigned int*)TP_TP_TF3_ERR_CNT_reg))
#define  TP_TP_TF3_ERR_CNT_err_cnt_shift                                         (0)
#define  TP_TP_TF3_ERR_CNT_err_cnt_mask                                          (0x0000FFFF)
#define  TP_TP_TF3_ERR_CNT_err_cnt(data)                                         (0x0000FFFF&(data))
#define  TP_TP_TF3_ERR_CNT_get_err_cnt(data)                                     (0x0000FFFF&(data))

#define  TP_TP_TF3_FRMCFG                                                        0x18014344
#define  TP_TP_TF3_FRMCFG_reg_addr                                               "0xB8014344"
#define  TP_TP_TF3_FRMCFG_reg                                                    0xB8014344
#define  TP_TP_TF3_FRMCFG_inst_addr                                              "0x002D"
#define  set_TP_TP_TF3_FRMCFG_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF3_FRMCFG_reg)=data)
#define  get_TP_TP_TF3_FRMCFG_reg                                                (*((volatile unsigned int*)TP_TP_TF3_FRMCFG_reg))
#define  TP_TP_TF3_FRMCFG_sync_byte_shift                                        (24)
#define  TP_TP_TF3_FRMCFG_dropno_shift                                           (20)
#define  TP_TP_TF3_FRMCFG_lockno_shift                                           (16)
#define  TP_TP_TF3_FRMCFG_packet_size_shift                                      (14)
#define  TP_TP_TF3_FRMCFG_data_order_shift                                       (13)
#define  TP_TP_TF3_FRMCFG_frm_en_shift                                           (12)
#define  TP_TP_TF3_FRMCFG_forcedrop_shift                                        (11)
#define  TP_TP_TF3_FRMCFG_syncmode_shift                                         (6)
#define  TP_TP_TF3_FRMCFG_serial_shift                                           (5)
#define  TP_TP_TF3_FRMCFG_datapin_shift                                          (4)
#define  TP_TP_TF3_FRMCFG_sync_byte_mask                                         (0xFF000000)
#define  TP_TP_TF3_FRMCFG_dropno_mask                                            (0x00F00000)
#define  TP_TP_TF3_FRMCFG_lockno_mask                                            (0x000F0000)
#define  TP_TP_TF3_FRMCFG_packet_size_mask                                       (0x0000C000)
#define  TP_TP_TF3_FRMCFG_data_order_mask                                        (0x00002000)
#define  TP_TP_TF3_FRMCFG_frm_en_mask                                            (0x00001000)
#define  TP_TP_TF3_FRMCFG_forcedrop_mask                                         (0x00000800)
#define  TP_TP_TF3_FRMCFG_syncmode_mask                                          (0x000007C0)
#define  TP_TP_TF3_FRMCFG_serial_mask                                            (0x00000020)
#define  TP_TP_TF3_FRMCFG_datapin_mask                                           (0x00000010)
#define  TP_TP_TF3_FRMCFG_sync_byte(data)                                        (0xFF000000&((data)<<24))
#define  TP_TP_TF3_FRMCFG_dropno(data)                                           (0x00F00000&((data)<<20))
#define  TP_TP_TF3_FRMCFG_lockno(data)                                           (0x000F0000&((data)<<16))
#define  TP_TP_TF3_FRMCFG_packet_size(data)                                      (0x0000C000&((data)<<14))
#define  TP_TP_TF3_FRMCFG_data_order(data)                                       (0x00002000&((data)<<13))
#define  TP_TP_TF3_FRMCFG_frm_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF3_FRMCFG_forcedrop(data)                                        (0x00000800&((data)<<11))
#define  TP_TP_TF3_FRMCFG_syncmode(data)                                         (0x000007C0&((data)<<6))
#define  TP_TP_TF3_FRMCFG_serial(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF3_FRMCFG_datapin(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF3_FRMCFG_get_sync_byte(data)                                    ((0xFF000000&(data))>>24)
#define  TP_TP_TF3_FRMCFG_get_dropno(data)                                       ((0x00F00000&(data))>>20)
#define  TP_TP_TF3_FRMCFG_get_lockno(data)                                       ((0x000F0000&(data))>>16)
#define  TP_TP_TF3_FRMCFG_get_packet_size(data)                                  ((0x0000C000&(data))>>14)
#define  TP_TP_TF3_FRMCFG_get_data_order(data)                                   ((0x00002000&(data))>>13)
#define  TP_TP_TF3_FRMCFG_get_frm_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF3_FRMCFG_get_forcedrop(data)                                    ((0x00000800&(data))>>11)
#define  TP_TP_TF3_FRMCFG_get_syncmode(data)                                     ((0x000007C0&(data))>>6)
#define  TP_TP_TF3_FRMCFG_get_serial(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF3_FRMCFG_get_datapin(data)                                      ((0x00000010&(data))>>4)

#define  TP_TP_TF3_INT                                                           0x18014348
#define  TP_TP_TF3_INT_reg_addr                                                  "0xB8014348"
#define  TP_TP_TF3_INT_reg                                                       0xB8014348
#define  TP_TP_TF3_INT_inst_addr                                                 "0x002E"
#define  set_TP_TP_TF3_INT_reg(data)                                             (*((volatile unsigned int*)TP_TP_TF3_INT_reg)=data)
#define  get_TP_TP_TF3_INT_reg                                                   (*((volatile unsigned int*)TP_TP_TF3_INT_reg))
#define  TP_TP_TF3_INT_adf_pcr_in_shift                                          (4)
#define  TP_TP_TF3_INT_overflow_shift                                            (3)
#define  TP_TP_TF3_INT_drop_shift                                                (2)
#define  TP_TP_TF3_INT_sync_shift                                                (1)
#define  TP_TP_TF3_INT_write_data_shift                                          (0)
#define  TP_TP_TF3_INT_adf_pcr_in_mask                                           (0x00000010)
#define  TP_TP_TF3_INT_overflow_mask                                             (0x00000008)
#define  TP_TP_TF3_INT_drop_mask                                                 (0x00000004)
#define  TP_TP_TF3_INT_sync_mask                                                 (0x00000002)
#define  TP_TP_TF3_INT_write_data_mask                                           (0x00000001)
#define  TP_TP_TF3_INT_adf_pcr_in(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF3_INT_overflow(data)                                            (0x00000008&((data)<<3))
#define  TP_TP_TF3_INT_drop(data)                                                (0x00000004&((data)<<2))
#define  TP_TP_TF3_INT_sync(data)                                                (0x00000002&((data)<<1))
#define  TP_TP_TF3_INT_write_data(data)                                          (0x00000001&(data))
#define  TP_TP_TF3_INT_get_adf_pcr_in(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF3_INT_get_overflow(data)                                        ((0x00000008&(data))>>3)
#define  TP_TP_TF3_INT_get_drop(data)                                            ((0x00000004&(data))>>2)
#define  TP_TP_TF3_INT_get_sync(data)                                            ((0x00000002&(data))>>1)
#define  TP_TP_TF3_INT_get_write_data(data)                                      (0x00000001&(data))

#define  TP_TP_TF3_INT_EN                                                        0x1801434C
#define  TP_TP_TF3_INT_EN_reg_addr                                               "0xB801434C"
#define  TP_TP_TF3_INT_EN_reg                                                    0xB801434C
#define  TP_TP_TF3_INT_EN_inst_addr                                              "0x002F"
#define  set_TP_TP_TF3_INT_EN_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF3_INT_EN_reg)=data)
#define  get_TP_TP_TF3_INT_EN_reg                                                (*((volatile unsigned int*)TP_TP_TF3_INT_EN_reg))
#define  TP_TP_TF3_INT_EN_adf_pcr_in_en_shift                                    (4)
#define  TP_TP_TF3_INT_EN_overflow_en_shift                                      (3)
#define  TP_TP_TF3_INT_EN_drop_en_shift                                          (2)
#define  TP_TP_TF3_INT_EN_sync_en_shift                                          (1)
#define  TP_TP_TF3_INT_EN_write_data_shift                                       (0)
#define  TP_TP_TF3_INT_EN_adf_pcr_in_en_mask                                     (0x00000010)
#define  TP_TP_TF3_INT_EN_overflow_en_mask                                       (0x00000008)
#define  TP_TP_TF3_INT_EN_drop_en_mask                                           (0x00000004)
#define  TP_TP_TF3_INT_EN_sync_en_mask                                           (0x00000002)
#define  TP_TP_TF3_INT_EN_write_data_mask                                        (0x00000001)
#define  TP_TP_TF3_INT_EN_adf_pcr_in_en(data)                                    (0x00000010&((data)<<4))
#define  TP_TP_TF3_INT_EN_overflow_en(data)                                      (0x00000008&((data)<<3))
#define  TP_TP_TF3_INT_EN_drop_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF3_INT_EN_sync_en(data)                                          (0x00000002&((data)<<1))
#define  TP_TP_TF3_INT_EN_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF3_INT_EN_get_adf_pcr_in_en(data)                                ((0x00000010&(data))>>4)
#define  TP_TP_TF3_INT_EN_get_overflow_en(data)                                  ((0x00000008&(data))>>3)
#define  TP_TP_TF3_INT_EN_get_drop_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF3_INT_EN_get_sync_en(data)                                      ((0x00000002&(data))>>1)
#define  TP_TP_TF3_INT_EN_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF_OUT_FRMCFG                                                     0x18014090
#define  TP_TP_TF_OUT_FRMCFG_reg_addr                                            "0xB8014090"
#define  TP_TP_TF_OUT_FRMCFG_reg                                                 0xB8014090
#define  TP_TP_TF_OUT_FRMCFG_inst_addr                                           "0x0030"
#define  set_TP_TP_TF_OUT_FRMCFG_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF_OUT_FRMCFG_reg)=data)
#define  get_TP_TP_TF_OUT_FRMCFG_reg                                             (*((volatile unsigned int*)TP_TP_TF_OUT_FRMCFG_reg))
#define  TP_TP_TF_OUT_FRMCFG_in_tpp_out_en_shift                                 (22)
#define  TP_TP_TF_OUT_FRMCFG_in_tp_out_en_shift                                  (21)
#define  TP_TP_TF_OUT_FRMCFG_in_tp_rst_shift                                     (19)
#define  TP_TP_TF_OUT_FRMCFG_data_src_shift                                      (16)
#define  TP_TP_TF_OUT_FRMCFG_in_data_order_shift                                 (14)
#define  TP_TP_TF_OUT_FRMCFG_in_serial_shift                                     (13)
#define  TP_TP_TF_OUT_FRMCFG_in_datapin_shift                                    (12)
#define  TP_TP_TF_OUT_FRMCFG_in_sync_pol_shift                                   (10)
#define  TP_TP_TF_OUT_FRMCFG_in_val_pol_shift                                    (9)
#define  TP_TP_TF_OUT_FRMCFG_in_clk_pol_shift                                    (8)
#define  TP_TP_TF_OUT_FRMCFG_out_data_order_shift                                (6)
#define  TP_TP_TF_OUT_FRMCFG_out_serial_shift                                    (5)
#define  TP_TP_TF_OUT_FRMCFG_out_sync_pol_shift                                  (2)
#define  TP_TP_TF_OUT_FRMCFG_out_val_pol_shift                                   (1)
#define  TP_TP_TF_OUT_FRMCFG_out_clk_pol_shift                                   (0)
#define  TP_TP_TF_OUT_FRMCFG_in_tpp_out_en_mask                                  (0x00400000)
#define  TP_TP_TF_OUT_FRMCFG_in_tp_out_en_mask                                   (0x00200000)
#define  TP_TP_TF_OUT_FRMCFG_in_tp_rst_mask                                      (0x00080000)
#define  TP_TP_TF_OUT_FRMCFG_data_src_mask                                       (0x00070000)
#define  TP_TP_TF_OUT_FRMCFG_in_data_order_mask                                  (0x00004000)
#define  TP_TP_TF_OUT_FRMCFG_in_serial_mask                                      (0x00002000)
#define  TP_TP_TF_OUT_FRMCFG_in_datapin_mask                                     (0x00001000)
#define  TP_TP_TF_OUT_FRMCFG_in_sync_pol_mask                                    (0x00000400)
#define  TP_TP_TF_OUT_FRMCFG_in_val_pol_mask                                     (0x00000200)
#define  TP_TP_TF_OUT_FRMCFG_in_clk_pol_mask                                     (0x00000100)
#define  TP_TP_TF_OUT_FRMCFG_out_data_order_mask                                 (0x00000040)
#define  TP_TP_TF_OUT_FRMCFG_out_serial_mask                                     (0x00000020)
#define  TP_TP_TF_OUT_FRMCFG_out_sync_pol_mask                                   (0x00000004)
#define  TP_TP_TF_OUT_FRMCFG_out_val_pol_mask                                    (0x00000002)
#define  TP_TP_TF_OUT_FRMCFG_out_clk_pol_mask                                    (0x00000001)
#define  TP_TP_TF_OUT_FRMCFG_in_tpp_out_en(data)                                 (0x00400000&((data)<<22))
#define  TP_TP_TF_OUT_FRMCFG_in_tp_out_en(data)                                  (0x00200000&((data)<<21))
#define  TP_TP_TF_OUT_FRMCFG_in_tp_rst(data)                                     (0x00080000&((data)<<19))
#define  TP_TP_TF_OUT_FRMCFG_data_src(data)                                      (0x00070000&((data)<<16))
#define  TP_TP_TF_OUT_FRMCFG_in_data_order(data)                                 (0x00004000&((data)<<14))
#define  TP_TP_TF_OUT_FRMCFG_in_serial(data)                                     (0x00002000&((data)<<13))
#define  TP_TP_TF_OUT_FRMCFG_in_datapin(data)                                    (0x00001000&((data)<<12))
#define  TP_TP_TF_OUT_FRMCFG_in_sync_pol(data)                                   (0x00000400&((data)<<10))
#define  TP_TP_TF_OUT_FRMCFG_in_val_pol(data)                                    (0x00000200&((data)<<9))
#define  TP_TP_TF_OUT_FRMCFG_in_clk_pol(data)                                    (0x00000100&((data)<<8))
#define  TP_TP_TF_OUT_FRMCFG_out_data_order(data)                                (0x00000040&((data)<<6))
#define  TP_TP_TF_OUT_FRMCFG_out_serial(data)                                    (0x00000020&((data)<<5))
#define  TP_TP_TF_OUT_FRMCFG_out_sync_pol(data)                                  (0x00000004&((data)<<2))
#define  TP_TP_TF_OUT_FRMCFG_out_val_pol(data)                                   (0x00000002&((data)<<1))
#define  TP_TP_TF_OUT_FRMCFG_out_clk_pol(data)                                   (0x00000001&(data))
#define  TP_TP_TF_OUT_FRMCFG_get_in_tpp_out_en(data)                             ((0x00400000&(data))>>22)
#define  TP_TP_TF_OUT_FRMCFG_get_in_tp_out_en(data)                              ((0x00200000&(data))>>21)
#define  TP_TP_TF_OUT_FRMCFG_get_in_tp_rst(data)                                 ((0x00080000&(data))>>19)
#define  TP_TP_TF_OUT_FRMCFG_get_data_src(data)                                  ((0x00070000&(data))>>16)
#define  TP_TP_TF_OUT_FRMCFG_get_in_data_order(data)                             ((0x00004000&(data))>>14)
#define  TP_TP_TF_OUT_FRMCFG_get_in_serial(data)                                 ((0x00002000&(data))>>13)
#define  TP_TP_TF_OUT_FRMCFG_get_in_datapin(data)                                ((0x00001000&(data))>>12)
#define  TP_TP_TF_OUT_FRMCFG_get_in_sync_pol(data)                               ((0x00000400&(data))>>10)
#define  TP_TP_TF_OUT_FRMCFG_get_in_val_pol(data)                                ((0x00000200&(data))>>9)
#define  TP_TP_TF_OUT_FRMCFG_get_in_clk_pol(data)                                ((0x00000100&(data))>>8)
#define  TP_TP_TF_OUT_FRMCFG_get_out_data_order(data)                            ((0x00000040&(data))>>6)
#define  TP_TP_TF_OUT_FRMCFG_get_out_serial(data)                                ((0x00000020&(data))>>5)
#define  TP_TP_TF_OUT_FRMCFG_get_out_sync_pol(data)                              ((0x00000004&(data))>>2)
#define  TP_TP_TF_OUT_FRMCFG_get_out_val_pol(data)                               ((0x00000002&(data))>>1)
#define  TP_TP_TF_OUT_FRMCFG_get_out_clk_pol(data)                               (0x00000001&(data))

#define  TP_TP_OUT_CTRL                                                          0x18014094
#define  TP_TP_OUT_CTRL_reg_addr                                                 "0xB8014094"
#define  TP_TP_OUT_CTRL_reg                                                      0xB8014094
#define  TP_TP_OUT_CTRL_inst_addr                                                "0x0031"
#define  set_TP_TP_OUT_CTRL_reg(data)                                            (*((volatile unsigned int*)TP_TP_OUT_CTRL_reg)=data)
#define  get_TP_TP_OUT_CTRL_reg                                                  (*((volatile unsigned int*)TP_TP_OUT_CTRL_reg))
#define  TP_TP_OUT_CTRL_share_mode_shift                                         (24)
#define  TP_TP_OUT_CTRL_out_share_en_shift                                       (23)
#define  TP_TP_OUT_CTRL_out_stop_mode_shift                                      (22)
#define  TP_TP_OUT_CTRL_get_size_shift                                           (20)
#define  TP_TP_OUT_CTRL_sync_dur_shift                                           (19)
#define  TP_TP_OUT_CTRL_ck_gate_shift                                            (18)
#define  TP_TP_OUT_CTRL_tp_frame_rate_shift                                      (5)
#define  TP_TP_OUT_CTRL_data_sel_shift                                           (4)
#define  TP_TP_OUT_CTRL_share_mode_mask                                          (0x01000000)
#define  TP_TP_OUT_CTRL_out_share_en_mask                                        (0x00800000)
#define  TP_TP_OUT_CTRL_out_stop_mode_mask                                       (0x00400000)
#define  TP_TP_OUT_CTRL_get_size_mask                                            (0x00300000)
#define  TP_TP_OUT_CTRL_sync_dur_mask                                            (0x00080000)
#define  TP_TP_OUT_CTRL_ck_gate_mask                                             (0x00040000)
#define  TP_TP_OUT_CTRL_tp_frame_rate_mask                                       (0x0003FFE0)
#define  TP_TP_OUT_CTRL_data_sel_mask                                            (0x00000010)
#define  TP_TP_OUT_CTRL_share_mode(data)                                         (0x01000000&((data)<<24))
#define  TP_TP_OUT_CTRL_out_share_en(data)                                       (0x00800000&((data)<<23))
#define  TP_TP_OUT_CTRL_out_stop_mode(data)                                      (0x00400000&((data)<<22))
#define  TP_TP_OUT_CTRL_get_size(data)                                           (0x00300000&((data)<<20))
#define  TP_TP_OUT_CTRL_sync_dur(data)                                           (0x00080000&((data)<<19))
#define  TP_TP_OUT_CTRL_ck_gate(data)                                            (0x00040000&((data)<<18))
#define  TP_TP_OUT_CTRL_tp_frame_rate(data)                                      (0x0003FFE0&((data)<<5))
#define  TP_TP_OUT_CTRL_data_sel(data)                                           (0x00000010&((data)<<4))
#define  TP_TP_OUT_CTRL_get_share_mode(data)                                     ((0x01000000&(data))>>24)
#define  TP_TP_OUT_CTRL_get_out_share_en(data)                                   ((0x00800000&(data))>>23)
#define  TP_TP_OUT_CTRL_get_out_stop_mode(data)                                  ((0x00400000&(data))>>22)
#define  TP_TP_OUT_CTRL_get_get_size(data)                                       ((0x00300000&(data))>>20)
#define  TP_TP_OUT_CTRL_get_sync_dur(data)                                       ((0x00080000&(data))>>19)
#define  TP_TP_OUT_CTRL_get_ck_gate(data)                                        ((0x00040000&(data))>>18)
#define  TP_TP_OUT_CTRL_get_tp_frame_rate(data)                                  ((0x0003FFE0&(data))>>5)
#define  TP_TP_OUT_CTRL_get_data_sel(data)                                       ((0x00000010&(data))>>4)

#define  TP_TP_OUT_INT                                                           0x18014098
#define  TP_TP_OUT_INT_reg_addr                                                  "0xB8014098"
#define  TP_TP_OUT_INT_reg                                                       0xB8014098
#define  TP_TP_OUT_INT_inst_addr                                                 "0x0032"
#define  set_TP_TP_OUT_INT_reg(data)                                             (*((volatile unsigned int*)TP_TP_OUT_INT_reg)=data)
#define  get_TP_TP_OUT_INT_reg                                                   (*((volatile unsigned int*)TP_TP_OUT_INT_reg))
#define  TP_TP_OUT_INT_pause_int_shift                                           (2)
#define  TP_TP_OUT_INT_pause_int_en_shift                                        (1)
#define  TP_TP_OUT_INT_write_data_shift                                          (0)
#define  TP_TP_OUT_INT_pause_int_mask                                            (0x00000004)
#define  TP_TP_OUT_INT_pause_int_en_mask                                         (0x00000002)
#define  TP_TP_OUT_INT_write_data_mask                                           (0x00000001)
#define  TP_TP_OUT_INT_pause_int(data)                                           (0x00000004&((data)<<2))
#define  TP_TP_OUT_INT_pause_int_en(data)                                        (0x00000002&((data)<<1))
#define  TP_TP_OUT_INT_write_data(data)                                          (0x00000001&(data))
#define  TP_TP_OUT_INT_get_pause_int(data)                                       ((0x00000004&(data))>>2)
#define  TP_TP_OUT_INT_get_pause_int_en(data)                                    ((0x00000002&(data))>>1)
#define  TP_TP_OUT_INT_get_write_data(data)                                      (0x00000001&(data))

#define  TP_TP_OUT_SHARE                                                         0x18014354
#define  TP_TP_OUT_SHARE_reg_addr                                                "0xB8014354"
#define  TP_TP_OUT_SHARE_reg                                                     0xB8014354
#define  TP_TP_OUT_SHARE_inst_addr                                               "0x0033"
#define  set_TP_TP_OUT_SHARE_reg(data)                                           (*((volatile unsigned int*)TP_TP_OUT_SHARE_reg)=data)
#define  get_TP_TP_OUT_SHARE_reg                                                 (*((volatile unsigned int*)TP_TP_OUT_SHARE_reg))
#define  TP_TP_OUT_SHARE_buf_th_shift                                            (0)
#define  TP_TP_OUT_SHARE_buf_th_mask                                             (0xFFFFFFFF)
#define  TP_TP_OUT_SHARE_buf_th(data)                                            (0xFFFFFFFF&(data))
#define  TP_TP_OUT_SHARE_get_buf_th(data)                                        (0xFFFFFFFF&(data))

#define  TP_TP_OUT_SHARE_1                                                       0x18014358
#define  TP_TP_OUT_SHARE_1_reg_addr                                              "0xB8014358"
#define  TP_TP_OUT_SHARE_1_reg                                                   0xB8014358
#define  TP_TP_OUT_SHARE_1_inst_addr                                             "0x0034"
#define  set_TP_TP_OUT_SHARE_1_reg(data)                                         (*((volatile unsigned int*)TP_TP_OUT_SHARE_1_reg)=data)
#define  get_TP_TP_OUT_SHARE_1_reg                                               (*((volatile unsigned int*)TP_TP_OUT_SHARE_1_reg))
#define  TP_TP_OUT_SHARE_1_buf_space_shift                                       (0)
#define  TP_TP_OUT_SHARE_1_buf_space_mask                                        (0xFFFFFFFF)
#define  TP_TP_OUT_SHARE_1_buf_space(data)                                       (0xFFFFFFFF&(data))
#define  TP_TP_OUT_SHARE_1_get_buf_space(data)                                   (0xFFFFFFFF&(data))

#define  TP_TP_OUT_SHARE_2                                                       0x1801435C
#define  TP_TP_OUT_SHARE_2_reg_addr                                              "0xB801435C"
#define  TP_TP_OUT_SHARE_2_reg                                                   0xB801435C
#define  TP_TP_OUT_SHARE_2_inst_addr                                             "0x0035"
#define  set_TP_TP_OUT_SHARE_2_reg(data)                                         (*((volatile unsigned int*)TP_TP_OUT_SHARE_2_reg)=data)
#define  get_TP_TP_OUT_SHARE_2_reg                                               (*((volatile unsigned int*)TP_TP_OUT_SHARE_2_reg))
#define  TP_TP_OUT_SHARE_2_time_out_shift                                        (0)
#define  TP_TP_OUT_SHARE_2_time_out_mask                                         (0xFFFFFFFF)
#define  TP_TP_OUT_SHARE_2_time_out(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP_OUT_SHARE_2_get_time_out(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP_IN_POL                                                            0x18014360
#define  TP_TP_IN_POL_reg_addr                                                   "0xB8014360"
#define  TP_TP_IN_POL_reg                                                        0xB8014360
#define  TP_TP_IN_POL_inst_addr                                                  "0x0036"
#define  set_TP_TP_IN_POL_reg(data)                                              (*((volatile unsigned int*)TP_TP_IN_POL_reg)=data)
#define  get_TP_TP_IN_POL_reg                                                    (*((volatile unsigned int*)TP_TP_IN_POL_reg))
#define  TP_TP_IN_POL_tpi_demod_val_pol_shift                                    (14)
#define  TP_TP_IN_POL_tpi_demod_sync_pol_shift                                   (13)
#define  TP_TP_IN_POL_tpi_demod_clk_pol_shift                                    (12)
#define  TP_TP_IN_POL_tpi_2_val_pol_shift                                        (10)
#define  TP_TP_IN_POL_tpi_2_sync_pol_shift                                       (9)
#define  TP_TP_IN_POL_tpi_2_clk_pol_shift                                        (8)
#define  TP_TP_IN_POL_tpi_1_val_pol_shift                                        (6)
#define  TP_TP_IN_POL_tpi_1_sync_pol_shift                                       (5)
#define  TP_TP_IN_POL_tpi_1_clk_pol_shift                                        (4)
#define  TP_TP_IN_POL_tpi_0_val_pol_shift                                        (2)
#define  TP_TP_IN_POL_tpi_0_sync_pol_shift                                       (1)
#define  TP_TP_IN_POL_tpi_0_clk_pol_shift                                        (0)
#define  TP_TP_IN_POL_tpi_demod_val_pol_mask                                     (0x00004000)
#define  TP_TP_IN_POL_tpi_demod_sync_pol_mask                                    (0x00002000)
#define  TP_TP_IN_POL_tpi_demod_clk_pol_mask                                     (0x00001000)
#define  TP_TP_IN_POL_tpi_2_val_pol_mask                                         (0x00000400)
#define  TP_TP_IN_POL_tpi_2_sync_pol_mask                                        (0x00000200)
#define  TP_TP_IN_POL_tpi_2_clk_pol_mask                                         (0x00000100)
#define  TP_TP_IN_POL_tpi_1_val_pol_mask                                         (0x00000040)
#define  TP_TP_IN_POL_tpi_1_sync_pol_mask                                        (0x00000020)
#define  TP_TP_IN_POL_tpi_1_clk_pol_mask                                         (0x00000010)
#define  TP_TP_IN_POL_tpi_0_val_pol_mask                                         (0x00000004)
#define  TP_TP_IN_POL_tpi_0_sync_pol_mask                                        (0x00000002)
#define  TP_TP_IN_POL_tpi_0_clk_pol_mask                                         (0x00000001)
#define  TP_TP_IN_POL_tpi_demod_val_pol(data)                                    (0x00004000&((data)<<14))
#define  TP_TP_IN_POL_tpi_demod_sync_pol(data)                                   (0x00002000&((data)<<13))
#define  TP_TP_IN_POL_tpi_demod_clk_pol(data)                                    (0x00001000&((data)<<12))
#define  TP_TP_IN_POL_tpi_2_val_pol(data)                                        (0x00000400&((data)<<10))
#define  TP_TP_IN_POL_tpi_2_sync_pol(data)                                       (0x00000200&((data)<<9))
#define  TP_TP_IN_POL_tpi_2_clk_pol(data)                                        (0x00000100&((data)<<8))
#define  TP_TP_IN_POL_tpi_1_val_pol(data)                                        (0x00000040&((data)<<6))
#define  TP_TP_IN_POL_tpi_1_sync_pol(data)                                       (0x00000020&((data)<<5))
#define  TP_TP_IN_POL_tpi_1_clk_pol(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_IN_POL_tpi_0_val_pol(data)                                        (0x00000004&((data)<<2))
#define  TP_TP_IN_POL_tpi_0_sync_pol(data)                                       (0x00000002&((data)<<1))
#define  TP_TP_IN_POL_tpi_0_clk_pol(data)                                        (0x00000001&(data))
#define  TP_TP_IN_POL_get_tpi_demod_val_pol(data)                                ((0x00004000&(data))>>14)
#define  TP_TP_IN_POL_get_tpi_demod_sync_pol(data)                               ((0x00002000&(data))>>13)
#define  TP_TP_IN_POL_get_tpi_demod_clk_pol(data)                                ((0x00001000&(data))>>12)
#define  TP_TP_IN_POL_get_tpi_2_val_pol(data)                                    ((0x00000400&(data))>>10)
#define  TP_TP_IN_POL_get_tpi_2_sync_pol(data)                                   ((0x00000200&(data))>>9)
#define  TP_TP_IN_POL_get_tpi_2_clk_pol(data)                                    ((0x00000100&(data))>>8)
#define  TP_TP_IN_POL_get_tpi_1_val_pol(data)                                    ((0x00000040&(data))>>6)
#define  TP_TP_IN_POL_get_tpi_1_sync_pol(data)                                   ((0x00000020&(data))>>5)
#define  TP_TP_IN_POL_get_tpi_1_clk_pol(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP_IN_POL_get_tpi_0_val_pol(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP_IN_POL_get_tpi_0_sync_pol(data)                                   ((0x00000002&(data))>>1)
#define  TP_TP_IN_POL_get_tpi_0_clk_pol(data)                                    (0x00000001&(data))

#define  TP_TP0_PCR_CTL                                                          0x180140AC
#define  TP_TP0_PCR_CTL_reg_addr                                                 "0xB80140AC"
#define  TP_TP0_PCR_CTL_reg                                                      0xB80140AC
#define  TP_TP0_PCR_CTL_inst_addr                                                "0x0037"
#define  set_TP_TP0_PCR_CTL_reg(data)                                            (*((volatile unsigned int*)TP_TP0_PCR_CTL_reg)=data)
#define  get_TP_TP0_PCR_CTL_reg                                                  (*((volatile unsigned int*)TP_TP0_PCR_CTL_reg))
#define  TP_TP0_PCR_CTL_pcr_stc_align_shift                                      (13)
#define  TP_TP0_PCR_CTL_pcr_st_shift                                             (12)
#define  TP_TP0_PCR_CTL_stc_sel_shift                                            (10)
#define  TP_TP0_PCR_CTL_local_pcr_sel_shift                                      (9)
#define  TP_TP0_PCR_CTL_extra_func_ena_shift                                     (8)
#define  TP_TP0_PCR_CTL_pcra_src_sel_shift                                       (7)
#define  TP_TP0_PCR_CTL_extra_pid_addr_shift                                     (0)
#define  TP_TP0_PCR_CTL_pcr_stc_align_mask                                       (0x00002000)
#define  TP_TP0_PCR_CTL_pcr_st_mask                                              (0x00001000)
#define  TP_TP0_PCR_CTL_stc_sel_mask                                             (0x00000C00)
#define  TP_TP0_PCR_CTL_local_pcr_sel_mask                                       (0x00000200)
#define  TP_TP0_PCR_CTL_extra_func_ena_mask                                      (0x00000100)
#define  TP_TP0_PCR_CTL_pcra_src_sel_mask                                        (0x00000080)
#define  TP_TP0_PCR_CTL_extra_pid_addr_mask                                      (0x0000007F)
#define  TP_TP0_PCR_CTL_pcr_stc_align(data)                                      (0x00002000&((data)<<13))
#define  TP_TP0_PCR_CTL_pcr_st(data)                                             (0x00001000&((data)<<12))
#define  TP_TP0_PCR_CTL_stc_sel(data)                                            (0x00000C00&((data)<<10))
#define  TP_TP0_PCR_CTL_local_pcr_sel(data)                                      (0x00000200&((data)<<9))
#define  TP_TP0_PCR_CTL_extra_func_ena(data)                                     (0x00000100&((data)<<8))
#define  TP_TP0_PCR_CTL_pcra_src_sel(data)                                       (0x00000080&((data)<<7))
#define  TP_TP0_PCR_CTL_extra_pid_addr(data)                                     (0x0000007F&(data))
#define  TP_TP0_PCR_CTL_get_pcr_stc_align(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP0_PCR_CTL_get_pcr_st(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP0_PCR_CTL_get_stc_sel(data)                                        ((0x00000C00&(data))>>10)
#define  TP_TP0_PCR_CTL_get_local_pcr_sel(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP0_PCR_CTL_get_extra_func_ena(data)                                 ((0x00000100&(data))>>8)
#define  TP_TP0_PCR_CTL_get_pcra_src_sel(data)                                   ((0x00000080&(data))>>7)
#define  TP_TP0_PCR_CTL_get_extra_pid_addr(data)                                 (0x0000007F&(data))

#define  TP_TP1_PCR_CTL                                                          0x180140B0
#define  TP_TP1_PCR_CTL_reg_addr                                                 "0xB80140B0"
#define  TP_TP1_PCR_CTL_reg                                                      0xB80140B0
#define  TP_TP1_PCR_CTL_inst_addr                                                "0x0038"
#define  set_TP_TP1_PCR_CTL_reg(data)                                            (*((volatile unsigned int*)TP_TP1_PCR_CTL_reg)=data)
#define  get_TP_TP1_PCR_CTL_reg                                                  (*((volatile unsigned int*)TP_TP1_PCR_CTL_reg))
#define  TP_TP1_PCR_CTL_pcr_stc_align_shift                                      (13)
#define  TP_TP1_PCR_CTL_pcr_st_shift                                             (12)
#define  TP_TP1_PCR_CTL_stc_sel_shift                                            (10)
#define  TP_TP1_PCR_CTL_local_pcr_sel_shift                                      (9)
#define  TP_TP1_PCR_CTL_extra_func_ena_shift                                     (8)
#define  TP_TP1_PCR_CTL_extra_pid_addr_shift                                     (0)
#define  TP_TP1_PCR_CTL_pcr_stc_align_mask                                       (0x00002000)
#define  TP_TP1_PCR_CTL_pcr_st_mask                                              (0x00001000)
#define  TP_TP1_PCR_CTL_stc_sel_mask                                             (0x00000C00)
#define  TP_TP1_PCR_CTL_local_pcr_sel_mask                                       (0x00000200)
#define  TP_TP1_PCR_CTL_extra_func_ena_mask                                      (0x00000100)
#define  TP_TP1_PCR_CTL_extra_pid_addr_mask                                      (0x0000007F)
#define  TP_TP1_PCR_CTL_pcr_stc_align(data)                                      (0x00002000&((data)<<13))
#define  TP_TP1_PCR_CTL_pcr_st(data)                                             (0x00001000&((data)<<12))
#define  TP_TP1_PCR_CTL_stc_sel(data)                                            (0x00000C00&((data)<<10))
#define  TP_TP1_PCR_CTL_local_pcr_sel(data)                                      (0x00000200&((data)<<9))
#define  TP_TP1_PCR_CTL_extra_func_ena(data)                                     (0x00000100&((data)<<8))
#define  TP_TP1_PCR_CTL_extra_pid_addr(data)                                     (0x0000007F&(data))
#define  TP_TP1_PCR_CTL_get_pcr_stc_align(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP1_PCR_CTL_get_pcr_st(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP1_PCR_CTL_get_stc_sel(data)                                        ((0x00000C00&(data))>>10)
#define  TP_TP1_PCR_CTL_get_local_pcr_sel(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP1_PCR_CTL_get_extra_func_ena(data)                                 ((0x00000100&(data))>>8)
#define  TP_TP1_PCR_CTL_get_extra_pid_addr(data)                                 (0x0000007F&(data))

#define  TP_TP2_PCR_CTL                                                          0x180140B4
#define  TP_TP2_PCR_CTL_reg_addr                                                 "0xB80140B4"
#define  TP_TP2_PCR_CTL_reg                                                      0xB80140B4
#define  TP_TP2_PCR_CTL_inst_addr                                                "0x0039"
#define  set_TP_TP2_PCR_CTL_reg(data)                                            (*((volatile unsigned int*)TP_TP2_PCR_CTL_reg)=data)
#define  get_TP_TP2_PCR_CTL_reg                                                  (*((volatile unsigned int*)TP_TP2_PCR_CTL_reg))
#define  TP_TP2_PCR_CTL_pcr_stc_align_shift                                      (13)
#define  TP_TP2_PCR_CTL_pcr_st_shift                                             (12)
#define  TP_TP2_PCR_CTL_stc_sel_shift                                            (10)
#define  TP_TP2_PCR_CTL_local_pcr_sel_shift                                      (9)
#define  TP_TP2_PCR_CTL_extra_func_ena_shift                                     (8)
#define  TP_TP2_PCR_CTL_extra_pid_addr_shift                                     (0)
#define  TP_TP2_PCR_CTL_pcr_stc_align_mask                                       (0x00002000)
#define  TP_TP2_PCR_CTL_pcr_st_mask                                              (0x00001000)
#define  TP_TP2_PCR_CTL_stc_sel_mask                                             (0x00000C00)
#define  TP_TP2_PCR_CTL_local_pcr_sel_mask                                       (0x00000200)
#define  TP_TP2_PCR_CTL_extra_func_ena_mask                                      (0x00000100)
#define  TP_TP2_PCR_CTL_extra_pid_addr_mask                                      (0x0000007F)
#define  TP_TP2_PCR_CTL_pcr_stc_align(data)                                      (0x00002000&((data)<<13))
#define  TP_TP2_PCR_CTL_pcr_st(data)                                             (0x00001000&((data)<<12))
#define  TP_TP2_PCR_CTL_stc_sel(data)                                            (0x00000C00&((data)<<10))
#define  TP_TP2_PCR_CTL_local_pcr_sel(data)                                      (0x00000200&((data)<<9))
#define  TP_TP2_PCR_CTL_extra_func_ena(data)                                     (0x00000100&((data)<<8))
#define  TP_TP2_PCR_CTL_extra_pid_addr(data)                                     (0x0000007F&(data))
#define  TP_TP2_PCR_CTL_get_pcr_stc_align(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP2_PCR_CTL_get_pcr_st(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP2_PCR_CTL_get_stc_sel(data)                                        ((0x00000C00&(data))>>10)
#define  TP_TP2_PCR_CTL_get_local_pcr_sel(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP2_PCR_CTL_get_extra_func_ena(data)                                 ((0x00000100&(data))>>8)
#define  TP_TP2_PCR_CTL_get_extra_pid_addr(data)                                 (0x0000007F&(data))

#define  TP_TP3_PCR_CTL                                                          0x18014350
#define  TP_TP3_PCR_CTL_reg_addr                                                 "0xB8014350"
#define  TP_TP3_PCR_CTL_reg                                                      0xB8014350
#define  TP_TP3_PCR_CTL_inst_addr                                                "0x003A"
#define  set_TP_TP3_PCR_CTL_reg(data)                                            (*((volatile unsigned int*)TP_TP3_PCR_CTL_reg)=data)
#define  get_TP_TP3_PCR_CTL_reg                                                  (*((volatile unsigned int*)TP_TP3_PCR_CTL_reg))
#define  TP_TP3_PCR_CTL_pcr_stc_align_shift                                      (13)
#define  TP_TP3_PCR_CTL_pcr_st_shift                                             (12)
#define  TP_TP3_PCR_CTL_stc_sel_shift                                            (10)
#define  TP_TP3_PCR_CTL_local_pcr_sel_shift                                      (9)
#define  TP_TP3_PCR_CTL_extra_func_ena_shift                                     (8)
#define  TP_TP3_PCR_CTL_extra_pid_addr_shift                                     (0)
#define  TP_TP3_PCR_CTL_pcr_stc_align_mask                                       (0x00002000)
#define  TP_TP3_PCR_CTL_pcr_st_mask                                              (0x00001000)
#define  TP_TP3_PCR_CTL_stc_sel_mask                                             (0x00000C00)
#define  TP_TP3_PCR_CTL_local_pcr_sel_mask                                       (0x00000200)
#define  TP_TP3_PCR_CTL_extra_func_ena_mask                                      (0x00000100)
#define  TP_TP3_PCR_CTL_extra_pid_addr_mask                                      (0x0000007F)
#define  TP_TP3_PCR_CTL_pcr_stc_align(data)                                      (0x00002000&((data)<<13))
#define  TP_TP3_PCR_CTL_pcr_st(data)                                             (0x00001000&((data)<<12))
#define  TP_TP3_PCR_CTL_stc_sel(data)                                            (0x00000C00&((data)<<10))
#define  TP_TP3_PCR_CTL_local_pcr_sel(data)                                      (0x00000200&((data)<<9))
#define  TP_TP3_PCR_CTL_extra_func_ena(data)                                     (0x00000100&((data)<<8))
#define  TP_TP3_PCR_CTL_extra_pid_addr(data)                                     (0x0000007F&(data))
#define  TP_TP3_PCR_CTL_get_pcr_stc_align(data)                                  ((0x00002000&(data))>>13)
#define  TP_TP3_PCR_CTL_get_pcr_st(data)                                         ((0x00001000&(data))>>12)
#define  TP_TP3_PCR_CTL_get_stc_sel(data)                                        ((0x00000C00&(data))>>10)
#define  TP_TP3_PCR_CTL_get_local_pcr_sel(data)                                  ((0x00000200&(data))>>9)
#define  TP_TP3_PCR_CTL_get_extra_func_ena(data)                                 ((0x00000100&(data))>>8)
#define  TP_TP3_PCR_CTL_get_extra_pid_addr(data)                                 (0x0000007F&(data))

#define  TP_TP_PCR_LATCH                                                         0x180140B8
#define  TP_TP_PCR_LATCH_reg_addr                                                "0xB80140B8"
#define  TP_TP_PCR_LATCH_reg                                                     0xB80140B8
#define  TP_TP_PCR_LATCH_inst_addr                                               "0x003B"
#define  set_TP_TP_PCR_LATCH_reg(data)                                           (*((volatile unsigned int*)TP_TP_PCR_LATCH_reg)=data)
#define  get_TP_TP_PCR_LATCH_reg                                                 (*((volatile unsigned int*)TP_TP_PCR_LATCH_reg))
#define  TP_TP_PCR_LATCH_latch_ena_shift                                         (8)
#define  TP_TP_PCR_LATCH_latch_sel_shift                                         (0)
#define  TP_TP_PCR_LATCH_latch_ena_mask                                          (0x00000100)
#define  TP_TP_PCR_LATCH_latch_sel_mask                                          (0x00000003)
#define  TP_TP_PCR_LATCH_latch_ena(data)                                         (0x00000100&((data)<<8))
#define  TP_TP_PCR_LATCH_latch_sel(data)                                         (0x00000003&(data))
#define  TP_TP_PCR_LATCH_get_latch_ena(data)                                     ((0x00000100&(data))>>8)
#define  TP_TP_PCR_LATCH_get_latch_sel(data)                                     (0x00000003&(data))

#define  TP_TP_PCR_BASE                                                          0x180140BC
#define  TP_TP_PCR_BASE_reg_addr                                                 "0xB80140BC"
#define  TP_TP_PCR_BASE_reg                                                      0xB80140BC
#define  TP_TP_PCR_BASE_inst_addr                                                "0x003C"
#define  set_TP_TP_PCR_BASE_reg(data)                                            (*((volatile unsigned int*)TP_TP_PCR_BASE_reg)=data)
#define  get_TP_TP_PCR_BASE_reg                                                  (*((volatile unsigned int*)TP_TP_PCR_BASE_reg))
#define  TP_TP_PCR_BASE_pcr_base_lo_shift                                        (0)
#define  TP_TP_PCR_BASE_pcr_base_lo_mask                                         (0xFFFFFFFF)
#define  TP_TP_PCR_BASE_pcr_base_lo(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP_PCR_BASE_get_pcr_base_lo(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP_PCR_EXT                                                           0x180140C0
#define  TP_TP_PCR_EXT_reg_addr                                                  "0xB80140C0"
#define  TP_TP_PCR_EXT_reg                                                       0xB80140C0
#define  TP_TP_PCR_EXT_inst_addr                                                 "0x003D"
#define  set_TP_TP_PCR_EXT_reg(data)                                             (*((volatile unsigned int*)TP_TP_PCR_EXT_reg)=data)
#define  get_TP_TP_PCR_EXT_reg                                                   (*((volatile unsigned int*)TP_TP_PCR_EXT_reg))
#define  TP_TP_PCR_EXT_pcr_base_hi_shift                                         (16)
#define  TP_TP_PCR_EXT_pcr_ext_shift                                             (0)
#define  TP_TP_PCR_EXT_pcr_base_hi_mask                                          (0x00010000)
#define  TP_TP_PCR_EXT_pcr_ext_mask                                              (0x000001FF)
#define  TP_TP_PCR_EXT_pcr_base_hi(data)                                         (0x00010000&((data)<<16))
#define  TP_TP_PCR_EXT_pcr_ext(data)                                             (0x000001FF&(data))
#define  TP_TP_PCR_EXT_get_pcr_base_hi(data)                                     ((0x00010000&(data))>>16)
#define  TP_TP_PCR_EXT_get_pcr_ext(data)                                         (0x000001FF&(data))

#define  TP_TP_PCR_SYSTEM_0                                                      0x180140C4
#define  TP_TP_PCR_SYSTEM_0_reg_addr                                             "0xB80140C4"
#define  TP_TP_PCR_SYSTEM_0_reg                                                  0xB80140C4
#define  TP_TP_PCR_SYSTEM_0_inst_addr                                            "0x003E"
#define  set_TP_TP_PCR_SYSTEM_0_reg(data)                                        (*((volatile unsigned int*)TP_TP_PCR_SYSTEM_0_reg)=data)
#define  get_TP_TP_PCR_SYSTEM_0_reg                                              (*((volatile unsigned int*)TP_TP_PCR_SYSTEM_0_reg))
#define  TP_TP_PCR_SYSTEM_0_system_ts_shift                                      (0)
#define  TP_TP_PCR_SYSTEM_0_system_ts_mask                                       (0xFFFFFFFF)
#define  TP_TP_PCR_SYSTEM_0_system_ts(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP_PCR_SYSTEM_0_get_system_ts(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP_PCR_SYSTEM_1                                                      0x180140C8
#define  TP_TP_PCR_SYSTEM_1_reg_addr                                             "0xB80140C8"
#define  TP_TP_PCR_SYSTEM_1_reg                                                  0xB80140C8
#define  TP_TP_PCR_SYSTEM_1_inst_addr                                            "0x003F"
#define  set_TP_TP_PCR_SYSTEM_1_reg(data)                                        (*((volatile unsigned int*)TP_TP_PCR_SYSTEM_1_reg)=data)
#define  get_TP_TP_PCR_SYSTEM_1_reg                                              (*((volatile unsigned int*)TP_TP_PCR_SYSTEM_1_reg))
#define  TP_TP_PCR_SYSTEM_1_system_ts_shift                                      (0)
#define  TP_TP_PCR_SYSTEM_1_system_ts_mask                                       (0xFFFFFFFF)
#define  TP_TP_PCR_SYSTEM_1_system_ts(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP_PCR_SYSTEM_1_get_system_ts(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP_SYNC_RPLACE                                                       0x180140CC
#define  TP_TP_SYNC_RPLACE_reg_addr                                              "0xB80140CC"
#define  TP_TP_SYNC_RPLACE_reg                                                   0xB80140CC
#define  TP_TP_SYNC_RPLACE_inst_addr                                             "0x0040"
#define  set_TP_TP_SYNC_RPLACE_reg(data)                                         (*((volatile unsigned int*)TP_TP_SYNC_RPLACE_reg)=data)
#define  get_TP_TP_SYNC_RPLACE_reg                                               (*((volatile unsigned int*)TP_TP_SYNC_RPLACE_reg))
#define  TP_TP_SYNC_RPLACE_tp3_shift                                             (24)
#define  TP_TP_SYNC_RPLACE_tp2_shift                                             (16)
#define  TP_TP_SYNC_RPLACE_tp1_shift                                             (8)
#define  TP_TP_SYNC_RPLACE_tp0_shift                                             (0)
#define  TP_TP_SYNC_RPLACE_tp3_mask                                              (0xFF000000)
#define  TP_TP_SYNC_RPLACE_tp2_mask                                              (0x00FF0000)
#define  TP_TP_SYNC_RPLACE_tp1_mask                                              (0x0000FF00)
#define  TP_TP_SYNC_RPLACE_tp0_mask                                              (0x000000FF)
#define  TP_TP_SYNC_RPLACE_tp3(data)                                             (0xFF000000&((data)<<24))
#define  TP_TP_SYNC_RPLACE_tp2(data)                                             (0x00FF0000&((data)<<16))
#define  TP_TP_SYNC_RPLACE_tp1(data)                                             (0x0000FF00&((data)<<8))
#define  TP_TP_SYNC_RPLACE_tp0(data)                                             (0x000000FF&(data))
#define  TP_TP_SYNC_RPLACE_get_tp3(data)                                         ((0xFF000000&(data))>>24)
#define  TP_TP_SYNC_RPLACE_get_tp2(data)                                         ((0x00FF0000&(data))>>16)
#define  TP_TP_SYNC_RPLACE_get_tp1(data)                                         ((0x0000FF00&(data))>>8)
#define  TP_TP_SYNC_RPLACE_get_tp0(data)                                         (0x000000FF&(data))

#define  TP_TP_PID_PART                                                          0x180140D0
#define  TP_TP_PID_PART_reg_addr                                                 "0xB80140D0"
#define  TP_TP_PID_PART_reg                                                      0xB80140D0
#define  TP_TP_PID_PART_inst_addr                                                "0x0041"
#define  set_TP_TP_PID_PART_reg(data)                                            (*((volatile unsigned int*)TP_TP_PID_PART_reg)=data)
#define  get_TP_TP_PID_PART_reg                                                  (*((volatile unsigned int*)TP_TP_PID_PART_reg))
#define  TP_TP_PID_PART_partition1_shift                                         (16)
#define  TP_TP_PID_PART_partition2_shift                                         (8)
#define  TP_TP_PID_PART_partition3_shift                                         (0)
#define  TP_TP_PID_PART_partition1_mask                                          (0x00FF0000)
#define  TP_TP_PID_PART_partition2_mask                                          (0x0000FF00)
#define  TP_TP_PID_PART_partition3_mask                                          (0x000000FF)
#define  TP_TP_PID_PART_partition1(data)                                         (0x00FF0000&((data)<<16))
#define  TP_TP_PID_PART_partition2(data)                                         (0x0000FF00&((data)<<8))
#define  TP_TP_PID_PART_partition3(data)                                         (0x000000FF&(data))
#define  TP_TP_PID_PART_get_partition1(data)                                     ((0x00FF0000&(data))>>16)
#define  TP_TP_PID_PART_get_partition2(data)                                     ((0x0000FF00&(data))>>8)
#define  TP_TP_PID_PART_get_partition3(data)                                     (0x000000FF&(data))

#define  TP_TP_PID_CTRL                                                          0x180140D4
#define  TP_TP_PID_CTRL_reg_addr                                                 "0xB80140D4"
#define  TP_TP_PID_CTRL_reg                                                      0xB80140D4
#define  TP_TP_PID_CTRL_inst_addr                                                "0x0042"
#define  set_TP_TP_PID_CTRL_reg(data)                                            (*((volatile unsigned int*)TP_TP_PID_CTRL_reg)=data)
#define  get_TP_TP_PID_CTRL_reg                                                  (*((volatile unsigned int*)TP_TP_PID_CTRL_reg))
#define  TP_TP_PID_CTRL_r_w_shift                                                (7)
#define  TP_TP_PID_CTRL_idx_shift                                                (0)
#define  TP_TP_PID_CTRL_r_w_mask                                                 (0x00000080)
#define  TP_TP_PID_CTRL_idx_mask                                                 (0x0000007F)
#define  TP_TP_PID_CTRL_r_w(data)                                                (0x00000080&((data)<<7))
#define  TP_TP_PID_CTRL_idx(data)                                                (0x0000007F&(data))
#define  TP_TP_PID_CTRL_get_r_w(data)                                            ((0x00000080&(data))>>7)
#define  TP_TP_PID_CTRL_get_idx(data)                                            (0x0000007F&(data))

#define  TP_TP_PID_DATA                                                          0x180140D8
#define  TP_TP_PID_DATA_reg_addr                                                 "0xB80140D8"
#define  TP_TP_PID_DATA_reg                                                      0xB80140D8
#define  TP_TP_PID_DATA_inst_addr                                                "0x0043"
#define  set_TP_TP_PID_DATA_reg(data)                                            (*((volatile unsigned int*)TP_TP_PID_DATA_reg)=data)
#define  get_TP_TP_PID_DATA_reg                                                  (*((volatile unsigned int*)TP_TP_PID_DATA_reg))
#define  TP_TP_PID_DATA_si_en_shift                                              (31)
#define  TP_TP_PID_DATA_pid_ini_shift                                            (30)
#define  TP_TP_PID_DATA_ai_en_shift                                              (29)
#define  TP_TP_PID_DATA_ti_en_shift                                              (28)
#define  TP_TP_PID_DATA_sec_idx_shift                                            (20)
#define  TP_TP_PID_DATA_sec_en_shift                                             (19)
#define  TP_TP_PID_DATA_ddr_q_shift                                              (14)
#define  TP_TP_PID_DATA_v_shift                                                  (13)
#define  TP_TP_PID_DATA_pid_shift                                                (0)
#define  TP_TP_PID_DATA_si_en_mask                                               (0x80000000)
#define  TP_TP_PID_DATA_pid_ini_mask                                             (0x40000000)
#define  TP_TP_PID_DATA_ai_en_mask                                               (0x20000000)
#define  TP_TP_PID_DATA_ti_en_mask                                               (0x10000000)
#define  TP_TP_PID_DATA_sec_idx_mask                                             (0x0FF00000)
#define  TP_TP_PID_DATA_sec_en_mask                                              (0x00080000)
#define  TP_TP_PID_DATA_ddr_q_mask                                               (0x0007C000)
#define  TP_TP_PID_DATA_v_mask                                                   (0x00002000)
#define  TP_TP_PID_DATA_pid_mask                                                 (0x00001FFF)
#define  TP_TP_PID_DATA_si_en(data)                                              (0x80000000&((data)<<31))
#define  TP_TP_PID_DATA_pid_ini(data)                                            (0x40000000&((data)<<30))
#define  TP_TP_PID_DATA_ai_en(data)                                              (0x20000000&((data)<<29))
#define  TP_TP_PID_DATA_ti_en(data)                                              (0x10000000&((data)<<28))
#define  TP_TP_PID_DATA_sec_idx(data)                                            (0x0FF00000&((data)<<20))
#define  TP_TP_PID_DATA_sec_en(data)                                             (0x00080000&((data)<<19))
#define  TP_TP_PID_DATA_ddr_q(data)                                              (0x0007C000&((data)<<14))
#define  TP_TP_PID_DATA_v(data)                                                  (0x00002000&((data)<<13))
#define  TP_TP_PID_DATA_pid(data)                                                (0x00001FFF&(data))
#define  TP_TP_PID_DATA_get_si_en(data)                                          ((0x80000000&(data))>>31)
#define  TP_TP_PID_DATA_get_pid_ini(data)                                        ((0x40000000&(data))>>30)
#define  TP_TP_PID_DATA_get_ai_en(data)                                          ((0x20000000&(data))>>29)
#define  TP_TP_PID_DATA_get_ti_en(data)                                          ((0x10000000&(data))>>28)
#define  TP_TP_PID_DATA_get_sec_idx(data)                                        ((0x0FF00000&(data))>>20)
#define  TP_TP_PID_DATA_get_sec_en(data)                                         ((0x00080000&(data))>>19)
#define  TP_TP_PID_DATA_get_ddr_q(data)                                          ((0x0007C000&(data))>>14)
#define  TP_TP_PID_DATA_get_v(data)                                              ((0x00002000&(data))>>13)
#define  TP_TP_PID_DATA_get_pid(data)                                            (0x00001FFF&(data))

#define  TP_TP_PID_DATA2                                                         0x180140DC
#define  TP_TP_PID_DATA2_reg_addr                                                "0xB80140DC"
#define  TP_TP_PID_DATA2_reg                                                     0xB80140DC
#define  TP_TP_PID_DATA2_inst_addr                                               "0x0044"
#define  set_TP_TP_PID_DATA2_reg(data)                                           (*((volatile unsigned int*)TP_TP_PID_DATA2_reg)=data)
#define  get_TP_TP_PID_DATA2_reg                                                 (*((volatile unsigned int*)TP_TP_PID_DATA2_reg))
#define  TP_TP_PID_DATA2_des_sel_shift                                           (29)
#define  TP_TP_PID_DATA2_aes_mode_shift                                          (27)
#define  TP_TP_PID_DATA2_tdes_mode_shift                                         (26)
#define  TP_TP_PID_DATA2_encrypt_tsc_en_shift                                    (25)
#define  TP_TP_PID_DATA2_encryption_key_shift                                    (24)
#define  TP_TP_PID_DATA2_keyindex_shift                                          (18)
#define  TP_TP_PID_DATA2_local_des_en_shift                                      (17)
#define  TP_TP_PID_DATA2_descramble_sel_shift                                    (16)
#define  TP_TP_PID_DATA2_pid_des_disable_shift                                   (15)
#define  TP_TP_PID_DATA2_encryption_en_shift                                     (14)
#define  TP_TP_PID_DATA2_info_q_en_shift                                         (13)
#define  TP_TP_PID_DATA2_pre_des_shift                                           (12)
#define  TP_TP_PID_DATA2_key_shift                                               (7)
#define  TP_TP_PID_DATA2_cc_en_shift                                             (6)
#define  TP_TP_PID_DATA2_ddr_q_en_shift                                          (5)
#define  TP_TP_PID_DATA2_info_q_shift                                            (0)
#define  TP_TP_PID_DATA2_des_sel_mask                                            (0xE0000000)
#define  TP_TP_PID_DATA2_aes_mode_mask                                           (0x18000000)
#define  TP_TP_PID_DATA2_tdes_mode_mask                                          (0x04000000)
#define  TP_TP_PID_DATA2_encrypt_tsc_en_mask                                     (0x02000000)
#define  TP_TP_PID_DATA2_encryption_key_mask                                     (0x01000000)
#define  TP_TP_PID_DATA2_keyindex_mask                                           (0x00FC0000)
#define  TP_TP_PID_DATA2_local_des_en_mask                                       (0x00020000)
#define  TP_TP_PID_DATA2_descramble_sel_mask                                     (0x00010000)
#define  TP_TP_PID_DATA2_pid_des_disable_mask                                    (0x00008000)
#define  TP_TP_PID_DATA2_encryption_en_mask                                      (0x00004000)
#define  TP_TP_PID_DATA2_info_q_en_mask                                          (0x00002000)
#define  TP_TP_PID_DATA2_pre_des_mask                                            (0x00001000)
#define  TP_TP_PID_DATA2_key_mask                                                (0x00000F80)
#define  TP_TP_PID_DATA2_cc_en_mask                                              (0x00000040)
#define  TP_TP_PID_DATA2_ddr_q_en_mask                                           (0x00000020)
#define  TP_TP_PID_DATA2_info_q_mask                                             (0x0000001F)
#define  TP_TP_PID_DATA2_des_sel(data)                                           (0xE0000000&((data)<<29))
#define  TP_TP_PID_DATA2_aes_mode(data)                                          (0x18000000&((data)<<27))
#define  TP_TP_PID_DATA2_tdes_mode(data)                                         (0x04000000&((data)<<26))
#define  TP_TP_PID_DATA2_encrypt_tsc_en(data)                                    (0x02000000&((data)<<25))
#define  TP_TP_PID_DATA2_encryption_key(data)                                    (0x01000000&((data)<<24))
#define  TP_TP_PID_DATA2_keyindex(data)                                          (0x00FC0000&((data)<<18))
#define  TP_TP_PID_DATA2_local_des_en(data)                                      (0x00020000&((data)<<17))
#define  TP_TP_PID_DATA2_descramble_sel(data)                                    (0x00010000&((data)<<16))
#define  TP_TP_PID_DATA2_pid_des_disable(data)                                   (0x00008000&((data)<<15))
#define  TP_TP_PID_DATA2_encryption_en(data)                                     (0x00004000&((data)<<14))
#define  TP_TP_PID_DATA2_info_q_en(data)                                         (0x00002000&((data)<<13))
#define  TP_TP_PID_DATA2_pre_des(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_PID_DATA2_key(data)                                               (0x00000F80&((data)<<7))
#define  TP_TP_PID_DATA2_cc_en(data)                                             (0x00000040&((data)<<6))
#define  TP_TP_PID_DATA2_ddr_q_en(data)                                          (0x00000020&((data)<<5))
#define  TP_TP_PID_DATA2_info_q(data)                                            (0x0000001F&(data))
#define  TP_TP_PID_DATA2_get_des_sel(data)                                       ((0xE0000000&(data))>>29)
#define  TP_TP_PID_DATA2_get_aes_mode(data)                                      ((0x18000000&(data))>>27)
#define  TP_TP_PID_DATA2_get_tdes_mode(data)                                     ((0x04000000&(data))>>26)
#define  TP_TP_PID_DATA2_get_encrypt_tsc_en(data)                                ((0x02000000&(data))>>25)
#define  TP_TP_PID_DATA2_get_encryption_key(data)                                ((0x01000000&(data))>>24)
#define  TP_TP_PID_DATA2_get_keyindex(data)                                      ((0x00FC0000&(data))>>18)
#define  TP_TP_PID_DATA2_get_local_des_en(data)                                  ((0x00020000&(data))>>17)
#define  TP_TP_PID_DATA2_get_descramble_sel(data)                                ((0x00010000&(data))>>16)
#define  TP_TP_PID_DATA2_get_pid_des_disable(data)                               ((0x00008000&(data))>>15)
#define  TP_TP_PID_DATA2_get_encryption_en(data)                                 ((0x00004000&(data))>>14)
#define  TP_TP_PID_DATA2_get_info_q_en(data)                                     ((0x00002000&(data))>>13)
#define  TP_TP_PID_DATA2_get_pre_des(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_PID_DATA2_get_key(data)                                           ((0x00000F80&(data))>>7)
#define  TP_TP_PID_DATA2_get_cc_en(data)                                         ((0x00000040&(data))>>6)
#define  TP_TP_PID_DATA2_get_ddr_q_en(data)                                      ((0x00000020&(data))>>5)
#define  TP_TP_PID_DATA2_get_info_q(data)                                        (0x0000001F&(data))

#define  TP_TP_PID_DATA3                                                         0x180140E0
#define  TP_TP_PID_DATA3_reg_addr                                                "0xB80140E0"
#define  TP_TP_PID_DATA3_reg                                                     0xB80140E0
#define  TP_TP_PID_DATA3_inst_addr                                               "0x0045"
#define  set_TP_TP_PID_DATA3_reg(data)                                           (*((volatile unsigned int*)TP_TP_PID_DATA3_reg)=data)
#define  get_TP_TP_PID_DATA3_reg                                                 (*((volatile unsigned int*)TP_TP_PID_DATA3_reg))
#define  TP_TP_PID_DATA3_ofb_mode_shift                                          (18)
#define  TP_TP_PID_DATA3_csa_mode_shift                                          (16)
#define  TP_TP_PID_DATA3_round_shift                                             (8)
#define  TP_TP_PID_DATA3_multi2_mode_shift                                       (7)
#define  TP_TP_PID_DATA3_map_11_shift                                            (6)
#define  TP_TP_PID_DATA3_map_10_shift                                            (5)
#define  TP_TP_PID_DATA3_map_01_shift                                            (4)
#define  TP_TP_PID_DATA3_des_mode_shift                                          (3)
#define  TP_TP_PID_DATA3_mode_shift                                              (0)
#define  TP_TP_PID_DATA3_ofb_mode_mask                                           (0x000C0000)
#define  TP_TP_PID_DATA3_csa_mode_mask                                           (0x00030000)
#define  TP_TP_PID_DATA3_round_mask                                              (0x0000FF00)
#define  TP_TP_PID_DATA3_multi2_mode_mask                                        (0x00000080)
#define  TP_TP_PID_DATA3_map_11_mask                                             (0x00000040)
#define  TP_TP_PID_DATA3_map_10_mask                                             (0x00000020)
#define  TP_TP_PID_DATA3_map_01_mask                                             (0x00000010)
#define  TP_TP_PID_DATA3_des_mode_mask                                           (0x00000008)
#define  TP_TP_PID_DATA3_mode_mask                                               (0x00000007)
#define  TP_TP_PID_DATA3_ofb_mode(data)                                          (0x000C0000&((data)<<18))
#define  TP_TP_PID_DATA3_csa_mode(data)                                          (0x00030000&((data)<<16))
#define  TP_TP_PID_DATA3_round(data)                                             (0x0000FF00&((data)<<8))
#define  TP_TP_PID_DATA3_multi2_mode(data)                                       (0x00000080&((data)<<7))
#define  TP_TP_PID_DATA3_map_11(data)                                            (0x00000040&((data)<<6))
#define  TP_TP_PID_DATA3_map_10(data)                                            (0x00000020&((data)<<5))
#define  TP_TP_PID_DATA3_map_01(data)                                            (0x00000010&((data)<<4))
#define  TP_TP_PID_DATA3_des_mode(data)                                          (0x00000008&((data)<<3))
#define  TP_TP_PID_DATA3_mode(data)                                              (0x00000007&(data))
#define  TP_TP_PID_DATA3_get_ofb_mode(data)                                      ((0x000C0000&(data))>>18)
#define  TP_TP_PID_DATA3_get_csa_mode(data)                                      ((0x00030000&(data))>>16)
#define  TP_TP_PID_DATA3_get_round(data)                                         ((0x0000FF00&(data))>>8)
#define  TP_TP_PID_DATA3_get_multi2_mode(data)                                   ((0x00000080&(data))>>7)
#define  TP_TP_PID_DATA3_get_map_11(data)                                        ((0x00000040&(data))>>6)
#define  TP_TP_PID_DATA3_get_map_10(data)                                        ((0x00000020&(data))>>5)
#define  TP_TP_PID_DATA3_get_map_01(data)                                        ((0x00000010&(data))>>4)
#define  TP_TP_PID_DATA3_get_des_mode(data)                                      ((0x00000008&(data))>>3)
#define  TP_TP_PID_DATA3_get_mode(data)                                          (0x00000007&(data))

#define  TP_TP_SEC_CTRL                                                          0x180140E4
#define  TP_TP_SEC_CTRL_reg_addr                                                 "0xB80140E4"
#define  TP_TP_SEC_CTRL_reg                                                      0xB80140E4
#define  TP_TP_SEC_CTRL_inst_addr                                                "0x0046"
#define  set_TP_TP_SEC_CTRL_reg(data)                                            (*((volatile unsigned int*)TP_TP_SEC_CTRL_reg)=data)
#define  get_TP_TP_SEC_CTRL_reg                                                  (*((volatile unsigned int*)TP_TP_SEC_CTRL_reg))
#define  TP_TP_SEC_CTRL_r_w_shift                                                (8)
#define  TP_TP_SEC_CTRL_idx_shift                                                (0)
#define  TP_TP_SEC_CTRL_r_w_mask                                                 (0x00000100)
#define  TP_TP_SEC_CTRL_idx_mask                                                 (0x000000FF)
#define  TP_TP_SEC_CTRL_r_w(data)                                                (0x00000100&((data)<<8))
#define  TP_TP_SEC_CTRL_idx(data)                                                (0x000000FF&(data))
#define  TP_TP_SEC_CTRL_get_r_w(data)                                            ((0x00000100&(data))>>8)
#define  TP_TP_SEC_CTRL_get_idx(data)                                            (0x000000FF&(data))

#define  TP_TP_SEC_DATA0                                                         0x180140E8
#define  TP_TP_SEC_DATA0_reg_addr                                                "0xB80140E8"
#define  TP_TP_SEC_DATA0_reg                                                     0xB80140E8
#define  TP_TP_SEC_DATA0_inst_addr                                               "0x0047"
#define  set_TP_TP_SEC_DATA0_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA0_reg)=data)
#define  get_TP_TP_SEC_DATA0_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA0_reg))
#define  TP_TP_SEC_DATA0_filter_value_msb_shift                                  (0)
#define  TP_TP_SEC_DATA0_filter_value_msb_mask                                   (0xFFFFFFFF)
#define  TP_TP_SEC_DATA0_filter_value_msb(data)                                  (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA0_get_filter_value_msb(data)                              (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA1                                                         0x180140EC
#define  TP_TP_SEC_DATA1_reg_addr                                                "0xB80140EC"
#define  TP_TP_SEC_DATA1_reg                                                     0xB80140EC
#define  TP_TP_SEC_DATA1_inst_addr                                               "0x0048"
#define  set_TP_TP_SEC_DATA1_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA1_reg)=data)
#define  get_TP_TP_SEC_DATA1_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA1_reg))
#define  TP_TP_SEC_DATA1_filter_value_lsb_shift                                  (0)
#define  TP_TP_SEC_DATA1_filter_value_lsb_mask                                   (0xFFFFFFFF)
#define  TP_TP_SEC_DATA1_filter_value_lsb(data)                                  (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA1_get_filter_value_lsb(data)                              (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA2                                                         0x180140F0
#define  TP_TP_SEC_DATA2_reg_addr                                                "0xB80140F0"
#define  TP_TP_SEC_DATA2_reg                                                     0xB80140F0
#define  TP_TP_SEC_DATA2_inst_addr                                               "0x0049"
#define  set_TP_TP_SEC_DATA2_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA2_reg)=data)
#define  get_TP_TP_SEC_DATA2_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA2_reg))
#define  TP_TP_SEC_DATA2_mask_value_msb_shift                                    (0)
#define  TP_TP_SEC_DATA2_mask_value_msb_mask                                     (0xFFFFFFFF)
#define  TP_TP_SEC_DATA2_mask_value_msb(data)                                    (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA2_get_mask_value_msb(data)                                (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA3                                                         0x180140F4
#define  TP_TP_SEC_DATA3_reg_addr                                                "0xB80140F4"
#define  TP_TP_SEC_DATA3_reg                                                     0xB80140F4
#define  TP_TP_SEC_DATA3_inst_addr                                               "0x004A"
#define  set_TP_TP_SEC_DATA3_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA3_reg)=data)
#define  get_TP_TP_SEC_DATA3_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA3_reg))
#define  TP_TP_SEC_DATA3_mask_value_lsb_shift                                    (0)
#define  TP_TP_SEC_DATA3_mask_value_lsb_mask                                     (0xFFFFFFFF)
#define  TP_TP_SEC_DATA3_mask_value_lsb(data)                                    (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA3_get_mask_value_lsb(data)                                (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA4                                                         0x180140F8
#define  TP_TP_SEC_DATA4_reg_addr                                                "0xB80140F8"
#define  TP_TP_SEC_DATA4_reg                                                     0xB80140F8
#define  TP_TP_SEC_DATA4_inst_addr                                               "0x004B"
#define  set_TP_TP_SEC_DATA4_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA4_reg)=data)
#define  get_TP_TP_SEC_DATA4_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA4_reg))
#define  TP_TP_SEC_DATA4_sp_filter_shift                                         (14)
#define  TP_TP_SEC_DATA4_sp_mask_shift                                           (12)
#define  TP_TP_SEC_DATA4_crc_en_shift                                            (11)
#define  TP_TP_SEC_DATA4_p_d_shift                                               (10)
#define  TP_TP_SEC_DATA4_p_n_shift                                               (9)
#define  TP_TP_SEC_DATA4_last_shift                                              (8)
#define  TP_TP_SEC_DATA4_next_sec_shift                                          (0)
#define  TP_TP_SEC_DATA4_sp_filter_mask                                          (0x0000C000)
#define  TP_TP_SEC_DATA4_sp_mask_mask                                            (0x00003000)
#define  TP_TP_SEC_DATA4_crc_en_mask                                             (0x00000800)
#define  TP_TP_SEC_DATA4_p_d_mask                                                (0x00000400)
#define  TP_TP_SEC_DATA4_p_n_mask                                                (0x00000200)
#define  TP_TP_SEC_DATA4_last_mask                                               (0x00000100)
#define  TP_TP_SEC_DATA4_next_sec_mask                                           (0x000000FF)
#define  TP_TP_SEC_DATA4_sp_filter(data)                                         (0x0000C000&((data)<<14))
#define  TP_TP_SEC_DATA4_sp_mask(data)                                           (0x00003000&((data)<<12))
#define  TP_TP_SEC_DATA4_crc_en(data)                                            (0x00000800&((data)<<11))
#define  TP_TP_SEC_DATA4_p_d(data)                                               (0x00000400&((data)<<10))
#define  TP_TP_SEC_DATA4_p_n(data)                                               (0x00000200&((data)<<9))
#define  TP_TP_SEC_DATA4_last(data)                                              (0x00000100&((data)<<8))
#define  TP_TP_SEC_DATA4_next_sec(data)                                          (0x000000FF&(data))
#define  TP_TP_SEC_DATA4_get_sp_filter(data)                                     ((0x0000C000&(data))>>14)
#define  TP_TP_SEC_DATA4_get_sp_mask(data)                                       ((0x00003000&(data))>>12)
#define  TP_TP_SEC_DATA4_get_crc_en(data)                                        ((0x00000800&(data))>>11)
#define  TP_TP_SEC_DATA4_get_p_d(data)                                           ((0x00000400&(data))>>10)
#define  TP_TP_SEC_DATA4_get_p_n(data)                                           ((0x00000200&(data))>>9)
#define  TP_TP_SEC_DATA4_get_last(data)                                          ((0x00000100&(data))>>8)
#define  TP_TP_SEC_DATA4_get_next_sec(data)                                      (0x000000FF&(data))

#define  TP_TP_SEC_DATA5                                                         0x180140FC
#define  TP_TP_SEC_DATA5_reg_addr                                                "0xB80140FC"
#define  TP_TP_SEC_DATA5_reg                                                     0xB80140FC
#define  TP_TP_SEC_DATA5_inst_addr                                               "0x004C"
#define  set_TP_TP_SEC_DATA5_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA5_reg)=data)
#define  get_TP_TP_SEC_DATA5_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA5_reg))
#define  TP_TP_SEC_DATA5_neg_filter_value_msb_shift                              (0)
#define  TP_TP_SEC_DATA5_neg_filter_value_msb_mask                               (0xFFFFFFFF)
#define  TP_TP_SEC_DATA5_neg_filter_value_msb(data)                              (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA5_get_neg_filter_value_msb(data)                          (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA6                                                         0x18014100
#define  TP_TP_SEC_DATA6_reg_addr                                                "0xB8014100"
#define  TP_TP_SEC_DATA6_reg                                                     0xB8014100
#define  TP_TP_SEC_DATA6_inst_addr                                               "0x004D"
#define  set_TP_TP_SEC_DATA6_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA6_reg)=data)
#define  get_TP_TP_SEC_DATA6_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA6_reg))
#define  TP_TP_SEC_DATA6_neg_filter_value_lsb_shift                              (0)
#define  TP_TP_SEC_DATA6_neg_filter_value_lsb_mask                               (0xFFFFFFFF)
#define  TP_TP_SEC_DATA6_neg_filter_value_lsb(data)                              (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA6_get_neg_filter_value_lsb(data)                          (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA7                                                         0x18014104
#define  TP_TP_SEC_DATA7_reg_addr                                                "0xB8014104"
#define  TP_TP_SEC_DATA7_reg                                                     0xB8014104
#define  TP_TP_SEC_DATA7_inst_addr                                               "0x004E"
#define  set_TP_TP_SEC_DATA7_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA7_reg)=data)
#define  get_TP_TP_SEC_DATA7_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA7_reg))
#define  TP_TP_SEC_DATA7_neg_mask_value_msb_shift                                (0)
#define  TP_TP_SEC_DATA7_neg_mask_value_msb_mask                                 (0xFFFFFFFF)
#define  TP_TP_SEC_DATA7_neg_mask_value_msb(data)                                (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA7_get_neg_mask_value_msb(data)                            (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA8                                                         0x1801410C
#define  TP_TP_SEC_DATA8_reg_addr                                                "0xB801410C"
#define  TP_TP_SEC_DATA8_reg                                                     0xB801410C
#define  TP_TP_SEC_DATA8_inst_addr                                               "0x004F"
#define  set_TP_TP_SEC_DATA8_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA8_reg)=data)
#define  get_TP_TP_SEC_DATA8_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA8_reg))
#define  TP_TP_SEC_DATA8_neg_mask_value_lsb_shift                                (0)
#define  TP_TP_SEC_DATA8_neg_mask_value_lsb_mask                                 (0xFFFFFFFF)
#define  TP_TP_SEC_DATA8_neg_mask_value_lsb(data)                                (0xFFFFFFFF&(data))
#define  TP_TP_SEC_DATA8_get_neg_mask_value_lsb(data)                            (0xFFFFFFFF&(data))

#define  TP_TP_SEC_DATA9                                                         0x18014110
#define  TP_TP_SEC_DATA9_reg_addr                                                "0xB8014110"
#define  TP_TP_SEC_DATA9_reg                                                     0xB8014110
#define  TP_TP_SEC_DATA9_inst_addr                                               "0x0050"
#define  set_TP_TP_SEC_DATA9_reg(data)                                           (*((volatile unsigned int*)TP_TP_SEC_DATA9_reg)=data)
#define  get_TP_TP_SEC_DATA9_reg                                                 (*((volatile unsigned int*)TP_TP_SEC_DATA9_reg))
#define  TP_TP_SEC_DATA9_neg_sp_filter_shift                                     (12)
#define  TP_TP_SEC_DATA9_neg_sp_mask_shift                                       (10)
#define  TP_TP_SEC_DATA9_filter_sel_shift                                        (0)
#define  TP_TP_SEC_DATA9_neg_sp_filter_mask                                      (0x00003000)
#define  TP_TP_SEC_DATA9_neg_sp_mask_mask                                        (0x00000C00)
#define  TP_TP_SEC_DATA9_filter_sel_mask                                         (0x00000003)
#define  TP_TP_SEC_DATA9_neg_sp_filter(data)                                     (0x00003000&((data)<<12))
#define  TP_TP_SEC_DATA9_neg_sp_mask(data)                                       (0x00000C00&((data)<<10))
#define  TP_TP_SEC_DATA9_filter_sel(data)                                        (0x00000003&(data))
#define  TP_TP_SEC_DATA9_get_neg_sp_filter(data)                                 ((0x00003000&(data))>>12)
#define  TP_TP_SEC_DATA9_get_neg_sp_mask(data)                                   ((0x00000C00&(data))>>10)
#define  TP_TP_SEC_DATA9_get_filter_sel(data)                                    (0x00000003&(data))

#define  TP_TP_TP0_DES_CNTL                                                      0x18014114
#define  TP_TP_TP0_DES_CNTL_reg_addr                                             "0xB8014114"
#define  TP_TP_TP0_DES_CNTL_reg                                                  0xB8014114
#define  TP_TP_TP0_DES_CNTL_inst_addr                                            "0x0051"
#define  set_TP_TP_TP0_DES_CNTL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TP0_DES_CNTL_reg)=data)
#define  get_TP_TP_TP0_DES_CNTL_reg                                              (*((volatile unsigned int*)TP_TP_TP0_DES_CNTL_reg))
#define  TP_TP_TP0_DES_CNTL_ofb_mode_shift                                       (18)
#define  TP_TP_TP0_DES_CNTL_csa_mode_shift                                       (16)
#define  TP_TP_TP0_DES_CNTL_round_shift                                          (8)
#define  TP_TP_TP0_DES_CNTL_multi2_mode_shift                                    (7)
#define  TP_TP_TP0_DES_CNTL_map_11_shift                                         (6)
#define  TP_TP_TP0_DES_CNTL_map_10_shift                                         (5)
#define  TP_TP_TP0_DES_CNTL_map_01_shift                                         (4)
#define  TP_TP_TP0_DES_CNTL_des_mode_shift                                       (3)
#define  TP_TP_TP0_DES_CNTL_mode_shift                                           (0)
#define  TP_TP_TP0_DES_CNTL_ofb_mode_mask                                        (0x000C0000)
#define  TP_TP_TP0_DES_CNTL_csa_mode_mask                                        (0x00030000)
#define  TP_TP_TP0_DES_CNTL_round_mask                                           (0x0000FF00)
#define  TP_TP_TP0_DES_CNTL_multi2_mode_mask                                     (0x00000080)
#define  TP_TP_TP0_DES_CNTL_map_11_mask                                          (0x00000040)
#define  TP_TP_TP0_DES_CNTL_map_10_mask                                          (0x00000020)
#define  TP_TP_TP0_DES_CNTL_map_01_mask                                          (0x00000010)
#define  TP_TP_TP0_DES_CNTL_des_mode_mask                                        (0x00000008)
#define  TP_TP_TP0_DES_CNTL_mode_mask                                            (0x00000007)
#define  TP_TP_TP0_DES_CNTL_ofb_mode(data)                                       (0x000C0000&((data)<<18))
#define  TP_TP_TP0_DES_CNTL_csa_mode(data)                                       (0x00030000&((data)<<16))
#define  TP_TP_TP0_DES_CNTL_round(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TP0_DES_CNTL_multi2_mode(data)                                    (0x00000080&((data)<<7))
#define  TP_TP_TP0_DES_CNTL_map_11(data)                                         (0x00000040&((data)<<6))
#define  TP_TP_TP0_DES_CNTL_map_10(data)                                         (0x00000020&((data)<<5))
#define  TP_TP_TP0_DES_CNTL_map_01(data)                                         (0x00000010&((data)<<4))
#define  TP_TP_TP0_DES_CNTL_des_mode(data)                                       (0x00000008&((data)<<3))
#define  TP_TP_TP0_DES_CNTL_mode(data)                                           (0x00000007&(data))
#define  TP_TP_TP0_DES_CNTL_get_ofb_mode(data)                                   ((0x000C0000&(data))>>18)
#define  TP_TP_TP0_DES_CNTL_get_csa_mode(data)                                   ((0x00030000&(data))>>16)
#define  TP_TP_TP0_DES_CNTL_get_round(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TP0_DES_CNTL_get_multi2_mode(data)                                ((0x00000080&(data))>>7)
#define  TP_TP_TP0_DES_CNTL_get_map_11(data)                                     ((0x00000040&(data))>>6)
#define  TP_TP_TP0_DES_CNTL_get_map_10(data)                                     ((0x00000020&(data))>>5)
#define  TP_TP_TP0_DES_CNTL_get_map_01(data)                                     ((0x00000010&(data))>>4)
#define  TP_TP_TP0_DES_CNTL_get_des_mode(data)                                   ((0x00000008&(data))>>3)
#define  TP_TP_TP0_DES_CNTL_get_mode(data)                                       (0x00000007&(data))

#define  TP_TP_KEY_INFO_0                                                        0x18014118
#define  TP_TP_KEY_INFO_0_reg_addr                                               "0xB8014118"
#define  TP_TP_KEY_INFO_0_reg                                                    0xB8014118
#define  TP_TP_KEY_INFO_0_inst_addr                                              "0x0052"
#define  set_TP_TP_KEY_INFO_0_reg(data)                                          (*((volatile unsigned int*)TP_TP_KEY_INFO_0_reg)=data)
#define  get_TP_TP_KEY_INFO_0_reg                                                (*((volatile unsigned int*)TP_TP_KEY_INFO_0_reg))
#define  TP_TP_KEY_INFO_0_key_info_shift                                         (0)
#define  TP_TP_KEY_INFO_0_key_info_mask                                          (0xFFFFFFFF)
#define  TP_TP_KEY_INFO_0_key_info(data)                                         (0xFFFFFFFF&(data))
#define  TP_TP_KEY_INFO_0_get_key_info(data)                                     (0xFFFFFFFF&(data))

#define  TP_TP_KEY_INFO_1                                                        0x1801411C
#define  TP_TP_KEY_INFO_1_reg_addr                                               "0xB801411C"
#define  TP_TP_KEY_INFO_1_reg                                                    0xB801411C
#define  TP_TP_KEY_INFO_1_inst_addr                                              "0x0053"
#define  set_TP_TP_KEY_INFO_1_reg(data)                                          (*((volatile unsigned int*)TP_TP_KEY_INFO_1_reg)=data)
#define  get_TP_TP_KEY_INFO_1_reg                                                (*((volatile unsigned int*)TP_TP_KEY_INFO_1_reg))
#define  TP_TP_KEY_INFO_1_key_info_shift                                         (0)
#define  TP_TP_KEY_INFO_1_key_info_mask                                          (0xFFFFFFFF)
#define  TP_TP_KEY_INFO_1_key_info(data)                                         (0xFFFFFFFF&(data))
#define  TP_TP_KEY_INFO_1_get_key_info(data)                                     (0xFFFFFFFF&(data))

#define  TP_TP_KEY_CTRL                                                          0x18014120
#define  TP_TP_KEY_CTRL_reg_addr                                                 "0xB8014120"
#define  TP_TP_KEY_CTRL_reg                                                      0xB8014120
#define  TP_TP_KEY_CTRL_inst_addr                                                "0x0054"
#define  set_TP_TP_KEY_CTRL_reg(data)                                            (*((volatile unsigned int*)TP_TP_KEY_CTRL_reg)=data)
#define  get_TP_TP_KEY_CTRL_reg                                                  (*((volatile unsigned int*)TP_TP_KEY_CTRL_reg))
#define  TP_TP_KEY_CTRL_r_w_shift                                                (7)
#define  TP_TP_KEY_CTRL_idx_shift                                                (0)
#define  TP_TP_KEY_CTRL_r_w_mask                                                 (0x00000080)
#define  TP_TP_KEY_CTRL_idx_mask                                                 (0x0000007F)
#define  TP_TP_KEY_CTRL_r_w(data)                                                (0x00000080&((data)<<7))
#define  TP_TP_KEY_CTRL_idx(data)                                                (0x0000007F&(data))
#define  TP_TP_KEY_CTRL_get_r_w(data)                                            ((0x00000080&(data))>>7)
#define  TP_TP_KEY_CTRL_get_idx(data)                                            (0x0000007F&(data))

#define  TP_TP_TP1_DES_CNTL                                                      0x18014124
#define  TP_TP_TP1_DES_CNTL_reg_addr                                             "0xB8014124"
#define  TP_TP_TP1_DES_CNTL_reg                                                  0xB8014124
#define  TP_TP_TP1_DES_CNTL_inst_addr                                            "0x0055"
#define  set_TP_TP_TP1_DES_CNTL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TP1_DES_CNTL_reg)=data)
#define  get_TP_TP_TP1_DES_CNTL_reg                                              (*((volatile unsigned int*)TP_TP_TP1_DES_CNTL_reg))
#define  TP_TP_TP1_DES_CNTL_ofb_mode_shift                                       (18)
#define  TP_TP_TP1_DES_CNTL_csa_mode_shift                                       (16)
#define  TP_TP_TP1_DES_CNTL_round_shift                                          (8)
#define  TP_TP_TP1_DES_CNTL_multi2_mode_shift                                    (7)
#define  TP_TP_TP1_DES_CNTL_map_11_shift                                         (6)
#define  TP_TP_TP1_DES_CNTL_map_10_shift                                         (5)
#define  TP_TP_TP1_DES_CNTL_map_01_shift                                         (4)
#define  TP_TP_TP1_DES_CNTL_des_mode_shift                                       (3)
#define  TP_TP_TP1_DES_CNTL_mode_shift                                           (0)
#define  TP_TP_TP1_DES_CNTL_ofb_mode_mask                                        (0x000C0000)
#define  TP_TP_TP1_DES_CNTL_csa_mode_mask                                        (0x00030000)
#define  TP_TP_TP1_DES_CNTL_round_mask                                           (0x0000FF00)
#define  TP_TP_TP1_DES_CNTL_multi2_mode_mask                                     (0x00000080)
#define  TP_TP_TP1_DES_CNTL_map_11_mask                                          (0x00000040)
#define  TP_TP_TP1_DES_CNTL_map_10_mask                                          (0x00000020)
#define  TP_TP_TP1_DES_CNTL_map_01_mask                                          (0x00000010)
#define  TP_TP_TP1_DES_CNTL_des_mode_mask                                        (0x00000008)
#define  TP_TP_TP1_DES_CNTL_mode_mask                                            (0x00000007)
#define  TP_TP_TP1_DES_CNTL_ofb_mode(data)                                       (0x000C0000&((data)<<18))
#define  TP_TP_TP1_DES_CNTL_csa_mode(data)                                       (0x00030000&((data)<<16))
#define  TP_TP_TP1_DES_CNTL_round(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TP1_DES_CNTL_multi2_mode(data)                                    (0x00000080&((data)<<7))
#define  TP_TP_TP1_DES_CNTL_map_11(data)                                         (0x00000040&((data)<<6))
#define  TP_TP_TP1_DES_CNTL_map_10(data)                                         (0x00000020&((data)<<5))
#define  TP_TP_TP1_DES_CNTL_map_01(data)                                         (0x00000010&((data)<<4))
#define  TP_TP_TP1_DES_CNTL_des_mode(data)                                       (0x00000008&((data)<<3))
#define  TP_TP_TP1_DES_CNTL_mode(data)                                           (0x00000007&(data))
#define  TP_TP_TP1_DES_CNTL_get_ofb_mode(data)                                   ((0x000C0000&(data))>>18)
#define  TP_TP_TP1_DES_CNTL_get_csa_mode(data)                                   ((0x00030000&(data))>>16)
#define  TP_TP_TP1_DES_CNTL_get_round(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TP1_DES_CNTL_get_multi2_mode(data)                                ((0x00000080&(data))>>7)
#define  TP_TP_TP1_DES_CNTL_get_map_11(data)                                     ((0x00000040&(data))>>6)
#define  TP_TP_TP1_DES_CNTL_get_map_10(data)                                     ((0x00000020&(data))>>5)
#define  TP_TP_TP1_DES_CNTL_get_map_01(data)                                     ((0x00000010&(data))>>4)
#define  TP_TP_TP1_DES_CNTL_get_des_mode(data)                                   ((0x00000008&(data))>>3)
#define  TP_TP_TP1_DES_CNTL_get_mode(data)                                       (0x00000007&(data))

#define  TP_TP_TP2_DES_CNTL                                                      0x18014128
#define  TP_TP_TP2_DES_CNTL_reg_addr                                             "0xB8014128"
#define  TP_TP_TP2_DES_CNTL_reg                                                  0xB8014128
#define  TP_TP_TP2_DES_CNTL_inst_addr                                            "0x0056"
#define  set_TP_TP_TP2_DES_CNTL_reg(data)                                        (*((volatile unsigned int*)TP_TP_TP2_DES_CNTL_reg)=data)
#define  get_TP_TP_TP2_DES_CNTL_reg                                              (*((volatile unsigned int*)TP_TP_TP2_DES_CNTL_reg))
#define  TP_TP_TP2_DES_CNTL_ofb_mode_shift                                       (18)
#define  TP_TP_TP2_DES_CNTL_csa_mode_shift                                       (16)
#define  TP_TP_TP2_DES_CNTL_round_shift                                          (8)
#define  TP_TP_TP2_DES_CNTL_multi2_mode_shift                                    (7)
#define  TP_TP_TP2_DES_CNTL_map_11_shift                                         (6)
#define  TP_TP_TP2_DES_CNTL_map_10_shift                                         (5)
#define  TP_TP_TP2_DES_CNTL_map_01_shift                                         (4)
#define  TP_TP_TP2_DES_CNTL_des_mode_shift                                       (3)
#define  TP_TP_TP2_DES_CNTL_mode_shift                                           (0)
#define  TP_TP_TP2_DES_CNTL_ofb_mode_mask                                        (0x000C0000)
#define  TP_TP_TP2_DES_CNTL_csa_mode_mask                                        (0x00030000)
#define  TP_TP_TP2_DES_CNTL_round_mask                                           (0x0000FF00)
#define  TP_TP_TP2_DES_CNTL_multi2_mode_mask                                     (0x00000080)
#define  TP_TP_TP2_DES_CNTL_map_11_mask                                          (0x00000040)
#define  TP_TP_TP2_DES_CNTL_map_10_mask                                          (0x00000020)
#define  TP_TP_TP2_DES_CNTL_map_01_mask                                          (0x00000010)
#define  TP_TP_TP2_DES_CNTL_des_mode_mask                                        (0x00000008)
#define  TP_TP_TP2_DES_CNTL_mode_mask                                            (0x00000007)
#define  TP_TP_TP2_DES_CNTL_ofb_mode(data)                                       (0x000C0000&((data)<<18))
#define  TP_TP_TP2_DES_CNTL_csa_mode(data)                                       (0x00030000&((data)<<16))
#define  TP_TP_TP2_DES_CNTL_round(data)                                          (0x0000FF00&((data)<<8))
#define  TP_TP_TP2_DES_CNTL_multi2_mode(data)                                    (0x00000080&((data)<<7))
#define  TP_TP_TP2_DES_CNTL_map_11(data)                                         (0x00000040&((data)<<6))
#define  TP_TP_TP2_DES_CNTL_map_10(data)                                         (0x00000020&((data)<<5))
#define  TP_TP_TP2_DES_CNTL_map_01(data)                                         (0x00000010&((data)<<4))
#define  TP_TP_TP2_DES_CNTL_des_mode(data)                                       (0x00000008&((data)<<3))
#define  TP_TP_TP2_DES_CNTL_mode(data)                                           (0x00000007&(data))
#define  TP_TP_TP2_DES_CNTL_get_ofb_mode(data)                                   ((0x000C0000&(data))>>18)
#define  TP_TP_TP2_DES_CNTL_get_csa_mode(data)                                   ((0x00030000&(data))>>16)
#define  TP_TP_TP2_DES_CNTL_get_round(data)                                      ((0x0000FF00&(data))>>8)
#define  TP_TP_TP2_DES_CNTL_get_multi2_mode(data)                                ((0x00000080&(data))>>7)
#define  TP_TP_TP2_DES_CNTL_get_map_11(data)                                     ((0x00000040&(data))>>6)
#define  TP_TP_TP2_DES_CNTL_get_map_10(data)                                     ((0x00000020&(data))>>5)
#define  TP_TP_TP2_DES_CNTL_get_map_01(data)                                     ((0x00000010&(data))>>4)
#define  TP_TP_TP2_DES_CNTL_get_des_mode(data)                                   ((0x00000008&(data))>>3)
#define  TP_TP_TP2_DES_CNTL_get_mode(data)                                       (0x00000007&(data))

#define  TP_TP_CRC_INIT                                                          0x1801412C
#define  TP_TP_CRC_INIT_reg_addr                                                 "0xB801412C"
#define  TP_TP_CRC_INIT_reg                                                      0xB801412C
#define  TP_TP_CRC_INIT_inst_addr                                                "0x0057"
#define  set_TP_TP_CRC_INIT_reg(data)                                            (*((volatile unsigned int*)TP_TP_CRC_INIT_reg)=data)
#define  get_TP_TP_CRC_INIT_reg                                                  (*((volatile unsigned int*)TP_TP_CRC_INIT_reg))
#define  TP_TP_CRC_INIT_crc_init_shift                                           (0)
#define  TP_TP_CRC_INIT_crc_init_mask                                            (0xFFFFFFFF)
#define  TP_TP_CRC_INIT_crc_init(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_CRC_INIT_get_crc_init(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_THRESHOLD                                                         0x18014130
#define  TP_TP_THRESHOLD_reg_addr                                                "0xB8014130"
#define  TP_TP_THRESHOLD_reg                                                     0xB8014130
#define  TP_TP_THRESHOLD_inst_addr                                               "0x0058"
#define  set_TP_TP_THRESHOLD_reg(data)                                           (*((volatile unsigned int*)TP_TP_THRESHOLD_reg)=data)
#define  get_TP_TP_THRESHOLD_reg                                                 (*((volatile unsigned int*)TP_TP_THRESHOLD_reg))
#define  TP_TP_THRESHOLD_threshold_shift                                         (0)
#define  TP_TP_THRESHOLD_threshold_mask                                          (0x1FFFFFFF)
#define  TP_TP_THRESHOLD_threshold(data)                                         (0x1FFFFFFF&(data))
#define  TP_TP_THRESHOLD_get_threshold(data)                                     (0x1FFFFFFF&(data))

#define  TP_TP_FULLNESS                                                          0x18014134
#define  TP_TP_FULLNESS_reg_addr                                                 "0xB8014134"
#define  TP_TP_FULLNESS_reg                                                      0xB8014134
#define  TP_TP_FULLNESS_inst_addr                                                "0x0059"
#define  set_TP_TP_FULLNESS_reg(data)                                            (*((volatile unsigned int*)TP_TP_FULLNESS_reg)=data)
#define  get_TP_TP_FULLNESS_reg                                                  (*((volatile unsigned int*)TP_TP_FULLNESS_reg))
#define  TP_TP_FULLNESS_fullness_shift                                           (0)
#define  TP_TP_FULLNESS_fullness_mask                                            (0x1FFFFFFF)
#define  TP_TP_FULLNESS_fullness(data)                                           (0x1FFFFFFF&(data))
#define  TP_TP_FULLNESS_get_fullness(data)                                       (0x1FFFFFFF&(data))

#define  TP_TP_RING_CTRL                                                         0x18014138
#define  TP_TP_RING_CTRL_reg_addr                                                "0xB8014138"
#define  TP_TP_RING_CTRL_reg                                                     0xB8014138
#define  TP_TP_RING_CTRL_inst_addr                                               "0x005A"
#define  set_TP_TP_RING_CTRL_reg(data)                                           (*((volatile unsigned int*)TP_TP_RING_CTRL_reg)=data)
#define  get_TP_TP_RING_CTRL_reg                                                 (*((volatile unsigned int*)TP_TP_RING_CTRL_reg))
#define  TP_TP_RING_CTRL_wm_shift                                                (7)
#define  TP_TP_RING_CTRL_r_w_shift                                               (6)
#define  TP_TP_RING_CTRL_idx_shift                                               (0)
#define  TP_TP_RING_CTRL_wm_mask                                                 (0x00000780)
#define  TP_TP_RING_CTRL_r_w_mask                                                (0x00000040)
#define  TP_TP_RING_CTRL_idx_mask                                                (0x0000001F)
#define  TP_TP_RING_CTRL_wm(data)                                                (0x00000780&((data)<<7))
#define  TP_TP_RING_CTRL_r_w(data)                                               (0x00000040&((data)<<6))
#define  TP_TP_RING_CTRL_idx(data)                                               (0x0000001F&(data))
#define  TP_TP_RING_CTRL_get_wm(data)                                            ((0x00000780&(data))>>7)
#define  TP_TP_RING_CTRL_get_r_w(data)                                           ((0x00000040&(data))>>6)
#define  TP_TP_RING_CTRL_get_idx(data)                                           (0x0000001F&(data))

#define  TP_TP_RING_LIMIT                                                        0x1801413C
#define  TP_TP_RING_LIMIT_reg_addr                                               "0xB801413C"
#define  TP_TP_RING_LIMIT_reg                                                    0xB801413C
#define  TP_TP_RING_LIMIT_inst_addr                                              "0x005B"
#define  set_TP_TP_RING_LIMIT_reg(data)                                          (*((volatile unsigned int*)TP_TP_RING_LIMIT_reg)=data)
#define  get_TP_TP_RING_LIMIT_reg                                                (*((volatile unsigned int*)TP_TP_RING_LIMIT_reg))
#define  TP_TP_RING_LIMIT_ring_limit_shift                                       (3)
#define  TP_TP_RING_LIMIT_ring_limit_mask                                        (0xFFFFFFF8)
#define  TP_TP_RING_LIMIT_ring_limit(data)                                       (0xFFFFFFF8&((data)<<3))
#define  TP_TP_RING_LIMIT_get_ring_limit(data)                                   ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_RING_BASE                                                         0x18014140
#define  TP_TP_RING_BASE_reg_addr                                                "0xB8014140"
#define  TP_TP_RING_BASE_reg                                                     0xB8014140
#define  TP_TP_RING_BASE_inst_addr                                               "0x005C"
#define  set_TP_TP_RING_BASE_reg(data)                                           (*((volatile unsigned int*)TP_TP_RING_BASE_reg)=data)
#define  get_TP_TP_RING_BASE_reg                                                 (*((volatile unsigned int*)TP_TP_RING_BASE_reg))
#define  TP_TP_RING_BASE_ring_base_shift                                         (3)
#define  TP_TP_RING_BASE_ring_base_mask                                          (0xFFFFFFF8)
#define  TP_TP_RING_BASE_ring_base(data)                                         (0xFFFFFFF8&((data)<<3))
#define  TP_TP_RING_BASE_get_ring_base(data)                                     ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_RING_RP                                                           0x18014144
#define  TP_TP_RING_RP_reg_addr                                                  "0xB8014144"
#define  TP_TP_RING_RP_reg                                                       0xB8014144
#define  TP_TP_RING_RP_inst_addr                                                 "0x005D"
#define  set_TP_TP_RING_RP_reg(data)                                             (*((volatile unsigned int*)TP_TP_RING_RP_reg)=data)
#define  get_TP_TP_RING_RP_reg                                                   (*((volatile unsigned int*)TP_TP_RING_RP_reg))
#define  TP_TP_RING_RP_ring_rp_shift                                             (0)
#define  TP_TP_RING_RP_ring_rp_mask                                              (0xFFFFFFFF)
#define  TP_TP_RING_RP_ring_rp(data)                                             (0xFFFFFFFF&(data))
#define  TP_TP_RING_RP_get_ring_rp(data)                                         (0xFFFFFFFF&(data))

#define  TP_TP_RING_WP                                                           0x18014148
#define  TP_TP_RING_WP_reg_addr                                                  "0xB8014148"
#define  TP_TP_RING_WP_reg                                                       0xB8014148
#define  TP_TP_RING_WP_inst_addr                                                 "0x005E"
#define  set_TP_TP_RING_WP_reg(data)                                             (*((volatile unsigned int*)TP_TP_RING_WP_reg)=data)
#define  get_TP_TP_RING_WP_reg                                                   (*((volatile unsigned int*)TP_TP_RING_WP_reg))
#define  TP_TP_RING_WP_ring_wp_shift                                             (0)
#define  TP_TP_RING_WP_ring_wp_mask                                              (0xFFFFFFFF)
#define  TP_TP_RING_WP_ring_wp(data)                                             (0xFFFFFFFF&(data))
#define  TP_TP_RING_WP_get_ring_wp(data)                                         (0xFFFFFFFF&(data))

#define  TP_TP_RING_AVAIL_INT_0                                                  0x1801414C
#define  TP_TP_RING_AVAIL_INT_0_reg_addr                                         "0xB801414C"
#define  TP_TP_RING_AVAIL_INT_0_reg                                              0xB801414C
#define  TP_TP_RING_AVAIL_INT_0_inst_addr                                        "0x005F"
#define  set_TP_TP_RING_AVAIL_INT_0_reg(data)                                    (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_0_reg)=data)
#define  get_TP_TP_RING_AVAIL_INT_0_reg                                          (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_0_reg))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_15_shift                              (16)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_14_shift                              (15)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_13_shift                              (14)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_12_shift                              (13)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_11_shift                              (12)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_10_shift                              (11)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_9_shift                               (10)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_8_shift                               (9)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_7_shift                               (8)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_6_shift                               (7)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_5_shift                               (6)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_4_shift                               (5)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_3_shift                               (4)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_2_shift                               (3)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_1_shift                               (2)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_0_shift                               (1)
#define  TP_TP_RING_AVAIL_INT_0_write_data_shift                                 (0)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_15_mask                               (0x00010000)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_14_mask                               (0x00008000)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_13_mask                               (0x00004000)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_12_mask                               (0x00002000)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_11_mask                               (0x00001000)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_10_mask                               (0x00000800)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_9_mask                                (0x00000400)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_8_mask                                (0x00000200)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_7_mask                                (0x00000100)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_6_mask                                (0x00000080)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_5_mask                                (0x00000040)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_4_mask                                (0x00000020)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_3_mask                                (0x00000010)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_2_mask                                (0x00000008)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_1_mask                                (0x00000004)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_0_mask                                (0x00000002)
#define  TP_TP_RING_AVAIL_INT_0_write_data_mask                                  (0x00000001)
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_15(data)                              (0x00010000&((data)<<16))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_14(data)                              (0x00008000&((data)<<15))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_13(data)                              (0x00004000&((data)<<14))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_12(data)                              (0x00002000&((data)<<13))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_11(data)                              (0x00001000&((data)<<12))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_10(data)                              (0x00000800&((data)<<11))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_9(data)                               (0x00000400&((data)<<10))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_8(data)                               (0x00000200&((data)<<9))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_7(data)                               (0x00000100&((data)<<8))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_6(data)                               (0x00000080&((data)<<7))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_5(data)                               (0x00000040&((data)<<6))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_4(data)                               (0x00000020&((data)<<5))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_3(data)                               (0x00000010&((data)<<4))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_2(data)                               (0x00000008&((data)<<3))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_1(data)                               (0x00000004&((data)<<2))
#define  TP_TP_RING_AVAIL_INT_0_ring_avail_0(data)                               (0x00000002&((data)<<1))
#define  TP_TP_RING_AVAIL_INT_0_write_data(data)                                 (0x00000001&(data))
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_15(data)                          ((0x00010000&(data))>>16)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_14(data)                          ((0x00008000&(data))>>15)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_13(data)                          ((0x00004000&(data))>>14)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_12(data)                          ((0x00002000&(data))>>13)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_11(data)                          ((0x00001000&(data))>>12)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_10(data)                          ((0x00000800&(data))>>11)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_9(data)                           ((0x00000400&(data))>>10)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_8(data)                           ((0x00000200&(data))>>9)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_7(data)                           ((0x00000100&(data))>>8)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_6(data)                           ((0x00000080&(data))>>7)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_5(data)                           ((0x00000040&(data))>>6)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_4(data)                           ((0x00000020&(data))>>5)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_3(data)                           ((0x00000010&(data))>>4)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_2(data)                           ((0x00000008&(data))>>3)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_1(data)                           ((0x00000004&(data))>>2)
#define  TP_TP_RING_AVAIL_INT_0_get_ring_avail_0(data)                           ((0x00000002&(data))>>1)
#define  TP_TP_RING_AVAIL_INT_0_get_write_data(data)                             (0x00000001&(data))

#define  TP_TP_RING_AVAIL_INT_1                                                  0x18014150
#define  TP_TP_RING_AVAIL_INT_1_reg_addr                                         "0xB8014150"
#define  TP_TP_RING_AVAIL_INT_1_reg                                              0xB8014150
#define  TP_TP_RING_AVAIL_INT_1_inst_addr                                        "0x0060"
#define  set_TP_TP_RING_AVAIL_INT_1_reg(data)                                    (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_1_reg)=data)
#define  get_TP_TP_RING_AVAIL_INT_1_reg                                          (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_1_reg))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_15_shift                              (16)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_14_shift                              (15)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_13_shift                              (14)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_12_shift                              (13)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_11_shift                              (12)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_10_shift                              (11)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_9_shift                               (10)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_8_shift                               (9)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_7_shift                               (8)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_6_shift                               (7)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_5_shift                               (6)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_4_shift                               (5)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_3_shift                               (4)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_2_shift                               (3)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_1_shift                               (2)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_0_shift                               (1)
#define  TP_TP_RING_AVAIL_INT_1_write_data_shift                                 (0)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_15_mask                               (0x00010000)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_14_mask                               (0x00008000)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_13_mask                               (0x00004000)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_12_mask                               (0x00002000)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_11_mask                               (0x00001000)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_10_mask                               (0x00000800)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_9_mask                                (0x00000400)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_8_mask                                (0x00000200)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_7_mask                                (0x00000100)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_6_mask                                (0x00000080)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_5_mask                                (0x00000040)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_4_mask                                (0x00000020)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_3_mask                                (0x00000010)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_2_mask                                (0x00000008)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_1_mask                                (0x00000004)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_0_mask                                (0x00000002)
#define  TP_TP_RING_AVAIL_INT_1_write_data_mask                                  (0x00000001)
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_15(data)                              (0x00010000&((data)<<16))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_14(data)                              (0x00008000&((data)<<15))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_13(data)                              (0x00004000&((data)<<14))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_12(data)                              (0x00002000&((data)<<13))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_11(data)                              (0x00001000&((data)<<12))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_10(data)                              (0x00000800&((data)<<11))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_9(data)                               (0x00000400&((data)<<10))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_8(data)                               (0x00000200&((data)<<9))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_7(data)                               (0x00000100&((data)<<8))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_6(data)                               (0x00000080&((data)<<7))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_5(data)                               (0x00000040&((data)<<6))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_4(data)                               (0x00000020&((data)<<5))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_3(data)                               (0x00000010&((data)<<4))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_2(data)                               (0x00000008&((data)<<3))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_1(data)                               (0x00000004&((data)<<2))
#define  TP_TP_RING_AVAIL_INT_1_ring_avail_0(data)                               (0x00000002&((data)<<1))
#define  TP_TP_RING_AVAIL_INT_1_write_data(data)                                 (0x00000001&(data))
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_15(data)                          ((0x00010000&(data))>>16)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_14(data)                          ((0x00008000&(data))>>15)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_13(data)                          ((0x00004000&(data))>>14)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_12(data)                          ((0x00002000&(data))>>13)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_11(data)                          ((0x00001000&(data))>>12)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_10(data)                          ((0x00000800&(data))>>11)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_9(data)                           ((0x00000400&(data))>>10)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_8(data)                           ((0x00000200&(data))>>9)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_7(data)                           ((0x00000100&(data))>>8)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_6(data)                           ((0x00000080&(data))>>7)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_5(data)                           ((0x00000040&(data))>>6)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_4(data)                           ((0x00000020&(data))>>5)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_3(data)                           ((0x00000010&(data))>>4)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_2(data)                           ((0x00000008&(data))>>3)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_1(data)                           ((0x00000004&(data))>>2)
#define  TP_TP_RING_AVAIL_INT_1_get_ring_avail_0(data)                           ((0x00000002&(data))>>1)
#define  TP_TP_RING_AVAIL_INT_1_get_write_data(data)                             (0x00000001&(data))

#define  TP_TP_RING_FULL_INT_0                                                   0x18014154
#define  TP_TP_RING_FULL_INT_0_reg_addr                                          "0xB8014154"
#define  TP_TP_RING_FULL_INT_0_reg                                               0xB8014154
#define  TP_TP_RING_FULL_INT_0_inst_addr                                         "0x0061"
#define  set_TP_TP_RING_FULL_INT_0_reg(data)                                     (*((volatile unsigned int*)TP_TP_RING_FULL_INT_0_reg)=data)
#define  get_TP_TP_RING_FULL_INT_0_reg                                           (*((volatile unsigned int*)TP_TP_RING_FULL_INT_0_reg))
#define  TP_TP_RING_FULL_INT_0_ring_full_15_shift                                (16)
#define  TP_TP_RING_FULL_INT_0_ring_full_14_shift                                (15)
#define  TP_TP_RING_FULL_INT_0_ring_full_13_shift                                (14)
#define  TP_TP_RING_FULL_INT_0_ring_full_12_shift                                (13)
#define  TP_TP_RING_FULL_INT_0_ring_full_11_shift                                (12)
#define  TP_TP_RING_FULL_INT_0_ring_full_10_shift                                (11)
#define  TP_TP_RING_FULL_INT_0_ring_full_9_shift                                 (10)
#define  TP_TP_RING_FULL_INT_0_ring_full_8_shift                                 (9)
#define  TP_TP_RING_FULL_INT_0_ring_full_7_shift                                 (8)
#define  TP_TP_RING_FULL_INT_0_ring_full_6_shift                                 (7)
#define  TP_TP_RING_FULL_INT_0_ring_full_5_shift                                 (6)
#define  TP_TP_RING_FULL_INT_0_ring_full_4_shift                                 (5)
#define  TP_TP_RING_FULL_INT_0_ring_full_3_shift                                 (4)
#define  TP_TP_RING_FULL_INT_0_ring_full_2_shift                                 (3)
#define  TP_TP_RING_FULL_INT_0_ring_full_1_shift                                 (2)
#define  TP_TP_RING_FULL_INT_0_ring_full_0_shift                                 (1)
#define  TP_TP_RING_FULL_INT_0_write_data_shift                                  (0)
#define  TP_TP_RING_FULL_INT_0_ring_full_15_mask                                 (0x00010000)
#define  TP_TP_RING_FULL_INT_0_ring_full_14_mask                                 (0x00008000)
#define  TP_TP_RING_FULL_INT_0_ring_full_13_mask                                 (0x00004000)
#define  TP_TP_RING_FULL_INT_0_ring_full_12_mask                                 (0x00002000)
#define  TP_TP_RING_FULL_INT_0_ring_full_11_mask                                 (0x00001000)
#define  TP_TP_RING_FULL_INT_0_ring_full_10_mask                                 (0x00000800)
#define  TP_TP_RING_FULL_INT_0_ring_full_9_mask                                  (0x00000400)
#define  TP_TP_RING_FULL_INT_0_ring_full_8_mask                                  (0x00000200)
#define  TP_TP_RING_FULL_INT_0_ring_full_7_mask                                  (0x00000100)
#define  TP_TP_RING_FULL_INT_0_ring_full_6_mask                                  (0x00000080)
#define  TP_TP_RING_FULL_INT_0_ring_full_5_mask                                  (0x00000040)
#define  TP_TP_RING_FULL_INT_0_ring_full_4_mask                                  (0x00000020)
#define  TP_TP_RING_FULL_INT_0_ring_full_3_mask                                  (0x00000010)
#define  TP_TP_RING_FULL_INT_0_ring_full_2_mask                                  (0x00000008)
#define  TP_TP_RING_FULL_INT_0_ring_full_1_mask                                  (0x00000004)
#define  TP_TP_RING_FULL_INT_0_ring_full_0_mask                                  (0x00000002)
#define  TP_TP_RING_FULL_INT_0_write_data_mask                                   (0x00000001)
#define  TP_TP_RING_FULL_INT_0_ring_full_15(data)                                (0x00010000&((data)<<16))
#define  TP_TP_RING_FULL_INT_0_ring_full_14(data)                                (0x00008000&((data)<<15))
#define  TP_TP_RING_FULL_INT_0_ring_full_13(data)                                (0x00004000&((data)<<14))
#define  TP_TP_RING_FULL_INT_0_ring_full_12(data)                                (0x00002000&((data)<<13))
#define  TP_TP_RING_FULL_INT_0_ring_full_11(data)                                (0x00001000&((data)<<12))
#define  TP_TP_RING_FULL_INT_0_ring_full_10(data)                                (0x00000800&((data)<<11))
#define  TP_TP_RING_FULL_INT_0_ring_full_9(data)                                 (0x00000400&((data)<<10))
#define  TP_TP_RING_FULL_INT_0_ring_full_8(data)                                 (0x00000200&((data)<<9))
#define  TP_TP_RING_FULL_INT_0_ring_full_7(data)                                 (0x00000100&((data)<<8))
#define  TP_TP_RING_FULL_INT_0_ring_full_6(data)                                 (0x00000080&((data)<<7))
#define  TP_TP_RING_FULL_INT_0_ring_full_5(data)                                 (0x00000040&((data)<<6))
#define  TP_TP_RING_FULL_INT_0_ring_full_4(data)                                 (0x00000020&((data)<<5))
#define  TP_TP_RING_FULL_INT_0_ring_full_3(data)                                 (0x00000010&((data)<<4))
#define  TP_TP_RING_FULL_INT_0_ring_full_2(data)                                 (0x00000008&((data)<<3))
#define  TP_TP_RING_FULL_INT_0_ring_full_1(data)                                 (0x00000004&((data)<<2))
#define  TP_TP_RING_FULL_INT_0_ring_full_0(data)                                 (0x00000002&((data)<<1))
#define  TP_TP_RING_FULL_INT_0_write_data(data)                                  (0x00000001&(data))
#define  TP_TP_RING_FULL_INT_0_get_ring_full_15(data)                            ((0x00010000&(data))>>16)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_14(data)                            ((0x00008000&(data))>>15)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_13(data)                            ((0x00004000&(data))>>14)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_12(data)                            ((0x00002000&(data))>>13)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_11(data)                            ((0x00001000&(data))>>12)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_10(data)                            ((0x00000800&(data))>>11)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_9(data)                             ((0x00000400&(data))>>10)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_8(data)                             ((0x00000200&(data))>>9)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_7(data)                             ((0x00000100&(data))>>8)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_6(data)                             ((0x00000080&(data))>>7)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_5(data)                             ((0x00000040&(data))>>6)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_4(data)                             ((0x00000020&(data))>>5)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_3(data)                             ((0x00000010&(data))>>4)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_2(data)                             ((0x00000008&(data))>>3)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_1(data)                             ((0x00000004&(data))>>2)
#define  TP_TP_RING_FULL_INT_0_get_ring_full_0(data)                             ((0x00000002&(data))>>1)
#define  TP_TP_RING_FULL_INT_0_get_write_data(data)                              (0x00000001&(data))

#define  TP_TP_RING_FULL_INT_1                                                   0x18014158
#define  TP_TP_RING_FULL_INT_1_reg_addr                                          "0xB8014158"
#define  TP_TP_RING_FULL_INT_1_reg                                               0xB8014158
#define  TP_TP_RING_FULL_INT_1_inst_addr                                         "0x0062"
#define  set_TP_TP_RING_FULL_INT_1_reg(data)                                     (*((volatile unsigned int*)TP_TP_RING_FULL_INT_1_reg)=data)
#define  get_TP_TP_RING_FULL_INT_1_reg                                           (*((volatile unsigned int*)TP_TP_RING_FULL_INT_1_reg))
#define  TP_TP_RING_FULL_INT_1_ring_full_15_shift                                (16)
#define  TP_TP_RING_FULL_INT_1_ring_full_14_shift                                (15)
#define  TP_TP_RING_FULL_INT_1_ring_full_13_shift                                (14)
#define  TP_TP_RING_FULL_INT_1_ring_full_12_shift                                (13)
#define  TP_TP_RING_FULL_INT_1_ring_full_11_shift                                (12)
#define  TP_TP_RING_FULL_INT_1_ring_full_10_shift                                (11)
#define  TP_TP_RING_FULL_INT_1_ring_full_9_shift                                 (10)
#define  TP_TP_RING_FULL_INT_1_ring_full_8_shift                                 (9)
#define  TP_TP_RING_FULL_INT_1_ring_full_7_shift                                 (8)
#define  TP_TP_RING_FULL_INT_1_ring_full_6_shift                                 (7)
#define  TP_TP_RING_FULL_INT_1_ring_full_5_shift                                 (6)
#define  TP_TP_RING_FULL_INT_1_ring_full_4_shift                                 (5)
#define  TP_TP_RING_FULL_INT_1_ring_full_3_shift                                 (4)
#define  TP_TP_RING_FULL_INT_1_ring_full_2_shift                                 (3)
#define  TP_TP_RING_FULL_INT_1_ring_full_1_shift                                 (2)
#define  TP_TP_RING_FULL_INT_1_ring_full_0_shift                                 (1)
#define  TP_TP_RING_FULL_INT_1_write_data_shift                                  (0)
#define  TP_TP_RING_FULL_INT_1_ring_full_15_mask                                 (0x00010000)
#define  TP_TP_RING_FULL_INT_1_ring_full_14_mask                                 (0x00008000)
#define  TP_TP_RING_FULL_INT_1_ring_full_13_mask                                 (0x00004000)
#define  TP_TP_RING_FULL_INT_1_ring_full_12_mask                                 (0x00002000)
#define  TP_TP_RING_FULL_INT_1_ring_full_11_mask                                 (0x00001000)
#define  TP_TP_RING_FULL_INT_1_ring_full_10_mask                                 (0x00000800)
#define  TP_TP_RING_FULL_INT_1_ring_full_9_mask                                  (0x00000400)
#define  TP_TP_RING_FULL_INT_1_ring_full_8_mask                                  (0x00000200)
#define  TP_TP_RING_FULL_INT_1_ring_full_7_mask                                  (0x00000100)
#define  TP_TP_RING_FULL_INT_1_ring_full_6_mask                                  (0x00000080)
#define  TP_TP_RING_FULL_INT_1_ring_full_5_mask                                  (0x00000040)
#define  TP_TP_RING_FULL_INT_1_ring_full_4_mask                                  (0x00000020)
#define  TP_TP_RING_FULL_INT_1_ring_full_3_mask                                  (0x00000010)
#define  TP_TP_RING_FULL_INT_1_ring_full_2_mask                                  (0x00000008)
#define  TP_TP_RING_FULL_INT_1_ring_full_1_mask                                  (0x00000004)
#define  TP_TP_RING_FULL_INT_1_ring_full_0_mask                                  (0x00000002)
#define  TP_TP_RING_FULL_INT_1_write_data_mask                                   (0x00000001)
#define  TP_TP_RING_FULL_INT_1_ring_full_15(data)                                (0x00010000&((data)<<16))
#define  TP_TP_RING_FULL_INT_1_ring_full_14(data)                                (0x00008000&((data)<<15))
#define  TP_TP_RING_FULL_INT_1_ring_full_13(data)                                (0x00004000&((data)<<14))
#define  TP_TP_RING_FULL_INT_1_ring_full_12(data)                                (0x00002000&((data)<<13))
#define  TP_TP_RING_FULL_INT_1_ring_full_11(data)                                (0x00001000&((data)<<12))
#define  TP_TP_RING_FULL_INT_1_ring_full_10(data)                                (0x00000800&((data)<<11))
#define  TP_TP_RING_FULL_INT_1_ring_full_9(data)                                 (0x00000400&((data)<<10))
#define  TP_TP_RING_FULL_INT_1_ring_full_8(data)                                 (0x00000200&((data)<<9))
#define  TP_TP_RING_FULL_INT_1_ring_full_7(data)                                 (0x00000100&((data)<<8))
#define  TP_TP_RING_FULL_INT_1_ring_full_6(data)                                 (0x00000080&((data)<<7))
#define  TP_TP_RING_FULL_INT_1_ring_full_5(data)                                 (0x00000040&((data)<<6))
#define  TP_TP_RING_FULL_INT_1_ring_full_4(data)                                 (0x00000020&((data)<<5))
#define  TP_TP_RING_FULL_INT_1_ring_full_3(data)                                 (0x00000010&((data)<<4))
#define  TP_TP_RING_FULL_INT_1_ring_full_2(data)                                 (0x00000008&((data)<<3))
#define  TP_TP_RING_FULL_INT_1_ring_full_1(data)                                 (0x00000004&((data)<<2))
#define  TP_TP_RING_FULL_INT_1_ring_full_0(data)                                 (0x00000002&((data)<<1))
#define  TP_TP_RING_FULL_INT_1_write_data(data)                                  (0x00000001&(data))
#define  TP_TP_RING_FULL_INT_1_get_ring_full_15(data)                            ((0x00010000&(data))>>16)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_14(data)                            ((0x00008000&(data))>>15)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_13(data)                            ((0x00004000&(data))>>14)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_12(data)                            ((0x00002000&(data))>>13)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_11(data)                            ((0x00001000&(data))>>12)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_10(data)                            ((0x00000800&(data))>>11)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_9(data)                             ((0x00000400&(data))>>10)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_8(data)                             ((0x00000200&(data))>>9)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_7(data)                             ((0x00000100&(data))>>8)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_6(data)                             ((0x00000080&(data))>>7)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_5(data)                             ((0x00000040&(data))>>6)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_4(data)                             ((0x00000020&(data))>>5)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_3(data)                             ((0x00000010&(data))>>4)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_2(data)                             ((0x00000008&(data))>>3)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_1(data)                             ((0x00000004&(data))>>2)
#define  TP_TP_RING_FULL_INT_1_get_ring_full_0(data)                             ((0x00000002&(data))>>1)
#define  TP_TP_RING_FULL_INT_1_get_write_data(data)                              (0x00000001&(data))

#define  TP_TP_RING_AVAIL_INT_EN_0                                               0x1801415C
#define  TP_TP_RING_AVAIL_INT_EN_0_reg_addr                                      "0xB801415C"
#define  TP_TP_RING_AVAIL_INT_EN_0_reg                                           0xB801415C
#define  TP_TP_RING_AVAIL_INT_EN_0_inst_addr                                     "0x0063"
#define  set_TP_TP_RING_AVAIL_INT_EN_0_reg(data)                                 (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_EN_0_reg)=data)
#define  get_TP_TP_RING_AVAIL_INT_EN_0_reg                                       (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_EN_0_reg))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_15_en_shift                        (16)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_14_en_shift                        (15)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_13_en_shift                        (14)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_12_en_shift                        (13)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_11_en_shift                        (12)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_10_en_shift                        (11)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_9_en_shift                         (10)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_8_en_shift                         (9)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_7_en_shift                         (8)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_6_en_shift                         (7)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_5_en_shift                         (6)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_4_en_shift                         (5)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_3_en_shift                         (4)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_2_en_shift                         (3)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_1_en_shift                         (2)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_0_en_shift                         (1)
#define  TP_TP_RING_AVAIL_INT_EN_0_write_data_shift                              (0)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_15_en_mask                         (0x00010000)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_14_en_mask                         (0x00008000)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_13_en_mask                         (0x00004000)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_12_en_mask                         (0x00002000)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_11_en_mask                         (0x00001000)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_10_en_mask                         (0x00000800)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_9_en_mask                          (0x00000400)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_8_en_mask                          (0x00000200)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_7_en_mask                          (0x00000100)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_6_en_mask                          (0x00000080)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_5_en_mask                          (0x00000040)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_4_en_mask                          (0x00000020)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_3_en_mask                          (0x00000010)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_2_en_mask                          (0x00000008)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_1_en_mask                          (0x00000004)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_0_en_mask                          (0x00000002)
#define  TP_TP_RING_AVAIL_INT_EN_0_write_data_mask                               (0x00000001)
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_15_en(data)                        (0x00010000&((data)<<16))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_14_en(data)                        (0x00008000&((data)<<15))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_13_en(data)                        (0x00004000&((data)<<14))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_12_en(data)                        (0x00002000&((data)<<13))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_11_en(data)                        (0x00001000&((data)<<12))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_10_en(data)                        (0x00000800&((data)<<11))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_9_en(data)                         (0x00000400&((data)<<10))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_8_en(data)                         (0x00000200&((data)<<9))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_7_en(data)                         (0x00000100&((data)<<8))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_6_en(data)                         (0x00000080&((data)<<7))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_5_en(data)                         (0x00000040&((data)<<6))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_4_en(data)                         (0x00000020&((data)<<5))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_3_en(data)                         (0x00000010&((data)<<4))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_2_en(data)                         (0x00000008&((data)<<3))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_1_en(data)                         (0x00000004&((data)<<2))
#define  TP_TP_RING_AVAIL_INT_EN_0_ring_avail_0_en(data)                         (0x00000002&((data)<<1))
#define  TP_TP_RING_AVAIL_INT_EN_0_write_data(data)                              (0x00000001&(data))
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_15_en(data)                    ((0x00010000&(data))>>16)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_14_en(data)                    ((0x00008000&(data))>>15)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_13_en(data)                    ((0x00004000&(data))>>14)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_12_en(data)                    ((0x00002000&(data))>>13)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_11_en(data)                    ((0x00001000&(data))>>12)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_10_en(data)                    ((0x00000800&(data))>>11)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_9_en(data)                     ((0x00000400&(data))>>10)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_8_en(data)                     ((0x00000200&(data))>>9)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_7_en(data)                     ((0x00000100&(data))>>8)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_6_en(data)                     ((0x00000080&(data))>>7)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_5_en(data)                     ((0x00000040&(data))>>6)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_4_en(data)                     ((0x00000020&(data))>>5)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_3_en(data)                     ((0x00000010&(data))>>4)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_2_en(data)                     ((0x00000008&(data))>>3)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_1_en(data)                     ((0x00000004&(data))>>2)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_ring_avail_0_en(data)                     ((0x00000002&(data))>>1)
#define  TP_TP_RING_AVAIL_INT_EN_0_get_write_data(data)                          (0x00000001&(data))

#define  TP_TP_RING_AVAIL_INT_EN_1                                               0x18014160
#define  TP_TP_RING_AVAIL_INT_EN_1_reg_addr                                      "0xB8014160"
#define  TP_TP_RING_AVAIL_INT_EN_1_reg                                           0xB8014160
#define  TP_TP_RING_AVAIL_INT_EN_1_inst_addr                                     "0x0064"
#define  set_TP_TP_RING_AVAIL_INT_EN_1_reg(data)                                 (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_EN_1_reg)=data)
#define  get_TP_TP_RING_AVAIL_INT_EN_1_reg                                       (*((volatile unsigned int*)TP_TP_RING_AVAIL_INT_EN_1_reg))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_15_en_shift                        (16)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_14_en_shift                        (15)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_13_en_shift                        (14)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_12_en_shift                        (13)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_11_en_shift                        (12)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_10_en_shift                        (11)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_9_en_shift                         (10)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_8_en_shift                         (9)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_7_en_shift                         (8)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_6_en_shift                         (7)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_5_en_shift                         (6)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_4_en_shift                         (5)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_3_en_shift                         (4)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_2_en_shift                         (3)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_1_en_shift                         (2)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_0_en_shift                         (1)
#define  TP_TP_RING_AVAIL_INT_EN_1_write_data_shift                              (0)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_15_en_mask                         (0x00010000)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_14_en_mask                         (0x00008000)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_13_en_mask                         (0x00004000)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_12_en_mask                         (0x00002000)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_11_en_mask                         (0x00001000)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_10_en_mask                         (0x00000800)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_9_en_mask                          (0x00000400)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_8_en_mask                          (0x00000200)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_7_en_mask                          (0x00000100)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_6_en_mask                          (0x00000080)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_5_en_mask                          (0x00000040)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_4_en_mask                          (0x00000020)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_3_en_mask                          (0x00000010)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_2_en_mask                          (0x00000008)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_1_en_mask                          (0x00000004)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_0_en_mask                          (0x00000002)
#define  TP_TP_RING_AVAIL_INT_EN_1_write_data_mask                               (0x00000001)
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_15_en(data)                        (0x00010000&((data)<<16))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_14_en(data)                        (0x00008000&((data)<<15))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_13_en(data)                        (0x00004000&((data)<<14))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_12_en(data)                        (0x00002000&((data)<<13))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_11_en(data)                        (0x00001000&((data)<<12))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_10_en(data)                        (0x00000800&((data)<<11))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_9_en(data)                         (0x00000400&((data)<<10))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_8_en(data)                         (0x00000200&((data)<<9))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_7_en(data)                         (0x00000100&((data)<<8))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_6_en(data)                         (0x00000080&((data)<<7))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_5_en(data)                         (0x00000040&((data)<<6))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_4_en(data)                         (0x00000020&((data)<<5))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_3_en(data)                         (0x00000010&((data)<<4))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_2_en(data)                         (0x00000008&((data)<<3))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_1_en(data)                         (0x00000004&((data)<<2))
#define  TP_TP_RING_AVAIL_INT_EN_1_ring_avail_0_en(data)                         (0x00000002&((data)<<1))
#define  TP_TP_RING_AVAIL_INT_EN_1_write_data(data)                              (0x00000001&(data))
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_15_en(data)                    ((0x00010000&(data))>>16)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_14_en(data)                    ((0x00008000&(data))>>15)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_13_en(data)                    ((0x00004000&(data))>>14)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_12_en(data)                    ((0x00002000&(data))>>13)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_11_en(data)                    ((0x00001000&(data))>>12)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_10_en(data)                    ((0x00000800&(data))>>11)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_9_en(data)                     ((0x00000400&(data))>>10)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_8_en(data)                     ((0x00000200&(data))>>9)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_7_en(data)                     ((0x00000100&(data))>>8)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_6_en(data)                     ((0x00000080&(data))>>7)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_5_en(data)                     ((0x00000040&(data))>>6)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_4_en(data)                     ((0x00000020&(data))>>5)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_3_en(data)                     ((0x00000010&(data))>>4)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_2_en(data)                     ((0x00000008&(data))>>3)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_1_en(data)                     ((0x00000004&(data))>>2)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_ring_avail_0_en(data)                     ((0x00000002&(data))>>1)
#define  TP_TP_RING_AVAIL_INT_EN_1_get_write_data(data)                          (0x00000001&(data))

#define  TP_TP_RING_FULL_INT_EN_0                                                0x18014164
#define  TP_TP_RING_FULL_INT_EN_0_reg_addr                                       "0xB8014164"
#define  TP_TP_RING_FULL_INT_EN_0_reg                                            0xB8014164
#define  TP_TP_RING_FULL_INT_EN_0_inst_addr                                      "0x0065"
#define  set_TP_TP_RING_FULL_INT_EN_0_reg(data)                                  (*((volatile unsigned int*)TP_TP_RING_FULL_INT_EN_0_reg)=data)
#define  get_TP_TP_RING_FULL_INT_EN_0_reg                                        (*((volatile unsigned int*)TP_TP_RING_FULL_INT_EN_0_reg))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_15_en_shift                          (16)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_14_en_shift                          (15)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_13_en_shift                          (14)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_12_en_shift                          (13)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_11_en_shift                          (12)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_10_en_shift                          (11)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_9_en_shift                           (10)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_8_en_shift                           (9)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_7_en_shift                           (8)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_6_en_shift                           (7)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_5_en_shift                           (6)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_4_en_shift                           (5)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_3_en_shift                           (4)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_2_en_shift                           (3)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_1_en_shift                           (2)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_0_en_shift                           (1)
#define  TP_TP_RING_FULL_INT_EN_0_write_data_shift                               (0)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_15_en_mask                           (0x00010000)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_14_en_mask                           (0x00008000)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_13_en_mask                           (0x00004000)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_12_en_mask                           (0x00002000)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_11_en_mask                           (0x00001000)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_10_en_mask                           (0x00000800)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_9_en_mask                            (0x00000400)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_8_en_mask                            (0x00000200)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_7_en_mask                            (0x00000100)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_6_en_mask                            (0x00000080)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_5_en_mask                            (0x00000040)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_4_en_mask                            (0x00000020)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_3_en_mask                            (0x00000010)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_2_en_mask                            (0x00000008)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_1_en_mask                            (0x00000004)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_0_en_mask                            (0x00000002)
#define  TP_TP_RING_FULL_INT_EN_0_write_data_mask                                (0x00000001)
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_15_en(data)                          (0x00010000&((data)<<16))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_14_en(data)                          (0x00008000&((data)<<15))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_13_en(data)                          (0x00004000&((data)<<14))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_12_en(data)                          (0x00002000&((data)<<13))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_11_en(data)                          (0x00001000&((data)<<12))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_10_en(data)                          (0x00000800&((data)<<11))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_9_en(data)                           (0x00000400&((data)<<10))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_8_en(data)                           (0x00000200&((data)<<9))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_7_en(data)                           (0x00000100&((data)<<8))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_6_en(data)                           (0x00000080&((data)<<7))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_5_en(data)                           (0x00000040&((data)<<6))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_4_en(data)                           (0x00000020&((data)<<5))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_3_en(data)                           (0x00000010&((data)<<4))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_2_en(data)                           (0x00000008&((data)<<3))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_1_en(data)                           (0x00000004&((data)<<2))
#define  TP_TP_RING_FULL_INT_EN_0_ring_full_0_en(data)                           (0x00000002&((data)<<1))
#define  TP_TP_RING_FULL_INT_EN_0_write_data(data)                               (0x00000001&(data))
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_15_en(data)                      ((0x00010000&(data))>>16)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_14_en(data)                      ((0x00008000&(data))>>15)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_13_en(data)                      ((0x00004000&(data))>>14)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_12_en(data)                      ((0x00002000&(data))>>13)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_11_en(data)                      ((0x00001000&(data))>>12)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_10_en(data)                      ((0x00000800&(data))>>11)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_9_en(data)                       ((0x00000400&(data))>>10)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_8_en(data)                       ((0x00000200&(data))>>9)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_7_en(data)                       ((0x00000100&(data))>>8)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_6_en(data)                       ((0x00000080&(data))>>7)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_5_en(data)                       ((0x00000040&(data))>>6)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_4_en(data)                       ((0x00000020&(data))>>5)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_3_en(data)                       ((0x00000010&(data))>>4)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_2_en(data)                       ((0x00000008&(data))>>3)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_1_en(data)                       ((0x00000004&(data))>>2)
#define  TP_TP_RING_FULL_INT_EN_0_get_ring_full_0_en(data)                       ((0x00000002&(data))>>1)
#define  TP_TP_RING_FULL_INT_EN_0_get_write_data(data)                           (0x00000001&(data))

#define  TP_TP_RING_FULL_INT_EN_1                                                0x18014168
#define  TP_TP_RING_FULL_INT_EN_1_reg_addr                                       "0xB8014168"
#define  TP_TP_RING_FULL_INT_EN_1_reg                                            0xB8014168
#define  TP_TP_RING_FULL_INT_EN_1_inst_addr                                      "0x0066"
#define  set_TP_TP_RING_FULL_INT_EN_1_reg(data)                                  (*((volatile unsigned int*)TP_TP_RING_FULL_INT_EN_1_reg)=data)
#define  get_TP_TP_RING_FULL_INT_EN_1_reg                                        (*((volatile unsigned int*)TP_TP_RING_FULL_INT_EN_1_reg))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_15_en_shift                          (16)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_14_en_shift                          (15)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_13_en_shift                          (14)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_12_en_shift                          (13)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_11_en_shift                          (12)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_10_en_shift                          (11)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_9_en_shift                           (10)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_8_en_shift                           (9)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_7_en_shift                           (8)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_6_en_shift                           (7)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_5_en_shift                           (6)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_4_en_shift                           (5)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_3_en_shift                           (4)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_2_en_shift                           (3)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_1_en_shift                           (2)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_0_en_shift                           (1)
#define  TP_TP_RING_FULL_INT_EN_1_write_data_shift                               (0)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_15_en_mask                           (0x00010000)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_14_en_mask                           (0x00008000)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_13_en_mask                           (0x00004000)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_12_en_mask                           (0x00002000)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_11_en_mask                           (0x00001000)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_10_en_mask                           (0x00000800)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_9_en_mask                            (0x00000400)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_8_en_mask                            (0x00000200)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_7_en_mask                            (0x00000100)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_6_en_mask                            (0x00000080)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_5_en_mask                            (0x00000040)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_4_en_mask                            (0x00000020)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_3_en_mask                            (0x00000010)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_2_en_mask                            (0x00000008)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_1_en_mask                            (0x00000004)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_0_en_mask                            (0x00000002)
#define  TP_TP_RING_FULL_INT_EN_1_write_data_mask                                (0x00000001)
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_15_en(data)                          (0x00010000&((data)<<16))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_14_en(data)                          (0x00008000&((data)<<15))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_13_en(data)                          (0x00004000&((data)<<14))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_12_en(data)                          (0x00002000&((data)<<13))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_11_en(data)                          (0x00001000&((data)<<12))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_10_en(data)                          (0x00000800&((data)<<11))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_9_en(data)                           (0x00000400&((data)<<10))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_8_en(data)                           (0x00000200&((data)<<9))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_7_en(data)                           (0x00000100&((data)<<8))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_6_en(data)                           (0x00000080&((data)<<7))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_5_en(data)                           (0x00000040&((data)<<6))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_4_en(data)                           (0x00000020&((data)<<5))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_3_en(data)                           (0x00000010&((data)<<4))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_2_en(data)                           (0x00000008&((data)<<3))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_1_en(data)                           (0x00000004&((data)<<2))
#define  TP_TP_RING_FULL_INT_EN_1_ring_full_0_en(data)                           (0x00000002&((data)<<1))
#define  TP_TP_RING_FULL_INT_EN_1_write_data(data)                               (0x00000001&(data))
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_15_en(data)                      ((0x00010000&(data))>>16)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_14_en(data)                      ((0x00008000&(data))>>15)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_13_en(data)                      ((0x00004000&(data))>>14)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_12_en(data)                      ((0x00002000&(data))>>13)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_11_en(data)                      ((0x00001000&(data))>>12)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_10_en(data)                      ((0x00000800&(data))>>11)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_9_en(data)                       ((0x00000400&(data))>>10)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_8_en(data)                       ((0x00000200&(data))>>9)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_7_en(data)                       ((0x00000100&(data))>>8)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_6_en(data)                       ((0x00000080&(data))>>7)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_5_en(data)                       ((0x00000040&(data))>>6)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_4_en(data)                       ((0x00000020&(data))>>5)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_3_en(data)                       ((0x00000010&(data))>>4)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_2_en(data)                       ((0x00000008&(data))>>3)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_1_en(data)                       ((0x00000004&(data))>>2)
#define  TP_TP_RING_FULL_INT_EN_1_get_ring_full_0_en(data)                       ((0x00000002&(data))>>1)
#define  TP_TP_RING_FULL_INT_EN_1_get_write_data(data)                           (0x00000001&(data))

#define  TP_TP_SYNC_POS                                                          0x18014180
#define  TP_TP_SYNC_POS_reg_addr                                                 "0xB8014180"
#define  TP_TP_SYNC_POS_reg                                                      0xB8014180
#define  TP_TP_SYNC_POS_inst_addr                                                "0x0067"
#define  set_TP_TP_SYNC_POS_reg(data)                                            (*((volatile unsigned int*)TP_TP_SYNC_POS_reg)=data)
#define  get_TP_TP_SYNC_POS_reg                                                  (*((volatile unsigned int*)TP_TP_SYNC_POS_reg))
#define  TP_TP_SYNC_POS_sync_pos_shift                                           (0)
#define  TP_TP_SYNC_POS_sync_pos_mask                                            (0xFFFFFFFF)
#define  TP_TP_SYNC_POS_sync_pos(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_SYNC_POS_get_sync_pos(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_DMY_A                                                             0x18014184
#define  TP_TP_DMY_A_reg_addr                                                    "0xB8014184"
#define  TP_TP_DMY_A_reg                                                         0xB8014184
#define  TP_TP_DMY_A_inst_addr                                                   "0x0068"
#define  set_TP_TP_DMY_A_reg(data)                                               (*((volatile unsigned int*)TP_TP_DMY_A_reg)=data)
#define  get_TP_TP_DMY_A_reg                                                     (*((volatile unsigned int*)TP_TP_DMY_A_reg))
#define  TP_TP_DMY_A_dmy_shift                                                   (0)
#define  TP_TP_DMY_A_dmy_mask                                                    (0xFFFFFFFF)
#define  TP_TP_DMY_A_dmy(data)                                                   (0xFFFFFFFF&(data))
#define  TP_TP_DMY_A_get_dmy(data)                                               (0xFFFFFFFF&(data))

#define  TP_TP_DMY_B                                                             0x18014188
#define  TP_TP_DMY_B_reg_addr                                                    "0xB8014188"
#define  TP_TP_DMY_B_reg                                                         0xB8014188
#define  TP_TP_DMY_B_inst_addr                                                   "0x0069"
#define  set_TP_TP_DMY_B_reg(data)                                               (*((volatile unsigned int*)TP_TP_DMY_B_reg)=data)
#define  get_TP_TP_DMY_B_reg                                                     (*((volatile unsigned int*)TP_TP_DMY_B_reg))
#define  TP_TP_DMY_B_dmy_shift                                                   (0)
#define  TP_TP_DMY_B_dmy_mask                                                    (0xFFFFFFFF)
#define  TP_TP_DMY_B_dmy(data)                                                   (0xFFFFFFFF&(data))
#define  TP_TP_DMY_B_get_dmy(data)                                               (0xFFFFFFFF&(data))

#define  TP_TP_BIST_MODE                                                         0x18014190
#define  TP_TP_BIST_MODE_reg_addr                                                "0xB8014190"
#define  TP_TP_BIST_MODE_reg                                                     0xB8014190
#define  TP_TP_BIST_MODE_inst_addr                                               "0x006A"
#define  set_TP_TP_BIST_MODE_reg(data)                                           (*((volatile unsigned int*)TP_TP_BIST_MODE_reg)=data)
#define  get_TP_TP_BIST_MODE_reg                                                 (*((volatile unsigned int*)TP_TP_BIST_MODE_reg))
#define  TP_TP_BIST_MODE_ls_shift                                                (1)
#define  TP_TP_BIST_MODE_bist_mode_tp_shift                                      (0)
#define  TP_TP_BIST_MODE_ls_mask                                                 (0x00000002)
#define  TP_TP_BIST_MODE_bist_mode_tp_mask                                       (0x00000001)
#define  TP_TP_BIST_MODE_ls(data)                                                (0x00000002&((data)<<1))
#define  TP_TP_BIST_MODE_bist_mode_tp(data)                                      (0x00000001&(data))
#define  TP_TP_BIST_MODE_get_ls(data)                                            ((0x00000002&(data))>>1)
#define  TP_TP_BIST_MODE_get_bist_mode_tp(data)                                  (0x00000001&(data))

#define  TP_tp_bist_done                                                         0x18014194
#define  TP_tp_bist_done_reg_addr                                                "0xB8014194"
#define  TP_tp_bist_done_reg                                                     0xB8014194
#define  TP_tp_bist_done_inst_addr                                               "0x006B"
#define  set_TP_tp_bist_done_reg(data)                                           (*((volatile unsigned int*)TP_tp_bist_done_reg)=data)
#define  get_TP_tp_bist_done_reg                                                 (*((volatile unsigned int*)TP_tp_bist_done_reg))
#define  TP_tp_bist_done_bist_done_tp_shift                                      (0)
#define  TP_tp_bist_done_bist_done_tp_mask                                       (0x00000001)
#define  TP_tp_bist_done_bist_done_tp(data)                                      (0x00000001&(data))
#define  TP_tp_bist_done_get_bist_done_tp(data)                                  (0x00000001&(data))

#define  TP_tp_bist_fail_group                                                   0x18014198
#define  TP_tp_bist_fail_group_reg_addr                                          "0xB8014198"
#define  TP_tp_bist_fail_group_reg                                               0xB8014198
#define  TP_tp_bist_fail_group_inst_addr                                         "0x006C"
#define  set_TP_tp_bist_fail_group_reg(data)                                     (*((volatile unsigned int*)TP_tp_bist_fail_group_reg)=data)
#define  get_TP_tp_bist_fail_group_reg                                           (*((volatile unsigned int*)TP_tp_bist_fail_group_reg))
#define  TP_tp_bist_fail_group_tp_bist_fail_group_tp_shift                       (0)
#define  TP_tp_bist_fail_group_tp_bist_fail_group_tp_mask                        (0x00000001)
#define  TP_tp_bist_fail_group_tp_bist_fail_group_tp(data)                       (0x00000001&(data))
#define  TP_tp_bist_fail_group_get_tp_bist_fail_group_tp(data)                   (0x00000001&(data))

#define  TP_tp_bist_fail                                                         0x1801419C
#define  TP_tp_bist_fail_reg_addr                                                "0xB801419C"
#define  TP_tp_bist_fail_reg                                                     0xB801419C
#define  TP_tp_bist_fail_inst_addr                                               "0x006D"
#define  set_TP_tp_bist_fail_reg(data)                                           (*((volatile unsigned int*)TP_tp_bist_fail_reg)=data)
#define  get_TP_tp_bist_fail_reg                                                 (*((volatile unsigned int*)TP_tp_bist_fail_reg))
#define  TP_tp_bist_fail_atsc_dma_shift                                          (13)
#define  TP_tp_bist_fail_tp_dma_4_shift                                          (12)
#define  TP_tp_bist_fail_tp_dma_0_shift                                          (11)
#define  TP_tp_bist_fail_tp_dma_1_shift                                          (10)
#define  TP_tp_bist_fail_tp_dma_2_shift                                          (9)
#define  TP_tp_bist_fail_tp_dma_3_shift                                          (8)
#define  TP_tp_bist_fail_tpp_dma_0_shift                                         (7)
#define  TP_tp_bist_fail_tpp_dma_1_shift                                         (6)
#define  TP_tp_bist_fail_tpp_dma_2_shift                                         (5)
#define  TP_tp_bist_fail_tpp_dma_3_shift                                         (4)
#define  TP_tp_bist_fail_ring_shift                                              (3)
#define  TP_tp_bist_fail_pid_shift                                               (2)
#define  TP_tp_bist_fail_sect_shift                                              (1)
#define  TP_tp_bist_fail_key_shift                                               (0)
#define  TP_tp_bist_fail_atsc_dma_mask                                           (0x00002000)
#define  TP_tp_bist_fail_tp_dma_4_mask                                           (0x00001000)
#define  TP_tp_bist_fail_tp_dma_0_mask                                           (0x00000800)
#define  TP_tp_bist_fail_tp_dma_1_mask                                           (0x00000400)
#define  TP_tp_bist_fail_tp_dma_2_mask                                           (0x00000200)
#define  TP_tp_bist_fail_tp_dma_3_mask                                           (0x00000100)
#define  TP_tp_bist_fail_tpp_dma_0_mask                                          (0x00000080)
#define  TP_tp_bist_fail_tpp_dma_1_mask                                          (0x00000040)
#define  TP_tp_bist_fail_tpp_dma_2_mask                                          (0x00000020)
#define  TP_tp_bist_fail_tpp_dma_3_mask                                          (0x00000010)
#define  TP_tp_bist_fail_ring_mask                                               (0x00000008)
#define  TP_tp_bist_fail_pid_mask                                                (0x00000004)
#define  TP_tp_bist_fail_sect_mask                                               (0x00000002)
#define  TP_tp_bist_fail_key_mask                                                (0x00000001)
#define  TP_tp_bist_fail_atsc_dma(data)                                          (0x00002000&((data)<<13))
#define  TP_tp_bist_fail_tp_dma_4(data)                                          (0x00001000&((data)<<12))
#define  TP_tp_bist_fail_tp_dma_0(data)                                          (0x00000800&((data)<<11))
#define  TP_tp_bist_fail_tp_dma_1(data)                                          (0x00000400&((data)<<10))
#define  TP_tp_bist_fail_tp_dma_2(data)                                          (0x00000200&((data)<<9))
#define  TP_tp_bist_fail_tp_dma_3(data)                                          (0x00000100&((data)<<8))
#define  TP_tp_bist_fail_tpp_dma_0(data)                                         (0x00000080&((data)<<7))
#define  TP_tp_bist_fail_tpp_dma_1(data)                                         (0x00000040&((data)<<6))
#define  TP_tp_bist_fail_tpp_dma_2(data)                                         (0x00000020&((data)<<5))
#define  TP_tp_bist_fail_tpp_dma_3(data)                                         (0x00000010&((data)<<4))
#define  TP_tp_bist_fail_ring(data)                                              (0x00000008&((data)<<3))
#define  TP_tp_bist_fail_pid(data)                                               (0x00000004&((data)<<2))
#define  TP_tp_bist_fail_sect(data)                                              (0x00000002&((data)<<1))
#define  TP_tp_bist_fail_key(data)                                               (0x00000001&(data))
#define  TP_tp_bist_fail_get_atsc_dma(data)                                      ((0x00002000&(data))>>13)
#define  TP_tp_bist_fail_get_tp_dma_4(data)                                      ((0x00001000&(data))>>12)
#define  TP_tp_bist_fail_get_tp_dma_0(data)                                      ((0x00000800&(data))>>11)
#define  TP_tp_bist_fail_get_tp_dma_1(data)                                      ((0x00000400&(data))>>10)
#define  TP_tp_bist_fail_get_tp_dma_2(data)                                      ((0x00000200&(data))>>9)
#define  TP_tp_bist_fail_get_tp_dma_3(data)                                      ((0x00000100&(data))>>8)
#define  TP_tp_bist_fail_get_tpp_dma_0(data)                                     ((0x00000080&(data))>>7)
#define  TP_tp_bist_fail_get_tpp_dma_1(data)                                     ((0x00000040&(data))>>6)
#define  TP_tp_bist_fail_get_tpp_dma_2(data)                                     ((0x00000020&(data))>>5)
#define  TP_tp_bist_fail_get_tpp_dma_3(data)                                     ((0x00000010&(data))>>4)
#define  TP_tp_bist_fail_get_ring(data)                                          ((0x00000008&(data))>>3)
#define  TP_tp_bist_fail_get_pid(data)                                           ((0x00000004&(data))>>2)
#define  TP_tp_bist_fail_get_sect(data)                                          ((0x00000002&(data))>>1)
#define  TP_tp_bist_fail_get_key(data)                                           (0x00000001&(data))

#define  TP_TP_DRF_MODE                                                          0x180141A0
#define  TP_TP_DRF_MODE_reg_addr                                                 "0xB80141A0"
#define  TP_TP_DRF_MODE_reg                                                      0xB80141A0
#define  TP_TP_DRF_MODE_inst_addr                                                "0x006E"
#define  set_TP_TP_DRF_MODE_reg(data)                                            (*((volatile unsigned int*)TP_TP_DRF_MODE_reg)=data)
#define  get_TP_TP_DRF_MODE_reg                                                  (*((volatile unsigned int*)TP_TP_DRF_MODE_reg))
#define  TP_TP_DRF_MODE_drf_mode_tp_shift                                        (0)
#define  TP_TP_DRF_MODE_drf_mode_tp_mask                                         (0x00000001)
#define  TP_TP_DRF_MODE_drf_mode_tp(data)                                        (0x00000001&(data))
#define  TP_TP_DRF_MODE_get_drf_mode_tp(data)                                    (0x00000001&(data))

#define  TP_tp_drf_resume                                                        0x180141A4
#define  TP_tp_drf_resume_reg_addr                                               "0xB80141A4"
#define  TP_tp_drf_resume_reg                                                    0xB80141A4
#define  TP_tp_drf_resume_inst_addr                                              "0x006F"
#define  set_TP_tp_drf_resume_reg(data)                                          (*((volatile unsigned int*)TP_tp_drf_resume_reg)=data)
#define  get_TP_tp_drf_resume_reg                                                (*((volatile unsigned int*)TP_tp_drf_resume_reg))
#define  TP_tp_drf_resume_drf_resume_tp_shift                                    (0)
#define  TP_tp_drf_resume_drf_resume_tp_mask                                     (0x00000001)
#define  TP_tp_drf_resume_drf_resume_tp(data)                                    (0x00000001&(data))
#define  TP_tp_drf_resume_get_drf_resume_tp(data)                                (0x00000001&(data))

#define  TP_tp_drf_done                                                          0x180141A8
#define  TP_tp_drf_done_reg_addr                                                 "0xB80141A8"
#define  TP_tp_drf_done_reg                                                      0xB80141A8
#define  TP_tp_drf_done_inst_addr                                                "0x0070"
#define  set_TP_tp_drf_done_reg(data)                                            (*((volatile unsigned int*)TP_tp_drf_done_reg)=data)
#define  get_TP_tp_drf_done_reg                                                  (*((volatile unsigned int*)TP_tp_drf_done_reg))
#define  TP_tp_drf_done_drf_done_tp_shift                                        (0)
#define  TP_tp_drf_done_drf_done_tp_mask                                         (0x00000001)
#define  TP_tp_drf_done_drf_done_tp(data)                                        (0x00000001&(data))
#define  TP_tp_drf_done_get_drf_done_tp(data)                                    (0x00000001&(data))

#define  TP_tp_drf_pause                                                         0x180141AC
#define  TP_tp_drf_pause_reg_addr                                                "0xB80141AC"
#define  TP_tp_drf_pause_reg                                                     0xB80141AC
#define  TP_tp_drf_pause_inst_addr                                               "0x0071"
#define  set_TP_tp_drf_pause_reg(data)                                           (*((volatile unsigned int*)TP_tp_drf_pause_reg)=data)
#define  get_TP_tp_drf_pause_reg                                                 (*((volatile unsigned int*)TP_tp_drf_pause_reg))
#define  TP_tp_drf_pause_drf_pause_tp_shift                                      (0)
#define  TP_tp_drf_pause_drf_pause_tp_mask                                       (0x00000001)
#define  TP_tp_drf_pause_drf_pause_tp(data)                                      (0x00000001&(data))
#define  TP_tp_drf_pause_get_drf_pause_tp(data)                                  (0x00000001&(data))

#define  TP_tp_drf_fail_group                                                    0x180141B0
#define  TP_tp_drf_fail_group_reg_addr                                           "0xB80141B0"
#define  TP_tp_drf_fail_group_reg                                                0xB80141B0
#define  TP_tp_drf_fail_group_inst_addr                                          "0x0072"
#define  set_TP_tp_drf_fail_group_reg(data)                                      (*((volatile unsigned int*)TP_tp_drf_fail_group_reg)=data)
#define  get_TP_tp_drf_fail_group_reg                                            (*((volatile unsigned int*)TP_tp_drf_fail_group_reg))
#define  TP_tp_drf_fail_group_drf_fail_group_tp_shift                            (0)
#define  TP_tp_drf_fail_group_drf_fail_group_tp_mask                             (0x00000001)
#define  TP_tp_drf_fail_group_drf_fail_group_tp(data)                            (0x00000001&(data))
#define  TP_tp_drf_fail_group_get_drf_fail_group_tp(data)                        (0x00000001&(data))

#define  TP_tp_drf_fail                                                          0x180141B4
#define  TP_tp_drf_fail_reg_addr                                                 "0xB80141B4"
#define  TP_tp_drf_fail_reg                                                      0xB80141B4
#define  TP_tp_drf_fail_inst_addr                                                "0x0073"
#define  set_TP_tp_drf_fail_reg(data)                                            (*((volatile unsigned int*)TP_tp_drf_fail_reg)=data)
#define  get_TP_tp_drf_fail_reg                                                  (*((volatile unsigned int*)TP_tp_drf_fail_reg))
#define  TP_tp_drf_fail_atsc_dma_shift                                           (13)
#define  TP_tp_drf_fail_tp_dma_4_shift                                           (12)
#define  TP_tp_drf_fail_tp_dma_0_shift                                           (11)
#define  TP_tp_drf_fail_tp_dma_1_shift                                           (10)
#define  TP_tp_drf_fail_tp_dma_2_shift                                           (9)
#define  TP_tp_drf_fail_tp_dma_3_shift                                           (8)
#define  TP_tp_drf_fail_tpp_dma_0_shift                                          (7)
#define  TP_tp_drf_fail_tpp_dma_1_shift                                          (6)
#define  TP_tp_drf_fail_tpp_dma_2_shift                                          (5)
#define  TP_tp_drf_fail_tpp_dma_3_shift                                          (4)
#define  TP_tp_drf_fail_ring_shift                                               (3)
#define  TP_tp_drf_fail_pid_shift                                                (2)
#define  TP_tp_drf_fail_sect_shift                                               (1)
#define  TP_tp_drf_fail_key_shift                                                (0)
#define  TP_tp_drf_fail_atsc_dma_mask                                            (0x00002000)
#define  TP_tp_drf_fail_tp_dma_4_mask                                            (0x00001000)
#define  TP_tp_drf_fail_tp_dma_0_mask                                            (0x00000800)
#define  TP_tp_drf_fail_tp_dma_1_mask                                            (0x00000400)
#define  TP_tp_drf_fail_tp_dma_2_mask                                            (0x00000200)
#define  TP_tp_drf_fail_tp_dma_3_mask                                            (0x00000100)
#define  TP_tp_drf_fail_tpp_dma_0_mask                                           (0x00000080)
#define  TP_tp_drf_fail_tpp_dma_1_mask                                           (0x00000040)
#define  TP_tp_drf_fail_tpp_dma_2_mask                                           (0x00000020)
#define  TP_tp_drf_fail_tpp_dma_3_mask                                           (0x00000010)
#define  TP_tp_drf_fail_ring_mask                                                (0x00000008)
#define  TP_tp_drf_fail_pid_mask                                                 (0x00000004)
#define  TP_tp_drf_fail_sect_mask                                                (0x00000002)
#define  TP_tp_drf_fail_key_mask                                                 (0x00000001)
#define  TP_tp_drf_fail_atsc_dma(data)                                           (0x00002000&((data)<<13))
#define  TP_tp_drf_fail_tp_dma_4(data)                                           (0x00001000&((data)<<12))
#define  TP_tp_drf_fail_tp_dma_0(data)                                           (0x00000800&((data)<<11))
#define  TP_tp_drf_fail_tp_dma_1(data)                                           (0x00000400&((data)<<10))
#define  TP_tp_drf_fail_tp_dma_2(data)                                           (0x00000200&((data)<<9))
#define  TP_tp_drf_fail_tp_dma_3(data)                                           (0x00000100&((data)<<8))
#define  TP_tp_drf_fail_tpp_dma_0(data)                                          (0x00000080&((data)<<7))
#define  TP_tp_drf_fail_tpp_dma_1(data)                                          (0x00000040&((data)<<6))
#define  TP_tp_drf_fail_tpp_dma_2(data)                                          (0x00000020&((data)<<5))
#define  TP_tp_drf_fail_tpp_dma_3(data)                                          (0x00000010&((data)<<4))
#define  TP_tp_drf_fail_ring(data)                                               (0x00000008&((data)<<3))
#define  TP_tp_drf_fail_pid(data)                                                (0x00000004&((data)<<2))
#define  TP_tp_drf_fail_sect(data)                                               (0x00000002&((data)<<1))
#define  TP_tp_drf_fail_key(data)                                                (0x00000001&(data))
#define  TP_tp_drf_fail_get_atsc_dma(data)                                       ((0x00002000&(data))>>13)
#define  TP_tp_drf_fail_get_tp_dma_4(data)                                       ((0x00001000&(data))>>12)
#define  TP_tp_drf_fail_get_tp_dma_0(data)                                       ((0x00000800&(data))>>11)
#define  TP_tp_drf_fail_get_tp_dma_1(data)                                       ((0x00000400&(data))>>10)
#define  TP_tp_drf_fail_get_tp_dma_2(data)                                       ((0x00000200&(data))>>9)
#define  TP_tp_drf_fail_get_tp_dma_3(data)                                       ((0x00000100&(data))>>8)
#define  TP_tp_drf_fail_get_tpp_dma_0(data)                                      ((0x00000080&(data))>>7)
#define  TP_tp_drf_fail_get_tpp_dma_1(data)                                      ((0x00000040&(data))>>6)
#define  TP_tp_drf_fail_get_tpp_dma_2(data)                                      ((0x00000020&(data))>>5)
#define  TP_tp_drf_fail_get_tpp_dma_3(data)                                      ((0x00000010&(data))>>4)
#define  TP_tp_drf_fail_get_ring(data)                                           ((0x00000008&(data))>>3)
#define  TP_tp_drf_fail_get_pid(data)                                            ((0x00000004&(data))>>2)
#define  TP_tp_drf_fail_get_sect(data)                                           ((0x00000002&(data))>>1)
#define  TP_tp_drf_fail_get_key(data)                                            (0x00000001&(data))

#define  TP_tp_bist_dvse                                                         0x180141B8
#define  TP_tp_bist_dvse_reg_addr                                                "0xB80141B8"
#define  TP_tp_bist_dvse_reg                                                     0xB80141B8
#define  TP_tp_bist_dvse_inst_addr                                               "0x0074"
#define  set_TP_tp_bist_dvse_reg(data)                                           (*((volatile unsigned int*)TP_tp_bist_dvse_reg)=data)
#define  get_TP_tp_bist_dvse_reg                                                 (*((volatile unsigned int*)TP_tp_bist_dvse_reg))
#define  TP_tp_bist_dvse_atsc_dma_shift                                          (13)
#define  TP_tp_bist_dvse_tp_dma_4_shift                                          (12)
#define  TP_tp_bist_dvse_tp_dma_0_shift                                          (11)
#define  TP_tp_bist_dvse_tp_dma_1_shift                                          (10)
#define  TP_tp_bist_dvse_tp_dma_2_shift                                          (9)
#define  TP_tp_bist_dvse_tp_dma_3_shift                                          (8)
#define  TP_tp_bist_dvse_tpp_dma_0_shift                                         (7)
#define  TP_tp_bist_dvse_tpp_dma_1_shift                                         (6)
#define  TP_tp_bist_dvse_tpp_dma_2_shift                                         (5)
#define  TP_tp_bist_dvse_tpp_dma_3_shift                                         (4)
#define  TP_tp_bist_dvse_ring_shift                                              (3)
#define  TP_tp_bist_dvse_pid_shift                                               (2)
#define  TP_tp_bist_dvse_sect_shift                                              (1)
#define  TP_tp_bist_dvse_key_shift                                               (0)
#define  TP_tp_bist_dvse_atsc_dma_mask                                           (0x00002000)
#define  TP_tp_bist_dvse_tp_dma_4_mask                                           (0x00001000)
#define  TP_tp_bist_dvse_tp_dma_0_mask                                           (0x00000800)
#define  TP_tp_bist_dvse_tp_dma_1_mask                                           (0x00000400)
#define  TP_tp_bist_dvse_tp_dma_2_mask                                           (0x00000200)
#define  TP_tp_bist_dvse_tp_dma_3_mask                                           (0x00000100)
#define  TP_tp_bist_dvse_tpp_dma_0_mask                                          (0x00000080)
#define  TP_tp_bist_dvse_tpp_dma_1_mask                                          (0x00000040)
#define  TP_tp_bist_dvse_tpp_dma_2_mask                                          (0x00000020)
#define  TP_tp_bist_dvse_tpp_dma_3_mask                                          (0x00000010)
#define  TP_tp_bist_dvse_ring_mask                                               (0x00000008)
#define  TP_tp_bist_dvse_pid_mask                                                (0x00000004)
#define  TP_tp_bist_dvse_sect_mask                                               (0x00000002)
#define  TP_tp_bist_dvse_key_mask                                                (0x00000001)
#define  TP_tp_bist_dvse_atsc_dma(data)                                          (0x00002000&((data)<<13))
#define  TP_tp_bist_dvse_tp_dma_4(data)                                          (0x00001000&((data)<<12))
#define  TP_tp_bist_dvse_tp_dma_0(data)                                          (0x00000800&((data)<<11))
#define  TP_tp_bist_dvse_tp_dma_1(data)                                          (0x00000400&((data)<<10))
#define  TP_tp_bist_dvse_tp_dma_2(data)                                          (0x00000200&((data)<<9))
#define  TP_tp_bist_dvse_tp_dma_3(data)                                          (0x00000100&((data)<<8))
#define  TP_tp_bist_dvse_tpp_dma_0(data)                                         (0x00000080&((data)<<7))
#define  TP_tp_bist_dvse_tpp_dma_1(data)                                         (0x00000040&((data)<<6))
#define  TP_tp_bist_dvse_tpp_dma_2(data)                                         (0x00000020&((data)<<5))
#define  TP_tp_bist_dvse_tpp_dma_3(data)                                         (0x00000010&((data)<<4))
#define  TP_tp_bist_dvse_ring(data)                                              (0x00000008&((data)<<3))
#define  TP_tp_bist_dvse_pid(data)                                               (0x00000004&((data)<<2))
#define  TP_tp_bist_dvse_sect(data)                                              (0x00000002&((data)<<1))
#define  TP_tp_bist_dvse_key(data)                                               (0x00000001&(data))
#define  TP_tp_bist_dvse_get_atsc_dma(data)                                      ((0x00002000&(data))>>13)
#define  TP_tp_bist_dvse_get_tp_dma_4(data)                                      ((0x00001000&(data))>>12)
#define  TP_tp_bist_dvse_get_tp_dma_0(data)                                      ((0x00000800&(data))>>11)
#define  TP_tp_bist_dvse_get_tp_dma_1(data)                                      ((0x00000400&(data))>>10)
#define  TP_tp_bist_dvse_get_tp_dma_2(data)                                      ((0x00000200&(data))>>9)
#define  TP_tp_bist_dvse_get_tp_dma_3(data)                                      ((0x00000100&(data))>>8)
#define  TP_tp_bist_dvse_get_tpp_dma_0(data)                                     ((0x00000080&(data))>>7)
#define  TP_tp_bist_dvse_get_tpp_dma_1(data)                                     ((0x00000040&(data))>>6)
#define  TP_tp_bist_dvse_get_tpp_dma_2(data)                                     ((0x00000020&(data))>>5)
#define  TP_tp_bist_dvse_get_tpp_dma_3(data)                                     ((0x00000010&(data))>>4)
#define  TP_tp_bist_dvse_get_ring(data)                                          ((0x00000008&(data))>>3)
#define  TP_tp_bist_dvse_get_pid(data)                                           ((0x00000004&(data))>>2)
#define  TP_tp_bist_dvse_get_sect(data)                                          ((0x00000002&(data))>>1)
#define  TP_tp_bist_dvse_get_key(data)                                           (0x00000001&(data))

#define  TP_tp_bist_dvs_0                                                        0x180141BC
#define  TP_tp_bist_dvs_0_reg_addr                                               "0xB80141BC"
#define  TP_tp_bist_dvs_0_reg                                                    0xB80141BC
#define  TP_tp_bist_dvs_0_inst_addr                                              "0x0075"
#define  set_TP_tp_bist_dvs_0_reg(data)                                          (*((volatile unsigned int*)TP_tp_bist_dvs_0_reg)=data)
#define  get_TP_tp_bist_dvs_0_reg                                                (*((volatile unsigned int*)TP_tp_bist_dvs_0_reg))
#define  TP_tp_bist_dvs_0_tpp_dma_0_shift                                        (28)
#define  TP_tp_bist_dvs_0_tpp_dma_1_shift                                        (24)
#define  TP_tp_bist_dvs_0_tpp_dma_2_shift                                        (20)
#define  TP_tp_bist_dvs_0_tpp_dma_3_shift                                        (16)
#define  TP_tp_bist_dvs_0_ring_shift                                             (12)
#define  TP_tp_bist_dvs_0_pid_shift                                              (8)
#define  TP_tp_bist_dvs_0_sect_shift                                             (4)
#define  TP_tp_bist_dvs_0_key_shift                                              (0)
#define  TP_tp_bist_dvs_0_tpp_dma_0_mask                                         (0xF0000000)
#define  TP_tp_bist_dvs_0_tpp_dma_1_mask                                         (0x0F000000)
#define  TP_tp_bist_dvs_0_tpp_dma_2_mask                                         (0x00F00000)
#define  TP_tp_bist_dvs_0_tpp_dma_3_mask                                         (0x000F0000)
#define  TP_tp_bist_dvs_0_ring_mask                                              (0x0000F000)
#define  TP_tp_bist_dvs_0_pid_mask                                               (0x00000F00)
#define  TP_tp_bist_dvs_0_sect_mask                                              (0x000000F0)
#define  TP_tp_bist_dvs_0_key_mask                                               (0x0000000F)
#define  TP_tp_bist_dvs_0_tpp_dma_0(data)                                        (0xF0000000&((data)<<28))
#define  TP_tp_bist_dvs_0_tpp_dma_1(data)                                        (0x0F000000&((data)<<24))
#define  TP_tp_bist_dvs_0_tpp_dma_2(data)                                        (0x00F00000&((data)<<20))
#define  TP_tp_bist_dvs_0_tpp_dma_3(data)                                        (0x000F0000&((data)<<16))
#define  TP_tp_bist_dvs_0_ring(data)                                             (0x0000F000&((data)<<12))
#define  TP_tp_bist_dvs_0_pid(data)                                              (0x00000F00&((data)<<8))
#define  TP_tp_bist_dvs_0_sect(data)                                             (0x000000F0&((data)<<4))
#define  TP_tp_bist_dvs_0_key(data)                                              (0x0000000F&(data))
#define  TP_tp_bist_dvs_0_get_tpp_dma_0(data)                                    ((0xF0000000&(data))>>28)
#define  TP_tp_bist_dvs_0_get_tpp_dma_1(data)                                    ((0x0F000000&(data))>>24)
#define  TP_tp_bist_dvs_0_get_tpp_dma_2(data)                                    ((0x00F00000&(data))>>20)
#define  TP_tp_bist_dvs_0_get_tpp_dma_3(data)                                    ((0x000F0000&(data))>>16)
#define  TP_tp_bist_dvs_0_get_ring(data)                                         ((0x0000F000&(data))>>12)
#define  TP_tp_bist_dvs_0_get_pid(data)                                          ((0x00000F00&(data))>>8)
#define  TP_tp_bist_dvs_0_get_sect(data)                                         ((0x000000F0&(data))>>4)
#define  TP_tp_bist_dvs_0_get_key(data)                                          (0x0000000F&(data))

#define  TP_tp_bist_dvs_1                                                        0x180141C0
#define  TP_tp_bist_dvs_1_reg_addr                                               "0xB80141C0"
#define  TP_tp_bist_dvs_1_reg                                                    0xB80141C0
#define  TP_tp_bist_dvs_1_inst_addr                                              "0x0076"
#define  set_TP_tp_bist_dvs_1_reg(data)                                          (*((volatile unsigned int*)TP_tp_bist_dvs_1_reg)=data)
#define  get_TP_tp_bist_dvs_1_reg                                                (*((volatile unsigned int*)TP_tp_bist_dvs_1_reg))
#define  TP_tp_bist_dvs_1_atsc_dma_shift                                         (20)
#define  TP_tp_bist_dvs_1_tp_dma_4_shift                                         (16)
#define  TP_tp_bist_dvs_1_tpp_dma_0_shift                                        (12)
#define  TP_tp_bist_dvs_1_tpp_dma_1_shift                                        (8)
#define  TP_tp_bist_dvs_1_tpp_dma_2_shift                                        (4)
#define  TP_tp_bist_dvs_1_tpp_dma_3_shift                                        (0)
#define  TP_tp_bist_dvs_1_atsc_dma_mask                                          (0x00F00000)
#define  TP_tp_bist_dvs_1_tp_dma_4_mask                                          (0x000F0000)
#define  TP_tp_bist_dvs_1_tpp_dma_0_mask                                         (0x0000F000)
#define  TP_tp_bist_dvs_1_tpp_dma_1_mask                                         (0x00000F00)
#define  TP_tp_bist_dvs_1_tpp_dma_2_mask                                         (0x000000F0)
#define  TP_tp_bist_dvs_1_tpp_dma_3_mask                                         (0x0000000F)
#define  TP_tp_bist_dvs_1_atsc_dma(data)                                         (0x00F00000&((data)<<20))
#define  TP_tp_bist_dvs_1_tp_dma_4(data)                                         (0x000F0000&((data)<<16))
#define  TP_tp_bist_dvs_1_tpp_dma_0(data)                                        (0x0000F000&((data)<<12))
#define  TP_tp_bist_dvs_1_tpp_dma_1(data)                                        (0x00000F00&((data)<<8))
#define  TP_tp_bist_dvs_1_tpp_dma_2(data)                                        (0x000000F0&((data)<<4))
#define  TP_tp_bist_dvs_1_tpp_dma_3(data)                                        (0x0000000F&(data))
#define  TP_tp_bist_dvs_1_get_atsc_dma(data)                                     ((0x00F00000&(data))>>20)
#define  TP_tp_bist_dvs_1_get_tp_dma_4(data)                                     ((0x000F0000&(data))>>16)
#define  TP_tp_bist_dvs_1_get_tpp_dma_0(data)                                    ((0x0000F000&(data))>>12)
#define  TP_tp_bist_dvs_1_get_tpp_dma_1(data)                                    ((0x00000F00&(data))>>8)
#define  TP_tp_bist_dvs_1_get_tpp_dma_2(data)                                    ((0x000000F0&(data))>>4)
#define  TP_tp_bist_dvs_1_get_tpp_dma_3(data)                                    (0x0000000F&(data))

#define  TP_TP_DEBUG                                                             0x18014300
#define  TP_TP_DEBUG_reg_addr                                                    "0xB8014300"
#define  TP_TP_DEBUG_reg                                                         0xB8014300
#define  TP_TP_DEBUG_inst_addr                                                   "0x0077"
#define  set_TP_TP_DEBUG_reg(data)                                               (*((volatile unsigned int*)TP_TP_DEBUG_reg)=data)
#define  get_TP_TP_DEBUG_reg                                                     (*((volatile unsigned int*)TP_TP_DEBUG_reg))
#define  TP_TP_DEBUG_debug_en_shift                                              (8)
#define  TP_TP_DEBUG_dv_verify_only_shift                                        (7)
#define  TP_TP_DEBUG_tp_sram_sleep_off_shift                                     (6)
#define  TP_TP_DEBUG_tp_pkt_sram_addr_rst_sel_shift                              (5)
#define  TP_TP_DEBUG_dbg_mode_shift                                              (0)
#define  TP_TP_DEBUG_debug_en_mask                                               (0x00000100)
#define  TP_TP_DEBUG_dv_verify_only_mask                                         (0x00000080)
#define  TP_TP_DEBUG_tp_sram_sleep_off_mask                                      (0x00000040)
#define  TP_TP_DEBUG_tp_pkt_sram_addr_rst_sel_mask                               (0x00000020)
#define  TP_TP_DEBUG_dbg_mode_mask                                               (0x0000001F)
#define  TP_TP_DEBUG_debug_en(data)                                              (0x00000100&((data)<<8))
#define  TP_TP_DEBUG_dv_verify_only(data)                                        (0x00000080&((data)<<7))
#define  TP_TP_DEBUG_tp_sram_sleep_off(data)                                     (0x00000040&((data)<<6))
#define  TP_TP_DEBUG_tp_pkt_sram_addr_rst_sel(data)                              (0x00000020&((data)<<5))
#define  TP_TP_DEBUG_dbg_mode(data)                                              (0x0000001F&(data))
#define  TP_TP_DEBUG_get_debug_en(data)                                          ((0x00000100&(data))>>8)
#define  TP_TP_DEBUG_get_dv_verify_only(data)                                    ((0x00000080&(data))>>7)
#define  TP_TP_DEBUG_get_tp_sram_sleep_off(data)                                 ((0x00000040&(data))>>6)
#define  TP_TP_DEBUG_get_tp_pkt_sram_addr_rst_sel(data)                          ((0x00000020&(data))>>5)
#define  TP_TP_DEBUG_get_dbg_mode(data)                                          (0x0000001F&(data))

#define  TP_TP_DEBUG_1                                                           0x18014304
#define  TP_TP_DEBUG_1_reg_addr                                                  "0xB8014304"
#define  TP_TP_DEBUG_1_reg                                                       0xB8014304
#define  TP_TP_DEBUG_1_inst_addr                                                 "0x0078"
#define  set_TP_TP_DEBUG_1_reg(data)                                             (*((volatile unsigned int*)TP_TP_DEBUG_1_reg)=data)
#define  get_TP_TP_DEBUG_1_reg                                                   (*((volatile unsigned int*)TP_TP_DEBUG_1_reg))
#define  TP_TP_DEBUG_1_m2tp_st_shift                                             (29)
#define  TP_TP_DEBUG_1_mtp_st_shift                                              (26)
#define  TP_TP_DEBUG_1_m2tp_p_st_shift                                           (24)
#define  TP_TP_DEBUG_1_mtp_p_st_shift                                            (22)
#define  TP_TP_DEBUG_1_tpp0_st_shift                                             (20)
#define  TP_TP_DEBUG_1_tp0_st_shift                                              (18)
#define  TP_TP_DEBUG_1_tpp0_m2m_st_shift                                         (15)
#define  TP_TP_DEBUG_1_tp0_m2m_st_shift                                          (12)
#define  TP_TP_DEBUG_1_dma_st_shift                                              (6)
#define  TP_TP_DEBUG_1_dma_p_st_shift                                            (0)
#define  TP_TP_DEBUG_1_m2tp_st_mask                                              (0x60000000)
#define  TP_TP_DEBUG_1_mtp_st_mask                                               (0x1C000000)
#define  TP_TP_DEBUG_1_m2tp_p_st_mask                                            (0x03000000)
#define  TP_TP_DEBUG_1_mtp_p_st_mask                                             (0x00C00000)
#define  TP_TP_DEBUG_1_tpp0_st_mask                                              (0x00300000)
#define  TP_TP_DEBUG_1_tp0_st_mask                                               (0x000C0000)
#define  TP_TP_DEBUG_1_tpp0_m2m_st_mask                                          (0x00038000)
#define  TP_TP_DEBUG_1_tp0_m2m_st_mask                                           (0x00007000)
#define  TP_TP_DEBUG_1_dma_st_mask                                               (0x00000FC0)
#define  TP_TP_DEBUG_1_dma_p_st_mask                                             (0x0000003F)
#define  TP_TP_DEBUG_1_m2tp_st(data)                                             (0x60000000&((data)<<29))
#define  TP_TP_DEBUG_1_mtp_st(data)                                              (0x1C000000&((data)<<26))
#define  TP_TP_DEBUG_1_m2tp_p_st(data)                                           (0x03000000&((data)<<24))
#define  TP_TP_DEBUG_1_mtp_p_st(data)                                            (0x00C00000&((data)<<22))
#define  TP_TP_DEBUG_1_tpp0_st(data)                                             (0x00300000&((data)<<20))
#define  TP_TP_DEBUG_1_tp0_st(data)                                              (0x000C0000&((data)<<18))
#define  TP_TP_DEBUG_1_tpp0_m2m_st(data)                                         (0x00038000&((data)<<15))
#define  TP_TP_DEBUG_1_tp0_m2m_st(data)                                          (0x00007000&((data)<<12))
#define  TP_TP_DEBUG_1_dma_st(data)                                              (0x00000FC0&((data)<<6))
#define  TP_TP_DEBUG_1_dma_p_st(data)                                            (0x0000003F&(data))
#define  TP_TP_DEBUG_1_get_m2tp_st(data)                                         ((0x60000000&(data))>>29)
#define  TP_TP_DEBUG_1_get_mtp_st(data)                                          ((0x1C000000&(data))>>26)
#define  TP_TP_DEBUG_1_get_m2tp_p_st(data)                                       ((0x03000000&(data))>>24)
#define  TP_TP_DEBUG_1_get_mtp_p_st(data)                                        ((0x00C00000&(data))>>22)
#define  TP_TP_DEBUG_1_get_tpp0_st(data)                                         ((0x00300000&(data))>>20)
#define  TP_TP_DEBUG_1_get_tp0_st(data)                                          ((0x000C0000&(data))>>18)
#define  TP_TP_DEBUG_1_get_tpp0_m2m_st(data)                                     ((0x00038000&(data))>>15)
#define  TP_TP_DEBUG_1_get_tp0_m2m_st(data)                                      ((0x00007000&(data))>>12)
#define  TP_TP_DEBUG_1_get_dma_st(data)                                          ((0x00000FC0&(data))>>6)
#define  TP_TP_DEBUG_1_get_dma_p_st(data)                                        (0x0000003F&(data))

#define  TP_TP_DEBUG_2                                                           0x18014308
#define  TP_TP_DEBUG_2_reg_addr                                                  "0xB8014308"
#define  TP_TP_DEBUG_2_reg                                                       0xB8014308
#define  TP_TP_DEBUG_2_inst_addr                                                 "0x0079"
#define  set_TP_TP_DEBUG_2_reg(data)                                             (*((volatile unsigned int*)TP_TP_DEBUG_2_reg)=data)
#define  get_TP_TP_DEBUG_2_reg                                                   (*((volatile unsigned int*)TP_TP_DEBUG_2_reg))
#define  TP_TP_DEBUG_2_debug_port_shift                                          (0)
#define  TP_TP_DEBUG_2_debug_port_mask                                           (0xFFFFFFFF)
#define  TP_TP_DEBUG_2_debug_port(data)                                          (0xFFFFFFFF&(data))
#define  TP_TP_DEBUG_2_get_debug_port(data)                                      (0xFFFFFFFF&(data))

#define  TP_TP0_M2M_RING_LIMIT                                                   0x18014400
#define  TP_TP0_M2M_RING_LIMIT_reg_addr                                          "0xB8014400"
#define  TP_TP0_M2M_RING_LIMIT_reg                                               0xB8014400
#define  TP_TP0_M2M_RING_LIMIT_inst_addr                                         "0x007A"
#define  set_TP_TP0_M2M_RING_LIMIT_reg(data)                                     (*((volatile unsigned int*)TP_TP0_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP0_M2M_RING_LIMIT_reg                                           (*((volatile unsigned int*)TP_TP0_M2M_RING_LIMIT_reg))
#define  TP_TP0_M2M_RING_LIMIT_ring_limit_shift                                  (3)
#define  TP_TP0_M2M_RING_LIMIT_ring_limit_mask                                   (0xFFFFFFF8)
#define  TP_TP0_M2M_RING_LIMIT_ring_limit(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP0_M2M_RING_LIMIT_get_ring_limit(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP0_M2M_RING_BASE                                                    0x18014404
#define  TP_TP0_M2M_RING_BASE_reg_addr                                           "0xB8014404"
#define  TP_TP0_M2M_RING_BASE_reg                                                0xB8014404
#define  TP_TP0_M2M_RING_BASE_inst_addr                                          "0x007B"
#define  set_TP_TP0_M2M_RING_BASE_reg(data)                                      (*((volatile unsigned int*)TP_TP0_M2M_RING_BASE_reg)=data)
#define  get_TP_TP0_M2M_RING_BASE_reg                                            (*((volatile unsigned int*)TP_TP0_M2M_RING_BASE_reg))
#define  TP_TP0_M2M_RING_BASE_ring_base_shift                                    (3)
#define  TP_TP0_M2M_RING_BASE_ring_base_mask                                     (0xFFFFFFF8)
#define  TP_TP0_M2M_RING_BASE_ring_base(data)                                    (0xFFFFFFF8&((data)<<3))
#define  TP_TP0_M2M_RING_BASE_get_ring_base(data)                                ((0xFFFFFFF8&(data))>>3)

#define  TP_TP0_M2M_RING_RP                                                      0x18014408
#define  TP_TP0_M2M_RING_RP_reg_addr                                             "0xB8014408"
#define  TP_TP0_M2M_RING_RP_reg                                                  0xB8014408
#define  TP_TP0_M2M_RING_RP_inst_addr                                            "0x007C"
#define  set_TP_TP0_M2M_RING_RP_reg(data)                                        (*((volatile unsigned int*)TP_TP0_M2M_RING_RP_reg)=data)
#define  get_TP_TP0_M2M_RING_RP_reg                                              (*((volatile unsigned int*)TP_TP0_M2M_RING_RP_reg))
#define  TP_TP0_M2M_RING_RP_ring_rp_shift                                        (0)
#define  TP_TP0_M2M_RING_RP_ring_rp_mask                                         (0xFFFFFFFF)
#define  TP_TP0_M2M_RING_RP_ring_rp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP0_M2M_RING_RP_get_ring_rp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP0_M2M_RING_WP                                                      0x1801440C
#define  TP_TP0_M2M_RING_WP_reg_addr                                             "0xB801440C"
#define  TP_TP0_M2M_RING_WP_reg                                                  0xB801440C
#define  TP_TP0_M2M_RING_WP_inst_addr                                            "0x007D"
#define  set_TP_TP0_M2M_RING_WP_reg(data)                                        (*((volatile unsigned int*)TP_TP0_M2M_RING_WP_reg)=data)
#define  get_TP_TP0_M2M_RING_WP_reg                                              (*((volatile unsigned int*)TP_TP0_M2M_RING_WP_reg))
#define  TP_TP0_M2M_RING_WP_ring_wp_shift                                        (0)
#define  TP_TP0_M2M_RING_WP_ring_wp_mask                                         (0xFFFFFFFF)
#define  TP_TP0_M2M_RING_WP_ring_wp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP0_M2M_RING_WP_get_ring_wp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP0_M2M_RING_CTRL                                                    0x18014410
#define  TP_TP0_M2M_RING_CTRL_reg_addr                                           "0xB8014410"
#define  TP_TP0_M2M_RING_CTRL_reg                                                0xB8014410
#define  TP_TP0_M2M_RING_CTRL_inst_addr                                          "0x007E"
#define  set_TP_TP0_M2M_RING_CTRL_reg(data)                                      (*((volatile unsigned int*)TP_TP0_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP0_M2M_RING_CTRL_reg                                            (*((volatile unsigned int*)TP_TP0_M2M_RING_CTRL_reg))
#define  TP_TP0_M2M_RING_CTRL_empty_shift                                        (4)
#define  TP_TP0_M2M_RING_CTRL_empty_en_shift                                     (3)
#define  TP_TP0_M2M_RING_CTRL_in_go_shift                                        (2)
#define  TP_TP0_M2M_RING_CTRL_go_shift                                           (1)
#define  TP_TP0_M2M_RING_CTRL_write_data_shift                                   (0)
#define  TP_TP0_M2M_RING_CTRL_empty_mask                                         (0x00000010)
#define  TP_TP0_M2M_RING_CTRL_empty_en_mask                                      (0x00000008)
#define  TP_TP0_M2M_RING_CTRL_in_go_mask                                         (0x00000004)
#define  TP_TP0_M2M_RING_CTRL_go_mask                                            (0x00000002)
#define  TP_TP0_M2M_RING_CTRL_write_data_mask                                    (0x00000001)
#define  TP_TP0_M2M_RING_CTRL_empty(data)                                        (0x00000010&((data)<<4))
#define  TP_TP0_M2M_RING_CTRL_empty_en(data)                                     (0x00000008&((data)<<3))
#define  TP_TP0_M2M_RING_CTRL_in_go(data)                                        (0x00000004&((data)<<2))
#define  TP_TP0_M2M_RING_CTRL_go(data)                                           (0x00000002&((data)<<1))
#define  TP_TP0_M2M_RING_CTRL_write_data(data)                                   (0x00000001&(data))
#define  TP_TP0_M2M_RING_CTRL_get_empty(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP0_M2M_RING_CTRL_get_empty_en(data)                                 ((0x00000008&(data))>>3)
#define  TP_TP0_M2M_RING_CTRL_get_in_go(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP0_M2M_RING_CTRL_get_go(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP0_M2M_RING_CTRL_get_write_data(data)                               (0x00000001&(data))

#define  TP_TP1_M2M_RING_LIMIT                                                   0x18014414
#define  TP_TP1_M2M_RING_LIMIT_reg_addr                                          "0xB8014414"
#define  TP_TP1_M2M_RING_LIMIT_reg                                               0xB8014414
#define  TP_TP1_M2M_RING_LIMIT_inst_addr                                         "0x007F"
#define  set_TP_TP1_M2M_RING_LIMIT_reg(data)                                     (*((volatile unsigned int*)TP_TP1_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP1_M2M_RING_LIMIT_reg                                           (*((volatile unsigned int*)TP_TP1_M2M_RING_LIMIT_reg))
#define  TP_TP1_M2M_RING_LIMIT_ring_limit_shift                                  (3)
#define  TP_TP1_M2M_RING_LIMIT_ring_limit_mask                                   (0xFFFFFFF8)
#define  TP_TP1_M2M_RING_LIMIT_ring_limit(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP1_M2M_RING_LIMIT_get_ring_limit(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP1_M2M_RING_BASE                                                    0x18014418
#define  TP_TP1_M2M_RING_BASE_reg_addr                                           "0xB8014418"
#define  TP_TP1_M2M_RING_BASE_reg                                                0xB8014418
#define  TP_TP1_M2M_RING_BASE_inst_addr                                          "0x0080"
#define  set_TP_TP1_M2M_RING_BASE_reg(data)                                      (*((volatile unsigned int*)TP_TP1_M2M_RING_BASE_reg)=data)
#define  get_TP_TP1_M2M_RING_BASE_reg                                            (*((volatile unsigned int*)TP_TP1_M2M_RING_BASE_reg))
#define  TP_TP1_M2M_RING_BASE_ring_base_shift                                    (3)
#define  TP_TP1_M2M_RING_BASE_ring_base_mask                                     (0xFFFFFFF8)
#define  TP_TP1_M2M_RING_BASE_ring_base(data)                                    (0xFFFFFFF8&((data)<<3))
#define  TP_TP1_M2M_RING_BASE_get_ring_base(data)                                ((0xFFFFFFF8&(data))>>3)

#define  TP_TP1_M2M_RING_RP                                                      0x1801441C
#define  TP_TP1_M2M_RING_RP_reg_addr                                             "0xB801441C"
#define  TP_TP1_M2M_RING_RP_reg                                                  0xB801441C
#define  TP_TP1_M2M_RING_RP_inst_addr                                            "0x0081"
#define  set_TP_TP1_M2M_RING_RP_reg(data)                                        (*((volatile unsigned int*)TP_TP1_M2M_RING_RP_reg)=data)
#define  get_TP_TP1_M2M_RING_RP_reg                                              (*((volatile unsigned int*)TP_TP1_M2M_RING_RP_reg))
#define  TP_TP1_M2M_RING_RP_ring_rp_shift                                        (0)
#define  TP_TP1_M2M_RING_RP_ring_rp_mask                                         (0xFFFFFFFF)
#define  TP_TP1_M2M_RING_RP_ring_rp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP1_M2M_RING_RP_get_ring_rp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP1_M2M_RING_WP                                                      0x18014420
#define  TP_TP1_M2M_RING_WP_reg_addr                                             "0xB8014420"
#define  TP_TP1_M2M_RING_WP_reg                                                  0xB8014420
#define  TP_TP1_M2M_RING_WP_inst_addr                                            "0x0082"
#define  set_TP_TP1_M2M_RING_WP_reg(data)                                        (*((volatile unsigned int*)TP_TP1_M2M_RING_WP_reg)=data)
#define  get_TP_TP1_M2M_RING_WP_reg                                              (*((volatile unsigned int*)TP_TP1_M2M_RING_WP_reg))
#define  TP_TP1_M2M_RING_WP_ring_wp_shift                                        (0)
#define  TP_TP1_M2M_RING_WP_ring_wp_mask                                         (0xFFFFFFFF)
#define  TP_TP1_M2M_RING_WP_ring_wp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP1_M2M_RING_WP_get_ring_wp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP1_M2M_RING_CTRL                                                    0x18014424
#define  TP_TP1_M2M_RING_CTRL_reg_addr                                           "0xB8014424"
#define  TP_TP1_M2M_RING_CTRL_reg                                                0xB8014424
#define  TP_TP1_M2M_RING_CTRL_inst_addr                                          "0x0083"
#define  set_TP_TP1_M2M_RING_CTRL_reg(data)                                      (*((volatile unsigned int*)TP_TP1_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP1_M2M_RING_CTRL_reg                                            (*((volatile unsigned int*)TP_TP1_M2M_RING_CTRL_reg))
#define  TP_TP1_M2M_RING_CTRL_empty_shift                                        (4)
#define  TP_TP1_M2M_RING_CTRL_empty_en_shift                                     (3)
#define  TP_TP1_M2M_RING_CTRL_in_go_shift                                        (2)
#define  TP_TP1_M2M_RING_CTRL_go_shift                                           (1)
#define  TP_TP1_M2M_RING_CTRL_write_data_shift                                   (0)
#define  TP_TP1_M2M_RING_CTRL_empty_mask                                         (0x00000010)
#define  TP_TP1_M2M_RING_CTRL_empty_en_mask                                      (0x00000008)
#define  TP_TP1_M2M_RING_CTRL_in_go_mask                                         (0x00000004)
#define  TP_TP1_M2M_RING_CTRL_go_mask                                            (0x00000002)
#define  TP_TP1_M2M_RING_CTRL_write_data_mask                                    (0x00000001)
#define  TP_TP1_M2M_RING_CTRL_empty(data)                                        (0x00000010&((data)<<4))
#define  TP_TP1_M2M_RING_CTRL_empty_en(data)                                     (0x00000008&((data)<<3))
#define  TP_TP1_M2M_RING_CTRL_in_go(data)                                        (0x00000004&((data)<<2))
#define  TP_TP1_M2M_RING_CTRL_go(data)                                           (0x00000002&((data)<<1))
#define  TP_TP1_M2M_RING_CTRL_write_data(data)                                   (0x00000001&(data))
#define  TP_TP1_M2M_RING_CTRL_get_empty(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP1_M2M_RING_CTRL_get_empty_en(data)                                 ((0x00000008&(data))>>3)
#define  TP_TP1_M2M_RING_CTRL_get_in_go(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP1_M2M_RING_CTRL_get_go(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP1_M2M_RING_CTRL_get_write_data(data)                               (0x00000001&(data))

#define  TP_TP2_M2M_RING_LIMIT                                                   0x18014428
#define  TP_TP2_M2M_RING_LIMIT_reg_addr                                          "0xB8014428"
#define  TP_TP2_M2M_RING_LIMIT_reg                                               0xB8014428
#define  TP_TP2_M2M_RING_LIMIT_inst_addr                                         "0x0084"
#define  set_TP_TP2_M2M_RING_LIMIT_reg(data)                                     (*((volatile unsigned int*)TP_TP2_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP2_M2M_RING_LIMIT_reg                                           (*((volatile unsigned int*)TP_TP2_M2M_RING_LIMIT_reg))
#define  TP_TP2_M2M_RING_LIMIT_ring_limit_shift                                  (3)
#define  TP_TP2_M2M_RING_LIMIT_ring_limit_mask                                   (0xFFFFFFF8)
#define  TP_TP2_M2M_RING_LIMIT_ring_limit(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP2_M2M_RING_LIMIT_get_ring_limit(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP2_M2M_RING_BASE                                                    0x1801442C
#define  TP_TP2_M2M_RING_BASE_reg_addr                                           "0xB801442C"
#define  TP_TP2_M2M_RING_BASE_reg                                                0xB801442C
#define  TP_TP2_M2M_RING_BASE_inst_addr                                          "0x0085"
#define  set_TP_TP2_M2M_RING_BASE_reg(data)                                      (*((volatile unsigned int*)TP_TP2_M2M_RING_BASE_reg)=data)
#define  get_TP_TP2_M2M_RING_BASE_reg                                            (*((volatile unsigned int*)TP_TP2_M2M_RING_BASE_reg))
#define  TP_TP2_M2M_RING_BASE_ring_base_shift                                    (3)
#define  TP_TP2_M2M_RING_BASE_ring_base_mask                                     (0xFFFFFFF8)
#define  TP_TP2_M2M_RING_BASE_ring_base(data)                                    (0xFFFFFFF8&((data)<<3))
#define  TP_TP2_M2M_RING_BASE_get_ring_base(data)                                ((0xFFFFFFF8&(data))>>3)

#define  TP_TP2_M2M_RING_RP                                                      0x18014430
#define  TP_TP2_M2M_RING_RP_reg_addr                                             "0xB8014430"
#define  TP_TP2_M2M_RING_RP_reg                                                  0xB8014430
#define  TP_TP2_M2M_RING_RP_inst_addr                                            "0x0086"
#define  set_TP_TP2_M2M_RING_RP_reg(data)                                        (*((volatile unsigned int*)TP_TP2_M2M_RING_RP_reg)=data)
#define  get_TP_TP2_M2M_RING_RP_reg                                              (*((volatile unsigned int*)TP_TP2_M2M_RING_RP_reg))
#define  TP_TP2_M2M_RING_RP_ring_rp_shift                                        (0)
#define  TP_TP2_M2M_RING_RP_ring_rp_mask                                         (0xFFFFFFFF)
#define  TP_TP2_M2M_RING_RP_ring_rp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP2_M2M_RING_RP_get_ring_rp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP2_M2M_RING_WP                                                      0x18014434
#define  TP_TP2_M2M_RING_WP_reg_addr                                             "0xB8014434"
#define  TP_TP2_M2M_RING_WP_reg                                                  0xB8014434
#define  TP_TP2_M2M_RING_WP_inst_addr                                            "0x0087"
#define  set_TP_TP2_M2M_RING_WP_reg(data)                                        (*((volatile unsigned int*)TP_TP2_M2M_RING_WP_reg)=data)
#define  get_TP_TP2_M2M_RING_WP_reg                                              (*((volatile unsigned int*)TP_TP2_M2M_RING_WP_reg))
#define  TP_TP2_M2M_RING_WP_ring_wp_shift                                        (0)
#define  TP_TP2_M2M_RING_WP_ring_wp_mask                                         (0xFFFFFFFF)
#define  TP_TP2_M2M_RING_WP_ring_wp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP2_M2M_RING_WP_get_ring_wp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP2_M2M_RING_CTRL                                                    0x18014438
#define  TP_TP2_M2M_RING_CTRL_reg_addr                                           "0xB8014438"
#define  TP_TP2_M2M_RING_CTRL_reg                                                0xB8014438
#define  TP_TP2_M2M_RING_CTRL_inst_addr                                          "0x0088"
#define  set_TP_TP2_M2M_RING_CTRL_reg(data)                                      (*((volatile unsigned int*)TP_TP2_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP2_M2M_RING_CTRL_reg                                            (*((volatile unsigned int*)TP_TP2_M2M_RING_CTRL_reg))
#define  TP_TP2_M2M_RING_CTRL_empty_shift                                        (4)
#define  TP_TP2_M2M_RING_CTRL_empty_en_shift                                     (3)
#define  TP_TP2_M2M_RING_CTRL_in_go_shift                                        (2)
#define  TP_TP2_M2M_RING_CTRL_go_shift                                           (1)
#define  TP_TP2_M2M_RING_CTRL_write_data_shift                                   (0)
#define  TP_TP2_M2M_RING_CTRL_empty_mask                                         (0x00000010)
#define  TP_TP2_M2M_RING_CTRL_empty_en_mask                                      (0x00000008)
#define  TP_TP2_M2M_RING_CTRL_in_go_mask                                         (0x00000004)
#define  TP_TP2_M2M_RING_CTRL_go_mask                                            (0x00000002)
#define  TP_TP2_M2M_RING_CTRL_write_data_mask                                    (0x00000001)
#define  TP_TP2_M2M_RING_CTRL_empty(data)                                        (0x00000010&((data)<<4))
#define  TP_TP2_M2M_RING_CTRL_empty_en(data)                                     (0x00000008&((data)<<3))
#define  TP_TP2_M2M_RING_CTRL_in_go(data)                                        (0x00000004&((data)<<2))
#define  TP_TP2_M2M_RING_CTRL_go(data)                                           (0x00000002&((data)<<1))
#define  TP_TP2_M2M_RING_CTRL_write_data(data)                                   (0x00000001&(data))
#define  TP_TP2_M2M_RING_CTRL_get_empty(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP2_M2M_RING_CTRL_get_empty_en(data)                                 ((0x00000008&(data))>>3)
#define  TP_TP2_M2M_RING_CTRL_get_in_go(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP2_M2M_RING_CTRL_get_go(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP2_M2M_RING_CTRL_get_write_data(data)                               (0x00000001&(data))

#define  TP_TP3_M2M_RING_LIMIT                                                   0x18014478
#define  TP_TP3_M2M_RING_LIMIT_reg_addr                                          "0xB8014478"
#define  TP_TP3_M2M_RING_LIMIT_reg                                               0xB8014478
#define  TP_TP3_M2M_RING_LIMIT_inst_addr                                         "0x0089"
#define  set_TP_TP3_M2M_RING_LIMIT_reg(data)                                     (*((volatile unsigned int*)TP_TP3_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP3_M2M_RING_LIMIT_reg                                           (*((volatile unsigned int*)TP_TP3_M2M_RING_LIMIT_reg))
#define  TP_TP3_M2M_RING_LIMIT_ring_limit_shift                                  (3)
#define  TP_TP3_M2M_RING_LIMIT_ring_limit_mask                                   (0xFFFFFFF8)
#define  TP_TP3_M2M_RING_LIMIT_ring_limit(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP3_M2M_RING_LIMIT_get_ring_limit(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP3_M2M_RING_BASE                                                    0x1801447C
#define  TP_TP3_M2M_RING_BASE_reg_addr                                           "0xB801447C"
#define  TP_TP3_M2M_RING_BASE_reg                                                0xB801447C
#define  TP_TP3_M2M_RING_BASE_inst_addr                                          "0x008A"
#define  set_TP_TP3_M2M_RING_BASE_reg(data)                                      (*((volatile unsigned int*)TP_TP3_M2M_RING_BASE_reg)=data)
#define  get_TP_TP3_M2M_RING_BASE_reg                                            (*((volatile unsigned int*)TP_TP3_M2M_RING_BASE_reg))
#define  TP_TP3_M2M_RING_BASE_ring_base_shift                                    (3)
#define  TP_TP3_M2M_RING_BASE_ring_base_mask                                     (0xFFFFFFF8)
#define  TP_TP3_M2M_RING_BASE_ring_base(data)                                    (0xFFFFFFF8&((data)<<3))
#define  TP_TP3_M2M_RING_BASE_get_ring_base(data)                                ((0xFFFFFFF8&(data))>>3)

#define  TP_TP3_M2M_RING_RP                                                      0x18014480
#define  TP_TP3_M2M_RING_RP_reg_addr                                             "0xB8014480"
#define  TP_TP3_M2M_RING_RP_reg                                                  0xB8014480
#define  TP_TP3_M2M_RING_RP_inst_addr                                            "0x008B"
#define  set_TP_TP3_M2M_RING_RP_reg(data)                                        (*((volatile unsigned int*)TP_TP3_M2M_RING_RP_reg)=data)
#define  get_TP_TP3_M2M_RING_RP_reg                                              (*((volatile unsigned int*)TP_TP3_M2M_RING_RP_reg))
#define  TP_TP3_M2M_RING_RP_ring_rp_shift                                        (0)
#define  TP_TP3_M2M_RING_RP_ring_rp_mask                                         (0xFFFFFFFF)
#define  TP_TP3_M2M_RING_RP_ring_rp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP3_M2M_RING_RP_get_ring_rp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP3_M2M_RING_WP                                                      0x18014484
#define  TP_TP3_M2M_RING_WP_reg_addr                                             "0xB8014484"
#define  TP_TP3_M2M_RING_WP_reg                                                  0xB8014484
#define  TP_TP3_M2M_RING_WP_inst_addr                                            "0x008C"
#define  set_TP_TP3_M2M_RING_WP_reg(data)                                        (*((volatile unsigned int*)TP_TP3_M2M_RING_WP_reg)=data)
#define  get_TP_TP3_M2M_RING_WP_reg                                              (*((volatile unsigned int*)TP_TP3_M2M_RING_WP_reg))
#define  TP_TP3_M2M_RING_WP_ring_wp_shift                                        (0)
#define  TP_TP3_M2M_RING_WP_ring_wp_mask                                         (0xFFFFFFFF)
#define  TP_TP3_M2M_RING_WP_ring_wp(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP3_M2M_RING_WP_get_ring_wp(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP3_M2M_RING_CTRL                                                    0x18014488
#define  TP_TP3_M2M_RING_CTRL_reg_addr                                           "0xB8014488"
#define  TP_TP3_M2M_RING_CTRL_reg                                                0xB8014488
#define  TP_TP3_M2M_RING_CTRL_inst_addr                                          "0x008D"
#define  set_TP_TP3_M2M_RING_CTRL_reg(data)                                      (*((volatile unsigned int*)TP_TP3_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP3_M2M_RING_CTRL_reg                                            (*((volatile unsigned int*)TP_TP3_M2M_RING_CTRL_reg))
#define  TP_TP3_M2M_RING_CTRL_empty_shift                                        (4)
#define  TP_TP3_M2M_RING_CTRL_empty_en_shift                                     (3)
#define  TP_TP3_M2M_RING_CTRL_in_go_shift                                        (2)
#define  TP_TP3_M2M_RING_CTRL_go_shift                                           (1)
#define  TP_TP3_M2M_RING_CTRL_write_data_shift                                   (0)
#define  TP_TP3_M2M_RING_CTRL_empty_mask                                         (0x00000010)
#define  TP_TP3_M2M_RING_CTRL_empty_en_mask                                      (0x00000008)
#define  TP_TP3_M2M_RING_CTRL_in_go_mask                                         (0x00000004)
#define  TP_TP3_M2M_RING_CTRL_go_mask                                            (0x00000002)
#define  TP_TP3_M2M_RING_CTRL_write_data_mask                                    (0x00000001)
#define  TP_TP3_M2M_RING_CTRL_empty(data)                                        (0x00000010&((data)<<4))
#define  TP_TP3_M2M_RING_CTRL_empty_en(data)                                     (0x00000008&((data)<<3))
#define  TP_TP3_M2M_RING_CTRL_in_go(data)                                        (0x00000004&((data)<<2))
#define  TP_TP3_M2M_RING_CTRL_go(data)                                           (0x00000002&((data)<<1))
#define  TP_TP3_M2M_RING_CTRL_write_data(data)                                   (0x00000001&(data))
#define  TP_TP3_M2M_RING_CTRL_get_empty(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP3_M2M_RING_CTRL_get_empty_en(data)                                 ((0x00000008&(data))>>3)
#define  TP_TP3_M2M_RING_CTRL_get_in_go(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP3_M2M_RING_CTRL_get_go(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP3_M2M_RING_CTRL_get_write_data(data)                               (0x00000001&(data))

#define  TP_TP0_P_M2M_RING_LIMIT                                                 0x1801443C
#define  TP_TP0_P_M2M_RING_LIMIT_reg_addr                                        "0xB801443C"
#define  TP_TP0_P_M2M_RING_LIMIT_reg                                             0xB801443C
#define  TP_TP0_P_M2M_RING_LIMIT_inst_addr                                       "0x008E"
#define  set_TP_TP0_P_M2M_RING_LIMIT_reg(data)                                   (*((volatile unsigned int*)TP_TP0_P_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP0_P_M2M_RING_LIMIT_reg                                         (*((volatile unsigned int*)TP_TP0_P_M2M_RING_LIMIT_reg))
#define  TP_TP0_P_M2M_RING_LIMIT_ring_limit_shift                                (3)
#define  TP_TP0_P_M2M_RING_LIMIT_ring_limit_mask                                 (0xFFFFFFF8)
#define  TP_TP0_P_M2M_RING_LIMIT_ring_limit(data)                                (0xFFFFFFF8&((data)<<3))
#define  TP_TP0_P_M2M_RING_LIMIT_get_ring_limit(data)                            ((0xFFFFFFF8&(data))>>3)

#define  TP_TP0_P_M2M_RING_BASE                                                  0x18014440
#define  TP_TP0_P_M2M_RING_BASE_reg_addr                                         "0xB8014440"
#define  TP_TP0_P_M2M_RING_BASE_reg                                              0xB8014440
#define  TP_TP0_P_M2M_RING_BASE_inst_addr                                        "0x008F"
#define  set_TP_TP0_P_M2M_RING_BASE_reg(data)                                    (*((volatile unsigned int*)TP_TP0_P_M2M_RING_BASE_reg)=data)
#define  get_TP_TP0_P_M2M_RING_BASE_reg                                          (*((volatile unsigned int*)TP_TP0_P_M2M_RING_BASE_reg))
#define  TP_TP0_P_M2M_RING_BASE_ring_base_shift                                  (3)
#define  TP_TP0_P_M2M_RING_BASE_ring_base_mask                                   (0xFFFFFFF8)
#define  TP_TP0_P_M2M_RING_BASE_ring_base(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP0_P_M2M_RING_BASE_get_ring_base(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP0_P_M2M_RING_RP                                                    0x18014444
#define  TP_TP0_P_M2M_RING_RP_reg_addr                                           "0xB8014444"
#define  TP_TP0_P_M2M_RING_RP_reg                                                0xB8014444
#define  TP_TP0_P_M2M_RING_RP_inst_addr                                          "0x0090"
#define  set_TP_TP0_P_M2M_RING_RP_reg(data)                                      (*((volatile unsigned int*)TP_TP0_P_M2M_RING_RP_reg)=data)
#define  get_TP_TP0_P_M2M_RING_RP_reg                                            (*((volatile unsigned int*)TP_TP0_P_M2M_RING_RP_reg))
#define  TP_TP0_P_M2M_RING_RP_ring_rp_shift                                      (0)
#define  TP_TP0_P_M2M_RING_RP_ring_rp_mask                                       (0xFFFFFFFF)
#define  TP_TP0_P_M2M_RING_RP_ring_rp(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP0_P_M2M_RING_RP_get_ring_rp(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP0_P_M2M_RING_WP                                                    0x18014448
#define  TP_TP0_P_M2M_RING_WP_reg_addr                                           "0xB8014448"
#define  TP_TP0_P_M2M_RING_WP_reg                                                0xB8014448
#define  TP_TP0_P_M2M_RING_WP_inst_addr                                          "0x0091"
#define  set_TP_TP0_P_M2M_RING_WP_reg(data)                                      (*((volatile unsigned int*)TP_TP0_P_M2M_RING_WP_reg)=data)
#define  get_TP_TP0_P_M2M_RING_WP_reg                                            (*((volatile unsigned int*)TP_TP0_P_M2M_RING_WP_reg))
#define  TP_TP0_P_M2M_RING_WP_ring_wp_shift                                      (0)
#define  TP_TP0_P_M2M_RING_WP_ring_wp_mask                                       (0xFFFFFFFF)
#define  TP_TP0_P_M2M_RING_WP_ring_wp(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP0_P_M2M_RING_WP_get_ring_wp(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP0_P_M2M_RING_CTRL                                                  0x1801444C
#define  TP_TP0_P_M2M_RING_CTRL_reg_addr                                         "0xB801444C"
#define  TP_TP0_P_M2M_RING_CTRL_reg                                              0xB801444C
#define  TP_TP0_P_M2M_RING_CTRL_inst_addr                                        "0x0092"
#define  set_TP_TP0_P_M2M_RING_CTRL_reg(data)                                    (*((volatile unsigned int*)TP_TP0_P_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP0_P_M2M_RING_CTRL_reg                                          (*((volatile unsigned int*)TP_TP0_P_M2M_RING_CTRL_reg))
#define  TP_TP0_P_M2M_RING_CTRL_empty_shift                                      (4)
#define  TP_TP0_P_M2M_RING_CTRL_empty_en_shift                                   (3)
#define  TP_TP0_P_M2M_RING_CTRL_in_go_shift                                      (2)
#define  TP_TP0_P_M2M_RING_CTRL_go_shift                                         (1)
#define  TP_TP0_P_M2M_RING_CTRL_write_data_shift                                 (0)
#define  TP_TP0_P_M2M_RING_CTRL_empty_mask                                       (0x00000010)
#define  TP_TP0_P_M2M_RING_CTRL_empty_en_mask                                    (0x00000008)
#define  TP_TP0_P_M2M_RING_CTRL_in_go_mask                                       (0x00000004)
#define  TP_TP0_P_M2M_RING_CTRL_go_mask                                          (0x00000002)
#define  TP_TP0_P_M2M_RING_CTRL_write_data_mask                                  (0x00000001)
#define  TP_TP0_P_M2M_RING_CTRL_empty(data)                                      (0x00000010&((data)<<4))
#define  TP_TP0_P_M2M_RING_CTRL_empty_en(data)                                   (0x00000008&((data)<<3))
#define  TP_TP0_P_M2M_RING_CTRL_in_go(data)                                      (0x00000004&((data)<<2))
#define  TP_TP0_P_M2M_RING_CTRL_go(data)                                         (0x00000002&((data)<<1))
#define  TP_TP0_P_M2M_RING_CTRL_write_data(data)                                 (0x00000001&(data))
#define  TP_TP0_P_M2M_RING_CTRL_get_empty(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP0_P_M2M_RING_CTRL_get_empty_en(data)                               ((0x00000008&(data))>>3)
#define  TP_TP0_P_M2M_RING_CTRL_get_in_go(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP0_P_M2M_RING_CTRL_get_go(data)                                     ((0x00000002&(data))>>1)
#define  TP_TP0_P_M2M_RING_CTRL_get_write_data(data)                             (0x00000001&(data))

#define  TP_TP1_P_M2M_RING_LIMIT                                                 0x18014450
#define  TP_TP1_P_M2M_RING_LIMIT_reg_addr                                        "0xB8014450"
#define  TP_TP1_P_M2M_RING_LIMIT_reg                                             0xB8014450
#define  TP_TP1_P_M2M_RING_LIMIT_inst_addr                                       "0x0093"
#define  set_TP_TP1_P_M2M_RING_LIMIT_reg(data)                                   (*((volatile unsigned int*)TP_TP1_P_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP1_P_M2M_RING_LIMIT_reg                                         (*((volatile unsigned int*)TP_TP1_P_M2M_RING_LIMIT_reg))
#define  TP_TP1_P_M2M_RING_LIMIT_ring_limit_shift                                (3)
#define  TP_TP1_P_M2M_RING_LIMIT_ring_limit_mask                                 (0xFFFFFFF8)
#define  TP_TP1_P_M2M_RING_LIMIT_ring_limit(data)                                (0xFFFFFFF8&((data)<<3))
#define  TP_TP1_P_M2M_RING_LIMIT_get_ring_limit(data)                            ((0xFFFFFFF8&(data))>>3)

#define  TP_TP1_P_M2M_RING_BASE                                                  0x18014454
#define  TP_TP1_P_M2M_RING_BASE_reg_addr                                         "0xB8014454"
#define  TP_TP1_P_M2M_RING_BASE_reg                                              0xB8014454
#define  TP_TP1_P_M2M_RING_BASE_inst_addr                                        "0x0094"
#define  set_TP_TP1_P_M2M_RING_BASE_reg(data)                                    (*((volatile unsigned int*)TP_TP1_P_M2M_RING_BASE_reg)=data)
#define  get_TP_TP1_P_M2M_RING_BASE_reg                                          (*((volatile unsigned int*)TP_TP1_P_M2M_RING_BASE_reg))
#define  TP_TP1_P_M2M_RING_BASE_ring_base_shift                                  (3)
#define  TP_TP1_P_M2M_RING_BASE_ring_base_mask                                   (0xFFFFFFF8)
#define  TP_TP1_P_M2M_RING_BASE_ring_base(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP1_P_M2M_RING_BASE_get_ring_base(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP1_P_M2M_RING_RP                                                    0x18014458
#define  TP_TP1_P_M2M_RING_RP_reg_addr                                           "0xB8014458"
#define  TP_TP1_P_M2M_RING_RP_reg                                                0xB8014458
#define  TP_TP1_P_M2M_RING_RP_inst_addr                                          "0x0095"
#define  set_TP_TP1_P_M2M_RING_RP_reg(data)                                      (*((volatile unsigned int*)TP_TP1_P_M2M_RING_RP_reg)=data)
#define  get_TP_TP1_P_M2M_RING_RP_reg                                            (*((volatile unsigned int*)TP_TP1_P_M2M_RING_RP_reg))
#define  TP_TP1_P_M2M_RING_RP_ring_rp_shift                                      (0)
#define  TP_TP1_P_M2M_RING_RP_ring_rp_mask                                       (0xFFFFFFFF)
#define  TP_TP1_P_M2M_RING_RP_ring_rp(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP1_P_M2M_RING_RP_get_ring_rp(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP1_P_M2M_RING_WP                                                    0x1801445C
#define  TP_TP1_P_M2M_RING_WP_reg_addr                                           "0xB801445C"
#define  TP_TP1_P_M2M_RING_WP_reg                                                0xB801445C
#define  TP_TP1_P_M2M_RING_WP_inst_addr                                          "0x0096"
#define  set_TP_TP1_P_M2M_RING_WP_reg(data)                                      (*((volatile unsigned int*)TP_TP1_P_M2M_RING_WP_reg)=data)
#define  get_TP_TP1_P_M2M_RING_WP_reg                                            (*((volatile unsigned int*)TP_TP1_P_M2M_RING_WP_reg))
#define  TP_TP1_P_M2M_RING_WP_ring_wp_shift                                      (0)
#define  TP_TP1_P_M2M_RING_WP_ring_wp_mask                                       (0xFFFFFFFF)
#define  TP_TP1_P_M2M_RING_WP_ring_wp(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP1_P_M2M_RING_WP_get_ring_wp(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP1_P_M2M_RING_CTRL                                                  0x18014460
#define  TP_TP1_P_M2M_RING_CTRL_reg_addr                                         "0xB8014460"
#define  TP_TP1_P_M2M_RING_CTRL_reg                                              0xB8014460
#define  TP_TP1_P_M2M_RING_CTRL_inst_addr                                        "0x0097"
#define  set_TP_TP1_P_M2M_RING_CTRL_reg(data)                                    (*((volatile unsigned int*)TP_TP1_P_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP1_P_M2M_RING_CTRL_reg                                          (*((volatile unsigned int*)TP_TP1_P_M2M_RING_CTRL_reg))
#define  TP_TP1_P_M2M_RING_CTRL_empty_shift                                      (4)
#define  TP_TP1_P_M2M_RING_CTRL_empty_en_shift                                   (3)
#define  TP_TP1_P_M2M_RING_CTRL_in_go_shift                                      (2)
#define  TP_TP1_P_M2M_RING_CTRL_go_shift                                         (1)
#define  TP_TP1_P_M2M_RING_CTRL_write_data_shift                                 (0)
#define  TP_TP1_P_M2M_RING_CTRL_empty_mask                                       (0x00000010)
#define  TP_TP1_P_M2M_RING_CTRL_empty_en_mask                                    (0x00000008)
#define  TP_TP1_P_M2M_RING_CTRL_in_go_mask                                       (0x00000004)
#define  TP_TP1_P_M2M_RING_CTRL_go_mask                                          (0x00000002)
#define  TP_TP1_P_M2M_RING_CTRL_write_data_mask                                  (0x00000001)
#define  TP_TP1_P_M2M_RING_CTRL_empty(data)                                      (0x00000010&((data)<<4))
#define  TP_TP1_P_M2M_RING_CTRL_empty_en(data)                                   (0x00000008&((data)<<3))
#define  TP_TP1_P_M2M_RING_CTRL_in_go(data)                                      (0x00000004&((data)<<2))
#define  TP_TP1_P_M2M_RING_CTRL_go(data)                                         (0x00000002&((data)<<1))
#define  TP_TP1_P_M2M_RING_CTRL_write_data(data)                                 (0x00000001&(data))
#define  TP_TP1_P_M2M_RING_CTRL_get_empty(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP1_P_M2M_RING_CTRL_get_empty_en(data)                               ((0x00000008&(data))>>3)
#define  TP_TP1_P_M2M_RING_CTRL_get_in_go(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP1_P_M2M_RING_CTRL_get_go(data)                                     ((0x00000002&(data))>>1)
#define  TP_TP1_P_M2M_RING_CTRL_get_write_data(data)                             (0x00000001&(data))

#define  TP_TP2_P_M2M_RING_LIMIT                                                 0x18014464
#define  TP_TP2_P_M2M_RING_LIMIT_reg_addr                                        "0xB8014464"
#define  TP_TP2_P_M2M_RING_LIMIT_reg                                             0xB8014464
#define  TP_TP2_P_M2M_RING_LIMIT_inst_addr                                       "0x0098"
#define  set_TP_TP2_P_M2M_RING_LIMIT_reg(data)                                   (*((volatile unsigned int*)TP_TP2_P_M2M_RING_LIMIT_reg)=data)
#define  get_TP_TP2_P_M2M_RING_LIMIT_reg                                         (*((volatile unsigned int*)TP_TP2_P_M2M_RING_LIMIT_reg))
#define  TP_TP2_P_M2M_RING_LIMIT_ring_limit_shift                                (3)
#define  TP_TP2_P_M2M_RING_LIMIT_ring_limit_mask                                 (0xFFFFFFF8)
#define  TP_TP2_P_M2M_RING_LIMIT_ring_limit(data)                                (0xFFFFFFF8&((data)<<3))
#define  TP_TP2_P_M2M_RING_LIMIT_get_ring_limit(data)                            ((0xFFFFFFF8&(data))>>3)

#define  TP_TP2_P_M2M_RING_BASE                                                  0x18014468
#define  TP_TP2_P_M2M_RING_BASE_reg_addr                                         "0xB8014468"
#define  TP_TP2_P_M2M_RING_BASE_reg                                              0xB8014468
#define  TP_TP2_P_M2M_RING_BASE_inst_addr                                        "0x0099"
#define  set_TP_TP2_P_M2M_RING_BASE_reg(data)                                    (*((volatile unsigned int*)TP_TP2_P_M2M_RING_BASE_reg)=data)
#define  get_TP_TP2_P_M2M_RING_BASE_reg                                          (*((volatile unsigned int*)TP_TP2_P_M2M_RING_BASE_reg))
#define  TP_TP2_P_M2M_RING_BASE_ring_base_shift                                  (3)
#define  TP_TP2_P_M2M_RING_BASE_ring_base_mask                                   (0xFFFFFFF8)
#define  TP_TP2_P_M2M_RING_BASE_ring_base(data)                                  (0xFFFFFFF8&((data)<<3))
#define  TP_TP2_P_M2M_RING_BASE_get_ring_base(data)                              ((0xFFFFFFF8&(data))>>3)

#define  TP_TP2_P_M2M_RING_RP                                                    0x1801446C
#define  TP_TP2_P_M2M_RING_RP_reg_addr                                           "0xB801446C"
#define  TP_TP2_P_M2M_RING_RP_reg                                                0xB801446C
#define  TP_TP2_P_M2M_RING_RP_inst_addr                                          "0x009A"
#define  set_TP_TP2_P_M2M_RING_RP_reg(data)                                      (*((volatile unsigned int*)TP_TP2_P_M2M_RING_RP_reg)=data)
#define  get_TP_TP2_P_M2M_RING_RP_reg                                            (*((volatile unsigned int*)TP_TP2_P_M2M_RING_RP_reg))
#define  TP_TP2_P_M2M_RING_RP_ring_rp_shift                                      (0)
#define  TP_TP2_P_M2M_RING_RP_ring_rp_mask                                       (0xFFFFFFFF)
#define  TP_TP2_P_M2M_RING_RP_ring_rp(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP2_P_M2M_RING_RP_get_ring_rp(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP2_P_M2M_RING_WP                                                    0x18014470
#define  TP_TP2_P_M2M_RING_WP_reg_addr                                           "0xB8014470"
#define  TP_TP2_P_M2M_RING_WP_reg                                                0xB8014470
#define  TP_TP2_P_M2M_RING_WP_inst_addr                                          "0x009B"
#define  set_TP_TP2_P_M2M_RING_WP_reg(data)                                      (*((volatile unsigned int*)TP_TP2_P_M2M_RING_WP_reg)=data)
#define  get_TP_TP2_P_M2M_RING_WP_reg                                            (*((volatile unsigned int*)TP_TP2_P_M2M_RING_WP_reg))
#define  TP_TP2_P_M2M_RING_WP_ring_wp_shift                                      (0)
#define  TP_TP2_P_M2M_RING_WP_ring_wp_mask                                       (0xFFFFFFFF)
#define  TP_TP2_P_M2M_RING_WP_ring_wp(data)                                      (0xFFFFFFFF&(data))
#define  TP_TP2_P_M2M_RING_WP_get_ring_wp(data)                                  (0xFFFFFFFF&(data))

#define  TP_TP2_P_M2M_RING_CTRL                                                  0x18014474
#define  TP_TP2_P_M2M_RING_CTRL_reg_addr                                         "0xB8014474"
#define  TP_TP2_P_M2M_RING_CTRL_reg                                              0xB8014474
#define  TP_TP2_P_M2M_RING_CTRL_inst_addr                                        "0x009C"
#define  set_TP_TP2_P_M2M_RING_CTRL_reg(data)                                    (*((volatile unsigned int*)TP_TP2_P_M2M_RING_CTRL_reg)=data)
#define  get_TP_TP2_P_M2M_RING_CTRL_reg                                          (*((volatile unsigned int*)TP_TP2_P_M2M_RING_CTRL_reg))
#define  TP_TP2_P_M2M_RING_CTRL_empty_shift                                      (4)
#define  TP_TP2_P_M2M_RING_CTRL_empty_en_shift                                   (3)
#define  TP_TP2_P_M2M_RING_CTRL_in_go_shift                                      (2)
#define  TP_TP2_P_M2M_RING_CTRL_go_shift                                         (1)
#define  TP_TP2_P_M2M_RING_CTRL_write_data_shift                                 (0)
#define  TP_TP2_P_M2M_RING_CTRL_empty_mask                                       (0x00000010)
#define  TP_TP2_P_M2M_RING_CTRL_empty_en_mask                                    (0x00000008)
#define  TP_TP2_P_M2M_RING_CTRL_in_go_mask                                       (0x00000004)
#define  TP_TP2_P_M2M_RING_CTRL_go_mask                                          (0x00000002)
#define  TP_TP2_P_M2M_RING_CTRL_write_data_mask                                  (0x00000001)
#define  TP_TP2_P_M2M_RING_CTRL_empty(data)                                      (0x00000010&((data)<<4))
#define  TP_TP2_P_M2M_RING_CTRL_empty_en(data)                                   (0x00000008&((data)<<3))
#define  TP_TP2_P_M2M_RING_CTRL_in_go(data)                                      (0x00000004&((data)<<2))
#define  TP_TP2_P_M2M_RING_CTRL_go(data)                                         (0x00000002&((data)<<1))
#define  TP_TP2_P_M2M_RING_CTRL_write_data(data)                                 (0x00000001&(data))
#define  TP_TP2_P_M2M_RING_CTRL_get_empty(data)                                  ((0x00000010&(data))>>4)
#define  TP_TP2_P_M2M_RING_CTRL_get_empty_en(data)                               ((0x00000008&(data))>>3)
#define  TP_TP2_P_M2M_RING_CTRL_get_in_go(data)                                  ((0x00000004&(data))>>2)
#define  TP_TP2_P_M2M_RING_CTRL_get_go(data)                                     ((0x00000002&(data))>>1)
#define  TP_TP2_P_M2M_RING_CTRL_get_write_data(data)                             (0x00000001&(data))

#define  TP_TP_TF0_P_CNTL                                                        0x18014500
#define  TP_TP_TF0_P_CNTL_reg_addr                                               "0xB8014500"
#define  TP_TP_TF0_P_CNTL_reg                                                    0xB8014500
#define  TP_TP_TF0_P_CNTL_inst_addr                                              "0x009D"
#define  set_TP_TP_TF0_P_CNTL_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF0_P_CNTL_reg)=data)
#define  get_TP_TP_TF0_P_CNTL_reg                                                (*((volatile unsigned int*)TP_TP_TF0_P_CNTL_reg))
#define  TP_TP_TF0_P_CNTL_two_bit_shift                                          (31)
#define  TP_TP_TF0_P_CNTL_two_bit_reverse_shift                                  (30)
#define  TP_TP_TF0_P_CNTL_two_bit_sel_h_shift                                    (29)
#define  TP_TP_TF0_P_CNTL_two_bit_sel_l_shift                                    (28)
#define  TP_TP_TF0_P_CNTL_src_sel_h_shift                                        (25)
#define  TP_TP_TF0_P_CNTL_src_sel_l_shift                                        (24)
#define  TP_TP_TF0_P_CNTL_dir_dma_shift                                          (23)
#define  TP_TP_TF0_P_CNTL_ci_mode_shift                                          (18)
#define  TP_TP_TF0_P_CNTL_tp_err_fix_en_shift                                    (17)
#define  TP_TP_TF0_P_CNTL_strm_id_en_shift                                       (16)
#define  TP_TP_TF0_P_CNTL_buf_rdy_ctl_shift                                      (15)
#define  TP_TP_TF0_P_CNTL_psc_en_shift                                           (14)
#define  TP_TP_TF0_P_CNTL_pes_en_shift                                           (13)
#define  TP_TP_TF0_P_CNTL_tsc_en_shift                                           (12)
#define  TP_TP_TF0_P_CNTL_tb_shift                                               (11)
#define  TP_TP_TF0_P_CNTL_busy_shift                                             (10)
#define  TP_TP_TF0_P_CNTL_mode_shift                                             (9)
#define  TP_TP_TF0_P_CNTL_du_en_shift                                            (8)
#define  TP_TP_TF0_P_CNTL_de_en_shift                                            (7)
#define  TP_TP_TF0_P_CNTL_xt_en_shift                                            (6)
#define  TP_TP_TF0_P_CNTL_pid_en_shift                                           (5)
#define  TP_TP_TF0_P_CNTL_null_en_shift                                          (4)
#define  TP_TP_TF0_P_CNTL_trerr_en_shift                                         (3)
#define  TP_TP_TF0_P_CNTL_sync_en_shift                                          (2)
#define  TP_TP_TF0_P_CNTL_rst_en_shift                                           (1)
#define  TP_TP_TF0_P_CNTL_write_data_shift                                       (0)
#define  TP_TP_TF0_P_CNTL_two_bit_mask                                           (0x80000000)
#define  TP_TP_TF0_P_CNTL_two_bit_reverse_mask                                   (0x40000000)
#define  TP_TP_TF0_P_CNTL_two_bit_sel_h_mask                                     (0x20000000)
#define  TP_TP_TF0_P_CNTL_two_bit_sel_l_mask                                     (0x10000000)
#define  TP_TP_TF0_P_CNTL_src_sel_h_mask                                         (0x02000000)
#define  TP_TP_TF0_P_CNTL_src_sel_l_mask                                         (0x01000000)
#define  TP_TP_TF0_P_CNTL_dir_dma_mask                                           (0x00800000)
#define  TP_TP_TF0_P_CNTL_ci_mode_mask                                           (0x00040000)
#define  TP_TP_TF0_P_CNTL_tp_err_fix_en_mask                                     (0x00020000)
#define  TP_TP_TF0_P_CNTL_strm_id_en_mask                                        (0x00010000)
#define  TP_TP_TF0_P_CNTL_buf_rdy_ctl_mask                                       (0x00008000)
#define  TP_TP_TF0_P_CNTL_psc_en_mask                                            (0x00004000)
#define  TP_TP_TF0_P_CNTL_pes_en_mask                                            (0x00002000)
#define  TP_TP_TF0_P_CNTL_tsc_en_mask                                            (0x00001000)
#define  TP_TP_TF0_P_CNTL_tb_mask                                                (0x00000800)
#define  TP_TP_TF0_P_CNTL_busy_mask                                              (0x00000400)
#define  TP_TP_TF0_P_CNTL_mode_mask                                              (0x00000200)
#define  TP_TP_TF0_P_CNTL_du_en_mask                                             (0x00000100)
#define  TP_TP_TF0_P_CNTL_de_en_mask                                             (0x00000080)
#define  TP_TP_TF0_P_CNTL_xt_en_mask                                             (0x00000040)
#define  TP_TP_TF0_P_CNTL_pid_en_mask                                            (0x00000020)
#define  TP_TP_TF0_P_CNTL_null_en_mask                                           (0x00000010)
#define  TP_TP_TF0_P_CNTL_trerr_en_mask                                          (0x00000008)
#define  TP_TP_TF0_P_CNTL_sync_en_mask                                           (0x00000004)
#define  TP_TP_TF0_P_CNTL_rst_en_mask                                            (0x00000002)
#define  TP_TP_TF0_P_CNTL_write_data_mask                                        (0x00000001)
#define  TP_TP_TF0_P_CNTL_two_bit(data)                                          (0x80000000&((data)<<31))
#define  TP_TP_TF0_P_CNTL_two_bit_reverse(data)                                  (0x40000000&((data)<<30))
#define  TP_TP_TF0_P_CNTL_two_bit_sel_h(data)                                    (0x20000000&((data)<<29))
#define  TP_TP_TF0_P_CNTL_two_bit_sel_l(data)                                    (0x10000000&((data)<<28))
#define  TP_TP_TF0_P_CNTL_src_sel_h(data)                                        (0x02000000&((data)<<25))
#define  TP_TP_TF0_P_CNTL_src_sel_l(data)                                        (0x01000000&((data)<<24))
#define  TP_TP_TF0_P_CNTL_dir_dma(data)                                          (0x00800000&((data)<<23))
#define  TP_TP_TF0_P_CNTL_ci_mode(data)                                          (0x00040000&((data)<<18))
#define  TP_TP_TF0_P_CNTL_tp_err_fix_en(data)                                    (0x00020000&((data)<<17))
#define  TP_TP_TF0_P_CNTL_strm_id_en(data)                                       (0x00010000&((data)<<16))
#define  TP_TP_TF0_P_CNTL_buf_rdy_ctl(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF0_P_CNTL_psc_en(data)                                           (0x00004000&((data)<<14))
#define  TP_TP_TF0_P_CNTL_pes_en(data)                                           (0x00002000&((data)<<13))
#define  TP_TP_TF0_P_CNTL_tsc_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF0_P_CNTL_tb(data)                                               (0x00000800&((data)<<11))
#define  TP_TP_TF0_P_CNTL_busy(data)                                             (0x00000400&((data)<<10))
#define  TP_TP_TF0_P_CNTL_mode(data)                                             (0x00000200&((data)<<9))
#define  TP_TP_TF0_P_CNTL_du_en(data)                                            (0x00000100&((data)<<8))
#define  TP_TP_TF0_P_CNTL_de_en(data)                                            (0x00000080&((data)<<7))
#define  TP_TP_TF0_P_CNTL_xt_en(data)                                            (0x00000040&((data)<<6))
#define  TP_TP_TF0_P_CNTL_pid_en(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF0_P_CNTL_null_en(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF0_P_CNTL_trerr_en(data)                                         (0x00000008&((data)<<3))
#define  TP_TP_TF0_P_CNTL_sync_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF0_P_CNTL_rst_en(data)                                           (0x00000002&((data)<<1))
#define  TP_TP_TF0_P_CNTL_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF0_P_CNTL_get_two_bit(data)                                      ((0x80000000&(data))>>31)
#define  TP_TP_TF0_P_CNTL_get_two_bit_reverse(data)                              ((0x40000000&(data))>>30)
#define  TP_TP_TF0_P_CNTL_get_two_bit_sel_h(data)                                ((0x20000000&(data))>>29)
#define  TP_TP_TF0_P_CNTL_get_two_bit_sel_l(data)                                ((0x10000000&(data))>>28)
#define  TP_TP_TF0_P_CNTL_get_src_sel_h(data)                                    ((0x02000000&(data))>>25)
#define  TP_TP_TF0_P_CNTL_get_src_sel_l(data)                                    ((0x01000000&(data))>>24)
#define  TP_TP_TF0_P_CNTL_get_dir_dma(data)                                      ((0x00800000&(data))>>23)
#define  TP_TP_TF0_P_CNTL_get_ci_mode(data)                                      ((0x00040000&(data))>>18)
#define  TP_TP_TF0_P_CNTL_get_tp_err_fix_en(data)                                ((0x00020000&(data))>>17)
#define  TP_TP_TF0_P_CNTL_get_strm_id_en(data)                                   ((0x00010000&(data))>>16)
#define  TP_TP_TF0_P_CNTL_get_buf_rdy_ctl(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF0_P_CNTL_get_psc_en(data)                                       ((0x00004000&(data))>>14)
#define  TP_TP_TF0_P_CNTL_get_pes_en(data)                                       ((0x00002000&(data))>>13)
#define  TP_TP_TF0_P_CNTL_get_tsc_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF0_P_CNTL_get_tb(data)                                           ((0x00000800&(data))>>11)
#define  TP_TP_TF0_P_CNTL_get_busy(data)                                         ((0x00000400&(data))>>10)
#define  TP_TP_TF0_P_CNTL_get_mode(data)                                         ((0x00000200&(data))>>9)
#define  TP_TP_TF0_P_CNTL_get_du_en(data)                                        ((0x00000100&(data))>>8)
#define  TP_TP_TF0_P_CNTL_get_de_en(data)                                        ((0x00000080&(data))>>7)
#define  TP_TP_TF0_P_CNTL_get_xt_en(data)                                        ((0x00000040&(data))>>6)
#define  TP_TP_TF0_P_CNTL_get_pid_en(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF0_P_CNTL_get_null_en(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF0_P_CNTL_get_trerr_en(data)                                     ((0x00000008&(data))>>3)
#define  TP_TP_TF0_P_CNTL_get_sync_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF0_P_CNTL_get_rst_en(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP_TF0_P_CNTL_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF0_P_CNT                                                         0x18014518
#define  TP_TP_TF0_P_CNT_reg_addr                                                "0xB8014518"
#define  TP_TP_TF0_P_CNT_reg                                                     0xB8014518
#define  TP_TP_TF0_P_CNT_inst_addr                                               "0x009E"
#define  set_TP_TP_TF0_P_CNT_reg(data)                                           (*((volatile unsigned int*)TP_TP_TF0_P_CNT_reg)=data)
#define  get_TP_TP_TF0_P_CNT_reg                                                 (*((volatile unsigned int*)TP_TP_TF0_P_CNT_reg))
#define  TP_TP_TF0_P_CNT_cnt_shift                                               (0)
#define  TP_TP_TF0_P_CNT_cnt_mask                                                (0x00FFFFFF)
#define  TP_TP_TF0_P_CNT_cnt(data)                                               (0x00FFFFFF&(data))
#define  TP_TP_TF0_P_CNT_get_cnt(data)                                           (0x00FFFFFF&(data))

#define  TP_TP_TF0_P_DRP_CNT                                                     0x1801451C
#define  TP_TP_TF0_P_DRP_CNT_reg_addr                                            "0xB801451C"
#define  TP_TP_TF0_P_DRP_CNT_reg                                                 0xB801451C
#define  TP_TP_TF0_P_DRP_CNT_inst_addr                                           "0x009F"
#define  set_TP_TP_TF0_P_DRP_CNT_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF0_P_DRP_CNT_reg)=data)
#define  get_TP_TP_TF0_P_DRP_CNT_reg                                             (*((volatile unsigned int*)TP_TP_TF0_P_DRP_CNT_reg))
#define  TP_TP_TF0_P_DRP_CNT_drp_cnt_shift                                       (0)
#define  TP_TP_TF0_P_DRP_CNT_drp_cnt_mask                                        (0x0000FFFF)
#define  TP_TP_TF0_P_DRP_CNT_drp_cnt(data)                                       (0x0000FFFF&(data))
#define  TP_TP_TF0_P_DRP_CNT_get_drp_cnt(data)                                   (0x0000FFFF&(data))

#define  TP_TP_TF0_P_FRMCFG                                                      0x18014524
#define  TP_TP_TF0_P_FRMCFG_reg_addr                                             "0xB8014524"
#define  TP_TP_TF0_P_FRMCFG_reg                                                  0xB8014524
#define  TP_TP_TF0_P_FRMCFG_inst_addr                                            "0x00A0"
#define  set_TP_TP_TF0_P_FRMCFG_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF0_P_FRMCFG_reg)=data)
#define  get_TP_TP_TF0_P_FRMCFG_reg                                              (*((volatile unsigned int*)TP_TP_TF0_P_FRMCFG_reg))
#define  TP_TP_TF0_P_FRMCFG_sync_byte_shift                                      (24)
#define  TP_TP_TF0_P_FRMCFG_dropno_shift                                         (20)
#define  TP_TP_TF0_P_FRMCFG_lockno_shift                                         (16)
#define  TP_TP_TF0_P_FRMCFG_packet_size_shift                                    (14)
#define  TP_TP_TF0_P_FRMCFG_data_order_shift                                     (13)
#define  TP_TP_TF0_P_FRMCFG_frm_en_shift                                         (12)
#define  TP_TP_TF0_P_FRMCFG_forcedrop_shift                                      (11)
#define  TP_TP_TF0_P_FRMCFG_syncmode_shift                                       (6)
#define  TP_TP_TF0_P_FRMCFG_serial_shift                                         (5)
#define  TP_TP_TF0_P_FRMCFG_datapin_shift                                        (4)
#define  TP_TP_TF0_P_FRMCFG_sync_byte_mask                                       (0xFF000000)
#define  TP_TP_TF0_P_FRMCFG_dropno_mask                                          (0x00F00000)
#define  TP_TP_TF0_P_FRMCFG_lockno_mask                                          (0x000F0000)
#define  TP_TP_TF0_P_FRMCFG_packet_size_mask                                     (0x0000C000)
#define  TP_TP_TF0_P_FRMCFG_data_order_mask                                      (0x00002000)
#define  TP_TP_TF0_P_FRMCFG_frm_en_mask                                          (0x00001000)
#define  TP_TP_TF0_P_FRMCFG_forcedrop_mask                                       (0x00000800)
#define  TP_TP_TF0_P_FRMCFG_syncmode_mask                                        (0x000007C0)
#define  TP_TP_TF0_P_FRMCFG_serial_mask                                          (0x00000020)
#define  TP_TP_TF0_P_FRMCFG_datapin_mask                                         (0x00000010)
#define  TP_TP_TF0_P_FRMCFG_sync_byte(data)                                      (0xFF000000&((data)<<24))
#define  TP_TP_TF0_P_FRMCFG_dropno(data)                                         (0x00F00000&((data)<<20))
#define  TP_TP_TF0_P_FRMCFG_lockno(data)                                         (0x000F0000&((data)<<16))
#define  TP_TP_TF0_P_FRMCFG_packet_size(data)                                    (0x0000C000&((data)<<14))
#define  TP_TP_TF0_P_FRMCFG_data_order(data)                                     (0x00002000&((data)<<13))
#define  TP_TP_TF0_P_FRMCFG_frm_en(data)                                         (0x00001000&((data)<<12))
#define  TP_TP_TF0_P_FRMCFG_forcedrop(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF0_P_FRMCFG_syncmode(data)                                       (0x000007C0&((data)<<6))
#define  TP_TP_TF0_P_FRMCFG_serial(data)                                         (0x00000020&((data)<<5))
#define  TP_TP_TF0_P_FRMCFG_datapin(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_TF0_P_FRMCFG_get_sync_byte(data)                                  ((0xFF000000&(data))>>24)
#define  TP_TP_TF0_P_FRMCFG_get_dropno(data)                                     ((0x00F00000&(data))>>20)
#define  TP_TP_TF0_P_FRMCFG_get_lockno(data)                                     ((0x000F0000&(data))>>16)
#define  TP_TP_TF0_P_FRMCFG_get_packet_size(data)                                ((0x0000C000&(data))>>14)
#define  TP_TP_TF0_P_FRMCFG_get_data_order(data)                                 ((0x00002000&(data))>>13)
#define  TP_TP_TF0_P_FRMCFG_get_frm_en(data)                                     ((0x00001000&(data))>>12)
#define  TP_TP_TF0_P_FRMCFG_get_forcedrop(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF0_P_FRMCFG_get_syncmode(data)                                   ((0x000007C0&(data))>>6)
#define  TP_TP_TF0_P_FRMCFG_get_serial(data)                                     ((0x00000020&(data))>>5)
#define  TP_TP_TF0_P_FRMCFG_get_datapin(data)                                    ((0x00000010&(data))>>4)

#define  TP_TP_TF0_P_INT                                                         0x18014528
#define  TP_TP_TF0_P_INT_reg_addr                                                "0xB8014528"
#define  TP_TP_TF0_P_INT_reg                                                     0xB8014528
#define  TP_TP_TF0_P_INT_inst_addr                                               "0x00A1"
#define  set_TP_TP_TF0_P_INT_reg(data)                                           (*((volatile unsigned int*)TP_TP_TF0_P_INT_reg)=data)
#define  get_TP_TP_TF0_P_INT_reg                                                 (*((volatile unsigned int*)TP_TP_TF0_P_INT_reg))
#define  TP_TP_TF0_P_INT_adf_pcr_in_shift                                        (4)
#define  TP_TP_TF0_P_INT_overflow_shift                                          (3)
#define  TP_TP_TF0_P_INT_drop_shift                                              (2)
#define  TP_TP_TF0_P_INT_sync_shift                                              (1)
#define  TP_TP_TF0_P_INT_write_data_shift                                        (0)
#define  TP_TP_TF0_P_INT_adf_pcr_in_mask                                         (0x00000010)
#define  TP_TP_TF0_P_INT_overflow_mask                                           (0x00000008)
#define  TP_TP_TF0_P_INT_drop_mask                                               (0x00000004)
#define  TP_TP_TF0_P_INT_sync_mask                                               (0x00000002)
#define  TP_TP_TF0_P_INT_write_data_mask                                         (0x00000001)
#define  TP_TP_TF0_P_INT_adf_pcr_in(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_TF0_P_INT_overflow(data)                                          (0x00000008&((data)<<3))
#define  TP_TP_TF0_P_INT_drop(data)                                              (0x00000004&((data)<<2))
#define  TP_TP_TF0_P_INT_sync(data)                                              (0x00000002&((data)<<1))
#define  TP_TP_TF0_P_INT_write_data(data)                                        (0x00000001&(data))
#define  TP_TP_TF0_P_INT_get_adf_pcr_in(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP_TF0_P_INT_get_overflow(data)                                      ((0x00000008&(data))>>3)
#define  TP_TP_TF0_P_INT_get_drop(data)                                          ((0x00000004&(data))>>2)
#define  TP_TP_TF0_P_INT_get_sync(data)                                          ((0x00000002&(data))>>1)
#define  TP_TP_TF0_P_INT_get_write_data(data)                                    (0x00000001&(data))

#define  TP_TP_TF0_P_INT_EN                                                      0x1801452C
#define  TP_TP_TF0_P_INT_EN_reg_addr                                             "0xB801452C"
#define  TP_TP_TF0_P_INT_EN_reg                                                  0xB801452C
#define  TP_TP_TF0_P_INT_EN_inst_addr                                            "0x00A2"
#define  set_TP_TP_TF0_P_INT_EN_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF0_P_INT_EN_reg)=data)
#define  get_TP_TP_TF0_P_INT_EN_reg                                              (*((volatile unsigned int*)TP_TP_TF0_P_INT_EN_reg))
#define  TP_TP_TF0_P_INT_EN_adf_pcr_in_en_shift                                  (4)
#define  TP_TP_TF0_P_INT_EN_overflow_en_shift                                    (3)
#define  TP_TP_TF0_P_INT_EN_drop_en_shift                                        (2)
#define  TP_TP_TF0_P_INT_EN_sync_en_shift                                        (1)
#define  TP_TP_TF0_P_INT_EN_write_data_shift                                     (0)
#define  TP_TP_TF0_P_INT_EN_adf_pcr_in_en_mask                                   (0x00000010)
#define  TP_TP_TF0_P_INT_EN_overflow_en_mask                                     (0x00000008)
#define  TP_TP_TF0_P_INT_EN_drop_en_mask                                         (0x00000004)
#define  TP_TP_TF0_P_INT_EN_sync_en_mask                                         (0x00000002)
#define  TP_TP_TF0_P_INT_EN_write_data_mask                                      (0x00000001)
#define  TP_TP_TF0_P_INT_EN_adf_pcr_in_en(data)                                  (0x00000010&((data)<<4))
#define  TP_TP_TF0_P_INT_EN_overflow_en(data)                                    (0x00000008&((data)<<3))
#define  TP_TP_TF0_P_INT_EN_drop_en(data)                                        (0x00000004&((data)<<2))
#define  TP_TP_TF0_P_INT_EN_sync_en(data)                                        (0x00000002&((data)<<1))
#define  TP_TP_TF0_P_INT_EN_write_data(data)                                     (0x00000001&(data))
#define  TP_TP_TF0_P_INT_EN_get_adf_pcr_in_en(data)                              ((0x00000010&(data))>>4)
#define  TP_TP_TF0_P_INT_EN_get_overflow_en(data)                                ((0x00000008&(data))>>3)
#define  TP_TP_TF0_P_INT_EN_get_drop_en(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP_TF0_P_INT_EN_get_sync_en(data)                                    ((0x00000002&(data))>>1)
#define  TP_TP_TF0_P_INT_EN_get_write_data(data)                                 (0x00000001&(data))

#define  TP_TP_TF1_P_CNTL                                                        0x18014530
#define  TP_TP_TF1_P_CNTL_reg_addr                                               "0xB8014530"
#define  TP_TP_TF1_P_CNTL_reg                                                    0xB8014530
#define  TP_TP_TF1_P_CNTL_inst_addr                                              "0x00A3"
#define  set_TP_TP_TF1_P_CNTL_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF1_P_CNTL_reg)=data)
#define  get_TP_TP_TF1_P_CNTL_reg                                                (*((volatile unsigned int*)TP_TP_TF1_P_CNTL_reg))
#define  TP_TP_TF1_P_CNTL_two_bit_shift                                          (31)
#define  TP_TP_TF1_P_CNTL_two_bit_reverse_shift                                  (30)
#define  TP_TP_TF1_P_CNTL_two_bit_sel_h_shift                                    (29)
#define  TP_TP_TF1_P_CNTL_two_bit_sel_l_shift                                    (28)
#define  TP_TP_TF1_P_CNTL_src_sel_h_shift                                        (25)
#define  TP_TP_TF1_P_CNTL_src_sel_l_shift                                        (24)
#define  TP_TP_TF1_P_CNTL_dir_dma_shift                                          (23)
#define  TP_TP_TF1_P_CNTL_ci_mode_shift                                          (18)
#define  TP_TP_TF1_P_CNTL_tp_err_fix_en_shift                                    (17)
#define  TP_TP_TF1_P_CNTL_strm_id_en_shift                                       (16)
#define  TP_TP_TF1_P_CNTL_buf_rdy_ctl_shift                                      (15)
#define  TP_TP_TF1_P_CNTL_psc_en_shift                                           (14)
#define  TP_TP_TF1_P_CNTL_pes_en_shift                                           (13)
#define  TP_TP_TF1_P_CNTL_tsc_en_shift                                           (12)
#define  TP_TP_TF1_P_CNTL_tb_shift                                               (11)
#define  TP_TP_TF1_P_CNTL_busy_shift                                             (10)
#define  TP_TP_TF1_P_CNTL_mode_shift                                             (9)
#define  TP_TP_TF1_P_CNTL_du_en_shift                                            (8)
#define  TP_TP_TF1_P_CNTL_de_en_shift                                            (7)
#define  TP_TP_TF1_P_CNTL_xt_en_shift                                            (6)
#define  TP_TP_TF1_P_CNTL_pid_en_shift                                           (5)
#define  TP_TP_TF1_P_CNTL_null_en_shift                                          (4)
#define  TP_TP_TF1_P_CNTL_trerr_en_shift                                         (3)
#define  TP_TP_TF1_P_CNTL_sync_en_shift                                          (2)
#define  TP_TP_TF1_P_CNTL_rst_en_shift                                           (1)
#define  TP_TP_TF1_P_CNTL_write_data_shift                                       (0)
#define  TP_TP_TF1_P_CNTL_two_bit_mask                                           (0x80000000)
#define  TP_TP_TF1_P_CNTL_two_bit_reverse_mask                                   (0x40000000)
#define  TP_TP_TF1_P_CNTL_two_bit_sel_h_mask                                     (0x20000000)
#define  TP_TP_TF1_P_CNTL_two_bit_sel_l_mask                                     (0x10000000)
#define  TP_TP_TF1_P_CNTL_src_sel_h_mask                                         (0x02000000)
#define  TP_TP_TF1_P_CNTL_src_sel_l_mask                                         (0x01000000)
#define  TP_TP_TF1_P_CNTL_dir_dma_mask                                           (0x00800000)
#define  TP_TP_TF1_P_CNTL_ci_mode_mask                                           (0x00040000)
#define  TP_TP_TF1_P_CNTL_tp_err_fix_en_mask                                     (0x00020000)
#define  TP_TP_TF1_P_CNTL_strm_id_en_mask                                        (0x00010000)
#define  TP_TP_TF1_P_CNTL_buf_rdy_ctl_mask                                       (0x00008000)
#define  TP_TP_TF1_P_CNTL_psc_en_mask                                            (0x00004000)
#define  TP_TP_TF1_P_CNTL_pes_en_mask                                            (0x00002000)
#define  TP_TP_TF1_P_CNTL_tsc_en_mask                                            (0x00001000)
#define  TP_TP_TF1_P_CNTL_tb_mask                                                (0x00000800)
#define  TP_TP_TF1_P_CNTL_busy_mask                                              (0x00000400)
#define  TP_TP_TF1_P_CNTL_mode_mask                                              (0x00000200)
#define  TP_TP_TF1_P_CNTL_du_en_mask                                             (0x00000100)
#define  TP_TP_TF1_P_CNTL_de_en_mask                                             (0x00000080)
#define  TP_TP_TF1_P_CNTL_xt_en_mask                                             (0x00000040)
#define  TP_TP_TF1_P_CNTL_pid_en_mask                                            (0x00000020)
#define  TP_TP_TF1_P_CNTL_null_en_mask                                           (0x00000010)
#define  TP_TP_TF1_P_CNTL_trerr_en_mask                                          (0x00000008)
#define  TP_TP_TF1_P_CNTL_sync_en_mask                                           (0x00000004)
#define  TP_TP_TF1_P_CNTL_rst_en_mask                                            (0x00000002)
#define  TP_TP_TF1_P_CNTL_write_data_mask                                        (0x00000001)
#define  TP_TP_TF1_P_CNTL_two_bit(data)                                          (0x80000000&((data)<<31))
#define  TP_TP_TF1_P_CNTL_two_bit_reverse(data)                                  (0x40000000&((data)<<30))
#define  TP_TP_TF1_P_CNTL_two_bit_sel_h(data)                                    (0x20000000&((data)<<29))
#define  TP_TP_TF1_P_CNTL_two_bit_sel_l(data)                                    (0x10000000&((data)<<28))
#define  TP_TP_TF1_P_CNTL_src_sel_h(data)                                        (0x02000000&((data)<<25))
#define  TP_TP_TF1_P_CNTL_src_sel_l(data)                                        (0x01000000&((data)<<24))
#define  TP_TP_TF1_P_CNTL_dir_dma(data)                                          (0x00800000&((data)<<23))
#define  TP_TP_TF1_P_CNTL_ci_mode(data)                                          (0x00040000&((data)<<18))
#define  TP_TP_TF1_P_CNTL_tp_err_fix_en(data)                                    (0x00020000&((data)<<17))
#define  TP_TP_TF1_P_CNTL_strm_id_en(data)                                       (0x00010000&((data)<<16))
#define  TP_TP_TF1_P_CNTL_buf_rdy_ctl(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF1_P_CNTL_psc_en(data)                                           (0x00004000&((data)<<14))
#define  TP_TP_TF1_P_CNTL_pes_en(data)                                           (0x00002000&((data)<<13))
#define  TP_TP_TF1_P_CNTL_tsc_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF1_P_CNTL_tb(data)                                               (0x00000800&((data)<<11))
#define  TP_TP_TF1_P_CNTL_busy(data)                                             (0x00000400&((data)<<10))
#define  TP_TP_TF1_P_CNTL_mode(data)                                             (0x00000200&((data)<<9))
#define  TP_TP_TF1_P_CNTL_du_en(data)                                            (0x00000100&((data)<<8))
#define  TP_TP_TF1_P_CNTL_de_en(data)                                            (0x00000080&((data)<<7))
#define  TP_TP_TF1_P_CNTL_xt_en(data)                                            (0x00000040&((data)<<6))
#define  TP_TP_TF1_P_CNTL_pid_en(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF1_P_CNTL_null_en(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF1_P_CNTL_trerr_en(data)                                         (0x00000008&((data)<<3))
#define  TP_TP_TF1_P_CNTL_sync_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF1_P_CNTL_rst_en(data)                                           (0x00000002&((data)<<1))
#define  TP_TP_TF1_P_CNTL_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF1_P_CNTL_get_two_bit(data)                                      ((0x80000000&(data))>>31)
#define  TP_TP_TF1_P_CNTL_get_two_bit_reverse(data)                              ((0x40000000&(data))>>30)
#define  TP_TP_TF1_P_CNTL_get_two_bit_sel_h(data)                                ((0x20000000&(data))>>29)
#define  TP_TP_TF1_P_CNTL_get_two_bit_sel_l(data)                                ((0x10000000&(data))>>28)
#define  TP_TP_TF1_P_CNTL_get_src_sel_h(data)                                    ((0x02000000&(data))>>25)
#define  TP_TP_TF1_P_CNTL_get_src_sel_l(data)                                    ((0x01000000&(data))>>24)
#define  TP_TP_TF1_P_CNTL_get_dir_dma(data)                                      ((0x00800000&(data))>>23)
#define  TP_TP_TF1_P_CNTL_get_ci_mode(data)                                      ((0x00040000&(data))>>18)
#define  TP_TP_TF1_P_CNTL_get_tp_err_fix_en(data)                                ((0x00020000&(data))>>17)
#define  TP_TP_TF1_P_CNTL_get_strm_id_en(data)                                   ((0x00010000&(data))>>16)
#define  TP_TP_TF1_P_CNTL_get_buf_rdy_ctl(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF1_P_CNTL_get_psc_en(data)                                       ((0x00004000&(data))>>14)
#define  TP_TP_TF1_P_CNTL_get_pes_en(data)                                       ((0x00002000&(data))>>13)
#define  TP_TP_TF1_P_CNTL_get_tsc_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF1_P_CNTL_get_tb(data)                                           ((0x00000800&(data))>>11)
#define  TP_TP_TF1_P_CNTL_get_busy(data)                                         ((0x00000400&(data))>>10)
#define  TP_TP_TF1_P_CNTL_get_mode(data)                                         ((0x00000200&(data))>>9)
#define  TP_TP_TF1_P_CNTL_get_du_en(data)                                        ((0x00000100&(data))>>8)
#define  TP_TP_TF1_P_CNTL_get_de_en(data)                                        ((0x00000080&(data))>>7)
#define  TP_TP_TF1_P_CNTL_get_xt_en(data)                                        ((0x00000040&(data))>>6)
#define  TP_TP_TF1_P_CNTL_get_pid_en(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF1_P_CNTL_get_null_en(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF1_P_CNTL_get_trerr_en(data)                                     ((0x00000008&(data))>>3)
#define  TP_TP_TF1_P_CNTL_get_sync_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF1_P_CNTL_get_rst_en(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP_TF1_P_CNTL_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF1_P_CNT                                                         0x18014548
#define  TP_TP_TF1_P_CNT_reg_addr                                                "0xB8014548"
#define  TP_TP_TF1_P_CNT_reg                                                     0xB8014548
#define  TP_TP_TF1_P_CNT_inst_addr                                               "0x00A4"
#define  set_TP_TP_TF1_P_CNT_reg(data)                                           (*((volatile unsigned int*)TP_TP_TF1_P_CNT_reg)=data)
#define  get_TP_TP_TF1_P_CNT_reg                                                 (*((volatile unsigned int*)TP_TP_TF1_P_CNT_reg))
#define  TP_TP_TF1_P_CNT_cnt_shift                                               (0)
#define  TP_TP_TF1_P_CNT_cnt_mask                                                (0x00FFFFFF)
#define  TP_TP_TF1_P_CNT_cnt(data)                                               (0x00FFFFFF&(data))
#define  TP_TP_TF1_P_CNT_get_cnt(data)                                           (0x00FFFFFF&(data))

#define  TP_TP_TF1_P_DRP_CNT                                                     0x1801454C
#define  TP_TP_TF1_P_DRP_CNT_reg_addr                                            "0xB801454C"
#define  TP_TP_TF1_P_DRP_CNT_reg                                                 0xB801454C
#define  TP_TP_TF1_P_DRP_CNT_inst_addr                                           "0x00A5"
#define  set_TP_TP_TF1_P_DRP_CNT_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF1_P_DRP_CNT_reg)=data)
#define  get_TP_TP_TF1_P_DRP_CNT_reg                                             (*((volatile unsigned int*)TP_TP_TF1_P_DRP_CNT_reg))
#define  TP_TP_TF1_P_DRP_CNT_drp_cnt_shift                                       (0)
#define  TP_TP_TF1_P_DRP_CNT_drp_cnt_mask                                        (0x0000FFFF)
#define  TP_TP_TF1_P_DRP_CNT_drp_cnt(data)                                       (0x0000FFFF&(data))
#define  TP_TP_TF1_P_DRP_CNT_get_drp_cnt(data)                                   (0x0000FFFF&(data))

#define  TP_TP_TF1_P_FRMCFG                                                      0x18014554
#define  TP_TP_TF1_P_FRMCFG_reg_addr                                             "0xB8014554"
#define  TP_TP_TF1_P_FRMCFG_reg                                                  0xB8014554
#define  TP_TP_TF1_P_FRMCFG_inst_addr                                            "0x00A6"
#define  set_TP_TP_TF1_P_FRMCFG_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF1_P_FRMCFG_reg)=data)
#define  get_TP_TP_TF1_P_FRMCFG_reg                                              (*((volatile unsigned int*)TP_TP_TF1_P_FRMCFG_reg))
#define  TP_TP_TF1_P_FRMCFG_sync_byte_shift                                      (24)
#define  TP_TP_TF1_P_FRMCFG_dropno_shift                                         (20)
#define  TP_TP_TF1_P_FRMCFG_lockno_shift                                         (16)
#define  TP_TP_TF1_P_FRMCFG_packet_size_shift                                    (14)
#define  TP_TP_TF1_P_FRMCFG_data_order_shift                                     (13)
#define  TP_TP_TF1_P_FRMCFG_frm_en_shift                                         (12)
#define  TP_TP_TF1_P_FRMCFG_forcedrop_shift                                      (11)
#define  TP_TP_TF1_P_FRMCFG_syncmode_shift                                       (6)
#define  TP_TP_TF1_P_FRMCFG_serial_shift                                         (5)
#define  TP_TP_TF1_P_FRMCFG_datapin_shift                                        (4)
#define  TP_TP_TF1_P_FRMCFG_sync_byte_mask                                       (0xFF000000)
#define  TP_TP_TF1_P_FRMCFG_dropno_mask                                          (0x00F00000)
#define  TP_TP_TF1_P_FRMCFG_lockno_mask                                          (0x000F0000)
#define  TP_TP_TF1_P_FRMCFG_packet_size_mask                                     (0x0000C000)
#define  TP_TP_TF1_P_FRMCFG_data_order_mask                                      (0x00002000)
#define  TP_TP_TF1_P_FRMCFG_frm_en_mask                                          (0x00001000)
#define  TP_TP_TF1_P_FRMCFG_forcedrop_mask                                       (0x00000800)
#define  TP_TP_TF1_P_FRMCFG_syncmode_mask                                        (0x000007C0)
#define  TP_TP_TF1_P_FRMCFG_serial_mask                                          (0x00000020)
#define  TP_TP_TF1_P_FRMCFG_datapin_mask                                         (0x00000010)
#define  TP_TP_TF1_P_FRMCFG_sync_byte(data)                                      (0xFF000000&((data)<<24))
#define  TP_TP_TF1_P_FRMCFG_dropno(data)                                         (0x00F00000&((data)<<20))
#define  TP_TP_TF1_P_FRMCFG_lockno(data)                                         (0x000F0000&((data)<<16))
#define  TP_TP_TF1_P_FRMCFG_packet_size(data)                                    (0x0000C000&((data)<<14))
#define  TP_TP_TF1_P_FRMCFG_data_order(data)                                     (0x00002000&((data)<<13))
#define  TP_TP_TF1_P_FRMCFG_frm_en(data)                                         (0x00001000&((data)<<12))
#define  TP_TP_TF1_P_FRMCFG_forcedrop(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF1_P_FRMCFG_syncmode(data)                                       (0x000007C0&((data)<<6))
#define  TP_TP_TF1_P_FRMCFG_serial(data)                                         (0x00000020&((data)<<5))
#define  TP_TP_TF1_P_FRMCFG_datapin(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_TF1_P_FRMCFG_get_sync_byte(data)                                  ((0xFF000000&(data))>>24)
#define  TP_TP_TF1_P_FRMCFG_get_dropno(data)                                     ((0x00F00000&(data))>>20)
#define  TP_TP_TF1_P_FRMCFG_get_lockno(data)                                     ((0x000F0000&(data))>>16)
#define  TP_TP_TF1_P_FRMCFG_get_packet_size(data)                                ((0x0000C000&(data))>>14)
#define  TP_TP_TF1_P_FRMCFG_get_data_order(data)                                 ((0x00002000&(data))>>13)
#define  TP_TP_TF1_P_FRMCFG_get_frm_en(data)                                     ((0x00001000&(data))>>12)
#define  TP_TP_TF1_P_FRMCFG_get_forcedrop(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF1_P_FRMCFG_get_syncmode(data)                                   ((0x000007C0&(data))>>6)
#define  TP_TP_TF1_P_FRMCFG_get_serial(data)                                     ((0x00000020&(data))>>5)
#define  TP_TP_TF1_P_FRMCFG_get_datapin(data)                                    ((0x00000010&(data))>>4)

#define  TP_TP_TF1_P_INT                                                         0x18014558
#define  TP_TP_TF1_P_INT_reg_addr                                                "0xB8014558"
#define  TP_TP_TF1_P_INT_reg                                                     0xB8014558
#define  TP_TP_TF1_P_INT_inst_addr                                               "0x00A7"
#define  set_TP_TP_TF1_P_INT_reg(data)                                           (*((volatile unsigned int*)TP_TP_TF1_P_INT_reg)=data)
#define  get_TP_TP_TF1_P_INT_reg                                                 (*((volatile unsigned int*)TP_TP_TF1_P_INT_reg))
#define  TP_TP_TF1_P_INT_adf_pcr_in_shift                                        (4)
#define  TP_TP_TF1_P_INT_overflow_shift                                          (3)
#define  TP_TP_TF1_P_INT_drop_shift                                              (2)
#define  TP_TP_TF1_P_INT_sync_shift                                              (1)
#define  TP_TP_TF1_P_INT_write_data_shift                                        (0)
#define  TP_TP_TF1_P_INT_adf_pcr_in_mask                                         (0x00000010)
#define  TP_TP_TF1_P_INT_overflow_mask                                           (0x00000008)
#define  TP_TP_TF1_P_INT_drop_mask                                               (0x00000004)
#define  TP_TP_TF1_P_INT_sync_mask                                               (0x00000002)
#define  TP_TP_TF1_P_INT_write_data_mask                                         (0x00000001)
#define  TP_TP_TF1_P_INT_adf_pcr_in(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_TF1_P_INT_overflow(data)                                          (0x00000008&((data)<<3))
#define  TP_TP_TF1_P_INT_drop(data)                                              (0x00000004&((data)<<2))
#define  TP_TP_TF1_P_INT_sync(data)                                              (0x00000002&((data)<<1))
#define  TP_TP_TF1_P_INT_write_data(data)                                        (0x00000001&(data))
#define  TP_TP_TF1_P_INT_get_adf_pcr_in(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP_TF1_P_INT_get_overflow(data)                                      ((0x00000008&(data))>>3)
#define  TP_TP_TF1_P_INT_get_drop(data)                                          ((0x00000004&(data))>>2)
#define  TP_TP_TF1_P_INT_get_sync(data)                                          ((0x00000002&(data))>>1)
#define  TP_TP_TF1_P_INT_get_write_data(data)                                    (0x00000001&(data))

#define  TP_TP_TF1_P_INT_EN                                                      0x1801455C
#define  TP_TP_TF1_P_INT_EN_reg_addr                                             "0xB801455C"
#define  TP_TP_TF1_P_INT_EN_reg                                                  0xB801455C
#define  TP_TP_TF1_P_INT_EN_inst_addr                                            "0x00A8"
#define  set_TP_TP_TF1_P_INT_EN_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF1_P_INT_EN_reg)=data)
#define  get_TP_TP_TF1_P_INT_EN_reg                                              (*((volatile unsigned int*)TP_TP_TF1_P_INT_EN_reg))
#define  TP_TP_TF1_P_INT_EN_adf_pcr_in_en_shift                                  (4)
#define  TP_TP_TF1_P_INT_EN_overflow_en_shift                                    (3)
#define  TP_TP_TF1_P_INT_EN_drop_en_shift                                        (2)
#define  TP_TP_TF1_P_INT_EN_sync_en_shift                                        (1)
#define  TP_TP_TF1_P_INT_EN_write_data_shift                                     (0)
#define  TP_TP_TF1_P_INT_EN_adf_pcr_in_en_mask                                   (0x00000010)
#define  TP_TP_TF1_P_INT_EN_overflow_en_mask                                     (0x00000008)
#define  TP_TP_TF1_P_INT_EN_drop_en_mask                                         (0x00000004)
#define  TP_TP_TF1_P_INT_EN_sync_en_mask                                         (0x00000002)
#define  TP_TP_TF1_P_INT_EN_write_data_mask                                      (0x00000001)
#define  TP_TP_TF1_P_INT_EN_adf_pcr_in_en(data)                                  (0x00000010&((data)<<4))
#define  TP_TP_TF1_P_INT_EN_overflow_en(data)                                    (0x00000008&((data)<<3))
#define  TP_TP_TF1_P_INT_EN_drop_en(data)                                        (0x00000004&((data)<<2))
#define  TP_TP_TF1_P_INT_EN_sync_en(data)                                        (0x00000002&((data)<<1))
#define  TP_TP_TF1_P_INT_EN_write_data(data)                                     (0x00000001&(data))
#define  TP_TP_TF1_P_INT_EN_get_adf_pcr_in_en(data)                              ((0x00000010&(data))>>4)
#define  TP_TP_TF1_P_INT_EN_get_overflow_en(data)                                ((0x00000008&(data))>>3)
#define  TP_TP_TF1_P_INT_EN_get_drop_en(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP_TF1_P_INT_EN_get_sync_en(data)                                    ((0x00000002&(data))>>1)
#define  TP_TP_TF1_P_INT_EN_get_write_data(data)                                 (0x00000001&(data))

#define  TP_TP_TF2_P_CNTL                                                        0x18014560
#define  TP_TP_TF2_P_CNTL_reg_addr                                               "0xB8014560"
#define  TP_TP_TF2_P_CNTL_reg                                                    0xB8014560
#define  TP_TP_TF2_P_CNTL_inst_addr                                              "0x00A9"
#define  set_TP_TP_TF2_P_CNTL_reg(data)                                          (*((volatile unsigned int*)TP_TP_TF2_P_CNTL_reg)=data)
#define  get_TP_TP_TF2_P_CNTL_reg                                                (*((volatile unsigned int*)TP_TP_TF2_P_CNTL_reg))
#define  TP_TP_TF2_P_CNTL_two_bit_shift                                          (31)
#define  TP_TP_TF2_P_CNTL_two_bit_reverse_shift                                  (30)
#define  TP_TP_TF2_P_CNTL_two_bit_sel_h_shift                                    (29)
#define  TP_TP_TF2_P_CNTL_two_bit_sel_l_shift                                    (28)
#define  TP_TP_TF2_P_CNTL_src_sel_h_shift                                        (25)
#define  TP_TP_TF2_P_CNTL_src_sel_l_shift                                        (24)
#define  TP_TP_TF2_P_CNTL_dir_dma_shift                                          (23)
#define  TP_TP_TF2_P_CNTL_ci_mode_shift                                          (18)
#define  TP_TP_TF2_P_CNTL_tp_err_fix_en_shift                                    (17)
#define  TP_TP_TF2_P_CNTL_strm_id_en_shift                                       (16)
#define  TP_TP_TF2_P_CNTL_buf_rdy_ctl_shift                                      (15)
#define  TP_TP_TF2_P_CNTL_psc_en_shift                                           (14)
#define  TP_TP_TF2_P_CNTL_pes_en_shift                                           (13)
#define  TP_TP_TF2_P_CNTL_tsc_en_shift                                           (12)
#define  TP_TP_TF2_P_CNTL_tb_shift                                               (11)
#define  TP_TP_TF2_P_CNTL_busy_shift                                             (10)
#define  TP_TP_TF2_P_CNTL_mode_shift                                             (9)
#define  TP_TP_TF2_P_CNTL_du_en_shift                                            (8)
#define  TP_TP_TF2_P_CNTL_de_en_shift                                            (7)
#define  TP_TP_TF2_P_CNTL_xt_en_shift                                            (6)
#define  TP_TP_TF2_P_CNTL_pid_en_shift                                           (5)
#define  TP_TP_TF2_P_CNTL_null_en_shift                                          (4)
#define  TP_TP_TF2_P_CNTL_trerr_en_shift                                         (3)
#define  TP_TP_TF2_P_CNTL_sync_en_shift                                          (2)
#define  TP_TP_TF2_P_CNTL_rst_en_shift                                           (1)
#define  TP_TP_TF2_P_CNTL_write_data_shift                                       (0)
#define  TP_TP_TF2_P_CNTL_two_bit_mask                                           (0x80000000)
#define  TP_TP_TF2_P_CNTL_two_bit_reverse_mask                                   (0x40000000)
#define  TP_TP_TF2_P_CNTL_two_bit_sel_h_mask                                     (0x20000000)
#define  TP_TP_TF2_P_CNTL_two_bit_sel_l_mask                                     (0x10000000)
#define  TP_TP_TF2_P_CNTL_src_sel_h_mask                                         (0x02000000)
#define  TP_TP_TF2_P_CNTL_src_sel_l_mask                                         (0x01000000)
#define  TP_TP_TF2_P_CNTL_dir_dma_mask                                           (0x00800000)
#define  TP_TP_TF2_P_CNTL_ci_mode_mask                                           (0x00040000)
#define  TP_TP_TF2_P_CNTL_tp_err_fix_en_mask                                     (0x00020000)
#define  TP_TP_TF2_P_CNTL_strm_id_en_mask                                        (0x00010000)
#define  TP_TP_TF2_P_CNTL_buf_rdy_ctl_mask                                       (0x00008000)
#define  TP_TP_TF2_P_CNTL_psc_en_mask                                            (0x00004000)
#define  TP_TP_TF2_P_CNTL_pes_en_mask                                            (0x00002000)
#define  TP_TP_TF2_P_CNTL_tsc_en_mask                                            (0x00001000)
#define  TP_TP_TF2_P_CNTL_tb_mask                                                (0x00000800)
#define  TP_TP_TF2_P_CNTL_busy_mask                                              (0x00000400)
#define  TP_TP_TF2_P_CNTL_mode_mask                                              (0x00000200)
#define  TP_TP_TF2_P_CNTL_du_en_mask                                             (0x00000100)
#define  TP_TP_TF2_P_CNTL_de_en_mask                                             (0x00000080)
#define  TP_TP_TF2_P_CNTL_xt_en_mask                                             (0x00000040)
#define  TP_TP_TF2_P_CNTL_pid_en_mask                                            (0x00000020)
#define  TP_TP_TF2_P_CNTL_null_en_mask                                           (0x00000010)
#define  TP_TP_TF2_P_CNTL_trerr_en_mask                                          (0x00000008)
#define  TP_TP_TF2_P_CNTL_sync_en_mask                                           (0x00000004)
#define  TP_TP_TF2_P_CNTL_rst_en_mask                                            (0x00000002)
#define  TP_TP_TF2_P_CNTL_write_data_mask                                        (0x00000001)
#define  TP_TP_TF2_P_CNTL_two_bit(data)                                          (0x80000000&((data)<<31))
#define  TP_TP_TF2_P_CNTL_two_bit_reverse(data)                                  (0x40000000&((data)<<30))
#define  TP_TP_TF2_P_CNTL_two_bit_sel_h(data)                                    (0x20000000&((data)<<29))
#define  TP_TP_TF2_P_CNTL_two_bit_sel_l(data)                                    (0x10000000&((data)<<28))
#define  TP_TP_TF2_P_CNTL_src_sel_h(data)                                        (0x02000000&((data)<<25))
#define  TP_TP_TF2_P_CNTL_src_sel_l(data)                                        (0x01000000&((data)<<24))
#define  TP_TP_TF2_P_CNTL_dir_dma(data)                                          (0x00800000&((data)<<23))
#define  TP_TP_TF2_P_CNTL_ci_mode(data)                                          (0x00040000&((data)<<18))
#define  TP_TP_TF2_P_CNTL_tp_err_fix_en(data)                                    (0x00020000&((data)<<17))
#define  TP_TP_TF2_P_CNTL_strm_id_en(data)                                       (0x00010000&((data)<<16))
#define  TP_TP_TF2_P_CNTL_buf_rdy_ctl(data)                                      (0x00008000&((data)<<15))
#define  TP_TP_TF2_P_CNTL_psc_en(data)                                           (0x00004000&((data)<<14))
#define  TP_TP_TF2_P_CNTL_pes_en(data)                                           (0x00002000&((data)<<13))
#define  TP_TP_TF2_P_CNTL_tsc_en(data)                                           (0x00001000&((data)<<12))
#define  TP_TP_TF2_P_CNTL_tb(data)                                               (0x00000800&((data)<<11))
#define  TP_TP_TF2_P_CNTL_busy(data)                                             (0x00000400&((data)<<10))
#define  TP_TP_TF2_P_CNTL_mode(data)                                             (0x00000200&((data)<<9))
#define  TP_TP_TF2_P_CNTL_du_en(data)                                            (0x00000100&((data)<<8))
#define  TP_TP_TF2_P_CNTL_de_en(data)                                            (0x00000080&((data)<<7))
#define  TP_TP_TF2_P_CNTL_xt_en(data)                                            (0x00000040&((data)<<6))
#define  TP_TP_TF2_P_CNTL_pid_en(data)                                           (0x00000020&((data)<<5))
#define  TP_TP_TF2_P_CNTL_null_en(data)                                          (0x00000010&((data)<<4))
#define  TP_TP_TF2_P_CNTL_trerr_en(data)                                         (0x00000008&((data)<<3))
#define  TP_TP_TF2_P_CNTL_sync_en(data)                                          (0x00000004&((data)<<2))
#define  TP_TP_TF2_P_CNTL_rst_en(data)                                           (0x00000002&((data)<<1))
#define  TP_TP_TF2_P_CNTL_write_data(data)                                       (0x00000001&(data))
#define  TP_TP_TF2_P_CNTL_get_two_bit(data)                                      ((0x80000000&(data))>>31)
#define  TP_TP_TF2_P_CNTL_get_two_bit_reverse(data)                              ((0x40000000&(data))>>30)
#define  TP_TP_TF2_P_CNTL_get_two_bit_sel_h(data)                                ((0x20000000&(data))>>29)
#define  TP_TP_TF2_P_CNTL_get_two_bit_sel_l(data)                                ((0x10000000&(data))>>28)
#define  TP_TP_TF2_P_CNTL_get_src_sel_h(data)                                    ((0x02000000&(data))>>25)
#define  TP_TP_TF2_P_CNTL_get_src_sel_l(data)                                    ((0x01000000&(data))>>24)
#define  TP_TP_TF2_P_CNTL_get_dir_dma(data)                                      ((0x00800000&(data))>>23)
#define  TP_TP_TF2_P_CNTL_get_ci_mode(data)                                      ((0x00040000&(data))>>18)
#define  TP_TP_TF2_P_CNTL_get_tp_err_fix_en(data)                                ((0x00020000&(data))>>17)
#define  TP_TP_TF2_P_CNTL_get_strm_id_en(data)                                   ((0x00010000&(data))>>16)
#define  TP_TP_TF2_P_CNTL_get_buf_rdy_ctl(data)                                  ((0x00008000&(data))>>15)
#define  TP_TP_TF2_P_CNTL_get_psc_en(data)                                       ((0x00004000&(data))>>14)
#define  TP_TP_TF2_P_CNTL_get_pes_en(data)                                       ((0x00002000&(data))>>13)
#define  TP_TP_TF2_P_CNTL_get_tsc_en(data)                                       ((0x00001000&(data))>>12)
#define  TP_TP_TF2_P_CNTL_get_tb(data)                                           ((0x00000800&(data))>>11)
#define  TP_TP_TF2_P_CNTL_get_busy(data)                                         ((0x00000400&(data))>>10)
#define  TP_TP_TF2_P_CNTL_get_mode(data)                                         ((0x00000200&(data))>>9)
#define  TP_TP_TF2_P_CNTL_get_du_en(data)                                        ((0x00000100&(data))>>8)
#define  TP_TP_TF2_P_CNTL_get_de_en(data)                                        ((0x00000080&(data))>>7)
#define  TP_TP_TF2_P_CNTL_get_xt_en(data)                                        ((0x00000040&(data))>>6)
#define  TP_TP_TF2_P_CNTL_get_pid_en(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP_TF2_P_CNTL_get_null_en(data)                                      ((0x00000010&(data))>>4)
#define  TP_TP_TF2_P_CNTL_get_trerr_en(data)                                     ((0x00000008&(data))>>3)
#define  TP_TP_TF2_P_CNTL_get_sync_en(data)                                      ((0x00000004&(data))>>2)
#define  TP_TP_TF2_P_CNTL_get_rst_en(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP_TF2_P_CNTL_get_write_data(data)                                   (0x00000001&(data))

#define  TP_TP_TF2_P_CNT                                                         0x18014578
#define  TP_TP_TF2_P_CNT_reg_addr                                                "0xB8014578"
#define  TP_TP_TF2_P_CNT_reg                                                     0xB8014578
#define  TP_TP_TF2_P_CNT_inst_addr                                               "0x00AA"
#define  set_TP_TP_TF2_P_CNT_reg(data)                                           (*((volatile unsigned int*)TP_TP_TF2_P_CNT_reg)=data)
#define  get_TP_TP_TF2_P_CNT_reg                                                 (*((volatile unsigned int*)TP_TP_TF2_P_CNT_reg))
#define  TP_TP_TF2_P_CNT_cnt_shift                                               (0)
#define  TP_TP_TF2_P_CNT_cnt_mask                                                (0x00FFFFFF)
#define  TP_TP_TF2_P_CNT_cnt(data)                                               (0x00FFFFFF&(data))
#define  TP_TP_TF2_P_CNT_get_cnt(data)                                           (0x00FFFFFF&(data))

#define  TP_TP_TF2_P_DRP_CNT                                                     0x1801457C
#define  TP_TP_TF2_P_DRP_CNT_reg_addr                                            "0xB801457C"
#define  TP_TP_TF2_P_DRP_CNT_reg                                                 0xB801457C
#define  TP_TP_TF2_P_DRP_CNT_inst_addr                                           "0x00AB"
#define  set_TP_TP_TF2_P_DRP_CNT_reg(data)                                       (*((volatile unsigned int*)TP_TP_TF2_P_DRP_CNT_reg)=data)
#define  get_TP_TP_TF2_P_DRP_CNT_reg                                             (*((volatile unsigned int*)TP_TP_TF2_P_DRP_CNT_reg))
#define  TP_TP_TF2_P_DRP_CNT_drp_cnt_shift                                       (0)
#define  TP_TP_TF2_P_DRP_CNT_drp_cnt_mask                                        (0x0000FFFF)
#define  TP_TP_TF2_P_DRP_CNT_drp_cnt(data)                                       (0x0000FFFF&(data))
#define  TP_TP_TF2_P_DRP_CNT_get_drp_cnt(data)                                   (0x0000FFFF&(data))

#define  TP_TP_TF2_P_FRMCFG                                                      0x18014584
#define  TP_TP_TF2_P_FRMCFG_reg_addr                                             "0xB8014584"
#define  TP_TP_TF2_P_FRMCFG_reg                                                  0xB8014584
#define  TP_TP_TF2_P_FRMCFG_inst_addr                                            "0x00AC"
#define  set_TP_TP_TF2_P_FRMCFG_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF2_P_FRMCFG_reg)=data)
#define  get_TP_TP_TF2_P_FRMCFG_reg                                              (*((volatile unsigned int*)TP_TP_TF2_P_FRMCFG_reg))
#define  TP_TP_TF2_P_FRMCFG_sync_byte_shift                                      (24)
#define  TP_TP_TF2_P_FRMCFG_dropno_shift                                         (20)
#define  TP_TP_TF2_P_FRMCFG_lockno_shift                                         (16)
#define  TP_TP_TF2_P_FRMCFG_packet_size_shift                                    (14)
#define  TP_TP_TF2_P_FRMCFG_data_order_shift                                     (13)
#define  TP_TP_TF2_P_FRMCFG_frm_en_shift                                         (12)
#define  TP_TP_TF2_P_FRMCFG_forcedrop_shift                                      (11)
#define  TP_TP_TF2_P_FRMCFG_syncmode_shift                                       (6)
#define  TP_TP_TF2_P_FRMCFG_serial_shift                                         (5)
#define  TP_TP_TF2_P_FRMCFG_datapin_shift                                        (4)
#define  TP_TP_TF2_P_FRMCFG_sync_byte_mask                                       (0xFF000000)
#define  TP_TP_TF2_P_FRMCFG_dropno_mask                                          (0x00F00000)
#define  TP_TP_TF2_P_FRMCFG_lockno_mask                                          (0x000F0000)
#define  TP_TP_TF2_P_FRMCFG_packet_size_mask                                     (0x0000C000)
#define  TP_TP_TF2_P_FRMCFG_data_order_mask                                      (0x00002000)
#define  TP_TP_TF2_P_FRMCFG_frm_en_mask                                          (0x00001000)
#define  TP_TP_TF2_P_FRMCFG_forcedrop_mask                                       (0x00000800)
#define  TP_TP_TF2_P_FRMCFG_syncmode_mask                                        (0x000007C0)
#define  TP_TP_TF2_P_FRMCFG_serial_mask                                          (0x00000020)
#define  TP_TP_TF2_P_FRMCFG_datapin_mask                                         (0x00000010)
#define  TP_TP_TF2_P_FRMCFG_sync_byte(data)                                      (0xFF000000&((data)<<24))
#define  TP_TP_TF2_P_FRMCFG_dropno(data)                                         (0x00F00000&((data)<<20))
#define  TP_TP_TF2_P_FRMCFG_lockno(data)                                         (0x000F0000&((data)<<16))
#define  TP_TP_TF2_P_FRMCFG_packet_size(data)                                    (0x0000C000&((data)<<14))
#define  TP_TP_TF2_P_FRMCFG_data_order(data)                                     (0x00002000&((data)<<13))
#define  TP_TP_TF2_P_FRMCFG_frm_en(data)                                         (0x00001000&((data)<<12))
#define  TP_TP_TF2_P_FRMCFG_forcedrop(data)                                      (0x00000800&((data)<<11))
#define  TP_TP_TF2_P_FRMCFG_syncmode(data)                                       (0x000007C0&((data)<<6))
#define  TP_TP_TF2_P_FRMCFG_serial(data)                                         (0x00000020&((data)<<5))
#define  TP_TP_TF2_P_FRMCFG_datapin(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_TF2_P_FRMCFG_get_sync_byte(data)                                  ((0xFF000000&(data))>>24)
#define  TP_TP_TF2_P_FRMCFG_get_dropno(data)                                     ((0x00F00000&(data))>>20)
#define  TP_TP_TF2_P_FRMCFG_get_lockno(data)                                     ((0x000F0000&(data))>>16)
#define  TP_TP_TF2_P_FRMCFG_get_packet_size(data)                                ((0x0000C000&(data))>>14)
#define  TP_TP_TF2_P_FRMCFG_get_data_order(data)                                 ((0x00002000&(data))>>13)
#define  TP_TP_TF2_P_FRMCFG_get_frm_en(data)                                     ((0x00001000&(data))>>12)
#define  TP_TP_TF2_P_FRMCFG_get_forcedrop(data)                                  ((0x00000800&(data))>>11)
#define  TP_TP_TF2_P_FRMCFG_get_syncmode(data)                                   ((0x000007C0&(data))>>6)
#define  TP_TP_TF2_P_FRMCFG_get_serial(data)                                     ((0x00000020&(data))>>5)
#define  TP_TP_TF2_P_FRMCFG_get_datapin(data)                                    ((0x00000010&(data))>>4)

#define  TP_TP_TF2_P_INT                                                         0x18014588
#define  TP_TP_TF2_P_INT_reg_addr                                                "0xB8014588"
#define  TP_TP_TF2_P_INT_reg                                                     0xB8014588
#define  TP_TP_TF2_P_INT_inst_addr                                               "0x00AD"
#define  set_TP_TP_TF2_P_INT_reg(data)                                           (*((volatile unsigned int*)TP_TP_TF2_P_INT_reg)=data)
#define  get_TP_TP_TF2_P_INT_reg                                                 (*((volatile unsigned int*)TP_TP_TF2_P_INT_reg))
#define  TP_TP_TF2_P_INT_adf_pcr_in_shift                                        (4)
#define  TP_TP_TF2_P_INT_overflow_shift                                          (3)
#define  TP_TP_TF2_P_INT_drop_shift                                              (2)
#define  TP_TP_TF2_P_INT_sync_shift                                              (1)
#define  TP_TP_TF2_P_INT_write_data_shift                                        (0)
#define  TP_TP_TF2_P_INT_adf_pcr_in_mask                                         (0x00000010)
#define  TP_TP_TF2_P_INT_overflow_mask                                           (0x00000008)
#define  TP_TP_TF2_P_INT_drop_mask                                               (0x00000004)
#define  TP_TP_TF2_P_INT_sync_mask                                               (0x00000002)
#define  TP_TP_TF2_P_INT_write_data_mask                                         (0x00000001)
#define  TP_TP_TF2_P_INT_adf_pcr_in(data)                                        (0x00000010&((data)<<4))
#define  TP_TP_TF2_P_INT_overflow(data)                                          (0x00000008&((data)<<3))
#define  TP_TP_TF2_P_INT_drop(data)                                              (0x00000004&((data)<<2))
#define  TP_TP_TF2_P_INT_sync(data)                                              (0x00000002&((data)<<1))
#define  TP_TP_TF2_P_INT_write_data(data)                                        (0x00000001&(data))
#define  TP_TP_TF2_P_INT_get_adf_pcr_in(data)                                    ((0x00000010&(data))>>4)
#define  TP_TP_TF2_P_INT_get_overflow(data)                                      ((0x00000008&(data))>>3)
#define  TP_TP_TF2_P_INT_get_drop(data)                                          ((0x00000004&(data))>>2)
#define  TP_TP_TF2_P_INT_get_sync(data)                                          ((0x00000002&(data))>>1)
#define  TP_TP_TF2_P_INT_get_write_data(data)                                    (0x00000001&(data))

#define  TP_TP_TF2_P_INT_EN                                                      0x1801458C
#define  TP_TP_TF2_P_INT_EN_reg_addr                                             "0xB801458C"
#define  TP_TP_TF2_P_INT_EN_reg                                                  0xB801458C
#define  TP_TP_TF2_P_INT_EN_inst_addr                                            "0x00AE"
#define  set_TP_TP_TF2_P_INT_EN_reg(data)                                        (*((volatile unsigned int*)TP_TP_TF2_P_INT_EN_reg)=data)
#define  get_TP_TP_TF2_P_INT_EN_reg                                              (*((volatile unsigned int*)TP_TP_TF2_P_INT_EN_reg))
#define  TP_TP_TF2_P_INT_EN_adf_pcr_in_en_shift                                  (4)
#define  TP_TP_TF2_P_INT_EN_overflow_en_shift                                    (3)
#define  TP_TP_TF2_P_INT_EN_drop_en_shift                                        (2)
#define  TP_TP_TF2_P_INT_EN_sync_en_shift                                        (1)
#define  TP_TP_TF2_P_INT_EN_write_data_shift                                     (0)
#define  TP_TP_TF2_P_INT_EN_adf_pcr_in_en_mask                                   (0x00000010)
#define  TP_TP_TF2_P_INT_EN_overflow_en_mask                                     (0x00000008)
#define  TP_TP_TF2_P_INT_EN_drop_en_mask                                         (0x00000004)
#define  TP_TP_TF2_P_INT_EN_sync_en_mask                                         (0x00000002)
#define  TP_TP_TF2_P_INT_EN_write_data_mask                                      (0x00000001)
#define  TP_TP_TF2_P_INT_EN_adf_pcr_in_en(data)                                  (0x00000010&((data)<<4))
#define  TP_TP_TF2_P_INT_EN_overflow_en(data)                                    (0x00000008&((data)<<3))
#define  TP_TP_TF2_P_INT_EN_drop_en(data)                                        (0x00000004&((data)<<2))
#define  TP_TP_TF2_P_INT_EN_sync_en(data)                                        (0x00000002&((data)<<1))
#define  TP_TP_TF2_P_INT_EN_write_data(data)                                     (0x00000001&(data))
#define  TP_TP_TF2_P_INT_EN_get_adf_pcr_in_en(data)                              ((0x00000010&(data))>>4)
#define  TP_TP_TF2_P_INT_EN_get_overflow_en(data)                                ((0x00000008&(data))>>3)
#define  TP_TP_TF2_P_INT_EN_get_drop_en(data)                                    ((0x00000004&(data))>>2)
#define  TP_TP_TF2_P_INT_EN_get_sync_en(data)                                    ((0x00000002&(data))>>1)
#define  TP_TP_TF2_P_INT_EN_get_write_data(data)                                 (0x00000001&(data))

#define  TP_TP_P_THRESHOLD                                                       0x18014590
#define  TP_TP_P_THRESHOLD_reg_addr                                              "0xB8014590"
#define  TP_TP_P_THRESHOLD_reg                                                   0xB8014590
#define  TP_TP_P_THRESHOLD_inst_addr                                             "0x00AF"
#define  set_TP_TP_P_THRESHOLD_reg(data)                                         (*((volatile unsigned int*)TP_TP_P_THRESHOLD_reg)=data)
#define  get_TP_TP_P_THRESHOLD_reg                                               (*((volatile unsigned int*)TP_TP_P_THRESHOLD_reg))
#define  TP_TP_P_THRESHOLD_threshold_shift                                       (0)
#define  TP_TP_P_THRESHOLD_threshold_mask                                        (0x1FFFFFFF)
#define  TP_TP_P_THRESHOLD_threshold(data)                                       (0x1FFFFFFF&(data))
#define  TP_TP_P_THRESHOLD_get_threshold(data)                                   (0x1FFFFFFF&(data))

#define  TP_TP_P_FULLNESS                                                        0x18014594
#define  TP_TP_P_FULLNESS_reg_addr                                               "0xB8014594"
#define  TP_TP_P_FULLNESS_reg                                                    0xB8014594
#define  TP_TP_P_FULLNESS_inst_addr                                              "0x00B0"
#define  set_TP_TP_P_FULLNESS_reg(data)                                          (*((volatile unsigned int*)TP_TP_P_FULLNESS_reg)=data)
#define  get_TP_TP_P_FULLNESS_reg                                                (*((volatile unsigned int*)TP_TP_P_FULLNESS_reg))
#define  TP_TP_P_FULLNESS_fullness_shift                                         (0)
#define  TP_TP_P_FULLNESS_fullness_mask                                          (0x1FFFFFFF)
#define  TP_TP_P_FULLNESS_fullness(data)                                         (0x1FFFFFFF&(data))
#define  TP_TP_P_FULLNESS_get_fullness(data)                                     (0x1FFFFFFF&(data))

#define  TP_TP_P_RING_CTRL                                                       0x18014598
#define  TP_TP_P_RING_CTRL_reg_addr                                              "0xB8014598"
#define  TP_TP_P_RING_CTRL_reg                                                   0xB8014598
#define  TP_TP_P_RING_CTRL_inst_addr                                             "0x00B1"
#define  set_TP_TP_P_RING_CTRL_reg(data)                                         (*((volatile unsigned int*)TP_TP_P_RING_CTRL_reg)=data)
#define  get_TP_TP_P_RING_CTRL_reg                                               (*((volatile unsigned int*)TP_TP_P_RING_CTRL_reg))
#define  TP_TP_P_RING_CTRL_wm_shift                                              (7)
#define  TP_TP_P_RING_CTRL_r_w_shift                                             (6)
#define  TP_TP_P_RING_CTRL_idx_shift                                             (0)
#define  TP_TP_P_RING_CTRL_wm_mask                                               (0x00000780)
#define  TP_TP_P_RING_CTRL_r_w_mask                                              (0x00000040)
#define  TP_TP_P_RING_CTRL_idx_mask                                              (0x00000003)
#define  TP_TP_P_RING_CTRL_wm(data)                                              (0x00000780&((data)<<7))
#define  TP_TP_P_RING_CTRL_r_w(data)                                             (0x00000040&((data)<<6))
#define  TP_TP_P_RING_CTRL_idx(data)                                             (0x00000003&(data))
#define  TP_TP_P_RING_CTRL_get_wm(data)                                          ((0x00000780&(data))>>7)
#define  TP_TP_P_RING_CTRL_get_r_w(data)                                         ((0x00000040&(data))>>6)
#define  TP_TP_P_RING_CTRL_get_idx(data)                                         (0x00000003&(data))

#define  TP_TP_P_RING_LIMIT                                                      0x1801459C
#define  TP_TP_P_RING_LIMIT_reg_addr                                             "0xB801459C"
#define  TP_TP_P_RING_LIMIT_reg                                                  0xB801459C
#define  TP_TP_P_RING_LIMIT_inst_addr                                            "0x00B2"
#define  set_TP_TP_P_RING_LIMIT_reg(data)                                        (*((volatile unsigned int*)TP_TP_P_RING_LIMIT_reg)=data)
#define  get_TP_TP_P_RING_LIMIT_reg                                              (*((volatile unsigned int*)TP_TP_P_RING_LIMIT_reg))
#define  TP_TP_P_RING_LIMIT_ring_limit_shift                                     (3)
#define  TP_TP_P_RING_LIMIT_ring_limit_mask                                      (0xFFFFFFF8)
#define  TP_TP_P_RING_LIMIT_ring_limit(data)                                     (0xFFFFFFF8&((data)<<3))
#define  TP_TP_P_RING_LIMIT_get_ring_limit(data)                                 ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_P_RING_BASE                                                       0x180145A0
#define  TP_TP_P_RING_BASE_reg_addr                                              "0xB80145A0"
#define  TP_TP_P_RING_BASE_reg                                                   0xB80145A0
#define  TP_TP_P_RING_BASE_inst_addr                                             "0x00B3"
#define  set_TP_TP_P_RING_BASE_reg(data)                                         (*((volatile unsigned int*)TP_TP_P_RING_BASE_reg)=data)
#define  get_TP_TP_P_RING_BASE_reg                                               (*((volatile unsigned int*)TP_TP_P_RING_BASE_reg))
#define  TP_TP_P_RING_BASE_ring_base_shift                                       (3)
#define  TP_TP_P_RING_BASE_ring_base_mask                                        (0xFFFFFFF8)
#define  TP_TP_P_RING_BASE_ring_base(data)                                       (0xFFFFFFF8&((data)<<3))
#define  TP_TP_P_RING_BASE_get_ring_base(data)                                   ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_P_RING_RP                                                         0x180145A4
#define  TP_TP_P_RING_RP_reg_addr                                                "0xB80145A4"
#define  TP_TP_P_RING_RP_reg                                                     0xB80145A4
#define  TP_TP_P_RING_RP_inst_addr                                               "0x00B4"
#define  set_TP_TP_P_RING_RP_reg(data)                                           (*((volatile unsigned int*)TP_TP_P_RING_RP_reg)=data)
#define  get_TP_TP_P_RING_RP_reg                                                 (*((volatile unsigned int*)TP_TP_P_RING_RP_reg))
#define  TP_TP_P_RING_RP_ring_rp_shift                                           (0)
#define  TP_TP_P_RING_RP_ring_rp_mask                                            (0xFFFFFFFF)
#define  TP_TP_P_RING_RP_ring_rp(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_P_RING_RP_get_ring_rp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_P_RING_WP                                                         0x180145A8
#define  TP_TP_P_RING_WP_reg_addr                                                "0xB80145A8"
#define  TP_TP_P_RING_WP_reg                                                     0xB80145A8
#define  TP_TP_P_RING_WP_inst_addr                                               "0x00B5"
#define  set_TP_TP_P_RING_WP_reg(data)                                           (*((volatile unsigned int*)TP_TP_P_RING_WP_reg)=data)
#define  get_TP_TP_P_RING_WP_reg                                                 (*((volatile unsigned int*)TP_TP_P_RING_WP_reg))
#define  TP_TP_P_RING_WP_ring_wp_shift                                           (0)
#define  TP_TP_P_RING_WP_ring_wp_mask                                            (0xFFFFFFFF)
#define  TP_TP_P_RING_WP_ring_wp(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_P_RING_WP_get_ring_wp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_P_RING_AVAIL_INT                                                  0x180145AC
#define  TP_TP_P_RING_AVAIL_INT_reg_addr                                         "0xB80145AC"
#define  TP_TP_P_RING_AVAIL_INT_reg                                              0xB80145AC
#define  TP_TP_P_RING_AVAIL_INT_inst_addr                                        "0x00B6"
#define  set_TP_TP_P_RING_AVAIL_INT_reg(data)                                    (*((volatile unsigned int*)TP_TP_P_RING_AVAIL_INT_reg)=data)
#define  get_TP_TP_P_RING_AVAIL_INT_reg                                          (*((volatile unsigned int*)TP_TP_P_RING_AVAIL_INT_reg))
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_2_shift                               (3)
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_1_shift                               (2)
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_0_shift                               (1)
#define  TP_TP_P_RING_AVAIL_INT_write_data_shift                                 (0)
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_2_mask                                (0x00000008)
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_1_mask                                (0x00000004)
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_0_mask                                (0x00000002)
#define  TP_TP_P_RING_AVAIL_INT_write_data_mask                                  (0x00000001)
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_2(data)                               (0x00000008&((data)<<3))
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_1(data)                               (0x00000004&((data)<<2))
#define  TP_TP_P_RING_AVAIL_INT_ring_avail_0(data)                               (0x00000002&((data)<<1))
#define  TP_TP_P_RING_AVAIL_INT_write_data(data)                                 (0x00000001&(data))
#define  TP_TP_P_RING_AVAIL_INT_get_ring_avail_2(data)                           ((0x00000008&(data))>>3)
#define  TP_TP_P_RING_AVAIL_INT_get_ring_avail_1(data)                           ((0x00000004&(data))>>2)
#define  TP_TP_P_RING_AVAIL_INT_get_ring_avail_0(data)                           ((0x00000002&(data))>>1)
#define  TP_TP_P_RING_AVAIL_INT_get_write_data(data)                             (0x00000001&(data))

#define  TP_TP_P_RING_FULL_INT                                                   0x180145B0
#define  TP_TP_P_RING_FULL_INT_reg_addr                                          "0xB80145B0"
#define  TP_TP_P_RING_FULL_INT_reg                                               0xB80145B0
#define  TP_TP_P_RING_FULL_INT_inst_addr                                         "0x00B7"
#define  set_TP_TP_P_RING_FULL_INT_reg(data)                                     (*((volatile unsigned int*)TP_TP_P_RING_FULL_INT_reg)=data)
#define  get_TP_TP_P_RING_FULL_INT_reg                                           (*((volatile unsigned int*)TP_TP_P_RING_FULL_INT_reg))
#define  TP_TP_P_RING_FULL_INT_ring_full_2_shift                                 (3)
#define  TP_TP_P_RING_FULL_INT_ring_full_1_shift                                 (2)
#define  TP_TP_P_RING_FULL_INT_ring_full_0_shift                                 (1)
#define  TP_TP_P_RING_FULL_INT_write_data_shift                                  (0)
#define  TP_TP_P_RING_FULL_INT_ring_full_2_mask                                  (0x00000008)
#define  TP_TP_P_RING_FULL_INT_ring_full_1_mask                                  (0x00000004)
#define  TP_TP_P_RING_FULL_INT_ring_full_0_mask                                  (0x00000002)
#define  TP_TP_P_RING_FULL_INT_write_data_mask                                   (0x00000001)
#define  TP_TP_P_RING_FULL_INT_ring_full_2(data)                                 (0x00000008&((data)<<3))
#define  TP_TP_P_RING_FULL_INT_ring_full_1(data)                                 (0x00000004&((data)<<2))
#define  TP_TP_P_RING_FULL_INT_ring_full_0(data)                                 (0x00000002&((data)<<1))
#define  TP_TP_P_RING_FULL_INT_write_data(data)                                  (0x00000001&(data))
#define  TP_TP_P_RING_FULL_INT_get_ring_full_2(data)                             ((0x00000008&(data))>>3)
#define  TP_TP_P_RING_FULL_INT_get_ring_full_1(data)                             ((0x00000004&(data))>>2)
#define  TP_TP_P_RING_FULL_INT_get_ring_full_0(data)                             ((0x00000002&(data))>>1)
#define  TP_TP_P_RING_FULL_INT_get_write_data(data)                              (0x00000001&(data))

#define  TP_TP_P_RING_AVAIL_INT_EN                                               0x180145B4
#define  TP_TP_P_RING_AVAIL_INT_EN_reg_addr                                      "0xB80145B4"
#define  TP_TP_P_RING_AVAIL_INT_EN_reg                                           0xB80145B4
#define  TP_TP_P_RING_AVAIL_INT_EN_inst_addr                                     "0x00B8"
#define  set_TP_TP_P_RING_AVAIL_INT_EN_reg(data)                                 (*((volatile unsigned int*)TP_TP_P_RING_AVAIL_INT_EN_reg)=data)
#define  get_TP_TP_P_RING_AVAIL_INT_EN_reg                                       (*((volatile unsigned int*)TP_TP_P_RING_AVAIL_INT_EN_reg))
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_2_en_shift                         (3)
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_1_en_shift                         (2)
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_0_en_shift                         (1)
#define  TP_TP_P_RING_AVAIL_INT_EN_write_data_shift                              (0)
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_2_en_mask                          (0x00000008)
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_1_en_mask                          (0x00000004)
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_0_en_mask                          (0x00000002)
#define  TP_TP_P_RING_AVAIL_INT_EN_write_data_mask                               (0x00000001)
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_2_en(data)                         (0x00000008&((data)<<3))
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_1_en(data)                         (0x00000004&((data)<<2))
#define  TP_TP_P_RING_AVAIL_INT_EN_ring_avail_0_en(data)                         (0x00000002&((data)<<1))
#define  TP_TP_P_RING_AVAIL_INT_EN_write_data(data)                              (0x00000001&(data))
#define  TP_TP_P_RING_AVAIL_INT_EN_get_ring_avail_2_en(data)                     ((0x00000008&(data))>>3)
#define  TP_TP_P_RING_AVAIL_INT_EN_get_ring_avail_1_en(data)                     ((0x00000004&(data))>>2)
#define  TP_TP_P_RING_AVAIL_INT_EN_get_ring_avail_0_en(data)                     ((0x00000002&(data))>>1)
#define  TP_TP_P_RING_AVAIL_INT_EN_get_write_data(data)                          (0x00000001&(data))

#define  TP_TP_P_RING_FULL_INT_EN                                                0x180145B8
#define  TP_TP_P_RING_FULL_INT_EN_reg_addr                                       "0xB80145B8"
#define  TP_TP_P_RING_FULL_INT_EN_reg                                            0xB80145B8
#define  TP_TP_P_RING_FULL_INT_EN_inst_addr                                      "0x00B9"
#define  set_TP_TP_P_RING_FULL_INT_EN_reg(data)                                  (*((volatile unsigned int*)TP_TP_P_RING_FULL_INT_EN_reg)=data)
#define  get_TP_TP_P_RING_FULL_INT_EN_reg                                        (*((volatile unsigned int*)TP_TP_P_RING_FULL_INT_EN_reg))
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_2_en_shift                           (3)
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_1_en_shift                           (2)
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_0_en_shift                           (1)
#define  TP_TP_P_RING_FULL_INT_EN_write_data_shift                               (0)
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_2_en_mask                            (0x00000008)
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_1_en_mask                            (0x00000004)
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_0_en_mask                            (0x00000002)
#define  TP_TP_P_RING_FULL_INT_EN_write_data_mask                                (0x00000001)
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_2_en(data)                           (0x00000008&((data)<<3))
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_1_en(data)                           (0x00000004&((data)<<2))
#define  TP_TP_P_RING_FULL_INT_EN_ring_full_0_en(data)                           (0x00000002&((data)<<1))
#define  TP_TP_P_RING_FULL_INT_EN_write_data(data)                               (0x00000001&(data))
#define  TP_TP_P_RING_FULL_INT_EN_get_ring_full_2_en(data)                       ((0x00000008&(data))>>3)
#define  TP_TP_P_RING_FULL_INT_EN_get_ring_full_1_en(data)                       ((0x00000004&(data))>>2)
#define  TP_TP_P_RING_FULL_INT_EN_get_ring_full_0_en(data)                       ((0x00000002&(data))>>1)
#define  TP_TP_P_RING_FULL_INT_EN_get_write_data(data)                           (0x00000001&(data))

#define  TP_TP_P_SYNC_RPLACE                                                     0x180146B8
#define  TP_TP_P_SYNC_RPLACE_reg_addr                                            "0xB80146B8"
#define  TP_TP_P_SYNC_RPLACE_reg                                                 0xB80146B8
#define  TP_TP_P_SYNC_RPLACE_inst_addr                                           "0x00BA"
#define  set_TP_TP_P_SYNC_RPLACE_reg(data)                                       (*((volatile unsigned int*)TP_TP_P_SYNC_RPLACE_reg)=data)
#define  get_TP_TP_P_SYNC_RPLACE_reg                                             (*((volatile unsigned int*)TP_TP_P_SYNC_RPLACE_reg))
#define  TP_TP_P_SYNC_RPLACE_tp2_shift                                           (16)
#define  TP_TP_P_SYNC_RPLACE_tp1_shift                                           (8)
#define  TP_TP_P_SYNC_RPLACE_tp0_shift                                           (0)
#define  TP_TP_P_SYNC_RPLACE_tp2_mask                                            (0x00FF0000)
#define  TP_TP_P_SYNC_RPLACE_tp1_mask                                            (0x0000FF00)
#define  TP_TP_P_SYNC_RPLACE_tp0_mask                                            (0x000000FF)
#define  TP_TP_P_SYNC_RPLACE_tp2(data)                                           (0x00FF0000&((data)<<16))
#define  TP_TP_P_SYNC_RPLACE_tp1(data)                                           (0x0000FF00&((data)<<8))
#define  TP_TP_P_SYNC_RPLACE_tp0(data)                                           (0x000000FF&(data))
#define  TP_TP_P_SYNC_RPLACE_get_tp2(data)                                       ((0x00FF0000&(data))>>16)
#define  TP_TP_P_SYNC_RPLACE_get_tp1(data)                                       ((0x0000FF00&(data))>>8)
#define  TP_TP_P_SYNC_RPLACE_get_tp0(data)                                       (0x000000FF&(data))

#define  TP_PREFIX_CTRL                                                          0x18014720
#define  TP_PREFIX_CTRL_reg_addr                                                 "0xB8014720"
#define  TP_PREFIX_CTRL_reg                                                      0xB8014720
#define  TP_PREFIX_CTRL_inst_addr                                                "0x00BB"
#define  set_TP_PREFIX_CTRL_reg(data)                                            (*((volatile unsigned int*)TP_PREFIX_CTRL_reg)=data)
#define  get_TP_PREFIX_CTRL_reg                                                  (*((volatile unsigned int*)TP_PREFIX_CTRL_reg))
#define  TP_PREFIX_CTRL_tp3_keep_shift                                           (11)
#define  TP_PREFIX_CTRL_tp0_keep_shift                                           (10)
#define  TP_PREFIX_CTRL_tp1_keep_shift                                           (9)
#define  TP_PREFIX_CTRL_tp2_keep_shift                                           (8)
#define  TP_PREFIX_CTRL_tp3_sel_shift                                            (6)
#define  TP_PREFIX_CTRL_tp0_sel_shift                                            (4)
#define  TP_PREFIX_CTRL_tp1_sel_shift                                            (2)
#define  TP_PREFIX_CTRL_tp2_sel_shift                                            (0)
#define  TP_PREFIX_CTRL_tp3_keep_mask                                            (0x00000800)
#define  TP_PREFIX_CTRL_tp0_keep_mask                                            (0x00000400)
#define  TP_PREFIX_CTRL_tp1_keep_mask                                            (0x00000200)
#define  TP_PREFIX_CTRL_tp2_keep_mask                                            (0x00000100)
#define  TP_PREFIX_CTRL_tp3_sel_mask                                             (0x000000C0)
#define  TP_PREFIX_CTRL_tp0_sel_mask                                             (0x00000030)
#define  TP_PREFIX_CTRL_tp1_sel_mask                                             (0x0000000C)
#define  TP_PREFIX_CTRL_tp2_sel_mask                                             (0x00000003)
#define  TP_PREFIX_CTRL_tp3_keep(data)                                           (0x00000800&((data)<<11))
#define  TP_PREFIX_CTRL_tp0_keep(data)                                           (0x00000400&((data)<<10))
#define  TP_PREFIX_CTRL_tp1_keep(data)                                           (0x00000200&((data)<<9))
#define  TP_PREFIX_CTRL_tp2_keep(data)                                           (0x00000100&((data)<<8))
#define  TP_PREFIX_CTRL_tp3_sel(data)                                            (0x000000C0&((data)<<6))
#define  TP_PREFIX_CTRL_tp0_sel(data)                                            (0x00000030&((data)<<4))
#define  TP_PREFIX_CTRL_tp1_sel(data)                                            (0x0000000C&((data)<<2))
#define  TP_PREFIX_CTRL_tp2_sel(data)                                            (0x00000003&(data))
#define  TP_PREFIX_CTRL_get_tp3_keep(data)                                       ((0x00000800&(data))>>11)
#define  TP_PREFIX_CTRL_get_tp0_keep(data)                                       ((0x00000400&(data))>>10)
#define  TP_PREFIX_CTRL_get_tp1_keep(data)                                       ((0x00000200&(data))>>9)
#define  TP_PREFIX_CTRL_get_tp2_keep(data)                                       ((0x00000100&(data))>>8)
#define  TP_PREFIX_CTRL_get_tp3_sel(data)                                        ((0x000000C0&(data))>>6)
#define  TP_PREFIX_CTRL_get_tp0_sel(data)                                        ((0x00000030&(data))>>4)
#define  TP_PREFIX_CTRL_get_tp1_sel(data)                                        ((0x0000000C&(data))>>2)
#define  TP_PREFIX_CTRL_get_tp2_sel(data)                                        (0x00000003&(data))

#define  TP_PREFIX_DATA1                                                         0x18014724
#define  TP_PREFIX_DATA1_reg_addr                                                "0xB8014724"
#define  TP_PREFIX_DATA1_reg                                                     0xB8014724
#define  TP_PREFIX_DATA1_inst_addr                                               "0x00BC"
#define  set_TP_PREFIX_DATA1_reg(data)                                           (*((volatile unsigned int*)TP_PREFIX_DATA1_reg)=data)
#define  get_TP_PREFIX_DATA1_reg                                                 (*((volatile unsigned int*)TP_PREFIX_DATA1_reg))
#define  TP_PREFIX_DATA1_meta_shift                                              (0)
#define  TP_PREFIX_DATA1_meta_mask                                               (0xFFFFFFFF)
#define  TP_PREFIX_DATA1_meta(data)                                              (0xFFFFFFFF&(data))
#define  TP_PREFIX_DATA1_get_meta(data)                                          (0xFFFFFFFF&(data))

#define  TP_PREFIX_DATA2                                                         0x18014728
#define  TP_PREFIX_DATA2_reg_addr                                                "0xB8014728"
#define  TP_PREFIX_DATA2_reg                                                     0xB8014728
#define  TP_PREFIX_DATA2_inst_addr                                               "0x00BD"
#define  set_TP_PREFIX_DATA2_reg(data)                                           (*((volatile unsigned int*)TP_PREFIX_DATA2_reg)=data)
#define  get_TP_PREFIX_DATA2_reg                                                 (*((volatile unsigned int*)TP_PREFIX_DATA2_reg))
#define  TP_PREFIX_DATA2_dbg01_shift                                             (0)
#define  TP_PREFIX_DATA2_dbg01_mask                                              (0xFFFFFFFF)
#define  TP_PREFIX_DATA2_dbg01(data)                                             (0xFFFFFFFF&(data))
#define  TP_PREFIX_DATA2_get_dbg01(data)                                         (0xFFFFFFFF&(data))

#define  TP_PREFIX_DATA3                                                         0x1801472C
#define  TP_PREFIX_DATA3_reg_addr                                                "0xB801472C"
#define  TP_PREFIX_DATA3_reg                                                     0xB801472C
#define  TP_PREFIX_DATA3_inst_addr                                               "0x00BE"
#define  set_TP_PREFIX_DATA3_reg(data)                                           (*((volatile unsigned int*)TP_PREFIX_DATA3_reg)=data)
#define  get_TP_PREFIX_DATA3_reg                                                 (*((volatile unsigned int*)TP_PREFIX_DATA3_reg))
#define  TP_PREFIX_DATA3_dbg02_shift                                             (0)
#define  TP_PREFIX_DATA3_dbg02_mask                                              (0xFFFFFFFF)
#define  TP_PREFIX_DATA3_dbg02(data)                                             (0xFFFFFFFF&(data))
#define  TP_PREFIX_DATA3_get_dbg02(data)                                         (0xFFFFFFFF&(data))

#define  TP_FR_CTRL                                                              0x18014730
#define  TP_FR_CTRL_reg_addr                                                     "0xB8014730"
#define  TP_FR_CTRL_reg                                                          0xB8014730
#define  TP_FR_CTRL_inst_addr                                                    "0x00BF"
#define  set_TP_FR_CTRL_reg(data)                                                (*((volatile unsigned int*)TP_FR_CTRL_reg)=data)
#define  get_TP_FR_CTRL_reg                                                      (*((volatile unsigned int*)TP_FR_CTRL_reg))
#define  TP_FR_CTRL_tp3_en_shift                                                 (15)
#define  TP_FR_CTRL_tp3_rate_shift                                               (12)
#define  TP_FR_CTRL_tp2_en_shift                                                 (11)
#define  TP_FR_CTRL_tp2_rate_shift                                               (8)
#define  TP_FR_CTRL_tp1_en_shift                                                 (7)
#define  TP_FR_CTRL_tp1_rate_shift                                               (4)
#define  TP_FR_CTRL_tp0_en_shift                                                 (3)
#define  TP_FR_CTRL_tp0_rate_shift                                               (0)
#define  TP_FR_CTRL_tp3_en_mask                                                  (0x00008000)
#define  TP_FR_CTRL_tp3_rate_mask                                                (0x00007000)
#define  TP_FR_CTRL_tp2_en_mask                                                  (0x00000800)
#define  TP_FR_CTRL_tp2_rate_mask                                                (0x00000700)
#define  TP_FR_CTRL_tp1_en_mask                                                  (0x00000080)
#define  TP_FR_CTRL_tp1_rate_mask                                                (0x00000070)
#define  TP_FR_CTRL_tp0_en_mask                                                  (0x00000008)
#define  TP_FR_CTRL_tp0_rate_mask                                                (0x00000007)
#define  TP_FR_CTRL_tp3_en(data)                                                 (0x00008000&((data)<<15))
#define  TP_FR_CTRL_tp3_rate(data)                                               (0x00007000&((data)<<12))
#define  TP_FR_CTRL_tp2_en(data)                                                 (0x00000800&((data)<<11))
#define  TP_FR_CTRL_tp2_rate(data)                                               (0x00000700&((data)<<8))
#define  TP_FR_CTRL_tp1_en(data)                                                 (0x00000080&((data)<<7))
#define  TP_FR_CTRL_tp1_rate(data)                                               (0x00000070&((data)<<4))
#define  TP_FR_CTRL_tp0_en(data)                                                 (0x00000008&((data)<<3))
#define  TP_FR_CTRL_tp0_rate(data)                                               (0x00000007&(data))
#define  TP_FR_CTRL_get_tp3_en(data)                                             ((0x00008000&(data))>>15)
#define  TP_FR_CTRL_get_tp3_rate(data)                                           ((0x00007000&(data))>>12)
#define  TP_FR_CTRL_get_tp2_en(data)                                             ((0x00000800&(data))>>11)
#define  TP_FR_CTRL_get_tp2_rate(data)                                           ((0x00000700&(data))>>8)
#define  TP_FR_CTRL_get_tp1_en(data)                                             ((0x00000080&(data))>>7)
#define  TP_FR_CTRL_get_tp1_rate(data)                                           ((0x00000070&(data))>>4)
#define  TP_FR_CTRL_get_tp0_en(data)                                             ((0x00000008&(data))>>3)
#define  TP_FR_CTRL_get_tp0_rate(data)                                           (0x00000007&(data))

#define  TP_FR_CNT_TP0                                                           0x18014734
#define  TP_FR_CNT_TP0_reg_addr                                                  "0xB8014734"
#define  TP_FR_CNT_TP0_reg                                                       0xB8014734
#define  TP_FR_CNT_TP0_inst_addr                                                 "0x00C0"
#define  set_TP_FR_CNT_TP0_reg(data)                                             (*((volatile unsigned int*)TP_FR_CNT_TP0_reg)=data)
#define  get_TP_FR_CNT_TP0_reg                                                   (*((volatile unsigned int*)TP_FR_CNT_TP0_reg))
#define  TP_FR_CNT_TP0_cnt_shift                                                 (0)
#define  TP_FR_CNT_TP0_cnt_mask                                                  (0xFFFFFFFF)
#define  TP_FR_CNT_TP0_cnt(data)                                                 (0xFFFFFFFF&(data))
#define  TP_FR_CNT_TP0_get_cnt(data)                                             (0xFFFFFFFF&(data))

#define  TP_FR_CNT_TP1                                                           0x18014744
#define  TP_FR_CNT_TP1_reg_addr                                                  "0xB8014744"
#define  TP_FR_CNT_TP1_reg                                                       0xB8014744
#define  TP_FR_CNT_TP1_inst_addr                                                 "0x00C1"
#define  set_TP_FR_CNT_TP1_reg(data)                                             (*((volatile unsigned int*)TP_FR_CNT_TP1_reg)=data)
#define  get_TP_FR_CNT_TP1_reg                                                   (*((volatile unsigned int*)TP_FR_CNT_TP1_reg))
#define  TP_FR_CNT_TP1_cnt_shift                                                 (0)
#define  TP_FR_CNT_TP1_cnt_mask                                                  (0xFFFFFFFF)
#define  TP_FR_CNT_TP1_cnt(data)                                                 (0xFFFFFFFF&(data))
#define  TP_FR_CNT_TP1_get_cnt(data)                                             (0xFFFFFFFF&(data))

#define  TP_FR_CNT_TP2                                                           0x18014748
#define  TP_FR_CNT_TP2_reg_addr                                                  "0xB8014748"
#define  TP_FR_CNT_TP2_reg                                                       0xB8014748
#define  TP_FR_CNT_TP2_inst_addr                                                 "0x00C2"
#define  set_TP_FR_CNT_TP2_reg(data)                                             (*((volatile unsigned int*)TP_FR_CNT_TP2_reg)=data)
#define  get_TP_FR_CNT_TP2_reg                                                   (*((volatile unsigned int*)TP_FR_CNT_TP2_reg))
#define  TP_FR_CNT_TP2_cnt_shift                                                 (0)
#define  TP_FR_CNT_TP2_cnt_mask                                                  (0xFFFFFFFF)
#define  TP_FR_CNT_TP2_cnt(data)                                                 (0xFFFFFFFF&(data))
#define  TP_FR_CNT_TP2_get_cnt(data)                                             (0xFFFFFFFF&(data))

#define  TP_FR_CNT_TP3                                                           0x1801474C
#define  TP_FR_CNT_TP3_reg_addr                                                  "0xB801474C"
#define  TP_FR_CNT_TP3_reg                                                       0xB801474C
#define  TP_FR_CNT_TP3_inst_addr                                                 "0x00C3"
#define  set_TP_FR_CNT_TP3_reg(data)                                             (*((volatile unsigned int*)TP_FR_CNT_TP3_reg)=data)
#define  get_TP_FR_CNT_TP3_reg                                                   (*((volatile unsigned int*)TP_FR_CNT_TP3_reg))
#define  TP_FR_CNT_TP3_cnt_shift                                                 (0)
#define  TP_FR_CNT_TP3_cnt_mask                                                  (0xFFFFFFFF)
#define  TP_FR_CNT_TP3_cnt(data)                                                 (0xFFFFFFFF&(data))
#define  TP_FR_CNT_TP3_get_cnt(data)                                             (0xFFFFFFFF&(data))

#define  TP_START_CODE_TP0                                                       0x18014750
#define  TP_START_CODE_TP0_reg_addr                                              "0xB8014750"
#define  TP_START_CODE_TP0_reg                                                   0xB8014750
#define  TP_START_CODE_TP0_inst_addr                                             "0x00C4"
#define  set_TP_START_CODE_TP0_reg(data)                                         (*((volatile unsigned int*)TP_START_CODE_TP0_reg)=data)
#define  get_TP_START_CODE_TP0_reg                                               (*((volatile unsigned int*)TP_START_CODE_TP0_reg))
#define  TP_START_CODE_TP0_req_level_shift                                       (26)
#define  TP_START_CODE_TP0_dma_flush_shift                                       (25)
#define  TP_START_CODE_TP0_en_shift                                              (24)
#define  TP_START_CODE_TP0_pattern_shift                                         (0)
#define  TP_START_CODE_TP0_req_level_mask                                        (0x7C000000)
#define  TP_START_CODE_TP0_dma_flush_mask                                        (0x02000000)
#define  TP_START_CODE_TP0_en_mask                                               (0x01000000)
#define  TP_START_CODE_TP0_pattern_mask                                          (0x00FFFFFF)
#define  TP_START_CODE_TP0_req_level(data)                                       (0x7C000000&((data)<<26))
#define  TP_START_CODE_TP0_dma_flush(data)                                       (0x02000000&((data)<<25))
#define  TP_START_CODE_TP0_en(data)                                              (0x01000000&((data)<<24))
#define  TP_START_CODE_TP0_pattern(data)                                         (0x00FFFFFF&(data))
#define  TP_START_CODE_TP0_get_req_level(data)                                   ((0x7C000000&(data))>>26)
#define  TP_START_CODE_TP0_get_dma_flush(data)                                   ((0x02000000&(data))>>25)
#define  TP_START_CODE_TP0_get_en(data)                                          ((0x01000000&(data))>>24)
#define  TP_START_CODE_TP0_get_pattern(data)                                     (0x00FFFFFF&(data))

#define  TP_START_CODE_TP1                                                       0x18014754
#define  TP_START_CODE_TP1_reg_addr                                              "0xB8014754"
#define  TP_START_CODE_TP1_reg                                                   0xB8014754
#define  TP_START_CODE_TP1_inst_addr                                             "0x00C5"
#define  set_TP_START_CODE_TP1_reg(data)                                         (*((volatile unsigned int*)TP_START_CODE_TP1_reg)=data)
#define  get_TP_START_CODE_TP1_reg                                               (*((volatile unsigned int*)TP_START_CODE_TP1_reg))
#define  TP_START_CODE_TP1_req_level_shift                                       (26)
#define  TP_START_CODE_TP1_dma_flush_shift                                       (25)
#define  TP_START_CODE_TP1_en_shift                                              (24)
#define  TP_START_CODE_TP1_pattern_shift                                         (0)
#define  TP_START_CODE_TP1_req_level_mask                                        (0x7C000000)
#define  TP_START_CODE_TP1_dma_flush_mask                                        (0x02000000)
#define  TP_START_CODE_TP1_en_mask                                               (0x01000000)
#define  TP_START_CODE_TP1_pattern_mask                                          (0x00FFFFFF)
#define  TP_START_CODE_TP1_req_level(data)                                       (0x7C000000&((data)<<26))
#define  TP_START_CODE_TP1_dma_flush(data)                                       (0x02000000&((data)<<25))
#define  TP_START_CODE_TP1_en(data)                                              (0x01000000&((data)<<24))
#define  TP_START_CODE_TP1_pattern(data)                                         (0x00FFFFFF&(data))
#define  TP_START_CODE_TP1_get_req_level(data)                                   ((0x7C000000&(data))>>26)
#define  TP_START_CODE_TP1_get_dma_flush(data)                                   ((0x02000000&(data))>>25)
#define  TP_START_CODE_TP1_get_en(data)                                          ((0x01000000&(data))>>24)
#define  TP_START_CODE_TP1_get_pattern(data)                                     (0x00FFFFFF&(data))

#define  TP_START_CODE_CTRL_TP0                                                  0x1801475C
#define  TP_START_CODE_CTRL_TP0_reg_addr                                         "0xB801475C"
#define  TP_START_CODE_CTRL_TP0_reg                                              0xB801475C
#define  TP_START_CODE_CTRL_TP0_inst_addr                                        "0x00C6"
#define  set_TP_START_CODE_CTRL_TP0_reg(data)                                    (*((volatile unsigned int*)TP_START_CODE_CTRL_TP0_reg)=data)
#define  get_TP_START_CODE_CTRL_TP0_reg                                          (*((volatile unsigned int*)TP_START_CODE_CTRL_TP0_reg))
#define  TP_START_CODE_CTRL_TP0_fifo_cnt_shift                                   (24)
#define  TP_START_CODE_CTRL_TP0_sw_rst_shift                                     (18)
#define  TP_START_CODE_CTRL_TP0_info_q_shift                                     (13)
#define  TP_START_CODE_CTRL_TP0_pid_shift                                        (0)
#define  TP_START_CODE_CTRL_TP0_fifo_cnt_mask                                    (0x7F000000)
#define  TP_START_CODE_CTRL_TP0_sw_rst_mask                                      (0x00040000)
#define  TP_START_CODE_CTRL_TP0_info_q_mask                                      (0x0003E000)
#define  TP_START_CODE_CTRL_TP0_pid_mask                                         (0x00001FFF)
#define  TP_START_CODE_CTRL_TP0_fifo_cnt(data)                                   (0x7F000000&((data)<<24))
#define  TP_START_CODE_CTRL_TP0_sw_rst(data)                                     (0x00040000&((data)<<18))
#define  TP_START_CODE_CTRL_TP0_info_q(data)                                     (0x0003E000&((data)<<13))
#define  TP_START_CODE_CTRL_TP0_pid(data)                                        (0x00001FFF&(data))
#define  TP_START_CODE_CTRL_TP0_get_fifo_cnt(data)                               ((0x7F000000&(data))>>24)
#define  TP_START_CODE_CTRL_TP0_get_sw_rst(data)                                 ((0x00040000&(data))>>18)
#define  TP_START_CODE_CTRL_TP0_get_info_q(data)                                 ((0x0003E000&(data))>>13)
#define  TP_START_CODE_CTRL_TP0_get_pid(data)                                    (0x00001FFF&(data))

#define  TP_START_CODE_CTRL_TP1                                                  0x18014760
#define  TP_START_CODE_CTRL_TP1_reg_addr                                         "0xB8014760"
#define  TP_START_CODE_CTRL_TP1_reg                                              0xB8014760
#define  TP_START_CODE_CTRL_TP1_inst_addr                                        "0x00C7"
#define  set_TP_START_CODE_CTRL_TP1_reg(data)                                    (*((volatile unsigned int*)TP_START_CODE_CTRL_TP1_reg)=data)
#define  get_TP_START_CODE_CTRL_TP1_reg                                          (*((volatile unsigned int*)TP_START_CODE_CTRL_TP1_reg))
#define  TP_START_CODE_CTRL_TP1_fifo_cnt_shift                                   (24)
#define  TP_START_CODE_CTRL_TP1_sw_rst_shift                                     (18)
#define  TP_START_CODE_CTRL_TP1_info_q_shift                                     (13)
#define  TP_START_CODE_CTRL_TP1_pid_shift                                        (0)
#define  TP_START_CODE_CTRL_TP1_fifo_cnt_mask                                    (0x7F000000)
#define  TP_START_CODE_CTRL_TP1_sw_rst_mask                                      (0x00040000)
#define  TP_START_CODE_CTRL_TP1_info_q_mask                                      (0x0003E000)
#define  TP_START_CODE_CTRL_TP1_pid_mask                                         (0x00001FFF)
#define  TP_START_CODE_CTRL_TP1_fifo_cnt(data)                                   (0x7F000000&((data)<<24))
#define  TP_START_CODE_CTRL_TP1_sw_rst(data)                                     (0x00040000&((data)<<18))
#define  TP_START_CODE_CTRL_TP1_info_q(data)                                     (0x0003E000&((data)<<13))
#define  TP_START_CODE_CTRL_TP1_pid(data)                                        (0x00001FFF&(data))
#define  TP_START_CODE_CTRL_TP1_get_fifo_cnt(data)                               ((0x7F000000&(data))>>24)
#define  TP_START_CODE_CTRL_TP1_get_sw_rst(data)                                 ((0x00040000&(data))>>18)
#define  TP_START_CODE_CTRL_TP1_get_info_q(data)                                 ((0x0003E000&(data))>>13)
#define  TP_START_CODE_CTRL_TP1_get_pid(data)                                    (0x00001FFF&(data))

#define  TP_START_CODE_WP_TP0                                                    0x18014764
#define  TP_START_CODE_WP_TP0_reg_addr                                           "0xB8014764"
#define  TP_START_CODE_WP_TP0_reg                                                0xB8014764
#define  TP_START_CODE_WP_TP0_inst_addr                                          "0x00C8"
#define  set_TP_START_CODE_WP_TP0_reg(data)                                      (*((volatile unsigned int*)TP_START_CODE_WP_TP0_reg)=data)
#define  get_TP_START_CODE_WP_TP0_reg                                            (*((volatile unsigned int*)TP_START_CODE_WP_TP0_reg))
#define  TP_START_CODE_WP_TP0_wp_shift                                           (0)
#define  TP_START_CODE_WP_TP0_wp_mask                                            (0xFFFFFFFF)
#define  TP_START_CODE_WP_TP0_wp(data)                                           (0xFFFFFFFF&(data))
#define  TP_START_CODE_WP_TP0_get_wp(data)                                       (0xFFFFFFFF&(data))

#define  TP_START_CODE_WP_TP1                                                    0x18014768
#define  TP_START_CODE_WP_TP1_reg_addr                                           "0xB8014768"
#define  TP_START_CODE_WP_TP1_reg                                                0xB8014768
#define  TP_START_CODE_WP_TP1_inst_addr                                          "0x00C9"
#define  set_TP_START_CODE_WP_TP1_reg(data)                                      (*((volatile unsigned int*)TP_START_CODE_WP_TP1_reg)=data)
#define  get_TP_START_CODE_WP_TP1_reg                                            (*((volatile unsigned int*)TP_START_CODE_WP_TP1_reg))
#define  TP_START_CODE_WP_TP1_wp_shift                                           (0)
#define  TP_START_CODE_WP_TP1_wp_mask                                            (0xFFFFFFFF)
#define  TP_START_CODE_WP_TP1_wp(data)                                           (0xFFFFFFFF&(data))
#define  TP_START_CODE_WP_TP1_get_wp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_SRC_CNTL                                                     0x18014800
#define  TP_TP_ATSC_SRC_CNTL_reg_addr                                            "0xB8014800"
#define  TP_TP_ATSC_SRC_CNTL_reg                                                 0xB8014800
#define  TP_TP_ATSC_SRC_CNTL_inst_addr                                           "0x00CA"
#define  set_TP_TP_ATSC_SRC_CNTL_reg(data)                                       (*((volatile unsigned int*)TP_TP_ATSC_SRC_CNTL_reg)=data)
#define  get_TP_TP_ATSC_SRC_CNTL_reg                                             (*((volatile unsigned int*)TP_TP_ATSC_SRC_CNTL_reg))
#define  TP_TP_ATSC_SRC_CNTL_sw_rst_shift                                        (28)
#define  TP_TP_ATSC_SRC_CNTL_data_endian_shift                                   (24)
#define  TP_TP_ATSC_SRC_CNTL_data_location_shift                                 (20)
#define  TP_TP_ATSC_SRC_CNTL_data_reverse_shift                                  (16)
#define  TP_TP_ATSC_SRC_CNTL_data_mode_shift                                     (12)
#define  TP_TP_ATSC_SRC_CNTL_protocol_shift                                      (8)
#define  TP_TP_ATSC_SRC_CNTL_src_sel_shift                                       (4)
#define  TP_TP_ATSC_SRC_CNTL_en_shift                                            (0)
#define  TP_TP_ATSC_SRC_CNTL_sw_rst_mask                                         (0x10000000)
#define  TP_TP_ATSC_SRC_CNTL_data_endian_mask                                    (0x01000000)
#define  TP_TP_ATSC_SRC_CNTL_data_location_mask                                  (0x00700000)
#define  TP_TP_ATSC_SRC_CNTL_data_reverse_mask                                   (0x00010000)
#define  TP_TP_ATSC_SRC_CNTL_data_mode_mask                                      (0x00003000)
#define  TP_TP_ATSC_SRC_CNTL_protocol_mask                                       (0x00000100)
#define  TP_TP_ATSC_SRC_CNTL_src_sel_mask                                        (0x00000030)
#define  TP_TP_ATSC_SRC_CNTL_en_mask                                             (0x00000001)
#define  TP_TP_ATSC_SRC_CNTL_sw_rst(data)                                        (0x10000000&((data)<<28))
#define  TP_TP_ATSC_SRC_CNTL_data_endian(data)                                   (0x01000000&((data)<<24))
#define  TP_TP_ATSC_SRC_CNTL_data_location(data)                                 (0x00700000&((data)<<20))
#define  TP_TP_ATSC_SRC_CNTL_data_reverse(data)                                  (0x00010000&((data)<<16))
#define  TP_TP_ATSC_SRC_CNTL_data_mode(data)                                     (0x00003000&((data)<<12))
#define  TP_TP_ATSC_SRC_CNTL_protocol(data)                                      (0x00000100&((data)<<8))
#define  TP_TP_ATSC_SRC_CNTL_src_sel(data)                                       (0x00000030&((data)<<4))
#define  TP_TP_ATSC_SRC_CNTL_en(data)                                            (0x00000001&(data))
#define  TP_TP_ATSC_SRC_CNTL_get_sw_rst(data)                                    ((0x10000000&(data))>>28)
#define  TP_TP_ATSC_SRC_CNTL_get_data_endian(data)                               ((0x01000000&(data))>>24)
#define  TP_TP_ATSC_SRC_CNTL_get_data_location(data)                             ((0x00700000&(data))>>20)
#define  TP_TP_ATSC_SRC_CNTL_get_data_reverse(data)                              ((0x00010000&(data))>>16)
#define  TP_TP_ATSC_SRC_CNTL_get_data_mode(data)                                 ((0x00003000&(data))>>12)
#define  TP_TP_ATSC_SRC_CNTL_get_protocol(data)                                  ((0x00000100&(data))>>8)
#define  TP_TP_ATSC_SRC_CNTL_get_src_sel(data)                                   ((0x00000030&(data))>>4)
#define  TP_TP_ATSC_SRC_CNTL_get_en(data)                                        (0x00000001&(data))

#define  TP_TP_ATSC_CONFIG1                                                      0x18014804
#define  TP_TP_ATSC_CONFIG1_reg_addr                                             "0xB8014804"
#define  TP_TP_ATSC_CONFIG1_reg                                                  0xB8014804
#define  TP_TP_ATSC_CONFIG1_inst_addr                                            "0x00CB"
#define  set_TP_TP_ATSC_CONFIG1_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_CONFIG1_reg)=data)
#define  get_TP_TP_ATSC_CONFIG1_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_CONFIG1_reg))
#define  TP_TP_ATSC_CONFIG1_sync_byte_shift                                      (24)
#define  TP_TP_ATSC_CONFIG1_dmy_discard_shift                                    (20)
#define  TP_TP_ATSC_CONFIG1_length_err_en_shift                                  (18)
#define  TP_TP_ATSC_CONFIG1_sync_en_shift                                        (17)
#define  TP_TP_ATSC_CONFIG1_err_en_shift                                         (16)
#define  TP_TP_ATSC_CONFIG1_oif_header_length_shift                              (4)
#define  TP_TP_ATSC_CONFIG1_hw_auto_mode_shift                                   (0)
#define  TP_TP_ATSC_CONFIG1_sync_byte_mask                                       (0xFF000000)
#define  TP_TP_ATSC_CONFIG1_dmy_discard_mask                                     (0x00100000)
#define  TP_TP_ATSC_CONFIG1_length_err_en_mask                                   (0x00040000)
#define  TP_TP_ATSC_CONFIG1_sync_en_mask                                         (0x00020000)
#define  TP_TP_ATSC_CONFIG1_err_en_mask                                          (0x00010000)
#define  TP_TP_ATSC_CONFIG1_oif_header_length_mask                               (0x00000FF0)
#define  TP_TP_ATSC_CONFIG1_hw_auto_mode_mask                                    (0x00000001)
#define  TP_TP_ATSC_CONFIG1_sync_byte(data)                                      (0xFF000000&((data)<<24))
#define  TP_TP_ATSC_CONFIG1_dmy_discard(data)                                    (0x00100000&((data)<<20))
#define  TP_TP_ATSC_CONFIG1_length_err_en(data)                                  (0x00040000&((data)<<18))
#define  TP_TP_ATSC_CONFIG1_sync_en(data)                                        (0x00020000&((data)<<17))
#define  TP_TP_ATSC_CONFIG1_err_en(data)                                         (0x00010000&((data)<<16))
#define  TP_TP_ATSC_CONFIG1_oif_header_length(data)                              (0x00000FF0&((data)<<4))
#define  TP_TP_ATSC_CONFIG1_hw_auto_mode(data)                                   (0x00000001&(data))
#define  TP_TP_ATSC_CONFIG1_get_sync_byte(data)                                  ((0xFF000000&(data))>>24)
#define  TP_TP_ATSC_CONFIG1_get_dmy_discard(data)                                ((0x00100000&(data))>>20)
#define  TP_TP_ATSC_CONFIG1_get_length_err_en(data)                              ((0x00040000&(data))>>18)
#define  TP_TP_ATSC_CONFIG1_get_sync_en(data)                                    ((0x00020000&(data))>>17)
#define  TP_TP_ATSC_CONFIG1_get_err_en(data)                                     ((0x00010000&(data))>>16)
#define  TP_TP_ATSC_CONFIG1_get_oif_header_length(data)                          ((0x00000FF0&(data))>>4)
#define  TP_TP_ATSC_CONFIG1_get_hw_auto_mode(data)                               (0x00000001&(data))

#define  TP_TP_ATSC_CONFIG2                                                      0x18014808
#define  TP_TP_ATSC_CONFIG2_reg_addr                                             "0xB8014808"
#define  TP_TP_ATSC_CONFIG2_reg                                                  0xB8014808
#define  TP_TP_ATSC_CONFIG2_inst_addr                                            "0x00CC"
#define  set_TP_TP_ATSC_CONFIG2_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_CONFIG2_reg)=data)
#define  get_TP_TP_ATSC_CONFIG2_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_CONFIG2_reg))
#define  TP_TP_ATSC_CONFIG2_starter_shift                                        (0)
#define  TP_TP_ATSC_CONFIG2_starter_mask                                         (0xFFFFFFFF)
#define  TP_TP_ATSC_CONFIG2_starter(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_CONFIG2_get_starter(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_CONFIG3                                                      0x1801480C
#define  TP_TP_ATSC_CONFIG3_reg_addr                                             "0xB801480C"
#define  TP_TP_ATSC_CONFIG3_reg                                                  0xB801480C
#define  TP_TP_ATSC_CONFIG3_inst_addr                                            "0x00CD"
#define  set_TP_TP_ATSC_CONFIG3_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_CONFIG3_reg)=data)
#define  get_TP_TP_ATSC_CONFIG3_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_CONFIG3_reg))
#define  TP_TP_ATSC_CONFIG3_oif_length_offset_shift                              (0)
#define  TP_TP_ATSC_CONFIG3_oif_length_offset_mask                               (0x0000FFFF)
#define  TP_TP_ATSC_CONFIG3_oif_length_offset(data)                              (0x0000FFFF&(data))
#define  TP_TP_ATSC_CONFIG3_get_oif_length_offset(data)                          (0x0000FFFF&(data))

#define  TP_TP_ATSC_PLP_FILTER1                                                  0x18014810
#define  TP_TP_ATSC_PLP_FILTER1_reg_addr                                         "0xB8014810"
#define  TP_TP_ATSC_PLP_FILTER1_reg                                              0xB8014810
#define  TP_TP_ATSC_PLP_FILTER1_inst_addr                                        "0x00CE"
#define  set_TP_TP_ATSC_PLP_FILTER1_reg(data)                                    (*((volatile unsigned int*)TP_TP_ATSC_PLP_FILTER1_reg)=data)
#define  get_TP_TP_ATSC_PLP_FILTER1_reg                                          (*((volatile unsigned int*)TP_TP_ATSC_PLP_FILTER1_reg))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx31_en_shift                               (31)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx30_en_shift                               (30)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx29_en_shift                               (29)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx28_en_shift                               (28)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx27_en_shift                               (27)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx26_en_shift                               (26)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx25_en_shift                               (25)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx24_en_shift                               (24)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx23_en_shift                               (23)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx22_en_shift                               (22)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx21_en_shift                               (21)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx20_en_shift                               (20)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx19_en_shift                               (19)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx18_en_shift                               (18)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx17_en_shift                               (17)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx16_en_shift                               (16)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx15_en_shift                               (15)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx14_en_shift                               (14)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx13_en_shift                               (13)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx12_en_shift                               (12)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx11_en_shift                               (11)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx10_en_shift                               (10)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx9_en_shift                                (9)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx8_en_shift                                (8)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx7_en_shift                                (7)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx6_en_shift                                (6)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx5_en_shift                                (5)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx4_en_shift                                (4)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx3_en_shift                                (3)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx2_en_shift                                (2)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx1_en_shift                                (1)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx0_en_shift                                (0)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx31_en_mask                                (0x80000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx30_en_mask                                (0x40000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx29_en_mask                                (0x20000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx28_en_mask                                (0x10000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx27_en_mask                                (0x08000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx26_en_mask                                (0x04000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx25_en_mask                                (0x02000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx24_en_mask                                (0x01000000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx23_en_mask                                (0x00800000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx22_en_mask                                (0x00400000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx21_en_mask                                (0x00200000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx20_en_mask                                (0x00100000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx19_en_mask                                (0x00080000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx18_en_mask                                (0x00040000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx17_en_mask                                (0x00020000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx16_en_mask                                (0x00010000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx15_en_mask                                (0x00008000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx14_en_mask                                (0x00004000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx13_en_mask                                (0x00002000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx12_en_mask                                (0x00001000)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx11_en_mask                                (0x00000800)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx10_en_mask                                (0x00000400)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx9_en_mask                                 (0x00000200)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx8_en_mask                                 (0x00000100)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx7_en_mask                                 (0x00000080)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx6_en_mask                                 (0x00000040)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx5_en_mask                                 (0x00000020)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx4_en_mask                                 (0x00000010)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx3_en_mask                                 (0x00000008)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx2_en_mask                                 (0x00000004)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx1_en_mask                                 (0x00000002)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx0_en_mask                                 (0x00000001)
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx31_en(data)                               (0x80000000&((data)<<31))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx30_en(data)                               (0x40000000&((data)<<30))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx29_en(data)                               (0x20000000&((data)<<29))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx28_en(data)                               (0x10000000&((data)<<28))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx27_en(data)                               (0x08000000&((data)<<27))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx26_en(data)                               (0x04000000&((data)<<26))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx25_en(data)                               (0x02000000&((data)<<25))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx24_en(data)                               (0x01000000&((data)<<24))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx23_en(data)                               (0x00800000&((data)<<23))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx22_en(data)                               (0x00400000&((data)<<22))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx21_en(data)                               (0x00200000&((data)<<21))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx20_en(data)                               (0x00100000&((data)<<20))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx19_en(data)                               (0x00080000&((data)<<19))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx18_en(data)                               (0x00040000&((data)<<18))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx17_en(data)                               (0x00020000&((data)<<17))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx16_en(data)                               (0x00010000&((data)<<16))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx15_en(data)                               (0x00008000&((data)<<15))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx14_en(data)                               (0x00004000&((data)<<14))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx13_en(data)                               (0x00002000&((data)<<13))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx12_en(data)                               (0x00001000&((data)<<12))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx11_en(data)                               (0x00000800&((data)<<11))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx10_en(data)                               (0x00000400&((data)<<10))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx9_en(data)                                (0x00000200&((data)<<9))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx8_en(data)                                (0x00000100&((data)<<8))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx7_en(data)                                (0x00000080&((data)<<7))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx6_en(data)                                (0x00000040&((data)<<6))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx5_en(data)                                (0x00000020&((data)<<5))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx4_en(data)                                (0x00000010&((data)<<4))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx3_en(data)                                (0x00000008&((data)<<3))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx2_en(data)                                (0x00000004&((data)<<2))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx1_en(data)                                (0x00000002&((data)<<1))
#define  TP_TP_ATSC_PLP_FILTER1_plp_idx0_en(data)                                (0x00000001&(data))
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx31_en(data)                           ((0x80000000&(data))>>31)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx30_en(data)                           ((0x40000000&(data))>>30)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx29_en(data)                           ((0x20000000&(data))>>29)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx28_en(data)                           ((0x10000000&(data))>>28)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx27_en(data)                           ((0x08000000&(data))>>27)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx26_en(data)                           ((0x04000000&(data))>>26)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx25_en(data)                           ((0x02000000&(data))>>25)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx24_en(data)                           ((0x01000000&(data))>>24)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx23_en(data)                           ((0x00800000&(data))>>23)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx22_en(data)                           ((0x00400000&(data))>>22)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx21_en(data)                           ((0x00200000&(data))>>21)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx20_en(data)                           ((0x00100000&(data))>>20)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx19_en(data)                           ((0x00080000&(data))>>19)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx18_en(data)                           ((0x00040000&(data))>>18)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx17_en(data)                           ((0x00020000&(data))>>17)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx16_en(data)                           ((0x00010000&(data))>>16)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx15_en(data)                           ((0x00008000&(data))>>15)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx14_en(data)                           ((0x00004000&(data))>>14)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx13_en(data)                           ((0x00002000&(data))>>13)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx12_en(data)                           ((0x00001000&(data))>>12)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx11_en(data)                           ((0x00000800&(data))>>11)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx10_en(data)                           ((0x00000400&(data))>>10)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx9_en(data)                            ((0x00000200&(data))>>9)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx8_en(data)                            ((0x00000100&(data))>>8)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx7_en(data)                            ((0x00000080&(data))>>7)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx6_en(data)                            ((0x00000040&(data))>>6)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx5_en(data)                            ((0x00000020&(data))>>5)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx4_en(data)                            ((0x00000010&(data))>>4)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx3_en(data)                            ((0x00000008&(data))>>3)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx2_en(data)                            ((0x00000004&(data))>>2)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx1_en(data)                            ((0x00000002&(data))>>1)
#define  TP_TP_ATSC_PLP_FILTER1_get_plp_idx0_en(data)                            (0x00000001&(data))

#define  TP_TP_ATSC_PLP_FILTER2                                                  0x18014814
#define  TP_TP_ATSC_PLP_FILTER2_reg_addr                                         "0xB8014814"
#define  TP_TP_ATSC_PLP_FILTER2_reg                                              0xB8014814
#define  TP_TP_ATSC_PLP_FILTER2_inst_addr                                        "0x00CF"
#define  set_TP_TP_ATSC_PLP_FILTER2_reg(data)                                    (*((volatile unsigned int*)TP_TP_ATSC_PLP_FILTER2_reg)=data)
#define  get_TP_TP_ATSC_PLP_FILTER2_reg                                          (*((volatile unsigned int*)TP_TP_ATSC_PLP_FILTER2_reg))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx63_en_shift                               (31)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx62_en_shift                               (30)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx61_en_shift                               (29)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx60_en_shift                               (28)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx59_en_shift                               (27)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx58_en_shift                               (26)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx57_en_shift                               (25)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx56_en_shift                               (24)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx55_en_shift                               (23)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx54_en_shift                               (22)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx53_en_shift                               (21)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx52_en_shift                               (20)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx51_en_shift                               (19)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx50_en_shift                               (18)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx49_en_shift                               (17)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx48_en_shift                               (16)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx47_en_shift                               (15)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx46_en_shift                               (14)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx45_en_shift                               (13)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx44_en_shift                               (12)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx43_en_shift                               (11)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx42_en_shift                               (10)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx41_en_shift                               (9)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx40_en_shift                               (8)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx39_en_shift                               (7)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx38_en_shift                               (6)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx37_en_shift                               (5)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx36_en_shift                               (4)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx35_en_shift                               (3)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx34_en_shift                               (2)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx33_en_shift                               (1)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx32_en_shift                               (0)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx63_en_mask                                (0x80000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx62_en_mask                                (0x40000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx61_en_mask                                (0x20000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx60_en_mask                                (0x10000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx59_en_mask                                (0x08000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx58_en_mask                                (0x04000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx57_en_mask                                (0x02000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx56_en_mask                                (0x01000000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx55_en_mask                                (0x00800000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx54_en_mask                                (0x00400000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx53_en_mask                                (0x00200000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx52_en_mask                                (0x00100000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx51_en_mask                                (0x00080000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx50_en_mask                                (0x00040000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx49_en_mask                                (0x00020000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx48_en_mask                                (0x00010000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx47_en_mask                                (0x00008000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx46_en_mask                                (0x00004000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx45_en_mask                                (0x00002000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx44_en_mask                                (0x00001000)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx43_en_mask                                (0x00000800)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx42_en_mask                                (0x00000400)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx41_en_mask                                (0x00000200)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx40_en_mask                                (0x00000100)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx39_en_mask                                (0x00000080)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx38_en_mask                                (0x00000040)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx37_en_mask                                (0x00000020)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx36_en_mask                                (0x00000010)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx35_en_mask                                (0x00000008)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx34_en_mask                                (0x00000004)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx33_en_mask                                (0x00000002)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx32_en_mask                                (0x00000001)
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx63_en(data)                               (0x80000000&((data)<<31))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx62_en(data)                               (0x40000000&((data)<<30))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx61_en(data)                               (0x20000000&((data)<<29))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx60_en(data)                               (0x10000000&((data)<<28))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx59_en(data)                               (0x08000000&((data)<<27))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx58_en(data)                               (0x04000000&((data)<<26))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx57_en(data)                               (0x02000000&((data)<<25))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx56_en(data)                               (0x01000000&((data)<<24))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx55_en(data)                               (0x00800000&((data)<<23))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx54_en(data)                               (0x00400000&((data)<<22))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx53_en(data)                               (0x00200000&((data)<<21))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx52_en(data)                               (0x00100000&((data)<<20))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx51_en(data)                               (0x00080000&((data)<<19))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx50_en(data)                               (0x00040000&((data)<<18))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx49_en(data)                               (0x00020000&((data)<<17))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx48_en(data)                               (0x00010000&((data)<<16))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx47_en(data)                               (0x00008000&((data)<<15))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx46_en(data)                               (0x00004000&((data)<<14))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx45_en(data)                               (0x00002000&((data)<<13))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx44_en(data)                               (0x00001000&((data)<<12))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx43_en(data)                               (0x00000800&((data)<<11))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx42_en(data)                               (0x00000400&((data)<<10))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx41_en(data)                               (0x00000200&((data)<<9))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx40_en(data)                               (0x00000100&((data)<<8))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx39_en(data)                               (0x00000080&((data)<<7))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx38_en(data)                               (0x00000040&((data)<<6))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx37_en(data)                               (0x00000020&((data)<<5))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx36_en(data)                               (0x00000010&((data)<<4))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx35_en(data)                               (0x00000008&((data)<<3))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx34_en(data)                               (0x00000004&((data)<<2))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx33_en(data)                               (0x00000002&((data)<<1))
#define  TP_TP_ATSC_PLP_FILTER2_plp_idx32_en(data)                               (0x00000001&(data))
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx63_en(data)                           ((0x80000000&(data))>>31)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx62_en(data)                           ((0x40000000&(data))>>30)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx61_en(data)                           ((0x20000000&(data))>>29)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx60_en(data)                           ((0x10000000&(data))>>28)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx59_en(data)                           ((0x08000000&(data))>>27)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx58_en(data)                           ((0x04000000&(data))>>26)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx57_en(data)                           ((0x02000000&(data))>>25)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx56_en(data)                           ((0x01000000&(data))>>24)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx55_en(data)                           ((0x00800000&(data))>>23)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx54_en(data)                           ((0x00400000&(data))>>22)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx53_en(data)                           ((0x00200000&(data))>>21)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx52_en(data)                           ((0x00100000&(data))>>20)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx51_en(data)                           ((0x00080000&(data))>>19)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx50_en(data)                           ((0x00040000&(data))>>18)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx49_en(data)                           ((0x00020000&(data))>>17)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx48_en(data)                           ((0x00010000&(data))>>16)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx47_en(data)                           ((0x00008000&(data))>>15)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx46_en(data)                           ((0x00004000&(data))>>14)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx45_en(data)                           ((0x00002000&(data))>>13)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx44_en(data)                           ((0x00001000&(data))>>12)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx43_en(data)                           ((0x00000800&(data))>>11)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx42_en(data)                           ((0x00000400&(data))>>10)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx41_en(data)                           ((0x00000200&(data))>>9)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx40_en(data)                           ((0x00000100&(data))>>8)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx39_en(data)                           ((0x00000080&(data))>>7)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx38_en(data)                           ((0x00000040&(data))>>6)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx37_en(data)                           ((0x00000020&(data))>>5)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx36_en(data)                           ((0x00000010&(data))>>4)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx35_en(data)                           ((0x00000008&(data))>>3)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx34_en(data)                           ((0x00000004&(data))>>2)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx33_en(data)                           ((0x00000002&(data))>>1)
#define  TP_TP_ATSC_PLP_FILTER2_get_plp_idx32_en(data)                           (0x00000001&(data))

#define  TP_TP_ATSC_D_LIMIT                                                      0x18014818
#define  TP_TP_ATSC_D_LIMIT_reg_addr                                             "0xB8014818"
#define  TP_TP_ATSC_D_LIMIT_reg                                                  0xB8014818
#define  TP_TP_ATSC_D_LIMIT_inst_addr                                            "0x00D0"
#define  set_TP_TP_ATSC_D_LIMIT_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_D_LIMIT_reg)=data)
#define  get_TP_TP_ATSC_D_LIMIT_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_D_LIMIT_reg))
#define  TP_TP_ATSC_D_LIMIT_ring_limit_shift                                     (3)
#define  TP_TP_ATSC_D_LIMIT_ring_limit_mask                                      (0xFFFFFFF8)
#define  TP_TP_ATSC_D_LIMIT_ring_limit(data)                                     (0xFFFFFFF8&((data)<<3))
#define  TP_TP_ATSC_D_LIMIT_get_ring_limit(data)                                 ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_ATSC_D_BASE                                                       0x1801481C
#define  TP_TP_ATSC_D_BASE_reg_addr                                              "0xB801481C"
#define  TP_TP_ATSC_D_BASE_reg                                                   0xB801481C
#define  TP_TP_ATSC_D_BASE_inst_addr                                             "0x00D1"
#define  set_TP_TP_ATSC_D_BASE_reg(data)                                         (*((volatile unsigned int*)TP_TP_ATSC_D_BASE_reg)=data)
#define  get_TP_TP_ATSC_D_BASE_reg                                               (*((volatile unsigned int*)TP_TP_ATSC_D_BASE_reg))
#define  TP_TP_ATSC_D_BASE_ring_base_shift                                       (3)
#define  TP_TP_ATSC_D_BASE_ring_base_mask                                        (0xFFFFFFF8)
#define  TP_TP_ATSC_D_BASE_ring_base(data)                                       (0xFFFFFFF8&((data)<<3))
#define  TP_TP_ATSC_D_BASE_get_ring_base(data)                                   ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_ATSC_D_RP                                                         0x18014820
#define  TP_TP_ATSC_D_RP_reg_addr                                                "0xB8014820"
#define  TP_TP_ATSC_D_RP_reg                                                     0xB8014820
#define  TP_TP_ATSC_D_RP_inst_addr                                               "0x00D2"
#define  set_TP_TP_ATSC_D_RP_reg(data)                                           (*((volatile unsigned int*)TP_TP_ATSC_D_RP_reg)=data)
#define  get_TP_TP_ATSC_D_RP_reg                                                 (*((volatile unsigned int*)TP_TP_ATSC_D_RP_reg))
#define  TP_TP_ATSC_D_RP_ring_rp_shift                                           (0)
#define  TP_TP_ATSC_D_RP_ring_rp_mask                                            (0xFFFFFFFF)
#define  TP_TP_ATSC_D_RP_ring_rp(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_D_RP_get_ring_rp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_D_WP                                                         0x18014824
#define  TP_TP_ATSC_D_WP_reg_addr                                                "0xB8014824"
#define  TP_TP_ATSC_D_WP_reg                                                     0xB8014824
#define  TP_TP_ATSC_D_WP_inst_addr                                               "0x00D3"
#define  set_TP_TP_ATSC_D_WP_reg(data)                                           (*((volatile unsigned int*)TP_TP_ATSC_D_WP_reg)=data)
#define  get_TP_TP_ATSC_D_WP_reg                                                 (*((volatile unsigned int*)TP_TP_ATSC_D_WP_reg))
#define  TP_TP_ATSC_D_WP_ring_wp_shift                                           (0)
#define  TP_TP_ATSC_D_WP_ring_wp_mask                                            (0xFFFFFFFF)
#define  TP_TP_ATSC_D_WP_ring_wp(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_D_WP_get_ring_wp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_I_LIMIT                                                      0x18014828
#define  TP_TP_ATSC_I_LIMIT_reg_addr                                             "0xB8014828"
#define  TP_TP_ATSC_I_LIMIT_reg                                                  0xB8014828
#define  TP_TP_ATSC_I_LIMIT_inst_addr                                            "0x00D4"
#define  set_TP_TP_ATSC_I_LIMIT_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_I_LIMIT_reg)=data)
#define  get_TP_TP_ATSC_I_LIMIT_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_I_LIMIT_reg))
#define  TP_TP_ATSC_I_LIMIT_ring_limit_shift                                     (3)
#define  TP_TP_ATSC_I_LIMIT_ring_limit_mask                                      (0xFFFFFFF8)
#define  TP_TP_ATSC_I_LIMIT_ring_limit(data)                                     (0xFFFFFFF8&((data)<<3))
#define  TP_TP_ATSC_I_LIMIT_get_ring_limit(data)                                 ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_ATSC_I_BASE                                                       0x1801482C
#define  TP_TP_ATSC_I_BASE_reg_addr                                              "0xB801482C"
#define  TP_TP_ATSC_I_BASE_reg                                                   0xB801482C
#define  TP_TP_ATSC_I_BASE_inst_addr                                             "0x00D5"
#define  set_TP_TP_ATSC_I_BASE_reg(data)                                         (*((volatile unsigned int*)TP_TP_ATSC_I_BASE_reg)=data)
#define  get_TP_TP_ATSC_I_BASE_reg                                               (*((volatile unsigned int*)TP_TP_ATSC_I_BASE_reg))
#define  TP_TP_ATSC_I_BASE_ring_base_shift                                       (3)
#define  TP_TP_ATSC_I_BASE_ring_base_mask                                        (0xFFFFFFF8)
#define  TP_TP_ATSC_I_BASE_ring_base(data)                                       (0xFFFFFFF8&((data)<<3))
#define  TP_TP_ATSC_I_BASE_get_ring_base(data)                                   ((0xFFFFFFF8&(data))>>3)

#define  TP_TP_ATSC_I_RP                                                         0x18014830
#define  TP_TP_ATSC_I_RP_reg_addr                                                "0xB8014830"
#define  TP_TP_ATSC_I_RP_reg                                                     0xB8014830
#define  TP_TP_ATSC_I_RP_inst_addr                                               "0x00D6"
#define  set_TP_TP_ATSC_I_RP_reg(data)                                           (*((volatile unsigned int*)TP_TP_ATSC_I_RP_reg)=data)
#define  get_TP_TP_ATSC_I_RP_reg                                                 (*((volatile unsigned int*)TP_TP_ATSC_I_RP_reg))
#define  TP_TP_ATSC_I_RP_ring_rp_shift                                           (0)
#define  TP_TP_ATSC_I_RP_ring_rp_mask                                            (0xFFFFFFFF)
#define  TP_TP_ATSC_I_RP_ring_rp(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_I_RP_get_ring_rp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_I_WP                                                         0x18014834
#define  TP_TP_ATSC_I_WP_reg_addr                                                "0xB8014834"
#define  TP_TP_ATSC_I_WP_reg                                                     0xB8014834
#define  TP_TP_ATSC_I_WP_inst_addr                                               "0x00D7"
#define  set_TP_TP_ATSC_I_WP_reg(data)                                           (*((volatile unsigned int*)TP_TP_ATSC_I_WP_reg)=data)
#define  get_TP_TP_ATSC_I_WP_reg                                                 (*((volatile unsigned int*)TP_TP_ATSC_I_WP_reg))
#define  TP_TP_ATSC_I_WP_ring_wp_shift                                           (0)
#define  TP_TP_ATSC_I_WP_ring_wp_mask                                            (0xFFFFFFFF)
#define  TP_TP_ATSC_I_WP_ring_wp(data)                                           (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_I_WP_get_ring_wp(data)                                       (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_RING_CTRL                                                    0x18014838
#define  TP_TP_ATSC_RING_CTRL_reg_addr                                           "0xB8014838"
#define  TP_TP_ATSC_RING_CTRL_reg                                                0xB8014838
#define  TP_TP_ATSC_RING_CTRL_inst_addr                                          "0x00D8"
#define  set_TP_TP_ATSC_RING_CTRL_reg(data)                                      (*((volatile unsigned int*)TP_TP_ATSC_RING_CTRL_reg)=data)
#define  get_TP_TP_ATSC_RING_CTRL_reg                                            (*((volatile unsigned int*)TP_TP_ATSC_RING_CTRL_reg))
#define  TP_TP_ATSC_RING_CTRL_iring_full_en_shift                                (28)
#define  TP_TP_ATSC_RING_CTRL_iring_full_shift                                   (24)
#define  TP_TP_ATSC_RING_CTRL_iring_available_en_shift                           (20)
#define  TP_TP_ATSC_RING_CTRL_iring_available_shift                              (16)
#define  TP_TP_ATSC_RING_CTRL_dring_full_en_shift                                (12)
#define  TP_TP_ATSC_RING_CTRL_dring_full_shift                                   (8)
#define  TP_TP_ATSC_RING_CTRL_dring_available_en_shift                           (4)
#define  TP_TP_ATSC_RING_CTRL_dring_available_shift                              (0)
#define  TP_TP_ATSC_RING_CTRL_iring_full_en_mask                                 (0x10000000)
#define  TP_TP_ATSC_RING_CTRL_iring_full_mask                                    (0x01000000)
#define  TP_TP_ATSC_RING_CTRL_iring_available_en_mask                            (0x00100000)
#define  TP_TP_ATSC_RING_CTRL_iring_available_mask                               (0x00010000)
#define  TP_TP_ATSC_RING_CTRL_dring_full_en_mask                                 (0x00001000)
#define  TP_TP_ATSC_RING_CTRL_dring_full_mask                                    (0x00000100)
#define  TP_TP_ATSC_RING_CTRL_dring_available_en_mask                            (0x00000010)
#define  TP_TP_ATSC_RING_CTRL_dring_available_mask                               (0x00000001)
#define  TP_TP_ATSC_RING_CTRL_iring_full_en(data)                                (0x10000000&((data)<<28))
#define  TP_TP_ATSC_RING_CTRL_iring_full(data)                                   (0x01000000&((data)<<24))
#define  TP_TP_ATSC_RING_CTRL_iring_available_en(data)                           (0x00100000&((data)<<20))
#define  TP_TP_ATSC_RING_CTRL_iring_available(data)                              (0x00010000&((data)<<16))
#define  TP_TP_ATSC_RING_CTRL_dring_full_en(data)                                (0x00001000&((data)<<12))
#define  TP_TP_ATSC_RING_CTRL_dring_full(data)                                   (0x00000100&((data)<<8))
#define  TP_TP_ATSC_RING_CTRL_dring_available_en(data)                           (0x00000010&((data)<<4))
#define  TP_TP_ATSC_RING_CTRL_dring_available(data)                              (0x00000001&(data))
#define  TP_TP_ATSC_RING_CTRL_get_iring_full_en(data)                            ((0x10000000&(data))>>28)
#define  TP_TP_ATSC_RING_CTRL_get_iring_full(data)                               ((0x01000000&(data))>>24)
#define  TP_TP_ATSC_RING_CTRL_get_iring_available_en(data)                       ((0x00100000&(data))>>20)
#define  TP_TP_ATSC_RING_CTRL_get_iring_available(data)                          ((0x00010000&(data))>>16)
#define  TP_TP_ATSC_RING_CTRL_get_dring_full_en(data)                            ((0x00001000&(data))>>12)
#define  TP_TP_ATSC_RING_CTRL_get_dring_full(data)                               ((0x00000100&(data))>>8)
#define  TP_TP_ATSC_RING_CTRL_get_dring_available_en(data)                       ((0x00000010&(data))>>4)
#define  TP_TP_ATSC_RING_CTRL_get_dring_available(data)                          (0x00000001&(data))

#define  TP_TP_ATSC_CNT                                                          0x1801483C
#define  TP_TP_ATSC_CNT_reg_addr                                                 "0xB801483C"
#define  TP_TP_ATSC_CNT_reg                                                      0xB801483C
#define  TP_TP_ATSC_CNT_inst_addr                                                "0x00D9"
#define  set_TP_TP_ATSC_CNT_reg(data)                                            (*((volatile unsigned int*)TP_TP_ATSC_CNT_reg)=data)
#define  get_TP_TP_ATSC_CNT_reg                                                  (*((volatile unsigned int*)TP_TP_ATSC_CNT_reg))
#define  TP_TP_ATSC_CNT_cnt_shift                                                (0)
#define  TP_TP_ATSC_CNT_cnt_mask                                                 (0xFFFFFFFF)
#define  TP_TP_ATSC_CNT_cnt(data)                                                (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_CNT_get_cnt(data)                                            (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_ERR_CNT                                                      0x18014840
#define  TP_TP_ATSC_ERR_CNT_reg_addr                                             "0xB8014840"
#define  TP_TP_ATSC_ERR_CNT_reg                                                  0xB8014840
#define  TP_TP_ATSC_ERR_CNT_inst_addr                                            "0x00DA"
#define  set_TP_TP_ATSC_ERR_CNT_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_ERR_CNT_reg)=data)
#define  get_TP_TP_ATSC_ERR_CNT_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_ERR_CNT_reg))
#define  TP_TP_ATSC_ERR_CNT_err_cnt_shift                                        (0)
#define  TP_TP_ATSC_ERR_CNT_err_cnt_mask                                         (0xFFFFFFFF)
#define  TP_TP_ATSC_ERR_CNT_err_cnt(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_ERR_CNT_get_err_cnt(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_DRP_CNT                                                      0x18014844
#define  TP_TP_ATSC_DRP_CNT_reg_addr                                             "0xB8014844"
#define  TP_TP_ATSC_DRP_CNT_reg                                                  0xB8014844
#define  TP_TP_ATSC_DRP_CNT_inst_addr                                            "0x00DB"
#define  set_TP_TP_ATSC_DRP_CNT_reg(data)                                        (*((volatile unsigned int*)TP_TP_ATSC_DRP_CNT_reg)=data)
#define  get_TP_TP_ATSC_DRP_CNT_reg                                              (*((volatile unsigned int*)TP_TP_ATSC_DRP_CNT_reg))
#define  TP_TP_ATSC_DRP_CNT_drp_cnt_shift                                        (0)
#define  TP_TP_ATSC_DRP_CNT_drp_cnt_mask                                         (0xFFFFFFFF)
#define  TP_TP_ATSC_DRP_CNT_drp_cnt(data)                                        (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_DRP_CNT_get_drp_cnt(data)                                    (0xFFFFFFFF&(data))

#define  TP_TP_ATSC_DMY                                                          0x18014848
#define  TP_TP_ATSC_DMY_reg_addr                                                 "0xB8014848"
#define  TP_TP_ATSC_DMY_reg                                                      0xB8014848
#define  TP_TP_ATSC_DMY_inst_addr                                                "0x00DC"
#define  set_TP_TP_ATSC_DMY_reg(data)                                            (*((volatile unsigned int*)TP_TP_ATSC_DMY_reg)=data)
#define  get_TP_TP_ATSC_DMY_reg                                                  (*((volatile unsigned int*)TP_TP_ATSC_DMY_reg))
#define  TP_TP_ATSC_DMY_dmy_shift                                                (0)
#define  TP_TP_ATSC_DMY_dmy_mask                                                 (0xFFFFFFFF)
#define  TP_TP_ATSC_DMY_dmy(data)                                                (0xFFFFFFFF&(data))
#define  TP_TP_ATSC_DMY_get_dmy(data)                                            (0xFFFFFFFF&(data))

#define  TP_TP0_ERR_CNT_EN                                                       0x18014738
#define  TP_TP0_ERR_CNT_EN_reg_addr                                              "0xB8014738"
#define  TP_TP0_ERR_CNT_EN_reg                                                   0xB8014738
#define  TP_TP0_ERR_CNT_EN_inst_addr                                             "0x00DD"
#define  set_TP_TP0_ERR_CNT_EN_reg(data)                                         (*((volatile unsigned int*)TP_TP0_ERR_CNT_EN_reg)=data)
#define  get_TP_TP0_ERR_CNT_EN_reg                                               (*((volatile unsigned int*)TP_TP0_ERR_CNT_EN_reg))
#define  TP_TP0_ERR_CNT_EN_item11_shift                                          (10)
#define  TP_TP0_ERR_CNT_EN_item10_shift                                          (9)
#define  TP_TP0_ERR_CNT_EN_item9_shift                                           (8)
#define  TP_TP0_ERR_CNT_EN_item8_shift                                           (7)
#define  TP_TP0_ERR_CNT_EN_item7_shift                                           (6)
#define  TP_TP0_ERR_CNT_EN_item6_shift                                           (5)
#define  TP_TP0_ERR_CNT_EN_item5_shift                                           (4)
#define  TP_TP0_ERR_CNT_EN_item4_shift                                           (3)
#define  TP_TP0_ERR_CNT_EN_item3_shift                                           (2)
#define  TP_TP0_ERR_CNT_EN_item2_shift                                           (1)
#define  TP_TP0_ERR_CNT_EN_item1_shift                                           (0)
#define  TP_TP0_ERR_CNT_EN_item11_mask                                           (0x00000400)
#define  TP_TP0_ERR_CNT_EN_item10_mask                                           (0x00000200)
#define  TP_TP0_ERR_CNT_EN_item9_mask                                            (0x00000100)
#define  TP_TP0_ERR_CNT_EN_item8_mask                                            (0x00000080)
#define  TP_TP0_ERR_CNT_EN_item7_mask                                            (0x00000040)
#define  TP_TP0_ERR_CNT_EN_item6_mask                                            (0x00000020)
#define  TP_TP0_ERR_CNT_EN_item5_mask                                            (0x00000010)
#define  TP_TP0_ERR_CNT_EN_item4_mask                                            (0x00000008)
#define  TP_TP0_ERR_CNT_EN_item3_mask                                            (0x00000004)
#define  TP_TP0_ERR_CNT_EN_item2_mask                                            (0x00000002)
#define  TP_TP0_ERR_CNT_EN_item1_mask                                            (0x00000001)
#define  TP_TP0_ERR_CNT_EN_item11(data)                                          (0x00000400&((data)<<10))
#define  TP_TP0_ERR_CNT_EN_item10(data)                                          (0x00000200&((data)<<9))
#define  TP_TP0_ERR_CNT_EN_item9(data)                                           (0x00000100&((data)<<8))
#define  TP_TP0_ERR_CNT_EN_item8(data)                                           (0x00000080&((data)<<7))
#define  TP_TP0_ERR_CNT_EN_item7(data)                                           (0x00000040&((data)<<6))
#define  TP_TP0_ERR_CNT_EN_item6(data)                                           (0x00000020&((data)<<5))
#define  TP_TP0_ERR_CNT_EN_item5(data)                                           (0x00000010&((data)<<4))
#define  TP_TP0_ERR_CNT_EN_item4(data)                                           (0x00000008&((data)<<3))
#define  TP_TP0_ERR_CNT_EN_item3(data)                                           (0x00000004&((data)<<2))
#define  TP_TP0_ERR_CNT_EN_item2(data)                                           (0x00000002&((data)<<1))
#define  TP_TP0_ERR_CNT_EN_item1(data)                                           (0x00000001&(data))
#define  TP_TP0_ERR_CNT_EN_get_item11(data)                                      ((0x00000400&(data))>>10)
#define  TP_TP0_ERR_CNT_EN_get_item10(data)                                      ((0x00000200&(data))>>9)
#define  TP_TP0_ERR_CNT_EN_get_item9(data)                                       ((0x00000100&(data))>>8)
#define  TP_TP0_ERR_CNT_EN_get_item8(data)                                       ((0x00000080&(data))>>7)
#define  TP_TP0_ERR_CNT_EN_get_item7(data)                                       ((0x00000040&(data))>>6)
#define  TP_TP0_ERR_CNT_EN_get_item6(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP0_ERR_CNT_EN_get_item5(data)                                       ((0x00000010&(data))>>4)
#define  TP_TP0_ERR_CNT_EN_get_item4(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP0_ERR_CNT_EN_get_item3(data)                                       ((0x00000004&(data))>>2)
#define  TP_TP0_ERR_CNT_EN_get_item2(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP0_ERR_CNT_EN_get_item1(data)                                       (0x00000001&(data))

#define  TP_TP1_ERR_CNT_EN                                                       0x1801473C
#define  TP_TP1_ERR_CNT_EN_reg_addr                                              "0xB801473C"
#define  TP_TP1_ERR_CNT_EN_reg                                                   0xB801473C
#define  TP_TP1_ERR_CNT_EN_inst_addr                                             "0x00DE"
#define  set_TP_TP1_ERR_CNT_EN_reg(data)                                         (*((volatile unsigned int*)TP_TP1_ERR_CNT_EN_reg)=data)
#define  get_TP_TP1_ERR_CNT_EN_reg                                               (*((volatile unsigned int*)TP_TP1_ERR_CNT_EN_reg))
#define  TP_TP1_ERR_CNT_EN_item11_shift                                          (10)
#define  TP_TP1_ERR_CNT_EN_item10_shift                                          (9)
#define  TP_TP1_ERR_CNT_EN_item9_shift                                           (8)
#define  TP_TP1_ERR_CNT_EN_item8_shift                                           (7)
#define  TP_TP1_ERR_CNT_EN_item7_shift                                           (6)
#define  TP_TP1_ERR_CNT_EN_item6_shift                                           (5)
#define  TP_TP1_ERR_CNT_EN_item5_shift                                           (4)
#define  TP_TP1_ERR_CNT_EN_item4_shift                                           (3)
#define  TP_TP1_ERR_CNT_EN_item3_shift                                           (2)
#define  TP_TP1_ERR_CNT_EN_item2_shift                                           (1)
#define  TP_TP1_ERR_CNT_EN_item1_shift                                           (0)
#define  TP_TP1_ERR_CNT_EN_item11_mask                                           (0x00000400)
#define  TP_TP1_ERR_CNT_EN_item10_mask                                           (0x00000200)
#define  TP_TP1_ERR_CNT_EN_item9_mask                                            (0x00000100)
#define  TP_TP1_ERR_CNT_EN_item8_mask                                            (0x00000080)
#define  TP_TP1_ERR_CNT_EN_item7_mask                                            (0x00000040)
#define  TP_TP1_ERR_CNT_EN_item6_mask                                            (0x00000020)
#define  TP_TP1_ERR_CNT_EN_item5_mask                                            (0x00000010)
#define  TP_TP1_ERR_CNT_EN_item4_mask                                            (0x00000008)
#define  TP_TP1_ERR_CNT_EN_item3_mask                                            (0x00000004)
#define  TP_TP1_ERR_CNT_EN_item2_mask                                            (0x00000002)
#define  TP_TP1_ERR_CNT_EN_item1_mask                                            (0x00000001)
#define  TP_TP1_ERR_CNT_EN_item11(data)                                          (0x00000400&((data)<<10))
#define  TP_TP1_ERR_CNT_EN_item10(data)                                          (0x00000200&((data)<<9))
#define  TP_TP1_ERR_CNT_EN_item9(data)                                           (0x00000100&((data)<<8))
#define  TP_TP1_ERR_CNT_EN_item8(data)                                           (0x00000080&((data)<<7))
#define  TP_TP1_ERR_CNT_EN_item7(data)                                           (0x00000040&((data)<<6))
#define  TP_TP1_ERR_CNT_EN_item6(data)                                           (0x00000020&((data)<<5))
#define  TP_TP1_ERR_CNT_EN_item5(data)                                           (0x00000010&((data)<<4))
#define  TP_TP1_ERR_CNT_EN_item4(data)                                           (0x00000008&((data)<<3))
#define  TP_TP1_ERR_CNT_EN_item3(data)                                           (0x00000004&((data)<<2))
#define  TP_TP1_ERR_CNT_EN_item2(data)                                           (0x00000002&((data)<<1))
#define  TP_TP1_ERR_CNT_EN_item1(data)                                           (0x00000001&(data))
#define  TP_TP1_ERR_CNT_EN_get_item11(data)                                      ((0x00000400&(data))>>10)
#define  TP_TP1_ERR_CNT_EN_get_item10(data)                                      ((0x00000200&(data))>>9)
#define  TP_TP1_ERR_CNT_EN_get_item9(data)                                       ((0x00000100&(data))>>8)
#define  TP_TP1_ERR_CNT_EN_get_item8(data)                                       ((0x00000080&(data))>>7)
#define  TP_TP1_ERR_CNT_EN_get_item7(data)                                       ((0x00000040&(data))>>6)
#define  TP_TP1_ERR_CNT_EN_get_item6(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP1_ERR_CNT_EN_get_item5(data)                                       ((0x00000010&(data))>>4)
#define  TP_TP1_ERR_CNT_EN_get_item4(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP1_ERR_CNT_EN_get_item3(data)                                       ((0x00000004&(data))>>2)
#define  TP_TP1_ERR_CNT_EN_get_item2(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP1_ERR_CNT_EN_get_item1(data)                                       (0x00000001&(data))

#define  TP_TP2_ERR_CNT_EN                                                       0x18014740
#define  TP_TP2_ERR_CNT_EN_reg_addr                                              "0xB8014740"
#define  TP_TP2_ERR_CNT_EN_reg                                                   0xB8014740
#define  TP_TP2_ERR_CNT_EN_inst_addr                                             "0x00DF"
#define  set_TP_TP2_ERR_CNT_EN_reg(data)                                         (*((volatile unsigned int*)TP_TP2_ERR_CNT_EN_reg)=data)
#define  get_TP_TP2_ERR_CNT_EN_reg                                               (*((volatile unsigned int*)TP_TP2_ERR_CNT_EN_reg))
#define  TP_TP2_ERR_CNT_EN_item11_shift                                          (10)
#define  TP_TP2_ERR_CNT_EN_item10_shift                                          (9)
#define  TP_TP2_ERR_CNT_EN_item9_shift                                           (8)
#define  TP_TP2_ERR_CNT_EN_item8_shift                                           (7)
#define  TP_TP2_ERR_CNT_EN_item7_shift                                           (6)
#define  TP_TP2_ERR_CNT_EN_item6_shift                                           (5)
#define  TP_TP2_ERR_CNT_EN_item5_shift                                           (4)
#define  TP_TP2_ERR_CNT_EN_item4_shift                                           (3)
#define  TP_TP2_ERR_CNT_EN_item3_shift                                           (2)
#define  TP_TP2_ERR_CNT_EN_item2_shift                                           (1)
#define  TP_TP2_ERR_CNT_EN_item1_shift                                           (0)
#define  TP_TP2_ERR_CNT_EN_item11_mask                                           (0x00000400)
#define  TP_TP2_ERR_CNT_EN_item10_mask                                           (0x00000200)
#define  TP_TP2_ERR_CNT_EN_item9_mask                                            (0x00000100)
#define  TP_TP2_ERR_CNT_EN_item8_mask                                            (0x00000080)
#define  TP_TP2_ERR_CNT_EN_item7_mask                                            (0x00000040)
#define  TP_TP2_ERR_CNT_EN_item6_mask                                            (0x00000020)
#define  TP_TP2_ERR_CNT_EN_item5_mask                                            (0x00000010)
#define  TP_TP2_ERR_CNT_EN_item4_mask                                            (0x00000008)
#define  TP_TP2_ERR_CNT_EN_item3_mask                                            (0x00000004)
#define  TP_TP2_ERR_CNT_EN_item2_mask                                            (0x00000002)
#define  TP_TP2_ERR_CNT_EN_item1_mask                                            (0x00000001)
#define  TP_TP2_ERR_CNT_EN_item11(data)                                          (0x00000400&((data)<<10))
#define  TP_TP2_ERR_CNT_EN_item10(data)                                          (0x00000200&((data)<<9))
#define  TP_TP2_ERR_CNT_EN_item9(data)                                           (0x00000100&((data)<<8))
#define  TP_TP2_ERR_CNT_EN_item8(data)                                           (0x00000080&((data)<<7))
#define  TP_TP2_ERR_CNT_EN_item7(data)                                           (0x00000040&((data)<<6))
#define  TP_TP2_ERR_CNT_EN_item6(data)                                           (0x00000020&((data)<<5))
#define  TP_TP2_ERR_CNT_EN_item5(data)                                           (0x00000010&((data)<<4))
#define  TP_TP2_ERR_CNT_EN_item4(data)                                           (0x00000008&((data)<<3))
#define  TP_TP2_ERR_CNT_EN_item3(data)                                           (0x00000004&((data)<<2))
#define  TP_TP2_ERR_CNT_EN_item2(data)                                           (0x00000002&((data)<<1))
#define  TP_TP2_ERR_CNT_EN_item1(data)                                           (0x00000001&(data))
#define  TP_TP2_ERR_CNT_EN_get_item11(data)                                      ((0x00000400&(data))>>10)
#define  TP_TP2_ERR_CNT_EN_get_item10(data)                                      ((0x00000200&(data))>>9)
#define  TP_TP2_ERR_CNT_EN_get_item9(data)                                       ((0x00000100&(data))>>8)
#define  TP_TP2_ERR_CNT_EN_get_item8(data)                                       ((0x00000080&(data))>>7)
#define  TP_TP2_ERR_CNT_EN_get_item7(data)                                       ((0x00000040&(data))>>6)
#define  TP_TP2_ERR_CNT_EN_get_item6(data)                                       ((0x00000020&(data))>>5)
#define  TP_TP2_ERR_CNT_EN_get_item5(data)                                       ((0x00000010&(data))>>4)
#define  TP_TP2_ERR_CNT_EN_get_item4(data)                                       ((0x00000008&(data))>>3)
#define  TP_TP2_ERR_CNT_EN_get_item3(data)                                       ((0x00000004&(data))>>2)
#define  TP_TP2_ERR_CNT_EN_get_item2(data)                                       ((0x00000002&(data))>>1)
#define  TP_TP2_ERR_CNT_EN_get_item1(data)                                       (0x00000001&(data))

#define  TP_TP_PCRA_90K_CNT_HIGH                                                 0x18014F00
#define  TP_TP_PCRA_90K_CNT_HIGH_reg_addr                                        "0xB8014F00"
#define  TP_TP_PCRA_90K_CNT_HIGH_reg                                             0xB8014F00
#define  TP_TP_PCRA_90K_CNT_HIGH_inst_addr                                       "0x00E0"
#define  set_TP_TP_PCRA_90K_CNT_HIGH_reg(data)                                   (*((volatile unsigned int*)TP_TP_PCRA_90K_CNT_HIGH_reg)=data)
#define  get_TP_TP_PCRA_90K_CNT_HIGH_reg                                         (*((volatile unsigned int*)TP_TP_PCRA_90K_CNT_HIGH_reg))
#define  TP_TP_PCRA_90K_CNT_HIGH_pcra_90k_cnt_high_shift                         (0)
#define  TP_TP_PCRA_90K_CNT_HIGH_pcra_90k_cnt_high_mask                          (0xFFFFFFFF)
#define  TP_TP_PCRA_90K_CNT_HIGH_pcra_90k_cnt_high(data)                         (0xFFFFFFFF&(data))
#define  TP_TP_PCRA_90K_CNT_HIGH_get_pcra_90k_cnt_high(data)                     (0xFFFFFFFF&(data))

#define  TP_TP_PCRA_90K_CNT                                                      0x18014F04
#define  TP_TP_PCRA_90K_CNT_reg_addr                                             "0xB8014F04"
#define  TP_TP_PCRA_90K_CNT_reg                                                  0xB8014F04
#define  TP_TP_PCRA_90K_CNT_inst_addr                                            "0x00E1"
#define  set_TP_TP_PCRA_90K_CNT_reg(data)                                        (*((volatile unsigned int*)TP_TP_PCRA_90K_CNT_reg)=data)
#define  get_TP_TP_PCRA_90K_CNT_reg                                              (*((volatile unsigned int*)TP_TP_PCRA_90K_CNT_reg))
#define  TP_TP_PCRA_90K_CNT_pcra_90k_cnt_shift                                   (0)
#define  TP_TP_PCRA_90K_CNT_pcra_90k_cnt_mask                                    (0xFFFFFFFF)
#define  TP_TP_PCRA_90K_CNT_pcra_90k_cnt(data)                                   (0xFFFFFFFF&(data))
#define  TP_TP_PCRA_90K_CNT_get_pcra_90k_cnt(data)                               (0xFFFFFFFF&(data))

#define  TP_TP_PCRB_90K_CNT_HIGH                                                 0x18014F08
#define  TP_TP_PCRB_90K_CNT_HIGH_reg_addr                                        "0xB8014F08"
#define  TP_TP_PCRB_90K_CNT_HIGH_reg                                             0xB8014F08
#define  TP_TP_PCRB_90K_CNT_HIGH_inst_addr                                       "0x00E2"
#define  set_TP_TP_PCRB_90K_CNT_HIGH_reg(data)                                   (*((volatile unsigned int*)TP_TP_PCRB_90K_CNT_HIGH_reg)=data)
#define  get_TP_TP_PCRB_90K_CNT_HIGH_reg                                         (*((volatile unsigned int*)TP_TP_PCRB_90K_CNT_HIGH_reg))
#define  TP_TP_PCRB_90K_CNT_HIGH_pcrb_90k_cnt_high_shift                         (0)
#define  TP_TP_PCRB_90K_CNT_HIGH_pcrb_90k_cnt_high_mask                          (0xFFFFFFFF)
#define  TP_TP_PCRB_90K_CNT_HIGH_pcrb_90k_cnt_high(data)                         (0xFFFFFFFF&(data))
#define  TP_TP_PCRB_90K_CNT_HIGH_get_pcrb_90k_cnt_high(data)                     (0xFFFFFFFF&(data))

#define  TP_TP_PCRB_90K_CNT                                                      0x18014F0C
#define  TP_TP_PCRB_90K_CNT_reg_addr                                             "0xB8014F0C"
#define  TP_TP_PCRB_90K_CNT_reg                                                  0xB8014F0C
#define  TP_TP_PCRB_90K_CNT_inst_addr                                            "0x00E3"
#define  set_TP_TP_PCRB_90K_CNT_reg(data)                                        (*((volatile unsigned int*)TP_TP_PCRB_90K_CNT_reg)=data)
#define  get_TP_TP_PCRB_90K_CNT_reg                                              (*((volatile unsigned int*)TP_TP_PCRB_90K_CNT_reg))
#define  TP_TP_PCRB_90K_CNT_pcrb_90k_cnt_shift                                   (0)
#define  TP_TP_PCRB_90K_CNT_pcrb_90k_cnt_mask                                    (0xFFFFFFFF)
#define  TP_TP_PCRB_90K_CNT_pcrb_90k_cnt(data)                                   (0xFFFFFFFF&(data))
#define  TP_TP_PCRB_90K_CNT_get_pcrb_90k_cnt(data)                               (0xFFFFFFFF&(data))

#define  TP_TP_MISC_27M_CFG                                                      0x18014F10
#define  TP_TP_MISC_27M_CFG_reg_addr                                             "0xB8014F10"
#define  TP_TP_MISC_27M_CFG_reg                                                  0xB8014F10
#define  TP_TP_MISC_27M_CFG_inst_addr                                            "0x00E4"
#define  set_TP_TP_MISC_27M_CFG_reg(data)                                        (*((volatile unsigned int*)TP_TP_MISC_27M_CFG_reg)=data)
#define  get_TP_TP_MISC_27M_CFG_reg                                              (*((volatile unsigned int*)TP_TP_MISC_27M_CFG_reg))
#define  TP_TP_MISC_27M_CFG_av_sync_sel_shift                                    (20)
#define  TP_TP_MISC_27M_CFG_av_sync_enable_shift                                 (16)
#define  TP_TP_MISC_27M_CFG_fr_df_shift                                          (4)
#define  TP_TP_MISC_27M_CFG_fr_enable_shift                                      (0)
#define  TP_TP_MISC_27M_CFG_av_sync_sel_mask                                     (0x00100000)
#define  TP_TP_MISC_27M_CFG_av_sync_enable_mask                                  (0x00010000)
#define  TP_TP_MISC_27M_CFG_fr_df_mask                                           (0x0000FFF0)
#define  TP_TP_MISC_27M_CFG_fr_enable_mask                                       (0x00000001)
#define  TP_TP_MISC_27M_CFG_av_sync_sel(data)                                    (0x00100000&((data)<<20))
#define  TP_TP_MISC_27M_CFG_av_sync_enable(data)                                 (0x00010000&((data)<<16))
#define  TP_TP_MISC_27M_CFG_fr_df(data)                                          (0x0000FFF0&((data)<<4))
#define  TP_TP_MISC_27M_CFG_fr_enable(data)                                      (0x00000001&(data))
#define  TP_TP_MISC_27M_CFG_get_av_sync_sel(data)                                ((0x00100000&(data))>>20)
#define  TP_TP_MISC_27M_CFG_get_av_sync_enable(data)                             ((0x00010000&(data))>>16)
#define  TP_TP_MISC_27M_CFG_get_fr_df(data)                                      ((0x0000FFF0&(data))>>4)
#define  TP_TP_MISC_27M_CFG_get_fr_enable(data)                                  (0x00000001&(data))

#define  TP_TP_MISC_27M_CTRL                                                     0x18014F14
#define  TP_TP_MISC_27M_CTRL_reg_addr                                            "0xB8014F14"
#define  TP_TP_MISC_27M_CTRL_reg                                                 0xB8014F14
#define  TP_TP_MISC_27M_CTRL_inst_addr                                           "0x00E5"
#define  set_TP_TP_MISC_27M_CTRL_reg(data)                                       (*((volatile unsigned int*)TP_TP_MISC_27M_CTRL_reg)=data)
#define  get_TP_TP_MISC_27M_CTRL_reg                                             (*((volatile unsigned int*)TP_TP_MISC_27M_CTRL_reg))
#define  TP_TP_MISC_27M_CTRL_latch_shift                                         (4)
#define  TP_TP_MISC_27M_CTRL_rst_shift                                           (0)
#define  TP_TP_MISC_27M_CTRL_latch_mask                                          (0x00000010)
#define  TP_TP_MISC_27M_CTRL_rst_mask                                            (0x00000001)
#define  TP_TP_MISC_27M_CTRL_latch(data)                                         (0x00000010&((data)<<4))
#define  TP_TP_MISC_27M_CTRL_rst(data)                                           (0x00000001&(data))
#define  TP_TP_MISC_27M_CTRL_get_latch(data)                                     ((0x00000010&(data))>>4)
#define  TP_TP_MISC_27M_CTRL_get_rst(data)                                       (0x00000001&(data))

#define  TP_TP_MISC_27M_CNT_HIGH                                                 0x18014F18
#define  TP_TP_MISC_27M_CNT_HIGH_reg_addr                                        "0xB8014F18"
#define  TP_TP_MISC_27M_CNT_HIGH_reg                                             0xB8014F18
#define  TP_TP_MISC_27M_CNT_HIGH_inst_addr                                       "0x00E6"
#define  set_TP_TP_MISC_27M_CNT_HIGH_reg(data)                                   (*((volatile unsigned int*)TP_TP_MISC_27M_CNT_HIGH_reg)=data)
#define  get_TP_TP_MISC_27M_CNT_HIGH_reg                                         (*((volatile unsigned int*)TP_TP_MISC_27M_CNT_HIGH_reg))
#define  TP_TP_MISC_27M_CNT_HIGH_tp_misc_27m_cnt_high_shift                      (0)
#define  TP_TP_MISC_27M_CNT_HIGH_tp_misc_27m_cnt_high_mask                       (0xFFFFFFFF)
#define  TP_TP_MISC_27M_CNT_HIGH_tp_misc_27m_cnt_high(data)                      (0xFFFFFFFF&(data))
#define  TP_TP_MISC_27M_CNT_HIGH_get_tp_misc_27m_cnt_high(data)                  (0xFFFFFFFF&(data))

#define  TP_TP_MISC_27M_CNT                                                      0x18014F1C
#define  TP_TP_MISC_27M_CNT_reg_addr                                             "0xB8014F1C"
#define  TP_TP_MISC_27M_CNT_reg                                                  0xB8014F1C
#define  TP_TP_MISC_27M_CNT_inst_addr                                            "0x00E7"
#define  set_TP_TP_MISC_27M_CNT_reg(data)                                        (*((volatile unsigned int*)TP_TP_MISC_27M_CNT_reg)=data)
#define  get_TP_TP_MISC_27M_CNT_reg                                              (*((volatile unsigned int*)TP_TP_MISC_27M_CNT_reg))
#define  TP_TP_MISC_27M_CNT_tp_misc_27m_cnt_shift                                (0)
#define  TP_TP_MISC_27M_CNT_tp_misc_27m_cnt_mask                                 (0xFFFFFFFF)
#define  TP_TP_MISC_27M_CNT_tp_misc_27m_cnt(data)                                (0xFFFFFFFF&(data))
#define  TP_TP_MISC_27M_CNT_get_tp_misc_27m_cnt(data)                            (0xFFFFFFFF&(data))

#define  TP_TP_AVSYNC_CNT_HIGH                                                   0x18014F20
#define  TP_TP_AVSYNC_CNT_HIGH_reg_addr                                          "0xB8014F20"
#define  TP_TP_AVSYNC_CNT_HIGH_reg                                               0xB8014F20
#define  TP_TP_AVSYNC_CNT_HIGH_inst_addr                                         "0x00E8"
#define  set_TP_TP_AVSYNC_CNT_HIGH_reg(data)                                     (*((volatile unsigned int*)TP_TP_AVSYNC_CNT_HIGH_reg)=data)
#define  get_TP_TP_AVSYNC_CNT_HIGH_reg                                           (*((volatile unsigned int*)TP_TP_AVSYNC_CNT_HIGH_reg))
#define  TP_TP_AVSYNC_CNT_HIGH_tp_avsync_cnt_high_shift                          (0)
#define  TP_TP_AVSYNC_CNT_HIGH_tp_avsync_cnt_high_mask                           (0xFFFFFFFF)
#define  TP_TP_AVSYNC_CNT_HIGH_tp_avsync_cnt_high(data)                          (0xFFFFFFFF&(data))
#define  TP_TP_AVSYNC_CNT_HIGH_get_tp_avsync_cnt_high(data)                      (0xFFFFFFFF&(data))

#define  TP_TP_AVSYNC_CNT                                                        0x18014F24
#define  TP_TP_AVSYNC_CNT_reg_addr                                               "0xB8014F24"
#define  TP_TP_AVSYNC_CNT_reg                                                    0xB8014F24
#define  TP_TP_AVSYNC_CNT_inst_addr                                              "0x00E9"
#define  set_TP_TP_AVSYNC_CNT_reg(data)                                          (*((volatile unsigned int*)TP_TP_AVSYNC_CNT_reg)=data)
#define  get_TP_TP_AVSYNC_CNT_reg                                                (*((volatile unsigned int*)TP_TP_AVSYNC_CNT_reg))
#define  TP_TP_AVSYNC_CNT_tp_avsync_cnt_shift                                    (0)
#define  TP_TP_AVSYNC_CNT_tp_avsync_cnt_mask                                     (0xFFFFFFFF)
#define  TP_TP_AVSYNC_CNT_tp_avsync_cnt(data)                                    (0xFFFFFFFF&(data))
#define  TP_TP_AVSYNC_CNT_get_tp_avsync_cnt(data)                                (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf0_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf0_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf0_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf0_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf0_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set00:1;
    };
}tp_tp_tf0_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf0_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf0_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_cnt:16;
    };
}tp_tp_tf0_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf0_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf0_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf0_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf1_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf1_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf1_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf1_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf1_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set00:1;
    };
}tp_tp_tf1_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf1_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf1_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_cnt:16;
    };
}tp_tp_tf1_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf1_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf1_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf1_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf2_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf2_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf2_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf2_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set00:1;
    };
}tp_tp_tf2_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf2_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf2_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_cnt:16;
    };
}tp_tp_tf2_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf2_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf2_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf2_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf3_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf3_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf3_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf3_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set3:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set0:8;
    };
}tp_tp_tf3_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set00:1;
    };
}tp_tp_tf3_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf3_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf3_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  err_cnt:16;
    };
}tp_tp_tf3_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf3_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf3_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf3_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  in_tpp_out_en:1;
        RBus_UInt32  in_tp_out_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  in_tp_rst:1;
        RBus_UInt32  data_src:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  in_data_order:1;
        RBus_UInt32  in_serial:1;
        RBus_UInt32  in_datapin:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  in_sync_pol:1;
        RBus_UInt32  in_val_pol:1;
        RBus_UInt32  in_clk_pol:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  out_data_order:1;
        RBus_UInt32  out_serial:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  out_sync_pol:1;
        RBus_UInt32  out_val_pol:1;
        RBus_UInt32  out_clk_pol:1;
    };
}tp_tp_tf_out_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  share_mode:1;
        RBus_UInt32  out_share_en:1;
        RBus_UInt32  out_stop_mode:1;
        RBus_UInt32  get_size:2;
        RBus_UInt32  sync_dur:1;
        RBus_UInt32  ck_gate:1;
        RBus_UInt32  tp_frame_rate:13;
        RBus_UInt32  data_sel:1;
        RBus_UInt32  res2:4;
    };
}tp_tp_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pause_int:1;
        RBus_UInt32  pause_int_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_out_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf_th:32;
    };
}tp_tp_out_share_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf_space:32;
    };
}tp_tp_out_share_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_out:32;
    };
}tp_tp_out_share_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  tpi_demod_val_pol:1;
        RBus_UInt32  tpi_demod_sync_pol:1;
        RBus_UInt32  tpi_demod_clk_pol:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tpi_2_val_pol:1;
        RBus_UInt32  tpi_2_sync_pol:1;
        RBus_UInt32  tpi_2_clk_pol:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  tpi_1_val_pol:1;
        RBus_UInt32  tpi_1_sync_pol:1;
        RBus_UInt32  tpi_1_clk_pol:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  tpi_0_val_pol:1;
        RBus_UInt32  tpi_0_sync_pol:1;
        RBus_UInt32  tpi_0_clk_pol:1;
    };
}tp_tp_in_pol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  pcra_src_sel:1;
        RBus_UInt32  extra_pid_addr:7;
    };
}tp_tp0_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  extra_pid_addr:7;
    };
}tp_tp1_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  extra_pid_addr:7;
    };
}tp_tp2_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  extra_pid_addr:7;
    };
}tp_tp3_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  latch_ena:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  latch_sel:2;
    };
}tp_tp_pcr_latch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_base_lo:32;
    };
}tp_tp_pcr_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  pcr_base_hi:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  pcr_ext:9;
    };
}tp_tp_pcr_ext_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  system_ts:32;
    };
}tp_tp_pcr_system_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp3:8;
        RBus_UInt32  tp2:8;
        RBus_UInt32  tp1:8;
        RBus_UInt32  tp0:8;
    };
}tp_tp_sync_rplace_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  partition1:8;
        RBus_UInt32  partition2:8;
        RBus_UInt32  partition3:8;
    };
}tp_tp_pid_part_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  r_w:1;
        RBus_UInt32  idx:7;
    };
}tp_tp_pid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  si_en:1;
        RBus_UInt32  pid_ini:1;
        RBus_UInt32  ai_en:1;
        RBus_UInt32  ti_en:1;
        RBus_UInt32  sec_idx:8;
        RBus_UInt32  sec_en:1;
        RBus_UInt32  ddr_q:5;
        RBus_UInt32  v:1;
        RBus_UInt32  pid:13;
    };
}tp_tp_pid_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  des_sel:3;
        RBus_UInt32  aes_mode:2;
        RBus_UInt32  tdes_mode:1;
        RBus_UInt32  encrypt_tsc_en:1;
        RBus_UInt32  encryption_key:1;
        RBus_UInt32  keyindex:6;
        RBus_UInt32  local_des_en:1;
        RBus_UInt32  descramble_sel:1;
        RBus_UInt32  pid_des_disable:1;
        RBus_UInt32  encryption_en:1;
        RBus_UInt32  info_q_en:1;
        RBus_UInt32  pre_des:1;
        RBus_UInt32  key:5;
        RBus_UInt32  cc_en:1;
        RBus_UInt32  ddr_q_en:1;
        RBus_UInt32  info_q:5;
    };
}tp_tp_pid_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  round:8;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  mode:3;
    };
}tp_tp_pid_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  r_w:1;
        RBus_UInt32  idx:8;
    };
}tp_tp_sec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_msb:32;
    };
}tp_tp_sec_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_lsb:32;
    };
}tp_tp_sec_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_msb:32;
    };
}tp_tp_sec_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_lsb:32;
    };
}tp_tp_sec_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sp_filter:2;
        RBus_UInt32  sp_mask:2;
        RBus_UInt32  crc_en:1;
        RBus_UInt32  p_d:1;
        RBus_UInt32  p_n:1;
        RBus_UInt32  last:1;
        RBus_UInt32  next_sec:8;
    };
}tp_tp_sec_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_msb:32;
    };
}tp_tp_sec_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_lsb:32;
    };
}tp_tp_sec_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_msb:32;
    };
}tp_tp_sec_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_lsb:32;
    };
}tp_tp_sec_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  neg_sp_filter:2;
        RBus_UInt32  neg_sp_mask:2;
        RBus_UInt32  res2:8;
        RBus_UInt32  filter_sel:2;
    };
}tp_tp_sec_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  round:8;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  mode:3;
    };
}tp_tp_tp0_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key_info:32;
    };
}tp_tp_key_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  r_w:1;
        RBus_UInt32  idx:7;
    };
}tp_tp_key_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  round:8;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  mode:3;
    };
}tp_tp_tp1_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  round:8;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  mode:3;
    };
}tp_tp_tp2_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_init:32;
    };
}tp_tp_crc_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  threshold:29;
    };
}tp_tp_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fullness:29;
    };
}tp_tp_fullness_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  wm:4;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  idx:5;
    };
}tp_tp_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_avail_15:1;
        RBus_UInt32  ring_avail_14:1;
        RBus_UInt32  ring_avail_13:1;
        RBus_UInt32  ring_avail_12:1;
        RBus_UInt32  ring_avail_11:1;
        RBus_UInt32  ring_avail_10:1;
        RBus_UInt32  ring_avail_9:1;
        RBus_UInt32  ring_avail_8:1;
        RBus_UInt32  ring_avail_7:1;
        RBus_UInt32  ring_avail_6:1;
        RBus_UInt32  ring_avail_5:1;
        RBus_UInt32  ring_avail_4:1;
        RBus_UInt32  ring_avail_3:1;
        RBus_UInt32  ring_avail_2:1;
        RBus_UInt32  ring_avail_1:1;
        RBus_UInt32  ring_avail_0:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_ring_avail_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_full_15:1;
        RBus_UInt32  ring_full_14:1;
        RBus_UInt32  ring_full_13:1;
        RBus_UInt32  ring_full_12:1;
        RBus_UInt32  ring_full_11:1;
        RBus_UInt32  ring_full_10:1;
        RBus_UInt32  ring_full_9:1;
        RBus_UInt32  ring_full_8:1;
        RBus_UInt32  ring_full_7:1;
        RBus_UInt32  ring_full_6:1;
        RBus_UInt32  ring_full_5:1;
        RBus_UInt32  ring_full_4:1;
        RBus_UInt32  ring_full_3:1;
        RBus_UInt32  ring_full_2:1;
        RBus_UInt32  ring_full_1:1;
        RBus_UInt32  ring_full_0:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_ring_full_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_avail_15_en:1;
        RBus_UInt32  ring_avail_14_en:1;
        RBus_UInt32  ring_avail_13_en:1;
        RBus_UInt32  ring_avail_12_en:1;
        RBus_UInt32  ring_avail_11_en:1;
        RBus_UInt32  ring_avail_10_en:1;
        RBus_UInt32  ring_avail_9_en:1;
        RBus_UInt32  ring_avail_8_en:1;
        RBus_UInt32  ring_avail_7_en:1;
        RBus_UInt32  ring_avail_6_en:1;
        RBus_UInt32  ring_avail_5_en:1;
        RBus_UInt32  ring_avail_4_en:1;
        RBus_UInt32  ring_avail_3_en:1;
        RBus_UInt32  ring_avail_2_en:1;
        RBus_UInt32  ring_avail_1_en:1;
        RBus_UInt32  ring_avail_0_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_ring_avail_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  ring_full_15_en:1;
        RBus_UInt32  ring_full_14_en:1;
        RBus_UInt32  ring_full_13_en:1;
        RBus_UInt32  ring_full_12_en:1;
        RBus_UInt32  ring_full_11_en:1;
        RBus_UInt32  ring_full_10_en:1;
        RBus_UInt32  ring_full_9_en:1;
        RBus_UInt32  ring_full_8_en:1;
        RBus_UInt32  ring_full_7_en:1;
        RBus_UInt32  ring_full_6_en:1;
        RBus_UInt32  ring_full_5_en:1;
        RBus_UInt32  ring_full_4_en:1;
        RBus_UInt32  ring_full_3_en:1;
        RBus_UInt32  ring_full_2_en:1;
        RBus_UInt32  ring_full_1_en:1;
        RBus_UInt32  ring_full_0_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_ring_full_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_pos:32;
    };
}tp_tp_sync_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_tp_dmy_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_tp_dmy_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ls:1;
        RBus_UInt32  bist_mode_tp:1;
    };
}tp_tp_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done_tp:1;
    };
}tp_tp_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tp_bist_fail_group_tp:1;
    };
}tp_tp_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  atsc_dma:1;
        RBus_UInt32  tp_dma_4:1;
        RBus_UInt32  tp_dma_0:1;
        RBus_UInt32  tp_dma_1:1;
        RBus_UInt32  tp_dma_2:1;
        RBus_UInt32  tp_dma_3:1;
        RBus_UInt32  tpp_dma_0:1;
        RBus_UInt32  tpp_dma_1:1;
        RBus_UInt32  tpp_dma_2:1;
        RBus_UInt32  tpp_dma_3:1;
        RBus_UInt32  ring:1;
        RBus_UInt32  pid:1;
        RBus_UInt32  sect:1;
        RBus_UInt32  key:1;
    };
}tp_tp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_mode_tp:1;
    };
}tp_tp_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resume_tp:1;
    };
}tp_tp_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_done_tp:1;
    };
}tp_tp_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pause_tp:1;
    };
}tp_tp_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_fail_group_tp:1;
    };
}tp_tp_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  atsc_dma:1;
        RBus_UInt32  tp_dma_4:1;
        RBus_UInt32  tp_dma_0:1;
        RBus_UInt32  tp_dma_1:1;
        RBus_UInt32  tp_dma_2:1;
        RBus_UInt32  tp_dma_3:1;
        RBus_UInt32  tpp_dma_0:1;
        RBus_UInt32  tpp_dma_1:1;
        RBus_UInt32  tpp_dma_2:1;
        RBus_UInt32  tpp_dma_3:1;
        RBus_UInt32  ring:1;
        RBus_UInt32  pid:1;
        RBus_UInt32  sect:1;
        RBus_UInt32  key:1;
    };
}tp_tp_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  atsc_dma:1;
        RBus_UInt32  tp_dma_4:1;
        RBus_UInt32  tp_dma_0:1;
        RBus_UInt32  tp_dma_1:1;
        RBus_UInt32  tp_dma_2:1;
        RBus_UInt32  tp_dma_3:1;
        RBus_UInt32  tpp_dma_0:1;
        RBus_UInt32  tpp_dma_1:1;
        RBus_UInt32  tpp_dma_2:1;
        RBus_UInt32  tpp_dma_3:1;
        RBus_UInt32  ring:1;
        RBus_UInt32  pid:1;
        RBus_UInt32  sect:1;
        RBus_UInt32  key:1;
    };
}tp_tp_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tpp_dma_0:4;
        RBus_UInt32  tpp_dma_1:4;
        RBus_UInt32  tpp_dma_2:4;
        RBus_UInt32  tpp_dma_3:4;
        RBus_UInt32  ring:4;
        RBus_UInt32  pid:4;
        RBus_UInt32  sect:4;
        RBus_UInt32  key:4;
    };
}tp_tp_bist_dvs_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  atsc_dma:4;
        RBus_UInt32  tp_dma_4:4;
        RBus_UInt32  tpp_dma_0:4;
        RBus_UInt32  tpp_dma_1:4;
        RBus_UInt32  tpp_dma_2:4;
        RBus_UInt32  tpp_dma_3:4;
    };
}tp_tp_bist_dvs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  dv_verify_only:1;
        RBus_UInt32  tp_sram_sleep_off:1;
        RBus_UInt32  tp_pkt_sram_addr_rst_sel:1;
        RBus_UInt32  dbg_mode:5;
    };
}tp_tp_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  m2tp_st:2;
        RBus_UInt32  mtp_st:3;
        RBus_UInt32  m2tp_p_st:2;
        RBus_UInt32  mtp_p_st:2;
        RBus_UInt32  tpp0_st:2;
        RBus_UInt32  tp0_st:2;
        RBus_UInt32  tpp0_m2m_st:3;
        RBus_UInt32  tp0_m2m_st:3;
        RBus_UInt32  dma_st:6;
        RBus_UInt32  dma_p_st:6;
    };
}tp_tp_debug_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_port:32;
    };
}tp_tp_debug_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp0_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp0_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp0_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp0_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp0_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp1_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp1_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp1_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp1_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp1_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp2_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp2_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp2_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp2_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp2_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp3_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp3_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp3_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp3_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp3_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp0_p_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp0_p_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp0_p_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp0_p_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp0_p_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp1_p_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp1_p_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp1_p_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp1_p_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp1_p_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp2_p_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp2_p_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp2_p_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp2_p_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  empty:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp2_p_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf0_p_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf0_p_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf0_p_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf0_p_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf0_p_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf0_p_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf1_p_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf1_p_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf1_p_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf1_p_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf1_p_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf1_p_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  two_bit:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf2_p_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt:24;
    };
}tp_tp_tf2_p_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drp_cnt:16;
    };
}tp_tp_tf2_p_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  dropno:4;
        RBus_UInt32  lockno:4;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  data_order:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  serial:1;
        RBus_UInt32  datapin:1;
        RBus_UInt32  res1:4;
    };
}tp_tp_tf2_p_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf2_p_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_tf2_p_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  threshold:29;
    };
}tp_tp_p_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fullness:29;
    };
}tp_tp_p_fullness_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  wm:4;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  idx:2;
    };
}tp_tp_p_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_p_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_p_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_p_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_p_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ring_avail_2:1;
        RBus_UInt32  ring_avail_1:1;
        RBus_UInt32  ring_avail_0:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_p_ring_avail_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ring_full_2:1;
        RBus_UInt32  ring_full_1:1;
        RBus_UInt32  ring_full_0:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_p_ring_full_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ring_avail_2_en:1;
        RBus_UInt32  ring_avail_1_en:1;
        RBus_UInt32  ring_avail_0_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_p_ring_avail_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  ring_full_2_en:1;
        RBus_UInt32  ring_full_1_en:1;
        RBus_UInt32  ring_full_0_en:1;
        RBus_UInt32  write_data:1;
    };
}tp_tp_p_ring_full_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tp2:8;
        RBus_UInt32  tp1:8;
        RBus_UInt32  tp0:8;
    };
}tp_tp_p_sync_rplace_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  tp3_keep:1;
        RBus_UInt32  tp0_keep:1;
        RBus_UInt32  tp1_keep:1;
        RBus_UInt32  tp2_keep:1;
        RBus_UInt32  tp3_sel:2;
        RBus_UInt32  tp0_sel:2;
        RBus_UInt32  tp1_sel:2;
        RBus_UInt32  tp2_sel:2;
    };
}tp_prefix_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  meta:32;
    };
}tp_prefix_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg01:32;
    };
}tp_prefix_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg02:32;
    };
}tp_prefix_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  tp3_en:1;
        RBus_UInt32  tp3_rate:3;
        RBus_UInt32  tp2_en:1;
        RBus_UInt32  tp2_rate:3;
        RBus_UInt32  tp1_en:1;
        RBus_UInt32  tp1_rate:3;
        RBus_UInt32  tp0_en:1;
        RBus_UInt32  tp0_rate:3;
    };
}tp_fr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  req_level:5;
        RBus_UInt32  dma_flush:1;
        RBus_UInt32  en:1;
        RBus_UInt32  pattern:24;
    };
}tp_start_code_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  req_level:5;
        RBus_UInt32  dma_flush:1;
        RBus_UInt32  en:1;
        RBus_UInt32  pattern:24;
    };
}tp_start_code_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fifo_cnt:7;
        RBus_UInt32  res2:5;
        RBus_UInt32  sw_rst:1;
        RBus_UInt32  info_q:5;
        RBus_UInt32  pid:13;
    };
}tp_start_code_ctrl_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fifo_cnt:7;
        RBus_UInt32  res2:5;
        RBus_UInt32  sw_rst:1;
        RBus_UInt32  info_q:5;
        RBus_UInt32  pid:13;
    };
}tp_start_code_ctrl_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wp:32;
    };
}tp_start_code_wp_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wp:32;
    };
}tp_start_code_wp_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sw_rst:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_endian:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  data_location:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  data_reverse:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  data_mode:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  protocol:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  src_sel:2;
        RBus_UInt32  res8:3;
        RBus_UInt32  en:1;
    };
}tp_tp_atsc_src_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_byte:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  dmy_discard:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  length_err_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  err_en:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  oif_header_length:8;
        RBus_UInt32  res4:3;
        RBus_UInt32  hw_auto_mode:1;
    };
}tp_tp_atsc_config1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  starter:32;
    };
}tp_tp_atsc_config2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  oif_length_offset:16;
    };
}tp_tp_atsc_config3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plp_idx31_en:1;
        RBus_UInt32  plp_idx30_en:1;
        RBus_UInt32  plp_idx29_en:1;
        RBus_UInt32  plp_idx28_en:1;
        RBus_UInt32  plp_idx27_en:1;
        RBus_UInt32  plp_idx26_en:1;
        RBus_UInt32  plp_idx25_en:1;
        RBus_UInt32  plp_idx24_en:1;
        RBus_UInt32  plp_idx23_en:1;
        RBus_UInt32  plp_idx22_en:1;
        RBus_UInt32  plp_idx21_en:1;
        RBus_UInt32  plp_idx20_en:1;
        RBus_UInt32  plp_idx19_en:1;
        RBus_UInt32  plp_idx18_en:1;
        RBus_UInt32  plp_idx17_en:1;
        RBus_UInt32  plp_idx16_en:1;
        RBus_UInt32  plp_idx15_en:1;
        RBus_UInt32  plp_idx14_en:1;
        RBus_UInt32  plp_idx13_en:1;
        RBus_UInt32  plp_idx12_en:1;
        RBus_UInt32  plp_idx11_en:1;
        RBus_UInt32  plp_idx10_en:1;
        RBus_UInt32  plp_idx9_en:1;
        RBus_UInt32  plp_idx8_en:1;
        RBus_UInt32  plp_idx7_en:1;
        RBus_UInt32  plp_idx6_en:1;
        RBus_UInt32  plp_idx5_en:1;
        RBus_UInt32  plp_idx4_en:1;
        RBus_UInt32  plp_idx3_en:1;
        RBus_UInt32  plp_idx2_en:1;
        RBus_UInt32  plp_idx1_en:1;
        RBus_UInt32  plp_idx0_en:1;
    };
}tp_tp_atsc_plp_filter1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plp_idx63_en:1;
        RBus_UInt32  plp_idx62_en:1;
        RBus_UInt32  plp_idx61_en:1;
        RBus_UInt32  plp_idx60_en:1;
        RBus_UInt32  plp_idx59_en:1;
        RBus_UInt32  plp_idx58_en:1;
        RBus_UInt32  plp_idx57_en:1;
        RBus_UInt32  plp_idx56_en:1;
        RBus_UInt32  plp_idx55_en:1;
        RBus_UInt32  plp_idx54_en:1;
        RBus_UInt32  plp_idx53_en:1;
        RBus_UInt32  plp_idx52_en:1;
        RBus_UInt32  plp_idx51_en:1;
        RBus_UInt32  plp_idx50_en:1;
        RBus_UInt32  plp_idx49_en:1;
        RBus_UInt32  plp_idx48_en:1;
        RBus_UInt32  plp_idx47_en:1;
        RBus_UInt32  plp_idx46_en:1;
        RBus_UInt32  plp_idx45_en:1;
        RBus_UInt32  plp_idx44_en:1;
        RBus_UInt32  plp_idx43_en:1;
        RBus_UInt32  plp_idx42_en:1;
        RBus_UInt32  plp_idx41_en:1;
        RBus_UInt32  plp_idx40_en:1;
        RBus_UInt32  plp_idx39_en:1;
        RBus_UInt32  plp_idx38_en:1;
        RBus_UInt32  plp_idx37_en:1;
        RBus_UInt32  plp_idx36_en:1;
        RBus_UInt32  plp_idx35_en:1;
        RBus_UInt32  plp_idx34_en:1;
        RBus_UInt32  plp_idx33_en:1;
        RBus_UInt32  plp_idx32_en:1;
    };
}tp_tp_atsc_plp_filter2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_atsc_d_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_atsc_d_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_atsc_d_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_atsc_d_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_limit:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_atsc_i_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_base:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_atsc_i_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_atsc_i_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_atsc_i_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  iring_full_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  iring_full:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  iring_available_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  iring_available:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  dring_full_en:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  dring_full:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  dring_available_en:1;
        RBus_UInt32  res8:3;
        RBus_UInt32  dring_available:1;
    };
}tp_tp_atsc_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_tp_atsc_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:32;
    };
}tp_tp_atsc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:32;
    };
}tp_tp_atsc_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_tp_atsc_dmy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  item11:1;
        RBus_UInt32  item10:1;
        RBus_UInt32  item9:1;
        RBus_UInt32  item8:1;
        RBus_UInt32  item7:1;
        RBus_UInt32  item6:1;
        RBus_UInt32  item5:1;
        RBus_UInt32  item4:1;
        RBus_UInt32  item3:1;
        RBus_UInt32  item2:1;
        RBus_UInt32  item1:1;
    };
}tp_tp0_err_cnt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  item11:1;
        RBus_UInt32  item10:1;
        RBus_UInt32  item9:1;
        RBus_UInt32  item8:1;
        RBus_UInt32  item7:1;
        RBus_UInt32  item6:1;
        RBus_UInt32  item5:1;
        RBus_UInt32  item4:1;
        RBus_UInt32  item3:1;
        RBus_UInt32  item2:1;
        RBus_UInt32  item1:1;
    };
}tp_tp1_err_cnt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  item11:1;
        RBus_UInt32  item10:1;
        RBus_UInt32  item9:1;
        RBus_UInt32  item8:1;
        RBus_UInt32  item7:1;
        RBus_UInt32  item6:1;
        RBus_UInt32  item5:1;
        RBus_UInt32  item4:1;
        RBus_UInt32  item3:1;
        RBus_UInt32  item2:1;
        RBus_UInt32  item1:1;
    };
}tp_tp2_err_cnt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcra_90k_cnt_high:32;
    };
}tp_tp_pcra_90k_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcra_90k_cnt:32;
    };
}tp_tp_pcra_90k_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcrb_90k_cnt_high:32;
    };
}tp_tp_pcrb_90k_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcrb_90k_cnt:32;
    };
}tp_tp_pcrb_90k_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  av_sync_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  av_sync_enable:1;
        RBus_UInt32  fr_df:12;
        RBus_UInt32  res3:3;
        RBus_UInt32  fr_enable:1;
    };
}tp_tp_misc_27m_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  latch:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rst:1;
    };
}tp_tp_misc_27m_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_misc_27m_cnt_high:32;
    };
}tp_tp_misc_27m_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_misc_27m_cnt:32;
    };
}tp_tp_misc_27m_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_avsync_cnt_high:32;
    };
}tp_tp_avsync_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_avsync_cnt:32;
    };
}tp_tp_avsync_cnt_RBUS;

#else //apply LITTLE_ENDIAN

//======TP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf0_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf0_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf0_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf0_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf0_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  val_set00:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf0_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf0_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf0_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf0_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf0_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf0_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf0_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf1_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf1_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf1_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf1_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf1_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  val_set00:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf1_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf1_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf1_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf1_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf1_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf1_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf1_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf2_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf2_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf2_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf2_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf2_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  val_set00:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf2_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf2_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf2_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf2_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf2_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf2_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf2_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf3_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf3_strm_id_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf3_strm_id_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf3_strm_id_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set0:8;
        RBus_UInt32  set1:8;
        RBus_UInt32  set2:8;
        RBus_UInt32  set3:8;
    };
}tp_tp_tf3_strm_id_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  val_set00:1;
        RBus_UInt32  val_set01:1;
        RBus_UInt32  val_set02:1;
        RBus_UInt32  val_set03:1;
        RBus_UInt32  val_set10:1;
        RBus_UInt32  val_set11:1;
        RBus_UInt32  val_set12:1;
        RBus_UInt32  val_set13:1;
        RBus_UInt32  val_set20:1;
        RBus_UInt32  val_set21:1;
        RBus_UInt32  val_set22:1;
        RBus_UInt32  val_set23:1;
        RBus_UInt32  val_set30:1;
        RBus_UInt32  val_set31:1;
        RBus_UInt32  val_set32:1;
        RBus_UInt32  val_set33:1;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf3_strm_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf3_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf3_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf3_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf3_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf3_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf3_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out_clk_pol:1;
        RBus_UInt32  out_val_pol:1;
        RBus_UInt32  out_sync_pol:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  out_serial:1;
        RBus_UInt32  out_data_order:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  in_clk_pol:1;
        RBus_UInt32  in_val_pol:1;
        RBus_UInt32  in_sync_pol:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  in_datapin:1;
        RBus_UInt32  in_serial:1;
        RBus_UInt32  in_data_order:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  data_src:3;
        RBus_UInt32  in_tp_rst:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  in_tp_out_en:1;
        RBus_UInt32  in_tpp_out_en:1;
        RBus_UInt32  res6:9;
    };
}tp_tp_tf_out_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  data_sel:1;
        RBus_UInt32  tp_frame_rate:13;
        RBus_UInt32  ck_gate:1;
        RBus_UInt32  sync_dur:1;
        RBus_UInt32  get_size:2;
        RBus_UInt32  out_stop_mode:1;
        RBus_UInt32  out_share_en:1;
        RBus_UInt32  share_mode:1;
        RBus_UInt32  res2:7;
    };
}tp_tp_out_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  pause_int_en:1;
        RBus_UInt32  pause_int:1;
        RBus_UInt32  res1:29;
    };
}tp_tp_out_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf_th:32;
    };
}tp_tp_out_share_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  buf_space:32;
    };
}tp_tp_out_share_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_out:32;
    };
}tp_tp_out_share_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tpi_0_clk_pol:1;
        RBus_UInt32  tpi_0_sync_pol:1;
        RBus_UInt32  tpi_0_val_pol:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tpi_1_clk_pol:1;
        RBus_UInt32  tpi_1_sync_pol:1;
        RBus_UInt32  tpi_1_val_pol:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tpi_2_clk_pol:1;
        RBus_UInt32  tpi_2_sync_pol:1;
        RBus_UInt32  tpi_2_val_pol:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  tpi_demod_clk_pol:1;
        RBus_UInt32  tpi_demod_sync_pol:1;
        RBus_UInt32  tpi_demod_val_pol:1;
        RBus_UInt32  res4:17;
    };
}tp_tp_in_pol_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extra_pid_addr:7;
        RBus_UInt32  pcra_src_sel:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  res1:18;
    };
}tp_tp0_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extra_pid_addr:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  res2:18;
    };
}tp_tp1_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extra_pid_addr:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  res2:18;
    };
}tp_tp2_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extra_pid_addr:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  extra_func_ena:1;
        RBus_UInt32  local_pcr_sel:1;
        RBus_UInt32  stc_sel:2;
        RBus_UInt32  pcr_st:1;
        RBus_UInt32  pcr_stc_align:1;
        RBus_UInt32  res2:18;
    };
}tp_tp3_pcr_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  latch_sel:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  latch_ena:1;
        RBus_UInt32  res2:23;
    };
}tp_tp_pcr_latch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_base_lo:32;
    };
}tp_tp_pcr_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_ext:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  pcr_base_hi:1;
        RBus_UInt32  res2:15;
    };
}tp_tp_pcr_ext_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  system_ts:32;
    };
}tp_tp_pcr_system_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp0:8;
        RBus_UInt32  tp1:8;
        RBus_UInt32  tp2:8;
        RBus_UInt32  tp3:8;
    };
}tp_tp_sync_rplace_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  partition3:8;
        RBus_UInt32  partition2:8;
        RBus_UInt32  partition1:8;
        RBus_UInt32  res1:8;
    };
}tp_tp_pid_part_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:7;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res1:24;
    };
}tp_tp_pid_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pid:13;
        RBus_UInt32  v:1;
        RBus_UInt32  ddr_q:5;
        RBus_UInt32  sec_en:1;
        RBus_UInt32  sec_idx:8;
        RBus_UInt32  ti_en:1;
        RBus_UInt32  ai_en:1;
        RBus_UInt32  pid_ini:1;
        RBus_UInt32  si_en:1;
    };
}tp_tp_pid_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  info_q:5;
        RBus_UInt32  ddr_q_en:1;
        RBus_UInt32  cc_en:1;
        RBus_UInt32  key:5;
        RBus_UInt32  pre_des:1;
        RBus_UInt32  info_q_en:1;
        RBus_UInt32  encryption_en:1;
        RBus_UInt32  pid_des_disable:1;
        RBus_UInt32  descramble_sel:1;
        RBus_UInt32  local_des_en:1;
        RBus_UInt32  keyindex:6;
        RBus_UInt32  encryption_key:1;
        RBus_UInt32  encrypt_tsc_en:1;
        RBus_UInt32  tdes_mode:1;
        RBus_UInt32  aes_mode:2;
        RBus_UInt32  des_sel:3;
    };
}tp_tp_pid_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  round:8;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  res1:12;
    };
}tp_tp_pid_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:8;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res1:23;
    };
}tp_tp_sec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_msb:32;
    };
}tp_tp_sec_data0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_value_lsb:32;
    };
}tp_tp_sec_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_msb:32;
    };
}tp_tp_sec_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mask_value_lsb:32;
    };
}tp_tp_sec_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  next_sec:8;
        RBus_UInt32  last:1;
        RBus_UInt32  p_n:1;
        RBus_UInt32  p_d:1;
        RBus_UInt32  crc_en:1;
        RBus_UInt32  sp_mask:2;
        RBus_UInt32  sp_filter:2;
        RBus_UInt32  res1:16;
    };
}tp_tp_sec_data4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_msb:32;
    };
}tp_tp_sec_data5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_filter_value_lsb:32;
    };
}tp_tp_sec_data6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_msb:32;
    };
}tp_tp_sec_data7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  neg_mask_value_lsb:32;
    };
}tp_tp_sec_data8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  filter_sel:2;
        RBus_UInt32  res1:8;
        RBus_UInt32  neg_sp_mask:2;
        RBus_UInt32  neg_sp_filter:2;
        RBus_UInt32  res2:18;
    };
}tp_tp_sec_data9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  round:8;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  res1:12;
    };
}tp_tp_tp0_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key_info:32;
    };
}tp_tp_key_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:7;
        RBus_UInt32  r_w:1;
        RBus_UInt32  res1:24;
    };
}tp_tp_key_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  round:8;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  res1:12;
    };
}tp_tp_tp1_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:3;
        RBus_UInt32  des_mode:1;
        RBus_UInt32  map_01:1;
        RBus_UInt32  map_10:1;
        RBus_UInt32  map_11:1;
        RBus_UInt32  multi2_mode:1;
        RBus_UInt32  round:8;
        RBus_UInt32  csa_mode:2;
        RBus_UInt32  ofb_mode:2;
        RBus_UInt32  res1:12;
    };
}tp_tp_tp2_des_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_init:32;
    };
}tp_tp_crc_init_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fullness:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_fullness_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  r_w:1;
        RBus_UInt32  wm:4;
        RBus_UInt32  res2:21;
    };
}tp_tp_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_avail_0:1;
        RBus_UInt32  ring_avail_1:1;
        RBus_UInt32  ring_avail_2:1;
        RBus_UInt32  ring_avail_3:1;
        RBus_UInt32  ring_avail_4:1;
        RBus_UInt32  ring_avail_5:1;
        RBus_UInt32  ring_avail_6:1;
        RBus_UInt32  ring_avail_7:1;
        RBus_UInt32  ring_avail_8:1;
        RBus_UInt32  ring_avail_9:1;
        RBus_UInt32  ring_avail_10:1;
        RBus_UInt32  ring_avail_11:1;
        RBus_UInt32  ring_avail_12:1;
        RBus_UInt32  ring_avail_13:1;
        RBus_UInt32  ring_avail_14:1;
        RBus_UInt32  ring_avail_15:1;
        RBus_UInt32  res1:15;
    };
}tp_tp_ring_avail_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_full_0:1;
        RBus_UInt32  ring_full_1:1;
        RBus_UInt32  ring_full_2:1;
        RBus_UInt32  ring_full_3:1;
        RBus_UInt32  ring_full_4:1;
        RBus_UInt32  ring_full_5:1;
        RBus_UInt32  ring_full_6:1;
        RBus_UInt32  ring_full_7:1;
        RBus_UInt32  ring_full_8:1;
        RBus_UInt32  ring_full_9:1;
        RBus_UInt32  ring_full_10:1;
        RBus_UInt32  ring_full_11:1;
        RBus_UInt32  ring_full_12:1;
        RBus_UInt32  ring_full_13:1;
        RBus_UInt32  ring_full_14:1;
        RBus_UInt32  ring_full_15:1;
        RBus_UInt32  res1:15;
    };
}tp_tp_ring_full_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_avail_0_en:1;
        RBus_UInt32  ring_avail_1_en:1;
        RBus_UInt32  ring_avail_2_en:1;
        RBus_UInt32  ring_avail_3_en:1;
        RBus_UInt32  ring_avail_4_en:1;
        RBus_UInt32  ring_avail_5_en:1;
        RBus_UInt32  ring_avail_6_en:1;
        RBus_UInt32  ring_avail_7_en:1;
        RBus_UInt32  ring_avail_8_en:1;
        RBus_UInt32  ring_avail_9_en:1;
        RBus_UInt32  ring_avail_10_en:1;
        RBus_UInt32  ring_avail_11_en:1;
        RBus_UInt32  ring_avail_12_en:1;
        RBus_UInt32  ring_avail_13_en:1;
        RBus_UInt32  ring_avail_14_en:1;
        RBus_UInt32  ring_avail_15_en:1;
        RBus_UInt32  res1:15;
    };
}tp_tp_ring_avail_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_full_0_en:1;
        RBus_UInt32  ring_full_1_en:1;
        RBus_UInt32  ring_full_2_en:1;
        RBus_UInt32  ring_full_3_en:1;
        RBus_UInt32  ring_full_4_en:1;
        RBus_UInt32  ring_full_5_en:1;
        RBus_UInt32  ring_full_6_en:1;
        RBus_UInt32  ring_full_7_en:1;
        RBus_UInt32  ring_full_8_en:1;
        RBus_UInt32  ring_full_9_en:1;
        RBus_UInt32  ring_full_10_en:1;
        RBus_UInt32  ring_full_11_en:1;
        RBus_UInt32  ring_full_12_en:1;
        RBus_UInt32  ring_full_13_en:1;
        RBus_UInt32  ring_full_14_en:1;
        RBus_UInt32  ring_full_15_en:1;
        RBus_UInt32  res1:15;
    };
}tp_tp_ring_full_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sync_pos:32;
    };
}tp_tp_sync_pos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_tp_dmy_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_tp_dmy_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_tp:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:30;
    };
}tp_tp_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_bist_fail_group_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key:1;
        RBus_UInt32  sect:1;
        RBus_UInt32  pid:1;
        RBus_UInt32  ring:1;
        RBus_UInt32  tpp_dma_3:1;
        RBus_UInt32  tpp_dma_2:1;
        RBus_UInt32  tpp_dma_1:1;
        RBus_UInt32  tpp_dma_0:1;
        RBus_UInt32  tp_dma_3:1;
        RBus_UInt32  tp_dma_2:1;
        RBus_UInt32  tp_dma_1:1;
        RBus_UInt32  tp_dma_0:1;
        RBus_UInt32  tp_dma_4:1;
        RBus_UInt32  atsc_dma:1;
        RBus_UInt32  res1:18;
    };
}tp_tp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_mode_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resume_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_done_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pause_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail_group_tp:1;
        RBus_UInt32  res1:31;
    };
}tp_tp_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key:1;
        RBus_UInt32  sect:1;
        RBus_UInt32  pid:1;
        RBus_UInt32  ring:1;
        RBus_UInt32  tpp_dma_3:1;
        RBus_UInt32  tpp_dma_2:1;
        RBus_UInt32  tpp_dma_1:1;
        RBus_UInt32  tpp_dma_0:1;
        RBus_UInt32  tp_dma_3:1;
        RBus_UInt32  tp_dma_2:1;
        RBus_UInt32  tp_dma_1:1;
        RBus_UInt32  tp_dma_0:1;
        RBus_UInt32  tp_dma_4:1;
        RBus_UInt32  atsc_dma:1;
        RBus_UInt32  res1:18;
    };
}tp_tp_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key:1;
        RBus_UInt32  sect:1;
        RBus_UInt32  pid:1;
        RBus_UInt32  ring:1;
        RBus_UInt32  tpp_dma_3:1;
        RBus_UInt32  tpp_dma_2:1;
        RBus_UInt32  tpp_dma_1:1;
        RBus_UInt32  tpp_dma_0:1;
        RBus_UInt32  tp_dma_3:1;
        RBus_UInt32  tp_dma_2:1;
        RBus_UInt32  tp_dma_1:1;
        RBus_UInt32  tp_dma_0:1;
        RBus_UInt32  tp_dma_4:1;
        RBus_UInt32  atsc_dma:1;
        RBus_UInt32  res1:18;
    };
}tp_tp_bist_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key:4;
        RBus_UInt32  sect:4;
        RBus_UInt32  pid:4;
        RBus_UInt32  ring:4;
        RBus_UInt32  tpp_dma_3:4;
        RBus_UInt32  tpp_dma_2:4;
        RBus_UInt32  tpp_dma_1:4;
        RBus_UInt32  tpp_dma_0:4;
    };
}tp_tp_bist_dvs_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tpp_dma_3:4;
        RBus_UInt32  tpp_dma_2:4;
        RBus_UInt32  tpp_dma_1:4;
        RBus_UInt32  tpp_dma_0:4;
        RBus_UInt32  tp_dma_4:4;
        RBus_UInt32  atsc_dma:4;
        RBus_UInt32  res1:8;
    };
}tp_tp_bist_dvs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_mode:5;
        RBus_UInt32  tp_pkt_sram_addr_rst_sel:1;
        RBus_UInt32  tp_sram_sleep_off:1;
        RBus_UInt32  dv_verify_only:1;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  res1:23;
    };
}tp_tp_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_p_st:6;
        RBus_UInt32  dma_st:6;
        RBus_UInt32  tp0_m2m_st:3;
        RBus_UInt32  tpp0_m2m_st:3;
        RBus_UInt32  tp0_st:2;
        RBus_UInt32  tpp0_st:2;
        RBus_UInt32  mtp_p_st:2;
        RBus_UInt32  m2tp_p_st:2;
        RBus_UInt32  mtp_st:3;
        RBus_UInt32  m2tp_st:2;
        RBus_UInt32  res1:1;
    };
}tp_tp_debug_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_port:32;
    };
}tp_tp_debug_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp0_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp0_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp0_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp0_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp0_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp1_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp1_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp1_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp1_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp1_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp2_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp2_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp2_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp2_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp2_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp3_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp3_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp3_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp3_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp3_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp0_p_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp0_p_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp0_p_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp0_p_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp0_p_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp1_p_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp1_p_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp1_p_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp1_p_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp1_p_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp2_p_m2m_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp2_p_m2m_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp2_p_m2m_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp2_p_m2m_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  in_go:1;
        RBus_UInt32  empty_en:1;
        RBus_UInt32  empty:1;
        RBus_UInt32  res1:27;
    };
}tp_tp2_p_m2m_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf0_p_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf0_p_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf0_p_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf0_p_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf0_p_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf0_p_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf1_p_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf1_p_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf1_p_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf1_p_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf1_p_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf1_p_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rst_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  trerr_en:1;
        RBus_UInt32  null_en:1;
        RBus_UInt32  pid_en:1;
        RBus_UInt32  xt_en:1;
        RBus_UInt32  de_en:1;
        RBus_UInt32  du_en:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  busy:1;
        RBus_UInt32  tb:1;
        RBus_UInt32  tsc_en:1;
        RBus_UInt32  pes_en:1;
        RBus_UInt32  psc_en:1;
        RBus_UInt32  buf_rdy_ctl:1;
        RBus_UInt32  strm_id_en:1;
        RBus_UInt32  tp_err_fix_en:1;
        RBus_UInt32  ci_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  dir_dma:1;
        RBus_UInt32  src_sel_l:1;
        RBus_UInt32  src_sel_h:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  two_bit_sel_l:1;
        RBus_UInt32  two_bit_sel_h:1;
        RBus_UInt32  two_bit_reverse:1;
        RBus_UInt32  two_bit:1;
    };
}tp_tp_tf2_p_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:24;
        RBus_UInt32  res1:8;
    };
}tp_tp_tf2_p_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_tf2_p_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  datapin:1;
        RBus_UInt32  serial:1;
        RBus_UInt32  syncmode:5;
        RBus_UInt32  forcedrop:1;
        RBus_UInt32  frm_en:1;
        RBus_UInt32  data_order:1;
        RBus_UInt32  packet_size:2;
        RBus_UInt32  lockno:4;
        RBus_UInt32  dropno:4;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_tf2_p_frmcfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  drop:1;
        RBus_UInt32  overflow:1;
        RBus_UInt32  adf_pcr_in:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf2_p_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  drop_en:1;
        RBus_UInt32  overflow_en:1;
        RBus_UInt32  adf_pcr_in_en:1;
        RBus_UInt32  res1:27;
    };
}tp_tp_tf2_p_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  threshold:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_p_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fullness:29;
        RBus_UInt32  res1:3;
    };
}tp_tp_p_fullness_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idx:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  r_w:1;
        RBus_UInt32  wm:4;
        RBus_UInt32  res2:21;
    };
}tp_tp_p_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp_p_ring_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp_p_ring_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_p_ring_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_p_ring_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_avail_0:1;
        RBus_UInt32  ring_avail_1:1;
        RBus_UInt32  ring_avail_2:1;
        RBus_UInt32  res1:28;
    };
}tp_tp_p_ring_avail_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_full_0:1;
        RBus_UInt32  ring_full_1:1;
        RBus_UInt32  ring_full_2:1;
        RBus_UInt32  res1:28;
    };
}tp_tp_p_ring_full_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_avail_0_en:1;
        RBus_UInt32  ring_avail_1_en:1;
        RBus_UInt32  ring_avail_2_en:1;
        RBus_UInt32  res1:28;
    };
}tp_tp_p_ring_avail_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ring_full_0_en:1;
        RBus_UInt32  ring_full_1_en:1;
        RBus_UInt32  ring_full_2_en:1;
        RBus_UInt32  res1:28;
    };
}tp_tp_p_ring_full_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp0:8;
        RBus_UInt32  tp1:8;
        RBus_UInt32  tp2:8;
        RBus_UInt32  res1:8;
    };
}tp_tp_p_sync_rplace_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp2_sel:2;
        RBus_UInt32  tp1_sel:2;
        RBus_UInt32  tp0_sel:2;
        RBus_UInt32  tp3_sel:2;
        RBus_UInt32  tp2_keep:1;
        RBus_UInt32  tp1_keep:1;
        RBus_UInt32  tp0_keep:1;
        RBus_UInt32  tp3_keep:1;
        RBus_UInt32  res1:20;
    };
}tp_prefix_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  meta:32;
    };
}tp_prefix_data1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg01:32;
    };
}tp_prefix_data2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg02:32;
    };
}tp_prefix_data3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp0_rate:3;
        RBus_UInt32  tp0_en:1;
        RBus_UInt32  tp1_rate:3;
        RBus_UInt32  tp1_en:1;
        RBus_UInt32  tp2_rate:3;
        RBus_UInt32  tp2_en:1;
        RBus_UInt32  tp3_rate:3;
        RBus_UInt32  tp3_en:1;
        RBus_UInt32  res1:16;
    };
}tp_fr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_fr_cnt_tp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern:24;
        RBus_UInt32  en:1;
        RBus_UInt32  dma_flush:1;
        RBus_UInt32  req_level:5;
        RBus_UInt32  res1:1;
    };
}tp_start_code_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern:24;
        RBus_UInt32  en:1;
        RBus_UInt32  dma_flush:1;
        RBus_UInt32  req_level:5;
        RBus_UInt32  res1:1;
    };
}tp_start_code_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pid:13;
        RBus_UInt32  info_q:5;
        RBus_UInt32  sw_rst:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  fifo_cnt:7;
        RBus_UInt32  res2:1;
    };
}tp_start_code_ctrl_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pid:13;
        RBus_UInt32  info_q:5;
        RBus_UInt32  sw_rst:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  fifo_cnt:7;
        RBus_UInt32  res2:1;
    };
}tp_start_code_ctrl_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wp:32;
    };
}tp_start_code_wp_tp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wp:32;
    };
}tp_start_code_wp_tp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  src_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  protocol:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  data_mode:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  data_reverse:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  data_location:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  data_endian:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  sw_rst:1;
        RBus_UInt32  res8:3;
    };
}tp_tp_atsc_src_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_auto_mode:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  oif_header_length:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  err_en:1;
        RBus_UInt32  sync_en:1;
        RBus_UInt32  length_err_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dmy_discard:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sync_byte:8;
    };
}tp_tp_atsc_config1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  starter:32;
    };
}tp_tp_atsc_config2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oif_length_offset:16;
        RBus_UInt32  res1:16;
    };
}tp_tp_atsc_config3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plp_idx0_en:1;
        RBus_UInt32  plp_idx1_en:1;
        RBus_UInt32  plp_idx2_en:1;
        RBus_UInt32  plp_idx3_en:1;
        RBus_UInt32  plp_idx4_en:1;
        RBus_UInt32  plp_idx5_en:1;
        RBus_UInt32  plp_idx6_en:1;
        RBus_UInt32  plp_idx7_en:1;
        RBus_UInt32  plp_idx8_en:1;
        RBus_UInt32  plp_idx9_en:1;
        RBus_UInt32  plp_idx10_en:1;
        RBus_UInt32  plp_idx11_en:1;
        RBus_UInt32  plp_idx12_en:1;
        RBus_UInt32  plp_idx13_en:1;
        RBus_UInt32  plp_idx14_en:1;
        RBus_UInt32  plp_idx15_en:1;
        RBus_UInt32  plp_idx16_en:1;
        RBus_UInt32  plp_idx17_en:1;
        RBus_UInt32  plp_idx18_en:1;
        RBus_UInt32  plp_idx19_en:1;
        RBus_UInt32  plp_idx20_en:1;
        RBus_UInt32  plp_idx21_en:1;
        RBus_UInt32  plp_idx22_en:1;
        RBus_UInt32  plp_idx23_en:1;
        RBus_UInt32  plp_idx24_en:1;
        RBus_UInt32  plp_idx25_en:1;
        RBus_UInt32  plp_idx26_en:1;
        RBus_UInt32  plp_idx27_en:1;
        RBus_UInt32  plp_idx28_en:1;
        RBus_UInt32  plp_idx29_en:1;
        RBus_UInt32  plp_idx30_en:1;
        RBus_UInt32  plp_idx31_en:1;
    };
}tp_tp_atsc_plp_filter1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plp_idx32_en:1;
        RBus_UInt32  plp_idx33_en:1;
        RBus_UInt32  plp_idx34_en:1;
        RBus_UInt32  plp_idx35_en:1;
        RBus_UInt32  plp_idx36_en:1;
        RBus_UInt32  plp_idx37_en:1;
        RBus_UInt32  plp_idx38_en:1;
        RBus_UInt32  plp_idx39_en:1;
        RBus_UInt32  plp_idx40_en:1;
        RBus_UInt32  plp_idx41_en:1;
        RBus_UInt32  plp_idx42_en:1;
        RBus_UInt32  plp_idx43_en:1;
        RBus_UInt32  plp_idx44_en:1;
        RBus_UInt32  plp_idx45_en:1;
        RBus_UInt32  plp_idx46_en:1;
        RBus_UInt32  plp_idx47_en:1;
        RBus_UInt32  plp_idx48_en:1;
        RBus_UInt32  plp_idx49_en:1;
        RBus_UInt32  plp_idx50_en:1;
        RBus_UInt32  plp_idx51_en:1;
        RBus_UInt32  plp_idx52_en:1;
        RBus_UInt32  plp_idx53_en:1;
        RBus_UInt32  plp_idx54_en:1;
        RBus_UInt32  plp_idx55_en:1;
        RBus_UInt32  plp_idx56_en:1;
        RBus_UInt32  plp_idx57_en:1;
        RBus_UInt32  plp_idx58_en:1;
        RBus_UInt32  plp_idx59_en:1;
        RBus_UInt32  plp_idx60_en:1;
        RBus_UInt32  plp_idx61_en:1;
        RBus_UInt32  plp_idx62_en:1;
        RBus_UInt32  plp_idx63_en:1;
    };
}tp_tp_atsc_plp_filter2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp_atsc_d_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp_atsc_d_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_atsc_d_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_atsc_d_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_limit:29;
    };
}tp_tp_atsc_i_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ring_base:29;
    };
}tp_tp_atsc_i_base_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_rp:32;
    };
}tp_tp_atsc_i_rp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ring_wp:32;
    };
}tp_tp_atsc_i_wp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dring_available:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dring_available_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dring_full:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dring_full_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  iring_available:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  iring_available_en:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  iring_full:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  iring_full_en:1;
        RBus_UInt32  res8:3;
    };
}tp_tp_atsc_ring_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt:32;
    };
}tp_tp_atsc_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_cnt:32;
    };
}tp_tp_atsc_err_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drp_cnt:32;
    };
}tp_tp_atsc_drp_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy:32;
    };
}tp_tp_atsc_dmy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  item1:1;
        RBus_UInt32  item2:1;
        RBus_UInt32  item3:1;
        RBus_UInt32  item4:1;
        RBus_UInt32  item5:1;
        RBus_UInt32  item6:1;
        RBus_UInt32  item7:1;
        RBus_UInt32  item8:1;
        RBus_UInt32  item9:1;
        RBus_UInt32  item10:1;
        RBus_UInt32  item11:1;
        RBus_UInt32  res1:21;
    };
}tp_tp0_err_cnt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  item1:1;
        RBus_UInt32  item2:1;
        RBus_UInt32  item3:1;
        RBus_UInt32  item4:1;
        RBus_UInt32  item5:1;
        RBus_UInt32  item6:1;
        RBus_UInt32  item7:1;
        RBus_UInt32  item8:1;
        RBus_UInt32  item9:1;
        RBus_UInt32  item10:1;
        RBus_UInt32  item11:1;
        RBus_UInt32  res1:21;
    };
}tp_tp1_err_cnt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  item1:1;
        RBus_UInt32  item2:1;
        RBus_UInt32  item3:1;
        RBus_UInt32  item4:1;
        RBus_UInt32  item5:1;
        RBus_UInt32  item6:1;
        RBus_UInt32  item7:1;
        RBus_UInt32  item8:1;
        RBus_UInt32  item9:1;
        RBus_UInt32  item10:1;
        RBus_UInt32  item11:1;
        RBus_UInt32  res1:21;
    };
}tp_tp2_err_cnt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcra_90k_cnt_high:32;
    };
}tp_tp_pcra_90k_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcra_90k_cnt:32;
    };
}tp_tp_pcra_90k_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcrb_90k_cnt_high:32;
    };
}tp_tp_pcrb_90k_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcrb_90k_cnt:32;
    };
}tp_tp_pcrb_90k_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fr_enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  fr_df:12;
        RBus_UInt32  av_sync_enable:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  av_sync_sel:1;
        RBus_UInt32  res3:11;
    };
}tp_tp_misc_27m_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  latch:1;
        RBus_UInt32  res2:27;
    };
}tp_tp_misc_27m_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_misc_27m_cnt_high:32;
    };
}tp_tp_misc_27m_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_misc_27m_cnt:32;
    };
}tp_tp_misc_27m_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_avsync_cnt_high:32;
    };
}tp_tp_avsync_cnt_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp_avsync_cnt:32;
    };
}tp_tp_avsync_cnt_RBUS;




#endif 


#endif 
