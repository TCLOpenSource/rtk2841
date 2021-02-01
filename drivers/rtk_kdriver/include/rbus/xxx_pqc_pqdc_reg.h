/**
* @file Mac5-DesignSpec-xxx_pqc_pqdc
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_XXX_PQC_PQDC_REG_H_
#define _RBUS_XXX_PQC_PQDC_REG_H_

#include "rbus_types.h"



//  XXX_PQC_PQDC Register Address
#define  XXX_PQC_PQDC_XXX_PQ_CMP                                                 0x18080000
#define  XXX_PQC_PQDC_XXX_PQ_CMP_reg_addr                                        "0xB8080000"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_reg                                             0xB8080000
#define  XXX_PQC_PQDC_XXX_PQ_CMP_inst_addr                                       "0x0000"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_reg(data)                                   (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_reg                                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_en_shift                                    (31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_width_div32_shift                           (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_height_shift                                (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_en_mask                                     (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_width_div32_mask                            (0x01FF0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_height_mask                                 (0x00003FFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_en(data)                                    (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_width_div32(data)                           (0x01FF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_cmp_height(data)                                (0x00003FFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_get_cmp_en(data)                                ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_get_cmp_width_div32(data)                       ((0x01FF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_get_cmp_height(data)                            (0x00003FFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR                                            0x18080004
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_reg_addr                                   "0xB8080004"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_reg                                        0xB8080004
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_inst_addr                                  "0x0001"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_reg(data)                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_reg                                    (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_dummy_31_5_shift                           (5)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_color_shift                       (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_bit_width_shift                   (2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_format_shift                      (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_dummy_31_5_mask                            (0xFFFFFFE0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_color_mask                        (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_bit_width_mask                    (0x0000000C)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_format_mask                       (0x00000003)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_dummy_31_5(data)                           (0xFFFFFFE0&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_color(data)                       (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_bit_width(data)                   (0x0000000C&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_cmp_data_format(data)                      (0x00000003&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_get_dummy_31_5(data)                       ((0xFFFFFFE0&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_get_cmp_data_color(data)                   ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_get_cmp_data_bit_width(data)               ((0x0000000C&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PAIR_get_cmp_data_format(data)                  (0x00000003&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT                                             0x18080008
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_reg_addr                                    "0xB8080008"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_reg                                         0xB8080008
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_inst_addr                                   "0x0002"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_BIT_reg(data)                               (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_BIT_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_BIT_reg                                     (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_BIT_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_first_line_more_bit_shift                   (24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_block_limit_bit_shift                       (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_line_limit_bit_shift                        (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_frame_limit_bit_shift                       (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_first_line_more_bit_mask                    (0x3F000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_block_limit_bit_mask                        (0x003F0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_line_limit_bit_mask                         (0x00003F00)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_frame_limit_bit_mask                        (0x0000003F)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_first_line_more_bit(data)                   (0x3F000000&((data)<<24))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_block_limit_bit(data)                       (0x003F0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_line_limit_bit(data)                        (0x00003F00&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_frame_limit_bit(data)                       (0x0000003F&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_get_first_line_more_bit(data)               ((0x3F000000&(data))>>24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_get_block_limit_bit(data)                   ((0x003F0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_get_line_limit_bit(data)                    ((0x00003F00&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BIT_get_frame_limit_bit(data)                   (0x0000003F&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE                                          0x1808000C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_reg_addr                                 "0xB808000C"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_reg                                      0xB808000C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_inst_addr                                "0x0003"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_reg(data)                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_reg                                  (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_g_ratio_shift                            (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_guarantee_max_qp_en_shift                (11)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_dynamic_allocate_ratio_en_shift          (10)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_poor_limit_min_qp_en_shift               (9)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_balance_en_shift                         (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_fisrt_line_more_en_shift                 (7)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_two_line_prediction_en_shift             (6)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_do_422_mode_shift                        (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_not_enough_bit_do_422_en_shift           (2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_not_rich_do_422_en_shift                 (1)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_rb_lossy_do_422_en_shift                 (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_g_ratio_mask                             (0x001F0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_guarantee_max_qp_en_mask                 (0x00000800)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_dynamic_allocate_ratio_en_mask           (0x00000400)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_poor_limit_min_qp_en_mask                (0x00000200)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_balance_en_mask                          (0x00000100)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_fisrt_line_more_en_mask                  (0x00000080)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_two_line_prediction_en_mask              (0x00000040)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_do_422_mode_mask                         (0x00000030)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_not_enough_bit_do_422_en_mask            (0x00000004)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_not_rich_do_422_en_mask                  (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_rb_lossy_do_422_en_mask                  (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_g_ratio(data)                            (0x001F0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_guarantee_max_qp_en(data)                (0x00000800&((data)<<11))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_dynamic_allocate_ratio_en(data)          (0x00000400&((data)<<10))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_poor_limit_min_qp_en(data)               (0x00000200&((data)<<9))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_balance_en(data)                         (0x00000100&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_fisrt_line_more_en(data)                 (0x00000080&((data)<<7))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_two_line_prediction_en(data)             (0x00000040&((data)<<6))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_do_422_mode(data)                        (0x00000030&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_not_enough_bit_do_422_en(data)           (0x00000004&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_not_rich_do_422_en(data)                 (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_rb_lossy_do_422_en(data)                 (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_g_ratio(data)                        ((0x001F0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_guarantee_max_qp_en(data)            ((0x00000800&(data))>>11)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_dynamic_allocate_ratio_en(data)      ((0x00000400&(data))>>10)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_poor_limit_min_qp_en(data)           ((0x00000200&(data))>>9)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_balance_en(data)                     ((0x00000100&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_fisrt_line_more_en(data)             ((0x00000080&(data))>>7)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_two_line_prediction_en(data)         ((0x00000040&(data))>>6)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_do_422_mode(data)                    ((0x00000030&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_not_enough_bit_do_422_en(data)       ((0x00000004&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_not_rich_do_422_en(data)             ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ENABLE_get_rb_lossy_do_422_en(data)             (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH                                          0x18080010
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_reg_addr                                 "0xB8080010"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_reg                                      0xB8080010
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_inst_addr                                "0x0004"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_reg(data)                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_reg                                  (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_not_enough_bit_do_422_qp_shift           (24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_not_rich_do_422_th_shift                 (20)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_rb_lossy_do_422_qp_level_shift           (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_value_th_shift                 (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_num_th_shift                   (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_near_num_th_shift              (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_not_enough_bit_do_422_qp_mask            (0x07000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_not_rich_do_422_th_mask                  (0x00F00000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_rb_lossy_do_422_qp_level_mask            (0x00070000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_value_th_mask                  (0x00000F00)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_num_th_mask                    (0x00000070)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_near_num_th_mask               (0x00000007)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_not_enough_bit_do_422_qp(data)           (0x07000000&((data)<<24))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_not_rich_do_422_th(data)                 (0x00F00000&((data)<<20))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_rb_lossy_do_422_qp_level(data)           (0x00070000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_value_th(data)                 (0x00000F00&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_num_th(data)                   (0x00000070&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_variation_near_num_th(data)              (0x00000007&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_get_not_enough_bit_do_422_qp(data)       ((0x07000000&(data))>>24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_get_not_rich_do_422_th(data)             ((0x00F00000&(data))>>20)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_get_rb_lossy_do_422_qp_level(data)       ((0x00070000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_get_variation_value_th(data)             ((0x00000F00&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_get_variation_num_th(data)               ((0x00000070&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_SMOOTH_get_variation_near_num_th(data)          (0x00000007&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE                                        0x18080014
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_reg_addr                               "0xB8080014"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_reg                                    0xB8080014
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_inst_addr                              "0x0005"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_reg(data)                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_reg                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_max_shift       (24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_min_shift       (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_line_shift            (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_more_shift            (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_less_shift            (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_max_mask        (0x1F000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_min_mask        (0x001F0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_line_mask             (0x00000700)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_more_mask             (0x000000F0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_less_mask             (0x0000000F)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_max(data)       (0x1F000000&((data)<<24))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_ratio_min(data)       (0x001F0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_line(data)            (0x00000700&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_more(data)            (0x000000F0&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_dynamic_allocate_less(data)            (0x0000000F&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_get_dynamic_allocate_ratio_max(data)   ((0x1F000000&(data))>>24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_get_dynamic_allocate_ratio_min(data)   ((0x001F0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_get_dynamic_allocate_line(data)        ((0x00000700&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_get_dynamic_allocate_more(data)        ((0x000000F0&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ALLOCATE_get_dynamic_allocate_less(data)        (0x0000000F&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR                                            0x18080018
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_reg_addr                                   "0xB8080018"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_reg                                        0xB8080018
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_inst_addr                                  "0x0006"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_POOR_reg(data)                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_POOR_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_POOR_reg                                    (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_POOR_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp4_shift                    (24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp3_shift                    (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp2_shift                    (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp1_shift                    (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp4_mask                     (0x1F000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp3_mask                     (0x001F0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp2_mask                     (0x00001F00)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp1_mask                     (0x0000001F)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp4(data)                    (0x1F000000&((data)<<24))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp3(data)                    (0x001F0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp2(data)                    (0x00001F00&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_poor_limit_th_qp1(data)                    (0x0000001F&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_get_poor_limit_th_qp4(data)                ((0x1F000000&(data))>>24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_get_poor_limit_th_qp3(data)                ((0x001F0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_get_poor_limit_th_qp2(data)                ((0x00001F00&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_POOR_get_poor_limit_th_qp1(data)                (0x0000001F&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee                                       0x1808001C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_reg_addr                              "0xB808001C"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_reg                                   0xB808001C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_inst_addr                             "0x0007"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_reg(data)                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_reg                               (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_guarantee_max_rb_qp_shift             (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_guarantee_max_g_qp_shift              (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_guarantee_max_rb_qp_mask              (0x000000F0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_guarantee_max_g_qp_mask               (0x0000000F)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_guarantee_max_rb_qp(data)             (0x000000F0&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_guarantee_max_g_qp(data)              (0x0000000F&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_get_guarantee_max_rb_qp(data)         ((0x000000F0&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_Guarantee_get_guarantee_max_g_qp(data)          (0x0000000F&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE                                         0x18080020
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_reg_addr                                "0xB8080020"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_reg                                     0xB8080020
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_inst_addr                               "0x0008"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_reg(data)                           (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_reg                                 (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_ov_th_shift                  (12)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_ud_th_shift                  (10)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_give_shift                   (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_ov_th_shift                   (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_ud_th_shift                   (2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_give_shift                    (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_ov_th_mask                   (0x00003000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_ud_th_mask                   (0x00000C00)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_give_mask                    (0x00000300)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_ov_th_mask                    (0x00000030)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_ud_th_mask                    (0x0000000C)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_give_mask                     (0x00000003)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_ov_th(data)                  (0x00003000&((data)<<12))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_ud_th(data)                  (0x00000C00&((data)<<10))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_rb_give(data)                   (0x00000300&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_ov_th(data)                   (0x00000030&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_ud_th(data)                   (0x0000000C&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_balance_g_give(data)                    (0x00000003&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_get_balance_rb_ov_th(data)              ((0x00003000&(data))>>12)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_get_balance_rb_ud_th(data)              ((0x00000C00&(data))>>10)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_get_balance_rb_give(data)               ((0x00000300&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_get_balance_g_ov_th(data)               ((0x00000030&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_get_balance_g_ud_th(data)               ((0x0000000C&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_BALANCE_get_balance_g_give(data)                (0x00000003&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN                                          0x18080024
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_reg_addr                                 "0xB8080024"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_reg                                      0xB8080024
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_inst_addr                                "0x0009"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_reg(data)                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_reg                                  (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_block_fifo_overflow_irq_en_shift         (15)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_input_size_more_irq_en_shift             (14)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_input_size_less_irq_en_shift             (13)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_over_flb_irq_en_shift                    (12)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_request_fifo_even_overflow_irq_en_shift  (9)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_request_fifo_odd_overflow_irq_en_shift   (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_g_fifo_even_overflow_irq_en_shift        (6)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_r_fifo_even_overflow_irq_en_shift        (5)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_b_fifo_even_overflow_irq_en_shift        (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_g_fifo_odd_overflow_irq_en_shift         (2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_r_fifo_odd_overflow_irq_en_shift         (1)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_b_fifo_odd_overflow_irq_en_shift         (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_block_fifo_overflow_irq_en_mask          (0x00008000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_input_size_more_irq_en_mask              (0x00004000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_input_size_less_irq_en_mask              (0x00002000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_over_flb_irq_en_mask                     (0x00001000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_request_fifo_even_overflow_irq_en_mask   (0x00000200)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_request_fifo_odd_overflow_irq_en_mask    (0x00000100)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_g_fifo_even_overflow_irq_en_mask         (0x00000040)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_r_fifo_even_overflow_irq_en_mask         (0x00000020)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_b_fifo_even_overflow_irq_en_mask         (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_g_fifo_odd_overflow_irq_en_mask          (0x00000004)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_r_fifo_odd_overflow_irq_en_mask          (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_b_fifo_odd_overflow_irq_en_mask          (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_block_fifo_overflow_irq_en(data)         (0x00008000&((data)<<15))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_input_size_more_irq_en(data)             (0x00004000&((data)<<14))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_input_size_less_irq_en(data)             (0x00002000&((data)<<13))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_over_flb_irq_en(data)                    (0x00001000&((data)<<12))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_request_fifo_even_overflow_irq_en(data)  (0x00000200&((data)<<9))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_request_fifo_odd_overflow_irq_en(data)   (0x00000100&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_g_fifo_even_overflow_irq_en(data)        (0x00000040&((data)<<6))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_r_fifo_even_overflow_irq_en(data)        (0x00000020&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_b_fifo_even_overflow_irq_en(data)        (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_g_fifo_odd_overflow_irq_en(data)         (0x00000004&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_r_fifo_odd_overflow_irq_en(data)         (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_b_fifo_odd_overflow_irq_en(data)         (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_block_fifo_overflow_irq_en(data)     ((0x00008000&(data))>>15)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_input_size_more_irq_en(data)         ((0x00004000&(data))>>14)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_input_size_less_irq_en(data)         ((0x00002000&(data))>>13)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_over_flb_irq_en(data)                ((0x00001000&(data))>>12)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_request_fifo_even_overflow_irq_en(data) ((0x00000200&(data))>>9)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_request_fifo_odd_overflow_irq_en(data) ((0x00000100&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_g_fifo_even_overflow_irq_en(data)    ((0x00000040&(data))>>6)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_r_fifo_even_overflow_irq_en(data)    ((0x00000020&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_b_fifo_even_overflow_irq_en(data)    ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_g_fifo_odd_overflow_irq_en(data)     ((0x00000004&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_r_fifo_odd_overflow_irq_en(data)     ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_EN_get_b_fifo_odd_overflow_irq_en(data)     (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST                                          0x18080028
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_reg_addr                                 "0xB8080028"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_reg                                      0xB8080028
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_inst_addr                                "0x000A"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_reg(data)                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_reg                                  (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_pqc_irq_shift                            (31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_block_fifo_overflow_st_shift             (15)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_input_size_more_st_shift                 (14)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_input_size_less_st_shift                 (13)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_over_flb_st_shift                        (12)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_request_fifo_even_overflow_st_shift      (9)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_request_fifo_odd_overflow_st_shift       (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_g_fifo_even_overflow_st_shift            (6)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_r_fifo_even_overflow_st_shift            (5)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_b_fifo_even_overflow_st_shift            (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_g_fifo_odd_overflow_st_shift             (2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_r_fifo_odd_overflow_st_shift             (1)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_b_fifo_odd_overflow_st_shift             (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_pqc_irq_mask                             (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_block_fifo_overflow_st_mask              (0x00008000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_input_size_more_st_mask                  (0x00004000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_input_size_less_st_mask                  (0x00002000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_over_flb_st_mask                         (0x00001000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_request_fifo_even_overflow_st_mask       (0x00000200)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_request_fifo_odd_overflow_st_mask        (0x00000100)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_g_fifo_even_overflow_st_mask             (0x00000040)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_r_fifo_even_overflow_st_mask             (0x00000020)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_b_fifo_even_overflow_st_mask             (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_g_fifo_odd_overflow_st_mask              (0x00000004)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_r_fifo_odd_overflow_st_mask              (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_b_fifo_odd_overflow_st_mask              (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_pqc_irq(data)                            (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_block_fifo_overflow_st(data)             (0x00008000&((data)<<15))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_input_size_more_st(data)                 (0x00004000&((data)<<14))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_input_size_less_st(data)                 (0x00002000&((data)<<13))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_over_flb_st(data)                        (0x00001000&((data)<<12))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_request_fifo_even_overflow_st(data)      (0x00000200&((data)<<9))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_request_fifo_odd_overflow_st(data)       (0x00000100&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_g_fifo_even_overflow_st(data)            (0x00000040&((data)<<6))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_r_fifo_even_overflow_st(data)            (0x00000020&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_b_fifo_even_overflow_st(data)            (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_g_fifo_odd_overflow_st(data)             (0x00000004&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_r_fifo_odd_overflow_st(data)             (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_b_fifo_odd_overflow_st(data)             (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_pqc_irq(data)                        ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_block_fifo_overflow_st(data)         ((0x00008000&(data))>>15)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_input_size_more_st(data)             ((0x00004000&(data))>>14)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_input_size_less_st(data)             ((0x00002000&(data))>>13)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_over_flb_st(data)                    ((0x00001000&(data))>>12)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_request_fifo_even_overflow_st(data)  ((0x00000200&(data))>>9)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_request_fifo_odd_overflow_st(data)   ((0x00000100&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_g_fifo_even_overflow_st(data)        ((0x00000040&(data))>>6)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_r_fifo_even_overflow_st(data)        ((0x00000020&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_b_fifo_even_overflow_st(data)        ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_g_fifo_odd_overflow_st(data)         ((0x00000004&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_r_fifo_odd_overflow_st(data)         ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_IRQ_ST_get_b_fifo_odd_overflow_st(data)         (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST                                              0x1808002C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_reg_addr                                     "0xB808002C"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_reg                                          0xB808002C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_inst_addr                                    "0x000B"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_ST_reg(data)                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_ST_reg                                      (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_cmp_two_pixel_mode_shift                     (31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_g_ratio_max_shift                            (24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_g_ratio_min_shift                            (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_cmp_package_height_cnt_shift                 (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_cmp_two_pixel_mode_mask                      (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_g_ratio_max_mask                             (0x1F000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_g_ratio_min_mask                             (0x001F0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_cmp_package_height_cnt_mask                  (0x00003FFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_cmp_two_pixel_mode(data)                     (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_g_ratio_max(data)                            (0x1F000000&((data)<<24))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_g_ratio_min(data)                            (0x001F0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_cmp_package_height_cnt(data)                 (0x00003FFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_get_cmp_two_pixel_mode(data)                 ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_get_g_ratio_max(data)                        ((0x1F000000&(data))>>24)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_get_g_ratio_min(data)                        ((0x001F0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_ST_get_cmp_package_height_cnt(data)             (0x00003FFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST                                           0x18080030
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_reg_addr                                  "0xB8080030"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_reg                                       0xB8080030
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_inst_addr                                 "0x000C"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_reg(data)                             (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_reg                                   (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_qp_measure_en_shift             (31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_g_qp_max_shift                  (20)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_rb_qp_max_shift                 (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_short_term_g_qp_max_shift                 (4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_short_term_rb_qp_max_shift                (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_qp_measure_en_mask              (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_g_qp_max_mask                   (0x00F00000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_rb_qp_max_mask                  (0x000F0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_short_term_g_qp_max_mask                  (0x000000F0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_short_term_rb_qp_max_mask                 (0x0000000F)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_qp_measure_en(data)             (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_g_qp_max(data)                  (0x00F00000&((data)<<20))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_long_term_rb_qp_max(data)                 (0x000F0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_short_term_g_qp_max(data)                 (0x000000F0&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_short_term_rb_qp_max(data)                (0x0000000F&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_get_long_term_qp_measure_en(data)         ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_get_long_term_g_qp_max(data)              ((0x00F00000&(data))>>20)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_get_long_term_rb_qp_max(data)             ((0x000F0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_get_short_term_g_qp_max(data)             ((0x000000F0&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_QP_ST_get_short_term_rb_qp_max(data)            (0x0000000F&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1                                        0x18080034
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_reg_addr                               "0xB8080034"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_reg                                    0xB8080034
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_inst_addr                              "0x000D"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_reg(data)                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_reg                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_measure_en_shift            (31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_g_shift                (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_r_shift                (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_b_shift                (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_measure_en_mask             (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_g_mask                 (0x00FF0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_r_mask                 (0x0000FF00)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_b_mask                 (0x000000FF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_measure_en(data)            (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_g(data)                (0x00FF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_r(data)                (0x0000FF00&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_fifo_water_even_b(data)                (0x000000FF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_get_fifo_water_measure_en(data)        ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_get_fifo_water_even_g(data)            ((0x00FF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_get_fifo_water_even_r(data)            ((0x0000FF00&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST1_get_fifo_water_even_b(data)            (0x000000FF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2                                        0x18080038
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_reg_addr                               "0xB8080038"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_reg                                    0xB8080038
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_inst_addr                              "0x000E"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_reg(data)                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_reg                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_g_shift                 (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_r_shift                 (8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_b_shift                 (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_g_mask                  (0x00FF0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_r_mask                  (0x0000FF00)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_b_mask                  (0x000000FF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_g(data)                 (0x00FF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_r(data)                 (0x0000FF00&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_fifo_water_odd_b(data)                 (0x000000FF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_get_fifo_water_odd_g(data)             ((0x00FF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_get_fifo_water_odd_r(data)             ((0x0000FF00&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_FIFO_ST2_get_fifo_water_odd_b(data)             (0x000000FF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST                                         0x1808003C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_reg_addr                                "0xB808003C"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_reg                                     0xB808003C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_inst_addr                               "0x000F"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_reg(data)                           (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_reg                                 (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_g_frame_left_shift                      (16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_rb_frame_left_shift                     (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_g_frame_left_mask                       (0xFFFF0000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_rb_frame_left_mask                      (0x0000FFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_g_frame_left(data)                      (0xFFFF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_rb_frame_left(data)                     (0x0000FFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_get_g_frame_left(data)                  ((0xFFFF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_LEFT_ST_get_rb_frame_left(data)                 (0x0000FFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST                                      0x18080040
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_reg_addr                             "0xB8080040"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_reg                                  0xB8080040
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_inst_addr                            "0x0010"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_reg(data)                        (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_reg                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_total_package_long_term_shift        (31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_total_package_even_shift             (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_total_package_long_term_mask         (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_total_package_even_mask              (0x00FFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_total_package_long_term(data)        (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_total_package_even(data)             (0x00FFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_get_total_package_long_term(data)    ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ST_get_total_package_even(data)         (0x00FFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G                                      0x18080044
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_reg_addr                             "0xB8080044"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_reg                                  0xB8080044
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_inst_addr                            "0x0011"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_reg(data)                        (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_reg                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_cmp_crc_even_g_shift                 (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_cmp_crc_even_g_mask                  (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_cmp_crc_even_g(data)                 (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_G_get_cmp_crc_even_g(data)             (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R                                      0x18080048
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_reg_addr                             "0xB8080048"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_reg                                  0xB8080048
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_inst_addr                            "0x0012"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_reg(data)                        (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_reg                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_cmp_crc_even_r_shift                 (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_cmp_crc_even_r_mask                  (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_cmp_crc_even_r(data)                 (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_R_get_cmp_crc_even_r(data)             (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B                                      0x1808004C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_reg_addr                             "0xB808004C"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_reg                                  0xB808004C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_inst_addr                            "0x0013"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_reg(data)                        (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_reg                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_cmp_crc_even_b_shift                 (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_cmp_crc_even_b_mask                  (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_cmp_crc_even_b(data)                 (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_EVEN_B_get_cmp_crc_even_b(data)             (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G                                       0x18080050
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_reg_addr                              "0xB8080050"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_reg                                   0xB8080050
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_inst_addr                             "0x0014"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_reg(data)                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_reg                               (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_cmp_crc_odd_g_shift                   (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_cmp_crc_odd_g_mask                    (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_cmp_crc_odd_g(data)                   (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_G_get_cmp_crc_odd_g(data)               (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R                                       0x18080054
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_reg_addr                              "0xB8080054"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_reg                                   0xB8080054
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_inst_addr                             "0x0015"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_reg(data)                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_reg                               (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_cmp_crc_odd_r_shift                   (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_cmp_crc_odd_r_mask                    (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_cmp_crc_odd_r(data)                   (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_R_get_cmp_crc_odd_r(data)               (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B                                       0x18080058
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_reg_addr                              "0xB8080058"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_reg                                   0xB8080058
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_inst_addr                             "0x0016"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_reg(data)                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_reg                               (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_cmp_crc_odd_b_shift                   (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_cmp_crc_odd_b_mask                    (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_cmp_crc_odd_b(data)                   (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_CRC_ODD_B_get_cmp_crc_odd_b(data)               (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST                                  0x1808005C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_reg_addr                         "0xB808005C"
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_reg                              0xB808005C
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_inst_addr                        "0x0017"
#define  set_XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_reg(data)                    (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_reg                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_total_package_odd_shift          (0)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_total_package_odd_mask           (0x00FFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_total_package_odd(data)          (0x00FFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_CMP_PACKAGE_ODD_ST_get_total_package_odd(data)      (0x00FFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP                                               0x18080060
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_reg_addr                                      "0xB8080060"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_reg                                           0xB8080060
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_inst_addr                                     "0x0018"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_reg(data)                                 (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_reg                                       (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_en_shift                                (31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_width_div32_shift                       (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_height_shift                            (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_en_mask                                 (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_width_div32_mask                        (0x01FF0000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_height_mask                             (0x00003FFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_en(data)                                (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_width_div32(data)                       (0x01FF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_decmp_height(data)                            (0x00003FFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_get_decmp_en(data)                            ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_get_decmp_width_div32(data)                   ((0x01FF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_get_decmp_height(data)                        (0x00003FFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR                                          0x18080064
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_reg_addr                                 "0xB8080064"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_reg                                      0xB8080064
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_inst_addr                                "0x0019"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_reg(data)                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_reg                                  (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_dummy_31_5_shift                         (5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_color_shift                   (4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_bit_width_shift               (2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_format_shift                  (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_dummy_31_5_mask                          (0xFFFFFFE0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_color_mask                    (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_bit_width_mask                (0x0000000C)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_format_mask                   (0x00000003)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_dummy_31_5(data)                         (0xFFFFFFE0&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_color(data)                   (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_bit_width(data)               (0x0000000C&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_decmp_data_format(data)                  (0x00000003&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_get_dummy_31_5(data)                     ((0xFFFFFFE0&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_get_decmp_data_color(data)               ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_get_decmp_data_bit_width(data)           ((0x0000000C&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_PAIR_get_decmp_data_format(data)              (0x00000003&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN                                        0x18080068
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_reg_addr                               "0xB8080068"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_reg                                    0xB8080068
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_inst_addr                              "0x001A"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_reg(data)                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_reg                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_saturation_type_shift                  (1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_saturation_en_shift                    (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_saturation_type_mask                   (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_saturation_en_mask                     (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_saturation_type(data)                  (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_saturation_en(data)                    (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_get_saturation_type(data)              ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_SAT_EN_get_saturation_en(data)                (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN                                        0x1808006C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_reg_addr                               "0xB808006C"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_reg                                    0xB808006C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_inst_addr                              "0x001B"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_reg(data)                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_reg                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_not_finish_irq_even_en_shift           (21)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_underflow_irq_even_en_shift            (20)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_r_error_even_en_shift              (18)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_g_error_even_en_shift              (17)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_b_error_even_en_shift              (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_not_finish_irq_odd_en_shift            (5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_underflow_irq_odd_en_shift             (4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_r_error_odd_en_shift               (2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_g_error_odd_en_shift               (1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_b_error_odd_en_shift               (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_not_finish_irq_even_en_mask            (0x00200000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_underflow_irq_even_en_mask             (0x00100000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_r_error_even_en_mask               (0x00040000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_g_error_even_en_mask               (0x00020000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_b_error_even_en_mask               (0x00010000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_not_finish_irq_odd_en_mask             (0x00000020)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_underflow_irq_odd_en_mask              (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_r_error_odd_en_mask                (0x00000004)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_g_error_odd_en_mask                (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_b_error_odd_en_mask                (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_not_finish_irq_even_en(data)           (0x00200000&((data)<<21))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_underflow_irq_even_en(data)            (0x00100000&((data)<<20))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_r_error_even_en(data)              (0x00040000&((data)<<18))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_g_error_even_en(data)              (0x00020000&((data)<<17))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_b_error_even_en(data)              (0x00010000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_not_finish_irq_odd_en(data)            (0x00000020&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_underflow_irq_odd_en(data)             (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_r_error_odd_en(data)               (0x00000004&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_g_error_odd_en(data)               (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_crc_b_error_odd_en(data)               (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_not_finish_irq_even_en(data)       ((0x00200000&(data))>>21)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_underflow_irq_even_en(data)        ((0x00100000&(data))>>20)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_crc_r_error_even_en(data)          ((0x00040000&(data))>>18)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_crc_g_error_even_en(data)          ((0x00020000&(data))>>17)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_crc_b_error_even_en(data)          ((0x00010000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_not_finish_irq_odd_en(data)        ((0x00000020&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_underflow_irq_odd_en(data)         ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_crc_r_error_odd_en(data)           ((0x00000004&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_crc_g_error_odd_en(data)           ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_EN_get_crc_b_error_odd_en(data)           (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st                                        0x18080070
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_reg_addr                               "0xB8080070"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_reg                                    0xB8080070
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_inst_addr                              "0x001C"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_reg(data)                          (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_reg                                (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_pqdc_irq_shift                         (31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_in_fifo_overflow_even_st_shift         (27)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_r_overflow_even_st_shift          (26)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_g_overflow_even_st_shift          (25)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_b_overflow_even_st_shift          (24)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_not_finish_irq_even_st_shift           (21)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_underflow_irq_even_st_shift            (20)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_r_error_even_st_shift              (18)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_g_error_even_st_shift              (17)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_b_error_even_st_shift              (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_in_fifo_overflow_odd_st_shift          (11)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_r_overflow_odd_st_shift           (10)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_g_overflow_odd_st_shift           (9)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_b_overflow_odd_st_shift           (8)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_not_finish_irq_odd_st_shift            (5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_underflow_irq_odd_st_shift             (4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_r_error_odd_st_shift               (2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_g_error_odd_st_shift               (1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_b_error_odd_st_shift               (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_pqdc_irq_mask                          (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_in_fifo_overflow_even_st_mask          (0x08000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_r_overflow_even_st_mask           (0x04000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_g_overflow_even_st_mask           (0x02000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_b_overflow_even_st_mask           (0x01000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_not_finish_irq_even_st_mask            (0x00200000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_underflow_irq_even_st_mask             (0x00100000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_r_error_even_st_mask               (0x00040000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_g_error_even_st_mask               (0x00020000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_b_error_even_st_mask               (0x00010000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_in_fifo_overflow_odd_st_mask           (0x00000800)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_r_overflow_odd_st_mask            (0x00000400)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_g_overflow_odd_st_mask            (0x00000200)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_b_overflow_odd_st_mask            (0x00000100)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_not_finish_irq_odd_st_mask             (0x00000020)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_underflow_irq_odd_st_mask              (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_r_error_odd_st_mask                (0x00000004)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_g_error_odd_st_mask                (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_b_error_odd_st_mask                (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_pqdc_irq(data)                         (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_in_fifo_overflow_even_st(data)         (0x08000000&((data)<<27))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_r_overflow_even_st(data)          (0x04000000&((data)<<26))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_g_overflow_even_st(data)          (0x02000000&((data)<<25))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_b_overflow_even_st(data)          (0x01000000&((data)<<24))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_not_finish_irq_even_st(data)           (0x00200000&((data)<<21))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_underflow_irq_even_st(data)            (0x00100000&((data)<<20))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_r_error_even_st(data)              (0x00040000&((data)<<18))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_g_error_even_st(data)              (0x00020000&((data)<<17))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_b_error_even_st(data)              (0x00010000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_in_fifo_overflow_odd_st(data)          (0x00000800&((data)<<11))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_r_overflow_odd_st(data)           (0x00000400&((data)<<10))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_g_overflow_odd_st(data)           (0x00000200&((data)<<9))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_ring_b_overflow_odd_st(data)           (0x00000100&((data)<<8))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_not_finish_irq_odd_st(data)            (0x00000020&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_underflow_irq_odd_st(data)             (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_r_error_odd_st(data)               (0x00000004&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_g_error_odd_st(data)               (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_crc_b_error_odd_st(data)               (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_pqdc_irq(data)                     ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_in_fifo_overflow_even_st(data)     ((0x08000000&(data))>>27)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_ring_r_overflow_even_st(data)      ((0x04000000&(data))>>26)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_ring_g_overflow_even_st(data)      ((0x02000000&(data))>>25)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_ring_b_overflow_even_st(data)      ((0x01000000&(data))>>24)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_not_finish_irq_even_st(data)       ((0x00200000&(data))>>21)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_underflow_irq_even_st(data)        ((0x00100000&(data))>>20)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_crc_r_error_even_st(data)          ((0x00040000&(data))>>18)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_crc_g_error_even_st(data)          ((0x00020000&(data))>>17)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_crc_b_error_even_st(data)          ((0x00010000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_in_fifo_overflow_odd_st(data)      ((0x00000800&(data))>>11)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_ring_r_overflow_odd_st(data)       ((0x00000400&(data))>>10)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_ring_g_overflow_odd_st(data)       ((0x00000200&(data))>>9)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_ring_b_overflow_odd_st(data)       ((0x00000100&(data))>>8)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_not_finish_irq_odd_st(data)        ((0x00000020&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_underflow_irq_odd_st(data)         ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_crc_r_error_odd_st(data)           ((0x00000004&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_crc_g_error_odd_st(data)           ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_IRQ_st_get_crc_b_error_odd_st(data)           (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN                                       0x18080074
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_reg_addr                              "0xB8080074"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_reg                                   0xB8080074
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_inst_addr                             "0x001D"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_reg(data)                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_reg                               (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_do_422_shift                  (31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp_sel_shift                  (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp7_shift                     (7)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp6_shift                     (6)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp5_shift                     (5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp4_shift                     (4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp3_shift                     (3)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp2_shift                     (2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp1_shift                     (1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp0_shift                     (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_do_422_mask                   (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp_sel_mask                   (0x00010000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp7_mask                      (0x00000080)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp6_mask                      (0x00000040)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp5_mask                      (0x00000020)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp4_mask                      (0x00000010)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp3_mask                      (0x00000008)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp2_mask                      (0x00000004)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp1_mask                      (0x00000002)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp0_mask                      (0x00000001)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_do_422(data)                  (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp_sel(data)                  (0x00010000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp7(data)                     (0x00000080&((data)<<7))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp6(data)                     (0x00000040&((data)<<6))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp5(data)                     (0x00000020&((data)<<5))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp4(data)                     (0x00000010&((data)<<4))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp3(data)                     (0x00000008&((data)<<3))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp2(data)                     (0x00000004&((data)<<2))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp1(data)                     (0x00000002&((data)<<1))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_mark_en_qp0(data)                     (0x00000001&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_do_422(data)              ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp_sel(data)              ((0x00010000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp7(data)                 ((0x00000080&(data))>>7)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp6(data)                 ((0x00000040&(data))>>6)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp5(data)                 ((0x00000020&(data))>>5)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp4(data)                 ((0x00000010&(data))>>4)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp3(data)                 ((0x00000008&(data))>>3)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp2(data)                 ((0x00000004&(data))>>2)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp1(data)                 ((0x00000002&(data))>>1)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_EN_get_mark_en_qp0(data)                 (0x00000001&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01                                 0x18080078
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_reg_addr                        "0xB8080078"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_reg                             0xB8080078
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_inst_addr                       "0x001E"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_reg(data)                   (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_reg                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_mark_color_0_shift              (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_mark_color_1_shift              (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_mark_color_0_mask               (0xFFFF0000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_mark_color_1_mask               (0x0000FFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_mark_color_0(data)              (0xFFFF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_mark_color_1(data)              (0x0000FFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_get_mark_color_0(data)          ((0xFFFF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_01_get_mark_color_1(data)          (0x0000FFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23                                 0x1808007C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_reg_addr                        "0xB808007C"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_reg                             0xB808007C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_inst_addr                       "0x001F"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_reg(data)                   (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_reg                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_mark_color_2_shift              (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_mark_color_3_shift              (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_mark_color_2_mask               (0xFFFF0000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_mark_color_3_mask               (0x0000FFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_mark_color_2(data)              (0xFFFF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_mark_color_3(data)              (0x0000FFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_get_mark_color_2(data)          ((0xFFFF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_23_get_mark_color_3(data)          (0x0000FFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45                                 0x18080080
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_reg_addr                        "0xB8080080"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_reg                             0xB8080080
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_inst_addr                       "0x0020"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_reg(data)                   (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_reg                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_mark_color_4_shift              (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_mark_color_5_shift              (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_mark_color_4_mask               (0xFFFF0000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_mark_color_5_mask               (0x0000FFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_mark_color_4(data)              (0xFFFF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_mark_color_5(data)              (0x0000FFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_get_mark_color_4(data)          ((0xFFFF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_45_get_mark_color_5(data)          (0x0000FFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67                                 0x18080084
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_reg_addr                        "0xB8080084"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_reg                             0xB8080084
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_inst_addr                       "0x0021"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_reg(data)                   (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_reg                         (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_mark_color_6_shift              (16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_mark_color_7_shift              (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_mark_color_6_mask               (0xFFFF0000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_mark_color_7_mask               (0x0000FFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_mark_color_6(data)              (0xFFFF0000&((data)<<16))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_mark_color_7(data)              (0x0000FFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_get_mark_color_6(data)          ((0xFFFF0000&(data))>>16)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_67_get_mark_color_7(data)          (0x0000FFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422                                0x18080088
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_reg_addr                       "0xB8080088"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_reg                            0xB8080088
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_inst_addr                      "0x0022"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_reg(data)                  (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_reg                        (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_mark_color_422_shift           (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_mark_color_422_mask            (0x0000FFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_mark_color_422(data)           (0x0000FFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_MARK_color_422_get_mark_color_422(data)       (0x0000FFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST                                            0x1808008C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_reg_addr                                   "0xB808008C"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_reg                                        0xB808008C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_inst_addr                                  "0x0023"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_ST_reg(data)                              (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_ST_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_ST_reg                                    (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_ST_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_decmp_two_pixel_mode_shift                 (31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_decmp_package_height_cnt_shift             (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_decmp_two_pixel_mode_mask                  (0x80000000)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_decmp_package_height_cnt_mask              (0x00003FFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_decmp_two_pixel_mode(data)                 (0x80000000&((data)<<31))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_decmp_package_height_cnt(data)             (0x00003FFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_get_decmp_two_pixel_mode(data)             ((0x80000000&(data))>>31)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_ST_get_decmp_package_height_cnt(data)         (0x00003FFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G                                    0x18080090
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_reg_addr                           "0xB8080090"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_reg                                0xB8080090
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_inst_addr                          "0x0024"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_reg(data)                      (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_reg                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_decmp_crc_even_g_shift             (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_decmp_crc_even_g_mask              (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_decmp_crc_even_g(data)             (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_G_get_decmp_crc_even_g(data)         (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R                                    0x18080094
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_reg_addr                           "0xB8080094"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_reg                                0xB8080094
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_inst_addr                          "0x0025"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_reg(data)                      (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_reg                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_decmp_crc_even_r_shift             (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_decmp_crc_even_r_mask              (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_decmp_crc_even_r(data)             (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_R_get_decmp_crc_even_r(data)         (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B                                    0x18080098
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_reg_addr                           "0xB8080098"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_reg                                0xB8080098
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_inst_addr                          "0x0026"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_reg(data)                      (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_reg                            (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_decmp_crc_even_b_shift             (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_decmp_crc_even_b_mask              (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_decmp_crc_even_b(data)             (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_EVEN_B_get_decmp_crc_even_b(data)         (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G                                     0x1808009C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_reg_addr                            "0xB808009C"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_reg                                 0xB808009C
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_inst_addr                           "0x0027"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_reg(data)                       (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_reg                             (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_decmp_crc_odd_g_shift               (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_decmp_crc_odd_g_mask                (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_decmp_crc_odd_g(data)               (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_G_get_decmp_crc_odd_g(data)           (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R                                     0x180800A0
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_reg_addr                            "0xB80800A0"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_reg                                 0xB80800A0
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_inst_addr                           "0x0028"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_reg(data)                       (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_reg                             (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_decmp_crc_odd_r_shift               (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_decmp_crc_odd_r_mask                (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_decmp_crc_odd_r(data)               (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_R_get_decmp_crc_odd_r(data)           (0xFFFFFFFF&(data))

#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B                                     0x180800A4
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_reg_addr                            "0xB80800A4"
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_reg                                 0xB80800A4
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_inst_addr                           "0x0029"
#define  set_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_reg(data)                       (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_reg)=data)
#define  get_XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_reg                             (*((volatile unsigned int*)XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_reg))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_decmp_crc_odd_b_shift               (0)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_decmp_crc_odd_b_mask                (0xFFFFFFFF)
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_decmp_crc_odd_b(data)               (0xFFFFFFFF&(data))
#define  XXX_PQC_PQDC_XXX_PQ_DECMP_CRC_ODD_B_get_decmp_crc_odd_b(data)           (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======XXX_PQC_PQDC register structure define==========

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
}xxx_pqc_pqdc_xxx_pq_cmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18080004_31_5:27;
        RBus_UInt32  cmp_data_color:1;
        RBus_UInt32  cmp_data_bit_width:2;
        RBus_UInt32  cmp_data_format:2;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_pair_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_bit_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_enable_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_smooth_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_allocate_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_poor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  guarantee_max_rb_qp:4;
        RBus_UInt32  guarantee_max_g_qp:4;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_guarantee_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_balance_RBUS;

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
        RBus_UInt32  request_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  g_fifo_even_overflow_irq_en:1;
        RBus_UInt32  r_fifo_even_overflow_irq_en:1;
        RBus_UInt32  b_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  g_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  r_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  b_fifo_odd_overflow_irq_en:1;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_irq_en_RBUS;

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
        RBus_UInt32  request_fifo_odd_overflow_st:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  g_fifo_even_overflow_st:1;
        RBus_UInt32  r_fifo_even_overflow_st:1;
        RBus_UInt32  b_fifo_even_overflow_st:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  g_fifo_odd_overflow_st:1;
        RBus_UInt32  r_fifo_odd_overflow_st:1;
        RBus_UInt32  b_fifo_odd_overflow_st:1;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_irq_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_qp_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_fifo_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  fifo_water_odd_g:8;
        RBus_UInt32  fifo_water_odd_r:8;
        RBus_UInt32  fifo_water_odd_b:8;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_fifo_st2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  g_frame_left:16;
        RBus_UInt32  rb_frame_left:16;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_left_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_package_long_term:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  total_package_even:24;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_package_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_odd_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_odd_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_odd_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_odd_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_odd_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_odd_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  total_package_odd:24;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_package_odd_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_decmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18080064_31_5:27;
        RBus_UInt32  decmp_data_color:1;
        RBus_UInt32  decmp_data_bit_width:2;
        RBus_UInt32  decmp_data_format:2;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_pair_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  saturation_type:1;
        RBus_UInt32  saturation_en:1;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_sat_en_RBUS;

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
        RBus_UInt32  res3:10;
        RBus_UInt32  not_finish_irq_odd_en:1;
        RBus_UInt32  underflow_irq_odd_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  crc_r_error_odd_en:1;
        RBus_UInt32  crc_g_error_odd_en:1;
        RBus_UInt32  crc_b_error_odd_en:1;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_irq_en_RBUS;

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
        RBus_UInt32  res4:4;
        RBus_UInt32  in_fifo_overflow_odd_st:1;
        RBus_UInt32  ring_r_overflow_odd_st:1;
        RBus_UInt32  ring_g_overflow_odd_st:1;
        RBus_UInt32  ring_b_overflow_odd_st:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  not_finish_irq_odd_st:1;
        RBus_UInt32  underflow_irq_odd_st:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  crc_r_error_odd_st:1;
        RBus_UInt32  crc_g_error_odd_st:1;
        RBus_UInt32  crc_b_error_odd_st:1;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_irq_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_decmp_mark_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_0:16;
        RBus_UInt32  mark_color_1:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_2:16;
        RBus_UInt32  mark_color_3:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_4:16;
        RBus_UInt32  mark_color_5:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_6:16;
        RBus_UInt32  mark_color_7:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  mark_color_422:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_422_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_two_pixel_mode:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  res2:2;
        RBus_UInt32  decmp_package_height_cnt:14;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_odd_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_odd_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_odd_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_odd_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_odd_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_odd_b_RBUS;

#else //apply LITTLE_ENDIAN

//======XXX_PQC_PQDC register structure define==========

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
}xxx_pqc_pqdc_xxx_pq_cmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_data_format:2;
        RBus_UInt32  cmp_data_bit_width:2;
        RBus_UInt32  cmp_data_color:1;
        RBus_UInt32  dummy18080004_31_5:27;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_pair_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_bit_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_enable_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_smooth_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_allocate_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_poor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  guarantee_max_g_qp:4;
        RBus_UInt32  guarantee_max_rb_qp:4;
        RBus_UInt32  res1:24;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_guarantee_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  r_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  g_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  b_fifo_even_overflow_irq_en:1;
        RBus_UInt32  r_fifo_even_overflow_irq_en:1;
        RBus_UInt32  g_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  request_fifo_odd_overflow_irq_en:1;
        RBus_UInt32  request_fifo_even_overflow_irq_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  over_flb_irq_en:1;
        RBus_UInt32  input_size_less_irq_en:1;
        RBus_UInt32  input_size_more_irq_en:1;
        RBus_UInt32  block_fifo_overflow_irq_en:1;
        RBus_UInt32  res4:16;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b_fifo_odd_overflow_st:1;
        RBus_UInt32  r_fifo_odd_overflow_st:1;
        RBus_UInt32  g_fifo_odd_overflow_st:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  b_fifo_even_overflow_st:1;
        RBus_UInt32  r_fifo_even_overflow_st:1;
        RBus_UInt32  g_fifo_even_overflow_st:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  request_fifo_odd_overflow_st:1;
        RBus_UInt32  request_fifo_even_overflow_st:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  over_flb_st:1;
        RBus_UInt32  input_size_less_st:1;
        RBus_UInt32  input_size_more_st:1;
        RBus_UInt32  block_fifo_overflow_st:1;
        RBus_UInt32  res4:15;
        RBus_UInt32  pqc_irq:1;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_irq_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_qp_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_cmp_fifo_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_water_odd_b:8;
        RBus_UInt32  fifo_water_odd_r:8;
        RBus_UInt32  fifo_water_odd_g:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:1;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_fifo_st2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rb_frame_left:16;
        RBus_UInt32  g_frame_left:16;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_left_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_package_even:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  total_package_long_term:1;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_package_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_even_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_odd_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_odd_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_odd_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_odd_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmp_crc_odd_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_crc_odd_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_package_odd:24;
        RBus_UInt32  res1:8;
    };
}xxx_pqc_pqdc_xxx_pq_cmp_package_odd_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_decmp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_data_format:2;
        RBus_UInt32  decmp_data_bit_width:2;
        RBus_UInt32  decmp_data_color:1;
        RBus_UInt32  dummy18080064_31_5:27;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_pair_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  saturation_en:1;
        RBus_UInt32  saturation_type:1;
        RBus_UInt32  res1:30;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_sat_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_b_error_odd_en:1;
        RBus_UInt32  crc_g_error_odd_en:1;
        RBus_UInt32  crc_r_error_odd_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  underflow_irq_odd_en:1;
        RBus_UInt32  not_finish_irq_odd_en:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  crc_b_error_even_en:1;
        RBus_UInt32  crc_g_error_even_en:1;
        RBus_UInt32  crc_r_error_even_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  underflow_irq_even_en:1;
        RBus_UInt32  not_finish_irq_even_en:1;
        RBus_UInt32  res4:10;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_irq_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_b_error_odd_st:1;
        RBus_UInt32  crc_g_error_odd_st:1;
        RBus_UInt32  crc_r_error_odd_st:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  underflow_irq_odd_st:1;
        RBus_UInt32  not_finish_irq_odd_st:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  ring_b_overflow_odd_st:1;
        RBus_UInt32  ring_g_overflow_odd_st:1;
        RBus_UInt32  ring_r_overflow_odd_st:1;
        RBus_UInt32  in_fifo_overflow_odd_st:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  crc_b_error_even_st:1;
        RBus_UInt32  crc_g_error_even_st:1;
        RBus_UInt32  crc_r_error_even_st:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  underflow_irq_even_st:1;
        RBus_UInt32  not_finish_irq_even_st:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  ring_b_overflow_even_st:1;
        RBus_UInt32  ring_g_overflow_even_st:1;
        RBus_UInt32  ring_r_overflow_even_st:1;
        RBus_UInt32  in_fifo_overflow_even_st:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  pqdc_irq:1;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_irq_st_RBUS;

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
}xxx_pqc_pqdc_xxx_pq_decmp_mark_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_1:16;
        RBus_UInt32  mark_color_0:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_3:16;
        RBus_UInt32  mark_color_2:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_5:16;
        RBus_UInt32  mark_color_4:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_45_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_7:16;
        RBus_UInt32  mark_color_6:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_67_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mark_color_422:16;
        RBus_UInt32  res1:16;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_mark_color_422_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_package_height_cnt:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:15;
        RBus_UInt32  decmp_two_pixel_mode:1;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_even_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_even_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_even_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_even_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_odd_g:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_odd_g_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_odd_r:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_odd_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  decmp_crc_odd_b:32;
    };
}xxx_pqc_pqdc_xxx_pq_decmp_crc_odd_b_RBUS;




#endif 


#endif 
