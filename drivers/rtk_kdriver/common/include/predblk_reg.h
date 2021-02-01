/**
* @file rbusPredblkReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PREDBLK_REG_H_
#define _RBUS_PREDBLK_REG_H_

#include "rbusTypes.h"



//  PREDBLK Register Address
#define  PREDBLK_NEIGHBOR                                                        0x1800E800
#define  PREDBLK_NEIGHBOR_reg_addr                                               "0xB800E800"
#define  PREDBLK_NEIGHBOR_reg                                                    0xB800E800
#define  PREDBLK_NEIGHBOR_inst_addr                                              "0x0000"
#define  PREDBLK_NEIGHBOR_inst_adr                                               "0x0000"
#define  PREDBLK_NEIGHBOR_inst                                                   0x0000
#define  set_PREDBLK_NEIGHBOR_reg(data)                                          (*((volatile unsigned int*)PREDBLK_NEIGHBOR_reg)=data)
#define  get_PREDBLK_NEIGHBOR_reg                                                (*((volatile unsigned int*)PREDBLK_NEIGHBOR_reg))
#define  PREDBLK_NEIGHBOR_Nhmem_Flush_shift                                      (24)
#define  PREDBLK_NEIGHBOR_RMEM_Rst_shift                                         (23)
#define  PREDBLK_NEIGHBOR_Deblk_xsfer_mode_shift                                 (22)
#define  PREDBLK_NEIGHBOR_Debug_mode_shift                                       (21)
#define  PREDBLK_NEIGHBOR_fmo_shift                                              (20)
#define  PREDBLK_NEIGHBOR_Softrst_disable_shift                                  (15)
#define  PREDBLK_NEIGHBOR_New_slice_row_shift                                    (14)
#define  PREDBLK_NEIGHBOR_New_slice_mb_x_shift                                   (5)
#define  PREDBLK_NEIGHBOR_Sw_neighbor_enable_shift                               (4)
#define  PREDBLK_NEIGHBOR_MbAddrA_available_shift                                (3)
#define  PREDBLK_NEIGHBOR_MbAddrB_available_shift                                (2)
#define  PREDBLK_NEIGHBOR_MbAddrC_available_shift                                (1)
#define  PREDBLK_NEIGHBOR_MbAddrD_available_shift                                (0)
#define  PREDBLK_NEIGHBOR_Nhmem_Flush_mask                                       (0x01000000)
#define  PREDBLK_NEIGHBOR_RMEM_Rst_mask                                          (0x00800000)
#define  PREDBLK_NEIGHBOR_Deblk_xsfer_mode_mask                                  (0x00400000)
#define  PREDBLK_NEIGHBOR_Debug_mode_mask                                        (0x00200000)
#define  PREDBLK_NEIGHBOR_fmo_mask                                               (0x00100000)
#define  PREDBLK_NEIGHBOR_Softrst_disable_mask                                   (0x00008000)
#define  PREDBLK_NEIGHBOR_New_slice_row_mask                                     (0x00004000)
#define  PREDBLK_NEIGHBOR_New_slice_mb_x_mask                                    (0x00003FE0)
#define  PREDBLK_NEIGHBOR_Sw_neighbor_enable_mask                                (0x00000010)
#define  PREDBLK_NEIGHBOR_MbAddrA_available_mask                                 (0x00000008)
#define  PREDBLK_NEIGHBOR_MbAddrB_available_mask                                 (0x00000004)
#define  PREDBLK_NEIGHBOR_MbAddrC_available_mask                                 (0x00000002)
#define  PREDBLK_NEIGHBOR_MbAddrD_available_mask                                 (0x00000001)
#define  PREDBLK_NEIGHBOR_Nhmem_Flush(data)                                      (0x01000000&((data)<<24))
#define  PREDBLK_NEIGHBOR_RMEM_Rst(data)                                         (0x00800000&((data)<<23))
#define  PREDBLK_NEIGHBOR_Deblk_xsfer_mode(data)                                 (0x00400000&((data)<<22))
#define  PREDBLK_NEIGHBOR_Debug_mode(data)                                       (0x00200000&((data)<<21))
#define  PREDBLK_NEIGHBOR_fmo(data)                                              (0x00100000&((data)<<20))
#define  PREDBLK_NEIGHBOR_Softrst_disable(data)                                  (0x00008000&((data)<<15))
#define  PREDBLK_NEIGHBOR_New_slice_row(data)                                    (0x00004000&((data)<<14))
#define  PREDBLK_NEIGHBOR_New_slice_mb_x(data)                                   (0x00003FE0&((data)<<5))
#define  PREDBLK_NEIGHBOR_Sw_neighbor_enable(data)                               (0x00000010&((data)<<4))
#define  PREDBLK_NEIGHBOR_MbAddrA_available(data)                                (0x00000008&((data)<<3))
#define  PREDBLK_NEIGHBOR_MbAddrB_available(data)                                (0x00000004&((data)<<2))
#define  PREDBLK_NEIGHBOR_MbAddrC_available(data)                                (0x00000002&((data)<<1))
#define  PREDBLK_NEIGHBOR_MbAddrD_available(data)                                (0x00000001&(data))
#define  PREDBLK_NEIGHBOR_get_Nhmem_Flush(data)                                  ((0x01000000&(data))>>24)
#define  PREDBLK_NEIGHBOR_get_RMEM_Rst(data)                                     ((0x00800000&(data))>>23)
#define  PREDBLK_NEIGHBOR_get_Deblk_xsfer_mode(data)                             ((0x00400000&(data))>>22)
#define  PREDBLK_NEIGHBOR_get_Debug_mode(data)                                   ((0x00200000&(data))>>21)
#define  PREDBLK_NEIGHBOR_get_fmo(data)                                          ((0x00100000&(data))>>20)
#define  PREDBLK_NEIGHBOR_get_Softrst_disable(data)                              ((0x00008000&(data))>>15)
#define  PREDBLK_NEIGHBOR_get_New_slice_row(data)                                ((0x00004000&(data))>>14)
#define  PREDBLK_NEIGHBOR_get_New_slice_mb_x(data)                               ((0x00003FE0&(data))>>5)
#define  PREDBLK_NEIGHBOR_get_Sw_neighbor_enable(data)                           ((0x00000010&(data))>>4)
#define  PREDBLK_NEIGHBOR_get_MbAddrA_available(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_NEIGHBOR_get_MbAddrB_available(data)                            ((0x00000004&(data))>>2)
#define  PREDBLK_NEIGHBOR_get_MbAddrC_available(data)                            ((0x00000002&(data))>>1)
#define  PREDBLK_NEIGHBOR_get_MbAddrD_available(data)                            (0x00000001&(data))
#define  PREDBLK_NEIGHBOR_Nhmem_Flush_src(data)                                  ((0x01000000&(data))>>24)
#define  PREDBLK_NEIGHBOR_RMEM_Rst_src(data)                                     ((0x00800000&(data))>>23)
#define  PREDBLK_NEIGHBOR_Deblk_xsfer_mode_src(data)                             ((0x00400000&(data))>>22)
#define  PREDBLK_NEIGHBOR_Debug_mode_src(data)                                   ((0x00200000&(data))>>21)
#define  PREDBLK_NEIGHBOR_fmo_src(data)                                          ((0x00100000&(data))>>20)
#define  PREDBLK_NEIGHBOR_Softrst_disable_src(data)                              ((0x00008000&(data))>>15)
#define  PREDBLK_NEIGHBOR_New_slice_row_src(data)                                ((0x00004000&(data))>>14)
#define  PREDBLK_NEIGHBOR_New_slice_mb_x_src(data)                               ((0x00003FE0&(data))>>5)
#define  PREDBLK_NEIGHBOR_Sw_neighbor_enable_src(data)                           ((0x00000010&(data))>>4)
#define  PREDBLK_NEIGHBOR_MbAddrA_available_src(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_NEIGHBOR_MbAddrB_available_src(data)                            ((0x00000004&(data))>>2)
#define  PREDBLK_NEIGHBOR_MbAddrC_available_src(data)                            ((0x00000002&(data))>>1)
#define  PREDBLK_NEIGHBOR_MbAddrD_available_src(data)                            (0x00000001&(data))

#define  PREDBLK_VC1INTC1                                                        0x1800E804
#define  PREDBLK_VC1INTC1_reg_addr                                               "0xB800E804"
#define  PREDBLK_VC1INTC1_reg                                                    0xB800E804
#define  PREDBLK_VC1INTC1_inst_addr                                              "0x0001"
#define  PREDBLK_VC1INTC1_inst_adr                                               "0x0001"
#define  PREDBLK_VC1INTC1_inst                                                   0x0001
#define  set_PREDBLK_VC1INTC1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC1_reg)=data)
#define  get_PREDBLK_VC1INTC1_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC1_reg))
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable_shift                                (17)
#define  PREDBLK_VC1INTC1_CONDOVER_shift                                         (15)
#define  PREDBLK_VC1INTC1_Rnd_ctrl_ovt_shift                                     (14)
#define  PREDBLK_VC1INTC1_RND_shift                                              (13)
#define  PREDBLK_VC1INTC1_INTCOMP_shift                                          (12)
#define  PREDBLK_VC1INTC1_LUMSCALE0_shift                                        (6)
#define  PREDBLK_VC1INTC1_LUMSHIFT0_shift                                        (0)
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable_mask                                 (0x00020000)
#define  PREDBLK_VC1INTC1_CONDOVER_mask                                          (0x00018000)
#define  PREDBLK_VC1INTC1_Rnd_ctrl_ovt_mask                                      (0x00004000)
#define  PREDBLK_VC1INTC1_RND_mask                                               (0x00002000)
#define  PREDBLK_VC1INTC1_INTCOMP_mask                                           (0x00001000)
#define  PREDBLK_VC1INTC1_LUMSCALE0_mask                                         (0x00000FC0)
#define  PREDBLK_VC1INTC1_LUMSHIFT0_mask                                         (0x0000003F)
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable(data)                                (0x00020000&((data)<<17))
#define  PREDBLK_VC1INTC1_CONDOVER(data)                                         (0x00018000&((data)<<15))
#define  PREDBLK_VC1INTC1_Rnd_ctrl_ovt(data)                                     (0x00004000&((data)<<14))
#define  PREDBLK_VC1INTC1_RND(data)                                              (0x00002000&((data)<<13))
#define  PREDBLK_VC1INTC1_INTCOMP(data)                                          (0x00001000&((data)<<12))
#define  PREDBLK_VC1INTC1_LUMSCALE0(data)                                        (0x00000FC0&((data)<<6))
#define  PREDBLK_VC1INTC1_LUMSHIFT0(data)                                        (0x0000003F&(data))
#define  PREDBLK_VC1INTC1_get_ic_mix_fcm_enable(data)                            ((0x00020000&(data))>>17)
#define  PREDBLK_VC1INTC1_get_CONDOVER(data)                                     ((0x00018000&(data))>>15)
#define  PREDBLK_VC1INTC1_get_Rnd_ctrl_ovt(data)                                 ((0x00004000&(data))>>14)
#define  PREDBLK_VC1INTC1_get_RND(data)                                          ((0x00002000&(data))>>13)
#define  PREDBLK_VC1INTC1_get_INTCOMP(data)                                      ((0x00001000&(data))>>12)
#define  PREDBLK_VC1INTC1_get_LUMSCALE0(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC1_get_LUMSHIFT0(data)                                    (0x0000003F&(data))
#define  PREDBLK_VC1INTC1_ic_mix_fcm_enable_src(data)                            ((0x00020000&(data))>>17)
#define  PREDBLK_VC1INTC1_CONDOVER_src(data)                                     ((0x00018000&(data))>>15)
#define  PREDBLK_VC1INTC1_Rnd_ctrl_ovt_src(data)                                 ((0x00004000&(data))>>14)
#define  PREDBLK_VC1INTC1_RND_src(data)                                          ((0x00002000&(data))>>13)
#define  PREDBLK_VC1INTC1_INTCOMP_src(data)                                      ((0x00001000&(data))>>12)
#define  PREDBLK_VC1INTC1_LUMSCALE0_src(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC1_LUMSHIFT0_src(data)                                    (0x0000003F&(data))

#define  PREDBLK_VC1INTC2                                                        0x1800E808
#define  PREDBLK_VC1INTC2_reg_addr                                               "0xB800E808"
#define  PREDBLK_VC1INTC2_reg                                                    0xB800E808
#define  PREDBLK_VC1INTC2_inst_addr                                              "0x0002"
#define  PREDBLK_VC1INTC2_inst_adr                                               "0x0002"
#define  PREDBLK_VC1INTC2_inst                                                   0x0002
#define  set_PREDBLK_VC1INTC2_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC2_reg)=data)
#define  get_PREDBLK_VC1INTC2_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC2_reg))
#define  PREDBLK_VC1INTC2_Ic_pass0_of_fwd_shift                                  (28)
#define  PREDBLK_VC1INTC2_Ic_pass1_of_fwd_shift                                  (24)
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_fwd_shift                                  (20)
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_fwd_shift                                  (16)
#define  PREDBLK_VC1INTC2_Ic_pass0_of_bwd_shift                                  (12)
#define  PREDBLK_VC1INTC2_Ic_pass1_of_bwd_shift                                  (8)
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_bwd_shift                                  (4)
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_bwd_shift                                  (0)
#define  PREDBLK_VC1INTC2_Ic_pass0_of_fwd_mask                                   (0xF0000000)
#define  PREDBLK_VC1INTC2_Ic_pass1_of_fwd_mask                                   (0x0F000000)
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_fwd_mask                                   (0x00F00000)
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_fwd_mask                                   (0x000F0000)
#define  PREDBLK_VC1INTC2_Ic_pass0_of_bwd_mask                                   (0x0000F000)
#define  PREDBLK_VC1INTC2_Ic_pass1_of_bwd_mask                                   (0x00000F00)
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_bwd_mask                                   (0x000000F0)
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_bwd_mask                                   (0x0000000F)
#define  PREDBLK_VC1INTC2_Ic_pass0_of_fwd(data)                                  (0xF0000000&((data)<<28))
#define  PREDBLK_VC1INTC2_Ic_pass1_of_fwd(data)                                  (0x0F000000&((data)<<24))
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_fwd(data)                                  (0x00F00000&((data)<<20))
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_fwd(data)                                  (0x000F0000&((data)<<16))
#define  PREDBLK_VC1INTC2_Ic_pass0_of_bwd(data)                                  (0x0000F000&((data)<<12))
#define  PREDBLK_VC1INTC2_Ic_pass1_of_bwd(data)                                  (0x00000F00&((data)<<8))
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_bwd(data)                                  (0x000000F0&((data)<<4))
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_bwd(data)                                  (0x0000000F&(data))
#define  PREDBLK_VC1INTC2_get_Ic_pass0_of_fwd(data)                              ((0xF0000000&(data))>>28)
#define  PREDBLK_VC1INTC2_get_Ic_pass1_of_fwd(data)                              ((0x0F000000&(data))>>24)
#define  PREDBLK_VC1INTC2_get_Ic_pass0_sf_fwd(data)                              ((0x00F00000&(data))>>20)
#define  PREDBLK_VC1INTC2_get_Ic_pass1_sf_fwd(data)                              ((0x000F0000&(data))>>16)
#define  PREDBLK_VC1INTC2_get_Ic_pass0_of_bwd(data)                              ((0x0000F000&(data))>>12)
#define  PREDBLK_VC1INTC2_get_Ic_pass1_of_bwd(data)                              ((0x00000F00&(data))>>8)
#define  PREDBLK_VC1INTC2_get_Ic_pass0_sf_bwd(data)                              ((0x000000F0&(data))>>4)
#define  PREDBLK_VC1INTC2_get_Ic_pass1_sf_bwd(data)                              (0x0000000F&(data))
#define  PREDBLK_VC1INTC2_Ic_pass0_of_fwd_src(data)                              ((0xF0000000&(data))>>28)
#define  PREDBLK_VC1INTC2_Ic_pass1_of_fwd_src(data)                              ((0x0F000000&(data))>>24)
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_fwd_src(data)                              ((0x00F00000&(data))>>20)
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_fwd_src(data)                              ((0x000F0000&(data))>>16)
#define  PREDBLK_VC1INTC2_Ic_pass0_of_bwd_src(data)                              ((0x0000F000&(data))>>12)
#define  PREDBLK_VC1INTC2_Ic_pass1_of_bwd_src(data)                              ((0x00000F00&(data))>>8)
#define  PREDBLK_VC1INTC2_Ic_pass0_sf_bwd_src(data)                              ((0x000000F0&(data))>>4)
#define  PREDBLK_VC1INTC2_Ic_pass1_sf_bwd_src(data)                              (0x0000000F&(data))

#define  PREDBLK_VC1INTC3                                                        0x1800E80C
#define  PREDBLK_VC1INTC3_reg_addr                                               "0xB800E80C"
#define  PREDBLK_VC1INTC3_reg                                                    0xB800E80C
#define  PREDBLK_VC1INTC3_inst_addr                                              "0x0003"
#define  PREDBLK_VC1INTC3_inst_adr                                               "0x0003"
#define  PREDBLK_VC1INTC3_inst                                                   0x0003
#define  set_PREDBLK_VC1INTC3_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC3_reg)=data)
#define  get_PREDBLK_VC1INTC3_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC3_reg))
#define  PREDBLK_VC1INTC3_LUMSCALE1_shift                                        (18)
#define  PREDBLK_VC1INTC3_LUMSHIFT1_shift                                        (12)
#define  PREDBLK_VC1INTC3_LUMSCALE2_shift                                        (6)
#define  PREDBLK_VC1INTC3_LUMSHIFT2_shift                                        (0)
#define  PREDBLK_VC1INTC3_LUMSCALE1_mask                                         (0x00FC0000)
#define  PREDBLK_VC1INTC3_LUMSHIFT1_mask                                         (0x0003F000)
#define  PREDBLK_VC1INTC3_LUMSCALE2_mask                                         (0x00000FC0)
#define  PREDBLK_VC1INTC3_LUMSHIFT2_mask                                         (0x0000003F)
#define  PREDBLK_VC1INTC3_LUMSCALE1(data)                                        (0x00FC0000&((data)<<18))
#define  PREDBLK_VC1INTC3_LUMSHIFT1(data)                                        (0x0003F000&((data)<<12))
#define  PREDBLK_VC1INTC3_LUMSCALE2(data)                                        (0x00000FC0&((data)<<6))
#define  PREDBLK_VC1INTC3_LUMSHIFT2(data)                                        (0x0000003F&(data))
#define  PREDBLK_VC1INTC3_get_LUMSCALE1(data)                                    ((0x00FC0000&(data))>>18)
#define  PREDBLK_VC1INTC3_get_LUMSHIFT1(data)                                    ((0x0003F000&(data))>>12)
#define  PREDBLK_VC1INTC3_get_LUMSCALE2(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC3_get_LUMSHIFT2(data)                                    (0x0000003F&(data))
#define  PREDBLK_VC1INTC3_LUMSCALE1_src(data)                                    ((0x00FC0000&(data))>>18)
#define  PREDBLK_VC1INTC3_LUMSHIFT1_src(data)                                    ((0x0003F000&(data))>>12)
#define  PREDBLK_VC1INTC3_LUMSCALE2_src(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC3_LUMSHIFT2_src(data)                                    (0x0000003F&(data))

#define  PREDBLK_VC1INTC4                                                        0x1800E810
#define  PREDBLK_VC1INTC4_reg_addr                                               "0xB800E810"
#define  PREDBLK_VC1INTC4_reg                                                    0xB800E810
#define  PREDBLK_VC1INTC4_inst_addr                                              "0x0004"
#define  PREDBLK_VC1INTC4_inst_adr                                               "0x0004"
#define  PREDBLK_VC1INTC4_inst                                                   0x0004
#define  set_PREDBLK_VC1INTC4_reg(data)                                          (*((volatile unsigned int*)PREDBLK_VC1INTC4_reg)=data)
#define  get_PREDBLK_VC1INTC4_reg                                                (*((volatile unsigned int*)PREDBLK_VC1INTC4_reg))
#define  PREDBLK_VC1INTC4_LUMSCALE3_shift                                        (18)
#define  PREDBLK_VC1INTC4_LUMSHIFT3_shift                                        (12)
#define  PREDBLK_VC1INTC4_LUMSCALE4_shift                                        (6)
#define  PREDBLK_VC1INTC4_LUMSHIFT4_shift                                        (0)
#define  PREDBLK_VC1INTC4_LUMSCALE3_mask                                         (0x00FC0000)
#define  PREDBLK_VC1INTC4_LUMSHIFT3_mask                                         (0x0003F000)
#define  PREDBLK_VC1INTC4_LUMSCALE4_mask                                         (0x00000FC0)
#define  PREDBLK_VC1INTC4_LUMSHIFT4_mask                                         (0x0000003F)
#define  PREDBLK_VC1INTC4_LUMSCALE3(data)                                        (0x00FC0000&((data)<<18))
#define  PREDBLK_VC1INTC4_LUMSHIFT3(data)                                        (0x0003F000&((data)<<12))
#define  PREDBLK_VC1INTC4_LUMSCALE4(data)                                        (0x00000FC0&((data)<<6))
#define  PREDBLK_VC1INTC4_LUMSHIFT4(data)                                        (0x0000003F&(data))
#define  PREDBLK_VC1INTC4_get_LUMSCALE3(data)                                    ((0x00FC0000&(data))>>18)
#define  PREDBLK_VC1INTC4_get_LUMSHIFT3(data)                                    ((0x0003F000&(data))>>12)
#define  PREDBLK_VC1INTC4_get_LUMSCALE4(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC4_get_LUMSHIFT4(data)                                    (0x0000003F&(data))
#define  PREDBLK_VC1INTC4_LUMSCALE3_src(data)                                    ((0x00FC0000&(data))>>18)
#define  PREDBLK_VC1INTC4_LUMSHIFT3_src(data)                                    ((0x0003F000&(data))>>12)
#define  PREDBLK_VC1INTC4_LUMSCALE4_src(data)                                    ((0x00000FC0&(data))>>6)
#define  PREDBLK_VC1INTC4_LUMSHIFT4_src(data)                                    (0x0000003F&(data))

#define  PREDBLK_NBINTRA0_0                                                      0x1800E814
#define  PREDBLK_NBINTRA0_0_reg_addr                                             "0xB800E814"
#define  PREDBLK_NBINTRA0_0_reg                                                  0xB800E814
#define  PREDBLK_NBINTRA0_0_inst_addr                                            "0x0005"
#define  PREDBLK_NBINTRA0_0_inst_adr                                             "0x0005"
#define  PREDBLK_NBINTRA0_0_inst                                                 0x0005
#define  set_PREDBLK_NBINTRA0_0_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_0_reg)=data)
#define  get_PREDBLK_NBINTRA0_0_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_0_reg))
#define  PREDBLK_NBINTRA0_intra_flag_shift                                       (0)
#define  PREDBLK_NBINTRA0_intra_flag_mask                                        (0xFFFFFFFF)
#define  PREDBLK_NBINTRA0_intra_flag(data)                                       (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_get_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA0_intra_flag_src(data)                                   (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA0_1                                                      0x1800E818
#define  PREDBLK_NBINTRA0_1_reg_addr                                             "0xB800E818"
#define  PREDBLK_NBINTRA0_1_reg                                                  0xB800E818
#define  PREDBLK_NBINTRA0_1_inst_addr                                            "0x0006"
#define  PREDBLK_NBINTRA0_1_inst_adr                                             "0x0006"
#define  PREDBLK_NBINTRA0_1_inst                                                 0x0006
#define  set_PREDBLK_NBINTRA0_1_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_1_reg)=data)
#define  get_PREDBLK_NBINTRA0_1_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_1_reg))

#define  PREDBLK_NBINTRA0_2                                                      0x1800E81C
#define  PREDBLK_NBINTRA0_2_reg_addr                                             "0xB800E81C"
#define  PREDBLK_NBINTRA0_2_reg                                                  0xB800E81C
#define  PREDBLK_NBINTRA0_2_inst_addr                                            "0x0007"
#define  PREDBLK_NBINTRA0_2_inst_adr                                             "0x0007"
#define  PREDBLK_NBINTRA0_2_inst                                                 0x0007
#define  set_PREDBLK_NBINTRA0_2_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_2_reg)=data)
#define  get_PREDBLK_NBINTRA0_2_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_2_reg))

#define  PREDBLK_NBINTRA0_3                                                      0x1800E820
#define  PREDBLK_NBINTRA0_3_reg_addr                                             "0xB800E820"
#define  PREDBLK_NBINTRA0_3_reg                                                  0xB800E820
#define  PREDBLK_NBINTRA0_3_inst_addr                                            "0x0008"
#define  PREDBLK_NBINTRA0_3_inst_adr                                             "0x0008"
#define  PREDBLK_NBINTRA0_3_inst                                                 0x0008
#define  set_PREDBLK_NBINTRA0_3_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_3_reg)=data)
#define  get_PREDBLK_NBINTRA0_3_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_3_reg))

#define  PREDBLK_NBINTRA0_4                                                      0x1800E824
#define  PREDBLK_NBINTRA0_4_reg_addr                                             "0xB800E824"
#define  PREDBLK_NBINTRA0_4_reg                                                  0xB800E824
#define  PREDBLK_NBINTRA0_4_inst_addr                                            "0x0009"
#define  PREDBLK_NBINTRA0_4_inst_adr                                             "0x0009"
#define  PREDBLK_NBINTRA0_4_inst                                                 0x0009
#define  set_PREDBLK_NBINTRA0_4_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_4_reg)=data)
#define  get_PREDBLK_NBINTRA0_4_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_4_reg))

#define  PREDBLK_NBINTRA0_5                                                      0x1800E828
#define  PREDBLK_NBINTRA0_5_reg_addr                                             "0xB800E828"
#define  PREDBLK_NBINTRA0_5_reg                                                  0xB800E828
#define  PREDBLK_NBINTRA0_5_inst_addr                                            "0x000A"
#define  PREDBLK_NBINTRA0_5_inst_adr                                             "0x000A"
#define  PREDBLK_NBINTRA0_5_inst                                                 0x000A
#define  set_PREDBLK_NBINTRA0_5_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_5_reg)=data)
#define  get_PREDBLK_NBINTRA0_5_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_5_reg))

#define  PREDBLK_NBINTRA0_6                                                      0x1800E82C
#define  PREDBLK_NBINTRA0_6_reg_addr                                             "0xB800E82C"
#define  PREDBLK_NBINTRA0_6_reg                                                  0xB800E82C
#define  PREDBLK_NBINTRA0_6_inst_addr                                            "0x000B"
#define  PREDBLK_NBINTRA0_6_inst_adr                                             "0x000B"
#define  PREDBLK_NBINTRA0_6_inst                                                 0x000B
#define  set_PREDBLK_NBINTRA0_6_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_6_reg)=data)
#define  get_PREDBLK_NBINTRA0_6_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_6_reg))

#define  PREDBLK_NBINTRA0_7                                                      0x1800E830
#define  PREDBLK_NBINTRA0_7_reg_addr                                             "0xB800E830"
#define  PREDBLK_NBINTRA0_7_reg                                                  0xB800E830
#define  PREDBLK_NBINTRA0_7_inst_addr                                            "0x000C"
#define  PREDBLK_NBINTRA0_7_inst_adr                                             "0x000C"
#define  PREDBLK_NBINTRA0_7_inst                                                 0x000C
#define  set_PREDBLK_NBINTRA0_7_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_7_reg)=data)
#define  get_PREDBLK_NBINTRA0_7_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_7_reg))

#define  PREDBLK_NBINTRA0_8                                                      0x1800E834
#define  PREDBLK_NBINTRA0_8_reg_addr                                             "0xB800E834"
#define  PREDBLK_NBINTRA0_8_reg                                                  0xB800E834
#define  PREDBLK_NBINTRA0_8_inst_addr                                            "0x000D"
#define  PREDBLK_NBINTRA0_8_inst_adr                                             "0x000D"
#define  PREDBLK_NBINTRA0_8_inst                                                 0x000D
#define  set_PREDBLK_NBINTRA0_8_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_8_reg)=data)
#define  get_PREDBLK_NBINTRA0_8_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_8_reg))

#define  PREDBLK_NBINTRA0_9                                                      0x1800E838
#define  PREDBLK_NBINTRA0_9_reg_addr                                             "0xB800E838"
#define  PREDBLK_NBINTRA0_9_reg                                                  0xB800E838
#define  PREDBLK_NBINTRA0_9_inst_addr                                            "0x000E"
#define  PREDBLK_NBINTRA0_9_inst_adr                                             "0x000E"
#define  PREDBLK_NBINTRA0_9_inst                                                 0x000E
#define  set_PREDBLK_NBINTRA0_9_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA0_9_reg)=data)
#define  get_PREDBLK_NBINTRA0_9_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA0_9_reg))

#define  PREDBLK_NBINTRA0_10                                                     0x1800E83C
#define  PREDBLK_NBINTRA0_10_reg_addr                                            "0xB800E83C"
#define  PREDBLK_NBINTRA0_10_reg                                                 0xB800E83C
#define  PREDBLK_NBINTRA0_10_inst_addr                                           "0x000F"
#define  PREDBLK_NBINTRA0_10_inst_adr                                            "0x000F"
#define  PREDBLK_NBINTRA0_10_inst                                                0x000F
#define  set_PREDBLK_NBINTRA0_10_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_10_reg)=data)
#define  get_PREDBLK_NBINTRA0_10_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_10_reg))

#define  PREDBLK_NBINTRA0_11                                                     0x1800E840
#define  PREDBLK_NBINTRA0_11_reg_addr                                            "0xB800E840"
#define  PREDBLK_NBINTRA0_11_reg                                                 0xB800E840
#define  PREDBLK_NBINTRA0_11_inst_addr                                           "0x0010"
#define  PREDBLK_NBINTRA0_11_inst_adr                                            "0x0010"
#define  PREDBLK_NBINTRA0_11_inst                                                0x0010
#define  set_PREDBLK_NBINTRA0_11_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_11_reg)=data)
#define  get_PREDBLK_NBINTRA0_11_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_11_reg))

#define  PREDBLK_NBINTRA0_12                                                     0x1800E844
#define  PREDBLK_NBINTRA0_12_reg_addr                                            "0xB800E844"
#define  PREDBLK_NBINTRA0_12_reg                                                 0xB800E844
#define  PREDBLK_NBINTRA0_12_inst_addr                                           "0x0011"
#define  PREDBLK_NBINTRA0_12_inst_adr                                            "0x0011"
#define  PREDBLK_NBINTRA0_12_inst                                                0x0011
#define  set_PREDBLK_NBINTRA0_12_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_12_reg)=data)
#define  get_PREDBLK_NBINTRA0_12_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_12_reg))

#define  PREDBLK_NBINTRA0_13                                                     0x1800E848
#define  PREDBLK_NBINTRA0_13_reg_addr                                            "0xB800E848"
#define  PREDBLK_NBINTRA0_13_reg                                                 0xB800E848
#define  PREDBLK_NBINTRA0_13_inst_addr                                           "0x0012"
#define  PREDBLK_NBINTRA0_13_inst_adr                                            "0x0012"
#define  PREDBLK_NBINTRA0_13_inst                                                0x0012
#define  set_PREDBLK_NBINTRA0_13_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_13_reg)=data)
#define  get_PREDBLK_NBINTRA0_13_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_13_reg))

#define  PREDBLK_NBINTRA0_14                                                     0x1800E84C
#define  PREDBLK_NBINTRA0_14_reg_addr                                            "0xB800E84C"
#define  PREDBLK_NBINTRA0_14_reg                                                 0xB800E84C
#define  PREDBLK_NBINTRA0_14_inst_addr                                           "0x0013"
#define  PREDBLK_NBINTRA0_14_inst_adr                                            "0x0013"
#define  PREDBLK_NBINTRA0_14_inst                                                0x0013
#define  set_PREDBLK_NBINTRA0_14_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_14_reg)=data)
#define  get_PREDBLK_NBINTRA0_14_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_14_reg))

#define  PREDBLK_NBINTRA0_15                                                     0x1800E850
#define  PREDBLK_NBINTRA0_15_reg_addr                                            "0xB800E850"
#define  PREDBLK_NBINTRA0_15_reg                                                 0xB800E850
#define  PREDBLK_NBINTRA0_15_inst_addr                                           "0x0014"
#define  PREDBLK_NBINTRA0_15_inst_adr                                            "0x0014"
#define  PREDBLK_NBINTRA0_15_inst                                                0x0014
#define  set_PREDBLK_NBINTRA0_15_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA0_15_reg)=data)
#define  get_PREDBLK_NBINTRA0_15_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA0_15_reg))

#define  PREDBLK_NBINTRA1_0                                                      0x1800E854
#define  PREDBLK_NBINTRA1_0_reg_addr                                             "0xB800E854"
#define  PREDBLK_NBINTRA1_0_reg                                                  0xB800E854
#define  PREDBLK_NBINTRA1_0_inst_addr                                            "0x0015"
#define  PREDBLK_NBINTRA1_0_inst_adr                                             "0x0015"
#define  PREDBLK_NBINTRA1_0_inst                                                 0x0015
#define  set_PREDBLK_NBINTRA1_0_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_0_reg)=data)
#define  get_PREDBLK_NBINTRA1_0_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_0_reg))
#define  PREDBLK_NBINTRA1_intra_flag_shift                                       (0)
#define  PREDBLK_NBINTRA1_intra_flag_mask                                        (0xFFFFFFFF)
#define  PREDBLK_NBINTRA1_intra_flag(data)                                       (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_get_intra_flag(data)                                   (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRA1_intra_flag_src(data)                                   (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRA1_1                                                      0x1800E858
#define  PREDBLK_NBINTRA1_1_reg_addr                                             "0xB800E858"
#define  PREDBLK_NBINTRA1_1_reg                                                  0xB800E858
#define  PREDBLK_NBINTRA1_1_inst_addr                                            "0x0016"
#define  PREDBLK_NBINTRA1_1_inst_adr                                             "0x0016"
#define  PREDBLK_NBINTRA1_1_inst                                                 0x0016
#define  set_PREDBLK_NBINTRA1_1_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_1_reg)=data)
#define  get_PREDBLK_NBINTRA1_1_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_1_reg))

#define  PREDBLK_NBINTRA1_2                                                      0x1800E85C
#define  PREDBLK_NBINTRA1_2_reg_addr                                             "0xB800E85C"
#define  PREDBLK_NBINTRA1_2_reg                                                  0xB800E85C
#define  PREDBLK_NBINTRA1_2_inst_addr                                            "0x0017"
#define  PREDBLK_NBINTRA1_2_inst_adr                                             "0x0017"
#define  PREDBLK_NBINTRA1_2_inst                                                 0x0017
#define  set_PREDBLK_NBINTRA1_2_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_2_reg)=data)
#define  get_PREDBLK_NBINTRA1_2_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_2_reg))

#define  PREDBLK_NBINTRA1_3                                                      0x1800E860
#define  PREDBLK_NBINTRA1_3_reg_addr                                             "0xB800E860"
#define  PREDBLK_NBINTRA1_3_reg                                                  0xB800E860
#define  PREDBLK_NBINTRA1_3_inst_addr                                            "0x0018"
#define  PREDBLK_NBINTRA1_3_inst_adr                                             "0x0018"
#define  PREDBLK_NBINTRA1_3_inst                                                 0x0018
#define  set_PREDBLK_NBINTRA1_3_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_3_reg)=data)
#define  get_PREDBLK_NBINTRA1_3_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_3_reg))

#define  PREDBLK_NBINTRA1_4                                                      0x1800E864
#define  PREDBLK_NBINTRA1_4_reg_addr                                             "0xB800E864"
#define  PREDBLK_NBINTRA1_4_reg                                                  0xB800E864
#define  PREDBLK_NBINTRA1_4_inst_addr                                            "0x0019"
#define  PREDBLK_NBINTRA1_4_inst_adr                                             "0x0019"
#define  PREDBLK_NBINTRA1_4_inst                                                 0x0019
#define  set_PREDBLK_NBINTRA1_4_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_4_reg)=data)
#define  get_PREDBLK_NBINTRA1_4_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_4_reg))

#define  PREDBLK_NBINTRA1_5                                                      0x1800E868
#define  PREDBLK_NBINTRA1_5_reg_addr                                             "0xB800E868"
#define  PREDBLK_NBINTRA1_5_reg                                                  0xB800E868
#define  PREDBLK_NBINTRA1_5_inst_addr                                            "0x001A"
#define  PREDBLK_NBINTRA1_5_inst_adr                                             "0x001A"
#define  PREDBLK_NBINTRA1_5_inst                                                 0x001A
#define  set_PREDBLK_NBINTRA1_5_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_5_reg)=data)
#define  get_PREDBLK_NBINTRA1_5_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_5_reg))

#define  PREDBLK_NBINTRA1_6                                                      0x1800E86C
#define  PREDBLK_NBINTRA1_6_reg_addr                                             "0xB800E86C"
#define  PREDBLK_NBINTRA1_6_reg                                                  0xB800E86C
#define  PREDBLK_NBINTRA1_6_inst_addr                                            "0x001B"
#define  PREDBLK_NBINTRA1_6_inst_adr                                             "0x001B"
#define  PREDBLK_NBINTRA1_6_inst                                                 0x001B
#define  set_PREDBLK_NBINTRA1_6_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_6_reg)=data)
#define  get_PREDBLK_NBINTRA1_6_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_6_reg))

#define  PREDBLK_NBINTRA1_7                                                      0x1800E870
#define  PREDBLK_NBINTRA1_7_reg_addr                                             "0xB800E870"
#define  PREDBLK_NBINTRA1_7_reg                                                  0xB800E870
#define  PREDBLK_NBINTRA1_7_inst_addr                                            "0x001C"
#define  PREDBLK_NBINTRA1_7_inst_adr                                             "0x001C"
#define  PREDBLK_NBINTRA1_7_inst                                                 0x001C
#define  set_PREDBLK_NBINTRA1_7_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_7_reg)=data)
#define  get_PREDBLK_NBINTRA1_7_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_7_reg))

#define  PREDBLK_NBINTRA1_8                                                      0x1800E874
#define  PREDBLK_NBINTRA1_8_reg_addr                                             "0xB800E874"
#define  PREDBLK_NBINTRA1_8_reg                                                  0xB800E874
#define  PREDBLK_NBINTRA1_8_inst_addr                                            "0x001D"
#define  PREDBLK_NBINTRA1_8_inst_adr                                             "0x001D"
#define  PREDBLK_NBINTRA1_8_inst                                                 0x001D
#define  set_PREDBLK_NBINTRA1_8_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_8_reg)=data)
#define  get_PREDBLK_NBINTRA1_8_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_8_reg))

#define  PREDBLK_NBINTRA1_9                                                      0x1800E878
#define  PREDBLK_NBINTRA1_9_reg_addr                                             "0xB800E878"
#define  PREDBLK_NBINTRA1_9_reg                                                  0xB800E878
#define  PREDBLK_NBINTRA1_9_inst_addr                                            "0x001E"
#define  PREDBLK_NBINTRA1_9_inst_adr                                             "0x001E"
#define  PREDBLK_NBINTRA1_9_inst                                                 0x001E
#define  set_PREDBLK_NBINTRA1_9_reg(data)                                        (*((volatile unsigned int*)PREDBLK_NBINTRA1_9_reg)=data)
#define  get_PREDBLK_NBINTRA1_9_reg                                              (*((volatile unsigned int*)PREDBLK_NBINTRA1_9_reg))

#define  PREDBLK_NBINTRA1_10                                                     0x1800E87C
#define  PREDBLK_NBINTRA1_10_reg_addr                                            "0xB800E87C"
#define  PREDBLK_NBINTRA1_10_reg                                                 0xB800E87C
#define  PREDBLK_NBINTRA1_10_inst_addr                                           "0x001F"
#define  PREDBLK_NBINTRA1_10_inst_adr                                            "0x001F"
#define  PREDBLK_NBINTRA1_10_inst                                                0x001F
#define  set_PREDBLK_NBINTRA1_10_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_10_reg)=data)
#define  get_PREDBLK_NBINTRA1_10_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_10_reg))

#define  PREDBLK_NBINTRA1_11                                                     0x1800E880
#define  PREDBLK_NBINTRA1_11_reg_addr                                            "0xB800E880"
#define  PREDBLK_NBINTRA1_11_reg                                                 0xB800E880
#define  PREDBLK_NBINTRA1_11_inst_addr                                           "0x0020"
#define  PREDBLK_NBINTRA1_11_inst_adr                                            "0x0020"
#define  PREDBLK_NBINTRA1_11_inst                                                0x0020
#define  set_PREDBLK_NBINTRA1_11_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_11_reg)=data)
#define  get_PREDBLK_NBINTRA1_11_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_11_reg))

#define  PREDBLK_NBINTRA1_12                                                     0x1800E884
#define  PREDBLK_NBINTRA1_12_reg_addr                                            "0xB800E884"
#define  PREDBLK_NBINTRA1_12_reg                                                 0xB800E884
#define  PREDBLK_NBINTRA1_12_inst_addr                                           "0x0021"
#define  PREDBLK_NBINTRA1_12_inst_adr                                            "0x0021"
#define  PREDBLK_NBINTRA1_12_inst                                                0x0021
#define  set_PREDBLK_NBINTRA1_12_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_12_reg)=data)
#define  get_PREDBLK_NBINTRA1_12_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_12_reg))

#define  PREDBLK_NBINTRA1_13                                                     0x1800E888
#define  PREDBLK_NBINTRA1_13_reg_addr                                            "0xB800E888"
#define  PREDBLK_NBINTRA1_13_reg                                                 0xB800E888
#define  PREDBLK_NBINTRA1_13_inst_addr                                           "0x0022"
#define  PREDBLK_NBINTRA1_13_inst_adr                                            "0x0022"
#define  PREDBLK_NBINTRA1_13_inst                                                0x0022
#define  set_PREDBLK_NBINTRA1_13_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_13_reg)=data)
#define  get_PREDBLK_NBINTRA1_13_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_13_reg))

#define  PREDBLK_NBINTRA1_14                                                     0x1800E88C
#define  PREDBLK_NBINTRA1_14_reg_addr                                            "0xB800E88C"
#define  PREDBLK_NBINTRA1_14_reg                                                 0xB800E88C
#define  PREDBLK_NBINTRA1_14_inst_addr                                           "0x0023"
#define  PREDBLK_NBINTRA1_14_inst_adr                                            "0x0023"
#define  PREDBLK_NBINTRA1_14_inst                                                0x0023
#define  set_PREDBLK_NBINTRA1_14_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_14_reg)=data)
#define  get_PREDBLK_NBINTRA1_14_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_14_reg))

#define  PREDBLK_NBINTRA1_15                                                     0x1800E890
#define  PREDBLK_NBINTRA1_15_reg_addr                                            "0xB800E890"
#define  PREDBLK_NBINTRA1_15_reg                                                 0xB800E890
#define  PREDBLK_NBINTRA1_15_inst_addr                                           "0x0024"
#define  PREDBLK_NBINTRA1_15_inst_adr                                            "0x0024"
#define  PREDBLK_NBINTRA1_15_inst                                                0x0024
#define  set_PREDBLK_NBINTRA1_15_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRA1_15_reg)=data)
#define  get_PREDBLK_NBINTRA1_15_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRA1_15_reg))

#define  PREDBLK_NBINTRACH_0                                                     0x1800E894
#define  PREDBLK_NBINTRACH_0_reg_addr                                            "0xB800E894"
#define  PREDBLK_NBINTRACH_0_reg                                                 0xB800E894
#define  PREDBLK_NBINTRACH_0_inst_addr                                           "0x0025"
#define  PREDBLK_NBINTRACH_0_inst_adr                                            "0x0025"
#define  PREDBLK_NBINTRACH_0_inst                                                0x0025
#define  set_PREDBLK_NBINTRACH_0_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_0_reg)=data)
#define  get_PREDBLK_NBINTRACH_0_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_0_reg))
#define  PREDBLK_NBINTRACH_intra_flag_shift                                      (0)
#define  PREDBLK_NBINTRACH_intra_flag_mask                                       (0xFFFFFFFF)
#define  PREDBLK_NBINTRACH_intra_flag(data)                                      (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_get_intra_flag(data)                                  (0xFFFFFFFF&(data))
#define  PREDBLK_NBINTRACH_intra_flag_src(data)                                  (0xFFFFFFFF&(data))

#define  PREDBLK_NBINTRACH_1                                                     0x1800E898
#define  PREDBLK_NBINTRACH_1_reg_addr                                            "0xB800E898"
#define  PREDBLK_NBINTRACH_1_reg                                                 0xB800E898
#define  PREDBLK_NBINTRACH_1_inst_addr                                           "0x0026"
#define  PREDBLK_NBINTRACH_1_inst_adr                                            "0x0026"
#define  PREDBLK_NBINTRACH_1_inst                                                0x0026
#define  set_PREDBLK_NBINTRACH_1_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_1_reg)=data)
#define  get_PREDBLK_NBINTRACH_1_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_1_reg))

#define  PREDBLK_NBINTRACH_2                                                     0x1800E89C
#define  PREDBLK_NBINTRACH_2_reg_addr                                            "0xB800E89C"
#define  PREDBLK_NBINTRACH_2_reg                                                 0xB800E89C
#define  PREDBLK_NBINTRACH_2_inst_addr                                           "0x0027"
#define  PREDBLK_NBINTRACH_2_inst_adr                                            "0x0027"
#define  PREDBLK_NBINTRACH_2_inst                                                0x0027
#define  set_PREDBLK_NBINTRACH_2_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_2_reg)=data)
#define  get_PREDBLK_NBINTRACH_2_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_2_reg))

#define  PREDBLK_NBINTRACH_3                                                     0x1800E8A0
#define  PREDBLK_NBINTRACH_3_reg_addr                                            "0xB800E8A0"
#define  PREDBLK_NBINTRACH_3_reg                                                 0xB800E8A0
#define  PREDBLK_NBINTRACH_3_inst_addr                                           "0x0028"
#define  PREDBLK_NBINTRACH_3_inst_adr                                            "0x0028"
#define  PREDBLK_NBINTRACH_3_inst                                                0x0028
#define  set_PREDBLK_NBINTRACH_3_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_3_reg)=data)
#define  get_PREDBLK_NBINTRACH_3_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_3_reg))

#define  PREDBLK_NBINTRACH_4                                                     0x1800E8A4
#define  PREDBLK_NBINTRACH_4_reg_addr                                            "0xB800E8A4"
#define  PREDBLK_NBINTRACH_4_reg                                                 0xB800E8A4
#define  PREDBLK_NBINTRACH_4_inst_addr                                           "0x0029"
#define  PREDBLK_NBINTRACH_4_inst_adr                                            "0x0029"
#define  PREDBLK_NBINTRACH_4_inst                                                0x0029
#define  set_PREDBLK_NBINTRACH_4_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_4_reg)=data)
#define  get_PREDBLK_NBINTRACH_4_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_4_reg))

#define  PREDBLK_NBINTRACH_5                                                     0x1800E8A8
#define  PREDBLK_NBINTRACH_5_reg_addr                                            "0xB800E8A8"
#define  PREDBLK_NBINTRACH_5_reg                                                 0xB800E8A8
#define  PREDBLK_NBINTRACH_5_inst_addr                                           "0x002A"
#define  PREDBLK_NBINTRACH_5_inst_adr                                            "0x002A"
#define  PREDBLK_NBINTRACH_5_inst                                                0x002A
#define  set_PREDBLK_NBINTRACH_5_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_5_reg)=data)
#define  get_PREDBLK_NBINTRACH_5_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_5_reg))

#define  PREDBLK_NBINTRACH_6                                                     0x1800E8AC
#define  PREDBLK_NBINTRACH_6_reg_addr                                            "0xB800E8AC"
#define  PREDBLK_NBINTRACH_6_reg                                                 0xB800E8AC
#define  PREDBLK_NBINTRACH_6_inst_addr                                           "0x002B"
#define  PREDBLK_NBINTRACH_6_inst_adr                                            "0x002B"
#define  PREDBLK_NBINTRACH_6_inst                                                0x002B
#define  set_PREDBLK_NBINTRACH_6_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_6_reg)=data)
#define  get_PREDBLK_NBINTRACH_6_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_6_reg))

#define  PREDBLK_NBINTRACH_7                                                     0x1800E8B0
#define  PREDBLK_NBINTRACH_7_reg_addr                                            "0xB800E8B0"
#define  PREDBLK_NBINTRACH_7_reg                                                 0xB800E8B0
#define  PREDBLK_NBINTRACH_7_inst_addr                                           "0x002C"
#define  PREDBLK_NBINTRACH_7_inst_adr                                            "0x002C"
#define  PREDBLK_NBINTRACH_7_inst                                                0x002C
#define  set_PREDBLK_NBINTRACH_7_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_7_reg)=data)
#define  get_PREDBLK_NBINTRACH_7_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_7_reg))

#define  PREDBLK_NBINTRACH_8                                                     0x1800E8B4
#define  PREDBLK_NBINTRACH_8_reg_addr                                            "0xB800E8B4"
#define  PREDBLK_NBINTRACH_8_reg                                                 0xB800E8B4
#define  PREDBLK_NBINTRACH_8_inst_addr                                           "0x002D"
#define  PREDBLK_NBINTRACH_8_inst_adr                                            "0x002D"
#define  PREDBLK_NBINTRACH_8_inst                                                0x002D
#define  set_PREDBLK_NBINTRACH_8_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_8_reg)=data)
#define  get_PREDBLK_NBINTRACH_8_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_8_reg))

#define  PREDBLK_NBINTRACH_9                                                     0x1800E8B8
#define  PREDBLK_NBINTRACH_9_reg_addr                                            "0xB800E8B8"
#define  PREDBLK_NBINTRACH_9_reg                                                 0xB800E8B8
#define  PREDBLK_NBINTRACH_9_inst_addr                                           "0x002E"
#define  PREDBLK_NBINTRACH_9_inst_adr                                            "0x002E"
#define  PREDBLK_NBINTRACH_9_inst                                                0x002E
#define  set_PREDBLK_NBINTRACH_9_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBINTRACH_9_reg)=data)
#define  get_PREDBLK_NBINTRACH_9_reg                                             (*((volatile unsigned int*)PREDBLK_NBINTRACH_9_reg))

#define  PREDBLK_NBINTRACH_10                                                    0x1800E8BC
#define  PREDBLK_NBINTRACH_10_reg_addr                                           "0xB800E8BC"
#define  PREDBLK_NBINTRACH_10_reg                                                0xB800E8BC
#define  PREDBLK_NBINTRACH_10_inst_addr                                          "0x002F"
#define  PREDBLK_NBINTRACH_10_inst_adr                                           "0x002F"
#define  PREDBLK_NBINTRACH_10_inst                                               0x002F
#define  set_PREDBLK_NBINTRACH_10_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_10_reg)=data)
#define  get_PREDBLK_NBINTRACH_10_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_10_reg))

#define  PREDBLK_NBINTRACH_11                                                    0x1800E8C0
#define  PREDBLK_NBINTRACH_11_reg_addr                                           "0xB800E8C0"
#define  PREDBLK_NBINTRACH_11_reg                                                0xB800E8C0
#define  PREDBLK_NBINTRACH_11_inst_addr                                          "0x0030"
#define  PREDBLK_NBINTRACH_11_inst_adr                                           "0x0030"
#define  PREDBLK_NBINTRACH_11_inst                                               0x0030
#define  set_PREDBLK_NBINTRACH_11_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_11_reg)=data)
#define  get_PREDBLK_NBINTRACH_11_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_11_reg))

#define  PREDBLK_NBINTRACH_12                                                    0x1800E8C4
#define  PREDBLK_NBINTRACH_12_reg_addr                                           "0xB800E8C4"
#define  PREDBLK_NBINTRACH_12_reg                                                0xB800E8C4
#define  PREDBLK_NBINTRACH_12_inst_addr                                          "0x0031"
#define  PREDBLK_NBINTRACH_12_inst_adr                                           "0x0031"
#define  PREDBLK_NBINTRACH_12_inst                                               0x0031
#define  set_PREDBLK_NBINTRACH_12_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_12_reg)=data)
#define  get_PREDBLK_NBINTRACH_12_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_12_reg))

#define  PREDBLK_NBINTRACH_13                                                    0x1800E8C8
#define  PREDBLK_NBINTRACH_13_reg_addr                                           "0xB800E8C8"
#define  PREDBLK_NBINTRACH_13_reg                                                0xB800E8C8
#define  PREDBLK_NBINTRACH_13_inst_addr                                          "0x0032"
#define  PREDBLK_NBINTRACH_13_inst_adr                                           "0x0032"
#define  PREDBLK_NBINTRACH_13_inst                                               0x0032
#define  set_PREDBLK_NBINTRACH_13_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_13_reg)=data)
#define  get_PREDBLK_NBINTRACH_13_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_13_reg))

#define  PREDBLK_NBINTRACH_14                                                    0x1800E8CC
#define  PREDBLK_NBINTRACH_14_reg_addr                                           "0xB800E8CC"
#define  PREDBLK_NBINTRACH_14_reg                                                0xB800E8CC
#define  PREDBLK_NBINTRACH_14_inst_addr                                          "0x0033"
#define  PREDBLK_NBINTRACH_14_inst_adr                                           "0x0033"
#define  PREDBLK_NBINTRACH_14_inst                                               0x0033
#define  set_PREDBLK_NBINTRACH_14_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_14_reg)=data)
#define  get_PREDBLK_NBINTRACH_14_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_14_reg))

#define  PREDBLK_NBINTRACH_15                                                    0x1800E8D0
#define  PREDBLK_NBINTRACH_15_reg_addr                                           "0xB800E8D0"
#define  PREDBLK_NBINTRACH_15_reg                                                0xB800E8D0
#define  PREDBLK_NBINTRACH_15_inst_addr                                          "0x0034"
#define  PREDBLK_NBINTRACH_15_inst_adr                                           "0x0034"
#define  PREDBLK_NBINTRACH_15_inst                                               0x0034
#define  set_PREDBLK_NBINTRACH_15_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBINTRACH_15_reg)=data)
#define  get_PREDBLK_NBINTRACH_15_reg                                            (*((volatile unsigned int*)PREDBLK_NBINTRACH_15_reg))

#define  PREDBLK_NBFIELDOV_0                                                     0x1800E8D4
#define  PREDBLK_NBFIELDOV_0_reg_addr                                            "0xB800E8D4"
#define  PREDBLK_NBFIELDOV_0_reg                                                 0xB800E8D4
#define  PREDBLK_NBFIELDOV_0_inst_addr                                           "0x0035"
#define  PREDBLK_NBFIELDOV_0_inst_adr                                            "0x0035"
#define  PREDBLK_NBFIELDOV_0_inst                                                0x0035
#define  set_PREDBLK_NBFIELDOV_0_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_0_reg)=data)
#define  get_PREDBLK_NBFIELDOV_0_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_0_reg))
#define  PREDBLK_NBFIELDOV_Field_overflag_flag_shift                             (0)
#define  PREDBLK_NBFIELDOV_Field_overflag_flag_mask                              (0xFFFFFFFF)
#define  PREDBLK_NBFIELDOV_Field_overflag_flag(data)                             (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_get_Field_overflag_flag(data)                         (0xFFFFFFFF&(data))
#define  PREDBLK_NBFIELDOV_Field_overflag_flag_src(data)                         (0xFFFFFFFF&(data))

#define  PREDBLK_NBFIELDOV_1                                                     0x1800E8D8
#define  PREDBLK_NBFIELDOV_1_reg_addr                                            "0xB800E8D8"
#define  PREDBLK_NBFIELDOV_1_reg                                                 0xB800E8D8
#define  PREDBLK_NBFIELDOV_1_inst_addr                                           "0x0036"
#define  PREDBLK_NBFIELDOV_1_inst_adr                                            "0x0036"
#define  PREDBLK_NBFIELDOV_1_inst                                                0x0036
#define  set_PREDBLK_NBFIELDOV_1_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_1_reg)=data)
#define  get_PREDBLK_NBFIELDOV_1_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_1_reg))

#define  PREDBLK_NBFIELDOV_2                                                     0x1800E8DC
#define  PREDBLK_NBFIELDOV_2_reg_addr                                            "0xB800E8DC"
#define  PREDBLK_NBFIELDOV_2_reg                                                 0xB800E8DC
#define  PREDBLK_NBFIELDOV_2_inst_addr                                           "0x0037"
#define  PREDBLK_NBFIELDOV_2_inst_adr                                            "0x0037"
#define  PREDBLK_NBFIELDOV_2_inst                                                0x0037
#define  set_PREDBLK_NBFIELDOV_2_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_2_reg)=data)
#define  get_PREDBLK_NBFIELDOV_2_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_2_reg))

#define  PREDBLK_NBFIELDOV_3                                                     0x1800E8E0
#define  PREDBLK_NBFIELDOV_3_reg_addr                                            "0xB800E8E0"
#define  PREDBLK_NBFIELDOV_3_reg                                                 0xB800E8E0
#define  PREDBLK_NBFIELDOV_3_inst_addr                                           "0x0038"
#define  PREDBLK_NBFIELDOV_3_inst_adr                                            "0x0038"
#define  PREDBLK_NBFIELDOV_3_inst                                                0x0038
#define  set_PREDBLK_NBFIELDOV_3_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_3_reg)=data)
#define  get_PREDBLK_NBFIELDOV_3_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_3_reg))

#define  PREDBLK_NBFIELDOV_4                                                     0x1800E8E4
#define  PREDBLK_NBFIELDOV_4_reg_addr                                            "0xB800E8E4"
#define  PREDBLK_NBFIELDOV_4_reg                                                 0xB800E8E4
#define  PREDBLK_NBFIELDOV_4_inst_addr                                           "0x0039"
#define  PREDBLK_NBFIELDOV_4_inst_adr                                            "0x0039"
#define  PREDBLK_NBFIELDOV_4_inst                                                0x0039
#define  set_PREDBLK_NBFIELDOV_4_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_4_reg)=data)
#define  get_PREDBLK_NBFIELDOV_4_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_4_reg))

#define  PREDBLK_NBFIELDOV_5                                                     0x1800E8E8
#define  PREDBLK_NBFIELDOV_5_reg_addr                                            "0xB800E8E8"
#define  PREDBLK_NBFIELDOV_5_reg                                                 0xB800E8E8
#define  PREDBLK_NBFIELDOV_5_inst_addr                                           "0x003A"
#define  PREDBLK_NBFIELDOV_5_inst_adr                                            "0x003A"
#define  PREDBLK_NBFIELDOV_5_inst                                                0x003A
#define  set_PREDBLK_NBFIELDOV_5_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_5_reg)=data)
#define  get_PREDBLK_NBFIELDOV_5_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_5_reg))

#define  PREDBLK_NBFIELDOV_6                                                     0x1800E8EC
#define  PREDBLK_NBFIELDOV_6_reg_addr                                            "0xB800E8EC"
#define  PREDBLK_NBFIELDOV_6_reg                                                 0xB800E8EC
#define  PREDBLK_NBFIELDOV_6_inst_addr                                           "0x003B"
#define  PREDBLK_NBFIELDOV_6_inst_adr                                            "0x003B"
#define  PREDBLK_NBFIELDOV_6_inst                                                0x003B
#define  set_PREDBLK_NBFIELDOV_6_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_6_reg)=data)
#define  get_PREDBLK_NBFIELDOV_6_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_6_reg))

#define  PREDBLK_NBFIELDOV_7                                                     0x1800E8F0
#define  PREDBLK_NBFIELDOV_7_reg_addr                                            "0xB800E8F0"
#define  PREDBLK_NBFIELDOV_7_reg                                                 0xB800E8F0
#define  PREDBLK_NBFIELDOV_7_inst_addr                                           "0x003C"
#define  PREDBLK_NBFIELDOV_7_inst_adr                                            "0x003C"
#define  PREDBLK_NBFIELDOV_7_inst                                                0x003C
#define  set_PREDBLK_NBFIELDOV_7_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_7_reg)=data)
#define  get_PREDBLK_NBFIELDOV_7_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_7_reg))

#define  PREDBLK_NBFIELDOV_8                                                     0x1800E8F4
#define  PREDBLK_NBFIELDOV_8_reg_addr                                            "0xB800E8F4"
#define  PREDBLK_NBFIELDOV_8_reg                                                 0xB800E8F4
#define  PREDBLK_NBFIELDOV_8_inst_addr                                           "0x003D"
#define  PREDBLK_NBFIELDOV_8_inst_adr                                            "0x003D"
#define  PREDBLK_NBFIELDOV_8_inst                                                0x003D
#define  set_PREDBLK_NBFIELDOV_8_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_8_reg)=data)
#define  get_PREDBLK_NBFIELDOV_8_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_8_reg))

#define  PREDBLK_NBFIELDOV_9                                                     0x1800E8F8
#define  PREDBLK_NBFIELDOV_9_reg_addr                                            "0xB800E8F8"
#define  PREDBLK_NBFIELDOV_9_reg                                                 0xB800E8F8
#define  PREDBLK_NBFIELDOV_9_inst_addr                                           "0x003E"
#define  PREDBLK_NBFIELDOV_9_inst_adr                                            "0x003E"
#define  PREDBLK_NBFIELDOV_9_inst                                                0x003E
#define  set_PREDBLK_NBFIELDOV_9_reg(data)                                       (*((volatile unsigned int*)PREDBLK_NBFIELDOV_9_reg)=data)
#define  get_PREDBLK_NBFIELDOV_9_reg                                             (*((volatile unsigned int*)PREDBLK_NBFIELDOV_9_reg))

#define  PREDBLK_NBFIELDOV_10                                                    0x1800E8FC
#define  PREDBLK_NBFIELDOV_10_reg_addr                                           "0xB800E8FC"
#define  PREDBLK_NBFIELDOV_10_reg                                                0xB800E8FC
#define  PREDBLK_NBFIELDOV_10_inst_addr                                          "0x003F"
#define  PREDBLK_NBFIELDOV_10_inst_adr                                           "0x003F"
#define  PREDBLK_NBFIELDOV_10_inst                                               0x003F
#define  set_PREDBLK_NBFIELDOV_10_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_10_reg)=data)
#define  get_PREDBLK_NBFIELDOV_10_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_10_reg))

#define  PREDBLK_NBFIELDOV_11                                                    0x1800E900
#define  PREDBLK_NBFIELDOV_11_reg_addr                                           "0xB800E900"
#define  PREDBLK_NBFIELDOV_11_reg                                                0xB800E900
#define  PREDBLK_NBFIELDOV_11_inst_addr                                          "0x0040"
#define  PREDBLK_NBFIELDOV_11_inst_adr                                           "0x0040"
#define  PREDBLK_NBFIELDOV_11_inst                                               0x0040
#define  set_PREDBLK_NBFIELDOV_11_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_11_reg)=data)
#define  get_PREDBLK_NBFIELDOV_11_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_11_reg))

#define  PREDBLK_NBFIELDOV_12                                                    0x1800E904
#define  PREDBLK_NBFIELDOV_12_reg_addr                                           "0xB800E904"
#define  PREDBLK_NBFIELDOV_12_reg                                                0xB800E904
#define  PREDBLK_NBFIELDOV_12_inst_addr                                          "0x0041"
#define  PREDBLK_NBFIELDOV_12_inst_adr                                           "0x0041"
#define  PREDBLK_NBFIELDOV_12_inst                                               0x0041
#define  set_PREDBLK_NBFIELDOV_12_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_12_reg)=data)
#define  get_PREDBLK_NBFIELDOV_12_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_12_reg))

#define  PREDBLK_NBFIELDOV_13                                                    0x1800E908
#define  PREDBLK_NBFIELDOV_13_reg_addr                                           "0xB800E908"
#define  PREDBLK_NBFIELDOV_13_reg                                                0xB800E908
#define  PREDBLK_NBFIELDOV_13_inst_addr                                          "0x0042"
#define  PREDBLK_NBFIELDOV_13_inst_adr                                           "0x0042"
#define  PREDBLK_NBFIELDOV_13_inst                                               0x0042
#define  set_PREDBLK_NBFIELDOV_13_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_13_reg)=data)
#define  get_PREDBLK_NBFIELDOV_13_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_13_reg))

#define  PREDBLK_NBFIELDOV_14                                                    0x1800E90C
#define  PREDBLK_NBFIELDOV_14_reg_addr                                           "0xB800E90C"
#define  PREDBLK_NBFIELDOV_14_reg                                                0xB800E90C
#define  PREDBLK_NBFIELDOV_14_inst_addr                                          "0x0043"
#define  PREDBLK_NBFIELDOV_14_inst_adr                                           "0x0043"
#define  PREDBLK_NBFIELDOV_14_inst                                               0x0043
#define  set_PREDBLK_NBFIELDOV_14_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_14_reg)=data)
#define  get_PREDBLK_NBFIELDOV_14_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_14_reg))

#define  PREDBLK_NBFIELDOV_15                                                    0x1800E910
#define  PREDBLK_NBFIELDOV_15_reg_addr                                           "0xB800E910"
#define  PREDBLK_NBFIELDOV_15_reg                                                0xB800E910
#define  PREDBLK_NBFIELDOV_15_inst_addr                                          "0x0044"
#define  PREDBLK_NBFIELDOV_15_inst_adr                                           "0x0044"
#define  PREDBLK_NBFIELDOV_15_inst                                               0x0044
#define  set_PREDBLK_NBFIELDOV_15_reg(data)                                      (*((volatile unsigned int*)PREDBLK_NBFIELDOV_15_reg)=data)
#define  get_PREDBLK_NBFIELDOV_15_reg                                            (*((volatile unsigned int*)PREDBLK_NBFIELDOV_15_reg))

#define  PREDBLK_NBEXTRA                                                         0x1800E914
#define  PREDBLK_NBEXTRA_reg_addr                                                "0xB800E914"
#define  PREDBLK_NBEXTRA_reg                                                     0xB800E914
#define  PREDBLK_NBEXTRA_inst_addr                                               "0x0045"
#define  PREDBLK_NBEXTRA_inst_adr                                                "0x0045"
#define  PREDBLK_NBEXTRA_inst                                                    0x0045
#define  set_PREDBLK_NBEXTRA_reg(data)                                           (*((volatile unsigned int*)PREDBLK_NBEXTRA_reg)=data)
#define  get_PREDBLK_NBEXTRA_reg                                                 (*((volatile unsigned int*)PREDBLK_NBEXTRA_reg))
#define  PREDBLK_NBEXTRA_Intra0_shift                                            (3)
#define  PREDBLK_NBEXTRA_Intra1_shift                                            (2)
#define  PREDBLK_NBEXTRA_IntraChroma_shift                                       (1)
#define  PREDBLK_NBEXTRA_IntraField_shift                                        (0)
#define  PREDBLK_NBEXTRA_Intra0_mask                                             (0x00000008)
#define  PREDBLK_NBEXTRA_Intra1_mask                                             (0x00000004)
#define  PREDBLK_NBEXTRA_IntraChroma_mask                                        (0x00000002)
#define  PREDBLK_NBEXTRA_IntraField_mask                                         (0x00000001)
#define  PREDBLK_NBEXTRA_Intra0(data)                                            (0x00000008&((data)<<3))
#define  PREDBLK_NBEXTRA_Intra1(data)                                            (0x00000004&((data)<<2))
#define  PREDBLK_NBEXTRA_IntraChroma(data)                                       (0x00000002&((data)<<1))
#define  PREDBLK_NBEXTRA_IntraField(data)                                        (0x00000001&(data))
#define  PREDBLK_NBEXTRA_get_Intra0(data)                                        ((0x00000008&(data))>>3)
#define  PREDBLK_NBEXTRA_get_Intra1(data)                                        ((0x00000004&(data))>>2)
#define  PREDBLK_NBEXTRA_get_IntraChroma(data)                                   ((0x00000002&(data))>>1)
#define  PREDBLK_NBEXTRA_get_IntraField(data)                                    (0x00000001&(data))
#define  PREDBLK_NBEXTRA_Intra0_src(data)                                        ((0x00000008&(data))>>3)
#define  PREDBLK_NBEXTRA_Intra1_src(data)                                        ((0x00000004&(data))>>2)
#define  PREDBLK_NBEXTRA_IntraChroma_src(data)                                   ((0x00000002&(data))>>1)
#define  PREDBLK_NBEXTRA_IntraField_src(data)                                    (0x00000001&(data))

#define  PREDBLK_WTBLSA                                                          0x1800E918
#define  PREDBLK_WTBLSA_reg_addr                                                 "0xB800E918"
#define  PREDBLK_WTBLSA_reg                                                      0xB800E918
#define  PREDBLK_WTBLSA_inst_addr                                                "0x0046"
#define  PREDBLK_WTBLSA_inst_adr                                                 "0x0046"
#define  PREDBLK_WTBLSA_inst                                                     0x0046
#define  set_PREDBLK_WTBLSA_reg(data)                                            (*((volatile unsigned int*)PREDBLK_WTBLSA_reg)=data)
#define  get_PREDBLK_WTBLSA_reg                                                  (*((volatile unsigned int*)PREDBLK_WTBLSA_reg))
#define  PREDBLK_WTBLSA_WTBL_StartA_shift                                        (0)
#define  PREDBLK_WTBLSA_WTBL_StartA_mask                                         (0x000003FF)
#define  PREDBLK_WTBLSA_WTBL_StartA(data)                                        (0x000003FF&(data))
#define  PREDBLK_WTBLSA_get_WTBL_StartA(data)                                    (0x000003FF&(data))
#define  PREDBLK_WTBLSA_WTBL_StartA_src(data)                                    (0x000003FF&(data))

#define  PREDBLK_WTFLAG_0                                                        0x1800E91C
#define  PREDBLK_WTFLAG_0_reg_addr                                               "0xB800E91C"
#define  PREDBLK_WTFLAG_0_reg                                                    0xB800E91C
#define  PREDBLK_WTFLAG_0_inst_addr                                              "0x0047"
#define  PREDBLK_WTFLAG_0_inst_adr                                               "0x0047"
#define  PREDBLK_WTFLAG_0_inst                                                   0x0047
#define  set_PREDBLK_WTFLAG_0_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_0_reg)=data)
#define  get_PREDBLK_WTFLAG_0_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_0_reg))
#define  PREDBLK_WTFLAG_wt_flag_shift                                            (0)
#define  PREDBLK_WTFLAG_wt_flag_mask                                             (0xFFFFFFFF)
#define  PREDBLK_WTFLAG_wt_flag(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_WTFLAG_get_wt_flag(data)                                        (0xFFFFFFFF&(data))
#define  PREDBLK_WTFLAG_wt_flag_src(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_WTFLAG_1                                                        0x1800E920
#define  PREDBLK_WTFLAG_1_reg_addr                                               "0xB800E920"
#define  PREDBLK_WTFLAG_1_reg                                                    0xB800E920
#define  PREDBLK_WTFLAG_1_inst_addr                                              "0x0048"
#define  PREDBLK_WTFLAG_1_inst_adr                                               "0x0048"
#define  PREDBLK_WTFLAG_1_inst                                                   0x0048
#define  set_PREDBLK_WTFLAG_1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_1_reg)=data)
#define  get_PREDBLK_WTFLAG_1_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_1_reg))

#define  PREDBLK_WTFLAG_2                                                        0x1800E924
#define  PREDBLK_WTFLAG_2_reg_addr                                               "0xB800E924"
#define  PREDBLK_WTFLAG_2_reg                                                    0xB800E924
#define  PREDBLK_WTFLAG_2_inst_addr                                              "0x0049"
#define  PREDBLK_WTFLAG_2_inst_adr                                               "0x0049"
#define  PREDBLK_WTFLAG_2_inst                                                   0x0049
#define  set_PREDBLK_WTFLAG_2_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_2_reg)=data)
#define  get_PREDBLK_WTFLAG_2_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_2_reg))

#define  PREDBLK_WTFLAG_3                                                        0x1800E928
#define  PREDBLK_WTFLAG_3_reg_addr                                               "0xB800E928"
#define  PREDBLK_WTFLAG_3_reg                                                    0xB800E928
#define  PREDBLK_WTFLAG_3_inst_addr                                              "0x004A"
#define  PREDBLK_WTFLAG_3_inst_adr                                               "0x004A"
#define  PREDBLK_WTFLAG_3_inst                                                   0x004A
#define  set_PREDBLK_WTFLAG_3_reg(data)                                          (*((volatile unsigned int*)PREDBLK_WTFLAG_3_reg)=data)
#define  get_PREDBLK_WTFLAG_3_reg                                                (*((volatile unsigned int*)PREDBLK_WTFLAG_3_reg))

#define  PREDBLK_SDMAADR                                                         0x1800E92C
#define  PREDBLK_SDMAADR_reg_addr                                                "0xB800E92C"
#define  PREDBLK_SDMAADR_reg                                                     0xB800E92C
#define  PREDBLK_SDMAADR_inst_addr                                               "0x004B"
#define  PREDBLK_SDMAADR_inst_adr                                                "0x004B"
#define  PREDBLK_SDMAADR_inst                                                    0x004B
#define  set_PREDBLK_SDMAADR_reg(data)                                           (*((volatile unsigned int*)PREDBLK_SDMAADR_reg)=data)
#define  get_PREDBLK_SDMAADR_reg                                                 (*((volatile unsigned int*)PREDBLK_SDMAADR_reg))
#define  PREDBLK_SDMAADR_Wdone_enable_shift                                      (31)
#define  PREDBLK_SDMAADR_Mem_eng_busy_shift                                      (30)
#define  PREDBLK_SDMAADR_seq_line_addr_shift                                     (0)
#define  PREDBLK_SDMAADR_Wdone_enable_mask                                       (0x80000000)
#define  PREDBLK_SDMAADR_Mem_eng_busy_mask                                       (0x40000000)
#define  PREDBLK_SDMAADR_seq_line_addr_mask                                      (0x1FFFFFFF)
#define  PREDBLK_SDMAADR_Wdone_enable(data)                                      (0x80000000&((data)<<31))
#define  PREDBLK_SDMAADR_Mem_eng_busy(data)                                      (0x40000000&((data)<<30))
#define  PREDBLK_SDMAADR_seq_line_addr(data)                                     (0x1FFFFFFF&(data))
#define  PREDBLK_SDMAADR_get_Wdone_enable(data)                                  ((0x80000000&(data))>>31)
#define  PREDBLK_SDMAADR_get_Mem_eng_busy(data)                                  ((0x40000000&(data))>>30)
#define  PREDBLK_SDMAADR_get_seq_line_addr(data)                                 (0x1FFFFFFF&(data))
#define  PREDBLK_SDMAADR_Wdone_enable_src(data)                                  ((0x80000000&(data))>>31)
#define  PREDBLK_SDMAADR_Mem_eng_busy_src(data)                                  ((0x40000000&(data))>>30)
#define  PREDBLK_SDMAADR_seq_line_addr_src(data)                                 (0x1FFFFFFF&(data))

#define  PREDBLK_INTR_THRESH                                                     0x1800E930
#define  PREDBLK_INTR_THRESH_reg_addr                                            "0xB800E930"
#define  PREDBLK_INTR_THRESH_reg                                                 0xB800E930
#define  PREDBLK_INTR_THRESH_inst_addr                                           "0x004C"
#define  PREDBLK_INTR_THRESH_inst_adr                                            "0x004C"
#define  PREDBLK_INTR_THRESH_inst                                                0x004C
#define  set_PREDBLK_INTR_THRESH_reg(data)                                       (*((volatile unsigned int*)PREDBLK_INTR_THRESH_reg)=data)
#define  get_PREDBLK_INTR_THRESH_reg                                             (*((volatile unsigned int*)PREDBLK_INTR_THRESH_reg))
#define  PREDBLK_INTR_THRESH_Value_shift                                         (0)
#define  PREDBLK_INTR_THRESH_Value_mask                                          (0x0FFFFFFF)
#define  PREDBLK_INTR_THRESH_Value(data)                                         (0x0FFFFFFF&(data))
#define  PREDBLK_INTR_THRESH_get_Value(data)                                     (0x0FFFFFFF&(data))
#define  PREDBLK_INTR_THRESH_Value_src(data)                                     (0x0FFFFFFF&(data))

#define  PREDBLK_BUSY                                                            0x1800E934
#define  PREDBLK_BUSY_reg_addr                                                   "0xB800E934"
#define  PREDBLK_BUSY_reg                                                        0xB800E934
#define  PREDBLK_BUSY_inst_addr                                                  "0x004D"
#define  PREDBLK_BUSY_inst_adr                                                   "0x004D"
#define  PREDBLK_BUSY_inst                                                       0x004D
#define  set_PREDBLK_BUSY_reg(data)                                              (*((volatile unsigned int*)PREDBLK_BUSY_reg)=data)
#define  get_PREDBLK_BUSY_reg                                                    (*((volatile unsigned int*)PREDBLK_BUSY_reg))
#define  PREDBLK_BUSY_Reach_Thresh_shift                                         (28)
#define  PREDBLK_BUSY_Count_shift                                                (0)
#define  PREDBLK_BUSY_Reach_Thresh_mask                                          (0x10000000)
#define  PREDBLK_BUSY_Count_mask                                                 (0x0FFFFFFF)
#define  PREDBLK_BUSY_Reach_Thresh(data)                                         (0x10000000&((data)<<28))
#define  PREDBLK_BUSY_Count(data)                                                (0x0FFFFFFF&(data))
#define  PREDBLK_BUSY_get_Reach_Thresh(data)                                     ((0x10000000&(data))>>28)
#define  PREDBLK_BUSY_get_Count(data)                                            (0x0FFFFFFF&(data))
#define  PREDBLK_BUSY_Reach_Thresh_src(data)                                     ((0x10000000&(data))>>28)
#define  PREDBLK_BUSY_Count_src(data)                                            (0x0FFFFFFF&(data))

#define  PREDBLK_BASEA                                                           0x1800E938
#define  PREDBLK_BASEA_reg_addr                                                  "0xB800E938"
#define  PREDBLK_BASEA_reg                                                       0xB800E938
#define  PREDBLK_BASEA_inst_addr                                                 "0x004E"
#define  PREDBLK_BASEA_inst_adr                                                  "0x004E"
#define  PREDBLK_BASEA_inst                                                      0x004E
#define  set_PREDBLK_BASEA_reg(data)                                             (*((volatile unsigned int*)PREDBLK_BASEA_reg)=data)
#define  get_PREDBLK_BASEA_reg                                                   (*((volatile unsigned int*)PREDBLK_BASEA_reg))
#define  PREDBLK_BASEA_BaseA0_shift                                              (16)
#define  PREDBLK_BASEA_BaseA1_shift                                              (3)
#define  PREDBLK_BASEA_BaseA0_mask                                               (0x007F0000)
#define  PREDBLK_BASEA_BaseA1_mask                                               (0x000003F8)
#define  PREDBLK_BASEA_BaseA0(data)                                              (0x007F0000&((data)<<16))
#define  PREDBLK_BASEA_BaseA1(data)                                              (0x000003F8&((data)<<3))
#define  PREDBLK_BASEA_get_BaseA0(data)                                          ((0x007F0000&(data))>>16)
#define  PREDBLK_BASEA_get_BaseA1(data)                                          ((0x000003F8&(data))>>3)
#define  PREDBLK_BASEA_BaseA0_src(data)                                          ((0x007F0000&(data))>>16)
#define  PREDBLK_BASEA_BaseA1_src(data)                                          ((0x000003F8&(data))>>3)

#define  PREDBLK_OFFSETA_0                                                       0x1800E93C
#define  PREDBLK_OFFSETA_0_reg_addr                                              "0xB800E93C"
#define  PREDBLK_OFFSETA_0_reg                                                   0xB800E93C
#define  PREDBLK_OFFSETA_0_inst_addr                                             "0x004F"
#define  PREDBLK_OFFSETA_0_inst_adr                                              "0x004F"
#define  PREDBLK_OFFSETA_0_inst                                                  0x004F
#define  set_PREDBLK_OFFSETA_0_reg(data)                                         (*((volatile unsigned int*)PREDBLK_OFFSETA_0_reg)=data)
#define  get_PREDBLK_OFFSETA_0_reg                                               (*((volatile unsigned int*)PREDBLK_OFFSETA_0_reg))
#define  PREDBLK_OFFSETA_OffsetA_shift                                           (3)
#define  PREDBLK_OFFSETA_OffsetA_mask                                            (0x000003F8)
#define  PREDBLK_OFFSETA_OffsetA(data)                                           (0x000003F8&((data)<<3))
#define  PREDBLK_OFFSETA_get_OffsetA(data)                                       ((0x000003F8&(data))>>3)
#define  PREDBLK_OFFSETA_OffsetA_src(data)                                       ((0x000003F8&(data))>>3)

#define  PREDBLK_OFFSETA_1                                                       0x1800E940
#define  PREDBLK_OFFSETA_1_reg_addr                                              "0xB800E940"
#define  PREDBLK_OFFSETA_1_reg                                                   0xB800E940
#define  PREDBLK_OFFSETA_1_inst_addr                                             "0x0050"
#define  PREDBLK_OFFSETA_1_inst_adr                                              "0x0050"
#define  PREDBLK_OFFSETA_1_inst                                                  0x0050
#define  set_PREDBLK_OFFSETA_1_reg(data)                                         (*((volatile unsigned int*)PREDBLK_OFFSETA_1_reg)=data)
#define  get_PREDBLK_OFFSETA_1_reg                                               (*((volatile unsigned int*)PREDBLK_OFFSETA_1_reg))

#define  PREDBLK_OFFSETA_2                                                       0x1800E944
#define  PREDBLK_OFFSETA_2_reg_addr                                              "0xB800E944"
#define  PREDBLK_OFFSETA_2_reg                                                   0xB800E944
#define  PREDBLK_OFFSETA_2_inst_addr                                             "0x0051"
#define  PREDBLK_OFFSETA_2_inst_adr                                              "0x0051"
#define  PREDBLK_OFFSETA_2_inst                                                  0x0051
#define  set_PREDBLK_OFFSETA_2_reg(data)                                         (*((volatile unsigned int*)PREDBLK_OFFSETA_2_reg)=data)
#define  get_PREDBLK_OFFSETA_2_reg                                               (*((volatile unsigned int*)PREDBLK_OFFSETA_2_reg))

#define  PREDBLK_DEBPAR                                                          0x1800E948
#define  PREDBLK_DEBPAR_reg_addr                                                 "0xB800E948"
#define  PREDBLK_DEBPAR_reg                                                      0xB800E948
#define  PREDBLK_DEBPAR_inst_addr                                                "0x0052"
#define  PREDBLK_DEBPAR_inst_adr                                                 "0x0052"
#define  PREDBLK_DEBPAR_inst                                                     0x0052
#define  set_PREDBLK_DEBPAR_reg(data)                                            (*((volatile unsigned int*)PREDBLK_DEBPAR_reg)=data)
#define  get_PREDBLK_DEBPAR_reg                                                  (*((volatile unsigned int*)PREDBLK_DEBPAR_reg))
#define  PREDBLK_DEBPAR_StartA_shift                                             (0)
#define  PREDBLK_DEBPAR_StartA_mask                                              (0x0000007F)
#define  PREDBLK_DEBPAR_StartA(data)                                             (0x0000007F&(data))
#define  PREDBLK_DEBPAR_get_StartA(data)                                         (0x0000007F&(data))
#define  PREDBLK_DEBPAR_StartA_src(data)                                         (0x0000007F&(data))

#define  PREDBLK_MPEGCTL                                                         0x1800E94C
#define  PREDBLK_MPEGCTL_reg_addr                                                "0xB800E94C"
#define  PREDBLK_MPEGCTL_reg                                                     0xB800E94C
#define  PREDBLK_MPEGCTL_inst_addr                                               "0x0053"
#define  PREDBLK_MPEGCTL_inst_adr                                                "0x0053"
#define  PREDBLK_MPEGCTL_inst                                                    0x0053
#define  set_PREDBLK_MPEGCTL_reg(data)                                           (*((volatile unsigned int*)PREDBLK_MPEGCTL_reg)=data)
#define  get_PREDBLK_MPEGCTL_reg                                                 (*((volatile unsigned int*)PREDBLK_MPEGCTL_reg))
#define  PREDBLK_MPEGCTL_Rounding_Control_shift                                  (1)
#define  PREDBLK_MPEGCTL_Quarter_Sample_shift                                    (0)
#define  PREDBLK_MPEGCTL_Rounding_Control_mask                                   (0x00000002)
#define  PREDBLK_MPEGCTL_Quarter_Sample_mask                                     (0x00000001)
#define  PREDBLK_MPEGCTL_Rounding_Control(data)                                  (0x00000002&((data)<<1))
#define  PREDBLK_MPEGCTL_Quarter_Sample(data)                                    (0x00000001&(data))
#define  PREDBLK_MPEGCTL_get_Rounding_Control(data)                              ((0x00000002&(data))>>1)
#define  PREDBLK_MPEGCTL_get_Quarter_Sample(data)                                (0x00000001&(data))
#define  PREDBLK_MPEGCTL_Rounding_Control_src(data)                              ((0x00000002&(data))>>1)
#define  PREDBLK_MPEGCTL_Quarter_Sample_src(data)                                (0x00000001&(data))

#define  PREDBLK_RMEMDDR1                                                        0x1800E950
#define  PREDBLK_RMEMDDR1_reg_addr                                               "0xB800E950"
#define  PREDBLK_RMEMDDR1_reg                                                    0xB800E950
#define  PREDBLK_RMEMDDR1_inst_addr                                              "0x0054"
#define  PREDBLK_RMEMDDR1_inst_adr                                               "0x0054"
#define  PREDBLK_RMEMDDR1_inst                                                   0x0054
#define  set_PREDBLK_RMEMDDR1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_RMEMDDR1_reg)=data)
#define  get_PREDBLK_RMEMDDR1_reg                                                (*((volatile unsigned int*)PREDBLK_RMEMDDR1_reg))
#define  PREDBLK_RMEMDDR1_Valid_shift                                            (31)
#define  PREDBLK_RMEMDDR1_Base_addr_shift                                        (3)
#define  PREDBLK_RMEMDDR1_Valid_mask                                             (0x80000000)
#define  PREDBLK_RMEMDDR1_Base_addr_mask                                         (0x1FFFFFF8)
#define  PREDBLK_RMEMDDR1_Valid(data)                                            (0x80000000&((data)<<31))
#define  PREDBLK_RMEMDDR1_Base_addr(data)                                        (0x1FFFFFF8&((data)<<3))
#define  PREDBLK_RMEMDDR1_get_Valid(data)                                        ((0x80000000&(data))>>31)
#define  PREDBLK_RMEMDDR1_get_Base_addr(data)                                    ((0x1FFFFFF8&(data))>>3)
#define  PREDBLK_RMEMDDR1_Valid_src(data)                                        ((0x80000000&(data))>>31)
#define  PREDBLK_RMEMDDR1_Base_addr_src(data)                                    ((0x1FFFFFF8&(data))>>3)

#define  PREDBLK_RMEMDDR2                                                        0x1800E954
#define  PREDBLK_RMEMDDR2_reg_addr                                               "0xB800E954"
#define  PREDBLK_RMEMDDR2_reg                                                    0xB800E954
#define  PREDBLK_RMEMDDR2_inst_addr                                              "0x0055"
#define  PREDBLK_RMEMDDR2_inst_adr                                               "0x0055"
#define  PREDBLK_RMEMDDR2_inst                                                   0x0055
#define  set_PREDBLK_RMEMDDR2_reg(data)                                          (*((volatile unsigned int*)PREDBLK_RMEMDDR2_reg)=data)
#define  get_PREDBLK_RMEMDDR2_reg                                                (*((volatile unsigned int*)PREDBLK_RMEMDDR2_reg))
#define  PREDBLK_RMEMDDR2_MBCnt_threshold_shift                                  (0)
#define  PREDBLK_RMEMDDR2_MBCnt_threshold_mask                                   (0xFFFFFFFF)
#define  PREDBLK_RMEMDDR2_MBCnt_threshold(data)                                  (0xFFFFFFFF&(data))
#define  PREDBLK_RMEMDDR2_get_MBCnt_threshold(data)                              (0xFFFFFFFF&(data))
#define  PREDBLK_RMEMDDR2_MBCnt_threshold_src(data)                              (0xFFFFFFFF&(data))

#define  PREDBLK_RMEMCTL                                                         0x1800E958
#define  PREDBLK_RMEMCTL_reg_addr                                                "0xB800E958"
#define  PREDBLK_RMEMCTL_reg                                                     0xB800E958
#define  PREDBLK_RMEMCTL_inst_addr                                               "0x0056"
#define  PREDBLK_RMEMCTL_inst_adr                                                "0x0056"
#define  PREDBLK_RMEMCTL_inst                                                    0x0056
#define  set_PREDBLK_RMEMCTL_reg(data)                                           (*((volatile unsigned int*)PREDBLK_RMEMCTL_reg)=data)
#define  get_PREDBLK_RMEMCTL_reg                                                 (*((volatile unsigned int*)PREDBLK_RMEMCTL_reg))
#define  PREDBLK_RMEMCTL_Valid_shift                                             (31)
#define  PREDBLK_RMEMCTL_Start_Addr_shift                                        (7)
#define  PREDBLK_RMEMCTL_End_Addr_shift                                          (0)
#define  PREDBLK_RMEMCTL_Valid_mask                                              (0x80000000)
#define  PREDBLK_RMEMCTL_Start_Addr_mask                                         (0x00003F80)
#define  PREDBLK_RMEMCTL_End_Addr_mask                                           (0x0000007F)
#define  PREDBLK_RMEMCTL_Valid(data)                                             (0x80000000&((data)<<31))
#define  PREDBLK_RMEMCTL_Start_Addr(data)                                        (0x00003F80&((data)<<7))
#define  PREDBLK_RMEMCTL_End_Addr(data)                                          (0x0000007F&(data))
#define  PREDBLK_RMEMCTL_get_Valid(data)                                         ((0x80000000&(data))>>31)
#define  PREDBLK_RMEMCTL_get_Start_Addr(data)                                    ((0x00003F80&(data))>>7)
#define  PREDBLK_RMEMCTL_get_End_Addr(data)                                      (0x0000007F&(data))
#define  PREDBLK_RMEMCTL_Valid_src(data)                                         ((0x80000000&(data))>>31)
#define  PREDBLK_RMEMCTL_Start_Addr_src(data)                                    ((0x00003F80&(data))>>7)
#define  PREDBLK_RMEMCTL_End_Addr_src(data)                                      (0x0000007F&(data))

#define  PREDBLK_URATIO_0                                                        0x1800E95C
#define  PREDBLK_URATIO_0_reg_addr                                               "0xB800E95C"
#define  PREDBLK_URATIO_0_reg                                                    0xB800E95C
#define  PREDBLK_URATIO_0_inst_addr                                              "0x0057"
#define  PREDBLK_URATIO_0_inst_adr                                               "0x0057"
#define  PREDBLK_URATIO_0_inst                                                   0x0057
#define  set_PREDBLK_URATIO_0_reg(data)                                          (*((volatile unsigned int*)PREDBLK_URATIO_0_reg)=data)
#define  get_PREDBLK_URATIO_0_reg                                                (*((volatile unsigned int*)PREDBLK_URATIO_0_reg))
#define  PREDBLK_URATIO_URatio_shift                                             (0)
#define  PREDBLK_URATIO_URatio_mask                                              (0x00007FFF)
#define  PREDBLK_URATIO_URatio(data)                                             (0x00007FFF&(data))
#define  PREDBLK_URATIO_get_URatio(data)                                         (0x00007FFF&(data))
#define  PREDBLK_URATIO_URatio_src(data)                                         (0x00007FFF&(data))

#define  PREDBLK_URATIO_1                                                        0x1800E960
#define  PREDBLK_URATIO_1_reg_addr                                               "0xB800E960"
#define  PREDBLK_URATIO_1_reg                                                    0xB800E960
#define  PREDBLK_URATIO_1_inst_addr                                              "0x0058"
#define  PREDBLK_URATIO_1_inst_adr                                               "0x0058"
#define  PREDBLK_URATIO_1_inst                                                   0x0058
#define  set_PREDBLK_URATIO_1_reg(data)                                          (*((volatile unsigned int*)PREDBLK_URATIO_1_reg)=data)
#define  get_PREDBLK_URATIO_1_reg                                                (*((volatile unsigned int*)PREDBLK_URATIO_1_reg))

#define  PREDBLK_DBUS                                                            0x1800E968
#define  PREDBLK_DBUS_reg_addr                                                   "0xB800E968"
#define  PREDBLK_DBUS_reg                                                        0xB800E968
#define  PREDBLK_DBUS_inst_addr                                                  "0x0059"
#define  PREDBLK_DBUS_inst_adr                                                   "0x005A"
#define  PREDBLK_DBUS_inst                                                       0x005A
#define  set_PREDBLK_DBUS_reg(data)                                              (*((volatile unsigned int*)PREDBLK_DBUS_reg)=data)
#define  get_PREDBLK_DBUS_reg                                                    (*((volatile unsigned int*)PREDBLK_DBUS_reg))
#define  PREDBLK_DBUS_GenPulse_shift                                             (31)
#define  PREDBLK_DBUS_PicCount_shift                                             (17)
#define  PREDBLK_DBUS_MbAddrX_shift                                              (8)
#define  PREDBLK_DBUS_MbAddrY_shift                                              (0)
#define  PREDBLK_DBUS_GenPulse_mask                                              (0x80000000)
#define  PREDBLK_DBUS_PicCount_mask                                              (0x7FFE0000)
#define  PREDBLK_DBUS_MbAddrX_mask                                               (0x0001FF00)
#define  PREDBLK_DBUS_MbAddrY_mask                                               (0x000000FF)
#define  PREDBLK_DBUS_GenPulse(data)                                             (0x80000000&((data)<<31))
#define  PREDBLK_DBUS_PicCount(data)                                             (0x7FFE0000&((data)<<17))
#define  PREDBLK_DBUS_MbAddrX(data)                                              (0x0001FF00&((data)<<8))
#define  PREDBLK_DBUS_MbAddrY(data)                                              (0x000000FF&(data))
#define  PREDBLK_DBUS_get_GenPulse(data)                                         ((0x80000000&(data))>>31)
#define  PREDBLK_DBUS_get_PicCount(data)                                         ((0x7FFE0000&(data))>>17)
#define  PREDBLK_DBUS_get_MbAddrX(data)                                          ((0x0001FF00&(data))>>8)
#define  PREDBLK_DBUS_get_MbAddrY(data)                                          (0x000000FF&(data))
#define  PREDBLK_DBUS_GenPulse_src(data)                                         ((0x80000000&(data))>>31)
#define  PREDBLK_DBUS_PicCount_src(data)                                         ((0x7FFE0000&(data))>>17)
#define  PREDBLK_DBUS_MbAddrX_src(data)                                          ((0x0001FF00&(data))>>8)
#define  PREDBLK_DBUS_MbAddrY_src(data)                                          (0x000000FF&(data))

#define  PREDBLK_DBUS2                                                           0x1800E96C
#define  PREDBLK_DBUS2_reg_addr                                                  "0xB800E96C"
#define  PREDBLK_DBUS2_reg                                                       0xB800E96C
#define  PREDBLK_DBUS2_inst_addr                                                 "0x005A"
#define  PREDBLK_DBUS2_inst_adr                                                  "0x005B"
#define  PREDBLK_DBUS2_inst                                                      0x005B
#define  set_PREDBLK_DBUS2_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS2_reg)=data)
#define  get_PREDBLK_DBUS2_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS2_reg))
#define  PREDBLK_DBUS2_DbgCtrl_shift                                             (0)
#define  PREDBLK_DBUS2_DbgCtrl_mask                                              (0xFFFFFFFF)
#define  PREDBLK_DBUS2_DbgCtrl(data)                                             (0xFFFFFFFF&(data))
#define  PREDBLK_DBUS2_get_DbgCtrl(data)                                         (0xFFFFFFFF&(data))
#define  PREDBLK_DBUS2_DbgCtrl_src(data)                                         (0xFFFFFFFF&(data))

#define  PREDBLK_DBUS3                                                           0x1800E9F0
#define  PREDBLK_DBUS3_reg_addr                                                  "0xB800E9F0"
#define  PREDBLK_DBUS3_reg                                                       0xB800E9F0
#define  PREDBLK_DBUS3_inst_addr                                                 "0x005B"
#define  PREDBLK_DBUS3_inst_adr                                                  "0x007C"
#define  PREDBLK_DBUS3_inst                                                      0x007C
#define  set_PREDBLK_DBUS3_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS3_reg)=data)
#define  get_PREDBLK_DBUS3_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS3_reg))
#define  PREDBLK_DBUS3_DbgCtrl3_shift                                            (3)
#define  PREDBLK_DBUS3_DbgCtrl_shift                                             (0)
#define  PREDBLK_DBUS3_DbgCtrl3_mask                                             (0xFFFFFFF8)
#define  PREDBLK_DBUS3_DbgCtrl_mask                                              (0x00000007)
#define  PREDBLK_DBUS3_DbgCtrl3(data)                                            (0xFFFFFFF8&((data)<<3))
#define  PREDBLK_DBUS3_DbgCtrl(data)                                             (0x00000007&(data))
#define  PREDBLK_DBUS3_get_DbgCtrl3(data)                                        ((0xFFFFFFF8&(data))>>3)
#define  PREDBLK_DBUS3_get_DbgCtrl(data)                                         (0x00000007&(data))
#define  PREDBLK_DBUS3_DbgCtrl3_src(data)                                        ((0xFFFFFFF8&(data))>>3)
#define  PREDBLK_DBUS3_DbgCtrl_src(data)                                         (0x00000007&(data))

#define  PREDBLK_DMAMSB                                                          0x1800E970
#define  PREDBLK_DMAMSB_reg_addr                                                 "0xB800E970"
#define  PREDBLK_DMAMSB_reg                                                      0xB800E970
#define  PREDBLK_DMAMSB_inst_addr                                                "0x005C"
#define  PREDBLK_DMAMSB_inst_adr                                                 "0x005C"
#define  PREDBLK_DMAMSB_inst                                                     0x005C
#define  set_PREDBLK_DMAMSB_reg(data)                                            (*((volatile unsigned int*)PREDBLK_DMAMSB_reg)=data)
#define  get_PREDBLK_DMAMSB_reg                                                  (*((volatile unsigned int*)PREDBLK_DMAMSB_reg))
#define  PREDBLK_DMAMSB_SDMAWR1MSB_shift                                         (6)
#define  PREDBLK_DMAMSB_SDMA2MSB_shift                                           (3)
#define  PREDBLK_DMAMSB_RMEM2MSB_shift                                           (0)
#define  PREDBLK_DMAMSB_SDMAWR1MSB_mask                                          (0x00000040)
#define  PREDBLK_DMAMSB_SDMA2MSB_mask                                            (0x00000038)
#define  PREDBLK_DMAMSB_RMEM2MSB_mask                                            (0x00000007)
#define  PREDBLK_DMAMSB_SDMAWR1MSB(data)                                         (0x00000040&((data)<<6))
#define  PREDBLK_DMAMSB_SDMA2MSB(data)                                           (0x00000038&((data)<<3))
#define  PREDBLK_DMAMSB_RMEM2MSB(data)                                           (0x00000007&(data))
#define  PREDBLK_DMAMSB_get_SDMAWR1MSB(data)                                     ((0x00000040&(data))>>6)
#define  PREDBLK_DMAMSB_get_SDMA2MSB(data)                                       ((0x00000038&(data))>>3)
#define  PREDBLK_DMAMSB_get_RMEM2MSB(data)                                       (0x00000007&(data))
#define  PREDBLK_DMAMSB_SDMAWR1MSB_src(data)                                     ((0x00000040&(data))>>6)
#define  PREDBLK_DMAMSB_SDMA2MSB_src(data)                                       ((0x00000038&(data))>>3)
#define  PREDBLK_DMAMSB_RMEM2MSB_src(data)                                       (0x00000007&(data))

#define  PREDBLK_DMEMADR                                                         0x1800E974
#define  PREDBLK_DMEMADR_reg_addr                                                "0xB800E974"
#define  PREDBLK_DMEMADR_reg                                                     0xB800E974
#define  PREDBLK_DMEMADR_inst_addr                                               "0x005D"
#define  PREDBLK_DMEMADR_inst_adr                                                "0x005D"
#define  PREDBLK_DMEMADR_inst                                                    0x005D
#define  set_PREDBLK_DMEMADR_reg(data)                                           (*((volatile unsigned int*)PREDBLK_DMEMADR_reg)=data)
#define  get_PREDBLK_DMEMADR_reg                                                 (*((volatile unsigned int*)PREDBLK_DMEMADR_reg))
#define  PREDBLK_DMEMADR_BaseAddr_shift                                          (0)
#define  PREDBLK_DMEMADR_BaseAddr_mask                                           (0x00000FFF)
#define  PREDBLK_DMEMADR_BaseAddr(data)                                          (0x00000FFF&(data))
#define  PREDBLK_DMEMADR_get_BaseAddr(data)                                      (0x00000FFF&(data))
#define  PREDBLK_DMEMADR_BaseAddr_src(data)                                      (0x00000FFF&(data))

#define  PREDBLK_DMEMOP                                                          0x1800E990
#define  PREDBLK_DMEMOP_reg_addr                                                 "0xB800E990"
#define  PREDBLK_DMEMOP_reg                                                      0xB800E990
#define  PREDBLK_DMEMOP_inst_addr                                                "0x005E"
#define  PREDBLK_DMEMOP_inst_adr                                                 "0x0064"
#define  PREDBLK_DMEMOP_inst                                                     0x0064
#define  set_PREDBLK_DMEMOP_reg(data)                                            (*((volatile unsigned int*)PREDBLK_DMEMOP_reg)=data)
#define  get_PREDBLK_DMEMOP_reg                                                  (*((volatile unsigned int*)PREDBLK_DMEMOP_reg))
#define  PREDBLK_DMEMOP_Count_shift                                              (0)
#define  PREDBLK_DMEMOP_Count_mask                                               (0x0FFFFFFF)
#define  PREDBLK_DMEMOP_Count(data)                                              (0x0FFFFFFF&(data))
#define  PREDBLK_DMEMOP_get_Count(data)                                          (0x0FFFFFFF&(data))
#define  PREDBLK_DMEMOP_Count_src(data)                                          (0x0FFFFFFF&(data))

#define  PREDBLK_SLICE_RESTART                                                   0x1800E994
#define  PREDBLK_SLICE_RESTART_reg_addr                                          "0xB800E994"
#define  PREDBLK_SLICE_RESTART_reg                                               0xB800E994
#define  PREDBLK_SLICE_RESTART_inst_addr                                         "0x005F"
#define  PREDBLK_SLICE_RESTART_inst_adr                                          "0x0065"
#define  PREDBLK_SLICE_RESTART_inst                                              0x0065
#define  set_PREDBLK_SLICE_RESTART_reg(data)                                     (*((volatile unsigned int*)PREDBLK_SLICE_RESTART_reg)=data)
#define  get_PREDBLK_SLICE_RESTART_reg                                           (*((volatile unsigned int*)PREDBLK_SLICE_RESTART_reg))
#define  PREDBLK_SLICE_RESTART_hw_enable_shift                                   (31)
#define  PREDBLK_SLICE_RESTART_Pmem_idle_shift                                   (0)
#define  PREDBLK_SLICE_RESTART_hw_enable_mask                                    (0x80000000)
#define  PREDBLK_SLICE_RESTART_Pmem_idle_mask                                    (0x00000001)
#define  PREDBLK_SLICE_RESTART_hw_enable(data)                                   (0x80000000&((data)<<31))
#define  PREDBLK_SLICE_RESTART_Pmem_idle(data)                                   (0x00000001&(data))
#define  PREDBLK_SLICE_RESTART_get_hw_enable(data)                               ((0x80000000&(data))>>31)
#define  PREDBLK_SLICE_RESTART_get_Pmem_idle(data)                               (0x00000001&(data))
#define  PREDBLK_SLICE_RESTART_hw_enable_src(data)                               ((0x80000000&(data))>>31)
#define  PREDBLK_SLICE_RESTART_Pmem_idle_src(data)                               (0x00000001&(data))

#define  PREDBLK_SLICE_DBG0                                                      0x1800E998
#define  PREDBLK_SLICE_DBG0_reg_addr                                             "0xB800E998"
#define  PREDBLK_SLICE_DBG0_reg                                                  0xB800E998
#define  PREDBLK_SLICE_DBG0_inst_addr                                            "0x0060"
#define  PREDBLK_SLICE_DBG0_inst_adr                                             "0x0066"
#define  PREDBLK_SLICE_DBG0_inst                                                 0x0066
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
#define  PREDBLK_SLICE_DBG0_sw_override_src(data)                                ((0x80000000&(data))>>31)
#define  PREDBLK_SLICE_DBG0_ddr_inb_rdadr_src(data)                              ((0x01E00000&(data))>>21)
#define  PREDBLK_SLICE_DBG0_ddr_out_rdadr_src(data)                              ((0x001F8000&(data))>>15)
#define  PREDBLK_SLICE_DBG0_inb_mbcnt_src(data)                                  ((0x00007800&(data))>>11)
#define  PREDBLK_SLICE_DBG0_out_mbcnt_src(data)                                  ((0x00000780&(data))>>7)
#define  PREDBLK_SLICE_DBG0_pmem_inb_mbptr_src(data)                             ((0x00000078&(data))>>3)
#define  PREDBLK_SLICE_DBG0_pmem_out_mbptr_src(data)                             (0x00000007&(data))

#define  PREDBLK_SLICE_DBG1                                                      0x1800E99C
#define  PREDBLK_SLICE_DBG1_reg_addr                                             "0xB800E99C"
#define  PREDBLK_SLICE_DBG1_reg                                                  0xB800E99C
#define  PREDBLK_SLICE_DBG1_inst_addr                                            "0x0061"
#define  PREDBLK_SLICE_DBG1_inst_adr                                             "0x0067"
#define  PREDBLK_SLICE_DBG1_inst                                                 0x0067
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
#define  PREDBLK_SLICE_DBG1_ddr_rng_rdptr_src(data)                              ((0x3FF00000&(data))>>20)
#define  PREDBLK_SLICE_DBG1_ddr_rng_wrptr_src(data)                              ((0x000FFC00&(data))>>10)
#define  PREDBLK_SLICE_DBG1_ddr_rng_size_src(data)                               (0x000003FF&(data))

#define  PREDBLK_CONFLICT                                                        0x1800E9A0
#define  PREDBLK_CONFLICT_reg_addr                                               "0xB800E9A0"
#define  PREDBLK_CONFLICT_reg                                                    0xB800E9A0
#define  PREDBLK_CONFLICT_inst_addr                                              "0x0062"
#define  PREDBLK_CONFLICT_inst_adr                                               "0x0068"
#define  PREDBLK_CONFLICT_inst                                                   0x0068
#define  set_PREDBLK_CONFLICT_reg(data)                                          (*((volatile unsigned int*)PREDBLK_CONFLICT_reg)=data)
#define  get_PREDBLK_CONFLICT_reg                                                (*((volatile unsigned int*)PREDBLK_CONFLICT_reg))
#define  PREDBLK_CONFLICT_On_shift                                               (31)
#define  PREDBLK_CONFLICT_Bank0_shift                                            (12)
#define  PREDBLK_CONFLICT_Bank1_shift                                            (8)
#define  PREDBLK_CONFLICT_Bank2_shift                                            (4)
#define  PREDBLK_CONFLICT_Bank3_shift                                            (0)
#define  PREDBLK_CONFLICT_On_mask                                                (0x80000000)
#define  PREDBLK_CONFLICT_Bank0_mask                                             (0x0000F000)
#define  PREDBLK_CONFLICT_Bank1_mask                                             (0x00000F00)
#define  PREDBLK_CONFLICT_Bank2_mask                                             (0x000000F0)
#define  PREDBLK_CONFLICT_Bank3_mask                                             (0x0000000F)
#define  PREDBLK_CONFLICT_On(data)                                               (0x80000000&((data)<<31))
#define  PREDBLK_CONFLICT_Bank0(data)                                            (0x0000F000&((data)<<12))
#define  PREDBLK_CONFLICT_Bank1(data)                                            (0x00000F00&((data)<<8))
#define  PREDBLK_CONFLICT_Bank2(data)                                            (0x000000F0&((data)<<4))
#define  PREDBLK_CONFLICT_Bank3(data)                                            (0x0000000F&(data))
#define  PREDBLK_CONFLICT_get_On(data)                                           ((0x80000000&(data))>>31)
#define  PREDBLK_CONFLICT_get_Bank0(data)                                        ((0x0000F000&(data))>>12)
#define  PREDBLK_CONFLICT_get_Bank1(data)                                        ((0x00000F00&(data))>>8)
#define  PREDBLK_CONFLICT_get_Bank2(data)                                        ((0x000000F0&(data))>>4)
#define  PREDBLK_CONFLICT_get_Bank3(data)                                        (0x0000000F&(data))
#define  PREDBLK_CONFLICT_On_src(data)                                           ((0x80000000&(data))>>31)
#define  PREDBLK_CONFLICT_Bank0_src(data)                                        ((0x0000F000&(data))>>12)
#define  PREDBLK_CONFLICT_Bank1_src(data)                                        ((0x00000F00&(data))>>8)
#define  PREDBLK_CONFLICT_Bank2_src(data)                                        ((0x000000F0&(data))>>4)
#define  PREDBLK_CONFLICT_Bank3_src(data)                                        (0x0000000F&(data))

#define  PREDBLK_ENCUMEM                                                         0x1800E9A4
#define  PREDBLK_ENCUMEM_reg_addr                                                "0xB800E9A4"
#define  PREDBLK_ENCUMEM_reg                                                     0xB800E9A4
#define  PREDBLK_ENCUMEM_inst_addr                                               "0x0063"
#define  PREDBLK_ENCUMEM_inst_adr                                                "0x0069"
#define  PREDBLK_ENCUMEM_inst                                                    0x0069
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
#define  PREDBLK_ENCUMEM_dma_src(data)                                           ((0x000000C0&(data))>>6)
#define  PREDBLK_ENCUMEM_ime_src(data)                                           ((0x00000030&(data))>>4)
#define  PREDBLK_ENCUMEM_fme_src(data)                                           ((0x0000000C&(data))>>2)
#define  PREDBLK_ENCUMEM_gcf_src(data)                                           (0x00000003&(data))

#define  PREDBLK_HEVC_UMEM_CTRL                                                  0x1800E9A8
#define  PREDBLK_HEVC_UMEM_CTRL_reg_addr                                         "0xB800E9A8"
#define  PREDBLK_HEVC_UMEM_CTRL_reg                                              0xB800E9A8
#define  PREDBLK_HEVC_UMEM_CTRL_inst_addr                                        "0x0064"
#define  PREDBLK_HEVC_UMEM_CTRL_inst_adr                                         "0x006A"
#define  PREDBLK_HEVC_UMEM_CTRL_inst                                             0x006A
#define  set_PREDBLK_HEVC_UMEM_CTRL_reg(data)                                    (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL_reg)=data)
#define  get_PREDBLK_HEVC_UMEM_CTRL_reg                                          (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL_reg))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10_shift                             (25)
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en_shift                                  (24)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9_shift                              (23)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank5_Owner_shift                                (22)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8_shift                              (21)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank4_Owner_shift                                (20)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7_shift                              (19)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank3_Owner_shift                                (18)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6_shift                              (17)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank2_Owner_shift                                (16)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5_shift                              (15)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank1_Owner_shift                                (14)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4_shift                              (13)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank0_Owner_shift                                (12)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3_shift                              (11)
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank_shift                                 (7)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2_shift                              (6)
#define  PREDBLK_HEVC_UMEM_CTRL_Pred_bank_shift                                  (2)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1_shift                              (1)
#define  PREDBLK_HEVC_UMEM_CTRL_Umem_init_shift                                  (0)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10_mask                              (0x02000000)
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en_mask                                   (0x01000000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9_mask                               (0x00800000)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank5_Owner_mask                                 (0x00400000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8_mask                               (0x00200000)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank4_Owner_mask                                 (0x00100000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7_mask                               (0x00080000)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank3_Owner_mask                                 (0x00040000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6_mask                               (0x00020000)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank2_Owner_mask                                 (0x00010000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5_mask                               (0x00008000)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank1_Owner_mask                                 (0x00004000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4_mask                               (0x00002000)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank0_Owner_mask                                 (0x00001000)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3_mask                               (0x00000800)
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank_mask                                  (0x00000780)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2_mask                               (0x00000040)
#define  PREDBLK_HEVC_UMEM_CTRL_Pred_bank_mask                                   (0x0000003C)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1_mask                               (0x00000002)
#define  PREDBLK_HEVC_UMEM_CTRL_Umem_init_mask                                   (0x00000001)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10(data)                             (0x02000000&((data)<<25))
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en(data)                                  (0x01000000&((data)<<24))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9(data)                              (0x00800000&((data)<<23))
#define  PREDBLK_HEVC_UMEM_CTRL_Bank5_Owner(data)                                (0x00400000&((data)<<22))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8(data)                              (0x00200000&((data)<<21))
#define  PREDBLK_HEVC_UMEM_CTRL_Bank4_Owner(data)                                (0x00100000&((data)<<20))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7(data)                              (0x00080000&((data)<<19))
#define  PREDBLK_HEVC_UMEM_CTRL_Bank3_Owner(data)                                (0x00040000&((data)<<18))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6(data)                              (0x00020000&((data)<<17))
#define  PREDBLK_HEVC_UMEM_CTRL_Bank2_Owner(data)                                (0x00010000&((data)<<16))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5(data)                              (0x00008000&((data)<<15))
#define  PREDBLK_HEVC_UMEM_CTRL_Bank1_Owner(data)                                (0x00004000&((data)<<14))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4(data)                              (0x00002000&((data)<<13))
#define  PREDBLK_HEVC_UMEM_CTRL_Bank0_Owner(data)                                (0x00001000&((data)<<12))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3(data)                              (0x00000800&((data)<<11))
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank(data)                                 (0x00000780&((data)<<7))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2(data)                              (0x00000040&((data)<<6))
#define  PREDBLK_HEVC_UMEM_CTRL_Pred_bank(data)                                  (0x0000003C&((data)<<2))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1(data)                              (0x00000002&((data)<<1))
#define  PREDBLK_HEVC_UMEM_CTRL_Umem_init(data)                                  (0x00000001&(data))
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable10(data)                         ((0x02000000&(data))>>25)
#define  PREDBLK_HEVC_UMEM_CTRL_get_um_dbg_en(data)                              ((0x01000000&(data))>>24)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable9(data)                          ((0x00800000&(data))>>23)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Bank5_Owner(data)                            ((0x00400000&(data))>>22)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable8(data)                          ((0x00200000&(data))>>21)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Bank4_Owner(data)                            ((0x00100000&(data))>>20)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable7(data)                          ((0x00080000&(data))>>19)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Bank3_Owner(data)                            ((0x00040000&(data))>>18)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable6(data)                          ((0x00020000&(data))>>17)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Bank2_Owner(data)                            ((0x00010000&(data))>>16)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable5(data)                          ((0x00008000&(data))>>15)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Bank1_Owner(data)                            ((0x00004000&(data))>>14)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable4(data)                          ((0x00002000&(data))>>13)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Bank0_Owner(data)                            ((0x00001000&(data))>>12)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable3(data)                          ((0x00000800&(data))>>11)
#define  PREDBLK_HEVC_UMEM_CTRL_get_itblk_bank(data)                             ((0x00000780&(data))>>7)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable2(data)                          ((0x00000040&(data))>>6)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Pred_bank(data)                              ((0x0000003C&(data))>>2)
#define  PREDBLK_HEVC_UMEM_CTRL_get_write_enable1(data)                          ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_UMEM_CTRL_get_Umem_init(data)                              (0x00000001&(data))
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable10_src(data)                         ((0x02000000&(data))>>25)
#define  PREDBLK_HEVC_UMEM_CTRL_um_dbg_en_src(data)                              ((0x01000000&(data))>>24)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable9_src(data)                          ((0x00800000&(data))>>23)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank5_Owner_src(data)                            ((0x00400000&(data))>>22)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable8_src(data)                          ((0x00200000&(data))>>21)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank4_Owner_src(data)                            ((0x00100000&(data))>>20)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable7_src(data)                          ((0x00080000&(data))>>19)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank3_Owner_src(data)                            ((0x00040000&(data))>>18)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable6_src(data)                          ((0x00020000&(data))>>17)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank2_Owner_src(data)                            ((0x00010000&(data))>>16)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable5_src(data)                          ((0x00008000&(data))>>15)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank1_Owner_src(data)                            ((0x00004000&(data))>>14)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable4_src(data)                          ((0x00002000&(data))>>13)
#define  PREDBLK_HEVC_UMEM_CTRL_Bank0_Owner_src(data)                            ((0x00001000&(data))>>12)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable3_src(data)                          ((0x00000800&(data))>>11)
#define  PREDBLK_HEVC_UMEM_CTRL_itblk_bank_src(data)                             ((0x00000780&(data))>>7)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable2_src(data)                          ((0x00000040&(data))>>6)
#define  PREDBLK_HEVC_UMEM_CTRL_Pred_bank_src(data)                              ((0x0000003C&(data))>>2)
#define  PREDBLK_HEVC_UMEM_CTRL_write_enable1_src(data)                          ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_UMEM_CTRL_Umem_init_src(data)                              (0x00000001&(data))

#define  PREDBLK_HEVC_UMEM_CTRL2                                                 0x1800E9F4
#define  PREDBLK_HEVC_UMEM_CTRL2_reg_addr                                        "0xB800E9F4"
#define  PREDBLK_HEVC_UMEM_CTRL2_reg                                             0xB800E9F4
#define  PREDBLK_HEVC_UMEM_CTRL2_inst_addr                                       "0x0065"
#define  PREDBLK_HEVC_UMEM_CTRL2_inst_adr                                        "0x007D"
#define  PREDBLK_HEVC_UMEM_CTRL2_inst                                            0x007D
#define  set_PREDBLK_HEVC_UMEM_CTRL2_reg(data)                                   (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL2_reg)=data)
#define  get_PREDBLK_HEVC_UMEM_CTRL2_reg                                         (*((volatile unsigned int*)PREDBLK_HEVC_UMEM_CTRL2_reg))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4_shift                             (7)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank9_Owner_shift                               (6)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3_shift                             (5)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank8_Owner_shift                               (4)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2_shift                             (3)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank7_Owner_shift                               (2)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1_shift                             (1)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank6_Owner_shift                               (0)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4_mask                              (0x00000080)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank9_Owner_mask                                (0x00000040)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3_mask                              (0x00000020)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank8_Owner_mask                                (0x00000010)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2_mask                              (0x00000008)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank7_Owner_mask                                (0x00000004)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1_mask                              (0x00000002)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank6_Owner_mask                                (0x00000001)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4(data)                             (0x00000080&((data)<<7))
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank9_Owner(data)                               (0x00000040&((data)<<6))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3(data)                             (0x00000020&((data)<<5))
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank8_Owner(data)                               (0x00000010&((data)<<4))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2(data)                             (0x00000008&((data)<<3))
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank7_Owner(data)                               (0x00000004&((data)<<2))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1(data)                             (0x00000002&((data)<<1))
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank6_Owner(data)                               (0x00000001&(data))
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable4(data)                         ((0x00000080&(data))>>7)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_Bank9_Owner(data)                           ((0x00000040&(data))>>6)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable3(data)                         ((0x00000020&(data))>>5)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_Bank8_Owner(data)                           ((0x00000010&(data))>>4)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable2(data)                         ((0x00000008&(data))>>3)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_Bank7_Owner(data)                           ((0x00000004&(data))>>2)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_write_enable1(data)                         ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_UMEM_CTRL2_get_Bank6_Owner(data)                           (0x00000001&(data))
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable4_src(data)                         ((0x00000080&(data))>>7)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank9_Owner_src(data)                           ((0x00000040&(data))>>6)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable3_src(data)                         ((0x00000020&(data))>>5)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank8_Owner_src(data)                           ((0x00000010&(data))>>4)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable2_src(data)                         ((0x00000008&(data))>>3)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank7_Owner_src(data)                           ((0x00000004&(data))>>2)
#define  PREDBLK_HEVC_UMEM_CTRL2_write_enable1_src(data)                         ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_UMEM_CTRL2_Bank6_Owner_src(data)                           (0x00000001&(data))

#define  PREDBLK_SDMAWRADR                                                       0x1800E9B0
#define  PREDBLK_SDMAWRADR_reg_addr                                              "0xB800E9B0"
#define  PREDBLK_SDMAWRADR_reg                                                   0xB800E9B0
#define  PREDBLK_SDMAWRADR_inst_addr                                             "0x0066"
#define  PREDBLK_SDMAWRADR_inst_adr                                              "0x006C"
#define  PREDBLK_SDMAWRADR_inst                                                  0x006C
#define  set_PREDBLK_SDMAWRADR_reg(data)                                         (*((volatile unsigned int*)PREDBLK_SDMAWRADR_reg)=data)
#define  get_PREDBLK_SDMAWRADR_reg                                               (*((volatile unsigned int*)PREDBLK_SDMAWRADR_reg))
#define  PREDBLK_SDMAWRADR_Enable_shift                                          (31)
#define  PREDBLK_SDMAWRADR_seq_line_addr_shift                                   (0)
#define  PREDBLK_SDMAWRADR_Enable_mask                                           (0x80000000)
#define  PREDBLK_SDMAWRADR_seq_line_addr_mask                                    (0x7FFFFFFF)
#define  PREDBLK_SDMAWRADR_Enable(data)                                          (0x80000000&((data)<<31))
#define  PREDBLK_SDMAWRADR_seq_line_addr(data)                                   (0x7FFFFFFF&(data))
#define  PREDBLK_SDMAWRADR_get_Enable(data)                                      ((0x80000000&(data))>>31)
#define  PREDBLK_SDMAWRADR_get_seq_line_addr(data)                               (0x7FFFFFFF&(data))
#define  PREDBLK_SDMAWRADR_Enable_src(data)                                      ((0x80000000&(data))>>31)
#define  PREDBLK_SDMAWRADR_seq_line_addr_src(data)                               (0x7FFFFFFF&(data))

#define  PREDBLK_DECCNTL                                                         0x1800E9B4
#define  PREDBLK_DECCNTL_reg_addr                                                "0xB800E9B4"
#define  PREDBLK_DECCNTL_reg                                                     0xB800E9B4
#define  PREDBLK_DECCNTL_inst_addr                                               "0x0067"
#define  PREDBLK_DECCNTL_inst_adr                                                "0x006D"
#define  PREDBLK_DECCNTL_inst                                                    0x006D
#define  set_PREDBLK_DECCNTL_reg(data)                                           (*((volatile unsigned int*)PREDBLK_DECCNTL_reg)=data)
#define  get_PREDBLK_DECCNTL_reg                                                 (*((volatile unsigned int*)PREDBLK_DECCNTL_reg))
#define  PREDBLK_DECCNTL_Reset_shift                                             (1)
#define  PREDBLK_DECCNTL_Start_shift                                             (0)
#define  PREDBLK_DECCNTL_Reset_mask                                              (0x00000002)
#define  PREDBLK_DECCNTL_Start_mask                                              (0x00000001)
#define  PREDBLK_DECCNTL_Reset(data)                                             (0x00000002&((data)<<1))
#define  PREDBLK_DECCNTL_Start(data)                                             (0x00000001&(data))
#define  PREDBLK_DECCNTL_get_Reset(data)                                         ((0x00000002&(data))>>1)
#define  PREDBLK_DECCNTL_get_Start(data)                                         (0x00000001&(data))
#define  PREDBLK_DECCNTL_Reset_src(data)                                         ((0x00000002&(data))>>1)
#define  PREDBLK_DECCNTL_Start_src(data)                                         (0x00000001&(data))

#define  PREDBLK_HEVCCNTL                                                        0x1800E9B8
#define  PREDBLK_HEVCCNTL_reg_addr                                               "0xB800E9B8"
#define  PREDBLK_HEVCCNTL_reg                                                    0xB800E9B8
#define  PREDBLK_HEVCCNTL_inst_addr                                              "0x0068"
#define  PREDBLK_HEVCCNTL_inst_adr                                               "0x006E"
#define  PREDBLK_HEVCCNTL_inst                                                   0x006E
#define  set_PREDBLK_HEVCCNTL_reg(data)                                          (*((volatile unsigned int*)PREDBLK_HEVCCNTL_reg)=data)
#define  get_PREDBLK_HEVCCNTL_reg                                                (*((volatile unsigned int*)PREDBLK_HEVCCNTL_reg))
#define  PREDBLK_HEVCCNTL_TenBit_shift                                           (31)
#define  PREDBLK_HEVCCNTL_VP9_enable_shift                                       (4)
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable_shift                                (3)
#define  PREDBLK_HEVCCNTL_itblk_dump_enable_shift                                (2)
#define  PREDBLK_HEVCCNTL_Itblk_dt_shift                                         (1)
#define  PREDBLK_HEVCCNTL_HEVC_Enable_shift                                      (0)
#define  PREDBLK_HEVCCNTL_TenBit_mask                                            (0x80000000)
#define  PREDBLK_HEVCCNTL_VP9_enable_mask                                        (0x00000010)
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable_mask                                 (0x00000008)
#define  PREDBLK_HEVCCNTL_itblk_dump_enable_mask                                 (0x00000004)
#define  PREDBLK_HEVCCNTL_Itblk_dt_mask                                          (0x00000002)
#define  PREDBLK_HEVCCNTL_HEVC_Enable_mask                                       (0x00000001)
#define  PREDBLK_HEVCCNTL_TenBit(data)                                           (0x80000000&((data)<<31))
#define  PREDBLK_HEVCCNTL_VP9_enable(data)                                       (0x00000010&((data)<<4))
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable(data)                                (0x00000008&((data)<<3))
#define  PREDBLK_HEVCCNTL_itblk_dump_enable(data)                                (0x00000004&((data)<<2))
#define  PREDBLK_HEVCCNTL_Itblk_dt(data)                                         (0x00000002&((data)<<1))
#define  PREDBLK_HEVCCNTL_HEVC_Enable(data)                                      (0x00000001&(data))
#define  PREDBLK_HEVCCNTL_get_TenBit(data)                                       ((0x80000000&(data))>>31)
#define  PREDBLK_HEVCCNTL_get_VP9_enable(data)                                   ((0x00000010&(data))>>4)
#define  PREDBLK_HEVCCNTL_get_mvbuf_dump_enable(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_HEVCCNTL_get_itblk_dump_enable(data)                            ((0x00000004&(data))>>2)
#define  PREDBLK_HEVCCNTL_get_Itblk_dt(data)                                     ((0x00000002&(data))>>1)
#define  PREDBLK_HEVCCNTL_get_HEVC_Enable(data)                                  (0x00000001&(data))
#define  PREDBLK_HEVCCNTL_TenBit_src(data)                                       ((0x80000000&(data))>>31)
#define  PREDBLK_HEVCCNTL_VP9_enable_src(data)                                   ((0x00000010&(data))>>4)
#define  PREDBLK_HEVCCNTL_mvbuf_dump_enable_src(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_HEVCCNTL_itblk_dump_enable_src(data)                            ((0x00000004&(data))>>2)
#define  PREDBLK_HEVCCNTL_Itblk_dt_src(data)                                     ((0x00000002&(data))>>1)
#define  PREDBLK_HEVCCNTL_HEVC_Enable_src(data)                                  (0x00000001&(data))

#define  PREDBLK_HVRMEMCTL                                                       0x1800E9BC
#define  PREDBLK_HVRMEMCTL_reg_addr                                              "0xB800E9BC"
#define  PREDBLK_HVRMEMCTL_reg                                                   0xB800E9BC
#define  PREDBLK_HVRMEMCTL_inst_addr                                             "0x0069"
#define  PREDBLK_HVRMEMCTL_inst_adr                                              "0x006F"
#define  PREDBLK_HVRMEMCTL_inst                                                  0x006F
#define  set_PREDBLK_HVRMEMCTL_reg(data)                                         (*((volatile unsigned int*)PREDBLK_HVRMEMCTL_reg)=data)
#define  get_PREDBLK_HVRMEMCTL_reg                                               (*((volatile unsigned int*)PREDBLK_HVRMEMCTL_reg))
#define  PREDBLK_HVRMEMCTL_addr_shift                                            (0)
#define  PREDBLK_HVRMEMCTL_addr_mask                                             (0xFFFFFFFF)
#define  PREDBLK_HVRMEMCTL_addr(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_HVRMEMCTL_get_addr(data)                                        (0xFFFFFFFF&(data))
#define  PREDBLK_HVRMEMCTL_addr_src(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_HEVC_DEBUG_CTRL                                                 0x1800E9AC
#define  PREDBLK_HEVC_DEBUG_CTRL_reg_addr                                        "0xB800E9AC"
#define  PREDBLK_HEVC_DEBUG_CTRL_reg                                             0xB800E9AC
#define  PREDBLK_HEVC_DEBUG_CTRL_inst_addr                                       "0x006A"
#define  PREDBLK_HEVC_DEBUG_CTRL_inst_adr                                        "0x006B"
#define  PREDBLK_HEVC_DEBUG_CTRL_inst                                            0x006B
#define  set_PREDBLK_HEVC_DEBUG_CTRL_reg(data)                                   (*((volatile unsigned int*)PREDBLK_HEVC_DEBUG_CTRL_reg)=data)
#define  get_PREDBLK_HEVC_DEBUG_CTRL_reg                                         (*((volatile unsigned int*)PREDBLK_HEVC_DEBUG_CTRL_reg))
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_count_shift                                (4)
#define  PREDBLK_HEVC_DEBUG_CTRL_Pred_op_go_shift                                (3)
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_dump_go_shift                              (2)
#define  PREDBLK_HEVC_DEBUG_CTRL_Ldumem_go_shift                                 (1)
#define  PREDBLK_HEVC_DEBUG_CTRL_Stumem_go_shift                                 (0)
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_count_mask                                 (0x000003F0)
#define  PREDBLK_HEVC_DEBUG_CTRL_Pred_op_go_mask                                 (0x00000008)
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_dump_go_mask                               (0x00000004)
#define  PREDBLK_HEVC_DEBUG_CTRL_Ldumem_go_mask                                  (0x00000002)
#define  PREDBLK_HEVC_DEBUG_CTRL_Stumem_go_mask                                  (0x00000001)
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_count(data)                                (0x000003F0&((data)<<4))
#define  PREDBLK_HEVC_DEBUG_CTRL_Pred_op_go(data)                                (0x00000008&((data)<<3))
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_dump_go(data)                              (0x00000004&((data)<<2))
#define  PREDBLK_HEVC_DEBUG_CTRL_Ldumem_go(data)                                 (0x00000002&((data)<<1))
#define  PREDBLK_HEVC_DEBUG_CTRL_Stumem_go(data)                                 (0x00000001&(data))
#define  PREDBLK_HEVC_DEBUG_CTRL_get_Rmem_count(data)                            ((0x000003F0&(data))>>4)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_Pred_op_go(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_Rmem_dump_go(data)                          ((0x00000004&(data))>>2)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_Ldumem_go(data)                             ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_DEBUG_CTRL_get_Stumem_go(data)                             (0x00000001&(data))
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_count_src(data)                            ((0x000003F0&(data))>>4)
#define  PREDBLK_HEVC_DEBUG_CTRL_Pred_op_go_src(data)                            ((0x00000008&(data))>>3)
#define  PREDBLK_HEVC_DEBUG_CTRL_Rmem_dump_go_src(data)                          ((0x00000004&(data))>>2)
#define  PREDBLK_HEVC_DEBUG_CTRL_Ldumem_go_src(data)                             ((0x00000002&(data))>>1)
#define  PREDBLK_HEVC_DEBUG_CTRL_Stumem_go_src(data)                             (0x00000001&(data))

#define  PREDBLK_LDUMEMCTL                                                       0x1800E9C0
#define  PREDBLK_LDUMEMCTL_reg_addr                                              "0xB800E9C0"
#define  PREDBLK_LDUMEMCTL_reg                                                   0xB800E9C0
#define  PREDBLK_LDUMEMCTL_inst_addr                                             "0x006B"
#define  PREDBLK_LDUMEMCTL_inst_adr                                              "0x0070"
#define  PREDBLK_LDUMEMCTL_inst                                                  0x0070
#define  set_PREDBLK_LDUMEMCTL_reg(data)                                         (*((volatile unsigned int*)PREDBLK_LDUMEMCTL_reg)=data)
#define  get_PREDBLK_LDUMEMCTL_reg                                               (*((volatile unsigned int*)PREDBLK_LDUMEMCTL_reg))
#define  PREDBLK_LDUMEMCTL_addr_shift                                            (0)
#define  PREDBLK_LDUMEMCTL_addr_mask                                             (0xFFFFFFFF)
#define  PREDBLK_LDUMEMCTL_addr(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_LDUMEMCTL_get_addr(data)                                        (0xFFFFFFFF&(data))
#define  PREDBLK_LDUMEMCTL_addr_src(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_STUMEMCTL                                                       0x1800E9C4
#define  PREDBLK_STUMEMCTL_reg_addr                                              "0xB800E9C4"
#define  PREDBLK_STUMEMCTL_reg                                                   0xB800E9C4
#define  PREDBLK_STUMEMCTL_inst_addr                                             "0x006C"
#define  PREDBLK_STUMEMCTL_inst_adr                                              "0x0071"
#define  PREDBLK_STUMEMCTL_inst                                                  0x0071
#define  set_PREDBLK_STUMEMCTL_reg(data)                                         (*((volatile unsigned int*)PREDBLK_STUMEMCTL_reg)=data)
#define  get_PREDBLK_STUMEMCTL_reg                                               (*((volatile unsigned int*)PREDBLK_STUMEMCTL_reg))
#define  PREDBLK_STUMEMCTL_addr_shift                                            (0)
#define  PREDBLK_STUMEMCTL_addr_mask                                             (0xFFFFFFFF)
#define  PREDBLK_STUMEMCTL_addr(data)                                            (0xFFFFFFFF&(data))
#define  PREDBLK_STUMEMCTL_get_addr(data)                                        (0xFFFFFFFF&(data))
#define  PREDBLK_STUMEMCTL_addr_src(data)                                        (0xFFFFFFFF&(data))

#define  PREDBLK_DBG_TUBUF                                                       0x1800E9C8
#define  PREDBLK_DBG_TUBUF_reg_addr                                              "0xB800E9C8"
#define  PREDBLK_DBG_TUBUF_reg                                                   0xB800E9C8
#define  PREDBLK_DBG_TUBUF_inst_addr                                             "0x006D"
#define  PREDBLK_DBG_TUBUF_inst_adr                                              "0x0072"
#define  PREDBLK_DBG_TUBUF_inst                                                  0x0072
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
#define  PREDBLK_DBG_TUBUF_tu_dbg_en_src(data)                                   ((0x40000000&(data))>>30)
#define  PREDBLK_DBG_TUBUF_rden_src(data)                                        ((0x20000000&(data))>>29)
#define  PREDBLK_DBG_TUBUF_wren_src(data)                                        ((0x10000000&(data))>>28)
#define  PREDBLK_DBG_TUBUF_addr_src(data)                                        ((0x0FC00000&(data))>>22)
#define  PREDBLK_DBG_TUBUF_data_src(data)                                        (0x003FFFFF&(data))

#define  PREDBLK_PTR_TUBUF                                                       0x1800E9CC
#define  PREDBLK_PTR_TUBUF_reg_addr                                              "0xB800E9CC"
#define  PREDBLK_PTR_TUBUF_reg                                                   0xB800E9CC
#define  PREDBLK_PTR_TUBUF_inst_addr                                             "0x006E"
#define  PREDBLK_PTR_TUBUF_inst_adr                                              "0x0073"
#define  PREDBLK_PTR_TUBUF_inst                                                  0x0073
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
#define  PREDBLK_PTR_TUBUF_itc_src(data)                                         ((0xFF000000&(data))>>24)
#define  PREDBLK_PTR_TUBUF_tuc_src(data)                                         ((0x00FF0000&(data))>>16)
#define  PREDBLK_PTR_TUBUF_puc_src(data)                                         ((0x0000FF00&(data))>>8)
#define  PREDBLK_PTR_TUBUF_com_src(data)                                         (0x000000FF&(data))

#define  PREDBLK_DUMP_ADDR_0                                                     0x1800E9D0
#define  PREDBLK_DUMP_ADDR_0_reg_addr                                            "0xB800E9D0"
#define  PREDBLK_DUMP_ADDR_0_reg                                                 0xB800E9D0
#define  PREDBLK_DUMP_ADDR_0_inst_addr                                           "0x006F"
#define  PREDBLK_DUMP_ADDR_0_inst_adr                                            "0x0074"
#define  PREDBLK_DUMP_ADDR_0_inst                                                0x0074
#define  set_PREDBLK_DUMP_ADDR_0_reg(data)                                       (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_0_reg)=data)
#define  get_PREDBLK_DUMP_ADDR_0_reg                                             (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_0_reg))
#define  PREDBLK_DUMP_ADDR_val_shift                                             (2)
#define  PREDBLK_DUMP_ADDR_val_mask                                              (0x7FFFFFFC)
#define  PREDBLK_DUMP_ADDR_val(data)                                             (0x7FFFFFFC&((data)<<2))
#define  PREDBLK_DUMP_ADDR_get_val(data)                                         ((0x7FFFFFFC&(data))>>2)
#define  PREDBLK_DUMP_ADDR_val_src(data)                                         ((0x7FFFFFFC&(data))>>2)

#define  PREDBLK_DUMP_ADDR_1                                                     0x1800E9D4
#define  PREDBLK_DUMP_ADDR_1_reg_addr                                            "0xB800E9D4"
#define  PREDBLK_DUMP_ADDR_1_reg                                                 0xB800E9D4
#define  PREDBLK_DUMP_ADDR_1_inst_addr                                           "0x0070"
#define  PREDBLK_DUMP_ADDR_1_inst_adr                                            "0x0075"
#define  PREDBLK_DUMP_ADDR_1_inst                                                0x0075
#define  set_PREDBLK_DUMP_ADDR_1_reg(data)                                       (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_1_reg)=data)
#define  get_PREDBLK_DUMP_ADDR_1_reg                                             (*((volatile unsigned int*)PREDBLK_DUMP_ADDR_1_reg))

#define  PREDBLK_HEVC_FRAME                                                      0x1800E9D8
#define  PREDBLK_HEVC_FRAME_reg_addr                                             "0xB800E9D8"
#define  PREDBLK_HEVC_FRAME_reg                                                  0xB800E9D8
#define  PREDBLK_HEVC_FRAME_inst_addr                                            "0x0071"
#define  PREDBLK_HEVC_FRAME_inst_adr                                             "0x0076"
#define  PREDBLK_HEVC_FRAME_inst                                                 0x0076
#define  set_PREDBLK_HEVC_FRAME_reg(data)                                        (*((volatile unsigned int*)PREDBLK_HEVC_FRAME_reg)=data)
#define  get_PREDBLK_HEVC_FRAME_reg                                              (*((volatile unsigned int*)PREDBLK_HEVC_FRAME_reg))
#define  PREDBLK_HEVC_FRAME_Count_shift                                          (0)
#define  PREDBLK_HEVC_FRAME_Count_mask                                           (0x0FFFFFFF)
#define  PREDBLK_HEVC_FRAME_Count(data)                                          (0x0FFFFFFF&(data))
#define  PREDBLK_HEVC_FRAME_get_Count(data)                                      (0x0FFFFFFF&(data))
#define  PREDBLK_HEVC_FRAME_Count_src(data)                                      (0x0FFFFFFF&(data))

#define  PREDBLK_HEVC_CTB                                                        0x1800E9DC
#define  PREDBLK_HEVC_CTB_reg_addr                                               "0xB800E9DC"
#define  PREDBLK_HEVC_CTB_reg                                                    0xB800E9DC
#define  PREDBLK_HEVC_CTB_inst_addr                                              "0x0072"
#define  PREDBLK_HEVC_CTB_inst_adr                                               "0x0077"
#define  PREDBLK_HEVC_CTB_inst                                                   0x0077
#define  set_PREDBLK_HEVC_CTB_reg(data)                                          (*((volatile unsigned int*)PREDBLK_HEVC_CTB_reg)=data)
#define  get_PREDBLK_HEVC_CTB_reg                                                (*((volatile unsigned int*)PREDBLK_HEVC_CTB_reg))
#define  PREDBLK_HEVC_CTB_count_shift                                            (0)
#define  PREDBLK_HEVC_CTB_count_mask                                             (0x0003FFFF)
#define  PREDBLK_HEVC_CTB_count(data)                                            (0x0003FFFF&(data))
#define  PREDBLK_HEVC_CTB_get_count(data)                                        (0x0003FFFF&(data))
#define  PREDBLK_HEVC_CTB_count_src(data)                                        (0x0003FFFF&(data))

#define  PREDBLK_DBUS4                                                           0x1800E9E0
#define  PREDBLK_DBUS4_reg_addr                                                  "0xB800E9E0"
#define  PREDBLK_DBUS4_reg                                                       0xB800E9E0
#define  PREDBLK_DBUS4_inst_addr                                                 "0x0073"
#define  PREDBLK_DBUS4_inst_adr                                                  "0x0078"
#define  PREDBLK_DBUS4_inst                                                      0x0078
#define  set_PREDBLK_DBUS4_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS4_reg)=data)
#define  get_PREDBLK_DBUS4_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS4_reg))
#define  PREDBLK_DBUS4_tbd_shift                                                 (18)
#define  PREDBLK_DBUS4_CTBX_shift                                                (9)
#define  PREDBLK_DBUS4_CTBY_shift                                                (0)
#define  PREDBLK_DBUS4_tbd_mask                                                  (0xFFFC0000)
#define  PREDBLK_DBUS4_CTBX_mask                                                 (0x0003FE00)
#define  PREDBLK_DBUS4_CTBY_mask                                                 (0x000001FF)
#define  PREDBLK_DBUS4_tbd(data)                                                 (0xFFFC0000&((data)<<18))
#define  PREDBLK_DBUS4_CTBX(data)                                                (0x0003FE00&((data)<<9))
#define  PREDBLK_DBUS4_CTBY(data)                                                (0x000001FF&(data))
#define  PREDBLK_DBUS4_get_tbd(data)                                             ((0xFFFC0000&(data))>>18)
#define  PREDBLK_DBUS4_get_CTBX(data)                                            ((0x0003FE00&(data))>>9)
#define  PREDBLK_DBUS4_get_CTBY(data)                                            (0x000001FF&(data))
#define  PREDBLK_DBUS4_tbd_src(data)                                             ((0xFFFC0000&(data))>>18)
#define  PREDBLK_DBUS4_CTBX_src(data)                                            ((0x0003FE00&(data))>>9)
#define  PREDBLK_DBUS4_CTBY_src(data)                                            (0x000001FF&(data))

#define  PREDBLK_DBUS5                                                           0x1800E9E4
#define  PREDBLK_DBUS5_reg_addr                                                  "0xB800E9E4"
#define  PREDBLK_DBUS5_reg                                                       0xB800E9E4
#define  PREDBLK_DBUS5_inst_addr                                                 "0x0074"
#define  PREDBLK_DBUS5_inst_adr                                                  "0x0079"
#define  PREDBLK_DBUS5_inst                                                      0x0079
#define  set_PREDBLK_DBUS5_reg(data)                                             (*((volatile unsigned int*)PREDBLK_DBUS5_reg)=data)
#define  get_PREDBLK_DBUS5_reg                                                   (*((volatile unsigned int*)PREDBLK_DBUS5_reg))
#define  PREDBLK_DBUS5_tbd_shift                                                 (0)
#define  PREDBLK_DBUS5_tbd_mask                                                  (0xFFFFFFFF)
#define  PREDBLK_DBUS5_tbd(data)                                                 (0xFFFFFFFF&(data))
#define  PREDBLK_DBUS5_get_tbd(data)                                             (0xFFFFFFFF&(data))
#define  PREDBLK_DBUS5_tbd_src(data)                                             (0xFFFFFFFF&(data))

#define  PREDBLK_RMPTR0                                                          0x1800E9E8
#define  PREDBLK_RMPTR0_reg_addr                                                 "0xB800E9E8"
#define  PREDBLK_RMPTR0_reg                                                      0xB800E9E8
#define  PREDBLK_RMPTR0_inst_addr                                                "0x0075"
#define  PREDBLK_RMPTR0_inst_adr                                                 "0x007A"
#define  PREDBLK_RMPTR0_inst                                                     0x007A
#define  set_PREDBLK_RMPTR0_reg(data)                                            (*((volatile unsigned int*)PREDBLK_RMPTR0_reg)=data)
#define  get_PREDBLK_RMPTR0_reg                                                  (*((volatile unsigned int*)PREDBLK_RMPTR0_reg))
#define  PREDBLK_RMPTR0_Large_enough_shift                                       (29)
#define  PREDBLK_RMPTR0_require_shift                                            (22)
#define  PREDBLK_RMPTR0_wrptr_shift                                              (11)
#define  PREDBLK_RMPTR0_rdptr_shift                                              (0)
#define  PREDBLK_RMPTR0_Large_enough_mask                                        (0x20000000)
#define  PREDBLK_RMPTR0_require_mask                                             (0x1FC00000)
#define  PREDBLK_RMPTR0_wrptr_mask                                               (0x003FF800)
#define  PREDBLK_RMPTR0_rdptr_mask                                               (0x000007FF)
#define  PREDBLK_RMPTR0_Large_enough(data)                                       (0x20000000&((data)<<29))
#define  PREDBLK_RMPTR0_require(data)                                            (0x1FC00000&((data)<<22))
#define  PREDBLK_RMPTR0_wrptr(data)                                              (0x003FF800&((data)<<11))
#define  PREDBLK_RMPTR0_rdptr(data)                                              (0x000007FF&(data))
#define  PREDBLK_RMPTR0_get_Large_enough(data)                                   ((0x20000000&(data))>>29)
#define  PREDBLK_RMPTR0_get_require(data)                                        ((0x1FC00000&(data))>>22)
#define  PREDBLK_RMPTR0_get_wrptr(data)                                          ((0x003FF800&(data))>>11)
#define  PREDBLK_RMPTR0_get_rdptr(data)                                          (0x000007FF&(data))
#define  PREDBLK_RMPTR0_Large_enough_src(data)                                   ((0x20000000&(data))>>29)
#define  PREDBLK_RMPTR0_require_src(data)                                        ((0x1FC00000&(data))>>22)
#define  PREDBLK_RMPTR0_wrptr_src(data)                                          ((0x003FF800&(data))>>11)
#define  PREDBLK_RMPTR0_rdptr_src(data)                                          (0x000007FF&(data))

#define  PREDBLK_RMPTR1                                                          0x1800E9EC
#define  PREDBLK_RMPTR1_reg_addr                                                 "0xB800E9EC"
#define  PREDBLK_RMPTR1_reg                                                      0xB800E9EC
#define  PREDBLK_RMPTR1_inst_addr                                                "0x0076"
#define  PREDBLK_RMPTR1_inst_adr                                                 "0x007B"
#define  PREDBLK_RMPTR1_inst                                                     0x007B
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
#define  PREDBLK_RMPTR1_msb_src(data)                                            ((0x00003800&(data))>>11)
#define  PREDBLK_RMPTR1_rdptr_src(data)                                          (0x000007FF&(data))

#define  PREDBLK_HEVCSB                                                          0x1800E9F8
#define  PREDBLK_HEVCSB_reg_addr                                                 "0xB800E9F8"
#define  PREDBLK_HEVCSB_reg                                                      0xB800E9F8
#define  PREDBLK_HEVCSB_inst_addr                                                "0x0077"
#define  PREDBLK_HEVCSB_inst_adr                                                 "0x007E"
#define  PREDBLK_HEVCSB_inst                                                     0x007E
#define  set_PREDBLK_HEVCSB_reg(data)                                            (*((volatile unsigned int*)PREDBLK_HEVCSB_reg)=data)
#define  get_PREDBLK_HEVCSB_reg                                                  (*((volatile unsigned int*)PREDBLK_HEVCSB_reg))
#define  PREDBLK_HEVCSB_startaddr_shift                                          (0)
#define  PREDBLK_HEVCSB_startaddr_mask                                           (0x0000007F)
#define  PREDBLK_HEVCSB_startaddr(data)                                          (0x0000007F&(data))
#define  PREDBLK_HEVCSB_get_startaddr(data)                                      (0x0000007F&(data))
#define  PREDBLK_HEVCSB_startaddr_src(data)                                      (0x0000007F&(data))

#ifdef _PREDBLK_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PREDBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  Nhmem_Flush:1;
        RBus_UInt32  RMEM_Rst:1;
        RBus_UInt32  Deblk_xsfer_mode:1;
        RBus_UInt32  Debug_mode:1;
        RBus_UInt32  fmo:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  Softrst_disable:1;
        RBus_UInt32  New_slice_row:1;
        RBus_UInt32  New_slice_mb_x:9;
        RBus_UInt32  Sw_neighbor_enable:1;
        RBus_UInt32  MbAddrA_available:1;
        RBus_UInt32  MbAddrB_available:1;
        RBus_UInt32  MbAddrC_available:1;
        RBus_UInt32  MbAddrD_available:1;
    };
}PREDBLK_NEIGHBOR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  ic_mix_fcm_enable:1;
        RBus_UInt32  CONDOVER:2;
        RBus_UInt32  Rnd_ctrl_ovt:1;
        RBus_UInt32  RND:1;
        RBus_UInt32  INTCOMP:1;
        RBus_UInt32  LUMSCALE0:6;
        RBus_UInt32  LUMSHIFT0:6;
    };
}PREDBLK_VC1INTC1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ic_pass0_of_fwd:4;
        RBus_UInt32  Ic_pass1_of_fwd:4;
        RBus_UInt32  Ic_pass0_sf_fwd:4;
        RBus_UInt32  Ic_pass1_sf_fwd:4;
        RBus_UInt32  Ic_pass0_of_bwd:4;
        RBus_UInt32  Ic_pass1_of_bwd:4;
        RBus_UInt32  Ic_pass0_sf_bwd:4;
        RBus_UInt32  Ic_pass1_sf_bwd:4;
    };
}PREDBLK_VC1INTC2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  LUMSCALE1:6;
        RBus_UInt32  LUMSHIFT1:6;
        RBus_UInt32  LUMSCALE2:6;
        RBus_UInt32  LUMSHIFT2:6;
    };
}PREDBLK_VC1INTC3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  LUMSCALE3:6;
        RBus_UInt32  LUMSHIFT3:6;
        RBus_UInt32  LUMSCALE4:6;
        RBus_UInt32  LUMSHIFT4:6;
    };
}PREDBLK_VC1INTC4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}PREDBLK_NBINTRA0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}PREDBLK_NBINTRA1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}PREDBLK_NBINTRACH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Field_overflag_flag:32;
    };
}PREDBLK_NBFIELDOV_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  Intra0:1;
        RBus_UInt32  Intra1:1;
        RBus_UInt32  IntraChroma:1;
        RBus_UInt32  IntraField:1;
    };
}PREDBLK_NBEXTRA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  WTBL_StartA:10;
    };
}PREDBLK_WTBLSA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wt_flag:32;
    };
}PREDBLK_WTFLAG_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Wdone_enable:1;
        RBus_UInt32  Mem_eng_busy:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  seq_line_addr:29;
    };
}PREDBLK_SDMAADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  Value:28;
    };
}PREDBLK_INTR_THRESH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  Reach_Thresh:1;
        RBus_UInt32  Count:28;
    };
}PREDBLK_BUSY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  BaseA0:7;
        RBus_UInt32  res2:6;
        RBus_UInt32  BaseA1:7;
        RBus_UInt32  res3:3;
    };
}PREDBLK_BASEA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  OffsetA:7;
        RBus_UInt32  res2:3;
    };
}PREDBLK_OFFSETA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  StartA:7;
    };
}PREDBLK_DEBPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  Rounding_Control:1;
        RBus_UInt32  Quarter_Sample:1;
    };
}PREDBLK_MPEGCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Valid:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  Base_addr:26;
        RBus_UInt32  res2:3;
    };
}PREDBLK_RMEMDDR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MBCnt_threshold:32;
    };
}PREDBLK_RMEMDDR2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Valid:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  Start_Addr:7;
        RBus_UInt32  End_Addr:7;
    };
}PREDBLK_RMEMCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  URatio:15;
    };
}PREDBLK_URATIO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  GenPulse:1;
        RBus_UInt32  PicCount:14;
        RBus_UInt32  MbAddrX:9;
        RBus_UInt32  MbAddrY:8;
    };
}PREDBLK_DBUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DbgCtrl:32;
    };
}PREDBLK_DBUS2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DbgCtrl3:29;
        RBus_UInt32  DbgCtrl:3;
    };
}PREDBLK_DBUS3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  SDMAWR1MSB:1;
        RBus_UInt32  SDMA2MSB:3;
        RBus_UInt32  RMEM2MSB:3;
    };
}PREDBLK_DMAMSB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  BaseAddr:12;
    };
}PREDBLK_DMEMADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  Count:28;
    };
}PREDBLK_DMEMOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_enable:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  Pmem_idle:1;
    };
}PREDBLK_SLICE_RESTART_RBUS;

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
}PREDBLK_SLICE_DBG0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ddr_rng_rdptr:10;
        RBus_UInt32  ddr_rng_wrptr:10;
        RBus_UInt32  ddr_rng_size:10;
    };
}PREDBLK_SLICE_DBG1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  On:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  Bank0:4;
        RBus_UInt32  Bank1:4;
        RBus_UInt32  Bank2:4;
        RBus_UInt32  Bank3:4;
    };
}PREDBLK_CONFLICT_RBUS;

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
}PREDBLK_ENCUMEM_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  um_dbg_en:1;
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  Bank5_Owner:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  Bank4_Owner:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  Bank3_Owner:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  Bank2_Owner:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  Bank1_Owner:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  Bank0_Owner:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  itblk_bank:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Pred_bank:4;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Umem_init:1;
    };
}PREDBLK_HEVC_UMEM_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  Bank9_Owner:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  Bank8_Owner:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Bank7_Owner:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Bank6_Owner:1;
    };
}PREDBLK_HEVC_UMEM_CTRL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Enable:1;
        RBus_UInt32  seq_line_addr:31;
    };
}PREDBLK_SDMAWRADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  Reset:1;
        RBus_UInt32  Start:1;
    };
}PREDBLK_DECCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  TenBit:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  VP9_enable:1;
        RBus_UInt32  mvbuf_dump_enable:1;
        RBus_UInt32  itblk_dump_enable:1;
        RBus_UInt32  Itblk_dt:1;
        RBus_UInt32  HEVC_Enable:1;
    };
}PREDBLK_HEVCCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}PREDBLK_HVRMEMCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  Rmem_count:6;
        RBus_UInt32  Pred_op_go:1;
        RBus_UInt32  Rmem_dump_go:1;
        RBus_UInt32  Ldumem_go:1;
        RBus_UInt32  Stumem_go:1;
    };
}PREDBLK_HEVC_DEBUG_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}PREDBLK_LDUMEMCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}PREDBLK_STUMEMCTL_RBUS;

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
}PREDBLK_DBG_TUBUF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  itc:8;
        RBus_UInt32  tuc:8;
        RBus_UInt32  puc:8;
        RBus_UInt32  com:8;
    };
}PREDBLK_PTR_TUBUF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  val:29;
        RBus_UInt32  res2:2;
    };
}PREDBLK_DUMP_ADDR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  Count:28;
    };
}PREDBLK_HEVC_FRAME_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  count:18;
    };
}PREDBLK_HEVC_CTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbd:14;
        RBus_UInt32  CTBX:9;
        RBus_UInt32  CTBY:9;
    };
}PREDBLK_DBUS4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbd:32;
    };
}PREDBLK_DBUS5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  Large_enough:1;
        RBus_UInt32  require:7;
        RBus_UInt32  wrptr:11;
        RBus_UInt32  rdptr:11;
    };
}PREDBLK_RMPTR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  msb:3;
        RBus_UInt32  rdptr:11;
    };
}PREDBLK_RMPTR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  startaddr:7;
    };
}PREDBLK_HEVCSB_RBUS;

#else //apply LITTLE_ENDIAN

//======PREDBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MbAddrD_available:1;
        RBus_UInt32  MbAddrC_available:1;
        RBus_UInt32  MbAddrB_available:1;
        RBus_UInt32  MbAddrA_available:1;
        RBus_UInt32  Sw_neighbor_enable:1;
        RBus_UInt32  New_slice_mb_x:9;
        RBus_UInt32  New_slice_row:1;
        RBus_UInt32  Softrst_disable:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  fmo:1;
        RBus_UInt32  Debug_mode:1;
        RBus_UInt32  Deblk_xsfer_mode:1;
        RBus_UInt32  RMEM_Rst:1;
        RBus_UInt32  Nhmem_Flush:1;
        RBus_UInt32  res2:7;
    };
}PREDBLK_NEIGHBOR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LUMSHIFT0:6;
        RBus_UInt32  LUMSCALE0:6;
        RBus_UInt32  INTCOMP:1;
        RBus_UInt32  RND:1;
        RBus_UInt32  Rnd_ctrl_ovt:1;
        RBus_UInt32  CONDOVER:2;
        RBus_UInt32  ic_mix_fcm_enable:1;
        RBus_UInt32  res1:14;
    };
}PREDBLK_VC1INTC1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Ic_pass1_sf_bwd:4;
        RBus_UInt32  Ic_pass0_sf_bwd:4;
        RBus_UInt32  Ic_pass1_of_bwd:4;
        RBus_UInt32  Ic_pass0_of_bwd:4;
        RBus_UInt32  Ic_pass1_sf_fwd:4;
        RBus_UInt32  Ic_pass0_sf_fwd:4;
        RBus_UInt32  Ic_pass1_of_fwd:4;
        RBus_UInt32  Ic_pass0_of_fwd:4;
    };
}PREDBLK_VC1INTC2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LUMSHIFT2:6;
        RBus_UInt32  LUMSCALE2:6;
        RBus_UInt32  LUMSHIFT1:6;
        RBus_UInt32  LUMSCALE1:6;
        RBus_UInt32  res1:8;
    };
}PREDBLK_VC1INTC3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  LUMSHIFT4:6;
        RBus_UInt32  LUMSCALE4:6;
        RBus_UInt32  LUMSHIFT3:6;
        RBus_UInt32  LUMSCALE3:6;
        RBus_UInt32  res1:8;
    };
}PREDBLK_VC1INTC4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}PREDBLK_NBINTRA0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}PREDBLK_NBINTRA1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_flag:32;
    };
}PREDBLK_NBINTRACH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Field_overflag_flag:32;
    };
}PREDBLK_NBFIELDOV_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  IntraField:1;
        RBus_UInt32  IntraChroma:1;
        RBus_UInt32  Intra1:1;
        RBus_UInt32  Intra0:1;
        RBus_UInt32  res1:28;
    };
}PREDBLK_NBEXTRA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  WTBL_StartA:10;
        RBus_UInt32  res1:22;
    };
}PREDBLK_WTBLSA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wt_flag:32;
    };
}PREDBLK_WTFLAG_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:29;
        RBus_UInt32  res1:1;
        RBus_UInt32  Mem_eng_busy:1;
        RBus_UInt32  Wdone_enable:1;
    };
}PREDBLK_SDMAADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Value:28;
        RBus_UInt32  res1:4;
    };
}PREDBLK_INTR_THRESH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Count:28;
        RBus_UInt32  Reach_Thresh:1;
        RBus_UInt32  res1:3;
    };
}PREDBLK_BUSY_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  BaseA1:7;
        RBus_UInt32  res2:6;
        RBus_UInt32  BaseA0:7;
        RBus_UInt32  res3:9;
    };
}PREDBLK_BASEA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  OffsetA:7;
        RBus_UInt32  res2:22;
    };
}PREDBLK_OFFSETA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  StartA:7;
        RBus_UInt32  res1:25;
    };
}PREDBLK_DEBPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Quarter_Sample:1;
        RBus_UInt32  Rounding_Control:1;
        RBus_UInt32  res1:30;
    };
}PREDBLK_MPEGCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  Base_addr:26;
        RBus_UInt32  res2:2;
        RBus_UInt32  Valid:1;
    };
}PREDBLK_RMEMDDR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MBCnt_threshold:32;
    };
}PREDBLK_RMEMDDR2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  End_Addr:7;
        RBus_UInt32  Start_Addr:7;
        RBus_UInt32  res1:17;
        RBus_UInt32  Valid:1;
    };
}PREDBLK_RMEMCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  URatio:15;
        RBus_UInt32  res1:17;
    };
}PREDBLK_URATIO_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MbAddrY:8;
        RBus_UInt32  MbAddrX:9;
        RBus_UInt32  PicCount:14;
        RBus_UInt32  GenPulse:1;
    };
}PREDBLK_DBUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DbgCtrl:32;
    };
}PREDBLK_DBUS2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  DbgCtrl:3;
        RBus_UInt32  DbgCtrl3:29;
    };
}PREDBLK_DBUS3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  RMEM2MSB:3;
        RBus_UInt32  SDMA2MSB:3;
        RBus_UInt32  SDMAWR1MSB:1;
        RBus_UInt32  res1:25;
    };
}PREDBLK_DMAMSB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  BaseAddr:12;
        RBus_UInt32  res1:20;
    };
}PREDBLK_DMEMADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Count:28;
        RBus_UInt32  res1:4;
    };
}PREDBLK_DMEMOP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Pmem_idle:1;
        RBus_UInt32  res1:30;
        RBus_UInt32  hw_enable:1;
    };
}PREDBLK_SLICE_RESTART_RBUS;

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
}PREDBLK_SLICE_DBG0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddr_rng_size:10;
        RBus_UInt32  ddr_rng_wrptr:10;
        RBus_UInt32  ddr_rng_rdptr:10;
        RBus_UInt32  res1:2;
    };
}PREDBLK_SLICE_DBG1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Bank3:4;
        RBus_UInt32  Bank2:4;
        RBus_UInt32  Bank1:4;
        RBus_UInt32  Bank0:4;
        RBus_UInt32  res1:15;
        RBus_UInt32  On:1;
    };
}PREDBLK_CONFLICT_RBUS;

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
}PREDBLK_ENCUMEM_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Umem_init:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Pred_bank:4;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  itblk_bank:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  Bank0_Owner:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  Bank1_Owner:1;
        RBus_UInt32  write_enable5:1;
        RBus_UInt32  Bank2_Owner:1;
        RBus_UInt32  write_enable6:1;
        RBus_UInt32  Bank3_Owner:1;
        RBus_UInt32  write_enable7:1;
        RBus_UInt32  Bank4_Owner:1;
        RBus_UInt32  write_enable8:1;
        RBus_UInt32  Bank5_Owner:1;
        RBus_UInt32  write_enable9:1;
        RBus_UInt32  um_dbg_en:1;
        RBus_UInt32  write_enable10:1;
        RBus_UInt32  res1:6;
    };
}PREDBLK_HEVC_UMEM_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Bank6_Owner:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Bank7_Owner:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Bank8_Owner:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  Bank9_Owner:1;
        RBus_UInt32  write_enable4:1;
        RBus_UInt32  res1:24;
    };
}PREDBLK_HEVC_UMEM_CTRL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_line_addr:31;
        RBus_UInt32  Enable:1;
    };
}PREDBLK_SDMAWRADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Start:1;
        RBus_UInt32  Reset:1;
        RBus_UInt32  res1:30;
    };
}PREDBLK_DECCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  HEVC_Enable:1;
        RBus_UInt32  Itblk_dt:1;
        RBus_UInt32  itblk_dump_enable:1;
        RBus_UInt32  mvbuf_dump_enable:1;
        RBus_UInt32  VP9_enable:1;
        RBus_UInt32  res1:26;
        RBus_UInt32  TenBit:1;
    };
}PREDBLK_HEVCCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}PREDBLK_HVRMEMCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Stumem_go:1;
        RBus_UInt32  Ldumem_go:1;
        RBus_UInt32  Rmem_dump_go:1;
        RBus_UInt32  Pred_op_go:1;
        RBus_UInt32  Rmem_count:6;
        RBus_UInt32  res1:22;
    };
}PREDBLK_HEVC_DEBUG_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}PREDBLK_LDUMEMCTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}PREDBLK_STUMEMCTL_RBUS;

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
}PREDBLK_DBG_TUBUF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  com:8;
        RBus_UInt32  puc:8;
        RBus_UInt32  tuc:8;
        RBus_UInt32  itc:8;
    };
}PREDBLK_PTR_TUBUF_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  val:29;
        RBus_UInt32  res2:1;
    };
}PREDBLK_DUMP_ADDR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Count:28;
        RBus_UInt32  res1:4;
    };
}PREDBLK_HEVC_FRAME_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  count:18;
        RBus_UInt32  res1:14;
    };
}PREDBLK_HEVC_CTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  CTBY:9;
        RBus_UInt32  CTBX:9;
        RBus_UInt32  tbd:14;
    };
}PREDBLK_DBUS4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tbd:32;
    };
}PREDBLK_DBUS5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:11;
        RBus_UInt32  wrptr:11;
        RBus_UInt32  require:7;
        RBus_UInt32  Large_enough:1;
        RBus_UInt32  res1:2;
    };
}PREDBLK_RMPTR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdptr:11;
        RBus_UInt32  msb:3;
        RBus_UInt32  res1:18;
    };
}PREDBLK_RMPTR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startaddr:7;
        RBus_UInt32  res1:25;
    };
}PREDBLK_HEVCSB_RBUS;




#endif 


#endif 
#endif 
