/**
* @file Mac5-DesignSpec-TVEDMA
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TVE_DMA_REG_H_
#define _RBUS_TVE_DMA_REG_H_

#include "rbus_types.h"



//  TVE_DMA Register Address
#define  TVE_DMA_TVE_VDDMA_CTRL                                                  0x1801F400
#define  TVE_DMA_TVE_VDDMA_CTRL_reg_addr                                         "0xB801F400"
#define  TVE_DMA_TVE_VDDMA_CTRL_reg                                              0xB801F400
#define  TVE_DMA_TVE_VDDMA_CTRL_inst_addr                                        "0x0000"
#define  set_TVE_DMA_TVE_VDDMA_CTRL_reg(data)                                    (*((volatile unsigned int*)TVE_DMA_TVE_VDDMA_CTRL_reg)=data)
#define  get_TVE_DMA_TVE_VDDMA_CTRL_reg                                          (*((volatile unsigned int*)TVE_DMA_TVE_VDDMA_CTRL_reg))
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_4byte_swap_shift                (16)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_y_cr_swap_shift                 (12)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_seq_sel_shift                   (8)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_buf_ctrl_shift                         (4)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_buf_sel_shift                          (0)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_4byte_swap_mask                 (0x00010000)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_y_cr_swap_mask                  (0x00001000)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_seq_sel_mask                    (0x00000100)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_buf_ctrl_mask                          (0x00000010)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_buf_sel_mask                           (0x00000001)
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_4byte_swap(data)                (0x00010000&((data)<<16))
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_y_cr_swap(data)                 (0x00001000&((data)<<12))
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_output_seq_sel(data)                   (0x00000100&((data)<<8))
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_buf_ctrl(data)                         (0x00000010&((data)<<4))
#define  TVE_DMA_TVE_VDDMA_CTRL_tve_vddma_buf_sel(data)                          (0x00000001&(data))
#define  TVE_DMA_TVE_VDDMA_CTRL_get_tve_vddma_output_4byte_swap(data)            ((0x00010000&(data))>>16)
#define  TVE_DMA_TVE_VDDMA_CTRL_get_tve_vddma_output_y_cr_swap(data)             ((0x00001000&(data))>>12)
#define  TVE_DMA_TVE_VDDMA_CTRL_get_tve_vddma_output_seq_sel(data)               ((0x00000100&(data))>>8)
#define  TVE_DMA_TVE_VDDMA_CTRL_get_tve_vddma_buf_ctrl(data)                     ((0x00000010&(data))>>4)
#define  TVE_DMA_TVE_VDDMA_CTRL_get_tve_vddma_buf_sel(data)                      (0x00000001&(data))

#define  TVE_DMA_TVE_VDDMA                                                       0x1801F404
#define  TVE_DMA_TVE_VDDMA_reg_addr                                              "0xB801F404"
#define  TVE_DMA_TVE_VDDMA_reg                                                   0xB801F404
#define  TVE_DMA_TVE_VDDMA_inst_addr                                             "0x0001"
#define  set_TVE_DMA_TVE_VDDMA_reg(data)                                         (*((volatile unsigned int*)TVE_DMA_TVE_VDDMA_reg)=data)
#define  get_TVE_DMA_TVE_VDDMA_reg                                               (*((volatile unsigned int*)TVE_DMA_TVE_VDDMA_reg))
#define  TVE_DMA_TVE_VDDMA_tve_vddma_waterlvl_shift                              (24)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_num_shift                                   (16)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_length_shift                                (8)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_remain_shift                                (0)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_waterlvl_mask                               (0x3F000000)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_num_mask                                    (0x00FF0000)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_length_mask                                 (0x0000FF00)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_remain_mask                                 (0x000000FF)
#define  TVE_DMA_TVE_VDDMA_tve_vddma_waterlvl(data)                              (0x3F000000&((data)<<24))
#define  TVE_DMA_TVE_VDDMA_tve_vddma_num(data)                                   (0x00FF0000&((data)<<16))
#define  TVE_DMA_TVE_VDDMA_tve_vddma_length(data)                                (0x0000FF00&((data)<<8))
#define  TVE_DMA_TVE_VDDMA_tve_vddma_remain(data)                                (0x000000FF&(data))
#define  TVE_DMA_TVE_VDDMA_get_tve_vddma_waterlvl(data)                          ((0x3F000000&(data))>>24)
#define  TVE_DMA_TVE_VDDMA_get_tve_vddma_num(data)                               ((0x00FF0000&(data))>>16)
#define  TVE_DMA_TVE_VDDMA_get_tve_vddma_length(data)                            ((0x0000FF00&(data))>>8)
#define  TVE_DMA_TVE_VDDMA_get_tve_vddma_remain(data)                            (0x000000FF&(data))

#define  TVE_DMA_TVEVDDMA_LINESTEP                                               0x1801F408
#define  TVE_DMA_TVEVDDMA_LINESTEP_reg_addr                                      "0xB801F408"
#define  TVE_DMA_TVEVDDMA_LINESTEP_reg                                           0xB801F408
#define  TVE_DMA_TVEVDDMA_LINESTEP_inst_addr                                     "0x0002"
#define  set_TVE_DMA_TVEVDDMA_LINESTEP_reg(data)                                 (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_LINESTEP_reg)=data)
#define  get_TVE_DMA_TVEVDDMA_LINESTEP_reg                                       (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_LINESTEP_reg))
#define  TVE_DMA_TVEVDDMA_LINESTEP_tve_vddma_line_step_shift                     (0)
#define  TVE_DMA_TVEVDDMA_LINESTEP_tve_vddma_line_step_mask                      (0x1FFFFFFF)
#define  TVE_DMA_TVEVDDMA_LINESTEP_tve_vddma_line_step(data)                     (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVDDMA_LINESTEP_get_tve_vddma_line_step(data)                 (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEVDDMA_SATRT0                                                 0x1801F410
#define  TVE_DMA_TVEVDDMA_SATRT0_reg_addr                                        "0xB801F410"
#define  TVE_DMA_TVEVDDMA_SATRT0_reg                                             0xB801F410
#define  TVE_DMA_TVEVDDMA_SATRT0_inst_addr                                       "0x0003"
#define  set_TVE_DMA_TVEVDDMA_SATRT0_reg(data)                                   (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT0_reg)=data)
#define  get_TVE_DMA_TVEVDDMA_SATRT0_reg                                         (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT0_reg))
#define  TVE_DMA_TVEVDDMA_SATRT0_tve_vddma_start_addr0_shift                     (0)
#define  TVE_DMA_TVEVDDMA_SATRT0_tve_vddma_start_addr0_mask                      (0x1FFFFFFF)
#define  TVE_DMA_TVEVDDMA_SATRT0_tve_vddma_start_addr0(data)                     (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVDDMA_SATRT0_get_tve_vddma_start_addr0(data)                 (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEVDDMA_SATRT1                                                 0x1801F414
#define  TVE_DMA_TVEVDDMA_SATRT1_reg_addr                                        "0xB801F414"
#define  TVE_DMA_TVEVDDMA_SATRT1_reg                                             0xB801F414
#define  TVE_DMA_TVEVDDMA_SATRT1_inst_addr                                       "0x0004"
#define  set_TVE_DMA_TVEVDDMA_SATRT1_reg(data)                                   (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT1_reg)=data)
#define  get_TVE_DMA_TVEVDDMA_SATRT1_reg                                         (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT1_reg))
#define  TVE_DMA_TVEVDDMA_SATRT1_tve_vddma_start_addr1_shift                     (0)
#define  TVE_DMA_TVEVDDMA_SATRT1_tve_vddma_start_addr1_mask                      (0x1FFFFFFF)
#define  TVE_DMA_TVEVDDMA_SATRT1_tve_vddma_start_addr1(data)                     (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVDDMA_SATRT1_get_tve_vddma_start_addr1(data)                 (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEVDDMA_SATRT2                                                 0x1801F418
#define  TVE_DMA_TVEVDDMA_SATRT2_reg_addr                                        "0xB801F418"
#define  TVE_DMA_TVEVDDMA_SATRT2_reg                                             0xB801F418
#define  TVE_DMA_TVEVDDMA_SATRT2_inst_addr                                       "0x0005"
#define  set_TVE_DMA_TVEVDDMA_SATRT2_reg(data)                                   (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT2_reg)=data)
#define  get_TVE_DMA_TVEVDDMA_SATRT2_reg                                         (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT2_reg))
#define  TVE_DMA_TVEVDDMA_SATRT2_tve_vddma_start_addr2_shift                     (0)
#define  TVE_DMA_TVEVDDMA_SATRT2_tve_vddma_start_addr2_mask                      (0x1FFFFFFF)
#define  TVE_DMA_TVEVDDMA_SATRT2_tve_vddma_start_addr2(data)                     (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVDDMA_SATRT2_get_tve_vddma_start_addr2(data)                 (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEVDDMA_SATRT3                                                 0x1801F41C
#define  TVE_DMA_TVEVDDMA_SATRT3_reg_addr                                        "0xB801F41C"
#define  TVE_DMA_TVEVDDMA_SATRT3_reg                                             0xB801F41C
#define  TVE_DMA_TVEVDDMA_SATRT3_inst_addr                                       "0x0006"
#define  set_TVE_DMA_TVEVDDMA_SATRT3_reg(data)                                   (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT3_reg)=data)
#define  get_TVE_DMA_TVEVDDMA_SATRT3_reg                                         (*((volatile unsigned int*)TVE_DMA_TVEVDDMA_SATRT3_reg))
#define  TVE_DMA_TVEVDDMA_SATRT3_tve_vddma_start_addr3_shift                     (0)
#define  TVE_DMA_TVEVDDMA_SATRT3_tve_vddma_start_addr3_mask                      (0x1FFFFFFF)
#define  TVE_DMA_TVEVDDMA_SATRT3_tve_vddma_start_addr3(data)                     (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVDDMA_SATRT3_get_tve_vddma_start_addr3(data)                 (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEVBIDMA_CTRL                                                  0x1801F420
#define  TVE_DMA_TVEVBIDMA_CTRL_reg_addr                                         "0xB801F420"
#define  TVE_DMA_TVEVBIDMA_CTRL_reg                                              0xB801F420
#define  TVE_DMA_TVEVBIDMA_CTRL_inst_addr                                        "0x0007"
#define  set_TVE_DMA_TVEVBIDMA_CTRL_reg(data)                                    (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_CTRL_reg)=data)
#define  get_TVE_DMA_TVEVBIDMA_CTRL_reg                                          (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_CTRL_reg))
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbi_dma_en_shift                             (17)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_output_4byte_swap_shift               (16)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_endian_shift                          (12)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_buf_num_shift                         (8)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_fetch_num_shift                       (4)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_total_line_shift                      (0)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbi_dma_en_mask                              (0x00020000)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_output_4byte_swap_mask                (0x00010000)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_endian_mask                           (0x00001000)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_buf_num_mask                          (0x00000F00)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_fetch_num_mask                        (0x00000010)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_total_line_mask                       (0x00000001)
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbi_dma_en(data)                             (0x00020000&((data)<<17))
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_output_4byte_swap(data)               (0x00010000&((data)<<16))
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_endian(data)                          (0x00001000&((data)<<12))
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_buf_num(data)                         (0x00000F00&((data)<<8))
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_fetch_num(data)                       (0x00000010&((data)<<4))
#define  TVE_DMA_TVEVBIDMA_CTRL_tve_vbidma_total_line(data)                      (0x00000001&(data))
#define  TVE_DMA_TVEVBIDMA_CTRL_get_tve_vbi_dma_en(data)                         ((0x00020000&(data))>>17)
#define  TVE_DMA_TVEVBIDMA_CTRL_get_tve_vbidma_output_4byte_swap(data)           ((0x00010000&(data))>>16)
#define  TVE_DMA_TVEVBIDMA_CTRL_get_tve_vbidma_endian(data)                      ((0x00001000&(data))>>12)
#define  TVE_DMA_TVEVBIDMA_CTRL_get_tve_vbidma_buf_num(data)                     ((0x00000F00&(data))>>8)
#define  TVE_DMA_TVEVBIDMA_CTRL_get_tve_vbidma_fetch_num(data)                   ((0x00000010&(data))>>4)
#define  TVE_DMA_TVEVBIDMA_CTRL_get_tve_vbidma_total_line(data)                  (0x00000001&(data))

#define  TVE_DMA_TVEVBIDMA_START                                                 0x1801F424
#define  TVE_DMA_TVEVBIDMA_START_reg_addr                                        "0xB801F424"
#define  TVE_DMA_TVEVBIDMA_START_reg                                             0xB801F424
#define  TVE_DMA_TVEVBIDMA_START_inst_addr                                       "0x0008"
#define  set_TVE_DMA_TVEVBIDMA_START_reg(data)                                   (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_START_reg)=data)
#define  get_TVE_DMA_TVEVBIDMA_START_reg                                         (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_START_reg))
#define  TVE_DMA_TVEVBIDMA_START_tve_vbidma_edge_trig_shift                      (29)
#define  TVE_DMA_TVEVBIDMA_START_tve_vbidma_start_addr_shift                     (0)
#define  TVE_DMA_TVEVBIDMA_START_tve_vbidma_edge_trig_mask                       (0x20000000)
#define  TVE_DMA_TVEVBIDMA_START_tve_vbidma_start_addr_mask                      (0x1FFFFFFF)
#define  TVE_DMA_TVEVBIDMA_START_tve_vbidma_edge_trig(data)                      (0x20000000&((data)<<29))
#define  TVE_DMA_TVEVBIDMA_START_tve_vbidma_start_addr(data)                     (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVBIDMA_START_get_tve_vbidma_edge_trig(data)                  ((0x20000000&(data))>>29)
#define  TVE_DMA_TVEVBIDMA_START_get_tve_vbidma_start_addr(data)                 (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEVBIDMA_READ_WINDOW                                           0x1801F428
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_reg_addr                                  "0xB801F428"
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_reg                                       0xB801F428
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_inst_addr                                 "0x0009"
#define  set_TVE_DMA_TVEVBIDMA_READ_WINDOW_reg(data)                             (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_READ_WINDOW_reg)=data)
#define  get_TVE_DMA_TVEVBIDMA_READ_WINDOW_reg                                   (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_READ_WINDOW_reg))
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_tve_vbi_read_start_shift                  (12)
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_tve_vbi_read_end_shift                    (0)
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_tve_vbi_read_start_mask                   (0x007FF000)
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_tve_vbi_read_end_mask                     (0x000007FF)
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_tve_vbi_read_start(data)                  (0x007FF000&((data)<<12))
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_tve_vbi_read_end(data)                    (0x000007FF&(data))
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_get_tve_vbi_read_start(data)              ((0x007FF000&(data))>>12)
#define  TVE_DMA_TVEVBIDMA_READ_WINDOW_get_tve_vbi_read_end(data)                (0x000007FF&(data))

#define  TVE_DMA_TVEVBIDMA_START_STATUS                                          0x1801F42C
#define  TVE_DMA_TVEVBIDMA_START_STATUS_reg_addr                                 "0xB801F42C"
#define  TVE_DMA_TVEVBIDMA_START_STATUS_reg                                      0xB801F42C
#define  TVE_DMA_TVEVBIDMA_START_STATUS_inst_addr                                "0x000A"
#define  set_TVE_DMA_TVEVBIDMA_START_STATUS_reg(data)                            (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_START_STATUS_reg)=data)
#define  get_TVE_DMA_TVEVBIDMA_START_STATUS_reg                                  (*((volatile unsigned int*)TVE_DMA_TVEVBIDMA_START_STATUS_reg))
#define  TVE_DMA_TVEVBIDMA_START_STATUS_tve_vbidma_start_addr_now_shift          (0)
#define  TVE_DMA_TVEVBIDMA_START_STATUS_tve_vbidma_start_addr_now_mask           (0x1FFFFFFF)
#define  TVE_DMA_TVEVBIDMA_START_STATUS_tve_vbidma_start_addr_now(data)          (0x1FFFFFFF&(data))
#define  TVE_DMA_TVEVBIDMA_START_STATUS_get_tve_vbidma_start_addr_now(data)      (0x1FFFFFFF&(data))

#define  TVE_DMA_TVEDMA_FIFOSTATUS                                               0x1801F430
#define  TVE_DMA_TVEDMA_FIFOSTATUS_reg_addr                                      "0xB801F430"
#define  TVE_DMA_TVEDMA_FIFOSTATUS_reg                                           0xB801F430
#define  TVE_DMA_TVEDMA_FIFOSTATUS_inst_addr                                     "0x000B"
#define  set_TVE_DMA_TVEDMA_FIFOSTATUS_reg(data)                                 (*((volatile unsigned int*)TVE_DMA_TVEDMA_FIFOSTATUS_reg)=data)
#define  get_TVE_DMA_TVEDMA_FIFOSTATUS_reg                                       (*((volatile unsigned int*)TVE_DMA_TVEDMA_FIFOSTATUS_reg))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_full_int_shift                    (7)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_empty_int_shift                   (6)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_full_shift                        (5)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_empty_shift                       (4)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_full_int_shift                     (3)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_empty_int_shift                    (2)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_full_shift                         (1)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_empty_shift                        (0)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_full_int_mask                     (0x00000080)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_empty_int_mask                    (0x00000040)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_full_mask                         (0x00000020)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_empty_mask                        (0x00000010)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_full_int_mask                      (0x00000008)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_empty_int_mask                     (0x00000004)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_full_mask                          (0x00000002)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_empty_mask                         (0x00000001)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_full_int(data)                    (0x00000080&((data)<<7))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_empty_int(data)                   (0x00000040&((data)<<6))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_full(data)                        (0x00000020&((data)<<5))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vbidma_fifo_empty(data)                       (0x00000010&((data)<<4))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_full_int(data)                     (0x00000008&((data)<<3))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_empty_int(data)                    (0x00000004&((data)<<2))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_full(data)                         (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_vddma_fifo_empty(data)                        (0x00000001&(data))
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vbidma_fifo_full_int(data)                ((0x00000080&(data))>>7)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vbidma_fifo_empty_int(data)               ((0x00000040&(data))>>6)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vbidma_fifo_full(data)                    ((0x00000020&(data))>>5)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vbidma_fifo_empty(data)                   ((0x00000010&(data))>>4)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vddma_fifo_full_int(data)                 ((0x00000008&(data))>>3)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vddma_fifo_empty_int(data)                ((0x00000004&(data))>>2)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vddma_fifo_full(data)                     ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_FIFOSTATUS_get_vddma_fifo_empty(data)                    (0x00000001&(data))

#define  TVE_DMA_TVEDMA_BIST_DVS                                                 0x1801F440
#define  TVE_DMA_TVEDMA_BIST_DVS_reg_addr                                        "0xB801F440"
#define  TVE_DMA_TVEDMA_BIST_DVS_reg                                             0xB801F440
#define  TVE_DMA_TVEDMA_BIST_DVS_inst_addr                                       "0x000C"
#define  set_TVE_DMA_TVEDMA_BIST_DVS_reg(data)                                   (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_DVS_reg)=data)
#define  get_TVE_DMA_TVEDMA_BIST_DVS_reg                                         (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_DVS_reg))
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_testrwm_shift                             (5)
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_tve_dvse_shift                            (4)
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_tve_dvs_shift                             (0)
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_testrwm_mask                              (0x00000020)
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_tve_dvse_mask                             (0x00000010)
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_tve_dvs_mask                              (0x0000000F)
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_testrwm(data)                             (0x00000020&((data)<<5))
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_tve_dvse(data)                            (0x00000010&((data)<<4))
#define  TVE_DMA_TVEDMA_BIST_DVS_mbist_tve_dvs(data)                             (0x0000000F&(data))
#define  TVE_DMA_TVEDMA_BIST_DVS_get_mbist_testrwm(data)                         ((0x00000020&(data))>>5)
#define  TVE_DMA_TVEDMA_BIST_DVS_get_mbist_tve_dvse(data)                        ((0x00000010&(data))>>4)
#define  TVE_DMA_TVEDMA_BIST_DVS_get_mbist_tve_dvs(data)                         (0x0000000F&(data))

#define  TVE_DMA_TVEDMA_BIST_MODE                                                0x1801F444
#define  TVE_DMA_TVEDMA_BIST_MODE_reg_addr                                       "0xB801F444"
#define  TVE_DMA_TVEDMA_BIST_MODE_reg                                            0xB801F444
#define  TVE_DMA_TVEDMA_BIST_MODE_inst_addr                                      "0x000D"
#define  set_TVE_DMA_TVEDMA_BIST_MODE_reg(data)                                  (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_MODE_reg)=data)
#define  get_TVE_DMA_TVEDMA_BIST_MODE_reg                                        (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_MODE_reg))
#define  TVE_DMA_TVEDMA_BIST_MODE_bist_mode_vbidma_shift                         (1)
#define  TVE_DMA_TVEDMA_BIST_MODE_bist_mode_vddma_shift                          (0)
#define  TVE_DMA_TVEDMA_BIST_MODE_bist_mode_vbidma_mask                          (0x00000002)
#define  TVE_DMA_TVEDMA_BIST_MODE_bist_mode_vddma_mask                           (0x00000001)
#define  TVE_DMA_TVEDMA_BIST_MODE_bist_mode_vbidma(data)                         (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_BIST_MODE_bist_mode_vddma(data)                          (0x00000001&(data))
#define  TVE_DMA_TVEDMA_BIST_MODE_get_bist_mode_vbidma(data)                     ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_BIST_MODE_get_bist_mode_vddma(data)                      (0x00000001&(data))

#define  TVE_DMA_TVEDMA_DRF_BIST_MODE                                            0x1801F448
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_reg_addr                                   "0xB801F448"
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_reg                                        0xB801F448
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_inst_addr                                  "0x000E"
#define  set_TVE_DMA_TVEDMA_DRF_BIST_MODE_reg(data)                              (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_MODE_reg)=data)
#define  get_TVE_DMA_TVEDMA_DRF_BIST_MODE_reg                                    (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_MODE_reg))
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_shift                 (1)
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_drf_bist_mode_vddma_shift                  (0)
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_drf_bist_mode_vbidma_mask                  (0x00000002)
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_drf_bist_mode_vddma_mask                   (0x00000001)
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_drf_bist_mode_vbidma(data)                 (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_drf_bist_mode_vddma(data)                  (0x00000001&(data))
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_get_drf_bist_mode_vbidma(data)             ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_DRF_BIST_MODE_get_drf_bist_mode_vddma(data)              (0x00000001&(data))

#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME                                          0x1801F44C
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_reg_addr                                 "0xB801F44C"
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_reg                                      0xB801F44C
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_inst_addr                                "0x000F"
#define  set_TVE_DMA_TVEDMA_DRF_TEST_RESUME_reg(data)                            (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_TEST_RESUME_reg)=data)
#define  get_TVE_DMA_TVEDMA_DRF_TEST_RESUME_reg                                  (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_TEST_RESUME_reg))
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_shift             (1)
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_drf_test_resume_vddma_shift              (0)
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_drf_test_resume_vbidma_mask              (0x00000002)
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_drf_test_resume_vddma_mask               (0x00000001)
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_drf_test_resume_vbidma(data)             (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_drf_test_resume_vddma(data)              (0x00000001&(data))
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_get_drf_test_resume_vbidma(data)         ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_DRF_TEST_RESUME_get_drf_test_resume_vddma(data)          (0x00000001&(data))

#define  TVE_DMA_TVEDMA_LS_CNTL                                                  0x1801F450
#define  TVE_DMA_TVEDMA_LS_CNTL_reg_addr                                         "0xB801F450"
#define  TVE_DMA_TVEDMA_LS_CNTL_reg                                              0xB801F450
#define  TVE_DMA_TVEDMA_LS_CNTL_inst_addr                                        "0x0010"
#define  set_TVE_DMA_TVEDMA_LS_CNTL_reg(data)                                    (*((volatile unsigned int*)TVE_DMA_TVEDMA_LS_CNTL_reg)=data)
#define  get_TVE_DMA_TVEDMA_LS_CNTL_reg                                          (*((volatile unsigned int*)TVE_DMA_TVEDMA_LS_CNTL_reg))
#define  TVE_DMA_TVEDMA_LS_CNTL_mbist_ls_cntl_shift                              (0)
#define  TVE_DMA_TVEDMA_LS_CNTL_mbist_ls_cntl_mask                               (0x00000001)
#define  TVE_DMA_TVEDMA_LS_CNTL_mbist_ls_cntl(data)                              (0x00000001&(data))
#define  TVE_DMA_TVEDMA_LS_CNTL_get_mbist_ls_cntl(data)                          (0x00000001&(data))

#define  TVE_DMA_TVEDMA_BIST_DONE                                                0x1801F454
#define  TVE_DMA_TVEDMA_BIST_DONE_reg_addr                                       "0xB801F454"
#define  TVE_DMA_TVEDMA_BIST_DONE_reg                                            0xB801F454
#define  TVE_DMA_TVEDMA_BIST_DONE_inst_addr                                      "0x0011"
#define  set_TVE_DMA_TVEDMA_BIST_DONE_reg(data)                                  (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_DONE_reg)=data)
#define  get_TVE_DMA_TVEDMA_BIST_DONE_reg                                        (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_DONE_reg))
#define  TVE_DMA_TVEDMA_BIST_DONE_bist_done_vbidma_shift                         (1)
#define  TVE_DMA_TVEDMA_BIST_DONE_bist_done_vddma_shift                          (0)
#define  TVE_DMA_TVEDMA_BIST_DONE_bist_done_vbidma_mask                          (0x00000002)
#define  TVE_DMA_TVEDMA_BIST_DONE_bist_done_vddma_mask                           (0x00000001)
#define  TVE_DMA_TVEDMA_BIST_DONE_bist_done_vbidma(data)                         (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_BIST_DONE_bist_done_vddma(data)                          (0x00000001&(data))
#define  TVE_DMA_TVEDMA_BIST_DONE_get_bist_done_vbidma(data)                     ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_BIST_DONE_get_bist_done_vddma(data)                      (0x00000001&(data))

#define  TVE_DMA_TVEDMA_DRF_BIST_DONE                                            0x1801F458
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_reg_addr                                   "0xB801F458"
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_reg                                        0xB801F458
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_inst_addr                                  "0x0012"
#define  set_TVE_DMA_TVEDMA_DRF_BIST_DONE_reg(data)                              (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_DONE_reg)=data)
#define  get_TVE_DMA_TVEDMA_DRF_BIST_DONE_reg                                    (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_DONE_reg))
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_drf_bist_done_vbidma_shift                 (1)
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_drf_bist_done_vddma_shift                  (0)
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_drf_bist_done_vbidma_mask                  (0x00000002)
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_drf_bist_done_vddma_mask                   (0x00000001)
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_drf_bist_done_vbidma(data)                 (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_drf_bist_done_vddma(data)                  (0x00000001&(data))
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_get_drf_bist_done_vbidma(data)             ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_DRF_BIST_DONE_get_drf_bist_done_vddma(data)              (0x00000001&(data))

#define  TVE_DMA_TVEDMA_BIST_FAIL                                                0x1801F45C
#define  TVE_DMA_TVEDMA_BIST_FAIL_reg_addr                                       "0xB801F45C"
#define  TVE_DMA_TVEDMA_BIST_FAIL_reg                                            0xB801F45C
#define  TVE_DMA_TVEDMA_BIST_FAIL_inst_addr                                      "0x0013"
#define  set_TVE_DMA_TVEDMA_BIST_FAIL_reg(data)                                  (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_FAIL_reg)=data)
#define  get_TVE_DMA_TVEDMA_BIST_FAIL_reg                                        (*((volatile unsigned int*)TVE_DMA_TVEDMA_BIST_FAIL_reg))
#define  TVE_DMA_TVEDMA_BIST_FAIL_bist_fail_vbidma_shift                         (1)
#define  TVE_DMA_TVEDMA_BIST_FAIL_bist_fail_vddma_shift                          (0)
#define  TVE_DMA_TVEDMA_BIST_FAIL_bist_fail_vbidma_mask                          (0x00000002)
#define  TVE_DMA_TVEDMA_BIST_FAIL_bist_fail_vddma_mask                           (0x00000001)
#define  TVE_DMA_TVEDMA_BIST_FAIL_bist_fail_vbidma(data)                         (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_BIST_FAIL_bist_fail_vddma(data)                          (0x00000001&(data))
#define  TVE_DMA_TVEDMA_BIST_FAIL_get_bist_fail_vbidma(data)                     ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_BIST_FAIL_get_bist_fail_vddma(data)                      (0x00000001&(data))

#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL                                            0x1801F460
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_reg_addr                                   "0xB801F460"
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_reg                                        0xB801F460
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_inst_addr                                  "0x0014"
#define  set_TVE_DMA_TVEDMA_DRF_BIST_FAIL_reg(data)                              (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_FAIL_reg)=data)
#define  get_TVE_DMA_TVEDMA_DRF_BIST_FAIL_reg                                    (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_FAIL_reg))
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_shift                 (1)
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_drf_bist_fail_vddma_shift                  (0)
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma_mask                  (0x00000002)
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_drf_bist_fail_vddma_mask                   (0x00000001)
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_drf_bist_fail_vbidma(data)                 (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_drf_bist_fail_vddma(data)                  (0x00000001&(data))
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_get_drf_bist_fail_vbidma(data)             ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_DRF_BIST_FAIL_get_drf_bist_fail_vddma(data)              (0x00000001&(data))

#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE                                           0x1801F464
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_reg_addr                                  "0xB801F464"
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_reg                                       0xB801F464
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_inst_addr                                 "0x0015"
#define  set_TVE_DMA_TVEDMA_DRF_BIST_PAUSE_reg(data)                             (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_PAUSE_reg)=data)
#define  get_TVE_DMA_TVEDMA_DRF_BIST_PAUSE_reg                                   (*((volatile unsigned int*)TVE_DMA_TVEDMA_DRF_BIST_PAUSE_reg))
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_shift              (1)
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_drf_start_pause_vddma_shift               (0)
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma_mask               (0x00000002)
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_drf_start_pause_vddma_mask                (0x00000001)
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_drf_start_pause_vbidma(data)              (0x00000002&((data)<<1))
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_drf_start_pause_vddma(data)               (0x00000001&(data))
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_get_drf_start_pause_vbidma(data)          ((0x00000002&(data))>>1)
#define  TVE_DMA_TVEDMA_DRF_BIST_PAUSE_get_drf_start_pause_vddma(data)           (0x00000001&(data))

#define  TVE_DMA_TVECRC                                                          0x1801F470
#define  TVE_DMA_TVECRC_reg_addr                                                 "0xB801F470"
#define  TVE_DMA_TVECRC_reg                                                      0xB801F470
#define  TVE_DMA_TVECRC_inst_addr                                                "0x0016"
#define  set_TVE_DMA_TVECRC_reg(data)                                            (*((volatile unsigned int*)TVE_DMA_TVECRC_reg)=data)
#define  get_TVE_DMA_TVECRC_reg                                                  (*((volatile unsigned int*)TVE_DMA_TVECRC_reg))
#define  TVE_DMA_TVECRC_crc_en_shift                                             (31)
#define  TVE_DMA_TVECRC_mv_go_shift                                              (30)
#define  TVE_DMA_TVECRC_crc_num_count_shift                                      (0)
#define  TVE_DMA_TVECRC_crc_en_mask                                              (0x80000000)
#define  TVE_DMA_TVECRC_mv_go_mask                                               (0x40000000)
#define  TVE_DMA_TVECRC_crc_num_count_mask                                       (0x001FFFFF)
#define  TVE_DMA_TVECRC_crc_en(data)                                             (0x80000000&((data)<<31))
#define  TVE_DMA_TVECRC_mv_go(data)                                              (0x40000000&((data)<<30))
#define  TVE_DMA_TVECRC_crc_num_count(data)                                      (0x001FFFFF&(data))
#define  TVE_DMA_TVECRC_get_crc_en(data)                                         ((0x80000000&(data))>>31)
#define  TVE_DMA_TVECRC_get_mv_go(data)                                          ((0x40000000&(data))>>30)
#define  TVE_DMA_TVECRC_get_crc_num_count(data)                                  (0x001FFFFF&(data))

#define  TVE_DMA_TVECRC_VALUE                                                    0x1801F474
#define  TVE_DMA_TVECRC_VALUE_reg_addr                                           "0xB801F474"
#define  TVE_DMA_TVECRC_VALUE_reg                                                0xB801F474
#define  TVE_DMA_TVECRC_VALUE_inst_addr                                          "0x0017"
#define  set_TVE_DMA_TVECRC_VALUE_reg(data)                                      (*((volatile unsigned int*)TVE_DMA_TVECRC_VALUE_reg)=data)
#define  get_TVE_DMA_TVECRC_VALUE_reg                                            (*((volatile unsigned int*)TVE_DMA_TVECRC_VALUE_reg))
#define  TVE_DMA_TVECRC_VALUE_crc_value_shift                                    (0)
#define  TVE_DMA_TVECRC_VALUE_crc_value_mask                                     (0x0000FFFF)
#define  TVE_DMA_TVECRC_VALUE_crc_value(data)                                    (0x0000FFFF&(data))
#define  TVE_DMA_TVECRC_VALUE_get_crc_value(data)                                (0x0000FFFF&(data))

#define  TVE_DMA_TVE_POWER_EN                                                    0x1801F478
#define  TVE_DMA_TVE_POWER_EN_reg_addr                                           "0xB801F478"
#define  TVE_DMA_TVE_POWER_EN_reg                                                0xB801F478
#define  TVE_DMA_TVE_POWER_EN_inst_addr                                          "0x0018"
#define  set_TVE_DMA_TVE_POWER_EN_reg(data)                                      (*((volatile unsigned int*)TVE_DMA_TVE_POWER_EN_reg)=data)
#define  get_TVE_DMA_TVE_POWER_EN_reg                                            (*((volatile unsigned int*)TVE_DMA_TVE_POWER_EN_reg))
#define  TVE_DMA_TVE_POWER_EN_sync_gen_en_shift                                  (1)
#define  TVE_DMA_TVE_POWER_EN_cvbs_en_shift                                      (0)
#define  TVE_DMA_TVE_POWER_EN_sync_gen_en_mask                                   (0x00000002)
#define  TVE_DMA_TVE_POWER_EN_cvbs_en_mask                                       (0x00000001)
#define  TVE_DMA_TVE_POWER_EN_sync_gen_en(data)                                  (0x00000002&((data)<<1))
#define  TVE_DMA_TVE_POWER_EN_cvbs_en(data)                                      (0x00000001&(data))
#define  TVE_DMA_TVE_POWER_EN_get_sync_gen_en(data)                              ((0x00000002&(data))>>1)
#define  TVE_DMA_TVE_POWER_EN_get_cvbs_en(data)                                  (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TVE_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  tve_vddma_output_4byte_swap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vddma_output_y_cr_swap:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vddma_output_seq_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vddma_buf_ctrl:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  tve_vddma_buf_sel:1;
    };
}tve_dma_tve_vddma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tve_vddma_waterlvl:6;
        RBus_UInt32  tve_vddma_num:8;
        RBus_UInt32  tve_vddma_length:8;
        RBus_UInt32  tve_vddma_remain:8;
    };
}tve_dma_tve_vddma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_line_step:29;
    };
}tve_dma_tvevddma_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr0:29;
    };
}tve_dma_tvevddma_satrt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr1:29;
    };
}tve_dma_tvevddma_satrt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr2:29;
    };
}tve_dma_tvevddma_satrt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_start_addr3:29;
    };
}tve_dma_tvevddma_satrt3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  tve_vbi_dma_en:1;
        RBus_UInt32  tve_vbidma_output_4byte_swap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_endian:1;
        RBus_UInt32  tve_vbidma_buf_num:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_fetch_num:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vbidma_total_line:1;
    };
}tve_dma_tvevbidma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  tve_vbidma_edge_trig:1;
        RBus_UInt32  tve_vbidma_start_addr:29;
    };
}tve_dma_tvevbidma_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tve_vbi_read_start:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  tve_vbi_read_end:11;
    };
}tve_dma_tvevbidma_read_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbidma_start_addr_now:29;
    };
}tve_dma_tvevbidma_start_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  vbidma_fifo_full_int:1;
        RBus_UInt32  vbidma_fifo_empty_int:1;
        RBus_UInt32  vbidma_fifo_full:1;
        RBus_UInt32  vbidma_fifo_empty:1;
        RBus_UInt32  vddma_fifo_full_int:1;
        RBus_UInt32  vddma_fifo_empty_int:1;
        RBus_UInt32  vddma_fifo_full:1;
        RBus_UInt32  vddma_fifo_empty:1;
    };
}tve_dma_tvedma_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  mbist_testrwm:1;
        RBus_UInt32  mbist_tve_dvse:1;
        RBus_UInt32  mbist_tve_dvs:4;
    };
}tve_dma_tvedma_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_mode_vbidma:1;
        RBus_UInt32  bist_mode_vddma:1;
    };
}tve_dma_tvedma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_mode_vbidma:1;
        RBus_UInt32  drf_bist_mode_vddma:1;
    };
}tve_dma_tvedma_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_test_resume_vbidma:1;
        RBus_UInt32  drf_test_resume_vddma:1;
    };
}tve_dma_tvedma_drf_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  mbist_ls_cntl:1;
    };
}tve_dma_tvedma_ls_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_done_vbidma:1;
        RBus_UInt32  bist_done_vddma:1;
    };
}tve_dma_tvedma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_done_vbidma:1;
        RBus_UInt32  drf_bist_done_vddma:1;
    };
}tve_dma_tvedma_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bist_fail_vbidma:1;
        RBus_UInt32  bist_fail_vddma:1;
    };
}tve_dma_tvedma_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_bist_fail_vbidma:1;
        RBus_UInt32  drf_bist_fail_vddma:1;
    };
}tve_dma_tvedma_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drf_start_pause_vbidma:1;
        RBus_UInt32  drf_start_pause_vddma:1;
    };
}tve_dma_tvedma_drf_bist_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_en:1;
        RBus_UInt32  mv_go:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  crc_num_count:21;
    };
}tve_dma_tvecrc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_value:16;
    };
}tve_dma_tvecrc_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  sync_gen_en:1;
        RBus_UInt32  cvbs_en:1;
    };
}tve_dma_tve_power_en_RBUS;

#else //apply LITTLE_ENDIAN

//======TVE_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_buf_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vddma_buf_ctrl:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vddma_output_seq_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vddma_output_y_cr_swap:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  tve_vddma_output_4byte_swap:1;
        RBus_UInt32  res5:15;
    };
}tve_dma_tve_vddma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_remain:8;
        RBus_UInt32  tve_vddma_length:8;
        RBus_UInt32  tve_vddma_num:8;
        RBus_UInt32  tve_vddma_waterlvl:6;
        RBus_UInt32  res1:2;
    };
}tve_dma_tve_vddma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_line_step:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr0:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr1:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr2:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vddma_start_addr3:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevddma_satrt3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_total_line:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  tve_vbidma_fetch_num:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tve_vbidma_buf_num:4;
        RBus_UInt32  tve_vbidma_endian:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tve_vbidma_output_4byte_swap:1;
        RBus_UInt32  tve_vbi_dma_en:1;
        RBus_UInt32  res4:14;
    };
}tve_dma_tvevbidma_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr:29;
        RBus_UInt32  tve_vbidma_edge_trig:1;
        RBus_UInt32  res1:2;
    };
}tve_dma_tvevbidma_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbi_read_end:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  tve_vbi_read_start:11;
        RBus_UInt32  res2:9;
    };
}tve_dma_tvevbidma_read_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tve_vbidma_start_addr_now:29;
        RBus_UInt32  res1:3;
    };
}tve_dma_tvevbidma_start_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vddma_fifo_empty:1;
        RBus_UInt32  vddma_fifo_full:1;
        RBus_UInt32  vddma_fifo_empty_int:1;
        RBus_UInt32  vddma_fifo_full_int:1;
        RBus_UInt32  vbidma_fifo_empty:1;
        RBus_UInt32  vbidma_fifo_full:1;
        RBus_UInt32  vbidma_fifo_empty_int:1;
        RBus_UInt32  vbidma_fifo_full_int:1;
        RBus_UInt32  res1:24;
    };
}tve_dma_tvedma_fifostatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_tve_dvs:4;
        RBus_UInt32  mbist_tve_dvse:1;
        RBus_UInt32  mbist_testrwm:1;
        RBus_UInt32  res1:26;
    };
}tve_dma_tvedma_bist_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode_vddma:1;
        RBus_UInt32  bist_mode_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_mode_vddma:1;
        RBus_UInt32  drf_bist_mode_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_test_resume_vddma:1;
        RBus_UInt32  drf_test_resume_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_test_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbist_ls_cntl:1;
        RBus_UInt32  res1:31;
    };
}tve_dma_tvedma_ls_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done_vddma:1;
        RBus_UInt32  bist_done_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_done_vddma:1;
        RBus_UInt32  drf_bist_done_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_vddma:1;
        RBus_UInt32  bist_fail_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_bist_fail_vddma:1;
        RBus_UInt32  drf_bist_fail_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_start_pause_vddma:1;
        RBus_UInt32  drf_start_pause_vbidma:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tvedma_drf_bist_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_num_count:21;
        RBus_UInt32  res1:9;
        RBus_UInt32  mv_go:1;
        RBus_UInt32  crc_en:1;
    };
}tve_dma_tvecrc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_value:16;
        RBus_UInt32  res1:16;
    };
}tve_dma_tvecrc_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cvbs_en:1;
        RBus_UInt32  sync_gen_en:1;
        RBus_UInt32  res1:30;
    };
}tve_dma_tve_power_en_RBUS;




#endif 


#endif 
