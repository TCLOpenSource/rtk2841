/**
* @file rbusPinmux_StReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/8/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PINMUX_ST_REG_H_
#define _RBUS_PINMUX_ST_REG_H_

#include "rbusTypes.h"



//  PINMUX_ST Register Address



#define  PINMUX_ST_ST_CFG_0_VADDR                           	(0xb8060200)
#define  PINMUX_ST_ST_CFG_1_VADDR                           	(0xb8060204)
#define  PINMUX_ST_ST_CFG_2_VADDR                           	(0xb8060208)
#define  PINMUX_ST_ST_CFG_3_VADDR                           	(0xb806020c)
#define  PINMUX_ST_ST_CFG_4_VADDR                           	(0xb8060210)
#define  PINMUX_ST_ST_CFG_5_VADDR                           	(0xb8060214)
#define  PINMUX_ST_ST_CFG_6_VADDR                           	(0xb8060218)
#define  PINMUX_ST_ST_CFG_7_VADDR                           	(0xb806021c)
#define  PINMUX_ST_ST_CFG_8_VADDR                           	(0xb8060220)
#define  PINMUX_ST_ST_CFG_9_VADDR                           	(0xb8060224)
#define  PINMUX_ST_ST_SCHMIDT_TRIGGER_0_VADDR               	(0xb8060230)
#define  PINMUX_ST_ST_SCHMIDT_TRIGGER_1_VADDR               	(0xb8060234)
#define  PINMUX_ST_ST_PIN_MUX_CTRL0_VADDR                   	(0xb8060240)
#define  PINMUX_ST_ST_TEST_PIN_CTRL_VADDR                   	(0xb8060250)
#define  PINMUX_ST_ST_PORL_CTRL_VADDR                       	(0xb8060254)
#define  PINMUX_ST_ST_V18_CONTROL_VADDR                     	(0xb8060258)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PINMUX_ST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_0_ps:4;
        RBus_UInt32  st_gpio_0_pu:1;
        RBus_UInt32  st_gpio_0_pd:1;
        RBus_UInt32  st_gpio_0_ds:1;
        RBus_UInt32  st_gpio_0_sr:1;
        RBus_UInt32  st_gpio_1_ps:4;
        RBus_UInt32  st_gpio_1_pu:1;
        RBus_UInt32  st_gpio_1_pd:1;
        RBus_UInt32  st_gpio_1_ds:1;
        RBus_UInt32  st_gpio_1_sr:1;
        RBus_UInt32  st_gpio_2_ps:4;
        RBus_UInt32  st_gpio_2_pu:1;
        RBus_UInt32  st_gpio_2_pd:1;
        RBus_UInt32  st_gpio_2_ds:1;
        RBus_UInt32  st_gpio_2_sr:1;
        RBus_UInt32  st_gpio_3_ps:4;
        RBus_UInt32  st_gpio_3_pu:1;
        RBus_UInt32  st_gpio_3_pd:1;
        RBus_UInt32  st_gpio_3_ds:1;
        RBus_UInt32  res1:1;
    };
}pinmux_st_st_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_4_ps:4;
        RBus_UInt32  st_gpio_4_pu:1;
        RBus_UInt32  st_gpio_4_pd:1;
        RBus_UInt32  st_gpio_4_ds:1;
        RBus_UInt32  st_gpio_4_sr:1;
        RBus_UInt32  st_gpio_5_ps:4;
        RBus_UInt32  st_gpio_5_pu:1;
        RBus_UInt32  st_gpio_5_pd:1;
        RBus_UInt32  st_gpio_5_ds:1;
        RBus_UInt32  st_gpio_5_sr:1;
        RBus_UInt32  st_gpio_6_ps:4;
        RBus_UInt32  st_gpio_6_pu:1;
        RBus_UInt32  st_gpio_6_pd:1;
        RBus_UInt32  st_gpio_6_ds:1;
        RBus_UInt32  st_gpio_6_sr:1;
        RBus_UInt32  st_gpio_7_ps:4;
        RBus_UInt32  st_gpio_7_pu:1;
        RBus_UInt32  st_gpio_7_pd:1;
        RBus_UInt32  st_gpio_7_ds:1;
        RBus_UInt32  st_gpio_7_sr:1;
    };
}pinmux_st_st_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_8_ps:4;
        RBus_UInt32  st_gpio_8_pu:1;
        RBus_UInt32  st_gpio_8_pd:1;
        RBus_UInt32  st_gpio_8_ds:1;
        RBus_UInt32  st_gpio_8_sr:1;
        RBus_UInt32  st_gpio_9_ps:4;
        RBus_UInt32  st_gpio_9_pu:1;
        RBus_UInt32  st_gpio_9_pd:1;
        RBus_UInt32  st_gpio_9_ds:1;
        RBus_UInt32  st_gpio_9_sr:1;
        RBus_UInt32  st_gpio_10_ps:4;
        RBus_UInt32  st_gpio_10_pu:1;
        RBus_UInt32  st_gpio_10_pd:1;
        RBus_UInt32  st_gpio_10_ds:1;
        RBus_UInt32  st_gpio_10_sr:1;
        RBus_UInt32  st_gpio_11_ps:4;
        RBus_UInt32  st_gpio_11_pu:1;
        RBus_UInt32  st_gpio_11_pd:1;
        RBus_UInt32  st_gpio_11_ds:1;
        RBus_UInt32  st_gpio_11_sr:1;
    };
}pinmux_st_st_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_12_ps:4;
        RBus_UInt32  st_gpio_12_pu:1;
        RBus_UInt32  st_gpio_12_pd:1;
        RBus_UInt32  st_gpio_12_ds:1;
        RBus_UInt32  st_gpio_12_sr:1;
        RBus_UInt32  st_gpio_13_ps:4;
        RBus_UInt32  st_gpio_13_pu:1;
        RBus_UInt32  st_gpio_13_pd:1;
        RBus_UInt32  st_gpio_13_ds:1;
        RBus_UInt32  st_gpio_13_sr:1;
        RBus_UInt32  st_gpio_14_ps:4;
        RBus_UInt32  st_gpio_14_pu:1;
        RBus_UInt32  st_gpio_14_pd:1;
        RBus_UInt32  st_gpio_14_ds:1;
        RBus_UInt32  st_gpio_14_sr:1;
        RBus_UInt32  st_gpio_15_ps:4;
        RBus_UInt32  st_gpio_15_pu:1;
        RBus_UInt32  st_gpio_15_pd:1;
        RBus_UInt32  st_gpio_15_ds:1;
        RBus_UInt32  st_gpio_15_sr:1;
    };
}pinmux_st_st_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_16_ps:4;
        RBus_UInt32  st_gpio_16_pu:1;
        RBus_UInt32  st_gpio_16_pd:1;
        RBus_UInt32  st_gpio_16_ds:1;
        RBus_UInt32  st_gpio_16_sr:1;
        RBus_UInt32  st_gpio_17_ps:4;
        RBus_UInt32  st_gpio_17_pu:1;
        RBus_UInt32  st_gpio_17_pd:1;
        RBus_UInt32  st_gpio_17_ds:1;
        RBus_UInt32  st_gpio_17_sr:1;
        RBus_UInt32  st_gpio_18_ps:4;
        RBus_UInt32  st_gpio_18_pu:1;
        RBus_UInt32  st_gpio_18_pd:1;
        RBus_UInt32  st_gpio_18_ds:1;
        RBus_UInt32  st_gpio_18_sr:1;
        RBus_UInt32  st_gpio_19_ps:4;
        RBus_UInt32  st_gpio_19_pu:1;
        RBus_UInt32  st_gpio_19_pd:1;
        RBus_UInt32  st_gpio_19_ds:1;
        RBus_UInt32  st_gpio_19_sr:1;
    };
}pinmux_st_st_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_20_ps:4;
        RBus_UInt32  st_gpio_20_pu:1;
        RBus_UInt32  st_gpio_20_pd:1;
        RBus_UInt32  st_gpio_20_ds:1;
        RBus_UInt32  st_gpio_20_sr:1;
        RBus_UInt32  st_gpio_21_ps:4;
        RBus_UInt32  st_gpio_21_pu:1;
        RBus_UInt32  st_gpio_21_pd:1;
        RBus_UInt32  st_gpio_21_ds:1;
        RBus_UInt32  st_gpio_21_sr:1;
        RBus_UInt32  st_gpio_22_ps:4;
        RBus_UInt32  st_gpio_22_pu:1;
        RBus_UInt32  st_gpio_22_pd:1;
        RBus_UInt32  st_gpio_22_ds:1;
        RBus_UInt32  st_gpio_22_sr:1;
        RBus_UInt32  st_gpio_23_ps:4;
        RBus_UInt32  st_gpio_23_pu:1;
        RBus_UInt32  st_gpio_23_pd:1;
        RBus_UInt32  st_gpio_23_ds:1;
        RBus_UInt32  st_gpio_23_sr:1;
    };
}pinmux_st_st_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_24_ps:4;
        RBus_UInt32  st_gpio_24_pu:1;
        RBus_UInt32  st_gpio_24_pd:1;
        RBus_UInt32  st_gpio_24_ds:1;
        RBus_UInt32  st_gpio_24_sr:1;
        RBus_UInt32  st_gpio_25_ps:4;
        RBus_UInt32  st_gpio_25_pu:1;
        RBus_UInt32  st_gpio_25_pd:1;
        RBus_UInt32  st_gpio_25_ds:1;
        RBus_UInt32  st_gpio_25_sr:1;
        RBus_UInt32  st_gpio_26_ps:4;
        RBus_UInt32  st_gpio_26_pu:1;
        RBus_UInt32  st_gpio_26_pd:1;
        RBus_UInt32  st_gpio_26_ds:1;
        RBus_UInt32  st_gpio_26_sr:1;
        RBus_UInt32  st_gpio_27_ps:4;
        RBus_UInt32  st_gpio_27_pu:1;
        RBus_UInt32  st_gpio_27_pd:1;
        RBus_UInt32  st_gpio_27_ds:1;
        RBus_UInt32  st_gpio_27_sr:1;
    };
}pinmux_st_st_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_28_ps:4;
        RBus_UInt32  st_gpio_28_pu:1;
        RBus_UInt32  st_gpio_28_pd:1;
        RBus_UInt32  st_gpio_28_ds:1;
        RBus_UInt32  st_gpio_28_sr:1;
        RBus_UInt32  st_gpio_29_ps:4;
        RBus_UInt32  st_gpio_29_pu:1;
        RBus_UInt32  st_gpio_29_pd:1;
        RBus_UInt32  st_gpio_29_ds:1;
        RBus_UInt32  st_gpio_29_sr:1;
        RBus_UInt32  st_gpio_30_ps:4;
        RBus_UInt32  st_gpio_30_pu:1;
        RBus_UInt32  st_gpio_30_pd:1;
        RBus_UInt32  st_gpio_30_ds:1;
        RBus_UInt32  st_gpio_30_sr:1;
        RBus_UInt32  st_gpio_31_ps:4;
        RBus_UInt32  st_gpio_31_pu:1;
        RBus_UInt32  st_gpio_31_pd:1;
        RBus_UInt32  st_gpio_31_ds:1;
        RBus_UInt32  st_gpio_31_sr:1;
    };
}pinmux_st_st_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_32_ps:4;
        RBus_UInt32  st_gpio_32_pu:1;
        RBus_UInt32  st_gpio_32_pd:1;
        RBus_UInt32  st_gpio_32_ds:1;
        RBus_UInt32  st_gpio_32_sr:1;
        RBus_UInt32  res1:24;
    };
}pinmux_st_st_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lsadc_ref_ps:4;
        RBus_UInt32  lsadc0_ps:4;
        RBus_UInt32  lsadc1_ps:4;
        RBus_UInt32  lsadc2_ps:4;
        RBus_UInt32  lsadc4_ps:4;
        RBus_UInt32  lsadc6_ps:4;
        RBus_UInt32  lsadc7_ps:4;
        RBus_UInt32  stb_dio_ps:4;
    };
}pinmux_st_st_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_0_smt:1;
        RBus_UInt32  st_gpio_1_smt:1;
        RBus_UInt32  st_gpio_2_smt:1;
        RBus_UInt32  st_gpio_3_smt:1;
        RBus_UInt32  st_gpio_4_smt:1;
        RBus_UInt32  st_gpio_5_smt:1;
        RBus_UInt32  st_gpio_6_smt:1;
        RBus_UInt32  st_gpio_7_smt:1;
        RBus_UInt32  st_gpio_8_smt:1;
        RBus_UInt32  st_gpio_9_smt:1;
        RBus_UInt32  st_gpio_10_smt:1;
        RBus_UInt32  st_gpio_11_smt:1;
        RBus_UInt32  st_gpio_12_smt:1;
        RBus_UInt32  st_gpio_13_smt:1;
        RBus_UInt32  st_gpio_14_smt:1;
        RBus_UInt32  st_gpio_15_smt:1;
        RBus_UInt32  st_gpio_16_smt:1;
        RBus_UInt32  st_gpio_17_smt:1;
        RBus_UInt32  st_gpio_18_smt:1;
        RBus_UInt32  st_gpio_19_smt:1;
        RBus_UInt32  st_gpio_20_smt:1;
        RBus_UInt32  st_gpio_21_smt:1;
        RBus_UInt32  st_gpio_22_smt:1;
        RBus_UInt32  st_gpio_23_smt:1;
        RBus_UInt32  st_gpio_24_smt:1;
        RBus_UInt32  st_gpio_25_smt:1;
        RBus_UInt32  st_gpio_26_smt:1;
        RBus_UInt32  st_gpio_27_smt:1;
        RBus_UInt32  st_gpio_28_smt:1;
        RBus_UInt32  st_gpio_29_smt:1;
        RBus_UInt32  st_gpio_30_smt:1;
        RBus_UInt32  st_gpio_31_smt:1;
    };
}pinmux_st_st_schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_32_smt:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  stb_gpi_en:1;
        RBus_UInt32  jd_gpi_en:7;
    };
}pinmux_st_st_schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  emcu_ur_rx_in_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  uart0_rxdi_in_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  i2c0_in_sel:4;
        RBus_UInt32  dtv_i2c_sel:1;
        RBus_UInt32  res4:6;
    };
}pinmux_st_st_pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  st_testpin_mux:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  iso_uni_pwm_1_sel:1;
        RBus_UInt32  iso_uni_pwm_0_sel:1;
    };
}pinmux_st_st_test_pin_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  spi_porl_release:1;
    };
}pinmux_st_st_porl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  st_gpio_2_ie_v18:1;
    };
}pinmux_st_st_v18_control_RBUS;

#else //apply LITTLE_ENDIAN

//======PINMUX_ST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  st_gpio_3_ds:1;
        RBus_UInt32  st_gpio_3_pd:1;
        RBus_UInt32  st_gpio_3_pu:1;
        RBus_UInt32  st_gpio_3_ps:4;
        RBus_UInt32  st_gpio_2_sr:1;
        RBus_UInt32  st_gpio_2_ds:1;
        RBus_UInt32  st_gpio_2_pd:1;
        RBus_UInt32  st_gpio_2_pu:1;
        RBus_UInt32  st_gpio_2_ps:4;
        RBus_UInt32  st_gpio_1_sr:1;
        RBus_UInt32  st_gpio_1_ds:1;
        RBus_UInt32  st_gpio_1_pd:1;
        RBus_UInt32  st_gpio_1_pu:1;
        RBus_UInt32  st_gpio_1_ps:4;
        RBus_UInt32  st_gpio_0_sr:1;
        RBus_UInt32  st_gpio_0_ds:1;
        RBus_UInt32  st_gpio_0_pd:1;
        RBus_UInt32  st_gpio_0_pu:1;
        RBus_UInt32  st_gpio_0_ps:4;
    };
}pinmux_st_st_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_7_sr:1;
        RBus_UInt32  st_gpio_7_ds:1;
        RBus_UInt32  st_gpio_7_pd:1;
        RBus_UInt32  st_gpio_7_pu:1;
        RBus_UInt32  st_gpio_7_ps:4;
        RBus_UInt32  st_gpio_6_sr:1;
        RBus_UInt32  st_gpio_6_ds:1;
        RBus_UInt32  st_gpio_6_pd:1;
        RBus_UInt32  st_gpio_6_pu:1;
        RBus_UInt32  st_gpio_6_ps:4;
        RBus_UInt32  st_gpio_5_sr:1;
        RBus_UInt32  st_gpio_5_ds:1;
        RBus_UInt32  st_gpio_5_pd:1;
        RBus_UInt32  st_gpio_5_pu:1;
        RBus_UInt32  st_gpio_5_ps:4;
        RBus_UInt32  st_gpio_4_sr:1;
        RBus_UInt32  st_gpio_4_ds:1;
        RBus_UInt32  st_gpio_4_pd:1;
        RBus_UInt32  st_gpio_4_pu:1;
        RBus_UInt32  st_gpio_4_ps:4;
    };
}pinmux_st_st_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_11_sr:1;
        RBus_UInt32  st_gpio_11_ds:1;
        RBus_UInt32  st_gpio_11_pd:1;
        RBus_UInt32  st_gpio_11_pu:1;
        RBus_UInt32  st_gpio_11_ps:4;
        RBus_UInt32  st_gpio_10_sr:1;
        RBus_UInt32  st_gpio_10_ds:1;
        RBus_UInt32  st_gpio_10_pd:1;
        RBus_UInt32  st_gpio_10_pu:1;
        RBus_UInt32  st_gpio_10_ps:4;
        RBus_UInt32  st_gpio_9_sr:1;
        RBus_UInt32  st_gpio_9_ds:1;
        RBus_UInt32  st_gpio_9_pd:1;
        RBus_UInt32  st_gpio_9_pu:1;
        RBus_UInt32  st_gpio_9_ps:4;
        RBus_UInt32  st_gpio_8_sr:1;
        RBus_UInt32  st_gpio_8_ds:1;
        RBus_UInt32  st_gpio_8_pd:1;
        RBus_UInt32  st_gpio_8_pu:1;
        RBus_UInt32  st_gpio_8_ps:4;
    };
}pinmux_st_st_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_15_sr:1;
        RBus_UInt32  st_gpio_15_ds:1;
        RBus_UInt32  st_gpio_15_pd:1;
        RBus_UInt32  st_gpio_15_pu:1;
        RBus_UInt32  st_gpio_15_ps:4;
        RBus_UInt32  st_gpio_14_sr:1;
        RBus_UInt32  st_gpio_14_ds:1;
        RBus_UInt32  st_gpio_14_pd:1;
        RBus_UInt32  st_gpio_14_pu:1;
        RBus_UInt32  st_gpio_14_ps:4;
        RBus_UInt32  st_gpio_13_sr:1;
        RBus_UInt32  st_gpio_13_ds:1;
        RBus_UInt32  st_gpio_13_pd:1;
        RBus_UInt32  st_gpio_13_pu:1;
        RBus_UInt32  st_gpio_13_ps:4;
        RBus_UInt32  st_gpio_12_sr:1;
        RBus_UInt32  st_gpio_12_ds:1;
        RBus_UInt32  st_gpio_12_pd:1;
        RBus_UInt32  st_gpio_12_pu:1;
        RBus_UInt32  st_gpio_12_ps:4;
    };
}pinmux_st_st_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_19_sr:1;
        RBus_UInt32  st_gpio_19_ds:1;
        RBus_UInt32  st_gpio_19_pd:1;
        RBus_UInt32  st_gpio_19_pu:1;
        RBus_UInt32  st_gpio_19_ps:4;
        RBus_UInt32  st_gpio_18_sr:1;
        RBus_UInt32  st_gpio_18_ds:1;
        RBus_UInt32  st_gpio_18_pd:1;
        RBus_UInt32  st_gpio_18_pu:1;
        RBus_UInt32  st_gpio_18_ps:4;
        RBus_UInt32  st_gpio_17_sr:1;
        RBus_UInt32  st_gpio_17_ds:1;
        RBus_UInt32  st_gpio_17_pd:1;
        RBus_UInt32  st_gpio_17_pu:1;
        RBus_UInt32  st_gpio_17_ps:4;
        RBus_UInt32  st_gpio_16_sr:1;
        RBus_UInt32  st_gpio_16_ds:1;
        RBus_UInt32  st_gpio_16_pd:1;
        RBus_UInt32  st_gpio_16_pu:1;
        RBus_UInt32  st_gpio_16_ps:4;
    };
}pinmux_st_st_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_23_sr:1;
        RBus_UInt32  st_gpio_23_ds:1;
        RBus_UInt32  st_gpio_23_pd:1;
        RBus_UInt32  st_gpio_23_pu:1;
        RBus_UInt32  st_gpio_23_ps:4;
        RBus_UInt32  st_gpio_22_sr:1;
        RBus_UInt32  st_gpio_22_ds:1;
        RBus_UInt32  st_gpio_22_pd:1;
        RBus_UInt32  st_gpio_22_pu:1;
        RBus_UInt32  st_gpio_22_ps:4;
        RBus_UInt32  st_gpio_21_sr:1;
        RBus_UInt32  st_gpio_21_ds:1;
        RBus_UInt32  st_gpio_21_pd:1;
        RBus_UInt32  st_gpio_21_pu:1;
        RBus_UInt32  st_gpio_21_ps:4;
        RBus_UInt32  st_gpio_20_sr:1;
        RBus_UInt32  st_gpio_20_ds:1;
        RBus_UInt32  st_gpio_20_pd:1;
        RBus_UInt32  st_gpio_20_pu:1;
        RBus_UInt32  st_gpio_20_ps:4;
    };
}pinmux_st_st_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_27_sr:1;
        RBus_UInt32  st_gpio_27_ds:1;
        RBus_UInt32  st_gpio_27_pd:1;
        RBus_UInt32  st_gpio_27_pu:1;
        RBus_UInt32  st_gpio_27_ps:4;
        RBus_UInt32  st_gpio_26_sr:1;
        RBus_UInt32  st_gpio_26_ds:1;
        RBus_UInt32  st_gpio_26_pd:1;
        RBus_UInt32  st_gpio_26_pu:1;
        RBus_UInt32  st_gpio_26_ps:4;
        RBus_UInt32  st_gpio_25_sr:1;
        RBus_UInt32  st_gpio_25_ds:1;
        RBus_UInt32  st_gpio_25_pd:1;
        RBus_UInt32  st_gpio_25_pu:1;
        RBus_UInt32  st_gpio_25_ps:4;
        RBus_UInt32  st_gpio_24_sr:1;
        RBus_UInt32  st_gpio_24_ds:1;
        RBus_UInt32  st_gpio_24_pd:1;
        RBus_UInt32  st_gpio_24_pu:1;
        RBus_UInt32  st_gpio_24_ps:4;
    };
}pinmux_st_st_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_31_sr:1;
        RBus_UInt32  st_gpio_31_ds:1;
        RBus_UInt32  st_gpio_31_pd:1;
        RBus_UInt32  st_gpio_31_pu:1;
        RBus_UInt32  st_gpio_31_ps:4;
        RBus_UInt32  st_gpio_30_sr:1;
        RBus_UInt32  st_gpio_30_ds:1;
        RBus_UInt32  st_gpio_30_pd:1;
        RBus_UInt32  st_gpio_30_pu:1;
        RBus_UInt32  st_gpio_30_ps:4;
        RBus_UInt32  st_gpio_29_sr:1;
        RBus_UInt32  st_gpio_29_ds:1;
        RBus_UInt32  st_gpio_29_pd:1;
        RBus_UInt32  st_gpio_29_pu:1;
        RBus_UInt32  st_gpio_29_ps:4;
        RBus_UInt32  st_gpio_28_sr:1;
        RBus_UInt32  st_gpio_28_ds:1;
        RBus_UInt32  st_gpio_28_pd:1;
        RBus_UInt32  st_gpio_28_pu:1;
        RBus_UInt32  st_gpio_28_ps:4;
    };
}pinmux_st_st_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  st_gpio_32_sr:1;
        RBus_UInt32  st_gpio_32_ds:1;
        RBus_UInt32  st_gpio_32_pd:1;
        RBus_UInt32  st_gpio_32_pu:1;
        RBus_UInt32  st_gpio_32_ps:4;
    };
}pinmux_st_st_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stb_dio_ps:4;
        RBus_UInt32  lsadc7_ps:4;
        RBus_UInt32  lsadc6_ps:4;
        RBus_UInt32  lsadc4_ps:4;
        RBus_UInt32  res1:16;
    };
}pinmux_st_st_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_31_smt:1;
        RBus_UInt32  st_gpio_30_smt:1;
        RBus_UInt32  st_gpio_29_smt:1;
        RBus_UInt32  st_gpio_28_smt:1;
        RBus_UInt32  st_gpio_27_smt:1;
        RBus_UInt32  st_gpio_26_smt:1;
        RBus_UInt32  st_gpio_25_smt:1;
        RBus_UInt32  st_gpio_24_smt:1;
        RBus_UInt32  st_gpio_23_smt:1;
        RBus_UInt32  st_gpio_22_smt:1;
        RBus_UInt32  st_gpio_21_smt:1;
        RBus_UInt32  st_gpio_20_smt:1;
        RBus_UInt32  st_gpio_19_smt:1;
        RBus_UInt32  st_gpio_18_smt:1;
        RBus_UInt32  st_gpio_17_smt:1;
        RBus_UInt32  st_gpio_16_smt:1;
        RBus_UInt32  st_gpio_15_smt:1;
        RBus_UInt32  st_gpio_14_smt:1;
        RBus_UInt32  st_gpio_13_smt:1;
        RBus_UInt32  st_gpio_12_smt:1;
        RBus_UInt32  st_gpio_11_smt:1;
        RBus_UInt32  st_gpio_10_smt:1;
        RBus_UInt32  st_gpio_9_smt:1;
        RBus_UInt32  st_gpio_8_smt:1;
        RBus_UInt32  st_gpio_7_smt:1;
        RBus_UInt32  st_gpio_6_smt:1;
        RBus_UInt32  st_gpio_5_smt:1;
        RBus_UInt32  st_gpio_4_smt:1;
        RBus_UInt32  st_gpio_3_smt:1;
        RBus_UInt32  st_gpio_2_smt:1;
        RBus_UInt32  st_gpio_1_smt:1;
        RBus_UInt32  st_gpio_0_smt:1;
    };
}pinmux_st_st_schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  jd_gpi_en:7;
        RBus_UInt32  stb_gpi_en:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  st_gpio_32_smt:1;
    };
}pinmux_st_st_schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  dtv_i2c_sel:1;
        RBus_UInt32  i2c0_in_sel:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  uart0_rxdi_in_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  emcu_ur_rx_in_sel:2;
        RBus_UInt32  res4:14;
    };
}pinmux_st_st_pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iso_uni_pwm_0_sel:1;
        RBus_UInt32  iso_uni_pwm_1_sel:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  st_testpin_mux:8;
        RBus_UInt32  res2:16;
    };
}pinmux_st_st_test_pin_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spi_porl_release:1;
        RBus_UInt32  res1:31;
    };
}pinmux_st_st_porl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_2_ie_v18:1;
        RBus_UInt32  res1:31;
    };
}pinmux_st_st_v18_control_RBUS;




#endif


#endif
