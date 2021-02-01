/**
* @file rbusDFEReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/7/24
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DFE_REG_H_
#define _RBUS_DFE_REG_H_

#include "rbusTypes.h"



//  DFE Register Address



#define  DFE_REG_DFE_EN_L0_VADDR                            	(0xb800dc00)
#define  DFE_REG_DFE_INIT0_L0_VADDR                         	(0xb800dc04)
#define  DFE_REG_DFE_INIT1_L0_VADDR                         	(0xb800dc08)
#define  DFE_REG_DFE_EN_L1_VADDR                            	(0xb800dc10)
#define  DFE_REG_DFE_INIT0_L1_VADDR                         	(0xb800dc14)
#define  DFE_REG_DFE_INIT1_L1_VADDR                         	(0xb800dc18)
#define  DFE_REG_DFE_EN_L2_VADDR                            	(0xb800dc20)
#define  DFE_REG_DFE_INIT0_L2_VADDR                         	(0xb800dc24)
#define  DFE_REG_DFE_INIT1_L2_VADDR                         	(0xb800dc28)
#define  DFE_REG_DFE_MODE_VADDR                             	(0xb800dc30)
#define  DFE_REG_DFE_GAIN_VADDR                             	(0xb800dc34)
#define  DFE_REG_DFE_LIMIT0_VADDR                           	(0xb800dc38)
#define  DFE_REG_DFE_LIMIT1_VADDR                           	(0xb800dc3c)
#define  DFE_REG_DFE_LIMIT2_VADDR                           	(0xb800dc40)
#define  DFE_REG_DFE_READBACK_VADDR                         	(0xb800dc44)
#define  DFE_REG_DFE_FLAG_VADDR                             	(0xb800dc48)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DFE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_inv_lane0:1;
        RBus_UInt32  timer_ctrl_en_lane0:1;
        RBus_UInt32  reduce_adapt_gain_lane0:2;
        RBus_UInt32  rl_det_en_lane0:1;
        RBus_UInt32  rl_det_mode_lane0:1;
        RBus_UInt32  rl_threshold_lane0:2;
        RBus_UInt32  dfe_adapt_en_lane0:8;
        RBus_UInt32  le_min_lane0:4;
        RBus_UInt32  le_rvs_lane0:2;
        RBus_UInt32  le_init_lane0:4;
        RBus_UInt32  tap4_init_lane0:6;
    };
}dfe_reg_dfe_en_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_init_lane0:6;
        RBus_UInt32  tap2_init_lane0:6;
        RBus_UInt32  tap1_init_lane0:6;
        RBus_UInt32  tap0_init_lane0:5;
        RBus_UInt32  servo_init_lane0:5;
        RBus_UInt32  vth_init_lane0:4;
    };
}dfe_reg_dfe_init0_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_in_init_lane0:8;
        RBus_UInt32  dfe_en_buffer_lane0:2;
        RBus_UInt32  dfe_en_buffer_manual_lane0:1;
        RBus_UInt32  dfe_set_cs_lane0:2;
        RBus_UInt32  dfe_set_cs_manual_lane0:1;
        RBus_UInt32  init1_rev_lane0_17:1;
        RBus_UInt32  init1_rev_lane0_16:1;
        RBus_UInt32  init1_rev_lane0_15:1;
        RBus_UInt32  init1_rev_lane0_14:1;
        RBus_UInt32  init1_rev_lane0_13_0:14;
    };
}dfe_reg_dfe_init1_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_inv_lane1:1;
        RBus_UInt32  timer_ctrl_en_lane1:1;
        RBus_UInt32  reduce_adapt_gain_lane1:2;
        RBus_UInt32  rl_det_en_lane1:1;
        RBus_UInt32  rl_det_mode_lane1:1;
        RBus_UInt32  rl_threshold_lane1:2;
        RBus_UInt32  dfe_adapt_en_lane1:8;
        RBus_UInt32  le_min_lane1:4;
        RBus_UInt32  le_rvs_lane1:2;
        RBus_UInt32  le_init_lane1:4;
        RBus_UInt32  tap4_init_lane1:6;
    };
}dfe_reg_dfe_en_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_init_lane1:6;
        RBus_UInt32  tap2_init_lane1:6;
        RBus_UInt32  tap1_init_lane1:6;
        RBus_UInt32  tap0_init_lane1:5;
        RBus_UInt32  servo_init_lane1:5;
        RBus_UInt32  vth_init_lane1:4;
    };
}dfe_reg_dfe_init0_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_in_init_lane1:8;
        RBus_UInt32  dfe_en_buffer_lane1:2;
        RBus_UInt32  dfe_en_buffer_manual_lane1:1;
        RBus_UInt32  dfe_set_cs_lane1:2;
        RBus_UInt32  dfe_set_cs_manual_lane1:1;
        RBus_UInt32  init1_rev_lane1_17:1;
        RBus_UInt32  init1_rev_lane1_16:1;
        RBus_UInt32  init1_rev_lane1_15:1;
        RBus_UInt32  init1_rev_lane1_14:1;
        RBus_UInt32  init1_rev_lane1_13_0:14;
    };
}dfe_reg_dfe_init1_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_inv_lane2:1;
        RBus_UInt32  timer_ctrl_en_lane2:1;
        RBus_UInt32  reduce_adapt_gain_lane2:2;
        RBus_UInt32  rl_det_en_lane2:1;
        RBus_UInt32  rl_det_mode_lane2:1;
        RBus_UInt32  rl_threshold_lane2:2;
        RBus_UInt32  dfe_adapt_en_lane2:8;
        RBus_UInt32  le_min_lane2:4;
        RBus_UInt32  le_rvs_lane2:2;
        RBus_UInt32  le_init_lane2:4;
        RBus_UInt32  tap4_init_lane2:6;
    };
}dfe_reg_dfe_en_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap3_init_lane2:6;
        RBus_UInt32  tap2_init_lane2:6;
        RBus_UInt32  tap1_init_lane2:6;
        RBus_UInt32  tap0_init_lane2:5;
        RBus_UInt32  servo_init_lane2:5;
        RBus_UInt32  vth_init_lane2:4;
    };
}dfe_reg_dfe_init0_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_in_init_lane2:8;
        RBus_UInt32  dfe_en_buffer_lane2:2;
        RBus_UInt32  dfe_en_buffer_manual_lane2:1;
        RBus_UInt32  dfe_set_cs_lane2:2;
        RBus_UInt32  dfe_set_cs_manual_lane2:1;
        RBus_UInt32  init1_rev_lane2_17:1;
        RBus_UInt32  init1_rev_lane2_16:1;
        RBus_UInt32  init1_rev_lane2_15:1;
        RBus_UInt32  init1_rev_lane2_14:1;
        RBus_UInt32  init1_rev_lane2_13_0:14;
    };
}dfe_reg_dfe_init1_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_mode:2;
        RBus_UInt32  edge_det_mode:1;
        RBus_UInt32  transition_only:1;
        RBus_UInt32  le_auto_reload:1;
        RBus_UInt32  tap1_delay:3;
        RBus_UInt32  tap24_delay:3;
        RBus_UInt32  le_delay:3;
        RBus_UInt32  servo_delay:2;
        RBus_UInt32  gray_en:8;
        RBus_UInt32  dfe_adapt_rstb:4;
        RBus_UInt32  cs_mode:1;
        RBus_UInt32  tap0_notrans:1;
        RBus_UInt32  servo_notrans:1;
        RBus_UInt32  dfe_debug_extra_sel:1;
    };
}dfe_reg_dfe_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap0_gain:3;
        RBus_UInt32  tap1_gain:3;
        RBus_UInt32  tap2_gain:3;
        RBus_UInt32  tap3_gain:3;
        RBus_UInt32  tap4_gain:3;
        RBus_UInt32  servo_gain:3;
        RBus_UInt32  le_gain1:3;
        RBus_UInt32  le_gain2:3;
        RBus_UInt32  gain_rev:8;
    };
}dfe_reg_dfe_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap0_max:5;
        RBus_UInt32  tap1_min:6;
        RBus_UInt32  tap2_max:5;
        RBus_UInt32  tap2_min:5;
        RBus_UInt32  tap3_max:5;
        RBus_UInt32  tap3_min:5;
        RBus_UInt32  limit0_rev:1;
    };
}dfe_reg_dfe_limit0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_max:5;
        RBus_UInt32  tap4_min:5;
        RBus_UInt32  vth_min:2;
        RBus_UInt32  vth_dis_buf_range:2;
        RBus_UInt32  vth_threshold:3;
        RBus_UInt32  tap0_threshold:4;
        RBus_UInt32  limit1_rev:11;
    };
}dfe_reg_dfe_limit1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  servo_divisor:6;
        RBus_UInt32  tap_divisor:6;
        RBus_UInt32  vth_divisor:4;
        RBus_UInt32  limit2_rev:16;
    };
}dfe_reg_dfe_limit2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  record_limit_en:1;
        RBus_UInt32  limit_sel:7;
        RBus_UInt32  limit_data:8;
        RBus_UInt32  coef_sel:8;
        RBus_UInt32  coef_data:8;
    };
}dfe_reg_dfe_readback_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adapt_fail_flag:4;
        RBus_UInt32  adapt_swing_max_flag:4;
        RBus_UInt32  flag_rev1:12;
        RBus_UInt32  flag_rev2:12;
    };
}dfe_reg_dfe_flag_RBUS;

#else //apply LITTLE_ENDIAN

//======DFE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_init_lane0:6;
        RBus_UInt32  le_init_lane0:4;
        RBus_UInt32  le_rvs_lane0:2;
        RBus_UInt32  le_min_lane0:4;
        RBus_UInt32  dfe_adapt_en_lane0:8;
        RBus_UInt32  rl_threshold_lane0:2;
        RBus_UInt32  rl_det_mode_lane0:1;
        RBus_UInt32  rl_det_en_lane0:1;
        RBus_UInt32  reduce_adapt_gain_lane0:2;
        RBus_UInt32  timer_ctrl_en_lane0:1;
        RBus_UInt32  clk_inv_lane0:1;
    };
}dfe_reg_dfe_en_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vth_init_lane0:4;
        RBus_UInt32  servo_init_lane0:5;
        RBus_UInt32  tap0_init_lane0:5;
        RBus_UInt32  tap1_init_lane0:6;
        RBus_UInt32  tap2_init_lane0:6;
        RBus_UInt32  tap3_init_lane0:6;
    };
}dfe_reg_dfe_init0_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init1_rev_lane0_13_0:14;
        RBus_UInt32  init1_rev_lane0_14:1;
        RBus_UInt32  init1_rev_lane0_15:1;
        RBus_UInt32  init1_rev_lane0_16:1;
        RBus_UInt32  init1_rev_lane0_17:1;
        RBus_UInt32  dfe_set_cs_manual_lane0:1;
        RBus_UInt32  dfe_set_cs_lane0:2;
        RBus_UInt32  dfe_en_buffer_manual_lane0:1;
        RBus_UInt32  dfe_en_buffer_lane0:2;
        RBus_UInt32  load_in_init_lane0:8;
    };
}dfe_reg_dfe_init1_l0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_init_lane1:6;
        RBus_UInt32  le_init_lane1:4;
        RBus_UInt32  le_rvs_lane1:2;
        RBus_UInt32  le_min_lane1:4;
        RBus_UInt32  dfe_adapt_en_lane1:8;
        RBus_UInt32  rl_threshold_lane1:2;
        RBus_UInt32  rl_det_mode_lane1:1;
        RBus_UInt32  rl_det_en_lane1:1;
        RBus_UInt32  reduce_adapt_gain_lane1:2;
        RBus_UInt32  timer_ctrl_en_lane1:1;
        RBus_UInt32  clk_inv_lane1:1;
    };
}dfe_reg_dfe_en_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vth_init_lane1:4;
        RBus_UInt32  servo_init_lane1:5;
        RBus_UInt32  tap0_init_lane1:5;
        RBus_UInt32  tap1_init_lane1:6;
        RBus_UInt32  tap2_init_lane1:6;
        RBus_UInt32  tap3_init_lane1:6;
    };
}dfe_reg_dfe_init0_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init1_rev_lane1_13_0:14;
        RBus_UInt32  init1_rev_lane1_14:1;
        RBus_UInt32  init1_rev_lane1_15:1;
        RBus_UInt32  init1_rev_lane1_16:1;
        RBus_UInt32  init1_rev_lane1_17:1;
        RBus_UInt32  dfe_set_cs_manual_lane1:1;
        RBus_UInt32  dfe_set_cs_lane1:2;
        RBus_UInt32  dfe_en_buffer_manual_lane1:1;
        RBus_UInt32  dfe_en_buffer_lane1:2;
        RBus_UInt32  load_in_init_lane1:8;
    };
}dfe_reg_dfe_init1_l1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tap4_init_lane2:6;
        RBus_UInt32  le_init_lane2:4;
        RBus_UInt32  le_rvs_lane2:2;
        RBus_UInt32  le_min_lane2:4;
        RBus_UInt32  dfe_adapt_en_lane2:8;
        RBus_UInt32  rl_threshold_lane2:2;
        RBus_UInt32  rl_det_mode_lane2:1;
        RBus_UInt32  rl_det_en_lane2:1;
        RBus_UInt32  reduce_adapt_gain_lane2:2;
        RBus_UInt32  timer_ctrl_en_lane2:1;
        RBus_UInt32  clk_inv_lane2:1;
    };
}dfe_reg_dfe_en_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vth_init_lane2:4;
        RBus_UInt32  servo_init_lane2:5;
        RBus_UInt32  tap0_init_lane2:5;
        RBus_UInt32  tap1_init_lane2:6;
        RBus_UInt32  tap2_init_lane2:6;
        RBus_UInt32  tap3_init_lane2:6;
    };
}dfe_reg_dfe_init0_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  init1_rev_lane2_13_0:14;
        RBus_UInt32  init1_rev_lane2_14:1;
        RBus_UInt32  init1_rev_lane2_15:1;
        RBus_UInt32  init1_rev_lane2_16:1;
        RBus_UInt32  init1_rev_lane2_17:1;
        RBus_UInt32  dfe_set_cs_manual_lane2:1;
        RBus_UInt32  dfe_set_cs_lane2:2;
        RBus_UInt32  dfe_en_buffer_manual_lane2:1;
        RBus_UInt32  dfe_en_buffer_lane2:2;
        RBus_UInt32  load_in_init_lane2:8;
    };
}dfe_reg_dfe_init1_l2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dfe_debug_extra_sel:1;
        RBus_UInt32  servo_notrans:1;
        RBus_UInt32  tap0_notrans:1;
        RBus_UInt32  cs_mode:1;
        RBus_UInt32  dfe_adapt_rstb:4;
        RBus_UInt32  gray_en:8;
        RBus_UInt32  servo_delay:2;
        RBus_UInt32  le_delay:3;
        RBus_UInt32  tap24_delay:3;
        RBus_UInt32  tap1_delay:3;
        RBus_UInt32  le_auto_reload:1;
        RBus_UInt32  transition_only:1;
        RBus_UInt32  edge_det_mode:1;
        RBus_UInt32  adapt_mode:2;
    };
}dfe_reg_dfe_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_rev:8;
        RBus_UInt32  le_gain2:3;
        RBus_UInt32  le_gain1:3;
        RBus_UInt32  servo_gain:3;
        RBus_UInt32  tap4_gain:3;
        RBus_UInt32  tap3_gain:3;
        RBus_UInt32  tap2_gain:3;
        RBus_UInt32  tap1_gain:3;
        RBus_UInt32  tap0_gain:3;
    };
}dfe_reg_dfe_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit0_rev:1;
        RBus_UInt32  tap3_min:5;
        RBus_UInt32  tap3_max:5;
        RBus_UInt32  tap2_min:5;
        RBus_UInt32  tap2_max:5;
        RBus_UInt32  tap1_min:6;
        RBus_UInt32  tap0_max:5;
    };
}dfe_reg_dfe_limit0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit1_rev:11;
        RBus_UInt32  tap0_threshold:4;
        RBus_UInt32  vth_threshold:3;
        RBus_UInt32  vth_dis_buf_range:2;
        RBus_UInt32  vth_min:2;
        RBus_UInt32  tap4_min:5;
        RBus_UInt32  tap4_max:5;
    };
}dfe_reg_dfe_limit1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit2_rev:16;
        RBus_UInt32  vth_divisor:4;
        RBus_UInt32  tap_divisor:6;
        RBus_UInt32  servo_divisor:6;
    };
}dfe_reg_dfe_limit2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_data:8;
        RBus_UInt32  coef_sel:8;
        RBus_UInt32  limit_data:8;
        RBus_UInt32  limit_sel:7;
        RBus_UInt32  record_limit_en:1;
    };
}dfe_reg_dfe_readback_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag_rev2:12;
        RBus_UInt32  flag_rev1:12;
        RBus_UInt32  adapt_swing_max_flag:4;
        RBus_UInt32  adapt_fail_flag:4;
    };
}dfe_reg_dfe_flag_RBUS;




#endif 

#define  REG_DFE_EN_L0                                                          0x1800DC00
#define  REG_DFE_EN_L0_reg_addr                                                 "0xB800DC00"
#define  REG_DFE_EN_L0_reg                                                      0xB800DC00
#define  REG_DFE_EN_L0_inst_addr                                                "0x0000"
#define  REG_DFE_EN_L0_inst                                                     0x0000
#define REG_DFE_EN_L0_clk_inv_lane0_shift                             (31)
#define REG_DFE_EN_L0_timer_ctrl_en_lane0_shift                       (30)
#define REG_DFE_EN_L0_reduce_adapt_gain_lane0_shift                   (28)
#define REG_DFE_EN_L0_rl_det_en_lane0_shift                           (27)
#define REG_DFE_EN_L0_rl_det_mode_lane0_shift                         (26)
#define REG_DFE_EN_L0_rl_threshold_lane0_shift                        (24)
#define REG_DFE_EN_L0_dfe_adapt_en_lane0_shift                        (16)
#define REG_DFE_EN_L0_le_min_lane0_shift                              (12)
#define REG_DFE_EN_L0_le_rvs_lane0_shift                              (10)
#define REG_DFE_EN_L0_le_init_lane0_shift                             (6)
#define REG_DFE_EN_L0_tap4_init_lane0_shift                           (0)
#define REG_DFE_EN_L0_clk_inv_lane0_mask                              (0x80000000)
#define REG_DFE_EN_L0_timer_ctrl_en_lane0_mask                        (0x40000000)
#define REG_DFE_EN_L0_reduce_adapt_gain_lane0_mask                    (0x30000000)
#define REG_DFE_EN_L0_rl_det_en_lane0_mask                            (0x08000000)
#define REG_DFE_EN_L0_rl_det_mode_lane0_mask                          (0x04000000)
#define REG_DFE_EN_L0_rl_threshold_lane0_mask                         (0x03000000)
#define REG_DFE_EN_L0_dfe_adapt_en_lane0_mask                         (0x00FF0000)
#define REG_DFE_EN_L0_le_min_lane0_mask                               (0x0000F000)
#define REG_DFE_EN_L0_le_rvs_lane0_mask                               (0x00000C00)
#define REG_DFE_EN_L0_le_init_lane0_mask                              (0x000003C0)
#define REG_DFE_EN_L0_tap4_init_lane0_mask                            (0x0000003F)
#define REG_DFE_EN_L0_clk_inv_lane0(data)                             (0x80000000&((data)<<31))
#define REG_DFE_EN_L0_timer_ctrl_en_lane0(data)                       (0x40000000&((data)<<30))
#define REG_DFE_EN_L0_reduce_adapt_gain_lane0(data)                   (0x30000000&((data)<<28))
#define REG_DFE_EN_L0_rl_det_en_lane0(data)                           (0x08000000&((data)<<27))
#define REG_DFE_EN_L0_rl_det_mode_lane0(data)                         (0x04000000&((data)<<26))
#define REG_DFE_EN_L0_rl_threshold_lane0(data)                        (0x03000000&((data)<<24))
#define REG_DFE_EN_L0_dfe_adapt_en_lane0(data)                        (0x00FF0000&((data)<<16))
#define REG_DFE_EN_L0_le_min_lane0(data)                              (0x0000F000&((data)<<12))
#define REG_DFE_EN_L0_le_rvs_lane0(data)                              (0x00000C00&((data)<<10))
#define REG_DFE_EN_L0_le_init_lane0(data)                             (0x000003C0&((data)<<6))
#define REG_DFE_EN_L0_tap4_init_lane0(data)                           (0x0000003F&(data))
#define REG_DFE_EN_L0_get_clk_inv_lane0(data)                         ((0x80000000&(data))>>31)
#define REG_DFE_EN_L0_get_timer_ctrl_en_lane0(data)                   ((0x40000000&(data))>>30)
#define REG_DFE_EN_L0_get_reduce_adapt_gain_lane0(data)               ((0x30000000&(data))>>28)
#define REG_DFE_EN_L0_get_rl_det_en_lane0(data)                       ((0x08000000&(data))>>27)
#define REG_DFE_EN_L0_get_rl_det_mode_lane0(data)                     ((0x04000000&(data))>>26)
#define REG_DFE_EN_L0_get_rl_threshold_lane0(data)                    ((0x03000000&(data))>>24)
#define REG_DFE_EN_L0_get_dfe_adapt_en_lane0(data)                    ((0x00FF0000&(data))>>16)
#define REG_DFE_EN_L0_get_le_min_lane0(data)                          ((0x0000F000&(data))>>12)
#define REG_DFE_EN_L0_get_le_rvs_lane0(data)                          ((0x00000C00&(data))>>10)
#define REG_DFE_EN_L0_get_le_init_lane0(data)                         ((0x000003C0&(data))>>6)
#define REG_DFE_EN_L0_get_tap4_init_lane0(data)                       (0x0000003F&(data))
#define REG_dfe_adapt_en_lane0_TAP0                                         _BIT16
#define REG_dfe_adapt_en_lane0_TAP1                                         _BIT17
#define REG_dfe_adapt_en_lane0_TAP2                                         _BIT18
#define REG_dfe_adapt_en_lane0_TAP3                                         _BIT19
#define REG_dfe_adapt_en_lane0_TAP4                                         _BIT20
#define REG_dfe_adapt_en_lane0_SERVO                                       _BIT21
#define REG_dfe_adapt_en_lane0_Vth                                            _BIT22
#define REG_dfe_adapt_en_lane0_LE                                              _BIT23


#define  REG_DFE_INIT0_L0                                                       0x1800DC04
#define  REG_DFE_INIT0_L0_reg_addr                                              "0xB800DC04"
#define  REG_DFE_INIT0_L0_reg                                                   0xB800DC04
#define  REG_DFE_INIT0_L0_inst_addr                                             "0x0001"
#define  REG_DFE_INIT0_L0_inst                                                  0x0001
#define REG_DFE_INIT0_L0_tap3_init_lane0_shift                        (26)
#define REG_DFE_INIT0_L0_tap2_init_lane0_shift                        (20)
#define REG_DFE_INIT0_L0_tap1_init_lane0_shift                        (14)
#define REG_DFE_INIT0_L0_tap0_init_lane0_shift                        (9)
#define REG_DFE_INIT0_L0_servo_init_lane0_shift                       (4)
#define REG_DFE_INIT0_L0_vth_init_lane0_shift                         (0)
#define REG_DFE_INIT0_L0_tap3_init_lane0_mask                         (0xFC000000)
#define REG_DFE_INIT0_L0_tap2_init_lane0_mask                         (0x03F00000)
#define REG_DFE_INIT0_L0_tap1_init_lane0_mask                         (0x000FC000)
#define REG_DFE_INIT0_L0_tap0_init_lane0_mask                         (0x00003E00)
#define REG_DFE_INIT0_L0_servo_init_lane0_mask                        (0x000001F0)
#define REG_DFE_INIT0_L0_vth_init_lane0_mask                          (0x0000000F)
#define REG_DFE_INIT0_L0_tap3_init_lane0(data)                        (0xFC000000&((data)<<26))
#define REG_DFE_INIT0_L0_tap2_init_lane0(data)                        (0x03F00000&((data)<<20))
#define REG_DFE_INIT0_L0_tap1_init_lane0(data)                        (0x000FC000&((data)<<14))
#define REG_DFE_INIT0_L0_tap0_init_lane0(data)                        (0x00003E00&((data)<<9))
#define REG_DFE_INIT0_L0_servo_init_lane0(data)                       (0x000001F0&((data)<<4))
#define REG_DFE_INIT0_L0_vth_init_lane0(data)                         (0x0000000F&(data))
#define REG_DFE_INIT0_L0_get_tap3_init_lane0(data)                    ((0xFC000000&(data))>>26)
#define REG_DFE_INIT0_L0_get_tap2_init_lane0(data)                    ((0x03F00000&(data))>>20)
#define REG_DFE_INIT0_L0_get_tap1_init_lane0(data)                    ((0x000FC000&(data))>>14)
#define REG_DFE_INIT0_L0_get_tap0_init_lane0(data)                    ((0x00003E00&(data))>>9)
#define REG_DFE_INIT0_L0_get_servo_init_lane0(data)                   ((0x000001F0&(data))>>4)
#define REG_DFE_INIT0_L0_get_vth_init_lane0(data)                     (0x0000000F&(data))

#define  REG_DFE_INIT1_L0                                                       0x1800DC08
#define  REG_DFE_INIT1_L0_reg_addr                                              "0xB800DC08"
#define  REG_DFE_INIT1_L0_reg                                                   0xB800DC08
#define  REG_DFE_INIT1_L0_inst_addr                                             "0x0002"
#define  REG_DFE_INIT1_L0_inst                                                  0x0002
#define REG_DFE_INIT1_L0_load_in_init_lane0_shift                     (24)
#define REG_DFE_INIT1_L0_dfe_en_buffer_lane0_shift                    (22)
#define REG_DFE_INIT1_L0_dfe_en_buffer_manual_lane0_shift             (21)
#define REG_DFE_INIT1_L0_dfe_set_cs_lane0_shift                       (19)
#define REG_DFE_INIT1_L0_dfe_set_cs_manual_lane0_shift                (18)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_17_shift                              (17)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_16_shift                              (16)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_15_shift                              (15)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_14_shift                              (14)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_13_0_shift                            (0)
#define REG_DFE_INIT1_L0_load_in_init_lane0_mask                      (0xFF000000)
#define REG_DFE_INIT1_L0_dfe_en_buffer_lane0_mask                     (0x00C00000)
#define REG_DFE_INIT1_L0_dfe_en_buffer_manual_lane0_mask              (0x00200000)
#define REG_DFE_INIT1_L0_dfe_set_cs_lane0_mask                        (0x00180000)
#define REG_DFE_INIT1_L0_dfe_set_cs_manual_lane0_mask                 (0x00040000)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_17_mask                               (0x00020000)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_16_mask                               (0x00010000)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_15_mask                               (0x00008000)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_14_mask                               (0x00004000)
#define  REG_DFE_INIT1_L0_init1_rev_lane0_13_0_mask                             (0x00003FFF)
#define REG_DFE_INIT1_L0_load_in_init_lane0(data)                     (0xFF000000&((data)<<24))
#define REG_DFE_INIT1_L0_dfe_en_buffer_lane0(data)                    (0x00C00000&((data)<<22))
#define REG_DFE_INIT1_L0_dfe_en_buffer_manual_lane0(data)             (0x00200000&((data)<<21))
#define REG_DFE_INIT1_L0_dfe_set_cs_lane0(data)                       (0x00180000&((data)<<19))
#define REG_DFE_INIT1_L0_dfe_set_cs_manual_lane0(data)                (0x00040000&((data)<<18))
#define  REG_DFE_INIT1_L0_init1_rev_lane0_17(data)                              (0x00020000&((data)<<17))
#define  REG_DFE_INIT1_L0_init1_rev_lane0_16(data)                              (0x00010000&((data)<<16))
#define  REG_DFE_INIT1_L0_init1_rev_lane0_15(data)                              (0x00008000&((data)<<15))
#define  REG_DFE_INIT1_L0_init1_rev_lane0_14(data)                              (0x00004000&((data)<<14))
#define  REG_DFE_INIT1_L0_init1_rev_lane0_13_0(data)                            (0x00003FFF&(data))
#define REG_DFE_INIT1_L0_get_load_in_init_lane0(data)                 ((0xFF000000&(data))>>24)
#define REG_DFE_INIT1_L0_get_dfe_en_buffer_lane0(data)                ((0x00C00000&(data))>>22)
#define REG_DFE_INIT1_L0_get_dfe_en_buffer_manual_lane0(data)         ((0x00200000&(data))>>21)
#define REG_DFE_INIT1_L0_get_dfe_set_cs_lane0(data)                   ((0x00180000&(data))>>19)
#define REG_DFE_INIT1_L0_get_dfe_set_cs_manual_lane0(data)            ((0x00040000&(data))>>18)
#define  REG_DFE_INIT1_L0_get_init1_rev_lane0_17(data)                          ((0x00020000&(data))>>17)
#define  REG_DFE_INIT1_L0_get_init1_rev_lane0_16(data)                          ((0x00010000&(data))>>16)
#define  REG_DFE_INIT1_L0_get_init1_rev_lane0_15(data)                          ((0x00008000&(data))>>15)
#define  REG_DFE_INIT1_L0_get_init1_rev_lane0_14(data)                          ((0x00004000&(data))>>14)
#define  REG_DFE_INIT1_L0_get_init1_rev_lane0_13_0(data)                        (0x00003FFF&(data))
#define load_in_init_lane0_LE		(_BIT31)
#define load_in_init_lane0_vth	(_BIT30)
#define load_in_init_lane0_tap1	(_BIT25)
#define load_in_init_lane0_tap0	(_BIT24)

#define  REG_DFE_EN_L1                                                          0x1800DC10
#define  REG_DFE_EN_L1_reg_addr                                                 "0xB800DC10"
#define  REG_DFE_EN_L1_reg                                                      0xB800DC10
#define  REG_DFE_EN_L1_inst_addr                                                "0x0003"
#define  REG_DFE_EN_L1_inst                                                     0x0003
#define REG_DFE_EN_L1_clk_inv_lane1_shift                             (31)
#define REG_DFE_EN_L1_timer_ctrl_en_lane1_shift                       (30)
#define REG_DFE_EN_L1_reduce_adapt_gain_lane1_shift                   (28)
#define REG_DFE_EN_L1_rl_det_en_lane1_shift                           (27)
#define REG_DFE_EN_L1_rl_det_mode_lane1_shift                         (26)
#define REG_DFE_EN_L1_rl_threshold_lane1_shift                        (24)
#define REG_DFE_EN_L1_dfe_adapt_en_lane1_shift                        (16)
#define REG_DFE_EN_L1_le_min_lane1_shift                              (12)
#define REG_DFE_EN_L1_le_rvs_lane1_shift                              (10)
#define REG_DFE_EN_L1_le_init_lane1_shift                             (6)
#define REG_DFE_EN_L1_tap4_init_lane1_shift                           (0)
#define REG_DFE_EN_L1_clk_inv_lane1_mask                              (0x80000000)
#define REG_DFE_EN_L1_timer_ctrl_en_lane1_mask                        (0x40000000)
#define REG_DFE_EN_L1_reduce_adapt_gain_lane1_mask                    (0x30000000)
#define REG_DFE_EN_L1_rl_det_en_lane1_mask                            (0x08000000)
#define REG_DFE_EN_L1_rl_det_mode_lane1_mask                          (0x04000000)
#define REG_DFE_EN_L1_rl_threshold_lane1_mask                         (0x03000000)
#define REG_DFE_EN_L1_dfe_adapt_en_lane1_mask                         (0x00FF0000)
#define REG_DFE_EN_L1_le_min_lane1_mask                               (0x0000F000)
#define REG_DFE_EN_L1_le_rvs_lane1_mask                               (0x00000C00)
#define REG_DFE_EN_L1_le_init_lane1_mask                              (0x000003C0)
#define REG_DFE_EN_L1_tap4_init_lane1_mask                            (0x0000003F)
#define REG_DFE_EN_L1_clk_inv_lane1(data)                             (0x80000000&((data)<<31))
#define REG_DFE_EN_L1_timer_ctrl_en_lane1(data)                       (0x40000000&((data)<<30))
#define REG_DFE_EN_L1_reduce_adapt_gain_lane1(data)                   (0x30000000&((data)<<28))
#define REG_DFE_EN_L1_rl_det_en_lane1(data)                           (0x08000000&((data)<<27))
#define REG_DFE_EN_L1_rl_det_mode_lane1(data)                         (0x04000000&((data)<<26))
#define REG_DFE_EN_L1_rl_threshold_lane1(data)                        (0x03000000&((data)<<24))
#define REG_DFE_EN_L1_dfe_adapt_en_lane1(data)                        (0x00FF0000&((data)<<16))
#define REG_DFE_EN_L1_le_min_lane1(data)                              (0x0000F000&((data)<<12))
#define REG_DFE_EN_L1_le_rvs_lane1(data)                              (0x00000C00&((data)<<10))
#define REG_DFE_EN_L1_le_init_lane1(data)                             (0x000003C0&((data)<<6))
#define REG_DFE_EN_L1_tap4_init_lane1(data)                           (0x0000003F&(data))
#define REG_DFE_EN_L1_get_clk_inv_lane1(data)                         ((0x80000000&(data))>>31)
#define REG_DFE_EN_L1_get_timer_ctrl_en_lane1(data)                   ((0x40000000&(data))>>30)
#define REG_DFE_EN_L1_get_reduce_adapt_gain_lane1(data)               ((0x30000000&(data))>>28)
#define REG_DFE_EN_L1_get_rl_det_en_lane1(data)                       ((0x08000000&(data))>>27)
#define REG_DFE_EN_L1_get_rl_det_mode_lane1(data)                     ((0x04000000&(data))>>26)
#define REG_DFE_EN_L1_get_rl_threshold_lane1(data)                    ((0x03000000&(data))>>24)
#define REG_DFE_EN_L1_get_dfe_adapt_en_lane1(data)                    ((0x00FF0000&(data))>>16)
#define REG_DFE_EN_L1_get_le_min_lane1(data)                          ((0x0000F000&(data))>>12)
#define REG_DFE_EN_L1_get_le_rvs_lane1(data)                          ((0x00000C00&(data))>>10)
#define REG_DFE_EN_L1_get_le_init_lane1(data)                         ((0x000003C0&(data))>>6)
#define REG_DFE_EN_L1_get_tap4_init_lane1(data)                       (0x0000003F&(data))
#define REG_dfe_adapt_en_lane1_TAP0                                         _BIT16
#define REG_dfe_adapt_en_lane1_TAP1                                         _BIT17
#define REG_dfe_adapt_en_lane1_TAP2                                         _BIT18
#define REG_dfe_adapt_en_lane1_TAP3                                         _BIT19
#define REG_dfe_adapt_en_lane1_TAP4                                         _BIT20
#define REG_dfe_adapt_en_lane1_SERVO                                       _BIT21
#define REG_dfe_adapt_en_lane1_Vth                                            _BIT22
#define REG_dfe_adapt_en_lane1_LE                                              _BIT23

#define  REG_DFE_INIT0_L1                                                       0x1800DC14
#define  REG_DFE_INIT0_L1_reg_addr                                              "0xB800DC14"
#define  REG_DFE_INIT0_L1_reg                                                   0xB800DC14
#define  REG_DFE_INIT0_L1_inst_addr                                             "0x0004"
#define  REG_DFE_INIT0_L1_inst                                                  0x0004
#define REG_DFE_INIT0_L1_tap3_init_lane1_shift                        (26)
#define REG_DFE_INIT0_L1_tap2_init_lane1_shift                        (20)
#define REG_DFE_INIT0_L1_tap1_init_lane1_shift                        (14)
#define REG_DFE_INIT0_L1_tap0_init_lane1_shift                        (9)
#define REG_DFE_INIT0_L1_servo_init_lane1_shift                       (4)
#define REG_DFE_INIT0_L1_vth_init_lane1_shift                         (0)
#define REG_DFE_INIT0_L1_tap3_init_lane1_mask                         (0xFC000000)
#define REG_DFE_INIT0_L1_tap2_init_lane1_mask                         (0x03F00000)
#define REG_DFE_INIT0_L1_tap1_init_lane1_mask                         (0x000FC000)
#define REG_DFE_INIT0_L1_tap0_init_lane1_mask                         (0x00003E00)
#define REG_DFE_INIT0_L1_servo_init_lane1_mask                        (0x000001F0)
#define REG_DFE_INIT0_L1_vth_init_lane1_mask                          (0x0000000F)
#define REG_DFE_INIT0_L1_tap3_init_lane1(data)                        (0xFC000000&((data)<<26))
#define REG_DFE_INIT0_L1_tap2_init_lane1(data)                        (0x03F00000&((data)<<20))
#define REG_DFE_INIT0_L1_tap1_init_lane1(data)                        (0x000FC000&((data)<<14))
#define REG_DFE_INIT0_L1_tap0_init_lane1(data)                        (0x00003E00&((data)<<9))
#define REG_DFE_INIT0_L1_servo_init_lane1(data)                       (0x000001F0&((data)<<4))
#define REG_DFE_INIT0_L1_vth_init_lane1(data)                         (0x0000000F&(data))
#define REG_DFE_INIT0_L1_get_tap3_init_lane1(data)                    ((0xFC000000&(data))>>26)
#define REG_DFE_INIT0_L1_get_tap2_init_lane1(data)                    ((0x03F00000&(data))>>20)
#define REG_DFE_INIT0_L1_get_tap1_init_lane1(data)                    ((0x000FC000&(data))>>14)
#define REG_DFE_INIT0_L1_get_tap0_init_lane1(data)                    ((0x00003E00&(data))>>9)
#define REG_DFE_INIT0_L1_get_servo_init_lane1(data)                   ((0x000001F0&(data))>>4)
#define REG_DFE_INIT0_L1_get_vth_init_lane1(data)                     (0x0000000F&(data))

#define  REG_DFE_INIT1_L1                                                       0x1800DC18
#define  REG_DFE_INIT1_L1_reg_addr                                              "0xB800DC18"
#define  REG_DFE_INIT1_L1_reg                                                   0xB800DC18
#define  REG_DFE_INIT1_L1_inst_addr                                             "0x0005"
#define  REG_DFE_INIT1_L1_inst                                                  0x0005
#define REG_DFE_INIT1_L1_load_in_init_lane1_shift                     (24)
#define REG_DFE_INIT1_L1_dfe_en_buffer_lane1_shift                    (22)
#define REG_DFE_INIT1_L1_dfe_en_buffer_manual_lane1_shift             (21)
#define REG_DFE_INIT1_L1_dfe_set_cs_lane1_shift                       (19)
#define REG_DFE_INIT1_L1_dfe_set_cs_manual_lane1_shift                (18)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_17_shift                              (17)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_16_shift                              (16)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_15_shift                              (15)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_14_shift                              (14)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_13_0_shift                            (0)
#define REG_DFE_INIT1_L1_load_in_init_lane1_mask                      (0xFF000000)
#define REG_DFE_INIT1_L1_dfe_en_buffer_lane1_mask                     (0x00C00000)
#define REG_DFE_INIT1_L1_dfe_en_buffer_manual_lane1_mask              (0x00200000)
#define REG_DFE_INIT1_L1_dfe_set_cs_lane1_mask                        (0x00180000)
#define REG_DFE_INIT1_L1_dfe_set_cs_manual_lane1_mask                 (0x00040000)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_17_mask                               (0x00020000)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_16_mask                               (0x00010000)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_15_mask                               (0x00008000)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_14_mask                               (0x00004000)
#define  REG_DFE_INIT1_L1_init1_rev_lane1_13_0_mask                             (0x00003FFF)
#define REG_DFE_INIT1_L1_load_in_init_lane1(data)                     (0xFF000000&((data)<<24))
#define REG_DFE_INIT1_L1_dfe_en_buffer_lane1(data)                    (0x00C00000&((data)<<22))
#define REG_DFE_INIT1_L1_dfe_en_buffer_manual_lane1(data)             (0x00200000&((data)<<21))
#define REG_DFE_INIT1_L1_dfe_set_cs_lane1(data)                       (0x00180000&((data)<<19))
#define REG_DFE_INIT1_L1_dfe_set_cs_manual_lane1(data)                (0x00040000&((data)<<18))
#define  REG_DFE_INIT1_L1_init1_rev_lane1_17(data)                              (0x00020000&((data)<<17))
#define  REG_DFE_INIT1_L1_init1_rev_lane1_16(data)                              (0x00010000&((data)<<16))
#define  REG_DFE_INIT1_L1_init1_rev_lane1_15(data)                              (0x00008000&((data)<<15))
#define  REG_DFE_INIT1_L1_init1_rev_lane1_14(data)                              (0x00004000&((data)<<14))
#define  REG_DFE_INIT1_L1_init1_rev_lane1_13_0(data)                            (0x00003FFF&(data))
#define REG_DFE_INIT1_L1_get_load_in_init_lane1(data)                 ((0xFF000000&(data))>>24)
#define REG_DFE_INIT1_L1_get_dfe_en_buffer_lane1(data)                ((0x00C00000&(data))>>22)
#define REG_DFE_INIT1_L1_get_dfe_en_buffer_manual_lane1(data)         ((0x00200000&(data))>>21)
#define REG_DFE_INIT1_L1_get_dfe_set_cs_lane1(data)                   ((0x00180000&(data))>>19)
#define REG_DFE_INIT1_L1_get_dfe_set_cs_manual_lane1(data)            ((0x00040000&(data))>>18)
#define  REG_DFE_INIT1_L1_get_init1_rev_lane1_17(data)                          ((0x00020000&(data))>>17)
#define  REG_DFE_INIT1_L1_get_init1_rev_lane1_16(data)                          ((0x00010000&(data))>>16)
#define  REG_DFE_INIT1_L1_get_init1_rev_lane1_15(data)                          ((0x00008000&(data))>>15)
#define  REG_DFE_INIT1_L1_get_init1_rev_lane1_14(data)                          ((0x00004000&(data))>>14)
#define  REG_DFE_INIT1_L1_get_init1_rev_lane1_13_0(data)                        (0x00003FFF&(data))

#define  REG_DFE_EN_L2                                                          0x1800DC20
#define  REG_DFE_EN_L2_reg_addr                                                 "0xB800DC20"
#define  REG_DFE_EN_L2_reg                                                      0xB800DC20
#define  REG_DFE_EN_L2_inst_addr                                                "0x0006"
#define  REG_DFE_EN_L2_inst                                                     0x0006
#define REG_DFE_EN_L2_clk_inv_lane2_shift                             (31)
#define REG_DFE_EN_L2_timer_ctrl_en_lane2_shift                       (30)
#define REG_DFE_EN_L2_reduce_adapt_gain_lane2_shift                   (28)
#define REG_DFE_EN_L2_rl_det_en_lane2_shift                           (27)
#define REG_DFE_EN_L2_rl_det_mode_lane2_shift                         (26)
#define REG_DFE_EN_L2_rl_threshold_lane2_shift                        (24)
#define REG_DFE_EN_L2_dfe_adapt_en_lane2_shift                        (16)
#define REG_DFE_EN_L2_le_min_lane2_shift                              (12)
#define REG_DFE_EN_L2_le_rvs_lane2_shift                              (10)
#define REG_DFE_EN_L2_le_init_lane2_shift                             (6)
#define REG_DFE_EN_L2_tap4_init_lane2_shift                           (0)
#define REG_DFE_EN_L2_clk_inv_lane2_mask                              (0x80000000)
#define REG_DFE_EN_L2_timer_ctrl_en_lane2_mask                        (0x40000000)
#define REG_DFE_EN_L2_reduce_adapt_gain_lane2_mask                    (0x30000000)
#define REG_DFE_EN_L2_rl_det_en_lane2_mask                            (0x08000000)
#define REG_DFE_EN_L2_rl_det_mode_lane2_mask                          (0x04000000)
#define REG_DFE_EN_L2_rl_threshold_lane2_mask                         (0x03000000)
#define REG_DFE_EN_L2_dfe_adapt_en_lane2_mask                         (0x00FF0000)
#define REG_DFE_EN_L2_le_min_lane2_mask                               (0x0000F000)
#define REG_DFE_EN_L2_le_rvs_lane2_mask                               (0x00000C00)
#define REG_DFE_EN_L2_le_init_lane2_mask                              (0x000003C0)
#define REG_DFE_EN_L2_tap4_init_lane2_mask                            (0x0000003F)
#define REG_DFE_EN_L2_clk_inv_lane2(data)                             (0x80000000&((data)<<31))
#define REG_DFE_EN_L2_timer_ctrl_en_lane2(data)                       (0x40000000&((data)<<30))
#define REG_DFE_EN_L2_reduce_adapt_gain_lane2(data)                   (0x30000000&((data)<<28))
#define REG_DFE_EN_L2_rl_det_en_lane2(data)                           (0x08000000&((data)<<27))
#define REG_DFE_EN_L2_rl_det_mode_lane2(data)                         (0x04000000&((data)<<26))
#define REG_DFE_EN_L2_rl_threshold_lane2(data)                        (0x03000000&((data)<<24))
#define REG_DFE_EN_L2_dfe_adapt_en_lane2(data)                        (0x00FF0000&((data)<<16))
#define REG_DFE_EN_L2_le_min_lane2(data)                              (0x0000F000&((data)<<12))
#define REG_DFE_EN_L2_le_rvs_lane2(data)                              (0x00000C00&((data)<<10))
#define REG_DFE_EN_L2_le_init_lane2(data)                             (0x000003C0&((data)<<6))
#define REG_DFE_EN_L2_tap4_init_lane2(data)                           (0x0000003F&(data))
#define REG_DFE_EN_L2_get_clk_inv_lane2(data)                         ((0x80000000&(data))>>31)
#define REG_DFE_EN_L2_get_timer_ctrl_en_lane2(data)                   ((0x40000000&(data))>>30)
#define REG_DFE_EN_L2_get_reduce_adapt_gain_lane2(data)               ((0x30000000&(data))>>28)
#define REG_DFE_EN_L2_get_rl_det_en_lane2(data)                       ((0x08000000&(data))>>27)
#define REG_DFE_EN_L2_get_rl_det_mode_lane2(data)                     ((0x04000000&(data))>>26)
#define REG_DFE_EN_L2_get_rl_threshold_lane2(data)                    ((0x03000000&(data))>>24)
#define REG_DFE_EN_L2_get_dfe_adapt_en_lane2(data)                    ((0x00FF0000&(data))>>16)
#define REG_DFE_EN_L2_get_le_min_lane2(data)                          ((0x0000F000&(data))>>12)
#define REG_DFE_EN_L2_get_le_rvs_lane2(data)                          ((0x00000C00&(data))>>10)
#define REG_DFE_EN_L2_get_le_init_lane2(data)                         ((0x000003C0&(data))>>6)
#define REG_DFE_EN_L2_get_tap4_init_lane2(data)                       (0x0000003F&(data))
#define REG_dfe_adapt_en_lane2_TAP0                                         _BIT16
#define REG_dfe_adapt_en_lane2_TAP1                                         _BIT17
#define REG_dfe_adapt_en_lane2_TAP2                                         _BIT18
#define REG_dfe_adapt_en_lane2_TAP3                                         _BIT19
#define REG_dfe_adapt_en_lane2_TAP4                                         _BIT20
#define REG_dfe_adapt_en_lane2_SERVO                                       _BIT21
#define REG_dfe_adapt_en_lane2_Vth                                            _BIT22
#define REG_dfe_adapt_en_lane2_LE                                              _BIT23


#define  REG_DFE_INIT0_L2                                                       0x1800DC24
#define  REG_DFE_INIT0_L2_reg_addr                                              "0xB800DC24"
#define  REG_DFE_INIT0_L2_reg                                                   0xB800DC24
#define  REG_DFE_INIT0_L2_inst_addr                                             "0x0007"
#define  REG_DFE_INIT0_L2_inst                                                  0x0007
#define REG_DFE_INIT0_L2_tap3_init_lane2_shift                        (26)
#define REG_DFE_INIT0_L2_tap2_init_lane2_shift                        (20)
#define REG_DFE_INIT0_L2_tap1_init_lane2_shift                        (14)
#define REG_DFE_INIT0_L2_tap0_init_lane2_shift                        (9)
#define REG_DFE_INIT0_L2_servo_init_lane2_shift                       (4)
#define REG_DFE_INIT0_L2_vth_init_lane2_shift                         (0)
#define REG_DFE_INIT0_L2_tap3_init_lane2_mask                         (0xFC000000)
#define REG_DFE_INIT0_L2_tap2_init_lane2_mask                         (0x03F00000)
#define REG_DFE_INIT0_L2_tap1_init_lane2_mask                         (0x000FC000)
#define REG_DFE_INIT0_L2_tap0_init_lane2_mask                         (0x00003E00)
#define REG_DFE_INIT0_L2_servo_init_lane2_mask                        (0x000001F0)
#define REG_DFE_INIT0_L2_vth_init_lane2_mask                          (0x0000000F)
#define REG_DFE_INIT0_L2_tap3_init_lane2(data)                        (0xFC000000&((data)<<26))
#define REG_DFE_INIT0_L2_tap2_init_lane2(data)                        (0x03F00000&((data)<<20))
#define REG_DFE_INIT0_L2_tap1_init_lane2(data)                        (0x000FC000&((data)<<14))
#define REG_DFE_INIT0_L2_tap0_init_lane2(data)                        (0x00003E00&((data)<<9))
#define REG_DFE_INIT0_L2_servo_init_lane2(data)                       (0x000001F0&((data)<<4))
#define REG_DFE_INIT0_L2_vth_init_lane2(data)                         (0x0000000F&(data))
#define REG_DFE_INIT0_L2_get_tap3_init_lane2(data)                    ((0xFC000000&(data))>>26)
#define REG_DFE_INIT0_L2_get_tap2_init_lane2(data)                    ((0x03F00000&(data))>>20)
#define REG_DFE_INIT0_L2_get_tap1_init_lane2(data)                    ((0x000FC000&(data))>>14)
#define REG_DFE_INIT0_L2_get_tap0_init_lane2(data)                    ((0x00003E00&(data))>>9)
#define REG_DFE_INIT0_L2_get_servo_init_lane2(data)                   ((0x000001F0&(data))>>4)
#define REG_DFE_INIT0_L2_get_vth_init_lane2(data)                     (0x0000000F&(data))

#define  REG_DFE_INIT1_L2                                                       0x1800DC28
#define  REG_DFE_INIT1_L2_reg_addr                                              "0xB800DC28"
#define  REG_DFE_INIT1_L2_reg                                                   0xB800DC28
#define  REG_DFE_INIT1_L2_inst_addr                                             "0x0008"
#define  REG_DFE_INIT1_L2_inst                                                  0x0008
#define REG_DFE_INIT1_L2_load_in_init_lane2_shift                     (24)
#define REG_DFE_INIT1_L2_dfe_en_buffer_lane2_shift                    (22)
#define REG_DFE_INIT1_L2_dfe_en_buffer_manual_lane2_shift             (21)
#define REG_DFE_INIT1_L2_dfe_set_cs_lane2_shift                       (19)
#define REG_DFE_INIT1_L2_dfe_set_cs_manual_lane2_shift                (18)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_17_shift                              (17)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_16_shift                              (16)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_15_shift                              (15)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_14_shift                              (14)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_13_0_shift                            (0)
#define REG_DFE_INIT1_L2_load_in_init_lane2_mask                      (0xFF000000)
#define REG_DFE_INIT1_L2_dfe_en_buffer_lane2_mask                     (0x00C00000)
#define REG_DFE_INIT1_L2_dfe_en_buffer_manual_lane2_mask              (0x00200000)
#define REG_DFE_INIT1_L2_dfe_set_cs_lane2_mask                        (0x00180000)
#define REG_DFE_INIT1_L2_dfe_set_cs_manual_lane2_mask                 (0x00040000)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_17_mask                               (0x00020000)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_16_mask                               (0x00010000)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_15_mask                               (0x00008000)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_14_mask                               (0x00004000)
#define  REG_DFE_INIT1_L2_init1_rev_lane2_13_0_mask                             (0x00003FFF)
#define REG_DFE_INIT1_L2_load_in_init_lane2(data)                     (0xFF000000&((data)<<24))
#define REG_DFE_INIT1_L2_dfe_en_buffer_lane2(data)                    (0x00C00000&((data)<<22))
#define REG_DFE_INIT1_L2_dfe_en_buffer_manual_lane2(data)             (0x00200000&((data)<<21))
#define REG_DFE_INIT1_L2_dfe_set_cs_lane2(data)                       (0x00180000&((data)<<19))
#define REG_DFE_INIT1_L2_dfe_set_cs_manual_lane2(data)                (0x00040000&((data)<<18))
#define  REG_DFE_INIT1_L2_init1_rev_lane2_17(data)                              (0x00020000&((data)<<17))
#define  REG_DFE_INIT1_L2_init1_rev_lane2_16(data)                              (0x00010000&((data)<<16))
#define  REG_DFE_INIT1_L2_init1_rev_lane2_15(data)                              (0x00008000&((data)<<15))
#define  REG_DFE_INIT1_L2_init1_rev_lane2_14(data)                              (0x00004000&((data)<<14))
#define  REG_DFE_INIT1_L2_init1_rev_lane2_13_0(data)                            (0x00003FFF&(data))
#define REG_DFE_INIT1_L2_get_load_in_init_lane2(data)                 ((0xFF000000&(data))>>24)
#define REG_DFE_INIT1_L2_get_dfe_en_buffer_lane2(data)                ((0x00C00000&(data))>>22)
#define REG_DFE_INIT1_L2_get_dfe_en_buffer_manual_lane2(data)         ((0x00200000&(data))>>21)
#define REG_DFE_INIT1_L2_get_dfe_set_cs_lane2(data)                   ((0x00180000&(data))>>19)
#define REG_DFE_INIT1_L2_get_dfe_set_cs_manual_lane2(data)            ((0x00040000&(data))>>18)
#define  REG_DFE_INIT1_L2_get_init1_rev_lane2_17(data)                          ((0x00020000&(data))>>17)
#define  REG_DFE_INIT1_L2_get_init1_rev_lane2_16(data)                          ((0x00010000&(data))>>16)
#define  REG_DFE_INIT1_L2_get_init1_rev_lane2_15(data)                          ((0x00008000&(data))>>15)
#define  REG_DFE_INIT1_L2_get_init1_rev_lane2_14(data)                          ((0x00004000&(data))>>14)
#define  REG_DFE_INIT1_L2_get_init1_rev_lane2_13_0(data)                        (0x00003FFF&(data))

#define  REG_DFE_MODE                                                           0x1800DC30
#define  REG_DFE_MODE_reg_addr                                                  "0xB800DC30"
#define  REG_DFE_MODE_reg                                                       0xB800DC30
#define  REG_DFE_MODE_inst_addr                                                 "0x0009"
#define  REG_DFE_MODE_inst                                                      0x0009
#define REG_DFE_MODE_adapt_mode_shift                                 (30)
#define REG_DFE_MODE_edge_det_mode_shift                              (29)
#define REG_DFE_MODE_transition_only_shift                            (28)
#define REG_DFE_MODE_le_auto_reload_shift                             (27)
#define REG_DFE_MODE_tap1_delay_shift                                 (24)
#define REG_DFE_MODE_tap24_delay_shift                                (21)
#define REG_DFE_MODE_le_delay_shift                                   (18)
#define REG_DFE_MODE_servo_delay_shift                                (16)
#define REG_DFE_MODE_gray_en_shift                                    (8)
#define REG_DFE_MODE_dfe_adapt_rstb_shift                             (4)
#define REG_DFE_MODE_cs_mode_shift                                    (3)
#define REG_DFE_MODE_tap0_notrans_shift                               (2)
#define REG_DFE_MODE_servo_notrans_shift                              (1)
#define REG_DFE_MODE_dfe_debug_extra_sel_shift                        (0)
#define REG_DFE_MODE_adapt_mode_mask                                  (0xC0000000)
#define REG_DFE_MODE_edge_det_mode_mask                               (0x20000000)
#define REG_DFE_MODE_transition_only_mask                             (0x10000000)
#define REG_DFE_MODE_le_auto_reload_mask                              (0x08000000)
#define REG_DFE_MODE_tap1_delay_mask                                  (0x07000000)
#define REG_DFE_MODE_tap24_delay_mask                                 (0x00E00000)
#define REG_DFE_MODE_le_delay_mask                                    (0x001C0000)
#define REG_DFE_MODE_servo_delay_mask                                 (0x00030000)
#define REG_DFE_MODE_gray_en_mask                                     (0x0000FF00)
#define REG_DFE_MODE_dfe_adapt_rstb_mask                              (0x000000F0)
#define REG_DFE_MODE_cs_mode_mask                                     (0x00000008)
#define REG_DFE_MODE_tap0_notrans_mask                                (0x00000004)
#define REG_DFE_MODE_servo_notrans_mask                               (0x00000002)
#define REG_DFE_MODE_dfe_debug_extra_sel_mask                         (0x00000001)
#define REG_DFE_MODE_adapt_mode(data)                                 (0xC0000000&((data)<<30))
#define REG_DFE_MODE_edge_det_mode(data)                              (0x20000000&((data)<<29))
#define REG_DFE_MODE_transition_only(data)                            (0x10000000&((data)<<28))
#define REG_DFE_MODE_le_auto_reload(data)                             (0x08000000&((data)<<27))
#define REG_DFE_MODE_tap1_delay(data)                                 (0x07000000&((data)<<24))
#define REG_DFE_MODE_tap24_delay(data)                                (0x00E00000&((data)<<21))
#define REG_DFE_MODE_le_delay(data)                                   (0x001C0000&((data)<<18))
#define REG_DFE_MODE_servo_delay(data)                                (0x00030000&((data)<<16))
#define REG_DFE_MODE_gray_en(data)                                    (0x0000FF00&((data)<<8))
#define REG_DFE_MODE_dfe_adapt_rstb(data)                             (0x000000F0&((data)<<4))
#define REG_DFE_MODE_cs_mode(data)                                    (0x00000008&((data)<<3))
#define REG_DFE_MODE_tap0_notrans(data)                               (0x00000004&((data)<<2))
#define REG_DFE_MODE_servo_notrans(data)                              (0x00000002&((data)<<1))
#define REG_DFE_MODE_dfe_debug_extra_sel(data)                        (0x00000001&(data))
#define REG_DFE_MODE_get_adapt_mode(data)                             ((0xC0000000&(data))>>30)
#define REG_DFE_MODE_get_edge_det_mode(data)                          ((0x20000000&(data))>>29)
#define REG_DFE_MODE_get_transition_only(data)                        ((0x10000000&(data))>>28)
#define REG_DFE_MODE_get_le_auto_reload(data)                         ((0x08000000&(data))>>27)
#define REG_DFE_MODE_get_tap1_delay(data)                             ((0x07000000&(data))>>24)
#define REG_DFE_MODE_get_tap24_delay(data)                            ((0x00E00000&(data))>>21)
#define REG_DFE_MODE_get_le_delay(data)                               ((0x001C0000&(data))>>18)
#define REG_DFE_MODE_get_servo_delay(data)                            ((0x00030000&(data))>>16)
#define REG_DFE_MODE_get_gray_en(data)                                ((0x0000FF00&(data))>>8)
#define REG_DFE_MODE_get_dfe_adapt_rstb(data)                         ((0x000000F0&(data))>>4)
#define REG_DFE_MODE_get_cs_mode(data)                                ((0x00000008&(data))>>3)
#define REG_DFE_MODE_get_tap0_notrans(data)                           ((0x00000004&(data))>>2)
#define REG_DFE_MODE_get_servo_notrans(data)                          ((0x00000002&(data))>>1)
#define REG_DFE_MODE_get_dfe_debug_extra_sel(data)                    (0x00000001&(data))

#define  REG_DFE_GAIN                                                           0x1800DC34
#define  REG_DFE_GAIN_reg_addr                                                  "0xB800DC34"
#define  REG_DFE_GAIN_reg                                                       0xB800DC34
#define  REG_DFE_GAIN_inst_addr                                                 "0x000A"
#define  REG_DFE_GAIN_inst                                                      0x000A
#define REG_DFE_GAIN_tap0_gain_shift                                  (29)
#define REG_DFE_GAIN_tap1_gain_shift                                  (26)
#define REG_DFE_GAIN_tap2_gain_shift                                  (23)
#define REG_DFE_GAIN_tap3_gain_shift                                  (20)
#define REG_DFE_GAIN_tap4_gain_shift                                  (17)
#define REG_DFE_GAIN_servo_gain_shift                                 (14)
#define REG_DFE_GAIN_le_gain1_shift                                   (11)
#define REG_DFE_GAIN_le_gain2_shift                                   (8)
#define REG_DFE_GAIN_gain_rev_shift                                   (0)
#define REG_DFE_GAIN_tap0_gain_mask                                   (0xE0000000)
#define REG_DFE_GAIN_tap1_gain_mask                                   (0x1C000000)
#define REG_DFE_GAIN_tap2_gain_mask                                   (0x03800000)
#define REG_DFE_GAIN_tap3_gain_mask                                   (0x00700000)
#define REG_DFE_GAIN_tap4_gain_mask                                   (0x000E0000)
#define REG_DFE_GAIN_servo_gain_mask                                  (0x0001C000)
#define REG_DFE_GAIN_le_gain1_mask                                    (0x00003800)
#define REG_DFE_GAIN_le_gain2_mask                                    (0x00000700)
#define REG_DFE_GAIN_gain_rev_mask                                    (0x000000FF)
#define REG_DFE_GAIN_tap0_gain(data)                                  (0xE0000000&((data)<<29))
#define REG_DFE_GAIN_tap1_gain(data)                                  (0x1C000000&((data)<<26))
#define REG_DFE_GAIN_tap2_gain(data)                                  (0x03800000&((data)<<23))
#define REG_DFE_GAIN_tap3_gain(data)                                  (0x00700000&((data)<<20))
#define REG_DFE_GAIN_tap4_gain(data)                                  (0x000E0000&((data)<<17))
#define REG_DFE_GAIN_servo_gain(data)                                 (0x0001C000&((data)<<14))
#define REG_DFE_GAIN_le_gain1(data)                                   (0x00003800&((data)<<11))
#define REG_DFE_GAIN_le_gain2(data)                                   (0x00000700&((data)<<8))
#define REG_DFE_GAIN_gain_rev(data)                                   (0x000000FF&(data))
#define REG_DFE_GAIN_get_tap0_gain(data)                              ((0xE0000000&(data))>>29)
#define REG_DFE_GAIN_get_tap1_gain(data)                              ((0x1C000000&(data))>>26)
#define REG_DFE_GAIN_get_tap2_gain(data)                              ((0x03800000&(data))>>23)
#define REG_DFE_GAIN_get_tap3_gain(data)                              ((0x00700000&(data))>>20)
#define REG_DFE_GAIN_get_tap4_gain(data)                              ((0x000E0000&(data))>>17)
#define REG_DFE_GAIN_get_servo_gain(data)                             ((0x0001C000&(data))>>14)
#define REG_DFE_GAIN_get_le_gain1(data)                               ((0x00003800&(data))>>11)
#define REG_DFE_GAIN_get_le_gain2(data)                               ((0x00000700&(data))>>8)
#define REG_DFE_GAIN_get_gain_rev(data)                               (0x000000FF&(data))

#define  REG_DFE_LIMIT0                                                         0x1800DC38
#define  REG_DFE_LIMIT0_reg_addr                                                "0xB800DC38"
#define  REG_DFE_LIMIT0_reg                                                     0xB800DC38
#define  REG_DFE_LIMIT0_inst_addr                                               "0x000B"
#define  REG_DFE_LIMIT0_inst                                                    0x000B
#define REG_DFE_LIMIT0_tap0_max_shift                                 (27)
#define REG_DFE_LIMIT0_tap1_min_shift                                 (21)
#define REG_DFE_LIMIT0_tap2_max_shift                                 (16)
#define REG_DFE_LIMIT0_tap2_min_shift                                 (11)
#define REG_DFE_LIMIT0_tap3_max_shift                                 (6)
#define REG_DFE_LIMIT0_tap3_min_shift                                 (1)
#define REG_DFE_LIMIT0_limit0_rev_shift                               (0)
#define REG_DFE_LIMIT0_tap0_max_mask                                  (0xF8000000)
#define REG_DFE_LIMIT0_tap1_min_mask                                  (0x07E00000)
#define REG_DFE_LIMIT0_tap2_max_mask                                  (0x001F0000)
#define REG_DFE_LIMIT0_tap2_min_mask                                  (0x0000F800)
#define REG_DFE_LIMIT0_tap3_max_mask                                  (0x000007C0)
#define REG_DFE_LIMIT0_tap3_min_mask                                  (0x0000003E)
#define REG_DFE_LIMIT0_limit0_rev_mask                                (0x00000001)
#define REG_DFE_LIMIT0_tap0_max(data)                                 (0xF8000000&((data)<<27))
#define REG_DFE_LIMIT0_tap1_min(data)                                 (0x07E00000&((data)<<21))
#define REG_DFE_LIMIT0_tap2_max(data)                                 (0x001F0000&((data)<<16))
#define REG_DFE_LIMIT0_tap2_min(data)                                 (0x0000F800&((data)<<11))
#define REG_DFE_LIMIT0_tap3_max(data)                                 (0x000007C0&((data)<<6))
#define REG_DFE_LIMIT0_tap3_min(data)                                 (0x0000003E&((data)<<1))
#define REG_DFE_LIMIT0_limit0_rev(data)                               (0x00000001&(data))
#define REG_DFE_LIMIT0_get_tap0_max(data)                             ((0xF8000000&(data))>>27)
#define REG_DFE_LIMIT0_get_tap1_min(data)                             ((0x07E00000&(data))>>21)
#define REG_DFE_LIMIT0_get_tap2_max(data)                             ((0x001F0000&(data))>>16)
#define REG_DFE_LIMIT0_get_tap2_min(data)                             ((0x0000F800&(data))>>11)
#define REG_DFE_LIMIT0_get_tap3_max(data)                             ((0x000007C0&(data))>>6)
#define REG_DFE_LIMIT0_get_tap3_min(data)                             ((0x0000003E&(data))>>1)
#define REG_DFE_LIMIT0_get_limit0_rev(data)                           (0x00000001&(data))

#define  REG_DFE_LIMIT1                                                         0x1800DC3C
#define  REG_DFE_LIMIT1_reg_addr                                                "0xB800DC3C"
#define  REG_DFE_LIMIT1_reg                                                     0xB800DC3C
#define  REG_DFE_LIMIT1_inst_addr                                               "0x000C"
#define  REG_DFE_LIMIT1_inst                                                    0x000C
#define REG_DFE_LIMIT1_tap4_max_shift                                 (27)
#define REG_DFE_LIMIT1_tap4_min_shift                                 (22)
#define REG_DFE_LIMIT1_vth_min_shift                                  (20)
#define REG_DFE_LIMIT1_vth_dis_buf_range_shift                        (18)
#define REG_DFE_LIMIT1_vth_threshold_shift                            (15)
#define REG_DFE_LIMIT1_tap0_threshold_shift                           (11)
#define REG_DFE_LIMIT1_limit1_rev_shift                               (0)
#define REG_DFE_LIMIT1_tap4_max_mask                                  (0xF8000000)
#define REG_DFE_LIMIT1_tap4_min_mask                                  (0x07C00000)
#define REG_DFE_LIMIT1_vth_min_mask                                   (0x00300000)
#define REG_DFE_LIMIT1_vth_dis_buf_range_mask                         (0x000C0000)
#define REG_DFE_LIMIT1_vth_threshold_mask                             (0x00038000)
#define REG_DFE_LIMIT1_tap0_threshold_mask                            (0x00007800)
#define REG_DFE_LIMIT1_limit1_rev_mask                                (0x000007FF)
#define REG_DFE_LIMIT1_tap4_max(data)                                 (0xF8000000&((data)<<27))
#define REG_DFE_LIMIT1_tap4_min(data)                                 (0x07C00000&((data)<<22))
#define REG_DFE_LIMIT1_vth_min(data)                                  (0x00300000&((data)<<20))
#define REG_DFE_LIMIT1_vth_dis_buf_range(data)                        (0x000C0000&((data)<<18))
#define REG_DFE_LIMIT1_vth_threshold(data)                            (0x00038000&((data)<<15))
#define REG_DFE_LIMIT1_tap0_threshold(data)                           (0x00007800&((data)<<11))
#define REG_DFE_LIMIT1_limit1_rev(data)                               (0x000007FF&(data))
#define REG_DFE_LIMIT1_get_tap4_max(data)                             ((0xF8000000&(data))>>27)
#define REG_DFE_LIMIT1_get_tap4_min(data)                             ((0x07C00000&(data))>>22)
#define REG_DFE_LIMIT1_get_vth_min(data)                              ((0x00300000&(data))>>20)
#define REG_DFE_LIMIT1_get_vth_dis_buf_range(data)                    ((0x000C0000&(data))>>18)
#define REG_DFE_LIMIT1_get_vth_threshold(data)                        ((0x00038000&(data))>>15)
#define REG_DFE_LIMIT1_get_tap0_threshold(data)                       ((0x00007800&(data))>>11)
#define REG_DFE_LIMIT1_get_limit1_rev(data)                           (0x000007FF&(data))

#define  REG_DFE_LIMIT2                                                         0x1800DC40
#define  REG_DFE_LIMIT2_reg_addr                                                "0xB800DC40"
#define  REG_DFE_LIMIT2_reg                                                     0xB800DC40
#define  REG_DFE_LIMIT2_inst_addr                                               "0x000D"
#define  REG_DFE_LIMIT2_inst                                                    0x000D
#define REG_DFE_LIMIT2_servo_divisor_shift                            (26)
#define REG_DFE_LIMIT2_tap_divisor_shift                              (20)
#define REG_DFE_LIMIT2_vth_divisor_shift                              (16)
#define REG_DFE_LIMIT2_limit2_rev_shift                               (0)
#define REG_DFE_LIMIT2_servo_divisor_mask                             (0xFC000000)
#define REG_DFE_LIMIT2_tap_divisor_mask                               (0x03F00000)
#define REG_DFE_LIMIT2_vth_divisor_mask                               (0x000F0000)
#define REG_DFE_LIMIT2_limit2_rev_mask                                (0x0000FFFF)
#define REG_DFE_LIMIT2_servo_divisor(data)                            (0xFC000000&((data)<<26))
#define REG_DFE_LIMIT2_tap_divisor(data)                              (0x03F00000&((data)<<20))
#define REG_DFE_LIMIT2_vth_divisor(data)                              (0x000F0000&((data)<<16))
#define REG_DFE_LIMIT2_limit2_rev(data)                               (0x0000FFFF&(data))
#define REG_DFE_LIMIT2_get_servo_divisor(data)                        ((0xFC000000&(data))>>26)
#define REG_DFE_LIMIT2_get_tap_divisor(data)                          ((0x03F00000&(data))>>20)
#define REG_DFE_LIMIT2_get_vth_divisor(data)                          ((0x000F0000&(data))>>16)
#define REG_DFE_LIMIT2_get_limit2_rev(data)                           (0x0000FFFF&(data))

#define  REG_DFE_READBACK                                                       0x1800DC44
#define  REG_DFE_READBACK_reg_addr                                              "0xB800DC44"
#define  REG_DFE_READBACK_reg                                                   0xB800DC44
#define  REG_DFE_READBACK_inst_addr                                             "0x000E"
#define  REG_DFE_READBACK_inst                                                  0x000E
#define REG_DFE_READBACK_record_limit_en_shift                        (31)
#define REG_DFE_READBACK_limit_sel_shift                              (24)
#define REG_DFE_READBACK_limit_data_shift                             (16)
#define REG_DFE_READBACK_coef_sel_shift                               (8)
#define REG_DFE_READBACK_coef_data_shift                              (0)
#define REG_DFE_READBACK_record_limit_en_mask                         (0x80000000)
#define REG_DFE_READBACK_limit_sel_mask                               (0x7F000000)
#define REG_DFE_READBACK_limit_data_mask                              (0x00FF0000)
#define REG_DFE_READBACK_coef_sel_mask                                (0x0000FF00)
#define REG_DFE_READBACK_coef_data_mask                               (0x000000FF)
#define REG_DFE_READBACK_record_limit_en(data)                        (0x80000000&((data)<<31))
#define REG_DFE_READBACK_limit_sel(data)                              (0x7F000000&((data)<<24))
#define REG_DFE_READBACK_limit_data(data)                             (0x00FF0000&((data)<<16))
#define REG_DFE_READBACK_coef_sel(data)                               (0x0000FF00&((data)<<8))
#define REG_DFE_READBACK_coef_data(data)                              (0x000000FF&(data))
#define REG_DFE_READBACK_get_record_limit_en(data)                    ((0x80000000&(data))>>31)
#define REG_DFE_READBACK_get_limit_sel(data)                          ((0x7F000000&(data))>>24)
#define REG_DFE_READBACK_get_limit_data(data)                         ((0x00FF0000&(data))>>16)
#define REG_DFE_READBACK_get_coef_sel(data)                           ((0x0000FF00&(data))>>8)
#define REG_DFE_READBACK_get_coef_data(data)                          (0x000000FF&(data))
#define limit_set_lane_mask					(_BIT30|_BIT29)
#define limit_set_lane_shift					(29)
#define limit_set_mask						(_BIT28|_BIT27|_BIT26|_BIT25|_BIT24)
#define limit_sel(data)  						(limit_set_mask&((data)<<24))
#define get_Tap0_max(data)                          	((0x1F0000&(data))>>16)
#define get_Tap0_min(data)                          	((0x1F0000&(data))>>16)
#define get_Tap1_max(data)                          	((0x3F0000&(data))>>16)
#define get_Tap1_min(data)                          	((0x3F0000&(data))>>16)
#define get_LEQ_max(data)                          	((0x1F0000&(data))>>16)
#define get_LEQ_min(data)                          	((0x1F0000&(data))>>16)
#define coef_set_lane_mask					(_BIT15|_BIT14)
#define coef_set_lane_shift					(14)
#define coef_set_mask						(_BIT13|_BIT12|_BIT11|_BIT10|_BIT9|_BIT8)
#define coef_sel(data)                               		(coef_set_mask&((data)<<8))
#define get_VTH_coef(data)                          	(0xF&(data))
#define get_TAP0_coef(data)                          	(0x1F&(data))
#define get_TAP1_coef(data)                          	(0x3F&(data))
#define get_TAP2_coef_sign(data)                   	(0x20&(data))
#define get_TAP2_coef(data)                          	(0x1F&(data))
#define get_TAP3_coef_sign(data)                    	(0x20&(data))
#define get_TAP3_coef(data)                          	(0x1F&(data))
#define get_TAP4_coef_sign(data)                     (0x20&(data))
#define get_TAP4_coef(data)                          	(0x1F&(data))
#define get_SERVO_coef(data)                          	(0x1F&(data))
#define get_LE1_coef(data)                          	(0x1F&(data))
#define get_CurrentStep_coef(data) 			((0x30&(data))>>4)
#define get_BufferMode_coef(data) 			((0xc0&(data))>>6)


#define  REG_DFE_FLAG                                                           0x1800DC48
#define  REG_DFE_FLAG_reg_addr                                                  "0xB800DC48"
#define  REG_DFE_FLAG_reg                                                       0xB800DC48
#define  REG_DFE_FLAG_inst_addr                                                 "0x000F"
#define  REG_DFE_FLAG_inst                                                      0x000F
#define REG_DFE_FLAG_adapt_fail_flag_shift                            (28)
#define REG_DFE_FLAG_adapt_swing_max_flag_shift                       (24)
#define REG_DFE_FLAG_flag_rev1_shift                                  (12)
#define REG_DFE_FLAG_flag_rev2_shift                                  (0)
#define REG_DFE_FLAG_adapt_fail_flag_mask                             (0xF0000000)
#define REG_DFE_FLAG_adapt_swing_max_flag_mask                        (0x0F000000)
#define REG_DFE_FLAG_flag_rev1_mask                                   (0x00FFF000)
#define REG_DFE_FLAG_flag_rev2_mask                                   (0x00000FFF)
#define REG_DFE_FLAG_adapt_fail_flag(data)                            (0xF0000000&((data)<<28))
#define REG_DFE_FLAG_adapt_swing_max_flag(data)                       (0x0F000000&((data)<<24))
#define REG_DFE_FLAG_flag_rev1(data)                                  (0x00FFF000&((data)<<12))
#define REG_DFE_FLAG_flag_rev2(data)                                  (0x00000FFF&(data))
#define REG_DFE_FLAG_get_adapt_fail_flag(data)                        ((0xF0000000&(data))>>28)
#define REG_DFE_FLAG_get_adapt_swing_max_flag(data)                   ((0x0F000000&(data))>>24)
#define REG_DFE_FLAG_get_flag_rev1(data)                              ((0x00FFF000&(data))>>12)
#define REG_DFE_FLAG_get_flag_rev2(data)                              (0x00000FFF&(data))
#endif
