/**
* @file Mac5-DesignSpec-D-Domain_Edge_Smooth
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_EDGE_SMOOTH_REG_H_
#define _RBUS_COLOR_EDGE_SMOOTH_REG_H_

#include "rbus_types.h"



//  COLOR_EDGE_SMOOTH Register Address
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL                       0x1802AA00
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_reg_addr              "0xB802AA00"
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_reg                   0xB802AA00
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_inst_addr             "0x0000"
#define  set_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_reg(data)         (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_reg               (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_reg))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_verlpf_select_shift   (20)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_weighting_factor_shift (16)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_outcurline_mode_shift (13)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_incurline_mode_shift  (12)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_sobel_extend_enable_shift (10)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_sobel_debug_enable_shift (9)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_dirlpf_enable_shift   (8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_verlpf_select_mask    (0x00100000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_weighting_factor_mask (0x000F0000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_outcurline_mode_mask  (0x00006000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_incurline_mode_mask   (0x00001000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_sobel_extend_enable_mask (0x00000400)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_sobel_debug_enable_mask (0x00000200)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_dirlpf_enable_mask    (0x00000100)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_verlpf_select(data)   (0x00100000&((data)<<20))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_weighting_factor(data) (0x000F0000&((data)<<16))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_outcurline_mode(data) (0x00006000&((data)<<13))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_incurline_mode(data)  (0x00001000&((data)<<12))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_sobel_extend_enable(data) (0x00000400&((data)<<10))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_sobel_debug_enable(data) (0x00000200&((data)<<9))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_dirlpf_enable(data)   (0x00000100&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_verlpf_select(data) ((0x00100000&(data))>>20)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_weighting_factor(data) ((0x000F0000&(data))>>16)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_outcurline_mode(data) ((0x00006000&(data))>>13)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_incurline_mode(data) ((0x00001000&(data))>>12)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_sobel_extend_enable(data) ((0x00000400&(data))>>10)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_sobel_debug_enable(data) ((0x00000200&(data))>>9)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_2DSHP_DIRLPF_CTRL_get_dirlpf_enable(data) ((0x00000100&(data))>>8)

#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD                              0x1802AA04
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_reg_addr                     "0xB802AA04"
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_reg                          0xB802AA04
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_inst_addr                    "0x0001"
#define  set_COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_reg(data)                (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_reg                      (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_reg))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_ths_shift              (24)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_thm_shift              (16)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_ths_lowang_shift       (8)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_thm_lowang_shift       (0)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_ths_mask               (0xFF000000)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_thm_mask               (0x00FF0000)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_ths_lowang_mask        (0x0000FF00)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_thm_lowang_mask        (0x000000FF)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_ths(data)              (0xFF000000&((data)<<24))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_thm(data)              (0x00FF0000&((data)<<16))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_ths_lowang(data)       (0x0000FF00&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_sobel_thm_lowang(data)       (0x000000FF&(data))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_get_sobel_ths(data)          ((0xFF000000&(data))>>24)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_get_sobel_thm(data)          ((0x00FF0000&(data))>>16)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_get_sobel_ths_lowang(data)   ((0x0000FF00&(data))>>8)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_DRAFT_THRESHOLD_get_sobel_thm_lowang(data)   (0x000000FF&(data))

#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE                           0x1802AA08
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_reg_addr                  "0xB802AA08"
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_reg                       0xB802AA08
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_inst_addr                 "0x0002"
#define  set_COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_reg(data)             (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_reg                   (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_reg))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_ths_hiang_shift     (24)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_thm_hiang_shift     (16)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_th_v3_shift         (8)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_th_h3_shift         (0)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_ths_hiang_mask      (0xFF000000)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_thm_hiang_mask      (0x00FF0000)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_th_v3_mask          (0x0000FF00)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_th_h3_mask          (0x000000FF)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_ths_hiang(data)     (0xFF000000&((data)<<24))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_thm_hiang(data)     (0x00FF0000&((data)<<16))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_th_v3(data)         (0x0000FF00&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_sobel_th_h3(data)         (0x000000FF&(data))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_get_sobel_ths_hiang(data) ((0xFF000000&(data))>>24)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_get_sobel_thm_hiang(data) ((0x00FF0000&(data))>>16)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_get_sobel_th_v3(data)     ((0x0000FF00&(data))>>8)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_LOWANGLE_get_sobel_th_h3(data)     (0x000000FF&(data))

#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE                            0x1802AA0C
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_reg_addr                   "0xB802AA0C"
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_reg                        0xB802AA0C
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_inst_addr                  "0x0003"
#define  set_COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_reg(data)              (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_reg                    (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_reg))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_v4_shift          (24)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_h4_shift          (16)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_v5_shift          (8)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_h5_shift          (0)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_v4_mask           (0xFF000000)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_h4_mask           (0x00FF0000)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_v5_mask           (0x0000FF00)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_h5_mask           (0x000000FF)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_v4(data)          (0xFF000000&((data)<<24))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_h4(data)          (0x00FF0000&((data)<<16))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_v5(data)          (0x0000FF00&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_sobel_th_h5(data)          (0x000000FF&(data))
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_get_sobel_th_v4(data)      ((0xFF000000&(data))>>24)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_get_sobel_th_h4(data)      ((0x00FF0000&(data))>>16)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_get_sobel_th_v5(data)      ((0x0000FF00&(data))>>8)
#define  COLOR_EDGE_SMOOTH_DM_SOBEL_THRESHOLD_HIANGLE_get_sobel_th_h5(data)      (0x000000FF&(data))

#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS                          0x1802AA10
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_reg_addr                 "0xB802AA10"
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_reg                      0xB802AA10
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_inst_addr                "0x0004"
#define  set_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_reg(data)            (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_reg                  (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_reg))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_sobel_th_v6_shift        (24)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_five_lines_enable_shift  (23)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_weight_shift       (8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_max1_thd_shift           (4)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_thd_shift          (1)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_en_shift           (0)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_sobel_th_v6_mask         (0xFF000000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_five_lines_enable_mask   (0x00800000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_weight_mask        (0x00000300)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_max1_thd_mask            (0x00000070)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_thd_mask           (0x0000000E)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_en_mask            (0x00000001)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_sobel_th_v6(data)        (0xFF000000&((data)<<24))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_five_lines_enable(data)  (0x00800000&((data)<<23))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_weight(data)       (0x00000300&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_max1_thd(data)           (0x00000070&((data)<<4))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_thd(data)          (0x0000000E&((data)<<1))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_chaos_en(data)           (0x00000001&(data))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_get_sobel_th_v6(data)    ((0xFF000000&(data))>>24)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_get_five_lines_enable(data) ((0x00800000&(data))>>23)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_get_chaos_weight(data)   ((0x00000300&(data))>>8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_get_max1_thd(data)       ((0x00000070&(data))>>4)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_get_chaos_thd(data)      ((0x0000000E&(data))>>1)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_DIRLPF_DECHAOS_get_chaos_en(data)       (0x00000001&(data))

#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN                            0x1802AA14
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_reg_addr                   "0xB802AA14"
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_reg                        0xB802AA14
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_inst_addr                  "0x0005"
#define  set_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_reg(data)              (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_reg                    (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_reg))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_enable_shift       (28)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_gain_pos_shift     (8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_gain_neg_shift     (0)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_enable_mask        (0x10000000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_gain_pos_mask      (0x0000FF00)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_gain_neg_mask      (0x000000FF)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_enable(data)       (0x10000000&((data)<<28))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_gain_pos(data)     (0x0000FF00&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_postshp_gain_neg(data)     (0x000000FF&(data))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_get_postshp_enable(data)   ((0x10000000&(data))>>28)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_get_postshp_gain_pos(data) ((0x0000FF00&(data))>>8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_GAIN_get_postshp_gain_neg(data) (0x000000FF&(data))

#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND                           0x1802AA18
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_reg_addr                  "0xB802AA18"
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_reg                       0xB802AA18
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_inst_addr                 "0x0006"
#define  set_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_reg(data)             (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_reg)=data)
#define  get_COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_reg                   (*((volatile unsigned int*)COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_reg))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_hv_pos_shift      (20)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_hv_neg_shift      (8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_lv_shift          (0)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_hv_pos_mask       (0x3FF00000)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_hv_neg_mask       (0x0003FF00)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_lv_mask           (0x000000FF)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_hv_pos(data)      (0x3FF00000&((data)<<20))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_hv_neg(data)      (0x0003FF00&((data)<<8))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_postshp_lv(data)          (0x000000FF&(data))
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_get_postshp_hv_pos(data)  ((0x3FF00000&(data))>>20)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_get_postshp_hv_neg(data)  ((0x0003FF00&(data))>>8)
#define  COLOR_EDGE_SMOOTH_DM_EdgeSmooth_POSTSHP_BOUND_get_postshp_lv(data)      (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_EDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  verlpf_select:1;
        RBus_UInt32  weighting_factor:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  outcurline_mode:2;
        RBus_UInt32  incurline_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sobel_extend_enable:1;
        RBus_UInt32  sobel_debug_enable:1;
        RBus_UInt32  dirlpf_enable:1;
        RBus_UInt32  res4:8;
    };
}color_edge_smooth_dm_edgesmooth_2dshp_dirlpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_ths:8;
        RBus_UInt32  sobel_thm:8;
        RBus_UInt32  sobel_ths_lowang:8;
        RBus_UInt32  sobel_thm_lowang:8;
    };
}color_edge_smooth_dm_sobel_draft_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_ths_hiang:8;
        RBus_UInt32  sobel_thm_hiang:8;
        RBus_UInt32  sobel_th_v3:8;
        RBus_UInt32  sobel_th_h3:8;
    };
}color_edge_smooth_dm_sobel_threshold_lowangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_v4:8;
        RBus_UInt32  sobel_th_h4:8;
        RBus_UInt32  sobel_th_v5:8;
        RBus_UInt32  sobel_th_h5:8;
    };
}color_edge_smooth_dm_sobel_threshold_hiangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_v6:8;
        RBus_UInt32  five_lines_enable:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  chaos_weight:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  max1_thd:3;
        RBus_UInt32  chaos_thd:3;
        RBus_UInt32  chaos_en:1;
    };
}color_edge_smooth_dm_edgesmooth_dirlpf_dechaos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  postshp_enable:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  postshp_gain_pos:8;
        RBus_UInt32  postshp_gain_neg:8;
    };
}color_edge_smooth_dm_edgesmooth_postshp_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  postshp_hv_pos:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  postshp_hv_neg:10;
        RBus_UInt32  postshp_lv:8;
    };
}color_edge_smooth_dm_edgesmooth_postshp_bound_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_EDGE_SMOOTH register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dirlpf_enable:1;
        RBus_UInt32  sobel_debug_enable:1;
        RBus_UInt32  sobel_extend_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  incurline_mode:1;
        RBus_UInt32  outcurline_mode:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  weighting_factor:4;
        RBus_UInt32  verlpf_select:1;
        RBus_UInt32  res4:11;
    };
}color_edge_smooth_dm_edgesmooth_2dshp_dirlpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_thm_lowang:8;
        RBus_UInt32  sobel_ths_lowang:8;
        RBus_UInt32  sobel_thm:8;
        RBus_UInt32  sobel_ths:8;
    };
}color_edge_smooth_dm_sobel_draft_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_h3:8;
        RBus_UInt32  sobel_th_v3:8;
        RBus_UInt32  sobel_thm_hiang:8;
        RBus_UInt32  sobel_ths_hiang:8;
    };
}color_edge_smooth_dm_sobel_threshold_lowangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sobel_th_h5:8;
        RBus_UInt32  sobel_th_v5:8;
        RBus_UInt32  sobel_th_h4:8;
        RBus_UInt32  sobel_th_v4:8;
    };
}color_edge_smooth_dm_sobel_threshold_hiangle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chaos_en:1;
        RBus_UInt32  chaos_thd:3;
        RBus_UInt32  max1_thd:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  chaos_weight:2;
        RBus_UInt32  res2:13;
        RBus_UInt32  five_lines_enable:1;
        RBus_UInt32  sobel_th_v6:8;
    };
}color_edge_smooth_dm_edgesmooth_dirlpf_dechaos_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postshp_gain_neg:8;
        RBus_UInt32  postshp_gain_pos:8;
        RBus_UInt32  res1:12;
        RBus_UInt32  postshp_enable:1;
        RBus_UInt32  res2:3;
    };
}color_edge_smooth_dm_edgesmooth_postshp_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postshp_lv:8;
        RBus_UInt32  postshp_hv_neg:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  postshp_hv_pos:10;
        RBus_UInt32  res2:2;
    };
}color_edge_smooth_dm_edgesmooth_postshp_bound_RBUS;




#endif 


#endif 
