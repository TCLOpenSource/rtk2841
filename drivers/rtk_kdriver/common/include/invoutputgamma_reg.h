/**
* @file rbusInvOutputgammaReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_INVOUTPUTGAMMA_REG_H_
#define _RBUS_INVOUTPUTGAMMA_REG_H_

#include "rbus_types.h"



//  INVOUTPUTGAMMA Register Address
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT                                       0x1802C820
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg_addr                              "0xB802C820"
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg                                   0xB802C820
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inst_addr                             "0x0000"
#define  set_INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg(data)                         (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg)=data)
#define  get_INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg                               (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_reg))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_index_shift         (16)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_d0_shift            (8)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_d1_shift            (0)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_index_mask          (0x0FFF0000)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_d0_mask             (0x00007F00)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_d1_mask             (0x0000007F)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_index(data)         (0x0FFF0000&((data)<<16))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_d0(data)            (0x00007F00&((data)<<8))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_inv_out_gamma_tab_d1(data)            (0x0000007F&(data))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_get_inv_out_gamma_tab_index(data)     ((0x0FFF0000&(data))>>16)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_get_inv_out_gamma_tab_d0(data)        ((0x00007F00&(data))>>8)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_PORT_get_inv_out_gamma_tab_d1(data)        (0x0000007F&(data))

#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1                                     0x1802C824
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg_addr                            "0xB802C824"
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg                                 0xB802C824
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inst_addr                           "0x0001"
#define  set_INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg(data)                       (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg)=data)
#define  get_INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg                             (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_reg))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_tab_addr_shift        (16)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_ax_rw_sel_shift       (7)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_ax_ch_sel_shift       (5)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_fifo_empty_shift      (4)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_fifo_full_shift       (3)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_wr_error_shift        (2)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_dummy_1_shift                       (1)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_en_shift              (0)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_tab_addr_mask         (0x007F0000)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_ax_rw_sel_mask        (0x00000180)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_ax_ch_sel_mask        (0x00000060)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_fifo_empty_mask       (0x00000010)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_fifo_full_mask        (0x00000008)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_wr_error_mask         (0x00000004)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_dummy_1_mask                        (0x00000002)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_en_mask               (0x00000001)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_tab_addr(data)        (0x007F0000&((data)<<16))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_ax_rw_sel(data)       (0x00000180&((data)<<7))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_ax_ch_sel(data)       (0x00000060&((data)<<5))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_fifo_empty(data)      (0x00000010&((data)<<4))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_fifo_full(data)       (0x00000008&((data)<<3))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_wr_error(data)        (0x00000004&((data)<<2))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_dummy_1(data)                       (0x00000002&((data)<<1))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_inv_out_gamma_en(data)              (0x00000001&(data))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_tab_addr(data)    ((0x007F0000&(data))>>16)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_ax_rw_sel(data)   ((0x00000180&(data))>>7)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_ax_ch_sel(data)   ((0x00000060&(data))>>5)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_fifo_empty(data)  ((0x00000010&(data))>>4)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_fifo_full(data)   ((0x00000008&(data))>>3)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_wr_error(data)    ((0x00000004&(data))>>2)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_dummy_1(data)                   ((0x00000002&(data))>>1)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_CTRL_1_get_inv_out_gamma_en(data)          (0x00000001&(data))

#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1                                0x1802C828
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_reg_addr                       "0xB802C828"
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_reg                            0xB802C828
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_inst_addr                      "0x0002"
#define  set_INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_reg(data)                  (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_reg)=data)
#define  get_INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_reg                        (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_reg))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_ls_shift                       (5)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_rme_shift                      (4)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_rm_shift                       (0)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_ls_mask                        (0x00000020)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_rme_mask                       (0x00000010)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_rm_mask                        (0x0000000F)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_ls(data)                       (0x00000020&((data)<<5))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_rme(data)                      (0x00000010&((data)<<4))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_rm(data)                       (0x0000000F&(data))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_get_ls(data)                   ((0x00000020&(data))>>5)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_get_rme(data)                  ((0x00000010&(data))>>4)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_1_get_rm(data)                   (0x0000000F&(data))

#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3                                0x1802C830
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_reg_addr                       "0xB802C830"
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_reg                            0xB802C830
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inst_addr                      "0x0003"
#define  set_INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_reg(data)                  (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_reg)=data)
#define  get_INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_reg                        (*((volatile unsigned int*)INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_reg))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r1_drf_bist_fail_shift (14)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g1_drf_bist_fail_shift (13)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b1_drf_bist_fail_shift (12)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r_drf_bist_fail_shift (10)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g_drf_bist_fail_shift (9)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b_drf_bist_fail_shift (8)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r1_bist_fail_shift (6)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g1_bist_fail_shift (5)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b1_bist_fail_shift (4)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r_bist_fail_shift (2)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g_bist_fail_shift (1)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b_bist_fail_shift (0)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r1_drf_bist_fail_mask (0x00004000)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g1_drf_bist_fail_mask (0x00002000)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b1_drf_bist_fail_mask (0x00001000)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r_drf_bist_fail_mask (0x00000400)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g_drf_bist_fail_mask (0x00000200)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b_drf_bist_fail_mask (0x00000100)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r1_bist_fail_mask (0x00000040)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g1_bist_fail_mask (0x00000020)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b1_bist_fail_mask (0x00000010)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r_bist_fail_mask (0x00000004)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g_bist_fail_mask (0x00000002)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b_bist_fail_mask (0x00000001)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r1_drf_bist_fail(data) (0x00004000&((data)<<14))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g1_drf_bist_fail(data) (0x00002000&((data)<<13))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b1_drf_bist_fail(data) (0x00001000&((data)<<12))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r_drf_bist_fail(data) (0x00000400&((data)<<10))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g_drf_bist_fail(data) (0x00000200&((data)<<9))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b_drf_bist_fail(data) (0x00000100&((data)<<8))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r1_bist_fail(data) (0x00000040&((data)<<6))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g1_bist_fail(data) (0x00000020&((data)<<5))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b1_bist_fail(data) (0x00000010&((data)<<4))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_r_bist_fail(data) (0x00000004&((data)<<2))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_g_bist_fail(data) (0x00000002&((data)<<1))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_inv_out_gamma_b_bist_fail(data) (0x00000001&(data))
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_r1_drf_bist_fail(data) ((0x00004000&(data))>>14)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_g1_drf_bist_fail(data) ((0x00002000&(data))>>13)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_b1_drf_bist_fail(data) ((0x00001000&(data))>>12)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_r_drf_bist_fail(data) ((0x00000400&(data))>>10)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_g_drf_bist_fail(data) ((0x00000200&(data))>>9)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_b_drf_bist_fail(data) ((0x00000100&(data))>>8)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_r1_bist_fail(data) ((0x00000040&(data))>>6)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_g1_bist_fail(data) ((0x00000020&(data))>>5)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_b1_bist_fail(data) ((0x00000010&(data))>>4)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_r_bist_fail(data) ((0x00000004&(data))>>2)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_g_bist_fail(data) ((0x00000002&(data))>>1)
#define  INVOUTPUTGAMMA_INV_OUT_GAMMA_BIST_CTRL_3_get_inv_out_gamma_b_bist_fail(data) (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======INVOUTPUTGAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  inv_out_gamma_tab_index:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  inv_out_gamma_tab_d0:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  inv_out_gamma_tab_d1:7;
    };
}invoutputgamma_inv_out_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  inv_out_gamma_tab_addr:7;
        RBus_UInt32  res2:7;
        RBus_UInt32  inv_out_gamma_ax_rw_sel:2;
        RBus_UInt32  inv_out_gamma_ax_ch_sel:2;
        RBus_UInt32  inv_out_gamma_fifo_empty:1;
        RBus_UInt32  inv_out_gamma_fifo_full:1;
        RBus_UInt32  inv_out_gamma_wr_error:1;
        RBus_UInt32  dummy1802c824_1:1;
        RBus_UInt32  inv_out_gamma_en:1;
    };
}invoutputgamma_inv_out_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}invoutputgamma_inv_out_gamma_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  inv_out_gamma_r1_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g1_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_b1_drf_bist_fail:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  inv_out_gamma_r_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_b_drf_bist_fail:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  inv_out_gamma_r1_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g1_bist_fail:1;
        RBus_UInt32  inv_out_gamma_b1_bist_fail:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  inv_out_gamma_r_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g_bist_fail:1;
        RBus_UInt32  inv_out_gamma_b_bist_fail:1;
    };
}invoutputgamma_inv_out_gamma_bist_ctrl_3_RBUS;

#else //apply LITTLE_ENDIAN

//======INVOUTPUTGAMMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_out_gamma_tab_d1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  inv_out_gamma_tab_d0:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  inv_out_gamma_tab_index:12;
        RBus_UInt32  res3:4;
    };
}invoutputgamma_inv_out_gamma_port_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_out_gamma_en:1;
        RBus_UInt32  dummy1802c824_1:1;
        RBus_UInt32  inv_out_gamma_wr_error:1;
        RBus_UInt32  inv_out_gamma_fifo_full:1;
        RBus_UInt32  inv_out_gamma_fifo_empty:1;
        RBus_UInt32  inv_out_gamma_ax_ch_sel:2;
        RBus_UInt32  inv_out_gamma_ax_rw_sel:2;
        RBus_UInt32  res1:7;
        RBus_UInt32  inv_out_gamma_tab_addr:7;
        RBus_UInt32  res2:9;
    };
}invoutputgamma_inv_out_gamma_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:26;
    };
}invoutputgamma_inv_out_gamma_bist_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inv_out_gamma_b_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g_bist_fail:1;
        RBus_UInt32  inv_out_gamma_r_bist_fail:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  inv_out_gamma_b1_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g1_bist_fail:1;
        RBus_UInt32  inv_out_gamma_r1_bist_fail:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  inv_out_gamma_b_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_r_drf_bist_fail:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  inv_out_gamma_b1_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_g1_drf_bist_fail:1;
        RBus_UInt32  inv_out_gamma_r1_drf_bist_fail:1;
        RBus_UInt32  res4:17;
    };
}invoutputgamma_inv_out_gamma_bist_ctrl_3_RBUS;




#endif 


#endif 
