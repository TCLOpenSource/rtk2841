/**
* @file rbusSaoReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/9
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SAO_REG_H_
#define _RBUS_SAO_REG_H_

#include "rbusTypes.h"



//  SAO Register Address
#define  SAO_SAO_CTRL                                                            0x1800FC00
#define  SAO_SAO_CTRL_reg_addr                                                   "0xB800FC00"
#define  SAO_SAO_CTRL_reg                                                        0xB800FC00
#define  SAO_SAO_CTRL_inst_addr                                                  "0x0000"
#define  SAO_SAO_CTRL_inst_adr                                                   "0x0000"
#define  SAO_SAO_CTRL_inst                                                       0x0000
#define  set_SAO_SAO_CTRL_reg(data)                                              (*((volatile unsigned int*)SAO_SAO_CTRL_reg)=data)
#define  get_SAO_SAO_CTRL_reg                                                    (*((volatile unsigned int*)SAO_SAO_CTRL_reg))
#define  SAO_SAO_CTRL_sao_wdone_1t_after_wlast_shift                             (3)
#define  SAO_SAO_CTRL_sao_reset_shift                                            (2)
#define  SAO_SAO_CTRL_sao_done_shift                                             (1)
#define  SAO_SAO_CTRL_sao_busy_shift                                             (0)
#define  SAO_SAO_CTRL_sao_wdone_1t_after_wlast_mask                              (0x00000008)
#define  SAO_SAO_CTRL_sao_reset_mask                                             (0x00000004)
#define  SAO_SAO_CTRL_sao_done_mask                                              (0x00000002)
#define  SAO_SAO_CTRL_sao_busy_mask                                              (0x00000001)
#define  SAO_SAO_CTRL_sao_wdone_1t_after_wlast(data)                             (0x00000008&((data)<<3))
#define  SAO_SAO_CTRL_sao_reset(data)                                            (0x00000004&((data)<<2))
#define  SAO_SAO_CTRL_sao_done(data)                                             (0x00000002&((data)<<1))
#define  SAO_SAO_CTRL_sao_busy(data)                                             (0x00000001&(data))
#define  SAO_SAO_CTRL_get_sao_wdone_1t_after_wlast(data)                         ((0x00000008&(data))>>3)
#define  SAO_SAO_CTRL_get_sao_reset(data)                                        ((0x00000004&(data))>>2)
#define  SAO_SAO_CTRL_get_sao_done(data)                                         ((0x00000002&(data))>>1)
#define  SAO_SAO_CTRL_get_sao_busy(data)                                         (0x00000001&(data))
#define  SAO_SAO_CTRL_sao_wdone_1t_after_wlast_src(data)                         ((0x00000008&(data))>>3)
#define  SAO_SAO_CTRL_sao_reset_src(data)                                        ((0x00000004&(data))>>2)
#define  SAO_SAO_CTRL_sao_done_src(data)                                         ((0x00000002&(data))>>1)
#define  SAO_SAO_CTRL_sao_busy_src(data)                                         (0x00000001&(data))

#define  SAO_SAO_VM0                                                             0x1800FC04
#define  SAO_SAO_VM0_reg_addr                                                    "0xB800FC04"
#define  SAO_SAO_VM0_reg                                                         0xB800FC04
#define  SAO_SAO_VM0_inst_addr                                                   "0x0001"
#define  SAO_SAO_VM0_inst_adr                                                    "0x0001"
#define  SAO_SAO_VM0_inst                                                        0x0001
#define  set_SAO_SAO_VM0_reg(data)                                               (*((volatile unsigned int*)SAO_SAO_VM0_reg)=data)
#define  get_SAO_SAO_VM0_reg                                                     (*((volatile unsigned int*)SAO_SAO_VM0_reg))
#define  SAO_SAO_VM0_vm_basea0_shift                                             (21)
#define  SAO_SAO_VM0_vm_basea1_shift                                             (14)
#define  SAO_SAO_VM0_vm_sb_adr_shift                                             (0)
#define  SAO_SAO_VM0_vm_basea0_mask                                              (0x0FE00000)
#define  SAO_SAO_VM0_vm_basea1_mask                                              (0x001FC000)
#define  SAO_SAO_VM0_vm_sb_adr_mask                                              (0x0000007F)
#define  SAO_SAO_VM0_vm_basea0(data)                                             (0x0FE00000&((data)<<21))
#define  SAO_SAO_VM0_vm_basea1(data)                                             (0x001FC000&((data)<<14))
#define  SAO_SAO_VM0_vm_sb_adr(data)                                             (0x0000007F&(data))
#define  SAO_SAO_VM0_get_vm_basea0(data)                                         ((0x0FE00000&(data))>>21)
#define  SAO_SAO_VM0_get_vm_basea1(data)                                         ((0x001FC000&(data))>>14)
#define  SAO_SAO_VM0_get_vm_sb_adr(data)                                         (0x0000007F&(data))
#define  SAO_SAO_VM0_vm_basea0_src(data)                                         ((0x0FE00000&(data))>>21)
#define  SAO_SAO_VM0_vm_basea1_src(data)                                         ((0x001FC000&(data))>>14)
#define  SAO_SAO_VM0_vm_sb_adr_src(data)                                         (0x0000007F&(data))

#define  SAO_SAO_VM1                                                             0x1800FC08
#define  SAO_SAO_VM1_reg_addr                                                    "0xB800FC08"
#define  SAO_SAO_VM1_reg                                                         0xB800FC08
#define  SAO_SAO_VM1_inst_addr                                                   "0x0002"
#define  SAO_SAO_VM1_inst_adr                                                    "0x0002"
#define  SAO_SAO_VM1_inst                                                        0x0002
#define  set_SAO_SAO_VM1_reg(data)                                               (*((volatile unsigned int*)SAO_SAO_VM1_reg)=data)
#define  get_SAO_SAO_VM1_reg                                                     (*((volatile unsigned int*)SAO_SAO_VM1_reg))
#define  SAO_SAO_VM1_vm_offseta0_shift                                           (21)
#define  SAO_SAO_VM1_vm_offseta1_shift                                           (14)
#define  SAO_SAO_VM1_vm_offseta0_mask                                            (0x0FE00000)
#define  SAO_SAO_VM1_vm_offseta1_mask                                            (0x001FC000)
#define  SAO_SAO_VM1_vm_offseta0(data)                                           (0x0FE00000&((data)<<21))
#define  SAO_SAO_VM1_vm_offseta1(data)                                           (0x001FC000&((data)<<14))
#define  SAO_SAO_VM1_get_vm_offseta0(data)                                       ((0x0FE00000&(data))>>21)
#define  SAO_SAO_VM1_get_vm_offseta1(data)                                       ((0x001FC000&(data))>>14)
#define  SAO_SAO_VM1_vm_offseta0_src(data)                                       ((0x0FE00000&(data))>>21)
#define  SAO_SAO_VM1_vm_offseta1_src(data)                                       ((0x001FC000&(data))>>14)

#define  SAO_SAO_DMA                                                             0x1800FC0C
#define  SAO_SAO_DMA_reg_addr                                                    "0xB800FC0C"
#define  SAO_SAO_DMA_reg                                                         0xB800FC0C
#define  SAO_SAO_DMA_inst_addr                                                   "0x0003"
#define  SAO_SAO_DMA_inst_adr                                                    "0x0003"
#define  SAO_SAO_DMA_inst                                                        0x0003
#define  set_SAO_SAO_DMA_reg(data)                                               (*((volatile unsigned int*)SAO_SAO_DMA_reg)=data)
#define  get_SAO_SAO_DMA_reg                                                     (*((volatile unsigned int*)SAO_SAO_DMA_reg))
#define  SAO_SAO_DMA_dma_busy_shift                                              (31)
#define  SAO_SAO_DMA_dma_adr_shift                                               (0)
#define  SAO_SAO_DMA_dma_busy_mask                                               (0x80000000)
#define  SAO_SAO_DMA_dma_adr_mask                                                (0x7FFFFFFF)
#define  SAO_SAO_DMA_dma_busy(data)                                              (0x80000000&((data)<<31))
#define  SAO_SAO_DMA_dma_adr(data)                                               (0x7FFFFFFF&(data))
#define  SAO_SAO_DMA_get_dma_busy(data)                                          ((0x80000000&(data))>>31)
#define  SAO_SAO_DMA_get_dma_adr(data)                                           (0x7FFFFFFF&(data))
#define  SAO_SAO_DMA_dma_busy_src(data)                                          ((0x80000000&(data))>>31)
#define  SAO_SAO_DMA_dma_adr_src(data)                                           (0x7FFFFFFF&(data))

#define  SAO_SAO_DBG0                                                            0x1800FC10
#define  SAO_SAO_DBG0_reg_addr                                                   "0xB800FC10"
#define  SAO_SAO_DBG0_reg                                                        0xB800FC10
#define  SAO_SAO_DBG0_inst_addr                                                  "0x0004"
#define  SAO_SAO_DBG0_inst_adr                                                   "0x0004"
#define  SAO_SAO_DBG0_inst                                                       0x0004
#define  set_SAO_SAO_DBG0_reg(data)                                              (*((volatile unsigned int*)SAO_SAO_DBG0_reg)=data)
#define  get_SAO_SAO_DBG0_reg                                                    (*((volatile unsigned int*)SAO_SAO_DBG0_reg))
#define  SAO_SAO_DBG0_sao_debug_en_shift                                         (12)
#define  SAO_SAO_DBG0_sao_debug_go_shift                                         (11)
#define  SAO_SAO_DBG0_mem_update_shift                                           (10)
#define  SAO_SAO_DBG0_mb_side_h_shift                                            (8)
#define  SAO_SAO_DBG0_mb_side_v_shift                                            (6)
#define  SAO_SAO_DBG0_state_skm0_shift                                           (4)
#define  SAO_SAO_DBG0_state_skm1_shift                                           (2)
#define  SAO_SAO_DBG0_skm_bank_sao_shift                                         (1)
#define  SAO_SAO_DBG0_skm_bank_dma_shift                                         (0)
#define  SAO_SAO_DBG0_sao_debug_en_mask                                          (0x00001000)
#define  SAO_SAO_DBG0_sao_debug_go_mask                                          (0x00000800)
#define  SAO_SAO_DBG0_mem_update_mask                                            (0x00000400)
#define  SAO_SAO_DBG0_mb_side_h_mask                                             (0x00000300)
#define  SAO_SAO_DBG0_mb_side_v_mask                                             (0x000000C0)
#define  SAO_SAO_DBG0_state_skm0_mask                                            (0x00000030)
#define  SAO_SAO_DBG0_state_skm1_mask                                            (0x0000000C)
#define  SAO_SAO_DBG0_skm_bank_sao_mask                                          (0x00000002)
#define  SAO_SAO_DBG0_skm_bank_dma_mask                                          (0x00000001)
#define  SAO_SAO_DBG0_sao_debug_en(data)                                         (0x00001000&((data)<<12))
#define  SAO_SAO_DBG0_sao_debug_go(data)                                         (0x00000800&((data)<<11))
#define  SAO_SAO_DBG0_mem_update(data)                                           (0x00000400&((data)<<10))
#define  SAO_SAO_DBG0_mb_side_h(data)                                            (0x00000300&((data)<<8))
#define  SAO_SAO_DBG0_mb_side_v(data)                                            (0x000000C0&((data)<<6))
#define  SAO_SAO_DBG0_state_skm0(data)                                           (0x00000030&((data)<<4))
#define  SAO_SAO_DBG0_state_skm1(data)                                           (0x0000000C&((data)<<2))
#define  SAO_SAO_DBG0_skm_bank_sao(data)                                         (0x00000002&((data)<<1))
#define  SAO_SAO_DBG0_skm_bank_dma(data)                                         (0x00000001&(data))
#define  SAO_SAO_DBG0_get_sao_debug_en(data)                                     ((0x00001000&(data))>>12)
#define  SAO_SAO_DBG0_get_sao_debug_go(data)                                     ((0x00000800&(data))>>11)
#define  SAO_SAO_DBG0_get_mem_update(data)                                       ((0x00000400&(data))>>10)
#define  SAO_SAO_DBG0_get_mb_side_h(data)                                        ((0x00000300&(data))>>8)
#define  SAO_SAO_DBG0_get_mb_side_v(data)                                        ((0x000000C0&(data))>>6)
#define  SAO_SAO_DBG0_get_state_skm0(data)                                       ((0x00000030&(data))>>4)
#define  SAO_SAO_DBG0_get_state_skm1(data)                                       ((0x0000000C&(data))>>2)
#define  SAO_SAO_DBG0_get_skm_bank_sao(data)                                     ((0x00000002&(data))>>1)
#define  SAO_SAO_DBG0_get_skm_bank_dma(data)                                     (0x00000001&(data))
#define  SAO_SAO_DBG0_sao_debug_en_src(data)                                     ((0x00001000&(data))>>12)
#define  SAO_SAO_DBG0_sao_debug_go_src(data)                                     ((0x00000800&(data))>>11)
#define  SAO_SAO_DBG0_mem_update_src(data)                                       ((0x00000400&(data))>>10)
#define  SAO_SAO_DBG0_mb_side_h_src(data)                                        ((0x00000300&(data))>>8)
#define  SAO_SAO_DBG0_mb_side_v_src(data)                                        ((0x000000C0&(data))>>6)
#define  SAO_SAO_DBG0_state_skm0_src(data)                                       ((0x00000030&(data))>>4)
#define  SAO_SAO_DBG0_state_skm1_src(data)                                       ((0x0000000C&(data))>>2)
#define  SAO_SAO_DBG0_skm_bank_sao_src(data)                                     ((0x00000002&(data))>>1)
#define  SAO_SAO_DBG0_skm_bank_dma_src(data)                                     (0x00000001&(data))

#define  SAO_SAO_DBG1                                                            0x1800FC14
#define  SAO_SAO_DBG1_reg_addr                                                   "0xB800FC14"
#define  SAO_SAO_DBG1_reg                                                        0xB800FC14
#define  SAO_SAO_DBG1_inst_addr                                                  "0x0005"
#define  SAO_SAO_DBG1_inst_adr                                                   "0x0005"
#define  SAO_SAO_DBG1_inst                                                       0x0005
#define  set_SAO_SAO_DBG1_reg(data)                                              (*((volatile unsigned int*)SAO_SAO_DBG1_reg)=data)
#define  get_SAO_SAO_DBG1_reg                                                    (*((volatile unsigned int*)SAO_SAO_DBG1_reg))
#define  SAO_SAO_DBG1_dma_debug_adr_shift                                        (0)
#define  SAO_SAO_DBG1_dma_debug_adr_mask                                         (0x7FFFFFFF)
#define  SAO_SAO_DBG1_dma_debug_adr(data)                                        (0x7FFFFFFF&(data))
#define  SAO_SAO_DBG1_get_dma_debug_adr(data)                                    (0x7FFFFFFF&(data))
#define  SAO_SAO_DBG1_dma_debug_adr_src(data)                                    (0x7FFFFFFF&(data))

#ifdef _SAO_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SAO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sao_wdone_1t_after_wlast:1;
        RBus_UInt32  sao_reset:1;
        RBus_UInt32  sao_done:1;
        RBus_UInt32  sao_busy:1;
    };
}SAO_SAO_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vm_basea0:7;
        RBus_UInt32  vm_basea1:7;
        RBus_UInt32  res2:7;
        RBus_UInt32  vm_sb_adr:7;
    };
}SAO_SAO_VM0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vm_offseta0:7;
        RBus_UInt32  vm_offseta1:7;
        RBus_UInt32  res2:14;
    };
}SAO_SAO_VM1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_busy:1;
        RBus_UInt32  dma_adr:31;
    };
}SAO_SAO_DMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  sao_debug_en:1;
        RBus_UInt32  sao_debug_go:1;
        RBus_UInt32  mem_update:1;
        RBus_UInt32  mb_side_h:2;
        RBus_UInt32  mb_side_v:2;
        RBus_UInt32  state_skm0:2;
        RBus_UInt32  state_skm1:2;
        RBus_UInt32  skm_bank_sao:1;
        RBus_UInt32  skm_bank_dma:1;
    };
}SAO_SAO_DBG0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_debug_adr:31;
    };
}SAO_SAO_DBG1_RBUS;

#else //apply LITTLE_ENDIAN

//======SAO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sao_busy:1;
        RBus_UInt32  sao_done:1;
        RBus_UInt32  sao_reset:1;
        RBus_UInt32  sao_wdone_1t_after_wlast:1;
        RBus_UInt32  res1:28;
    };
}SAO_SAO_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vm_sb_adr:7;
        RBus_UInt32  res1:7;
        RBus_UInt32  vm_basea1:7;
        RBus_UInt32  vm_basea0:7;
        RBus_UInt32  res2:4;
    };
}SAO_SAO_VM0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  vm_offseta1:7;
        RBus_UInt32  vm_offseta0:7;
        RBus_UInt32  res2:4;
    };
}SAO_SAO_VM1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_adr:31;
        RBus_UInt32  dma_busy:1;
    };
}SAO_SAO_DMA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  skm_bank_dma:1;
        RBus_UInt32  skm_bank_sao:1;
        RBus_UInt32  state_skm1:2;
        RBus_UInt32  state_skm0:2;
        RBus_UInt32  mb_side_v:2;
        RBus_UInt32  mb_side_h:2;
        RBus_UInt32  mem_update:1;
        RBus_UInt32  sao_debug_go:1;
        RBus_UInt32  sao_debug_en:1;
        RBus_UInt32  res1:19;
    };
}SAO_SAO_DBG0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debug_adr:31;
        RBus_UInt32  res1:1;
    };
}SAO_SAO_DBG1_RBUS;




#endif 


#endif 
#endif 
