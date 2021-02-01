/**
* @file rbusPinmuxReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PINMUX_REG_H_
#define _RBUS_PINMUX_REG_H_

#include "rbusTypes.h"



//  PINMUX Register Address



#define  PINMUX_GPIO_CFG_0_VADDR                            	(0xb8000800)
#define  PINMUX_GPIO_CFG_1_VADDR                            	(0xb8000804)
#define  PINMUX_GPIO_CFG_2_VADDR                            	(0xb8000808)
#define  PINMUX_GPIO_CFG_3_VADDR                            	(0xb800080c)
#define  PINMUX_GPIO_CFG_4_VADDR                            	(0xb8000810)
#define  PINMUX_GPIO_CFG_5_VADDR                            	(0xb8000814)
#define  PINMUX_GPIO_CFG_6_VADDR                            	(0xb8000818)
#define  PINMUX_GPIO_CFG_7_VADDR                            	(0xb800081c)
#define  PINMUX_GPIO_CFG_8_VADDR                            	(0xb8000820)
#define  PINMUX_GPIO_CFG_9_VADDR                            	(0xb8000824)
#define  PINMUX_GPIO_CFG_10_VADDR                           	(0xb8000828)
#define  PINMUX_GPIO_CFG_11_VADDR                           	(0xb800082c)
#define  PINMUX_GPIO_CFG_12_VADDR                           	(0xb8000830)
#define  PINMUX_GPIO_CFG_13_VADDR                           	(0xb8000834)
#define  PINMUX_GPIO_CFG_14_VADDR                           	(0xb8000838)
#define  PINMUX_GPIO_CFG_15_VADDR                           	(0xb800083c)
#define  PINMUX_GPIO_CFG_16_VADDR                           	(0xb8000840)
#define  PINMUX_GPIO_CFG_17_VADDR                           	(0xb8000844)
#define  PINMUX_GPIO_CFG_18_VADDR                           	(0xb8000848)
#define  PINMUX_GPIO_CFG_19_VADDR                           	(0xb800084c)
#define  PINMUX_LVDS_CFG_0_VADDR                            	(0xb8000860)
#define  PINMUX_LVDS_CFG_1_VADDR                            	(0xb8000864)
#define  PINMUX_LVDS_CFG_2_VADDR                            	(0xb8000868)
#define  PINMUX_LVDS_CFG_3_VADDR                            	(0xb800086c)
#define  PINMUX_HV_CFG_VADDR                                	(0xb8000870)
#define  PINMUX_YPP_ADC_CFG_0_VADDR                         	(0xb8000880)
#define  PINMUX_YPP_ADC_CFG_1_VADDR                         	(0xb8000884)
#define  PINMUX_ADC_CFG_VADDR                               	(0xb800088c)
#define  PINMUX_SCART_FSW_CFG_VD_DAC_CFG_VADDR              	(0xb8000890)
#define  PINMUX_BB_CFG_0_VADDR                              	(0xb8000898)
#define  PINMUX_BB_CFG_1_VADDR                              	(0xb800089c)
#define  PINMUX_PIN_MUX_CTRL0_VADDR                         	(0xb80008a0)
#define  PINMUX_PIN_MUX_CTRL1_VADDR                         	(0xb80008a4)
#define  PINMUX_PIN_MUX_CTRL2_VADDR                         	(0xb80008a8)
#define  PINMUX_SCHMIDT_TRIGGER_0_VADDR                     	(0xb80008b0)
#define  PINMUX_SCHMIDT_TRIGGER_1_VADDR                     	(0xb80008b4)
#define  PINMUX_SCHMIDT_TRIGGER_2_VADDR                     	(0xb80008b8)
#define  PINMUX_MAIN_TEST_PIN_CTRL_VADDR                    	(0xb80008c0)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PINMUX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_0_ps:4;
        RBus_UInt32  gpio_0_pu:1;
        RBus_UInt32  gpio_0_pd:1;
        RBus_UInt32  gpio_0_ds:1;
        RBus_UInt32  gpio_0_sr:1;
        RBus_UInt32  gpio_1_ps:4;
        RBus_UInt32  gpio_1_pu:1;
        RBus_UInt32  gpio_1_pd:1;
        RBus_UInt32  gpio_1_ds:1;
        RBus_UInt32  gpio_1_sr:1;
        RBus_UInt32  gpio_2_ps:4;
        RBus_UInt32  gpio_2_pu:1;
        RBus_UInt32  gpio_2_pd:1;
        RBus_UInt32  gpio_2_ds:1;
        RBus_UInt32  gpio_2_sr:1;
        RBus_UInt32  gpio_3_ps:4;
        RBus_UInt32  gpio_3_pu:1;
        RBus_UInt32  gpio_3_pd:1;
        RBus_UInt32  gpio_3_ds:1;
        RBus_UInt32  gpio_3_sr:1;
    };
}pinmux_gpio_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_4_ps:4;
        RBus_UInt32  gpio_4_pu:1;
        RBus_UInt32  gpio_4_pd:1;
        RBus_UInt32  gpio_4_ds:1;
        RBus_UInt32  gpio_4_sr:1;
        RBus_UInt32  gpio_5_ps:4;
        RBus_UInt32  gpio_5_pu:1;
        RBus_UInt32  gpio_5_pd:1;
        RBus_UInt32  gpio_5_ds:1;
        RBus_UInt32  gpio_5_sr:1;
        RBus_UInt32  gpio_6_ps:4;
        RBus_UInt32  gpio_6_pu:1;
        RBus_UInt32  gpio_6_pd:1;
        RBus_UInt32  gpio_6_ds:1;
        RBus_UInt32  gpio_6_sr:1;
        RBus_UInt32  gpio_7_ps:4;
        RBus_UInt32  gpio_7_pu:1;
        RBus_UInt32  gpio_7_pd:1;
        RBus_UInt32  gpio_7_ds:1;
        RBus_UInt32  gpio_7_sr:1;
    };
}pinmux_gpio_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_8_ps:4;
        RBus_UInt32  gpio_8_pu:1;
        RBus_UInt32  gpio_8_pd:1;
        RBus_UInt32  gpio_8_ds:1;
        RBus_UInt32  gpio_8_sr:1;
        RBus_UInt32  gpio_9_ps:4;
        RBus_UInt32  gpio_9_pu:1;
        RBus_UInt32  gpio_9_pd:1;
        RBus_UInt32  gpio_9_ds:1;
        RBus_UInt32  gpio_9_sr:1;
        RBus_UInt32  gpio_10_ps:4;
        RBus_UInt32  gpio_10_pu:1;
        RBus_UInt32  gpio_10_pd:1;
        RBus_UInt32  gpio_10_ds:1;
        RBus_UInt32  gpio_10_sr:1;
        RBus_UInt32  gpio_11_ps:4;
        RBus_UInt32  gpio_11_pu:1;
        RBus_UInt32  gpio_11_pd:1;
        RBus_UInt32  gpio_11_ds:1;
        RBus_UInt32  gpio_11_sr:1;
    };
}pinmux_gpio_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_12_ps:4;
        RBus_UInt32  gpio_12_pu:1;
        RBus_UInt32  gpio_12_pd:1;
        RBus_UInt32  gpio_12_ds:1;
        RBus_UInt32  gpio_12_sr:1;
        RBus_UInt32  gpio_13_ps:4;
        RBus_UInt32  gpio_13_pu:1;
        RBus_UInt32  gpio_13_pd:1;
        RBus_UInt32  gpio_13_ds:1;
        RBus_UInt32  gpio_13_sr:1;
        RBus_UInt32  gpio_14_ps:4;
        RBus_UInt32  gpio_14_pu:1;
        RBus_UInt32  gpio_14_pd:1;
        RBus_UInt32  gpio_14_ds:1;
        RBus_UInt32  gpio_14_sr:1;
        RBus_UInt32  gpio_15_ps:4;
        RBus_UInt32  gpio_15_pu:1;
        RBus_UInt32  gpio_15_pd:1;
        RBus_UInt32  gpio_15_ds:1;
        RBus_UInt32  gpio_15_sr:1;
    };
}pinmux_gpio_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_16_ps:4;
        RBus_UInt32  gpio_16_pu:1;
        RBus_UInt32  gpio_16_pd:1;
        RBus_UInt32  gpio_16_ds:1;
        RBus_UInt32  gpio_16_sr:1;
        RBus_UInt32  gpio_17_ps:4;
        RBus_UInt32  gpio_17_pu:1;
        RBus_UInt32  gpio_17_pd:1;
        RBus_UInt32  gpio_17_ds:1;
        RBus_UInt32  gpio_17_sr:1;
        RBus_UInt32  gpio_18_ps:4;
        RBus_UInt32  gpio_18_pu:1;
        RBus_UInt32  gpio_18_pd:1;
        RBus_UInt32  gpio_18_ds:1;
        RBus_UInt32  gpio_18_sr:1;
        RBus_UInt32  gpio_19_ps:4;
        RBus_UInt32  gpio_19_pu:1;
        RBus_UInt32  gpio_19_pd:1;
        RBus_UInt32  gpio_19_ds:1;
        RBus_UInt32  gpio_19_sr:1;
    };
}pinmux_gpio_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_20_ps:4;
        RBus_UInt32  gpio_20_pu:1;
        RBus_UInt32  gpio_20_pd:1;
        RBus_UInt32  gpio_20_ds:1;
        RBus_UInt32  gpio_20_sr:1;
        RBus_UInt32  gpio_21_ps:4;
        RBus_UInt32  gpio_21_pu:1;
        RBus_UInt32  gpio_21_pd:1;
        RBus_UInt32  gpio_21_ds:1;
        RBus_UInt32  gpio_21_sr:1;
        RBus_UInt32  gpio_22_ps:4;
        RBus_UInt32  gpio_22_pu:1;
        RBus_UInt32  gpio_22_pd:1;
        RBus_UInt32  gpio_22_ds:1;
        RBus_UInt32  gpio_22_sr:1;
        RBus_UInt32  gpio_23_ps:4;
        RBus_UInt32  gpio_23_pu:1;
        RBus_UInt32  gpio_23_pd:1;
        RBus_UInt32  gpio_23_ds:1;
        RBus_UInt32  gpio_23_sr:1;
    };
}pinmux_gpio_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_24_ps:4;
        RBus_UInt32  gpio_24_pu:1;
        RBus_UInt32  gpio_24_pd:1;
        RBus_UInt32  gpio_24_ds:1;
        RBus_UInt32  gpio_24_sr:1;
        RBus_UInt32  gpio_25_ps:4;
        RBus_UInt32  gpio_25_pu:1;
        RBus_UInt32  gpio_25_pd:1;
        RBus_UInt32  gpio_25_ds:1;
        RBus_UInt32  gpio_25_sr:1;
        RBus_UInt32  gpio_26_ps:4;
        RBus_UInt32  gpio_26_pu:1;
        RBus_UInt32  gpio_26_pd:1;
        RBus_UInt32  gpio_26_ds:1;
        RBus_UInt32  gpio_26_sr:1;
        RBus_UInt32  gpio_27_ps:4;
        RBus_UInt32  gpio_27_pu:1;
        RBus_UInt32  gpio_27_pd:1;
        RBus_UInt32  gpio_27_ds:1;
        RBus_UInt32  gpio_27_sr:1;
    };
}pinmux_gpio_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_28_ps:4;
        RBus_UInt32  gpio_28_pu:1;
        RBus_UInt32  gpio_28_pd:1;
        RBus_UInt32  gpio_28_ds:1;
        RBus_UInt32  gpio_28_sr:1;
        RBus_UInt32  gpio_29_ps:4;
        RBus_UInt32  gpio_29_pu:1;
        RBus_UInt32  gpio_29_pd:1;
        RBus_UInt32  gpio_29_ds:1;
        RBus_UInt32  gpio_29_sr:1;
        RBus_UInt32  gpio_30_ps:4;
        RBus_UInt32  gpio_30_pu:1;
        RBus_UInt32  gpio_30_pd:1;
        RBus_UInt32  gpio_30_ds:1;
        RBus_UInt32  gpio_30_sr:1;
        RBus_UInt32  gpio_31_ps:4;
        RBus_UInt32  gpio_31_pu:1;
        RBus_UInt32  gpio_31_pd:1;
        RBus_UInt32  gpio_31_ds:1;
        RBus_UInt32  gpio_31_sr:1;
    };
}pinmux_gpio_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_32_ps:4;
        RBus_UInt32  gpio_32_pu:1;
        RBus_UInt32  gpio_32_pd:1;
        RBus_UInt32  gpio_32_ds:1;
        RBus_UInt32  gpio_32_sr:1;
        RBus_UInt32  gpio_33_ps:4;
        RBus_UInt32  gpio_33_pu:1;
        RBus_UInt32  gpio_33_pd:1;
        RBus_UInt32  gpio_33_ds:1;
        RBus_UInt32  gpio_33_sr:1;
        RBus_UInt32  res1:16;
    };
}pinmux_gpio_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_34_ps:4;
        RBus_UInt32  gpio_34_pu:1;
        RBus_UInt32  gpio_34_pd:1;
        RBus_UInt32  gpio_34_ds:1;
        RBus_UInt32  gpio_34_sr:1;
        RBus_UInt32  gpio_35_ps:4;
        RBus_UInt32  gpio_35_pu:1;
        RBus_UInt32  gpio_35_pd:1;
        RBus_UInt32  gpio_35_ds:1;
        RBus_UInt32  gpio_35_sr:1;
        RBus_UInt32  gpio_36_ps:4;
        RBus_UInt32  gpio_36_pu:1;
        RBus_UInt32  gpio_36_pd:1;
        RBus_UInt32  gpio_36_ds:1;
        RBus_UInt32  gpio_36_sr:1;
        RBus_UInt32  gpio_37_ps:4;
        RBus_UInt32  gpio_37_pu:1;
        RBus_UInt32  gpio_37_pd:1;
        RBus_UInt32  gpio_37_ds:1;
        RBus_UInt32  gpio_37_sr:1;
    };
}pinmux_gpio_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_38_ps:4;
        RBus_UInt32  gpio_38_pu:1;
        RBus_UInt32  gpio_38_pd:1;
        RBus_UInt32  gpio_38_ds:1;
        RBus_UInt32  gpio_38_sr:1;
        RBus_UInt32  gpio_39_ps:4;
        RBus_UInt32  gpio_39_pu:1;
        RBus_UInt32  gpio_39_pd:1;
        RBus_UInt32  gpio_39_ds:1;
        RBus_UInt32  gpio_39_sr:1;
        RBus_UInt32  gpio_40_ps:4;
        RBus_UInt32  gpio_40_pu:1;
        RBus_UInt32  gpio_40_pd:1;
        RBus_UInt32  gpio_40_ds:1;
        RBus_UInt32  gpio_40_sr:1;
        RBus_UInt32  gpio_41_ps:4;
        RBus_UInt32  gpio_41_pu:1;
        RBus_UInt32  gpio_41_pd:1;
        RBus_UInt32  gpio_41_ds:1;
        RBus_UInt32  gpio_41_sr:1;
    };
}pinmux_gpio_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_42_ps:4;
        RBus_UInt32  gpio_42_pu:1;
        RBus_UInt32  gpio_42_pd:1;
        RBus_UInt32  gpio_42_ds:1;
        RBus_UInt32  gpio_42_sr:1;
        RBus_UInt32  gpio_43_ps:4;
        RBus_UInt32  gpio_43_pu:1;
        RBus_UInt32  gpio_43_pd:1;
        RBus_UInt32  gpio_43_ds:1;
        RBus_UInt32  gpio_43_sr:1;
        RBus_UInt32  gpio_44_ps:4;
        RBus_UInt32  gpio_44_pu:1;
        RBus_UInt32  gpio_44_pd:1;
        RBus_UInt32  gpio_44_ds:1;
        RBus_UInt32  gpio_44_sr:1;
        RBus_UInt32  gpio_45_ps:4;
        RBus_UInt32  gpio_45_pu:1;
        RBus_UInt32  gpio_45_pd:1;
        RBus_UInt32  gpio_45_ds:1;
        RBus_UInt32  gpio_45_sr:1;
    };
}pinmux_gpio_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_46_ps:4;
        RBus_UInt32  gpio_46_pu:1;
        RBus_UInt32  gpio_46_pd:1;
        RBus_UInt32  gpio_46_ds:1;
        RBus_UInt32  gpio_46_sr:1;
        RBus_UInt32  gpio_47_ps:4;
        RBus_UInt32  gpio_47_pu:1;
        RBus_UInt32  gpio_47_pd:1;
        RBus_UInt32  gpio_47_ds:1;
        RBus_UInt32  gpio_47_sr:1;
        RBus_UInt32  gpio_48_ps:4;
        RBus_UInt32  gpio_48_pu:1;
        RBus_UInt32  gpio_48_pd:1;
        RBus_UInt32  gpio_48_ds:1;
        RBus_UInt32  gpio_48_sr:1;
        RBus_UInt32  gpio_49_ps:4;
        RBus_UInt32  gpio_49_pu:1;
        RBus_UInt32  gpio_49_pd:1;
        RBus_UInt32  gpio_49_ds:1;
        RBus_UInt32  gpio_49_sr:1;
    };
}pinmux_gpio_cfg_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_50_ps:4;
        RBus_UInt32  gpio_50_pu:1;
        RBus_UInt32  gpio_50_pd:1;
        RBus_UInt32  gpio_50_ds:1;
        RBus_UInt32  gpio_50_sr:1;
        RBus_UInt32  gpio_51_ps:4;
        RBus_UInt32  gpio_51_pu:1;
        RBus_UInt32  gpio_51_pd:1;
        RBus_UInt32  gpio_51_ds:1;
        RBus_UInt32  gpio_51_sr:1;
        RBus_UInt32  gpio_52_ps:4;
        RBus_UInt32  gpio_52_pu:1;
        RBus_UInt32  gpio_52_pd:1;
        RBus_UInt32  gpio_52_ds:1;
        RBus_UInt32  gpio_52_sr:1;
        RBus_UInt32  gpio_53_ps:4;
        RBus_UInt32  gpio_53_pu:1;
        RBus_UInt32  gpio_53_pd:1;
        RBus_UInt32  gpio_53_ds:1;
        RBus_UInt32  gpio_53_sr:1;
    };
}pinmux_gpio_cfg_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_54_ps:4;
        RBus_UInt32  gpio_54_pu:1;
        RBus_UInt32  gpio_54_pd:1;
        RBus_UInt32  gpio_54_ds:1;
        RBus_UInt32  gpio_54_sr:1;
        RBus_UInt32  gpio_55_ps:4;
        RBus_UInt32  gpio_55_pu:1;
        RBus_UInt32  gpio_55_pd:1;
        RBus_UInt32  gpio_55_ds:1;
        RBus_UInt32  gpio_55_sr:1;
        RBus_UInt32  gpio_56_ps:4;
        RBus_UInt32  gpio_56_pu:1;
        RBus_UInt32  gpio_56_pd:1;
        RBus_UInt32  gpio_56_ds:1;
        RBus_UInt32  gpio_56_sr:1;
        RBus_UInt32  gpio_57_ps:4;
        RBus_UInt32  gpio_57_pu:1;
        RBus_UInt32  gpio_57_pd:1;
        RBus_UInt32  gpio_57_ds:1;
        RBus_UInt32  gpio_57_sr:1;
    };
}pinmux_gpio_cfg_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_58_ps:4;
        RBus_UInt32  gpio_58_pu:1;
        RBus_UInt32  gpio_58_pd:1;
        RBus_UInt32  gpio_58_ds:1;
        RBus_UInt32  gpio_58_sr:1;
        RBus_UInt32  gpio_59_ps:4;
        RBus_UInt32  gpio_59_pu:1;
        RBus_UInt32  gpio_59_pd:1;
        RBus_UInt32  gpio_59_ds:1;
        RBus_UInt32  gpio_59_sr:1;
        RBus_UInt32  gpio_60_ps:4;
        RBus_UInt32  gpio_60_pu:1;
        RBus_UInt32  gpio_60_pd:1;
        RBus_UInt32  gpio_60_ds:1;
        RBus_UInt32  gpio_60_sr:1;
        RBus_UInt32  gpio_61_ps:4;
        RBus_UInt32  gpio_61_pu:1;
        RBus_UInt32  gpio_61_pd:1;
        RBus_UInt32  gpio_61_ds:1;
        RBus_UInt32  gpio_61_sr:1;
    };
}pinmux_gpio_cfg_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_62_ps:4;
        RBus_UInt32  gpio_62_pu:1;
        RBus_UInt32  gpio_62_pd:1;
        RBus_UInt32  gpio_62_ds:1;
        RBus_UInt32  gpio_62_sr:1;
        RBus_UInt32  gpio_63_ps:4;
        RBus_UInt32  gpio_63_pu:1;
        RBus_UInt32  gpio_63_pd:1;
        RBus_UInt32  gpio_63_ds:1;
        RBus_UInt32  gpio_63_sr:1;
        RBus_UInt32  gpio_64_ps:4;
        RBus_UInt32  gpio_64_pu:1;
        RBus_UInt32  gpio_64_pd:1;
        RBus_UInt32  gpio_64_ds:1;
        RBus_UInt32  gpio_64_sr:1;
        RBus_UInt32  gpio_65_ps:4;
        RBus_UInt32  gpio_65_pu:1;
        RBus_UInt32  gpio_65_pd:1;
        RBus_UInt32  gpio_65_ds:1;
        RBus_UInt32  gpio_65_sr:1;
    };
}pinmux_gpio_cfg_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_66_ps:4;
        RBus_UInt32  gpio_66_pu:1;
        RBus_UInt32  gpio_66_pd:1;
        RBus_UInt32  gpio_66_ds:1;
        RBus_UInt32  gpio_66_sr:1;
        RBus_UInt32  gpio_67_ps:4;
        RBus_UInt32  gpio_67_pu:1;
        RBus_UInt32  gpio_67_pd:1;
        RBus_UInt32  gpio_67_ds:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  gpio_68_ps:4;
        RBus_UInt32  gpio_68_pu:1;
        RBus_UInt32  gpio_68_pd:1;
        RBus_UInt32  gpio_68_ds:1;
        RBus_UInt32  gpio_68_sr:1;
        RBus_UInt32  gpio_69_ps:4;
        RBus_UInt32  gpio_69_pu:1;
        RBus_UInt32  gpio_69_pd:1;
        RBus_UInt32  gpio_69_ds:1;
        RBus_UInt32  gpio_69_sr:1;
    };
}pinmux_gpio_cfg_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_70_ps:4;
        RBus_UInt32  gpio_70_pu:1;
        RBus_UInt32  gpio_70_pd:1;
        RBus_UInt32  gpio_70_ds:1;
        RBus_UInt32  gpio_70_sr:1;
        RBus_UInt32  gpio_71_ps:4;
        RBus_UInt32  gpio_71_pu:1;
        RBus_UInt32  gpio_71_pd:1;
        RBus_UInt32  gpio_71_ds:1;
        RBus_UInt32  gpio_71_sr:1;
        RBus_UInt32  gpio_72_ps:4;
        RBus_UInt32  gpio_72_pu:1;
        RBus_UInt32  gpio_72_pd:1;
        RBus_UInt32  gpio_72_ds:1;
        RBus_UInt32  gpio_72_sr:1;
        RBus_UInt32  gpio_73_ps:4;
        RBus_UInt32  gpio_73_pu:1;
        RBus_UInt32  gpio_73_pd:1;
        RBus_UInt32  gpio_73_ds:1;
        RBus_UInt32  gpio_73_sr:1;
    };
}pinmux_gpio_cfg_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_74_ps:4;
        RBus_UInt32  gpio_74_pu:1;
        RBus_UInt32  gpio_74_pd:1;
        RBus_UInt32  gpio_74_ds:1;
        RBus_UInt32  gpio_74_sr:1;
        RBus_UInt32  gpio_75_ps:4;
        RBus_UInt32  gpio_75_pu:1;
        RBus_UInt32  gpio_75_pd:1;
        RBus_UInt32  gpio_75_ds:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:16;
    };
}pinmux_gpio_cfg_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_gp_ps:4;
        RBus_UInt32  lvds_a_gn_ps:4;
        RBus_UInt32  lvds_a_fp_ps:4;
        RBus_UInt32  lvds_a_fn_ps:4;
        RBus_UInt32  lvds_a_ep_ps:4;
        RBus_UInt32  lvds_a_en_ps:4;
        RBus_UInt32  lvds_a_dp_ps:4;
        RBus_UInt32  lvds_a_dn_ps:4;
    };
}pinmux_lvds_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_cp_ps:4;
        RBus_UInt32  lvds_a_cn_ps:4;
        RBus_UInt32  lvds_a_bp_ps:4;
        RBus_UInt32  lvds_a_bn_ps:4;
        RBus_UInt32  lvds_a_ap_ps:4;
        RBus_UInt32  lvds_a_an_ps:4;
        RBus_UInt32  res1:8;
    };
}pinmux_lvds_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_gp_ps:4;
        RBus_UInt32  lvds_b_gn_ps:4;
        RBus_UInt32  lvds_b_fp_ps:4;
        RBus_UInt32  lvds_b_fn_ps:4;
        RBus_UInt32  lvds_b_ep_ps:4;
        RBus_UInt32  lvds_b_en_ps:4;
        RBus_UInt32  lvds_b_dp_ps:4;
        RBus_UInt32  lvds_b_dn_ps:4;
    };
}pinmux_lvds_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_cp_ps:4;
        RBus_UInt32  lvds_b_cn_ps:4;
        RBus_UInt32  lvds_b_bp_ps:4;
        RBus_UInt32  lvds_b_bn_ps:4;
        RBus_UInt32  lvds_b_ap_ps:4;
        RBus_UInt32  lvds_b_an_ps:4;
        RBus_UInt32  res1:8;
    };
}pinmux_lvds_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_ps:4;
        RBus_UInt32  hsync_ps:4;
        RBus_UInt32  res1:22;
        RBus_UInt32  vsync_gpi_en:1;
        RBus_UInt32  hsync_gpi_en:1;
    };
}pinmux_hv_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_0p_ps:4;
        RBus_UInt32  vin_bn_ps:4;
        RBus_UInt32  vin_1p_ps:4;
        RBus_UInt32  vin_2p_ps:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  vin_0p_gpi_en:1;
        RBus_UInt32  vin_bn_gpi_en:1;
        RBus_UInt32  vin_1p_gpi_en:1;
        RBus_UInt32  vin_2p_gpi_en:1;
    };
}pinmux_ypp_adc_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_6p_ps:4;
        RBus_UInt32  vin_y1n_ps:4;
        RBus_UInt32  vin_7p_ps:4;
        RBus_UInt32  vin_8p_ps:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  vin_6p_gpi_en:1;
        RBus_UInt32  vin_y1n_gpi_en:1;
        RBus_UInt32  vin_7p_gpi_en:1;
        RBus_UInt32  vin_8p_gpi_en:1;
    };
}pinmux_ypp_adc_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_9p_ps:4;
        RBus_UInt32  vin_12p_ps:4;
        RBus_UInt32  vin_a0n_ps:4;
        RBus_UInt32  vin_a2n_ps:4;
        RBus_UInt32  vin_10p_ps:4;
        RBus_UInt32  vin_13p_ps:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  vin_9p_pi_en:1;
        RBus_UInt32  vin_12p_gpi_en:1;
        RBus_UInt32  vin_a0n_gpi_en:1;
        RBus_UInt32  vin_a2n_gpi_en:1;
        RBus_UInt32  vin_10p_gpi_en:1;
        RBus_UInt32  vin_13p_gpi_en:1;
    };
}pinmux_adc_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scart_fsw_0_ps:4;
        RBus_UInt32  vdbs_out_ps:4;
        RBus_UInt32  vdac_out_ps:4;
        RBus_UInt32  res1:7;
        RBus_UInt32  hsdm2_gpi_en:1;
        RBus_UInt32  hsdp2_gpi_en:1;
        RBus_UInt32  usb3_hsdp_ps:4;
        RBus_UInt32  usb3_hsdm_ps:4;
        RBus_UInt32  scart_fsw_0_gpi_en:1;
        RBus_UInt32  vdbs_out_gpi_en:1;
        RBus_UInt32  vdac_out_gpi_en:1;
    };
}pinmux_scart_fsw_cfg_vd_dac_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_ai2l_ps:4;
        RBus_UInt32  bb_ai2r_ps:4;
        RBus_UInt32  bb_ai3l_ps:4;
        RBus_UInt32  bb_ai3r_ps:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  bb_ai2l_gpi_en:1;
        RBus_UInt32  bb_ai2r_gpi_en:1;
        RBus_UInt32  bb_ai3l_gpi_en:1;
        RBus_UInt32  bb_ai3r_gpi_en:1;
    };
}pinmux_bb_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_aiol_ps:4;
        RBus_UInt32  bb_aior_ps:4;
        RBus_UInt32  bb_hpol_ps:4;
        RBus_UInt32  bb_hpor_ps:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  bb_aiol_gpi_en:1;
        RBus_UInt32  bb_aior_gpi_en:1;
        RBus_UInt32  bb_hpol_gpi_en:1;
        RBus_UInt32  bb_hpor_gpi_en:1;
    };
}pinmux_bb_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tp0_mux_selection:3;
        RBus_UInt32  tp1_mux_selection:3;
        RBus_UInt32  tp2_mux_selection:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  i2c2_in_sel:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  i2c1_in_sel:3;
        RBus_UInt32  i2s_in_sel:2;
        RBus_UInt32  antoe_in_sel:2;
        RBus_UInt32  antrx_in_sel:2;
        RBus_UInt32  anttx_in_sel:2;
        RBus_UInt32  sc_in_sel:3;
    };
}pinmux_pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ld_spi0_p2_sck_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_spi0_p3_sdo_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  ld_spi0_p4_sdi_sel:2;
        RBus_UInt32  res4:7;
    };
}pinmux_pin_mux_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spdif_in_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  epi_lock_in_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  demod_i2c_relay_in_sel:2;
        RBus_UInt32  usb_pwr_flag0_in_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  cr_sd_in_sel:2;
        RBus_UInt32  uart1_rxdi_in_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  uart2_rxdi_in_sel:3;
        RBus_UInt32  res5:8;
        RBus_UInt32  phif_enable:1;
    };
}pinmux_pin_mux_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_0_smt:1;
        RBus_UInt32  gpio_1_smt:1;
        RBus_UInt32  gpio_2_smt:1;
        RBus_UInt32  gpio_3_smt:1;
        RBus_UInt32  gpio_4_smt:1;
        RBus_UInt32  gpio_5_smt:1;
        RBus_UInt32  gpio_6_smt:1;
        RBus_UInt32  gpio_7_smt:1;
        RBus_UInt32  gpio_8_smt:1;
        RBus_UInt32  gpio_9_smt:1;
        RBus_UInt32  gpio_10_smt:1;
        RBus_UInt32  gpio_11_smt:1;
        RBus_UInt32  gpio_12_smt:1;
        RBus_UInt32  gpio_13_smt:1;
        RBus_UInt32  gpio_14_smt:1;
        RBus_UInt32  gpio_15_smt:1;
        RBus_UInt32  gpio_16_smt:1;
        RBus_UInt32  gpio_17_smt:1;
        RBus_UInt32  gpio_18_smt:1;
        RBus_UInt32  gpio_19_smt:1;
        RBus_UInt32  gpio_20_smt:1;
        RBus_UInt32  gpio_21_smt:1;
        RBus_UInt32  gpio_22_smt:1;
        RBus_UInt32  gpio_23_smt:1;
        RBus_UInt32  gpio_24_smt:1;
        RBus_UInt32  gpio_25_smt:1;
        RBus_UInt32  gpio_26_smt:1;
        RBus_UInt32  gpio_27_smt:1;
        RBus_UInt32  gpio_28_smt:1;
        RBus_UInt32  gpio_29_smt:1;
        RBus_UInt32  gpio_30_smt:1;
        RBus_UInt32  gpio_31_smt:1;
    };
}pinmux_schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_32_smt:1;
        RBus_UInt32  gpio_33_smt:1;
        RBus_UInt32  gpio_34_smt:1;
        RBus_UInt32  gpio_35_smt:1;
        RBus_UInt32  gpio_36_smt:1;
        RBus_UInt32  gpio_37_smt:1;
        RBus_UInt32  gpio_38_smt:1;
        RBus_UInt32  gpio_39_smt:1;
        RBus_UInt32  gpio_40_smt:1;
        RBus_UInt32  gpio_41_smt:1;
        RBus_UInt32  gpio_42_smt:1;
        RBus_UInt32  gpio_43_smt:1;
        RBus_UInt32  gpio_44_smt:1;
        RBus_UInt32  gpio_45_smt:1;
        RBus_UInt32  gpio_46_smt:1;
        RBus_UInt32  gpio_47_smt:1;
        RBus_UInt32  gpio_48_smt:1;
        RBus_UInt32  gpio_49_smt:1;
        RBus_UInt32  gpio_50_smt:1;
        RBus_UInt32  gpio_51_smt:1;
        RBus_UInt32  gpio_52_smt:1;
        RBus_UInt32  gpio_53_smt:1;
        RBus_UInt32  gpio_54_smt:1;
        RBus_UInt32  gpio_55_smt:1;
        RBus_UInt32  gpio_56_smt:1;
        RBus_UInt32  gpio_57_smt:1;
        RBus_UInt32  gpio_58_smt:1;
        RBus_UInt32  gpio_59_smt:1;
        RBus_UInt32  res1:4;
    };
}pinmux_schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_60_smt:1;
        RBus_UInt32  gpio_61_smt:1;
        RBus_UInt32  gpio_62_smt:1;
        RBus_UInt32  gpio_63_smt:1;
        RBus_UInt32  gpio_64_smt:1;
        RBus_UInt32  gpio_65_smt:1;
        RBus_UInt32  gpio_66_smt:1;
        RBus_UInt32  gpio_67_smt:1;
        RBus_UInt32  gpio_68_smt:1;
        RBus_UInt32  gpio_69_smt:1;
        RBus_UInt32  gpio_70_smt:1;
        RBus_UInt32  gpio_71_smt:1;
        RBus_UInt32  gpio_72_smt:1;
        RBus_UInt32  gpio_73_smt:1;
        RBus_UInt32  gpio_74_smt:1;
        RBus_UInt32  gpio_75_smt:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  gpio_74_ie_v18:1;
        RBus_UInt32  gpio_68_ie_v18:1;
    };
}pinmux_schmidt_trigger_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  main_ext_clk_en:10;
        RBus_UInt32  testpin_mux:8;
    };
}pinmux_main_test_pin_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======PINMUX register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_3_sr:1;
        RBus_UInt32  gpio_3_ds:1;
        RBus_UInt32  gpio_3_pd:1;
        RBus_UInt32  gpio_3_pu:1;
        RBus_UInt32  gpio_3_ps:4;
        RBus_UInt32  gpio_2_sr:1;
        RBus_UInt32  gpio_2_ds:1;
        RBus_UInt32  gpio_2_pd:1;
        RBus_UInt32  gpio_2_pu:1;
        RBus_UInt32  gpio_2_ps:4;
        RBus_UInt32  gpio_1_sr:1;
        RBus_UInt32  gpio_1_ds:1;
        RBus_UInt32  gpio_1_pd:1;
        RBus_UInt32  gpio_1_pu:1;
        RBus_UInt32  gpio_1_ps:4;
        RBus_UInt32  gpio_0_sr:1;
        RBus_UInt32  gpio_0_ds:1;
        RBus_UInt32  gpio_0_pd:1;
        RBus_UInt32  gpio_0_pu:1;
        RBus_UInt32  gpio_0_ps:4;
    };
}pinmux_gpio_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_7_sr:1;
        RBus_UInt32  gpio_7_ds:1;
        RBus_UInt32  gpio_7_pd:1;
        RBus_UInt32  gpio_7_pu:1;
        RBus_UInt32  gpio_7_ps:4;
        RBus_UInt32  gpio_6_sr:1;
        RBus_UInt32  gpio_6_ds:1;
        RBus_UInt32  gpio_6_pd:1;
        RBus_UInt32  gpio_6_pu:1;
        RBus_UInt32  gpio_6_ps:4;
        RBus_UInt32  gpio_5_sr:1;
        RBus_UInt32  gpio_5_ds:1;
        RBus_UInt32  gpio_5_pd:1;
        RBus_UInt32  gpio_5_pu:1;
        RBus_UInt32  gpio_5_ps:4;
        RBus_UInt32  gpio_4_sr:1;
        RBus_UInt32  gpio_4_ds:1;
        RBus_UInt32  gpio_4_pd:1;
        RBus_UInt32  gpio_4_pu:1;
        RBus_UInt32  gpio_4_ps:4;
    };
}pinmux_gpio_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_11_sr:1;
        RBus_UInt32  gpio_11_ds:1;
        RBus_UInt32  gpio_11_pd:1;
        RBus_UInt32  gpio_11_pu:1;
        RBus_UInt32  gpio_11_ps:4;
        RBus_UInt32  gpio_10_sr:1;
        RBus_UInt32  gpio_10_ds:1;
        RBus_UInt32  gpio_10_pd:1;
        RBus_UInt32  gpio_10_pu:1;
        RBus_UInt32  gpio_10_ps:4;
        RBus_UInt32  gpio_9_sr:1;
        RBus_UInt32  gpio_9_ds:1;
        RBus_UInt32  gpio_9_pd:1;
        RBus_UInt32  gpio_9_pu:1;
        RBus_UInt32  gpio_9_ps:4;
        RBus_UInt32  gpio_8_sr:1;
        RBus_UInt32  gpio_8_ds:1;
        RBus_UInt32  gpio_8_pd:1;
        RBus_UInt32  gpio_8_pu:1;
        RBus_UInt32  gpio_8_ps:4;
    };
}pinmux_gpio_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_15_sr:1;
        RBus_UInt32  gpio_15_ds:1;
        RBus_UInt32  gpio_15_pd:1;
        RBus_UInt32  gpio_15_pu:1;
        RBus_UInt32  gpio_15_ps:4;
        RBus_UInt32  gpio_14_sr:1;
        RBus_UInt32  gpio_14_ds:1;
        RBus_UInt32  gpio_14_pd:1;
        RBus_UInt32  gpio_14_pu:1;
        RBus_UInt32  gpio_14_ps:4;
        RBus_UInt32  gpio_13_sr:1;
        RBus_UInt32  gpio_13_ds:1;
        RBus_UInt32  gpio_13_pd:1;
        RBus_UInt32  gpio_13_pu:1;
        RBus_UInt32  gpio_13_ps:4;
        RBus_UInt32  gpio_12_sr:1;
        RBus_UInt32  gpio_12_ds:1;
        RBus_UInt32  gpio_12_pd:1;
        RBus_UInt32  gpio_12_pu:1;
        RBus_UInt32  gpio_12_ps:4;
    };
}pinmux_gpio_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_19_sr:1;
        RBus_UInt32  gpio_19_ds:1;
        RBus_UInt32  gpio_19_pd:1;
        RBus_UInt32  gpio_19_pu:1;
        RBus_UInt32  gpio_19_ps:4;
        RBus_UInt32  gpio_18_sr:1;
        RBus_UInt32  gpio_18_ds:1;
        RBus_UInt32  gpio_18_pd:1;
        RBus_UInt32  gpio_18_pu:1;
        RBus_UInt32  gpio_18_ps:4;
        RBus_UInt32  gpio_17_sr:1;
        RBus_UInt32  gpio_17_ds:1;
        RBus_UInt32  gpio_17_pd:1;
        RBus_UInt32  gpio_17_pu:1;
        RBus_UInt32  gpio_17_ps:4;
        RBus_UInt32  gpio_16_sr:1;
        RBus_UInt32  gpio_16_ds:1;
        RBus_UInt32  gpio_16_pd:1;
        RBus_UInt32  gpio_16_pu:1;
        RBus_UInt32  gpio_16_ps:4;
    };
}pinmux_gpio_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_23_sr:1;
        RBus_UInt32  gpio_23_ds:1;
        RBus_UInt32  gpio_23_pd:1;
        RBus_UInt32  gpio_23_pu:1;
        RBus_UInt32  gpio_23_ps:4;
        RBus_UInt32  gpio_22_sr:1;
        RBus_UInt32  gpio_22_ds:1;
        RBus_UInt32  gpio_22_pd:1;
        RBus_UInt32  gpio_22_pu:1;
        RBus_UInt32  gpio_22_ps:4;
        RBus_UInt32  gpio_21_sr:1;
        RBus_UInt32  gpio_21_ds:1;
        RBus_UInt32  gpio_21_pd:1;
        RBus_UInt32  gpio_21_pu:1;
        RBus_UInt32  gpio_21_ps:4;
        RBus_UInt32  gpio_20_sr:1;
        RBus_UInt32  gpio_20_ds:1;
        RBus_UInt32  gpio_20_pd:1;
        RBus_UInt32  gpio_20_pu:1;
        RBus_UInt32  gpio_20_ps:4;
    };
}pinmux_gpio_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_27_sr:1;
        RBus_UInt32  gpio_27_ds:1;
        RBus_UInt32  gpio_27_pd:1;
        RBus_UInt32  gpio_27_pu:1;
        RBus_UInt32  gpio_27_ps:4;
        RBus_UInt32  gpio_26_sr:1;
        RBus_UInt32  gpio_26_ds:1;
        RBus_UInt32  gpio_26_pd:1;
        RBus_UInt32  gpio_26_pu:1;
        RBus_UInt32  gpio_26_ps:4;
        RBus_UInt32  gpio_25_sr:1;
        RBus_UInt32  gpio_25_ds:1;
        RBus_UInt32  gpio_25_pd:1;
        RBus_UInt32  gpio_25_pu:1;
        RBus_UInt32  gpio_25_ps:4;
        RBus_UInt32  gpio_24_sr:1;
        RBus_UInt32  gpio_24_ds:1;
        RBus_UInt32  gpio_24_pd:1;
        RBus_UInt32  gpio_24_pu:1;
        RBus_UInt32  gpio_24_ps:4;
    };
}pinmux_gpio_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_31_sr:1;
        RBus_UInt32  gpio_31_ds:1;
        RBus_UInt32  gpio_31_pd:1;
        RBus_UInt32  gpio_31_pu:1;
        RBus_UInt32  gpio_31_ps:4;
        RBus_UInt32  gpio_30_sr:1;
        RBus_UInt32  gpio_30_ds:1;
        RBus_UInt32  gpio_30_pd:1;
        RBus_UInt32  gpio_30_pu:1;
        RBus_UInt32  gpio_30_ps:4;
        RBus_UInt32  gpio_29_sr:1;
        RBus_UInt32  gpio_29_ds:1;
        RBus_UInt32  gpio_29_pd:1;
        RBus_UInt32  gpio_29_pu:1;
        RBus_UInt32  gpio_29_ps:4;
        RBus_UInt32  gpio_28_sr:1;
        RBus_UInt32  gpio_28_ds:1;
        RBus_UInt32  gpio_28_pd:1;
        RBus_UInt32  gpio_28_pu:1;
        RBus_UInt32  gpio_28_ps:4;
    };
}pinmux_gpio_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gpio_33_sr:1;
        RBus_UInt32  gpio_33_ds:1;
        RBus_UInt32  gpio_33_pd:1;
        RBus_UInt32  gpio_33_pu:1;
        RBus_UInt32  gpio_33_ps:4;
        RBus_UInt32  gpio_32_sr:1;
        RBus_UInt32  gpio_32_ds:1;
        RBus_UInt32  gpio_32_pd:1;
        RBus_UInt32  gpio_32_pu:1;
        RBus_UInt32  gpio_32_ps:4;
    };
}pinmux_gpio_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_37_sr:1;
        RBus_UInt32  gpio_37_ds:1;
        RBus_UInt32  gpio_37_pd:1;
        RBus_UInt32  gpio_37_pu:1;
        RBus_UInt32  gpio_37_ps:4;
        RBus_UInt32  gpio_36_sr:1;
        RBus_UInt32  gpio_36_ds:1;
        RBus_UInt32  gpio_36_pd:1;
        RBus_UInt32  gpio_36_pu:1;
        RBus_UInt32  gpio_36_ps:4;
        RBus_UInt32  gpio_35_sr:1;
        RBus_UInt32  gpio_35_ds:1;
        RBus_UInt32  gpio_35_pd:1;
        RBus_UInt32  gpio_35_pu:1;
        RBus_UInt32  gpio_35_ps:4;
        RBus_UInt32  gpio_34_sr:1;
        RBus_UInt32  gpio_34_ds:1;
        RBus_UInt32  gpio_34_pd:1;
        RBus_UInt32  gpio_34_pu:1;
        RBus_UInt32  gpio_34_ps:4;
    };
}pinmux_gpio_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_41_sr:1;
        RBus_UInt32  gpio_41_ds:1;
        RBus_UInt32  gpio_41_pd:1;
        RBus_UInt32  gpio_41_pu:1;
        RBus_UInt32  gpio_41_ps:4;
        RBus_UInt32  gpio_40_sr:1;
        RBus_UInt32  gpio_40_ds:1;
        RBus_UInt32  gpio_40_pd:1;
        RBus_UInt32  gpio_40_pu:1;
        RBus_UInt32  gpio_40_ps:4;
        RBus_UInt32  gpio_39_sr:1;
        RBus_UInt32  gpio_39_ds:1;
        RBus_UInt32  gpio_39_pd:1;
        RBus_UInt32  gpio_39_pu:1;
        RBus_UInt32  gpio_39_ps:4;
        RBus_UInt32  gpio_38_sr:1;
        RBus_UInt32  gpio_38_ds:1;
        RBus_UInt32  gpio_38_pd:1;
        RBus_UInt32  gpio_38_pu:1;
        RBus_UInt32  gpio_38_ps:4;
    };
}pinmux_gpio_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_45_sr:1;
        RBus_UInt32  gpio_45_ds:1;
        RBus_UInt32  gpio_45_pd:1;
        RBus_UInt32  gpio_45_pu:1;
        RBus_UInt32  gpio_45_ps:4;
        RBus_UInt32  gpio_44_sr:1;
        RBus_UInt32  gpio_44_ds:1;
        RBus_UInt32  gpio_44_pd:1;
        RBus_UInt32  gpio_44_pu:1;
        RBus_UInt32  gpio_44_ps:4;
        RBus_UInt32  gpio_43_sr:1;
        RBus_UInt32  gpio_43_ds:1;
        RBus_UInt32  gpio_43_pd:1;
        RBus_UInt32  gpio_43_pu:1;
        RBus_UInt32  gpio_43_ps:4;
        RBus_UInt32  gpio_42_sr:1;
        RBus_UInt32  gpio_42_ds:1;
        RBus_UInt32  gpio_42_pd:1;
        RBus_UInt32  gpio_42_pu:1;
        RBus_UInt32  gpio_42_ps:4;
    };
}pinmux_gpio_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_49_sr:1;
        RBus_UInt32  gpio_49_ds:1;
        RBus_UInt32  gpio_49_pd:1;
        RBus_UInt32  gpio_49_pu:1;
        RBus_UInt32  gpio_49_ps:4;
        RBus_UInt32  gpio_48_sr:1;
        RBus_UInt32  gpio_48_ds:1;
        RBus_UInt32  gpio_48_pd:1;
        RBus_UInt32  gpio_48_pu:1;
        RBus_UInt32  gpio_48_ps:4;
        RBus_UInt32  gpio_47_sr:1;
        RBus_UInt32  gpio_47_ds:1;
        RBus_UInt32  gpio_47_pd:1;
        RBus_UInt32  gpio_47_pu:1;
        RBus_UInt32  gpio_47_ps:4;
        RBus_UInt32  gpio_46_sr:1;
        RBus_UInt32  gpio_46_ds:1;
        RBus_UInt32  gpio_46_pd:1;
        RBus_UInt32  gpio_46_pu:1;
        RBus_UInt32  gpio_46_ps:4;
    };
}pinmux_gpio_cfg_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_53_sr:1;
        RBus_UInt32  gpio_53_ds:1;
        RBus_UInt32  gpio_53_pd:1;
        RBus_UInt32  gpio_53_pu:1;
        RBus_UInt32  gpio_53_ps:4;
        RBus_UInt32  gpio_52_sr:1;
        RBus_UInt32  gpio_52_ds:1;
        RBus_UInt32  gpio_52_pd:1;
        RBus_UInt32  gpio_52_pu:1;
        RBus_UInt32  gpio_52_ps:4;
        RBus_UInt32  gpio_51_sr:1;
        RBus_UInt32  gpio_51_ds:1;
        RBus_UInt32  gpio_51_pd:1;
        RBus_UInt32  gpio_51_pu:1;
        RBus_UInt32  gpio_51_ps:4;
        RBus_UInt32  gpio_50_sr:1;
        RBus_UInt32  gpio_50_ds:1;
        RBus_UInt32  gpio_50_pd:1;
        RBus_UInt32  gpio_50_pu:1;
        RBus_UInt32  gpio_50_ps:4;
    };
}pinmux_gpio_cfg_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_57_sr:1;
        RBus_UInt32  gpio_57_ds:1;
        RBus_UInt32  gpio_57_pd:1;
        RBus_UInt32  gpio_57_pu:1;
        RBus_UInt32  gpio_57_ps:4;
        RBus_UInt32  gpio_56_sr:1;
        RBus_UInt32  gpio_56_ds:1;
        RBus_UInt32  gpio_56_pd:1;
        RBus_UInt32  gpio_56_pu:1;
        RBus_UInt32  gpio_56_ps:4;
        RBus_UInt32  gpio_55_sr:1;
        RBus_UInt32  gpio_55_ds:1;
        RBus_UInt32  gpio_55_pd:1;
        RBus_UInt32  gpio_55_pu:1;
        RBus_UInt32  gpio_55_ps:4;
        RBus_UInt32  gpio_54_sr:1;
        RBus_UInt32  gpio_54_ds:1;
        RBus_UInt32  gpio_54_pd:1;
        RBus_UInt32  gpio_54_pu:1;
        RBus_UInt32  gpio_54_ps:4;
    };
}pinmux_gpio_cfg_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_61_sr:1;
        RBus_UInt32  gpio_61_ds:1;
        RBus_UInt32  gpio_61_pd:1;
        RBus_UInt32  gpio_61_pu:1;
        RBus_UInt32  gpio_61_ps:4;
        RBus_UInt32  gpio_60_sr:1;
        RBus_UInt32  gpio_60_ds:1;
        RBus_UInt32  gpio_60_pd:1;
        RBus_UInt32  gpio_60_pu:1;
        RBus_UInt32  gpio_60_ps:4;
        RBus_UInt32  gpio_59_sr:1;
        RBus_UInt32  gpio_59_ds:1;
        RBus_UInt32  gpio_59_pd:1;
        RBus_UInt32  gpio_59_pu:1;
        RBus_UInt32  gpio_59_ps:4;
        RBus_UInt32  gpio_58_sr:1;
        RBus_UInt32  gpio_58_ds:1;
        RBus_UInt32  gpio_58_pd:1;
        RBus_UInt32  gpio_58_pu:1;
        RBus_UInt32  gpio_58_ps:4;
    };
}pinmux_gpio_cfg_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_65_sr:1;
        RBus_UInt32  gpio_65_ds:1;
        RBus_UInt32  gpio_65_pd:1;
        RBus_UInt32  gpio_65_pu:1;
        RBus_UInt32  gpio_65_ps:4;
        RBus_UInt32  gpio_64_sr:1;
        RBus_UInt32  gpio_64_ds:1;
        RBus_UInt32  gpio_64_pd:1;
        RBus_UInt32  gpio_64_pu:1;
        RBus_UInt32  gpio_64_ps:4;
        RBus_UInt32  gpio_63_sr:1;
        RBus_UInt32  gpio_63_ds:1;
        RBus_UInt32  gpio_63_pd:1;
        RBus_UInt32  gpio_63_pu:1;
        RBus_UInt32  gpio_63_ps:4;
        RBus_UInt32  gpio_62_sr:1;
        RBus_UInt32  gpio_62_ds:1;
        RBus_UInt32  gpio_62_pd:1;
        RBus_UInt32  gpio_62_pu:1;
        RBus_UInt32  gpio_62_ps:4;
    };
}pinmux_gpio_cfg_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_69_sr:1;
        RBus_UInt32  gpio_69_ds:1;
        RBus_UInt32  gpio_69_pd:1;
        RBus_UInt32  gpio_69_pu:1;
        RBus_UInt32  gpio_69_ps:4;
        RBus_UInt32  gpio_68_sr:1;
        RBus_UInt32  gpio_68_ds:1;
        RBus_UInt32  gpio_68_pd:1;
        RBus_UInt32  gpio_68_pu:1;
        RBus_UInt32  gpio_68_ps:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  gpio_67_ds:1;
        RBus_UInt32  gpio_67_pd:1;
        RBus_UInt32  gpio_67_pu:1;
        RBus_UInt32  gpio_67_ps:4;
        RBus_UInt32  gpio_66_sr:1;
        RBus_UInt32  gpio_66_ds:1;
        RBus_UInt32  gpio_66_pd:1;
        RBus_UInt32  gpio_66_pu:1;
        RBus_UInt32  gpio_66_ps:4;
    };
}pinmux_gpio_cfg_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_73_sr:1;
        RBus_UInt32  gpio_73_ds:1;
        RBus_UInt32  gpio_73_pd:1;
        RBus_UInt32  gpio_73_pu:1;
        RBus_UInt32  gpio_73_ps:4;
        RBus_UInt32  gpio_72_sr:1;
        RBus_UInt32  gpio_72_ds:1;
        RBus_UInt32  gpio_72_pd:1;
        RBus_UInt32  gpio_72_pu:1;
        RBus_UInt32  gpio_72_ps:4;
        RBus_UInt32  gpio_71_sr:1;
        RBus_UInt32  gpio_71_ds:1;
        RBus_UInt32  gpio_71_pd:1;
        RBus_UInt32  gpio_71_pu:1;
        RBus_UInt32  gpio_71_ps:4;
        RBus_UInt32  gpio_70_sr:1;
        RBus_UInt32  gpio_70_ds:1;
        RBus_UInt32  gpio_70_pd:1;
        RBus_UInt32  gpio_70_pu:1;
        RBus_UInt32  gpio_70_ps:4;
    };
}pinmux_gpio_cfg_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  res2:1;
        RBus_UInt32  gpio_75_ds:1;
        RBus_UInt32  gpio_75_pd:1;
        RBus_UInt32  gpio_75_pu:1;
        RBus_UInt32  gpio_75_ps:4;
        RBus_UInt32  gpio_74_sr:1;
        RBus_UInt32  gpio_74_ds:1;
        RBus_UInt32  gpio_74_pd:1;
        RBus_UInt32  gpio_74_pu:1;
        RBus_UInt32  gpio_74_ps:4;
    };
}pinmux_gpio_cfg_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_dn_ps:4;
        RBus_UInt32  lvds_a_dp_ps:4;
        RBus_UInt32  lvds_a_en_ps:4;
        RBus_UInt32  lvds_a_ep_ps:4;
        RBus_UInt32  lvds_a_fn_ps:4;
        RBus_UInt32  lvds_a_fp_ps:4;
        RBus_UInt32  lvds_a_gn_ps:4;
        RBus_UInt32  lvds_a_gp_ps:4;
    };
}pinmux_lvds_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lvds_a_an_ps:4;
        RBus_UInt32  lvds_a_ap_ps:4;
        RBus_UInt32  lvds_a_bn_ps:4;
        RBus_UInt32  lvds_a_bp_ps:4;
        RBus_UInt32  lvds_a_cn_ps:4;
        RBus_UInt32  lvds_a_cp_ps:4;
    };
}pinmux_lvds_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_dn_ps:4;
        RBus_UInt32  lvds_b_dp_ps:4;
        RBus_UInt32  lvds_b_en_ps:4;
        RBus_UInt32  lvds_b_ep_ps:4;
        RBus_UInt32  lvds_b_fn_ps:4;
        RBus_UInt32  lvds_b_fp_ps:4;
        RBus_UInt32  lvds_b_gn_ps:4;
        RBus_UInt32  lvds_b_gp_ps:4;
    };
}pinmux_lvds_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lvds_b_an_ps:4;
        RBus_UInt32  lvds_b_ap_ps:4;
        RBus_UInt32  lvds_b_bn_ps:4;
        RBus_UInt32  lvds_b_bp_ps:4;
        RBus_UInt32  lvds_b_cn_ps:4;
        RBus_UInt32  lvds_b_cp_ps:4;
    };
}pinmux_lvds_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsync_gpi_en:1;
        RBus_UInt32  vsync_gpi_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  hsync_ps:4;
        RBus_UInt32  vsync_ps:4;
    };
}pinmux_hv_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_2p_gpi_en:1;
        RBus_UInt32  vin_1p_gpi_en:1;
        RBus_UInt32  vin_bn_gpi_en:1;
        RBus_UInt32  vin_0p_gpi_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  vin_2p_ps:4;
        RBus_UInt32  vin_1p_ps:4;
        RBus_UInt32  vin_bn_ps:4;
        RBus_UInt32  vin_0p_ps:4;
    };
}pinmux_ypp_adc_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_8p_gpi_en:1;
        RBus_UInt32  vin_7p_gpi_en:1;
        RBus_UInt32  vin_y1n_gpi_en:1;
        RBus_UInt32  vin_6p_gpi_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  vin_8p_ps:4;
        RBus_UInt32  vin_7p_ps:4;
        RBus_UInt32  vin_y1n_ps:4;
        RBus_UInt32  vin_6p_ps:4;
    };
}pinmux_ypp_adc_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_13p_gpi_en:1;
        RBus_UInt32  vin_10p_gpi_en:1;
        RBus_UInt32  vin_a2n_gpi_en:1;
        RBus_UInt32  vin_a0n_gpi_en:1;
        RBus_UInt32  vin_12p_gpi_en:1;
        RBus_UInt32  vin_9p_pi_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vin_13p_ps:4;
        RBus_UInt32  vin_10p_ps:4;
        RBus_UInt32  vin_a2n_ps:4;
        RBus_UInt32  vin_a0n_ps:4;
        RBus_UInt32  vin_12p_ps:4;
        RBus_UInt32  vin_9p_ps:4;
    };
}pinmux_adc_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdac_out_gpi_en:1;
        RBus_UInt32  vdbs_out_gpi_en:1;
        RBus_UInt32  scart_fsw_0_gpi_en:1;
        RBus_UInt32  usb3_hsdm_ps:4;
        RBus_UInt32  usb3_hsdp_ps:4;
        RBus_UInt32  hsdp2_gpi_en:1;
        RBus_UInt32  hsdm2_gpi_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  vdac_out_ps:4;
        RBus_UInt32  vdbs_out_ps:4;
        RBus_UInt32  scart_fsw_0_ps:4;
    };
}pinmux_scart_fsw_cfg_vd_dac_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_ai3r_gpi_en:1;
        RBus_UInt32  bb_ai3l_gpi_en:1;
        RBus_UInt32  bb_ai2r_gpi_en:1;
        RBus_UInt32  bb_ai2l_gpi_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  bb_ai3r_ps:4;
        RBus_UInt32  bb_ai3l_ps:4;
        RBus_UInt32  bb_ai2r_ps:4;
        RBus_UInt32  bb_ai2l_ps:4;
    };
}pinmux_bb_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_hpor_gpi_en:1;
        RBus_UInt32  bb_hpol_gpi_en:1;
        RBus_UInt32  bb_aior_gpi_en:1;
        RBus_UInt32  bb_aiol_gpi_en:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  bb_hpor_ps:4;
        RBus_UInt32  bb_hpol_ps:4;
        RBus_UInt32  bb_aior_ps:4;
        RBus_UInt32  bb_aiol_ps:4;
    };
}pinmux_bb_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_in_sel:3;
        RBus_UInt32  anttx_in_sel:2;
        RBus_UInt32  antrx_in_sel:2;
        RBus_UInt32  antoe_in_sel:2;
        RBus_UInt32  i2s_in_sel:2;
        RBus_UInt32  i2c1_in_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  i2c2_in_sel:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  tp2_mux_selection:3;
        RBus_UInt32  tp1_mux_selection:3;
        RBus_UInt32  tp0_mux_selection:3;
        RBus_UInt32  res3:3;
    };
}pinmux_pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ld_spi0_p4_sdi_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ld_spi0_p3_sdo_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_spi0_p2_sck_sel:2;
        RBus_UInt32  res4:16;
    };
}pinmux_pin_mux_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phif_enable:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  uart2_rxdi_in_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  uart1_rxdi_in_sel:3;
        RBus_UInt32  cr_sd_in_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  usb_pwr_flag1_in_sel:2;
        RBus_UInt32  usb_pwr_flag0_in_sel:2;
        RBus_UInt32  demod_i2c_relay_in_sel:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  epi_lock_in_sel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  spdif_in_sel:2;
    };
}pinmux_pin_mux_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_31_smt:1;
        RBus_UInt32  gpio_30_smt:1;
        RBus_UInt32  gpio_29_smt:1;
        RBus_UInt32  gpio_28_smt:1;
        RBus_UInt32  gpio_27_smt:1;
        RBus_UInt32  gpio_26_smt:1;
        RBus_UInt32  gpio_25_smt:1;
        RBus_UInt32  gpio_24_smt:1;
        RBus_UInt32  gpio_23_smt:1;
        RBus_UInt32  gpio_22_smt:1;
        RBus_UInt32  gpio_21_smt:1;
        RBus_UInt32  gpio_20_smt:1;
        RBus_UInt32  gpio_19_smt:1;
        RBus_UInt32  gpio_18_smt:1;
        RBus_UInt32  gpio_17_smt:1;
        RBus_UInt32  gpio_16_smt:1;
        RBus_UInt32  gpio_15_smt:1;
        RBus_UInt32  gpio_14_smt:1;
        RBus_UInt32  gpio_13_smt:1;
        RBus_UInt32  gpio_12_smt:1;
        RBus_UInt32  gpio_11_smt:1;
        RBus_UInt32  gpio_10_smt:1;
        RBus_UInt32  gpio_9_smt:1;
        RBus_UInt32  gpio_8_smt:1;
        RBus_UInt32  gpio_7_smt:1;
        RBus_UInt32  gpio_6_smt:1;
        RBus_UInt32  gpio_5_smt:1;
        RBus_UInt32  gpio_4_smt:1;
        RBus_UInt32  gpio_3_smt:1;
        RBus_UInt32  gpio_2_smt:1;
        RBus_UInt32  gpio_1_smt:1;
        RBus_UInt32  gpio_0_smt:1;
    };
}pinmux_schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gpio_59_smt:1;
        RBus_UInt32  gpio_58_smt:1;
        RBus_UInt32  gpio_57_smt:1;
        RBus_UInt32  gpio_56_smt:1;
        RBus_UInt32  gpio_55_smt:1;
        RBus_UInt32  gpio_54_smt:1;
        RBus_UInt32  gpio_53_smt:1;
        RBus_UInt32  gpio_52_smt:1;
        RBus_UInt32  gpio_51_smt:1;
        RBus_UInt32  gpio_50_smt:1;
        RBus_UInt32  gpio_49_smt:1;
        RBus_UInt32  gpio_48_smt:1;
        RBus_UInt32  gpio_47_smt:1;
        RBus_UInt32  gpio_46_smt:1;
        RBus_UInt32  gpio_45_smt:1;
        RBus_UInt32  gpio_44_smt:1;
        RBus_UInt32  gpio_43_smt:1;
        RBus_UInt32  gpio_42_smt:1;
        RBus_UInt32  gpio_41_smt:1;
        RBus_UInt32  gpio_40_smt:1;
        RBus_UInt32  gpio_39_smt:1;
        RBus_UInt32  gpio_38_smt:1;
        RBus_UInt32  gpio_37_smt:1;
        RBus_UInt32  gpio_36_smt:1;
        RBus_UInt32  gpio_35_smt:1;
        RBus_UInt32  gpio_34_smt:1;
        RBus_UInt32  gpio_33_smt:1;
        RBus_UInt32  gpio_32_smt:1;
    };
}pinmux_schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_68_ie_v18:1;
        RBus_UInt32  gpio_74_ie_v18:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  gpio_75_smt:1;
        RBus_UInt32  gpio_74_smt:1;
        RBus_UInt32  gpio_73_smt:1;
        RBus_UInt32  gpio_72_smt:1;
        RBus_UInt32  gpio_71_smt:1;
        RBus_UInt32  gpio_70_smt:1;
        RBus_UInt32  gpio_69_smt:1;
        RBus_UInt32  gpio_68_smt:1;
        RBus_UInt32  gpio_67_smt:1;
        RBus_UInt32  gpio_66_smt:1;
        RBus_UInt32  gpio_65_smt:1;
        RBus_UInt32  gpio_64_smt:1;
        RBus_UInt32  gpio_63_smt:1;
        RBus_UInt32  gpio_62_smt:1;
        RBus_UInt32  gpio_61_smt:1;
        RBus_UInt32  gpio_60_smt:1;
    };
}pinmux_schmidt_trigger_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  testpin_mux:8;
        RBus_UInt32  main_ext_clk_en:10;
        RBus_UInt32  res1:14;
    };
}pinmux_main_test_pin_ctrl_RBUS;




#endif


#endif
