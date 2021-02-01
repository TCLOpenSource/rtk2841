/**
* @file rbusDC_SYSReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/14
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DC_SYS_REG_H_
#define _RBUS_DC_SYS_REG_H_

#include "rbus_types.h"



//  DC_SYS Register Address
#define  DC_SYS_DC_PICT_SET                                                      0x18007000
#define  DC_SYS_DC_PICT_SET_reg_addr                                             "0xB8007000"
#define  DC_SYS_DC_PICT_SET_reg                                                  0xB8007000
#define  DC_SYS_DC_PICT_SET_inst_addr                                            "0x0000"
#define  set_DC_SYS_DC_PICT_SET_reg(data)                                        (*((volatile unsigned int*)DC_SYS_DC_PICT_SET_reg)=data)
#define  get_DC_SYS_DC_PICT_SET_reg                                              (*((volatile unsigned int*)DC_SYS_DC_PICT_SET_reg))
#define  DC_SYS_DC_PICT_SET_pict_width_scale_shift                               (17)
#define  DC_SYS_DC_PICT_SET_pict_init_page_shift                                 (0)
#define  DC_SYS_DC_PICT_SET_pict_width_scale_mask                                (0x007E0000)
#define  DC_SYS_DC_PICT_SET_pict_init_page_mask                                  (0x0001FFFF)
#define  DC_SYS_DC_PICT_SET_pict_width_scale(data)                               (0x007E0000&((data)<<17))
#define  DC_SYS_DC_PICT_SET_pict_init_page(data)                                 (0x0001FFFF&(data))
#define  DC_SYS_DC_PICT_SET_get_pict_width_scale(data)                           ((0x007E0000&(data))>>17)
#define  DC_SYS_DC_PICT_SET_get_pict_init_page(data)                             (0x0001FFFF&(data))

#define  DC_SYS_DC_SYS_MISC                                                      0x18007004
#define  DC_SYS_DC_SYS_MISC_reg_addr                                             "0xB8007004"
#define  DC_SYS_DC_SYS_MISC_reg                                                  0xB8007004
#define  DC_SYS_DC_SYS_MISC_inst_addr                                            "0x0001"
#define  set_DC_SYS_DC_SYS_MISC_reg(data)                                        (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC_reg)=data)
#define  get_DC_SYS_DC_SYS_MISC_reg                                              (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC_reg))
#define  DC_SYS_DC_SYS_MISC_dram_8g_used_shift                                   (28)
#define  DC_SYS_DC_SYS_MISC_dram_4g_used_shift                                   (27)
#define  DC_SYS_DC_SYS_MISC_ddr3_512_used_shift                                  (26)
#define  DC_SYS_DC_SYS_MISC_dram_2g_used_shift                                   (25)
#define  DC_SYS_DC_SYS_MISC_pre_arb_scheme_sel_shift                             (24)
#define  DC_SYS_DC_SYS_MISC_arb_mask_all_en_shift                                (23)
#define  DC_SYS_DC_SYS_MISC_self_lookback_mode_shift                             (20)
#define  DC_SYS_DC_SYS_MISC_mem_num_shift                                        (19)
#define  DC_SYS_DC_SYS_MISC_dis_8x2to16x1_dummy_shift                            (18)
#define  DC_SYS_DC_SYS_MISC_page_size_shift                                      (16)
#define  DC_SYS_DC_SYS_MISC_dummy_15_12_shift                                    (12)
#define  DC_SYS_DC_SYS_MISC_bank_scr_256_shift                                   (11)
#define  DC_SYS_DC_SYS_MISC_en_bank_scr_shift                                    (10)
#define  DC_SYS_DC_SYS_MISC_max_bl_size_shift                                    (9)
#define  DC_SYS_DC_SYS_MISC_en_max_bl_limit_shift                                (8)
#define  DC_SYS_DC_SYS_MISC_small_dram_4g_shift                                  (7)
#define  DC_SYS_DC_SYS_MISC_small_dram_2g_shift                                  (6)
#define  DC_SYS_DC_SYS_MISC_small_dram_1g_shift                                  (5)
#define  DC_SYS_DC_SYS_MISC_small_dram_512m_shift                                (4)
#define  DC_SYS_DC_SYS_MISC_dummy_3_1_shift                                      (1)
#define  DC_SYS_DC_SYS_MISC_en_2ddr_diff_size_shift                              (0)
#define  DC_SYS_DC_SYS_MISC_dram_8g_used_mask                                    (0x10000000)
#define  DC_SYS_DC_SYS_MISC_dram_4g_used_mask                                    (0x08000000)
#define  DC_SYS_DC_SYS_MISC_ddr3_512_used_mask                                   (0x04000000)
#define  DC_SYS_DC_SYS_MISC_dram_2g_used_mask                                    (0x02000000)
#define  DC_SYS_DC_SYS_MISC_pre_arb_scheme_sel_mask                              (0x01000000)
#define  DC_SYS_DC_SYS_MISC_arb_mask_all_en_mask                                 (0x00800000)
#define  DC_SYS_DC_SYS_MISC_self_lookback_mode_mask                              (0x00100000)
#define  DC_SYS_DC_SYS_MISC_mem_num_mask                                         (0x00080000)
#define  DC_SYS_DC_SYS_MISC_dis_8x2to16x1_dummy_mask                             (0x00040000)
#define  DC_SYS_DC_SYS_MISC_page_size_mask                                       (0x00030000)
#define  DC_SYS_DC_SYS_MISC_dummy_15_12_mask                                     (0x0000F000)
#define  DC_SYS_DC_SYS_MISC_bank_scr_256_mask                                    (0x00000800)
#define  DC_SYS_DC_SYS_MISC_en_bank_scr_mask                                     (0x00000400)
#define  DC_SYS_DC_SYS_MISC_max_bl_size_mask                                     (0x00000200)
#define  DC_SYS_DC_SYS_MISC_en_max_bl_limit_mask                                 (0x00000100)
#define  DC_SYS_DC_SYS_MISC_small_dram_4g_mask                                   (0x00000080)
#define  DC_SYS_DC_SYS_MISC_small_dram_2g_mask                                   (0x00000040)
#define  DC_SYS_DC_SYS_MISC_small_dram_1g_mask                                   (0x00000020)
#define  DC_SYS_DC_SYS_MISC_small_dram_512m_mask                                 (0x00000010)
#define  DC_SYS_DC_SYS_MISC_dummy_3_1_mask                                       (0x0000000E)
#define  DC_SYS_DC_SYS_MISC_en_2ddr_diff_size_mask                               (0x00000001)
#define  DC_SYS_DC_SYS_MISC_dram_8g_used(data)                                   (0x10000000&((data)<<28))
#define  DC_SYS_DC_SYS_MISC_dram_4g_used(data)                                   (0x08000000&((data)<<27))
#define  DC_SYS_DC_SYS_MISC_ddr3_512_used(data)                                  (0x04000000&((data)<<26))
#define  DC_SYS_DC_SYS_MISC_dram_2g_used(data)                                   (0x02000000&((data)<<25))
#define  DC_SYS_DC_SYS_MISC_pre_arb_scheme_sel(data)                             (0x01000000&((data)<<24))
#define  DC_SYS_DC_SYS_MISC_arb_mask_all_en(data)                                (0x00800000&((data)<<23))
#define  DC_SYS_DC_SYS_MISC_self_lookback_mode(data)                             (0x00100000&((data)<<20))
#define  DC_SYS_DC_SYS_MISC_mem_num(data)                                        (0x00080000&((data)<<19))
#define  DC_SYS_DC_SYS_MISC_dis_8x2to16x1_dummy(data)                            (0x00040000&((data)<<18))
#define  DC_SYS_DC_SYS_MISC_page_size(data)                                      (0x00030000&((data)<<16))
#define  DC_SYS_DC_SYS_MISC_dummy_15_12(data)                                    (0x0000F000&((data)<<12))
#define  DC_SYS_DC_SYS_MISC_bank_scr_256(data)                                   (0x00000800&((data)<<11))
#define  DC_SYS_DC_SYS_MISC_en_bank_scr(data)                                    (0x00000400&((data)<<10))
#define  DC_SYS_DC_SYS_MISC_max_bl_size(data)                                    (0x00000200&((data)<<9))
#define  DC_SYS_DC_SYS_MISC_en_max_bl_limit(data)                                (0x00000100&((data)<<8))
#define  DC_SYS_DC_SYS_MISC_small_dram_4g(data)                                  (0x00000080&((data)<<7))
#define  DC_SYS_DC_SYS_MISC_small_dram_2g(data)                                  (0x00000040&((data)<<6))
#define  DC_SYS_DC_SYS_MISC_small_dram_1g(data)                                  (0x00000020&((data)<<5))
#define  DC_SYS_DC_SYS_MISC_small_dram_512m(data)                                (0x00000010&((data)<<4))
#define  DC_SYS_DC_SYS_MISC_dummy_3_1(data)                                      (0x0000000E&((data)<<1))
#define  DC_SYS_DC_SYS_MISC_en_2ddr_diff_size(data)                              (0x00000001&(data))
#define  DC_SYS_DC_SYS_MISC_get_dram_8g_used(data)                               ((0x10000000&(data))>>28)
#define  DC_SYS_DC_SYS_MISC_get_dram_4g_used(data)                               ((0x08000000&(data))>>27)
#define  DC_SYS_DC_SYS_MISC_get_ddr3_512_used(data)                              ((0x04000000&(data))>>26)
#define  DC_SYS_DC_SYS_MISC_get_dram_2g_used(data)                               ((0x02000000&(data))>>25)
#define  DC_SYS_DC_SYS_MISC_get_pre_arb_scheme_sel(data)                         ((0x01000000&(data))>>24)
#define  DC_SYS_DC_SYS_MISC_get_arb_mask_all_en(data)                            ((0x00800000&(data))>>23)
#define  DC_SYS_DC_SYS_MISC_get_self_lookback_mode(data)                         ((0x00100000&(data))>>20)
#define  DC_SYS_DC_SYS_MISC_get_mem_num(data)                                    ((0x00080000&(data))>>19)
#define  DC_SYS_DC_SYS_MISC_get_dis_8x2to16x1_dummy(data)                        ((0x00040000&(data))>>18)
#define  DC_SYS_DC_SYS_MISC_get_page_size(data)                                  ((0x00030000&(data))>>16)
#define  DC_SYS_DC_SYS_MISC_get_dummy_15_12(data)                                ((0x0000F000&(data))>>12)
#define  DC_SYS_DC_SYS_MISC_get_bank_scr_256(data)                               ((0x00000800&(data))>>11)
#define  DC_SYS_DC_SYS_MISC_get_en_bank_scr(data)                                ((0x00000400&(data))>>10)
#define  DC_SYS_DC_SYS_MISC_get_max_bl_size(data)                                ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SYS_MISC_get_en_max_bl_limit(data)                            ((0x00000100&(data))>>8)
#define  DC_SYS_DC_SYS_MISC_get_small_dram_4g(data)                              ((0x00000080&(data))>>7)
#define  DC_SYS_DC_SYS_MISC_get_small_dram_2g(data)                              ((0x00000040&(data))>>6)
#define  DC_SYS_DC_SYS_MISC_get_small_dram_1g(data)                              ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SYS_MISC_get_small_dram_512m(data)                            ((0x00000010&(data))>>4)
#define  DC_SYS_DC_SYS_MISC_get_dummy_3_1(data)                                  ((0x0000000E&(data))>>1)
#define  DC_SYS_DC_SYS_MISC_get_en_2ddr_diff_size(data)                          (0x00000001&(data))

#define  DC_SYS_dc_pic_offset_x_detection                                        0x18007010
#define  DC_SYS_dc_pic_offset_x_detection_reg_addr                               "0xB8007010"
#define  DC_SYS_dc_pic_offset_x_detection_reg                                    0xB8007010
#define  DC_SYS_dc_pic_offset_x_detection_inst_addr                              "0x0002"
#define  set_DC_SYS_dc_pic_offset_x_detection_reg(data)                          (*((volatile unsigned int*)DC_SYS_dc_pic_offset_x_detection_reg)=data)
#define  get_DC_SYS_dc_pic_offset_x_detection_reg                                (*((volatile unsigned int*)DC_SYS_dc_pic_offset_x_detection_reg))
#define  DC_SYS_dc_pic_offset_x_detection_enable_shift                           (0)
#define  DC_SYS_dc_pic_offset_x_detection_enable_mask                            (0x00000001)
#define  DC_SYS_dc_pic_offset_x_detection_enable(data)                           (0x00000001&(data))
#define  DC_SYS_dc_pic_offset_x_detection_get_enable(data)                       (0x00000001&(data))

#define  DC_SYS_DC_PICT_SET_OFFSET                                               0x18007020
#define  DC_SYS_DC_PICT_SET_OFFSET_reg_addr                                      "0xB8007020"
#define  DC_SYS_DC_PICT_SET_OFFSET_reg                                           0xB8007020
#define  DC_SYS_DC_PICT_SET_OFFSET_inst_addr                                     "0x0003"
#define  set_DC_SYS_DC_PICT_SET_OFFSET_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_PICT_SET_OFFSET_reg)=data)
#define  get_DC_SYS_DC_PICT_SET_OFFSET_reg                                       (*((volatile unsigned int*)DC_SYS_DC_PICT_SET_OFFSET_reg))
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_num_shift                            (24)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_offset_rd_shift                          (23)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_wide_shift                           (20)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y_shift                       (10)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x_shift                       (0)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_num_mask                             (0xFF000000)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_offset_rd_mask                           (0x00800000)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_wide_mask                            (0x00100000)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y_mask                        (0x000FFC00)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x_mask                        (0x000003FF)
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_num(data)                            (0xFF000000&((data)<<24))
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_offset_rd(data)                          (0x00800000&((data)<<23))
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_wide(data)                           (0x00100000&((data)<<20))
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(data)                       (0x000FFC00&((data)<<10))
#define  DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(data)                       (0x000003FF&(data))
#define  DC_SYS_DC_PICT_SET_OFFSET_get_pict_set_num(data)                        ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_PICT_SET_OFFSET_get_pict_offset_rd(data)                      ((0x00800000&(data))>>23)
#define  DC_SYS_DC_PICT_SET_OFFSET_get_pict_set_wide(data)                       ((0x00100000&(data))>>20)
#define  DC_SYS_DC_PICT_SET_OFFSET_get_pict_set_offset_y(data)                   ((0x000FFC00&(data))>>10)
#define  DC_SYS_DC_PICT_SET_OFFSET_get_pict_set_offset_x(data)                   (0x000003FF&(data))

#define  DC_SYS_DC_REQ_STATUS                                                    0x18007024
#define  DC_SYS_DC_REQ_STATUS_reg_addr                                           "0xB8007024"
#define  DC_SYS_DC_REQ_STATUS_reg                                                0xB8007024
#define  DC_SYS_DC_REQ_STATUS_inst_addr                                          "0x0004"
#define  set_DC_SYS_DC_REQ_STATUS_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_REQ_STATUS_reg)=data)
#define  get_DC_SYS_DC_REQ_STATUS_reg                                            (*((volatile unsigned int*)DC_SYS_DC_REQ_STATUS_reg))
#define  DC_SYS_DC_REQ_STATUS_req_pending_shift                                  (16)
#define  DC_SYS_DC_REQ_STATUS_req_id_shift                                       (0)
#define  DC_SYS_DC_REQ_STATUS_req_pending_mask                                   (0x00010000)
#define  DC_SYS_DC_REQ_STATUS_req_id_mask                                        (0x00001FFF)
#define  DC_SYS_DC_REQ_STATUS_req_pending(data)                                  (0x00010000&((data)<<16))
#define  DC_SYS_DC_REQ_STATUS_req_id(data)                                       (0x00001FFF&(data))
#define  DC_SYS_DC_REQ_STATUS_get_req_pending(data)                              ((0x00010000&(data))>>16)
#define  DC_SYS_DC_REQ_STATUS_get_req_id(data)                                   (0x00001FFF&(data))

#define  DC_SYS_DC_SYS_MISC2                                                     0x18007028
#define  DC_SYS_DC_SYS_MISC2_reg_addr                                            "0xB8007028"
#define  DC_SYS_DC_SYS_MISC2_reg                                                 0xB8007028
#define  DC_SYS_DC_SYS_MISC2_inst_addr                                           "0x0005"
#define  set_DC_SYS_DC_SYS_MISC2_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC2_reg)=data)
#define  get_DC_SYS_DC_SYS_MISC2_reg                                             (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC2_reg))
#define  DC_SYS_DC_SYS_MISC2_pre_arb_merge_shift                                 (31)
#define  DC_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold_shift                      (24)
#define  DC_SYS_DC_SYS_MISC2_full_cmd_count_shift                                (20)
#define  DC_SYS_DC_SYS_MISC2_pre_tra_rd_cnt_shift                                (10)
#define  DC_SYS_DC_SYS_MISC2_pre_tra_wr_cnt_shift                                (0)
#define  DC_SYS_DC_SYS_MISC2_pre_arb_merge_mask                                  (0x80000000)
#define  DC_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold_mask                       (0x07000000)
#define  DC_SYS_DC_SYS_MISC2_full_cmd_count_mask                                 (0x00F00000)
#define  DC_SYS_DC_SYS_MISC2_pre_tra_rd_cnt_mask                                 (0x000FFC00)
#define  DC_SYS_DC_SYS_MISC2_pre_tra_wr_cnt_mask                                 (0x000003FF)
#define  DC_SYS_DC_SYS_MISC2_pre_arb_merge(data)                                 (0x80000000&((data)<<31))
#define  DC_SYS_DC_SYS_MISC2_qfifo_cnt_full_threshold(data)                      (0x07000000&((data)<<24))
#define  DC_SYS_DC_SYS_MISC2_full_cmd_count(data)                                (0x00F00000&((data)<<20))
#define  DC_SYS_DC_SYS_MISC2_pre_tra_rd_cnt(data)                                (0x000FFC00&((data)<<10))
#define  DC_SYS_DC_SYS_MISC2_pre_tra_wr_cnt(data)                                (0x000003FF&(data))
#define  DC_SYS_DC_SYS_MISC2_get_pre_arb_merge(data)                             ((0x80000000&(data))>>31)
#define  DC_SYS_DC_SYS_MISC2_get_qfifo_cnt_full_threshold(data)                  ((0x07000000&(data))>>24)
#define  DC_SYS_DC_SYS_MISC2_get_full_cmd_count(data)                            ((0x00F00000&(data))>>20)
#define  DC_SYS_DC_SYS_MISC2_get_pre_tra_rd_cnt(data)                            ((0x000FFC00&(data))>>10)
#define  DC_SYS_DC_SYS_MISC2_get_pre_tra_wr_cnt(data)                            (0x000003FF&(data))

#define  DC_SYS_DC_SYS_MISC3                                                     0x1800702C
#define  DC_SYS_DC_SYS_MISC3_reg_addr                                            "0xB800702C"
#define  DC_SYS_DC_SYS_MISC3_reg                                                 0xB800702C
#define  DC_SYS_DC_SYS_MISC3_inst_addr                                           "0x0006"
#define  set_DC_SYS_DC_SYS_MISC3_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC3_reg)=data)
#define  get_DC_SYS_DC_SYS_MISC3_reg                                             (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC3_reg))
#define  DC_SYS_DC_SYS_MISC3_ve2_id_gen_en_shift                                 (31)
#define  DC_SYS_DC_SYS_MISC3_ve_id_gen_en_shift                                  (30)
#define  DC_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold_shift                      (24)
#define  DC_SYS_DC_SYS_MISC3_memc_cmd_queue_flush_shift                          (21)
#define  DC_SYS_DC_SYS_MISC3_memc_cmd_grp_disable_shift                          (20)
#define  DC_SYS_DC_SYS_MISC3_se2_cmd_queue_flush_shift                           (19)
#define  DC_SYS_DC_SYS_MISC3_se2_cmd_grp_disable_shift                           (18)
#define  DC_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush_shift                           (17)
#define  DC_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable_shift                           (16)
#define  DC_SYS_DC_SYS_MISC3_ve_cmd_queue_flush_shift                            (9)
#define  DC_SYS_DC_SYS_MISC3_ve_cmd_grp_disable_shift                            (8)
#define  DC_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush_shift                         (7)
#define  DC_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable_shift                         (6)
#define  DC_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush_shift                         (5)
#define  DC_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable_shift                         (4)
#define  DC_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant_shift              (2)
#define  DC_SYS_DC_SYS_MISC3_gpu_cmd_queue_flush_shift                           (1)
#define  DC_SYS_DC_SYS_MISC3_gpu_cmd_grp_disable_shift                           (0)
#define  DC_SYS_DC_SYS_MISC3_ve2_id_gen_en_mask                                  (0x80000000)
#define  DC_SYS_DC_SYS_MISC3_ve_id_gen_en_mask                                   (0x40000000)
#define  DC_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold_mask                       (0x07000000)
#define  DC_SYS_DC_SYS_MISC3_memc_cmd_queue_flush_mask                           (0x00200000)
#define  DC_SYS_DC_SYS_MISC3_memc_cmd_grp_disable_mask                           (0x00100000)
#define  DC_SYS_DC_SYS_MISC3_se2_cmd_queue_flush_mask                            (0x00080000)
#define  DC_SYS_DC_SYS_MISC3_se2_cmd_grp_disable_mask                            (0x00040000)
#define  DC_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush_mask                            (0x00020000)
#define  DC_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable_mask                            (0x00010000)
#define  DC_SYS_DC_SYS_MISC3_ve_cmd_queue_flush_mask                             (0x00000200)
#define  DC_SYS_DC_SYS_MISC3_ve_cmd_grp_disable_mask                             (0x00000100)
#define  DC_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush_mask                          (0x00000080)
#define  DC_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable_mask                          (0x00000040)
#define  DC_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush_mask                          (0x00000020)
#define  DC_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable_mask                          (0x00000010)
#define  DC_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant_mask               (0x00000004)
#define  DC_SYS_DC_SYS_MISC3_gpu_cmd_queue_flush_mask                            (0x00000002)
#define  DC_SYS_DC_SYS_MISC3_gpu_cmd_grp_disable_mask                            (0x00000001)
#define  DC_SYS_DC_SYS_MISC3_ve2_id_gen_en(data)                                 (0x80000000&((data)<<31))
#define  DC_SYS_DC_SYS_MISC3_ve_id_gen_en(data)                                  (0x40000000&((data)<<30))
#define  DC_SYS_DC_SYS_MISC3_wfifo_cnt_full_threshold(data)                      (0x07000000&((data)<<24))
#define  DC_SYS_DC_SYS_MISC3_memc_cmd_queue_flush(data)                          (0x00200000&((data)<<21))
#define  DC_SYS_DC_SYS_MISC3_memc_cmd_grp_disable(data)                          (0x00100000&((data)<<20))
#define  DC_SYS_DC_SYS_MISC3_se2_cmd_queue_flush(data)                           (0x00080000&((data)<<19))
#define  DC_SYS_DC_SYS_MISC3_se2_cmd_grp_disable(data)                           (0x00040000&((data)<<18))
#define  DC_SYS_DC_SYS_MISC3_ve2_cmd_queue_flush(data)                           (0x00020000&((data)<<17))
#define  DC_SYS_DC_SYS_MISC3_ve2_cmd_grp_disable(data)                           (0x00010000&((data)<<16))
#define  DC_SYS_DC_SYS_MISC3_ve_cmd_queue_flush(data)                            (0x00000200&((data)<<9))
#define  DC_SYS_DC_SYS_MISC3_ve_cmd_grp_disable(data)                            (0x00000100&((data)<<8))
#define  DC_SYS_DC_SYS_MISC3_tvsb4_cmd_queue_flush(data)                         (0x00000080&((data)<<7))
#define  DC_SYS_DC_SYS_MISC3_tvsb4_cmd_grp_disable(data)                         (0x00000040&((data)<<6))
#define  DC_SYS_DC_SYS_MISC3_tvsb3_cmd_queue_flush(data)                         (0x00000020&((data)<<5))
#define  DC_SYS_DC_SYS_MISC3_tvsb3_cmd_grp_disable(data)                         (0x00000010&((data)<<4))
#define  DC_SYS_DC_SYS_MISC3_enable_arb_delay_by_tv_sb1_grant(data)              (0x00000004&((data)<<2))
#define  DC_SYS_DC_SYS_MISC3_gpu_cmd_queue_flush(data)                           (0x00000002&((data)<<1))
#define  DC_SYS_DC_SYS_MISC3_gpu_cmd_grp_disable(data)                           (0x00000001&(data))
#define  DC_SYS_DC_SYS_MISC3_get_ve2_id_gen_en(data)                             ((0x80000000&(data))>>31)
#define  DC_SYS_DC_SYS_MISC3_get_ve_id_gen_en(data)                              ((0x40000000&(data))>>30)
#define  DC_SYS_DC_SYS_MISC3_get_wfifo_cnt_full_threshold(data)                  ((0x07000000&(data))>>24)
#define  DC_SYS_DC_SYS_MISC3_get_memc_cmd_queue_flush(data)                      ((0x00200000&(data))>>21)
#define  DC_SYS_DC_SYS_MISC3_get_memc_cmd_grp_disable(data)                      ((0x00100000&(data))>>20)
#define  DC_SYS_DC_SYS_MISC3_get_se2_cmd_queue_flush(data)                       ((0x00080000&(data))>>19)
#define  DC_SYS_DC_SYS_MISC3_get_se2_cmd_grp_disable(data)                       ((0x00040000&(data))>>18)
#define  DC_SYS_DC_SYS_MISC3_get_ve2_cmd_queue_flush(data)                       ((0x00020000&(data))>>17)
#define  DC_SYS_DC_SYS_MISC3_get_ve2_cmd_grp_disable(data)                       ((0x00010000&(data))>>16)
#define  DC_SYS_DC_SYS_MISC3_get_ve_cmd_queue_flush(data)                        ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SYS_MISC3_get_ve_cmd_grp_disable(data)                        ((0x00000100&(data))>>8)
#define  DC_SYS_DC_SYS_MISC3_get_tvsb4_cmd_queue_flush(data)                     ((0x00000080&(data))>>7)
#define  DC_SYS_DC_SYS_MISC3_get_tvsb4_cmd_grp_disable(data)                     ((0x00000040&(data))>>6)
#define  DC_SYS_DC_SYS_MISC3_get_tvsb3_cmd_queue_flush(data)                     ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SYS_MISC3_get_tvsb3_cmd_grp_disable(data)                     ((0x00000010&(data))>>4)
#define  DC_SYS_DC_SYS_MISC3_get_enable_arb_delay_by_tv_sb1_grant(data)          ((0x00000004&(data))>>2)
#define  DC_SYS_DC_SYS_MISC3_get_gpu_cmd_queue_flush(data)                       ((0x00000002&(data))>>1)
#define  DC_SYS_DC_SYS_MISC3_get_gpu_cmd_grp_disable(data)                       (0x00000001&(data))

#define  DC_SYS_DC_SYS_MISC4                                                     0x18007030
#define  DC_SYS_DC_SYS_MISC4_reg_addr                                            "0xB8007030"
#define  DC_SYS_DC_SYS_MISC4_reg                                                 0xB8007030
#define  DC_SYS_DC_SYS_MISC4_inst_addr                                           "0x0007"
#define  set_DC_SYS_DC_SYS_MISC4_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC4_reg)=data)
#define  get_DC_SYS_DC_SYS_MISC4_reg                                             (*((volatile unsigned int*)DC_SYS_DC_SYS_MISC4_reg))
#define  DC_SYS_DC_SYS_MISC4_memc_space_margin_shift                             (24)
#define  DC_SYS_DC_SYS_MISC4_se2_space_margin_shift                              (20)
#define  DC_SYS_DC_SYS_MISC4_ve2_space_margin_shift                              (16)
#define  DC_SYS_DC_SYS_MISC4_ve_space_margin_shift                               (12)
#define  DC_SYS_DC_SYS_MISC4_tvsb4_space_margin_shift                            (8)
#define  DC_SYS_DC_SYS_MISC4_tvsb3_space_margin_shift                            (4)
#define  DC_SYS_DC_SYS_MISC4_gpu_space_margin_shift                              (0)
#define  DC_SYS_DC_SYS_MISC4_memc_space_margin_mask                              (0x0F000000)
#define  DC_SYS_DC_SYS_MISC4_se2_space_margin_mask                               (0x00F00000)
#define  DC_SYS_DC_SYS_MISC4_ve2_space_margin_mask                               (0x000F0000)
#define  DC_SYS_DC_SYS_MISC4_ve_space_margin_mask                                (0x0000F000)
#define  DC_SYS_DC_SYS_MISC4_tvsb4_space_margin_mask                             (0x00000F00)
#define  DC_SYS_DC_SYS_MISC4_tvsb3_space_margin_mask                             (0x000000F0)
#define  DC_SYS_DC_SYS_MISC4_gpu_space_margin_mask                               (0x0000000F)
#define  DC_SYS_DC_SYS_MISC4_memc_space_margin(data)                             (0x0F000000&((data)<<24))
#define  DC_SYS_DC_SYS_MISC4_se2_space_margin(data)                              (0x00F00000&((data)<<20))
#define  DC_SYS_DC_SYS_MISC4_ve2_space_margin(data)                              (0x000F0000&((data)<<16))
#define  DC_SYS_DC_SYS_MISC4_ve_space_margin(data)                               (0x0000F000&((data)<<12))
#define  DC_SYS_DC_SYS_MISC4_tvsb4_space_margin(data)                            (0x00000F00&((data)<<8))
#define  DC_SYS_DC_SYS_MISC4_tvsb3_space_margin(data)                            (0x000000F0&((data)<<4))
#define  DC_SYS_DC_SYS_MISC4_gpu_space_margin(data)                              (0x0000000F&(data))
#define  DC_SYS_DC_SYS_MISC4_get_memc_space_margin(data)                         ((0x0F000000&(data))>>24)
#define  DC_SYS_DC_SYS_MISC4_get_se2_space_margin(data)                          ((0x00F00000&(data))>>20)
#define  DC_SYS_DC_SYS_MISC4_get_ve2_space_margin(data)                          ((0x000F0000&(data))>>16)
#define  DC_SYS_DC_SYS_MISC4_get_ve_space_margin(data)                           ((0x0000F000&(data))>>12)
#define  DC_SYS_DC_SYS_MISC4_get_tvsb4_space_margin(data)                        ((0x00000F00&(data))>>8)
#define  DC_SYS_DC_SYS_MISC4_get_tvsb3_space_margin(data)                        ((0x000000F0&(data))>>4)
#define  DC_SYS_DC_SYS_MISC4_get_gpu_space_margin(data)                          (0x0000000F&(data))

#define  DC_SYS_DC_sfmode0                                                       0x18007040
#define  DC_SYS_DC_sfmode0_reg_addr                                              "0xB8007040"
#define  DC_SYS_DC_sfmode0_reg                                                   0xB8007040
#define  DC_SYS_DC_sfmode0_inst_addr                                             "0x0008"
#define  set_DC_SYS_DC_sfmode0_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_sfmode0_reg)=data)
#define  get_DC_SYS_DC_sfmode0_reg                                               (*((volatile unsigned int*)DC_SYS_DC_sfmode0_reg))
#define  DC_SYS_DC_sfmode0_sfmode_pattern0_shift                                 (0)
#define  DC_SYS_DC_sfmode0_sfmode_pattern0_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode0_sfmode_pattern0(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode0_get_sfmode_pattern0(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode1                                                       0x18007044
#define  DC_SYS_DC_sfmode1_reg_addr                                              "0xB8007044"
#define  DC_SYS_DC_sfmode1_reg                                                   0xB8007044
#define  DC_SYS_DC_sfmode1_inst_addr                                             "0x0009"
#define  set_DC_SYS_DC_sfmode1_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_sfmode1_reg)=data)
#define  get_DC_SYS_DC_sfmode1_reg                                               (*((volatile unsigned int*)DC_SYS_DC_sfmode1_reg))
#define  DC_SYS_DC_sfmode1_sfmode_pattern1_shift                                 (0)
#define  DC_SYS_DC_sfmode1_sfmode_pattern1_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode1_sfmode_pattern1(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode1_get_sfmode_pattern1(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode2                                                       0x18007048
#define  DC_SYS_DC_sfmode2_reg_addr                                              "0xB8007048"
#define  DC_SYS_DC_sfmode2_reg                                                   0xB8007048
#define  DC_SYS_DC_sfmode2_inst_addr                                             "0x000A"
#define  set_DC_SYS_DC_sfmode2_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_sfmode2_reg)=data)
#define  get_DC_SYS_DC_sfmode2_reg                                               (*((volatile unsigned int*)DC_SYS_DC_sfmode2_reg))
#define  DC_SYS_DC_sfmode2_sfmode_pattern2_shift                                 (0)
#define  DC_SYS_DC_sfmode2_sfmode_pattern2_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode2_sfmode_pattern2(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode2_get_sfmode_pattern2(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode3                                                       0x1800704C
#define  DC_SYS_DC_sfmode3_reg_addr                                              "0xB800704C"
#define  DC_SYS_DC_sfmode3_reg                                                   0xB800704C
#define  DC_SYS_DC_sfmode3_inst_addr                                             "0x000B"
#define  set_DC_SYS_DC_sfmode3_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_sfmode3_reg)=data)
#define  get_DC_SYS_DC_sfmode3_reg                                               (*((volatile unsigned int*)DC_SYS_DC_sfmode3_reg))
#define  DC_SYS_DC_sfmode3_sfmode_pattern3_shift                                 (0)
#define  DC_SYS_DC_sfmode3_sfmode_pattern3_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode3_sfmode_pattern3(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode3_get_sfmode_pattern3(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode_cmp0                                                   0x18007050
#define  DC_SYS_DC_sfmode_cmp0_reg_addr                                          "0xB8007050"
#define  DC_SYS_DC_sfmode_cmp0_reg                                               0xB8007050
#define  DC_SYS_DC_sfmode_cmp0_inst_addr                                         "0x000C"
#define  set_DC_SYS_DC_sfmode_cmp0_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp0_reg)=data)
#define  get_DC_SYS_DC_sfmode_cmp0_reg                                           (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp0_reg))
#define  DC_SYS_DC_sfmode_cmp0_sfmode_cmp_rlt0_shift                             (0)
#define  DC_SYS_DC_sfmode_cmp0_sfmode_cmp_rlt0_mask                              (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode_cmp0_sfmode_cmp_rlt0(data)                             (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode_cmp0_get_sfmode_cmp_rlt0(data)                         (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode_cmp1                                                   0x18007054
#define  DC_SYS_DC_sfmode_cmp1_reg_addr                                          "0xB8007054"
#define  DC_SYS_DC_sfmode_cmp1_reg                                               0xB8007054
#define  DC_SYS_DC_sfmode_cmp1_inst_addr                                         "0x000D"
#define  set_DC_SYS_DC_sfmode_cmp1_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp1_reg)=data)
#define  get_DC_SYS_DC_sfmode_cmp1_reg                                           (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp1_reg))
#define  DC_SYS_DC_sfmode_cmp1_sfmode_cmp_rlt1_shift                             (0)
#define  DC_SYS_DC_sfmode_cmp1_sfmode_cmp_rlt1_mask                              (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode_cmp1_sfmode_cmp_rlt1(data)                             (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode_cmp1_get_sfmode_cmp_rlt1(data)                         (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode_cmp2                                                   0x18007058
#define  DC_SYS_DC_sfmode_cmp2_reg_addr                                          "0xB8007058"
#define  DC_SYS_DC_sfmode_cmp2_reg                                               0xB8007058
#define  DC_SYS_DC_sfmode_cmp2_inst_addr                                         "0x000E"
#define  set_DC_SYS_DC_sfmode_cmp2_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp2_reg)=data)
#define  get_DC_SYS_DC_sfmode_cmp2_reg                                           (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp2_reg))
#define  DC_SYS_DC_sfmode_cmp2_sfmode_cmp_rlt2_shift                             (0)
#define  DC_SYS_DC_sfmode_cmp2_sfmode_cmp_rlt2_mask                              (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode_cmp2_sfmode_cmp_rlt2(data)                             (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode_cmp2_get_sfmode_cmp_rlt2(data)                         (0xFFFFFFFF&(data))

#define  DC_SYS_DC_sfmode_cmp3                                                   0x1800705C
#define  DC_SYS_DC_sfmode_cmp3_reg_addr                                          "0xB800705C"
#define  DC_SYS_DC_sfmode_cmp3_reg                                               0xB800705C
#define  DC_SYS_DC_sfmode_cmp3_inst_addr                                         "0x000F"
#define  set_DC_SYS_DC_sfmode_cmp3_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp3_reg)=data)
#define  get_DC_SYS_DC_sfmode_cmp3_reg                                           (*((volatile unsigned int*)DC_SYS_DC_sfmode_cmp3_reg))
#define  DC_SYS_DC_sfmode_cmp3_sfmode_cmp_rlt3_shift                             (0)
#define  DC_SYS_DC_sfmode_cmp3_sfmode_cmp_rlt3_mask                              (0xFFFFFFFF)
#define  DC_SYS_DC_sfmode_cmp3_sfmode_cmp_rlt3(data)                             (0xFFFFFFFF&(data))
#define  DC_SYS_DC_sfmode_cmp3_get_sfmode_cmp_rlt3(data)                         (0xFFFFFFFF&(data))

#define  DC_SYS_DC_debug_ctrl                                                    0x18007060
#define  DC_SYS_DC_debug_ctrl_reg_addr                                           "0xB8007060"
#define  DC_SYS_DC_debug_ctrl_reg                                                0xB8007060
#define  DC_SYS_DC_debug_ctrl_inst_addr                                          "0x0010"
#define  set_DC_SYS_DC_debug_ctrl_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_debug_ctrl_reg)=data)
#define  get_DC_SYS_DC_debug_ctrl_reg                                            (*((volatile unsigned int*)DC_SYS_DC_debug_ctrl_reg))
#define  DC_SYS_DC_debug_ctrl_debug_sys_sel_shift                                (17)
#define  DC_SYS_DC_debug_ctrl_debug_en_shift                                     (16)
#define  DC_SYS_DC_debug_ctrl_debug_sel_1_shift                                  (8)
#define  DC_SYS_DC_debug_ctrl_debug_sel_0_shift                                  (0)
#define  DC_SYS_DC_debug_ctrl_debug_sys_sel_mask                                 (0x00060000)
#define  DC_SYS_DC_debug_ctrl_debug_en_mask                                      (0x00010000)
#define  DC_SYS_DC_debug_ctrl_debug_sel_1_mask                                   (0x00003F00)
#define  DC_SYS_DC_debug_ctrl_debug_sel_0_mask                                   (0x0000003F)
#define  DC_SYS_DC_debug_ctrl_debug_sys_sel(data)                                (0x00060000&((data)<<17))
#define  DC_SYS_DC_debug_ctrl_debug_en(data)                                     (0x00010000&((data)<<16))
#define  DC_SYS_DC_debug_ctrl_debug_sel_1(data)                                  (0x00003F00&((data)<<8))
#define  DC_SYS_DC_debug_ctrl_debug_sel_0(data)                                  (0x0000003F&(data))
#define  DC_SYS_DC_debug_ctrl_get_debug_sys_sel(data)                            ((0x00060000&(data))>>17)
#define  DC_SYS_DC_debug_ctrl_get_debug_en(data)                                 ((0x00010000&(data))>>16)
#define  DC_SYS_DC_debug_ctrl_get_debug_sel_1(data)                              ((0x00003F00&(data))>>8)
#define  DC_SYS_DC_debug_ctrl_get_debug_sel_0(data)                              (0x0000003F&(data))

#define  DC_SYS_DC_debug_out                                                     0x18007068
#define  DC_SYS_DC_debug_out_reg_addr                                            "0xB8007068"
#define  DC_SYS_DC_debug_out_reg                                                 0xB8007068
#define  DC_SYS_DC_debug_out_inst_addr                                           "0x0011"
#define  set_DC_SYS_DC_debug_out_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_debug_out_reg)=data)
#define  get_DC_SYS_DC_debug_out_reg                                             (*((volatile unsigned int*)DC_SYS_DC_debug_out_reg))
#define  DC_SYS_DC_debug_out_dbg_sys_out1_shift                                  (16)
#define  DC_SYS_DC_debug_out_dbg_sys_out0_shift                                  (0)
#define  DC_SYS_DC_debug_out_dbg_sys_out1_mask                                   (0xFFFF0000)
#define  DC_SYS_DC_debug_out_dbg_sys_out0_mask                                   (0x0000FFFF)
#define  DC_SYS_DC_debug_out_dbg_sys_out1(data)                                  (0xFFFF0000&((data)<<16))
#define  DC_SYS_DC_debug_out_dbg_sys_out0(data)                                  (0x0000FFFF&(data))
#define  DC_SYS_DC_debug_out_get_dbg_sys_out1(data)                              ((0xFFFF0000&(data))>>16)
#define  DC_SYS_DC_debug_out_get_dbg_sys_out0(data)                              (0x0000FFFF&(data))

#define  DC_SYS_DC_debug_status                                                  0x18007064
#define  DC_SYS_DC_debug_status_reg_addr                                         "0xB8007064"
#define  DC_SYS_DC_debug_status_reg                                              0xB8007064
#define  DC_SYS_DC_debug_status_inst_addr                                        "0x0012"
#define  set_DC_SYS_DC_debug_status_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_debug_status_reg)=data)
#define  get_DC_SYS_DC_debug_status_reg                                          (*((volatile unsigned int*)DC_SYS_DC_debug_status_reg))
#define  DC_SYS_DC_debug_status_exsram_fifo_underflow_shift                      (25)
#define  DC_SYS_DC_debug_status_exsram_fifo_overflow_shift                       (24)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_2_underflow_shift                 (23)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_1_underflow_shift                 (22)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_0_underflow_shift                 (21)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_2_underflow_shift                  (20)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_1_underflow_shift                  (19)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_0_underflow_shift                  (18)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_2_overflow_shift                  (17)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_1_overflow_shift                  (16)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_0_overflow_shift                  (15)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_2_overflow_shift                   (14)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_1_overflow_shift                   (13)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_0_overflow_shift                   (12)
#define  DC_SYS_DC_debug_status_write_fifo_2_underflow_shift                     (11)
#define  DC_SYS_DC_debug_status_write_fifo_1_underflow_shift                     (10)
#define  DC_SYS_DC_debug_status_write_fifo_0_underflow_shift                     (9)
#define  DC_SYS_DC_debug_status_read_fifo_2_underflow_shift                      (8)
#define  DC_SYS_DC_debug_status_read_fifo_1_underflow_shift                      (7)
#define  DC_SYS_DC_debug_status_read_fifo_0_underflow_shift                      (6)
#define  DC_SYS_DC_debug_status_write_fifo_2_overflow_shift                      (5)
#define  DC_SYS_DC_debug_status_write_fifo_1_overflow_shift                      (4)
#define  DC_SYS_DC_debug_status_write_fifo_0_overflow_shift                      (3)
#define  DC_SYS_DC_debug_status_read_fifo_2_overflow_shift                       (2)
#define  DC_SYS_DC_debug_status_read_fifo_1_overflow_shift                       (1)
#define  DC_SYS_DC_debug_status_read_fifo_0_overflow_shift                       (0)
#define  DC_SYS_DC_debug_status_exsram_fifo_underflow_mask                       (0x02000000)
#define  DC_SYS_DC_debug_status_exsram_fifo_overflow_mask                        (0x01000000)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_2_underflow_mask                  (0x00800000)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_1_underflow_mask                  (0x00400000)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_0_underflow_mask                  (0x00200000)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_2_underflow_mask                   (0x00100000)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_1_underflow_mask                   (0x00080000)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_0_underflow_mask                   (0x00040000)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_2_overflow_mask                   (0x00020000)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_1_overflow_mask                   (0x00010000)
#define  DC_SYS_DC_debug_status_write_cmd_fifo_0_overflow_mask                   (0x00008000)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_2_overflow_mask                    (0x00004000)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_1_overflow_mask                    (0x00002000)
#define  DC_SYS_DC_debug_status_read_cmd_fifo_0_overflow_mask                    (0x00001000)
#define  DC_SYS_DC_debug_status_write_fifo_2_underflow_mask                      (0x00000800)
#define  DC_SYS_DC_debug_status_write_fifo_1_underflow_mask                      (0x00000400)
#define  DC_SYS_DC_debug_status_write_fifo_0_underflow_mask                      (0x00000200)
#define  DC_SYS_DC_debug_status_read_fifo_2_underflow_mask                       (0x00000100)
#define  DC_SYS_DC_debug_status_read_fifo_1_underflow_mask                       (0x00000080)
#define  DC_SYS_DC_debug_status_read_fifo_0_underflow_mask                       (0x00000040)
#define  DC_SYS_DC_debug_status_write_fifo_2_overflow_mask                       (0x00000020)
#define  DC_SYS_DC_debug_status_write_fifo_1_overflow_mask                       (0x00000010)
#define  DC_SYS_DC_debug_status_write_fifo_0_overflow_mask                       (0x00000008)
#define  DC_SYS_DC_debug_status_read_fifo_2_overflow_mask                        (0x00000004)
#define  DC_SYS_DC_debug_status_read_fifo_1_overflow_mask                        (0x00000002)
#define  DC_SYS_DC_debug_status_read_fifo_0_overflow_mask                        (0x00000001)
#define  DC_SYS_DC_debug_status_exsram_fifo_underflow(data)                      (0x02000000&((data)<<25))
#define  DC_SYS_DC_debug_status_exsram_fifo_overflow(data)                       (0x01000000&((data)<<24))
#define  DC_SYS_DC_debug_status_write_cmd_fifo_2_underflow(data)                 (0x00800000&((data)<<23))
#define  DC_SYS_DC_debug_status_write_cmd_fifo_1_underflow(data)                 (0x00400000&((data)<<22))
#define  DC_SYS_DC_debug_status_write_cmd_fifo_0_underflow(data)                 (0x00200000&((data)<<21))
#define  DC_SYS_DC_debug_status_read_cmd_fifo_2_underflow(data)                  (0x00100000&((data)<<20))
#define  DC_SYS_DC_debug_status_read_cmd_fifo_1_underflow(data)                  (0x00080000&((data)<<19))
#define  DC_SYS_DC_debug_status_read_cmd_fifo_0_underflow(data)                  (0x00040000&((data)<<18))
#define  DC_SYS_DC_debug_status_write_cmd_fifo_2_overflow(data)                  (0x00020000&((data)<<17))
#define  DC_SYS_DC_debug_status_write_cmd_fifo_1_overflow(data)                  (0x00010000&((data)<<16))
#define  DC_SYS_DC_debug_status_write_cmd_fifo_0_overflow(data)                  (0x00008000&((data)<<15))
#define  DC_SYS_DC_debug_status_read_cmd_fifo_2_overflow(data)                   (0x00004000&((data)<<14))
#define  DC_SYS_DC_debug_status_read_cmd_fifo_1_overflow(data)                   (0x00002000&((data)<<13))
#define  DC_SYS_DC_debug_status_read_cmd_fifo_0_overflow(data)                   (0x00001000&((data)<<12))
#define  DC_SYS_DC_debug_status_write_fifo_2_underflow(data)                     (0x00000800&((data)<<11))
#define  DC_SYS_DC_debug_status_write_fifo_1_underflow(data)                     (0x00000400&((data)<<10))
#define  DC_SYS_DC_debug_status_write_fifo_0_underflow(data)                     (0x00000200&((data)<<9))
#define  DC_SYS_DC_debug_status_read_fifo_2_underflow(data)                      (0x00000100&((data)<<8))
#define  DC_SYS_DC_debug_status_read_fifo_1_underflow(data)                      (0x00000080&((data)<<7))
#define  DC_SYS_DC_debug_status_read_fifo_0_underflow(data)                      (0x00000040&((data)<<6))
#define  DC_SYS_DC_debug_status_write_fifo_2_overflow(data)                      (0x00000020&((data)<<5))
#define  DC_SYS_DC_debug_status_write_fifo_1_overflow(data)                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_debug_status_write_fifo_0_overflow(data)                      (0x00000008&((data)<<3))
#define  DC_SYS_DC_debug_status_read_fifo_2_overflow(data)                       (0x00000004&((data)<<2))
#define  DC_SYS_DC_debug_status_read_fifo_1_overflow(data)                       (0x00000002&((data)<<1))
#define  DC_SYS_DC_debug_status_read_fifo_0_overflow(data)                       (0x00000001&(data))
#define  DC_SYS_DC_debug_status_get_exsram_fifo_underflow(data)                  ((0x02000000&(data))>>25)
#define  DC_SYS_DC_debug_status_get_exsram_fifo_overflow(data)                   ((0x01000000&(data))>>24)
#define  DC_SYS_DC_debug_status_get_write_cmd_fifo_2_underflow(data)             ((0x00800000&(data))>>23)
#define  DC_SYS_DC_debug_status_get_write_cmd_fifo_1_underflow(data)             ((0x00400000&(data))>>22)
#define  DC_SYS_DC_debug_status_get_write_cmd_fifo_0_underflow(data)             ((0x00200000&(data))>>21)
#define  DC_SYS_DC_debug_status_get_read_cmd_fifo_2_underflow(data)              ((0x00100000&(data))>>20)
#define  DC_SYS_DC_debug_status_get_read_cmd_fifo_1_underflow(data)              ((0x00080000&(data))>>19)
#define  DC_SYS_DC_debug_status_get_read_cmd_fifo_0_underflow(data)              ((0x00040000&(data))>>18)
#define  DC_SYS_DC_debug_status_get_write_cmd_fifo_2_overflow(data)              ((0x00020000&(data))>>17)
#define  DC_SYS_DC_debug_status_get_write_cmd_fifo_1_overflow(data)              ((0x00010000&(data))>>16)
#define  DC_SYS_DC_debug_status_get_write_cmd_fifo_0_overflow(data)              ((0x00008000&(data))>>15)
#define  DC_SYS_DC_debug_status_get_read_cmd_fifo_2_overflow(data)               ((0x00004000&(data))>>14)
#define  DC_SYS_DC_debug_status_get_read_cmd_fifo_1_overflow(data)               ((0x00002000&(data))>>13)
#define  DC_SYS_DC_debug_status_get_read_cmd_fifo_0_overflow(data)               ((0x00001000&(data))>>12)
#define  DC_SYS_DC_debug_status_get_write_fifo_2_underflow(data)                 ((0x00000800&(data))>>11)
#define  DC_SYS_DC_debug_status_get_write_fifo_1_underflow(data)                 ((0x00000400&(data))>>10)
#define  DC_SYS_DC_debug_status_get_write_fifo_0_underflow(data)                 ((0x00000200&(data))>>9)
#define  DC_SYS_DC_debug_status_get_read_fifo_2_underflow(data)                  ((0x00000100&(data))>>8)
#define  DC_SYS_DC_debug_status_get_read_fifo_1_underflow(data)                  ((0x00000080&(data))>>7)
#define  DC_SYS_DC_debug_status_get_read_fifo_0_underflow(data)                  ((0x00000040&(data))>>6)
#define  DC_SYS_DC_debug_status_get_write_fifo_2_overflow(data)                  ((0x00000020&(data))>>5)
#define  DC_SYS_DC_debug_status_get_write_fifo_1_overflow(data)                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_debug_status_get_write_fifo_0_overflow(data)                  ((0x00000008&(data))>>3)
#define  DC_SYS_DC_debug_status_get_read_fifo_2_overflow(data)                   ((0x00000004&(data))>>2)
#define  DC_SYS_DC_debug_status_get_read_fifo_1_overflow(data)                   ((0x00000002&(data))>>1)
#define  DC_SYS_DC_debug_status_get_read_fifo_0_overflow(data)                   (0x00000001&(data))

#define  DC_SYS_DC_PRIORITY_CTRL0                                                0x18007080
#define  DC_SYS_DC_PRIORITY_CTRL0_reg_addr                                       "0xB8007080"
#define  DC_SYS_DC_PRIORITY_CTRL0_reg                                            0xB8007080
#define  DC_SYS_DC_PRIORITY_CTRL0_inst_addr                                      "0x0013"
#define  set_DC_SYS_DC_PRIORITY_CTRL0_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL0_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL0_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL0_reg))
#define  DC_SYS_DC_PRIORITY_CTRL0_c0_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL0_c0_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL0_c0_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL0_c0_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL0_c0_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL0_c0_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL0_get_c0_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL0_get_c0_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL1                                                0x18007084
#define  DC_SYS_DC_PRIORITY_CTRL1_reg_addr                                       "0xB8007084"
#define  DC_SYS_DC_PRIORITY_CTRL1_reg                                            0xB8007084
#define  DC_SYS_DC_PRIORITY_CTRL1_inst_addr                                      "0x0014"
#define  set_DC_SYS_DC_PRIORITY_CTRL1_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL1_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL1_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL1_reg))
#define  DC_SYS_DC_PRIORITY_CTRL1_c1_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL1_c1_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL1_c1_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL1_c1_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL1_c1_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL1_c1_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL1_get_c1_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL1_get_c1_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL2                                                0x18007088
#define  DC_SYS_DC_PRIORITY_CTRL2_reg_addr                                       "0xB8007088"
#define  DC_SYS_DC_PRIORITY_CTRL2_reg                                            0xB8007088
#define  DC_SYS_DC_PRIORITY_CTRL2_inst_addr                                      "0x0015"
#define  set_DC_SYS_DC_PRIORITY_CTRL2_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL2_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL2_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL2_reg))
#define  DC_SYS_DC_PRIORITY_CTRL2_c2_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL2_c2_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL2_c2_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL2_c2_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL2_c2_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL2_c2_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL2_get_c2_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL2_get_c2_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL3                                                0x1800708C
#define  DC_SYS_DC_PRIORITY_CTRL3_reg_addr                                       "0xB800708C"
#define  DC_SYS_DC_PRIORITY_CTRL3_reg                                            0xB800708C
#define  DC_SYS_DC_PRIORITY_CTRL3_inst_addr                                      "0x0016"
#define  set_DC_SYS_DC_PRIORITY_CTRL3_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL3_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL3_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL3_reg))
#define  DC_SYS_DC_PRIORITY_CTRL3_c3_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL3_c3_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL3_c3_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL3_c3_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL3_c3_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL3_c3_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL3_get_c3_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL3_get_c3_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL4                                                0x18007090
#define  DC_SYS_DC_PRIORITY_CTRL4_reg_addr                                       "0xB8007090"
#define  DC_SYS_DC_PRIORITY_CTRL4_reg                                            0xB8007090
#define  DC_SYS_DC_PRIORITY_CTRL4_inst_addr                                      "0x0017"
#define  set_DC_SYS_DC_PRIORITY_CTRL4_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL4_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL4_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL4_reg))
#define  DC_SYS_DC_PRIORITY_CTRL4_c4_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL4_c4_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL4_c4_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL4_c4_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL4_c4_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL4_c4_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL4_get_c4_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL4_get_c4_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL5                                                0x18007094
#define  DC_SYS_DC_PRIORITY_CTRL5_reg_addr                                       "0xB8007094"
#define  DC_SYS_DC_PRIORITY_CTRL5_reg                                            0xB8007094
#define  DC_SYS_DC_PRIORITY_CTRL5_inst_addr                                      "0x0018"
#define  set_DC_SYS_DC_PRIORITY_CTRL5_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL5_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL5_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL5_reg))
#define  DC_SYS_DC_PRIORITY_CTRL5_c5_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL5_c5_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL5_c5_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL5_c5_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL5_c5_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL5_c5_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL5_get_c5_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL5_get_c5_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL6                                                0x18007098
#define  DC_SYS_DC_PRIORITY_CTRL6_reg_addr                                       "0xB8007098"
#define  DC_SYS_DC_PRIORITY_CTRL6_reg                                            0xB8007098
#define  DC_SYS_DC_PRIORITY_CTRL6_inst_addr                                      "0x0019"
#define  set_DC_SYS_DC_PRIORITY_CTRL6_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL6_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL6_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL6_reg))
#define  DC_SYS_DC_PRIORITY_CTRL6_c6_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL6_c6_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL6_c6_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL6_c6_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL6_c6_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL6_c6_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL6_get_c6_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL6_get_c6_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL7                                                0x1800709C
#define  DC_SYS_DC_PRIORITY_CTRL7_reg_addr                                       "0xB800709C"
#define  DC_SYS_DC_PRIORITY_CTRL7_reg                                            0xB800709C
#define  DC_SYS_DC_PRIORITY_CTRL7_inst_addr                                      "0x001A"
#define  set_DC_SYS_DC_PRIORITY_CTRL7_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL7_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL7_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL7_reg))
#define  DC_SYS_DC_PRIORITY_CTRL7_c7_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL7_c7_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL7_c7_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL7_c7_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL7_c7_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL7_c7_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL7_get_c7_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL7_get_c7_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL8                                                0x180070A0
#define  DC_SYS_DC_PRIORITY_CTRL8_reg_addr                                       "0xB80070A0"
#define  DC_SYS_DC_PRIORITY_CTRL8_reg                                            0xB80070A0
#define  DC_SYS_DC_PRIORITY_CTRL8_inst_addr                                      "0x001B"
#define  set_DC_SYS_DC_PRIORITY_CTRL8_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL8_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL8_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL8_reg))
#define  DC_SYS_DC_PRIORITY_CTRL8_c8_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL8_c8_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL8_c8_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL8_c8_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL8_c8_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL8_c8_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL8_get_c8_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL8_get_c8_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL9                                                0x180070A4
#define  DC_SYS_DC_PRIORITY_CTRL9_reg_addr                                       "0xB80070A4"
#define  DC_SYS_DC_PRIORITY_CTRL9_reg                                            0xB80070A4
#define  DC_SYS_DC_PRIORITY_CTRL9_inst_addr                                      "0x001C"
#define  set_DC_SYS_DC_PRIORITY_CTRL9_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL9_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL9_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL9_reg))
#define  DC_SYS_DC_PRIORITY_CTRL9_c9_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRL9_c9_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRL9_c9_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRL9_c9_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL9_c9_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL9_c9_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL9_get_c9_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL9_get_c9_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRLA                                                0x180070A8
#define  DC_SYS_DC_PRIORITY_CTRLA_reg_addr                                       "0xB80070A8"
#define  DC_SYS_DC_PRIORITY_CTRLA_reg                                            0xB80070A8
#define  DC_SYS_DC_PRIORITY_CTRLA_inst_addr                                      "0x001D"
#define  set_DC_SYS_DC_PRIORITY_CTRLA_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRLA_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRLA_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRLA_reg))
#define  DC_SYS_DC_PRIORITY_CTRLA_ca_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRLA_ca_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRLA_ca_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRLA_ca_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRLA_ca_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRLA_ca_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRLA_get_ca_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRLA_get_ca_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRLB                                                0x180070AC
#define  DC_SYS_DC_PRIORITY_CTRLB_reg_addr                                       "0xB80070AC"
#define  DC_SYS_DC_PRIORITY_CTRLB_reg                                            0xB80070AC
#define  DC_SYS_DC_PRIORITY_CTRLB_inst_addr                                      "0x001E"
#define  set_DC_SYS_DC_PRIORITY_CTRLB_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRLB_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRLB_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRLB_reg))
#define  DC_SYS_DC_PRIORITY_CTRLB_cb_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRLB_cb_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRLB_cb_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRLB_cb_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRLB_cb_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRLB_cb_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRLB_get_cb_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRLB_get_cb_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRLC                                                0x180070B0
#define  DC_SYS_DC_PRIORITY_CTRLC_reg_addr                                       "0xB80070B0"
#define  DC_SYS_DC_PRIORITY_CTRLC_reg                                            0xB80070B0
#define  DC_SYS_DC_PRIORITY_CTRLC_inst_addr                                      "0x001F"
#define  set_DC_SYS_DC_PRIORITY_CTRLC_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRLC_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRLC_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRLC_reg))
#define  DC_SYS_DC_PRIORITY_CTRLC_cc_latcnt_end_shift                            (16)
#define  DC_SYS_DC_PRIORITY_CTRLC_cc_latcnt_beg_shift                            (0)
#define  DC_SYS_DC_PRIORITY_CTRLC_cc_latcnt_end_mask                             (0x00FF0000)
#define  DC_SYS_DC_PRIORITY_CTRLC_cc_latcnt_beg_mask                             (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRLC_cc_latcnt_end(data)                            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRLC_cc_latcnt_beg(data)                            (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRLC_get_cc_latcnt_end(data)                        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRLC_get_cc_latcnt_beg(data)                        (0x000000FF&(data))

#define  DC_SYS_DC_PRIORITY_CTRL_HIE                                             0x180070B4
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_reg_addr                                    "0xB80070B4"
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_reg                                         0xB80070B4
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_inst_addr                                   "0x0020"
#define  set_DC_SYS_DC_PRIORITY_CTRL_HIE_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL_HIE_reg)=data)
#define  get_DC_SYS_DC_PRIORITY_CTRL_HIE_reg                                     (*((volatile unsigned int*)DC_SYS_DC_PRIORITY_CTRL_HIE_reg))
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_gpu_lat_new_shift                           (31)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_hie_cmp_dis_shift                           (16)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_latcnt_period_shift                         (0)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_gpu_lat_new_mask                            (0x80000000)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_hie_cmp_dis_mask                            (0x1FFF0000)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_latcnt_period_mask                          (0x000000FF)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_gpu_lat_new(data)                           (0x80000000&((data)<<31))
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_hie_cmp_dis(data)                           (0x1FFF0000&((data)<<16))
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_latcnt_period(data)                         (0x000000FF&(data))
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_get_gpu_lat_new(data)                       ((0x80000000&(data))>>31)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_get_hie_cmp_dis(data)                       ((0x1FFF0000&(data))>>16)
#define  DC_SYS_DC_PRIORITY_CTRL_HIE_get_latcnt_period(data)                     (0x000000FF&(data))

#define  DC_SYS_DC_client_mask                                                   0x180070D0
#define  DC_SYS_DC_client_mask_reg_addr                                          "0xB80070D0"
#define  DC_SYS_DC_client_mask_reg                                               0xB80070D0
#define  DC_SYS_DC_client_mask_inst_addr                                         "0x0021"
#define  set_DC_SYS_DC_client_mask_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_client_mask_reg)=data)
#define  get_DC_SYS_DC_client_mask_reg                                           (*((volatile unsigned int*)DC_SYS_DC_client_mask_reg))
#define  DC_SYS_DC_client_mask_req_mask_index_shift                              (0)
#define  DC_SYS_DC_client_mask_req_mask_index_mask                               (0x00001FFF)
#define  DC_SYS_DC_client_mask_req_mask_index(data)                              (0x00001FFF&(data))
#define  DC_SYS_DC_client_mask_get_req_mask_index(data)                          (0x00001FFF&(data))

#define  DC_SYS_DC_PC_CTRL                                                       0x18007100
#define  DC_SYS_DC_PC_CTRL_reg_addr                                              "0xB8007100"
#define  DC_SYS_DC_PC_CTRL_reg                                                   0xB8007100
#define  DC_SYS_DC_PC_CTRL_inst_addr                                             "0x0022"
#define  set_DC_SYS_DC_PC_CTRL_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_PC_CTRL_reg)=data)
#define  get_DC_SYS_DC_PC_CTRL_reg                                               (*((volatile unsigned int*)DC_SYS_DC_PC_CTRL_reg))
#define  DC_SYS_DC_PC_CTRL_pc_rcmd_only_shift                                    (31)
#define  DC_SYS_DC_PC_CTRL_pc_go_shift                                           (0)
#define  DC_SYS_DC_PC_CTRL_pc_rcmd_only_mask                                     (0x80000000)
#define  DC_SYS_DC_PC_CTRL_pc_go_mask                                            (0x00000001)
#define  DC_SYS_DC_PC_CTRL_pc_rcmd_only(data)                                    (0x80000000&((data)<<31))
#define  DC_SYS_DC_PC_CTRL_pc_go(data)                                           (0x00000001&(data))
#define  DC_SYS_DC_PC_CTRL_get_pc_rcmd_only(data)                                ((0x80000000&(data))>>31)
#define  DC_SYS_DC_PC_CTRL_get_pc_go(data)                                       (0x00000001&(data))

#define  DC_SYS_DC_PC_TOTA_MON_NUM                                               0x18007104
#define  DC_SYS_DC_PC_TOTA_MON_NUM_reg_addr                                      "0xB8007104"
#define  DC_SYS_DC_PC_TOTA_MON_NUM_reg                                           0xB8007104
#define  DC_SYS_DC_PC_TOTA_MON_NUM_inst_addr                                     "0x0023"
#define  set_DC_SYS_DC_PC_TOTA_MON_NUM_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_PC_TOTA_MON_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_TOTA_MON_NUM_reg                                       (*((volatile unsigned int*)DC_SYS_DC_PC_TOTA_MON_NUM_reg))
#define  DC_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num_shift                         (0)
#define  DC_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_PC_TOTA_MON_NUM_pc_tota_mon_num(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_TOTA_MON_NUM_get_pc_tota_mon_num(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_TOTA_ACK_NUM                                               0x18007108
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_reg_addr                                      "0xB8007108"
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_reg                                           0xB8007108
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_inst_addr                                     "0x0024"
#define  set_DC_SYS_DC_PC_TOTA_ACK_NUM_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_PC_TOTA_ACK_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_TOTA_ACK_NUM_reg                                       (*((volatile unsigned int*)DC_SYS_DC_PC_TOTA_ACK_NUM_reg))
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_shift                         (0)
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_pc_tota_ack_num(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_TOTA_ACK_NUM_get_pc_tota_ack_num(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_TOTA_IDL_NUM                                               0x1800710C
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_reg_addr                                      "0xB800710C"
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_reg                                           0xB800710C
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_inst_addr                                     "0x0025"
#define  set_DC_SYS_DC_PC_TOTA_IDL_NUM_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_PC_TOTA_IDL_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_TOTA_IDL_NUM_reg                                       (*((volatile unsigned int*)DC_SYS_DC_PC_TOTA_IDL_NUM_reg))
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_shift                         (0)
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_pc_tota_idl_num(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_TOTA_IDL_NUM_get_pc_tota_idl_num(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_ctrl                                             0x18007110
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_reg_addr                                    "0xB8007110"
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_reg                                         0xB8007110
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_inst_addr                                   "0x0026"
#define  set_DC_SYS_DC_PC_SYSH_prog_ctrl_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_ctrl_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_ctrl_reg                                     (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_ctrl_reg))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_3_shift                            (23)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog2_sel_shift                     (19)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_2_shift                            (15)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog1_sel_shift                     (11)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_1_shift                            (7)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog0_sel_shift                     (3)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_3_mask                             (0x00800000)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog2_sel_mask                      (0x00780000)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_2_mask                             (0x00008000)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog1_sel_mask                      (0x00007800)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_1_mask                             (0x00000080)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog0_sel_mask                      (0x00000078)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_3(data)                            (0x00800000&((data)<<23))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog2_sel(data)                     (0x00780000&((data)<<19))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_2(data)                            (0x00008000&((data)<<15))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog1_sel(data)                     (0x00007800&((data)<<11))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_write_en_1(data)                            (0x00000080&((data)<<7))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_pc_sysh_prog0_sel(data)                     (0x00000078&((data)<<3))
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_get_write_en_3(data)                        ((0x00800000&(data))>>23)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_get_pc_sysh_prog2_sel(data)                 ((0x00780000&(data))>>19)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_get_write_en_2(data)                        ((0x00008000&(data))>>15)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_get_pc_sysh_prog1_sel(data)                 ((0x00007800&(data))>>11)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_get_write_en_1(data)                        ((0x00000080&(data))>>7)
#define  DC_SYS_DC_PC_SYSH_prog_ctrl_get_pc_sysh_prog0_sel(data)                 ((0x00000078&(data))>>3)

#define  DC_SYS_DC_PC_SYS_prog_ctrl1                                             0x18007120
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_reg_addr                                    "0xB8007120"
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_reg                                         0xB8007120
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_inst_addr                                   "0x0027"
#define  set_DC_SYS_DC_PC_SYS_prog_ctrl1_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_PC_SYS_prog_ctrl1_reg)=data)
#define  get_DC_SYS_DC_PC_SYS_prog_ctrl1_reg                                     (*((volatile unsigned int*)DC_SYS_DC_PC_SYS_prog_ctrl1_reg))
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog2_req_occur_shift               (6)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog1_req_occur_shift               (5)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog0_req_occur_shift               (4)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog2_req_occur_mask                (0x00000040)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog1_req_occur_mask                (0x00000020)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog0_req_occur_mask                (0x00000010)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog2_req_occur(data)               (0x00000040&((data)<<6))
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog1_req_occur(data)               (0x00000020&((data)<<5))
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_pc_sysh_prog0_req_occur(data)               (0x00000010&((data)<<4))
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_get_pc_sysh_prog2_req_occur(data)           ((0x00000040&(data))>>6)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_get_pc_sysh_prog1_req_occur(data)           ((0x00000020&(data))>>5)
#define  DC_SYS_DC_PC_SYS_prog_ctrl1_get_pc_sysh_prog0_req_occur(data)           ((0x00000010&(data))>>4)

#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT                                        0x18007130
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_reg_addr                               "0xB8007130"
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_reg                                    0xB8007130
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_inst_addr                              "0x0028"
#define  set_DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_reg))
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_sysh_prog0_acc_lat_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_sysh_prog0_acc_lat_mask                (0xFFFFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_sysh_prog0_acc_lat(data)               (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_0_ACC_LAT_get_sysh_prog0_acc_lat(data)           (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT                                        0x18007134
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg_addr                               "0xB8007134"
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg                                    0xB8007134
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_inst_addr                              "0x0029"
#define  set_DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_reg))
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_sysh_prog0_max_lat_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_sysh_prog0_max_lat_mask                (0x0000FFFF)
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_sysh_prog0_max_lat(data)               (0x0000FFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_0_MAX_LAT_get_sysh_prog0_max_lat(data)           (0x0000FFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM                                        0x18007138
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_reg_addr                               "0xB8007138"
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_reg                                    0xB8007138
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_inst_addr                              "0x002A"
#define  set_DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_reg))
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_sysh_prog0_req_num_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_sysh_prog0_req_num_mask                (0x00FFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_sysh_prog0_req_num(data)               (0x00FFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_0_REQ_NUM_get_sysh_prog0_req_num(data)           (0x00FFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM                                        0x1800713C
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg_addr                               "0xB800713C"
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg                                    0xB800713C
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_inst_addr                              "0x002B"
#define  set_DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_reg))
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_sysh_prog0_ack_num_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_sysh_prog0_ack_num_mask                (0xFFFFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_sysh_prog0_ack_num(data)               (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_0_ACK_NUM_get_sysh_prog0_ack_num(data)           (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT                                        0x18007140
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_reg_addr                               "0xB8007140"
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_reg                                    0xB8007140
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_inst_addr                              "0x002C"
#define  set_DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_reg))
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_sysh_prog1_acc_lat_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_sysh_prog1_acc_lat_mask                (0xFFFFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_sysh_prog1_acc_lat(data)               (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_1_ACC_LAT_get_sysh_prog1_acc_lat(data)           (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT                                        0x18007144
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg_addr                               "0xB8007144"
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg                                    0xB8007144
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_inst_addr                              "0x002D"
#define  set_DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_reg))
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_sysh_prog1_max_lat_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_sysh_prog1_max_lat_mask                (0x0000FFFF)
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_sysh_prog1_max_lat(data)               (0x0000FFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_1_MAX_LAT_get_sysh_prog1_max_lat(data)           (0x0000FFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM                                        0x18007148
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_reg_addr                               "0xB8007148"
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_reg                                    0xB8007148
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_inst_addr                              "0x002E"
#define  set_DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_reg))
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_sysh_prog1_req_num_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_sysh_prog1_req_num_mask                (0x00FFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_sysh_prog1_req_num(data)               (0x00FFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_1_REQ_NUM_get_sysh_prog1_req_num(data)           (0x00FFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM                                        0x1800714C
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg_addr                               "0xB800714C"
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg                                    0xB800714C
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_inst_addr                              "0x002F"
#define  set_DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_reg))
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_sysh_prog1_ack_num_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_sysh_prog1_ack_num_mask                (0xFFFFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_sysh_prog1_ack_num(data)               (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_1_ACK_NUM_get_sysh_prog1_ack_num(data)           (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT                                        0x18007150
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_reg_addr                               "0xB8007150"
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_reg                                    0xB8007150
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_inst_addr                              "0x0030"
#define  set_DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_reg))
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_sysh_prog2_acc_lat_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_sysh_prog2_acc_lat_mask                (0xFFFFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_sysh_prog2_acc_lat(data)               (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_2_ACC_LAT_get_sysh_prog2_acc_lat(data)           (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT                                        0x18007154
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg_addr                               "0xB8007154"
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg                                    0xB8007154
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_inst_addr                              "0x0031"
#define  set_DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_reg))
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_sysh_prog2_max_lat_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_sysh_prog2_max_lat_mask                (0x0000FFFF)
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_sysh_prog2_max_lat(data)               (0x0000FFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_2_MAX_LAT_get_sysh_prog2_max_lat(data)           (0x0000FFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM                                        0x18007158
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_reg_addr                               "0xB8007158"
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_reg                                    0xB8007158
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_inst_addr                              "0x0032"
#define  set_DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_reg))
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_sysh_prog2_req_num_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_sysh_prog2_req_num_mask                (0x00FFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_sysh_prog2_req_num(data)               (0x00FFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_2_REQ_NUM_get_sysh_prog2_req_num(data)           (0x00FFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM                                        0x1800715C
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg_addr                               "0xB800715C"
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg                                    0xB800715C
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_inst_addr                              "0x0033"
#define  set_DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_reg))
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_sysh_prog2_ack_num_shift               (0)
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_sysh_prog2_ack_num_mask                (0xFFFFFFFF)
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_sysh_prog2_ack_num(data)               (0xFFFFFFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_2_ACK_NUM_get_sysh_prog2_ack_num(data)           (0xFFFFFFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_cti                                              0x18007170
#define  DC_SYS_DC_PC_SYSH_prog_cti_reg_addr                                     "0xB8007170"
#define  DC_SYS_DC_PC_SYSH_prog_cti_reg                                          0xB8007170
#define  DC_SYS_DC_PC_SYSH_prog_cti_inst_addr                                    "0x0034"
#define  set_DC_SYS_DC_PC_SYSH_prog_cti_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_cti_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_cti_reg                                      (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_cti_reg))
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog2_shift                 (16)
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog1_shift                 (8)
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog0_shift                 (0)
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog2_mask                  (0x001F0000)
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog1_mask                  (0x00001F00)
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog0_mask                  (0x0000001F)
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog2(data)                 (0x001F0000&((data)<<16))
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog1(data)                 (0x00001F00&((data)<<8))
#define  DC_SYS_DC_PC_SYSH_prog_cti_cmd_num_in_cti_q_prog0(data)                 (0x0000001F&(data))
#define  DC_SYS_DC_PC_SYSH_prog_cti_get_cmd_num_in_cti_q_prog2(data)             ((0x001F0000&(data))>>16)
#define  DC_SYS_DC_PC_SYSH_prog_cti_get_cmd_num_in_cti_q_prog1(data)             ((0x00001F00&(data))>>8)
#define  DC_SYS_DC_PC_SYSH_prog_cti_get_cmd_num_in_cti_q_prog0(data)             (0x0000001F&(data))

#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0                                        0x18007174
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_reg_addr                               "0xB8007174"
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_reg                                    0xB8007174
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_inst_addr                              "0x0035"
#define  set_DC_SYS_DC_PC_SYSH_prog_cmd_num_0_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_cmd_num_0_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_cmd_num_0_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_cmd_num_0_reg))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog2_shift            (16)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog1_shift            (8)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog0_shift            (0)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog2_mask             (0x00FF0000)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog1_mask             (0x0000FF00)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog0_mask             (0x000000FF)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog2(data)            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog1(data)            (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_remain_cmd_num0_prog0(data)            (0x000000FF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_get_remain_cmd_num0_prog2(data)        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_get_remain_cmd_num0_prog1(data)        ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_0_get_remain_cmd_num0_prog0(data)        (0x000000FF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1                                        0x18007178
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_reg_addr                               "0xB8007178"
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_reg                                    0xB8007178
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_inst_addr                              "0x0036"
#define  set_DC_SYS_DC_PC_SYSH_prog_cmd_num_1_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_cmd_num_1_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_cmd_num_1_reg                                (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_cmd_num_1_reg))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog2_shift            (16)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog1_shift            (8)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog0_shift            (0)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog2_mask             (0x00FF0000)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog1_mask             (0x0000FF00)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog0_mask             (0x000000FF)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog2(data)            (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog1(data)            (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_remain_cmd_num1_prog0(data)            (0x000000FF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_get_remain_cmd_num1_prog2(data)        ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_get_remain_cmd_num1_prog1(data)        ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_PC_SYSH_prog_cmd_num_1_get_remain_cmd_num1_prog0(data)        (0x000000FF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_0                                                0x18007190
#define  DC_SYS_DC_PC_SYSH_prog_0_reg_addr                                       "0xB8007190"
#define  DC_SYS_DC_PC_SYSH_prog_0_reg                                            0xB8007190
#define  DC_SYS_DC_PC_SYSH_prog_0_inst_addr                                      "0x0037"
#define  set_DC_SYS_DC_PC_SYSH_prog_0_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_0_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_0_reg))
#define  DC_SYS_DC_PC_SYSH_prog_0_sysh0_hitend_cnt_shift                         (0)
#define  DC_SYS_DC_PC_SYSH_prog_0_sysh0_hitend_cnt_mask                          (0x0000FFFF)
#define  DC_SYS_DC_PC_SYSH_prog_0_sysh0_hitend_cnt(data)                         (0x0000FFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_0_get_sysh0_hitend_cnt(data)                     (0x0000FFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_1                                                0x18007194
#define  DC_SYS_DC_PC_SYSH_prog_1_reg_addr                                       "0xB8007194"
#define  DC_SYS_DC_PC_SYSH_prog_1_reg                                            0xB8007194
#define  DC_SYS_DC_PC_SYSH_prog_1_inst_addr                                      "0x0038"
#define  set_DC_SYS_DC_PC_SYSH_prog_1_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_1_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_1_reg))
#define  DC_SYS_DC_PC_SYSH_prog_1_sysh1_hitend_cnt_shift                         (0)
#define  DC_SYS_DC_PC_SYSH_prog_1_sysh1_hitend_cnt_mask                          (0x0000FFFF)
#define  DC_SYS_DC_PC_SYSH_prog_1_sysh1_hitend_cnt(data)                         (0x0000FFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_1_get_sysh1_hitend_cnt(data)                     (0x0000FFFF&(data))

#define  DC_SYS_DC_PC_SYSH_prog_2                                                0x18007198
#define  DC_SYS_DC_PC_SYSH_prog_2_reg_addr                                       "0xB8007198"
#define  DC_SYS_DC_PC_SYSH_prog_2_reg                                            0xB8007198
#define  DC_SYS_DC_PC_SYSH_prog_2_inst_addr                                      "0x0039"
#define  set_DC_SYS_DC_PC_SYSH_prog_2_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_reg)=data)
#define  get_DC_SYS_DC_PC_SYSH_prog_2_reg                                        (*((volatile unsigned int*)DC_SYS_DC_PC_SYSH_prog_2_reg))
#define  DC_SYS_DC_PC_SYSH_prog_2_sysh2_hitend_cnt_shift                         (0)
#define  DC_SYS_DC_PC_SYSH_prog_2_sysh2_hitend_cnt_mask                          (0x0000FFFF)
#define  DC_SYS_DC_PC_SYSH_prog_2_sysh2_hitend_cnt(data)                         (0x0000FFFF&(data))
#define  DC_SYS_DC_PC_SYSH_prog_2_get_sysh2_hitend_cnt(data)                     (0x0000FFFF&(data))

#define  DC_SYS_DC_bist_mode                                                     0x180071C0
#define  DC_SYS_DC_bist_mode_reg_addr                                            "0xB80071C0"
#define  DC_SYS_DC_bist_mode_reg                                                 0xB80071C0
#define  DC_SYS_DC_bist_mode_inst_addr                                           "0x003A"
#define  set_DC_SYS_DC_bist_mode_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_bist_mode_reg)=data)
#define  get_DC_SYS_DC_bist_mode_reg                                             (*((volatile unsigned int*)DC_SYS_DC_bist_mode_reg))
#define  DC_SYS_DC_bist_mode_dc_bist_mode_pict0_shift                            (1)
#define  DC_SYS_DC_bist_mode_dc_bist_mode_pict0_mask                             (0x00000002)
#define  DC_SYS_DC_bist_mode_dc_bist_mode_pict0(data)                            (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_mode_get_dc_bist_mode_pict0(data)                        ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_done                                                     0x180071C4
#define  DC_SYS_DC_bist_done_reg_addr                                            "0xB80071C4"
#define  DC_SYS_DC_bist_done_reg                                                 0xB80071C4
#define  DC_SYS_DC_bist_done_inst_addr                                           "0x003B"
#define  set_DC_SYS_DC_bist_done_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_bist_done_reg)=data)
#define  get_DC_SYS_DC_bist_done_reg                                             (*((volatile unsigned int*)DC_SYS_DC_bist_done_reg))
#define  DC_SYS_DC_bist_done_dc_bist_done_pict0_shift                            (1)
#define  DC_SYS_DC_bist_done_dc_bist_done_pict0_mask                             (0x00000002)
#define  DC_SYS_DC_bist_done_dc_bist_done_pict0(data)                            (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_done_get_dc_bist_done_pict0(data)                        ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_fail                                                     0x180071C8
#define  DC_SYS_DC_bist_fail_reg_addr                                            "0xB80071C8"
#define  DC_SYS_DC_bist_fail_reg                                                 0xB80071C8
#define  DC_SYS_DC_bist_fail_inst_addr                                           "0x003C"
#define  set_DC_SYS_DC_bist_fail_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_bist_fail_reg)=data)
#define  get_DC_SYS_DC_bist_fail_reg                                             (*((volatile unsigned int*)DC_SYS_DC_bist_fail_reg))
#define  DC_SYS_DC_bist_fail_dc_bist_fail_group_pict0_shift                      (1)
#define  DC_SYS_DC_bist_fail_dc_bist_fail_group_pict0_mask                       (0x00000002)
#define  DC_SYS_DC_bist_fail_dc_bist_fail_group_pict0(data)                      (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_fail_get_dc_bist_fail_group_pict0(data)                  ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_drf                                                      0x180071CC
#define  DC_SYS_DC_bist_drf_reg_addr                                             "0xB80071CC"
#define  DC_SYS_DC_bist_drf_reg                                                  0xB80071CC
#define  DC_SYS_DC_bist_drf_inst_addr                                            "0x003D"
#define  set_DC_SYS_DC_bist_drf_reg(data)                                        (*((volatile unsigned int*)DC_SYS_DC_bist_drf_reg)=data)
#define  get_DC_SYS_DC_bist_drf_reg                                              (*((volatile unsigned int*)DC_SYS_DC_bist_drf_reg))
#define  DC_SYS_DC_bist_drf_dc_drf_mode_pict0_shift                              (1)
#define  DC_SYS_DC_bist_drf_dc_drf_mode_pict0_mask                               (0x00000002)
#define  DC_SYS_DC_bist_drf_dc_drf_mode_pict0(data)                              (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_drf_get_dc_drf_mode_pict0(data)                          ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_resume                                                   0x180071D0
#define  DC_SYS_DC_bist_resume_reg_addr                                          "0xB80071D0"
#define  DC_SYS_DC_bist_resume_reg                                               0xB80071D0
#define  DC_SYS_DC_bist_resume_inst_addr                                         "0x003E"
#define  set_DC_SYS_DC_bist_resume_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_bist_resume_reg)=data)
#define  get_DC_SYS_DC_bist_resume_reg                                           (*((volatile unsigned int*)DC_SYS_DC_bist_resume_reg))
#define  DC_SYS_DC_bist_resume_dc_drf_resume_pict0_shift                         (1)
#define  DC_SYS_DC_bist_resume_dc_drf_resume_pict0_mask                          (0x00000002)
#define  DC_SYS_DC_bist_resume_dc_drf_resume_pict0(data)                         (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_resume_get_dc_drf_resume_pict0(data)                     ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist0_drf_done                                                0x180071D4
#define  DC_SYS_DC_bist0_drf_done_reg_addr                                       "0xB80071D4"
#define  DC_SYS_DC_bist0_drf_done_reg                                            0xB80071D4
#define  DC_SYS_DC_bist0_drf_done_inst_addr                                      "0x003F"
#define  set_DC_SYS_DC_bist0_drf_done_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_bist0_drf_done_reg)=data)
#define  get_DC_SYS_DC_bist0_drf_done_reg                                        (*((volatile unsigned int*)DC_SYS_DC_bist0_drf_done_reg))
#define  DC_SYS_DC_bist0_drf_done_dc_drf_done_pict0_shift                        (1)
#define  DC_SYS_DC_bist0_drf_done_dc_drf_done_pict0_mask                         (0x00000002)
#define  DC_SYS_DC_bist0_drf_done_dc_drf_done_pict0(data)                        (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist0_drf_done_get_dc_drf_done_pict0(data)                    ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_drf_pause                                                0x180071D8
#define  DC_SYS_DC_bist_drf_pause_reg_addr                                       "0xB80071D8"
#define  DC_SYS_DC_bist_drf_pause_reg                                            0xB80071D8
#define  DC_SYS_DC_bist_drf_pause_inst_addr                                      "0x0040"
#define  set_DC_SYS_DC_bist_drf_pause_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_bist_drf_pause_reg)=data)
#define  get_DC_SYS_DC_bist_drf_pause_reg                                        (*((volatile unsigned int*)DC_SYS_DC_bist_drf_pause_reg))
#define  DC_SYS_DC_bist_drf_pause_dc_drf_pause_pict0_shift                       (1)
#define  DC_SYS_DC_bist_drf_pause_dc_drf_pause_pict0_mask                        (0x00000002)
#define  DC_SYS_DC_bist_drf_pause_dc_drf_pause_pict0(data)                       (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_drf_pause_get_dc_drf_pause_pict0(data)                   ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_drf_fail                                                 0x180071DC
#define  DC_SYS_DC_bist_drf_fail_reg_addr                                        "0xB80071DC"
#define  DC_SYS_DC_bist_drf_fail_reg                                             0xB80071DC
#define  DC_SYS_DC_bist_drf_fail_inst_addr                                       "0x0041"
#define  set_DC_SYS_DC_bist_drf_fail_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_bist_drf_fail_reg)=data)
#define  get_DC_SYS_DC_bist_drf_fail_reg                                         (*((volatile unsigned int*)DC_SYS_DC_bist_drf_fail_reg))
#define  DC_SYS_DC_bist_drf_fail_dc_drf_fail_group_pict0_shift                   (1)
#define  DC_SYS_DC_bist_drf_fail_dc_drf_fail_group_pict0_mask                    (0x00000002)
#define  DC_SYS_DC_bist_drf_fail_dc_drf_fail_group_pict0(data)                   (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_drf_fail_get_dc_drf_fail_group_pict0(data)               ((0x00000002&(data))>>1)

#define  DC_SYS_DC_bist_detail                                                   0x180071E0
#define  DC_SYS_DC_bist_detail_reg_addr                                          "0xB80071E0"
#define  DC_SYS_DC_bist_detail_reg                                               0xB80071E0
#define  DC_SYS_DC_bist_detail_inst_addr                                         "0x0042"
#define  set_DC_SYS_DC_bist_detail_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_bist_detail_reg)=data)
#define  get_DC_SYS_DC_bist_detail_reg                                           (*((volatile unsigned int*)DC_SYS_DC_bist_detail_reg))
#define  DC_SYS_DC_bist_detail_dc_drf_pict_fail0_shift                           (5)
#define  DC_SYS_DC_bist_detail_dc_bist_pict_fail0_shift                          (4)
#define  DC_SYS_DC_bist_detail_dc_drf_pict_fail0_mask                            (0x00000020)
#define  DC_SYS_DC_bist_detail_dc_bist_pict_fail0_mask                           (0x00000010)
#define  DC_SYS_DC_bist_detail_dc_drf_pict_fail0(data)                           (0x00000020&((data)<<5))
#define  DC_SYS_DC_bist_detail_dc_bist_pict_fail0(data)                          (0x00000010&((data)<<4))
#define  DC_SYS_DC_bist_detail_get_dc_drf_pict_fail0(data)                       ((0x00000020&(data))>>5)
#define  DC_SYS_DC_bist_detail_get_dc_bist_pict_fail0(data)                      ((0x00000010&(data))>>4)

#define  DC_SYS_DC_bist_rm                                                       0x180071E4
#define  DC_SYS_DC_bist_rm_reg_addr                                              "0xB80071E4"
#define  DC_SYS_DC_bist_rm_reg                                                   0xB80071E4
#define  DC_SYS_DC_bist_rm_inst_addr                                             "0x0043"
#define  set_DC_SYS_DC_bist_rm_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_bist_rm_reg)=data)
#define  get_DC_SYS_DC_bist_rm_reg                                               (*((volatile unsigned int*)DC_SYS_DC_bist_rm_reg))
#define  DC_SYS_DC_bist_rm_rme_shift                                             (4)
#define  DC_SYS_DC_bist_rm_rm_3_shift                                            (3)
#define  DC_SYS_DC_bist_rm_rm_2_shift                                            (2)
#define  DC_SYS_DC_bist_rm_rm_1_shift                                            (1)
#define  DC_SYS_DC_bist_rm_rm_0_shift                                            (0)
#define  DC_SYS_DC_bist_rm_rme_mask                                              (0x00000010)
#define  DC_SYS_DC_bist_rm_rm_3_mask                                             (0x00000008)
#define  DC_SYS_DC_bist_rm_rm_2_mask                                             (0x00000004)
#define  DC_SYS_DC_bist_rm_rm_1_mask                                             (0x00000002)
#define  DC_SYS_DC_bist_rm_rm_0_mask                                             (0x00000001)
#define  DC_SYS_DC_bist_rm_rme(data)                                             (0x00000010&((data)<<4))
#define  DC_SYS_DC_bist_rm_rm_3(data)                                            (0x00000008&((data)<<3))
#define  DC_SYS_DC_bist_rm_rm_2(data)                                            (0x00000004&((data)<<2))
#define  DC_SYS_DC_bist_rm_rm_1(data)                                            (0x00000002&((data)<<1))
#define  DC_SYS_DC_bist_rm_rm_0(data)                                            (0x00000001&(data))
#define  DC_SYS_DC_bist_rm_get_rme(data)                                         ((0x00000010&(data))>>4)
#define  DC_SYS_DC_bist_rm_get_rm_3(data)                                        ((0x00000008&(data))>>3)
#define  DC_SYS_DC_bist_rm_get_rm_2(data)                                        ((0x00000004&(data))>>2)
#define  DC_SYS_DC_bist_rm_get_rm_1(data)                                        ((0x00000002&(data))>>1)
#define  DC_SYS_DC_bist_rm_get_rm_0(data)                                        (0x00000001&(data))

#define  DC_SYS_DC_dummy_reg0                                                    0x180071F0
#define  DC_SYS_DC_dummy_reg0_reg_addr                                           "0xB80071F0"
#define  DC_SYS_DC_dummy_reg0_reg                                                0xB80071F0
#define  DC_SYS_DC_dummy_reg0_inst_addr                                          "0x0044"
#define  set_DC_SYS_DC_dummy_reg0_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_dummy_reg0_reg)=data)
#define  get_DC_SYS_DC_dummy_reg0_reg                                            (*((volatile unsigned int*)DC_SYS_DC_dummy_reg0_reg))
#define  DC_SYS_DC_dummy_reg0_dummy_reg0_shift                                   (0)
#define  DC_SYS_DC_dummy_reg0_dummy_reg0_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_dummy_reg0_dummy_reg0(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_dummy_reg0_get_dummy_reg0(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_dummy_reg1                                                    0x180071F4
#define  DC_SYS_DC_dummy_reg1_reg_addr                                           "0xB80071F4"
#define  DC_SYS_DC_dummy_reg1_reg                                                0xB80071F4
#define  DC_SYS_DC_dummy_reg1_inst_addr                                          "0x0045"
#define  set_DC_SYS_DC_dummy_reg1_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_dummy_reg1_reg)=data)
#define  get_DC_SYS_DC_dummy_reg1_reg                                            (*((volatile unsigned int*)DC_SYS_DC_dummy_reg1_reg))
#define  DC_SYS_DC_dummy_reg1_dummy_reg1_shift                                   (0)
#define  DC_SYS_DC_dummy_reg1_dummy_reg1_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_dummy_reg1_dummy_reg1(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_dummy_reg1_get_dummy_reg1(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_dummy_reg2                                                    0x180071F8
#define  DC_SYS_DC_dummy_reg2_reg_addr                                           "0xB80071F8"
#define  DC_SYS_DC_dummy_reg2_reg                                                0xB80071F8
#define  DC_SYS_DC_dummy_reg2_inst_addr                                          "0x0046"
#define  set_DC_SYS_DC_dummy_reg2_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_dummy_reg2_reg)=data)
#define  get_DC_SYS_DC_dummy_reg2_reg                                            (*((volatile unsigned int*)DC_SYS_DC_dummy_reg2_reg))
#define  DC_SYS_DC_dummy_reg2_dummy_reg2_shift                                   (0)
#define  DC_SYS_DC_dummy_reg2_dummy_reg2_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_dummy_reg2_dummy_reg2(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_dummy_reg2_get_dummy_reg2(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_dummy_reg3                                                    0x180071FC
#define  DC_SYS_DC_dummy_reg3_reg_addr                                           "0xB80071FC"
#define  DC_SYS_DC_dummy_reg3_reg                                                0xB80071FC
#define  DC_SYS_DC_dummy_reg3_inst_addr                                          "0x0047"
#define  set_DC_SYS_DC_dummy_reg3_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_dummy_reg3_reg)=data)
#define  get_DC_SYS_DC_dummy_reg3_reg                                            (*((volatile unsigned int*)DC_SYS_DC_dummy_reg3_reg))
#define  DC_SYS_DC_dummy_reg3_dummy_reg3_shift                                   (0)
#define  DC_SYS_DC_dummy_reg3_dummy_reg3_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_dummy_reg3_dummy_reg3(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_dummy_reg3_get_dummy_reg3(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_TYPE_0                                                     0x18007200
#define  DC_SYS_DC_MT_TYPE_0_reg_addr                                            "0xB8007200"
#define  DC_SYS_DC_MT_TYPE_0_reg                                                 0xB8007200
#define  DC_SYS_DC_MT_TYPE_0_inst_addr                                           "0x0048"
#define  set_DC_SYS_DC_MT_TYPE_0_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_0_reg)=data)
#define  get_DC_SYS_DC_MT_TYPE_0_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_0_reg))
#define  DC_SYS_DC_MT_TYPE_0_mem_type_shift                                      (30)
#define  DC_SYS_DC_MT_TYPE_0_mem_type_mask                                       (0xC0000000)
#define  DC_SYS_DC_MT_TYPE_0_mem_type(data)                                      (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_TYPE_0_get_mem_type(data)                                  ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MT_TYPE_1                                                     0x18007204
#define  DC_SYS_DC_MT_TYPE_1_reg_addr                                            "0xB8007204"
#define  DC_SYS_DC_MT_TYPE_1_reg                                                 0xB8007204
#define  DC_SYS_DC_MT_TYPE_1_inst_addr                                           "0x0049"
#define  set_DC_SYS_DC_MT_TYPE_1_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_1_reg)=data)
#define  get_DC_SYS_DC_MT_TYPE_1_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_1_reg))
#define  DC_SYS_DC_MT_TYPE_1_mem_type_shift                                      (30)
#define  DC_SYS_DC_MT_TYPE_1_mem_type_mask                                       (0xC0000000)
#define  DC_SYS_DC_MT_TYPE_1_mem_type(data)                                      (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_TYPE_1_get_mem_type(data)                                  ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MT_TYPE_2                                                     0x18007208
#define  DC_SYS_DC_MT_TYPE_2_reg_addr                                            "0xB8007208"
#define  DC_SYS_DC_MT_TYPE_2_reg                                                 0xB8007208
#define  DC_SYS_DC_MT_TYPE_2_inst_addr                                           "0x004A"
#define  set_DC_SYS_DC_MT_TYPE_2_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_2_reg)=data)
#define  get_DC_SYS_DC_MT_TYPE_2_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_2_reg))
#define  DC_SYS_DC_MT_TYPE_2_mem_type_shift                                      (30)
#define  DC_SYS_DC_MT_TYPE_2_mem_type_mask                                       (0xC0000000)
#define  DC_SYS_DC_MT_TYPE_2_mem_type(data)                                      (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_TYPE_2_get_mem_type(data)                                  ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MT_TYPE_3                                                     0x1800720C
#define  DC_SYS_DC_MT_TYPE_3_reg_addr                                            "0xB800720C"
#define  DC_SYS_DC_MT_TYPE_3_reg                                                 0xB800720C
#define  DC_SYS_DC_MT_TYPE_3_inst_addr                                           "0x004B"
#define  set_DC_SYS_DC_MT_TYPE_3_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_3_reg)=data)
#define  get_DC_SYS_DC_MT_TYPE_3_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_TYPE_3_reg))
#define  DC_SYS_DC_MT_TYPE_3_mem_type_shift                                      (30)
#define  DC_SYS_DC_MT_TYPE_3_mem_type_mask                                       (0xC0000000)
#define  DC_SYS_DC_MT_TYPE_3_mem_type(data)                                      (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_TYPE_3_get_mem_type(data)                                  ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MT_SADDR_0                                                    0x18007210
#define  DC_SYS_DC_MT_SADDR_0_reg_addr                                           "0xB8007210"
#define  DC_SYS_DC_MT_SADDR_0_reg                                                0xB8007210
#define  DC_SYS_DC_MT_SADDR_0_inst_addr                                          "0x004C"
#define  set_DC_SYS_DC_MT_SADDR_0_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_0_reg)=data)
#define  get_DC_SYS_DC_MT_SADDR_0_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_0_reg))
#define  DC_SYS_DC_MT_SADDR_0_saddr_shift                                        (5)
#define  DC_SYS_DC_MT_SADDR_0_saddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_SADDR_0_saddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_SADDR_0_get_saddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_SADDR_1                                                    0x18007214
#define  DC_SYS_DC_MT_SADDR_1_reg_addr                                           "0xB8007214"
#define  DC_SYS_DC_MT_SADDR_1_reg                                                0xB8007214
#define  DC_SYS_DC_MT_SADDR_1_inst_addr                                          "0x004D"
#define  set_DC_SYS_DC_MT_SADDR_1_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_1_reg)=data)
#define  get_DC_SYS_DC_MT_SADDR_1_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_1_reg))
#define  DC_SYS_DC_MT_SADDR_1_saddr_shift                                        (5)
#define  DC_SYS_DC_MT_SADDR_1_saddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_SADDR_1_saddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_SADDR_1_get_saddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_SADDR_2                                                    0x18007218
#define  DC_SYS_DC_MT_SADDR_2_reg_addr                                           "0xB8007218"
#define  DC_SYS_DC_MT_SADDR_2_reg                                                0xB8007218
#define  DC_SYS_DC_MT_SADDR_2_inst_addr                                          "0x004E"
#define  set_DC_SYS_DC_MT_SADDR_2_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_2_reg)=data)
#define  get_DC_SYS_DC_MT_SADDR_2_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_2_reg))
#define  DC_SYS_DC_MT_SADDR_2_saddr_shift                                        (5)
#define  DC_SYS_DC_MT_SADDR_2_saddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_SADDR_2_saddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_SADDR_2_get_saddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_SADDR_3                                                    0x1800721C
#define  DC_SYS_DC_MT_SADDR_3_reg_addr                                           "0xB800721C"
#define  DC_SYS_DC_MT_SADDR_3_reg                                                0xB800721C
#define  DC_SYS_DC_MT_SADDR_3_inst_addr                                          "0x004F"
#define  set_DC_SYS_DC_MT_SADDR_3_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_3_reg)=data)
#define  get_DC_SYS_DC_MT_SADDR_3_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_SADDR_3_reg))
#define  DC_SYS_DC_MT_SADDR_3_saddr_shift                                        (5)
#define  DC_SYS_DC_MT_SADDR_3_saddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_SADDR_3_saddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_SADDR_3_get_saddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_EADDR_0                                                    0x18007220
#define  DC_SYS_DC_MT_EADDR_0_reg_addr                                           "0xB8007220"
#define  DC_SYS_DC_MT_EADDR_0_reg                                                0xB8007220
#define  DC_SYS_DC_MT_EADDR_0_inst_addr                                          "0x0050"
#define  set_DC_SYS_DC_MT_EADDR_0_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_0_reg)=data)
#define  get_DC_SYS_DC_MT_EADDR_0_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_0_reg))
#define  DC_SYS_DC_MT_EADDR_0_eaddr_shift                                        (5)
#define  DC_SYS_DC_MT_EADDR_0_eaddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_EADDR_0_eaddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_EADDR_0_get_eaddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_EADDR_1                                                    0x18007224
#define  DC_SYS_DC_MT_EADDR_1_reg_addr                                           "0xB8007224"
#define  DC_SYS_DC_MT_EADDR_1_reg                                                0xB8007224
#define  DC_SYS_DC_MT_EADDR_1_inst_addr                                          "0x0051"
#define  set_DC_SYS_DC_MT_EADDR_1_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_1_reg)=data)
#define  get_DC_SYS_DC_MT_EADDR_1_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_1_reg))
#define  DC_SYS_DC_MT_EADDR_1_eaddr_shift                                        (5)
#define  DC_SYS_DC_MT_EADDR_1_eaddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_EADDR_1_eaddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_EADDR_1_get_eaddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_EADDR_2                                                    0x18007228
#define  DC_SYS_DC_MT_EADDR_2_reg_addr                                           "0xB8007228"
#define  DC_SYS_DC_MT_EADDR_2_reg                                                0xB8007228
#define  DC_SYS_DC_MT_EADDR_2_inst_addr                                          "0x0052"
#define  set_DC_SYS_DC_MT_EADDR_2_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_2_reg)=data)
#define  get_DC_SYS_DC_MT_EADDR_2_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_2_reg))
#define  DC_SYS_DC_MT_EADDR_2_eaddr_shift                                        (5)
#define  DC_SYS_DC_MT_EADDR_2_eaddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_EADDR_2_eaddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_EADDR_2_get_eaddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_EADDR_3                                                    0x1800722C
#define  DC_SYS_DC_MT_EADDR_3_reg_addr                                           "0xB800722C"
#define  DC_SYS_DC_MT_EADDR_3_reg                                                0xB800722C
#define  DC_SYS_DC_MT_EADDR_3_inst_addr                                          "0x0053"
#define  set_DC_SYS_DC_MT_EADDR_3_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_3_reg)=data)
#define  get_DC_SYS_DC_MT_EADDR_3_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_EADDR_3_reg))
#define  DC_SYS_DC_MT_EADDR_3_eaddr_shift                                        (5)
#define  DC_SYS_DC_MT_EADDR_3_eaddr_mask                                         (0x7FFFFFE0)
#define  DC_SYS_DC_MT_EADDR_3_eaddr(data)                                        (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MT_EADDR_3_get_eaddr(data)                                    ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MT_MODE_0                                                     0x18007240
#define  DC_SYS_DC_MT_MODE_0_reg_addr                                            "0xB8007240"
#define  DC_SYS_DC_MT_MODE_0_reg                                                 0xB8007240
#define  DC_SYS_DC_MT_MODE_0_inst_addr                                           "0x0054"
#define  set_DC_SYS_DC_MT_MODE_0_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_0_reg)=data)
#define  get_DC_SYS_DC_MT_MODE_0_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_0_reg))
#define  DC_SYS_DC_MT_MODE_0_write_enable5_shift                                 (2)
#define  DC_SYS_DC_MT_MODE_0_mode_shift                                          (0)
#define  DC_SYS_DC_MT_MODE_0_write_enable5_mask                                  (0x00000004)
#define  DC_SYS_DC_MT_MODE_0_mode_mask                                           (0x00000003)
#define  DC_SYS_DC_MT_MODE_0_write_enable5(data)                                 (0x00000004&((data)<<2))
#define  DC_SYS_DC_MT_MODE_0_mode(data)                                          (0x00000003&(data))
#define  DC_SYS_DC_MT_MODE_0_get_write_enable5(data)                             ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MT_MODE_0_get_mode(data)                                      (0x00000003&(data))

#define  DC_SYS_DC_MT_MODE_1                                                     0x18007244
#define  DC_SYS_DC_MT_MODE_1_reg_addr                                            "0xB8007244"
#define  DC_SYS_DC_MT_MODE_1_reg                                                 0xB8007244
#define  DC_SYS_DC_MT_MODE_1_inst_addr                                           "0x0055"
#define  set_DC_SYS_DC_MT_MODE_1_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_1_reg)=data)
#define  get_DC_SYS_DC_MT_MODE_1_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_1_reg))
#define  DC_SYS_DC_MT_MODE_1_write_enable5_shift                                 (2)
#define  DC_SYS_DC_MT_MODE_1_mode_shift                                          (0)
#define  DC_SYS_DC_MT_MODE_1_write_enable5_mask                                  (0x00000004)
#define  DC_SYS_DC_MT_MODE_1_mode_mask                                           (0x00000003)
#define  DC_SYS_DC_MT_MODE_1_write_enable5(data)                                 (0x00000004&((data)<<2))
#define  DC_SYS_DC_MT_MODE_1_mode(data)                                          (0x00000003&(data))
#define  DC_SYS_DC_MT_MODE_1_get_write_enable5(data)                             ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MT_MODE_1_get_mode(data)                                      (0x00000003&(data))

#define  DC_SYS_DC_MT_MODE_2                                                     0x18007248
#define  DC_SYS_DC_MT_MODE_2_reg_addr                                            "0xB8007248"
#define  DC_SYS_DC_MT_MODE_2_reg                                                 0xB8007248
#define  DC_SYS_DC_MT_MODE_2_inst_addr                                           "0x0056"
#define  set_DC_SYS_DC_MT_MODE_2_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_2_reg)=data)
#define  get_DC_SYS_DC_MT_MODE_2_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_2_reg))
#define  DC_SYS_DC_MT_MODE_2_write_enable5_shift                                 (2)
#define  DC_SYS_DC_MT_MODE_2_mode_shift                                          (0)
#define  DC_SYS_DC_MT_MODE_2_write_enable5_mask                                  (0x00000004)
#define  DC_SYS_DC_MT_MODE_2_mode_mask                                           (0x00000003)
#define  DC_SYS_DC_MT_MODE_2_write_enable5(data)                                 (0x00000004&((data)<<2))
#define  DC_SYS_DC_MT_MODE_2_mode(data)                                          (0x00000003&(data))
#define  DC_SYS_DC_MT_MODE_2_get_write_enable5(data)                             ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MT_MODE_2_get_mode(data)                                      (0x00000003&(data))

#define  DC_SYS_DC_MT_MODE_3                                                     0x1800724C
#define  DC_SYS_DC_MT_MODE_3_reg_addr                                            "0xB800724C"
#define  DC_SYS_DC_MT_MODE_3_reg                                                 0xB800724C
#define  DC_SYS_DC_MT_MODE_3_inst_addr                                           "0x0057"
#define  set_DC_SYS_DC_MT_MODE_3_reg(data)                                       (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_3_reg)=data)
#define  get_DC_SYS_DC_MT_MODE_3_reg                                             (*((volatile unsigned int*)DC_SYS_DC_MT_MODE_3_reg))
#define  DC_SYS_DC_MT_MODE_3_write_enable5_shift                                 (2)
#define  DC_SYS_DC_MT_MODE_3_mode_shift                                          (0)
#define  DC_SYS_DC_MT_MODE_3_write_enable5_mask                                  (0x00000004)
#define  DC_SYS_DC_MT_MODE_3_mode_mask                                           (0x00000003)
#define  DC_SYS_DC_MT_MODE_3_write_enable5(data)                                 (0x00000004&((data)<<2))
#define  DC_SYS_DC_MT_MODE_3_mode(data)                                          (0x00000003&(data))
#define  DC_SYS_DC_MT_MODE_3_get_write_enable5(data)                             ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MT_MODE_3_get_mode(data)                                      (0x00000003&(data))

#define  DC_SYS_DC_MT_TABLE_0                                                    0x18007260
#define  DC_SYS_DC_MT_TABLE_0_reg_addr                                           "0xB8007260"
#define  DC_SYS_DC_MT_TABLE_0_reg                                                0xB8007260
#define  DC_SYS_DC_MT_TABLE_0_inst_addr                                          "0x0058"
#define  set_DC_SYS_DC_MT_TABLE_0_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_0_reg)=data)
#define  get_DC_SYS_DC_MT_TABLE_0_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_0_reg))
#define  DC_SYS_DC_MT_TABLE_0_module_id_0_shift                                  (24)
#define  DC_SYS_DC_MT_TABLE_0_module_id_1_shift                                  (16)
#define  DC_SYS_DC_MT_TABLE_0_module_id_2_shift                                  (8)
#define  DC_SYS_DC_MT_TABLE_0_module_id_3_shift                                  (0)
#define  DC_SYS_DC_MT_TABLE_0_module_id_0_mask                                   (0xFF000000)
#define  DC_SYS_DC_MT_TABLE_0_module_id_1_mask                                   (0x00FF0000)
#define  DC_SYS_DC_MT_TABLE_0_module_id_2_mask                                   (0x0000FF00)
#define  DC_SYS_DC_MT_TABLE_0_module_id_3_mask                                   (0x000000FF)
#define  DC_SYS_DC_MT_TABLE_0_module_id_0(data)                                  (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MT_TABLE_0_module_id_1(data)                                  (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MT_TABLE_0_module_id_2(data)                                  (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MT_TABLE_0_module_id_3(data)                                  (0x000000FF&(data))
#define  DC_SYS_DC_MT_TABLE_0_get_module_id_0(data)                              ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MT_TABLE_0_get_module_id_1(data)                              ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MT_TABLE_0_get_module_id_2(data)                              ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MT_TABLE_0_get_module_id_3(data)                              (0x000000FF&(data))

#define  DC_SYS_DC_MT_TABLE_1                                                    0x18007264
#define  DC_SYS_DC_MT_TABLE_1_reg_addr                                           "0xB8007264"
#define  DC_SYS_DC_MT_TABLE_1_reg                                                0xB8007264
#define  DC_SYS_DC_MT_TABLE_1_inst_addr                                          "0x0059"
#define  set_DC_SYS_DC_MT_TABLE_1_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_1_reg)=data)
#define  get_DC_SYS_DC_MT_TABLE_1_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_1_reg))
#define  DC_SYS_DC_MT_TABLE_1_module_id_0_shift                                  (24)
#define  DC_SYS_DC_MT_TABLE_1_module_id_1_shift                                  (16)
#define  DC_SYS_DC_MT_TABLE_1_module_id_2_shift                                  (8)
#define  DC_SYS_DC_MT_TABLE_1_module_id_3_shift                                  (0)
#define  DC_SYS_DC_MT_TABLE_1_module_id_0_mask                                   (0xFF000000)
#define  DC_SYS_DC_MT_TABLE_1_module_id_1_mask                                   (0x00FF0000)
#define  DC_SYS_DC_MT_TABLE_1_module_id_2_mask                                   (0x0000FF00)
#define  DC_SYS_DC_MT_TABLE_1_module_id_3_mask                                   (0x000000FF)
#define  DC_SYS_DC_MT_TABLE_1_module_id_0(data)                                  (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MT_TABLE_1_module_id_1(data)                                  (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MT_TABLE_1_module_id_2(data)                                  (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MT_TABLE_1_module_id_3(data)                                  (0x000000FF&(data))
#define  DC_SYS_DC_MT_TABLE_1_get_module_id_0(data)                              ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MT_TABLE_1_get_module_id_1(data)                              ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MT_TABLE_1_get_module_id_2(data)                              ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MT_TABLE_1_get_module_id_3(data)                              (0x000000FF&(data))

#define  DC_SYS_DC_MT_TABLE_2                                                    0x18007268
#define  DC_SYS_DC_MT_TABLE_2_reg_addr                                           "0xB8007268"
#define  DC_SYS_DC_MT_TABLE_2_reg                                                0xB8007268
#define  DC_SYS_DC_MT_TABLE_2_inst_addr                                          "0x005A"
#define  set_DC_SYS_DC_MT_TABLE_2_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_2_reg)=data)
#define  get_DC_SYS_DC_MT_TABLE_2_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_2_reg))
#define  DC_SYS_DC_MT_TABLE_2_module_id_0_shift                                  (24)
#define  DC_SYS_DC_MT_TABLE_2_module_id_1_shift                                  (16)
#define  DC_SYS_DC_MT_TABLE_2_module_id_2_shift                                  (8)
#define  DC_SYS_DC_MT_TABLE_2_module_id_3_shift                                  (0)
#define  DC_SYS_DC_MT_TABLE_2_module_id_0_mask                                   (0xFF000000)
#define  DC_SYS_DC_MT_TABLE_2_module_id_1_mask                                   (0x00FF0000)
#define  DC_SYS_DC_MT_TABLE_2_module_id_2_mask                                   (0x0000FF00)
#define  DC_SYS_DC_MT_TABLE_2_module_id_3_mask                                   (0x000000FF)
#define  DC_SYS_DC_MT_TABLE_2_module_id_0(data)                                  (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MT_TABLE_2_module_id_1(data)                                  (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MT_TABLE_2_module_id_2(data)                                  (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MT_TABLE_2_module_id_3(data)                                  (0x000000FF&(data))
#define  DC_SYS_DC_MT_TABLE_2_get_module_id_0(data)                              ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MT_TABLE_2_get_module_id_1(data)                              ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MT_TABLE_2_get_module_id_2(data)                              ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MT_TABLE_2_get_module_id_3(data)                              (0x000000FF&(data))

#define  DC_SYS_DC_MT_TABLE_3                                                    0x1800726C
#define  DC_SYS_DC_MT_TABLE_3_reg_addr                                           "0xB800726C"
#define  DC_SYS_DC_MT_TABLE_3_reg                                                0xB800726C
#define  DC_SYS_DC_MT_TABLE_3_inst_addr                                          "0x005B"
#define  set_DC_SYS_DC_MT_TABLE_3_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_3_reg)=data)
#define  get_DC_SYS_DC_MT_TABLE_3_reg                                            (*((volatile unsigned int*)DC_SYS_DC_MT_TABLE_3_reg))
#define  DC_SYS_DC_MT_TABLE_3_module_id_0_shift                                  (24)
#define  DC_SYS_DC_MT_TABLE_3_module_id_1_shift                                  (16)
#define  DC_SYS_DC_MT_TABLE_3_module_id_2_shift                                  (8)
#define  DC_SYS_DC_MT_TABLE_3_module_id_3_shift                                  (0)
#define  DC_SYS_DC_MT_TABLE_3_module_id_0_mask                                   (0xFF000000)
#define  DC_SYS_DC_MT_TABLE_3_module_id_1_mask                                   (0x00FF0000)
#define  DC_SYS_DC_MT_TABLE_3_module_id_2_mask                                   (0x0000FF00)
#define  DC_SYS_DC_MT_TABLE_3_module_id_3_mask                                   (0x000000FF)
#define  DC_SYS_DC_MT_TABLE_3_module_id_0(data)                                  (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MT_TABLE_3_module_id_1(data)                                  (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MT_TABLE_3_module_id_2(data)                                  (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MT_TABLE_3_module_id_3(data)                                  (0x000000FF&(data))
#define  DC_SYS_DC_MT_TABLE_3_get_module_id_0(data)                              ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MT_TABLE_3_get_module_id_1(data)                              ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MT_TABLE_3_get_module_id_2(data)                              ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MT_TABLE_3_get_module_id_3(data)                              (0x000000FF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_0                                                0x18007280
#define  DC_SYS_DC_MT_ADDCMD_HI_0_reg_addr                                       "0xB8007280"
#define  DC_SYS_DC_MT_ADDCMD_HI_0_reg                                            0xB8007280
#define  DC_SYS_DC_MT_ADDCMD_HI_0_inst_addr                                      "0x005C"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_0_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_0_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_0_shift                            (30)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_1_shift                            (28)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_2_shift                            (26)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_3_shift                            (24)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_ever_trap_shift                                (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_module_id_shift                                (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_0_mask                             (0xC0000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_1_mask                             (0x30000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_2_mask                             (0x0C000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_3_mask                             (0x03000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_ever_trap_mask                                 (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_module_id_mask                                 (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_addcmd_mask                                    (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_0(data)                            (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_1(data)                            (0x30000000&((data)<<28))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_2(data)                            (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_access_type_3(data)                            (0x03000000&((data)<<24))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_ever_trap(data)                                (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_module_id(data)                                (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_addcmd(data)                                   (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_access_type_0(data)                        ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_access_type_1(data)                        ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_access_type_2(data)                        ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_access_type_3(data)                        ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_ever_trap(data)                            ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_module_id(data)                            ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_0_get_addcmd(data)                               (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_1                                                0x18007284
#define  DC_SYS_DC_MT_ADDCMD_HI_1_reg_addr                                       "0xB8007284"
#define  DC_SYS_DC_MT_ADDCMD_HI_1_reg                                            0xB8007284
#define  DC_SYS_DC_MT_ADDCMD_HI_1_inst_addr                                      "0x005D"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_1_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_1_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_0_shift                            (30)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_1_shift                            (28)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_2_shift                            (26)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_3_shift                            (24)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_ever_trap_shift                                (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_module_id_shift                                (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_0_mask                             (0xC0000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_1_mask                             (0x30000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_2_mask                             (0x0C000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_3_mask                             (0x03000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_ever_trap_mask                                 (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_module_id_mask                                 (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_addcmd_mask                                    (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_0(data)                            (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_1(data)                            (0x30000000&((data)<<28))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_2(data)                            (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_access_type_3(data)                            (0x03000000&((data)<<24))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_ever_trap(data)                                (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_module_id(data)                                (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_addcmd(data)                                   (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_access_type_0(data)                        ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_access_type_1(data)                        ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_access_type_2(data)                        ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_access_type_3(data)                        ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_ever_trap(data)                            ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_module_id(data)                            ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_1_get_addcmd(data)                               (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_2                                                0x18007288
#define  DC_SYS_DC_MT_ADDCMD_HI_2_reg_addr                                       "0xB8007288"
#define  DC_SYS_DC_MT_ADDCMD_HI_2_reg                                            0xB8007288
#define  DC_SYS_DC_MT_ADDCMD_HI_2_inst_addr                                      "0x005E"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_2_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_2_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_0_shift                            (30)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_1_shift                            (28)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_2_shift                            (26)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_3_shift                            (24)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_ever_trap_shift                                (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_module_id_shift                                (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_0_mask                             (0xC0000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_1_mask                             (0x30000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_2_mask                             (0x0C000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_3_mask                             (0x03000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_ever_trap_mask                                 (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_module_id_mask                                 (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_addcmd_mask                                    (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_0(data)                            (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_1(data)                            (0x30000000&((data)<<28))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_2(data)                            (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_access_type_3(data)                            (0x03000000&((data)<<24))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_ever_trap(data)                                (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_module_id(data)                                (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_addcmd(data)                                   (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_access_type_0(data)                        ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_access_type_1(data)                        ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_access_type_2(data)                        ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_access_type_3(data)                        ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_ever_trap(data)                            ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_module_id(data)                            ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_2_get_addcmd(data)                               (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_3                                                0x1800728C
#define  DC_SYS_DC_MT_ADDCMD_HI_3_reg_addr                                       "0xB800728C"
#define  DC_SYS_DC_MT_ADDCMD_HI_3_reg                                            0xB800728C
#define  DC_SYS_DC_MT_ADDCMD_HI_3_inst_addr                                      "0x005F"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_3_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_3_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_0_shift                            (30)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_1_shift                            (28)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_2_shift                            (26)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_3_shift                            (24)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_ever_trap_shift                                (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_module_id_shift                                (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_0_mask                             (0xC0000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_1_mask                             (0x30000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_2_mask                             (0x0C000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_3_mask                             (0x03000000)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_ever_trap_mask                                 (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_module_id_mask                                 (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_addcmd_mask                                    (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_0(data)                            (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_1(data)                            (0x30000000&((data)<<28))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_2(data)                            (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_access_type_3(data)                            (0x03000000&((data)<<24))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_ever_trap(data)                                (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_module_id(data)                                (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_addcmd(data)                                   (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_access_type_0(data)                        ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_access_type_1(data)                        ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_access_type_2(data)                        ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_access_type_3(data)                        ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_ever_trap(data)                            ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_module_id(data)                            ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_3_get_addcmd(data)                               (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_0                                                0x180072A0
#define  DC_SYS_DC_MT_ADDCMD_LO_0_reg_addr                                       "0xB80072A0"
#define  DC_SYS_DC_MT_ADDCMD_LO_0_reg                                            0xB80072A0
#define  DC_SYS_DC_MT_ADDCMD_LO_0_inst_addr                                      "0x0060"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_0_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_0_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_0_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_0_addcmd_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_0_addcmd(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_0_get_addcmd(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_1                                                0x180072A4
#define  DC_SYS_DC_MT_ADDCMD_LO_1_reg_addr                                       "0xB80072A4"
#define  DC_SYS_DC_MT_ADDCMD_LO_1_reg                                            0xB80072A4
#define  DC_SYS_DC_MT_ADDCMD_LO_1_inst_addr                                      "0x0061"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_1_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_1_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_1_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_1_addcmd_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_1_addcmd(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_1_get_addcmd(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_2                                                0x180072A8
#define  DC_SYS_DC_MT_ADDCMD_LO_2_reg_addr                                       "0xB80072A8"
#define  DC_SYS_DC_MT_ADDCMD_LO_2_reg                                            0xB80072A8
#define  DC_SYS_DC_MT_ADDCMD_LO_2_inst_addr                                      "0x0062"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_2_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_2_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_2_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_2_addcmd_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_2_addcmd(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_2_get_addcmd(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_3                                                0x180072AC
#define  DC_SYS_DC_MT_ADDCMD_LO_3_reg_addr                                       "0xB80072AC"
#define  DC_SYS_DC_MT_ADDCMD_LO_3_reg                                            0xB80072AC
#define  DC_SYS_DC_MT_ADDCMD_LO_3_inst_addr                                      "0x0063"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_3_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_3_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_3_addcmd_shift                                   (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_3_addcmd_mask                                    (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_3_addcmd(data)                                   (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_3_get_addcmd(data)                               (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_0                                                0x180072B0
#define  DC_SYS_DC_MT_ADDCMD_SA_0_reg_addr                                       "0xB80072B0"
#define  DC_SYS_DC_MT_ADDCMD_SA_0_reg                                            0xB80072B0
#define  DC_SYS_DC_MT_ADDCMD_SA_0_inst_addr                                      "0x0064"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_0_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_0_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_0_trap_seq_sa_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_0_trap_seq_sa_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_0_trap_seq_sa(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_0_get_trap_seq_sa(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_1                                                0x180072B4
#define  DC_SYS_DC_MT_ADDCMD_SA_1_reg_addr                                       "0xB80072B4"
#define  DC_SYS_DC_MT_ADDCMD_SA_1_reg                                            0xB80072B4
#define  DC_SYS_DC_MT_ADDCMD_SA_1_inst_addr                                      "0x0065"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_1_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_1_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_1_trap_seq_sa_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_1_trap_seq_sa_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_1_trap_seq_sa(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_1_get_trap_seq_sa(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_2                                                0x180072B8
#define  DC_SYS_DC_MT_ADDCMD_SA_2_reg_addr                                       "0xB80072B8"
#define  DC_SYS_DC_MT_ADDCMD_SA_2_reg                                            0xB80072B8
#define  DC_SYS_DC_MT_ADDCMD_SA_2_inst_addr                                      "0x0066"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_2_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_2_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_2_trap_seq_sa_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_2_trap_seq_sa_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_2_trap_seq_sa(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_2_get_trap_seq_sa(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_3                                                0x180072BC
#define  DC_SYS_DC_MT_ADDCMD_SA_3_reg_addr                                       "0xB80072BC"
#define  DC_SYS_DC_MT_ADDCMD_SA_3_reg                                            0xB80072BC
#define  DC_SYS_DC_MT_ADDCMD_SA_3_inst_addr                                      "0x0067"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_3_reg(data)                                  (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_3_reg                                        (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_3_trap_seq_sa_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_3_trap_seq_sa_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_3_trap_seq_sa(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_3_get_trap_seq_sa(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_MISC                                                       0x180072C0
#define  DC_SYS_DC_MT_MISC_reg_addr                                              "0xB80072C0"
#define  DC_SYS_DC_MT_MISC_reg                                                   0xB80072C0
#define  DC_SYS_DC_MT_MISC_inst_addr                                             "0x0068"
#define  set_DC_SYS_DC_MT_MISC_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_MT_MISC_reg)=data)
#define  get_DC_SYS_DC_MT_MISC_reg                                               (*((volatile unsigned int*)DC_SYS_DC_MT_MISC_reg))
#define  DC_SYS_DC_MT_MISC_disable_cross_range_check_shift                       (0)
#define  DC_SYS_DC_MT_MISC_disable_cross_range_check_mask                        (0x00000001)
#define  DC_SYS_DC_MT_MISC_disable_cross_range_check(data)                       (0x00000001&(data))
#define  DC_SYS_DC_MT_MISC_get_disable_cross_range_check(data)                   (0x00000001&(data))

#define  DC_SYS_DC_EC_CTRL                                                       0x180072D0
#define  DC_SYS_DC_EC_CTRL_reg_addr                                              "0xB80072D0"
#define  DC_SYS_DC_EC_CTRL_reg                                                   0xB80072D0
#define  DC_SYS_DC_EC_CTRL_inst_addr                                             "0x0069"
#define  set_DC_SYS_DC_EC_CTRL_reg(data)                                         (*((volatile unsigned int*)DC_SYS_DC_EC_CTRL_reg)=data)
#define  get_DC_SYS_DC_EC_CTRL_reg                                               (*((volatile unsigned int*)DC_SYS_DC_EC_CTRL_reg))
#define  DC_SYS_DC_EC_CTRL_write_enable3_shift                                   (31)
#define  DC_SYS_DC_EC_CTRL_error_cmd_swap_addr_shift                             (4)
#define  DC_SYS_DC_EC_CTRL_write_enable2_shift                                   (3)
#define  DC_SYS_DC_EC_CTRL_error_cmd_swap_en_shift                               (2)
#define  DC_SYS_DC_EC_CTRL_write_enable1_shift                                   (1)
#define  DC_SYS_DC_EC_CTRL_error_cmd_detection_en_shift                          (0)
#define  DC_SYS_DC_EC_CTRL_write_enable3_mask                                    (0x80000000)
#define  DC_SYS_DC_EC_CTRL_error_cmd_swap_addr_mask                              (0x7FFFFFF0)
#define  DC_SYS_DC_EC_CTRL_write_enable2_mask                                    (0x00000008)
#define  DC_SYS_DC_EC_CTRL_error_cmd_swap_en_mask                                (0x00000004)
#define  DC_SYS_DC_EC_CTRL_write_enable1_mask                                    (0x00000002)
#define  DC_SYS_DC_EC_CTRL_error_cmd_detection_en_mask                           (0x00000001)
#define  DC_SYS_DC_EC_CTRL_write_enable3(data)                                   (0x80000000&((data)<<31))
#define  DC_SYS_DC_EC_CTRL_error_cmd_swap_addr(data)                             (0x7FFFFFF0&((data)<<4))
#define  DC_SYS_DC_EC_CTRL_write_enable2(data)                                   (0x00000008&((data)<<3))
#define  DC_SYS_DC_EC_CTRL_error_cmd_swap_en(data)                               (0x00000004&((data)<<2))
#define  DC_SYS_DC_EC_CTRL_write_enable1(data)                                   (0x00000002&((data)<<1))
#define  DC_SYS_DC_EC_CTRL_error_cmd_detection_en(data)                          (0x00000001&(data))
#define  DC_SYS_DC_EC_CTRL_get_write_enable3(data)                               ((0x80000000&(data))>>31)
#define  DC_SYS_DC_EC_CTRL_get_error_cmd_swap_addr(data)                         ((0x7FFFFFF0&(data))>>4)
#define  DC_SYS_DC_EC_CTRL_get_write_enable2(data)                               ((0x00000008&(data))>>3)
#define  DC_SYS_DC_EC_CTRL_get_error_cmd_swap_en(data)                           ((0x00000004&(data))>>2)
#define  DC_SYS_DC_EC_CTRL_get_write_enable1(data)                               ((0x00000002&(data))>>1)
#define  DC_SYS_DC_EC_CTRL_get_error_cmd_detection_en(data)                      (0x00000001&(data))

#define  DC_SYS_DC_EC_ADDCMD_HI                                                  0x180072D4
#define  DC_SYS_DC_EC_ADDCMD_HI_reg_addr                                         "0xB80072D4"
#define  DC_SYS_DC_EC_ADDCMD_HI_reg                                              0xB80072D4
#define  DC_SYS_DC_EC_ADDCMD_HI_inst_addr                                        "0x006A"
#define  set_DC_SYS_DC_EC_ADDCMD_HI_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_HI_reg)=data)
#define  get_DC_SYS_DC_EC_ADDCMD_HI_reg                                          (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_HI_reg))
#define  DC_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap_shift                        (31)
#define  DC_SYS_DC_EC_ADDCMD_HI_trap_case_shift                                  (23)
#define  DC_SYS_DC_EC_ADDCMD_HI_addcmd_hi_shift                                  (0)
#define  DC_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap_mask                         (0x80000000)
#define  DC_SYS_DC_EC_ADDCMD_HI_trap_case_mask                                   (0x7F800000)
#define  DC_SYS_DC_EC_ADDCMD_HI_addcmd_hi_mask                                   (0x007FFFFF)
#define  DC_SYS_DC_EC_ADDCMD_HI_error_cmd_ever_trap(data)                        (0x80000000&((data)<<31))
#define  DC_SYS_DC_EC_ADDCMD_HI_trap_case(data)                                  (0x7F800000&((data)<<23))
#define  DC_SYS_DC_EC_ADDCMD_HI_addcmd_hi(data)                                  (0x007FFFFF&(data))
#define  DC_SYS_DC_EC_ADDCMD_HI_get_error_cmd_ever_trap(data)                    ((0x80000000&(data))>>31)
#define  DC_SYS_DC_EC_ADDCMD_HI_get_trap_case(data)                              ((0x7F800000&(data))>>23)
#define  DC_SYS_DC_EC_ADDCMD_HI_get_addcmd_hi(data)                              (0x007FFFFF&(data))

#define  DC_SYS_DC_EC_ADDCMD_LO                                                  0x180072D8
#define  DC_SYS_DC_EC_ADDCMD_LO_reg_addr                                         "0xB80072D8"
#define  DC_SYS_DC_EC_ADDCMD_LO_reg                                              0xB80072D8
#define  DC_SYS_DC_EC_ADDCMD_LO_inst_addr                                        "0x006B"
#define  set_DC_SYS_DC_EC_ADDCMD_LO_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_LO_reg)=data)
#define  get_DC_SYS_DC_EC_ADDCMD_LO_reg                                          (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_LO_reg))
#define  DC_SYS_DC_EC_ADDCMD_LO_addcmd_lo_shift                                  (0)
#define  DC_SYS_DC_EC_ADDCMD_LO_addcmd_lo_mask                                   (0xFFFFFFFF)
#define  DC_SYS_DC_EC_ADDCMD_LO_addcmd_lo(data)                                  (0xFFFFFFFF&(data))
#define  DC_SYS_DC_EC_ADDCMD_LO_get_addcmd_lo(data)                              (0xFFFFFFFF&(data))

#define  DC_SYS_DC_RD_TAG_CHECK                                                  0x180072DC
#define  DC_SYS_DC_RD_TAG_CHECK_reg_addr                                         "0xB80072DC"
#define  DC_SYS_DC_RD_TAG_CHECK_reg                                              0xB80072DC
#define  DC_SYS_DC_RD_TAG_CHECK_inst_addr                                        "0x006C"
#define  set_DC_SYS_DC_RD_TAG_CHECK_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_RD_TAG_CHECK_reg)=data)
#define  get_DC_SYS_DC_RD_TAG_CHECK_reg                                          (*((volatile unsigned int*)DC_SYS_DC_RD_TAG_CHECK_reg))
#define  DC_SYS_DC_RD_TAG_CHECK_write_enable2_shift                              (3)
#define  DC_SYS_DC_RD_TAG_CHECK_err_blk_err_dis_shift                            (2)
#define  DC_SYS_DC_RD_TAG_CHECK_write_enable1_shift                              (1)
#define  DC_SYS_DC_RD_TAG_CHECK_tag_check_en_shift                               (0)
#define  DC_SYS_DC_RD_TAG_CHECK_write_enable2_mask                               (0x00000008)
#define  DC_SYS_DC_RD_TAG_CHECK_err_blk_err_dis_mask                             (0x00000004)
#define  DC_SYS_DC_RD_TAG_CHECK_write_enable1_mask                               (0x00000002)
#define  DC_SYS_DC_RD_TAG_CHECK_tag_check_en_mask                                (0x00000001)
#define  DC_SYS_DC_RD_TAG_CHECK_write_enable2(data)                              (0x00000008&((data)<<3))
#define  DC_SYS_DC_RD_TAG_CHECK_err_blk_err_dis(data)                            (0x00000004&((data)<<2))
#define  DC_SYS_DC_RD_TAG_CHECK_write_enable1(data)                              (0x00000002&((data)<<1))
#define  DC_SYS_DC_RD_TAG_CHECK_tag_check_en(data)                               (0x00000001&(data))
#define  DC_SYS_DC_RD_TAG_CHECK_get_write_enable2(data)                          ((0x00000008&(data))>>3)
#define  DC_SYS_DC_RD_TAG_CHECK_get_err_blk_err_dis(data)                        ((0x00000004&(data))>>2)
#define  DC_SYS_DC_RD_TAG_CHECK_get_write_enable1(data)                          ((0x00000002&(data))>>1)
#define  DC_SYS_DC_RD_TAG_CHECK_get_tag_check_en(data)                           (0x00000001&(data))

#define  DC_SYS_DC_int_enable                                                    0x180072E8
#define  DC_SYS_DC_int_enable_reg_addr                                           "0xB80072E8"
#define  DC_SYS_DC_int_enable_reg                                                0xB80072E8
#define  DC_SYS_DC_int_enable_inst_addr                                          "0x006D"
#define  set_DC_SYS_DC_int_enable_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_int_enable_reg)=data)
#define  get_DC_SYS_DC_int_enable_reg                                            (*((volatile unsigned int*)DC_SYS_DC_int_enable_reg))
#define  DC_SYS_DC_int_enable_pic_offset_x_odd_int_en_shift                      (24)
#define  DC_SYS_DC_int_enable_rd_tag_mismatch_int_en_shift                       (23)
#define  DC_SYS_DC_int_enable_err_seq_sa_odd_int_en_shift                        (22)
#define  DC_SYS_DC_int_enable_err_seq_bl_zero_int_en_shift                       (21)
#define  DC_SYS_DC_int_enable_err_seq_bl_odd_int_en_shift                        (20)
#define  DC_SYS_DC_int_enable_err_blk_8x2_on_64_int_en_shift                     (19)
#define  DC_SYS_DC_int_enable_err_blk_size_exceed_int_en_shift                   (18)
#define  DC_SYS_DC_int_enable_err_blk_h_zero_int_en_shift                        (17)
#define  DC_SYS_DC_int_enable_err_blk_w_zero_int_en_shift                        (16)
#define  DC_SYS_DC_int_enable_err_blk_err_int_en_shift                           (15)
#define  DC_SYS_DC_int_enable_mt_3_mod3_int_en_shift                             (12)
#define  DC_SYS_DC_int_enable_mt_3_mod2_int_en_shift                             (11)
#define  DC_SYS_DC_int_enable_mt_3_mod1_int_en_shift                             (10)
#define  DC_SYS_DC_int_enable_mt_2_mod3_int_en_shift                             (9)
#define  DC_SYS_DC_int_enable_mt_2_mod2_int_en_shift                             (8)
#define  DC_SYS_DC_int_enable_mt_2_mod1_int_en_shift                             (7)
#define  DC_SYS_DC_int_enable_mt_1_mod3_int_en_shift                             (6)
#define  DC_SYS_DC_int_enable_mt_1_mod2_int_en_shift                             (5)
#define  DC_SYS_DC_int_enable_mt_1_mod1_int_en_shift                             (4)
#define  DC_SYS_DC_int_enable_mt_0_mod3_int_en_shift                             (3)
#define  DC_SYS_DC_int_enable_mt_0_mod2_int_en_shift                             (2)
#define  DC_SYS_DC_int_enable_mt_0_mod1_int_en_shift                             (1)
#define  DC_SYS_DC_int_enable_write_data_shift                                   (0)
#define  DC_SYS_DC_int_enable_pic_offset_x_odd_int_en_mask                       (0x01000000)
#define  DC_SYS_DC_int_enable_rd_tag_mismatch_int_en_mask                        (0x00800000)
#define  DC_SYS_DC_int_enable_err_seq_sa_odd_int_en_mask                         (0x00400000)
#define  DC_SYS_DC_int_enable_err_seq_bl_zero_int_en_mask                        (0x00200000)
#define  DC_SYS_DC_int_enable_err_seq_bl_odd_int_en_mask                         (0x00100000)
#define  DC_SYS_DC_int_enable_err_blk_8x2_on_64_int_en_mask                      (0x00080000)
#define  DC_SYS_DC_int_enable_err_blk_size_exceed_int_en_mask                    (0x00040000)
#define  DC_SYS_DC_int_enable_err_blk_h_zero_int_en_mask                         (0x00020000)
#define  DC_SYS_DC_int_enable_err_blk_w_zero_int_en_mask                         (0x00010000)
#define  DC_SYS_DC_int_enable_err_blk_err_int_en_mask                            (0x00008000)
#define  DC_SYS_DC_int_enable_mt_3_mod3_int_en_mask                              (0x00001000)
#define  DC_SYS_DC_int_enable_mt_3_mod2_int_en_mask                              (0x00000800)
#define  DC_SYS_DC_int_enable_mt_3_mod1_int_en_mask                              (0x00000400)
#define  DC_SYS_DC_int_enable_mt_2_mod3_int_en_mask                              (0x00000200)
#define  DC_SYS_DC_int_enable_mt_2_mod2_int_en_mask                              (0x00000100)
#define  DC_SYS_DC_int_enable_mt_2_mod1_int_en_mask                              (0x00000080)
#define  DC_SYS_DC_int_enable_mt_1_mod3_int_en_mask                              (0x00000040)
#define  DC_SYS_DC_int_enable_mt_1_mod2_int_en_mask                              (0x00000020)
#define  DC_SYS_DC_int_enable_mt_1_mod1_int_en_mask                              (0x00000010)
#define  DC_SYS_DC_int_enable_mt_0_mod3_int_en_mask                              (0x00000008)
#define  DC_SYS_DC_int_enable_mt_0_mod2_int_en_mask                              (0x00000004)
#define  DC_SYS_DC_int_enable_mt_0_mod1_int_en_mask                              (0x00000002)
#define  DC_SYS_DC_int_enable_write_data_mask                                    (0x00000001)
#define  DC_SYS_DC_int_enable_pic_offset_x_odd_int_en(data)                      (0x01000000&((data)<<24))
#define  DC_SYS_DC_int_enable_rd_tag_mismatch_int_en(data)                       (0x00800000&((data)<<23))
#define  DC_SYS_DC_int_enable_err_seq_sa_odd_int_en(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_int_enable_err_seq_bl_zero_int_en(data)                       (0x00200000&((data)<<21))
#define  DC_SYS_DC_int_enable_err_seq_bl_odd_int_en(data)                        (0x00100000&((data)<<20))
#define  DC_SYS_DC_int_enable_err_blk_8x2_on_64_int_en(data)                     (0x00080000&((data)<<19))
#define  DC_SYS_DC_int_enable_err_blk_size_exceed_int_en(data)                   (0x00040000&((data)<<18))
#define  DC_SYS_DC_int_enable_err_blk_h_zero_int_en(data)                        (0x00020000&((data)<<17))
#define  DC_SYS_DC_int_enable_err_blk_w_zero_int_en(data)                        (0x00010000&((data)<<16))
#define  DC_SYS_DC_int_enable_err_blk_err_int_en(data)                           (0x00008000&((data)<<15))
#define  DC_SYS_DC_int_enable_mt_3_mod3_int_en(data)                             (0x00001000&((data)<<12))
#define  DC_SYS_DC_int_enable_mt_3_mod2_int_en(data)                             (0x00000800&((data)<<11))
#define  DC_SYS_DC_int_enable_mt_3_mod1_int_en(data)                             (0x00000400&((data)<<10))
#define  DC_SYS_DC_int_enable_mt_2_mod3_int_en(data)                             (0x00000200&((data)<<9))
#define  DC_SYS_DC_int_enable_mt_2_mod2_int_en(data)                             (0x00000100&((data)<<8))
#define  DC_SYS_DC_int_enable_mt_2_mod1_int_en(data)                             (0x00000080&((data)<<7))
#define  DC_SYS_DC_int_enable_mt_1_mod3_int_en(data)                             (0x00000040&((data)<<6))
#define  DC_SYS_DC_int_enable_mt_1_mod2_int_en(data)                             (0x00000020&((data)<<5))
#define  DC_SYS_DC_int_enable_mt_1_mod1_int_en(data)                             (0x00000010&((data)<<4))
#define  DC_SYS_DC_int_enable_mt_0_mod3_int_en(data)                             (0x00000008&((data)<<3))
#define  DC_SYS_DC_int_enable_mt_0_mod2_int_en(data)                             (0x00000004&((data)<<2))
#define  DC_SYS_DC_int_enable_mt_0_mod1_int_en(data)                             (0x00000002&((data)<<1))
#define  DC_SYS_DC_int_enable_write_data(data)                                   (0x00000001&(data))
#define  DC_SYS_DC_int_enable_get_pic_offset_x_odd_int_en(data)                  ((0x01000000&(data))>>24)
#define  DC_SYS_DC_int_enable_get_rd_tag_mismatch_int_en(data)                   ((0x00800000&(data))>>23)
#define  DC_SYS_DC_int_enable_get_err_seq_sa_odd_int_en(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_int_enable_get_err_seq_bl_zero_int_en(data)                   ((0x00200000&(data))>>21)
#define  DC_SYS_DC_int_enable_get_err_seq_bl_odd_int_en(data)                    ((0x00100000&(data))>>20)
#define  DC_SYS_DC_int_enable_get_err_blk_8x2_on_64_int_en(data)                 ((0x00080000&(data))>>19)
#define  DC_SYS_DC_int_enable_get_err_blk_size_exceed_int_en(data)               ((0x00040000&(data))>>18)
#define  DC_SYS_DC_int_enable_get_err_blk_h_zero_int_en(data)                    ((0x00020000&(data))>>17)
#define  DC_SYS_DC_int_enable_get_err_blk_w_zero_int_en(data)                    ((0x00010000&(data))>>16)
#define  DC_SYS_DC_int_enable_get_err_blk_err_int_en(data)                       ((0x00008000&(data))>>15)
#define  DC_SYS_DC_int_enable_get_mt_3_mod3_int_en(data)                         ((0x00001000&(data))>>12)
#define  DC_SYS_DC_int_enable_get_mt_3_mod2_int_en(data)                         ((0x00000800&(data))>>11)
#define  DC_SYS_DC_int_enable_get_mt_3_mod1_int_en(data)                         ((0x00000400&(data))>>10)
#define  DC_SYS_DC_int_enable_get_mt_2_mod3_int_en(data)                         ((0x00000200&(data))>>9)
#define  DC_SYS_DC_int_enable_get_mt_2_mod2_int_en(data)                         ((0x00000100&(data))>>8)
#define  DC_SYS_DC_int_enable_get_mt_2_mod1_int_en(data)                         ((0x00000080&(data))>>7)
#define  DC_SYS_DC_int_enable_get_mt_1_mod3_int_en(data)                         ((0x00000040&(data))>>6)
#define  DC_SYS_DC_int_enable_get_mt_1_mod2_int_en(data)                         ((0x00000020&(data))>>5)
#define  DC_SYS_DC_int_enable_get_mt_1_mod1_int_en(data)                         ((0x00000010&(data))>>4)
#define  DC_SYS_DC_int_enable_get_mt_0_mod3_int_en(data)                         ((0x00000008&(data))>>3)
#define  DC_SYS_DC_int_enable_get_mt_0_mod2_int_en(data)                         ((0x00000004&(data))>>2)
#define  DC_SYS_DC_int_enable_get_mt_0_mod1_int_en(data)                         ((0x00000002&(data))>>1)
#define  DC_SYS_DC_int_enable_get_write_data(data)                               (0x00000001&(data))

#define  DC_SYS_DC_int_status                                                    0x180072EC
#define  DC_SYS_DC_int_status_reg_addr                                           "0xB80072EC"
#define  DC_SYS_DC_int_status_reg                                                0xB80072EC
#define  DC_SYS_DC_int_status_inst_addr                                          "0x006E"
#define  set_DC_SYS_DC_int_status_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_int_status_reg)=data)
#define  get_DC_SYS_DC_int_status_reg                                            (*((volatile unsigned int*)DC_SYS_DC_int_status_reg))
#define  DC_SYS_DC_int_status_pic_offset_x_odd_int_shift                         (24)
#define  DC_SYS_DC_int_status_rd_tag_mismatch_int_shift                          (23)
#define  DC_SYS_DC_int_status_err_seq_sa_odd_int_shift                           (22)
#define  DC_SYS_DC_int_status_err_seq_bl_zero_int_shift                          (21)
#define  DC_SYS_DC_int_status_err_seq_bl_odd_int_shift                           (20)
#define  DC_SYS_DC_int_status_err_blk_8x2_on_64_int_shift                        (19)
#define  DC_SYS_DC_int_status_err_blk_size_exceed_int_shift                      (18)
#define  DC_SYS_DC_int_status_err_blk_h_zero_int_shift                           (17)
#define  DC_SYS_DC_int_status_err_blk_w_zero_int_shift                           (16)
#define  DC_SYS_DC_int_status_err_blk_err_int_shift                              (15)
#define  DC_SYS_DC_int_status_mt_3_mod3_int_shift                                (12)
#define  DC_SYS_DC_int_status_mt_3_mod2_int_shift                                (11)
#define  DC_SYS_DC_int_status_mt_3_mod1_int_shift                                (10)
#define  DC_SYS_DC_int_status_mt_2_mod3_int_shift                                (9)
#define  DC_SYS_DC_int_status_mt_2_mod2_int_shift                                (8)
#define  DC_SYS_DC_int_status_mt_2_mod1_int_shift                                (7)
#define  DC_SYS_DC_int_status_mt_1_mod3_int_shift                                (6)
#define  DC_SYS_DC_int_status_mt_1_mod2_int_shift                                (5)
#define  DC_SYS_DC_int_status_mt_1_mod1_int_shift                                (4)
#define  DC_SYS_DC_int_status_mt_0_mod3_int_shift                                (3)
#define  DC_SYS_DC_int_status_mt_0_mod2_int_shift                                (2)
#define  DC_SYS_DC_int_status_mt_0_mod1_int_shift                                (1)
#define  DC_SYS_DC_int_status_write_data_shift                                   (0)
#define  DC_SYS_DC_int_status_pic_offset_x_odd_int_mask                          (0x01000000)
#define  DC_SYS_DC_int_status_rd_tag_mismatch_int_mask                           (0x00800000)
#define  DC_SYS_DC_int_status_err_seq_sa_odd_int_mask                            (0x00400000)
#define  DC_SYS_DC_int_status_err_seq_bl_zero_int_mask                           (0x00200000)
#define  DC_SYS_DC_int_status_err_seq_bl_odd_int_mask                            (0x00100000)
#define  DC_SYS_DC_int_status_err_blk_8x2_on_64_int_mask                         (0x00080000)
#define  DC_SYS_DC_int_status_err_blk_size_exceed_int_mask                       (0x00040000)
#define  DC_SYS_DC_int_status_err_blk_h_zero_int_mask                            (0x00020000)
#define  DC_SYS_DC_int_status_err_blk_w_zero_int_mask                            (0x00010000)
#define  DC_SYS_DC_int_status_err_blk_err_int_mask                               (0x00008000)
#define  DC_SYS_DC_int_status_mt_3_mod3_int_mask                                 (0x00001000)
#define  DC_SYS_DC_int_status_mt_3_mod2_int_mask                                 (0x00000800)
#define  DC_SYS_DC_int_status_mt_3_mod1_int_mask                                 (0x00000400)
#define  DC_SYS_DC_int_status_mt_2_mod3_int_mask                                 (0x00000200)
#define  DC_SYS_DC_int_status_mt_2_mod2_int_mask                                 (0x00000100)
#define  DC_SYS_DC_int_status_mt_2_mod1_int_mask                                 (0x00000080)
#define  DC_SYS_DC_int_status_mt_1_mod3_int_mask                                 (0x00000040)
#define  DC_SYS_DC_int_status_mt_1_mod2_int_mask                                 (0x00000020)
#define  DC_SYS_DC_int_status_mt_1_mod1_int_mask                                 (0x00000010)
#define  DC_SYS_DC_int_status_mt_0_mod3_int_mask                                 (0x00000008)
#define  DC_SYS_DC_int_status_mt_0_mod2_int_mask                                 (0x00000004)
#define  DC_SYS_DC_int_status_mt_0_mod1_int_mask                                 (0x00000002)
#define  DC_SYS_DC_int_status_write_data_mask                                    (0x00000001)
#define  DC_SYS_DC_int_status_pic_offset_x_odd_int(data)                         (0x01000000&((data)<<24))
#define  DC_SYS_DC_int_status_rd_tag_mismatch_int(data)                          (0x00800000&((data)<<23))
#define  DC_SYS_DC_int_status_err_seq_sa_odd_int(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_int_status_err_seq_bl_zero_int(data)                          (0x00200000&((data)<<21))
#define  DC_SYS_DC_int_status_err_seq_bl_odd_int(data)                           (0x00100000&((data)<<20))
#define  DC_SYS_DC_int_status_err_blk_8x2_on_64_int(data)                        (0x00080000&((data)<<19))
#define  DC_SYS_DC_int_status_err_blk_size_exceed_int(data)                      (0x00040000&((data)<<18))
#define  DC_SYS_DC_int_status_err_blk_h_zero_int(data)                           (0x00020000&((data)<<17))
#define  DC_SYS_DC_int_status_err_blk_w_zero_int(data)                           (0x00010000&((data)<<16))
#define  DC_SYS_DC_int_status_err_blk_err_int(data)                              (0x00008000&((data)<<15))
#define  DC_SYS_DC_int_status_mt_3_mod3_int(data)                                (0x00001000&((data)<<12))
#define  DC_SYS_DC_int_status_mt_3_mod2_int(data)                                (0x00000800&((data)<<11))
#define  DC_SYS_DC_int_status_mt_3_mod1_int(data)                                (0x00000400&((data)<<10))
#define  DC_SYS_DC_int_status_mt_2_mod3_int(data)                                (0x00000200&((data)<<9))
#define  DC_SYS_DC_int_status_mt_2_mod2_int(data)                                (0x00000100&((data)<<8))
#define  DC_SYS_DC_int_status_mt_2_mod1_int(data)                                (0x00000080&((data)<<7))
#define  DC_SYS_DC_int_status_mt_1_mod3_int(data)                                (0x00000040&((data)<<6))
#define  DC_SYS_DC_int_status_mt_1_mod2_int(data)                                (0x00000020&((data)<<5))
#define  DC_SYS_DC_int_status_mt_1_mod1_int(data)                                (0x00000010&((data)<<4))
#define  DC_SYS_DC_int_status_mt_0_mod3_int(data)                                (0x00000008&((data)<<3))
#define  DC_SYS_DC_int_status_mt_0_mod2_int(data)                                (0x00000004&((data)<<2))
#define  DC_SYS_DC_int_status_mt_0_mod1_int(data)                                (0x00000002&((data)<<1))
#define  DC_SYS_DC_int_status_write_data(data)                                   (0x00000001&(data))
#define  DC_SYS_DC_int_status_get_pic_offset_x_odd_int(data)                     ((0x01000000&(data))>>24)
#define  DC_SYS_DC_int_status_get_rd_tag_mismatch_int(data)                      ((0x00800000&(data))>>23)
#define  DC_SYS_DC_int_status_get_err_seq_sa_odd_int(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_int_status_get_err_seq_bl_zero_int(data)                      ((0x00200000&(data))>>21)
#define  DC_SYS_DC_int_status_get_err_seq_bl_odd_int(data)                       ((0x00100000&(data))>>20)
#define  DC_SYS_DC_int_status_get_err_blk_8x2_on_64_int(data)                    ((0x00080000&(data))>>19)
#define  DC_SYS_DC_int_status_get_err_blk_size_exceed_int(data)                  ((0x00040000&(data))>>18)
#define  DC_SYS_DC_int_status_get_err_blk_h_zero_int(data)                       ((0x00020000&(data))>>17)
#define  DC_SYS_DC_int_status_get_err_blk_w_zero_int(data)                       ((0x00010000&(data))>>16)
#define  DC_SYS_DC_int_status_get_err_blk_err_int(data)                          ((0x00008000&(data))>>15)
#define  DC_SYS_DC_int_status_get_mt_3_mod3_int(data)                            ((0x00001000&(data))>>12)
#define  DC_SYS_DC_int_status_get_mt_3_mod2_int(data)                            ((0x00000800&(data))>>11)
#define  DC_SYS_DC_int_status_get_mt_3_mod1_int(data)                            ((0x00000400&(data))>>10)
#define  DC_SYS_DC_int_status_get_mt_2_mod3_int(data)                            ((0x00000200&(data))>>9)
#define  DC_SYS_DC_int_status_get_mt_2_mod2_int(data)                            ((0x00000100&(data))>>8)
#define  DC_SYS_DC_int_status_get_mt_2_mod1_int(data)                            ((0x00000080&(data))>>7)
#define  DC_SYS_DC_int_status_get_mt_1_mod3_int(data)                            ((0x00000040&(data))>>6)
#define  DC_SYS_DC_int_status_get_mt_1_mod2_int(data)                            ((0x00000020&(data))>>5)
#define  DC_SYS_DC_int_status_get_mt_1_mod1_int(data)                            ((0x00000010&(data))>>4)
#define  DC_SYS_DC_int_status_get_mt_0_mod3_int(data)                            ((0x00000008&(data))>>3)
#define  DC_SYS_DC_int_status_get_mt_0_mod2_int(data)                            ((0x00000004&(data))>>2)
#define  DC_SYS_DC_int_status_get_mt_0_mod1_int(data)                            ((0x00000002&(data))>>1)
#define  DC_SYS_DC_int_status_get_write_data(data)                               (0x00000001&(data))

#define  DC_SYS_bw_ctrl                                                          0x18007300
#define  DC_SYS_bw_ctrl_reg_addr                                                 "0xB8007300"
#define  DC_SYS_bw_ctrl_reg                                                      0xB8007300
#define  DC_SYS_bw_ctrl_inst_addr                                                "0x006F"
#define  set_DC_SYS_bw_ctrl_reg(data)                                            (*((volatile unsigned int*)DC_SYS_bw_ctrl_reg)=data)
#define  get_DC_SYS_bw_ctrl_reg                                                  (*((volatile unsigned int*)DC_SYS_bw_ctrl_reg))
#define  DC_SYS_bw_ctrl_bypass_req_to_arb_shift                                  (31)
#define  DC_SYS_bw_ctrl_bw_mode_shift                                            (0)
#define  DC_SYS_bw_ctrl_bypass_req_to_arb_mask                                   (0x80000000)
#define  DC_SYS_bw_ctrl_bw_mode_mask                                             (0x03FFFFFF)
#define  DC_SYS_bw_ctrl_bypass_req_to_arb(data)                                  (0x80000000&((data)<<31))
#define  DC_SYS_bw_ctrl_bw_mode(data)                                            (0x03FFFFFF&(data))
#define  DC_SYS_bw_ctrl_get_bypass_req_to_arb(data)                              ((0x80000000&(data))>>31)
#define  DC_SYS_bw_ctrl_get_bw_mode(data)                                        (0x03FFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_0                                             0x18007304
#define  DC_SYS_bw_timer_threshold_0_reg_addr                                    "0xB8007304"
#define  DC_SYS_bw_timer_threshold_0_reg                                         0xB8007304
#define  DC_SYS_bw_timer_threshold_0_inst_addr                                   "0x0070"
#define  set_DC_SYS_bw_timer_threshold_0_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_0_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_0_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_0_reg))
#define  DC_SYS_bw_timer_threshold_0_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_0_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_0_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_0_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_1                                             0x18007308
#define  DC_SYS_bw_timer_threshold_1_reg_addr                                    "0xB8007308"
#define  DC_SYS_bw_timer_threshold_1_reg                                         0xB8007308
#define  DC_SYS_bw_timer_threshold_1_inst_addr                                   "0x0071"
#define  set_DC_SYS_bw_timer_threshold_1_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_1_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_1_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_1_reg))
#define  DC_SYS_bw_timer_threshold_1_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_1_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_1_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_1_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_2                                             0x1800730C
#define  DC_SYS_bw_timer_threshold_2_reg_addr                                    "0xB800730C"
#define  DC_SYS_bw_timer_threshold_2_reg                                         0xB800730C
#define  DC_SYS_bw_timer_threshold_2_inst_addr                                   "0x0072"
#define  set_DC_SYS_bw_timer_threshold_2_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_2_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_2_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_2_reg))
#define  DC_SYS_bw_timer_threshold_2_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_2_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_2_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_2_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_3                                             0x18007310
#define  DC_SYS_bw_timer_threshold_3_reg_addr                                    "0xB8007310"
#define  DC_SYS_bw_timer_threshold_3_reg                                         0xB8007310
#define  DC_SYS_bw_timer_threshold_3_inst_addr                                   "0x0073"
#define  set_DC_SYS_bw_timer_threshold_3_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_3_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_3_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_3_reg))
#define  DC_SYS_bw_timer_threshold_3_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_3_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_3_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_3_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_4                                             0x18007314
#define  DC_SYS_bw_timer_threshold_4_reg_addr                                    "0xB8007314"
#define  DC_SYS_bw_timer_threshold_4_reg                                         0xB8007314
#define  DC_SYS_bw_timer_threshold_4_inst_addr                                   "0x0074"
#define  set_DC_SYS_bw_timer_threshold_4_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_4_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_4_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_4_reg))
#define  DC_SYS_bw_timer_threshold_4_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_4_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_4_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_4_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_5                                             0x18007318
#define  DC_SYS_bw_timer_threshold_5_reg_addr                                    "0xB8007318"
#define  DC_SYS_bw_timer_threshold_5_reg                                         0xB8007318
#define  DC_SYS_bw_timer_threshold_5_inst_addr                                   "0x0075"
#define  set_DC_SYS_bw_timer_threshold_5_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_5_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_5_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_5_reg))
#define  DC_SYS_bw_timer_threshold_5_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_5_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_5_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_5_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_6                                             0x1800731C
#define  DC_SYS_bw_timer_threshold_6_reg_addr                                    "0xB800731C"
#define  DC_SYS_bw_timer_threshold_6_reg                                         0xB800731C
#define  DC_SYS_bw_timer_threshold_6_inst_addr                                   "0x0076"
#define  set_DC_SYS_bw_timer_threshold_6_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_6_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_6_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_6_reg))
#define  DC_SYS_bw_timer_threshold_6_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_6_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_6_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_6_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_7                                             0x18007320
#define  DC_SYS_bw_timer_threshold_7_reg_addr                                    "0xB8007320"
#define  DC_SYS_bw_timer_threshold_7_reg                                         0xB8007320
#define  DC_SYS_bw_timer_threshold_7_inst_addr                                   "0x0077"
#define  set_DC_SYS_bw_timer_threshold_7_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_7_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_7_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_7_reg))
#define  DC_SYS_bw_timer_threshold_7_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_7_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_7_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_7_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_8                                             0x18007324
#define  DC_SYS_bw_timer_threshold_8_reg_addr                                    "0xB8007324"
#define  DC_SYS_bw_timer_threshold_8_reg                                         0xB8007324
#define  DC_SYS_bw_timer_threshold_8_inst_addr                                   "0x0078"
#define  set_DC_SYS_bw_timer_threshold_8_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_8_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_8_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_8_reg))
#define  DC_SYS_bw_timer_threshold_8_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_8_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_8_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_8_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_9                                             0x18007328
#define  DC_SYS_bw_timer_threshold_9_reg_addr                                    "0xB8007328"
#define  DC_SYS_bw_timer_threshold_9_reg                                         0xB8007328
#define  DC_SYS_bw_timer_threshold_9_inst_addr                                   "0x0079"
#define  set_DC_SYS_bw_timer_threshold_9_reg(data)                               (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_9_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_9_reg                                     (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_9_reg))
#define  DC_SYS_bw_timer_threshold_9_value_shift                                 (0)
#define  DC_SYS_bw_timer_threshold_9_value_mask                                  (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_9_value(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_9_get_value(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_10                                            0x1800732C
#define  DC_SYS_bw_timer_threshold_10_reg_addr                                   "0xB800732C"
#define  DC_SYS_bw_timer_threshold_10_reg                                        0xB800732C
#define  DC_SYS_bw_timer_threshold_10_inst_addr                                  "0x007A"
#define  set_DC_SYS_bw_timer_threshold_10_reg(data)                              (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_10_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_10_reg                                    (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_10_reg))
#define  DC_SYS_bw_timer_threshold_10_value_shift                                (0)
#define  DC_SYS_bw_timer_threshold_10_value_mask                                 (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_10_value(data)                                (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_10_get_value(data)                            (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_11                                            0x18007330
#define  DC_SYS_bw_timer_threshold_11_reg_addr                                   "0xB8007330"
#define  DC_SYS_bw_timer_threshold_11_reg                                        0xB8007330
#define  DC_SYS_bw_timer_threshold_11_inst_addr                                  "0x007B"
#define  set_DC_SYS_bw_timer_threshold_11_reg(data)                              (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_11_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_11_reg                                    (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_11_reg))
#define  DC_SYS_bw_timer_threshold_11_value_shift                                (0)
#define  DC_SYS_bw_timer_threshold_11_value_mask                                 (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_11_value(data)                                (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_11_get_value(data)                            (0xFFFFFFFF&(data))

#define  DC_SYS_bw_timer_threshold_12                                            0x18007334
#define  DC_SYS_bw_timer_threshold_12_reg_addr                                   "0xB8007334"
#define  DC_SYS_bw_timer_threshold_12_reg                                        0xB8007334
#define  DC_SYS_bw_timer_threshold_12_inst_addr                                  "0x007C"
#define  set_DC_SYS_bw_timer_threshold_12_reg(data)                              (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_12_reg)=data)
#define  get_DC_SYS_bw_timer_threshold_12_reg                                    (*((volatile unsigned int*)DC_SYS_bw_timer_threshold_12_reg))
#define  DC_SYS_bw_timer_threshold_12_value_shift                                (0)
#define  DC_SYS_bw_timer_threshold_12_value_mask                                 (0xFFFFFFFF)
#define  DC_SYS_bw_timer_threshold_12_value(data)                                (0xFFFFFFFF&(data))
#define  DC_SYS_bw_timer_threshold_12_get_value(data)                            (0xFFFFFFFF&(data))

#define  DC_SYS_bw_request_threshold_0                                           0x18007338
#define  DC_SYS_bw_request_threshold_0_reg_addr                                  "0xB8007338"
#define  DC_SYS_bw_request_threshold_0_reg                                       0xB8007338
#define  DC_SYS_bw_request_threshold_0_inst_addr                                 "0x007D"
#define  set_DC_SYS_bw_request_threshold_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_0_reg)=data)
#define  get_DC_SYS_bw_request_threshold_0_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_0_reg))
#define  DC_SYS_bw_request_threshold_0_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_0_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_0_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_0_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_1                                           0x1800733C
#define  DC_SYS_bw_request_threshold_1_reg_addr                                  "0xB800733C"
#define  DC_SYS_bw_request_threshold_1_reg                                       0xB800733C
#define  DC_SYS_bw_request_threshold_1_inst_addr                                 "0x007E"
#define  set_DC_SYS_bw_request_threshold_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_1_reg)=data)
#define  get_DC_SYS_bw_request_threshold_1_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_1_reg))
#define  DC_SYS_bw_request_threshold_1_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_1_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_1_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_1_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_2                                           0x18007340
#define  DC_SYS_bw_request_threshold_2_reg_addr                                  "0xB8007340"
#define  DC_SYS_bw_request_threshold_2_reg                                       0xB8007340
#define  DC_SYS_bw_request_threshold_2_inst_addr                                 "0x007F"
#define  set_DC_SYS_bw_request_threshold_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_2_reg)=data)
#define  get_DC_SYS_bw_request_threshold_2_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_2_reg))
#define  DC_SYS_bw_request_threshold_2_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_2_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_2_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_2_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_3                                           0x18007344
#define  DC_SYS_bw_request_threshold_3_reg_addr                                  "0xB8007344"
#define  DC_SYS_bw_request_threshold_3_reg                                       0xB8007344
#define  DC_SYS_bw_request_threshold_3_inst_addr                                 "0x0080"
#define  set_DC_SYS_bw_request_threshold_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_3_reg)=data)
#define  get_DC_SYS_bw_request_threshold_3_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_3_reg))
#define  DC_SYS_bw_request_threshold_3_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_3_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_3_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_3_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_4                                           0x18007348
#define  DC_SYS_bw_request_threshold_4_reg_addr                                  "0xB8007348"
#define  DC_SYS_bw_request_threshold_4_reg                                       0xB8007348
#define  DC_SYS_bw_request_threshold_4_inst_addr                                 "0x0081"
#define  set_DC_SYS_bw_request_threshold_4_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_4_reg)=data)
#define  get_DC_SYS_bw_request_threshold_4_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_4_reg))
#define  DC_SYS_bw_request_threshold_4_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_4_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_4_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_4_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_5                                           0x1800734C
#define  DC_SYS_bw_request_threshold_5_reg_addr                                  "0xB800734C"
#define  DC_SYS_bw_request_threshold_5_reg                                       0xB800734C
#define  DC_SYS_bw_request_threshold_5_inst_addr                                 "0x0082"
#define  set_DC_SYS_bw_request_threshold_5_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_5_reg)=data)
#define  get_DC_SYS_bw_request_threshold_5_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_5_reg))
#define  DC_SYS_bw_request_threshold_5_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_5_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_5_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_5_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_6                                           0x18007350
#define  DC_SYS_bw_request_threshold_6_reg_addr                                  "0xB8007350"
#define  DC_SYS_bw_request_threshold_6_reg                                       0xB8007350
#define  DC_SYS_bw_request_threshold_6_inst_addr                                 "0x0083"
#define  set_DC_SYS_bw_request_threshold_6_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_6_reg)=data)
#define  get_DC_SYS_bw_request_threshold_6_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_6_reg))
#define  DC_SYS_bw_request_threshold_6_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_6_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_6_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_6_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_7                                           0x18007354
#define  DC_SYS_bw_request_threshold_7_reg_addr                                  "0xB8007354"
#define  DC_SYS_bw_request_threshold_7_reg                                       0xB8007354
#define  DC_SYS_bw_request_threshold_7_inst_addr                                 "0x0084"
#define  set_DC_SYS_bw_request_threshold_7_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_7_reg)=data)
#define  get_DC_SYS_bw_request_threshold_7_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_7_reg))
#define  DC_SYS_bw_request_threshold_7_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_7_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_7_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_7_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_8                                           0x18007358
#define  DC_SYS_bw_request_threshold_8_reg_addr                                  "0xB8007358"
#define  DC_SYS_bw_request_threshold_8_reg                                       0xB8007358
#define  DC_SYS_bw_request_threshold_8_inst_addr                                 "0x0085"
#define  set_DC_SYS_bw_request_threshold_8_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_8_reg)=data)
#define  get_DC_SYS_bw_request_threshold_8_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_8_reg))
#define  DC_SYS_bw_request_threshold_8_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_8_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_8_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_8_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_9                                           0x1800735C
#define  DC_SYS_bw_request_threshold_9_reg_addr                                  "0xB800735C"
#define  DC_SYS_bw_request_threshold_9_reg                                       0xB800735C
#define  DC_SYS_bw_request_threshold_9_inst_addr                                 "0x0086"
#define  set_DC_SYS_bw_request_threshold_9_reg(data)                             (*((volatile unsigned int*)DC_SYS_bw_request_threshold_9_reg)=data)
#define  get_DC_SYS_bw_request_threshold_9_reg                                   (*((volatile unsigned int*)DC_SYS_bw_request_threshold_9_reg))
#define  DC_SYS_bw_request_threshold_9_value_shift                               (0)
#define  DC_SYS_bw_request_threshold_9_value_mask                                (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_9_value(data)                               (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_9_get_value(data)                           (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_10                                          0x18007360
#define  DC_SYS_bw_request_threshold_10_reg_addr                                 "0xB8007360"
#define  DC_SYS_bw_request_threshold_10_reg                                      0xB8007360
#define  DC_SYS_bw_request_threshold_10_inst_addr                                "0x0087"
#define  set_DC_SYS_bw_request_threshold_10_reg(data)                            (*((volatile unsigned int*)DC_SYS_bw_request_threshold_10_reg)=data)
#define  get_DC_SYS_bw_request_threshold_10_reg                                  (*((volatile unsigned int*)DC_SYS_bw_request_threshold_10_reg))
#define  DC_SYS_bw_request_threshold_10_value_shift                              (0)
#define  DC_SYS_bw_request_threshold_10_value_mask                               (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_10_value(data)                              (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_10_get_value(data)                          (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_11                                          0x18007364
#define  DC_SYS_bw_request_threshold_11_reg_addr                                 "0xB8007364"
#define  DC_SYS_bw_request_threshold_11_reg                                      0xB8007364
#define  DC_SYS_bw_request_threshold_11_inst_addr                                "0x0088"
#define  set_DC_SYS_bw_request_threshold_11_reg(data)                            (*((volatile unsigned int*)DC_SYS_bw_request_threshold_11_reg)=data)
#define  get_DC_SYS_bw_request_threshold_11_reg                                  (*((volatile unsigned int*)DC_SYS_bw_request_threshold_11_reg))
#define  DC_SYS_bw_request_threshold_11_value_shift                              (0)
#define  DC_SYS_bw_request_threshold_11_value_mask                               (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_11_value(data)                              (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_11_get_value(data)                          (0x00FFFFFF&(data))

#define  DC_SYS_bw_request_threshold_12                                          0x18007368
#define  DC_SYS_bw_request_threshold_12_reg_addr                                 "0xB8007368"
#define  DC_SYS_bw_request_threshold_12_reg                                      0xB8007368
#define  DC_SYS_bw_request_threshold_12_inst_addr                                "0x0089"
#define  set_DC_SYS_bw_request_threshold_12_reg(data)                            (*((volatile unsigned int*)DC_SYS_bw_request_threshold_12_reg)=data)
#define  get_DC_SYS_bw_request_threshold_12_reg                                  (*((volatile unsigned int*)DC_SYS_bw_request_threshold_12_reg))
#define  DC_SYS_bw_request_threshold_12_value_shift                              (0)
#define  DC_SYS_bw_request_threshold_12_value_mask                               (0x00FFFFFF)
#define  DC_SYS_bw_request_threshold_12_value(data)                              (0x00FFFFFF&(data))
#define  DC_SYS_bw_request_threshold_12_get_value(data)                          (0x00FFFFFF&(data))

#define  DC_SYS_dc_sys2_mux                                                      0x18007400
#define  DC_SYS_dc_sys2_mux_reg_addr                                             "0xB8007400"
#define  DC_SYS_dc_sys2_mux_reg                                                  0xB8007400
#define  DC_SYS_dc_sys2_mux_inst_addr                                            "0x008A"
#define  set_DC_SYS_dc_sys2_mux_reg(data)                                        (*((volatile unsigned int*)DC_SYS_dc_sys2_mux_reg)=data)
#define  get_DC_SYS_dc_sys2_mux_reg                                              (*((volatile unsigned int*)DC_SYS_dc_sys2_mux_reg))
#define  DC_SYS_dc_sys2_mux_pre_tra_rd_cnt_shift                                 (20)
#define  DC_SYS_dc_sys2_mux_pre_tra_wr_cnt_shift                                 (8)
#define  DC_SYS_dc_sys2_mux_tv_sb5_mux_shift                                     (4)
#define  DC_SYS_dc_sys2_mux_tv_sb1_mux_shift                                     (3)
#define  DC_SYS_dc_sys2_mux_memc_mux_shift                                       (2)
#define  DC_SYS_dc_sys2_mux_tv_sb4_mux_shift                                     (1)
#define  DC_SYS_dc_sys2_mux_tv_sb2_mux_shift                                     (0)
#define  DC_SYS_dc_sys2_mux_pre_tra_rd_cnt_mask                                  (0x3FF00000)
#define  DC_SYS_dc_sys2_mux_pre_tra_wr_cnt_mask                                  (0x0003FF00)
#define  DC_SYS_dc_sys2_mux_tv_sb5_mux_mask                                      (0x00000010)
#define  DC_SYS_dc_sys2_mux_tv_sb1_mux_mask                                      (0x00000008)
#define  DC_SYS_dc_sys2_mux_memc_mux_mask                                        (0x00000004)
#define  DC_SYS_dc_sys2_mux_tv_sb4_mux_mask                                      (0x00000002)
#define  DC_SYS_dc_sys2_mux_tv_sb2_mux_mask                                      (0x00000001)
#define  DC_SYS_dc_sys2_mux_pre_tra_rd_cnt(data)                                 (0x3FF00000&((data)<<20))
#define  DC_SYS_dc_sys2_mux_pre_tra_wr_cnt(data)                                 (0x0003FF00&((data)<<8))
#define  DC_SYS_dc_sys2_mux_tv_sb5_mux(data)                                     (0x00000010&((data)<<4))
#define  DC_SYS_dc_sys2_mux_tv_sb1_mux(data)                                     (0x00000008&((data)<<3))
#define  DC_SYS_dc_sys2_mux_memc_mux(data)                                       (0x00000004&((data)<<2))
#define  DC_SYS_dc_sys2_mux_tv_sb4_mux(data)                                     (0x00000002&((data)<<1))
#define  DC_SYS_dc_sys2_mux_tv_sb2_mux(data)                                     (0x00000001&(data))
#define  DC_SYS_dc_sys2_mux_get_pre_tra_rd_cnt(data)                             ((0x3FF00000&(data))>>20)
#define  DC_SYS_dc_sys2_mux_get_pre_tra_wr_cnt(data)                             ((0x0003FF00&(data))>>8)
#define  DC_SYS_dc_sys2_mux_get_tv_sb5_mux(data)                                 ((0x00000010&(data))>>4)
#define  DC_SYS_dc_sys2_mux_get_tv_sb1_mux(data)                                 ((0x00000008&(data))>>3)
#define  DC_SYS_dc_sys2_mux_get_memc_mux(data)                                   ((0x00000004&(data))>>2)
#define  DC_SYS_dc_sys2_mux_get_tv_sb4_mux(data)                                 ((0x00000002&(data))>>1)
#define  DC_SYS_dc_sys2_mux_get_tv_sb2_mux(data)                                 (0x00000001&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0                                           0x18007410
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg_addr                                  "0xB8007410"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg                                       0xB8007410
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_inst_addr                                 "0x008B"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1                                           0x18007414
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg_addr                                  "0xB8007414"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg                                       0xB8007414
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_inst_addr                                 "0x008C"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_1_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2                                           0x18007418
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg_addr                                  "0xB8007418"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg                                       0xB8007418
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_inst_addr                                 "0x008D"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_2_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3                                           0x1800741C
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg_addr                                  "0xB800741C"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg                                       0xB800741C
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_inst_addr                                 "0x008E"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS2_3_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0                                           0x18007420
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg_addr                                  "0xB8007420"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg                                       0xB8007420
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_inst_addr                                 "0x008F"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1                                           0x18007424
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg_addr                                  "0xB8007424"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg                                       0xB8007424
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_inst_addr                                 "0x0090"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_1_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2                                           0x18007428
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg_addr                                  "0xB8007428"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg                                       0xB8007428
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_inst_addr                                 "0x0091"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_2_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3                                           0x1800742C
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg_addr                                  "0xB800742C"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg                                       0xB800742C
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_inst_addr                                 "0x0092"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS2_3_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0                                           0x18007430
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg_addr                                  "0xB8007430"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg                                       0xB8007430
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_inst_addr                                 "0x0093"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1                                           0x18007434
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg_addr                                  "0xB8007434"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg                                       0xB8007434
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_inst_addr                                 "0x0094"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_1_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2                                           0x18007438
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg_addr                                  "0xB8007438"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg                                       0xB8007438
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_inst_addr                                 "0x0095"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_2_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3                                           0x1800743C
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg_addr                                  "0xB800743C"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg                                       0xB800743C
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_inst_addr                                 "0x0096"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS2_3_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2                                             0x18007440
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg_addr                                    "0xB8007440"
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg                                         0xB8007440
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_inst_addr                                   "0x0097"
#define  set_DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg)=data)
#define  get_DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg                                     (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_shift                   (31)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case_shift                             (23)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_addcmd_hi_shift                             (0)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap_mask                    (0x80000000)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case_mask                              (0x7F800000)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_addcmd_hi_mask                              (0x007FFFFF)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_error_cmd_ever_trap(data)                   (0x80000000&((data)<<31))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_trap_case(data)                             (0x7F800000&((data)<<23))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_addcmd_hi(data)                             (0x007FFFFF&(data))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_get_error_cmd_ever_trap(data)               ((0x80000000&(data))>>31)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_get_trap_case(data)                         ((0x7F800000&(data))>>23)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS2_get_addcmd_hi(data)                         (0x007FFFFF&(data))

#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2                                             0x18007444
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg_addr                                    "0xB8007444"
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg                                         0xB8007444
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_inst_addr                                   "0x0098"
#define  set_DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg)=data)
#define  get_DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg                                     (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg))
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_addcmd_lo_shift                             (0)
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_addcmd_lo_mask                              (0xFFFFFFFF)
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_addcmd_lo(data)                             (0xFFFFFFFF&(data))
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS2_get_addcmd_lo(data)                         (0xFFFFFFFF&(data))

#define  DC_SYS_DC_int_enable_SYS2                                               0x1800744C
#define  DC_SYS_DC_int_enable_SYS2_reg_addr                                      "0xB800744C"
#define  DC_SYS_DC_int_enable_SYS2_reg                                           0xB800744C
#define  DC_SYS_DC_int_enable_SYS2_inst_addr                                     "0x0099"
#define  set_DC_SYS_DC_int_enable_SYS2_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_int_enable_SYS2_reg)=data)
#define  get_DC_SYS_DC_int_enable_SYS2_reg                                       (*((volatile unsigned int*)DC_SYS_DC_int_enable_SYS2_reg))
#define  DC_SYS_DC_int_enable_SYS2_rd_tag_mismatch_int_en_shift                  (23)
#define  DC_SYS_DC_int_enable_SYS2_err_seq_sa_odd_int_en_shift                   (22)
#define  DC_SYS_DC_int_enable_SYS2_err_seq_bl_zero_int_en_shift                  (21)
#define  DC_SYS_DC_int_enable_SYS2_err_seq_bl_odd_int_en_shift                   (20)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_8x2_on_64_int_en_shift                (19)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_size_exceed_int_en_shift              (18)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_h_zero_int_en_shift                   (17)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_w_zero_int_en_shift                   (16)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_err_int_en_shift                      (15)
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod3_int_en_shift                        (12)
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod2_int_en_shift                        (11)
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod1_int_en_shift                        (10)
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod3_int_en_shift                        (9)
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod2_int_en_shift                        (8)
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod1_int_en_shift                        (7)
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod3_int_en_shift                        (6)
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod2_int_en_shift                        (5)
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod1_int_en_shift                        (4)
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod3_int_en_shift                        (3)
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod2_int_en_shift                        (2)
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod1_int_en_shift                        (1)
#define  DC_SYS_DC_int_enable_SYS2_write_data_shift                              (0)
#define  DC_SYS_DC_int_enable_SYS2_rd_tag_mismatch_int_en_mask                   (0x00800000)
#define  DC_SYS_DC_int_enable_SYS2_err_seq_sa_odd_int_en_mask                    (0x00400000)
#define  DC_SYS_DC_int_enable_SYS2_err_seq_bl_zero_int_en_mask                   (0x00200000)
#define  DC_SYS_DC_int_enable_SYS2_err_seq_bl_odd_int_en_mask                    (0x00100000)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_8x2_on_64_int_en_mask                 (0x00080000)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_size_exceed_int_en_mask               (0x00040000)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_h_zero_int_en_mask                    (0x00020000)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_w_zero_int_en_mask                    (0x00010000)
#define  DC_SYS_DC_int_enable_SYS2_err_blk_err_int_en_mask                       (0x00008000)
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod3_int_en_mask                         (0x00001000)
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod2_int_en_mask                         (0x00000800)
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod1_int_en_mask                         (0x00000400)
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod3_int_en_mask                         (0x00000200)
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod2_int_en_mask                         (0x00000100)
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod1_int_en_mask                         (0x00000080)
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod3_int_en_mask                         (0x00000040)
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod2_int_en_mask                         (0x00000020)
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod1_int_en_mask                         (0x00000010)
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod3_int_en_mask                         (0x00000008)
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod2_int_en_mask                         (0x00000004)
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod1_int_en_mask                         (0x00000002)
#define  DC_SYS_DC_int_enable_SYS2_write_data_mask                               (0x00000001)
#define  DC_SYS_DC_int_enable_SYS2_rd_tag_mismatch_int_en(data)                  (0x00800000&((data)<<23))
#define  DC_SYS_DC_int_enable_SYS2_err_seq_sa_odd_int_en(data)                   (0x00400000&((data)<<22))
#define  DC_SYS_DC_int_enable_SYS2_err_seq_bl_zero_int_en(data)                  (0x00200000&((data)<<21))
#define  DC_SYS_DC_int_enable_SYS2_err_seq_bl_odd_int_en(data)                   (0x00100000&((data)<<20))
#define  DC_SYS_DC_int_enable_SYS2_err_blk_8x2_on_64_int_en(data)                (0x00080000&((data)<<19))
#define  DC_SYS_DC_int_enable_SYS2_err_blk_size_exceed_int_en(data)              (0x00040000&((data)<<18))
#define  DC_SYS_DC_int_enable_SYS2_err_blk_h_zero_int_en(data)                   (0x00020000&((data)<<17))
#define  DC_SYS_DC_int_enable_SYS2_err_blk_w_zero_int_en(data)                   (0x00010000&((data)<<16))
#define  DC_SYS_DC_int_enable_SYS2_err_blk_err_int_en(data)                      (0x00008000&((data)<<15))
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod3_int_en(data)                        (0x00001000&((data)<<12))
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod2_int_en(data)                        (0x00000800&((data)<<11))
#define  DC_SYS_DC_int_enable_SYS2_mt_3_mod1_int_en(data)                        (0x00000400&((data)<<10))
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod3_int_en(data)                        (0x00000200&((data)<<9))
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod2_int_en(data)                        (0x00000100&((data)<<8))
#define  DC_SYS_DC_int_enable_SYS2_mt_2_mod1_int_en(data)                        (0x00000080&((data)<<7))
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod3_int_en(data)                        (0x00000040&((data)<<6))
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod2_int_en(data)                        (0x00000020&((data)<<5))
#define  DC_SYS_DC_int_enable_SYS2_mt_1_mod1_int_en(data)                        (0x00000010&((data)<<4))
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod3_int_en(data)                        (0x00000008&((data)<<3))
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod2_int_en(data)                        (0x00000004&((data)<<2))
#define  DC_SYS_DC_int_enable_SYS2_mt_0_mod1_int_en(data)                        (0x00000002&((data)<<1))
#define  DC_SYS_DC_int_enable_SYS2_write_data(data)                              (0x00000001&(data))
#define  DC_SYS_DC_int_enable_SYS2_get_rd_tag_mismatch_int_en(data)              ((0x00800000&(data))>>23)
#define  DC_SYS_DC_int_enable_SYS2_get_err_seq_sa_odd_int_en(data)               ((0x00400000&(data))>>22)
#define  DC_SYS_DC_int_enable_SYS2_get_err_seq_bl_zero_int_en(data)              ((0x00200000&(data))>>21)
#define  DC_SYS_DC_int_enable_SYS2_get_err_seq_bl_odd_int_en(data)               ((0x00100000&(data))>>20)
#define  DC_SYS_DC_int_enable_SYS2_get_err_blk_8x2_on_64_int_en(data)            ((0x00080000&(data))>>19)
#define  DC_SYS_DC_int_enable_SYS2_get_err_blk_size_exceed_int_en(data)          ((0x00040000&(data))>>18)
#define  DC_SYS_DC_int_enable_SYS2_get_err_blk_h_zero_int_en(data)               ((0x00020000&(data))>>17)
#define  DC_SYS_DC_int_enable_SYS2_get_err_blk_w_zero_int_en(data)               ((0x00010000&(data))>>16)
#define  DC_SYS_DC_int_enable_SYS2_get_err_blk_err_int_en(data)                  ((0x00008000&(data))>>15)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_3_mod3_int_en(data)                    ((0x00001000&(data))>>12)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_3_mod2_int_en(data)                    ((0x00000800&(data))>>11)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_3_mod1_int_en(data)                    ((0x00000400&(data))>>10)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_2_mod3_int_en(data)                    ((0x00000200&(data))>>9)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_2_mod2_int_en(data)                    ((0x00000100&(data))>>8)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_2_mod1_int_en(data)                    ((0x00000080&(data))>>7)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_1_mod3_int_en(data)                    ((0x00000040&(data))>>6)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_1_mod2_int_en(data)                    ((0x00000020&(data))>>5)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_1_mod1_int_en(data)                    ((0x00000010&(data))>>4)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_0_mod3_int_en(data)                    ((0x00000008&(data))>>3)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_0_mod2_int_en(data)                    ((0x00000004&(data))>>2)
#define  DC_SYS_DC_int_enable_SYS2_get_mt_0_mod1_int_en(data)                    ((0x00000002&(data))>>1)
#define  DC_SYS_DC_int_enable_SYS2_get_write_data(data)                          (0x00000001&(data))

#define  DC_SYS_DC_int_status_SYS2                                               0x18007450
#define  DC_SYS_DC_int_status_SYS2_reg_addr                                      "0xB8007450"
#define  DC_SYS_DC_int_status_SYS2_reg                                           0xB8007450
#define  DC_SYS_DC_int_status_SYS2_inst_addr                                     "0x009A"
#define  set_DC_SYS_DC_int_status_SYS2_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_int_status_SYS2_reg)=data)
#define  get_DC_SYS_DC_int_status_SYS2_reg                                       (*((volatile unsigned int*)DC_SYS_DC_int_status_SYS2_reg))
#define  DC_SYS_DC_int_status_SYS2_rd_tag_mismatch_int_shift                     (23)
#define  DC_SYS_DC_int_status_SYS2_err_seq_sa_odd_int_shift                      (22)
#define  DC_SYS_DC_int_status_SYS2_err_seq_bl_zero_int_shift                     (21)
#define  DC_SYS_DC_int_status_SYS2_err_seq_bl_odd_int_shift                      (20)
#define  DC_SYS_DC_int_status_SYS2_err_blk_8x2_on_64_int_shift                   (19)
#define  DC_SYS_DC_int_status_SYS2_err_blk_size_exceed_int_shift                 (18)
#define  DC_SYS_DC_int_status_SYS2_err_blk_h_zero_int_shift                      (17)
#define  DC_SYS_DC_int_status_SYS2_err_blk_w_zero_int_shift                      (16)
#define  DC_SYS_DC_int_status_SYS2_err_blk_err_int_shift                         (15)
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod3_int_shift                           (12)
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod2_int_shift                           (11)
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod1_int_shift                           (10)
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod3_int_shift                           (9)
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod2_int_shift                           (8)
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod1_int_shift                           (7)
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod3_int_shift                           (6)
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod2_int_shift                           (5)
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod1_int_shift                           (4)
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod3_int_shift                           (3)
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod2_int_shift                           (2)
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod1_int_shift                           (1)
#define  DC_SYS_DC_int_status_SYS2_write_data_shift                              (0)
#define  DC_SYS_DC_int_status_SYS2_rd_tag_mismatch_int_mask                      (0x00800000)
#define  DC_SYS_DC_int_status_SYS2_err_seq_sa_odd_int_mask                       (0x00400000)
#define  DC_SYS_DC_int_status_SYS2_err_seq_bl_zero_int_mask                      (0x00200000)
#define  DC_SYS_DC_int_status_SYS2_err_seq_bl_odd_int_mask                       (0x00100000)
#define  DC_SYS_DC_int_status_SYS2_err_blk_8x2_on_64_int_mask                    (0x00080000)
#define  DC_SYS_DC_int_status_SYS2_err_blk_size_exceed_int_mask                  (0x00040000)
#define  DC_SYS_DC_int_status_SYS2_err_blk_h_zero_int_mask                       (0x00020000)
#define  DC_SYS_DC_int_status_SYS2_err_blk_w_zero_int_mask                       (0x00010000)
#define  DC_SYS_DC_int_status_SYS2_err_blk_err_int_mask                          (0x00008000)
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod3_int_mask                            (0x00001000)
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod2_int_mask                            (0x00000800)
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod1_int_mask                            (0x00000400)
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod3_int_mask                            (0x00000200)
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod2_int_mask                            (0x00000100)
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod1_int_mask                            (0x00000080)
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod3_int_mask                            (0x00000040)
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod2_int_mask                            (0x00000020)
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod1_int_mask                            (0x00000010)
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod3_int_mask                            (0x00000008)
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod2_int_mask                            (0x00000004)
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod1_int_mask                            (0x00000002)
#define  DC_SYS_DC_int_status_SYS2_write_data_mask                               (0x00000001)
#define  DC_SYS_DC_int_status_SYS2_rd_tag_mismatch_int(data)                     (0x00800000&((data)<<23))
#define  DC_SYS_DC_int_status_SYS2_err_seq_sa_odd_int(data)                      (0x00400000&((data)<<22))
#define  DC_SYS_DC_int_status_SYS2_err_seq_bl_zero_int(data)                     (0x00200000&((data)<<21))
#define  DC_SYS_DC_int_status_SYS2_err_seq_bl_odd_int(data)                      (0x00100000&((data)<<20))
#define  DC_SYS_DC_int_status_SYS2_err_blk_8x2_on_64_int(data)                   (0x00080000&((data)<<19))
#define  DC_SYS_DC_int_status_SYS2_err_blk_size_exceed_int(data)                 (0x00040000&((data)<<18))
#define  DC_SYS_DC_int_status_SYS2_err_blk_h_zero_int(data)                      (0x00020000&((data)<<17))
#define  DC_SYS_DC_int_status_SYS2_err_blk_w_zero_int(data)                      (0x00010000&((data)<<16))
#define  DC_SYS_DC_int_status_SYS2_err_blk_err_int(data)                         (0x00008000&((data)<<15))
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod3_int(data)                           (0x00001000&((data)<<12))
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod2_int(data)                           (0x00000800&((data)<<11))
#define  DC_SYS_DC_int_status_SYS2_mt_3_mod1_int(data)                           (0x00000400&((data)<<10))
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod3_int(data)                           (0x00000200&((data)<<9))
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod2_int(data)                           (0x00000100&((data)<<8))
#define  DC_SYS_DC_int_status_SYS2_mt_2_mod1_int(data)                           (0x00000080&((data)<<7))
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod3_int(data)                           (0x00000040&((data)<<6))
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod2_int(data)                           (0x00000020&((data)<<5))
#define  DC_SYS_DC_int_status_SYS2_mt_1_mod1_int(data)                           (0x00000010&((data)<<4))
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod3_int(data)                           (0x00000008&((data)<<3))
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod2_int(data)                           (0x00000004&((data)<<2))
#define  DC_SYS_DC_int_status_SYS2_mt_0_mod1_int(data)                           (0x00000002&((data)<<1))
#define  DC_SYS_DC_int_status_SYS2_write_data(data)                              (0x00000001&(data))
#define  DC_SYS_DC_int_status_SYS2_get_rd_tag_mismatch_int(data)                 ((0x00800000&(data))>>23)
#define  DC_SYS_DC_int_status_SYS2_get_err_seq_sa_odd_int(data)                  ((0x00400000&(data))>>22)
#define  DC_SYS_DC_int_status_SYS2_get_err_seq_bl_zero_int(data)                 ((0x00200000&(data))>>21)
#define  DC_SYS_DC_int_status_SYS2_get_err_seq_bl_odd_int(data)                  ((0x00100000&(data))>>20)
#define  DC_SYS_DC_int_status_SYS2_get_err_blk_8x2_on_64_int(data)               ((0x00080000&(data))>>19)
#define  DC_SYS_DC_int_status_SYS2_get_err_blk_size_exceed_int(data)             ((0x00040000&(data))>>18)
#define  DC_SYS_DC_int_status_SYS2_get_err_blk_h_zero_int(data)                  ((0x00020000&(data))>>17)
#define  DC_SYS_DC_int_status_SYS2_get_err_blk_w_zero_int(data)                  ((0x00010000&(data))>>16)
#define  DC_SYS_DC_int_status_SYS2_get_err_blk_err_int(data)                     ((0x00008000&(data))>>15)
#define  DC_SYS_DC_int_status_SYS2_get_mt_3_mod3_int(data)                       ((0x00001000&(data))>>12)
#define  DC_SYS_DC_int_status_SYS2_get_mt_3_mod2_int(data)                       ((0x00000800&(data))>>11)
#define  DC_SYS_DC_int_status_SYS2_get_mt_3_mod1_int(data)                       ((0x00000400&(data))>>10)
#define  DC_SYS_DC_int_status_SYS2_get_mt_2_mod3_int(data)                       ((0x00000200&(data))>>9)
#define  DC_SYS_DC_int_status_SYS2_get_mt_2_mod2_int(data)                       ((0x00000100&(data))>>8)
#define  DC_SYS_DC_int_status_SYS2_get_mt_2_mod1_int(data)                       ((0x00000080&(data))>>7)
#define  DC_SYS_DC_int_status_SYS2_get_mt_1_mod3_int(data)                       ((0x00000040&(data))>>6)
#define  DC_SYS_DC_int_status_SYS2_get_mt_1_mod2_int(data)                       ((0x00000020&(data))>>5)
#define  DC_SYS_DC_int_status_SYS2_get_mt_1_mod1_int(data)                       ((0x00000010&(data))>>4)
#define  DC_SYS_DC_int_status_SYS2_get_mt_0_mod3_int(data)                       ((0x00000008&(data))>>3)
#define  DC_SYS_DC_int_status_SYS2_get_mt_0_mod2_int(data)                       ((0x00000004&(data))>>2)
#define  DC_SYS_DC_int_status_SYS2_get_mt_0_mod1_int(data)                       ((0x00000002&(data))>>1)
#define  DC_SYS_DC_int_status_SYS2_get_write_data(data)                          (0x00000001&(data))

#define  DC_SYS_dc_sys3_mux                                                      0x18007480
#define  DC_SYS_dc_sys3_mux_reg_addr                                             "0xB8007480"
#define  DC_SYS_dc_sys3_mux_reg                                                  0xB8007480
#define  DC_SYS_dc_sys3_mux_inst_addr                                            "0x009B"
#define  set_DC_SYS_dc_sys3_mux_reg(data)                                        (*((volatile unsigned int*)DC_SYS_dc_sys3_mux_reg)=data)
#define  get_DC_SYS_dc_sys3_mux_reg                                              (*((volatile unsigned int*)DC_SYS_dc_sys3_mux_reg))
#define  DC_SYS_dc_sys3_mux_pre_tra_rd_cnt_shift                                 (20)
#define  DC_SYS_dc_sys3_mux_pre_tra_wr_cnt_shift                                 (8)
#define  DC_SYS_dc_sys3_mux_gpu_mux_shift                                        (4)
#define  DC_SYS_dc_sys3_mux_se2_mux_shift                                        (3)
#define  DC_SYS_dc_sys3_mux_tv_sb3_mux_shift                                     (2)
#define  DC_SYS_dc_sys3_mux_ve2_mux_shift                                        (1)
#define  DC_SYS_dc_sys3_mux_ve_mux_shift                                         (0)
#define  DC_SYS_dc_sys3_mux_pre_tra_rd_cnt_mask                                  (0x3FF00000)
#define  DC_SYS_dc_sys3_mux_pre_tra_wr_cnt_mask                                  (0x0003FF00)
#define  DC_SYS_dc_sys3_mux_gpu_mux_mask                                         (0x00000010)
#define  DC_SYS_dc_sys3_mux_se2_mux_mask                                         (0x00000008)
#define  DC_SYS_dc_sys3_mux_tv_sb3_mux_mask                                      (0x00000004)
#define  DC_SYS_dc_sys3_mux_ve2_mux_mask                                         (0x00000002)
#define  DC_SYS_dc_sys3_mux_ve_mux_mask                                          (0x00000001)
#define  DC_SYS_dc_sys3_mux_pre_tra_rd_cnt(data)                                 (0x3FF00000&((data)<<20))
#define  DC_SYS_dc_sys3_mux_pre_tra_wr_cnt(data)                                 (0x0003FF00&((data)<<8))
#define  DC_SYS_dc_sys3_mux_gpu_mux(data)                                        (0x00000010&((data)<<4))
#define  DC_SYS_dc_sys3_mux_se2_mux(data)                                        (0x00000008&((data)<<3))
#define  DC_SYS_dc_sys3_mux_tv_sb3_mux(data)                                     (0x00000004&((data)<<2))
#define  DC_SYS_dc_sys3_mux_ve2_mux(data)                                        (0x00000002&((data)<<1))
#define  DC_SYS_dc_sys3_mux_ve_mux(data)                                         (0x00000001&(data))
#define  DC_SYS_dc_sys3_mux_get_pre_tra_rd_cnt(data)                             ((0x3FF00000&(data))>>20)
#define  DC_SYS_dc_sys3_mux_get_pre_tra_wr_cnt(data)                             ((0x0003FF00&(data))>>8)
#define  DC_SYS_dc_sys3_mux_get_gpu_mux(data)                                    ((0x00000010&(data))>>4)
#define  DC_SYS_dc_sys3_mux_get_se2_mux(data)                                    ((0x00000008&(data))>>3)
#define  DC_SYS_dc_sys3_mux_get_tv_sb3_mux(data)                                 ((0x00000004&(data))>>2)
#define  DC_SYS_dc_sys3_mux_get_ve2_mux(data)                                    ((0x00000002&(data))>>1)
#define  DC_SYS_dc_sys3_mux_get_ve_mux(data)                                     (0x00000001&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0                                           0x18007490
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg_addr                                  "0xB8007490"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg                                       0xB8007490
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_inst_addr                                 "0x009C"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1                                           0x18007494
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_reg_addr                                  "0xB8007494"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_reg                                       0xB8007494
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_inst_addr                                 "0x009D"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_1_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2                                           0x18007498
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_reg_addr                                  "0xB8007498"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_reg                                       0xB8007498
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_inst_addr                                 "0x009E"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_2_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3                                           0x1800749C
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_reg_addr                                  "0xB800749C"
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_reg                                       0xB800749C
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_inst_addr                                 "0x009F"
#define  set_DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_ever_trap_shift                           (22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_module_id_shift                           (14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_ever_trap_mask                            (0x00400000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_module_id_mask                            (0x003FC000)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_addcmd_mask                               (0x00003FFF)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_ever_trap(data)                           (0x00400000&((data)<<22))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_module_id(data)                           (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_addcmd(data)                              (0x00003FFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_get_ever_trap(data)                       ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_get_module_id(data)                       ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MT_ADDCMD_HI_SYS3_3_get_addcmd(data)                          (0x00003FFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0                                           0x180074A0
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg_addr                                  "0xB80074A0"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg                                       0xB80074A0
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_inst_addr                                 "0x00A0"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1                                           0x180074A4
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_reg_addr                                  "0xB80074A4"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_reg                                       0xB80074A4
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_inst_addr                                 "0x00A1"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_1_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2                                           0x180074A8
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_reg_addr                                  "0xB80074A8"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_reg                                       0xB80074A8
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_inst_addr                                 "0x00A2"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_2_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3                                           0x180074AC
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_reg_addr                                  "0xB80074AC"
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_reg                                       0xB80074AC
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_inst_addr                                 "0x00A3"
#define  set_DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_addcmd_shift                              (0)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_addcmd_mask                               (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_addcmd(data)                              (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_LO_SYS3_3_get_addcmd(data)                          (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0                                           0x180074B0
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg_addr                                  "0xB80074B0"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg                                       0xB80074B0
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_inst_addr                                 "0x00A4"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1                                           0x180074B4
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_reg_addr                                  "0xB80074B4"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_reg                                       0xB80074B4
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_inst_addr                                 "0x00A5"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_1_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2                                           0x180074B8
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_reg_addr                                  "0xB80074B8"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_reg                                       0xB80074B8
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_inst_addr                                 "0x00A6"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_2_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3                                           0x180074BC
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_reg_addr                                  "0xB80074BC"
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_reg                                       0xB80074BC
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_inst_addr                                 "0x00A7"
#define  set_DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_reg(data)                             (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_reg)=data)
#define  get_DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_reg                                   (*((volatile unsigned int*)DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_reg))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_trap_seq_sa_shift                         (0)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_trap_seq_sa_mask                          (0xFFFFFFFF)
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_trap_seq_sa(data)                         (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MT_ADDCMD_SA_SYS3_3_get_trap_seq_sa(data)                     (0xFFFFFFFF&(data))

#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3                                             0x180074C0
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg_addr                                    "0xB80074C0"
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg                                         0xB80074C0
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_inst_addr                                   "0x00A8"
#define  set_DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg)=data)
#define  get_DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg                                     (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_error_cmd_ever_trap_shift                   (31)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_trap_case_shift                             (23)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_addcmd_hi_shift                             (0)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_error_cmd_ever_trap_mask                    (0x80000000)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_trap_case_mask                              (0x7F800000)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_addcmd_hi_mask                              (0x007FFFFF)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_error_cmd_ever_trap(data)                   (0x80000000&((data)<<31))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_trap_case(data)                             (0x7F800000&((data)<<23))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_addcmd_hi(data)                             (0x007FFFFF&(data))
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_get_error_cmd_ever_trap(data)               ((0x80000000&(data))>>31)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_get_trap_case(data)                         ((0x7F800000&(data))>>23)
#define  DC_SYS_DC_EC_ADDCMD_HI_SYS3_get_addcmd_hi(data)                         (0x007FFFFF&(data))

#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3                                             0x180074C4
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg_addr                                    "0xB80074C4"
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg                                         0xB80074C4
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_inst_addr                                   "0x00A9"
#define  set_DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg)=data)
#define  get_DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg                                     (*((volatile unsigned int*)DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg))
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_addcmd_lo_shift                             (0)
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_addcmd_lo_mask                              (0xFFFFFFFF)
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_addcmd_lo(data)                             (0xFFFFFFFF&(data))
#define  DC_SYS_DC_EC_ADDCMD_LO_SYS3_get_addcmd_lo(data)                         (0xFFFFFFFF&(data))

#define  DC_SYS_DC_int_enable_SYS3                                               0x180074CC
#define  DC_SYS_DC_int_enable_SYS3_reg_addr                                      "0xB80074CC"
#define  DC_SYS_DC_int_enable_SYS3_reg                                           0xB80074CC
#define  DC_SYS_DC_int_enable_SYS3_inst_addr                                     "0x00AA"
#define  set_DC_SYS_DC_int_enable_SYS3_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_int_enable_SYS3_reg)=data)
#define  get_DC_SYS_DC_int_enable_SYS3_reg                                       (*((volatile unsigned int*)DC_SYS_DC_int_enable_SYS3_reg))
#define  DC_SYS_DC_int_enable_SYS3_rd_tag_mismatch_int_en_shift                  (23)
#define  DC_SYS_DC_int_enable_SYS3_err_seq_sa_odd_int_en_shift                   (22)
#define  DC_SYS_DC_int_enable_SYS3_err_seq_bl_zero_int_en_shift                  (21)
#define  DC_SYS_DC_int_enable_SYS3_err_seq_bl_odd_int_en_shift                   (20)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_8x2_on_64_int_en_shift                (19)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_size_exceed_int_en_shift              (18)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_h_zero_int_en_shift                   (17)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_w_zero_int_en_shift                   (16)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_err_int_en_shift                      (15)
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod3_int_en_shift                        (12)
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod2_int_en_shift                        (11)
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod1_int_en_shift                        (10)
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod3_int_en_shift                        (9)
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod2_int_en_shift                        (8)
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod1_int_en_shift                        (7)
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod3_int_en_shift                        (6)
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod2_int_en_shift                        (5)
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod1_int_en_shift                        (4)
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod3_int_en_shift                        (3)
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod2_int_en_shift                        (2)
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod1_int_en_shift                        (1)
#define  DC_SYS_DC_int_enable_SYS3_write_data_shift                              (0)
#define  DC_SYS_DC_int_enable_SYS3_rd_tag_mismatch_int_en_mask                   (0x00800000)
#define  DC_SYS_DC_int_enable_SYS3_err_seq_sa_odd_int_en_mask                    (0x00400000)
#define  DC_SYS_DC_int_enable_SYS3_err_seq_bl_zero_int_en_mask                   (0x00200000)
#define  DC_SYS_DC_int_enable_SYS3_err_seq_bl_odd_int_en_mask                    (0x00100000)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_8x2_on_64_int_en_mask                 (0x00080000)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_size_exceed_int_en_mask               (0x00040000)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_h_zero_int_en_mask                    (0x00020000)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_w_zero_int_en_mask                    (0x00010000)
#define  DC_SYS_DC_int_enable_SYS3_err_blk_err_int_en_mask                       (0x00008000)
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod3_int_en_mask                         (0x00001000)
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod2_int_en_mask                         (0x00000800)
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod1_int_en_mask                         (0x00000400)
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod3_int_en_mask                         (0x00000200)
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod2_int_en_mask                         (0x00000100)
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod1_int_en_mask                         (0x00000080)
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod3_int_en_mask                         (0x00000040)
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod2_int_en_mask                         (0x00000020)
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod1_int_en_mask                         (0x00000010)
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod3_int_en_mask                         (0x00000008)
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod2_int_en_mask                         (0x00000004)
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod1_int_en_mask                         (0x00000002)
#define  DC_SYS_DC_int_enable_SYS3_write_data_mask                               (0x00000001)
#define  DC_SYS_DC_int_enable_SYS3_rd_tag_mismatch_int_en(data)                  (0x00800000&((data)<<23))
#define  DC_SYS_DC_int_enable_SYS3_err_seq_sa_odd_int_en(data)                   (0x00400000&((data)<<22))
#define  DC_SYS_DC_int_enable_SYS3_err_seq_bl_zero_int_en(data)                  (0x00200000&((data)<<21))
#define  DC_SYS_DC_int_enable_SYS3_err_seq_bl_odd_int_en(data)                   (0x00100000&((data)<<20))
#define  DC_SYS_DC_int_enable_SYS3_err_blk_8x2_on_64_int_en(data)                (0x00080000&((data)<<19))
#define  DC_SYS_DC_int_enable_SYS3_err_blk_size_exceed_int_en(data)              (0x00040000&((data)<<18))
#define  DC_SYS_DC_int_enable_SYS3_err_blk_h_zero_int_en(data)                   (0x00020000&((data)<<17))
#define  DC_SYS_DC_int_enable_SYS3_err_blk_w_zero_int_en(data)                   (0x00010000&((data)<<16))
#define  DC_SYS_DC_int_enable_SYS3_err_blk_err_int_en(data)                      (0x00008000&((data)<<15))
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod3_int_en(data)                        (0x00001000&((data)<<12))
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod2_int_en(data)                        (0x00000800&((data)<<11))
#define  DC_SYS_DC_int_enable_SYS3_mt_3_mod1_int_en(data)                        (0x00000400&((data)<<10))
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod3_int_en(data)                        (0x00000200&((data)<<9))
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod2_int_en(data)                        (0x00000100&((data)<<8))
#define  DC_SYS_DC_int_enable_SYS3_mt_2_mod1_int_en(data)                        (0x00000080&((data)<<7))
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod3_int_en(data)                        (0x00000040&((data)<<6))
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod2_int_en(data)                        (0x00000020&((data)<<5))
#define  DC_SYS_DC_int_enable_SYS3_mt_1_mod1_int_en(data)                        (0x00000010&((data)<<4))
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod3_int_en(data)                        (0x00000008&((data)<<3))
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod2_int_en(data)                        (0x00000004&((data)<<2))
#define  DC_SYS_DC_int_enable_SYS3_mt_0_mod1_int_en(data)                        (0x00000002&((data)<<1))
#define  DC_SYS_DC_int_enable_SYS3_write_data(data)                              (0x00000001&(data))
#define  DC_SYS_DC_int_enable_SYS3_get_rd_tag_mismatch_int_en(data)              ((0x00800000&(data))>>23)
#define  DC_SYS_DC_int_enable_SYS3_get_err_seq_sa_odd_int_en(data)               ((0x00400000&(data))>>22)
#define  DC_SYS_DC_int_enable_SYS3_get_err_seq_bl_zero_int_en(data)              ((0x00200000&(data))>>21)
#define  DC_SYS_DC_int_enable_SYS3_get_err_seq_bl_odd_int_en(data)               ((0x00100000&(data))>>20)
#define  DC_SYS_DC_int_enable_SYS3_get_err_blk_8x2_on_64_int_en(data)            ((0x00080000&(data))>>19)
#define  DC_SYS_DC_int_enable_SYS3_get_err_blk_size_exceed_int_en(data)          ((0x00040000&(data))>>18)
#define  DC_SYS_DC_int_enable_SYS3_get_err_blk_h_zero_int_en(data)               ((0x00020000&(data))>>17)
#define  DC_SYS_DC_int_enable_SYS3_get_err_blk_w_zero_int_en(data)               ((0x00010000&(data))>>16)
#define  DC_SYS_DC_int_enable_SYS3_get_err_blk_err_int_en(data)                  ((0x00008000&(data))>>15)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_3_mod3_int_en(data)                    ((0x00001000&(data))>>12)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_3_mod2_int_en(data)                    ((0x00000800&(data))>>11)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_3_mod1_int_en(data)                    ((0x00000400&(data))>>10)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_2_mod3_int_en(data)                    ((0x00000200&(data))>>9)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_2_mod2_int_en(data)                    ((0x00000100&(data))>>8)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_2_mod1_int_en(data)                    ((0x00000080&(data))>>7)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_1_mod3_int_en(data)                    ((0x00000040&(data))>>6)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_1_mod2_int_en(data)                    ((0x00000020&(data))>>5)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_1_mod1_int_en(data)                    ((0x00000010&(data))>>4)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_0_mod3_int_en(data)                    ((0x00000008&(data))>>3)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_0_mod2_int_en(data)                    ((0x00000004&(data))>>2)
#define  DC_SYS_DC_int_enable_SYS3_get_mt_0_mod1_int_en(data)                    ((0x00000002&(data))>>1)
#define  DC_SYS_DC_int_enable_SYS3_get_write_data(data)                          (0x00000001&(data))

#define  DC_SYS_DC_int_status_SYS3                                               0x180074D0
#define  DC_SYS_DC_int_status_SYS3_reg_addr                                      "0xB80074D0"
#define  DC_SYS_DC_int_status_SYS3_reg                                           0xB80074D0
#define  DC_SYS_DC_int_status_SYS3_inst_addr                                     "0x00AB"
#define  set_DC_SYS_DC_int_status_SYS3_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_int_status_SYS3_reg)=data)
#define  get_DC_SYS_DC_int_status_SYS3_reg                                       (*((volatile unsigned int*)DC_SYS_DC_int_status_SYS3_reg))
#define  DC_SYS_DC_int_status_SYS3_rd_tag_mismatch_int_shift                     (23)
#define  DC_SYS_DC_int_status_SYS3_err_seq_sa_odd_int_shift                      (22)
#define  DC_SYS_DC_int_status_SYS3_err_seq_bl_zero_int_shift                     (21)
#define  DC_SYS_DC_int_status_SYS3_err_seq_bl_odd_int_shift                      (20)
#define  DC_SYS_DC_int_status_SYS3_err_blk_8x2_on_64_int_shift                   (19)
#define  DC_SYS_DC_int_status_SYS3_err_blk_size_exceed_int_shift                 (18)
#define  DC_SYS_DC_int_status_SYS3_err_blk_h_zero_int_shift                      (17)
#define  DC_SYS_DC_int_status_SYS3_err_blk_w_zero_int_shift                      (16)
#define  DC_SYS_DC_int_status_SYS3_err_blk_err_int_shift                         (15)
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod3_int_shift                           (12)
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod2_int_shift                           (11)
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod1_int_shift                           (10)
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod3_int_shift                           (9)
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod2_int_shift                           (8)
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod1_int_shift                           (7)
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod3_int_shift                           (6)
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod2_int_shift                           (5)
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod1_int_shift                           (4)
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod3_int_shift                           (3)
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod2_int_shift                           (2)
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod1_int_shift                           (1)
#define  DC_SYS_DC_int_status_SYS3_write_data_shift                              (0)
#define  DC_SYS_DC_int_status_SYS3_rd_tag_mismatch_int_mask                      (0x00800000)
#define  DC_SYS_DC_int_status_SYS3_err_seq_sa_odd_int_mask                       (0x00400000)
#define  DC_SYS_DC_int_status_SYS3_err_seq_bl_zero_int_mask                      (0x00200000)
#define  DC_SYS_DC_int_status_SYS3_err_seq_bl_odd_int_mask                       (0x00100000)
#define  DC_SYS_DC_int_status_SYS3_err_blk_8x2_on_64_int_mask                    (0x00080000)
#define  DC_SYS_DC_int_status_SYS3_err_blk_size_exceed_int_mask                  (0x00040000)
#define  DC_SYS_DC_int_status_SYS3_err_blk_h_zero_int_mask                       (0x00020000)
#define  DC_SYS_DC_int_status_SYS3_err_blk_w_zero_int_mask                       (0x00010000)
#define  DC_SYS_DC_int_status_SYS3_err_blk_err_int_mask                          (0x00008000)
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod3_int_mask                            (0x00001000)
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod2_int_mask                            (0x00000800)
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod1_int_mask                            (0x00000400)
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod3_int_mask                            (0x00000200)
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod2_int_mask                            (0x00000100)
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod1_int_mask                            (0x00000080)
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod3_int_mask                            (0x00000040)
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod2_int_mask                            (0x00000020)
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod1_int_mask                            (0x00000010)
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod3_int_mask                            (0x00000008)
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod2_int_mask                            (0x00000004)
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod1_int_mask                            (0x00000002)
#define  DC_SYS_DC_int_status_SYS3_write_data_mask                               (0x00000001)
#define  DC_SYS_DC_int_status_SYS3_rd_tag_mismatch_int(data)                     (0x00800000&((data)<<23))
#define  DC_SYS_DC_int_status_SYS3_err_seq_sa_odd_int(data)                      (0x00400000&((data)<<22))
#define  DC_SYS_DC_int_status_SYS3_err_seq_bl_zero_int(data)                     (0x00200000&((data)<<21))
#define  DC_SYS_DC_int_status_SYS3_err_seq_bl_odd_int(data)                      (0x00100000&((data)<<20))
#define  DC_SYS_DC_int_status_SYS3_err_blk_8x2_on_64_int(data)                   (0x00080000&((data)<<19))
#define  DC_SYS_DC_int_status_SYS3_err_blk_size_exceed_int(data)                 (0x00040000&((data)<<18))
#define  DC_SYS_DC_int_status_SYS3_err_blk_h_zero_int(data)                      (0x00020000&((data)<<17))
#define  DC_SYS_DC_int_status_SYS3_err_blk_w_zero_int(data)                      (0x00010000&((data)<<16))
#define  DC_SYS_DC_int_status_SYS3_err_blk_err_int(data)                         (0x00008000&((data)<<15))
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod3_int(data)                           (0x00001000&((data)<<12))
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod2_int(data)                           (0x00000800&((data)<<11))
#define  DC_SYS_DC_int_status_SYS3_mt_3_mod1_int(data)                           (0x00000400&((data)<<10))
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod3_int(data)                           (0x00000200&((data)<<9))
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod2_int(data)                           (0x00000100&((data)<<8))
#define  DC_SYS_DC_int_status_SYS3_mt_2_mod1_int(data)                           (0x00000080&((data)<<7))
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod3_int(data)                           (0x00000040&((data)<<6))
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod2_int(data)                           (0x00000020&((data)<<5))
#define  DC_SYS_DC_int_status_SYS3_mt_1_mod1_int(data)                           (0x00000010&((data)<<4))
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod3_int(data)                           (0x00000008&((data)<<3))
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod2_int(data)                           (0x00000004&((data)<<2))
#define  DC_SYS_DC_int_status_SYS3_mt_0_mod1_int(data)                           (0x00000002&((data)<<1))
#define  DC_SYS_DC_int_status_SYS3_write_data(data)                              (0x00000001&(data))
#define  DC_SYS_DC_int_status_SYS3_get_rd_tag_mismatch_int(data)                 ((0x00800000&(data))>>23)
#define  DC_SYS_DC_int_status_SYS3_get_err_seq_sa_odd_int(data)                  ((0x00400000&(data))>>22)
#define  DC_SYS_DC_int_status_SYS3_get_err_seq_bl_zero_int(data)                 ((0x00200000&(data))>>21)
#define  DC_SYS_DC_int_status_SYS3_get_err_seq_bl_odd_int(data)                  ((0x00100000&(data))>>20)
#define  DC_SYS_DC_int_status_SYS3_get_err_blk_8x2_on_64_int(data)               ((0x00080000&(data))>>19)
#define  DC_SYS_DC_int_status_SYS3_get_err_blk_size_exceed_int(data)             ((0x00040000&(data))>>18)
#define  DC_SYS_DC_int_status_SYS3_get_err_blk_h_zero_int(data)                  ((0x00020000&(data))>>17)
#define  DC_SYS_DC_int_status_SYS3_get_err_blk_w_zero_int(data)                  ((0x00010000&(data))>>16)
#define  DC_SYS_DC_int_status_SYS3_get_err_blk_err_int(data)                     ((0x00008000&(data))>>15)
#define  DC_SYS_DC_int_status_SYS3_get_mt_3_mod3_int(data)                       ((0x00001000&(data))>>12)
#define  DC_SYS_DC_int_status_SYS3_get_mt_3_mod2_int(data)                       ((0x00000800&(data))>>11)
#define  DC_SYS_DC_int_status_SYS3_get_mt_3_mod1_int(data)                       ((0x00000400&(data))>>10)
#define  DC_SYS_DC_int_status_SYS3_get_mt_2_mod3_int(data)                       ((0x00000200&(data))>>9)
#define  DC_SYS_DC_int_status_SYS3_get_mt_2_mod2_int(data)                       ((0x00000100&(data))>>8)
#define  DC_SYS_DC_int_status_SYS3_get_mt_2_mod1_int(data)                       ((0x00000080&(data))>>7)
#define  DC_SYS_DC_int_status_SYS3_get_mt_1_mod3_int(data)                       ((0x00000040&(data))>>6)
#define  DC_SYS_DC_int_status_SYS3_get_mt_1_mod2_int(data)                       ((0x00000020&(data))>>5)
#define  DC_SYS_DC_int_status_SYS3_get_mt_1_mod1_int(data)                       ((0x00000010&(data))>>4)
#define  DC_SYS_DC_int_status_SYS3_get_mt_0_mod3_int(data)                       ((0x00000008&(data))>>3)
#define  DC_SYS_DC_int_status_SYS3_get_mt_0_mod2_int(data)                       ((0x00000004&(data))>>2)
#define  DC_SYS_DC_int_status_SYS3_get_mt_0_mod1_int(data)                       ((0x00000002&(data))>>1)
#define  DC_SYS_DC_int_status_SYS3_get_write_data(data)                          (0x00000001&(data))

#define  DC_SYS_DC_MTEX_TYPE_0                                                   0x18007600
#define  DC_SYS_DC_MTEX_TYPE_0_reg_addr                                          "0xB8007600"
#define  DC_SYS_DC_MTEX_TYPE_0_reg                                               0xB8007600
#define  DC_SYS_DC_MTEX_TYPE_0_inst_addr                                         "0x00AC"
#define  set_DC_SYS_DC_MTEX_TYPE_0_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_TYPE_0_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_0_reg))
#define  DC_SYS_DC_MTEX_TYPE_0_mem_type_shift                                    (30)
#define  DC_SYS_DC_MTEX_TYPE_0_mem_type_mask                                     (0xC0000000)
#define  DC_SYS_DC_MTEX_TYPE_0_mem_type(data)                                    (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_TYPE_0_get_mem_type(data)                                ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MTEX_TYPE_1                                                   0x18007604
#define  DC_SYS_DC_MTEX_TYPE_1_reg_addr                                          "0xB8007604"
#define  DC_SYS_DC_MTEX_TYPE_1_reg                                               0xB8007604
#define  DC_SYS_DC_MTEX_TYPE_1_inst_addr                                         "0x00AD"
#define  set_DC_SYS_DC_MTEX_TYPE_1_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_TYPE_1_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_1_reg))
#define  DC_SYS_DC_MTEX_TYPE_1_mem_type_shift                                    (30)
#define  DC_SYS_DC_MTEX_TYPE_1_mem_type_mask                                     (0xC0000000)
#define  DC_SYS_DC_MTEX_TYPE_1_mem_type(data)                                    (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_TYPE_1_get_mem_type(data)                                ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MTEX_TYPE_2                                                   0x18007608
#define  DC_SYS_DC_MTEX_TYPE_2_reg_addr                                          "0xB8007608"
#define  DC_SYS_DC_MTEX_TYPE_2_reg                                               0xB8007608
#define  DC_SYS_DC_MTEX_TYPE_2_inst_addr                                         "0x00AE"
#define  set_DC_SYS_DC_MTEX_TYPE_2_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_TYPE_2_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_2_reg))
#define  DC_SYS_DC_MTEX_TYPE_2_mem_type_shift                                    (30)
#define  DC_SYS_DC_MTEX_TYPE_2_mem_type_mask                                     (0xC0000000)
#define  DC_SYS_DC_MTEX_TYPE_2_mem_type(data)                                    (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_TYPE_2_get_mem_type(data)                                ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MTEX_TYPE_3                                                   0x1800760C
#define  DC_SYS_DC_MTEX_TYPE_3_reg_addr                                          "0xB800760C"
#define  DC_SYS_DC_MTEX_TYPE_3_reg                                               0xB800760C
#define  DC_SYS_DC_MTEX_TYPE_3_inst_addr                                         "0x00AF"
#define  set_DC_SYS_DC_MTEX_TYPE_3_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_TYPE_3_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_TYPE_3_reg))
#define  DC_SYS_DC_MTEX_TYPE_3_mem_type_shift                                    (30)
#define  DC_SYS_DC_MTEX_TYPE_3_mem_type_mask                                     (0xC0000000)
#define  DC_SYS_DC_MTEX_TYPE_3_mem_type(data)                                    (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_TYPE_3_get_mem_type(data)                                ((0xC0000000&(data))>>30)

#define  DC_SYS_DC_MTEX_SADDR_0                                                  0x18007610
#define  DC_SYS_DC_MTEX_SADDR_0_reg_addr                                         "0xB8007610"
#define  DC_SYS_DC_MTEX_SADDR_0_reg                                              0xB8007610
#define  DC_SYS_DC_MTEX_SADDR_0_inst_addr                                        "0x00B0"
#define  set_DC_SYS_DC_MTEX_SADDR_0_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_SADDR_0_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_0_reg))
#define  DC_SYS_DC_MTEX_SADDR_0_saddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_SADDR_0_saddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_SADDR_0_saddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_SADDR_0_get_saddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_SADDR_1                                                  0x18007614
#define  DC_SYS_DC_MTEX_SADDR_1_reg_addr                                         "0xB8007614"
#define  DC_SYS_DC_MTEX_SADDR_1_reg                                              0xB8007614
#define  DC_SYS_DC_MTEX_SADDR_1_inst_addr                                        "0x00B1"
#define  set_DC_SYS_DC_MTEX_SADDR_1_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_SADDR_1_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_1_reg))
#define  DC_SYS_DC_MTEX_SADDR_1_saddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_SADDR_1_saddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_SADDR_1_saddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_SADDR_1_get_saddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_SADDR_2                                                  0x18007618
#define  DC_SYS_DC_MTEX_SADDR_2_reg_addr                                         "0xB8007618"
#define  DC_SYS_DC_MTEX_SADDR_2_reg                                              0xB8007618
#define  DC_SYS_DC_MTEX_SADDR_2_inst_addr                                        "0x00B2"
#define  set_DC_SYS_DC_MTEX_SADDR_2_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_SADDR_2_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_2_reg))
#define  DC_SYS_DC_MTEX_SADDR_2_saddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_SADDR_2_saddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_SADDR_2_saddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_SADDR_2_get_saddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_SADDR_3                                                  0x1800761C
#define  DC_SYS_DC_MTEX_SADDR_3_reg_addr                                         "0xB800761C"
#define  DC_SYS_DC_MTEX_SADDR_3_reg                                              0xB800761C
#define  DC_SYS_DC_MTEX_SADDR_3_inst_addr                                        "0x00B3"
#define  set_DC_SYS_DC_MTEX_SADDR_3_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_SADDR_3_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_SADDR_3_reg))
#define  DC_SYS_DC_MTEX_SADDR_3_saddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_SADDR_3_saddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_SADDR_3_saddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_SADDR_3_get_saddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_EADDR_0                                                  0x18007620
#define  DC_SYS_DC_MTEX_EADDR_0_reg_addr                                         "0xB8007620"
#define  DC_SYS_DC_MTEX_EADDR_0_reg                                              0xB8007620
#define  DC_SYS_DC_MTEX_EADDR_0_inst_addr                                        "0x00B4"
#define  set_DC_SYS_DC_MTEX_EADDR_0_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_EADDR_0_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_0_reg))
#define  DC_SYS_DC_MTEX_EADDR_0_eaddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_EADDR_0_eaddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_EADDR_0_eaddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_EADDR_0_get_eaddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_EADDR_1                                                  0x18007624
#define  DC_SYS_DC_MTEX_EADDR_1_reg_addr                                         "0xB8007624"
#define  DC_SYS_DC_MTEX_EADDR_1_reg                                              0xB8007624
#define  DC_SYS_DC_MTEX_EADDR_1_inst_addr                                        "0x00B5"
#define  set_DC_SYS_DC_MTEX_EADDR_1_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_EADDR_1_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_1_reg))
#define  DC_SYS_DC_MTEX_EADDR_1_eaddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_EADDR_1_eaddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_EADDR_1_eaddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_EADDR_1_get_eaddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_EADDR_2                                                  0x18007628
#define  DC_SYS_DC_MTEX_EADDR_2_reg_addr                                         "0xB8007628"
#define  DC_SYS_DC_MTEX_EADDR_2_reg                                              0xB8007628
#define  DC_SYS_DC_MTEX_EADDR_2_inst_addr                                        "0x00B6"
#define  set_DC_SYS_DC_MTEX_EADDR_2_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_EADDR_2_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_2_reg))
#define  DC_SYS_DC_MTEX_EADDR_2_eaddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_EADDR_2_eaddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_EADDR_2_eaddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_EADDR_2_get_eaddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_EADDR_3                                                  0x1800762C
#define  DC_SYS_DC_MTEX_EADDR_3_reg_addr                                         "0xB800762C"
#define  DC_SYS_DC_MTEX_EADDR_3_reg                                              0xB800762C
#define  DC_SYS_DC_MTEX_EADDR_3_inst_addr                                        "0x00B7"
#define  set_DC_SYS_DC_MTEX_EADDR_3_reg(data)                                    (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_EADDR_3_reg                                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_EADDR_3_reg))
#define  DC_SYS_DC_MTEX_EADDR_3_eaddr_shift                                      (5)
#define  DC_SYS_DC_MTEX_EADDR_3_eaddr_mask                                       (0x7FFFFFE0)
#define  DC_SYS_DC_MTEX_EADDR_3_eaddr(data)                                      (0x7FFFFFE0&((data)<<5))
#define  DC_SYS_DC_MTEX_EADDR_3_get_eaddr(data)                                  ((0x7FFFFFE0&(data))>>5)

#define  DC_SYS_DC_MTEX_MODE_0                                                   0x18007640
#define  DC_SYS_DC_MTEX_MODE_0_reg_addr                                          "0xB8007640"
#define  DC_SYS_DC_MTEX_MODE_0_reg                                               0xB8007640
#define  DC_SYS_DC_MTEX_MODE_0_inst_addr                                         "0x00B8"
#define  set_DC_SYS_DC_MTEX_MODE_0_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_MODE_0_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_0_reg))
#define  DC_SYS_DC_MTEX_MODE_0_write_enable5_shift                               (2)
#define  DC_SYS_DC_MTEX_MODE_0_mode_shift                                        (0)
#define  DC_SYS_DC_MTEX_MODE_0_write_enable5_mask                                (0x00000004)
#define  DC_SYS_DC_MTEX_MODE_0_mode_mask                                         (0x00000003)
#define  DC_SYS_DC_MTEX_MODE_0_write_enable5(data)                               (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_MODE_0_mode(data)                                        (0x00000003&(data))
#define  DC_SYS_DC_MTEX_MODE_0_get_write_enable5(data)                           ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_MODE_0_get_mode(data)                                    (0x00000003&(data))

#define  DC_SYS_DC_MTEX_MODE_1                                                   0x18007644
#define  DC_SYS_DC_MTEX_MODE_1_reg_addr                                          "0xB8007644"
#define  DC_SYS_DC_MTEX_MODE_1_reg                                               0xB8007644
#define  DC_SYS_DC_MTEX_MODE_1_inst_addr                                         "0x00B9"
#define  set_DC_SYS_DC_MTEX_MODE_1_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_MODE_1_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_1_reg))
#define  DC_SYS_DC_MTEX_MODE_1_write_enable5_shift                               (2)
#define  DC_SYS_DC_MTEX_MODE_1_mode_shift                                        (0)
#define  DC_SYS_DC_MTEX_MODE_1_write_enable5_mask                                (0x00000004)
#define  DC_SYS_DC_MTEX_MODE_1_mode_mask                                         (0x00000003)
#define  DC_SYS_DC_MTEX_MODE_1_write_enable5(data)                               (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_MODE_1_mode(data)                                        (0x00000003&(data))
#define  DC_SYS_DC_MTEX_MODE_1_get_write_enable5(data)                           ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_MODE_1_get_mode(data)                                    (0x00000003&(data))

#define  DC_SYS_DC_MTEX_MODE_2                                                   0x18007648
#define  DC_SYS_DC_MTEX_MODE_2_reg_addr                                          "0xB8007648"
#define  DC_SYS_DC_MTEX_MODE_2_reg                                               0xB8007648
#define  DC_SYS_DC_MTEX_MODE_2_inst_addr                                         "0x00BA"
#define  set_DC_SYS_DC_MTEX_MODE_2_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_MODE_2_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_2_reg))
#define  DC_SYS_DC_MTEX_MODE_2_write_enable5_shift                               (2)
#define  DC_SYS_DC_MTEX_MODE_2_mode_shift                                        (0)
#define  DC_SYS_DC_MTEX_MODE_2_write_enable5_mask                                (0x00000004)
#define  DC_SYS_DC_MTEX_MODE_2_mode_mask                                         (0x00000003)
#define  DC_SYS_DC_MTEX_MODE_2_write_enable5(data)                               (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_MODE_2_mode(data)                                        (0x00000003&(data))
#define  DC_SYS_DC_MTEX_MODE_2_get_write_enable5(data)                           ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_MODE_2_get_mode(data)                                    (0x00000003&(data))

#define  DC_SYS_DC_MTEX_MODE_3                                                   0x1800764C
#define  DC_SYS_DC_MTEX_MODE_3_reg_addr                                          "0xB800764C"
#define  DC_SYS_DC_MTEX_MODE_3_reg                                               0xB800764C
#define  DC_SYS_DC_MTEX_MODE_3_inst_addr                                         "0x00BB"
#define  set_DC_SYS_DC_MTEX_MODE_3_reg(data)                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_MODE_3_reg                                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_MODE_3_reg))
#define  DC_SYS_DC_MTEX_MODE_3_write_enable5_shift                               (2)
#define  DC_SYS_DC_MTEX_MODE_3_mode_shift                                        (0)
#define  DC_SYS_DC_MTEX_MODE_3_write_enable5_mask                                (0x00000004)
#define  DC_SYS_DC_MTEX_MODE_3_mode_mask                                         (0x00000003)
#define  DC_SYS_DC_MTEX_MODE_3_write_enable5(data)                               (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_MODE_3_mode(data)                                        (0x00000003&(data))
#define  DC_SYS_DC_MTEX_MODE_3_get_write_enable5(data)                           ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_MODE_3_get_mode(data)                                    (0x00000003&(data))

#define  DC_SYS_DC_MTEX_TABLE0_0                                                 0x18007660
#define  DC_SYS_DC_MTEX_TABLE0_0_reg_addr                                        "0xB8007660"
#define  DC_SYS_DC_MTEX_TABLE0_0_reg                                             0xB8007660
#define  DC_SYS_DC_MTEX_TABLE0_0_inst_addr                                       "0x00BC"
#define  set_DC_SYS_DC_MTEX_TABLE0_0_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE0_0_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_0_reg))
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_0_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_1_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_2_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_3_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_0_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_1_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_2_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_3_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_0(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_1(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_2(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE0_0_module_id_3(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE0_0_get_module_id_0(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE0_0_get_module_id_1(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE0_0_get_module_id_2(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE0_0_get_module_id_3(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE0_1                                                 0x18007664
#define  DC_SYS_DC_MTEX_TABLE0_1_reg_addr                                        "0xB8007664"
#define  DC_SYS_DC_MTEX_TABLE0_1_reg                                             0xB8007664
#define  DC_SYS_DC_MTEX_TABLE0_1_inst_addr                                       "0x00BD"
#define  set_DC_SYS_DC_MTEX_TABLE0_1_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE0_1_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_1_reg))
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_0_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_1_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_2_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_3_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_0_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_1_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_2_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_3_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_0(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_1(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_2(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE0_1_module_id_3(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE0_1_get_module_id_0(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE0_1_get_module_id_1(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE0_1_get_module_id_2(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE0_1_get_module_id_3(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE0_2                                                 0x18007668
#define  DC_SYS_DC_MTEX_TABLE0_2_reg_addr                                        "0xB8007668"
#define  DC_SYS_DC_MTEX_TABLE0_2_reg                                             0xB8007668
#define  DC_SYS_DC_MTEX_TABLE0_2_inst_addr                                       "0x00BE"
#define  set_DC_SYS_DC_MTEX_TABLE0_2_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE0_2_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_2_reg))
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_0_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_1_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_2_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_3_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_0_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_1_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_2_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_3_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_0(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_1(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_2(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE0_2_module_id_3(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE0_2_get_module_id_0(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE0_2_get_module_id_1(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE0_2_get_module_id_2(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE0_2_get_module_id_3(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE0_3                                                 0x1800766C
#define  DC_SYS_DC_MTEX_TABLE0_3_reg_addr                                        "0xB800766C"
#define  DC_SYS_DC_MTEX_TABLE0_3_reg                                             0xB800766C
#define  DC_SYS_DC_MTEX_TABLE0_3_inst_addr                                       "0x00BF"
#define  set_DC_SYS_DC_MTEX_TABLE0_3_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE0_3_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE0_3_reg))
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_0_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_1_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_2_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_3_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_0_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_1_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_2_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_3_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_0(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_1(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_2(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE0_3_module_id_3(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE0_3_get_module_id_0(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE0_3_get_module_id_1(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE0_3_get_module_id_2(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE0_3_get_module_id_3(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE1_0                                                 0x18007670
#define  DC_SYS_DC_MTEX_TABLE1_0_reg_addr                                        "0xB8007670"
#define  DC_SYS_DC_MTEX_TABLE1_0_reg                                             0xB8007670
#define  DC_SYS_DC_MTEX_TABLE1_0_inst_addr                                       "0x00C0"
#define  set_DC_SYS_DC_MTEX_TABLE1_0_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE1_0_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_0_reg))
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_4_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_5_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_6_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_7_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_4_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_5_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_6_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_7_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_4(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_5(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_6(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE1_0_module_id_7(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE1_0_get_module_id_4(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE1_0_get_module_id_5(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE1_0_get_module_id_6(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE1_0_get_module_id_7(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE1_1                                                 0x18007674
#define  DC_SYS_DC_MTEX_TABLE1_1_reg_addr                                        "0xB8007674"
#define  DC_SYS_DC_MTEX_TABLE1_1_reg                                             0xB8007674
#define  DC_SYS_DC_MTEX_TABLE1_1_inst_addr                                       "0x00C1"
#define  set_DC_SYS_DC_MTEX_TABLE1_1_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE1_1_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_1_reg))
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_4_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_5_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_6_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_7_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_4_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_5_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_6_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_7_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_4(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_5(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_6(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE1_1_module_id_7(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE1_1_get_module_id_4(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE1_1_get_module_id_5(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE1_1_get_module_id_6(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE1_1_get_module_id_7(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE1_2                                                 0x18007678
#define  DC_SYS_DC_MTEX_TABLE1_2_reg_addr                                        "0xB8007678"
#define  DC_SYS_DC_MTEX_TABLE1_2_reg                                             0xB8007678
#define  DC_SYS_DC_MTEX_TABLE1_2_inst_addr                                       "0x00C2"
#define  set_DC_SYS_DC_MTEX_TABLE1_2_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE1_2_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_2_reg))
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_4_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_5_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_6_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_7_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_4_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_5_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_6_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_7_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_4(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_5(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_6(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE1_2_module_id_7(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE1_2_get_module_id_4(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE1_2_get_module_id_5(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE1_2_get_module_id_6(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE1_2_get_module_id_7(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_TABLE1_3                                                 0x1800767C
#define  DC_SYS_DC_MTEX_TABLE1_3_reg_addr                                        "0xB800767C"
#define  DC_SYS_DC_MTEX_TABLE1_3_reg                                             0xB800767C
#define  DC_SYS_DC_MTEX_TABLE1_3_inst_addr                                       "0x00C3"
#define  set_DC_SYS_DC_MTEX_TABLE1_3_reg(data)                                   (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_TABLE1_3_reg                                         (*((volatile unsigned int*)DC_SYS_DC_MTEX_TABLE1_3_reg))
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_4_shift                               (24)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_5_shift                               (16)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_6_shift                               (8)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_7_shift                               (0)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_4_mask                                (0xFF000000)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_5_mask                                (0x00FF0000)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_6_mask                                (0x0000FF00)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_7_mask                                (0x000000FF)
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_4(data)                               (0xFF000000&((data)<<24))
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_5(data)                               (0x00FF0000&((data)<<16))
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_6(data)                               (0x0000FF00&((data)<<8))
#define  DC_SYS_DC_MTEX_TABLE1_3_module_id_7(data)                               (0x000000FF&(data))
#define  DC_SYS_DC_MTEX_TABLE1_3_get_module_id_4(data)                           ((0xFF000000&(data))>>24)
#define  DC_SYS_DC_MTEX_TABLE1_3_get_module_id_5(data)                           ((0x00FF0000&(data))>>16)
#define  DC_SYS_DC_MTEX_TABLE1_3_get_module_id_6(data)                           ((0x0000FF00&(data))>>8)
#define  DC_SYS_DC_MTEX_TABLE1_3_get_module_id_7(data)                           (0x000000FF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0                                             0x18007680
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg_addr                                    "0xB8007680"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg                                         0xB8007680
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_inst_addr                                   "0x00C4"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_0_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_1_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_2_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_3_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_ever_trap_shift                             (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_module_id_shift                             (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_addcmd_shift                                (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_0_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_1_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_2_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_3_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_ever_trap_mask                              (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_module_id_mask                              (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_addcmd_mask                                 (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_0(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_1(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_2(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_access_type_3(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_ever_trap(data)                             (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_module_id(data)                             (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_addcmd(data)                                (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_access_type_0(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_access_type_1(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_access_type_2(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_access_type_3(data)                     ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_ever_trap(data)                         ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_module_id(data)                         ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_0_get_addcmd(data)                            (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1                                             0x18007684
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_reg_addr                                    "0xB8007684"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_reg                                         0xB8007684
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_inst_addr                                   "0x00C5"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_1_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_1_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_0_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_1_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_2_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_3_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_ever_trap_shift                             (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_module_id_shift                             (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_addcmd_shift                                (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_0_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_1_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_2_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_3_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_ever_trap_mask                              (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_module_id_mask                              (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_addcmd_mask                                 (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_0(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_1(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_2(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_access_type_3(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_ever_trap(data)                             (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_module_id(data)                             (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_addcmd(data)                                (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_access_type_0(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_access_type_1(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_access_type_2(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_access_type_3(data)                     ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_ever_trap(data)                         ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_module_id(data)                         ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_1_get_addcmd(data)                            (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2                                             0x18007688
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_reg_addr                                    "0xB8007688"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_reg                                         0xB8007688
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_inst_addr                                   "0x00C6"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_2_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_2_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_0_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_1_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_2_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_3_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_ever_trap_shift                             (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_module_id_shift                             (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_addcmd_shift                                (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_0_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_1_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_2_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_3_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_ever_trap_mask                              (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_module_id_mask                              (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_addcmd_mask                                 (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_0(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_1(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_2(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_access_type_3(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_ever_trap(data)                             (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_module_id(data)                             (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_addcmd(data)                                (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_access_type_0(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_access_type_1(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_access_type_2(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_access_type_3(data)                     ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_ever_trap(data)                         ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_module_id(data)                         ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_2_get_addcmd(data)                            (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3                                             0x1800768C
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_reg_addr                                    "0xB800768C"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_reg                                         0xB800768C
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_inst_addr                                   "0x00C7"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_3_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_3_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_0_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_1_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_2_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_3_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_ever_trap_shift                             (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_module_id_shift                             (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_addcmd_shift                                (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_0_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_1_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_2_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_3_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_ever_trap_mask                              (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_module_id_mask                              (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_addcmd_mask                                 (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_0(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_1(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_2(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_access_type_3(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_ever_trap(data)                             (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_module_id(data)                             (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_addcmd(data)                                (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_access_type_0(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_access_type_1(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_access_type_2(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_access_type_3(data)                     ((0x03000000&(data))>>24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_ever_trap(data)                         ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_module_id(data)                         ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_3_get_addcmd(data)                            (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0                                             0x18007690
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg_addr                                    "0xB8007690"
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg                                         0xB8007690
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_inst_addr                                   "0x00C8"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_4_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_5_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_6_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_7_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_4_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_5_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_6_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_7_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_4(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_5(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_6(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_access_type_7(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_get_access_type_4(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_get_access_type_5(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_get_access_type_6(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_0_get_access_type_7(data)                     ((0x03000000&(data))>>24)

#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1                                             0x18007694
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_reg_addr                                    "0xB8007694"
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_reg                                         0xB8007694
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_inst_addr                                   "0x00C9"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI1_1_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI1_1_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_4_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_5_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_6_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_7_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_4_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_5_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_6_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_7_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_4(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_5(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_6(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_access_type_7(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_get_access_type_4(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_get_access_type_5(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_get_access_type_6(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_1_get_access_type_7(data)                     ((0x03000000&(data))>>24)

#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2                                             0x18007698
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_reg_addr                                    "0xB8007698"
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_reg                                         0xB8007698
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_inst_addr                                   "0x00CA"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI1_2_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI1_2_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_4_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_5_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_6_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_7_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_4_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_5_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_6_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_7_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_4(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_5(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_6(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_access_type_7(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_get_access_type_4(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_get_access_type_5(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_get_access_type_6(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_2_get_access_type_7(data)                     ((0x03000000&(data))>>24)

#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3                                             0x1800769C
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_reg_addr                                    "0xB800769C"
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_reg                                         0xB800769C
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_inst_addr                                   "0x00CB"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI1_3_reg(data)                               (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI1_3_reg                                     (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI1_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_4_shift                         (30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_5_shift                         (28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_6_shift                         (26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_7_shift                         (24)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_4_mask                          (0xC0000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_5_mask                          (0x30000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_6_mask                          (0x0C000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_7_mask                          (0x03000000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_4(data)                         (0xC0000000&((data)<<30))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_5(data)                         (0x30000000&((data)<<28))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_6(data)                         (0x0C000000&((data)<<26))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_access_type_7(data)                         (0x03000000&((data)<<24))
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_get_access_type_4(data)                     ((0xC0000000&(data))>>30)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_get_access_type_5(data)                     ((0x30000000&(data))>>28)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_get_access_type_6(data)                     ((0x0C000000&(data))>>26)
#define  DC_SYS_DC_MTEX_ADDCMD_HI1_3_get_access_type_7(data)                     ((0x03000000&(data))>>24)

#define  DC_SYS_DC_MTEX_ADDCMD_LO_0                                              0x180076A0
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_reg_addr                                     "0xB80076A0"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_reg                                          0xB80076A0
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_inst_addr                                    "0x00CC"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_0_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_0_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_addcmd_shift                                 (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_addcmd_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_addcmd(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_0_get_addcmd(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_1                                              0x180076A4
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_reg_addr                                     "0xB80076A4"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_reg                                          0xB80076A4
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_inst_addr                                    "0x00CD"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_1_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_1_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_addcmd_shift                                 (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_addcmd_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_addcmd(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_1_get_addcmd(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_2                                              0x180076A8
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_reg_addr                                     "0xB80076A8"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_reg                                          0xB80076A8
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_inst_addr                                    "0x00CE"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_2_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_2_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_addcmd_shift                                 (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_addcmd_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_addcmd(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_2_get_addcmd(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_3                                              0x180076AC
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_reg_addr                                     "0xB80076AC"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_reg                                          0xB80076AC
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_inst_addr                                    "0x00CF"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_3_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_3_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_addcmd_shift                                 (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_addcmd_mask                                  (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_addcmd(data)                                 (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_3_get_addcmd(data)                             (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_0                                              0x180076B0
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_reg_addr                                     "0xB80076B0"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_reg                                          0xB80076B0
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_inst_addr                                    "0x00D0"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_0_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_0_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_trap_seq_sa_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_trap_seq_sa_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_trap_seq_sa(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_0_get_trap_seq_sa(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_1                                              0x180076B4
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_reg_addr                                     "0xB80076B4"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_reg                                          0xB80076B4
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_inst_addr                                    "0x00D1"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_1_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_1_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_trap_seq_sa_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_trap_seq_sa_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_trap_seq_sa(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_1_get_trap_seq_sa(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_2                                              0x180076B8
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_reg_addr                                     "0xB80076B8"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_reg                                          0xB80076B8
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_inst_addr                                    "0x00D2"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_2_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_2_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_trap_seq_sa_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_trap_seq_sa_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_trap_seq_sa(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_2_get_trap_seq_sa(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_3                                              0x180076BC
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_reg_addr                                     "0xB80076BC"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_reg                                          0xB80076BC
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_inst_addr                                    "0x00D3"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_3_reg(data)                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_3_reg                                      (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_trap_seq_sa_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_trap_seq_sa_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_trap_seq_sa(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_3_get_trap_seq_sa(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0                                        0x180076C0
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg_addr                               "0xB80076C0"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg                                    0xB80076C0
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_inst_addr                              "0x00D4"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1                                        0x180076C4
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_reg_addr                               "0xB80076C4"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_reg                                    0xB80076C4
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_inst_addr                              "0x00D5"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_1_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2                                        0x180076C8
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_reg_addr                               "0xB80076C8"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_reg                                    0xB80076C8
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_inst_addr                              "0x00D6"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_2_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3                                        0x180076CC
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_reg_addr                               "0xB80076CC"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_reg                                    0xB80076CC
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_inst_addr                              "0x00D7"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_3_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0                                         0x180076D0
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg_addr                                "0xB80076D0"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg                                     0xB80076D0
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_inst_addr                               "0x00D8"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1                                         0x180076D4
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_reg_addr                                "0xB80076D4"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_reg                                     0xB80076D4
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_inst_addr                               "0x00D9"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_1_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2                                         0x180076D8
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_reg_addr                                "0xB80076D8"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_reg                                     0xB80076D8
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_inst_addr                               "0x00DA"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_2_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3                                         0x180076DC
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_reg_addr                                "0xB80076DC"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_reg                                     0xB80076DC
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_inst_addr                               "0x00DB"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_3_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0                                         0x180076E0
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg_addr                                "0xB80076E0"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg                                     0xB80076E0
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_inst_addr                               "0x00DC"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1                                         0x180076E4
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_reg_addr                                "0xB80076E4"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_reg                                     0xB80076E4
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_inst_addr                               "0x00DD"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_1_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2                                         0x180076E8
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_reg_addr                                "0xB80076E8"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_reg                                     0xB80076E8
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_inst_addr                               "0x00DE"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_2_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3                                         0x180076EC
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_reg_addr                                "0xB80076EC"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_reg                                     0xB80076EC
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_inst_addr                               "0x00DF"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_3_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0                                        0x180076F0
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg_addr                               "0xB80076F0"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg                                    0xB80076F0
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_inst_addr                              "0x00E0"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1                                        0x180076F4
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_reg_addr                               "0xB80076F4"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_reg                                    0xB80076F4
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_inst_addr                              "0x00E1"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_1_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2                                        0x180076F8
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_reg_addr                               "0xB80076F8"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_reg                                    0xB80076F8
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_inst_addr                              "0x00E2"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_2_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3                                        0x180076FC
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_reg_addr                               "0xB80076FC"
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_reg                                    0xB80076FC
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_inst_addr                              "0x00E3"
#define  set_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_reg(data)                          (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_reg                                (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_ever_trap_shift                        (22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_module_id_shift                        (14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_addcmd_shift                           (0)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_ever_trap_mask                         (0x00400000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_module_id_mask                         (0x003FC000)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_addcmd_mask                            (0x00003FFF)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_ever_trap(data)                        (0x00400000&((data)<<22))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_module_id(data)                        (0x003FC000&((data)<<14))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_addcmd(data)                           (0x00003FFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_get_ever_trap(data)                    ((0x00400000&(data))>>22)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_get_module_id(data)                    ((0x003FC000&(data))>>14)
#define  DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_3_get_addcmd(data)                       (0x00003FFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0                                         0x18007700
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg_addr                                "0xB8007700"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg                                     0xB8007700
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_inst_addr                               "0x00E4"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1                                         0x18007704
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_reg_addr                                "0xB8007704"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_reg                                     0xB8007704
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_inst_addr                               "0x00E5"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_1_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2                                         0x18007708
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_reg_addr                                "0xB8007708"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_reg                                     0xB8007708
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_inst_addr                               "0x00E6"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_2_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3                                         0x1800770C
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_reg_addr                                "0xB800770C"
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_reg                                     0xB800770C
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_inst_addr                               "0x00E7"
#define  set_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_addcmd_shift                            (0)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_addcmd_mask                             (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_addcmd(data)                            (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_3_get_addcmd(data)                        (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0                                         0x18007710
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg_addr                                "0xB8007710"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg                                     0xB8007710
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_inst_addr                               "0x00E8"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1                                         0x18007714
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_reg_addr                                "0xB8007714"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_reg                                     0xB8007714
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_inst_addr                               "0x00E9"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_1_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2                                         0x18007718
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_reg_addr                                "0xB8007718"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_reg                                     0xB8007718
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_inst_addr                               "0x00EA"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_2_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3                                         0x1800771C
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_reg_addr                                "0xB800771C"
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_reg                                     0xB800771C
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_inst_addr                               "0x00EB"
#define  set_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_reg(data)                           (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_reg)=data)
#define  get_DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_reg                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_reg))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_trap_seq_sa_shift                       (0)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_trap_seq_sa_mask                        (0xFFFFFFFF)
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_trap_seq_sa(data)                       (0xFFFFFFFF&(data))
#define  DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_3_get_trap_seq_sa(data)                   (0xFFFFFFFF&(data))

#define  DC_SYS_DC_MTEX_int_enable                                               0x18007720
#define  DC_SYS_DC_MTEX_int_enable_reg_addr                                      "0xB8007720"
#define  DC_SYS_DC_MTEX_int_enable_reg                                           0xB8007720
#define  DC_SYS_DC_MTEX_int_enable_inst_addr                                     "0x00EC"
#define  set_DC_SYS_DC_MTEX_int_enable_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_enable_reg)=data)
#define  get_DC_SYS_DC_MTEX_int_enable_reg                                       (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_enable_reg))
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod3_int_en_shift                        (12)
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod2_int_en_shift                        (11)
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod1_int_en_shift                        (10)
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod3_int_en_shift                        (9)
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod2_int_en_shift                        (8)
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod1_int_en_shift                        (7)
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod3_int_en_shift                        (6)
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod2_int_en_shift                        (5)
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod1_int_en_shift                        (4)
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod3_int_en_shift                        (3)
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod2_int_en_shift                        (2)
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod1_int_en_shift                        (1)
#define  DC_SYS_DC_MTEX_int_enable_write_data_shift                              (0)
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod3_int_en_mask                         (0x00001000)
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod2_int_en_mask                         (0x00000800)
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod1_int_en_mask                         (0x00000400)
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod3_int_en_mask                         (0x00000200)
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod2_int_en_mask                         (0x00000100)
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod1_int_en_mask                         (0x00000080)
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod3_int_en_mask                         (0x00000040)
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod2_int_en_mask                         (0x00000020)
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod1_int_en_mask                         (0x00000010)
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod3_int_en_mask                         (0x00000008)
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod2_int_en_mask                         (0x00000004)
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod1_int_en_mask                         (0x00000002)
#define  DC_SYS_DC_MTEX_int_enable_write_data_mask                               (0x00000001)
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod3_int_en(data)                        (0x00001000&((data)<<12))
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod2_int_en(data)                        (0x00000800&((data)<<11))
#define  DC_SYS_DC_MTEX_int_enable_mt_3_mod1_int_en(data)                        (0x00000400&((data)<<10))
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod3_int_en(data)                        (0x00000200&((data)<<9))
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod2_int_en(data)                        (0x00000100&((data)<<8))
#define  DC_SYS_DC_MTEX_int_enable_mt_2_mod1_int_en(data)                        (0x00000080&((data)<<7))
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod3_int_en(data)                        (0x00000040&((data)<<6))
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod2_int_en(data)                        (0x00000020&((data)<<5))
#define  DC_SYS_DC_MTEX_int_enable_mt_1_mod1_int_en(data)                        (0x00000010&((data)<<4))
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod3_int_en(data)                        (0x00000008&((data)<<3))
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod2_int_en(data)                        (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_int_enable_mt_0_mod1_int_en(data)                        (0x00000002&((data)<<1))
#define  DC_SYS_DC_MTEX_int_enable_write_data(data)                              (0x00000001&(data))
#define  DC_SYS_DC_MTEX_int_enable_get_mt_3_mod3_int_en(data)                    ((0x00001000&(data))>>12)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_3_mod2_int_en(data)                    ((0x00000800&(data))>>11)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_3_mod1_int_en(data)                    ((0x00000400&(data))>>10)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_2_mod3_int_en(data)                    ((0x00000200&(data))>>9)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_2_mod2_int_en(data)                    ((0x00000100&(data))>>8)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_2_mod1_int_en(data)                    ((0x00000080&(data))>>7)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_1_mod3_int_en(data)                    ((0x00000040&(data))>>6)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_1_mod2_int_en(data)                    ((0x00000020&(data))>>5)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_1_mod1_int_en(data)                    ((0x00000010&(data))>>4)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_0_mod3_int_en(data)                    ((0x00000008&(data))>>3)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_0_mod2_int_en(data)                    ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_int_enable_get_mt_0_mod1_int_en(data)                    ((0x00000002&(data))>>1)
#define  DC_SYS_DC_MTEX_int_enable_get_write_data(data)                          (0x00000001&(data))

#define  DC_SYS_DC_MTEX_int_status                                               0x18007724
#define  DC_SYS_DC_MTEX_int_status_reg_addr                                      "0xB8007724"
#define  DC_SYS_DC_MTEX_int_status_reg                                           0xB8007724
#define  DC_SYS_DC_MTEX_int_status_inst_addr                                     "0x00ED"
#define  set_DC_SYS_DC_MTEX_int_status_reg(data)                                 (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_status_reg)=data)
#define  get_DC_SYS_DC_MTEX_int_status_reg                                       (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_status_reg))
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod3_int_shift                           (12)
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod2_int_shift                           (11)
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod1_int_shift                           (10)
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod3_int_shift                           (9)
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod2_int_shift                           (8)
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod1_int_shift                           (7)
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod3_int_shift                           (6)
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod2_int_shift                           (5)
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod1_int_shift                           (4)
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod3_int_shift                           (3)
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod2_int_shift                           (2)
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod1_int_shift                           (1)
#define  DC_SYS_DC_MTEX_int_status_write_data_shift                              (0)
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod3_int_mask                            (0x00001000)
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod2_int_mask                            (0x00000800)
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod1_int_mask                            (0x00000400)
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod3_int_mask                            (0x00000200)
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod2_int_mask                            (0x00000100)
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod1_int_mask                            (0x00000080)
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod3_int_mask                            (0x00000040)
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod2_int_mask                            (0x00000020)
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod1_int_mask                            (0x00000010)
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod3_int_mask                            (0x00000008)
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod2_int_mask                            (0x00000004)
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod1_int_mask                            (0x00000002)
#define  DC_SYS_DC_MTEX_int_status_write_data_mask                               (0x00000001)
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod3_int(data)                           (0x00001000&((data)<<12))
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod2_int(data)                           (0x00000800&((data)<<11))
#define  DC_SYS_DC_MTEX_int_status_mt_3_mod1_int(data)                           (0x00000400&((data)<<10))
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod3_int(data)                           (0x00000200&((data)<<9))
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod2_int(data)                           (0x00000100&((data)<<8))
#define  DC_SYS_DC_MTEX_int_status_mt_2_mod1_int(data)                           (0x00000080&((data)<<7))
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod3_int(data)                           (0x00000040&((data)<<6))
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod2_int(data)                           (0x00000020&((data)<<5))
#define  DC_SYS_DC_MTEX_int_status_mt_1_mod1_int(data)                           (0x00000010&((data)<<4))
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod3_int(data)                           (0x00000008&((data)<<3))
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod2_int(data)                           (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_int_status_mt_0_mod1_int(data)                           (0x00000002&((data)<<1))
#define  DC_SYS_DC_MTEX_int_status_write_data(data)                              (0x00000001&(data))
#define  DC_SYS_DC_MTEX_int_status_get_mt_3_mod3_int(data)                       ((0x00001000&(data))>>12)
#define  DC_SYS_DC_MTEX_int_status_get_mt_3_mod2_int(data)                       ((0x00000800&(data))>>11)
#define  DC_SYS_DC_MTEX_int_status_get_mt_3_mod1_int(data)                       ((0x00000400&(data))>>10)
#define  DC_SYS_DC_MTEX_int_status_get_mt_2_mod3_int(data)                       ((0x00000200&(data))>>9)
#define  DC_SYS_DC_MTEX_int_status_get_mt_2_mod2_int(data)                       ((0x00000100&(data))>>8)
#define  DC_SYS_DC_MTEX_int_status_get_mt_2_mod1_int(data)                       ((0x00000080&(data))>>7)
#define  DC_SYS_DC_MTEX_int_status_get_mt_1_mod3_int(data)                       ((0x00000040&(data))>>6)
#define  DC_SYS_DC_MTEX_int_status_get_mt_1_mod2_int(data)                       ((0x00000020&(data))>>5)
#define  DC_SYS_DC_MTEX_int_status_get_mt_1_mod1_int(data)                       ((0x00000010&(data))>>4)
#define  DC_SYS_DC_MTEX_int_status_get_mt_0_mod3_int(data)                       ((0x00000008&(data))>>3)
#define  DC_SYS_DC_MTEX_int_status_get_mt_0_mod2_int(data)                       ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_int_status_get_mt_0_mod1_int(data)                       ((0x00000002&(data))>>1)
#define  DC_SYS_DC_MTEX_int_status_get_write_data(data)                          (0x00000001&(data))

#define  DC_SYS_DC_MTEX_int_enable_SYS2                                          0x18007730
#define  DC_SYS_DC_MTEX_int_enable_SYS2_reg_addr                                 "0xB8007730"
#define  DC_SYS_DC_MTEX_int_enable_SYS2_reg                                      0xB8007730
#define  DC_SYS_DC_MTEX_int_enable_SYS2_inst_addr                                "0x00EE"
#define  set_DC_SYS_DC_MTEX_int_enable_SYS2_reg(data)                            (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_enable_SYS2_reg)=data)
#define  get_DC_SYS_DC_MTEX_int_enable_SYS2_reg                                  (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_enable_SYS2_reg))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod3_int_en_shift                   (12)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod2_int_en_shift                   (11)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod1_int_en_shift                   (10)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod3_int_en_shift                   (9)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod2_int_en_shift                   (8)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod1_int_en_shift                   (7)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod3_int_en_shift                   (6)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod2_int_en_shift                   (5)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod1_int_en_shift                   (4)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod3_int_en_shift                   (3)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod2_int_en_shift                   (2)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod1_int_en_shift                   (1)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_write_data_shift                         (0)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod3_int_en_mask                    (0x00001000)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod2_int_en_mask                    (0x00000800)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod1_int_en_mask                    (0x00000400)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod3_int_en_mask                    (0x00000200)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod2_int_en_mask                    (0x00000100)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod1_int_en_mask                    (0x00000080)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod3_int_en_mask                    (0x00000040)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod2_int_en_mask                    (0x00000020)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod1_int_en_mask                    (0x00000010)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod3_int_en_mask                    (0x00000008)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod2_int_en_mask                    (0x00000004)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod1_int_en_mask                    (0x00000002)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_write_data_mask                          (0x00000001)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod3_int_en(data)                   (0x00001000&((data)<<12))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod2_int_en(data)                   (0x00000800&((data)<<11))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_3_mod1_int_en(data)                   (0x00000400&((data)<<10))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod3_int_en(data)                   (0x00000200&((data)<<9))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod2_int_en(data)                   (0x00000100&((data)<<8))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_2_mod1_int_en(data)                   (0x00000080&((data)<<7))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod3_int_en(data)                   (0x00000040&((data)<<6))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod2_int_en(data)                   (0x00000020&((data)<<5))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_1_mod1_int_en(data)                   (0x00000010&((data)<<4))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod3_int_en(data)                   (0x00000008&((data)<<3))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod2_int_en(data)                   (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_mt_0_mod1_int_en(data)                   (0x00000002&((data)<<1))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_write_data(data)                         (0x00000001&(data))
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_3_mod3_int_en(data)               ((0x00001000&(data))>>12)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_3_mod2_int_en(data)               ((0x00000800&(data))>>11)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_3_mod1_int_en(data)               ((0x00000400&(data))>>10)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_2_mod3_int_en(data)               ((0x00000200&(data))>>9)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_2_mod2_int_en(data)               ((0x00000100&(data))>>8)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_2_mod1_int_en(data)               ((0x00000080&(data))>>7)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_1_mod3_int_en(data)               ((0x00000040&(data))>>6)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_1_mod2_int_en(data)               ((0x00000020&(data))>>5)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_1_mod1_int_en(data)               ((0x00000010&(data))>>4)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_0_mod3_int_en(data)               ((0x00000008&(data))>>3)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_0_mod2_int_en(data)               ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_mt_0_mod1_int_en(data)               ((0x00000002&(data))>>1)
#define  DC_SYS_DC_MTEX_int_enable_SYS2_get_write_data(data)                     (0x00000001&(data))

#define  DC_SYS_DC_MTEX_int_status_SYS2                                          0x18007734
#define  DC_SYS_DC_MTEX_int_status_SYS2_reg_addr                                 "0xB8007734"
#define  DC_SYS_DC_MTEX_int_status_SYS2_reg                                      0xB8007734
#define  DC_SYS_DC_MTEX_int_status_SYS2_inst_addr                                "0x00EF"
#define  set_DC_SYS_DC_MTEX_int_status_SYS2_reg(data)                            (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_status_SYS2_reg)=data)
#define  get_DC_SYS_DC_MTEX_int_status_SYS2_reg                                  (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_status_SYS2_reg))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod3_int_shift                      (12)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod2_int_shift                      (11)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod1_int_shift                      (10)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod3_int_shift                      (9)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod2_int_shift                      (8)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod1_int_shift                      (7)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod3_int_shift                      (6)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod2_int_shift                      (5)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod1_int_shift                      (4)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod3_int_shift                      (3)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod2_int_shift                      (2)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod1_int_shift                      (1)
#define  DC_SYS_DC_MTEX_int_status_SYS2_write_data_shift                         (0)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod3_int_mask                       (0x00001000)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod2_int_mask                       (0x00000800)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod1_int_mask                       (0x00000400)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod3_int_mask                       (0x00000200)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod2_int_mask                       (0x00000100)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod1_int_mask                       (0x00000080)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod3_int_mask                       (0x00000040)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod2_int_mask                       (0x00000020)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod1_int_mask                       (0x00000010)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod3_int_mask                       (0x00000008)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod2_int_mask                       (0x00000004)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod1_int_mask                       (0x00000002)
#define  DC_SYS_DC_MTEX_int_status_SYS2_write_data_mask                          (0x00000001)
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod3_int(data)                      (0x00001000&((data)<<12))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod2_int(data)                      (0x00000800&((data)<<11))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_3_mod1_int(data)                      (0x00000400&((data)<<10))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod3_int(data)                      (0x00000200&((data)<<9))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod2_int(data)                      (0x00000100&((data)<<8))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_2_mod1_int(data)                      (0x00000080&((data)<<7))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod3_int(data)                      (0x00000040&((data)<<6))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod2_int(data)                      (0x00000020&((data)<<5))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_1_mod1_int(data)                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod3_int(data)                      (0x00000008&((data)<<3))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod2_int(data)                      (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_int_status_SYS2_mt_0_mod1_int(data)                      (0x00000002&((data)<<1))
#define  DC_SYS_DC_MTEX_int_status_SYS2_write_data(data)                         (0x00000001&(data))
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_3_mod3_int(data)                  ((0x00001000&(data))>>12)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_3_mod2_int(data)                  ((0x00000800&(data))>>11)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_3_mod1_int(data)                  ((0x00000400&(data))>>10)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_2_mod3_int(data)                  ((0x00000200&(data))>>9)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_2_mod2_int(data)                  ((0x00000100&(data))>>8)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_2_mod1_int(data)                  ((0x00000080&(data))>>7)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_1_mod3_int(data)                  ((0x00000040&(data))>>6)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_1_mod2_int(data)                  ((0x00000020&(data))>>5)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_1_mod1_int(data)                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_0_mod3_int(data)                  ((0x00000008&(data))>>3)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_0_mod2_int(data)                  ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_mt_0_mod1_int(data)                  ((0x00000002&(data))>>1)
#define  DC_SYS_DC_MTEX_int_status_SYS2_get_write_data(data)                     (0x00000001&(data))

#define  DC_SYS_DC_MTEX_int_enable_SYS3                                          0x18007740
#define  DC_SYS_DC_MTEX_int_enable_SYS3_reg_addr                                 "0xB8007740"
#define  DC_SYS_DC_MTEX_int_enable_SYS3_reg                                      0xB8007740
#define  DC_SYS_DC_MTEX_int_enable_SYS3_inst_addr                                "0x00F0"
#define  set_DC_SYS_DC_MTEX_int_enable_SYS3_reg(data)                            (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_enable_SYS3_reg)=data)
#define  get_DC_SYS_DC_MTEX_int_enable_SYS3_reg                                  (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_enable_SYS3_reg))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod3_int_en_shift                   (12)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod2_int_en_shift                   (11)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod1_int_en_shift                   (10)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod3_int_en_shift                   (9)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod2_int_en_shift                   (8)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod1_int_en_shift                   (7)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod3_int_en_shift                   (6)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod2_int_en_shift                   (5)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod1_int_en_shift                   (4)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod3_int_en_shift                   (3)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod2_int_en_shift                   (2)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod1_int_en_shift                   (1)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_write_data_shift                         (0)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod3_int_en_mask                    (0x00001000)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod2_int_en_mask                    (0x00000800)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod1_int_en_mask                    (0x00000400)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod3_int_en_mask                    (0x00000200)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod2_int_en_mask                    (0x00000100)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod1_int_en_mask                    (0x00000080)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod3_int_en_mask                    (0x00000040)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod2_int_en_mask                    (0x00000020)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod1_int_en_mask                    (0x00000010)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod3_int_en_mask                    (0x00000008)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod2_int_en_mask                    (0x00000004)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod1_int_en_mask                    (0x00000002)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_write_data_mask                          (0x00000001)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod3_int_en(data)                   (0x00001000&((data)<<12))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod2_int_en(data)                   (0x00000800&((data)<<11))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_3_mod1_int_en(data)                   (0x00000400&((data)<<10))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod3_int_en(data)                   (0x00000200&((data)<<9))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod2_int_en(data)                   (0x00000100&((data)<<8))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_2_mod1_int_en(data)                   (0x00000080&((data)<<7))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod3_int_en(data)                   (0x00000040&((data)<<6))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod2_int_en(data)                   (0x00000020&((data)<<5))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_1_mod1_int_en(data)                   (0x00000010&((data)<<4))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod3_int_en(data)                   (0x00000008&((data)<<3))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod2_int_en(data)                   (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_mt_0_mod1_int_en(data)                   (0x00000002&((data)<<1))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_write_data(data)                         (0x00000001&(data))
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_3_mod3_int_en(data)               ((0x00001000&(data))>>12)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_3_mod2_int_en(data)               ((0x00000800&(data))>>11)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_3_mod1_int_en(data)               ((0x00000400&(data))>>10)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_2_mod3_int_en(data)               ((0x00000200&(data))>>9)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_2_mod2_int_en(data)               ((0x00000100&(data))>>8)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_2_mod1_int_en(data)               ((0x00000080&(data))>>7)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_1_mod3_int_en(data)               ((0x00000040&(data))>>6)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_1_mod2_int_en(data)               ((0x00000020&(data))>>5)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_1_mod1_int_en(data)               ((0x00000010&(data))>>4)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_0_mod3_int_en(data)               ((0x00000008&(data))>>3)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_0_mod2_int_en(data)               ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_mt_0_mod1_int_en(data)               ((0x00000002&(data))>>1)
#define  DC_SYS_DC_MTEX_int_enable_SYS3_get_write_data(data)                     (0x00000001&(data))

#define  DC_SYS_DC_MTEX_int_status_SYS3                                          0x18007744
#define  DC_SYS_DC_MTEX_int_status_SYS3_reg_addr                                 "0xB8007744"
#define  DC_SYS_DC_MTEX_int_status_SYS3_reg                                      0xB8007744
#define  DC_SYS_DC_MTEX_int_status_SYS3_inst_addr                                "0x00F1"
#define  set_DC_SYS_DC_MTEX_int_status_SYS3_reg(data)                            (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_status_SYS3_reg)=data)
#define  get_DC_SYS_DC_MTEX_int_status_SYS3_reg                                  (*((volatile unsigned int*)DC_SYS_DC_MTEX_int_status_SYS3_reg))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod3_int_shift                      (12)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod2_int_shift                      (11)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod1_int_shift                      (10)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod3_int_shift                      (9)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod2_int_shift                      (8)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod1_int_shift                      (7)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod3_int_shift                      (6)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod2_int_shift                      (5)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod1_int_shift                      (4)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod3_int_shift                      (3)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod2_int_shift                      (2)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod1_int_shift                      (1)
#define  DC_SYS_DC_MTEX_int_status_SYS3_write_data_shift                         (0)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod3_int_mask                       (0x00001000)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod2_int_mask                       (0x00000800)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod1_int_mask                       (0x00000400)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod3_int_mask                       (0x00000200)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod2_int_mask                       (0x00000100)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod1_int_mask                       (0x00000080)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod3_int_mask                       (0x00000040)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod2_int_mask                       (0x00000020)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod1_int_mask                       (0x00000010)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod3_int_mask                       (0x00000008)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod2_int_mask                       (0x00000004)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod1_int_mask                       (0x00000002)
#define  DC_SYS_DC_MTEX_int_status_SYS3_write_data_mask                          (0x00000001)
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod3_int(data)                      (0x00001000&((data)<<12))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod2_int(data)                      (0x00000800&((data)<<11))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_3_mod1_int(data)                      (0x00000400&((data)<<10))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod3_int(data)                      (0x00000200&((data)<<9))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod2_int(data)                      (0x00000100&((data)<<8))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_2_mod1_int(data)                      (0x00000080&((data)<<7))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod3_int(data)                      (0x00000040&((data)<<6))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod2_int(data)                      (0x00000020&((data)<<5))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_1_mod1_int(data)                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod3_int(data)                      (0x00000008&((data)<<3))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod2_int(data)                      (0x00000004&((data)<<2))
#define  DC_SYS_DC_MTEX_int_status_SYS3_mt_0_mod1_int(data)                      (0x00000002&((data)<<1))
#define  DC_SYS_DC_MTEX_int_status_SYS3_write_data(data)                         (0x00000001&(data))
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_3_mod3_int(data)                  ((0x00001000&(data))>>12)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_3_mod2_int(data)                  ((0x00000800&(data))>>11)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_3_mod1_int(data)                  ((0x00000400&(data))>>10)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_2_mod3_int(data)                  ((0x00000200&(data))>>9)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_2_mod2_int(data)                  ((0x00000100&(data))>>8)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_2_mod1_int(data)                  ((0x00000080&(data))>>7)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_1_mod3_int(data)                  ((0x00000040&(data))>>6)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_1_mod2_int(data)                  ((0x00000020&(data))>>5)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_1_mod1_int(data)                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_0_mod3_int(data)                  ((0x00000008&(data))>>3)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_0_mod2_int(data)                  ((0x00000004&(data))>>2)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_mt_0_mod1_int(data)                  ((0x00000002&(data))>>1)
#define  DC_SYS_DC_MTEX_int_status_SYS3_get_write_data(data)                     (0x00000001&(data))

#define  DC_SYS_DC_SFTX_TEST0                                                    0x18007800
#define  DC_SYS_DC_SFTX_TEST0_reg_addr                                           "0xB8007800"
#define  DC_SYS_DC_SFTX_TEST0_reg                                                0xB8007800
#define  DC_SYS_DC_SFTX_TEST0_inst_addr                                          "0x00F2"
#define  set_DC_SYS_DC_SFTX_TEST0_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_SFTX_TEST0_reg)=data)
#define  get_DC_SYS_DC_SFTX_TEST0_reg                                            (*((volatile unsigned int*)DC_SYS_DC_SFTX_TEST0_reg))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_disram_shift                            (10)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_gpu_shift                               (9)
#define  DC_SYS_DC_SFTX_TEST0_dummy_8_6_shift                                    (6)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_se2_shift                               (5)
#define  DC_SYS_DC_SFTX_TEST0_dummy_4_shift                                      (4)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb2_shift                             (3)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb4_shift                             (2)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb5_shift                             (1)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_ve_shift                                (0)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_disram_mask                             (0x00000400)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_gpu_mask                                (0x00000200)
#define  DC_SYS_DC_SFTX_TEST0_dummy_8_6_mask                                     (0x000001C0)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_se2_mask                                (0x00000020)
#define  DC_SYS_DC_SFTX_TEST0_dummy_4_mask                                       (0x00000010)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb2_mask                              (0x00000008)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb4_mask                              (0x00000004)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb5_mask                              (0x00000002)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_ve_mask                                 (0x00000001)
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_disram(data)                            (0x00000400&((data)<<10))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_gpu(data)                               (0x00000200&((data)<<9))
#define  DC_SYS_DC_SFTX_TEST0_dummy_8_6(data)                                    (0x000001C0&((data)<<6))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_se2(data)                               (0x00000020&((data)<<5))
#define  DC_SYS_DC_SFTX_TEST0_dummy_4(data)                                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb2(data)                             (0x00000008&((data)<<3))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb4(data)                             (0x00000004&((data)<<2))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_tvsb5(data)                             (0x00000002&((data)<<1))
#define  DC_SYS_DC_SFTX_TEST0_sf_tx_mode_ve(data)                                (0x00000001&(data))
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_disram(data)                        ((0x00000400&(data))>>10)
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_gpu(data)                           ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SFTX_TEST0_get_dummy_8_6(data)                                ((0x000001C0&(data))>>6)
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_se2(data)                           ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SFTX_TEST0_get_dummy_4(data)                                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_tvsb2(data)                         ((0x00000008&(data))>>3)
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_tvsb4(data)                         ((0x00000004&(data))>>2)
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_tvsb5(data)                         ((0x00000002&(data))>>1)
#define  DC_SYS_DC_SFTX_TEST0_get_sf_tx_mode_ve(data)                            (0x00000001&(data))

#define  DC_SYS_DC_SFTX_TEST1                                                    0x18007804
#define  DC_SYS_DC_SFTX_TEST1_reg_addr                                           "0xB8007804"
#define  DC_SYS_DC_SFTX_TEST1_reg                                                0xB8007804
#define  DC_SYS_DC_SFTX_TEST1_inst_addr                                          "0x00F3"
#define  set_DC_SYS_DC_SFTX_TEST1_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_SFTX_TEST1_reg)=data)
#define  get_DC_SYS_DC_SFTX_TEST1_reg                                            (*((volatile unsigned int*)DC_SYS_DC_SFTX_TEST1_reg))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_disram_shift                         (26)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_gpu_shift                            (25)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_se2_shift                            (21)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb2_shift                          (19)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb4_shift                          (18)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb5_shift                          (17)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_ve_shift                             (16)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_disram_shift                           (10)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_gpu_shift                              (9)
#define  DC_SYS_DC_SFTX_TEST1_dummy_8_6_shift                                    (6)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_se2_shift                              (5)
#define  DC_SYS_DC_SFTX_TEST1_dummy_4_shift                                      (4)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb2_shift                            (3)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb4_shift                            (2)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb5_shift                            (1)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_ve_shift                               (0)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_disram_mask                          (0x04000000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_gpu_mask                             (0x02000000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_se2_mask                             (0x00200000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb2_mask                           (0x00080000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb4_mask                           (0x00040000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb5_mask                           (0x00020000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_ve_mask                              (0x00010000)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_disram_mask                            (0x00000400)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_gpu_mask                               (0x00000200)
#define  DC_SYS_DC_SFTX_TEST1_dummy_8_6_mask                                     (0x000001C0)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_se2_mask                               (0x00000020)
#define  DC_SYS_DC_SFTX_TEST1_dummy_4_mask                                       (0x00000010)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb2_mask                             (0x00000008)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb4_mask                             (0x00000004)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb5_mask                             (0x00000002)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_ve_mask                                (0x00000001)
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_disram(data)                         (0x04000000&((data)<<26))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_gpu(data)                            (0x02000000&((data)<<25))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_se2(data)                            (0x00200000&((data)<<21))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb2(data)                          (0x00080000&((data)<<19))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb4(data)                          (0x00040000&((data)<<18))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_tvsb5(data)                          (0x00020000&((data)<<17))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_work_ro_ve(data)                             (0x00010000&((data)<<16))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_disram(data)                           (0x00000400&((data)<<10))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_gpu(data)                              (0x00000200&((data)<<9))
#define  DC_SYS_DC_SFTX_TEST1_dummy_8_6(data)                                    (0x000001C0&((data)<<6))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_se2(data)                              (0x00000020&((data)<<5))
#define  DC_SYS_DC_SFTX_TEST1_dummy_4(data)                                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb2(data)                            (0x00000008&((data)<<3))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb4(data)                            (0x00000004&((data)<<2))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_tvsb5(data)                            (0x00000002&((data)<<1))
#define  DC_SYS_DC_SFTX_TEST1_sf_tx_start_ve(data)                               (0x00000001&(data))
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_disram(data)                     ((0x04000000&(data))>>26)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_gpu(data)                        ((0x02000000&(data))>>25)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_se2(data)                        ((0x00200000&(data))>>21)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_tvsb2(data)                      ((0x00080000&(data))>>19)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_tvsb4(data)                      ((0x00040000&(data))>>18)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_tvsb5(data)                      ((0x00020000&(data))>>17)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_work_ro_ve(data)                         ((0x00010000&(data))>>16)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_disram(data)                       ((0x00000400&(data))>>10)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_gpu(data)                          ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SFTX_TEST1_get_dummy_8_6(data)                                ((0x000001C0&(data))>>6)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_se2(data)                          ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SFTX_TEST1_get_dummy_4(data)                                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_tvsb2(data)                        ((0x00000008&(data))>>3)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_tvsb4(data)                        ((0x00000004&(data))>>2)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_tvsb5(data)                        ((0x00000002&(data))>>1)
#define  DC_SYS_DC_SFTX_TEST1_get_sf_tx_start_ve(data)                           (0x00000001&(data))

#define  DC_SYS_DC_SFRX_TEST0                                                    0x18007808
#define  DC_SYS_DC_SFRX_TEST0_reg_addr                                           "0xB8007808"
#define  DC_SYS_DC_SFRX_TEST0_reg                                                0xB8007808
#define  DC_SYS_DC_SFRX_TEST0_inst_addr                                          "0x00F4"
#define  set_DC_SYS_DC_SFRX_TEST0_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_SFRX_TEST0_reg)=data)
#define  get_DC_SYS_DC_SFRX_TEST0_reg                                            (*((volatile unsigned int*)DC_SYS_DC_SFRX_TEST0_reg))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_disram_shift                           (26)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_gpu_shift                              (25)
#define  DC_SYS_DC_SFRX_TEST0_dummy_24_22_shift                                  (22)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_se2_shift                              (21)
#define  DC_SYS_DC_SFRX_TEST0_dummy_20_shift                                     (20)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb2_shift                            (19)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb4_shift                            (18)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb5_shift                            (17)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_ve_shift                               (16)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_disram_shift                            (10)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_gpu_shift                               (9)
#define  DC_SYS_DC_SFRX_TEST0_dummy_8_6_shift                                    (6)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_se2_shift                               (5)
#define  DC_SYS_DC_SFRX_TEST0_dummy_4_shift                                      (4)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb2_shift                             (3)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb4_shift                             (2)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb5_shift                             (1)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_ve_shift                                (0)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_disram_mask                            (0x04000000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_gpu_mask                               (0x02000000)
#define  DC_SYS_DC_SFRX_TEST0_dummy_24_22_mask                                   (0x01C00000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_se2_mask                               (0x00200000)
#define  DC_SYS_DC_SFRX_TEST0_dummy_20_mask                                      (0x00100000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb2_mask                             (0x00080000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb4_mask                             (0x00040000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb5_mask                             (0x00020000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_ve_mask                                (0x00010000)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_disram_mask                             (0x00000400)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_gpu_mask                                (0x00000200)
#define  DC_SYS_DC_SFRX_TEST0_dummy_8_6_mask                                     (0x000001C0)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_se2_mask                                (0x00000020)
#define  DC_SYS_DC_SFRX_TEST0_dummy_4_mask                                       (0x00000010)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb2_mask                              (0x00000008)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb4_mask                              (0x00000004)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb5_mask                              (0x00000002)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_ve_mask                                 (0x00000001)
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_disram(data)                           (0x04000000&((data)<<26))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_gpu(data)                              (0x02000000&((data)<<25))
#define  DC_SYS_DC_SFRX_TEST0_dummy_24_22(data)                                  (0x01C00000&((data)<<22))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_se2(data)                              (0x00200000&((data)<<21))
#define  DC_SYS_DC_SFRX_TEST0_dummy_20(data)                                     (0x00100000&((data)<<20))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb2(data)                            (0x00080000&((data)<<19))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb4(data)                            (0x00040000&((data)<<18))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_tvsb5(data)                            (0x00020000&((data)<<17))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_gated_ve(data)                               (0x00010000&((data)<<16))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_disram(data)                            (0x00000400&((data)<<10))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_gpu(data)                               (0x00000200&((data)<<9))
#define  DC_SYS_DC_SFRX_TEST0_dummy_8_6(data)                                    (0x000001C0&((data)<<6))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_se2(data)                               (0x00000020&((data)<<5))
#define  DC_SYS_DC_SFRX_TEST0_dummy_4(data)                                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb2(data)                             (0x00000008&((data)<<3))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb4(data)                             (0x00000004&((data)<<2))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_tvsb5(data)                             (0x00000002&((data)<<1))
#define  DC_SYS_DC_SFRX_TEST0_sf_rx_mode_ve(data)                                (0x00000001&(data))
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_disram(data)                       ((0x04000000&(data))>>26)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_gpu(data)                          ((0x02000000&(data))>>25)
#define  DC_SYS_DC_SFRX_TEST0_get_dummy_24_22(data)                              ((0x01C00000&(data))>>22)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_se2(data)                          ((0x00200000&(data))>>21)
#define  DC_SYS_DC_SFRX_TEST0_get_dummy_20(data)                                 ((0x00100000&(data))>>20)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_tvsb2(data)                        ((0x00080000&(data))>>19)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_tvsb4(data)                        ((0x00040000&(data))>>18)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_tvsb5(data)                        ((0x00020000&(data))>>17)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_gated_ve(data)                           ((0x00010000&(data))>>16)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_disram(data)                        ((0x00000400&(data))>>10)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_gpu(data)                           ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SFRX_TEST0_get_dummy_8_6(data)                                ((0x000001C0&(data))>>6)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_se2(data)                           ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SFRX_TEST0_get_dummy_4(data)                                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_tvsb2(data)                         ((0x00000008&(data))>>3)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_tvsb4(data)                         ((0x00000004&(data))>>2)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_tvsb5(data)                         ((0x00000002&(data))>>1)
#define  DC_SYS_DC_SFRX_TEST0_get_sf_rx_mode_ve(data)                            (0x00000001&(data))

#define  DC_SYS_DC_SFRX_TEST1                                                    0x1800780C
#define  DC_SYS_DC_SFRX_TEST1_reg_addr                                           "0xB800780C"
#define  DC_SYS_DC_SFRX_TEST1_reg                                                0xB800780C
#define  DC_SYS_DC_SFRX_TEST1_inst_addr                                          "0x00F5"
#define  set_DC_SYS_DC_SFRX_TEST1_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_SFRX_TEST1_reg)=data)
#define  get_DC_SYS_DC_SFRX_TEST1_reg                                            (*((volatile unsigned int*)DC_SYS_DC_SFRX_TEST1_reg))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_disram_shift                         (26)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_gpu_shift                            (25)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_se2_shift                            (21)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb2_shift                          (19)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb4_shift                          (18)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb5_shift                          (17)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_ve_shift                             (16)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_disram_shift                           (10)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_gpu_shift                              (9)
#define  DC_SYS_DC_SFRX_TEST1_dummy_8_6_shift                                    (6)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_se2_shift                              (5)
#define  DC_SYS_DC_SFRX_TEST1_dummy_4_shift                                      (4)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb2_shift                            (3)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb4_shift                            (2)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb5_shift                            (1)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_ve_shift                               (0)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_disram_mask                          (0x04000000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_gpu_mask                             (0x02000000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_se2_mask                             (0x00200000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb2_mask                           (0x00080000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb4_mask                           (0x00040000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb5_mask                           (0x00020000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_ve_mask                              (0x00010000)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_disram_mask                            (0x00000400)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_gpu_mask                               (0x00000200)
#define  DC_SYS_DC_SFRX_TEST1_dummy_8_6_mask                                     (0x000001C0)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_se2_mask                               (0x00000020)
#define  DC_SYS_DC_SFRX_TEST1_dummy_4_mask                                       (0x00000010)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb2_mask                             (0x00000008)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb4_mask                             (0x00000004)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb5_mask                             (0x00000002)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_ve_mask                                (0x00000001)
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_disram(data)                         (0x04000000&((data)<<26))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_gpu(data)                            (0x02000000&((data)<<25))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_se2(data)                            (0x00200000&((data)<<21))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb2(data)                          (0x00080000&((data)<<19))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb4(data)                          (0x00040000&((data)<<18))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_tvsb5(data)                          (0x00020000&((data)<<17))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_done_ro_ve(data)                             (0x00010000&((data)<<16))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_disram(data)                           (0x00000400&((data)<<10))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_gpu(data)                              (0x00000200&((data)<<9))
#define  DC_SYS_DC_SFRX_TEST1_dummy_8_6(data)                                    (0x000001C0&((data)<<6))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_se2(data)                              (0x00000020&((data)<<5))
#define  DC_SYS_DC_SFRX_TEST1_dummy_4(data)                                      (0x00000010&((data)<<4))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb2(data)                            (0x00000008&((data)<<3))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb4(data)                            (0x00000004&((data)<<2))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_tvsb5(data)                            (0x00000002&((data)<<1))
#define  DC_SYS_DC_SFRX_TEST1_sf_rx_start_ve(data)                               (0x00000001&(data))
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_disram(data)                     ((0x04000000&(data))>>26)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_gpu(data)                        ((0x02000000&(data))>>25)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_se2(data)                        ((0x00200000&(data))>>21)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_tvsb2(data)                      ((0x00080000&(data))>>19)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_tvsb4(data)                      ((0x00040000&(data))>>18)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_tvsb5(data)                      ((0x00020000&(data))>>17)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_done_ro_ve(data)                         ((0x00010000&(data))>>16)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_disram(data)                       ((0x00000400&(data))>>10)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_gpu(data)                          ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SFRX_TEST1_get_dummy_8_6(data)                                ((0x000001C0&(data))>>6)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_se2(data)                          ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SFRX_TEST1_get_dummy_4(data)                                  ((0x00000010&(data))>>4)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_tvsb2(data)                        ((0x00000008&(data))>>3)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_tvsb4(data)                        ((0x00000004&(data))>>2)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_tvsb5(data)                        ((0x00000002&(data))>>1)
#define  DC_SYS_DC_SFRX_TEST1_get_sf_rx_start_ve(data)                           (0x00000001&(data))

#define  DC_SYS_DC_SFRX_TEST2                                                    0x18007810
#define  DC_SYS_DC_SFRX_TEST2_reg_addr                                           "0xB8007810"
#define  DC_SYS_DC_SFRX_TEST2_reg                                                0xB8007810
#define  DC_SYS_DC_SFRX_TEST2_inst_addr                                          "0x00F6"
#define  set_DC_SYS_DC_SFRX_TEST2_reg(data)                                      (*((volatile unsigned int*)DC_SYS_DC_SFRX_TEST2_reg)=data)
#define  get_DC_SYS_DC_SFRX_TEST2_reg                                            (*((volatile unsigned int*)DC_SYS_DC_SFRX_TEST2_reg))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_disram_shift                          (10)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_gpu_shift                             (9)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_se2_shift                             (5)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb2_shift                           (3)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb4_shift                           (2)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb5_shift                           (1)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_ve_shift                              (0)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_disram_mask                           (0x00000400)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_gpu_mask                              (0x00000200)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_se2_mask                              (0x00000020)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb2_mask                            (0x00000008)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb4_mask                            (0x00000004)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb5_mask                            (0x00000002)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_ve_mask                               (0x00000001)
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_disram(data)                          (0x00000400&((data)<<10))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_gpu(data)                             (0x00000200&((data)<<9))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_se2(data)                             (0x00000020&((data)<<5))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb2(data)                           (0x00000008&((data)<<3))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb4(data)                           (0x00000004&((data)<<2))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_tvsb5(data)                           (0x00000002&((data)<<1))
#define  DC_SYS_DC_SFRX_TEST2_sf_rx_err_ro_ve(data)                              (0x00000001&(data))
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_disram(data)                      ((0x00000400&(data))>>10)
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_gpu(data)                         ((0x00000200&(data))>>9)
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_se2(data)                         ((0x00000020&(data))>>5)
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_tvsb2(data)                       ((0x00000008&(data))>>3)
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_tvsb4(data)                       ((0x00000004&(data))>>2)
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_tvsb5(data)                       ((0x00000002&(data))>>1)
#define  DC_SYS_DC_SFRX_TEST2_get_sf_rx_err_ro_ve(data)                          (0x00000001&(data))

#define  DC_SYS_DC_TS_DBG                                                        0x180078F0
#define  DC_SYS_DC_TS_DBG_reg_addr                                               "0xB80078F0"
#define  DC_SYS_DC_TS_DBG_reg                                                    0xB80078F0
#define  DC_SYS_DC_TS_DBG_inst_addr                                              "0x00F7"
#define  set_DC_SYS_DC_TS_DBG_reg(data)                                          (*((volatile unsigned int*)DC_SYS_DC_TS_DBG_reg)=data)
#define  get_DC_SYS_DC_TS_DBG_reg                                                (*((volatile unsigned int*)DC_SYS_DC_TS_DBG_reg))
#define  DC_SYS_DC_TS_DBG_ts_dbg_sel_shift                                       (16)
#define  DC_SYS_DC_TS_DBG_ts_dbg_out_shift                                       (0)
#define  DC_SYS_DC_TS_DBG_ts_dbg_sel_mask                                        (0x000F0000)
#define  DC_SYS_DC_TS_DBG_ts_dbg_out_mask                                        (0x000003FF)
#define  DC_SYS_DC_TS_DBG_ts_dbg_sel(data)                                       (0x000F0000&((data)<<16))
#define  DC_SYS_DC_TS_DBG_ts_dbg_out(data)                                       (0x000003FF&(data))
#define  DC_SYS_DC_TS_DBG_get_ts_dbg_sel(data)                                   ((0x000F0000&(data))>>16)
#define  DC_SYS_DC_TS_DBG_get_ts_dbg_out(data)                                   (0x000003FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC_SYS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pict_width_scale:6;
        RBus_UInt32  pict_init_page:17;
    };
}dc_sys_dc_pict_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dram_8g_used:1;
        RBus_UInt32  dram_4g_used:1;
        RBus_UInt32  ddr3_512_used:1;
        RBus_UInt32  dram_2g_used:1;
        RBus_UInt32  pre_arb_scheme_sel:1;
        RBus_UInt32  arb_mask_all_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  self_lookback_mode:1;
        RBus_UInt32  mem_num:1;
        RBus_UInt32  dis_8x2to16x1_dummy:1;
        RBus_UInt32  page_size:2;
        RBus_UInt32  dummy18007004_15_12:4;
        RBus_UInt32  bank_scr_256:1;
        RBus_UInt32  en_bank_scr:1;
        RBus_UInt32  max_bl_size:1;
        RBus_UInt32  en_max_bl_limit:1;
        RBus_UInt32  small_dram_4g:1;
        RBus_UInt32  small_dram_2g:1;
        RBus_UInt32  small_dram_1g:1;
        RBus_UInt32  small_dram_512m:1;
        RBus_UInt32  dummy18007004_3_1:3;
        RBus_UInt32  en_2ddr_diff_size:1;
    };
}dc_sys_dc_sys_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  enable:1;
    };
}dc_sys_dc_pic_offset_x_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_set_num:8;
        RBus_UInt32  pict_offset_rd:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pict_set_wide:1;
        RBus_UInt32  pict_set_offset_y:10;
        RBus_UInt32  pict_set_offset_x:10;
    };
}dc_sys_dc_pict_set_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  req_pending:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  req_id:13;
    };
}dc_sys_dc_req_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_arb_merge:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  qfifo_cnt_full_threshold:3;
        RBus_UInt32  full_cmd_count:4;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  pre_tra_wr_cnt:10;
    };
}dc_sys_dc_sys_misc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve2_id_gen_en:1;
        RBus_UInt32  ve_id_gen_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  wfifo_cnt_full_threshold:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  memc_cmd_queue_flush:1;
        RBus_UInt32  memc_cmd_grp_disable:1;
        RBus_UInt32  se2_cmd_queue_flush:1;
        RBus_UInt32  se2_cmd_grp_disable:1;
        RBus_UInt32  ve2_cmd_queue_flush:1;
        RBus_UInt32  ve2_cmd_grp_disable:1;
        RBus_UInt32  res3:6;
        RBus_UInt32  ve_cmd_queue_flush:1;
        RBus_UInt32  ve_cmd_grp_disable:1;
        RBus_UInt32  tvsb4_cmd_queue_flush:1;
        RBus_UInt32  tvsb4_cmd_grp_disable:1;
        RBus_UInt32  tvsb3_cmd_queue_flush:1;
        RBus_UInt32  tvsb3_cmd_grp_disable:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  enable_arb_delay_by_tv_sb1_grant:1;
        RBus_UInt32  gpu_cmd_queue_flush:1;
        RBus_UInt32  gpu_cmd_grp_disable:1;
    };
}dc_sys_dc_sys_misc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_space_margin:4;
        RBus_UInt32  se2_space_margin:4;
        RBus_UInt32  ve2_space_margin:4;
        RBus_UInt32  ve_space_margin:4;
        RBus_UInt32  tvsb4_space_margin:4;
        RBus_UInt32  tvsb3_space_margin:4;
        RBus_UInt32  gpu_space_margin:4;
    };
}dc_sys_dc_sys_misc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern0:32;
    };
}dc_sys_dc_sfmode0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern1:32;
    };
}dc_sys_dc_sfmode1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern2:32;
    };
}dc_sys_dc_sfmode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern3:32;
    };
}dc_sys_dc_sfmode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt0:32;
    };
}dc_sys_dc_sfmode_cmp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt1:32;
    };
}dc_sys_dc_sfmode_cmp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt2:32;
    };
}dc_sys_dc_sfmode_cmp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt3:32;
    };
}dc_sys_dc_sfmode_cmp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  debug_sys_sel:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  debug_sel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  debug_sel_0:6;
    };
}dc_sys_dc_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sys_out1:16;
        RBus_UInt32  dbg_sys_out0:16;
    };
}dc_sys_dc_debug_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  exsram_fifo_underflow:1;
        RBus_UInt32  exsram_fifo_overflow:1;
        RBus_UInt32  write_cmd_fifo_2_underflow:1;
        RBus_UInt32  write_cmd_fifo_1_underflow:1;
        RBus_UInt32  write_cmd_fifo_0_underflow:1;
        RBus_UInt32  read_cmd_fifo_2_underflow:1;
        RBus_UInt32  read_cmd_fifo_1_underflow:1;
        RBus_UInt32  read_cmd_fifo_0_underflow:1;
        RBus_UInt32  write_cmd_fifo_2_overflow:1;
        RBus_UInt32  write_cmd_fifo_1_overflow:1;
        RBus_UInt32  write_cmd_fifo_0_overflow:1;
        RBus_UInt32  read_cmd_fifo_2_overflow:1;
        RBus_UInt32  read_cmd_fifo_1_overflow:1;
        RBus_UInt32  read_cmd_fifo_0_overflow:1;
        RBus_UInt32  write_fifo_2_underflow:1;
        RBus_UInt32  write_fifo_1_underflow:1;
        RBus_UInt32  write_fifo_0_underflow:1;
        RBus_UInt32  read_fifo_2_underflow:1;
        RBus_UInt32  read_fifo_1_underflow:1;
        RBus_UInt32  read_fifo_0_underflow:1;
        RBus_UInt32  write_fifo_2_overflow:1;
        RBus_UInt32  write_fifo_1_overflow:1;
        RBus_UInt32  write_fifo_0_overflow:1;
        RBus_UInt32  read_fifo_2_overflow:1;
        RBus_UInt32  read_fifo_1_overflow:1;
        RBus_UInt32  read_fifo_0_overflow:1;
    };
}dc_sys_dc_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c0_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c1_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c2_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c3_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c4_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c5_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c6_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c7_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c8_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c8_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  c9_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  c9_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ca_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  ca_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cb_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  cb_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cc_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  cc_latcnt_beg:8;
    };
}dc_sys_dc_priority_ctrlc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpu_lat_new:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hie_cmp_dis:13;
        RBus_UInt32  res2:8;
        RBus_UInt32  latcnt_period:8;
    };
}dc_sys_dc_priority_ctrl_hie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  req_mask_index:13;
    };
}dc_sys_dc_client_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_rcmd_only:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pc_go:1;
    };
}dc_sys_dc_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}dc_sys_dc_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}dc_sys_dc_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}dc_sys_dc_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_sysh_prog2_sel:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_sysh_prog1_sel:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_sysh_prog0_sel:4;
        RBus_UInt32  res4:3;
    };
}dc_sys_dc_pc_sysh_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pc_sysh_prog2_req_occur:1;
        RBus_UInt32  pc_sysh_prog1_req_occur:1;
        RBus_UInt32  pc_sysh_prog0_req_occur:1;
        RBus_UInt32  res2:4;
    };
}dc_sys_dc_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_acc_lat:32;
    };
}dc_sys_dc_pc_sysh_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog0_max_lat:16;
    };
}dc_sys_dc_pc_sysh_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog0_req_num:24;
    };
}dc_sys_dc_pc_sysh_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_ack_num:32;
    };
}dc_sys_dc_pc_sysh_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_acc_lat:32;
    };
}dc_sys_dc_pc_sysh_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog1_max_lat:16;
    };
}dc_sys_dc_pc_sysh_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog1_req_num:24;
    };
}dc_sys_dc_pc_sysh_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_ack_num:32;
    };
}dc_sys_dc_pc_sysh_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_acc_lat:32;
    };
}dc_sys_dc_pc_sysh_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh_prog2_max_lat:16;
    };
}dc_sys_dc_pc_sysh_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sysh_prog2_req_num:24;
    };
}dc_sys_dc_pc_sysh_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_ack_num:32;
    };
}dc_sys_dc_pc_sysh_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cmd_num_in_cti_q_prog2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  cmd_num_in_cti_q_prog1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  cmd_num_in_cti_q_prog0:5;
    };
}dc_sys_dc_pc_sysh_prog_cti_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  remain_cmd_num0_prog2:8;
        RBus_UInt32  remain_cmd_num0_prog1:8;
        RBus_UInt32  remain_cmd_num0_prog0:8;
    };
}dc_sys_dc_pc_sysh_prog_cmd_num_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  remain_cmd_num1_prog2:8;
        RBus_UInt32  remain_cmd_num1_prog1:8;
        RBus_UInt32  remain_cmd_num1_prog0:8;
    };
}dc_sys_dc_pc_sysh_prog_cmd_num_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh0_hitend_cnt:16;
    };
}dc_sys_dc_pc_sysh_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh1_hitend_cnt:16;
    };
}dc_sys_dc_pc_sysh_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sysh2_hitend_cnt:16;
    };
}dc_sys_dc_pc_sysh_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  res2:3;
        RBus_UInt32  dc_bist_mode_pict0:1;
        RBus_UInt32  res3:1;
    };
}dc_sys_dc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_bist_done_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_bist_fail_group_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_mode_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_resume_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_done_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_pause_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dc_drf_fail_group_pict0:1;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dc_drf_pict_fail0:1;
        RBus_UInt32  dc_bist_pict_fail0:1;
        RBus_UInt32  res4:4;
    };
}dc_sys_dc_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  res2:3;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_0:1;
    };
}dc_sys_dc_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg0:32;
    };
}dc_sys_dc_dummy_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg1:32;
    };
}dc_sys_dc_dummy_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg2:32;
    };
}dc_sys_dc_dummy_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg3:32;
    };
}dc_sys_dc_dummy_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_type:2;
        RBus_UInt32  res1:30;
    };
}dc_sys_dc_mt_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:5;
    };
}dc_sys_dc_mt_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:5;
    };
}dc_sys_dc_mt_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  mode:2;
    };
}dc_sys_dc_mt_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_0:8;
        RBus_UInt32  module_id_1:8;
        RBus_UInt32  module_id_2:8;
        RBus_UInt32  module_id_3:8;
    };
}dc_sys_dc_mt_table_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_type_0:2;
        RBus_UInt32  access_type_1:2;
        RBus_UInt32  access_type_2:2;
        RBus_UInt32  access_type_3:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:8;
        RBus_UInt32  addcmd:14;
    };
}dc_sys_dc_mt_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mt_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mt_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  disable_cross_range_check:1;
    };
}dc_sys_dc_mt_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  error_cmd_swap_addr:27;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  error_cmd_swap_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  error_cmd_detection_en:1;
    };
}dc_sys_dc_ec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:23;
    };
}dc_sys_dc_ec_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_sys_dc_ec_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  err_blk_err_dis:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  tag_check_en:1;
    };
}dc_sys_dc_rd_tag_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pic_offset_x_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_err_int_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pic_offset_x_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_err_int:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypass_req_to_arb:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  bw_mode:26;
    };
}dc_sys_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}dc_sys_bw_timer_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  value:24;
    };
}dc_sys_bw_request_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  res3:3;
        RBus_UInt32  tv_sb5_mux:1;
        RBus_UInt32  tv_sb1_mux:1;
        RBus_UInt32  memc_mux:1;
        RBus_UInt32  tv_sb4_mux:1;
        RBus_UInt32  tv_sb2_mux:1;
    };
}dc_sys_dc_sys2_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:8;
        RBus_UInt32  addcmd:14;
    };
}dc_sys_dc_mt_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mt_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mt_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:23;
    };
}dc_sys_dc_ec_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_sys_dc_ec_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_err_int_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_int_enable_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_err_int:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_int_status_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  res3:3;
        RBus_UInt32  gpu_mux:1;
        RBus_UInt32  se2_mux:1;
        RBus_UInt32  tv_sb3_mux:1;
        RBus_UInt32  ve2_mux:1;
        RBus_UInt32  ve_mux:1;
    };
}dc_sys_dc_sys3_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:8;
        RBus_UInt32  addcmd:14;
    };
}dc_sys_dc_mt_addcmd_hi_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mt_addcmd_lo_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mt_addcmd_sa_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_cmd_ever_trap:1;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  addcmd_hi:23;
    };
}dc_sys_dc_ec_addcmd_hi_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_sys_dc_ec_addcmd_lo_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_err_int_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_int_enable_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_err_int:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_int_status_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_type:2;
        RBus_UInt32  res1:30;
    };
}dc_sys_dc_mtex_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:5;
    };
}dc_sys_dc_mtex_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:5;
    };
}dc_sys_dc_mtex_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  mode:2;
    };
}dc_sys_dc_mtex_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_0:8;
        RBus_UInt32  module_id_1:8;
        RBus_UInt32  module_id_2:8;
        RBus_UInt32  module_id_3:8;
    };
}dc_sys_dc_mtex_table0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_4:8;
        RBus_UInt32  module_id_5:8;
        RBus_UInt32  module_id_6:8;
        RBus_UInt32  module_id_7:8;
    };
}dc_sys_dc_mtex_table1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_type_0:2;
        RBus_UInt32  access_type_1:2;
        RBus_UInt32  access_type_2:2;
        RBus_UInt32  access_type_3:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:8;
        RBus_UInt32  addcmd:14;
    };
}dc_sys_dc_mtex_addcmd_hi0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  access_type_4:2;
        RBus_UInt32  access_type_5:2;
        RBus_UInt32  access_type_6:2;
        RBus_UInt32  access_type_7:2;
        RBus_UInt32  res1:24;
    };
}dc_sys_dc_mtex_addcmd_hi1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mtex_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mtex_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:8;
        RBus_UInt32  addcmd:14;
    };
}dc_sys_dc_mtex_addcmd_hi0_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mtex_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mtex_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  module_id:8;
        RBus_UInt32  addcmd:14;
    };
}dc_sys_dc_mtex_addcmd_hi0_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mtex_addcmd_lo_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mtex_addcmd_sa_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_mtex_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_mtex_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_mtex_int_enable_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_mtex_int_status_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_mtex_int_enable_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  write_data:1;
    };
}dc_sys_dc_mtex_int_status_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sf_tx_mode_disram:1;
        RBus_UInt32  sf_tx_mode_gpu:1;
        RBus_UInt32  dummy18007800_8_6:3;
        RBus_UInt32  sf_tx_mode_se2:1;
        RBus_UInt32  dummy18007800_4:1;
        RBus_UInt32  sf_tx_mode_tvsb2:1;
        RBus_UInt32  sf_tx_mode_tvsb4:1;
        RBus_UInt32  sf_tx_mode_tvsb5:1;
        RBus_UInt32  sf_tx_mode_ve:1;
    };
}dc_sys_dc_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sf_tx_work_ro_disram:1;
        RBus_UInt32  sf_tx_work_ro_gpu:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_tx_work_ro_se2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_tx_work_ro_tvsb2:1;
        RBus_UInt32  sf_tx_work_ro_tvsb4:1;
        RBus_UInt32  sf_tx_work_ro_tvsb5:1;
        RBus_UInt32  sf_tx_work_ro_ve:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  sf_tx_start_disram:1;
        RBus_UInt32  sf_tx_start_gpu:1;
        RBus_UInt32  dummy18007804_8_6:3;
        RBus_UInt32  sf_tx_start_se2:1;
        RBus_UInt32  dummy18007804_4:1;
        RBus_UInt32  sf_tx_start_tvsb2:1;
        RBus_UInt32  sf_tx_start_tvsb4:1;
        RBus_UInt32  sf_tx_start_tvsb5:1;
        RBus_UInt32  sf_tx_start_ve:1;
    };
}dc_sys_dc_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sf_rx_gated_disram:1;
        RBus_UInt32  sf_rx_gated_gpu:1;
        RBus_UInt32  dummy18007808_24_22:3;
        RBus_UInt32  sf_rx_gated_se2:1;
        RBus_UInt32  dummy18007808_20:1;
        RBus_UInt32  sf_rx_gated_tvsb2:1;
        RBus_UInt32  sf_rx_gated_tvsb4:1;
        RBus_UInt32  sf_rx_gated_tvsb5:1;
        RBus_UInt32  sf_rx_gated_ve:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  sf_rx_mode_disram:1;
        RBus_UInt32  sf_rx_mode_gpu:1;
        RBus_UInt32  dummy18007808_8_6:3;
        RBus_UInt32  sf_rx_mode_se2:1;
        RBus_UInt32  dummy18007808_4:1;
        RBus_UInt32  sf_rx_mode_tvsb2:1;
        RBus_UInt32  sf_rx_mode_tvsb4:1;
        RBus_UInt32  sf_rx_mode_tvsb5:1;
        RBus_UInt32  sf_rx_mode_ve:1;
    };
}dc_sys_dc_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  sf_rx_done_ro_disram:1;
        RBus_UInt32  sf_rx_done_ro_gpu:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_rx_done_ro_se2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_rx_done_ro_tvsb2:1;
        RBus_UInt32  sf_rx_done_ro_tvsb4:1;
        RBus_UInt32  sf_rx_done_ro_tvsb5:1;
        RBus_UInt32  sf_rx_done_ro_ve:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  sf_rx_start_disram:1;
        RBus_UInt32  sf_rx_start_gpu:1;
        RBus_UInt32  dummy1800780c_8_6:3;
        RBus_UInt32  sf_rx_start_se2:1;
        RBus_UInt32  dummy1800780c_4:1;
        RBus_UInt32  sf_rx_start_tvsb2:1;
        RBus_UInt32  sf_rx_start_tvsb4:1;
        RBus_UInt32  sf_rx_start_tvsb5:1;
        RBus_UInt32  sf_rx_start_ve:1;
    };
}dc_sys_dc_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  sf_rx_err_ro_disram:1;
        RBus_UInt32  sf_rx_err_ro_gpu:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_rx_err_ro_se2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sf_rx_err_ro_tvsb2:1;
        RBus_UInt32  sf_rx_err_ro_tvsb4:1;
        RBus_UInt32  sf_rx_err_ro_tvsb5:1;
        RBus_UInt32  sf_rx_err_ro_ve:1;
    };
}dc_sys_dc_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ts_dbg_sel:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  ts_dbg_out:10;
    };
}dc_sys_dc_ts_dbg_RBUS;

#else //apply LITTLE_ENDIAN

//======DC_SYS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_init_page:17;
        RBus_UInt32  pict_width_scale:6;
        RBus_UInt32  res1:9;
    };
}dc_sys_dc_pict_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_2ddr_diff_size:1;
        RBus_UInt32  dummy18007004_3:3;
        RBus_UInt32  small_dram_512m:1;
        RBus_UInt32  small_dram_1g:1;
        RBus_UInt32  small_dram_2g:1;
        RBus_UInt32  small_dram_4g:1;
        RBus_UInt32  en_max_bl_limit:1;
        RBus_UInt32  max_bl_size:1;
        RBus_UInt32  en_bank_scr:1;
        RBus_UInt32  bank_scr_256:1;
        RBus_UInt32  dummy18007004_15:4;
        RBus_UInt32  page_size:2;
        RBus_UInt32  dis_8x2to16x1_dummy:1;
        RBus_UInt32  mem_num:1;
        RBus_UInt32  self_lookback_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  arb_mask_all_en:1;
        RBus_UInt32  pre_arb_scheme_sel:1;
        RBus_UInt32  dram_2g_used:1;
        RBus_UInt32  ddr3_512_used:1;
        RBus_UInt32  dram_4g_used:1;
        RBus_UInt32  dram_8g_used:1;
        RBus_UInt32  res2:3;
    };
}dc_sys_dc_sys_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:31;
    };
}dc_sys_dc_pic_offset_x_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pict_set_offset_x:10;
        RBus_UInt32  pict_set_offset_y:10;
        RBus_UInt32  pict_set_wide:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pict_offset_rd:1;
        RBus_UInt32  pict_set_num:8;
    };
}dc_sys_dc_pict_set_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_id:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  req_pending:1;
        RBus_UInt32  res2:15;
    };
}dc_sys_dc_req_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  full_cmd_count:4;
        RBus_UInt32  qfifo_cnt_full_threshold:3;
        RBus_UInt32  res1:4;
        RBus_UInt32  pre_arb_merge:1;
    };
}dc_sys_dc_sys_misc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpu_cmd_grp_disable:1;
        RBus_UInt32  gpu_cmd_queue_flush:1;
        RBus_UInt32  enable_arb_delay_by_tv_sb1_grant:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tvsb3_cmd_grp_disable:1;
        RBus_UInt32  tvsb3_cmd_queue_flush:1;
        RBus_UInt32  tvsb4_cmd_grp_disable:1;
        RBus_UInt32  tvsb4_cmd_queue_flush:1;
        RBus_UInt32  ve_cmd_grp_disable:1;
        RBus_UInt32  ve_cmd_queue_flush:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  ve2_cmd_grp_disable:1;
        RBus_UInt32  ve2_cmd_queue_flush:1;
        RBus_UInt32  se2_cmd_grp_disable:1;
        RBus_UInt32  se2_cmd_queue_flush:1;
        RBus_UInt32  memc_cmd_grp_disable:1;
        RBus_UInt32  memc_cmd_queue_flush:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  wfifo_cnt_full_threshold:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  ve_id_gen_en:1;
        RBus_UInt32  ve2_id_gen_en:1;
    };
}dc_sys_dc_sys_misc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpu_space_margin:4;
        RBus_UInt32  tvsb3_space_margin:4;
        RBus_UInt32  tvsb4_space_margin:4;
        RBus_UInt32  ve_space_margin:4;
        RBus_UInt32  ve2_space_margin:4;
        RBus_UInt32  se2_space_margin:4;
        RBus_UInt32  memc_space_margin:4;
        RBus_UInt32  res1:4;
    };
}dc_sys_dc_sys_misc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern0:32;
    };
}dc_sys_dc_sfmode0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern1:32;
    };
}dc_sys_dc_sfmode1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern2:32;
    };
}dc_sys_dc_sfmode2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_pattern3:32;
    };
}dc_sys_dc_sfmode3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt0:32;
    };
}dc_sys_dc_sfmode_cmp0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt1:32;
    };
}dc_sys_dc_sfmode_cmp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt2:32;
    };
}dc_sys_dc_sfmode_cmp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sfmode_cmp_rlt3:32;
    };
}dc_sys_dc_sfmode_cmp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_sel_0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  debug_sel_1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  debug_en:1;
        RBus_UInt32  debug_sys_sel:2;
        RBus_UInt32  res3:13;
    };
}dc_sys_dc_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sys_out0:16;
        RBus_UInt32  dbg_sys_out1:16;
    };
}dc_sys_dc_debug_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_fifo_0_overflow:1;
        RBus_UInt32  read_fifo_1_overflow:1;
        RBus_UInt32  read_fifo_2_overflow:1;
        RBus_UInt32  write_fifo_0_overflow:1;
        RBus_UInt32  write_fifo_1_overflow:1;
        RBus_UInt32  write_fifo_2_overflow:1;
        RBus_UInt32  read_fifo_0_underflow:1;
        RBus_UInt32  read_fifo_1_underflow:1;
        RBus_UInt32  read_fifo_2_underflow:1;
        RBus_UInt32  write_fifo_0_underflow:1;
        RBus_UInt32  write_fifo_1_underflow:1;
        RBus_UInt32  write_fifo_2_underflow:1;
        RBus_UInt32  read_cmd_fifo_0_overflow:1;
        RBus_UInt32  read_cmd_fifo_1_overflow:1;
        RBus_UInt32  read_cmd_fifo_2_overflow:1;
        RBus_UInt32  write_cmd_fifo_0_overflow:1;
        RBus_UInt32  write_cmd_fifo_1_overflow:1;
        RBus_UInt32  write_cmd_fifo_2_overflow:1;
        RBus_UInt32  read_cmd_fifo_0_underflow:1;
        RBus_UInt32  read_cmd_fifo_1_underflow:1;
        RBus_UInt32  read_cmd_fifo_2_underflow:1;
        RBus_UInt32  write_cmd_fifo_0_underflow:1;
        RBus_UInt32  write_cmd_fifo_1_underflow:1;
        RBus_UInt32  write_cmd_fifo_2_underflow:1;
        RBus_UInt32  exsram_fifo_overflow:1;
        RBus_UInt32  exsram_fifo_underflow:1;
        RBus_UInt32  res1:6;
    };
}dc_sys_dc_debug_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c8_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c8_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c9_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  c9_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrl9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ca_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  ca_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrla_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cb_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cb_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrlb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cc_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cc_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_priority_ctrlc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  latcnt_period:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  hie_cmp_dis:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  gpu_lat_new:1;
    };
}dc_sys_dc_priority_ctrl_hie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  req_mask_index:13;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_client_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pc_rcmd_only:1;
    };
}dc_sys_dc_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}dc_sys_dc_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}dc_sys_dc_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}dc_sys_dc_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pc_sysh_prog0_sel:4;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pc_sysh_prog1_sel:4;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pc_sysh_prog2_sel:4;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res4:8;
    };
}dc_sys_dc_pc_sysh_prog_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pc_sysh_prog0_req_occur:1;
        RBus_UInt32  pc_sysh_prog1_req_occur:1;
        RBus_UInt32  pc_sysh_prog2_req_occur:1;
        RBus_UInt32  res2:25;
    };
}dc_sys_dc_pc_sys_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_acc_lat:32;
    };
}dc_sys_dc_pc_sysh_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc_sys_dc_pc_sysh_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc_sys_dc_pc_sysh_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog0_ack_num:32;
    };
}dc_sys_dc_pc_sysh_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_acc_lat:32;
    };
}dc_sys_dc_pc_sysh_prog_1_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc_sys_dc_pc_sysh_prog_1_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc_sys_dc_pc_sysh_prog_1_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog1_ack_num:32;
    };
}dc_sys_dc_pc_sysh_prog_1_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_acc_lat:32;
    };
}dc_sys_dc_pc_sysh_prog_2_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_max_lat:16;
        RBus_UInt32  res1:16;
    };
}dc_sys_dc_pc_sysh_prog_2_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_req_num:24;
        RBus_UInt32  res1:8;
    };
}dc_sys_dc_pc_sysh_prog_2_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh_prog2_ack_num:32;
    };
}dc_sys_dc_pc_sysh_prog_2_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_num_in_cti_q_prog0:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  cmd_num_in_cti_q_prog1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  cmd_num_in_cti_q_prog2:5;
        RBus_UInt32  res3:11;
    };
}dc_sys_dc_pc_sysh_prog_cti_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remain_cmd_num0_prog0:8;
        RBus_UInt32  remain_cmd_num0_prog1:8;
        RBus_UInt32  remain_cmd_num0_prog2:8;
        RBus_UInt32  res1:8;
    };
}dc_sys_dc_pc_sysh_prog_cmd_num_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  remain_cmd_num1_prog0:8;
        RBus_UInt32  remain_cmd_num1_prog1:8;
        RBus_UInt32  remain_cmd_num1_prog2:8;
        RBus_UInt32  res1:8;
    };
}dc_sys_dc_pc_sysh_prog_cmd_num_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh0_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc_sys_dc_pc_sysh_prog_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh1_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc_sys_dc_pc_sysh_prog_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sysh2_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}dc_sys_dc_pc_sysh_prog_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_bist_mode_pict0:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:27;
    };
}dc_sys_dc_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_bist_done_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_bist_fail_group_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_mode_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist_drf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_resume_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_done_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist0_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_pause_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dc_drf_fail_group_pict0:1;
        RBus_UInt32  res2:30;
    };
}dc_sys_dc_bist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dc_bist_pict_fail0:1;
        RBus_UInt32  dc_drf_pict_fail0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:24;
    };
}dc_sys_dc_bist_detail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:24;
    };
}dc_sys_dc_bist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg0:32;
    };
}dc_sys_dc_dummy_reg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg1:32;
    };
}dc_sys_dc_dummy_reg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg2:32;
    };
}dc_sys_dc_dummy_reg2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_reg3:32;
    };
}dc_sys_dc_dummy_reg3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mem_type:2;
    };
}dc_sys_dc_mt_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_mt_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_mt_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_dc_mt_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_3:8;
        RBus_UInt32  module_id_2:8;
        RBus_UInt32  module_id_1:8;
        RBus_UInt32  module_id_0:8;
    };
}dc_sys_dc_mt_table_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:8;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  access_type_3:2;
        RBus_UInt32  access_type_2:2;
        RBus_UInt32  access_type_1:2;
        RBus_UInt32  access_type_0:2;
    };
}dc_sys_dc_mt_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mt_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mt_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disable_cross_range_check:1;
        RBus_UInt32  res1:31;
    };
}dc_sys_dc_mt_misc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_cmd_detection_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  error_cmd_swap_en:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  error_cmd_swap_addr:27;
        RBus_UInt32  write_enable3:1;
    };
}dc_sys_dc_ec_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:23;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
    };
}dc_sys_dc_ec_addcmd_hi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_sys_dc_ec_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tag_check_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  err_blk_err_dis:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:28;
    };
}dc_sys_dc_rd_tag_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  err_blk_err_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  pic_offset_x_odd_int_en:1;
        RBus_UInt32  res2:7;
    };
}dc_sys_dc_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  err_blk_err_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  pic_offset_x_odd_int:1;
        RBus_UInt32  res2:7;
    };
}dc_sys_dc_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_mode:26;
        RBus_UInt32  res1:5;
        RBus_UInt32  bypass_req_to_arb:1;
    };
}dc_sys_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}dc_sys_bw_timer_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:24;
        RBus_UInt32  res1:8;
    };
}dc_sys_bw_request_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tv_sb2_mux:1;
        RBus_UInt32  tv_sb4_mux:1;
        RBus_UInt32  memc_mux:1;
        RBus_UInt32  tv_sb1_mux:1;
        RBus_UInt32  tv_sb5_mux:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  res3:2;
    };
}dc_sys_dc_sys2_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:8;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:9;
    };
}dc_sys_dc_mt_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mt_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mt_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:23;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
    };
}dc_sys_dc_ec_addcmd_hi_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_sys_dc_ec_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  err_blk_err_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_int_enable_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  err_blk_err_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_int_status_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_mux:1;
        RBus_UInt32  ve2_mux:1;
        RBus_UInt32  tv_sb3_mux:1;
        RBus_UInt32  se2_mux:1;
        RBus_UInt32  gpu_mux:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pre_tra_wr_cnt:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pre_tra_rd_cnt:10;
        RBus_UInt32  res3:2;
    };
}dc_sys_dc_sys3_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:8;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:9;
    };
}dc_sys_dc_mt_addcmd_hi_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mt_addcmd_lo_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mt_addcmd_sa_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_hi:23;
        RBus_UInt32  trap_case:8;
        RBus_UInt32  error_cmd_ever_trap:1;
    };
}dc_sys_dc_ec_addcmd_hi_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd_lo:32;
    };
}dc_sys_dc_ec_addcmd_lo_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  err_blk_err_int_en:1;
        RBus_UInt32  err_blk_w_zero_int_en:1;
        RBus_UInt32  err_blk_h_zero_int_en:1;
        RBus_UInt32  err_blk_size_exceed_int_en:1;
        RBus_UInt32  err_blk_8x2_on_64_int_en:1;
        RBus_UInt32  err_seq_bl_odd_int_en:1;
        RBus_UInt32  err_seq_bl_zero_int_en:1;
        RBus_UInt32  err_seq_sa_odd_int_en:1;
        RBus_UInt32  rd_tag_mismatch_int_en:1;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_int_enable_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  err_blk_err_int:1;
        RBus_UInt32  err_blk_w_zero_int:1;
        RBus_UInt32  err_blk_h_zero_int:1;
        RBus_UInt32  err_blk_size_exceed_int:1;
        RBus_UInt32  err_blk_8x2_on_64_int:1;
        RBus_UInt32  err_seq_bl_odd_int:1;
        RBus_UInt32  err_seq_bl_zero_int:1;
        RBus_UInt32  err_seq_sa_odd_int:1;
        RBus_UInt32  rd_tag_mismatch_int:1;
        RBus_UInt32  res2:8;
    };
}dc_sys_dc_int_status_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  mem_type:2;
    };
}dc_sys_dc_mtex_type_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  saddr:26;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_mtex_saddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  eaddr:26;
        RBus_UInt32  res2:1;
    };
}dc_sys_dc_mtex_eaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode:2;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_dc_mtex_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_3:8;
        RBus_UInt32  module_id_2:8;
        RBus_UInt32  module_id_1:8;
        RBus_UInt32  module_id_0:8;
    };
}dc_sys_dc_mtex_table0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  module_id_7:8;
        RBus_UInt32  module_id_6:8;
        RBus_UInt32  module_id_5:8;
        RBus_UInt32  module_id_4:8;
    };
}dc_sys_dc_mtex_table1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:8;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  access_type_3:2;
        RBus_UInt32  access_type_2:2;
        RBus_UInt32  access_type_1:2;
        RBus_UInt32  access_type_0:2;
    };
}dc_sys_dc_mtex_addcmd_hi0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  access_type_7:2;
        RBus_UInt32  access_type_6:2;
        RBus_UInt32  access_type_5:2;
        RBus_UInt32  access_type_4:2;
    };
}dc_sys_dc_mtex_addcmd_hi1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mtex_addcmd_lo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mtex_addcmd_sa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:8;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:9;
    };
}dc_sys_dc_mtex_addcmd_hi0_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mtex_addcmd_lo_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mtex_addcmd_sa_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:14;
        RBus_UInt32  module_id:8;
        RBus_UInt32  ever_trap:1;
        RBus_UInt32  res1:9;
    };
}dc_sys_dc_mtex_addcmd_hi0_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addcmd:32;
    };
}dc_sys_dc_mtex_addcmd_lo_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  trap_seq_sa:32;
    };
}dc_sys_dc_mtex_addcmd_sa_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_mtex_int_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_mtex_int_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_mtex_int_enable_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_mtex_int_status_sys2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int_en:1;
        RBus_UInt32  mt_0_mod2_int_en:1;
        RBus_UInt32  mt_0_mod3_int_en:1;
        RBus_UInt32  mt_1_mod1_int_en:1;
        RBus_UInt32  mt_1_mod2_int_en:1;
        RBus_UInt32  mt_1_mod3_int_en:1;
        RBus_UInt32  mt_2_mod1_int_en:1;
        RBus_UInt32  mt_2_mod2_int_en:1;
        RBus_UInt32  mt_2_mod3_int_en:1;
        RBus_UInt32  mt_3_mod1_int_en:1;
        RBus_UInt32  mt_3_mod2_int_en:1;
        RBus_UInt32  mt_3_mod3_int_en:1;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_mtex_int_enable_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  mt_0_mod1_int:1;
        RBus_UInt32  mt_0_mod2_int:1;
        RBus_UInt32  mt_0_mod3_int:1;
        RBus_UInt32  mt_1_mod1_int:1;
        RBus_UInt32  mt_1_mod2_int:1;
        RBus_UInt32  mt_1_mod3_int:1;
        RBus_UInt32  mt_2_mod1_int:1;
        RBus_UInt32  mt_2_mod2_int:1;
        RBus_UInt32  mt_2_mod3_int:1;
        RBus_UInt32  mt_3_mod1_int:1;
        RBus_UInt32  mt_3_mod2_int:1;
        RBus_UInt32  mt_3_mod3_int:1;
        RBus_UInt32  res1:19;
    };
}dc_sys_dc_mtex_int_status_sys3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_mode_ve:1;
        RBus_UInt32  sf_tx_mode_tvsb5:1;
        RBus_UInt32  sf_tx_mode_tvsb4:1;
        RBus_UInt32  sf_tx_mode_tvsb2:1;
        RBus_UInt32  dummy18007800_4:1;
        RBus_UInt32  sf_tx_mode_se2:1;
        RBus_UInt32  dummy18007800_8:3;
        RBus_UInt32  sf_tx_mode_gpu:1;
        RBus_UInt32  sf_tx_mode_disram:1;
        RBus_UInt32  res1:21;
    };
}dc_sys_dc_sftx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_tx_start_ve:1;
        RBus_UInt32  sf_tx_start_tvsb5:1;
        RBus_UInt32  sf_tx_start_tvsb4:1;
        RBus_UInt32  sf_tx_start_tvsb2:1;
        RBus_UInt32  dummy18007804_4:1;
        RBus_UInt32  sf_tx_start_se2:1;
        RBus_UInt32  dummy18007804_8:3;
        RBus_UInt32  sf_tx_start_gpu:1;
        RBus_UInt32  sf_tx_start_disram:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  sf_tx_work_ro_ve:1;
        RBus_UInt32  sf_tx_work_ro_tvsb5:1;
        RBus_UInt32  sf_tx_work_ro_tvsb4:1;
        RBus_UInt32  sf_tx_work_ro_tvsb2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_tx_work_ro_se2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sf_tx_work_ro_gpu:1;
        RBus_UInt32  sf_tx_work_ro_disram:1;
        RBus_UInt32  res4:5;
    };
}dc_sys_dc_sftx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_mode_ve:1;
        RBus_UInt32  sf_rx_mode_tvsb5:1;
        RBus_UInt32  sf_rx_mode_tvsb4:1;
        RBus_UInt32  sf_rx_mode_tvsb2:1;
        RBus_UInt32  dummy18007808_4:1;
        RBus_UInt32  sf_rx_mode_se2:1;
        RBus_UInt32  dummy18007808_8:3;
        RBus_UInt32  sf_rx_mode_gpu:1;
        RBus_UInt32  sf_rx_mode_disram:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  sf_rx_gated_ve:1;
        RBus_UInt32  sf_rx_gated_tvsb5:1;
        RBus_UInt32  sf_rx_gated_tvsb4:1;
        RBus_UInt32  sf_rx_gated_tvsb2:1;
        RBus_UInt32  dummy18007808_20:1;
        RBus_UInt32  sf_rx_gated_se2:1;
        RBus_UInt32  dummy18007808_24:3;
        RBus_UInt32  sf_rx_gated_gpu:1;
        RBus_UInt32  sf_rx_gated_disram:1;
        RBus_UInt32  res2:5;
    };
}dc_sys_dc_sfrx_test0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_start_ve:1;
        RBus_UInt32  sf_rx_start_tvsb5:1;
        RBus_UInt32  sf_rx_start_tvsb4:1;
        RBus_UInt32  sf_rx_start_tvsb2:1;
        RBus_UInt32  dummy1800780c_4:1;
        RBus_UInt32  sf_rx_start_se2:1;
        RBus_UInt32  dummy1800780c_8:3;
        RBus_UInt32  sf_rx_start_gpu:1;
        RBus_UInt32  sf_rx_start_disram:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  sf_rx_done_ro_ve:1;
        RBus_UInt32  sf_rx_done_ro_tvsb5:1;
        RBus_UInt32  sf_rx_done_ro_tvsb4:1;
        RBus_UInt32  sf_rx_done_ro_tvsb2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sf_rx_done_ro_se2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sf_rx_done_ro_gpu:1;
        RBus_UInt32  sf_rx_done_ro_disram:1;
        RBus_UInt32  res4:5;
    };
}dc_sys_dc_sfrx_test1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sf_rx_err_ro_ve:1;
        RBus_UInt32  sf_rx_err_ro_tvsb5:1;
        RBus_UInt32  sf_rx_err_ro_tvsb4:1;
        RBus_UInt32  sf_rx_err_ro_tvsb2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sf_rx_err_ro_se2:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sf_rx_err_ro_gpu:1;
        RBus_UInt32  sf_rx_err_ro_disram:1;
        RBus_UInt32  res3:21;
    };
}dc_sys_dc_sfrx_test2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_dbg_out:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ts_dbg_sel:4;
        RBus_UInt32  res2:12;
    };
}dc_sys_dc_ts_dbg_RBUS;




#endif 
#endif 
