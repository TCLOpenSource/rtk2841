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

#ifndef _RBUS_DC2H_VI_REG_H_
#define _RBUS_DC2H_VI_REG_H_

#include "rbus_types.h"



//  DC2H_VI Register Address
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT                                              0x18029D00
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_reg_addr                                     "0xB8029D00"
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_reg                                          0xB8029D00
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_inst_addr                                    "0x0000"
#define  set_DC2H_VI_DC2H_V1_OUTPUT_FMT_reg(data)                                (*((volatile unsigned int*)DC2H_VI_DC2H_V1_OUTPUT_FMT_reg)=data)
#define  get_DC2H_VI_DC2H_V1_OUTPUT_FMT_reg                                      (*((volatile unsigned int*)DC2H_VI_DC2H_V1_OUTPUT_FMT_reg))
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_8byte_shift                             (7)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_4byte_shift                             (6)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_2byte_shift                             (5)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_1byte_shift                             (4)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_data_format_shift                            (0)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_8byte_mask                              (0x00000080)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_4byte_mask                              (0x00000040)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_2byte_mask                              (0x00000020)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_1byte_mask                              (0x00000010)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_data_format_mask                             (0x00000001)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_8byte(data)                             (0x00000080&((data)<<7))
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_4byte(data)                             (0x00000040&((data)<<6))
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_2byte(data)                             (0x00000020&((data)<<5))
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_swap_1byte(data)                             (0x00000010&((data)<<4))
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_data_format(data)                            (0x00000001&(data))
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_get_swap_8byte(data)                         ((0x00000080&(data))>>7)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_get_swap_4byte(data)                         ((0x00000040&(data))>>6)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_get_swap_2byte(data)                         ((0x00000020&(data))>>5)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_get_swap_1byte(data)                         ((0x00000010&(data))>>4)
#define  DC2H_VI_DC2H_V1_OUTPUT_FMT_get_data_format(data)                        (0x00000001&(data))

#define  DC2H_VI_DC2H_CWVH1                                                      0x18029D04
#define  DC2H_VI_DC2H_CWVH1_reg_addr                                             "0xB8029D04"
#define  DC2H_VI_DC2H_CWVH1_reg                                                  0xB8029D04
#define  DC2H_VI_DC2H_CWVH1_inst_addr                                            "0x0001"
#define  set_DC2H_VI_DC2H_CWVH1_reg(data)                                        (*((volatile unsigned int*)DC2H_VI_DC2H_CWVH1_reg)=data)
#define  get_DC2H_VI_DC2H_CWVH1_reg                                              (*((volatile unsigned int*)DC2H_VI_DC2H_CWVH1_reg))
#define  DC2H_VI_DC2H_CWVH1_hsize_shift                                          (12)
#define  DC2H_VI_DC2H_CWVH1_vsize_shift                                          (0)
#define  DC2H_VI_DC2H_CWVH1_hsize_mask                                           (0x01FFF000)
#define  DC2H_VI_DC2H_CWVH1_vsize_mask                                           (0x00000FFF)
#define  DC2H_VI_DC2H_CWVH1_hsize(data)                                          (0x01FFF000&((data)<<12))
#define  DC2H_VI_DC2H_CWVH1_vsize(data)                                          (0x00000FFF&(data))
#define  DC2H_VI_DC2H_CWVH1_get_hsize(data)                                      ((0x01FFF000&(data))>>12)
#define  DC2H_VI_DC2H_CWVH1_get_vsize(data)                                      (0x00000FFF&(data))

#define  DC2H_VI_DC2H_CWVH1_2                                                    0x18029D08
#define  DC2H_VI_DC2H_CWVH1_2_reg_addr                                           "0xB8029D08"
#define  DC2H_VI_DC2H_CWVH1_2_reg                                                0xB8029D08
#define  DC2H_VI_DC2H_CWVH1_2_inst_addr                                          "0x0002"
#define  set_DC2H_VI_DC2H_CWVH1_2_reg(data)                                      (*((volatile unsigned int*)DC2H_VI_DC2H_CWVH1_2_reg)=data)
#define  get_DC2H_VI_DC2H_CWVH1_2_reg                                            (*((volatile unsigned int*)DC2H_VI_DC2H_CWVH1_2_reg))
#define  DC2H_VI_DC2H_CWVH1_2_vsize_c_shift                                      (0)
#define  DC2H_VI_DC2H_CWVH1_2_vsize_c_mask                                       (0x00000FFF)
#define  DC2H_VI_DC2H_CWVH1_2_vsize_c(data)                                      (0x00000FFF&(data))
#define  DC2H_VI_DC2H_CWVH1_2_get_vsize_c(data)                                  (0x00000FFF&(data))

#define  DC2H_VI_DC2H_DMACTL                                                     0x18029D0C
#define  DC2H_VI_DC2H_DMACTL_reg_addr                                            "0xB8029D0C"
#define  DC2H_VI_DC2H_DMACTL_reg                                                 0xB8029D0C
#define  DC2H_VI_DC2H_DMACTL_inst_addr                                           "0x0003"
#define  set_DC2H_VI_DC2H_DMACTL_reg(data)                                       (*((volatile unsigned int*)DC2H_VI_DC2H_DMACTL_reg)=data)
#define  get_DC2H_VI_DC2H_DMACTL_reg                                             (*((volatile unsigned int*)DC2H_VI_DC2H_DMACTL_reg))
#define  DC2H_VI_DC2H_DMACTL_seq_blk_sel_shift                                   (31)
#define  DC2H_VI_DC2H_DMACTL_dummy_30_9_shift                                    (9)
#define  DC2H_VI_DC2H_DMACTL_dmaen1_shift                                        (8)
#define  DC2H_VI_DC2H_DMACTL_bstlen_shift                                        (0)
#define  DC2H_VI_DC2H_DMACTL_seq_blk_sel_mask                                    (0x80000000)
#define  DC2H_VI_DC2H_DMACTL_dummy_30_9_mask                                     (0x7FFFFE00)
#define  DC2H_VI_DC2H_DMACTL_dmaen1_mask                                         (0x00000100)
#define  DC2H_VI_DC2H_DMACTL_bstlen_mask                                         (0x00000007)
#define  DC2H_VI_DC2H_DMACTL_seq_blk_sel(data)                                   (0x80000000&((data)<<31))
#define  DC2H_VI_DC2H_DMACTL_dummy_30_9(data)                                    (0x7FFFFE00&((data)<<9))
#define  DC2H_VI_DC2H_DMACTL_dmaen1(data)                                        (0x00000100&((data)<<8))
#define  DC2H_VI_DC2H_DMACTL_bstlen(data)                                        (0x00000007&(data))
#define  DC2H_VI_DC2H_DMACTL_get_seq_blk_sel(data)                               ((0x80000000&(data))>>31)
#define  DC2H_VI_DC2H_DMACTL_get_dummy_30_9(data)                                ((0x7FFFFE00&(data))>>9)
#define  DC2H_VI_DC2H_DMACTL_get_dmaen1(data)                                    ((0x00000100&(data))>>8)
#define  DC2H_VI_DC2H_DMACTL_get_bstlen(data)                                    (0x00000007&(data))

#define  DC2H_VI_DC2H_Y1BUF                                                      0x18029D10
#define  DC2H_VI_DC2H_Y1BUF_reg_addr                                             "0xB8029D10"
#define  DC2H_VI_DC2H_Y1BUF_reg                                                  0xB8029D10
#define  DC2H_VI_DC2H_Y1BUF_inst_addr                                            "0x0004"
#define  set_DC2H_VI_DC2H_Y1BUF_reg(data)                                        (*((volatile unsigned int*)DC2H_VI_DC2H_Y1BUF_reg)=data)
#define  get_DC2H_VI_DC2H_Y1BUF_reg                                              (*((volatile unsigned int*)DC2H_VI_DC2H_Y1BUF_reg))
#define  DC2H_VI_DC2H_Y1BUF_y_water_lvl_shift                                    (10)
#define  DC2H_VI_DC2H_Y1BUF_y_water_lvl_mask                                     (0x0003FC00)
#define  DC2H_VI_DC2H_Y1BUF_y_water_lvl(data)                                    (0x0003FC00&((data)<<10))
#define  DC2H_VI_DC2H_Y1BUF_get_y_water_lvl(data)                                ((0x0003FC00&(data))>>10)

#define  DC2H_VI_DC2H_C1BUF                                                      0x18029D14
#define  DC2H_VI_DC2H_C1BUF_reg_addr                                             "0xB8029D14"
#define  DC2H_VI_DC2H_C1BUF_reg                                                  0xB8029D14
#define  DC2H_VI_DC2H_C1BUF_inst_addr                                            "0x0005"
#define  set_DC2H_VI_DC2H_C1BUF_reg(data)                                        (*((volatile unsigned int*)DC2H_VI_DC2H_C1BUF_reg)=data)
#define  get_DC2H_VI_DC2H_C1BUF_reg                                              (*((volatile unsigned int*)DC2H_VI_DC2H_C1BUF_reg))
#define  DC2H_VI_DC2H_C1BUF_c_water_lvl_shift                                    (20)
#define  DC2H_VI_DC2H_C1BUF_c_water_lvl_mask                                     (0x0FF00000)
#define  DC2H_VI_DC2H_C1BUF_c_water_lvl(data)                                    (0x0FF00000&((data)<<20))
#define  DC2H_VI_DC2H_C1BUF_get_c_water_lvl(data)                                ((0x0FF00000&(data))>>20)

#define  DC2H_VI_DC2H_DMACTL1                                                    0x18029D18
#define  DC2H_VI_DC2H_DMACTL1_reg_addr                                           "0xB8029D18"
#define  DC2H_VI_DC2H_DMACTL1_reg                                                0xB8029D18
#define  DC2H_VI_DC2H_DMACTL1_inst_addr                                          "0x0006"
#define  set_DC2H_VI_DC2H_DMACTL1_reg(data)                                      (*((volatile unsigned int*)DC2H_VI_DC2H_DMACTL1_reg)=data)
#define  get_DC2H_VI_DC2H_DMACTL1_reg                                            (*((volatile unsigned int*)DC2H_VI_DC2H_DMACTL1_reg))
#define  DC2H_VI_DC2H_DMACTL1_y_ads_set_shift                                    (24)
#define  DC2H_VI_DC2H_DMACTL1_c_ads_set_shift                                    (16)
#define  DC2H_VI_DC2H_DMACTL1_dummy_15_0_shift                                   (0)
#define  DC2H_VI_DC2H_DMACTL1_y_ads_set_mask                                     (0x7F000000)
#define  DC2H_VI_DC2H_DMACTL1_c_ads_set_mask                                     (0x007F0000)
#define  DC2H_VI_DC2H_DMACTL1_dummy_15_0_mask                                    (0x0000FFFF)
#define  DC2H_VI_DC2H_DMACTL1_y_ads_set(data)                                    (0x7F000000&((data)<<24))
#define  DC2H_VI_DC2H_DMACTL1_c_ads_set(data)                                    (0x007F0000&((data)<<16))
#define  DC2H_VI_DC2H_DMACTL1_dummy_15_0(data)                                   (0x0000FFFF&(data))
#define  DC2H_VI_DC2H_DMACTL1_get_y_ads_set(data)                                ((0x7F000000&(data))>>24)
#define  DC2H_VI_DC2H_DMACTL1_get_c_ads_set(data)                                ((0x007F0000&(data))>>16)
#define  DC2H_VI_DC2H_DMACTL1_get_dummy_15_0(data)                               (0x0000FFFF&(data))

#define  DC2H_VI_DC2H_DMA_MIN_TIME                                               0x18029D1C
#define  DC2H_VI_DC2H_DMA_MIN_TIME_reg_addr                                      "0xB8029D1C"
#define  DC2H_VI_DC2H_DMA_MIN_TIME_reg                                           0xB8029D1C
#define  DC2H_VI_DC2H_DMA_MIN_TIME_inst_addr                                     "0x0007"
#define  set_DC2H_VI_DC2H_DMA_MIN_TIME_reg(data)                                 (*((volatile unsigned int*)DC2H_VI_DC2H_DMA_MIN_TIME_reg)=data)
#define  get_DC2H_VI_DC2H_DMA_MIN_TIME_reg                                       (*((volatile unsigned int*)DC2H_VI_DC2H_DMA_MIN_TIME_reg))
#define  DC2H_VI_DC2H_DMA_MIN_TIME_y1c1_min_time_shift                           (25)
#define  DC2H_VI_DC2H_DMA_MIN_TIME_dummy_24_0_shift                              (0)
#define  DC2H_VI_DC2H_DMA_MIN_TIME_y1c1_min_time_mask                            (0x1E000000)
#define  DC2H_VI_DC2H_DMA_MIN_TIME_dummy_24_0_mask                               (0x01FFFFFF)
#define  DC2H_VI_DC2H_DMA_MIN_TIME_y1c1_min_time(data)                           (0x1E000000&((data)<<25))
#define  DC2H_VI_DC2H_DMA_MIN_TIME_dummy_24_0(data)                              (0x01FFFFFF&(data))
#define  DC2H_VI_DC2H_DMA_MIN_TIME_get_y1c1_min_time(data)                       ((0x1E000000&(data))>>25)
#define  DC2H_VI_DC2H_DMA_MIN_TIME_get_dummy_24_0(data)                          (0x01FFFFFF&(data))

#define  DC2H_VI_DC2H_INTEN                                                      0x18029D20
#define  DC2H_VI_DC2H_INTEN_reg_addr                                             "0xB8029D20"
#define  DC2H_VI_DC2H_INTEN_reg                                                  0xB8029D20
#define  DC2H_VI_DC2H_INTEN_inst_addr                                            "0x0008"
#define  set_DC2H_VI_DC2H_INTEN_reg(data)                                        (*((volatile unsigned int*)DC2H_VI_DC2H_INTEN_reg)=data)
#define  get_DC2H_VI_DC2H_INTEN_reg                                              (*((volatile unsigned int*)DC2H_VI_DC2H_INTEN_reg))
#define  DC2H_VI_DC2H_INTEN_dma_fifo_of_int_en_shift                             (6)
#define  DC2H_VI_DC2H_INTEN_dma_fifo_uf_int_en_shift                             (5)
#define  DC2H_VI_DC2H_INTEN_dmaerrinte_shift                                     (4)
#define  DC2H_VI_DC2H_INTEN_video_in_last_wr_y_flag_ie_shift                     (2)
#define  DC2H_VI_DC2H_INTEN_video_in_last_wr_c_flag_ie_shift                     (1)
#define  DC2H_VI_DC2H_INTEN_vsinte1_shift                                        (0)
#define  DC2H_VI_DC2H_INTEN_dma_fifo_of_int_en_mask                              (0x00000040)
#define  DC2H_VI_DC2H_INTEN_dma_fifo_uf_int_en_mask                              (0x00000020)
#define  DC2H_VI_DC2H_INTEN_dmaerrinte_mask                                      (0x00000010)
#define  DC2H_VI_DC2H_INTEN_video_in_last_wr_y_flag_ie_mask                      (0x00000004)
#define  DC2H_VI_DC2H_INTEN_video_in_last_wr_c_flag_ie_mask                      (0x00000002)
#define  DC2H_VI_DC2H_INTEN_vsinte1_mask                                         (0x00000001)
#define  DC2H_VI_DC2H_INTEN_dma_fifo_of_int_en(data)                             (0x00000040&((data)<<6))
#define  DC2H_VI_DC2H_INTEN_dma_fifo_uf_int_en(data)                             (0x00000020&((data)<<5))
#define  DC2H_VI_DC2H_INTEN_dmaerrinte(data)                                     (0x00000010&((data)<<4))
#define  DC2H_VI_DC2H_INTEN_video_in_last_wr_y_flag_ie(data)                     (0x00000004&((data)<<2))
#define  DC2H_VI_DC2H_INTEN_video_in_last_wr_c_flag_ie(data)                     (0x00000002&((data)<<1))
#define  DC2H_VI_DC2H_INTEN_vsinte1(data)                                        (0x00000001&(data))
#define  DC2H_VI_DC2H_INTEN_get_dma_fifo_of_int_en(data)                         ((0x00000040&(data))>>6)
#define  DC2H_VI_DC2H_INTEN_get_dma_fifo_uf_int_en(data)                         ((0x00000020&(data))>>5)
#define  DC2H_VI_DC2H_INTEN_get_dmaerrinte(data)                                 ((0x00000010&(data))>>4)
#define  DC2H_VI_DC2H_INTEN_get_video_in_last_wr_y_flag_ie(data)                 ((0x00000004&(data))>>2)
#define  DC2H_VI_DC2H_INTEN_get_video_in_last_wr_c_flag_ie(data)                 ((0x00000002&(data))>>1)
#define  DC2H_VI_DC2H_INTEN_get_vsinte1(data)                                    (0x00000001&(data))

#define  DC2H_VI_DC2H_INTST                                                      0x18029D24
#define  DC2H_VI_DC2H_INTST_reg_addr                                             "0xB8029D24"
#define  DC2H_VI_DC2H_INTST_reg                                                  0xB8029D24
#define  DC2H_VI_DC2H_INTST_inst_addr                                            "0x0009"
#define  set_DC2H_VI_DC2H_INTST_reg(data)                                        (*((volatile unsigned int*)DC2H_VI_DC2H_INTST_reg)=data)
#define  get_DC2H_VI_DC2H_INTST_reg                                              (*((volatile unsigned int*)DC2H_VI_DC2H_INTST_reg))
#define  DC2H_VI_DC2H_INTST_dma_fifo_of_shift                                    (6)
#define  DC2H_VI_DC2H_INTST_dma_fifo_uf_shift                                    (5)
#define  DC2H_VI_DC2H_INTST_dmaerrints_shift                                     (4)
#define  DC2H_VI_DC2H_INTST_video_in_last_wr_y_flag_shift                        (2)
#define  DC2H_VI_DC2H_INTST_video_in_last_wr_c_flag_shift                        (1)
#define  DC2H_VI_DC2H_INTST_vsints1_shift                                        (0)
#define  DC2H_VI_DC2H_INTST_dma_fifo_of_mask                                     (0x00000040)
#define  DC2H_VI_DC2H_INTST_dma_fifo_uf_mask                                     (0x00000020)
#define  DC2H_VI_DC2H_INTST_dmaerrints_mask                                      (0x00000010)
#define  DC2H_VI_DC2H_INTST_video_in_last_wr_y_flag_mask                         (0x00000004)
#define  DC2H_VI_DC2H_INTST_video_in_last_wr_c_flag_mask                         (0x00000002)
#define  DC2H_VI_DC2H_INTST_vsints1_mask                                         (0x00000001)
#define  DC2H_VI_DC2H_INTST_dma_fifo_of(data)                                    (0x00000040&((data)<<6))
#define  DC2H_VI_DC2H_INTST_dma_fifo_uf(data)                                    (0x00000020&((data)<<5))
#define  DC2H_VI_DC2H_INTST_dmaerrints(data)                                     (0x00000010&((data)<<4))
#define  DC2H_VI_DC2H_INTST_video_in_last_wr_y_flag(data)                        (0x00000004&((data)<<2))
#define  DC2H_VI_DC2H_INTST_video_in_last_wr_c_flag(data)                        (0x00000002&((data)<<1))
#define  DC2H_VI_DC2H_INTST_vsints1(data)                                        (0x00000001&(data))
#define  DC2H_VI_DC2H_INTST_get_dma_fifo_of(data)                                ((0x00000040&(data))>>6)
#define  DC2H_VI_DC2H_INTST_get_dma_fifo_uf(data)                                ((0x00000020&(data))>>5)
#define  DC2H_VI_DC2H_INTST_get_dmaerrints(data)                                 ((0x00000010&(data))>>4)
#define  DC2H_VI_DC2H_INTST_get_video_in_last_wr_y_flag(data)                    ((0x00000004&(data))>>2)
#define  DC2H_VI_DC2H_INTST_get_video_in_last_wr_c_flag(data)                    ((0x00000002&(data))>>1)
#define  DC2H_VI_DC2H_INTST_get_vsints1(data)                                    (0x00000001&(data))

#define  DC2H_VI_DC2H_GCTL                                                       0x18029D28
#define  DC2H_VI_DC2H_GCTL_reg_addr                                              "0xB8029D28"
#define  DC2H_VI_DC2H_GCTL_reg                                                   0xB8029D28
#define  DC2H_VI_DC2H_GCTL_inst_addr                                             "0x000A"
#define  set_DC2H_VI_DC2H_GCTL_reg(data)                                         (*((volatile unsigned int*)DC2H_VI_DC2H_GCTL_reg)=data)
#define  get_DC2H_VI_DC2H_GCTL_reg                                               (*((volatile unsigned int*)DC2H_VI_DC2H_GCTL_reg))
#define  DC2H_VI_DC2H_GCTL_vsce1_shift                                           (4)
#define  DC2H_VI_DC2H_GCTL_vsce1_mask                                            (0x00000010)
#define  DC2H_VI_DC2H_GCTL_vsce1(data)                                           (0x00000010&((data)<<4))
#define  DC2H_VI_DC2H_GCTL_get_vsce1(data)                                       ((0x00000010&(data))>>4)

#define  DC2H_VI_DC2H_Y1OBUFF                                                    0x18029D2C
#define  DC2H_VI_DC2H_Y1OBUFF_reg_addr                                           "0xB8029D2C"
#define  DC2H_VI_DC2H_Y1OBUFF_reg                                                0xB8029D2C
#define  DC2H_VI_DC2H_Y1OBUFF_inst_addr                                          "0x000B"
#define  set_DC2H_VI_DC2H_Y1OBUFF_reg(data)                                      (*((volatile unsigned int*)DC2H_VI_DC2H_Y1OBUFF_reg)=data)
#define  get_DC2H_VI_DC2H_Y1OBUFF_reg                                            (*((volatile unsigned int*)DC2H_VI_DC2H_Y1OBUFF_reg))
#define  DC2H_VI_DC2H_Y1OBUFF_y_buf_start_shift                                  (16)
#define  DC2H_VI_DC2H_Y1OBUFF_y_buf_end_shift                                    (0)
#define  DC2H_VI_DC2H_Y1OBUFF_y_buf_start_mask                                   (0x00FF0000)
#define  DC2H_VI_DC2H_Y1OBUFF_y_buf_end_mask                                     (0x000000FF)
#define  DC2H_VI_DC2H_Y1OBUFF_y_buf_start(data)                                  (0x00FF0000&((data)<<16))
#define  DC2H_VI_DC2H_Y1OBUFF_y_buf_end(data)                                    (0x000000FF&(data))
#define  DC2H_VI_DC2H_Y1OBUFF_get_y_buf_start(data)                              ((0x00FF0000&(data))>>16)
#define  DC2H_VI_DC2H_Y1OBUFF_get_y_buf_end(data)                                (0x000000FF&(data))

#define  DC2H_VI_DC2H_C1OBUFF                                                    0x18029D30
#define  DC2H_VI_DC2H_C1OBUFF_reg_addr                                           "0xB8029D30"
#define  DC2H_VI_DC2H_C1OBUFF_reg                                                0xB8029D30
#define  DC2H_VI_DC2H_C1OBUFF_inst_addr                                          "0x000C"
#define  set_DC2H_VI_DC2H_C1OBUFF_reg(data)                                      (*((volatile unsigned int*)DC2H_VI_DC2H_C1OBUFF_reg)=data)
#define  get_DC2H_VI_DC2H_C1OBUFF_reg                                            (*((volatile unsigned int*)DC2H_VI_DC2H_C1OBUFF_reg))
#define  DC2H_VI_DC2H_C1OBUFF_c_buf_start_shift                                  (16)
#define  DC2H_VI_DC2H_C1OBUFF_c_buf_end_shift                                    (0)
#define  DC2H_VI_DC2H_C1OBUFF_c_buf_start_mask                                   (0x00FF0000)
#define  DC2H_VI_DC2H_C1OBUFF_c_buf_end_mask                                     (0x000000FF)
#define  DC2H_VI_DC2H_C1OBUFF_c_buf_start(data)                                  (0x00FF0000&((data)<<16))
#define  DC2H_VI_DC2H_C1OBUFF_c_buf_end(data)                                    (0x000000FF&(data))
#define  DC2H_VI_DC2H_C1OBUFF_get_c_buf_start(data)                              ((0x00FF0000&(data))>>16)
#define  DC2H_VI_DC2H_C1OBUFF_get_c_buf_end(data)                                (0x000000FF&(data))

#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE                                        0x18029D34
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_reg_addr                               "0xB8029D34"
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_reg                                    0xB8029D34
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_inst_addr                              "0x000D"
#define  set_DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_reg(data)                          (*((volatile unsigned int*)DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_reg                                (*((volatile unsigned int*)DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_reg))
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_vi_ls_shift                            (0)
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_vi_ls_mask                             (0x00000001)
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_vi_ls(data)                            (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_LIGHT_SLEEP_MODE_get_vi_ls(data)                        (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE                                         0x18029D38
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_reg_addr                                "0xB8029D38"
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_reg                                     0xB8029D38
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_inst_addr                               "0x000E"
#define  set_DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_reg(data)                           (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_reg                                 (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_reg))
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_vi_ds_shift                             (0)
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_vi_ds_mask                              (0x00000001)
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_vi_ds(data)                             (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_DEEP_SLEEP_MODE_get_vi_ds(data)                         (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE                                          0x18029D3C
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_reg_addr                                 "0xB8029D3C"
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_reg                                      0xB8029D3C
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_inst_addr                                "0x000F"
#define  set_DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_reg(data)                            (*((volatile unsigned int*)DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_reg                                  (*((volatile unsigned int*)DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_reg))
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_vi_sd_shift                              (0)
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_vi_sd_mask                               (0x00000001)
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_vi_sd(data)                              (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_SHUT_DOWN_MODE_get_vi_sd(data)                          (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE                                      0x18029D40
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_reg_addr                             "0xB8029D40"
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_reg                                  0xB8029D40
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_inst_addr                            "0x0010"
#define  set_DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_reg(data)                        (*((volatile unsigned int*)DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_reg                              (*((volatile unsigned int*)DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_reg))
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_vi_rme_shift                         (0)
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_vi_rme_mask                          (0x00000001)
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_vi_rme(data)                         (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_READ_MARGIN_ENABLE_get_vi_rme(data)                     (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_READ_MARGIN                                             0x18029D44
#define  DC2H_VI_DC2H_VI_READ_MARGIN_reg_addr                                    "0xB8029D44"
#define  DC2H_VI_DC2H_VI_READ_MARGIN_reg                                         0xB8029D44
#define  DC2H_VI_DC2H_VI_READ_MARGIN_inst_addr                                   "0x0011"
#define  set_DC2H_VI_DC2H_VI_READ_MARGIN_reg(data)                               (*((volatile unsigned int*)DC2H_VI_DC2H_VI_READ_MARGIN_reg)=data)
#define  get_DC2H_VI_DC2H_VI_READ_MARGIN_reg                                     (*((volatile unsigned int*)DC2H_VI_DC2H_VI_READ_MARGIN_reg))
#define  DC2H_VI_DC2H_VI_READ_MARGIN_vi_rm_shift                                 (0)
#define  DC2H_VI_DC2H_VI_READ_MARGIN_vi_rm_mask                                  (0x0000000F)
#define  DC2H_VI_DC2H_VI_READ_MARGIN_vi_rm(data)                                 (0x0000000F&(data))
#define  DC2H_VI_DC2H_VI_READ_MARGIN_get_vi_rm(data)                             (0x0000000F&(data))

#define  DC2H_VI_DC2H_VI_BIST_MODE                                               0x18029D48
#define  DC2H_VI_DC2H_VI_BIST_MODE_reg_addr                                      "0xB8029D48"
#define  DC2H_VI_DC2H_VI_BIST_MODE_reg                                           0xB8029D48
#define  DC2H_VI_DC2H_VI_BIST_MODE_inst_addr                                     "0x0012"
#define  set_DC2H_VI_DC2H_VI_BIST_MODE_reg(data)                                 (*((volatile unsigned int*)DC2H_VI_DC2H_VI_BIST_MODE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_BIST_MODE_reg                                       (*((volatile unsigned int*)DC2H_VI_DC2H_VI_BIST_MODE_reg))
#define  DC2H_VI_DC2H_VI_BIST_MODE_vi_bist_mode_shift                            (0)
#define  DC2H_VI_DC2H_VI_BIST_MODE_vi_bist_mode_mask                             (0x00000001)
#define  DC2H_VI_DC2H_VI_BIST_MODE_vi_bist_mode(data)                            (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_BIST_MODE_get_vi_bist_mode(data)                        (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_BIST_DONE                                               0x18029D4C
#define  DC2H_VI_DC2H_VI_BIST_DONE_reg_addr                                      "0xB8029D4C"
#define  DC2H_VI_DC2H_VI_BIST_DONE_reg                                           0xB8029D4C
#define  DC2H_VI_DC2H_VI_BIST_DONE_inst_addr                                     "0x0013"
#define  set_DC2H_VI_DC2H_VI_BIST_DONE_reg(data)                                 (*((volatile unsigned int*)DC2H_VI_DC2H_VI_BIST_DONE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_BIST_DONE_reg                                       (*((volatile unsigned int*)DC2H_VI_DC2H_VI_BIST_DONE_reg))
#define  DC2H_VI_DC2H_VI_BIST_DONE_vi_bist_done_shift                            (0)
#define  DC2H_VI_DC2H_VI_BIST_DONE_vi_bist_done_mask                             (0x00000001)
#define  DC2H_VI_DC2H_VI_BIST_DONE_vi_bist_done(data)                            (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_BIST_DONE_get_vi_bist_done(data)                        (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP                                         0x18029D50
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_reg_addr                                "0xB8029D50"
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_reg                                     0xB8029D50
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_inst_addr                               "0x0014"
#define  set_DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_reg(data)                           (*((volatile unsigned int*)DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_reg)=data)
#define  get_DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_reg                                 (*((volatile unsigned int*)DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_reg))
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_vi_bist_fail_shift                      (0)
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_vi_bist_fail_mask                       (0x00000001)
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_vi_bist_fail(data)                      (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_BIST_FAIL_GROUP_get_vi_bist_fail(data)                  (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_DRF_MODE                                                0x18029D54
#define  DC2H_VI_DC2H_VI_DRF_MODE_reg_addr                                       "0xB8029D54"
#define  DC2H_VI_DC2H_VI_DRF_MODE_reg                                            0xB8029D54
#define  DC2H_VI_DC2H_VI_DRF_MODE_inst_addr                                      "0x0015"
#define  set_DC2H_VI_DC2H_VI_DRF_MODE_reg(data)                                  (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_MODE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_DRF_MODE_reg                                        (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_MODE_reg))
#define  DC2H_VI_DC2H_VI_DRF_MODE_vi_drf_mode_shift                              (0)
#define  DC2H_VI_DC2H_VI_DRF_MODE_vi_drf_mode_mask                               (0x00000001)
#define  DC2H_VI_DC2H_VI_DRF_MODE_vi_drf_mode(data)                              (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_DRF_MODE_get_vi_drf_mode(data)                          (0x00000001&(data))

#define  DC2H_VI_VI_DRF_RESUME                                                   0x18029D58
#define  DC2H_VI_VI_DRF_RESUME_reg_addr                                          "0xB8029D58"
#define  DC2H_VI_VI_DRF_RESUME_reg                                               0xB8029D58
#define  DC2H_VI_VI_DRF_RESUME_inst_addr                                         "0x0016"
#define  set_DC2H_VI_VI_DRF_RESUME_reg(data)                                     (*((volatile unsigned int*)DC2H_VI_VI_DRF_RESUME_reg)=data)
#define  get_DC2H_VI_VI_DRF_RESUME_reg                                           (*((volatile unsigned int*)DC2H_VI_VI_DRF_RESUME_reg))
#define  DC2H_VI_VI_DRF_RESUME_vi_drf_resume_shift                               (0)
#define  DC2H_VI_VI_DRF_RESUME_vi_drf_resume_mask                                (0x00000001)
#define  DC2H_VI_VI_DRF_RESUME_vi_drf_resume(data)                               (0x00000001&(data))
#define  DC2H_VI_VI_DRF_RESUME_get_vi_drf_resume(data)                           (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_DRF_DONE                                                0x18029D5C
#define  DC2H_VI_DC2H_VI_DRF_DONE_reg_addr                                       "0xB8029D5C"
#define  DC2H_VI_DC2H_VI_DRF_DONE_reg                                            0xB8029D5C
#define  DC2H_VI_DC2H_VI_DRF_DONE_inst_addr                                      "0x0017"
#define  set_DC2H_VI_DC2H_VI_DRF_DONE_reg(data)                                  (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_DONE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_DRF_DONE_reg                                        (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_DONE_reg))
#define  DC2H_VI_DC2H_VI_DRF_DONE_vi_drf_done_shift                              (0)
#define  DC2H_VI_DC2H_VI_DRF_DONE_vi_drf_done_mask                               (0x00000001)
#define  DC2H_VI_DC2H_VI_DRF_DONE_vi_drf_done(data)                              (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_DRF_DONE_get_vi_drf_done(data)                          (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_DRF_PAUSE                                               0x18029D60
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_reg_addr                                      "0xB8029D60"
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_reg                                           0xB8029D60
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_inst_addr                                     "0x0018"
#define  set_DC2H_VI_DC2H_VI_DRF_PAUSE_reg(data)                                 (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_PAUSE_reg)=data)
#define  get_DC2H_VI_DC2H_VI_DRF_PAUSE_reg                                       (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_PAUSE_reg))
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_vi_drf_pause_shift                            (0)
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_vi_drf_pause_mask                             (0x00000001)
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_vi_drf_pause(data)                            (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_DRF_PAUSE_get_vi_drf_pause(data)                        (0x00000001&(data))

#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP                                          0x18029D64
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_reg_addr                                 "0xB8029D64"
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_reg                                      0xB8029D64
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_inst_addr                                "0x0019"
#define  set_DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_reg(data)                            (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_reg)=data)
#define  get_DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_reg                                  (*((volatile unsigned int*)DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_reg))
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_vi_drf_fail_shift                        (0)
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_vi_drf_fail_mask                         (0x00000001)
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_vi_drf_fail(data)                        (0x00000001&(data))
#define  DC2H_VI_DC2H_VI_DRF_FAIL_GROUP_get_vi_drf_fail(data)                    (0x00000001&(data))

#define  DC2H_VI_DC2H_DBG                                                        0x18029D68
#define  DC2H_VI_DC2H_DBG_reg_addr                                               "0xB8029D68"
#define  DC2H_VI_DC2H_DBG_reg                                                    0xB8029D68
#define  DC2H_VI_DC2H_DBG_inst_addr                                              "0x001A"
#define  set_DC2H_VI_DC2H_DBG_reg(data)                                          (*((volatile unsigned int*)DC2H_VI_DC2H_DBG_reg)=data)
#define  get_DC2H_VI_DC2H_DBG_reg                                                (*((volatile unsigned int*)DC2H_VI_DC2H_DBG_reg))
#define  DC2H_VI_DC2H_DBG_dbg_sel_shift                                          (0)
#define  DC2H_VI_DC2H_DBG_dbg_sel_mask                                           (0x0000003F)
#define  DC2H_VI_DC2H_DBG_dbg_sel(data)                                          (0x0000003F&(data))
#define  DC2H_VI_DC2H_DBG_get_dbg_sel(data)                                      (0x0000003F&(data))

#define  DC2H_VI_DC2H_vi_doublebuffer                                            0x18029D6C
#define  DC2H_VI_DC2H_vi_doublebuffer_reg_addr                                   "0xB8029D6C"
#define  DC2H_VI_DC2H_vi_doublebuffer_reg                                        0xB8029D6C
#define  DC2H_VI_DC2H_vi_doublebuffer_inst_addr                                  "0x001B"
#define  set_DC2H_VI_DC2H_vi_doublebuffer_reg(data)                              (*((volatile unsigned int*)DC2H_VI_DC2H_vi_doublebuffer_reg)=data)
#define  get_DC2H_VI_DC2H_vi_doublebuffer_reg                                    (*((volatile unsigned int*)DC2H_VI_DC2H_vi_doublebuffer_reg))
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_apply_shift                          (2)
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_sel_shift                            (1)
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_en_shift                             (0)
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_apply_mask                           (0x00000004)
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_sel_mask                             (0x00000002)
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_en_mask                              (0x00000001)
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_apply(data)                          (0x00000004&((data)<<2))
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_sel(data)                            (0x00000002&((data)<<1))
#define  DC2H_VI_DC2H_vi_doublebuffer_vi_db_en(data)                             (0x00000001&(data))
#define  DC2H_VI_DC2H_vi_doublebuffer_get_vi_db_apply(data)                      ((0x00000004&(data))>>2)
#define  DC2H_VI_DC2H_vi_doublebuffer_get_vi_db_sel(data)                        ((0x00000002&(data))>>1)
#define  DC2H_VI_DC2H_vi_doublebuffer_get_vi_db_en(data)                         (0x00000001&(data))

#define  DC2H_VI_DC2H_vi_addcmd_transform                                        0x18029D74
#define  DC2H_VI_DC2H_vi_addcmd_transform_reg_addr                               "0xB8029D74"
#define  DC2H_VI_DC2H_vi_addcmd_transform_reg                                    0xB8029D74
#define  DC2H_VI_DC2H_vi_addcmd_transform_inst_addr                              "0x001C"
#define  set_DC2H_VI_DC2H_vi_addcmd_transform_reg(data)                          (*((volatile unsigned int*)DC2H_VI_DC2H_vi_addcmd_transform_reg)=data)
#define  get_DC2H_VI_DC2H_vi_addcmd_transform_reg                                (*((volatile unsigned int*)DC2H_VI_DC2H_vi_addcmd_transform_reg))
#define  DC2H_VI_DC2H_vi_addcmd_transform_line_step_shift                        (3)
#define  DC2H_VI_DC2H_vi_addcmd_transform_vi_addcmd_trans_en_shift               (0)
#define  DC2H_VI_DC2H_vi_addcmd_transform_line_step_mask                         (0xFFFFFFF8)
#define  DC2H_VI_DC2H_vi_addcmd_transform_vi_addcmd_trans_en_mask                (0x00000001)
#define  DC2H_VI_DC2H_vi_addcmd_transform_line_step(data)                        (0xFFFFFFF8&((data)<<3))
#define  DC2H_VI_DC2H_vi_addcmd_transform_vi_addcmd_trans_en(data)               (0x00000001&(data))
#define  DC2H_VI_DC2H_vi_addcmd_transform_get_line_step(data)                    ((0xFFFFFFF8&(data))>>3)
#define  DC2H_VI_DC2H_vi_addcmd_transform_get_vi_addcmd_trans_en(data)           (0x00000001&(data))

#define  DC2H_VI_DC2H_vi_ads_start_y                                             0x18029D78
#define  DC2H_VI_DC2H_vi_ads_start_y_reg_addr                                    "0xB8029D78"
#define  DC2H_VI_DC2H_vi_ads_start_y_reg                                         0xB8029D78
#define  DC2H_VI_DC2H_vi_ads_start_y_inst_addr                                   "0x001D"
#define  set_DC2H_VI_DC2H_vi_ads_start_y_reg(data)                               (*((volatile unsigned int*)DC2H_VI_DC2H_vi_ads_start_y_reg)=data)
#define  get_DC2H_VI_DC2H_vi_ads_start_y_reg                                     (*((volatile unsigned int*)DC2H_VI_DC2H_vi_ads_start_y_reg))
#define  DC2H_VI_DC2H_vi_ads_start_y_y_ads_start_shift                           (3)
#define  DC2H_VI_DC2H_vi_ads_start_y_y_ads_start_mask                            (0xFFFFFFF8)
#define  DC2H_VI_DC2H_vi_ads_start_y_y_ads_start(data)                           (0xFFFFFFF8&((data)<<3))
#define  DC2H_VI_DC2H_vi_ads_start_y_get_y_ads_start(data)                       ((0xFFFFFFF8&(data))>>3)

#define  DC2H_VI_DC2H_vi_ads_start_c                                             0x18029D7C
#define  DC2H_VI_DC2H_vi_ads_start_c_reg_addr                                    "0xB8029D7C"
#define  DC2H_VI_DC2H_vi_ads_start_c_reg                                         0xB8029D7C
#define  DC2H_VI_DC2H_vi_ads_start_c_inst_addr                                   "0x001E"
#define  set_DC2H_VI_DC2H_vi_ads_start_c_reg(data)                               (*((volatile unsigned int*)DC2H_VI_DC2H_vi_ads_start_c_reg)=data)
#define  get_DC2H_VI_DC2H_vi_ads_start_c_reg                                     (*((volatile unsigned int*)DC2H_VI_DC2H_vi_ads_start_c_reg))
#define  DC2H_VI_DC2H_vi_ads_start_c_c_ads_start_shift                           (3)
#define  DC2H_VI_DC2H_vi_ads_start_c_c_ads_start_mask                            (0xFFFFFFF8)
#define  DC2H_VI_DC2H_vi_ads_start_c_c_ads_start(data)                           (0xFFFFFFF8&((data)<<3))
#define  DC2H_VI_DC2H_vi_ads_start_c_get_c_ads_start(data)                       ((0xFFFFFFF8&(data))>>3)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC2H_VI register structure define==========

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
}dc2h_vi_dc2h_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hsize:13;
        RBus_UInt32  vsize:12;
    };
}dc2h_vi_dc2h_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vsize_c:12;
    };
}dc2h_vi_dc2h_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_blk_sel:1;
        RBus_UInt32  dummy18029d0c_30_9:22;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  bstlen:3;
    };
}dc2h_vi_dc2h_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  y_water_lvl:8;
        RBus_UInt32  res2:10;
    };
}dc2h_vi_dc2h_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  c_water_lvl:8;
        RBus_UInt32  res2:20;
    };
}dc2h_vi_dc2h_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  dummy18029d18_15_0:16;
    };
}dc2h_vi_dc2h_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  dummy18029d1c_24_0:25;
    };
}dc2h_vi_dc2h_dma_min_time_RBUS;

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
}dc2h_vi_dc2h_inten_RBUS;

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
}dc2h_vi_dc2h_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:4;
    };
}dc2h_vi_dc2h_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  y_buf_end:8;
    };
}dc2h_vi_dc2h_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c_buf_end:8;
    };
}dc2h_vi_dc2h_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_ls:1;
    };
}dc2h_vi_dc2h_vi_light_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_ds:1;
    };
}dc2h_vi_dc2h_vi_deep_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_sd:1;
    };
}dc2h_vi_dc2h_vi_shut_down_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_rme:1;
    };
}dc2h_vi_dc2h_vi_read_margin_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  vi_rm:4;
    };
}dc2h_vi_dc2h_vi_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_bist_mode:1;
    };
}dc2h_vi_dc2h_vi_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_bist_done:1;
    };
}dc2h_vi_dc2h_vi_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_bist_fail:1;
    };
}dc2h_vi_dc2h_vi_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_mode:1;
    };
}dc2h_vi_dc2h_vi_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_resume:1;
    };
}dc2h_vi_vi_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_done:1;
    };
}dc2h_vi_dc2h_vi_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_pause:1;
    };
}dc2h_vi_dc2h_vi_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  vi_drf_fail:1;
    };
}dc2h_vi_dc2h_vi_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dbg_sel:6;
    };
}dc2h_vi_dc2h_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_en:1;
    };
}dc2h_vi_dc2h_vi_doublebuffer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  line_step:29;
        RBus_UInt32  res1:2;
        RBus_UInt32  vi_addcmd_trans_en:1;
    };
}dc2h_vi_dc2h_vi_addcmd_transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_ads_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_vi_dc2h_vi_ads_start_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_ads_start:29;
        RBus_UInt32  res1:3;
    };
}dc2h_vi_dc2h_vi_ads_start_c_RBUS;

#else //apply LITTLE_ENDIAN

//======DC2H_VI register structure define==========

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
}dc2h_vi_dc2h_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize:12;
        RBus_UInt32  hsize:13;
        RBus_UInt32  res1:7;
    };
}dc2h_vi_dc2h_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize_c:12;
        RBus_UInt32  res1:20;
    };
}dc2h_vi_dc2h_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bstlen:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  dummy18029d0c_30_9:22;
        RBus_UInt32  seq_blk_sel:1;
    };
}dc2h_vi_dc2h_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  y_water_lvl:8;
        RBus_UInt32  res2:14;
    };
}dc2h_vi_dc2h_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  c_water_lvl:8;
        RBus_UInt32  res2:4;
    };
}dc2h_vi_dc2h_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029d18_15_0:16;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
    };
}dc2h_vi_dc2h_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029d1c_24_0:25;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  res1:3;
    };
}dc2h_vi_dc2h_dma_min_time_RBUS;

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
}dc2h_vi_dc2h_inten_RBUS;

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
}dc2h_vi_dc2h_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:27;
    };
}dc2h_vi_dc2h_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
    };
}dc2h_vi_dc2h_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
    };
}dc2h_vi_dc2h_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_ls:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_light_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_ds:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_deep_sleep_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_sd:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_shut_down_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_rme:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_read_margin_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_rm:4;
        RBus_UInt32  res1:28;
    };
}dc2h_vi_dc2h_vi_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_bist_done:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_bist_fail:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_vi_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_done:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_drf_fail:1;
        RBus_UInt32  res1:31;
    };
}dc2h_vi_dc2h_vi_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel:6;
        RBus_UInt32  res1:26;
    };
}dc2h_vi_dc2h_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_db_en:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  res1:29;
    };
}dc2h_vi_dc2h_vi_doublebuffer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_addcmd_trans_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  line_step:29;
    };
}dc2h_vi_dc2h_vi_addcmd_transform_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y_ads_start:29;
    };
}dc2h_vi_dc2h_vi_ads_start_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  c_ads_start:29;
    };
}dc2h_vi_dc2h_vi_ads_start_c_RBUS;




#endif 


#endif 
