/**
* @file Macarthur5-DesignSpec-MISC
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MISC_REG_H_
#define _RBUS_MISC_REG_H_

#include "rbus_types.h"



//  MISC Register Address
#define  MISC_isr                                                                0x1801B000
#define  MISC_isr_reg_addr                                                       "0xB801B000"
#define  MISC_isr_reg                                                            0xB801B000
#define  MISC_isr_inst_addr                                                      "0x0000"
#define  set_MISC_isr_reg(data)                                                  (*((volatile unsigned int*)MISC_isr_reg)=data)
#define  get_MISC_isr_reg                                                        (*((volatile unsigned int*)MISC_isr_reg))
#define  MISC_isr_i2c4_int_shift                                                 (28)
#define  MISC_isr_i2c1_int_shift                                                 (27)
#define  MISC_isr_i2c2_int_shift                                                 (26)
#define  MISC_isr_i2c3_int_shift                                                 (25)
#define  MISC_isr_sc0_int_shift                                                  (24)
#define  MISC_isr_pcmcia_int_shift                                               (21)
#define  MISC_isr_gpio_int_shift                                                 (19)
#define  MISC_isr_ddc1_int_shift                                                 (15)
#define  MISC_isr_tc7_int_shift                                                  (14)
#define  MISC_isr_tc6_int_shift                                                  (13)
#define  MISC_isr_tc5_int_shift                                                  (12)
#define  MISC_isr_tc4_int_shift                                                  (11)
#define  MISC_isr_tc3_int_shift                                                  (10)
#define  MISC_isr_tc2_int_shift                                                  (9)
#define  MISC_isr_tc1_int_shift                                                  (8)
#define  MISC_isr_tc0_int_shift                                                  (7)
#define  MISC_isr_ur1_int_shift                                                  (6)
#define  MISC_isr_i2c4_int_mask                                                  (0x10000000)
#define  MISC_isr_i2c1_int_mask                                                  (0x08000000)
#define  MISC_isr_i2c2_int_mask                                                  (0x04000000)
#define  MISC_isr_i2c3_int_mask                                                  (0x02000000)
#define  MISC_isr_sc0_int_mask                                                   (0x01000000)
#define  MISC_isr_pcmcia_int_mask                                                (0x00200000)
#define  MISC_isr_gpio_int_mask                                                  (0x00080000)
#define  MISC_isr_ddc1_int_mask                                                  (0x00008000)
#define  MISC_isr_tc7_int_mask                                                   (0x00004000)
#define  MISC_isr_tc6_int_mask                                                   (0x00002000)
#define  MISC_isr_tc5_int_mask                                                   (0x00001000)
#define  MISC_isr_tc4_int_mask                                                   (0x00000800)
#define  MISC_isr_tc3_int_mask                                                   (0x00000400)
#define  MISC_isr_tc2_int_mask                                                   (0x00000200)
#define  MISC_isr_tc1_int_mask                                                   (0x00000100)
#define  MISC_isr_tc0_int_mask                                                   (0x00000080)
#define  MISC_isr_ur1_int_mask                                                   (0x00000040)
#define  MISC_isr_i2c4_int(data)                                                 (0x10000000&((data)<<28))
#define  MISC_isr_i2c1_int(data)                                                 (0x08000000&((data)<<27))
#define  MISC_isr_i2c2_int(data)                                                 (0x04000000&((data)<<26))
#define  MISC_isr_i2c3_int(data)                                                 (0x02000000&((data)<<25))
#define  MISC_isr_sc0_int(data)                                                  (0x01000000&((data)<<24))
#define  MISC_isr_pcmcia_int(data)                                               (0x00200000&((data)<<21))
#define  MISC_isr_gpio_int(data)                                                 (0x00080000&((data)<<19))
#define  MISC_isr_ddc1_int(data)                                                 (0x00008000&((data)<<15))
#define  MISC_isr_tc7_int(data)                                                  (0x00004000&((data)<<14))
#define  MISC_isr_tc6_int(data)                                                  (0x00002000&((data)<<13))
#define  MISC_isr_tc5_int(data)                                                  (0x00001000&((data)<<12))
#define  MISC_isr_tc4_int(data)                                                  (0x00000800&((data)<<11))
#define  MISC_isr_tc3_int(data)                                                  (0x00000400&((data)<<10))
#define  MISC_isr_tc2_int(data)                                                  (0x00000200&((data)<<9))
#define  MISC_isr_tc1_int(data)                                                  (0x00000100&((data)<<8))
#define  MISC_isr_tc0_int(data)                                                  (0x00000080&((data)<<7))
#define  MISC_isr_ur1_int(data)                                                  (0x00000040&((data)<<6))
#define  MISC_isr_get_i2c4_int(data)                                             ((0x10000000&(data))>>28)
#define  MISC_isr_get_i2c1_int(data)                                             ((0x08000000&(data))>>27)
#define  MISC_isr_get_i2c2_int(data)                                             ((0x04000000&(data))>>26)
#define  MISC_isr_get_i2c3_int(data)                                             ((0x02000000&(data))>>25)
#define  MISC_isr_get_sc0_int(data)                                              ((0x01000000&(data))>>24)
#define  MISC_isr_get_pcmcia_int(data)                                           ((0x00200000&(data))>>21)
#define  MISC_isr_get_gpio_int(data)                                             ((0x00080000&(data))>>19)
#define  MISC_isr_get_ddc1_int(data)                                             ((0x00008000&(data))>>15)
#define  MISC_isr_get_tc7_int(data)                                              ((0x00004000&(data))>>14)
#define  MISC_isr_get_tc6_int(data)                                              ((0x00002000&(data))>>13)
#define  MISC_isr_get_tc5_int(data)                                              ((0x00001000&(data))>>12)
#define  MISC_isr_get_tc4_int(data)                                              ((0x00000800&(data))>>11)
#define  MISC_isr_get_tc3_int(data)                                              ((0x00000400&(data))>>10)
#define  MISC_isr_get_tc2_int(data)                                              ((0x00000200&(data))>>9)
#define  MISC_isr_get_tc1_int(data)                                              ((0x00000100&(data))>>8)
#define  MISC_isr_get_tc0_int(data)                                              ((0x00000080&(data))>>7)
#define  MISC_isr_get_ur1_int(data)                                              ((0x00000040&(data))>>6)

#define  MISC_dbg                                                                0x1801B008
#define  MISC_dbg_reg_addr                                                       "0xB801B008"
#define  MISC_dbg_reg                                                            0xB801B008
#define  MISC_dbg_inst_addr                                                      "0x0001"
#define  set_MISC_dbg_reg(data)                                                  (*((volatile unsigned int*)MISC_dbg_reg)=data)
#define  get_MISC_dbg_reg                                                        (*((volatile unsigned int*)MISC_dbg_reg))
#define  MISC_dbg_sel0_shift                                                     (2)
#define  MISC_dbg_enable_shift                                                   (0)
#define  MISC_dbg_sel0_mask                                                      (0x0000003C)
#define  MISC_dbg_enable_mask                                                    (0x00000001)
#define  MISC_dbg_sel0(data)                                                     (0x0000003C&((data)<<2))
#define  MISC_dbg_enable(data)                                                   (0x00000001&(data))
#define  MISC_dbg_get_sel0(data)                                                 ((0x0000003C&(data))>>2)
#define  MISC_dbg_get_enable(data)                                               (0x00000001&(data))

#define  MISC_dummy                                                              0x1801B00C
#define  MISC_dummy_reg_addr                                                     "0xB801B00C"
#define  MISC_dummy_reg                                                          0xB801B00C
#define  MISC_dummy_inst_addr                                                    "0x0002"
#define  set_MISC_dummy_reg(data)                                                (*((volatile unsigned int*)MISC_dummy_reg)=data)
#define  get_MISC_dummy_reg                                                      (*((volatile unsigned int*)MISC_dummy_reg))
#define  MISC_dummy_sc_od_mode_shift                                             (4)
#define  MISC_dummy_uart_od_mode_en_shift                                        (2)
#define  MISC_dummy_sc_od_mode_mask                                              (0x00000010)
#define  MISC_dummy_uart_od_mode_en_mask                                         (0x00000004)
#define  MISC_dummy_sc_od_mode(data)                                             (0x00000010&((data)<<4))
#define  MISC_dummy_uart_od_mode_en(data)                                        (0x00000004&((data)<<2))
#define  MISC_dummy_get_sc_od_mode(data)                                         ((0x00000010&(data))>>4)
#define  MISC_dummy_get_uart_od_mode_en(data)                                    ((0x00000004&(data))>>2)

#define  MISC_isr_switch                                                         0x1801B010
#define  MISC_isr_switch_reg_addr                                                "0xB801B010"
#define  MISC_isr_switch_reg                                                     0xB801B010
#define  MISC_isr_switch_inst_addr                                               "0x0003"
#define  set_MISC_isr_switch_reg(data)                                           (*((volatile unsigned int*)MISC_isr_switch_reg)=data)
#define  get_MISC_isr_switch_reg                                                 (*((volatile unsigned int*)MISC_isr_switch_reg))
#define  MISC_isr_switch_rvd6_shift                                              (29)
#define  MISC_isr_switch_i2c1_int_sel_shift                                      (28)
#define  MISC_isr_switch_i2c2_int_sel_shift                                      (27)
#define  MISC_isr_switch_i2c3_int_sel_shift                                      (26)
#define  MISC_isr_switch_i2c4_int_sel_shift                                      (25)
#define  MISC_isr_switch_sc0_int_sel_shift                                       (24)
#define  MISC_isr_switch_rvd5_shift                                              (22)
#define  MISC_isr_switch_pcmcia_int_sel_shift                                    (21)
#define  MISC_isr_switch_rvd4_shift                                              (20)
#define  MISC_isr_switch_gpio_int_sel_shift                                      (19)
#define  MISC_isr_switch_rvd3_shift                                              (16)
#define  MISC_isr_switch_ddc1_int_sel_shift                                      (15)
#define  MISC_isr_switch_tc7_int_sel_shift                                       (14)
#define  MISC_isr_switch_tc6_int_sel_shift                                       (13)
#define  MISC_isr_switch_tc5_int_sel_shift                                       (12)
#define  MISC_isr_switch_tc3_int_sel_shift                                       (11)
#define  MISC_isr_switch_rvd2_shift                                              (7)
#define  MISC_isr_switch_ur1_int_sel_shift                                       (6)
#define  MISC_isr_switch_rvd1_shift                                              (0)
#define  MISC_isr_switch_rvd6_mask                                               (0xE0000000)
#define  MISC_isr_switch_i2c1_int_sel_mask                                       (0x10000000)
#define  MISC_isr_switch_i2c2_int_sel_mask                                       (0x08000000)
#define  MISC_isr_switch_i2c3_int_sel_mask                                       (0x04000000)
#define  MISC_isr_switch_i2c4_int_sel_mask                                       (0x02000000)
#define  MISC_isr_switch_sc0_int_sel_mask                                        (0x01000000)
#define  MISC_isr_switch_rvd5_mask                                               (0x00400000)
#define  MISC_isr_switch_pcmcia_int_sel_mask                                     (0x00200000)
#define  MISC_isr_switch_rvd4_mask                                               (0x00100000)
#define  MISC_isr_switch_gpio_int_sel_mask                                       (0x00080000)
#define  MISC_isr_switch_rvd3_mask                                               (0x00070000)
#define  MISC_isr_switch_ddc1_int_sel_mask                                       (0x00008000)
#define  MISC_isr_switch_tc7_int_sel_mask                                        (0x00004000)
#define  MISC_isr_switch_tc6_int_sel_mask                                        (0x00002000)
#define  MISC_isr_switch_tc5_int_sel_mask                                        (0x00001000)
#define  MISC_isr_switch_tc3_int_sel_mask                                        (0x00000800)
#define  MISC_isr_switch_rvd2_mask                                               (0x00000780)
#define  MISC_isr_switch_ur1_int_sel_mask                                        (0x00000040)
#define  MISC_isr_switch_rvd1_mask                                               (0x0000001F)
#define  MISC_isr_switch_rvd6(data)                                              (0xE0000000&((data)<<29))
#define  MISC_isr_switch_i2c1_int_sel(data)                                      (0x10000000&((data)<<28))
#define  MISC_isr_switch_i2c2_int_sel(data)                                      (0x08000000&((data)<<27))
#define  MISC_isr_switch_i2c3_int_sel(data)                                      (0x04000000&((data)<<26))
#define  MISC_isr_switch_i2c4_int_sel(data)                                      (0x02000000&((data)<<25))
#define  MISC_isr_switch_sc0_int_sel(data)                                       (0x01000000&((data)<<24))
#define  MISC_isr_switch_rvd5(data)                                              (0x00400000&((data)<<22))
#define  MISC_isr_switch_pcmcia_int_sel(data)                                    (0x00200000&((data)<<21))
#define  MISC_isr_switch_rvd4(data)                                              (0x00100000&((data)<<20))
#define  MISC_isr_switch_gpio_int_sel(data)                                      (0x00080000&((data)<<19))
#define  MISC_isr_switch_rvd3(data)                                              (0x00070000&((data)<<16))
#define  MISC_isr_switch_ddc1_int_sel(data)                                      (0x00008000&((data)<<15))
#define  MISC_isr_switch_tc7_int_sel(data)                                       (0x00004000&((data)<<14))
#define  MISC_isr_switch_tc6_int_sel(data)                                       (0x00002000&((data)<<13))
#define  MISC_isr_switch_tc5_int_sel(data)                                       (0x00001000&((data)<<12))
#define  MISC_isr_switch_tc3_int_sel(data)                                       (0x00000800&((data)<<11))
#define  MISC_isr_switch_rvd2(data)                                              (0x00000780&((data)<<7))
#define  MISC_isr_switch_ur1_int_sel(data)                                       (0x00000040&((data)<<6))
#define  MISC_isr_switch_rvd1(data)                                              (0x0000001F&(data))
#define  MISC_isr_switch_get_rvd6(data)                                          ((0xE0000000&(data))>>29)
#define  MISC_isr_switch_get_i2c1_int_sel(data)                                  ((0x10000000&(data))>>28)
#define  MISC_isr_switch_get_i2c2_int_sel(data)                                  ((0x08000000&(data))>>27)
#define  MISC_isr_switch_get_i2c3_int_sel(data)                                  ((0x04000000&(data))>>26)
#define  MISC_isr_switch_get_i2c4_int_sel(data)                                  ((0x02000000&(data))>>25)
#define  MISC_isr_switch_get_sc0_int_sel(data)                                   ((0x01000000&(data))>>24)
#define  MISC_isr_switch_get_rvd5(data)                                          ((0x00400000&(data))>>22)
#define  MISC_isr_switch_get_pcmcia_int_sel(data)                                ((0x00200000&(data))>>21)
#define  MISC_isr_switch_get_rvd4(data)                                          ((0x00100000&(data))>>20)
#define  MISC_isr_switch_get_gpio_int_sel(data)                                  ((0x00080000&(data))>>19)
#define  MISC_isr_switch_get_rvd3(data)                                          ((0x00070000&(data))>>16)
#define  MISC_isr_switch_get_ddc1_int_sel(data)                                  ((0x00008000&(data))>>15)
#define  MISC_isr_switch_get_tc7_int_sel(data)                                   ((0x00004000&(data))>>14)
#define  MISC_isr_switch_get_tc6_int_sel(data)                                   ((0x00002000&(data))>>13)
#define  MISC_isr_switch_get_tc5_int_sel(data)                                   ((0x00001000&(data))>>12)
#define  MISC_isr_switch_get_tc3_int_sel(data)                                   ((0x00000800&(data))>>11)
#define  MISC_isr_switch_get_rvd2(data)                                          ((0x00000780&(data))>>7)
#define  MISC_isr_switch_get_ur1_int_sel(data)                                   ((0x00000040&(data))>>6)
#define  MISC_isr_switch_get_rvd1(data)                                          (0x0000001F&(data))

#define  MISC_dummy2                                                             0x1801B014
#define  MISC_dummy2_reg_addr                                                    "0xB801B014"
#define  MISC_dummy2_reg                                                         0xB801B014
#define  MISC_dummy2_inst_addr                                                   "0x0004"
#define  set_MISC_dummy2_reg(data)                                               (*((volatile unsigned int*)MISC_dummy2_reg)=data)
#define  get_MISC_dummy2_reg                                                     (*((volatile unsigned int*)MISC_dummy2_reg))
#define  MISC_dummy2_dummy2_shift                                                (0)
#define  MISC_dummy2_dummy2_mask                                                 (0xFFFFFFFF)
#define  MISC_dummy2_dummy2(data)                                                (0xFFFFFFFF&(data))
#define  MISC_dummy2_get_dummy2(data)                                            (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MISC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  i2c4_int:1;
        RBus_UInt32  i2c1_int:1;
        RBus_UInt32  i2c2_int:1;
        RBus_UInt32  i2c3_int:1;
        RBus_UInt32  sc0_int:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pcmcia_int:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  tc7_int:1;
        RBus_UInt32  tc6_int:1;
        RBus_UInt32  tc5_int:1;
        RBus_UInt32  tc4_int:1;
        RBus_UInt32  tc3_int:1;
        RBus_UInt32  tc2_int:1;
        RBus_UInt32  tc1_int:1;
        RBus_UInt32  tc0_int:1;
        RBus_UInt32  ur1_int:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:4;
    };
}misc_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  sel0:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  enable:1;
    };
}misc_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sc_od_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  uart_od_mode_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
    };
}misc_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvd6:3;
        RBus_UInt32  i2c1_int_sel:1;
        RBus_UInt32  i2c2_int_sel:1;
        RBus_UInt32  i2c3_int_sel:1;
        RBus_UInt32  i2c4_int_sel:1;
        RBus_UInt32  sc0_int_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rvd5:1;
        RBus_UInt32  pcmcia_int_sel:1;
        RBus_UInt32  rvd4:1;
        RBus_UInt32  gpio_int_sel:1;
        RBus_UInt32  rvd3:3;
        RBus_UInt32  ddc1_int_sel:1;
        RBus_UInt32  tc7_int_sel:1;
        RBus_UInt32  tc6_int_sel:1;
        RBus_UInt32  tc5_int_sel:1;
        RBus_UInt32  tc3_int_sel:1;
        RBus_UInt32  rvd2:4;
        RBus_UInt32  ur1_int_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rvd1:5;
    };
}misc_isr_switch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}misc_dummy2_RBUS;

#else //apply LITTLE_ENDIAN

//======MISC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ur1_int:1;
        RBus_UInt32  tc0_int:1;
        RBus_UInt32  tc1_int:1;
        RBus_UInt32  tc2_int:1;
        RBus_UInt32  tc3_int:1;
        RBus_UInt32  tc4_int:1;
        RBus_UInt32  tc5_int:1;
        RBus_UInt32  tc6_int:1;
        RBus_UInt32  tc7_int:1;
        RBus_UInt32  ddc1_int:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  gpio_int:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pcmcia_int:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  sc0_int:1;
        RBus_UInt32  i2c3_int:1;
        RBus_UInt32  i2c2_int:1;
        RBus_UInt32  i2c1_int:1;
        RBus_UInt32  i2c4_int:1;
        RBus_UInt32  res8:3;
    };
}misc_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sel0:4;
        RBus_UInt32  res2:26;
    };
}misc_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  uart_od_mode_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  sc_od_mode:1;
        RBus_UInt32  res4:27;
    };
}misc_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rvd1:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  ur1_int_sel:1;
        RBus_UInt32  rvd2:4;
        RBus_UInt32  tc3_int_sel:1;
        RBus_UInt32  tc5_int_sel:1;
        RBus_UInt32  tc6_int_sel:1;
        RBus_UInt32  tc7_int_sel:1;
        RBus_UInt32  ddc1_int_sel:1;
        RBus_UInt32  rvd3:3;
        RBus_UInt32  gpio_int_sel:1;
        RBus_UInt32  rvd4:1;
        RBus_UInt32  pcmcia_int_sel:1;
        RBus_UInt32  rvd5:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  sc0_int_sel:1;
        RBus_UInt32  i2c4_int_sel:1;
        RBus_UInt32  i2c3_int_sel:1;
        RBus_UInt32  i2c2_int_sel:1;
        RBus_UInt32  i2c1_int_sel:1;
        RBus_UInt32  rvd6:3;
    };
}misc_isr_switch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy2:32;
    };
}misc_dummy2_RBUS;




#endif 


#endif 
