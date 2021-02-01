/**
* @file Mac5_VE_PREDBLK_arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PREDBLK_REG_H_
#define _RBUS_PREDBLK_REG_H_

#include "rbus_types.h"



//  PREDBLK Register Address
#define  PREDBLK_NEIGHBOR                                                        0x1800E800
#define  PREDBLK_NEIGHBOR_reg_addr                                               "0xB800E800"
#define  PREDBLK_NEIGHBOR_reg                                                    0xB800E800
#define  PREDBLK_NEIGHBOR_inst_addr                                              "0x0000"
#define  set_PREDBLK_NEIGHBOR_reg(data)                                          (*((volatile unsigned int*)PREDBLK_NEIGHBOR_reg)=data)
#define  get_PREDBLK_NEIGHBOR_reg                                                (*((volatile unsigned int*)PREDBLK_NEIGHBOR_reg))
#define  PREDBLK_NEIGHBOR_nhmem_flush_shift                                      (24)
#define  PREDBLK_NEIGHBOR_rmem_rst_shift                                         (23)
#define  PREDBLK_NEIGHBOR_deblk_xsfer_mode_shift                                 (22)
#define  PREDBLK_NEIGHBOR_debug_mode_shift                                       (21)
#define  PREDBLK_NEIGHBOR_fmo_shift                                              (20)
#define  PREDBLK_NEIGHBOR_softrst_disable_shift                                  (15)
#define  PREDBLK_NEIGHBOR_new_slice_row_shift                                    (14)
#define  PREDBLK_NEIGHBOR_new_slice_mb_x_shift                                   (5)
#define  PREDBLK_NEIGHBOR_sw_neighbor_enable_shift                               (4)
#define  PREDBLK_NEIGHBOR_mbaddra_available_shift                                (3)
#define  PREDBLK_NEIGHBOR_mbaddrb_available_shift                                (2)
#define  PREDBLK_NEIGHBOR_mbaddrc_available_shift                                (1)
#define  PREDBLK_NEIGHBOR_mbaddrd_available_shift                                (0)
#define  PREDBLK_NEIGHBOR_nhmem_flush_mask                                       (0x01000000)
#define  PREDBLK_NEIGHBOR_rmem_rst_mask                                          (0x00800000)
#define  PREDBLK_NEIGHBOR_deblk_xsfer_mode_mask                                  (0x00400000)
#define  PREDBLK_NEIGHBOR_debug_mode_mask                                        (0x00200000)
#define  PREDBLK_NEIGHBOR_fmo_mask                                               (0x00100000)
#define  PREDBLK_NEIGHBOR_softrst_disable_mask                                   (0x00008000)
#define  PREDBLK_NEIGHBOR_new_slice_row_mask                                     (0x00004000)
#define  PREDBLK_NEIGHBOR_new_slice_mb_x_mask                                    (0x00003FE0)
#define  PREDBLK_NEIGHBOR_sw_neighbor_enable_mask                                (0x00000010)
#define  PREDBLK_NEIGHBOR_mbaddra_available_mask                                 (0x00000008)
#define  PREDBLK_NEIGHBOR_mbaddrb_available_mask                                 (0x00000004)
#define  PREDBLK_NEIGHBOR_mbaddrc_available_mask                                 (0x00000002)
#define  PREDBLK_NEIGHBOR_mbaddrd_available_mask                                 (0x00000001)
#define  PREDBLK_NEIGHBOR_nhmem_flush(data)                                      (0x01000000&((data)<<24))
#define  PREDBLK_NEIGHBOR_rmem_rst(data)                                         (0x00800000&((data)<<23))
#define  PREDBLK_NEIGHBOR_deblk_xsfer_mode(data)                                 (0x00400000&((data)<<22))
#define  PREDBLK_NEIGHBOR_debug_mode(data)                                       (0x00200000&((data)<<21))
#define  PREDBLK_NEIGHBOR_fmo(data)                                              (0x00100000&((data)<<20))
#define  PREDBLK_NEIGHBOR_softrst_disable(data)                                  (0x00008000&((data)<<15))
#define  PREDBLK_NEIGHBOR_new_slice_row(data)                                    (0x00004000&((data)<<14))
#define  PREDBLK_NEIGHBOR_new_slice_mb_x(data)                                   (0x00003FE0&((data)<<5))
#define  PREDBLK_NEIGHBOR_sw_neighbor_enable(data)                               (0x00000010&((data)<<4))
#define  PREDBLK_NEIGHBOR_mbaddra_available(data)                                (0x00000008&((data)<<3))
#define  PREDBLK_NEIGHBOR_mbaddrb_available(data)                                (0x00000004&((data)<<2))
#define  PREDBLK_NEIGHBOR_mbaddrc_available(data)                                (0x00000002&((data)<<1))
#define  PREDBLK_NEIGHBOR_mbaddrd_available(data)                                (0x00000001&(data))
#define  PREDBLK_NEIGHBOR_get_nhmem_flush(data)                                  ((0x01000000&(data))>>24)
#define  PREDBLK_NEIGHBOR_get_rmem_rst(data)                                     ((0x00800000&(data))>>23)
#define  PREDBLK_NEIGHBOR_get_deblk_xsfer_mode(data)                             ((0x00400000&(data))>>22)
#define  PREDBLK_NEIGHBOR_get_debug_mode(data)                                   ((0x00200000&(data))>>21)
#define  PREDBLK_NEIGHBOR_get_fmo(data)                                          ((0x00100000&(data))>>20)
#define  PREDBLK_NEIGHBOR_get_softrst_disable(data)                              ((0x00008000&(data))>>15)
#define  PREDBLK_NEIGHBOR_get_new_slice_row(data)                                ((0x00004000&(data))>>14)
#define  PREDBLK_NEIGHBOR_get_new_slice_mb_x(data)                               ((0x00003FE0&(data))>>5)
#define  PREDBLK_NEIGHBOR_get_sw_neighbor_enable(data)                           ((0x00000010&(data))>>4)
#define  PREDBLK_NEIGHBOR_get_mbaddra_available(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_NEIGHBOR_get_mbaddrb_available(data)                            ((0x00000004&(data))>>2)
#define  PREDBLK_NEIGHBOR_get_mbaddrc_available(data)                            ((0x00000002&(data))>>1)
#define  PREDBLK_NEIGHBOR_get_mbaddrd_available(data)                            (0x00000001&(data))

#define  PREDBLK_VC1INTC1                                                        0x1800E804
#define  PREDBLK_VC1INTC1_reg_addr                                               "0xB800E804"
#define  PREDBLK_VC1INTC1_reg                                                    0xB800E804
#define  PREDBLK_VC1INTC1_inst_addr                                              "0x0001"
#define  set_PREDBLK_VC1INTC1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC1_reg)=data)
#define  get_PREDBLK_VC1INTC1_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC1_reg))
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable_shift                                (17)
#define  PREDBLK_VC1INTC1_condover_shift                                         (15)
#define  PREDBLK_VC1INTC1_rnd_ctrl_ovt_shift                                     (14)
#define  PREDBLK_VC1INTC1_rnd_shift                                              (13)
#define  PREDBLK_VC1INTC1_intcomp_shift                                          (12)
#define  PREDBLK_VC1INTC1_lumscale0_shift                                        (6)
#define  PREDBLK_VC1INTC1_lumshift0_shift                                        (0)
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable_mask                                 (0x00020000)
#define  PREDBLK_VC1INTC1_condover_mask                                          (0x00018000)
#define  PREDBLK_VC1INTC1_rnd_ctrl_ovt_mask                                      (0x00004000)
#define  PREDBLK_VC1INTC1_rnd_mask                                               (0x00002000)
#define  PREDBLK_VC1INTC1_intcomp_mask                                           (0x00001000)
#define  PREDBLK_VC1INTC1_lumscale0_mask                                         (0x00000FC0)
#define  PREDBLK_VC1INTC1_lumshift0_mask                                         (0x0000003F)
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable(data)                                (0x00020000&((data)<<17))
#define  PREDBLK_VC1INTC1_condover(data)                                         (0x00018000&((data)<<15))
#define  PREDBLK_VC1INTC1_rnd_ctrl_ovt(data)                                     (0x00004000&((data)<<14))
#define  PREDBLK_VC1INTC1_rnd(data)                                              (0x00002000&((data)<<13))
#define  PREDBLK_VC1INTC1_intcomp(data)                                          (0x00001000&((data)<<12))
#define  PREDBLK_VC1INTC1_lumscale0(data)                                        (0x00000FC0&((data)<<6))
#define  PREDBLK_VC1INTC1_lumshift0(data)                                        (0x0000003F&(data))
#define  PREDBLK_VC1INTC1_get_ic_mix_fcm_enable(data)                            ((0x00020000&(data))>>17)
#define  PREDBLK_VC1INTC1_get_condover(data)                                     ((0x00018000&(data))>>15)
#define  PREDBLK_VC1INTC1_get_rnd_ctrl_ovt(data)                                 ((0x00004000&(data))>>14)
#define  PREDBLK_VC1INTC1_get_rnd(data)                                          ((0x00002000&(data))>>13)
#define  PREDBLK_VC1INTC1_get_intcomp(data)                                      ((0x00001000&(data))>>12)
#define  PREDBLK_VC1INTC1_get_lumscale0(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC1_get_lumshift0(data)                                    (0x0000003F&(data))

#define  PREDBLK_VC1INTC2                                                        0x1800E808
#define  PREDBLK_VC1INTC2_reg_addr                                               "0xB800E808"
#define  PREDBLK_VC1INTC2_reg                                                    0xB800E808
#define  PREDBLK_VC1INTC2_inst_addr                                              "0x0002"
#define  set_PREDBLK_VC1INTC2_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC2_reg)=data)
#define  get_PREDBLK_VC1INTC2_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC2_reg))
#define  PREDBLK_VC1INTC2_ic_pass0_of_fwd_shift                                  (28)
#define  PREDBLK_VC1INTC2_ic_pass1_of_fwd_shift                                  (24)
#define  PREDBLK_VC1INTC2_ic_pass0_sf_fwd_shift                                  (20)
#define  PREDBLK_VC1INTC2_ic_pass1_sf_fwd_shift                                  (16)
#define  PREDBLK_VC1INTC2_ic_pass0_of_bwd_shift                                  (12)
#define  PREDBLK_VC1INTC2_ic_pass1_of_bwd_shift                                  (8)
#define  PREDBLK_VC1INTC2_ic_pass0_sf_bwd_shift                                  (4)
#define  PREDBLK_VC1INTC2_ic_pass1_sf_bwd_shift                                  (0)
#define  PREDBLK_VC1INTC2_ic_pass0_of_fwd_mask                                   (0xF0000000)
#define  PREDBLK_VC1INTC2_ic_pass1_of_fwd_mask                                   (0x0F000000)
#define  PREDBLK_VC1INTC2_ic_pass0_sf_fwd_mask                                   (0x00F00000)
#define  PREDBLK_VC1INTC2_ic_pass1_sf_fwd_mask                                   (0x000F0000)
#define  PREDBLK_VC1INTC2_ic_pass0_of_bwd_mask                                   (0x0000F000)
#define  PREDBLK_VC1INTC2_ic_pass1_of_bwd_mask                                   (0x00000F00)
#define  PREDBLK_VC1INTC2_ic_pass0_sf_bwd_mask                                   (0x000000F0)
#define  PREDBLK_VC1INTC2_ic_pass1_sf_bwd_mask                                   (0x0000000F)
#define  PREDBLK_VC1INTC2_ic_pass0_of_fwd(data)                                  (0xF0000000&((data)<<28))
#define  PREDBLK_VC1INTC2_ic_pass1_of_fwd(data)                                  (0x0F000000&((data)<<24))
#define  PREDBLK_VC1INTC2_ic_pass0_sf_fwd(data)                                  (0x00F00000&((data)<<20))
#define  PREDBLK_VC1INTC2_ic_pass1_sf_fwd(data)                                  (0x000F0000&((data)<<16))
#define  PREDBLK_VC1INTC2_ic_pass0_of_bwd(data)                                  (0x0000F000&((data)<<12))
#define  PREDBLK_VC1INTC2_ic_pass1_of_bwd(data)                                  (0x00000F00&((data)<<8))
#define  PREDBLK_VC1INTC2_ic_pass0_sf_bwd(data)                                  (0x000000F0&((data)<<4))
#define  PREDBLK_VC1INTC2_ic_pass1_sf_bwd(data)                                  (0x0000000F&(data))
#define  PREDBLK_VC1INTC2_get_ic_pass0_of_fwd(data)                              ((0xF0000000&(data))>>28)
#define  PREDBLK_VC1INTC2_get_ic_pass1_of_fwd(data)                              ((0x0F000000&(data))>>24)
#define  PREDBLK_VC1INTC2_get_ic_pass0_sf_fwd(data)                              ((0x00F00000&(data))>>20)
#define  PREDBLK_VC1INTC2_get_ic_pass1_sf_fwd(data)                              ((0x000F0000&(data))>>16)
#define  PREDBLK_VC1INTC2_get_ic_pass0_of_bwd(data)                              ((0x0000F000&(data))>>12)
#define  PREDBLK_VC1INTC2_get_ic_pass1_of_bwd(data)                              ((0x00000F00&(data))>>8)
#define  PREDBLK_VC1INTC2_get_ic_pass0_sf_bwd(data)                              ((0x000000F0&(data))>>4)
#define  PREDBLK_VC1INTC2_get_ic_pass1_sf_bwd(data)                              (0x0000000F&(data))

#define  PREDBLK_VC1INTC3                                                        0x1800E80C
#define  PREDBLK_VC1INTC3_reg_addr                                               "0xB800E80C"
#define  PREDBLK_VC1INTC3_reg                                                    0xB800E80C
#define  PREDBLK_VC1INTC3_inst_addr                                              "0x0003"
#define  set_PREDBLK_VC1INTC3_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC3_reg)=data)
#define  get_PREDBLK_VC1INTC3_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC3_reg))
#define  PREDBLK_VC1INTC3_lumscale1_shift                                        (18)
#define  PREDBLK_VC1INTC3_lumshift1_shift                                        (12)
#define  PREDBLK_VC1INTC3_lumscale2_shift                                        (6)
#define  PREDBLK_VC1INTC3_lumshift2_shift                                        (0)
#define  PREDBLK_VC1INTC3_lumscale1_mask                                         (0x00FC0000)
#define  PREDBLK_VC1INTC3_lumshift1_mask                                         (0x0003F000)
#define  PREDBLK_VC1INTC3_lumscale2_mask                                         (0x00000FC0)
#define  PREDBLK_VC1INTC3_lumshift2_mask                                         (0x0000003F)
#define  PREDBLK_VC1INTC3_lumscale1(data)                                        (0x00FC0000&((data)<<18))
#define  PREDBLK_VC1INTC3_lumshift1(data)                                        (0x0003F000&((data)<<12))
#define  PREDBLK_VC1INTC3_lumscale2(data)                                        (0x00000FC0&((data)<<6))
#define  PREDBLK_VC1INTC3_lumshift2(data)                                        (0x0000003F&(data))
#define  PREDBLK_VC1INTC3_get_lumscale1(data)                                    ((0x00FC0000&(data))>>18)
#define  PREDBLK_VC1INTC3_get_lumshift1(data)                                    ((0x0003F000&(data))>>12)
#define  PREDBLK_VC1INTC3_get_lumscale2(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC3_get_lumshift2(data)                                    (0x0000003F&(data))

#define  PREDBLK_VC1INTC4                                                        0x1800E810
#define  PREDBLK_VC1INTC4_reg_addr                                               "0xB800E810"
#define  PREDBLK_VC1INTC4_reg                                                    0xB800E810
#define  PREDBLK_VC1INTC4_inst_addr                                              "0x0004"
#define  set_PREDBLK_VC1INTC4_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC4_reg)=data)
#define  get_PREDBLK_VC1INTC4_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC4_reg))
#define  PREDBLK_VC1INTC4_lumscale3_shift                                        (18)
#define  PREDBLK_VC1INTC4_lumshift3_shift                                        (12)
#define  PREDBLK_VC1INTC4_lumscale4_shift                                        (6)
#define  PREDBLK_VC1INTC4_lumshift4_shift                                        (0)
#define  PREDBLK_VC1INTC4_lumscale3_mask                                         (0x00FC0000)
#define  PREDBLK_VC1INTC4_lumshift3_mask                                         (0x0003F000)
#define  PREDBLK_VC1INTC4_lumscale4_mask                                         (0x00000FC0)
#define  PREDBLK_VC1INTC4_lumshift4_mask                                         (0x0000003F)
#define  PREDBLK_VC1INTC4_lumscale3(data)                                        (0x00FC0000&((data)<<18))
#define  PREDBLK_VC1INTC4_lumshift3(data)                                        (0x0003F000&((data)<<12))
#define  PREDBLK_VC1INTC4_lumscale4(data)                                        (0x00000FC0&((data)<<6))
#define  PREDBLK_VC1INTC4_lumshift4(data)                                        (0x0000003F&(data))
#define  PREDBLK_VC1INTC4_get_lumscale3(data)                                    ((0x00FC0000&(data))>>18)
#define  PREDBLK_VC1INTC4_get_lumshift3(data)                                    ((0x0003F000&(data))>>12)
#define  PREDBLK_VC1INTC4_get_lumscale4(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC4_get_lumshift4(data)                                    (0x0000003F&(data))

#define  PREDBLK_NBINTRA0_0                                                      0x1800E814
#define  PREDBLK_NBINTRA0_0_reg_addr                                             "0xB800E814"
#define  PREDBLK_NBINTRA0_0_reg                                                  0xB800E814
#define  PREDBLK_NBINTRA0_0_inst_addr                                            "0x0005"
#define  set_PREDBLK_NBINTRA0_0_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_0_reg)=data)
#define  get_PREDBLK_NBINTRA0_0_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_0_reg))
#define  PREDBLK_NBINTRA0_0_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_0_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_0_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_0_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_1                                                      0x1800E818
#define  PREDBLK_NBINTRA0_1_reg_addr                                             "0xB800E818"
#define  PREDBLK_NBINTRA0_1_reg                                                  0xB800E818
#define  PREDBLK_NBINTRA0_1_inst_addr                                            "0x0006"
#define  set_PREDBLK_NBINTRA0_1_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_1_reg)=data)
#define  get_PREDBLK_NBINTRA0_1_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_1_reg))
#define  PREDBLK_NBINTRA0_1_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_1_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_1_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_1_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_2                                                      0x1800E81C
#define  PREDBLK_NBINTRA0_2_reg_addr                                             "0xB800E81C"
#define  PREDBLK_NBINTRA0_2_reg                                                  0xB800E81C
#define  PREDBLK_NBINTRA0_2_inst_addr                                            "0x0007"
#define  set_PREDBLK_NBINTRA0_2_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_2_reg)=data)
#define  get_PREDBLK_NBINTRA0_2_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_2_reg))
#define  PREDBLK_NBINTRA0_2_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_2_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_2_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_2_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_3                                                      0x1800E820
#define  PREDBLK_NBINTRA0_3_reg_addr                                             "0xB800E820"
#define  PREDBLK_NBINTRA0_3_reg                                                  0xB800E820
#define  PREDBLK_NBINTRA0_3_inst_addr                                            "0x0008"
#define  set_PREDBLK_NBINTRA0_3_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_3_reg)=data)
#define  get_PREDBLK_NBINTRA0_3_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_3_reg))
#define  PREDBLK_NBINTRA0_3_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_3_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_3_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_3_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_4                                                      0x1800E824
#define  PREDBLK_NBINTRA0_4_reg_addr                                             "0xB800E824"
#define  PREDBLK_NBINTRA0_4_reg                                                  0xB800E824
#define  PREDBLK_NBINTRA0_4_inst_addr                                            "0x0009"
#define  set_PREDBLK_NBINTRA0_4_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_4_reg)=data)
#define  get_PREDBLK_NBINTRA0_4_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_4_reg))
#define  PREDBLK_NBINTRA0_4_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_4_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_4_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_4_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_5                                                      0x1800E828
#define  PREDBLK_NBINTRA0_5_reg_addr                                             "0xB800E828"
#define  PREDBLK_NBINTRA0_5_reg                                                  0xB800E828
#define  PREDBLK_NBINTRA0_5_inst_addr                                            "0x000A"
#define  set_PREDBLK_NBINTRA0_5_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_5_reg)=data)
#define  get_PREDBLK_NBINTRA0_5_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_5_reg))
#define  PREDBLK_NBINTRA0_5_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_5_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_5_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_5_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_6                                                      0x1800E82C
#define  PREDBLK_NBINTRA0_6_reg_addr                                             "0xB800E82C"
#define  PREDBLK_NBINTRA0_6_reg                                                  0xB800E82C
#define  PREDBLK_NBINTRA0_6_inst_addr                                            "0x000B"
#define  set_PREDBLK_NBINTRA0_6_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_6_reg)=data)
#define  get_PREDBLK_NBINTRA0_6_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_6_reg))
#define  PREDBLK_NBINTRA0_6_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_6_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_6_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_6_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_7                                                      0x1800E830
#define  PREDBLK_NBINTRA0_7_reg_addr                                             "0xB800E830"
#define  PREDBLK_NBINTRA0_7_reg                                                  0xB800E830
#define  PREDBLK_NBINTRA0_7_inst_addr                                            "0x000C"
#define  set_PREDBLK_NBINTRA0_7_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_7_reg)=data)
#define  get_PREDBLK_NBINTRA0_7_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_7_reg))
#define  PREDBLK_NBINTRA0_7_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_7_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_7_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_7_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_8                                                      0x1800E834
#define  PREDBLK_NBINTRA0_8_reg_addr                                             "0xB800E834"
#define  PREDBLK_NBINTRA0_8_reg                                                  0xB800E834
#define  PREDBLK_NBINTRA0_8_inst_addr                                            "0x000D"
#define  set_PREDBLK_NBINTRA0_8_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_8_reg)=data)
#define  get_PREDBLK_NBINTRA0_8_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_8_reg))
#define  PREDBLK_NBINTRA0_8_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_8_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_8_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_8_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_9                                                      0x1800E838
#define  PREDBLK_NBINTRA0_9_reg_addr                                             "0xB800E838"
#define  PREDBLK_NBINTRA0_9_reg                                                  0xB800E838
#define  PREDBLK_NBINTRA0_9_inst_addr                                            "0x000E"
#define  set_PREDBLK_NBINTRA0_9_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_9_reg)=data)
#define  get_PREDBLK_NBINTRA0_9_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_9_reg))
#define  PREDBLK_NBINTRA0_9_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA0_9_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_9_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_9_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_10                                                     0x1800E83C
#define  PREDBLK_NBINTRA0_10_reg_addr                                            "0xB800E83C"
#define  PREDBLK_NBINTRA0_10_reg                                                 0xB800E83C
#define  PREDBLK_NBINTRA0_10_inst_addr                                           "0x000F"
#define  set_PREDBLK_NBINTRA0_10_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_10_reg)=data)
#define  get_PREDBLK_NBINTRA0_10_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_10_reg))
#define  PREDBLK_NBINTRA0_10_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA0_10_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_10_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_10_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_11                                                     0x1800E840
#define  PREDBLK_NBINTRA0_11_reg_addr                                            "0xB800E840"
#define  PREDBLK_NBINTRA0_11_reg                                                 0xB800E840
#define  PREDBLK_NBINTRA0_11_inst_addr                                           "0x0010"
#define  set_PREDBLK_NBINTRA0_11_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_11_reg)=data)
#define  get_PREDBLK_NBINTRA0_11_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_11_reg))
#define  PREDBLK_NBINTRA0_11_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA0_11_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_11_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_11_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_12                                                     0x1800E844
#define  PREDBLK_NBINTRA0_12_reg_addr                                            "0xB800E844"
#define  PREDBLK_NBINTRA0_12_reg                                                 0xB800E844
#define  PREDBLK_NBINTRA0_12_inst_addr                                           "0x0011"
#define  set_PREDBLK_NBINTRA0_12_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_12_reg)=data)
#define  get_PREDBLK_NBINTRA0_12_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_12_reg))
#define  PREDBLK_NBINTRA0_12_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA0_12_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_12_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_12_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_13                                                     0x1800E848
#define  PREDBLK_NBINTRA0_13_reg_addr                                            "0xB800E848"
#define  PREDBLK_NBINTRA0_13_reg                                                 0xB800E848
#define  PREDBLK_NBINTRA0_13_inst_addr                                           "0x0012"
#define  set_PREDBLK_NBINTRA0_13_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_13_reg)=data)
#define  get_PREDBLK_NBINTRA0_13_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_13_reg))
#define  PREDBLK_NBINTRA0_13_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA0_13_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_13_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_13_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_14                                                     0x1800E84C
#define  PREDBLK_NBINTRA0_14_reg_addr                                            "0xB800E84C"
#define  PREDBLK_NBINTRA0_14_reg                                                 0xB800E84C
#define  PREDBLK_NBINTRA0_14_inst_addr                                           "0x0013"
#define  set_PREDBLK_NBINTRA0_14_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_14_reg)=data)
#define  get_PREDBLK_NBINTRA0_14_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_14_reg))
#define  PREDBLK_NBINTRA0_14_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA0_14_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_14_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_14_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_15                                                     0x1800E850
#define  PREDBLK_NBINTRA0_15_reg_addr                                            "0xB800E850"
#define  PREDBLK_NBINTRA0_15_reg                                                 0xB800E850
#define  PREDBLK_NBINTRA0_15_inst_addr                                           "0x0014"
#define  set_PREDBLK_NBINTRA0_15_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_15_reg)=data)
#define  get_PREDBLK_NBINTRA0_15_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_15_reg))
#define  PREDBLK_NBINTRA0_15_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA0_15_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_15_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_15_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_0                                                      0x1800E854
#define  PREDBLK_NBINTRA1_0_reg_addr                                             "0xB800E854"
#define  PREDBLK_NBINTRA1_0_reg                                                  0xB800E854
#define  PREDBLK_NBINTRA1_0_inst_addr                                            "0x0015"
#define  set_PREDBLK_NBINTRA1_0_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_0_reg)=data)
#define  get_PREDBLK_NBINTRA1_0_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_0_reg))
#define  PREDBLK_NBINTRA1_0_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_0_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_0_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_0_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_1                                                      0x1800E858
#define  PREDBLK_NBINTRA1_1_reg_addr                                             "0xB800E858"
#define  PREDBLK_NBINTRA1_1_reg                                                  0xB800E858
#define  PREDBLK_NBINTRA1_1_inst_addr                                            "0x0016"
#define  set_PREDBLK_NBINTRA1_1_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_1_reg)=data)
#define  get_PREDBLK_NBINTRA1_1_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_1_reg))
#define  PREDBLK_NBINTRA1_1_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_1_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_1_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_1_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_2                                                      0x1800E85C
#define  PREDBLK_NBINTRA1_2_reg_addr                                             "0xB800E85C"
#define  PREDBLK_NBINTRA1_2_reg                                                  0xB800E85C
#define  PREDBLK_NBINTRA1_2_inst_addr                                            "0x0017"
#define  set_PREDBLK_NBINTRA1_2_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_2_reg)=data)
#define  get_PREDBLK_NBINTRA1_2_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_2_reg))
#define  PREDBLK_NBINTRA1_2_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_2_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_2_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_2_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_3                                                      0x1800E860
#define  PREDBLK_NBINTRA1_3_reg_addr                                             "0xB800E860"
#define  PREDBLK_NBINTRA1_3_reg                                                  0xB800E860
#define  PREDBLK_NBINTRA1_3_inst_addr                                            "0x0018"
#define  set_PREDBLK_NBINTRA1_3_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_3_reg)=data)
#define  get_PREDBLK_NBINTRA1_3_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_3_reg))
#define  PREDBLK_NBINTRA1_3_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_3_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_3_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_3_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_4                                                      0x1800E864
#define  PREDBLK_NBINTRA1_4_reg_addr                                             "0xB800E864"
#define  PREDBLK_NBINTRA1_4_reg                                                  0xB800E864
#define  PREDBLK_NBINTRA1_4_inst_addr                                            "0x0019"
#define  set_PREDBLK_NBINTRA1_4_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_4_reg)=data)
#define  get_PREDBLK_NBINTRA1_4_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_4_reg))
#define  PREDBLK_NBINTRA1_4_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_4_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_4_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_4_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_5                                                      0x1800E868
#define  PREDBLK_NBINTRA1_5_reg_addr                                             "0xB800E868"
#define  PREDBLK_NBINTRA1_5_reg                                                  0xB800E868
#define  PREDBLK_NBINTRA1_5_inst_addr                                            "0x001A"
#define  set_PREDBLK_NBINTRA1_5_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_5_reg)=data)
#define  get_PREDBLK_NBINTRA1_5_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_5_reg))
#define  PREDBLK_NBINTRA1_5_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_5_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_5_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_5_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_6                                                      0x1800E86C
#define  PREDBLK_NBINTRA1_6_reg_addr                                             "0xB800E86C"
#define  PREDBLK_NBINTRA1_6_reg                                                  0xB800E86C
#define  PREDBLK_NBINTRA1_6_inst_addr                                            "0x001B"
#define  set_PREDBLK_NBINTRA1_6_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_6_reg)=data)
#define  get_PREDBLK_NBINTRA1_6_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_6_reg))
#define  PREDBLK_NBINTRA1_6_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_6_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_6_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_6_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_7                                                      0x1800E870
#define  PREDBLK_NBINTRA1_7_reg_addr                                             "0xB800E870"
#define  PREDBLK_NBINTRA1_7_reg                                                  0xB800E870
#define  PREDBLK_NBINTRA1_7_inst_addr                                            "0x001C"
#define  set_PREDBLK_NBINTRA1_7_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_7_reg)=data)
#define  get_PREDBLK_NBINTRA1_7_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_7_reg))
#define  PREDBLK_NBINTRA1_7_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_7_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_7_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_7_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_8                                                      0x1800E874
#define  PREDBLK_NBINTRA1_8_reg_addr                                             "0xB800E874"
#define  PREDBLK_NBINTRA1_8_reg                                                  0xB800E874
#define  PREDBLK_NBINTRA1_8_inst_addr                                            "0x001D"
#define  set_PREDBLK_NBINTRA1_8_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_8_reg)=data)
#define  get_PREDBLK_NBINTRA1_8_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_8_reg))
#define  PREDBLK_NBINTRA1_8_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_8_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_8_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_8_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_9                                                      0x1800E878
#define  PREDBLK_NBINTRA1_9_reg_addr                                             "0xB800E878"
#define  PREDBLK_NBINTRA1_9_reg                                                  0xB800E878
#define  PREDBLK_NBINTRA1_9_inst_addr                                            "0x001E"
#define  set_PREDBLK_NBINTRA1_9_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_9_reg)=data)
#define  get_PREDBLK_NBINTRA1_9_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_9_reg))
#define  PREDBLK_NBINTRA1_9_intra_flag_shift                                     (0)
#define  PREDBLK_NBINTRA1_9_intra_flag_mask                                      (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_9_intra_flag(data)                                     (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_9_get_intra_flag(data)                                 (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_10                                                     0x1800E87C
#define  PREDBLK_NBINTRA1_10_reg_addr                                            "0xB800E87C"
#define  PREDBLK_NBINTRA1_10_reg                                                 0xB800E87C
#define  PREDBLK_NBINTRA1_10_inst_addr                                           "0x001F"
#define  set_PREDBLK_NBINTRA1_10_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_10_reg)=data)
#define  get_PREDBLK_NBINTRA1_10_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_10_reg))
#define  PREDBLK_NBINTRA1_10_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA1_10_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_10_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_10_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_11                                                     0x1800E880
#define  PREDBLK_NBINTRA1_11_reg_addr                                            "0xB800E880"
#define  PREDBLK_NBINTRA1_11_reg                                                 0xB800E880
#define  PREDBLK_NBINTRA1_11_inst_addr                                           "0x0020"
#define  set_PREDBLK_NBINTRA1_11_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_11_reg)=data)
#define  get_PREDBLK_NBINTRA1_11_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_11_reg))
#define  PREDBLK_NBINTRA1_11_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA1_11_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_11_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_11_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_12                                                     0x1800E884
#define  PREDBLK_NBINTRA1_12_reg_addr                                            "0xB800E884"
#define  PREDBLK_NBINTRA1_12_reg                                                 0xB800E884
#define  PREDBLK_NBINTRA1_12_inst_addr                                           "0x0021"
#define  set_PREDBLK_NBINTRA1_12_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_12_reg)=data)
#define  get_PREDBLK_NBINTRA1_12_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_12_reg))
#define  PREDBLK_NBINTRA1_12_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA1_12_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_12_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_12_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_13                                                     0x1800E888
#define  PREDBLK_NBINTRA1_13_reg_addr                                            "0xB800E888"
#define  PREDBLK_NBINTRA1_13_reg                                                 0xB800E888
#define  PREDBLK_NBINTRA1_13_inst_addr                                           "0x0022"
#define  set_PREDBLK_NBINTRA1_13_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_13_reg)=data)
#define  get_PREDBLK_NBINTRA1_13_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_13_reg))
#define  PREDBLK_NBINTRA1_13_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA1_13_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_13_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_13_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_14                                                     0x1800E88C
#define  PREDBLK_NBINTRA1_14_reg_addr                                            "0xB800E88C"
#define  PREDBLK_NBINTRA1_14_reg                                                 0xB800E88C
#define  PREDBLK_NBINTRA1_14_inst_addr                                           "0x0023"
#define  set_PREDBLK_NBINTRA1_14_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_14_reg)=data)
#define  get_PREDBLK_NBINTRA1_14_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_14_reg))
#define  PREDBLK_NBINTRA1_14_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA1_14_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_14_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_14_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_15                                                     0x1800E890
#define  PREDBLK_NBINTRA1_15_reg_addr                                            "0xB800E890"
#define  PREDBLK_NBINTRA1_15_reg                                                 0xB800E890
#define  PREDBLK_NBINTRA1_15_inst_addr                                           "0x0024"
#define  set_PREDBLK_NBINTRA1_15_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_15_reg)=data)
#define  get_PREDBLK_NBINTRA1_15_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_15_reg))
#define  PREDBLK_NBINTRA1_15_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRA1_15_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_15_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_15_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_0                                                     0x1800E894
#define  PREDBLK_NBINTRACH_0_reg_addr                                            "0xB800E894"
#define  PREDBLK_NBINTRACH_0_reg                                                 0xB800E894
#define  PREDBLK_NBINTRACH_0_inst_addr                                           "0x0025"
#define  set_PREDBLK_NBINTRACH_0_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_0_reg)=data)
#define  get_PREDBLK_NBINTRACH_0_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_0_reg))
#define  PREDBLK_NBINTRACH_0_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_0_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_0_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_0_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_1                                                     0x1800E898
#define  PREDBLK_NBINTRACH_1_reg_addr                                            "0xB800E898"
#define  PREDBLK_NBINTRACH_1_reg                                                 0xB800E898
#define  PREDBLK_NBINTRACH_1_inst_addr                                           "0x0026"
#define  set_PREDBLK_NBINTRACH_1_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_1_reg)=data)
#define  get_PREDBLK_NBINTRACH_1_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_1_reg))
#define  PREDBLK_NBINTRACH_1_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_1_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_1_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_1_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_2                                                     0x1800E89C
#define  PREDBLK_NBINTRACH_2_reg_addr                                            "0xB800E89C"
#define  PREDBLK_NBINTRACH_2_reg                                                 0xB800E89C
#define  PREDBLK_NBINTRACH_2_inst_addr                                           "0x0027"
#define  set_PREDBLK_NBINTRACH_2_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_2_reg)=data)
#define  get_PREDBLK_NBINTRACH_2_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_2_reg))
#define  PREDBLK_NBINTRACH_2_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_2_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_2_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_2_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_3                                                     0x1800E8A0
#define  PREDBLK_NBINTRACH_3_reg_addr                                            "0xB800E8A0"
#define  PREDBLK_NBINTRACH_3_reg                                                 0xB800E8A0
#define  PREDBLK_NBINTRACH_3_inst_addr                                           "0x0028"
#define  set_PREDBLK_NBINTRACH_3_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_3_reg)=data)
#define  get_PREDBLK_NBINTRACH_3_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_3_reg))
#define  PREDBLK_NBINTRACH_3_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_3_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_3_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_3_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_4                                                     0x1800E8A4
#define  PREDBLK_NBINTRACH_4_reg_addr                                            "0xB800E8A4"
#define  PREDBLK_NBINTRACH_4_reg                                                 0xB800E8A4
#define  PREDBLK_NBINTRACH_4_inst_addr                                           "0x0029"
#define  set_PREDBLK_NBINTRACH_4_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_4_reg)=data)
#define  get_PREDBLK_NBINTRACH_4_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_4_reg))
#define  PREDBLK_NBINTRACH_4_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_4_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_4_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_4_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_5                                                     0x1800E8A8
#define  PREDBLK_NBINTRACH_5_reg_addr                                            "0xB800E8A8"
#define  PREDBLK_NBINTRACH_5_reg                                                 0xB800E8A8
#define  PREDBLK_NBINTRACH_5_inst_addr                                           "0x002A"
#define  set_PREDBLK_NBINTRACH_5_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_5_reg)=data)
#define  get_PREDBLK_NBINTRACH_5_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_5_reg))
#define  PREDBLK_NBINTRACH_5_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_5_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_5_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_5_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_6                                                     0x1800E8AC
#define  PREDBLK_NBINTRACH_6_reg_addr                                            "0xB800E8AC"
#define  PREDBLK_NBINTRACH_6_reg                                                 0xB800E8AC
#define  PREDBLK_NBINTRACH_6_inst_addr                                           "0x002B"
#define  set_PREDBLK_NBINTRACH_6_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_6_reg)=data)
#define  get_PREDBLK_NBINTRACH_6_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_6_reg))
#define  PREDBLK_NBINTRACH_6_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_6_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_6_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_6_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_7                                                     0x1800E8B0
#define  PREDBLK_NBINTRACH_7_reg_addr                                            "0xB800E8B0"
#define  PREDBLK_NBINTRACH_7_reg                                                 0xB800E8B0
#define  PREDBLK_NBINTRACH_7_inst_addr                                           "0x002C"
#define  set_PREDBLK_NBINTRACH_7_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_7_reg)=data)
#define  get_PREDBLK_NBINTRACH_7_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_7_reg))
#define  PREDBLK_NBINTRACH_7_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_7_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_7_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_7_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_8                                                     0x1800E8B4
#define  PREDBLK_NBINTRACH_8_reg_addr                                            "0xB800E8B4"
#define  PREDBLK_NBINTRACH_8_reg                                                 0xB800E8B4
#define  PREDBLK_NBINTRACH_8_inst_addr                                           "0x002D"
#define  set_PREDBLK_NBINTRACH_8_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_8_reg)=data)
#define  get_PREDBLK_NBINTRACH_8_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_8_reg))
#define  PREDBLK_NBINTRACH_8_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_8_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_8_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_8_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_9                                                     0x1800E8B8
#define  PREDBLK_NBINTRACH_9_reg_addr                                            "0xB800E8B8"
#define  PREDBLK_NBINTRACH_9_reg                                                 0xB800E8B8
#define  PREDBLK_NBINTRACH_9_inst_addr                                           "0x002E"
#define  set_PREDBLK_NBINTRACH_9_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_9_reg)=data)
#define  get_PREDBLK_NBINTRACH_9_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_9_reg))
#define  PREDBLK_NBINTRACH_9_intra_flag_shift                                    (0)
#define  PREDBLK_NBINTRACH_9_intra_flag_mask                                     (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_9_intra_flag(data)                                    (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_9_get_intra_flag(data)                                (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_10                                                    0x1800E8BC
#define  PREDBLK_NBINTRACH_10_reg_addr                                           "0xB800E8BC"
#define  PREDBLK_NBINTRACH_10_reg                                                0xB800E8BC
#define  PREDBLK_NBINTRACH_10_inst_addr                                          "0x002F"
#define  set_PREDBLK_NBINTRACH_10_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_10_reg)=data)
#define  get_PREDBLK_NBINTRACH_10_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_10_reg))
#define  PREDBLK_NBINTRACH_10_intra_flag_shift                                   (0)
#define  PREDBLK_NBINTRACH_10_intra_flag_mask                                    (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_10_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_10_get_intra_flag(data)                               (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_11                                                    0x1800E8C0
#define  PREDBLK_NBINTRACH_11_reg_addr                                           "0xB800E8C0"
#define  PREDBLK_NBINTRACH_11_reg                                                0xB800E8C0
#define  PREDBLK_NBINTRACH_11_inst_addr                                          "0x0030"
#define  set_PREDBLK_NBINTRACH_11_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_11_reg)=data)
#define  get_PREDBLK_NBINTRACH_11_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_11_reg))
#define  PREDBLK_NBINTRACH_11_intra_flag_shift                                   (0)
#define  PREDBLK_NBINTRACH_11_intra_flag_mask                                    (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_11_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_11_get_intra_flag(data)                               (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_12                                                    0x1800E8C4
#define  PREDBLK_NBINTRACH_12_reg_addr                                           "0xB800E8C4"
#define  PREDBLK_NBINTRACH_12_reg                                                0xB800E8C4
#define  PREDBLK_NBINTRACH_12_inst_addr                                          "0x0031"
#define  set_PREDBLK_NBINTRACH_12_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_12_reg)=data)
#define  get_PREDBLK_NBINTRACH_12_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_12_reg))
#define  PREDBLK_NBINTRACH_12_intra_flag_shift                                   (0)
#define  PREDBLK_NBINTRACH_12_intra_flag_mask                                    (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_12_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_12_get_intra_flag(data)                               (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_13                                                    0x1800E8C8
#define  PREDBLK_NBINTRACH_13_reg_addr                                           "0xB800E8C8"
#define  PREDBLK_NBINTRACH_13_reg                                                0xB800E8C8
#define  PREDBLK_NBINTRACH_13_inst_addr                                          "0x0032"
#define  set_PREDBLK_NBINTRACH_13_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_13_reg)=data)
#define  get_PREDBLK_NBINTRACH_13_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_13_reg))
#define  PREDBLK_NBINTRACH_13_intra_flag_shift                                   (0)
#define  PREDBLK_NBINTRACH_13_intra_flag_mask                                    (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_13_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_13_get_intra_flag(data)                               (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_14                                                    0x1800E8CC
#define  PREDBLK_NBINTRACH_14_reg_addr                                           "0xB800E8CC"
#define  PREDBLK_NBINTRACH_14_reg                                                0xB800E8CC
#define  PREDBLK_NBINTRACH_14_inst_addr                                          "0x0033"
#define  set_PREDBLK_NBINTRACH_14_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_14_reg)=data)
#define  get_PREDBLK_NBINTRACH_14_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_14_reg))
#define  PREDBLK_NBINTRACH_14_intra_flag_shift                                   (0)
#define  PREDBLK_NBINTRACH_14_intra_flag_mask                                    (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_14_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_14_get_intra_flag(data)                               (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_15                                                    0x1800E8D0
#define  PREDBLK_NBINTRACH_15_reg_addr                                           "0xB800E8D0"
#define  PREDBLK_NBINTRACH_15_reg                                                0xB800E8D0
#define  PREDBLK_NBINTRACH_15_inst_addr                                          "0x0034"
#define  set_PREDBLK_NBINTRACH_15_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_15_reg)=data)
#define  get_PREDBLK_NBINTRACH_15_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_15_reg))
#define  PREDBLK_NBINTRACH_15_intra_flag_shift                                   (0)
#define  PREDBLK_NBINTRACH_15_intra_flag_mask                                    (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_15_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_15_get_intra_flag(data)                               (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_0                                                     0x1800E8D4
#define  PREDBLK_NBFIELDOV_0_reg_addr                                            "0xB800E8D4"
#define  PREDBLK_NBFIELDOV_0_reg                                                 0xB800E8D4
#define  PREDBLK_NBFIELDOV_0_inst_addr                                           "0x0035"
#define  set_PREDBLK_NBFIELDOV_0_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_0_reg)=data)
#define  get_PREDBLK_NBFIELDOV_0_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_0_reg))
#define  PREDBLK_NBFIELDOV_0_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_0_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_0_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_0_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_1                                                     0x1800E8D8
#define  PREDBLK_NBFIELDOV_1_reg_addr                                            "0xB800E8D8"
#define  PREDBLK_NBFIELDOV_1_reg                                                 0xB800E8D8
#define  PREDBLK_NBFIELDOV_1_inst_addr                                           "0x0036"
#define  set_PREDBLK_NBFIELDOV_1_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_1_reg)=data)
#define  get_PREDBLK_NBFIELDOV_1_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_1_reg))
#define  PREDBLK_NBFIELDOV_1_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_1_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_1_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_1_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_2                                                     0x1800E8DC
#define  PREDBLK_NBFIELDOV_2_reg_addr                                            "0xB800E8DC"
#define  PREDBLK_NBFIELDOV_2_reg                                                 0xB800E8DC
#define  PREDBLK_NBFIELDOV_2_inst_addr                                           "0x0037"
#define  set_PREDBLK_NBFIELDOV_2_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_2_reg)=data)
#define  get_PREDBLK_NBFIELDOV_2_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_2_reg))
#define  PREDBLK_NBFIELDOV_2_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_2_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_2_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_2_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_3                                                     0x1800E8E0
#define  PREDBLK_NBFIELDOV_3_reg_addr                                            "0xB800E8E0"
#define  PREDBLK_NBFIELDOV_3_reg                                                 0xB800E8E0
#define  PREDBLK_NBFIELDOV_3_inst_addr                                           "0x0038"
#define  set_PREDBLK_NBFIELDOV_3_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_3_reg)=data)
#define  get_PREDBLK_NBFIELDOV_3_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_3_reg))
#define  PREDBLK_NBFIELDOV_3_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_3_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_3_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_3_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_4                                                     0x1800E8E4
#define  PREDBLK_NBFIELDOV_4_reg_addr                                            "0xB800E8E4"
#define  PREDBLK_NBFIELDOV_4_reg                                                 0xB800E8E4
#define  PREDBLK_NBFIELDOV_4_inst_addr                                           "0x0039"
#define  set_PREDBLK_NBFIELDOV_4_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_4_reg)=data)
#define  get_PREDBLK_NBFIELDOV_4_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_4_reg))
#define  PREDBLK_NBFIELDOV_4_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_4_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_4_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_4_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_5                                                     0x1800E8E8
#define  PREDBLK_NBFIELDOV_5_reg_addr                                            "0xB800E8E8"
#define  PREDBLK_NBFIELDOV_5_reg                                                 0xB800E8E8
#define  PREDBLK_NBFIELDOV_5_inst_addr                                           "0x003A"
#define  set_PREDBLK_NBFIELDOV_5_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_5_reg)=data)
#define  get_PREDBLK_NBFIELDOV_5_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_5_reg))
#define  PREDBLK_NBFIELDOV_5_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_5_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_5_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_5_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_6                                                     0x1800E8EC
#define  PREDBLK_NBFIELDOV_6_reg_addr                                            "0xB800E8EC"
#define  PREDBLK_NBFIELDOV_6_reg                                                 0xB800E8EC
#define  PREDBLK_NBFIELDOV_6_inst_addr                                           "0x003B"
#define  set_PREDBLK_NBFIELDOV_6_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_6_reg)=data)
#define  get_PREDBLK_NBFIELDOV_6_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_6_reg))
#define  PREDBLK_NBFIELDOV_6_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_6_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_6_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_6_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_7                                                     0x1800E8F0
#define  PREDBLK_NBFIELDOV_7_reg_addr                                            "0xB800E8F0"
#define  PREDBLK_NBFIELDOV_7_reg                                                 0xB800E8F0
#define  PREDBLK_NBFIELDOV_7_inst_addr                                           "0x003C"
#define  set_PREDBLK_NBFIELDOV_7_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_7_reg)=data)
#define  get_PREDBLK_NBFIELDOV_7_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_7_reg))
#define  PREDBLK_NBFIELDOV_7_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_7_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_7_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_7_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_8                                                     0x1800E8F4
#define  PREDBLK_NBFIELDOV_8_reg_addr                                            "0xB800E8F4"
#define  PREDBLK_NBFIELDOV_8_reg                                                 0xB800E8F4
#define  PREDBLK_NBFIELDOV_8_inst_addr                                           "0x003D"
#define  set_PREDBLK_NBFIELDOV_8_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_8_reg)=data)
#define  get_PREDBLK_NBFIELDOV_8_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_8_reg))
#define  PREDBLK_NBFIELDOV_8_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_8_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_8_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_8_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_9                                                     0x1800E8F8
#define  PREDBLK_NBFIELDOV_9_reg_addr                                            "0xB800E8F8"
#define  PREDBLK_NBFIELDOV_9_reg                                                 0xB800E8F8
#define  PREDBLK_NBFIELDOV_9_inst_addr                                           "0x003E"
#define  set_PREDBLK_NBFIELDOV_9_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_9_reg)=data)
#define  get_PREDBLK_NBFIELDOV_9_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_9_reg))
#define  PREDBLK_NBFIELDOV_9_field_overflag_flag_shift                           (0)
#define  PREDBLK_NBFIELDOV_9_field_overflag_flag_mask                            (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_9_field_overflag_flag(data)                           (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_9_get_field_overflag_flag(data)                       (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_10                                                    0x1800E8FC
#define  PREDBLK_NBFIELDOV_10_reg_addr                                           "0xB800E8FC"
#define  PREDBLK_NBFIELDOV_10_reg                                                0xB800E8FC
#define  PREDBLK_NBFIELDOV_10_inst_addr                                          "0x003F"
#define  set_PREDBLK_NBFIELDOV_10_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_10_reg)=data)
#define  get_PREDBLK_NBFIELDOV_10_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_10_reg))
#define  PREDBLK_NBFIELDOV_10_field_overflag_flag_shift                          (0)
#define  PREDBLK_NBFIELDOV_10_field_overflag_flag_mask                           (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_10_field_overflag_flag(data)                          (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_10_get_field_overflag_flag(data)                      (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_11                                                    0x1800E900
#define  PREDBLK_NBFIELDOV_11_reg_addr                                           "0xB800E900"
#define  PREDBLK_NBFIELDOV_11_reg                                                0xB800E900
#define  PREDBLK_NBFIELDOV_11_inst_addr                                          "0x0040"
#define  set_PREDBLK_NBFIELDOV_11_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_11_reg)=data)
#define  get_PREDBLK_NBFIELDOV_11_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_11_reg))
#define  PREDBLK_NBFIELDOV_11_field_overflag_flag_shift                          (0)
#define  PREDBLK_NBFIELDOV_11_field_overflag_flag_mask                           (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_11_field_overflag_flag(data)                          (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_11_get_field_overflag_flag(data)                      (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_12                                                    0x1800E904
#define  PREDBLK_NBFIELDOV_12_reg_addr                                           "0xB800E904"
#define  PREDBLK_NBFIELDOV_12_reg                                                0xB800E904
#define  PREDBLK_NBFIELDOV_12_inst_addr                                          "0x0041"
#define  set_PREDBLK_NBFIELDOV_12_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_12_reg)=data)
#define  get_PREDBLK_NBFIELDOV_12_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_12_reg))
#define  PREDBLK_NBFIELDOV_12_field_overflag_flag_shift                          (0)
#define  PREDBLK_NBFIELDOV_12_field_overflag_flag_mask                           (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_12_field_overflag_flag(data)                          (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_12_get_field_overflag_flag(data)                      (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_13                                                    0x1800E908
#define  PREDBLK_NBFIELDOV_13_reg_addr                                           "0xB800E908"
#define  PREDBLK_NBFIELDOV_13_reg                                                0xB800E908
#define  PREDBLK_NBFIELDOV_13_inst_addr                                          "0x0042"
#define  set_PREDBLK_NBFIELDOV_13_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_13_reg)=data)
#define  get_PREDBLK_NBFIELDOV_13_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_13_reg))
#define  PREDBLK_NBFIELDOV_13_field_overflag_flag_shift                          (0)
#define  PREDBLK_NBFIELDOV_13_field_overflag_flag_mask                           (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_13_field_overflag_flag(data)                          (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_13_get_field_overflag_flag(data)                      (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_14                                                    0x1800E90C
#define  PREDBLK_NBFIELDOV_14_reg_addr                                           "0xB800E90C"
#define  PREDBLK_NBFIELDOV_14_reg                                                0xB800E90C
#define  PREDBLK_NBFIELDOV_14_inst_addr                                          "0x0043"
#define  set_PREDBLK_NBFIELDOV_14_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_14_reg)=data)
#define  get_PREDBLK_NBFIELDOV_14_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_14_reg))
#define  PREDBLK_NBFIELDOV_14_field_overflag_flag_shift                          (0)
#define  PREDBLK_NBFIELDOV_14_field_overflag_flag_mask                           (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_14_field_overflag_flag(data)                          (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_14_get_field_overflag_flag(data)                      (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_15                                                    0x1800E910
#define  PREDBLK_NBFIELDOV_15_reg_addr                                           "0xB800E910"
#define  PREDBLK_NBFIELDOV_15_reg                                                0xB800E910
#define  PREDBLK_NBFIELDOV_15_inst_addr                                          "0x0044"
#define  set_PREDBLK_NBFIELDOV_15_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_15_reg)=data)
#define  get_PREDBLK_NBFIELDOV_15_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_15_reg))
#define  PREDBLK_NBFIELDOV_15_field_overflag_flag_shift                          (0)
#define  PREDBLK_NBFIELDOV_15_field_overflag_flag_mask                           (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_15_field_overflag_flag(data)                          (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_15_get_field_overflag_flag(data)                      (0xFFFFFFFF&(data))

#define  PREDBLK_NBEXTRA                                                         0x1800E914
#define  PREDBLK_NBEXTRA_reg_addr                                                "0xB800E914"
#define  PREDBLK_NBEXTRA_reg                                                     0xB800E914
#define  PREDBLK_NBEXTRA_inst_addr                                               "0x0045"
#define  set_PREDBLK_NBEXTRA_reg(data)                                           (*((volatile unsigned int*)PREDBLK_NBEXTRA_reg)=data)
#define  get_PREDBLK_NBEXTRA_reg                                                 (*((volatile unsigned int*)PREDBLK_NBEXTRA_reg))
#define  PREDBLK_NBEXTRA_intra0_shift                                            (3)
#define  PREDBLK_NBEXTRA_intra1_shift                                            (2)
#define  PREDBLK_NBEXTRA_intrachroma_shift                                       (1)
#define  PREDBLK_NBEXTRA_intrafield_shift                                        (0)
#define  PREDBLK_NBEXTRA_intra0_mask                                             (0x00000008)
#define  PREDBLK_NBEXTRA_intra1_mask                                             (0x00000004)
#define  PREDBLK_NBEXTRA_intrachroma_mask                                        (0x00000002)
#define  PREDBLK_NBEXTRA_intrafield_mask                                         (0x00000001)
#define  PREDBLK_NBEXTRA_intra0(data)                                            (0x00000008&((data)<<3))
#define  PREDBLK_NBEXTRA_intra1(data)                                            (0x00000004&((data)<<2))
#define  PREDBLK_NBEXTRA_intrachroma(data)                                       (0x00000002&((data)<<1))
#define  PREDBLK_NBEXTRA_intrafield(data)                                        (0x00000001&(data))
#define  PREDBLK_NBEXTRA_get_intra0(data)                                        ((0x00000008&(data))>>3)
#define  PREDBLK_NBEXTRA_get_intra1(data)                                        ((0x00000004&(data))>>2)
#define  PREDBLK_NBEXTRA_get_intrachroma(data)                                   ((0x00000002&(data))>>1)
#define  PREDBLK_NBEXTRA_get_intrafield(data)                                    (0x00000001&(data))

#define  PREDBLK_WTBLSA                                                          0x1800E918
#define  PREDBLK_WTBLSA_reg_addr                                                 "0xB800E918"
#define  PREDBLK_WTBLSA_reg                                                      0xB800E918
#define  PREDBLK_WTBLSA_inst_addr                                                "0x0046"
#define  set_PREDBLK_WTBLSA_reg(data)                                            (*((volatile unsigned int*)PREDBLK_WTBLSA_reg)=data)
#define  get_PREDBLK_WTBLSA_reg                                                  (*((volatile unsigned int*)PREDBLK_WTBLSA_reg))
#define  PREDBLK_WTBLSA_wtbl_starta_shift                                        (0)
#define  PREDBLK_WTBLSA_wtbl_starta_mask                                         (0x000003FF)
#define  PREDBLK_WTBLSA_wtbl_starta(data)                                        (0x000003FF&(data))
#define  PREDBLK_WTBLSA_get_wtbl_starta(data)                                    (0x000003FF&(data))

#define  PREDBLK_WTFLAG_0                                                        0x1800E91C
#define  PREDBLK_WTFLAG_0_reg_addr                                               "0xB800E91C"
#define  PREDBLK_WTFLAG_0_reg                                                    0xB800E91C
#define  PREDBLK_WTFLAG_0_inst_addr                                              "0x0047"
#define  set_PREDBLK_WTFLAG_0_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_0_reg)=data)
#define  get_PREDBLK_WTFLAG_0_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_0_reg))
#define  PREDBLK_WTFLAG_0_wt_flag_shift                                          (0)
#define  PREDBLK_WTFLAG_0_wt_flag_mask                                           (0xFFFFFFFF)
#define  PREDBLK_WTFLAG_0_wt_flag(data)                                          (0xFFFFFFFF&(data))
#define  PREDBLK_WTFLAG_0_get_wt_flag(data)                                      (0xFFFFFFFF&(data))

#define  PREDBLK_WTFLAG_1                                                        0x1800E920
#define  PREDBLK_WTFLAG_1_reg_addr                                               "0xB800E920"
#define  PREDBLK_WTFLAG_1_reg                                                    0xB800E920
#define  PREDBLK_WTFLAG_1_inst_addr                                              "0x0048"
#define  set_PREDBLK_WTFLAG_1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_1_reg)=data)
#define  get_PREDBLK_WTFLAG_1_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_1_reg))
#define  PREDBLK_WTFLAG_1_wt_flag_shift                                          (0)
#define  PREDBLK_WTFLAG_1_wt_flag_mask                                           (0xFFFFFFFF)
#define  PREDBLK_WTFLAG_1_wt_flag(data)                                          (0xFFFFFFFF&(data))
#define  PREDBLK_WTFLAG_1_get_wt_flag(data)                                      (0xFFFFFFFF&(data))

#define  PREDBLK_WTFLAG_2                                                        0x1800E924
#define  PREDBLK_WTFLAG_2_reg_addr                                               "0xB800E924"
#define  PREDBLK_WTFLAG_2_reg                                                    0xB800E924
#define  PREDBLK_WTFLAG_2_inst_addr                                              "0x0049"
#define  set_PREDBLK_WTFLAG_2_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_2_reg)=data)
#define  get_PREDBLK_WTFLAG_2_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_2_reg))
#define  PREDBLK_WTFLAG_2_wt_flag_shift                                          (0)
#define  PREDBLK_WTFLAG_2_wt_flag_mask                                           (0xFFFFFFFF)
#define  PREDBLK_WTFLAG_2_wt_flag(data)                                          (0xFFFFFFFF&(data))
#define  PREDBLK_WTFLAG_2_get_wt_flag(data)                                      (0xFFFFFFFF&(data))

#define  PREDBLK_WTFLAG_3                                                        0x1800E928
#define  PREDBLK_WTFLAG_3_reg_addr                                               "0xB800E928"
#define  PREDBLK_WTFLAG_3_reg                                                    0xB800E928
#define  PREDBLK_WTFLAG_3_inst_addr                                              "0x004A"
#define  set_PREDBLK_WTFLAG_3_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_3_reg)=data)
#define  get_PREDBLK_WTFLAG_3_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_3_reg))
#define  PREDBLK_WTFLAG_3_wt_flag_shift                                          (0)
#define  PREDBLK_WTFLAG_3_wt_flag_mask                                           (0xFFFFFFFF)
#define  PREDBLK_WTFLAG_3_wt_flag(data)                                          (0xFFFFFFFF&(data))
#define  PREDBLK_WTFLAG_3_get_wt_flag(data)                                      (0xFFFFFFFF&(data))

#define  PREDBLK_SDMAADR                                                         0x1800E92C
#define  PREDBLK_SDMAADR_reg_addr                                                "0xB800E92C"
#define  PREDBLK_SDMAADR_reg                                                     0xB800E92C
#define  PREDBLK_SDMAADR_inst_addr                                               "0x004B"
#define  set_PREDBLK_SDMAADR_reg(data)                                           (*((volatile unsigned int*)PREDBLK_SDMAADR_reg)=data)
#define  get_PREDBLK_SDMAADR_reg                                                 (*((volatile unsigned int*)PREDBLK_SDMAADR_reg))
#define  PREDBLK_SDMAADR_wdone_enable_shift                                      (31)
#define  PREDBLK_SDMAADR_mem_eng_busy_shift                                      (30)
#define  PREDBLK_SDMAADR_seq_line_addr_shift                                     (0)
#define  PREDBLK_SDMAADR_wdone_enable_mask                                       (0x80000000)
#define  PREDBLK_SDMAADR_mem_eng_busy_mask                                       (0x40000000)
#define  PREDBLK_SDMAADR_seq_line_addr_mask                                      (0x1FFFFFFF)
#define  PREDBLK_SDMAADR_wdone_enable(data)                                      (0x80000000&((data)<<31))
#define  PREDBLK_SDMAADR_mem_eng_busy(data)                                      (0x40000000&((data)<<30))
#define  PREDBLK_SDMAADR_seq_line_addr(data)                                     (0x1FFFFFFF&(data))
#define  PREDBLK_SDMAADR_get_wdone_enable(data)                                  ((0x80000000&(data))>>31)
#define  PREDBLK_SDMAADR_get_mem_eng_busy(data)                                  ((0x40000000&(data))>>30)
#define  PREDBLK_SDMAADR_get_seq_line_addr(data)                                 (0x1FFFFFFF&(data))

#define  PREDBLK_INTR_THRESH                                                     0x1800E930
#define  PREDBLK_INTR_THRESH_reg_addr                                            "0xB800E930"
#define  PREDBLK_INTR_THRESH_reg                                                 0xB800E930
#define  PREDBLK_INTR_THRESH_inst_addr                                           "0x004C"
#define  set_PREDBLK_INTR_THRESH_reg(data)                                       (*((volatile unsigned int*)PREDBLK_INTR_THRESH_reg)=data)
#define  get_PREDBLK_INTR_THRESH_reg                                             (*((volatile unsigned int*)PREDBLK_INTR_THRESH_reg))
#define  PREDBLK_INTR_THRESH_value_shift                                         (0)
#define  PREDBLK_INTR_THRESH_value_mask                                          (0x0FFFFFFF)
#define  PREDBLK_INTR_THRESH_value(data)                                         (0x0FFFFFFF&(data))
#define  PREDBLK_INTR_THRESH_get_value(data)                                     (0x0FFFFFFF&(data))

#define  PREDBLK_BUSY                                                            0x1800E934
#define  PREDBLK_BUSY_reg_addr                                                   "0xB800E934"
#define  PREDBLK_BUSY_reg                                                        0xB800E934
#define  PREDBLK_BUSY_inst_addr                                                  "0x004D"
#define  set_PREDBLK_BUSY_reg(data)                                              (*((volatile unsigned int*)PREDBLK_BUSY_reg)=data)
#define  get_PREDBLK_BUSY_reg                                                    (*((volatile unsigned int*)PREDBLK_BUSY_reg))
#define  PREDBLK_BUSY_reach_thresh_shift                                         (28)
#define  PREDBLK_BUSY_count_shift                                                (0)
#define  PREDBLK_BUSY_reach_thresh_mask                                          (0x10000000)
#define  PREDBLK_BUSY_count_mask                                                 (0x0FFFFFFF)
#define  PREDBLK_BUSY_reach_thresh(data)                                         (0x10000000&((data)<<28))
#define  PREDBLK_BUSY_count(data)                                                (0x0FFFFFFF&(data))
#define  PREDBLK_BUSY_get_reach_thresh(data)                                     ((0x10000000&(data))>>28)
#define  PREDBLK_BUSY_get_count(data)                                            (0x0FFFFFFF&(data))

#define  PREDBLK_BASEA                                                           0x1800E938
#define  PREDBLK_BASEA_reg_addr                                                  "0xB800E938"
#define  PREDBLK_BASEA_reg                                                       0xB800E938
#define  PREDBLK_BASEA_inst_addr                                                 "0x004E"
#define  set_PREDBLK_BASEA_reg(data)                                             (*((volatile unsigned int*)PREDBLK_BASEA_reg)=data)
#define  get_PREDBLK_BASEA_reg                                                   (*((volatile unsigned int*)PREDBLK_BASEA_reg))
#define  PREDBLK_BASEA_basea0_shift                                              (16)
#define  PREDBLK_BASEA_basea1_shift                                              (3)
#define  PREDBLK_BASEA_basea0_mask                                               (0x007F0000)
#define  PREDBLK_BASEA_basea1_mask                                               (0x000003F8)
#define  PREDBLK_BASEA_basea0(data)                                              (0x007F0000&((data)<<16))
#define  PREDBLK_BASEA_basea1(data)                                              (0x000003F8&((data)<<3))
#define  PREDBLK_BASEA_get_basea0(data)                                          ((0x007F0000&(data))>>16)
#define  PREDBLK_BASEA_get_basea1(data)                                          ((0x000003F8&(data))>>3)

#define  PREDBLK_OFFSETA_0                                                       0x1800E93C
#define  PREDBLK_OFFSETA_0_reg_addr                                              "0xB800E93C"
#define  PREDBLK_OFFSETA_0_reg                                                   0xB800E93C
#define  PREDBLK_OFFSETA_0_inst_addr                                             "0x004F"
#define  set_PREDBLK_OFFSETA_0_reg(data)                                         (*((volatile unsigned int*)PREDBLK_OFFSETA_0_reg)=data)
#define  get_PREDBLK_OFFSETA_0_reg                                               (*((volatile unsigned int*)PREDBLK_OFFSETA_0_reg))
#define  PREDBLK_OFFSETA_0_offseta_shift                                         (3)
#define  PREDBLK_OFFSETA_0_offseta_mask                                          (0x000003F8)
#define  PREDBLK_OFFSETA_0_offseta(data)                                         (0x000003F8&((data)<<3))
#define  PREDBLK_OFFSETA_0_get_offseta(data)                                     ((0x000003F8&(data))>>3)

#define  PREDBLK_OFFSETA_1                                                       0x1800E940
#define  PREDBLK_OFFSETA_1_reg_addr                                              "0xB800E940"
#define  PREDBLK_OFFSETA_1_reg                                                   0xB800E940
#define  PREDBLK_OFFSETA_1_inst_addr                                             "0x0050"
#define  set_PREDBLK_OFFSETA_1_reg(data)                                         (*((volatile unsigned int*)PREDBLK_OFFSETA_1_reg)=data)
#define  get_PREDBLK_OFFSETA_1_reg                                               (*((volatile unsigned int*)PREDBLK_OFFSETA_1_reg))
#define  PREDBLK_OFFSETA_1_offseta_shift                                         (3)
#define  PREDBLK_OFFSETA_1_offseta_mask                                          (0x000003F8)
#define  PREDBLK_OFFSETA_1_offseta(data)                                         (0x000003F8&((data)<<3))
#define  PREDBLK_OFFSETA_1_get_offseta(data)                                     ((0x000003F8&(data))>>3)

#define  PREDBLK_OFFSETA_2                                                       0x1800E944
#define  PREDBLK_OFFSETA_2_reg_addr                                              "0xB800E944"
#define  PREDBLK_OFFSETA_2_reg                                                   0xB800E944
#define  PREDBLK_OFFSETA_2_inst_addr                                             "0x0051"
#define  set_PREDBLK_OFFSETA_2_reg(data)                                         (*((volatile unsigned int*)PREDBLK_OFFSETA_2_reg)=data)
#define  get_PREDBLK_OFFSETA_2_reg                                               (*((volatile unsigned int*)PREDBLK_OFFSETA_2_reg))
#define  PREDBLK_OFFSETA_2_offseta_shift                                         (3)
#define  PREDBLK_OFFSETA_2_offseta_mask                                          (0x000003F8)
#define  PREDBLK_OFFSETA_2_offseta(data)                                         (0x000003F8&((data)<<3))
#define  PREDBLK_OFFSETA_2_get_offseta(data)                                     ((0x000003F8&(data))>>3)

#define  PREDBLK_DEBPAR                                                          0x1800E948
#define  PREDBLK_DEBPAR_reg_addr                                                 "0xB800E948"
#define  PREDBLK_DEBPAR_reg                                                      0xB800E948
#define  PREDBLK_DEBPAR_inst_addr                                                "0x0052"
#define  set_PREDBLK_DEBPAR_reg(data)                                            (*((volatile unsigned int*)PREDBLK_DEBPAR_reg)=data)
#define  get_PREDBLK_DEBPAR_reg                                                  (*((volatile unsigned int*)PREDBLK_DEBPAR_reg))
#define  PREDBLK_DEBPAR_starta_shift                                             (0)
#define  PREDBLK_DEBPAR_starta_mask                                              (0x0000007F)
#define  PREDBLK_DEBPAR_starta(data)                                             (0x0000007F&(data))
#define  PREDBLK_DEBPAR_get_starta(data)                                         (0x0000007F&(data))

#define  PREDBLK_MPEGCTL                                                         0x1800E94C
#define  PREDBLK_MPEGCTL_reg_addr                                                "0xB800E94C"
#define  PREDBLK_MPEGCTL_reg                                                     0xB800E94C
#define  PREDBLK_MPEGCTL_inst_addr                                               "0x0053"
#define  set_PREDBLK_MPEGCTL_reg(data)                                           (*((volatile unsigned int*)PREDBLK_MPEGCTL_reg)=data)
#define  get_PREDBLK_MPEGCTL_reg                                                 (*((volatile unsigned int*)PREDBLK_MPEGCTL_reg))
#define  PREDBLK_MPEGCTL_rounding_control_shift                                  (1)
#define  PREDBLK_MPEGCTL_quarter_sample_shift                                    (0)
#define  PREDBLK_MPEGCTL_rounding_control_mask                                   (0x00000002)
#define  PREDBLK_MPEGCTL_quarter_sample_mask                                     (0x00000001)
#define  PREDBLK_MPEGCTL_rounding_control(data)                                  (0x00000002&((data)<<1))
#define  PREDBLK_MPEGCTL_quarter_sample(data)                                    (0x00000001&(data))
#define  PREDBLK_MPEGCTL_get_rounding_control(data)                              ((0x00000002&(data))>>1)
#define  PREDBLK_MPEGCTL_get_quarter_sample(data)                                (0x00000001&(data))

#define  PREDBLK_RMEMDDR1                                                        0x1800E950
#define  PREDBLK_RMEMDDR1_reg_addr                                               "0xB800E950"
#define  PREDBLK_RMEMDDR1_reg                                                    0xB800E950
#define  PREDBLK_RMEMDDR1_inst_addr                                              "0x0054"
#define  set_PREDBLK_RMEMDDR1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_RMEMDDR1_reg)=data)
#define  get_PREDBLK_RMEMDDR1_reg                                                (*((volatile unsigned int*)PREDBLK_RMEMDDR1_reg))
#define  PREDBLK_RMEMDDR1_valid_shift                                            (31)
#define  PREDBLK_RMEMDDR1_base_addr_shift                                        (3)
#define  PREDBLK_RMEMDDR1_valid_mask                                             (0x80000000)
#define  PREDBLK_RMEMDDR1_base_addr_mask                                         (0x1FFFFFF8)
#define  PREDBLK_RMEMDDR1_valid(data)                                            (0x80000000&((data)<<31))
#define  PREDBLK_RMEMDDR1_base_addr(data)                                        (0x1FFFFFF8&((data)<<3))
#define  PREDBLK_RMEMDDR1_get_valid(data)                                        ((0x80000000&(data))>>31)
#define  PREDBLK_RMEMDDR1_get_base_addr(data)                                    ((0x1FFFFFF8&(data))>>3)

#define  PREDBLK_RMEMDDR2                                                        0x1800E954
#define  PREDBLK_RMEMDDR2_reg_addr                                               "0xB800E954"
#define  PREDBLK_RMEMDDR2_reg                                                    0xB800E954
#define  PREDBLK_RMEMDDR2_inst_addr                                              "0x0055"
#define  set_PREDBLK_RMEMDDR2_reg(data)                                          (*((volatile unsigned int*)PREDBLK_RMEMDDR2_reg)=data)
#define  get_PREDBLK_RMEMDDR2_reg                                                (*((volatile unsigned int*)PREDBLK_RMEMDDR2_reg))
#define  PREDBLK_RMEMDDR2_mbcnt_threshold_shift                                  (0)
#define  PREDBLK_RMEMDDR2_mbcnt_threshold_mask                                   (0xFFFFFFFF)
#define  PREDBLK_RMEMDDR2_mbcnt_threshold(data)                                  (0xFFFFFFFF&(data))
#define  PREDBLK_RMEMDDR2_get_mbcnt_threshold(data)                              (0xFFFFFFFF&(data))

#define  PREDBLK_RMEMCTL                                                         0x1800E958
#define  PREDBLK_RMEMCTL_reg_addr                                                "0xB800E958"
#define  PREDBLK_RMEMCTL_reg                                                     0xB800E958
#define  PREDBLK_RMEMCTL_inst_addr                                               "0x0056"
#define  set_PREDBLK_RMEMCTL_reg(data)                                           (*((volatile unsigned int*)PREDBLK_RMEMCTL_reg)=data)
#define  get_PREDBLK_RMEMCTL_reg                                                 (*((volatile unsigned int*)PREDBLK_RMEMCTL_reg))
#define  PREDBLK_RMEMCTL_valid_shift                                             (31)
#define  PREDBLK_RMEMCTL_start_addr_shift                                        (7)
#define  PREDBLK_RMEMCTL_end_addr_shift                                          (0)
#define  PREDBLK_RMEMCTL_valid_mask                                              (0x80000000)
#define  PREDBLK_RMEMCTL_start_addr_mask                                         (0x00003F80)
#define  PREDBLK_RMEMCTL_end_addr_mask                                           (0x0000007F)
#define  PREDBLK_RMEMCTL_valid(data)                                             (0x80000000&((data)<<31))
#define  PREDBLK_RMEMCTL_start_addr(data)                                        (0x00003F80&((data)<<7))
#define  PREDBLK_RMEMCTL_end_addr(data)                                          (0x0000007F&(data))
#define  PREDBLK_RMEMCTL_get_valid(data)                                         ((0x80000000&(data))>>31)
#define  PREDBLK_RMEMCTL_get_start_addr(data)                                    ((0x00003F80&(data))>>7)
#define  PREDBLK_RMEMCTL_get_end_addr(data)                                      (0x0000007F&(data))

#define  PREDBLK_URATIO_0                                                        0x1800E95C
#define  PREDBLK_URATIO_0_reg_addr                                               "0xB800E95C"
#define  PREDBLK_URATIO_0_reg                                                    0xB800E95C
#define  PREDBLK_URATIO_0_inst_addr                                              "0x0057"
#define  set_PREDBLK_URATIO_0_reg(data)                                          (*((volatile unsigned int*)PREDBLK_URATIO_0_reg)=data)
#define  get_PREDBLK_URATIO_0_reg                                                (*((volatile unsigned int*)PREDBLK_URATIO_0_reg))
#define  PREDBLK_URATIO_0_uratio_shift                                           (0)
#define  PREDBLK_URATIO_0_uratio_mask                                            (0x00007FFF)
#define  PREDBLK_URATIO_0_uratio(data)                                           (0x00007FFF&(data))
#define  PREDBLK_URATIO_0_get_uratio(data)                                       (0x00007FFF&(data))

#define  PREDBLK_URATIO_1                                                        0x1800E960
#define  PREDBLK_URATIO_1_reg_addr                                               "0xB800E960"
#define  PREDBLK_URATIO_1_reg                                                    0xB800E960
#define  PREDBLK_URATIO_1_inst_addr                                              "0x0058"
#define  set_PREDBLK_URATIO_1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_URATIO_1_reg)=data)
#define  get_PREDBLK_URATIO_1_reg                                                (*((volatile unsigned int*)PREDBLK_URATIO_1_reg))
#define  PREDBLK_URATIO_1_uratio_shift                                           (0)
#define  PREDBLK_URATIO_1_uratio_mask                                            (0x00007FFF)
#define  PREDBLK_URATIO_1_uratio(data)                                           (0x00007FFF&(data))
#define  PREDBLK_URATIO_1_get_uratio(data)                                       (0x00007FFF&(data))

#define  PREDBLK_DBUS                                                            0x1800E968
#define  PREDBLK_DBUS_reg_addr                                                   "0xB800E968"
#define  PREDBLK_DBUS_reg                                                        0xB800E968
#define  PREDBLK_DBUS_inst_addr                                                  "0x0059"
#define  set_PREDBLK_DBUS_reg(data)                                              (*((volatile unsigned int*)PREDBLK_DBUS_reg)=data)
#define  get_PREDBLK_DBUS_reg                                                    (*((volatile unsigned int*)PREDBLK_DBUS_reg))
#define  PREDBLK_DBUS_genpulse_shift                                             (31)
#define  PREDBLK_DBUS_piccount_shift                                             (17)
#define  PREDBLK_DBUS_mbaddrx_shift                                              (8)
#define  PREDBLK_DBUS_mbaddry_shift                                              (0)
#define  PREDBLK_DBUS_genpulse_mask                                              (0x80000000)
#define  PREDBLK_DBUS_piccount_mask                                              (0x7FFE0000)
#define  PREDBLK_DBUS_mbaddrx_mask                                               (0x0001FF00)
#define  PREDBLK_DBUS_mbaddry_mask                                               (0x000000FF)
#define  PREDBLK_DBUS_genpulse(data)                                             (0x80000000&((data)<<31))
#define  PREDBLK_DBUS_piccount(data)                                             (0x7FFE0000&((data)<<17))
#define  PREDBLK_DBUS_mbaddrx(data)                                              (0x0001FF00&((data)<<8))
#define  PREDBLK_DBUS_mbaddry(data)                                              (0x000000FF&(data))
#define  PREDBLK_DBUS_get_genpulse(data)                                         ((0x80000000&(data))>>31)
#define  PREDBLK_DBUS_get_piccount(data)                                         ((0x7FFE0000&(data))>>17)
#define  PREDBLK_DBUS_get_mbaddrx(data)                                          ((0x0001FF00&(data))>>8)
#define  PREDBLK_DBUS_get_mbaddry(data)                                          (0x000000FF&(data))

#define  PREDBLK_DBUS2                                                           0x1800E96C
#define  PREDBLK_DBUS2_reg_addr                                                  "0xB800E96C"
#define  PREDBLK_DBUS2_reg                                                       0xB800E96C
#define  PREDBLK_DBUS2_inst_addr                                                 "0x005A"
#define  set_PREDBLK_DBUS2_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS2_reg)=data)
#define  get_PREDBLK_DBUS2_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS2_reg))
#define  PREDBLK_DBUS2_dbgctrl_shift                                             (0)
#define  PREDBLK_DBUS2_dbgctrl_mask                                              (0xFFFFFFFF)
#define  PREDBLK_DBUS2_dbgctrl(data)                                             (0xFFFFFFFF&(data))
#define  PREDBLK_DBUS2_get_dbgctrl(data)                                         (0xFFFFFFFF&(data))

#define  PREDBLK_DBUS3                                                           0x1800E9F0
#define  PREDBLK_DBUS3_reg_addr                                                  "0xB800E9F0"
#define  PREDBLK_DBUS3_reg                                                       0xB800E9F0
#define  PREDBLK_DBUS3_inst_addr                                                 "0x005B"
#define  set_PREDBLK_DBUS3_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS3_reg)=data)
#define  get_PREDBLK_DBUS3_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS3_reg))
#define  PREDBLK_DBUS3_dbgctrl3_shift                                            (3)
#define  PREDBLK_DBUS3_dbgctrl_shift                                             (0)
#define  PREDBLK_DBUS3_dbgctrl3_mask                                             (0xFFFFFFF8)
#define  PREDBLK_DBUS3_dbgctrl_mask                                              (0x00000007)
#define  PREDBLK_DBUS3_dbgctrl3(data)                                            (0xFFFFFFF8&((data)<<3))
#define  PREDBLK_DBUS3_dbgctrl(data)                                             (0x00000007&(data))
#define  PREDBLK_DBUS3_get_dbgctrl3(data)                                        ((0xFFFFFFF8&(data))>>3)
#define  PREDBLK_DBUS3_get_dbgctrl(data)                                         (0x00000007&(data))

#define  PREDBLK_DMAMSB                                                          0x1800E970
#define  PREDBLK_DMAMSB_reg_addr                                                 "0xB800E970"
#define  PREDBLK_DMAMSB_reg                                                      0xB800E970
#define  PREDBLK_DMAMSB_inst_addr                                                "0x005C"
#define  set_PREDBLK_DMAMSB_reg(data)                                            (*((volatile unsigned int*)PREDBLK_DMAMSB_reg)=data)
#define  get_PREDBLK_DMAMSB_reg                                                  (*((volatile unsigned int*)PREDBLK_DMAMSB_reg))
#define  PREDBLK_DMAMSB_sdmawr1msb_shift                                         (6)
#define  PREDBLK_DMAMSB_sdma2msb_shift                                           (3)
#define  PREDBLK_DMAMSB_rmem2msb_shift                                           (0)
#define  PREDBLK_DMAMSB_sdmawr1msb_mask                                          (0x00000040)
#define  PREDBLK_DMAMSB_sdma2msb_mask                                            (0x00000038)
#define  PREDBLK_DMAMSB_rmem2msb_mask                                            (0x00000007)
#define  PREDBLK_DMAMSB_sdmawr1msb(data)                                         (0x00000040&((data)<<6))
#define  PREDBLK_DMAMSB_sdma2msb(data)                                           (0x00000038&((data)<<3))
#define  PREDBLK_DMAMSB_rmem2msb(data)                                           (0x00000007&(data))
#define  PREDBLK_DMAMSB_get_sdmawr1msb(data)                                     ((0x00000040&(data))>>6)
#define  PREDBLK_DMAMSB_get_sdma2msb(data)                                       ((0x00000038&(data))>>3)
#define  PREDBLK_DMAMSB_get_rmem2msb(data)                                       (0x00000007&(data))

#define  PREDBLK_DMEMADR                                                         0x1800E974
#define  PREDBLK_DMEMADR_reg_addr                                                "0xB800E974"
#define  PREDBLK_DMEMADR_reg                                                     0xB800E974
#define  PREDBLK_DMEMADR_inst_addr                                               "0x005D"
#define  set_PREDBLK_DMEMADR_reg(data)                                           (*((volatile unsigned int*)PREDBLK_DMEMADR_reg)=data)
#define  get_PREDBLK_DMEMADR_reg                                                 (*((volatile unsigned int*)PREDBLK_DMEMADR_reg))
#define  PREDBLK_DMEMADR_baseaddr_shift                                          (0)
#define  PREDBLK_DMEMADR_baseaddr_mask                                           (0x00000FFF)
#define  PREDBLK_DMEMADR_baseaddr(data)                                          (0x00000FFF&(data))
#define  PREDBLK_DMEMADR_get_baseaddr(data)                                      (0x00000FFF&(data))

#define  PREDBLK_DMEMOP                                                          0x1800E990
#define  PREDBLK_DMEMOP_reg_addr                                                 "0xB800E990"
#define  PREDBLK_DMEMOP_reg                                                      0xB800E990
#define  PREDBLK_DMEMOP_inst_addr                                                "0x005E"
#define  set_PREDBLK_DMEMOP_reg(data)                                            (*((volatile unsigned int*)PREDBLK_DMEMOP_reg)=data)
#define  get_PREDBLK_DMEMOP_reg                                                  (*((volatile unsigned int*)PREDBLK_DMEMOP_reg))
#define  PREDBLK_DMEMOP_count_shift                                              (0)
#define  PREDBLK_DMEMOP_count_mask                                               (0x0FFFFFFF)
#define  PREDBLK_DMEMOP_count(data)                                              (0x0FFFFFFF&(data))
#define  PREDBLK_DMEMOP_get_count(data)                                          (0x0FFFFFFF&(data))

#define  PREDBLK_SLICE_RESTART                                                   0x1800E994
#define  PREDBLK_SLICE_RESTART_reg_addr                                          "0xB800E994"
#define  PREDBLK_SLICE_RESTART_reg                                               0xB800E994
#define  PREDBLK_SLICE_RESTART_inst_addr                                         "0x005F"
#define  set_PREDBLK_SLICE_RESTART_reg(data)                                     (*((volatile unsigned int*)PREDBLK_SLICE_RESTART_reg)=data)
#define  get_PREDBLK_SLICE_RESTART_reg                                           (*((volatile unsigned int*)PREDBLK_SLICE_RESTART_reg))
#define  PREDBLK_SLICE_RESTART_hw_enable_shift                                   (31)
#define  PREDBLK_SLICE_RESTART_pmem_idle_shift                                   (0)
#define  PREDBLK_SLICE_RESTART_hw_enable_mask                                    (0x80000000)
#define  PREDBLK_SLICE_RESTART_pmem_idle_mask                                    (0x00000001)
#define  PREDBLK_SLICE_RESTART_hw_enable(data)                                   (0x80000000&((data)<<31))
#define  PREDBLK_SLICE_RESTART_pmem_idle(data)                                   (0x00000001&(data))
#define  PREDBLK_SLICE_RESTART_get_hw_enable(data)                               ((0x80000000&(data))>>31)
#define  PREDBLK_SLICE_RESTART_get_pmem_idle(data)                               (0x00000001&(data))

#define  PREDBLK_SLICE_DBG0                                                      0x1800E998
#define  PREDBLK_SLICE_DBG0_reg_addr                                             "0xB800E998"
#define  PREDBLK_SLICE_DBG0_reg                                                  0xB800E998
#define  PREDBLK_SLICE_DBG0_inst_addr                                            "0x0060"
#define  set_PREDBLK_SLICE_DBG0_reg(data)                                        (*((volatile unsigned int*)PREDBLK_SLICE_DBG0_reg)=data)
#define  get_PREDBLK_SLICE_DBG0_reg                                              (*((volatile unsigned int*)PREDBLK_SLICE_DBG0_reg))
#define  PREDBLK_SLICE_DBG0_sw_override_shift                                    (31)
#define  PREDBLK_SLICE_DBG0_ddr_inb_rdadr_shift                                  (21)
#define  PREDBLK_SLICE_DBG0_ddr_out_rdadr_shift                                  (15)
#define  PREDBLK_SLICE_DBG0_inb_mbcnt_shift                                      (11)
#define  PREDBLK_SLICE_DBG0_out_mbcnt_shift                                      (7)
#define  PREDBLK_SLICE_DBG0_pmem_inb_mbptr_shift                                 (3)
#define  PREDBLK_SLICE_DBG0_pmem_out_mbptr_shift                                 (0)
#define  PREDBLK_SLICE_DBG0_sw_override_mask                                     (0x80000000)
#define  PREDBLK_SLICE_DBG0_ddr_inb_rdadr_mask                                   (0x01E00000)
#define  PREDBLK_SLICE_DBG0_ddr_out_rdadr_mask                                   (0x001F8000)
#define  PREDBLK_SLICE_DBG0_inb_mbcnt_mask                                       (0x00007800)
#define  PREDBLK_SLICE_DBG0_out_mbcnt_mask                                       (0x00000780)
#define  PREDBLK_SLICE_DBG0_pmem_inb_mbptr_mask                                  (0x00000078)
#define  PREDBLK_SLICE_DBG0_pmem_out_mbptr_mask                                  (0x00000007)
#define  PREDBLK_SLICE_DBG0_sw_override(data)                                    (0x80000000&((data)<<31))
#define  PREDBLK_SLICE_DBG0_ddr_inb_rdadr(data)                                  (0x01E00000&((data)<<21))
#define  PREDBLK_SLICE_DBG0_ddr_out_rdadr(data)                                  (0x001F8000&((data)<<15))
#define  PREDBLK_SLICE_DBG0_inb_mbcnt(data)                                      (0x00007800&((data)<<11))
#define  PREDBLK_SLICE_DBG0_out_mbcnt(data)                                      (0x00000780&((data)<<7))
#define  PREDBLK_SLICE_DBG0_pmem_inb_mbptr(data)                                 (0x00000078&((data)<<3))
#define  PREDBLK_SLICE_DBG0_pmem_out_mbptr(data)                                 (0x00000007&(data))
#define  PREDBLK_SLICE_DBG0_get_sw_override(data)                                ((0x80000000&(data))>>31)
#define  PREDBLK_SLICE_DBG0_get_ddr_inb_rdadr(data)                              ((0x01E00000&(data))>>21)
#define  PREDBLK_SLICE_DBG0_get_ddr_out_rdadr(data)                              ((0x001F8000&(data))>>15)
#define  PREDBLK_SLICE_DBG0_get_inb_mbcnt(data)                                  ((0x00007800&(data))>>11)
#define  PREDBLK_SLICE_DBG0_get_out_mbcnt(data)                                  ((0x00000780&(data))>>7)
#define  PREDBLK_SLICE_DBG0_get_pmem_inb_mbptr(data)                             ((0x00000078&(data))>>3)
#define  PREDBLK_SLICE_DBG0_get_pmem_out_mbptr(data)                             (0x00000007&(data))

#define  PREDBLK_SLICE_DBG1                                                      0x1800E99C
#define  PREDBLK_SLICE_DBG1_reg_addr                                             "0xB800E99C"
#define  PREDBLK_SLICE_DBG1_reg                                                  0xB800E99C
#define  PREDBLK_SLICE_DBG1_inst_addr                                            "0x0061"
#define  set_PREDBLK_SLICE_DBG1_reg(data)                                        (*((volatile unsigned int*)PREDBLK_SLICE_DBG1_reg)=data)
#define  get_PREDBLK_SLICE_DBG1_reg                                              (*((volatile unsigned int*)PREDBLK_SLICE_DBG1_reg))
#define  PREDBLK_SLICE_DBG1_ddr_rng_rdptr_shift                                  (20)
#define  PREDBLK_SLICE_DBG1_ddr_rng_wrptr_shift                                  (10)
#define  PREDBLK_SLICE_DBG1_ddr_rng_size_shift                                   (0)
#define  PREDBLK_SLICE_DBG1_ddr_rng_rdptr_mask                                   (0x3FF00000)
#define  PREDBLK_SLICE_DBG1_ddr_rng_wrptr_mask                                   (0x000FFC00)
#define  PREDBLK_SLICE_DBG1_ddr_rng_size_mask                                    (0x000003FF)
#define  PREDBLK_SLICE_DBG1_ddr_rng_rdptr(data)                                  (0x3FF00000&((data)<<20))
#define  PREDBLK_SLICE_DBG1_ddr_rng_wrptr(data)                                  (0x000FFC00&((data)<<10))
#define  PREDBLK_SLICE_DBG1_ddr_rng_size(data)                                   (0x000003FF&(data))
#define  PREDBLK_SLICE_DBG1_get_ddr_rng_rdptr(data)                              ((0x3FF00000&(data))>>20)
#define  PREDBLK_SLICE_DBG1_get_ddr_rng_wrptr(data)                              ((0x000FFC00&(data))>>10)
#define  PREDBLK_SLICE_DBG1_get_ddr_rng_size(data)                               (0x000003FF&(data))

#define  PREDBLK_CONFLICT                                                        0x1800E9A0
#define  PREDBLK_CONFLICT_reg_addr                                               "0xB800E9A0"
#define  PREDBLK_CONFLICT_reg                                                    0xB800E9A0
#define  PREDBLK_CONFLICT_inst_addr                                              "0x0062"
#define  set_PREDBLK_CONFLICT_reg(data)                                          (*((volatile unsigned int*)PREDBLK_CONFLICT_reg)=data)
#define  get_PREDBLK_CONFLICT_reg                                                (*((volatile unsigned int*)PREDBLK_CONFLICT_reg))
#define  PREDBLK_CONFLICT_on_shift                                               (31)
#define  PREDBLK_CONFLICT_bank0_shift                                            (12)
#define  PREDBLK_CONFLICT_bank1_shift                                            (8)
#define  PREDBLK_CONFLICT_bank2_shift                                            (4)
#define  PREDBLK_CONFLICT_bank3_shift                                            (0)
#define  PREDBLK_CONFLICT_on_mask                                                (0x80000000)
#define  PREDBLK_CONFLICT_bank0_mask                                             (0x0000F000)
#define  PREDBLK_CONFLICT_bank1_mask                                             (0x00000F00)
#define  PREDBLK_CONFLICT_bank2_mask                                             (0x000000F0)
#define  PREDBLK_CONFLICT_bank3_mask                                             (0x0000000F)
#define  PREDBLK_CONFLICT_on(data)                                               (0x80000000&((data)<<31))
#define  PREDBLK_CONFLICT_bank0(data)                                            (0x0000F000&((data)<<12))
#define  PREDBLK_CONFLICT_bank1(data)                                            (0x00000F00&((data)<<8))
#define  PREDBLK_CONFLICT_bank2(data)                                            (0x000000F0&((data)<<4))
#define  PREDBLK_CONFLICT_bank3(data)                                            (0x0000000F&(data))
#define  PREDBLK_CONFLICT_get_on(data)                                           ((0x80000000&(data))>>31)
#define  PREDBLK_CONFLICT_get_bank0(data)                                        ((0x0000F000&(data))>>12)
#define  PREDBLK_CONFLICT_get_bank1(data)                                        ((0x00000F00&(data))>>8)
#define  PREDBLK_CONFLICT_get_bank2(data)                                        ((0x000000F0&(data))>>4)
#define  PREDBLK_CONFLICT_get_bank3(data)                                        (0x0000000F&(data))

#define  PREDBLK_ENCUMEM                                                         0x1800E9A4
#define  PREDBLK_ENCUMEM_reg_addr                                                "0xB800E9A4"
#define  PREDBLK_ENCUMEM_reg                                                     0xB800E9A4
#define  PREDBLK_ENCUMEM_inst_addr                                               "0x0063"
#define  set_PREDBLK_ENCUMEM_reg(data)                                           (*((volatile unsigned int*)PREDBLK_ENCUMEM_reg)=data)
#define  get_PREDBLK_ENCUMEM_reg                                                 (*((volatile unsigned int*)PREDBLK_ENCUMEM_reg))
#define  PREDBLK_ENCUMEM_dma_shift                                               (6)
#define  PREDBLK_ENCUMEM_ime_shift                                               (4)
#define  PREDBLK_ENCUMEM_fme_shift                                               (2)
#define  PREDBLK_ENCUMEM_gcf_shift                                               (0)
#define  PREDBLK_ENCUMEM_dma_mask                                                (0x000000C0)
#define  PREDBLK_ENCUMEM_ime_mask                                                (0x00000030)
#define  PREDBLK_ENCUMEM_fme_mask                                                (0x0000000C)
#define  PREDBLK_ENCUMEM_gcf_mask                                                (0x00000003)
#define  PREDBLK_ENCUMEM_dma(data)                                               (0x000000C0&((data)<<6))
#define  PREDBLK_ENCUMEM_ime(data)                                               (0x00000030&((data)<<4))
#define  PREDBLK_ENCUMEM_fme(data)                                               (0x0000000C&((data)<<2))
#define  PREDBLK_ENCUMEM_gcf(data)                                               (0x00000003&(data))
#define  PREDBLK_ENCUMEM_get_dma(data)                                           ((0x000000C0&(data))>>6)
#define  PREDBLK_ENCUMEM_get_ime(data)                                           ((0x00000030&(data))>>4)
#define  PREDBLK_ENCUMEM_get_fme(data)                                           ((0x0000000C&(data))>>2)
#define  PREDBLK_ENCUMEM_get_gcf(data)                                           (0x00000003&(data))

#define  PREDBLK_HEVC_UMEM_CTRL                                                  0x1800E9A8
#define  PREDBLK_HEVC_UMEM_CTRL_reg_addr                                         "0xB800E9A8"
#define  PREDBLK_HEVC_UMEM_CTRL_reg                                              0xB800E9A8
#define  PREDBLK_HEVC_UMEM_CTRL_inst_addr                                        "0x0064"
#define  set_PREDBLK_HEVC_UMEM_CTRL_reg(data)                                    (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL_reg)=data)
#define  get_PREDBLK_HEVC_UMEM_CTRL_reg                                          (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL_reg))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10_shift                             (25)
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en_shift                                  (24)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9_shift                              (23)
#define  PREDBLK_HEVC_UMEM_CTRL_bank5_owner_shift                                (22)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8_shift                              (21)
#define  PREDBLK_HEVC_UMEM_CTRL_bank4_owner_shift                                (20)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7_shift                              (19)
#define  PREDBLK_HEVC_UMEM_CTRL_bank3_owner_shift                                (18)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6_shift                              (17)
#define  PREDBLK_HEVC_UMEM_CTRL_bank2_owner_shift                                (16)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5_shift                              (15)
#define  PREDBLK_HEVC_UMEM_CTRL_bank1_owner_shift                                (14)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4_shift                              (13)
#define  PREDBLK_HEVC_UMEM_CTRL_bank0_owner_shift                                (12)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3_shift                              (11)
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank_shift                                 (7)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2_shift                              (6)
#define  PREDBLK_HEVC_UMEM_CTRL_pred_bank_shift                                  (2)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1_shift                              (1)
#define  PREDBLK_HEVC_UMEM_CTRL_umem_init_shift                                  (0)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10_mask                              (0x02000000)
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en_mask                                   (0x01000000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9_mask                               (0x00800000)
#define  PREDBLK_HEVC_UMEM_CTRL_bank5_owner_mask                                 (0x00400000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8_mask                               (0x00200000)
#define  PREDBLK_HEVC_UMEM_CTRL_bank4_owner_mask                                 (0x00100000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7_mask                               (0x00080000)
#define  PREDBLK_HEVC_UMEM_CTRL_bank3_owner_mask                                 (0x00040000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6_mask                               (0x00020000)
#define  PREDBLK_HEVC_UMEM_CTRL_bank2_owner_mask                                 (0x00010000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5_mask                               (0x00008000)
#define  PREDBLK_HEVC_UMEM_CTRL_bank1_owner_mask                                 (0x00004000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4_mask                               (0x00002000)
#define  PREDBLK_HEVC_UMEM_CTRL_bank0_owner_mask                                 (0x00001000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3_mask                               (0x00000800)
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank_mask                                  (0x00000780)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2_mask                               (0x00000040)
#define  PREDBLK_HEVC_UMEM_CTRL_pred_bank_mask                                   (0x0000003C)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1_mask                               (0x00000002)
#define  PREDBLK_HEVC_UMEM_CTRL_umem_init_mask                                   (0x00000001)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10(data)                             (0x02000000&((data)<<25))
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en(data)                                  (0x01000000&((data)<<24))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9(data)                              (0x00800000&((data)<<23))
#define  PREDBLK_HEVC_UMEM_CTRL_bank5_owner(data)                                (0x00400000&((data)<<22))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8(data)                              (0x00200000&((data)<<21))
#define  PREDBLK_HEVC_UMEM_CTRL_bank4_owner(data)                                (0x00100000&((data)<<20))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7(data)                              (0x00080000&((data)<<19))
#define  PREDBLK_HEVC_UMEM_CTRL_bank3_owner(data)                                (0x00040000&((data)<<18))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6(data)                              (0x00020000&((data)<<17))
#define  PREDBLK_HEVC_UMEM_CTRL_bank2_owner(data)                                (0x00010000&((data)<<16))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5(data)                              (0x00008000&((data)<<15))
#define  PREDBLK_HEVC_UMEM_CTRL_bank1_owner(data)                                (0x00004000&((data)<<14))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4(data)                              (0x00002000&((data)<<13))
#define  PREDBLK_HEVC_UMEM_CTRL_bank0_owner(data)                                (0x00001000&((data)<<12))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3(data)                              (0x00000800&((data)<<11))
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank(data)                                 (0x00000780&((data)<<7))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2(data)                              (0x00000040&((data)<<6))
#define  PREDBLK_HEVC_UMEM_CTRL_pred_bank(data)                                  (0x0000003C&((data)<<2))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1(data)                              (0x00000002&((data)<<1))
#define  PREDBLK_HEVC_UMEM_CTRL_umem_init(data)                                  (0x00000001&(data))
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable10(data)                         ((0x02000000&(data))>>25)
#define  PREDBLK_HEVC_UMEM_CTRL_get_um_dbg_en(data)                              ((0x01000000&(data))>>24)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable9(data)                          ((0x00800000&(data))>>23)
#define  PREDBLK_HEVC_UMEM_CTRL_get_bank5_owner(data)                            ((0x00400000&(data))>>22)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable8(data)                          ((0x00200000&(data))>>21)
#define  PREDBLK_HEVC_UMEM_CTRL_get_bank4_owner(data)                            ((0x00100000&(data))>>20)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable7(data)                          ((0x00080000&(data))>>19)
#define  PREDBLK_HEVC_UMEM_CTRL_get_bank3_owner(data)                            ((0x00040000&(data))>>18)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable6(data)                          ((0x00020000&(data))>>17)
#define  PREDBLK_HEVC_UMEM_CTRL_get_bank2_owner(data)                            ((0x00010000&(data))>>16)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable5(data)                          ((0x00008000&(data))>>15)
#define  PREDBLK_HEVC_UMEM_CTRL_get_bank1_owner(data)                            ((0x00004000&(data))>>14)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable4(data)                          ((0x00002000&(data))>>13)
#define  PREDBLK_HEVC_UMEM_CTRL_get_bank0_owner(data)                            ((0x00001000&(data))>>12)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable3(data)                          ((0x00000800&(data))>>11)
#define  PREDBLK_HEVC_UMEM_CTRL_get_itblk_bank(data)                             ((0x00000780&(data))>>7)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable2(data)                          ((0x00000040&(data))>>6)
#define  PREDBLK_HEVC_UMEM_CTRL_get_pred_bank(data)                              ((0x0000003C&(data))>>2)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable1(data)                          ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_UMEM_CTRL_get_umem_init(data)                              (0x00000001&(data))

#define  PREDBLK_HEVC_UMEM_CTRL2                                                 0x1800E9F4
#define  PREDBLK_HEVC_UMEM_CTRL2_reg_addr                                        "0xB800E9F4"
#define  PREDBLK_HEVC_UMEM_CTRL2_reg                                             0xB800E9F4
#define  PREDBLK_HEVC_UMEM_CTRL2_inst_addr                                       "0x0065"
#define  set_PREDBLK_HEVC_UMEM_CTRL2_reg(data)                                   (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL2_reg)=data)
#define  get_PREDBLK_HEVC_UMEM_CTRL2_reg                                         (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL2_reg))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4_shift                             (7)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank9_owner_shift                               (6)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3_shift                             (5)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank8_owner_shift                               (4)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2_shift                             (3)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank7_owner_shift                               (2)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1_shift                             (1)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank6_owner_shift                               (0)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4_mask                              (0x00000080)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank9_owner_mask                                (0x00000040)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3_mask                              (0x00000020)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank8_owner_mask                                (0x00000010)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2_mask                              (0x00000008)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank7_owner_mask                                (0x00000004)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1_mask                              (0x00000002)
#define  PREDBLK_HEVC_UMEM_CTRL2_bank6_owner_mask                                (0x00000001)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4(data)                             (0x00000080&((data)<<7))
#define  PREDBLK_HEVC_UMEM_CTRL2_bank9_owner(data)                               (0x00000040&((data)<<6))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3(data)                             (0x00000020&((data)<<5))
#define  PREDBLK_HEVC_UMEM_CTRL2_bank8_owner(data)                               (0x00000010&((data)<<4))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2(data)                             (0x00000008&((data)<<3))
#define  PREDBLK_HEVC_UMEM_CTRL2_bank7_owner(data)                               (0x00000004&((data)<<2))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1(data)                             (0x00000002&((data)<<1))
#define  PREDBLK_HEVC_UMEM_CTRL2_bank6_owner(data)                               (0x00000001&(data))
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable4(data)                         ((0x00000080&(data))>>7)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_bank9_owner(data)                           ((0x00000040&(data))>>6)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable3(data)                         ((0x00000020&(data))>>5)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_bank8_owner(data)                           ((0x00000010&(data))>>4)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable2(data)                         ((0x00000008&(data))>>3)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_bank7_owner(data)                           ((0x00000004&(data))>>2)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable1(data)                         ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_bank6_owner(data)                           (0x00000001&(data))

#define  PREDBLK_SDMAWRADR                                                       0x1800E9B0
#define  PREDBLK_SDMAWRADR_reg_addr                                              "0xB800E9B0"
#define  PREDBLK_SDMAWRADR_reg                                                   0xB800E9B0
#define  PREDBLK_SDMAWRADR_inst_addr                                             "0x0066"
#define  set_PREDBLK_SDMAWRADR_reg(data)                                         (*((volatile unsigned int*)PREDBLK_SDMAWRADR_reg)=data)
#define  get_PREDBLK_SDMAWRADR_reg                                               (*((volatile unsigned int*)PREDBLK_SDMAWRADR_reg))
#define  PREDBLK_SDMAWRADR_enable_shift                                          (31)
#define  PREDBLK_SDMAWRADR_seq_line_addr_shift                                   (0)
#define  PREDBLK_SDMAWRADR_enable_mask                                           (0x80000000)
#define  PREDBLK_SDMAWRADR_seq_line_addr_mask                                    (0x7FFFFFFF)
#define  PREDBLK_SDMAWRADR_enable(data)                                          (0x80000000&((data)<<31))
#define  PREDBLK_SDMAWRADR_seq_line_addr(data)                                   (0x7FFFFFFF&(data))
#define  PREDBLK_SDMAWRADR_get_enable(data)                                      ((0x80000000&(data))>>31)
#define  PREDBLK_SDMAWRADR_get_seq_line_addr(data)                               (0x7FFFFFFF&(data))

#define  PREDBLK_DECCNTL                                                         0x1800E9B4
#define  PREDBLK_DECCNTL_reg_addr                                                "0xB800E9B4"
#define  PREDBLK_DECCNTL_reg                                                     0xB800E9B4
#define  PREDBLK_DECCNTL_inst_addr                                               "0x0067"
#define  set_PREDBLK_DECCNTL_reg(data)                                           (*((volatile unsigned int*)PREDBLK_DECCNTL_reg)=data)
#define  get_PREDBLK_DECCNTL_reg                                                 (*((volatile unsigned int*)PREDBLK_DECCNTL_reg))
#define  PREDBLK_DECCNTL_reset_shift                                             (1)
#define  PREDBLK_DECCNTL_start_shift                                             (0)
#define  PREDBLK_DECCNTL_reset_mask                                              (0x00000002)
#define  PREDBLK_DECCNTL_start_mask                                              (0x00000001)
#define  PREDBLK_DECCNTL_reset(data)                                             (0x00000002&((data)<<1))
#define  PREDBLK_DECCNTL_start(data)                                             (0x00000001&(data))
#define  PREDBLK_DECCNTL_get_reset(data)                                         ((0x00000002&(data))>>1)
#define  PREDBLK_DECCNTL_get_start(data)                                         (0x00000001&(data))

#define  PREDBLK_HEVCCNTL                                                        0x1800E9B8
#define  PREDBLK_HEVCCNTL_reg_addr                                               "0xB800E9B8"
#define  PREDBLK_HEVCCNTL_reg                                                    0xB800E9B8
#define  PREDBLK_HEVCCNTL_inst_addr                                              "0x0068"
#define  set_PREDBLK_HEVCCNTL_reg(data)                                          (*((volatile unsigned int*)PREDBLK_HEVCCNTL_reg)=data)
#define  get_PREDBLK_HEVCCNTL_reg                                                (*((volatile unsigned int*)PREDBLK_HEVCCNTL_reg))
#define  PREDBLK_HEVCCNTL_tenbit_shift                                           (31)
#define  PREDBLK_HEVCCNTL_vp9_enable_shift                                       (4)
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable_shift                                (3)
#define  PREDBLK_HEVCCNTL_itblk_dump_enable_shift                                (2)
#define  PREDBLK_HEVCCNTL_itblk_dt_shift                                         (1)
#define  PREDBLK_HEVCCNTL_hevc_enable_shift                                      (0)
#define  PREDBLK_HEVCCNTL_tenbit_mask                                            (0x80000000)
#define  PREDBLK_HEVCCNTL_vp9_enable_mask                                        (0x00000010)
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable_mask                                 (0x00000008)
#define  PREDBLK_HEVCCNTL_itblk_dump_enable_mask                                 (0x00000004)
#define  PREDBLK_HEVCCNTL_itblk_dt_mask                                          (0x00000002)
#define  PREDBLK_HEVCCNTL_hevc_enable_mask                                       (0x00000001)
#define  PREDBLK_HEVCCNTL_tenbit(data)                                           (0x80000000&((data)<<31))
#define  PREDBLK_HEVCCNTL_vp9_enable(data)                                       (0x00000010&((data)<<4))
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable(data)                                (0x00000008&((data)<<3))
#define  PREDBLK_HEVCCNTL_itblk_dump_enable(data)                                (0x00000004&((data)<<2))
#define  PREDBLK_HEVCCNTL_itblk_dt(data)                                         (0x00000002&((data)<<1))
#define  PREDBLK_HEVCCNTL_hevc_enable(data)                                      (0x00000001&(data))
#define  PREDBLK_HEVCCNTL_get_tenbit(data)                                       ((0x80000000&(data))>>31)
#define  PREDBLK_HEVCCNTL_get_vp9_enable(data)                                   ((0x00000010&(data))>>4)
#define  PREDBLK_HEVCCNTL_get_mvbuf_dump_enable(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_HEVCCNTL_get_itblk_dump_enable(data)                            ((0x00000004&(data))>>2)
#define  PREDBLK_HEVCCNTL_get_itblk_dt(data)                                     ((0x00000002&(data))>>1)
#define  PREDBLK_HEVCCNTL_get_hevc_enable(data)                                  (0x00000001&(data))

#define  PREDBLK_HVRMEMCTL                                                       0x1800E9BC
#define  PREDBLK_HVRMEMCTL_reg_addr                                              "0xB800E9BC"
#define  PREDBLK_HVRMEMCTL_reg                                                   0xB800E9BC
#define  PREDBLK_HVRMEMCTL_inst_addr                                             "0x0069"
#define  set_PREDBLK_HVRMEMCTL_reg(data)                                         (*((volatile unsigned int*)PREDBLK_HVRMEMCTL_reg)=data)
#define  get_PREDBLK_HVRMEMCTL_reg                                               (*((volatile unsigned int*)PREDBLK_HVRMEMCTL_reg))
#define  PREDBLK_HVRMEMCTL_addr_shift                                            (0)
#define  PREDBLK_HVRMEMCTL_addr_mask                                             (0xFFFFFFFF)
#define  PREDBLK_HVRMEMCTL_addr(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_HVRMEMCTL_get_addr(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_HEVC_DEBUG_CTRL                                                 0x1800E9AC
#define  PREDBLK_HEVC_DEBUG_CTRL_reg_addr                                        "0xB800E9AC"
#define  PREDBLK_HEVC_DEBUG_CTRL_reg                                             0xB800E9AC
#define  PREDBLK_HEVC_DEBUG_CTRL_inst_addr                                       "0x006A"
#define  set_PREDBLK_HEVC_DEBUG_CTRL_reg(data)                                   (*((volatile unsigned int*)PREDBLK_HEVC_DEBUG_CTRL_reg)=data)
#define  get_PREDBLK_HEVC_DEBUG_CTRL_reg                                         (*((volatile unsigned int*)PREDBLK_HEVC_DEBUG_CTRL_reg))
#define  PREDBLK_HEVC_DEBUG_CTRL_rmem_count_shift                                (4)
#define  PREDBLK_HEVC_DEBUG_CTRL_pred_op_go_shift                                (3)
#define  PREDBLK_HEVC_DEBUG_CTRL_rmem_dump_go_shift                              (2)
#define  PREDBLK_HEVC_DEBUG_CTRL_ldumem_go_shift                                 (1)
#define  PREDBLK_HEVC_DEBUG_CTRL_stumem_go_shift                                 (0)
#define  PREDBLK_HEVC_DEBUG_CTRL_rmem_count_mask                                 (0x000003F0)
#define  PREDBLK_HEVC_DEBUG_CTRL_pred_op_go_mask                                 (0x00000008)
#define  PREDBLK_HEVC_DEBUG_CTRL_rmem_dump_go_mask                               (0x00000004)
#define  PREDBLK_HEVC_DEBUG_CTRL_ldumem_go_mask                                  (0x00000002)
#define  PREDBLK_HEVC_DEBUG_CTRL_stumem_go_mask                                  (0x00000001)
#define  PREDBLK_HEVC_DEBUG_CTRL_rmem_count(data)                                (0x000003F0&((data)<<4))
#define  PREDBLK_HEVC_DEBUG_CTRL_pred_op_go(data)                                (0x00000008&((data)<<3))
#define  PREDBLK_HEVC_DEBUG_CTRL_rmem_dump_go(data)                              (0x00000004&((data)<<2))
#define  PREDBLK_HEVC_DEBUG_CTRL_ldumem_go(data)                                 (0x00000002&((data)<<1))
#define  PREDBLK_HEVC_DEBUG_CTRL_stumem_go(data)                                 (0x00000001&(data))
#define  PREDBLK_HEVC_DEBUG_CTRL_get_rmem_count(data)                            ((0x000003F0&(data))>>4)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_pred_op_go(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_rmem_dump_go(data)                          ((0x00000004&(data))>>2)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_ldumem_go(data)                             ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_stumem_go(data)                             (0x00000001&(data))

#define  PREDBLK_LDUMEMCTL                                                       0x1800E9C0
#define  PREDBLK_LDUMEMCTL_reg_addr                                              "0xB800E9C0"
#define  PREDBLK_LDUMEMCTL_reg                                                   0xB800E9C0
#define  PREDBLK_LDUMEMCTL_inst_addr                                             "0x006B"
#define  set_PREDBLK_LDUMEMCTL_reg(data)                                         (*((volatile unsigned int*)PREDBLK_LDUMEMCTL_reg)=data)
#define  get_PREDBLK_LDUMEMCTL_reg                                               (*((volatile unsigned int*)PREDBLK_LDUMEMCTL_reg))
#define  PREDBLK_LDUMEMCTL_addr_shift                                            (0)
#define  PREDBLK_LDUMEMCTL_addr_mask                                             (0xFFFFFFFF)
#define  PREDBLK_LDUMEMCTL_addr(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_LDUMEMCTL_get_addr(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_STUMEMCTL                                                       0x1800E9C4
#define  PREDBLK_STUMEMCTL_reg_addr                                              "0xB800E9C4"
#define  PREDBLK_STUMEMCTL_reg                                                   0xB800E9C4
#define  PREDBLK_STUMEMCTL_inst_addr                                             "0x006C"
#define  set_PREDBLK_STUMEMCTL_reg(data)                                         (*((volatile unsigned int*)PREDBLK_STUMEMCTL_reg)=data)
#define  get_PREDBLK_STUMEMCTL_reg                                               (*((volatile unsigned int*)PREDBLK_STUMEMCTL_reg))
#define  PREDBLK_STUMEMCTL_addr_shift                                            (0)
#define  PREDBLK_STUMEMCTL_addr_mask                                             (0xFFFFFFFF)
#define  PREDBLK_STUMEMCTL_addr(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_STUMEMCTL_get_addr(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_DBG_TUBUF                                                       0x1800E9C8
#define  PREDBLK_DBG_TUBUF_reg_addr                                              "0xB800E9C8"
#define  PREDBLK_DBG_TUBUF_reg                                                   0xB800E9C8
#define  PREDBLK_DBG_TUBUF_inst_addr                                             "0x006D"
#define  set_PREDBLK_DBG_TUBUF_reg(data)                                         (*((volatile unsigned int*)PREDBLK_DBG_TUBUF_reg)=data)
#define  get_PREDBLK_DBG_TUBUF_reg                                               (*((volatile unsigned int*)PREDBLK_DBG_TUBUF_reg))
#define  PREDBLK_DBG_TUBUF_tu_dbg_en_shift                                       (30)
#define  PREDBLK_DBG_TUBUF_rden_shift                                            (29)
#define  PREDBLK_DBG_TUBUF_wren_shift                                            (28)
#define  PREDBLK_DBG_TUBUF_addr_shift                                            (22)
#define  PREDBLK_DBG_TUBUF_data_shift                                            (0)
#define  PREDBLK_DBG_TUBUF_tu_dbg_en_mask                                        (0x40000000)
#define  PREDBLK_DBG_TUBUF_rden_mask                                             (0x20000000)
#define  PREDBLK_DBG_TUBUF_wren_mask                                             (0x10000000)
#define  PREDBLK_DBG_TUBUF_addr_mask                                             (0x0FC00000)
#define  PREDBLK_DBG_TUBUF_data_mask                                             (0x003FFFFF)
#define  PREDBLK_DBG_TUBUF_tu_dbg_en(data)                                       (0x40000000&((data)<<30))
#define  PREDBLK_DBG_TUBUF_rden(data)                                            (0x20000000&((data)<<29))
#define  PREDBLK_DBG_TUBUF_wren(data)                                            (0x10000000&((data)<<28))
#define  PREDBLK_DBG_TUBUF_addr(data)                                            (0x0FC00000&((data)<<22))
#define  PREDBLK_DBG_TUBUF_data(data)                                            (0x003FFFFF&(data))
#define  PREDBLK_DBG_TUBUF_get_tu_dbg_en(data)                                   ((0x40000000&(data))>>30)
#define  PREDBLK_DBG_TUBUF_get_rden(data)                                        ((0x20000000&(data))>>29)
#define  PREDBLK_DBG_TUBUF_get_wren(data)                                        ((0x10000000&(data))>>28)
#define  PREDBLK_DBG_TUBUF_get_addr(data)                                        ((0x0FC00000&(data))>>22)
#define  PREDBLK_DBG_TUBUF_get_data(data)                                        (0x003FFFFF&(data))

#define  PREDBLK_PTR_TUBUF                                                       0x1800E9CC
#define  PREDBLK_PTR_TUBUF_reg_addr                                              "0xB800E9CC"
#define  PREDBLK_PTR_TUBUF_reg                                                   0xB800E9CC
#define  PREDBLK_PTR_TUBUF_inst_addr                                             "0x006E"
#define  set_PREDBLK_PTR_TUBUF_reg(data)                                         (*((volatile unsigned int*)PREDBLK_PTR_TUBUF_reg)=data)
#define  get_PREDBLK_PTR_TUBUF_reg                                               (*((volatile unsigned int*)PREDBLK_PTR_TUBUF_reg))
#define  PREDBLK_PTR_TUBUF_itc_shift                                             (24)
#define  PREDBLK_PTR_TUBUF_tuc_shift                                             (16)
#define  PREDBLK_PTR_TUBUF_puc_shift                                             (8)
#define  PREDBLK_PTR_TUBUF_com_shift                                             (0)
#define  PREDBLK_PTR_TUBUF_itc_mask                                              (0xFF000000)
#define  PREDBLK_PTR_TUBUF_tuc_mask                                              (0x00FF0000)
#define  PREDBLK_PTR_TUBUF_puc_mask                                              (0x0000FF00)
#define  PREDBLK_PTR_TUBUF_com_mask                                              (0x000000FF)
#define  PREDBLK_PTR_TUBUF_itc(data)                                             (0xFF000000&((data)<<24))
#define  PREDBLK_PTR_TUBUF_tuc(data)                                             (0x00FF0000&((data)<<16))
#define  PREDBLK_PTR_TUBUF_puc(data)                                             (0x0000FF00&((data)<<8))
#define  PREDBLK_PTR_TUBUF_com(data)                                             (0x000000FF&(data))
#define  PREDBLK_PTR_TUBUF_get_itc(data)                                         ((0xFF000000&(data))>>24)
#define  PREDBLK_PTR_TUBUF_get_tuc(data)                                         ((0x00FF0000&(data))>>16)
#define  PREDBLK_PTR_TUBUF_get_puc(data)                                         ((0x0000FF00&(data))>>8)
#define  PREDBLK_PTR_TUBUF_get_com(data)                                         (0x000000FF&(data))

#define  PREDBLK_DUMP_ADDR_0                                                     0x1800E9D0
#define  PREDBLK_DUMP_ADDR_0_reg_addr                                            "0xB800E9D0"
#define  PREDBLK_DUMP_ADDR_0_reg                                                 0xB800E9D0
#define  PREDBLK_DUMP_ADDR_0_inst_addr                                           "0x006F"
#define  set_PREDBLK_DUMP_ADDR_0_reg(data)                                       (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_0_reg)=data)
#define  get_PREDBLK_DUMP_ADDR_0_reg                                             (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_0_reg))
#define  PREDBLK_DUMP_ADDR_0_val_shift                                           (2)
#define  PREDBLK_DUMP_ADDR_0_val_mask                                            (0x7FFFFFFC)
#define  PREDBLK_DUMP_ADDR_0_val(data)                                           (0x7FFFFFFC&((data)<<2))
#define  PREDBLK_DUMP_ADDR_0_get_val(data)                                       ((0x7FFFFFFC&(data))>>2)

#define  PREDBLK_DUMP_ADDR_1                                                     0x1800E9D4
#define  PREDBLK_DUMP_ADDR_1_reg_addr                                            "0xB800E9D4"
#define  PREDBLK_DUMP_ADDR_1_reg                                                 0xB800E9D4
#define  PREDBLK_DUMP_ADDR_1_inst_addr                                           "0x0070"
#define  set_PREDBLK_DUMP_ADDR_1_reg(data)                                       (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_1_reg)=data)
#define  get_PREDBLK_DUMP_ADDR_1_reg                                             (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_1_reg))
#define  PREDBLK_DUMP_ADDR_1_val_shift                                           (2)
#define  PREDBLK_DUMP_ADDR_1_val_mask                                            (0x7FFFFFFC)
#define  PREDBLK_DUMP_ADDR_1_val(data)                                           (0x7FFFFFFC&((data)<<2))
#define  PREDBLK_DUMP_ADDR_1_get_val(data)                                       ((0x7FFFFFFC&(data))>>2)

#define  PREDBLK_HEVC_FRAME                                                      0x1800E9D8
#define  PREDBLK_HEVC_FRAME_reg_addr                                             "0xB800E9D8"
#define  PREDBLK_HEVC_FRAME_reg                                                  0xB800E9D8
#define  PREDBLK_HEVC_FRAME_inst_addr                                            "0x0071"
#define  set_PREDBLK_HEVC_FRAME_reg(data)                                        (*((volatile unsigned int*)PREDBLK_HEVC_FRAME_reg)=data)
#define  get_PREDBLK_HEVC_FRAME_reg                                              (*((volatile unsigned int*)PREDBLK_HEVC_FRAME_reg))
#define  PREDBLK_HEVC_FRAME_count_shift                                          (0)
#define  PREDBLK_HEVC_FRAME_count_mask                                           (0x0FFFFFFF)
#define  PREDBLK_HEVC_FRAME_count(data)                                          (0x0FFFFFFF&(data))
#define  PREDBLK_HEVC_FRAME_get_count(data)                                      (0x0FFFFFFF&(data))

#define  PREDBLK_HEVC_CTB                                                        0x1800E9DC
#define  PREDBLK_HEVC_CTB_reg_addr                                               "0xB800E9DC"
#define  PREDBLK_HEVC_CTB_reg                                                    0xB800E9DC
#define  PREDBLK_HEVC_CTB_inst_addr                                              "0x0072"
#define  set_PREDBLK_HEVC_CTB_reg(data)                                          (*((volatile unsigned int*)PREDBLK_HEVC_CTB_reg)=data)
#define  get_PREDBLK_HEVC_CTB_reg                                                (*((volatile unsigned int*)PREDBLK_HEVC_CTB_reg))
#define  PREDBLK_HEVC_CTB_count_shift                                            (0)
#define  PREDBLK_HEVC_CTB_count_mask                                             (0x0003FFFF)
#define  PREDBLK_HEVC_CTB_count(data)                                            (0x0003FFFF&(data))
#define  PREDBLK_HEVC_CTB_get_count(data)                                        (0x0003FFFF&(data))

#define  PREDBLK_DBUS4                                                           0x1800E9E0
#define  PREDBLK_DBUS4_reg_addr                                                  "0xB800E9E0"
#define  PREDBLK_DBUS4_reg                                                       0xB800E9E0
#define  PREDBLK_DBUS4_inst_addr                                                 "0x0073"
#define  set_PREDBLK_DBUS4_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS4_reg)=data)
#define  get_PREDBLK_DBUS4_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS4_reg))
#define  PREDBLK_DBUS4_tbd_shift                                                 (18)
#define  PREDBLK_DBUS4_ctbx_shift                                                (9)
#define  PREDBLK_DBUS4_ctby_shift                                                (0)
#define  PREDBLK_DBUS4_tbd_mask                                                  (0xFFFC0000)
#define  PREDBLK_DBUS4_ctbx_mask                                                 (0x0003FE00)
#define  PREDBLK_DBUS4_ctby_mask                                                 (0x000001FF)
#define  PREDBLK_DBUS4_tbd(data)                                                 (0xFFFC0000&((data)<<18))
#define  PREDBLK_DBUS4_ctbx(data)                                                (0x0003FE00&((data)<<9))
#define  PREDBLK_DBUS4_ctby(data)                                                (0x000001FF&(data))
#define  PREDBLK_DBUS4_get_tbd(data)                                             ((0xFFFC0000&(data))>>18)
#define  PREDBLK_DBUS4_get_ctbx(data)                                            ((0x0003FE00&(data))>>9)
#define  PREDBLK_DBUS4_get_ctby(data)                                            (0x000001FF&(data))

#define  PREDBLK_DBUS5                                                           0x1800E9E4
#define  PREDBLK_DBUS5_reg_addr                                                  "0xB800E9E4"
#define  PREDBLK_DBUS5_reg                                                       0xB800E9E4
#define  PREDBLK_DBUS5_inst_addr                                                 "0x0074"
#define  set_PREDBLK_DBUS5_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS5_reg)=data)
#define  get_PREDBLK_DBUS5_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS5_reg))
#define  PREDBLK_DBUS5_tbd_shift                                                 (0)
#define  PREDBLK_DBUS5_tbd_mask                                                  (0xFFFFFFFF)
#define  PREDBLK_DBUS5_tbd(data)                                                 (0xFFFFFFFF&(data))
#define  PREDBLK_DBUS5_get_tbd(data)                                             (0xFFFFFFFF&(data))

#define  PREDBLK_RMPTR0                                                          0x1800E9E8
#define  PREDBLK_RMPTR0_reg_addr                                                 "0xB800E9E8"
#define  PREDBLK_RMPTR0_reg                                                      0xB800E9E8
#define  PREDBLK_RMPTR0_inst_addr                                                "0x0075"
#define  set_PREDBLK_RMPTR0_reg(data)                                            (*((volatile unsigned int*)PREDBLK_RMPTR0_reg)=data)
#define  get_PREDBLK_RMPTR0_reg                                                  (*((volatile unsigned int*)PREDBLK_RMPTR0_reg))
#define  PREDBLK_RMPTR0_large_enough_shift                                       (29)
#define  PREDBLK_RMPTR0_require_shift                                            (22)
#define  PREDBLK_RMPTR0_wrptr_shift                                              (11)
#define  PREDBLK_RMPTR0_rdptr_shift                                              (0)
#define  PREDBLK_RMPTR0_large_enough_mask                                        (0x20000000)
#define  PREDBLK_RMPTR0_require_mask                                             (0x1FC00000)
#define  PREDBLK_RMPTR0_wrptr_mask                                               (0x003FF800)
#define  PREDBLK_RMPTR0_rdptr_mask                                               (0x000007FF)
#define  PREDBLK_RMPTR0_large_enough(data)                                       (0x20000000&((data)<<29))
#define  PREDBLK_RMPTR0_require(data)                                            (0x1FC00000&((data)<<22))
#define  PREDBLK_RMPTR0_wrptr(data)                                              (0x003FF800&((data)<<11))
#define  PREDBLK_RMPTR0_rdptr(data)                                              (0x000007FF&(data))
#define  PREDBLK_RMPTR0_get_large_enough(data)                                   ((0x20000000&(data))>>29)
#define  PREDBLK_RMPTR0_get_require(data)                                        ((0x1FC00000&(data))>>22)
#define  PREDBLK_RMPTR0_get_wrptr(data)                                          ((0x003FF800&(data))>>11)
#define  PREDBLK_RMPTR0_get_rdptr(data)                                          (0x000007FF&(data))

#define  PREDBLK_RMPTR1                                                          0x1800E9EC
#define  PREDBLK_RMPTR1_reg_addr                                                 "0xB800E9EC"
#define  PREDBLK_RMPTR1_reg                                                      0xB800E9EC
#define  PREDBLK_RMPTR1_inst_addr                                                "0x0076"
#define  set_PREDBLK_RMPTR1_reg(data)                                            (*((volatile unsigned int*)PREDBLK_RMPTR1_reg)=data)
#define  get_PREDBLK_RMPTR1_reg                                                  (*((volatile unsigned int*)PREDBLK_RMPTR1_reg))
#define  PREDBLK_RMPTR1_msb_shift                                                (11)
#define  PREDBLK_RMPTR1_rdptr_shift                                              (0)
#define  PREDBLK_RMPTR1_msb_mask                                                 (0x00003800)
#define  PREDBLK_RMPTR1_rdptr_mask                                               (0x000007FF)
#define  PREDBLK_RMPTR1_msb(data)                                                (0x00003800&((data)<<11))
#define  PREDBLK_RMPTR1_rdptr(data)                                              (0x000007FF&(data))
#define  PREDBLK_RMPTR1_get_msb(data)                                            ((0x00003800&(data))>>11)
#define  PREDBLK_RMPTR1_get_rdptr(data)                                          (0x000007FF&(data))

#define  PREDBLK_HEVCSB                                                          0x1800E9F8
#define  PREDBLK_HEVCSB_reg_addr                                                 "0xB800E9F8"
#define  PREDBLK_HEVCSB_reg                                                      0xB800E9F8
#define  PREDBLK_HEVCSB_inst_addr                                                "0x0077"
#define  set_PREDBLK_HEVCSB_reg(data)                                            (*((volatile unsigned int*)PREDBLK_HEVCSB_reg)=data)
#define  get_PREDBLK_HEVCSB_reg                                                  (*((volatile unsigned int*)PREDBLK_HEVCSB_reg))
#define  PREDBLK_HEVCSB_startaddr_shift                                          (0)
#define  PREDBLK_HEVCSB_startaddr_mask                                           (0x0000007F)
#define  PREDBLK_HEVCSB_startaddr(data)                                          (0x0000007F&(data))
#define  PREDBLK_HEVCSB_get_startaddr(data)                                      (0x0000007F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PREDBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  nhmem_flush:1;
        RBus_UInt32  rmem_rst:1;
        RBus_UInt32  deblk_xsfer_mode:1;
        RBus_UInt32  debug_mode:1;
        RBus_UInt32  fmo:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  softrst_disable:1;
        RBus_UInt32  new_slice_row:1;
        RBus_UInt32  new_slice_mb_x:9;
        RBus_UInt32  sw_neighbor_enable:1;
        RBus_UInt32  mbaddra_available:1;
        RBus_UInt32  mbaddrb_available:1;
        RBus_UInt32  mbaddrc_available:1;
        RBus_UInt32  mbaddrd_available:1;
    };
}predblk_neighbor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ic_mix_fcm_enable:1;
        RBus_UInt32  condover:2;
        RBus_UInt32  rnd_ctrl_ovt:1;
        RBus_UInt32  rnd:1;
        RBus_UInt32  intcomp:1;
        RBus_UInt32  lumscale0:6;
        RBus_UInt32  lumshift0:6;
    };
}predblk_vc1intc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_pass0_of_fwd:4;
        RBus_UInt32  ic_pass1_of_fwd:4;
        RBus_UInt32  ic_pass0_sf_fwd:4;
        RBus_UInt32  ic_pass1_sf_fwd:4;
        RBus_UInt32  ic_pass0_of_bwd:4;
        RBus_UInt32  ic_pass1_of_bwd:4;
        RBus_UInt32  ic_pass0_sf_bwd:4;
        RBus_UInt32  ic_pass1_sf_bwd:4;
    };
}predblk_vc1intc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lumscale1:6;
        RBus_UInt32  lumshift1:6;
        RBus_UInt32  lumscale2:6;
        RBus_UInt32  lumshift2:6;
    };
}predblk_vc1intc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  lumscale3:6;
        RBus_UInt32  lumshift3:6;
        RBus_UInt32  lumscale4:6;
        RBus_UInt32  lumshift4:6;
    };
}predblk_vc1intc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}predblk_nbintra0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}predblk_nbintra1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}predblk_nbintrach_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_overflag_flag:32;
    };
}predblk_nbfieldov_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  intra0:1;
        RBus_UInt32  intra1:1;
        RBus_UInt32  intrachroma:1;
        RBus_UInt32  intrafield:1;
    };
}predblk_nbextra_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  wtbl_starta:10;
    };
}predblk_wtblsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wt_flag:32;
    };
}predblk_wtflag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdone_enable:1;
        RBus_UInt32  mem_eng_busy:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  seq_line_addr:29;
    };
}predblk_sdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  value:28;
    };
}predblk_intr_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reach_thresh:1;
        RBus_UInt32  count:28;
    };
}predblk_busy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  basea0:7;
        RBus_UInt32  res2:6;
        RBus_UInt32  basea1:7;
        RBus_UInt32  res3:3;
    };
}predblk_basea_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  offseta:7;
        RBus_UInt32  res2:3;
    };
}predblk_offseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  starta:7;
    };
}predblk_debpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  rounding_control:1;
        RBus_UInt32  quarter_sample:1;
    };
}predblk_mpegctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  base_addr:26;
        RBus_UInt32  res2:3;
    };
}predblk_rmemddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbcnt_threshold:32;
    };
}predblk_rmemddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  valid:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  start_addr:7;
        RBus_UInt32  end_addr:7;
    };
}predblk_rmemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  uratio:15;
    };
}predblk_uratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  genpulse:1;
        RBus_UInt32  piccount:14;
        RBus_UInt32  mbaddrx:9;
        RBus_UInt32  mbaddry:8;
    };
}predblk_dbus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:32;
    };
}predblk_dbus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl3:29;
        RBus_UInt32  dbgctrl:3;
    };
}predblk_dbus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sdmawr1msb:1;
        RBus_UInt32  sdma2msb:3;
        RBus_UInt32  rmem2msb:3;
    };
}predblk_dmamsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  baseaddr:12;
    };
}predblk_dmemadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  count:28;
    };
}predblk_dmemop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_enable:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  pmem_idle:1;
    };
}predblk_slice_restart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_override:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  ddr_inb_rdadr:4;
        RBus_UInt32  ddr_out_rdadr:6;
        RBus_UInt32  inb_mbcnt:4;
        RBus_UInt32  out_mbcnt:4;
        RBus_UInt32  pmem_inb_mbptr:4;
        RBus_UInt32  pmem_out_mbptr:3;
    };
}predblk_slice_dbg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ddr_rng_rdptr:10;
        RBus_UInt32  ddr_rng_wrptr:10;
        RBus_UInt32  ddr_rng_size:10;
    };
}predblk_slice_dbg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  on:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  bank0:4;
        RBus_UInt32  bank1:4;
        RBus_UInt32  bank2:4;
        RBus_UInt32  bank3:4;
    };
}predblk_conflict_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dma:2;
        RBus_UInt32  ime:2;
        RBus_UInt32  fme:2;
        RBus_UInt32  gcf:2;
    };
}predblk_encumem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  um_dbg_en:1;
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  bank5_owner:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  bank4_owner:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  bank3_owner:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  bank2_owner:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  bank1_owner:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  bank0_owner:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  itblk_bank:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  pred_bank:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  umem_init:1;
    };
}predblk_hevc_umem_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  bank9_owner:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  bank8_owner:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  bank7_owner:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bank6_owner:1;
    };
}predblk_hevc_umem_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  seq_line_addr:31;
    };
}predblk_sdmawradr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  reset:1;
        RBus_UInt32  start:1;
    };
}predblk_deccntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tenbit:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  vp9_enable:1;
        RBus_UInt32  mvbuf_dump_enable:1;
        RBus_UInt32  itblk_dump_enable:1;
        RBus_UInt32  itblk_dt:1;
        RBus_UInt32  hevc_enable:1;
    };
}predblk_hevccntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}predblk_hvrmemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  rmem_count:6;
        RBus_UInt32  pred_op_go:1;
        RBus_UInt32  rmem_dump_go:1;
        RBus_UInt32  ldumem_go:1;
        RBus_UInt32  stumem_go:1;
    };
}predblk_hevc_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}predblk_ldumemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}predblk_stumemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  tu_dbg_en:1;
        RBus_UInt32  rden:1;
        RBus_UInt32  wren:1;
        RBus_UInt32  addr:6;
        RBus_UInt32  data:22;
    };
}predblk_dbg_tubuf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itc:8;
        RBus_UInt32  tuc:8;
        RBus_UInt32  puc:8;
        RBus_UInt32  com:8;
    };
}predblk_ptr_tubuf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  val:29;
        RBus_UInt32  res2:2;
    };
}predblk_dump_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  count:28;
    };
}predblk_hevc_frame_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  count:18;
    };
}predblk_hevc_ctb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbd:14;
        RBus_UInt32  ctbx:9;
        RBus_UInt32  ctby:9;
    };
}predblk_dbus4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbd:32;
    };
}predblk_dbus5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  large_enough:1;
        RBus_UInt32  require:7;
        RBus_UInt32  wrptr:11;
        RBus_UInt32  rdptr:11;
    };
}predblk_rmptr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  msb:3;
        RBus_UInt32  rdptr:11;
    };
}predblk_rmptr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  startaddr:7;
    };
}predblk_hevcsb_RBUS;

#else //apply LITTLE_ENDIAN

//======PREDBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddrd_available:1;
        RBus_UInt32  mbaddrc_available:1;
        RBus_UInt32  mbaddrb_available:1;
        RBus_UInt32  mbaddra_available:1;
        RBus_UInt32  sw_neighbor_enable:1;
        RBus_UInt32  new_slice_mb_x:9;
        RBus_UInt32  new_slice_row:1;
        RBus_UInt32  softrst_disable:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  fmo:1;
        RBus_UInt32  debug_mode:1;
        RBus_UInt32  deblk_xsfer_mode:1;
        RBus_UInt32  rmem_rst:1;
        RBus_UInt32  nhmem_flush:1;
        RBus_UInt32  res2:7;
    };
}predblk_neighbor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lumshift0:6;
        RBus_UInt32  lumscale0:6;
        RBus_UInt32  intcomp:1;
        RBus_UInt32  rnd:1;
        RBus_UInt32  rnd_ctrl_ovt:1;
        RBus_UInt32  condover:2;
        RBus_UInt32  ic_mix_fcm_enable:1;
        RBus_UInt32  res1:14;
    };
}predblk_vc1intc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ic_pass1_sf_bwd:4;
        RBus_UInt32  ic_pass0_sf_bwd:4;
        RBus_UInt32  ic_pass1_of_bwd:4;
        RBus_UInt32  ic_pass0_of_bwd:4;
        RBus_UInt32  ic_pass1_sf_fwd:4;
        RBus_UInt32  ic_pass0_sf_fwd:4;
        RBus_UInt32  ic_pass1_of_fwd:4;
        RBus_UInt32  ic_pass0_of_fwd:4;
    };
}predblk_vc1intc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lumshift2:6;
        RBus_UInt32  lumscale2:6;
        RBus_UInt32  lumshift1:6;
        RBus_UInt32  lumscale1:6;
        RBus_UInt32  res1:8;
    };
}predblk_vc1intc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lumshift4:6;
        RBus_UInt32  lumscale4:6;
        RBus_UInt32  lumshift3:6;
        RBus_UInt32  lumscale3:6;
        RBus_UInt32  res1:8;
    };
}predblk_vc1intc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}predblk_nbintra0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}predblk_nbintra1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}predblk_nbintrach_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_overflag_flag:32;
    };
}predblk_nbfieldov_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intrafield:1;
        RBus_UInt32  intrachroma:1;
        RBus_UInt32  intra1:1;
        RBus_UInt32  intra0:1;
        RBus_UInt32  res1:28;
    };
}predblk_nbextra_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtbl_starta:10;
        RBus_UInt32  res1:22;
    };
}predblk_wtblsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wt_flag:32;
    };
}predblk_wtflag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:29;
        RBus_UInt32  res1:1;
        RBus_UInt32  mem_eng_busy:1;
        RBus_UInt32  wdone_enable:1;
    };
}predblk_sdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  value:28;
        RBus_UInt32  res1:4;
    };
}predblk_intr_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:28;
        RBus_UInt32  reach_thresh:1;
        RBus_UInt32  res1:3;
    };
}predblk_busy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  basea1:7;
        RBus_UInt32  res2:6;
        RBus_UInt32  basea0:7;
        RBus_UInt32  res3:9;
    };
}predblk_basea_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  offseta:7;
        RBus_UInt32  res2:22;
    };
}predblk_offseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  starta:7;
        RBus_UInt32  res1:25;
    };
}predblk_debpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  quarter_sample:1;
        RBus_UInt32  rounding_control:1;
        RBus_UInt32  res1:30;
    };
}predblk_mpegctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  base_addr:26;
        RBus_UInt32  res2:2;
        RBus_UInt32  valid:1;
    };
}predblk_rmemddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbcnt_threshold:32;
    };
}predblk_rmemddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  end_addr:7;
        RBus_UInt32  start_addr:7;
        RBus_UInt32  res1:17;
        RBus_UInt32  valid:1;
    };
}predblk_rmemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uratio:15;
        RBus_UInt32  res1:17;
    };
}predblk_uratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddry:8;
        RBus_UInt32  mbaddrx:9;
        RBus_UInt32  piccount:14;
        RBus_UInt32  genpulse:1;
    };
}predblk_dbus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:32;
    };
}predblk_dbus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbgctrl:3;
        RBus_UInt32  dbgctrl3:29;
    };
}predblk_dbus3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rmem2msb:3;
        RBus_UInt32  sdma2msb:3;
        RBus_UInt32  sdmawr1msb:1;
        RBus_UInt32  res1:25;
    };
}predblk_dmamsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  baseaddr:12;
        RBus_UInt32  res1:20;
    };
}predblk_dmemadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:28;
        RBus_UInt32  res1:4;
    };
}predblk_dmemop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pmem_idle:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  hw_enable:1;
    };
}predblk_slice_restart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pmem_out_mbptr:3;
        RBus_UInt32  pmem_inb_mbptr:4;
        RBus_UInt32  out_mbcnt:4;
        RBus_UInt32  inb_mbcnt:4;
        RBus_UInt32  ddr_out_rdadr:6;
        RBus_UInt32  ddr_inb_rdadr:4;
        RBus_UInt32  res1:6;
        RBus_UInt32  sw_override:1;
    };
}predblk_slice_dbg0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_rng_size:10;
        RBus_UInt32  ddr_rng_wrptr:10;
        RBus_UInt32  ddr_rng_rdptr:10;
        RBus_UInt32  res1:2;
    };
}predblk_slice_dbg1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bank3:4;
        RBus_UInt32  bank2:4;
        RBus_UInt32  bank1:4;
        RBus_UInt32  bank0:4;
        RBus_UInt32  res1:15;
        RBus_UInt32  on:1;
    };
}predblk_conflict_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gcf:2;
        RBus_UInt32  fme:2;
        RBus_UInt32  ime:2;
        RBus_UInt32  dma:2;
        RBus_UInt32  res1:24;
    };
}predblk_encumem_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  umem_init:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  pred_bank:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  itblk_bank:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  bank0_owner:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  bank1_owner:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  bank2_owner:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  bank3_owner:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  bank4_owner:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  bank5_owner:1;
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  um_dbg_en:1;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  res1:6;
    };
}predblk_hevc_umem_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bank6_owner:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  bank7_owner:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  bank8_owner:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  bank9_owner:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:24;
    };
}predblk_hevc_umem_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:31;
        RBus_UInt32  enable:1;
    };
}predblk_sdmawradr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start:1;
        RBus_UInt32  reset:1;
        RBus_UInt32  res1:30;
    };
}predblk_deccntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hevc_enable:1;
        RBus_UInt32  itblk_dt:1;
        RBus_UInt32  itblk_dump_enable:1;
        RBus_UInt32  mvbuf_dump_enable:1;
        RBus_UInt32  vp9_enable:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  tenbit:1;
    };
}predblk_hevccntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}predblk_hvrmemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stumem_go:1;
        RBus_UInt32  ldumem_go:1;
        RBus_UInt32  rmem_dump_go:1;
        RBus_UInt32  pred_op_go:1;
        RBus_UInt32  rmem_count:6;
        RBus_UInt32  res1:22;
    };
}predblk_hevc_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}predblk_ldumemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}predblk_stumemctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:22;
        RBus_UInt32  addr:6;
        RBus_UInt32  wren:1;
        RBus_UInt32  rden:1;
        RBus_UInt32  tu_dbg_en:1;
        RBus_UInt32  res1:1;
    };
}predblk_dbg_tubuf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  com:8;
        RBus_UInt32  puc:8;
        RBus_UInt32  tuc:8;
        RBus_UInt32  itc:8;
    };
}predblk_ptr_tubuf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  val:29;
        RBus_UInt32  res2:1;
    };
}predblk_dump_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:28;
        RBus_UInt32  res1:4;
    };
}predblk_hevc_frame_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:18;
        RBus_UInt32  res1:14;
    };
}predblk_hevc_ctb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctby:9;
        RBus_UInt32  ctbx:9;
        RBus_UInt32  tbd:14;
    };
}predblk_dbus4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbd:32;
    };
}predblk_dbus5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:11;
        RBus_UInt32  wrptr:11;
        RBus_UInt32  require:7;
        RBus_UInt32  large_enough:1;
        RBus_UInt32  res1:2;
    };
}predblk_rmptr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:11;
        RBus_UInt32  msb:3;
        RBus_UInt32  res1:18;
    };
}predblk_rmptr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startaddr:7;
        RBus_UInt32  res1:25;
    };
}predblk_hevcsb_RBUS;




#endif 


#endif 
