/**
* @file rbusCabac_p2Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CABAC_P2_REG_H_
#define _RBUS_CABAC_P2_REG_H_

#include "rbusTypes.h"



//  CABAC_P2 Register Address
#define  CABAC_P2_CABAC_LEFTTOP_0                                                0x1800E030
#define  CABAC_P2_CABAC_LEFTTOP_0_reg_addr                                       "0xB800E030"
#define  CABAC_P2_CABAC_LEFTTOP_0_reg                                            0xB800E030
#define  CABAC_P2_CABAC_LEFTTOP_0_inst_addr                                      "0x0000"
#define  CABAC_P2_CABAC_LEFTTOP_0_inst_adr                                       "0x000C"
#define  CABAC_P2_CABAC_LEFTTOP_0_inst                                           0x000C
#define  set_CABAC_P2_CABAC_LEFTTOP_0_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_0_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTTOP_0_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_0_reg))
#define  CABAC_P2_CABAC_LEFTTOP_left_top_shift                                   (0)
#define  CABAC_P2_CABAC_LEFTTOP_left_top_mask                                    (0xFFFFFFFF)
#define  CABAC_P2_CABAC_LEFTTOP_left_top(data)                                   (0xFFFFFFFF&(data))
#define  CABAC_P2_CABAC_LEFTTOP_get_left_top(data)                               (0xFFFFFFFF&(data))
#define  CABAC_P2_CABAC_LEFTTOP_left_top_src(data)                               (0xFFFFFFFF&(data))

#define  CABAC_P2_CABAC_LEFTTOP_1                                                0x1800E034
#define  CABAC_P2_CABAC_LEFTTOP_1_reg_addr                                       "0xB800E034"
#define  CABAC_P2_CABAC_LEFTTOP_1_reg                                            0xB800E034
#define  CABAC_P2_CABAC_LEFTTOP_1_inst_addr                                      "0x0001"
#define  CABAC_P2_CABAC_LEFTTOP_1_inst_adr                                       "0x000D"
#define  CABAC_P2_CABAC_LEFTTOP_1_inst                                           0x000D
#define  set_CABAC_P2_CABAC_LEFTTOP_1_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_1_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTTOP_1_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_1_reg))

#define  CABAC_P2_CABAC_LEFTTOP_2                                                0x1800E038
#define  CABAC_P2_CABAC_LEFTTOP_2_reg_addr                                       "0xB800E038"
#define  CABAC_P2_CABAC_LEFTTOP_2_reg                                            0xB800E038
#define  CABAC_P2_CABAC_LEFTTOP_2_inst_addr                                      "0x0002"
#define  CABAC_P2_CABAC_LEFTTOP_2_inst_adr                                       "0x000E"
#define  CABAC_P2_CABAC_LEFTTOP_2_inst                                           0x000E
#define  set_CABAC_P2_CABAC_LEFTTOP_2_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_2_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTTOP_2_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_2_reg))

#define  CABAC_P2_CABAC_LEFTTOP_3                                                0x1800E03C
#define  CABAC_P2_CABAC_LEFTTOP_3_reg_addr                                       "0xB800E03C"
#define  CABAC_P2_CABAC_LEFTTOP_3_reg                                            0xB800E03C
#define  CABAC_P2_CABAC_LEFTTOP_3_inst_addr                                      "0x0003"
#define  CABAC_P2_CABAC_LEFTTOP_3_inst_adr                                       "0x000F"
#define  CABAC_P2_CABAC_LEFTTOP_3_inst                                           0x000F
#define  set_CABAC_P2_CABAC_LEFTTOP_3_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_3_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTTOP_3_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_3_reg))

#define  CABAC_P2_CABAC_LEFTTOP_4                                                0x1800E040
#define  CABAC_P2_CABAC_LEFTTOP_4_reg_addr                                       "0xB800E040"
#define  CABAC_P2_CABAC_LEFTTOP_4_reg                                            0xB800E040
#define  CABAC_P2_CABAC_LEFTTOP_4_inst_addr                                      "0x0004"
#define  CABAC_P2_CABAC_LEFTTOP_4_inst_adr                                       "0x0010"
#define  CABAC_P2_CABAC_LEFTTOP_4_inst                                           0x0010
#define  set_CABAC_P2_CABAC_LEFTTOP_4_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_4_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTTOP_4_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_4_reg))

#define  CABAC_P2_CABAC_LEFTTOP_5                                                0x1800E044
#define  CABAC_P2_CABAC_LEFTTOP_5_reg_addr                                       "0xB800E044"
#define  CABAC_P2_CABAC_LEFTTOP_5_reg                                            0xB800E044
#define  CABAC_P2_CABAC_LEFTTOP_5_inst_addr                                      "0x0005"
#define  CABAC_P2_CABAC_LEFTTOP_5_inst_adr                                       "0x0011"
#define  CABAC_P2_CABAC_LEFTTOP_5_inst                                           0x0011
#define  set_CABAC_P2_CABAC_LEFTTOP_5_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_5_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTTOP_5_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTTOP_5_reg))

#define  CABAC_P2_CABAC_LEFTBOT_0                                                0x1800E050
#define  CABAC_P2_CABAC_LEFTBOT_0_reg_addr                                       "0xB800E050"
#define  CABAC_P2_CABAC_LEFTBOT_0_reg                                            0xB800E050
#define  CABAC_P2_CABAC_LEFTBOT_0_inst_addr                                      "0x0006"
#define  CABAC_P2_CABAC_LEFTBOT_0_inst_adr                                       "0x0014"
#define  CABAC_P2_CABAC_LEFTBOT_0_inst                                           0x0014
#define  set_CABAC_P2_CABAC_LEFTBOT_0_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_0_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTBOT_0_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_0_reg))
#define  CABAC_P2_CABAC_LEFTBOT_left_bot_shift                                   (0)
#define  CABAC_P2_CABAC_LEFTBOT_left_bot_mask                                    (0xFFFFFFFF)
#define  CABAC_P2_CABAC_LEFTBOT_left_bot(data)                                   (0xFFFFFFFF&(data))
#define  CABAC_P2_CABAC_LEFTBOT_get_left_bot(data)                               (0xFFFFFFFF&(data))
#define  CABAC_P2_CABAC_LEFTBOT_left_bot_src(data)                               (0xFFFFFFFF&(data))

#define  CABAC_P2_CABAC_LEFTBOT_1                                                0x1800E054
#define  CABAC_P2_CABAC_LEFTBOT_1_reg_addr                                       "0xB800E054"
#define  CABAC_P2_CABAC_LEFTBOT_1_reg                                            0xB800E054
#define  CABAC_P2_CABAC_LEFTBOT_1_inst_addr                                      "0x0007"
#define  CABAC_P2_CABAC_LEFTBOT_1_inst_adr                                       "0x0015"
#define  CABAC_P2_CABAC_LEFTBOT_1_inst                                           0x0015
#define  set_CABAC_P2_CABAC_LEFTBOT_1_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_1_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTBOT_1_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_1_reg))

#define  CABAC_P2_CABAC_LEFTBOT_2                                                0x1800E058
#define  CABAC_P2_CABAC_LEFTBOT_2_reg_addr                                       "0xB800E058"
#define  CABAC_P2_CABAC_LEFTBOT_2_reg                                            0xB800E058
#define  CABAC_P2_CABAC_LEFTBOT_2_inst_addr                                      "0x0008"
#define  CABAC_P2_CABAC_LEFTBOT_2_inst_adr                                       "0x0016"
#define  CABAC_P2_CABAC_LEFTBOT_2_inst                                           0x0016
#define  set_CABAC_P2_CABAC_LEFTBOT_2_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_2_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTBOT_2_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_2_reg))

#define  CABAC_P2_CABAC_LEFTBOT_3                                                0x1800E05C
#define  CABAC_P2_CABAC_LEFTBOT_3_reg_addr                                       "0xB800E05C"
#define  CABAC_P2_CABAC_LEFTBOT_3_reg                                            0xB800E05C
#define  CABAC_P2_CABAC_LEFTBOT_3_inst_addr                                      "0x0009"
#define  CABAC_P2_CABAC_LEFTBOT_3_inst_adr                                       "0x0017"
#define  CABAC_P2_CABAC_LEFTBOT_3_inst                                           0x0017
#define  set_CABAC_P2_CABAC_LEFTBOT_3_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_3_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTBOT_3_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_3_reg))

#define  CABAC_P2_CABAC_LEFTBOT_4                                                0x1800E060
#define  CABAC_P2_CABAC_LEFTBOT_4_reg_addr                                       "0xB800E060"
#define  CABAC_P2_CABAC_LEFTBOT_4_reg                                            0xB800E060
#define  CABAC_P2_CABAC_LEFTBOT_4_inst_addr                                      "0x000A"
#define  CABAC_P2_CABAC_LEFTBOT_4_inst_adr                                       "0x0018"
#define  CABAC_P2_CABAC_LEFTBOT_4_inst                                           0x0018
#define  set_CABAC_P2_CABAC_LEFTBOT_4_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_4_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTBOT_4_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_4_reg))

#define  CABAC_P2_CABAC_LEFTBOT_5                                                0x1800E064
#define  CABAC_P2_CABAC_LEFTBOT_5_reg_addr                                       "0xB800E064"
#define  CABAC_P2_CABAC_LEFTBOT_5_reg                                            0xB800E064
#define  CABAC_P2_CABAC_LEFTBOT_5_inst_addr                                      "0x000B"
#define  CABAC_P2_CABAC_LEFTBOT_5_inst_adr                                       "0x0019"
#define  CABAC_P2_CABAC_LEFTBOT_5_inst                                           0x0019
#define  set_CABAC_P2_CABAC_LEFTBOT_5_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_5_reg)=data)
#define  get_CABAC_P2_CABAC_LEFTBOT_5_reg                                        (*((volatile unsigned int*)CABAC_P2_CABAC_LEFTBOT_5_reg))

#define  CABAC_P2_CABAC_P2_CNTL3                                                 0x1800E360
#define  CABAC_P2_CABAC_P2_CNTL3_reg_addr                                        "0xB800E360"
#define  CABAC_P2_CABAC_P2_CNTL3_reg                                             0xB800E360
#define  CABAC_P2_CABAC_P2_CNTL3_inst_addr                                       "0x000C"
#define  CABAC_P2_CABAC_P2_CNTL3_inst_adr                                        "0x00D8"
#define  CABAC_P2_CABAC_P2_CNTL3_inst                                            0x00D8
#define  set_CABAC_P2_CABAC_P2_CNTL3_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL3_reg)=data)
#define  get_CABAC_P2_CABAC_P2_CNTL3_reg                                         (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL3_reg))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable7_shift                             (30)
#define  CABAC_P2_CABAC_P2_CNTL3_reset_cabacp2_bsfifo_shift                      (29)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable6_shift                             (28)
#define  CABAC_P2_CABAC_P2_CNTL3_decode_en_cabacp2_shift                         (27)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable5_shift                             (26)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_1p_mode_shift                             (25)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable4_shift                             (24)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_p3_shift                               (23)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable3_shift                             (22)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_go_shift                               (21)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable2_shift                             (20)
#define  CABAC_P2_CABAC_P2_CNTL3_latch_enable_shift                              (19)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable1_shift                             (18)
#define  CABAC_P2_CABAC_P2_CNTL3_codioffset_shift                                (9)
#define  CABAC_P2_CABAC_P2_CNTL3_codirange_shift                                 (0)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable7_mask                              (0x40000000)
#define  CABAC_P2_CABAC_P2_CNTL3_reset_cabacp2_bsfifo_mask                       (0x20000000)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable6_mask                              (0x10000000)
#define  CABAC_P2_CABAC_P2_CNTL3_decode_en_cabacp2_mask                          (0x08000000)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable5_mask                              (0x04000000)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_1p_mode_mask                              (0x02000000)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable4_mask                              (0x01000000)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_p3_mask                                (0x00800000)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable3_mask                              (0x00400000)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_go_mask                                (0x00200000)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable2_mask                              (0x00100000)
#define  CABAC_P2_CABAC_P2_CNTL3_latch_enable_mask                               (0x00080000)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable1_mask                              (0x00040000)
#define  CABAC_P2_CABAC_P2_CNTL3_codioffset_mask                                 (0x0003FE00)
#define  CABAC_P2_CABAC_P2_CNTL3_codirange_mask                                  (0x000001FF)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable7(data)                             (0x40000000&((data)<<30))
#define  CABAC_P2_CABAC_P2_CNTL3_reset_cabacp2_bsfifo(data)                      (0x20000000&((data)<<29))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable6(data)                             (0x10000000&((data)<<28))
#define  CABAC_P2_CABAC_P2_CNTL3_decode_en_cabacp2(data)                         (0x08000000&((data)<<27))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable5(data)                             (0x04000000&((data)<<26))
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_1p_mode(data)                             (0x02000000&((data)<<25))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable4(data)                             (0x01000000&((data)<<24))
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_p3(data)                               (0x00800000&((data)<<23))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable3(data)                             (0x00400000&((data)<<22))
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_go(data)                               (0x00200000&((data)<<21))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable2(data)                             (0x00100000&((data)<<20))
#define  CABAC_P2_CABAC_P2_CNTL3_latch_enable(data)                              (0x00080000&((data)<<19))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable1(data)                             (0x00040000&((data)<<18))
#define  CABAC_P2_CABAC_P2_CNTL3_codioffset(data)                                (0x0003FE00&((data)<<9))
#define  CABAC_P2_CABAC_P2_CNTL3_codirange(data)                                 (0x000001FF&(data))
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable7(data)                         ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL3_get_reset_cabacp2_bsfifo(data)                  ((0x20000000&(data))>>29)
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable6(data)                         ((0x10000000&(data))>>28)
#define  CABAC_P2_CABAC_P2_CNTL3_get_decode_en_cabacp2(data)                     ((0x08000000&(data))>>27)
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable5(data)                         ((0x04000000&(data))>>26)
#define  CABAC_P2_CABAC_P2_CNTL3_get_cabac_1p_mode(data)                         ((0x02000000&(data))>>25)
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable4(data)                         ((0x01000000&(data))>>24)
#define  CABAC_P2_CABAC_P2_CNTL3_get_cabac_p2_p3(data)                           ((0x00800000&(data))>>23)
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable3(data)                         ((0x00400000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL3_get_cabac_p2_go(data)                           ((0x00200000&(data))>>21)
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable2(data)                         ((0x00100000&(data))>>20)
#define  CABAC_P2_CABAC_P2_CNTL3_get_latch_enable(data)                          ((0x00080000&(data))>>19)
#define  CABAC_P2_CABAC_P2_CNTL3_get_write_enable1(data)                         ((0x00040000&(data))>>18)
#define  CABAC_P2_CABAC_P2_CNTL3_get_codioffset(data)                            ((0x0003FE00&(data))>>9)
#define  CABAC_P2_CABAC_P2_CNTL3_get_codirange(data)                             (0x000001FF&(data))
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable7_src(data)                         ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL3_reset_cabacp2_bsfifo_src(data)                  ((0x20000000&(data))>>29)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable6_src(data)                         ((0x10000000&(data))>>28)
#define  CABAC_P2_CABAC_P2_CNTL3_decode_en_cabacp2_src(data)                     ((0x08000000&(data))>>27)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable5_src(data)                         ((0x04000000&(data))>>26)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_1p_mode_src(data)                         ((0x02000000&(data))>>25)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable4_src(data)                         ((0x01000000&(data))>>24)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_p3_src(data)                           ((0x00800000&(data))>>23)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable3_src(data)                         ((0x00400000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL3_cabac_p2_go_src(data)                           ((0x00200000&(data))>>21)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable2_src(data)                         ((0x00100000&(data))>>20)
#define  CABAC_P2_CABAC_P2_CNTL3_latch_enable_src(data)                          ((0x00080000&(data))>>19)
#define  CABAC_P2_CABAC_P2_CNTL3_write_enable1_src(data)                         ((0x00040000&(data))>>18)
#define  CABAC_P2_CABAC_P2_CNTL3_codioffset_src(data)                            ((0x0003FE00&(data))>>9)
#define  CABAC_P2_CABAC_P2_CNTL3_codirange_src(data)                             (0x000001FF&(data))

#define  CABAC_P2_CABAC_P2_CNTL4                                                 0x1800E3D0
#define  CABAC_P2_CABAC_P2_CNTL4_reg_addr                                        "0xB800E3D0"
#define  CABAC_P2_CABAC_P2_CNTL4_reg                                             0xB800E3D0
#define  CABAC_P2_CABAC_P2_CNTL4_inst_addr                                       "0x000D"
#define  CABAC_P2_CABAC_P2_CNTL4_inst_adr                                        "0x00F4"
#define  CABAC_P2_CABAC_P2_CNTL4_inst                                            0x00F4
#define  set_CABAC_P2_CABAC_P2_CNTL4_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL4_reg)=data)
#define  get_CABAC_P2_CABAC_P2_CNTL4_reg                                         (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL4_reg))
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable5_shift                             (30)
#define  CABAC_P2_CABAC_P2_CNTL4_arb_wait_value_shift                            (25)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable4_shift                             (24)
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_done_shift                          (23)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable3_shift                             (22)
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_shift                               (21)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable2_shift                             (20)
#define  CABAC_P2_CABAC_P2_CNTL4_Cabacp2_idle_shift                              (19)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable1_shift                             (18)
#define  CABAC_P2_CABAC_P2_CNTL4_cabacp2_header_byte_cnt_shift                   (0)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable5_mask                              (0x40000000)
#define  CABAC_P2_CABAC_P2_CNTL4_arb_wait_value_mask                             (0x3E000000)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable4_mask                              (0x01000000)
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_done_mask                           (0x00800000)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable3_mask                              (0x00400000)
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_mask                                (0x00200000)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable2_mask                              (0x00100000)
#define  CABAC_P2_CABAC_P2_CNTL4_Cabacp2_idle_mask                               (0x00080000)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable1_mask                              (0x00040000)
#define  CABAC_P2_CABAC_P2_CNTL4_cabacp2_header_byte_cnt_mask                    (0x0003FFFF)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable5(data)                             (0x40000000&((data)<<30))
#define  CABAC_P2_CABAC_P2_CNTL4_arb_wait_value(data)                            (0x3E000000&((data)<<25))
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable4(data)                             (0x01000000&((data)<<24))
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_done(data)                          (0x00800000&((data)<<23))
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable3(data)                             (0x00400000&((data)<<22))
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2(data)                               (0x00200000&((data)<<21))
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable2(data)                             (0x00100000&((data)<<20))
#define  CABAC_P2_CABAC_P2_CNTL4_Cabacp2_idle(data)                              (0x00080000&((data)<<19))
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable1(data)                             (0x00040000&((data)<<18))
#define  CABAC_P2_CABAC_P2_CNTL4_cabacp2_header_byte_cnt(data)                   (0x0003FFFF&(data))
#define  CABAC_P2_CABAC_P2_CNTL4_get_write_enable5(data)                         ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL4_get_arb_wait_value(data)                        ((0x3E000000&(data))>>25)
#define  CABAC_P2_CABAC_P2_CNTL4_get_write_enable4(data)                         ((0x01000000&(data))>>24)
#define  CABAC_P2_CABAC_P2_CNTL4_get_HaltCabacp2_done(data)                      ((0x00800000&(data))>>23)
#define  CABAC_P2_CABAC_P2_CNTL4_get_write_enable3(data)                         ((0x00400000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL4_get_HaltCabacp2(data)                           ((0x00200000&(data))>>21)
#define  CABAC_P2_CABAC_P2_CNTL4_get_write_enable2(data)                         ((0x00100000&(data))>>20)
#define  CABAC_P2_CABAC_P2_CNTL4_get_Cabacp2_idle(data)                          ((0x00080000&(data))>>19)
#define  CABAC_P2_CABAC_P2_CNTL4_get_write_enable1(data)                         ((0x00040000&(data))>>18)
#define  CABAC_P2_CABAC_P2_CNTL4_get_cabacp2_header_byte_cnt(data)               (0x0003FFFF&(data))
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable5_src(data)                         ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL4_arb_wait_value_src(data)                        ((0x3E000000&(data))>>25)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable4_src(data)                         ((0x01000000&(data))>>24)
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_done_src(data)                      ((0x00800000&(data))>>23)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable3_src(data)                         ((0x00400000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL4_HaltCabacp2_src(data)                           ((0x00200000&(data))>>21)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable2_src(data)                         ((0x00100000&(data))>>20)
#define  CABAC_P2_CABAC_P2_CNTL4_Cabacp2_idle_src(data)                          ((0x00080000&(data))>>19)
#define  CABAC_P2_CABAC_P2_CNTL4_write_enable1_src(data)                         ((0x00040000&(data))>>18)
#define  CABAC_P2_CABAC_P2_CNTL4_cabacp2_header_byte_cnt_src(data)               (0x0003FFFF&(data))

#define  CABAC_P2_CABACP2_INT_STATUS                                             0x1800E3D4
#define  CABAC_P2_CABACP2_INT_STATUS_reg_addr                                    "0xB800E3D4"
#define  CABAC_P2_CABACP2_INT_STATUS_reg                                         0xB800E3D4
#define  CABAC_P2_CABACP2_INT_STATUS_inst_addr                                   "0x000E"
#define  CABAC_P2_CABACP2_INT_STATUS_inst_adr                                    "0x00F5"
#define  CABAC_P2_CABACP2_INT_STATUS_inst                                        0x00F5
#define  set_CABAC_P2_CABACP2_INT_STATUS_reg(data)                               (*((volatile unsigned int*)CABAC_P2_CABACP2_INT_STATUS_reg)=data)
#define  get_CABAC_P2_CABACP2_INT_STATUS_reg                                     (*((volatile unsigned int*)CABAC_P2_CABACP2_INT_STATUS_reg))
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_wfifo_err_shift                    (4)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_bsfifo_err_shift                   (3)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_dec_err_shift                      (2)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_done_shift                         (1)
#define  CABAC_P2_CABACP2_INT_STATUS_write_data_shift                            (0)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_wfifo_err_mask                     (0x00000010)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_bsfifo_err_mask                    (0x00000008)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_dec_err_mask                       (0x00000004)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_done_mask                          (0x00000002)
#define  CABAC_P2_CABACP2_INT_STATUS_write_data_mask                             (0x00000001)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_wfifo_err(data)                    (0x00000010&((data)<<4))
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_bsfifo_err(data)                   (0x00000008&((data)<<3))
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_dec_err(data)                      (0x00000004&((data)<<2))
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_done(data)                         (0x00000002&((data)<<1))
#define  CABAC_P2_CABACP2_INT_STATUS_write_data(data)                            (0x00000001&(data))
#define  CABAC_P2_CABACP2_INT_STATUS_get_cabac_p2_wfifo_err(data)                ((0x00000010&(data))>>4)
#define  CABAC_P2_CABACP2_INT_STATUS_get_cabac_p2_bsfifo_err(data)               ((0x00000008&(data))>>3)
#define  CABAC_P2_CABACP2_INT_STATUS_get_cabac_p2_dec_err(data)                  ((0x00000004&(data))>>2)
#define  CABAC_P2_CABACP2_INT_STATUS_get_cabac_p2_done(data)                     ((0x00000002&(data))>>1)
#define  CABAC_P2_CABACP2_INT_STATUS_get_write_data(data)                        (0x00000001&(data))
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_wfifo_err_src(data)                ((0x00000010&(data))>>4)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_bsfifo_err_src(data)               ((0x00000008&(data))>>3)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_dec_err_src(data)                  ((0x00000004&(data))>>2)
#define  CABAC_P2_CABACP2_INT_STATUS_cabac_p2_done_src(data)                     ((0x00000002&(data))>>1)
#define  CABAC_P2_CABACP2_INT_STATUS_write_data_src(data)                        (0x00000001&(data))

#define  CABAC_P2_CABACP2_INT_EN                                                 0x1800E3D8
#define  CABAC_P2_CABACP2_INT_EN_reg_addr                                        "0xB800E3D8"
#define  CABAC_P2_CABACP2_INT_EN_reg                                             0xB800E3D8
#define  CABAC_P2_CABACP2_INT_EN_inst_addr                                       "0x000F"
#define  CABAC_P2_CABACP2_INT_EN_inst_adr                                        "0x00F6"
#define  CABAC_P2_CABACP2_INT_EN_inst                                            0x00F6
#define  set_CABAC_P2_CABACP2_INT_EN_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_CABACP2_INT_EN_reg)=data)
#define  get_CABAC_P2_CABACP2_INT_EN_reg                                         (*((volatile unsigned int*)CABAC_P2_CABACP2_INT_EN_reg))
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_wfifo_err_ie_shift                     (4)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_bsfifo_err_ie_shift                    (3)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_dec_err_ie_shift                       (2)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_done_ie_shift                          (1)
#define  CABAC_P2_CABACP2_INT_EN_write_data_shift                                (0)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_wfifo_err_ie_mask                      (0x00000010)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_bsfifo_err_ie_mask                     (0x00000008)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_dec_err_ie_mask                        (0x00000004)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_done_ie_mask                           (0x00000002)
#define  CABAC_P2_CABACP2_INT_EN_write_data_mask                                 (0x00000001)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_wfifo_err_ie(data)                     (0x00000010&((data)<<4))
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_bsfifo_err_ie(data)                    (0x00000008&((data)<<3))
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_dec_err_ie(data)                       (0x00000004&((data)<<2))
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_done_ie(data)                          (0x00000002&((data)<<1))
#define  CABAC_P2_CABACP2_INT_EN_write_data(data)                                (0x00000001&(data))
#define  CABAC_P2_CABACP2_INT_EN_get_cabac_p2_wfifo_err_ie(data)                 ((0x00000010&(data))>>4)
#define  CABAC_P2_CABACP2_INT_EN_get_cabac_p2_bsfifo_err_ie(data)                ((0x00000008&(data))>>3)
#define  CABAC_P2_CABACP2_INT_EN_get_cabac_p2_dec_err_ie(data)                   ((0x00000004&(data))>>2)
#define  CABAC_P2_CABACP2_INT_EN_get_cabac_p2_done_ie(data)                      ((0x00000002&(data))>>1)
#define  CABAC_P2_CABACP2_INT_EN_get_write_data(data)                            (0x00000001&(data))
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_wfifo_err_ie_src(data)                 ((0x00000010&(data))>>4)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_bsfifo_err_ie_src(data)                ((0x00000008&(data))>>3)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_dec_err_ie_src(data)                   ((0x00000004&(data))>>2)
#define  CABAC_P2_CABACP2_INT_EN_cabac_p2_done_ie_src(data)                      ((0x00000002&(data))>>1)
#define  CABAC_P2_CABACP2_INT_EN_write_data_src(data)                            (0x00000001&(data))

#define  CABAC_P2_CABAC_P2_CNTL5                                                 0x1800E3DC
#define  CABAC_P2_CABAC_P2_CNTL5_reg_addr                                        "0xB800E3DC"
#define  CABAC_P2_CABAC_P2_CNTL5_reg                                             0xB800E3DC
#define  CABAC_P2_CABAC_P2_CNTL5_inst_addr                                       "0x0010"
#define  CABAC_P2_CABAC_P2_CNTL5_inst_adr                                        "0x00F7"
#define  CABAC_P2_CABAC_P2_CNTL5_inst                                            0x00F7
#define  set_CABAC_P2_CABAC_P2_CNTL5_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL5_reg)=data)
#define  get_CABAC_P2_CABAC_P2_CNTL5_reg                                         (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL5_reg))
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable4_shift                             (30)
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_eos_shift                                  (29)
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_p2_err_shift                               (28)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable3_shift                             (27)
#define  CABAC_P2_CABAC_P2_CNTL5_coding_type_shift                               (22)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable2_shift                             (21)
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_pred_counter_shift                      (11)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable1_shift                             (10)
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_curmb_addr_shift                        (0)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable4_mask                              (0x40000000)
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_eos_mask                                   (0x20000000)
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_p2_err_mask                                (0x10000000)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable3_mask                              (0x08000000)
#define  CABAC_P2_CABAC_P2_CNTL5_coding_type_mask                                (0x07C00000)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable2_mask                              (0x00200000)
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_pred_counter_mask                       (0x001FF800)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable1_mask                              (0x00000400)
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_curmb_addr_mask                         (0x000003FF)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable4(data)                             (0x40000000&((data)<<30))
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_eos(data)                                  (0x20000000&((data)<<29))
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_p2_err(data)                               (0x10000000&((data)<<28))
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable3(data)                             (0x08000000&((data)<<27))
#define  CABAC_P2_CABAC_P2_CNTL5_coding_type(data)                               (0x07C00000&((data)<<22))
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable2(data)                             (0x00200000&((data)<<21))
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_pred_counter(data)                      (0x001FF800&((data)<<11))
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable1(data)                             (0x00000400&((data)<<10))
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_curmb_addr(data)                        (0x000003FF&(data))
#define  CABAC_P2_CABAC_P2_CNTL5_get_write_enable4(data)                         ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL5_get_hevc_eos(data)                              ((0x20000000&(data))>>29)
#define  CABAC_P2_CABAC_P2_CNTL5_get_hevc_p2_err(data)                           ((0x10000000&(data))>>28)
#define  CABAC_P2_CABAC_P2_CNTL5_get_write_enable3(data)                         ((0x08000000&(data))>>27)
#define  CABAC_P2_CABAC_P2_CNTL5_get_coding_type(data)                           ((0x07C00000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL5_get_write_enable2(data)                         ((0x00200000&(data))>>21)
#define  CABAC_P2_CABAC_P2_CNTL5_get_cabacp2_pred_counter(data)                  ((0x001FF800&(data))>>11)
#define  CABAC_P2_CABAC_P2_CNTL5_get_write_enable1(data)                         ((0x00000400&(data))>>10)
#define  CABAC_P2_CABAC_P2_CNTL5_get_cabacp2_curmb_addr(data)                    (0x000003FF&(data))
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable4_src(data)                         ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_eos_src(data)                              ((0x20000000&(data))>>29)
#define  CABAC_P2_CABAC_P2_CNTL5_hevc_p2_err_src(data)                           ((0x10000000&(data))>>28)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable3_src(data)                         ((0x08000000&(data))>>27)
#define  CABAC_P2_CABAC_P2_CNTL5_coding_type_src(data)                           ((0x07C00000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable2_src(data)                         ((0x00200000&(data))>>21)
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_pred_counter_src(data)                  ((0x001FF800&(data))>>11)
#define  CABAC_P2_CABAC_P2_CNTL5_write_enable1_src(data)                         ((0x00000400&(data))>>10)
#define  CABAC_P2_CABAC_P2_CNTL5_cabacp2_curmb_addr_src(data)                    (0x000003FF&(data))

#define  CABAC_P2_P2_BSCNTL                                                      0x1800E3E0
#define  CABAC_P2_P2_BSCNTL_reg_addr                                             "0xB800E3E0"
#define  CABAC_P2_P2_BSCNTL_reg                                                  0xB800E3E0
#define  CABAC_P2_P2_BSCNTL_inst_addr                                            "0x0011"
#define  CABAC_P2_P2_BSCNTL_inst_adr                                             "0x00F8"
#define  CABAC_P2_P2_BSCNTL_inst                                                 0x00F8
#define  set_CABAC_P2_P2_BSCNTL_reg(data)                                        (*((volatile unsigned int*)CABAC_P2_P2_BSCNTL_reg)=data)
#define  get_CABAC_P2_P2_BSCNTL_reg                                              (*((volatile unsigned int*)CABAC_P2_P2_BSCNTL_reg))
#define  CABAC_P2_P2_BSCNTL_write_enable3_shift                                  (6)
#define  CABAC_P2_P2_BSCNTL_p2_startcode_prevnt_en_shift                         (5)
#define  CABAC_P2_P2_BSCNTL_write_enable2_shift                                  (4)
#define  CABAC_P2_P2_BSCNTL_detect_startcode_error_shift                         (3)
#define  CABAC_P2_P2_BSCNTL_write_enable1_shift                                  (2)
#define  CABAC_P2_P2_BSCNTL_min_xfer_size_shift                                  (0)
#define  CABAC_P2_P2_BSCNTL_write_enable3_mask                                   (0x00000040)
#define  CABAC_P2_P2_BSCNTL_p2_startcode_prevnt_en_mask                          (0x00000020)
#define  CABAC_P2_P2_BSCNTL_write_enable2_mask                                   (0x00000010)
#define  CABAC_P2_P2_BSCNTL_detect_startcode_error_mask                          (0x00000008)
#define  CABAC_P2_P2_BSCNTL_write_enable1_mask                                   (0x00000004)
#define  CABAC_P2_P2_BSCNTL_min_xfer_size_mask                                   (0x00000003)
#define  CABAC_P2_P2_BSCNTL_write_enable3(data)                                  (0x00000040&((data)<<6))
#define  CABAC_P2_P2_BSCNTL_p2_startcode_prevnt_en(data)                         (0x00000020&((data)<<5))
#define  CABAC_P2_P2_BSCNTL_write_enable2(data)                                  (0x00000010&((data)<<4))
#define  CABAC_P2_P2_BSCNTL_detect_startcode_error(data)                         (0x00000008&((data)<<3))
#define  CABAC_P2_P2_BSCNTL_write_enable1(data)                                  (0x00000004&((data)<<2))
#define  CABAC_P2_P2_BSCNTL_min_xfer_size(data)                                  (0x00000003&(data))
#define  CABAC_P2_P2_BSCNTL_get_write_enable3(data)                              ((0x00000040&(data))>>6)
#define  CABAC_P2_P2_BSCNTL_get_p2_startcode_prevnt_en(data)                     ((0x00000020&(data))>>5)
#define  CABAC_P2_P2_BSCNTL_get_write_enable2(data)                              ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_BSCNTL_get_detect_startcode_error(data)                     ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_BSCNTL_get_write_enable1(data)                              ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_BSCNTL_get_min_xfer_size(data)                              (0x00000003&(data))
#define  CABAC_P2_P2_BSCNTL_write_enable3_src(data)                              ((0x00000040&(data))>>6)
#define  CABAC_P2_P2_BSCNTL_p2_startcode_prevnt_en_src(data)                     ((0x00000020&(data))>>5)
#define  CABAC_P2_P2_BSCNTL_write_enable2_src(data)                              ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_BSCNTL_detect_startcode_error_src(data)                     ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_BSCNTL_write_enable1_src(data)                              ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_BSCNTL_min_xfer_size_src(data)                              (0x00000003&(data))

#define  CABAC_P2_P2_BS_MIN_THR                                                  0x1800E3E4
#define  CABAC_P2_P2_BS_MIN_THR_reg_addr                                         "0xB800E3E4"
#define  CABAC_P2_P2_BS_MIN_THR_reg                                              0xB800E3E4
#define  CABAC_P2_P2_BS_MIN_THR_inst_addr                                        "0x0012"
#define  CABAC_P2_P2_BS_MIN_THR_inst_adr                                         "0x00F9"
#define  CABAC_P2_P2_BS_MIN_THR_inst                                             0x00F9
#define  set_CABAC_P2_P2_BS_MIN_THR_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_BS_MIN_THR_reg)=data)
#define  get_CABAC_P2_P2_BS_MIN_THR_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_BS_MIN_THR_reg))
#define  CABAC_P2_P2_BS_MIN_THR_min_thre_shift                                   (0)
#define  CABAC_P2_P2_BS_MIN_THR_min_thre_mask                                    (0x0000007F)
#define  CABAC_P2_P2_BS_MIN_THR_min_thre(data)                                   (0x0000007F&(data))
#define  CABAC_P2_P2_BS_MIN_THR_get_min_thre(data)                               (0x0000007F&(data))
#define  CABAC_P2_P2_BS_MIN_THR_min_thre_src(data)                               (0x0000007F&(data))

#define  CABAC_P2_P2_BSTIMER                                                     0x1800E3E8
#define  CABAC_P2_P2_BSTIMER_reg_addr                                            "0xB800E3E8"
#define  CABAC_P2_P2_BSTIMER_reg                                                 0xB800E3E8
#define  CABAC_P2_P2_BSTIMER_inst_addr                                           "0x0013"
#define  CABAC_P2_P2_BSTIMER_inst_adr                                            "0x00FA"
#define  CABAC_P2_P2_BSTIMER_inst                                                0x00FA
#define  set_CABAC_P2_P2_BSTIMER_reg(data)                                       (*((volatile unsigned int*)CABAC_P2_P2_BSTIMER_reg)=data)
#define  get_CABAC_P2_P2_BSTIMER_reg                                             (*((volatile unsigned int*)CABAC_P2_P2_BSTIMER_reg))
#define  CABAC_P2_P2_BSTIMER_timer_value_shift                                   (0)
#define  CABAC_P2_P2_BSTIMER_timer_value_mask                                    (0x00FFFFFF)
#define  CABAC_P2_P2_BSTIMER_timer_value(data)                                   (0x00FFFFFF&(data))
#define  CABAC_P2_P2_BSTIMER_get_timer_value(data)                               (0x00FFFFFF&(data))
#define  CABAC_P2_P2_BSTIMER_timer_value_src(data)                               (0x00FFFFFF&(data))

#define  CABAC_P2_P2_RFIFO_BASE                                                  0x1800E364
#define  CABAC_P2_P2_RFIFO_BASE_reg_addr                                         "0xB800E364"
#define  CABAC_P2_P2_RFIFO_BASE_reg                                              0xB800E364
#define  CABAC_P2_P2_RFIFO_BASE_inst_addr                                        "0x0014"
#define  CABAC_P2_P2_RFIFO_BASE_inst_adr                                         "0x00D9"
#define  CABAC_P2_P2_RFIFO_BASE_inst                                             0x00D9
#define  set_CABAC_P2_P2_RFIFO_BASE_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_BASE_reg)=data)
#define  get_CABAC_P2_P2_RFIFO_BASE_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_BASE_reg))
#define  CABAC_P2_P2_RFIFO_BASE_base_addr_shift                                  (0)
#define  CABAC_P2_P2_RFIFO_BASE_base_addr_mask                                   (0xFFFFFFFF)
#define  CABAC_P2_P2_RFIFO_BASE_base_addr(data)                                  (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_BASE_get_base_addr(data)                              (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_BASE_base_addr_src(data)                              (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_RFIFO_LIMIT                                                 0x1800E368
#define  CABAC_P2_P2_RFIFO_LIMIT_reg_addr                                        "0xB800E368"
#define  CABAC_P2_P2_RFIFO_LIMIT_reg                                             0xB800E368
#define  CABAC_P2_P2_RFIFO_LIMIT_inst_addr                                       "0x0015"
#define  CABAC_P2_P2_RFIFO_LIMIT_inst_adr                                        "0x00DA"
#define  CABAC_P2_P2_RFIFO_LIMIT_inst                                            0x00DA
#define  set_CABAC_P2_P2_RFIFO_LIMIT_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_LIMIT_reg)=data)
#define  get_CABAC_P2_P2_RFIFO_LIMIT_reg                                         (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_LIMIT_reg))
#define  CABAC_P2_P2_RFIFO_LIMIT_limit_addr_shift                                (0)
#define  CABAC_P2_P2_RFIFO_LIMIT_limit_addr_mask                                 (0xFFFFFFFF)
#define  CABAC_P2_P2_RFIFO_LIMIT_limit_addr(data)                                (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_LIMIT_get_limit_addr(data)                            (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_LIMIT_limit_addr_src(data)                            (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_RFIFO_WPTR                                                  0x1800E36C
#define  CABAC_P2_P2_RFIFO_WPTR_reg_addr                                         "0xB800E36C"
#define  CABAC_P2_P2_RFIFO_WPTR_reg                                              0xB800E36C
#define  CABAC_P2_P2_RFIFO_WPTR_inst_addr                                        "0x0016"
#define  CABAC_P2_P2_RFIFO_WPTR_inst_adr                                         "0x00DB"
#define  CABAC_P2_P2_RFIFO_WPTR_inst                                             0x00DB
#define  set_CABAC_P2_P2_RFIFO_WPTR_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_WPTR_reg)=data)
#define  get_CABAC_P2_P2_RFIFO_WPTR_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_WPTR_reg))
#define  CABAC_P2_P2_RFIFO_WPTR_wr_ptr_shift                                     (0)
#define  CABAC_P2_P2_RFIFO_WPTR_wr_ptr_mask                                      (0xFFFFFFFF)
#define  CABAC_P2_P2_RFIFO_WPTR_wr_ptr(data)                                     (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_WPTR_get_wr_ptr(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_WPTR_wr_ptr_src(data)                                 (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_RFIFO_RPTR                                                  0x1800E370
#define  CABAC_P2_P2_RFIFO_RPTR_reg_addr                                         "0xB800E370"
#define  CABAC_P2_P2_RFIFO_RPTR_reg                                              0xB800E370
#define  CABAC_P2_P2_RFIFO_RPTR_inst_addr                                        "0x0017"
#define  CABAC_P2_P2_RFIFO_RPTR_inst_adr                                         "0x00DC"
#define  CABAC_P2_P2_RFIFO_RPTR_inst                                             0x00DC
#define  set_CABAC_P2_P2_RFIFO_RPTR_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_RPTR_reg)=data)
#define  get_CABAC_P2_P2_RFIFO_RPTR_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_RPTR_reg))
#define  CABAC_P2_P2_RFIFO_RPTR_rd_ptr_shift                                     (0)
#define  CABAC_P2_P2_RFIFO_RPTR_rd_ptr_mask                                      (0xFFFFFFFF)
#define  CABAC_P2_P2_RFIFO_RPTR_rd_ptr(data)                                     (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_RPTR_get_rd_ptr(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_RPTR_rd_ptr_src(data)                                 (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_WFIFO_BASE                                                  0x1800E374
#define  CABAC_P2_P2_WFIFO_BASE_reg_addr                                         "0xB800E374"
#define  CABAC_P2_P2_WFIFO_BASE_reg                                              0xB800E374
#define  CABAC_P2_P2_WFIFO_BASE_inst_addr                                        "0x0018"
#define  CABAC_P2_P2_WFIFO_BASE_inst_adr                                         "0x00DD"
#define  CABAC_P2_P2_WFIFO_BASE_inst                                             0x00DD
#define  set_CABAC_P2_P2_WFIFO_BASE_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_BASE_reg)=data)
#define  get_CABAC_P2_P2_WFIFO_BASE_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_BASE_reg))
#define  CABAC_P2_P2_WFIFO_BASE_base_addr_shift                                  (0)
#define  CABAC_P2_P2_WFIFO_BASE_base_addr_mask                                   (0xFFFFFFFF)
#define  CABAC_P2_P2_WFIFO_BASE_base_addr(data)                                  (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_BASE_get_base_addr(data)                              (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_BASE_base_addr_src(data)                              (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_WFIFO_LIMIT                                                 0x1800E378
#define  CABAC_P2_P2_WFIFO_LIMIT_reg_addr                                        "0xB800E378"
#define  CABAC_P2_P2_WFIFO_LIMIT_reg                                             0xB800E378
#define  CABAC_P2_P2_WFIFO_LIMIT_inst_addr                                       "0x0019"
#define  CABAC_P2_P2_WFIFO_LIMIT_inst_adr                                        "0x00DE"
#define  CABAC_P2_P2_WFIFO_LIMIT_inst                                            0x00DE
#define  set_CABAC_P2_P2_WFIFO_LIMIT_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_LIMIT_reg)=data)
#define  get_CABAC_P2_P2_WFIFO_LIMIT_reg                                         (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_LIMIT_reg))
#define  CABAC_P2_P2_WFIFO_LIMIT_limit_addr_shift                                (0)
#define  CABAC_P2_P2_WFIFO_LIMIT_limit_addr_mask                                 (0xFFFFFFFF)
#define  CABAC_P2_P2_WFIFO_LIMIT_limit_addr(data)                                (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_LIMIT_get_limit_addr(data)                            (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_LIMIT_limit_addr_src(data)                            (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_WFIFO_WPTR                                                  0x1800E37C
#define  CABAC_P2_P2_WFIFO_WPTR_reg_addr                                         "0xB800E37C"
#define  CABAC_P2_P2_WFIFO_WPTR_reg                                              0xB800E37C
#define  CABAC_P2_P2_WFIFO_WPTR_inst_addr                                        "0x001A"
#define  CABAC_P2_P2_WFIFO_WPTR_inst_adr                                         "0x00DF"
#define  CABAC_P2_P2_WFIFO_WPTR_inst                                             0x00DF
#define  set_CABAC_P2_P2_WFIFO_WPTR_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_WPTR_reg)=data)
#define  get_CABAC_P2_P2_WFIFO_WPTR_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_WPTR_reg))
#define  CABAC_P2_P2_WFIFO_WPTR_wr_ptr_shift                                     (0)
#define  CABAC_P2_P2_WFIFO_WPTR_wr_ptr_mask                                      (0xFFFFFFFF)
#define  CABAC_P2_P2_WFIFO_WPTR_wr_ptr(data)                                     (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_WPTR_get_wr_ptr(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_WPTR_wr_ptr_src(data)                                 (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_WFIFO_RPTR                                                  0x1800E380
#define  CABAC_P2_P2_WFIFO_RPTR_reg_addr                                         "0xB800E380"
#define  CABAC_P2_P2_WFIFO_RPTR_reg                                              0xB800E380
#define  CABAC_P2_P2_WFIFO_RPTR_inst_addr                                        "0x001B"
#define  CABAC_P2_P2_WFIFO_RPTR_inst_adr                                         "0x00E0"
#define  CABAC_P2_P2_WFIFO_RPTR_inst                                             0x00E0
#define  set_CABAC_P2_P2_WFIFO_RPTR_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_RPTR_reg)=data)
#define  get_CABAC_P2_P2_WFIFO_RPTR_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_WFIFO_RPTR_reg))
#define  CABAC_P2_P2_WFIFO_RPTR_rd_ptr_shift                                     (0)
#define  CABAC_P2_P2_WFIFO_RPTR_rd_ptr_mask                                      (0xFFFFFFFF)
#define  CABAC_P2_P2_WFIFO_RPTR_rd_ptr(data)                                     (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_RPTR_get_rd_ptr(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_WFIFO_RPTR_rd_ptr_src(data)                                 (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_RFIFO_DECBSPTR                                              0x1800E384
#define  CABAC_P2_P2_RFIFO_DECBSPTR_reg_addr                                     "0xB800E384"
#define  CABAC_P2_P2_RFIFO_DECBSPTR_reg                                          0xB800E384
#define  CABAC_P2_P2_RFIFO_DECBSPTR_inst_addr                                    "0x001C"
#define  CABAC_P2_P2_RFIFO_DECBSPTR_inst_adr                                     "0x00E1"
#define  CABAC_P2_P2_RFIFO_DECBSPTR_inst                                         0x00E1
#define  set_CABAC_P2_P2_RFIFO_DECBSPTR_reg(data)                                (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_DECBSPTR_reg)=data)
#define  get_CABAC_P2_P2_RFIFO_DECBSPTR_reg                                      (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_DECBSPTR_reg))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_dec_bit_ptr_shift                            (0)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_dec_bit_ptr_mask                             (0xFFFFFFFF)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_dec_bit_ptr(data)                            (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_get_dec_bit_ptr(data)                        (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_dec_bit_ptr_src(data)                        (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB                                          0x1800E24C
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_reg_addr                                 "0xB800E24C"
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_reg                                      0xB800E24C
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_inst_addr                                "0x001D"
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_inst_adr                                 "0x0093"
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_inst                                     0x0093
#define  set_CABAC_P2_P2_RFIFO_DECBSPTR_MSB_reg(data)                            (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_DECBSPTR_MSB_reg)=data)
#define  get_CABAC_P2_P2_RFIFO_DECBSPTR_MSB_reg                                  (*((volatile unsigned int*)CABAC_P2_P2_RFIFO_DECBSPTR_MSB_reg))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_pre_bin_loc_reg_msb_shift                (6)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_bin_loc_reg_msb_shift                    (3)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_dec_bit_ptr_msb_shift                    (0)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_pre_bin_loc_reg_msb_mask                 (0x000001C0)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_bin_loc_reg_msb_mask                     (0x00000038)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_dec_bit_ptr_msb_mask                     (0x00000007)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_pre_bin_loc_reg_msb(data)                (0x000001C0&((data)<<6))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_bin_loc_reg_msb(data)                    (0x00000038&((data)<<3))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_dec_bit_ptr_msb(data)                    (0x00000007&(data))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_get_pre_bin_loc_reg_msb(data)            ((0x000001C0&(data))>>6)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_get_bin_loc_reg_msb(data)                ((0x00000038&(data))>>3)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_get_dec_bit_ptr_msb(data)                (0x00000007&(data))
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_pre_bin_loc_reg_msb_src(data)            ((0x000001C0&(data))>>6)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_bin_loc_reg_msb_src(data)                ((0x00000038&(data))>>3)
#define  CABAC_P2_P2_RFIFO_DECBSPTR_MSB_dec_bit_ptr_msb_src(data)                (0x00000007&(data))

#define  CABAC_P2_P2_LDSTADDR                                                    0x1800E25C
#define  CABAC_P2_P2_LDSTADDR_reg_addr                                           "0xB800E25C"
#define  CABAC_P2_P2_LDSTADDR_reg                                                0xB800E25C
#define  CABAC_P2_P2_LDSTADDR_inst_addr                                          "0x001E"
#define  CABAC_P2_P2_LDSTADDR_inst_adr                                           "0x0097"
#define  CABAC_P2_P2_LDSTADDR_inst                                               0x0097
#define  set_CABAC_P2_P2_LDSTADDR_reg(data)                                      (*((volatile unsigned int*)CABAC_P2_P2_LDSTADDR_reg)=data)
#define  get_CABAC_P2_P2_LDSTADDR_reg                                            (*((volatile unsigned int*)CABAC_P2_P2_LDSTADDR_reg))
#define  CABAC_P2_P2_LDSTADDR_ldst_addr_shift                                    (0)
#define  CABAC_P2_P2_LDSTADDR_ldst_addr_mask                                     (0xFFFFFFFF)
#define  CABAC_P2_P2_LDSTADDR_ldst_addr(data)                                    (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_LDSTADDR_get_ldst_addr(data)                                (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_LDSTADDR_ldst_addr_src(data)                                (0xFFFFFFFF&(data))

#define  CABAC_P2_CABAC_P2_CNTL                                                  0x1800E388
#define  CABAC_P2_CABAC_P2_CNTL_reg_addr                                         "0xB800E388"
#define  CABAC_P2_CABAC_P2_CNTL_reg                                              0xB800E388
#define  CABAC_P2_CABAC_P2_CNTL_inst_addr                                        "0x001F"
#define  CABAC_P2_CABAC_P2_CNTL_inst_adr                                         "0x00E2"
#define  CABAC_P2_CABAC_P2_CNTL_inst                                             0x00E2
#define  set_CABAC_P2_CABAC_P2_CNTL_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL_reg)=data)
#define  get_CABAC_P2_CABAC_P2_CNTL_reg                                          (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL_reg))
#define  CABAC_P2_CABAC_P2_CNTL_entropy_coding_mode_shift                        (28)
#define  CABAC_P2_CABAC_P2_CNTL_pic_init_qp_shift                                (22)
#define  CABAC_P2_CABAC_P2_CNTL_chroma_qp_offset_shift                           (17)
#define  CABAC_P2_CABAC_P2_CNTL_second_chroma_qp_offset_shift                    (12)
#define  CABAC_P2_CABAC_P2_CNTL_direct_8x8_inferflg_shift                        (11)
#define  CABAC_P2_CABAC_P2_CNTL_transform_8x8_mode_flg_shift                     (10)
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l0_active_minus1_shift               (5)
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l1_active_minus1_shift               (0)
#define  CABAC_P2_CABAC_P2_CNTL_entropy_coding_mode_mask                         (0x10000000)
#define  CABAC_P2_CABAC_P2_CNTL_pic_init_qp_mask                                 (0x0FC00000)
#define  CABAC_P2_CABAC_P2_CNTL_chroma_qp_offset_mask                            (0x003E0000)
#define  CABAC_P2_CABAC_P2_CNTL_second_chroma_qp_offset_mask                     (0x0001F000)
#define  CABAC_P2_CABAC_P2_CNTL_direct_8x8_inferflg_mask                         (0x00000800)
#define  CABAC_P2_CABAC_P2_CNTL_transform_8x8_mode_flg_mask                      (0x00000400)
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l0_active_minus1_mask                (0x000003E0)
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l1_active_minus1_mask                (0x0000001F)
#define  CABAC_P2_CABAC_P2_CNTL_entropy_coding_mode(data)                        (0x10000000&((data)<<28))
#define  CABAC_P2_CABAC_P2_CNTL_pic_init_qp(data)                                (0x0FC00000&((data)<<22))
#define  CABAC_P2_CABAC_P2_CNTL_chroma_qp_offset(data)                           (0x003E0000&((data)<<17))
#define  CABAC_P2_CABAC_P2_CNTL_second_chroma_qp_offset(data)                    (0x0001F000&((data)<<12))
#define  CABAC_P2_CABAC_P2_CNTL_direct_8x8_inferflg(data)                        (0x00000800&((data)<<11))
#define  CABAC_P2_CABAC_P2_CNTL_transform_8x8_mode_flg(data)                     (0x00000400&((data)<<10))
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l0_active_minus1(data)               (0x000003E0&((data)<<5))
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l1_active_minus1(data)               (0x0000001F&(data))
#define  CABAC_P2_CABAC_P2_CNTL_get_entropy_coding_mode(data)                    ((0x10000000&(data))>>28)
#define  CABAC_P2_CABAC_P2_CNTL_get_pic_init_qp(data)                            ((0x0FC00000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL_get_chroma_qp_offset(data)                       ((0x003E0000&(data))>>17)
#define  CABAC_P2_CABAC_P2_CNTL_get_second_chroma_qp_offset(data)                ((0x0001F000&(data))>>12)
#define  CABAC_P2_CABAC_P2_CNTL_get_direct_8x8_inferflg(data)                    ((0x00000800&(data))>>11)
#define  CABAC_P2_CABAC_P2_CNTL_get_transform_8x8_mode_flg(data)                 ((0x00000400&(data))>>10)
#define  CABAC_P2_CABAC_P2_CNTL_get_num_ref_idx_l0_active_minus1(data)           ((0x000003E0&(data))>>5)
#define  CABAC_P2_CABAC_P2_CNTL_get_num_ref_idx_l1_active_minus1(data)           (0x0000001F&(data))
#define  CABAC_P2_CABAC_P2_CNTL_entropy_coding_mode_src(data)                    ((0x10000000&(data))>>28)
#define  CABAC_P2_CABAC_P2_CNTL_pic_init_qp_src(data)                            ((0x0FC00000&(data))>>22)
#define  CABAC_P2_CABAC_P2_CNTL_chroma_qp_offset_src(data)                       ((0x003E0000&(data))>>17)
#define  CABAC_P2_CABAC_P2_CNTL_second_chroma_qp_offset_src(data)                ((0x0001F000&(data))>>12)
#define  CABAC_P2_CABAC_P2_CNTL_direct_8x8_inferflg_src(data)                    ((0x00000800&(data))>>11)
#define  CABAC_P2_CABAC_P2_CNTL_transform_8x8_mode_flg_src(data)                 ((0x00000400&(data))>>10)
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l0_active_minus1_src(data)           ((0x000003E0&(data))>>5)
#define  CABAC_P2_CABAC_P2_CNTL_num_ref_idx_l1_active_minus1_src(data)           (0x0000001F&(data))

#define  CABAC_P2_CABAC_P2_CNTL2                                                 0x1800E38C
#define  CABAC_P2_CABAC_P2_CNTL2_reg_addr                                        "0xB800E38C"
#define  CABAC_P2_CABAC_P2_CNTL2_reg                                             0xB800E38C
#define  CABAC_P2_CABAC_P2_CNTL2_inst_addr                                       "0x0020"
#define  CABAC_P2_CABAC_P2_CNTL2_inst_adr                                        "0x00E3"
#define  CABAC_P2_CABAC_P2_CNTL2_inst                                            0x00E3
#define  set_CABAC_P2_CABAC_P2_CNTL2_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL2_reg)=data)
#define  get_CABAC_P2_CABAC_P2_CNTL2_reg                                         (*((volatile unsigned int*)CABAC_P2_CABAC_P2_CNTL2_reg))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable7_shift                             (31)
#define  CABAC_P2_CABAC_P2_CNTL2_mb_adaptive_frame_field_flag_shift              (30)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable6_shift                             (29)
#define  CABAC_P2_CABAC_P2_CNTL2_picmb_w_shift                                   (19)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable5_shift                             (18)
#define  CABAC_P2_CABAC_P2_CNTL2_monochrome_shift                                (17)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable4_shift                             (16)
#define  CABAC_P2_CABAC_P2_CNTL2_field_pic_flag_shift                            (15)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable3_shift                             (14)
#define  CABAC_P2_CABAC_P2_CNTL2_pic_type_shift                                  (11)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable2_shift                             (10)
#define  CABAC_P2_CABAC_P2_CNTL2_slice_qp_delta_shift                            (3)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable1_shift                             (2)
#define  CABAC_P2_CABAC_P2_CNTL2_cabac_init_idc_shift                            (0)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable7_mask                              (0x80000000)
#define  CABAC_P2_CABAC_P2_CNTL2_mb_adaptive_frame_field_flag_mask               (0x40000000)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable6_mask                              (0x20000000)
#define  CABAC_P2_CABAC_P2_CNTL2_picmb_w_mask                                    (0x1FF80000)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable5_mask                              (0x00040000)
#define  CABAC_P2_CABAC_P2_CNTL2_monochrome_mask                                 (0x00020000)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable4_mask                              (0x00010000)
#define  CABAC_P2_CABAC_P2_CNTL2_field_pic_flag_mask                             (0x00008000)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable3_mask                              (0x00004000)
#define  CABAC_P2_CABAC_P2_CNTL2_pic_type_mask                                   (0x00003800)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable2_mask                              (0x00000400)
#define  CABAC_P2_CABAC_P2_CNTL2_slice_qp_delta_mask                             (0x000003F8)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable1_mask                              (0x00000004)
#define  CABAC_P2_CABAC_P2_CNTL2_cabac_init_idc_mask                             (0x00000003)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable7(data)                             (0x80000000&((data)<<31))
#define  CABAC_P2_CABAC_P2_CNTL2_mb_adaptive_frame_field_flag(data)              (0x40000000&((data)<<30))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable6(data)                             (0x20000000&((data)<<29))
#define  CABAC_P2_CABAC_P2_CNTL2_picmb_w(data)                                   (0x1FF80000&((data)<<19))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable5(data)                             (0x00040000&((data)<<18))
#define  CABAC_P2_CABAC_P2_CNTL2_monochrome(data)                                (0x00020000&((data)<<17))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable4(data)                             (0x00010000&((data)<<16))
#define  CABAC_P2_CABAC_P2_CNTL2_field_pic_flag(data)                            (0x00008000&((data)<<15))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable3(data)                             (0x00004000&((data)<<14))
#define  CABAC_P2_CABAC_P2_CNTL2_pic_type(data)                                  (0x00003800&((data)<<11))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable2(data)                             (0x00000400&((data)<<10))
#define  CABAC_P2_CABAC_P2_CNTL2_slice_qp_delta(data)                            (0x000003F8&((data)<<3))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable1(data)                             (0x00000004&((data)<<2))
#define  CABAC_P2_CABAC_P2_CNTL2_cabac_init_idc(data)                            (0x00000003&(data))
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable7(data)                         ((0x80000000&(data))>>31)
#define  CABAC_P2_CABAC_P2_CNTL2_get_mb_adaptive_frame_field_flag(data)          ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable6(data)                         ((0x20000000&(data))>>29)
#define  CABAC_P2_CABAC_P2_CNTL2_get_picmb_w(data)                               ((0x1FF80000&(data))>>19)
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable5(data)                         ((0x00040000&(data))>>18)
#define  CABAC_P2_CABAC_P2_CNTL2_get_monochrome(data)                            ((0x00020000&(data))>>17)
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable4(data)                         ((0x00010000&(data))>>16)
#define  CABAC_P2_CABAC_P2_CNTL2_get_field_pic_flag(data)                        ((0x00008000&(data))>>15)
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable3(data)                         ((0x00004000&(data))>>14)
#define  CABAC_P2_CABAC_P2_CNTL2_get_pic_type(data)                              ((0x00003800&(data))>>11)
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable2(data)                         ((0x00000400&(data))>>10)
#define  CABAC_P2_CABAC_P2_CNTL2_get_slice_qp_delta(data)                        ((0x000003F8&(data))>>3)
#define  CABAC_P2_CABAC_P2_CNTL2_get_write_enable1(data)                         ((0x00000004&(data))>>2)
#define  CABAC_P2_CABAC_P2_CNTL2_get_cabac_init_idc(data)                        (0x00000003&(data))
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable7_src(data)                         ((0x80000000&(data))>>31)
#define  CABAC_P2_CABAC_P2_CNTL2_mb_adaptive_frame_field_flag_src(data)          ((0x40000000&(data))>>30)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable6_src(data)                         ((0x20000000&(data))>>29)
#define  CABAC_P2_CABAC_P2_CNTL2_picmb_w_src(data)                               ((0x1FF80000&(data))>>19)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable5_src(data)                         ((0x00040000&(data))>>18)
#define  CABAC_P2_CABAC_P2_CNTL2_monochrome_src(data)                            ((0x00020000&(data))>>17)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable4_src(data)                         ((0x00010000&(data))>>16)
#define  CABAC_P2_CABAC_P2_CNTL2_field_pic_flag_src(data)                        ((0x00008000&(data))>>15)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable3_src(data)                         ((0x00004000&(data))>>14)
#define  CABAC_P2_CABAC_P2_CNTL2_pic_type_src(data)                              ((0x00003800&(data))>>11)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable2_src(data)                         ((0x00000400&(data))>>10)
#define  CABAC_P2_CABAC_P2_CNTL2_slice_qp_delta_src(data)                        ((0x000003F8&(data))>>3)
#define  CABAC_P2_CABAC_P2_CNTL2_write_enable1_src(data)                         ((0x00000004&(data))>>2)
#define  CABAC_P2_CABAC_P2_CNTL2_cabac_init_idc_src(data)                        (0x00000003&(data))

#define  CABAC_P2_P2_HEVCSEQCNTL                                                 0x1800E254
#define  CABAC_P2_P2_HEVCSEQCNTL_reg_addr                                        "0xB800E254"
#define  CABAC_P2_P2_HEVCSEQCNTL_reg                                             0xB800E254
#define  CABAC_P2_P2_HEVCSEQCNTL_inst_addr                                       "0x0021"
#define  CABAC_P2_P2_HEVCSEQCNTL_inst_adr                                        "0x0095"
#define  CABAC_P2_P2_HEVCSEQCNTL_inst                                            0x0095
#define  set_CABAC_P2_P2_HEVCSEQCNTL_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_P2_HEVCSEQCNTL_reg)=data)
#define  get_CABAC_P2_P2_HEVCSEQCNTL_reg                                         (*((volatile unsigned int*)CABAC_P2_P2_HEVCSEQCNTL_reg))
#define  CABAC_P2_P2_HEVCSEQCNTL_chroma_bits_shift                               (28)
#define  CABAC_P2_P2_HEVCSEQCNTL_luma_bits_shift                                 (26)
#define  CABAC_P2_P2_HEVCSEQCNTL_mincbsize_shift                                 (21)
#define  CABAC_P2_P2_HEVCSEQCNTL_ctbsize_shift                                   (19)
#define  CABAC_P2_P2_HEVCSEQCNTL_min_trafo_size_shift                            (17)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trafo_size_shift                            (15)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_inter_shift                (12)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_intra_shift                (9)
#define  CABAC_P2_P2_HEVCSEQCNTL_amp_enabled_flag_shift                          (8)
#define  CABAC_P2_P2_HEVCSEQCNTL_pcm_enabled_flag_shift                          (6)
#define  CABAC_P2_P2_HEVCSEQCNTL_min_ipcm_cbsize_shift                           (4)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_ipcm_cbsize_shift                           (2)
#define  CABAC_P2_P2_HEVCSEQCNTL_chroma_bits_mask                                (0x30000000)
#define  CABAC_P2_P2_HEVCSEQCNTL_luma_bits_mask                                  (0x0C000000)
#define  CABAC_P2_P2_HEVCSEQCNTL_mincbsize_mask                                  (0x00600000)
#define  CABAC_P2_P2_HEVCSEQCNTL_ctbsize_mask                                    (0x00180000)
#define  CABAC_P2_P2_HEVCSEQCNTL_min_trafo_size_mask                             (0x00060000)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trafo_size_mask                             (0x00018000)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_inter_mask                 (0x00007000)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_intra_mask                 (0x00000E00)
#define  CABAC_P2_P2_HEVCSEQCNTL_amp_enabled_flag_mask                           (0x00000100)
#define  CABAC_P2_P2_HEVCSEQCNTL_pcm_enabled_flag_mask                           (0x00000040)
#define  CABAC_P2_P2_HEVCSEQCNTL_min_ipcm_cbsize_mask                            (0x00000030)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_ipcm_cbsize_mask                            (0x0000000C)
#define  CABAC_P2_P2_HEVCSEQCNTL_chroma_bits(data)                               (0x30000000&((data)<<28))
#define  CABAC_P2_P2_HEVCSEQCNTL_luma_bits(data)                                 (0x0C000000&((data)<<26))
#define  CABAC_P2_P2_HEVCSEQCNTL_mincbsize(data)                                 (0x00600000&((data)<<21))
#define  CABAC_P2_P2_HEVCSEQCNTL_ctbsize(data)                                   (0x00180000&((data)<<19))
#define  CABAC_P2_P2_HEVCSEQCNTL_min_trafo_size(data)                            (0x00060000&((data)<<17))
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trafo_size(data)                            (0x00018000&((data)<<15))
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_inter(data)                (0x00007000&((data)<<12))
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_intra(data)                (0x00000E00&((data)<<9))
#define  CABAC_P2_P2_HEVCSEQCNTL_amp_enabled_flag(data)                          (0x00000100&((data)<<8))
#define  CABAC_P2_P2_HEVCSEQCNTL_pcm_enabled_flag(data)                          (0x00000040&((data)<<6))
#define  CABAC_P2_P2_HEVCSEQCNTL_min_ipcm_cbsize(data)                           (0x00000030&((data)<<4))
#define  CABAC_P2_P2_HEVCSEQCNTL_max_ipcm_cbsize(data)                           (0x0000000C&((data)<<2))
#define  CABAC_P2_P2_HEVCSEQCNTL_get_chroma_bits(data)                           ((0x30000000&(data))>>28)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_luma_bits(data)                             ((0x0C000000&(data))>>26)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_mincbsize(data)                             ((0x00600000&(data))>>21)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_ctbsize(data)                               ((0x00180000&(data))>>19)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_min_trafo_size(data)                        ((0x00060000&(data))>>17)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_max_trafo_size(data)                        ((0x00018000&(data))>>15)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_max_trans_hier_depth_inter(data)            ((0x00007000&(data))>>12)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_max_trans_hier_depth_intra(data)            ((0x00000E00&(data))>>9)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_amp_enabled_flag(data)                      ((0x00000100&(data))>>8)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_pcm_enabled_flag(data)                      ((0x00000040&(data))>>6)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_min_ipcm_cbsize(data)                       ((0x00000030&(data))>>4)
#define  CABAC_P2_P2_HEVCSEQCNTL_get_max_ipcm_cbsize(data)                       ((0x0000000C&(data))>>2)
#define  CABAC_P2_P2_HEVCSEQCNTL_chroma_bits_src(data)                           ((0x30000000&(data))>>28)
#define  CABAC_P2_P2_HEVCSEQCNTL_luma_bits_src(data)                             ((0x0C000000&(data))>>26)
#define  CABAC_P2_P2_HEVCSEQCNTL_mincbsize_src(data)                             ((0x00600000&(data))>>21)
#define  CABAC_P2_P2_HEVCSEQCNTL_ctbsize_src(data)                               ((0x00180000&(data))>>19)
#define  CABAC_P2_P2_HEVCSEQCNTL_min_trafo_size_src(data)                        ((0x00060000&(data))>>17)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trafo_size_src(data)                        ((0x00018000&(data))>>15)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_inter_src(data)            ((0x00007000&(data))>>12)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_trans_hier_depth_intra_src(data)            ((0x00000E00&(data))>>9)
#define  CABAC_P2_P2_HEVCSEQCNTL_amp_enabled_flag_src(data)                      ((0x00000100&(data))>>8)
#define  CABAC_P2_P2_HEVCSEQCNTL_pcm_enabled_flag_src(data)                      ((0x00000040&(data))>>6)
#define  CABAC_P2_P2_HEVCSEQCNTL_min_ipcm_cbsize_src(data)                       ((0x00000030&(data))>>4)
#define  CABAC_P2_P2_HEVCSEQCNTL_max_ipcm_cbsize_src(data)                       ((0x0000000C&(data))>>2)

#define  CABAC_P2_P2_HEVCPICSIZE                                                 0x1800E258
#define  CABAC_P2_P2_HEVCPICSIZE_reg_addr                                        "0xB800E258"
#define  CABAC_P2_P2_HEVCPICSIZE_reg                                             0xB800E258
#define  CABAC_P2_P2_HEVCPICSIZE_inst_addr                                       "0x0022"
#define  CABAC_P2_P2_HEVCPICSIZE_inst_adr                                        "0x0096"
#define  CABAC_P2_P2_HEVCPICSIZE_inst                                            0x0096
#define  set_CABAC_P2_P2_HEVCPICSIZE_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_P2_HEVCPICSIZE_reg)=data)
#define  get_CABAC_P2_P2_HEVCPICSIZE_reg                                         (*((volatile unsigned int*)CABAC_P2_P2_HEVCPICSIZE_reg))
#define  CABAC_P2_P2_HEVCPICSIZE_pic_width_shift                                 (13)
#define  CABAC_P2_P2_HEVCPICSIZE_pic_height_shift                                (0)
#define  CABAC_P2_P2_HEVCPICSIZE_pic_width_mask                                  (0x07FFE000)
#define  CABAC_P2_P2_HEVCPICSIZE_pic_height_mask                                 (0x00001FFF)
#define  CABAC_P2_P2_HEVCPICSIZE_pic_width(data)                                 (0x07FFE000&((data)<<13))
#define  CABAC_P2_P2_HEVCPICSIZE_pic_height(data)                                (0x00001FFF&(data))
#define  CABAC_P2_P2_HEVCPICSIZE_get_pic_width(data)                             ((0x07FFE000&(data))>>13)
#define  CABAC_P2_P2_HEVCPICSIZE_get_pic_height(data)                            (0x00001FFF&(data))
#define  CABAC_P2_P2_HEVCPICSIZE_pic_width_src(data)                             ((0x07FFE000&(data))>>13)
#define  CABAC_P2_P2_HEVCPICSIZE_pic_height_src(data)                            (0x00001FFF&(data))

#define  CABAC_P2_P2_HEVC_CNTL                                                   0x1800E068
#define  CABAC_P2_P2_HEVC_CNTL_reg_addr                                          "0xB800E068"
#define  CABAC_P2_P2_HEVC_CNTL_reg                                               0xB800E068
#define  CABAC_P2_P2_HEVC_CNTL_inst_addr                                         "0x0023"
#define  CABAC_P2_P2_HEVC_CNTL_inst_adr                                          "0x001A"
#define  CABAC_P2_P2_HEVC_CNTL_inst                                              0x001A
#define  set_CABAC_P2_P2_HEVC_CNTL_reg(data)                                     (*((volatile unsigned int*)CABAC_P2_P2_HEVC_CNTL_reg)=data)
#define  get_CABAC_P2_P2_HEVC_CNTL_reg                                           (*((volatile unsigned int*)CABAC_P2_P2_HEVC_CNTL_reg))
#define  CABAC_P2_P2_HEVC_CNTL_vp9_fwbw_upd_max_bl_option_shift                  (26)
#define  CABAC_P2_P2_HEVC_CNTL_byte_align_always_drop_shift                      (24)
#define  CABAC_P2_P2_HEVC_CNTL_mvd_l1_zero_flag_shift                            (23)
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_chroma_shift                        (19)
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_luma_shift                          (15)
#define  CABAC_P2_P2_HEVC_CNTL_cabac_init_flag_shift                             (14)
#define  CABAC_P2_P2_HEVC_CNTL_entropy_coding_sync_enabled_flag_shift            (13)
#define  CABAC_P2_P2_HEVC_CNTL_tiles_enabled_flag_shift                          (12)
#define  CABAC_P2_P2_HEVC_CNTL_min_cu_qp_delta_size_shift                        (9)
#define  CABAC_P2_P2_HEVC_CNTL_cu_qp_delta_enabled_flag_shift                    (8)
#define  CABAC_P2_P2_HEVC_CNTL_max_num_merge_cand_shift                          (5)
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_chroma_flag_shift                       (4)
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_luma_flag_shift                         (3)
#define  CABAC_P2_P2_HEVC_CNTL_transform_skip_enabled_flag_shift                 (2)
#define  CABAC_P2_P2_HEVC_CNTL_transquant_bypass_enable_flag_shift               (1)
#define  CABAC_P2_P2_HEVC_CNTL_sign_data_hiding_flag_shift                       (0)
#define  CABAC_P2_P2_HEVC_CNTL_vp9_fwbw_upd_max_bl_option_mask                   (0x0C000000)
#define  CABAC_P2_P2_HEVC_CNTL_byte_align_always_drop_mask                       (0x01000000)
#define  CABAC_P2_P2_HEVC_CNTL_mvd_l1_zero_flag_mask                             (0x00800000)
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_chroma_mask                         (0x00780000)
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_luma_mask                           (0x00078000)
#define  CABAC_P2_P2_HEVC_CNTL_cabac_init_flag_mask                              (0x00004000)
#define  CABAC_P2_P2_HEVC_CNTL_entropy_coding_sync_enabled_flag_mask             (0x00002000)
#define  CABAC_P2_P2_HEVC_CNTL_tiles_enabled_flag_mask                           (0x00001000)
#define  CABAC_P2_P2_HEVC_CNTL_min_cu_qp_delta_size_mask                         (0x00000E00)
#define  CABAC_P2_P2_HEVC_CNTL_cu_qp_delta_enabled_flag_mask                     (0x00000100)
#define  CABAC_P2_P2_HEVC_CNTL_max_num_merge_cand_mask                           (0x000000E0)
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_chroma_flag_mask                        (0x00000010)
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_luma_flag_mask                          (0x00000008)
#define  CABAC_P2_P2_HEVC_CNTL_transform_skip_enabled_flag_mask                  (0x00000004)
#define  CABAC_P2_P2_HEVC_CNTL_transquant_bypass_enable_flag_mask                (0x00000002)
#define  CABAC_P2_P2_HEVC_CNTL_sign_data_hiding_flag_mask                        (0x00000001)
#define  CABAC_P2_P2_HEVC_CNTL_vp9_fwbw_upd_max_bl_option(data)                  (0x0C000000&((data)<<26))
#define  CABAC_P2_P2_HEVC_CNTL_byte_align_always_drop(data)                      (0x01000000&((data)<<24))
#define  CABAC_P2_P2_HEVC_CNTL_mvd_l1_zero_flag(data)                            (0x00800000&((data)<<23))
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_chroma(data)                        (0x00780000&((data)<<19))
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_luma(data)                          (0x00078000&((data)<<15))
#define  CABAC_P2_P2_HEVC_CNTL_cabac_init_flag(data)                             (0x00004000&((data)<<14))
#define  CABAC_P2_P2_HEVC_CNTL_entropy_coding_sync_enabled_flag(data)            (0x00002000&((data)<<13))
#define  CABAC_P2_P2_HEVC_CNTL_tiles_enabled_flag(data)                          (0x00001000&((data)<<12))
#define  CABAC_P2_P2_HEVC_CNTL_min_cu_qp_delta_size(data)                        (0x00000E00&((data)<<9))
#define  CABAC_P2_P2_HEVC_CNTL_cu_qp_delta_enabled_flag(data)                    (0x00000100&((data)<<8))
#define  CABAC_P2_P2_HEVC_CNTL_max_num_merge_cand(data)                          (0x000000E0&((data)<<5))
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_chroma_flag(data)                       (0x00000010&((data)<<4))
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_luma_flag(data)                         (0x00000008&((data)<<3))
#define  CABAC_P2_P2_HEVC_CNTL_transform_skip_enabled_flag(data)                 (0x00000004&((data)<<2))
#define  CABAC_P2_P2_HEVC_CNTL_transquant_bypass_enable_flag(data)               (0x00000002&((data)<<1))
#define  CABAC_P2_P2_HEVC_CNTL_sign_data_hiding_flag(data)                       (0x00000001&(data))
#define  CABAC_P2_P2_HEVC_CNTL_get_vp9_fwbw_upd_max_bl_option(data)              ((0x0C000000&(data))>>26)
#define  CABAC_P2_P2_HEVC_CNTL_get_byte_align_always_drop(data)                  ((0x01000000&(data))>>24)
#define  CABAC_P2_P2_HEVC_CNTL_get_mvd_l1_zero_flag(data)                        ((0x00800000&(data))>>23)
#define  CABAC_P2_P2_HEVC_CNTL_get_pcm_bit_depth_chroma(data)                    ((0x00780000&(data))>>19)
#define  CABAC_P2_P2_HEVC_CNTL_get_pcm_bit_depth_luma(data)                      ((0x00078000&(data))>>15)
#define  CABAC_P2_P2_HEVC_CNTL_get_cabac_init_flag(data)                         ((0x00004000&(data))>>14)
#define  CABAC_P2_P2_HEVC_CNTL_get_entropy_coding_sync_enabled_flag(data)        ((0x00002000&(data))>>13)
#define  CABAC_P2_P2_HEVC_CNTL_get_tiles_enabled_flag(data)                      ((0x00001000&(data))>>12)
#define  CABAC_P2_P2_HEVC_CNTL_get_min_cu_qp_delta_size(data)                    ((0x00000E00&(data))>>9)
#define  CABAC_P2_P2_HEVC_CNTL_get_cu_qp_delta_enabled_flag(data)                ((0x00000100&(data))>>8)
#define  CABAC_P2_P2_HEVC_CNTL_get_max_num_merge_cand(data)                      ((0x000000E0&(data))>>5)
#define  CABAC_P2_P2_HEVC_CNTL_get_slice_sao_chroma_flag(data)                   ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_HEVC_CNTL_get_slice_sao_luma_flag(data)                     ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_HEVC_CNTL_get_transform_skip_enabled_flag(data)             ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_HEVC_CNTL_get_transquant_bypass_enable_flag(data)           ((0x00000002&(data))>>1)
#define  CABAC_P2_P2_HEVC_CNTL_get_sign_data_hiding_flag(data)                   (0x00000001&(data))
#define  CABAC_P2_P2_HEVC_CNTL_vp9_fwbw_upd_max_bl_option_src(data)              ((0x0C000000&(data))>>26)
#define  CABAC_P2_P2_HEVC_CNTL_byte_align_always_drop_src(data)                  ((0x01000000&(data))>>24)
#define  CABAC_P2_P2_HEVC_CNTL_mvd_l1_zero_flag_src(data)                        ((0x00800000&(data))>>23)
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_chroma_src(data)                    ((0x00780000&(data))>>19)
#define  CABAC_P2_P2_HEVC_CNTL_pcm_bit_depth_luma_src(data)                      ((0x00078000&(data))>>15)
#define  CABAC_P2_P2_HEVC_CNTL_cabac_init_flag_src(data)                         ((0x00004000&(data))>>14)
#define  CABAC_P2_P2_HEVC_CNTL_entropy_coding_sync_enabled_flag_src(data)        ((0x00002000&(data))>>13)
#define  CABAC_P2_P2_HEVC_CNTL_tiles_enabled_flag_src(data)                      ((0x00001000&(data))>>12)
#define  CABAC_P2_P2_HEVC_CNTL_min_cu_qp_delta_size_src(data)                    ((0x00000E00&(data))>>9)
#define  CABAC_P2_P2_HEVC_CNTL_cu_qp_delta_enabled_flag_src(data)                ((0x00000100&(data))>>8)
#define  CABAC_P2_P2_HEVC_CNTL_max_num_merge_cand_src(data)                      ((0x000000E0&(data))>>5)
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_chroma_flag_src(data)                   ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_HEVC_CNTL_slice_sao_luma_flag_src(data)                     ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_HEVC_CNTL_transform_skip_enabled_flag_src(data)             ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_HEVC_CNTL_transquant_bypass_enable_flag_src(data)           ((0x00000002&(data))>>1)
#define  CABAC_P2_P2_HEVC_CNTL_sign_data_hiding_flag_src(data)                   (0x00000001&(data))

#define  CABAC_P2_P2_HEVC_TILE1                                                  0x1800E06C
#define  CABAC_P2_P2_HEVC_TILE1_reg_addr                                         "0xB800E06C"
#define  CABAC_P2_P2_HEVC_TILE1_reg                                              0xB800E06C
#define  CABAC_P2_P2_HEVC_TILE1_inst_addr                                        "0x0024"
#define  CABAC_P2_P2_HEVC_TILE1_inst_adr                                         "0x001B"
#define  CABAC_P2_P2_HEVC_TILE1_inst                                             0x001B
#define  set_CABAC_P2_P2_HEVC_TILE1_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_HEVC_TILE1_reg)=data)
#define  get_CABAC_P2_P2_HEVC_TILE1_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_HEVC_TILE1_reg))
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_w_shift                                 (9)
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_h_shift                                 (0)
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_w_mask                                  (0x0007FE00)
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_h_mask                                  (0x000001FF)
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_w(data)                                 (0x0007FE00&((data)<<9))
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_h(data)                                 (0x000001FF&(data))
#define  CABAC_P2_P2_HEVC_TILE1_get_tile_ctb_w(data)                             ((0x0007FE00&(data))>>9)
#define  CABAC_P2_P2_HEVC_TILE1_get_tile_ctb_h(data)                             (0x000001FF&(data))
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_w_src(data)                             ((0x0007FE00&(data))>>9)
#define  CABAC_P2_P2_HEVC_TILE1_tile_ctb_h_src(data)                             (0x000001FF&(data))

#define  CABAC_P2_P2_HEVC_TILE2                                                  0x1800E048
#define  CABAC_P2_P2_HEVC_TILE2_reg_addr                                         "0xB800E048"
#define  CABAC_P2_P2_HEVC_TILE2_reg                                              0xB800E048
#define  CABAC_P2_P2_HEVC_TILE2_inst_addr                                        "0x0025"
#define  CABAC_P2_P2_HEVC_TILE2_inst_adr                                         "0x0012"
#define  CABAC_P2_P2_HEVC_TILE2_inst                                             0x0012
#define  set_CABAC_P2_P2_HEVC_TILE2_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_HEVC_TILE2_reg)=data)
#define  get_CABAC_P2_P2_HEVC_TILE2_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_HEVC_TILE2_reg))
#define  CABAC_P2_P2_HEVC_TILE2_ctxmem_work_sel_shift                            (19)
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_x_shift                           (9)
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_y_shift                           (0)
#define  CABAC_P2_P2_HEVC_TILE2_ctxmem_work_sel_mask                             (0x00080000)
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_x_mask                            (0x0007FE00)
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_y_mask                            (0x000001FF)
#define  CABAC_P2_P2_HEVC_TILE2_ctxmem_work_sel(data)                            (0x00080000&((data)<<19))
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_x(data)                           (0x0007FE00&((data)<<9))
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_y(data)                           (0x000001FF&(data))
#define  CABAC_P2_P2_HEVC_TILE2_get_ctxmem_work_sel(data)                        ((0x00080000&(data))>>19)
#define  CABAC_P2_P2_HEVC_TILE2_get_tile_start_adr_x(data)                       ((0x0007FE00&(data))>>9)
#define  CABAC_P2_P2_HEVC_TILE2_get_tile_start_adr_y(data)                       (0x000001FF&(data))
#define  CABAC_P2_P2_HEVC_TILE2_ctxmem_work_sel_src(data)                        ((0x00080000&(data))>>19)
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_x_src(data)                       ((0x0007FE00&(data))>>9)
#define  CABAC_P2_P2_HEVC_TILE2_tile_start_adr_y_src(data)                       (0x000001FF&(data))

#define  CABAC_P2_P2_HEVC_TILE3                                                  0x1800E04C
#define  CABAC_P2_P2_HEVC_TILE3_reg_addr                                         "0xB800E04C"
#define  CABAC_P2_P2_HEVC_TILE3_reg                                              0xB800E04C
#define  CABAC_P2_P2_HEVC_TILE3_inst_addr                                        "0x0026"
#define  CABAC_P2_P2_HEVC_TILE3_inst_adr                                         "0x0013"
#define  CABAC_P2_P2_HEVC_TILE3_inst                                             0x0013
#define  set_CABAC_P2_P2_HEVC_TILE3_reg(data)                                    (*((volatile unsigned int*)CABAC_P2_P2_HEVC_TILE3_reg)=data)
#define  get_CABAC_P2_P2_HEVC_TILE3_reg                                          (*((volatile unsigned int*)CABAC_P2_P2_HEVC_TILE3_reg))
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_x_shift                          (9)
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_y_shift                          (0)
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_x_mask                           (0x0007FE00)
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_y_mask                           (0x000001FF)
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_x(data)                          (0x0007FE00&((data)<<9))
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_y(data)                          (0x000001FF&(data))
#define  CABAC_P2_P2_HEVC_TILE3_get_tile_offset_adr_x(data)                      ((0x0007FE00&(data))>>9)
#define  CABAC_P2_P2_HEVC_TILE3_get_tile_offset_adr_y(data)                      (0x000001FF&(data))
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_x_src(data)                      ((0x0007FE00&(data))>>9)
#define  CABAC_P2_P2_HEVC_TILE3_tile_offset_adr_y_src(data)                      (0x000001FF&(data))

#define  CABAC_P2_P2_DECBITCNT                                                   0x1800E250
#define  CABAC_P2_P2_DECBITCNT_reg_addr                                          "0xB800E250"
#define  CABAC_P2_P2_DECBITCNT_reg                                               0xB800E250
#define  CABAC_P2_P2_DECBITCNT_inst_addr                                         "0x0027"
#define  CABAC_P2_P2_DECBITCNT_inst_adr                                          "0x0094"
#define  CABAC_P2_P2_DECBITCNT_inst                                              0x0094
#define  set_CABAC_P2_P2_DECBITCNT_reg(data)                                     (*((volatile unsigned int*)CABAC_P2_P2_DECBITCNT_reg)=data)
#define  get_CABAC_P2_P2_DECBITCNT_reg                                           (*((volatile unsigned int*)CABAC_P2_P2_DECBITCNT_reg))
#define  CABAC_P2_P2_DECBITCNT_max_bit_shift                                     (0)
#define  CABAC_P2_P2_DECBITCNT_max_bit_mask                                      (0xFFFFFFFF)
#define  CABAC_P2_P2_DECBITCNT_max_bit(data)                                     (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_DECBITCNT_get_max_bit(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_DECBITCNT_max_bit_src(data)                                 (0xFFFFFFFF&(data))

#define  CABAC_P2_HEVC_CTB                                                       0x1800E078
#define  CABAC_P2_HEVC_CTB_reg_addr                                              "0xB800E078"
#define  CABAC_P2_HEVC_CTB_reg                                                   0xB800E078
#define  CABAC_P2_HEVC_CTB_inst_addr                                             "0x0028"
#define  CABAC_P2_HEVC_CTB_inst_adr                                              "0x001E"
#define  CABAC_P2_HEVC_CTB_inst                                                  0x001E
#define  set_CABAC_P2_HEVC_CTB_reg(data)                                         (*((volatile unsigned int*)CABAC_P2_HEVC_CTB_reg)=data)
#define  get_CABAC_P2_HEVC_CTB_reg                                               (*((volatile unsigned int*)CABAC_P2_HEVC_CTB_reg))
#define  CABAC_P2_HEVC_CTB_bin_loc_reg_shift                                     (0)
#define  CABAC_P2_HEVC_CTB_bin_loc_reg_mask                                      (0xFFFFFFFF)
#define  CABAC_P2_HEVC_CTB_bin_loc_reg(data)                                     (0xFFFFFFFF&(data))
#define  CABAC_P2_HEVC_CTB_get_bin_loc_reg(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_HEVC_CTB_bin_loc_reg_src(data)                                 (0xFFFFFFFF&(data))

#define  CABAC_P2_HEVC_PRE_CTB                                                   0x1800E07C
#define  CABAC_P2_HEVC_PRE_CTB_reg_addr                                          "0xB800E07C"
#define  CABAC_P2_HEVC_PRE_CTB_reg                                               0xB800E07C
#define  CABAC_P2_HEVC_PRE_CTB_inst_addr                                         "0x0029"
#define  CABAC_P2_HEVC_PRE_CTB_inst_adr                                          "0x001F"
#define  CABAC_P2_HEVC_PRE_CTB_inst                                              0x001F
#define  set_CABAC_P2_HEVC_PRE_CTB_reg(data)                                     (*((volatile unsigned int*)CABAC_P2_HEVC_PRE_CTB_reg)=data)
#define  get_CABAC_P2_HEVC_PRE_CTB_reg                                           (*((volatile unsigned int*)CABAC_P2_HEVC_PRE_CTB_reg))
#define  CABAC_P2_HEVC_PRE_CTB_bin_loc_reg_shift                                 (0)
#define  CABAC_P2_HEVC_PRE_CTB_bin_loc_reg_mask                                  (0xFFFFFFFF)
#define  CABAC_P2_HEVC_PRE_CTB_bin_loc_reg(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_HEVC_PRE_CTB_get_bin_loc_reg(data)                             (0xFFFFFFFF&(data))
#define  CABAC_P2_HEVC_PRE_CTB_bin_loc_reg_src(data)                             (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_SEGTAB_BASE                                                 0x1800E024
#define  CABAC_P2_P2_SEGTAB_BASE_reg_addr                                        "0xB800E024"
#define  CABAC_P2_P2_SEGTAB_BASE_reg                                             0xB800E024
#define  CABAC_P2_P2_SEGTAB_BASE_inst_addr                                       "0x002A"
#define  CABAC_P2_P2_SEGTAB_BASE_inst_adr                                        "0x0009"
#define  CABAC_P2_P2_SEGTAB_BASE_inst                                            0x0009
#define  set_CABAC_P2_P2_SEGTAB_BASE_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_P2_SEGTAB_BASE_reg)=data)
#define  get_CABAC_P2_P2_SEGTAB_BASE_reg                                         (*((volatile unsigned int*)CABAC_P2_P2_SEGTAB_BASE_reg))
#define  CABAC_P2_P2_SEGTAB_BASE_base_addr_shift                                 (0)
#define  CABAC_P2_P2_SEGTAB_BASE_base_addr_mask                                  (0xFFFFFFFF)
#define  CABAC_P2_P2_SEGTAB_BASE_base_addr(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_SEGTAB_BASE_get_base_addr(data)                             (0xFFFFFFFF&(data))
#define  CABAC_P2_P2_SEGTAB_BASE_base_addr_src(data)                             (0xFFFFFFFF&(data))

#define  CABAC_P2_P2_SEG_SET0                                                    0x1800E028
#define  CABAC_P2_P2_SEG_SET0_reg_addr                                           "0xB800E028"
#define  CABAC_P2_P2_SEG_SET0_reg                                                0xB800E028
#define  CABAC_P2_P2_SEG_SET0_inst_addr                                          "0x002B"
#define  CABAC_P2_P2_SEG_SET0_inst_adr                                           "0x000A"
#define  CABAC_P2_P2_SEG_SET0_inst                                               0x000A
#define  set_CABAC_P2_P2_SEG_SET0_reg(data)                                      (*((volatile unsigned int*)CABAC_P2_P2_SEG_SET0_reg)=data)
#define  get_CABAC_P2_P2_SEG_SET0_reg                                            (*((volatile unsigned int*)CABAC_P2_P2_SEG_SET0_reg))
#define  CABAC_P2_P2_SEG_SET0_id_7_ref_frame_shift                               (21)
#define  CABAC_P2_P2_SEG_SET0_id_6_ref_frame_shift                               (18)
#define  CABAC_P2_P2_SEG_SET0_id_5_ref_frame_shift                               (15)
#define  CABAC_P2_P2_SEG_SET0_id_4_ref_frame_shift                               (12)
#define  CABAC_P2_P2_SEG_SET0_id_3_ref_frame_shift                               (9)
#define  CABAC_P2_P2_SEG_SET0_id_2_ref_frame_shift                               (6)
#define  CABAC_P2_P2_SEG_SET0_id_1_ref_frame_shift                               (3)
#define  CABAC_P2_P2_SEG_SET0_id_0_ref_frame_shift                               (0)
#define  CABAC_P2_P2_SEG_SET0_id_7_ref_frame_mask                                (0x00E00000)
#define  CABAC_P2_P2_SEG_SET0_id_6_ref_frame_mask                                (0x001C0000)
#define  CABAC_P2_P2_SEG_SET0_id_5_ref_frame_mask                                (0x00038000)
#define  CABAC_P2_P2_SEG_SET0_id_4_ref_frame_mask                                (0x00007000)
#define  CABAC_P2_P2_SEG_SET0_id_3_ref_frame_mask                                (0x00000E00)
#define  CABAC_P2_P2_SEG_SET0_id_2_ref_frame_mask                                (0x000001C0)
#define  CABAC_P2_P2_SEG_SET0_id_1_ref_frame_mask                                (0x00000038)
#define  CABAC_P2_P2_SEG_SET0_id_0_ref_frame_mask                                (0x00000007)
#define  CABAC_P2_P2_SEG_SET0_id_7_ref_frame(data)                               (0x00E00000&((data)<<21))
#define  CABAC_P2_P2_SEG_SET0_id_6_ref_frame(data)                               (0x001C0000&((data)<<18))
#define  CABAC_P2_P2_SEG_SET0_id_5_ref_frame(data)                               (0x00038000&((data)<<15))
#define  CABAC_P2_P2_SEG_SET0_id_4_ref_frame(data)                               (0x00007000&((data)<<12))
#define  CABAC_P2_P2_SEG_SET0_id_3_ref_frame(data)                               (0x00000E00&((data)<<9))
#define  CABAC_P2_P2_SEG_SET0_id_2_ref_frame(data)                               (0x000001C0&((data)<<6))
#define  CABAC_P2_P2_SEG_SET0_id_1_ref_frame(data)                               (0x00000038&((data)<<3))
#define  CABAC_P2_P2_SEG_SET0_id_0_ref_frame(data)                               (0x00000007&(data))
#define  CABAC_P2_P2_SEG_SET0_get_id_7_ref_frame(data)                           ((0x00E00000&(data))>>21)
#define  CABAC_P2_P2_SEG_SET0_get_id_6_ref_frame(data)                           ((0x001C0000&(data))>>18)
#define  CABAC_P2_P2_SEG_SET0_get_id_5_ref_frame(data)                           ((0x00038000&(data))>>15)
#define  CABAC_P2_P2_SEG_SET0_get_id_4_ref_frame(data)                           ((0x00007000&(data))>>12)
#define  CABAC_P2_P2_SEG_SET0_get_id_3_ref_frame(data)                           ((0x00000E00&(data))>>9)
#define  CABAC_P2_P2_SEG_SET0_get_id_2_ref_frame(data)                           ((0x000001C0&(data))>>6)
#define  CABAC_P2_P2_SEG_SET0_get_id_1_ref_frame(data)                           ((0x00000038&(data))>>3)
#define  CABAC_P2_P2_SEG_SET0_get_id_0_ref_frame(data)                           (0x00000007&(data))
#define  CABAC_P2_P2_SEG_SET0_id_7_ref_frame_src(data)                           ((0x00E00000&(data))>>21)
#define  CABAC_P2_P2_SEG_SET0_id_6_ref_frame_src(data)                           ((0x001C0000&(data))>>18)
#define  CABAC_P2_P2_SEG_SET0_id_5_ref_frame_src(data)                           ((0x00038000&(data))>>15)
#define  CABAC_P2_P2_SEG_SET0_id_4_ref_frame_src(data)                           ((0x00007000&(data))>>12)
#define  CABAC_P2_P2_SEG_SET0_id_3_ref_frame_src(data)                           ((0x00000E00&(data))>>9)
#define  CABAC_P2_P2_SEG_SET0_id_2_ref_frame_src(data)                           ((0x000001C0&(data))>>6)
#define  CABAC_P2_P2_SEG_SET0_id_1_ref_frame_src(data)                           ((0x00000038&(data))>>3)
#define  CABAC_P2_P2_SEG_SET0_id_0_ref_frame_src(data)                           (0x00000007&(data))

#define  CABAC_P2_P2_SEG_SET1                                                    0x1800E02C
#define  CABAC_P2_P2_SEG_SET1_reg_addr                                           "0xB800E02C"
#define  CABAC_P2_P2_SEG_SET1_reg                                                0xB800E02C
#define  CABAC_P2_P2_SEG_SET1_inst_addr                                          "0x002C"
#define  CABAC_P2_P2_SEG_SET1_inst_adr                                           "0x000B"
#define  CABAC_P2_P2_SEG_SET1_inst                                               0x000B
#define  set_CABAC_P2_P2_SEG_SET1_reg(data)                                      (*((volatile unsigned int*)CABAC_P2_P2_SEG_SET1_reg)=data)
#define  get_CABAC_P2_P2_SEG_SET1_reg                                            (*((volatile unsigned int*)CABAC_P2_P2_SEG_SET1_reg))
#define  CABAC_P2_P2_SEG_SET1_prev_frm_id_is_all_0_shift                         (29)
#define  CABAC_P2_P2_SEG_SET1_id_skip_mask_shift                                 (21)
#define  CABAC_P2_P2_SEG_SET1_id_ref_frame_mask_shift                            (13)
#define  CABAC_P2_P2_SEG_SET1_id_7_skip_shift                                    (12)
#define  CABAC_P2_P2_SEG_SET1_id_6_skip_shift                                    (11)
#define  CABAC_P2_P2_SEG_SET1_id_5_skip_shift                                    (10)
#define  CABAC_P2_P2_SEG_SET1_id_4_skip_shift                                    (9)
#define  CABAC_P2_P2_SEG_SET1_id_3_skip_shift                                    (8)
#define  CABAC_P2_P2_SEG_SET1_id_2_skip_shift                                    (7)
#define  CABAC_P2_P2_SEG_SET1_id_1_skip_shift                                    (6)
#define  CABAC_P2_P2_SEG_SET1_id_0_skip_shift                                    (5)
#define  CABAC_P2_P2_SEG_SET1_temperal_update_shift                              (4)
#define  CABAC_P2_P2_SEG_SET1_abs_delta_shift                                    (3)
#define  CABAC_P2_P2_SEG_SET1_update_data_shift                                  (2)
#define  CABAC_P2_P2_SEG_SET1_update_map_shift                                   (1)
#define  CABAC_P2_P2_SEG_SET1_enabled_shift                                      (0)
#define  CABAC_P2_P2_SEG_SET1_prev_frm_id_is_all_0_mask                          (0x20000000)
#define  CABAC_P2_P2_SEG_SET1_id_skip_mask_mask                                  (0x1FE00000)
#define  CABAC_P2_P2_SEG_SET1_id_ref_frame_mask_mask                             (0x001FE000)
#define  CABAC_P2_P2_SEG_SET1_id_7_skip_mask                                     (0x00001000)
#define  CABAC_P2_P2_SEG_SET1_id_6_skip_mask                                     (0x00000800)
#define  CABAC_P2_P2_SEG_SET1_id_5_skip_mask                                     (0x00000400)
#define  CABAC_P2_P2_SEG_SET1_id_4_skip_mask                                     (0x00000200)
#define  CABAC_P2_P2_SEG_SET1_id_3_skip_mask                                     (0x00000100)
#define  CABAC_P2_P2_SEG_SET1_id_2_skip_mask                                     (0x00000080)
#define  CABAC_P2_P2_SEG_SET1_id_1_skip_mask                                     (0x00000040)
#define  CABAC_P2_P2_SEG_SET1_id_0_skip_mask                                     (0x00000020)
#define  CABAC_P2_P2_SEG_SET1_temperal_update_mask                               (0x00000010)
#define  CABAC_P2_P2_SEG_SET1_abs_delta_mask                                     (0x00000008)
#define  CABAC_P2_P2_SEG_SET1_update_data_mask                                   (0x00000004)
#define  CABAC_P2_P2_SEG_SET1_update_map_mask                                    (0x00000002)
#define  CABAC_P2_P2_SEG_SET1_enabled_mask                                       (0x00000001)
#define  CABAC_P2_P2_SEG_SET1_prev_frm_id_is_all_0(data)                         (0x20000000&((data)<<29))
#define  CABAC_P2_P2_SEG_SET1_id_skip_mask(data)                                 (0x1FE00000&((data)<<21))
#define  CABAC_P2_P2_SEG_SET1_id_ref_frame_mask(data)                            (0x001FE000&((data)<<13))
#define  CABAC_P2_P2_SEG_SET1_id_7_skip(data)                                    (0x00001000&((data)<<12))
#define  CABAC_P2_P2_SEG_SET1_id_6_skip(data)                                    (0x00000800&((data)<<11))
#define  CABAC_P2_P2_SEG_SET1_id_5_skip(data)                                    (0x00000400&((data)<<10))
#define  CABAC_P2_P2_SEG_SET1_id_4_skip(data)                                    (0x00000200&((data)<<9))
#define  CABAC_P2_P2_SEG_SET1_id_3_skip(data)                                    (0x00000100&((data)<<8))
#define  CABAC_P2_P2_SEG_SET1_id_2_skip(data)                                    (0x00000080&((data)<<7))
#define  CABAC_P2_P2_SEG_SET1_id_1_skip(data)                                    (0x00000040&((data)<<6))
#define  CABAC_P2_P2_SEG_SET1_id_0_skip(data)                                    (0x00000020&((data)<<5))
#define  CABAC_P2_P2_SEG_SET1_temperal_update(data)                              (0x00000010&((data)<<4))
#define  CABAC_P2_P2_SEG_SET1_abs_delta(data)                                    (0x00000008&((data)<<3))
#define  CABAC_P2_P2_SEG_SET1_update_data(data)                                  (0x00000004&((data)<<2))
#define  CABAC_P2_P2_SEG_SET1_update_map(data)                                   (0x00000002&((data)<<1))
#define  CABAC_P2_P2_SEG_SET1_enabled(data)                                      (0x00000001&(data))
#define  CABAC_P2_P2_SEG_SET1_get_prev_frm_id_is_all_0(data)                     ((0x20000000&(data))>>29)
#define  CABAC_P2_P2_SEG_SET1_get_id_skip_mask(data)                             ((0x1FE00000&(data))>>21)
#define  CABAC_P2_P2_SEG_SET1_get_id_ref_frame_mask(data)                        ((0x001FE000&(data))>>13)
#define  CABAC_P2_P2_SEG_SET1_get_id_7_skip(data)                                ((0x00001000&(data))>>12)
#define  CABAC_P2_P2_SEG_SET1_get_id_6_skip(data)                                ((0x00000800&(data))>>11)
#define  CABAC_P2_P2_SEG_SET1_get_id_5_skip(data)                                ((0x00000400&(data))>>10)
#define  CABAC_P2_P2_SEG_SET1_get_id_4_skip(data)                                ((0x00000200&(data))>>9)
#define  CABAC_P2_P2_SEG_SET1_get_id_3_skip(data)                                ((0x00000100&(data))>>8)
#define  CABAC_P2_P2_SEG_SET1_get_id_2_skip(data)                                ((0x00000080&(data))>>7)
#define  CABAC_P2_P2_SEG_SET1_get_id_1_skip(data)                                ((0x00000040&(data))>>6)
#define  CABAC_P2_P2_SEG_SET1_get_id_0_skip(data)                                ((0x00000020&(data))>>5)
#define  CABAC_P2_P2_SEG_SET1_get_temperal_update(data)                          ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_SEG_SET1_get_abs_delta(data)                                ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_SEG_SET1_get_update_data(data)                              ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_SEG_SET1_get_update_map(data)                               ((0x00000002&(data))>>1)
#define  CABAC_P2_P2_SEG_SET1_get_enabled(data)                                  (0x00000001&(data))
#define  CABAC_P2_P2_SEG_SET1_prev_frm_id_is_all_0_src(data)                     ((0x20000000&(data))>>29)
#define  CABAC_P2_P2_SEG_SET1_id_skip_mask_src(data)                             ((0x1FE00000&(data))>>21)
#define  CABAC_P2_P2_SEG_SET1_id_ref_frame_mask_src(data)                        ((0x001FE000&(data))>>13)
#define  CABAC_P2_P2_SEG_SET1_id_7_skip_src(data)                                ((0x00001000&(data))>>12)
#define  CABAC_P2_P2_SEG_SET1_id_6_skip_src(data)                                ((0x00000800&(data))>>11)
#define  CABAC_P2_P2_SEG_SET1_id_5_skip_src(data)                                ((0x00000400&(data))>>10)
#define  CABAC_P2_P2_SEG_SET1_id_4_skip_src(data)                                ((0x00000200&(data))>>9)
#define  CABAC_P2_P2_SEG_SET1_id_3_skip_src(data)                                ((0x00000100&(data))>>8)
#define  CABAC_P2_P2_SEG_SET1_id_2_skip_src(data)                                ((0x00000080&(data))>>7)
#define  CABAC_P2_P2_SEG_SET1_id_1_skip_src(data)                                ((0x00000040&(data))>>6)
#define  CABAC_P2_P2_SEG_SET1_id_0_skip_src(data)                                ((0x00000020&(data))>>5)
#define  CABAC_P2_P2_SEG_SET1_temperal_update_src(data)                          ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_SEG_SET1_abs_delta_src(data)                                ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_SEG_SET1_update_data_src(data)                              ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_SEG_SET1_update_map_src(data)                               ((0x00000002&(data))>>1)
#define  CABAC_P2_P2_SEG_SET1_enabled_src(data)                                  (0x00000001&(data))

#define  CABAC_P2_P2_VP9_PIC_LEVEL                                               0x1800E12C
#define  CABAC_P2_P2_VP9_PIC_LEVEL_reg_addr                                      "0xB800E12C"
#define  CABAC_P2_P2_VP9_PIC_LEVEL_reg                                           0xB800E12C
#define  CABAC_P2_P2_VP9_PIC_LEVEL_inst_addr                                     "0x002D"
#define  CABAC_P2_P2_VP9_PIC_LEVEL_inst_adr                                      "0x004B"
#define  CABAC_P2_P2_VP9_PIC_LEVEL_inst                                          0x004B
#define  set_CABAC_P2_P2_VP9_PIC_LEVEL_reg(data)                                 (*((volatile unsigned int*)CABAC_P2_P2_VP9_PIC_LEVEL_reg)=data)
#define  get_CABAC_P2_P2_VP9_PIC_LEVEL_reg                                       (*((volatile unsigned int*)CABAC_P2_P2_VP9_PIC_LEVEL_reg))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_lossless_shift                                (23)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_allow_high_precision_mv_shift                 (22)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_error_resilient_mode_shift                    (21)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_x_shift                           (20)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_y_shift                           (19)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_intra_only_shift                              (18)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_tx_mode_shift                                 (15)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_reference_mode_shift                          (13)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_ref_frame_sign_bias_shift                     (9)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_fixed_ref_shift                          (7)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_0_shift                          (5)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_1_shift                          (3)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_interp_filter_shift                           (0)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_lossless_mask                                 (0x00800000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_allow_high_precision_mv_mask                  (0x00400000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_error_resilient_mode_mask                     (0x00200000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_x_mask                            (0x00100000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_y_mask                            (0x00080000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_intra_only_mask                               (0x00040000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_tx_mode_mask                                  (0x00038000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_reference_mode_mask                           (0x00006000)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_ref_frame_sign_bias_mask                      (0x00001E00)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_fixed_ref_mask                           (0x00000180)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_0_mask                           (0x00000060)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_1_mask                           (0x00000018)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_interp_filter_mask                            (0x00000007)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_lossless(data)                                (0x00800000&((data)<<23))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_allow_high_precision_mv(data)                 (0x00400000&((data)<<22))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_error_resilient_mode(data)                    (0x00200000&((data)<<21))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_x(data)                           (0x00100000&((data)<<20))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_y(data)                           (0x00080000&((data)<<19))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_intra_only(data)                              (0x00040000&((data)<<18))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_tx_mode(data)                                 (0x00038000&((data)<<15))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_reference_mode(data)                          (0x00006000&((data)<<13))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_ref_frame_sign_bias(data)                     (0x00001E00&((data)<<9))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_fixed_ref(data)                          (0x00000180&((data)<<7))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_0(data)                          (0x00000060&((data)<<5))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_1(data)                          (0x00000018&((data)<<3))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_interp_filter(data)                           (0x00000007&(data))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_lossless(data)                            ((0x00800000&(data))>>23)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_allow_high_precision_mv(data)             ((0x00400000&(data))>>22)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_error_resilient_mode(data)                ((0x00200000&(data))>>21)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_subsampling_x(data)                       ((0x00100000&(data))>>20)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_subsampling_y(data)                       ((0x00080000&(data))>>19)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_intra_only(data)                          ((0x00040000&(data))>>18)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_tx_mode(data)                             ((0x00038000&(data))>>15)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_reference_mode(data)                      ((0x00006000&(data))>>13)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_ref_frame_sign_bias(data)                 ((0x00001E00&(data))>>9)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_comp_fixed_ref(data)                      ((0x00000180&(data))>>7)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_comp_var_ref_0(data)                      ((0x00000060&(data))>>5)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_comp_var_ref_1(data)                      ((0x00000018&(data))>>3)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_get_interp_filter(data)                       (0x00000007&(data))
#define  CABAC_P2_P2_VP9_PIC_LEVEL_lossless_src(data)                            ((0x00800000&(data))>>23)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_allow_high_precision_mv_src(data)             ((0x00400000&(data))>>22)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_error_resilient_mode_src(data)                ((0x00200000&(data))>>21)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_x_src(data)                       ((0x00100000&(data))>>20)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_subsampling_y_src(data)                       ((0x00080000&(data))>>19)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_intra_only_src(data)                          ((0x00040000&(data))>>18)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_tx_mode_src(data)                             ((0x00038000&(data))>>15)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_reference_mode_src(data)                      ((0x00006000&(data))>>13)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_ref_frame_sign_bias_src(data)                 ((0x00001E00&(data))>>9)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_fixed_ref_src(data)                      ((0x00000180&(data))>>7)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_0_src(data)                      ((0x00000060&(data))>>5)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_comp_var_ref_1_src(data)                      ((0x00000018&(data))>>3)
#define  CABAC_P2_P2_VP9_PIC_LEVEL_interp_filter_src(data)                       (0x00000007&(data))

#define  CABAC_P2_VP9CO                                                          0x1800E084
#define  CABAC_P2_VP9CO_reg_addr                                                 "0xB800E084"
#define  CABAC_P2_VP9CO_reg                                                      0xB800E084
#define  CABAC_P2_VP9CO_inst_addr                                                "0x002E"
#define  CABAC_P2_VP9CO_inst_adr                                                 "0x0021"
#define  CABAC_P2_VP9CO_inst                                                     0x0021
#define  set_CABAC_P2_VP9CO_reg(data)                                            (*((volatile unsigned int*)CABAC_P2_VP9CO_reg)=data)
#define  get_CABAC_P2_VP9CO_reg                                                  (*((volatile unsigned int*)CABAC_P2_VP9CO_reg))
#define  CABAC_P2_VP9CO_StCoMemSAddr_shift                                       (0)
#define  CABAC_P2_VP9CO_StCoMemSAddr_mask                                        (0xFFFFFFFF)
#define  CABAC_P2_VP9CO_StCoMemSAddr(data)                                       (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9CO_get_StCoMemSAddr(data)                                   (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9CO_StCoMemSAddr_src(data)                                   (0xFFFFFFFF&(data))

#define  CABAC_P2_VP9CO1                                                         0x1800E088
#define  CABAC_P2_VP9CO1_reg_addr                                                "0xB800E088"
#define  CABAC_P2_VP9CO1_reg                                                     0xB800E088
#define  CABAC_P2_VP9CO1_inst_addr                                               "0x002F"
#define  CABAC_P2_VP9CO1_inst_adr                                                "0x0022"
#define  CABAC_P2_VP9CO1_inst                                                    0x0022
#define  set_CABAC_P2_VP9CO1_reg(data)                                           (*((volatile unsigned int*)CABAC_P2_VP9CO1_reg)=data)
#define  get_CABAC_P2_VP9CO1_reg                                                 (*((volatile unsigned int*)CABAC_P2_VP9CO1_reg))
#define  CABAC_P2_VP9CO1_LdCoMemSAddr_shift                                      (0)
#define  CABAC_P2_VP9CO1_LdCoMemSAddr_mask                                       (0xFFFFFFFF)
#define  CABAC_P2_VP9CO1_LdCoMemSAddr(data)                                      (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9CO1_get_LdCoMemSAddr(data)                                  (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9CO1_LdCoMemSAddr_src(data)                                  (0xFFFFFFFF&(data))

#define  CABAC_P2_VP9NH                                                          0x1800E08C
#define  CABAC_P2_VP9NH_reg_addr                                                 "0xB800E08C"
#define  CABAC_P2_VP9NH_reg                                                      0xB800E08C
#define  CABAC_P2_VP9NH_inst_addr                                                "0x0030"
#define  CABAC_P2_VP9NH_inst_adr                                                 "0x0023"
#define  CABAC_P2_VP9NH_inst                                                     0x0023
#define  set_CABAC_P2_VP9NH_reg(data)                                            (*((volatile unsigned int*)CABAC_P2_VP9NH_reg)=data)
#define  get_CABAC_P2_VP9NH_reg                                                  (*((volatile unsigned int*)CABAC_P2_VP9NH_reg))
#define  CABAC_P2_VP9NH_StNhMemSAddr_shift                                       (0)
#define  CABAC_P2_VP9NH_StNhMemSAddr_mask                                        (0xFFFFFFFF)
#define  CABAC_P2_VP9NH_StNhMemSAddr(data)                                       (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9NH_get_StNhMemSAddr(data)                                   (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9NH_StNhMemSAddr_src(data)                                   (0xFFFFFFFF&(data))

#define  CABAC_P2_VP9NH1                                                         0x1800E098
#define  CABAC_P2_VP9NH1_reg_addr                                                "0xB800E098"
#define  CABAC_P2_VP9NH1_reg                                                     0xB800E098
#define  CABAC_P2_VP9NH1_inst_addr                                               "0x0031"
#define  CABAC_P2_VP9NH1_inst_adr                                                "0x0026"
#define  CABAC_P2_VP9NH1_inst                                                    0x0026
#define  set_CABAC_P2_VP9NH1_reg(data)                                           (*((volatile unsigned int*)CABAC_P2_VP9NH1_reg)=data)
#define  get_CABAC_P2_VP9NH1_reg                                                 (*((volatile unsigned int*)CABAC_P2_VP9NH1_reg))
#define  CABAC_P2_VP9NH1_LdNhMemSAddr_shift                                      (0)
#define  CABAC_P2_VP9NH1_LdNhMemSAddr_mask                                       (0xFFFFFFFF)
#define  CABAC_P2_VP9NH1_LdNhMemSAddr(data)                                      (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9NH1_get_LdNhMemSAddr(data)                                  (0xFFFFFFFF&(data))
#define  CABAC_P2_VP9NH1_LdNhMemSAddr_src(data)                                  (0xFFFFFFFF&(data))

#define  CABAC_P2_VP9CO2                                                         0x1800E268
#define  CABAC_P2_VP9CO2_reg_addr                                                "0xB800E268"
#define  CABAC_P2_VP9CO2_reg                                                     0xB800E268
#define  CABAC_P2_VP9CO2_inst_addr                                               "0x0032"
#define  CABAC_P2_VP9CO2_inst_adr                                                "0x009A"
#define  CABAC_P2_VP9CO2_inst                                                    0x009A
#define  set_CABAC_P2_VP9CO2_reg(data)                                           (*((volatile unsigned int*)CABAC_P2_VP9CO2_reg)=data)
#define  get_CABAC_P2_VP9CO2_reg                                                 (*((volatile unsigned int*)CABAC_P2_VP9CO2_reg))
#define  CABAC_P2_VP9CO2_DisableCoMem_shift                                      (0)
#define  CABAC_P2_VP9CO2_DisableCoMem_mask                                       (0x00000001)
#define  CABAC_P2_VP9CO2_DisableCoMem(data)                                      (0x00000001&(data))
#define  CABAC_P2_VP9CO2_get_DisableCoMem(data)                                  (0x00000001&(data))
#define  CABAC_P2_VP9CO2_DisableCoMem_src(data)                                  (0x00000001&(data))

#define  CABAC_P2_P2_NDB_CTL                                                     0x1800E3B8
#define  CABAC_P2_P2_NDB_CTL_reg_addr                                            "0xB800E3B8"
#define  CABAC_P2_P2_NDB_CTL_reg                                                 0xB800E3B8
#define  CABAC_P2_P2_NDB_CTL_inst_addr                                           "0x0033"
#define  CABAC_P2_P2_NDB_CTL_inst_adr                                            "0x00EE"
#define  CABAC_P2_P2_NDB_CTL_inst                                                0x00EE
#define  set_CABAC_P2_P2_NDB_CTL_reg(data)                                       (*((volatile unsigned int*)CABAC_P2_P2_NDB_CTL_reg)=data)
#define  get_CABAC_P2_P2_NDB_CTL_reg                                             (*((volatile unsigned int*)CABAC_P2_P2_NDB_CTL_reg))
#define  CABAC_P2_P2_NDB_CTL_write_enable3_shift                                 (5)
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_done_shift                               (4)
#define  CABAC_P2_P2_NDB_CTL_write_enable2_shift                                 (3)
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_shift                                    (2)
#define  CABAC_P2_P2_NDB_CTL_write_enable1_shift                                 (1)
#define  CABAC_P2_P2_NDB_CTL_postwrite_en_shift                                  (0)
#define  CABAC_P2_P2_NDB_CTL_write_enable3_mask                                  (0x00000020)
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_done_mask                                (0x00000010)
#define  CABAC_P2_P2_NDB_CTL_write_enable2_mask                                  (0x00000008)
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_mask                                     (0x00000004)
#define  CABAC_P2_P2_NDB_CTL_write_enable1_mask                                  (0x00000002)
#define  CABAC_P2_P2_NDB_CTL_postwrite_en_mask                                   (0x00000001)
#define  CABAC_P2_P2_NDB_CTL_write_enable3(data)                                 (0x00000020&((data)<<5))
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_done(data)                               (0x00000010&((data)<<4))
#define  CABAC_P2_P2_NDB_CTL_write_enable2(data)                                 (0x00000008&((data)<<3))
#define  CABAC_P2_P2_NDB_CTL_cabac_halt(data)                                    (0x00000004&((data)<<2))
#define  CABAC_P2_P2_NDB_CTL_write_enable1(data)                                 (0x00000002&((data)<<1))
#define  CABAC_P2_P2_NDB_CTL_postwrite_en(data)                                  (0x00000001&(data))
#define  CABAC_P2_P2_NDB_CTL_get_write_enable3(data)                             ((0x00000020&(data))>>5)
#define  CABAC_P2_P2_NDB_CTL_get_cabac_halt_done(data)                           ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_NDB_CTL_get_write_enable2(data)                             ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_NDB_CTL_get_cabac_halt(data)                                ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_NDB_CTL_get_write_enable1(data)                             ((0x00000002&(data))>>1)
#define  CABAC_P2_P2_NDB_CTL_get_postwrite_en(data)                              (0x00000001&(data))
#define  CABAC_P2_P2_NDB_CTL_write_enable3_src(data)                             ((0x00000020&(data))>>5)
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_done_src(data)                           ((0x00000010&(data))>>4)
#define  CABAC_P2_P2_NDB_CTL_write_enable2_src(data)                             ((0x00000008&(data))>>3)
#define  CABAC_P2_P2_NDB_CTL_cabac_halt_src(data)                                ((0x00000004&(data))>>2)
#define  CABAC_P2_P2_NDB_CTL_write_enable1_src(data)                             ((0x00000002&(data))>>1)
#define  CABAC_P2_P2_NDB_CTL_postwrite_en_src(data)                              (0x00000001&(data))

#define  CABAC_P2_NDB_CABAC_BASE                                                 0x1800E394
#define  CABAC_P2_NDB_CABAC_BASE_reg_addr                                        "0xB800E394"
#define  CABAC_P2_NDB_CABAC_BASE_reg                                             0xB800E394
#define  CABAC_P2_NDB_CABAC_BASE_inst_addr                                       "0x0034"
#define  CABAC_P2_NDB_CABAC_BASE_inst_adr                                        "0x00E5"
#define  CABAC_P2_NDB_CABAC_BASE_inst                                            0x00E5
#define  set_CABAC_P2_NDB_CABAC_BASE_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_BASE_reg)=data)
#define  get_CABAC_P2_NDB_CABAC_BASE_reg                                         (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_BASE_reg))
#define  CABAC_P2_NDB_CABAC_BASE_base_addr_shift                                 (0)
#define  CABAC_P2_NDB_CABAC_BASE_base_addr_mask                                  (0xFFFFFFFF)
#define  CABAC_P2_NDB_CABAC_BASE_base_addr(data)                                 (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_BASE_get_base_addr(data)                             (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_BASE_base_addr_src(data)                             (0xFFFFFFFF&(data))

#define  CABAC_P2_NDB_CABAC_LIMIT                                                0x1800E39C
#define  CABAC_P2_NDB_CABAC_LIMIT_reg_addr                                       "0xB800E39C"
#define  CABAC_P2_NDB_CABAC_LIMIT_reg                                            0xB800E39C
#define  CABAC_P2_NDB_CABAC_LIMIT_inst_addr                                      "0x0035"
#define  CABAC_P2_NDB_CABAC_LIMIT_inst_adr                                       "0x00E7"
#define  CABAC_P2_NDB_CABAC_LIMIT_inst                                           0x00E7
#define  set_CABAC_P2_NDB_CABAC_LIMIT_reg(data)                                  (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_LIMIT_reg)=data)
#define  get_CABAC_P2_NDB_CABAC_LIMIT_reg                                        (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_LIMIT_reg))
#define  CABAC_P2_NDB_CABAC_LIMIT_limit_addr_shift                               (0)
#define  CABAC_P2_NDB_CABAC_LIMIT_limit_addr_mask                                (0xFFFFFFFF)
#define  CABAC_P2_NDB_CABAC_LIMIT_limit_addr(data)                               (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_LIMIT_get_limit_addr(data)                           (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_LIMIT_limit_addr_src(data)                           (0xFFFFFFFF&(data))

#define  CABAC_P2_NDB_CABAC_WPTR                                                 0x1800E3A0
#define  CABAC_P2_NDB_CABAC_WPTR_reg_addr                                        "0xB800E3A0"
#define  CABAC_P2_NDB_CABAC_WPTR_reg                                             0xB800E3A0
#define  CABAC_P2_NDB_CABAC_WPTR_inst_addr                                       "0x0036"
#define  CABAC_P2_NDB_CABAC_WPTR_inst_adr                                        "0x00E8"
#define  CABAC_P2_NDB_CABAC_WPTR_inst                                            0x00E8
#define  set_CABAC_P2_NDB_CABAC_WPTR_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_WPTR_reg)=data)
#define  get_CABAC_P2_NDB_CABAC_WPTR_reg                                         (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_WPTR_reg))
#define  CABAC_P2_NDB_CABAC_WPTR_wr_ptr_shift                                    (0)
#define  CABAC_P2_NDB_CABAC_WPTR_wr_ptr_mask                                     (0xFFFFFFFF)
#define  CABAC_P2_NDB_CABAC_WPTR_wr_ptr(data)                                    (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_WPTR_get_wr_ptr(data)                                (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_WPTR_wr_ptr_src(data)                                (0xFFFFFFFF&(data))

#define  CABAC_P2_NDB_CABAC_RPTR                                                 0x1800E3A4
#define  CABAC_P2_NDB_CABAC_RPTR_reg_addr                                        "0xB800E3A4"
#define  CABAC_P2_NDB_CABAC_RPTR_reg                                             0xB800E3A4
#define  CABAC_P2_NDB_CABAC_RPTR_inst_addr                                       "0x0037"
#define  CABAC_P2_NDB_CABAC_RPTR_inst_adr                                        "0x00E9"
#define  CABAC_P2_NDB_CABAC_RPTR_inst                                            0x00E9
#define  set_CABAC_P2_NDB_CABAC_RPTR_reg(data)                                   (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_RPTR_reg)=data)
#define  get_CABAC_P2_NDB_CABAC_RPTR_reg                                         (*((volatile unsigned int*)CABAC_P2_NDB_CABAC_RPTR_reg))
#define  CABAC_P2_NDB_CABAC_RPTR_rd_ptr_shift                                    (0)
#define  CABAC_P2_NDB_CABAC_RPTR_rd_ptr_mask                                     (0xFFFFFFFF)
#define  CABAC_P2_NDB_CABAC_RPTR_rd_ptr(data)                                    (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_RPTR_get_rd_ptr(data)                                (0xFFFFFFFF&(data))
#define  CABAC_P2_NDB_CABAC_RPTR_rd_ptr_src(data)                                (0xFFFFFFFF&(data))

#ifdef _CABAC_P2_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CABAC_P2 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_top:32;
    };
}CABAC_P2_CABAC_LEFTTOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_bot:32;
    };
}CABAC_P2_CABAC_LEFTBOT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  reset_cabacp2_bsfifo:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  decode_en_cabacp2:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  cabac_1p_mode:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  cabac_p2_p3:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_p2_go:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  latch_enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  codioffset:9;
        RBus_UInt32  codirange:9;
    };
}CABAC_P2_CABAC_P2_CNTL3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  arb_wait_value:5;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  HaltCabacp2_done:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  HaltCabacp2:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Cabacp2_idle:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabacp2_header_byte_cnt:18;
    };
}CABAC_P2_CABAC_P2_CNTL4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cabac_p2_wfifo_err:1;
        RBus_UInt32  cabac_p2_bsfifo_err:1;
        RBus_UInt32  cabac_p2_dec_err:1;
        RBus_UInt32  cabac_p2_done:1;
        RBus_UInt32  write_data:1;
    };
}CABAC_P2_CABACP2_INT_STATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cabac_p2_wfifo_err_ie:1;
        RBus_UInt32  cabac_p2_bsfifo_err_ie:1;
        RBus_UInt32  cabac_p2_dec_err_ie:1;
        RBus_UInt32  cabac_p2_done_ie:1;
        RBus_UInt32  write_data:1;
    };
}CABAC_P2_CABACP2_INT_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  hevc_eos:1;
        RBus_UInt32  hevc_p2_err:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  coding_type:5;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabacp2_pred_counter:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabacp2_curmb_addr:10;
    };
}CABAC_P2_CABAC_P2_CNTL5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  p2_startcode_prevnt_en:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  detect_startcode_error:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  min_xfer_size:2;
    };
}CABAC_P2_P2_BSCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  min_thre:7;
    };
}CABAC_P2_P2_BS_MIN_THR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  timer_value:24;
    };
}CABAC_P2_P2_BSTIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_P2_RFIFO_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CABAC_P2_P2_RFIFO_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CABAC_P2_P2_RFIFO_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CABAC_P2_P2_RFIFO_RPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_P2_WFIFO_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CABAC_P2_P2_WFIFO_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CABAC_P2_P2_WFIFO_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CABAC_P2_P2_WFIFO_RPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr:32;
    };
}CABAC_P2_P2_RFIFO_DECBSPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  pre_bin_loc_reg_msb:3;
        RBus_UInt32  bin_loc_reg_msb:3;
        RBus_UInt32  dec_bit_ptr_msb:3;
    };
}CABAC_P2_P2_RFIFO_DECBSPTR_MSB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldst_addr:32;
    };
}CABAC_P2_P2_LDSTADDR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  entropy_coding_mode:1;
        RBus_UInt32  pic_init_qp:6;
        RBus_UInt32  chroma_qp_offset:5;
        RBus_UInt32  second_chroma_qp_offset:5;
        RBus_UInt32  direct_8x8_inferflg:1;
        RBus_UInt32  transform_8x8_mode_flg:1;
        RBus_UInt32  num_ref_idx_l0_active_minus1:5;
        RBus_UInt32  num_ref_idx_l1_active_minus1:5;
    };
}CABAC_P2_CABAC_P2_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  mb_adaptive_frame_field_flag:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  picmb_w:10;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  monochrome:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  field_pic_flag:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  pic_type:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  slice_qp_delta:7;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabac_init_idc:2;
    };
}CABAC_P2_CABAC_P2_CNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_bits:2;
        RBus_UInt32  luma_bits:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  mincbsize:2;
        RBus_UInt32  ctbsize:2;
        RBus_UInt32  min_trafo_size:2;
        RBus_UInt32  max_trafo_size:2;
        RBus_UInt32  max_trans_hier_depth_inter:3;
        RBus_UInt32  max_trans_hier_depth_intra:3;
        RBus_UInt32  amp_enabled_flag:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pcm_enabled_flag:1;
        RBus_UInt32  min_ipcm_cbsize:2;
        RBus_UInt32  max_ipcm_cbsize:2;
        RBus_UInt32  res4:2;
    };
}CABAC_P2_P2_HEVCSEQCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pic_width:14;
        RBus_UInt32  pic_height:13;
    };
}CABAC_P2_P2_HEVCPICSIZE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vp9_fwbw_upd_max_bl_option:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  byte_align_always_drop:1;
        RBus_UInt32  mvd_l1_zero_flag:1;
        RBus_UInt32  pcm_bit_depth_chroma:4;
        RBus_UInt32  pcm_bit_depth_luma:4;
        RBus_UInt32  cabac_init_flag:1;
        RBus_UInt32  entropy_coding_sync_enabled_flag:1;
        RBus_UInt32  tiles_enabled_flag:1;
        RBus_UInt32  min_cu_qp_delta_size:3;
        RBus_UInt32  cu_qp_delta_enabled_flag:1;
        RBus_UInt32  max_num_merge_cand:3;
        RBus_UInt32  slice_sao_chroma_flag:1;
        RBus_UInt32  slice_sao_luma_flag:1;
        RBus_UInt32  transform_skip_enabled_flag:1;
        RBus_UInt32  transquant_bypass_enable_flag:1;
        RBus_UInt32  sign_data_hiding_flag:1;
    };
}CABAC_P2_P2_HEVC_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tile_ctb_w:10;
        RBus_UInt32  tile_ctb_h:9;
    };
}CABAC_P2_P2_HEVC_TILE1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ctxmem_work_sel:1;
        RBus_UInt32  tile_start_adr_x:10;
        RBus_UInt32  tile_start_adr_y:9;
    };
}CABAC_P2_P2_HEVC_TILE2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  tile_offset_adr_x:10;
        RBus_UInt32  tile_offset_adr_y:9;
    };
}CABAC_P2_P2_HEVC_TILE3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_bit:32;
    };
}CABAC_P2_P2_DECBITCNT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bin_loc_reg:32;
    };
}CABAC_P2_HEVC_CTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bin_loc_reg:32;
    };
}CABAC_P2_HEVC_PRE_CTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_P2_SEGTAB_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  id_7_ref_frame:3;
        RBus_UInt32  id_6_ref_frame:3;
        RBus_UInt32  id_5_ref_frame:3;
        RBus_UInt32  id_4_ref_frame:3;
        RBus_UInt32  id_3_ref_frame:3;
        RBus_UInt32  id_2_ref_frame:3;
        RBus_UInt32  id_1_ref_frame:3;
        RBus_UInt32  id_0_ref_frame:3;
    };
}CABAC_P2_P2_SEG_SET0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  prev_frm_id_is_all_0:1;
        RBus_UInt32  id_skip_mask:8;
        RBus_UInt32  id_ref_frame_mask:8;
        RBus_UInt32  id_7_skip:1;
        RBus_UInt32  id_6_skip:1;
        RBus_UInt32  id_5_skip:1;
        RBus_UInt32  id_4_skip:1;
        RBus_UInt32  id_3_skip:1;
        RBus_UInt32  id_2_skip:1;
        RBus_UInt32  id_1_skip:1;
        RBus_UInt32  id_0_skip:1;
        RBus_UInt32  temperal_update:1;
        RBus_UInt32  abs_delta:1;
        RBus_UInt32  update_data:1;
        RBus_UInt32  update_map:1;
        RBus_UInt32  enabled:1;
    };
}CABAC_P2_P2_SEG_SET1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lossless:1;
        RBus_UInt32  allow_high_precision_mv:1;
        RBus_UInt32  error_resilient_mode:1;
        RBus_UInt32  subsampling_x:1;
        RBus_UInt32  subsampling_y:1;
        RBus_UInt32  intra_only:1;
        RBus_UInt32  tx_mode:3;
        RBus_UInt32  reference_mode:2;
        RBus_UInt32  ref_frame_sign_bias:4;
        RBus_UInt32  comp_fixed_ref:2;
        RBus_UInt32  comp_var_ref_0:2;
        RBus_UInt32  comp_var_ref_1:2;
        RBus_UInt32  interp_filter:3;
    };
}CABAC_P2_P2_VP9_PIC_LEVEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  StCoMemSAddr:32;
    };
}CABAC_P2_VP9CO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LdCoMemSAddr:32;
    };
}CABAC_P2_VP9CO1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  StNhMemSAddr:32;
    };
}CABAC_P2_VP9NH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LdNhMemSAddr:32;
    };
}CABAC_P2_VP9NH1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  DisableCoMem:1;
    };
}CABAC_P2_VP9CO2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_halt_done:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_halt:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  postwrite_en:1;
    };
}CABAC_P2_P2_NDB_CTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_NDB_CABAC_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CABAC_P2_NDB_CABAC_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CABAC_P2_NDB_CABAC_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CABAC_P2_NDB_CABAC_RPTR_RBUS;

#else //apply LITTLE_ENDIAN

//======CABAC_P2 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_top:32;
    };
}CABAC_P2_CABAC_LEFTTOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  left_bot:32;
    };
}CABAC_P2_CABAC_LEFTBOT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  codirange:9;
        RBus_UInt32  codioffset:9;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  latch_enable:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_p2_go:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  cabac_p2_p3:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  cabac_1p_mode:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  decode_en_cabacp2:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  reset_cabacp2_bsfifo:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  res1:1;
    };
}CABAC_P2_CABAC_P2_CNTL3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cabacp2_header_byte_cnt:18;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Cabacp2_idle:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  HaltCabacp2:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  HaltCabacp2_done:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  arb_wait_value:5;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  res1:1;
    };
}CABAC_P2_CABAC_P2_CNTL4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  cabac_p2_done:1;
        RBus_UInt32  cabac_p2_dec_err:1;
        RBus_UInt32  cabac_p2_bsfifo_err:1;
        RBus_UInt32  cabac_p2_wfifo_err:1;
        RBus_UInt32  res1:27;
    };
}CABAC_P2_CABACP2_INT_STATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  cabac_p2_done_ie:1;
        RBus_UInt32  cabac_p2_dec_err_ie:1;
        RBus_UInt32  cabac_p2_bsfifo_err_ie:1;
        RBus_UInt32  cabac_p2_wfifo_err_ie:1;
        RBus_UInt32  res1:27;
    };
}CABAC_P2_CABACP2_INT_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cabacp2_curmb_addr:10;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabacp2_pred_counter:10;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  coding_type:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  hevc_p2_err:1;
        RBus_UInt32  hevc_eos:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:1;
    };
}CABAC_P2_CABAC_P2_CNTL5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_xfer_size:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  detect_startcode_error:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  p2_startcode_prevnt_en:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:25;
    };
}CABAC_P2_P2_BSCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  min_thre:7;
        RBus_UInt32  res1:25;
    };
}CABAC_P2_P2_BS_MIN_THR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  timer_value:24;
        RBus_UInt32  res1:8;
    };
}CABAC_P2_P2_BSTIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_P2_RFIFO_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CABAC_P2_P2_RFIFO_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CABAC_P2_P2_RFIFO_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CABAC_P2_P2_RFIFO_RPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_P2_WFIFO_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CABAC_P2_P2_WFIFO_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CABAC_P2_P2_WFIFO_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CABAC_P2_P2_WFIFO_RPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr:32;
    };
}CABAC_P2_P2_RFIFO_DECBSPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dec_bit_ptr_msb:3;
        RBus_UInt32  bin_loc_reg_msb:3;
        RBus_UInt32  pre_bin_loc_reg_msb:3;
        RBus_UInt32  res1:23;
    };
}CABAC_P2_P2_RFIFO_DECBSPTR_MSB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ldst_addr:32;
    };
}CABAC_P2_P2_LDSTADDR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  num_ref_idx_l1_active_minus1:5;
        RBus_UInt32  num_ref_idx_l0_active_minus1:5;
        RBus_UInt32  transform_8x8_mode_flg:1;
        RBus_UInt32  direct_8x8_inferflg:1;
        RBus_UInt32  second_chroma_qp_offset:5;
        RBus_UInt32  chroma_qp_offset:5;
        RBus_UInt32  pic_init_qp:6;
        RBus_UInt32  entropy_coding_mode:1;
        RBus_UInt32  res1:3;
    };
}CABAC_P2_CABAC_P2_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cabac_init_idc:2;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  slice_qp_delta:7;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  pic_type:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  field_pic_flag:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  monochrome:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  picmb_w:10;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  mb_adaptive_frame_field_flag:1;
        RBus_UInt32  write_enable7:1;
    };
}CABAC_P2_CABAC_P2_CNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  max_ipcm_cbsize:2;
        RBus_UInt32  min_ipcm_cbsize:2;
        RBus_UInt32  pcm_enabled_flag:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  amp_enabled_flag:1;
        RBus_UInt32  max_trans_hier_depth_intra:3;
        RBus_UInt32  max_trans_hier_depth_inter:3;
        RBus_UInt32  max_trafo_size:2;
        RBus_UInt32  min_trafo_size:2;
        RBus_UInt32  ctbsize:2;
        RBus_UInt32  mincbsize:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  luma_bits:2;
        RBus_UInt32  chroma_bits:2;
        RBus_UInt32  res4:2;
    };
}CABAC_P2_P2_HEVCSEQCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pic_height:13;
        RBus_UInt32  pic_width:14;
        RBus_UInt32  res1:5;
    };
}CABAC_P2_P2_HEVCPICSIZE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sign_data_hiding_flag:1;
        RBus_UInt32  transquant_bypass_enable_flag:1;
        RBus_UInt32  transform_skip_enabled_flag:1;
        RBus_UInt32  slice_sao_luma_flag:1;
        RBus_UInt32  slice_sao_chroma_flag:1;
        RBus_UInt32  max_num_merge_cand:3;
        RBus_UInt32  cu_qp_delta_enabled_flag:1;
        RBus_UInt32  min_cu_qp_delta_size:3;
        RBus_UInt32  tiles_enabled_flag:1;
        RBus_UInt32  entropy_coding_sync_enabled_flag:1;
        RBus_UInt32  cabac_init_flag:1;
        RBus_UInt32  pcm_bit_depth_luma:4;
        RBus_UInt32  pcm_bit_depth_chroma:4;
        RBus_UInt32  mvd_l1_zero_flag:1;
        RBus_UInt32  byte_align_always_drop:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vp9_fwbw_upd_max_bl_option:2;
        RBus_UInt32  res2:4;
    };
}CABAC_P2_P2_HEVC_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tile_ctb_h:9;
        RBus_UInt32  tile_ctb_w:10;
        RBus_UInt32  res1:13;
    };
}CABAC_P2_P2_HEVC_TILE1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tile_start_adr_y:9;
        RBus_UInt32  tile_start_adr_x:10;
        RBus_UInt32  ctxmem_work_sel:1;
        RBus_UInt32  res1:12;
    };
}CABAC_P2_P2_HEVC_TILE2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tile_offset_adr_y:9;
        RBus_UInt32  tile_offset_adr_x:10;
        RBus_UInt32  res1:13;
    };
}CABAC_P2_P2_HEVC_TILE3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_bit:32;
    };
}CABAC_P2_P2_DECBITCNT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bin_loc_reg:32;
    };
}CABAC_P2_HEVC_CTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bin_loc_reg:32;
    };
}CABAC_P2_HEVC_PRE_CTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_P2_SEGTAB_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  id_0_ref_frame:3;
        RBus_UInt32  id_1_ref_frame:3;
        RBus_UInt32  id_2_ref_frame:3;
        RBus_UInt32  id_3_ref_frame:3;
        RBus_UInt32  id_4_ref_frame:3;
        RBus_UInt32  id_5_ref_frame:3;
        RBus_UInt32  id_6_ref_frame:3;
        RBus_UInt32  id_7_ref_frame:3;
        RBus_UInt32  res1:8;
    };
}CABAC_P2_P2_SEG_SET0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enabled:1;
        RBus_UInt32  update_map:1;
        RBus_UInt32  update_data:1;
        RBus_UInt32  abs_delta:1;
        RBus_UInt32  temperal_update:1;
        RBus_UInt32  id_0_skip:1;
        RBus_UInt32  id_1_skip:1;
        RBus_UInt32  id_2_skip:1;
        RBus_UInt32  id_3_skip:1;
        RBus_UInt32  id_4_skip:1;
        RBus_UInt32  id_5_skip:1;
        RBus_UInt32  id_6_skip:1;
        RBus_UInt32  id_7_skip:1;
        RBus_UInt32  id_ref_frame_mask:8;
        RBus_UInt32  id_skip_mask:8;
        RBus_UInt32  prev_frm_id_is_all_0:1;
        RBus_UInt32  res1:2;
    };
}CABAC_P2_P2_SEG_SET1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  interp_filter:3;
        RBus_UInt32  comp_var_ref_1:2;
        RBus_UInt32  comp_var_ref_0:2;
        RBus_UInt32  comp_fixed_ref:2;
        RBus_UInt32  ref_frame_sign_bias:4;
        RBus_UInt32  reference_mode:2;
        RBus_UInt32  tx_mode:3;
        RBus_UInt32  intra_only:1;
        RBus_UInt32  subsampling_y:1;
        RBus_UInt32  subsampling_x:1;
        RBus_UInt32  error_resilient_mode:1;
        RBus_UInt32  allow_high_precision_mv:1;
        RBus_UInt32  lossless:1;
        RBus_UInt32  res1:8;
    };
}CABAC_P2_P2_VP9_PIC_LEVEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  StCoMemSAddr:32;
    };
}CABAC_P2_VP9CO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LdCoMemSAddr:32;
    };
}CABAC_P2_VP9CO1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  StNhMemSAddr:32;
    };
}CABAC_P2_VP9NH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LdNhMemSAddr:32;
    };
}CABAC_P2_VP9NH1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DisableCoMem:1;
        RBus_UInt32  res1:31;
    };
}CABAC_P2_VP9CO2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postwrite_en:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  cabac_halt:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  cabac_halt_done:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:26;
    };
}CABAC_P2_P2_NDB_CTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_addr:32;
    };
}CABAC_P2_NDB_CABAC_BASE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  limit_addr:32;
    };
}CABAC_P2_NDB_CABAC_LIMIT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_ptr:32;
    };
}CABAC_P2_NDB_CABAC_WPTR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_ptr:32;
    };
}CABAC_P2_NDB_CABAC_RPTR_RBUS;




#endif 


#endif 
#endif 
