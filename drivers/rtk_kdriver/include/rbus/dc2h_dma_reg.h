/**
* @file Mac5-DesignSpec-D-Domain_DC2H
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DC2H_DMA_REG_H_
#define _RBUS_DC2H_DMA_REG_H_

#include "rbus_types.h"



//  DC2H_DMA Register Address
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1                                            0x18029D80
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_reg_addr                                   "0xB8029D80"
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_reg                                        0xB8029D80
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_inst_addr                                  "0x0000"
#define  set_DC2H_DMA_dc2h_Seq_mode_CTRL1_reg(data)                              (*((volatile unsigned int*)DC2H_DMA_dc2h_Seq_mode_CTRL1_reg)=data)
#define  get_DC2H_DMA_dc2h_Seq_mode_CTRL1_reg                                    (*((volatile unsigned int*)DC2H_DMA_dc2h_Seq_mode_CTRL1_reg))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_argb_dummy_data_shift                      (8)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_argb_swap_shift                            (5)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_rgb_to_argb_en_shift                       (4)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_cap_en_shift                               (0)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_argb_dummy_data_mask                       (0x0000FF00)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_argb_swap_mask                             (0x00000020)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_rgb_to_argb_en_mask                        (0x00000010)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_cap_en_mask                                (0x00000001)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_argb_dummy_data(data)                      (0x0000FF00&((data)<<8))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_argb_swap(data)                            (0x00000020&((data)<<5))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_rgb_to_argb_en(data)                       (0x00000010&((data)<<4))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_cap_en(data)                               (0x00000001&(data))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_get_argb_dummy_data(data)                  ((0x0000FF00&(data))>>8)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_get_argb_swap(data)                        ((0x00000020&(data))>>5)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_get_rgb_to_argb_en(data)                   ((0x00000010&(data))>>4)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL1_get_cap_en(data)                           (0x00000001&(data))

#define  DC2H_DMA_dc2h_Seq_mode_CTRL2                                            0x18029D84
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_reg_addr                                   "0xB8029D84"
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_reg                                        0xB8029D84
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_inst_addr                                  "0x0001"
#define  set_DC2H_DMA_dc2h_Seq_mode_CTRL2_reg(data)                              (*((volatile unsigned int*)DC2H_DMA_dc2h_Seq_mode_CTRL2_reg)=data)
#define  get_DC2H_DMA_dc2h_Seq_mode_CTRL2_reg                                    (*((volatile unsigned int*)DC2H_DMA_dc2h_Seq_mode_CTRL2_reg))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_vact_shift                                 (16)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_hact_shift                                 (0)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_vact_mask                                  (0xFFFF0000)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_hact_mask                                  (0x00007FFF)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_vact(data)                                 (0xFFFF0000&((data)<<16))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_hact(data)                                 (0x00007FFF&(data))
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_get_vact(data)                             ((0xFFFF0000&(data))>>16)
#define  DC2H_DMA_dc2h_Seq_mode_CTRL2_get_hact(data)                             (0x00007FFF&(data))

#define  DC2H_DMA_dc2h_Cap_CTL0                                                  0x18029D88
#define  DC2H_DMA_dc2h_Cap_CTL0_reg_addr                                         "0xB8029D88"
#define  DC2H_DMA_dc2h_Cap_CTL0_reg                                              0xB8029D88
#define  DC2H_DMA_dc2h_Cap_CTL0_inst_addr                                        "0x0002"
#define  set_DC2H_DMA_dc2h_Cap_CTL0_reg(data)                                    (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_CTL0_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_CTL0_reg                                          (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_CTL0_reg))
#define  DC2H_DMA_dc2h_Cap_CTL0_triple_buf_en_shift                              (31)
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_block_fw_shift                               (29)
#define  DC2H_DMA_dc2h_Cap_CTL0_set_block_sel_shift                              (28)
#define  DC2H_DMA_dc2h_Cap_CTL0_vs_fall_rst_en_shift                             (21)
#define  DC2H_DMA_dc2h_Cap_CTL0_auto_block_sel_en_shift                          (20)
#define  DC2H_DMA_dc2h_Cap_CTL0_bit_sel_shift                                    (18)
#define  DC2H_DMA_dc2h_Cap_CTL0_pixel_encoding_shift                             (16)
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_write_len_shift                              (8)
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_write_rem_shift                              (0)
#define  DC2H_DMA_dc2h_Cap_CTL0_triple_buf_en_mask                               (0x80000000)
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_block_fw_mask                                (0x60000000)
#define  DC2H_DMA_dc2h_Cap_CTL0_set_block_sel_mask                               (0x10000000)
#define  DC2H_DMA_dc2h_Cap_CTL0_vs_fall_rst_en_mask                              (0x00200000)
#define  DC2H_DMA_dc2h_Cap_CTL0_auto_block_sel_en_mask                           (0x00100000)
#define  DC2H_DMA_dc2h_Cap_CTL0_bit_sel_mask                                     (0x00040000)
#define  DC2H_DMA_dc2h_Cap_CTL0_pixel_encoding_mask                              (0x00030000)
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_write_len_mask                               (0x00007F00)
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_write_rem_mask                               (0x0000007F)
#define  DC2H_DMA_dc2h_Cap_CTL0_triple_buf_en(data)                              (0x80000000&((data)<<31))
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_block_fw(data)                               (0x60000000&((data)<<29))
#define  DC2H_DMA_dc2h_Cap_CTL0_set_block_sel(data)                              (0x10000000&((data)<<28))
#define  DC2H_DMA_dc2h_Cap_CTL0_vs_fall_rst_en(data)                             (0x00200000&((data)<<21))
#define  DC2H_DMA_dc2h_Cap_CTL0_auto_block_sel_en(data)                          (0x00100000&((data)<<20))
#define  DC2H_DMA_dc2h_Cap_CTL0_bit_sel(data)                                    (0x00040000&((data)<<18))
#define  DC2H_DMA_dc2h_Cap_CTL0_pixel_encoding(data)                             (0x00030000&((data)<<16))
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_write_len(data)                              (0x00007F00&((data)<<8))
#define  DC2H_DMA_dc2h_Cap_CTL0_cap_write_rem(data)                              (0x0000007F&(data))
#define  DC2H_DMA_dc2h_Cap_CTL0_get_triple_buf_en(data)                          ((0x80000000&(data))>>31)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_cap_block_fw(data)                           ((0x60000000&(data))>>29)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_set_block_sel(data)                          ((0x10000000&(data))>>28)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_vs_fall_rst_en(data)                         ((0x00200000&(data))>>21)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_auto_block_sel_en(data)                      ((0x00100000&(data))>>20)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_bit_sel(data)                                ((0x00040000&(data))>>18)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_pixel_encoding(data)                         ((0x00030000&(data))>>16)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_cap_write_len(data)                          ((0x00007F00&(data))>>8)
#define  DC2H_DMA_dc2h_Cap_CTL0_get_cap_write_rem(data)                          (0x0000007F&(data))

#define  DC2H_DMA_dc2h_Cap_CTL1                                                  0x18029D8C
#define  DC2H_DMA_dc2h_Cap_CTL1_reg_addr                                         "0xB8029D8C"
#define  DC2H_DMA_dc2h_Cap_CTL1_reg                                              0xB8029D8C
#define  DC2H_DMA_dc2h_Cap_CTL1_inst_addr                                        "0x0003"
#define  set_DC2H_DMA_dc2h_Cap_CTL1_reg(data)                                    (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_CTL1_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_CTL1_reg                                          (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_CTL1_reg))
#define  DC2H_DMA_dc2h_Cap_CTL1_cap_water_lv_shift                               (8)
#define  DC2H_DMA_dc2h_Cap_CTL1_cap_write_num_shift                              (0)
#define  DC2H_DMA_dc2h_Cap_CTL1_cap_water_lv_mask                                (0x00007F00)
#define  DC2H_DMA_dc2h_Cap_CTL1_cap_write_num_mask                               (0x000000FF)
#define  DC2H_DMA_dc2h_Cap_CTL1_cap_water_lv(data)                               (0x00007F00&((data)<<8))
#define  DC2H_DMA_dc2h_Cap_CTL1_cap_write_num(data)                              (0x000000FF&(data))
#define  DC2H_DMA_dc2h_Cap_CTL1_get_cap_water_lv(data)                           ((0x00007F00&(data))>>8)
#define  DC2H_DMA_dc2h_Cap_CTL1_get_cap_write_num(data)                          (0x000000FF&(data))

#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1                                         0x18029D90
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg_addr                                "0xB8029D90"
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg                                     0xB8029D90
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_inst_addr                               "0x0004"
#define  set_DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg(data)                           (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg                                 (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_BoundaryAddr1_reg))
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_cap_mem_up_limit_shift                  (3)
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_cap_mem_up_limit_mask                   (0xFFFFFFF8)
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_cap_mem_up_limit(data)                  (0xFFFFFFF8&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr1_get_cap_mem_up_limit(data)              ((0xFFFFFFF8&(data))>>3)

#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2                                         0x18029D94
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg_addr                                "0xB8029D94"
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg                                     0xB8029D94
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_inst_addr                               "0x0005"
#define  set_DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg(data)                           (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg                                 (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_BoundaryAddr2_reg))
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_cap_mem_low_limit_shift                 (3)
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_cap_mem_low_limit_mask                  (0xFFFFFFF8)
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_cap_mem_low_limit(data)                 (0xFFFFFFF8&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_BoundaryAddr2_get_cap_mem_low_limit(data)             ((0xFFFFFFF8&(data))>>3)

#define  DC2H_DMA_dc2h_Cap_L1_Start                                              0x18029D98
#define  DC2H_DMA_dc2h_Cap_L1_Start_reg_addr                                     "0xB8029D98"
#define  DC2H_DMA_dc2h_Cap_L1_Start_reg                                          0xB8029D98
#define  DC2H_DMA_dc2h_Cap_L1_Start_inst_addr                                    "0x0006"
#define  set_DC2H_DMA_dc2h_Cap_L1_Start_reg(data)                                (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L1_Start_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_L1_Start_reg                                      (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L1_Start_reg))
#define  DC2H_DMA_dc2h_Cap_L1_Start_cap_l1_start_shift                           (3)
#define  DC2H_DMA_dc2h_Cap_L1_Start_cap_l1_start_mask                            (0xFFFFFFF8)
#define  DC2H_DMA_dc2h_Cap_L1_Start_cap_l1_start(data)                           (0xFFFFFFF8&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_L1_Start_get_cap_l1_start(data)                       ((0xFFFFFFF8&(data))>>3)

#define  DC2H_DMA_dc2h_Cap_L2_Start                                              0x18029D9C
#define  DC2H_DMA_dc2h_Cap_L2_Start_reg_addr                                     "0xB8029D9C"
#define  DC2H_DMA_dc2h_Cap_L2_Start_reg                                          0xB8029D9C
#define  DC2H_DMA_dc2h_Cap_L2_Start_inst_addr                                    "0x0007"
#define  set_DC2H_DMA_dc2h_Cap_L2_Start_reg(data)                                (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L2_Start_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_L2_Start_reg                                      (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L2_Start_reg))
#define  DC2H_DMA_dc2h_Cap_L2_Start_cap_l2_start_shift                           (3)
#define  DC2H_DMA_dc2h_Cap_L2_Start_cap_l2_start_mask                            (0xFFFFFFF8)
#define  DC2H_DMA_dc2h_Cap_L2_Start_cap_l2_start(data)                           (0xFFFFFFF8&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_L2_Start_get_cap_l2_start(data)                       ((0xFFFFFFF8&(data))>>3)

#define  DC2H_DMA_dc2h_Cap_L3_Start                                              0x18029DA0
#define  DC2H_DMA_dc2h_Cap_L3_Start_reg_addr                                     "0xB8029DA0"
#define  DC2H_DMA_dc2h_Cap_L3_Start_reg                                          0xB8029DA0
#define  DC2H_DMA_dc2h_Cap_L3_Start_inst_addr                                    "0x0008"
#define  set_DC2H_DMA_dc2h_Cap_L3_Start_reg(data)                                (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L3_Start_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_L3_Start_reg                                      (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L3_Start_reg))
#define  DC2H_DMA_dc2h_Cap_L3_Start_cap_l3_start_shift                           (3)
#define  DC2H_DMA_dc2h_Cap_L3_Start_cap_l3_start_mask                            (0xFFFFFFF8)
#define  DC2H_DMA_dc2h_Cap_L3_Start_cap_l3_start(data)                           (0xFFFFFFF8&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_L3_Start_get_cap_l3_start(data)                       ((0xFFFFFFF8&(data))>>3)

#define  DC2H_DMA_dc2h_Cap_L1_Start_db                                           0x18029DA4
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_reg_addr                                  "0xB8029DA4"
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_reg                                       0xB8029DA4
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_inst_addr                                 "0x0009"
#define  set_DC2H_DMA_dc2h_Cap_L1_Start_db_reg(data)                             (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L1_Start_db_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_L1_Start_db_reg                                   (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_L1_Start_db_reg))
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_cap_l1_start_db_shift                     (3)
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_cap_l1_start_db_mask                      (0xFFFFFFF8)
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_cap_l1_start_db(data)                     (0xFFFFFFF8&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_L1_Start_db_get_cap_l1_start_db(data)                 ((0xFFFFFFF8&(data))>>3)

#define  DC2H_DMA_dc2h_Cap_Status                                                0x18029DA8
#define  DC2H_DMA_dc2h_Cap_Status_reg_addr                                       "0xB8029DA8"
#define  DC2H_DMA_dc2h_Cap_Status_reg                                            0xB8029DA8
#define  DC2H_DMA_dc2h_Cap_Status_inst_addr                                      "0x000A"
#define  set_DC2H_DMA_dc2h_Cap_Status_reg(data)                                  (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_Status_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_Status_reg                                        (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_Status_reg))
#define  DC2H_DMA_dc2h_Cap_Status_cap_block_2_shift                              (12)
#define  DC2H_DMA_dc2h_Cap_Status_cap_over_size_shift                            (11)
#define  DC2H_DMA_dc2h_Cap_Status_cap_under_size_shift                           (10)
#define  DC2H_DMA_dc2h_Cap_Status_vs_rising_occur_shift                          (8)
#define  DC2H_DMA_dc2h_Cap_Status_cap_block_shift                                (6)
#define  DC2H_DMA_dc2h_Cap_Status_cap_field_shift                                (5)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_full_shift                            (4)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_empty_shift                           (3)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_overflow_shift                        (2)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_underflow_shift                       (1)
#define  DC2H_DMA_dc2h_Cap_Status_cap_ddr_over_range_shift                       (0)
#define  DC2H_DMA_dc2h_Cap_Status_cap_block_2_mask                               (0x00003000)
#define  DC2H_DMA_dc2h_Cap_Status_cap_over_size_mask                             (0x00000800)
#define  DC2H_DMA_dc2h_Cap_Status_cap_under_size_mask                            (0x00000400)
#define  DC2H_DMA_dc2h_Cap_Status_vs_rising_occur_mask                           (0x00000100)
#define  DC2H_DMA_dc2h_Cap_Status_cap_block_mask                                 (0x00000040)
#define  DC2H_DMA_dc2h_Cap_Status_cap_field_mask                                 (0x00000020)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_full_mask                             (0x00000010)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_empty_mask                            (0x00000008)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_overflow_mask                         (0x00000004)
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_underflow_mask                        (0x00000002)
#define  DC2H_DMA_dc2h_Cap_Status_cap_ddr_over_range_mask                        (0x00000001)
#define  DC2H_DMA_dc2h_Cap_Status_cap_block_2(data)                              (0x00003000&((data)<<12))
#define  DC2H_DMA_dc2h_Cap_Status_cap_over_size(data)                            (0x00000800&((data)<<11))
#define  DC2H_DMA_dc2h_Cap_Status_cap_under_size(data)                           (0x00000400&((data)<<10))
#define  DC2H_DMA_dc2h_Cap_Status_vs_rising_occur(data)                          (0x00000100&((data)<<8))
#define  DC2H_DMA_dc2h_Cap_Status_cap_block(data)                                (0x00000040&((data)<<6))
#define  DC2H_DMA_dc2h_Cap_Status_cap_field(data)                                (0x00000020&((data)<<5))
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_full(data)                            (0x00000010&((data)<<4))
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_empty(data)                           (0x00000008&((data)<<3))
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_overflow(data)                        (0x00000004&((data)<<2))
#define  DC2H_DMA_dc2h_Cap_Status_cap_fifo_underflow(data)                       (0x00000002&((data)<<1))
#define  DC2H_DMA_dc2h_Cap_Status_cap_ddr_over_range(data)                       (0x00000001&(data))
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_block_2(data)                          ((0x00003000&(data))>>12)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_over_size(data)                        ((0x00000800&(data))>>11)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_under_size(data)                       ((0x00000400&(data))>>10)
#define  DC2H_DMA_dc2h_Cap_Status_get_vs_rising_occur(data)                      ((0x00000100&(data))>>8)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_block(data)                            ((0x00000040&(data))>>6)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_field(data)                            ((0x00000020&(data))>>5)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_fifo_full(data)                        ((0x00000010&(data))>>4)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_fifo_empty(data)                       ((0x00000008&(data))>>3)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_fifo_overflow(data)                    ((0x00000004&(data))>>2)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_fifo_underflow(data)                   ((0x00000002&(data))>>1)
#define  DC2H_DMA_dc2h_Cap_Status_get_cap_ddr_over_range(data)                   (0x00000001&(data))

#define  DC2H_DMA_dc2h_Cap_CRC_CTRL                                              0x18029DAC
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_reg_addr                                     "0xB8029DAC"
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_reg                                          0xB8029DAC
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_inst_addr                                    "0x000B"
#define  set_DC2H_DMA_dc2h_Cap_CRC_CTRL_reg(data)                                (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_CRC_CTRL_reg)=data)
#define  get_DC2H_DMA_dc2h_Cap_CRC_CTRL_reg                                      (*((volatile unsigned int*)DC2H_DMA_dc2h_Cap_CRC_CTRL_reg))
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_l_crc_conti_shift                            (1)
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_l_crc_start_shift                            (0)
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_l_crc_conti_mask                             (0x00000002)
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_l_crc_start_mask                             (0x00000001)
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_l_crc_conti(data)                            (0x00000002&((data)<<1))
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_l_crc_start(data)                            (0x00000001&(data))
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_get_l_crc_conti(data)                        ((0x00000002&(data))>>1)
#define  DC2H_DMA_dc2h_Cap_CRC_CTRL_get_l_crc_start(data)                        (0x00000001&(data))

#define  DC2H_DMA_dc2h_CRC_Result                                                0x18029DB0
#define  DC2H_DMA_dc2h_CRC_Result_reg_addr                                       "0xB8029DB0"
#define  DC2H_DMA_dc2h_CRC_Result_reg                                            0xB8029DB0
#define  DC2H_DMA_dc2h_CRC_Result_inst_addr                                      "0x000C"
#define  set_DC2H_DMA_dc2h_CRC_Result_reg(data)                                  (*((volatile unsigned int*)DC2H_DMA_dc2h_CRC_Result_reg)=data)
#define  get_DC2H_DMA_dc2h_CRC_Result_reg                                        (*((volatile unsigned int*)DC2H_DMA_dc2h_CRC_Result_reg))
#define  DC2H_DMA_dc2h_CRC_Result_dc2h_seq_crc_result_shift                      (0)
#define  DC2H_DMA_dc2h_CRC_Result_dc2h_seq_crc_result_mask                       (0xFFFFFFFF)
#define  DC2H_DMA_dc2h_CRC_Result_dc2h_seq_crc_result(data)                      (0xFFFFFFFF&(data))
#define  DC2H_DMA_dc2h_CRC_Result_get_dc2h_seq_crc_result(data)                  (0xFFFFFFFF&(data))

#define  DC2H_DMA_dc2h_seq_Interrupt_Enable                                      0x18029DB4
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_reg_addr                             "0xB8029DB4"
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_reg                                  0xB8029DB4
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_inst_addr                            "0x000D"
#define  set_DC2H_DMA_dc2h_seq_Interrupt_Enable_reg(data)                        (*((volatile unsigned int*)DC2H_DMA_dc2h_seq_Interrupt_Enable_reg)=data)
#define  get_DC2H_DMA_dc2h_seq_Interrupt_Enable_reg                              (*((volatile unsigned int*)DC2H_DMA_dc2h_seq_Interrupt_Enable_reg))
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_mem_err_ie_shift                     (2)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_fifo_err_ie_shift                    (1)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_vs_rising_ie_shift                   (0)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_mem_err_ie_mask                      (0x00000004)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_fifo_err_ie_mask                     (0x00000002)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_vs_rising_ie_mask                    (0x00000001)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_mem_err_ie(data)                     (0x00000004&((data)<<2))
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_fifo_err_ie(data)                    (0x00000002&((data)<<1))
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_vs_rising_ie(data)                   (0x00000001&(data))
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_get_mem_err_ie(data)                 ((0x00000004&(data))>>2)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_get_fifo_err_ie(data)                ((0x00000002&(data))>>1)
#define  DC2H_DMA_dc2h_seq_Interrupt_Enable_get_vs_rising_ie(data)               (0x00000001&(data))

#define  DC2H_DMA_dc2h_seq_byte_channel_swap                                     0x18029DB8
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_reg_addr                            "0xB8029DB8"
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_reg                                 0xB8029DB8
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_inst_addr                           "0x000E"
#define  set_DC2H_DMA_dc2h_seq_byte_channel_swap_reg(data)                       (*((volatile unsigned int*)DC2H_DMA_dc2h_seq_byte_channel_swap_reg)=data)
#define  get_DC2H_DMA_dc2h_seq_byte_channel_swap_reg                             (*((volatile unsigned int*)DC2H_DMA_dc2h_seq_byte_channel_swap_reg))
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_channel_swap_shift              (4)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_8byte_swap_shift                (3)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_4byte_swap_shift                (2)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_2byte_swap_shift                (1)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_1byte_swap_shift                (0)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_channel_swap_mask               (0x00000070)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_8byte_swap_mask                 (0x00000008)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_4byte_swap_mask                 (0x00000004)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_2byte_swap_mask                 (0x00000002)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_1byte_swap_mask                 (0x00000001)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_channel_swap(data)              (0x00000070&((data)<<4))
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_8byte_swap(data)                (0x00000008&((data)<<3))
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_4byte_swap(data)                (0x00000004&((data)<<2))
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_2byte_swap(data)                (0x00000002&((data)<<1))
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_dma_1byte_swap(data)                (0x00000001&(data))
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_get_dma_channel_swap(data)          ((0x00000070&(data))>>4)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_get_dma_8byte_swap(data)            ((0x00000008&(data))>>3)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_get_dma_4byte_swap(data)            ((0x00000004&(data))>>2)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_get_dma_2byte_swap(data)            ((0x00000002&(data))>>1)
#define  DC2H_DMA_dc2h_seq_byte_channel_swap_get_dma_1byte_swap(data)            (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC2H_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cap_en:1;
    };
}dc2h_dma_dc2h_seq_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  hact:15;
    };
}dc2h_dma_dc2h_seq_mode_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  triple_buf_en:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  cap_write_rem:7;
    };
}dc2h_dma_dc2h_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  cap_write_num:8;
    };
}dc2h_dma_dc2h_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_up_limit:29;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_dc2h_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_low_limit:29;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_dc2h_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_dc2h_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l2_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_dc2h_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l3_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_dc2h_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}dc2h_dma_dc2h_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}dc2h_dma_dc2h_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  l_crc_start:1;
    };
}dc2h_dma_dc2h_cap_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_seq_crc_result:32;
    };
}dc2h_dma_dc2h_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  vs_rising_ie:1;
    };
}dc2h_dma_dc2h_seq_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_1byte_swap:1;
    };
}dc2h_dma_dc2h_seq_byte_channel_swap_RBUS;

#else //apply LITTLE_ENDIAN

//======DC2H_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rgb_to_argb_en:1;
        RBus_UInt32  argb_swap:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  argb_dummy_data:8;
        RBus_UInt32  res3:16;
    };
}dc2h_dma_dc2h_seq_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  vact:16;
    };
}dc2h_dma_dc2h_seq_mode_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  res4:6;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  triple_buf_en:1;
    };
}dc2h_dma_dc2h_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:8;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  res1:17;
    };
}dc2h_dma_dc2h_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_up_limit:29;
    };
}dc2h_dma_dc2h_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_low_limit:29;
    };
}dc2h_dma_dc2h_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start:29;
    };
}dc2h_dma_dc2h_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l2_start:29;
    };
}dc2h_dma_dc2h_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l3_start:29;
    };
}dc2h_dma_dc2h_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start_db:29;
    };
}dc2h_dma_dc2h_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  res3:18;
    };
}dc2h_dma_dc2h_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_start:1;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  res1:30;
    };
}dc2h_dma_dc2h_cap_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc2h_seq_crc_result:32;
    };
}dc2h_dma_dc2h_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_rising_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  res1:29;
    };
}dc2h_dma_dc2h_seq_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_1byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  res1:25;
    };
}dc2h_dma_dc2h_seq_byte_channel_swap_RBUS;




#endif 


#endif 
