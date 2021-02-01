/**
* @file rbusDC_SYS_SECUREReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/12/14
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DC_SYS_SECURE_REG_H_
#define _RBUS_DC_SYS_SECURE_REG_H_

#include "rbus_types.h"



//  DC_SYS_SECURE Register Address
#define  DC_SYS_SECURE_exsram_ctrl                                               0x18007500
#define  DC_SYS_SECURE_exsram_ctrl_reg_addr                                      "0xB8007500"
#define  DC_SYS_SECURE_exsram_ctrl_reg                                           0xB8007500
#define  DC_SYS_SECURE_exsram_ctrl_inst_addr                                     "0x0000"
#define  set_DC_SYS_SECURE_exsram_ctrl_reg(data)                                 (*((volatile unsigned int*)DC_SYS_SECURE_exsram_ctrl_reg)=data)
#define  get_DC_SYS_SECURE_exsram_ctrl_reg                                       (*((volatile unsigned int*)DC_SYS_SECURE_exsram_ctrl_reg))
#define  DC_SYS_SECURE_exsram_ctrl_dcmc_secure_int_route_2_nonsecure_shift       (2)
#define  DC_SYS_SECURE_exsram_ctrl_dc_scpu_di_sram_off_shift                     (1)
#define  DC_SYS_SECURE_exsram_ctrl_enable_shift                                  (0)
#define  DC_SYS_SECURE_exsram_ctrl_dcmc_secure_int_route_2_nonsecure_mask        (0x00000004)
#define  DC_SYS_SECURE_exsram_ctrl_dc_scpu_di_sram_off_mask                      (0x00000002)
#define  DC_SYS_SECURE_exsram_ctrl_enable_mask                                   (0x00000001)
#define  DC_SYS_SECURE_exsram_ctrl_dcmc_secure_int_route_2_nonsecure(data)       (0x00000004&((data)<<2))
#define  DC_SYS_SECURE_exsram_ctrl_dc_scpu_di_sram_off(data)                     (0x00000002&((data)<<1))
#define  DC_SYS_SECURE_exsram_ctrl_enable(data)                                  (0x00000001&(data))
#define  DC_SYS_SECURE_exsram_ctrl_get_dcmc_secure_int_route_2_nonsecure(data)   ((0x00000004&(data))>>2)
#define  DC_SYS_SECURE_exsram_ctrl_get_dc_scpu_di_sram_off(data)                 ((0x00000002&(data))>>1)
#define  DC_SYS_SECURE_exsram_ctrl_get_enable(data)                              (0x00000001&(data))

#define  DC_SYS_SECURE_DC_mem_exsram_ctrl                                        0x18007504
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_reg_addr                               "0xB8007504"
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_reg                                    0xB8007504
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_inst_addr                              "0x0001"
#define  set_DC_SYS_SECURE_DC_mem_exsram_ctrl_reg(data)                          (*((volatile unsigned int*)DC_SYS_SECURE_DC_mem_exsram_ctrl_reg)=data)
#define  get_DC_SYS_SECURE_DC_mem_exsram_ctrl_reg                                (*((volatile unsigned int*)DC_SYS_SECURE_DC_mem_exsram_ctrl_reg))
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_exsram_0_en_shift                      (16)
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_exsram_0_en_mask                       (0x00010000)
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_exsram_0_en(data)                      (0x00010000&((data)<<16))
#define  DC_SYS_SECURE_DC_mem_exsram_ctrl_get_exsram_0_en(data)                  ((0x00010000&(data))>>16)

#define  DC_SYS_SECURE_DC_mem_exsram_access_r                                    0x18007508
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_reg_addr                           "0xB8007508"
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_reg                                0xB8007508
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_inst_addr                          "0x0002"
#define  set_DC_SYS_SECURE_DC_mem_exsram_access_r_reg(data)                      (*((volatile unsigned int*)DC_SYS_SECURE_DC_mem_exsram_access_r_reg)=data)
#define  get_DC_SYS_SECURE_DC_mem_exsram_access_r_reg                            (*((volatile unsigned int*)DC_SYS_SECURE_DC_mem_exsram_access_r_reg))
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_tp_kc_shift                        (4)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_emmc_kc_shift                      (3)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_nf_kc_shift                        (2)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_cp_kc_shift                        (1)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_md_kc_shift                        (0)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_tp_kc_mask                         (0x00000010)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_emmc_kc_mask                       (0x00000008)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_nf_kc_mask                         (0x00000004)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_cp_kc_mask                         (0x00000002)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_md_kc_mask                         (0x00000001)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_tp_kc(data)                        (0x00000010&((data)<<4))
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_emmc_kc(data)                      (0x00000008&((data)<<3))
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_nf_kc(data)                        (0x00000004&((data)<<2))
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_cp_kc(data)                        (0x00000002&((data)<<1))
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_md_kc(data)                        (0x00000001&(data))
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_get_tp_kc(data)                    ((0x00000010&(data))>>4)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_get_emmc_kc(data)                  ((0x00000008&(data))>>3)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_get_nf_kc(data)                    ((0x00000004&(data))>>2)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_get_cp_kc(data)                    ((0x00000002&(data))>>1)
#define  DC_SYS_SECURE_DC_mem_exsram_access_r_get_md_kc(data)                    (0x00000001&(data))

#define  DC_SYS_SECURE_DC_mem_exsram_access_w                                    0x1800750C
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_reg_addr                           "0xB800750C"
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_reg                                0xB800750C
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_inst_addr                          "0x0003"
#define  set_DC_SYS_SECURE_DC_mem_exsram_access_w_reg(data)                      (*((volatile unsigned int*)DC_SYS_SECURE_DC_mem_exsram_access_w_reg)=data)
#define  get_DC_SYS_SECURE_DC_mem_exsram_access_w_reg                            (*((volatile unsigned int*)DC_SYS_SECURE_DC_mem_exsram_access_w_reg))
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_tp_kc_shift                        (4)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_emmc_kc_shift                      (3)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_nf_kc_shift                        (2)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_cp_kc_shift                        (1)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_md_kc_shift                        (0)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_tp_kc_mask                         (0x00000010)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_emmc_kc_mask                       (0x00000008)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_nf_kc_mask                         (0x00000004)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_cp_kc_mask                         (0x00000002)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_md_kc_mask                         (0x00000001)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_tp_kc(data)                        (0x00000010&((data)<<4))
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_emmc_kc(data)                      (0x00000008&((data)<<3))
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_nf_kc(data)                        (0x00000004&((data)<<2))
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_cp_kc(data)                        (0x00000002&((data)<<1))
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_md_kc(data)                        (0x00000001&(data))
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_get_tp_kc(data)                    ((0x00000010&(data))>>4)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_get_emmc_kc(data)                  ((0x00000008&(data))>>3)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_get_nf_kc(data)                    ((0x00000004&(data))>>2)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_get_cp_kc(data)                    ((0x00000002&(data))>>1)
#define  DC_SYS_SECURE_DC_mem_exsram_access_w_get_md_kc(data)                    (0x00000001&(data))

#define  DC_SYS_SECURE_DC_secure_exsram_int                                      0x18007510
#define  DC_SYS_SECURE_DC_secure_exsram_int_reg_addr                             "0xB8007510"
#define  DC_SYS_SECURE_DC_secure_exsram_int_reg                                  0xB8007510
#define  DC_SYS_SECURE_DC_secure_exsram_int_inst_addr                            "0x0004"
#define  set_DC_SYS_SECURE_DC_secure_exsram_int_reg(data)                        (*((volatile unsigned int*)DC_SYS_SECURE_DC_secure_exsram_int_reg)=data)
#define  get_DC_SYS_SECURE_DC_secure_exsram_int_reg                              (*((volatile unsigned int*)DC_SYS_SECURE_DC_secure_exsram_int_reg))
#define  DC_SYS_SECURE_DC_secure_exsram_int_exsram_int_en_shift                  (16)
#define  DC_SYS_SECURE_DC_secure_exsram_int_exsram_int_shift                     (0)
#define  DC_SYS_SECURE_DC_secure_exsram_int_exsram_int_en_mask                   (0x00010000)
#define  DC_SYS_SECURE_DC_secure_exsram_int_exsram_int_mask                      (0x00000001)
#define  DC_SYS_SECURE_DC_secure_exsram_int_exsram_int_en(data)                  (0x00010000&((data)<<16))
#define  DC_SYS_SECURE_DC_secure_exsram_int_exsram_int(data)                     (0x00000001&(data))
#define  DC_SYS_SECURE_DC_secure_exsram_int_get_exsram_int_en(data)              ((0x00010000&(data))>>16)
#define  DC_SYS_SECURE_DC_secure_exsram_int_get_exsram_int(data)                 (0x00000001&(data))

#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0                             0x18007514
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_reg_addr                    "0xB8007514"
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_reg                         0xB8007514
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_inst_addr                   "0x0005"
#define  set_DC_SYS_SECURE_DC_secure_exsram_error_info_0_reg(data)               (*((volatile unsigned int*)DC_SYS_SECURE_DC_secure_exsram_error_info_0_reg)=data)
#define  get_DC_SYS_SECURE_DC_secure_exsram_error_info_0_reg                     (*((volatile unsigned int*)DC_SYS_SECURE_DC_secure_exsram_error_info_0_reg))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_latch_shift             (28)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_blk_shift               (20)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_bl_shift                (12)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_w_shift                 (8)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_id_shift                (0)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_latch_mask              (0x10000000)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_blk_mask                (0x00100000)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_bl_mask                 (0x000FF000)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_w_mask                  (0x00000100)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_id_mask                 (0x000000FF)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_latch(data)             (0x10000000&((data)<<28))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_blk(data)               (0x00100000&((data)<<20))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_bl(data)                (0x000FF000&((data)<<12))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_w(data)                 (0x00000100&((data)<<8))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_err_id(data)                (0x000000FF&(data))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_get_err_latch(data)         ((0x10000000&(data))>>28)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_get_err_blk(data)           ((0x00100000&(data))>>20)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_get_err_bl(data)            ((0x000FF000&(data))>>12)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_get_err_w(data)             ((0x00000100&(data))>>8)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_0_get_err_id(data)            (0x000000FF&(data))

#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1                             0x18007518
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_reg_addr                    "0xB8007518"
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_reg                         0xB8007518
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_inst_addr                   "0x0006"
#define  set_DC_SYS_SECURE_DC_secure_exsram_error_info_1_reg(data)               (*((volatile unsigned int*)DC_SYS_SECURE_DC_secure_exsram_error_info_1_reg)=data)
#define  get_DC_SYS_SECURE_DC_secure_exsram_error_info_1_reg                     (*((volatile unsigned int*)DC_SYS_SECURE_DC_secure_exsram_error_info_1_reg))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_err_addr_shift              (3)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_err_addr_mask               (0xFFFFFFF8)
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_err_addr(data)              (0xFFFFFFF8&((data)<<3))
#define  DC_SYS_SECURE_DC_secure_exsram_error_info_1_get_err_addr(data)          ((0xFFFFFFF8&(data))>>3)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DC_SYS_SECURE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dcmc_secure_int_route_2_nonsecure:1;
        RBus_UInt32  dc_scpu_di_sram_off:1;
        RBus_UInt32  enable:1;
    };
}dc_sys_secure_exsram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  exsram_0_en:1;
        RBus_UInt32  res2:16;
    };
}dc_sys_secure_dc_mem_exsram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_kc:1;
    };
}dc_sys_secure_dc_mem_exsram_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_kc:1;
    };
}dc_sys_secure_dc_mem_exsram_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  exsram_int_en:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  exsram_int:1;
    };
}dc_sys_secure_dc_secure_exsram_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  err_latch:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  err_blk:1;
        RBus_UInt32  err_bl:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  err_w:1;
        RBus_UInt32  err_id:8;
    };
}dc_sys_secure_dc_secure_exsram_error_info_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_addr:29;
        RBus_UInt32  res1:3;
    };
}dc_sys_secure_dc_secure_exsram_error_info_1_RBUS;

#else //apply LITTLE_ENDIAN

//======DC_SYS_SECURE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  dc_scpu_di_sram_off:1;
        RBus_UInt32  dcmc_secure_int_route_2_nonsecure:1;
        RBus_UInt32  res1:29;
    };
}dc_sys_secure_exsram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  exsram_0_en:1;
        RBus_UInt32  res2:15;
    };
}dc_sys_secure_dc_mem_exsram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  res1:27;
    };
}dc_sys_secure_dc_mem_exsram_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  res1:27;
    };
}dc_sys_secure_dc_mem_exsram_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  exsram_int:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  exsram_int_en:1;
        RBus_UInt32  res2:15;
    };
}dc_sys_secure_dc_secure_exsram_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_id:8;
        RBus_UInt32  err_w:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  err_bl:8;
        RBus_UInt32  err_blk:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  err_latch:1;
        RBus_UInt32  res3:3;
    };
}dc_sys_secure_dc_secure_exsram_error_info_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  err_addr:29;
    };
}dc_sys_secure_dc_secure_exsram_error_info_1_RBUS;




#endif 


#endif 
