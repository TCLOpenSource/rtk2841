/**
* @file rbusMdomain_vi_subReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MDOMAIN_VI_SUB_REG_H_
#define _RBUS_MDOMAIN_VI_SUB_REG_H_

#include "rbusTypes.h"



//  MDOMAIN_VI_SUB Register Address
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT                                        0x18027100
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_reg_addr                               "0xB8027100"
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_reg                                    0xB8027100
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_inst_addr                              "0x0000"
#define  set_MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_reg(data)                          (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_reg                                (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_reg))
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_8byte_shift                       (7)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_4byte_shift                       (6)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_2byte_shift                       (5)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_1byte_shift                       (4)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_data_format_shift                      (0)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_8byte_mask                        (0x00000080)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_4byte_mask                        (0x00000040)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_2byte_mask                        (0x00000020)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_1byte_mask                        (0x00000010)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_data_format_mask                       (0x00000001)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_8byte(data)                       (0x00000080&((data)<<7))
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_4byte(data)                       (0x00000040&((data)<<6))
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_2byte(data)                       (0x00000020&((data)<<5))
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_swap_1byte(data)                       (0x00000010&((data)<<4))
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_data_format(data)                      (0x00000001&(data))
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_get_swap_8byte(data)                   ((0x00000080&(data))>>7)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_get_swap_4byte(data)                   ((0x00000040&(data))>>6)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_get_swap_2byte(data)                   ((0x00000020&(data))>>5)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_get_swap_1byte(data)                   ((0x00000010&(data))>>4)
#define  MDOMAIN_VI_SUB_SUB_V1_OUTPUT_FMT_get_data_format(data)                  (0x00000001&(data))

#define  MDOMAIN_VI_SUB_SUB_CWVH1                                                0x18027104
#define  MDOMAIN_VI_SUB_SUB_CWVH1_reg_addr                                       "0xB8027104"
#define  MDOMAIN_VI_SUB_SUB_CWVH1_reg                                            0xB8027104
#define  MDOMAIN_VI_SUB_SUB_CWVH1_inst_addr                                      "0x0001"
#define  set_MDOMAIN_VI_SUB_SUB_CWVH1_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_CWVH1_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_CWVH1_reg                                        (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_CWVH1_reg))
#define  MDOMAIN_VI_SUB_SUB_CWVH1_hsize_shift                                    (12)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_vsize_shift                                    (0)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_hsize_mask                                     (0x01FFF000)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_vsize_mask                                     (0x00000FFF)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_hsize(data)                                    (0x01FFF000&((data)<<12))
#define  MDOMAIN_VI_SUB_SUB_CWVH1_vsize(data)                                    (0x00000FFF&(data))
#define  MDOMAIN_VI_SUB_SUB_CWVH1_get_hsize(data)                                ((0x01FFF000&(data))>>12)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_get_vsize(data)                                (0x00000FFF&(data))

#define  MDOMAIN_VI_SUB_SUB_CWVH1_2                                              0x18027108
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_reg_addr                                     "0xB8027108"
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_reg                                          0xB8027108
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_inst_addr                                    "0x0002"
#define  set_MDOMAIN_VI_SUB_SUB_CWVH1_2_reg(data)                                (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_CWVH1_2_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_CWVH1_2_reg                                      (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_CWVH1_2_reg))
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_vsize_c_shift                                (0)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_vsize_c_mask                                 (0x00000FFF)
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_vsize_c(data)                                (0x00000FFF&(data))
#define  MDOMAIN_VI_SUB_SUB_CWVH1_2_get_vsize_c(data)                            (0x00000FFF&(data))

#define  MDOMAIN_VI_SUB_SUB_DMACTL                                               0x1802710C
#define  MDOMAIN_VI_SUB_SUB_DMACTL_reg_addr                                      "0xB802710C"
#define  MDOMAIN_VI_SUB_SUB_DMACTL_reg                                           0xB802710C
#define  MDOMAIN_VI_SUB_SUB_DMACTL_inst_addr                                     "0x0003"
#define  set_MDOMAIN_VI_SUB_SUB_DMACTL_reg(data)                                 (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_DMACTL_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_DMACTL_reg                                       (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_DMACTL_reg))
#define  MDOMAIN_VI_SUB_SUB_DMACTL_seq_blk_sel_shift                             (31)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_dummy_shift                                   (9)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_dmaen1_shift                                  (8)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_bstlen_shift                                  (0)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_seq_blk_sel_mask                              (0x80000000)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_dummy_mask                                    (0x7FFFFE00)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_dmaen1_mask                                   (0x00000100)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_bstlen_mask                                   (0x00000007)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_seq_blk_sel(data)                             (0x80000000&((data)<<31))
#define  MDOMAIN_VI_SUB_SUB_DMACTL_dummy(data)                                   (0x7FFFFE00&((data)<<9))
#define  MDOMAIN_VI_SUB_SUB_DMACTL_dmaen1(data)                                  (0x00000100&((data)<<8))
#define  MDOMAIN_VI_SUB_SUB_DMACTL_bstlen(data)                                  (0x00000007&(data))
#define  MDOMAIN_VI_SUB_SUB_DMACTL_get_seq_blk_sel(data)                         ((0x80000000&(data))>>31)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_get_dummy(data)                               ((0x7FFFFE00&(data))>>9)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_get_dmaen1(data)                              ((0x00000100&(data))>>8)
#define  MDOMAIN_VI_SUB_SUB_DMACTL_get_bstlen(data)                              (0x00000007&(data))

#define  MDOMAIN_VI_SUB_SUB_Y1BUF                                                0x18027110
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_reg_addr                                       "0xB8027110"
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_reg                                            0xB8027110
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_inst_addr                                      "0x0004"
#define  set_MDOMAIN_VI_SUB_SUB_Y1BUF_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_Y1BUF_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_Y1BUF_reg                                        (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_Y1BUF_reg))
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_y_water_lvl_shift                              (10)
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_y_water_lvl_mask                               (0x0000FC00)
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_y_water_lvl(data)                              (0x0000FC00&((data)<<10))
#define  MDOMAIN_VI_SUB_SUB_Y1BUF_get_y_water_lvl(data)                          ((0x0000FC00&(data))>>10)

#define  MDOMAIN_VI_SUB_SUB_C1BUF                                                0x18027114
#define  MDOMAIN_VI_SUB_SUB_C1BUF_reg_addr                                       "0xB8027114"
#define  MDOMAIN_VI_SUB_SUB_C1BUF_reg                                            0xB8027114
#define  MDOMAIN_VI_SUB_SUB_C1BUF_inst_addr                                      "0x0005"
#define  set_MDOMAIN_VI_SUB_SUB_C1BUF_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_C1BUF_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_C1BUF_reg                                        (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_C1BUF_reg))
#define  MDOMAIN_VI_SUB_SUB_C1BUF_c_water_lvl_shift                              (20)
#define  MDOMAIN_VI_SUB_SUB_C1BUF_c_water_lvl_mask                               (0x03F00000)
#define  MDOMAIN_VI_SUB_SUB_C1BUF_c_water_lvl(data)                              (0x03F00000&((data)<<20))
#define  MDOMAIN_VI_SUB_SUB_C1BUF_get_c_water_lvl(data)                          ((0x03F00000&(data))>>20)

#define  MDOMAIN_VI_SUB_SUB_DMACTL1                                              0x18027118
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_reg_addr                                     "0xB8027118"
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_reg                                          0xB8027118
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_inst_addr                                    "0x0006"
#define  set_MDOMAIN_VI_SUB_SUB_DMACTL1_reg(data)                                (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_DMACTL1_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_DMACTL1_reg                                      (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_DMACTL1_reg))
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_y_ads_set_shift                              (24)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_c_ads_set_shift                              (16)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_dummy_shift                                  (0)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_y_ads_set_mask                               (0x7F000000)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_c_ads_set_mask                               (0x007F0000)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_dummy_mask                                   (0x0000FFFF)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_y_ads_set(data)                              (0x7F000000&((data)<<24))
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_c_ads_set(data)                              (0x007F0000&((data)<<16))
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_dummy(data)                                  (0x0000FFFF&(data))
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_get_y_ads_set(data)                          ((0x7F000000&(data))>>24)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_get_c_ads_set(data)                          ((0x007F0000&(data))>>16)
#define  MDOMAIN_VI_SUB_SUB_DMACTL1_get_dummy(data)                              (0x0000FFFF&(data))

#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME                                         0x1802711C
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_reg_addr                                "0xB802711C"
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_reg                                     0xB802711C
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_inst_addr                               "0x0007"
#define  set_MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_reg(data)                           (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_reg                                 (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_reg))
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_y1c1_min_time_shift                     (25)
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_dummy_shift                             (0)
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_y1c1_min_time_mask                      (0x1E000000)
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_dummy_mask                              (0x01FFFFFF)
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_y1c1_min_time(data)                     (0x1E000000&((data)<<25))
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_dummy(data)                             (0x01FFFFFF&(data))
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_get_y1c1_min_time(data)                 ((0x1E000000&(data))>>25)
#define  MDOMAIN_VI_SUB_SUB_DMA_MIN_TIME_get_dummy(data)                         (0x01FFFFFF&(data))

#define  MDOMAIN_VI_SUB_SUB_INTEN                                                0x18027120
#define  MDOMAIN_VI_SUB_SUB_INTEN_reg_addr                                       "0xB8027120"
#define  MDOMAIN_VI_SUB_SUB_INTEN_reg                                            0xB8027120
#define  MDOMAIN_VI_SUB_SUB_INTEN_inst_addr                                      "0x0008"
#define  set_MDOMAIN_VI_SUB_SUB_INTEN_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_INTEN_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_INTEN_reg                                        (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_INTEN_reg))
#define  MDOMAIN_VI_SUB_SUB_INTEN_dmaerrinte_shift                               (4)
#define  MDOMAIN_VI_SUB_SUB_INTEN_video_in_last_wr_y_flag_ie_shift               (2)
#define  MDOMAIN_VI_SUB_SUB_INTEN_video_in_last_wr_c_flag_ie_shift               (1)
#define  MDOMAIN_VI_SUB_SUB_INTEN_vsinte1_shift                                  (0)
#define  MDOMAIN_VI_SUB_SUB_INTEN_dmaerrinte_mask                                (0x00000010)
#define  MDOMAIN_VI_SUB_SUB_INTEN_video_in_last_wr_y_flag_ie_mask                (0x00000004)
#define  MDOMAIN_VI_SUB_SUB_INTEN_video_in_last_wr_c_flag_ie_mask                (0x00000002)
#define  MDOMAIN_VI_SUB_SUB_INTEN_vsinte1_mask                                   (0x00000001)
#define  MDOMAIN_VI_SUB_SUB_INTEN_dmaerrinte(data)                               (0x00000010&((data)<<4))
#define  MDOMAIN_VI_SUB_SUB_INTEN_video_in_last_wr_y_flag_ie(data)               (0x00000004&((data)<<2))
#define  MDOMAIN_VI_SUB_SUB_INTEN_video_in_last_wr_c_flag_ie(data)               (0x00000002&((data)<<1))
#define  MDOMAIN_VI_SUB_SUB_INTEN_vsinte1(data)                                  (0x00000001&(data))
#define  MDOMAIN_VI_SUB_SUB_INTEN_get_dmaerrinte(data)                           ((0x00000010&(data))>>4)
#define  MDOMAIN_VI_SUB_SUB_INTEN_get_video_in_last_wr_y_flag_ie(data)           ((0x00000004&(data))>>2)
#define  MDOMAIN_VI_SUB_SUB_INTEN_get_video_in_last_wr_c_flag_ie(data)           ((0x00000002&(data))>>1)
#define  MDOMAIN_VI_SUB_SUB_INTEN_get_vsinte1(data)                              (0x00000001&(data))

#define  MDOMAIN_VI_SUB_SUB_INTST                                                0x18027124
#define  MDOMAIN_VI_SUB_SUB_INTST_reg_addr                                       "0xB8027124"
#define  MDOMAIN_VI_SUB_SUB_INTST_reg                                            0xB8027124
#define  MDOMAIN_VI_SUB_SUB_INTST_inst_addr                                      "0x0009"
#define  set_MDOMAIN_VI_SUB_SUB_INTST_reg(data)                                  (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_INTST_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_INTST_reg                                        (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_INTST_reg))
#define  MDOMAIN_VI_SUB_SUB_INTST_dmaerrints_shift                               (4)
#define  MDOMAIN_VI_SUB_SUB_INTST_video_in_last_wr_y_flag_shift                  (2)
#define  MDOMAIN_VI_SUB_SUB_INTST_video_in_last_wr_c_flag_shift                  (1)
#define  MDOMAIN_VI_SUB_SUB_INTST_vsints1_shift                                  (0)
#define  MDOMAIN_VI_SUB_SUB_INTST_dmaerrints_mask                                (0x00000010)
#define  MDOMAIN_VI_SUB_SUB_INTST_video_in_last_wr_y_flag_mask                   (0x00000004)
#define  MDOMAIN_VI_SUB_SUB_INTST_video_in_last_wr_c_flag_mask                   (0x00000002)
#define  MDOMAIN_VI_SUB_SUB_INTST_vsints1_mask                                   (0x00000001)
#define  MDOMAIN_VI_SUB_SUB_INTST_dmaerrints(data)                               (0x00000010&((data)<<4))
#define  MDOMAIN_VI_SUB_SUB_INTST_video_in_last_wr_y_flag(data)                  (0x00000004&((data)<<2))
#define  MDOMAIN_VI_SUB_SUB_INTST_video_in_last_wr_c_flag(data)                  (0x00000002&((data)<<1))
#define  MDOMAIN_VI_SUB_SUB_INTST_vsints1(data)                                  (0x00000001&(data))
#define  MDOMAIN_VI_SUB_SUB_INTST_get_dmaerrints(data)                           ((0x00000010&(data))>>4)
#define  MDOMAIN_VI_SUB_SUB_INTST_get_video_in_last_wr_y_flag(data)              ((0x00000004&(data))>>2)
#define  MDOMAIN_VI_SUB_SUB_INTST_get_video_in_last_wr_c_flag(data)              ((0x00000002&(data))>>1)
#define  MDOMAIN_VI_SUB_SUB_INTST_get_vsints1(data)                              (0x00000001&(data))

#define  MDOMAIN_VI_SUB_SUB_GCTL                                                 0x18027128
#define  MDOMAIN_VI_SUB_SUB_GCTL_reg_addr                                        "0xB8027128"
#define  MDOMAIN_VI_SUB_SUB_GCTL_reg                                             0xB8027128
#define  MDOMAIN_VI_SUB_SUB_GCTL_inst_addr                                       "0x000A"
#define  set_MDOMAIN_VI_SUB_SUB_GCTL_reg(data)                                   (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_GCTL_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_GCTL_reg                                         (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_GCTL_reg))
#define  MDOMAIN_VI_SUB_SUB_GCTL_vsce1_shift                                     (4)
#define  MDOMAIN_VI_SUB_SUB_GCTL_vsce1_mask                                      (0x00000010)
#define  MDOMAIN_VI_SUB_SUB_GCTL_vsce1(data)                                     (0x00000010&((data)<<4))
#define  MDOMAIN_VI_SUB_SUB_GCTL_get_vsce1(data)                                 ((0x00000010&(data))>>4)

#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF                                              0x1802712C
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_reg_addr                                     "0xB802712C"
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_reg                                          0xB802712C
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_inst_addr                                    "0x000B"
#define  set_MDOMAIN_VI_SUB_SUB_Y1OBUFF_reg(data)                                (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_Y1OBUFF_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_Y1OBUFF_reg                                      (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_Y1OBUFF_reg))
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_y_buf_start_shift                            (16)
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_y_buf_end_shift                              (0)
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_y_buf_start_mask                             (0x00FF0000)
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_y_buf_end_mask                               (0x000000FF)
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_y_buf_start(data)                            (0x00FF0000&((data)<<16))
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_y_buf_end(data)                              (0x000000FF&(data))
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_get_y_buf_start(data)                        ((0x00FF0000&(data))>>16)
#define  MDOMAIN_VI_SUB_SUB_Y1OBUFF_get_y_buf_end(data)                          (0x000000FF&(data))

#define  MDOMAIN_VI_SUB_SUB_C1OBUFF                                              0x18027130
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_reg_addr                                     "0xB8027130"
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_reg                                          0xB8027130
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_inst_addr                                    "0x000C"
#define  set_MDOMAIN_VI_SUB_SUB_C1OBUFF_reg(data)                                (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_C1OBUFF_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_C1OBUFF_reg                                      (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_C1OBUFF_reg))
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_c_buf_start_shift                            (16)
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_c_buf_end_shift                              (0)
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_c_buf_start_mask                             (0x00FF0000)
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_c_buf_end_mask                               (0x000000FF)
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_c_buf_start(data)                            (0x00FF0000&((data)<<16))
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_c_buf_end(data)                              (0x000000FF&(data))
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_get_c_buf_start(data)                        ((0x00FF0000&(data))>>16)
#define  MDOMAIN_VI_SUB_SUB_C1OBUFF_get_c_buf_end(data)                          (0x000000FF&(data))

#define  MDOMAIN_VI_SUB_SUB_VI_DBG                                               0x18027168
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_reg_addr                                      "0xB8027168"
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_reg                                           0xB8027168
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_inst_addr                                     "0x000D"
#define  set_MDOMAIN_VI_SUB_SUB_VI_DBG_reg(data)                                 (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_VI_DBG_reg)=data)
#define  get_MDOMAIN_VI_SUB_SUB_VI_DBG_reg                                       (*((volatile unsigned int*)MDOMAIN_VI_SUB_SUB_VI_DBG_reg))
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_dbg_sel_shift                                 (0)
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_dbg_sel_mask                                  (0x0000003F)
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_dbg_sel(data)                                 (0x0000003F&(data))
#define  MDOMAIN_VI_SUB_SUB_VI_DBG_get_dbg_sel(data)                             (0x0000003F&(data))

#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer                                 0x18027170
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_reg_addr                        "0xB8027170"
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_reg                             0xB8027170
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_inst_addr                       "0x000E"
#define  set_MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_reg(data)                   (*((volatile unsigned int*)MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_reg)=data)
#define  get_MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_reg                         (*((volatile unsigned int*)MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_reg))
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_apply_shift               (2)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_sel_shift                 (1)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_en_shift                  (0)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_apply_mask                (0x00000004)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_sel_mask                  (0x00000002)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_en_mask                   (0x00000001)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_apply(data)               (0x00000004&((data)<<2))
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_sel(data)                 (0x00000002&((data)<<1))
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_vi_db_en(data)                  (0x00000001&(data))
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_get_vi_db_apply(data)           ((0x00000004&(data))>>2)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_get_vi_db_sel(data)             ((0x00000002&(data))>>1)
#define  MDOMAIN_VI_SUB_mdom_sub_vi_doublebuffer_get_vi_db_en(data)              (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MDOMAIN_VI_SUB register structure define==========

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
}mdomain_vi_sub_sub_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  hsize:13;
        RBus_UInt32  vsize:12;
    };
}mdomain_vi_sub_sub_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  vsize_c:12;
    };
}mdomain_vi_sub_sub_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_blk_sel:1;
        RBus_UInt32  dummy1802710c_30_9:22;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  bstlen:3;
    };
}mdomain_vi_sub_sub_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  y_water_lvl:6;
        RBus_UInt32  res2:10;
    };
}mdomain_vi_sub_sub_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  c_water_lvl:6;
        RBus_UInt32  res2:20;
    };
}mdomain_vi_sub_sub_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  dummy18027118_15_0:16;
    };
}mdomain_vi_sub_sub_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  dummy1802711c_24_0:25;
    };
}mdomain_vi_sub_sub_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  vsinte1:1;
    };
}mdomain_vi_sub_sub_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  vsints1:1;
    };
}mdomain_vi_sub_sub_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:4;
    };
}mdomain_vi_sub_sub_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  y_buf_end:8;
    };
}mdomain_vi_sub_sub_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c_buf_end:8;
    };
}mdomain_vi_sub_sub_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dbg_sel:6;
    };
}mdomain_vi_sub_sub_vi_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_en:1;
    };
}mdomain_vi_sub_mdom_sub_vi_doublebuffer_RBUS;

#else //apply LITTLE_ENDIAN

//======MDOMAIN_VI_SUB register structure define==========

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
}mdomain_vi_sub_sub_v1_output_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize:12;
        RBus_UInt32  hsize:13;
        RBus_UInt32  res1:7;
    };
}mdomain_vi_sub_sub_cwvh1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsize_c:12;
        RBus_UInt32  res1:20;
    };
}mdomain_vi_sub_sub_cwvh1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bstlen:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dmaen1:1;
        RBus_UInt32  dummy1802710c_30_9:22;
        RBus_UInt32  seq_blk_sel:1;
    };
}mdomain_vi_sub_sub_dmactl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  y_water_lvl:6;
        RBus_UInt32  res2:16;
    };
}mdomain_vi_sub_sub_y1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  c_water_lvl:6;
        RBus_UInt32  res2:6;
    };
}mdomain_vi_sub_sub_c1buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18027118_15_0:16;
        RBus_UInt32  c_ads_set:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  y_ads_set:7;
        RBus_UInt32  res2:1;
    };
}mdomain_vi_sub_sub_dmactl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802711c_24_0:25;
        RBus_UInt32  y1c1_min_time:4;
        RBus_UInt32  res1:3;
    };
}mdomain_vi_sub_sub_dma_min_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsinte1:1;
        RBus_UInt32  video_in_last_wr_c_flag_ie:1;
        RBus_UInt32  video_in_last_wr_y_flag_ie:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmaerrinte:1;
        RBus_UInt32  res2:27;
    };
}mdomain_vi_sub_sub_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsints1:1;
        RBus_UInt32  video_in_last_wr_c_flag:1;
        RBus_UInt32  video_in_last_wr_y_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dmaerrints:1;
        RBus_UInt32  res2:27;
    };
}mdomain_vi_sub_sub_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vsce1:1;
        RBus_UInt32  res2:27;
    };
}mdomain_vi_sub_sub_gctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  y_buf_start:8;
        RBus_UInt32  res2:8;
    };
}mdomain_vi_sub_sub_y1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c_buf_end:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c_buf_start:8;
        RBus_UInt32  res2:8;
    };
}mdomain_vi_sub_sub_c1obuff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel:6;
        RBus_UInt32  res1:26;
    };
}mdomain_vi_sub_sub_vi_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vi_db_en:1;
        RBus_UInt32  vi_db_sel:1;
        RBus_UInt32  vi_db_apply:1;
        RBus_UInt32  res1:29;
    };
}mdomain_vi_sub_mdom_sub_vi_doublebuffer_RBUS;




#endif 


#endif 
