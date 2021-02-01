#ifndef __RTK_PWM_REG_H__
#define __RTK_PWM_REG_H__

#include <linux/io.h>

#define	 PWM_M_PLUS_VADDR		(0xb8028CF8)
#define	 PWM_M_PLUS_MASK		(0x00001FFF)

/*Copy from rbus_DesignSpec_ISO_MISC_PWMReg.h*/
#define  ISO_MIS_PWM_DB_CTRL_VADDR		(0xb8061280)
#define  ISO_MIS_PWM0_CTRL_VADDR		(ISO_MIS_PWM_DB_CTRL_VADDR + 0x4)
#define  ISO_MIS_PWM0_TIMING_CTRL_VADDR		(ISO_MIS_PWM_DB_CTRL_VADDR + 0x8)
#define  ISO_MIS_PWM0_DUTY_SET_VADDR		(ISO_MIS_PWM_DB_CTRL_VADDR + 0xC)
#define  ISO_MIS_PWM1_CTRL_VADDR		(ISO_MIS_PWM_DB_CTRL_VADDR + 0x10)
#define  ISO_MIS_PWM1_TIMING_CTRL_VADDR		(ISO_MIS_PWM_DB_CTRL_VADDR + 0x14)
#define  ISO_MIS_PWM1_DUTY_SET_VADDR		(ISO_MIS_PWM_DB_CTRL_VADDR + 0x18)

/*Copy from rbus_DesignSpec_MISC_PWMReg.h*/
#define  MIS_PWM_DB_CTRL_VADDR		(0xb801bc80)
#define  MIS_PWM0_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x4)
#define  MIS_PWM0_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x8)
#define  MIS_PWM0_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0xC)
#define  MIS_PWM1_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x10)
#define  MIS_PWM1_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x14)
#define  MIS_PWM1_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x18)
#define  MIS_PWM2_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x1C)
#define  MIS_PWM2_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x20)
#define  MIS_PWM2_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x24)
#define  MIS_PWM3_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x28)
#define  MIS_PWM3_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x2C)
#define  MIS_PWM3_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x30)
#define  MIS_PWM4_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x34)
#define  MIS_PWM4_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x38)
#define  MIS_PWM4_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x3C)
#define  MIS_PWM5_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x40)
#define  MIS_PWM5_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x44)
#define  MIS_PWM5_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x48)
#define  MIS_PWM6_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x4C)
#define  MIS_PWM6_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x50)
#define  MIS_PWM6_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x54)
#define  MIS_PWM7_CTRL_VADDR		(MIS_PWM_DB_CTRL_VADDR + 0x58)
#define  MIS_PWM7_TIMING_CTRL_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x5C)
#define  MIS_PWM7_DUTY_SET_VADDR	(MIS_PWM_DB_CTRL_VADDR + 0x60)
//#define  MIS_DUMMY_VADDR 		        (MIS_PWM_DB_CTRL_VADDR + 0x64)

#ifndef LITTLE_ENDIAN		/*apply BIG_ENDIAN */

/*======MACARTHUR3_DESIGNSPEC_MISC_PWM register structure define==========*/

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 pwm_w_db_en:1;
		RBus_UInt32 DB_RD_SEL:1;
		RBus_UInt32 res1:1;
		RBus_UInt32 pwm_w_db_mode:1;
		RBus_UInt32 pwm_global_delay_en:1;
		RBus_UInt32 res2:27;
	};
} pwm0_db_ctrl_RBUS;

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 pwm0l:1;
		RBus_UInt32 pwm0_ck:1;
		RBus_UInt32 pwm0_en:1;
		RBus_UInt32 pwm0_vs_rst_en:1;
		RBus_UInt32 pwm0_dut_8b:1;
		RBus_UInt32 pwm0_vs_delay_thr:21;
		RBus_UInt32 pwm0_vs_delay_en:1;
		RBus_UInt32 pwm0_w_db_wr:1;
		RBus_UInt32 res2:3;
		RBus_UInt32 pwm0_width_sel:1;
	};
} pwm0_ctrl_RBUS;

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 pwm0_cnt_mode:1;
		RBus_UInt32 pwm0_ck_sel_hs:1;
		RBus_UInt32 pwm0_ck_sel:1;
		RBus_UInt32 res1:1;
		RBus_UInt32 pwm0_cycle_max:4;
		RBus_UInt32 res2:10;
		RBus_UInt32 pwm0_m:2;
		RBus_UInt32 pwm0_n:12;
	};
} pwm0_timing_ctrl_RBUS;

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 res1:4;
		RBus_UInt32 pwm0_dut:12;
		RBus_UInt32 res2:4;
		RBus_UInt32 pwm0_totalcnt:12;
	};
} pwm0_duty_set_RBUS;

#else /*apply LITTLE_ENDIAN */

/*======MACARTHUR3_DESIGNSPEC_MISC_PWM register structure define==========*/

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 res1:27;
		RBus_UInt32 pwm_global_delay_en:1;
		RBus_UInt32 pwm_w_db_mode:1;
		RBus_UInt32 res2:1;
		RBus_UInt32 DB_RD_SEL:1;
		RBus_UInt32 pwm_w_db_en:1;
	};
} pwm0_db_ctrl_RBUS;

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 pwm0_width_sel:1;
		RBus_UInt32 res1:3;
		RBus_UInt32 pwm0_w_db_wr:1;
		RBus_UInt32 pwm0_vs_delay_en:1;
		RBus_UInt32 pwm0_vs_delay_thr:21;
		RBus_UInt32 pwm0_dut_8b:1;
		RBus_UInt32 pwm0_vs_rst_en:1;
		RBus_UInt32 pwm0_en:1;
		RBus_UInt32 pwm0_ck:1;
		RBus_UInt32 pwm0l:1;
	};
} pwm0_ctrl_RBUS;

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 pwm0_n:12;
		RBus_UInt32 pwm0_m:2;
		RBus_UInt32 res1:10;
		RBus_UInt32 pwm0_cycle_max:4;
		RBus_UInt32 res2:1;
		RBus_UInt32 pwm0_ck_sel:1;
		RBus_UInt32 pwm0_ck_sel_hs:1;
		RBus_UInt32 pwm0_cnt_mode:1;
	};
} pwm0_timing_ctrl_RBUS;

typedef union {
	RBus_UInt32 regValue;
	struct {
		RBus_UInt32 pwm0_totalcnt:12;
		RBus_UInt32 res1:4;
		RBus_UInt32 pwm0_dut:12;
		RBus_UInt32 res2:4;
	};
} pwm0_duty_set_RBUS;
#endif

struct rtk_pwm_reg_map_t {
	unsigned long CTRL;
	unsigned long TIMING_CTRL;
	unsigned long DUTY_SET;
};
typedef struct rtk_pwm_reg_map_t rtk_pwm_reg_map;

struct rtk_pwm_phy_t {
	const rtk_pwm_reg_map *p_reg_map;
};
typedef struct rtk_pwm_phy_t rtk_pwm_phy;

static const rtk_pwm_reg_map RTD_iso_pwm0_reg = {
	.CTRL = ISO_MIS_PWM0_CTRL_VADDR,
	.TIMING_CTRL = ISO_MIS_PWM0_TIMING_CTRL_VADDR,
	.DUTY_SET = ISO_MIS_PWM0_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_iso_pwm1_reg = {
	.CTRL = ISO_MIS_PWM1_CTRL_VADDR,
	.TIMING_CTRL = ISO_MIS_PWM1_TIMING_CTRL_VADDR,
	.DUTY_SET = ISO_MIS_PWM1_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm0_reg = {
	.CTRL = MIS_PWM0_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM0_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM0_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm1_reg = {
	.CTRL = MIS_PWM1_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM1_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM1_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm2_reg = {
	.CTRL = MIS_PWM2_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM2_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM2_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm3_reg = {
	.CTRL = MIS_PWM3_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM3_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM3_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm4_reg = {
	.CTRL = MIS_PWM4_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM4_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM4_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm5_reg = {
	.CTRL = MIS_PWM5_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM5_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM5_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm6_reg = {
	.CTRL = MIS_PWM6_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM6_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM6_DUTY_SET_VADDR,
};

static const rtk_pwm_reg_map RTD_mis_pwm7_reg = {
	.CTRL = MIS_PWM7_CTRL_VADDR,
	.TIMING_CTRL = MIS_PWM7_TIMING_CTRL_VADDR,
	.DUTY_SET = MIS_PWM7_DUTY_SET_VADDR,
};



static const rtk_pwm_phy pwm_iso_phy[] = {
	{&RTD_iso_pwm0_reg},
	{&RTD_iso_pwm1_reg},
};

static const rtk_pwm_phy pwm_mis_phy[] = {
	{&RTD_mis_pwm0_reg},
	{&RTD_mis_pwm1_reg},
	{&RTD_mis_pwm2_reg},
	{&RTD_mis_pwm3_reg},
	{&RTD_mis_pwm4_reg},
	{&RTD_mis_pwm5_reg},
	{&RTD_mis_pwm6_reg},
	{&RTD_mis_pwm7_reg},
};

#endif
