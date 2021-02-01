#include "rbusTypes.h"
#include "misc_reg.h"
#include "rbusPinmuxReg.h"
#include "rbusPinmux_StReg.h"

#define PWM_DB_CTRL_VADDR                  (0xb801bc80)
#define PWM0_CTRL_VADDR                      (0xb801bc84)
#define PWM0_TIMING_CTRL_VADDR        (0xb801bc88)
#define PWM0_DUTY_SET_VADDR             (0xb801bc8c)

#define ISO_PWM_DB_CTRL_VADDR                (0xb8061280)
#define ISO_PWM0_CTRL_VADDR                    (0xb8061284)
#define ISO_PWM0_TIMING_CTRL_VADDR      (0xb8061288)
#define ISO_PWM0_DUTY_SET_VADDR           (0xb806128C)
#define ISO_PWM1_CTRL_VADDR                    (0xb8061290)
#define ISO_PWM1_TIMING_CTRL_VADDR      (0xb8061294)
#define ISO_PWM1_DUTY_SET_VADDR           (0xb8061298)
#define PWM_ODMODE_CR			(0xb80612b4)


//#define PIN_MUX_CTRL3_VADDR			(PINMUX_PIN_MUX_CTRL3_VADDR)
#define ISO_ST_TEST_PIN_CTRL			(PINMUX_ST_ST_TEST_PIN_CTRL_VADDR)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm_w_db_en:1;
        RBus_UInt32  pwm_db_rsel:1;
        RBus_UInt32  pwm_w_db_wr:1;
        RBus_UInt32  pwm_w_db_mode:1;
        RBus_UInt32  res1:28;
    };
}pwm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0l:1;
        RBus_UInt32  pwm0_ck:1;
        RBus_UInt32  pwm0_en:1;
        RBus_UInt32  pwm0_vs_rst_en:1;
        RBus_UInt32  pwm0_dut_8b:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  open_drain_mod_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pwm_width_sel:1;
    };
}pwm0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_cnt_mode:1;
        RBus_UInt32  pwm0_ck_sel_hs:1;
        RBus_UInt32  pwm0_ck_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm0_cycle_max:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm0_m:2;
        RBus_UInt32  pwm0_n:12;
    };
}pwm0_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pwm0_dut:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm0_totalcnt:12;
    };
}pwm0_duty_set_RBUS;

#else
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pwm_w_db_mode:1;
        RBus_UInt32  pwm_w_db_wr:1;
        RBus_UInt32  pwm_db_rsel:1;
        RBus_UInt32  pwm_w_db_en:1;
    };
}pwm_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm_width_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  open_drain_mod_sel:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  pwm0_dut_8b:1;
        RBus_UInt32  pwm0_vs_rst_en:1;
        RBus_UInt32  pwm0_en:1;
        RBus_UInt32  pwm0_ck:1;
        RBus_UInt32  pwm0l:1;
    };
}pwm0_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_n:12;
        RBus_UInt32  pwm0_m:2;
        RBus_UInt32  res2:10;
        RBus_UInt32  pwm0_cycle_max:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  pwm0_ck_sel:1;
        RBus_UInt32  pwm0_ck_sel_hs:1;
        RBus_UInt32  pwm0_cnt_mode:1;
    };
}pwm0_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm0_totalcnt:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  pwm0_dut:12;
        RBus_UInt32  res1:4;
    };
}pwm0_duty_set_RBUS;

#endif
