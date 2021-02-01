/**
* @file rbusGPIOReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_GPIO_REG_H_
#define _RBUS_GPIO_REG_H_

#include "rbus_types.h"



//  GPIO Register Address
#define  GPIO_GPDIR                                                              0x18061100
#define  GPIO_GPDIR_reg_addr                                                     "0xB8061100"
#define  GPIO_GPDIR_reg                                                          0xB8061100
#define  GPIO_GPDIR_inst_addr                                                    "0x0000"
#define  set_GPIO_GPDIR_reg(data)                                                (*((volatile unsigned int*)GPIO_GPDIR_reg)=data)
#define  get_GPIO_GPDIR_reg                                                      (*((volatile unsigned int*)GPIO_GPDIR_reg))
#define  GPIO_GPDIR_gpdir_shift                                                  (0)
#define  GPIO_GPDIR_gpdir_mask                                                   (0xFFFFFFFF)
#define  GPIO_GPDIR_gpdir(data)                                                  (0xFFFFFFFF&(data))
#define  GPIO_GPDIR_get_gpdir(data)                                              (0xFFFFFFFF&(data))

#define  GPIO_GPDIR_1                                                            0x18061104
#define  GPIO_GPDIR_1_reg_addr                                                   "0xB8061104"
#define  GPIO_GPDIR_1_reg                                                        0xB8061104
#define  GPIO_GPDIR_1_inst_addr                                                  "0x0001"
#define  set_GPIO_GPDIR_1_reg(data)                                              (*((volatile unsigned int*)GPIO_GPDIR_1_reg)=data)
#define  get_GPIO_GPDIR_1_reg                                                    (*((volatile unsigned int*)GPIO_GPDIR_1_reg))
#define  GPIO_GPDIR_1_gpdir_shift                                                (0)
#define  GPIO_GPDIR_1_gpdir_mask                                                 (0x0000001F)
#define  GPIO_GPDIR_1_gpdir(data)                                                (0x0000001F&(data))
#define  GPIO_GPDIR_1_get_gpdir(data)                                            (0x0000001F&(data))

#define  GPIO_GPDATO                                                             0x18061108
#define  GPIO_GPDATO_reg_addr                                                    "0xB8061108"
#define  GPIO_GPDATO_reg                                                         0xB8061108
#define  GPIO_GPDATO_inst_addr                                                   "0x0002"
#define  set_GPIO_GPDATO_reg(data)                                               (*((volatile unsigned int*)GPIO_GPDATO_reg)=data)
#define  get_GPIO_GPDATO_reg                                                     (*((volatile unsigned int*)GPIO_GPDATO_reg))
#define  GPIO_GPDATO_gpdato_shift                                                (0)
#define  GPIO_GPDATO_gpdato_mask                                                 (0xFFFFFFFF)
#define  GPIO_GPDATO_gpdato(data)                                                (0xFFFFFFFF&(data))
#define  GPIO_GPDATO_get_gpdato(data)                                            (0xFFFFFFFF&(data))

#define  GPIO_GPDATO_1                                                           0x1806110C
#define  GPIO_GPDATO_1_reg_addr                                                  "0xB806110C"
#define  GPIO_GPDATO_1_reg                                                       0xB806110C
#define  GPIO_GPDATO_1_inst_addr                                                 "0x0003"
#define  set_GPIO_GPDATO_1_reg(data)                                             (*((volatile unsigned int*)GPIO_GPDATO_1_reg)=data)
#define  get_GPIO_GPDATO_1_reg                                                   (*((volatile unsigned int*)GPIO_GPDATO_1_reg))
#define  GPIO_GPDATO_1_gpdato_shift                                              (0)
#define  GPIO_GPDATO_1_gpdato_mask                                               (0x0000001F)
#define  GPIO_GPDATO_1_gpdato(data)                                              (0x0000001F&(data))
#define  GPIO_GPDATO_1_get_gpdato(data)                                          (0x0000001F&(data))

#define  GPIO_GPDATI                                                             0x18061110
#define  GPIO_GPDATI_reg_addr                                                    "0xB8061110"
#define  GPIO_GPDATI_reg                                                         0xB8061110
#define  GPIO_GPDATI_inst_addr                                                   "0x0004"
#define  set_GPIO_GPDATI_reg(data)                                               (*((volatile unsigned int*)GPIO_GPDATI_reg)=data)
#define  get_GPIO_GPDATI_reg                                                     (*((volatile unsigned int*)GPIO_GPDATI_reg))
#define  GPIO_GPDATI_gpdati_shift                                                (0)
#define  GPIO_GPDATI_gpdati_mask                                                 (0xFFFFFFFF)
#define  GPIO_GPDATI_gpdati(data)                                                (0xFFFFFFFF&(data))
#define  GPIO_GPDATI_get_gpdati(data)                                            (0xFFFFFFFF&(data))

#define  GPIO_GPDATI_1                                                           0x18061114
#define  GPIO_GPDATI_1_reg_addr                                                  "0xB8061114"
#define  GPIO_GPDATI_1_reg                                                       0xB8061114
#define  GPIO_GPDATI_1_inst_addr                                                 "0x0005"
#define  set_GPIO_GPDATI_1_reg(data)                                             (*((volatile unsigned int*)GPIO_GPDATI_1_reg)=data)
#define  get_GPIO_GPDATI_1_reg                                                   (*((volatile unsigned int*)GPIO_GPDATI_1_reg))
#define  GPIO_GPDATI_1_gpdati_shift                                              (0)
#define  GPIO_GPDATI_1_gpdati_mask                                               (0x0000001F)
#define  GPIO_GPDATI_1_gpdati(data)                                              (0x0000001F&(data))
#define  GPIO_GPDATI_1_get_gpdati(data)                                          (0x0000001F&(data))

#define  GPIO_GPIE                                                               0x18061118
#define  GPIO_GPIE_reg_addr                                                      "0xB8061118"
#define  GPIO_GPIE_reg                                                           0xB8061118
#define  GPIO_GPIE_inst_addr                                                     "0x0006"
#define  set_GPIO_GPIE_reg(data)                                                 (*((volatile unsigned int*)GPIO_GPIE_reg)=data)
#define  get_GPIO_GPIE_reg                                                       (*((volatile unsigned int*)GPIO_GPIE_reg))
#define  GPIO_GPIE_gp_shift                                                      (0)
#define  GPIO_GPIE_gp_mask                                                       (0xFFFFFFFF)
#define  GPIO_GPIE_gp(data)                                                      (0xFFFFFFFF&(data))
#define  GPIO_GPIE_get_gp(data)                                                  (0xFFFFFFFF&(data))

#define  GPIO_GPIE_1                                                             0x1806111C
#define  GPIO_GPIE_1_reg_addr                                                    "0xB806111C"
#define  GPIO_GPIE_1_reg                                                         0xB806111C
#define  GPIO_GPIE_1_inst_addr                                                   "0x0007"
#define  set_GPIO_GPIE_1_reg(data)                                               (*((volatile unsigned int*)GPIO_GPIE_1_reg)=data)
#define  get_GPIO_GPIE_1_reg                                                     (*((volatile unsigned int*)GPIO_GPIE_1_reg))
#define  GPIO_GPIE_1_gp_shift                                                    (0)
#define  GPIO_GPIE_1_gp_mask                                                     (0x0000001F)
#define  GPIO_GPIE_1_gp(data)                                                    (0x0000001F&(data))
#define  GPIO_GPIE_1_get_gp(data)                                                (0x0000001F&(data))

#define  GPIO_GPDP                                                               0x18061120
#define  GPIO_GPDP_reg_addr                                                      "0xB8061120"
#define  GPIO_GPDP_reg                                                           0xB8061120
#define  GPIO_GPDP_inst_addr                                                     "0x0008"
#define  set_GPIO_GPDP_reg(data)                                                 (*((volatile unsigned int*)GPIO_GPDP_reg)=data)
#define  get_GPIO_GPDP_reg                                                       (*((volatile unsigned int*)GPIO_GPDP_reg))
#define  GPIO_GPDP_gpha_shift                                                    (0)
#define  GPIO_GPDP_gpha_mask                                                     (0xFFFFFFFF)
#define  GPIO_GPDP_gpha(data)                                                    (0xFFFFFFFF&(data))
#define  GPIO_GPDP_get_gpha(data)                                                (0xFFFFFFFF&(data))

#define  GPIO_GPDP_1                                                             0x18061124
#define  GPIO_GPDP_1_reg_addr                                                    "0xB8061124"
#define  GPIO_GPDP_1_reg                                                         0xB8061124
#define  GPIO_GPDP_1_inst_addr                                                   "0x0009"
#define  set_GPIO_GPDP_1_reg(data)                                               (*((volatile unsigned int*)GPIO_GPDP_1_reg)=data)
#define  get_GPIO_GPDP_1_reg                                                     (*((volatile unsigned int*)GPIO_GPDP_1_reg))
#define  GPIO_GPDP_1_gpha_shift                                                  (0)
#define  GPIO_GPDP_1_gpha_mask                                                   (0x0000001F)
#define  GPIO_GPDP_1_gpha(data)                                                  (0x0000001F&(data))
#define  GPIO_GPDP_1_get_gpha(data)                                              (0x0000001F&(data))

#define  GPIO_GPDEB                                                              0x18061128
#define  GPIO_GPDEB_reg_addr                                                     "0xB8061128"
#define  GPIO_GPDEB_reg                                                          0xB8061128
#define  GPIO_GPDEB_inst_addr                                                    "0x000A"
#define  set_GPIO_GPDEB_reg(data)                                                (*((volatile unsigned int*)GPIO_GPDEB_reg)=data)
#define  get_GPIO_GPDEB_reg                                                      (*((volatile unsigned int*)GPIO_GPDEB_reg))
#define  GPIO_GPDEB_write_en2_shift                                              (7)
#define  GPIO_GPDEB_clk2_shift                                                   (4)
#define  GPIO_GPDEB_write_en1_shift                                              (3)
#define  GPIO_GPDEB_clk1_shift                                                   (0)
#define  GPIO_GPDEB_write_en2_mask                                               (0x00000080)
#define  GPIO_GPDEB_clk2_mask                                                    (0x00000070)
#define  GPIO_GPDEB_write_en1_mask                                               (0x00000008)
#define  GPIO_GPDEB_clk1_mask                                                    (0x00000007)
#define  GPIO_GPDEB_write_en2(data)                                              (0x00000080&((data)<<7))
#define  GPIO_GPDEB_clk2(data)                                                   (0x00000070&((data)<<4))
#define  GPIO_GPDEB_write_en1(data)                                              (0x00000008&((data)<<3))
#define  GPIO_GPDEB_clk1(data)                                                   (0x00000007&(data))
#define  GPIO_GPDEB_get_write_en2(data)                                          ((0x00000080&(data))>>7)
#define  GPIO_GPDEB_get_clk2(data)                                               ((0x00000070&(data))>>4)
#define  GPIO_GPDEB_get_write_en1(data)                                          ((0x00000008&(data))>>3)
#define  GPIO_GPDEB_get_clk1(data)                                               (0x00000007&(data))

#define  GPIO_ISR_GP_ASSERT                                                      0x18061130
#define  GPIO_ISR_GP_ASSERT_reg_addr                                             "0xB8061130"
#define  GPIO_ISR_GP_ASSERT_reg                                                  0xB8061130
#define  GPIO_ISR_GP_ASSERT_inst_addr                                            "0x000B"
#define  set_GPIO_ISR_GP_ASSERT_reg(data)                                        (*((volatile unsigned int*)GPIO_ISR_GP_ASSERT_reg)=data)
#define  get_GPIO_ISR_GP_ASSERT_reg                                              (*((volatile unsigned int*)GPIO_ISR_GP_ASSERT_reg))
#define  GPIO_ISR_GP_ASSERT_int30_a_shift                                        (31)
#define  GPIO_ISR_GP_ASSERT_int29_a_shift                                        (30)
#define  GPIO_ISR_GP_ASSERT_int28_a_shift                                        (29)
#define  GPIO_ISR_GP_ASSERT_int27_a_shift                                        (28)
#define  GPIO_ISR_GP_ASSERT_int26_a_shift                                        (27)
#define  GPIO_ISR_GP_ASSERT_int25_a_shift                                        (26)
#define  GPIO_ISR_GP_ASSERT_int24_a_shift                                        (25)
#define  GPIO_ISR_GP_ASSERT_int23_a_shift                                        (24)
#define  GPIO_ISR_GP_ASSERT_int22_a_shift                                        (23)
#define  GPIO_ISR_GP_ASSERT_int21_a_shift                                        (22)
#define  GPIO_ISR_GP_ASSERT_int20_a_shift                                        (21)
#define  GPIO_ISR_GP_ASSERT_int19_a_shift                                        (20)
#define  GPIO_ISR_GP_ASSERT_int18_a_shift                                        (19)
#define  GPIO_ISR_GP_ASSERT_int17_a_shift                                        (18)
#define  GPIO_ISR_GP_ASSERT_int16_a_shift                                        (17)
#define  GPIO_ISR_GP_ASSERT_int15_a_shift                                        (16)
#define  GPIO_ISR_GP_ASSERT_int14_a_shift                                        (15)
#define  GPIO_ISR_GP_ASSERT_int13_a_shift                                        (14)
#define  GPIO_ISR_GP_ASSERT_int12_a_shift                                        (13)
#define  GPIO_ISR_GP_ASSERT_int11_a_shift                                        (12)
#define  GPIO_ISR_GP_ASSERT_int10_a_shift                                        (11)
#define  GPIO_ISR_GP_ASSERT_int9_a_shift                                         (10)
#define  GPIO_ISR_GP_ASSERT_int8_a_shift                                         (9)
#define  GPIO_ISR_GP_ASSERT_int7_a_shift                                         (8)
#define  GPIO_ISR_GP_ASSERT_int6_a_shift                                         (7)
#define  GPIO_ISR_GP_ASSERT_int5_a_shift                                         (6)
#define  GPIO_ISR_GP_ASSERT_int4_a_shift                                         (5)
#define  GPIO_ISR_GP_ASSERT_int3_a_shift                                         (4)
#define  GPIO_ISR_GP_ASSERT_int2_a_shift                                         (3)
#define  GPIO_ISR_GP_ASSERT_int1_a_shift                                         (2)
#define  GPIO_ISR_GP_ASSERT_int0_a_shift                                         (1)
#define  GPIO_ISR_GP_ASSERT_write_data_shift                                     (0)
#define  GPIO_ISR_GP_ASSERT_int30_a_mask                                         (0x80000000)
#define  GPIO_ISR_GP_ASSERT_int29_a_mask                                         (0x40000000)
#define  GPIO_ISR_GP_ASSERT_int28_a_mask                                         (0x20000000)
#define  GPIO_ISR_GP_ASSERT_int27_a_mask                                         (0x10000000)
#define  GPIO_ISR_GP_ASSERT_int26_a_mask                                         (0x08000000)
#define  GPIO_ISR_GP_ASSERT_int25_a_mask                                         (0x04000000)
#define  GPIO_ISR_GP_ASSERT_int24_a_mask                                         (0x02000000)
#define  GPIO_ISR_GP_ASSERT_int23_a_mask                                         (0x01000000)
#define  GPIO_ISR_GP_ASSERT_int22_a_mask                                         (0x00800000)
#define  GPIO_ISR_GP_ASSERT_int21_a_mask                                         (0x00400000)
#define  GPIO_ISR_GP_ASSERT_int20_a_mask                                         (0x00200000)
#define  GPIO_ISR_GP_ASSERT_int19_a_mask                                         (0x00100000)
#define  GPIO_ISR_GP_ASSERT_int18_a_mask                                         (0x00080000)
#define  GPIO_ISR_GP_ASSERT_int17_a_mask                                         (0x00040000)
#define  GPIO_ISR_GP_ASSERT_int16_a_mask                                         (0x00020000)
#define  GPIO_ISR_GP_ASSERT_int15_a_mask                                         (0x00010000)
#define  GPIO_ISR_GP_ASSERT_int14_a_mask                                         (0x00008000)
#define  GPIO_ISR_GP_ASSERT_int13_a_mask                                         (0x00004000)
#define  GPIO_ISR_GP_ASSERT_int12_a_mask                                         (0x00002000)
#define  GPIO_ISR_GP_ASSERT_int11_a_mask                                         (0x00001000)
#define  GPIO_ISR_GP_ASSERT_int10_a_mask                                         (0x00000800)
#define  GPIO_ISR_GP_ASSERT_int9_a_mask                                          (0x00000400)
#define  GPIO_ISR_GP_ASSERT_int8_a_mask                                          (0x00000200)
#define  GPIO_ISR_GP_ASSERT_int7_a_mask                                          (0x00000100)
#define  GPIO_ISR_GP_ASSERT_int6_a_mask                                          (0x00000080)
#define  GPIO_ISR_GP_ASSERT_int5_a_mask                                          (0x00000040)
#define  GPIO_ISR_GP_ASSERT_int4_a_mask                                          (0x00000020)
#define  GPIO_ISR_GP_ASSERT_int3_a_mask                                          (0x00000010)
#define  GPIO_ISR_GP_ASSERT_int2_a_mask                                          (0x00000008)
#define  GPIO_ISR_GP_ASSERT_int1_a_mask                                          (0x00000004)
#define  GPIO_ISR_GP_ASSERT_int0_a_mask                                          (0x00000002)
#define  GPIO_ISR_GP_ASSERT_write_data_mask                                      (0x00000001)
#define  GPIO_ISR_GP_ASSERT_int30_a(data)                                        (0x80000000&((data)<<31))
#define  GPIO_ISR_GP_ASSERT_int29_a(data)                                        (0x40000000&((data)<<30))
#define  GPIO_ISR_GP_ASSERT_int28_a(data)                                        (0x20000000&((data)<<29))
#define  GPIO_ISR_GP_ASSERT_int27_a(data)                                        (0x10000000&((data)<<28))
#define  GPIO_ISR_GP_ASSERT_int26_a(data)                                        (0x08000000&((data)<<27))
#define  GPIO_ISR_GP_ASSERT_int25_a(data)                                        (0x04000000&((data)<<26))
#define  GPIO_ISR_GP_ASSERT_int24_a(data)                                        (0x02000000&((data)<<25))
#define  GPIO_ISR_GP_ASSERT_int23_a(data)                                        (0x01000000&((data)<<24))
#define  GPIO_ISR_GP_ASSERT_int22_a(data)                                        (0x00800000&((data)<<23))
#define  GPIO_ISR_GP_ASSERT_int21_a(data)                                        (0x00400000&((data)<<22))
#define  GPIO_ISR_GP_ASSERT_int20_a(data)                                        (0x00200000&((data)<<21))
#define  GPIO_ISR_GP_ASSERT_int19_a(data)                                        (0x00100000&((data)<<20))
#define  GPIO_ISR_GP_ASSERT_int18_a(data)                                        (0x00080000&((data)<<19))
#define  GPIO_ISR_GP_ASSERT_int17_a(data)                                        (0x00040000&((data)<<18))
#define  GPIO_ISR_GP_ASSERT_int16_a(data)                                        (0x00020000&((data)<<17))
#define  GPIO_ISR_GP_ASSERT_int15_a(data)                                        (0x00010000&((data)<<16))
#define  GPIO_ISR_GP_ASSERT_int14_a(data)                                        (0x00008000&((data)<<15))
#define  GPIO_ISR_GP_ASSERT_int13_a(data)                                        (0x00004000&((data)<<14))
#define  GPIO_ISR_GP_ASSERT_int12_a(data)                                        (0x00002000&((data)<<13))
#define  GPIO_ISR_GP_ASSERT_int11_a(data)                                        (0x00001000&((data)<<12))
#define  GPIO_ISR_GP_ASSERT_int10_a(data)                                        (0x00000800&((data)<<11))
#define  GPIO_ISR_GP_ASSERT_int9_a(data)                                         (0x00000400&((data)<<10))
#define  GPIO_ISR_GP_ASSERT_int8_a(data)                                         (0x00000200&((data)<<9))
#define  GPIO_ISR_GP_ASSERT_int7_a(data)                                         (0x00000100&((data)<<8))
#define  GPIO_ISR_GP_ASSERT_int6_a(data)                                         (0x00000080&((data)<<7))
#define  GPIO_ISR_GP_ASSERT_int5_a(data)                                         (0x00000040&((data)<<6))
#define  GPIO_ISR_GP_ASSERT_int4_a(data)                                         (0x00000020&((data)<<5))
#define  GPIO_ISR_GP_ASSERT_int3_a(data)                                         (0x00000010&((data)<<4))
#define  GPIO_ISR_GP_ASSERT_int2_a(data)                                         (0x00000008&((data)<<3))
#define  GPIO_ISR_GP_ASSERT_int1_a(data)                                         (0x00000004&((data)<<2))
#define  GPIO_ISR_GP_ASSERT_int0_a(data)                                         (0x00000002&((data)<<1))
#define  GPIO_ISR_GP_ASSERT_write_data(data)                                     (0x00000001&(data))
#define  GPIO_ISR_GP_ASSERT_get_int30_a(data)                                    ((0x80000000&(data))>>31)
#define  GPIO_ISR_GP_ASSERT_get_int29_a(data)                                    ((0x40000000&(data))>>30)
#define  GPIO_ISR_GP_ASSERT_get_int28_a(data)                                    ((0x20000000&(data))>>29)
#define  GPIO_ISR_GP_ASSERT_get_int27_a(data)                                    ((0x10000000&(data))>>28)
#define  GPIO_ISR_GP_ASSERT_get_int26_a(data)                                    ((0x08000000&(data))>>27)
#define  GPIO_ISR_GP_ASSERT_get_int25_a(data)                                    ((0x04000000&(data))>>26)
#define  GPIO_ISR_GP_ASSERT_get_int24_a(data)                                    ((0x02000000&(data))>>25)
#define  GPIO_ISR_GP_ASSERT_get_int23_a(data)                                    ((0x01000000&(data))>>24)
#define  GPIO_ISR_GP_ASSERT_get_int22_a(data)                                    ((0x00800000&(data))>>23)
#define  GPIO_ISR_GP_ASSERT_get_int21_a(data)                                    ((0x00400000&(data))>>22)
#define  GPIO_ISR_GP_ASSERT_get_int20_a(data)                                    ((0x00200000&(data))>>21)
#define  GPIO_ISR_GP_ASSERT_get_int19_a(data)                                    ((0x00100000&(data))>>20)
#define  GPIO_ISR_GP_ASSERT_get_int18_a(data)                                    ((0x00080000&(data))>>19)
#define  GPIO_ISR_GP_ASSERT_get_int17_a(data)                                    ((0x00040000&(data))>>18)
#define  GPIO_ISR_GP_ASSERT_get_int16_a(data)                                    ((0x00020000&(data))>>17)
#define  GPIO_ISR_GP_ASSERT_get_int15_a(data)                                    ((0x00010000&(data))>>16)
#define  GPIO_ISR_GP_ASSERT_get_int14_a(data)                                    ((0x00008000&(data))>>15)
#define  GPIO_ISR_GP_ASSERT_get_int13_a(data)                                    ((0x00004000&(data))>>14)
#define  GPIO_ISR_GP_ASSERT_get_int12_a(data)                                    ((0x00002000&(data))>>13)
#define  GPIO_ISR_GP_ASSERT_get_int11_a(data)                                    ((0x00001000&(data))>>12)
#define  GPIO_ISR_GP_ASSERT_get_int10_a(data)                                    ((0x00000800&(data))>>11)
#define  GPIO_ISR_GP_ASSERT_get_int9_a(data)                                     ((0x00000400&(data))>>10)
#define  GPIO_ISR_GP_ASSERT_get_int8_a(data)                                     ((0x00000200&(data))>>9)
#define  GPIO_ISR_GP_ASSERT_get_int7_a(data)                                     ((0x00000100&(data))>>8)
#define  GPIO_ISR_GP_ASSERT_get_int6_a(data)                                     ((0x00000080&(data))>>7)
#define  GPIO_ISR_GP_ASSERT_get_int5_a(data)                                     ((0x00000040&(data))>>6)
#define  GPIO_ISR_GP_ASSERT_get_int4_a(data)                                     ((0x00000020&(data))>>5)
#define  GPIO_ISR_GP_ASSERT_get_int3_a(data)                                     ((0x00000010&(data))>>4)
#define  GPIO_ISR_GP_ASSERT_get_int2_a(data)                                     ((0x00000008&(data))>>3)
#define  GPIO_ISR_GP_ASSERT_get_int1_a(data)                                     ((0x00000004&(data))>>2)
#define  GPIO_ISR_GP_ASSERT_get_int0_a(data)                                     ((0x00000002&(data))>>1)
#define  GPIO_ISR_GP_ASSERT_get_write_data(data)                                 (0x00000001&(data))

#define  GPIO_ISR_GP_ASSERT_1                                                    0x18061134
#define  GPIO_ISR_GP_ASSERT_1_reg_addr                                           "0xB8061134"
#define  GPIO_ISR_GP_ASSERT_1_reg                                                0xB8061134
#define  GPIO_ISR_GP_ASSERT_1_inst_addr                                          "0x000C"
#define  set_GPIO_ISR_GP_ASSERT_1_reg(data)                                      (*((volatile unsigned int*)GPIO_ISR_GP_ASSERT_1_reg)=data)
#define  get_GPIO_ISR_GP_ASSERT_1_reg                                            (*((volatile unsigned int*)GPIO_ISR_GP_ASSERT_1_reg))
#define  GPIO_ISR_GP_ASSERT_1_int36_a_shift                                      (6)
#define  GPIO_ISR_GP_ASSERT_1_int35_a_shift                                      (5)
#define  GPIO_ISR_GP_ASSERT_1_int34_a_shift                                      (4)
#define  GPIO_ISR_GP_ASSERT_1_int33_a_shift                                      (3)
#define  GPIO_ISR_GP_ASSERT_1_int32_a_shift                                      (2)
#define  GPIO_ISR_GP_ASSERT_1_int31_a_shift                                      (1)
#define  GPIO_ISR_GP_ASSERT_1_write_data_shift                                   (0)
#define  GPIO_ISR_GP_ASSERT_1_int36_a_mask                                       (0x00000040)
#define  GPIO_ISR_GP_ASSERT_1_int35_a_mask                                       (0x00000020)
#define  GPIO_ISR_GP_ASSERT_1_int34_a_mask                                       (0x00000010)
#define  GPIO_ISR_GP_ASSERT_1_int33_a_mask                                       (0x00000008)
#define  GPIO_ISR_GP_ASSERT_1_int32_a_mask                                       (0x00000004)
#define  GPIO_ISR_GP_ASSERT_1_int31_a_mask                                       (0x00000002)
#define  GPIO_ISR_GP_ASSERT_1_write_data_mask                                    (0x00000001)
#define  GPIO_ISR_GP_ASSERT_1_int36_a(data)                                      (0x00000040&((data)<<6))
#define  GPIO_ISR_GP_ASSERT_1_int35_a(data)                                      (0x00000020&((data)<<5))
#define  GPIO_ISR_GP_ASSERT_1_int34_a(data)                                      (0x00000010&((data)<<4))
#define  GPIO_ISR_GP_ASSERT_1_int33_a(data)                                      (0x00000008&((data)<<3))
#define  GPIO_ISR_GP_ASSERT_1_int32_a(data)                                      (0x00000004&((data)<<2))
#define  GPIO_ISR_GP_ASSERT_1_int31_a(data)                                      (0x00000002&((data)<<1))
#define  GPIO_ISR_GP_ASSERT_1_write_data(data)                                   (0x00000001&(data))
#define  GPIO_ISR_GP_ASSERT_1_get_int36_a(data)                                  ((0x00000040&(data))>>6)
#define  GPIO_ISR_GP_ASSERT_1_get_int35_a(data)                                  ((0x00000020&(data))>>5)
#define  GPIO_ISR_GP_ASSERT_1_get_int34_a(data)                                  ((0x00000010&(data))>>4)
#define  GPIO_ISR_GP_ASSERT_1_get_int33_a(data)                                  ((0x00000008&(data))>>3)
#define  GPIO_ISR_GP_ASSERT_1_get_int32_a(data)                                  ((0x00000004&(data))>>2)
#define  GPIO_ISR_GP_ASSERT_1_get_int31_a(data)                                  ((0x00000002&(data))>>1)
#define  GPIO_ISR_GP_ASSERT_1_get_write_data(data)                               (0x00000001&(data))

#define  GPIO_ISR_GP_DEASSERT                                                    0x18061138
#define  GPIO_ISR_GP_DEASSERT_reg_addr                                           "0xB8061138"
#define  GPIO_ISR_GP_DEASSERT_reg                                                0xB8061138
#define  GPIO_ISR_GP_DEASSERT_inst_addr                                          "0x000D"
#define  set_GPIO_ISR_GP_DEASSERT_reg(data)                                      (*((volatile unsigned int*)GPIO_ISR_GP_DEASSERT_reg)=data)
#define  get_GPIO_ISR_GP_DEASSERT_reg                                            (*((volatile unsigned int*)GPIO_ISR_GP_DEASSERT_reg))
#define  GPIO_ISR_GP_DEASSERT_int30_da_shift                                     (31)
#define  GPIO_ISR_GP_DEASSERT_int29_da_shift                                     (30)
#define  GPIO_ISR_GP_DEASSERT_int28_da_shift                                     (29)
#define  GPIO_ISR_GP_DEASSERT_int27_da_shift                                     (28)
#define  GPIO_ISR_GP_DEASSERT_int26_da_shift                                     (27)
#define  GPIO_ISR_GP_DEASSERT_int25_da_shift                                     (26)
#define  GPIO_ISR_GP_DEASSERT_int24_da_shift                                     (25)
#define  GPIO_ISR_GP_DEASSERT_int23_da_shift                                     (24)
#define  GPIO_ISR_GP_DEASSERT_int22_da_shift                                     (23)
#define  GPIO_ISR_GP_DEASSERT_int21_da_shift                                     (22)
#define  GPIO_ISR_GP_DEASSERT_int20_da_shift                                     (21)
#define  GPIO_ISR_GP_DEASSERT_int19_da_shift                                     (20)
#define  GPIO_ISR_GP_DEASSERT_int18_da_shift                                     (19)
#define  GPIO_ISR_GP_DEASSERT_int17_da_shift                                     (18)
#define  GPIO_ISR_GP_DEASSERT_int16_da_shift                                     (17)
#define  GPIO_ISR_GP_DEASSERT_int15_da_shift                                     (16)
#define  GPIO_ISR_GP_DEASSERT_int14_da_shift                                     (15)
#define  GPIO_ISR_GP_DEASSERT_int13_da_shift                                     (14)
#define  GPIO_ISR_GP_DEASSERT_int12_da_shift                                     (13)
#define  GPIO_ISR_GP_DEASSERT_int11_da_shift                                     (12)
#define  GPIO_ISR_GP_DEASSERT_int10_da_shift                                     (11)
#define  GPIO_ISR_GP_DEASSERT_int9_da_shift                                      (10)
#define  GPIO_ISR_GP_DEASSERT_int8_da_shift                                      (9)
#define  GPIO_ISR_GP_DEASSERT_int7_da_shift                                      (8)
#define  GPIO_ISR_GP_DEASSERT_int6_da_shift                                      (7)
#define  GPIO_ISR_GP_DEASSERT_int5_da_shift                                      (6)
#define  GPIO_ISR_GP_DEASSERT_int4_da_shift                                      (5)
#define  GPIO_ISR_GP_DEASSERT_int3_da_shift                                      (4)
#define  GPIO_ISR_GP_DEASSERT_int2_da_shift                                      (3)
#define  GPIO_ISR_GP_DEASSERT_int1_da_shift                                      (2)
#define  GPIO_ISR_GP_DEASSERT_int0_da_shift                                      (1)
#define  GPIO_ISR_GP_DEASSERT_write_data_shift                                   (0)
#define  GPIO_ISR_GP_DEASSERT_int30_da_mask                                      (0x80000000)
#define  GPIO_ISR_GP_DEASSERT_int29_da_mask                                      (0x40000000)
#define  GPIO_ISR_GP_DEASSERT_int28_da_mask                                      (0x20000000)
#define  GPIO_ISR_GP_DEASSERT_int27_da_mask                                      (0x10000000)
#define  GPIO_ISR_GP_DEASSERT_int26_da_mask                                      (0x08000000)
#define  GPIO_ISR_GP_DEASSERT_int25_da_mask                                      (0x04000000)
#define  GPIO_ISR_GP_DEASSERT_int24_da_mask                                      (0x02000000)
#define  GPIO_ISR_GP_DEASSERT_int23_da_mask                                      (0x01000000)
#define  GPIO_ISR_GP_DEASSERT_int22_da_mask                                      (0x00800000)
#define  GPIO_ISR_GP_DEASSERT_int21_da_mask                                      (0x00400000)
#define  GPIO_ISR_GP_DEASSERT_int20_da_mask                                      (0x00200000)
#define  GPIO_ISR_GP_DEASSERT_int19_da_mask                                      (0x00100000)
#define  GPIO_ISR_GP_DEASSERT_int18_da_mask                                      (0x00080000)
#define  GPIO_ISR_GP_DEASSERT_int17_da_mask                                      (0x00040000)
#define  GPIO_ISR_GP_DEASSERT_int16_da_mask                                      (0x00020000)
#define  GPIO_ISR_GP_DEASSERT_int15_da_mask                                      (0x00010000)
#define  GPIO_ISR_GP_DEASSERT_int14_da_mask                                      (0x00008000)
#define  GPIO_ISR_GP_DEASSERT_int13_da_mask                                      (0x00004000)
#define  GPIO_ISR_GP_DEASSERT_int12_da_mask                                      (0x00002000)
#define  GPIO_ISR_GP_DEASSERT_int11_da_mask                                      (0x00001000)
#define  GPIO_ISR_GP_DEASSERT_int10_da_mask                                      (0x00000800)
#define  GPIO_ISR_GP_DEASSERT_int9_da_mask                                       (0x00000400)
#define  GPIO_ISR_GP_DEASSERT_int8_da_mask                                       (0x00000200)
#define  GPIO_ISR_GP_DEASSERT_int7_da_mask                                       (0x00000100)
#define  GPIO_ISR_GP_DEASSERT_int6_da_mask                                       (0x00000080)
#define  GPIO_ISR_GP_DEASSERT_int5_da_mask                                       (0x00000040)
#define  GPIO_ISR_GP_DEASSERT_int4_da_mask                                       (0x00000020)
#define  GPIO_ISR_GP_DEASSERT_int3_da_mask                                       (0x00000010)
#define  GPIO_ISR_GP_DEASSERT_int2_da_mask                                       (0x00000008)
#define  GPIO_ISR_GP_DEASSERT_int1_da_mask                                       (0x00000004)
#define  GPIO_ISR_GP_DEASSERT_int0_da_mask                                       (0x00000002)
#define  GPIO_ISR_GP_DEASSERT_write_data_mask                                    (0x00000001)
#define  GPIO_ISR_GP_DEASSERT_int30_da(data)                                     (0x80000000&((data)<<31))
#define  GPIO_ISR_GP_DEASSERT_int29_da(data)                                     (0x40000000&((data)<<30))
#define  GPIO_ISR_GP_DEASSERT_int28_da(data)                                     (0x20000000&((data)<<29))
#define  GPIO_ISR_GP_DEASSERT_int27_da(data)                                     (0x10000000&((data)<<28))
#define  GPIO_ISR_GP_DEASSERT_int26_da(data)                                     (0x08000000&((data)<<27))
#define  GPIO_ISR_GP_DEASSERT_int25_da(data)                                     (0x04000000&((data)<<26))
#define  GPIO_ISR_GP_DEASSERT_int24_da(data)                                     (0x02000000&((data)<<25))
#define  GPIO_ISR_GP_DEASSERT_int23_da(data)                                     (0x01000000&((data)<<24))
#define  GPIO_ISR_GP_DEASSERT_int22_da(data)                                     (0x00800000&((data)<<23))
#define  GPIO_ISR_GP_DEASSERT_int21_da(data)                                     (0x00400000&((data)<<22))
#define  GPIO_ISR_GP_DEASSERT_int20_da(data)                                     (0x00200000&((data)<<21))
#define  GPIO_ISR_GP_DEASSERT_int19_da(data)                                     (0x00100000&((data)<<20))
#define  GPIO_ISR_GP_DEASSERT_int18_da(data)                                     (0x00080000&((data)<<19))
#define  GPIO_ISR_GP_DEASSERT_int17_da(data)                                     (0x00040000&((data)<<18))
#define  GPIO_ISR_GP_DEASSERT_int16_da(data)                                     (0x00020000&((data)<<17))
#define  GPIO_ISR_GP_DEASSERT_int15_da(data)                                     (0x00010000&((data)<<16))
#define  GPIO_ISR_GP_DEASSERT_int14_da(data)                                     (0x00008000&((data)<<15))
#define  GPIO_ISR_GP_DEASSERT_int13_da(data)                                     (0x00004000&((data)<<14))
#define  GPIO_ISR_GP_DEASSERT_int12_da(data)                                     (0x00002000&((data)<<13))
#define  GPIO_ISR_GP_DEASSERT_int11_da(data)                                     (0x00001000&((data)<<12))
#define  GPIO_ISR_GP_DEASSERT_int10_da(data)                                     (0x00000800&((data)<<11))
#define  GPIO_ISR_GP_DEASSERT_int9_da(data)                                      (0x00000400&((data)<<10))
#define  GPIO_ISR_GP_DEASSERT_int8_da(data)                                      (0x00000200&((data)<<9))
#define  GPIO_ISR_GP_DEASSERT_int7_da(data)                                      (0x00000100&((data)<<8))
#define  GPIO_ISR_GP_DEASSERT_int6_da(data)                                      (0x00000080&((data)<<7))
#define  GPIO_ISR_GP_DEASSERT_int5_da(data)                                      (0x00000040&((data)<<6))
#define  GPIO_ISR_GP_DEASSERT_int4_da(data)                                      (0x00000020&((data)<<5))
#define  GPIO_ISR_GP_DEASSERT_int3_da(data)                                      (0x00000010&((data)<<4))
#define  GPIO_ISR_GP_DEASSERT_int2_da(data)                                      (0x00000008&((data)<<3))
#define  GPIO_ISR_GP_DEASSERT_int1_da(data)                                      (0x00000004&((data)<<2))
#define  GPIO_ISR_GP_DEASSERT_int0_da(data)                                      (0x00000002&((data)<<1))
#define  GPIO_ISR_GP_DEASSERT_write_data(data)                                   (0x00000001&(data))
#define  GPIO_ISR_GP_DEASSERT_get_int30_da(data)                                 ((0x80000000&(data))>>31)
#define  GPIO_ISR_GP_DEASSERT_get_int29_da(data)                                 ((0x40000000&(data))>>30)
#define  GPIO_ISR_GP_DEASSERT_get_int28_da(data)                                 ((0x20000000&(data))>>29)
#define  GPIO_ISR_GP_DEASSERT_get_int27_da(data)                                 ((0x10000000&(data))>>28)
#define  GPIO_ISR_GP_DEASSERT_get_int26_da(data)                                 ((0x08000000&(data))>>27)
#define  GPIO_ISR_GP_DEASSERT_get_int25_da(data)                                 ((0x04000000&(data))>>26)
#define  GPIO_ISR_GP_DEASSERT_get_int24_da(data)                                 ((0x02000000&(data))>>25)
#define  GPIO_ISR_GP_DEASSERT_get_int23_da(data)                                 ((0x01000000&(data))>>24)
#define  GPIO_ISR_GP_DEASSERT_get_int22_da(data)                                 ((0x00800000&(data))>>23)
#define  GPIO_ISR_GP_DEASSERT_get_int21_da(data)                                 ((0x00400000&(data))>>22)
#define  GPIO_ISR_GP_DEASSERT_get_int20_da(data)                                 ((0x00200000&(data))>>21)
#define  GPIO_ISR_GP_DEASSERT_get_int19_da(data)                                 ((0x00100000&(data))>>20)
#define  GPIO_ISR_GP_DEASSERT_get_int18_da(data)                                 ((0x00080000&(data))>>19)
#define  GPIO_ISR_GP_DEASSERT_get_int17_da(data)                                 ((0x00040000&(data))>>18)
#define  GPIO_ISR_GP_DEASSERT_get_int16_da(data)                                 ((0x00020000&(data))>>17)
#define  GPIO_ISR_GP_DEASSERT_get_int15_da(data)                                 ((0x00010000&(data))>>16)
#define  GPIO_ISR_GP_DEASSERT_get_int14_da(data)                                 ((0x00008000&(data))>>15)
#define  GPIO_ISR_GP_DEASSERT_get_int13_da(data)                                 ((0x00004000&(data))>>14)
#define  GPIO_ISR_GP_DEASSERT_get_int12_da(data)                                 ((0x00002000&(data))>>13)
#define  GPIO_ISR_GP_DEASSERT_get_int11_da(data)                                 ((0x00001000&(data))>>12)
#define  GPIO_ISR_GP_DEASSERT_get_int10_da(data)                                 ((0x00000800&(data))>>11)
#define  GPIO_ISR_GP_DEASSERT_get_int9_da(data)                                  ((0x00000400&(data))>>10)
#define  GPIO_ISR_GP_DEASSERT_get_int8_da(data)                                  ((0x00000200&(data))>>9)
#define  GPIO_ISR_GP_DEASSERT_get_int7_da(data)                                  ((0x00000100&(data))>>8)
#define  GPIO_ISR_GP_DEASSERT_get_int6_da(data)                                  ((0x00000080&(data))>>7)
#define  GPIO_ISR_GP_DEASSERT_get_int5_da(data)                                  ((0x00000040&(data))>>6)
#define  GPIO_ISR_GP_DEASSERT_get_int4_da(data)                                  ((0x00000020&(data))>>5)
#define  GPIO_ISR_GP_DEASSERT_get_int3_da(data)                                  ((0x00000010&(data))>>4)
#define  GPIO_ISR_GP_DEASSERT_get_int2_da(data)                                  ((0x00000008&(data))>>3)
#define  GPIO_ISR_GP_DEASSERT_get_int1_da(data)                                  ((0x00000004&(data))>>2)
#define  GPIO_ISR_GP_DEASSERT_get_int0_da(data)                                  ((0x00000002&(data))>>1)
#define  GPIO_ISR_GP_DEASSERT_get_write_data(data)                               (0x00000001&(data))

#define  GPIO_ISR_GP_DEASSERT_1                                                  0x1806113C
#define  GPIO_ISR_GP_DEASSERT_1_reg_addr                                         "0xB806113C"
#define  GPIO_ISR_GP_DEASSERT_1_reg                                              0xB806113C
#define  GPIO_ISR_GP_DEASSERT_1_inst_addr                                        "0x000E"
#define  set_GPIO_ISR_GP_DEASSERT_1_reg(data)                                    (*((volatile unsigned int*)GPIO_ISR_GP_DEASSERT_1_reg)=data)
#define  get_GPIO_ISR_GP_DEASSERT_1_reg                                          (*((volatile unsigned int*)GPIO_ISR_GP_DEASSERT_1_reg))
#define  GPIO_ISR_GP_DEASSERT_1_int36_da_shift                                   (6)
#define  GPIO_ISR_GP_DEASSERT_1_int35_da_shift                                   (5)
#define  GPIO_ISR_GP_DEASSERT_1_int34_da_shift                                   (4)
#define  GPIO_ISR_GP_DEASSERT_1_int33_da_shift                                   (3)
#define  GPIO_ISR_GP_DEASSERT_1_int32_da_shift                                   (2)
#define  GPIO_ISR_GP_DEASSERT_1_int31_da_shift                                   (1)
#define  GPIO_ISR_GP_DEASSERT_1_write_data_shift                                 (0)
#define  GPIO_ISR_GP_DEASSERT_1_int36_da_mask                                    (0x00000040)
#define  GPIO_ISR_GP_DEASSERT_1_int35_da_mask                                    (0x00000020)
#define  GPIO_ISR_GP_DEASSERT_1_int34_da_mask                                    (0x00000010)
#define  GPIO_ISR_GP_DEASSERT_1_int33_da_mask                                    (0x00000008)
#define  GPIO_ISR_GP_DEASSERT_1_int32_da_mask                                    (0x00000004)
#define  GPIO_ISR_GP_DEASSERT_1_int31_da_mask                                    (0x00000002)
#define  GPIO_ISR_GP_DEASSERT_1_write_data_mask                                  (0x00000001)
#define  GPIO_ISR_GP_DEASSERT_1_int36_da(data)                                   (0x00000040&((data)<<6))
#define  GPIO_ISR_GP_DEASSERT_1_int35_da(data)                                   (0x00000020&((data)<<5))
#define  GPIO_ISR_GP_DEASSERT_1_int34_da(data)                                   (0x00000010&((data)<<4))
#define  GPIO_ISR_GP_DEASSERT_1_int33_da(data)                                   (0x00000008&((data)<<3))
#define  GPIO_ISR_GP_DEASSERT_1_int32_da(data)                                   (0x00000004&((data)<<2))
#define  GPIO_ISR_GP_DEASSERT_1_int31_da(data)                                   (0x00000002&((data)<<1))
#define  GPIO_ISR_GP_DEASSERT_1_write_data(data)                                 (0x00000001&(data))
#define  GPIO_ISR_GP_DEASSERT_1_get_int36_da(data)                               ((0x00000040&(data))>>6)
#define  GPIO_ISR_GP_DEASSERT_1_get_int35_da(data)                               ((0x00000020&(data))>>5)
#define  GPIO_ISR_GP_DEASSERT_1_get_int34_da(data)                               ((0x00000010&(data))>>4)
#define  GPIO_ISR_GP_DEASSERT_1_get_int33_da(data)                               ((0x00000008&(data))>>3)
#define  GPIO_ISR_GP_DEASSERT_1_get_int32_da(data)                               ((0x00000004&(data))>>2)
#define  GPIO_ISR_GP_DEASSERT_1_get_int31_da(data)                               ((0x00000002&(data))>>1)
#define  GPIO_ISR_GP_DEASSERT_1_get_write_data(data)                             (0x00000001&(data))

#define  GPIO_GP_INT_SEL                                                         0x18061140
#define  GPIO_GP_INT_SEL_reg_addr                                                "0xB8061140"
#define  GPIO_GP_INT_SEL_reg                                                     0xB8061140
#define  GPIO_GP_INT_SEL_inst_addr                                               "0x000F"
#define  set_GPIO_GP_INT_SEL_reg(data)                                           (*((volatile unsigned int*)GPIO_GP_INT_SEL_reg)=data)
#define  get_GPIO_GP_INT_SEL_reg                                                 (*((volatile unsigned int*)GPIO_GP_INT_SEL_reg))
#define  GPIO_GP_INT_SEL_intsel_shift                                            (0)
#define  GPIO_GP_INT_SEL_intsel_mask                                             (0x00000003)
#define  GPIO_GP_INT_SEL_intsel(data)                                            (0x00000003&(data))
#define  GPIO_GP_INT_SEL_get_intsel(data)                                        (0x00000003&(data))

#define  GPIO_GPI_DATI                                                           0x18061144
#define  GPIO_GPI_DATI_reg_addr                                                  "0xB8061144"
#define  GPIO_GPI_DATI_reg                                                       0xB8061144
#define  GPIO_GPI_DATI_inst_addr                                                 "0x0010"
#define  set_GPIO_GPI_DATI_reg(data)                                             (*((volatile unsigned int*)GPIO_GPI_DATI_reg)=data)
#define  get_GPIO_GPI_DATI_reg                                                   (*((volatile unsigned int*)GPIO_GPI_DATI_reg))
#define  GPIO_GPI_DATI_gpidati_shift                                             (0)
#define  GPIO_GPI_DATI_gpidati_mask                                              (0x00000003)
#define  GPIO_GPI_DATI_gpidati(data)                                             (0x00000003&(data))
#define  GPIO_GPI_DATI_get_gpidati(data)                                         (0x00000003&(data))

#define  GPIO_GPI_GPIE                                                           0x18061148
#define  GPIO_GPI_GPIE_reg_addr                                                  "0xB8061148"
#define  GPIO_GPI_GPIE_reg                                                       0xB8061148
#define  GPIO_GPI_GPIE_inst_addr                                                 "0x0011"
#define  set_GPIO_GPI_GPIE_reg(data)                                             (*((volatile unsigned int*)GPIO_GPI_GPIE_reg)=data)
#define  get_GPIO_GPI_GPIE_reg                                                   (*((volatile unsigned int*)GPIO_GPI_GPIE_reg))
#define  GPIO_GPI_GPIE_gp_shift                                                  (0)
#define  GPIO_GPI_GPIE_gp_mask                                                   (0x00000003)
#define  GPIO_GPI_GPIE_gp(data)                                                  (0x00000003&(data))
#define  GPIO_GPI_GPIE_get_gp(data)                                              (0x00000003&(data))

#define  GPIO_GPI_DP                                                             0x1806114C
#define  GPIO_GPI_DP_reg_addr                                                    "0xB806114C"
#define  GPIO_GPI_DP_reg                                                         0xB806114C
#define  GPIO_GPI_DP_inst_addr                                                   "0x0012"
#define  set_GPIO_GPI_DP_reg(data)                                               (*((volatile unsigned int*)GPIO_GPI_DP_reg)=data)
#define  get_GPIO_GPI_DP_reg                                                     (*((volatile unsigned int*)GPIO_GPI_DP_reg))
#define  GPIO_GPI_DP_gpha_shift                                                  (0)
#define  GPIO_GPI_DP_gpha_mask                                                   (0x00000003)
#define  GPIO_GPI_DP_gpha(data)                                                  (0x00000003&(data))
#define  GPIO_GPI_DP_get_gpha(data)                                              (0x00000003&(data))

#define  GPIO_ISR_GPI_ASSERT                                                     0x18061150
#define  GPIO_ISR_GPI_ASSERT_reg_addr                                            "0xB8061150"
#define  GPIO_ISR_GPI_ASSERT_reg                                                 0xB8061150
#define  GPIO_ISR_GPI_ASSERT_inst_addr                                           "0x0013"
#define  set_GPIO_ISR_GPI_ASSERT_reg(data)                                       (*((volatile unsigned int*)GPIO_ISR_GPI_ASSERT_reg)=data)
#define  get_GPIO_ISR_GPI_ASSERT_reg                                             (*((volatile unsigned int*)GPIO_ISR_GPI_ASSERT_reg))
#define  GPIO_ISR_GPI_ASSERT_int1_a_shift                                        (1)
#define  GPIO_ISR_GPI_ASSERT_int0_a_shift                                        (0)
#define  GPIO_ISR_GPI_ASSERT_int1_a_mask                                         (0x00000002)
#define  GPIO_ISR_GPI_ASSERT_int0_a_mask                                         (0x00000001)
#define  GPIO_ISR_GPI_ASSERT_int1_a(data)                                        (0x00000002&((data)<<1))
#define  GPIO_ISR_GPI_ASSERT_int0_a(data)                                        (0x00000001&(data))
#define  GPIO_ISR_GPI_ASSERT_get_int1_a(data)                                    ((0x00000002&(data))>>1)
#define  GPIO_ISR_GPI_ASSERT_get_int0_a(data)                                    (0x00000001&(data))

#define  GPIO_ISR_GPI_DEASSERT                                                   0x18061154
#define  GPIO_ISR_GPI_DEASSERT_reg_addr                                          "0xB8061154"
#define  GPIO_ISR_GPI_DEASSERT_reg                                               0xB8061154
#define  GPIO_ISR_GPI_DEASSERT_inst_addr                                         "0x0014"
#define  set_GPIO_ISR_GPI_DEASSERT_reg(data)                                     (*((volatile unsigned int*)GPIO_ISR_GPI_DEASSERT_reg)=data)
#define  get_GPIO_ISR_GPI_DEASSERT_reg                                           (*((volatile unsigned int*)GPIO_ISR_GPI_DEASSERT_reg))
#define  GPIO_ISR_GPI_DEASSERT_int1_da_shift                                     (1)
#define  GPIO_ISR_GPI_DEASSERT_int0_da_shift                                     (0)
#define  GPIO_ISR_GPI_DEASSERT_int1_da_mask                                      (0x00000002)
#define  GPIO_ISR_GPI_DEASSERT_int0_da_mask                                      (0x00000001)
#define  GPIO_ISR_GPI_DEASSERT_int1_da(data)                                     (0x00000002&((data)<<1))
#define  GPIO_ISR_GPI_DEASSERT_int0_da(data)                                     (0x00000001&(data))
#define  GPIO_ISR_GPI_DEASSERT_get_int1_da(data)                                 ((0x00000002&(data))>>1)
#define  GPIO_ISR_GPI_DEASSERT_get_int0_da(data)                                 (0x00000001&(data))

#define  GPIO_GPO_DATO                                                           0x18061158
#define  GPIO_GPO_DATO_reg_addr                                                  "0xB8061158"
#define  GPIO_GPO_DATO_reg                                                       0xB8061158
#define  GPIO_GPO_DATO_inst_addr                                                 "0x0015"
#define  set_GPIO_GPO_DATO_reg(data)                                             (*((volatile unsigned int*)GPIO_GPO_DATO_reg)=data)
#define  get_GPIO_GPO_DATO_reg                                                   (*((volatile unsigned int*)GPIO_GPO_DATO_reg))
#define  GPIO_GPO_DATO_gpdato_shift                                              (0)
#define  GPIO_GPO_DATO_gpdato_mask                                               (0x00000001)
#define  GPIO_GPO_DATO_gpdato(data)                                              (0x00000001&(data))
#define  GPIO_GPO_DATO_get_gpdato(data)                                          (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======GPIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}gpio_gpdir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  gpdir:5;
    };
}gpio_gpdir_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}gpio_gpdato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  gpdato:5;
    };
}gpio_gpdato_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}gpio_gpdati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  gpdati:5;
    };
}gpio_gpdati_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}gpio_gpie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  gp:5;
    };
}gpio_gpie_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}gpio_gpdp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  gpha:5;
    };
}gpio_gpdp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  clk2:3;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  clk1:3;
    };
}gpio_gpdeb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int30_a:1;
        RBus_UInt32  int29_a:1;
        RBus_UInt32  int28_a:1;
        RBus_UInt32  int27_a:1;
        RBus_UInt32  int26_a:1;
        RBus_UInt32  int25_a:1;
        RBus_UInt32  int24_a:1;
        RBus_UInt32  int23_a:1;
        RBus_UInt32  int22_a:1;
        RBus_UInt32  int21_a:1;
        RBus_UInt32  int20_a:1;
        RBus_UInt32  int19_a:1;
        RBus_UInt32  int18_a:1;
        RBus_UInt32  int17_a:1;
        RBus_UInt32  int16_a:1;
        RBus_UInt32  int15_a:1;
        RBus_UInt32  int14_a:1;
        RBus_UInt32  int13_a:1;
        RBus_UInt32  int12_a:1;
        RBus_UInt32  int11_a:1;
        RBus_UInt32  int10_a:1;
        RBus_UInt32  int9_a:1;
        RBus_UInt32  int8_a:1;
        RBus_UInt32  int7_a:1;
        RBus_UInt32  int6_a:1;
        RBus_UInt32  int5_a:1;
        RBus_UInt32  int4_a:1;
        RBus_UInt32  int3_a:1;
        RBus_UInt32  int2_a:1;
        RBus_UInt32  int1_a:1;
        RBus_UInt32  int0_a:1;
        RBus_UInt32  write_data:1;
    };
}gpio_isr_gp_assert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  int36_a:1;
        RBus_UInt32  int35_a:1;
        RBus_UInt32  int34_a:1;
        RBus_UInt32  int33_a:1;
        RBus_UInt32  int32_a:1;
        RBus_UInt32  int31_a:1;
        RBus_UInt32  write_data:1;
    };
}gpio_isr_gp_assert_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int30_da:1;
        RBus_UInt32  int29_da:1;
        RBus_UInt32  int28_da:1;
        RBus_UInt32  int27_da:1;
        RBus_UInt32  int26_da:1;
        RBus_UInt32  int25_da:1;
        RBus_UInt32  int24_da:1;
        RBus_UInt32  int23_da:1;
        RBus_UInt32  int22_da:1;
        RBus_UInt32  int21_da:1;
        RBus_UInt32  int20_da:1;
        RBus_UInt32  int19_da:1;
        RBus_UInt32  int18_da:1;
        RBus_UInt32  int17_da:1;
        RBus_UInt32  int16_da:1;
        RBus_UInt32  int15_da:1;
        RBus_UInt32  int14_da:1;
        RBus_UInt32  int13_da:1;
        RBus_UInt32  int12_da:1;
        RBus_UInt32  int11_da:1;
        RBus_UInt32  int10_da:1;
        RBus_UInt32  int9_da:1;
        RBus_UInt32  int8_da:1;
        RBus_UInt32  int7_da:1;
        RBus_UInt32  int6_da:1;
        RBus_UInt32  int5_da:1;
        RBus_UInt32  int4_da:1;
        RBus_UInt32  int3_da:1;
        RBus_UInt32  int2_da:1;
        RBus_UInt32  int1_da:1;
        RBus_UInt32  int0_da:1;
        RBus_UInt32  write_data:1;
    };
}gpio_isr_gp_deassert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  int36_da:1;
        RBus_UInt32  int35_da:1;
        RBus_UInt32  int34_da:1;
        RBus_UInt32  int33_da:1;
        RBus_UInt32  int32_da:1;
        RBus_UInt32  int31_da:1;
        RBus_UInt32  write_data:1;
    };
}gpio_isr_gp_deassert_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  intsel:2;
    };
}gpio_gp_int_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  gpidati:2;
    };
}gpio_gpi_dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  gp:2;
    };
}gpio_gpi_gpie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  gpha:2;
    };
}gpio_gpi_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  int1_a:1;
        RBus_UInt32  int0_a:1;
    };
}gpio_isr_gpi_assert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  int1_da:1;
        RBus_UInt32  int0_da:1;
    };
}gpio_isr_gpi_deassert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  gpdato:1;
    };
}gpio_gpo_dato_RBUS;

#else //apply LITTLE_ENDIAN

//======GPIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:32;
    };
}gpio_gpdir_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdir:5;
        RBus_UInt32  res1:27;
    };
}gpio_gpdir_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:32;
    };
}gpio_gpdato_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:5;
        RBus_UInt32  res1:27;
    };
}gpio_gpdato_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:32;
    };
}gpio_gpdati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdati:5;
        RBus_UInt32  res1:27;
    };
}gpio_gpdati_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:32;
    };
}gpio_gpie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:5;
        RBus_UInt32  res1:27;
    };
}gpio_gpie_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:32;
    };
}gpio_gpdp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:5;
        RBus_UInt32  res1:27;
    };
}gpio_gpdp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk1:3;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  clk2:3;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  res1:24;
    };
}gpio_gpdeb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int0_a:1;
        RBus_UInt32  int1_a:1;
        RBus_UInt32  int2_a:1;
        RBus_UInt32  int3_a:1;
        RBus_UInt32  int4_a:1;
        RBus_UInt32  int5_a:1;
        RBus_UInt32  int6_a:1;
        RBus_UInt32  int7_a:1;
        RBus_UInt32  int8_a:1;
        RBus_UInt32  int9_a:1;
        RBus_UInt32  int10_a:1;
        RBus_UInt32  int11_a:1;
        RBus_UInt32  int12_a:1;
        RBus_UInt32  int13_a:1;
        RBus_UInt32  int14_a:1;
        RBus_UInt32  int15_a:1;
        RBus_UInt32  int16_a:1;
        RBus_UInt32  int17_a:1;
        RBus_UInt32  int18_a:1;
        RBus_UInt32  int19_a:1;
        RBus_UInt32  int20_a:1;
        RBus_UInt32  int21_a:1;
        RBus_UInt32  int22_a:1;
        RBus_UInt32  int23_a:1;
        RBus_UInt32  int24_a:1;
        RBus_UInt32  int25_a:1;
        RBus_UInt32  int26_a:1;
        RBus_UInt32  int27_a:1;
        RBus_UInt32  int28_a:1;
        RBus_UInt32  int29_a:1;
        RBus_UInt32  int30_a:1;
    };
}gpio_isr_gp_assert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int31_a:1;
        RBus_UInt32  int32_a:1;
        RBus_UInt32  int33_a:1;
        RBus_UInt32  int34_a:1;
        RBus_UInt32  int35_a:1;
        RBus_UInt32  int36_a:1;
        RBus_UInt32  res1:25;
    };
}gpio_isr_gp_assert_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int0_da:1;
        RBus_UInt32  int1_da:1;
        RBus_UInt32  int2_da:1;
        RBus_UInt32  int3_da:1;
        RBus_UInt32  int4_da:1;
        RBus_UInt32  int5_da:1;
        RBus_UInt32  int6_da:1;
        RBus_UInt32  int7_da:1;
        RBus_UInt32  int8_da:1;
        RBus_UInt32  int9_da:1;
        RBus_UInt32  int10_da:1;
        RBus_UInt32  int11_da:1;
        RBus_UInt32  int12_da:1;
        RBus_UInt32  int13_da:1;
        RBus_UInt32  int14_da:1;
        RBus_UInt32  int15_da:1;
        RBus_UInt32  int16_da:1;
        RBus_UInt32  int17_da:1;
        RBus_UInt32  int18_da:1;
        RBus_UInt32  int19_da:1;
        RBus_UInt32  int20_da:1;
        RBus_UInt32  int21_da:1;
        RBus_UInt32  int22_da:1;
        RBus_UInt32  int23_da:1;
        RBus_UInt32  int24_da:1;
        RBus_UInt32  int25_da:1;
        RBus_UInt32  int26_da:1;
        RBus_UInt32  int27_da:1;
        RBus_UInt32  int28_da:1;
        RBus_UInt32  int29_da:1;
        RBus_UInt32  int30_da:1;
    };
}gpio_isr_gp_deassert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  int31_da:1;
        RBus_UInt32  int32_da:1;
        RBus_UInt32  int33_da:1;
        RBus_UInt32  int34_da:1;
        RBus_UInt32  int35_da:1;
        RBus_UInt32  int36_da:1;
        RBus_UInt32  res1:25;
    };
}gpio_isr_gp_deassert_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intsel:2;
        RBus_UInt32  res1:30;
    };
}gpio_gp_int_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpidati:2;
        RBus_UInt32  res1:30;
    };
}gpio_gpi_dati_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gp:2;
        RBus_UInt32  res1:30;
    };
}gpio_gpi_gpie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpha:2;
        RBus_UInt32  res1:30;
    };
}gpio_gpi_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int0_a:1;
        RBus_UInt32  int1_a:1;
        RBus_UInt32  res1:30;
    };
}gpio_isr_gpi_assert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int0_da:1;
        RBus_UInt32  int1_da:1;
        RBus_UInt32  res1:30;
    };
}gpio_isr_gpi_deassert_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpdato:1;
        RBus_UInt32  res1:31;
    };
}gpio_gpo_dato_RBUS;




#endif 


#endif 
