/**
* @file MacArthur5-DesignSpec-I-Domain_ring_filter
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RINGFILTER_REG_H_
#define _RBUS_RINGFILTER_REG_H_

#include "rbus_types.h"



//  RINGFILTER Register Address
#define  RINGFILTER_RFILTER_CTRL                                                 0x18023580
#define  RINGFILTER_RFILTER_CTRL_reg_addr                                        "0xB8023580"
#define  RINGFILTER_RFILTER_CTRL_reg                                             0xB8023580
#define  RINGFILTER_RFILTER_CTRL_inst_addr                                       "0x0000"
#define  set_RINGFILTER_RFILTER_CTRL_reg(data)                                   (*((volatile unsigned int*)RINGFILTER_RFILTER_CTRL_reg)=data)
#define  get_RINGFILTER_RFILTER_CTRL_reg                                         (*((volatile unsigned int*)RINGFILTER_RFILTER_CTRL_reg))
#define  RINGFILTER_RFILTER_CTRL_rfilter_lsb2_tie0_shift                         (8)
#define  RINGFILTER_RFILTER_CTRL_rfilter_en_shift                                (7)
#define  RINGFILTER_RFILTER_CTRL_rfilter_ofs_rng_mode_shift                      (6)
#define  RINGFILTER_RFILTER_CTRL_rfilter_jj_en_shift                             (5)
#define  RINGFILTER_RFILTER_CTRL_rfilter_r_unaffected_shift                      (4)
#define  RINGFILTER_RFILTER_CTRL_rfilter_g_unaffected_shift                      (3)
#define  RINGFILTER_RFILTER_CTRL_rfilter_b_unaffected_shift                      (2)
#define  RINGFILTER_RFILTER_CTRL_rfilter_lsb2_tie0_mask                          (0x00000100)
#define  RINGFILTER_RFILTER_CTRL_rfilter_en_mask                                 (0x00000080)
#define  RINGFILTER_RFILTER_CTRL_rfilter_ofs_rng_mode_mask                       (0x00000040)
#define  RINGFILTER_RFILTER_CTRL_rfilter_jj_en_mask                              (0x00000020)
#define  RINGFILTER_RFILTER_CTRL_rfilter_r_unaffected_mask                       (0x00000010)
#define  RINGFILTER_RFILTER_CTRL_rfilter_g_unaffected_mask                       (0x00000008)
#define  RINGFILTER_RFILTER_CTRL_rfilter_b_unaffected_mask                       (0x00000004)
#define  RINGFILTER_RFILTER_CTRL_rfilter_lsb2_tie0(data)                         (0x00000100&((data)<<8))
#define  RINGFILTER_RFILTER_CTRL_rfilter_en(data)                                (0x00000080&((data)<<7))
#define  RINGFILTER_RFILTER_CTRL_rfilter_ofs_rng_mode(data)                      (0x00000040&((data)<<6))
#define  RINGFILTER_RFILTER_CTRL_rfilter_jj_en(data)                             (0x00000020&((data)<<5))
#define  RINGFILTER_RFILTER_CTRL_rfilter_r_unaffected(data)                      (0x00000010&((data)<<4))
#define  RINGFILTER_RFILTER_CTRL_rfilter_g_unaffected(data)                      (0x00000008&((data)<<3))
#define  RINGFILTER_RFILTER_CTRL_rfilter_b_unaffected(data)                      (0x00000004&((data)<<2))
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_lsb2_tie0(data)                     ((0x00000100&(data))>>8)
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_en(data)                            ((0x00000080&(data))>>7)
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_ofs_rng_mode(data)                  ((0x00000040&(data))>>6)
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_jj_en(data)                         ((0x00000020&(data))>>5)
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_r_unaffected(data)                  ((0x00000010&(data))>>4)
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_g_unaffected(data)                  ((0x00000008&(data))>>3)
#define  RINGFILTER_RFILTER_CTRL_get_rfilter_b_unaffected(data)                  ((0x00000004&(data))>>2)

#define  RINGFILTER_RFILTER_THD                                                  0x18023584
#define  RINGFILTER_RFILTER_THD_reg_addr                                         "0xB8023584"
#define  RINGFILTER_RFILTER_THD_reg                                              0xB8023584
#define  RINGFILTER_RFILTER_THD_inst_addr                                        "0x0001"
#define  set_RINGFILTER_RFILTER_THD_reg(data)                                    (*((volatile unsigned int*)RINGFILTER_RFILTER_THD_reg)=data)
#define  get_RINGFILTER_RFILTER_THD_reg                                          (*((volatile unsigned int*)RINGFILTER_RFILTER_THD_reg))
#define  RINGFILTER_RFILTER_THD_rfilter_thd_rng_exp_shift                        (8)
#define  RINGFILTER_RFILTER_THD_rfilter_thd_shift                                (0)
#define  RINGFILTER_RFILTER_THD_rfilter_thd_rng_exp_mask                         (0x00000700)
#define  RINGFILTER_RFILTER_THD_rfilter_thd_mask                                 (0x000000FF)
#define  RINGFILTER_RFILTER_THD_rfilter_thd_rng_exp(data)                        (0x00000700&((data)<<8))
#define  RINGFILTER_RFILTER_THD_rfilter_thd(data)                                (0x000000FF&(data))
#define  RINGFILTER_RFILTER_THD_get_rfilter_thd_rng_exp(data)                    ((0x00000700&(data))>>8)
#define  RINGFILTER_RFILTER_THD_get_rfilter_thd(data)                            (0x000000FF&(data))

#define  RINGFILTER_RFILTER_OFS_COEF                                             0x18023588
#define  RINGFILTER_RFILTER_OFS_COEF_reg_addr                                    "0xB8023588"
#define  RINGFILTER_RFILTER_OFS_COEF_reg                                         0xB8023588
#define  RINGFILTER_RFILTER_OFS_COEF_inst_addr                                   "0x0002"
#define  set_RINGFILTER_RFILTER_OFS_COEF_reg(data)                               (*((volatile unsigned int*)RINGFILTER_RFILTER_OFS_COEF_reg)=data)
#define  get_RINGFILTER_RFILTER_OFS_COEF_reg                                     (*((volatile unsigned int*)RINGFILTER_RFILTER_OFS_COEF_reg))
#define  RINGFILTER_RFILTER_OFS_COEF_rfilter_ofs_rng_exp_shift                   (8)
#define  RINGFILTER_RFILTER_OFS_COEF_rfilter_ofs_coef_shift                      (0)
#define  RINGFILTER_RFILTER_OFS_COEF_rfilter_ofs_rng_exp_mask                    (0x00000700)
#define  RINGFILTER_RFILTER_OFS_COEF_rfilter_ofs_coef_mask                       (0x0000001F)
#define  RINGFILTER_RFILTER_OFS_COEF_rfilter_ofs_rng_exp(data)                   (0x00000700&((data)<<8))
#define  RINGFILTER_RFILTER_OFS_COEF_rfilter_ofs_coef(data)                      (0x0000001F&(data))
#define  RINGFILTER_RFILTER_OFS_COEF_get_rfilter_ofs_rng_exp(data)               ((0x00000700&(data))>>8)
#define  RINGFILTER_RFILTER_OFS_COEF_get_rfilter_ofs_coef(data)                  (0x0000001F&(data))

#define  RINGFILTER_RFILTER_DIFF_THD                                             0x1802358C
#define  RINGFILTER_RFILTER_DIFF_THD_reg_addr                                    "0xB802358C"
#define  RINGFILTER_RFILTER_DIFF_THD_reg                                         0xB802358C
#define  RINGFILTER_RFILTER_DIFF_THD_inst_addr                                   "0x0003"
#define  set_RINGFILTER_RFILTER_DIFF_THD_reg(data)                               (*((volatile unsigned int*)RINGFILTER_RFILTER_DIFF_THD_reg)=data)
#define  get_RINGFILTER_RFILTER_DIFF_THD_reg                                     (*((volatile unsigned int*)RINGFILTER_RFILTER_DIFF_THD_reg))
#define  RINGFILTER_RFILTER_DIFF_THD_rfilter_diff_thd_lb_shift                   (8)
#define  RINGFILTER_RFILTER_DIFF_THD_rfilter_diff_thd_ub_shift                   (0)
#define  RINGFILTER_RFILTER_DIFF_THD_rfilter_diff_thd_lb_mask                    (0x00000F00)
#define  RINGFILTER_RFILTER_DIFF_THD_rfilter_diff_thd_ub_mask                    (0x00000003)
#define  RINGFILTER_RFILTER_DIFF_THD_rfilter_diff_thd_lb(data)                   (0x00000F00&((data)<<8))
#define  RINGFILTER_RFILTER_DIFF_THD_rfilter_diff_thd_ub(data)                   (0x00000003&(data))
#define  RINGFILTER_RFILTER_DIFF_THD_get_rfilter_diff_thd_lb(data)               ((0x00000F00&(data))>>8)
#define  RINGFILTER_RFILTER_DIFF_THD_get_rfilter_diff_thd_ub(data)               (0x00000003&(data))

#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL                                     0x18023590
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg_addr                            "0xB8023590"
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg                                 0xB8023590
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_inst_addr                           "0x0004"
#define  set_RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg(data)                       (*((volatile unsigned int*)RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg)=data)
#define  get_RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg                             (*((volatile unsigned int*)RINGFILTER_RFILTER_FACTOR_TEST_CTRL_reg))
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_diff_fac_2px_set_shift      (3)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_thd_fac_set_shift           (2)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_ofs_fac_set_shift           (1)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_diff_fac_set_shift          (0)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_diff_fac_2px_set_mask       (0x00000008)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_thd_fac_set_mask            (0x00000004)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_ofs_fac_set_mask            (0x00000002)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_diff_fac_set_mask           (0x00000001)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_diff_fac_2px_set(data)      (0x00000008&((data)<<3))
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_thd_fac_set(data)           (0x00000004&((data)<<2))
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_ofs_fac_set(data)           (0x00000002&((data)<<1))
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_rfilter_diff_fac_set(data)          (0x00000001&(data))
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_get_rfilter_diff_fac_2px_set(data)  ((0x00000008&(data))>>3)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_get_rfilter_thd_fac_set(data)       ((0x00000004&(data))>>2)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_get_rfilter_ofs_fac_set(data)       ((0x00000002&(data))>>1)
#define  RINGFILTER_RFILTER_FACTOR_TEST_CTRL_get_rfilter_diff_fac_set(data)      (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RINGFILTER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  rfilter_lsb2_tie0:1;
        RBus_UInt32  rfilter_en:1;
        RBus_UInt32  rfilter_ofs_rng_mode:1;
        RBus_UInt32  rfilter_jj_en:1;
        RBus_UInt32  rfilter_r_unaffected:1;
        RBus_UInt32  rfilter_g_unaffected:1;
        RBus_UInt32  rfilter_b_unaffected:1;
        RBus_UInt32  res2:2;
    };
}ringfilter_rfilter_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  rfilter_thd_rng_exp:3;
        RBus_UInt32  rfilter_thd:8;
    };
}ringfilter_rfilter_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  rfilter_ofs_rng_exp:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  rfilter_ofs_coef:5;
    };
}ringfilter_rfilter_ofs_coef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  rfilter_diff_thd_lb:4;
        RBus_UInt32  res2:6;
        RBus_UInt32  rfilter_diff_thd_ub:2;
    };
}ringfilter_rfilter_diff_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rfilter_diff_fac_2px_set:1;
        RBus_UInt32  rfilter_thd_fac_set:1;
        RBus_UInt32  rfilter_ofs_fac_set:1;
        RBus_UInt32  rfilter_diff_fac_set:1;
    };
}ringfilter_rfilter_factor_test_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======RINGFILTER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  rfilter_b_unaffected:1;
        RBus_UInt32  rfilter_g_unaffected:1;
        RBus_UInt32  rfilter_r_unaffected:1;
        RBus_UInt32  rfilter_jj_en:1;
        RBus_UInt32  rfilter_ofs_rng_mode:1;
        RBus_UInt32  rfilter_en:1;
        RBus_UInt32  rfilter_lsb2_tie0:1;
        RBus_UInt32  res2:23;
    };
}ringfilter_rfilter_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfilter_thd:8;
        RBus_UInt32  rfilter_thd_rng_exp:3;
        RBus_UInt32  res1:21;
    };
}ringfilter_rfilter_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfilter_ofs_coef:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  rfilter_ofs_rng_exp:3;
        RBus_UInt32  res2:21;
    };
}ringfilter_rfilter_ofs_coef_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfilter_diff_thd_ub:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  rfilter_diff_thd_lb:4;
        RBus_UInt32  res2:20;
    };
}ringfilter_rfilter_diff_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rfilter_diff_fac_set:1;
        RBus_UInt32  rfilter_ofs_fac_set:1;
        RBus_UInt32  rfilter_thd_fac_set:1;
        RBus_UInt32  rfilter_diff_fac_2px_set:1;
        RBus_UInt32  res1:28;
    };
}ringfilter_rfilter_factor_test_ctrl_RBUS;




#endif 


#endif 
