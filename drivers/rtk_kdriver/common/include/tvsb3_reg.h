/**
* @file rbusTVSB3Reg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TVSB3_REG_H_
#define _RBUS_TVSB3_REG_H_

#include "rbus_types.h"



//  TVSB3 Register Address
#define  TVSB3_TV_SB3_DCU1_ARB_CR0                                               0x1801C500
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_reg_addr                                      "0xB801C500"
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_reg                                           0xB801C500
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_inst_addr                                     "0x0000"
#define  set_TVSB3_TV_SB3_DCU1_ARB_CR0_reg(data)                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_CR0_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_ARB_CR0_reg                                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_CR0_reg))
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_dummy_31_4_shift                              (4)
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_time_step_shift                               (0)
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_dummy_31_4_mask                               (0xFFFFFFF0)
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_time_step_mask                                (0x0000000F)
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_dummy_31_4(data)                              (0xFFFFFFF0&((data)<<4))
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_time_step(data)                               (0x0000000F&(data))
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_get_dummy_31_4(data)                          ((0xFFFFFFF0&(data))>>4)
#define  TVSB3_TV_SB3_DCU1_ARB_CR0_get_time_step(data)                           (0x0000000F&(data))

#define  TVSB3_TV_SB3_DCU1_ARB_CR1                                               0x1801C504
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_reg_addr                                      "0xB801C504"
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_reg                                           0xB801C504
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_inst_addr                                     "0x0001"
#define  set_TVSB3_TV_SB3_DCU1_ARB_CR1_reg(data)                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_CR1_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_ARB_CR1_reg                                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_CR1_reg))
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_cnt_src_sel_shift                             (16)
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_arb_en_shift                                  (0)
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_cnt_src_sel_mask                              (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_arb_en_mask                                   (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_cnt_src_sel(data)                             (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_arb_en(data)                                  (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_get_cnt_src_sel(data)                         ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_ARB_CR1_get_arb_en(data)                              (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1                                            0x1801C508
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_reg_addr                                   "0xB801C508"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_reg                                        0xB801C508
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_inst_addr                                  "0x0002"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR1_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR1_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR1_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR1_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_client0_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_client0_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_client0_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_client0_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_client0_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_client0_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_get_client0_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR1_get_client0_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2                                            0x1801C50C
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_reg_addr                                   "0xB801C50C"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_reg                                        0xB801C50C
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_inst_addr                                  "0x0003"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR2_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR2_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR2_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR2_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_client1_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_client1_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_client1_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_client1_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_client1_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_client1_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_get_client1_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR2_get_client1_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3                                            0x1801C510
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_reg_addr                                   "0xB801C510"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_reg                                        0xB801C510
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_inst_addr                                  "0x0004"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR3_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR3_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR3_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR3_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_client2_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_client2_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_client2_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_client2_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_client2_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_client2_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_get_client2_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR3_get_client2_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4                                            0x1801C514
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_reg_addr                                   "0xB801C514"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_reg                                        0xB801C514
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_inst_addr                                  "0x0005"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR4_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR4_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR4_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR4_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_client3_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_client3_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_client3_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_client3_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_client3_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_client3_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_get_client3_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR4_get_client3_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5                                            0x1801C518
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_reg_addr                                   "0xB801C518"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_reg                                        0xB801C518
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_inst_addr                                  "0x0006"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR5_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR5_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR5_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR5_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_client4_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_client4_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_client4_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_client4_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_client4_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_client4_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_get_client4_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR5_get_client4_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6                                            0x1801C51C
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_reg_addr                                   "0xB801C51C"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_reg                                        0xB801C51C
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_inst_addr                                  "0x0007"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR6_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR6_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR6_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR6_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_client5_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_client5_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_client5_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_client5_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_client5_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_client5_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_get_client5_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR6_get_client5_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7                                            0x1801C520
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_reg_addr                                   "0xB801C520"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_reg                                        0xB801C520
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_inst_addr                                  "0x0008"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR7_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR7_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR7_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR7_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_client6_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_client6_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_client6_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_client6_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_client6_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_client6_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_get_client6_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR7_get_client6_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8                                            0x1801C524
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_reg_addr                                   "0xB801C524"
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_reg                                        0xB801C524
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_inst_addr                                  "0x0009"
#define  set_TVSB3_TV_SB3_DCU1_LATCNT_CR8_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR8_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LATCNT_CR8_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LATCNT_CR8_reg))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_client7_latcnt_end_shift                   (16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_client7_latcnt_beg_shift                   (0)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_client7_latcnt_end_mask                    (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_client7_latcnt_beg_mask                    (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_client7_latcnt_end(data)                   (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_client7_latcnt_beg(data)                   (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_get_client7_latcnt_end(data)               ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LATCNT_CR8_get_client7_latcnt_beg(data)               (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_CTRL                                               0x1801C550
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_reg_addr                                      "0xB801C550"
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_reg                                           0xB801C550
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_inst_addr                                     "0x000A"
#define  set_TVSB3_TV_SB3_DCU1_PC_CTRL_reg(data)                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_CTRL_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_CTRL_reg                                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_CTRL_reg))
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_pc_go_shift                                   (0)
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_pc_go_mask                                    (0x00000001)
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_pc_go(data)                                   (0x00000001&(data))
#define  TVSB3_TV_SB3_DCU1_PC_CTRL_get_pc_go(data)                               (0x00000001&(data))

#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM                                       0x1801C554
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_reg_addr                              "0xB801C554"
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_reg                                   0xB801C554
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_inst_addr                             "0x000B"
#define  set_TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_reg(data)                         (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_reg                               (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_reg))
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_pc_tota_mon_num_shift                 (0)
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_pc_tota_mon_num_mask                  (0xFFFFFFFF)
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_pc_tota_mon_num(data)                 (0xFFFFFFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_MON_NUM_get_pc_tota_mon_num(data)             (0xFFFFFFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM                                       0x1801C558
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_reg_addr                              "0xB801C558"
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_reg                                   0xB801C558
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_inst_addr                             "0x000C"
#define  set_TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_reg(data)                         (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_reg                               (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_reg))
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_pc_tota_ack_num_shift                 (0)
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_pc_tota_ack_num_mask                  (0xFFFFFFFF)
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_pc_tota_ack_num(data)                 (0xFFFFFFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_ACK_NUM_get_pc_tota_ack_num(data)             (0xFFFFFFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM                                       0x1801C55C
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_reg_addr                              "0xB801C55C"
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_reg                                   0xB801C55C
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_inst_addr                             "0x000D"
#define  set_TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_reg(data)                         (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_reg                               (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_reg))
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_pc_tota_idl_num_shift                 (0)
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_pc_tota_idl_num_mask                  (0xFFFFFFFF)
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_pc_tota_idl_num(data)                 (0xFFFFFFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_TOTA_IDL_NUM_get_pc_tota_idl_num(data)             (0xFFFFFFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1                                         0x1801C560
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_reg_addr                                "0xB801C560"
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_reg                                     0xB801C560
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_inst_addr                               "0x000E"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_reg(data)                           (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_reg                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_3_shift                        (23)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog2_sel_shift                      (16)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_2_shift                        (15)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog1_sel_shift                      (8)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_1_shift                        (7)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog0_sel_shift                      (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_3_mask                         (0x00800000)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog2_sel_mask                       (0x007F0000)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_2_mask                         (0x00008000)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog1_sel_mask                       (0x00007F00)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_1_mask                         (0x00000080)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog0_sel_mask                       (0x0000007F)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_3(data)                        (0x00800000&((data)<<23))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog2_sel(data)                      (0x007F0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_2(data)                        (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog1_sel(data)                      (0x00007F00&((data)<<8))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_write_en_1(data)                        (0x00000080&((data)<<7))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_pc_prog0_sel(data)                      (0x0000007F&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_get_write_en_3(data)                    ((0x00800000&(data))>>23)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_get_pc_prog2_sel(data)                  ((0x007F0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_get_write_en_2(data)                    ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_get_pc_prog1_sel(data)                  ((0x00007F00&(data))>>8)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_get_write_en_1(data)                    ((0x00000080&(data))>>7)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl1_get_pc_prog0_sel(data)                  (0x0000007F&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2                                         0x1801C564
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_reg_addr                                "0xB801C564"
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_reg                                     0xB801C564
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_inst_addr                               "0x000F"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_reg(data)                           (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_reg                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog2_req_occur_shift                (2)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog1_req_occur_shift                (1)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog0_req_occur_shift                (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog2_req_occur_mask                 (0x00000004)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog1_req_occur_mask                 (0x00000002)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog0_req_occur_mask                 (0x00000001)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog2_req_occur(data)                (0x00000004&((data)<<2))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog1_req_occur(data)                (0x00000002&((data)<<1))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_pc_prog0_req_occur(data)                (0x00000001&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_get_pc_prog2_req_occur(data)            ((0x00000004&(data))>>2)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_get_pc_prog1_req_occur(data)            ((0x00000002&(data))>>1)
#define  TVSB3_TV_SB3_DCU1_PC_prog_ctrl2_get_pc_prog0_req_occur(data)            (0x00000001&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel                                 0x1801C568
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_reg_addr                        "0xB801C568"
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_reg                             0xB801C568
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_inst_addr                       "0x0010"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_reg(data)                   (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_reg                         (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_prog_channel_sel_shift          (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_prog_channel_sel_mask           (0x00000003)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_prog_channel_sel(data)          (0x00000003&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_channel_sel_get_prog_channel_sel(data)      (0x00000003&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat                                     0x1801C56C
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_reg_addr                            "0xB801C56C"
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_reg                                 0xB801C56C
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_inst_addr                           "0x0011"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_reg(data)                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_reg                             (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_prog_acc_lat_shift                  (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_prog_acc_lat_mask                   (0xFFFFFFFF)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_prog_acc_lat(data)                  (0xFFFFFFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_acc_lat_get_prog_acc_lat(data)              (0xFFFFFFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat                                     0x1801C570
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_reg_addr                            "0xB801C570"
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_reg                                 0xB801C570
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_inst_addr                           "0x0012"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_reg(data)                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_reg                             (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_prog_max_lat_shift                  (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_prog_max_lat_mask                   (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_prog_max_lat(data)                  (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_max_lat_get_prog_max_lat(data)              (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num                                     0x1801C574
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_reg_addr                            "0xB801C574"
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_reg                                 0xB801C574
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_inst_addr                           "0x0013"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_reg(data)                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_reg                             (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_prog_req_num_shift                  (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_prog_req_num_mask                   (0x00FFFFFF)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_prog_req_num(data)                  (0x00FFFFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_req_num_get_prog_req_num(data)              (0x00FFFFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num                                     0x1801C578
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_reg_addr                            "0xB801C578"
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_reg                                 0xB801C578
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_inst_addr                           "0x0014"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_reg(data)                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_reg                             (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_prog_ack_num_shift                  (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_prog_ack_num_mask                   (0xFFFFFFFF)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_prog_ack_num(data)                  (0xFFFFFFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_ack_num_get_prog_ack_num(data)              (0xFFFFFFFF&(data))

#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend                                      0x1801C57C
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_reg_addr                             "0xB801C57C"
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_reg                                  0xB801C57C
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_inst_addr                            "0x0015"
#define  set_TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_reg(data)                        (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_reg                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_reg))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_prog_hitend_cnt_shift                (0)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_prog_hitend_cnt_mask                 (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_prog_hitend_cnt(data)                (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_PC_prog_0_hitend_get_prog_hitend_cnt(data)            (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_ARB_SR0                                               0x1801C5C8
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_reg_addr                                      "0xB801C5C8"
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_reg                                           0xB801C5C8
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_inst_addr                                     "0x0016"
#define  set_TVSB3_TV_SB3_DCU1_ARB_SR0_reg(data)                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_SR0_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_ARB_SR0_reg                                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_SR0_reg))
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_sb_req_shift                                  (16)
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_sb_gnt_shift                                  (0)
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_sb_req_mask                                   (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_sb_gnt_mask                                   (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_sb_req(data)                                  (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_sb_gnt(data)                                  (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_get_sb_req(data)                              ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_ARB_SR0_get_sb_gnt(data)                              (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_ARB_SR1                                               0x1801C5CC
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_reg_addr                                      "0xB801C5CC"
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_reg                                           0xB801C5CC
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_inst_addr                                     "0x0017"
#define  set_TVSB3_TV_SB3_DCU1_ARB_SR1_reg(data)                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_SR1_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_ARB_SR1_reg                                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_SR1_reg))
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_win_latcnt_shift                              (0)
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_win_latcnt_mask                               (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_win_latcnt(data)                              (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_ARB_SR1_get_win_latcnt(data)                          (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_ARB_SR2                                               0x1801C5D0
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_reg_addr                                      "0xB801C5D0"
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_reg                                           0xB801C5D0
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_inst_addr                                     "0x0018"
#define  set_TVSB3_TV_SB3_DCU1_ARB_SR2_reg(data)                                 (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_SR2_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_ARB_SR2_reg                                       (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_ARB_SR2_reg))
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_low_lvl_ie_shift                              (16)
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_low_lvl_ip_shift                              (0)
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_low_lvl_ie_mask                               (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_low_lvl_ip_mask                               (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_low_lvl_ie(data)                              (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_low_lvl_ip(data)                              (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_get_low_lvl_ie(data)                          ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_ARB_SR2_get_low_lvl_ip(data)                          (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1                                        0x1801C5D4
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_reg_addr                               "0xB801C5D4"
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_reg                                    0xB801C5D4
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_inst_addr                              "0x0019"
#define  set_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_reg(data)                          (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_reg                                (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_reg))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client1_low_latcnt_en_shift            (31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client1_low_latcnt_shift               (16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client0_low_latcnt_en_shift            (15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client0_low_latcnt_shift               (0)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client1_low_latcnt_en_mask             (0x80000000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client1_low_latcnt_mask                (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client0_low_latcnt_en_mask             (0x00008000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client0_low_latcnt_mask                (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client1_low_latcnt_en(data)            (0x80000000&((data)<<31))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client1_low_latcnt(data)               (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client0_low_latcnt_en(data)            (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_client0_low_latcnt(data)               (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_get_client1_low_latcnt_en(data)        ((0x80000000&(data))>>31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_get_client1_low_latcnt(data)           ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_get_client0_low_latcnt_en(data)        ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR1_get_client0_low_latcnt(data)           (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2                                        0x1801C5D8
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_reg_addr                               "0xB801C5D8"
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_reg                                    0xB801C5D8
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_inst_addr                              "0x001A"
#define  set_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_reg(data)                          (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_reg                                (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_reg))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client3_low_latcnt_en_shift            (31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client3_low_latcnt_shift               (16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client2_low_latcnt_en_shift            (15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client2_low_latcnt_shift               (0)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client3_low_latcnt_en_mask             (0x80000000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client3_low_latcnt_mask                (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client2_low_latcnt_en_mask             (0x00008000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client2_low_latcnt_mask                (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client3_low_latcnt_en(data)            (0x80000000&((data)<<31))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client3_low_latcnt(data)               (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client2_low_latcnt_en(data)            (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_client2_low_latcnt(data)               (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_get_client3_low_latcnt_en(data)        ((0x80000000&(data))>>31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_get_client3_low_latcnt(data)           ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_get_client2_low_latcnt_en(data)        ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR2_get_client2_low_latcnt(data)           (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3                                        0x1801C5DC
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_reg_addr                               "0xB801C5DC"
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_reg                                    0xB801C5DC
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_inst_addr                              "0x001B"
#define  set_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_reg(data)                          (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_reg                                (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_reg))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client5_low_latcnt_en_shift            (31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client5_low_latcnt_shift               (16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client4_low_latcnt_en_shift            (15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client4_low_latcnt_shift               (0)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client5_low_latcnt_en_mask             (0x80000000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client5_low_latcnt_mask                (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client4_low_latcnt_en_mask             (0x00008000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client4_low_latcnt_mask                (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client5_low_latcnt_en(data)            (0x80000000&((data)<<31))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client5_low_latcnt(data)               (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client4_low_latcnt_en(data)            (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_client4_low_latcnt(data)               (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_get_client5_low_latcnt_en(data)        ((0x80000000&(data))>>31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_get_client5_low_latcnt(data)           ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_get_client4_low_latcnt_en(data)        ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR3_get_client4_low_latcnt(data)           (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4                                        0x1801C5E0
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_reg_addr                               "0xB801C5E0"
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_reg                                    0xB801C5E0
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_inst_addr                              "0x001C"
#define  set_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_reg(data)                          (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_reg                                (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_reg))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client7_low_latcnt_en_shift            (31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client7_low_latcnt_shift               (16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client6_low_latcnt_en_shift            (15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client6_low_latcnt_shift               (0)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client7_low_latcnt_en_mask             (0x80000000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client7_low_latcnt_mask                (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client6_low_latcnt_en_mask             (0x00008000)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client6_low_latcnt_mask                (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client7_low_latcnt_en(data)            (0x80000000&((data)<<31))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client7_low_latcnt(data)               (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client6_low_latcnt_en(data)            (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_client6_low_latcnt(data)               (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_get_client7_low_latcnt_en(data)        ((0x80000000&(data))>>31)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_get_client7_low_latcnt(data)           ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_get_client6_low_latcnt_en(data)        ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_LOW_LATCNT_CR4_get_client6_low_latcnt(data)           (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_DEBUG                                                 0x1801C5F4
#define  TVSB3_TV_SB3_DCU1_DEBUG_reg_addr                                        "0xB801C5F4"
#define  TVSB3_TV_SB3_DCU1_DEBUG_reg                                             0xB801C5F4
#define  TVSB3_TV_SB3_DCU1_DEBUG_inst_addr                                       "0x001D"
#define  set_TVSB3_TV_SB3_DCU1_DEBUG_reg(data)                                   (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_DEBUG_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_DEBUG_reg                                         (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_DEBUG_reg))
#define  TVSB3_TV_SB3_DCU1_DEBUG_sb_debug_mode_shift                             (0)
#define  TVSB3_TV_SB3_DCU1_DEBUG_sb_debug_mode_mask                              (0x0000000F)
#define  TVSB3_TV_SB3_DCU1_DEBUG_sb_debug_mode(data)                             (0x0000000F&(data))
#define  TVSB3_TV_SB3_DCU1_DEBUG_get_sb_debug_mode(data)                         (0x0000000F&(data))

#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR                                    0x1801C5F8
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_reg_addr                           "0xB801C5F8"
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_reg                                0xB801C5F8
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_inst_addr                          "0x001E"
#define  set_TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_reg(data)                      (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_reg                            (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_reg))
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_keep_cycle_shift             (28)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_level_shift                  (16)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_level_arb_en_shift           (0)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_keep_cycle_mask              (0x70000000)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_level_mask                   (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_level_arb_en_mask            (0x000000FF)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_keep_cycle(data)             (0x70000000&((data)<<28))
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_level(data)                  (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_under_level_arb_en(data)           (0x000000FF&(data))
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_get_under_keep_cycle(data)         ((0x70000000&(data))>>28)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_get_under_level(data)              ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_UNDER_LEVEL_ARB_CR_get_under_level_arb_en(data)       (0x000000FF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_0                                            0x1801C52C
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_reg_addr                                   "0xB801C52C"
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_reg                                        0xB801C52C
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_inst_addr                                  "0x001F"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_0_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_0_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_0_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_0_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_max_req_num_0_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_req_thr_0_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_time_thr_0_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_max_req_num_0_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_req_thr_0_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_time_thr_0_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_max_req_num_0(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_req_thr_0(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_time_thr_0(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_get_max_req_num_0(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_get_req_thr_0(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_0_get_time_thr_0(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_1                                            0x1801C530
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_reg_addr                                   "0xB801C530"
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_reg                                        0xB801C530
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_inst_addr                                  "0x0020"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_1_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_1_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_1_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_1_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_max_req_num_1_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_req_thr_1_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_time_thr_1_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_max_req_num_1_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_req_thr_1_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_time_thr_1_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_max_req_num_1(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_req_thr_1(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_time_thr_1(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_get_max_req_num_1(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_get_req_thr_1(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_1_get_time_thr_1(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_2                                            0x1801C534
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_reg_addr                                   "0xB801C534"
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_reg                                        0xB801C534
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_inst_addr                                  "0x0021"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_2_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_2_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_2_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_2_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_max_req_num_2_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_req_thr_2_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_time_thr_2_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_max_req_num_2_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_req_thr_2_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_time_thr_2_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_max_req_num_2(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_req_thr_2(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_time_thr_2(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_get_max_req_num_2(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_get_req_thr_2(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_2_get_time_thr_2(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_3                                            0x1801C538
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_reg_addr                                   "0xB801C538"
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_reg                                        0xB801C538
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_inst_addr                                  "0x0022"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_3_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_3_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_3_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_3_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_max_req_num_3_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_req_thr_3_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_time_thr_3_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_max_req_num_3_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_req_thr_3_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_time_thr_3_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_max_req_num_3(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_req_thr_3(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_time_thr_3(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_get_max_req_num_3(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_get_req_thr_3(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_3_get_time_thr_3(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_4                                            0x1801C53C
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_reg_addr                                   "0xB801C53C"
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_reg                                        0xB801C53C
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_inst_addr                                  "0x0023"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_4_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_4_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_4_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_4_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_max_req_num_4_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_req_thr_4_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_time_thr_4_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_max_req_num_4_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_req_thr_4_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_time_thr_4_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_max_req_num_4(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_req_thr_4(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_time_thr_4(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_get_max_req_num_4(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_get_req_thr_4(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_4_get_time_thr_4(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_5                                            0x1801C540
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_reg_addr                                   "0xB801C540"
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_reg                                        0xB801C540
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_inst_addr                                  "0x0024"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_5_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_5_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_5_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_5_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_max_req_num_5_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_req_thr_5_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_time_thr_5_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_max_req_num_5_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_req_thr_5_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_time_thr_5_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_max_req_num_5(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_req_thr_5(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_time_thr_5(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_get_max_req_num_5(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_get_req_thr_5(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_5_get_time_thr_5(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_6                                            0x1801C544
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_reg_addr                                   "0xB801C544"
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_reg                                        0xB801C544
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_inst_addr                                  "0x0025"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_6_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_6_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_6_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_6_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_max_req_num_6_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_req_thr_6_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_time_thr_6_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_max_req_num_6_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_req_thr_6_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_time_thr_6_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_max_req_num_6(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_req_thr_6(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_time_thr_6(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_get_max_req_num_6(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_get_req_thr_6(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_6_get_time_thr_6(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_7                                            0x1801C548
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_reg_addr                                   "0xB801C548"
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_reg                                        0xB801C548
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_inst_addr                                  "0x0026"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_7_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_7_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_7_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_7_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_max_req_num_7_shift                        (24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_req_thr_7_shift                            (16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_time_thr_7_shift                           (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_max_req_num_7_mask                         (0xFF000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_req_thr_7_mask                             (0x00FF0000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_time_thr_7_mask                            (0x0000FFFF)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_max_req_num_7(data)                        (0xFF000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_req_thr_7(data)                            (0x00FF0000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_time_thr_7(data)                           (0x0000FFFF&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_get_max_req_num_7(data)                    ((0xFF000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_get_req_thr_7(data)                        ((0x00FF0000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_bw_limit_7_get_time_thr_7(data)                       (0x0000FFFF&(data))

#define  TVSB3_TV_SB3_DCU1_bw_limit_en                                           0x1801C5E8
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_reg_addr                                  "0xB801C5E8"
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_reg                                       0xB801C5E8
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_inst_addr                                 "0x0027"
#define  set_TVSB3_TV_SB3_DCU1_bw_limit_en_reg(data)                             (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_en_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_bw_limit_en_reg                                   (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_bw_limit_en_reg))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_len_scheme_en_shift                       (31)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_7_shift                     (15)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_7_shift                       (14)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_6_shift                     (13)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_6_shift                       (12)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_5_shift                     (11)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_5_shift                       (10)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_4_shift                     (9)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_4_shift                       (8)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_3_shift                     (7)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_3_shift                       (6)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_2_shift                     (5)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_2_shift                       (4)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_1_shift                     (3)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_1_shift                       (2)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_0_shift                     (1)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_0_shift                       (0)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_len_scheme_en_mask                        (0x80000000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_7_mask                      (0x00008000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_7_mask                        (0x00004000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_6_mask                      (0x00002000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_6_mask                        (0x00001000)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_5_mask                      (0x00000800)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_5_mask                        (0x00000400)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_4_mask                      (0x00000200)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_4_mask                        (0x00000100)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_3_mask                      (0x00000080)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_3_mask                        (0x00000040)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_2_mask                      (0x00000020)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_2_mask                        (0x00000010)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_1_mask                      (0x00000008)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_1_mask                        (0x00000004)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_0_mask                      (0x00000002)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_0_mask                        (0x00000001)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_len_scheme_en(data)                       (0x80000000&((data)<<31))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_7(data)                     (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_7(data)                       (0x00004000&((data)<<14))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_6(data)                     (0x00002000&((data)<<13))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_6(data)                       (0x00001000&((data)<<12))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_5(data)                     (0x00000800&((data)<<11))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_5(data)                       (0x00000400&((data)<<10))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_4(data)                     (0x00000200&((data)<<9))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_4(data)                       (0x00000100&((data)<<8))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_3(data)                     (0x00000080&((data)<<7))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_3(data)                       (0x00000040&((data)<<6))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_2(data)                     (0x00000020&((data)<<5))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_2(data)                       (0x00000010&((data)<<4))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_1(data)                     (0x00000008&((data)<<3))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_1(data)                       (0x00000004&((data)<<2))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_status_clr_0(data)                     (0x00000002&((data)<<1))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_bw_limit_en_0(data)                       (0x00000001&(data))
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_len_scheme_en(data)                   ((0x80000000&(data))>>31)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_7(data)                 ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_7(data)                   ((0x00004000&(data))>>14)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_6(data)                 ((0x00002000&(data))>>13)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_6(data)                   ((0x00001000&(data))>>12)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_5(data)                 ((0x00000800&(data))>>11)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_5(data)                   ((0x00000400&(data))>>10)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_4(data)                 ((0x00000200&(data))>>9)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_4(data)                   ((0x00000100&(data))>>8)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_3(data)                 ((0x00000080&(data))>>7)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_3(data)                   ((0x00000040&(data))>>6)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_2(data)                 ((0x00000020&(data))>>5)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_2(data)                   ((0x00000010&(data))>>4)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_1(data)                 ((0x00000008&(data))>>3)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_1(data)                   ((0x00000004&(data))>>2)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_status_clr_0(data)                 ((0x00000002&(data))>>1)
#define  TVSB3_TV_SB3_DCU1_bw_limit_en_get_bw_limit_en_0(data)                   (0x00000001&(data))

#define  TVSB3_TV_SB3_DCU1_queue_ctrl                                            0x1801C5EC
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_reg_addr                                   "0xB801C5EC"
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_reg                                        0xB801C5EC
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_inst_addr                                  "0x0028"
#define  set_TVSB3_TV_SB3_DCU1_queue_ctrl_reg(data)                              (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_queue_ctrl_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_queue_ctrl_reg                                    (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_queue_ctrl_reg))
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_rd_queue_num_shift                         (4)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_dummy_3_shift                              (3)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_wr_queue_num_shift                         (0)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_rd_queue_num_mask                          (0x000001F0)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_dummy_3_mask                               (0x00000008)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_wr_queue_num_mask                          (0x00000007)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_rd_queue_num(data)                         (0x000001F0&((data)<<4))
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_dummy_3(data)                              (0x00000008&((data)<<3))
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_wr_queue_num(data)                         (0x00000007&(data))
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_get_rd_queue_num(data)                     ((0x000001F0&(data))>>4)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_get_dummy_3(data)                          ((0x00000008&(data))>>3)
#define  TVSB3_TV_SB3_DCU1_queue_ctrl_get_wr_queue_num(data)                     (0x00000007&(data))

#define  TVSB3_TV_SB3_DCU1_cti_ctrl                                              0x1801C5A0
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_reg_addr                                     "0xB801C5A0"
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_reg                                          0xB801C5A0
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_inst_addr                                    "0x0029"
#define  set_TVSB3_TV_SB3_DCU1_cti_ctrl_reg(data)                                (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_cti_ctrl_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_cti_ctrl_reg                                      (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_cti_ctrl_reg))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_rd_wr_same_grp_se_shift                  (27)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_space_margin_se_shift                    (24)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_more_than_4_se_shift              (23)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_block_se_shift                    (22)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cmd_err_se_shift                     (21)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_len_err_se_shift                     (20)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_alight_err_se_shift                  (19)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_repeat_err_se_shift                  (18)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_num_err_se_shift                     (17)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cont_err_se_shift                    (16)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_rd_wr_same_grp_shift                     (15)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_space_margin_shift                       (12)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_more_than_4_shift                 (11)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_block_shift                       (10)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cmd_err_shift                        (9)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_len_err_shift                        (8)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_alight_err_shift                     (7)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_repeat_err_shift                     (6)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_num_err_shift                        (5)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cont_err_shift                       (4)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_grp_wr_disable_shift                         (3)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_status_clr_shift                         (2)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_queue_flush_shift                            (1)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_grp_disable_shift                            (0)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_rd_wr_same_grp_se_mask                   (0x08000000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_space_margin_se_mask                     (0x07000000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_more_than_4_se_mask               (0x00800000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_block_se_mask                     (0x00400000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cmd_err_se_mask                      (0x00200000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_len_err_se_mask                      (0x00100000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_alight_err_se_mask                   (0x00080000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_repeat_err_se_mask                   (0x00040000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_num_err_se_mask                      (0x00020000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cont_err_se_mask                     (0x00010000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_rd_wr_same_grp_mask                      (0x00008000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_space_margin_mask                        (0x00007000)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_more_than_4_mask                  (0x00000800)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_block_mask                        (0x00000400)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cmd_err_mask                         (0x00000200)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_len_err_mask                         (0x00000100)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_alight_err_mask                      (0x00000080)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_repeat_err_mask                      (0x00000040)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_num_err_mask                         (0x00000020)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cont_err_mask                        (0x00000010)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_grp_wr_disable_mask                          (0x00000008)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_status_clr_mask                          (0x00000004)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_queue_flush_mask                             (0x00000002)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_grp_disable_mask                             (0x00000001)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_rd_wr_same_grp_se(data)                  (0x08000000&((data)<<27))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_space_margin_se(data)                    (0x07000000&((data)<<24))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_more_than_4_se(data)              (0x00800000&((data)<<23))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_block_se(data)                    (0x00400000&((data)<<22))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cmd_err_se(data)                     (0x00200000&((data)<<21))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_len_err_se(data)                     (0x00100000&((data)<<20))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_alight_err_se(data)                  (0x00080000&((data)<<19))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_repeat_err_se(data)                  (0x00040000&((data)<<18))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_num_err_se(data)                     (0x00020000&((data)<<17))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cont_err_se(data)                    (0x00010000&((data)<<16))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_rd_wr_same_grp(data)                     (0x00008000&((data)<<15))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_space_margin(data)                       (0x00007000&((data)<<12))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_more_than_4(data)                 (0x00000800&((data)<<11))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_wr_grp_block(data)                       (0x00000400&((data)<<10))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cmd_err(data)                        (0x00000200&((data)<<9))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_len_err(data)                        (0x00000100&((data)<<8))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_alight_err(data)                     (0x00000080&((data)<<7))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_repeat_err(data)                     (0x00000040&((data)<<6))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_num_err(data)                        (0x00000020&((data)<<5))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_grp_cont_err(data)                       (0x00000010&((data)<<4))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_grp_wr_disable(data)                         (0x00000008&((data)<<3))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_cti_status_clr(data)                         (0x00000004&((data)<<2))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_queue_flush(data)                            (0x00000002&((data)<<1))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_grp_disable(data)                            (0x00000001&(data))
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_rd_wr_same_grp_se(data)              ((0x08000000&(data))>>27)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_space_margin_se(data)                ((0x07000000&(data))>>24)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_wr_grp_more_than_4_se(data)          ((0x00800000&(data))>>23)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_wr_grp_block_se(data)                ((0x00400000&(data))>>22)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_cmd_err_se(data)                 ((0x00200000&(data))>>21)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_len_err_se(data)                 ((0x00100000&(data))>>20)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_alight_err_se(data)              ((0x00080000&(data))>>19)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_repeat_err_se(data)              ((0x00040000&(data))>>18)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_num_err_se(data)                 ((0x00020000&(data))>>17)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_cont_err_se(data)                ((0x00010000&(data))>>16)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_rd_wr_same_grp(data)                 ((0x00008000&(data))>>15)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_space_margin(data)                   ((0x00007000&(data))>>12)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_wr_grp_more_than_4(data)             ((0x00000800&(data))>>11)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_wr_grp_block(data)                   ((0x00000400&(data))>>10)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_cmd_err(data)                    ((0x00000200&(data))>>9)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_len_err(data)                    ((0x00000100&(data))>>8)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_alight_err(data)                 ((0x00000080&(data))>>7)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_repeat_err(data)                 ((0x00000040&(data))>>6)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_num_err(data)                    ((0x00000020&(data))>>5)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_grp_cont_err(data)                   ((0x00000010&(data))>>4)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_grp_wr_disable(data)                     ((0x00000008&(data))>>3)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_cti_status_clr(data)                     ((0x00000004&(data))>>2)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_queue_flush(data)                        ((0x00000002&(data))>>1)
#define  TVSB3_TV_SB3_DCU1_cti_ctrl_get_grp_disable(data)                        (0x00000001&(data))

#define  TVSB3_TV_SB3_DCU1_error_status                                          0x1801C5FC
#define  TVSB3_TV_SB3_DCU1_error_status_reg_addr                                 "0xB801C5FC"
#define  TVSB3_TV_SB3_DCU1_error_status_reg                                      0xB801C5FC
#define  TVSB3_TV_SB3_DCU1_error_status_inst_addr                                "0x002A"
#define  set_TVSB3_TV_SB3_DCU1_error_status_reg(data)                            (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_error_status_reg)=data)
#define  get_TVSB3_TV_SB3_DCU1_error_status_reg                                  (*((volatile unsigned int*)TVSB3_TV_SB3_DCU1_error_status_reg))
#define  TVSB3_TV_SB3_DCU1_error_status_error_clr_shift                          (31)
#define  TVSB3_TV_SB3_DCU1_error_status_error_zero_length_id_shift               (12)
#define  TVSB3_TV_SB3_DCU1_error_status_error_wdone_full_shift                   (10)
#define  TVSB3_TV_SB3_DCU1_error_status_error_read_full_shift                    (9)
#define  TVSB3_TV_SB3_DCU1_error_status_error_write_full_shift                   (8)
#define  TVSB3_TV_SB3_DCU1_error_status_error_req_id_shift                       (0)
#define  TVSB3_TV_SB3_DCU1_error_status_error_clr_mask                           (0x80000000)
#define  TVSB3_TV_SB3_DCU1_error_status_error_zero_length_id_mask                (0x0000F000)
#define  TVSB3_TV_SB3_DCU1_error_status_error_wdone_full_mask                    (0x00000400)
#define  TVSB3_TV_SB3_DCU1_error_status_error_read_full_mask                     (0x00000200)
#define  TVSB3_TV_SB3_DCU1_error_status_error_write_full_mask                    (0x00000100)
#define  TVSB3_TV_SB3_DCU1_error_status_error_req_id_mask                        (0x0000000F)
#define  TVSB3_TV_SB3_DCU1_error_status_error_clr(data)                          (0x80000000&((data)<<31))
#define  TVSB3_TV_SB3_DCU1_error_status_error_zero_length_id(data)               (0x0000F000&((data)<<12))
#define  TVSB3_TV_SB3_DCU1_error_status_error_wdone_full(data)                   (0x00000400&((data)<<10))
#define  TVSB3_TV_SB3_DCU1_error_status_error_read_full(data)                    (0x00000200&((data)<<9))
#define  TVSB3_TV_SB3_DCU1_error_status_error_write_full(data)                   (0x00000100&((data)<<8))
#define  TVSB3_TV_SB3_DCU1_error_status_error_req_id(data)                       (0x0000000F&(data))
#define  TVSB3_TV_SB3_DCU1_error_status_get_error_clr(data)                      ((0x80000000&(data))>>31)
#define  TVSB3_TV_SB3_DCU1_error_status_get_error_zero_length_id(data)           ((0x0000F000&(data))>>12)
#define  TVSB3_TV_SB3_DCU1_error_status_get_error_wdone_full(data)               ((0x00000400&(data))>>10)
#define  TVSB3_TV_SB3_DCU1_error_status_get_error_read_full(data)                ((0x00000200&(data))>>9)
#define  TVSB3_TV_SB3_DCU1_error_status_get_error_write_full(data)               ((0x00000100&(data))>>8)
#define  TVSB3_TV_SB3_DCU1_error_status_get_error_req_id(data)                   (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TVSB3 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1801c500_31_4:28;
        RBus_UInt32  time_step:4;
    };
}tvsb3_tv_sb3_dcu1_arb_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt_src_sel:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  arb_en:8;
    };
}tvsb3_tv_sb3_dcu1_arb_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client0_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client0_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client1_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client1_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client2_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client2_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client3_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client3_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client4_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client4_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client5_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client5_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client6_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client6_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  client7_latcnt_end:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  client7_latcnt_beg:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  pc_go:1;
    };
}tvsb3_tv_sb3_dcu1_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  pc_prog2_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_prog1_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_prog0_sel:7;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pc_prog2_req_occur:1;
        RBus_UInt32  pc_prog1_req_occur:1;
        RBus_UInt32  pc_prog0_req_occur:1;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  prog_channel_sel:2;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_channel_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_acc_lat:32;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  prog_max_lat:16;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  prog_req_num:24;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_ack_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  prog_hitend_cnt:16;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_hitend_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sb_req:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sb_gnt:8;
    };
}tvsb3_tv_sb3_dcu1_arb_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  win_latcnt:8;
    };
}tvsb3_tv_sb3_dcu1_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  low_lvl_ie:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  low_lvl_ip:8;
    };
}tvsb3_tv_sb3_dcu1_arb_sr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client1_low_latcnt_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  client1_low_latcnt:8;
        RBus_UInt32  client0_low_latcnt_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  client0_low_latcnt:8;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client3_low_latcnt_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  client3_low_latcnt:8;
        RBus_UInt32  client2_low_latcnt_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  client2_low_latcnt:8;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client5_low_latcnt_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  client5_low_latcnt:8;
        RBus_UInt32  client4_low_latcnt_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  client4_low_latcnt:8;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client7_low_latcnt_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  client7_low_latcnt:8;
        RBus_UInt32  client6_low_latcnt_en:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  client6_low_latcnt:8;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  sb_debug_mode:4;
    };
}tvsb3_tv_sb3_dcu1_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  under_keep_cycle:3;
        RBus_UInt32  res2:4;
        RBus_UInt32  under_level:8;
        RBus_UInt32  res3:8;
        RBus_UInt32  under_level_arb_en:8;
    };
}tvsb3_tv_sb3_dcu1_under_level_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_0:8;
        RBus_UInt32  req_thr_0:8;
        RBus_UInt32  time_thr_0:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_1:8;
        RBus_UInt32  req_thr_1:8;
        RBus_UInt32  time_thr_1:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_2:8;
        RBus_UInt32  req_thr_2:8;
        RBus_UInt32  time_thr_2:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_3:8;
        RBus_UInt32  req_thr_3:8;
        RBus_UInt32  time_thr_3:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_4:8;
        RBus_UInt32  req_thr_4:8;
        RBus_UInt32  time_thr_4:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_5:8;
        RBus_UInt32  req_thr_5:8;
        RBus_UInt32  time_thr_5:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_6:8;
        RBus_UInt32  req_thr_6:8;
        RBus_UInt32  time_thr_6:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_req_num_7:8;
        RBus_UInt32  req_thr_7:8;
        RBus_UInt32  time_thr_7:16;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  len_scheme_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  bw_status_clr_7:1;
        RBus_UInt32  bw_limit_en_7:1;
        RBus_UInt32  bw_status_clr_6:1;
        RBus_UInt32  bw_limit_en_6:1;
        RBus_UInt32  bw_status_clr_5:1;
        RBus_UInt32  bw_limit_en_5:1;
        RBus_UInt32  bw_status_clr_4:1;
        RBus_UInt32  bw_limit_en_4:1;
        RBus_UInt32  bw_status_clr_3:1;
        RBus_UInt32  bw_limit_en_3:1;
        RBus_UInt32  bw_status_clr_2:1;
        RBus_UInt32  bw_limit_en_2:1;
        RBus_UInt32  bw_status_clr_1:1;
        RBus_UInt32  bw_limit_en_1:1;
        RBus_UInt32  bw_status_clr_0:1;
        RBus_UInt32  bw_limit_en_0:1;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  rd_queue_num:5;
        RBus_UInt32  dummy1801c5ec_3:1;
        RBus_UInt32  wr_queue_num:3;
    };
}tvsb3_tv_sb3_dcu1_queue_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cti_rd_wr_same_grp_se:1;
        RBus_UInt32  cti_space_margin_se:3;
        RBus_UInt32  cti_wr_grp_more_than_4_se:1;
        RBus_UInt32  cti_wr_grp_block_se:1;
        RBus_UInt32  cti_grp_cmd_err_se:1;
        RBus_UInt32  cti_grp_len_err_se:1;
        RBus_UInt32  cti_grp_alight_err_se:1;
        RBus_UInt32  cti_grp_repeat_err_se:1;
        RBus_UInt32  cti_grp_num_err_se:1;
        RBus_UInt32  cti_grp_cont_err_se:1;
        RBus_UInt32  cti_rd_wr_same_grp:1;
        RBus_UInt32  cti_space_margin:3;
        RBus_UInt32  cti_wr_grp_more_than_4:1;
        RBus_UInt32  cti_wr_grp_block:1;
        RBus_UInt32  cti_grp_cmd_err:1;
        RBus_UInt32  cti_grp_len_err:1;
        RBus_UInt32  cti_grp_alight_err:1;
        RBus_UInt32  cti_grp_repeat_err:1;
        RBus_UInt32  cti_grp_num_err:1;
        RBus_UInt32  cti_grp_cont_err:1;
        RBus_UInt32  grp_wr_disable:1;
        RBus_UInt32  cti_status_clr:1;
        RBus_UInt32  queue_flush:1;
        RBus_UInt32  grp_disable:1;
    };
}tvsb3_tv_sb3_dcu1_cti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_clr:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  error_zero_length_id:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  error_wdone_full:1;
        RBus_UInt32  error_read_full:1;
        RBus_UInt32  error_write_full:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  error_req_id:4;
    };
}tvsb3_tv_sb3_dcu1_error_status_RBUS;

#else //apply LITTLE_ENDIAN

//======TVSB3 register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_step:4;
        RBus_UInt32  dummy1801c500_31_4:28;
    };
}tvsb3_tv_sb3_dcu1_arb_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arb_en:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt_src_sel:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_arb_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client0_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client0_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client1_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client1_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client2_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client2_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client3_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client3_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client4_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client4_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client5_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client5_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client6_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client6_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client7_latcnt_beg:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  client7_latcnt_end:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_latcnt_cr8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_go:1;
        RBus_UInt32  res1:31;
    };
}tvsb3_tv_sb3_dcu1_pc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_mon_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_tota_mon_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_ack_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_tota_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_tota_idl_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_tota_idl_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_prog0_sel:7;
        RBus_UInt32  write_en_1:1;
        RBus_UInt32  pc_prog1_sel:7;
        RBus_UInt32  write_en_2:1;
        RBus_UInt32  pc_prog2_sel:7;
        RBus_UInt32  write_en_3:1;
        RBus_UInt32  res1:8;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_prog0_req_occur:1;
        RBus_UInt32  pc_prog1_req_occur:1;
        RBus_UInt32  pc_prog2_req_occur:1;
        RBus_UInt32  res1:29;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_channel_sel:2;
        RBus_UInt32  res1:30;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_channel_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_acc_lat:32;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_acc_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_max_lat:16;
        RBus_UInt32  res1:16;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_max_lat_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_req_num:24;
        RBus_UInt32  res1:8;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_ack_num:32;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_ack_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prog_hitend_cnt:16;
        RBus_UInt32  res1:16;
    };
}tvsb3_tv_sb3_dcu1_pc_prog_0_hitend_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb_gnt:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sb_req:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_arb_sr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  win_latcnt:8;
        RBus_UInt32  res1:24;
    };
}tvsb3_tv_sb3_dcu1_arb_sr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_lvl_ip:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  low_lvl_ie:8;
        RBus_UInt32  res2:8;
    };
}tvsb3_tv_sb3_dcu1_arb_sr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client0_low_latcnt:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  client0_low_latcnt_en:1;
        RBus_UInt32  client1_low_latcnt:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  client1_low_latcnt_en:1;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client2_low_latcnt:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  client2_low_latcnt_en:1;
        RBus_UInt32  client3_low_latcnt:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  client3_low_latcnt_en:1;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client4_low_latcnt:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  client4_low_latcnt_en:1;
        RBus_UInt32  client5_low_latcnt:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  client5_low_latcnt_en:1;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  client6_low_latcnt:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  client6_low_latcnt_en:1;
        RBus_UInt32  client7_low_latcnt:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  client7_low_latcnt_en:1;
    };
}tvsb3_tv_sb3_dcu1_low_latcnt_cr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb_debug_mode:4;
        RBus_UInt32  res1:28;
    };
}tvsb3_tv_sb3_dcu1_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  under_level_arb_en:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  under_level:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  under_keep_cycle:3;
        RBus_UInt32  res3:1;
    };
}tvsb3_tv_sb3_dcu1_under_level_arb_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_0:16;
        RBus_UInt32  req_thr_0:8;
        RBus_UInt32  max_req_num_0:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_1:16;
        RBus_UInt32  req_thr_1:8;
        RBus_UInt32  max_req_num_1:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_2:16;
        RBus_UInt32  req_thr_2:8;
        RBus_UInt32  max_req_num_2:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_3:16;
        RBus_UInt32  req_thr_3:8;
        RBus_UInt32  max_req_num_3:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_4:16;
        RBus_UInt32  req_thr_4:8;
        RBus_UInt32  max_req_num_4:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_5:16;
        RBus_UInt32  req_thr_5:8;
        RBus_UInt32  max_req_num_5:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_6:16;
        RBus_UInt32  req_thr_6:8;
        RBus_UInt32  max_req_num_6:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  time_thr_7:16;
        RBus_UInt32  req_thr_7:8;
        RBus_UInt32  max_req_num_7:8;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_limit_en_0:1;
        RBus_UInt32  bw_status_clr_0:1;
        RBus_UInt32  bw_limit_en_1:1;
        RBus_UInt32  bw_status_clr_1:1;
        RBus_UInt32  bw_limit_en_2:1;
        RBus_UInt32  bw_status_clr_2:1;
        RBus_UInt32  bw_limit_en_3:1;
        RBus_UInt32  bw_status_clr_3:1;
        RBus_UInt32  bw_limit_en_4:1;
        RBus_UInt32  bw_status_clr_4:1;
        RBus_UInt32  bw_limit_en_5:1;
        RBus_UInt32  bw_status_clr_5:1;
        RBus_UInt32  bw_limit_en_6:1;
        RBus_UInt32  bw_status_clr_6:1;
        RBus_UInt32  bw_limit_en_7:1;
        RBus_UInt32  bw_status_clr_7:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  len_scheme_en:1;
    };
}tvsb3_tv_sb3_dcu1_bw_limit_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_queue_num:3;
        RBus_UInt32  dummy1801c5ec_3_3:1;
        RBus_UInt32  rd_queue_num:5;
        RBus_UInt32  res1:23;
    };
}tvsb3_tv_sb3_dcu1_queue_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grp_disable:1;
        RBus_UInt32  queue_flush:1;
        RBus_UInt32  cti_status_clr:1;
        RBus_UInt32  grp_wr_disable:1;
        RBus_UInt32  cti_grp_cont_err:1;
        RBus_UInt32  cti_grp_num_err:1;
        RBus_UInt32  cti_grp_repeat_err:1;
        RBus_UInt32  cti_grp_alight_err:1;
        RBus_UInt32  cti_grp_len_err:1;
        RBus_UInt32  cti_grp_cmd_err:1;
        RBus_UInt32  cti_wr_grp_block:1;
        RBus_UInt32  cti_wr_grp_more_than_4:1;
        RBus_UInt32  cti_space_margin:3;
        RBus_UInt32  cti_rd_wr_same_grp:1;
        RBus_UInt32  cti_grp_cont_err_se:1;
        RBus_UInt32  cti_grp_num_err_se:1;
        RBus_UInt32  cti_grp_repeat_err_se:1;
        RBus_UInt32  cti_grp_alight_err_se:1;
        RBus_UInt32  cti_grp_len_err_se:1;
        RBus_UInt32  cti_grp_cmd_err_se:1;
        RBus_UInt32  cti_wr_grp_block_se:1;
        RBus_UInt32  cti_wr_grp_more_than_4_se:1;
        RBus_UInt32  cti_space_margin_se:3;
        RBus_UInt32  cti_rd_wr_same_grp_se:1;
        RBus_UInt32  res1:4;
    };
}tvsb3_tv_sb3_dcu1_cti_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  error_req_id:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  error_write_full:1;
        RBus_UInt32  error_read_full:1;
        RBus_UInt32  error_wdone_full:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  error_zero_length_id:4;
        RBus_UInt32  res3:15;
        RBus_UInt32  error_clr:1;
    };
}tvsb3_tv_sb3_dcu1_error_status_RBUS;




#endif 


#endif 
