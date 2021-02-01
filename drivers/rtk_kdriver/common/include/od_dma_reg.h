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

#ifndef _RBUS_OD_DMA_REG_H_
#define _RBUS_OD_DMA_REG_H_

#include "rbus_types.h"



//  OD_DMA Register Address
#define  OD_DMA_ODDMA_PQ_CMP                                                     0x1802CD00
#define  OD_DMA_ODDMA_PQ_CMP_reg_addr                                            "0xB802CD00"
#define  OD_DMA_ODDMA_PQ_CMP_reg                                                 0xB802CD00
#define  OD_DMA_ODDMA_PQ_CMP_inst_addr                                           "0x0000"
#define  set_OD_DMA_ODDMA_PQ_CMP_reg(data)                                       (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_reg                                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_reg))
#define  OD_DMA_ODDMA_PQ_CMP_cmp_en_shift                                        (31)
#define  OD_DMA_ODDMA_PQ_CMP_cmp_width_div32_shift                               (16)
#define  OD_DMA_ODDMA_PQ_CMP_cmp_height_shift                                    (0)
#define  OD_DMA_ODDMA_PQ_CMP_cmp_en_mask                                         (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_cmp_width_div32_mask                                (0x01FF0000)
#define  OD_DMA_ODDMA_PQ_CMP_cmp_height_mask                                     (0x00003FFF)
#define  OD_DMA_ODDMA_PQ_CMP_cmp_en(data)                                        (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_cmp_width_div32(data)                               (0x01FF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_cmp_height(data)                                    (0x00003FFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_get_cmp_en(data)                                    ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_get_cmp_width_div32(data)                           ((0x01FF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_get_cmp_height(data)                                (0x00003FFF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_PAIR                                                0x1802CD04
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_reg_addr                                       "0xB802CD04"
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_reg                                            0xB802CD04
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_inst_addr                                      "0x0001"
#define  set_OD_DMA_ODDMA_PQ_CMP_PAIR_reg(data)                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_PAIR_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_PAIR_reg                                        (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_PAIR_reg))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_dummy_31_shift                                 (31)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_eco_reg_vsync_no_req_shift                     (30)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_dummy_29_5_shift                               (5)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_color_shift                           (4)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_bit_width_shift                       (2)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_format_shift                          (0)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_dummy_31_mask                                  (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_eco_reg_vsync_no_req_mask                      (0x40000000)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_dummy_29_5_mask                                (0x3FFFFFE0)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_color_mask                            (0x00000010)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_bit_width_mask                        (0x0000000C)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_format_mask                           (0x00000003)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_dummy_31(data)                                 (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_eco_reg_vsync_no_req(data)                     (0x40000000&((data)<<30))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_dummy_29_5(data)                               (0x3FFFFFE0&((data)<<5))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_color(data)                           (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_bit_width(data)                       (0x0000000C&((data)<<2))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_cmp_data_format(data)                          (0x00000003&(data))
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_get_dummy_31(data)                             ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_get_eco_reg_vsync_no_req(data)                 ((0x40000000&(data))>>30)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_get_dummy_29_5(data)                           ((0x3FFFFFE0&(data))>>5)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_get_cmp_data_color(data)                       ((0x00000010&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_get_cmp_data_bit_width(data)                   ((0x0000000C&(data))>>2)
#define  OD_DMA_ODDMA_PQ_CMP_PAIR_get_cmp_data_format(data)                      (0x00000003&(data))

#define  OD_DMA_ODDMA_PQ_CMP_BIT                                                 0x1802CD08
#define  OD_DMA_ODDMA_PQ_CMP_BIT_reg_addr                                        "0xB802CD08"
#define  OD_DMA_ODDMA_PQ_CMP_BIT_reg                                             0xB802CD08
#define  OD_DMA_ODDMA_PQ_CMP_BIT_inst_addr                                       "0x0002"
#define  set_OD_DMA_ODDMA_PQ_CMP_BIT_reg(data)                                   (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_BIT_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_BIT_reg                                         (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_BIT_reg))
#define  OD_DMA_ODDMA_PQ_CMP_BIT_first_line_more_bit_shift                       (24)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_block_limit_bit_shift                           (16)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_line_limit_bit_shift                            (8)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_frame_limit_bit_shift                           (0)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_first_line_more_bit_mask                        (0x3F000000)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_block_limit_bit_mask                            (0x003F0000)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_line_limit_bit_mask                             (0x00003F00)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_frame_limit_bit_mask                            (0x0000003F)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_first_line_more_bit(data)                       (0x3F000000&((data)<<24))
#define  OD_DMA_ODDMA_PQ_CMP_BIT_block_limit_bit(data)                           (0x003F0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_BIT_line_limit_bit(data)                            (0x00003F00&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_BIT_frame_limit_bit(data)                           (0x0000003F&(data))
#define  OD_DMA_ODDMA_PQ_CMP_BIT_get_first_line_more_bit(data)                   ((0x3F000000&(data))>>24)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_get_block_limit_bit(data)                       ((0x003F0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_get_line_limit_bit(data)                        ((0x00003F00&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_BIT_get_frame_limit_bit(data)                       (0x0000003F&(data))

#define  OD_DMA_ODDMA_PQ_CMP_ENABLE                                              0x1802CD0C
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_reg_addr                                     "0xB802CD0C"
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_reg                                          0xB802CD0C
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_inst_addr                                    "0x0003"
#define  set_OD_DMA_ODDMA_PQ_CMP_ENABLE_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_ENABLE_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_ENABLE_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_ENABLE_reg))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_g_ratio_shift                                (16)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_guarantee_max_qp_en_shift                    (11)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_dynamic_allocate_ratio_en_shift              (10)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_poor_limit_min_qp_en_shift                   (9)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_balance_en_shift                             (8)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_fisrt_line_more_en_shift                     (7)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_two_line_prediction_en_shift                 (6)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_do_422_mode_shift                            (4)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_not_enough_bit_do_422_en_shift               (2)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_not_rich_do_422_en_shift                     (1)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_rb_lossy_do_422_en_shift                     (0)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_g_ratio_mask                                 (0x001F0000)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_guarantee_max_qp_en_mask                     (0x00000800)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_dynamic_allocate_ratio_en_mask               (0x00000400)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_poor_limit_min_qp_en_mask                    (0x00000200)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_balance_en_mask                              (0x00000100)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_fisrt_line_more_en_mask                      (0x00000080)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_two_line_prediction_en_mask                  (0x00000040)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_do_422_mode_mask                             (0x00000030)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_not_enough_bit_do_422_en_mask                (0x00000004)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_not_rich_do_422_en_mask                      (0x00000002)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_rb_lossy_do_422_en_mask                      (0x00000001)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_g_ratio(data)                                (0x001F0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_guarantee_max_qp_en(data)                    (0x00000800&((data)<<11))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_dynamic_allocate_ratio_en(data)              (0x00000400&((data)<<10))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_poor_limit_min_qp_en(data)                   (0x00000200&((data)<<9))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_balance_en(data)                             (0x00000100&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_fisrt_line_more_en(data)                     (0x00000080&((data)<<7))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_two_line_prediction_en(data)                 (0x00000040&((data)<<6))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_do_422_mode(data)                            (0x00000030&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_not_enough_bit_do_422_en(data)               (0x00000004&((data)<<2))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_not_rich_do_422_en(data)                     (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_rb_lossy_do_422_en(data)                     (0x00000001&(data))
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_g_ratio(data)                            ((0x001F0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_guarantee_max_qp_en(data)                ((0x00000800&(data))>>11)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_dynamic_allocate_ratio_en(data)          ((0x00000400&(data))>>10)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_poor_limit_min_qp_en(data)               ((0x00000200&(data))>>9)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_balance_en(data)                         ((0x00000100&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_fisrt_line_more_en(data)                 ((0x00000080&(data))>>7)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_two_line_prediction_en(data)             ((0x00000040&(data))>>6)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_do_422_mode(data)                        ((0x00000030&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_not_enough_bit_do_422_en(data)           ((0x00000004&(data))>>2)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_not_rich_do_422_en(data)                 ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_PQ_CMP_ENABLE_get_rb_lossy_do_422_en(data)                 (0x00000001&(data))

#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH                                              0x1802CD10
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_reg_addr                                     "0xB802CD10"
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_reg                                          0xB802CD10
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_inst_addr                                    "0x0004"
#define  set_OD_DMA_ODDMA_PQ_CMP_SMOOTH_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_SMOOTH_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_SMOOTH_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_SMOOTH_reg))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_not_enough_bit_do_422_qp_shift               (24)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_not_rich_do_422_th_shift                     (20)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_rb_lossy_do_422_qp_level_shift               (16)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_value_th_shift                     (8)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_num_th_shift                       (4)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_near_num_th_shift                  (0)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_not_enough_bit_do_422_qp_mask                (0x07000000)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_not_rich_do_422_th_mask                      (0x00F00000)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_rb_lossy_do_422_qp_level_mask                (0x00070000)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_value_th_mask                      (0x00000F00)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_num_th_mask                        (0x00000070)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_near_num_th_mask                   (0x00000007)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_not_enough_bit_do_422_qp(data)               (0x07000000&((data)<<24))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_not_rich_do_422_th(data)                     (0x00F00000&((data)<<20))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_rb_lossy_do_422_qp_level(data)               (0x00070000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_value_th(data)                     (0x00000F00&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_num_th(data)                       (0x00000070&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_variation_near_num_th(data)                  (0x00000007&(data))
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_get_not_enough_bit_do_422_qp(data)           ((0x07000000&(data))>>24)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_get_not_rich_do_422_th(data)                 ((0x00F00000&(data))>>20)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_get_rb_lossy_do_422_qp_level(data)           ((0x00070000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_get_variation_value_th(data)                 ((0x00000F00&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_get_variation_num_th(data)                   ((0x00000070&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_SMOOTH_get_variation_near_num_th(data)              (0x00000007&(data))

#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE                                            0x1802CD14
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_reg_addr                                   "0xB802CD14"
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_reg                                        0xB802CD14
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_inst_addr                                  "0x0005"
#define  set_OD_DMA_ODDMA_PQ_CMP_ALLOCATE_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_ALLOCATE_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_ALLOCATE_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_ALLOCATE_reg))
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_max_shift           (24)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_min_shift           (16)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_line_shift                (8)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_more_shift                (4)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_less_shift                (0)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_max_mask            (0x1F000000)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_min_mask            (0x001F0000)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_line_mask                 (0x00000700)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_more_mask                 (0x000000F0)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_less_mask                 (0x0000000F)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_max(data)           (0x1F000000&((data)<<24))
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_min(data)           (0x001F0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_line(data)                (0x00000700&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_more(data)                (0x000000F0&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_dynamic_allocate_less(data)                (0x0000000F&(data))
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_get_dynamic_allocate_ratio_max(data)       ((0x1F000000&(data))>>24)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_get_dynamic_allocate_ratio_min(data)       ((0x001F0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_get_dynamic_allocate_line(data)            ((0x00000700&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_get_dynamic_allocate_more(data)            ((0x000000F0&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_ALLOCATE_get_dynamic_allocate_less(data)            (0x0000000F&(data))

#define  OD_DMA_ODDMA_PQ_CMP_POOR                                                0x1802CD18
#define  OD_DMA_ODDMA_PQ_CMP_POOR_reg_addr                                       "0xB802CD18"
#define  OD_DMA_ODDMA_PQ_CMP_POOR_reg                                            0xB802CD18
#define  OD_DMA_ODDMA_PQ_CMP_POOR_inst_addr                                      "0x0006"
#define  set_OD_DMA_ODDMA_PQ_CMP_POOR_reg(data)                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_POOR_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_POOR_reg                                        (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_POOR_reg))
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp4_shift                        (24)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp3_shift                        (16)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp2_shift                        (8)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp1_shift                        (0)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp4_mask                         (0x1F000000)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp3_mask                         (0x001F0000)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp2_mask                         (0x00001F00)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp1_mask                         (0x0000001F)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp4(data)                        (0x1F000000&((data)<<24))
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp3(data)                        (0x001F0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp2(data)                        (0x00001F00&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_POOR_poor_limit_th_qp1(data)                        (0x0000001F&(data))
#define  OD_DMA_ODDMA_PQ_CMP_POOR_get_poor_limit_th_qp4(data)                    ((0x1F000000&(data))>>24)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_get_poor_limit_th_qp3(data)                    ((0x001F0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_get_poor_limit_th_qp2(data)                    ((0x00001F00&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_POOR_get_poor_limit_th_qp1(data)                    (0x0000001F&(data))

#define  OD_DMA_ODDMA_PQ_CMP_Guarantee                                           0x1802CD1C
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_reg_addr                                  "0xB802CD1C"
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_reg                                       0xB802CD1C
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_inst_addr                                 "0x0007"
#define  set_OD_DMA_ODDMA_PQ_CMP_Guarantee_reg(data)                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_Guarantee_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_Guarantee_reg                                   (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_Guarantee_reg))
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_guarantee_max_rb_qp_shift                 (4)
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_guarantee_max_g_qp_shift                  (0)
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_guarantee_max_rb_qp_mask                  (0x000000F0)
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_guarantee_max_g_qp_mask                   (0x0000000F)
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_guarantee_max_rb_qp(data)                 (0x000000F0&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_guarantee_max_g_qp(data)                  (0x0000000F&(data))
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_get_guarantee_max_rb_qp(data)             ((0x000000F0&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_Guarantee_get_guarantee_max_g_qp(data)              (0x0000000F&(data))

#define  OD_DMA_ODDMA_PQ_CMP_BALANCE                                             0x1802CD20
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_reg_addr                                    "0xB802CD20"
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_reg                                         0xB802CD20
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_inst_addr                                   "0x0008"
#define  set_OD_DMA_ODDMA_PQ_CMP_BALANCE_reg(data)                               (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_BALANCE_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_BALANCE_reg                                     (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_BALANCE_reg))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_ov_th_shift                      (12)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_ud_th_shift                      (10)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_give_shift                       (8)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_ov_th_shift                       (4)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_ud_th_shift                       (2)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_give_shift                        (0)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_ov_th_mask                       (0x00003000)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_ud_th_mask                       (0x00000C00)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_give_mask                        (0x00000300)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_ov_th_mask                        (0x00000030)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_ud_th_mask                        (0x0000000C)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_give_mask                         (0x00000003)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_ov_th(data)                      (0x00003000&((data)<<12))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_ud_th(data)                      (0x00000C00&((data)<<10))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_rb_give(data)                       (0x00000300&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_ov_th(data)                       (0x00000030&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_ud_th(data)                       (0x0000000C&((data)<<2))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_balance_g_give(data)                        (0x00000003&(data))
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_get_balance_rb_ov_th(data)                  ((0x00003000&(data))>>12)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_get_balance_rb_ud_th(data)                  ((0x00000C00&(data))>>10)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_get_balance_rb_give(data)                   ((0x00000300&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_get_balance_g_ov_th(data)                   ((0x00000030&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_get_balance_g_ud_th(data)                   ((0x0000000C&(data))>>2)
#define  OD_DMA_ODDMA_PQ_CMP_BALANCE_get_balance_g_give(data)                    (0x00000003&(data))

#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN                                              0x1802CD24
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_reg_addr                                     "0xB802CD24"
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_reg                                          0xB802CD24
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_inst_addr                                    "0x0009"
#define  set_OD_DMA_ODDMA_PQ_CMP_IRQ_EN_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_IRQ_EN_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_IRQ_EN_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_IRQ_EN_reg))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_block_fifo_overflow_irq_en_shift             (15)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_input_size_more_irq_en_shift                 (14)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_input_size_less_irq_en_shift                 (13)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_over_flb_irq_en_shift                        (12)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_request_fifo_even_overflow_irq_en_shift      (9)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_g_fifo_even_overflow_irq_en_shift            (6)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_r_fifo_even_overflow_irq_en_shift            (5)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_b_fifo_even_overflow_irq_en_shift            (4)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_block_fifo_overflow_irq_en_mask              (0x00008000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_input_size_more_irq_en_mask                  (0x00004000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_input_size_less_irq_en_mask                  (0x00002000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_over_flb_irq_en_mask                         (0x00001000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_request_fifo_even_overflow_irq_en_mask       (0x00000200)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_g_fifo_even_overflow_irq_en_mask             (0x00000040)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_r_fifo_even_overflow_irq_en_mask             (0x00000020)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_b_fifo_even_overflow_irq_en_mask             (0x00000010)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_block_fifo_overflow_irq_en(data)             (0x00008000&((data)<<15))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_input_size_more_irq_en(data)                 (0x00004000&((data)<<14))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_input_size_less_irq_en(data)                 (0x00002000&((data)<<13))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_over_flb_irq_en(data)                        (0x00001000&((data)<<12))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_request_fifo_even_overflow_irq_en(data)      (0x00000200&((data)<<9))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_g_fifo_even_overflow_irq_en(data)            (0x00000040&((data)<<6))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_r_fifo_even_overflow_irq_en(data)            (0x00000020&((data)<<5))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_b_fifo_even_overflow_irq_en(data)            (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_block_fifo_overflow_irq_en(data)         ((0x00008000&(data))>>15)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_input_size_more_irq_en(data)             ((0x00004000&(data))>>14)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_input_size_less_irq_en(data)             ((0x00002000&(data))>>13)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_over_flb_irq_en(data)                    ((0x00001000&(data))>>12)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_request_fifo_even_overflow_irq_en(data)  ((0x00000200&(data))>>9)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_g_fifo_even_overflow_irq_en(data)        ((0x00000040&(data))>>6)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_r_fifo_even_overflow_irq_en(data)        ((0x00000020&(data))>>5)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_EN_get_b_fifo_even_overflow_irq_en(data)        ((0x00000010&(data))>>4)

#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST                                              0x1802CD28
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_reg_addr                                     "0xB802CD28"
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_reg                                          0xB802CD28
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_inst_addr                                    "0x000A"
#define  set_OD_DMA_ODDMA_PQ_CMP_IRQ_ST_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_IRQ_ST_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_IRQ_ST_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_IRQ_ST_reg))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_pqc_irq_shift                                (31)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_block_fifo_overflow_st_shift                 (15)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_input_size_more_st_shift                     (14)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_input_size_less_st_shift                     (13)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_over_flb_st_shift                            (12)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_request_fifo_even_overflow_st_shift          (9)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_g_fifo_even_overflow_st_shift                (6)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_r_fifo_even_overflow_st_shift                (5)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_b_fifo_even_overflow_st_shift                (4)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_pqc_irq_mask                                 (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_block_fifo_overflow_st_mask                  (0x00008000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_input_size_more_st_mask                      (0x00004000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_input_size_less_st_mask                      (0x00002000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_over_flb_st_mask                             (0x00001000)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_request_fifo_even_overflow_st_mask           (0x00000200)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_g_fifo_even_overflow_st_mask                 (0x00000040)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_r_fifo_even_overflow_st_mask                 (0x00000020)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_b_fifo_even_overflow_st_mask                 (0x00000010)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_pqc_irq(data)                                (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_block_fifo_overflow_st(data)                 (0x00008000&((data)<<15))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_input_size_more_st(data)                     (0x00004000&((data)<<14))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_input_size_less_st(data)                     (0x00002000&((data)<<13))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_over_flb_st(data)                            (0x00001000&((data)<<12))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_request_fifo_even_overflow_st(data)          (0x00000200&((data)<<9))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_g_fifo_even_overflow_st(data)                (0x00000040&((data)<<6))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_r_fifo_even_overflow_st(data)                (0x00000020&((data)<<5))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_b_fifo_even_overflow_st(data)                (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_pqc_irq(data)                            ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_block_fifo_overflow_st(data)             ((0x00008000&(data))>>15)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_input_size_more_st(data)                 ((0x00004000&(data))>>14)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_input_size_less_st(data)                 ((0x00002000&(data))>>13)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_over_flb_st(data)                        ((0x00001000&(data))>>12)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_request_fifo_even_overflow_st(data)      ((0x00000200&(data))>>9)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_g_fifo_even_overflow_st(data)            ((0x00000040&(data))>>6)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_r_fifo_even_overflow_st(data)            ((0x00000020&(data))>>5)
#define  OD_DMA_ODDMA_PQ_CMP_IRQ_ST_get_b_fifo_even_overflow_st(data)            ((0x00000010&(data))>>4)

#define  OD_DMA_ODDMA_PQ_CMP_ST                                                  0x1802CD2C
#define  OD_DMA_ODDMA_PQ_CMP_ST_reg_addr                                         "0xB802CD2C"
#define  OD_DMA_ODDMA_PQ_CMP_ST_reg                                              0xB802CD2C
#define  OD_DMA_ODDMA_PQ_CMP_ST_inst_addr                                        "0x000B"
#define  set_OD_DMA_ODDMA_PQ_CMP_ST_reg(data)                                    (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_ST_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_ST_reg                                          (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_ST_reg))
#define  OD_DMA_ODDMA_PQ_CMP_ST_cmp_two_pixel_mode_shift                         (31)
#define  OD_DMA_ODDMA_PQ_CMP_ST_g_ratio_max_shift                                (24)
#define  OD_DMA_ODDMA_PQ_CMP_ST_g_ratio_min_shift                                (16)
#define  OD_DMA_ODDMA_PQ_CMP_ST_cmp_package_height_cnt_shift                     (0)
#define  OD_DMA_ODDMA_PQ_CMP_ST_cmp_two_pixel_mode_mask                          (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_ST_g_ratio_max_mask                                 (0x1F000000)
#define  OD_DMA_ODDMA_PQ_CMP_ST_g_ratio_min_mask                                 (0x001F0000)
#define  OD_DMA_ODDMA_PQ_CMP_ST_cmp_package_height_cnt_mask                      (0x00003FFF)
#define  OD_DMA_ODDMA_PQ_CMP_ST_cmp_two_pixel_mode(data)                         (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_ST_g_ratio_max(data)                                (0x1F000000&((data)<<24))
#define  OD_DMA_ODDMA_PQ_CMP_ST_g_ratio_min(data)                                (0x001F0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_ST_cmp_package_height_cnt(data)                     (0x00003FFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_ST_get_cmp_two_pixel_mode(data)                     ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_ST_get_g_ratio_max(data)                            ((0x1F000000&(data))>>24)
#define  OD_DMA_ODDMA_PQ_CMP_ST_get_g_ratio_min(data)                            ((0x001F0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_ST_get_cmp_package_height_cnt(data)                 (0x00003FFF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_QP_ST                                               0x1802CD30
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_reg_addr                                      "0xB802CD30"
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_reg                                           0xB802CD30
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_inst_addr                                     "0x000C"
#define  set_OD_DMA_ODDMA_PQ_CMP_QP_ST_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_QP_ST_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_QP_ST_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_QP_ST_reg))
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_qp_measure_en_shift                 (31)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_g_qp_max_shift                      (20)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_rb_qp_max_shift                     (16)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_short_term_g_qp_max_shift                     (4)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_short_term_rb_qp_max_shift                    (0)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_qp_measure_en_mask                  (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_g_qp_max_mask                       (0x00F00000)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_rb_qp_max_mask                      (0x000F0000)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_short_term_g_qp_max_mask                      (0x000000F0)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_short_term_rb_qp_max_mask                     (0x0000000F)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_qp_measure_en(data)                 (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_g_qp_max(data)                      (0x00F00000&((data)<<20))
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_long_term_rb_qp_max(data)                     (0x000F0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_short_term_g_qp_max(data)                     (0x000000F0&((data)<<4))
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_short_term_rb_qp_max(data)                    (0x0000000F&(data))
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_get_long_term_qp_measure_en(data)             ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_get_long_term_g_qp_max(data)                  ((0x00F00000&(data))>>20)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_get_long_term_rb_qp_max(data)                 ((0x000F0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_get_short_term_g_qp_max(data)                 ((0x000000F0&(data))>>4)
#define  OD_DMA_ODDMA_PQ_CMP_QP_ST_get_short_term_rb_qp_max(data)                (0x0000000F&(data))

#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1                                            0x1802CD34
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_reg_addr                                   "0xB802CD34"
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_reg                                        0xB802CD34
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_inst_addr                                  "0x000D"
#define  set_OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_reg))
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_measure_en_shift                (31)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_g_shift                    (16)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_r_shift                    (8)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_b_shift                    (0)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_measure_en_mask                 (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_g_mask                     (0x00FF0000)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_r_mask                     (0x0000FF00)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_b_mask                     (0x000000FF)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_measure_en(data)                (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_g(data)                    (0x00FF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_r(data)                    (0x0000FF00&((data)<<8))
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_fifo_water_even_b(data)                    (0x000000FF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_get_fifo_water_measure_en(data)            ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_get_fifo_water_even_g(data)                ((0x00FF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_get_fifo_water_even_r(data)                ((0x0000FF00&(data))>>8)
#define  OD_DMA_ODDMA_PQ_CMP_FIFO_ST1_get_fifo_water_even_b(data)                (0x000000FF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST                                             0x1802CD3C
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_reg_addr                                    "0xB802CD3C"
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_reg                                         0xB802CD3C
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_inst_addr                                   "0x000E"
#define  set_OD_DMA_ODDMA_PQ_CMP_LEFT_ST_reg(data)                               (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_LEFT_ST_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_LEFT_ST_reg                                     (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_LEFT_ST_reg))
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_g_frame_left_shift                          (16)
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_rb_frame_left_shift                         (0)
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_g_frame_left_mask                           (0xFFFF0000)
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_rb_frame_left_mask                          (0x0000FFFF)
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_g_frame_left(data)                          (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_rb_frame_left(data)                         (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_get_g_frame_left(data)                      ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_CMP_LEFT_ST_get_rb_frame_left(data)                     (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST                                          0x1802CD40
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_reg_addr                                 "0xB802CD40"
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_reg                                      0xB802CD40
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_inst_addr                                "0x000F"
#define  set_OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_reg))
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_total_package_long_term_shift            (31)
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_total_package_even_shift                 (0)
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_total_package_long_term_mask             (0x80000000)
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_total_package_even_mask                  (0x00FFFFFF)
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_total_package_long_term(data)            (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_total_package_even(data)                 (0x00FFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_get_total_package_long_term(data)        ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_CMP_PACKAGE_ST_get_total_package_even(data)             (0x00FFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G                                          0x1802CD44
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_reg_addr                                 "0xB802CD44"
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_reg                                      0xB802CD44
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_inst_addr                                "0x0010"
#define  set_OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_reg))
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_cmp_crc_even_g_shift                     (0)
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_cmp_crc_even_g_mask                      (0xFFFFFFFF)
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_cmp_crc_even_g(data)                     (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_G_get_cmp_crc_even_g(data)                 (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R                                          0x1802CD48
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_reg_addr                                 "0xB802CD48"
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_reg                                      0xB802CD48
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_inst_addr                                "0x0011"
#define  set_OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_reg))
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_cmp_crc_even_r_shift                     (0)
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_cmp_crc_even_r_mask                      (0xFFFFFFFF)
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_cmp_crc_even_r(data)                     (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_R_get_cmp_crc_even_r(data)                 (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B                                          0x1802CD4C
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_reg_addr                                 "0xB802CD4C"
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_reg                                      0xB802CD4C
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_inst_addr                                "0x0012"
#define  set_OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_reg))
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_cmp_crc_even_b_shift                     (0)
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_cmp_crc_even_b_mask                      (0xFFFFFFFF)
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_cmp_crc_even_b(data)                     (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_CMP_CRC_EVEN_B_get_cmp_crc_even_b(data)                 (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP                                                   0x1802CD60
#define  OD_DMA_ODDMA_PQ_DECMP_reg_addr                                          "0xB802CD60"
#define  OD_DMA_ODDMA_PQ_DECMP_reg                                               0xB802CD60
#define  OD_DMA_ODDMA_PQ_DECMP_inst_addr                                         "0x0013"
#define  set_OD_DMA_ODDMA_PQ_DECMP_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_en_shift                                    (31)
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_width_div32_shift                           (16)
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_height_shift                                (0)
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_en_mask                                     (0x80000000)
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_width_div32_mask                            (0x01FF0000)
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_height_mask                                 (0x00003FFF)
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_en(data)                                    (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_width_div32(data)                           (0x01FF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_decmp_height(data)                                (0x00003FFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_get_decmp_en(data)                                ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_DECMP_get_decmp_width_div32(data)                       ((0x01FF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_DECMP_get_decmp_height(data)                            (0x00003FFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_PAIR                                              0x1802CD64
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_reg_addr                                     "0xB802CD64"
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_reg                                          0xB802CD64
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_inst_addr                                    "0x0014"
#define  set_OD_DMA_ODDMA_PQ_DECMP_PAIR_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_PAIR_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_PAIR_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_PAIR_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_dummy_31_5_shift                             (5)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_color_shift                       (4)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_bit_width_shift                   (2)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_format_shift                      (0)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_dummy_31_5_mask                              (0xFFFFFFE0)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_color_mask                        (0x00000010)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_bit_width_mask                    (0x0000000C)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_format_mask                       (0x00000003)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_dummy_31_5(data)                             (0xFFFFFFE0&((data)<<5))
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_color(data)                       (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_bit_width(data)                   (0x0000000C&((data)<<2))
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_decmp_data_format(data)                      (0x00000003&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_get_dummy_31_5(data)                         ((0xFFFFFFE0&(data))>>5)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_get_decmp_data_color(data)                   ((0x00000010&(data))>>4)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_get_decmp_data_bit_width(data)               ((0x0000000C&(data))>>2)
#define  OD_DMA_ODDMA_PQ_DECMP_PAIR_get_decmp_data_format(data)                  (0x00000003&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN                                            0x1802CD68
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg_addr                                   "0xB802CD68"
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg                                        0xB802CD68
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_inst_addr                                  "0x0015"
#define  set_OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_SAT_EN_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_saturation_type_shift                      (1)
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_saturation_en_shift                        (0)
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_saturation_type_mask                       (0x00000002)
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_saturation_en_mask                         (0x00000001)
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_saturation_type(data)                      (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_saturation_en(data)                        (0x00000001&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_get_saturation_type(data)                  ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_PQ_DECMP_SAT_EN_get_saturation_en(data)                    (0x00000001&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN                                            0x1802CD6C
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_reg_addr                                   "0xB802CD6C"
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_reg                                        0xB802CD6C
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_inst_addr                                  "0x0016"
#define  set_OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_not_finish_irq_even_en_shift               (21)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_underflow_irq_even_en_shift                (20)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_r_error_even_en_shift                  (18)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_g_error_even_en_shift                  (17)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_b_error_even_en_shift                  (16)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_not_finish_irq_even_en_mask                (0x00200000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_underflow_irq_even_en_mask                 (0x00100000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_r_error_even_en_mask                   (0x00040000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_g_error_even_en_mask                   (0x00020000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_b_error_even_en_mask                   (0x00010000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_not_finish_irq_even_en(data)               (0x00200000&((data)<<21))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_underflow_irq_even_en(data)                (0x00100000&((data)<<20))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_r_error_even_en(data)                  (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_g_error_even_en(data)                  (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_crc_b_error_even_en(data)                  (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_get_not_finish_irq_even_en(data)           ((0x00200000&(data))>>21)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_get_underflow_irq_even_en(data)            ((0x00100000&(data))>>20)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_get_crc_r_error_even_en(data)              ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_get_crc_g_error_even_en(data)              ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_EN_get_crc_b_error_even_en(data)              ((0x00010000&(data))>>16)

#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st                                            0x1802CD70
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_reg_addr                                   "0xB802CD70"
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_reg                                        0xB802CD70
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_inst_addr                                  "0x0017"
#define  set_OD_DMA_ODDMA_PQ_DECMP_IRQ_st_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_IRQ_st_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_IRQ_st_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_IRQ_st_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_pqdc_irq_shift                             (31)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_in_fifo_overflow_even_st_shift             (27)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_r_overflow_even_st_shift              (26)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_g_overflow_even_st_shift              (25)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_b_overflow_even_st_shift              (24)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_not_finish_irq_even_st_shift               (21)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_underflow_irq_even_st_shift                (20)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_r_error_even_st_shift                  (18)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_g_error_even_st_shift                  (17)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_b_error_even_st_shift                  (16)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_pqdc_irq_mask                              (0x80000000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_in_fifo_overflow_even_st_mask              (0x08000000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_r_overflow_even_st_mask               (0x04000000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_g_overflow_even_st_mask               (0x02000000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_b_overflow_even_st_mask               (0x01000000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_not_finish_irq_even_st_mask                (0x00200000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_underflow_irq_even_st_mask                 (0x00100000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_r_error_even_st_mask                   (0x00040000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_g_error_even_st_mask                   (0x00020000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_b_error_even_st_mask                   (0x00010000)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_pqdc_irq(data)                             (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_in_fifo_overflow_even_st(data)             (0x08000000&((data)<<27))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_r_overflow_even_st(data)              (0x04000000&((data)<<26))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_g_overflow_even_st(data)              (0x02000000&((data)<<25))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_ring_b_overflow_even_st(data)              (0x01000000&((data)<<24))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_not_finish_irq_even_st(data)               (0x00200000&((data)<<21))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_underflow_irq_even_st(data)                (0x00100000&((data)<<20))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_r_error_even_st(data)                  (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_g_error_even_st(data)                  (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_crc_b_error_even_st(data)                  (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_pqdc_irq(data)                         ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_in_fifo_overflow_even_st(data)         ((0x08000000&(data))>>27)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_ring_r_overflow_even_st(data)          ((0x04000000&(data))>>26)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_ring_g_overflow_even_st(data)          ((0x02000000&(data))>>25)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_ring_b_overflow_even_st(data)          ((0x01000000&(data))>>24)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_not_finish_irq_even_st(data)           ((0x00200000&(data))>>21)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_underflow_irq_even_st(data)            ((0x00100000&(data))>>20)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_crc_r_error_even_st(data)              ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_crc_g_error_even_st(data)              ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_PQ_DECMP_IRQ_st_get_crc_b_error_even_st(data)              ((0x00010000&(data))>>16)

#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN                                           0x1802CD74
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_reg_addr                                  "0xB802CD74"
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_reg                                       0xB802CD74
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_inst_addr                                 "0x0018"
#define  set_OD_DMA_ODDMA_PQ_DECMP_MARK_EN_reg(data)                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_EN_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_MARK_EN_reg                                   (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_EN_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_do_422_shift                      (31)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp_sel_shift                      (16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp7_shift                         (7)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp6_shift                         (6)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp5_shift                         (5)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp4_shift                         (4)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp3_shift                         (3)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp2_shift                         (2)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp1_shift                         (1)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp0_shift                         (0)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_do_422_mask                       (0x80000000)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp_sel_mask                       (0x00010000)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp7_mask                          (0x00000080)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp6_mask                          (0x00000040)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp5_mask                          (0x00000020)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp4_mask                          (0x00000010)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp3_mask                          (0x00000008)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp2_mask                          (0x00000004)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp1_mask                          (0x00000002)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp0_mask                          (0x00000001)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_do_422(data)                      (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp_sel(data)                      (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp7(data)                         (0x00000080&((data)<<7))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp6(data)                         (0x00000040&((data)<<6))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp5(data)                         (0x00000020&((data)<<5))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp4(data)                         (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp3(data)                         (0x00000008&((data)<<3))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp2(data)                         (0x00000004&((data)<<2))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp1(data)                         (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_mark_en_qp0(data)                         (0x00000001&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_do_422(data)                  ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp_sel(data)                  ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp7(data)                     ((0x00000080&(data))>>7)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp6(data)                     ((0x00000040&(data))>>6)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp5(data)                     ((0x00000020&(data))>>5)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp4(data)                     ((0x00000010&(data))>>4)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp3(data)                     ((0x00000008&(data))>>3)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp2(data)                     ((0x00000004&(data))>>2)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp1(data)                     ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_EN_get_mark_en_qp0(data)                     (0x00000001&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01                                     0x1802CD78
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_reg_addr                            "0xB802CD78"
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_reg                                 0xB802CD78
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_inst_addr                           "0x0019"
#define  set_OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_reg(data)                       (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_reg                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_mark_color_0_shift                  (16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_mark_color_1_shift                  (0)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_mark_color_0_mask                   (0xFFFF0000)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_mark_color_1_mask                   (0x0000FFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_mark_color_0(data)                  (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_mark_color_1(data)                  (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_get_mark_color_0(data)              ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_01_get_mark_color_1(data)              (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23                                     0x1802CD7C
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_reg_addr                            "0xB802CD7C"
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_reg                                 0xB802CD7C
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_inst_addr                           "0x001A"
#define  set_OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_reg(data)                       (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_reg                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_mark_color_2_shift                  (16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_mark_color_3_shift                  (0)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_mark_color_2_mask                   (0xFFFF0000)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_mark_color_3_mask                   (0x0000FFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_mark_color_2(data)                  (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_mark_color_3(data)                  (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_get_mark_color_2(data)              ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_23_get_mark_color_3(data)              (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45                                     0x1802CD80
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_reg_addr                            "0xB802CD80"
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_reg                                 0xB802CD80
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_inst_addr                           "0x001B"
#define  set_OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_reg(data)                       (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_reg                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_mark_color_4_shift                  (16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_mark_color_5_shift                  (0)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_mark_color_4_mask                   (0xFFFF0000)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_mark_color_5_mask                   (0x0000FFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_mark_color_4(data)                  (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_mark_color_5(data)                  (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_get_mark_color_4(data)              ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_45_get_mark_color_5(data)              (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67                                     0x1802CD84
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_reg_addr                            "0xB802CD84"
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_reg                                 0xB802CD84
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_inst_addr                           "0x001C"
#define  set_OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_reg(data)                       (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_reg                             (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_mark_color_6_shift                  (16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_mark_color_7_shift                  (0)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_mark_color_6_mask                   (0xFFFF0000)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_mark_color_7_mask                   (0x0000FFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_mark_color_6(data)                  (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_mark_color_7(data)                  (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_get_mark_color_6(data)              ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_67_get_mark_color_7(data)              (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422                                    0x1802CD88
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_reg_addr                           "0xB802CD88"
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_reg                                0xB802CD88
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_inst_addr                          "0x001D"
#define  set_OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_reg(data)                      (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_reg                            (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_mark_color_422_shift               (0)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_mark_color_422_mask                (0x0000FFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_mark_color_422(data)               (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_MARK_color_422_get_mark_color_422(data)           (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_ST                                                0x1802CD8C
#define  OD_DMA_ODDMA_PQ_DECMP_ST_reg_addr                                       "0xB802CD8C"
#define  OD_DMA_ODDMA_PQ_DECMP_ST_reg                                            0xB802CD8C
#define  OD_DMA_ODDMA_PQ_DECMP_ST_inst_addr                                      "0x001E"
#define  set_OD_DMA_ODDMA_PQ_DECMP_ST_reg(data)                                  (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_ST_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_ST_reg                                        (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_ST_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_ST_decmp_two_pixel_mode_shift                     (31)
#define  OD_DMA_ODDMA_PQ_DECMP_ST_decmp_package_height_cnt_shift                 (0)
#define  OD_DMA_ODDMA_PQ_DECMP_ST_decmp_two_pixel_mode_mask                      (0x80000000)
#define  OD_DMA_ODDMA_PQ_DECMP_ST_decmp_package_height_cnt_mask                  (0x00003FFF)
#define  OD_DMA_ODDMA_PQ_DECMP_ST_decmp_two_pixel_mode(data)                     (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_PQ_DECMP_ST_decmp_package_height_cnt(data)                 (0x00003FFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_ST_get_decmp_two_pixel_mode(data)                 ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_PQ_DECMP_ST_get_decmp_package_height_cnt(data)             (0x00003FFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G                                        0x1802CD90
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_reg_addr                               "0xB802CD90"
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_reg                                    0xB802CD90
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_inst_addr                              "0x001F"
#define  set_OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_reg(data)                          (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_reg                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_decmp_crc_even_g_shift                 (0)
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_decmp_crc_even_g_mask                  (0xFFFFFFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_decmp_crc_even_g(data)                 (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_G_get_decmp_crc_even_g(data)             (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R                                        0x1802CD94
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_reg_addr                               "0xB802CD94"
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_reg                                    0xB802CD94
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_inst_addr                              "0x0020"
#define  set_OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_reg(data)                          (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_reg                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_decmp_crc_even_r_shift                 (0)
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_decmp_crc_even_r_mask                  (0xFFFFFFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_decmp_crc_even_r(data)                 (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_R_get_decmp_crc_even_r(data)             (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B                                        0x1802CD98
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_reg_addr                               "0xB802CD98"
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_reg                                    0xB802CD98
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_inst_addr                              "0x0021"
#define  set_OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_reg(data)                          (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_reg                                (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_decmp_crc_even_b_shift                 (0)
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_decmp_crc_even_b_mask                  (0xFFFFFFFF)
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_decmp_crc_even_b(data)                 (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_CRC_EVEN_B_get_decmp_crc_even_b(data)             (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION                                      0x1802CDA8
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg_addr                             "0xB802CDA8"
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg                                  0xB802CDA8
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_inst_addr                            "0x0022"
#define  set_OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg(data)                        (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg)=data)
#define  get_OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg                              (*((volatile unsigned int*)OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_reg))
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_tr_en_shift                          (0)
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_tr_en_mask                           (0x00000001)
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_tr_en(data)                          (0x00000001&(data))
#define  OD_DMA_ODDMA_PQ_DECMP_COMPENSATION_get_tr_en(data)                      (0x00000001&(data))

#define  OD_DMA_OD_DMA_CTRL4                                                     0x1802CDB0
#define  OD_DMA_OD_DMA_CTRL4_reg_addr                                            "0xB802CDB0"
#define  OD_DMA_OD_DMA_CTRL4_reg                                                 0xB802CDB0
#define  OD_DMA_OD_DMA_CTRL4_inst_addr                                           "0x0023"
#define  set_OD_DMA_OD_DMA_CTRL4_reg(data)                                       (*((volatile unsigned int*)OD_DMA_OD_DMA_CTRL4_reg)=data)
#define  get_OD_DMA_OD_DMA_CTRL4_reg                                             (*((volatile unsigned int*)OD_DMA_OD_DMA_CTRL4_reg))
#define  OD_DMA_OD_DMA_CTRL4_smooth_tog_en_shift                                 (8)
#define  OD_DMA_OD_DMA_CTRL4_disp_db_apply_shift                                 (6)
#define  OD_DMA_OD_DMA_CTRL4_disp_db_rd_sel_shift                                (5)
#define  OD_DMA_OD_DMA_CTRL4_disp_db_en_shift                                    (4)
#define  OD_DMA_OD_DMA_CTRL4_cap_db_apply_shift                                  (2)
#define  OD_DMA_OD_DMA_CTRL4_cap_db_rd_sel_shift                                 (1)
#define  OD_DMA_OD_DMA_CTRL4_cap_db_en_shift                                     (0)
#define  OD_DMA_OD_DMA_CTRL4_smooth_tog_en_mask                                  (0x00000100)
#define  OD_DMA_OD_DMA_CTRL4_disp_db_apply_mask                                  (0x00000040)
#define  OD_DMA_OD_DMA_CTRL4_disp_db_rd_sel_mask                                 (0x00000020)
#define  OD_DMA_OD_DMA_CTRL4_disp_db_en_mask                                     (0x00000010)
#define  OD_DMA_OD_DMA_CTRL4_cap_db_apply_mask                                   (0x00000004)
#define  OD_DMA_OD_DMA_CTRL4_cap_db_rd_sel_mask                                  (0x00000002)
#define  OD_DMA_OD_DMA_CTRL4_cap_db_en_mask                                      (0x00000001)
#define  OD_DMA_OD_DMA_CTRL4_smooth_tog_en(data)                                 (0x00000100&((data)<<8))
#define  OD_DMA_OD_DMA_CTRL4_disp_db_apply(data)                                 (0x00000040&((data)<<6))
#define  OD_DMA_OD_DMA_CTRL4_disp_db_rd_sel(data)                                (0x00000020&((data)<<5))
#define  OD_DMA_OD_DMA_CTRL4_disp_db_en(data)                                    (0x00000010&((data)<<4))
#define  OD_DMA_OD_DMA_CTRL4_cap_db_apply(data)                                  (0x00000004&((data)<<2))
#define  OD_DMA_OD_DMA_CTRL4_cap_db_rd_sel(data)                                 (0x00000002&((data)<<1))
#define  OD_DMA_OD_DMA_CTRL4_cap_db_en(data)                                     (0x00000001&(data))
#define  OD_DMA_OD_DMA_CTRL4_get_smooth_tog_en(data)                             ((0x00000100&(data))>>8)
#define  OD_DMA_OD_DMA_CTRL4_get_disp_db_apply(data)                             ((0x00000040&(data))>>6)
#define  OD_DMA_OD_DMA_CTRL4_get_disp_db_rd_sel(data)                            ((0x00000020&(data))>>5)
#define  OD_DMA_OD_DMA_CTRL4_get_disp_db_en(data)                                ((0x00000010&(data))>>4)
#define  OD_DMA_OD_DMA_CTRL4_get_cap_db_apply(data)                              ((0x00000004&(data))>>2)
#define  OD_DMA_OD_DMA_CTRL4_get_cap_db_rd_sel(data)                             ((0x00000002&(data))>>1)
#define  OD_DMA_OD_DMA_CTRL4_get_cap_db_en(data)                                 (0x00000001&(data))

#define  OD_DMA_ODDMA_LR_Separate_CTRL2                                          0x1802CDB8
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_reg_addr                                 "0xB802CDB8"
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_reg                                      0xB802CDB8
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_inst_addr                                "0x0024"
#define  set_OD_DMA_ODDMA_LR_Separate_CTRL2_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_LR_Separate_CTRL2_reg)=data)
#define  get_OD_DMA_ODDMA_LR_Separate_CTRL2_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_LR_Separate_CTRL2_reg))
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_vact_shift                               (16)
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_hact_shift                               (0)
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_vact_mask                                (0xFFFF0000)
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_hact_mask                                (0x00007FFF)
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_vact(data)                               (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_hact(data)                               (0x00007FFF&(data))
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_get_vact(data)                           ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_LR_Separate_CTRL2_get_hact(data)                           (0x00007FFF&(data))

#define  OD_DMA_ODDMA_Cap_CTL0                                                   0x1802CDBC
#define  OD_DMA_ODDMA_Cap_CTL0_reg_addr                                          "0xB802CDBC"
#define  OD_DMA_ODDMA_Cap_CTL0_reg                                               0xB802CDBC
#define  OD_DMA_ODDMA_Cap_CTL0_inst_addr                                         "0x0025"
#define  set_OD_DMA_ODDMA_Cap_CTL0_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_CTL0_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_CTL0_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_CTL0_reg))
#define  OD_DMA_ODDMA_Cap_CTL0_cap_block_fw_shift                                (29)
#define  OD_DMA_ODDMA_Cap_CTL0_set_block_sel_shift                               (28)
#define  OD_DMA_ODDMA_Cap_CTL0_comp_de_comp_bypass_shift                         (25)
#define  OD_DMA_ODDMA_Cap_CTL0_freeze_en_shift                                   (24)
#define  OD_DMA_ODDMA_Cap_CTL0_auto_block_sel_en_shift                           (22)
#define  OD_DMA_ODDMA_Cap_CTL0_cap_en_shift                                      (19)
#define  OD_DMA_ODDMA_Cap_CTL0_cap_block_fw_mask                                 (0x60000000)
#define  OD_DMA_ODDMA_Cap_CTL0_set_block_sel_mask                                (0x10000000)
#define  OD_DMA_ODDMA_Cap_CTL0_comp_de_comp_bypass_mask                          (0x02000000)
#define  OD_DMA_ODDMA_Cap_CTL0_freeze_en_mask                                    (0x01000000)
#define  OD_DMA_ODDMA_Cap_CTL0_auto_block_sel_en_mask                            (0x00400000)
#define  OD_DMA_ODDMA_Cap_CTL0_cap_en_mask                                       (0x00080000)
#define  OD_DMA_ODDMA_Cap_CTL0_cap_block_fw(data)                                (0x60000000&((data)<<29))
#define  OD_DMA_ODDMA_Cap_CTL0_set_block_sel(data)                               (0x10000000&((data)<<28))
#define  OD_DMA_ODDMA_Cap_CTL0_comp_de_comp_bypass(data)                         (0x02000000&((data)<<25))
#define  OD_DMA_ODDMA_Cap_CTL0_freeze_en(data)                                   (0x01000000&((data)<<24))
#define  OD_DMA_ODDMA_Cap_CTL0_auto_block_sel_en(data)                           (0x00400000&((data)<<22))
#define  OD_DMA_ODDMA_Cap_CTL0_cap_en(data)                                      (0x00080000&((data)<<19))
#define  OD_DMA_ODDMA_Cap_CTL0_get_cap_block_fw(data)                            ((0x60000000&(data))>>29)
#define  OD_DMA_ODDMA_Cap_CTL0_get_set_block_sel(data)                           ((0x10000000&(data))>>28)
#define  OD_DMA_ODDMA_Cap_CTL0_get_comp_de_comp_bypass(data)                     ((0x02000000&(data))>>25)
#define  OD_DMA_ODDMA_Cap_CTL0_get_freeze_en(data)                               ((0x01000000&(data))>>24)
#define  OD_DMA_ODDMA_Cap_CTL0_get_auto_block_sel_en(data)                       ((0x00400000&(data))>>22)
#define  OD_DMA_ODDMA_Cap_CTL0_get_cap_en(data)                                  ((0x00080000&(data))>>19)

#define  OD_DMA_ODDMA_Cap_CTL1                                                   0x1802CDC0
#define  OD_DMA_ODDMA_Cap_CTL1_reg_addr                                          "0xB802CDC0"
#define  OD_DMA_ODDMA_Cap_CTL1_reg                                               0xB802CDC0
#define  OD_DMA_ODDMA_Cap_CTL1_inst_addr                                         "0x0026"
#define  set_OD_DMA_ODDMA_Cap_CTL1_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_CTL1_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_CTL1_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_CTL1_reg))
#define  OD_DMA_ODDMA_Cap_CTL1_bit_sel_shift                                     (17)
#define  OD_DMA_ODDMA_Cap_CTL1_pixel_encoding_shift                              (16)
#define  OD_DMA_ODDMA_Cap_CTL1_cap_write_len_shift                               (8)
#define  OD_DMA_ODDMA_Cap_CTL1_cap_write_rem_shift                               (0)
#define  OD_DMA_ODDMA_Cap_CTL1_bit_sel_mask                                      (0x00060000)
#define  OD_DMA_ODDMA_Cap_CTL1_pixel_encoding_mask                               (0x00010000)
#define  OD_DMA_ODDMA_Cap_CTL1_cap_write_len_mask                                (0x00007F00)
#define  OD_DMA_ODDMA_Cap_CTL1_cap_write_rem_mask                                (0x0000007F)
#define  OD_DMA_ODDMA_Cap_CTL1_bit_sel(data)                                     (0x00060000&((data)<<17))
#define  OD_DMA_ODDMA_Cap_CTL1_pixel_encoding(data)                              (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_Cap_CTL1_cap_write_len(data)                               (0x00007F00&((data)<<8))
#define  OD_DMA_ODDMA_Cap_CTL1_cap_write_rem(data)                               (0x0000007F&(data))
#define  OD_DMA_ODDMA_Cap_CTL1_get_bit_sel(data)                                 ((0x00060000&(data))>>17)
#define  OD_DMA_ODDMA_Cap_CTL1_get_pixel_encoding(data)                          ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_Cap_CTL1_get_cap_write_len(data)                           ((0x00007F00&(data))>>8)
#define  OD_DMA_ODDMA_Cap_CTL1_get_cap_write_rem(data)                           (0x0000007F&(data))

#define  OD_DMA_ODDMA_Cap_CTL2                                                   0x1802CDC4
#define  OD_DMA_ODDMA_Cap_CTL2_reg_addr                                          "0xB802CDC4"
#define  OD_DMA_ODDMA_Cap_CTL2_reg                                               0xB802CDC4
#define  OD_DMA_ODDMA_Cap_CTL2_inst_addr                                         "0x0027"
#define  set_OD_DMA_ODDMA_Cap_CTL2_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_CTL2_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_CTL2_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_CTL2_reg))
#define  OD_DMA_ODDMA_Cap_CTL2_cap_water_lv_shift                                (16)
#define  OD_DMA_ODDMA_Cap_CTL2_cap_write_num_shift                               (0)
#define  OD_DMA_ODDMA_Cap_CTL2_cap_water_lv_mask                                 (0x007F0000)
#define  OD_DMA_ODDMA_Cap_CTL2_cap_write_num_mask                                (0x0000FFFF)
#define  OD_DMA_ODDMA_Cap_CTL2_cap_water_lv(data)                                (0x007F0000&((data)<<16))
#define  OD_DMA_ODDMA_Cap_CTL2_cap_write_num(data)                               (0x0000FFFF&(data))
#define  OD_DMA_ODDMA_Cap_CTL2_get_cap_water_lv(data)                            ((0x007F0000&(data))>>16)
#define  OD_DMA_ODDMA_Cap_CTL2_get_cap_write_num(data)                           (0x0000FFFF&(data))

#define  OD_DMA_ODDMA_Cap_BoundaryAddr1                                          0x1802CDD0
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_reg_addr                                 "0xB802CDD0"
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_reg                                      0xB802CDD0
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_inst_addr                                "0x0028"
#define  set_OD_DMA_ODDMA_Cap_BoundaryAddr1_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_BoundaryAddr1_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_BoundaryAddr1_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_BoundaryAddr1_reg))
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_cap_mem_up_limit_shift                   (3)
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_cap_mem_up_limit_mask                    (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_cap_mem_up_limit(data)                   (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Cap_BoundaryAddr1_get_cap_mem_up_limit(data)               ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Cap_BoundaryAddr2                                          0x1802CDD4
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_reg_addr                                 "0xB802CDD4"
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_reg                                      0xB802CDD4
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_inst_addr                                "0x0029"
#define  set_OD_DMA_ODDMA_Cap_BoundaryAddr2_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_BoundaryAddr2_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_BoundaryAddr2_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_BoundaryAddr2_reg))
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_cap_mem_low_limit_shift                  (3)
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_cap_mem_low_limit_mask                   (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_cap_mem_low_limit(data)                  (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Cap_BoundaryAddr2_get_cap_mem_low_limit(data)              ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Cap_LineStep                                               0x1802CDD8
#define  OD_DMA_ODDMA_Cap_LineStep_reg_addr                                      "0xB802CDD8"
#define  OD_DMA_ODDMA_Cap_LineStep_reg                                           0xB802CDD8
#define  OD_DMA_ODDMA_Cap_LineStep_inst_addr                                     "0x002A"
#define  set_OD_DMA_ODDMA_Cap_LineStep_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_LineStep_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_LineStep_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_LineStep_reg))
#define  OD_DMA_ODDMA_Cap_LineStep_cap_line_step_shift                           (3)
#define  OD_DMA_ODDMA_Cap_LineStep_cap_line_step_mask                            (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Cap_LineStep_cap_line_step(data)                           (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Cap_LineStep_get_cap_line_step(data)                       ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Cap_L1_Start                                               0x1802CDE0
#define  OD_DMA_ODDMA_Cap_L1_Start_reg_addr                                      "0xB802CDE0"
#define  OD_DMA_ODDMA_Cap_L1_Start_reg                                           0xB802CDE0
#define  OD_DMA_ODDMA_Cap_L1_Start_inst_addr                                     "0x002B"
#define  set_OD_DMA_ODDMA_Cap_L1_Start_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L1_Start_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_L1_Start_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L1_Start_reg))
#define  OD_DMA_ODDMA_Cap_L1_Start_cap_l1_start_shift                            (3)
#define  OD_DMA_ODDMA_Cap_L1_Start_cap_l1_start_mask                             (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Cap_L1_Start_cap_l1_start(data)                            (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Cap_L1_Start_get_cap_l1_start(data)                        ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Cap_L2_Start                                               0x1802CDE4
#define  OD_DMA_ODDMA_Cap_L2_Start_reg_addr                                      "0xB802CDE4"
#define  OD_DMA_ODDMA_Cap_L2_Start_reg                                           0xB802CDE4
#define  OD_DMA_ODDMA_Cap_L2_Start_inst_addr                                     "0x002C"
#define  set_OD_DMA_ODDMA_Cap_L2_Start_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L2_Start_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_L2_Start_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L2_Start_reg))
#define  OD_DMA_ODDMA_Cap_L2_Start_cap_l2_start_shift                            (3)
#define  OD_DMA_ODDMA_Cap_L2_Start_cap_l2_start_mask                             (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Cap_L2_Start_cap_l2_start(data)                            (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Cap_L2_Start_get_cap_l2_start(data)                        ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Cap_L1_Start_db                                            0x1802CE00
#define  OD_DMA_ODDMA_Cap_L1_Start_db_reg_addr                                   "0xB802CE00"
#define  OD_DMA_ODDMA_Cap_L1_Start_db_reg                                        0xB802CE00
#define  OD_DMA_ODDMA_Cap_L1_Start_db_inst_addr                                  "0x002D"
#define  set_OD_DMA_ODDMA_Cap_L1_Start_db_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L1_Start_db_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_L1_Start_db_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L1_Start_db_reg))
#define  OD_DMA_ODDMA_Cap_L1_Start_db_cap_l1_start_db_shift                      (3)
#define  OD_DMA_ODDMA_Cap_L1_Start_db_cap_l1_start_db_mask                       (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Cap_L1_Start_db_cap_l1_start_db(data)                      (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Cap_L1_Start_db_get_cap_l1_start_db(data)                  ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Cap_Status                                                 0x1802CE08
#define  OD_DMA_ODDMA_Cap_Status_reg_addr                                        "0xB802CE08"
#define  OD_DMA_ODDMA_Cap_Status_reg                                             0xB802CE08
#define  OD_DMA_ODDMA_Cap_Status_inst_addr                                       "0x002E"
#define  set_OD_DMA_ODDMA_Cap_Status_reg(data)                                   (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_Status_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_Status_reg                                         (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_Status_reg))
#define  OD_DMA_ODDMA_Cap_Status_cap_over_size_shift                             (11)
#define  OD_DMA_ODDMA_Cap_Status_cap_under_size_shift                            (10)
#define  OD_DMA_ODDMA_Cap_Status_freeze_ok_shift                                 (9)
#define  OD_DMA_ODDMA_Cap_Status_vs_rising_occur_shift                           (8)
#define  OD_DMA_ODDMA_Cap_Status_cap_block_shift                                 (6)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_full_shift                             (4)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_empty_shift                            (3)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_overflow_shift                         (2)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_underflow_shift                        (1)
#define  OD_DMA_ODDMA_Cap_Status_cap_ddr_over_range_shift                        (0)
#define  OD_DMA_ODDMA_Cap_Status_cap_over_size_mask                              (0x00000800)
#define  OD_DMA_ODDMA_Cap_Status_cap_under_size_mask                             (0x00000400)
#define  OD_DMA_ODDMA_Cap_Status_freeze_ok_mask                                  (0x00000200)
#define  OD_DMA_ODDMA_Cap_Status_vs_rising_occur_mask                            (0x00000100)
#define  OD_DMA_ODDMA_Cap_Status_cap_block_mask                                  (0x000000C0)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_full_mask                              (0x00000010)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_empty_mask                             (0x00000008)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_overflow_mask                          (0x00000004)
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_underflow_mask                         (0x00000002)
#define  OD_DMA_ODDMA_Cap_Status_cap_ddr_over_range_mask                         (0x00000001)
#define  OD_DMA_ODDMA_Cap_Status_cap_over_size(data)                             (0x00000800&((data)<<11))
#define  OD_DMA_ODDMA_Cap_Status_cap_under_size(data)                            (0x00000400&((data)<<10))
#define  OD_DMA_ODDMA_Cap_Status_freeze_ok(data)                                 (0x00000200&((data)<<9))
#define  OD_DMA_ODDMA_Cap_Status_vs_rising_occur(data)                           (0x00000100&((data)<<8))
#define  OD_DMA_ODDMA_Cap_Status_cap_block(data)                                 (0x000000C0&((data)<<6))
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_full(data)                             (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_empty(data)                            (0x00000008&((data)<<3))
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_overflow(data)                         (0x00000004&((data)<<2))
#define  OD_DMA_ODDMA_Cap_Status_cap_fifo_underflow(data)                        (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_Cap_Status_cap_ddr_over_range(data)                        (0x00000001&(data))
#define  OD_DMA_ODDMA_Cap_Status_get_cap_over_size(data)                         ((0x00000800&(data))>>11)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_under_size(data)                        ((0x00000400&(data))>>10)
#define  OD_DMA_ODDMA_Cap_Status_get_freeze_ok(data)                             ((0x00000200&(data))>>9)
#define  OD_DMA_ODDMA_Cap_Status_get_vs_rising_occur(data)                       ((0x00000100&(data))>>8)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_block(data)                             ((0x000000C0&(data))>>6)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_fifo_full(data)                         ((0x00000010&(data))>>4)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_fifo_empty(data)                        ((0x00000008&(data))>>3)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_fifo_overflow(data)                     ((0x00000004&(data))>>2)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_fifo_underflow(data)                    ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_Cap_Status_get_cap_ddr_over_range(data)                    (0x00000001&(data))

#define  OD_DMA_ODDMA_CAP_RM                                                     0x1802CE1C
#define  OD_DMA_ODDMA_CAP_RM_reg_addr                                            "0xB802CE1C"
#define  OD_DMA_ODDMA_CAP_RM_reg                                                 0xB802CE1C
#define  OD_DMA_ODDMA_CAP_RM_inst_addr                                           "0x002F"
#define  set_OD_DMA_ODDMA_CAP_RM_reg(data)                                       (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_RM_reg)=data)
#define  get_OD_DMA_ODDMA_CAP_RM_reg                                             (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_RM_reg))
#define  OD_DMA_ODDMA_CAP_RM_pqc2_rm_1_shift                                     (24)
#define  OD_DMA_ODDMA_CAP_RM_pqc2_rm_0_shift                                     (20)
#define  OD_DMA_ODDMA_CAP_RM_pqc1_rm_0_shift                                     (16)
#define  OD_DMA_ODDMA_CAP_RM_cap_rm_shift                                        (0)
#define  OD_DMA_ODDMA_CAP_RM_pqc2_rm_1_mask                                      (0x0F000000)
#define  OD_DMA_ODDMA_CAP_RM_pqc2_rm_0_mask                                      (0x00F00000)
#define  OD_DMA_ODDMA_CAP_RM_pqc1_rm_0_mask                                      (0x000F0000)
#define  OD_DMA_ODDMA_CAP_RM_cap_rm_mask                                         (0x0000000F)
#define  OD_DMA_ODDMA_CAP_RM_pqc2_rm_1(data)                                     (0x0F000000&((data)<<24))
#define  OD_DMA_ODDMA_CAP_RM_pqc2_rm_0(data)                                     (0x00F00000&((data)<<20))
#define  OD_DMA_ODDMA_CAP_RM_pqc1_rm_0(data)                                     (0x000F0000&((data)<<16))
#define  OD_DMA_ODDMA_CAP_RM_cap_rm(data)                                        (0x0000000F&(data))
#define  OD_DMA_ODDMA_CAP_RM_get_pqc2_rm_1(data)                                 ((0x0F000000&(data))>>24)
#define  OD_DMA_ODDMA_CAP_RM_get_pqc2_rm_0(data)                                 ((0x00F00000&(data))>>20)
#define  OD_DMA_ODDMA_CAP_RM_get_pqc1_rm_0(data)                                 ((0x000F0000&(data))>>16)
#define  OD_DMA_ODDMA_CAP_RM_get_cap_rm(data)                                    (0x0000000F&(data))

#define  OD_DMA_ODDMA_CAP_RME                                                    0x1802CE20
#define  OD_DMA_ODDMA_CAP_RME_reg_addr                                           "0xB802CE20"
#define  OD_DMA_ODDMA_CAP_RME_reg                                                0xB802CE20
#define  OD_DMA_ODDMA_CAP_RME_inst_addr                                          "0x0030"
#define  set_OD_DMA_ODDMA_CAP_RME_reg(data)                                      (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_RME_reg)=data)
#define  get_OD_DMA_ODDMA_CAP_RME_reg                                            (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_RME_reg))
#define  OD_DMA_ODDMA_CAP_RME_pqc_test_rwm_shift                                 (31)
#define  OD_DMA_ODDMA_CAP_RME_pqc2_rme_1_shift                                   (18)
#define  OD_DMA_ODDMA_CAP_RME_pqc2_rme_0_shift                                   (17)
#define  OD_DMA_ODDMA_CAP_RME_pqc1_rme_0_shift                                   (16)
#define  OD_DMA_ODDMA_CAP_RME_cap_rme_shift                                      (0)
#define  OD_DMA_ODDMA_CAP_RME_pqc_test_rwm_mask                                  (0x80000000)
#define  OD_DMA_ODDMA_CAP_RME_pqc2_rme_1_mask                                    (0x00040000)
#define  OD_DMA_ODDMA_CAP_RME_pqc2_rme_0_mask                                    (0x00020000)
#define  OD_DMA_ODDMA_CAP_RME_pqc1_rme_0_mask                                    (0x00010000)
#define  OD_DMA_ODDMA_CAP_RME_cap_rme_mask                                       (0x00000001)
#define  OD_DMA_ODDMA_CAP_RME_pqc_test_rwm(data)                                 (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_CAP_RME_pqc2_rme_1(data)                                   (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_CAP_RME_pqc2_rme_0(data)                                   (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_CAP_RME_pqc1_rme_0(data)                                   (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_CAP_RME_cap_rme(data)                                      (0x00000001&(data))
#define  OD_DMA_ODDMA_CAP_RME_get_pqc_test_rwm(data)                             ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_CAP_RME_get_pqc2_rme_1(data)                               ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_CAP_RME_get_pqc2_rme_0(data)                               ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_CAP_RME_get_pqc1_rme_0(data)                               ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_CAP_RME_get_cap_rme(data)                                  (0x00000001&(data))

#define  OD_DMA_ODDMA_CAP_LS                                                     0x1802CE24
#define  OD_DMA_ODDMA_CAP_LS_reg_addr                                            "0xB802CE24"
#define  OD_DMA_ODDMA_CAP_LS_reg                                                 0xB802CE24
#define  OD_DMA_ODDMA_CAP_LS_inst_addr                                           "0x0031"
#define  set_OD_DMA_ODDMA_CAP_LS_reg(data)                                       (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_LS_reg)=data)
#define  get_OD_DMA_ODDMA_CAP_LS_reg                                             (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_LS_reg))
#define  OD_DMA_ODDMA_CAP_LS_pqc2_ls_1_shift                                     (18)
#define  OD_DMA_ODDMA_CAP_LS_pqc2_ls_0_shift                                     (17)
#define  OD_DMA_ODDMA_CAP_LS_pqc1_ls_0_shift                                     (16)
#define  OD_DMA_ODDMA_CAP_LS_cap_ls_shift                                        (0)
#define  OD_DMA_ODDMA_CAP_LS_pqc2_ls_1_mask                                      (0x00040000)
#define  OD_DMA_ODDMA_CAP_LS_pqc2_ls_0_mask                                      (0x00020000)
#define  OD_DMA_ODDMA_CAP_LS_pqc1_ls_0_mask                                      (0x00010000)
#define  OD_DMA_ODDMA_CAP_LS_cap_ls_mask                                         (0x00000001)
#define  OD_DMA_ODDMA_CAP_LS_pqc2_ls_1(data)                                     (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_CAP_LS_pqc2_ls_0(data)                                     (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_CAP_LS_pqc1_ls_0(data)                                     (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_CAP_LS_cap_ls(data)                                        (0x00000001&(data))
#define  OD_DMA_ODDMA_CAP_LS_get_pqc2_ls_1(data)                                 ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_CAP_LS_get_pqc2_ls_0(data)                                 ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_CAP_LS_get_pqc1_ls_0(data)                                 ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_CAP_LS_get_cap_ls(data)                                    (0x00000001&(data))

#define  OD_DMA_ODDMA_CAP_FAIL                                                   0x1802CE28
#define  OD_DMA_ODDMA_CAP_FAIL_reg_addr                                          "0xB802CE28"
#define  OD_DMA_ODDMA_CAP_FAIL_reg                                               0xB802CE28
#define  OD_DMA_ODDMA_CAP_FAIL_inst_addr                                         "0x0032"
#define  set_OD_DMA_ODDMA_CAP_FAIL_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_FAIL_reg)=data)
#define  get_OD_DMA_ODDMA_CAP_FAIL_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_FAIL_reg))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_5_shift                            (22)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_4_shift                            (21)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_3_shift                            (20)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_2_shift                            (19)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_1_shift                            (18)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_0_shift                            (17)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc1_bist_fail_0_shift                            (16)
#define  OD_DMA_ODDMA_CAP_FAIL_cap_bist_fail_shift                               (0)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_5_mask                             (0x00400000)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_4_mask                             (0x00200000)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_3_mask                             (0x00100000)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_2_mask                             (0x00080000)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_1_mask                             (0x00040000)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_0_mask                             (0x00020000)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc1_bist_fail_0_mask                             (0x00010000)
#define  OD_DMA_ODDMA_CAP_FAIL_cap_bist_fail_mask                                (0x00000001)
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_5(data)                            (0x00400000&((data)<<22))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_4(data)                            (0x00200000&((data)<<21))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_3(data)                            (0x00100000&((data)<<20))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_2(data)                            (0x00080000&((data)<<19))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_1(data)                            (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc2_bist_fail_0(data)                            (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_CAP_FAIL_pqc1_bist_fail_0(data)                            (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_CAP_FAIL_cap_bist_fail(data)                               (0x00000001&(data))
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc2_bist_fail_5(data)                        ((0x00400000&(data))>>22)
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc2_bist_fail_4(data)                        ((0x00200000&(data))>>21)
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc2_bist_fail_3(data)                        ((0x00100000&(data))>>20)
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc2_bist_fail_2(data)                        ((0x00080000&(data))>>19)
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc2_bist_fail_1(data)                        ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc2_bist_fail_0(data)                        ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_CAP_FAIL_get_pqc1_bist_fail_0(data)                        ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_CAP_FAIL_get_cap_bist_fail(data)                           (0x00000001&(data))

#define  OD_DMA_ODDMA_CAP_DRF_FAIL                                               0x1802CE2C
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_reg_addr                                      "0xB802CE2C"
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_reg                                           0xB802CE2C
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_inst_addr                                     "0x0033"
#define  set_OD_DMA_ODDMA_CAP_DRF_FAIL_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_DRF_FAIL_reg)=data)
#define  get_OD_DMA_ODDMA_CAP_DRF_FAIL_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_CAP_DRF_FAIL_reg))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_5_shift                         (22)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_4_shift                         (21)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_3_shift                         (20)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_2_shift                         (19)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_1_shift                         (18)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_0_shift                         (17)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc1_drf_fail_0_shift                         (16)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_cap_drf_fail_shift                            (0)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_5_mask                          (0x00400000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_4_mask                          (0x00200000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_3_mask                          (0x00100000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_2_mask                          (0x00080000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_1_mask                          (0x00040000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_0_mask                          (0x00020000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc1_drf_fail_0_mask                          (0x00010000)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_cap_drf_fail_mask                             (0x00000001)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_5(data)                         (0x00400000&((data)<<22))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_4(data)                         (0x00200000&((data)<<21))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_3(data)                         (0x00100000&((data)<<20))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_2(data)                         (0x00080000&((data)<<19))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_1(data)                         (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc2_drf_fail_0(data)                         (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_pqc1_drf_fail_0(data)                         (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_cap_drf_fail(data)                            (0x00000001&(data))
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc2_drf_fail_5(data)                     ((0x00400000&(data))>>22)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc2_drf_fail_4(data)                     ((0x00200000&(data))>>21)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc2_drf_fail_3(data)                     ((0x00100000&(data))>>20)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc2_drf_fail_2(data)                     ((0x00080000&(data))>>19)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc2_drf_fail_1(data)                     ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc2_drf_fail_0(data)                     ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_pqc1_drf_fail_0(data)                     ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_CAP_DRF_FAIL_get_cap_drf_fail(data)                        (0x00000001&(data))

#define  OD_DMA_ODDMA_CRC_CTRL                                                   0x1802CE30
#define  OD_DMA_ODDMA_CRC_CTRL_reg_addr                                          "0xB802CE30"
#define  OD_DMA_ODDMA_CRC_CTRL_reg                                               0xB802CE30
#define  OD_DMA_ODDMA_CRC_CTRL_inst_addr                                         "0x0034"
#define  set_OD_DMA_ODDMA_CRC_CTRL_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_CRC_CTRL_reg)=data)
#define  get_OD_DMA_ODDMA_CRC_CTRL_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_CRC_CTRL_reg))
#define  OD_DMA_ODDMA_CRC_CTRL_match_buffer_shift                                (28)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_comp_error_int_shift                          (27)
#define  OD_DMA_ODDMA_CRC_CTRL_dynamic_crc_cmp_en_shift                          (26)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_comp_error_flag_shift                         (24)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_bit_sel_shift                                 (21)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_pixel_encoding_shift                          (20)
#define  OD_DMA_ODDMA_CRC_CTRL_disp_crc_conti_shift                              (5)
#define  OD_DMA_ODDMA_CRC_CTRL_disp_crc_start_shift                              (4)
#define  OD_DMA_ODDMA_CRC_CTRL_cap_crc_conti_shift                               (1)
#define  OD_DMA_ODDMA_CRC_CTRL_cap_crc_start_shift                               (0)
#define  OD_DMA_ODDMA_CRC_CTRL_match_buffer_mask                                 (0x30000000)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_comp_error_int_mask                           (0x08000000)
#define  OD_DMA_ODDMA_CRC_CTRL_dynamic_crc_cmp_en_mask                           (0x04000000)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_comp_error_flag_mask                          (0x01000000)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_bit_sel_mask                                  (0x00E00000)
#define  OD_DMA_ODDMA_CRC_CTRL_crc_pixel_encoding_mask                           (0x00100000)
#define  OD_DMA_ODDMA_CRC_CTRL_disp_crc_conti_mask                               (0x00000020)
#define  OD_DMA_ODDMA_CRC_CTRL_disp_crc_start_mask                               (0x00000010)
#define  OD_DMA_ODDMA_CRC_CTRL_cap_crc_conti_mask                                (0x00000002)
#define  OD_DMA_ODDMA_CRC_CTRL_cap_crc_start_mask                                (0x00000001)
#define  OD_DMA_ODDMA_CRC_CTRL_match_buffer(data)                                (0x30000000&((data)<<28))
#define  OD_DMA_ODDMA_CRC_CTRL_crc_comp_error_int(data)                          (0x08000000&((data)<<27))
#define  OD_DMA_ODDMA_CRC_CTRL_dynamic_crc_cmp_en(data)                          (0x04000000&((data)<<26))
#define  OD_DMA_ODDMA_CRC_CTRL_crc_comp_error_flag(data)                         (0x01000000&((data)<<24))
#define  OD_DMA_ODDMA_CRC_CTRL_crc_bit_sel(data)                                 (0x00E00000&((data)<<21))
#define  OD_DMA_ODDMA_CRC_CTRL_crc_pixel_encoding(data)                          (0x00100000&((data)<<20))
#define  OD_DMA_ODDMA_CRC_CTRL_disp_crc_conti(data)                              (0x00000020&((data)<<5))
#define  OD_DMA_ODDMA_CRC_CTRL_disp_crc_start(data)                              (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_CRC_CTRL_cap_crc_conti(data)                               (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_CRC_CTRL_cap_crc_start(data)                               (0x00000001&(data))
#define  OD_DMA_ODDMA_CRC_CTRL_get_match_buffer(data)                            ((0x30000000&(data))>>28)
#define  OD_DMA_ODDMA_CRC_CTRL_get_crc_comp_error_int(data)                      ((0x08000000&(data))>>27)
#define  OD_DMA_ODDMA_CRC_CTRL_get_dynamic_crc_cmp_en(data)                      ((0x04000000&(data))>>26)
#define  OD_DMA_ODDMA_CRC_CTRL_get_crc_comp_error_flag(data)                     ((0x01000000&(data))>>24)
#define  OD_DMA_ODDMA_CRC_CTRL_get_crc_bit_sel(data)                             ((0x00E00000&(data))>>21)
#define  OD_DMA_ODDMA_CRC_CTRL_get_crc_pixel_encoding(data)                      ((0x00100000&(data))>>20)
#define  OD_DMA_ODDMA_CRC_CTRL_get_disp_crc_conti(data)                          ((0x00000020&(data))>>5)
#define  OD_DMA_ODDMA_CRC_CTRL_get_disp_crc_start(data)                          ((0x00000010&(data))>>4)
#define  OD_DMA_ODDMA_CRC_CTRL_get_cap_crc_conti(data)                           ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_CRC_CTRL_get_cap_crc_start(data)                           (0x00000001&(data))

#define  OD_DMA_ODDMA_CRC_mask                                                   0x1802CE34
#define  OD_DMA_ODDMA_CRC_mask_reg_addr                                          "0xB802CE34"
#define  OD_DMA_ODDMA_CRC_mask_reg                                               0xB802CE34
#define  OD_DMA_ODDMA_CRC_mask_inst_addr                                         "0x0035"
#define  set_OD_DMA_ODDMA_CRC_mask_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_CRC_mask_reg)=data)
#define  get_OD_DMA_ODDMA_CRC_mask_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_CRC_mask_reg))
#define  OD_DMA_ODDMA_CRC_mask_crc_mask_shift                                    (0)
#define  OD_DMA_ODDMA_CRC_mask_crc_mask_mask                                     (0x3FFFFFFF)
#define  OD_DMA_ODDMA_CRC_mask_crc_mask(data)                                    (0x3FFFFFFF&(data))
#define  OD_DMA_ODDMA_CRC_mask_get_crc_mask(data)                                (0x3FFFFFFF&(data))

#define  OD_DMA_ODDMA_Cap_L_CRC_Result                                           0x1802CE38
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_reg_addr                                  "0xB802CE38"
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_reg                                       0xB802CE38
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_inst_addr                                 "0x0036"
#define  set_OD_DMA_ODDMA_Cap_L_CRC_Result_reg(data)                             (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L_CRC_Result_reg)=data)
#define  get_OD_DMA_ODDMA_Cap_L_CRC_Result_reg                                   (*((volatile unsigned int*)OD_DMA_ODDMA_Cap_L_CRC_Result_reg))
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_cap_l_crc_result_shift                    (0)
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_cap_l_crc_result_mask                     (0xFFFFFFFF)
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_cap_l_crc_result(data)                    (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_Cap_L_CRC_Result_get_cap_l_crc_result(data)                (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_Disp_L_CRC_Result                                          0x1802CE48
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_reg_addr                                 "0xB802CE48"
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_reg                                      0xB802CE48
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_inst_addr                                "0x0037"
#define  set_OD_DMA_ODDMA_Disp_L_CRC_Result_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_L_CRC_Result_reg)=data)
#define  get_OD_DMA_ODDMA_Disp_L_CRC_Result_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_L_CRC_Result_reg))
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_disp_l_crc_result_shift                  (0)
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_disp_l_crc_result_mask                   (0xFFFFFFFF)
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_disp_l_crc_result(data)                  (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_Disp_L_CRC_Result_get_disp_l_crc_result(data)              (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_DMA_rate_CTRL                                              0x1802CE68
#define  OD_DMA_ODDMA_DMA_rate_CTRL_reg_addr                                     "0xB802CE68"
#define  OD_DMA_ODDMA_DMA_rate_CTRL_reg                                          0xB802CE68
#define  OD_DMA_ODDMA_DMA_rate_CTRL_inst_addr                                    "0x0038"
#define  set_OD_DMA_ODDMA_DMA_rate_CTRL_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_DMA_rate_CTRL_reg)=data)
#define  get_OD_DMA_ODDMA_DMA_rate_CTRL_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_DMA_rate_CTRL_reg))
#define  OD_DMA_ODDMA_DMA_rate_CTRL_disp_rate_en_shift                           (1)
#define  OD_DMA_ODDMA_DMA_rate_CTRL_cap_rate_en_shift                            (0)
#define  OD_DMA_ODDMA_DMA_rate_CTRL_disp_rate_en_mask                            (0x00000002)
#define  OD_DMA_ODDMA_DMA_rate_CTRL_cap_rate_en_mask                             (0x00000001)
#define  OD_DMA_ODDMA_DMA_rate_CTRL_disp_rate_en(data)                           (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_DMA_rate_CTRL_cap_rate_en(data)                            (0x00000001&(data))
#define  OD_DMA_ODDMA_DMA_rate_CTRL_get_disp_rate_en(data)                       ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_DMA_rate_CTRL_get_cap_rate_en(data)                        (0x00000001&(data))

#define  OD_DMA_ODDMA_Capture_rate                                               0x1802CE6C
#define  OD_DMA_ODDMA_Capture_rate_reg_addr                                      "0xB802CE6C"
#define  OD_DMA_ODDMA_Capture_rate_reg                                           0xB802CE6C
#define  OD_DMA_ODDMA_Capture_rate_inst_addr                                     "0x0039"
#define  set_OD_DMA_ODDMA_Capture_rate_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Capture_rate_reg)=data)
#define  get_OD_DMA_ODDMA_Capture_rate_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_Capture_rate_reg))
#define  OD_DMA_ODDMA_Capture_rate_cap_rate_shift                                (0)
#define  OD_DMA_ODDMA_Capture_rate_cap_rate_mask                                 (0xFFFFFFFF)
#define  OD_DMA_ODDMA_Capture_rate_cap_rate(data)                                (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_Capture_rate_get_cap_rate(data)                            (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_Display_rate                                               0x1802CE70
#define  OD_DMA_ODDMA_Display_rate_reg_addr                                      "0xB802CE70"
#define  OD_DMA_ODDMA_Display_rate_reg                                           0xB802CE70
#define  OD_DMA_ODDMA_Display_rate_inst_addr                                     "0x003A"
#define  set_OD_DMA_ODDMA_Display_rate_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Display_rate_reg)=data)
#define  get_OD_DMA_ODDMA_Display_rate_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_Display_rate_reg))
#define  OD_DMA_ODDMA_Display_rate_disp_rate_shift                               (0)
#define  OD_DMA_ODDMA_Display_rate_disp_rate_mask                                (0xFFFFFFFF)
#define  OD_DMA_ODDMA_Display_rate_disp_rate(data)                               (0xFFFFFFFF&(data))
#define  OD_DMA_ODDMA_Display_rate_get_disp_rate(data)                           (0xFFFFFFFF&(data))

#define  OD_DMA_ODDMA_Display_CTRL                                               0x1802CE80
#define  OD_DMA_ODDMA_Display_CTRL_reg_addr                                      "0xB802CE80"
#define  OD_DMA_ODDMA_Display_CTRL_reg                                           0xB802CE80
#define  OD_DMA_ODDMA_Display_CTRL_inst_addr                                     "0x003B"
#define  set_OD_DMA_ODDMA_Display_CTRL_reg(data)                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Display_CTRL_reg)=data)
#define  get_OD_DMA_ODDMA_Display_CTRL_reg                                       (*((volatile unsigned int*)OD_DMA_ODDMA_Display_CTRL_reg))
#define  OD_DMA_ODDMA_Display_CTRL_disp_3ddma_en_shift                           (8)
#define  OD_DMA_ODDMA_Display_CTRL_stop_burst_en_shift                           (4)
#define  OD_DMA_ODDMA_Display_CTRL_disp_3ddma_en_mask                            (0x00000100)
#define  OD_DMA_ODDMA_Display_CTRL_stop_burst_en_mask                            (0x00000010)
#define  OD_DMA_ODDMA_Display_CTRL_disp_3ddma_en(data)                           (0x00000100&((data)<<8))
#define  OD_DMA_ODDMA_Display_CTRL_stop_burst_en(data)                           (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_Display_CTRL_get_disp_3ddma_en(data)                       ((0x00000100&(data))>>8)
#define  OD_DMA_ODDMA_Display_CTRL_get_stop_burst_en(data)                       ((0x00000010&(data))>>4)

#define  OD_DMA_ODDMA_Display_NumWTL                                             0x1802CE8C
#define  OD_DMA_ODDMA_Display_NumWTL_reg_addr                                    "0xB802CE8C"
#define  OD_DMA_ODDMA_Display_NumWTL_reg                                         0xB802CE8C
#define  OD_DMA_ODDMA_Display_NumWTL_inst_addr                                   "0x003C"
#define  set_OD_DMA_ODDMA_Display_NumWTL_reg(data)                               (*((volatile unsigned int*)OD_DMA_ODDMA_Display_NumWTL_reg)=data)
#define  get_OD_DMA_ODDMA_Display_NumWTL_reg                                     (*((volatile unsigned int*)OD_DMA_ODDMA_Display_NumWTL_reg))
#define  OD_DMA_ODDMA_Display_NumWTL_disp_pixel_num_shift                        (16)
#define  OD_DMA_ODDMA_Display_NumWTL_disp_wtlvl_shift                            (0)
#define  OD_DMA_ODDMA_Display_NumWTL_disp_pixel_num_mask                         (0x1FFF0000)
#define  OD_DMA_ODDMA_Display_NumWTL_disp_wtlvl_mask                             (0x0000007F)
#define  OD_DMA_ODDMA_Display_NumWTL_disp_pixel_num(data)                        (0x1FFF0000&((data)<<16))
#define  OD_DMA_ODDMA_Display_NumWTL_disp_wtlvl(data)                            (0x0000007F&(data))
#define  OD_DMA_ODDMA_Display_NumWTL_get_disp_pixel_num(data)                    ((0x1FFF0000&(data))>>16)
#define  OD_DMA_ODDMA_Display_NumWTL_get_disp_wtlvl(data)                        (0x0000007F&(data))

#define  OD_DMA_ODDMA_Display_RdNumLenRem                                        0x1802CE9C
#define  OD_DMA_ODDMA_Display_RdNumLenRem_reg_addr                               "0xB802CE9C"
#define  OD_DMA_ODDMA_Display_RdNumLenRem_reg                                    0xB802CE9C
#define  OD_DMA_ODDMA_Display_RdNumLenRem_inst_addr                              "0x003D"
#define  set_OD_DMA_ODDMA_Display_RdNumLenRem_reg(data)                          (*((volatile unsigned int*)OD_DMA_ODDMA_Display_RdNumLenRem_reg)=data)
#define  get_OD_DMA_ODDMA_Display_RdNumLenRem_reg                                (*((volatile unsigned int*)OD_DMA_ODDMA_Display_RdNumLenRem_reg))
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_num_shift                    (16)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_len_shift                    (8)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_remain_shift                 (0)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_num_mask                     (0xFFFF0000)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_len_mask                     (0x00007F00)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_remain_mask                  (0x0000007F)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_num(data)                    (0xFFFF0000&((data)<<16))
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_len(data)                    (0x00007F00&((data)<<8))
#define  OD_DMA_ODDMA_Display_RdNumLenRem_disp_read_remain(data)                 (0x0000007F&(data))
#define  OD_DMA_ODDMA_Display_RdNumLenRem_get_disp_read_num(data)                ((0xFFFF0000&(data))>>16)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_get_disp_read_len(data)                ((0x00007F00&(data))>>8)
#define  OD_DMA_ODDMA_Display_RdNumLenRem_get_disp_read_remain(data)             (0x0000007F&(data))

#define  OD_DMA_ODDMA_Disp_LineStep                                              0x1802CEAC
#define  OD_DMA_ODDMA_Disp_LineStep_reg_addr                                     "0xB802CEAC"
#define  OD_DMA_ODDMA_Disp_LineStep_reg                                          0xB802CEAC
#define  OD_DMA_ODDMA_Disp_LineStep_inst_addr                                    "0x003E"
#define  set_OD_DMA_ODDMA_Disp_LineStep_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_LineStep_reg)=data)
#define  get_OD_DMA_ODDMA_Disp_LineStep_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_LineStep_reg))
#define  OD_DMA_ODDMA_Disp_LineStep_disp_line_step_shift                         (3)
#define  OD_DMA_ODDMA_Disp_LineStep_disp_line_step_mask                          (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Disp_LineStep_disp_line_step(data)                         (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Disp_LineStep_get_disp_line_step(data)                     ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Display_LineNum                                            0x1802CEBC
#define  OD_DMA_ODDMA_Display_LineNum_reg_addr                                   "0xB802CEBC"
#define  OD_DMA_ODDMA_Display_LineNum_reg                                        0xB802CEBC
#define  OD_DMA_ODDMA_Display_LineNum_inst_addr                                  "0x003F"
#define  set_OD_DMA_ODDMA_Display_LineNum_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_Display_LineNum_reg)=data)
#define  get_OD_DMA_ODDMA_Display_LineNum_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_Display_LineNum_reg))
#define  OD_DMA_ODDMA_Display_LineNum_disp_line_number_shift                     (0)
#define  OD_DMA_ODDMA_Display_LineNum_disp_line_number_mask                      (0x00001FFF)
#define  OD_DMA_ODDMA_Display_LineNum_disp_line_number(data)                     (0x00001FFF&(data))
#define  OD_DMA_ODDMA_Display_LineNum_get_disp_line_number(data)                 (0x00001FFF&(data))

#define  OD_DMA_ODDMA_Display_Status1                                            0x1802CECC
#define  OD_DMA_ODDMA_Display_Status1_reg_addr                                   "0xB802CECC"
#define  OD_DMA_ODDMA_Display_Status1_reg                                        0xB802CECC
#define  OD_DMA_ODDMA_Display_Status1_inst_addr                                  "0x0040"
#define  set_OD_DMA_ODDMA_Display_Status1_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_Display_Status1_reg)=data)
#define  get_OD_DMA_ODDMA_Display_Status1_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_Display_Status1_reg))
#define  OD_DMA_ODDMA_Display_Status1_disp_clr_over_range_shift                  (7)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_clr_shift                        (6)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_full_shift                       (5)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_empty_shift                      (4)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_overflow_shift                   (3)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_underflow_shift                  (2)
#define  OD_DMA_ODDMA_Display_Status1_disp_adr_down_over_range_shift             (1)
#define  OD_DMA_ODDMA_Display_Status1_disp_adr_up_over_range_shift               (0)
#define  OD_DMA_ODDMA_Display_Status1_disp_clr_over_range_mask                   (0x00000080)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_clr_mask                         (0x00000040)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_full_mask                        (0x00000020)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_empty_mask                       (0x00000010)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_overflow_mask                    (0x00000008)
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_underflow_mask                   (0x00000004)
#define  OD_DMA_ODDMA_Display_Status1_disp_adr_down_over_range_mask              (0x00000002)
#define  OD_DMA_ODDMA_Display_Status1_disp_adr_up_over_range_mask                (0x00000001)
#define  OD_DMA_ODDMA_Display_Status1_disp_clr_over_range(data)                  (0x00000080&((data)<<7))
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_clr(data)                        (0x00000040&((data)<<6))
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_full(data)                       (0x00000020&((data)<<5))
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_empty(data)                      (0x00000010&((data)<<4))
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_overflow(data)                   (0x00000008&((data)<<3))
#define  OD_DMA_ODDMA_Display_Status1_disp_fifo_underflow(data)                  (0x00000004&((data)<<2))
#define  OD_DMA_ODDMA_Display_Status1_disp_adr_down_over_range(data)             (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_Display_Status1_disp_adr_up_over_range(data)               (0x00000001&(data))
#define  OD_DMA_ODDMA_Display_Status1_get_disp_clr_over_range(data)              ((0x00000080&(data))>>7)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_fifo_clr(data)                    ((0x00000040&(data))>>6)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_fifo_full(data)                   ((0x00000020&(data))>>5)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_fifo_empty(data)                  ((0x00000010&(data))>>4)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_fifo_overflow(data)               ((0x00000008&(data))>>3)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_fifo_underflow(data)              ((0x00000004&(data))>>2)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_adr_down_over_range(data)         ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_Display_Status1_get_disp_adr_up_over_range(data)           (0x00000001&(data))

#define  OD_DMA_ODDMA_Display_Status2                                            0x1802CED0
#define  OD_DMA_ODDMA_Display_Status2_reg_addr                                   "0xB802CED0"
#define  OD_DMA_ODDMA_Display_Status2_reg                                        0xB802CED0
#define  OD_DMA_ODDMA_Display_Status2_inst_addr                                  "0x0041"
#define  set_OD_DMA_ODDMA_Display_Status2_reg(data)                              (*((volatile unsigned int*)OD_DMA_ODDMA_Display_Status2_reg)=data)
#define  get_OD_DMA_ODDMA_Display_Status2_reg                                    (*((volatile unsigned int*)OD_DMA_ODDMA_Display_Status2_reg))
#define  OD_DMA_ODDMA_Display_Status2_disp_read_block_shift                      (1)
#define  OD_DMA_ODDMA_Display_Status2_disp_read_block_mask                       (0x00000006)
#define  OD_DMA_ODDMA_Display_Status2_disp_read_block(data)                      (0x00000006&((data)<<1))
#define  OD_DMA_ODDMA_Display_Status2_get_disp_read_block(data)                  ((0x00000006&(data))>>1)

#define  OD_DMA_ODDMA_Disp_Start_addr_L1                                         0x1802CED4
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_reg_addr                                "0xB802CED4"
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_reg                                     0xB802CED4
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_inst_addr                               "0x0042"
#define  set_OD_DMA_ODDMA_Disp_Start_addr_L1_reg(data)                           (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_Start_addr_L1_reg)=data)
#define  get_OD_DMA_ODDMA_Disp_Start_addr_L1_reg                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_Start_addr_L1_reg))
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_disp_start_addr_l1_shift                (3)
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_disp_start_addr_l1_mask                 (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_disp_start_addr_l1(data)                (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Disp_Start_addr_L1_get_disp_start_addr_l1(data)            ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Disp_Start_addr_L2                                         0x1802CED8
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_reg_addr                                "0xB802CED8"
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_reg                                     0xB802CED8
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_inst_addr                               "0x0043"
#define  set_OD_DMA_ODDMA_Disp_Start_addr_L2_reg(data)                           (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_Start_addr_L2_reg)=data)
#define  get_OD_DMA_ODDMA_Disp_Start_addr_L2_reg                                 (*((volatile unsigned int*)OD_DMA_ODDMA_Disp_Start_addr_L2_reg))
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_disp_start_addr_l2_shift                (3)
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_disp_start_addr_l2_mask                 (0xFFFFFFF8)
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_disp_start_addr_l2(data)                (0xFFFFFFF8&((data)<<3))
#define  OD_DMA_ODDMA_Disp_Start_addr_L2_get_disp_start_addr_l2(data)            ((0xFFFFFFF8&(data))>>3)

#define  OD_DMA_ODDMA_Interrupt_Enable                                           0x1802CF54
#define  OD_DMA_ODDMA_Interrupt_Enable_reg_addr                                  "0xB802CF54"
#define  OD_DMA_ODDMA_Interrupt_Enable_reg                                       0xB802CF54
#define  OD_DMA_ODDMA_Interrupt_Enable_inst_addr                                 "0x0044"
#define  set_OD_DMA_ODDMA_Interrupt_Enable_reg(data)                             (*((volatile unsigned int*)OD_DMA_ODDMA_Interrupt_Enable_reg)=data)
#define  get_OD_DMA_ODDMA_Interrupt_Enable_reg                                   (*((volatile unsigned int*)OD_DMA_ODDMA_Interrupt_Enable_reg))
#define  OD_DMA_ODDMA_Interrupt_Enable_disp_mem_err_ie_shift                     (9)
#define  OD_DMA_ODDMA_Interrupt_Enable_disp_fifo_err_ie_shift                    (8)
#define  OD_DMA_ODDMA_Interrupt_Enable_cap_mem_err_ie_shift                      (2)
#define  OD_DMA_ODDMA_Interrupt_Enable_cap_fifo_err_ie_shift                     (1)
#define  OD_DMA_ODDMA_Interrupt_Enable_vs_rising_ie_shift                        (0)
#define  OD_DMA_ODDMA_Interrupt_Enable_disp_mem_err_ie_mask                      (0x00000200)
#define  OD_DMA_ODDMA_Interrupt_Enable_disp_fifo_err_ie_mask                     (0x00000100)
#define  OD_DMA_ODDMA_Interrupt_Enable_cap_mem_err_ie_mask                       (0x00000004)
#define  OD_DMA_ODDMA_Interrupt_Enable_cap_fifo_err_ie_mask                      (0x00000002)
#define  OD_DMA_ODDMA_Interrupt_Enable_vs_rising_ie_mask                         (0x00000001)
#define  OD_DMA_ODDMA_Interrupt_Enable_disp_mem_err_ie(data)                     (0x00000200&((data)<<9))
#define  OD_DMA_ODDMA_Interrupt_Enable_disp_fifo_err_ie(data)                    (0x00000100&((data)<<8))
#define  OD_DMA_ODDMA_Interrupt_Enable_cap_mem_err_ie(data)                      (0x00000004&((data)<<2))
#define  OD_DMA_ODDMA_Interrupt_Enable_cap_fifo_err_ie(data)                     (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_Interrupt_Enable_vs_rising_ie(data)                        (0x00000001&(data))
#define  OD_DMA_ODDMA_Interrupt_Enable_get_disp_mem_err_ie(data)                 ((0x00000200&(data))>>9)
#define  OD_DMA_ODDMA_Interrupt_Enable_get_disp_fifo_err_ie(data)                ((0x00000100&(data))>>8)
#define  OD_DMA_ODDMA_Interrupt_Enable_get_cap_mem_err_ie(data)                  ((0x00000004&(data))>>2)
#define  OD_DMA_ODDMA_Interrupt_Enable_get_cap_fifo_err_ie(data)                 ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_Interrupt_Enable_get_vs_rising_ie(data)                    (0x00000001&(data))

#define  OD_DMA_oddma_comp_decomp_clk_gated                                      0x1802CF58
#define  OD_DMA_oddma_comp_decomp_clk_gated_reg_addr                             "0xB802CF58"
#define  OD_DMA_oddma_comp_decomp_clk_gated_reg                                  0xB802CF58
#define  OD_DMA_oddma_comp_decomp_clk_gated_inst_addr                            "0x0045"
#define  set_OD_DMA_oddma_comp_decomp_clk_gated_reg(data)                        (*((volatile unsigned int*)OD_DMA_oddma_comp_decomp_clk_gated_reg)=data)
#define  get_OD_DMA_oddma_comp_decomp_clk_gated_reg                              (*((volatile unsigned int*)OD_DMA_oddma_comp_decomp_clk_gated_reg))
#define  OD_DMA_oddma_comp_decomp_clk_gated_comp_decomp_clk_en_shift             (0)
#define  OD_DMA_oddma_comp_decomp_clk_gated_comp_decomp_clk_en_mask              (0x00000001)
#define  OD_DMA_oddma_comp_decomp_clk_gated_comp_decomp_clk_en(data)             (0x00000001&(data))
#define  OD_DMA_oddma_comp_decomp_clk_gated_get_comp_decomp_clk_en(data)         (0x00000001&(data))

#define  OD_DMA_ODDMA_byte_channel_swap                                          0x1802CF60
#define  OD_DMA_ODDMA_byte_channel_swap_reg_addr                                 "0xB802CF60"
#define  OD_DMA_ODDMA_byte_channel_swap_reg                                      0xB802CF60
#define  OD_DMA_ODDMA_byte_channel_swap_inst_addr                                "0x0046"
#define  set_OD_DMA_ODDMA_byte_channel_swap_reg(data)                            (*((volatile unsigned int*)OD_DMA_ODDMA_byte_channel_swap_reg)=data)
#define  get_OD_DMA_ODDMA_byte_channel_swap_reg                                  (*((volatile unsigned int*)OD_DMA_ODDMA_byte_channel_swap_reg))
#define  OD_DMA_ODDMA_byte_channel_swap_disp_channel_swap_shift                  (20)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_8byte_swap_shift                    (19)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_4byte_swap_shift                    (18)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_2byte_swap_shift                    (17)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_1byte_swap_shift                    (16)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_channel_swap_shift                   (4)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_8byte_swap_shift                     (3)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_4byte_swap_shift                     (2)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_2byte_swap_shift                     (1)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_1byte_swap_shift                     (0)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_channel_swap_mask                   (0x00700000)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_8byte_swap_mask                     (0x00080000)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_4byte_swap_mask                     (0x00040000)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_2byte_swap_mask                     (0x00020000)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_1byte_swap_mask                     (0x00010000)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_channel_swap_mask                    (0x00000070)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_8byte_swap_mask                      (0x00000008)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_4byte_swap_mask                      (0x00000004)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_2byte_swap_mask                      (0x00000002)
#define  OD_DMA_ODDMA_byte_channel_swap_cap_1byte_swap_mask                      (0x00000001)
#define  OD_DMA_ODDMA_byte_channel_swap_disp_channel_swap(data)                  (0x00700000&((data)<<20))
#define  OD_DMA_ODDMA_byte_channel_swap_disp_8byte_swap(data)                    (0x00080000&((data)<<19))
#define  OD_DMA_ODDMA_byte_channel_swap_disp_4byte_swap(data)                    (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_byte_channel_swap_disp_2byte_swap(data)                    (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_byte_channel_swap_disp_1byte_swap(data)                    (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_byte_channel_swap_cap_channel_swap(data)                   (0x00000070&((data)<<4))
#define  OD_DMA_ODDMA_byte_channel_swap_cap_8byte_swap(data)                     (0x00000008&((data)<<3))
#define  OD_DMA_ODDMA_byte_channel_swap_cap_4byte_swap(data)                     (0x00000004&((data)<<2))
#define  OD_DMA_ODDMA_byte_channel_swap_cap_2byte_swap(data)                     (0x00000002&((data)<<1))
#define  OD_DMA_ODDMA_byte_channel_swap_cap_1byte_swap(data)                     (0x00000001&(data))
#define  OD_DMA_ODDMA_byte_channel_swap_get_disp_channel_swap(data)              ((0x00700000&(data))>>20)
#define  OD_DMA_ODDMA_byte_channel_swap_get_disp_8byte_swap(data)                ((0x00080000&(data))>>19)
#define  OD_DMA_ODDMA_byte_channel_swap_get_disp_4byte_swap(data)                ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_byte_channel_swap_get_disp_2byte_swap(data)                ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_byte_channel_swap_get_disp_1byte_swap(data)                ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_byte_channel_swap_get_cap_channel_swap(data)               ((0x00000070&(data))>>4)
#define  OD_DMA_ODDMA_byte_channel_swap_get_cap_8byte_swap(data)                 ((0x00000008&(data))>>3)
#define  OD_DMA_ODDMA_byte_channel_swap_get_cap_4byte_swap(data)                 ((0x00000004&(data))>>2)
#define  OD_DMA_ODDMA_byte_channel_swap_get_cap_2byte_swap(data)                 ((0x00000002&(data))>>1)
#define  OD_DMA_ODDMA_byte_channel_swap_get_cap_1byte_swap(data)                 (0x00000001&(data))

#define  OD_DMA_ODDMA_DISP_RM                                                    0x1802CFE0
#define  OD_DMA_ODDMA_DISP_RM_reg_addr                                           "0xB802CFE0"
#define  OD_DMA_ODDMA_DISP_RM_reg                                                0xB802CFE0
#define  OD_DMA_ODDMA_DISP_RM_inst_addr                                          "0x0047"
#define  set_OD_DMA_ODDMA_DISP_RM_reg(data)                                      (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_RM_reg)=data)
#define  get_OD_DMA_ODDMA_DISP_RM_reg                                            (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_RM_reg))
#define  OD_DMA_ODDMA_DISP_RM_pqdc2_rm_0_shift                                   (20)
#define  OD_DMA_ODDMA_DISP_RM_pqdc1_rm_0_shift                                   (16)
#define  OD_DMA_ODDMA_DISP_RM_disp_rm_shift                                      (0)
#define  OD_DMA_ODDMA_DISP_RM_pqdc2_rm_0_mask                                    (0x00F00000)
#define  OD_DMA_ODDMA_DISP_RM_pqdc1_rm_0_mask                                    (0x000F0000)
#define  OD_DMA_ODDMA_DISP_RM_disp_rm_mask                                       (0x0000000F)
#define  OD_DMA_ODDMA_DISP_RM_pqdc2_rm_0(data)                                   (0x00F00000&((data)<<20))
#define  OD_DMA_ODDMA_DISP_RM_pqdc1_rm_0(data)                                   (0x000F0000&((data)<<16))
#define  OD_DMA_ODDMA_DISP_RM_disp_rm(data)                                      (0x0000000F&(data))
#define  OD_DMA_ODDMA_DISP_RM_get_pqdc2_rm_0(data)                               ((0x00F00000&(data))>>20)
#define  OD_DMA_ODDMA_DISP_RM_get_pqdc1_rm_0(data)                               ((0x000F0000&(data))>>16)
#define  OD_DMA_ODDMA_DISP_RM_get_disp_rm(data)                                  (0x0000000F&(data))

#define  OD_DMA_ODDMA_DISP_RME                                                   0x1802CFE4
#define  OD_DMA_ODDMA_DISP_RME_reg_addr                                          "0xB802CFE4"
#define  OD_DMA_ODDMA_DISP_RME_reg                                               0xB802CFE4
#define  OD_DMA_ODDMA_DISP_RME_inst_addr                                         "0x0048"
#define  set_OD_DMA_ODDMA_DISP_RME_reg(data)                                     (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_RME_reg)=data)
#define  get_OD_DMA_ODDMA_DISP_RME_reg                                           (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_RME_reg))
#define  OD_DMA_ODDMA_DISP_RME_pqdc_test_rwm_shift                               (31)
#define  OD_DMA_ODDMA_DISP_RME_pqdc2_rme_0_shift                                 (17)
#define  OD_DMA_ODDMA_DISP_RME_pqdc1_rme_0_shift                                 (16)
#define  OD_DMA_ODDMA_DISP_RME_disp_rme_shift                                    (0)
#define  OD_DMA_ODDMA_DISP_RME_pqdc_test_rwm_mask                                (0x80000000)
#define  OD_DMA_ODDMA_DISP_RME_pqdc2_rme_0_mask                                  (0x00020000)
#define  OD_DMA_ODDMA_DISP_RME_pqdc1_rme_0_mask                                  (0x00010000)
#define  OD_DMA_ODDMA_DISP_RME_disp_rme_mask                                     (0x00000001)
#define  OD_DMA_ODDMA_DISP_RME_pqdc_test_rwm(data)                               (0x80000000&((data)<<31))
#define  OD_DMA_ODDMA_DISP_RME_pqdc2_rme_0(data)                                 (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_DISP_RME_pqdc1_rme_0(data)                                 (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_DISP_RME_disp_rme(data)                                    (0x00000001&(data))
#define  OD_DMA_ODDMA_DISP_RME_get_pqdc_test_rwm(data)                           ((0x80000000&(data))>>31)
#define  OD_DMA_ODDMA_DISP_RME_get_pqdc2_rme_0(data)                             ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_DISP_RME_get_pqdc1_rme_0(data)                             ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_DISP_RME_get_disp_rme(data)                                (0x00000001&(data))

#define  OD_DMA_ODDMA_DISP_LS                                                    0x1802CFE8
#define  OD_DMA_ODDMA_DISP_LS_reg_addr                                           "0xB802CFE8"
#define  OD_DMA_ODDMA_DISP_LS_reg                                                0xB802CFE8
#define  OD_DMA_ODDMA_DISP_LS_inst_addr                                          "0x0049"
#define  set_OD_DMA_ODDMA_DISP_LS_reg(data)                                      (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_LS_reg)=data)
#define  get_OD_DMA_ODDMA_DISP_LS_reg                                            (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_LS_reg))
#define  OD_DMA_ODDMA_DISP_LS_pqdc2_ls_0_shift                                   (17)
#define  OD_DMA_ODDMA_DISP_LS_pqdc1_ls_0_shift                                   (16)
#define  OD_DMA_ODDMA_DISP_LS_disp_ls_shift                                      (0)
#define  OD_DMA_ODDMA_DISP_LS_pqdc2_ls_0_mask                                    (0x00020000)
#define  OD_DMA_ODDMA_DISP_LS_pqdc1_ls_0_mask                                    (0x00010000)
#define  OD_DMA_ODDMA_DISP_LS_disp_ls_mask                                       (0x00000001)
#define  OD_DMA_ODDMA_DISP_LS_pqdc2_ls_0(data)                                   (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_DISP_LS_pqdc1_ls_0(data)                                   (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_DISP_LS_disp_ls(data)                                      (0x00000001&(data))
#define  OD_DMA_ODDMA_DISP_LS_get_pqdc2_ls_0(data)                               ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_DISP_LS_get_pqdc1_ls_0(data)                               ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_DISP_LS_get_disp_ls(data)                                  (0x00000001&(data))

#define  OD_DMA_ODDMA_DISP_BIST_FAIL                                             0x1802CFEC
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_reg_addr                                    "0xB802CFEC"
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_reg                                         0xB802CFEC
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_inst_addr                                   "0x004A"
#define  set_OD_DMA_ODDMA_DISP_BIST_FAIL_reg(data)                               (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_BIST_FAIL_reg)=data)
#define  get_OD_DMA_ODDMA_DISP_BIST_FAIL_reg                                     (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_BIST_FAIL_reg))
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc2_bist_fail_1_shift                     (18)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc2_bist_fail_0_shift                     (17)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc1_bist_fail_0_shift                     (16)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_disp_bist_fail_shift                        (0)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc2_bist_fail_1_mask                      (0x00040000)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc2_bist_fail_0_mask                      (0x00020000)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc1_bist_fail_0_mask                      (0x00010000)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_disp_bist_fail_mask                         (0x00000001)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc2_bist_fail_1(data)                     (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc2_bist_fail_0(data)                     (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_pqdc1_bist_fail_0(data)                     (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_disp_bist_fail(data)                        (0x00000001&(data))
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_get_pqdc2_bist_fail_1(data)                 ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_get_pqdc2_bist_fail_0(data)                 ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_get_pqdc1_bist_fail_0(data)                 ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_DISP_BIST_FAIL_get_disp_bist_fail(data)                    (0x00000001&(data))

#define  OD_DMA_ODDMA_DISP_DRF_FAIL                                              0x1802CFF0
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_reg_addr                                     "0xB802CFF0"
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_reg                                          0xB802CFF0
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_inst_addr                                    "0x004B"
#define  set_OD_DMA_ODDMA_DISP_DRF_FAIL_reg(data)                                (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_DRF_FAIL_reg)=data)
#define  get_OD_DMA_ODDMA_DISP_DRF_FAIL_reg                                      (*((volatile unsigned int*)OD_DMA_ODDMA_DISP_DRF_FAIL_reg))
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc2_drf_fail_1_shift                       (18)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc2_drf_fail_0_shift                       (17)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc1_drf_fail_0_shift                       (16)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_disp_drf_fail_shift                          (0)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc2_drf_fail_1_mask                        (0x00040000)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc2_drf_fail_0_mask                        (0x00020000)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc1_drf_fail_0_mask                        (0x00010000)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_disp_drf_fail_mask                           (0x00000001)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc2_drf_fail_1(data)                       (0x00040000&((data)<<18))
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc2_drf_fail_0(data)                       (0x00020000&((data)<<17))
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_pqdc1_drf_fail_0(data)                       (0x00010000&((data)<<16))
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_disp_drf_fail(data)                          (0x00000001&(data))
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_get_pqdc2_drf_fail_1(data)                   ((0x00040000&(data))>>18)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_get_pqdc2_drf_fail_0(data)                   ((0x00020000&(data))>>17)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_get_pqdc1_drf_fail_0(data)                   ((0x00010000&(data))>>16)
#define  OD_DMA_ODDMA_DISP_DRF_FAIL_get_disp_drf_fail(data)                      (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OD_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  cmp_width_div32:9;
        RBus_UInt32  res2:2;
        RBus_UInt32  cmp_height:14;
    };
}od_dma_oddma_pq_cmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802cd04_31:1;
        RBus_UInt32  eco_reg_vsync_no_req:1;
        RBus_UInt32  dummy1802cd04_29_5:25;
        RBus_UInt32  cmp_data_color:1;
        RBus_UInt32  cmp_data_bit_width:2;
        RBus_UInt32  cmp_data_format:2;
    };
}od_dma_oddma_pq_cmp_pair_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  first_line_more_bit:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  block_limit_bit:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  line_limit_bit:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  frame_limit_bit:6;
    };
}od_dma_oddma_pq_cmp_bit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  g_ratio:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  guarantee_max_qp_en:1;
        RBus_UInt32  dynamic_allocate_ratio_en:1;
        RBus_UInt32  poor_limit_min_qp_en:1;
        RBus_UInt32  balance_en:1;
        RBus_UInt32  fisrt_line_more_en:1;
        RBus_UInt32  two_line_prediction_en:1;
        RBus_UInt32  do_422_mode:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  not_enough_bit_do_422_en:1;
        RBus_UInt32  not_rich_do_422_en:1;
        RBus_UInt32  rb_lossy_do_422_en:1;
    };
}od_dma_oddma_pq_cmp_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  not_enough_bit_do_422_qp:3;
        RBus_UInt32  not_rich_do_422_th:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  rb_lossy_do_422_qp_level:3;
        RBus_UInt32  res3:4;
        RBus_UInt32  variation_value_th:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  variation_num_th:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  variation_near_num_th:3;
    };
}od_dma_oddma_pq_cmp_smooth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dynamic_allocate_ratio_max:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dynamic_allocate_ratio_min:5;
        RBus_UInt32  res3:5;
        RBus_UInt32  dynamic_allocate_line:3;
        RBus_UInt32  dynamic_allocate_more:4;
        RBus_UInt32  dynamic_allocate_less:4;
    };
}od_dma_oddma_pq_cmp_allocate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  poor_limit_th_qp4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  poor_limit_th_qp3:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  poor_limit_th_qp2:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  poor_limit_th_qp1:5;
    };
}od_dma_oddma_pq_cmp_poor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  guarantee_max_rb_qp:4;
        RBus_UInt32  guarantee_max_g_qp:4;
    };
}od_dma_oddma_pq_cmp_guarantee_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  balance_rb_ov_th:2;
        RBus_UInt32  balance_rb_ud_th:2;
        RBus_UInt32  balance_rb_give:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  balance_g_ov_th:2;
        RBus_UInt32  balance_g_ud_th:2;
        RBus_UInt32  balance_g_give:2;
    };
}od_dma_oddma_pq_cmp_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  block_fifo_overflow_irq_en:1;
        RBus_UInt32  input_size_more_irq_en:1;
        RBus_UInt32  input_size_less_irq_en:1;
        RBus_UInt32  over_flb_irq_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  request_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  g_fifo_even_overflow_irq_en:1;
        RBus_UInt32  r_fifo_even_overflow_irq_en:1;
        RBus_UInt32  b_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res4:4;
    };
}od_dma_oddma_pq_cmp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pqc_irq:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  block_fifo_overflow_st:1;
        RBus_UInt32  input_size_more_st:1;
        RBus_UInt32  input_size_less_st:1;
        RBus_UInt32  over_flb_st:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  request_fifo_even_overflow_st:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  g_fifo_even_overflow_st:1;
        RBus_UInt32  r_fifo_even_overflow_st:1;
        RBus_UInt32  b_fifo_even_overflow_st:1;
        RBus_UInt32  res4:4;
    };
}od_dma_oddma_pq_cmp_irq_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_two_pixel_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  g_ratio_max:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  g_ratio_min:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  cmp_package_height_cnt:14;
    };
}od_dma_oddma_pq_cmp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  long_term_qp_measure_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  long_term_g_qp_max:4;
        RBus_UInt32  long_term_rb_qp_max:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  short_term_g_qp_max:4;
        RBus_UInt32  short_term_rb_qp_max:4;
    };
}od_dma_oddma_pq_cmp_qp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_water_measure_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  fifo_water_even_g:8;
        RBus_UInt32  fifo_water_even_r:8;
        RBus_UInt32  fifo_water_even_b:8;
    };
}od_dma_oddma_pq_cmp_fifo_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  g_frame_left:16;
        RBus_UInt32  rb_frame_left:16;
    };
}od_dma_oddma_pq_cmp_left_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_package_long_term:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  total_package_even:24;
    };
}od_dma_oddma_pq_cmp_package_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_g:32;
    };
}od_dma_oddma_pq_cmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_r:32;
    };
}od_dma_oddma_pq_cmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_b:32;
    };
}od_dma_oddma_pq_cmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  decmp_width_div32:9;
        RBus_UInt32  res2:2;
        RBus_UInt32  decmp_height:14;
    };
}od_dma_oddma_pq_decmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802cd64_31_5:27;
        RBus_UInt32  decmp_data_color:1;
        RBus_UInt32  decmp_data_bit_width:2;
        RBus_UInt32  decmp_data_format:2;
    };
}od_dma_oddma_pq_decmp_pair_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  saturation_type:1;
        RBus_UInt32  saturation_en:1;
    };
}od_dma_oddma_pq_decmp_sat_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  not_finish_irq_even_en:1;
        RBus_UInt32  underflow_irq_even_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  crc_r_error_even_en:1;
        RBus_UInt32  crc_g_error_even_en:1;
        RBus_UInt32  crc_b_error_even_en:1;
        RBus_UInt32  res3:16;
    };
}od_dma_oddma_pq_decmp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pqdc_irq:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  in_fifo_overflow_even_st:1;
        RBus_UInt32  ring_r_overflow_even_st:1;
        RBus_UInt32  ring_g_overflow_even_st:1;
        RBus_UInt32  ring_b_overflow_even_st:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  not_finish_irq_even_st:1;
        RBus_UInt32  underflow_irq_even_st:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  crc_r_error_even_st:1;
        RBus_UInt32  crc_g_error_even_st:1;
        RBus_UInt32  crc_b_error_even_st:1;
        RBus_UInt32  res4:16;
    };
}od_dma_oddma_pq_decmp_irq_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_en_do_422:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  mark_en_qp_sel:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  mark_en_qp7:1;
        RBus_UInt32  mark_en_qp6:1;
        RBus_UInt32  mark_en_qp5:1;
        RBus_UInt32  mark_en_qp4:1;
        RBus_UInt32  mark_en_qp3:1;
        RBus_UInt32  mark_en_qp2:1;
        RBus_UInt32  mark_en_qp1:1;
        RBus_UInt32  mark_en_qp0:1;
    };
}od_dma_oddma_pq_decmp_mark_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_0:16;
        RBus_UInt32  mark_color_1:16;
    };
}od_dma_oddma_pq_decmp_mark_color_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_2:16;
        RBus_UInt32  mark_color_3:16;
    };
}od_dma_oddma_pq_decmp_mark_color_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_4:16;
        RBus_UInt32  mark_color_5:16;
    };
}od_dma_oddma_pq_decmp_mark_color_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_6:16;
        RBus_UInt32  mark_color_7:16;
    };
}od_dma_oddma_pq_decmp_mark_color_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mark_color_422:16;
    };
}od_dma_oddma_pq_decmp_mark_color_422_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_two_pixel_mode:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  res2:2;
        RBus_UInt32  decmp_package_height_cnt:14;
    };
}od_dma_oddma_pq_decmp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_g:32;
    };
}od_dma_oddma_pq_decmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_r:32;
    };
}od_dma_oddma_pq_decmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_b:32;
    };
}od_dma_oddma_pq_decmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  tr_en:1;
    };
}od_dma_oddma_pq_decmp_compensation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  smooth_tog_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp_db_apply:1;
        RBus_UInt32  disp_db_rd_sel:1;
        RBus_UInt32  disp_db_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_db_apply:1;
        RBus_UInt32  cap_db_rd_sel:1;
        RBus_UInt32  cap_db_en:1;
    };
}od_dma_od_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  hact:15;
    };
}od_dma_oddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  comp_de_comp_bypass:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  cap_en:1;
        RBus_UInt32  res5:19;
    };
}od_dma_oddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  bit_sel:2;
        RBus_UInt32  pixel_encoding:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_write_rem:7;
    };
}od_dma_oddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  cap_write_num:16;
    };
}od_dma_oddma_cap_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_up_limit:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_low_limit:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_line_step:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l2_start:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  cap_block:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}od_dma_oddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pqc2_rm_1:4;
        RBus_UInt32  pqc2_rm_0:4;
        RBus_UInt32  pqc1_rm_0:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  cap_rm:4;
    };
}od_dma_oddma_cap_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pqc_test_rwm:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  pqc2_rme_1:1;
        RBus_UInt32  pqc2_rme_0:1;
        RBus_UInt32  pqc1_rme_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  cap_rme:1;
    };
}od_dma_oddma_cap_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pqc2_ls_1:1;
        RBus_UInt32  pqc2_ls_0:1;
        RBus_UInt32  pqc1_ls_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  cap_ls:1;
    };
}od_dma_oddma_cap_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pqc2_bist_fail_5:1;
        RBus_UInt32  pqc2_bist_fail_4:1;
        RBus_UInt32  pqc2_bist_fail_3:1;
        RBus_UInt32  pqc2_bist_fail_2:1;
        RBus_UInt32  pqc2_bist_fail_1:1;
        RBus_UInt32  pqc2_bist_fail_0:1;
        RBus_UInt32  pqc1_bist_fail_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  cap_bist_fail:1;
    };
}od_dma_oddma_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pqc2_drf_fail_5:1;
        RBus_UInt32  pqc2_drf_fail_4:1;
        RBus_UInt32  pqc2_drf_fail_3:1;
        RBus_UInt32  pqc2_drf_fail_2:1;
        RBus_UInt32  pqc2_drf_fail_1:1;
        RBus_UInt32  pqc2_drf_fail_0:1;
        RBus_UInt32  pqc1_drf_fail_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  cap_drf_fail:1;
    };
}od_dma_oddma_cap_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  match_buffer:2;
        RBus_UInt32  crc_comp_error_int:1;
        RBus_UInt32  dynamic_crc_cmp_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  crc_comp_error_flag:1;
        RBus_UInt32  crc_bit_sel:3;
        RBus_UInt32  crc_pixel_encoding:1;
        RBus_UInt32  res3:14;
        RBus_UInt32  disp_crc_conti:1;
        RBus_UInt32  disp_crc_start:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  cap_crc_conti:1;
        RBus_UInt32  cap_crc_start:1;
    };
}od_dma_oddma_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  crc_mask:30;
    };
}od_dma_oddma_crc_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l_crc_result:32;
    };
}od_dma_oddma_cap_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_l_crc_result:32;
    };
}od_dma_oddma_disp_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  disp_rate_en:1;
        RBus_UInt32  cap_rate_en:1;
    };
}od_dma_oddma_dma_rate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rate:32;
    };
}od_dma_oddma_capture_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_rate:32;
    };
}od_dma_oddma_display_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  disp_3ddma_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  stop_burst_en:1;
        RBus_UInt32  res3:4;
    };
}od_dma_oddma_display_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp_pixel_num:13;
        RBus_UInt32  res2:9;
        RBus_UInt32  disp_wtlvl:7;
    };
}od_dma_oddma_display_numwtl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_read_num:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_read_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp_read_remain:7;
    };
}od_dma_oddma_display_rdnumlenrem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_line_step:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  disp_line_number:13;
    };
}od_dma_oddma_display_linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  disp_clr_over_range:1;
        RBus_UInt32  disp_fifo_clr:1;
        RBus_UInt32  disp_fifo_full:1;
        RBus_UInt32  disp_fifo_empty:1;
        RBus_UInt32  disp_fifo_overflow:1;
        RBus_UInt32  disp_fifo_underflow:1;
        RBus_UInt32  disp_adr_down_over_range:1;
        RBus_UInt32  disp_adr_up_over_range:1;
    };
}od_dma_oddma_display_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  disp_read_block:2;
        RBus_UInt32  res2:1;
    };
}od_dma_oddma_display_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_start_addr_l1:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp_start_addr_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_start_addr_l2:29;
        RBus_UInt32  res1:3;
    };
}od_dma_oddma_disp_start_addr_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  disp_mem_err_ie:1;
        RBus_UInt32  disp_fifo_err_ie:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cap_mem_err_ie:1;
        RBus_UInt32  cap_fifo_err_ie:1;
        RBus_UInt32  vs_rising_ie:1;
    };
}od_dma_oddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  comp_decomp_clk_en:1;
    };
}od_dma_oddma_comp_decomp_clk_gated_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  disp_channel_swap:3;
        RBus_UInt32  disp_8byte_swap:1;
        RBus_UInt32  disp_4byte_swap:1;
        RBus_UInt32  disp_2byte_swap:1;
        RBus_UInt32  disp_1byte_swap:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  cap_channel_swap:3;
        RBus_UInt32  cap_8byte_swap:1;
        RBus_UInt32  cap_4byte_swap:1;
        RBus_UInt32  cap_2byte_swap:1;
        RBus_UInt32  cap_1byte_swap:1;
    };
}od_dma_oddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pqdc2_rm_0:4;
        RBus_UInt32  pqdc1_rm_0:4;
        RBus_UInt32  res2:12;
        RBus_UInt32  disp_rm:4;
    };
}od_dma_oddma_disp_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pqdc_test_rwm:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  pqdc2_rme_0:1;
        RBus_UInt32  pqdc1_rme_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  disp_rme:1;
    };
}od_dma_oddma_disp_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  pqdc2_ls_0:1;
        RBus_UInt32  pqdc1_ls_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  disp_ls:1;
    };
}od_dma_oddma_disp_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pqdc2_bist_fail_1:1;
        RBus_UInt32  pqdc2_bist_fail_0:1;
        RBus_UInt32  pqdc1_bist_fail_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  disp_bist_fail:1;
    };
}od_dma_oddma_disp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pqdc2_drf_fail_1:1;
        RBus_UInt32  pqdc2_drf_fail_0:1;
        RBus_UInt32  pqdc1_drf_fail_0:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  disp_drf_fail:1;
    };
}od_dma_oddma_disp_drf_fail_RBUS;

#else //apply LITTLE_ENDIAN

//======OD_DMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_height:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cmp_width_div32:9;
        RBus_UInt32  res2:6;
        RBus_UInt32  cmp_en:1;
    };
}od_dma_oddma_pq_cmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_data_format:2;
        RBus_UInt32  cmp_data_bit_width:2;
        RBus_UInt32  cmp_data_color:1;
        RBus_UInt32  dummy1802cd04_29_5:25;
        RBus_UInt32  eco_reg_vsync_no_req:1;
        RBus_UInt32  dummy1802cd04_31:1;
    };
}od_dma_oddma_pq_cmp_pair_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_limit_bit:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  line_limit_bit:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  block_limit_bit:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  first_line_more_bit:6;
        RBus_UInt32  res4:2;
    };
}od_dma_oddma_pq_cmp_bit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rb_lossy_do_422_en:1;
        RBus_UInt32  not_rich_do_422_en:1;
        RBus_UInt32  not_enough_bit_do_422_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  do_422_mode:2;
        RBus_UInt32  two_line_prediction_en:1;
        RBus_UInt32  fisrt_line_more_en:1;
        RBus_UInt32  balance_en:1;
        RBus_UInt32  poor_limit_min_qp_en:1;
        RBus_UInt32  dynamic_allocate_ratio_en:1;
        RBus_UInt32  guarantee_max_qp_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  g_ratio:5;
        RBus_UInt32  res3:11;
    };
}od_dma_oddma_pq_cmp_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  variation_near_num_th:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  variation_num_th:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  variation_value_th:4;
        RBus_UInt32  res3:4;
        RBus_UInt32  rb_lossy_do_422_qp_level:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  not_rich_do_422_th:4;
        RBus_UInt32  not_enough_bit_do_422_qp:3;
        RBus_UInt32  res5:5;
    };
}od_dma_oddma_pq_cmp_smooth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dynamic_allocate_less:4;
        RBus_UInt32  dynamic_allocate_more:4;
        RBus_UInt32  dynamic_allocate_line:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  dynamic_allocate_ratio_min:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dynamic_allocate_ratio_max:5;
        RBus_UInt32  res3:3;
    };
}od_dma_oddma_pq_cmp_allocate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  poor_limit_th_qp1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  poor_limit_th_qp2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  poor_limit_th_qp3:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  poor_limit_th_qp4:5;
        RBus_UInt32  res4:3;
    };
}od_dma_oddma_pq_cmp_poor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  guarantee_max_g_qp:4;
        RBus_UInt32  guarantee_max_rb_qp:4;
        RBus_UInt32  res1:24;
    };
}od_dma_oddma_pq_cmp_guarantee_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  balance_g_give:2;
        RBus_UInt32  balance_g_ud_th:2;
        RBus_UInt32  balance_g_ov_th:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  balance_rb_give:2;
        RBus_UInt32  balance_rb_ud_th:2;
        RBus_UInt32  balance_rb_ov_th:2;
        RBus_UInt32  res2:18;
    };
}od_dma_oddma_pq_cmp_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  b_fifo_even_overflow_irq_en:1;
        RBus_UInt32  r_fifo_even_overflow_irq_en:1;
        RBus_UInt32  g_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  request_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  over_flb_irq_en:1;
        RBus_UInt32  input_size_less_irq_en:1;
        RBus_UInt32  input_size_more_irq_en:1;
        RBus_UInt32  block_fifo_overflow_irq_en:1;
        RBus_UInt32  res4:16;
    };
}od_dma_oddma_pq_cmp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  b_fifo_even_overflow_st:1;
        RBus_UInt32  r_fifo_even_overflow_st:1;
        RBus_UInt32  g_fifo_even_overflow_st:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  request_fifo_even_overflow_st:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  over_flb_st:1;
        RBus_UInt32  input_size_less_st:1;
        RBus_UInt32  input_size_more_st:1;
        RBus_UInt32  block_fifo_overflow_st:1;
        RBus_UInt32  res4:15;
        RBus_UInt32  pqc_irq:1;
    };
}od_dma_oddma_pq_cmp_irq_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_package_height_cnt:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  g_ratio_min:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  g_ratio_max:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  cmp_two_pixel_mode:1;
    };
}od_dma_oddma_pq_cmp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  short_term_rb_qp_max:4;
        RBus_UInt32  short_term_g_qp_max:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  long_term_rb_qp_max:4;
        RBus_UInt32  long_term_g_qp_max:4;
        RBus_UInt32  res2:7;
        RBus_UInt32  long_term_qp_measure_en:1;
    };
}od_dma_oddma_pq_cmp_qp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_water_even_b:8;
        RBus_UInt32  fifo_water_even_r:8;
        RBus_UInt32  fifo_water_even_g:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  fifo_water_measure_en:1;
    };
}od_dma_oddma_pq_cmp_fifo_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rb_frame_left:16;
        RBus_UInt32  g_frame_left:16;
    };
}od_dma_oddma_pq_cmp_left_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_package_even:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  total_package_long_term:1;
    };
}od_dma_oddma_pq_cmp_package_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_g:32;
    };
}od_dma_oddma_pq_cmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_r:32;
    };
}od_dma_oddma_pq_cmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_b:32;
    };
}od_dma_oddma_pq_cmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_height:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  decmp_width_div32:9;
        RBus_UInt32  res2:6;
        RBus_UInt32  decmp_en:1;
    };
}od_dma_oddma_pq_decmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_data_format:2;
        RBus_UInt32  decmp_data_bit_width:2;
        RBus_UInt32  decmp_data_color:1;
        RBus_UInt32  dummy1802cd64_31_5:27;
    };
}od_dma_oddma_pq_decmp_pair_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  saturation_en:1;
        RBus_UInt32  saturation_type:1;
        RBus_UInt32  res1:30;
    };
}od_dma_oddma_pq_decmp_sat_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_b_error_even_en:1;
        RBus_UInt32  crc_g_error_even_en:1;
        RBus_UInt32  crc_r_error_even_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  underflow_irq_even_en:1;
        RBus_UInt32  not_finish_irq_even_en:1;
        RBus_UInt32  res3:10;
    };
}od_dma_oddma_pq_decmp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  crc_b_error_even_st:1;
        RBus_UInt32  crc_g_error_even_st:1;
        RBus_UInt32  crc_r_error_even_st:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  underflow_irq_even_st:1;
        RBus_UInt32  not_finish_irq_even_st:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ring_b_overflow_even_st:1;
        RBus_UInt32  ring_g_overflow_even_st:1;
        RBus_UInt32  ring_r_overflow_even_st:1;
        RBus_UInt32  in_fifo_overflow_even_st:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  pqdc_irq:1;
    };
}od_dma_oddma_pq_decmp_irq_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_en_qp0:1;
        RBus_UInt32  mark_en_qp1:1;
        RBus_UInt32  mark_en_qp2:1;
        RBus_UInt32  mark_en_qp3:1;
        RBus_UInt32  mark_en_qp4:1;
        RBus_UInt32  mark_en_qp5:1;
        RBus_UInt32  mark_en_qp6:1;
        RBus_UInt32  mark_en_qp7:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  mark_en_qp_sel:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  mark_en_do_422:1;
    };
}od_dma_oddma_pq_decmp_mark_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_1:16;
        RBus_UInt32  mark_color_0:16;
    };
}od_dma_oddma_pq_decmp_mark_color_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_3:16;
        RBus_UInt32  mark_color_2:16;
    };
}od_dma_oddma_pq_decmp_mark_color_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_5:16;
        RBus_UInt32  mark_color_4:16;
    };
}od_dma_oddma_pq_decmp_mark_color_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_7:16;
        RBus_UInt32  mark_color_6:16;
    };
}od_dma_oddma_pq_decmp_mark_color_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_422:16;
        RBus_UInt32  res1:16;
    };
}od_dma_oddma_pq_decmp_mark_color_422_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_package_height_cnt:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:15;
        RBus_UInt32  decmp_two_pixel_mode:1;
    };
}od_dma_oddma_pq_decmp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_g:32;
    };
}od_dma_oddma_pq_decmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_r:32;
    };
}od_dma_oddma_pq_decmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_b:32;
    };
}od_dma_oddma_pq_decmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tr_en:1;
        RBus_UInt32  res1:31;
    };
}od_dma_oddma_pq_decmp_compensation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_db_en:1;
        RBus_UInt32  cap_db_rd_sel:1;
        RBus_UInt32  cap_db_apply:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_db_en:1;
        RBus_UInt32  disp_db_rd_sel:1;
        RBus_UInt32  disp_db_apply:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  smooth_tog_en:1;
        RBus_UInt32  res3:23;
    };
}od_dma_od_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  vact:16;
    };
}od_dma_oddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  cap_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  comp_de_comp_bypass:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  res5:1;
    };
}od_dma_oddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pixel_encoding:1;
        RBus_UInt32  bit_sel:2;
        RBus_UInt32  res3:13;
    };
}od_dma_oddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:16;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  res1:9;
    };
}od_dma_oddma_cap_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_up_limit:29;
    };
}od_dma_oddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_low_limit:29;
    };
}od_dma_oddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_line_step:29;
    };
}od_dma_oddma_cap_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start:29;
    };
}od_dma_oddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l2_start:29;
    };
}od_dma_oddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start_db:29;
    };
}od_dma_oddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_block:2;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  res2:20;
    };
}od_dma_oddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rm:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  pqc1_rm_0:4;
        RBus_UInt32  pqc2_rm_0:4;
        RBus_UInt32  pqc2_rm_1:4;
        RBus_UInt32  res2:4;
    };
}od_dma_oddma_cap_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rme:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqc1_rme_0:1;
        RBus_UInt32  pqc2_rme_0:1;
        RBus_UInt32  pqc2_rme_1:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  pqc_test_rwm:1;
    };
}od_dma_oddma_cap_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ls:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqc1_ls_0:1;
        RBus_UInt32  pqc2_ls_0:1;
        RBus_UInt32  pqc2_ls_1:1;
        RBus_UInt32  res2:13;
    };
}od_dma_oddma_cap_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_bist_fail:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqc1_bist_fail_0:1;
        RBus_UInt32  pqc2_bist_fail_0:1;
        RBus_UInt32  pqc2_bist_fail_1:1;
        RBus_UInt32  pqc2_bist_fail_2:1;
        RBus_UInt32  pqc2_bist_fail_3:1;
        RBus_UInt32  pqc2_bist_fail_4:1;
        RBus_UInt32  pqc2_bist_fail_5:1;
        RBus_UInt32  res2:9;
    };
}od_dma_oddma_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_drf_fail:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqc1_drf_fail_0:1;
        RBus_UInt32  pqc2_drf_fail_0:1;
        RBus_UInt32  pqc2_drf_fail_1:1;
        RBus_UInt32  pqc2_drf_fail_2:1;
        RBus_UInt32  pqc2_drf_fail_3:1;
        RBus_UInt32  pqc2_drf_fail_4:1;
        RBus_UInt32  pqc2_drf_fail_5:1;
        RBus_UInt32  res2:9;
    };
}od_dma_oddma_cap_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_crc_start:1;
        RBus_UInt32  cap_crc_conti:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  disp_crc_start:1;
        RBus_UInt32  disp_crc_conti:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  crc_pixel_encoding:1;
        RBus_UInt32  crc_bit_sel:3;
        RBus_UInt32  crc_comp_error_flag:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dynamic_crc_cmp_en:1;
        RBus_UInt32  crc_comp_error_int:1;
        RBus_UInt32  match_buffer:2;
        RBus_UInt32  res4:2;
    };
}od_dma_oddma_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_mask:30;
        RBus_UInt32  res1:2;
    };
}od_dma_oddma_crc_mask_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l_crc_result:32;
    };
}od_dma_oddma_cap_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_l_crc_result:32;
    };
}od_dma_oddma_disp_l_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rate_en:1;
        RBus_UInt32  disp_rate_en:1;
        RBus_UInt32  res1:30;
    };
}od_dma_oddma_dma_rate_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_rate:32;
    };
}od_dma_oddma_capture_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_rate:32;
    };
}od_dma_oddma_display_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  stop_burst_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  disp_3ddma_en:1;
        RBus_UInt32  res3:23;
    };
}od_dma_oddma_display_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_wtlvl:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  disp_pixel_num:13;
        RBus_UInt32  res2:3;
    };
}od_dma_oddma_display_numwtl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_read_remain:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_read_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  disp_read_num:16;
    };
}od_dma_oddma_display_rdnumlenrem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp_line_step:29;
    };
}od_dma_oddma_disp_linestep_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_line_number:13;
        RBus_UInt32  res1:19;
    };
}od_dma_oddma_display_linenum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_adr_up_over_range:1;
        RBus_UInt32  disp_adr_down_over_range:1;
        RBus_UInt32  disp_fifo_underflow:1;
        RBus_UInt32  disp_fifo_overflow:1;
        RBus_UInt32  disp_fifo_empty:1;
        RBus_UInt32  disp_fifo_full:1;
        RBus_UInt32  disp_fifo_clr:1;
        RBus_UInt32  disp_clr_over_range:1;
        RBus_UInt32  res1:24;
    };
}od_dma_oddma_display_status1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp_read_block:2;
        RBus_UInt32  res2:29;
    };
}od_dma_oddma_display_status2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp_start_addr_l1:29;
    };
}od_dma_oddma_disp_start_addr_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  disp_start_addr_l2:29;
    };
}od_dma_oddma_disp_start_addr_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_rising_ie:1;
        RBus_UInt32  cap_fifo_err_ie:1;
        RBus_UInt32  cap_mem_err_ie:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  disp_fifo_err_ie:1;
        RBus_UInt32  disp_mem_err_ie:1;
        RBus_UInt32  res2:22;
    };
}od_dma_oddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_decomp_clk_en:1;
        RBus_UInt32  res1:31;
    };
}od_dma_oddma_comp_decomp_clk_gated_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_1byte_swap:1;
        RBus_UInt32  cap_2byte_swap:1;
        RBus_UInt32  cap_4byte_swap:1;
        RBus_UInt32  cap_8byte_swap:1;
        RBus_UInt32  cap_channel_swap:3;
        RBus_UInt32  res1:9;
        RBus_UInt32  disp_1byte_swap:1;
        RBus_UInt32  disp_2byte_swap:1;
        RBus_UInt32  disp_4byte_swap:1;
        RBus_UInt32  disp_8byte_swap:1;
        RBus_UInt32  disp_channel_swap:3;
        RBus_UInt32  res2:9;
    };
}od_dma_oddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_rm:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  pqdc1_rm_0:4;
        RBus_UInt32  pqdc2_rm_0:4;
        RBus_UInt32  res2:8;
    };
}od_dma_oddma_disp_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_rme:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqdc1_rme_0:1;
        RBus_UInt32  pqdc2_rme_0:1;
        RBus_UInt32  res2:13;
        RBus_UInt32  pqdc_test_rwm:1;
    };
}od_dma_oddma_disp_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_ls:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqdc1_ls_0:1;
        RBus_UInt32  pqdc2_ls_0:1;
        RBus_UInt32  res2:14;
    };
}od_dma_oddma_disp_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_bist_fail:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqdc1_bist_fail_0:1;
        RBus_UInt32  pqdc2_bist_fail_0:1;
        RBus_UInt32  pqdc2_bist_fail_1:1;
        RBus_UInt32  res2:13;
    };
}od_dma_oddma_disp_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disp_drf_fail:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pqdc1_drf_fail_0:1;
        RBus_UInt32  pqdc2_drf_fail_0:1;
        RBus_UInt32  pqdc2_drf_fail_1:1;
        RBus_UInt32  res2:13;
    };
}od_dma_oddma_disp_drf_fail_RBUS;




#endif 


#endif 
