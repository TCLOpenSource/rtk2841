/**
* @file Mac5-DesignSpec-MC_secure_register
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MC_SECURE_REG_H_
#define _RBUS_MC_SECURE_REG_H_

#include "rbus_types.h"



//  MC_SECURE Register Address
#define  MC_SECURE_MC_global_scramble_ctrl                                       0x180B0000
#define  MC_SECURE_MC_global_scramble_ctrl_reg_addr                              "0xB80B0000"
#define  MC_SECURE_MC_global_scramble_ctrl_reg                                   0xB80B0000
#define  MC_SECURE_MC_global_scramble_ctrl_inst_addr                             "0x0000"
#define  set_MC_SECURE_MC_global_scramble_ctrl_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_global_scramble_ctrl_reg)=data)
#define  get_MC_SECURE_MC_global_scramble_ctrl_reg                               (*((volatile unsigned int*)MC_SECURE_MC_global_scramble_ctrl_reg))
#define  MC_SECURE_MC_global_scramble_ctrl_global_scramble_en_shift              (0)
#define  MC_SECURE_MC_global_scramble_ctrl_global_scramble_en_mask               (0x00000001)
#define  MC_SECURE_MC_global_scramble_ctrl_global_scramble_en(data)              (0x00000001&(data))
#define  MC_SECURE_MC_global_scramble_ctrl_get_global_scramble_en(data)          (0x00000001&(data))

#define  MC_SECURE_MC_mem_scramble_global_0                                      0x180B0010
#define  MC_SECURE_MC_mem_scramble_global_0_reg_addr                             "0xB80B0010"
#define  MC_SECURE_MC_mem_scramble_global_0_reg                                  0xB80B0010
#define  MC_SECURE_MC_mem_scramble_global_0_inst_addr                            "0x0001"
#define  set_MC_SECURE_MC_mem_scramble_global_0_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_0_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_0_reg))
#define  MC_SECURE_MC_mem_scramble_global_0_key1_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_0_key0_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_0_key1_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_0_key0_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_0_key1(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_0_key0(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_0_get_key1(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_0_get_key0(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_global_1                                      0x180B0014
#define  MC_SECURE_MC_mem_scramble_global_1_reg_addr                             "0xB80B0014"
#define  MC_SECURE_MC_mem_scramble_global_1_reg                                  0xB80B0014
#define  MC_SECURE_MC_mem_scramble_global_1_inst_addr                            "0x0002"
#define  set_MC_SECURE_MC_mem_scramble_global_1_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_1_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_1_reg))
#define  MC_SECURE_MC_mem_scramble_global_1_key3_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_1_key2_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_1_key3_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_1_key2_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_1_key3(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_1_key2(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_1_get_key3(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_1_get_key2(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_global_2                                      0x180B0018
#define  MC_SECURE_MC_mem_scramble_global_2_reg_addr                             "0xB80B0018"
#define  MC_SECURE_MC_mem_scramble_global_2_reg                                  0xB80B0018
#define  MC_SECURE_MC_mem_scramble_global_2_inst_addr                            "0x0003"
#define  set_MC_SECURE_MC_mem_scramble_global_2_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_2_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_2_reg))
#define  MC_SECURE_MC_mem_scramble_global_2_key5_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_2_key4_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_2_key5_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_2_key4_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_2_key5(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_2_key4(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_2_get_key5(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_2_get_key4(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_global_3                                      0x180B001C
#define  MC_SECURE_MC_mem_scramble_global_3_reg_addr                             "0xB80B001C"
#define  MC_SECURE_MC_mem_scramble_global_3_reg                                  0xB80B001C
#define  MC_SECURE_MC_mem_scramble_global_3_inst_addr                            "0x0004"
#define  set_MC_SECURE_MC_mem_scramble_global_3_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_3_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_3_reg))
#define  MC_SECURE_MC_mem_scramble_global_3_key7_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_3_key6_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_3_key7_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_3_key6_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_3_key7(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_3_key6(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_3_get_key7(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_3_get_key6(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_global_4                                      0x180B0020
#define  MC_SECURE_MC_mem_scramble_global_4_reg_addr                             "0xB80B0020"
#define  MC_SECURE_MC_mem_scramble_global_4_reg                                  0xB80B0020
#define  MC_SECURE_MC_mem_scramble_global_4_inst_addr                            "0x0005"
#define  set_MC_SECURE_MC_mem_scramble_global_4_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_4_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_4_reg))
#define  MC_SECURE_MC_mem_scramble_global_4_key9_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_4_key8_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_4_key9_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_4_key8_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_4_key9(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_4_key8(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_4_get_key9(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_4_get_key8(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_global_5                                      0x180B0024
#define  MC_SECURE_MC_mem_scramble_global_5_reg_addr                             "0xB80B0024"
#define  MC_SECURE_MC_mem_scramble_global_5_reg                                  0xB80B0024
#define  MC_SECURE_MC_mem_scramble_global_5_inst_addr                            "0x0006"
#define  set_MC_SECURE_MC_mem_scramble_global_5_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_5_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_5_reg))
#define  MC_SECURE_MC_mem_scramble_global_5_keyb_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_5_keya_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_5_keyb_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_5_keya_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_5_keyb(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_5_keya(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_5_get_keyb(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_5_get_keya(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_global_6                                      0x180B0028
#define  MC_SECURE_MC_mem_scramble_global_6_reg_addr                             "0xB80B0028"
#define  MC_SECURE_MC_mem_scramble_global_6_reg                                  0xB80B0028
#define  MC_SECURE_MC_mem_scramble_global_6_inst_addr                            "0x0007"
#define  set_MC_SECURE_MC_mem_scramble_global_6_reg(data)                        (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_global_6_reg                              (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_global_6_reg))
#define  MC_SECURE_MC_mem_scramble_global_6_keyd_shift                           (16)
#define  MC_SECURE_MC_mem_scramble_global_6_keyc_shift                           (0)
#define  MC_SECURE_MC_mem_scramble_global_6_keyd_mask                            (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_global_6_keyc_mask                            (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_global_6_keyd(data)                           (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_global_6_keyc(data)                           (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_global_6_get_keyd(data)                       ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_global_6_get_keyc(data)                       (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_protect_ctrl                                           0x180B0030
#define  MC_SECURE_MC_mem_protect_ctrl_reg_addr                                  "0xB80B0030"
#define  MC_SECURE_MC_mem_protect_ctrl_reg                                       0xB80B0030
#define  MC_SECURE_MC_mem_protect_ctrl_inst_addr                                 "0x0008"
#define  set_MC_SECURE_MC_mem_protect_ctrl_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_ctrl_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_ctrl_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_ctrl_reg))
#define  MC_SECURE_MC_mem_protect_ctrl_protect_3_en_shift                        (19)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_2_en_shift                        (18)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_1_en_shift                        (17)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_0_en_shift                        (16)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_3_en_mask                         (0x00080000)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_2_en_mask                         (0x00040000)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_1_en_mask                         (0x00020000)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_0_en_mask                         (0x00010000)
#define  MC_SECURE_MC_mem_protect_ctrl_protect_3_en(data)                        (0x00080000&((data)<<19))
#define  MC_SECURE_MC_mem_protect_ctrl_protect_2_en(data)                        (0x00040000&((data)<<18))
#define  MC_SECURE_MC_mem_protect_ctrl_protect_1_en(data)                        (0x00020000&((data)<<17))
#define  MC_SECURE_MC_mem_protect_ctrl_protect_0_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_mem_protect_ctrl_get_protect_3_en(data)                    ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_mem_protect_ctrl_get_protect_2_en(data)                    ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_mem_protect_ctrl_get_protect_1_en(data)                    ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_mem_protect_ctrl_get_protect_0_en(data)                    ((0x00010000&(data))>>16)

#define  MC_SECURE_MC_secure_max                                                 0x180B0034
#define  MC_SECURE_MC_secure_max_reg_addr                                        "0xB80B0034"
#define  MC_SECURE_MC_secure_max_reg                                             0xB80B0034
#define  MC_SECURE_MC_secure_max_inst_addr                                       "0x0009"
#define  set_MC_SECURE_MC_secure_max_reg(data)                                   (*((volatile unsigned int*)MC_SECURE_MC_secure_max_reg)=data)
#define  get_MC_SECURE_MC_secure_max_reg                                         (*((volatile unsigned int*)MC_SECURE_MC_secure_max_reg))
#define  MC_SECURE_MC_secure_max_addr_shift                                      (12)
#define  MC_SECURE_MC_secure_max_addr_mask                                       (0xFFFFF000)
#define  MC_SECURE_MC_secure_max_addr(data)                                      (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_secure_max_get_addr(data)                                  ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_start_0                                        0x180B0040
#define  MC_SECURE_MC_mem_protect_start_0_reg_addr                               "0xB80B0040"
#define  MC_SECURE_MC_mem_protect_start_0_reg                                    0xB80B0040
#define  MC_SECURE_MC_mem_protect_start_0_inst_addr                              "0x000A"
#define  set_MC_SECURE_MC_mem_protect_start_0_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_0_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_start_0_reg                                (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_0_reg))
#define  MC_SECURE_MC_mem_protect_start_0_addr_shift                             (12)
#define  MC_SECURE_MC_mem_protect_start_0_addr_mask                              (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_start_0_addr(data)                             (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_start_0_get_addr(data)                         ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_start_1                                        0x180B0044
#define  MC_SECURE_MC_mem_protect_start_1_reg_addr                               "0xB80B0044"
#define  MC_SECURE_MC_mem_protect_start_1_reg                                    0xB80B0044
#define  MC_SECURE_MC_mem_protect_start_1_inst_addr                              "0x000B"
#define  set_MC_SECURE_MC_mem_protect_start_1_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_1_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_start_1_reg                                (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_1_reg))
#define  MC_SECURE_MC_mem_protect_start_1_addr_shift                             (12)
#define  MC_SECURE_MC_mem_protect_start_1_addr_mask                              (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_start_1_addr(data)                             (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_start_1_get_addr(data)                         ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_start_2                                        0x180B0048
#define  MC_SECURE_MC_mem_protect_start_2_reg_addr                               "0xB80B0048"
#define  MC_SECURE_MC_mem_protect_start_2_reg                                    0xB80B0048
#define  MC_SECURE_MC_mem_protect_start_2_inst_addr                              "0x000C"
#define  set_MC_SECURE_MC_mem_protect_start_2_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_2_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_start_2_reg                                (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_2_reg))
#define  MC_SECURE_MC_mem_protect_start_2_addr_shift                             (12)
#define  MC_SECURE_MC_mem_protect_start_2_addr_mask                              (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_start_2_addr(data)                             (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_start_2_get_addr(data)                         ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_start_3                                        0x180B004C
#define  MC_SECURE_MC_mem_protect_start_3_reg_addr                               "0xB80B004C"
#define  MC_SECURE_MC_mem_protect_start_3_reg                                    0xB80B004C
#define  MC_SECURE_MC_mem_protect_start_3_inst_addr                              "0x000D"
#define  set_MC_SECURE_MC_mem_protect_start_3_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_3_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_start_3_reg                                (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_start_3_reg))
#define  MC_SECURE_MC_mem_protect_start_3_addr_shift                             (12)
#define  MC_SECURE_MC_mem_protect_start_3_addr_mask                              (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_start_3_addr(data)                             (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_start_3_get_addr(data)                         ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_end_0                                          0x180B0050
#define  MC_SECURE_MC_mem_protect_end_0_reg_addr                                 "0xB80B0050"
#define  MC_SECURE_MC_mem_protect_end_0_reg                                      0xB80B0050
#define  MC_SECURE_MC_mem_protect_end_0_inst_addr                                "0x000E"
#define  set_MC_SECURE_MC_mem_protect_end_0_reg(data)                            (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_0_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_end_0_reg                                  (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_0_reg))
#define  MC_SECURE_MC_mem_protect_end_0_addr_shift                               (12)
#define  MC_SECURE_MC_mem_protect_end_0_addr_mask                                (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_end_0_addr(data)                               (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_end_0_get_addr(data)                           ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_end_1                                          0x180B0054
#define  MC_SECURE_MC_mem_protect_end_1_reg_addr                                 "0xB80B0054"
#define  MC_SECURE_MC_mem_protect_end_1_reg                                      0xB80B0054
#define  MC_SECURE_MC_mem_protect_end_1_inst_addr                                "0x000F"
#define  set_MC_SECURE_MC_mem_protect_end_1_reg(data)                            (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_1_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_end_1_reg                                  (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_1_reg))
#define  MC_SECURE_MC_mem_protect_end_1_addr_shift                               (12)
#define  MC_SECURE_MC_mem_protect_end_1_addr_mask                                (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_end_1_addr(data)                               (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_end_1_get_addr(data)                           ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_end_2                                          0x180B0058
#define  MC_SECURE_MC_mem_protect_end_2_reg_addr                                 "0xB80B0058"
#define  MC_SECURE_MC_mem_protect_end_2_reg                                      0xB80B0058
#define  MC_SECURE_MC_mem_protect_end_2_inst_addr                                "0x0010"
#define  set_MC_SECURE_MC_mem_protect_end_2_reg(data)                            (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_2_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_end_2_reg                                  (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_2_reg))
#define  MC_SECURE_MC_mem_protect_end_2_addr_shift                               (12)
#define  MC_SECURE_MC_mem_protect_end_2_addr_mask                                (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_end_2_addr(data)                               (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_end_2_get_addr(data)                           ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_end_3                                          0x180B005C
#define  MC_SECURE_MC_mem_protect_end_3_reg_addr                                 "0xB80B005C"
#define  MC_SECURE_MC_mem_protect_end_3_reg                                      0xB80B005C
#define  MC_SECURE_MC_mem_protect_end_3_inst_addr                                "0x0011"
#define  set_MC_SECURE_MC_mem_protect_end_3_reg(data)                            (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_3_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_end_3_reg                                  (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_end_3_reg))
#define  MC_SECURE_MC_mem_protect_end_3_addr_shift                               (12)
#define  MC_SECURE_MC_mem_protect_end_3_addr_mask                                (0xFFFFF000)
#define  MC_SECURE_MC_mem_protect_end_3_addr(data)                               (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_protect_end_3_get_addr(data)                           ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_protect_access_r_0                                     0x180B0060
#define  MC_SECURE_MC_mem_protect_access_r_0_reg_addr                            "0xB80B0060"
#define  MC_SECURE_MC_mem_protect_access_r_0_reg                                 0xB80B0060
#define  MC_SECURE_MC_mem_protect_access_r_0_inst_addr                           "0x0012"
#define  set_MC_SECURE_MC_mem_protect_access_r_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_0_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_r_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_0_reg))
#define  MC_SECURE_MC_mem_protect_access_r_0_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_r_0_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_r_0_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_r_0_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_r_0_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_r_0_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_r_0_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_r_0_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_r_0_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_r_0_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_r_0_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_r_0_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_r_0_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_r_0_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_r_0_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_r_0_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_r_0_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_r_0_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_r_0_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_r_0_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_r_1                                     0x180B0064
#define  MC_SECURE_MC_mem_protect_access_r_1_reg_addr                            "0xB80B0064"
#define  MC_SECURE_MC_mem_protect_access_r_1_reg                                 0xB80B0064
#define  MC_SECURE_MC_mem_protect_access_r_1_inst_addr                           "0x0013"
#define  set_MC_SECURE_MC_mem_protect_access_r_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_1_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_r_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_1_reg))
#define  MC_SECURE_MC_mem_protect_access_r_1_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_r_1_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_r_1_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_r_1_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_r_1_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_r_1_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_r_1_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_r_1_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_r_1_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_r_1_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_r_1_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_r_1_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_r_1_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_r_1_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_r_1_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_r_1_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_r_1_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_r_1_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_r_1_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_r_1_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_r_2                                     0x180B0068
#define  MC_SECURE_MC_mem_protect_access_r_2_reg_addr                            "0xB80B0068"
#define  MC_SECURE_MC_mem_protect_access_r_2_reg                                 0xB80B0068
#define  MC_SECURE_MC_mem_protect_access_r_2_inst_addr                           "0x0014"
#define  set_MC_SECURE_MC_mem_protect_access_r_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_2_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_r_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_2_reg))
#define  MC_SECURE_MC_mem_protect_access_r_2_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_r_2_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_r_2_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_r_2_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_r_2_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_r_2_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_r_2_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_r_2_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_r_2_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_r_2_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_r_2_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_r_2_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_r_2_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_r_2_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_r_2_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_r_2_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_r_2_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_r_2_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_r_2_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_r_2_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_r_3                                     0x180B006C
#define  MC_SECURE_MC_mem_protect_access_r_3_reg_addr                            "0xB80B006C"
#define  MC_SECURE_MC_mem_protect_access_r_3_reg                                 0xB80B006C
#define  MC_SECURE_MC_mem_protect_access_r_3_inst_addr                           "0x0015"
#define  set_MC_SECURE_MC_mem_protect_access_r_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_3_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_r_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_r_3_reg))
#define  MC_SECURE_MC_mem_protect_access_r_3_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_r_3_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_r_3_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_r_3_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_r_3_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_r_3_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_r_3_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_r_3_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_r_3_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_r_3_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_r_3_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_r_3_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_r_3_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_r_3_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_r_3_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_r_3_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_r_3_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_r_3_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_r_3_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_r_3_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_w_0                                     0x180B0070
#define  MC_SECURE_MC_mem_protect_access_w_0_reg_addr                            "0xB80B0070"
#define  MC_SECURE_MC_mem_protect_access_w_0_reg                                 0xB80B0070
#define  MC_SECURE_MC_mem_protect_access_w_0_inst_addr                           "0x0016"
#define  set_MC_SECURE_MC_mem_protect_access_w_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_0_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_w_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_0_reg))
#define  MC_SECURE_MC_mem_protect_access_w_0_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_w_0_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_w_0_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_w_0_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_w_0_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_w_0_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_w_0_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_w_0_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_w_0_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_w_0_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_w_0_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_w_0_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_w_0_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_w_0_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_w_0_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_w_0_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_w_0_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_w_0_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_w_0_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_w_0_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_w_1                                     0x180B0074
#define  MC_SECURE_MC_mem_protect_access_w_1_reg_addr                            "0xB80B0074"
#define  MC_SECURE_MC_mem_protect_access_w_1_reg                                 0xB80B0074
#define  MC_SECURE_MC_mem_protect_access_w_1_inst_addr                           "0x0017"
#define  set_MC_SECURE_MC_mem_protect_access_w_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_1_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_w_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_1_reg))
#define  MC_SECURE_MC_mem_protect_access_w_1_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_w_1_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_w_1_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_w_1_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_w_1_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_w_1_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_w_1_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_w_1_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_w_1_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_w_1_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_w_1_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_w_1_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_w_1_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_w_1_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_w_1_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_w_1_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_w_1_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_w_1_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_w_1_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_w_1_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_w_2                                     0x180B0078
#define  MC_SECURE_MC_mem_protect_access_w_2_reg_addr                            "0xB80B0078"
#define  MC_SECURE_MC_mem_protect_access_w_2_reg                                 0xB80B0078
#define  MC_SECURE_MC_mem_protect_access_w_2_inst_addr                           "0x0018"
#define  set_MC_SECURE_MC_mem_protect_access_w_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_2_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_w_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_2_reg))
#define  MC_SECURE_MC_mem_protect_access_w_2_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_w_2_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_w_2_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_w_2_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_w_2_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_w_2_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_w_2_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_w_2_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_w_2_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_w_2_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_w_2_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_w_2_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_w_2_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_w_2_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_w_2_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_w_2_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_w_2_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_w_2_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_w_2_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_w_2_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_protect_access_w_3                                     0x180B007C
#define  MC_SECURE_MC_mem_protect_access_w_3_reg_addr                            "0xB80B007C"
#define  MC_SECURE_MC_mem_protect_access_w_3_reg                                 0xB80B007C
#define  MC_SECURE_MC_mem_protect_access_w_3_inst_addr                           "0x0019"
#define  set_MC_SECURE_MC_mem_protect_access_w_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_3_reg)=data)
#define  get_MC_SECURE_MC_mem_protect_access_w_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_protect_access_w_3_reg))
#define  MC_SECURE_MC_mem_protect_access_w_3_tp_kc_shift                         (4)
#define  MC_SECURE_MC_mem_protect_access_w_3_emmc_kc_shift                       (3)
#define  MC_SECURE_MC_mem_protect_access_w_3_nf_kc_shift                         (2)
#define  MC_SECURE_MC_mem_protect_access_w_3_cp_kc_shift                         (1)
#define  MC_SECURE_MC_mem_protect_access_w_3_md_kc_shift                         (0)
#define  MC_SECURE_MC_mem_protect_access_w_3_tp_kc_mask                          (0x00000010)
#define  MC_SECURE_MC_mem_protect_access_w_3_emmc_kc_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_protect_access_w_3_nf_kc_mask                          (0x00000004)
#define  MC_SECURE_MC_mem_protect_access_w_3_cp_kc_mask                          (0x00000002)
#define  MC_SECURE_MC_mem_protect_access_w_3_md_kc_mask                          (0x00000001)
#define  MC_SECURE_MC_mem_protect_access_w_3_tp_kc(data)                         (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_protect_access_w_3_emmc_kc(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_protect_access_w_3_nf_kc(data)                         (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_protect_access_w_3_cp_kc(data)                         (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_protect_access_w_3_md_kc(data)                         (0x00000001&(data))
#define  MC_SECURE_MC_mem_protect_access_w_3_get_tp_kc(data)                     ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_protect_access_w_3_get_emmc_kc(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_protect_access_w_3_get_nf_kc(data)                     ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_protect_access_w_3_get_cp_kc(data)                     ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_protect_access_w_3_get_md_kc(data)                     (0x00000001&(data))

#define  MC_SECURE_MC_mem_content_ctrl                                           0x180B0080
#define  MC_SECURE_MC_mem_content_ctrl_reg_addr                                  "0xB80B0080"
#define  MC_SECURE_MC_mem_content_ctrl_reg                                       0xB80B0080
#define  MC_SECURE_MC_mem_content_ctrl_inst_addr                                 "0x001A"
#define  set_MC_SECURE_MC_mem_content_ctrl_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_mem_content_ctrl_reg)=data)
#define  get_MC_SECURE_MC_mem_content_ctrl_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_mem_content_ctrl_reg))
#define  MC_SECURE_MC_mem_content_ctrl_content_7_en_shift                        (23)
#define  MC_SECURE_MC_mem_content_ctrl_content_6_en_shift                        (22)
#define  MC_SECURE_MC_mem_content_ctrl_content_5_en_shift                        (21)
#define  MC_SECURE_MC_mem_content_ctrl_content_4_en_shift                        (20)
#define  MC_SECURE_MC_mem_content_ctrl_content_3_en_shift                        (19)
#define  MC_SECURE_MC_mem_content_ctrl_content_2_en_shift                        (18)
#define  MC_SECURE_MC_mem_content_ctrl_content_1_en_shift                        (17)
#define  MC_SECURE_MC_mem_content_ctrl_content_0_en_shift                        (16)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_7_en_shift                       (7)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_6_en_shift                       (6)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_5_en_shift                       (5)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_4_en_shift                       (4)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_3_en_shift                       (3)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_2_en_shift                       (2)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_1_en_shift                       (1)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_0_en_shift                       (0)
#define  MC_SECURE_MC_mem_content_ctrl_content_7_en_mask                         (0x00800000)
#define  MC_SECURE_MC_mem_content_ctrl_content_6_en_mask                         (0x00400000)
#define  MC_SECURE_MC_mem_content_ctrl_content_5_en_mask                         (0x00200000)
#define  MC_SECURE_MC_mem_content_ctrl_content_4_en_mask                         (0x00100000)
#define  MC_SECURE_MC_mem_content_ctrl_content_3_en_mask                         (0x00080000)
#define  MC_SECURE_MC_mem_content_ctrl_content_2_en_mask                         (0x00040000)
#define  MC_SECURE_MC_mem_content_ctrl_content_1_en_mask                         (0x00020000)
#define  MC_SECURE_MC_mem_content_ctrl_content_0_en_mask                         (0x00010000)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_7_en_mask                        (0x00000080)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_6_en_mask                        (0x00000040)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_5_en_mask                        (0x00000020)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_4_en_mask                        (0x00000010)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_3_en_mask                        (0x00000008)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_2_en_mask                        (0x00000004)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_1_en_mask                        (0x00000002)
#define  MC_SECURE_MC_mem_content_ctrl_scramble_0_en_mask                        (0x00000001)
#define  MC_SECURE_MC_mem_content_ctrl_content_7_en(data)                        (0x00800000&((data)<<23))
#define  MC_SECURE_MC_mem_content_ctrl_content_6_en(data)                        (0x00400000&((data)<<22))
#define  MC_SECURE_MC_mem_content_ctrl_content_5_en(data)                        (0x00200000&((data)<<21))
#define  MC_SECURE_MC_mem_content_ctrl_content_4_en(data)                        (0x00100000&((data)<<20))
#define  MC_SECURE_MC_mem_content_ctrl_content_3_en(data)                        (0x00080000&((data)<<19))
#define  MC_SECURE_MC_mem_content_ctrl_content_2_en(data)                        (0x00040000&((data)<<18))
#define  MC_SECURE_MC_mem_content_ctrl_content_1_en(data)                        (0x00020000&((data)<<17))
#define  MC_SECURE_MC_mem_content_ctrl_content_0_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_7_en(data)                       (0x00000080&((data)<<7))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_6_en(data)                       (0x00000040&((data)<<6))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_5_en(data)                       (0x00000020&((data)<<5))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_4_en(data)                       (0x00000010&((data)<<4))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_3_en(data)                       (0x00000008&((data)<<3))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_2_en(data)                       (0x00000004&((data)<<2))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_1_en(data)                       (0x00000002&((data)<<1))
#define  MC_SECURE_MC_mem_content_ctrl_scramble_0_en(data)                       (0x00000001&(data))
#define  MC_SECURE_MC_mem_content_ctrl_get_content_7_en(data)                    ((0x00800000&(data))>>23)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_6_en(data)                    ((0x00400000&(data))>>22)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_5_en(data)                    ((0x00200000&(data))>>21)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_4_en(data)                    ((0x00100000&(data))>>20)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_3_en(data)                    ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_2_en(data)                    ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_1_en(data)                    ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_mem_content_ctrl_get_content_0_en(data)                    ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_7_en(data)                   ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_6_en(data)                   ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_5_en(data)                   ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_4_en(data)                   ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_3_en(data)                   ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_2_en(data)                   ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_1_en(data)                   ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_mem_content_ctrl_get_scramble_0_en(data)                   (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_0                                        0x180B0090
#define  MC_SECURE_MC_scramble_access_r_0_reg_addr                               "0xB80B0090"
#define  MC_SECURE_MC_scramble_access_r_0_reg                                    0xB80B0090
#define  MC_SECURE_MC_scramble_access_r_0_inst_addr                              "0x001B"
#define  set_MC_SECURE_MC_scramble_access_r_0_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_0_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_0_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_0_reg))
#define  MC_SECURE_MC_scramble_access_r_0_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_0_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_0_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_0_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_0_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_0_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_0_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_0_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_0_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_0_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_0_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_0_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_0_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_0_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_0_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_0_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_0_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_0_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_0_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_0_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_0_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_0_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_0_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_0_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_0_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_0_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_0_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_0_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_0_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_0_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_0_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_0_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_0_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_0_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_0_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_0_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_0_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_0_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_0_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_0_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_0_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_0_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_0_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_0_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_0_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_0_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_0_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_0_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_1                                        0x180B0094
#define  MC_SECURE_MC_scramble_access_r_1_reg_addr                               "0xB80B0094"
#define  MC_SECURE_MC_scramble_access_r_1_reg                                    0xB80B0094
#define  MC_SECURE_MC_scramble_access_r_1_inst_addr                              "0x001C"
#define  set_MC_SECURE_MC_scramble_access_r_1_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_1_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_1_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_1_reg))
#define  MC_SECURE_MC_scramble_access_r_1_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_1_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_1_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_1_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_1_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_1_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_1_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_1_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_1_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_1_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_1_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_1_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_1_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_1_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_1_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_1_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_1_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_1_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_1_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_1_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_1_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_1_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_1_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_1_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_1_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_1_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_1_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_1_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_1_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_1_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_1_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_1_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_1_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_1_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_1_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_1_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_1_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_1_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_1_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_1_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_1_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_1_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_1_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_1_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_1_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_1_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_1_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_1_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_2                                        0x180B0098
#define  MC_SECURE_MC_scramble_access_r_2_reg_addr                               "0xB80B0098"
#define  MC_SECURE_MC_scramble_access_r_2_reg                                    0xB80B0098
#define  MC_SECURE_MC_scramble_access_r_2_inst_addr                              "0x001D"
#define  set_MC_SECURE_MC_scramble_access_r_2_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_2_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_2_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_2_reg))
#define  MC_SECURE_MC_scramble_access_r_2_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_2_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_2_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_2_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_2_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_2_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_2_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_2_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_2_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_2_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_2_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_2_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_2_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_2_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_2_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_2_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_2_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_2_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_2_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_2_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_2_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_2_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_2_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_2_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_2_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_2_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_2_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_2_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_2_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_2_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_2_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_2_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_2_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_2_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_2_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_2_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_2_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_2_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_2_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_2_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_2_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_2_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_2_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_2_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_2_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_2_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_2_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_2_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_3                                        0x180B009C
#define  MC_SECURE_MC_scramble_access_r_3_reg_addr                               "0xB80B009C"
#define  MC_SECURE_MC_scramble_access_r_3_reg                                    0xB80B009C
#define  MC_SECURE_MC_scramble_access_r_3_inst_addr                              "0x001E"
#define  set_MC_SECURE_MC_scramble_access_r_3_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_3_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_3_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_3_reg))
#define  MC_SECURE_MC_scramble_access_r_3_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_3_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_3_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_3_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_3_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_3_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_3_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_3_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_3_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_3_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_3_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_3_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_3_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_3_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_3_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_3_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_3_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_3_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_3_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_3_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_3_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_3_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_3_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_3_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_3_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_3_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_3_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_3_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_3_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_3_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_3_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_3_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_3_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_3_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_3_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_3_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_3_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_3_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_3_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_3_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_3_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_3_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_3_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_3_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_3_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_3_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_3_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_3_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_4                                        0x180B00A0
#define  MC_SECURE_MC_scramble_access_r_4_reg_addr                               "0xB80B00A0"
#define  MC_SECURE_MC_scramble_access_r_4_reg                                    0xB80B00A0
#define  MC_SECURE_MC_scramble_access_r_4_inst_addr                              "0x001F"
#define  set_MC_SECURE_MC_scramble_access_r_4_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_4_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_4_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_4_reg))
#define  MC_SECURE_MC_scramble_access_r_4_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_4_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_4_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_4_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_4_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_4_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_4_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_4_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_4_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_4_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_4_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_4_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_4_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_4_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_4_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_4_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_4_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_4_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_4_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_4_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_4_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_4_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_4_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_4_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_4_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_4_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_4_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_4_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_4_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_4_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_4_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_4_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_4_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_4_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_4_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_4_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_4_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_4_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_4_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_4_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_4_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_4_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_4_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_4_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_4_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_4_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_4_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_4_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_5                                        0x180B00A4
#define  MC_SECURE_MC_scramble_access_r_5_reg_addr                               "0xB80B00A4"
#define  MC_SECURE_MC_scramble_access_r_5_reg                                    0xB80B00A4
#define  MC_SECURE_MC_scramble_access_r_5_inst_addr                              "0x0020"
#define  set_MC_SECURE_MC_scramble_access_r_5_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_5_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_5_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_5_reg))
#define  MC_SECURE_MC_scramble_access_r_5_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_5_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_5_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_5_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_5_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_5_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_5_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_5_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_5_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_5_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_5_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_5_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_5_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_5_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_5_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_5_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_5_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_5_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_5_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_5_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_5_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_5_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_5_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_5_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_5_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_5_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_5_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_5_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_5_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_5_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_5_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_5_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_5_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_5_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_5_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_5_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_5_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_5_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_5_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_5_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_5_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_5_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_5_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_5_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_5_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_5_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_5_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_5_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_6                                        0x180B00A8
#define  MC_SECURE_MC_scramble_access_r_6_reg_addr                               "0xB80B00A8"
#define  MC_SECURE_MC_scramble_access_r_6_reg                                    0xB80B00A8
#define  MC_SECURE_MC_scramble_access_r_6_inst_addr                              "0x0021"
#define  set_MC_SECURE_MC_scramble_access_r_6_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_6_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_6_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_6_reg))
#define  MC_SECURE_MC_scramble_access_r_6_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_6_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_6_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_6_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_6_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_6_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_6_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_6_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_6_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_6_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_6_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_6_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_6_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_6_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_6_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_6_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_6_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_6_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_6_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_6_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_6_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_6_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_6_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_6_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_6_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_6_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_6_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_6_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_6_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_6_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_6_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_6_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_6_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_6_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_6_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_6_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_6_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_6_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_6_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_6_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_6_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_6_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_6_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_6_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_6_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_6_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_6_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_6_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_r_7                                        0x180B00AC
#define  MC_SECURE_MC_scramble_access_r_7_reg_addr                               "0xB80B00AC"
#define  MC_SECURE_MC_scramble_access_r_7_reg                                    0xB80B00AC
#define  MC_SECURE_MC_scramble_access_r_7_inst_addr                              "0x0022"
#define  set_MC_SECURE_MC_scramble_access_r_7_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_7_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_r_7_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_r_7_reg))
#define  MC_SECURE_MC_scramble_access_r_7_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_r_7_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_r_7_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_r_7_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_r_7_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_r_7_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_r_7_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_r_7_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_r_7_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_r_7_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_r_7_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_r_7_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_r_7_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_r_7_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_r_7_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_r_7_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_r_7_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_r_7_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_r_7_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_r_7_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_r_7_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_r_7_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_r_7_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_r_7_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_r_7_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_r_7_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_r_7_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_r_7_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_r_7_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_r_7_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_r_7_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_r_7_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_r_7_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_r_7_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_r_7_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_r_7_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_r_7_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_r_7_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_r_7_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_r_7_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_r_7_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_r_7_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_r_7_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_r_7_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_r_7_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_r_7_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_r_7_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_r_7_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_0                                        0x180B00B0
#define  MC_SECURE_MC_scramble_access_w_0_reg_addr                               "0xB80B00B0"
#define  MC_SECURE_MC_scramble_access_w_0_reg                                    0xB80B00B0
#define  MC_SECURE_MC_scramble_access_w_0_inst_addr                              "0x0023"
#define  set_MC_SECURE_MC_scramble_access_w_0_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_0_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_0_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_0_reg))
#define  MC_SECURE_MC_scramble_access_w_0_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_0_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_0_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_0_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_0_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_0_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_0_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_0_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_0_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_0_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_0_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_0_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_0_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_0_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_0_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_0_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_0_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_0_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_0_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_0_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_0_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_0_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_0_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_0_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_0_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_0_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_0_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_0_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_0_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_0_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_0_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_0_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_0_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_0_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_0_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_0_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_0_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_0_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_0_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_0_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_0_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_0_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_0_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_0_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_0_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_0_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_0_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_0_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_1                                        0x180B00B4
#define  MC_SECURE_MC_scramble_access_w_1_reg_addr                               "0xB80B00B4"
#define  MC_SECURE_MC_scramble_access_w_1_reg                                    0xB80B00B4
#define  MC_SECURE_MC_scramble_access_w_1_inst_addr                              "0x0024"
#define  set_MC_SECURE_MC_scramble_access_w_1_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_1_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_1_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_1_reg))
#define  MC_SECURE_MC_scramble_access_w_1_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_1_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_1_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_1_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_1_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_1_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_1_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_1_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_1_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_1_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_1_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_1_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_1_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_1_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_1_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_1_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_1_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_1_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_1_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_1_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_1_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_1_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_1_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_1_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_1_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_1_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_1_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_1_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_1_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_1_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_1_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_1_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_1_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_1_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_1_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_1_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_1_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_1_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_1_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_1_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_1_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_1_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_1_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_1_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_1_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_1_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_1_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_1_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_2                                        0x180B00B8
#define  MC_SECURE_MC_scramble_access_w_2_reg_addr                               "0xB80B00B8"
#define  MC_SECURE_MC_scramble_access_w_2_reg                                    0xB80B00B8
#define  MC_SECURE_MC_scramble_access_w_2_inst_addr                              "0x0025"
#define  set_MC_SECURE_MC_scramble_access_w_2_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_2_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_2_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_2_reg))
#define  MC_SECURE_MC_scramble_access_w_2_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_2_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_2_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_2_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_2_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_2_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_2_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_2_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_2_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_2_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_2_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_2_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_2_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_2_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_2_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_2_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_2_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_2_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_2_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_2_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_2_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_2_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_2_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_2_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_2_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_2_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_2_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_2_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_2_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_2_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_2_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_2_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_2_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_2_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_2_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_2_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_2_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_2_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_2_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_2_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_2_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_2_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_2_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_2_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_2_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_2_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_2_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_2_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_3                                        0x180B00BC
#define  MC_SECURE_MC_scramble_access_w_3_reg_addr                               "0xB80B00BC"
#define  MC_SECURE_MC_scramble_access_w_3_reg                                    0xB80B00BC
#define  MC_SECURE_MC_scramble_access_w_3_inst_addr                              "0x0026"
#define  set_MC_SECURE_MC_scramble_access_w_3_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_3_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_3_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_3_reg))
#define  MC_SECURE_MC_scramble_access_w_3_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_3_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_3_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_3_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_3_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_3_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_3_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_3_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_3_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_3_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_3_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_3_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_3_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_3_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_3_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_3_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_3_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_3_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_3_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_3_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_3_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_3_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_3_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_3_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_3_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_3_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_3_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_3_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_3_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_3_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_3_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_3_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_3_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_3_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_3_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_3_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_3_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_3_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_3_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_3_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_3_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_3_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_3_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_3_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_3_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_3_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_3_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_3_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_4                                        0x180B00C0
#define  MC_SECURE_MC_scramble_access_w_4_reg_addr                               "0xB80B00C0"
#define  MC_SECURE_MC_scramble_access_w_4_reg                                    0xB80B00C0
#define  MC_SECURE_MC_scramble_access_w_4_inst_addr                              "0x0027"
#define  set_MC_SECURE_MC_scramble_access_w_4_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_4_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_4_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_4_reg))
#define  MC_SECURE_MC_scramble_access_w_4_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_4_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_4_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_4_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_4_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_4_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_4_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_4_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_4_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_4_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_4_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_4_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_4_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_4_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_4_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_4_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_4_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_4_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_4_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_4_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_4_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_4_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_4_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_4_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_4_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_4_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_4_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_4_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_4_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_4_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_4_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_4_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_4_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_4_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_4_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_4_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_4_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_4_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_4_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_4_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_4_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_4_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_4_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_4_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_4_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_4_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_4_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_4_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_5                                        0x180B00C4
#define  MC_SECURE_MC_scramble_access_w_5_reg_addr                               "0xB80B00C4"
#define  MC_SECURE_MC_scramble_access_w_5_reg                                    0xB80B00C4
#define  MC_SECURE_MC_scramble_access_w_5_inst_addr                              "0x0028"
#define  set_MC_SECURE_MC_scramble_access_w_5_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_5_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_5_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_5_reg))
#define  MC_SECURE_MC_scramble_access_w_5_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_5_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_5_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_5_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_5_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_5_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_5_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_5_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_5_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_5_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_5_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_5_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_5_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_5_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_5_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_5_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_5_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_5_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_5_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_5_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_5_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_5_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_5_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_5_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_5_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_5_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_5_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_5_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_5_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_5_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_5_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_5_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_5_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_5_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_5_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_5_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_5_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_5_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_5_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_5_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_5_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_5_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_5_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_5_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_5_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_5_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_5_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_5_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_6                                        0x180B00C8
#define  MC_SECURE_MC_scramble_access_w_6_reg_addr                               "0xB80B00C8"
#define  MC_SECURE_MC_scramble_access_w_6_reg                                    0xB80B00C8
#define  MC_SECURE_MC_scramble_access_w_6_inst_addr                              "0x0029"
#define  set_MC_SECURE_MC_scramble_access_w_6_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_6_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_6_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_6_reg))
#define  MC_SECURE_MC_scramble_access_w_6_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_6_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_6_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_6_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_6_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_6_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_6_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_6_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_6_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_6_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_6_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_6_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_6_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_6_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_6_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_6_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_6_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_6_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_6_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_6_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_6_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_6_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_6_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_6_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_6_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_6_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_6_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_6_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_6_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_6_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_6_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_6_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_6_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_6_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_6_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_6_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_6_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_6_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_6_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_6_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_6_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_6_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_6_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_6_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_6_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_6_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_6_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_6_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_scramble_access_w_7                                        0x180B00CC
#define  MC_SECURE_MC_scramble_access_w_7_reg_addr                               "0xB80B00CC"
#define  MC_SECURE_MC_scramble_access_w_7_reg                                    0xB80B00CC
#define  MC_SECURE_MC_scramble_access_w_7_inst_addr                              "0x002A"
#define  set_MC_SECURE_MC_scramble_access_w_7_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_7_reg)=data)
#define  get_MC_SECURE_MC_scramble_access_w_7_reg                                (*((volatile unsigned int*)MC_SECURE_MC_scramble_access_w_7_reg))
#define  MC_SECURE_MC_scramble_access_w_7_tp_kc_shift                            (13)
#define  MC_SECURE_MC_scramble_access_w_7_emmc_kc_shift                          (12)
#define  MC_SECURE_MC_scramble_access_w_7_acpu_shift                             (10)
#define  MC_SECURE_MC_scramble_access_w_7_vcpu_shift                             (8)
#define  MC_SECURE_MC_scramble_access_w_7_nf_kc_shift                            (7)
#define  MC_SECURE_MC_scramble_access_w_7_ve_shift                               (6)
#define  MC_SECURE_MC_scramble_access_w_7_vde_shift                              (5)
#define  MC_SECURE_MC_scramble_access_w_7_ade_shift                              (4)
#define  MC_SECURE_MC_scramble_access_w_7_ae_shift                               (3)
#define  MC_SECURE_MC_scramble_access_w_7_md_kc_shift                            (2)
#define  MC_SECURE_MC_scramble_access_w_7_cp_kc_shift                            (1)
#define  MC_SECURE_MC_scramble_access_w_7_md_vc_shift                            (0)
#define  MC_SECURE_MC_scramble_access_w_7_tp_kc_mask                             (0x00002000)
#define  MC_SECURE_MC_scramble_access_w_7_emmc_kc_mask                           (0x00001000)
#define  MC_SECURE_MC_scramble_access_w_7_acpu_mask                              (0x00000400)
#define  MC_SECURE_MC_scramble_access_w_7_vcpu_mask                              (0x00000100)
#define  MC_SECURE_MC_scramble_access_w_7_nf_kc_mask                             (0x00000080)
#define  MC_SECURE_MC_scramble_access_w_7_ve_mask                                (0x00000040)
#define  MC_SECURE_MC_scramble_access_w_7_vde_mask                               (0x00000020)
#define  MC_SECURE_MC_scramble_access_w_7_ade_mask                               (0x00000010)
#define  MC_SECURE_MC_scramble_access_w_7_ae_mask                                (0x00000008)
#define  MC_SECURE_MC_scramble_access_w_7_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_scramble_access_w_7_cp_kc_mask                             (0x00000002)
#define  MC_SECURE_MC_scramble_access_w_7_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_scramble_access_w_7_tp_kc(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_scramble_access_w_7_emmc_kc(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_scramble_access_w_7_acpu(data)                             (0x00000400&((data)<<10))
#define  MC_SECURE_MC_scramble_access_w_7_vcpu(data)                             (0x00000100&((data)<<8))
#define  MC_SECURE_MC_scramble_access_w_7_nf_kc(data)                            (0x00000080&((data)<<7))
#define  MC_SECURE_MC_scramble_access_w_7_ve(data)                               (0x00000040&((data)<<6))
#define  MC_SECURE_MC_scramble_access_w_7_vde(data)                              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_scramble_access_w_7_ade(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_scramble_access_w_7_ae(data)                               (0x00000008&((data)<<3))
#define  MC_SECURE_MC_scramble_access_w_7_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_scramble_access_w_7_cp_kc(data)                            (0x00000002&((data)<<1))
#define  MC_SECURE_MC_scramble_access_w_7_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_scramble_access_w_7_get_tp_kc(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_scramble_access_w_7_get_emmc_kc(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_scramble_access_w_7_get_acpu(data)                         ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_scramble_access_w_7_get_vcpu(data)                         ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_scramble_access_w_7_get_nf_kc(data)                        ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_scramble_access_w_7_get_ve(data)                           ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_scramble_access_w_7_get_vde(data)                          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_scramble_access_w_7_get_ade(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_scramble_access_w_7_get_ae(data)                           ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_scramble_access_w_7_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_scramble_access_w_7_get_cp_kc(data)                        ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_scramble_access_w_7_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_mem_scramble_start_0                                       0x180B00D0
#define  MC_SECURE_MC_mem_scramble_start_0_reg_addr                              "0xB80B00D0"
#define  MC_SECURE_MC_mem_scramble_start_0_reg                                   0xB80B00D0
#define  MC_SECURE_MC_mem_scramble_start_0_inst_addr                             "0x002B"
#define  set_MC_SECURE_MC_mem_scramble_start_0_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_0_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_0_reg))
#define  MC_SECURE_MC_mem_scramble_start_0_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_0_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_0_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_0_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_1                                       0x180B00D4
#define  MC_SECURE_MC_mem_scramble_start_1_reg_addr                              "0xB80B00D4"
#define  MC_SECURE_MC_mem_scramble_start_1_reg                                   0xB80B00D4
#define  MC_SECURE_MC_mem_scramble_start_1_inst_addr                             "0x002C"
#define  set_MC_SECURE_MC_mem_scramble_start_1_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_1_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_1_reg))
#define  MC_SECURE_MC_mem_scramble_start_1_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_1_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_1_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_1_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_2                                       0x180B00D8
#define  MC_SECURE_MC_mem_scramble_start_2_reg_addr                              "0xB80B00D8"
#define  MC_SECURE_MC_mem_scramble_start_2_reg                                   0xB80B00D8
#define  MC_SECURE_MC_mem_scramble_start_2_inst_addr                             "0x002D"
#define  set_MC_SECURE_MC_mem_scramble_start_2_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_2_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_2_reg))
#define  MC_SECURE_MC_mem_scramble_start_2_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_2_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_2_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_2_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_3                                       0x180B00DC
#define  MC_SECURE_MC_mem_scramble_start_3_reg_addr                              "0xB80B00DC"
#define  MC_SECURE_MC_mem_scramble_start_3_reg                                   0xB80B00DC
#define  MC_SECURE_MC_mem_scramble_start_3_inst_addr                             "0x002E"
#define  set_MC_SECURE_MC_mem_scramble_start_3_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_3_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_3_reg))
#define  MC_SECURE_MC_mem_scramble_start_3_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_3_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_3_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_3_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_4                                       0x180B00E0
#define  MC_SECURE_MC_mem_scramble_start_4_reg_addr                              "0xB80B00E0"
#define  MC_SECURE_MC_mem_scramble_start_4_reg                                   0xB80B00E0
#define  MC_SECURE_MC_mem_scramble_start_4_inst_addr                             "0x002F"
#define  set_MC_SECURE_MC_mem_scramble_start_4_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_4_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_4_reg))
#define  MC_SECURE_MC_mem_scramble_start_4_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_4_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_4_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_4_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_5                                       0x180B00E4
#define  MC_SECURE_MC_mem_scramble_start_5_reg_addr                              "0xB80B00E4"
#define  MC_SECURE_MC_mem_scramble_start_5_reg                                   0xB80B00E4
#define  MC_SECURE_MC_mem_scramble_start_5_inst_addr                             "0x0030"
#define  set_MC_SECURE_MC_mem_scramble_start_5_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_5_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_5_reg))
#define  MC_SECURE_MC_mem_scramble_start_5_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_5_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_5_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_5_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_6                                       0x180B00E8
#define  MC_SECURE_MC_mem_scramble_start_6_reg_addr                              "0xB80B00E8"
#define  MC_SECURE_MC_mem_scramble_start_6_reg                                   0xB80B00E8
#define  MC_SECURE_MC_mem_scramble_start_6_inst_addr                             "0x0031"
#define  set_MC_SECURE_MC_mem_scramble_start_6_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_6_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_6_reg))
#define  MC_SECURE_MC_mem_scramble_start_6_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_6_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_6_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_6_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_start_7                                       0x180B00EC
#define  MC_SECURE_MC_mem_scramble_start_7_reg_addr                              "0xB80B00EC"
#define  MC_SECURE_MC_mem_scramble_start_7_reg                                   0xB80B00EC
#define  MC_SECURE_MC_mem_scramble_start_7_inst_addr                             "0x0032"
#define  set_MC_SECURE_MC_mem_scramble_start_7_reg(data)                         (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_start_7_reg                               (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_start_7_reg))
#define  MC_SECURE_MC_mem_scramble_start_7_addr_shift                            (12)
#define  MC_SECURE_MC_mem_scramble_start_7_addr_mask                             (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_start_7_addr(data)                            (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_start_7_get_addr(data)                        ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_0                                         0x180B00F0
#define  MC_SECURE_MC_mem_scramble_end_0_reg_addr                                "0xB80B00F0"
#define  MC_SECURE_MC_mem_scramble_end_0_reg                                     0xB80B00F0
#define  MC_SECURE_MC_mem_scramble_end_0_inst_addr                               "0x0033"
#define  set_MC_SECURE_MC_mem_scramble_end_0_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_0_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_0_reg))
#define  MC_SECURE_MC_mem_scramble_end_0_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_0_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_0_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_0_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_1                                         0x180B00F4
#define  MC_SECURE_MC_mem_scramble_end_1_reg_addr                                "0xB80B00F4"
#define  MC_SECURE_MC_mem_scramble_end_1_reg                                     0xB80B00F4
#define  MC_SECURE_MC_mem_scramble_end_1_inst_addr                               "0x0034"
#define  set_MC_SECURE_MC_mem_scramble_end_1_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_1_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_1_reg))
#define  MC_SECURE_MC_mem_scramble_end_1_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_1_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_1_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_1_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_2                                         0x180B00F8
#define  MC_SECURE_MC_mem_scramble_end_2_reg_addr                                "0xB80B00F8"
#define  MC_SECURE_MC_mem_scramble_end_2_reg                                     0xB80B00F8
#define  MC_SECURE_MC_mem_scramble_end_2_inst_addr                               "0x0035"
#define  set_MC_SECURE_MC_mem_scramble_end_2_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_2_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_2_reg))
#define  MC_SECURE_MC_mem_scramble_end_2_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_2_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_2_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_2_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_3                                         0x180B00FC
#define  MC_SECURE_MC_mem_scramble_end_3_reg_addr                                "0xB80B00FC"
#define  MC_SECURE_MC_mem_scramble_end_3_reg                                     0xB80B00FC
#define  MC_SECURE_MC_mem_scramble_end_3_inst_addr                               "0x0036"
#define  set_MC_SECURE_MC_mem_scramble_end_3_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_3_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_3_reg))
#define  MC_SECURE_MC_mem_scramble_end_3_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_3_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_3_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_3_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_4                                         0x180B0100
#define  MC_SECURE_MC_mem_scramble_end_4_reg_addr                                "0xB80B0100"
#define  MC_SECURE_MC_mem_scramble_end_4_reg                                     0xB80B0100
#define  MC_SECURE_MC_mem_scramble_end_4_inst_addr                               "0x0037"
#define  set_MC_SECURE_MC_mem_scramble_end_4_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_4_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_4_reg))
#define  MC_SECURE_MC_mem_scramble_end_4_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_4_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_4_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_4_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_5                                         0x180B0104
#define  MC_SECURE_MC_mem_scramble_end_5_reg_addr                                "0xB80B0104"
#define  MC_SECURE_MC_mem_scramble_end_5_reg                                     0xB80B0104
#define  MC_SECURE_MC_mem_scramble_end_5_inst_addr                               "0x0038"
#define  set_MC_SECURE_MC_mem_scramble_end_5_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_5_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_5_reg))
#define  MC_SECURE_MC_mem_scramble_end_5_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_5_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_5_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_5_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_6                                         0x180B0108
#define  MC_SECURE_MC_mem_scramble_end_6_reg_addr                                "0xB80B0108"
#define  MC_SECURE_MC_mem_scramble_end_6_reg                                     0xB80B0108
#define  MC_SECURE_MC_mem_scramble_end_6_inst_addr                               "0x0039"
#define  set_MC_SECURE_MC_mem_scramble_end_6_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_6_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_6_reg))
#define  MC_SECURE_MC_mem_scramble_end_6_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_6_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_6_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_6_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_end_7                                         0x180B010C
#define  MC_SECURE_MC_mem_scramble_end_7_reg_addr                                "0xB80B010C"
#define  MC_SECURE_MC_mem_scramble_end_7_reg                                     0xB80B010C
#define  MC_SECURE_MC_mem_scramble_end_7_inst_addr                               "0x003A"
#define  set_MC_SECURE_MC_mem_scramble_end_7_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_end_7_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_end_7_reg))
#define  MC_SECURE_MC_mem_scramble_end_7_addr_shift                              (12)
#define  MC_SECURE_MC_mem_scramble_end_7_addr_mask                               (0xFFFFF000)
#define  MC_SECURE_MC_mem_scramble_end_7_addr(data)                              (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_mem_scramble_end_7_get_addr(data)                          ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_mem_scramble_buf_cur0_0                                    0x180B0110
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_reg_addr                           "0xB80B0110"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_reg                                0xB80B0110
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_inst_addr                          "0x003B"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_0_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_1                                    0x180B0114
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_reg_addr                           "0xB80B0114"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_reg                                0xB80B0114
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_inst_addr                          "0x003C"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_1_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_2                                    0x180B0118
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_reg_addr                           "0xB80B0118"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_reg                                0xB80B0118
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_inst_addr                          "0x003D"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_2_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_3                                    0x180B011C
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_reg_addr                           "0xB80B011C"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_reg                                0xB80B011C
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_inst_addr                          "0x003E"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_3_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_4                                    0x180B0120
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_reg_addr                           "0xB80B0120"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_reg                                0xB80B0120
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_inst_addr                          "0x003F"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_4_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_5                                    0x180B0124
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_reg_addr                           "0xB80B0124"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_reg                                0xB80B0124
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_inst_addr                          "0x0040"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_5_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_6                                    0x180B0128
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_reg_addr                           "0xB80B0128"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_reg                                0xB80B0128
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_inst_addr                          "0x0041"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_6_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur0_7                                    0x180B012C
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_reg_addr                           "0xB80B012C"
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_reg                                0xB80B012C
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_inst_addr                          "0x0042"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur0_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur0_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur0_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur0_7_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_0                                    0x180B0130
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_reg_addr                           "0xB80B0130"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_reg                                0xB80B0130
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_inst_addr                          "0x0043"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_0_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_1                                    0x180B0134
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_reg_addr                           "0xB80B0134"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_reg                                0xB80B0134
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_inst_addr                          "0x0044"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_1_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_2                                    0x180B0138
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_reg_addr                           "0xB80B0138"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_reg                                0xB80B0138
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_inst_addr                          "0x0045"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_2_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_3                                    0x180B013C
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_reg_addr                           "0xB80B013C"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_reg                                0xB80B013C
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_inst_addr                          "0x0046"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_3_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_4                                    0x180B0140
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_reg_addr                           "0xB80B0140"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_reg                                0xB80B0140
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_inst_addr                          "0x0047"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_4_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_5                                    0x180B0144
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_reg_addr                           "0xB80B0144"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_reg                                0xB80B0144
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_inst_addr                          "0x0048"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_5_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_6                                    0x180B0148
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_reg_addr                           "0xB80B0148"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_reg                                0xB80B0148
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_inst_addr                          "0x0049"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_6_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur1_7                                    0x180B014C
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_reg_addr                           "0xB80B014C"
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_reg                                0xB80B014C
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_inst_addr                          "0x004A"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur1_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur1_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur1_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur1_7_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_0                                    0x180B0150
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_reg_addr                           "0xB80B0150"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_reg                                0xB80B0150
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_inst_addr                          "0x004B"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_0_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_1                                    0x180B0154
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_reg_addr                           "0xB80B0154"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_reg                                0xB80B0154
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_inst_addr                          "0x004C"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_1_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_2                                    0x180B0158
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_reg_addr                           "0xB80B0158"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_reg                                0xB80B0158
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_inst_addr                          "0x004D"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_2_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_3                                    0x180B015C
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_reg_addr                           "0xB80B015C"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_reg                                0xB80B015C
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_inst_addr                          "0x004E"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_3_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_4                                    0x180B0160
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_reg_addr                           "0xB80B0160"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_reg                                0xB80B0160
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_inst_addr                          "0x004F"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_4_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_5                                    0x180B0164
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_reg_addr                           "0xB80B0164"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_reg                                0xB80B0164
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_inst_addr                          "0x0050"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_5_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_6                                    0x180B0168
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_reg_addr                           "0xB80B0168"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_reg                                0xB80B0168
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_inst_addr                          "0x0051"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_6_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur2_7                                    0x180B016C
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_reg_addr                           "0xB80B016C"
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_reg                                0xB80B016C
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_inst_addr                          "0x0052"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur2_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur2_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur2_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur2_7_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_0                                    0x180B0170
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_reg_addr                           "0xB80B0170"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_reg                                0xB80B0170
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_inst_addr                          "0x0053"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_0_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_1                                    0x180B0174
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_reg_addr                           "0xB80B0174"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_reg                                0xB80B0174
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_inst_addr                          "0x0054"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_1_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_2                                    0x180B0178
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_reg_addr                           "0xB80B0178"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_reg                                0xB80B0178
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_inst_addr                          "0x0055"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_2_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_3                                    0x180B017C
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_reg_addr                           "0xB80B017C"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_reg                                0xB80B017C
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_inst_addr                          "0x0056"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_3_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_4                                    0x180B0180
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_reg_addr                           "0xB80B0180"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_reg                                0xB80B0180
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_inst_addr                          "0x0057"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_4_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_5                                    0x180B0184
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_reg_addr                           "0xB80B0184"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_reg                                0xB80B0184
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_inst_addr                          "0x0058"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_5_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_6                                    0x180B0188
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_reg_addr                           "0xB80B0188"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_reg                                0xB80B0188
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_inst_addr                          "0x0059"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_6_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur3_7                                    0x180B018C
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_reg_addr                           "0xB80B018C"
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_reg                                0xB80B018C
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_inst_addr                          "0x005A"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur3_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur3_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur3_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur3_7_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_0                                    0x180B0190
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_reg_addr                           "0xB80B0190"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_reg                                0xB80B0190
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_inst_addr                          "0x005B"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_0_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_1                                    0x180B0194
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_reg_addr                           "0xB80B0194"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_reg                                0xB80B0194
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_inst_addr                          "0x005C"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_1_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_2                                    0x180B0198
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_reg_addr                           "0xB80B0198"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_reg                                0xB80B0198
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_inst_addr                          "0x005D"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_2_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_3                                    0x180B019C
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_reg_addr                           "0xB80B019C"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_reg                                0xB80B019C
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_inst_addr                          "0x005E"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_3_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_4                                    0x180B01A0
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_reg_addr                           "0xB80B01A0"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_reg                                0xB80B01A0
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_inst_addr                          "0x005F"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_4_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_5                                    0x180B01A4
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_reg_addr                           "0xB80B01A4"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_reg                                0xB80B01A4
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_inst_addr                          "0x0060"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_5_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_6                                    0x180B01A8
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_reg_addr                           "0xB80B01A8"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_reg                                0xB80B01A8
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_inst_addr                          "0x0061"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_6_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur4_7                                    0x180B01AC
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_reg_addr                           "0xB80B01AC"
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_reg                                0xB80B01AC
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_inst_addr                          "0x0062"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur4_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur4_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur4_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur4_7_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_0                                    0x180B01B0
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_reg_addr                           "0xB80B01B0"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_reg                                0xB80B01B0
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_inst_addr                          "0x0063"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_0_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_1                                    0x180B01B4
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_reg_addr                           "0xB80B01B4"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_reg                                0xB80B01B4
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_inst_addr                          "0x0064"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_1_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_2                                    0x180B01B8
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_reg_addr                           "0xB80B01B8"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_reg                                0xB80B01B8
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_inst_addr                          "0x0065"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_2_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_3                                    0x180B01BC
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_reg_addr                           "0xB80B01BC"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_reg                                0xB80B01BC
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_inst_addr                          "0x0066"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_3_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_4                                    0x180B01C0
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_reg_addr                           "0xB80B01C0"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_reg                                0xB80B01C0
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_inst_addr                          "0x0067"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_4_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_5                                    0x180B01C4
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_reg_addr                           "0xB80B01C4"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_reg                                0xB80B01C4
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_inst_addr                          "0x0068"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_5_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_6                                    0x180B01C8
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_reg_addr                           "0xB80B01C8"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_reg                                0xB80B01C8
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_inst_addr                          "0x0069"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_6_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur5_7                                    0x180B01CC
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_reg_addr                           "0xB80B01CC"
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_reg                                0xB80B01CC
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_inst_addr                          "0x006A"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur5_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur5_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur5_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur5_7_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_0                                    0x180B01D0
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_reg_addr                           "0xB80B01D0"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_reg                                0xB80B01D0
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_inst_addr                          "0x006B"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_0_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_1                                    0x180B01D4
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_reg_addr                           "0xB80B01D4"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_reg                                0xB80B01D4
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_inst_addr                          "0x006C"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_1_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_2                                    0x180B01D8
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_reg_addr                           "0xB80B01D8"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_reg                                0xB80B01D8
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_inst_addr                          "0x006D"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_2_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_3                                    0x180B01DC
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_reg_addr                           "0xB80B01DC"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_reg                                0xB80B01DC
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_inst_addr                          "0x006E"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_3_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_4                                    0x180B01E0
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_reg_addr                           "0xB80B01E0"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_reg                                0xB80B01E0
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_inst_addr                          "0x006F"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_4_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_5                                    0x180B01E4
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_reg_addr                           "0xB80B01E4"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_reg                                0xB80B01E4
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_inst_addr                          "0x0070"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_5_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_6                                    0x180B01E8
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_reg_addr                           "0xB80B01E8"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_reg                                0xB80B01E8
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_inst_addr                          "0x0071"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_6_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_cur6_7                                    0x180B01EC
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_reg_addr                           "0xB80B01EC"
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_reg                                0xB80B01EC
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_inst_addr                          "0x0072"
#define  set_MC_SECURE_MC_mem_scramble_buf_cur6_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_cur6_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_cur6_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_cur6_7_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_0                                    0x180B01F0
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_reg_addr                           "0xB80B01F0"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_reg                                0xB80B01F0
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_inst_addr                          "0x0073"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_0_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_1                                    0x180B01F4
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_reg_addr                           "0xB80B01F4"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_reg                                0xB80B01F4
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_inst_addr                          "0x0074"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_1_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_2                                    0x180B01F8
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_reg_addr                           "0xB80B01F8"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_reg                                0xB80B01F8
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_inst_addr                          "0x0075"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_2_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_3                                    0x180B01FC
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_reg_addr                           "0xB80B01FC"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_reg                                0xB80B01FC
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_inst_addr                          "0x0076"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_3_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_4                                    0x180B0200
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_reg_addr                           "0xB80B0200"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_reg                                0xB80B0200
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_inst_addr                          "0x0077"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_4_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_5                                    0x180B0204
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_reg_addr                           "0xB80B0204"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_reg                                0xB80B0204
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_inst_addr                          "0x0078"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_5_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_6                                    0x180B0208
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_reg_addr                           "0xB80B0208"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_reg                                0xB80B0208
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_inst_addr                          "0x0079"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_6_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre0_7                                    0x180B020C
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_reg_addr                           "0xB80B020C"
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_reg                                0xB80B020C
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_inst_addr                          "0x007A"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre0_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre0_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre0_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_key1_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_key0_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_key1_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_key0_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_key1(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_key0(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_get_key1(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre0_7_get_key0(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_0                                    0x180B0210
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_reg_addr                           "0xB80B0210"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_reg                                0xB80B0210
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_inst_addr                          "0x007B"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_0_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_1                                    0x180B0214
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_reg_addr                           "0xB80B0214"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_reg                                0xB80B0214
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_inst_addr                          "0x007C"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_1_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_2                                    0x180B0218
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_reg_addr                           "0xB80B0218"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_reg                                0xB80B0218
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_inst_addr                          "0x007D"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_2_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_3                                    0x180B021C
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_reg_addr                           "0xB80B021C"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_reg                                0xB80B021C
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_inst_addr                          "0x007E"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_3_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_4                                    0x180B0220
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_reg_addr                           "0xB80B0220"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_reg                                0xB80B0220
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_inst_addr                          "0x007F"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_4_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_5                                    0x180B0224
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_reg_addr                           "0xB80B0224"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_reg                                0xB80B0224
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_inst_addr                          "0x0080"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_5_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_6                                    0x180B0228
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_reg_addr                           "0xB80B0228"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_reg                                0xB80B0228
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_inst_addr                          "0x0081"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_6_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre1_7                                    0x180B022C
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_reg_addr                           "0xB80B022C"
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_reg                                0xB80B022C
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_inst_addr                          "0x0082"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre1_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre1_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre1_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_key3_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_key2_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_key3_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_key2_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_key3(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_key2(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_get_key3(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre1_7_get_key2(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_0                                    0x180B0230
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_reg_addr                           "0xB80B0230"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_reg                                0xB80B0230
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_inst_addr                          "0x0083"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_0_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_1                                    0x180B0234
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_reg_addr                           "0xB80B0234"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_reg                                0xB80B0234
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_inst_addr                          "0x0084"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_1_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_2                                    0x180B0238
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_reg_addr                           "0xB80B0238"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_reg                                0xB80B0238
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_inst_addr                          "0x0085"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_2_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_3                                    0x180B023C
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_reg_addr                           "0xB80B023C"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_reg                                0xB80B023C
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_inst_addr                          "0x0086"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_3_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_4                                    0x180B0240
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_reg_addr                           "0xB80B0240"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_reg                                0xB80B0240
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_inst_addr                          "0x0087"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_4_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_5                                    0x180B0244
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_reg_addr                           "0xB80B0244"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_reg                                0xB80B0244
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_inst_addr                          "0x0088"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_5_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_6                                    0x180B0248
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_reg_addr                           "0xB80B0248"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_reg                                0xB80B0248
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_inst_addr                          "0x0089"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_6_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre2_7                                    0x180B024C
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_reg_addr                           "0xB80B024C"
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_reg                                0xB80B024C
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_inst_addr                          "0x008A"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre2_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre2_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre2_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_key5_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_key4_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_key5_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_key4_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_key5(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_key4(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_get_key5(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre2_7_get_key4(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_0                                    0x180B0250
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_reg_addr                           "0xB80B0250"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_reg                                0xB80B0250
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_inst_addr                          "0x008B"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_0_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_1                                    0x180B0254
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_reg_addr                           "0xB80B0254"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_reg                                0xB80B0254
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_inst_addr                          "0x008C"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_1_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_2                                    0x180B0258
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_reg_addr                           "0xB80B0258"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_reg                                0xB80B0258
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_inst_addr                          "0x008D"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_2_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_3                                    0x180B025C
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_reg_addr                           "0xB80B025C"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_reg                                0xB80B025C
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_inst_addr                          "0x008E"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_3_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_4                                    0x180B0260
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_reg_addr                           "0xB80B0260"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_reg                                0xB80B0260
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_inst_addr                          "0x008F"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_4_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_5                                    0x180B0264
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_reg_addr                           "0xB80B0264"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_reg                                0xB80B0264
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_inst_addr                          "0x0090"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_5_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_6                                    0x180B0268
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_reg_addr                           "0xB80B0268"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_reg                                0xB80B0268
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_inst_addr                          "0x0091"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_6_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre3_7                                    0x180B026C
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_reg_addr                           "0xB80B026C"
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_reg                                0xB80B026C
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_inst_addr                          "0x0092"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre3_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre3_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre3_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_key7_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_key6_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_key7_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_key6_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_key7(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_key6(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_get_key7(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre3_7_get_key6(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_0                                    0x180B0270
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_reg_addr                           "0xB80B0270"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_reg                                0xB80B0270
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_inst_addr                          "0x0093"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_0_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_1                                    0x180B0274
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_reg_addr                           "0xB80B0274"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_reg                                0xB80B0274
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_inst_addr                          "0x0094"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_1_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_2                                    0x180B0278
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_reg_addr                           "0xB80B0278"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_reg                                0xB80B0278
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_inst_addr                          "0x0095"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_2_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_3                                    0x180B027C
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_reg_addr                           "0xB80B027C"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_reg                                0xB80B027C
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_inst_addr                          "0x0096"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_3_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_4                                    0x180B0280
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_reg_addr                           "0xB80B0280"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_reg                                0xB80B0280
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_inst_addr                          "0x0097"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_4_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_5                                    0x180B0284
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_reg_addr                           "0xB80B0284"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_reg                                0xB80B0284
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_inst_addr                          "0x0098"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_5_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_6                                    0x180B0288
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_reg_addr                           "0xB80B0288"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_reg                                0xB80B0288
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_inst_addr                          "0x0099"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_6_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre4_7                                    0x180B028C
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_reg_addr                           "0xB80B028C"
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_reg                                0xB80B028C
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_inst_addr                          "0x009A"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre4_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre4_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre4_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_key9_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_key8_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_key9_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_key8_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_key9(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_key8(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_get_key9(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre4_7_get_key8(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_0                                    0x180B0290
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_reg_addr                           "0xB80B0290"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_reg                                0xB80B0290
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_inst_addr                          "0x009B"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_0_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_1                                    0x180B0294
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_reg_addr                           "0xB80B0294"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_reg                                0xB80B0294
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_inst_addr                          "0x009C"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_1_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_2                                    0x180B0298
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_reg_addr                           "0xB80B0298"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_reg                                0xB80B0298
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_inst_addr                          "0x009D"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_2_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_3                                    0x180B029C
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_reg_addr                           "0xB80B029C"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_reg                                0xB80B029C
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_inst_addr                          "0x009E"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_3_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_4                                    0x180B02A0
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_reg_addr                           "0xB80B02A0"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_reg                                0xB80B02A0
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_inst_addr                          "0x009F"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_4_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_5                                    0x180B02A4
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_reg_addr                           "0xB80B02A4"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_reg                                0xB80B02A4
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_inst_addr                          "0x00A0"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_5_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_6                                    0x180B02A8
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_reg_addr                           "0xB80B02A8"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_reg                                0xB80B02A8
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_inst_addr                          "0x00A1"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_6_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre5_7                                    0x180B02AC
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_reg_addr                           "0xB80B02AC"
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_reg                                0xB80B02AC
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_inst_addr                          "0x00A2"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre5_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre5_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre5_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_keyb_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_keya_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_keyb_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_keya_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_keyb(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_keya(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_get_keyb(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre5_7_get_keya(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_0                                    0x180B02B0
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_reg_addr                           "0xB80B02B0"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_reg                                0xB80B02B0
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_inst_addr                          "0x00A3"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_0_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_0_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_0_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_1                                    0x180B02B4
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_reg_addr                           "0xB80B02B4"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_reg                                0xB80B02B4
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_inst_addr                          "0x00A4"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_1_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_1_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_1_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_2                                    0x180B02B8
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_reg_addr                           "0xB80B02B8"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_reg                                0xB80B02B8
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_inst_addr                          "0x00A5"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_2_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_2_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_2_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_3                                    0x180B02BC
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_reg_addr                           "0xB80B02BC"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_reg                                0xB80B02BC
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_inst_addr                          "0x00A6"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_3_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_3_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_3_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_4                                    0x180B02C0
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_reg_addr                           "0xB80B02C0"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_reg                                0xB80B02C0
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_inst_addr                          "0x00A7"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_4_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_4_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_4_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_5                                    0x180B02C4
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_reg_addr                           "0xB80B02C4"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_reg                                0xB80B02C4
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_inst_addr                          "0x00A8"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_5_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_5_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_5_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_6                                    0x180B02C8
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_reg_addr                           "0xB80B02C8"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_reg                                0xB80B02C8
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_inst_addr                          "0x00A9"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_6_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_6_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_6_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_pre6_7                                    0x180B02CC
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_reg_addr                           "0xB80B02CC"
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_reg                                0xB80B02CC
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_inst_addr                          "0x00AA"
#define  set_MC_SECURE_MC_mem_scramble_buf_pre6_7_reg(data)                      (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_pre6_7_reg                            (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_pre6_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_keyd_shift                         (16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_keyc_shift                         (0)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_keyd_mask                          (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_keyc_mask                          (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_keyd(data)                         (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_keyc(data)                         (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_get_keyd(data)                     ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_pre6_7_get_keyc(data)                     (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_0                                     0x180B02D0
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_reg_addr                            "0xB80B02D0"
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_reg                                 0xB80B02D0
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_inst_addr                           "0x00AB"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_0_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_1                                     0x180B02D4
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_reg_addr                            "0xB80B02D4"
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_reg                                 0xB80B02D4
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_inst_addr                           "0x00AC"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_1_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_2                                     0x180B02D8
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_reg_addr                            "0xB80B02D8"
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_reg                                 0xB80B02D8
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_inst_addr                           "0x00AD"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_2_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_3                                     0x180B02DC
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_reg_addr                            "0xB80B02DC"
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_reg                                 0xB80B02DC
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_inst_addr                           "0x00AE"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_3_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_4                                     0x180B02E0
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_reg_addr                            "0xB80B02E0"
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_reg                                 0xB80B02E0
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_inst_addr                           "0x00AF"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_4_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_5                                     0x180B02E4
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_reg_addr                            "0xB80B02E4"
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_reg                                 0xB80B02E4
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_inst_addr                           "0x00B0"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_5_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_6                                     0x180B02E8
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_reg_addr                            "0xB80B02E8"
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_reg                                 0xB80B02E8
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_inst_addr                           "0x00B1"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_6_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up0_7                                     0x180B02EC
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_reg_addr                            "0xB80B02EC"
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_reg                                 0xB80B02EC
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_inst_addr                           "0x00B2"
#define  set_MC_SECURE_MC_mem_scramble_buf_up0_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up0_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up0_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_key1_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_key0_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_key1_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_key0_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_key1(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_key0(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_get_key1(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up0_7_get_key0(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_0                                     0x180B02F0
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_reg_addr                            "0xB80B02F0"
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_reg                                 0xB80B02F0
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_inst_addr                           "0x00B3"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_0_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_1                                     0x180B02F4
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_reg_addr                            "0xB80B02F4"
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_reg                                 0xB80B02F4
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_inst_addr                           "0x00B4"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_1_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_2                                     0x180B02F8
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_reg_addr                            "0xB80B02F8"
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_reg                                 0xB80B02F8
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_inst_addr                           "0x00B5"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_2_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_3                                     0x180B02FC
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_reg_addr                            "0xB80B02FC"
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_reg                                 0xB80B02FC
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_inst_addr                           "0x00B6"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_3_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_4                                     0x180B0300
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_reg_addr                            "0xB80B0300"
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_reg                                 0xB80B0300
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_inst_addr                           "0x00B7"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_4_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_5                                     0x180B0304
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_reg_addr                            "0xB80B0304"
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_reg                                 0xB80B0304
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_inst_addr                           "0x00B8"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_5_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_6                                     0x180B0308
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_reg_addr                            "0xB80B0308"
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_reg                                 0xB80B0308
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_inst_addr                           "0x00B9"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_6_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up1_7                                     0x180B030C
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_reg_addr                            "0xB80B030C"
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_reg                                 0xB80B030C
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_inst_addr                           "0x00BA"
#define  set_MC_SECURE_MC_mem_scramble_buf_up1_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up1_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up1_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_key3_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_key2_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_key3_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_key2_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_key3(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_key2(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_get_key3(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up1_7_get_key2(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_0                                     0x180B0310
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_reg_addr                            "0xB80B0310"
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_reg                                 0xB80B0310
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_inst_addr                           "0x00BB"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_0_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_1                                     0x180B0314
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_reg_addr                            "0xB80B0314"
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_reg                                 0xB80B0314
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_inst_addr                           "0x00BC"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_1_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_2                                     0x180B0318
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_reg_addr                            "0xB80B0318"
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_reg                                 0xB80B0318
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_inst_addr                           "0x00BD"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_2_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_3                                     0x180B031C
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_reg_addr                            "0xB80B031C"
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_reg                                 0xB80B031C
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_inst_addr                           "0x00BE"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_3_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_4                                     0x180B0320
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_reg_addr                            "0xB80B0320"
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_reg                                 0xB80B0320
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_inst_addr                           "0x00BF"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_4_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_5                                     0x180B0324
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_reg_addr                            "0xB80B0324"
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_reg                                 0xB80B0324
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_inst_addr                           "0x00C0"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_5_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_6                                     0x180B0328
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_reg_addr                            "0xB80B0328"
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_reg                                 0xB80B0328
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_inst_addr                           "0x00C1"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_6_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up2_7                                     0x180B032C
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_reg_addr                            "0xB80B032C"
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_reg                                 0xB80B032C
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_inst_addr                           "0x00C2"
#define  set_MC_SECURE_MC_mem_scramble_buf_up2_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up2_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up2_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_key5_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_key4_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_key5_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_key4_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_key5(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_key4(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_get_key5(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up2_7_get_key4(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_0                                     0x180B0330
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_reg_addr                            "0xB80B0330"
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_reg                                 0xB80B0330
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_inst_addr                           "0x00C3"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_0_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_1                                     0x180B0334
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_reg_addr                            "0xB80B0334"
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_reg                                 0xB80B0334
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_inst_addr                           "0x00C4"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_1_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_2                                     0x180B0338
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_reg_addr                            "0xB80B0338"
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_reg                                 0xB80B0338
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_inst_addr                           "0x00C5"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_2_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_3                                     0x180B033C
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_reg_addr                            "0xB80B033C"
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_reg                                 0xB80B033C
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_inst_addr                           "0x00C6"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_3_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_4                                     0x180B0340
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_reg_addr                            "0xB80B0340"
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_reg                                 0xB80B0340
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_inst_addr                           "0x00C7"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_4_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_5                                     0x180B0344
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_reg_addr                            "0xB80B0344"
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_reg                                 0xB80B0344
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_inst_addr                           "0x00C8"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_5_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_6                                     0x180B0348
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_reg_addr                            "0xB80B0348"
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_reg                                 0xB80B0348
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_inst_addr                           "0x00C9"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_6_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up3_7                                     0x180B034C
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_reg_addr                            "0xB80B034C"
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_reg                                 0xB80B034C
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_inst_addr                           "0x00CA"
#define  set_MC_SECURE_MC_mem_scramble_buf_up3_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up3_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up3_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_key7_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_key6_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_key7_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_key6_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_key7(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_key6(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_get_key7(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up3_7_get_key6(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_0                                     0x180B0350
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_reg_addr                            "0xB80B0350"
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_reg                                 0xB80B0350
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_inst_addr                           "0x00CB"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_0_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_1                                     0x180B0354
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_reg_addr                            "0xB80B0354"
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_reg                                 0xB80B0354
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_inst_addr                           "0x00CC"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_1_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_2                                     0x180B0358
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_reg_addr                            "0xB80B0358"
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_reg                                 0xB80B0358
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_inst_addr                           "0x00CD"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_2_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_3                                     0x180B035C
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_reg_addr                            "0xB80B035C"
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_reg                                 0xB80B035C
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_inst_addr                           "0x00CE"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_3_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_4                                     0x180B0360
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_reg_addr                            "0xB80B0360"
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_reg                                 0xB80B0360
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_inst_addr                           "0x00CF"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_4_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_5                                     0x180B0364
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_reg_addr                            "0xB80B0364"
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_reg                                 0xB80B0364
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_inst_addr                           "0x00D0"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_5_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_6                                     0x180B0368
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_reg_addr                            "0xB80B0368"
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_reg                                 0xB80B0368
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_inst_addr                           "0x00D1"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_6_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up4_7                                     0x180B036C
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_reg_addr                            "0xB80B036C"
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_reg                                 0xB80B036C
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_inst_addr                           "0x00D2"
#define  set_MC_SECURE_MC_mem_scramble_buf_up4_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up4_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up4_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_key9_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_key8_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_key9_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_key8_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_key9(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_key8(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_get_key9(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up4_7_get_key8(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_0                                     0x180B0370
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_reg_addr                            "0xB80B0370"
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_reg                                 0xB80B0370
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_inst_addr                           "0x00D3"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_0_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_1                                     0x180B0374
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_reg_addr                            "0xB80B0374"
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_reg                                 0xB80B0374
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_inst_addr                           "0x00D4"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_1_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_2                                     0x180B0378
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_reg_addr                            "0xB80B0378"
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_reg                                 0xB80B0378
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_inst_addr                           "0x00D5"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_2_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_3                                     0x180B037C
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_reg_addr                            "0xB80B037C"
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_reg                                 0xB80B037C
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_inst_addr                           "0x00D6"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_3_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_4                                     0x180B0380
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_reg_addr                            "0xB80B0380"
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_reg                                 0xB80B0380
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_inst_addr                           "0x00D7"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_4_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_5                                     0x180B0384
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_reg_addr                            "0xB80B0384"
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_reg                                 0xB80B0384
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_inst_addr                           "0x00D8"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_5_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_6                                     0x180B0388
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_reg_addr                            "0xB80B0388"
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_reg                                 0xB80B0388
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_inst_addr                           "0x00D9"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_6_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up5_7                                     0x180B038C
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_reg_addr                            "0xB80B038C"
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_reg                                 0xB80B038C
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_inst_addr                           "0x00DA"
#define  set_MC_SECURE_MC_mem_scramble_buf_up5_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up5_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up5_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_keyb_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_keya_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_keyb_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_keya_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_keyb(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_keya(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_get_keyb(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up5_7_get_keya(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_0                                     0x180B0390
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_reg_addr                            "0xB80B0390"
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_reg                                 0xB80B0390
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_inst_addr                           "0x00DB"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_0_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_0_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_0_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_0_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_0_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_1                                     0x180B0394
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_reg_addr                            "0xB80B0394"
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_reg                                 0xB80B0394
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_inst_addr                           "0x00DC"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_1_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_1_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_1_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_1_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_1_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_2                                     0x180B0398
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_reg_addr                            "0xB80B0398"
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_reg                                 0xB80B0398
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_inst_addr                           "0x00DD"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_2_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_2_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_2_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_2_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_2_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_3                                     0x180B039C
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_reg_addr                            "0xB80B039C"
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_reg                                 0xB80B039C
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_inst_addr                           "0x00DE"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_3_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_3_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_3_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_3_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_3_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_4                                     0x180B03A0
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_reg_addr                            "0xB80B03A0"
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_reg                                 0xB80B03A0
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_inst_addr                           "0x00DF"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_4_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_4_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_4_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_4_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_4_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_5                                     0x180B03A4
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_reg_addr                            "0xB80B03A4"
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_reg                                 0xB80B03A4
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_inst_addr                           "0x00E0"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_5_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_5_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_5_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_5_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_5_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_6                                     0x180B03A8
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_reg_addr                            "0xB80B03A8"
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_reg                                 0xB80B03A8
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_inst_addr                           "0x00E1"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_6_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_6_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_6_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_6_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_6_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_scramble_buf_up6_7                                     0x180B03AC
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_reg_addr                            "0xB80B03AC"
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_reg                                 0xB80B03AC
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_inst_addr                           "0x00E2"
#define  set_MC_SECURE_MC_mem_scramble_buf_up6_7_reg(data)                       (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_7_reg)=data)
#define  get_MC_SECURE_MC_mem_scramble_buf_up6_7_reg                             (*((volatile unsigned int*)MC_SECURE_MC_mem_scramble_buf_up6_7_reg))
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_keyd_shift                          (16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_keyc_shift                          (0)
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_keyd_mask                           (0xFFFF0000)
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_keyc_mask                           (0x0000FFFF)
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_keyd(data)                          (0xFFFF0000&((data)<<16))
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_keyc(data)                          (0x0000FFFF&(data))
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_get_keyd(data)                      ((0xFFFF0000&(data))>>16)
#define  MC_SECURE_MC_mem_scramble_buf_up6_7_get_keyc(data)                      (0x0000FFFF&(data))

#define  MC_SECURE_MC_mem_display_ctrl                                           0x180B03F0
#define  MC_SECURE_MC_mem_display_ctrl_reg_addr                                  "0xB80B03F0"
#define  MC_SECURE_MC_mem_display_ctrl_reg                                       0xB80B03F0
#define  MC_SECURE_MC_mem_display_ctrl_inst_addr                                 "0x00E3"
#define  set_MC_SECURE_MC_mem_display_ctrl_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_mem_display_ctrl_reg)=data)
#define  get_MC_SECURE_MC_mem_display_ctrl_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_mem_display_ctrl_reg))
#define  MC_SECURE_MC_mem_display_ctrl_gpu_id_mode_shift                         (30)
#define  MC_SECURE_MC_mem_display_ctrl_display_15_en_shift                       (23)
#define  MC_SECURE_MC_mem_display_ctrl_display_14_en_shift                       (22)
#define  MC_SECURE_MC_mem_display_ctrl_display_13_en_shift                       (21)
#define  MC_SECURE_MC_mem_display_ctrl_display_12_en_shift                       (20)
#define  MC_SECURE_MC_mem_display_ctrl_display_11_en_shift                       (19)
#define  MC_SECURE_MC_mem_display_ctrl_display_10_en_shift                       (18)
#define  MC_SECURE_MC_mem_display_ctrl_display_9_en_shift                        (17)
#define  MC_SECURE_MC_mem_display_ctrl_display_8_en_shift                        (16)
#define  MC_SECURE_MC_mem_display_ctrl_display_7_en_shift                        (15)
#define  MC_SECURE_MC_mem_display_ctrl_display_6_en_shift                        (14)
#define  MC_SECURE_MC_mem_display_ctrl_display_5_en_shift                        (13)
#define  MC_SECURE_MC_mem_display_ctrl_display_4_en_shift                        (12)
#define  MC_SECURE_MC_mem_display_ctrl_display_3_en_shift                        (11)
#define  MC_SECURE_MC_mem_display_ctrl_display_2_en_shift                        (10)
#define  MC_SECURE_MC_mem_display_ctrl_display_1_en_shift                        (9)
#define  MC_SECURE_MC_mem_display_ctrl_display_0_en_shift                        (8)
#define  MC_SECURE_MC_mem_display_ctrl_gpu_id_mode_mask                          (0xC0000000)
#define  MC_SECURE_MC_mem_display_ctrl_display_15_en_mask                        (0x00800000)
#define  MC_SECURE_MC_mem_display_ctrl_display_14_en_mask                        (0x00400000)
#define  MC_SECURE_MC_mem_display_ctrl_display_13_en_mask                        (0x00200000)
#define  MC_SECURE_MC_mem_display_ctrl_display_12_en_mask                        (0x00100000)
#define  MC_SECURE_MC_mem_display_ctrl_display_11_en_mask                        (0x00080000)
#define  MC_SECURE_MC_mem_display_ctrl_display_10_en_mask                        (0x00040000)
#define  MC_SECURE_MC_mem_display_ctrl_display_9_en_mask                         (0x00020000)
#define  MC_SECURE_MC_mem_display_ctrl_display_8_en_mask                         (0x00010000)
#define  MC_SECURE_MC_mem_display_ctrl_display_7_en_mask                         (0x00008000)
#define  MC_SECURE_MC_mem_display_ctrl_display_6_en_mask                         (0x00004000)
#define  MC_SECURE_MC_mem_display_ctrl_display_5_en_mask                         (0x00002000)
#define  MC_SECURE_MC_mem_display_ctrl_display_4_en_mask                         (0x00001000)
#define  MC_SECURE_MC_mem_display_ctrl_display_3_en_mask                         (0x00000800)
#define  MC_SECURE_MC_mem_display_ctrl_display_2_en_mask                         (0x00000400)
#define  MC_SECURE_MC_mem_display_ctrl_display_1_en_mask                         (0x00000200)
#define  MC_SECURE_MC_mem_display_ctrl_display_0_en_mask                         (0x00000100)
#define  MC_SECURE_MC_mem_display_ctrl_gpu_id_mode(data)                         (0xC0000000&((data)<<30))
#define  MC_SECURE_MC_mem_display_ctrl_display_15_en(data)                       (0x00800000&((data)<<23))
#define  MC_SECURE_MC_mem_display_ctrl_display_14_en(data)                       (0x00400000&((data)<<22))
#define  MC_SECURE_MC_mem_display_ctrl_display_13_en(data)                       (0x00200000&((data)<<21))
#define  MC_SECURE_MC_mem_display_ctrl_display_12_en(data)                       (0x00100000&((data)<<20))
#define  MC_SECURE_MC_mem_display_ctrl_display_11_en(data)                       (0x00080000&((data)<<19))
#define  MC_SECURE_MC_mem_display_ctrl_display_10_en(data)                       (0x00040000&((data)<<18))
#define  MC_SECURE_MC_mem_display_ctrl_display_9_en(data)                        (0x00020000&((data)<<17))
#define  MC_SECURE_MC_mem_display_ctrl_display_8_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_mem_display_ctrl_display_7_en(data)                        (0x00008000&((data)<<15))
#define  MC_SECURE_MC_mem_display_ctrl_display_6_en(data)                        (0x00004000&((data)<<14))
#define  MC_SECURE_MC_mem_display_ctrl_display_5_en(data)                        (0x00002000&((data)<<13))
#define  MC_SECURE_MC_mem_display_ctrl_display_4_en(data)                        (0x00001000&((data)<<12))
#define  MC_SECURE_MC_mem_display_ctrl_display_3_en(data)                        (0x00000800&((data)<<11))
#define  MC_SECURE_MC_mem_display_ctrl_display_2_en(data)                        (0x00000400&((data)<<10))
#define  MC_SECURE_MC_mem_display_ctrl_display_1_en(data)                        (0x00000200&((data)<<9))
#define  MC_SECURE_MC_mem_display_ctrl_display_0_en(data)                        (0x00000100&((data)<<8))
#define  MC_SECURE_MC_mem_display_ctrl_get_gpu_id_mode(data)                     ((0xC0000000&(data))>>30)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_15_en(data)                   ((0x00800000&(data))>>23)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_14_en(data)                   ((0x00400000&(data))>>22)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_13_en(data)                   ((0x00200000&(data))>>21)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_12_en(data)                   ((0x00100000&(data))>>20)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_11_en(data)                   ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_10_en(data)                   ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_9_en(data)                    ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_8_en(data)                    ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_7_en(data)                    ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_6_en(data)                    ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_5_en(data)                    ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_4_en(data)                    ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_3_en(data)                    ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_2_en(data)                    ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_1_en(data)                    ((0x00000200&(data))>>9)
#define  MC_SECURE_MC_mem_display_ctrl_get_display_0_en(data)                    ((0x00000100&(data))>>8)

#define  MC_SECURE_MC_display_start_0                                            0x180B0400
#define  MC_SECURE_MC_display_start_0_reg_addr                                   "0xB80B0400"
#define  MC_SECURE_MC_display_start_0_reg                                        0xB80B0400
#define  MC_SECURE_MC_display_start_0_inst_addr                                  "0x00E4"
#define  set_MC_SECURE_MC_display_start_0_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_0_reg)=data)
#define  get_MC_SECURE_MC_display_start_0_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_0_reg))
#define  MC_SECURE_MC_display_start_0_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_0_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_0_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_0_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_1                                            0x180B0404
#define  MC_SECURE_MC_display_start_1_reg_addr                                   "0xB80B0404"
#define  MC_SECURE_MC_display_start_1_reg                                        0xB80B0404
#define  MC_SECURE_MC_display_start_1_inst_addr                                  "0x00E5"
#define  set_MC_SECURE_MC_display_start_1_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_1_reg)=data)
#define  get_MC_SECURE_MC_display_start_1_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_1_reg))
#define  MC_SECURE_MC_display_start_1_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_1_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_1_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_1_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_2                                            0x180B0408
#define  MC_SECURE_MC_display_start_2_reg_addr                                   "0xB80B0408"
#define  MC_SECURE_MC_display_start_2_reg                                        0xB80B0408
#define  MC_SECURE_MC_display_start_2_inst_addr                                  "0x00E6"
#define  set_MC_SECURE_MC_display_start_2_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_2_reg)=data)
#define  get_MC_SECURE_MC_display_start_2_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_2_reg))
#define  MC_SECURE_MC_display_start_2_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_2_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_2_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_2_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_3                                            0x180B040C
#define  MC_SECURE_MC_display_start_3_reg_addr                                   "0xB80B040C"
#define  MC_SECURE_MC_display_start_3_reg                                        0xB80B040C
#define  MC_SECURE_MC_display_start_3_inst_addr                                  "0x00E7"
#define  set_MC_SECURE_MC_display_start_3_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_3_reg)=data)
#define  get_MC_SECURE_MC_display_start_3_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_3_reg))
#define  MC_SECURE_MC_display_start_3_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_3_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_3_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_3_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_4                                            0x180B0410
#define  MC_SECURE_MC_display_start_4_reg_addr                                   "0xB80B0410"
#define  MC_SECURE_MC_display_start_4_reg                                        0xB80B0410
#define  MC_SECURE_MC_display_start_4_inst_addr                                  "0x00E8"
#define  set_MC_SECURE_MC_display_start_4_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_4_reg)=data)
#define  get_MC_SECURE_MC_display_start_4_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_4_reg))
#define  MC_SECURE_MC_display_start_4_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_4_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_4_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_4_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_5                                            0x180B0414
#define  MC_SECURE_MC_display_start_5_reg_addr                                   "0xB80B0414"
#define  MC_SECURE_MC_display_start_5_reg                                        0xB80B0414
#define  MC_SECURE_MC_display_start_5_inst_addr                                  "0x00E9"
#define  set_MC_SECURE_MC_display_start_5_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_5_reg)=data)
#define  get_MC_SECURE_MC_display_start_5_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_5_reg))
#define  MC_SECURE_MC_display_start_5_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_5_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_5_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_5_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_6                                            0x180B0418
#define  MC_SECURE_MC_display_start_6_reg_addr                                   "0xB80B0418"
#define  MC_SECURE_MC_display_start_6_reg                                        0xB80B0418
#define  MC_SECURE_MC_display_start_6_inst_addr                                  "0x00EA"
#define  set_MC_SECURE_MC_display_start_6_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_6_reg)=data)
#define  get_MC_SECURE_MC_display_start_6_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_6_reg))
#define  MC_SECURE_MC_display_start_6_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_6_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_6_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_6_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_7                                            0x180B041C
#define  MC_SECURE_MC_display_start_7_reg_addr                                   "0xB80B041C"
#define  MC_SECURE_MC_display_start_7_reg                                        0xB80B041C
#define  MC_SECURE_MC_display_start_7_inst_addr                                  "0x00EB"
#define  set_MC_SECURE_MC_display_start_7_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_7_reg)=data)
#define  get_MC_SECURE_MC_display_start_7_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_7_reg))
#define  MC_SECURE_MC_display_start_7_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_7_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_7_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_7_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_8                                            0x180B0420
#define  MC_SECURE_MC_display_start_8_reg_addr                                   "0xB80B0420"
#define  MC_SECURE_MC_display_start_8_reg                                        0xB80B0420
#define  MC_SECURE_MC_display_start_8_inst_addr                                  "0x00EC"
#define  set_MC_SECURE_MC_display_start_8_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_8_reg)=data)
#define  get_MC_SECURE_MC_display_start_8_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_8_reg))
#define  MC_SECURE_MC_display_start_8_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_8_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_8_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_8_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_9                                            0x180B0424
#define  MC_SECURE_MC_display_start_9_reg_addr                                   "0xB80B0424"
#define  MC_SECURE_MC_display_start_9_reg                                        0xB80B0424
#define  MC_SECURE_MC_display_start_9_inst_addr                                  "0x00ED"
#define  set_MC_SECURE_MC_display_start_9_reg(data)                              (*((volatile unsigned int*)MC_SECURE_MC_display_start_9_reg)=data)
#define  get_MC_SECURE_MC_display_start_9_reg                                    (*((volatile unsigned int*)MC_SECURE_MC_display_start_9_reg))
#define  MC_SECURE_MC_display_start_9_addr_shift                                 (12)
#define  MC_SECURE_MC_display_start_9_addr_mask                                  (0xFFFFF000)
#define  MC_SECURE_MC_display_start_9_addr(data)                                 (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_9_get_addr(data)                             ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_10                                           0x180B0428
#define  MC_SECURE_MC_display_start_10_reg_addr                                  "0xB80B0428"
#define  MC_SECURE_MC_display_start_10_reg                                       0xB80B0428
#define  MC_SECURE_MC_display_start_10_inst_addr                                 "0x00EE"
#define  set_MC_SECURE_MC_display_start_10_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_display_start_10_reg)=data)
#define  get_MC_SECURE_MC_display_start_10_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_display_start_10_reg))
#define  MC_SECURE_MC_display_start_10_addr_shift                                (12)
#define  MC_SECURE_MC_display_start_10_addr_mask                                 (0xFFFFF000)
#define  MC_SECURE_MC_display_start_10_addr(data)                                (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_10_get_addr(data)                            ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_11                                           0x180B042C
#define  MC_SECURE_MC_display_start_11_reg_addr                                  "0xB80B042C"
#define  MC_SECURE_MC_display_start_11_reg                                       0xB80B042C
#define  MC_SECURE_MC_display_start_11_inst_addr                                 "0x00EF"
#define  set_MC_SECURE_MC_display_start_11_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_display_start_11_reg)=data)
#define  get_MC_SECURE_MC_display_start_11_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_display_start_11_reg))
#define  MC_SECURE_MC_display_start_11_addr_shift                                (12)
#define  MC_SECURE_MC_display_start_11_addr_mask                                 (0xFFFFF000)
#define  MC_SECURE_MC_display_start_11_addr(data)                                (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_11_get_addr(data)                            ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_12                                           0x180B0430
#define  MC_SECURE_MC_display_start_12_reg_addr                                  "0xB80B0430"
#define  MC_SECURE_MC_display_start_12_reg                                       0xB80B0430
#define  MC_SECURE_MC_display_start_12_inst_addr                                 "0x00F0"
#define  set_MC_SECURE_MC_display_start_12_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_display_start_12_reg)=data)
#define  get_MC_SECURE_MC_display_start_12_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_display_start_12_reg))
#define  MC_SECURE_MC_display_start_12_addr_shift                                (12)
#define  MC_SECURE_MC_display_start_12_addr_mask                                 (0xFFFFF000)
#define  MC_SECURE_MC_display_start_12_addr(data)                                (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_12_get_addr(data)                            ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_13                                           0x180B0434
#define  MC_SECURE_MC_display_start_13_reg_addr                                  "0xB80B0434"
#define  MC_SECURE_MC_display_start_13_reg                                       0xB80B0434
#define  MC_SECURE_MC_display_start_13_inst_addr                                 "0x00F1"
#define  set_MC_SECURE_MC_display_start_13_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_display_start_13_reg)=data)
#define  get_MC_SECURE_MC_display_start_13_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_display_start_13_reg))
#define  MC_SECURE_MC_display_start_13_addr_shift                                (12)
#define  MC_SECURE_MC_display_start_13_addr_mask                                 (0xFFFFF000)
#define  MC_SECURE_MC_display_start_13_addr(data)                                (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_13_get_addr(data)                            ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_14                                           0x180B0438
#define  MC_SECURE_MC_display_start_14_reg_addr                                  "0xB80B0438"
#define  MC_SECURE_MC_display_start_14_reg                                       0xB80B0438
#define  MC_SECURE_MC_display_start_14_inst_addr                                 "0x00F2"
#define  set_MC_SECURE_MC_display_start_14_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_display_start_14_reg)=data)
#define  get_MC_SECURE_MC_display_start_14_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_display_start_14_reg))
#define  MC_SECURE_MC_display_start_14_addr_shift                                (12)
#define  MC_SECURE_MC_display_start_14_addr_mask                                 (0xFFFFF000)
#define  MC_SECURE_MC_display_start_14_addr(data)                                (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_14_get_addr(data)                            ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_start_15                                           0x180B043C
#define  MC_SECURE_MC_display_start_15_reg_addr                                  "0xB80B043C"
#define  MC_SECURE_MC_display_start_15_reg                                       0xB80B043C
#define  MC_SECURE_MC_display_start_15_inst_addr                                 "0x00F3"
#define  set_MC_SECURE_MC_display_start_15_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_display_start_15_reg)=data)
#define  get_MC_SECURE_MC_display_start_15_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_display_start_15_reg))
#define  MC_SECURE_MC_display_start_15_addr_shift                                (12)
#define  MC_SECURE_MC_display_start_15_addr_mask                                 (0xFFFFF000)
#define  MC_SECURE_MC_display_start_15_addr(data)                                (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_start_15_get_addr(data)                            ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_0                                              0x180B0440
#define  MC_SECURE_MC_display_end_0_reg_addr                                     "0xB80B0440"
#define  MC_SECURE_MC_display_end_0_reg                                          0xB80B0440
#define  MC_SECURE_MC_display_end_0_inst_addr                                    "0x00F4"
#define  set_MC_SECURE_MC_display_end_0_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_0_reg)=data)
#define  get_MC_SECURE_MC_display_end_0_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_0_reg))
#define  MC_SECURE_MC_display_end_0_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_0_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_0_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_0_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_1                                              0x180B0444
#define  MC_SECURE_MC_display_end_1_reg_addr                                     "0xB80B0444"
#define  MC_SECURE_MC_display_end_1_reg                                          0xB80B0444
#define  MC_SECURE_MC_display_end_1_inst_addr                                    "0x00F5"
#define  set_MC_SECURE_MC_display_end_1_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_1_reg)=data)
#define  get_MC_SECURE_MC_display_end_1_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_1_reg))
#define  MC_SECURE_MC_display_end_1_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_1_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_1_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_1_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_2                                              0x180B0448
#define  MC_SECURE_MC_display_end_2_reg_addr                                     "0xB80B0448"
#define  MC_SECURE_MC_display_end_2_reg                                          0xB80B0448
#define  MC_SECURE_MC_display_end_2_inst_addr                                    "0x00F6"
#define  set_MC_SECURE_MC_display_end_2_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_2_reg)=data)
#define  get_MC_SECURE_MC_display_end_2_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_2_reg))
#define  MC_SECURE_MC_display_end_2_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_2_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_2_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_2_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_3                                              0x180B044C
#define  MC_SECURE_MC_display_end_3_reg_addr                                     "0xB80B044C"
#define  MC_SECURE_MC_display_end_3_reg                                          0xB80B044C
#define  MC_SECURE_MC_display_end_3_inst_addr                                    "0x00F7"
#define  set_MC_SECURE_MC_display_end_3_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_3_reg)=data)
#define  get_MC_SECURE_MC_display_end_3_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_3_reg))
#define  MC_SECURE_MC_display_end_3_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_3_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_3_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_3_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_4                                              0x180B0450
#define  MC_SECURE_MC_display_end_4_reg_addr                                     "0xB80B0450"
#define  MC_SECURE_MC_display_end_4_reg                                          0xB80B0450
#define  MC_SECURE_MC_display_end_4_inst_addr                                    "0x00F8"
#define  set_MC_SECURE_MC_display_end_4_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_4_reg)=data)
#define  get_MC_SECURE_MC_display_end_4_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_4_reg))
#define  MC_SECURE_MC_display_end_4_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_4_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_4_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_4_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_5                                              0x180B0454
#define  MC_SECURE_MC_display_end_5_reg_addr                                     "0xB80B0454"
#define  MC_SECURE_MC_display_end_5_reg                                          0xB80B0454
#define  MC_SECURE_MC_display_end_5_inst_addr                                    "0x00F9"
#define  set_MC_SECURE_MC_display_end_5_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_5_reg)=data)
#define  get_MC_SECURE_MC_display_end_5_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_5_reg))
#define  MC_SECURE_MC_display_end_5_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_5_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_5_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_5_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_6                                              0x180B0458
#define  MC_SECURE_MC_display_end_6_reg_addr                                     "0xB80B0458"
#define  MC_SECURE_MC_display_end_6_reg                                          0xB80B0458
#define  MC_SECURE_MC_display_end_6_inst_addr                                    "0x00FA"
#define  set_MC_SECURE_MC_display_end_6_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_6_reg)=data)
#define  get_MC_SECURE_MC_display_end_6_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_6_reg))
#define  MC_SECURE_MC_display_end_6_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_6_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_6_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_6_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_7                                              0x180B045C
#define  MC_SECURE_MC_display_end_7_reg_addr                                     "0xB80B045C"
#define  MC_SECURE_MC_display_end_7_reg                                          0xB80B045C
#define  MC_SECURE_MC_display_end_7_inst_addr                                    "0x00FB"
#define  set_MC_SECURE_MC_display_end_7_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_7_reg)=data)
#define  get_MC_SECURE_MC_display_end_7_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_7_reg))
#define  MC_SECURE_MC_display_end_7_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_7_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_7_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_7_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_8                                              0x180B0460
#define  MC_SECURE_MC_display_end_8_reg_addr                                     "0xB80B0460"
#define  MC_SECURE_MC_display_end_8_reg                                          0xB80B0460
#define  MC_SECURE_MC_display_end_8_inst_addr                                    "0x00FC"
#define  set_MC_SECURE_MC_display_end_8_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_8_reg)=data)
#define  get_MC_SECURE_MC_display_end_8_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_8_reg))
#define  MC_SECURE_MC_display_end_8_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_8_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_8_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_8_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_9                                              0x180B0464
#define  MC_SECURE_MC_display_end_9_reg_addr                                     "0xB80B0464"
#define  MC_SECURE_MC_display_end_9_reg                                          0xB80B0464
#define  MC_SECURE_MC_display_end_9_inst_addr                                    "0x00FD"
#define  set_MC_SECURE_MC_display_end_9_reg(data)                                (*((volatile unsigned int*)MC_SECURE_MC_display_end_9_reg)=data)
#define  get_MC_SECURE_MC_display_end_9_reg                                      (*((volatile unsigned int*)MC_SECURE_MC_display_end_9_reg))
#define  MC_SECURE_MC_display_end_9_addr_shift                                   (12)
#define  MC_SECURE_MC_display_end_9_addr_mask                                    (0xFFFFF000)
#define  MC_SECURE_MC_display_end_9_addr(data)                                   (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_9_get_addr(data)                               ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_10                                             0x180B0468
#define  MC_SECURE_MC_display_end_10_reg_addr                                    "0xB80B0468"
#define  MC_SECURE_MC_display_end_10_reg                                         0xB80B0468
#define  MC_SECURE_MC_display_end_10_inst_addr                                   "0x00FE"
#define  set_MC_SECURE_MC_display_end_10_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_display_end_10_reg)=data)
#define  get_MC_SECURE_MC_display_end_10_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_display_end_10_reg))
#define  MC_SECURE_MC_display_end_10_addr_shift                                  (12)
#define  MC_SECURE_MC_display_end_10_addr_mask                                   (0xFFFFF000)
#define  MC_SECURE_MC_display_end_10_addr(data)                                  (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_10_get_addr(data)                              ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_11                                             0x180B046C
#define  MC_SECURE_MC_display_end_11_reg_addr                                    "0xB80B046C"
#define  MC_SECURE_MC_display_end_11_reg                                         0xB80B046C
#define  MC_SECURE_MC_display_end_11_inst_addr                                   "0x00FF"
#define  set_MC_SECURE_MC_display_end_11_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_display_end_11_reg)=data)
#define  get_MC_SECURE_MC_display_end_11_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_display_end_11_reg))
#define  MC_SECURE_MC_display_end_11_addr_shift                                  (12)
#define  MC_SECURE_MC_display_end_11_addr_mask                                   (0xFFFFF000)
#define  MC_SECURE_MC_display_end_11_addr(data)                                  (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_11_get_addr(data)                              ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_12                                             0x180B0470
#define  MC_SECURE_MC_display_end_12_reg_addr                                    "0xB80B0470"
#define  MC_SECURE_MC_display_end_12_reg                                         0xB80B0470
#define  MC_SECURE_MC_display_end_12_inst_addr                                   "0x0100"
#define  set_MC_SECURE_MC_display_end_12_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_display_end_12_reg)=data)
#define  get_MC_SECURE_MC_display_end_12_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_display_end_12_reg))
#define  MC_SECURE_MC_display_end_12_addr_shift                                  (12)
#define  MC_SECURE_MC_display_end_12_addr_mask                                   (0xFFFFF000)
#define  MC_SECURE_MC_display_end_12_addr(data)                                  (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_12_get_addr(data)                              ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_13                                             0x180B0474
#define  MC_SECURE_MC_display_end_13_reg_addr                                    "0xB80B0474"
#define  MC_SECURE_MC_display_end_13_reg                                         0xB80B0474
#define  MC_SECURE_MC_display_end_13_inst_addr                                   "0x0101"
#define  set_MC_SECURE_MC_display_end_13_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_display_end_13_reg)=data)
#define  get_MC_SECURE_MC_display_end_13_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_display_end_13_reg))
#define  MC_SECURE_MC_display_end_13_addr_shift                                  (12)
#define  MC_SECURE_MC_display_end_13_addr_mask                                   (0xFFFFF000)
#define  MC_SECURE_MC_display_end_13_addr(data)                                  (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_13_get_addr(data)                              ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_14                                             0x180B0478
#define  MC_SECURE_MC_display_end_14_reg_addr                                    "0xB80B0478"
#define  MC_SECURE_MC_display_end_14_reg                                         0xB80B0478
#define  MC_SECURE_MC_display_end_14_inst_addr                                   "0x0102"
#define  set_MC_SECURE_MC_display_end_14_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_display_end_14_reg)=data)
#define  get_MC_SECURE_MC_display_end_14_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_display_end_14_reg))
#define  MC_SECURE_MC_display_end_14_addr_shift                                  (12)
#define  MC_SECURE_MC_display_end_14_addr_mask                                   (0xFFFFF000)
#define  MC_SECURE_MC_display_end_14_addr(data)                                  (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_14_get_addr(data)                              ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_end_15                                             0x180B047C
#define  MC_SECURE_MC_display_end_15_reg_addr                                    "0xB80B047C"
#define  MC_SECURE_MC_display_end_15_reg                                         0xB80B047C
#define  MC_SECURE_MC_display_end_15_inst_addr                                   "0x0103"
#define  set_MC_SECURE_MC_display_end_15_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_display_end_15_reg)=data)
#define  get_MC_SECURE_MC_display_end_15_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_display_end_15_reg))
#define  MC_SECURE_MC_display_end_15_addr_shift                                  (12)
#define  MC_SECURE_MC_display_end_15_addr_mask                                   (0xFFFFF000)
#define  MC_SECURE_MC_display_end_15_addr(data)                                  (0xFFFFF000&((data)<<12))
#define  MC_SECURE_MC_display_end_15_get_addr(data)                              ((0xFFFFF000&(data))>>12)

#define  MC_SECURE_MC_display_access_r_0                                         0x180B0480
#define  MC_SECURE_MC_display_access_r_0_reg_addr                                "0xB80B0480"
#define  MC_SECURE_MC_display_access_r_0_reg                                     0xB80B0480
#define  MC_SECURE_MC_display_access_r_0_inst_addr                               "0x0104"
#define  set_MC_SECURE_MC_display_access_r_0_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_0_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_0_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_0_reg))
#define  MC_SECURE_MC_display_access_r_0_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_0_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_0_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_0_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_0_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_0_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_0_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_0_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_0_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_0_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_0_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_0_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_0_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_0_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_0_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_0_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_0_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_0_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_0_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_0_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_0_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_0_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_0_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_0_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_0_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_0_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_0_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_0_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_0_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_0_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_0_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_0_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_0_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_0_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_0_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_0_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_0_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_0_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_0_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_0_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_0_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_0_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_0_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_0_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_0_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_0_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_0_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_0_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_0_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_0_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_0_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_0_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_0_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_0_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_0_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_0_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_0_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_0_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_0_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_0_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_0_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_0_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_0_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_0_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_1                                         0x180B0484
#define  MC_SECURE_MC_display_access_r_1_reg_addr                                "0xB80B0484"
#define  MC_SECURE_MC_display_access_r_1_reg                                     0xB80B0484
#define  MC_SECURE_MC_display_access_r_1_inst_addr                               "0x0105"
#define  set_MC_SECURE_MC_display_access_r_1_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_1_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_1_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_1_reg))
#define  MC_SECURE_MC_display_access_r_1_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_1_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_1_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_1_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_1_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_1_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_1_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_1_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_1_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_1_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_1_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_1_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_1_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_1_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_1_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_1_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_1_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_1_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_1_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_1_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_1_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_1_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_1_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_1_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_1_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_1_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_1_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_1_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_1_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_1_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_1_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_1_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_1_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_1_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_1_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_1_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_1_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_1_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_1_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_1_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_1_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_1_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_1_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_1_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_1_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_1_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_1_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_1_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_1_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_1_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_1_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_1_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_1_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_1_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_1_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_1_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_1_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_1_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_1_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_1_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_1_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_1_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_1_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_1_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_2                                         0x180B0488
#define  MC_SECURE_MC_display_access_r_2_reg_addr                                "0xB80B0488"
#define  MC_SECURE_MC_display_access_r_2_reg                                     0xB80B0488
#define  MC_SECURE_MC_display_access_r_2_inst_addr                               "0x0106"
#define  set_MC_SECURE_MC_display_access_r_2_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_2_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_2_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_2_reg))
#define  MC_SECURE_MC_display_access_r_2_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_2_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_2_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_2_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_2_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_2_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_2_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_2_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_2_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_2_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_2_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_2_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_2_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_2_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_2_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_2_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_2_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_2_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_2_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_2_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_2_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_2_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_2_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_2_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_2_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_2_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_2_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_2_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_2_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_2_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_2_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_2_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_2_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_2_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_2_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_2_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_2_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_2_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_2_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_2_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_2_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_2_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_2_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_2_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_2_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_2_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_2_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_2_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_2_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_2_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_2_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_2_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_2_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_2_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_2_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_2_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_2_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_2_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_2_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_2_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_2_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_2_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_2_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_2_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_3                                         0x180B048C
#define  MC_SECURE_MC_display_access_r_3_reg_addr                                "0xB80B048C"
#define  MC_SECURE_MC_display_access_r_3_reg                                     0xB80B048C
#define  MC_SECURE_MC_display_access_r_3_inst_addr                               "0x0107"
#define  set_MC_SECURE_MC_display_access_r_3_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_3_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_3_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_3_reg))
#define  MC_SECURE_MC_display_access_r_3_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_3_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_3_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_3_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_3_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_3_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_3_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_3_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_3_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_3_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_3_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_3_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_3_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_3_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_3_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_3_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_3_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_3_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_3_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_3_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_3_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_3_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_3_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_3_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_3_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_3_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_3_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_3_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_3_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_3_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_3_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_3_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_3_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_3_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_3_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_3_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_3_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_3_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_3_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_3_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_3_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_3_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_3_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_3_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_3_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_3_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_3_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_3_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_3_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_3_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_3_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_3_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_3_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_3_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_3_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_3_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_3_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_3_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_3_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_3_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_3_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_3_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_3_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_3_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_4                                         0x180B0490
#define  MC_SECURE_MC_display_access_r_4_reg_addr                                "0xB80B0490"
#define  MC_SECURE_MC_display_access_r_4_reg                                     0xB80B0490
#define  MC_SECURE_MC_display_access_r_4_inst_addr                               "0x0108"
#define  set_MC_SECURE_MC_display_access_r_4_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_4_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_4_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_4_reg))
#define  MC_SECURE_MC_display_access_r_4_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_4_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_4_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_4_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_4_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_4_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_4_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_4_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_4_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_4_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_4_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_4_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_4_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_4_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_4_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_4_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_4_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_4_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_4_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_4_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_4_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_4_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_4_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_4_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_4_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_4_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_4_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_4_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_4_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_4_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_4_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_4_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_4_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_4_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_4_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_4_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_4_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_4_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_4_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_4_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_4_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_4_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_4_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_4_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_4_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_4_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_4_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_4_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_4_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_4_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_4_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_4_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_4_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_4_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_4_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_4_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_4_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_4_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_4_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_4_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_4_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_4_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_4_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_4_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_5                                         0x180B0494
#define  MC_SECURE_MC_display_access_r_5_reg_addr                                "0xB80B0494"
#define  MC_SECURE_MC_display_access_r_5_reg                                     0xB80B0494
#define  MC_SECURE_MC_display_access_r_5_inst_addr                               "0x0109"
#define  set_MC_SECURE_MC_display_access_r_5_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_5_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_5_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_5_reg))
#define  MC_SECURE_MC_display_access_r_5_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_5_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_5_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_5_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_5_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_5_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_5_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_5_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_5_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_5_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_5_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_5_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_5_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_5_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_5_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_5_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_5_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_5_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_5_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_5_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_5_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_5_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_5_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_5_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_5_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_5_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_5_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_5_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_5_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_5_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_5_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_5_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_5_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_5_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_5_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_5_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_5_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_5_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_5_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_5_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_5_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_5_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_5_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_5_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_5_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_5_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_5_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_5_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_5_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_5_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_5_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_5_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_5_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_5_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_5_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_5_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_5_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_5_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_5_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_5_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_5_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_5_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_5_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_5_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_6                                         0x180B0498
#define  MC_SECURE_MC_display_access_r_6_reg_addr                                "0xB80B0498"
#define  MC_SECURE_MC_display_access_r_6_reg                                     0xB80B0498
#define  MC_SECURE_MC_display_access_r_6_inst_addr                               "0x010A"
#define  set_MC_SECURE_MC_display_access_r_6_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_6_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_6_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_6_reg))
#define  MC_SECURE_MC_display_access_r_6_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_6_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_6_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_6_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_6_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_6_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_6_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_6_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_6_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_6_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_6_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_6_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_6_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_6_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_6_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_6_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_6_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_6_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_6_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_6_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_6_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_6_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_6_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_6_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_6_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_6_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_6_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_6_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_6_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_6_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_6_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_6_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_6_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_6_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_6_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_6_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_6_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_6_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_6_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_6_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_6_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_6_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_6_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_6_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_6_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_6_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_6_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_6_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_6_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_6_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_6_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_6_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_6_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_6_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_6_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_6_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_6_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_6_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_6_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_6_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_6_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_6_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_6_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_6_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_7                                         0x180B049C
#define  MC_SECURE_MC_display_access_r_7_reg_addr                                "0xB80B049C"
#define  MC_SECURE_MC_display_access_r_7_reg                                     0xB80B049C
#define  MC_SECURE_MC_display_access_r_7_inst_addr                               "0x010B"
#define  set_MC_SECURE_MC_display_access_r_7_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_7_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_7_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_7_reg))
#define  MC_SECURE_MC_display_access_r_7_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_7_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_7_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_7_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_7_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_7_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_7_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_7_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_7_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_7_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_7_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_7_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_7_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_7_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_7_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_7_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_7_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_7_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_7_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_7_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_7_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_7_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_7_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_7_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_7_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_7_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_7_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_7_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_7_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_7_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_7_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_7_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_7_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_7_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_7_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_7_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_7_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_7_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_7_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_7_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_7_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_7_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_7_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_7_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_7_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_7_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_7_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_7_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_7_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_7_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_7_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_7_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_7_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_7_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_7_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_7_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_7_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_7_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_7_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_7_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_7_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_7_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_7_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_7_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_8                                         0x180B04A0
#define  MC_SECURE_MC_display_access_r_8_reg_addr                                "0xB80B04A0"
#define  MC_SECURE_MC_display_access_r_8_reg                                     0xB80B04A0
#define  MC_SECURE_MC_display_access_r_8_inst_addr                               "0x010C"
#define  set_MC_SECURE_MC_display_access_r_8_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_8_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_8_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_8_reg))
#define  MC_SECURE_MC_display_access_r_8_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_8_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_8_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_8_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_8_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_8_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_8_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_8_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_8_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_8_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_8_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_8_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_8_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_8_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_8_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_8_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_8_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_8_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_8_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_8_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_8_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_8_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_8_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_8_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_8_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_8_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_8_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_8_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_8_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_8_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_8_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_8_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_8_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_8_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_8_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_8_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_8_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_8_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_8_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_8_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_8_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_8_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_8_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_8_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_8_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_8_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_8_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_8_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_8_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_8_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_8_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_8_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_8_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_8_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_8_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_8_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_8_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_8_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_8_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_8_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_8_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_8_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_8_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_8_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_9                                         0x180B04A4
#define  MC_SECURE_MC_display_access_r_9_reg_addr                                "0xB80B04A4"
#define  MC_SECURE_MC_display_access_r_9_reg                                     0xB80B04A4
#define  MC_SECURE_MC_display_access_r_9_inst_addr                               "0x010D"
#define  set_MC_SECURE_MC_display_access_r_9_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_9_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_9_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_9_reg))
#define  MC_SECURE_MC_display_access_r_9_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_r_9_se_shift                                (24)
#define  MC_SECURE_MC_display_access_r_9_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_r_9_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_r_9_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_r_9_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_r_9_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_r_9_me_shift                                (11)
#define  MC_SECURE_MC_display_access_r_9_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_r_9_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_r_9_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_r_9_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_r_9_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_r_9_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_r_9_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_r_9_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_r_9_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_r_9_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_r_9_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_9_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_r_9_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_r_9_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_r_9_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_r_9_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_r_9_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_r_9_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_r_9_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_r_9_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_r_9_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_r_9_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_r_9_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_r_9_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_r_9_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_9_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_9_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_9_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_9_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_9_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_9_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_9_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_9_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_9_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_9_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_9_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_9_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_9_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_9_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_9_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_9_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_9_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_9_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_9_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_9_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_9_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_9_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_9_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_9_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_9_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_9_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_9_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_9_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_9_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_9_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_9_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_10                                        0x180B04A8
#define  MC_SECURE_MC_display_access_r_10_reg_addr                               "0xB80B04A8"
#define  MC_SECURE_MC_display_access_r_10_reg                                    0xB80B04A8
#define  MC_SECURE_MC_display_access_r_10_inst_addr                              "0x010E"
#define  set_MC_SECURE_MC_display_access_r_10_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_10_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_10_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_10_reg))
#define  MC_SECURE_MC_display_access_r_10_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_r_10_se_shift                               (24)
#define  MC_SECURE_MC_display_access_r_10_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_r_10_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_r_10_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_r_10_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_r_10_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_r_10_me_shift                               (11)
#define  MC_SECURE_MC_display_access_r_10_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_r_10_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_r_10_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_r_10_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_r_10_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_r_10_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_r_10_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_r_10_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_r_10_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_r_10_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_r_10_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_10_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_r_10_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_r_10_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_r_10_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_r_10_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_r_10_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_r_10_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_r_10_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_r_10_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_r_10_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_r_10_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_r_10_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_r_10_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_r_10_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_10_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_10_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_10_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_10_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_10_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_10_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_10_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_10_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_10_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_10_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_10_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_10_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_10_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_10_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_10_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_10_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_10_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_10_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_10_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_10_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_10_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_10_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_10_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_10_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_10_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_10_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_10_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_10_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_10_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_10_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_10_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_11                                        0x180B04AC
#define  MC_SECURE_MC_display_access_r_11_reg_addr                               "0xB80B04AC"
#define  MC_SECURE_MC_display_access_r_11_reg                                    0xB80B04AC
#define  MC_SECURE_MC_display_access_r_11_inst_addr                              "0x010F"
#define  set_MC_SECURE_MC_display_access_r_11_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_11_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_11_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_11_reg))
#define  MC_SECURE_MC_display_access_r_11_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_r_11_se_shift                               (24)
#define  MC_SECURE_MC_display_access_r_11_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_r_11_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_r_11_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_r_11_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_r_11_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_r_11_me_shift                               (11)
#define  MC_SECURE_MC_display_access_r_11_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_r_11_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_r_11_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_r_11_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_r_11_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_r_11_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_r_11_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_r_11_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_r_11_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_r_11_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_r_11_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_11_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_r_11_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_r_11_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_r_11_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_r_11_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_r_11_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_r_11_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_r_11_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_r_11_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_r_11_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_r_11_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_r_11_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_r_11_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_r_11_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_11_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_11_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_11_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_11_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_11_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_11_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_11_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_11_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_11_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_11_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_11_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_11_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_11_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_11_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_11_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_11_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_11_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_11_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_11_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_11_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_11_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_11_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_11_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_11_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_11_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_11_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_11_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_11_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_11_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_11_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_11_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_12                                        0x180B04B0
#define  MC_SECURE_MC_display_access_r_12_reg_addr                               "0xB80B04B0"
#define  MC_SECURE_MC_display_access_r_12_reg                                    0xB80B04B0
#define  MC_SECURE_MC_display_access_r_12_inst_addr                              "0x0110"
#define  set_MC_SECURE_MC_display_access_r_12_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_12_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_12_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_12_reg))
#define  MC_SECURE_MC_display_access_r_12_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_r_12_se_shift                               (24)
#define  MC_SECURE_MC_display_access_r_12_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_r_12_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_r_12_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_r_12_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_r_12_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_r_12_me_shift                               (11)
#define  MC_SECURE_MC_display_access_r_12_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_r_12_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_r_12_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_r_12_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_r_12_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_r_12_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_r_12_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_r_12_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_r_12_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_r_12_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_r_12_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_12_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_r_12_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_r_12_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_r_12_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_r_12_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_r_12_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_r_12_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_r_12_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_r_12_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_r_12_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_r_12_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_r_12_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_r_12_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_r_12_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_12_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_12_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_12_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_12_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_12_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_12_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_12_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_12_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_12_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_12_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_12_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_12_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_12_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_12_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_12_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_12_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_12_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_12_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_12_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_12_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_12_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_12_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_12_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_12_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_12_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_12_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_12_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_12_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_12_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_12_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_12_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_13                                        0x180B04B4
#define  MC_SECURE_MC_display_access_r_13_reg_addr                               "0xB80B04B4"
#define  MC_SECURE_MC_display_access_r_13_reg                                    0xB80B04B4
#define  MC_SECURE_MC_display_access_r_13_inst_addr                              "0x0111"
#define  set_MC_SECURE_MC_display_access_r_13_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_13_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_13_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_13_reg))
#define  MC_SECURE_MC_display_access_r_13_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_r_13_se_shift                               (24)
#define  MC_SECURE_MC_display_access_r_13_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_r_13_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_r_13_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_r_13_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_r_13_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_r_13_me_shift                               (11)
#define  MC_SECURE_MC_display_access_r_13_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_r_13_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_r_13_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_r_13_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_r_13_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_r_13_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_r_13_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_r_13_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_r_13_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_r_13_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_r_13_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_13_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_r_13_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_r_13_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_r_13_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_r_13_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_r_13_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_r_13_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_r_13_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_r_13_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_r_13_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_r_13_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_r_13_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_r_13_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_r_13_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_13_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_13_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_13_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_13_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_13_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_13_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_13_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_13_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_13_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_13_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_13_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_13_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_13_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_13_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_13_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_13_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_13_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_13_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_13_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_13_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_13_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_13_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_13_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_13_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_13_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_13_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_13_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_13_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_13_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_13_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_13_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_14                                        0x180B04B8
#define  MC_SECURE_MC_display_access_r_14_reg_addr                               "0xB80B04B8"
#define  MC_SECURE_MC_display_access_r_14_reg                                    0xB80B04B8
#define  MC_SECURE_MC_display_access_r_14_inst_addr                              "0x0112"
#define  set_MC_SECURE_MC_display_access_r_14_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_14_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_14_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_14_reg))
#define  MC_SECURE_MC_display_access_r_14_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_r_14_se_shift                               (24)
#define  MC_SECURE_MC_display_access_r_14_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_r_14_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_r_14_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_r_14_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_r_14_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_r_14_me_shift                               (11)
#define  MC_SECURE_MC_display_access_r_14_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_r_14_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_r_14_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_r_14_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_r_14_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_r_14_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_r_14_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_r_14_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_r_14_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_r_14_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_r_14_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_14_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_r_14_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_r_14_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_r_14_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_r_14_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_r_14_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_r_14_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_r_14_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_r_14_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_r_14_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_r_14_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_r_14_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_r_14_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_r_14_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_14_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_14_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_14_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_14_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_14_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_14_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_14_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_14_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_14_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_14_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_14_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_14_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_14_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_14_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_14_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_14_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_14_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_14_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_14_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_14_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_14_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_14_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_14_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_14_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_14_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_14_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_14_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_14_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_14_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_14_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_14_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_r_15                                        0x180B04BC
#define  MC_SECURE_MC_display_access_r_15_reg_addr                               "0xB80B04BC"
#define  MC_SECURE_MC_display_access_r_15_reg                                    0xB80B04BC
#define  MC_SECURE_MC_display_access_r_15_inst_addr                              "0x0113"
#define  set_MC_SECURE_MC_display_access_r_15_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_15_reg)=data)
#define  get_MC_SECURE_MC_display_access_r_15_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_r_15_reg))
#define  MC_SECURE_MC_display_access_r_15_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_r_15_se_shift                               (24)
#define  MC_SECURE_MC_display_access_r_15_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_r_15_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_r_15_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_r_15_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_r_15_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_r_15_me_shift                               (11)
#define  MC_SECURE_MC_display_access_r_15_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_r_15_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_r_15_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_r_15_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_r_15_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_r_15_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_r_15_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_r_15_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_r_15_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_r_15_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_r_15_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_r_15_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_r_15_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_r_15_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_r_15_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_r_15_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_r_15_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_r_15_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_r_15_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_r_15_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_r_15_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_r_15_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_r_15_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_r_15_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_r_15_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_r_15_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_r_15_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_r_15_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_r_15_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_r_15_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_r_15_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_r_15_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_r_15_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_r_15_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_r_15_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_r_15_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_r_15_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_r_15_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_r_15_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_r_15_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_r_15_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_r_15_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_r_15_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_r_15_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_r_15_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_r_15_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_r_15_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_r_15_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_r_15_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_r_15_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_r_15_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_r_15_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_r_15_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_r_15_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_r_15_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_r_15_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_0                                         0x180B04C0
#define  MC_SECURE_MC_display_access_w_0_reg_addr                                "0xB80B04C0"
#define  MC_SECURE_MC_display_access_w_0_reg                                     0xB80B04C0
#define  MC_SECURE_MC_display_access_w_0_inst_addr                               "0x0114"
#define  set_MC_SECURE_MC_display_access_w_0_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_0_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_0_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_0_reg))
#define  MC_SECURE_MC_display_access_w_0_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_0_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_0_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_0_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_0_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_0_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_0_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_0_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_0_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_0_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_0_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_0_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_0_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_0_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_0_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_0_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_0_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_0_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_0_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_0_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_0_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_0_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_0_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_0_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_0_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_0_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_0_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_0_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_0_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_0_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_0_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_0_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_0_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_0_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_0_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_0_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_0_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_0_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_0_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_0_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_0_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_0_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_0_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_0_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_0_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_0_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_0_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_0_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_0_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_0_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_0_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_0_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_0_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_0_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_0_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_0_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_0_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_0_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_0_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_0_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_0_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_0_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_0_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_0_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_1                                         0x180B04C4
#define  MC_SECURE_MC_display_access_w_1_reg_addr                                "0xB80B04C4"
#define  MC_SECURE_MC_display_access_w_1_reg                                     0xB80B04C4
#define  MC_SECURE_MC_display_access_w_1_inst_addr                               "0x0115"
#define  set_MC_SECURE_MC_display_access_w_1_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_1_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_1_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_1_reg))
#define  MC_SECURE_MC_display_access_w_1_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_1_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_1_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_1_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_1_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_1_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_1_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_1_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_1_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_1_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_1_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_1_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_1_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_1_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_1_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_1_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_1_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_1_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_1_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_1_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_1_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_1_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_1_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_1_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_1_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_1_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_1_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_1_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_1_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_1_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_1_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_1_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_1_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_1_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_1_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_1_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_1_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_1_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_1_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_1_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_1_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_1_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_1_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_1_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_1_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_1_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_1_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_1_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_1_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_1_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_1_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_1_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_1_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_1_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_1_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_1_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_1_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_1_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_1_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_1_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_1_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_1_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_1_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_1_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_2                                         0x180B04C8
#define  MC_SECURE_MC_display_access_w_2_reg_addr                                "0xB80B04C8"
#define  MC_SECURE_MC_display_access_w_2_reg                                     0xB80B04C8
#define  MC_SECURE_MC_display_access_w_2_inst_addr                               "0x0116"
#define  set_MC_SECURE_MC_display_access_w_2_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_2_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_2_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_2_reg))
#define  MC_SECURE_MC_display_access_w_2_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_2_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_2_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_2_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_2_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_2_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_2_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_2_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_2_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_2_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_2_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_2_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_2_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_2_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_2_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_2_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_2_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_2_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_2_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_2_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_2_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_2_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_2_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_2_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_2_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_2_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_2_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_2_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_2_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_2_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_2_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_2_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_2_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_2_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_2_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_2_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_2_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_2_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_2_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_2_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_2_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_2_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_2_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_2_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_2_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_2_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_2_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_2_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_2_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_2_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_2_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_2_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_2_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_2_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_2_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_2_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_2_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_2_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_2_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_2_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_2_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_2_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_2_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_2_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_3                                         0x180B04CC
#define  MC_SECURE_MC_display_access_w_3_reg_addr                                "0xB80B04CC"
#define  MC_SECURE_MC_display_access_w_3_reg                                     0xB80B04CC
#define  MC_SECURE_MC_display_access_w_3_inst_addr                               "0x0117"
#define  set_MC_SECURE_MC_display_access_w_3_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_3_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_3_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_3_reg))
#define  MC_SECURE_MC_display_access_w_3_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_3_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_3_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_3_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_3_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_3_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_3_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_3_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_3_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_3_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_3_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_3_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_3_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_3_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_3_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_3_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_3_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_3_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_3_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_3_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_3_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_3_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_3_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_3_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_3_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_3_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_3_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_3_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_3_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_3_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_3_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_3_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_3_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_3_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_3_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_3_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_3_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_3_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_3_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_3_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_3_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_3_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_3_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_3_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_3_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_3_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_3_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_3_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_3_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_3_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_3_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_3_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_3_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_3_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_3_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_3_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_3_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_3_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_3_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_3_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_3_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_3_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_3_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_3_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_4                                         0x180B04D0
#define  MC_SECURE_MC_display_access_w_4_reg_addr                                "0xB80B04D0"
#define  MC_SECURE_MC_display_access_w_4_reg                                     0xB80B04D0
#define  MC_SECURE_MC_display_access_w_4_inst_addr                               "0x0118"
#define  set_MC_SECURE_MC_display_access_w_4_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_4_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_4_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_4_reg))
#define  MC_SECURE_MC_display_access_w_4_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_4_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_4_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_4_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_4_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_4_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_4_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_4_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_4_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_4_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_4_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_4_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_4_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_4_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_4_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_4_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_4_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_4_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_4_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_4_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_4_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_4_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_4_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_4_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_4_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_4_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_4_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_4_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_4_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_4_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_4_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_4_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_4_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_4_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_4_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_4_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_4_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_4_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_4_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_4_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_4_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_4_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_4_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_4_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_4_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_4_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_4_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_4_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_4_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_4_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_4_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_4_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_4_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_4_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_4_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_4_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_4_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_4_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_4_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_4_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_4_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_4_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_4_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_4_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_5                                         0x180B04D4
#define  MC_SECURE_MC_display_access_w_5_reg_addr                                "0xB80B04D4"
#define  MC_SECURE_MC_display_access_w_5_reg                                     0xB80B04D4
#define  MC_SECURE_MC_display_access_w_5_inst_addr                               "0x0119"
#define  set_MC_SECURE_MC_display_access_w_5_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_5_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_5_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_5_reg))
#define  MC_SECURE_MC_display_access_w_5_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_5_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_5_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_5_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_5_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_5_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_5_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_5_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_5_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_5_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_5_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_5_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_5_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_5_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_5_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_5_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_5_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_5_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_5_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_5_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_5_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_5_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_5_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_5_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_5_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_5_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_5_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_5_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_5_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_5_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_5_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_5_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_5_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_5_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_5_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_5_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_5_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_5_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_5_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_5_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_5_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_5_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_5_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_5_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_5_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_5_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_5_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_5_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_5_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_5_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_5_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_5_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_5_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_5_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_5_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_5_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_5_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_5_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_5_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_5_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_5_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_5_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_5_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_5_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_6                                         0x180B04D8
#define  MC_SECURE_MC_display_access_w_6_reg_addr                                "0xB80B04D8"
#define  MC_SECURE_MC_display_access_w_6_reg                                     0xB80B04D8
#define  MC_SECURE_MC_display_access_w_6_inst_addr                               "0x011A"
#define  set_MC_SECURE_MC_display_access_w_6_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_6_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_6_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_6_reg))
#define  MC_SECURE_MC_display_access_w_6_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_6_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_6_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_6_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_6_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_6_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_6_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_6_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_6_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_6_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_6_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_6_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_6_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_6_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_6_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_6_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_6_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_6_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_6_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_6_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_6_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_6_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_6_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_6_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_6_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_6_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_6_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_6_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_6_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_6_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_6_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_6_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_6_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_6_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_6_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_6_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_6_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_6_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_6_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_6_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_6_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_6_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_6_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_6_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_6_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_6_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_6_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_6_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_6_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_6_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_6_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_6_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_6_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_6_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_6_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_6_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_6_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_6_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_6_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_6_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_6_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_6_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_6_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_6_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_7                                         0x180B04DC
#define  MC_SECURE_MC_display_access_w_7_reg_addr                                "0xB80B04DC"
#define  MC_SECURE_MC_display_access_w_7_reg                                     0xB80B04DC
#define  MC_SECURE_MC_display_access_w_7_inst_addr                               "0x011B"
#define  set_MC_SECURE_MC_display_access_w_7_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_7_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_7_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_7_reg))
#define  MC_SECURE_MC_display_access_w_7_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_7_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_7_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_7_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_7_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_7_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_7_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_7_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_7_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_7_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_7_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_7_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_7_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_7_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_7_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_7_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_7_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_7_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_7_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_7_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_7_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_7_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_7_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_7_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_7_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_7_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_7_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_7_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_7_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_7_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_7_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_7_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_7_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_7_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_7_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_7_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_7_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_7_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_7_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_7_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_7_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_7_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_7_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_7_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_7_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_7_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_7_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_7_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_7_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_7_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_7_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_7_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_7_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_7_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_7_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_7_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_7_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_7_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_7_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_7_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_7_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_7_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_7_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_7_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_8                                         0x180B04E0
#define  MC_SECURE_MC_display_access_w_8_reg_addr                                "0xB80B04E0"
#define  MC_SECURE_MC_display_access_w_8_reg                                     0xB80B04E0
#define  MC_SECURE_MC_display_access_w_8_inst_addr                               "0x011C"
#define  set_MC_SECURE_MC_display_access_w_8_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_8_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_8_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_8_reg))
#define  MC_SECURE_MC_display_access_w_8_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_8_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_8_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_8_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_8_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_8_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_8_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_8_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_8_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_8_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_8_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_8_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_8_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_8_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_8_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_8_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_8_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_8_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_8_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_8_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_8_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_8_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_8_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_8_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_8_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_8_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_8_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_8_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_8_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_8_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_8_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_8_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_8_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_8_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_8_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_8_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_8_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_8_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_8_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_8_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_8_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_8_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_8_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_8_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_8_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_8_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_8_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_8_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_8_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_8_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_8_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_8_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_8_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_8_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_8_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_8_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_8_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_8_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_8_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_8_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_8_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_8_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_8_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_8_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_9                                         0x180B04E4
#define  MC_SECURE_MC_display_access_w_9_reg_addr                                "0xB80B04E4"
#define  MC_SECURE_MC_display_access_w_9_reg                                     0xB80B04E4
#define  MC_SECURE_MC_display_access_w_9_inst_addr                               "0x011D"
#define  set_MC_SECURE_MC_display_access_w_9_reg(data)                           (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_9_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_9_reg                                 (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_9_reg))
#define  MC_SECURE_MC_display_access_w_9_rbusdma_shift                           (26)
#define  MC_SECURE_MC_display_access_w_9_se_shift                                (24)
#define  MC_SECURE_MC_display_access_w_9_gpu_shift                               (16)
#define  MC_SECURE_MC_display_access_w_9_dispd_shift                             (15)
#define  MC_SECURE_MC_display_access_w_9_dispm_shift                             (14)
#define  MC_SECURE_MC_display_access_w_9_dispi_shift                             (13)
#define  MC_SECURE_MC_display_access_w_9_memc_shift                              (12)
#define  MC_SECURE_MC_display_access_w_9_me_shift                                (11)
#define  MC_SECURE_MC_display_access_w_9_osd_shift                               (9)
#define  MC_SECURE_MC_display_access_w_9_subtitle_shift                          (8)
#define  MC_SECURE_MC_display_access_w_9_vcpu_shift                              (6)
#define  MC_SECURE_MC_display_access_w_9_ve_shift                                (5)
#define  MC_SECURE_MC_display_access_w_9_vde_shift                               (4)
#define  MC_SECURE_MC_display_access_w_9_md_kc_shift                             (2)
#define  MC_SECURE_MC_display_access_w_9_scpu_shift                              (1)
#define  MC_SECURE_MC_display_access_w_9_md_vc_shift                             (0)
#define  MC_SECURE_MC_display_access_w_9_rbusdma_mask                            (0x04000000)
#define  MC_SECURE_MC_display_access_w_9_se_mask                                 (0x03000000)
#define  MC_SECURE_MC_display_access_w_9_gpu_mask                                (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_9_dispd_mask                              (0x00008000)
#define  MC_SECURE_MC_display_access_w_9_dispm_mask                              (0x00004000)
#define  MC_SECURE_MC_display_access_w_9_dispi_mask                              (0x00002000)
#define  MC_SECURE_MC_display_access_w_9_memc_mask                               (0x00001000)
#define  MC_SECURE_MC_display_access_w_9_me_mask                                 (0x00000800)
#define  MC_SECURE_MC_display_access_w_9_osd_mask                                (0x00000600)
#define  MC_SECURE_MC_display_access_w_9_subtitle_mask                           (0x00000100)
#define  MC_SECURE_MC_display_access_w_9_vcpu_mask                               (0x00000040)
#define  MC_SECURE_MC_display_access_w_9_ve_mask                                 (0x00000020)
#define  MC_SECURE_MC_display_access_w_9_vde_mask                                (0x00000010)
#define  MC_SECURE_MC_display_access_w_9_md_kc_mask                              (0x00000004)
#define  MC_SECURE_MC_display_access_w_9_scpu_mask                               (0x00000002)
#define  MC_SECURE_MC_display_access_w_9_md_vc_mask                              (0x00000001)
#define  MC_SECURE_MC_display_access_w_9_rbusdma(data)                           (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_9_se(data)                                (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_9_gpu(data)                               (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_9_dispd(data)                             (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_9_dispm(data)                             (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_9_dispi(data)                             (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_9_memc(data)                              (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_9_me(data)                                (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_9_osd(data)                               (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_9_subtitle(data)                          (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_9_vcpu(data)                              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_9_ve(data)                                (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_9_vde(data)                               (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_9_md_kc(data)                             (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_9_scpu(data)                              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_9_md_vc(data)                             (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_9_get_rbusdma(data)                       ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_9_get_se(data)                            ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_9_get_gpu(data)                           ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_9_get_dispd(data)                         ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_9_get_dispm(data)                         ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_9_get_dispi(data)                         ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_9_get_memc(data)                          ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_9_get_me(data)                            ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_9_get_osd(data)                           ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_9_get_subtitle(data)                      ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_9_get_vcpu(data)                          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_9_get_ve(data)                            ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_9_get_vde(data)                           ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_9_get_md_kc(data)                         ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_9_get_scpu(data)                          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_9_get_md_vc(data)                         (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_10                                        0x180B04E8
#define  MC_SECURE_MC_display_access_w_10_reg_addr                               "0xB80B04E8"
#define  MC_SECURE_MC_display_access_w_10_reg                                    0xB80B04E8
#define  MC_SECURE_MC_display_access_w_10_inst_addr                              "0x011E"
#define  set_MC_SECURE_MC_display_access_w_10_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_10_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_10_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_10_reg))
#define  MC_SECURE_MC_display_access_w_10_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_w_10_se_shift                               (24)
#define  MC_SECURE_MC_display_access_w_10_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_w_10_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_w_10_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_w_10_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_w_10_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_w_10_me_shift                               (11)
#define  MC_SECURE_MC_display_access_w_10_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_w_10_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_w_10_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_w_10_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_w_10_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_w_10_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_w_10_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_w_10_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_w_10_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_w_10_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_w_10_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_10_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_w_10_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_w_10_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_w_10_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_w_10_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_w_10_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_w_10_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_w_10_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_w_10_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_w_10_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_w_10_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_w_10_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_w_10_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_w_10_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_10_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_10_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_10_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_10_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_10_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_10_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_10_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_10_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_10_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_10_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_10_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_10_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_10_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_10_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_10_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_10_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_10_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_10_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_10_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_10_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_10_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_10_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_10_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_10_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_10_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_10_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_10_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_10_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_10_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_10_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_10_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_11                                        0x180B04EC
#define  MC_SECURE_MC_display_access_w_11_reg_addr                               "0xB80B04EC"
#define  MC_SECURE_MC_display_access_w_11_reg                                    0xB80B04EC
#define  MC_SECURE_MC_display_access_w_11_inst_addr                              "0x011F"
#define  set_MC_SECURE_MC_display_access_w_11_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_11_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_11_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_11_reg))
#define  MC_SECURE_MC_display_access_w_11_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_w_11_se_shift                               (24)
#define  MC_SECURE_MC_display_access_w_11_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_w_11_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_w_11_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_w_11_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_w_11_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_w_11_me_shift                               (11)
#define  MC_SECURE_MC_display_access_w_11_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_w_11_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_w_11_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_w_11_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_w_11_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_w_11_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_w_11_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_w_11_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_w_11_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_w_11_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_w_11_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_11_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_w_11_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_w_11_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_w_11_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_w_11_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_w_11_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_w_11_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_w_11_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_w_11_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_w_11_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_w_11_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_w_11_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_w_11_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_w_11_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_11_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_11_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_11_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_11_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_11_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_11_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_11_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_11_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_11_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_11_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_11_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_11_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_11_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_11_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_11_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_11_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_11_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_11_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_11_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_11_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_11_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_11_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_11_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_11_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_11_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_11_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_11_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_11_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_11_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_11_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_11_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_12                                        0x180B04F0
#define  MC_SECURE_MC_display_access_w_12_reg_addr                               "0xB80B04F0"
#define  MC_SECURE_MC_display_access_w_12_reg                                    0xB80B04F0
#define  MC_SECURE_MC_display_access_w_12_inst_addr                              "0x0120"
#define  set_MC_SECURE_MC_display_access_w_12_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_12_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_12_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_12_reg))
#define  MC_SECURE_MC_display_access_w_12_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_w_12_se_shift                               (24)
#define  MC_SECURE_MC_display_access_w_12_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_w_12_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_w_12_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_w_12_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_w_12_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_w_12_me_shift                               (11)
#define  MC_SECURE_MC_display_access_w_12_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_w_12_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_w_12_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_w_12_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_w_12_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_w_12_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_w_12_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_w_12_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_w_12_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_w_12_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_w_12_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_12_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_w_12_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_w_12_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_w_12_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_w_12_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_w_12_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_w_12_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_w_12_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_w_12_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_w_12_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_w_12_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_w_12_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_w_12_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_w_12_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_12_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_12_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_12_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_12_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_12_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_12_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_12_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_12_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_12_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_12_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_12_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_12_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_12_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_12_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_12_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_12_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_12_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_12_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_12_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_12_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_12_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_12_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_12_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_12_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_12_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_12_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_12_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_12_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_12_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_12_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_12_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_13                                        0x180B04F4
#define  MC_SECURE_MC_display_access_w_13_reg_addr                               "0xB80B04F4"
#define  MC_SECURE_MC_display_access_w_13_reg                                    0xB80B04F4
#define  MC_SECURE_MC_display_access_w_13_inst_addr                              "0x0121"
#define  set_MC_SECURE_MC_display_access_w_13_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_13_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_13_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_13_reg))
#define  MC_SECURE_MC_display_access_w_13_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_w_13_se_shift                               (24)
#define  MC_SECURE_MC_display_access_w_13_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_w_13_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_w_13_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_w_13_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_w_13_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_w_13_me_shift                               (11)
#define  MC_SECURE_MC_display_access_w_13_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_w_13_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_w_13_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_w_13_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_w_13_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_w_13_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_w_13_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_w_13_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_w_13_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_w_13_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_w_13_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_13_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_w_13_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_w_13_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_w_13_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_w_13_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_w_13_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_w_13_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_w_13_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_w_13_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_w_13_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_w_13_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_w_13_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_w_13_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_w_13_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_13_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_13_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_13_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_13_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_13_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_13_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_13_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_13_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_13_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_13_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_13_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_13_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_13_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_13_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_13_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_13_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_13_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_13_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_13_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_13_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_13_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_13_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_13_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_13_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_13_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_13_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_13_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_13_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_13_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_13_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_13_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_14                                        0x180B04F8
#define  MC_SECURE_MC_display_access_w_14_reg_addr                               "0xB80B04F8"
#define  MC_SECURE_MC_display_access_w_14_reg                                    0xB80B04F8
#define  MC_SECURE_MC_display_access_w_14_inst_addr                              "0x0122"
#define  set_MC_SECURE_MC_display_access_w_14_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_14_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_14_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_14_reg))
#define  MC_SECURE_MC_display_access_w_14_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_w_14_se_shift                               (24)
#define  MC_SECURE_MC_display_access_w_14_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_w_14_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_w_14_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_w_14_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_w_14_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_w_14_me_shift                               (11)
#define  MC_SECURE_MC_display_access_w_14_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_w_14_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_w_14_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_w_14_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_w_14_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_w_14_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_w_14_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_w_14_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_w_14_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_w_14_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_w_14_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_14_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_w_14_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_w_14_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_w_14_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_w_14_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_w_14_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_w_14_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_w_14_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_w_14_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_w_14_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_w_14_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_w_14_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_w_14_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_w_14_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_14_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_14_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_14_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_14_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_14_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_14_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_14_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_14_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_14_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_14_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_14_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_14_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_14_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_14_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_14_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_14_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_14_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_14_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_14_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_14_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_14_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_14_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_14_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_14_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_14_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_14_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_14_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_14_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_14_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_14_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_14_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_display_access_w_15                                        0x180B04FC
#define  MC_SECURE_MC_display_access_w_15_reg_addr                               "0xB80B04FC"
#define  MC_SECURE_MC_display_access_w_15_reg                                    0xB80B04FC
#define  MC_SECURE_MC_display_access_w_15_inst_addr                              "0x0123"
#define  set_MC_SECURE_MC_display_access_w_15_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_15_reg)=data)
#define  get_MC_SECURE_MC_display_access_w_15_reg                                (*((volatile unsigned int*)MC_SECURE_MC_display_access_w_15_reg))
#define  MC_SECURE_MC_display_access_w_15_rbusdma_shift                          (26)
#define  MC_SECURE_MC_display_access_w_15_se_shift                               (24)
#define  MC_SECURE_MC_display_access_w_15_gpu_shift                              (16)
#define  MC_SECURE_MC_display_access_w_15_dispd_shift                            (15)
#define  MC_SECURE_MC_display_access_w_15_dispm_shift                            (14)
#define  MC_SECURE_MC_display_access_w_15_dispi_shift                            (13)
#define  MC_SECURE_MC_display_access_w_15_memc_shift                             (12)
#define  MC_SECURE_MC_display_access_w_15_me_shift                               (11)
#define  MC_SECURE_MC_display_access_w_15_osd_shift                              (9)
#define  MC_SECURE_MC_display_access_w_15_subtitle_shift                         (8)
#define  MC_SECURE_MC_display_access_w_15_vcpu_shift                             (6)
#define  MC_SECURE_MC_display_access_w_15_ve_shift                               (5)
#define  MC_SECURE_MC_display_access_w_15_vde_shift                              (4)
#define  MC_SECURE_MC_display_access_w_15_md_kc_shift                            (2)
#define  MC_SECURE_MC_display_access_w_15_scpu_shift                             (1)
#define  MC_SECURE_MC_display_access_w_15_md_vc_shift                            (0)
#define  MC_SECURE_MC_display_access_w_15_rbusdma_mask                           (0x04000000)
#define  MC_SECURE_MC_display_access_w_15_se_mask                                (0x03000000)
#define  MC_SECURE_MC_display_access_w_15_gpu_mask                               (0x00FF0000)
#define  MC_SECURE_MC_display_access_w_15_dispd_mask                             (0x00008000)
#define  MC_SECURE_MC_display_access_w_15_dispm_mask                             (0x00004000)
#define  MC_SECURE_MC_display_access_w_15_dispi_mask                             (0x00002000)
#define  MC_SECURE_MC_display_access_w_15_memc_mask                              (0x00001000)
#define  MC_SECURE_MC_display_access_w_15_me_mask                                (0x00000800)
#define  MC_SECURE_MC_display_access_w_15_osd_mask                               (0x00000600)
#define  MC_SECURE_MC_display_access_w_15_subtitle_mask                          (0x00000100)
#define  MC_SECURE_MC_display_access_w_15_vcpu_mask                              (0x00000040)
#define  MC_SECURE_MC_display_access_w_15_ve_mask                                (0x00000020)
#define  MC_SECURE_MC_display_access_w_15_vde_mask                               (0x00000010)
#define  MC_SECURE_MC_display_access_w_15_md_kc_mask                             (0x00000004)
#define  MC_SECURE_MC_display_access_w_15_scpu_mask                              (0x00000002)
#define  MC_SECURE_MC_display_access_w_15_md_vc_mask                             (0x00000001)
#define  MC_SECURE_MC_display_access_w_15_rbusdma(data)                          (0x04000000&((data)<<26))
#define  MC_SECURE_MC_display_access_w_15_se(data)                               (0x03000000&((data)<<24))
#define  MC_SECURE_MC_display_access_w_15_gpu(data)                              (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_display_access_w_15_dispd(data)                            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_display_access_w_15_dispm(data)                            (0x00004000&((data)<<14))
#define  MC_SECURE_MC_display_access_w_15_dispi(data)                            (0x00002000&((data)<<13))
#define  MC_SECURE_MC_display_access_w_15_memc(data)                             (0x00001000&((data)<<12))
#define  MC_SECURE_MC_display_access_w_15_me(data)                               (0x00000800&((data)<<11))
#define  MC_SECURE_MC_display_access_w_15_osd(data)                              (0x00000600&((data)<<9))
#define  MC_SECURE_MC_display_access_w_15_subtitle(data)                         (0x00000100&((data)<<8))
#define  MC_SECURE_MC_display_access_w_15_vcpu(data)                             (0x00000040&((data)<<6))
#define  MC_SECURE_MC_display_access_w_15_ve(data)                               (0x00000020&((data)<<5))
#define  MC_SECURE_MC_display_access_w_15_vde(data)                              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_display_access_w_15_md_kc(data)                            (0x00000004&((data)<<2))
#define  MC_SECURE_MC_display_access_w_15_scpu(data)                             (0x00000002&((data)<<1))
#define  MC_SECURE_MC_display_access_w_15_md_vc(data)                            (0x00000001&(data))
#define  MC_SECURE_MC_display_access_w_15_get_rbusdma(data)                      ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_display_access_w_15_get_se(data)                           ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_display_access_w_15_get_gpu(data)                          ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_display_access_w_15_get_dispd(data)                        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_display_access_w_15_get_dispm(data)                        ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_display_access_w_15_get_dispi(data)                        ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_display_access_w_15_get_memc(data)                         ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_display_access_w_15_get_me(data)                           ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_display_access_w_15_get_osd(data)                          ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_display_access_w_15_get_subtitle(data)                     ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_display_access_w_15_get_vcpu(data)                         ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_display_access_w_15_get_ve(data)                           ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_display_access_w_15_get_vde(data)                          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_display_access_w_15_get_md_kc(data)                        ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_display_access_w_15_get_scpu(data)                         ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_display_access_w_15_get_md_vc(data)                        (0x00000001&(data))

#define  MC_SECURE_MC_mem_default_ctrl                                           0x180B0500
#define  MC_SECURE_MC_mem_default_ctrl_reg_addr                                  "0xB80B0500"
#define  MC_SECURE_MC_mem_default_ctrl_reg                                       0xB80B0500
#define  MC_SECURE_MC_mem_default_ctrl_inst_addr                                 "0x0124"
#define  set_MC_SECURE_MC_mem_default_ctrl_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_mem_default_ctrl_reg)=data)
#define  get_MC_SECURE_MC_mem_default_ctrl_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_mem_default_ctrl_reg))
#define  MC_SECURE_MC_mem_default_ctrl_default_0_en_shift                        (16)
#define  MC_SECURE_MC_mem_default_ctrl_default_0_en_mask                         (0x00010000)
#define  MC_SECURE_MC_mem_default_ctrl_default_0_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_mem_default_ctrl_get_default_0_en(data)                    ((0x00010000&(data))>>16)

#define  MC_SECURE_MC_default_access_r                                           0x180B0510
#define  MC_SECURE_MC_default_access_r_reg_addr                                  "0xB80B0510"
#define  MC_SECURE_MC_default_access_r_reg                                       0xB80B0510
#define  MC_SECURE_MC_default_access_r_inst_addr                                 "0x0125"
#define  set_MC_SECURE_MC_default_access_r_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_default_access_r_reg)=data)
#define  get_MC_SECURE_MC_default_access_r_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_default_access_r_reg))
#define  MC_SECURE_MC_default_access_r_rbusdma_shift                             (26)
#define  MC_SECURE_MC_default_access_r_se_shift                                  (24)
#define  MC_SECURE_MC_default_access_r_gpu_shift                                 (16)
#define  MC_SECURE_MC_default_access_r_dispd_shift                               (15)
#define  MC_SECURE_MC_default_access_r_dispm_shift                               (14)
#define  MC_SECURE_MC_default_access_r_dispi_shift                               (13)
#define  MC_SECURE_MC_default_access_r_memc_shift                                (12)
#define  MC_SECURE_MC_default_access_r_osd_shift                                 (9)
#define  MC_SECURE_MC_default_access_r_subtitle_shift                            (8)
#define  MC_SECURE_MC_default_access_r_vcpu_shift                                (6)
#define  MC_SECURE_MC_default_access_r_ve_shift                                  (5)
#define  MC_SECURE_MC_default_access_r_vde_shift                                 (4)
#define  MC_SECURE_MC_default_access_r_md_kc_shift                               (2)
#define  MC_SECURE_MC_default_access_r_scpu_shift                                (1)
#define  MC_SECURE_MC_default_access_r_md_vc_shift                               (0)
#define  MC_SECURE_MC_default_access_r_rbusdma_mask                              (0x04000000)
#define  MC_SECURE_MC_default_access_r_se_mask                                   (0x03000000)
#define  MC_SECURE_MC_default_access_r_gpu_mask                                  (0x00FF0000)
#define  MC_SECURE_MC_default_access_r_dispd_mask                                (0x00008000)
#define  MC_SECURE_MC_default_access_r_dispm_mask                                (0x00004000)
#define  MC_SECURE_MC_default_access_r_dispi_mask                                (0x00002000)
#define  MC_SECURE_MC_default_access_r_memc_mask                                 (0x00001000)
#define  MC_SECURE_MC_default_access_r_osd_mask                                  (0x00000600)
#define  MC_SECURE_MC_default_access_r_subtitle_mask                             (0x00000100)
#define  MC_SECURE_MC_default_access_r_vcpu_mask                                 (0x00000040)
#define  MC_SECURE_MC_default_access_r_ve_mask                                   (0x00000020)
#define  MC_SECURE_MC_default_access_r_vde_mask                                  (0x00000010)
#define  MC_SECURE_MC_default_access_r_md_kc_mask                                (0x00000004)
#define  MC_SECURE_MC_default_access_r_scpu_mask                                 (0x00000002)
#define  MC_SECURE_MC_default_access_r_md_vc_mask                                (0x00000001)
#define  MC_SECURE_MC_default_access_r_rbusdma(data)                             (0x04000000&((data)<<26))
#define  MC_SECURE_MC_default_access_r_se(data)                                  (0x03000000&((data)<<24))
#define  MC_SECURE_MC_default_access_r_gpu(data)                                 (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_default_access_r_dispd(data)                               (0x00008000&((data)<<15))
#define  MC_SECURE_MC_default_access_r_dispm(data)                               (0x00004000&((data)<<14))
#define  MC_SECURE_MC_default_access_r_dispi(data)                               (0x00002000&((data)<<13))
#define  MC_SECURE_MC_default_access_r_memc(data)                                (0x00001000&((data)<<12))
#define  MC_SECURE_MC_default_access_r_osd(data)                                 (0x00000600&((data)<<9))
#define  MC_SECURE_MC_default_access_r_subtitle(data)                            (0x00000100&((data)<<8))
#define  MC_SECURE_MC_default_access_r_vcpu(data)                                (0x00000040&((data)<<6))
#define  MC_SECURE_MC_default_access_r_ve(data)                                  (0x00000020&((data)<<5))
#define  MC_SECURE_MC_default_access_r_vde(data)                                 (0x00000010&((data)<<4))
#define  MC_SECURE_MC_default_access_r_md_kc(data)                               (0x00000004&((data)<<2))
#define  MC_SECURE_MC_default_access_r_scpu(data)                                (0x00000002&((data)<<1))
#define  MC_SECURE_MC_default_access_r_md_vc(data)                               (0x00000001&(data))
#define  MC_SECURE_MC_default_access_r_get_rbusdma(data)                         ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_default_access_r_get_se(data)                              ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_default_access_r_get_gpu(data)                             ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_default_access_r_get_dispd(data)                           ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_default_access_r_get_dispm(data)                           ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_default_access_r_get_dispi(data)                           ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_default_access_r_get_memc(data)                            ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_default_access_r_get_osd(data)                             ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_default_access_r_get_subtitle(data)                        ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_default_access_r_get_vcpu(data)                            ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_default_access_r_get_ve(data)                              ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_default_access_r_get_vde(data)                             ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_default_access_r_get_md_kc(data)                           ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_default_access_r_get_scpu(data)                            ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_default_access_r_get_md_vc(data)                           (0x00000001&(data))

#define  MC_SECURE_MC_default_access_w                                           0x180B0514
#define  MC_SECURE_MC_default_access_w_reg_addr                                  "0xB80B0514"
#define  MC_SECURE_MC_default_access_w_reg                                       0xB80B0514
#define  MC_SECURE_MC_default_access_w_inst_addr                                 "0x0126"
#define  set_MC_SECURE_MC_default_access_w_reg(data)                             (*((volatile unsigned int*)MC_SECURE_MC_default_access_w_reg)=data)
#define  get_MC_SECURE_MC_default_access_w_reg                                   (*((volatile unsigned int*)MC_SECURE_MC_default_access_w_reg))
#define  MC_SECURE_MC_default_access_w_rbusdma_shift                             (26)
#define  MC_SECURE_MC_default_access_w_se_shift                                  (24)
#define  MC_SECURE_MC_default_access_w_gpu_shift                                 (16)
#define  MC_SECURE_MC_default_access_w_dispd_shift                               (15)
#define  MC_SECURE_MC_default_access_w_dispm_shift                               (14)
#define  MC_SECURE_MC_default_access_w_dispi_shift                               (13)
#define  MC_SECURE_MC_default_access_w_memc_shift                                (12)
#define  MC_SECURE_MC_default_access_w_osd_shift                                 (9)
#define  MC_SECURE_MC_default_access_w_subtitle_shift                            (8)
#define  MC_SECURE_MC_default_access_w_vcpu_shift                                (6)
#define  MC_SECURE_MC_default_access_w_ve_shift                                  (5)
#define  MC_SECURE_MC_default_access_w_vde_shift                                 (4)
#define  MC_SECURE_MC_default_access_w_md_kc_shift                               (2)
#define  MC_SECURE_MC_default_access_w_scpu_shift                                (1)
#define  MC_SECURE_MC_default_access_w_md_vc_shift                               (0)
#define  MC_SECURE_MC_default_access_w_rbusdma_mask                              (0x04000000)
#define  MC_SECURE_MC_default_access_w_se_mask                                   (0x03000000)
#define  MC_SECURE_MC_default_access_w_gpu_mask                                  (0x00FF0000)
#define  MC_SECURE_MC_default_access_w_dispd_mask                                (0x00008000)
#define  MC_SECURE_MC_default_access_w_dispm_mask                                (0x00004000)
#define  MC_SECURE_MC_default_access_w_dispi_mask                                (0x00002000)
#define  MC_SECURE_MC_default_access_w_memc_mask                                 (0x00001000)
#define  MC_SECURE_MC_default_access_w_osd_mask                                  (0x00000600)
#define  MC_SECURE_MC_default_access_w_subtitle_mask                             (0x00000100)
#define  MC_SECURE_MC_default_access_w_vcpu_mask                                 (0x00000040)
#define  MC_SECURE_MC_default_access_w_ve_mask                                   (0x00000020)
#define  MC_SECURE_MC_default_access_w_vde_mask                                  (0x00000010)
#define  MC_SECURE_MC_default_access_w_md_kc_mask                                (0x00000004)
#define  MC_SECURE_MC_default_access_w_scpu_mask                                 (0x00000002)
#define  MC_SECURE_MC_default_access_w_md_vc_mask                                (0x00000001)
#define  MC_SECURE_MC_default_access_w_rbusdma(data)                             (0x04000000&((data)<<26))
#define  MC_SECURE_MC_default_access_w_se(data)                                  (0x03000000&((data)<<24))
#define  MC_SECURE_MC_default_access_w_gpu(data)                                 (0x00FF0000&((data)<<16))
#define  MC_SECURE_MC_default_access_w_dispd(data)                               (0x00008000&((data)<<15))
#define  MC_SECURE_MC_default_access_w_dispm(data)                               (0x00004000&((data)<<14))
#define  MC_SECURE_MC_default_access_w_dispi(data)                               (0x00002000&((data)<<13))
#define  MC_SECURE_MC_default_access_w_memc(data)                                (0x00001000&((data)<<12))
#define  MC_SECURE_MC_default_access_w_osd(data)                                 (0x00000600&((data)<<9))
#define  MC_SECURE_MC_default_access_w_subtitle(data)                            (0x00000100&((data)<<8))
#define  MC_SECURE_MC_default_access_w_vcpu(data)                                (0x00000040&((data)<<6))
#define  MC_SECURE_MC_default_access_w_ve(data)                                  (0x00000020&((data)<<5))
#define  MC_SECURE_MC_default_access_w_vde(data)                                 (0x00000010&((data)<<4))
#define  MC_SECURE_MC_default_access_w_md_kc(data)                               (0x00000004&((data)<<2))
#define  MC_SECURE_MC_default_access_w_scpu(data)                                (0x00000002&((data)<<1))
#define  MC_SECURE_MC_default_access_w_md_vc(data)                               (0x00000001&(data))
#define  MC_SECURE_MC_default_access_w_get_rbusdma(data)                         ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_default_access_w_get_se(data)                              ((0x03000000&(data))>>24)
#define  MC_SECURE_MC_default_access_w_get_gpu(data)                             ((0x00FF0000&(data))>>16)
#define  MC_SECURE_MC_default_access_w_get_dispd(data)                           ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_default_access_w_get_dispm(data)                           ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_default_access_w_get_dispi(data)                           ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_default_access_w_get_memc(data)                            ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_default_access_w_get_osd(data)                             ((0x00000600&(data))>>9)
#define  MC_SECURE_MC_default_access_w_get_subtitle(data)                        ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_default_access_w_get_vcpu(data)                            ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_default_access_w_get_ve(data)                              ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_default_access_w_get_vde(data)                             ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_default_access_w_get_md_kc(data)                           ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_default_access_w_get_scpu(data)                            ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_default_access_w_get_md_vc(data)                           (0x00000001&(data))

#define  MC_SECURE_MC_secure_int_0                                               0x180B0700
#define  MC_SECURE_MC_secure_int_0_reg_addr                                      "0xB80B0700"
#define  MC_SECURE_MC_secure_int_0_reg                                           0xB80B0700
#define  MC_SECURE_MC_secure_int_0_inst_addr                                     "0x0127"
#define  set_MC_SECURE_MC_secure_int_0_reg(data)                                 (*((volatile unsigned int*)MC_SECURE_MC_secure_int_0_reg)=data)
#define  get_MC_SECURE_MC_secure_int_0_reg                                       (*((volatile unsigned int*)MC_SECURE_MC_secure_int_0_reg))
#define  MC_SECURE_MC_secure_int_0_seq_over_max_secure_addr_int_en_shift         (31)
#define  MC_SECURE_MC_secure_int_0_protect_3_int_en_shift                        (19)
#define  MC_SECURE_MC_secure_int_0_protect_2_int_en_shift                        (18)
#define  MC_SECURE_MC_secure_int_0_protect_1_int_en_shift                        (17)
#define  MC_SECURE_MC_secure_int_0_protect_0_int_en_shift                        (16)
#define  MC_SECURE_MC_secure_int_0_seq_over_max_secure_addr_int_shift            (15)
#define  MC_SECURE_MC_secure_int_0_protect_3_int_shift                           (3)
#define  MC_SECURE_MC_secure_int_0_protect_2_int_shift                           (2)
#define  MC_SECURE_MC_secure_int_0_protect_1_int_shift                           (1)
#define  MC_SECURE_MC_secure_int_0_protect_0_int_shift                           (0)
#define  MC_SECURE_MC_secure_int_0_seq_over_max_secure_addr_int_en_mask          (0x80000000)
#define  MC_SECURE_MC_secure_int_0_protect_3_int_en_mask                         (0x00080000)
#define  MC_SECURE_MC_secure_int_0_protect_2_int_en_mask                         (0x00040000)
#define  MC_SECURE_MC_secure_int_0_protect_1_int_en_mask                         (0x00020000)
#define  MC_SECURE_MC_secure_int_0_protect_0_int_en_mask                         (0x00010000)
#define  MC_SECURE_MC_secure_int_0_seq_over_max_secure_addr_int_mask             (0x00008000)
#define  MC_SECURE_MC_secure_int_0_protect_3_int_mask                            (0x00000008)
#define  MC_SECURE_MC_secure_int_0_protect_2_int_mask                            (0x00000004)
#define  MC_SECURE_MC_secure_int_0_protect_1_int_mask                            (0x00000002)
#define  MC_SECURE_MC_secure_int_0_protect_0_int_mask                            (0x00000001)
#define  MC_SECURE_MC_secure_int_0_seq_over_max_secure_addr_int_en(data)         (0x80000000&((data)<<31))
#define  MC_SECURE_MC_secure_int_0_protect_3_int_en(data)                        (0x00080000&((data)<<19))
#define  MC_SECURE_MC_secure_int_0_protect_2_int_en(data)                        (0x00040000&((data)<<18))
#define  MC_SECURE_MC_secure_int_0_protect_1_int_en(data)                        (0x00020000&((data)<<17))
#define  MC_SECURE_MC_secure_int_0_protect_0_int_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_secure_int_0_seq_over_max_secure_addr_int(data)            (0x00008000&((data)<<15))
#define  MC_SECURE_MC_secure_int_0_protect_3_int(data)                           (0x00000008&((data)<<3))
#define  MC_SECURE_MC_secure_int_0_protect_2_int(data)                           (0x00000004&((data)<<2))
#define  MC_SECURE_MC_secure_int_0_protect_1_int(data)                           (0x00000002&((data)<<1))
#define  MC_SECURE_MC_secure_int_0_protect_0_int(data)                           (0x00000001&(data))
#define  MC_SECURE_MC_secure_int_0_get_seq_over_max_secure_addr_int_en(data)     ((0x80000000&(data))>>31)
#define  MC_SECURE_MC_secure_int_0_get_protect_3_int_en(data)                    ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_secure_int_0_get_protect_2_int_en(data)                    ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_secure_int_0_get_protect_1_int_en(data)                    ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_secure_int_0_get_protect_0_int_en(data)                    ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_secure_int_0_get_seq_over_max_secure_addr_int(data)        ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_secure_int_0_get_protect_3_int(data)                       ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_secure_int_0_get_protect_2_int(data)                       ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_secure_int_0_get_protect_1_int(data)                       ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_secure_int_0_get_protect_0_int(data)                       (0x00000001&(data))

#define  MC_SECURE_MC_secure_int_1                                               0x180B0704
#define  MC_SECURE_MC_secure_int_1_reg_addr                                      "0xB80B0704"
#define  MC_SECURE_MC_secure_int_1_reg                                           0xB80B0704
#define  MC_SECURE_MC_secure_int_1_inst_addr                                     "0x0128"
#define  set_MC_SECURE_MC_secure_int_1_reg(data)                                 (*((volatile unsigned int*)MC_SECURE_MC_secure_int_1_reg)=data)
#define  get_MC_SECURE_MC_secure_int_1_reg                                       (*((volatile unsigned int*)MC_SECURE_MC_secure_int_1_reg))
#define  MC_SECURE_MC_secure_int_1_content_7_int_en_shift                        (23)
#define  MC_SECURE_MC_secure_int_1_content_6_int_en_shift                        (22)
#define  MC_SECURE_MC_secure_int_1_content_5_int_en_shift                        (21)
#define  MC_SECURE_MC_secure_int_1_content_4_int_en_shift                        (20)
#define  MC_SECURE_MC_secure_int_1_content_3_int_en_shift                        (19)
#define  MC_SECURE_MC_secure_int_1_content_2_int_en_shift                        (18)
#define  MC_SECURE_MC_secure_int_1_content_1_int_en_shift                        (17)
#define  MC_SECURE_MC_secure_int_1_content_0_int_en_shift                        (16)
#define  MC_SECURE_MC_secure_int_1_content_7_int_shift                           (7)
#define  MC_SECURE_MC_secure_int_1_content_6_int_shift                           (6)
#define  MC_SECURE_MC_secure_int_1_content_5_int_shift                           (5)
#define  MC_SECURE_MC_secure_int_1_content_4_int_shift                           (4)
#define  MC_SECURE_MC_secure_int_1_content_3_int_shift                           (3)
#define  MC_SECURE_MC_secure_int_1_content_2_int_shift                           (2)
#define  MC_SECURE_MC_secure_int_1_content_1_int_shift                           (1)
#define  MC_SECURE_MC_secure_int_1_content_0_int_shift                           (0)
#define  MC_SECURE_MC_secure_int_1_content_7_int_en_mask                         (0x00800000)
#define  MC_SECURE_MC_secure_int_1_content_6_int_en_mask                         (0x00400000)
#define  MC_SECURE_MC_secure_int_1_content_5_int_en_mask                         (0x00200000)
#define  MC_SECURE_MC_secure_int_1_content_4_int_en_mask                         (0x00100000)
#define  MC_SECURE_MC_secure_int_1_content_3_int_en_mask                         (0x00080000)
#define  MC_SECURE_MC_secure_int_1_content_2_int_en_mask                         (0x00040000)
#define  MC_SECURE_MC_secure_int_1_content_1_int_en_mask                         (0x00020000)
#define  MC_SECURE_MC_secure_int_1_content_0_int_en_mask                         (0x00010000)
#define  MC_SECURE_MC_secure_int_1_content_7_int_mask                            (0x00000080)
#define  MC_SECURE_MC_secure_int_1_content_6_int_mask                            (0x00000040)
#define  MC_SECURE_MC_secure_int_1_content_5_int_mask                            (0x00000020)
#define  MC_SECURE_MC_secure_int_1_content_4_int_mask                            (0x00000010)
#define  MC_SECURE_MC_secure_int_1_content_3_int_mask                            (0x00000008)
#define  MC_SECURE_MC_secure_int_1_content_2_int_mask                            (0x00000004)
#define  MC_SECURE_MC_secure_int_1_content_1_int_mask                            (0x00000002)
#define  MC_SECURE_MC_secure_int_1_content_0_int_mask                            (0x00000001)
#define  MC_SECURE_MC_secure_int_1_content_7_int_en(data)                        (0x00800000&((data)<<23))
#define  MC_SECURE_MC_secure_int_1_content_6_int_en(data)                        (0x00400000&((data)<<22))
#define  MC_SECURE_MC_secure_int_1_content_5_int_en(data)                        (0x00200000&((data)<<21))
#define  MC_SECURE_MC_secure_int_1_content_4_int_en(data)                        (0x00100000&((data)<<20))
#define  MC_SECURE_MC_secure_int_1_content_3_int_en(data)                        (0x00080000&((data)<<19))
#define  MC_SECURE_MC_secure_int_1_content_2_int_en(data)                        (0x00040000&((data)<<18))
#define  MC_SECURE_MC_secure_int_1_content_1_int_en(data)                        (0x00020000&((data)<<17))
#define  MC_SECURE_MC_secure_int_1_content_0_int_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_secure_int_1_content_7_int(data)                           (0x00000080&((data)<<7))
#define  MC_SECURE_MC_secure_int_1_content_6_int(data)                           (0x00000040&((data)<<6))
#define  MC_SECURE_MC_secure_int_1_content_5_int(data)                           (0x00000020&((data)<<5))
#define  MC_SECURE_MC_secure_int_1_content_4_int(data)                           (0x00000010&((data)<<4))
#define  MC_SECURE_MC_secure_int_1_content_3_int(data)                           (0x00000008&((data)<<3))
#define  MC_SECURE_MC_secure_int_1_content_2_int(data)                           (0x00000004&((data)<<2))
#define  MC_SECURE_MC_secure_int_1_content_1_int(data)                           (0x00000002&((data)<<1))
#define  MC_SECURE_MC_secure_int_1_content_0_int(data)                           (0x00000001&(data))
#define  MC_SECURE_MC_secure_int_1_get_content_7_int_en(data)                    ((0x00800000&(data))>>23)
#define  MC_SECURE_MC_secure_int_1_get_content_6_int_en(data)                    ((0x00400000&(data))>>22)
#define  MC_SECURE_MC_secure_int_1_get_content_5_int_en(data)                    ((0x00200000&(data))>>21)
#define  MC_SECURE_MC_secure_int_1_get_content_4_int_en(data)                    ((0x00100000&(data))>>20)
#define  MC_SECURE_MC_secure_int_1_get_content_3_int_en(data)                    ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_secure_int_1_get_content_2_int_en(data)                    ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_secure_int_1_get_content_1_int_en(data)                    ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_secure_int_1_get_content_0_int_en(data)                    ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_secure_int_1_get_content_7_int(data)                       ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_secure_int_1_get_content_6_int(data)                       ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_secure_int_1_get_content_5_int(data)                       ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_secure_int_1_get_content_4_int(data)                       ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_secure_int_1_get_content_3_int(data)                       ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_secure_int_1_get_content_2_int(data)                       ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_secure_int_1_get_content_1_int(data)                       ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_secure_int_1_get_content_0_int(data)                       (0x00000001&(data))

#define  MC_SECURE_MC_secure_int_2                                               0x180B0708
#define  MC_SECURE_MC_secure_int_2_reg_addr                                      "0xB80B0708"
#define  MC_SECURE_MC_secure_int_2_reg                                           0xB80B0708
#define  MC_SECURE_MC_secure_int_2_inst_addr                                     "0x0129"
#define  set_MC_SECURE_MC_secure_int_2_reg(data)                                 (*((volatile unsigned int*)MC_SECURE_MC_secure_int_2_reg)=data)
#define  get_MC_SECURE_MC_secure_int_2_reg                                       (*((volatile unsigned int*)MC_SECURE_MC_secure_int_2_reg))
#define  MC_SECURE_MC_secure_int_2_display_15_int_en_shift                       (31)
#define  MC_SECURE_MC_secure_int_2_display_14_int_en_shift                       (30)
#define  MC_SECURE_MC_secure_int_2_display_13_int_en_shift                       (29)
#define  MC_SECURE_MC_secure_int_2_display_12_int_en_shift                       (28)
#define  MC_SECURE_MC_secure_int_2_display_11_int_en_shift                       (27)
#define  MC_SECURE_MC_secure_int_2_display_10_int_en_shift                       (26)
#define  MC_SECURE_MC_secure_int_2_display_9_int_en_shift                        (25)
#define  MC_SECURE_MC_secure_int_2_display_8_int_en_shift                        (24)
#define  MC_SECURE_MC_secure_int_2_display_7_int_en_shift                        (23)
#define  MC_SECURE_MC_secure_int_2_display_6_int_en_shift                        (22)
#define  MC_SECURE_MC_secure_int_2_display_5_int_en_shift                        (21)
#define  MC_SECURE_MC_secure_int_2_display_4_int_en_shift                        (20)
#define  MC_SECURE_MC_secure_int_2_display_3_int_en_shift                        (19)
#define  MC_SECURE_MC_secure_int_2_display_2_int_en_shift                        (18)
#define  MC_SECURE_MC_secure_int_2_display_1_int_en_shift                        (17)
#define  MC_SECURE_MC_secure_int_2_display_0_int_en_shift                        (16)
#define  MC_SECURE_MC_secure_int_2_display_15_int_shift                          (15)
#define  MC_SECURE_MC_secure_int_2_display_14_int_shift                          (14)
#define  MC_SECURE_MC_secure_int_2_display_13_int_shift                          (13)
#define  MC_SECURE_MC_secure_int_2_display_12_int_shift                          (12)
#define  MC_SECURE_MC_secure_int_2_display_11_int_shift                          (11)
#define  MC_SECURE_MC_secure_int_2_display_10_int_shift                          (10)
#define  MC_SECURE_MC_secure_int_2_display_9_int_shift                           (9)
#define  MC_SECURE_MC_secure_int_2_display_8_int_shift                           (8)
#define  MC_SECURE_MC_secure_int_2_display_7_int_shift                           (7)
#define  MC_SECURE_MC_secure_int_2_display_6_int_shift                           (6)
#define  MC_SECURE_MC_secure_int_2_display_5_int_shift                           (5)
#define  MC_SECURE_MC_secure_int_2_display_4_int_shift                           (4)
#define  MC_SECURE_MC_secure_int_2_display_3_int_shift                           (3)
#define  MC_SECURE_MC_secure_int_2_display_2_int_shift                           (2)
#define  MC_SECURE_MC_secure_int_2_display_1_int_shift                           (1)
#define  MC_SECURE_MC_secure_int_2_display_0_int_shift                           (0)
#define  MC_SECURE_MC_secure_int_2_display_15_int_en_mask                        (0x80000000)
#define  MC_SECURE_MC_secure_int_2_display_14_int_en_mask                        (0x40000000)
#define  MC_SECURE_MC_secure_int_2_display_13_int_en_mask                        (0x20000000)
#define  MC_SECURE_MC_secure_int_2_display_12_int_en_mask                        (0x10000000)
#define  MC_SECURE_MC_secure_int_2_display_11_int_en_mask                        (0x08000000)
#define  MC_SECURE_MC_secure_int_2_display_10_int_en_mask                        (0x04000000)
#define  MC_SECURE_MC_secure_int_2_display_9_int_en_mask                         (0x02000000)
#define  MC_SECURE_MC_secure_int_2_display_8_int_en_mask                         (0x01000000)
#define  MC_SECURE_MC_secure_int_2_display_7_int_en_mask                         (0x00800000)
#define  MC_SECURE_MC_secure_int_2_display_6_int_en_mask                         (0x00400000)
#define  MC_SECURE_MC_secure_int_2_display_5_int_en_mask                         (0x00200000)
#define  MC_SECURE_MC_secure_int_2_display_4_int_en_mask                         (0x00100000)
#define  MC_SECURE_MC_secure_int_2_display_3_int_en_mask                         (0x00080000)
#define  MC_SECURE_MC_secure_int_2_display_2_int_en_mask                         (0x00040000)
#define  MC_SECURE_MC_secure_int_2_display_1_int_en_mask                         (0x00020000)
#define  MC_SECURE_MC_secure_int_2_display_0_int_en_mask                         (0x00010000)
#define  MC_SECURE_MC_secure_int_2_display_15_int_mask                           (0x00008000)
#define  MC_SECURE_MC_secure_int_2_display_14_int_mask                           (0x00004000)
#define  MC_SECURE_MC_secure_int_2_display_13_int_mask                           (0x00002000)
#define  MC_SECURE_MC_secure_int_2_display_12_int_mask                           (0x00001000)
#define  MC_SECURE_MC_secure_int_2_display_11_int_mask                           (0x00000800)
#define  MC_SECURE_MC_secure_int_2_display_10_int_mask                           (0x00000400)
#define  MC_SECURE_MC_secure_int_2_display_9_int_mask                            (0x00000200)
#define  MC_SECURE_MC_secure_int_2_display_8_int_mask                            (0x00000100)
#define  MC_SECURE_MC_secure_int_2_display_7_int_mask                            (0x00000080)
#define  MC_SECURE_MC_secure_int_2_display_6_int_mask                            (0x00000040)
#define  MC_SECURE_MC_secure_int_2_display_5_int_mask                            (0x00000020)
#define  MC_SECURE_MC_secure_int_2_display_4_int_mask                            (0x00000010)
#define  MC_SECURE_MC_secure_int_2_display_3_int_mask                            (0x00000008)
#define  MC_SECURE_MC_secure_int_2_display_2_int_mask                            (0x00000004)
#define  MC_SECURE_MC_secure_int_2_display_1_int_mask                            (0x00000002)
#define  MC_SECURE_MC_secure_int_2_display_0_int_mask                            (0x00000001)
#define  MC_SECURE_MC_secure_int_2_display_15_int_en(data)                       (0x80000000&((data)<<31))
#define  MC_SECURE_MC_secure_int_2_display_14_int_en(data)                       (0x40000000&((data)<<30))
#define  MC_SECURE_MC_secure_int_2_display_13_int_en(data)                       (0x20000000&((data)<<29))
#define  MC_SECURE_MC_secure_int_2_display_12_int_en(data)                       (0x10000000&((data)<<28))
#define  MC_SECURE_MC_secure_int_2_display_11_int_en(data)                       (0x08000000&((data)<<27))
#define  MC_SECURE_MC_secure_int_2_display_10_int_en(data)                       (0x04000000&((data)<<26))
#define  MC_SECURE_MC_secure_int_2_display_9_int_en(data)                        (0x02000000&((data)<<25))
#define  MC_SECURE_MC_secure_int_2_display_8_int_en(data)                        (0x01000000&((data)<<24))
#define  MC_SECURE_MC_secure_int_2_display_7_int_en(data)                        (0x00800000&((data)<<23))
#define  MC_SECURE_MC_secure_int_2_display_6_int_en(data)                        (0x00400000&((data)<<22))
#define  MC_SECURE_MC_secure_int_2_display_5_int_en(data)                        (0x00200000&((data)<<21))
#define  MC_SECURE_MC_secure_int_2_display_4_int_en(data)                        (0x00100000&((data)<<20))
#define  MC_SECURE_MC_secure_int_2_display_3_int_en(data)                        (0x00080000&((data)<<19))
#define  MC_SECURE_MC_secure_int_2_display_2_int_en(data)                        (0x00040000&((data)<<18))
#define  MC_SECURE_MC_secure_int_2_display_1_int_en(data)                        (0x00020000&((data)<<17))
#define  MC_SECURE_MC_secure_int_2_display_0_int_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_secure_int_2_display_15_int(data)                          (0x00008000&((data)<<15))
#define  MC_SECURE_MC_secure_int_2_display_14_int(data)                          (0x00004000&((data)<<14))
#define  MC_SECURE_MC_secure_int_2_display_13_int(data)                          (0x00002000&((data)<<13))
#define  MC_SECURE_MC_secure_int_2_display_12_int(data)                          (0x00001000&((data)<<12))
#define  MC_SECURE_MC_secure_int_2_display_11_int(data)                          (0x00000800&((data)<<11))
#define  MC_SECURE_MC_secure_int_2_display_10_int(data)                          (0x00000400&((data)<<10))
#define  MC_SECURE_MC_secure_int_2_display_9_int(data)                           (0x00000200&((data)<<9))
#define  MC_SECURE_MC_secure_int_2_display_8_int(data)                           (0x00000100&((data)<<8))
#define  MC_SECURE_MC_secure_int_2_display_7_int(data)                           (0x00000080&((data)<<7))
#define  MC_SECURE_MC_secure_int_2_display_6_int(data)                           (0x00000040&((data)<<6))
#define  MC_SECURE_MC_secure_int_2_display_5_int(data)                           (0x00000020&((data)<<5))
#define  MC_SECURE_MC_secure_int_2_display_4_int(data)                           (0x00000010&((data)<<4))
#define  MC_SECURE_MC_secure_int_2_display_3_int(data)                           (0x00000008&((data)<<3))
#define  MC_SECURE_MC_secure_int_2_display_2_int(data)                           (0x00000004&((data)<<2))
#define  MC_SECURE_MC_secure_int_2_display_1_int(data)                           (0x00000002&((data)<<1))
#define  MC_SECURE_MC_secure_int_2_display_0_int(data)                           (0x00000001&(data))
#define  MC_SECURE_MC_secure_int_2_get_display_15_int_en(data)                   ((0x80000000&(data))>>31)
#define  MC_SECURE_MC_secure_int_2_get_display_14_int_en(data)                   ((0x40000000&(data))>>30)
#define  MC_SECURE_MC_secure_int_2_get_display_13_int_en(data)                   ((0x20000000&(data))>>29)
#define  MC_SECURE_MC_secure_int_2_get_display_12_int_en(data)                   ((0x10000000&(data))>>28)
#define  MC_SECURE_MC_secure_int_2_get_display_11_int_en(data)                   ((0x08000000&(data))>>27)
#define  MC_SECURE_MC_secure_int_2_get_display_10_int_en(data)                   ((0x04000000&(data))>>26)
#define  MC_SECURE_MC_secure_int_2_get_display_9_int_en(data)                    ((0x02000000&(data))>>25)
#define  MC_SECURE_MC_secure_int_2_get_display_8_int_en(data)                    ((0x01000000&(data))>>24)
#define  MC_SECURE_MC_secure_int_2_get_display_7_int_en(data)                    ((0x00800000&(data))>>23)
#define  MC_SECURE_MC_secure_int_2_get_display_6_int_en(data)                    ((0x00400000&(data))>>22)
#define  MC_SECURE_MC_secure_int_2_get_display_5_int_en(data)                    ((0x00200000&(data))>>21)
#define  MC_SECURE_MC_secure_int_2_get_display_4_int_en(data)                    ((0x00100000&(data))>>20)
#define  MC_SECURE_MC_secure_int_2_get_display_3_int_en(data)                    ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_secure_int_2_get_display_2_int_en(data)                    ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_secure_int_2_get_display_1_int_en(data)                    ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_secure_int_2_get_display_0_int_en(data)                    ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_secure_int_2_get_display_15_int(data)                      ((0x00008000&(data))>>15)
#define  MC_SECURE_MC_secure_int_2_get_display_14_int(data)                      ((0x00004000&(data))>>14)
#define  MC_SECURE_MC_secure_int_2_get_display_13_int(data)                      ((0x00002000&(data))>>13)
#define  MC_SECURE_MC_secure_int_2_get_display_12_int(data)                      ((0x00001000&(data))>>12)
#define  MC_SECURE_MC_secure_int_2_get_display_11_int(data)                      ((0x00000800&(data))>>11)
#define  MC_SECURE_MC_secure_int_2_get_display_10_int(data)                      ((0x00000400&(data))>>10)
#define  MC_SECURE_MC_secure_int_2_get_display_9_int(data)                       ((0x00000200&(data))>>9)
#define  MC_SECURE_MC_secure_int_2_get_display_8_int(data)                       ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_secure_int_2_get_display_7_int(data)                       ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_secure_int_2_get_display_6_int(data)                       ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_secure_int_2_get_display_5_int(data)                       ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_secure_int_2_get_display_4_int(data)                       ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_secure_int_2_get_display_3_int(data)                       ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_secure_int_2_get_display_2_int(data)                       ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_secure_int_2_get_display_1_int(data)                       ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_secure_int_2_get_display_0_int(data)                       (0x00000001&(data))

#define  MC_SECURE_MC_secure_int_3                                               0x180B070C
#define  MC_SECURE_MC_secure_int_3_reg_addr                                      "0xB80B070C"
#define  MC_SECURE_MC_secure_int_3_reg                                           0xB80B070C
#define  MC_SECURE_MC_secure_int_3_inst_addr                                     "0x012A"
#define  set_MC_SECURE_MC_secure_int_3_reg(data)                                 (*((volatile unsigned int*)MC_SECURE_MC_secure_int_3_reg)=data)
#define  get_MC_SECURE_MC_secure_int_3_reg                                       (*((volatile unsigned int*)MC_SECURE_MC_secure_int_3_reg))
#define  MC_SECURE_MC_secure_int_3_default_0_int_en_shift                        (16)
#define  MC_SECURE_MC_secure_int_3_default_0_int_shift                           (0)
#define  MC_SECURE_MC_secure_int_3_default_0_int_en_mask                         (0x00010000)
#define  MC_SECURE_MC_secure_int_3_default_0_int_mask                            (0x00000001)
#define  MC_SECURE_MC_secure_int_3_default_0_int_en(data)                        (0x00010000&((data)<<16))
#define  MC_SECURE_MC_secure_int_3_default_0_int(data)                           (0x00000001&(data))
#define  MC_SECURE_MC_secure_int_3_get_default_0_int_en(data)                    ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_secure_int_3_get_default_0_int(data)                       (0x00000001&(data))

#define  MC_SECURE_MC_secure_key_int                                             0x180B0710
#define  MC_SECURE_MC_secure_key_int_reg_addr                                    "0xB80B0710"
#define  MC_SECURE_MC_secure_key_int_reg                                         0xB80B0710
#define  MC_SECURE_MC_secure_key_int_inst_addr                                   "0x012B"
#define  set_MC_SECURE_MC_secure_key_int_reg(data)                               (*((volatile unsigned int*)MC_SECURE_MC_secure_key_int_reg)=data)
#define  get_MC_SECURE_MC_secure_key_int_reg                                     (*((volatile unsigned int*)MC_SECURE_MC_secure_key_int_reg))
#define  MC_SECURE_MC_secure_key_int_content7_key_updated_int_en_shift           (23)
#define  MC_SECURE_MC_secure_key_int_content6_key_updated_int_en_shift           (22)
#define  MC_SECURE_MC_secure_key_int_content5_key_updated_int_en_shift           (21)
#define  MC_SECURE_MC_secure_key_int_content4_key_updated_int_en_shift           (20)
#define  MC_SECURE_MC_secure_key_int_content3_key_updated_int_en_shift           (19)
#define  MC_SECURE_MC_secure_key_int_content2_key_updated_int_en_shift           (18)
#define  MC_SECURE_MC_secure_key_int_content1_key_updated_int_en_shift           (17)
#define  MC_SECURE_MC_secure_key_int_content0_key_updated_int_en_shift           (16)
#define  MC_SECURE_MC_secure_key_int_content7_key_updated_int_shift              (7)
#define  MC_SECURE_MC_secure_key_int_content6_key_updated_int_shift              (6)
#define  MC_SECURE_MC_secure_key_int_content5_key_updated_int_shift              (5)
#define  MC_SECURE_MC_secure_key_int_content4_key_updated_int_shift              (4)
#define  MC_SECURE_MC_secure_key_int_content3_key_updated_int_shift              (3)
#define  MC_SECURE_MC_secure_key_int_content2_key_updated_int_shift              (2)
#define  MC_SECURE_MC_secure_key_int_content1_key_updated_int_shift              (1)
#define  MC_SECURE_MC_secure_key_int_content0_key_updated_int_shift              (0)
#define  MC_SECURE_MC_secure_key_int_content7_key_updated_int_en_mask            (0x00800000)
#define  MC_SECURE_MC_secure_key_int_content6_key_updated_int_en_mask            (0x00400000)
#define  MC_SECURE_MC_secure_key_int_content5_key_updated_int_en_mask            (0x00200000)
#define  MC_SECURE_MC_secure_key_int_content4_key_updated_int_en_mask            (0x00100000)
#define  MC_SECURE_MC_secure_key_int_content3_key_updated_int_en_mask            (0x00080000)
#define  MC_SECURE_MC_secure_key_int_content2_key_updated_int_en_mask            (0x00040000)
#define  MC_SECURE_MC_secure_key_int_content1_key_updated_int_en_mask            (0x00020000)
#define  MC_SECURE_MC_secure_key_int_content0_key_updated_int_en_mask            (0x00010000)
#define  MC_SECURE_MC_secure_key_int_content7_key_updated_int_mask               (0x00000080)
#define  MC_SECURE_MC_secure_key_int_content6_key_updated_int_mask               (0x00000040)
#define  MC_SECURE_MC_secure_key_int_content5_key_updated_int_mask               (0x00000020)
#define  MC_SECURE_MC_secure_key_int_content4_key_updated_int_mask               (0x00000010)
#define  MC_SECURE_MC_secure_key_int_content3_key_updated_int_mask               (0x00000008)
#define  MC_SECURE_MC_secure_key_int_content2_key_updated_int_mask               (0x00000004)
#define  MC_SECURE_MC_secure_key_int_content1_key_updated_int_mask               (0x00000002)
#define  MC_SECURE_MC_secure_key_int_content0_key_updated_int_mask               (0x00000001)
#define  MC_SECURE_MC_secure_key_int_content7_key_updated_int_en(data)           (0x00800000&((data)<<23))
#define  MC_SECURE_MC_secure_key_int_content6_key_updated_int_en(data)           (0x00400000&((data)<<22))
#define  MC_SECURE_MC_secure_key_int_content5_key_updated_int_en(data)           (0x00200000&((data)<<21))
#define  MC_SECURE_MC_secure_key_int_content4_key_updated_int_en(data)           (0x00100000&((data)<<20))
#define  MC_SECURE_MC_secure_key_int_content3_key_updated_int_en(data)           (0x00080000&((data)<<19))
#define  MC_SECURE_MC_secure_key_int_content2_key_updated_int_en(data)           (0x00040000&((data)<<18))
#define  MC_SECURE_MC_secure_key_int_content1_key_updated_int_en(data)           (0x00020000&((data)<<17))
#define  MC_SECURE_MC_secure_key_int_content0_key_updated_int_en(data)           (0x00010000&((data)<<16))
#define  MC_SECURE_MC_secure_key_int_content7_key_updated_int(data)              (0x00000080&((data)<<7))
#define  MC_SECURE_MC_secure_key_int_content6_key_updated_int(data)              (0x00000040&((data)<<6))
#define  MC_SECURE_MC_secure_key_int_content5_key_updated_int(data)              (0x00000020&((data)<<5))
#define  MC_SECURE_MC_secure_key_int_content4_key_updated_int(data)              (0x00000010&((data)<<4))
#define  MC_SECURE_MC_secure_key_int_content3_key_updated_int(data)              (0x00000008&((data)<<3))
#define  MC_SECURE_MC_secure_key_int_content2_key_updated_int(data)              (0x00000004&((data)<<2))
#define  MC_SECURE_MC_secure_key_int_content1_key_updated_int(data)              (0x00000002&((data)<<1))
#define  MC_SECURE_MC_secure_key_int_content0_key_updated_int(data)              (0x00000001&(data))
#define  MC_SECURE_MC_secure_key_int_get_content7_key_updated_int_en(data)       ((0x00800000&(data))>>23)
#define  MC_SECURE_MC_secure_key_int_get_content6_key_updated_int_en(data)       ((0x00400000&(data))>>22)
#define  MC_SECURE_MC_secure_key_int_get_content5_key_updated_int_en(data)       ((0x00200000&(data))>>21)
#define  MC_SECURE_MC_secure_key_int_get_content4_key_updated_int_en(data)       ((0x00100000&(data))>>20)
#define  MC_SECURE_MC_secure_key_int_get_content3_key_updated_int_en(data)       ((0x00080000&(data))>>19)
#define  MC_SECURE_MC_secure_key_int_get_content2_key_updated_int_en(data)       ((0x00040000&(data))>>18)
#define  MC_SECURE_MC_secure_key_int_get_content1_key_updated_int_en(data)       ((0x00020000&(data))>>17)
#define  MC_SECURE_MC_secure_key_int_get_content0_key_updated_int_en(data)       ((0x00010000&(data))>>16)
#define  MC_SECURE_MC_secure_key_int_get_content7_key_updated_int(data)          ((0x00000080&(data))>>7)
#define  MC_SECURE_MC_secure_key_int_get_content6_key_updated_int(data)          ((0x00000040&(data))>>6)
#define  MC_SECURE_MC_secure_key_int_get_content5_key_updated_int(data)          ((0x00000020&(data))>>5)
#define  MC_SECURE_MC_secure_key_int_get_content4_key_updated_int(data)          ((0x00000010&(data))>>4)
#define  MC_SECURE_MC_secure_key_int_get_content3_key_updated_int(data)          ((0x00000008&(data))>>3)
#define  MC_SECURE_MC_secure_key_int_get_content2_key_updated_int(data)          ((0x00000004&(data))>>2)
#define  MC_SECURE_MC_secure_key_int_get_content1_key_updated_int(data)          ((0x00000002&(data))>>1)
#define  MC_SECURE_MC_secure_key_int_get_content0_key_updated_int(data)          (0x00000001&(data))

#define  MC_SECURE_MC_secure_error_info_0                                        0x180B0720
#define  MC_SECURE_MC_secure_error_info_0_reg_addr                               "0xB80B0720"
#define  MC_SECURE_MC_secure_error_info_0_reg                                    0xB80B0720
#define  MC_SECURE_MC_secure_error_info_0_inst_addr                              "0x012C"
#define  set_MC_SECURE_MC_secure_error_info_0_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_secure_error_info_0_reg)=data)
#define  get_MC_SECURE_MC_secure_error_info_0_reg                                (*((volatile unsigned int*)MC_SECURE_MC_secure_error_info_0_reg))
#define  MC_SECURE_MC_secure_error_info_0_err_latch_shift                        (28)
#define  MC_SECURE_MC_secure_error_info_0_err_blk_shift                          (20)
#define  MC_SECURE_MC_secure_error_info_0_err_bl_shift                           (12)
#define  MC_SECURE_MC_secure_error_info_0_err_w_shift                            (8)
#define  MC_SECURE_MC_secure_error_info_0_err_id_shift                           (0)
#define  MC_SECURE_MC_secure_error_info_0_err_latch_mask                         (0x10000000)
#define  MC_SECURE_MC_secure_error_info_0_err_blk_mask                           (0x00100000)
#define  MC_SECURE_MC_secure_error_info_0_err_bl_mask                            (0x000FF000)
#define  MC_SECURE_MC_secure_error_info_0_err_w_mask                             (0x00000100)
#define  MC_SECURE_MC_secure_error_info_0_err_id_mask                            (0x000000FF)
#define  MC_SECURE_MC_secure_error_info_0_err_latch(data)                        (0x10000000&((data)<<28))
#define  MC_SECURE_MC_secure_error_info_0_err_blk(data)                          (0x00100000&((data)<<20))
#define  MC_SECURE_MC_secure_error_info_0_err_bl(data)                           (0x000FF000&((data)<<12))
#define  MC_SECURE_MC_secure_error_info_0_err_w(data)                            (0x00000100&((data)<<8))
#define  MC_SECURE_MC_secure_error_info_0_err_id(data)                           (0x000000FF&(data))
#define  MC_SECURE_MC_secure_error_info_0_get_err_latch(data)                    ((0x10000000&(data))>>28)
#define  MC_SECURE_MC_secure_error_info_0_get_err_blk(data)                      ((0x00100000&(data))>>20)
#define  MC_SECURE_MC_secure_error_info_0_get_err_bl(data)                       ((0x000FF000&(data))>>12)
#define  MC_SECURE_MC_secure_error_info_0_get_err_w(data)                        ((0x00000100&(data))>>8)
#define  MC_SECURE_MC_secure_error_info_0_get_err_id(data)                       (0x000000FF&(data))

#define  MC_SECURE_MC_secure_error_info_1                                        0x180B0724
#define  MC_SECURE_MC_secure_error_info_1_reg_addr                               "0xB80B0724"
#define  MC_SECURE_MC_secure_error_info_1_reg                                    0xB80B0724
#define  MC_SECURE_MC_secure_error_info_1_inst_addr                              "0x012D"
#define  set_MC_SECURE_MC_secure_error_info_1_reg(data)                          (*((volatile unsigned int*)MC_SECURE_MC_secure_error_info_1_reg)=data)
#define  get_MC_SECURE_MC_secure_error_info_1_reg                                (*((volatile unsigned int*)MC_SECURE_MC_secure_error_info_1_reg))
#define  MC_SECURE_MC_secure_error_info_1_err_addr_shift                         (3)
#define  MC_SECURE_MC_secure_error_info_1_err_addr_mask                          (0xFFFFFFF8)
#define  MC_SECURE_MC_secure_error_info_1_err_addr(data)                         (0xFFFFFFF8&((data)<<3))
#define  MC_SECURE_MC_secure_error_info_1_get_err_addr(data)                     ((0xFFFFFFF8&(data))>>3)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MC_SECURE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  global_scramble_en:1;
    };
}mc_secure_mc_global_scramble_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key1:16;
        RBus_UInt32  key0:16;
    };
}mc_secure_mc_mem_scramble_global_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key3:16;
        RBus_UInt32  key2:16;
    };
}mc_secure_mc_mem_scramble_global_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key5:16;
        RBus_UInt32  key4:16;
    };
}mc_secure_mc_mem_scramble_global_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key7:16;
        RBus_UInt32  key6:16;
    };
}mc_secure_mc_mem_scramble_global_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key9:16;
        RBus_UInt32  key8:16;
    };
}mc_secure_mc_mem_scramble_global_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyb:16;
        RBus_UInt32  keya:16;
    };
}mc_secure_mc_mem_scramble_global_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyd:16;
        RBus_UInt32  keyc:16;
    };
}mc_secure_mc_mem_scramble_global_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  protect_3_en:1;
        RBus_UInt32  protect_2_en:1;
        RBus_UInt32  protect_1_en:1;
        RBus_UInt32  protect_0_en:1;
        RBus_UInt32  res2:16;
    };
}mc_secure_mc_mem_protect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_secure_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_mem_protect_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_mem_protect_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_kc:1;
    };
}mc_secure_mc_mem_protect_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_kc:1;
    };
}mc_secure_mc_mem_protect_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  content_7_en:1;
        RBus_UInt32  content_6_en:1;
        RBus_UInt32  content_5_en:1;
        RBus_UInt32  content_4_en:1;
        RBus_UInt32  content_3_en:1;
        RBus_UInt32  content_2_en:1;
        RBus_UInt32  content_1_en:1;
        RBus_UInt32  content_0_en:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  scramble_7_en:1;
        RBus_UInt32  scramble_6_en:1;
        RBus_UInt32  scramble_5_en:1;
        RBus_UInt32  scramble_4_en:1;
        RBus_UInt32  scramble_3_en:1;
        RBus_UInt32  scramble_2_en:1;
        RBus_UInt32  scramble_1_en:1;
        RBus_UInt32  scramble_0_en:1;
    };
}mc_secure_mc_mem_content_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  acpu:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ade:1;
        RBus_UInt32  ae:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_vc:1;
    };
}mc_secure_mc_scramble_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  acpu:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ade:1;
        RBus_UInt32  ae:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_vc:1;
    };
}mc_secure_mc_scramble_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_mem_scramble_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_mem_scramble_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key1:16;
        RBus_UInt32  key0:16;
    };
}mc_secure_mc_mem_scramble_buf_cur0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key3:16;
        RBus_UInt32  key2:16;
    };
}mc_secure_mc_mem_scramble_buf_cur1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key5:16;
        RBus_UInt32  key4:16;
    };
}mc_secure_mc_mem_scramble_buf_cur2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key7:16;
        RBus_UInt32  key6:16;
    };
}mc_secure_mc_mem_scramble_buf_cur3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key9:16;
        RBus_UInt32  key8:16;
    };
}mc_secure_mc_mem_scramble_buf_cur4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyb:16;
        RBus_UInt32  keya:16;
    };
}mc_secure_mc_mem_scramble_buf_cur5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyd:16;
        RBus_UInt32  keyc:16;
    };
}mc_secure_mc_mem_scramble_buf_cur6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key1:16;
        RBus_UInt32  key0:16;
    };
}mc_secure_mc_mem_scramble_buf_pre0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key3:16;
        RBus_UInt32  key2:16;
    };
}mc_secure_mc_mem_scramble_buf_pre1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key5:16;
        RBus_UInt32  key4:16;
    };
}mc_secure_mc_mem_scramble_buf_pre2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key7:16;
        RBus_UInt32  key6:16;
    };
}mc_secure_mc_mem_scramble_buf_pre3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key9:16;
        RBus_UInt32  key8:16;
    };
}mc_secure_mc_mem_scramble_buf_pre4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyb:16;
        RBus_UInt32  keya:16;
    };
}mc_secure_mc_mem_scramble_buf_pre5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyd:16;
        RBus_UInt32  keyc:16;
    };
}mc_secure_mc_mem_scramble_buf_pre6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key1:16;
        RBus_UInt32  key0:16;
    };
}mc_secure_mc_mem_scramble_buf_up0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key3:16;
        RBus_UInt32  key2:16;
    };
}mc_secure_mc_mem_scramble_buf_up1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key5:16;
        RBus_UInt32  key4:16;
    };
}mc_secure_mc_mem_scramble_buf_up2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key7:16;
        RBus_UInt32  key6:16;
    };
}mc_secure_mc_mem_scramble_buf_up3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key9:16;
        RBus_UInt32  key8:16;
    };
}mc_secure_mc_mem_scramble_buf_up4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyb:16;
        RBus_UInt32  keya:16;
    };
}mc_secure_mc_mem_scramble_buf_up5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyd:16;
        RBus_UInt32  keyc:16;
    };
}mc_secure_mc_mem_scramble_buf_up6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gpu_id_mode:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  display_15_en:1;
        RBus_UInt32  display_14_en:1;
        RBus_UInt32  display_13_en:1;
        RBus_UInt32  display_12_en:1;
        RBus_UInt32  display_11_en:1;
        RBus_UInt32  display_10_en:1;
        RBus_UInt32  display_9_en:1;
        RBus_UInt32  display_8_en:1;
        RBus_UInt32  display_7_en:1;
        RBus_UInt32  display_6_en:1;
        RBus_UInt32  display_5_en:1;
        RBus_UInt32  display_4_en:1;
        RBus_UInt32  display_3_en:1;
        RBus_UInt32  display_2_en:1;
        RBus_UInt32  display_1_en:1;
        RBus_UInt32  display_0_en:1;
        RBus_UInt32  res2:8;
    };
}mc_secure_mc_mem_display_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_display_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:20;
        RBus_UInt32  res1:12;
    };
}mc_secure_mc_display_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  se:2;
        RBus_UInt32  gpu:8;
        RBus_UInt32  dispd:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  me:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_vc:1;
    };
}mc_secure_mc_display_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  se:2;
        RBus_UInt32  gpu:8;
        RBus_UInt32  dispd:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  me:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_vc:1;
    };
}mc_secure_mc_display_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  default_0_en:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  res3:1;
    };
}mc_secure_mc_mem_default_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  se:2;
        RBus_UInt32  gpu:8;
        RBus_UInt32  dispd:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_vc:1;
    };
}mc_secure_mc_default_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  se:2;
        RBus_UInt32  gpu:8;
        RBus_UInt32  dispd:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_vc:1;
    };
}mc_secure_mc_default_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_over_max_secure_addr_int_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  protect_3_int_en:1;
        RBus_UInt32  protect_2_int_en:1;
        RBus_UInt32  protect_1_int_en:1;
        RBus_UInt32  protect_0_int_en:1;
        RBus_UInt32  seq_over_max_secure_addr_int:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  protect_3_int:1;
        RBus_UInt32  protect_2_int:1;
        RBus_UInt32  protect_1_int:1;
        RBus_UInt32  protect_0_int:1;
    };
}mc_secure_mc_secure_int_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  content_7_int_en:1;
        RBus_UInt32  content_6_int_en:1;
        RBus_UInt32  content_5_int_en:1;
        RBus_UInt32  content_4_int_en:1;
        RBus_UInt32  content_3_int_en:1;
        RBus_UInt32  content_2_int_en:1;
        RBus_UInt32  content_1_int_en:1;
        RBus_UInt32  content_0_int_en:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  content_7_int:1;
        RBus_UInt32  content_6_int:1;
        RBus_UInt32  content_5_int:1;
        RBus_UInt32  content_4_int:1;
        RBus_UInt32  content_3_int:1;
        RBus_UInt32  content_2_int:1;
        RBus_UInt32  content_1_int:1;
        RBus_UInt32  content_0_int:1;
    };
}mc_secure_mc_secure_int_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  display_15_int_en:1;
        RBus_UInt32  display_14_int_en:1;
        RBus_UInt32  display_13_int_en:1;
        RBus_UInt32  display_12_int_en:1;
        RBus_UInt32  display_11_int_en:1;
        RBus_UInt32  display_10_int_en:1;
        RBus_UInt32  display_9_int_en:1;
        RBus_UInt32  display_8_int_en:1;
        RBus_UInt32  display_7_int_en:1;
        RBus_UInt32  display_6_int_en:1;
        RBus_UInt32  display_5_int_en:1;
        RBus_UInt32  display_4_int_en:1;
        RBus_UInt32  display_3_int_en:1;
        RBus_UInt32  display_2_int_en:1;
        RBus_UInt32  display_1_int_en:1;
        RBus_UInt32  display_0_int_en:1;
        RBus_UInt32  display_15_int:1;
        RBus_UInt32  display_14_int:1;
        RBus_UInt32  display_13_int:1;
        RBus_UInt32  display_12_int:1;
        RBus_UInt32  display_11_int:1;
        RBus_UInt32  display_10_int:1;
        RBus_UInt32  display_9_int:1;
        RBus_UInt32  display_8_int:1;
        RBus_UInt32  display_7_int:1;
        RBus_UInt32  display_6_int:1;
        RBus_UInt32  display_5_int:1;
        RBus_UInt32  display_4_int:1;
        RBus_UInt32  display_3_int:1;
        RBus_UInt32  display_2_int:1;
        RBus_UInt32  display_1_int:1;
        RBus_UInt32  display_0_int:1;
    };
}mc_secure_mc_secure_int_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  default_0_int_en:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  default_0_int:1;
    };
}mc_secure_mc_secure_int_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  content7_key_updated_int_en:1;
        RBus_UInt32  content6_key_updated_int_en:1;
        RBus_UInt32  content5_key_updated_int_en:1;
        RBus_UInt32  content4_key_updated_int_en:1;
        RBus_UInt32  content3_key_updated_int_en:1;
        RBus_UInt32  content2_key_updated_int_en:1;
        RBus_UInt32  content1_key_updated_int_en:1;
        RBus_UInt32  content0_key_updated_int_en:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  content7_key_updated_int:1;
        RBus_UInt32  content6_key_updated_int:1;
        RBus_UInt32  content5_key_updated_int:1;
        RBus_UInt32  content4_key_updated_int:1;
        RBus_UInt32  content3_key_updated_int:1;
        RBus_UInt32  content2_key_updated_int:1;
        RBus_UInt32  content1_key_updated_int:1;
        RBus_UInt32  content0_key_updated_int:1;
    };
}mc_secure_mc_secure_key_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  err_latch:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  err_blk:1;
        RBus_UInt32  err_bl:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  err_w:1;
        RBus_UInt32  err_id:8;
    };
}mc_secure_mc_secure_error_info_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_addr:29;
        RBus_UInt32  res1:3;
    };
}mc_secure_mc_secure_error_info_1_RBUS;

#else //apply LITTLE_ENDIAN

//======MC_SECURE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_scramble_en:1;
        RBus_UInt32  res1:31;
    };
}mc_secure_mc_global_scramble_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key0:16;
        RBus_UInt32  key1:16;
    };
}mc_secure_mc_mem_scramble_global_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key2:16;
        RBus_UInt32  key3:16;
    };
}mc_secure_mc_mem_scramble_global_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key4:16;
        RBus_UInt32  key5:16;
    };
}mc_secure_mc_mem_scramble_global_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key6:16;
        RBus_UInt32  key7:16;
    };
}mc_secure_mc_mem_scramble_global_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key8:16;
        RBus_UInt32  key9:16;
    };
}mc_secure_mc_mem_scramble_global_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keya:16;
        RBus_UInt32  keyb:16;
    };
}mc_secure_mc_mem_scramble_global_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyc:16;
        RBus_UInt32  keyd:16;
    };
}mc_secure_mc_mem_scramble_global_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  protect_0_en:1;
        RBus_UInt32  protect_1_en:1;
        RBus_UInt32  protect_2_en:1;
        RBus_UInt32  protect_3_en:1;
        RBus_UInt32  res2:12;
    };
}mc_secure_mc_mem_protect_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_secure_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_mem_protect_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_mem_protect_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  res1:27;
    };
}mc_secure_mc_mem_protect_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_kc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  res1:27;
    };
}mc_secure_mc_mem_protect_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scramble_0_en:1;
        RBus_UInt32  scramble_1_en:1;
        RBus_UInt32  scramble_2_en:1;
        RBus_UInt32  scramble_3_en:1;
        RBus_UInt32  scramble_4_en:1;
        RBus_UInt32  scramble_5_en:1;
        RBus_UInt32  scramble_6_en:1;
        RBus_UInt32  scramble_7_en:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  content_0_en:1;
        RBus_UInt32  content_1_en:1;
        RBus_UInt32  content_2_en:1;
        RBus_UInt32  content_3_en:1;
        RBus_UInt32  content_4_en:1;
        RBus_UInt32  content_5_en:1;
        RBus_UInt32  content_6_en:1;
        RBus_UInt32  content_7_en:1;
        RBus_UInt32  res2:8;
    };
}mc_secure_mc_mem_content_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_vc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  ae:1;
        RBus_UInt32  ade:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  acpu:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  res3:18;
    };
}mc_secure_mc_scramble_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_vc:1;
        RBus_UInt32  cp_kc:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  ae:1;
        RBus_UInt32  ade:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  nf_kc:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  acpu:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  emmc_kc:1;
        RBus_UInt32  tp_kc:1;
        RBus_UInt32  res3:18;
    };
}mc_secure_mc_scramble_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_mem_scramble_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_mem_scramble_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key0:16;
        RBus_UInt32  key1:16;
    };
}mc_secure_mc_mem_scramble_buf_cur0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key2:16;
        RBus_UInt32  key3:16;
    };
}mc_secure_mc_mem_scramble_buf_cur1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key4:16;
        RBus_UInt32  key5:16;
    };
}mc_secure_mc_mem_scramble_buf_cur2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key6:16;
        RBus_UInt32  key7:16;
    };
}mc_secure_mc_mem_scramble_buf_cur3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key8:16;
        RBus_UInt32  key9:16;
    };
}mc_secure_mc_mem_scramble_buf_cur4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keya:16;
        RBus_UInt32  keyb:16;
    };
}mc_secure_mc_mem_scramble_buf_cur5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyc:16;
        RBus_UInt32  keyd:16;
    };
}mc_secure_mc_mem_scramble_buf_cur6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key0:16;
        RBus_UInt32  key1:16;
    };
}mc_secure_mc_mem_scramble_buf_pre0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key2:16;
        RBus_UInt32  key3:16;
    };
}mc_secure_mc_mem_scramble_buf_pre1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key4:16;
        RBus_UInt32  key5:16;
    };
}mc_secure_mc_mem_scramble_buf_pre2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key6:16;
        RBus_UInt32  key7:16;
    };
}mc_secure_mc_mem_scramble_buf_pre3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key8:16;
        RBus_UInt32  key9:16;
    };
}mc_secure_mc_mem_scramble_buf_pre4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keya:16;
        RBus_UInt32  keyb:16;
    };
}mc_secure_mc_mem_scramble_buf_pre5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyc:16;
        RBus_UInt32  keyd:16;
    };
}mc_secure_mc_mem_scramble_buf_pre6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key0:16;
        RBus_UInt32  key1:16;
    };
}mc_secure_mc_mem_scramble_buf_up0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key2:16;
        RBus_UInt32  key3:16;
    };
}mc_secure_mc_mem_scramble_buf_up1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key4:16;
        RBus_UInt32  key5:16;
    };
}mc_secure_mc_mem_scramble_buf_up2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key6:16;
        RBus_UInt32  key7:16;
    };
}mc_secure_mc_mem_scramble_buf_up3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  key8:16;
        RBus_UInt32  key9:16;
    };
}mc_secure_mc_mem_scramble_buf_up4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keya:16;
        RBus_UInt32  keyb:16;
    };
}mc_secure_mc_mem_scramble_buf_up5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  keyc:16;
        RBus_UInt32  keyd:16;
    };
}mc_secure_mc_mem_scramble_buf_up6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  display_0_en:1;
        RBus_UInt32  display_1_en:1;
        RBus_UInt32  display_2_en:1;
        RBus_UInt32  display_3_en:1;
        RBus_UInt32  display_4_en:1;
        RBus_UInt32  display_5_en:1;
        RBus_UInt32  display_6_en:1;
        RBus_UInt32  display_7_en:1;
        RBus_UInt32  display_8_en:1;
        RBus_UInt32  display_9_en:1;
        RBus_UInt32  display_10_en:1;
        RBus_UInt32  display_11_en:1;
        RBus_UInt32  display_12_en:1;
        RBus_UInt32  display_13_en:1;
        RBus_UInt32  display_14_en:1;
        RBus_UInt32  display_15_en:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  gpu_id_mode:2;
    };
}mc_secure_mc_mem_display_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_display_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  addr:20;
    };
}mc_secure_mc_display_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_vc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  me:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispd:1;
        RBus_UInt32  gpu:8;
        RBus_UInt32  se:2;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  res3:5;
    };
}mc_secure_mc_display_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_vc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  me:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispd:1;
        RBus_UInt32  gpu:8;
        RBus_UInt32  se:2;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  res3:5;
    };
}mc_secure_mc_display_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  default_0_en:1;
        RBus_UInt32  res3:15;
    };
}mc_secure_mc_mem_default_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_vc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispd:1;
        RBus_UInt32  gpu:8;
        RBus_UInt32  se:2;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  res4:5;
    };
}mc_secure_mc_default_access_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_vc:1;
        RBus_UInt32  scpu:1;
        RBus_UInt32  md_kc:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vde:1;
        RBus_UInt32  ve:1;
        RBus_UInt32  vcpu:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  subtitle:1;
        RBus_UInt32  osd:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  memc:1;
        RBus_UInt32  dispi:1;
        RBus_UInt32  dispm:1;
        RBus_UInt32  dispd:1;
        RBus_UInt32  gpu:8;
        RBus_UInt32  se:2;
        RBus_UInt32  rbusdma:1;
        RBus_UInt32  res4:5;
    };
}mc_secure_mc_default_access_w_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  protect_0_int:1;
        RBus_UInt32  protect_1_int:1;
        RBus_UInt32  protect_2_int:1;
        RBus_UInt32  protect_3_int:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  seq_over_max_secure_addr_int:1;
        RBus_UInt32  protect_0_int_en:1;
        RBus_UInt32  protect_1_int_en:1;
        RBus_UInt32  protect_2_int_en:1;
        RBus_UInt32  protect_3_int_en:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  seq_over_max_secure_addr_int_en:1;
    };
}mc_secure_mc_secure_int_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  content_0_int:1;
        RBus_UInt32  content_1_int:1;
        RBus_UInt32  content_2_int:1;
        RBus_UInt32  content_3_int:1;
        RBus_UInt32  content_4_int:1;
        RBus_UInt32  content_5_int:1;
        RBus_UInt32  content_6_int:1;
        RBus_UInt32  content_7_int:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  content_0_int_en:1;
        RBus_UInt32  content_1_int_en:1;
        RBus_UInt32  content_2_int_en:1;
        RBus_UInt32  content_3_int_en:1;
        RBus_UInt32  content_4_int_en:1;
        RBus_UInt32  content_5_int_en:1;
        RBus_UInt32  content_6_int_en:1;
        RBus_UInt32  content_7_int_en:1;
        RBus_UInt32  res2:8;
    };
}mc_secure_mc_secure_int_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  display_0_int:1;
        RBus_UInt32  display_1_int:1;
        RBus_UInt32  display_2_int:1;
        RBus_UInt32  display_3_int:1;
        RBus_UInt32  display_4_int:1;
        RBus_UInt32  display_5_int:1;
        RBus_UInt32  display_6_int:1;
        RBus_UInt32  display_7_int:1;
        RBus_UInt32  display_8_int:1;
        RBus_UInt32  display_9_int:1;
        RBus_UInt32  display_10_int:1;
        RBus_UInt32  display_11_int:1;
        RBus_UInt32  display_12_int:1;
        RBus_UInt32  display_13_int:1;
        RBus_UInt32  display_14_int:1;
        RBus_UInt32  display_15_int:1;
        RBus_UInt32  display_0_int_en:1;
        RBus_UInt32  display_1_int_en:1;
        RBus_UInt32  display_2_int_en:1;
        RBus_UInt32  display_3_int_en:1;
        RBus_UInt32  display_4_int_en:1;
        RBus_UInt32  display_5_int_en:1;
        RBus_UInt32  display_6_int_en:1;
        RBus_UInt32  display_7_int_en:1;
        RBus_UInt32  display_8_int_en:1;
        RBus_UInt32  display_9_int_en:1;
        RBus_UInt32  display_10_int_en:1;
        RBus_UInt32  display_11_int_en:1;
        RBus_UInt32  display_12_int_en:1;
        RBus_UInt32  display_13_int_en:1;
        RBus_UInt32  display_14_int_en:1;
        RBus_UInt32  display_15_int_en:1;
    };
}mc_secure_mc_secure_int_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  default_0_int:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  default_0_int_en:1;
        RBus_UInt32  res2:15;
    };
}mc_secure_mc_secure_int_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  content0_key_updated_int:1;
        RBus_UInt32  content1_key_updated_int:1;
        RBus_UInt32  content2_key_updated_int:1;
        RBus_UInt32  content3_key_updated_int:1;
        RBus_UInt32  content4_key_updated_int:1;
        RBus_UInt32  content5_key_updated_int:1;
        RBus_UInt32  content6_key_updated_int:1;
        RBus_UInt32  content7_key_updated_int:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  content0_key_updated_int_en:1;
        RBus_UInt32  content1_key_updated_int_en:1;
        RBus_UInt32  content2_key_updated_int_en:1;
        RBus_UInt32  content3_key_updated_int_en:1;
        RBus_UInt32  content4_key_updated_int_en:1;
        RBus_UInt32  content5_key_updated_int_en:1;
        RBus_UInt32  content6_key_updated_int_en:1;
        RBus_UInt32  content7_key_updated_int_en:1;
        RBus_UInt32  res2:8;
    };
}mc_secure_mc_secure_key_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  err_id:8;
        RBus_UInt32  err_w:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  err_bl:8;
        RBus_UInt32  err_blk:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  err_latch:1;
        RBus_UInt32  res3:3;
    };
}mc_secure_mc_secure_error_info_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  err_addr:29;
    };
}mc_secure_mc_secure_error_info_1_RBUS;




#endif 


#endif 
