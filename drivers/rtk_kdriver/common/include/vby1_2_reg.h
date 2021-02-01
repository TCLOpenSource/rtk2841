/**
* @file rbusVBY1_2Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VBY1_2_REG_H_
#define _RBUS_VBY1_2_REG_H_

#include "rbus_types.h"



//  VBY1_2 Register Address
#define  VBY1_2_VIDEO_FORMAT_2                                                   0x1802D800
#define  VBY1_2_VIDEO_FORMAT_2_reg_addr                                          "0xB802D800"
#define  VBY1_2_VIDEO_FORMAT_2_reg                                               0xB802D800
#define  VBY1_2_VIDEO_FORMAT_2_inst_addr                                         "0x0000"
#define  set_VBY1_2_VIDEO_FORMAT_2_reg(data)                                     (*((volatile unsigned int*)VBY1_2_VIDEO_FORMAT_2_reg)=data)
#define  get_VBY1_2_VIDEO_FORMAT_2_reg                                           (*((volatile unsigned int*)VBY1_2_VIDEO_FORMAT_2_reg))
#define  VBY1_2_VIDEO_FORMAT_2_vby1_2_dclk_div_sel_shift                         (20)
#define  VBY1_2_VIDEO_FORMAT_2_color_format_shift                                (16)
#define  VBY1_2_VIDEO_FORMAT_2_win_shift                                         (0)
#define  VBY1_2_VIDEO_FORMAT_2_vby1_2_dclk_div_sel_mask                          (0x00300000)
#define  VBY1_2_VIDEO_FORMAT_2_color_format_mask                                 (0x000F0000)
#define  VBY1_2_VIDEO_FORMAT_2_win_mask                                          (0x000003FF)
#define  VBY1_2_VIDEO_FORMAT_2_vby1_2_dclk_div_sel(data)                         (0x00300000&((data)<<20))
#define  VBY1_2_VIDEO_FORMAT_2_color_format(data)                                (0x000F0000&((data)<<16))
#define  VBY1_2_VIDEO_FORMAT_2_win(data)                                         (0x000003FF&(data))
#define  VBY1_2_VIDEO_FORMAT_2_get_vby1_2_dclk_div_sel(data)                     ((0x00300000&(data))>>20)
#define  VBY1_2_VIDEO_FORMAT_2_get_color_format(data)                            ((0x000F0000&(data))>>16)
#define  VBY1_2_VIDEO_FORMAT_2_get_win(data)                                     (0x000003FF&(data))

#define  VBY1_2_LANE_STATUS_2                                                    0x1802D804
#define  VBY1_2_LANE_STATUS_2_reg_addr                                           "0xB802D804"
#define  VBY1_2_LANE_STATUS_2_reg                                                0xB802D804
#define  VBY1_2_LANE_STATUS_2_inst_addr                                          "0x0001"
#define  set_VBY1_2_LANE_STATUS_2_reg(data)                                      (*((volatile unsigned int*)VBY1_2_LANE_STATUS_2_reg)=data)
#define  get_VBY1_2_LANE_STATUS_2_reg                                            (*((volatile unsigned int*)VBY1_2_LANE_STATUS_2_reg))
#define  VBY1_2_LANE_STATUS_2_lane_count_shift                                   (16)
#define  VBY1_2_LANE_STATUS_2_byte_mode_shift                                    (0)
#define  VBY1_2_LANE_STATUS_2_lane_count_mask                                    (0x001F0000)
#define  VBY1_2_LANE_STATUS_2_byte_mode_mask                                     (0x00000007)
#define  VBY1_2_LANE_STATUS_2_lane_count(data)                                   (0x001F0000&((data)<<16))
#define  VBY1_2_LANE_STATUS_2_byte_mode(data)                                    (0x00000007&(data))
#define  VBY1_2_LANE_STATUS_2_get_lane_count(data)                               ((0x001F0000&(data))>>16)
#define  VBY1_2_LANE_STATUS_2_get_byte_mode(data)                                (0x00000007&(data))

#define  VBY1_2_CTL_2                                                            0x1802D808
#define  VBY1_2_CTL_2_reg_addr                                                   "0xB802D808"
#define  VBY1_2_CTL_2_reg                                                        0xB802D808
#define  VBY1_2_CTL_2_inst_addr                                                  "0x0002"
#define  set_VBY1_2_CTL_2_reg(data)                                              (*((volatile unsigned int*)VBY1_2_CTL_2_reg)=data)
#define  get_VBY1_2_CTL_2_reg                                                    (*((volatile unsigned int*)VBY1_2_CTL_2_reg))
#define  VBY1_2_CTL_2_ctl_shift                                                  (0)
#define  VBY1_2_CTL_2_ctl_mask                                                   (0x00FFFFFF)
#define  VBY1_2_CTL_2_ctl(data)                                                  (0x00FFFFFF&(data))
#define  VBY1_2_CTL_2_get_ctl(data)                                              (0x00FFFFFF&(data))

#define  VBY1_2_TRANSMIT_CONTROL_2                                               0x1802D810
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_addr                                      "0xB802D810"
#define  VBY1_2_TRANSMIT_CONTROL_2_reg                                           0xB802D810
#define  VBY1_2_TRANSMIT_CONTROL_2_inst_addr                                     "0x0003"
#define  set_VBY1_2_TRANSMIT_CONTROL_2_reg(data)                                 (*((volatile unsigned int*)VBY1_2_TRANSMIT_CONTROL_2_reg)=data)
#define  get_VBY1_2_TRANSMIT_CONTROL_2_reg                                       (*((volatile unsigned int*)VBY1_2_TRANSMIT_CONTROL_2_reg))
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_en_shift                                  (31)
#define  VBY1_2_TRANSMIT_CONTROL_2_pll_stable_shift                              (30)
#define  VBY1_2_TRANSMIT_CONTROL_2_transfer_en_shift                             (29)
#define  VBY1_2_TRANSMIT_CONTROL_2_video_trans_mode_shift                        (28)
#define  VBY1_2_TRANSMIT_CONTROL_2_debounce_cnt_shift                            (24)
#define  VBY1_2_TRANSMIT_CONTROL_2_bs_after_aln_shift                            (23)
#define  VBY1_2_TRANSMIT_CONTROL_2_be_before_aln_shift                           (22)
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_delay_shift                               (0)
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_en_mask                                   (0x80000000)
#define  VBY1_2_TRANSMIT_CONTROL_2_pll_stable_mask                               (0x40000000)
#define  VBY1_2_TRANSMIT_CONTROL_2_transfer_en_mask                              (0x20000000)
#define  VBY1_2_TRANSMIT_CONTROL_2_video_trans_mode_mask                         (0x10000000)
#define  VBY1_2_TRANSMIT_CONTROL_2_debounce_cnt_mask                             (0x0F000000)
#define  VBY1_2_TRANSMIT_CONTROL_2_bs_after_aln_mask                             (0x00800000)
#define  VBY1_2_TRANSMIT_CONTROL_2_be_before_aln_mask                            (0x00400000)
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_delay_mask                                (0x003FFFFF)
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_en(data)                                  (0x80000000&((data)<<31))
#define  VBY1_2_TRANSMIT_CONTROL_2_pll_stable(data)                              (0x40000000&((data)<<30))
#define  VBY1_2_TRANSMIT_CONTROL_2_transfer_en(data)                             (0x20000000&((data)<<29))
#define  VBY1_2_TRANSMIT_CONTROL_2_video_trans_mode(data)                        (0x10000000&((data)<<28))
#define  VBY1_2_TRANSMIT_CONTROL_2_debounce_cnt(data)                            (0x0F000000&((data)<<24))
#define  VBY1_2_TRANSMIT_CONTROL_2_bs_after_aln(data)                            (0x00800000&((data)<<23))
#define  VBY1_2_TRANSMIT_CONTROL_2_be_before_aln(data)                           (0x00400000&((data)<<22))
#define  VBY1_2_TRANSMIT_CONTROL_2_reg_delay(data)                               (0x003FFFFF&(data))
#define  VBY1_2_TRANSMIT_CONTROL_2_get_reg_en(data)                              ((0x80000000&(data))>>31)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_pll_stable(data)                          ((0x40000000&(data))>>30)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_transfer_en(data)                         ((0x20000000&(data))>>29)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_video_trans_mode(data)                    ((0x10000000&(data))>>28)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_debounce_cnt(data)                        ((0x0F000000&(data))>>24)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_bs_after_aln(data)                        ((0x00800000&(data))>>23)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_be_before_aln(data)                       ((0x00400000&(data))>>22)
#define  VBY1_2_TRANSMIT_CONTROL_2_get_reg_delay(data)                           (0x003FFFFF&(data))

#define  VBY1_2_TRANSMIT_STATUS_2                                                0x1802D814
#define  VBY1_2_TRANSMIT_STATUS_2_reg_addr                                       "0xB802D814"
#define  VBY1_2_TRANSMIT_STATUS_2_reg                                            0xB802D814
#define  VBY1_2_TRANSMIT_STATUS_2_inst_addr                                      "0x0004"
#define  set_VBY1_2_TRANSMIT_STATUS_2_reg(data)                                  (*((volatile unsigned int*)VBY1_2_TRANSMIT_STATUS_2_reg)=data)
#define  get_VBY1_2_TRANSMIT_STATUS_2_reg                                        (*((volatile unsigned int*)VBY1_2_TRANSMIT_STATUS_2_reg))
#define  VBY1_2_TRANSMIT_STATUS_2_dummy_31_8_shift                               (8)
#define  VBY1_2_TRANSMIT_STATUS_2_reset_sel_shift                                (7)
#define  VBY1_2_TRANSMIT_STATUS_2_num_check_fail_shift                           (6)
#define  VBY1_2_TRANSMIT_STATUS_2_aln_finish_shift                               (5)
#define  VBY1_2_TRANSMIT_STATUS_2_initial_finish_shift                           (4)
#define  VBY1_2_TRANSMIT_STATUS_2_cdr_out_en_shift                               (3)
#define  VBY1_2_TRANSMIT_STATUS_2_video_en_shift                                 (2)
#define  VBY1_2_TRANSMIT_STATUS_2_aln_en_shift                                   (1)
#define  VBY1_2_TRANSMIT_STATUS_2_initial_en_shift                               (0)
#define  VBY1_2_TRANSMIT_STATUS_2_dummy_31_8_mask                                (0xFFFFFF00)
#define  VBY1_2_TRANSMIT_STATUS_2_reset_sel_mask                                 (0x00000080)
#define  VBY1_2_TRANSMIT_STATUS_2_num_check_fail_mask                            (0x00000040)
#define  VBY1_2_TRANSMIT_STATUS_2_aln_finish_mask                                (0x00000020)
#define  VBY1_2_TRANSMIT_STATUS_2_initial_finish_mask                            (0x00000010)
#define  VBY1_2_TRANSMIT_STATUS_2_cdr_out_en_mask                                (0x00000008)
#define  VBY1_2_TRANSMIT_STATUS_2_video_en_mask                                  (0x00000004)
#define  VBY1_2_TRANSMIT_STATUS_2_aln_en_mask                                    (0x00000002)
#define  VBY1_2_TRANSMIT_STATUS_2_initial_en_mask                                (0x00000001)
#define  VBY1_2_TRANSMIT_STATUS_2_dummy_31_8(data)                               (0xFFFFFF00&((data)<<8))
#define  VBY1_2_TRANSMIT_STATUS_2_reset_sel(data)                                (0x00000080&((data)<<7))
#define  VBY1_2_TRANSMIT_STATUS_2_num_check_fail(data)                           (0x00000040&((data)<<6))
#define  VBY1_2_TRANSMIT_STATUS_2_aln_finish(data)                               (0x00000020&((data)<<5))
#define  VBY1_2_TRANSMIT_STATUS_2_initial_finish(data)                           (0x00000010&((data)<<4))
#define  VBY1_2_TRANSMIT_STATUS_2_cdr_out_en(data)                               (0x00000008&((data)<<3))
#define  VBY1_2_TRANSMIT_STATUS_2_video_en(data)                                 (0x00000004&((data)<<2))
#define  VBY1_2_TRANSMIT_STATUS_2_aln_en(data)                                   (0x00000002&((data)<<1))
#define  VBY1_2_TRANSMIT_STATUS_2_initial_en(data)                               (0x00000001&(data))
#define  VBY1_2_TRANSMIT_STATUS_2_get_dummy_31_8(data)                           ((0xFFFFFF00&(data))>>8)
#define  VBY1_2_TRANSMIT_STATUS_2_get_reset_sel(data)                            ((0x00000080&(data))>>7)
#define  VBY1_2_TRANSMIT_STATUS_2_get_num_check_fail(data)                       ((0x00000040&(data))>>6)
#define  VBY1_2_TRANSMIT_STATUS_2_get_aln_finish(data)                           ((0x00000020&(data))>>5)
#define  VBY1_2_TRANSMIT_STATUS_2_get_initial_finish(data)                       ((0x00000010&(data))>>4)
#define  VBY1_2_TRANSMIT_STATUS_2_get_cdr_out_en(data)                           ((0x00000008&(data))>>3)
#define  VBY1_2_TRANSMIT_STATUS_2_get_video_en(data)                             ((0x00000004&(data))>>2)
#define  VBY1_2_TRANSMIT_STATUS_2_get_aln_en(data)                               ((0x00000002&(data))>>1)
#define  VBY1_2_TRANSMIT_STATUS_2_get_initial_en(data)                           (0x00000001&(data))

#define  VBY1_2_THREE_FLAG_2                                                     0x1802D818
#define  VBY1_2_THREE_FLAG_2_reg_addr                                            "0xB802D818"
#define  VBY1_2_THREE_FLAG_2_reg                                                 0xB802D818
#define  VBY1_2_THREE_FLAG_2_inst_addr                                           "0x0005"
#define  set_VBY1_2_THREE_FLAG_2_reg(data)                                       (*((volatile unsigned int*)VBY1_2_THREE_FLAG_2_reg)=data)
#define  get_VBY1_2_THREE_FLAG_2_reg                                             (*((volatile unsigned int*)VBY1_2_THREE_FLAG_2_reg))
#define  VBY1_2_THREE_FLAG_2_three_mode_shift                                    (1)
#define  VBY1_2_THREE_FLAG_2_three_en_shift                                      (0)
#define  VBY1_2_THREE_FLAG_2_three_mode_mask                                     (0x00000006)
#define  VBY1_2_THREE_FLAG_2_three_en_mask                                       (0x00000001)
#define  VBY1_2_THREE_FLAG_2_three_mode(data)                                    (0x00000006&((data)<<1))
#define  VBY1_2_THREE_FLAG_2_three_en(data)                                      (0x00000001&(data))
#define  VBY1_2_THREE_FLAG_2_get_three_mode(data)                                ((0x00000006&(data))>>1)
#define  VBY1_2_THREE_FLAG_2_get_three_en(data)                                  (0x00000001&(data))

#define  VBY1_2_CRC_CONTROL_2                                                    0x1802D820
#define  VBY1_2_CRC_CONTROL_2_reg_addr                                           "0xB802D820"
#define  VBY1_2_CRC_CONTROL_2_reg                                                0xB802D820
#define  VBY1_2_CRC_CONTROL_2_inst_addr                                          "0x0006"
#define  set_VBY1_2_CRC_CONTROL_2_reg(data)                                      (*((volatile unsigned int*)VBY1_2_CRC_CONTROL_2_reg)=data)
#define  get_VBY1_2_CRC_CONTROL_2_reg                                            (*((volatile unsigned int*)VBY1_2_CRC_CONTROL_2_reg))
#define  VBY1_2_CRC_CONTROL_2_reg_crc_auto_cmp_en_shift                          (2)
#define  VBY1_2_CRC_CONTROL_2_reg_crc_conti_shift                                (1)
#define  VBY1_2_CRC_CONTROL_2_reg_crc_start_shift                                (0)
#define  VBY1_2_CRC_CONTROL_2_reg_crc_auto_cmp_en_mask                           (0x00000004)
#define  VBY1_2_CRC_CONTROL_2_reg_crc_conti_mask                                 (0x00000002)
#define  VBY1_2_CRC_CONTROL_2_reg_crc_start_mask                                 (0x00000001)
#define  VBY1_2_CRC_CONTROL_2_reg_crc_auto_cmp_en(data)                          (0x00000004&((data)<<2))
#define  VBY1_2_CRC_CONTROL_2_reg_crc_conti(data)                                (0x00000002&((data)<<1))
#define  VBY1_2_CRC_CONTROL_2_reg_crc_start(data)                                (0x00000001&(data))
#define  VBY1_2_CRC_CONTROL_2_get_reg_crc_auto_cmp_en(data)                      ((0x00000004&(data))>>2)
#define  VBY1_2_CRC_CONTROL_2_get_reg_crc_conti(data)                            ((0x00000002&(data))>>1)
#define  VBY1_2_CRC_CONTROL_2_get_reg_crc_start(data)                            (0x00000001&(data))

#define  VBY1_2_CRC_RESULT_2                                                     0x1802D824
#define  VBY1_2_CRC_RESULT_2_reg_addr                                            "0xB802D824"
#define  VBY1_2_CRC_RESULT_2_reg                                                 0xB802D824
#define  VBY1_2_CRC_RESULT_2_inst_addr                                           "0x0007"
#define  set_VBY1_2_CRC_RESULT_2_reg(data)                                       (*((volatile unsigned int*)VBY1_2_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_CRC_RESULT_2_reg                                             (*((volatile unsigned int*)VBY1_2_CRC_RESULT_2_reg))
#define  VBY1_2_CRC_RESULT_2_crc_result_shift                                    (0)
#define  VBY1_2_CRC_RESULT_2_crc_result_mask                                     (0xFFFFFFFF)
#define  VBY1_2_CRC_RESULT_2_crc_result(data)                                    (0xFFFFFFFF&(data))
#define  VBY1_2_CRC_RESULT_2_get_crc_result(data)                                (0xFFFFFFFF&(data))

#define  VBY1_2_CRC_DES_2                                                        0x1802D828
#define  VBY1_2_CRC_DES_2_reg_addr                                               "0xB802D828"
#define  VBY1_2_CRC_DES_2_reg                                                    0xB802D828
#define  VBY1_2_CRC_DES_2_inst_addr                                              "0x0008"
#define  set_VBY1_2_CRC_DES_2_reg(data)                                          (*((volatile unsigned int*)VBY1_2_CRC_DES_2_reg)=data)
#define  get_VBY1_2_CRC_DES_2_reg                                                (*((volatile unsigned int*)VBY1_2_CRC_DES_2_reg))
#define  VBY1_2_CRC_DES_2_reg_crc_des_shift                                      (0)
#define  VBY1_2_CRC_DES_2_reg_crc_des_mask                                       (0xFFFFFFFF)
#define  VBY1_2_CRC_DES_2_reg_crc_des(data)                                      (0xFFFFFFFF&(data))
#define  VBY1_2_CRC_DES_2_get_reg_crc_des(data)                                  (0xFFFFFFFF&(data))

#define  VBY1_2_CRC_ERROR_CNT_2                                                  0x1802D82C
#define  VBY1_2_CRC_ERROR_CNT_2_reg_addr                                         "0xB802D82C"
#define  VBY1_2_CRC_ERROR_CNT_2_reg                                              0xB802D82C
#define  VBY1_2_CRC_ERROR_CNT_2_inst_addr                                        "0x0009"
#define  set_VBY1_2_CRC_ERROR_CNT_2_reg(data)                                    (*((volatile unsigned int*)VBY1_2_CRC_ERROR_CNT_2_reg)=data)
#define  get_VBY1_2_CRC_ERROR_CNT_2_reg                                          (*((volatile unsigned int*)VBY1_2_CRC_ERROR_CNT_2_reg))
#define  VBY1_2_CRC_ERROR_CNT_2_crc_err_cnt_shift                                (0)
#define  VBY1_2_CRC_ERROR_CNT_2_crc_err_cnt_mask                                 (0x0000FFFF)
#define  VBY1_2_CRC_ERROR_CNT_2_crc_err_cnt(data)                                (0x0000FFFF&(data))
#define  VBY1_2_CRC_ERROR_CNT_2_get_crc_err_cnt(data)                            (0x0000FFFF&(data))

#define  VBY1_2_BYTE_REPEAT_DROP_2                                               0x1802D840
#define  VBY1_2_BYTE_REPEAT_DROP_2_reg_addr                                      "0xB802D840"
#define  VBY1_2_BYTE_REPEAT_DROP_2_reg                                           0xB802D840
#define  VBY1_2_BYTE_REPEAT_DROP_2_inst_addr                                     "0x000A"
#define  set_VBY1_2_BYTE_REPEAT_DROP_2_reg(data)                                 (*((volatile unsigned int*)VBY1_2_BYTE_REPEAT_DROP_2_reg)=data)
#define  get_VBY1_2_BYTE_REPEAT_DROP_2_reg                                       (*((volatile unsigned int*)VBY1_2_BYTE_REPEAT_DROP_2_reg))
#define  VBY1_2_BYTE_REPEAT_DROP_2_drop_1_byte_shift                             (1)
#define  VBY1_2_BYTE_REPEAT_DROP_2_repeat_1_byte_shift                           (0)
#define  VBY1_2_BYTE_REPEAT_DROP_2_drop_1_byte_mask                              (0x00000002)
#define  VBY1_2_BYTE_REPEAT_DROP_2_repeat_1_byte_mask                            (0x00000001)
#define  VBY1_2_BYTE_REPEAT_DROP_2_drop_1_byte(data)                             (0x00000002&((data)<<1))
#define  VBY1_2_BYTE_REPEAT_DROP_2_repeat_1_byte(data)                           (0x00000001&(data))
#define  VBY1_2_BYTE_REPEAT_DROP_2_get_drop_1_byte(data)                         ((0x00000002&(data))>>1)
#define  VBY1_2_BYTE_REPEAT_DROP_2_get_repeat_1_byte(data)                       (0x00000001&(data))

#define  VBY1_2_ASYNC_FIFO_RST_2                                                 0x1802D844
#define  VBY1_2_ASYNC_FIFO_RST_2_reg_addr                                        "0xB802D844"
#define  VBY1_2_ASYNC_FIFO_RST_2_reg                                             0xB802D844
#define  VBY1_2_ASYNC_FIFO_RST_2_inst_addr                                       "0x000B"
#define  set_VBY1_2_ASYNC_FIFO_RST_2_reg(data)                                   (*((volatile unsigned int*)VBY1_2_ASYNC_FIFO_RST_2_reg)=data)
#define  get_VBY1_2_ASYNC_FIFO_RST_2_reg                                         (*((volatile unsigned int*)VBY1_2_ASYNC_FIFO_RST_2_reg))
#define  VBY1_2_ASYNC_FIFO_RST_2_fifo_vs_rst_en_shift                            (16)
#define  VBY1_2_ASYNC_FIFO_RST_2_fifo_vs_rst_delay_shift                         (0)
#define  VBY1_2_ASYNC_FIFO_RST_2_fifo_vs_rst_en_mask                             (0x00010000)
#define  VBY1_2_ASYNC_FIFO_RST_2_fifo_vs_rst_delay_mask                          (0x0000FFFF)
#define  VBY1_2_ASYNC_FIFO_RST_2_fifo_vs_rst_en(data)                            (0x00010000&((data)<<16))
#define  VBY1_2_ASYNC_FIFO_RST_2_fifo_vs_rst_delay(data)                         (0x0000FFFF&(data))
#define  VBY1_2_ASYNC_FIFO_RST_2_get_fifo_vs_rst_en(data)                        ((0x00010000&(data))>>16)
#define  VBY1_2_ASYNC_FIFO_RST_2_get_fifo_vs_rst_delay(data)                     (0x0000FFFF&(data))

#define  VBY1_2_VBY1_DEBUG_2                                                     0x1802D850
#define  VBY1_2_VBY1_DEBUG_2_reg_addr                                            "0xB802D850"
#define  VBY1_2_VBY1_DEBUG_2_reg                                                 0xB802D850
#define  VBY1_2_VBY1_DEBUG_2_inst_addr                                           "0x000C"
#define  set_VBY1_2_VBY1_DEBUG_2_reg(data)                                       (*((volatile unsigned int*)VBY1_2_VBY1_DEBUG_2_reg)=data)
#define  get_VBY1_2_VBY1_DEBUG_2_reg                                             (*((volatile unsigned int*)VBY1_2_VBY1_DEBUG_2_reg))
#define  VBY1_2_VBY1_DEBUG_2_debug_mode_shift                                    (0)
#define  VBY1_2_VBY1_DEBUG_2_debug_mode_mask                                     (0x0000001F)
#define  VBY1_2_VBY1_DEBUG_2_debug_mode(data)                                    (0x0000001F&(data))
#define  VBY1_2_VBY1_DEBUG_2_get_debug_mode(data)                                (0x0000001F&(data))

#define  VBY1_2_VBY1_STATUS_FW_CTRL_2                                            0x1802D854
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_reg_addr                                   "0xB802D854"
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_reg                                        0xB802D854
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_inst_addr                                  "0x000D"
#define  set_VBY1_2_VBY1_STATUS_FW_CTRL_2_reg(data)                              (*((volatile unsigned int*)VBY1_2_VBY1_STATUS_FW_CTRL_2_reg)=data)
#define  get_VBY1_2_VBY1_STATUS_FW_CTRL_2_reg                                    (*((volatile unsigned int*)VBY1_2_VBY1_STATUS_FW_CTRL_2_reg))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_mode_ctrl_shift                      (31)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_mode_ctrl_shift                      (30)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_fw_htpdn_set_shift                         (29)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_fw_lockn_set_shift                         (28)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_ie_shift                             (27)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_ie_shift                             (26)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_int_status_shift                     (25)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_int_status_shift                     (24)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_vs_set_shift                  (18)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_hs_set_shift                  (17)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_shift                         (16)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_shift                                (3)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_shift                                (2)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_hw_htpdn_shift                             (1)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_hw_lockn_shift                             (0)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_mode_ctrl_mask                       (0x80000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_mode_ctrl_mask                       (0x40000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_fw_htpdn_set_mask                          (0x20000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_fw_lockn_set_mask                          (0x10000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_ie_mask                              (0x08000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_ie_mask                              (0x04000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_int_status_mask                      (0x02000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_int_status_mask                      (0x01000000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_vs_set_mask                   (0x00040000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_hs_set_mask                   (0x00020000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_mask                          (0x00010000)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_mask                                 (0x00000008)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_mask                                 (0x00000004)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_hw_htpdn_mask                              (0x00000002)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_hw_lockn_mask                              (0x00000001)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_mode_ctrl(data)                      (0x80000000&((data)<<31))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_mode_ctrl(data)                      (0x40000000&((data)<<30))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_fw_htpdn_set(data)                         (0x20000000&((data)<<29))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_fw_lockn_set(data)                         (0x10000000&((data)<<28))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_ie(data)                             (0x08000000&((data)<<27))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_ie(data)                             (0x04000000&((data)<<26))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn_int_status(data)                     (0x02000000&((data)<<25))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn_int_status(data)                     (0x01000000&((data)<<24))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_vs_set(data)                  (0x00040000&((data)<<18))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode_hs_set(data)                  (0x00020000&((data)<<17))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_de_only_mode(data)                         (0x00010000&((data)<<16))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_htpdn(data)                                (0x00000008&((data)<<3))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_lockn(data)                                (0x00000004&((data)<<2))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_hw_htpdn(data)                             (0x00000002&((data)<<1))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_hw_lockn(data)                             (0x00000001&(data))
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_htpdn_mode_ctrl(data)                  ((0x80000000&(data))>>31)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_lockn_mode_ctrl(data)                  ((0x40000000&(data))>>30)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_fw_htpdn_set(data)                     ((0x20000000&(data))>>29)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_fw_lockn_set(data)                     ((0x10000000&(data))>>28)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_htpdn_ie(data)                         ((0x08000000&(data))>>27)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_lockn_ie(data)                         ((0x04000000&(data))>>26)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_htpdn_int_status(data)                 ((0x02000000&(data))>>25)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_lockn_int_status(data)                 ((0x01000000&(data))>>24)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_de_only_mode_vs_set(data)              ((0x00040000&(data))>>18)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_de_only_mode_hs_set(data)              ((0x00020000&(data))>>17)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_de_only_mode(data)                     ((0x00010000&(data))>>16)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_htpdn(data)                            ((0x00000008&(data))>>3)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_lockn(data)                            ((0x00000004&(data))>>2)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_hw_htpdn(data)                         ((0x00000002&(data))>>1)
#define  VBY1_2_VBY1_STATUS_FW_CTRL_2_get_hw_lockn(data)                         (0x00000001&(data))

#define  VBY1_2_LANE_CRC_CONTROL_2                                               0x1802D86C
#define  VBY1_2_LANE_CRC_CONTROL_2_reg_addr                                      "0xB802D86C"
#define  VBY1_2_LANE_CRC_CONTROL_2_reg                                           0xB802D86C
#define  VBY1_2_LANE_CRC_CONTROL_2_inst_addr                                     "0x000E"
#define  set_VBY1_2_LANE_CRC_CONTROL_2_reg(data)                                 (*((volatile unsigned int*)VBY1_2_LANE_CRC_CONTROL_2_reg)=data)
#define  get_VBY1_2_LANE_CRC_CONTROL_2_reg                                       (*((volatile unsigned int*)VBY1_2_LANE_CRC_CONTROL_2_reg))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_0_crc_conti_shift                        (31)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_0_crc_start_shift                        (30)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_1_crc_conti_shift                        (29)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_1_crc_start_shift                        (28)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_2_crc_conti_shift                        (27)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_2_crc_start_shift                        (26)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_3_crc_conti_shift                        (25)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_3_crc_start_shift                        (24)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_4_crc_conti_shift                        (23)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_4_crc_start_shift                        (22)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_5_crc_conti_shift                        (21)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_5_crc_start_shift                        (20)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_6_crc_conti_shift                        (19)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_6_crc_start_shift                        (18)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_7_crc_conti_shift                        (17)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_7_crc_start_shift                        (16)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_0_crc_conti_mask                         (0x80000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_0_crc_start_mask                         (0x40000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_1_crc_conti_mask                         (0x20000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_1_crc_start_mask                         (0x10000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_2_crc_conti_mask                         (0x08000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_2_crc_start_mask                         (0x04000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_3_crc_conti_mask                         (0x02000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_3_crc_start_mask                         (0x01000000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_4_crc_conti_mask                         (0x00800000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_4_crc_start_mask                         (0x00400000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_5_crc_conti_mask                         (0x00200000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_5_crc_start_mask                         (0x00100000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_6_crc_conti_mask                         (0x00080000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_6_crc_start_mask                         (0x00040000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_7_crc_conti_mask                         (0x00020000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_7_crc_start_mask                         (0x00010000)
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_0_crc_conti(data)                        (0x80000000&((data)<<31))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_0_crc_start(data)                        (0x40000000&((data)<<30))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_1_crc_conti(data)                        (0x20000000&((data)<<29))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_1_crc_start(data)                        (0x10000000&((data)<<28))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_2_crc_conti(data)                        (0x08000000&((data)<<27))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_2_crc_start(data)                        (0x04000000&((data)<<26))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_3_crc_conti(data)                        (0x02000000&((data)<<25))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_3_crc_start(data)                        (0x01000000&((data)<<24))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_4_crc_conti(data)                        (0x00800000&((data)<<23))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_4_crc_start(data)                        (0x00400000&((data)<<22))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_5_crc_conti(data)                        (0x00200000&((data)<<21))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_5_crc_start(data)                        (0x00100000&((data)<<20))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_6_crc_conti(data)                        (0x00080000&((data)<<19))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_6_crc_start(data)                        (0x00040000&((data)<<18))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_7_crc_conti(data)                        (0x00020000&((data)<<17))
#define  VBY1_2_LANE_CRC_CONTROL_2_lane_7_crc_start(data)                        (0x00010000&((data)<<16))
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_0_crc_conti(data)                    ((0x80000000&(data))>>31)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_0_crc_start(data)                    ((0x40000000&(data))>>30)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_1_crc_conti(data)                    ((0x20000000&(data))>>29)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_1_crc_start(data)                    ((0x10000000&(data))>>28)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_2_crc_conti(data)                    ((0x08000000&(data))>>27)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_2_crc_start(data)                    ((0x04000000&(data))>>26)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_3_crc_conti(data)                    ((0x02000000&(data))>>25)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_3_crc_start(data)                    ((0x01000000&(data))>>24)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_4_crc_conti(data)                    ((0x00800000&(data))>>23)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_4_crc_start(data)                    ((0x00400000&(data))>>22)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_5_crc_conti(data)                    ((0x00200000&(data))>>21)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_5_crc_start(data)                    ((0x00100000&(data))>>20)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_6_crc_conti(data)                    ((0x00080000&(data))>>19)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_6_crc_start(data)                    ((0x00040000&(data))>>18)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_7_crc_conti(data)                    ((0x00020000&(data))>>17)
#define  VBY1_2_LANE_CRC_CONTROL_2_get_lane_7_crc_start(data)                    ((0x00010000&(data))>>16)

#define  VBY1_2_LANE_0_CRC_RESULT_2                                              0x1802D870
#define  VBY1_2_LANE_0_CRC_RESULT_2_reg_addr                                     "0xB802D870"
#define  VBY1_2_LANE_0_CRC_RESULT_2_reg                                          0xB802D870
#define  VBY1_2_LANE_0_CRC_RESULT_2_inst_addr                                    "0x000F"
#define  set_VBY1_2_LANE_0_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_0_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_0_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_0_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_0_CRC_RESULT_2_lane_0_crc_result_shift                      (0)
#define  VBY1_2_LANE_0_CRC_RESULT_2_lane_0_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_0_CRC_RESULT_2_lane_0_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_0_CRC_RESULT_2_get_lane_0_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_1_CRC_RESULT_2                                              0x1802D874
#define  VBY1_2_LANE_1_CRC_RESULT_2_reg_addr                                     "0xB802D874"
#define  VBY1_2_LANE_1_CRC_RESULT_2_reg                                          0xB802D874
#define  VBY1_2_LANE_1_CRC_RESULT_2_inst_addr                                    "0x0010"
#define  set_VBY1_2_LANE_1_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_1_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_1_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_1_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_1_CRC_RESULT_2_lane_1_crc_result_shift                      (0)
#define  VBY1_2_LANE_1_CRC_RESULT_2_lane_1_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_1_CRC_RESULT_2_lane_1_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_1_CRC_RESULT_2_get_lane_1_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_2_CRC_RESULT_2                                              0x1802D878
#define  VBY1_2_LANE_2_CRC_RESULT_2_reg_addr                                     "0xB802D878"
#define  VBY1_2_LANE_2_CRC_RESULT_2_reg                                          0xB802D878
#define  VBY1_2_LANE_2_CRC_RESULT_2_inst_addr                                    "0x0011"
#define  set_VBY1_2_LANE_2_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_2_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_2_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_2_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_2_CRC_RESULT_2_lane_2_crc_result_shift                      (0)
#define  VBY1_2_LANE_2_CRC_RESULT_2_lane_2_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_2_CRC_RESULT_2_lane_2_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_2_CRC_RESULT_2_get_lane_2_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_3_CRC_RESULT_2                                              0x1802D87C
#define  VBY1_2_LANE_3_CRC_RESULT_2_reg_addr                                     "0xB802D87C"
#define  VBY1_2_LANE_3_CRC_RESULT_2_reg                                          0xB802D87C
#define  VBY1_2_LANE_3_CRC_RESULT_2_inst_addr                                    "0x0012"
#define  set_VBY1_2_LANE_3_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_3_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_3_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_3_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_3_CRC_RESULT_2_lane_3_crc_result_shift                      (0)
#define  VBY1_2_LANE_3_CRC_RESULT_2_lane_3_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_3_CRC_RESULT_2_lane_3_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_3_CRC_RESULT_2_get_lane_3_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_4_CRC_RESULT_2                                              0x1802D880
#define  VBY1_2_LANE_4_CRC_RESULT_2_reg_addr                                     "0xB802D880"
#define  VBY1_2_LANE_4_CRC_RESULT_2_reg                                          0xB802D880
#define  VBY1_2_LANE_4_CRC_RESULT_2_inst_addr                                    "0x0013"
#define  set_VBY1_2_LANE_4_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_4_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_4_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_4_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_4_CRC_RESULT_2_lane_4_crc_result_shift                      (0)
#define  VBY1_2_LANE_4_CRC_RESULT_2_lane_4_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_4_CRC_RESULT_2_lane_4_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_4_CRC_RESULT_2_get_lane_4_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_5_CRC_RESULT_2                                              0x1802D884
#define  VBY1_2_LANE_5_CRC_RESULT_2_reg_addr                                     "0xB802D884"
#define  VBY1_2_LANE_5_CRC_RESULT_2_reg                                          0xB802D884
#define  VBY1_2_LANE_5_CRC_RESULT_2_inst_addr                                    "0x0014"
#define  set_VBY1_2_LANE_5_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_5_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_5_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_5_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_5_CRC_RESULT_2_lane_5_crc_result_shift                      (0)
#define  VBY1_2_LANE_5_CRC_RESULT_2_lane_5_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_5_CRC_RESULT_2_lane_5_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_5_CRC_RESULT_2_get_lane_5_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_6_CRC_RESULT_2                                              0x1802D888
#define  VBY1_2_LANE_6_CRC_RESULT_2_reg_addr                                     "0xB802D888"
#define  VBY1_2_LANE_6_CRC_RESULT_2_reg                                          0xB802D888
#define  VBY1_2_LANE_6_CRC_RESULT_2_inst_addr                                    "0x0015"
#define  set_VBY1_2_LANE_6_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_6_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_6_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_6_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_6_CRC_RESULT_2_lane_6_crc_result_shift                      (0)
#define  VBY1_2_LANE_6_CRC_RESULT_2_lane_6_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_6_CRC_RESULT_2_lane_6_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_6_CRC_RESULT_2_get_lane_6_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_LANE_7_CRC_RESULT_2                                              0x1802D88C
#define  VBY1_2_LANE_7_CRC_RESULT_2_reg_addr                                     "0xB802D88C"
#define  VBY1_2_LANE_7_CRC_RESULT_2_reg                                          0xB802D88C
#define  VBY1_2_LANE_7_CRC_RESULT_2_inst_addr                                    "0x0016"
#define  set_VBY1_2_LANE_7_CRC_RESULT_2_reg(data)                                (*((volatile unsigned int*)VBY1_2_LANE_7_CRC_RESULT_2_reg)=data)
#define  get_VBY1_2_LANE_7_CRC_RESULT_2_reg                                      (*((volatile unsigned int*)VBY1_2_LANE_7_CRC_RESULT_2_reg))
#define  VBY1_2_LANE_7_CRC_RESULT_2_lane_7_crc_result_shift                      (0)
#define  VBY1_2_LANE_7_CRC_RESULT_2_lane_7_crc_result_mask                       (0xFFFFFFFF)
#define  VBY1_2_LANE_7_CRC_RESULT_2_lane_7_crc_result(data)                      (0xFFFFFFFF&(data))
#define  VBY1_2_LANE_7_CRC_RESULT_2_get_lane_7_crc_result(data)                  (0xFFFFFFFF&(data))

#define  VBY1_2_DATA_CAPTURE_2_0                                                 0x1802D8B0
#define  VBY1_2_DATA_CAPTURE_2_0_reg_addr                                        "0xB802D8B0"
#define  VBY1_2_DATA_CAPTURE_2_0_reg                                             0xB802D8B0
#define  VBY1_2_DATA_CAPTURE_2_0_inst_addr                                       "0x0017"
#define  set_VBY1_2_DATA_CAPTURE_2_0_reg(data)                                   (*((volatile unsigned int*)VBY1_2_DATA_CAPTURE_2_0_reg)=data)
#define  get_VBY1_2_DATA_CAPTURE_2_0_reg                                         (*((volatile unsigned int*)VBY1_2_DATA_CAPTURE_2_0_reg))
#define  VBY1_2_DATA_CAPTURE_2_0_capture_lane_sel_shift                          (28)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_active_only_shift                       (27)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_v_shift                                 (16)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_h_shift                                 (0)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_lane_sel_mask                           (0x70000000)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_active_only_mask                        (0x08000000)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_v_mask                                  (0x07FF0000)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_h_mask                                  (0x00001FFF)
#define  VBY1_2_DATA_CAPTURE_2_0_capture_lane_sel(data)                          (0x70000000&((data)<<28))
#define  VBY1_2_DATA_CAPTURE_2_0_capture_active_only(data)                       (0x08000000&((data)<<27))
#define  VBY1_2_DATA_CAPTURE_2_0_capture_v(data)                                 (0x07FF0000&((data)<<16))
#define  VBY1_2_DATA_CAPTURE_2_0_capture_h(data)                                 (0x00001FFF&(data))
#define  VBY1_2_DATA_CAPTURE_2_0_get_capture_lane_sel(data)                      ((0x70000000&(data))>>28)
#define  VBY1_2_DATA_CAPTURE_2_0_get_capture_active_only(data)                   ((0x08000000&(data))>>27)
#define  VBY1_2_DATA_CAPTURE_2_0_get_capture_v(data)                             ((0x07FF0000&(data))>>16)
#define  VBY1_2_DATA_CAPTURE_2_0_get_capture_h(data)                             (0x00001FFF&(data))

#define  VBY1_2_DATA_CAPTURE_2_1                                                 0x1802D8B4
#define  VBY1_2_DATA_CAPTURE_2_1_reg_addr                                        "0xB802D8B4"
#define  VBY1_2_DATA_CAPTURE_2_1_reg                                             0xB802D8B4
#define  VBY1_2_DATA_CAPTURE_2_1_inst_addr                                       "0x0018"
#define  set_VBY1_2_DATA_CAPTURE_2_1_reg(data)                                   (*((volatile unsigned int*)VBY1_2_DATA_CAPTURE_2_1_reg)=data)
#define  get_VBY1_2_DATA_CAPTURE_2_1_reg                                         (*((volatile unsigned int*)VBY1_2_DATA_CAPTURE_2_1_reg))
#define  VBY1_2_DATA_CAPTURE_2_1_capture_data_39_32_shift                        (0)
#define  VBY1_2_DATA_CAPTURE_2_1_capture_data_39_32_mask                         (0x000000FF)
#define  VBY1_2_DATA_CAPTURE_2_1_capture_data_39_32(data)                        (0x000000FF&(data))
#define  VBY1_2_DATA_CAPTURE_2_1_get_capture_data_39_32(data)                    (0x000000FF&(data))

#define  VBY1_2_DATA_CAPTURE_2_2                                                 0x1802D8B8
#define  VBY1_2_DATA_CAPTURE_2_2_reg_addr                                        "0xB802D8B8"
#define  VBY1_2_DATA_CAPTURE_2_2_reg                                             0xB802D8B8
#define  VBY1_2_DATA_CAPTURE_2_2_inst_addr                                       "0x0019"
#define  set_VBY1_2_DATA_CAPTURE_2_2_reg(data)                                   (*((volatile unsigned int*)VBY1_2_DATA_CAPTURE_2_2_reg)=data)
#define  get_VBY1_2_DATA_CAPTURE_2_2_reg                                         (*((volatile unsigned int*)VBY1_2_DATA_CAPTURE_2_2_reg))
#define  VBY1_2_DATA_CAPTURE_2_2_capture_data_31_0_shift                         (0)
#define  VBY1_2_DATA_CAPTURE_2_2_capture_data_31_0_mask                          (0xFFFFFFFF)
#define  VBY1_2_DATA_CAPTURE_2_2_capture_data_31_0(data)                         (0xFFFFFFFF&(data))
#define  VBY1_2_DATA_CAPTURE_2_2_get_capture_data_31_0(data)                     (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VBY1_2 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  vby1_2_dclk_div_sel:2;
        RBus_UInt32  color_format:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  win:10;
    };
}vby1_2_video_format_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  lane_count:5;
        RBus_UInt32  res2:13;
        RBus_UInt32  byte_mode:3;
    };
}vby1_2_lane_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ctl:24;
    };
}vby1_2_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_en:1;
        RBus_UInt32  pll_stable:1;
        RBus_UInt32  transfer_en:1;
        RBus_UInt32  video_trans_mode:1;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  bs_after_aln:1;
        RBus_UInt32  be_before_aln:1;
        RBus_UInt32  reg_delay:22;
    };
}vby1_2_transmit_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802d814_31_8:24;
        RBus_UInt32  reset_sel:1;
        RBus_UInt32  num_check_fail:1;
        RBus_UInt32  aln_finish:1;
        RBus_UInt32  initial_finish:1;
        RBus_UInt32  cdr_out_en:1;
        RBus_UInt32  video_en:1;
        RBus_UInt32  aln_en:1;
        RBus_UInt32  initial_en:1;
    };
}vby1_2_transmit_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  three_mode:2;
        RBus_UInt32  three_en:1;
    };
}vby1_2_three_flag_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  reg_crc_auto_cmp_en:1;
        RBus_UInt32  reg_crc_conti:1;
        RBus_UInt32  reg_crc_start:1;
    };
}vby1_2_crc_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}vby1_2_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_crc_des:32;
    };
}vby1_2_crc_des_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_err_cnt:16;
    };
}vby1_2_crc_error_cnt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  drop_1_byte:1;
        RBus_UInt32  repeat_1_byte:1;
    };
}vby1_2_byte_repeat_drop_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  fifo_vs_rst_en:1;
        RBus_UInt32  fifo_vs_rst_delay:16;
    };
}vby1_2_async_fifo_rst_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  debug_mode:5;
    };
}vby1_2_vby1_debug_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  htpdn_mode_ctrl:1;
        RBus_UInt32  lockn_mode_ctrl:1;
        RBus_UInt32  fw_htpdn_set:1;
        RBus_UInt32  fw_lockn_set:1;
        RBus_UInt32  htpdn_ie:1;
        RBus_UInt32  lockn_ie:1;
        RBus_UInt32  htpdn_int_status:1;
        RBus_UInt32  lockn_int_status:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  de_only_mode_vs_set:1;
        RBus_UInt32  de_only_mode_hs_set:1;
        RBus_UInt32  de_only_mode:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  htpdn:1;
        RBus_UInt32  lockn:1;
        RBus_UInt32  hw_htpdn:1;
        RBus_UInt32  hw_lockn:1;
    };
}vby1_2_vby1_status_fw_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_0_crc_conti:1;
        RBus_UInt32  lane_0_crc_start:1;
        RBus_UInt32  lane_1_crc_conti:1;
        RBus_UInt32  lane_1_crc_start:1;
        RBus_UInt32  lane_2_crc_conti:1;
        RBus_UInt32  lane_2_crc_start:1;
        RBus_UInt32  lane_3_crc_conti:1;
        RBus_UInt32  lane_3_crc_start:1;
        RBus_UInt32  lane_4_crc_conti:1;
        RBus_UInt32  lane_4_crc_start:1;
        RBus_UInt32  lane_5_crc_conti:1;
        RBus_UInt32  lane_5_crc_start:1;
        RBus_UInt32  lane_6_crc_conti:1;
        RBus_UInt32  lane_6_crc_start:1;
        RBus_UInt32  lane_7_crc_conti:1;
        RBus_UInt32  lane_7_crc_start:1;
        RBus_UInt32  res1:16;
    };
}vby1_2_lane_crc_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_0_crc_result:32;
    };
}vby1_2_lane_0_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_1_crc_result:32;
    };
}vby1_2_lane_1_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_2_crc_result:32;
    };
}vby1_2_lane_2_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_3_crc_result:32;
    };
}vby1_2_lane_3_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_4_crc_result:32;
    };
}vby1_2_lane_4_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_5_crc_result:32;
    };
}vby1_2_lane_5_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_6_crc_result:32;
    };
}vby1_2_lane_6_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_7_crc_result:32;
    };
}vby1_2_lane_7_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  capture_lane_sel:3;
        RBus_UInt32  capture_active_only:1;
        RBus_UInt32  capture_v:11;
        RBus_UInt32  res2:3;
        RBus_UInt32  capture_h:13;
    };
}vby1_2_data_capture_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  capture_data_39_32:8;
    };
}vby1_2_data_capture_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  capture_data_31_0:32;
    };
}vby1_2_data_capture_2_2_RBUS;

#else //apply LITTLE_ENDIAN

//======VBY1_2 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  color_format:4;
        RBus_UInt32  vby1_2_dclk_div_sel:2;
        RBus_UInt32  res2:10;
    };
}vby1_2_video_format_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte_mode:3;
        RBus_UInt32  res1:13;
        RBus_UInt32  lane_count:5;
        RBus_UInt32  res2:11;
    };
}vby1_2_lane_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctl:24;
        RBus_UInt32  res1:8;
    };
}vby1_2_ctl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_delay:22;
        RBus_UInt32  be_before_aln:1;
        RBus_UInt32  bs_after_aln:1;
        RBus_UInt32  debounce_cnt:4;
        RBus_UInt32  video_trans_mode:1;
        RBus_UInt32  transfer_en:1;
        RBus_UInt32  pll_stable:1;
        RBus_UInt32  reg_en:1;
    };
}vby1_2_transmit_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  initial_en:1;
        RBus_UInt32  aln_en:1;
        RBus_UInt32  video_en:1;
        RBus_UInt32  cdr_out_en:1;
        RBus_UInt32  initial_finish:1;
        RBus_UInt32  aln_finish:1;
        RBus_UInt32  num_check_fail:1;
        RBus_UInt32  reset_sel:1;
        RBus_UInt32  dummy1802d814_31:24;
    };
}vby1_2_transmit_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  three_en:1;
        RBus_UInt32  three_mode:2;
        RBus_UInt32  res1:29;
    };
}vby1_2_three_flag_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_crc_start:1;
        RBus_UInt32  reg_crc_conti:1;
        RBus_UInt32  reg_crc_auto_cmp_en:1;
        RBus_UInt32  res1:29;
    };
}vby1_2_crc_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}vby1_2_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_crc_des:32;
    };
}vby1_2_crc_des_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_err_cnt:16;
        RBus_UInt32  res1:16;
    };
}vby1_2_crc_error_cnt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  repeat_1_byte:1;
        RBus_UInt32  drop_1_byte:1;
        RBus_UInt32  res1:30;
    };
}vby1_2_byte_repeat_drop_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_vs_rst_delay:16;
        RBus_UInt32  fifo_vs_rst_en:1;
        RBus_UInt32  res1:15;
    };
}vby1_2_async_fifo_rst_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:5;
        RBus_UInt32  res1:27;
    };
}vby1_2_vby1_debug_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_lockn:1;
        RBus_UInt32  hw_htpdn:1;
        RBus_UInt32  lockn:1;
        RBus_UInt32  htpdn:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  de_only_mode:1;
        RBus_UInt32  de_only_mode_hs_set:1;
        RBus_UInt32  de_only_mode_vs_set:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  lockn_int_status:1;
        RBus_UInt32  htpdn_int_status:1;
        RBus_UInt32  lockn_ie:1;
        RBus_UInt32  htpdn_ie:1;
        RBus_UInt32  fw_lockn_set:1;
        RBus_UInt32  fw_htpdn_set:1;
        RBus_UInt32  lockn_mode_ctrl:1;
        RBus_UInt32  htpdn_mode_ctrl:1;
    };
}vby1_2_vby1_status_fw_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lane_7_crc_start:1;
        RBus_UInt32  lane_7_crc_conti:1;
        RBus_UInt32  lane_6_crc_start:1;
        RBus_UInt32  lane_6_crc_conti:1;
        RBus_UInt32  lane_5_crc_start:1;
        RBus_UInt32  lane_5_crc_conti:1;
        RBus_UInt32  lane_4_crc_start:1;
        RBus_UInt32  lane_4_crc_conti:1;
        RBus_UInt32  lane_3_crc_start:1;
        RBus_UInt32  lane_3_crc_conti:1;
        RBus_UInt32  lane_2_crc_start:1;
        RBus_UInt32  lane_2_crc_conti:1;
        RBus_UInt32  lane_1_crc_start:1;
        RBus_UInt32  lane_1_crc_conti:1;
        RBus_UInt32  lane_0_crc_start:1;
        RBus_UInt32  lane_0_crc_conti:1;
    };
}vby1_2_lane_crc_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_0_crc_result:32;
    };
}vby1_2_lane_0_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_1_crc_result:32;
    };
}vby1_2_lane_1_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_2_crc_result:32;
    };
}vby1_2_lane_2_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_3_crc_result:32;
    };
}vby1_2_lane_3_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_4_crc_result:32;
    };
}vby1_2_lane_4_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_5_crc_result:32;
    };
}vby1_2_lane_5_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_6_crc_result:32;
    };
}vby1_2_lane_6_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lane_7_crc_result:32;
    };
}vby1_2_lane_7_crc_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  capture_h:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  capture_v:11;
        RBus_UInt32  capture_active_only:1;
        RBus_UInt32  capture_lane_sel:3;
        RBus_UInt32  res2:1;
    };
}vby1_2_data_capture_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  capture_data_39_32:8;
        RBus_UInt32  res1:24;
    };
}vby1_2_data_capture_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  capture_data_31_0:32;
    };
}vby1_2_data_capture_2_2_RBUS;




#endif 


#endif 
