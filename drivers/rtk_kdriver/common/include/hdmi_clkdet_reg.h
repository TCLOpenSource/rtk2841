/**
* @file rbusHDMI_CLKDETReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_HDMI_CLKDET_REG_H_
#define _RBUS_HDMI_CLKDET_REG_H_

#include "rbus_types.h"



//  HDMI_CLKDET Register Address
#define  HDMI_CLKDET_CLKDETCR                                                    0x18061F00
#define  HDMI_CLKDET_CLKDETCR_reg_addr                                           "0xB8061F00"
#define  HDMI_CLKDET_CLKDETCR_reg                                                0xB8061F00
#define  HDMI_CLKDET_CLKDETCR_inst_addr                                          "0x0000"
#define  set_HDMI_CLKDET_CLKDETCR_reg(data)                                      (*((volatile unsigned int*)HDMI_CLKDET_CLKDETCR_reg)=data)
#define  get_HDMI_CLKDET_CLKDETCR_reg                                            (*((volatile unsigned int*)HDMI_CLKDET_CLKDETCR_reg))
#define  HDMI_CLKDET_CLKDETCR_dummy_31_1_shift                                   (1)
#define  HDMI_CLKDET_CLKDETCR_clock_det_en_shift                                 (0)
#define  HDMI_CLKDET_CLKDETCR_dummy_31_1_mask                                    (0xFFFFFFFE)
#define  HDMI_CLKDET_CLKDETCR_clock_det_en_mask                                  (0x00000001)
#define  HDMI_CLKDET_CLKDETCR_dummy_31_1(data)                                   (0xFFFFFFFE&((data)<<1))
#define  HDMI_CLKDET_CLKDETCR_clock_det_en(data)                                 (0x00000001&(data))
#define  HDMI_CLKDET_CLKDETCR_get_dummy_31_1(data)                               ((0xFFFFFFFE&(data))>>1)
#define  HDMI_CLKDET_CLKDETCR_get_clock_det_en(data)                             (0x00000001&(data))

#define  HDMI_CLKDET_CLKDETSR                                                    0x18061F04
#define  HDMI_CLKDET_CLKDETSR_reg_addr                                           "0xB8061F04"
#define  HDMI_CLKDET_CLKDETSR_reg                                                0xB8061F04
#define  HDMI_CLKDET_CLKDETSR_inst_addr                                          "0x0001"
#define  set_HDMI_CLKDET_CLKDETSR_reg(data)                                      (*((volatile unsigned int*)HDMI_CLKDET_CLKDETSR_reg)=data)
#define  get_HDMI_CLKDET_CLKDETSR_reg                                            (*((volatile unsigned int*)HDMI_CLKDET_CLKDETSR_reg))
#define  HDMI_CLKDET_CLKDETSR_en_tmds_chg_irq_shift                              (5)
#define  HDMI_CLKDET_CLKDETSR_tmds_chg_irq_shift                                 (4)
#define  HDMI_CLKDET_CLKDETSR_dummy_3_2_shift                                    (2)
#define  HDMI_CLKDET_CLKDETSR_clk_in_target_irq_en_shift                         (1)
#define  HDMI_CLKDET_CLKDETSR_clk_in_target_shift                                (0)
#define  HDMI_CLKDET_CLKDETSR_en_tmds_chg_irq_mask                               (0x00000020)
#define  HDMI_CLKDET_CLKDETSR_tmds_chg_irq_mask                                  (0x00000010)
#define  HDMI_CLKDET_CLKDETSR_dummy_3_2_mask                                     (0x0000000C)
#define  HDMI_CLKDET_CLKDETSR_clk_in_target_irq_en_mask                          (0x00000002)
#define  HDMI_CLKDET_CLKDETSR_clk_in_target_mask                                 (0x00000001)
#define  HDMI_CLKDET_CLKDETSR_en_tmds_chg_irq(data)                              (0x00000020&((data)<<5))
#define  HDMI_CLKDET_CLKDETSR_tmds_chg_irq(data)                                 (0x00000010&((data)<<4))
#define  HDMI_CLKDET_CLKDETSR_dummy_3_2(data)                                    (0x0000000C&((data)<<2))
#define  HDMI_CLKDET_CLKDETSR_clk_in_target_irq_en(data)                         (0x00000002&((data)<<1))
#define  HDMI_CLKDET_CLKDETSR_clk_in_target(data)                                (0x00000001&(data))
#define  HDMI_CLKDET_CLKDETSR_get_en_tmds_chg_irq(data)                          ((0x00000020&(data))>>5)
#define  HDMI_CLKDET_CLKDETSR_get_tmds_chg_irq(data)                             ((0x00000010&(data))>>4)
#define  HDMI_CLKDET_CLKDETSR_get_dummy_3_2(data)                                ((0x0000000C&(data))>>2)
#define  HDMI_CLKDET_CLKDETSR_get_clk_in_target_irq_en(data)                     ((0x00000002&(data))>>1)
#define  HDMI_CLKDET_CLKDETSR_get_clk_in_target(data)                            (0x00000001&(data))

#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00                                      0x18061F08
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_reg_addr                             "0xB8061F08"
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_reg                                  0xB8061F08
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_inst_addr                            "0x0002"
#define  set_HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_reg(data)                        (*((volatile unsigned int*)HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_reg)=data)
#define  get_HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_reg                              (*((volatile unsigned int*)HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_reg))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_dclk_cnt_start_shift                 (16)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_dclk_cnt_end_shift                   (0)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_dclk_cnt_start_mask                  (0x0FFF0000)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_dclk_cnt_end_mask                    (0x00000FFF)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_dclk_cnt_start(data)                 (0x0FFF0000&((data)<<16))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_dclk_cnt_end(data)                   (0x00000FFF&(data))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_get_dclk_cnt_start(data)             ((0x0FFF0000&(data))>>16)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_00_get_dclk_cnt_end(data)               (0x00000FFF&(data))

#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01                                      0x18061F0C
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_reg_addr                             "0xB8061F0C"
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_reg                                  0xB8061F0C
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_inst_addr                            "0x0003"
#define  set_HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_reg(data)                        (*((volatile unsigned int*)HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_reg)=data)
#define  get_HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_reg                              (*((volatile unsigned int*)HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_reg))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_target_for_maximum_clk_counter_shift (16)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_target_for_minimum_clk_counter_shift (0)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_target_for_maximum_clk_counter_mask  (0x0FFF0000)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_target_for_minimum_clk_counter_mask  (0x00000FFF)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_target_for_maximum_clk_counter(data) (0x0FFF0000&((data)<<16))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_target_for_minimum_clk_counter(data) (0x00000FFF&(data))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_get_target_for_maximum_clk_counter(data) ((0x0FFF0000&(data))>>16)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_01_get_target_for_minimum_clk_counter(data) (0x00000FFF&(data))

#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02                                      0x18061F10
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_reg_addr                             "0xB8061F10"
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_reg                                  0xB8061F10
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_inst_addr                            "0x0004"
#define  set_HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_reg(data)                        (*((volatile unsigned int*)HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_reg)=data)
#define  get_HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_reg                              (*((volatile unsigned int*)HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_reg))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_clk_counter_err_threshold_shift      (8)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_clk_counter_debounce_shift           (0)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_clk_counter_err_threshold_mask       (0x00000F00)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_clk_counter_debounce_mask            (0x000000FF)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_clk_counter_err_threshold(data)      (0x00000F00&((data)<<8))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_clk_counter_debounce(data)           (0x000000FF&(data))
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_get_clk_counter_err_threshold(data)  ((0x00000F00&(data))>>8)
#define  HDMI_CLKDET_GDI_TMDSCLK_SETTING_02_get_clk_counter_debounce(data)       (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======HDMI_CLKDET register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18061f00_31_1:31;
        RBus_UInt32  clock_det_en:1;
    };
}hdmi_clkdet_clkdetcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  en_tmds_chg_irq:1;
        RBus_UInt32  tmds_chg_irq:1;
        RBus_UInt32  dummy18061f04_3_2:2;
        RBus_UInt32  clk_in_target_irq_en:1;
        RBus_UInt32  clk_in_target:1;
    };
}hdmi_clkdet_clkdetsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_cnt_start:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  dclk_cnt_end:12;
    };
}hdmi_clkdet_gdi_tmdsclk_setting_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  target_for_maximum_clk_counter:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  target_for_minimum_clk_counter:12;
    };
}hdmi_clkdet_gdi_tmdsclk_setting_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  clk_counter_err_threshold:4;
        RBus_UInt32  clk_counter_debounce:8;
    };
}hdmi_clkdet_gdi_tmdsclk_setting_02_RBUS;

#else //apply LITTLE_ENDIAN

//======HDMI_CLKDET register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clock_det_en:1;
        RBus_UInt32  dummy18061f00_31:31;
    };
}hdmi_clkdet_clkdetcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_in_target:1;
        RBus_UInt32  clk_in_target_irq_en:1;
        RBus_UInt32  dummy18061f04_3:2;
        RBus_UInt32  tmds_chg_irq:1;
        RBus_UInt32  en_tmds_chg_irq:1;
        RBus_UInt32  res1:26;
    };
}hdmi_clkdet_clkdetsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_cnt_end:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dclk_cnt_start:12;
        RBus_UInt32  res2:4;
    };
}hdmi_clkdet_gdi_tmdsclk_setting_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  target_for_minimum_clk_counter:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  target_for_maximum_clk_counter:12;
        RBus_UInt32  res2:4;
    };
}hdmi_clkdet_gdi_tmdsclk_setting_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_counter_debounce:8;
        RBus_UInt32  clk_counter_err_threshold:4;
        RBus_UInt32  res1:20;
    };
}hdmi_clkdet_gdi_tmdsclk_setting_02_RBUS;




#endif 


#endif 
