/**
* @file Mac5-DesignSpec-M_Domain_VI
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MDOMAIN_VI_MAIN_REG_H_
#define _RBUS_MDOMAIN_VI_MAIN_REG_H_

#include "rbus_types.h"



//  MDOMAIN_VI_MAIN Register Address
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT                                           0x18027000
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg_addr                                  "0xB8027000"
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg                                       0xB8027000
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_inst_addr                                 "0x0000"
#define  set_MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg(data)                             (*((volatile unsigned int*)MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg)=data)
#define  get_MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg                                   (*((volatile unsigned int*)MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_reg))
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_8byte_shift                          (7)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_4byte_shift                          (6)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_2byte_shift                          (5)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_1byte_shift                          (4)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_data_format_shift                         (0)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_8byte_mask                           (0x00000080)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_4byte_mask                           (0x00000040)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_2byte_mask                           (0x00000020)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_1byte_mask                           (0x00000010)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_data_format_mask                          (0x00000001)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_8byte(data)                          (0x00000080&((data)<<7))
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_4byte(data)                          (0x00000040&((data)<<6))
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_2byte(data)                          (0x00000020&((data)<<5))
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_swap_1byte(data)                          (0x00000010&((data)<<4))
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_data_format(data)                         (0x00000001&(data))
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_get_swap_8byte(data)                      ((0x00000080&(data))>>7)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_get_swap_4byte(data)                      ((0x00000040&(data))>>6)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_get_swap_2byte(data)                      ((0x00000020&(data))>>5)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_get_swap_1byte(data)                      ((0x00000010&(data))>>4)
#define  MDOMAIN_VI_MAIN_V1_OUTPUT_FMT_get_data_format(data)                     (0x00000001&(data))

#define  MDOMAIN_VI_MAIN_CWVH1                                                   0x18027004
#define  MDOMAIN_VI_MAIN_CWVH1_reg_addr                                          "0xB8027004"
#define  MDOMAIN_VI_MAIN_CWVH1_reg                                               0xB8027004
#define  MDOMAIN_VI_MAIN_CWVH1_inst_addr                                         "0x0001"
#define  set_MDOMAIN_VI_MAIN_CWVH1_reg(data)                                     (*((volatile unsigned int*)MDOMAIN_VI_MAIN_CWVH1_reg)=data)
#define  get_MDOMAIN_VI_MAIN_CWVH1_reg                                           (*((volatile unsigned int*)MDOMAIN_VI_MAIN_CWVH1_reg))
#define  MDOMAIN_VI_MAIN_CWVH1_hsize_shift                                       (12)
#define  MDOMAIN_VI_MAIN_CWVH1_vsize_shift                                       (0)
#define  MDOMAIN_VI_MAIN_CWVH1_hsize_mask                                        (0x01FFF000)
#define  MDOMAIN_VI_MAIN_CWVH1_vsize_mask                                        (0x00000FFF)
#define  MDOMAIN_VI_MAIN_CWVH1_hsize(data)                                       (0x01FFF000&((data)<<12))
#define  MDOMAIN_VI_MAIN_CWVH1_vsize(data)                                       (0x00000FFF&(data))
#define  MDOMAIN_VI_MAIN_CWVH1_get_hsize(data)                                   ((0x01FFF000&(data))>>12)
#define  MDOMAIN_VI_MAIN_CWVH1_get_vsize(data)                                   (0x00000FFF&(data))

#define  MDOMAIN_VI_MAIN_CWVH1_2                                                 0x18027008
#define  MDOMAIN_VI_MAIN_CWVH1_2_reg_addr                                        "0xB8027008"
#define  MDOMAIN_VI_MAIN_CWVH1_2_reg                                             0xB8027008
#define  MDOMAIN_VI_MAIN_CWVH1_2_inst_addr                                       "0x0002"
#define  set_MDOMAIN_VI_MAIN_CWVH1_2_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_VI_MAIN_CWVH1_2_reg)=data)
#define  get_MDOMAIN_VI_MAIN_CWVH1_2_reg                                         (*((volatile unsigned int*)MDOMAIN_VI_MAIN_CWVH1_2_reg))
#define  MDOMAIN_VI_MAIN_CWVH1_2_vsize_c_shift                                   (0)
#define  MDOMAIN_VI_MAIN_CWVH1_2_vsize_c_mask                                    (0x00000FFF)
#define  MDOMAIN_VI_MAIN_CWVH1_2_vsize_c(data)                                   (0x00000FFF&(data))
#define  MDOMAIN_VI_MAIN_CWVH1_2_get_vsize_c(data)                               (0x00000FFF&(data))

#define  MDOMAIN_VI_MAIN_DMACTL                                                  0x1802700C
#define  MDOMAIN_VI_MAIN_DMACTL_reg_addr                                         "0xB802700C"
#define  MDOMAIN_VI_MAIN_DMACTL_reg                                              0xB802700C
#define  MDOMAIN_VI_MAIN_DMACTL_inst_addr                                        "0x0003"
#define  set_MDOMAIN_VI_MAIN_DMACTL_reg(data)                                    (*((volatile unsigned int*)MDOMAIN_VI_MAIN_DMACTL_reg)=data)
#define  get_MDOMAIN_VI_MAIN_DMACTL_reg                                          (*((volatile unsigned int*)MDOMAIN_VI_MAIN_DMACTL_reg))
#define  MDOMAIN_VI_MAIN_DMACTL_seq_blk_sel_shift                                (31)
#define  MDOMAIN_VI_MAIN_DMACTL_dummy_30_9_shift                                 (9)
#define  MDOMAIN_VI_MAIN_DMACTL_dmaen1_shift                                     (8)
#define  MDOMAIN_VI_MAIN_DMACTL_bstlen_shift                                     (0)
#define  MDOMAIN_VI_MAIN_DMACTL_seq_blk_sel_mask                                 (0x80000000)
#define  MDOMAIN_VI_MAIN_DMACTL_dummy_30_9_mask                                  (0x7FFFFE00)
#define  MDOMAIN_VI_MAIN_DMACTL_dmaen1_mask                                      (0x00000100)
#define  MDOMAIN_VI_MAIN_DMACTL_bstlen_mask                                      (0x00000007)
#define  MDOMAIN_VI_MAIN_DMACTL_seq_blk_sel(data)                                (0x80000000&((data)<<31))
#define  MDOMAIN_VI_MAIN_DMACTL_dummy_30_9(data)                                 (0x7FFFFE00&((data)<<9))
#define  MDOMAIN_VI_MAIN_DMACTL_dmaen1(data)                                     (0x00000100&((data)<<8))
#define  MDOMAIN_VI_MAIN_DMACTL_bstlen(data)                                     (0x00000007&(data))
#define  MDOMAIN_VI_MAIN_DMACTL_get_seq_blk_sel(data)                            ((0x80000000&(data))>>31)
#define  MDOMAIN_VI_MAIN_DMACTL_get_dummy_30_9(data)                             ((0x7FFFFE00&(data))>>9)
#define  MDOMAIN_VI_MAIN_DMACTL_get_dmaen1(data)                                 ((0x00000100&(data))>>8)
#define  MDOMAIN_VI_MAIN_DMACTL_get_bstlen(data)                                 (0x00000007&(data))

#define  MDOMAIN_VI_MAIN_Y1BUF                                                   0x18027010
#define  MDOMAIN_VI_MAIN_Y1BUF_reg_addr                                          "0xB8027010"
#define  MDOMAIN_VI_MAIN_Y1BUF_reg                                               0xB8027010
#define  MDOMAIN_VI_MAIN_Y1BUF_inst_addr                                         "0x0004"
#define  set_MDOMAIN_VI_MAIN_Y1BUF_reg(data)                                     (*((volatile unsigned int*)MDOMAIN_VI_MAIN_Y1BUF_reg)=data)
#define  get_MDOMAIN_VI_MAIN_Y1BUF_reg                                           (*((volatile unsigned int*)MDOMAIN_VI_MAIN_Y1BUF_reg))
#define  MDOMAIN_VI_MAIN_Y1BUF_y_water_lvl_shift                                 (10)
#define  MDOMAIN_VI_MAIN_Y1BUF_y_water_lvl_mask                                  (0x0003FC00)
#define  MDOMAIN_VI_MAIN_Y1BUF_y_water_lvl(data)                                 (0x0003FC00&((data)<<10))
#define  MDOMAIN_VI_MAIN_Y1BUF_get_y_water_lvl(data)                             ((0x0003FC00&(data))>>10)

#define  MDOMAIN_VI_MAIN_C1BUF                                                   0x18027014
#define  MDOMAIN_VI_MAIN_C1BUF_reg_addr                                          "0xB8027014"
#define  MDOMAIN_VI_MAIN_C1BUF_reg                                               0xB8027014
#define  MDOMAIN_VI_MAIN_C1BUF_inst_addr                                         "0x0005"
#define  set_MDOMAIN_VI_MAIN_C1BUF_reg(data)                                     (*((volatile unsigned int*)MDOMAIN_VI_MAIN_C1BUF_reg)=data)
#define  get_MDOMAIN_VI_MAIN_C1BUF_reg                                           (*((volatile unsigned int*)MDOMAIN_VI_MAIN_C1BUF_reg))
#define  MDOMAIN_VI_MAIN_C1BUF_c_water_lvl_shift                                 (20)
#define  MDOMAIN_VI_MAIN_C1BUF_c_water_lvl_mask                                  (0x0FF00000)
#define  MDOMAIN_VI_MAIN_C1BUF_c_water_lvl(data)                                 (0x0FF00000&((data)<<20))
#define  MDOMAIN_VI_MAIN_C1BUF_get_c_water_lvl(data)                             ((0x0FF00000&(data))>>20)

#define  MDOMAIN_VI_MAIN_DMACTL1                                                 0x18027018
#define  MDOMAIN_VI_MAIN_DMACTL1_reg_addr                                        "0xB8027018"
#define  MDOMAIN_VI_MAIN_DMACTL1_reg                                             0xB8027018
#define  MDOMAIN_VI_MAIN_DMACTL1_inst_addr                                       "0x0006"
#define  set_MDOMAIN_VI_MAIN_DMACTL1_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_VI_MAIN_DMACTL1_reg)=data)
#define  get_MDOMAIN_VI_MAIN_DMACTL1_reg                                         (*((volatile unsigned int*)MDOMAIN_VI_MAIN_DMACTL1_reg))
#define  MDOMAIN_VI_MAIN_DMACTL1_y_ads_set_shift                                 (24)
#define  MDOMAIN_VI_MAIN_DMACTL1_c_ads_set_shift                                 (16)
#define  MDOMAIN_VI_MAIN_DMACTL1_dummy_15_0_shift                                (0)
#define  MDOMAIN_VI_MAIN_DMACTL1_y_ads_set_mask                                  (0x7F000000)
#define  MDOMAIN_VI_MAIN_DMACTL1_c_ads_set_mask                                  (0x007F0000)
#define  MDOMAIN_VI_MAIN_DMACTL1_dummy_15_0_mask                                 (0x0000FFFF)
#define  MDOMAIN_VI_MAIN_DMACTL1_y_ads_set(data)                                 (0x7F000000&((data)<<24))
#define  MDOMAIN_VI_MAIN_DMACTL1_c_ads_set(data)                                 (0x007F0000&((data)<<16))
#define  MDOMAIN_VI_MAIN_DMACTL1_dummy_15_0(data)                                (0x0000FFFF&(data))
#define  MDOMAIN_VI_MAIN_DMACTL1_get_y_ads_set(data)                             ((0x7F000000&(data))>>24)
#define  MDOMAIN_VI_MAIN_DMACTL1_get_c_ads_set(data)                             ((0x007F0000&(data))>>16)
#define  MDOMAIN_VI_MAIN_DMACTL1_get_dummy_15_0(data)                            (0x0000FFFF&(data))

#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME                                            0x1802701C
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_reg_addr                                   "0xB802701C"
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_reg                                        0xB802701C
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_inst_addr                                  "0x0007"
#define  set_MDOMAIN_VI_MAIN_DMA_MIN_TIME_reg(data)                              (*((volatile unsigned int*)MDOMAIN_VI_MAIN_DMA_MIN_TIME_reg)=data)
#define  get_MDOMAIN_VI_MAIN_DMA_MIN_TIME_reg                                    (*((volatile unsigned int*)MDOMAIN_VI_MAIN_DMA_MIN_TIME_reg))
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_y1c1_min_time_shift                        (25)
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_dummy_24_0_shift                           (0)
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_y1c1_min_time_mask                         (0x1E000000)
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_dummy_24_0_mask                            (0x01FFFFFF)
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_y1c1_min_time(data)                        (0x1E000000&((data)<<25))
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_dummy_24_0(data)                           (0x01FFFFFF&(data))
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_get_y1c1_min_time(data)                    ((0x1E000000&(data))>>25)
#define  MDOMAIN_VI_MAIN_DMA_MIN_TIME_get_dummy_24_0(data)                       (0x01FFFFFF&(data))

#define  MDOMAIN_VI_MAIN_INTEN                                                   0x18027020
#define  MDOMAIN_VI_MAIN_INTEN_reg_addr                                          "0xB8027020"
#define  MDOMAIN_VI_MAIN_INTEN_reg                                               0xB8027020
#define  MDOMAIN_VI_MAIN_INTEN_inst_addr                                         "0x0008"
#define  set_MDOMAIN_VI_MAIN_INTEN_reg(data)                                     (*((volatile unsigned int*)MDOMAIN_VI_MAIN_INTEN_reg)=data)
#define  get_MDOMAIN_VI_MAIN_INTEN_reg                                           (*((volatile unsigned int*)MDOMAIN_VI_MAIN_INTEN_reg))
#define  MDOMAIN_VI_MAIN_INTEN_dma_fifo_of_int_en_shift                          (6)
#define  MDOMAIN_VI_MAIN_INTEN_dma_fifo_uf_int_en_shift                          (5)
#define  MDOMAIN_VI_MAIN_INTEN_dmaerrinte_shift                                  (4)
#define  MDOMAIN_VI_MAIN_INTEN_video_in_last_wr_y_flag_ie_shift                  (2)
#define  MDOMAIN_VI_MAIN_INTEN_video_in_last_wr_c_flag_ie_shift                  (1)
#define  MDOMAIN_VI_MAIN_INTEN_vsinte1_shift                                     (0)
#define  MDOMAIN_VI_MAIN_INTEN_dma_fifo_of_int_en_mask                           (0x00000040)
#define  MDOMAIN_VI_MAIN_INTEN_dma_fifo_uf_int_en_mask                           (0x00000020)
#define  MDOMAIN_VI_MAIN_INTEN_dmaerrinte_mask                                   (0x00000010)
#define  MDOMAIN_VI_MAIN_INTEN_video_in_last_wr_y_flag_ie_mask                   (0x00000004)
#define  MDOMAIN_VI_MAIN_INTEN_video_in_last_wr_c_flag_ie_mask                   (0x00000002)
#define  MDOMAIN_VI_MAIN_INTEN_vsinte1_mask                                      (0x00000001)
#define  MDOMAIN_VI_MAIN_INTEN_dma_fifo_of_int_en(data)                          (0x00000040&((data)<<6))
#define  MDOMAIN_VI_MAIN_INTEN_dma_fifo_uf_int_en(data)                          (0x00000020&((data)<<5))
#define  MDOMAIN_VI_MAIN_INTEN_dmaerrinte(data)                                  (0x00000010&((data)<<4))
#define  MDOMAIN_VI_MAIN_INTEN_video_in_last_wr_y_flag_ie(data)                  (0x00000004&((data)<<2))
#define  MDOMAIN_VI_MAIN_INTEN_video_in_last_wr_c_flag_ie(data)                  (0x00000002&((data)<<1))
#define  MDOMAIN_VI_MAIN_INTEN_vsinte1(data)                                     (0x00000001&(data))
#define  MDOMAIN_VI_MAIN_INTEN_get_dma_fifo_of_int_en(data)                      ((0x00000040&(data))>>6)
#define  MDOMAIN_VI_MAIN_INTEN_get_dma_fifo_uf_int_en(data)                      ((0x00000020&(data))>>5)
#define  MDOMAIN_VI_MAIN_INTEN_get_dmaerrinte(data)                              ((0x00000010&(data))>>4)
#define  MDOMAIN_VI_MAIN_INTEN_get_video_in_last_wr_y_flag_ie(data)              ((0x00000004&(data))>>2)
#define  MDOMAIN_VI_MAIN_INTEN_get_video_in_last_wr_c_flag_ie(data)              ((0x00000002&(data))>>1)
#define  MDOMAIN_VI_MAIN_INTEN_get_vsinte1(data)                                 (0x00000001&(data))

#define  MDOMAIN_VI_MAIN_INTST                                                   0x18027024
#define  MDOMAIN_VI_MAIN_INTST_reg_addr                                          "0xB8027024"
#define  MDOMAIN_VI_MAIN_INTST_reg                                               0xB8027024
#define  MDOMAIN_VI_MAIN_INTST_inst_addr                                         "0x0009"
#define  set_MDOMAIN_VI_MAIN_INTST_reg(data)                                     (*((volatile unsigned int*)MDOMAIN_VI_MAIN_INTST_reg)=data)
#define  get_MDOMAIN_VI_MAIN_INTST_reg                                           (*((volatile unsigned int*)MDOMAIN_VI_MAIN_INTST_reg))
#define  MDOMAIN_VI_MAIN_INTST_dma_fifo_of_shift                                 (6)
#define  MDOMAIN_VI_MAIN_INTST_dma_fifo_uf_shift                                 (5)
#define  MDOMAIN_VI_MAIN_INTST_dmaerrints_shift                                  (4)
#define  MDOMAIN_VI_MAIN_INTST_video_in_last_wr_y_flag_shift                     (2)
#define  MDOMAIN_VI_MAIN_INTST_video_in_last_wr_c_flag_shift                     (1)
#define  MDOMAIN_VI_MAIN_INTST_vsints1_shift                                     (0)
#define  MDOMAIN_VI_MAIN_INTST_dma_fifo_of_mask                                  (0x00000040)
#define  MDOMAIN_VI_MAIN_INTST_dma_fifo_uf_mask                                  (0x00000020)
#define  MDOMAIN_VI_MAIN_INTST_dmaerrints_mask                                   (0x00000010)
#define  MDOMAIN_VI_MAIN_INTST_video_in_last_wr_y_flag_mask                      (0x00000004)
#define  MDOMAIN_VI_MAIN_INTST_video_in_last_wr_c_flag_mask                      (0x00000002)
#define  MDOMAIN_VI_MAIN_INTST_vsints1_mask                                      (0x00000001)
#define  MDOMAIN_VI_MAIN_INTST_dma_fifo_of(data)                                 (0x00000040&((data)<<6))
#define  MDOMAIN_VI_MAIN_INTST_dma_fifo_uf(data)                                 (0x00000020&((data)<<5))
#define  MDOMAIN_VI_MAIN_INTST_dmaerrints(data)                                  (0x00000010&((data)<<4))
#define  MDOMAIN_VI_MAIN_INTST_video_in_last_wr_y_flag(data)                     (0x00000004&((data)<<2))
#define  MDOMAIN_VI_MAIN_INTST_video_in_last_wr_c_flag(data)                     (0x00000002&((data)<<1))
#define  MDOMAIN_VI_MAIN_INTST_vsints1(data)                                     (0x00000001&(data))
#define  MDOMAIN_VI_MAIN_INTST_get_dma_fifo_of(data)                             ((0x00000040&(data))>>6)
#define  MDOMAIN_VI_MAIN_INTST_get_dma_fifo_uf(data)                             ((0x00000020&(data))>>5)
#define  MDOMAIN_VI_MAIN_INTST_get_dmaerrints(data)                              ((0x00000010&(data))>>4)
#define  MDOMAIN_VI_MAIN_INTST_get_video_in_last_wr_y_flag(data)                 ((0x00000004&(data))>>2)
#define  MDOMAIN_VI_MAIN_INTST_get_video_in_last_wr_c_flag(data)                 ((0x00000002&(data))>>1)
#define  MDOMAIN_VI_MAIN_INTST_get_vsints1(data)                                 (0x00000001&(data))

#define  MDOMAIN_VI_MAIN_GCTL                                                    0x18027028
#define  MDOMAIN_VI_MAIN_GCTL_reg_addr                                           "0xB8027028"
#define  MDOMAIN_VI_MAIN_GCTL_reg                                                0xB8027028
#define  MDOMAIN_VI_MAIN_GCTL_inst_addr                                          "0x000A"
#define  set_MDOMAIN_VI_MAIN_GCTL_reg(data)                                      (*((volatile unsigned int*)MDOMAIN_VI_MAIN_GCTL_reg)=data)
#define  get_MDOMAIN_VI_MAIN_GCTL_reg                                            (*((volatile unsigned int*)MDOMAIN_VI_MAIN_GCTL_reg))
#define  MDOMAIN_VI_MAIN_GCTL_vsce1_shift                                        (4)
#define  MDOMAIN_VI_MAIN_GCTL_vsce1_mask                                         (0x00000010)
#define  MDOMAIN_VI_MAIN_GCTL_vsce1(data)                                        (0x00000010&((data)<<4))
#define  MDOMAIN_VI_MAIN_GCTL_get_vsce1(data)                                    ((0x00000010&(data))>>4)

#define  MDOMAIN_VI_MAIN_Y1OBUFF                                                 0x1802702C
#define  MDOMAIN_VI_MAIN_Y1OBUFF_reg_addr                                        "0xB802702C"
#define  MDOMAIN_VI_MAIN_Y1OBUFF_reg                                             0xB802702C
#define  MDOMAIN_VI_MAIN_Y1OBUFF_inst_addr                                       "0x000B"
#define  set_MDOMAIN_VI_MAIN_Y1OBUFF_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_VI_MAIN_Y1OBUFF_reg)=data)
#define  get_MDOMAIN_VI_MAIN_Y1OBUFF_reg                                         (*((volatile unsigned int*)MDOMAIN_VI_MAIN_Y1OBUFF_reg))
#define  MDOMAIN_VI_MAIN_Y1OBUFF_y_buf_start_shift                               (16)
#define  MDOMAIN_VI_MAIN_Y1OBUFF_y_buf_end_shift                                 (0)
#define  MDOMAIN_VI_MAIN_Y1OBUFF_y_buf_start_mask                                (0x00FF0000)
#define  MDOMAIN_VI_MAIN_Y1OBUFF_y_buf_end_mask                                  (0x000000FF)
#define  MDOMAIN_VI_MAIN_Y1OBUFF_y_buf_start(data)                               (0x00FF0000&((data)<<16))
#define  MDOMAIN_VI_MAIN_Y1OBUFF_y_buf_end(data)                                 (0x000000FF&(data))
#define  MDOMAIN_VI_MAIN_Y1OBUFF_get_y_buf_start(data)                           ((0x00FF0000&(data))>>16)
#define  MDOMAIN_VI_MAIN_Y1OBUFF_get_y_buf_end(data)                             (0x000000FF&(data))

#define  MDOMAIN_VI_MAIN_C1OBUFF                                                 0x18027030
#define  MDOMAIN_VI_MAIN_C1OBUFF_reg_addr                                        "0xB8027030"
#define  MDOMAIN_VI_MAIN_C1OBUFF_reg                                             0xB8027030
#define  MDOMAIN_VI_MAIN_C1OBUFF_inst_addr                                       "0x000C"
#define  set_MDOMAIN_VI_MAIN_C1OBUFF_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_VI_MAIN_C1OBUFF_reg)=data)
#define  get_MDOMAIN_VI_MAIN_C1OBUFF_reg                                         (*((volatile unsigned int*)MDOMAIN_VI_MAIN_C1OBUFF_reg))
#define  MDOMAIN_VI_MAIN_C1OBUFF_c_buf_start_shift                               (16)
#define  MDOMAIN_VI_MAIN_C1OBUFF_c_buf_end_shift                                 (0)
#define  MDOMAIN_VI_MAIN_C1OBUFF_c_buf_start_mask                                (0x00FF0000)
#define  MDOMAIN_VI_MAIN_C1OBUFF_c_buf_end_mask                                  (0x000000FF)
#define  MDOMAIN_VI_MAIN_C1OBUFF_c_buf_start(data)                               (0x00FF0000&((data)<<16))
#define  MDOMAIN_VI_MAIN_C1OBUFF_c_buf_end(data)                                 (0x000000FF&(data))
#define  MDOMAIN_VI_MAIN_C1OBUFF_get_c_buf_start(data)                           ((0x00FF0000&(data))>>16)
#define  MDOMAIN_VI_MAIN_C1OBUFF_get_c_buf_end(data)                             (0x000000FF&(data))

#define  MDOMAIN_VI_MAIN_VI_DBG                                                  0x18027068
#define  MDOMAIN_VI_MAIN_VI_DBG_reg_addr                                         "0xB8027068"
#define  MDOMAIN_VI_MAIN_VI_DBG_reg                                              0xB8027068
#define  MDOMAIN_VI_MAIN_VI_DBG_inst_addr                                        "0x000D"
#define  set_MDOMAIN_VI_MAIN_VI_DBG_reg(data)                                    (*((volatile unsigned int*)MDOMAIN_VI_MAIN_VI_DBG_reg)=data)
#define  get_MDOMAIN_VI_MAIN_VI_DBG_reg                                          (*((volatile unsigned int*)MDOMAIN_VI_MAIN_VI_DBG_reg))
#define  MDOMAIN_VI_MAIN_VI_DBG_dbg_sel_shift                                    (0)
#define  MDOMAIN_VI_MAIN_VI_DBG_dbg_sel_mask                                     (0x0000003F)
#define  MDOMAIN_VI_MAIN_VI_DBG_dbg_sel(data)                                    (0x0000003F&(data))
#define  MDOMAIN_VI_MAIN_VI_DBG_get_dbg_sel(data)                                (0x0000003F&(data))

#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer                                    0x18027070
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_reg_addr                           "0xB8027070"
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_reg                                0xB8027070
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_inst_addr                          "0x000E"
#define  set_MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_reg(data)                      (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_reg)=data)
#define  get_MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_reg                            (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_reg))
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_apply_shift                  (2)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_sel_shift                    (1)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_en_shift                     (0)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_apply_mask                   (0x00000004)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_sel_mask                     (0x00000002)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_en_mask                      (0x00000001)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_apply(data)                  (0x00000004&((data)<<2))
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_sel(data)                    (0x00000002&((data)<<1))
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_vi_db_en(data)                     (0x00000001&(data))
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_get_vi_db_apply(data)              ((0x00000004&(data))>>2)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_get_vi_db_sel(data)                ((0x00000002&(data))>>1)
#define  MDOMAIN_VI_MAIN_mdom_vi_doublebuffer_get_vi_db_en(data)                 (0x00000001&(data))

#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform                                0x18027074
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_reg_addr                       "0xB8027074"
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_reg                            0xB8027074
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_inst_addr                      "0x000F"
#define  set_MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_reg(data)                  (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_reg)=data)
#define  get_MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_reg                        (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_reg))
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_line_step_shift                (3)
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_vi_addcmd_trans_en_shift       (0)
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_line_step_mask                 (0xFFFFFFF8)
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_vi_addcmd_trans_en_mask        (0x00000001)
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_line_step(data)                (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_vi_addcmd_trans_en(data)       (0x00000001&(data))
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_get_line_step(data)            ((0xFFFFFFF8&(data))>>3)
#define  MDOMAIN_VI_MAIN_mdom_vi_addcmd_transform_get_vi_addcmd_trans_en(data)   (0x00000001&(data))

#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y                                     0x18027078
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_reg_addr                            "0xB8027078"
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_reg                                 0xB8027078
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_inst_addr                           "0x0010"
#define  set_MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_reg(data)                       (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_reg)=data)
#define  get_MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_reg                             (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_reg))
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_y_ads_start_shift                   (3)
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_y_ads_start_mask                    (0xFFFFFFF8)
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_y_ads_start(data)                   (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_y_get_y_ads_start(data)               ((0xFFFFFFF8&(data))>>3)

#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c                                     0x1802707C
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg_addr                            "0xB802707C"
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg                                 0xB802707C
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_inst_addr                           "0x0011"
#define  set_MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg(data)                       (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg)=data)
#define  get_MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg                             (*((volatile unsigned int*)MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_reg))
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_c_ads_start_shift                   (3)
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_c_ads_start_mask                    (0xFFFFFFF8)
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_c_ads_start(data)                   (0xFFFFFFF8&((data)<<3))
#define  MDOMAIN_VI_MAIN_mdom_vi_ads_start_c_get_c_ads_start(data)               ((0xFFFFFFF8&(data))>>3)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MDOMAIN_VI_MAIN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  swap_8byte:1;
        RBus_UInt32  swap_4byte:1;
        RBus_UInt32  swap_2byte:1;
        RBus_UInt32  swap_1byte:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  data_format:1;
    };
}mdomain_vi_main_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hsize:13;
        RBus_UInt32  vsize:12;
    };
}mdomain_vi_main_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vsize_c:12;
    };
}mdomain_vi_main_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_blk_sel:1;
        RBus_UInt32  dummy1802700c_30_9:22;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  bstlen:3;
    };
}mdomain_vi_main_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  y_water_lvl:8;
        RBus_UInt32  res2:10;
    };
}mdomain_vi_main_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  c_water_lvl:8;
        RBus_UInt32  res2:20;
    };
}mdomain_vi_main_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  dummy18027018_15_0:16;
    };
}mdomain_vi_main_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  dummy1802701c_24_0:25;
    };
}mdomain_vi_main_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_fifo_of_int_en:1;
        RBus_UInt32  dma_fifo_uf_int_en:1;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  vsinte1:1;
    };
}mdomain_vi_main_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_fifo_of:1;
        RBus_UInt32  dma_fifo_uf:1;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  vsints1:1;
    };
}mdomain_vi_main_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:4;
    };
}mdomain_vi_main_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  y_buf_end:8;
    };
}mdomain_vi_main_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c_buf_end:8;
    };
}mdomain_vi_main_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dbg_sel:6;
    };
}mdomain_vi_main_vi_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_en:1;
    };
}mdomain_vi_main_mdom_vi_doublebuffer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line_step:29;
        RBus_UInt32  res1:2;
        RBus_UInt32  vi_addcmd_trans_en:1;
    };
}mdomain_vi_main_mdom_vi_addcmd_transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_ads_start:29;
        RBus_UInt32  res1:3;
    };
}mdomain_vi_main_mdom_vi_ads_start_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_ads_start:29;
        RBus_UInt32  res1:3;
    };
}mdomain_vi_main_mdom_vi_ads_start_c_RBUS;

#else //apply LITTLE_ENDIAN

//======MDOMAIN_VI_MAIN register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_format:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  swap_1byte:1;
        RBus_UInt32  swap_2byte:1;
        RBus_UInt32  swap_4byte:1;
        RBus_UInt32  swap_8byte:1;
        RBus_UInt32  res2:24;
    };
}mdomain_vi_main_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize:12;
        RBus_UInt32  hsize:13;
        RBus_UInt32  res1:7;
    };
}mdomain_vi_main_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize_c:12;
        RBus_UInt32  res1:20;
    };
}mdomain_vi_main_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bstlen:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  dummy1802700c_30_9:22;
        RBus_UInt32  seq_blk_sel:1;
    };
}mdomain_vi_main_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  y_water_lvl:8;
        RBus_UInt32  res2:14;
    };
}mdomain_vi_main_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  c_water_lvl:8;
        RBus_UInt32  res2:4;
    };
}mdomain_vi_main_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18027018_15_0:16;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
    };
}mdomain_vi_main_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802701c_24_0:25;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  res1:3;
    };
}mdomain_vi_main_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsinte1:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  dma_fifo_uf_int_en:1;
        RBus_UInt32  dma_fifo_of_int_en:1;
        RBus_UInt32  res2:25;
    };
}mdomain_vi_main_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsints1:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  dma_fifo_uf:1;
        RBus_UInt32  dma_fifo_of:1;
        RBus_UInt32  res2:25;
    };
}mdomain_vi_main_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:27;
    };
}mdomain_vi_main_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
    };
}mdomain_vi_main_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
    };
}mdomain_vi_main_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel:6;
        RBus_UInt32  res1:26;
    };
}mdomain_vi_main_vi_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_db_en:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  res1:29;
    };
}mdomain_vi_main_mdom_vi_doublebuffer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_addcmd_trans_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  line_step:29;
    };
}mdomain_vi_main_mdom_vi_addcmd_transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y_ads_start:29;
    };
}mdomain_vi_main_mdom_vi_ads_start_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  c_ads_start:29;
    };
}mdomain_vi_main_mdom_vi_ads_start_c_RBUS;




#endif 


#endif 
