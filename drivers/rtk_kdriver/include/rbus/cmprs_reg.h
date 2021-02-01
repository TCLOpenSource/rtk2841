/**
* @file Mac5_VE_CMPRS_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CMPRS_REG_H_
#define _RBUS_CMPRS_REG_H_

#include "rbus_types.h"



//  CMPRS Register Address
#define  CMPRS_CCPAR                                                             0x1800EB80
#define  CMPRS_CCPAR_reg_addr                                                    "0xB800EB80"
#define  CMPRS_CCPAR_reg                                                         0xB800EB80
#define  CMPRS_CCPAR_inst_addr                                                   "0x0000"
#define  set_CMPRS_CCPAR_reg(data)                                               (*((volatile unsigned int*)CMPRS_CCPAR_reg)=data)
#define  get_CMPRS_CCPAR_reg                                                     (*((volatile unsigned int*)CMPRS_CCPAR_reg))
#define  CMPRS_CCPAR_dmy_auto_mode_shift                                         (30)
#define  CMPRS_CCPAR_dmy_mb_row_shift                                            (29)
#define  CMPRS_CCPAR_dmy_mb_clm_shift                                            (28)
#define  CMPRS_CCPAR_mb_field_decoding_flag_shift                                (25)
#define  CMPRS_CCPAR_dmy_row_ctb_shift                                           (24)
#define  CMPRS_CCPAR_dmy_clm_ctb_shift                                           (23)
#define  CMPRS_CCPAR_mb_num_shift                                                (19)
#define  CMPRS_CCPAR_cur_mb_x_shift                                              (9)
#define  CMPRS_CCPAR_cur_mb_y_shift                                              (0)
#define  CMPRS_CCPAR_dmy_auto_mode_mask                                          (0x40000000)
#define  CMPRS_CCPAR_dmy_mb_row_mask                                             (0x20000000)
#define  CMPRS_CCPAR_dmy_mb_clm_mask                                             (0x10000000)
#define  CMPRS_CCPAR_mb_field_decoding_flag_mask                                 (0x02000000)
#define  CMPRS_CCPAR_dmy_row_ctb_mask                                            (0x01000000)
#define  CMPRS_CCPAR_dmy_clm_ctb_mask                                            (0x00800000)
#define  CMPRS_CCPAR_mb_num_mask                                                 (0x00780000)
#define  CMPRS_CCPAR_cur_mb_x_mask                                               (0x0007FE00)
#define  CMPRS_CCPAR_cur_mb_y_mask                                               (0x000001FF)
#define  CMPRS_CCPAR_dmy_auto_mode(data)                                         (0x40000000&((data)<<30))
#define  CMPRS_CCPAR_dmy_mb_row(data)                                            (0x20000000&((data)<<29))
#define  CMPRS_CCPAR_dmy_mb_clm(data)                                            (0x10000000&((data)<<28))
#define  CMPRS_CCPAR_mb_field_decoding_flag(data)                                (0x02000000&((data)<<25))
#define  CMPRS_CCPAR_dmy_row_ctb(data)                                           (0x01000000&((data)<<24))
#define  CMPRS_CCPAR_dmy_clm_ctb(data)                                           (0x00800000&((data)<<23))
#define  CMPRS_CCPAR_mb_num(data)                                                (0x00780000&((data)<<19))
#define  CMPRS_CCPAR_cur_mb_x(data)                                              (0x0007FE00&((data)<<9))
#define  CMPRS_CCPAR_cur_mb_y(data)                                              (0x000001FF&(data))
#define  CMPRS_CCPAR_get_dmy_auto_mode(data)                                     ((0x40000000&(data))>>30)
#define  CMPRS_CCPAR_get_dmy_mb_row(data)                                        ((0x20000000&(data))>>29)
#define  CMPRS_CCPAR_get_dmy_mb_clm(data)                                        ((0x10000000&(data))>>28)
#define  CMPRS_CCPAR_get_mb_field_decoding_flag(data)                            ((0x02000000&(data))>>25)
#define  CMPRS_CCPAR_get_dmy_row_ctb(data)                                       ((0x01000000&(data))>>24)
#define  CMPRS_CCPAR_get_dmy_clm_ctb(data)                                       ((0x00800000&(data))>>23)
#define  CMPRS_CCPAR_get_mb_num(data)                                            ((0x00780000&(data))>>19)
#define  CMPRS_CCPAR_get_cur_mb_x(data)                                          ((0x0007FE00&(data))>>9)
#define  CMPRS_CCPAR_get_cur_mb_y(data)                                          (0x000001FF&(data))

#define  CMPRS_STATUS                                                            0x1800EB84
#define  CMPRS_STATUS_reg_addr                                                   "0xB800EB84"
#define  CMPRS_STATUS_reg                                                        0xB800EB84
#define  CMPRS_STATUS_inst_addr                                                  "0x0001"
#define  set_CMPRS_STATUS_reg(data)                                              (*((volatile unsigned int*)CMPRS_STATUS_reg)=data)
#define  get_CMPRS_STATUS_reg                                                    (*((volatile unsigned int*)CMPRS_STATUS_reg))
#define  CMPRS_STATUS_max_leaf_nodes_shift                                       (19)
#define  CMPRS_STATUS_dma_eff_enhance_shift                                      (18)
#define  CMPRS_STATUS_post_write_disable_shift                                   (17)
#define  CMPRS_STATUS_hdr_addr_update_shift                                      (16)
#define  CMPRS_STATUS_comp_core_irq_shift                                        (15)
#define  CMPRS_STATUS_comp_core_bypass_shift                                     (12)
#define  CMPRS_STATUS_comp_core_errflag_clr_shift                                (8)
#define  CMPRS_STATUS_comp_core_flag2irq_en_shift                                (4)
#define  CMPRS_STATUS_comp_core_errflag_shift                                    (0)
#define  CMPRS_STATUS_max_leaf_nodes_mask                                        (0x01F80000)
#define  CMPRS_STATUS_dma_eff_enhance_mask                                       (0x00040000)
#define  CMPRS_STATUS_post_write_disable_mask                                    (0x00020000)
#define  CMPRS_STATUS_hdr_addr_update_mask                                       (0x00010000)
#define  CMPRS_STATUS_comp_core_irq_mask                                         (0x00008000)
#define  CMPRS_STATUS_comp_core_bypass_mask                                      (0x00001000)
#define  CMPRS_STATUS_comp_core_errflag_clr_mask                                 (0x00000F00)
#define  CMPRS_STATUS_comp_core_flag2irq_en_mask                                 (0x000000F0)
#define  CMPRS_STATUS_comp_core_errflag_mask                                     (0x0000000F)
#define  CMPRS_STATUS_max_leaf_nodes(data)                                       (0x01F80000&((data)<<19))
#define  CMPRS_STATUS_dma_eff_enhance(data)                                      (0x00040000&((data)<<18))
#define  CMPRS_STATUS_post_write_disable(data)                                   (0x00020000&((data)<<17))
#define  CMPRS_STATUS_hdr_addr_update(data)                                      (0x00010000&((data)<<16))
#define  CMPRS_STATUS_comp_core_irq(data)                                        (0x00008000&((data)<<15))
#define  CMPRS_STATUS_comp_core_bypass(data)                                     (0x00001000&((data)<<12))
#define  CMPRS_STATUS_comp_core_errflag_clr(data)                                (0x00000F00&((data)<<8))
#define  CMPRS_STATUS_comp_core_flag2irq_en(data)                                (0x000000F0&((data)<<4))
#define  CMPRS_STATUS_comp_core_errflag(data)                                    (0x0000000F&(data))
#define  CMPRS_STATUS_get_max_leaf_nodes(data)                                   ((0x01F80000&(data))>>19)
#define  CMPRS_STATUS_get_dma_eff_enhance(data)                                  ((0x00040000&(data))>>18)
#define  CMPRS_STATUS_get_post_write_disable(data)                               ((0x00020000&(data))>>17)
#define  CMPRS_STATUS_get_hdr_addr_update(data)                                  ((0x00010000&(data))>>16)
#define  CMPRS_STATUS_get_comp_core_irq(data)                                    ((0x00008000&(data))>>15)
#define  CMPRS_STATUS_get_comp_core_bypass(data)                                 ((0x00001000&(data))>>12)
#define  CMPRS_STATUS_get_comp_core_errflag_clr(data)                            ((0x00000F00&(data))>>8)
#define  CMPRS_STATUS_get_comp_core_flag2irq_en(data)                            ((0x000000F0&(data))>>4)
#define  CMPRS_STATUS_get_comp_core_errflag(data)                                (0x0000000F&(data))

#define  CMPRS_VMADR0                                                            0x1800EB88
#define  CMPRS_VMADR0_reg_addr                                                   "0xB800EB88"
#define  CMPRS_VMADR0_reg                                                        0xB800EB88
#define  CMPRS_VMADR0_inst_addr                                                  "0x0002"
#define  set_CMPRS_VMADR0_reg(data)                                              (*((volatile unsigned int*)CMPRS_VMADR0_reg)=data)
#define  get_CMPRS_VMADR0_reg                                                    (*((volatile unsigned int*)CMPRS_VMADR0_reg))
#define  CMPRS_VMADR0_sb_str_addr_shift                                          (16)
#define  CMPRS_VMADR0_offseta2_shift                                             (7)
#define  CMPRS_VMADR0_basea2_shift                                               (0)
#define  CMPRS_VMADR0_sb_str_addr_mask                                           (0x007F0000)
#define  CMPRS_VMADR0_offseta2_mask                                              (0x00003F80)
#define  CMPRS_VMADR0_basea2_mask                                                (0x0000007F)
#define  CMPRS_VMADR0_sb_str_addr(data)                                          (0x007F0000&((data)<<16))
#define  CMPRS_VMADR0_offseta2(data)                                             (0x00003F80&((data)<<7))
#define  CMPRS_VMADR0_basea2(data)                                               (0x0000007F&(data))
#define  CMPRS_VMADR0_get_sb_str_addr(data)                                      ((0x007F0000&(data))>>16)
#define  CMPRS_VMADR0_get_offseta2(data)                                         ((0x00003F80&(data))>>7)
#define  CMPRS_VMADR0_get_basea2(data)                                           (0x0000007F&(data))

#define  CMPRS_VMADR1                                                            0x1800EB8C
#define  CMPRS_VMADR1_reg_addr                                                   "0xB800EB8C"
#define  CMPRS_VMADR1_reg                                                        0xB800EB8C
#define  CMPRS_VMADR1_inst_addr                                                  "0x0003"
#define  set_CMPRS_VMADR1_reg(data)                                              (*((volatile unsigned int*)CMPRS_VMADR1_reg)=data)
#define  get_CMPRS_VMADR1_reg                                                    (*((volatile unsigned int*)CMPRS_VMADR1_reg))
#define  CMPRS_VMADR1_offseta1_shift                                             (23)
#define  CMPRS_VMADR1_basea1_shift                                               (16)
#define  CMPRS_VMADR1_offseta0_shift                                             (7)
#define  CMPRS_VMADR1_basea0_shift                                               (0)
#define  CMPRS_VMADR1_offseta1_mask                                              (0x3F800000)
#define  CMPRS_VMADR1_basea1_mask                                                (0x007F0000)
#define  CMPRS_VMADR1_offseta0_mask                                              (0x00003F80)
#define  CMPRS_VMADR1_basea0_mask                                                (0x0000007F)
#define  CMPRS_VMADR1_offseta1(data)                                             (0x3F800000&((data)<<23))
#define  CMPRS_VMADR1_basea1(data)                                               (0x007F0000&((data)<<16))
#define  CMPRS_VMADR1_offseta0(data)                                             (0x00003F80&((data)<<7))
#define  CMPRS_VMADR1_basea0(data)                                               (0x0000007F&(data))
#define  CMPRS_VMADR1_get_offseta1(data)                                         ((0x3F800000&(data))>>23)
#define  CMPRS_VMADR1_get_basea1(data)                                           ((0x007F0000&(data))>>16)
#define  CMPRS_VMADR1_get_offseta0(data)                                         ((0x00003F80&(data))>>7)
#define  CMPRS_VMADR1_get_basea0(data)                                           (0x0000007F&(data))

#define  CMPRS_HDMAADR_0                                                         0x1800EB90
#define  CMPRS_HDMAADR_0_reg_addr                                                "0xB800EB90"
#define  CMPRS_HDMAADR_0_reg                                                     0xB800EB90
#define  CMPRS_HDMAADR_0_inst_addr                                               "0x0004"
#define  set_CMPRS_HDMAADR_0_reg(data)                                           (*((volatile unsigned int*)CMPRS_HDMAADR_0_reg)=data)
#define  get_CMPRS_HDMAADR_0_reg                                                 (*((volatile unsigned int*)CMPRS_HDMAADR_0_reg))
#define  CMPRS_HDMAADR_0_hdr_str_addr_shift                                      (0)
#define  CMPRS_HDMAADR_0_hdr_str_addr_mask                                       (0xFFFFFFFF)
#define  CMPRS_HDMAADR_0_hdr_str_addr(data)                                      (0xFFFFFFFF&(data))
#define  CMPRS_HDMAADR_0_get_hdr_str_addr(data)                                  (0xFFFFFFFF&(data))

#define  CMPRS_HDMAADR_1                                                         0x1800EB94
#define  CMPRS_HDMAADR_1_reg_addr                                                "0xB800EB94"
#define  CMPRS_HDMAADR_1_reg                                                     0xB800EB94
#define  CMPRS_HDMAADR_1_inst_addr                                               "0x0005"
#define  set_CMPRS_HDMAADR_1_reg(data)                                           (*((volatile unsigned int*)CMPRS_HDMAADR_1_reg)=data)
#define  get_CMPRS_HDMAADR_1_reg                                                 (*((volatile unsigned int*)CMPRS_HDMAADR_1_reg))
#define  CMPRS_HDMAADR_1_hdr_str_addr_shift                                      (0)
#define  CMPRS_HDMAADR_1_hdr_str_addr_mask                                       (0xFFFFFFFF)
#define  CMPRS_HDMAADR_1_hdr_str_addr(data)                                      (0xFFFFFFFF&(data))
#define  CMPRS_HDMAADR_1_get_hdr_str_addr(data)                                  (0xFFFFFFFF&(data))

#define  CMPRS_Control                                                           0x1800EB98
#define  CMPRS_Control_reg_addr                                                  "0xB800EB98"
#define  CMPRS_Control_reg                                                       0xB800EB98
#define  CMPRS_Control_inst_addr                                                 "0x0006"
#define  set_CMPRS_Control_reg(data)                                             (*((volatile unsigned int*)CMPRS_Control_reg)=data)
#define  get_CMPRS_Control_reg                                                   (*((volatile unsigned int*)CMPRS_Control_reg))
#define  CMPRS_Control_budget_bytes_shift                                        (18)
#define  CMPRS_Control_qp_decision_method_y_shift                                (17)
#define  CMPRS_Control_qp_decision_method_c_shift                                (16)
#define  CMPRS_Control_alternate_budget_y_shift                                  (10)
#define  CMPRS_Control_alternate_budget_c_shift                                  (4)
#define  CMPRS_Control_min_qp_y_shift                                            (2)
#define  CMPRS_Control_min_qp_c_shift                                            (0)
#define  CMPRS_Control_budget_bytes_mask                                         (0x01FC0000)
#define  CMPRS_Control_qp_decision_method_y_mask                                 (0x00020000)
#define  CMPRS_Control_qp_decision_method_c_mask                                 (0x00010000)
#define  CMPRS_Control_alternate_budget_y_mask                                   (0x0000FC00)
#define  CMPRS_Control_alternate_budget_c_mask                                   (0x000003F0)
#define  CMPRS_Control_min_qp_y_mask                                             (0x0000000C)
#define  CMPRS_Control_min_qp_c_mask                                             (0x00000003)
#define  CMPRS_Control_budget_bytes(data)                                        (0x01FC0000&((data)<<18))
#define  CMPRS_Control_qp_decision_method_y(data)                                (0x00020000&((data)<<17))
#define  CMPRS_Control_qp_decision_method_c(data)                                (0x00010000&((data)<<16))
#define  CMPRS_Control_alternate_budget_y(data)                                  (0x0000FC00&((data)<<10))
#define  CMPRS_Control_alternate_budget_c(data)                                  (0x000003F0&((data)<<4))
#define  CMPRS_Control_min_qp_y(data)                                            (0x0000000C&((data)<<2))
#define  CMPRS_Control_min_qp_c(data)                                            (0x00000003&(data))
#define  CMPRS_Control_get_budget_bytes(data)                                    ((0x01FC0000&(data))>>18)
#define  CMPRS_Control_get_qp_decision_method_y(data)                            ((0x00020000&(data))>>17)
#define  CMPRS_Control_get_qp_decision_method_c(data)                            ((0x00010000&(data))>>16)
#define  CMPRS_Control_get_alternate_budget_y(data)                              ((0x0000FC00&(data))>>10)
#define  CMPRS_Control_get_alternate_budget_c(data)                              ((0x000003F0&(data))>>4)
#define  CMPRS_Control_get_min_qp_y(data)                                        ((0x0000000C&(data))>>2)
#define  CMPRS_Control_get_min_qp_c(data)                                        (0x00000003&(data))

#define  CMPRS_Statistics                                                        0x1800EB9C
#define  CMPRS_Statistics_reg_addr                                               "0xB800EB9C"
#define  CMPRS_Statistics_reg                                                    0xB800EB9C
#define  CMPRS_Statistics_inst_addr                                              "0x0007"
#define  set_CMPRS_Statistics_reg(data)                                          (*((volatile unsigned int*)CMPRS_Statistics_reg)=data)
#define  get_CMPRS_Statistics_reg                                                (*((volatile unsigned int*)CMPRS_Statistics_reg))
#define  CMPRS_Statistics_qp_count_y_shift                                       (16)
#define  CMPRS_Statistics_qp_count_c_shift                                       (0)
#define  CMPRS_Statistics_qp_count_y_mask                                        (0xFFFF0000)
#define  CMPRS_Statistics_qp_count_c_mask                                        (0x0000FFFF)
#define  CMPRS_Statistics_qp_count_y(data)                                       (0xFFFF0000&((data)<<16))
#define  CMPRS_Statistics_qp_count_c(data)                                       (0x0000FFFF&(data))
#define  CMPRS_Statistics_get_qp_count_y(data)                                   ((0xFFFF0000&(data))>>16)
#define  CMPRS_Statistics_get_qp_count_c(data)                                   (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CMPRS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dmy_auto_mode:1;
        RBus_UInt32  dmy_mb_row:1;
        RBus_UInt32  dmy_mb_clm:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  dmy_row_ctb:1;
        RBus_UInt32  dmy_clm_ctb:1;
        RBus_UInt32  mb_num:4;
        RBus_UInt32  cur_mb_x:10;
        RBus_UInt32  cur_mb_y:9;
    };
}cmprs_ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  max_leaf_nodes:6;
        RBus_UInt32  dma_eff_enhance:1;
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  hdr_addr_update:1;
        RBus_UInt32  comp_core_irq:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  comp_core_bypass:1;
        RBus_UInt32  comp_core_errflag_clr:4;
        RBus_UInt32  comp_core_flag2irq_en:4;
        RBus_UInt32  comp_core_errflag:4;
    };
}cmprs_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  sb_str_addr:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  offseta2:7;
        RBus_UInt32  basea2:7;
    };
}cmprs_vmadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  offseta1:7;
        RBus_UInt32  basea1:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  offseta0:7;
        RBus_UInt32  basea0:7;
    };
}cmprs_vmadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr:32;
    };
}cmprs_hdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  budget_bytes:7;
        RBus_UInt32  qp_decision_method_y:1;
        RBus_UInt32  qp_decision_method_c:1;
        RBus_UInt32  alternate_budget_y:6;
        RBus_UInt32  alternate_budget_c:6;
        RBus_UInt32  min_qp_y:2;
        RBus_UInt32  min_qp_c:2;
    };
}cmprs_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qp_count_y:16;
        RBus_UInt32  qp_count_c:16;
    };
}cmprs_statistics_RBUS;

#else //apply LITTLE_ENDIAN

//======CMPRS register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_mb_y:9;
        RBus_UInt32  cur_mb_x:10;
        RBus_UInt32  mb_num:4;
        RBus_UInt32  dmy_clm_ctb:1;
        RBus_UInt32  dmy_row_ctb:1;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dmy_mb_clm:1;
        RBus_UInt32  dmy_mb_row:1;
        RBus_UInt32  dmy_auto_mode:1;
        RBus_UInt32  res2:1;
    };
}cmprs_ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  comp_core_errflag:4;
        RBus_UInt32  comp_core_flag2irq_en:4;
        RBus_UInt32  comp_core_errflag_clr:4;
        RBus_UInt32  comp_core_bypass:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  comp_core_irq:1;
        RBus_UInt32  hdr_addr_update:1;
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  dma_eff_enhance:1;
        RBus_UInt32  max_leaf_nodes:6;
        RBus_UInt32  res2:7;
    };
}cmprs_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  basea2:7;
        RBus_UInt32  offseta2:7;
        RBus_UInt32  res1:2;
        RBus_UInt32  sb_str_addr:7;
        RBus_UInt32  res2:9;
    };
}cmprs_vmadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  basea0:7;
        RBus_UInt32  offseta0:7;
        RBus_UInt32  res1:2;
        RBus_UInt32  basea1:7;
        RBus_UInt32  offseta1:7;
        RBus_UInt32  res2:2;
    };
}cmprs_vmadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr:32;
    };
}cmprs_hdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_qp_c:2;
        RBus_UInt32  min_qp_y:2;
        RBus_UInt32  alternate_budget_c:6;
        RBus_UInt32  alternate_budget_y:6;
        RBus_UInt32  qp_decision_method_c:1;
        RBus_UInt32  qp_decision_method_y:1;
        RBus_UInt32  budget_bytes:7;
        RBus_UInt32  res1:7;
    };
}cmprs_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qp_count_c:16;
        RBus_UInt32  qp_count_y:16;
    };
}cmprs_statistics_RBUS;




#endif 


#endif 
