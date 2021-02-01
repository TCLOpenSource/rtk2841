/**
* @file rbusPinMux_MainReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-8-4
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PINMUX_MAIN_REG_H_
#define _RBUS_PINMUX_MAIN_REG_H_

#include "rbus_types.h"



//  PINMUX_MAIN Register Address
#define  PINMUX_MAIN_GPIO_CFG_0                                                  0x18000800
#define  PINMUX_MAIN_GPIO_CFG_0_reg_addr                                         "0xB8000800"
#define  PINMUX_MAIN_GPIO_CFG_0_reg                                              0xB8000800
#define  PINMUX_MAIN_GPIO_CFG_0_inst_addr                                        "0x0000"
#define  set_PINMUX_MAIN_GPIO_CFG_0_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_0_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_0_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_0_reg))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_ps_shift                                  (28)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_pu_shift                                  (27)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_pd_shift                                  (26)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_ds_shift                                  (25)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_sr_shift                                  (24)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_ps_shift                                  (20)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_pu_shift                                  (19)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_pd_shift                                  (18)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_ds_shift                                  (17)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_sr_shift                                  (16)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_ps_shift                                  (12)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_pu_shift                                  (11)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_pd_shift                                  (10)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_ds_shift                                  (9)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_sr_shift                                  (8)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_ps_shift                                  (4)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_pu_shift                                  (3)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_pd_shift                                  (2)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_ds_shift                                  (1)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_sr_shift                                  (0)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_ps_mask                                   (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_pu_mask                                   (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_pd_mask                                   (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_ds_mask                                   (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_sr_mask                                   (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_ps_mask                                   (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_pu_mask                                   (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_pd_mask                                   (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_ds_mask                                   (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_sr_mask                                   (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_ps_mask                                   (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_pu_mask                                   (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_pd_mask                                   (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_ds_mask                                   (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_sr_mask                                   (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_ps_mask                                   (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_pu_mask                                   (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_pd_mask                                   (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_ds_mask                                   (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_sr_mask                                   (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_ps(data)                                  (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_pu(data)                                  (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_pd(data)                                  (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_ds(data)                                  (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_0_sr(data)                                  (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_ps(data)                                  (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_pu(data)                                  (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_pd(data)                                  (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_ds(data)                                  (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_1_sr(data)                                  (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_ps(data)                                  (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_pu(data)                                  (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_pd(data)                                  (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_ds(data)                                  (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_2_sr(data)                                  (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_ps(data)                                  (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_pu(data)                                  (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_pd(data)                                  (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_ds(data)                                  (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_0_gpio_3_sr(data)                                  (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_0_ps(data)                              ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_0_pu(data)                              ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_0_pd(data)                              ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_0_ds(data)                              ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_0_sr(data)                              ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_1_ps(data)                              ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_1_pu(data)                              ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_1_pd(data)                              ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_1_ds(data)                              ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_1_sr(data)                              ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_2_ps(data)                              ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_2_pu(data)                              ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_2_pd(data)                              ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_2_ds(data)                              ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_2_sr(data)                              ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_3_ps(data)                              ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_3_pu(data)                              ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_3_pd(data)                              ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_3_ds(data)                              ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_0_get_gpio_3_sr(data)                              (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_1                                                  0x18000804
#define  PINMUX_MAIN_GPIO_CFG_1_reg_addr                                         "0xB8000804"
#define  PINMUX_MAIN_GPIO_CFG_1_reg                                              0xB8000804
#define  PINMUX_MAIN_GPIO_CFG_1_inst_addr                                        "0x0001"
#define  set_PINMUX_MAIN_GPIO_CFG_1_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_1_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_1_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_1_reg))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_ps_shift                                  (28)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_pu_shift                                  (27)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_pd_shift                                  (26)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_ds_shift                                  (25)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_sr_shift                                  (24)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_ps_shift                                  (20)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_pu_shift                                  (19)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_pd_shift                                  (18)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_ds_shift                                  (17)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_sr_shift                                  (16)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_ps_shift                                  (12)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_pu_shift                                  (11)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_pd_shift                                  (10)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_ds_shift                                  (9)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_sr_shift                                  (8)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_ps_shift                                  (4)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_pu_shift                                  (3)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_pd_shift                                  (2)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_ds_shift                                  (1)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_sr_shift                                  (0)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_ps_mask                                   (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_pu_mask                                   (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_pd_mask                                   (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_ds_mask                                   (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_sr_mask                                   (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_ps_mask                                   (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_pu_mask                                   (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_pd_mask                                   (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_ds_mask                                   (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_sr_mask                                   (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_ps_mask                                   (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_pu_mask                                   (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_pd_mask                                   (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_ds_mask                                   (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_sr_mask                                   (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_ps_mask                                   (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_pu_mask                                   (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_pd_mask                                   (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_ds_mask                                   (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_sr_mask                                   (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_ps(data)                                  (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_pu(data)                                  (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_pd(data)                                  (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_ds(data)                                  (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_4_sr(data)                                  (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_ps(data)                                  (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_pu(data)                                  (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_pd(data)                                  (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_ds(data)                                  (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_5_sr(data)                                  (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_ps(data)                                  (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_pu(data)                                  (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_pd(data)                                  (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_ds(data)                                  (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_6_sr(data)                                  (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_ps(data)                                  (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_pu(data)                                  (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_pd(data)                                  (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_ds(data)                                  (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_1_gpio_7_sr(data)                                  (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_4_ps(data)                              ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_4_pu(data)                              ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_4_pd(data)                              ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_4_ds(data)                              ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_4_sr(data)                              ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_5_ps(data)                              ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_5_pu(data)                              ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_5_pd(data)                              ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_5_ds(data)                              ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_5_sr(data)                              ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_6_ps(data)                              ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_6_pu(data)                              ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_6_pd(data)                              ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_6_ds(data)                              ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_6_sr(data)                              ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_7_ps(data)                              ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_7_pu(data)                              ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_7_pd(data)                              ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_7_ds(data)                              ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_1_get_gpio_7_sr(data)                              (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_2                                                  0x18000808
#define  PINMUX_MAIN_GPIO_CFG_2_reg_addr                                         "0xB8000808"
#define  PINMUX_MAIN_GPIO_CFG_2_reg                                              0xB8000808
#define  PINMUX_MAIN_GPIO_CFG_2_inst_addr                                        "0x0002"
#define  set_PINMUX_MAIN_GPIO_CFG_2_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_2_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_2_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_2_reg))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_ps_shift                                  (28)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_pu_shift                                  (27)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_pd_shift                                  (26)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_ds_shift                                  (25)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_sr_shift                                  (24)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_ps_shift                                  (20)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_pu_shift                                  (19)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_pd_shift                                  (18)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_ds_shift                                  (17)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_sr_shift                                  (16)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_ps_mask                                   (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_pu_mask                                   (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_pd_mask                                   (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_ds_mask                                   (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_sr_mask                                   (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_ps_mask                                   (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_pu_mask                                   (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_pd_mask                                   (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_ds_mask                                   (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_sr_mask                                   (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_ps(data)                                  (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_pu(data)                                  (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_pd(data)                                  (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_ds(data)                                  (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_8_sr(data)                                  (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_ps(data)                                  (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_pu(data)                                  (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_pd(data)                                  (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_ds(data)                                  (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_9_sr(data)                                  (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_10_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_2_gpio_11_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_8_ps(data)                              ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_8_pu(data)                              ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_8_pd(data)                              ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_8_ds(data)                              ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_8_sr(data)                              ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_9_ps(data)                              ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_9_pu(data)                              ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_9_pd(data)                              ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_9_ds(data)                              ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_9_sr(data)                              ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_10_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_10_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_10_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_10_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_10_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_11_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_11_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_11_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_11_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_2_get_gpio_11_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_3                                                  0x1800080C
#define  PINMUX_MAIN_GPIO_CFG_3_reg_addr                                         "0xB800080C"
#define  PINMUX_MAIN_GPIO_CFG_3_reg                                              0xB800080C
#define  PINMUX_MAIN_GPIO_CFG_3_inst_addr                                        "0x0003"
#define  set_PINMUX_MAIN_GPIO_CFG_3_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_3_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_3_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_3_reg))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_12_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_13_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_14_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_3_gpio_15_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_12_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_12_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_12_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_12_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_12_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_13_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_13_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_13_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_13_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_13_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_14_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_14_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_14_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_14_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_14_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_15_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_15_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_15_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_15_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_3_get_gpio_15_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_4                                                  0x18000810
#define  PINMUX_MAIN_GPIO_CFG_4_reg_addr                                         "0xB8000810"
#define  PINMUX_MAIN_GPIO_CFG_4_reg                                              0xB8000810
#define  PINMUX_MAIN_GPIO_CFG_4_inst_addr                                        "0x0004"
#define  set_PINMUX_MAIN_GPIO_CFG_4_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_4_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_4_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_4_reg))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_16_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_17_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_18_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_4_gpio_19_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_16_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_16_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_16_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_16_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_16_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_17_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_17_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_17_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_17_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_17_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_18_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_18_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_18_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_18_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_18_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_19_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_19_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_19_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_19_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_4_get_gpio_19_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_5                                                  0x18000814
#define  PINMUX_MAIN_GPIO_CFG_5_reg_addr                                         "0xB8000814"
#define  PINMUX_MAIN_GPIO_CFG_5_reg                                              0xB8000814
#define  PINMUX_MAIN_GPIO_CFG_5_inst_addr                                        "0x0005"
#define  set_PINMUX_MAIN_GPIO_CFG_5_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_5_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_5_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_5_reg))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_20_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_21_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_22_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_5_gpio_23_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_20_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_20_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_20_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_20_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_20_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_21_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_21_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_21_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_21_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_21_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_22_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_22_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_22_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_22_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_22_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_23_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_23_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_23_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_23_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_5_get_gpio_23_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_6                                                  0x18000818
#define  PINMUX_MAIN_GPIO_CFG_6_reg_addr                                         "0xB8000818"
#define  PINMUX_MAIN_GPIO_CFG_6_reg                                              0xB8000818
#define  PINMUX_MAIN_GPIO_CFG_6_inst_addr                                        "0x0006"
#define  set_PINMUX_MAIN_GPIO_CFG_6_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_6_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_6_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_6_reg))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_24_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_25_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_26_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_6_gpio_27_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_24_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_24_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_24_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_24_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_24_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_25_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_25_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_25_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_25_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_25_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_26_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_26_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_26_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_26_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_26_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_27_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_27_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_27_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_27_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_6_get_gpio_27_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_7                                                  0x1800081C
#define  PINMUX_MAIN_GPIO_CFG_7_reg_addr                                         "0xB800081C"
#define  PINMUX_MAIN_GPIO_CFG_7_reg                                              0xB800081C
#define  PINMUX_MAIN_GPIO_CFG_7_inst_addr                                        "0x0007"
#define  set_PINMUX_MAIN_GPIO_CFG_7_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_7_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_7_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_7_reg))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_28_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_29_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_30_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_7_gpio_31_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_28_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_28_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_28_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_28_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_28_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_29_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_29_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_29_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_29_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_29_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_30_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_30_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_30_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_30_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_30_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_31_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_31_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_31_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_31_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_7_get_gpio_31_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_8                                                  0x18000820
#define  PINMUX_MAIN_GPIO_CFG_8_reg_addr                                         "0xB8000820"
#define  PINMUX_MAIN_GPIO_CFG_8_reg                                              0xB8000820
#define  PINMUX_MAIN_GPIO_CFG_8_inst_addr                                        "0x0008"
#define  set_PINMUX_MAIN_GPIO_CFG_8_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_8_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_8_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_8_reg))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_32_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_33_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_34_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_8_gpio_35_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_32_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_32_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_32_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_32_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_32_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_33_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_33_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_33_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_33_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_33_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_34_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_34_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_34_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_34_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_34_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_35_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_35_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_35_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_35_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_8_get_gpio_35_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_9                                                  0x18000824
#define  PINMUX_MAIN_GPIO_CFG_9_reg_addr                                         "0xB8000824"
#define  PINMUX_MAIN_GPIO_CFG_9_reg                                              0xB8000824
#define  PINMUX_MAIN_GPIO_CFG_9_inst_addr                                        "0x0009"
#define  set_PINMUX_MAIN_GPIO_CFG_9_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_9_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_9_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_9_reg))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_ps_shift                                 (28)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_pu_shift                                 (27)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_pd_shift                                 (26)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_ds_shift                                 (25)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_sr_shift                                 (24)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_ps_shift                                 (20)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_pu_shift                                 (19)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_pd_shift                                 (18)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_ds_shift                                 (17)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_sr_shift                                 (16)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_ps_shift                                 (12)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_pu_shift                                 (11)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_pd_shift                                 (10)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_ds_shift                                 (9)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_sr_shift                                 (8)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_ps_shift                                 (4)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_pu_shift                                 (3)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_pd_shift                                 (2)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_ds_shift                                 (1)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_sr_shift                                 (0)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_pu_mask                                  (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_pd_mask                                  (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_ds_mask                                  (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_sr_mask                                  (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_pu_mask                                  (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_pd_mask                                  (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_ds_mask                                  (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_sr_mask                                  (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_pu_mask                                  (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_pd_mask                                  (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_ds_mask                                  (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_sr_mask                                  (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_pu_mask                                  (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_pd_mask                                  (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_ds_mask                                  (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_sr_mask                                  (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_pu(data)                                 (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_pd(data)                                 (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_ds(data)                                 (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_36_sr(data)                                 (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_pu(data)                                 (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_pd(data)                                 (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_ds(data)                                 (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_37_sr(data)                                 (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_pu(data)                                 (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_pd(data)                                 (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_ds(data)                                 (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_38_sr(data)                                 (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_pu(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_pd(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_ds(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_9_gpio_39_sr(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_36_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_36_pu(data)                             ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_36_pd(data)                             ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_36_ds(data)                             ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_36_sr(data)                             ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_37_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_37_pu(data)                             ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_37_pd(data)                             ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_37_ds(data)                             ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_37_sr(data)                             ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_38_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_38_pu(data)                             ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_38_pd(data)                             ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_38_ds(data)                             ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_38_sr(data)                             ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_39_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_39_pu(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_39_pd(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_39_ds(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_9_get_gpio_39_sr(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_10                                                 0x18000828
#define  PINMUX_MAIN_GPIO_CFG_10_reg_addr                                        "0xB8000828"
#define  PINMUX_MAIN_GPIO_CFG_10_reg                                             0xB8000828
#define  PINMUX_MAIN_GPIO_CFG_10_inst_addr                                       "0x000A"
#define  set_PINMUX_MAIN_GPIO_CFG_10_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_10_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_10_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_10_reg))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_40_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_41_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_42_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_10_gpio_43_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_40_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_40_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_40_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_40_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_40_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_41_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_41_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_41_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_41_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_41_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_42_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_42_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_42_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_42_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_42_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_43_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_43_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_43_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_43_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_10_get_gpio_43_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_11                                                 0x1800082C
#define  PINMUX_MAIN_GPIO_CFG_11_reg_addr                                        "0xB800082C"
#define  PINMUX_MAIN_GPIO_CFG_11_reg                                             0xB800082C
#define  PINMUX_MAIN_GPIO_CFG_11_inst_addr                                       "0x000B"
#define  set_PINMUX_MAIN_GPIO_CFG_11_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_11_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_11_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_11_reg))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_44_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_45_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_46_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_11_gpio_47_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_44_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_44_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_44_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_44_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_44_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_45_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_45_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_45_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_45_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_45_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_46_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_46_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_46_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_46_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_46_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_47_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_47_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_47_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_47_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_11_get_gpio_47_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_12                                                 0x18000830
#define  PINMUX_MAIN_GPIO_CFG_12_reg_addr                                        "0xB8000830"
#define  PINMUX_MAIN_GPIO_CFG_12_reg                                             0xB8000830
#define  PINMUX_MAIN_GPIO_CFG_12_inst_addr                                       "0x000C"
#define  set_PINMUX_MAIN_GPIO_CFG_12_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_12_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_12_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_12_reg))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_48_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_49_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_50_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_12_gpio_51_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_48_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_48_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_48_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_48_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_48_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_49_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_49_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_49_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_49_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_49_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_50_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_50_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_50_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_50_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_50_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_51_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_51_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_51_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_51_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_12_get_gpio_51_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_13                                                 0x18000834
#define  PINMUX_MAIN_GPIO_CFG_13_reg_addr                                        "0xB8000834"
#define  PINMUX_MAIN_GPIO_CFG_13_reg                                             0xB8000834
#define  PINMUX_MAIN_GPIO_CFG_13_inst_addr                                       "0x000D"
#define  set_PINMUX_MAIN_GPIO_CFG_13_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_13_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_13_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_13_reg))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_52_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_53_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_54_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_13_gpio_55_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_52_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_52_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_52_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_52_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_52_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_53_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_53_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_53_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_53_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_53_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_54_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_54_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_54_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_54_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_54_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_55_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_55_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_55_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_55_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_13_get_gpio_55_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_14                                                 0x18000838
#define  PINMUX_MAIN_GPIO_CFG_14_reg_addr                                        "0xB8000838"
#define  PINMUX_MAIN_GPIO_CFG_14_reg                                             0xB8000838
#define  PINMUX_MAIN_GPIO_CFG_14_inst_addr                                       "0x000E"
#define  set_PINMUX_MAIN_GPIO_CFG_14_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_14_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_14_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_14_reg))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_56_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_57_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_58_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_14_gpio_59_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_56_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_56_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_56_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_56_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_56_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_57_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_57_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_57_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_57_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_57_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_58_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_58_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_58_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_58_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_58_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_59_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_59_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_59_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_59_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_14_get_gpio_59_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_15                                                 0x1800083C
#define  PINMUX_MAIN_GPIO_CFG_15_reg_addr                                        "0xB800083C"
#define  PINMUX_MAIN_GPIO_CFG_15_reg                                             0xB800083C
#define  PINMUX_MAIN_GPIO_CFG_15_inst_addr                                       "0x000F"
#define  set_PINMUX_MAIN_GPIO_CFG_15_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_15_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_15_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_15_reg))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_60_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_61_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_62_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_15_gpio_63_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_60_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_60_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_60_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_60_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_60_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_61_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_61_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_61_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_61_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_61_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_62_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_62_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_62_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_62_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_62_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_63_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_63_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_63_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_63_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_15_get_gpio_63_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_16                                                 0x18000840
#define  PINMUX_MAIN_GPIO_CFG_16_reg_addr                                        "0xB8000840"
#define  PINMUX_MAIN_GPIO_CFG_16_reg                                             0xB8000840
#define  PINMUX_MAIN_GPIO_CFG_16_inst_addr                                       "0x0010"
#define  set_PINMUX_MAIN_GPIO_CFG_16_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_16_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_16_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_16_reg))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_64_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_65_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_66_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_16_gpio_67_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_64_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_64_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_64_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_64_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_64_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_65_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_65_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_65_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_65_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_65_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_66_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_66_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_66_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_66_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_66_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_67_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_67_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_67_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_67_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_16_get_gpio_67_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_17                                                 0x18000844
#define  PINMUX_MAIN_GPIO_CFG_17_reg_addr                                        "0xB8000844"
#define  PINMUX_MAIN_GPIO_CFG_17_reg                                             0xB8000844
#define  PINMUX_MAIN_GPIO_CFG_17_inst_addr                                       "0x0011"
#define  set_PINMUX_MAIN_GPIO_CFG_17_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_17_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_17_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_17_reg))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_68_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_69_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_70_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_17_gpio_71_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_68_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_68_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_68_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_68_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_68_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_69_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_69_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_69_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_69_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_69_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_70_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_70_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_70_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_70_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_70_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_71_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_71_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_71_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_71_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_17_get_gpio_71_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_18                                                 0x18000848
#define  PINMUX_MAIN_GPIO_CFG_18_reg_addr                                        "0xB8000848"
#define  PINMUX_MAIN_GPIO_CFG_18_reg                                             0xB8000848
#define  PINMUX_MAIN_GPIO_CFG_18_inst_addr                                       "0x0012"
#define  set_PINMUX_MAIN_GPIO_CFG_18_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_18_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_18_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_18_reg))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_72_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_73_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_74_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_18_gpio_75_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_72_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_72_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_72_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_72_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_72_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_73_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_73_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_73_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_73_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_73_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_74_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_74_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_74_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_74_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_74_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_75_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_75_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_75_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_75_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_18_get_gpio_75_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_19                                                 0x1800084C
#define  PINMUX_MAIN_GPIO_CFG_19_reg_addr                                        "0xB800084C"
#define  PINMUX_MAIN_GPIO_CFG_19_reg                                             0xB800084C
#define  PINMUX_MAIN_GPIO_CFG_19_inst_addr                                       "0x0013"
#define  set_PINMUX_MAIN_GPIO_CFG_19_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_19_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_19_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_19_reg))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_76_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_77_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_78_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_19_gpio_79_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_76_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_76_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_76_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_76_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_76_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_77_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_77_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_77_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_77_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_77_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_78_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_78_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_78_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_78_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_78_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_79_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_79_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_79_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_79_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_19_get_gpio_79_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_20                                                 0x18000850
#define  PINMUX_MAIN_GPIO_CFG_20_reg_addr                                        "0xB8000850"
#define  PINMUX_MAIN_GPIO_CFG_20_reg                                             0xB8000850
#define  PINMUX_MAIN_GPIO_CFG_20_inst_addr                                       "0x0014"
#define  set_PINMUX_MAIN_GPIO_CFG_20_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_20_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_20_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_20_reg))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_80_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_81_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_82_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_20_gpio_83_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_80_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_80_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_80_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_80_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_80_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_81_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_81_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_81_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_81_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_81_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_82_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_82_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_82_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_82_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_82_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_83_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_83_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_83_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_83_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_20_get_gpio_83_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_21                                                 0x18000854
#define  PINMUX_MAIN_GPIO_CFG_21_reg_addr                                        "0xB8000854"
#define  PINMUX_MAIN_GPIO_CFG_21_reg                                             0xB8000854
#define  PINMUX_MAIN_GPIO_CFG_21_inst_addr                                       "0x0015"
#define  set_PINMUX_MAIN_GPIO_CFG_21_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_21_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_21_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_21_reg))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_84_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_85_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_86_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_21_gpio_87_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_84_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_84_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_84_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_84_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_84_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_85_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_85_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_85_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_85_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_85_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_86_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_86_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_86_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_86_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_86_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_87_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_87_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_87_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_87_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_21_get_gpio_87_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_22                                                 0x18000858
#define  PINMUX_MAIN_GPIO_CFG_22_reg_addr                                        "0xB8000858"
#define  PINMUX_MAIN_GPIO_CFG_22_reg                                             0xB8000858
#define  PINMUX_MAIN_GPIO_CFG_22_inst_addr                                       "0x0016"
#define  set_PINMUX_MAIN_GPIO_CFG_22_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_22_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_22_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_22_reg))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_ps_shift                                (12)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_pu_shift                                (11)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_pd_shift                                (10)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_ds_shift                                (9)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_sr_shift                                (8)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_ps_shift                                (4)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_pu_shift                                (3)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_pd_shift                                (2)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_ds_shift                                (1)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_sr_shift                                (0)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_ps_mask                                 (0x0000F000)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_pu_mask                                 (0x00000800)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_pd_mask                                 (0x00000400)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_ds_mask                                 (0x00000200)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_sr_mask                                 (0x00000100)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_ps_mask                                 (0x000000F0)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_pu_mask                                 (0x00000008)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_pd_mask                                 (0x00000004)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_ds_mask                                 (0x00000002)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_sr_mask                                 (0x00000001)
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_88_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_89_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_ps(data)                                (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_pu(data)                                (0x00000800&((data)<<11))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_pd(data)                                (0x00000400&((data)<<10))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_ds(data)                                (0x00000200&((data)<<9))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_90_sr(data)                                (0x00000100&((data)<<8))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_ps(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_pu(data)                                (0x00000008&((data)<<3))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_pd(data)                                (0x00000004&((data)<<2))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_ds(data)                                (0x00000002&((data)<<1))
#define  PINMUX_MAIN_GPIO_CFG_22_gpio_91_sr(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_88_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_88_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_88_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_88_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_88_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_89_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_89_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_89_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_89_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_89_sr(data)                            ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_90_ps(data)                            ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_90_pu(data)                            ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_90_pd(data)                            ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_90_ds(data)                            ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_90_sr(data)                            ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_91_ps(data)                            ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_91_pu(data)                            ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_91_pd(data)                            ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_91_ds(data)                            ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_GPIO_CFG_22_get_gpio_91_sr(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_GPIO_CFG_23                                                 0x1800085C
#define  PINMUX_MAIN_GPIO_CFG_23_reg_addr                                        "0xB800085C"
#define  PINMUX_MAIN_GPIO_CFG_23_reg                                             0xB800085C
#define  PINMUX_MAIN_GPIO_CFG_23_inst_addr                                       "0x0017"
#define  set_PINMUX_MAIN_GPIO_CFG_23_reg(data)                                   (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_23_reg)=data)
#define  get_PINMUX_MAIN_GPIO_CFG_23_reg                                         (*((volatile unsigned int*)PINMUX_MAIN_GPIO_CFG_23_reg))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_ps_shift                                (28)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_pu_shift                                (27)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_pd_shift                                (26)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_ds_shift                                (25)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_sr_shift                                (24)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_ps_shift                                (20)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_pu_shift                                (19)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_pd_shift                                (18)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_ds_shift                                (17)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_sr_shift                                (16)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_ps_mask                                 (0xF0000000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_pu_mask                                 (0x08000000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_pd_mask                                 (0x04000000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_ds_mask                                 (0x02000000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_sr_mask                                 (0x01000000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_ps_mask                                 (0x00F00000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_pu_mask                                 (0x00080000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_pd_mask                                 (0x00040000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_ds_mask                                 (0x00020000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_sr_mask                                 (0x00010000)
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_ps(data)                                (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_pu(data)                                (0x08000000&((data)<<27))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_pd(data)                                (0x04000000&((data)<<26))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_ds(data)                                (0x02000000&((data)<<25))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_92_sr(data)                                (0x01000000&((data)<<24))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_ps(data)                                (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_pu(data)                                (0x00080000&((data)<<19))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_pd(data)                                (0x00040000&((data)<<18))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_ds(data)                                (0x00020000&((data)<<17))
#define  PINMUX_MAIN_GPIO_CFG_23_gpio_93_sr(data)                                (0x00010000&((data)<<16))
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_92_ps(data)                            ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_92_pu(data)                            ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_92_pd(data)                            ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_92_ds(data)                            ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_92_sr(data)                            ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_93_ps(data)                            ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_93_pu(data)                            ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_93_pd(data)                            ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_93_ds(data)                            ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_GPIO_CFG_23_get_gpio_93_sr(data)                            ((0x00010000&(data))>>16)

#define  PINMUX_MAIN_APLL_0                                                      0x1800086C
#define  PINMUX_MAIN_APLL_0_reg_addr                                             "0xB800086C"
#define  PINMUX_MAIN_APLL_0_reg                                                  0xB800086C
#define  PINMUX_MAIN_APLL_0_inst_addr                                            "0x0018"
#define  set_PINMUX_MAIN_APLL_0_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_APLL_0_reg)=data)
#define  get_PINMUX_MAIN_APLL_0_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_APLL_0_reg))
#define  PINMUX_MAIN_APLL_0_vsync_ps_shift                                       (28)
#define  PINMUX_MAIN_APLL_0_hsync_ps_shift                                       (24)
#define  PINMUX_MAIN_APLL_0_vsync_gpi_en_shift                                   (1)
#define  PINMUX_MAIN_APLL_0_hsync_gpi_en_shift                                   (0)
#define  PINMUX_MAIN_APLL_0_vsync_ps_mask                                        (0xF0000000)
#define  PINMUX_MAIN_APLL_0_hsync_ps_mask                                        (0x0F000000)
#define  PINMUX_MAIN_APLL_0_vsync_gpi_en_mask                                    (0x00000002)
#define  PINMUX_MAIN_APLL_0_hsync_gpi_en_mask                                    (0x00000001)
#define  PINMUX_MAIN_APLL_0_vsync_ps(data)                                       (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_APLL_0_hsync_ps(data)                                       (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_APLL_0_vsync_gpi_en(data)                                   (0x00000002&((data)<<1))
#define  PINMUX_MAIN_APLL_0_hsync_gpi_en(data)                                   (0x00000001&(data))
#define  PINMUX_MAIN_APLL_0_get_vsync_ps(data)                                   ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_APLL_0_get_hsync_ps(data)                                   ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_APLL_0_get_vsync_gpi_en(data)                               ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_APLL_0_get_hsync_gpi_en(data)                               (0x00000001&(data))

#define  PINMUX_MAIN_BB_Audio_0                                                  0x18000870
#define  PINMUX_MAIN_BB_Audio_0_reg_addr                                         "0xB8000870"
#define  PINMUX_MAIN_BB_Audio_0_reg                                              0xB8000870
#define  PINMUX_MAIN_BB_Audio_0_inst_addr                                        "0x0019"
#define  set_PINMUX_MAIN_BB_Audio_0_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_BB_Audio_0_reg)=data)
#define  get_PINMUX_MAIN_BB_Audio_0_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_BB_Audio_0_reg))
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2l_ps_shift                                 (28)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2r_ps_shift                                 (24)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2l_gpi_en_shift                             (1)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2r_gpi_en_shift                             (0)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2l_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2r_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2l_gpi_en_mask                              (0x00000002)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2r_gpi_en_mask                              (0x00000001)
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2l_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2r_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2l_gpi_en(data)                             (0x00000002&((data)<<1))
#define  PINMUX_MAIN_BB_Audio_0_bb_ai2r_gpi_en(data)                             (0x00000001&(data))
#define  PINMUX_MAIN_BB_Audio_0_get_bb_ai2l_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_BB_Audio_0_get_bb_ai2r_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_BB_Audio_0_get_bb_ai2l_gpi_en(data)                         ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_BB_Audio_0_get_bb_ai2r_gpi_en(data)                         (0x00000001&(data))

#define  PINMUX_MAIN_BB_Audio_1                                                  0x18000874
#define  PINMUX_MAIN_BB_Audio_1_reg_addr                                         "0xB8000874"
#define  PINMUX_MAIN_BB_Audio_1_reg                                              0xB8000874
#define  PINMUX_MAIN_BB_Audio_1_inst_addr                                        "0x001A"
#define  set_PINMUX_MAIN_BB_Audio_1_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_BB_Audio_1_reg)=data)
#define  get_PINMUX_MAIN_BB_Audio_1_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_BB_Audio_1_reg))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3l_ps_shift                                 (28)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3r_ps_shift                                 (24)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4l_ps_shift                                 (20)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4r_ps_shift                                 (16)
#define  PINMUX_MAIN_BB_Audio_1_bb_aiol_ps_shift                                 (12)
#define  PINMUX_MAIN_BB_Audio_1_bb_aior_ps_shift                                 (8)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3l_gpi_en_shift                             (5)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3r_gpi_en_shift                             (4)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4l_gpi_en_shift                             (3)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4r_gpi_en_shift                             (2)
#define  PINMUX_MAIN_BB_Audio_1_bb_aiol_gpi_en_shift                             (1)
#define  PINMUX_MAIN_BB_Audio_1_bb_aior_gpi_en_shift                             (0)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3l_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3r_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4l_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4r_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_BB_Audio_1_bb_aiol_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_BB_Audio_1_bb_aior_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3l_gpi_en_mask                              (0x00000020)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3r_gpi_en_mask                              (0x00000010)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4l_gpi_en_mask                              (0x00000008)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4r_gpi_en_mask                              (0x00000004)
#define  PINMUX_MAIN_BB_Audio_1_bb_aiol_gpi_en_mask                              (0x00000002)
#define  PINMUX_MAIN_BB_Audio_1_bb_aior_gpi_en_mask                              (0x00000001)
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3l_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3r_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4l_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4r_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_BB_Audio_1_bb_aiol_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_BB_Audio_1_bb_aior_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3l_gpi_en(data)                             (0x00000020&((data)<<5))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai3r_gpi_en(data)                             (0x00000010&((data)<<4))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4l_gpi_en(data)                             (0x00000008&((data)<<3))
#define  PINMUX_MAIN_BB_Audio_1_bb_ai4r_gpi_en(data)                             (0x00000004&((data)<<2))
#define  PINMUX_MAIN_BB_Audio_1_bb_aiol_gpi_en(data)                             (0x00000002&((data)<<1))
#define  PINMUX_MAIN_BB_Audio_1_bb_aior_gpi_en(data)                             (0x00000001&(data))
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai3l_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai3r_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai4l_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai4r_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_aiol_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_aior_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai3l_gpi_en(data)                         ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai3r_gpi_en(data)                         ((0x00000010&(data))>>4)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai4l_gpi_en(data)                         ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_ai4r_gpi_en(data)                         ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_aiol_gpi_en(data)                         ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_BB_Audio_1_get_bb_aior_gpi_en(data)                         (0x00000001&(data))

#define  PINMUX_MAIN_BB_Audio_2                                                  0x18000878
#define  PINMUX_MAIN_BB_Audio_2_reg_addr                                         "0xB8000878"
#define  PINMUX_MAIN_BB_Audio_2_reg                                              0xB8000878
#define  PINMUX_MAIN_BB_Audio_2_inst_addr                                        "0x001B"
#define  set_PINMUX_MAIN_BB_Audio_2_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_BB_Audio_2_reg)=data)
#define  get_PINMUX_MAIN_BB_Audio_2_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_BB_Audio_2_reg))
#define  PINMUX_MAIN_BB_Audio_2_bb_hpol_ps_shift                                 (28)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpor_ps_shift                                 (24)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpol_gpi_en_shift                             (1)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpor_gpi_en_shift                             (0)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpol_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpor_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpol_gpi_en_mask                              (0x00000002)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpor_gpi_en_mask                              (0x00000001)
#define  PINMUX_MAIN_BB_Audio_2_bb_hpol_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_BB_Audio_2_bb_hpor_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_BB_Audio_2_bb_hpol_gpi_en(data)                             (0x00000002&((data)<<1))
#define  PINMUX_MAIN_BB_Audio_2_bb_hpor_gpi_en(data)                             (0x00000001&(data))
#define  PINMUX_MAIN_BB_Audio_2_get_bb_hpol_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_BB_Audio_2_get_bb_hpor_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_BB_Audio_2_get_bb_hpol_gpi_en(data)                         ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_BB_Audio_2_get_bb_hpor_gpi_en(data)                         (0x00000001&(data))

#define  PINMUX_MAIN_LVDS_1_0                                                    0x1800087C
#define  PINMUX_MAIN_LVDS_1_0_reg_addr                                           "0xB800087C"
#define  PINMUX_MAIN_LVDS_1_0_reg                                                0xB800087C
#define  PINMUX_MAIN_LVDS_1_0_inst_addr                                          "0x001C"
#define  set_PINMUX_MAIN_LVDS_1_0_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_0_reg)=data)
#define  get_PINMUX_MAIN_LVDS_1_0_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_0_reg))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_fp_ps_shift                                 (28)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_fn_ps_shift                                 (24)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_ep_ps_shift                                 (20)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_en_ps_shift                                 (16)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_dp_ps_shift                                 (12)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_dn_ps_shift                                 (8)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_cp_ps_shift                                 (4)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_cn_ps_shift                                 (0)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_fp_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_fn_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_ep_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_en_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_dp_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_dn_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_cp_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_cn_ps_mask                                  (0x0000000F)
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_fp_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_fn_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_ep_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_en_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_dp_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_dn_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_cp_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_LVDS_1_0_lvds_a_cn_ps(data)                                 (0x0000000F&(data))
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_fp_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_fn_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_ep_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_en_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_dp_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_dn_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_cp_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_LVDS_1_0_get_lvds_a_cn_ps(data)                             (0x0000000F&(data))

#define  PINMUX_MAIN_LVDS_1_1                                                    0x18000880
#define  PINMUX_MAIN_LVDS_1_1_reg_addr                                           "0xB8000880"
#define  PINMUX_MAIN_LVDS_1_1_reg                                                0xB8000880
#define  PINMUX_MAIN_LVDS_1_1_inst_addr                                          "0x001D"
#define  set_PINMUX_MAIN_LVDS_1_1_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_1_reg)=data)
#define  get_PINMUX_MAIN_LVDS_1_1_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_1_reg))
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_bp_ps_shift                                 (28)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_bn_ps_shift                                 (24)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_ap_ps_shift                                 (20)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_an_ps_shift                                 (16)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_fp_ps_shift                                 (12)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_fn_ps_shift                                 (8)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_ep_ps_shift                                 (4)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_en_ps_shift                                 (0)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_bp_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_bn_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_ap_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_an_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_fp_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_fn_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_ep_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_en_ps_mask                                  (0x0000000F)
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_bp_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_bn_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_ap_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_LVDS_1_1_lvds_a_an_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_fp_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_fn_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_ep_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_LVDS_1_1_lvds_b_en_ps(data)                                 (0x0000000F&(data))
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_a_bp_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_a_bn_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_a_ap_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_a_an_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_b_fp_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_b_fn_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_b_ep_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_LVDS_1_1_get_lvds_b_en_ps(data)                             (0x0000000F&(data))

#define  PINMUX_MAIN_LVDS_1_2                                                    0x18000884
#define  PINMUX_MAIN_LVDS_1_2_reg_addr                                           "0xB8000884"
#define  PINMUX_MAIN_LVDS_1_2_reg                                                0xB8000884
#define  PINMUX_MAIN_LVDS_1_2_inst_addr                                          "0x001E"
#define  set_PINMUX_MAIN_LVDS_1_2_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_2_reg)=data)
#define  get_PINMUX_MAIN_LVDS_1_2_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_2_reg))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_dp_ps_shift                                 (28)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_dn_ps_shift                                 (24)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_cp_ps_shift                                 (20)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_cn_ps_shift                                 (16)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_bp_ps_shift                                 (12)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_bn_ps_shift                                 (8)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_ap_ps_shift                                 (4)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_an_ps_shift                                 (0)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_dp_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_dn_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_cp_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_cn_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_bp_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_bn_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_ap_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_an_ps_mask                                  (0x0000000F)
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_dp_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_dn_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_cp_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_cn_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_bp_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_bn_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_ap_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_LVDS_1_2_lvds_b_an_ps(data)                                 (0x0000000F&(data))
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_dp_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_dn_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_cp_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_cn_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_bp_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_bn_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_ap_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_LVDS_1_2_get_lvds_b_an_ps(data)                             (0x0000000F&(data))

#define  PINMUX_MAIN_LVDS_1_3                                                    0x18000888
#define  PINMUX_MAIN_LVDS_1_3_reg_addr                                           "0xB8000888"
#define  PINMUX_MAIN_LVDS_1_3_reg                                                0xB8000888
#define  PINMUX_MAIN_LVDS_1_3_inst_addr                                          "0x001F"
#define  set_PINMUX_MAIN_LVDS_1_3_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_3_reg)=data)
#define  get_PINMUX_MAIN_LVDS_1_3_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_3_reg))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_fp_ps_shift                                 (28)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_fn_ps_shift                                 (24)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_ep_ps_shift                                 (20)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_en_ps_shift                                 (16)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_dp_ps_shift                                 (12)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_dn_ps_shift                                 (8)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_cp_ps_shift                                 (4)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_cn_ps_shift                                 (0)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_fp_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_fn_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_ep_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_en_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_dp_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_dn_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_cp_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_cn_ps_mask                                  (0x0000000F)
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_fp_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_fn_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_ep_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_en_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_dp_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_dn_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_cp_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_LVDS_1_3_lvds_c_cn_ps(data)                                 (0x0000000F&(data))
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_fp_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_fn_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_ep_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_en_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_dp_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_dn_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_cp_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_LVDS_1_3_get_lvds_c_cn_ps(data)                             (0x0000000F&(data))

#define  PINMUX_MAIN_LVDS_1_4                                                    0x1800088C
#define  PINMUX_MAIN_LVDS_1_4_reg_addr                                           "0xB800088C"
#define  PINMUX_MAIN_LVDS_1_4_reg                                                0xB800088C
#define  PINMUX_MAIN_LVDS_1_4_inst_addr                                          "0x0020"
#define  set_PINMUX_MAIN_LVDS_1_4_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_4_reg)=data)
#define  get_PINMUX_MAIN_LVDS_1_4_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_4_reg))
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_bp_ps_shift                                 (28)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_bn_ps_shift                                 (24)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_ap_ps_shift                                 (20)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_an_ps_shift                                 (16)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_fp_ps_shift                                 (12)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_fn_ps_shift                                 (8)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_ep_ps_shift                                 (4)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_en_ps_shift                                 (0)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_bp_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_bn_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_ap_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_an_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_fp_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_fn_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_ep_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_en_ps_mask                                  (0x0000000F)
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_bp_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_bn_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_ap_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_LVDS_1_4_lvds_c_an_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_fp_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_fn_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_ep_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_LVDS_1_4_lvds_d_en_ps(data)                                 (0x0000000F&(data))
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_c_bp_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_c_bn_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_c_ap_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_c_an_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_d_fp_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_d_fn_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_d_ep_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_LVDS_1_4_get_lvds_d_en_ps(data)                             (0x0000000F&(data))

#define  PINMUX_MAIN_LVDS_1_5                                                    0x18000890
#define  PINMUX_MAIN_LVDS_1_5_reg_addr                                           "0xB8000890"
#define  PINMUX_MAIN_LVDS_1_5_reg                                                0xB8000890
#define  PINMUX_MAIN_LVDS_1_5_inst_addr                                          "0x0021"
#define  set_PINMUX_MAIN_LVDS_1_5_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_5_reg)=data)
#define  get_PINMUX_MAIN_LVDS_1_5_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_LVDS_1_5_reg))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_dp_ps_shift                                 (28)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_dn_ps_shift                                 (24)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_cp_ps_shift                                 (20)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_cn_ps_shift                                 (16)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_bp_ps_shift                                 (12)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_bn_ps_shift                                 (8)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_ap_ps_shift                                 (4)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_an_ps_shift                                 (0)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_dp_ps_mask                                  (0xF0000000)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_dn_ps_mask                                  (0x0F000000)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_cp_ps_mask                                  (0x00F00000)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_cn_ps_mask                                  (0x000F0000)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_bp_ps_mask                                  (0x0000F000)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_bn_ps_mask                                  (0x00000F00)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_ap_ps_mask                                  (0x000000F0)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_an_ps_mask                                  (0x0000000F)
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_dp_ps(data)                                 (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_dn_ps(data)                                 (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_cp_ps(data)                                 (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_cn_ps(data)                                 (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_bp_ps(data)                                 (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_bn_ps(data)                                 (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_ap_ps(data)                                 (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_LVDS_1_5_lvds_d_an_ps(data)                                 (0x0000000F&(data))
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_dp_ps(data)                             ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_dn_ps(data)                             ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_cp_ps(data)                             ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_cn_ps(data)                             ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_bp_ps(data)                             ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_bn_ps(data)                             ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_ap_ps(data)                             ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_LVDS_1_5_get_lvds_d_an_ps(data)                             (0x0000000F&(data))

#define  PINMUX_MAIN_VD_ADC_0                                                    0x18000898
#define  PINMUX_MAIN_VD_ADC_0_reg_addr                                           "0xB8000898"
#define  PINMUX_MAIN_VD_ADC_0_reg                                                0xB8000898
#define  PINMUX_MAIN_VD_ADC_0_inst_addr                                          "0x0022"
#define  set_PINMUX_MAIN_VD_ADC_0_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_VD_ADC_0_reg)=data)
#define  get_PINMUX_MAIN_VD_ADC_0_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_VD_ADC_0_reg))
#define  PINMUX_MAIN_VD_ADC_0_scart_fsw_0_ps_shift                               (28)
#define  PINMUX_MAIN_VD_ADC_0_vin_13p_ps_shift                                   (24)
#define  PINMUX_MAIN_VD_ADC_0_vin_10p_ps_shift                                   (20)
#define  PINMUX_MAIN_VD_ADC_0_vin_a2n_ps_shift                                   (16)
#define  PINMUX_MAIN_VD_ADC_0_vin_a0n_ps_shift                                   (12)
#define  PINMUX_MAIN_VD_ADC_0_vin_12p_ps_shift                                   (8)
#define  PINMUX_MAIN_VD_ADC_0_scart_fsw_0_gpi_en_shift                           (5)
#define  PINMUX_MAIN_VD_ADC_0_vin_13p_gpi_en_shift                               (4)
#define  PINMUX_MAIN_VD_ADC_0_vin_10p_gpi_en_shift                               (3)
#define  PINMUX_MAIN_VD_ADC_0_vin_a2n_gpi_en_shift                               (2)
#define  PINMUX_MAIN_VD_ADC_0_vin_a0n_gpi_en_shift                               (1)
#define  PINMUX_MAIN_VD_ADC_0_vin_12p_gpi_en_shift                               (0)
#define  PINMUX_MAIN_VD_ADC_0_scart_fsw_0_ps_mask                                (0xF0000000)
#define  PINMUX_MAIN_VD_ADC_0_vin_13p_ps_mask                                    (0x0F000000)
#define  PINMUX_MAIN_VD_ADC_0_vin_10p_ps_mask                                    (0x00F00000)
#define  PINMUX_MAIN_VD_ADC_0_vin_a2n_ps_mask                                    (0x000F0000)
#define  PINMUX_MAIN_VD_ADC_0_vin_a0n_ps_mask                                    (0x0000F000)
#define  PINMUX_MAIN_VD_ADC_0_vin_12p_ps_mask                                    (0x00000F00)
#define  PINMUX_MAIN_VD_ADC_0_scart_fsw_0_gpi_en_mask                            (0x00000020)
#define  PINMUX_MAIN_VD_ADC_0_vin_13p_gpi_en_mask                                (0x00000010)
#define  PINMUX_MAIN_VD_ADC_0_vin_10p_gpi_en_mask                                (0x00000008)
#define  PINMUX_MAIN_VD_ADC_0_vin_a2n_gpi_en_mask                                (0x00000004)
#define  PINMUX_MAIN_VD_ADC_0_vin_a0n_gpi_en_mask                                (0x00000002)
#define  PINMUX_MAIN_VD_ADC_0_vin_12p_gpi_en_mask                                (0x00000001)
#define  PINMUX_MAIN_VD_ADC_0_scart_fsw_0_ps(data)                               (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_VD_ADC_0_vin_13p_ps(data)                                   (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_VD_ADC_0_vin_10p_ps(data)                                   (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_VD_ADC_0_vin_a2n_ps(data)                                   (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_VD_ADC_0_vin_a0n_ps(data)                                   (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_VD_ADC_0_vin_12p_ps(data)                                   (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_VD_ADC_0_scart_fsw_0_gpi_en(data)                           (0x00000020&((data)<<5))
#define  PINMUX_MAIN_VD_ADC_0_vin_13p_gpi_en(data)                               (0x00000010&((data)<<4))
#define  PINMUX_MAIN_VD_ADC_0_vin_10p_gpi_en(data)                               (0x00000008&((data)<<3))
#define  PINMUX_MAIN_VD_ADC_0_vin_a2n_gpi_en(data)                               (0x00000004&((data)<<2))
#define  PINMUX_MAIN_VD_ADC_0_vin_a0n_gpi_en(data)                               (0x00000002&((data)<<1))
#define  PINMUX_MAIN_VD_ADC_0_vin_12p_gpi_en(data)                               (0x00000001&(data))
#define  PINMUX_MAIN_VD_ADC_0_get_scart_fsw_0_ps(data)                           ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_13p_ps(data)                               ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_10p_ps(data)                               ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_a2n_ps(data)                               ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_a0n_ps(data)                               ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_12p_ps(data)                               ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_VD_ADC_0_get_scart_fsw_0_gpi_en(data)                       ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_13p_gpi_en(data)                           ((0x00000010&(data))>>4)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_10p_gpi_en(data)                           ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_a2n_gpi_en(data)                           ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_a0n_gpi_en(data)                           ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_VD_ADC_0_get_vin_12p_gpi_en(data)                           (0x00000001&(data))

#define  PINMUX_MAIN_VD_ADC_1                                                    0x1800089C
#define  PINMUX_MAIN_VD_ADC_1_reg_addr                                           "0xB800089C"
#define  PINMUX_MAIN_VD_ADC_1_reg                                                0xB800089C
#define  PINMUX_MAIN_VD_ADC_1_inst_addr                                          "0x0023"
#define  set_PINMUX_MAIN_VD_ADC_1_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_VD_ADC_1_reg)=data)
#define  get_PINMUX_MAIN_VD_ADC_1_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_VD_ADC_1_reg))
#define  PINMUX_MAIN_VD_ADC_1_vin_9p_ps_shift                                    (28)
#define  PINMUX_MAIN_VD_ADC_1_vin_9p_gpi_en_shift                                (0)
#define  PINMUX_MAIN_VD_ADC_1_vin_9p_ps_mask                                     (0xF0000000)
#define  PINMUX_MAIN_VD_ADC_1_vin_9p_gpi_en_mask                                 (0x00000001)
#define  PINMUX_MAIN_VD_ADC_1_vin_9p_ps(data)                                    (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_VD_ADC_1_vin_9p_gpi_en(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_VD_ADC_1_get_vin_9p_ps(data)                                ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_VD_ADC_1_get_vin_9p_gpi_en(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_VD_DAC_0                                                    0x180008A0
#define  PINMUX_MAIN_VD_DAC_0_reg_addr                                           "0xB80008A0"
#define  PINMUX_MAIN_VD_DAC_0_reg                                                0xB80008A0
#define  PINMUX_MAIN_VD_DAC_0_inst_addr                                          "0x0024"
#define  set_PINMUX_MAIN_VD_DAC_0_reg(data)                                      (*((volatile unsigned int*)PINMUX_MAIN_VD_DAC_0_reg)=data)
#define  get_PINMUX_MAIN_VD_DAC_0_reg                                            (*((volatile unsigned int*)PINMUX_MAIN_VD_DAC_0_reg))
#define  PINMUX_MAIN_VD_DAC_0_vdbs_out_ps_shift                                  (28)
#define  PINMUX_MAIN_VD_DAC_0_vdac_out_ps_shift                                  (24)
#define  PINMUX_MAIN_VD_DAC_0_vdbs_out_gpi_en_shift                              (1)
#define  PINMUX_MAIN_VD_DAC_0_vdac_out_gpi_en_shift                              (0)
#define  PINMUX_MAIN_VD_DAC_0_vdbs_out_ps_mask                                   (0xF0000000)
#define  PINMUX_MAIN_VD_DAC_0_vdac_out_ps_mask                                   (0x0F000000)
#define  PINMUX_MAIN_VD_DAC_0_vdbs_out_gpi_en_mask                               (0x00000002)
#define  PINMUX_MAIN_VD_DAC_0_vdac_out_gpi_en_mask                               (0x00000001)
#define  PINMUX_MAIN_VD_DAC_0_vdbs_out_ps(data)                                  (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_VD_DAC_0_vdac_out_ps(data)                                  (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_VD_DAC_0_vdbs_out_gpi_en(data)                              (0x00000002&((data)<<1))
#define  PINMUX_MAIN_VD_DAC_0_vdac_out_gpi_en(data)                              (0x00000001&(data))
#define  PINMUX_MAIN_VD_DAC_0_get_vdbs_out_ps(data)                              ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_VD_DAC_0_get_vdac_out_ps(data)                              ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_VD_DAC_0_get_vdbs_out_gpi_en(data)                          ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_VD_DAC_0_get_vdac_out_gpi_en(data)                          (0x00000001&(data))

#define  PINMUX_MAIN_YPbPr_0                                                     0x180008A4
#define  PINMUX_MAIN_YPbPr_0_reg_addr                                            "0xB80008A4"
#define  PINMUX_MAIN_YPbPr_0_reg                                                 0xB80008A4
#define  PINMUX_MAIN_YPbPr_0_inst_addr                                           "0x0025"
#define  set_PINMUX_MAIN_YPbPr_0_reg(data)                                       (*((volatile unsigned int*)PINMUX_MAIN_YPbPr_0_reg)=data)
#define  get_PINMUX_MAIN_YPbPr_0_reg                                             (*((volatile unsigned int*)PINMUX_MAIN_YPbPr_0_reg))
#define  PINMUX_MAIN_YPbPr_0_vin_0p_ps_shift                                     (28)
#define  PINMUX_MAIN_YPbPr_0_vin_bn_ps_shift                                     (24)
#define  PINMUX_MAIN_YPbPr_0_vin_1p_ps_shift                                     (20)
#define  PINMUX_MAIN_YPbPr_0_vin_2p_ps_shift                                     (16)
#define  PINMUX_MAIN_YPbPr_0_vin_6p_ps_shift                                     (12)
#define  PINMUX_MAIN_YPbPr_0_vin_y1n_ps_shift                                    (8)
#define  PINMUX_MAIN_YPbPr_0_vin_0p_gpi_en_shift                                 (5)
#define  PINMUX_MAIN_YPbPr_0_vin_bn_gpi_en_shift                                 (4)
#define  PINMUX_MAIN_YPbPr_0_vin_1p_gpi_en_shift                                 (3)
#define  PINMUX_MAIN_YPbPr_0_vin_2p_gpi_en_shift                                 (2)
#define  PINMUX_MAIN_YPbPr_0_vin_6p_gpi_en_shift                                 (1)
#define  PINMUX_MAIN_YPbPr_0_vin_y1n_gpi_en_shift                                (0)
#define  PINMUX_MAIN_YPbPr_0_vin_0p_ps_mask                                      (0xF0000000)
#define  PINMUX_MAIN_YPbPr_0_vin_bn_ps_mask                                      (0x0F000000)
#define  PINMUX_MAIN_YPbPr_0_vin_1p_ps_mask                                      (0x00F00000)
#define  PINMUX_MAIN_YPbPr_0_vin_2p_ps_mask                                      (0x000F0000)
#define  PINMUX_MAIN_YPbPr_0_vin_6p_ps_mask                                      (0x0000F000)
#define  PINMUX_MAIN_YPbPr_0_vin_y1n_ps_mask                                     (0x00000F00)
#define  PINMUX_MAIN_YPbPr_0_vin_0p_gpi_en_mask                                  (0x00000020)
#define  PINMUX_MAIN_YPbPr_0_vin_bn_gpi_en_mask                                  (0x00000010)
#define  PINMUX_MAIN_YPbPr_0_vin_1p_gpi_en_mask                                  (0x00000008)
#define  PINMUX_MAIN_YPbPr_0_vin_2p_gpi_en_mask                                  (0x00000004)
#define  PINMUX_MAIN_YPbPr_0_vin_6p_gpi_en_mask                                  (0x00000002)
#define  PINMUX_MAIN_YPbPr_0_vin_y1n_gpi_en_mask                                 (0x00000001)
#define  PINMUX_MAIN_YPbPr_0_vin_0p_ps(data)                                     (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_YPbPr_0_vin_bn_ps(data)                                     (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_YPbPr_0_vin_1p_ps(data)                                     (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_YPbPr_0_vin_2p_ps(data)                                     (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_YPbPr_0_vin_6p_ps(data)                                     (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_YPbPr_0_vin_y1n_ps(data)                                    (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_YPbPr_0_vin_0p_gpi_en(data)                                 (0x00000020&((data)<<5))
#define  PINMUX_MAIN_YPbPr_0_vin_bn_gpi_en(data)                                 (0x00000010&((data)<<4))
#define  PINMUX_MAIN_YPbPr_0_vin_1p_gpi_en(data)                                 (0x00000008&((data)<<3))
#define  PINMUX_MAIN_YPbPr_0_vin_2p_gpi_en(data)                                 (0x00000004&((data)<<2))
#define  PINMUX_MAIN_YPbPr_0_vin_6p_gpi_en(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_YPbPr_0_vin_y1n_gpi_en(data)                                (0x00000001&(data))
#define  PINMUX_MAIN_YPbPr_0_get_vin_0p_ps(data)                                 ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_YPbPr_0_get_vin_bn_ps(data)                                 ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_YPbPr_0_get_vin_1p_ps(data)                                 ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_YPbPr_0_get_vin_2p_ps(data)                                 ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_YPbPr_0_get_vin_6p_ps(data)                                 ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_YPbPr_0_get_vin_y1n_ps(data)                                ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_YPbPr_0_get_vin_0p_gpi_en(data)                             ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_YPbPr_0_get_vin_bn_gpi_en(data)                             ((0x00000010&(data))>>4)
#define  PINMUX_MAIN_YPbPr_0_get_vin_1p_gpi_en(data)                             ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_YPbPr_0_get_vin_2p_gpi_en(data)                             ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_YPbPr_0_get_vin_6p_gpi_en(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_YPbPr_0_get_vin_y1n_gpi_en(data)                            (0x00000001&(data))

#define  PINMUX_MAIN_YPbPr_1                                                     0x180008A8
#define  PINMUX_MAIN_YPbPr_1_reg_addr                                            "0xB80008A8"
#define  PINMUX_MAIN_YPbPr_1_reg                                                 0xB80008A8
#define  PINMUX_MAIN_YPbPr_1_inst_addr                                           "0x0026"
#define  set_PINMUX_MAIN_YPbPr_1_reg(data)                                       (*((volatile unsigned int*)PINMUX_MAIN_YPbPr_1_reg)=data)
#define  get_PINMUX_MAIN_YPbPr_1_reg                                             (*((volatile unsigned int*)PINMUX_MAIN_YPbPr_1_reg))
#define  PINMUX_MAIN_YPbPr_1_vin_7p_ps_shift                                     (28)
#define  PINMUX_MAIN_YPbPr_1_vin_8p_ps_shift                                     (24)
#define  PINMUX_MAIN_YPbPr_1_vin_7p_gpi_en_shift                                 (1)
#define  PINMUX_MAIN_YPbPr_1_vin_8p_gpi_en_shift                                 (0)
#define  PINMUX_MAIN_YPbPr_1_vin_7p_ps_mask                                      (0xF0000000)
#define  PINMUX_MAIN_YPbPr_1_vin_8p_ps_mask                                      (0x0F000000)
#define  PINMUX_MAIN_YPbPr_1_vin_7p_gpi_en_mask                                  (0x00000002)
#define  PINMUX_MAIN_YPbPr_1_vin_8p_gpi_en_mask                                  (0x00000001)
#define  PINMUX_MAIN_YPbPr_1_vin_7p_ps(data)                                     (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_YPbPr_1_vin_8p_ps(data)                                     (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_YPbPr_1_vin_7p_gpi_en(data)                                 (0x00000002&((data)<<1))
#define  PINMUX_MAIN_YPbPr_1_vin_8p_gpi_en(data)                                 (0x00000001&(data))
#define  PINMUX_MAIN_YPbPr_1_get_vin_7p_ps(data)                                 ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_YPbPr_1_get_vin_8p_ps(data)                                 ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_YPbPr_1_get_vin_7p_gpi_en(data)                             ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_YPbPr_1_get_vin_8p_gpi_en(data)                             (0x00000001&(data))

#define  PINMUX_MAIN_Pin_Mux_Ctrl0                                               0x180008AC
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_reg_addr                                      "0xB80008AC"
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_reg                                           0xB80008AC
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_inst_addr                                     "0x0027"
#define  set_PINMUX_MAIN_Pin_Mux_Ctrl0_reg(data)                                 (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl0_reg)=data)
#define  get_PINMUX_MAIN_Pin_Mux_Ctrl0_reg                                       (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl0_reg))
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_cr_sd_in_sel_shift                            (23)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_demod_i2c_relay_in_sel_shift                  (19)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_i2c3_in_sel_shift                             (8)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_cr_sd_in_sel_mask                             (0x01800000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_demod_i2c_relay_in_sel_mask                   (0x00180000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_i2c3_in_sel_mask                              (0x00000700)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_cr_sd_in_sel(data)                            (0x01800000&((data)<<23))
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_demod_i2c_relay_in_sel(data)                  (0x00180000&((data)<<19))
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_i2c3_in_sel(data)                             (0x00000700&((data)<<8))
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_get_cr_sd_in_sel(data)                        ((0x01800000&(data))>>23)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_get_demod_i2c_relay_in_sel(data)              ((0x00180000&(data))>>19)
#define  PINMUX_MAIN_Pin_Mux_Ctrl0_get_i2c3_in_sel(data)                         ((0x00000700&(data))>>8)

#define  PINMUX_MAIN_Pin_Mux_Ctrl1                                               0x180008B0
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_reg_addr                                      "0xB80008B0"
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_reg                                           0xB80008B0
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_inst_addr                                     "0x0028"
#define  set_PINMUX_MAIN_Pin_Mux_Ctrl1_reg(data)                                 (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl1_reg)=data)
#define  get_PINMUX_MAIN_Pin_Mux_Ctrl1_reg                                       (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl1_reg))
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_sc0_in_sel_shift                              (28)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_sc1_in_sel_shift                              (19)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_vby1_sel_shift                                (4)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_sc0_in_sel_mask                               (0x30000000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_sc1_in_sel_mask                               (0x00180000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_vby1_sel_mask                                 (0x000000F0)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_sc0_in_sel(data)                              (0x30000000&((data)<<28))
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_sc1_in_sel(data)                              (0x00180000&((data)<<19))
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_vby1_sel(data)                                (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_get_sc0_in_sel(data)                          ((0x30000000&(data))>>28)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_get_sc1_in_sel(data)                          ((0x00180000&(data))>>19)
#define  PINMUX_MAIN_Pin_Mux_Ctrl1_get_vby1_sel(data)                            ((0x000000F0&(data))>>4)

#define  PINMUX_MAIN_Pin_Mux_Ctrl2                                               0x180008B4
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_reg_addr                                      "0xB80008B4"
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_reg                                           0xB80008B4
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_inst_addr                                     "0x0029"
#define  set_PINMUX_MAIN_Pin_Mux_Ctrl2_reg(data)                                 (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl2_reg)=data)
#define  get_PINMUX_MAIN_Pin_Mux_Ctrl2_reg                                       (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl2_reg))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p2_sck_sel_shift                      (25)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p3_sdo_sel_shift                      (22)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p4_sdi_sel_shift                      (19)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p2_sck_sel_shift                      (16)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p3_sdo_sel_shift                      (13)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p4_sdi_sel_shift                      (10)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_antoe_in_sel_shift                            (6)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_antrx_in_sel_shift                            (4)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_anttx_in_sel_shift                            (2)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_phif_enable_shift                             (0)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p2_sck_sel_mask                       (0x0E000000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p3_sdo_sel_mask                       (0x01C00000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p4_sdi_sel_mask                       (0x00380000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p2_sck_sel_mask                       (0x00070000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p3_sdo_sel_mask                       (0x0000E000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p4_sdi_sel_mask                       (0x00001C00)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_antoe_in_sel_mask                             (0x000000C0)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_antrx_in_sel_mask                             (0x00000030)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_anttx_in_sel_mask                             (0x0000000C)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_phif_enable_mask                              (0x00000001)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p2_sck_sel(data)                      (0x0E000000&((data)<<25))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p3_sdo_sel(data)                      (0x01C00000&((data)<<22))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi0_p4_sdi_sel(data)                      (0x00380000&((data)<<19))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p2_sck_sel(data)                      (0x00070000&((data)<<16))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p3_sdo_sel(data)                      (0x0000E000&((data)<<13))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_ld_spi1_p4_sdi_sel(data)                      (0x00001C00&((data)<<10))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_antoe_in_sel(data)                            (0x000000C0&((data)<<6))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_antrx_in_sel(data)                            (0x00000030&((data)<<4))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_anttx_in_sel(data)                            (0x0000000C&((data)<<2))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_phif_enable(data)                             (0x00000001&(data))
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_ld_spi0_p2_sck_sel(data)                  ((0x0E000000&(data))>>25)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_ld_spi0_p3_sdo_sel(data)                  ((0x01C00000&(data))>>22)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_ld_spi0_p4_sdi_sel(data)                  ((0x00380000&(data))>>19)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_ld_spi1_p2_sck_sel(data)                  ((0x00070000&(data))>>16)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_ld_spi1_p3_sdo_sel(data)                  ((0x0000E000&(data))>>13)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_ld_spi1_p4_sdi_sel(data)                  ((0x00001C00&(data))>>10)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_antoe_in_sel(data)                        ((0x000000C0&(data))>>6)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_antrx_in_sel(data)                        ((0x00000030&(data))>>4)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_anttx_in_sel(data)                        ((0x0000000C&(data))>>2)
#define  PINMUX_MAIN_Pin_Mux_Ctrl2_get_phif_enable(data)                         (0x00000001&(data))

#define  PINMUX_MAIN_Pin_Mux_Ctrl3                                               0x180008B8
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_reg_addr                                      "0xB80008B8"
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_reg                                           0xB80008B8
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_inst_addr                                     "0x002A"
#define  set_PINMUX_MAIN_Pin_Mux_Ctrl3_reg(data)                                 (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl3_reg)=data)
#define  get_PINMUX_MAIN_Pin_Mux_Ctrl3_reg                                       (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_Ctrl3_reg))
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_testpin_mux_shift                             (22)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_main_ext_clk_en_shift                         (6)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_pcmcia_dat_swap_sel_shift                     (5)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_testpin_mux_mask                              (0x3FC00000)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_main_ext_clk_en_mask                          (0x003FFFC0)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_pcmcia_dat_swap_sel_mask                      (0x00000020)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_testpin_mux(data)                             (0x3FC00000&((data)<<22))
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_main_ext_clk_en(data)                         (0x003FFFC0&((data)<<6))
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_pcmcia_dat_swap_sel(data)                     (0x00000020&((data)<<5))
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_get_testpin_mux(data)                         ((0x3FC00000&(data))>>22)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_get_main_ext_clk_en(data)                     ((0x003FFFC0&(data))>>6)
#define  PINMUX_MAIN_Pin_Mux_Ctrl3_get_pcmcia_dat_swap_sel(data)                 ((0x00000020&(data))>>5)

#define  PINMUX_MAIN_Pin_Mux_TPSEL                                               0x180008BC
#define  PINMUX_MAIN_Pin_Mux_TPSEL_reg_addr                                      "0xB80008BC"
#define  PINMUX_MAIN_Pin_Mux_TPSEL_reg                                           0xB80008BC
#define  PINMUX_MAIN_Pin_Mux_TPSEL_inst_addr                                     "0x002B"
#define  set_PINMUX_MAIN_Pin_Mux_TPSEL_reg(data)                                 (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_TPSEL_reg)=data)
#define  get_PINMUX_MAIN_Pin_Mux_TPSEL_reg                                       (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_TPSEL_reg))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp3_mux_selection_shift                       (29)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp2_mux_selection_shift                       (26)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp1_mux_selection_shift                       (23)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp0_mux_selection_shift                       (20)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp0_clk_sel_shift                             (17)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp1_clk_sel_shift                             (14)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp2_clk_sel_shift                             (11)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp3_clk_sel_shift                             (8)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_dtv_i2c_sel_shift                             (7)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_usb_pwr_flag0_in_sel_shift                    (5)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_usb3_pwr_flag0_in_sel_shift                   (3)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp3_mux_selection_mask                        (0xE0000000)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp2_mux_selection_mask                        (0x1C000000)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp1_mux_selection_mask                        (0x03800000)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp0_mux_selection_mask                        (0x00700000)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp0_clk_sel_mask                              (0x000E0000)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp1_clk_sel_mask                              (0x0001C000)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp2_clk_sel_mask                              (0x00003800)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp3_clk_sel_mask                              (0x00000700)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_dtv_i2c_sel_mask                              (0x00000080)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_usb_pwr_flag0_in_sel_mask                     (0x00000060)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_usb3_pwr_flag0_in_sel_mask                    (0x00000018)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp3_mux_selection(data)                       (0xE0000000&((data)<<29))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp2_mux_selection(data)                       (0x1C000000&((data)<<26))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp1_mux_selection(data)                       (0x03800000&((data)<<23))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp0_mux_selection(data)                       (0x00700000&((data)<<20))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp0_clk_sel(data)                             (0x000E0000&((data)<<17))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp1_clk_sel(data)                             (0x0001C000&((data)<<14))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp2_clk_sel(data)                             (0x00003800&((data)<<11))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_tp3_clk_sel(data)                             (0x00000700&((data)<<8))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_dtv_i2c_sel(data)                             (0x00000080&((data)<<7))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_usb_pwr_flag0_in_sel(data)                    (0x00000060&((data)<<5))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_usb3_pwr_flag0_in_sel(data)                   (0x00000018&((data)<<3))
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp3_mux_selection(data)                   ((0xE0000000&(data))>>29)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp2_mux_selection(data)                   ((0x1C000000&(data))>>26)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp1_mux_selection(data)                   ((0x03800000&(data))>>23)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp0_mux_selection(data)                   ((0x00700000&(data))>>20)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp0_clk_sel(data)                         ((0x000E0000&(data))>>17)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp1_clk_sel(data)                         ((0x0001C000&(data))>>14)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp2_clk_sel(data)                         ((0x00003800&(data))>>11)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_tp3_clk_sel(data)                         ((0x00000700&(data))>>8)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_dtv_i2c_sel(data)                         ((0x00000080&(data))>>7)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_usb_pwr_flag0_in_sel(data)                ((0x00000060&(data))>>5)
#define  PINMUX_MAIN_Pin_Mux_TPSEL_get_usb3_pwr_flag0_in_sel(data)               ((0x00000018&(data))>>3)

#define  PINMUX_MAIN_Schmidt_trigger_0                                           0x180008C0
#define  PINMUX_MAIN_Schmidt_trigger_0_reg_addr                                  "0xB80008C0"
#define  PINMUX_MAIN_Schmidt_trigger_0_reg                                       0xB80008C0
#define  PINMUX_MAIN_Schmidt_trigger_0_inst_addr                                 "0x002C"
#define  set_PINMUX_MAIN_Schmidt_trigger_0_reg(data)                             (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_0_reg)=data)
#define  get_PINMUX_MAIN_Schmidt_trigger_0_reg                                   (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_0_reg))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_0_smt_shift                          (31)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_1_smt_shift                          (30)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_2_smt_shift                          (29)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_3_smt_shift                          (28)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_4_smt_shift                          (27)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_5_smt_shift                          (26)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_6_smt_shift                          (25)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_7_smt_shift                          (24)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_8_smt_shift                          (23)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_9_smt_shift                          (22)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_10_smt_shift                         (21)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_11_smt_shift                         (20)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_12_smt_shift                         (19)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_13_smt_shift                         (18)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_14_smt_shift                         (17)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_15_smt_shift                         (16)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_16_smt_shift                         (15)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_17_smt_shift                         (14)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_18_smt_shift                         (13)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_19_smt_shift                         (12)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_20_smt_shift                         (11)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_21_smt_shift                         (10)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_22_smt_shift                         (9)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_23_smt_shift                         (8)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_24_smt_shift                         (7)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_25_smt_shift                         (6)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_26_smt_shift                         (5)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_27_smt_shift                         (4)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_28_smt_shift                         (3)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_29_smt_shift                         (2)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_30_smt_shift                         (1)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_31_smt_shift                         (0)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_0_smt_mask                           (0x80000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_1_smt_mask                           (0x40000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_2_smt_mask                           (0x20000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_3_smt_mask                           (0x10000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_4_smt_mask                           (0x08000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_5_smt_mask                           (0x04000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_6_smt_mask                           (0x02000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_7_smt_mask                           (0x01000000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_8_smt_mask                           (0x00800000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_9_smt_mask                           (0x00400000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_10_smt_mask                          (0x00200000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_11_smt_mask                          (0x00100000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_12_smt_mask                          (0x00080000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_13_smt_mask                          (0x00040000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_14_smt_mask                          (0x00020000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_15_smt_mask                          (0x00010000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_16_smt_mask                          (0x00008000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_17_smt_mask                          (0x00004000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_18_smt_mask                          (0x00002000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_19_smt_mask                          (0x00001000)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_20_smt_mask                          (0x00000800)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_21_smt_mask                          (0x00000400)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_22_smt_mask                          (0x00000200)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_23_smt_mask                          (0x00000100)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_24_smt_mask                          (0x00000080)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_25_smt_mask                          (0x00000040)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_26_smt_mask                          (0x00000020)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_27_smt_mask                          (0x00000010)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_28_smt_mask                          (0x00000008)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_29_smt_mask                          (0x00000004)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_30_smt_mask                          (0x00000002)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_31_smt_mask                          (0x00000001)
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_0_smt(data)                          (0x80000000&((data)<<31))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_1_smt(data)                          (0x40000000&((data)<<30))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_2_smt(data)                          (0x20000000&((data)<<29))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_3_smt(data)                          (0x10000000&((data)<<28))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_4_smt(data)                          (0x08000000&((data)<<27))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_5_smt(data)                          (0x04000000&((data)<<26))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_6_smt(data)                          (0x02000000&((data)<<25))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_7_smt(data)                          (0x01000000&((data)<<24))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_8_smt(data)                          (0x00800000&((data)<<23))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_9_smt(data)                          (0x00400000&((data)<<22))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_10_smt(data)                         (0x00200000&((data)<<21))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_11_smt(data)                         (0x00100000&((data)<<20))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_12_smt(data)                         (0x00080000&((data)<<19))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_13_smt(data)                         (0x00040000&((data)<<18))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_14_smt(data)                         (0x00020000&((data)<<17))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_15_smt(data)                         (0x00010000&((data)<<16))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_16_smt(data)                         (0x00008000&((data)<<15))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_17_smt(data)                         (0x00004000&((data)<<14))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_18_smt(data)                         (0x00002000&((data)<<13))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_19_smt(data)                         (0x00001000&((data)<<12))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_20_smt(data)                         (0x00000800&((data)<<11))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_21_smt(data)                         (0x00000400&((data)<<10))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_22_smt(data)                         (0x00000200&((data)<<9))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_23_smt(data)                         (0x00000100&((data)<<8))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_24_smt(data)                         (0x00000080&((data)<<7))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_25_smt(data)                         (0x00000040&((data)<<6))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_26_smt(data)                         (0x00000020&((data)<<5))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_27_smt(data)                         (0x00000010&((data)<<4))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_28_smt(data)                         (0x00000008&((data)<<3))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_29_smt(data)                         (0x00000004&((data)<<2))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_30_smt(data)                         (0x00000002&((data)<<1))
#define  PINMUX_MAIN_Schmidt_trigger_0_gpio_31_smt(data)                         (0x00000001&(data))
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_0_smt(data)                      ((0x80000000&(data))>>31)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_1_smt(data)                      ((0x40000000&(data))>>30)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_2_smt(data)                      ((0x20000000&(data))>>29)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_3_smt(data)                      ((0x10000000&(data))>>28)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_4_smt(data)                      ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_5_smt(data)                      ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_6_smt(data)                      ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_7_smt(data)                      ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_8_smt(data)                      ((0x00800000&(data))>>23)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_9_smt(data)                      ((0x00400000&(data))>>22)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_10_smt(data)                     ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_11_smt(data)                     ((0x00100000&(data))>>20)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_12_smt(data)                     ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_13_smt(data)                     ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_14_smt(data)                     ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_15_smt(data)                     ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_16_smt(data)                     ((0x00008000&(data))>>15)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_17_smt(data)                     ((0x00004000&(data))>>14)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_18_smt(data)                     ((0x00002000&(data))>>13)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_19_smt(data)                     ((0x00001000&(data))>>12)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_20_smt(data)                     ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_21_smt(data)                     ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_22_smt(data)                     ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_23_smt(data)                     ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_24_smt(data)                     ((0x00000080&(data))>>7)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_25_smt(data)                     ((0x00000040&(data))>>6)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_26_smt(data)                     ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_27_smt(data)                     ((0x00000010&(data))>>4)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_28_smt(data)                     ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_29_smt(data)                     ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_30_smt(data)                     ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_Schmidt_trigger_0_get_gpio_31_smt(data)                     (0x00000001&(data))

#define  PINMUX_MAIN_Schmidt_trigger_1                                           0x180008C4
#define  PINMUX_MAIN_Schmidt_trigger_1_reg_addr                                  "0xB80008C4"
#define  PINMUX_MAIN_Schmidt_trigger_1_reg                                       0xB80008C4
#define  PINMUX_MAIN_Schmidt_trigger_1_inst_addr                                 "0x002D"
#define  set_PINMUX_MAIN_Schmidt_trigger_1_reg(data)                             (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_1_reg)=data)
#define  get_PINMUX_MAIN_Schmidt_trigger_1_reg                                   (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_1_reg))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_32_smt_shift                         (31)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_33_smt_shift                         (30)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_34_smt_shift                         (29)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_35_smt_shift                         (28)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_36_smt_shift                         (27)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_37_smt_shift                         (26)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_38_smt_shift                         (25)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_39_smt_shift                         (24)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_40_smt_shift                         (23)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_41_smt_shift                         (22)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_42_smt_shift                         (21)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_43_smt_shift                         (20)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_44_smt_shift                         (19)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_45_smt_shift                         (18)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_46_smt_shift                         (17)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_47_smt_shift                         (16)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_48_smt_shift                         (15)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_49_smt_shift                         (14)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_50_smt_shift                         (13)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_51_smt_shift                         (12)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_52_smt_shift                         (11)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_53_smt_shift                         (10)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_54_smt_shift                         (9)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_55_smt_shift                         (8)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_56_smt_shift                         (7)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_57_smt_shift                         (6)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_58_smt_shift                         (5)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_59_smt_shift                         (4)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_60_smt_shift                         (3)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_61_smt_shift                         (2)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_62_smt_shift                         (1)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_63_smt_shift                         (0)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_32_smt_mask                          (0x80000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_33_smt_mask                          (0x40000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_34_smt_mask                          (0x20000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_35_smt_mask                          (0x10000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_36_smt_mask                          (0x08000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_37_smt_mask                          (0x04000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_38_smt_mask                          (0x02000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_39_smt_mask                          (0x01000000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_40_smt_mask                          (0x00800000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_41_smt_mask                          (0x00400000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_42_smt_mask                          (0x00200000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_43_smt_mask                          (0x00100000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_44_smt_mask                          (0x00080000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_45_smt_mask                          (0x00040000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_46_smt_mask                          (0x00020000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_47_smt_mask                          (0x00010000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_48_smt_mask                          (0x00008000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_49_smt_mask                          (0x00004000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_50_smt_mask                          (0x00002000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_51_smt_mask                          (0x00001000)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_52_smt_mask                          (0x00000800)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_53_smt_mask                          (0x00000400)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_54_smt_mask                          (0x00000200)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_55_smt_mask                          (0x00000100)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_56_smt_mask                          (0x00000080)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_57_smt_mask                          (0x00000040)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_58_smt_mask                          (0x00000020)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_59_smt_mask                          (0x00000010)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_60_smt_mask                          (0x00000008)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_61_smt_mask                          (0x00000004)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_62_smt_mask                          (0x00000002)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_63_smt_mask                          (0x00000001)
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_32_smt(data)                         (0x80000000&((data)<<31))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_33_smt(data)                         (0x40000000&((data)<<30))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_34_smt(data)                         (0x20000000&((data)<<29))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_35_smt(data)                         (0x10000000&((data)<<28))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_36_smt(data)                         (0x08000000&((data)<<27))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_37_smt(data)                         (0x04000000&((data)<<26))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_38_smt(data)                         (0x02000000&((data)<<25))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_39_smt(data)                         (0x01000000&((data)<<24))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_40_smt(data)                         (0x00800000&((data)<<23))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_41_smt(data)                         (0x00400000&((data)<<22))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_42_smt(data)                         (0x00200000&((data)<<21))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_43_smt(data)                         (0x00100000&((data)<<20))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_44_smt(data)                         (0x00080000&((data)<<19))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_45_smt(data)                         (0x00040000&((data)<<18))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_46_smt(data)                         (0x00020000&((data)<<17))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_47_smt(data)                         (0x00010000&((data)<<16))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_48_smt(data)                         (0x00008000&((data)<<15))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_49_smt(data)                         (0x00004000&((data)<<14))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_50_smt(data)                         (0x00002000&((data)<<13))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_51_smt(data)                         (0x00001000&((data)<<12))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_52_smt(data)                         (0x00000800&((data)<<11))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_53_smt(data)                         (0x00000400&((data)<<10))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_54_smt(data)                         (0x00000200&((data)<<9))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_55_smt(data)                         (0x00000100&((data)<<8))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_56_smt(data)                         (0x00000080&((data)<<7))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_57_smt(data)                         (0x00000040&((data)<<6))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_58_smt(data)                         (0x00000020&((data)<<5))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_59_smt(data)                         (0x00000010&((data)<<4))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_60_smt(data)                         (0x00000008&((data)<<3))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_61_smt(data)                         (0x00000004&((data)<<2))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_62_smt(data)                         (0x00000002&((data)<<1))
#define  PINMUX_MAIN_Schmidt_trigger_1_gpio_63_smt(data)                         (0x00000001&(data))
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_32_smt(data)                     ((0x80000000&(data))>>31)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_33_smt(data)                     ((0x40000000&(data))>>30)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_34_smt(data)                     ((0x20000000&(data))>>29)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_35_smt(data)                     ((0x10000000&(data))>>28)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_36_smt(data)                     ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_37_smt(data)                     ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_38_smt(data)                     ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_39_smt(data)                     ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_40_smt(data)                     ((0x00800000&(data))>>23)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_41_smt(data)                     ((0x00400000&(data))>>22)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_42_smt(data)                     ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_43_smt(data)                     ((0x00100000&(data))>>20)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_44_smt(data)                     ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_45_smt(data)                     ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_46_smt(data)                     ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_47_smt(data)                     ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_48_smt(data)                     ((0x00008000&(data))>>15)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_49_smt(data)                     ((0x00004000&(data))>>14)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_50_smt(data)                     ((0x00002000&(data))>>13)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_51_smt(data)                     ((0x00001000&(data))>>12)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_52_smt(data)                     ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_53_smt(data)                     ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_54_smt(data)                     ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_55_smt(data)                     ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_56_smt(data)                     ((0x00000080&(data))>>7)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_57_smt(data)                     ((0x00000040&(data))>>6)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_58_smt(data)                     ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_59_smt(data)                     ((0x00000010&(data))>>4)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_60_smt(data)                     ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_61_smt(data)                     ((0x00000004&(data))>>2)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_62_smt(data)                     ((0x00000002&(data))>>1)
#define  PINMUX_MAIN_Schmidt_trigger_1_get_gpio_63_smt(data)                     (0x00000001&(data))

#define  PINMUX_MAIN_Schmidt_trigger_2                                           0x180008C8
#define  PINMUX_MAIN_Schmidt_trigger_2_reg_addr                                  "0xB80008C8"
#define  PINMUX_MAIN_Schmidt_trigger_2_reg                                       0xB80008C8
#define  PINMUX_MAIN_Schmidt_trigger_2_inst_addr                                 "0x002E"
#define  set_PINMUX_MAIN_Schmidt_trigger_2_reg(data)                             (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_2_reg)=data)
#define  get_PINMUX_MAIN_Schmidt_trigger_2_reg                                   (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_2_reg))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_64_smt_shift                         (31)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_65_smt_shift                         (30)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_66_smt_shift                         (29)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_67_smt_shift                         (28)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_68_smt_shift                         (27)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_69_smt_shift                         (26)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_70_smt_shift                         (25)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_71_smt_shift                         (24)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_72_smt_shift                         (23)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_73_smt_shift                         (22)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_74_smt_shift                         (21)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_75_smt_shift                         (20)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_76_smt_shift                         (19)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_77_smt_shift                         (18)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_78_smt_shift                         (17)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_79_smt_shift                         (16)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_80_smt_shift                         (15)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_81_smt_shift                         (14)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_82_smt_shift                         (13)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_83_smt_shift                         (12)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_84_smt_shift                         (11)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_85_smt_shift                         (10)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_86_smt_shift                         (9)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_87_smt_shift                         (8)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_88_smt_shift                         (7)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_89_smt_shift                         (6)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_90_smt_shift                         (5)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_91_smt_shift                         (4)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_92_smt_shift                         (3)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_93_smt_shift                         (2)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_64_smt_mask                          (0x80000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_65_smt_mask                          (0x40000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_66_smt_mask                          (0x20000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_67_smt_mask                          (0x10000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_68_smt_mask                          (0x08000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_69_smt_mask                          (0x04000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_70_smt_mask                          (0x02000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_71_smt_mask                          (0x01000000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_72_smt_mask                          (0x00800000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_73_smt_mask                          (0x00400000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_74_smt_mask                          (0x00200000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_75_smt_mask                          (0x00100000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_76_smt_mask                          (0x00080000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_77_smt_mask                          (0x00040000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_78_smt_mask                          (0x00020000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_79_smt_mask                          (0x00010000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_80_smt_mask                          (0x00008000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_81_smt_mask                          (0x00004000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_82_smt_mask                          (0x00002000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_83_smt_mask                          (0x00001000)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_84_smt_mask                          (0x00000800)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_85_smt_mask                          (0x00000400)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_86_smt_mask                          (0x00000200)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_87_smt_mask                          (0x00000100)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_88_smt_mask                          (0x00000080)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_89_smt_mask                          (0x00000040)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_90_smt_mask                          (0x00000020)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_91_smt_mask                          (0x00000010)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_92_smt_mask                          (0x00000008)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_93_smt_mask                          (0x00000004)
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_64_smt(data)                         (0x80000000&((data)<<31))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_65_smt(data)                         (0x40000000&((data)<<30))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_66_smt(data)                         (0x20000000&((data)<<29))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_67_smt(data)                         (0x10000000&((data)<<28))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_68_smt(data)                         (0x08000000&((data)<<27))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_69_smt(data)                         (0x04000000&((data)<<26))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_70_smt(data)                         (0x02000000&((data)<<25))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_71_smt(data)                         (0x01000000&((data)<<24))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_72_smt(data)                         (0x00800000&((data)<<23))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_73_smt(data)                         (0x00400000&((data)<<22))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_74_smt(data)                         (0x00200000&((data)<<21))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_75_smt(data)                         (0x00100000&((data)<<20))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_76_smt(data)                         (0x00080000&((data)<<19))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_77_smt(data)                         (0x00040000&((data)<<18))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_78_smt(data)                         (0x00020000&((data)<<17))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_79_smt(data)                         (0x00010000&((data)<<16))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_80_smt(data)                         (0x00008000&((data)<<15))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_81_smt(data)                         (0x00004000&((data)<<14))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_82_smt(data)                         (0x00002000&((data)<<13))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_83_smt(data)                         (0x00001000&((data)<<12))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_84_smt(data)                         (0x00000800&((data)<<11))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_85_smt(data)                         (0x00000400&((data)<<10))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_86_smt(data)                         (0x00000200&((data)<<9))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_87_smt(data)                         (0x00000100&((data)<<8))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_88_smt(data)                         (0x00000080&((data)<<7))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_89_smt(data)                         (0x00000040&((data)<<6))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_90_smt(data)                         (0x00000020&((data)<<5))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_91_smt(data)                         (0x00000010&((data)<<4))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_92_smt(data)                         (0x00000008&((data)<<3))
#define  PINMUX_MAIN_Schmidt_trigger_2_gpio_93_smt(data)                         (0x00000004&((data)<<2))
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_64_smt(data)                     ((0x80000000&(data))>>31)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_65_smt(data)                     ((0x40000000&(data))>>30)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_66_smt(data)                     ((0x20000000&(data))>>29)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_67_smt(data)                     ((0x10000000&(data))>>28)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_68_smt(data)                     ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_69_smt(data)                     ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_70_smt(data)                     ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_71_smt(data)                     ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_72_smt(data)                     ((0x00800000&(data))>>23)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_73_smt(data)                     ((0x00400000&(data))>>22)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_74_smt(data)                     ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_75_smt(data)                     ((0x00100000&(data))>>20)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_76_smt(data)                     ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_77_smt(data)                     ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_78_smt(data)                     ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_79_smt(data)                     ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_80_smt(data)                     ((0x00008000&(data))>>15)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_81_smt(data)                     ((0x00004000&(data))>>14)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_82_smt(data)                     ((0x00002000&(data))>>13)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_83_smt(data)                     ((0x00001000&(data))>>12)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_84_smt(data)                     ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_85_smt(data)                     ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_86_smt(data)                     ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_87_smt(data)                     ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_88_smt(data)                     ((0x00000080&(data))>>7)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_89_smt(data)                     ((0x00000040&(data))>>6)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_90_smt(data)                     ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_91_smt(data)                     ((0x00000010&(data))>>4)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_92_smt(data)                     ((0x00000008&(data))>>3)
#define  PINMUX_MAIN_Schmidt_trigger_2_get_gpio_93_smt(data)                     ((0x00000004&(data))>>2)

#define  PINMUX_MAIN_Schmidt_trigger_3                                           0x180008CC
#define  PINMUX_MAIN_Schmidt_trigger_3_reg_addr                                  "0xB80008CC"
#define  PINMUX_MAIN_Schmidt_trigger_3_reg                                       0xB80008CC
#define  PINMUX_MAIN_Schmidt_trigger_3_inst_addr                                 "0x002F"
#define  set_PINMUX_MAIN_Schmidt_trigger_3_reg(data)                             (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_3_reg)=data)
#define  get_PINMUX_MAIN_Schmidt_trigger_3_reg                                   (*((volatile unsigned int*)PINMUX_MAIN_Schmidt_trigger_3_reg))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_clk_smt_shift                        (21)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_rst_n_smt_shift                      (20)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_ds_smt_shift                         (19)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_cmd_smt_shift                        (18)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d0_smt_shift                         (17)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d1_smt_shift                         (16)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d2_smt_shift                         (15)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d3_smt_shift                         (14)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d4_smt_shift                         (13)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d5_smt_shift                         (12)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d6_smt_shift                         (11)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d7_smt_shift                         (10)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_clk_smt_mask                         (0x00200000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_rst_n_smt_mask                       (0x00100000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_ds_smt_mask                          (0x00080000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_cmd_smt_mask                         (0x00040000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d0_smt_mask                          (0x00020000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d1_smt_mask                          (0x00010000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d2_smt_mask                          (0x00008000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d3_smt_mask                          (0x00004000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d4_smt_mask                          (0x00002000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d5_smt_mask                          (0x00001000)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d6_smt_mask                          (0x00000800)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d7_smt_mask                          (0x00000400)
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_clk_smt(data)                        (0x00200000&((data)<<21))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_rst_n_smt(data)                      (0x00100000&((data)<<20))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_ds_smt(data)                         (0x00080000&((data)<<19))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_cmd_smt(data)                        (0x00040000&((data)<<18))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d0_smt(data)                         (0x00020000&((data)<<17))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d1_smt(data)                         (0x00010000&((data)<<16))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d2_smt(data)                         (0x00008000&((data)<<15))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d3_smt(data)                         (0x00004000&((data)<<14))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d4_smt(data)                         (0x00002000&((data)<<13))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d5_smt(data)                         (0x00001000&((data)<<12))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d6_smt(data)                         (0x00000800&((data)<<11))
#define  PINMUX_MAIN_Schmidt_trigger_3_emmc_d7_smt(data)                         (0x00000400&((data)<<10))
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_clk_smt(data)                    ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_rst_n_smt(data)                  ((0x00100000&(data))>>20)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_ds_smt(data)                     ((0x00080000&(data))>>19)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_cmd_smt(data)                    ((0x00040000&(data))>>18)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d0_smt(data)                     ((0x00020000&(data))>>17)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d1_smt(data)                     ((0x00010000&(data))>>16)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d2_smt(data)                     ((0x00008000&(data))>>15)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d3_smt(data)                     ((0x00004000&(data))>>14)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d4_smt(data)                     ((0x00002000&(data))>>13)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d5_smt(data)                     ((0x00001000&(data))>>12)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d6_smt(data)                     ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_Schmidt_trigger_3_get_emmc_d7_smt(data)                     ((0x00000400&(data))>>10)

#define  PINMUX_MAIN_EMMC_0                                                      0x180008D0
#define  PINMUX_MAIN_EMMC_0_reg_addr                                             "0xB80008D0"
#define  PINMUX_MAIN_EMMC_0_reg                                                  0xB80008D0
#define  PINMUX_MAIN_EMMC_0_inst_addr                                            "0x0030"
#define  set_PINMUX_MAIN_EMMC_0_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_0_reg)=data)
#define  get_PINMUX_MAIN_EMMC_0_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_0_reg))
#define  PINMUX_MAIN_EMMC_0_emmc_clk_ps_shift                                    (28)
#define  PINMUX_MAIN_EMMC_0_emmc_rst_n_ps_shift                                  (24)
#define  PINMUX_MAIN_EMMC_0_emmc_ds_ps_shift                                     (20)
#define  PINMUX_MAIN_EMMC_0_emmc_cmd_ps_shift                                    (16)
#define  PINMUX_MAIN_EMMC_0_emmc_clk_ps_mask                                     (0xF0000000)
#define  PINMUX_MAIN_EMMC_0_emmc_rst_n_ps_mask                                   (0x0F000000)
#define  PINMUX_MAIN_EMMC_0_emmc_ds_ps_mask                                      (0x00F00000)
#define  PINMUX_MAIN_EMMC_0_emmc_cmd_ps_mask                                     (0x000F0000)
#define  PINMUX_MAIN_EMMC_0_emmc_clk_ps(data)                                    (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_EMMC_0_emmc_rst_n_ps(data)                                  (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_0_emmc_ds_ps(data)                                     (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_EMMC_0_emmc_cmd_ps(data)                                    (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_EMMC_0_get_emmc_clk_ps(data)                                ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_EMMC_0_get_emmc_rst_n_ps(data)                              ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_0_get_emmc_ds_ps(data)                                 ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_EMMC_0_get_emmc_cmd_ps(data)                                ((0x000F0000&(data))>>16)

#define  PINMUX_MAIN_EMMC_1                                                      0x180008D4
#define  PINMUX_MAIN_EMMC_1_reg_addr                                             "0xB80008D4"
#define  PINMUX_MAIN_EMMC_1_reg                                                  0xB80008D4
#define  PINMUX_MAIN_EMMC_1_inst_addr                                            "0x0031"
#define  set_PINMUX_MAIN_EMMC_1_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_1_reg)=data)
#define  get_PINMUX_MAIN_EMMC_1_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_1_reg))
#define  PINMUX_MAIN_EMMC_1_emmc_d0_ps_shift                                     (28)
#define  PINMUX_MAIN_EMMC_1_emmc_d1_ps_shift                                     (24)
#define  PINMUX_MAIN_EMMC_1_emmc_d2_ps_shift                                     (20)
#define  PINMUX_MAIN_EMMC_1_emmc_d3_ps_shift                                     (16)
#define  PINMUX_MAIN_EMMC_1_emmc_d4_ps_shift                                     (12)
#define  PINMUX_MAIN_EMMC_1_emmc_d5_ps_shift                                     (8)
#define  PINMUX_MAIN_EMMC_1_emmc_d6_ps_shift                                     (4)
#define  PINMUX_MAIN_EMMC_1_emmc_d7_ps_shift                                     (0)
#define  PINMUX_MAIN_EMMC_1_emmc_d0_ps_mask                                      (0xF0000000)
#define  PINMUX_MAIN_EMMC_1_emmc_d1_ps_mask                                      (0x0F000000)
#define  PINMUX_MAIN_EMMC_1_emmc_d2_ps_mask                                      (0x00F00000)
#define  PINMUX_MAIN_EMMC_1_emmc_d3_ps_mask                                      (0x000F0000)
#define  PINMUX_MAIN_EMMC_1_emmc_d4_ps_mask                                      (0x0000F000)
#define  PINMUX_MAIN_EMMC_1_emmc_d5_ps_mask                                      (0x00000F00)
#define  PINMUX_MAIN_EMMC_1_emmc_d6_ps_mask                                      (0x000000F0)
#define  PINMUX_MAIN_EMMC_1_emmc_d7_ps_mask                                      (0x0000000F)
#define  PINMUX_MAIN_EMMC_1_emmc_d0_ps(data)                                     (0xF0000000&((data)<<28))
#define  PINMUX_MAIN_EMMC_1_emmc_d1_ps(data)                                     (0x0F000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_1_emmc_d2_ps(data)                                     (0x00F00000&((data)<<20))
#define  PINMUX_MAIN_EMMC_1_emmc_d3_ps(data)                                     (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_EMMC_1_emmc_d4_ps(data)                                     (0x0000F000&((data)<<12))
#define  PINMUX_MAIN_EMMC_1_emmc_d5_ps(data)                                     (0x00000F00&((data)<<8))
#define  PINMUX_MAIN_EMMC_1_emmc_d6_ps(data)                                     (0x000000F0&((data)<<4))
#define  PINMUX_MAIN_EMMC_1_emmc_d7_ps(data)                                     (0x0000000F&(data))
#define  PINMUX_MAIN_EMMC_1_get_emmc_d0_ps(data)                                 ((0xF0000000&(data))>>28)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d1_ps(data)                                 ((0x0F000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d2_ps(data)                                 ((0x00F00000&(data))>>20)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d3_ps(data)                                 ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d4_ps(data)                                 ((0x0000F000&(data))>>12)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d5_ps(data)                                 ((0x00000F00&(data))>>8)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d6_ps(data)                                 ((0x000000F0&(data))>>4)
#define  PINMUX_MAIN_EMMC_1_get_emmc_d7_ps(data)                                 (0x0000000F&(data))

#define  PINMUX_MAIN_EMMC_2                                                      0x180008D8
#define  PINMUX_MAIN_EMMC_2_reg_addr                                             "0xB80008D8"
#define  PINMUX_MAIN_EMMC_2_reg                                                  0xB80008D8
#define  PINMUX_MAIN_EMMC_2_inst_addr                                            "0x0032"
#define  set_PINMUX_MAIN_EMMC_2_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_2_reg)=data)
#define  get_PINMUX_MAIN_EMMC_2_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_2_reg))
#define  PINMUX_MAIN_EMMC_2_emmc_clk_ds_shift                                    (24)
#define  PINMUX_MAIN_EMMC_2_emmc_rst_n_ds_shift                                  (16)
#define  PINMUX_MAIN_EMMC_2_emmc_ds_ds_shift                                     (8)
#define  PINMUX_MAIN_EMMC_2_emmc_cmd_ds_shift                                    (0)
#define  PINMUX_MAIN_EMMC_2_emmc_clk_ds_mask                                     (0xFF000000)
#define  PINMUX_MAIN_EMMC_2_emmc_rst_n_ds_mask                                   (0x00FF0000)
#define  PINMUX_MAIN_EMMC_2_emmc_ds_ds_mask                                      (0x0000FF00)
#define  PINMUX_MAIN_EMMC_2_emmc_cmd_ds_mask                                     (0x000000FF)
#define  PINMUX_MAIN_EMMC_2_emmc_clk_ds(data)                                    (0xFF000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_2_emmc_rst_n_ds(data)                                  (0x00FF0000&((data)<<16))
#define  PINMUX_MAIN_EMMC_2_emmc_ds_ds(data)                                     (0x0000FF00&((data)<<8))
#define  PINMUX_MAIN_EMMC_2_emmc_cmd_ds(data)                                    (0x000000FF&(data))
#define  PINMUX_MAIN_EMMC_2_get_emmc_clk_ds(data)                                ((0xFF000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_2_get_emmc_rst_n_ds(data)                              ((0x00FF0000&(data))>>16)
#define  PINMUX_MAIN_EMMC_2_get_emmc_ds_ds(data)                                 ((0x0000FF00&(data))>>8)
#define  PINMUX_MAIN_EMMC_2_get_emmc_cmd_ds(data)                                (0x000000FF&(data))

#define  PINMUX_MAIN_EMMC_3                                                      0x180008DC
#define  PINMUX_MAIN_EMMC_3_reg_addr                                             "0xB80008DC"
#define  PINMUX_MAIN_EMMC_3_reg                                                  0xB80008DC
#define  PINMUX_MAIN_EMMC_3_inst_addr                                            "0x0033"
#define  set_PINMUX_MAIN_EMMC_3_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_3_reg)=data)
#define  get_PINMUX_MAIN_EMMC_3_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_3_reg))
#define  PINMUX_MAIN_EMMC_3_emmc_d0_ds_shift                                     (24)
#define  PINMUX_MAIN_EMMC_3_emmc_d1_ds_shift                                     (16)
#define  PINMUX_MAIN_EMMC_3_emmc_d2_ds_shift                                     (8)
#define  PINMUX_MAIN_EMMC_3_emmc_d3_ds_shift                                     (0)
#define  PINMUX_MAIN_EMMC_3_emmc_d0_ds_mask                                      (0xFF000000)
#define  PINMUX_MAIN_EMMC_3_emmc_d1_ds_mask                                      (0x00FF0000)
#define  PINMUX_MAIN_EMMC_3_emmc_d2_ds_mask                                      (0x0000FF00)
#define  PINMUX_MAIN_EMMC_3_emmc_d3_ds_mask                                      (0x000000FF)
#define  PINMUX_MAIN_EMMC_3_emmc_d0_ds(data)                                     (0xFF000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_3_emmc_d1_ds(data)                                     (0x00FF0000&((data)<<16))
#define  PINMUX_MAIN_EMMC_3_emmc_d2_ds(data)                                     (0x0000FF00&((data)<<8))
#define  PINMUX_MAIN_EMMC_3_emmc_d3_ds(data)                                     (0x000000FF&(data))
#define  PINMUX_MAIN_EMMC_3_get_emmc_d0_ds(data)                                 ((0xFF000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_3_get_emmc_d1_ds(data)                                 ((0x00FF0000&(data))>>16)
#define  PINMUX_MAIN_EMMC_3_get_emmc_d2_ds(data)                                 ((0x0000FF00&(data))>>8)
#define  PINMUX_MAIN_EMMC_3_get_emmc_d3_ds(data)                                 (0x000000FF&(data))

#define  PINMUX_MAIN_EMMC_4                                                      0x180008E0
#define  PINMUX_MAIN_EMMC_4_reg_addr                                             "0xB80008E0"
#define  PINMUX_MAIN_EMMC_4_reg                                                  0xB80008E0
#define  PINMUX_MAIN_EMMC_4_inst_addr                                            "0x0034"
#define  set_PINMUX_MAIN_EMMC_4_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_4_reg)=data)
#define  get_PINMUX_MAIN_EMMC_4_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_4_reg))
#define  PINMUX_MAIN_EMMC_4_emmc_d4_ds_shift                                     (24)
#define  PINMUX_MAIN_EMMC_4_emmc_d5_ds_shift                                     (16)
#define  PINMUX_MAIN_EMMC_4_emmc_d6_ds_shift                                     (8)
#define  PINMUX_MAIN_EMMC_4_emmc_d7_ds_shift                                     (0)
#define  PINMUX_MAIN_EMMC_4_emmc_d4_ds_mask                                      (0xFF000000)
#define  PINMUX_MAIN_EMMC_4_emmc_d5_ds_mask                                      (0x00FF0000)
#define  PINMUX_MAIN_EMMC_4_emmc_d6_ds_mask                                      (0x0000FF00)
#define  PINMUX_MAIN_EMMC_4_emmc_d7_ds_mask                                      (0x000000FF)
#define  PINMUX_MAIN_EMMC_4_emmc_d4_ds(data)                                     (0xFF000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_4_emmc_d5_ds(data)                                     (0x00FF0000&((data)<<16))
#define  PINMUX_MAIN_EMMC_4_emmc_d6_ds(data)                                     (0x0000FF00&((data)<<8))
#define  PINMUX_MAIN_EMMC_4_emmc_d7_ds(data)                                     (0x000000FF&(data))
#define  PINMUX_MAIN_EMMC_4_get_emmc_d4_ds(data)                                 ((0xFF000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_4_get_emmc_d5_ds(data)                                 ((0x00FF0000&(data))>>16)
#define  PINMUX_MAIN_EMMC_4_get_emmc_d6_ds(data)                                 ((0x0000FF00&(data))>>8)
#define  PINMUX_MAIN_EMMC_4_get_emmc_d7_ds(data)                                 (0x000000FF&(data))

#define  PINMUX_MAIN_EMMC_5                                                      0x180008E4
#define  PINMUX_MAIN_EMMC_5_reg_addr                                             "0xB80008E4"
#define  PINMUX_MAIN_EMMC_5_reg                                                  0xB80008E4
#define  PINMUX_MAIN_EMMC_5_inst_addr                                            "0x0035"
#define  set_PINMUX_MAIN_EMMC_5_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_5_reg)=data)
#define  get_PINMUX_MAIN_EMMC_5_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_5_reg))
#define  PINMUX_MAIN_EMMC_5_emmc_clk_pu_shift                                    (31)
#define  PINMUX_MAIN_EMMC_5_emmc_rst_n_pu_shift                                  (30)
#define  PINMUX_MAIN_EMMC_5_emmc_ds_pu_shift                                     (29)
#define  PINMUX_MAIN_EMMC_5_emmc_cmd_pu_shift                                    (28)
#define  PINMUX_MAIN_EMMC_5_emmc_d0_pu_shift                                     (27)
#define  PINMUX_MAIN_EMMC_5_emmc_d1_pu_shift                                     (26)
#define  PINMUX_MAIN_EMMC_5_emmc_d2_pu_shift                                     (25)
#define  PINMUX_MAIN_EMMC_5_emmc_d3_pu_shift                                     (24)
#define  PINMUX_MAIN_EMMC_5_emmc_d4_pu_shift                                     (23)
#define  PINMUX_MAIN_EMMC_5_emmc_d5_pu_shift                                     (22)
#define  PINMUX_MAIN_EMMC_5_emmc_d6_pu_shift                                     (21)
#define  PINMUX_MAIN_EMMC_5_emmc_d7_pu_shift                                     (20)
#define  PINMUX_MAIN_EMMC_5_emmc_clk_pd_shift                                    (15)
#define  PINMUX_MAIN_EMMC_5_emmc_rst_n_pd_shift                                  (14)
#define  PINMUX_MAIN_EMMC_5_emmc_ds_pd_shift                                     (13)
#define  PINMUX_MAIN_EMMC_5_emmc_cmd_pd_shift                                    (12)
#define  PINMUX_MAIN_EMMC_5_emmc_d0_pd_shift                                     (11)
#define  PINMUX_MAIN_EMMC_5_emmc_d1_pd_shift                                     (10)
#define  PINMUX_MAIN_EMMC_5_emmc_d2_pd_shift                                     (9)
#define  PINMUX_MAIN_EMMC_5_emmc_d3_pd_shift                                     (8)
#define  PINMUX_MAIN_EMMC_5_emmc_d4_pd_shift                                     (7)
#define  PINMUX_MAIN_EMMC_5_emmc_d5_pd_shift                                     (6)
#define  PINMUX_MAIN_EMMC_5_emmc_d6_pd_shift                                     (5)
#define  PINMUX_MAIN_EMMC_5_emmc_d7_pd_shift                                     (4)
#define  PINMUX_MAIN_EMMC_5_emmc_clk_pu_mask                                     (0x80000000)
#define  PINMUX_MAIN_EMMC_5_emmc_rst_n_pu_mask                                   (0x40000000)
#define  PINMUX_MAIN_EMMC_5_emmc_ds_pu_mask                                      (0x20000000)
#define  PINMUX_MAIN_EMMC_5_emmc_cmd_pu_mask                                     (0x10000000)
#define  PINMUX_MAIN_EMMC_5_emmc_d0_pu_mask                                      (0x08000000)
#define  PINMUX_MAIN_EMMC_5_emmc_d1_pu_mask                                      (0x04000000)
#define  PINMUX_MAIN_EMMC_5_emmc_d2_pu_mask                                      (0x02000000)
#define  PINMUX_MAIN_EMMC_5_emmc_d3_pu_mask                                      (0x01000000)
#define  PINMUX_MAIN_EMMC_5_emmc_d4_pu_mask                                      (0x00800000)
#define  PINMUX_MAIN_EMMC_5_emmc_d5_pu_mask                                      (0x00400000)
#define  PINMUX_MAIN_EMMC_5_emmc_d6_pu_mask                                      (0x00200000)
#define  PINMUX_MAIN_EMMC_5_emmc_d7_pu_mask                                      (0x00100000)
#define  PINMUX_MAIN_EMMC_5_emmc_clk_pd_mask                                     (0x00008000)
#define  PINMUX_MAIN_EMMC_5_emmc_rst_n_pd_mask                                   (0x00004000)
#define  PINMUX_MAIN_EMMC_5_emmc_ds_pd_mask                                      (0x00002000)
#define  PINMUX_MAIN_EMMC_5_emmc_cmd_pd_mask                                     (0x00001000)
#define  PINMUX_MAIN_EMMC_5_emmc_d0_pd_mask                                      (0x00000800)
#define  PINMUX_MAIN_EMMC_5_emmc_d1_pd_mask                                      (0x00000400)
#define  PINMUX_MAIN_EMMC_5_emmc_d2_pd_mask                                      (0x00000200)
#define  PINMUX_MAIN_EMMC_5_emmc_d3_pd_mask                                      (0x00000100)
#define  PINMUX_MAIN_EMMC_5_emmc_d4_pd_mask                                      (0x00000080)
#define  PINMUX_MAIN_EMMC_5_emmc_d5_pd_mask                                      (0x00000040)
#define  PINMUX_MAIN_EMMC_5_emmc_d6_pd_mask                                      (0x00000020)
#define  PINMUX_MAIN_EMMC_5_emmc_d7_pd_mask                                      (0x00000010)
#define  PINMUX_MAIN_EMMC_5_emmc_clk_pu(data)                                    (0x80000000&((data)<<31))
#define  PINMUX_MAIN_EMMC_5_emmc_rst_n_pu(data)                                  (0x40000000&((data)<<30))
#define  PINMUX_MAIN_EMMC_5_emmc_ds_pu(data)                                     (0x20000000&((data)<<29))
#define  PINMUX_MAIN_EMMC_5_emmc_cmd_pu(data)                                    (0x10000000&((data)<<28))
#define  PINMUX_MAIN_EMMC_5_emmc_d0_pu(data)                                     (0x08000000&((data)<<27))
#define  PINMUX_MAIN_EMMC_5_emmc_d1_pu(data)                                     (0x04000000&((data)<<26))
#define  PINMUX_MAIN_EMMC_5_emmc_d2_pu(data)                                     (0x02000000&((data)<<25))
#define  PINMUX_MAIN_EMMC_5_emmc_d3_pu(data)                                     (0x01000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_5_emmc_d4_pu(data)                                     (0x00800000&((data)<<23))
#define  PINMUX_MAIN_EMMC_5_emmc_d5_pu(data)                                     (0x00400000&((data)<<22))
#define  PINMUX_MAIN_EMMC_5_emmc_d6_pu(data)                                     (0x00200000&((data)<<21))
#define  PINMUX_MAIN_EMMC_5_emmc_d7_pu(data)                                     (0x00100000&((data)<<20))
#define  PINMUX_MAIN_EMMC_5_emmc_clk_pd(data)                                    (0x00008000&((data)<<15))
#define  PINMUX_MAIN_EMMC_5_emmc_rst_n_pd(data)                                  (0x00004000&((data)<<14))
#define  PINMUX_MAIN_EMMC_5_emmc_ds_pd(data)                                     (0x00002000&((data)<<13))
#define  PINMUX_MAIN_EMMC_5_emmc_cmd_pd(data)                                    (0x00001000&((data)<<12))
#define  PINMUX_MAIN_EMMC_5_emmc_d0_pd(data)                                     (0x00000800&((data)<<11))
#define  PINMUX_MAIN_EMMC_5_emmc_d1_pd(data)                                     (0x00000400&((data)<<10))
#define  PINMUX_MAIN_EMMC_5_emmc_d2_pd(data)                                     (0x00000200&((data)<<9))
#define  PINMUX_MAIN_EMMC_5_emmc_d3_pd(data)                                     (0x00000100&((data)<<8))
#define  PINMUX_MAIN_EMMC_5_emmc_d4_pd(data)                                     (0x00000080&((data)<<7))
#define  PINMUX_MAIN_EMMC_5_emmc_d5_pd(data)                                     (0x00000040&((data)<<6))
#define  PINMUX_MAIN_EMMC_5_emmc_d6_pd(data)                                     (0x00000020&((data)<<5))
#define  PINMUX_MAIN_EMMC_5_emmc_d7_pd(data)                                     (0x00000010&((data)<<4))
#define  PINMUX_MAIN_EMMC_5_get_emmc_clk_pu(data)                                ((0x80000000&(data))>>31)
#define  PINMUX_MAIN_EMMC_5_get_emmc_rst_n_pu(data)                              ((0x40000000&(data))>>30)
#define  PINMUX_MAIN_EMMC_5_get_emmc_ds_pu(data)                                 ((0x20000000&(data))>>29)
#define  PINMUX_MAIN_EMMC_5_get_emmc_cmd_pu(data)                                ((0x10000000&(data))>>28)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d0_pu(data)                                 ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d1_pu(data)                                 ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d2_pu(data)                                 ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d3_pu(data)                                 ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d4_pu(data)                                 ((0x00800000&(data))>>23)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d5_pu(data)                                 ((0x00400000&(data))>>22)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d6_pu(data)                                 ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d7_pu(data)                                 ((0x00100000&(data))>>20)
#define  PINMUX_MAIN_EMMC_5_get_emmc_clk_pd(data)                                ((0x00008000&(data))>>15)
#define  PINMUX_MAIN_EMMC_5_get_emmc_rst_n_pd(data)                              ((0x00004000&(data))>>14)
#define  PINMUX_MAIN_EMMC_5_get_emmc_ds_pd(data)                                 ((0x00002000&(data))>>13)
#define  PINMUX_MAIN_EMMC_5_get_emmc_cmd_pd(data)                                ((0x00001000&(data))>>12)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d0_pd(data)                                 ((0x00000800&(data))>>11)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d1_pd(data)                                 ((0x00000400&(data))>>10)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d2_pd(data)                                 ((0x00000200&(data))>>9)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d3_pd(data)                                 ((0x00000100&(data))>>8)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d4_pd(data)                                 ((0x00000080&(data))>>7)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d5_pd(data)                                 ((0x00000040&(data))>>6)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d6_pd(data)                                 ((0x00000020&(data))>>5)
#define  PINMUX_MAIN_EMMC_5_get_emmc_d7_pd(data)                                 ((0x00000010&(data))>>4)

#define  PINMUX_MAIN_EMMC_6                                                      0x180008E8
#define  PINMUX_MAIN_EMMC_6_reg_addr                                             "0xB80008E8"
#define  PINMUX_MAIN_EMMC_6_reg                                                  0xB80008E8
#define  PINMUX_MAIN_EMMC_6_inst_addr                                            "0x0036"
#define  set_PINMUX_MAIN_EMMC_6_reg(data)                                        (*((volatile unsigned int*)PINMUX_MAIN_EMMC_6_reg)=data)
#define  get_PINMUX_MAIN_EMMC_6_reg                                              (*((volatile unsigned int*)PINMUX_MAIN_EMMC_6_reg))
#define  PINMUX_MAIN_EMMC_6_emmc_clk_sr_shift                                    (31)
#define  PINMUX_MAIN_EMMC_6_emmc_rst_n_sr_shift                                  (30)
#define  PINMUX_MAIN_EMMC_6_emmc_ds_sr_shift                                     (29)
#define  PINMUX_MAIN_EMMC_6_emmc_cmd_sr_shift                                    (28)
#define  PINMUX_MAIN_EMMC_6_emmc_d0_sr_shift                                     (27)
#define  PINMUX_MAIN_EMMC_6_emmc_d1_sr_shift                                     (26)
#define  PINMUX_MAIN_EMMC_6_emmc_d2_sr_shift                                     (25)
#define  PINMUX_MAIN_EMMC_6_emmc_d3_sr_shift                                     (24)
#define  PINMUX_MAIN_EMMC_6_emmc_d4_sr_shift                                     (23)
#define  PINMUX_MAIN_EMMC_6_emmc_d5_sr_shift                                     (22)
#define  PINMUX_MAIN_EMMC_6_emmc_d6_sr_shift                                     (21)
#define  PINMUX_MAIN_EMMC_6_emmc_d7_sr_shift                                     (20)
#define  PINMUX_MAIN_EMMC_6_emmc_clk_sr_mask                                     (0x80000000)
#define  PINMUX_MAIN_EMMC_6_emmc_rst_n_sr_mask                                   (0x40000000)
#define  PINMUX_MAIN_EMMC_6_emmc_ds_sr_mask                                      (0x20000000)
#define  PINMUX_MAIN_EMMC_6_emmc_cmd_sr_mask                                     (0x10000000)
#define  PINMUX_MAIN_EMMC_6_emmc_d0_sr_mask                                      (0x08000000)
#define  PINMUX_MAIN_EMMC_6_emmc_d1_sr_mask                                      (0x04000000)
#define  PINMUX_MAIN_EMMC_6_emmc_d2_sr_mask                                      (0x02000000)
#define  PINMUX_MAIN_EMMC_6_emmc_d3_sr_mask                                      (0x01000000)
#define  PINMUX_MAIN_EMMC_6_emmc_d4_sr_mask                                      (0x00800000)
#define  PINMUX_MAIN_EMMC_6_emmc_d5_sr_mask                                      (0x00400000)
#define  PINMUX_MAIN_EMMC_6_emmc_d6_sr_mask                                      (0x00200000)
#define  PINMUX_MAIN_EMMC_6_emmc_d7_sr_mask                                      (0x00100000)
#define  PINMUX_MAIN_EMMC_6_emmc_clk_sr(data)                                    (0x80000000&((data)<<31))
#define  PINMUX_MAIN_EMMC_6_emmc_rst_n_sr(data)                                  (0x40000000&((data)<<30))
#define  PINMUX_MAIN_EMMC_6_emmc_ds_sr(data)                                     (0x20000000&((data)<<29))
#define  PINMUX_MAIN_EMMC_6_emmc_cmd_sr(data)                                    (0x10000000&((data)<<28))
#define  PINMUX_MAIN_EMMC_6_emmc_d0_sr(data)                                     (0x08000000&((data)<<27))
#define  PINMUX_MAIN_EMMC_6_emmc_d1_sr(data)                                     (0x04000000&((data)<<26))
#define  PINMUX_MAIN_EMMC_6_emmc_d2_sr(data)                                     (0x02000000&((data)<<25))
#define  PINMUX_MAIN_EMMC_6_emmc_d3_sr(data)                                     (0x01000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_6_emmc_d4_sr(data)                                     (0x00800000&((data)<<23))
#define  PINMUX_MAIN_EMMC_6_emmc_d5_sr(data)                                     (0x00400000&((data)<<22))
#define  PINMUX_MAIN_EMMC_6_emmc_d6_sr(data)                                     (0x00200000&((data)<<21))
#define  PINMUX_MAIN_EMMC_6_emmc_d7_sr(data)                                     (0x00100000&((data)<<20))
#define  PINMUX_MAIN_EMMC_6_get_emmc_clk_sr(data)                                ((0x80000000&(data))>>31)
#define  PINMUX_MAIN_EMMC_6_get_emmc_rst_n_sr(data)                              ((0x40000000&(data))>>30)
#define  PINMUX_MAIN_EMMC_6_get_emmc_ds_sr(data)                                 ((0x20000000&(data))>>29)
#define  PINMUX_MAIN_EMMC_6_get_emmc_cmd_sr(data)                                ((0x10000000&(data))>>28)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d0_sr(data)                                 ((0x08000000&(data))>>27)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d1_sr(data)                                 ((0x04000000&(data))>>26)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d2_sr(data)                                 ((0x02000000&(data))>>25)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d3_sr(data)                                 ((0x01000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d4_sr(data)                                 ((0x00800000&(data))>>23)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d5_sr(data)                                 ((0x00400000&(data))>>22)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d6_sr(data)                                 ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_EMMC_6_get_emmc_d7_sr(data)                                 ((0x00100000&(data))>>20)

#define  PINMUX_MAIN_IR_Measure                                                  0x180008EC
#define  PINMUX_MAIN_IR_Measure_reg_addr                                         "0xB80008EC"
#define  PINMUX_MAIN_IR_Measure_reg                                              0xB80008EC
#define  PINMUX_MAIN_IR_Measure_inst_addr                                        "0x0037"
#define  set_PINMUX_MAIN_IR_Measure_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_IR_Measure_reg)=data)
#define  get_PINMUX_MAIN_IR_Measure_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_IR_Measure_reg))
#define  PINMUX_MAIN_IR_Measure_ir_ms_vcc_shift                                  (31)
#define  PINMUX_MAIN_IR_Measure_ir_ms_gnd_shift                                  (30)
#define  PINMUX_MAIN_IR_Measure_ir_ms_vcc_mask                                   (0x80000000)
#define  PINMUX_MAIN_IR_Measure_ir_ms_gnd_mask                                   (0x40000000)
#define  PINMUX_MAIN_IR_Measure_ir_ms_vcc(data)                                  (0x80000000&((data)<<31))
#define  PINMUX_MAIN_IR_Measure_ir_ms_gnd(data)                                  (0x40000000&((data)<<30))
#define  PINMUX_MAIN_IR_Measure_get_ir_ms_vcc(data)                              ((0x80000000&(data))>>31)
#define  PINMUX_MAIN_IR_Measure_get_ir_ms_gnd(data)                              ((0x40000000&(data))>>30)

#define  PINMUX_MAIN_Pin_Mux_IEV18_0                                             0x180008F0
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_reg_addr                                    "0xB80008F0"
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_reg                                         0xB80008F0
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_inst_addr                                   "0x0038"
#define  set_PINMUX_MAIN_Pin_Mux_IEV18_0_reg(data)                               (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_IEV18_0_reg)=data)
#define  get_PINMUX_MAIN_Pin_Mux_IEV18_0_reg                                     (*((volatile unsigned int*)PINMUX_MAIN_Pin_Mux_IEV18_0_reg))
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_gpio_93_ie_v18_shift                        (31)
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_gpio_93_ie_v18_mask                         (0x80000000)
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_gpio_93_ie_v18(data)                        (0x80000000&((data)<<31))
#define  PINMUX_MAIN_Pin_Mux_IEV18_0_get_gpio_93_ie_v18(data)                    ((0x80000000&(data))>>31)

#define  PINMUX_MAIN_EMMC_Dummy                                                  0x180008F4
#define  PINMUX_MAIN_EMMC_Dummy_reg_addr                                         "0xB80008F4"
#define  PINMUX_MAIN_EMMC_Dummy_reg                                              0xB80008F4
#define  PINMUX_MAIN_EMMC_Dummy_inst_addr                                        "0x0039"
#define  set_PINMUX_MAIN_EMMC_Dummy_reg(data)                                    (*((volatile unsigned int*)PINMUX_MAIN_EMMC_Dummy_reg)=data)
#define  get_PINMUX_MAIN_EMMC_Dummy_reg                                          (*((volatile unsigned int*)PINMUX_MAIN_EMMC_Dummy_reg))
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_ds_shift                                (24)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_pu_shift                                (23)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_pd_shift                                (22)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_sr_shift                                (21)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_smt_shift                               (20)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_ps_shift                                (16)
#define  PINMUX_MAIN_EMMC_Dummy_dummy_15_0_shift                                 (0)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_ds_mask                                 (0xFF000000)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_pu_mask                                 (0x00800000)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_pd_mask                                 (0x00400000)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_sr_mask                                 (0x00200000)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_smt_mask                                (0x00100000)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_ps_mask                                 (0x000F0000)
#define  PINMUX_MAIN_EMMC_Dummy_dummy_15_0_mask                                  (0x0000FFFF)
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_ds(data)                                (0xFF000000&((data)<<24))
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_pu(data)                                (0x00800000&((data)<<23))
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_pd(data)                                (0x00400000&((data)<<22))
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_sr(data)                                (0x00200000&((data)<<21))
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_smt(data)                               (0x00100000&((data)<<20))
#define  PINMUX_MAIN_EMMC_Dummy_emmc_dmy_ps(data)                                (0x000F0000&((data)<<16))
#define  PINMUX_MAIN_EMMC_Dummy_dummy_15_0(data)                                 (0x0000FFFF&(data))
#define  PINMUX_MAIN_EMMC_Dummy_get_emmc_dmy_ds(data)                            ((0xFF000000&(data))>>24)
#define  PINMUX_MAIN_EMMC_Dummy_get_emmc_dmy_pu(data)                            ((0x00800000&(data))>>23)
#define  PINMUX_MAIN_EMMC_Dummy_get_emmc_dmy_pd(data)                            ((0x00400000&(data))>>22)
#define  PINMUX_MAIN_EMMC_Dummy_get_emmc_dmy_sr(data)                            ((0x00200000&(data))>>21)
#define  PINMUX_MAIN_EMMC_Dummy_get_emmc_dmy_smt(data)                           ((0x00100000&(data))>>20)
#define  PINMUX_MAIN_EMMC_Dummy_get_emmc_dmy_ps(data)                            ((0x000F0000&(data))>>16)
#define  PINMUX_MAIN_EMMC_Dummy_get_dummy_15_0(data)                             (0x0000FFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PINMUX_MAIN register structure define==========

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
}gpio_cfg_0_RBUS;

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
}gpio_cfg_1_RBUS;

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
}gpio_cfg_2_RBUS;

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
}gpio_cfg_3_RBUS;

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
}gpio_cfg_4_RBUS;

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
}gpio_cfg_5_RBUS;

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
}gpio_cfg_6_RBUS;

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
}gpio_cfg_7_RBUS;

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
    };
}gpio_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
        RBus_UInt32  gpio_66_ps:4;
        RBus_UInt32  gpio_66_pu:1;
        RBus_UInt32  gpio_66_pd:1;
        RBus_UInt32  gpio_66_ds:1;
        RBus_UInt32  gpio_66_sr:1;
        RBus_UInt32  gpio_67_ps:4;
        RBus_UInt32  gpio_67_pu:1;
        RBus_UInt32  gpio_67_pd:1;
        RBus_UInt32  gpio_67_ds:1;
        RBus_UInt32  gpio_67_sr:1;
    };
}gpio_cfg_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
        RBus_UInt32  gpio_74_ps:4;
        RBus_UInt32  gpio_74_pu:1;
        RBus_UInt32  gpio_74_pd:1;
        RBus_UInt32  gpio_74_ds:1;
        RBus_UInt32  gpio_74_sr:1;
        RBus_UInt32  gpio_75_ps:4;
        RBus_UInt32  gpio_75_pu:1;
        RBus_UInt32  gpio_75_pd:1;
        RBus_UInt32  gpio_75_ds:1;
        RBus_UInt32  gpio_75_sr:1;
    };
}gpio_cfg_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_76_ps:4;
        RBus_UInt32  gpio_76_pu:1;
        RBus_UInt32  gpio_76_pd:1;
        RBus_UInt32  gpio_76_ds:1;
        RBus_UInt32  gpio_76_sr:1;
        RBus_UInt32  gpio_77_ps:4;
        RBus_UInt32  gpio_77_pu:1;
        RBus_UInt32  gpio_77_pd:1;
        RBus_UInt32  gpio_77_ds:1;
        RBus_UInt32  gpio_77_sr:1;
        RBus_UInt32  gpio_78_ps:4;
        RBus_UInt32  gpio_78_pu:1;
        RBus_UInt32  gpio_78_pd:1;
        RBus_UInt32  gpio_78_ds:1;
        RBus_UInt32  gpio_78_sr:1;
        RBus_UInt32  gpio_79_ps:4;
        RBus_UInt32  gpio_79_pu:1;
        RBus_UInt32  gpio_79_pd:1;
        RBus_UInt32  gpio_79_ds:1;
        RBus_UInt32  gpio_79_sr:1;
    };
}gpio_cfg_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_80_ps:4;
        RBus_UInt32  gpio_80_pu:1;
        RBus_UInt32  gpio_80_pd:1;
        RBus_UInt32  gpio_80_ds:1;
        RBus_UInt32  gpio_80_sr:1;
        RBus_UInt32  gpio_81_ps:4;
        RBus_UInt32  gpio_81_pu:1;
        RBus_UInt32  gpio_81_pd:1;
        RBus_UInt32  gpio_81_ds:1;
        RBus_UInt32  gpio_81_sr:1;
        RBus_UInt32  gpio_82_ps:4;
        RBus_UInt32  gpio_82_pu:1;
        RBus_UInt32  gpio_82_pd:1;
        RBus_UInt32  gpio_82_ds:1;
        RBus_UInt32  gpio_82_sr:1;
        RBus_UInt32  gpio_83_ps:4;
        RBus_UInt32  gpio_83_pu:1;
        RBus_UInt32  gpio_83_pd:1;
        RBus_UInt32  gpio_83_ds:1;
        RBus_UInt32  gpio_83_sr:1;
    };
}gpio_cfg_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_84_ps:4;
        RBus_UInt32  gpio_84_pu:1;
        RBus_UInt32  gpio_84_pd:1;
        RBus_UInt32  gpio_84_ds:1;
        RBus_UInt32  gpio_84_sr:1;
        RBus_UInt32  gpio_85_ps:4;
        RBus_UInt32  gpio_85_pu:1;
        RBus_UInt32  gpio_85_pd:1;
        RBus_UInt32  gpio_85_ds:1;
        RBus_UInt32  gpio_85_sr:1;
        RBus_UInt32  gpio_86_ps:4;
        RBus_UInt32  gpio_86_pu:1;
        RBus_UInt32  gpio_86_pd:1;
        RBus_UInt32  gpio_86_ds:1;
        RBus_UInt32  gpio_86_sr:1;
        RBus_UInt32  gpio_87_ps:4;
        RBus_UInt32  gpio_87_pu:1;
        RBus_UInt32  gpio_87_pd:1;
        RBus_UInt32  gpio_87_ds:1;
        RBus_UInt32  gpio_87_sr:1;
    };
}gpio_cfg_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_88_ps:4;
        RBus_UInt32  gpio_88_pu:1;
        RBus_UInt32  gpio_88_pd:1;
        RBus_UInt32  gpio_88_ds:1;
        RBus_UInt32  gpio_88_sr:1;
        RBus_UInt32  gpio_89_ps:4;
        RBus_UInt32  gpio_89_pu:1;
        RBus_UInt32  gpio_89_pd:1;
        RBus_UInt32  gpio_89_ds:1;
        RBus_UInt32  gpio_89_sr:1;
        RBus_UInt32  gpio_90_ps:4;
        RBus_UInt32  gpio_90_pu:1;
        RBus_UInt32  gpio_90_pd:1;
        RBus_UInt32  gpio_90_ds:1;
        RBus_UInt32  gpio_90_sr:1;
        RBus_UInt32  gpio_91_ps:4;
        RBus_UInt32  gpio_91_pu:1;
        RBus_UInt32  gpio_91_pd:1;
        RBus_UInt32  gpio_91_ds:1;
        RBus_UInt32  gpio_91_sr:1;
    };
}gpio_cfg_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_92_ps:4;
        RBus_UInt32  gpio_92_pu:1;
        RBus_UInt32  gpio_92_pd:1;
        RBus_UInt32  gpio_92_ds:1;
        RBus_UInt32  gpio_92_sr:1;
        RBus_UInt32  gpio_93_ps:4;
        RBus_UInt32  gpio_93_pu:1;
        RBus_UInt32  gpio_93_pd:1;
        RBus_UInt32  gpio_93_ds:1;
        RBus_UInt32  gpio_93_sr:1;
        RBus_UInt32  res1:16;
    };
}gpio_cfg_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_26_RBUS;

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
}apll_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_ai2l_ps:4;
        RBus_UInt32  bb_ai2r_ps:4;
        RBus_UInt32  res1:22;
        RBus_UInt32  bb_ai2l_gpi_en:1;
        RBus_UInt32  bb_ai2r_gpi_en:1;
    };
}bb_audio_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_ai3l_ps:4;
        RBus_UInt32  bb_ai3r_ps:4;
        RBus_UInt32  bb_ai4l_ps:4;
        RBus_UInt32  bb_ai4r_ps:4;
        RBus_UInt32  bb_aiol_ps:4;
        RBus_UInt32  bb_aior_ps:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  bb_ai3l_gpi_en:1;
        RBus_UInt32  bb_ai3r_gpi_en:1;
        RBus_UInt32  bb_ai4l_gpi_en:1;
        RBus_UInt32  bb_ai4r_gpi_en:1;
        RBus_UInt32  bb_aiol_gpi_en:1;
        RBus_UInt32  bb_aior_gpi_en:1;
    };
}bb_audio_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_hpol_ps:4;
        RBus_UInt32  bb_hpor_ps:4;
        RBus_UInt32  res1:22;
        RBus_UInt32  bb_hpol_gpi_en:1;
        RBus_UInt32  bb_hpor_gpi_en:1;
    };
}bb_audio_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_fp_ps:4;
        RBus_UInt32  lvds_a_fn_ps:4;
        RBus_UInt32  lvds_a_ep_ps:4;
        RBus_UInt32  lvds_a_en_ps:4;
        RBus_UInt32  lvds_a_dp_ps:4;
        RBus_UInt32  lvds_a_dn_ps:4;
        RBus_UInt32  lvds_a_cp_ps:4;
        RBus_UInt32  lvds_a_cn_ps:4;
    };
}lvds_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_bp_ps:4;
        RBus_UInt32  lvds_a_bn_ps:4;
        RBus_UInt32  lvds_a_ap_ps:4;
        RBus_UInt32  lvds_a_an_ps:4;
        RBus_UInt32  lvds_b_fp_ps:4;
        RBus_UInt32  lvds_b_fn_ps:4;
        RBus_UInt32  lvds_b_ep_ps:4;
        RBus_UInt32  lvds_b_en_ps:4;
    };
}lvds_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_dp_ps:4;
        RBus_UInt32  lvds_b_dn_ps:4;
        RBus_UInt32  lvds_b_cp_ps:4;
        RBus_UInt32  lvds_b_cn_ps:4;
        RBus_UInt32  lvds_b_bp_ps:4;
        RBus_UInt32  lvds_b_bn_ps:4;
        RBus_UInt32  lvds_b_ap_ps:4;
        RBus_UInt32  lvds_b_an_ps:4;
    };
}lvds_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_fp_ps:4;
        RBus_UInt32  lvds_c_fn_ps:4;
        RBus_UInt32  lvds_c_ep_ps:4;
        RBus_UInt32  lvds_c_en_ps:4;
        RBus_UInt32  lvds_c_dp_ps:4;
        RBus_UInt32  lvds_c_dn_ps:4;
        RBus_UInt32  lvds_c_cp_ps:4;
        RBus_UInt32  lvds_c_cn_ps:4;
    };
}lvds_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_bp_ps:4;
        RBus_UInt32  lvds_c_bn_ps:4;
        RBus_UInt32  lvds_c_ap_ps:4;
        RBus_UInt32  lvds_c_an_ps:4;
        RBus_UInt32  lvds_d_fp_ps:4;
        RBus_UInt32  lvds_d_fn_ps:4;
        RBus_UInt32  lvds_d_ep_ps:4;
        RBus_UInt32  lvds_d_en_ps:4;
    };
}lvds_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_dp_ps:4;
        RBus_UInt32  lvds_d_dn_ps:4;
        RBus_UInt32  lvds_d_cp_ps:4;
        RBus_UInt32  lvds_d_cn_ps:4;
        RBus_UInt32  lvds_d_bp_ps:4;
        RBus_UInt32  lvds_d_bn_ps:4;
        RBus_UInt32  lvds_d_ap_ps:4;
        RBus_UInt32  lvds_d_an_ps:4;
    };
}lvds_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scart_fsw_0_ps:4;
        RBus_UInt32  vin_13p_ps:4;
        RBus_UInt32  vin_10p_ps:4;
        RBus_UInt32  vin_a2n_ps:4;
        RBus_UInt32  vin_a0n_ps:4;
        RBus_UInt32  vin_12p_ps:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  scart_fsw_0_gpi_en:1;
        RBus_UInt32  vin_13p_gpi_en:1;
        RBus_UInt32  vin_10p_gpi_en:1;
        RBus_UInt32  vin_a2n_gpi_en:1;
        RBus_UInt32  vin_a0n_gpi_en:1;
        RBus_UInt32  vin_12p_gpi_en:1;
    };
}vd_adc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_9p_ps:4;
        RBus_UInt32  res1:27;
        RBus_UInt32  vin_9p_gpi_en:1;
    };
}vd_adc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdbs_out_ps:4;
        RBus_UInt32  vdac_out_ps:4;
        RBus_UInt32  res1:22;
        RBus_UInt32  vdbs_out_gpi_en:1;
        RBus_UInt32  vdac_out_gpi_en:1;
    };
}vd_dac_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_0p_ps:4;
        RBus_UInt32  vin_bn_ps:4;
        RBus_UInt32  vin_1p_ps:4;
        RBus_UInt32  vin_2p_ps:4;
        RBus_UInt32  vin_6p_ps:4;
        RBus_UInt32  vin_y1n_ps:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  vin_0p_gpi_en:1;
        RBus_UInt32  vin_bn_gpi_en:1;
        RBus_UInt32  vin_1p_gpi_en:1;
        RBus_UInt32  vin_2p_gpi_en:1;
        RBus_UInt32  vin_6p_gpi_en:1;
        RBus_UInt32  vin_y1n_gpi_en:1;
    };
}ypbpr_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_7p_ps:4;
        RBus_UInt32  vin_8p_ps:4;
        RBus_UInt32  res1:22;
        RBus_UInt32  vin_7p_gpi_en:1;
        RBus_UInt32  vin_8p_gpi_en:1;
    };
}ypbpr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cr_sd_in_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  demod_i2c_relay_in_sel:2;
        RBus_UInt32  res3:8;
        RBus_UInt32  i2c3_in_sel:3;
        RBus_UInt32  res4:8;
    };
}pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sc0_in_sel:2;
        RBus_UInt32  res2:7;
        RBus_UInt32  sc1_in_sel:2;
        RBus_UInt32  res3:11;
        RBus_UInt32  vby1_sel:4;
        RBus_UInt32  res4:4;
    };
}pin_mux_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_spi0_p2_sck_sel:3;
        RBus_UInt32  ld_spi0_p3_sdo_sel:3;
        RBus_UInt32  ld_spi0_p4_sdi_sel:3;
        RBus_UInt32  ld_spi1_p2_sck_sel:3;
        RBus_UInt32  ld_spi1_p3_sdo_sel:3;
        RBus_UInt32  ld_spi1_p4_sdi_sel:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  antoe_in_sel:2;
        RBus_UInt32  antrx_in_sel:2;
        RBus_UInt32  anttx_in_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  phif_enable:1;
    };
}pin_mux_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  testpin_mux:8;
        RBus_UInt32  main_ext_clk_en:16;
        RBus_UInt32  pcmcia_dat_swap_sel:1;
        RBus_UInt32  res2:5;
    };
}pin_mux_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tp3_mux_selection:3;
        RBus_UInt32  tp2_mux_selection:3;
        RBus_UInt32  tp1_mux_selection:3;
        RBus_UInt32  tp0_mux_selection:3;
        RBus_UInt32  tp0_clk_sel:3;
        RBus_UInt32  tp1_clk_sel:3;
        RBus_UInt32  tp2_clk_sel:3;
        RBus_UInt32  tp3_clk_sel:3;
        RBus_UInt32  dtv_i2c_sel:1;
        RBus_UInt32  usb_pwr_flag0_in_sel:2;
        RBus_UInt32  usb3_pwr_flag0_in_sel:2;
        RBus_UInt32  res1:3;
    };
}pin_mux_tpsel_RBUS;

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
}schmidt_trigger_0_RBUS;

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
        RBus_UInt32  gpio_60_smt:1;
        RBus_UInt32  gpio_61_smt:1;
        RBus_UInt32  gpio_62_smt:1;
        RBus_UInt32  gpio_63_smt:1;
    };
}schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
        RBus_UInt32  gpio_76_smt:1;
        RBus_UInt32  gpio_77_smt:1;
        RBus_UInt32  gpio_78_smt:1;
        RBus_UInt32  gpio_79_smt:1;
        RBus_UInt32  gpio_80_smt:1;
        RBus_UInt32  gpio_81_smt:1;
        RBus_UInt32  gpio_82_smt:1;
        RBus_UInt32  gpio_83_smt:1;
        RBus_UInt32  gpio_84_smt:1;
        RBus_UInt32  gpio_85_smt:1;
        RBus_UInt32  gpio_86_smt:1;
        RBus_UInt32  gpio_87_smt:1;
        RBus_UInt32  gpio_88_smt:1;
        RBus_UInt32  gpio_89_smt:1;
        RBus_UInt32  gpio_90_smt:1;
        RBus_UInt32  gpio_91_smt:1;
        RBus_UInt32  gpio_92_smt:1;
        RBus_UInt32  gpio_93_smt:1;
        RBus_UInt32  res1:2;
    };
}schmidt_trigger_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  emmc_clk_smt:1;
        RBus_UInt32  emmc_rst_n_smt:1;
        RBus_UInt32  emmc_ds_smt:1;
        RBus_UInt32  emmc_cmd_smt:1;
        RBus_UInt32  emmc_d0_smt:1;
        RBus_UInt32  emmc_d1_smt:1;
        RBus_UInt32  emmc_d2_smt:1;
        RBus_UInt32  emmc_d3_smt:1;
        RBus_UInt32  emmc_d4_smt:1;
        RBus_UInt32  emmc_d5_smt:1;
        RBus_UInt32  emmc_d6_smt:1;
        RBus_UInt32  emmc_d7_smt:1;
        RBus_UInt32  res2:10;
    };
}schmidt_trigger_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_clk_ps:4;
        RBus_UInt32  emmc_rst_n_ps:4;
        RBus_UInt32  emmc_ds_ps:4;
        RBus_UInt32  emmc_cmd_ps:4;
        RBus_UInt32  res1:16;
    };
}emmc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_d0_ps:4;
        RBus_UInt32  emmc_d1_ps:4;
        RBus_UInt32  emmc_d2_ps:4;
        RBus_UInt32  emmc_d3_ps:4;
        RBus_UInt32  emmc_d4_ps:4;
        RBus_UInt32  emmc_d5_ps:4;
        RBus_UInt32  emmc_d6_ps:4;
        RBus_UInt32  emmc_d7_ps:4;
    };
}emmc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_clk_ds:8;
        RBus_UInt32  emmc_rst_n_ds:8;
        RBus_UInt32  emmc_ds_ds:8;
        RBus_UInt32  emmc_cmd_ds:8;
    };
}emmc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_d0_ds:8;
        RBus_UInt32  emmc_d1_ds:8;
        RBus_UInt32  emmc_d2_ds:8;
        RBus_UInt32  emmc_d3_ds:8;
    };
}emmc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_d4_ds:8;
        RBus_UInt32  emmc_d5_ds:8;
        RBus_UInt32  emmc_d6_ds:8;
        RBus_UInt32  emmc_d7_ds:8;
    };
}emmc_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_clk_pu:1;
        RBus_UInt32  emmc_rst_n_pu:1;
        RBus_UInt32  emmc_ds_pu:1;
        RBus_UInt32  emmc_cmd_pu:1;
        RBus_UInt32  emmc_d0_pu:1;
        RBus_UInt32  emmc_d1_pu:1;
        RBus_UInt32  emmc_d2_pu:1;
        RBus_UInt32  emmc_d3_pu:1;
        RBus_UInt32  emmc_d4_pu:1;
        RBus_UInt32  emmc_d5_pu:1;
        RBus_UInt32  emmc_d6_pu:1;
        RBus_UInt32  emmc_d7_pu:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  emmc_clk_pd:1;
        RBus_UInt32  emmc_rst_n_pd:1;
        RBus_UInt32  emmc_ds_pd:1;
        RBus_UInt32  emmc_cmd_pd:1;
        RBus_UInt32  emmc_d0_pd:1;
        RBus_UInt32  emmc_d1_pd:1;
        RBus_UInt32  emmc_d2_pd:1;
        RBus_UInt32  emmc_d3_pd:1;
        RBus_UInt32  emmc_d4_pd:1;
        RBus_UInt32  emmc_d5_pd:1;
        RBus_UInt32  emmc_d6_pd:1;
        RBus_UInt32  emmc_d7_pd:1;
        RBus_UInt32  res2:4;
    };
}emmc_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_clk_sr:1;
        RBus_UInt32  emmc_rst_n_sr:1;
        RBus_UInt32  emmc_ds_sr:1;
        RBus_UInt32  emmc_cmd_sr:1;
        RBus_UInt32  emmc_d0_sr:1;
        RBus_UInt32  emmc_d1_sr:1;
        RBus_UInt32  emmc_d2_sr:1;
        RBus_UInt32  emmc_d3_sr:1;
        RBus_UInt32  emmc_d4_sr:1;
        RBus_UInt32  emmc_d5_sr:1;
        RBus_UInt32  emmc_d6_sr:1;
        RBus_UInt32  emmc_d7_sr:1;
        RBus_UInt32  res1:20;
    };
}emmc_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ir_ms_vcc:1;
        RBus_UInt32  ir_ms_gnd:1;
        RBus_UInt32  res1:30;
    };
}ir_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_93_ie_v18:1;
        RBus_UInt32  res1:31;
    };
}pin_mux_iev18_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_dmy_ds:8;
        RBus_UInt32  emmc_dmy_pu:1;
        RBus_UInt32  emmc_dmy_pd:1;
        RBus_UInt32  emmc_dmy_sr:1;
        RBus_UInt32  emmc_dmy_smt:1;
        RBus_UInt32  emmc_dmy_ps:4;
        RBus_UInt32  dummy180008f4_15_0:16;
    };
}emmc_dummy_RBUS;

#else //apply LITTLE_ENDIAN

//======PINMUX_MAIN register structure define==========

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
}gpio_cfg_0_RBUS;

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
}gpio_cfg_1_RBUS;

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
}gpio_cfg_2_RBUS;

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
}gpio_cfg_3_RBUS;

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
}gpio_cfg_4_RBUS;

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
}gpio_cfg_5_RBUS;

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
}gpio_cfg_6_RBUS;

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
}gpio_cfg_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
}gpio_cfg_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_67_sr:1;
        RBus_UInt32  gpio_67_ds:1;
        RBus_UInt32  gpio_67_pd:1;
        RBus_UInt32  gpio_67_pu:1;
        RBus_UInt32  gpio_67_ps:4;
        RBus_UInt32  gpio_66_sr:1;
        RBus_UInt32  gpio_66_ds:1;
        RBus_UInt32  gpio_66_pd:1;
        RBus_UInt32  gpio_66_pu:1;
        RBus_UInt32  gpio_66_ps:4;
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
    };
}gpio_cfg_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
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
    };
}gpio_cfg_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_75_sr:1;
        RBus_UInt32  gpio_75_ds:1;
        RBus_UInt32  gpio_75_pd:1;
        RBus_UInt32  gpio_75_pu:1;
        RBus_UInt32  gpio_75_ps:4;
        RBus_UInt32  gpio_74_sr:1;
        RBus_UInt32  gpio_74_ds:1;
        RBus_UInt32  gpio_74_pd:1;
        RBus_UInt32  gpio_74_pu:1;
        RBus_UInt32  gpio_74_ps:4;
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
    };
}gpio_cfg_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_79_sr:1;
        RBus_UInt32  gpio_79_ds:1;
        RBus_UInt32  gpio_79_pd:1;
        RBus_UInt32  gpio_79_pu:1;
        RBus_UInt32  gpio_79_ps:4;
        RBus_UInt32  gpio_78_sr:1;
        RBus_UInt32  gpio_78_ds:1;
        RBus_UInt32  gpio_78_pd:1;
        RBus_UInt32  gpio_78_pu:1;
        RBus_UInt32  gpio_78_ps:4;
        RBus_UInt32  gpio_77_sr:1;
        RBus_UInt32  gpio_77_ds:1;
        RBus_UInt32  gpio_77_pd:1;
        RBus_UInt32  gpio_77_pu:1;
        RBus_UInt32  gpio_77_ps:4;
        RBus_UInt32  gpio_76_sr:1;
        RBus_UInt32  gpio_76_ds:1;
        RBus_UInt32  gpio_76_pd:1;
        RBus_UInt32  gpio_76_pu:1;
        RBus_UInt32  gpio_76_ps:4;
    };
}gpio_cfg_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_83_sr:1;
        RBus_UInt32  gpio_83_ds:1;
        RBus_UInt32  gpio_83_pd:1;
        RBus_UInt32  gpio_83_pu:1;
        RBus_UInt32  gpio_83_ps:4;
        RBus_UInt32  gpio_82_sr:1;
        RBus_UInt32  gpio_82_ds:1;
        RBus_UInt32  gpio_82_pd:1;
        RBus_UInt32  gpio_82_pu:1;
        RBus_UInt32  gpio_82_ps:4;
        RBus_UInt32  gpio_81_sr:1;
        RBus_UInt32  gpio_81_ds:1;
        RBus_UInt32  gpio_81_pd:1;
        RBus_UInt32  gpio_81_pu:1;
        RBus_UInt32  gpio_81_ps:4;
        RBus_UInt32  gpio_80_sr:1;
        RBus_UInt32  gpio_80_ds:1;
        RBus_UInt32  gpio_80_pd:1;
        RBus_UInt32  gpio_80_pu:1;
        RBus_UInt32  gpio_80_ps:4;
    };
}gpio_cfg_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_87_sr:1;
        RBus_UInt32  gpio_87_ds:1;
        RBus_UInt32  gpio_87_pd:1;
        RBus_UInt32  gpio_87_pu:1;
        RBus_UInt32  gpio_87_ps:4;
        RBus_UInt32  gpio_86_sr:1;
        RBus_UInt32  gpio_86_ds:1;
        RBus_UInt32  gpio_86_pd:1;
        RBus_UInt32  gpio_86_pu:1;
        RBus_UInt32  gpio_86_ps:4;
        RBus_UInt32  gpio_85_sr:1;
        RBus_UInt32  gpio_85_ds:1;
        RBus_UInt32  gpio_85_pd:1;
        RBus_UInt32  gpio_85_pu:1;
        RBus_UInt32  gpio_85_ps:4;
        RBus_UInt32  gpio_84_sr:1;
        RBus_UInt32  gpio_84_ds:1;
        RBus_UInt32  gpio_84_pd:1;
        RBus_UInt32  gpio_84_pu:1;
        RBus_UInt32  gpio_84_ps:4;
    };
}gpio_cfg_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_91_sr:1;
        RBus_UInt32  gpio_91_ds:1;
        RBus_UInt32  gpio_91_pd:1;
        RBus_UInt32  gpio_91_pu:1;
        RBus_UInt32  gpio_91_ps:4;
        RBus_UInt32  gpio_90_sr:1;
        RBus_UInt32  gpio_90_ds:1;
        RBus_UInt32  gpio_90_pd:1;
        RBus_UInt32  gpio_90_pu:1;
        RBus_UInt32  gpio_90_ps:4;
        RBus_UInt32  gpio_89_sr:1;
        RBus_UInt32  gpio_89_ds:1;
        RBus_UInt32  gpio_89_pd:1;
        RBus_UInt32  gpio_89_pu:1;
        RBus_UInt32  gpio_89_ps:4;
        RBus_UInt32  gpio_88_sr:1;
        RBus_UInt32  gpio_88_ds:1;
        RBus_UInt32  gpio_88_pd:1;
        RBus_UInt32  gpio_88_pu:1;
        RBus_UInt32  gpio_88_ps:4;
    };
}gpio_cfg_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gpio_93_sr:1;
        RBus_UInt32  gpio_93_ds:1;
        RBus_UInt32  gpio_93_pd:1;
        RBus_UInt32  gpio_93_pu:1;
        RBus_UInt32  gpio_93_ps:4;
        RBus_UInt32  gpio_92_sr:1;
        RBus_UInt32  gpio_92_ds:1;
        RBus_UInt32  gpio_92_pd:1;
        RBus_UInt32  gpio_92_pu:1;
        RBus_UInt32  gpio_92_ps:4;
    };
}gpio_cfg_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}gpio_cfg_26_RBUS;

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
}apll_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_ai2r_gpi_en:1;
        RBus_UInt32  bb_ai2l_gpi_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  bb_ai2r_ps:4;
        RBus_UInt32  bb_ai2l_ps:4;
    };
}bb_audio_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_aior_gpi_en:1;
        RBus_UInt32  bb_aiol_gpi_en:1;
        RBus_UInt32  bb_ai4r_gpi_en:1;
        RBus_UInt32  bb_ai4l_gpi_en:1;
        RBus_UInt32  bb_ai3r_gpi_en:1;
        RBus_UInt32  bb_ai3l_gpi_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  bb_aior_ps:4;
        RBus_UInt32  bb_aiol_ps:4;
        RBus_UInt32  bb_ai4r_ps:4;
        RBus_UInt32  bb_ai4l_ps:4;
        RBus_UInt32  bb_ai3r_ps:4;
        RBus_UInt32  bb_ai3l_ps:4;
    };
}bb_audio_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_hpor_gpi_en:1;
        RBus_UInt32  bb_hpol_gpi_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  bb_hpor_ps:4;
        RBus_UInt32  bb_hpol_ps:4;
    };
}bb_audio_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_a_cn_ps:4;
        RBus_UInt32  lvds_a_cp_ps:4;
        RBus_UInt32  lvds_a_dn_ps:4;
        RBus_UInt32  lvds_a_dp_ps:4;
        RBus_UInt32  lvds_a_en_ps:4;
        RBus_UInt32  lvds_a_ep_ps:4;
        RBus_UInt32  lvds_a_fn_ps:4;
        RBus_UInt32  lvds_a_fp_ps:4;
    };
}lvds_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_en_ps:4;
        RBus_UInt32  lvds_b_ep_ps:4;
        RBus_UInt32  lvds_b_fn_ps:4;
        RBus_UInt32  lvds_b_fp_ps:4;
        RBus_UInt32  lvds_a_an_ps:4;
        RBus_UInt32  lvds_a_ap_ps:4;
        RBus_UInt32  lvds_a_bn_ps:4;
        RBus_UInt32  lvds_a_bp_ps:4;
    };
}lvds_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_b_an_ps:4;
        RBus_UInt32  lvds_b_ap_ps:4;
        RBus_UInt32  lvds_b_bn_ps:4;
        RBus_UInt32  lvds_b_bp_ps:4;
        RBus_UInt32  lvds_b_cn_ps:4;
        RBus_UInt32  lvds_b_cp_ps:4;
        RBus_UInt32  lvds_b_dn_ps:4;
        RBus_UInt32  lvds_b_dp_ps:4;
    };
}lvds_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_c_cn_ps:4;
        RBus_UInt32  lvds_c_cp_ps:4;
        RBus_UInt32  lvds_c_dn_ps:4;
        RBus_UInt32  lvds_c_dp_ps:4;
        RBus_UInt32  lvds_c_en_ps:4;
        RBus_UInt32  lvds_c_ep_ps:4;
        RBus_UInt32  lvds_c_fn_ps:4;
        RBus_UInt32  lvds_c_fp_ps:4;
    };
}lvds_1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_en_ps:4;
        RBus_UInt32  lvds_d_ep_ps:4;
        RBus_UInt32  lvds_d_fn_ps:4;
        RBus_UInt32  lvds_d_fp_ps:4;
        RBus_UInt32  lvds_c_an_ps:4;
        RBus_UInt32  lvds_c_ap_ps:4;
        RBus_UInt32  lvds_c_bn_ps:4;
        RBus_UInt32  lvds_c_bp_ps:4;
    };
}lvds_1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lvds_d_an_ps:4;
        RBus_UInt32  lvds_d_ap_ps:4;
        RBus_UInt32  lvds_d_bn_ps:4;
        RBus_UInt32  lvds_d_bp_ps:4;
        RBus_UInt32  lvds_d_cn_ps:4;
        RBus_UInt32  lvds_d_cp_ps:4;
        RBus_UInt32  lvds_d_dn_ps:4;
        RBus_UInt32  lvds_d_dp_ps:4;
    };
}lvds_1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_12p_gpi_en:1;
        RBus_UInt32  vin_a0n_gpi_en:1;
        RBus_UInt32  vin_a2n_gpi_en:1;
        RBus_UInt32  vin_10p_gpi_en:1;
        RBus_UInt32  vin_13p_gpi_en:1;
        RBus_UInt32  scart_fsw_0_gpi_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vin_12p_ps:4;
        RBus_UInt32  vin_a0n_ps:4;
        RBus_UInt32  vin_a2n_ps:4;
        RBus_UInt32  vin_10p_ps:4;
        RBus_UInt32  vin_13p_ps:4;
        RBus_UInt32  scart_fsw_0_ps:4;
    };
}vd_adc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_9p_gpi_en:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  vin_9p_ps:4;
    };
}vd_adc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdac_out_gpi_en:1;
        RBus_UInt32  vdbs_out_gpi_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  vdac_out_ps:4;
        RBus_UInt32  vdbs_out_ps:4;
    };
}vd_dac_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_y1n_gpi_en:1;
        RBus_UInt32  vin_6p_gpi_en:1;
        RBus_UInt32  vin_2p_gpi_en:1;
        RBus_UInt32  vin_1p_gpi_en:1;
        RBus_UInt32  vin_bn_gpi_en:1;
        RBus_UInt32  vin_0p_gpi_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  vin_y1n_ps:4;
        RBus_UInt32  vin_6p_ps:4;
        RBus_UInt32  vin_2p_ps:4;
        RBus_UInt32  vin_1p_ps:4;
        RBus_UInt32  vin_bn_ps:4;
        RBus_UInt32  vin_0p_ps:4;
    };
}ypbpr_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vin_8p_gpi_en:1;
        RBus_UInt32  vin_7p_gpi_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  vin_8p_ps:4;
        RBus_UInt32  vin_7p_ps:4;
    };
}ypbpr_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  i2c3_in_sel:3;
        RBus_UInt32  res2:8;
        RBus_UInt32  demod_i2c_relay_in_sel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  cr_sd_in_sel:2;
        RBus_UInt32  res4:7;
    };
}pin_mux_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vby1_sel:4;
        RBus_UInt32  res2:11;
        RBus_UInt32  sc1_in_sel:2;
        RBus_UInt32  res3:7;
        RBus_UInt32  sc0_in_sel:2;
        RBus_UInt32  res4:2;
    };
}pin_mux_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phif_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  anttx_in_sel:2;
        RBus_UInt32  antrx_in_sel:2;
        RBus_UInt32  antoe_in_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_spi1_p4_sdi_sel:3;
        RBus_UInt32  ld_spi1_p3_sdo_sel:3;
        RBus_UInt32  ld_spi1_p2_sck_sel:3;
        RBus_UInt32  ld_spi0_p4_sdi_sel:3;
        RBus_UInt32  ld_spi0_p3_sdo_sel:3;
        RBus_UInt32  ld_spi0_p2_sck_sel:3;
        RBus_UInt32  res3:4;
    };
}pin_mux_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pcmcia_dat_swap_sel:1;
        RBus_UInt32  main_ext_clk_en:16;
        RBus_UInt32  testpin_mux:8;
        RBus_UInt32  res2:2;
    };
}pin_mux_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  usb3_pwr_flag0_in_sel:2;
        RBus_UInt32  usb_pwr_flag0_in_sel:2;
        RBus_UInt32  dtv_i2c_sel:1;
        RBus_UInt32  tp3_clk_sel:3;
        RBus_UInt32  tp2_clk_sel:3;
        RBus_UInt32  tp1_clk_sel:3;
        RBus_UInt32  tp0_clk_sel:3;
        RBus_UInt32  tp0_mux_selection:3;
        RBus_UInt32  tp1_mux_selection:3;
        RBus_UInt32  tp2_mux_selection:3;
        RBus_UInt32  tp3_mux_selection:3;
    };
}pin_mux_tpsel_RBUS;

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
}schmidt_trigger_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpio_63_smt:1;
        RBus_UInt32  gpio_62_smt:1;
        RBus_UInt32  gpio_61_smt:1;
        RBus_UInt32  gpio_60_smt:1;
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
}schmidt_trigger_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  gpio_93_smt:1;
        RBus_UInt32  gpio_92_smt:1;
        RBus_UInt32  gpio_91_smt:1;
        RBus_UInt32  gpio_90_smt:1;
        RBus_UInt32  gpio_89_smt:1;
        RBus_UInt32  gpio_88_smt:1;
        RBus_UInt32  gpio_87_smt:1;
        RBus_UInt32  gpio_86_smt:1;
        RBus_UInt32  gpio_85_smt:1;
        RBus_UInt32  gpio_84_smt:1;
        RBus_UInt32  gpio_83_smt:1;
        RBus_UInt32  gpio_82_smt:1;
        RBus_UInt32  gpio_81_smt:1;
        RBus_UInt32  gpio_80_smt:1;
        RBus_UInt32  gpio_79_smt:1;
        RBus_UInt32  gpio_78_smt:1;
        RBus_UInt32  gpio_77_smt:1;
        RBus_UInt32  gpio_76_smt:1;
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
    };
}schmidt_trigger_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  emmc_d7_smt:1;
        RBus_UInt32  emmc_d6_smt:1;
        RBus_UInt32  emmc_d5_smt:1;
        RBus_UInt32  emmc_d4_smt:1;
        RBus_UInt32  emmc_d3_smt:1;
        RBus_UInt32  emmc_d2_smt:1;
        RBus_UInt32  emmc_d1_smt:1;
        RBus_UInt32  emmc_d0_smt:1;
        RBus_UInt32  emmc_cmd_smt:1;
        RBus_UInt32  emmc_ds_smt:1;
        RBus_UInt32  emmc_rst_n_smt:1;
        RBus_UInt32  emmc_clk_smt:1;
        RBus_UInt32  res2:10;
    };
}schmidt_trigger_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  emmc_cmd_ps:4;
        RBus_UInt32  emmc_ds_ps:4;
        RBus_UInt32  emmc_rst_n_ps:4;
        RBus_UInt32  emmc_clk_ps:4;
    };
}emmc_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_d7_ps:4;
        RBus_UInt32  emmc_d6_ps:4;
        RBus_UInt32  emmc_d5_ps:4;
        RBus_UInt32  emmc_d4_ps:4;
        RBus_UInt32  emmc_d3_ps:4;
        RBus_UInt32  emmc_d2_ps:4;
        RBus_UInt32  emmc_d1_ps:4;
        RBus_UInt32  emmc_d0_ps:4;
    };
}emmc_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_cmd_ds:8;
        RBus_UInt32  emmc_ds_ds:8;
        RBus_UInt32  emmc_rst_n_ds:8;
        RBus_UInt32  emmc_clk_ds:8;
    };
}emmc_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_d3_ds:8;
        RBus_UInt32  emmc_d2_ds:8;
        RBus_UInt32  emmc_d1_ds:8;
        RBus_UInt32  emmc_d0_ds:8;
    };
}emmc_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emmc_d7_ds:8;
        RBus_UInt32  emmc_d6_ds:8;
        RBus_UInt32  emmc_d5_ds:8;
        RBus_UInt32  emmc_d4_ds:8;
    };
}emmc_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  emmc_d7_pd:1;
        RBus_UInt32  emmc_d6_pd:1;
        RBus_UInt32  emmc_d5_pd:1;
        RBus_UInt32  emmc_d4_pd:1;
        RBus_UInt32  emmc_d3_pd:1;
        RBus_UInt32  emmc_d2_pd:1;
        RBus_UInt32  emmc_d1_pd:1;
        RBus_UInt32  emmc_d0_pd:1;
        RBus_UInt32  emmc_cmd_pd:1;
        RBus_UInt32  emmc_ds_pd:1;
        RBus_UInt32  emmc_rst_n_pd:1;
        RBus_UInt32  emmc_clk_pd:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  emmc_d7_pu:1;
        RBus_UInt32  emmc_d6_pu:1;
        RBus_UInt32  emmc_d5_pu:1;
        RBus_UInt32  emmc_d4_pu:1;
        RBus_UInt32  emmc_d3_pu:1;
        RBus_UInt32  emmc_d2_pu:1;
        RBus_UInt32  emmc_d1_pu:1;
        RBus_UInt32  emmc_d0_pu:1;
        RBus_UInt32  emmc_cmd_pu:1;
        RBus_UInt32  emmc_ds_pu:1;
        RBus_UInt32  emmc_rst_n_pu:1;
        RBus_UInt32  emmc_clk_pu:1;
    };
}emmc_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  emmc_d7_sr:1;
        RBus_UInt32  emmc_d6_sr:1;
        RBus_UInt32  emmc_d5_sr:1;
        RBus_UInt32  emmc_d4_sr:1;
        RBus_UInt32  emmc_d3_sr:1;
        RBus_UInt32  emmc_d2_sr:1;
        RBus_UInt32  emmc_d1_sr:1;
        RBus_UInt32  emmc_d0_sr:1;
        RBus_UInt32  emmc_cmd_sr:1;
        RBus_UInt32  emmc_ds_sr:1;
        RBus_UInt32  emmc_rst_n_sr:1;
        RBus_UInt32  emmc_clk_sr:1;
    };
}emmc_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ir_ms_gnd:1;
        RBus_UInt32  ir_ms_vcc:1;
    };
}ir_measure_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  gpio_93_ie_v18:1;
    };
}pin_mux_iev18_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180008f4_15_0:16;
        RBus_UInt32  emmc_dmy_ps:4;
        RBus_UInt32  emmc_dmy_smt:1;
        RBus_UInt32  emmc_dmy_sr:1;
        RBus_UInt32  emmc_dmy_pd:1;
        RBus_UInt32  emmc_dmy_pu:1;
        RBus_UInt32  emmc_dmy_ds:8;
    };
}emmc_dummy_RBUS;




#endif 


#endif 
