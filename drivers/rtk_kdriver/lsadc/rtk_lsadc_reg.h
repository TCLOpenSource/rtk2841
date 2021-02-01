/**
 **
 */

#ifndef _RTK_LSADC_REG_H_
#define _RTK_LSADC_REG_H_


#include "rtk_lsadc_reg_rtd284x.h"


#define  PAD_0_CONTROL		ST_PAD0_VADDR
#define  PAD_1_CONTROL		ST_PAD1_VADDR
#define  PAD_2_CONTROL		ST_PAD2_VADDR
#define  PAD_3_CONTROL		ST_PAD3_VADDR
#define  PAD_4_CONTROL		ST_PAD4_VADDR
#define  PAD_5_CONTROL		ST_PAD5_VADDR
#define  PAD_6_CONTROL		ST_PAD6_VADDR
#define  PAD_7_CONTROL		ST_PAD7_VADDR
#define  LSADC_CTRL		ST_LSADC_CTRL_VADDR
#define  LSADC_STATUS		ST_LSADC_STATUS_VADDR
#define  ANALOG_CTRL		ST_LSADC_ANALOG_CTRL_VADDR
#define  DEBUG_PORT		ST_LSADC_PERI_TOP_DEBUG_VADDR
#define  PAD5_COMPARE_SET0	LSADC_PAD5_LEVEL_SET0_VADDR
#define  PAD5_COMPARE_SET1	LSADC_PAD5_LEVEL_SET1_VADDR
#define  PAD5_COMPARE_SET2	LSADC_PAD5_LEVEL_SET2_VADDR
#define  PAD5_COMPARE_SET3	LSADC_PAD5_LEVEL_SET3_VADDR
#define  PAD5_COMPARE_SET4	LSADC_PAD5_LEVEL_SET4_VADDR
#define  PAD5_COMPARE_SET5	LSADC_PAD5_LEVEL_SET5_VADDR
#define  PAD6_COMPARE_SET0	LSADC_PAD6_LEVEL_SET0_VADDR
#define  PAD6_COMPARE_SET1	LSADC_PAD6_LEVEL_SET1_VADDR
#define  PAD6_COMPARE_SET2	LSADC_PAD6_LEVEL_SET2_VADDR
#define  PAD6_COMPARE_SET3	LSADC_PAD6_LEVEL_SET3_VADDR
#define  PAD6_COMPARE_SET4	LSADC_PAD6_LEVEL_SET4_VADDR
#define  PAD6_COMPARE_SET5	LSADC_PAD6_LEVEL_SET5_VADDR
#define  PAD7_COMPARE_SET0	LSADC_PAD7_LEVEL_SET0_VADDR
#define  PAD7_COMPARE_SET1	LSADC_PAD7_LEVEL_SET1_VADDR
#define  PAD7_COMPARE_SET2	LSADC_PAD7_LEVEL_SET2_VADDR
#define  PAD7_COMPARE_SET3	LSADC_PAD7_LEVEL_SET3_VADDR
#define  PAD7_COMPARE_SET4	LSADC_PAD7_LEVEL_SET4_VADDR
#define  PAD7_COMPARE_SET5	LSADC_PAD7_LEVEL_SET5_VADDR
#define  PAD5_COMPARE_STATUS	LSADC_INT_PAD5_VADDR
#define  PAD6_COMPARE_STATUS	LSADC_INT_PAD6_VADDR
#define  PAD7_COMPARE_STATUS	LSADC_INT_PAD7_VADDR


typedef struct _rtk_lsdac_reg_map_t {
    unsigned int padCtrl;
    unsigned int lsadc_ctrl;
    unsigned int status;
    unsigned int analog_ctrl;
    unsigned int padCompare0;
    unsigned int padCompare1;
    unsigned int padCompare2;
    unsigned int padCompare3;
    unsigned int padCompare4;
    unsigned int padCompare5;
    unsigned int compareStatus;
} rtk_lsdac_reg_map ;


typedef struct _rtk_lsadc_phy_t {
	const rtk_lsdac_reg_map *p_reg_map;
} rtk_lsadc_phy;




static const rtk_lsdac_reg_map lsadc_0_reg = {
	 .padCtrl          = PAD_0_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD5_COMPARE_SET0,
	 .padCompare1  = PAD5_COMPARE_SET1,
	 .padCompare2  = PAD5_COMPARE_SET2,
	 .padCompare3  = PAD5_COMPARE_SET3,
	 .padCompare4  = PAD5_COMPARE_SET4,
	 .padCompare5  = PAD5_COMPARE_SET5,
	 .compareStatus = PAD5_COMPARE_STATUS,
};

static const rtk_lsdac_reg_map lsadc_1_reg = {
	 .padCtrl          = PAD_1_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD5_COMPARE_SET0,
	 .padCompare1  = PAD5_COMPARE_SET1,
	 .padCompare2  = PAD5_COMPARE_SET2,
	 .padCompare3  = PAD5_COMPARE_SET3,
	 .padCompare4  = PAD5_COMPARE_SET4,
	 .padCompare5  = PAD5_COMPARE_SET5,
	 .compareStatus = PAD5_COMPARE_STATUS,
};


static const rtk_lsdac_reg_map lsadc_2_reg = {
	 .padCtrl          = PAD_2_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD5_COMPARE_SET0,
	 .padCompare1  = PAD5_COMPARE_SET1,
	 .padCompare2  = PAD5_COMPARE_SET2,
	 .padCompare3  = PAD5_COMPARE_SET3,
	 .padCompare4  = PAD5_COMPARE_SET4,
	 .padCompare5  = PAD5_COMPARE_SET5,
	 .compareStatus = PAD5_COMPARE_STATUS,
};



static const rtk_lsdac_reg_map lsadc_3_reg = {
	 .padCtrl          = PAD_3_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD5_COMPARE_SET0,
	 .padCompare1  = PAD5_COMPARE_SET1,
	 .padCompare2  = PAD5_COMPARE_SET2,
	 .padCompare3  = PAD5_COMPARE_SET3,
	 .padCompare4  = PAD5_COMPARE_SET4,
	 .padCompare5  = PAD5_COMPARE_SET5,
	 .compareStatus = PAD5_COMPARE_STATUS,
};



static const rtk_lsdac_reg_map lsadc_4_reg = {
	 .padCtrl          = PAD_4_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD5_COMPARE_SET0,
	 .padCompare1  = PAD5_COMPARE_SET1,
	 .padCompare2  = PAD5_COMPARE_SET2,
	 .padCompare3  = PAD5_COMPARE_SET3,
	 .padCompare4  = PAD5_COMPARE_SET4,
	 .padCompare5  = PAD5_COMPARE_SET5,
	 .compareStatus = PAD5_COMPARE_STATUS,
};



static const rtk_lsdac_reg_map lsadc_5_reg = {
	 .padCtrl          = PAD_5_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD5_COMPARE_SET0,
	 .padCompare1  = PAD5_COMPARE_SET1,
	 .padCompare2  = PAD5_COMPARE_SET2,
	 .padCompare3  = PAD5_COMPARE_SET3,
	 .padCompare4  = PAD5_COMPARE_SET4,
	 .padCompare5  = PAD5_COMPARE_SET5,
	 .compareStatus = PAD5_COMPARE_STATUS,
};


static const rtk_lsdac_reg_map lsadc_6_reg = {
	 .padCtrl          = PAD_6_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD6_COMPARE_SET0,
	 .padCompare1  = PAD6_COMPARE_SET1,
	 .padCompare2  = PAD6_COMPARE_SET2,
	 .padCompare3  = PAD6_COMPARE_SET3,
	 .padCompare4  = PAD6_COMPARE_SET4,
	 .padCompare5  = PAD6_COMPARE_SET5,
	 .compareStatus = PAD6_COMPARE_STATUS,
};


static const rtk_lsdac_reg_map lsadc_7_reg = {
	 .padCtrl          = PAD_7_CONTROL,
	 .lsadc_ctrl       = LSADC_CTRL,
	 .status            = LSADC_STATUS,
	 .analog_ctrl     = ANALOG_CTRL,
	 .padCompare0  = PAD7_COMPARE_SET0,
	 .padCompare1  = PAD7_COMPARE_SET1,
	 .padCompare2  = PAD7_COMPARE_SET2,
	 .padCompare3  = PAD7_COMPARE_SET3,
	 .padCompare4  = PAD7_COMPARE_SET4,
	 .padCompare5  = PAD7_COMPARE_SET5,
	 .compareStatus = PAD7_COMPARE_STATUS,
};

static const rtk_lsadc_phy lsadcArray[] = {

	{&lsadc_0_reg},
	{&lsadc_1_reg},
	{&lsadc_2_reg},
	{&lsadc_3_reg},
	{&lsadc_4_reg},
	{&lsadc_5_reg},
	{&lsadc_6_reg},
	{&lsadc_7_reg},
};




/*
typedef enum {
	PCB_LSADC_TYPE_VOLTAGE,
	PCB_LSADC_TYPE_CURRENT,
	PCB_LSADC_TYPE_UNDEF,
} PCB_LSADC_TYPE_T;
*/


#endif


