/**
* @file rbusDe_only_modeReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012-8-15
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_DE_ONLY_MODE_REG_H_
#define _RBUS_DE_ONLY_MODE_REG_H_

#include "rbus/rbusTypes.h"




// DE_ONLY_MODE Register Address

#define DE_ONLY_MODE_MAIN_1_DE_ONLY_MODE_CTRL0_VADDR  (0xb8022500)
#define DE_ONLY_MODE_MAIN_1_DE_ONLY_MODE_CTRL1_VADDR  (0xb8022504)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL0_VADDR  (0xb8022508)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL1_VADDR  (0xb802250c)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL2_VADDR  (0xb8022510)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL3_VADDR  (0xb8022514)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL4_VADDR  (0xb8022518)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL5_VADDR  (0xb802251c)
#define DE_ONLY_MODE_MAIN_1_DE_DETECT_EXTEND_CTRL6_VADDR  (0xb8022520)
#define DE_ONLY_MODE_SUB_DE_ONLY_MODE_CTRL0_VADDR  (0xb8022530)
#define DE_ONLY_MODE_SUB_DE_ONLY_MODE_CTRL1_VADDR  (0xb8022534)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL0_VADDR  (0xb8022538)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL1_VADDR  (0xb802253c)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL2_VADDR  (0xb8022540)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL3_VADDR  (0xb8022544)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL4_VADDR  (0xb8022548)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL5_VADDR  (0xb802254c)
#define DE_ONLY_MODE_SUB_DE_DETECT_EXTEND_CTRL6_VADDR  (0xb8022550)
#define DE_ONLY_MODE_MAIN_2_DE_ONLY_MODE_CTRL0_VADDR  (0xb8022560)
#define DE_ONLY_MODE_MAIN_2_DE_ONLY_MODE_CTRL1_VADDR  (0xb8022564)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL0_VADDR  (0xb8022568)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL1_VADDR  (0xb802256c)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL2_VADDR  (0xb8022570)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL3_VADDR  (0xb8022574)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL4_VADDR  (0xb8022578)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL5_VADDR  (0xb802257c)
#define DE_ONLY_MODE_MAIN_2_DE_DETECT_EXTEND_CTRL6_VADDR  (0xb8022580)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======DE_ONLY_MODE register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_de_only_mode:1;
        RBus_UInt32  m1_autogen_hs_width:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m1_autogen_h_fporch:15;
    };
}main_1_de_only_mode_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_mask_hs_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  m1_autogen_vs_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_autogen_v_fporch:13;
    };
}main_1_de_only_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_de_extend_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  m1_de_v_porch_length:24;
    };
}main_1_de_detect_extend_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m1_de_h_porch_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_de_act_length:13;
    };
}main_1_de_detect_extend_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_detect_cond_detect_low:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  m1_detect_cont_low:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_detect_th_low:5;
        RBus_UInt32  m1_detect_cond_detect_high:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  m1_detect_cont_high:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  m1_detect_th_high:5;
    };
}main_1_de_detect_extend_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_fix_pixel_mode:1;
        RBus_UInt32  m1_cont_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  m1_high_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_low_width:13;
    };
}main_1_de_detect_extend_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_v_low_width:20;
        RBus_UInt32  m1_line_number:12;
    };
}main_1_de_detect_extend_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m1_err_act_high_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_err_h_porch_max:13;
    };
}main_1_de_detect_extend_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_err_v_porch_max:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  m1_vgip_select_de:1;
        RBus_UInt32  m1_sync_autogen_select_de:1;
        RBus_UInt32  m1_de_wdog_en:1;
        RBus_UInt32  m1_de_irq_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  m1_act_high_error:1;
        RBus_UInt32  m1_h_porch_error:1;
        RBus_UInt32  m1_v_porch_error:1;
    };
}main_1_de_detect_extend_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_de_only_mode:1;
        RBus_UInt32  s_autogen_hs_width:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_autogen_h_fporch:15;
    };
}sub_de_only_mode_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_mask_hs_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  s_autogen_vs_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_autogen_v_fporch:13;
    };
}sub_de_only_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_de_extend_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  s_de_v_porch_length:24;
    };
}sub_de_detect_extend_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  s_de_h_porch_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_de_act_length:13;
    };
}sub_de_detect_extend_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_detect_cond_detect_low:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  s_detect_cont_low:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_detect_th_low:5;
        RBus_UInt32  s_detect_cond_detect_high:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  s_detect_cont_high:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  s_detect_th_high:5;
    };
}sub_de_detect_extend_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_fix_pixel_mode:1;
        RBus_UInt32  s_cont_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_high_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_low_width:13;
    };
}sub_de_detect_extend_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_v_low_width:20;
        RBus_UInt32  s_line_number:12;
    };
}sub_de_detect_extend_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  s_err_act_high_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_err_h_porch_max:13;
    };
}sub_de_detect_extend_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_err_v_porch_max:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  s_vgip_select_de:1;
        RBus_UInt32  s_sync_autogen_select_de:1;
        RBus_UInt32  s_de_wdog_en:1;
        RBus_UInt32  s_de_irq_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  s_act_high_error:1;
        RBus_UInt32  s_h_porch_error:1;
        RBus_UInt32  s_v_porch_error:1;
    };
}sub_de_detect_extend_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_de_only_mode:1;
        RBus_UInt32  m2_autogen_hs_width:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m2_autogen_h_fporch:15;
    };
}main_2_de_only_mode_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_mask_hs_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  m2_autogen_vs_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_autogen_v_fporch:13;
    };
}main_2_de_only_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_de_extend_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  m2_de_v_porch_length:24;
    };
}main_2_de_detect_extend_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m2_de_h_porch_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_de_act_length:13;
    };
}main_2_de_detect_extend_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_detect_cond_detect_low:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  m2_detect_cont_low:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_detect_th_low:5;
        RBus_UInt32  m2_detect_cond_detect_high:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  m2_detect_cont_high:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  m2_detect_th_high:5;
    };
}main_2_de_detect_extend_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_fix_pixel_mode:1;
        RBus_UInt32  m2_cont_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  m2_high_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_low_width:13;
    };
}main_2_de_detect_extend_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_v_low_width:20;
        RBus_UInt32  m2_line_number:12;
    };
}main_2_de_detect_extend_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  m2_err_act_high_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_err_h_porch_max:13;
    };
}main_2_de_detect_extend_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_err_v_porch_max:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  m2_vgip_select_de:1;
        RBus_UInt32  m2_sync_autogen_select_de:1;
        RBus_UInt32  m2_de_wdog_en:1;
        RBus_UInt32  m2_de_irq_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  m2_act_high_error:1;
        RBus_UInt32  m2_h_porch_error:1;
        RBus_UInt32  m2_v_porch_error:1;
    };
}main_2_de_detect_extend_ctrl6_RBUS;





#else //apply LITTLE_ENDIAN


//======DE_ONLY_MODE register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_autogen_h_fporch:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m1_autogen_hs_width:15;
        RBus_UInt32  m1_de_only_mode:1;
    };
}main_1_de_only_mode_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_autogen_v_fporch:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_autogen_vs_width:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  m1_mask_hs_sel:1;
    };
}main_1_de_only_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_de_v_porch_length:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  m1_de_extend_en:1;
    };
}main_1_de_detect_extend_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_de_act_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_de_h_porch_length:13;
        RBus_UInt32  res1:3;
    };
}main_1_de_detect_extend_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_detect_th_high:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  m1_detect_cont_high:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  m1_detect_cond_detect_high:1;
        RBus_UInt32  m1_detect_th_low:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_detect_cont_low:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  m1_detect_cond_detect_low:1;
    };
}main_1_de_detect_extend_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_low_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_high_width:13;
        RBus_UInt32  res1:1;
        RBus_UInt32  m1_cont_mode:1;
        RBus_UInt32  m1_fix_pixel_mode:1;
    };
}main_1_de_detect_extend_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_line_number:12;
        RBus_UInt32  m1_v_low_width:20;
    };
}main_1_de_detect_extend_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_err_h_porch_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m1_err_act_high_max:13;
        RBus_UInt32  res1:3;
    };
}main_1_de_detect_extend_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m1_v_porch_error:1;
        RBus_UInt32  m1_h_porch_error:1;
        RBus_UInt32  m1_act_high_error:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  m1_de_irq_en:1;
        RBus_UInt32  m1_de_wdog_en:1;
        RBus_UInt32  m1_sync_autogen_select_de:1;
        RBus_UInt32  m1_vgip_select_de:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  m1_err_v_porch_max:20;
    };
}main_1_de_detect_extend_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_autogen_h_fporch:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_autogen_hs_width:15;
        RBus_UInt32  s_de_only_mode:1;
    };
}sub_de_only_mode_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_autogen_v_fporch:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_autogen_vs_width:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  s_mask_hs_sel:1;
    };
}sub_de_only_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_de_v_porch_length:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  s_de_extend_en:1;
    };
}sub_de_detect_extend_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_de_act_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_de_h_porch_length:13;
        RBus_UInt32  res1:3;
    };
}sub_de_detect_extend_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_detect_th_high:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  s_detect_cont_high:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  s_detect_cond_detect_high:1;
        RBus_UInt32  s_detect_th_low:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_detect_cont_low:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  s_detect_cond_detect_low:1;
    };
}sub_de_detect_extend_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_low_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_high_width:13;
        RBus_UInt32  res1:1;
        RBus_UInt32  s_cont_mode:1;
        RBus_UInt32  s_fix_pixel_mode:1;
    };
}sub_de_detect_extend_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_line_number:12;
        RBus_UInt32  s_v_low_width:20;
    };
}sub_de_detect_extend_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_err_h_porch_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s_err_act_high_max:13;
        RBus_UInt32  res1:3;
    };
}sub_de_detect_extend_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s_v_porch_error:1;
        RBus_UInt32  s_h_porch_error:1;
        RBus_UInt32  s_act_high_error:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  s_de_irq_en:1;
        RBus_UInt32  s_de_wdog_en:1;
        RBus_UInt32  s_sync_autogen_select_de:1;
        RBus_UInt32  s_vgip_select_de:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  s_err_v_porch_max:20;
    };
}sub_de_detect_extend_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_autogen_h_fporch:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  m2_autogen_hs_width:15;
        RBus_UInt32  m2_de_only_mode:1;
    };
}main_2_de_only_mode_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_autogen_v_fporch:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_autogen_vs_width:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  m2_mask_hs_sel:1;
    };
}main_2_de_only_mode_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_de_v_porch_length:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  m2_de_extend_en:1;
    };
}main_2_de_detect_extend_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_de_act_length:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_de_h_porch_length:13;
        RBus_UInt32  res1:3;
    };
}main_2_de_detect_extend_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_detect_th_high:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  m2_detect_cont_high:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  m2_detect_cond_detect_high:1;
        RBus_UInt32  m2_detect_th_low:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_detect_cont_low:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  m2_detect_cond_detect_low:1;
    };
}main_2_de_detect_extend_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_low_width:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_high_width:13;
        RBus_UInt32  res1:1;
        RBus_UInt32  m2_cont_mode:1;
        RBus_UInt32  m2_fix_pixel_mode:1;
    };
}main_2_de_detect_extend_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_line_number:12;
        RBus_UInt32  m2_v_low_width:20;
    };
}main_2_de_detect_extend_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_err_h_porch_max:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  m2_err_act_high_max:13;
        RBus_UInt32  res1:3;
    };
}main_2_de_detect_extend_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m2_v_porch_error:1;
        RBus_UInt32  m2_h_porch_error:1;
        RBus_UInt32  m2_act_high_error:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  m2_de_irq_en:1;
        RBus_UInt32  m2_de_wdog_en:1;
        RBus_UInt32  m2_sync_autogen_select_de:1;
        RBus_UInt32  m2_vgip_select_de:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  m2_err_v_porch_max:20;
    };
}main_2_de_detect_extend_ctrl6_RBUS;


#endif







#endif //_RBUS_DE_ONLY_MODE_REG_H_
