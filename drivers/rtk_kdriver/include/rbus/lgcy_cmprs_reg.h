/**
* @file Mac5_LGCY_VE_CMPRS_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_CMPRS_REG_H_
#define _RBUS_LGCY_CMPRS_REG_H_

#include "rbus_types.h"



//  LGCY_CMPRS Register Address
#define  LGCY_CMPRS_CCPAR                                                        0x1800EB80
#define  LGCY_CMPRS_CCPAR_reg_addr                                               "0xB800EB80"
#define  LGCY_CMPRS_CCPAR_reg                                                    0xB800EB80
#define  LGCY_CMPRS_CCPAR_inst_addr                                              "0x0000"
#define  set_LGCY_CMPRS_CCPAR_reg(data)                                          (*((volatile unsigned int*)LGCY_CMPRS_CCPAR_reg)=data)
#define  get_LGCY_CMPRS_CCPAR_reg                                                (*((volatile unsigned int*)LGCY_CMPRS_CCPAR_reg))
#define  LGCY_CMPRS_CCPAR_dmy_auto_mode_shift                                    (30)
#define  LGCY_CMPRS_CCPAR_dmy_mb_row_shift                                       (29)
#define  LGCY_CMPRS_CCPAR_dmy_mb_clm_shift                                       (28)
#define  LGCY_CMPRS_CCPAR_mb_field_decoding_flag_shift                           (25)
#define  LGCY_CMPRS_CCPAR_dmy_row_ctb_shift                                      (24)
#define  LGCY_CMPRS_CCPAR_dmy_clm_ctb_shift                                      (23)
#define  LGCY_CMPRS_CCPAR_mb_num_shift                                           (19)
#define  LGCY_CMPRS_CCPAR_cur_mb_x_shift                                         (9)
#define  LGCY_CMPRS_CCPAR_cur_mb_y_shift                                         (0)
#define  LGCY_CMPRS_CCPAR_dmy_auto_mode_mask                                     (0x40000000)
#define  LGCY_CMPRS_CCPAR_dmy_mb_row_mask                                        (0x20000000)
#define  LGCY_CMPRS_CCPAR_dmy_mb_clm_mask                                        (0x10000000)
#define  LGCY_CMPRS_CCPAR_mb_field_decoding_flag_mask                            (0x02000000)
#define  LGCY_CMPRS_CCPAR_dmy_row_ctb_mask                                       (0x01000000)
#define  LGCY_CMPRS_CCPAR_dmy_clm_ctb_mask                                       (0x00800000)
#define  LGCY_CMPRS_CCPAR_mb_num_mask                                            (0x00780000)
#define  LGCY_CMPRS_CCPAR_cur_mb_x_mask                                          (0x0007FE00)
#define  LGCY_CMPRS_CCPAR_cur_mb_y_mask                                          (0x000001FF)
#define  LGCY_CMPRS_CCPAR_dmy_auto_mode(data)                                    (0x40000000&((data)<<30))
#define  LGCY_CMPRS_CCPAR_dmy_mb_row(data)                                       (0x20000000&((data)<<29))
#define  LGCY_CMPRS_CCPAR_dmy_mb_clm(data)                                       (0x10000000&((data)<<28))
#define  LGCY_CMPRS_CCPAR_mb_field_decoding_flag(data)                           (0x02000000&((data)<<25))
#define  LGCY_CMPRS_CCPAR_dmy_row_ctb(data)                                      (0x01000000&((data)<<24))
#define  LGCY_CMPRS_CCPAR_dmy_clm_ctb(data)                                      (0x00800000&((data)<<23))
#define  LGCY_CMPRS_CCPAR_mb_num(data)                                           (0x00780000&((data)<<19))
#define  LGCY_CMPRS_CCPAR_cur_mb_x(data)                                         (0x0007FE00&((data)<<9))
#define  LGCY_CMPRS_CCPAR_cur_mb_y(data)                                         (0x000001FF&(data))
#define  LGCY_CMPRS_CCPAR_get_dmy_auto_mode(data)                                ((0x40000000&(data))>>30)
#define  LGCY_CMPRS_CCPAR_get_dmy_mb_row(data)                                   ((0x20000000&(data))>>29)
#define  LGCY_CMPRS_CCPAR_get_dmy_mb_clm(data)                                   ((0x10000000&(data))>>28)
#define  LGCY_CMPRS_CCPAR_get_mb_field_decoding_flag(data)                       ((0x02000000&(data))>>25)
#define  LGCY_CMPRS_CCPAR_get_dmy_row_ctb(data)                                  ((0x01000000&(data))>>24)
#define  LGCY_CMPRS_CCPAR_get_dmy_clm_ctb(data)                                  ((0x00800000&(data))>>23)
#define  LGCY_CMPRS_CCPAR_get_mb_num(data)                                       ((0x00780000&(data))>>19)
#define  LGCY_CMPRS_CCPAR_get_cur_mb_x(data)                                     ((0x0007FE00&(data))>>9)
#define  LGCY_CMPRS_CCPAR_get_cur_mb_y(data)                                     (0x000001FF&(data))

#define  LGCY_CMPRS_STATUS                                                       0x1800EB84
#define  LGCY_CMPRS_STATUS_reg_addr                                              "0xB800EB84"
#define  LGCY_CMPRS_STATUS_reg                                                   0xB800EB84
#define  LGCY_CMPRS_STATUS_inst_addr                                             "0x0001"
#define  set_LGCY_CMPRS_STATUS_reg(data)                                         (*((volatile unsigned int*)LGCY_CMPRS_STATUS_reg)=data)
#define  get_LGCY_CMPRS_STATUS_reg                                               (*((volatile unsigned int*)LGCY_CMPRS_STATUS_reg))
#define  LGCY_CMPRS_STATUS_max_leaf_nodes_shift                                  (19)
#define  LGCY_CMPRS_STATUS_dma_eff_enhance_shift                                 (18)
#define  LGCY_CMPRS_STATUS_post_write_disable_shift                              (17)
#define  LGCY_CMPRS_STATUS_hdr_addr_update_shift                                 (16)
#define  LGCY_CMPRS_STATUS_comp_core_irq_shift                                   (15)
#define  LGCY_CMPRS_STATUS_comp_core_bypass_shift                                (12)
#define  LGCY_CMPRS_STATUS_comp_core_errflag_clr_shift                           (8)
#define  LGCY_CMPRS_STATUS_comp_core_flag2irq_en_shift                           (4)
#define  LGCY_CMPRS_STATUS_comp_core_errflag_shift                               (0)
#define  LGCY_CMPRS_STATUS_max_leaf_nodes_mask                                   (0x01F80000)
#define  LGCY_CMPRS_STATUS_dma_eff_enhance_mask                                  (0x00040000)
#define  LGCY_CMPRS_STATUS_post_write_disable_mask                               (0x00020000)
#define  LGCY_CMPRS_STATUS_hdr_addr_update_mask                                  (0x00010000)
#define  LGCY_CMPRS_STATUS_comp_core_irq_mask                                    (0x00008000)
#define  LGCY_CMPRS_STATUS_comp_core_bypass_mask                                 (0x00001000)
#define  LGCY_CMPRS_STATUS_comp_core_errflag_clr_mask                            (0x00000F00)
#define  LGCY_CMPRS_STATUS_comp_core_flag2irq_en_mask                            (0x000000F0)
#define  LGCY_CMPRS_STATUS_comp_core_errflag_mask                                (0x0000000F)
#define  LGCY_CMPRS_STATUS_max_leaf_nodes(data)                                  (0x01F80000&((data)<<19))
#define  LGCY_CMPRS_STATUS_dma_eff_enhance(data)                                 (0x00040000&((data)<<18))
#define  LGCY_CMPRS_STATUS_post_write_disable(data)                              (0x00020000&((data)<<17))
#define  LGCY_CMPRS_STATUS_hdr_addr_update(data)                                 (0x00010000&((data)<<16))
#define  LGCY_CMPRS_STATUS_comp_core_irq(data)                                   (0x00008000&((data)<<15))
#define  LGCY_CMPRS_STATUS_comp_core_bypass(data)                                (0x00001000&((data)<<12))
#define  LGCY_CMPRS_STATUS_comp_core_errflag_clr(data)                           (0x00000F00&((data)<<8))
#define  LGCY_CMPRS_STATUS_comp_core_flag2irq_en(data)                           (0x000000F0&((data)<<4))
#define  LGCY_CMPRS_STATUS_comp_core_errflag(data)                               (0x0000000F&(data))
#define  LGCY_CMPRS_STATUS_get_max_leaf_nodes(data)                              ((0x01F80000&(data))>>19)
#define  LGCY_CMPRS_STATUS_get_dma_eff_enhance(data)                             ((0x00040000&(data))>>18)
#define  LGCY_CMPRS_STATUS_get_post_write_disable(data)                          ((0x00020000&(data))>>17)
#define  LGCY_CMPRS_STATUS_get_hdr_addr_update(data)                             ((0x00010000&(data))>>16)
#define  LGCY_CMPRS_STATUS_get_comp_core_irq(data)                               ((0x00008000&(data))>>15)
#define  LGCY_CMPRS_STATUS_get_comp_core_bypass(data)                            ((0x00001000&(data))>>12)
#define  LGCY_CMPRS_STATUS_get_comp_core_errflag_clr(data)                       ((0x00000F00&(data))>>8)
#define  LGCY_CMPRS_STATUS_get_comp_core_flag2irq_en(data)                       ((0x000000F0&(data))>>4)
#define  LGCY_CMPRS_STATUS_get_comp_core_errflag(data)                           (0x0000000F&(data))

#define  LGCY_CMPRS_VMADR0                                                       0x1800EB88
#define  LGCY_CMPRS_VMADR0_reg_addr                                              "0xB800EB88"
#define  LGCY_CMPRS_VMADR0_reg                                                   0xB800EB88
#define  LGCY_CMPRS_VMADR0_inst_addr                                             "0x0002"
#define  set_LGCY_CMPRS_VMADR0_reg(data)                                         (*((volatile unsigned int*)LGCY_CMPRS_VMADR0_reg)=data)
#define  get_LGCY_CMPRS_VMADR0_reg                                               (*((volatile unsigned int*)LGCY_CMPRS_VMADR0_reg))
#define  LGCY_CMPRS_VMADR0_sb_str_addr_shift                                     (16)
#define  LGCY_CMPRS_VMADR0_offseta2_shift                                        (7)
#define  LGCY_CMPRS_VMADR0_basea2_shift                                          (0)
#define  LGCY_CMPRS_VMADR0_sb_str_addr_mask                                      (0x007F0000)
#define  LGCY_CMPRS_VMADR0_offseta2_mask                                         (0x00003F80)
#define  LGCY_CMPRS_VMADR0_basea2_mask                                           (0x0000007F)
#define  LGCY_CMPRS_VMADR0_sb_str_addr(data)                                     (0x007F0000&((data)<<16))
#define  LGCY_CMPRS_VMADR0_offseta2(data)                                        (0x00003F80&((data)<<7))
#define  LGCY_CMPRS_VMADR0_basea2(data)                                          (0x0000007F&(data))
#define  LGCY_CMPRS_VMADR0_get_sb_str_addr(data)                                 ((0x007F0000&(data))>>16)
#define  LGCY_CMPRS_VMADR0_get_offseta2(data)                                    ((0x00003F80&(data))>>7)
#define  LGCY_CMPRS_VMADR0_get_basea2(data)                                      (0x0000007F&(data))

#define  LGCY_CMPRS_VMADR1                                                       0x1800EB8C
#define  LGCY_CMPRS_VMADR1_reg_addr                                              "0xB800EB8C"
#define  LGCY_CMPRS_VMADR1_reg                                                   0xB800EB8C
#define  LGCY_CMPRS_VMADR1_inst_addr                                             "0x0003"
#define  set_LGCY_CMPRS_VMADR1_reg(data)                                         (*((volatile unsigned int*)LGCY_CMPRS_VMADR1_reg)=data)
#define  get_LGCY_CMPRS_VMADR1_reg                                               (*((volatile unsigned int*)LGCY_CMPRS_VMADR1_reg))
#define  LGCY_CMPRS_VMADR1_offseta1_shift                                        (23)
#define  LGCY_CMPRS_VMADR1_basea1_shift                                          (16)
#define  LGCY_CMPRS_VMADR1_offseta0_shift                                        (7)
#define  LGCY_CMPRS_VMADR1_basea0_shift                                          (0)
#define  LGCY_CMPRS_VMADR1_offseta1_mask                                         (0x3F800000)
#define  LGCY_CMPRS_VMADR1_basea1_mask                                           (0x007F0000)
#define  LGCY_CMPRS_VMADR1_offseta0_mask                                         (0x00003F80)
#define  LGCY_CMPRS_VMADR1_basea0_mask                                           (0x0000007F)
#define  LGCY_CMPRS_VMADR1_offseta1(data)                                        (0x3F800000&((data)<<23))
#define  LGCY_CMPRS_VMADR1_basea1(data)                                          (0x007F0000&((data)<<16))
#define  LGCY_CMPRS_VMADR1_offseta0(data)                                        (0x00003F80&((data)<<7))
#define  LGCY_CMPRS_VMADR1_basea0(data)                                          (0x0000007F&(data))
#define  LGCY_CMPRS_VMADR1_get_offseta1(data)                                    ((0x3F800000&(data))>>23)
#define  LGCY_CMPRS_VMADR1_get_basea1(data)                                      ((0x007F0000&(data))>>16)
#define  LGCY_CMPRS_VMADR1_get_offseta0(data)                                    ((0x00003F80&(data))>>7)
#define  LGCY_CMPRS_VMADR1_get_basea0(data)                                      (0x0000007F&(data))

#define  LGCY_CMPRS_HDMAADR_0                                                    0x1800EB90
#define  LGCY_CMPRS_HDMAADR_0_reg_addr                                           "0xB800EB90"
#define  LGCY_CMPRS_HDMAADR_0_reg                                                0xB800EB90
#define  LGCY_CMPRS_HDMAADR_0_inst_addr                                          "0x0004"
#define  set_LGCY_CMPRS_HDMAADR_0_reg(data)                                      (*((volatile unsigned int*)LGCY_CMPRS_HDMAADR_0_reg)=data)
#define  get_LGCY_CMPRS_HDMAADR_0_reg                                            (*((volatile unsigned int*)LGCY_CMPRS_HDMAADR_0_reg))
#define  LGCY_CMPRS_HDMAADR_0_hdr_str_addr_shift                                 (0)
#define  LGCY_CMPRS_HDMAADR_0_hdr_str_addr_mask                                  (0xFFFFFFFF)
#define  LGCY_CMPRS_HDMAADR_0_hdr_str_addr(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_CMPRS_HDMAADR_0_get_hdr_str_addr(data)                             (0xFFFFFFFF&(data))

#define  LGCY_CMPRS_HDMAADR_1                                                    0x1800EB94
#define  LGCY_CMPRS_HDMAADR_1_reg_addr                                           "0xB800EB94"
#define  LGCY_CMPRS_HDMAADR_1_reg                                                0xB800EB94
#define  LGCY_CMPRS_HDMAADR_1_inst_addr                                          "0x0005"
#define  set_LGCY_CMPRS_HDMAADR_1_reg(data)                                      (*((volatile unsigned int*)LGCY_CMPRS_HDMAADR_1_reg)=data)
#define  get_LGCY_CMPRS_HDMAADR_1_reg                                            (*((volatile unsigned int*)LGCY_CMPRS_HDMAADR_1_reg))
#define  LGCY_CMPRS_HDMAADR_1_hdr_str_addr_shift                                 (0)
#define  LGCY_CMPRS_HDMAADR_1_hdr_str_addr_mask                                  (0xFFFFFFFF)
#define  LGCY_CMPRS_HDMAADR_1_hdr_str_addr(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_CMPRS_HDMAADR_1_get_hdr_str_addr(data)                             (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_CMPRS register structure define==========

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
}lgcy_cmprs_ccpar_RBUS;

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
}lgcy_cmprs_status_RBUS;

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
}lgcy_cmprs_vmadr0_RBUS;

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
}lgcy_cmprs_vmadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr:32;
    };
}lgcy_cmprs_hdmaadr_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_CMPRS register structure define==========

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
}lgcy_cmprs_ccpar_RBUS;

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
}lgcy_cmprs_status_RBUS;

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
}lgcy_cmprs_vmadr0_RBUS;

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
}lgcy_cmprs_vmadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdr_str_addr:32;
    };
}lgcy_cmprs_hdmaadr_RBUS;




#endif 


#endif 
