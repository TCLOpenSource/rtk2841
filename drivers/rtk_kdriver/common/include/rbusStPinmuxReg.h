/**
* @file rbusPinmuxReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2010/6/21
* @version 1.1
* @ingroup model_rbus
*
*/

#ifndef _RBUS_STPINMUX_REG_H_
#define _RBUS_STPINMUX_REG_H_

#include "rbusTypes.h"




// PINMUX Register Address

#define PINMUX_ST_CFG_0_VADDR                      (0xb8060200)
#define PINMUX_ST_CFG_1_VADDR                      (0xb8060204)
#define PINMUX_ST_CFG_2_VADDR                      (0xb8060208)
#define PINMUX_ST_CFG_3_VADDR                      (0xb8060210)
#define PINMUX_ST_CFG_4_VADDR                      (0xb8060214)
#define PINMUX_ST_CFG_5_VADDR                      (0xb8060218)
#define PINMUX_ST_CFG_6_VADDR                      (0xb806021c)
#define PINMUX_ST_CFG_7_VADDR                      (0xb8060220)
#define PINMUX_ST_CFG_8_VADDR                      (0xb8060224)
#define PINMUX_ST_CFG_9_VADDR                      (0xb8060228)
#define PINMUX_ST_CFG_10_VADDR                     (0xb806022c)
#define PINMUX_ST_CFG_11_VADDR                     (0xb8060230)
#define PINMUX_ST_SPI_CFG_VADDR                    (0xb8060250)
#define PINMUX_ST_BOPTION_CFG_0_VADDR              (0xb8060260)
#define PINMUX_ST_BOPTION_CFG_1_VADDR              (0xb8060264)
#define PINMUX_ST_BOPTION_CFG_2_VADDR              (0xb8060268)
#define PINMUX_ST_SCHMIDT_TRIGGER_0_VADDR          (0xb8060280)
#define PINMUX_ST_SCHMIDT_TRIGGER_1_VADDR          (0xb8060284)
#define PINMUX_ST_PIN_MUX_CTRL0_VADDR              (0xb80602a0)
#define PINMUX_ST_TEST_PIN_CTRL_VADDR              (0xb80602a4)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======PINMUX register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hddc0_scl_ps:4;
        RBus_UInt32  hddc0_scl_pu:1;
        RBus_UInt32  hddc0_scl_pd:1;
        RBus_UInt32  hddc0_scl_ds:1;
        RBus_UInt32  hddc0_scl_sr:1;
        RBus_UInt32  hddc0_sda_ps:4;
        RBus_UInt32  hddc0_sda_pu:1;
        RBus_UInt32  hddc0_sda_pd:1;
        RBus_UInt32  hddc0_sda_ds:1;
        RBus_UInt32  hddc0_sda_sr:1;
        RBus_UInt32  vddc_scl_ps:4;
        RBus_UInt32  vddc_scl_pu:1;
        RBus_UInt32  vddc_scl_pd:1;
        RBus_UInt32  vddc_scl_ds:1;
        RBus_UInt32  vddc_scl_sr:1;
        RBus_UInt32  vddc_sda_ps:4;
        RBus_UInt32  vddc_sda_pu:1;
        RBus_UInt32  vddc_sda_pd:1;
        RBus_UInt32  vddc_sda_ds:1;
        RBus_UInt32  vddc_sda_sr:1;
    };
}st_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hddc2_scl_ps:4;
        RBus_UInt32  hddc2_scl_pu:1;
        RBus_UInt32  hddc2_scl_pd:1;
        RBus_UInt32  hddc2_scl_ds:1;
        RBus_UInt32  hddc2_scl_sr:1;
        RBus_UInt32  hddc2_sda_ps:4;
        RBus_UInt32  hddc2_sda_pu:1;
        RBus_UInt32  hddc2_sda_pd:1;
        RBus_UInt32  hddc2_sda_ds:1;
        RBus_UInt32  hddc2_sda_sr:1;
        RBus_UInt32  hddc1_scl_ps:4;
        RBus_UInt32  hddc1_scl_pu:1;
        RBus_UInt32  hddc1_scl_pd:1;
        RBus_UInt32  hddc1_scl_ds:1;
        RBus_UInt32  hddc1_scl_sr:1;
        RBus_UInt32  hddc1_sda_ps:4;
        RBus_UInt32  hddc1_sda_pu:1;
        RBus_UInt32  hddc1_sda_pd:1;
        RBus_UInt32  hddc1_sda_ds:1;
        RBus_UInt32  hddc1_sda_sr:1;
    };
}st_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lsadc5_ps:4;
        RBus_UInt32  lsadc4_ps:4;
        RBus_UInt32  lsadc3_ps:4;
        RBus_UInt32  lsadc2_ps:4;
        RBus_UInt32  lsadc1_ps:4;
        RBus_UInt32  lsadc0_ps:4;
    };
}st_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lsadc_ref_ps:4;
        RBus_UInt32  res1:28;
    };
}st_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rst_out_ps:4;
        RBus_UInt32  rst_out_pu:1;
        RBus_UInt32  rst_out_pd:1;
        RBus_UInt32  rst_out_ds:1;
        RBus_UInt32  rst_out_sr:1;
        RBus_UInt32  rst_in_ps:4;
        RBus_UInt32  rst_in_pu:1;
        RBus_UInt32  rst_in_pd:1;
        RBus_UInt32  rst_in_ds:1;
        RBus_UInt32  rst_in_sr:1;
    };
}st_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}st_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  st_gpio_25_ps:4;
        RBus_UInt32  st_gpio_25_pu:1;
        RBus_UInt32  st_gpio_25_pd:1;
        RBus_UInt32  st_gpio_25_ds:1;
        RBus_UInt32  st_gpio_25_sr:1;
        RBus_UInt32  st_gpio_24_ps:4;
        RBus_UInt32  st_gpio_24_pu:1;
        RBus_UInt32  st_gpio_24_pd:1;
        RBus_UInt32  st_gpio_24_ds:1;
        RBus_UInt32  st_gpio_24_sr:1;
    };
}st_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_23_ps:4;
        RBus_UInt32  st_gpio_23_pu:1;
        RBus_UInt32  st_gpio_23_pd:1;
        RBus_UInt32  st_gpio_23_ds:1;
        RBus_UInt32  st_gpio_23_sr:1;
        RBus_UInt32  st_gpio_22_ps:4;
        RBus_UInt32  st_gpio_22_pu:1;
        RBus_UInt32  st_gpio_22_pd:1;
        RBus_UInt32  st_gpio_22_ds:1;
        RBus_UInt32  st_gpio_22_sr:1;
        RBus_UInt32  st_gpio_21_ps:4;
        RBus_UInt32  st_gpio_21_pu:1;
        RBus_UInt32  st_gpio_21_pd:1;
        RBus_UInt32  st_gpio_21_ds:1;
        RBus_UInt32  st_gpio_21_sr:1;
        RBus_UInt32  st_gpio_20_ps:4;
        RBus_UInt32  st_gpio_20_pu:1;
        RBus_UInt32  st_gpio_20_pd:1;
        RBus_UInt32  st_gpio_20_ds:1;
        RBus_UInt32  st_gpio_20_sr:1;
    };
}st_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_19_ps:4;
        RBus_UInt32  st_gpio_19_pu:1;
        RBus_UInt32  st_gpio_19_pd:1;
        RBus_UInt32  st_gpio_19_ds:1;
        RBus_UInt32  st_gpio_19_sr:1;
        RBus_UInt32  st_gpio_18_ps:4;
        RBus_UInt32  st_gpio_18_pu:1;
        RBus_UInt32  st_gpio_18_pd:1;
        RBus_UInt32  st_gpio_18_ds:1;
        RBus_UInt32  st_gpio_18_sr:1;
        RBus_UInt32  st_gpio_17_ps:4;
        RBus_UInt32  st_gpio_17_pu:1;
        RBus_UInt32  st_gpio_17_pd:1;
        RBus_UInt32  st_gpio_17_ds:1;
        RBus_UInt32  st_gpio_17_sr:1;
        RBus_UInt32  st_gpio_16_ps:4;
        RBus_UInt32  st_gpio_16_pu:1;
        RBus_UInt32  st_gpio_16_pd:1;
        RBus_UInt32  st_gpio_16_ds:1;
        RBus_UInt32  st_gpio_16_sr:1;
    };
}st_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_15_ps:4;
        RBus_UInt32  st_gpio_15_pu:1;
        RBus_UInt32  st_gpio_15_pd:1;
        RBus_UInt32  st_gpio_15_ds:1;
        RBus_UInt32  st_gpio_15_sr:1;
        RBus_UInt32  st_gpio_14_ps:4;
        RBus_UInt32  st_gpio_14_pu:1;
        RBus_UInt32  st_gpio_14_pd:1;
        RBus_UInt32  st_gpio_14_ds:1;
        RBus_UInt32  st_gpio_14_sr:1;
        RBus_UInt32  st_gpio_13_ps:4;
        RBus_UInt32  st_gpio_13_pu:1;
        RBus_UInt32  st_gpio_13_pd:1;
        RBus_UInt32  st_gpio_13_ds:1;
        RBus_UInt32  st_gpio_13_sr:1;
        RBus_UInt32  st_gpio_12_ps:4;
        RBus_UInt32  st_gpio_12_pu:1;
        RBus_UInt32  st_gpio_12_pd:1;
        RBus_UInt32  st_gpio_12_ds:1;
        RBus_UInt32  st_gpio_12_sr:1;
    };
}st_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_11_ps:4;
        RBus_UInt32  st_gpio_11_pu:1;
        RBus_UInt32  st_gpio_11_pd:1;
        RBus_UInt32  st_gpio_11_ds:1;
        RBus_UInt32  st_gpio_11_sr:1;
        RBus_UInt32  st_gpio_10_ps:4;
        RBus_UInt32  st_gpio_10_pu:1;
        RBus_UInt32  st_gpio_10_pd:1;
        RBus_UInt32  st_gpio_10_ds:1;
        RBus_UInt32  st_gpio_10_sr:1;
        RBus_UInt32  st_gpio_9_ps:4;
        RBus_UInt32  st_gpio_9_pu:1;
        RBus_UInt32  st_gpio_9_pd:1;
        RBus_UInt32  st_gpio_9_ds:1;
        RBus_UInt32  st_gpio_9_sr:1;
        RBus_UInt32  st_gpio_8_ps:4;
        RBus_UInt32  st_gpio_8_pu:1;
        RBus_UInt32  st_gpio_8_pd:1;
        RBus_UInt32  st_gpio_8_ds:1;
        RBus_UInt32  st_gpio_8_sr:1;
    };
}st_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_7_ps:4;
        RBus_UInt32  st_gpio_7_pu:1;
        RBus_UInt32  st_gpio_7_pd:1;
        RBus_UInt32  st_gpio_7_ds:1;
        RBus_UInt32  st_gpio_7_sr:1;
        RBus_UInt32  st_gpio_6_ps:4;
        RBus_UInt32  st_gpio_6_pu:1;
        RBus_UInt32  st_gpio_6_pd:1;
        RBus_UInt32  st_gpio_6_ds:1;
        RBus_UInt32  st_gpio_6_sr:1;
        RBus_UInt32  res1:16;
    };
}st_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spi_cs_n_ps:4;
        RBus_UInt32  spi_cs_n_pu:1;
        RBus_UInt32  spi_cs_n_pd:1;
        RBus_UInt32  spi_cs_n_ds:1;
        RBus_UInt32  spi_cs_n_sr:1;
        RBus_UInt32  spi_sck_ps:4;
        RBus_UInt32  spi_sck_pu:1;
        RBus_UInt32  spi_sck_pd:1;
        RBus_UInt32  spi_sck_ds:1;
        RBus_UInt32  spi_sck_sr:1;
        RBus_UInt32  spi_do_ps:4;
        RBus_UInt32  spi_do_pu:1;
        RBus_UInt32  spi_do_pd:1;
        RBus_UInt32  spi_do_ds:1;
        RBus_UInt32  spi_do_sr:1;
        RBus_UInt32  spi_di_ps:4;
        RBus_UInt32  spi_di_pu:1;
        RBus_UInt32  spi_di_pd:1;
        RBus_UInt32  spi_di_ds:1;
        RBus_UInt32  spi_di_sr:1;
    };
}st_spi_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:4;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:4;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  res20:1;
    };
}st_boption_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:4;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:4;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  res20:1;
    };
}st_boption_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:16;
    };
}st_boption_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rst_in_smt:1;
        RBus_UInt32  rst_out_smt:1;
        RBus_UInt32  spi_cs_n_smt:1;
        RBus_UInt32  spi_sck_smt:1;
        RBus_UInt32  spi_do_smt:1;
        RBus_UInt32  spi_di_smt:1;
        RBus_UInt32  vddc_sda_smt:1;
        RBus_UInt32  vddc_scl_smt:1;
        RBus_UInt32  hddc2_sda_smt:1;
        RBus_UInt32  hddc2_scl_smt:1;
        RBus_UInt32  hddc1_sda_smt:1;
        RBus_UInt32  hddc1_scl_smt:1;
        RBus_UInt32  hddc0_sda_smt:1;
        RBus_UInt32  hddc0_scl_smt:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:7;
    };
}st_schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
        RBus_UInt32  res1:12;
    };
}st_schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  st_uart1_in_sel:2;
        RBus_UInt32  st_uart2_in_sel:1;
        RBus_UInt32  st_uart0_in_sel:1;
        RBus_UInt32  st_irrx_in_sel:2;
        RBus_UInt32  st_i2c0_in_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  st_i2c1_in_sel:1;
        RBus_UInt32  st_i2c2_in_sel:2;
    };
}st_pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_dummy:16;
        RBus_UInt32  st_ext_clk_en:8;
        RBus_UInt32  st_testpin_mux:8;
    };
}st_test_pin_ctrl_RBUS;





#else //apply LITTLE_ENDIAN


//======PINMUX register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vddc_sda_sr:1;
        RBus_UInt32  vddc_sda_ds:1;
        RBus_UInt32  vddc_sda_pd:1;
        RBus_UInt32  vddc_sda_pu:1;
        RBus_UInt32  vddc_sda_ps:4;
        RBus_UInt32  vddc_scl_sr:1;
        RBus_UInt32  vddc_scl_ds:1;
        RBus_UInt32  vddc_scl_pd:1;
        RBus_UInt32  vddc_scl_pu:1;
        RBus_UInt32  vddc_scl_ps:4;
        RBus_UInt32  hddc0_sda_sr:1;
        RBus_UInt32  hddc0_sda_ds:1;
        RBus_UInt32  hddc0_sda_pd:1;
        RBus_UInt32  hddc0_sda_pu:1;
        RBus_UInt32  hddc0_sda_ps:4;
        RBus_UInt32  hddc0_scl_sr:1;
        RBus_UInt32  hddc0_scl_ds:1;
        RBus_UInt32  hddc0_scl_pd:1;
        RBus_UInt32  hddc0_scl_pu:1;
        RBus_UInt32  hddc0_scl_ps:4;
    };
}st_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hddc1_sda_sr:1;
        RBus_UInt32  hddc1_sda_ds:1;
        RBus_UInt32  hddc1_sda_pd:1;
        RBus_UInt32  hddc1_sda_pu:1;
        RBus_UInt32  hddc1_sda_ps:4;
        RBus_UInt32  hddc1_scl_sr:1;
        RBus_UInt32  hddc1_scl_ds:1;
        RBus_UInt32  hddc1_scl_pd:1;
        RBus_UInt32  hddc1_scl_pu:1;
        RBus_UInt32  hddc1_scl_ps:4;
        RBus_UInt32  hddc2_sda_sr:1;
        RBus_UInt32  hddc2_sda_ds:1;
        RBus_UInt32  hddc2_sda_pd:1;
        RBus_UInt32  hddc2_sda_pu:1;
        RBus_UInt32  hddc2_sda_ps:4;
        RBus_UInt32  hddc2_scl_sr:1;
        RBus_UInt32  hddc2_scl_ds:1;
        RBus_UInt32  hddc2_scl_pd:1;
        RBus_UInt32  hddc2_scl_pu:1;
        RBus_UInt32  hddc2_scl_ps:4;
    };
}st_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lsadc0_ps:4;
        RBus_UInt32  lsadc1_ps:4;
        RBus_UInt32  lsadc2_ps:4;
        RBus_UInt32  lsadc3_ps:4;
        RBus_UInt32  lsadc4_ps:4;
        RBus_UInt32  lsadc5_ps:4;
        RBus_UInt32  res1:8;
    };
}st_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  lsadc_ref_ps:4;
    };
}st_cfg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rst_in_sr:1;
        RBus_UInt32  rst_in_ds:1;
        RBus_UInt32  rst_in_pd:1;
        RBus_UInt32  rst_in_pu:1;
        RBus_UInt32  rst_in_ps:4;
        RBus_UInt32  rst_out_sr:1;
        RBus_UInt32  rst_out_ds:1;
        RBus_UInt32  rst_out_pd:1;
        RBus_UInt32  rst_out_pu:1;
        RBus_UInt32  rst_out_ps:4;
        RBus_UInt32  res1:16;
    };
}st_cfg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}st_cfg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_24_sr:1;
        RBus_UInt32  st_gpio_24_ds:1;
        RBus_UInt32  st_gpio_24_pd:1;
        RBus_UInt32  st_gpio_24_pu:1;
        RBus_UInt32  st_gpio_24_ps:4;
        RBus_UInt32  st_gpio_25_sr:1;
        RBus_UInt32  st_gpio_25_ds:1;
        RBus_UInt32  st_gpio_25_pd:1;
        RBus_UInt32  st_gpio_25_pu:1;
        RBus_UInt32  st_gpio_25_ps:4;
        RBus_UInt32  res1:16;
    };
}st_cfg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_20_sr:1;
        RBus_UInt32  st_gpio_20_ds:1;
        RBus_UInt32  st_gpio_20_pd:1;
        RBus_UInt32  st_gpio_20_pu:1;
        RBus_UInt32  st_gpio_20_ps:4;
        RBus_UInt32  st_gpio_21_sr:1;
        RBus_UInt32  st_gpio_21_ds:1;
        RBus_UInt32  st_gpio_21_pd:1;
        RBus_UInt32  st_gpio_21_pu:1;
        RBus_UInt32  st_gpio_21_ps:4;
        RBus_UInt32  st_gpio_22_sr:1;
        RBus_UInt32  st_gpio_22_ds:1;
        RBus_UInt32  st_gpio_22_pd:1;
        RBus_UInt32  st_gpio_22_pu:1;
        RBus_UInt32  st_gpio_22_ps:4;
        RBus_UInt32  st_gpio_23_sr:1;
        RBus_UInt32  st_gpio_23_ds:1;
        RBus_UInt32  st_gpio_23_pd:1;
        RBus_UInt32  st_gpio_23_pu:1;
        RBus_UInt32  st_gpio_23_ps:4;
    };
}st_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_16_sr:1;
        RBus_UInt32  st_gpio_16_ds:1;
        RBus_UInt32  st_gpio_16_pd:1;
        RBus_UInt32  st_gpio_16_pu:1;
        RBus_UInt32  st_gpio_16_ps:4;
        RBus_UInt32  st_gpio_17_sr:1;
        RBus_UInt32  st_gpio_17_ds:1;
        RBus_UInt32  st_gpio_17_pd:1;
        RBus_UInt32  st_gpio_17_pu:1;
        RBus_UInt32  st_gpio_17_ps:4;
        RBus_UInt32  st_gpio_18_sr:1;
        RBus_UInt32  st_gpio_18_ds:1;
        RBus_UInt32  st_gpio_18_pd:1;
        RBus_UInt32  st_gpio_18_pu:1;
        RBus_UInt32  st_gpio_18_ps:4;
        RBus_UInt32  st_gpio_19_sr:1;
        RBus_UInt32  st_gpio_19_ds:1;
        RBus_UInt32  st_gpio_19_pd:1;
        RBus_UInt32  st_gpio_19_pu:1;
        RBus_UInt32  st_gpio_19_ps:4;
    };
}st_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_12_sr:1;
        RBus_UInt32  st_gpio_12_ds:1;
        RBus_UInt32  st_gpio_12_pd:1;
        RBus_UInt32  st_gpio_12_pu:1;
        RBus_UInt32  st_gpio_12_ps:4;
        RBus_UInt32  st_gpio_13_sr:1;
        RBus_UInt32  st_gpio_13_ds:1;
        RBus_UInt32  st_gpio_13_pd:1;
        RBus_UInt32  st_gpio_13_pu:1;
        RBus_UInt32  st_gpio_13_ps:4;
        RBus_UInt32  st_gpio_14_sr:1;
        RBus_UInt32  st_gpio_14_ds:1;
        RBus_UInt32  st_gpio_14_pd:1;
        RBus_UInt32  st_gpio_14_pu:1;
        RBus_UInt32  st_gpio_14_ps:4;
        RBus_UInt32  st_gpio_15_sr:1;
        RBus_UInt32  st_gpio_15_ds:1;
        RBus_UInt32  st_gpio_15_pd:1;
        RBus_UInt32  st_gpio_15_pu:1;
        RBus_UInt32  st_gpio_15_ps:4;
    };
}st_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_gpio_8_sr:1;
        RBus_UInt32  st_gpio_8_ds:1;
        RBus_UInt32  st_gpio_8_pd:1;
        RBus_UInt32  st_gpio_8_pu:1;
        RBus_UInt32  st_gpio_8_ps:4;
        RBus_UInt32  st_gpio_9_sr:1;
        RBus_UInt32  st_gpio_9_ds:1;
        RBus_UInt32  st_gpio_9_pd:1;
        RBus_UInt32  st_gpio_9_pu:1;
        RBus_UInt32  st_gpio_9_ps:4;
        RBus_UInt32  st_gpio_10_sr:1;
        RBus_UInt32  st_gpio_10_ds:1;
        RBus_UInt32  st_gpio_10_pd:1;
        RBus_UInt32  st_gpio_10_pu:1;
        RBus_UInt32  st_gpio_10_ps:4;
        RBus_UInt32  st_gpio_11_sr:1;
        RBus_UInt32  st_gpio_11_ds:1;
        RBus_UInt32  st_gpio_11_pd:1;
        RBus_UInt32  st_gpio_11_pu:1;
        RBus_UInt32  st_gpio_11_ps:4;
    };
}st_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  st_gpio_6_sr:1;
        RBus_UInt32  st_gpio_6_ds:1;
        RBus_UInt32  st_gpio_6_pd:1;
        RBus_UInt32  st_gpio_6_pu:1;
        RBus_UInt32  st_gpio_6_ps:4;
        RBus_UInt32  st_gpio_7_sr:1;
        RBus_UInt32  st_gpio_7_ds:1;
        RBus_UInt32  st_gpio_7_pd:1;
        RBus_UInt32  st_gpio_7_pu:1;
        RBus_UInt32  st_gpio_7_ps:4;
    };
}st_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spi_di_sr:1;
        RBus_UInt32  spi_di_ds:1;
        RBus_UInt32  spi_di_pd:1;
        RBus_UInt32  spi_di_pu:1;
        RBus_UInt32  spi_di_ps:4;
        RBus_UInt32  spi_do_sr:1;
        RBus_UInt32  spi_do_ds:1;
        RBus_UInt32  spi_do_pd:1;
        RBus_UInt32  spi_do_pu:1;
        RBus_UInt32  spi_do_ps:4;
        RBus_UInt32  spi_sck_sr:1;
        RBus_UInt32  spi_sck_ds:1;
        RBus_UInt32  spi_sck_pd:1;
        RBus_UInt32  spi_sck_pu:1;
        RBus_UInt32  spi_sck_ps:4;
        RBus_UInt32  spi_cs_n_sr:1;
        RBus_UInt32  spi_cs_n_ds:1;
        RBus_UInt32  spi_cs_n_pd:1;
        RBus_UInt32  spi_cs_n_pu:1;
        RBus_UInt32  spi_cs_n_ps:4;
    };
}st_spi_cfg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res20:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res16:4;
        RBus_UInt32  res15:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res11:4;
        RBus_UInt32  res10:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:4;
    };
}st_boption_cfg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res20:1;
        RBus_UInt32  res19:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res16:4;
        RBus_UInt32  res15:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res11:4;
        RBus_UInt32  res10:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:4;
    };
}st_boption_cfg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res11:16;
        RBus_UInt32  res10:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res6:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:4;
    };
}st_boption_cfg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res12:7;
        RBus_UInt32  res11:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hddc0_scl_smt:1;
        RBus_UInt32  hddc0_sda_smt:1;
        RBus_UInt32  hddc1_scl_smt:1;
        RBus_UInt32  hddc1_sda_smt:1;
        RBus_UInt32  hddc2_scl_smt:1;
        RBus_UInt32  hddc2_sda_smt:1;
        RBus_UInt32  vddc_scl_smt:1;
        RBus_UInt32  vddc_sda_smt:1;
        RBus_UInt32  spi_di_smt:1;
        RBus_UInt32  spi_do_smt:1;
        RBus_UInt32  spi_sck_smt:1;
        RBus_UInt32  spi_cs_n_smt:1;
        RBus_UInt32  rst_out_smt:1;
        RBus_UInt32  rst_in_smt:1;
        RBus_UInt32  res1:1;
    };
}st_schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
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
    };
}st_schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_i2c2_in_sel:2;
        RBus_UInt32  st_i2c1_in_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  st_i2c0_in_sel:2;
        RBus_UInt32  st_irrx_in_sel:2;
        RBus_UInt32  st_uart0_in_sel:1;
        RBus_UInt32  st_uart2_in_sel:1;
        RBus_UInt32  st_uart1_in_sel:2;
        RBus_UInt32  res1:20;
    };
}st_pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_testpin_mux:8;
        RBus_UInt32  st_ext_clk_en:8;
        RBus_UInt32  st_dummy:16;
    };
}st_test_pin_ctrl_RBUS;


#endif







#endif //_RBUS_PINMUX_REG_H_


