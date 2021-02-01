/**
* @file Mac5-DesignSpec-SE
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SE_REG_H_
#define _RBUS_SE_REG_H_

#include "rbus_types.h"



//  SE Register Address
#define  SE_CMDBASE_0                                                            0x1800C000
#define  SE_CMDBASE_0_reg_addr                                                   "0xB800C000"
#define  SE_CMDBASE_0_reg                                                        0xB800C000
#define  SE_CMDBASE_0_inst_addr                                                  "0x0000"
#define  set_SE_CMDBASE_0_reg(data)                                              (*((volatile unsigned int*)SE_CMDBASE_0_reg)=data)
#define  get_SE_CMDBASE_0_reg                                                    (*((volatile unsigned int*)SE_CMDBASE_0_reg))
#define  SE_CMDBASE_0_base_shift                                                 (4)
#define  SE_CMDBASE_0_base_mask                                                  (0xFFFFFFF0)
#define  SE_CMDBASE_0_base(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDBASE_0_get_base(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDBASE_1                                                            0x1800C004
#define  SE_CMDBASE_1_reg_addr                                                   "0xB800C004"
#define  SE_CMDBASE_1_reg                                                        0xB800C004
#define  SE_CMDBASE_1_inst_addr                                                  "0x0001"
#define  set_SE_CMDBASE_1_reg(data)                                              (*((volatile unsigned int*)SE_CMDBASE_1_reg)=data)
#define  get_SE_CMDBASE_1_reg                                                    (*((volatile unsigned int*)SE_CMDBASE_1_reg))
#define  SE_CMDBASE_1_base_shift                                                 (4)
#define  SE_CMDBASE_1_base_mask                                                  (0xFFFFFFF0)
#define  SE_CMDBASE_1_base(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDBASE_1_get_base(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDLMT_0                                                             0x1800C010
#define  SE_CMDLMT_0_reg_addr                                                    "0xB800C010"
#define  SE_CMDLMT_0_reg                                                         0xB800C010
#define  SE_CMDLMT_0_inst_addr                                                   "0x0002"
#define  set_SE_CMDLMT_0_reg(data)                                               (*((volatile unsigned int*)SE_CMDLMT_0_reg)=data)
#define  get_SE_CMDLMT_0_reg                                                     (*((volatile unsigned int*)SE_CMDLMT_0_reg))
#define  SE_CMDLMT_0_limit_shift                                                 (4)
#define  SE_CMDLMT_0_limit_mask                                                  (0xFFFFFFF0)
#define  SE_CMDLMT_0_limit(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDLMT_0_get_limit(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDLMT_1                                                             0x1800C014
#define  SE_CMDLMT_1_reg_addr                                                    "0xB800C014"
#define  SE_CMDLMT_1_reg                                                         0xB800C014
#define  SE_CMDLMT_1_inst_addr                                                   "0x0003"
#define  set_SE_CMDLMT_1_reg(data)                                               (*((volatile unsigned int*)SE_CMDLMT_1_reg)=data)
#define  get_SE_CMDLMT_1_reg                                                     (*((volatile unsigned int*)SE_CMDLMT_1_reg))
#define  SE_CMDLMT_1_limit_shift                                                 (4)
#define  SE_CMDLMT_1_limit_mask                                                  (0xFFFFFFF0)
#define  SE_CMDLMT_1_limit(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDLMT_1_get_limit(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDRPTR_0                                                            0x1800C020
#define  SE_CMDRPTR_0_reg_addr                                                   "0xB800C020"
#define  SE_CMDRPTR_0_reg                                                        0xB800C020
#define  SE_CMDRPTR_0_inst_addr                                                  "0x0004"
#define  set_SE_CMDRPTR_0_reg(data)                                              (*((volatile unsigned int*)SE_CMDRPTR_0_reg)=data)
#define  get_SE_CMDRPTR_0_reg                                                    (*((volatile unsigned int*)SE_CMDRPTR_0_reg))
#define  SE_CMDRPTR_0_rptr_shift                                                 (4)
#define  SE_CMDRPTR_0_rptr_mask                                                  (0xFFFFFFF0)
#define  SE_CMDRPTR_0_rptr(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDRPTR_0_get_rptr(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDRPTR_1                                                            0x1800C024
#define  SE_CMDRPTR_1_reg_addr                                                   "0xB800C024"
#define  SE_CMDRPTR_1_reg                                                        0xB800C024
#define  SE_CMDRPTR_1_inst_addr                                                  "0x0005"
#define  set_SE_CMDRPTR_1_reg(data)                                              (*((volatile unsigned int*)SE_CMDRPTR_1_reg)=data)
#define  get_SE_CMDRPTR_1_reg                                                    (*((volatile unsigned int*)SE_CMDRPTR_1_reg))
#define  SE_CMDRPTR_1_rptr_shift                                                 (4)
#define  SE_CMDRPTR_1_rptr_mask                                                  (0xFFFFFFF0)
#define  SE_CMDRPTR_1_rptr(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDRPTR_1_get_rptr(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDWPTR_0                                                            0x1800C030
#define  SE_CMDWPTR_0_reg_addr                                                   "0xB800C030"
#define  SE_CMDWPTR_0_reg                                                        0xB800C030
#define  SE_CMDWPTR_0_inst_addr                                                  "0x0006"
#define  set_SE_CMDWPTR_0_reg(data)                                              (*((volatile unsigned int*)SE_CMDWPTR_0_reg)=data)
#define  get_SE_CMDWPTR_0_reg                                                    (*((volatile unsigned int*)SE_CMDWPTR_0_reg))
#define  SE_CMDWPTR_0_wptr_shift                                                 (4)
#define  SE_CMDWPTR_0_wptr_mask                                                  (0xFFFFFFF0)
#define  SE_CMDWPTR_0_wptr(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDWPTR_0_get_wptr(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_CMDWPTR_1                                                            0x1800C034
#define  SE_CMDWPTR_1_reg_addr                                                   "0xB800C034"
#define  SE_CMDWPTR_1_reg                                                        0xB800C034
#define  SE_CMDWPTR_1_inst_addr                                                  "0x0007"
#define  set_SE_CMDWPTR_1_reg(data)                                              (*((volatile unsigned int*)SE_CMDWPTR_1_reg)=data)
#define  get_SE_CMDWPTR_1_reg                                                    (*((volatile unsigned int*)SE_CMDWPTR_1_reg))
#define  SE_CMDWPTR_1_wptr_shift                                                 (4)
#define  SE_CMDWPTR_1_wptr_mask                                                  (0xFFFFFFF0)
#define  SE_CMDWPTR_1_wptr(data)                                                 (0xFFFFFFF0&((data)<<4))
#define  SE_CMDWPTR_1_get_wptr(data)                                             ((0xFFFFFFF0&(data))>>4)

#define  SE_SRWORDCNT_0                                                          0x1800C040
#define  SE_SRWORDCNT_0_reg_addr                                                 "0xB800C040"
#define  SE_SRWORDCNT_0_reg                                                      0xB800C040
#define  SE_SRWORDCNT_0_inst_addr                                                "0x0008"
#define  set_SE_SRWORDCNT_0_reg(data)                                            (*((volatile unsigned int*)SE_SRWORDCNT_0_reg)=data)
#define  get_SE_SRWORDCNT_0_reg                                                  (*((volatile unsigned int*)SE_SRWORDCNT_0_reg))
#define  SE_SRWORDCNT_0_srwordcnt_shift                                          (0)
#define  SE_SRWORDCNT_0_srwordcnt_mask                                           (0x0000007F)
#define  SE_SRWORDCNT_0_srwordcnt(data)                                          (0x0000007F&(data))
#define  SE_SRWORDCNT_0_get_srwordcnt(data)                                      (0x0000007F&(data))

#define  SE_SRWORDCNT_1                                                          0x1800C044
#define  SE_SRWORDCNT_1_reg_addr                                                 "0xB800C044"
#define  SE_SRWORDCNT_1_reg                                                      0xB800C044
#define  SE_SRWORDCNT_1_inst_addr                                                "0x0009"
#define  set_SE_SRWORDCNT_1_reg(data)                                            (*((volatile unsigned int*)SE_SRWORDCNT_1_reg)=data)
#define  get_SE_SRWORDCNT_1_reg                                                  (*((volatile unsigned int*)SE_SRWORDCNT_1_reg))
#define  SE_SRWORDCNT_1_srwordcnt_shift                                          (0)
#define  SE_SRWORDCNT_1_srwordcnt_mask                                           (0x0000007F)
#define  SE_SRWORDCNT_1_srwordcnt(data)                                          (0x0000007F&(data))
#define  SE_SRWORDCNT_1_get_srwordcnt(data)                                      (0x0000007F&(data))

#define  SE_Q_Priority                                                           0x1800C050
#define  SE_Q_Priority_reg_addr                                                  "0xB800C050"
#define  SE_Q_Priority_reg                                                       0xB800C050
#define  SE_Q_Priority_inst_addr                                                 "0x000A"
#define  set_SE_Q_Priority_reg(data)                                             (*((volatile unsigned int*)SE_Q_Priority_reg)=data)
#define  get_SE_Q_Priority_reg                                                   (*((volatile unsigned int*)SE_Q_Priority_reg))
#define  SE_Q_Priority_disable_shift                                             (8)
#define  SE_Q_Priority_pri2_shift                                                (2)
#define  SE_Q_Priority_pri1_shift                                                (0)
#define  SE_Q_Priority_disable_mask                                              (0x00000F00)
#define  SE_Q_Priority_pri2_mask                                                 (0x0000000C)
#define  SE_Q_Priority_pri1_mask                                                 (0x00000003)
#define  SE_Q_Priority_disable(data)                                             (0x00000F00&((data)<<8))
#define  SE_Q_Priority_pri2(data)                                                (0x0000000C&((data)<<2))
#define  SE_Q_Priority_pri1(data)                                                (0x00000003&(data))
#define  SE_Q_Priority_get_disable(data)                                         ((0x00000F00&(data))>>8)
#define  SE_Q_Priority_get_pri2(data)                                            ((0x0000000C&(data))>>2)
#define  SE_Q_Priority_get_pri1(data)                                            (0x00000003&(data))

#define  SE_CLR_FMT_0                                                            0x1800C060
#define  SE_CLR_FMT_0_reg_addr                                                   "0xB800C060"
#define  SE_CLR_FMT_0_reg                                                        0xB800C060
#define  SE_CLR_FMT_0_inst_addr                                                  "0x000B"
#define  set_SE_CLR_FMT_0_reg(data)                                              (*((volatile unsigned int*)SE_CLR_FMT_0_reg)=data)
#define  get_SE_CLR_FMT_0_reg                                                    (*((volatile unsigned int*)SE_CLR_FMT_0_reg))
#define  SE_CLR_FMT_0_write_enable10_shift                                       (22)
#define  SE_CLR_FMT_0_rounding_en_shift                                          (21)
#define  SE_CLR_FMT_0_write_enable8_shift                                        (20)
#define  SE_CLR_FMT_0_big_endian_o_shift                                         (19)
#define  SE_CLR_FMT_0_write_enable7_shift                                        (18)
#define  SE_CLR_FMT_0_big_endian_i2_shift                                        (17)
#define  SE_CLR_FMT_0_write_enable6_shift                                        (16)
#define  SE_CLR_FMT_0_big_endian_i1_shift                                        (15)
#define  SE_CLR_FMT_0_write_enable5_shift                                        (14)
#define  SE_CLR_FMT_0_alpha_loc2_shift                                           (13)
#define  SE_CLR_FMT_0_write_enable2_shift                                        (6)
#define  SE_CLR_FMT_0_alpha_loc_shift                                            (5)
#define  SE_CLR_FMT_0_write_enable1_shift                                        (4)
#define  SE_CLR_FMT_0_format_shift                                               (0)
#define  SE_CLR_FMT_0_write_enable10_mask                                        (0x00400000)
#define  SE_CLR_FMT_0_rounding_en_mask                                           (0x00200000)
#define  SE_CLR_FMT_0_write_enable8_mask                                         (0x00100000)
#define  SE_CLR_FMT_0_big_endian_o_mask                                          (0x00080000)
#define  SE_CLR_FMT_0_write_enable7_mask                                         (0x00040000)
#define  SE_CLR_FMT_0_big_endian_i2_mask                                         (0x00020000)
#define  SE_CLR_FMT_0_write_enable6_mask                                         (0x00010000)
#define  SE_CLR_FMT_0_big_endian_i1_mask                                         (0x00008000)
#define  SE_CLR_FMT_0_write_enable5_mask                                         (0x00004000)
#define  SE_CLR_FMT_0_alpha_loc2_mask                                            (0x00002000)
#define  SE_CLR_FMT_0_write_enable2_mask                                         (0x00000040)
#define  SE_CLR_FMT_0_alpha_loc_mask                                             (0x00000020)
#define  SE_CLR_FMT_0_write_enable1_mask                                         (0x00000010)
#define  SE_CLR_FMT_0_format_mask                                                (0x0000000F)
#define  SE_CLR_FMT_0_write_enable10(data)                                       (0x00400000&((data)<<22))
#define  SE_CLR_FMT_0_rounding_en(data)                                          (0x00200000&((data)<<21))
#define  SE_CLR_FMT_0_write_enable8(data)                                        (0x00100000&((data)<<20))
#define  SE_CLR_FMT_0_big_endian_o(data)                                         (0x00080000&((data)<<19))
#define  SE_CLR_FMT_0_write_enable7(data)                                        (0x00040000&((data)<<18))
#define  SE_CLR_FMT_0_big_endian_i2(data)                                        (0x00020000&((data)<<17))
#define  SE_CLR_FMT_0_write_enable6(data)                                        (0x00010000&((data)<<16))
#define  SE_CLR_FMT_0_big_endian_i1(data)                                        (0x00008000&((data)<<15))
#define  SE_CLR_FMT_0_write_enable5(data)                                        (0x00004000&((data)<<14))
#define  SE_CLR_FMT_0_alpha_loc2(data)                                           (0x00002000&((data)<<13))
#define  SE_CLR_FMT_0_write_enable2(data)                                        (0x00000040&((data)<<6))
#define  SE_CLR_FMT_0_alpha_loc(data)                                            (0x00000020&((data)<<5))
#define  SE_CLR_FMT_0_write_enable1(data)                                        (0x00000010&((data)<<4))
#define  SE_CLR_FMT_0_format(data)                                               (0x0000000F&(data))
#define  SE_CLR_FMT_0_get_write_enable10(data)                                   ((0x00400000&(data))>>22)
#define  SE_CLR_FMT_0_get_rounding_en(data)                                      ((0x00200000&(data))>>21)
#define  SE_CLR_FMT_0_get_write_enable8(data)                                    ((0x00100000&(data))>>20)
#define  SE_CLR_FMT_0_get_big_endian_o(data)                                     ((0x00080000&(data))>>19)
#define  SE_CLR_FMT_0_get_write_enable7(data)                                    ((0x00040000&(data))>>18)
#define  SE_CLR_FMT_0_get_big_endian_i2(data)                                    ((0x00020000&(data))>>17)
#define  SE_CLR_FMT_0_get_write_enable6(data)                                    ((0x00010000&(data))>>16)
#define  SE_CLR_FMT_0_get_big_endian_i1(data)                                    ((0x00008000&(data))>>15)
#define  SE_CLR_FMT_0_get_write_enable5(data)                                    ((0x00004000&(data))>>14)
#define  SE_CLR_FMT_0_get_alpha_loc2(data)                                       ((0x00002000&(data))>>13)
#define  SE_CLR_FMT_0_get_write_enable2(data)                                    ((0x00000040&(data))>>6)
#define  SE_CLR_FMT_0_get_alpha_loc(data)                                        ((0x00000020&(data))>>5)
#define  SE_CLR_FMT_0_get_write_enable1(data)                                    ((0x00000010&(data))>>4)
#define  SE_CLR_FMT_0_get_format(data)                                           (0x0000000F&(data))

#define  SE_CLR_FMT_1                                                            0x1800C064
#define  SE_CLR_FMT_1_reg_addr                                                   "0xB800C064"
#define  SE_CLR_FMT_1_reg                                                        0xB800C064
#define  SE_CLR_FMT_1_inst_addr                                                  "0x000C"
#define  set_SE_CLR_FMT_1_reg(data)                                              (*((volatile unsigned int*)SE_CLR_FMT_1_reg)=data)
#define  get_SE_CLR_FMT_1_reg                                                    (*((volatile unsigned int*)SE_CLR_FMT_1_reg))
#define  SE_CLR_FMT_1_write_enable10_shift                                       (22)
#define  SE_CLR_FMT_1_rounding_en_shift                                          (21)
#define  SE_CLR_FMT_1_write_enable8_shift                                        (20)
#define  SE_CLR_FMT_1_big_endian_o_shift                                         (19)
#define  SE_CLR_FMT_1_write_enable7_shift                                        (18)
#define  SE_CLR_FMT_1_big_endian_i2_shift                                        (17)
#define  SE_CLR_FMT_1_write_enable6_shift                                        (16)
#define  SE_CLR_FMT_1_big_endian_i1_shift                                        (15)
#define  SE_CLR_FMT_1_write_enable5_shift                                        (14)
#define  SE_CLR_FMT_1_alpha_loc2_shift                                           (13)
#define  SE_CLR_FMT_1_write_enable2_shift                                        (6)
#define  SE_CLR_FMT_1_alpha_loc_shift                                            (5)
#define  SE_CLR_FMT_1_write_enable1_shift                                        (4)
#define  SE_CLR_FMT_1_format_shift                                               (0)
#define  SE_CLR_FMT_1_write_enable10_mask                                        (0x00400000)
#define  SE_CLR_FMT_1_rounding_en_mask                                           (0x00200000)
#define  SE_CLR_FMT_1_write_enable8_mask                                         (0x00100000)
#define  SE_CLR_FMT_1_big_endian_o_mask                                          (0x00080000)
#define  SE_CLR_FMT_1_write_enable7_mask                                         (0x00040000)
#define  SE_CLR_FMT_1_big_endian_i2_mask                                         (0x00020000)
#define  SE_CLR_FMT_1_write_enable6_mask                                         (0x00010000)
#define  SE_CLR_FMT_1_big_endian_i1_mask                                         (0x00008000)
#define  SE_CLR_FMT_1_write_enable5_mask                                         (0x00004000)
#define  SE_CLR_FMT_1_alpha_loc2_mask                                            (0x00002000)
#define  SE_CLR_FMT_1_write_enable2_mask                                         (0x00000040)
#define  SE_CLR_FMT_1_alpha_loc_mask                                             (0x00000020)
#define  SE_CLR_FMT_1_write_enable1_mask                                         (0x00000010)
#define  SE_CLR_FMT_1_format_mask                                                (0x0000000F)
#define  SE_CLR_FMT_1_write_enable10(data)                                       (0x00400000&((data)<<22))
#define  SE_CLR_FMT_1_rounding_en(data)                                          (0x00200000&((data)<<21))
#define  SE_CLR_FMT_1_write_enable8(data)                                        (0x00100000&((data)<<20))
#define  SE_CLR_FMT_1_big_endian_o(data)                                         (0x00080000&((data)<<19))
#define  SE_CLR_FMT_1_write_enable7(data)                                        (0x00040000&((data)<<18))
#define  SE_CLR_FMT_1_big_endian_i2(data)                                        (0x00020000&((data)<<17))
#define  SE_CLR_FMT_1_write_enable6(data)                                        (0x00010000&((data)<<16))
#define  SE_CLR_FMT_1_big_endian_i1(data)                                        (0x00008000&((data)<<15))
#define  SE_CLR_FMT_1_write_enable5(data)                                        (0x00004000&((data)<<14))
#define  SE_CLR_FMT_1_alpha_loc2(data)                                           (0x00002000&((data)<<13))
#define  SE_CLR_FMT_1_write_enable2(data)                                        (0x00000040&((data)<<6))
#define  SE_CLR_FMT_1_alpha_loc(data)                                            (0x00000020&((data)<<5))
#define  SE_CLR_FMT_1_write_enable1(data)                                        (0x00000010&((data)<<4))
#define  SE_CLR_FMT_1_format(data)                                               (0x0000000F&(data))
#define  SE_CLR_FMT_1_get_write_enable10(data)                                   ((0x00400000&(data))>>22)
#define  SE_CLR_FMT_1_get_rounding_en(data)                                      ((0x00200000&(data))>>21)
#define  SE_CLR_FMT_1_get_write_enable8(data)                                    ((0x00100000&(data))>>20)
#define  SE_CLR_FMT_1_get_big_endian_o(data)                                     ((0x00080000&(data))>>19)
#define  SE_CLR_FMT_1_get_write_enable7(data)                                    ((0x00040000&(data))>>18)
#define  SE_CLR_FMT_1_get_big_endian_i2(data)                                    ((0x00020000&(data))>>17)
#define  SE_CLR_FMT_1_get_write_enable6(data)                                    ((0x00010000&(data))>>16)
#define  SE_CLR_FMT_1_get_big_endian_i1(data)                                    ((0x00008000&(data))>>15)
#define  SE_CLR_FMT_1_get_write_enable5(data)                                    ((0x00004000&(data))>>14)
#define  SE_CLR_FMT_1_get_alpha_loc2(data)                                       ((0x00002000&(data))>>13)
#define  SE_CLR_FMT_1_get_write_enable2(data)                                    ((0x00000040&(data))>>6)
#define  SE_CLR_FMT_1_get_alpha_loc(data)                                        ((0x00000020&(data))>>5)
#define  SE_CLR_FMT_1_get_write_enable1(data)                                    ((0x00000010&(data))>>4)
#define  SE_CLR_FMT_1_get_format(data)                                           (0x0000000F&(data))

#define  SE_COLOR_KEY_0                                                          0x1800C070
#define  SE_COLOR_KEY_0_reg_addr                                                 "0xB800C070"
#define  SE_COLOR_KEY_0_reg                                                      0xB800C070
#define  SE_COLOR_KEY_0_inst_addr                                                "0x000D"
#define  set_SE_COLOR_KEY_0_reg(data)                                            (*((volatile unsigned int*)SE_COLOR_KEY_0_reg)=data)
#define  get_SE_COLOR_KEY_0_reg                                                  (*((volatile unsigned int*)SE_COLOR_KEY_0_reg))
#define  SE_COLOR_KEY_0_color_key_shift                                          (0)
#define  SE_COLOR_KEY_0_color_key_mask                                           (0x00FFFFFF)
#define  SE_COLOR_KEY_0_color_key(data)                                          (0x00FFFFFF&(data))
#define  SE_COLOR_KEY_0_get_color_key(data)                                      (0x00FFFFFF&(data))

#define  SE_COLOR_KEY_1                                                          0x1800C074
#define  SE_COLOR_KEY_1_reg_addr                                                 "0xB800C074"
#define  SE_COLOR_KEY_1_reg                                                      0xB800C074
#define  SE_COLOR_KEY_1_inst_addr                                                "0x000E"
#define  set_SE_COLOR_KEY_1_reg(data)                                            (*((volatile unsigned int*)SE_COLOR_KEY_1_reg)=data)
#define  get_SE_COLOR_KEY_1_reg                                                  (*((volatile unsigned int*)SE_COLOR_KEY_1_reg))
#define  SE_COLOR_KEY_1_color_key_shift                                          (0)
#define  SE_COLOR_KEY_1_color_key_mask                                           (0x00FFFFFF)
#define  SE_COLOR_KEY_1_color_key(data)                                          (0x00FFFFFF&(data))
#define  SE_COLOR_KEY_1_get_color_key(data)                                      (0x00FFFFFF&(data))

#define  SE_DST_COLOR_KEY_0                                                      0x1800C080
#define  SE_DST_COLOR_KEY_0_reg_addr                                             "0xB800C080"
#define  SE_DST_COLOR_KEY_0_reg                                                  0xB800C080
#define  SE_DST_COLOR_KEY_0_inst_addr                                            "0x000F"
#define  set_SE_DST_COLOR_KEY_0_reg(data)                                        (*((volatile unsigned int*)SE_DST_COLOR_KEY_0_reg)=data)
#define  get_SE_DST_COLOR_KEY_0_reg                                              (*((volatile unsigned int*)SE_DST_COLOR_KEY_0_reg))
#define  SE_DST_COLOR_KEY_0_dst_color_key_shift                                  (0)
#define  SE_DST_COLOR_KEY_0_dst_color_key_mask                                   (0x00FFFFFF)
#define  SE_DST_COLOR_KEY_0_dst_color_key(data)                                  (0x00FFFFFF&(data))
#define  SE_DST_COLOR_KEY_0_get_dst_color_key(data)                              (0x00FFFFFF&(data))

#define  SE_DST_COLOR_KEY_1                                                      0x1800C084
#define  SE_DST_COLOR_KEY_1_reg_addr                                             "0xB800C084"
#define  SE_DST_COLOR_KEY_1_reg                                                  0xB800C084
#define  SE_DST_COLOR_KEY_1_inst_addr                                            "0x0010"
#define  set_SE_DST_COLOR_KEY_1_reg(data)                                        (*((volatile unsigned int*)SE_DST_COLOR_KEY_1_reg)=data)
#define  get_SE_DST_COLOR_KEY_1_reg                                              (*((volatile unsigned int*)SE_DST_COLOR_KEY_1_reg))
#define  SE_DST_COLOR_KEY_1_dst_color_key_shift                                  (0)
#define  SE_DST_COLOR_KEY_1_dst_color_key_mask                                   (0x00FFFFFF)
#define  SE_DST_COLOR_KEY_1_dst_color_key(data)                                  (0x00FFFFFF&(data))
#define  SE_DST_COLOR_KEY_1_get_dst_color_key(data)                              (0x00FFFFFF&(data))

#define  SE_SRC_COLOR_0                                                          0x1800C090
#define  SE_SRC_COLOR_0_reg_addr                                                 "0xB800C090"
#define  SE_SRC_COLOR_0_reg                                                      0xB800C090
#define  SE_SRC_COLOR_0_inst_addr                                                "0x0011"
#define  set_SE_SRC_COLOR_0_reg(data)                                            (*((volatile unsigned int*)SE_SRC_COLOR_0_reg)=data)
#define  get_SE_SRC_COLOR_0_reg                                                  (*((volatile unsigned int*)SE_SRC_COLOR_0_reg))
#define  SE_SRC_COLOR_0_src_color_shift                                          (0)
#define  SE_SRC_COLOR_0_src_color_mask                                           (0xFFFFFFFF)
#define  SE_SRC_COLOR_0_src_color(data)                                          (0xFFFFFFFF&(data))
#define  SE_SRC_COLOR_0_get_src_color(data)                                      (0xFFFFFFFF&(data))

#define  SE_SRC_COLOR_1                                                          0x1800C094
#define  SE_SRC_COLOR_1_reg_addr                                                 "0xB800C094"
#define  SE_SRC_COLOR_1_reg                                                      0xB800C094
#define  SE_SRC_COLOR_1_inst_addr                                                "0x0012"
#define  set_SE_SRC_COLOR_1_reg(data)                                            (*((volatile unsigned int*)SE_SRC_COLOR_1_reg)=data)
#define  get_SE_SRC_COLOR_1_reg                                                  (*((volatile unsigned int*)SE_SRC_COLOR_1_reg))
#define  SE_SRC_COLOR_1_src_color_shift                                          (0)
#define  SE_SRC_COLOR_1_src_color_mask                                           (0xFFFFFFFF)
#define  SE_SRC_COLOR_1_src_color(data)                                          (0xFFFFFFFF&(data))
#define  SE_SRC_COLOR_1_get_src_color(data)                                      (0xFFFFFFFF&(data))

#define  SE_SRC_ALPHA_0                                                          0x1800C0A0
#define  SE_SRC_ALPHA_0_reg_addr                                                 "0xB800C0A0"
#define  SE_SRC_ALPHA_0_reg                                                      0xB800C0A0
#define  SE_SRC_ALPHA_0_inst_addr                                                "0x0013"
#define  set_SE_SRC_ALPHA_0_reg(data)                                            (*((volatile unsigned int*)SE_SRC_ALPHA_0_reg)=data)
#define  get_SE_SRC_ALPHA_0_reg                                                  (*((volatile unsigned int*)SE_SRC_ALPHA_0_reg))
#define  SE_SRC_ALPHA_0_src_alpha_shift                                          (0)
#define  SE_SRC_ALPHA_0_src_alpha_mask                                           (0x000000FF)
#define  SE_SRC_ALPHA_0_src_alpha(data)                                          (0x000000FF&(data))
#define  SE_SRC_ALPHA_0_get_src_alpha(data)                                      (0x000000FF&(data))

#define  SE_SRC_ALPHA_1                                                          0x1800C0A4
#define  SE_SRC_ALPHA_1_reg_addr                                                 "0xB800C0A4"
#define  SE_SRC_ALPHA_1_reg                                                      0xB800C0A4
#define  SE_SRC_ALPHA_1_inst_addr                                                "0x0014"
#define  set_SE_SRC_ALPHA_1_reg(data)                                            (*((volatile unsigned int*)SE_SRC_ALPHA_1_reg)=data)
#define  get_SE_SRC_ALPHA_1_reg                                                  (*((volatile unsigned int*)SE_SRC_ALPHA_1_reg))
#define  SE_SRC_ALPHA_1_src_alpha_shift                                          (0)
#define  SE_SRC_ALPHA_1_src_alpha_mask                                           (0x000000FF)
#define  SE_SRC_ALPHA_1_src_alpha(data)                                          (0x000000FF&(data))
#define  SE_SRC_ALPHA_1_get_src_alpha(data)                                      (0x000000FF&(data))

#define  SE_DEST_ALPHA_0                                                         0x1800C0B0
#define  SE_DEST_ALPHA_0_reg_addr                                                "0xB800C0B0"
#define  SE_DEST_ALPHA_0_reg                                                     0xB800C0B0
#define  SE_DEST_ALPHA_0_inst_addr                                               "0x0015"
#define  set_SE_DEST_ALPHA_0_reg(data)                                           (*((volatile unsigned int*)SE_DEST_ALPHA_0_reg)=data)
#define  get_SE_DEST_ALPHA_0_reg                                                 (*((volatile unsigned int*)SE_DEST_ALPHA_0_reg))
#define  SE_DEST_ALPHA_0_dest_alpha_shift                                        (0)
#define  SE_DEST_ALPHA_0_dest_alpha_mask                                         (0x000000FF)
#define  SE_DEST_ALPHA_0_dest_alpha(data)                                        (0x000000FF&(data))
#define  SE_DEST_ALPHA_0_get_dest_alpha(data)                                    (0x000000FF&(data))

#define  SE_DEST_ALPHA_1                                                         0x1800C0B4
#define  SE_DEST_ALPHA_1_reg_addr                                                "0xB800C0B4"
#define  SE_DEST_ALPHA_1_reg                                                     0xB800C0B4
#define  SE_DEST_ALPHA_1_inst_addr                                               "0x0016"
#define  set_SE_DEST_ALPHA_1_reg(data)                                           (*((volatile unsigned int*)SE_DEST_ALPHA_1_reg)=data)
#define  get_SE_DEST_ALPHA_1_reg                                                 (*((volatile unsigned int*)SE_DEST_ALPHA_1_reg))
#define  SE_DEST_ALPHA_1_dest_alpha_shift                                        (0)
#define  SE_DEST_ALPHA_1_dest_alpha_mask                                         (0x000000FF)
#define  SE_DEST_ALPHA_1_dest_alpha(data)                                        (0x000000FF&(data))
#define  SE_DEST_ALPHA_1_get_dest_alpha(data)                                    (0x000000FF&(data))

#define  SE_RSLT_ALPHA_0                                                         0x1800C0C0
#define  SE_RSLT_ALPHA_0_reg_addr                                                "0xB800C0C0"
#define  SE_RSLT_ALPHA_0_reg                                                     0xB800C0C0
#define  SE_RSLT_ALPHA_0_inst_addr                                               "0x0017"
#define  set_SE_RSLT_ALPHA_0_reg(data)                                           (*((volatile unsigned int*)SE_RSLT_ALPHA_0_reg)=data)
#define  get_SE_RSLT_ALPHA_0_reg                                                 (*((volatile unsigned int*)SE_RSLT_ALPHA_0_reg))
#define  SE_RSLT_ALPHA_0_rslt_alpha_shift                                        (0)
#define  SE_RSLT_ALPHA_0_rslt_alpha_mask                                         (0x000000FF)
#define  SE_RSLT_ALPHA_0_rslt_alpha(data)                                        (0x000000FF&(data))
#define  SE_RSLT_ALPHA_0_get_rslt_alpha(data)                                    (0x000000FF&(data))

#define  SE_RSLT_ALPHA_1                                                         0x1800C0C4
#define  SE_RSLT_ALPHA_1_reg_addr                                                "0xB800C0C4"
#define  SE_RSLT_ALPHA_1_reg                                                     0xB800C0C4
#define  SE_RSLT_ALPHA_1_inst_addr                                               "0x0018"
#define  set_SE_RSLT_ALPHA_1_reg(data)                                           (*((volatile unsigned int*)SE_RSLT_ALPHA_1_reg)=data)
#define  get_SE_RSLT_ALPHA_1_reg                                                 (*((volatile unsigned int*)SE_RSLT_ALPHA_1_reg))
#define  SE_RSLT_ALPHA_1_rslt_alpha_shift                                        (0)
#define  SE_RSLT_ALPHA_1_rslt_alpha_mask                                         (0x000000FF)
#define  SE_RSLT_ALPHA_1_rslt_alpha(data)                                        (0x000000FF&(data))
#define  SE_RSLT_ALPHA_1_get_rslt_alpha(data)                                    (0x000000FF&(data))

#define  SE_BADDR1_0                                                             0x1800C0D0
#define  SE_BADDR1_0_reg_addr                                                    "0xB800C0D0"
#define  SE_BADDR1_0_reg                                                         0xB800C0D0
#define  SE_BADDR1_0_inst_addr                                                   "0x0019"
#define  set_SE_BADDR1_0_reg(data)                                               (*((volatile unsigned int*)SE_BADDR1_0_reg)=data)
#define  get_SE_BADDR1_0_reg                                                     (*((volatile unsigned int*)SE_BADDR1_0_reg))
#define  SE_BADDR1_0_baddr_shift                                                 (0)
#define  SE_BADDR1_0_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR1_0_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR1_0_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_BADDR1_1                                                             0x1800C0D4
#define  SE_BADDR1_1_reg_addr                                                    "0xB800C0D4"
#define  SE_BADDR1_1_reg                                                         0xB800C0D4
#define  SE_BADDR1_1_inst_addr                                                   "0x001A"
#define  set_SE_BADDR1_1_reg(data)                                               (*((volatile unsigned int*)SE_BADDR1_1_reg)=data)
#define  get_SE_BADDR1_1_reg                                                     (*((volatile unsigned int*)SE_BADDR1_1_reg))
#define  SE_BADDR1_1_baddr_shift                                                 (0)
#define  SE_BADDR1_1_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR1_1_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR1_1_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_BADDR1_2                                                             0x1800C0D8
#define  SE_BADDR1_2_reg_addr                                                    "0xB800C0D8"
#define  SE_BADDR1_2_reg                                                         0xB800C0D8
#define  SE_BADDR1_2_inst_addr                                                   "0x001B"
#define  set_SE_BADDR1_2_reg(data)                                               (*((volatile unsigned int*)SE_BADDR1_2_reg)=data)
#define  get_SE_BADDR1_2_reg                                                     (*((volatile unsigned int*)SE_BADDR1_2_reg))
#define  SE_BADDR1_2_baddr_shift                                                 (0)
#define  SE_BADDR1_2_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR1_2_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR1_2_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_BADDR1_3                                                             0x1800C0DC
#define  SE_BADDR1_3_reg_addr                                                    "0xB800C0DC"
#define  SE_BADDR1_3_reg                                                         0xB800C0DC
#define  SE_BADDR1_3_inst_addr                                                   "0x001C"
#define  set_SE_BADDR1_3_reg(data)                                               (*((volatile unsigned int*)SE_BADDR1_3_reg)=data)
#define  get_SE_BADDR1_3_reg                                                     (*((volatile unsigned int*)SE_BADDR1_3_reg))
#define  SE_BADDR1_3_baddr_shift                                                 (0)
#define  SE_BADDR1_3_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR1_3_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR1_3_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_PITCH1_0                                                             0x1800C0E0
#define  SE_PITCH1_0_reg_addr                                                    "0xB800C0E0"
#define  SE_PITCH1_0_reg                                                         0xB800C0E0
#define  SE_PITCH1_0_inst_addr                                                   "0x001D"
#define  set_SE_PITCH1_0_reg(data)                                               (*((volatile unsigned int*)SE_PITCH1_0_reg)=data)
#define  get_SE_PITCH1_0_reg                                                     (*((volatile unsigned int*)SE_PITCH1_0_reg))
#define  SE_PITCH1_0_interleave_shift                                            (16)
#define  SE_PITCH1_0_pitch_shift                                                 (0)
#define  SE_PITCH1_0_interleave_mask                                             (0x00010000)
#define  SE_PITCH1_0_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH1_0_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH1_0_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH1_0_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH1_0_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_PITCH1_1                                                             0x1800C0E4
#define  SE_PITCH1_1_reg_addr                                                    "0xB800C0E4"
#define  SE_PITCH1_1_reg                                                         0xB800C0E4
#define  SE_PITCH1_1_inst_addr                                                   "0x001E"
#define  set_SE_PITCH1_1_reg(data)                                               (*((volatile unsigned int*)SE_PITCH1_1_reg)=data)
#define  get_SE_PITCH1_1_reg                                                     (*((volatile unsigned int*)SE_PITCH1_1_reg))
#define  SE_PITCH1_1_interleave_shift                                            (16)
#define  SE_PITCH1_1_pitch_shift                                                 (0)
#define  SE_PITCH1_1_interleave_mask                                             (0x00010000)
#define  SE_PITCH1_1_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH1_1_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH1_1_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH1_1_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH1_1_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_PITCH1_2                                                             0x1800C0E8
#define  SE_PITCH1_2_reg_addr                                                    "0xB800C0E8"
#define  SE_PITCH1_2_reg                                                         0xB800C0E8
#define  SE_PITCH1_2_inst_addr                                                   "0x001F"
#define  set_SE_PITCH1_2_reg(data)                                               (*((volatile unsigned int*)SE_PITCH1_2_reg)=data)
#define  get_SE_PITCH1_2_reg                                                     (*((volatile unsigned int*)SE_PITCH1_2_reg))
#define  SE_PITCH1_2_interleave_shift                                            (16)
#define  SE_PITCH1_2_pitch_shift                                                 (0)
#define  SE_PITCH1_2_interleave_mask                                             (0x00010000)
#define  SE_PITCH1_2_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH1_2_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH1_2_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH1_2_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH1_2_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_PITCH1_3                                                             0x1800C0EC
#define  SE_PITCH1_3_reg_addr                                                    "0xB800C0EC"
#define  SE_PITCH1_3_reg                                                         0xB800C0EC
#define  SE_PITCH1_3_inst_addr                                                   "0x0020"
#define  set_SE_PITCH1_3_reg(data)                                               (*((volatile unsigned int*)SE_PITCH1_3_reg)=data)
#define  get_SE_PITCH1_3_reg                                                     (*((volatile unsigned int*)SE_PITCH1_3_reg))
#define  SE_PITCH1_3_interleave_shift                                            (16)
#define  SE_PITCH1_3_pitch_shift                                                 (0)
#define  SE_PITCH1_3_interleave_mask                                             (0x00010000)
#define  SE_PITCH1_3_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH1_3_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH1_3_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH1_3_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH1_3_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_BADDR2_0                                                             0x1800C0F0
#define  SE_BADDR2_0_reg_addr                                                    "0xB800C0F0"
#define  SE_BADDR2_0_reg                                                         0xB800C0F0
#define  SE_BADDR2_0_inst_addr                                                   "0x0021"
#define  set_SE_BADDR2_0_reg(data)                                               (*((volatile unsigned int*)SE_BADDR2_0_reg)=data)
#define  get_SE_BADDR2_0_reg                                                     (*((volatile unsigned int*)SE_BADDR2_0_reg))
#define  SE_BADDR2_0_baddr_shift                                                 (0)
#define  SE_BADDR2_0_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR2_0_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR2_0_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_BADDR2_1                                                             0x1800C0F4
#define  SE_BADDR2_1_reg_addr                                                    "0xB800C0F4"
#define  SE_BADDR2_1_reg                                                         0xB800C0F4
#define  SE_BADDR2_1_inst_addr                                                   "0x0022"
#define  set_SE_BADDR2_1_reg(data)                                               (*((volatile unsigned int*)SE_BADDR2_1_reg)=data)
#define  get_SE_BADDR2_1_reg                                                     (*((volatile unsigned int*)SE_BADDR2_1_reg))
#define  SE_BADDR2_1_baddr_shift                                                 (0)
#define  SE_BADDR2_1_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR2_1_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR2_1_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_BADDR2_2                                                             0x1800C0F8
#define  SE_BADDR2_2_reg_addr                                                    "0xB800C0F8"
#define  SE_BADDR2_2_reg                                                         0xB800C0F8
#define  SE_BADDR2_2_inst_addr                                                   "0x0023"
#define  set_SE_BADDR2_2_reg(data)                                               (*((volatile unsigned int*)SE_BADDR2_2_reg)=data)
#define  get_SE_BADDR2_2_reg                                                     (*((volatile unsigned int*)SE_BADDR2_2_reg))
#define  SE_BADDR2_2_baddr_shift                                                 (0)
#define  SE_BADDR2_2_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR2_2_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR2_2_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_BADDR2_3                                                             0x1800C0FC
#define  SE_BADDR2_3_reg_addr                                                    "0xB800C0FC"
#define  SE_BADDR2_3_reg                                                         0xB800C0FC
#define  SE_BADDR2_3_inst_addr                                                   "0x0024"
#define  set_SE_BADDR2_3_reg(data)                                               (*((volatile unsigned int*)SE_BADDR2_3_reg)=data)
#define  get_SE_BADDR2_3_reg                                                     (*((volatile unsigned int*)SE_BADDR2_3_reg))
#define  SE_BADDR2_3_baddr_shift                                                 (0)
#define  SE_BADDR2_3_baddr_mask                                                  (0xFFFFFFFF)
#define  SE_BADDR2_3_baddr(data)                                                 (0xFFFFFFFF&(data))
#define  SE_BADDR2_3_get_baddr(data)                                             (0xFFFFFFFF&(data))

#define  SE_PITCH2_0                                                             0x1800C100
#define  SE_PITCH2_0_reg_addr                                                    "0xB800C100"
#define  SE_PITCH2_0_reg                                                         0xB800C100
#define  SE_PITCH2_0_inst_addr                                                   "0x0025"
#define  set_SE_PITCH2_0_reg(data)                                               (*((volatile unsigned int*)SE_PITCH2_0_reg)=data)
#define  get_SE_PITCH2_0_reg                                                     (*((volatile unsigned int*)SE_PITCH2_0_reg))
#define  SE_PITCH2_0_interleave_shift                                            (16)
#define  SE_PITCH2_0_pitch_shift                                                 (0)
#define  SE_PITCH2_0_interleave_mask                                             (0x00010000)
#define  SE_PITCH2_0_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH2_0_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH2_0_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH2_0_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH2_0_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_PITCH2_1                                                             0x1800C104
#define  SE_PITCH2_1_reg_addr                                                    "0xB800C104"
#define  SE_PITCH2_1_reg                                                         0xB800C104
#define  SE_PITCH2_1_inst_addr                                                   "0x0026"
#define  set_SE_PITCH2_1_reg(data)                                               (*((volatile unsigned int*)SE_PITCH2_1_reg)=data)
#define  get_SE_PITCH2_1_reg                                                     (*((volatile unsigned int*)SE_PITCH2_1_reg))
#define  SE_PITCH2_1_interleave_shift                                            (16)
#define  SE_PITCH2_1_pitch_shift                                                 (0)
#define  SE_PITCH2_1_interleave_mask                                             (0x00010000)
#define  SE_PITCH2_1_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH2_1_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH2_1_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH2_1_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH2_1_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_PITCH2_2                                                             0x1800C108
#define  SE_PITCH2_2_reg_addr                                                    "0xB800C108"
#define  SE_PITCH2_2_reg                                                         0xB800C108
#define  SE_PITCH2_2_inst_addr                                                   "0x0027"
#define  set_SE_PITCH2_2_reg(data)                                               (*((volatile unsigned int*)SE_PITCH2_2_reg)=data)
#define  get_SE_PITCH2_2_reg                                                     (*((volatile unsigned int*)SE_PITCH2_2_reg))
#define  SE_PITCH2_2_interleave_shift                                            (16)
#define  SE_PITCH2_2_pitch_shift                                                 (0)
#define  SE_PITCH2_2_interleave_mask                                             (0x00010000)
#define  SE_PITCH2_2_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH2_2_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH2_2_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH2_2_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH2_2_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_PITCH2_3                                                             0x1800C10C
#define  SE_PITCH2_3_reg_addr                                                    "0xB800C10C"
#define  SE_PITCH2_3_reg                                                         0xB800C10C
#define  SE_PITCH2_3_inst_addr                                                   "0x0028"
#define  set_SE_PITCH2_3_reg(data)                                               (*((volatile unsigned int*)SE_PITCH2_3_reg)=data)
#define  get_SE_PITCH2_3_reg                                                     (*((volatile unsigned int*)SE_PITCH2_3_reg))
#define  SE_PITCH2_3_interleave_shift                                            (16)
#define  SE_PITCH2_3_pitch_shift                                                 (0)
#define  SE_PITCH2_3_interleave_mask                                             (0x00010000)
#define  SE_PITCH2_3_pitch_mask                                                  (0x0000FFFF)
#define  SE_PITCH2_3_interleave(data)                                            (0x00010000&((data)<<16))
#define  SE_PITCH2_3_pitch(data)                                                 (0x0000FFFF&(data))
#define  SE_PITCH2_3_get_interleave(data)                                        ((0x00010000&(data))>>16)
#define  SE_PITCH2_3_get_pitch(data)                                             (0x0000FFFF&(data))

#define  SE_CLUT_LOCK_ST                                                         0x1800C1D0
#define  SE_CLUT_LOCK_ST_reg_addr                                                "0xB800C1D0"
#define  SE_CLUT_LOCK_ST_reg                                                     0xB800C1D0
#define  SE_CLUT_LOCK_ST_inst_addr                                               "0x0029"
#define  set_SE_CLUT_LOCK_ST_reg(data)                                           (*((volatile unsigned int*)SE_CLUT_LOCK_ST_reg)=data)
#define  get_SE_CLUT_LOCK_ST_reg                                                 (*((volatile unsigned int*)SE_CLUT_LOCK_ST_reg))
#define  SE_CLUT_LOCK_ST_clut_lock_st_shift                                      (0)
#define  SE_CLUT_LOCK_ST_clut_lock_st_mask                                       (0x00000007)
#define  SE_CLUT_LOCK_ST_clut_lock_st(data)                                      (0x00000007&(data))
#define  SE_CLUT_LOCK_ST_get_clut_lock_st(data)                                  (0x00000007&(data))

#define  SE_CONVSCALING_0                                                        0x1800C1E0
#define  SE_CONVSCALING_0_reg_addr                                               "0xB800C1E0"
#define  SE_CONVSCALING_0_reg                                                    0xB800C1E0
#define  SE_CONVSCALING_0_inst_addr                                              "0x002A"
#define  set_SE_CONVSCALING_0_reg(data)                                          (*((volatile unsigned int*)SE_CONVSCALING_0_reg)=data)
#define  get_SE_CONVSCALING_0_reg                                                (*((volatile unsigned int*)SE_CONVSCALING_0_reg))
#define  SE_CONVSCALING_0_hdown_shift                                            (3)
#define  SE_CONVSCALING_0_vdown_shift                                            (2)
#define  SE_CONVSCALING_0_hup_shift                                              (1)
#define  SE_CONVSCALING_0_vup_shift                                              (0)
#define  SE_CONVSCALING_0_hdown_mask                                             (0x00000008)
#define  SE_CONVSCALING_0_vdown_mask                                             (0x00000004)
#define  SE_CONVSCALING_0_hup_mask                                               (0x00000002)
#define  SE_CONVSCALING_0_vup_mask                                               (0x00000001)
#define  SE_CONVSCALING_0_hdown(data)                                            (0x00000008&((data)<<3))
#define  SE_CONVSCALING_0_vdown(data)                                            (0x00000004&((data)<<2))
#define  SE_CONVSCALING_0_hup(data)                                              (0x00000002&((data)<<1))
#define  SE_CONVSCALING_0_vup(data)                                              (0x00000001&(data))
#define  SE_CONVSCALING_0_get_hdown(data)                                        ((0x00000008&(data))>>3)
#define  SE_CONVSCALING_0_get_vdown(data)                                        ((0x00000004&(data))>>2)
#define  SE_CONVSCALING_0_get_hup(data)                                          ((0x00000002&(data))>>1)
#define  SE_CONVSCALING_0_get_vup(data)                                          (0x00000001&(data))

#define  SE_CONVSCALING_1                                                        0x1800C1E4
#define  SE_CONVSCALING_1_reg_addr                                               "0xB800C1E4"
#define  SE_CONVSCALING_1_reg                                                    0xB800C1E4
#define  SE_CONVSCALING_1_inst_addr                                              "0x002B"
#define  set_SE_CONVSCALING_1_reg(data)                                          (*((volatile unsigned int*)SE_CONVSCALING_1_reg)=data)
#define  get_SE_CONVSCALING_1_reg                                                (*((volatile unsigned int*)SE_CONVSCALING_1_reg))
#define  SE_CONVSCALING_1_hdown_shift                                            (3)
#define  SE_CONVSCALING_1_vdown_shift                                            (2)
#define  SE_CONVSCALING_1_hup_shift                                              (1)
#define  SE_CONVSCALING_1_vup_shift                                              (0)
#define  SE_CONVSCALING_1_hdown_mask                                             (0x00000008)
#define  SE_CONVSCALING_1_vdown_mask                                             (0x00000004)
#define  SE_CONVSCALING_1_hup_mask                                               (0x00000002)
#define  SE_CONVSCALING_1_vup_mask                                               (0x00000001)
#define  SE_CONVSCALING_1_hdown(data)                                            (0x00000008&((data)<<3))
#define  SE_CONVSCALING_1_vdown(data)                                            (0x00000004&((data)<<2))
#define  SE_CONVSCALING_1_hup(data)                                              (0x00000002&((data)<<1))
#define  SE_CONVSCALING_1_vup(data)                                              (0x00000001&(data))
#define  SE_CONVSCALING_1_get_hdown(data)                                        ((0x00000008&(data))>>3)
#define  SE_CONVSCALING_1_get_vdown(data)                                        ((0x00000004&(data))>>2)
#define  SE_CONVSCALING_1_get_hup(data)                                          ((0x00000002&(data))>>1)
#define  SE_CONVSCALING_1_get_vup(data)                                          (0x00000001&(data))

#define  SE_CONVCOEF1_0                                                          0x1800C1F0
#define  SE_CONVCOEF1_0_reg_addr                                                 "0xB800C1F0"
#define  SE_CONVCOEF1_0_reg                                                      0xB800C1F0
#define  SE_CONVCOEF1_0_inst_addr                                                "0x002C"
#define  set_SE_CONVCOEF1_0_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF1_0_reg)=data)
#define  get_SE_CONVCOEF1_0_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF1_0_reg))
#define  SE_CONVCOEF1_0_m01_shift                                                (13)
#define  SE_CONVCOEF1_0_m00_shift                                                (0)
#define  SE_CONVCOEF1_0_m01_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF1_0_m00_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF1_0_m01(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF1_0_m00(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF1_0_get_m01(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF1_0_get_m00(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF1_1                                                          0x1800C1F4
#define  SE_CONVCOEF1_1_reg_addr                                                 "0xB800C1F4"
#define  SE_CONVCOEF1_1_reg                                                      0xB800C1F4
#define  SE_CONVCOEF1_1_inst_addr                                                "0x002D"
#define  set_SE_CONVCOEF1_1_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF1_1_reg)=data)
#define  get_SE_CONVCOEF1_1_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF1_1_reg))
#define  SE_CONVCOEF1_1_m01_shift                                                (13)
#define  SE_CONVCOEF1_1_m00_shift                                                (0)
#define  SE_CONVCOEF1_1_m01_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF1_1_m00_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF1_1_m01(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF1_1_m00(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF1_1_get_m01(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF1_1_get_m00(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF2_0                                                          0x1800C200
#define  SE_CONVCOEF2_0_reg_addr                                                 "0xB800C200"
#define  SE_CONVCOEF2_0_reg                                                      0xB800C200
#define  SE_CONVCOEF2_0_inst_addr                                                "0x002E"
#define  set_SE_CONVCOEF2_0_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF2_0_reg)=data)
#define  get_SE_CONVCOEF2_0_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF2_0_reg))
#define  SE_CONVCOEF2_0_m10_shift                                                (13)
#define  SE_CONVCOEF2_0_m02_shift                                                (0)
#define  SE_CONVCOEF2_0_m10_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF2_0_m02_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF2_0_m10(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF2_0_m02(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF2_0_get_m10(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF2_0_get_m02(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF2_1                                                          0x1800C204
#define  SE_CONVCOEF2_1_reg_addr                                                 "0xB800C204"
#define  SE_CONVCOEF2_1_reg                                                      0xB800C204
#define  SE_CONVCOEF2_1_inst_addr                                                "0x002F"
#define  set_SE_CONVCOEF2_1_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF2_1_reg)=data)
#define  get_SE_CONVCOEF2_1_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF2_1_reg))
#define  SE_CONVCOEF2_1_m10_shift                                                (13)
#define  SE_CONVCOEF2_1_m02_shift                                                (0)
#define  SE_CONVCOEF2_1_m10_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF2_1_m02_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF2_1_m10(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF2_1_m02(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF2_1_get_m10(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF2_1_get_m02(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF3_0                                                          0x1800C210
#define  SE_CONVCOEF3_0_reg_addr                                                 "0xB800C210"
#define  SE_CONVCOEF3_0_reg                                                      0xB800C210
#define  SE_CONVCOEF3_0_inst_addr                                                "0x0030"
#define  set_SE_CONVCOEF3_0_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF3_0_reg)=data)
#define  get_SE_CONVCOEF3_0_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF3_0_reg))
#define  SE_CONVCOEF3_0_m12_shift                                                (13)
#define  SE_CONVCOEF3_0_m11_shift                                                (0)
#define  SE_CONVCOEF3_0_m12_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF3_0_m11_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF3_0_m12(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF3_0_m11(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF3_0_get_m12(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF3_0_get_m11(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF3_1                                                          0x1800C214
#define  SE_CONVCOEF3_1_reg_addr                                                 "0xB800C214"
#define  SE_CONVCOEF3_1_reg                                                      0xB800C214
#define  SE_CONVCOEF3_1_inst_addr                                                "0x0031"
#define  set_SE_CONVCOEF3_1_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF3_1_reg)=data)
#define  get_SE_CONVCOEF3_1_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF3_1_reg))
#define  SE_CONVCOEF3_1_m12_shift                                                (13)
#define  SE_CONVCOEF3_1_m11_shift                                                (0)
#define  SE_CONVCOEF3_1_m12_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF3_1_m11_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF3_1_m12(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF3_1_m11(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF3_1_get_m12(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF3_1_get_m11(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF4_0                                                          0x1800C220
#define  SE_CONVCOEF4_0_reg_addr                                                 "0xB800C220"
#define  SE_CONVCOEF4_0_reg                                                      0xB800C220
#define  SE_CONVCOEF4_0_inst_addr                                                "0x0032"
#define  set_SE_CONVCOEF4_0_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF4_0_reg)=data)
#define  get_SE_CONVCOEF4_0_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF4_0_reg))
#define  SE_CONVCOEF4_0_m21_shift                                                (13)
#define  SE_CONVCOEF4_0_m20_shift                                                (0)
#define  SE_CONVCOEF4_0_m21_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF4_0_m20_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF4_0_m21(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF4_0_m20(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF4_0_get_m21(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF4_0_get_m20(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF4_1                                                          0x1800C224
#define  SE_CONVCOEF4_1_reg_addr                                                 "0xB800C224"
#define  SE_CONVCOEF4_1_reg                                                      0xB800C224
#define  SE_CONVCOEF4_1_inst_addr                                                "0x0033"
#define  set_SE_CONVCOEF4_1_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF4_1_reg)=data)
#define  get_SE_CONVCOEF4_1_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF4_1_reg))
#define  SE_CONVCOEF4_1_m21_shift                                                (13)
#define  SE_CONVCOEF4_1_m20_shift                                                (0)
#define  SE_CONVCOEF4_1_m21_mask                                                 (0x03FFE000)
#define  SE_CONVCOEF4_1_m20_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF4_1_m21(data)                                                (0x03FFE000&((data)<<13))
#define  SE_CONVCOEF4_1_m20(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF4_1_get_m21(data)                                            ((0x03FFE000&(data))>>13)
#define  SE_CONVCOEF4_1_get_m20(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF5_0                                                          0x1800C230
#define  SE_CONVCOEF5_0_reg_addr                                                 "0xB800C230"
#define  SE_CONVCOEF5_0_reg                                                      0xB800C230
#define  SE_CONVCOEF5_0_inst_addr                                                "0x0034"
#define  set_SE_CONVCOEF5_0_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF5_0_reg)=data)
#define  get_SE_CONVCOEF5_0_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF5_0_reg))
#define  SE_CONVCOEF5_0_m22_shift                                                (0)
#define  SE_CONVCOEF5_0_m22_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF5_0_m22(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF5_0_get_m22(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF5_1                                                          0x1800C234
#define  SE_CONVCOEF5_1_reg_addr                                                 "0xB800C234"
#define  SE_CONVCOEF5_1_reg                                                      0xB800C234
#define  SE_CONVCOEF5_1_inst_addr                                                "0x0035"
#define  set_SE_CONVCOEF5_1_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF5_1_reg)=data)
#define  get_SE_CONVCOEF5_1_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF5_1_reg))
#define  SE_CONVCOEF5_1_m22_shift                                                (0)
#define  SE_CONVCOEF5_1_m22_mask                                                 (0x00001FFF)
#define  SE_CONVCOEF5_1_m22(data)                                                (0x00001FFF&(data))
#define  SE_CONVCOEF5_1_get_m22(data)                                            (0x00001FFF&(data))

#define  SE_CONVCOEF6_0                                                          0x1800C240
#define  SE_CONVCOEF6_0_reg_addr                                                 "0xB800C240"
#define  SE_CONVCOEF6_0_reg                                                      0xB800C240
#define  SE_CONVCOEF6_0_inst_addr                                                "0x0036"
#define  set_SE_CONVCOEF6_0_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF6_0_reg)=data)
#define  get_SE_CONVCOEF6_0_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF6_0_reg))
#define  SE_CONVCOEF6_0_a2_shift                                                 (20)
#define  SE_CONVCOEF6_0_a1_shift                                                 (10)
#define  SE_CONVCOEF6_0_a0_shift                                                 (0)
#define  SE_CONVCOEF6_0_a2_mask                                                  (0x3FF00000)
#define  SE_CONVCOEF6_0_a1_mask                                                  (0x000FFC00)
#define  SE_CONVCOEF6_0_a0_mask                                                  (0x000003FF)
#define  SE_CONVCOEF6_0_a2(data)                                                 (0x3FF00000&((data)<<20))
#define  SE_CONVCOEF6_0_a1(data)                                                 (0x000FFC00&((data)<<10))
#define  SE_CONVCOEF6_0_a0(data)                                                 (0x000003FF&(data))
#define  SE_CONVCOEF6_0_get_a2(data)                                             ((0x3FF00000&(data))>>20)
#define  SE_CONVCOEF6_0_get_a1(data)                                             ((0x000FFC00&(data))>>10)
#define  SE_CONVCOEF6_0_get_a0(data)                                             (0x000003FF&(data))

#define  SE_CONVCOEF6_1                                                          0x1800C244
#define  SE_CONVCOEF6_1_reg_addr                                                 "0xB800C244"
#define  SE_CONVCOEF6_1_reg                                                      0xB800C244
#define  SE_CONVCOEF6_1_inst_addr                                                "0x0037"
#define  set_SE_CONVCOEF6_1_reg(data)                                            (*((volatile unsigned int*)SE_CONVCOEF6_1_reg)=data)
#define  get_SE_CONVCOEF6_1_reg                                                  (*((volatile unsigned int*)SE_CONVCOEF6_1_reg))
#define  SE_CONVCOEF6_1_a2_shift                                                 (20)
#define  SE_CONVCOEF6_1_a1_shift                                                 (10)
#define  SE_CONVCOEF6_1_a0_shift                                                 (0)
#define  SE_CONVCOEF6_1_a2_mask                                                  (0x3FF00000)
#define  SE_CONVCOEF6_1_a1_mask                                                  (0x000FFC00)
#define  SE_CONVCOEF6_1_a0_mask                                                  (0x000003FF)
#define  SE_CONVCOEF6_1_a2(data)                                                 (0x3FF00000&((data)<<20))
#define  SE_CONVCOEF6_1_a1(data)                                                 (0x000FFC00&((data)<<10))
#define  SE_CONVCOEF6_1_a0(data)                                                 (0x000003FF&(data))
#define  SE_CONVCOEF6_1_get_a2(data)                                             ((0x3FF00000&(data))>>20)
#define  SE_CONVCOEF6_1_get_a1(data)                                             ((0x000FFC00&(data))>>10)
#define  SE_CONVCOEF6_1_get_a0(data)                                             (0x000003FF&(data))

#define  SE_FCV_BITBLIT_COLOR_KEY_0                                              0x1800C250
#define  SE_FCV_BITBLIT_COLOR_KEY_0_reg_addr                                     "0xB800C250"
#define  SE_FCV_BITBLIT_COLOR_KEY_0_reg                                          0xB800C250
#define  SE_FCV_BITBLIT_COLOR_KEY_0_inst_addr                                    "0x0038"
#define  set_SE_FCV_BITBLIT_COLOR_KEY_0_reg(data)                                (*((volatile unsigned int*)SE_FCV_BITBLIT_COLOR_KEY_0_reg)=data)
#define  get_SE_FCV_BITBLIT_COLOR_KEY_0_reg                                      (*((volatile unsigned int*)SE_FCV_BITBLIT_COLOR_KEY_0_reg))
#define  SE_FCV_BITBLIT_COLOR_KEY_0_color_key_shift                              (0)
#define  SE_FCV_BITBLIT_COLOR_KEY_0_color_key_mask                               (0x00FFFFFF)
#define  SE_FCV_BITBLIT_COLOR_KEY_0_color_key(data)                              (0x00FFFFFF&(data))
#define  SE_FCV_BITBLIT_COLOR_KEY_0_get_color_key(data)                          (0x00FFFFFF&(data))

#define  SE_FCV_BITBLIT_COLOR_KEY_1                                              0x1800C254
#define  SE_FCV_BITBLIT_COLOR_KEY_1_reg_addr                                     "0xB800C254"
#define  SE_FCV_BITBLIT_COLOR_KEY_1_reg                                          0xB800C254
#define  SE_FCV_BITBLIT_COLOR_KEY_1_inst_addr                                    "0x0039"
#define  set_SE_FCV_BITBLIT_COLOR_KEY_1_reg(data)                                (*((volatile unsigned int*)SE_FCV_BITBLIT_COLOR_KEY_1_reg)=data)
#define  get_SE_FCV_BITBLIT_COLOR_KEY_1_reg                                      (*((volatile unsigned int*)SE_FCV_BITBLIT_COLOR_KEY_1_reg))
#define  SE_FCV_BITBLIT_COLOR_KEY_1_color_key_shift                              (0)
#define  SE_FCV_BITBLIT_COLOR_KEY_1_color_key_mask                               (0x00FFFFFF)
#define  SE_FCV_BITBLIT_COLOR_KEY_1_color_key(data)                              (0x00FFFFFF&(data))
#define  SE_FCV_BITBLIT_COLOR_KEY_1_get_color_key(data)                          (0x00FFFFFF&(data))

#define  SE_SRC_CLR_RED_0                                                        0x1800C260
#define  SE_SRC_CLR_RED_0_reg_addr                                               "0xB800C260"
#define  SE_SRC_CLR_RED_0_reg                                                    0xB800C260
#define  SE_SRC_CLR_RED_0_inst_addr                                              "0x003A"
#define  set_SE_SRC_CLR_RED_0_reg(data)                                          (*((volatile unsigned int*)SE_SRC_CLR_RED_0_reg)=data)
#define  get_SE_SRC_CLR_RED_0_reg                                                (*((volatile unsigned int*)SE_SRC_CLR_RED_0_reg))
#define  SE_SRC_CLR_RED_0_src_clr_add_red_shift                                  (16)
#define  SE_SRC_CLR_RED_0_src_clr_mul_red_shift                                  (0)
#define  SE_SRC_CLR_RED_0_src_clr_add_red_mask                                   (0x01FF0000)
#define  SE_SRC_CLR_RED_0_src_clr_mul_red_mask                                   (0x000001FF)
#define  SE_SRC_CLR_RED_0_src_clr_add_red(data)                                  (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_RED_0_src_clr_mul_red(data)                                  (0x000001FF&(data))
#define  SE_SRC_CLR_RED_0_get_src_clr_add_red(data)                              ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_RED_0_get_src_clr_mul_red(data)                              (0x000001FF&(data))

#define  SE_SRC_CLR_RED_1                                                        0x1800C264
#define  SE_SRC_CLR_RED_1_reg_addr                                               "0xB800C264"
#define  SE_SRC_CLR_RED_1_reg                                                    0xB800C264
#define  SE_SRC_CLR_RED_1_inst_addr                                              "0x003B"
#define  set_SE_SRC_CLR_RED_1_reg(data)                                          (*((volatile unsigned int*)SE_SRC_CLR_RED_1_reg)=data)
#define  get_SE_SRC_CLR_RED_1_reg                                                (*((volatile unsigned int*)SE_SRC_CLR_RED_1_reg))
#define  SE_SRC_CLR_RED_1_src_clr_add_red_shift                                  (16)
#define  SE_SRC_CLR_RED_1_src_clr_mul_red_shift                                  (0)
#define  SE_SRC_CLR_RED_1_src_clr_add_red_mask                                   (0x01FF0000)
#define  SE_SRC_CLR_RED_1_src_clr_mul_red_mask                                   (0x000001FF)
#define  SE_SRC_CLR_RED_1_src_clr_add_red(data)                                  (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_RED_1_src_clr_mul_red(data)                                  (0x000001FF&(data))
#define  SE_SRC_CLR_RED_1_get_src_clr_add_red(data)                              ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_RED_1_get_src_clr_mul_red(data)                              (0x000001FF&(data))

#define  SE_SRC_CLR_GREEN_0                                                      0x1800C270
#define  SE_SRC_CLR_GREEN_0_reg_addr                                             "0xB800C270"
#define  SE_SRC_CLR_GREEN_0_reg                                                  0xB800C270
#define  SE_SRC_CLR_GREEN_0_inst_addr                                            "0x003C"
#define  set_SE_SRC_CLR_GREEN_0_reg(data)                                        (*((volatile unsigned int*)SE_SRC_CLR_GREEN_0_reg)=data)
#define  get_SE_SRC_CLR_GREEN_0_reg                                              (*((volatile unsigned int*)SE_SRC_CLR_GREEN_0_reg))
#define  SE_SRC_CLR_GREEN_0_src_clr_add_green_shift                              (16)
#define  SE_SRC_CLR_GREEN_0_src_clr_mul_green_shift                              (0)
#define  SE_SRC_CLR_GREEN_0_src_clr_add_green_mask                               (0x01FF0000)
#define  SE_SRC_CLR_GREEN_0_src_clr_mul_green_mask                               (0x000001FF)
#define  SE_SRC_CLR_GREEN_0_src_clr_add_green(data)                              (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_GREEN_0_src_clr_mul_green(data)                              (0x000001FF&(data))
#define  SE_SRC_CLR_GREEN_0_get_src_clr_add_green(data)                          ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_GREEN_0_get_src_clr_mul_green(data)                          (0x000001FF&(data))

#define  SE_SRC_CLR_GREEN_1                                                      0x1800C274
#define  SE_SRC_CLR_GREEN_1_reg_addr                                             "0xB800C274"
#define  SE_SRC_CLR_GREEN_1_reg                                                  0xB800C274
#define  SE_SRC_CLR_GREEN_1_inst_addr                                            "0x003D"
#define  set_SE_SRC_CLR_GREEN_1_reg(data)                                        (*((volatile unsigned int*)SE_SRC_CLR_GREEN_1_reg)=data)
#define  get_SE_SRC_CLR_GREEN_1_reg                                              (*((volatile unsigned int*)SE_SRC_CLR_GREEN_1_reg))
#define  SE_SRC_CLR_GREEN_1_src_clr_add_green_shift                              (16)
#define  SE_SRC_CLR_GREEN_1_src_clr_mul_green_shift                              (0)
#define  SE_SRC_CLR_GREEN_1_src_clr_add_green_mask                               (0x01FF0000)
#define  SE_SRC_CLR_GREEN_1_src_clr_mul_green_mask                               (0x000001FF)
#define  SE_SRC_CLR_GREEN_1_src_clr_add_green(data)                              (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_GREEN_1_src_clr_mul_green(data)                              (0x000001FF&(data))
#define  SE_SRC_CLR_GREEN_1_get_src_clr_add_green(data)                          ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_GREEN_1_get_src_clr_mul_green(data)                          (0x000001FF&(data))

#define  SE_SRC_CLR_BLUE_0                                                       0x1800C280
#define  SE_SRC_CLR_BLUE_0_reg_addr                                              "0xB800C280"
#define  SE_SRC_CLR_BLUE_0_reg                                                   0xB800C280
#define  SE_SRC_CLR_BLUE_0_inst_addr                                             "0x003E"
#define  set_SE_SRC_CLR_BLUE_0_reg(data)                                         (*((volatile unsigned int*)SE_SRC_CLR_BLUE_0_reg)=data)
#define  get_SE_SRC_CLR_BLUE_0_reg                                               (*((volatile unsigned int*)SE_SRC_CLR_BLUE_0_reg))
#define  SE_SRC_CLR_BLUE_0_src_clr_add_blue_shift                                (16)
#define  SE_SRC_CLR_BLUE_0_src_clr_mul_blue_shift                                (0)
#define  SE_SRC_CLR_BLUE_0_src_clr_add_blue_mask                                 (0x01FF0000)
#define  SE_SRC_CLR_BLUE_0_src_clr_mul_blue_mask                                 (0x000001FF)
#define  SE_SRC_CLR_BLUE_0_src_clr_add_blue(data)                                (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_BLUE_0_src_clr_mul_blue(data)                                (0x000001FF&(data))
#define  SE_SRC_CLR_BLUE_0_get_src_clr_add_blue(data)                            ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_BLUE_0_get_src_clr_mul_blue(data)                            (0x000001FF&(data))

#define  SE_SRC_CLR_BLUE_1                                                       0x1800C284
#define  SE_SRC_CLR_BLUE_1_reg_addr                                              "0xB800C284"
#define  SE_SRC_CLR_BLUE_1_reg                                                   0xB800C284
#define  SE_SRC_CLR_BLUE_1_inst_addr                                             "0x003F"
#define  set_SE_SRC_CLR_BLUE_1_reg(data)                                         (*((volatile unsigned int*)SE_SRC_CLR_BLUE_1_reg)=data)
#define  get_SE_SRC_CLR_BLUE_1_reg                                               (*((volatile unsigned int*)SE_SRC_CLR_BLUE_1_reg))
#define  SE_SRC_CLR_BLUE_1_src_clr_add_blue_shift                                (16)
#define  SE_SRC_CLR_BLUE_1_src_clr_mul_blue_shift                                (0)
#define  SE_SRC_CLR_BLUE_1_src_clr_add_blue_mask                                 (0x01FF0000)
#define  SE_SRC_CLR_BLUE_1_src_clr_mul_blue_mask                                 (0x000001FF)
#define  SE_SRC_CLR_BLUE_1_src_clr_add_blue(data)                                (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_BLUE_1_src_clr_mul_blue(data)                                (0x000001FF&(data))
#define  SE_SRC_CLR_BLUE_1_get_src_clr_add_blue(data)                            ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_BLUE_1_get_src_clr_mul_blue(data)                            (0x000001FF&(data))

#define  SE_SRC_CLR_ALPHA_0                                                      0x1800C290
#define  SE_SRC_CLR_ALPHA_0_reg_addr                                             "0xB800C290"
#define  SE_SRC_CLR_ALPHA_0_reg                                                  0xB800C290
#define  SE_SRC_CLR_ALPHA_0_inst_addr                                            "0x0040"
#define  set_SE_SRC_CLR_ALPHA_0_reg(data)                                        (*((volatile unsigned int*)SE_SRC_CLR_ALPHA_0_reg)=data)
#define  get_SE_SRC_CLR_ALPHA_0_reg                                              (*((volatile unsigned int*)SE_SRC_CLR_ALPHA_0_reg))
#define  SE_SRC_CLR_ALPHA_0_src_clr_add_alpha_shift                              (16)
#define  SE_SRC_CLR_ALPHA_0_src_clr_mul_alpha_shift                              (0)
#define  SE_SRC_CLR_ALPHA_0_src_clr_add_alpha_mask                               (0x01FF0000)
#define  SE_SRC_CLR_ALPHA_0_src_clr_mul_alpha_mask                               (0x000001FF)
#define  SE_SRC_CLR_ALPHA_0_src_clr_add_alpha(data)                              (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_ALPHA_0_src_clr_mul_alpha(data)                              (0x000001FF&(data))
#define  SE_SRC_CLR_ALPHA_0_get_src_clr_add_alpha(data)                          ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_ALPHA_0_get_src_clr_mul_alpha(data)                          (0x000001FF&(data))

#define  SE_SRC_CLR_ALPHA_1                                                      0x1800C294
#define  SE_SRC_CLR_ALPHA_1_reg_addr                                             "0xB800C294"
#define  SE_SRC_CLR_ALPHA_1_reg                                                  0xB800C294
#define  SE_SRC_CLR_ALPHA_1_inst_addr                                            "0x0041"
#define  set_SE_SRC_CLR_ALPHA_1_reg(data)                                        (*((volatile unsigned int*)SE_SRC_CLR_ALPHA_1_reg)=data)
#define  get_SE_SRC_CLR_ALPHA_1_reg                                              (*((volatile unsigned int*)SE_SRC_CLR_ALPHA_1_reg))
#define  SE_SRC_CLR_ALPHA_1_src_clr_add_alpha_shift                              (16)
#define  SE_SRC_CLR_ALPHA_1_src_clr_mul_alpha_shift                              (0)
#define  SE_SRC_CLR_ALPHA_1_src_clr_add_alpha_mask                               (0x01FF0000)
#define  SE_SRC_CLR_ALPHA_1_src_clr_mul_alpha_mask                               (0x000001FF)
#define  SE_SRC_CLR_ALPHA_1_src_clr_add_alpha(data)                              (0x01FF0000&((data)<<16))
#define  SE_SRC_CLR_ALPHA_1_src_clr_mul_alpha(data)                              (0x000001FF&(data))
#define  SE_SRC_CLR_ALPHA_1_get_src_clr_add_alpha(data)                          ((0x01FF0000&(data))>>16)
#define  SE_SRC_CLR_ALPHA_1_get_src_clr_mul_alpha(data)                          (0x000001FF&(data))

#define  SE_SYNC_VO_MARGIN_0                                                     0x1800C2A0
#define  SE_SYNC_VO_MARGIN_0_reg_addr                                            "0xB800C2A0"
#define  SE_SYNC_VO_MARGIN_0_reg                                                 0xB800C2A0
#define  SE_SYNC_VO_MARGIN_0_inst_addr                                           "0x0042"
#define  set_SE_SYNC_VO_MARGIN_0_reg(data)                                       (*((volatile unsigned int*)SE_SYNC_VO_MARGIN_0_reg)=data)
#define  get_SE_SYNC_VO_MARGIN_0_reg                                             (*((volatile unsigned int*)SE_SYNC_VO_MARGIN_0_reg))
#define  SE_SYNC_VO_MARGIN_0_auto_dir_en_shift                                   (31)
#define  SE_SYNC_VO_MARGIN_0_vo_plane_shift                                      (30)
#define  SE_SYNC_VO_MARGIN_0_before_vo_cur_shift                                 (29)
#define  SE_SYNC_VO_MARGIN_0_after_vo_cur_shift                                  (28)
#define  SE_SYNC_VO_MARGIN_0_vbi_shift                                           (27)
#define  SE_SYNC_VO_MARGIN_0_margin_votose_shift                                 (0)
#define  SE_SYNC_VO_MARGIN_0_auto_dir_en_mask                                    (0x80000000)
#define  SE_SYNC_VO_MARGIN_0_vo_plane_mask                                       (0x40000000)
#define  SE_SYNC_VO_MARGIN_0_before_vo_cur_mask                                  (0x20000000)
#define  SE_SYNC_VO_MARGIN_0_after_vo_cur_mask                                   (0x10000000)
#define  SE_SYNC_VO_MARGIN_0_vbi_mask                                            (0x08000000)
#define  SE_SYNC_VO_MARGIN_0_margin_votose_mask                                  (0x00000FFF)
#define  SE_SYNC_VO_MARGIN_0_auto_dir_en(data)                                   (0x80000000&((data)<<31))
#define  SE_SYNC_VO_MARGIN_0_vo_plane(data)                                      (0x40000000&((data)<<30))
#define  SE_SYNC_VO_MARGIN_0_before_vo_cur(data)                                 (0x20000000&((data)<<29))
#define  SE_SYNC_VO_MARGIN_0_after_vo_cur(data)                                  (0x10000000&((data)<<28))
#define  SE_SYNC_VO_MARGIN_0_vbi(data)                                           (0x08000000&((data)<<27))
#define  SE_SYNC_VO_MARGIN_0_margin_votose(data)                                 (0x00000FFF&(data))
#define  SE_SYNC_VO_MARGIN_0_get_auto_dir_en(data)                               ((0x80000000&(data))>>31)
#define  SE_SYNC_VO_MARGIN_0_get_vo_plane(data)                                  ((0x40000000&(data))>>30)
#define  SE_SYNC_VO_MARGIN_0_get_before_vo_cur(data)                             ((0x20000000&(data))>>29)
#define  SE_SYNC_VO_MARGIN_0_get_after_vo_cur(data)                              ((0x10000000&(data))>>28)
#define  SE_SYNC_VO_MARGIN_0_get_vbi(data)                                       ((0x08000000&(data))>>27)
#define  SE_SYNC_VO_MARGIN_0_get_margin_votose(data)                             (0x00000FFF&(data))

#define  SE_SYNC_VO_MARGIN_1                                                     0x1800C2A4
#define  SE_SYNC_VO_MARGIN_1_reg_addr                                            "0xB800C2A4"
#define  SE_SYNC_VO_MARGIN_1_reg                                                 0xB800C2A4
#define  SE_SYNC_VO_MARGIN_1_inst_addr                                           "0x0043"
#define  set_SE_SYNC_VO_MARGIN_1_reg(data)                                       (*((volatile unsigned int*)SE_SYNC_VO_MARGIN_1_reg)=data)
#define  get_SE_SYNC_VO_MARGIN_1_reg                                             (*((volatile unsigned int*)SE_SYNC_VO_MARGIN_1_reg))
#define  SE_SYNC_VO_MARGIN_1_auto_dir_en_shift                                   (31)
#define  SE_SYNC_VO_MARGIN_1_vo_plane_shift                                      (30)
#define  SE_SYNC_VO_MARGIN_1_before_vo_cur_shift                                 (29)
#define  SE_SYNC_VO_MARGIN_1_after_vo_cur_shift                                  (28)
#define  SE_SYNC_VO_MARGIN_1_vbi_shift                                           (27)
#define  SE_SYNC_VO_MARGIN_1_margin_votose_shift                                 (0)
#define  SE_SYNC_VO_MARGIN_1_auto_dir_en_mask                                    (0x80000000)
#define  SE_SYNC_VO_MARGIN_1_vo_plane_mask                                       (0x40000000)
#define  SE_SYNC_VO_MARGIN_1_before_vo_cur_mask                                  (0x20000000)
#define  SE_SYNC_VO_MARGIN_1_after_vo_cur_mask                                   (0x10000000)
#define  SE_SYNC_VO_MARGIN_1_vbi_mask                                            (0x08000000)
#define  SE_SYNC_VO_MARGIN_1_margin_votose_mask                                  (0x00000FFF)
#define  SE_SYNC_VO_MARGIN_1_auto_dir_en(data)                                   (0x80000000&((data)<<31))
#define  SE_SYNC_VO_MARGIN_1_vo_plane(data)                                      (0x40000000&((data)<<30))
#define  SE_SYNC_VO_MARGIN_1_before_vo_cur(data)                                 (0x20000000&((data)<<29))
#define  SE_SYNC_VO_MARGIN_1_after_vo_cur(data)                                  (0x10000000&((data)<<28))
#define  SE_SYNC_VO_MARGIN_1_vbi(data)                                           (0x08000000&((data)<<27))
#define  SE_SYNC_VO_MARGIN_1_margin_votose(data)                                 (0x00000FFF&(data))
#define  SE_SYNC_VO_MARGIN_1_get_auto_dir_en(data)                               ((0x80000000&(data))>>31)
#define  SE_SYNC_VO_MARGIN_1_get_vo_plane(data)                                  ((0x40000000&(data))>>30)
#define  SE_SYNC_VO_MARGIN_1_get_before_vo_cur(data)                             ((0x20000000&(data))>>29)
#define  SE_SYNC_VO_MARGIN_1_get_after_vo_cur(data)                              ((0x10000000&(data))>>28)
#define  SE_SYNC_VO_MARGIN_1_get_vbi(data)                                       ((0x08000000&(data))>>27)
#define  SE_SYNC_VO_MARGIN_1_get_margin_votose(data)                             (0x00000FFF&(data))

#define  SE_SYNC_VO_LOCATION_0                                                   0x1800C2B0
#define  SE_SYNC_VO_LOCATION_0_reg_addr                                          "0xB800C2B0"
#define  SE_SYNC_VO_LOCATION_0_reg                                               0xB800C2B0
#define  SE_SYNC_VO_LOCATION_0_inst_addr                                         "0x0044"
#define  set_SE_SYNC_VO_LOCATION_0_reg(data)                                     (*((volatile unsigned int*)SE_SYNC_VO_LOCATION_0_reg)=data)
#define  get_SE_SYNC_VO_LOCATION_0_reg                                           (*((volatile unsigned int*)SE_SYNC_VO_LOCATION_0_reg))
#define  SE_SYNC_VO_LOCATION_0_vo_current_y_shift                                (0)
#define  SE_SYNC_VO_LOCATION_0_vo_current_y_mask                                 (0x00003FFF)
#define  SE_SYNC_VO_LOCATION_0_vo_current_y(data)                                (0x00003FFF&(data))
#define  SE_SYNC_VO_LOCATION_0_get_vo_current_y(data)                            (0x00003FFF&(data))

#define  SE_SYNC_VO_LOCATION_1                                                   0x1800C2B4
#define  SE_SYNC_VO_LOCATION_1_reg_addr                                          "0xB800C2B4"
#define  SE_SYNC_VO_LOCATION_1_reg                                               0xB800C2B4
#define  SE_SYNC_VO_LOCATION_1_inst_addr                                         "0x0045"
#define  set_SE_SYNC_VO_LOCATION_1_reg(data)                                     (*((volatile unsigned int*)SE_SYNC_VO_LOCATION_1_reg)=data)
#define  get_SE_SYNC_VO_LOCATION_1_reg                                           (*((volatile unsigned int*)SE_SYNC_VO_LOCATION_1_reg))
#define  SE_SYNC_VO_LOCATION_1_vo_current_y_shift                                (0)
#define  SE_SYNC_VO_LOCATION_1_vo_current_y_mask                                 (0x00003FFF)
#define  SE_SYNC_VO_LOCATION_1_vo_current_y(data)                                (0x00003FFF&(data))
#define  SE_SYNC_VO_LOCATION_1_get_vo_current_y(data)                            (0x00003FFF&(data))

#define  SE_FB_COLORALPHA_0                                                      0x1800CB50
#define  SE_FB_COLORALPHA_0_reg_addr                                             "0xB800CB50"
#define  SE_FB_COLORALPHA_0_reg                                                  0xB800CB50
#define  SE_FB_COLORALPHA_0_inst_addr                                            "0x0046"
#define  set_SE_FB_COLORALPHA_0_reg(data)                                        (*((volatile unsigned int*)SE_FB_COLORALPHA_0_reg)=data)
#define  get_SE_FB_COLORALPHA_0_reg                                              (*((volatile unsigned int*)SE_FB_COLORALPHA_0_reg))
#define  SE_FB_COLORALPHA_0_color_alpha_shift                                    (0)
#define  SE_FB_COLORALPHA_0_color_alpha_mask                                     (0x000000FF)
#define  SE_FB_COLORALPHA_0_color_alpha(data)                                    (0x000000FF&(data))
#define  SE_FB_COLORALPHA_0_get_color_alpha(data)                                (0x000000FF&(data))

#define  SE_FB_COLORALPHA_1                                                      0x1800CB54
#define  SE_FB_COLORALPHA_1_reg_addr                                             "0xB800CB54"
#define  SE_FB_COLORALPHA_1_reg                                                  0xB800CB54
#define  SE_FB_COLORALPHA_1_inst_addr                                            "0x0047"
#define  set_SE_FB_COLORALPHA_1_reg(data)                                        (*((volatile unsigned int*)SE_FB_COLORALPHA_1_reg)=data)
#define  get_SE_FB_COLORALPHA_1_reg                                              (*((volatile unsigned int*)SE_FB_COLORALPHA_1_reg))
#define  SE_FB_COLORALPHA_1_color_alpha_shift                                    (0)
#define  SE_FB_COLORALPHA_1_color_alpha_mask                                     (0x000000FF)
#define  SE_FB_COLORALPHA_1_color_alpha(data)                                    (0x000000FF&(data))
#define  SE_FB_COLORALPHA_1_get_color_alpha(data)                                (0x000000FF&(data))

#define  SE_STRETCH_0                                                            0x1800C2C0
#define  SE_STRETCH_0_reg_addr                                                   "0xB800C2C0"
#define  SE_STRETCH_0_reg                                                        0xB800C2C0
#define  SE_STRETCH_0_inst_addr                                                  "0x0048"
#define  set_SE_STRETCH_0_reg(data)                                              (*((volatile unsigned int*)SE_STRETCH_0_reg)=data)
#define  get_SE_STRETCH_0_reg                                                    (*((volatile unsigned int*)SE_STRETCH_0_reg))
#define  SE_STRETCH_0_repl_alpha_shift                                           (7)
#define  SE_STRETCH_0_repl_color_shift                                           (6)
#define  SE_STRETCH_0_ref_alpha_shift                                            (5)
#define  SE_STRETCH_0_htype_shift                                                (3)
#define  SE_STRETCH_0_vtype_shift                                                (2)
#define  SE_STRETCH_0_hodd_shift                                                 (1)
#define  SE_STRETCH_0_vodd_shift                                                 (0)
#define  SE_STRETCH_0_repl_alpha_mask                                            (0x00000080)
#define  SE_STRETCH_0_repl_color_mask                                            (0x00000040)
#define  SE_STRETCH_0_ref_alpha_mask                                             (0x00000020)
#define  SE_STRETCH_0_htype_mask                                                 (0x00000018)
#define  SE_STRETCH_0_vtype_mask                                                 (0x00000004)
#define  SE_STRETCH_0_hodd_mask                                                  (0x00000002)
#define  SE_STRETCH_0_vodd_mask                                                  (0x00000001)
#define  SE_STRETCH_0_repl_alpha(data)                                           (0x00000080&((data)<<7))
#define  SE_STRETCH_0_repl_color(data)                                           (0x00000040&((data)<<6))
#define  SE_STRETCH_0_ref_alpha(data)                                            (0x00000020&((data)<<5))
#define  SE_STRETCH_0_htype(data)                                                (0x00000018&((data)<<3))
#define  SE_STRETCH_0_vtype(data)                                                (0x00000004&((data)<<2))
#define  SE_STRETCH_0_hodd(data)                                                 (0x00000002&((data)<<1))
#define  SE_STRETCH_0_vodd(data)                                                 (0x00000001&(data))
#define  SE_STRETCH_0_get_repl_alpha(data)                                       ((0x00000080&(data))>>7)
#define  SE_STRETCH_0_get_repl_color(data)                                       ((0x00000040&(data))>>6)
#define  SE_STRETCH_0_get_ref_alpha(data)                                        ((0x00000020&(data))>>5)
#define  SE_STRETCH_0_get_htype(data)                                            ((0x00000018&(data))>>3)
#define  SE_STRETCH_0_get_vtype(data)                                            ((0x00000004&(data))>>2)
#define  SE_STRETCH_0_get_hodd(data)                                             ((0x00000002&(data))>>1)
#define  SE_STRETCH_0_get_vodd(data)                                             (0x00000001&(data))

#define  SE_STRETCH_1                                                            0x1800C2C4
#define  SE_STRETCH_1_reg_addr                                                   "0xB800C2C4"
#define  SE_STRETCH_1_reg                                                        0xB800C2C4
#define  SE_STRETCH_1_inst_addr                                                  "0x0049"
#define  set_SE_STRETCH_1_reg(data)                                              (*((volatile unsigned int*)SE_STRETCH_1_reg)=data)
#define  get_SE_STRETCH_1_reg                                                    (*((volatile unsigned int*)SE_STRETCH_1_reg))
#define  SE_STRETCH_1_repl_alpha_shift                                           (7)
#define  SE_STRETCH_1_repl_color_shift                                           (6)
#define  SE_STRETCH_1_ref_alpha_shift                                            (5)
#define  SE_STRETCH_1_htype_shift                                                (3)
#define  SE_STRETCH_1_vtype_shift                                                (2)
#define  SE_STRETCH_1_hodd_shift                                                 (1)
#define  SE_STRETCH_1_vodd_shift                                                 (0)
#define  SE_STRETCH_1_repl_alpha_mask                                            (0x00000080)
#define  SE_STRETCH_1_repl_color_mask                                            (0x00000040)
#define  SE_STRETCH_1_ref_alpha_mask                                             (0x00000020)
#define  SE_STRETCH_1_htype_mask                                                 (0x00000018)
#define  SE_STRETCH_1_vtype_mask                                                 (0x00000004)
#define  SE_STRETCH_1_hodd_mask                                                  (0x00000002)
#define  SE_STRETCH_1_vodd_mask                                                  (0x00000001)
#define  SE_STRETCH_1_repl_alpha(data)                                           (0x00000080&((data)<<7))
#define  SE_STRETCH_1_repl_color(data)                                           (0x00000040&((data)<<6))
#define  SE_STRETCH_1_ref_alpha(data)                                            (0x00000020&((data)<<5))
#define  SE_STRETCH_1_htype(data)                                                (0x00000018&((data)<<3))
#define  SE_STRETCH_1_vtype(data)                                                (0x00000004&((data)<<2))
#define  SE_STRETCH_1_hodd(data)                                                 (0x00000002&((data)<<1))
#define  SE_STRETCH_1_vodd(data)                                                 (0x00000001&(data))
#define  SE_STRETCH_1_get_repl_alpha(data)                                       ((0x00000080&(data))>>7)
#define  SE_STRETCH_1_get_repl_color(data)                                       ((0x00000040&(data))>>6)
#define  SE_STRETCH_1_get_ref_alpha(data)                                        ((0x00000020&(data))>>5)
#define  SE_STRETCH_1_get_htype(data)                                            ((0x00000018&(data))>>3)
#define  SE_STRETCH_1_get_vtype(data)                                            ((0x00000004&(data))>>2)
#define  SE_STRETCH_1_get_hodd(data)                                             ((0x00000002&(data))>>1)
#define  SE_STRETCH_1_get_vodd(data)                                             (0x00000001&(data))

#define  SE_HDHS_0                                                               0x1800C2D0
#define  SE_HDHS_0_reg_addr                                                      "0xB800C2D0"
#define  SE_HDHS_0_reg                                                           0xB800C2D0
#define  SE_HDHS_0_inst_addr                                                     "0x004A"
#define  set_SE_HDHS_0_reg(data)                                                 (*((volatile unsigned int*)SE_HDHS_0_reg)=data)
#define  get_SE_HDHS_0_reg                                                       (*((volatile unsigned int*)SE_HDHS_0_reg))
#define  SE_HDHS_0_h_scaling_iniph_shift                                         (18)
#define  SE_HDHS_0_h_scaling_dph_msb_shift                                       (14)
#define  SE_HDHS_0_h_scaling_dph_lsb_shift                                       (0)
#define  SE_HDHS_0_h_scaling_iniph_mask                                          (0x003C0000)
#define  SE_HDHS_0_h_scaling_dph_msb_mask                                        (0x0003C000)
#define  SE_HDHS_0_h_scaling_dph_lsb_mask                                        (0x00003FFF)
#define  SE_HDHS_0_h_scaling_iniph(data)                                         (0x003C0000&((data)<<18))
#define  SE_HDHS_0_h_scaling_dph_msb(data)                                       (0x0003C000&((data)<<14))
#define  SE_HDHS_0_h_scaling_dph_lsb(data)                                       (0x00003FFF&(data))
#define  SE_HDHS_0_get_h_scaling_iniph(data)                                     ((0x003C0000&(data))>>18)
#define  SE_HDHS_0_get_h_scaling_dph_msb(data)                                   ((0x0003C000&(data))>>14)
#define  SE_HDHS_0_get_h_scaling_dph_lsb(data)                                   (0x00003FFF&(data))

#define  SE_HDHS_1                                                               0x1800C2D4
#define  SE_HDHS_1_reg_addr                                                      "0xB800C2D4"
#define  SE_HDHS_1_reg                                                           0xB800C2D4
#define  SE_HDHS_1_inst_addr                                                     "0x004B"
#define  set_SE_HDHS_1_reg(data)                                                 (*((volatile unsigned int*)SE_HDHS_1_reg)=data)
#define  get_SE_HDHS_1_reg                                                       (*((volatile unsigned int*)SE_HDHS_1_reg))
#define  SE_HDHS_1_h_scaling_iniph_shift                                         (18)
#define  SE_HDHS_1_h_scaling_dph_msb_shift                                       (14)
#define  SE_HDHS_1_h_scaling_dph_lsb_shift                                       (0)
#define  SE_HDHS_1_h_scaling_iniph_mask                                          (0x003C0000)
#define  SE_HDHS_1_h_scaling_dph_msb_mask                                        (0x0003C000)
#define  SE_HDHS_1_h_scaling_dph_lsb_mask                                        (0x00003FFF)
#define  SE_HDHS_1_h_scaling_iniph(data)                                         (0x003C0000&((data)<<18))
#define  SE_HDHS_1_h_scaling_dph_msb(data)                                       (0x0003C000&((data)<<14))
#define  SE_HDHS_1_h_scaling_dph_lsb(data)                                       (0x00003FFF&(data))
#define  SE_HDHS_1_get_h_scaling_iniph(data)                                     ((0x003C0000&(data))>>18)
#define  SE_HDHS_1_get_h_scaling_dph_msb(data)                                   ((0x0003C000&(data))>>14)
#define  SE_HDHS_1_get_h_scaling_dph_lsb(data)                                   (0x00003FFF&(data))

#define  SE_VDHS_0                                                               0x1800C2E0
#define  SE_VDHS_0_reg_addr                                                      "0xB800C2E0"
#define  SE_VDHS_0_reg                                                           0xB800C2E0
#define  SE_VDHS_0_inst_addr                                                     "0x004C"
#define  set_SE_VDHS_0_reg(data)                                                 (*((volatile unsigned int*)SE_VDHS_0_reg)=data)
#define  get_SE_VDHS_0_reg                                                       (*((volatile unsigned int*)SE_VDHS_0_reg))
#define  SE_VDHS_0_v_scaling_iniph_shift                                         (18)
#define  SE_VDHS_0_v_scaling_dph_msb_shift                                       (14)
#define  SE_VDHS_0_v_scaling_dph_lsb_shift                                       (0)
#define  SE_VDHS_0_v_scaling_iniph_mask                                          (0x003C0000)
#define  SE_VDHS_0_v_scaling_dph_msb_mask                                        (0x0003C000)
#define  SE_VDHS_0_v_scaling_dph_lsb_mask                                        (0x00003FFF)
#define  SE_VDHS_0_v_scaling_iniph(data)                                         (0x003C0000&((data)<<18))
#define  SE_VDHS_0_v_scaling_dph_msb(data)                                       (0x0003C000&((data)<<14))
#define  SE_VDHS_0_v_scaling_dph_lsb(data)                                       (0x00003FFF&(data))
#define  SE_VDHS_0_get_v_scaling_iniph(data)                                     ((0x003C0000&(data))>>18)
#define  SE_VDHS_0_get_v_scaling_dph_msb(data)                                   ((0x0003C000&(data))>>14)
#define  SE_VDHS_0_get_v_scaling_dph_lsb(data)                                   (0x00003FFF&(data))

#define  SE_VDHS_1                                                               0x1800C2E4
#define  SE_VDHS_1_reg_addr                                                      "0xB800C2E4"
#define  SE_VDHS_1_reg                                                           0xB800C2E4
#define  SE_VDHS_1_inst_addr                                                     "0x004D"
#define  set_SE_VDHS_1_reg(data)                                                 (*((volatile unsigned int*)SE_VDHS_1_reg)=data)
#define  get_SE_VDHS_1_reg                                                       (*((volatile unsigned int*)SE_VDHS_1_reg))
#define  SE_VDHS_1_v_scaling_iniph_shift                                         (18)
#define  SE_VDHS_1_v_scaling_dph_msb_shift                                       (14)
#define  SE_VDHS_1_v_scaling_dph_lsb_shift                                       (0)
#define  SE_VDHS_1_v_scaling_iniph_mask                                          (0x003C0000)
#define  SE_VDHS_1_v_scaling_dph_msb_mask                                        (0x0003C000)
#define  SE_VDHS_1_v_scaling_dph_lsb_mask                                        (0x00003FFF)
#define  SE_VDHS_1_v_scaling_iniph(data)                                         (0x003C0000&((data)<<18))
#define  SE_VDHS_1_v_scaling_dph_msb(data)                                       (0x0003C000&((data)<<14))
#define  SE_VDHS_1_v_scaling_dph_lsb(data)                                       (0x00003FFF&(data))
#define  SE_VDHS_1_get_v_scaling_iniph(data)                                     ((0x003C0000&(data))>>18)
#define  SE_VDHS_1_get_v_scaling_dph_msb(data)                                   ((0x0003C000&(data))>>14)
#define  SE_VDHS_1_get_v_scaling_dph_lsb(data)                                   (0x00003FFF&(data))

#define  SE_HCOEF1_0                                                             0x1800C300
#define  SE_HCOEF1_0_reg_addr                                                    "0xB800C300"
#define  SE_HCOEF1_0_reg                                                         0xB800C300
#define  SE_HCOEF1_0_inst_addr                                                   "0x004E"
#define  set_SE_HCOEF1_0_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_0_reg)=data)
#define  get_SE_HCOEF1_0_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_0_reg))
#define  SE_HCOEF1_0_hcoef_shift                                                 (0)
#define  SE_HCOEF1_0_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_0_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_0_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_1                                                             0x1800C304
#define  SE_HCOEF1_1_reg_addr                                                    "0xB800C304"
#define  SE_HCOEF1_1_reg                                                         0xB800C304
#define  SE_HCOEF1_1_inst_addr                                                   "0x004F"
#define  set_SE_HCOEF1_1_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_1_reg)=data)
#define  get_SE_HCOEF1_1_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_1_reg))
#define  SE_HCOEF1_1_hcoef_shift                                                 (0)
#define  SE_HCOEF1_1_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_1_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_1_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_2                                                             0x1800C308
#define  SE_HCOEF1_2_reg_addr                                                    "0xB800C308"
#define  SE_HCOEF1_2_reg                                                         0xB800C308
#define  SE_HCOEF1_2_inst_addr                                                   "0x0050"
#define  set_SE_HCOEF1_2_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_2_reg)=data)
#define  get_SE_HCOEF1_2_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_2_reg))
#define  SE_HCOEF1_2_hcoef_shift                                                 (0)
#define  SE_HCOEF1_2_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_2_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_2_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_3                                                             0x1800C30C
#define  SE_HCOEF1_3_reg_addr                                                    "0xB800C30C"
#define  SE_HCOEF1_3_reg                                                         0xB800C30C
#define  SE_HCOEF1_3_inst_addr                                                   "0x0051"
#define  set_SE_HCOEF1_3_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_3_reg)=data)
#define  get_SE_HCOEF1_3_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_3_reg))
#define  SE_HCOEF1_3_hcoef_shift                                                 (0)
#define  SE_HCOEF1_3_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_3_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_3_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_4                                                             0x1800C310
#define  SE_HCOEF1_4_reg_addr                                                    "0xB800C310"
#define  SE_HCOEF1_4_reg                                                         0xB800C310
#define  SE_HCOEF1_4_inst_addr                                                   "0x0052"
#define  set_SE_HCOEF1_4_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_4_reg)=data)
#define  get_SE_HCOEF1_4_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_4_reg))
#define  SE_HCOEF1_4_hcoef_shift                                                 (0)
#define  SE_HCOEF1_4_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_4_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_4_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_5                                                             0x1800C314
#define  SE_HCOEF1_5_reg_addr                                                    "0xB800C314"
#define  SE_HCOEF1_5_reg                                                         0xB800C314
#define  SE_HCOEF1_5_inst_addr                                                   "0x0053"
#define  set_SE_HCOEF1_5_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_5_reg)=data)
#define  get_SE_HCOEF1_5_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_5_reg))
#define  SE_HCOEF1_5_hcoef_shift                                                 (0)
#define  SE_HCOEF1_5_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_5_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_5_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_6                                                             0x1800C318
#define  SE_HCOEF1_6_reg_addr                                                    "0xB800C318"
#define  SE_HCOEF1_6_reg                                                         0xB800C318
#define  SE_HCOEF1_6_inst_addr                                                   "0x0054"
#define  set_SE_HCOEF1_6_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_6_reg)=data)
#define  get_SE_HCOEF1_6_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_6_reg))
#define  SE_HCOEF1_6_hcoef_shift                                                 (0)
#define  SE_HCOEF1_6_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_6_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_6_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_7                                                             0x1800C31C
#define  SE_HCOEF1_7_reg_addr                                                    "0xB800C31C"
#define  SE_HCOEF1_7_reg                                                         0xB800C31C
#define  SE_HCOEF1_7_inst_addr                                                   "0x0055"
#define  set_SE_HCOEF1_7_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_7_reg)=data)
#define  get_SE_HCOEF1_7_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_7_reg))
#define  SE_HCOEF1_7_hcoef_shift                                                 (0)
#define  SE_HCOEF1_7_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_7_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_7_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_8                                                             0x1800C320
#define  SE_HCOEF1_8_reg_addr                                                    "0xB800C320"
#define  SE_HCOEF1_8_reg                                                         0xB800C320
#define  SE_HCOEF1_8_inst_addr                                                   "0x0056"
#define  set_SE_HCOEF1_8_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_8_reg)=data)
#define  get_SE_HCOEF1_8_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_8_reg))
#define  SE_HCOEF1_8_hcoef_shift                                                 (0)
#define  SE_HCOEF1_8_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_8_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_8_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_9                                                             0x1800C324
#define  SE_HCOEF1_9_reg_addr                                                    "0xB800C324"
#define  SE_HCOEF1_9_reg                                                         0xB800C324
#define  SE_HCOEF1_9_inst_addr                                                   "0x0057"
#define  set_SE_HCOEF1_9_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF1_9_reg)=data)
#define  get_SE_HCOEF1_9_reg                                                     (*((volatile unsigned int*)SE_HCOEF1_9_reg))
#define  SE_HCOEF1_9_hcoef_shift                                                 (0)
#define  SE_HCOEF1_9_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF1_9_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF1_9_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF1_10                                                            0x1800C328
#define  SE_HCOEF1_10_reg_addr                                                   "0xB800C328"
#define  SE_HCOEF1_10_reg                                                        0xB800C328
#define  SE_HCOEF1_10_inst_addr                                                  "0x0058"
#define  set_SE_HCOEF1_10_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_10_reg)=data)
#define  get_SE_HCOEF1_10_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_10_reg))
#define  SE_HCOEF1_10_hcoef_shift                                                (0)
#define  SE_HCOEF1_10_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_10_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_10_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_11                                                            0x1800C32C
#define  SE_HCOEF1_11_reg_addr                                                   "0xB800C32C"
#define  SE_HCOEF1_11_reg                                                        0xB800C32C
#define  SE_HCOEF1_11_inst_addr                                                  "0x0059"
#define  set_SE_HCOEF1_11_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_11_reg)=data)
#define  get_SE_HCOEF1_11_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_11_reg))
#define  SE_HCOEF1_11_hcoef_shift                                                (0)
#define  SE_HCOEF1_11_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_11_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_11_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_12                                                            0x1800C330
#define  SE_HCOEF1_12_reg_addr                                                   "0xB800C330"
#define  SE_HCOEF1_12_reg                                                        0xB800C330
#define  SE_HCOEF1_12_inst_addr                                                  "0x005A"
#define  set_SE_HCOEF1_12_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_12_reg)=data)
#define  get_SE_HCOEF1_12_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_12_reg))
#define  SE_HCOEF1_12_hcoef_shift                                                (0)
#define  SE_HCOEF1_12_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_12_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_12_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_13                                                            0x1800C334
#define  SE_HCOEF1_13_reg_addr                                                   "0xB800C334"
#define  SE_HCOEF1_13_reg                                                        0xB800C334
#define  SE_HCOEF1_13_inst_addr                                                  "0x005B"
#define  set_SE_HCOEF1_13_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_13_reg)=data)
#define  get_SE_HCOEF1_13_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_13_reg))
#define  SE_HCOEF1_13_hcoef_shift                                                (0)
#define  SE_HCOEF1_13_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_13_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_13_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_14                                                            0x1800C338
#define  SE_HCOEF1_14_reg_addr                                                   "0xB800C338"
#define  SE_HCOEF1_14_reg                                                        0xB800C338
#define  SE_HCOEF1_14_inst_addr                                                  "0x005C"
#define  set_SE_HCOEF1_14_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_14_reg)=data)
#define  get_SE_HCOEF1_14_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_14_reg))
#define  SE_HCOEF1_14_hcoef_shift                                                (0)
#define  SE_HCOEF1_14_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_14_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_14_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_15                                                            0x1800C33C
#define  SE_HCOEF1_15_reg_addr                                                   "0xB800C33C"
#define  SE_HCOEF1_15_reg                                                        0xB800C33C
#define  SE_HCOEF1_15_inst_addr                                                  "0x005D"
#define  set_SE_HCOEF1_15_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_15_reg)=data)
#define  get_SE_HCOEF1_15_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_15_reg))
#define  SE_HCOEF1_15_hcoef_shift                                                (0)
#define  SE_HCOEF1_15_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_15_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_15_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_16                                                            0x1800C340
#define  SE_HCOEF1_16_reg_addr                                                   "0xB800C340"
#define  SE_HCOEF1_16_reg                                                        0xB800C340
#define  SE_HCOEF1_16_inst_addr                                                  "0x005E"
#define  set_SE_HCOEF1_16_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_16_reg)=data)
#define  get_SE_HCOEF1_16_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_16_reg))
#define  SE_HCOEF1_16_hcoef_shift                                                (0)
#define  SE_HCOEF1_16_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_16_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_16_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_17                                                            0x1800C344
#define  SE_HCOEF1_17_reg_addr                                                   "0xB800C344"
#define  SE_HCOEF1_17_reg                                                        0xB800C344
#define  SE_HCOEF1_17_inst_addr                                                  "0x005F"
#define  set_SE_HCOEF1_17_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_17_reg)=data)
#define  get_SE_HCOEF1_17_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_17_reg))
#define  SE_HCOEF1_17_hcoef_shift                                                (0)
#define  SE_HCOEF1_17_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_17_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_17_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_18                                                            0x1800C348
#define  SE_HCOEF1_18_reg_addr                                                   "0xB800C348"
#define  SE_HCOEF1_18_reg                                                        0xB800C348
#define  SE_HCOEF1_18_inst_addr                                                  "0x0060"
#define  set_SE_HCOEF1_18_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_18_reg)=data)
#define  get_SE_HCOEF1_18_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_18_reg))
#define  SE_HCOEF1_18_hcoef_shift                                                (0)
#define  SE_HCOEF1_18_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_18_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_18_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_19                                                            0x1800C34C
#define  SE_HCOEF1_19_reg_addr                                                   "0xB800C34C"
#define  SE_HCOEF1_19_reg                                                        0xB800C34C
#define  SE_HCOEF1_19_inst_addr                                                  "0x0061"
#define  set_SE_HCOEF1_19_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_19_reg)=data)
#define  get_SE_HCOEF1_19_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_19_reg))
#define  SE_HCOEF1_19_hcoef_shift                                                (0)
#define  SE_HCOEF1_19_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_19_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_19_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_20                                                            0x1800C350
#define  SE_HCOEF1_20_reg_addr                                                   "0xB800C350"
#define  SE_HCOEF1_20_reg                                                        0xB800C350
#define  SE_HCOEF1_20_inst_addr                                                  "0x0062"
#define  set_SE_HCOEF1_20_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_20_reg)=data)
#define  get_SE_HCOEF1_20_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_20_reg))
#define  SE_HCOEF1_20_hcoef_shift                                                (0)
#define  SE_HCOEF1_20_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_20_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_20_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_21                                                            0x1800C354
#define  SE_HCOEF1_21_reg_addr                                                   "0xB800C354"
#define  SE_HCOEF1_21_reg                                                        0xB800C354
#define  SE_HCOEF1_21_inst_addr                                                  "0x0063"
#define  set_SE_HCOEF1_21_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_21_reg)=data)
#define  get_SE_HCOEF1_21_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_21_reg))
#define  SE_HCOEF1_21_hcoef_shift                                                (0)
#define  SE_HCOEF1_21_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_21_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_21_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_22                                                            0x1800C358
#define  SE_HCOEF1_22_reg_addr                                                   "0xB800C358"
#define  SE_HCOEF1_22_reg                                                        0xB800C358
#define  SE_HCOEF1_22_inst_addr                                                  "0x0064"
#define  set_SE_HCOEF1_22_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_22_reg)=data)
#define  get_SE_HCOEF1_22_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_22_reg))
#define  SE_HCOEF1_22_hcoef_shift                                                (0)
#define  SE_HCOEF1_22_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_22_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_22_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_23                                                            0x1800C35C
#define  SE_HCOEF1_23_reg_addr                                                   "0xB800C35C"
#define  SE_HCOEF1_23_reg                                                        0xB800C35C
#define  SE_HCOEF1_23_inst_addr                                                  "0x0065"
#define  set_SE_HCOEF1_23_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_23_reg)=data)
#define  get_SE_HCOEF1_23_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_23_reg))
#define  SE_HCOEF1_23_hcoef_shift                                                (0)
#define  SE_HCOEF1_23_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_23_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_23_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_24                                                            0x1800C360
#define  SE_HCOEF1_24_reg_addr                                                   "0xB800C360"
#define  SE_HCOEF1_24_reg                                                        0xB800C360
#define  SE_HCOEF1_24_inst_addr                                                  "0x0066"
#define  set_SE_HCOEF1_24_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_24_reg)=data)
#define  get_SE_HCOEF1_24_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_24_reg))
#define  SE_HCOEF1_24_hcoef_shift                                                (0)
#define  SE_HCOEF1_24_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_24_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_24_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_25                                                            0x1800C364
#define  SE_HCOEF1_25_reg_addr                                                   "0xB800C364"
#define  SE_HCOEF1_25_reg                                                        0xB800C364
#define  SE_HCOEF1_25_inst_addr                                                  "0x0067"
#define  set_SE_HCOEF1_25_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_25_reg)=data)
#define  get_SE_HCOEF1_25_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_25_reg))
#define  SE_HCOEF1_25_hcoef_shift                                                (0)
#define  SE_HCOEF1_25_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_25_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_25_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_26                                                            0x1800C368
#define  SE_HCOEF1_26_reg_addr                                                   "0xB800C368"
#define  SE_HCOEF1_26_reg                                                        0xB800C368
#define  SE_HCOEF1_26_inst_addr                                                  "0x0068"
#define  set_SE_HCOEF1_26_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_26_reg)=data)
#define  get_SE_HCOEF1_26_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_26_reg))
#define  SE_HCOEF1_26_hcoef_shift                                                (0)
#define  SE_HCOEF1_26_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_26_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_26_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_27                                                            0x1800C36C
#define  SE_HCOEF1_27_reg_addr                                                   "0xB800C36C"
#define  SE_HCOEF1_27_reg                                                        0xB800C36C
#define  SE_HCOEF1_27_inst_addr                                                  "0x0069"
#define  set_SE_HCOEF1_27_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_27_reg)=data)
#define  get_SE_HCOEF1_27_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_27_reg))
#define  SE_HCOEF1_27_hcoef_shift                                                (0)
#define  SE_HCOEF1_27_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_27_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_27_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_28                                                            0x1800C370
#define  SE_HCOEF1_28_reg_addr                                                   "0xB800C370"
#define  SE_HCOEF1_28_reg                                                        0xB800C370
#define  SE_HCOEF1_28_inst_addr                                                  "0x006A"
#define  set_SE_HCOEF1_28_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_28_reg)=data)
#define  get_SE_HCOEF1_28_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_28_reg))
#define  SE_HCOEF1_28_hcoef_shift                                                (0)
#define  SE_HCOEF1_28_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_28_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_28_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_29                                                            0x1800C374
#define  SE_HCOEF1_29_reg_addr                                                   "0xB800C374"
#define  SE_HCOEF1_29_reg                                                        0xB800C374
#define  SE_HCOEF1_29_inst_addr                                                  "0x006B"
#define  set_SE_HCOEF1_29_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_29_reg)=data)
#define  get_SE_HCOEF1_29_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_29_reg))
#define  SE_HCOEF1_29_hcoef_shift                                                (0)
#define  SE_HCOEF1_29_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_29_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_29_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_30                                                            0x1800C378
#define  SE_HCOEF1_30_reg_addr                                                   "0xB800C378"
#define  SE_HCOEF1_30_reg                                                        0xB800C378
#define  SE_HCOEF1_30_inst_addr                                                  "0x006C"
#define  set_SE_HCOEF1_30_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_30_reg)=data)
#define  get_SE_HCOEF1_30_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_30_reg))
#define  SE_HCOEF1_30_hcoef_shift                                                (0)
#define  SE_HCOEF1_30_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_30_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_30_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_31                                                            0x1800C37C
#define  SE_HCOEF1_31_reg_addr                                                   "0xB800C37C"
#define  SE_HCOEF1_31_reg                                                        0xB800C37C
#define  SE_HCOEF1_31_inst_addr                                                  "0x006D"
#define  set_SE_HCOEF1_31_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF1_31_reg)=data)
#define  get_SE_HCOEF1_31_reg                                                    (*((volatile unsigned int*)SE_HCOEF1_31_reg))
#define  SE_HCOEF1_31_hcoef_shift                                                (0)
#define  SE_HCOEF1_31_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF1_31_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF1_31_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF1_32_0                                                          0x1800C380
#define  SE_HCOEF1_32_0_reg_addr                                                 "0xB800C380"
#define  SE_HCOEF1_32_0_reg                                                      0xB800C380
#define  SE_HCOEF1_32_0_inst_addr                                                "0x006E"
#define  set_SE_HCOEF1_32_0_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_0_reg)=data)
#define  get_SE_HCOEF1_32_0_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_0_reg))
#define  SE_HCOEF1_32_0_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_0_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_0_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_0_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_1                                                          0x1800C384
#define  SE_HCOEF1_32_1_reg_addr                                                 "0xB800C384"
#define  SE_HCOEF1_32_1_reg                                                      0xB800C384
#define  SE_HCOEF1_32_1_inst_addr                                                "0x006F"
#define  set_SE_HCOEF1_32_1_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_1_reg)=data)
#define  get_SE_HCOEF1_32_1_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_1_reg))
#define  SE_HCOEF1_32_1_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_1_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_1_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_1_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_2                                                          0x1800C388
#define  SE_HCOEF1_32_2_reg_addr                                                 "0xB800C388"
#define  SE_HCOEF1_32_2_reg                                                      0xB800C388
#define  SE_HCOEF1_32_2_inst_addr                                                "0x0070"
#define  set_SE_HCOEF1_32_2_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_2_reg)=data)
#define  get_SE_HCOEF1_32_2_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_2_reg))
#define  SE_HCOEF1_32_2_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_2_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_2_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_2_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_3                                                          0x1800C38C
#define  SE_HCOEF1_32_3_reg_addr                                                 "0xB800C38C"
#define  SE_HCOEF1_32_3_reg                                                      0xB800C38C
#define  SE_HCOEF1_32_3_inst_addr                                                "0x0071"
#define  set_SE_HCOEF1_32_3_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_3_reg)=data)
#define  get_SE_HCOEF1_32_3_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_3_reg))
#define  SE_HCOEF1_32_3_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_3_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_3_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_3_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_4                                                          0x1800C390
#define  SE_HCOEF1_32_4_reg_addr                                                 "0xB800C390"
#define  SE_HCOEF1_32_4_reg                                                      0xB800C390
#define  SE_HCOEF1_32_4_inst_addr                                                "0x0072"
#define  set_SE_HCOEF1_32_4_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_4_reg)=data)
#define  get_SE_HCOEF1_32_4_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_4_reg))
#define  SE_HCOEF1_32_4_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_4_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_4_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_4_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_5                                                          0x1800C394
#define  SE_HCOEF1_32_5_reg_addr                                                 "0xB800C394"
#define  SE_HCOEF1_32_5_reg                                                      0xB800C394
#define  SE_HCOEF1_32_5_inst_addr                                                "0x0073"
#define  set_SE_HCOEF1_32_5_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_5_reg)=data)
#define  get_SE_HCOEF1_32_5_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_5_reg))
#define  SE_HCOEF1_32_5_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_5_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_5_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_5_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_6                                                          0x1800C398
#define  SE_HCOEF1_32_6_reg_addr                                                 "0xB800C398"
#define  SE_HCOEF1_32_6_reg                                                      0xB800C398
#define  SE_HCOEF1_32_6_inst_addr                                                "0x0074"
#define  set_SE_HCOEF1_32_6_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_6_reg)=data)
#define  get_SE_HCOEF1_32_6_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_6_reg))
#define  SE_HCOEF1_32_6_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_6_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_6_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_6_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_7                                                          0x1800C39C
#define  SE_HCOEF1_32_7_reg_addr                                                 "0xB800C39C"
#define  SE_HCOEF1_32_7_reg                                                      0xB800C39C
#define  SE_HCOEF1_32_7_inst_addr                                                "0x0075"
#define  set_SE_HCOEF1_32_7_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_7_reg)=data)
#define  get_SE_HCOEF1_32_7_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_7_reg))
#define  SE_HCOEF1_32_7_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_7_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_7_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_7_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_8                                                          0x1800C3A0
#define  SE_HCOEF1_32_8_reg_addr                                                 "0xB800C3A0"
#define  SE_HCOEF1_32_8_reg                                                      0xB800C3A0
#define  SE_HCOEF1_32_8_inst_addr                                                "0x0076"
#define  set_SE_HCOEF1_32_8_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_8_reg)=data)
#define  get_SE_HCOEF1_32_8_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_8_reg))
#define  SE_HCOEF1_32_8_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_8_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_8_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_8_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_9                                                          0x1800C3A4
#define  SE_HCOEF1_32_9_reg_addr                                                 "0xB800C3A4"
#define  SE_HCOEF1_32_9_reg                                                      0xB800C3A4
#define  SE_HCOEF1_32_9_inst_addr                                                "0x0077"
#define  set_SE_HCOEF1_32_9_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF1_32_9_reg)=data)
#define  get_SE_HCOEF1_32_9_reg                                                  (*((volatile unsigned int*)SE_HCOEF1_32_9_reg))
#define  SE_HCOEF1_32_9_hcoef_shift                                              (0)
#define  SE_HCOEF1_32_9_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF1_32_9_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF1_32_9_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF1_32_10                                                         0x1800C3A8
#define  SE_HCOEF1_32_10_reg_addr                                                "0xB800C3A8"
#define  SE_HCOEF1_32_10_reg                                                     0xB800C3A8
#define  SE_HCOEF1_32_10_inst_addr                                               "0x0078"
#define  set_SE_HCOEF1_32_10_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_10_reg)=data)
#define  get_SE_HCOEF1_32_10_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_10_reg))
#define  SE_HCOEF1_32_10_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_10_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_10_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_10_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_11                                                         0x1800C3AC
#define  SE_HCOEF1_32_11_reg_addr                                                "0xB800C3AC"
#define  SE_HCOEF1_32_11_reg                                                     0xB800C3AC
#define  SE_HCOEF1_32_11_inst_addr                                               "0x0079"
#define  set_SE_HCOEF1_32_11_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_11_reg)=data)
#define  get_SE_HCOEF1_32_11_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_11_reg))
#define  SE_HCOEF1_32_11_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_11_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_11_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_11_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_12                                                         0x1800C3B0
#define  SE_HCOEF1_32_12_reg_addr                                                "0xB800C3B0"
#define  SE_HCOEF1_32_12_reg                                                     0xB800C3B0
#define  SE_HCOEF1_32_12_inst_addr                                               "0x007A"
#define  set_SE_HCOEF1_32_12_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_12_reg)=data)
#define  get_SE_HCOEF1_32_12_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_12_reg))
#define  SE_HCOEF1_32_12_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_12_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_12_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_12_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_13                                                         0x1800C3B4
#define  SE_HCOEF1_32_13_reg_addr                                                "0xB800C3B4"
#define  SE_HCOEF1_32_13_reg                                                     0xB800C3B4
#define  SE_HCOEF1_32_13_inst_addr                                               "0x007B"
#define  set_SE_HCOEF1_32_13_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_13_reg)=data)
#define  get_SE_HCOEF1_32_13_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_13_reg))
#define  SE_HCOEF1_32_13_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_13_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_13_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_13_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_14                                                         0x1800C3B8
#define  SE_HCOEF1_32_14_reg_addr                                                "0xB800C3B8"
#define  SE_HCOEF1_32_14_reg                                                     0xB800C3B8
#define  SE_HCOEF1_32_14_inst_addr                                               "0x007C"
#define  set_SE_HCOEF1_32_14_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_14_reg)=data)
#define  get_SE_HCOEF1_32_14_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_14_reg))
#define  SE_HCOEF1_32_14_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_14_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_14_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_14_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_15                                                         0x1800C3BC
#define  SE_HCOEF1_32_15_reg_addr                                                "0xB800C3BC"
#define  SE_HCOEF1_32_15_reg                                                     0xB800C3BC
#define  SE_HCOEF1_32_15_inst_addr                                               "0x007D"
#define  set_SE_HCOEF1_32_15_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_15_reg)=data)
#define  get_SE_HCOEF1_32_15_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_15_reg))
#define  SE_HCOEF1_32_15_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_15_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_15_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_15_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_16                                                         0x1800C3C0
#define  SE_HCOEF1_32_16_reg_addr                                                "0xB800C3C0"
#define  SE_HCOEF1_32_16_reg                                                     0xB800C3C0
#define  SE_HCOEF1_32_16_inst_addr                                               "0x007E"
#define  set_SE_HCOEF1_32_16_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_16_reg)=data)
#define  get_SE_HCOEF1_32_16_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_16_reg))
#define  SE_HCOEF1_32_16_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_16_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_16_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_16_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_17                                                         0x1800C3C4
#define  SE_HCOEF1_32_17_reg_addr                                                "0xB800C3C4"
#define  SE_HCOEF1_32_17_reg                                                     0xB800C3C4
#define  SE_HCOEF1_32_17_inst_addr                                               "0x007F"
#define  set_SE_HCOEF1_32_17_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_17_reg)=data)
#define  get_SE_HCOEF1_32_17_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_17_reg))
#define  SE_HCOEF1_32_17_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_17_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_17_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_17_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_18                                                         0x1800C3C8
#define  SE_HCOEF1_32_18_reg_addr                                                "0xB800C3C8"
#define  SE_HCOEF1_32_18_reg                                                     0xB800C3C8
#define  SE_HCOEF1_32_18_inst_addr                                               "0x0080"
#define  set_SE_HCOEF1_32_18_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_18_reg)=data)
#define  get_SE_HCOEF1_32_18_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_18_reg))
#define  SE_HCOEF1_32_18_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_18_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_18_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_18_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_19                                                         0x1800C3CC
#define  SE_HCOEF1_32_19_reg_addr                                                "0xB800C3CC"
#define  SE_HCOEF1_32_19_reg                                                     0xB800C3CC
#define  SE_HCOEF1_32_19_inst_addr                                               "0x0081"
#define  set_SE_HCOEF1_32_19_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_19_reg)=data)
#define  get_SE_HCOEF1_32_19_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_19_reg))
#define  SE_HCOEF1_32_19_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_19_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_19_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_19_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_20                                                         0x1800C3D0
#define  SE_HCOEF1_32_20_reg_addr                                                "0xB800C3D0"
#define  SE_HCOEF1_32_20_reg                                                     0xB800C3D0
#define  SE_HCOEF1_32_20_inst_addr                                               "0x0082"
#define  set_SE_HCOEF1_32_20_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_20_reg)=data)
#define  get_SE_HCOEF1_32_20_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_20_reg))
#define  SE_HCOEF1_32_20_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_20_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_20_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_20_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_21                                                         0x1800C3D4
#define  SE_HCOEF1_32_21_reg_addr                                                "0xB800C3D4"
#define  SE_HCOEF1_32_21_reg                                                     0xB800C3D4
#define  SE_HCOEF1_32_21_inst_addr                                               "0x0083"
#define  set_SE_HCOEF1_32_21_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_21_reg)=data)
#define  get_SE_HCOEF1_32_21_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_21_reg))
#define  SE_HCOEF1_32_21_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_21_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_21_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_21_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_22                                                         0x1800C3D8
#define  SE_HCOEF1_32_22_reg_addr                                                "0xB800C3D8"
#define  SE_HCOEF1_32_22_reg                                                     0xB800C3D8
#define  SE_HCOEF1_32_22_inst_addr                                               "0x0084"
#define  set_SE_HCOEF1_32_22_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_22_reg)=data)
#define  get_SE_HCOEF1_32_22_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_22_reg))
#define  SE_HCOEF1_32_22_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_22_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_22_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_22_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_23                                                         0x1800C3DC
#define  SE_HCOEF1_32_23_reg_addr                                                "0xB800C3DC"
#define  SE_HCOEF1_32_23_reg                                                     0xB800C3DC
#define  SE_HCOEF1_32_23_inst_addr                                               "0x0085"
#define  set_SE_HCOEF1_32_23_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_23_reg)=data)
#define  get_SE_HCOEF1_32_23_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_23_reg))
#define  SE_HCOEF1_32_23_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_23_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_23_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_23_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_24                                                         0x1800C3E0
#define  SE_HCOEF1_32_24_reg_addr                                                "0xB800C3E0"
#define  SE_HCOEF1_32_24_reg                                                     0xB800C3E0
#define  SE_HCOEF1_32_24_inst_addr                                               "0x0086"
#define  set_SE_HCOEF1_32_24_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_24_reg)=data)
#define  get_SE_HCOEF1_32_24_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_24_reg))
#define  SE_HCOEF1_32_24_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_24_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_24_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_24_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_25                                                         0x1800C3E4
#define  SE_HCOEF1_32_25_reg_addr                                                "0xB800C3E4"
#define  SE_HCOEF1_32_25_reg                                                     0xB800C3E4
#define  SE_HCOEF1_32_25_inst_addr                                               "0x0087"
#define  set_SE_HCOEF1_32_25_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_25_reg)=data)
#define  get_SE_HCOEF1_32_25_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_25_reg))
#define  SE_HCOEF1_32_25_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_25_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_25_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_25_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_26                                                         0x1800C3E8
#define  SE_HCOEF1_32_26_reg_addr                                                "0xB800C3E8"
#define  SE_HCOEF1_32_26_reg                                                     0xB800C3E8
#define  SE_HCOEF1_32_26_inst_addr                                               "0x0088"
#define  set_SE_HCOEF1_32_26_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_26_reg)=data)
#define  get_SE_HCOEF1_32_26_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_26_reg))
#define  SE_HCOEF1_32_26_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_26_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_26_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_26_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_27                                                         0x1800C3EC
#define  SE_HCOEF1_32_27_reg_addr                                                "0xB800C3EC"
#define  SE_HCOEF1_32_27_reg                                                     0xB800C3EC
#define  SE_HCOEF1_32_27_inst_addr                                               "0x0089"
#define  set_SE_HCOEF1_32_27_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_27_reg)=data)
#define  get_SE_HCOEF1_32_27_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_27_reg))
#define  SE_HCOEF1_32_27_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_27_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_27_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_27_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_28                                                         0x1800C3F0
#define  SE_HCOEF1_32_28_reg_addr                                                "0xB800C3F0"
#define  SE_HCOEF1_32_28_reg                                                     0xB800C3F0
#define  SE_HCOEF1_32_28_inst_addr                                               "0x008A"
#define  set_SE_HCOEF1_32_28_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_28_reg)=data)
#define  get_SE_HCOEF1_32_28_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_28_reg))
#define  SE_HCOEF1_32_28_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_28_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_28_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_28_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_29                                                         0x1800C3F4
#define  SE_HCOEF1_32_29_reg_addr                                                "0xB800C3F4"
#define  SE_HCOEF1_32_29_reg                                                     0xB800C3F4
#define  SE_HCOEF1_32_29_inst_addr                                               "0x008B"
#define  set_SE_HCOEF1_32_29_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_29_reg)=data)
#define  get_SE_HCOEF1_32_29_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_29_reg))
#define  SE_HCOEF1_32_29_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_29_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_29_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_29_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_30                                                         0x1800C3F8
#define  SE_HCOEF1_32_30_reg_addr                                                "0xB800C3F8"
#define  SE_HCOEF1_32_30_reg                                                     0xB800C3F8
#define  SE_HCOEF1_32_30_inst_addr                                               "0x008C"
#define  set_SE_HCOEF1_32_30_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_30_reg)=data)
#define  get_SE_HCOEF1_32_30_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_30_reg))
#define  SE_HCOEF1_32_30_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_30_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_30_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_30_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF1_32_31                                                         0x1800C3FC
#define  SE_HCOEF1_32_31_reg_addr                                                "0xB800C3FC"
#define  SE_HCOEF1_32_31_reg                                                     0xB800C3FC
#define  SE_HCOEF1_32_31_inst_addr                                               "0x008D"
#define  set_SE_HCOEF1_32_31_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF1_32_31_reg)=data)
#define  get_SE_HCOEF1_32_31_reg                                                 (*((volatile unsigned int*)SE_HCOEF1_32_31_reg))
#define  SE_HCOEF1_32_31_hcoef_shift                                             (0)
#define  SE_HCOEF1_32_31_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF1_32_31_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF1_32_31_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF1_0                                                             0x1800C400
#define  SE_VCOEF1_0_reg_addr                                                    "0xB800C400"
#define  SE_VCOEF1_0_reg                                                         0xB800C400
#define  SE_VCOEF1_0_inst_addr                                                   "0x008E"
#define  set_SE_VCOEF1_0_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_0_reg)=data)
#define  get_SE_VCOEF1_0_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_0_reg))
#define  SE_VCOEF1_0_vcoef_shift                                                 (0)
#define  SE_VCOEF1_0_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_0_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_0_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_1                                                             0x1800C404
#define  SE_VCOEF1_1_reg_addr                                                    "0xB800C404"
#define  SE_VCOEF1_1_reg                                                         0xB800C404
#define  SE_VCOEF1_1_inst_addr                                                   "0x008F"
#define  set_SE_VCOEF1_1_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_1_reg)=data)
#define  get_SE_VCOEF1_1_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_1_reg))
#define  SE_VCOEF1_1_vcoef_shift                                                 (0)
#define  SE_VCOEF1_1_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_1_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_1_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_2                                                             0x1800C408
#define  SE_VCOEF1_2_reg_addr                                                    "0xB800C408"
#define  SE_VCOEF1_2_reg                                                         0xB800C408
#define  SE_VCOEF1_2_inst_addr                                                   "0x0090"
#define  set_SE_VCOEF1_2_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_2_reg)=data)
#define  get_SE_VCOEF1_2_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_2_reg))
#define  SE_VCOEF1_2_vcoef_shift                                                 (0)
#define  SE_VCOEF1_2_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_2_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_2_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_3                                                             0x1800C40C
#define  SE_VCOEF1_3_reg_addr                                                    "0xB800C40C"
#define  SE_VCOEF1_3_reg                                                         0xB800C40C
#define  SE_VCOEF1_3_inst_addr                                                   "0x0091"
#define  set_SE_VCOEF1_3_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_3_reg)=data)
#define  get_SE_VCOEF1_3_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_3_reg))
#define  SE_VCOEF1_3_vcoef_shift                                                 (0)
#define  SE_VCOEF1_3_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_3_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_3_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_4                                                             0x1800C410
#define  SE_VCOEF1_4_reg_addr                                                    "0xB800C410"
#define  SE_VCOEF1_4_reg                                                         0xB800C410
#define  SE_VCOEF1_4_inst_addr                                                   "0x0092"
#define  set_SE_VCOEF1_4_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_4_reg)=data)
#define  get_SE_VCOEF1_4_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_4_reg))
#define  SE_VCOEF1_4_vcoef_shift                                                 (0)
#define  SE_VCOEF1_4_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_4_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_4_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_5                                                             0x1800C414
#define  SE_VCOEF1_5_reg_addr                                                    "0xB800C414"
#define  SE_VCOEF1_5_reg                                                         0xB800C414
#define  SE_VCOEF1_5_inst_addr                                                   "0x0093"
#define  set_SE_VCOEF1_5_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_5_reg)=data)
#define  get_SE_VCOEF1_5_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_5_reg))
#define  SE_VCOEF1_5_vcoef_shift                                                 (0)
#define  SE_VCOEF1_5_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_5_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_5_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_6                                                             0x1800C418
#define  SE_VCOEF1_6_reg_addr                                                    "0xB800C418"
#define  SE_VCOEF1_6_reg                                                         0xB800C418
#define  SE_VCOEF1_6_inst_addr                                                   "0x0094"
#define  set_SE_VCOEF1_6_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_6_reg)=data)
#define  get_SE_VCOEF1_6_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_6_reg))
#define  SE_VCOEF1_6_vcoef_shift                                                 (0)
#define  SE_VCOEF1_6_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_6_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_6_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_7                                                             0x1800C41C
#define  SE_VCOEF1_7_reg_addr                                                    "0xB800C41C"
#define  SE_VCOEF1_7_reg                                                         0xB800C41C
#define  SE_VCOEF1_7_inst_addr                                                   "0x0095"
#define  set_SE_VCOEF1_7_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_7_reg)=data)
#define  get_SE_VCOEF1_7_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_7_reg))
#define  SE_VCOEF1_7_vcoef_shift                                                 (0)
#define  SE_VCOEF1_7_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_7_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_7_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_8                                                             0x1800C420
#define  SE_VCOEF1_8_reg_addr                                                    "0xB800C420"
#define  SE_VCOEF1_8_reg                                                         0xB800C420
#define  SE_VCOEF1_8_inst_addr                                                   "0x0096"
#define  set_SE_VCOEF1_8_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_8_reg)=data)
#define  get_SE_VCOEF1_8_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_8_reg))
#define  SE_VCOEF1_8_vcoef_shift                                                 (0)
#define  SE_VCOEF1_8_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_8_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_8_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_9                                                             0x1800C424
#define  SE_VCOEF1_9_reg_addr                                                    "0xB800C424"
#define  SE_VCOEF1_9_reg                                                         0xB800C424
#define  SE_VCOEF1_9_inst_addr                                                   "0x0097"
#define  set_SE_VCOEF1_9_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF1_9_reg)=data)
#define  get_SE_VCOEF1_9_reg                                                     (*((volatile unsigned int*)SE_VCOEF1_9_reg))
#define  SE_VCOEF1_9_vcoef_shift                                                 (0)
#define  SE_VCOEF1_9_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF1_9_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF1_9_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF1_10                                                            0x1800C428
#define  SE_VCOEF1_10_reg_addr                                                   "0xB800C428"
#define  SE_VCOEF1_10_reg                                                        0xB800C428
#define  SE_VCOEF1_10_inst_addr                                                  "0x0098"
#define  set_SE_VCOEF1_10_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF1_10_reg)=data)
#define  get_SE_VCOEF1_10_reg                                                    (*((volatile unsigned int*)SE_VCOEF1_10_reg))
#define  SE_VCOEF1_10_vcoef_shift                                                (0)
#define  SE_VCOEF1_10_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF1_10_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF1_10_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF1_11                                                            0x1800C42C
#define  SE_VCOEF1_11_reg_addr                                                   "0xB800C42C"
#define  SE_VCOEF1_11_reg                                                        0xB800C42C
#define  SE_VCOEF1_11_inst_addr                                                  "0x0099"
#define  set_SE_VCOEF1_11_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF1_11_reg)=data)
#define  get_SE_VCOEF1_11_reg                                                    (*((volatile unsigned int*)SE_VCOEF1_11_reg))
#define  SE_VCOEF1_11_vcoef_shift                                                (0)
#define  SE_VCOEF1_11_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF1_11_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF1_11_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF1_12                                                            0x1800C430
#define  SE_VCOEF1_12_reg_addr                                                   "0xB800C430"
#define  SE_VCOEF1_12_reg                                                        0xB800C430
#define  SE_VCOEF1_12_inst_addr                                                  "0x009A"
#define  set_SE_VCOEF1_12_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF1_12_reg)=data)
#define  get_SE_VCOEF1_12_reg                                                    (*((volatile unsigned int*)SE_VCOEF1_12_reg))
#define  SE_VCOEF1_12_vcoef_shift                                                (0)
#define  SE_VCOEF1_12_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF1_12_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF1_12_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF1_13                                                            0x1800C434
#define  SE_VCOEF1_13_reg_addr                                                   "0xB800C434"
#define  SE_VCOEF1_13_reg                                                        0xB800C434
#define  SE_VCOEF1_13_inst_addr                                                  "0x009B"
#define  set_SE_VCOEF1_13_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF1_13_reg)=data)
#define  get_SE_VCOEF1_13_reg                                                    (*((volatile unsigned int*)SE_VCOEF1_13_reg))
#define  SE_VCOEF1_13_vcoef_shift                                                (0)
#define  SE_VCOEF1_13_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF1_13_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF1_13_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF1_14                                                            0x1800C438
#define  SE_VCOEF1_14_reg_addr                                                   "0xB800C438"
#define  SE_VCOEF1_14_reg                                                        0xB800C438
#define  SE_VCOEF1_14_inst_addr                                                  "0x009C"
#define  set_SE_VCOEF1_14_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF1_14_reg)=data)
#define  get_SE_VCOEF1_14_reg                                                    (*((volatile unsigned int*)SE_VCOEF1_14_reg))
#define  SE_VCOEF1_14_vcoef_shift                                                (0)
#define  SE_VCOEF1_14_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF1_14_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF1_14_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF1_15                                                            0x1800C43C
#define  SE_VCOEF1_15_reg_addr                                                   "0xB800C43C"
#define  SE_VCOEF1_15_reg                                                        0xB800C43C
#define  SE_VCOEF1_15_inst_addr                                                  "0x009D"
#define  set_SE_VCOEF1_15_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF1_15_reg)=data)
#define  get_SE_VCOEF1_15_reg                                                    (*((volatile unsigned int*)SE_VCOEF1_15_reg))
#define  SE_VCOEF1_15_vcoef_shift                                                (0)
#define  SE_VCOEF1_15_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF1_15_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF1_15_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF1_16_0                                                          0x1800C440
#define  SE_VCOEF1_16_0_reg_addr                                                 "0xB800C440"
#define  SE_VCOEF1_16_0_reg                                                      0xB800C440
#define  SE_VCOEF1_16_0_inst_addr                                                "0x009E"
#define  set_SE_VCOEF1_16_0_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_0_reg)=data)
#define  get_SE_VCOEF1_16_0_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_0_reg))
#define  SE_VCOEF1_16_0_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_0_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_0_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_0_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_1                                                          0x1800C444
#define  SE_VCOEF1_16_1_reg_addr                                                 "0xB800C444"
#define  SE_VCOEF1_16_1_reg                                                      0xB800C444
#define  SE_VCOEF1_16_1_inst_addr                                                "0x009F"
#define  set_SE_VCOEF1_16_1_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_1_reg)=data)
#define  get_SE_VCOEF1_16_1_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_1_reg))
#define  SE_VCOEF1_16_1_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_1_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_1_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_1_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_2                                                          0x1800C448
#define  SE_VCOEF1_16_2_reg_addr                                                 "0xB800C448"
#define  SE_VCOEF1_16_2_reg                                                      0xB800C448
#define  SE_VCOEF1_16_2_inst_addr                                                "0x00A0"
#define  set_SE_VCOEF1_16_2_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_2_reg)=data)
#define  get_SE_VCOEF1_16_2_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_2_reg))
#define  SE_VCOEF1_16_2_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_2_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_2_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_2_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_3                                                          0x1800C44C
#define  SE_VCOEF1_16_3_reg_addr                                                 "0xB800C44C"
#define  SE_VCOEF1_16_3_reg                                                      0xB800C44C
#define  SE_VCOEF1_16_3_inst_addr                                                "0x00A1"
#define  set_SE_VCOEF1_16_3_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_3_reg)=data)
#define  get_SE_VCOEF1_16_3_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_3_reg))
#define  SE_VCOEF1_16_3_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_3_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_3_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_3_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_4                                                          0x1800C450
#define  SE_VCOEF1_16_4_reg_addr                                                 "0xB800C450"
#define  SE_VCOEF1_16_4_reg                                                      0xB800C450
#define  SE_VCOEF1_16_4_inst_addr                                                "0x00A2"
#define  set_SE_VCOEF1_16_4_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_4_reg)=data)
#define  get_SE_VCOEF1_16_4_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_4_reg))
#define  SE_VCOEF1_16_4_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_4_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_4_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_4_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_5                                                          0x1800C454
#define  SE_VCOEF1_16_5_reg_addr                                                 "0xB800C454"
#define  SE_VCOEF1_16_5_reg                                                      0xB800C454
#define  SE_VCOEF1_16_5_inst_addr                                                "0x00A3"
#define  set_SE_VCOEF1_16_5_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_5_reg)=data)
#define  get_SE_VCOEF1_16_5_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_5_reg))
#define  SE_VCOEF1_16_5_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_5_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_5_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_5_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_6                                                          0x1800C458
#define  SE_VCOEF1_16_6_reg_addr                                                 "0xB800C458"
#define  SE_VCOEF1_16_6_reg                                                      0xB800C458
#define  SE_VCOEF1_16_6_inst_addr                                                "0x00A4"
#define  set_SE_VCOEF1_16_6_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_6_reg)=data)
#define  get_SE_VCOEF1_16_6_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_6_reg))
#define  SE_VCOEF1_16_6_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_6_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_6_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_6_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_7                                                          0x1800C45C
#define  SE_VCOEF1_16_7_reg_addr                                                 "0xB800C45C"
#define  SE_VCOEF1_16_7_reg                                                      0xB800C45C
#define  SE_VCOEF1_16_7_inst_addr                                                "0x00A5"
#define  set_SE_VCOEF1_16_7_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_7_reg)=data)
#define  get_SE_VCOEF1_16_7_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_7_reg))
#define  SE_VCOEF1_16_7_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_7_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_7_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_7_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_8                                                          0x1800C460
#define  SE_VCOEF1_16_8_reg_addr                                                 "0xB800C460"
#define  SE_VCOEF1_16_8_reg                                                      0xB800C460
#define  SE_VCOEF1_16_8_inst_addr                                                "0x00A6"
#define  set_SE_VCOEF1_16_8_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_8_reg)=data)
#define  get_SE_VCOEF1_16_8_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_8_reg))
#define  SE_VCOEF1_16_8_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_8_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_8_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_8_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_9                                                          0x1800C464
#define  SE_VCOEF1_16_9_reg_addr                                                 "0xB800C464"
#define  SE_VCOEF1_16_9_reg                                                      0xB800C464
#define  SE_VCOEF1_16_9_inst_addr                                                "0x00A7"
#define  set_SE_VCOEF1_16_9_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF1_16_9_reg)=data)
#define  get_SE_VCOEF1_16_9_reg                                                  (*((volatile unsigned int*)SE_VCOEF1_16_9_reg))
#define  SE_VCOEF1_16_9_vcoef_shift                                              (0)
#define  SE_VCOEF1_16_9_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF1_16_9_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF1_16_9_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF1_16_10                                                         0x1800C468
#define  SE_VCOEF1_16_10_reg_addr                                                "0xB800C468"
#define  SE_VCOEF1_16_10_reg                                                     0xB800C468
#define  SE_VCOEF1_16_10_inst_addr                                               "0x00A8"
#define  set_SE_VCOEF1_16_10_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF1_16_10_reg)=data)
#define  get_SE_VCOEF1_16_10_reg                                                 (*((volatile unsigned int*)SE_VCOEF1_16_10_reg))
#define  SE_VCOEF1_16_10_vcoef_shift                                             (0)
#define  SE_VCOEF1_16_10_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF1_16_10_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF1_16_10_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF1_16_11                                                         0x1800C46C
#define  SE_VCOEF1_16_11_reg_addr                                                "0xB800C46C"
#define  SE_VCOEF1_16_11_reg                                                     0xB800C46C
#define  SE_VCOEF1_16_11_inst_addr                                               "0x00A9"
#define  set_SE_VCOEF1_16_11_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF1_16_11_reg)=data)
#define  get_SE_VCOEF1_16_11_reg                                                 (*((volatile unsigned int*)SE_VCOEF1_16_11_reg))
#define  SE_VCOEF1_16_11_vcoef_shift                                             (0)
#define  SE_VCOEF1_16_11_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF1_16_11_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF1_16_11_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF1_16_12                                                         0x1800C470
#define  SE_VCOEF1_16_12_reg_addr                                                "0xB800C470"
#define  SE_VCOEF1_16_12_reg                                                     0xB800C470
#define  SE_VCOEF1_16_12_inst_addr                                               "0x00AA"
#define  set_SE_VCOEF1_16_12_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF1_16_12_reg)=data)
#define  get_SE_VCOEF1_16_12_reg                                                 (*((volatile unsigned int*)SE_VCOEF1_16_12_reg))
#define  SE_VCOEF1_16_12_vcoef_shift                                             (0)
#define  SE_VCOEF1_16_12_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF1_16_12_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF1_16_12_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF1_16_13                                                         0x1800C474
#define  SE_VCOEF1_16_13_reg_addr                                                "0xB800C474"
#define  SE_VCOEF1_16_13_reg                                                     0xB800C474
#define  SE_VCOEF1_16_13_inst_addr                                               "0x00AB"
#define  set_SE_VCOEF1_16_13_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF1_16_13_reg)=data)
#define  get_SE_VCOEF1_16_13_reg                                                 (*((volatile unsigned int*)SE_VCOEF1_16_13_reg))
#define  SE_VCOEF1_16_13_vcoef_shift                                             (0)
#define  SE_VCOEF1_16_13_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF1_16_13_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF1_16_13_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF1_16_14                                                         0x1800C478
#define  SE_VCOEF1_16_14_reg_addr                                                "0xB800C478"
#define  SE_VCOEF1_16_14_reg                                                     0xB800C478
#define  SE_VCOEF1_16_14_inst_addr                                               "0x00AC"
#define  set_SE_VCOEF1_16_14_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF1_16_14_reg)=data)
#define  get_SE_VCOEF1_16_14_reg                                                 (*((volatile unsigned int*)SE_VCOEF1_16_14_reg))
#define  SE_VCOEF1_16_14_vcoef_shift                                             (0)
#define  SE_VCOEF1_16_14_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF1_16_14_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF1_16_14_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF1_16_15                                                         0x1800C47C
#define  SE_VCOEF1_16_15_reg_addr                                                "0xB800C47C"
#define  SE_VCOEF1_16_15_reg                                                     0xB800C47C
#define  SE_VCOEF1_16_15_inst_addr                                               "0x00AD"
#define  set_SE_VCOEF1_16_15_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF1_16_15_reg)=data)
#define  get_SE_VCOEF1_16_15_reg                                                 (*((volatile unsigned int*)SE_VCOEF1_16_15_reg))
#define  SE_VCOEF1_16_15_vcoef_shift                                             (0)
#define  SE_VCOEF1_16_15_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF1_16_15_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF1_16_15_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_0                                                             0x1800C480
#define  SE_HCOEF2_0_reg_addr                                                    "0xB800C480"
#define  SE_HCOEF2_0_reg                                                         0xB800C480
#define  SE_HCOEF2_0_inst_addr                                                   "0x00AE"
#define  set_SE_HCOEF2_0_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_0_reg)=data)
#define  get_SE_HCOEF2_0_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_0_reg))
#define  SE_HCOEF2_0_hcoef_shift                                                 (0)
#define  SE_HCOEF2_0_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_0_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_0_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_1                                                             0x1800C484
#define  SE_HCOEF2_1_reg_addr                                                    "0xB800C484"
#define  SE_HCOEF2_1_reg                                                         0xB800C484
#define  SE_HCOEF2_1_inst_addr                                                   "0x00AF"
#define  set_SE_HCOEF2_1_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_1_reg)=data)
#define  get_SE_HCOEF2_1_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_1_reg))
#define  SE_HCOEF2_1_hcoef_shift                                                 (0)
#define  SE_HCOEF2_1_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_1_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_1_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_2                                                             0x1800C488
#define  SE_HCOEF2_2_reg_addr                                                    "0xB800C488"
#define  SE_HCOEF2_2_reg                                                         0xB800C488
#define  SE_HCOEF2_2_inst_addr                                                   "0x00B0"
#define  set_SE_HCOEF2_2_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_2_reg)=data)
#define  get_SE_HCOEF2_2_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_2_reg))
#define  SE_HCOEF2_2_hcoef_shift                                                 (0)
#define  SE_HCOEF2_2_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_2_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_2_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_3                                                             0x1800C48C
#define  SE_HCOEF2_3_reg_addr                                                    "0xB800C48C"
#define  SE_HCOEF2_3_reg                                                         0xB800C48C
#define  SE_HCOEF2_3_inst_addr                                                   "0x00B1"
#define  set_SE_HCOEF2_3_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_3_reg)=data)
#define  get_SE_HCOEF2_3_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_3_reg))
#define  SE_HCOEF2_3_hcoef_shift                                                 (0)
#define  SE_HCOEF2_3_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_3_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_3_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_4                                                             0x1800C490
#define  SE_HCOEF2_4_reg_addr                                                    "0xB800C490"
#define  SE_HCOEF2_4_reg                                                         0xB800C490
#define  SE_HCOEF2_4_inst_addr                                                   "0x00B2"
#define  set_SE_HCOEF2_4_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_4_reg)=data)
#define  get_SE_HCOEF2_4_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_4_reg))
#define  SE_HCOEF2_4_hcoef_shift                                                 (0)
#define  SE_HCOEF2_4_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_4_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_4_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_5                                                             0x1800C494
#define  SE_HCOEF2_5_reg_addr                                                    "0xB800C494"
#define  SE_HCOEF2_5_reg                                                         0xB800C494
#define  SE_HCOEF2_5_inst_addr                                                   "0x00B3"
#define  set_SE_HCOEF2_5_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_5_reg)=data)
#define  get_SE_HCOEF2_5_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_5_reg))
#define  SE_HCOEF2_5_hcoef_shift                                                 (0)
#define  SE_HCOEF2_5_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_5_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_5_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_6                                                             0x1800C498
#define  SE_HCOEF2_6_reg_addr                                                    "0xB800C498"
#define  SE_HCOEF2_6_reg                                                         0xB800C498
#define  SE_HCOEF2_6_inst_addr                                                   "0x00B4"
#define  set_SE_HCOEF2_6_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_6_reg)=data)
#define  get_SE_HCOEF2_6_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_6_reg))
#define  SE_HCOEF2_6_hcoef_shift                                                 (0)
#define  SE_HCOEF2_6_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_6_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_6_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_7                                                             0x1800C49C
#define  SE_HCOEF2_7_reg_addr                                                    "0xB800C49C"
#define  SE_HCOEF2_7_reg                                                         0xB800C49C
#define  SE_HCOEF2_7_inst_addr                                                   "0x00B5"
#define  set_SE_HCOEF2_7_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_7_reg)=data)
#define  get_SE_HCOEF2_7_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_7_reg))
#define  SE_HCOEF2_7_hcoef_shift                                                 (0)
#define  SE_HCOEF2_7_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_7_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_7_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_8                                                             0x1800C4A0
#define  SE_HCOEF2_8_reg_addr                                                    "0xB800C4A0"
#define  SE_HCOEF2_8_reg                                                         0xB800C4A0
#define  SE_HCOEF2_8_inst_addr                                                   "0x00B6"
#define  set_SE_HCOEF2_8_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_8_reg)=data)
#define  get_SE_HCOEF2_8_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_8_reg))
#define  SE_HCOEF2_8_hcoef_shift                                                 (0)
#define  SE_HCOEF2_8_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_8_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_8_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_9                                                             0x1800C4A4
#define  SE_HCOEF2_9_reg_addr                                                    "0xB800C4A4"
#define  SE_HCOEF2_9_reg                                                         0xB800C4A4
#define  SE_HCOEF2_9_inst_addr                                                   "0x00B7"
#define  set_SE_HCOEF2_9_reg(data)                                               (*((volatile unsigned int*)SE_HCOEF2_9_reg)=data)
#define  get_SE_HCOEF2_9_reg                                                     (*((volatile unsigned int*)SE_HCOEF2_9_reg))
#define  SE_HCOEF2_9_hcoef_shift                                                 (0)
#define  SE_HCOEF2_9_hcoef_mask                                                  (0x00003FFF)
#define  SE_HCOEF2_9_hcoef(data)                                                 (0x00003FFF&(data))
#define  SE_HCOEF2_9_get_hcoef(data)                                             (0x00003FFF&(data))

#define  SE_HCOEF2_10                                                            0x1800C4A8
#define  SE_HCOEF2_10_reg_addr                                                   "0xB800C4A8"
#define  SE_HCOEF2_10_reg                                                        0xB800C4A8
#define  SE_HCOEF2_10_inst_addr                                                  "0x00B8"
#define  set_SE_HCOEF2_10_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_10_reg)=data)
#define  get_SE_HCOEF2_10_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_10_reg))
#define  SE_HCOEF2_10_hcoef_shift                                                (0)
#define  SE_HCOEF2_10_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_10_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_10_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_11                                                            0x1800C4AC
#define  SE_HCOEF2_11_reg_addr                                                   "0xB800C4AC"
#define  SE_HCOEF2_11_reg                                                        0xB800C4AC
#define  SE_HCOEF2_11_inst_addr                                                  "0x00B9"
#define  set_SE_HCOEF2_11_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_11_reg)=data)
#define  get_SE_HCOEF2_11_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_11_reg))
#define  SE_HCOEF2_11_hcoef_shift                                                (0)
#define  SE_HCOEF2_11_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_11_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_11_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_12                                                            0x1800C4B0
#define  SE_HCOEF2_12_reg_addr                                                   "0xB800C4B0"
#define  SE_HCOEF2_12_reg                                                        0xB800C4B0
#define  SE_HCOEF2_12_inst_addr                                                  "0x00BA"
#define  set_SE_HCOEF2_12_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_12_reg)=data)
#define  get_SE_HCOEF2_12_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_12_reg))
#define  SE_HCOEF2_12_hcoef_shift                                                (0)
#define  SE_HCOEF2_12_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_12_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_12_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_13                                                            0x1800C4B4
#define  SE_HCOEF2_13_reg_addr                                                   "0xB800C4B4"
#define  SE_HCOEF2_13_reg                                                        0xB800C4B4
#define  SE_HCOEF2_13_inst_addr                                                  "0x00BB"
#define  set_SE_HCOEF2_13_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_13_reg)=data)
#define  get_SE_HCOEF2_13_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_13_reg))
#define  SE_HCOEF2_13_hcoef_shift                                                (0)
#define  SE_HCOEF2_13_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_13_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_13_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_14                                                            0x1800C4B8
#define  SE_HCOEF2_14_reg_addr                                                   "0xB800C4B8"
#define  SE_HCOEF2_14_reg                                                        0xB800C4B8
#define  SE_HCOEF2_14_inst_addr                                                  "0x00BC"
#define  set_SE_HCOEF2_14_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_14_reg)=data)
#define  get_SE_HCOEF2_14_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_14_reg))
#define  SE_HCOEF2_14_hcoef_shift                                                (0)
#define  SE_HCOEF2_14_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_14_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_14_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_15                                                            0x1800C4BC
#define  SE_HCOEF2_15_reg_addr                                                   "0xB800C4BC"
#define  SE_HCOEF2_15_reg                                                        0xB800C4BC
#define  SE_HCOEF2_15_inst_addr                                                  "0x00BD"
#define  set_SE_HCOEF2_15_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_15_reg)=data)
#define  get_SE_HCOEF2_15_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_15_reg))
#define  SE_HCOEF2_15_hcoef_shift                                                (0)
#define  SE_HCOEF2_15_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_15_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_15_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_16                                                            0x1800C4C0
#define  SE_HCOEF2_16_reg_addr                                                   "0xB800C4C0"
#define  SE_HCOEF2_16_reg                                                        0xB800C4C0
#define  SE_HCOEF2_16_inst_addr                                                  "0x00BE"
#define  set_SE_HCOEF2_16_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_16_reg)=data)
#define  get_SE_HCOEF2_16_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_16_reg))
#define  SE_HCOEF2_16_hcoef_shift                                                (0)
#define  SE_HCOEF2_16_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_16_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_16_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_17                                                            0x1800C4C4
#define  SE_HCOEF2_17_reg_addr                                                   "0xB800C4C4"
#define  SE_HCOEF2_17_reg                                                        0xB800C4C4
#define  SE_HCOEF2_17_inst_addr                                                  "0x00BF"
#define  set_SE_HCOEF2_17_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_17_reg)=data)
#define  get_SE_HCOEF2_17_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_17_reg))
#define  SE_HCOEF2_17_hcoef_shift                                                (0)
#define  SE_HCOEF2_17_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_17_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_17_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_18                                                            0x1800C4C8
#define  SE_HCOEF2_18_reg_addr                                                   "0xB800C4C8"
#define  SE_HCOEF2_18_reg                                                        0xB800C4C8
#define  SE_HCOEF2_18_inst_addr                                                  "0x00C0"
#define  set_SE_HCOEF2_18_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_18_reg)=data)
#define  get_SE_HCOEF2_18_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_18_reg))
#define  SE_HCOEF2_18_hcoef_shift                                                (0)
#define  SE_HCOEF2_18_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_18_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_18_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_19                                                            0x1800C4CC
#define  SE_HCOEF2_19_reg_addr                                                   "0xB800C4CC"
#define  SE_HCOEF2_19_reg                                                        0xB800C4CC
#define  SE_HCOEF2_19_inst_addr                                                  "0x00C1"
#define  set_SE_HCOEF2_19_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_19_reg)=data)
#define  get_SE_HCOEF2_19_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_19_reg))
#define  SE_HCOEF2_19_hcoef_shift                                                (0)
#define  SE_HCOEF2_19_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_19_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_19_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_20                                                            0x1800C4D0
#define  SE_HCOEF2_20_reg_addr                                                   "0xB800C4D0"
#define  SE_HCOEF2_20_reg                                                        0xB800C4D0
#define  SE_HCOEF2_20_inst_addr                                                  "0x00C2"
#define  set_SE_HCOEF2_20_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_20_reg)=data)
#define  get_SE_HCOEF2_20_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_20_reg))
#define  SE_HCOEF2_20_hcoef_shift                                                (0)
#define  SE_HCOEF2_20_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_20_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_20_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_21                                                            0x1800C4D4
#define  SE_HCOEF2_21_reg_addr                                                   "0xB800C4D4"
#define  SE_HCOEF2_21_reg                                                        0xB800C4D4
#define  SE_HCOEF2_21_inst_addr                                                  "0x00C3"
#define  set_SE_HCOEF2_21_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_21_reg)=data)
#define  get_SE_HCOEF2_21_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_21_reg))
#define  SE_HCOEF2_21_hcoef_shift                                                (0)
#define  SE_HCOEF2_21_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_21_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_21_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_22                                                            0x1800C4D8
#define  SE_HCOEF2_22_reg_addr                                                   "0xB800C4D8"
#define  SE_HCOEF2_22_reg                                                        0xB800C4D8
#define  SE_HCOEF2_22_inst_addr                                                  "0x00C4"
#define  set_SE_HCOEF2_22_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_22_reg)=data)
#define  get_SE_HCOEF2_22_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_22_reg))
#define  SE_HCOEF2_22_hcoef_shift                                                (0)
#define  SE_HCOEF2_22_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_22_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_22_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_23                                                            0x1800C4DC
#define  SE_HCOEF2_23_reg_addr                                                   "0xB800C4DC"
#define  SE_HCOEF2_23_reg                                                        0xB800C4DC
#define  SE_HCOEF2_23_inst_addr                                                  "0x00C5"
#define  set_SE_HCOEF2_23_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_23_reg)=data)
#define  get_SE_HCOEF2_23_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_23_reg))
#define  SE_HCOEF2_23_hcoef_shift                                                (0)
#define  SE_HCOEF2_23_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_23_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_23_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_24                                                            0x1800C4E0
#define  SE_HCOEF2_24_reg_addr                                                   "0xB800C4E0"
#define  SE_HCOEF2_24_reg                                                        0xB800C4E0
#define  SE_HCOEF2_24_inst_addr                                                  "0x00C6"
#define  set_SE_HCOEF2_24_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_24_reg)=data)
#define  get_SE_HCOEF2_24_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_24_reg))
#define  SE_HCOEF2_24_hcoef_shift                                                (0)
#define  SE_HCOEF2_24_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_24_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_24_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_25                                                            0x1800C4E4
#define  SE_HCOEF2_25_reg_addr                                                   "0xB800C4E4"
#define  SE_HCOEF2_25_reg                                                        0xB800C4E4
#define  SE_HCOEF2_25_inst_addr                                                  "0x00C7"
#define  set_SE_HCOEF2_25_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_25_reg)=data)
#define  get_SE_HCOEF2_25_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_25_reg))
#define  SE_HCOEF2_25_hcoef_shift                                                (0)
#define  SE_HCOEF2_25_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_25_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_25_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_26                                                            0x1800C4E8
#define  SE_HCOEF2_26_reg_addr                                                   "0xB800C4E8"
#define  SE_HCOEF2_26_reg                                                        0xB800C4E8
#define  SE_HCOEF2_26_inst_addr                                                  "0x00C8"
#define  set_SE_HCOEF2_26_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_26_reg)=data)
#define  get_SE_HCOEF2_26_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_26_reg))
#define  SE_HCOEF2_26_hcoef_shift                                                (0)
#define  SE_HCOEF2_26_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_26_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_26_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_27                                                            0x1800C4EC
#define  SE_HCOEF2_27_reg_addr                                                   "0xB800C4EC"
#define  SE_HCOEF2_27_reg                                                        0xB800C4EC
#define  SE_HCOEF2_27_inst_addr                                                  "0x00C9"
#define  set_SE_HCOEF2_27_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_27_reg)=data)
#define  get_SE_HCOEF2_27_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_27_reg))
#define  SE_HCOEF2_27_hcoef_shift                                                (0)
#define  SE_HCOEF2_27_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_27_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_27_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_28                                                            0x1800C4F0
#define  SE_HCOEF2_28_reg_addr                                                   "0xB800C4F0"
#define  SE_HCOEF2_28_reg                                                        0xB800C4F0
#define  SE_HCOEF2_28_inst_addr                                                  "0x00CA"
#define  set_SE_HCOEF2_28_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_28_reg)=data)
#define  get_SE_HCOEF2_28_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_28_reg))
#define  SE_HCOEF2_28_hcoef_shift                                                (0)
#define  SE_HCOEF2_28_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_28_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_28_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_29                                                            0x1800C4F4
#define  SE_HCOEF2_29_reg_addr                                                   "0xB800C4F4"
#define  SE_HCOEF2_29_reg                                                        0xB800C4F4
#define  SE_HCOEF2_29_inst_addr                                                  "0x00CB"
#define  set_SE_HCOEF2_29_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_29_reg)=data)
#define  get_SE_HCOEF2_29_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_29_reg))
#define  SE_HCOEF2_29_hcoef_shift                                                (0)
#define  SE_HCOEF2_29_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_29_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_29_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_30                                                            0x1800C4F8
#define  SE_HCOEF2_30_reg_addr                                                   "0xB800C4F8"
#define  SE_HCOEF2_30_reg                                                        0xB800C4F8
#define  SE_HCOEF2_30_inst_addr                                                  "0x00CC"
#define  set_SE_HCOEF2_30_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_30_reg)=data)
#define  get_SE_HCOEF2_30_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_30_reg))
#define  SE_HCOEF2_30_hcoef_shift                                                (0)
#define  SE_HCOEF2_30_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_30_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_30_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_31                                                            0x1800C4FC
#define  SE_HCOEF2_31_reg_addr                                                   "0xB800C4FC"
#define  SE_HCOEF2_31_reg                                                        0xB800C4FC
#define  SE_HCOEF2_31_inst_addr                                                  "0x00CD"
#define  set_SE_HCOEF2_31_reg(data)                                              (*((volatile unsigned int*)SE_HCOEF2_31_reg)=data)
#define  get_SE_HCOEF2_31_reg                                                    (*((volatile unsigned int*)SE_HCOEF2_31_reg))
#define  SE_HCOEF2_31_hcoef_shift                                                (0)
#define  SE_HCOEF2_31_hcoef_mask                                                 (0x00003FFF)
#define  SE_HCOEF2_31_hcoef(data)                                                (0x00003FFF&(data))
#define  SE_HCOEF2_31_get_hcoef(data)                                            (0x00003FFF&(data))

#define  SE_HCOEF2_32_0                                                          0x1800C500
#define  SE_HCOEF2_32_0_reg_addr                                                 "0xB800C500"
#define  SE_HCOEF2_32_0_reg                                                      0xB800C500
#define  SE_HCOEF2_32_0_inst_addr                                                "0x00CE"
#define  set_SE_HCOEF2_32_0_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_0_reg)=data)
#define  get_SE_HCOEF2_32_0_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_0_reg))
#define  SE_HCOEF2_32_0_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_0_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_0_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_0_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_1                                                          0x1800C504
#define  SE_HCOEF2_32_1_reg_addr                                                 "0xB800C504"
#define  SE_HCOEF2_32_1_reg                                                      0xB800C504
#define  SE_HCOEF2_32_1_inst_addr                                                "0x00CF"
#define  set_SE_HCOEF2_32_1_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_1_reg)=data)
#define  get_SE_HCOEF2_32_1_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_1_reg))
#define  SE_HCOEF2_32_1_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_1_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_1_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_1_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_2                                                          0x1800C508
#define  SE_HCOEF2_32_2_reg_addr                                                 "0xB800C508"
#define  SE_HCOEF2_32_2_reg                                                      0xB800C508
#define  SE_HCOEF2_32_2_inst_addr                                                "0x00D0"
#define  set_SE_HCOEF2_32_2_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_2_reg)=data)
#define  get_SE_HCOEF2_32_2_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_2_reg))
#define  SE_HCOEF2_32_2_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_2_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_2_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_2_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_3                                                          0x1800C50C
#define  SE_HCOEF2_32_3_reg_addr                                                 "0xB800C50C"
#define  SE_HCOEF2_32_3_reg                                                      0xB800C50C
#define  SE_HCOEF2_32_3_inst_addr                                                "0x00D1"
#define  set_SE_HCOEF2_32_3_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_3_reg)=data)
#define  get_SE_HCOEF2_32_3_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_3_reg))
#define  SE_HCOEF2_32_3_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_3_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_3_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_3_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_4                                                          0x1800C510
#define  SE_HCOEF2_32_4_reg_addr                                                 "0xB800C510"
#define  SE_HCOEF2_32_4_reg                                                      0xB800C510
#define  SE_HCOEF2_32_4_inst_addr                                                "0x00D2"
#define  set_SE_HCOEF2_32_4_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_4_reg)=data)
#define  get_SE_HCOEF2_32_4_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_4_reg))
#define  SE_HCOEF2_32_4_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_4_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_4_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_4_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_5                                                          0x1800C514
#define  SE_HCOEF2_32_5_reg_addr                                                 "0xB800C514"
#define  SE_HCOEF2_32_5_reg                                                      0xB800C514
#define  SE_HCOEF2_32_5_inst_addr                                                "0x00D3"
#define  set_SE_HCOEF2_32_5_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_5_reg)=data)
#define  get_SE_HCOEF2_32_5_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_5_reg))
#define  SE_HCOEF2_32_5_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_5_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_5_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_5_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_6                                                          0x1800C518
#define  SE_HCOEF2_32_6_reg_addr                                                 "0xB800C518"
#define  SE_HCOEF2_32_6_reg                                                      0xB800C518
#define  SE_HCOEF2_32_6_inst_addr                                                "0x00D4"
#define  set_SE_HCOEF2_32_6_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_6_reg)=data)
#define  get_SE_HCOEF2_32_6_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_6_reg))
#define  SE_HCOEF2_32_6_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_6_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_6_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_6_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_7                                                          0x1800C51C
#define  SE_HCOEF2_32_7_reg_addr                                                 "0xB800C51C"
#define  SE_HCOEF2_32_7_reg                                                      0xB800C51C
#define  SE_HCOEF2_32_7_inst_addr                                                "0x00D5"
#define  set_SE_HCOEF2_32_7_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_7_reg)=data)
#define  get_SE_HCOEF2_32_7_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_7_reg))
#define  SE_HCOEF2_32_7_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_7_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_7_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_7_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_8                                                          0x1800C520
#define  SE_HCOEF2_32_8_reg_addr                                                 "0xB800C520"
#define  SE_HCOEF2_32_8_reg                                                      0xB800C520
#define  SE_HCOEF2_32_8_inst_addr                                                "0x00D6"
#define  set_SE_HCOEF2_32_8_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_8_reg)=data)
#define  get_SE_HCOEF2_32_8_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_8_reg))
#define  SE_HCOEF2_32_8_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_8_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_8_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_8_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_9                                                          0x1800C524
#define  SE_HCOEF2_32_9_reg_addr                                                 "0xB800C524"
#define  SE_HCOEF2_32_9_reg                                                      0xB800C524
#define  SE_HCOEF2_32_9_inst_addr                                                "0x00D7"
#define  set_SE_HCOEF2_32_9_reg(data)                                            (*((volatile unsigned int*)SE_HCOEF2_32_9_reg)=data)
#define  get_SE_HCOEF2_32_9_reg                                                  (*((volatile unsigned int*)SE_HCOEF2_32_9_reg))
#define  SE_HCOEF2_32_9_hcoef_shift                                              (0)
#define  SE_HCOEF2_32_9_hcoef_mask                                               (0x00003FFF)
#define  SE_HCOEF2_32_9_hcoef(data)                                              (0x00003FFF&(data))
#define  SE_HCOEF2_32_9_get_hcoef(data)                                          (0x00003FFF&(data))

#define  SE_HCOEF2_32_10                                                         0x1800C528
#define  SE_HCOEF2_32_10_reg_addr                                                "0xB800C528"
#define  SE_HCOEF2_32_10_reg                                                     0xB800C528
#define  SE_HCOEF2_32_10_inst_addr                                               "0x00D8"
#define  set_SE_HCOEF2_32_10_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_10_reg)=data)
#define  get_SE_HCOEF2_32_10_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_10_reg))
#define  SE_HCOEF2_32_10_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_10_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_10_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_10_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_11                                                         0x1800C52C
#define  SE_HCOEF2_32_11_reg_addr                                                "0xB800C52C"
#define  SE_HCOEF2_32_11_reg                                                     0xB800C52C
#define  SE_HCOEF2_32_11_inst_addr                                               "0x00D9"
#define  set_SE_HCOEF2_32_11_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_11_reg)=data)
#define  get_SE_HCOEF2_32_11_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_11_reg))
#define  SE_HCOEF2_32_11_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_11_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_11_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_11_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_12                                                         0x1800C530
#define  SE_HCOEF2_32_12_reg_addr                                                "0xB800C530"
#define  SE_HCOEF2_32_12_reg                                                     0xB800C530
#define  SE_HCOEF2_32_12_inst_addr                                               "0x00DA"
#define  set_SE_HCOEF2_32_12_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_12_reg)=data)
#define  get_SE_HCOEF2_32_12_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_12_reg))
#define  SE_HCOEF2_32_12_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_12_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_12_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_12_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_13                                                         0x1800C534
#define  SE_HCOEF2_32_13_reg_addr                                                "0xB800C534"
#define  SE_HCOEF2_32_13_reg                                                     0xB800C534
#define  SE_HCOEF2_32_13_inst_addr                                               "0x00DB"
#define  set_SE_HCOEF2_32_13_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_13_reg)=data)
#define  get_SE_HCOEF2_32_13_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_13_reg))
#define  SE_HCOEF2_32_13_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_13_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_13_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_13_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_14                                                         0x1800C538
#define  SE_HCOEF2_32_14_reg_addr                                                "0xB800C538"
#define  SE_HCOEF2_32_14_reg                                                     0xB800C538
#define  SE_HCOEF2_32_14_inst_addr                                               "0x00DC"
#define  set_SE_HCOEF2_32_14_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_14_reg)=data)
#define  get_SE_HCOEF2_32_14_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_14_reg))
#define  SE_HCOEF2_32_14_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_14_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_14_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_14_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_15                                                         0x1800C53C
#define  SE_HCOEF2_32_15_reg_addr                                                "0xB800C53C"
#define  SE_HCOEF2_32_15_reg                                                     0xB800C53C
#define  SE_HCOEF2_32_15_inst_addr                                               "0x00DD"
#define  set_SE_HCOEF2_32_15_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_15_reg)=data)
#define  get_SE_HCOEF2_32_15_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_15_reg))
#define  SE_HCOEF2_32_15_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_15_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_15_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_15_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_16                                                         0x1800C540
#define  SE_HCOEF2_32_16_reg_addr                                                "0xB800C540"
#define  SE_HCOEF2_32_16_reg                                                     0xB800C540
#define  SE_HCOEF2_32_16_inst_addr                                               "0x00DE"
#define  set_SE_HCOEF2_32_16_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_16_reg)=data)
#define  get_SE_HCOEF2_32_16_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_16_reg))
#define  SE_HCOEF2_32_16_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_16_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_16_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_16_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_17                                                         0x1800C544
#define  SE_HCOEF2_32_17_reg_addr                                                "0xB800C544"
#define  SE_HCOEF2_32_17_reg                                                     0xB800C544
#define  SE_HCOEF2_32_17_inst_addr                                               "0x00DF"
#define  set_SE_HCOEF2_32_17_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_17_reg)=data)
#define  get_SE_HCOEF2_32_17_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_17_reg))
#define  SE_HCOEF2_32_17_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_17_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_17_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_17_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_18                                                         0x1800C548
#define  SE_HCOEF2_32_18_reg_addr                                                "0xB800C548"
#define  SE_HCOEF2_32_18_reg                                                     0xB800C548
#define  SE_HCOEF2_32_18_inst_addr                                               "0x00E0"
#define  set_SE_HCOEF2_32_18_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_18_reg)=data)
#define  get_SE_HCOEF2_32_18_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_18_reg))
#define  SE_HCOEF2_32_18_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_18_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_18_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_18_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_19                                                         0x1800C54C
#define  SE_HCOEF2_32_19_reg_addr                                                "0xB800C54C"
#define  SE_HCOEF2_32_19_reg                                                     0xB800C54C
#define  SE_HCOEF2_32_19_inst_addr                                               "0x00E1"
#define  set_SE_HCOEF2_32_19_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_19_reg)=data)
#define  get_SE_HCOEF2_32_19_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_19_reg))
#define  SE_HCOEF2_32_19_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_19_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_19_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_19_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_20                                                         0x1800C550
#define  SE_HCOEF2_32_20_reg_addr                                                "0xB800C550"
#define  SE_HCOEF2_32_20_reg                                                     0xB800C550
#define  SE_HCOEF2_32_20_inst_addr                                               "0x00E2"
#define  set_SE_HCOEF2_32_20_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_20_reg)=data)
#define  get_SE_HCOEF2_32_20_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_20_reg))
#define  SE_HCOEF2_32_20_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_20_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_20_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_20_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_21                                                         0x1800C554
#define  SE_HCOEF2_32_21_reg_addr                                                "0xB800C554"
#define  SE_HCOEF2_32_21_reg                                                     0xB800C554
#define  SE_HCOEF2_32_21_inst_addr                                               "0x00E3"
#define  set_SE_HCOEF2_32_21_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_21_reg)=data)
#define  get_SE_HCOEF2_32_21_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_21_reg))
#define  SE_HCOEF2_32_21_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_21_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_21_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_21_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_22                                                         0x1800C558
#define  SE_HCOEF2_32_22_reg_addr                                                "0xB800C558"
#define  SE_HCOEF2_32_22_reg                                                     0xB800C558
#define  SE_HCOEF2_32_22_inst_addr                                               "0x00E4"
#define  set_SE_HCOEF2_32_22_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_22_reg)=data)
#define  get_SE_HCOEF2_32_22_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_22_reg))
#define  SE_HCOEF2_32_22_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_22_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_22_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_22_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_23                                                         0x1800C55C
#define  SE_HCOEF2_32_23_reg_addr                                                "0xB800C55C"
#define  SE_HCOEF2_32_23_reg                                                     0xB800C55C
#define  SE_HCOEF2_32_23_inst_addr                                               "0x00E5"
#define  set_SE_HCOEF2_32_23_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_23_reg)=data)
#define  get_SE_HCOEF2_32_23_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_23_reg))
#define  SE_HCOEF2_32_23_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_23_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_23_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_23_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_24                                                         0x1800C560
#define  SE_HCOEF2_32_24_reg_addr                                                "0xB800C560"
#define  SE_HCOEF2_32_24_reg                                                     0xB800C560
#define  SE_HCOEF2_32_24_inst_addr                                               "0x00E6"
#define  set_SE_HCOEF2_32_24_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_24_reg)=data)
#define  get_SE_HCOEF2_32_24_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_24_reg))
#define  SE_HCOEF2_32_24_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_24_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_24_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_24_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_25                                                         0x1800C564
#define  SE_HCOEF2_32_25_reg_addr                                                "0xB800C564"
#define  SE_HCOEF2_32_25_reg                                                     0xB800C564
#define  SE_HCOEF2_32_25_inst_addr                                               "0x00E7"
#define  set_SE_HCOEF2_32_25_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_25_reg)=data)
#define  get_SE_HCOEF2_32_25_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_25_reg))
#define  SE_HCOEF2_32_25_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_25_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_25_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_25_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_26                                                         0x1800C568
#define  SE_HCOEF2_32_26_reg_addr                                                "0xB800C568"
#define  SE_HCOEF2_32_26_reg                                                     0xB800C568
#define  SE_HCOEF2_32_26_inst_addr                                               "0x00E8"
#define  set_SE_HCOEF2_32_26_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_26_reg)=data)
#define  get_SE_HCOEF2_32_26_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_26_reg))
#define  SE_HCOEF2_32_26_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_26_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_26_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_26_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_27                                                         0x1800C56C
#define  SE_HCOEF2_32_27_reg_addr                                                "0xB800C56C"
#define  SE_HCOEF2_32_27_reg                                                     0xB800C56C
#define  SE_HCOEF2_32_27_inst_addr                                               "0x00E9"
#define  set_SE_HCOEF2_32_27_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_27_reg)=data)
#define  get_SE_HCOEF2_32_27_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_27_reg))
#define  SE_HCOEF2_32_27_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_27_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_27_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_27_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_28                                                         0x1800C570
#define  SE_HCOEF2_32_28_reg_addr                                                "0xB800C570"
#define  SE_HCOEF2_32_28_reg                                                     0xB800C570
#define  SE_HCOEF2_32_28_inst_addr                                               "0x00EA"
#define  set_SE_HCOEF2_32_28_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_28_reg)=data)
#define  get_SE_HCOEF2_32_28_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_28_reg))
#define  SE_HCOEF2_32_28_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_28_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_28_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_28_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_29                                                         0x1800C574
#define  SE_HCOEF2_32_29_reg_addr                                                "0xB800C574"
#define  SE_HCOEF2_32_29_reg                                                     0xB800C574
#define  SE_HCOEF2_32_29_inst_addr                                               "0x00EB"
#define  set_SE_HCOEF2_32_29_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_29_reg)=data)
#define  get_SE_HCOEF2_32_29_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_29_reg))
#define  SE_HCOEF2_32_29_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_29_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_29_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_29_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_30                                                         0x1800C578
#define  SE_HCOEF2_32_30_reg_addr                                                "0xB800C578"
#define  SE_HCOEF2_32_30_reg                                                     0xB800C578
#define  SE_HCOEF2_32_30_inst_addr                                               "0x00EC"
#define  set_SE_HCOEF2_32_30_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_30_reg)=data)
#define  get_SE_HCOEF2_32_30_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_30_reg))
#define  SE_HCOEF2_32_30_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_30_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_30_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_30_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_HCOEF2_32_31                                                         0x1800C57C
#define  SE_HCOEF2_32_31_reg_addr                                                "0xB800C57C"
#define  SE_HCOEF2_32_31_reg                                                     0xB800C57C
#define  SE_HCOEF2_32_31_inst_addr                                               "0x00ED"
#define  set_SE_HCOEF2_32_31_reg(data)                                           (*((volatile unsigned int*)SE_HCOEF2_32_31_reg)=data)
#define  get_SE_HCOEF2_32_31_reg                                                 (*((volatile unsigned int*)SE_HCOEF2_32_31_reg))
#define  SE_HCOEF2_32_31_hcoef_shift                                             (0)
#define  SE_HCOEF2_32_31_hcoef_mask                                              (0x00003FFF)
#define  SE_HCOEF2_32_31_hcoef(data)                                             (0x00003FFF&(data))
#define  SE_HCOEF2_32_31_get_hcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF2_0                                                             0x1800C580
#define  SE_VCOEF2_0_reg_addr                                                    "0xB800C580"
#define  SE_VCOEF2_0_reg                                                         0xB800C580
#define  SE_VCOEF2_0_inst_addr                                                   "0x00EE"
#define  set_SE_VCOEF2_0_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_0_reg)=data)
#define  get_SE_VCOEF2_0_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_0_reg))
#define  SE_VCOEF2_0_vcoef_shift                                                 (0)
#define  SE_VCOEF2_0_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_0_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_0_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_1                                                             0x1800C584
#define  SE_VCOEF2_1_reg_addr                                                    "0xB800C584"
#define  SE_VCOEF2_1_reg                                                         0xB800C584
#define  SE_VCOEF2_1_inst_addr                                                   "0x00EF"
#define  set_SE_VCOEF2_1_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_1_reg)=data)
#define  get_SE_VCOEF2_1_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_1_reg))
#define  SE_VCOEF2_1_vcoef_shift                                                 (0)
#define  SE_VCOEF2_1_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_1_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_1_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_2                                                             0x1800C588
#define  SE_VCOEF2_2_reg_addr                                                    "0xB800C588"
#define  SE_VCOEF2_2_reg                                                         0xB800C588
#define  SE_VCOEF2_2_inst_addr                                                   "0x00F0"
#define  set_SE_VCOEF2_2_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_2_reg)=data)
#define  get_SE_VCOEF2_2_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_2_reg))
#define  SE_VCOEF2_2_vcoef_shift                                                 (0)
#define  SE_VCOEF2_2_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_2_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_2_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_3                                                             0x1800C58C
#define  SE_VCOEF2_3_reg_addr                                                    "0xB800C58C"
#define  SE_VCOEF2_3_reg                                                         0xB800C58C
#define  SE_VCOEF2_3_inst_addr                                                   "0x00F1"
#define  set_SE_VCOEF2_3_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_3_reg)=data)
#define  get_SE_VCOEF2_3_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_3_reg))
#define  SE_VCOEF2_3_vcoef_shift                                                 (0)
#define  SE_VCOEF2_3_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_3_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_3_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_4                                                             0x1800C590
#define  SE_VCOEF2_4_reg_addr                                                    "0xB800C590"
#define  SE_VCOEF2_4_reg                                                         0xB800C590
#define  SE_VCOEF2_4_inst_addr                                                   "0x00F2"
#define  set_SE_VCOEF2_4_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_4_reg)=data)
#define  get_SE_VCOEF2_4_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_4_reg))
#define  SE_VCOEF2_4_vcoef_shift                                                 (0)
#define  SE_VCOEF2_4_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_4_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_4_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_5                                                             0x1800C594
#define  SE_VCOEF2_5_reg_addr                                                    "0xB800C594"
#define  SE_VCOEF2_5_reg                                                         0xB800C594
#define  SE_VCOEF2_5_inst_addr                                                   "0x00F3"
#define  set_SE_VCOEF2_5_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_5_reg)=data)
#define  get_SE_VCOEF2_5_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_5_reg))
#define  SE_VCOEF2_5_vcoef_shift                                                 (0)
#define  SE_VCOEF2_5_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_5_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_5_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_6                                                             0x1800C598
#define  SE_VCOEF2_6_reg_addr                                                    "0xB800C598"
#define  SE_VCOEF2_6_reg                                                         0xB800C598
#define  SE_VCOEF2_6_inst_addr                                                   "0x00F4"
#define  set_SE_VCOEF2_6_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_6_reg)=data)
#define  get_SE_VCOEF2_6_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_6_reg))
#define  SE_VCOEF2_6_vcoef_shift                                                 (0)
#define  SE_VCOEF2_6_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_6_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_6_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_7                                                             0x1800C59C
#define  SE_VCOEF2_7_reg_addr                                                    "0xB800C59C"
#define  SE_VCOEF2_7_reg                                                         0xB800C59C
#define  SE_VCOEF2_7_inst_addr                                                   "0x00F5"
#define  set_SE_VCOEF2_7_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_7_reg)=data)
#define  get_SE_VCOEF2_7_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_7_reg))
#define  SE_VCOEF2_7_vcoef_shift                                                 (0)
#define  SE_VCOEF2_7_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_7_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_7_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_8                                                             0x1800C5A0
#define  SE_VCOEF2_8_reg_addr                                                    "0xB800C5A0"
#define  SE_VCOEF2_8_reg                                                         0xB800C5A0
#define  SE_VCOEF2_8_inst_addr                                                   "0x00F6"
#define  set_SE_VCOEF2_8_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_8_reg)=data)
#define  get_SE_VCOEF2_8_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_8_reg))
#define  SE_VCOEF2_8_vcoef_shift                                                 (0)
#define  SE_VCOEF2_8_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_8_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_8_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_9                                                             0x1800C5A4
#define  SE_VCOEF2_9_reg_addr                                                    "0xB800C5A4"
#define  SE_VCOEF2_9_reg                                                         0xB800C5A4
#define  SE_VCOEF2_9_inst_addr                                                   "0x00F7"
#define  set_SE_VCOEF2_9_reg(data)                                               (*((volatile unsigned int*)SE_VCOEF2_9_reg)=data)
#define  get_SE_VCOEF2_9_reg                                                     (*((volatile unsigned int*)SE_VCOEF2_9_reg))
#define  SE_VCOEF2_9_vcoef_shift                                                 (0)
#define  SE_VCOEF2_9_vcoef_mask                                                  (0x00003FFF)
#define  SE_VCOEF2_9_vcoef(data)                                                 (0x00003FFF&(data))
#define  SE_VCOEF2_9_get_vcoef(data)                                             (0x00003FFF&(data))

#define  SE_VCOEF2_10                                                            0x1800C5A8
#define  SE_VCOEF2_10_reg_addr                                                   "0xB800C5A8"
#define  SE_VCOEF2_10_reg                                                        0xB800C5A8
#define  SE_VCOEF2_10_inst_addr                                                  "0x00F8"
#define  set_SE_VCOEF2_10_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF2_10_reg)=data)
#define  get_SE_VCOEF2_10_reg                                                    (*((volatile unsigned int*)SE_VCOEF2_10_reg))
#define  SE_VCOEF2_10_vcoef_shift                                                (0)
#define  SE_VCOEF2_10_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF2_10_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF2_10_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF2_11                                                            0x1800C5AC
#define  SE_VCOEF2_11_reg_addr                                                   "0xB800C5AC"
#define  SE_VCOEF2_11_reg                                                        0xB800C5AC
#define  SE_VCOEF2_11_inst_addr                                                  "0x00F9"
#define  set_SE_VCOEF2_11_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF2_11_reg)=data)
#define  get_SE_VCOEF2_11_reg                                                    (*((volatile unsigned int*)SE_VCOEF2_11_reg))
#define  SE_VCOEF2_11_vcoef_shift                                                (0)
#define  SE_VCOEF2_11_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF2_11_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF2_11_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF2_12                                                            0x1800C5B0
#define  SE_VCOEF2_12_reg_addr                                                   "0xB800C5B0"
#define  SE_VCOEF2_12_reg                                                        0xB800C5B0
#define  SE_VCOEF2_12_inst_addr                                                  "0x00FA"
#define  set_SE_VCOEF2_12_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF2_12_reg)=data)
#define  get_SE_VCOEF2_12_reg                                                    (*((volatile unsigned int*)SE_VCOEF2_12_reg))
#define  SE_VCOEF2_12_vcoef_shift                                                (0)
#define  SE_VCOEF2_12_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF2_12_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF2_12_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF2_13                                                            0x1800C5B4
#define  SE_VCOEF2_13_reg_addr                                                   "0xB800C5B4"
#define  SE_VCOEF2_13_reg                                                        0xB800C5B4
#define  SE_VCOEF2_13_inst_addr                                                  "0x00FB"
#define  set_SE_VCOEF2_13_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF2_13_reg)=data)
#define  get_SE_VCOEF2_13_reg                                                    (*((volatile unsigned int*)SE_VCOEF2_13_reg))
#define  SE_VCOEF2_13_vcoef_shift                                                (0)
#define  SE_VCOEF2_13_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF2_13_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF2_13_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF2_14                                                            0x1800C5B8
#define  SE_VCOEF2_14_reg_addr                                                   "0xB800C5B8"
#define  SE_VCOEF2_14_reg                                                        0xB800C5B8
#define  SE_VCOEF2_14_inst_addr                                                  "0x00FC"
#define  set_SE_VCOEF2_14_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF2_14_reg)=data)
#define  get_SE_VCOEF2_14_reg                                                    (*((volatile unsigned int*)SE_VCOEF2_14_reg))
#define  SE_VCOEF2_14_vcoef_shift                                                (0)
#define  SE_VCOEF2_14_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF2_14_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF2_14_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF2_15                                                            0x1800C5BC
#define  SE_VCOEF2_15_reg_addr                                                   "0xB800C5BC"
#define  SE_VCOEF2_15_reg                                                        0xB800C5BC
#define  SE_VCOEF2_15_inst_addr                                                  "0x00FD"
#define  set_SE_VCOEF2_15_reg(data)                                              (*((volatile unsigned int*)SE_VCOEF2_15_reg)=data)
#define  get_SE_VCOEF2_15_reg                                                    (*((volatile unsigned int*)SE_VCOEF2_15_reg))
#define  SE_VCOEF2_15_vcoef_shift                                                (0)
#define  SE_VCOEF2_15_vcoef_mask                                                 (0x00003FFF)
#define  SE_VCOEF2_15_vcoef(data)                                                (0x00003FFF&(data))
#define  SE_VCOEF2_15_get_vcoef(data)                                            (0x00003FFF&(data))

#define  SE_VCOEF2_16_0                                                          0x1800C5C0
#define  SE_VCOEF2_16_0_reg_addr                                                 "0xB800C5C0"
#define  SE_VCOEF2_16_0_reg                                                      0xB800C5C0
#define  SE_VCOEF2_16_0_inst_addr                                                "0x00FE"
#define  set_SE_VCOEF2_16_0_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_0_reg)=data)
#define  get_SE_VCOEF2_16_0_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_0_reg))
#define  SE_VCOEF2_16_0_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_0_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_0_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_0_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_1                                                          0x1800C5C4
#define  SE_VCOEF2_16_1_reg_addr                                                 "0xB800C5C4"
#define  SE_VCOEF2_16_1_reg                                                      0xB800C5C4
#define  SE_VCOEF2_16_1_inst_addr                                                "0x00FF"
#define  set_SE_VCOEF2_16_1_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_1_reg)=data)
#define  get_SE_VCOEF2_16_1_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_1_reg))
#define  SE_VCOEF2_16_1_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_1_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_1_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_1_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_2                                                          0x1800C5C8
#define  SE_VCOEF2_16_2_reg_addr                                                 "0xB800C5C8"
#define  SE_VCOEF2_16_2_reg                                                      0xB800C5C8
#define  SE_VCOEF2_16_2_inst_addr                                                "0x0100"
#define  set_SE_VCOEF2_16_2_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_2_reg)=data)
#define  get_SE_VCOEF2_16_2_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_2_reg))
#define  SE_VCOEF2_16_2_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_2_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_2_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_2_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_3                                                          0x1800C5CC
#define  SE_VCOEF2_16_3_reg_addr                                                 "0xB800C5CC"
#define  SE_VCOEF2_16_3_reg                                                      0xB800C5CC
#define  SE_VCOEF2_16_3_inst_addr                                                "0x0101"
#define  set_SE_VCOEF2_16_3_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_3_reg)=data)
#define  get_SE_VCOEF2_16_3_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_3_reg))
#define  SE_VCOEF2_16_3_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_3_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_3_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_3_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_4                                                          0x1800C5D0
#define  SE_VCOEF2_16_4_reg_addr                                                 "0xB800C5D0"
#define  SE_VCOEF2_16_4_reg                                                      0xB800C5D0
#define  SE_VCOEF2_16_4_inst_addr                                                "0x0102"
#define  set_SE_VCOEF2_16_4_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_4_reg)=data)
#define  get_SE_VCOEF2_16_4_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_4_reg))
#define  SE_VCOEF2_16_4_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_4_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_4_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_4_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_5                                                          0x1800C5D4
#define  SE_VCOEF2_16_5_reg_addr                                                 "0xB800C5D4"
#define  SE_VCOEF2_16_5_reg                                                      0xB800C5D4
#define  SE_VCOEF2_16_5_inst_addr                                                "0x0103"
#define  set_SE_VCOEF2_16_5_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_5_reg)=data)
#define  get_SE_VCOEF2_16_5_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_5_reg))
#define  SE_VCOEF2_16_5_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_5_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_5_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_5_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_6                                                          0x1800C5D8
#define  SE_VCOEF2_16_6_reg_addr                                                 "0xB800C5D8"
#define  SE_VCOEF2_16_6_reg                                                      0xB800C5D8
#define  SE_VCOEF2_16_6_inst_addr                                                "0x0104"
#define  set_SE_VCOEF2_16_6_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_6_reg)=data)
#define  get_SE_VCOEF2_16_6_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_6_reg))
#define  SE_VCOEF2_16_6_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_6_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_6_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_6_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_7                                                          0x1800C5DC
#define  SE_VCOEF2_16_7_reg_addr                                                 "0xB800C5DC"
#define  SE_VCOEF2_16_7_reg                                                      0xB800C5DC
#define  SE_VCOEF2_16_7_inst_addr                                                "0x0105"
#define  set_SE_VCOEF2_16_7_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_7_reg)=data)
#define  get_SE_VCOEF2_16_7_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_7_reg))
#define  SE_VCOEF2_16_7_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_7_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_7_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_7_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_8                                                          0x1800C5E0
#define  SE_VCOEF2_16_8_reg_addr                                                 "0xB800C5E0"
#define  SE_VCOEF2_16_8_reg                                                      0xB800C5E0
#define  SE_VCOEF2_16_8_inst_addr                                                "0x0106"
#define  set_SE_VCOEF2_16_8_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_8_reg)=data)
#define  get_SE_VCOEF2_16_8_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_8_reg))
#define  SE_VCOEF2_16_8_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_8_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_8_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_8_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_9                                                          0x1800C5E4
#define  SE_VCOEF2_16_9_reg_addr                                                 "0xB800C5E4"
#define  SE_VCOEF2_16_9_reg                                                      0xB800C5E4
#define  SE_VCOEF2_16_9_inst_addr                                                "0x0107"
#define  set_SE_VCOEF2_16_9_reg(data)                                            (*((volatile unsigned int*)SE_VCOEF2_16_9_reg)=data)
#define  get_SE_VCOEF2_16_9_reg                                                  (*((volatile unsigned int*)SE_VCOEF2_16_9_reg))
#define  SE_VCOEF2_16_9_vcoef_shift                                              (0)
#define  SE_VCOEF2_16_9_vcoef_mask                                               (0x00003FFF)
#define  SE_VCOEF2_16_9_vcoef(data)                                              (0x00003FFF&(data))
#define  SE_VCOEF2_16_9_get_vcoef(data)                                          (0x00003FFF&(data))

#define  SE_VCOEF2_16_10                                                         0x1800C5E8
#define  SE_VCOEF2_16_10_reg_addr                                                "0xB800C5E8"
#define  SE_VCOEF2_16_10_reg                                                     0xB800C5E8
#define  SE_VCOEF2_16_10_inst_addr                                               "0x0108"
#define  set_SE_VCOEF2_16_10_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF2_16_10_reg)=data)
#define  get_SE_VCOEF2_16_10_reg                                                 (*((volatile unsigned int*)SE_VCOEF2_16_10_reg))
#define  SE_VCOEF2_16_10_vcoef_shift                                             (0)
#define  SE_VCOEF2_16_10_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF2_16_10_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF2_16_10_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF2_16_11                                                         0x1800C5EC
#define  SE_VCOEF2_16_11_reg_addr                                                "0xB800C5EC"
#define  SE_VCOEF2_16_11_reg                                                     0xB800C5EC
#define  SE_VCOEF2_16_11_inst_addr                                               "0x0109"
#define  set_SE_VCOEF2_16_11_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF2_16_11_reg)=data)
#define  get_SE_VCOEF2_16_11_reg                                                 (*((volatile unsigned int*)SE_VCOEF2_16_11_reg))
#define  SE_VCOEF2_16_11_vcoef_shift                                             (0)
#define  SE_VCOEF2_16_11_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF2_16_11_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF2_16_11_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF2_16_12                                                         0x1800C5F0
#define  SE_VCOEF2_16_12_reg_addr                                                "0xB800C5F0"
#define  SE_VCOEF2_16_12_reg                                                     0xB800C5F0
#define  SE_VCOEF2_16_12_inst_addr                                               "0x010A"
#define  set_SE_VCOEF2_16_12_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF2_16_12_reg)=data)
#define  get_SE_VCOEF2_16_12_reg                                                 (*((volatile unsigned int*)SE_VCOEF2_16_12_reg))
#define  SE_VCOEF2_16_12_vcoef_shift                                             (0)
#define  SE_VCOEF2_16_12_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF2_16_12_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF2_16_12_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF2_16_13                                                         0x1800C5F4
#define  SE_VCOEF2_16_13_reg_addr                                                "0xB800C5F4"
#define  SE_VCOEF2_16_13_reg                                                     0xB800C5F4
#define  SE_VCOEF2_16_13_inst_addr                                               "0x010B"
#define  set_SE_VCOEF2_16_13_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF2_16_13_reg)=data)
#define  get_SE_VCOEF2_16_13_reg                                                 (*((volatile unsigned int*)SE_VCOEF2_16_13_reg))
#define  SE_VCOEF2_16_13_vcoef_shift                                             (0)
#define  SE_VCOEF2_16_13_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF2_16_13_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF2_16_13_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF2_16_14                                                         0x1800C5F8
#define  SE_VCOEF2_16_14_reg_addr                                                "0xB800C5F8"
#define  SE_VCOEF2_16_14_reg                                                     0xB800C5F8
#define  SE_VCOEF2_16_14_inst_addr                                               "0x010C"
#define  set_SE_VCOEF2_16_14_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF2_16_14_reg)=data)
#define  get_SE_VCOEF2_16_14_reg                                                 (*((volatile unsigned int*)SE_VCOEF2_16_14_reg))
#define  SE_VCOEF2_16_14_vcoef_shift                                             (0)
#define  SE_VCOEF2_16_14_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF2_16_14_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF2_16_14_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_VCOEF2_16_15                                                         0x1800C5FC
#define  SE_VCOEF2_16_15_reg_addr                                                "0xB800C5FC"
#define  SE_VCOEF2_16_15_reg                                                     0xB800C5FC
#define  SE_VCOEF2_16_15_inst_addr                                               "0x010D"
#define  set_SE_VCOEF2_16_15_reg(data)                                           (*((volatile unsigned int*)SE_VCOEF2_16_15_reg)=data)
#define  get_SE_VCOEF2_16_15_reg                                                 (*((volatile unsigned int*)SE_VCOEF2_16_15_reg))
#define  SE_VCOEF2_16_15_vcoef_shift                                             (0)
#define  SE_VCOEF2_16_15_vcoef_mask                                              (0x00003FFF)
#define  SE_VCOEF2_16_15_vcoef(data)                                             (0x00003FFF&(data))
#define  SE_VCOEF2_16_15_get_vcoef(data)                                         (0x00003FFF&(data))

#define  SE_SC_BITBLIT_COLOR_KEY_0                                               0x1800C900
#define  SE_SC_BITBLIT_COLOR_KEY_0_reg_addr                                      "0xB800C900"
#define  SE_SC_BITBLIT_COLOR_KEY_0_reg                                           0xB800C900
#define  SE_SC_BITBLIT_COLOR_KEY_0_inst_addr                                     "0x010E"
#define  set_SE_SC_BITBLIT_COLOR_KEY_0_reg(data)                                 (*((volatile unsigned int*)SE_SC_BITBLIT_COLOR_KEY_0_reg)=data)
#define  get_SE_SC_BITBLIT_COLOR_KEY_0_reg                                       (*((volatile unsigned int*)SE_SC_BITBLIT_COLOR_KEY_0_reg))
#define  SE_SC_BITBLIT_COLOR_KEY_0_color_key_shift                               (0)
#define  SE_SC_BITBLIT_COLOR_KEY_0_color_key_mask                                (0x00FFFFFF)
#define  SE_SC_BITBLIT_COLOR_KEY_0_color_key(data)                               (0x00FFFFFF&(data))
#define  SE_SC_BITBLIT_COLOR_KEY_0_get_color_key(data)                           (0x00FFFFFF&(data))

#define  SE_SC_BITBLIT_COLOR_KEY_1                                               0x1800C904
#define  SE_SC_BITBLIT_COLOR_KEY_1_reg_addr                                      "0xB800C904"
#define  SE_SC_BITBLIT_COLOR_KEY_1_reg                                           0xB800C904
#define  SE_SC_BITBLIT_COLOR_KEY_1_inst_addr                                     "0x010F"
#define  set_SE_SC_BITBLIT_COLOR_KEY_1_reg(data)                                 (*((volatile unsigned int*)SE_SC_BITBLIT_COLOR_KEY_1_reg)=data)
#define  get_SE_SC_BITBLIT_COLOR_KEY_1_reg                                       (*((volatile unsigned int*)SE_SC_BITBLIT_COLOR_KEY_1_reg))
#define  SE_SC_BITBLIT_COLOR_KEY_1_color_key_shift                               (0)
#define  SE_SC_BITBLIT_COLOR_KEY_1_color_key_mask                                (0x00FFFFFF)
#define  SE_SC_BITBLIT_COLOR_KEY_1_color_key(data)                               (0x00FFFFFF&(data))
#define  SE_SC_BITBLIT_COLOR_KEY_1_get_color_key(data)                           (0x00FFFFFF&(data))

#define  SE_SRC_LG_2_0                                                           0x1800CC20
#define  SE_SRC_LG_2_0_reg_addr                                                  "0xB800CC20"
#define  SE_SRC_LG_2_0_reg                                                       0xB800CC20
#define  SE_SRC_LG_2_0_inst_addr                                                 "0x0110"
#define  set_SE_SRC_LG_2_0_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_2_0_reg)=data)
#define  get_SE_SRC_LG_2_0_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_2_0_reg))
#define  SE_SRC_LG_2_0_src_x_color_g_step_shift                                  (16)
#define  SE_SRC_LG_2_0_src_x_color_r_step_shift                                  (0)
#define  SE_SRC_LG_2_0_src_x_color_g_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_2_0_src_x_color_r_step_mask                                   (0x00001FFF)
#define  SE_SRC_LG_2_0_src_x_color_g_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_2_0_src_x_color_r_step(data)                                  (0x00001FFF&(data))
#define  SE_SRC_LG_2_0_get_src_x_color_g_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_2_0_get_src_x_color_r_step(data)                              (0x00001FFF&(data))

#define  SE_SRC_LG_2_1                                                           0x1800CC24
#define  SE_SRC_LG_2_1_reg_addr                                                  "0xB800CC24"
#define  SE_SRC_LG_2_1_reg                                                       0xB800CC24
#define  SE_SRC_LG_2_1_inst_addr                                                 "0x0111"
#define  set_SE_SRC_LG_2_1_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_2_1_reg)=data)
#define  get_SE_SRC_LG_2_1_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_2_1_reg))
#define  SE_SRC_LG_2_1_src_x_color_g_step_shift                                  (16)
#define  SE_SRC_LG_2_1_src_x_color_r_step_shift                                  (0)
#define  SE_SRC_LG_2_1_src_x_color_g_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_2_1_src_x_color_r_step_mask                                   (0x00001FFF)
#define  SE_SRC_LG_2_1_src_x_color_g_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_2_1_src_x_color_r_step(data)                                  (0x00001FFF&(data))
#define  SE_SRC_LG_2_1_get_src_x_color_g_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_2_1_get_src_x_color_r_step(data)                              (0x00001FFF&(data))

#define  SE_SRC_LG_3_0                                                           0x1800CC30
#define  SE_SRC_LG_3_0_reg_addr                                                  "0xB800CC30"
#define  SE_SRC_LG_3_0_reg                                                       0xB800CC30
#define  SE_SRC_LG_3_0_inst_addr                                                 "0x0112"
#define  set_SE_SRC_LG_3_0_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_3_0_reg)=data)
#define  get_SE_SRC_LG_3_0_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_3_0_reg))
#define  SE_SRC_LG_3_0_src_x_color_b_step_shift                                  (16)
#define  SE_SRC_LG_3_0_src_x_alpha_step_shift                                    (0)
#define  SE_SRC_LG_3_0_src_x_color_b_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_3_0_src_x_alpha_step_mask                                     (0x00001FFF)
#define  SE_SRC_LG_3_0_src_x_color_b_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_3_0_src_x_alpha_step(data)                                    (0x00001FFF&(data))
#define  SE_SRC_LG_3_0_get_src_x_color_b_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_3_0_get_src_x_alpha_step(data)                                (0x00001FFF&(data))

#define  SE_SRC_LG_3_1                                                           0x1800CC34
#define  SE_SRC_LG_3_1_reg_addr                                                  "0xB800CC34"
#define  SE_SRC_LG_3_1_reg                                                       0xB800CC34
#define  SE_SRC_LG_3_1_inst_addr                                                 "0x0113"
#define  set_SE_SRC_LG_3_1_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_3_1_reg)=data)
#define  get_SE_SRC_LG_3_1_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_3_1_reg))
#define  SE_SRC_LG_3_1_src_x_color_b_step_shift                                  (16)
#define  SE_SRC_LG_3_1_src_x_alpha_step_shift                                    (0)
#define  SE_SRC_LG_3_1_src_x_color_b_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_3_1_src_x_alpha_step_mask                                     (0x00001FFF)
#define  SE_SRC_LG_3_1_src_x_color_b_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_3_1_src_x_alpha_step(data)                                    (0x00001FFF&(data))
#define  SE_SRC_LG_3_1_get_src_x_color_b_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_3_1_get_src_x_alpha_step(data)                                (0x00001FFF&(data))

#define  SE_SRC_LG_4_0                                                           0x1800CC40
#define  SE_SRC_LG_4_0_reg_addr                                                  "0xB800CC40"
#define  SE_SRC_LG_4_0_reg                                                       0xB800CC40
#define  SE_SRC_LG_4_0_inst_addr                                                 "0x0114"
#define  set_SE_SRC_LG_4_0_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_4_0_reg)=data)
#define  get_SE_SRC_LG_4_0_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_4_0_reg))
#define  SE_SRC_LG_4_0_src_y_color_g_step_shift                                  (16)
#define  SE_SRC_LG_4_0_src_y_color_r_step_shift                                  (0)
#define  SE_SRC_LG_4_0_src_y_color_g_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_4_0_src_y_color_r_step_mask                                   (0x00001FFF)
#define  SE_SRC_LG_4_0_src_y_color_g_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_4_0_src_y_color_r_step(data)                                  (0x00001FFF&(data))
#define  SE_SRC_LG_4_0_get_src_y_color_g_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_4_0_get_src_y_color_r_step(data)                              (0x00001FFF&(data))

#define  SE_SRC_LG_4_1                                                           0x1800CC44
#define  SE_SRC_LG_4_1_reg_addr                                                  "0xB800CC44"
#define  SE_SRC_LG_4_1_reg                                                       0xB800CC44
#define  SE_SRC_LG_4_1_inst_addr                                                 "0x0115"
#define  set_SE_SRC_LG_4_1_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_4_1_reg)=data)
#define  get_SE_SRC_LG_4_1_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_4_1_reg))
#define  SE_SRC_LG_4_1_src_y_color_g_step_shift                                  (16)
#define  SE_SRC_LG_4_1_src_y_color_r_step_shift                                  (0)
#define  SE_SRC_LG_4_1_src_y_color_g_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_4_1_src_y_color_r_step_mask                                   (0x00001FFF)
#define  SE_SRC_LG_4_1_src_y_color_g_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_4_1_src_y_color_r_step(data)                                  (0x00001FFF&(data))
#define  SE_SRC_LG_4_1_get_src_y_color_g_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_4_1_get_src_y_color_r_step(data)                              (0x00001FFF&(data))

#define  SE_SRC_LG_5_0                                                           0x1800CC50
#define  SE_SRC_LG_5_0_reg_addr                                                  "0xB800CC50"
#define  SE_SRC_LG_5_0_reg                                                       0xB800CC50
#define  SE_SRC_LG_5_0_inst_addr                                                 "0x0116"
#define  set_SE_SRC_LG_5_0_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_5_0_reg)=data)
#define  get_SE_SRC_LG_5_0_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_5_0_reg))
#define  SE_SRC_LG_5_0_src_y_color_b_step_shift                                  (16)
#define  SE_SRC_LG_5_0_src_y_alpha_step_shift                                    (0)
#define  SE_SRC_LG_5_0_src_y_color_b_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_5_0_src_y_alpha_step_mask                                     (0x00001FFF)
#define  SE_SRC_LG_5_0_src_y_color_b_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_5_0_src_y_alpha_step(data)                                    (0x00001FFF&(data))
#define  SE_SRC_LG_5_0_get_src_y_color_b_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_5_0_get_src_y_alpha_step(data)                                (0x00001FFF&(data))

#define  SE_SRC_LG_5_1                                                           0x1800CC54
#define  SE_SRC_LG_5_1_reg_addr                                                  "0xB800CC54"
#define  SE_SRC_LG_5_1_reg                                                       0xB800CC54
#define  SE_SRC_LG_5_1_inst_addr                                                 "0x0117"
#define  set_SE_SRC_LG_5_1_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_5_1_reg)=data)
#define  get_SE_SRC_LG_5_1_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_5_1_reg))
#define  SE_SRC_LG_5_1_src_y_color_b_step_shift                                  (16)
#define  SE_SRC_LG_5_1_src_y_alpha_step_shift                                    (0)
#define  SE_SRC_LG_5_1_src_y_color_b_step_mask                                   (0x1FFF0000)
#define  SE_SRC_LG_5_1_src_y_alpha_step_mask                                     (0x00001FFF)
#define  SE_SRC_LG_5_1_src_y_color_b_step(data)                                  (0x1FFF0000&((data)<<16))
#define  SE_SRC_LG_5_1_src_y_alpha_step(data)                                    (0x00001FFF&(data))
#define  SE_SRC_LG_5_1_get_src_y_color_b_step(data)                              ((0x1FFF0000&(data))>>16)
#define  SE_SRC_LG_5_1_get_src_y_alpha_step(data)                                (0x00001FFF&(data))

#define  SE_SRC_LG_6_0                                                           0x1800CC60
#define  SE_SRC_LG_6_0_reg_addr                                                  "0xB800CC60"
#define  SE_SRC_LG_6_0_reg                                                       0xB800CC60
#define  SE_SRC_LG_6_0_inst_addr                                                 "0x0118"
#define  set_SE_SRC_LG_6_0_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_6_0_reg)=data)
#define  get_SE_SRC_LG_6_0_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_6_0_reg))
#define  SE_SRC_LG_6_0_src_color_direction_shift                                 (0)
#define  SE_SRC_LG_6_0_src_color_direction_mask                                  (0x00000003)
#define  SE_SRC_LG_6_0_src_color_direction(data)                                 (0x00000003&(data))
#define  SE_SRC_LG_6_0_get_src_color_direction(data)                             (0x00000003&(data))

#define  SE_SRC_LG_6_1                                                           0x1800CC64
#define  SE_SRC_LG_6_1_reg_addr                                                  "0xB800CC64"
#define  SE_SRC_LG_6_1_reg                                                       0xB800CC64
#define  SE_SRC_LG_6_1_inst_addr                                                 "0x0119"
#define  set_SE_SRC_LG_6_1_reg(data)                                             (*((volatile unsigned int*)SE_SRC_LG_6_1_reg)=data)
#define  get_SE_SRC_LG_6_1_reg                                                   (*((volatile unsigned int*)SE_SRC_LG_6_1_reg))
#define  SE_SRC_LG_6_1_src_color_direction_shift                                 (0)
#define  SE_SRC_LG_6_1_src_color_direction_mask                                  (0x00000003)
#define  SE_SRC_LG_6_1_src_color_direction(data)                                 (0x00000003&(data))
#define  SE_SRC_LG_6_1_get_src_color_direction(data)                             (0x00000003&(data))

#define  SE_CTRL_0                                                               0x1800C960
#define  SE_CTRL_0_reg_addr                                                      "0xB800C960"
#define  SE_CTRL_0_reg                                                           0xB800C960
#define  SE_CTRL_0_inst_addr                                                     "0x011A"
#define  set_SE_CTRL_0_reg(data)                                                 (*((volatile unsigned int*)SE_CTRL_0_reg)=data)
#define  get_SE_CTRL_0_reg                                                       (*((volatile unsigned int*)SE_CTRL_0_reg))
#define  SE_CTRL_0_endiswap_shift                                                (2)
#define  SE_CTRL_0_go_shift                                                      (1)
#define  SE_CTRL_0_write_data_shift                                              (0)
#define  SE_CTRL_0_endiswap_mask                                                 (0x00000004)
#define  SE_CTRL_0_go_mask                                                       (0x00000002)
#define  SE_CTRL_0_write_data_mask                                               (0x00000001)
#define  SE_CTRL_0_endiswap(data)                                                (0x00000004&((data)<<2))
#define  SE_CTRL_0_go(data)                                                      (0x00000002&((data)<<1))
#define  SE_CTRL_0_write_data(data)                                              (0x00000001&(data))
#define  SE_CTRL_0_get_endiswap(data)                                            ((0x00000004&(data))>>2)
#define  SE_CTRL_0_get_go(data)                                                  ((0x00000002&(data))>>1)
#define  SE_CTRL_0_get_write_data(data)                                          (0x00000001&(data))

#define  SE_CTRL_1                                                               0x1800C964
#define  SE_CTRL_1_reg_addr                                                      "0xB800C964"
#define  SE_CTRL_1_reg                                                           0xB800C964
#define  SE_CTRL_1_inst_addr                                                     "0x011B"
#define  set_SE_CTRL_1_reg(data)                                                 (*((volatile unsigned int*)SE_CTRL_1_reg)=data)
#define  get_SE_CTRL_1_reg                                                       (*((volatile unsigned int*)SE_CTRL_1_reg))
#define  SE_CTRL_1_endiswap_shift                                                (2)
#define  SE_CTRL_1_go_shift                                                      (1)
#define  SE_CTRL_1_write_data_shift                                              (0)
#define  SE_CTRL_1_endiswap_mask                                                 (0x00000004)
#define  SE_CTRL_1_go_mask                                                       (0x00000002)
#define  SE_CTRL_1_write_data_mask                                               (0x00000001)
#define  SE_CTRL_1_endiswap(data)                                                (0x00000004&((data)<<2))
#define  SE_CTRL_1_go(data)                                                      (0x00000002&((data)<<1))
#define  SE_CTRL_1_write_data(data)                                              (0x00000001&(data))
#define  SE_CTRL_1_get_endiswap(data)                                            ((0x00000004&(data))>>2)
#define  SE_CTRL_1_get_go(data)                                                  ((0x00000002&(data))>>1)
#define  SE_CTRL_1_get_write_data(data)                                          (0x00000001&(data))

#define  SE_IDLE_0                                                               0x1800C970
#define  SE_IDLE_0_reg_addr                                                      "0xB800C970"
#define  SE_IDLE_0_reg                                                           0xB800C970
#define  SE_IDLE_0_inst_addr                                                     "0x011C"
#define  set_SE_IDLE_0_reg(data)                                                 (*((volatile unsigned int*)SE_IDLE_0_reg)=data)
#define  get_SE_IDLE_0_reg                                                       (*((volatile unsigned int*)SE_IDLE_0_reg))
#define  SE_IDLE_0_idle_shift                                                    (0)
#define  SE_IDLE_0_idle_mask                                                     (0x00000001)
#define  SE_IDLE_0_idle(data)                                                    (0x00000001&(data))
#define  SE_IDLE_0_get_idle(data)                                                (0x00000001&(data))

#define  SE_IDLE_1                                                               0x1800C974
#define  SE_IDLE_1_reg_addr                                                      "0xB800C974"
#define  SE_IDLE_1_reg                                                           0xB800C974
#define  SE_IDLE_1_inst_addr                                                     "0x011D"
#define  set_SE_IDLE_1_reg(data)                                                 (*((volatile unsigned int*)SE_IDLE_1_reg)=data)
#define  get_SE_IDLE_1_reg                                                       (*((volatile unsigned int*)SE_IDLE_1_reg))
#define  SE_IDLE_1_idle_shift                                                    (0)
#define  SE_IDLE_1_idle_mask                                                     (0x00000001)
#define  SE_IDLE_1_idle(data)                                                    (0x00000001&(data))
#define  SE_IDLE_1_get_idle(data)                                                (0x00000001&(data))

#define  SE_INTSEL                                                               0x1800C980
#define  SE_INTSEL_reg_addr                                                      "0xB800C980"
#define  SE_INTSEL_reg                                                           0xB800C980
#define  SE_INTSEL_inst_addr                                                     "0x011E"
#define  set_SE_INTSEL_reg(data)                                                 (*((volatile unsigned int*)SE_INTSEL_reg)=data)
#define  get_SE_INTSEL_reg                                                       (*((volatile unsigned int*)SE_INTSEL_reg))
#define  SE_INTSEL_sel2_shift                                                    (4)
#define  SE_INTSEL_sel1_shift                                                    (0)
#define  SE_INTSEL_sel2_mask                                                     (0x00000070)
#define  SE_INTSEL_sel1_mask                                                     (0x00000007)
#define  SE_INTSEL_sel2(data)                                                    (0x00000070&((data)<<4))
#define  SE_INTSEL_sel1(data)                                                    (0x00000007&(data))
#define  SE_INTSEL_get_sel2(data)                                                ((0x00000070&(data))>>4)
#define  SE_INTSEL_get_sel1(data)                                                (0x00000007&(data))

#define  SE_INTS_0                                                               0x1800C990
#define  SE_INTS_0_reg_addr                                                      "0xB800C990"
#define  SE_INTS_0_reg                                                           0xB800C990
#define  SE_INTS_0_inst_addr                                                     "0x011F"
#define  set_SE_INTS_0_reg(data)                                                 (*((volatile unsigned int*)SE_INTS_0_reg)=data)
#define  get_SE_INTS_0_reg                                                       (*((volatile unsigned int*)SE_INTS_0_reg))
#define  SE_INTS_0_vo_sync_err_shift                                             (17)
#define  SE_INTS_0_fmt_err_shift                                                 (16)
#define  SE_INTS_0_com_empty_shift                                               (3)
#define  SE_INTS_0_com_err_shift                                                 (2)
#define  SE_INTS_0_sync_shift                                                    (1)
#define  SE_INTS_0_write_data_shift                                              (0)
#define  SE_INTS_0_vo_sync_err_mask                                              (0x00020000)
#define  SE_INTS_0_fmt_err_mask                                                  (0x00010000)
#define  SE_INTS_0_com_empty_mask                                                (0x00000008)
#define  SE_INTS_0_com_err_mask                                                  (0x00000004)
#define  SE_INTS_0_sync_mask                                                     (0x00000002)
#define  SE_INTS_0_write_data_mask                                               (0x00000001)
#define  SE_INTS_0_vo_sync_err(data)                                             (0x00020000&((data)<<17))
#define  SE_INTS_0_fmt_err(data)                                                 (0x00010000&((data)<<16))
#define  SE_INTS_0_com_empty(data)                                               (0x00000008&((data)<<3))
#define  SE_INTS_0_com_err(data)                                                 (0x00000004&((data)<<2))
#define  SE_INTS_0_sync(data)                                                    (0x00000002&((data)<<1))
#define  SE_INTS_0_write_data(data)                                              (0x00000001&(data))
#define  SE_INTS_0_get_vo_sync_err(data)                                         ((0x00020000&(data))>>17)
#define  SE_INTS_0_get_fmt_err(data)                                             ((0x00010000&(data))>>16)
#define  SE_INTS_0_get_com_empty(data)                                           ((0x00000008&(data))>>3)
#define  SE_INTS_0_get_com_err(data)                                             ((0x00000004&(data))>>2)
#define  SE_INTS_0_get_sync(data)                                                ((0x00000002&(data))>>1)
#define  SE_INTS_0_get_write_data(data)                                          (0x00000001&(data))

#define  SE_INTS_1                                                               0x1800C994
#define  SE_INTS_1_reg_addr                                                      "0xB800C994"
#define  SE_INTS_1_reg                                                           0xB800C994
#define  SE_INTS_1_inst_addr                                                     "0x0120"
#define  set_SE_INTS_1_reg(data)                                                 (*((volatile unsigned int*)SE_INTS_1_reg)=data)
#define  get_SE_INTS_1_reg                                                       (*((volatile unsigned int*)SE_INTS_1_reg))
#define  SE_INTS_1_vo_sync_err_shift                                             (17)
#define  SE_INTS_1_fmt_err_shift                                                 (16)
#define  SE_INTS_1_com_empty_shift                                               (3)
#define  SE_INTS_1_com_err_shift                                                 (2)
#define  SE_INTS_1_sync_shift                                                    (1)
#define  SE_INTS_1_write_data_shift                                              (0)
#define  SE_INTS_1_vo_sync_err_mask                                              (0x00020000)
#define  SE_INTS_1_fmt_err_mask                                                  (0x00010000)
#define  SE_INTS_1_com_empty_mask                                                (0x00000008)
#define  SE_INTS_1_com_err_mask                                                  (0x00000004)
#define  SE_INTS_1_sync_mask                                                     (0x00000002)
#define  SE_INTS_1_write_data_mask                                               (0x00000001)
#define  SE_INTS_1_vo_sync_err(data)                                             (0x00020000&((data)<<17))
#define  SE_INTS_1_fmt_err(data)                                                 (0x00010000&((data)<<16))
#define  SE_INTS_1_com_empty(data)                                               (0x00000008&((data)<<3))
#define  SE_INTS_1_com_err(data)                                                 (0x00000004&((data)<<2))
#define  SE_INTS_1_sync(data)                                                    (0x00000002&((data)<<1))
#define  SE_INTS_1_write_data(data)                                              (0x00000001&(data))
#define  SE_INTS_1_get_vo_sync_err(data)                                         ((0x00020000&(data))>>17)
#define  SE_INTS_1_get_fmt_err(data)                                             ((0x00010000&(data))>>16)
#define  SE_INTS_1_get_com_empty(data)                                           ((0x00000008&(data))>>3)
#define  SE_INTS_1_get_com_err(data)                                             ((0x00000004&(data))>>2)
#define  SE_INTS_1_get_sync(data)                                                ((0x00000002&(data))>>1)
#define  SE_INTS_1_get_write_data(data)                                          (0x00000001&(data))

#define  SE_INTE_0                                                               0x1800C9A0
#define  SE_INTE_0_reg_addr                                                      "0xB800C9A0"
#define  SE_INTE_0_reg                                                           0xB800C9A0
#define  SE_INTE_0_inst_addr                                                     "0x0121"
#define  set_SE_INTE_0_reg(data)                                                 (*((volatile unsigned int*)SE_INTE_0_reg)=data)
#define  get_SE_INTE_0_reg                                                       (*((volatile unsigned int*)SE_INTE_0_reg))
#define  SE_INTE_0_vo_sync_err_shift                                             (17)
#define  SE_INTE_0_fmt_err_shift                                                 (16)
#define  SE_INTE_0_com_empty_shift                                               (3)
#define  SE_INTE_0_com_err_shift                                                 (2)
#define  SE_INTE_0_sync_shift                                                    (1)
#define  SE_INTE_0_write_data_shift                                              (0)
#define  SE_INTE_0_vo_sync_err_mask                                              (0x00020000)
#define  SE_INTE_0_fmt_err_mask                                                  (0x00010000)
#define  SE_INTE_0_com_empty_mask                                                (0x00000008)
#define  SE_INTE_0_com_err_mask                                                  (0x00000004)
#define  SE_INTE_0_sync_mask                                                     (0x00000002)
#define  SE_INTE_0_write_data_mask                                               (0x00000001)
#define  SE_INTE_0_vo_sync_err(data)                                             (0x00020000&((data)<<17))
#define  SE_INTE_0_fmt_err(data)                                                 (0x00010000&((data)<<16))
#define  SE_INTE_0_com_empty(data)                                               (0x00000008&((data)<<3))
#define  SE_INTE_0_com_err(data)                                                 (0x00000004&((data)<<2))
#define  SE_INTE_0_sync(data)                                                    (0x00000002&((data)<<1))
#define  SE_INTE_0_write_data(data)                                              (0x00000001&(data))
#define  SE_INTE_0_get_vo_sync_err(data)                                         ((0x00020000&(data))>>17)
#define  SE_INTE_0_get_fmt_err(data)                                             ((0x00010000&(data))>>16)
#define  SE_INTE_0_get_com_empty(data)                                           ((0x00000008&(data))>>3)
#define  SE_INTE_0_get_com_err(data)                                             ((0x00000004&(data))>>2)
#define  SE_INTE_0_get_sync(data)                                                ((0x00000002&(data))>>1)
#define  SE_INTE_0_get_write_data(data)                                          (0x00000001&(data))

#define  SE_INTE_1                                                               0x1800C9A4
#define  SE_INTE_1_reg_addr                                                      "0xB800C9A4"
#define  SE_INTE_1_reg                                                           0xB800C9A4
#define  SE_INTE_1_inst_addr                                                     "0x0122"
#define  set_SE_INTE_1_reg(data)                                                 (*((volatile unsigned int*)SE_INTE_1_reg)=data)
#define  get_SE_INTE_1_reg                                                       (*((volatile unsigned int*)SE_INTE_1_reg))
#define  SE_INTE_1_vo_sync_err_shift                                             (17)
#define  SE_INTE_1_fmt_err_shift                                                 (16)
#define  SE_INTE_1_com_empty_shift                                               (3)
#define  SE_INTE_1_com_err_shift                                                 (2)
#define  SE_INTE_1_sync_shift                                                    (1)
#define  SE_INTE_1_write_data_shift                                              (0)
#define  SE_INTE_1_vo_sync_err_mask                                              (0x00020000)
#define  SE_INTE_1_fmt_err_mask                                                  (0x00010000)
#define  SE_INTE_1_com_empty_mask                                                (0x00000008)
#define  SE_INTE_1_com_err_mask                                                  (0x00000004)
#define  SE_INTE_1_sync_mask                                                     (0x00000002)
#define  SE_INTE_1_write_data_mask                                               (0x00000001)
#define  SE_INTE_1_vo_sync_err(data)                                             (0x00020000&((data)<<17))
#define  SE_INTE_1_fmt_err(data)                                                 (0x00010000&((data)<<16))
#define  SE_INTE_1_com_empty(data)                                               (0x00000008&((data)<<3))
#define  SE_INTE_1_com_err(data)                                                 (0x00000004&((data)<<2))
#define  SE_INTE_1_sync(data)                                                    (0x00000002&((data)<<1))
#define  SE_INTE_1_write_data(data)                                              (0x00000001&(data))
#define  SE_INTE_1_get_vo_sync_err(data)                                         ((0x00020000&(data))>>17)
#define  SE_INTE_1_get_fmt_err(data)                                             ((0x00010000&(data))>>16)
#define  SE_INTE_1_get_com_empty(data)                                           ((0x00000008&(data))>>3)
#define  SE_INTE_1_get_com_err(data)                                             ((0x00000004&(data))>>2)
#define  SE_INTE_1_get_sync(data)                                                ((0x00000002&(data))>>1)
#define  SE_INTE_1_get_write_data(data)                                          (0x00000001&(data))

#define  SE_INSTCNT_L_0                                                          0x1800C9B0
#define  SE_INSTCNT_L_0_reg_addr                                                 "0xB800C9B0"
#define  SE_INSTCNT_L_0_reg                                                      0xB800C9B0
#define  SE_INSTCNT_L_0_inst_addr                                                "0x0123"
#define  set_SE_INSTCNT_L_0_reg(data)                                            (*((volatile unsigned int*)SE_INSTCNT_L_0_reg)=data)
#define  get_SE_INSTCNT_L_0_reg                                                  (*((volatile unsigned int*)SE_INSTCNT_L_0_reg))
#define  SE_INSTCNT_L_0_instcnt_l_shift                                          (0)
#define  SE_INSTCNT_L_0_instcnt_l_mask                                           (0xFFFFFFFF)
#define  SE_INSTCNT_L_0_instcnt_l(data)                                          (0xFFFFFFFF&(data))
#define  SE_INSTCNT_L_0_get_instcnt_l(data)                                      (0xFFFFFFFF&(data))

#define  SE_INSTCNT_L_1                                                          0x1800C9B4
#define  SE_INSTCNT_L_1_reg_addr                                                 "0xB800C9B4"
#define  SE_INSTCNT_L_1_reg                                                      0xB800C9B4
#define  SE_INSTCNT_L_1_inst_addr                                                "0x0124"
#define  set_SE_INSTCNT_L_1_reg(data)                                            (*((volatile unsigned int*)SE_INSTCNT_L_1_reg)=data)
#define  get_SE_INSTCNT_L_1_reg                                                  (*((volatile unsigned int*)SE_INSTCNT_L_1_reg))
#define  SE_INSTCNT_L_1_instcnt_l_shift                                          (0)
#define  SE_INSTCNT_L_1_instcnt_l_mask                                           (0xFFFFFFFF)
#define  SE_INSTCNT_L_1_instcnt_l(data)                                          (0xFFFFFFFF&(data))
#define  SE_INSTCNT_L_1_get_instcnt_l(data)                                      (0xFFFFFFFF&(data))

#define  SE_INSTCNT_H_0                                                          0x1800C9C0
#define  SE_INSTCNT_H_0_reg_addr                                                 "0xB800C9C0"
#define  SE_INSTCNT_H_0_reg                                                      0xB800C9C0
#define  SE_INSTCNT_H_0_inst_addr                                                "0x0125"
#define  set_SE_INSTCNT_H_0_reg(data)                                            (*((volatile unsigned int*)SE_INSTCNT_H_0_reg)=data)
#define  get_SE_INSTCNT_H_0_reg                                                  (*((volatile unsigned int*)SE_INSTCNT_H_0_reg))
#define  SE_INSTCNT_H_0_instcnt_h_shift                                          (0)
#define  SE_INSTCNT_H_0_instcnt_h_mask                                           (0xFFFFFFFF)
#define  SE_INSTCNT_H_0_instcnt_h(data)                                          (0xFFFFFFFF&(data))
#define  SE_INSTCNT_H_0_get_instcnt_h(data)                                      (0xFFFFFFFF&(data))

#define  SE_INSTCNT_H_1                                                          0x1800C9C4
#define  SE_INSTCNT_H_1_reg_addr                                                 "0xB800C9C4"
#define  SE_INSTCNT_H_1_reg                                                      0xB800C9C4
#define  SE_INSTCNT_H_1_inst_addr                                                "0x0126"
#define  set_SE_INSTCNT_H_1_reg(data)                                            (*((volatile unsigned int*)SE_INSTCNT_H_1_reg)=data)
#define  get_SE_INSTCNT_H_1_reg                                                  (*((volatile unsigned int*)SE_INSTCNT_H_1_reg))
#define  SE_INSTCNT_H_1_instcnt_h_shift                                          (0)
#define  SE_INSTCNT_H_1_instcnt_h_mask                                           (0xFFFFFFFF)
#define  SE_INSTCNT_H_1_instcnt_h(data)                                          (0xFFFFFFFF&(data))
#define  SE_INSTCNT_H_1_get_instcnt_h(data)                                      (0xFFFFFFFF&(data))

#define  SE_CLUT_RADR                                                            0x1800C9D0
#define  SE_CLUT_RADR_reg_addr                                                   "0xB800C9D0"
#define  SE_CLUT_RADR_reg                                                        0xB800C9D0
#define  SE_CLUT_RADR_inst_addr                                                  "0x0127"
#define  set_SE_CLUT_RADR_reg(data)                                              (*((volatile unsigned int*)SE_CLUT_RADR_reg)=data)
#define  get_SE_CLUT_RADR_reg                                                    (*((volatile unsigned int*)SE_CLUT_RADR_reg))
#define  SE_CLUT_RADR_radr_shift                                                 (0)
#define  SE_CLUT_RADR_radr_mask                                                  (0x000000FF)
#define  SE_CLUT_RADR_radr(data)                                                 (0x000000FF&(data))
#define  SE_CLUT_RADR_get_radr(data)                                             (0x000000FF&(data))

#define  SE_CLUT_VALUE                                                           0x1800C9D4
#define  SE_CLUT_VALUE_reg_addr                                                  "0xB800C9D4"
#define  SE_CLUT_VALUE_reg                                                       0xB800C9D4
#define  SE_CLUT_VALUE_inst_addr                                                 "0x0128"
#define  set_SE_CLUT_VALUE_reg(data)                                             (*((volatile unsigned int*)SE_CLUT_VALUE_reg)=data)
#define  get_SE_CLUT_VALUE_reg                                                   (*((volatile unsigned int*)SE_CLUT_VALUE_reg))
#define  SE_CLUT_VALUE_value_shift                                               (0)
#define  SE_CLUT_VALUE_value_mask                                                (0xFFFFFFFF)
#define  SE_CLUT_VALUE_value(data)                                               (0xFFFFFFFF&(data))
#define  SE_CLUT_VALUE_get_value(data)                                           (0xFFFFFFFF&(data))

#define  SE_DBG                                                                  0x1800C9D8
#define  SE_DBG_reg_addr                                                         "0xB800C9D8"
#define  SE_DBG_reg                                                              0xB800C9D8
#define  SE_DBG_inst_addr                                                        "0x0129"
#define  set_SE_DBG_reg(data)                                                    (*((volatile unsigned int*)SE_DBG_reg)=data)
#define  get_SE_DBG_reg                                                          (*((volatile unsigned int*)SE_DBG_reg))
#define  SE_DBG_dbg_change_shift                                                 (25)
#define  SE_DBG_dbg_en_shift                                                     (24)
#define  SE_DBG_dbg_module_sel1_shift                                            (20)
#define  SE_DBG_dbg_module_sel0_shift                                            (16)
#define  SE_DBG_dbg_sel1_shift                                                   (8)
#define  SE_DBG_dbg_sel0_shift                                                   (0)
#define  SE_DBG_dbg_change_mask                                                  (0x02000000)
#define  SE_DBG_dbg_en_mask                                                      (0x01000000)
#define  SE_DBG_dbg_module_sel1_mask                                             (0x00F00000)
#define  SE_DBG_dbg_module_sel0_mask                                             (0x000F0000)
#define  SE_DBG_dbg_sel1_mask                                                    (0x00001F00)
#define  SE_DBG_dbg_sel0_mask                                                    (0x0000001F)
#define  SE_DBG_dbg_change(data)                                                 (0x02000000&((data)<<25))
#define  SE_DBG_dbg_en(data)                                                     (0x01000000&((data)<<24))
#define  SE_DBG_dbg_module_sel1(data)                                            (0x00F00000&((data)<<20))
#define  SE_DBG_dbg_module_sel0(data)                                            (0x000F0000&((data)<<16))
#define  SE_DBG_dbg_sel1(data)                                                   (0x00001F00&((data)<<8))
#define  SE_DBG_dbg_sel0(data)                                                   (0x0000001F&(data))
#define  SE_DBG_get_dbg_change(data)                                             ((0x02000000&(data))>>25)
#define  SE_DBG_get_dbg_en(data)                                                 ((0x01000000&(data))>>24)
#define  SE_DBG_get_dbg_module_sel1(data)                                        ((0x00F00000&(data))>>20)
#define  SE_DBG_get_dbg_module_sel0(data)                                        ((0x000F0000&(data))>>16)
#define  SE_DBG_get_dbg_sel1(data)                                               ((0x00001F00&(data))>>8)
#define  SE_DBG_get_dbg_sel0(data)                                               (0x0000001F&(data))

#define  SE_SCTCH                                                                0x1800C9DC
#define  SE_SCTCH_reg_addr                                                       "0xB800C9DC"
#define  SE_SCTCH_reg                                                            0xB800C9DC
#define  SE_SCTCH_inst_addr                                                      "0x012A"
#define  set_SE_SCTCH_reg(data)                                                  (*((volatile unsigned int*)SE_SCTCH_reg)=data)
#define  get_SE_SCTCH_reg                                                        (*((volatile unsigned int*)SE_SCTCH_reg))
#define  SE_SCTCH_reg1_shift                                                     (16)
#define  SE_SCTCH_reg0_shift                                                     (0)
#define  SE_SCTCH_reg1_mask                                                      (0xFFFF0000)
#define  SE_SCTCH_reg0_mask                                                      (0x0000FFFF)
#define  SE_SCTCH_reg1(data)                                                     (0xFFFF0000&((data)<<16))
#define  SE_SCTCH_reg0(data)                                                     (0x0000FFFF&(data))
#define  SE_SCTCH_get_reg1(data)                                                 ((0xFFFF0000&(data))>>16)
#define  SE_SCTCH_get_reg0(data)                                                 (0x0000FFFF&(data))

#define  SE_SFT                                                                  0x1800C9E0
#define  SE_SFT_reg_addr                                                         "0xB800C9E0"
#define  SE_SFT_reg                                                              0xB800C9E0
#define  SE_SFT_inst_addr                                                        "0x012B"
#define  set_SE_SFT_reg(data)                                                    (*((volatile unsigned int*)SE_SFT_reg)=data)
#define  get_SE_SFT_reg                                                          (*((volatile unsigned int*)SE_SFT_reg))
#define  SE_SFT_reg_sf_rx_err_ro_shift                                           (31)
#define  SE_SFT_reg_sf_rx_done_ro_shift                                          (30)
#define  SE_SFT_reg_sf_rx_gated_shift                                            (29)
#define  SE_SFT_reg_sf_rx_start_shift                                            (28)
#define  SE_SFT_reg_sf_rx_mode_shift                                             (27)
#define  SE_SFT_reg_sf_tx_work_ro_shift                                          (2)
#define  SE_SFT_reg_sf_tx_start_shift                                            (1)
#define  SE_SFT_reg_sf_tx_mode_shift                                             (0)
#define  SE_SFT_reg_sf_rx_err_ro_mask                                            (0x80000000)
#define  SE_SFT_reg_sf_rx_done_ro_mask                                           (0x40000000)
#define  SE_SFT_reg_sf_rx_gated_mask                                             (0x20000000)
#define  SE_SFT_reg_sf_rx_start_mask                                             (0x10000000)
#define  SE_SFT_reg_sf_rx_mode_mask                                              (0x08000000)
#define  SE_SFT_reg_sf_tx_work_ro_mask                                           (0x00000004)
#define  SE_SFT_reg_sf_tx_start_mask                                             (0x00000002)
#define  SE_SFT_reg_sf_tx_mode_mask                                              (0x00000001)
#define  SE_SFT_reg_sf_rx_err_ro(data)                                           (0x80000000&((data)<<31))
#define  SE_SFT_reg_sf_rx_done_ro(data)                                          (0x40000000&((data)<<30))
#define  SE_SFT_reg_sf_rx_gated(data)                                            (0x20000000&((data)<<29))
#define  SE_SFT_reg_sf_rx_start(data)                                            (0x10000000&((data)<<28))
#define  SE_SFT_reg_sf_rx_mode(data)                                             (0x08000000&((data)<<27))
#define  SE_SFT_reg_sf_tx_work_ro(data)                                          (0x00000004&((data)<<2))
#define  SE_SFT_reg_sf_tx_start(data)                                            (0x00000002&((data)<<1))
#define  SE_SFT_reg_sf_tx_mode(data)                                             (0x00000001&(data))
#define  SE_SFT_get_reg_sf_rx_err_ro(data)                                       ((0x80000000&(data))>>31)
#define  SE_SFT_get_reg_sf_rx_done_ro(data)                                      ((0x40000000&(data))>>30)
#define  SE_SFT_get_reg_sf_rx_gated(data)                                        ((0x20000000&(data))>>29)
#define  SE_SFT_get_reg_sf_rx_start(data)                                        ((0x10000000&(data))>>28)
#define  SE_SFT_get_reg_sf_rx_mode(data)                                         ((0x08000000&(data))>>27)
#define  SE_SFT_get_reg_sf_tx_work_ro(data)                                      ((0x00000004&(data))>>2)
#define  SE_SFT_get_reg_sf_tx_start(data)                                        ((0x00000002&(data))>>1)
#define  SE_SFT_get_reg_sf_tx_mode(data)                                         (0x00000001&(data))

#define  SE_READ_MARGIN                                                          0x1800CA00
#define  SE_READ_MARGIN_reg_addr                                                 "0xB800CA00"
#define  SE_READ_MARGIN_reg                                                      0xB800CA00
#define  SE_READ_MARGIN_inst_addr                                                "0x012C"
#define  set_SE_READ_MARGIN_reg(data)                                            (*((volatile unsigned int*)SE_READ_MARGIN_reg)=data)
#define  get_SE_READ_MARGIN_reg                                                  (*((volatile unsigned int*)SE_READ_MARGIN_reg))
#define  SE_READ_MARGIN_ls_shift                                                 (5)
#define  SE_READ_MARGIN_rm_shift                                                 (1)
#define  SE_READ_MARGIN_rme_shift                                                (0)
#define  SE_READ_MARGIN_ls_mask                                                  (0x00000020)
#define  SE_READ_MARGIN_rm_mask                                                  (0x0000001E)
#define  SE_READ_MARGIN_rme_mask                                                 (0x00000001)
#define  SE_READ_MARGIN_ls(data)                                                 (0x00000020&((data)<<5))
#define  SE_READ_MARGIN_rm(data)                                                 (0x0000001E&((data)<<1))
#define  SE_READ_MARGIN_rme(data)                                                (0x00000001&(data))
#define  SE_READ_MARGIN_get_ls(data)                                             ((0x00000020&(data))>>5)
#define  SE_READ_MARGIN_get_rm(data)                                             ((0x0000001E&(data))>>1)
#define  SE_READ_MARGIN_get_rme(data)                                            (0x00000001&(data))

#define  SE_SE_BIST_MODE                                                         0x1800CA04
#define  SE_SE_BIST_MODE_reg_addr                                                "0xB800CA04"
#define  SE_SE_BIST_MODE_reg                                                     0xB800CA04
#define  SE_SE_BIST_MODE_inst_addr                                               "0x012D"
#define  set_SE_SE_BIST_MODE_reg(data)                                           (*((volatile unsigned int*)SE_SE_BIST_MODE_reg)=data)
#define  get_SE_SE_BIST_MODE_reg                                                 (*((volatile unsigned int*)SE_SE_BIST_MODE_reg))
#define  SE_SE_BIST_MODE_se_bist_mode_1_shift                                    (1)
#define  SE_SE_BIST_MODE_se_bist_mode_0_shift                                    (0)
#define  SE_SE_BIST_MODE_se_bist_mode_1_mask                                     (0x00000002)
#define  SE_SE_BIST_MODE_se_bist_mode_0_mask                                     (0x00000001)
#define  SE_SE_BIST_MODE_se_bist_mode_1(data)                                    (0x00000002&((data)<<1))
#define  SE_SE_BIST_MODE_se_bist_mode_0(data)                                    (0x00000001&(data))
#define  SE_SE_BIST_MODE_get_se_bist_mode_1(data)                                ((0x00000002&(data))>>1)
#define  SE_SE_BIST_MODE_get_se_bist_mode_0(data)                                (0x00000001&(data))

#define  SE_SE_BIST_DONE                                                         0x1800CA08
#define  SE_SE_BIST_DONE_reg_addr                                                "0xB800CA08"
#define  SE_SE_BIST_DONE_reg                                                     0xB800CA08
#define  SE_SE_BIST_DONE_inst_addr                                               "0x012E"
#define  set_SE_SE_BIST_DONE_reg(data)                                           (*((volatile unsigned int*)SE_SE_BIST_DONE_reg)=data)
#define  get_SE_SE_BIST_DONE_reg                                                 (*((volatile unsigned int*)SE_SE_BIST_DONE_reg))
#define  SE_SE_BIST_DONE_se_bist_done_1_shift                                    (1)
#define  SE_SE_BIST_DONE_se_bist_done_0_shift                                    (0)
#define  SE_SE_BIST_DONE_se_bist_done_1_mask                                     (0x00000002)
#define  SE_SE_BIST_DONE_se_bist_done_0_mask                                     (0x00000001)
#define  SE_SE_BIST_DONE_se_bist_done_1(data)                                    (0x00000002&((data)<<1))
#define  SE_SE_BIST_DONE_se_bist_done_0(data)                                    (0x00000001&(data))
#define  SE_SE_BIST_DONE_get_se_bist_done_1(data)                                ((0x00000002&(data))>>1)
#define  SE_SE_BIST_DONE_get_se_bist_done_0(data)                                (0x00000001&(data))

#define  SE_SE_BIST_FAIL_GROUP                                                   0x1800CA0C
#define  SE_SE_BIST_FAIL_GROUP_reg_addr                                          "0xB800CA0C"
#define  SE_SE_BIST_FAIL_GROUP_reg                                               0xB800CA0C
#define  SE_SE_BIST_FAIL_GROUP_inst_addr                                         "0x012F"
#define  set_SE_SE_BIST_FAIL_GROUP_reg(data)                                     (*((volatile unsigned int*)SE_SE_BIST_FAIL_GROUP_reg)=data)
#define  get_SE_SE_BIST_FAIL_GROUP_reg                                           (*((volatile unsigned int*)SE_SE_BIST_FAIL_GROUP_reg))
#define  SE_SE_BIST_FAIL_GROUP_se_bist_fail_group_1_shift                        (1)
#define  SE_SE_BIST_FAIL_GROUP_se_bist_fail_group_0_shift                        (0)
#define  SE_SE_BIST_FAIL_GROUP_se_bist_fail_group_1_mask                         (0x00000002)
#define  SE_SE_BIST_FAIL_GROUP_se_bist_fail_group_0_mask                         (0x00000001)
#define  SE_SE_BIST_FAIL_GROUP_se_bist_fail_group_1(data)                        (0x00000002&((data)<<1))
#define  SE_SE_BIST_FAIL_GROUP_se_bist_fail_group_0(data)                        (0x00000001&(data))
#define  SE_SE_BIST_FAIL_GROUP_get_se_bist_fail_group_1(data)                    ((0x00000002&(data))>>1)
#define  SE_SE_BIST_FAIL_GROUP_get_se_bist_fail_group_0(data)                    (0x00000001&(data))

#define  SE_SE_BIST_0_FAIL                                                       0x1800CA10
#define  SE_SE_BIST_0_FAIL_reg_addr                                              "0xB800CA10"
#define  SE_SE_BIST_0_FAIL_reg                                                   0xB800CA10
#define  SE_SE_BIST_0_FAIL_inst_addr                                             "0x0130"
#define  set_SE_SE_BIST_0_FAIL_reg(data)                                         (*((volatile unsigned int*)SE_SE_BIST_0_FAIL_reg)=data)
#define  get_SE_SE_BIST_0_FAIL_reg                                               (*((volatile unsigned int*)SE_SE_BIST_0_FAIL_reg))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_8_shift                                (8)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_7_shift                                (7)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_6_shift                                (6)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_5_shift                                (5)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_4_shift                                (4)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_3_shift                                (3)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_2_shift                                (2)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_1_shift                                (1)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_0_shift                                (0)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_8_mask                                 (0x00000100)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_7_mask                                 (0x00000080)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_6_mask                                 (0x00000040)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_5_mask                                 (0x00000020)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_4_mask                                 (0x00000010)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_3_mask                                 (0x00000008)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_2_mask                                 (0x00000004)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_1_mask                                 (0x00000002)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_0_mask                                 (0x00000001)
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_8(data)                                (0x00000100&((data)<<8))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_7(data)                                (0x00000080&((data)<<7))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_6(data)                                (0x00000040&((data)<<6))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_5(data)                                (0x00000020&((data)<<5))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_4(data)                                (0x00000010&((data)<<4))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_3(data)                                (0x00000008&((data)<<3))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_2(data)                                (0x00000004&((data)<<2))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_1(data)                                (0x00000002&((data)<<1))
#define  SE_SE_BIST_0_FAIL_se_bist_0_fail_0(data)                                (0x00000001&(data))
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_8(data)                            ((0x00000100&(data))>>8)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_7(data)                            ((0x00000080&(data))>>7)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_6(data)                            ((0x00000040&(data))>>6)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_5(data)                            ((0x00000020&(data))>>5)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_4(data)                            ((0x00000010&(data))>>4)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_3(data)                            ((0x00000008&(data))>>3)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_2(data)                            ((0x00000004&(data))>>2)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_1(data)                            ((0x00000002&(data))>>1)
#define  SE_SE_BIST_0_FAIL_get_se_bist_0_fail_0(data)                            (0x00000001&(data))

#define  SE_SE_BIST_1_FAIL                                                       0x1800CA14
#define  SE_SE_BIST_1_FAIL_reg_addr                                              "0xB800CA14"
#define  SE_SE_BIST_1_FAIL_reg                                                   0xB800CA14
#define  SE_SE_BIST_1_FAIL_inst_addr                                             "0x0131"
#define  set_SE_SE_BIST_1_FAIL_reg(data)                                         (*((volatile unsigned int*)SE_SE_BIST_1_FAIL_reg)=data)
#define  get_SE_SE_BIST_1_FAIL_reg                                               (*((volatile unsigned int*)SE_SE_BIST_1_FAIL_reg))
#define  SE_SE_BIST_1_FAIL_se_bist_1_fail_1_shift                                (1)
#define  SE_SE_BIST_1_FAIL_se_bist_1_fail_0_shift                                (0)
#define  SE_SE_BIST_1_FAIL_se_bist_1_fail_1_mask                                 (0x00000002)
#define  SE_SE_BIST_1_FAIL_se_bist_1_fail_0_mask                                 (0x00000001)
#define  SE_SE_BIST_1_FAIL_se_bist_1_fail_1(data)                                (0x00000002&((data)<<1))
#define  SE_SE_BIST_1_FAIL_se_bist_1_fail_0(data)                                (0x00000001&(data))
#define  SE_SE_BIST_1_FAIL_get_se_bist_1_fail_1(data)                            ((0x00000002&(data))>>1)
#define  SE_SE_BIST_1_FAIL_get_se_bist_1_fail_0(data)                            (0x00000001&(data))

#define  SE_SE_DRF_MODE                                                          0x1800CA18
#define  SE_SE_DRF_MODE_reg_addr                                                 "0xB800CA18"
#define  SE_SE_DRF_MODE_reg                                                      0xB800CA18
#define  SE_SE_DRF_MODE_inst_addr                                                "0x0132"
#define  set_SE_SE_DRF_MODE_reg(data)                                            (*((volatile unsigned int*)SE_SE_DRF_MODE_reg)=data)
#define  get_SE_SE_DRF_MODE_reg                                                  (*((volatile unsigned int*)SE_SE_DRF_MODE_reg))
#define  SE_SE_DRF_MODE_se_drf_mode_1_shift                                      (1)
#define  SE_SE_DRF_MODE_se_drf_mode_0_shift                                      (0)
#define  SE_SE_DRF_MODE_se_drf_mode_1_mask                                       (0x00000002)
#define  SE_SE_DRF_MODE_se_drf_mode_0_mask                                       (0x00000001)
#define  SE_SE_DRF_MODE_se_drf_mode_1(data)                                      (0x00000002&((data)<<1))
#define  SE_SE_DRF_MODE_se_drf_mode_0(data)                                      (0x00000001&(data))
#define  SE_SE_DRF_MODE_get_se_drf_mode_1(data)                                  ((0x00000002&(data))>>1)
#define  SE_SE_DRF_MODE_get_se_drf_mode_0(data)                                  (0x00000001&(data))

#define  SE_SE_DRF_RESUME                                                        0x1800CA1C
#define  SE_SE_DRF_RESUME_reg_addr                                               "0xB800CA1C"
#define  SE_SE_DRF_RESUME_reg                                                    0xB800CA1C
#define  SE_SE_DRF_RESUME_inst_addr                                              "0x0133"
#define  set_SE_SE_DRF_RESUME_reg(data)                                          (*((volatile unsigned int*)SE_SE_DRF_RESUME_reg)=data)
#define  get_SE_SE_DRF_RESUME_reg                                                (*((volatile unsigned int*)SE_SE_DRF_RESUME_reg))
#define  SE_SE_DRF_RESUME_se_drf_resume_1_shift                                  (1)
#define  SE_SE_DRF_RESUME_se_drf_resume_0_shift                                  (0)
#define  SE_SE_DRF_RESUME_se_drf_resume_1_mask                                   (0x00000002)
#define  SE_SE_DRF_RESUME_se_drf_resume_0_mask                                   (0x00000001)
#define  SE_SE_DRF_RESUME_se_drf_resume_1(data)                                  (0x00000002&((data)<<1))
#define  SE_SE_DRF_RESUME_se_drf_resume_0(data)                                  (0x00000001&(data))
#define  SE_SE_DRF_RESUME_get_se_drf_resume_1(data)                              ((0x00000002&(data))>>1)
#define  SE_SE_DRF_RESUME_get_se_drf_resume_0(data)                              (0x00000001&(data))

#define  SE_SE_DRF_DONE                                                          0x1800CA20
#define  SE_SE_DRF_DONE_reg_addr                                                 "0xB800CA20"
#define  SE_SE_DRF_DONE_reg                                                      0xB800CA20
#define  SE_SE_DRF_DONE_inst_addr                                                "0x0134"
#define  set_SE_SE_DRF_DONE_reg(data)                                            (*((volatile unsigned int*)SE_SE_DRF_DONE_reg)=data)
#define  get_SE_SE_DRF_DONE_reg                                                  (*((volatile unsigned int*)SE_SE_DRF_DONE_reg))
#define  SE_SE_DRF_DONE_se_drf_done_1_shift                                      (1)
#define  SE_SE_DRF_DONE_se_drf_done_0_shift                                      (0)
#define  SE_SE_DRF_DONE_se_drf_done_1_mask                                       (0x00000002)
#define  SE_SE_DRF_DONE_se_drf_done_0_mask                                       (0x00000001)
#define  SE_SE_DRF_DONE_se_drf_done_1(data)                                      (0x00000002&((data)<<1))
#define  SE_SE_DRF_DONE_se_drf_done_0(data)                                      (0x00000001&(data))
#define  SE_SE_DRF_DONE_get_se_drf_done_1(data)                                  ((0x00000002&(data))>>1)
#define  SE_SE_DRF_DONE_get_se_drf_done_0(data)                                  (0x00000001&(data))

#define  SE_SE_DRF_PAUSE                                                         0x1800CA24
#define  SE_SE_DRF_PAUSE_reg_addr                                                "0xB800CA24"
#define  SE_SE_DRF_PAUSE_reg                                                     0xB800CA24
#define  SE_SE_DRF_PAUSE_inst_addr                                               "0x0135"
#define  set_SE_SE_DRF_PAUSE_reg(data)                                           (*((volatile unsigned int*)SE_SE_DRF_PAUSE_reg)=data)
#define  get_SE_SE_DRF_PAUSE_reg                                                 (*((volatile unsigned int*)SE_SE_DRF_PAUSE_reg))
#define  SE_SE_DRF_PAUSE_se_drf_pause_1_shift                                    (1)
#define  SE_SE_DRF_PAUSE_se_drf_pause_0_shift                                    (0)
#define  SE_SE_DRF_PAUSE_se_drf_pause_1_mask                                     (0x00000002)
#define  SE_SE_DRF_PAUSE_se_drf_pause_0_mask                                     (0x00000001)
#define  SE_SE_DRF_PAUSE_se_drf_pause_1(data)                                    (0x00000002&((data)<<1))
#define  SE_SE_DRF_PAUSE_se_drf_pause_0(data)                                    (0x00000001&(data))
#define  SE_SE_DRF_PAUSE_get_se_drf_pause_1(data)                                ((0x00000002&(data))>>1)
#define  SE_SE_DRF_PAUSE_get_se_drf_pause_0(data)                                (0x00000001&(data))

#define  SE_SE_DRF_FAIL_GROUP                                                    0x1800CA28
#define  SE_SE_DRF_FAIL_GROUP_reg_addr                                           "0xB800CA28"
#define  SE_SE_DRF_FAIL_GROUP_reg                                                0xB800CA28
#define  SE_SE_DRF_FAIL_GROUP_inst_addr                                          "0x0136"
#define  set_SE_SE_DRF_FAIL_GROUP_reg(data)                                      (*((volatile unsigned int*)SE_SE_DRF_FAIL_GROUP_reg)=data)
#define  get_SE_SE_DRF_FAIL_GROUP_reg                                            (*((volatile unsigned int*)SE_SE_DRF_FAIL_GROUP_reg))
#define  SE_SE_DRF_FAIL_GROUP_se_drf_fail_group_1_shift                          (1)
#define  SE_SE_DRF_FAIL_GROUP_se_drf_fail_group_0_shift                          (0)
#define  SE_SE_DRF_FAIL_GROUP_se_drf_fail_group_1_mask                           (0x00000002)
#define  SE_SE_DRF_FAIL_GROUP_se_drf_fail_group_0_mask                           (0x00000001)
#define  SE_SE_DRF_FAIL_GROUP_se_drf_fail_group_1(data)                          (0x00000002&((data)<<1))
#define  SE_SE_DRF_FAIL_GROUP_se_drf_fail_group_0(data)                          (0x00000001&(data))
#define  SE_SE_DRF_FAIL_GROUP_get_se_drf_fail_group_1(data)                      ((0x00000002&(data))>>1)
#define  SE_SE_DRF_FAIL_GROUP_get_se_drf_fail_group_0(data)                      (0x00000001&(data))

#define  SE_SE_DRF_0_FAIL                                                        0x1800CA2C
#define  SE_SE_DRF_0_FAIL_reg_addr                                               "0xB800CA2C"
#define  SE_SE_DRF_0_FAIL_reg                                                    0xB800CA2C
#define  SE_SE_DRF_0_FAIL_inst_addr                                              "0x0137"
#define  set_SE_SE_DRF_0_FAIL_reg(data)                                          (*((volatile unsigned int*)SE_SE_DRF_0_FAIL_reg)=data)
#define  get_SE_SE_DRF_0_FAIL_reg                                                (*((volatile unsigned int*)SE_SE_DRF_0_FAIL_reg))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_8_shift                                  (8)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_7_shift                                  (7)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_6_shift                                  (6)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_5_shift                                  (5)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_4_shift                                  (4)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_3_shift                                  (3)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_2_shift                                  (2)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_1_shift                                  (1)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_0_shift                                  (0)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_8_mask                                   (0x00000100)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_7_mask                                   (0x00000080)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_6_mask                                   (0x00000040)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_5_mask                                   (0x00000020)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_4_mask                                   (0x00000010)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_3_mask                                   (0x00000008)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_2_mask                                   (0x00000004)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_1_mask                                   (0x00000002)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_0_mask                                   (0x00000001)
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_8(data)                                  (0x00000100&((data)<<8))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_7(data)                                  (0x00000080&((data)<<7))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_6(data)                                  (0x00000040&((data)<<6))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_5(data)                                  (0x00000020&((data)<<5))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_4(data)                                  (0x00000010&((data)<<4))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_3(data)                                  (0x00000008&((data)<<3))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_2(data)                                  (0x00000004&((data)<<2))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_1(data)                                  (0x00000002&((data)<<1))
#define  SE_SE_DRF_0_FAIL_se_drf_0_fail_0(data)                                  (0x00000001&(data))
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_8(data)                              ((0x00000100&(data))>>8)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_7(data)                              ((0x00000080&(data))>>7)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_6(data)                              ((0x00000040&(data))>>6)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_5(data)                              ((0x00000020&(data))>>5)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_4(data)                              ((0x00000010&(data))>>4)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_3(data)                              ((0x00000008&(data))>>3)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_2(data)                              ((0x00000004&(data))>>2)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_1(data)                              ((0x00000002&(data))>>1)
#define  SE_SE_DRF_0_FAIL_get_se_drf_0_fail_0(data)                              (0x00000001&(data))

#define  SE_SE_DRF_1_FAIL                                                        0x1800CA30
#define  SE_SE_DRF_1_FAIL_reg_addr                                               "0xB800CA30"
#define  SE_SE_DRF_1_FAIL_reg                                                    0xB800CA30
#define  SE_SE_DRF_1_FAIL_inst_addr                                              "0x0138"
#define  set_SE_SE_DRF_1_FAIL_reg(data)                                          (*((volatile unsigned int*)SE_SE_DRF_1_FAIL_reg)=data)
#define  get_SE_SE_DRF_1_FAIL_reg                                                (*((volatile unsigned int*)SE_SE_DRF_1_FAIL_reg))
#define  SE_SE_DRF_1_FAIL_se_drf_1_fail_1_shift                                  (1)
#define  SE_SE_DRF_1_FAIL_se_drf_1_fail_0_shift                                  (0)
#define  SE_SE_DRF_1_FAIL_se_drf_1_fail_1_mask                                   (0x00000002)
#define  SE_SE_DRF_1_FAIL_se_drf_1_fail_0_mask                                   (0x00000001)
#define  SE_SE_DRF_1_FAIL_se_drf_1_fail_1(data)                                  (0x00000002&((data)<<1))
#define  SE_SE_DRF_1_FAIL_se_drf_1_fail_0(data)                                  (0x00000001&(data))
#define  SE_SE_DRF_1_FAIL_get_se_drf_1_fail_1(data)                              ((0x00000002&(data))>>1)
#define  SE_SE_DRF_1_FAIL_get_se_drf_1_fail_0(data)                              (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base:28;
        RBus_UInt32  res1:4;
    };
}se_cmdbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit:28;
        RBus_UInt32  res1:4;
    };
}se_cmdlmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rptr:28;
        RBus_UInt32  res1:4;
    };
}se_cmdrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wptr:28;
        RBus_UInt32  res1:4;
    };
}se_cmdwptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  srwordcnt:7;
    };
}se_srwordcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  disable:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  pri2:2;
        RBus_UInt32  pri1:2;
    };
}se_q_priority_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  rounding_en:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  big_endian_o:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  big_endian_i2:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  big_endian_i1:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  alpha_loc2:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  alpha_loc:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  format:4;
    };
}se_clr_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  color_key:24;
    };
}se_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dst_color_key:24;
    };
}se_dst_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_color:32;
    };
}se_src_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  src_alpha:8;
    };
}se_src_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dest_alpha:8;
    };
}se_dest_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rslt_alpha:8;
    };
}se_rslt_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  baddr:32;
    };
}se_baddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  interleave:1;
        RBus_UInt32  pitch:16;
    };
}se_pitch1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  baddr:32;
    };
}se_baddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  interleave:1;
        RBus_UInt32  pitch:16;
    };
}se_pitch2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  clut_lock_st:3;
    };
}se_clut_lock_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hdown:1;
        RBus_UInt32  vdown:1;
        RBus_UInt32  hup:1;
        RBus_UInt32  vup:1;
    };
}se_convscaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  m01:13;
        RBus_UInt32  m00:13;
    };
}se_convcoef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  m10:13;
        RBus_UInt32  m02:13;
    };
}se_convcoef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  m12:13;
        RBus_UInt32  m11:13;
    };
}se_convcoef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  m21:13;
        RBus_UInt32  m20:13;
    };
}se_convcoef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  m22:13;
    };
}se_convcoef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  a2:10;
        RBus_UInt32  a1:10;
        RBus_UInt32  a0:10;
    };
}se_convcoef6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  color_key:24;
    };
}se_fcv_bitblit_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_red:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  src_clr_mul_red:9;
    };
}se_src_clr_red_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_green:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  src_clr_mul_green:9;
    };
}se_src_clr_green_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_blue:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  src_clr_mul_blue:9;
    };
}se_src_clr_blue_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_alpha:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  src_clr_mul_alpha:9;
    };
}se_src_clr_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_dir_en:1;
        RBus_UInt32  vo_plane:1;
        RBus_UInt32  before_vo_cur:1;
        RBus_UInt32  after_vo_cur:1;
        RBus_UInt32  vbi:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  margin_votose:12;
    };
}se_sync_vo_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vo_current_y:14;
    };
}se_sync_vo_location_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  color_alpha:8;
    };
}se_fb_coloralpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  repl_alpha:1;
        RBus_UInt32  repl_color:1;
        RBus_UInt32  ref_alpha:1;
        RBus_UInt32  htype:2;
        RBus_UInt32  vtype:1;
        RBus_UInt32  hodd:1;
        RBus_UInt32  vodd:1;
    };
}se_stretch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  h_scaling_iniph:4;
        RBus_UInt32  h_scaling_dph_msb:4;
        RBus_UInt32  h_scaling_dph_lsb:14;
    };
}se_hdhs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  v_scaling_iniph:4;
        RBus_UInt32  v_scaling_dph_msb:4;
        RBus_UInt32  v_scaling_dph_lsb:14;
    };
}se_vdhs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hcoef:14;
    };
}se_hcoef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hcoef:14;
    };
}se_hcoef1_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vcoef:14;
    };
}se_vcoef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vcoef:14;
    };
}se_vcoef1_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hcoef:14;
    };
}se_hcoef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hcoef:14;
    };
}se_hcoef2_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vcoef:14;
    };
}se_vcoef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vcoef:14;
    };
}se_vcoef2_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  color_key:24;
    };
}se_sc_bitblit_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  src_x_color_g_step:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  src_x_color_r_step:13;
    };
}se_src_lg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  src_x_color_b_step:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  src_x_alpha_step:13;
    };
}se_src_lg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  src_y_color_g_step:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  src_y_color_r_step:13;
    };
}se_src_lg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  src_y_color_b_step:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  src_y_alpha_step:13;
    };
}se_src_lg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  src_color_direction:2;
    };
}se_src_lg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  endiswap:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}se_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  idle:1;
    };
}se_idle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sel2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  sel1:3;
    };
}se_intsel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  vo_sync_err:1;
        RBus_UInt32  fmt_err:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  com_empty:1;
        RBus_UInt32  com_err:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}se_ints_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  vo_sync_err:1;
        RBus_UInt32  fmt_err:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  com_empty:1;
        RBus_UInt32  com_err:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  write_data:1;
    };
}se_inte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  instcnt_l:32;
    };
}se_instcnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  instcnt_h:32;
    };
}se_instcnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  radr:8;
    };
}se_clut_radr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}se_clut_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  dbg_change:1;
        RBus_UInt32  dbg_en:1;
        RBus_UInt32  dbg_module_sel1:4;
        RBus_UInt32  dbg_module_sel0:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dbg_sel1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  dbg_sel0:5;
    };
}se_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg1:16;
        RBus_UInt32  reg0:16;
    };
}se_sctch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_rx_err_ro:1;
        RBus_UInt32  reg_sf_rx_done_ro:1;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_sf_tx_work_ro:1;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  reg_sf_tx_mode:1;
    };
}se_sft_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls:1;
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
    };
}se_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_bist_mode_1:1;
        RBus_UInt32  se_bist_mode_0:1;
    };
}se_se_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_bist_done_1:1;
        RBus_UInt32  se_bist_done_0:1;
    };
}se_se_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_bist_fail_group_1:1;
        RBus_UInt32  se_bist_fail_group_0:1;
    };
}se_se_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  se_bist_0_fail_8:1;
        RBus_UInt32  se_bist_0_fail_7:1;
        RBus_UInt32  se_bist_0_fail_6:1;
        RBus_UInt32  se_bist_0_fail_5:1;
        RBus_UInt32  se_bist_0_fail_4:1;
        RBus_UInt32  se_bist_0_fail_3:1;
        RBus_UInt32  se_bist_0_fail_2:1;
        RBus_UInt32  se_bist_0_fail_1:1;
        RBus_UInt32  se_bist_0_fail_0:1;
    };
}se_se_bist_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_bist_1_fail_1:1;
        RBus_UInt32  se_bist_1_fail_0:1;
    };
}se_se_bist_1_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_drf_mode_1:1;
        RBus_UInt32  se_drf_mode_0:1;
    };
}se_se_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_drf_resume_1:1;
        RBus_UInt32  se_drf_resume_0:1;
    };
}se_se_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_drf_done_1:1;
        RBus_UInt32  se_drf_done_0:1;
    };
}se_se_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_drf_pause_1:1;
        RBus_UInt32  se_drf_pause_0:1;
    };
}se_se_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_drf_fail_group_1:1;
        RBus_UInt32  se_drf_fail_group_0:1;
    };
}se_se_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  se_drf_0_fail_8:1;
        RBus_UInt32  se_drf_0_fail_7:1;
        RBus_UInt32  se_drf_0_fail_6:1;
        RBus_UInt32  se_drf_0_fail_5:1;
        RBus_UInt32  se_drf_0_fail_4:1;
        RBus_UInt32  se_drf_0_fail_3:1;
        RBus_UInt32  se_drf_0_fail_2:1;
        RBus_UInt32  se_drf_0_fail_1:1;
        RBus_UInt32  se_drf_0_fail_0:1;
    };
}se_se_drf_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  se_drf_1_fail_1:1;
        RBus_UInt32  se_drf_1_fail_0:1;
    };
}se_se_drf_1_fail_RBUS;

#else //apply LITTLE_ENDIAN

//======SE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  base:28;
    };
}se_cmdbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  limit:28;
    };
}se_cmdlmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rptr:28;
    };
}se_cmdrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  wptr:28;
    };
}se_cmdwptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srwordcnt:7;
        RBus_UInt32  res1:25;
    };
}se_srwordcnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pri1:2;
        RBus_UInt32  pri2:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  disable:4;
        RBus_UInt32  res2:20;
    };
}se_q_priority_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  format:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  alpha_loc:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  alpha_loc2:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  big_endian_i1:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  big_endian_i2:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  big_endian_o:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  rounding_en:1;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  res2:9;
    };
}se_clr_fmt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_key:24;
        RBus_UInt32  res1:8;
    };
}se_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dst_color_key:24;
        RBus_UInt32  res1:8;
    };
}se_dst_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_color:32;
    };
}se_src_color_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_alpha:8;
        RBus_UInt32  res1:24;
    };
}se_src_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dest_alpha:8;
        RBus_UInt32  res1:24;
    };
}se_dest_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rslt_alpha:8;
        RBus_UInt32  res1:24;
    };
}se_rslt_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  baddr:32;
    };
}se_baddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pitch:16;
        RBus_UInt32  interleave:1;
        RBus_UInt32  res1:15;
    };
}se_pitch1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  baddr:32;
    };
}se_baddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pitch:16;
        RBus_UInt32  interleave:1;
        RBus_UInt32  res1:15;
    };
}se_pitch2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clut_lock_st:3;
        RBus_UInt32  res1:29;
    };
}se_clut_lock_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vup:1;
        RBus_UInt32  hup:1;
        RBus_UInt32  vdown:1;
        RBus_UInt32  hdown:1;
        RBus_UInt32  res1:28;
    };
}se_convscaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m00:13;
        RBus_UInt32  m01:13;
        RBus_UInt32  res1:6;
    };
}se_convcoef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m02:13;
        RBus_UInt32  m10:13;
        RBus_UInt32  res1:6;
    };
}se_convcoef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:13;
        RBus_UInt32  m12:13;
        RBus_UInt32  res1:6;
    };
}se_convcoef3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m20:13;
        RBus_UInt32  m21:13;
        RBus_UInt32  res1:6;
    };
}se_convcoef4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:13;
        RBus_UInt32  res1:19;
    };
}se_convcoef5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a0:10;
        RBus_UInt32  a1:10;
        RBus_UInt32  a2:10;
        RBus_UInt32  res1:2;
    };
}se_convcoef6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_key:24;
        RBus_UInt32  res1:8;
    };
}se_fcv_bitblit_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_clr_mul_red:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_red:9;
        RBus_UInt32  res2:7;
    };
}se_src_clr_red_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_clr_mul_green:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_green:9;
        RBus_UInt32  res2:7;
    };
}se_src_clr_green_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_clr_mul_blue:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_blue:9;
        RBus_UInt32  res2:7;
    };
}se_src_clr_blue_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_clr_mul_alpha:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  src_clr_add_alpha:9;
        RBus_UInt32  res2:7;
    };
}se_src_clr_alpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  margin_votose:12;
        RBus_UInt32  res1:15;
        RBus_UInt32  vbi:1;
        RBus_UInt32  after_vo_cur:1;
        RBus_UInt32  before_vo_cur:1;
        RBus_UInt32  vo_plane:1;
        RBus_UInt32  auto_dir_en:1;
    };
}se_sync_vo_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vo_current_y:14;
        RBus_UInt32  res1:18;
    };
}se_sync_vo_location_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_alpha:8;
        RBus_UInt32  res1:24;
    };
}se_fb_coloralpha_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vodd:1;
        RBus_UInt32  hodd:1;
        RBus_UInt32  vtype:1;
        RBus_UInt32  htype:2;
        RBus_UInt32  ref_alpha:1;
        RBus_UInt32  repl_color:1;
        RBus_UInt32  repl_alpha:1;
        RBus_UInt32  res1:24;
    };
}se_stretch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_scaling_dph_lsb:14;
        RBus_UInt32  h_scaling_dph_msb:4;
        RBus_UInt32  h_scaling_iniph:4;
        RBus_UInt32  res1:10;
    };
}se_hdhs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_scaling_dph_lsb:14;
        RBus_UInt32  v_scaling_dph_msb:4;
        RBus_UInt32  v_scaling_iniph:4;
        RBus_UInt32  res1:10;
    };
}se_vdhs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcoef:14;
        RBus_UInt32  res1:18;
    };
}se_hcoef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcoef:14;
        RBus_UInt32  res1:18;
    };
}se_hcoef1_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcoef:14;
        RBus_UInt32  res1:18;
    };
}se_vcoef1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcoef:14;
        RBus_UInt32  res1:18;
    };
}se_vcoef1_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcoef:14;
        RBus_UInt32  res1:18;
    };
}se_hcoef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcoef:14;
        RBus_UInt32  res1:18;
    };
}se_hcoef2_32_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcoef:14;
        RBus_UInt32  res1:18;
    };
}se_vcoef2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vcoef:14;
        RBus_UInt32  res1:18;
    };
}se_vcoef2_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  color_key:24;
        RBus_UInt32  res1:8;
    };
}se_sc_bitblit_color_key_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_x_color_r_step:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  src_x_color_g_step:13;
        RBus_UInt32  res2:3;
    };
}se_src_lg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_x_alpha_step:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  src_x_color_b_step:13;
        RBus_UInt32  res2:3;
    };
}se_src_lg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_y_color_r_step:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  src_y_color_g_step:13;
        RBus_UInt32  res2:3;
    };
}se_src_lg_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_y_alpha_step:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  src_y_color_b_step:13;
        RBus_UInt32  res2:3;
    };
}se_src_lg_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_color_direction:2;
        RBus_UInt32  res1:30;
    };
}se_src_lg_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  endiswap:1;
        RBus_UInt32  res1:29;
    };
}se_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  idle:1;
        RBus_UInt32  res1:31;
    };
}se_idle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel1:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  sel2:3;
        RBus_UInt32  res2:25;
    };
}se_intsel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  com_err:1;
        RBus_UInt32  com_empty:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  fmt_err:1;
        RBus_UInt32  vo_sync_err:1;
        RBus_UInt32  res2:14;
    };
}se_ints_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sync:1;
        RBus_UInt32  com_err:1;
        RBus_UInt32  com_empty:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  fmt_err:1;
        RBus_UInt32  vo_sync_err:1;
        RBus_UInt32  res2:14;
    };
}se_inte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  instcnt_l:32;
    };
}se_instcnt_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  instcnt_h:32;
    };
}se_instcnt_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  radr:8;
        RBus_UInt32  res1:24;
    };
}se_clut_radr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:32;
    };
}se_clut_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbg_sel0:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  dbg_sel1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dbg_module_sel0:4;
        RBus_UInt32  dbg_module_sel1:4;
        RBus_UInt32  dbg_en:1;
        RBus_UInt32  dbg_change:1;
        RBus_UInt32  res3:6;
    };
}se_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg0:16;
        RBus_UInt32  reg1:16;
    };
}se_sctch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_sf_tx_mode:1;
        RBus_UInt32  reg_sf_tx_start:1;
        RBus_UInt32  reg_sf_tx_work_ro:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_sf_rx_mode:1;
        RBus_UInt32  reg_sf_rx_start:1;
        RBus_UInt32  reg_sf_rx_gated:1;
        RBus_UInt32  reg_sf_rx_done_ro:1;
        RBus_UInt32  reg_sf_rx_err_ro:1;
    };
}se_sft_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:26;
    };
}se_read_margin_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_bist_mode_0:1;
        RBus_UInt32  se_bist_mode_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_bist_done_0:1;
        RBus_UInt32  se_bist_done_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_bist_fail_group_0:1;
        RBus_UInt32  se_bist_fail_group_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_bist_0_fail_0:1;
        RBus_UInt32  se_bist_0_fail_1:1;
        RBus_UInt32  se_bist_0_fail_2:1;
        RBus_UInt32  se_bist_0_fail_3:1;
        RBus_UInt32  se_bist_0_fail_4:1;
        RBus_UInt32  se_bist_0_fail_5:1;
        RBus_UInt32  se_bist_0_fail_6:1;
        RBus_UInt32  se_bist_0_fail_7:1;
        RBus_UInt32  se_bist_0_fail_8:1;
        RBus_UInt32  res1:23;
    };
}se_se_bist_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_bist_1_fail_0:1;
        RBus_UInt32  se_bist_1_fail_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_bist_1_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_mode_0:1;
        RBus_UInt32  se_drf_mode_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_resume_0:1;
        RBus_UInt32  se_drf_resume_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_done_0:1;
        RBus_UInt32  se_drf_done_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_pause_0:1;
        RBus_UInt32  se_drf_pause_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_fail_group_0:1;
        RBus_UInt32  se_drf_fail_group_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_0_fail_0:1;
        RBus_UInt32  se_drf_0_fail_1:1;
        RBus_UInt32  se_drf_0_fail_2:1;
        RBus_UInt32  se_drf_0_fail_3:1;
        RBus_UInt32  se_drf_0_fail_4:1;
        RBus_UInt32  se_drf_0_fail_5:1;
        RBus_UInt32  se_drf_0_fail_6:1;
        RBus_UInt32  se_drf_0_fail_7:1;
        RBus_UInt32  se_drf_0_fail_8:1;
        RBus_UInt32  res1:23;
    };
}se_se_drf_0_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  se_drf_1_fail_0:1;
        RBus_UInt32  se_drf_1_fail_1:1;
        RBus_UInt32  res1:30;
    };
}se_se_drf_1_fail_RBUS;




#endif 


#endif 
