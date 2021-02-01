/**
* @file rbusCRTReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-2-16
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_CRT_REG_H_
#define _RBUS_CRT_REG_H_

#include "rbusTypes.h"

//  CRT Register Address
#define  CRT_SYS_SRST0                                                           0x18000100
#define  CRT_SYS_SRST0_reg_addr                                                  "0xB8000100"
#define  CRT_SYS_SRST0_reg                                                       0xB8000100
#define  CRT_SYS_SRST0_inst_addr                                                 "0x0000"
#define  set_CRT_SYS_SRST0_reg(data)                                             (*((volatile unsigned int*)CRT_SYS_SRST0_reg)=data)
#define  get_CRT_SYS_SRST0_reg                                                   (*((volatile unsigned int*)CRT_SYS_SRST0_reg))
#define  CRT_SYS_SRST0_rstn_ib_sb1_shift                                         (31)
#define  CRT_SYS_SRST0_rstn_ib_sb2_shift                                         (30)
#define  CRT_SYS_SRST0_rstn_ib_sb3_shift                                         (29)
#define  CRT_SYS_SRST0_rstn_ib_ve_shift                                          (28)
#define  CRT_SYS_SRST0_rstn_ib_ve2_shift                                         (27)
#define  CRT_SYS_SRST0_rstn_ib_vp9_shift                                         (26)
#define  CRT_SYS_SRST0_rstn_ib_tvsb1_shift                                       (25)
#define  CRT_SYS_SRST0_rstn_nd_shift                                             (24)
#define  CRT_SYS_SRST0_rstn_akl_shift                                            (23)
#define  CRT_SYS_SRST0_rstn_dsc_shift                                            (22)
#define  CRT_SYS_SRST0_rstn_sce_shift                                            (21)
#define  CRT_SYS_SRST0_rstn_kt_shift                                             (20)
#define  CRT_SYS_SRST0_rstn_ib_gpu_shift                                         (19)
#define  CRT_SYS_SRST0_rstn_kcpu_shift                                           (18)
#define  CRT_SYS_SRST0_rstn_vde2_shift                                           (17)
#define  CRT_SYS_SRST0_rstn_ve2_p2_shift                                         (16)
#define  CRT_SYS_SRST0_rstn_ve2_shift                                            (15)
#define  CRT_SYS_SRST0_rstn_vcpu2_shift                                          (14)
#define  CRT_SYS_SRST0_rstn_vp9_shift                                            (13)
#define  CRT_SYS_SRST0_rstn_acpu_shift                                           (12)
#define  CRT_SYS_SRST0_rstn_ib_tvsb2_shift                                       (11)
#define  CRT_SYS_SRST0_rstn_ib_tvsb3_shift                                       (10)
#define  CRT_SYS_SRST0_rstn_ib_tvsb4_shift                                       (9)
#define  CRT_SYS_SRST0_rstn_ib_tvsb5_shift                                       (8)
#define  CRT_SYS_SRST0_rstn_scpu_wrap_shift                                      (7)
#define  CRT_SYS_SRST0_rstn_vde_shift                                            (6)
#define  CRT_SYS_SRST0_rstn_ve_p2_shift                                          (5)
#define  CRT_SYS_SRST0_rstn_ve_shift                                             (4)
#define  CRT_SYS_SRST0_rstn_vcpu_shift                                           (3)
#define  CRT_SYS_SRST0_rstn_ae_shift                                             (2)
#define  CRT_SYS_SRST0_rstn_scpu_shift                                           (1)
#define  CRT_SYS_SRST0_rstn_pllreg_shift                                         (0)
#define  CRT_SYS_SRST0_rstn_ib_sb1_mask                                          (0x80000000)
#define  CRT_SYS_SRST0_rstn_ib_sb2_mask                                          (0x40000000)
#define  CRT_SYS_SRST0_rstn_ib_sb3_mask                                          (0x20000000)
#define  CRT_SYS_SRST0_rstn_ib_ve_mask                                           (0x10000000)
#define  CRT_SYS_SRST0_rstn_ib_ve2_mask                                          (0x08000000)
#define  CRT_SYS_SRST0_rstn_ib_vp9_mask                                          (0x04000000)
#define  CRT_SYS_SRST0_rstn_ib_tvsb1_mask                                        (0x02000000)
#define  CRT_SYS_SRST0_rstn_nd_mask                                              (0x01000000)
#define  CRT_SYS_SRST0_rstn_akl_mask                                             (0x00800000)
#define  CRT_SYS_SRST0_rstn_dsc_mask                                             (0x00400000)
#define  CRT_SYS_SRST0_rstn_sce_mask                                             (0x00200000)
#define  CRT_SYS_SRST0_rstn_kt_mask                                              (0x00100000)
#define  CRT_SYS_SRST0_rstn_ib_gpu_mask                                          (0x00080000)
#define  CRT_SYS_SRST0_rstn_kcpu_mask                                            (0x00040000)
#define  CRT_SYS_SRST0_rstn_vde2_mask                                            (0x00020000)
#define  CRT_SYS_SRST0_rstn_ve2_p2_mask                                          (0x00010000)
#define  CRT_SYS_SRST0_rstn_ve2_mask                                             (0x00008000)
#define  CRT_SYS_SRST0_rstn_vcpu2_mask                                           (0x00004000)
#define  CRT_SYS_SRST0_rstn_vp9_mask                                             (0x00002000)
#define  CRT_SYS_SRST0_rstn_acpu_mask                                            (0x00001000)
#define  CRT_SYS_SRST0_rstn_ib_tvsb2_mask                                        (0x00000800)
#define  CRT_SYS_SRST0_rstn_ib_tvsb3_mask                                        (0x00000400)
#define  CRT_SYS_SRST0_rstn_ib_tvsb4_mask                                        (0x00000200)
#define  CRT_SYS_SRST0_rstn_ib_tvsb5_mask                                        (0x00000100)
#define  CRT_SYS_SRST0_rstn_scpu_wrap_mask                                       (0x00000080)
#define  CRT_SYS_SRST0_rstn_vde_mask                                             (0x00000040)
#define  CRT_SYS_SRST0_rstn_ve_p2_mask                                           (0x00000020)
#define  CRT_SYS_SRST0_rstn_ve_mask                                              (0x00000010)
#define  CRT_SYS_SRST0_rstn_vcpu_mask                                            (0x00000008)
#define  CRT_SYS_SRST0_rstn_ae_mask                                              (0x00000004)
#define  CRT_SYS_SRST0_rstn_scpu_mask                                            (0x00000002)
#define  CRT_SYS_SRST0_rstn_pllreg_mask                                          (0x00000001)
#define  CRT_SYS_SRST0_rstn_ib_sb1(data)                                         (0x80000000&((data)<<31))
#define  CRT_SYS_SRST0_rstn_ib_sb2(data)                                         (0x40000000&((data)<<30))
#define  CRT_SYS_SRST0_rstn_ib_sb3(data)                                         (0x20000000&((data)<<29))
#define  CRT_SYS_SRST0_rstn_ib_ve(data)                                          (0x10000000&((data)<<28))
#define  CRT_SYS_SRST0_rstn_ib_ve2(data)                                         (0x08000000&((data)<<27))
#define  CRT_SYS_SRST0_rstn_ib_vp9(data)                                         (0x04000000&((data)<<26))
#define  CRT_SYS_SRST0_rstn_ib_tvsb1(data)                                       (0x02000000&((data)<<25))
#define  CRT_SYS_SRST0_rstn_nd(data)                                             (0x01000000&((data)<<24))
#define  CRT_SYS_SRST0_rstn_akl(data)                                            (0x00800000&((data)<<23))
#define  CRT_SYS_SRST0_rstn_dsc(data)                                            (0x00400000&((data)<<22))
#define  CRT_SYS_SRST0_rstn_sce(data)                                            (0x00200000&((data)<<21))
#define  CRT_SYS_SRST0_rstn_kt(data)                                             (0x00100000&((data)<<20))
#define  CRT_SYS_SRST0_rstn_ib_gpu(data)                                         (0x00080000&((data)<<19))
#define  CRT_SYS_SRST0_rstn_kcpu(data)                                           (0x00040000&((data)<<18))
#define  CRT_SYS_SRST0_rstn_vde2(data)                                           (0x00020000&((data)<<17))
#define  CRT_SYS_SRST0_rstn_ve2_p2(data)                                         (0x00010000&((data)<<16))
#define  CRT_SYS_SRST0_rstn_ve2(data)                                            (0x00008000&((data)<<15))
#define  CRT_SYS_SRST0_rstn_vcpu2(data)                                          (0x00004000&((data)<<14))
#define  CRT_SYS_SRST0_rstn_vp9(data)                                            (0x00002000&((data)<<13))
#define  CRT_SYS_SRST0_rstn_acpu(data)                                           (0x00001000&((data)<<12))
#define  CRT_SYS_SRST0_rstn_ib_tvsb2(data)                                       (0x00000800&((data)<<11))
#define  CRT_SYS_SRST0_rstn_ib_tvsb3(data)                                       (0x00000400&((data)<<10))
#define  CRT_SYS_SRST0_rstn_ib_tvsb4(data)                                       (0x00000200&((data)<<9))
#define  CRT_SYS_SRST0_rstn_ib_tvsb5(data)                                       (0x00000100&((data)<<8))
#define  CRT_SYS_SRST0_rstn_scpu_wrap(data)                                      (0x00000080&((data)<<7))
#define  CRT_SYS_SRST0_rstn_vde(data)                                            (0x00000040&((data)<<6))
#define  CRT_SYS_SRST0_rstn_ve_p2(data)                                          (0x00000020&((data)<<5))
#define  CRT_SYS_SRST0_rstn_ve(data)                                             (0x00000010&((data)<<4))
#define  CRT_SYS_SRST0_rstn_vcpu(data)                                           (0x00000008&((data)<<3))
#define  CRT_SYS_SRST0_rstn_ae(data)                                             (0x00000004&((data)<<2))
#define  CRT_SYS_SRST0_rstn_scpu(data)                                           (0x00000002&((data)<<1))
#define  CRT_SYS_SRST0_rstn_pllreg(data)                                         (0x00000001&(data))
#define  CRT_SYS_SRST0_get_rstn_ib_sb1(data)                                     ((0x80000000&(data))>>31)
#define  CRT_SYS_SRST0_get_rstn_ib_sb2(data)                                     ((0x40000000&(data))>>30)
#define  CRT_SYS_SRST0_get_rstn_ib_sb3(data)                                     ((0x20000000&(data))>>29)
#define  CRT_SYS_SRST0_get_rstn_ib_ve(data)                                      ((0x10000000&(data))>>28)
#define  CRT_SYS_SRST0_get_rstn_ib_ve2(data)                                     ((0x08000000&(data))>>27)
#define  CRT_SYS_SRST0_get_rstn_ib_vp9(data)                                     ((0x04000000&(data))>>26)
#define  CRT_SYS_SRST0_get_rstn_ib_tvsb1(data)                                   ((0x02000000&(data))>>25)
#define  CRT_SYS_SRST0_get_rstn_nd(data)                                         ((0x01000000&(data))>>24)
#define  CRT_SYS_SRST0_get_rstn_akl(data)                                        ((0x00800000&(data))>>23)
#define  CRT_SYS_SRST0_get_rstn_dsc(data)                                        ((0x00400000&(data))>>22)
#define  CRT_SYS_SRST0_get_rstn_sce(data)                                        ((0x00200000&(data))>>21)
#define  CRT_SYS_SRST0_get_rstn_kt(data)                                         ((0x00100000&(data))>>20)
#define  CRT_SYS_SRST0_get_rstn_ib_gpu(data)                                     ((0x00080000&(data))>>19)
#define  CRT_SYS_SRST0_get_rstn_kcpu(data)                                       ((0x00040000&(data))>>18)
#define  CRT_SYS_SRST0_get_rstn_vde2(data)                                       ((0x00020000&(data))>>17)
#define  CRT_SYS_SRST0_get_rstn_ve2_p2(data)                                     ((0x00010000&(data))>>16)
#define  CRT_SYS_SRST0_get_rstn_ve2(data)                                        ((0x00008000&(data))>>15)
#define  CRT_SYS_SRST0_get_rstn_vcpu2(data)                                      ((0x00004000&(data))>>14)
#define  CRT_SYS_SRST0_get_rstn_vp9(data)                                        ((0x00002000&(data))>>13)
#define  CRT_SYS_SRST0_get_rstn_acpu(data)                                       ((0x00001000&(data))>>12)
#define  CRT_SYS_SRST0_get_rstn_ib_tvsb2(data)                                   ((0x00000800&(data))>>11)
#define  CRT_SYS_SRST0_get_rstn_ib_tvsb3(data)                                   ((0x00000400&(data))>>10)
#define  CRT_SYS_SRST0_get_rstn_ib_tvsb4(data)                                   ((0x00000200&(data))>>9)
#define  CRT_SYS_SRST0_get_rstn_ib_tvsb5(data)                                   ((0x00000100&(data))>>8)
#define  CRT_SYS_SRST0_get_rstn_scpu_wrap(data)                                  ((0x00000080&(data))>>7)
#define  CRT_SYS_SRST0_get_rstn_vde(data)                                        ((0x00000040&(data))>>6)
#define  CRT_SYS_SRST0_get_rstn_ve_p2(data)                                      ((0x00000020&(data))>>5)
#define  CRT_SYS_SRST0_get_rstn_ve(data)                                         ((0x00000010&(data))>>4)
#define  CRT_SYS_SRST0_get_rstn_vcpu(data)                                       ((0x00000008&(data))>>3)
#define  CRT_SYS_SRST0_get_rstn_ae(data)                                         ((0x00000004&(data))>>2)
#define  CRT_SYS_SRST0_get_rstn_scpu(data)                                       ((0x00000002&(data))>>1)
#define  CRT_SYS_SRST0_get_rstn_pllreg(data)                                     (0x00000001&(data))

#define  CRT_SYS_SRST1                                                           0x18000104
#define  CRT_SYS_SRST1_reg_addr                                                  "0xB8000104"
#define  CRT_SYS_SRST1_reg                                                       0xB8000104
#define  CRT_SYS_SRST1_inst_addr                                                 "0x0001"
#define  set_CRT_SYS_SRST1_reg(data)                                             (*((volatile unsigned int*)CRT_SYS_SRST1_reg)=data)
#define  get_CRT_SYS_SRST1_reg                                                   (*((volatile unsigned int*)CRT_SYS_SRST1_reg))
#define  CRT_SYS_SRST1_rstn_tvsb1_shift                                          (31)
#define  CRT_SYS_SRST1_rstn_tvsb2_shift                                          (30)
#define  CRT_SYS_SRST1_rstn_tvsb3_shift                                          (29)
#define  CRT_SYS_SRST1_rstn_tvsb4_shift                                          (28)
#define  CRT_SYS_SRST1_rstn_tvsb5_shift                                          (27)
#define  CRT_SYS_SRST1_rstn_tve_shift                                            (26)
#define  CRT_SYS_SRST1_rstn_dcphy_shift                                          (25)
#define  CRT_SYS_SRST1_rstn_dcu_shift                                            (24)
#define  CRT_SYS_SRST1_rstn_if_demod_shift                                       (23)
#define  CRT_SYS_SRST1_rstn_vdec_shift                                           (22)
#define  CRT_SYS_SRST1_rstn_vdec2_shift                                          (21)
#define  CRT_SYS_SRST1_rstn_vbis0_shift                                          (20)
#define  CRT_SYS_SRST1_rstn_audio2_dac_shift                                     (19)
#define  CRT_SYS_SRST1_rstn_audio_adc_shift                                      (18)
#define  CRT_SYS_SRST1_rstn_audio_dac_shift                                      (17)
#define  CRT_SYS_SRST1_rstn_audio_shift                                          (16)
#define  CRT_SYS_SRST1_rstn_ifadc_shift                                          (15)
#define  CRT_SYS_SRST1_rstn_cbus_shift                                           (14)
#define  CRT_SYS_SRST1_rstn_offms_shift                                          (13)
#define  CRT_SYS_SRST1_rstn_me_shift                                             (12)
#define  CRT_SYS_SRST1_rstn_apll_adc_shift                                       (11)
#define  CRT_SYS_SRST1_rstn_hdmi_shift                                           (10)
#define  CRT_SYS_SRST1_rstn_hdmitx_shift                                         (9)
#define  CRT_SYS_SRST1_rstn_tp_shift                                             (8)
#define  CRT_SYS_SRST1_rstn_cp_shift                                             (7)
#define  CRT_SYS_SRST1_rstn_md_shift                                             (6)
#define  CRT_SYS_SRST1_rstn_se_shift                                             (5)
#define  CRT_SYS_SRST1_rstn_3d_gde_shift                                         (3)
#define  CRT_SYS_SRST1_rstn_vodma_shift                                          (2)
#define  CRT_SYS_SRST1_rstn_dispim_shift                                         (1)
#define  CRT_SYS_SRST1_rstn_disp_shift                                           (0)
#define  CRT_SYS_SRST1_rstn_tvsb1_mask                                           (0x80000000)
#define  CRT_SYS_SRST1_rstn_tvsb2_mask                                           (0x40000000)
#define  CRT_SYS_SRST1_rstn_tvsb3_mask                                           (0x20000000)
#define  CRT_SYS_SRST1_rstn_tvsb4_mask                                           (0x10000000)
#define  CRT_SYS_SRST1_rstn_tvsb5_mask                                           (0x08000000)
#define  CRT_SYS_SRST1_rstn_tve_mask                                             (0x04000000)
#define  CRT_SYS_SRST1_rstn_dcphy_mask                                           (0x02000000)
#define  CRT_SYS_SRST1_rstn_dcu_mask                                             (0x01000000)
#define  CRT_SYS_SRST1_rstn_if_demod_mask                                        (0x00800000)
#define  CRT_SYS_SRST1_rstn_vdec_mask                                            (0x00400000)
#define  CRT_SYS_SRST1_rstn_vdec2_mask                                           (0x00200000)
#define  CRT_SYS_SRST1_rstn_vbis0_mask                                           (0x00100000)
#define  CRT_SYS_SRST1_rstn_audio2_dac_mask                                      (0x00080000)
#define  CRT_SYS_SRST1_rstn_audio_adc_mask                                       (0x00040000)
#define  CRT_SYS_SRST1_rstn_audio_dac_mask                                       (0x00020000)
#define  CRT_SYS_SRST1_rstn_audio_mask                                           (0x00010000)
#define  CRT_SYS_SRST1_rstn_ifadc_mask                                           (0x00008000)
#define  CRT_SYS_SRST1_rstn_cbus_mask                                            (0x00004000)
#define  CRT_SYS_SRST1_rstn_offms_mask                                           (0x00002000)
#define  CRT_SYS_SRST1_rstn_me_mask                                              (0x00001000)
#define  CRT_SYS_SRST1_rstn_apll_adc_mask                                        (0x00000800)
#define  CRT_SYS_SRST1_rstn_hdmi_mask                                            (0x00000400)
#define  CRT_SYS_SRST1_rstn_hdmitx_mask                                          (0x00000200)
#define  CRT_SYS_SRST1_rstn_tp_mask                                              (0x00000100)
#define  CRT_SYS_SRST1_rstn_cp_mask                                              (0x00000080)
#define  CRT_SYS_SRST1_rstn_md_mask                                              (0x00000040)
#define  CRT_SYS_SRST1_rstn_se_mask                                              (0x00000020)
#define  CRT_SYS_SRST1_rstn_3d_gde_mask                                          (0x00000008)
#define  CRT_SYS_SRST1_rstn_vodma_mask                                           (0x00000004)
#define  CRT_SYS_SRST1_rstn_dispim_mask                                          (0x00000002)
#define  CRT_SYS_SRST1_rstn_disp_mask                                            (0x00000001)
#define  CRT_SYS_SRST1_rstn_tvsb1(data)                                          (0x80000000&((data)<<31))
#define  CRT_SYS_SRST1_rstn_tvsb2(data)                                          (0x40000000&((data)<<30))
#define  CRT_SYS_SRST1_rstn_tvsb3(data)                                          (0x20000000&((data)<<29))
#define  CRT_SYS_SRST1_rstn_tvsb4(data)                                          (0x10000000&((data)<<28))
#define  CRT_SYS_SRST1_rstn_tvsb5(data)                                          (0x08000000&((data)<<27))
#define  CRT_SYS_SRST1_rstn_tve(data)                                            (0x04000000&((data)<<26))
#define  CRT_SYS_SRST1_rstn_dcphy(data)                                          (0x02000000&((data)<<25))
#define  CRT_SYS_SRST1_rstn_dcu(data)                                            (0x01000000&((data)<<24))
#define  CRT_SYS_SRST1_rstn_if_demod(data)                                       (0x00800000&((data)<<23))
#define  CRT_SYS_SRST1_rstn_vdec(data)                                           (0x00400000&((data)<<22))
#define  CRT_SYS_SRST1_rstn_vdec2(data)                                          (0x00200000&((data)<<21))
#define  CRT_SYS_SRST1_rstn_vbis0(data)                                          (0x00100000&((data)<<20))
#define  CRT_SYS_SRST1_rstn_audio2_dac(data)                                     (0x00080000&((data)<<19))
#define  CRT_SYS_SRST1_rstn_audio_adc(data)                                      (0x00040000&((data)<<18))
#define  CRT_SYS_SRST1_rstn_audio_dac(data)                                      (0x00020000&((data)<<17))
#define  CRT_SYS_SRST1_rstn_audio(data)                                          (0x00010000&((data)<<16))
#define  CRT_SYS_SRST1_rstn_ifadc(data)                                          (0x00008000&((data)<<15))
#define  CRT_SYS_SRST1_rstn_cbus(data)                                           (0x00004000&((data)<<14))
#define  CRT_SYS_SRST1_rstn_offms(data)                                          (0x00002000&((data)<<13))
#define  CRT_SYS_SRST1_rstn_me(data)                                             (0x00001000&((data)<<12))
#define  CRT_SYS_SRST1_rstn_apll_adc(data)                                       (0x00000800&((data)<<11))
#define  CRT_SYS_SRST1_rstn_hdmi(data)                                           (0x00000400&((data)<<10))
#define  CRT_SYS_SRST1_rstn_hdmitx(data)                                         (0x00000200&((data)<<9))
#define  CRT_SYS_SRST1_rstn_tp(data)                                             (0x00000100&((data)<<8))
#define  CRT_SYS_SRST1_rstn_cp(data)                                             (0x00000080&((data)<<7))
#define  CRT_SYS_SRST1_rstn_md(data)                                             (0x00000040&((data)<<6))
#define  CRT_SYS_SRST1_rstn_se(data)                                             (0x00000020&((data)<<5))
#define  CRT_SYS_SRST1_rstn_3d_gde(data)                                         (0x00000008&((data)<<3))
#define  CRT_SYS_SRST1_rstn_vodma(data)                                          (0x00000004&((data)<<2))
#define  CRT_SYS_SRST1_rstn_dispim(data)                                         (0x00000002&((data)<<1))
#define  CRT_SYS_SRST1_rstn_disp(data)                                           (0x00000001&(data))
#define  CRT_SYS_SRST1_get_rstn_tvsb1(data)                                      ((0x80000000&(data))>>31)
#define  CRT_SYS_SRST1_get_rstn_tvsb2(data)                                      ((0x40000000&(data))>>30)
#define  CRT_SYS_SRST1_get_rstn_tvsb3(data)                                      ((0x20000000&(data))>>29)
#define  CRT_SYS_SRST1_get_rstn_tvsb4(data)                                      ((0x10000000&(data))>>28)
#define  CRT_SYS_SRST1_get_rstn_tvsb5(data)                                      ((0x08000000&(data))>>27)
#define  CRT_SYS_SRST1_get_rstn_tve(data)                                        ((0x04000000&(data))>>26)
#define  CRT_SYS_SRST1_get_rstn_dcphy(data)                                      ((0x02000000&(data))>>25)
#define  CRT_SYS_SRST1_get_rstn_dcu(data)                                        ((0x01000000&(data))>>24)
#define  CRT_SYS_SRST1_get_rstn_if_demod(data)                                   ((0x00800000&(data))>>23)
#define  CRT_SYS_SRST1_get_rstn_vdec(data)                                       ((0x00400000&(data))>>22)
#define  CRT_SYS_SRST1_get_rstn_vdec2(data)                                      ((0x00200000&(data))>>21)
#define  CRT_SYS_SRST1_get_rstn_vbis0(data)                                      ((0x00100000&(data))>>20)
#define  CRT_SYS_SRST1_get_rstn_audio2_dac(data)                                 ((0x00080000&(data))>>19)
#define  CRT_SYS_SRST1_get_rstn_audio_adc(data)                                  ((0x00040000&(data))>>18)
#define  CRT_SYS_SRST1_get_rstn_audio_dac(data)                                  ((0x00020000&(data))>>17)
#define  CRT_SYS_SRST1_get_rstn_audio(data)                                      ((0x00010000&(data))>>16)
#define  CRT_SYS_SRST1_get_rstn_ifadc(data)                                      ((0x00008000&(data))>>15)
#define  CRT_SYS_SRST1_get_rstn_cbus(data)                                       ((0x00004000&(data))>>14)
#define  CRT_SYS_SRST1_get_rstn_offms(data)                                      ((0x00002000&(data))>>13)
#define  CRT_SYS_SRST1_get_rstn_me(data)                                         ((0x00001000&(data))>>12)
#define  CRT_SYS_SRST1_get_rstn_apll_adc(data)                                   ((0x00000800&(data))>>11)
#define  CRT_SYS_SRST1_get_rstn_hdmi(data)                                       ((0x00000400&(data))>>10)
#define  CRT_SYS_SRST1_get_rstn_hdmitx(data)                                     ((0x00000200&(data))>>9)
#define  CRT_SYS_SRST1_get_rstn_tp(data)                                         ((0x00000100&(data))>>8)
#define  CRT_SYS_SRST1_get_rstn_cp(data)                                         ((0x00000080&(data))>>7)
#define  CRT_SYS_SRST1_get_rstn_md(data)                                         ((0x00000040&(data))>>6)
#define  CRT_SYS_SRST1_get_rstn_se(data)                                         ((0x00000020&(data))>>5)
#define  CRT_SYS_SRST1_get_rstn_3d_gde(data)                                     ((0x00000008&(data))>>3)
#define  CRT_SYS_SRST1_get_rstn_vodma(data)                                      ((0x00000004&(data))>>2)
#define  CRT_SYS_SRST1_get_rstn_dispim(data)                                     ((0x00000002&(data))>>1)
#define  CRT_SYS_SRST1_get_rstn_disp(data)                                       (0x00000001&(data))

#define  CRT_SYS_SRST2                                                           0x18000108
#define  CRT_SYS_SRST2_reg_addr                                                  "0xB8000108"
#define  CRT_SYS_SRST2_reg                                                       0xB8000108
#define  CRT_SYS_SRST2_inst_addr                                                 "0x0002"
#define  set_CRT_SYS_SRST2_reg(data)                                             (*((volatile unsigned int*)CRT_SYS_SRST2_reg)=data)
#define  get_CRT_SYS_SRST2_reg                                                   (*((volatile unsigned int*)CRT_SYS_SRST2_reg))
#define  CRT_SYS_SRST2_rstn_tm_shift                                             (28)
#define  CRT_SYS_SRST2_rstn_atvin2_shift                                         (27)
#define  CRT_SYS_SRST2_rstn_atvin_shift                                          (26)
#define  CRT_SYS_SRST2_dummy1_shift                                               (24)
#define  CRT_SYS_SRST2_rstn_emmc_shift                                           (23)
#define  CRT_SYS_SRST2_rstn_bistreg_shift                                        (21)
#define  CRT_SYS_SRST2_dummy2_shift                                               (19)
#define  CRT_SYS_SRST2_rstn_usb_shift                                            (18)
#define  CRT_SYS_SRST2_rstn_otg_shift                                            (17)
#define  CRT_SYS_SRST2_dummy3_shift                                               (14)
#define  CRT_SYS_SRST2_rstn_irtx_shift                                           (13)
#define  CRT_SYS_SRST2_rstn_padmux_shift                                         (12)
#define  CRT_SYS_SRST2_rstn_dtv_demod_shift                                      (11)
#define  CRT_SYS_SRST2_rstn_misc_shift                                           (10)
#define  CRT_SYS_SRST2_rstn_pwm_shift                                            (9)
#define  CRT_SYS_SRST2_rstn_uart1_shift                                          (8)
#define  CRT_SYS_SRST2_rstn_uart2_shift                                          (7)
#define  CRT_SYS_SRST2_rstn_sc1_shift                                            (6)
#define  CRT_SYS_SRST2_rstn_gpio_shift                                           (5)
#define  CRT_SYS_SRST2_rstn_i2c1_shift                                           (4)
#define  CRT_SYS_SRST2_rstn_i2c2_shift                                           (3)
#define  CRT_SYS_SRST2_rstn_nf_shift                                             (2)
#define  CRT_SYS_SRST2_rstn_sc_shift                                             (1)
#define  CRT_SYS_SRST2_rstn_pc_shift                                             (0)
#define  CRT_SYS_SRST2_rstn_tm_mask                                              (0x10000000)
#define  CRT_SYS_SRST2_rstn_atvin2_mask                                          (0x08000000)
#define  CRT_SYS_SRST2_rstn_atvin_mask                                           (0x04000000)
#define  CRT_SYS_SRST2_dummy1_mask                                                (0x03000000)
#define  CRT_SYS_SRST2_rstn_emmc_mask                                            (0x00800000)
#define  CRT_SYS_SRST2_rstn_bistreg_mask                                         (0x00200000)
#define  CRT_SYS_SRST2_dummy2_mask                                                (0x00180000)
#define  CRT_SYS_SRST2_rstn_usb_mask                                             (0x00040000)
#define  CRT_SYS_SRST2_rstn_otg_mask                                             (0x00020000)
#define  CRT_SYS_SRST2_dummy3_mask                                                (0x0000C000)
#define  CRT_SYS_SRST2_rstn_irtx_mask                                            (0x00002000)
#define  CRT_SYS_SRST2_rstn_padmux_mask                                          (0x00001000)
#define  CRT_SYS_SRST2_rstn_dtv_demod_mask                                       (0x00000800)
#define  CRT_SYS_SRST2_rstn_misc_mask                                            (0x00000400)
#define  CRT_SYS_SRST2_rstn_pwm_mask                                             (0x00000200)
#define  CRT_SYS_SRST2_rstn_uart1_mask                                           (0x00000100)
#define  CRT_SYS_SRST2_rstn_uart2_mask                                           (0x00000080)
#define  CRT_SYS_SRST2_rstn_sc1_mask                                             (0x00000040)
#define  CRT_SYS_SRST2_rstn_gpio_mask                                            (0x00000020)
#define  CRT_SYS_SRST2_rstn_i2c1_mask                                            (0x00000010)
#define  CRT_SYS_SRST2_rstn_i2c2_mask                                            (0x00000008)
#define  CRT_SYS_SRST2_rstn_nf_mask                                              (0x00000004)
#define  CRT_SYS_SRST2_rstn_sc_mask                                              (0x00000002)
#define  CRT_SYS_SRST2_rstn_pc_mask                                              (0x00000001)
#define  CRT_SYS_SRST2_rstn_tm(data)                                             (0x10000000&((data)<<28))
#define  CRT_SYS_SRST2_rstn_atvin2(data)                                         (0x08000000&((data)<<27))
#define  CRT_SYS_SRST2_rstn_atvin(data)                                          (0x04000000&((data)<<26))
#define  CRT_SYS_SRST2_dummy1(data)                                               (0x03000000&((data)<<24))
#define  CRT_SYS_SRST2_rstn_emmc(data)                                           (0x00800000&((data)<<23))
#define  CRT_SYS_SRST2_rstn_bistreg(data)                                        (0x00200000&((data)<<21))
#define  CRT_SYS_SRST2_dummy2(data)                                               (0x00180000&((data)<<19))
#define  CRT_SYS_SRST2_rstn_usb(data)                                            (0x00040000&((data)<<18))
#define  CRT_SYS_SRST2_rstn_otg(data)                                            (0x00020000&((data)<<17))
#define  CRT_SYS_SRST2_dummy3(data)                                               (0x0000C000&((data)<<14))
#define  CRT_SYS_SRST2_rstn_irtx(data)                                           (0x00002000&((data)<<13))
#define  CRT_SYS_SRST2_rstn_padmux(data)                                         (0x00001000&((data)<<12))
#define  CRT_SYS_SRST2_rstn_dtv_demod(data)                                      (0x00000800&((data)<<11))
#define  CRT_SYS_SRST2_rstn_misc(data)                                           (0x00000400&((data)<<10))
#define  CRT_SYS_SRST2_rstn_pwm(data)                                            (0x00000200&((data)<<9))
#define  CRT_SYS_SRST2_rstn_uart1(data)                                          (0x00000100&((data)<<8))
#define  CRT_SYS_SRST2_rstn_uart2(data)                                          (0x00000080&((data)<<7))
#define  CRT_SYS_SRST2_rstn_sc1(data)                                            (0x00000040&((data)<<6))
#define  CRT_SYS_SRST2_rstn_gpio(data)                                           (0x00000020&((data)<<5))
#define  CRT_SYS_SRST2_rstn_i2c1(data)                                           (0x00000010&((data)<<4))
#define  CRT_SYS_SRST2_rstn_i2c2(data)                                           (0x00000008&((data)<<3))
#define  CRT_SYS_SRST2_rstn_nf(data)                                             (0x00000004&((data)<<2))
#define  CRT_SYS_SRST2_rstn_sc(data)                                             (0x00000002&((data)<<1))
#define  CRT_SYS_SRST2_rstn_pc(data)                                             (0x00000001&(data))
#define  CRT_SYS_SRST2_get_rstn_tm(data)                                         ((0x10000000&(data))>>28)
#define  CRT_SYS_SRST2_get_rstn_atvin2(data)                                     ((0x08000000&(data))>>27)
#define  CRT_SYS_SRST2_get_rstn_atvin(data)                                      ((0x04000000&(data))>>26)
#define  CRT_SYS_SRST2_get_dummy1(data)                                           ((0x03000000&(data))>>24)
#define  CRT_SYS_SRST2_get_rstn_emmc(data)                                       ((0x00800000&(data))>>23)
#define  CRT_SYS_SRST2_get_rstn_bistreg(data)                                    ((0x00200000&(data))>>21)
#define  CRT_SYS_SRST2_get_dummy2(data)                                           ((0x00180000&(data))>>19)
#define  CRT_SYS_SRST2_get_rstn_usb(data)                                        ((0x00040000&(data))>>18)
#define  CRT_SYS_SRST2_get_rstn_otg(data)                                        ((0x00020000&(data))>>17)
#define  CRT_SYS_SRST2_get_dummy3(data)                                           ((0x0000C000&(data))>>14)
#define  CRT_SYS_SRST2_get_rstn_irtx(data)                                       ((0x00002000&(data))>>13)
#define  CRT_SYS_SRST2_get_rstn_padmux(data)                                     ((0x00001000&(data))>>12)
#define  CRT_SYS_SRST2_get_rstn_dtv_demod(data)                                  ((0x00000800&(data))>>11)
#define  CRT_SYS_SRST2_get_rstn_misc(data)                                       ((0x00000400&(data))>>10)
#define  CRT_SYS_SRST2_get_rstn_pwm(data)                                        ((0x00000200&(data))>>9)
#define  CRT_SYS_SRST2_get_rstn_uart1(data)                                      ((0x00000100&(data))>>8)
#define  CRT_SYS_SRST2_get_rstn_uart2(data)                                      ((0x00000080&(data))>>7)
#define  CRT_SYS_SRST2_get_rstn_sc1(data)                                        ((0x00000040&(data))>>6)
#define  CRT_SYS_SRST2_get_rstn_gpio(data)                                       ((0x00000020&(data))>>5)
#define  CRT_SYS_SRST2_get_rstn_i2c1(data)                                       ((0x00000010&(data))>>4)
#define  CRT_SYS_SRST2_get_rstn_i2c2(data)                                       ((0x00000008&(data))>>3)
#define  CRT_SYS_SRST2_get_rstn_nf(data)                                         ((0x00000004&(data))>>2)
#define  CRT_SYS_SRST2_get_rstn_sc(data)                                         ((0x00000002&(data))>>1)
#define  CRT_SYS_SRST2_get_rstn_pc(data)                                         (0x00000001&(data))

#define  CRT_SYS_SRST3                                                           0x1800010C
#define  CRT_SYS_SRST3_reg_addr                                                  "0xB800010C"
#define  CRT_SYS_SRST3_reg                                                       0xB800010C
#define  CRT_SYS_SRST3_inst_addr                                                 "0x0003"
#define  set_CRT_SYS_SRST3_reg(data)                                             (*((volatile unsigned int*)CRT_SYS_SRST3_reg)=data)
#define  get_CRT_SYS_SRST3_reg                                                   (*((volatile unsigned int*)CRT_SYS_SRST3_reg))
#define  CRT_SYS_SRST3_rstn_dcphy2_shift                                         (25)
#define  CRT_SYS_SRST3_rstn_dcu2_shift                                           (24)
#define  CRT_SYS_SRST3_rstn_ddc_shift                                            (17)
#define  CRT_SYS_SRST3_rstn_sd_shift                                             (16)
#define  CRT_SYS_SRST3_rstn_hdmitx_pll_shift                                     (12)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p3_shift                                    (7)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p2_shift                                    (6)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p1_shift                                    (5)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p0_shift                                    (4)
#define  CRT_SYS_SRST3_rstn_usb3_mdio_p0_shift                                   (1)
#define  CRT_SYS_SRST3_rstn_usb3_phy_p0_shift                                    (0)
#define  CRT_SYS_SRST3_rstn_dcphy2_mask                                          (0x02000000)
#define  CRT_SYS_SRST3_rstn_dcu2_mask                                            (0x01000000)
#define  CRT_SYS_SRST3_rstn_ddc_mask                                             (0x00020000)
#define  CRT_SYS_SRST3_rstn_sd_mask                                              (0x00010000)
#define  CRT_SYS_SRST3_rstn_hdmitx_pll_mask                                      (0x00001000)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p3_mask                                     (0x00000080)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p2_mask                                     (0x00000040)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p1_mask                                     (0x00000020)
#define  CRT_SYS_SRST3_rstn_usb2_phy_p0_mask                                     (0x00000010)
#define  CRT_SYS_SRST3_rstn_usb3_mdio_p0_mask                                    (0x00000002)
#define  CRT_SYS_SRST3_rstn_usb3_phy_p0_mask                                     (0x00000001)
#define  CRT_SYS_SRST3_rstn_dcphy2(data)                                         (0x02000000&((data)<<25))
#define  CRT_SYS_SRST3_rstn_dcu2(data)                                           (0x01000000&((data)<<24))
#define  CRT_SYS_SRST3_rstn_ddc(data)                                            (0x00020000&((data)<<17))
#define  CRT_SYS_SRST3_rstn_sd(data)                                             (0x00010000&((data)<<16))
#define  CRT_SYS_SRST3_rstn_hdmitx_pll(data)                                     (0x00001000&((data)<<12))
#define  CRT_SYS_SRST3_rstn_usb2_phy_p3(data)                                    (0x00000080&((data)<<7))
#define  CRT_SYS_SRST3_rstn_usb2_phy_p2(data)                                    (0x00000040&((data)<<6))
#define  CRT_SYS_SRST3_rstn_usb2_phy_p1(data)                                    (0x00000020&((data)<<5))
#define  CRT_SYS_SRST3_rstn_usb2_phy_p0(data)                                    (0x00000010&((data)<<4))
#define  CRT_SYS_SRST3_rstn_usb3_mdio_p0(data)                                   (0x00000002&((data)<<1))
#define  CRT_SYS_SRST3_rstn_usb3_phy_p0(data)                                    (0x00000001&(data))
#define  CRT_SYS_SRST3_get_rstn_dcphy2(data)                                     ((0x02000000&(data))>>25)
#define  CRT_SYS_SRST3_get_rstn_dcu2(data)                                       ((0x01000000&(data))>>24)
#define  CRT_SYS_SRST3_get_rstn_ddc(data)                                        ((0x00020000&(data))>>17)
#define  CRT_SYS_SRST3_get_rstn_sd(data)                                         ((0x00010000&(data))>>16)
#define  CRT_SYS_SRST3_get_rstn_hdmitx_pll(data)                                 ((0x00001000&(data))>>12)
#define  CRT_SYS_SRST3_get_rstn_usb2_phy_p3(data)                                ((0x00000080&(data))>>7)
#define  CRT_SYS_SRST3_get_rstn_usb2_phy_p2(data)                                ((0x00000040&(data))>>6)
#define  CRT_SYS_SRST3_get_rstn_usb2_phy_p1(data)                                ((0x00000020&(data))>>5)
#define  CRT_SYS_SRST3_get_rstn_usb2_phy_p0(data)                                ((0x00000010&(data))>>4)
#define  CRT_SYS_SRST3_get_rstn_usb3_mdio_p0(data)                               ((0x00000002&(data))>>1)
#define  CRT_SYS_SRST3_get_rstn_usb3_phy_p0(data)                                (0x00000001&(data))

#define  CRT_SYS_CLKEN0                                                          0x18000110
#define  CRT_SYS_CLKEN0_reg_addr                                                 "0xB8000110"
#define  CRT_SYS_CLKEN0_reg                                                      0xB8000110
#define  CRT_SYS_CLKEN0_inst_addr                                                "0x0004"
#define  set_CRT_SYS_CLKEN0_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CLKEN0_reg)=data)
#define  get_CRT_SYS_CLKEN0_reg                                                  (*((volatile unsigned int*)CRT_SYS_CLKEN0_reg))
#define  CRT_SYS_CLKEN0_clken_akl_shift                                          (23)
#define  CRT_SYS_CLKEN0_clken_dsc_shift                                          (22)
#define  CRT_SYS_CLKEN0_clken_sce_shift                                          (21)
#define  CRT_SYS_CLKEN0_clken_kt_shift                                           (20)
#define  CRT_SYS_CLKEN0_clken_kcpu_shift                                         (18)
#define  CRT_SYS_CLKEN0_clken_ve2_p2_shift                                       (16)
#define  CRT_SYS_CLKEN0_clken_ve2_shift                                          (15)
#define  CRT_SYS_CLKEN0_clken_vcpu2_shift                                        (14)
#define  CRT_SYS_CLKEN0_clken_vp9_shift                                          (13)
#define  CRT_SYS_CLKEN0_clken_acpu_shift                                         (12)
#define  CRT_SYS_CLKEN0_clken_ve_p2_shift                                        (5)
#define  CRT_SYS_CLKEN0_clken_ve_shift                                           (4)
#define  CRT_SYS_CLKEN0_clken_vcpu_shift                                         (3)
#define  CRT_SYS_CLKEN0_clken_scpu_wrap_shift                                    (2)
#define  CRT_SYS_CLKEN0_clken_scpu_shift                                         (1)
#define  CRT_SYS_CLKEN0_clken_pllreg_shift                                       (0)
#define  CRT_SYS_CLKEN0_clken_akl_mask                                           (0x00800000)
#define  CRT_SYS_CLKEN0_clken_dsc_mask                                           (0x00400000)
#define  CRT_SYS_CLKEN0_clken_sce_mask                                           (0x00200000)
#define  CRT_SYS_CLKEN0_clken_kt_mask                                            (0x00100000)
#define  CRT_SYS_CLKEN0_clken_kcpu_mask                                          (0x00040000)
#define  CRT_SYS_CLKEN0_clken_ve2_p2_mask                                        (0x00010000)
#define  CRT_SYS_CLKEN0_clken_ve2_mask                                           (0x00008000)
#define  CRT_SYS_CLKEN0_clken_vcpu2_mask                                         (0x00004000)
#define  CRT_SYS_CLKEN0_clken_vp9_mask                                           (0x00002000)
#define  CRT_SYS_CLKEN0_clken_acpu_mask                                          (0x00001000)
#define  CRT_SYS_CLKEN0_clken_ve_p2_mask                                         (0x00000020)
#define  CRT_SYS_CLKEN0_clken_ve_mask                                            (0x00000010)
#define  CRT_SYS_CLKEN0_clken_vcpu_mask                                          (0x00000008)
#define  CRT_SYS_CLKEN0_clken_scpu_wrap_mask                                     (0x00000004)
#define  CRT_SYS_CLKEN0_clken_scpu_mask                                          (0x00000002)
#define  CRT_SYS_CLKEN0_clken_pllreg_mask                                        (0x00000001)
#define  CRT_SYS_CLKEN0_clken_akl(data)                                          (0x00800000&((data)<<23))
#define  CRT_SYS_CLKEN0_clken_dsc(data)                                          (0x00400000&((data)<<22))
#define  CRT_SYS_CLKEN0_clken_sce(data)                                          (0x00200000&((data)<<21))
#define  CRT_SYS_CLKEN0_clken_kt(data)                                           (0x00100000&((data)<<20))
#define  CRT_SYS_CLKEN0_clken_kcpu(data)                                         (0x00040000&((data)<<18))
#define  CRT_SYS_CLKEN0_clken_ve2_p2(data)                                       (0x00010000&((data)<<16))
#define  CRT_SYS_CLKEN0_clken_ve2(data)                                          (0x00008000&((data)<<15))
#define  CRT_SYS_CLKEN0_clken_vcpu2(data)                                        (0x00004000&((data)<<14))
#define  CRT_SYS_CLKEN0_clken_vp9(data)                                          (0x00002000&((data)<<13))
#define  CRT_SYS_CLKEN0_clken_acpu(data)                                         (0x00001000&((data)<<12))
#define  CRT_SYS_CLKEN0_clken_ve_p2(data)                                        (0x00000020&((data)<<5))
#define  CRT_SYS_CLKEN0_clken_ve(data)                                           (0x00000010&((data)<<4))
#define  CRT_SYS_CLKEN0_clken_vcpu(data)                                         (0x00000008&((data)<<3))
#define  CRT_SYS_CLKEN0_clken_scpu_wrap(data)                                    (0x00000004&((data)<<2))
#define  CRT_SYS_CLKEN0_clken_scpu(data)                                         (0x00000002&((data)<<1))
#define  CRT_SYS_CLKEN0_clken_pllreg(data)                                       (0x00000001&(data))
#define  CRT_SYS_CLKEN0_get_clken_akl(data)                                      ((0x00800000&(data))>>23)
#define  CRT_SYS_CLKEN0_get_clken_dsc(data)                                      ((0x00400000&(data))>>22)
#define  CRT_SYS_CLKEN0_get_clken_sce(data)                                      ((0x00200000&(data))>>21)
#define  CRT_SYS_CLKEN0_get_clken_kt(data)                                       ((0x00100000&(data))>>20)
#define  CRT_SYS_CLKEN0_get_clken_kcpu(data)                                     ((0x00040000&(data))>>18)
#define  CRT_SYS_CLKEN0_get_clken_ve2_p2(data)                                   ((0x00010000&(data))>>16)
#define  CRT_SYS_CLKEN0_get_clken_ve2(data)                                      ((0x00008000&(data))>>15)
#define  CRT_SYS_CLKEN0_get_clken_vcpu2(data)                                    ((0x00004000&(data))>>14)
#define  CRT_SYS_CLKEN0_get_clken_vp9(data)                                      ((0x00002000&(data))>>13)
#define  CRT_SYS_CLKEN0_get_clken_acpu(data)                                     ((0x00001000&(data))>>12)
#define  CRT_SYS_CLKEN0_get_clken_ve_p2(data)                                    ((0x00000020&(data))>>5)
#define  CRT_SYS_CLKEN0_get_clken_ve(data)                                       ((0x00000010&(data))>>4)
#define  CRT_SYS_CLKEN0_get_clken_vcpu(data)                                     ((0x00000008&(data))>>3)
#define  CRT_SYS_CLKEN0_get_clken_scpu_wrap(data)                                ((0x00000004&(data))>>2)
#define  CRT_SYS_CLKEN0_get_clken_scpu(data)                                     ((0x00000002&(data))>>1)
#define  CRT_SYS_CLKEN0_get_clken_pllreg(data)                                   (0x00000001&(data))

#define  CRT_SYS_CLKEN1                                                          0x18000114
#define  CRT_SYS_CLKEN1_reg_addr                                                 "0xB8000114"
#define  CRT_SYS_CLKEN1_reg                                                      0xB8000114
#define  CRT_SYS_CLKEN1_inst_addr                                                "0x0005"
#define  set_CRT_SYS_CLKEN1_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CLKEN1_reg)=data)
#define  get_CRT_SYS_CLKEN1_reg                                                  (*((volatile unsigned int*)CRT_SYS_CLKEN1_reg))
#define  CRT_SYS_CLKEN1_clken_tvsb1_shift                                        (31)
#define  CRT_SYS_CLKEN1_clken_tvsb2_shift                                        (30)
#define  CRT_SYS_CLKEN1_clken_tvsb3_shift                                        (29)
#define  CRT_SYS_CLKEN1_clken_tvsb4_shift                                        (28)
#define  CRT_SYS_CLKEN1_clken_tvsb5_shift                                        (27)
#define  CRT_SYS_CLKEN1_clken_tve_shift                                          (26)
#define  CRT_SYS_CLKEN1_clken_dcphy_shift                                        (25)
#define  CRT_SYS_CLKEN1_clken_dcu_shift                                          (24)
#define  CRT_SYS_CLKEN1_clken_if_demod_shift                                     (23)
#define  CRT_SYS_CLKEN1_clken_vdec_shift                                         (22)
#define  CRT_SYS_CLKEN1_clken_se2_shift                                          (21)
#define  CRT_SYS_CLKEN1_clken_vbis0_shift                                        (20)
#define  CRT_SYS_CLKEN1_dummy_shift                                              (18)
#define  CRT_SYS_CLKEN1_clken_audio_pre512fs_shift                               (17)
#define  CRT_SYS_CLKEN1_clken_audio_shift                                        (16)
#define  CRT_SYS_CLKEN1_clken_ifadc_shift                                        (15)
#define  CRT_SYS_CLKEN1_clken_cbus_shift                                         (14)
#define  CRT_SYS_CLKEN1_clken_offms_shift                                        (13)
#define  CRT_SYS_CLKEN1_clken_me_shift                                           (12)
#define  CRT_SYS_CLKEN1_clken_apll_adc_shift                                     (11)
#define  CRT_SYS_CLKEN1_clken_hdmi_shift                                         (10)
#define  CRT_SYS_CLKEN1_clken_hdmitx_shift                                       (9)
#define  CRT_SYS_CLKEN1_clken_tp_shift                                           (8)
#define  CRT_SYS_CLKEN1_clken_cp_shift                                           (7)
#define  CRT_SYS_CLKEN1_clken_md_shift                                           (6)
#define  CRT_SYS_CLKEN1_clken_se_shift                                           (5)
#define  CRT_SYS_CLKEN1_clken_tp_div_shift                                       (4)
#define  CRT_SYS_CLKEN1_clken_3d_gde_shift                                       (3)
#define  CRT_SYS_CLKEN1_clken_vodma_shift                                        (2)
#define  CRT_SYS_CLKEN1_clken_dispim_shift                                       (1)
#define  CRT_SYS_CLKEN1_clken_disp_shift                                         (0)
#define  CRT_SYS_CLKEN1_clken_tvsb1_mask                                         (0x80000000)
#define  CRT_SYS_CLKEN1_clken_tvsb2_mask                                         (0x40000000)
#define  CRT_SYS_CLKEN1_clken_tvsb3_mask                                         (0x20000000)
#define  CRT_SYS_CLKEN1_clken_tvsb4_mask                                         (0x10000000)
#define  CRT_SYS_CLKEN1_clken_tvsb5_mask                                         (0x08000000)
#define  CRT_SYS_CLKEN1_clken_tve_mask                                           (0x04000000)
#define  CRT_SYS_CLKEN1_clken_dcphy_mask                                         (0x02000000)
#define  CRT_SYS_CLKEN1_clken_dcu_mask                                           (0x01000000)
#define  CRT_SYS_CLKEN1_clken_if_demod_mask                                      (0x00800000)
#define  CRT_SYS_CLKEN1_clken_vdec_mask                                          (0x00400000)
#define  CRT_SYS_CLKEN1_clken_se2_mask                                           (0x00200000)
#define  CRT_SYS_CLKEN1_clken_vbis0_mask                                         (0x00100000)
#define  CRT_SYS_CLKEN1_dummy_mask                                               (0x000C0000)
#define  CRT_SYS_CLKEN1_clken_audio_pre512fs_mask                                (0x00020000)
#define  CRT_SYS_CLKEN1_clken_audio_mask                                         (0x00010000)
#define  CRT_SYS_CLKEN1_clken_ifadc_mask                                         (0x00008000)
#define  CRT_SYS_CLKEN1_clken_cbus_mask                                          (0x00004000)
#define  CRT_SYS_CLKEN1_clken_offms_mask                                         (0x00002000)
#define  CRT_SYS_CLKEN1_clken_me_mask                                            (0x00001000)
#define  CRT_SYS_CLKEN1_clken_apll_adc_mask                                      (0x00000800)
#define  CRT_SYS_CLKEN1_clken_hdmi_mask                                          (0x00000400)
#define  CRT_SYS_CLKEN1_clken_hdmitx_mask                                        (0x00000200)
#define  CRT_SYS_CLKEN1_clken_tp_mask                                            (0x00000100)
#define  CRT_SYS_CLKEN1_clken_cp_mask                                            (0x00000080)
#define  CRT_SYS_CLKEN1_clken_md_mask                                            (0x00000040)
#define  CRT_SYS_CLKEN1_clken_se_mask                                            (0x00000020)
#define  CRT_SYS_CLKEN1_clken_tp_div_mask                                        (0x00000010)
#define  CRT_SYS_CLKEN1_clken_3d_gde_mask                                        (0x00000008)
#define  CRT_SYS_CLKEN1_clken_vodma_mask                                         (0x00000004)
#define  CRT_SYS_CLKEN1_clken_dispim_mask                                        (0x00000002)
#define  CRT_SYS_CLKEN1_clken_disp_mask                                          (0x00000001)
#define  CRT_SYS_CLKEN1_clken_tvsb1(data)                                        (0x80000000&((data)<<31))
#define  CRT_SYS_CLKEN1_clken_tvsb2(data)                                        (0x40000000&((data)<<30))
#define  CRT_SYS_CLKEN1_clken_tvsb3(data)                                        (0x20000000&((data)<<29))
#define  CRT_SYS_CLKEN1_clken_tvsb4(data)                                        (0x10000000&((data)<<28))
#define  CRT_SYS_CLKEN1_clken_tvsb5(data)                                        (0x08000000&((data)<<27))
#define  CRT_SYS_CLKEN1_clken_tve(data)                                          (0x04000000&((data)<<26))
#define  CRT_SYS_CLKEN1_clken_dcphy(data)                                        (0x02000000&((data)<<25))
#define  CRT_SYS_CLKEN1_clken_dcu(data)                                          (0x01000000&((data)<<24))
#define  CRT_SYS_CLKEN1_clken_if_demod(data)                                     (0x00800000&((data)<<23))
#define  CRT_SYS_CLKEN1_clken_vdec(data)                                         (0x00400000&((data)<<22))
#define  CRT_SYS_CLKEN1_clken_se2(data)                                          (0x00200000&((data)<<21))
#define  CRT_SYS_CLKEN1_clken_vbis0(data)                                        (0x00100000&((data)<<20))
#define  CRT_SYS_CLKEN1_dummy(data)                                              (0x000C0000&((data)<<18))
#define  CRT_SYS_CLKEN1_clken_audio_pre512fs(data)                               (0x00020000&((data)<<17))
#define  CRT_SYS_CLKEN1_clken_audio(data)                                        (0x00010000&((data)<<16))
#define  CRT_SYS_CLKEN1_clken_ifadc(data)                                        (0x00008000&((data)<<15))
#define  CRT_SYS_CLKEN1_clken_cbus(data)                                         (0x00004000&((data)<<14))
#define  CRT_SYS_CLKEN1_clken_offms(data)                                        (0x00002000&((data)<<13))
#define  CRT_SYS_CLKEN1_clken_me(data)                                           (0x00001000&((data)<<12))
#define  CRT_SYS_CLKEN1_clken_apll_adc(data)                                     (0x00000800&((data)<<11))
#define  CRT_SYS_CLKEN1_clken_hdmi(data)                                         (0x00000400&((data)<<10))
#define  CRT_SYS_CLKEN1_clken_hdmitx(data)                                       (0x00000200&((data)<<9))
#define  CRT_SYS_CLKEN1_clken_tp(data)                                           (0x00000100&((data)<<8))
#define  CRT_SYS_CLKEN1_clken_cp(data)                                           (0x00000080&((data)<<7))
#define  CRT_SYS_CLKEN1_clken_md(data)                                           (0x00000040&((data)<<6))
#define  CRT_SYS_CLKEN1_clken_se(data)                                           (0x00000020&((data)<<5))
#define  CRT_SYS_CLKEN1_clken_tp_div(data)                                       (0x00000010&((data)<<4))
#define  CRT_SYS_CLKEN1_clken_3d_gde(data)                                       (0x00000008&((data)<<3))
#define  CRT_SYS_CLKEN1_clken_vodma(data)                                        (0x00000004&((data)<<2))
#define  CRT_SYS_CLKEN1_clken_dispim(data)                                       (0x00000002&((data)<<1))
#define  CRT_SYS_CLKEN1_clken_disp(data)                                         (0x00000001&(data))
#define  CRT_SYS_CLKEN1_get_clken_tvsb1(data)                                    ((0x80000000&(data))>>31)
#define  CRT_SYS_CLKEN1_get_clken_tvsb2(data)                                    ((0x40000000&(data))>>30)
#define  CRT_SYS_CLKEN1_get_clken_tvsb3(data)                                    ((0x20000000&(data))>>29)
#define  CRT_SYS_CLKEN1_get_clken_tvsb4(data)                                    ((0x10000000&(data))>>28)
#define  CRT_SYS_CLKEN1_get_clken_tvsb5(data)                                    ((0x08000000&(data))>>27)
#define  CRT_SYS_CLKEN1_get_clken_tve(data)                                      ((0x04000000&(data))>>26)
#define  CRT_SYS_CLKEN1_get_clken_dcphy(data)                                    ((0x02000000&(data))>>25)
#define  CRT_SYS_CLKEN1_get_clken_dcu(data)                                      ((0x01000000&(data))>>24)
#define  CRT_SYS_CLKEN1_get_clken_if_demod(data)                                 ((0x00800000&(data))>>23)
#define  CRT_SYS_CLKEN1_get_clken_vdec(data)                                     ((0x00400000&(data))>>22)
#define  CRT_SYS_CLKEN1_get_clken_se2(data)                                      ((0x00200000&(data))>>21)
#define  CRT_SYS_CLKEN1_get_clken_vbis0(data)                                    ((0x00100000&(data))>>20)
#define  CRT_SYS_CLKEN1_get_dummy(data)                                          ((0x000C0000&(data))>>18)
#define  CRT_SYS_CLKEN1_get_clken_audio_pre512fs(data)                           ((0x00020000&(data))>>17)
#define  CRT_SYS_CLKEN1_get_clken_audio(data)                                    ((0x00010000&(data))>>16)
#define  CRT_SYS_CLKEN1_get_clken_ifadc(data)                                    ((0x00008000&(data))>>15)
#define  CRT_SYS_CLKEN1_get_clken_cbus(data)                                     ((0x00004000&(data))>>14)
#define  CRT_SYS_CLKEN1_get_clken_offms(data)                                    ((0x00002000&(data))>>13)
#define  CRT_SYS_CLKEN1_get_clken_me(data)                                       ((0x00001000&(data))>>12)
#define  CRT_SYS_CLKEN1_get_clken_apll_adc(data)                                 ((0x00000800&(data))>>11)
#define  CRT_SYS_CLKEN1_get_clken_hdmi(data)                                     ((0x00000400&(data))>>10)
#define  CRT_SYS_CLKEN1_get_clken_hdmitx(data)                                   ((0x00000200&(data))>>9)
#define  CRT_SYS_CLKEN1_get_clken_tp(data)                                       ((0x00000100&(data))>>8)
#define  CRT_SYS_CLKEN1_get_clken_cp(data)                                       ((0x00000080&(data))>>7)
#define  CRT_SYS_CLKEN1_get_clken_md(data)                                       ((0x00000040&(data))>>6)
#define  CRT_SYS_CLKEN1_get_clken_se(data)                                       ((0x00000020&(data))>>5)
#define  CRT_SYS_CLKEN1_get_clken_tp_div(data)                                   ((0x00000010&(data))>>4)
#define  CRT_SYS_CLKEN1_get_clken_3d_gde(data)                                   ((0x00000008&(data))>>3)
#define  CRT_SYS_CLKEN1_get_clken_vodma(data)                                    ((0x00000004&(data))>>2)
#define  CRT_SYS_CLKEN1_get_clken_dispim(data)                                   ((0x00000002&(data))>>1)
#define  CRT_SYS_CLKEN1_get_clken_disp(data)                                     (0x00000001&(data))

#define  CRT_SYS_CLKEN2                                                          0x18000118
#define  CRT_SYS_CLKEN2_reg_addr                                                 "0xB8000118"
#define  CRT_SYS_CLKEN2_reg                                                      0xB8000118
#define  CRT_SYS_CLKEN2_inst_addr                                                "0x0006"
#define  set_CRT_SYS_CLKEN2_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CLKEN2_reg)=data)
#define  get_CRT_SYS_CLKEN2_reg                                                  (*((volatile unsigned int*)CRT_SYS_CLKEN2_reg))
#define  CRT_SYS_CLKEN2_clken_tm_shift                                           (28)
#define  CRT_SYS_CLKEN2_clken_atvin_vd_shift                                     (27)
#define  CRT_SYS_CLKEN2_clken_atvin_ifd_shift                                    (26)
#define  CRT_SYS_CLKEN2_dummy1_shift                                              (24)
#define  CRT_SYS_CLKEN2_clken_emmc_shift                                         (23)
#define  CRT_SYS_CLKEN2_clken_efuse_shift                                        (22)
#define  CRT_SYS_CLKEN2_clken_bistreg_shift                                      (21)
#define  CRT_SYS_CLKEN2_clken_usb_shift                                          (18)
#define  CRT_SYS_CLKEN2_clken_otg_shift                                          (17)
#define  CRT_SYS_CLKEN2_clken_audio2_512fs_shift                                 (15)
#define  CRT_SYS_CLKEN2_dummy2_shift                                              (14)
#define  CRT_SYS_CLKEN2_clken_irtx_shift                                         (13)
#define  CRT_SYS_CLKEN2_clken_padmux_shift                                       (12)
#define  CRT_SYS_CLKEN2_clken_dtv_demod_shift                                    (11)
#define  CRT_SYS_CLKEN2_clken_misc_shift                                         (10)
#define  CRT_SYS_CLKEN2_clken_pwm_shift                                          (9)
#define  CRT_SYS_CLKEN2_clken_uart1_shift                                        (8)
#define  CRT_SYS_CLKEN2_clken_uart2_shift                                        (7)
#define  CRT_SYS_CLKEN2_clken_sc1_shift                                          (6)
#define  CRT_SYS_CLKEN2_clken_gpio_shift                                         (5)
#define  CRT_SYS_CLKEN2_clken_i2c1_shift                                         (4)
#define  CRT_SYS_CLKEN2_clken_i2c2_shift                                         (3)
#define  CRT_SYS_CLKEN2_clken_nf_shift                                           (2)
#define  CRT_SYS_CLKEN2_clken_sc_shift                                           (1)
#define  CRT_SYS_CLKEN2_clken_pc_shift                                           (0)
#define  CRT_SYS_CLKEN2_clken_tm_mask                                            (0x10000000)
#define  CRT_SYS_CLKEN2_clken_atvin_vd_mask                                      (0x08000000)
#define  CRT_SYS_CLKEN2_clken_atvin_ifd_mask                                     (0x04000000)
#define  CRT_SYS_CLKEN2_dummy1_mask                                               (0x03000000)
#define  CRT_SYS_CLKEN2_clken_emmc_mask                                          (0x00800000)
#define  CRT_SYS_CLKEN2_clken_efuse_mask                                         (0x00400000)
#define  CRT_SYS_CLKEN2_clken_bistreg_mask                                       (0x00200000)
#define  CRT_SYS_CLKEN2_clken_usb_mask                                           (0x00040000)
#define  CRT_SYS_CLKEN2_clken_otg_mask                                           (0x00020000)
#define  CRT_SYS_CLKEN2_clken_audio2_512fs_mask                                  (0x00008000)
#define  CRT_SYS_CLKEN2_dummy2_mask                                               (0x00004000)
#define  CRT_SYS_CLKEN2_clken_irtx_mask                                          (0x00002000)
#define  CRT_SYS_CLKEN2_clken_padmux_mask                                        (0x00001000)
#define  CRT_SYS_CLKEN2_clken_dtv_demod_mask                                     (0x00000800)
#define  CRT_SYS_CLKEN2_clken_misc_mask                                          (0x00000400)
#define  CRT_SYS_CLKEN2_clken_pwm_mask                                           (0x00000200)
#define  CRT_SYS_CLKEN2_clken_uart1_mask                                         (0x00000100)
#define  CRT_SYS_CLKEN2_clken_uart2_mask                                         (0x00000080)
#define  CRT_SYS_CLKEN2_clken_sc1_mask                                           (0x00000040)
#define  CRT_SYS_CLKEN2_clken_gpio_mask                                          (0x00000020)
#define  CRT_SYS_CLKEN2_clken_i2c1_mask                                          (0x00000010)
#define  CRT_SYS_CLKEN2_clken_i2c2_mask                                          (0x00000008)
#define  CRT_SYS_CLKEN2_clken_nf_mask                                            (0x00000004)
#define  CRT_SYS_CLKEN2_clken_sc_mask                                            (0x00000002)
#define  CRT_SYS_CLKEN2_clken_pc_mask                                            (0x00000001)
#define  CRT_SYS_CLKEN2_clken_tm(data)                                           (0x10000000&((data)<<28))
#define  CRT_SYS_CLKEN2_clken_atvin_vd(data)                                     (0x08000000&((data)<<27))
#define  CRT_SYS_CLKEN2_clken_atvin_ifd(data)                                    (0x04000000&((data)<<26))
#define  CRT_SYS_CLKEN2_dummy1(data)                                              (0x03000000&((data)<<24))
#define  CRT_SYS_CLKEN2_clken_emmc(data)                                         (0x00800000&((data)<<23))
#define  CRT_SYS_CLKEN2_clken_efuse(data)                                        (0x00400000&((data)<<22))
#define  CRT_SYS_CLKEN2_clken_bistreg(data)                                      (0x00200000&((data)<<21))
#define  CRT_SYS_CLKEN2_clken_usb(data)                                          (0x00040000&((data)<<18))
#define  CRT_SYS_CLKEN2_clken_otg(data)                                          (0x00020000&((data)<<17))
#define  CRT_SYS_CLKEN2_clken_audio2_512fs(data)                                 (0x00008000&((data)<<15))
#define  CRT_SYS_CLKEN2_dummy2(data)                                              (0x00004000&((data)<<14))
#define  CRT_SYS_CLKEN2_clken_irtx(data)                                         (0x00002000&((data)<<13))
#define  CRT_SYS_CLKEN2_clken_padmux(data)                                       (0x00001000&((data)<<12))
#define  CRT_SYS_CLKEN2_clken_dtv_demod(data)                                    (0x00000800&((data)<<11))
#define  CRT_SYS_CLKEN2_clken_misc(data)                                         (0x00000400&((data)<<10))
#define  CRT_SYS_CLKEN2_clken_pwm(data)                                          (0x00000200&((data)<<9))
#define  CRT_SYS_CLKEN2_clken_uart1(data)                                        (0x00000100&((data)<<8))
#define  CRT_SYS_CLKEN2_clken_uart2(data)                                        (0x00000080&((data)<<7))
#define  CRT_SYS_CLKEN2_clken_sc1(data)                                          (0x00000040&((data)<<6))
#define  CRT_SYS_CLKEN2_clken_gpio(data)                                         (0x00000020&((data)<<5))
#define  CRT_SYS_CLKEN2_clken_i2c1(data)                                         (0x00000010&((data)<<4))
#define  CRT_SYS_CLKEN2_clken_i2c2(data)                                         (0x00000008&((data)<<3))
#define  CRT_SYS_CLKEN2_clken_nf(data)                                           (0x00000004&((data)<<2))
#define  CRT_SYS_CLKEN2_clken_sc(data)                                           (0x00000002&((data)<<1))
#define  CRT_SYS_CLKEN2_clken_pc(data)                                           (0x00000001&(data))
#define  CRT_SYS_CLKEN2_get_clken_tm(data)                                       ((0x10000000&(data))>>28)
#define  CRT_SYS_CLKEN2_get_clken_atvin_vd(data)                                 ((0x08000000&(data))>>27)
#define  CRT_SYS_CLKEN2_get_clken_atvin_ifd(data)                                ((0x04000000&(data))>>26)
#define  CRT_SYS_CLKEN2_get_dummy1(data)                                          ((0x03000000&(data))>>24)
#define  CRT_SYS_CLKEN2_get_clken_emmc(data)                                     ((0x00800000&(data))>>23)
#define  CRT_SYS_CLKEN2_get_clken_efuse(data)                                    ((0x00400000&(data))>>22)
#define  CRT_SYS_CLKEN2_get_clken_bistreg(data)                                  ((0x00200000&(data))>>21)
#define  CRT_SYS_CLKEN2_get_clken_usb(data)                                      ((0x00040000&(data))>>18)
#define  CRT_SYS_CLKEN2_get_clken_otg(data)                                      ((0x00020000&(data))>>17)
#define  CRT_SYS_CLKEN2_get_clken_audio2_512fs(data)                             ((0x00008000&(data))>>15)
#define  CRT_SYS_CLKEN2_get_dummy2(data)                                          ((0x00004000&(data))>>14)
#define  CRT_SYS_CLKEN2_get_clken_irtx(data)                                     ((0x00002000&(data))>>13)
#define  CRT_SYS_CLKEN2_get_clken_padmux(data)                                   ((0x00001000&(data))>>12)
#define  CRT_SYS_CLKEN2_get_clken_dtv_demod(data)                                ((0x00000800&(data))>>11)
#define  CRT_SYS_CLKEN2_get_clken_misc(data)                                     ((0x00000400&(data))>>10)
#define  CRT_SYS_CLKEN2_get_clken_pwm(data)                                      ((0x00000200&(data))>>9)
#define  CRT_SYS_CLKEN2_get_clken_uart1(data)                                    ((0x00000100&(data))>>8)
#define  CRT_SYS_CLKEN2_get_clken_uart2(data)                                    ((0x00000080&(data))>>7)
#define  CRT_SYS_CLKEN2_get_clken_sc1(data)                                      ((0x00000040&(data))>>6)
#define  CRT_SYS_CLKEN2_get_clken_gpio(data)                                     ((0x00000020&(data))>>5)
#define  CRT_SYS_CLKEN2_get_clken_i2c1(data)                                     ((0x00000010&(data))>>4)
#define  CRT_SYS_CLKEN2_get_clken_i2c2(data)                                     ((0x00000008&(data))>>3)
#define  CRT_SYS_CLKEN2_get_clken_nf(data)                                       ((0x00000004&(data))>>2)
#define  CRT_SYS_CLKEN2_get_clken_sc(data)                                       ((0x00000002&(data))>>1)
#define  CRT_SYS_CLKEN2_get_clken_pc(data)                                       (0x00000001&(data))

#define  CRT_SYS_CLKEN3                                                          0x1800011C
#define  CRT_SYS_CLKEN3_reg_addr                                                 "0xB800011C"
#define  CRT_SYS_CLKEN3_reg                                                      0xB800011C
#define  CRT_SYS_CLKEN3_inst_addr                                                "0x0007"
#define  set_CRT_SYS_CLKEN3_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CLKEN3_reg)=data)
#define  get_CRT_SYS_CLKEN3_reg                                                  (*((volatile unsigned int*)CRT_SYS_CLKEN3_reg))
#define  CRT_SYS_CLKEN3_clken_dcphy2_shift                                       (25)
#define  CRT_SYS_CLKEN3_clken_dcu2_shift                                         (24)
#define  CRT_SYS_CLKEN3_clken_ddc_shift                                          (17)
#define  CRT_SYS_CLKEN3_clken_sd_shift                                           (16)
#define  CRT_SYS_CLKEN3_clken_audio2_dma_r_512fs_shift                           (7)
#define  CRT_SYS_CLKEN3_clken_audio_dma_r_512fs_shift                            (6)
#define  CRT_SYS_CLKEN3_clken_audio_da1_256fs_shift                              (5)
#define  CRT_SYS_CLKEN3_clken_audio_da1_128fs_shift                              (4)
#define  CRT_SYS_CLKEN3_clken_audio_da0_256fs_shift                              (3)
#define  CRT_SYS_CLKEN3_clken_audio_da0_128fs_shift                              (2)
#define  CRT_SYS_CLKEN3_clken_audio_ad_256fs_shift                               (1)
#define  CRT_SYS_CLKEN3_clken_audio_ad_128fs_shift                               (0)
#define  CRT_SYS_CLKEN3_clken_dcphy2_mask                                        (0x02000000)
#define  CRT_SYS_CLKEN3_clken_dcu2_mask                                          (0x01000000)
#define  CRT_SYS_CLKEN3_clken_ddc_mask                                           (0x00020000)
#define  CRT_SYS_CLKEN3_clken_sd_mask                                            (0x00010000)
#define  CRT_SYS_CLKEN3_clken_audio2_dma_r_512fs_mask                            (0x00000080)
#define  CRT_SYS_CLKEN3_clken_audio_dma_r_512fs_mask                             (0x00000040)
#define  CRT_SYS_CLKEN3_clken_audio_da1_256fs_mask                               (0x00000020)
#define  CRT_SYS_CLKEN3_clken_audio_da1_128fs_mask                               (0x00000010)
#define  CRT_SYS_CLKEN3_clken_audio_da0_256fs_mask                               (0x00000008)
#define  CRT_SYS_CLKEN3_clken_audio_da0_128fs_mask                               (0x00000004)
#define  CRT_SYS_CLKEN3_clken_audio_ad_256fs_mask                                (0x00000002)
#define  CRT_SYS_CLKEN3_clken_audio_ad_128fs_mask                                (0x00000001)
#define  CRT_SYS_CLKEN3_clken_dcphy2(data)                                       (0x02000000&((data)<<25))
#define  CRT_SYS_CLKEN3_clken_dcu2(data)                                         (0x01000000&((data)<<24))
#define  CRT_SYS_CLKEN3_clken_ddc(data)                                          (0x00020000&((data)<<17))
#define  CRT_SYS_CLKEN3_clken_sd(data)                                           (0x00010000&((data)<<16))
#define  CRT_SYS_CLKEN3_clken_audio2_dma_r_512fs(data)                           (0x00000080&((data)<<7))
#define  CRT_SYS_CLKEN3_clken_audio_dma_r_512fs(data)                            (0x00000040&((data)<<6))
#define  CRT_SYS_CLKEN3_clken_audio_da1_256fs(data)                              (0x00000020&((data)<<5))
#define  CRT_SYS_CLKEN3_clken_audio_da1_128fs(data)                              (0x00000010&((data)<<4))
#define  CRT_SYS_CLKEN3_clken_audio_da0_256fs(data)                              (0x00000008&((data)<<3))
#define  CRT_SYS_CLKEN3_clken_audio_da0_128fs(data)                              (0x00000004&((data)<<2))
#define  CRT_SYS_CLKEN3_clken_audio_ad_256fs(data)                               (0x00000002&((data)<<1))
#define  CRT_SYS_CLKEN3_clken_audio_ad_128fs(data)                               (0x00000001&(data))
#define  CRT_SYS_CLKEN3_get_clken_dcphy2(data)                                   ((0x02000000&(data))>>25)
#define  CRT_SYS_CLKEN3_get_clken_dcu2(data)                                     ((0x01000000&(data))>>24)
#define  CRT_SYS_CLKEN3_get_clken_ddc(data)                                      ((0x00020000&(data))>>17)
#define  CRT_SYS_CLKEN3_get_clken_sd(data)                                       ((0x00010000&(data))>>16)
#define  CRT_SYS_CLKEN3_get_clken_audio2_dma_r_512fs(data)                       ((0x00000080&(data))>>7)
#define  CRT_SYS_CLKEN3_get_clken_audio_dma_r_512fs(data)                        ((0x00000040&(data))>>6)
#define  CRT_SYS_CLKEN3_get_clken_audio_da1_256fs(data)                          ((0x00000020&(data))>>5)
#define  CRT_SYS_CLKEN3_get_clken_audio_da1_128fs(data)                          ((0x00000010&(data))>>4)
#define  CRT_SYS_CLKEN3_get_clken_audio_da0_256fs(data)                          ((0x00000008&(data))>>3)
#define  CRT_SYS_CLKEN3_get_clken_audio_da0_128fs(data)                          ((0x00000004&(data))>>2)
#define  CRT_SYS_CLKEN3_get_clken_audio_ad_256fs(data)                           ((0x00000002&(data))>>1)
#define  CRT_SYS_CLKEN3_get_clken_audio_ad_128fs(data)                           (0x00000001&(data))

#define  CRT_SYS_CPUSEL                                                          0x18000200
#define  CRT_SYS_CPUSEL_reg_addr                                                 "0xB8000200"
#define  CRT_SYS_CPUSEL_reg                                                      0xB8000200
#define  CRT_SYS_CPUSEL_inst_addr                                                "0x0008"
#define  set_CRT_SYS_CPUSEL_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CPUSEL_reg)=data)
#define  get_CRT_SYS_CPUSEL_reg                                                  (*((volatile unsigned int*)CRT_SYS_CPUSEL_reg))
#define  CRT_SYS_CPUSEL_ejtag_mode_shift                                         (4)
#define  CRT_SYS_CPUSEL_kcpu_clksel_shift                                        (0)
#define  CRT_SYS_CPUSEL_ejtag_mode_mask                                          (0x00000010)
#define  CRT_SYS_CPUSEL_kcpu_clksel_mask                                         (0x00000001)
#define  CRT_SYS_CPUSEL_ejtag_mode(data)                                         (0x00000010&((data)<<4))
#define  CRT_SYS_CPUSEL_kcpu_clksel(data)                                        (0x00000001&(data))
#define  CRT_SYS_CPUSEL_get_ejtag_mode(data)                                     ((0x00000010&(data))>>4)
#define  CRT_SYS_CPUSEL_get_kcpu_clksel(data)                                    (0x00000001&(data))

#define  CRT_SYS_CLKSEL                                                          0x18000204
#define  CRT_SYS_CLKSEL_reg_addr                                                 "0xB8000204"
#define  CRT_SYS_CLKSEL_reg                                                      0xB8000204
#define  CRT_SYS_CLKSEL_inst_addr                                                "0x0009"
#define  set_CRT_SYS_CLKSEL_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CLKSEL_reg)=data)
#define  get_CRT_SYS_CLKSEL_reg                                                  (*((volatile unsigned int*)CRT_SYS_CLKSEL_reg))
#define  CRT_SYS_CLKSEL_pll_bypass_ref_clk_mode_shift                            (31)
#define  CRT_SYS_CLKSEL_dtv_rbus_i2c_sel_shift                                   (30)
#define  CRT_SYS_CLKSEL_sd_emmc_clk_sel_shift                                    (27)
#define  CRT_SYS_CLKSEL_pcr108_clksel_shift                                      (26)
#define  CRT_SYS_CLKSEL_epi_dbg_clksel_shift                                     (25)
#define  CRT_SYS_CLKSEL_dpll_clksel_shift                                        (23)
#define  CRT_SYS_CLKSEL_sd_clk_div_shift                                         (20)
#define  CRT_SYS_CLKSEL_ve_rif_use_p2clk_shift                                   (19)
#define  CRT_SYS_CLKSEL_ve2_rif_use_p2clk_shift                                  (18)
#define  CRT_SYS_CLKSEL_atvin_clk_sel_shift                                      (17)
#define  CRT_SYS_CLKSEL_atvin_vd_clk_sel_shift                                   (16)
#define  CRT_SYS_CLKSEL_atvin_vdadc_tve_clk_sel_shift                            (15)
#define  CRT_SYS_CLKSEL_tve_108m_clk_sel_shift                                   (13)
#define  CRT_SYS_CLKSEL_cbus_clksel_shift                                        (12)
#define  CRT_SYS_CLKSEL_tp_post_div_shift                                        (8)
#define  CRT_SYS_CLKSEL_tp_pre_div_shift                                         (4)
#define  CRT_SYS_CLKSEL_vdec_x27_clksel_shift                                    (3)
#define  CRT_SYS_CLKSEL_vbis0_yppsel_shift                                       (2)
#define  CRT_SYS_CLKSEL_inv_vbis0_clk_shift                                      (1)
#define  CRT_SYS_CLKSEL_uart_clksel_shift                                        (0)
#define  CRT_SYS_CLKSEL_pll_bypass_ref_clk_mode_mask                             (0x80000000)
#define  CRT_SYS_CLKSEL_dtv_rbus_i2c_sel_mask                                    (0x40000000)
#define  CRT_SYS_CLKSEL_sd_emmc_clk_sel_mask                                     (0x18000000)
#define  CRT_SYS_CLKSEL_pcr108_clksel_mask                                       (0x04000000)
#define  CRT_SYS_CLKSEL_epi_dbg_clksel_mask                                      (0x02000000)
#define  CRT_SYS_CLKSEL_dpll_clksel_mask                                         (0x01800000)
#define  CRT_SYS_CLKSEL_sd_clk_div_mask                                          (0x00700000)
#define  CRT_SYS_CLKSEL_ve_rif_use_p2clk_mask                                    (0x00080000)
#define  CRT_SYS_CLKSEL_ve2_rif_use_p2clk_mask                                   (0x00040000)
#define  CRT_SYS_CLKSEL_atvin_clk_sel_mask                                       (0x00020000)
#define  CRT_SYS_CLKSEL_atvin_vd_clk_sel_mask                                    (0x00010000)
#define  CRT_SYS_CLKSEL_atvin_vdadc_tve_clk_sel_mask                             (0x00008000)
#define  CRT_SYS_CLKSEL_tve_108m_clk_sel_mask                                    (0x00002000)
#define  CRT_SYS_CLKSEL_cbus_clksel_mask                                         (0x00001000)
#define  CRT_SYS_CLKSEL_tp_post_div_mask                                         (0x00000F00)
#define  CRT_SYS_CLKSEL_tp_pre_div_mask                                          (0x000000F0)
#define  CRT_SYS_CLKSEL_vdec_x27_clksel_mask                                     (0x00000008)
#define  CRT_SYS_CLKSEL_vbis0_yppsel_mask                                        (0x00000004)
#define  CRT_SYS_CLKSEL_inv_vbis0_clk_mask                                       (0x00000002)
#define  CRT_SYS_CLKSEL_uart_clksel_mask                                         (0x00000001)
#define  CRT_SYS_CLKSEL_pll_bypass_ref_clk_mode(data)                            (0x80000000&((data)<<31))
#define  CRT_SYS_CLKSEL_dtv_rbus_i2c_sel(data)                                   (0x40000000&((data)<<30))
#define  CRT_SYS_CLKSEL_sd_emmc_clk_sel(data)                                    (0x18000000&((data)<<27))
#define  CRT_SYS_CLKSEL_pcr108_clksel(data)                                      (0x04000000&((data)<<26))
#define  CRT_SYS_CLKSEL_epi_dbg_clksel(data)                                     (0x02000000&((data)<<25))
#define  CRT_SYS_CLKSEL_dpll_clksel(data)                                        (0x01800000&((data)<<23))
#define  CRT_SYS_CLKSEL_sd_clk_div(data)                                         (0x00700000&((data)<<20))
#define  CRT_SYS_CLKSEL_ve_rif_use_p2clk(data)                                   (0x00080000&((data)<<19))
#define  CRT_SYS_CLKSEL_ve2_rif_use_p2clk(data)                                  (0x00040000&((data)<<18))
#define  CRT_SYS_CLKSEL_atvin_clk_sel(data)                                      (0x00020000&((data)<<17))
#define  CRT_SYS_CLKSEL_atvin_vd_clk_sel(data)                                   (0x00010000&((data)<<16))
#define  CRT_SYS_CLKSEL_atvin_vdadc_tve_clk_sel(data)                            (0x00008000&((data)<<15))
#define  CRT_SYS_CLKSEL_tve_108m_clk_sel(data)                                   (0x00002000&((data)<<13))
#define  CRT_SYS_CLKSEL_cbus_clksel(data)                                        (0x00001000&((data)<<12))
#define  CRT_SYS_CLKSEL_tp_post_div(data)                                        (0x00000F00&((data)<<8))
#define  CRT_SYS_CLKSEL_tp_pre_div(data)                                         (0x000000F0&((data)<<4))
#define  CRT_SYS_CLKSEL_vdec_x27_clksel(data)                                    (0x00000008&((data)<<3))
#define  CRT_SYS_CLKSEL_vbis0_yppsel(data)                                       (0x00000004&((data)<<2))
#define  CRT_SYS_CLKSEL_inv_vbis0_clk(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_CLKSEL_uart_clksel(data)                                        (0x00000001&(data))
#define  CRT_SYS_CLKSEL_get_pll_bypass_ref_clk_mode(data)                        ((0x80000000&(data))>>31)
#define  CRT_SYS_CLKSEL_get_dtv_rbus_i2c_sel(data)                               ((0x40000000&(data))>>30)
#define  CRT_SYS_CLKSEL_get_sd_emmc_clk_sel(data)                                ((0x18000000&(data))>>27)
#define  CRT_SYS_CLKSEL_get_pcr108_clksel(data)                                  ((0x04000000&(data))>>26)
#define  CRT_SYS_CLKSEL_get_epi_dbg_clksel(data)                                 ((0x02000000&(data))>>25)
#define  CRT_SYS_CLKSEL_get_dpll_clksel(data)                                    ((0x01800000&(data))>>23)
#define  CRT_SYS_CLKSEL_get_sd_clk_div(data)                                     ((0x00700000&(data))>>20)
#define  CRT_SYS_CLKSEL_get_ve_rif_use_p2clk(data)                               ((0x00080000&(data))>>19)
#define  CRT_SYS_CLKSEL_get_ve2_rif_use_p2clk(data)                              ((0x00040000&(data))>>18)
#define  CRT_SYS_CLKSEL_get_atvin_clk_sel(data)                                  ((0x00020000&(data))>>17)
#define  CRT_SYS_CLKSEL_get_atvin_vd_clk_sel(data)                               ((0x00010000&(data))>>16)
#define  CRT_SYS_CLKSEL_get_atvin_vdadc_tve_clk_sel(data)                        ((0x00008000&(data))>>15)
#define  CRT_SYS_CLKSEL_get_tve_108m_clk_sel(data)                               ((0x00002000&(data))>>13)
#define  CRT_SYS_CLKSEL_get_cbus_clksel(data)                                    ((0x00001000&(data))>>12)
#define  CRT_SYS_CLKSEL_get_tp_post_div(data)                                    ((0x00000F00&(data))>>8)
#define  CRT_SYS_CLKSEL_get_tp_pre_div(data)                                     ((0x000000F0&(data))>>4)
#define  CRT_SYS_CLKSEL_get_vdec_x27_clksel(data)                                ((0x00000008&(data))>>3)
#define  CRT_SYS_CLKSEL_get_vbis0_yppsel(data)                                   ((0x00000004&(data))>>2)
#define  CRT_SYS_CLKSEL_get_inv_vbis0_clk(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_CLKSEL_get_uart_clksel(data)                                    (0x00000001&(data))

#define  CRT_SYS_DISPCLKSEL                                                      0x18000208
#define  CRT_SYS_DISPCLKSEL_reg_addr                                             "0xB8000208"
#define  CRT_SYS_DISPCLKSEL_reg                                                  0xB8000208
#define  CRT_SYS_DISPCLKSEL_inst_addr                                            "0x000A"
#define  set_CRT_SYS_DISPCLKSEL_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_DISPCLKSEL_reg)=data)
#define  get_CRT_SYS_DISPCLKSEL_reg                                              (*((volatile unsigned int*)CRT_SYS_DISPCLKSEL_reg))
#define  CRT_SYS_DISPCLKSEL_hdmitx_clksel_shift                                  (15)
#define  CRT_SYS_DISPCLKSEL_dispd_gdma_clk_sel_shift                             (14)
#define  CRT_SYS_DISPCLKSEL_dispd_video_div_shift                                (12)
#define  CRT_SYS_DISPCLKSEL_dummy_shift                                          (10)
#define  CRT_SYS_DISPCLKSEL_dispd_osd_div_shift                                  (8)
#define  CRT_SYS_DISPCLKSEL_clken_disp_sfg_shift                                 (4)
#define  CRT_SYS_DISPCLKSEL_clken_disp_gdma_shift                                (3)
#define  CRT_SYS_DISPCLKSEL_clken_disp_video_shift                               (2)
#define  CRT_SYS_DISPCLKSEL_clken_disp_osd_shift                                 (1)
#define  CRT_SYS_DISPCLKSEL_clken_disp_5k_shift                                  (0)
#define  CRT_SYS_DISPCLKSEL_hdmitx_clksel_mask                                   (0x00018000)
#define  CRT_SYS_DISPCLKSEL_dispd_gdma_clk_sel_mask                              (0x00004000)
#define  CRT_SYS_DISPCLKSEL_dispd_video_div_mask                                 (0x00003000)
#define  CRT_SYS_DISPCLKSEL_dummy_mask                                           (0x00000C00)
#define  CRT_SYS_DISPCLKSEL_dispd_osd_div_mask                                   (0x00000300)
#define  CRT_SYS_DISPCLKSEL_clken_disp_sfg_mask                                  (0x00000010)
#define  CRT_SYS_DISPCLKSEL_clken_disp_gdma_mask                                 (0x00000008)
#define  CRT_SYS_DISPCLKSEL_clken_disp_video_mask                                (0x00000004)
#define  CRT_SYS_DISPCLKSEL_clken_disp_osd_mask                                  (0x00000002)
#define  CRT_SYS_DISPCLKSEL_clken_disp_5k_mask                                   (0x00000001)
#define  CRT_SYS_DISPCLKSEL_hdmitx_clksel(data)                                  (0x00018000&((data)<<15))
#define  CRT_SYS_DISPCLKSEL_dispd_gdma_clk_sel(data)                             (0x00004000&((data)<<14))
#define  CRT_SYS_DISPCLKSEL_dispd_video_div(data)                                (0x00003000&((data)<<12))
#define  CRT_SYS_DISPCLKSEL_dummy(data)                                          (0x00000C00&((data)<<10))
#define  CRT_SYS_DISPCLKSEL_dispd_osd_div(data)                                  (0x00000300&((data)<<8))
#define  CRT_SYS_DISPCLKSEL_clken_disp_sfg(data)                                 (0x00000010&((data)<<4))
#define  CRT_SYS_DISPCLKSEL_clken_disp_gdma(data)                                (0x00000008&((data)<<3))
#define  CRT_SYS_DISPCLKSEL_clken_disp_video(data)                               (0x00000004&((data)<<2))
#define  CRT_SYS_DISPCLKSEL_clken_disp_osd(data)                                 (0x00000002&((data)<<1))
#define  CRT_SYS_DISPCLKSEL_clken_disp_5k(data)                                  (0x00000001&(data))
#define  CRT_SYS_DISPCLKSEL_get_hdmitx_clksel(data)                              ((0x00018000&(data))>>15)
#define  CRT_SYS_DISPCLKSEL_get_dispd_gdma_clk_sel(data)                         ((0x00004000&(data))>>14)
#define  CRT_SYS_DISPCLKSEL_get_dispd_video_div(data)                            ((0x00003000&(data))>>12)
#define  CRT_SYS_DISPCLKSEL_get_dummy(data)                                      ((0x00000C00&(data))>>10)
#define  CRT_SYS_DISPCLKSEL_get_dispd_osd_div(data)                              ((0x00000300&(data))>>8)
#define  CRT_SYS_DISPCLKSEL_get_clken_disp_sfg(data)                             ((0x00000010&(data))>>4)
#define  CRT_SYS_DISPCLKSEL_get_clken_disp_gdma(data)                            ((0x00000008&(data))>>3)
#define  CRT_SYS_DISPCLKSEL_get_clken_disp_video(data)                           ((0x00000004&(data))>>2)
#define  CRT_SYS_DISPCLKSEL_get_clken_disp_osd(data)                             ((0x00000002&(data))>>1)
#define  CRT_SYS_DISPCLKSEL_get_clken_disp_5k(data)                              (0x00000001&(data))

#define  CRT_SYS_CLKDIV                                                          0x18000214
#define  CRT_SYS_CLKDIV_reg_addr                                                 "0xB8000214"
#define  CRT_SYS_CLKDIV_reg                                                      0xB8000214
#define  CRT_SYS_CLKDIV_inst_addr                                                "0x000B"
#define  set_CRT_SYS_CLKDIV_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_CLKDIV_reg)=data)
#define  get_CRT_SYS_CLKDIV_reg                                                  (*((volatile unsigned int*)CRT_SYS_CLKDIV_reg))
#define  CRT_SYS_CLKDIV_hdmi_tmds_div_shift                                      (12)
#define  CRT_SYS_CLKDIV_nf_clksel_shift                                          (8)
#define  CRT_SYS_CLKDIV_dtv_demod_multi_req_disable_shift                        (7)
#define  CRT_SYS_CLKDIV_aud_dtv2_freq_sel_shift                                  (4)
#define  CRT_SYS_CLKDIV_demod_i2c_saddr_sel_shift                                (3)
#define  CRT_SYS_CLKDIV_aud_dtv_freq_sel_shift                                   (0)
#define  CRT_SYS_CLKDIV_hdmi_tmds_div_mask                                       (0x00003000)
#define  CRT_SYS_CLKDIV_nf_clksel_mask                                           (0x00000700)
#define  CRT_SYS_CLKDIV_dtv_demod_multi_req_disable_mask                         (0x00000080)
#define  CRT_SYS_CLKDIV_aud_dtv2_freq_sel_mask                                   (0x00000070)
#define  CRT_SYS_CLKDIV_demod_i2c_saddr_sel_mask                                 (0x00000008)
#define  CRT_SYS_CLKDIV_aud_dtv_freq_sel_mask                                    (0x00000007)
#define  CRT_SYS_CLKDIV_hdmi_tmds_div(data)                                      (0x00003000&((data)<<12))
#define  CRT_SYS_CLKDIV_nf_clksel(data)                                          (0x00000700&((data)<<8))
#define  CRT_SYS_CLKDIV_dtv_demod_multi_req_disable(data)                        (0x00000080&((data)<<7))
#define  CRT_SYS_CLKDIV_aud_dtv2_freq_sel(data)                                  (0x00000070&((data)<<4))
#define  CRT_SYS_CLKDIV_demod_i2c_saddr_sel(data)                                (0x00000008&((data)<<3))
#define  CRT_SYS_CLKDIV_aud_dtv_freq_sel(data)                                   (0x00000007&(data))
#define  CRT_SYS_CLKDIV_get_hdmi_tmds_div(data)                                  ((0x00003000&(data))>>12)
#define  CRT_SYS_CLKDIV_get_nf_clksel(data)                                      ((0x00000700&(data))>>8)
#define  CRT_SYS_CLKDIV_get_dtv_demod_multi_req_disable(data)                    ((0x00000080&(data))>>7)
#define  CRT_SYS_CLKDIV_get_aud_dtv2_freq_sel(data)                              ((0x00000070&(data))>>4)
#define  CRT_SYS_CLKDIV_get_demod_i2c_saddr_sel(data)                            ((0x00000008&(data))>>3)
#define  CRT_SYS_CLKDIV_get_aud_dtv_freq_sel(data)                               (0x00000007&(data))

#define  CRT_SYS_ARM_WD                                                          0x18000218
#define  CRT_SYS_ARM_WD_reg_addr                                                 "0xB8000218"
#define  CRT_SYS_ARM_WD_reg                                                      0xB8000218
#define  CRT_SYS_ARM_WD_inst_addr                                                "0x000C"
#define  set_CRT_SYS_ARM_WD_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_ARM_WD_reg)=data)
#define  get_CRT_SYS_ARM_WD_reg                                                  (*((volatile unsigned int*)CRT_SYS_ARM_WD_reg))
#define  CRT_SYS_ARM_WD_scpu_wd_en_shift                                         (16)
#define  CRT_SYS_ARM_WD_scpu_wd_cnt_shift                                        (0)
#define  CRT_SYS_ARM_WD_scpu_wd_en_mask                                          (0x00010000)
#define  CRT_SYS_ARM_WD_scpu_wd_cnt_mask                                         (0x00000FFF)
#define  CRT_SYS_ARM_WD_scpu_wd_en(data)                                         (0x00010000&((data)<<16))
#define  CRT_SYS_ARM_WD_scpu_wd_cnt(data)                                        (0x00000FFF&(data))
#define  CRT_SYS_ARM_WD_get_scpu_wd_en(data)                                     ((0x00010000&(data))>>16)
#define  CRT_SYS_ARM_WD_get_scpu_wd_cnt(data)                                    (0x00000FFF&(data))

#define  CRT_SYS_TVSB1                                                           0x1800021C
#define  CRT_SYS_TVSB1_reg_addr                                                  "0xB800021C"
#define  CRT_SYS_TVSB1_reg                                                       0xB800021C
#define  CRT_SYS_TVSB1_inst_addr                                                 "0x000D"
#define  set_CRT_SYS_TVSB1_reg(data)                                             (*((volatile unsigned int*)CRT_SYS_TVSB1_reg)=data)
#define  get_CRT_SYS_TVSB1_reg                                                   (*((volatile unsigned int*)CRT_SYS_TVSB1_reg))
#define  CRT_SYS_TVSB1_dummy_shift                                               (0)
#define  CRT_SYS_TVSB1_dummy_mask                                                (0xFFFFFFFF)
#define  CRT_SYS_TVSB1_dummy(data)                                               (0xFFFFFFFF&(data))
#define  CRT_SYS_TVSB1_get_dummy(data)                                           (0xFFFFFFFF&(data))

#define  CRT_SYS_DYN_SW_CPU                                                      0x18000220
#define  CRT_SYS_DYN_SW_CPU_reg_addr                                             "0xB8000220"
#define  CRT_SYS_DYN_SW_CPU_reg                                                  0xB8000220
#define  CRT_SYS_DYN_SW_CPU_inst_addr                                            "0x000E"
#define  set_CRT_SYS_DYN_SW_CPU_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_DYN_SW_CPU_reg)=data)
#define  get_CRT_SYS_DYN_SW_CPU_reg                                              (*((volatile unsigned int*)CRT_SYS_DYN_SW_CPU_reg))
#define  CRT_SYS_DYN_SW_CPU_clkratio_vcpu_shift                                  (20)
#define  CRT_SYS_DYN_SW_CPU_clkratio_vcpu_active_shift                           (16)
#define  CRT_SYS_DYN_SW_CPU_clkratio_acpu_shift                                  (12)
#define  CRT_SYS_DYN_SW_CPU_clkratio_acpu_active_shift                           (8)
#define  CRT_SYS_DYN_SW_CPU_clkratio_vcpu_mask                                   (0x00F00000)
#define  CRT_SYS_DYN_SW_CPU_clkratio_vcpu_active_mask                            (0x00010000)
#define  CRT_SYS_DYN_SW_CPU_clkratio_acpu_mask                                   (0x0000F000)
#define  CRT_SYS_DYN_SW_CPU_clkratio_acpu_active_mask                            (0x00000100)
#define  CRT_SYS_DYN_SW_CPU_clkratio_vcpu(data)                                  (0x00F00000&((data)<<20))
#define  CRT_SYS_DYN_SW_CPU_clkratio_vcpu_active(data)                           (0x00010000&((data)<<16))
#define  CRT_SYS_DYN_SW_CPU_clkratio_acpu(data)                                  (0x0000F000&((data)<<12))
#define  CRT_SYS_DYN_SW_CPU_clkratio_acpu_active(data)                           (0x00000100&((data)<<8))
#define  CRT_SYS_DYN_SW_CPU_get_clkratio_vcpu(data)                              ((0x00F00000&(data))>>20)
#define  CRT_SYS_DYN_SW_CPU_get_clkratio_vcpu_active(data)                       ((0x00010000&(data))>>16)
#define  CRT_SYS_DYN_SW_CPU_get_clkratio_acpu(data)                              ((0x0000F000&(data))>>12)
#define  CRT_SYS_DYN_SW_CPU_get_clkratio_acpu_active(data)                       ((0x00000100&(data))>>8)

#define  CRT_EFUSE_CTRL0                                                         0x18000240
#define  CRT_EFUSE_CTRL0_reg_addr                                                "0xB8000240"
#define  CRT_EFUSE_CTRL0_reg                                                     0xB8000240
#define  CRT_EFUSE_CTRL0_inst_addr                                               "0x000F"
#define  set_CRT_EFUSE_CTRL0_reg(data)                                           (*((volatile unsigned int*)CRT_EFUSE_CTRL0_reg)=data)
#define  get_CRT_EFUSE_CTRL0_reg                                                 (*((volatile unsigned int*)CRT_EFUSE_CTRL0_reg))
#define  CRT_EFUSE_CTRL0_efuse_ready_shift                                       (0)
#define  CRT_EFUSE_CTRL0_efuse_ready_mask                                        (0x00000001)
#define  CRT_EFUSE_CTRL0_efuse_ready(data)                                       (0x00000001&(data))
#define  CRT_EFUSE_CTRL0_get_efuse_ready(data)                                   (0x00000001&(data))

#define  CRT_POWER_CTRL0                                                         0x18000260
#define  CRT_POWER_CTRL0_reg_addr                                                "0xB8000260"
#define  CRT_POWER_CTRL0_reg                                                     0xB8000260
#define  CRT_POWER_CTRL0_inst_addr                                               "0x0010"
#define  set_CRT_POWER_CTRL0_reg(data)                                           (*((volatile unsigned int*)CRT_POWER_CTRL0_reg)=data)
#define  get_CRT_POWER_CTRL0_reg                                                 (*((volatile unsigned int*)CRT_POWER_CTRL0_reg))
#define  CRT_POWER_CTRL0_atv_iso_en_shift                                        (12)
#define  CRT_POWER_CTRL0_atv_str_status_shift                                    (10)
#define  CRT_POWER_CTRL0_atv_str_pow_shift                                       (8)
#define  CRT_POWER_CTRL0_dtv_iso_en_shift                                        (4)
#define  CRT_POWER_CTRL0_dtv_str_status_shift                                    (2)
#define  CRT_POWER_CTRL0_dtv_str_pow_shift                                       (0)
#define  CRT_POWER_CTRL0_atv_iso_en_mask                                         (0x00001000)
#define  CRT_POWER_CTRL0_atv_str_status_mask                                     (0x00000400)
#define  CRT_POWER_CTRL0_atv_str_pow_mask                                        (0x00000100)
#define  CRT_POWER_CTRL0_dtv_iso_en_mask                                         (0x00000010)
#define  CRT_POWER_CTRL0_dtv_str_status_mask                                     (0x00000004)
#define  CRT_POWER_CTRL0_dtv_str_pow_mask                                        (0x00000001)
#define  CRT_POWER_CTRL0_atv_iso_en(data)                                        (0x00001000&((data)<<12))
#define  CRT_POWER_CTRL0_atv_str_status(data)                                    (0x00000400&((data)<<10))
#define  CRT_POWER_CTRL0_atv_str_pow(data)                                       (0x00000100&((data)<<8))
#define  CRT_POWER_CTRL0_dtv_iso_en(data)                                        (0x00000010&((data)<<4))
#define  CRT_POWER_CTRL0_dtv_str_status(data)                                    (0x00000004&((data)<<2))
#define  CRT_POWER_CTRL0_dtv_str_pow(data)                                       (0x00000001&(data))
#define  CRT_POWER_CTRL0_get_atv_iso_en(data)                                    ((0x00001000&(data))>>12)
#define  CRT_POWER_CTRL0_get_atv_str_status(data)                                ((0x00000400&(data))>>10)
#define  CRT_POWER_CTRL0_get_atv_str_pow(data)                                   ((0x00000100&(data))>>8)
#define  CRT_POWER_CTRL0_get_dtv_iso_en(data)                                    ((0x00000010&(data))>>4)
#define  CRT_POWER_CTRL0_get_dtv_str_status(data)                                ((0x00000004&(data))>>2)
#define  CRT_POWER_CTRL0_get_dtv_str_pow(data)                                   (0x00000001&(data))

#define  CRT_TEMP_SENSOR_1                                                       0x18000380
#define  CRT_TEMP_SENSOR_1_reg_addr                                              "0xB8000380"
#define  CRT_TEMP_SENSOR_1_reg                                                   0xB8000380
#define  CRT_TEMP_SENSOR_1_inst_addr                                             "0x0011"
#define  set_CRT_TEMP_SENSOR_1_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_1_reg)=data)
#define  get_CRT_TEMP_SENSOR_1_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_1_reg))
#define  CRT_TEMP_SENSOR_1_tm_a_shift                                            (0)
#define  CRT_TEMP_SENSOR_1_tm_a_mask                                             (0x1FFFFFFF)
#define  CRT_TEMP_SENSOR_1_tm_a(data)                                            (0x1FFFFFFF&(data))
#define  CRT_TEMP_SENSOR_1_get_tm_a(data)                                        (0x1FFFFFFF&(data))

#define  CRT_TEMP_SENSOR_2                                                       0x18000384
#define  CRT_TEMP_SENSOR_2_reg_addr                                              "0xB8000384"
#define  CRT_TEMP_SENSOR_2_reg                                                   0xB8000384
#define  CRT_TEMP_SENSOR_2_inst_addr                                             "0x0012"
#define  set_CRT_TEMP_SENSOR_2_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_2_reg)=data)
#define  get_CRT_TEMP_SENSOR_2_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_2_reg))
#define  CRT_TEMP_SENSOR_2_tm_b_shift                                            (10)
#define  CRT_TEMP_SENSOR_2_tm_adccksel_shift                                     (7)
#define  CRT_TEMP_SENSOR_2_tm_cal_en_shift                                       (6)
#define  CRT_TEMP_SENSOR_2_tm_biaschop_shift                                     (5)
#define  CRT_TEMP_SENSOR_2_tm_chopen_shift                                       (4)
#define  CRT_TEMP_SENSOR_2_tm_cksourcesel_shift                                  (3)
#define  CRT_TEMP_SENSOR_2_tm_dsr_shift                                          (0)
#define  CRT_TEMP_SENSOR_2_tm_b_mask                                             (0xFFFFFC00)
#define  CRT_TEMP_SENSOR_2_tm_adccksel_mask                                      (0x00000380)
#define  CRT_TEMP_SENSOR_2_tm_cal_en_mask                                        (0x00000040)
#define  CRT_TEMP_SENSOR_2_tm_biaschop_mask                                      (0x00000020)
#define  CRT_TEMP_SENSOR_2_tm_chopen_mask                                        (0x00000010)
#define  CRT_TEMP_SENSOR_2_tm_cksourcesel_mask                                   (0x00000008)
#define  CRT_TEMP_SENSOR_2_tm_dsr_mask                                           (0x00000007)
#define  CRT_TEMP_SENSOR_2_tm_b(data)                                            (0xFFFFFC00&((data)<<10))
#define  CRT_TEMP_SENSOR_2_tm_adccksel(data)                                     (0x00000380&((data)<<7))
#define  CRT_TEMP_SENSOR_2_tm_cal_en(data)                                       (0x00000040&((data)<<6))
#define  CRT_TEMP_SENSOR_2_tm_biaschop(data)                                     (0x00000020&((data)<<5))
#define  CRT_TEMP_SENSOR_2_tm_chopen(data)                                       (0x00000010&((data)<<4))
#define  CRT_TEMP_SENSOR_2_tm_cksourcesel(data)                                  (0x00000008&((data)<<3))
#define  CRT_TEMP_SENSOR_2_tm_dsr(data)                                          (0x00000007&(data))
#define  CRT_TEMP_SENSOR_2_get_tm_b(data)                                        ((0xFFFFFC00&(data))>>10)
#define  CRT_TEMP_SENSOR_2_get_tm_adccksel(data)                                 ((0x00000380&(data))>>7)
#define  CRT_TEMP_SENSOR_2_get_tm_cal_en(data)                                   ((0x00000040&(data))>>6)
#define  CRT_TEMP_SENSOR_2_get_tm_biaschop(data)                                 ((0x00000020&(data))>>5)
#define  CRT_TEMP_SENSOR_2_get_tm_chopen(data)                                   ((0x00000010&(data))>>4)
#define  CRT_TEMP_SENSOR_2_get_tm_cksourcesel(data)                              ((0x00000008&(data))>>3)
#define  CRT_TEMP_SENSOR_2_get_tm_dsr(data)                                      (0x00000007&(data))

#define  CRT_TEMP_SENSOR_3                                                       0x18000388
#define  CRT_TEMP_SENSOR_3_reg_addr                                              "0xB8000388"
#define  CRT_TEMP_SENSOR_3_reg                                                   0xB8000388
#define  CRT_TEMP_SENSOR_3_inst_addr                                             "0x0013"
#define  set_CRT_TEMP_SENSOR_3_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_3_reg)=data)
#define  get_CRT_TEMP_SENSOR_3_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_3_reg))
#define  CRT_TEMP_SENSOR_3_tm_en_chop_shift                                      (31)
#define  CRT_TEMP_SENSOR_3_tm_filteredgesel_shift                                (30)
#define  CRT_TEMP_SENSOR_3_tm_hold_en_shift                                      (29)
#define  CRT_TEMP_SENSOR_3_tm_order3_shift                                       (28)
#define  CRT_TEMP_SENSOR_3_tm_offset_shift                                       (6)
#define  CRT_TEMP_SENSOR_3_tm_pow_shift                                          (5)
#define  CRT_TEMP_SENSOR_3_tm_en_chop_mask                                       (0x80000000)
#define  CRT_TEMP_SENSOR_3_tm_filteredgesel_mask                                 (0x40000000)
#define  CRT_TEMP_SENSOR_3_tm_hold_en_mask                                       (0x20000000)
#define  CRT_TEMP_SENSOR_3_tm_order3_mask                                        (0x10000000)
#define  CRT_TEMP_SENSOR_3_tm_offset_mask                                        (0x0FFFFFC0)
#define  CRT_TEMP_SENSOR_3_tm_pow_mask                                           (0x00000020)
#define  CRT_TEMP_SENSOR_3_tm_en_chop(data)                                      (0x80000000&((data)<<31))
#define  CRT_TEMP_SENSOR_3_tm_filteredgesel(data)                                (0x40000000&((data)<<30))
#define  CRT_TEMP_SENSOR_3_tm_hold_en(data)                                      (0x20000000&((data)<<29))
#define  CRT_TEMP_SENSOR_3_tm_order3(data)                                       (0x10000000&((data)<<28))
#define  CRT_TEMP_SENSOR_3_tm_offset(data)                                       (0x0FFFFFC0&((data)<<6))
#define  CRT_TEMP_SENSOR_3_tm_pow(data)                                          (0x00000020&((data)<<5))
#define  CRT_TEMP_SENSOR_3_get_tm_en_chop(data)                                  ((0x80000000&(data))>>31)
#define  CRT_TEMP_SENSOR_3_get_tm_filteredgesel(data)                            ((0x40000000&(data))>>30)
#define  CRT_TEMP_SENSOR_3_get_tm_hold_en(data)                                  ((0x20000000&(data))>>29)
#define  CRT_TEMP_SENSOR_3_get_tm_order3(data)                                   ((0x10000000&(data))>>28)
#define  CRT_TEMP_SENSOR_3_get_tm_offset(data)                                   ((0x0FFFFFC0&(data))>>6)
#define  CRT_TEMP_SENSOR_3_get_tm_pow(data)                                      ((0x00000020&(data))>>5)

#define  CRT_TEMP_SENSOR_4                                                       0x1800038C
#define  CRT_TEMP_SENSOR_4_reg_addr                                              "0xB800038C"
#define  CRT_TEMP_SENSOR_4_reg                                                   0xB800038C
#define  CRT_TEMP_SENSOR_4_inst_addr                                             "0x0014"
#define  set_CRT_TEMP_SENSOR_4_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_4_reg)=data)
#define  get_CRT_TEMP_SENSOR_4_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_4_reg))
#define  CRT_TEMP_SENSOR_4_tm_r_shift                                            (8)
#define  CRT_TEMP_SENSOR_4_tm_opcursel_shift                                     (6)
#define  CRT_TEMP_SENSOR_4_tm_hold_dly_shift                                     (4)
#define  CRT_TEMP_SENSOR_4_tm_osccursel_shift                                    (2)
#define  CRT_TEMP_SENSOR_4_tm_resol_shift                                        (0)
#define  CRT_TEMP_SENSOR_4_tm_r_mask                                             (0xFFFFFF00)
#define  CRT_TEMP_SENSOR_4_tm_opcursel_mask                                      (0x000000C0)
#define  CRT_TEMP_SENSOR_4_tm_hold_dly_mask                                      (0x00000030)
#define  CRT_TEMP_SENSOR_4_tm_osccursel_mask                                     (0x0000000C)
#define  CRT_TEMP_SENSOR_4_tm_resol_mask                                         (0x00000003)
#define  CRT_TEMP_SENSOR_4_tm_r(data)                                            (0xFFFFFF00&((data)<<8))
#define  CRT_TEMP_SENSOR_4_tm_opcursel(data)                                     (0x000000C0&((data)<<6))
#define  CRT_TEMP_SENSOR_4_tm_hold_dly(data)                                     (0x00000030&((data)<<4))
#define  CRT_TEMP_SENSOR_4_tm_osccursel(data)                                    (0x0000000C&((data)<<2))
#define  CRT_TEMP_SENSOR_4_tm_resol(data)                                        (0x00000003&(data))
#define  CRT_TEMP_SENSOR_4_get_tm_r(data)                                        ((0xFFFFFF00&(data))>>8)
#define  CRT_TEMP_SENSOR_4_get_tm_opcursel(data)                                 ((0x000000C0&(data))>>6)
#define  CRT_TEMP_SENSOR_4_get_tm_hold_dly(data)                                 ((0x00000030&(data))>>4)
#define  CRT_TEMP_SENSOR_4_get_tm_osccursel(data)                                ((0x0000000C&(data))>>2)
#define  CRT_TEMP_SENSOR_4_get_tm_resol(data)                                    (0x00000003&(data))

#define  CRT_TEMP_SENSOR_5                                                       0x18000390
#define  CRT_TEMP_SENSOR_5_reg_addr                                              "0xB8000390"
#define  CRT_TEMP_SENSOR_5_reg                                                   0xB8000390
#define  CRT_TEMP_SENSOR_5_inst_addr                                             "0x0015"
#define  set_CRT_TEMP_SENSOR_5_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_5_reg)=data)
#define  get_CRT_TEMP_SENSOR_5_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_5_reg))
#define  CRT_TEMP_SENSOR_5_tm_rstb_shift                                         (31)
#define  CRT_TEMP_SENSOR_5_tm_sdm_test_shift                                     (30)
#define  CRT_TEMP_SENSOR_5_tm_sdm_test_en_shift                                  (29)
#define  CRT_TEMP_SENSOR_5_tm_test_en_shift                                      (28)
#define  CRT_TEMP_SENSOR_5_tm_vcmsel_shift                                       (25)
#define  CRT_TEMP_SENSOR_5_tm_vbe_biassel_shift                                  (23)
#define  CRT_TEMP_SENSOR_5_tm_chopfreqsel_shift                                  (12)
#define  CRT_TEMP_SENSOR_5_tm_chop_swcnt_shift                                   (4)
#define  CRT_TEMP_SENSOR_5_tm_rst_n_shift                                        (0)
#define  CRT_TEMP_SENSOR_5_tm_rstb_mask                                          (0x80000000)
#define  CRT_TEMP_SENSOR_5_tm_sdm_test_mask                                      (0x40000000)
#define  CRT_TEMP_SENSOR_5_tm_sdm_test_en_mask                                   (0x20000000)
#define  CRT_TEMP_SENSOR_5_tm_test_en_mask                                       (0x10000000)
#define  CRT_TEMP_SENSOR_5_tm_vcmsel_mask                                        (0x0E000000)
#define  CRT_TEMP_SENSOR_5_tm_vbe_biassel_mask                                   (0x01800000)
#define  CRT_TEMP_SENSOR_5_tm_chopfreqsel_mask                                   (0x007FF000)
#define  CRT_TEMP_SENSOR_5_tm_chop_swcnt_mask                                    (0x000001F0)
#define  CRT_TEMP_SENSOR_5_tm_rst_n_mask                                         (0x00000001)
#define  CRT_TEMP_SENSOR_5_tm_rstb(data)                                         (0x80000000&((data)<<31))
#define  CRT_TEMP_SENSOR_5_tm_sdm_test(data)                                     (0x40000000&((data)<<30))
#define  CRT_TEMP_SENSOR_5_tm_sdm_test_en(data)                                  (0x20000000&((data)<<29))
#define  CRT_TEMP_SENSOR_5_tm_test_en(data)                                      (0x10000000&((data)<<28))
#define  CRT_TEMP_SENSOR_5_tm_vcmsel(data)                                       (0x0E000000&((data)<<25))
#define  CRT_TEMP_SENSOR_5_tm_vbe_biassel(data)                                  (0x01800000&((data)<<23))
#define  CRT_TEMP_SENSOR_5_tm_chopfreqsel(data)                                  (0x007FF000&((data)<<12))
#define  CRT_TEMP_SENSOR_5_tm_chop_swcnt(data)                                   (0x000001F0&((data)<<4))
#define  CRT_TEMP_SENSOR_5_tm_rst_n(data)                                        (0x00000001&(data))
#define  CRT_TEMP_SENSOR_5_get_tm_rstb(data)                                     ((0x80000000&(data))>>31)
#define  CRT_TEMP_SENSOR_5_get_tm_sdm_test(data)                                 ((0x40000000&(data))>>30)
#define  CRT_TEMP_SENSOR_5_get_tm_sdm_test_en(data)                              ((0x20000000&(data))>>29)
#define  CRT_TEMP_SENSOR_5_get_tm_test_en(data)                                  ((0x10000000&(data))>>28)
#define  CRT_TEMP_SENSOR_5_get_tm_vcmsel(data)                                   ((0x0E000000&(data))>>25)
#define  CRT_TEMP_SENSOR_5_get_tm_vbe_biassel(data)                              ((0x01800000&(data))>>23)
#define  CRT_TEMP_SENSOR_5_get_tm_chopfreqsel(data)                              ((0x007FF000&(data))>>12)
#define  CRT_TEMP_SENSOR_5_get_tm_chop_swcnt(data)                               ((0x000001F0&(data))>>4)
#define  CRT_TEMP_SENSOR_5_get_tm_rst_n(data)                                    (0x00000001&(data))

#define  CRT_TEMP_SENSOR_6                                                       0x18000394
#define  CRT_TEMP_SENSOR_6_reg_addr                                              "0xB8000394"
#define  CRT_TEMP_SENSOR_6_reg                                                   0xB8000394
#define  CRT_TEMP_SENSOR_6_inst_addr                                             "0x0016"
#define  set_CRT_TEMP_SENSOR_6_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_6_reg)=data)
#define  get_CRT_TEMP_SENSOR_6_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_6_reg))
#define  CRT_TEMP_SENSOR_6_tm_sample_dly_shift                                   (16)
#define  CRT_TEMP_SENSOR_6_tm_compare_dly_shift                                  (0)
#define  CRT_TEMP_SENSOR_6_tm_sample_dly_mask                                    (0xFFFF0000)
#define  CRT_TEMP_SENSOR_6_tm_compare_dly_mask                                   (0x0000FFFF)
#define  CRT_TEMP_SENSOR_6_tm_sample_dly(data)                                   (0xFFFF0000&((data)<<16))
#define  CRT_TEMP_SENSOR_6_tm_compare_dly(data)                                  (0x0000FFFF&(data))
#define  CRT_TEMP_SENSOR_6_get_tm_sample_dly(data)                               ((0xFFFF0000&(data))>>16)
#define  CRT_TEMP_SENSOR_6_get_tm_compare_dly(data)                              (0x0000FFFF&(data))

#define  CRT_TEMP_SENSOR_7                                                       0x18000398
#define  CRT_TEMP_SENSOR_7_reg_addr                                              "0xB8000398"
#define  CRT_TEMP_SENSOR_7_reg                                                   0xB8000398
#define  CRT_TEMP_SENSOR_7_inst_addr                                             "0x0017"
#define  set_CRT_TEMP_SENSOR_7_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_7_reg)=data)
#define  get_CRT_TEMP_SENSOR_7_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_7_reg))
#define  CRT_TEMP_SENSOR_7_tm_pwron_dly_shift                                    (16)
#define  CRT_TEMP_SENSOR_7_tm_reverse_cmp_out_shift                              (15)
#define  CRT_TEMP_SENSOR_7_tm_sbg_shift                                          (12)
#define  CRT_TEMP_SENSOR_7_tm_sinl_shift                                         (10)
#define  CRT_TEMP_SENSOR_7_tm_sos_shift                                          (7)
#define  CRT_TEMP_SENSOR_7_tm_en_shift                                           (6)
#define  CRT_TEMP_SENSOR_7_tm_sw2_sw3_reverse_shift                              (5)
#define  CRT_TEMP_SENSOR_7_tm_scan_mode_shift                                    (4)
#define  CRT_TEMP_SENSOR_7_tm_biasdem_sel_shift                                  (3)
#define  CRT_TEMP_SENSOR_7_td_wrep_edge_sel_shift                                (1)
#define  CRT_TEMP_SENSOR_7_data_valid_edge_sel_shift                             (0)
#define  CRT_TEMP_SENSOR_7_tm_pwron_dly_mask                                     (0xFFFF0000)
#define  CRT_TEMP_SENSOR_7_tm_reverse_cmp_out_mask                               (0x00008000)
#define  CRT_TEMP_SENSOR_7_tm_sbg_mask                                           (0x00007000)
#define  CRT_TEMP_SENSOR_7_tm_sinl_mask                                          (0x00000C00)
#define  CRT_TEMP_SENSOR_7_tm_sos_mask                                           (0x00000380)
#define  CRT_TEMP_SENSOR_7_tm_en_mask                                            (0x00000040)
#define  CRT_TEMP_SENSOR_7_tm_sw2_sw3_reverse_mask                               (0x00000020)
#define  CRT_TEMP_SENSOR_7_tm_scan_mode_mask                                     (0x00000010)
#define  CRT_TEMP_SENSOR_7_tm_biasdem_sel_mask                                   (0x00000008)
#define  CRT_TEMP_SENSOR_7_td_wrep_edge_sel_mask                                 (0x00000002)
#define  CRT_TEMP_SENSOR_7_data_valid_edge_sel_mask                              (0x00000001)
#define  CRT_TEMP_SENSOR_7_tm_pwron_dly(data)                                    (0xFFFF0000&((data)<<16))
#define  CRT_TEMP_SENSOR_7_tm_reverse_cmp_out(data)                              (0x00008000&((data)<<15))
#define  CRT_TEMP_SENSOR_7_tm_sbg(data)                                          (0x00007000&((data)<<12))
#define  CRT_TEMP_SENSOR_7_tm_sinl(data)                                         (0x00000C00&((data)<<10))
#define  CRT_TEMP_SENSOR_7_tm_sos(data)                                          (0x00000380&((data)<<7))
#define  CRT_TEMP_SENSOR_7_tm_en(data)                                           (0x00000040&((data)<<6))
#define  CRT_TEMP_SENSOR_7_tm_sw2_sw3_reverse(data)                              (0x00000020&((data)<<5))
#define  CRT_TEMP_SENSOR_7_tm_scan_mode(data)                                    (0x00000010&((data)<<4))
#define  CRT_TEMP_SENSOR_7_tm_biasdem_sel(data)                                  (0x00000008&((data)<<3))
#define  CRT_TEMP_SENSOR_7_td_wrep_edge_sel(data)                                (0x00000002&((data)<<1))
#define  CRT_TEMP_SENSOR_7_data_valid_edge_sel(data)                             (0x00000001&(data))
#define  CRT_TEMP_SENSOR_7_get_tm_pwron_dly(data)                                ((0xFFFF0000&(data))>>16)
#define  CRT_TEMP_SENSOR_7_get_tm_reverse_cmp_out(data)                          ((0x00008000&(data))>>15)
#define  CRT_TEMP_SENSOR_7_get_tm_sbg(data)                                      ((0x00007000&(data))>>12)
#define  CRT_TEMP_SENSOR_7_get_tm_sinl(data)                                     ((0x00000C00&(data))>>10)
#define  CRT_TEMP_SENSOR_7_get_tm_sos(data)                                      ((0x00000380&(data))>>7)
#define  CRT_TEMP_SENSOR_7_get_tm_en(data)                                       ((0x00000040&(data))>>6)
#define  CRT_TEMP_SENSOR_7_get_tm_sw2_sw3_reverse(data)                          ((0x00000020&(data))>>5)
#define  CRT_TEMP_SENSOR_7_get_tm_scan_mode(data)                                ((0x00000010&(data))>>4)
#define  CRT_TEMP_SENSOR_7_get_tm_biasdem_sel(data)                              ((0x00000008&(data))>>3)
#define  CRT_TEMP_SENSOR_7_get_td_wrep_edge_sel(data)                            ((0x00000002&(data))>>1)
#define  CRT_TEMP_SENSOR_7_get_data_valid_edge_sel(data)                         (0x00000001&(data))

#define  CRT_TEMP_SENSOR_8                                                       0x1800039C
#define  CRT_TEMP_SENSOR_8_reg_addr                                              "0xB800039C"
#define  CRT_TEMP_SENSOR_8_reg                                                   0xB800039C
#define  CRT_TEMP_SENSOR_8_inst_addr                                             "0x0018"
#define  set_CRT_TEMP_SENSOR_8_reg(data)                                         (*((volatile unsigned int*)CRT_TEMP_SENSOR_8_reg)=data)
#define  get_CRT_TEMP_SENSOR_8_reg                                               (*((volatile unsigned int*)CRT_TEMP_SENSOR_8_reg))
#define  CRT_TEMP_SENSOR_8_tm_s_shift                                            (0)
#define  CRT_TEMP_SENSOR_8_tm_s_mask                                             (0x007FFFFF)
#define  CRT_TEMP_SENSOR_8_tm_s(data)                                            (0x007FFFFF&(data))
#define  CRT_TEMP_SENSOR_8_get_tm_s(data)                                        (0x007FFFFF&(data))

#define  CRT_THERMAL_RESULT_1                                                    0x180003A0
#define  CRT_THERMAL_RESULT_1_reg_addr                                           "0xB80003A0"
#define  CRT_THERMAL_RESULT_1_reg                                                0xB80003A0
#define  CRT_THERMAL_RESULT_1_inst_addr                                          "0x0019"
#define  set_CRT_THERMAL_RESULT_1_reg(data)                                      (*((volatile unsigned int*)CRT_THERMAL_RESULT_1_reg)=data)
#define  get_CRT_THERMAL_RESULT_1_reg                                            (*((volatile unsigned int*)CRT_THERMAL_RESULT_1_reg))
#define  CRT_THERMAL_RESULT_1_data_out_tm_shift                                  (24)
#define  CRT_THERMAL_RESULT_1_ct_out_o_tm_shift                                  (0)
#define  CRT_THERMAL_RESULT_1_data_out_tm_mask                                   (0x7F000000)
#define  CRT_THERMAL_RESULT_1_ct_out_o_tm_mask                                   (0x0007FFFF)
#define  CRT_THERMAL_RESULT_1_data_out_tm(data)                                  (0x7F000000&((data)<<24))
#define  CRT_THERMAL_RESULT_1_ct_out_o_tm(data)                                  (0x0007FFFF&(data))
#define  CRT_THERMAL_RESULT_1_get_data_out_tm(data)                              ((0x7F000000&(data))>>24)
#define  CRT_THERMAL_RESULT_1_get_ct_out_o_tm(data)                              (0x0007FFFF&(data))

#define  CRT_THERMAL_RESULT_2                                                    0x180003A4
#define  CRT_THERMAL_RESULT_2_reg_addr                                           "0xB80003A4"
#define  CRT_THERMAL_RESULT_2_reg                                                0xB80003A4
#define  CRT_THERMAL_RESULT_2_inst_addr                                          "0x001A"
#define  set_CRT_THERMAL_RESULT_2_reg(data)                                      (*((volatile unsigned int*)CRT_THERMAL_RESULT_2_reg)=data)
#define  get_CRT_THERMAL_RESULT_2_reg                                            (*((volatile unsigned int*)CRT_THERMAL_RESULT_2_reg))
#define  CRT_THERMAL_RESULT_2_u_out_tm_shift                                     (0)
#define  CRT_THERMAL_RESULT_2_u_out_tm_mask                                      (0x003FFFFF)
#define  CRT_THERMAL_RESULT_2_u_out_tm(data)                                     (0x003FFFFF&(data))
#define  CRT_THERMAL_RESULT_2_get_u_out_tm(data)                                 (0x003FFFFF&(data))

#define  CRT_INT_CTRL_SCPU                                                       0x18000290
#define  CRT_INT_CTRL_SCPU_reg_addr                                              "0xB8000290"
#define  CRT_INT_CTRL_SCPU_reg                                                   0xB8000290
#define  CRT_INT_CTRL_SCPU_inst_addr                                             "0x001B"
#define  set_CRT_INT_CTRL_SCPU_reg(data)                                         (*((volatile unsigned int*)CRT_INT_CTRL_SCPU_reg)=data)
#define  get_CRT_INT_CTRL_SCPU_reg                                               (*((volatile unsigned int*)CRT_INT_CTRL_SCPU_reg))
#define  CRT_INT_CTRL_SCPU_smartcard_int_scpu_routing_en_shift                   (31)
#define  CRT_INT_CTRL_SCPU_dummy1_shift                                           (30)
#define  CRT_INT_CTRL_SCPU_dummy2_shift                                           (29)
#define  CRT_INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en_shift               (28)
#define  CRT_INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en_shift        (27)
#define  CRT_INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en_shift                (26)
#define  CRT_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_shift        (25)
#define  CRT_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_shift                (24)
#define  CRT_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_shift            (23)
#define  CRT_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_shift                 (22)
#define  CRT_INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en_shift                 (21)
#define  CRT_INT_CTRL_SCPU_akl_int_scpu_routing_en_shift                         (20)
#define  CRT_INT_CTRL_SCPU_usb3_int_scpu_routing_en_shift                        (19)
#define  CRT_INT_CTRL_SCPU_otg_int_scpu_routing_en_shift                         (18)
#define  CRT_INT_CTRL_SCPU_etn_int_scpu_routing_en_shift                         (17)
#define  CRT_INT_CTRL_SCPU_sd_int_scpu_routing_en_shift                          (16)
#define  CRT_INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en_shift                   (15)
#define  CRT_INT_CTRL_SCPU_audio_irq_scpu_routing_en_shift                       (14)
#define  CRT_INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en_shift                    (13)
#define  CRT_INT_CTRL_SCPU_dcphy_int_scpu_routing_en_shift                       (12)
#define  CRT_INT_CTRL_SCPU_dc_int_scpu_routing_en_shift                          (11)
#define  CRT_INT_CTRL_SCPU_tve_int_scpu_routing_en_shift                         (10)
#define  CRT_INT_CTRL_SCPU_osd_int_scpu_routing_en_shift                         (9)
#define  CRT_INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en_shift                  (8)
#define  CRT_INT_CTRL_SCPU_dctl_int_scpu_routing_en_shift                        (7)
#define  CRT_INT_CTRL_SCPU_vbi_int_scpu_routing_en_shift                         (6)
#define  CRT_INT_CTRL_SCPU_vdec_int_scpu_routing_en_shift                        (5)
#define  CRT_INT_CTRL_SCPU_if_demod_int_scpu_routing_en_shift                    (4)
#define  CRT_INT_CTRL_SCPU_dispm_int_scpu_routing_en_shift                       (3)
#define  CRT_INT_CTRL_SCPU_dispi_int_scpu_routing_en_shift                       (2)
#define  CRT_INT_CTRL_SCPU_apll_dds_int_scpu_routing_en_shift                    (1)
#define  CRT_INT_CTRL_SCPU_ddc_int_scpu_routing_en_shift                         (0)
#define  CRT_INT_CTRL_SCPU_smartcard_int_scpu_routing_en_mask                    (0x80000000)
#define  CRT_INT_CTRL_SCPU_dummy1_mask                                            (0x40000000)
#define  CRT_INT_CTRL_SCPU_dummy2_mask                                            (0x20000000)
#define  CRT_INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en_mask                (0x10000000)
#define  CRT_INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en_mask         (0x08000000)
#define  CRT_INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en_mask                 (0x04000000)
#define  CRT_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_mask         (0x02000000)
#define  CRT_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_mask                 (0x01000000)
#define  CRT_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_mask             (0x00800000)
#define  CRT_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask                  (0x00400000)
#define  CRT_INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en_mask                  (0x00200000)
#define  CRT_INT_CTRL_SCPU_akl_int_scpu_routing_en_mask                          (0x00100000)
#define  CRT_INT_CTRL_SCPU_usb3_int_scpu_routing_en_mask                         (0x00080000)
#define  CRT_INT_CTRL_SCPU_otg_int_scpu_routing_en_mask                          (0x00040000)
#define  CRT_INT_CTRL_SCPU_etn_int_scpu_routing_en_mask                          (0x00020000)
#define  CRT_INT_CTRL_SCPU_sd_int_scpu_routing_en_mask                           (0x00010000)
#define  CRT_INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en_mask                    (0x00008000)
#define  CRT_INT_CTRL_SCPU_audio_irq_scpu_routing_en_mask                        (0x00004000)
#define  CRT_INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en_mask                     (0x00002000)
#define  CRT_INT_CTRL_SCPU_dcphy_int_scpu_routing_en_mask                        (0x00001000)
#define  CRT_INT_CTRL_SCPU_dc_int_scpu_routing_en_mask                           (0x00000800)
#define  CRT_INT_CTRL_SCPU_tve_int_scpu_routing_en_mask                          (0x00000400)
#define  CRT_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask                          (0x00000200)
#define  CRT_INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en_mask                   (0x00000100)
#define  CRT_INT_CTRL_SCPU_dctl_int_scpu_routing_en_mask                         (0x00000080)
#define  CRT_INT_CTRL_SCPU_vbi_int_scpu_routing_en_mask                          (0x00000040)
#define  CRT_INT_CTRL_SCPU_vdec_int_scpu_routing_en_mask                         (0x00000020)
#define  CRT_INT_CTRL_SCPU_if_demod_int_scpu_routing_en_mask                     (0x00000010)
#define  CRT_INT_CTRL_SCPU_dispm_int_scpu_routing_en_mask                        (0x00000008)
#define  CRT_INT_CTRL_SCPU_dispi_int_scpu_routing_en_mask                        (0x00000004)
#define  CRT_INT_CTRL_SCPU_apll_dds_int_scpu_routing_en_mask                     (0x00000002)
#define  CRT_INT_CTRL_SCPU_ddc_int_scpu_routing_en_mask                          (0x00000001)
#define  CRT_INT_CTRL_SCPU_smartcard_int_scpu_routing_en(data)                   (0x80000000&((data)<<31))
#define  CRT_INT_CTRL_SCPU_dummy1(data)                                           (0x40000000&((data)<<30))
#define  CRT_INT_CTRL_SCPU_dummy2(data)                                           (0x20000000&((data)<<29))
#define  CRT_INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en(data)               (0x10000000&((data)<<28))
#define  CRT_INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en(data)        (0x08000000&((data)<<27))
#define  CRT_INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en(data)                (0x04000000&((data)<<26))
#define  CRT_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en(data)        (0x02000000&((data)<<25))
#define  CRT_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en(data)                (0x01000000&((data)<<24))
#define  CRT_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en(data)            (0x00800000&((data)<<23))
#define  CRT_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en(data)                 (0x00400000&((data)<<22))
#define  CRT_INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en(data)                 (0x00200000&((data)<<21))
#define  CRT_INT_CTRL_SCPU_akl_int_scpu_routing_en(data)                         (0x00100000&((data)<<20))
#define  CRT_INT_CTRL_SCPU_usb3_int_scpu_routing_en(data)                        (0x00080000&((data)<<19))
#define  CRT_INT_CTRL_SCPU_otg_int_scpu_routing_en(data)                         (0x00040000&((data)<<18))
#define  CRT_INT_CTRL_SCPU_etn_int_scpu_routing_en(data)                         (0x00020000&((data)<<17))
#define  CRT_INT_CTRL_SCPU_sd_int_scpu_routing_en(data)                          (0x00010000&((data)<<16))
#define  CRT_INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en(data)                   (0x00008000&((data)<<15))
#define  CRT_INT_CTRL_SCPU_audio_irq_scpu_routing_en(data)                       (0x00004000&((data)<<14))
#define  CRT_INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en(data)                    (0x00002000&((data)<<13))
#define  CRT_INT_CTRL_SCPU_dcphy_int_scpu_routing_en(data)                       (0x00001000&((data)<<12))
#define  CRT_INT_CTRL_SCPU_dc_int_scpu_routing_en(data)                          (0x00000800&((data)<<11))
#define  CRT_INT_CTRL_SCPU_tve_int_scpu_routing_en(data)                         (0x00000400&((data)<<10))
#define  CRT_INT_CTRL_SCPU_osd_int_scpu_routing_en(data)                         (0x00000200&((data)<<9))
#define  CRT_INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en(data)                  (0x00000100&((data)<<8))
#define  CRT_INT_CTRL_SCPU_dctl_int_scpu_routing_en(data)                        (0x00000080&((data)<<7))
#define  CRT_INT_CTRL_SCPU_vbi_int_scpu_routing_en(data)                         (0x00000040&((data)<<6))
#define  CRT_INT_CTRL_SCPU_vdec_int_scpu_routing_en(data)                        (0x00000020&((data)<<5))
#define  CRT_INT_CTRL_SCPU_if_demod_int_scpu_routing_en(data)                    (0x00000010&((data)<<4))
#define  CRT_INT_CTRL_SCPU_dispm_int_scpu_routing_en(data)                       (0x00000008&((data)<<3))
#define  CRT_INT_CTRL_SCPU_dispi_int_scpu_routing_en(data)                       (0x00000004&((data)<<2))
#define  CRT_INT_CTRL_SCPU_apll_dds_int_scpu_routing_en(data)                    (0x00000002&((data)<<1))
#define  CRT_INT_CTRL_SCPU_ddc_int_scpu_routing_en(data)                         (0x00000001&(data))
#define  CRT_INT_CTRL_SCPU_get_smartcard_int_scpu_routing_en(data)               ((0x80000000&(data))>>31)
#define  CRT_INT_CTRL_SCPU_get_dummy1(data)                                       ((0x40000000&(data))>>30)
#define  CRT_INT_CTRL_SCPU_get_dummy2(data)                                       ((0x20000000&(data))>>29)
#define  CRT_INT_CTRL_SCPU_get_standby_syncp_int_scpu_routing_en(data)           ((0x10000000&(data))>>28)
#define  CRT_INT_CTRL_SCPU_get_standby_hdmi_clk_det_int_scpu_routing_en(data)    ((0x08000000&(data))>>27)
#define  CRT_INT_CTRL_SCPU_get_standby_wdog_int_scpu_routing_en(data)            ((0x04000000&(data))>>26)
#define  CRT_INT_CTRL_SCPU_get_standby_iso_misc_off_int_scpu_routing_en(data)    ((0x02000000&(data))>>25)
#define  CRT_INT_CTRL_SCPU_get_standby_cbus_int_scpu_routing_en(data)            ((0x01000000&(data))>>24)
#define  CRT_INT_CTRL_SCPU_get_standby_iso_misc_int_scpu_routing_en(data)        ((0x00800000&(data))>>23)
#define  CRT_INT_CTRL_SCPU_get_standby_cec_int_scpu_routing_en(data)             ((0x00400000&(data))>>22)
#define  CRT_INT_CTRL_SCPU_get_standby_rtc_int_scpu_routing_en(data)             ((0x00200000&(data))>>21)
#define  CRT_INT_CTRL_SCPU_get_akl_int_scpu_routing_en(data)                     ((0x00100000&(data))>>20)
#define  CRT_INT_CTRL_SCPU_get_usb3_int_scpu_routing_en(data)                    ((0x00080000&(data))>>19)
#define  CRT_INT_CTRL_SCPU_get_otg_int_scpu_routing_en(data)                     ((0x00040000&(data))>>18)
#define  CRT_INT_CTRL_SCPU_get_etn_int_scpu_routing_en(data)                     ((0x00020000&(data))>>17)
#define  CRT_INT_CTRL_SCPU_get_sd_int_scpu_routing_en(data)                      ((0x00010000&(data))>>16)
#define  CRT_INT_CTRL_SCPU_get_audio_dma_irq_scpu_routing_en(data)               ((0x00008000&(data))>>15)
#define  CRT_INT_CTRL_SCPU_get_audio_irq_scpu_routing_en(data)                   ((0x00004000&(data))>>14)
#define  CRT_INT_CTRL_SCPU_get_tv_sb_dc_int_scpu_routing_en(data)                ((0x00002000&(data))>>13)
#define  CRT_INT_CTRL_SCPU_get_dcphy_int_scpu_routing_en(data)                   ((0x00001000&(data))>>12)
#define  CRT_INT_CTRL_SCPU_get_dc_int_scpu_routing_en(data)                      ((0x00000800&(data))>>11)
#define  CRT_INT_CTRL_SCPU_get_tve_int_scpu_routing_en(data)                     ((0x00000400&(data))>>10)
#define  CRT_INT_CTRL_SCPU_get_osd_int_scpu_routing_en(data)                     ((0x00000200&(data))>>9)
#define  CRT_INT_CTRL_SCPU_get_ultra_zoom_int_scpu_routing_en(data)              ((0x00000100&(data))>>8)
#define  CRT_INT_CTRL_SCPU_get_dctl_int_scpu_routing_en(data)                    ((0x00000080&(data))>>7)
#define  CRT_INT_CTRL_SCPU_get_vbi_int_scpu_routing_en(data)                     ((0x00000040&(data))>>6)
#define  CRT_INT_CTRL_SCPU_get_vdec_int_scpu_routing_en(data)                    ((0x00000020&(data))>>5)
#define  CRT_INT_CTRL_SCPU_get_if_demod_int_scpu_routing_en(data)                ((0x00000010&(data))>>4)
#define  CRT_INT_CTRL_SCPU_get_dispm_int_scpu_routing_en(data)                   ((0x00000008&(data))>>3)
#define  CRT_INT_CTRL_SCPU_get_dispi_int_scpu_routing_en(data)                   ((0x00000004&(data))>>2)
#define  CRT_INT_CTRL_SCPU_get_apll_dds_int_scpu_routing_en(data)                ((0x00000002&(data))>>1)
#define  CRT_INT_CTRL_SCPU_get_ddc_int_scpu_routing_en(data)                     (0x00000001&(data))

#define  CRT_INT_CTRL_VCPU                                                       0x18000294
#define  CRT_INT_CTRL_VCPU_reg_addr                                              "0xB8000294"
#define  CRT_INT_CTRL_VCPU_reg                                                   0xB8000294
#define  CRT_INT_CTRL_VCPU_inst_addr                                             "0x001C"
#define  set_CRT_INT_CTRL_VCPU_reg(data)                                         (*((volatile unsigned int*)CRT_INT_CTRL_VCPU_reg)=data)
#define  get_CRT_INT_CTRL_VCPU_reg                                               (*((volatile unsigned int*)CRT_INT_CTRL_VCPU_reg))
#define  CRT_INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en_shift                    (30)
#define  CRT_INT_CTRL_VCPU_vodma_int_vcpu_routing_en_shift                       (29)
#define  CRT_INT_CTRL_VCPU_dummy1_shift                                           (28)
#define  CRT_INT_CTRL_VCPU_dummy2_shift                                           (27)
#define  CRT_INT_CTRL_VCPU_dummy3_shift                                           (26)
#define  CRT_INT_CTRL_VCPU_dummy4_shift                                           (25)
#define  CRT_INT_CTRL_VCPU_dummy5_shift                                           (24)
#define  CRT_INT_CTRL_VCPU_dummy6_shift                                           (23)
#define  CRT_INT_CTRL_VCPU_dummy7_shift                                           (22)
#define  CRT_INT_CTRL_VCPU_dummy8_shift                                           (21)
#define  CRT_INT_CTRL_VCPU_dummy9_shift                                           (20)
#define  CRT_INT_CTRL_VCPU_dummy10_shift                                           (19)
#define  CRT_INT_CTRL_VCPU_dummy11_shift                                           (18)
#define  CRT_INT_CTRL_VCPU_dummy12_shift                                           (17)
#define  CRT_INT_CTRL_VCPU_dummy13_shift                                           (16)
#define  CRT_INT_CTRL_VCPU_dummy14_shift                                           (15)
#define  CRT_INT_CTRL_VCPU_dummy15_shift                                           (14)
#define  CRT_INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en_shift                    (13)
#define  CRT_INT_CTRL_VCPU_dcphy_int_vcpu_routing_en_shift                       (12)
#define  CRT_INT_CTRL_VCPU_dc_int_vcpu_routing_en_shift                          (11)
#define  CRT_INT_CTRL_VCPU_tve_int_vcpu_routing_en_shift                         (10)
#define  CRT_INT_CTRL_VCPU_osd_int_vcpu_routing_en_shift                         (9)
#define  CRT_INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en_shift                  (8)
#define  CRT_INT_CTRL_VCPU_dctl_int_vcpu_routing_en_shift                        (7)
#define  CRT_INT_CTRL_VCPU_vbi_int_vcpu_routing_en_shift                         (6)
#define  CRT_INT_CTRL_VCPU_vdec_int_vcpu_routing_en_shift                        (5)
#define  CRT_INT_CTRL_VCPU_if_demod_int_vcpu_routing_en_shift                    (4)
#define  CRT_INT_CTRL_VCPU_dispm_int_vcpu_routing_en_shift                       (3)
#define  CRT_INT_CTRL_VCPU_dispi_int_vcpu_routing_en_shift                       (2)
#define  CRT_INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en_shift                    (1)
#define  CRT_INT_CTRL_VCPU_ddc_int_vcpu_routing_en_shift                         (0)
#define  CRT_INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en_mask                     (0x40000000)
#define  CRT_INT_CTRL_VCPU_vodma_int_vcpu_routing_en_mask                        (0x20000000)
#define  CRT_INT_CTRL_VCPU_dummy1_mask                                            (0x10000000)
#define  CRT_INT_CTRL_VCPU_dummy2_mask                                            (0x08000000)
#define  CRT_INT_CTRL_VCPU_dummy3_mask                                            (0x04000000)
#define  CRT_INT_CTRL_VCPU_dummy4_mask                                            (0x02000000)
#define  CRT_INT_CTRL_VCPU_dummy5_mask                                            (0x01000000)
#define  CRT_INT_CTRL_VCPU_dummy6_mask                                            (0x00800000)
#define  CRT_INT_CTRL_VCPU_dummy7_mask                                            (0x00400000)
#define  CRT_INT_CTRL_VCPU_dummy8_mask                                            (0x00200000)
#define  CRT_INT_CTRL_VCPU_dummy9_mask                                            (0x00100000)
#define  CRT_INT_CTRL_VCPU_dummy10_mask                                            (0x00080000)
#define  CRT_INT_CTRL_VCPU_dummy11_mask                                            (0x00040000)
#define  CRT_INT_CTRL_VCPU_dummy12_mask                                            (0x00020000)
#define  CRT_INT_CTRL_VCPU_dummy13_mask                                            (0x00010000)
#define  CRT_INT_CTRL_VCPU_dummy14_mask                                            (0x00008000)
#define  CRT_INT_CTRL_VCPU_dummy15_mask                                            (0x00004000)
#define  CRT_INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en_mask                     (0x00002000)
#define  CRT_INT_CTRL_VCPU_dcphy_int_vcpu_routing_en_mask                        (0x00001000)
#define  CRT_INT_CTRL_VCPU_dc_int_vcpu_routing_en_mask                           (0x00000800)
#define  CRT_INT_CTRL_VCPU_tve_int_vcpu_routing_en_mask                          (0x00000400)
#define  CRT_INT_CTRL_VCPU_osd_int_vcpu_routing_en_mask                          (0x00000200)
#define  CRT_INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en_mask                   (0x00000100)
#define  CRT_INT_CTRL_VCPU_dctl_int_vcpu_routing_en_mask                         (0x00000080)
#define  CRT_INT_CTRL_VCPU_vbi_int_vcpu_routing_en_mask                          (0x00000040)
#define  CRT_INT_CTRL_VCPU_vdec_int_vcpu_routing_en_mask                         (0x00000020)
#define  CRT_INT_CTRL_VCPU_if_demod_int_vcpu_routing_en_mask                     (0x00000010)
#define  CRT_INT_CTRL_VCPU_dispm_int_vcpu_routing_en_mask                        (0x00000008)
#define  CRT_INT_CTRL_VCPU_dispi_int_vcpu_routing_en_mask                        (0x00000004)
#define  CRT_INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en_mask                     (0x00000002)
#define  CRT_INT_CTRL_VCPU_ddc_int_vcpu_routing_en_mask                          (0x00000001)
#define  CRT_INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en(data)                    (0x40000000&((data)<<30))
#define  CRT_INT_CTRL_VCPU_vodma_int_vcpu_routing_en(data)                       (0x20000000&((data)<<29))
#define  CRT_INT_CTRL_VCPU_dummy1(data)                                           (0x10000000&((data)<<28))
#define  CRT_INT_CTRL_VCPU_dummy2(data)                                           (0x08000000&((data)<<27))
#define  CRT_INT_CTRL_VCPU_dummy3(data)                                           (0x04000000&((data)<<26))
#define  CRT_INT_CTRL_VCPU_dummy4(data)                                           (0x02000000&((data)<<25))
#define  CRT_INT_CTRL_VCPU_dummy5(data)                                           (0x01000000&((data)<<24))
#define  CRT_INT_CTRL_VCPU_dummy6(data)                                           (0x00800000&((data)<<23))
#define  CRT_INT_CTRL_VCPU_dummy7(data)                                           (0x00400000&((data)<<22))
#define  CRT_INT_CTRL_VCPU_dummy8(data)                                           (0x00200000&((data)<<21))
#define  CRT_INT_CTRL_VCPU_dummy9(data)                                           (0x00100000&((data)<<20))
#define  CRT_INT_CTRL_VCPU_dummy10(data)                                           (0x00080000&((data)<<19))
#define  CRT_INT_CTRL_VCPU_dummy11(data)                                           (0x00040000&((data)<<18))
#define  CRT_INT_CTRL_VCPU_dummy12(data)                                           (0x00020000&((data)<<17))
#define  CRT_INT_CTRL_VCPU_dummy13(data)                                           (0x00010000&((data)<<16))
#define  CRT_INT_CTRL_VCPU_dummy14(data)                                           (0x00008000&((data)<<15))
#define  CRT_INT_CTRL_VCPU_dummy15(data)                                           (0x00004000&((data)<<14))
#define  CRT_INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en(data)                    (0x00002000&((data)<<13))
#define  CRT_INT_CTRL_VCPU_dcphy_int_vcpu_routing_en(data)                       (0x00001000&((data)<<12))
#define  CRT_INT_CTRL_VCPU_dc_int_vcpu_routing_en(data)                          (0x00000800&((data)<<11))
#define  CRT_INT_CTRL_VCPU_tve_int_vcpu_routing_en(data)                         (0x00000400&((data)<<10))
#define  CRT_INT_CTRL_VCPU_osd_int_vcpu_routing_en(data)                         (0x00000200&((data)<<9))
#define  CRT_INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en(data)                  (0x00000100&((data)<<8))
#define  CRT_INT_CTRL_VCPU_dctl_int_vcpu_routing_en(data)                        (0x00000080&((data)<<7))
#define  CRT_INT_CTRL_VCPU_vbi_int_vcpu_routing_en(data)                         (0x00000040&((data)<<6))
#define  CRT_INT_CTRL_VCPU_vdec_int_vcpu_routing_en(data)                        (0x00000020&((data)<<5))
#define  CRT_INT_CTRL_VCPU_if_demod_int_vcpu_routing_en(data)                    (0x00000010&((data)<<4))
#define  CRT_INT_CTRL_VCPU_dispm_int_vcpu_routing_en(data)                       (0x00000008&((data)<<3))
#define  CRT_INT_CTRL_VCPU_dispi_int_vcpu_routing_en(data)                       (0x00000004&((data)<<2))
#define  CRT_INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en(data)                    (0x00000002&((data)<<1))
#define  CRT_INT_CTRL_VCPU_ddc_int_vcpu_routing_en(data)                         (0x00000001&(data))
#define  CRT_INT_CTRL_VCPU_get_disp2tve_int_vcpu_routing_en(data)                ((0x40000000&(data))>>30)
#define  CRT_INT_CTRL_VCPU_get_vodma_int_vcpu_routing_en(data)                   ((0x20000000&(data))>>29)
#define  CRT_INT_CTRL_VCPU_get_dummy1(data)                                       ((0x10000000&(data))>>28)
#define  CRT_INT_CTRL_VCPU_get_dummy2(data)                                       ((0x08000000&(data))>>27)
#define  CRT_INT_CTRL_VCPU_get_dummy3(data)                                       ((0x04000000&(data))>>26)
#define  CRT_INT_CTRL_VCPU_get_dummy4(data)                                       ((0x02000000&(data))>>25)
#define  CRT_INT_CTRL_VCPU_get_dummy5(data)                                       ((0x01000000&(data))>>24)
#define  CRT_INT_CTRL_VCPU_get_dummy6(data)                                       ((0x00800000&(data))>>23)
#define  CRT_INT_CTRL_VCPU_get_dummy7(data)                                       ((0x00400000&(data))>>22)
#define  CRT_INT_CTRL_VCPU_get_dummy8(data)                                       ((0x00200000&(data))>>21)
#define  CRT_INT_CTRL_VCPU_get_dummy9(data)                                       ((0x00100000&(data))>>20)
#define  CRT_INT_CTRL_VCPU_get_dummy10(data)                                       ((0x00080000&(data))>>19)
#define  CRT_INT_CTRL_VCPU_get_dummy11(data)                                       ((0x00040000&(data))>>18)
#define  CRT_INT_CTRL_VCPU_get_dummy12(data)                                       ((0x00020000&(data))>>17)
#define  CRT_INT_CTRL_VCPU_get_dummy13(data)                                       ((0x00010000&(data))>>16)
#define  CRT_INT_CTRL_VCPU_get_dummy14(data)                                       ((0x00008000&(data))>>15)
#define  CRT_INT_CTRL_VCPU_get_dummy15(data)                                       ((0x00004000&(data))>>14)
#define  CRT_INT_CTRL_VCPU_get_tv_sb_dc_int_vcpu_routing_en(data)                ((0x00002000&(data))>>13)
#define  CRT_INT_CTRL_VCPU_get_dcphy_int_vcpu_routing_en(data)                   ((0x00001000&(data))>>12)
#define  CRT_INT_CTRL_VCPU_get_dc_int_vcpu_routing_en(data)                      ((0x00000800&(data))>>11)
#define  CRT_INT_CTRL_VCPU_get_tve_int_vcpu_routing_en(data)                     ((0x00000400&(data))>>10)
#define  CRT_INT_CTRL_VCPU_get_osd_int_vcpu_routing_en(data)                     ((0x00000200&(data))>>9)
#define  CRT_INT_CTRL_VCPU_get_ultra_zoom_int_vcpu_routing_en(data)              ((0x00000100&(data))>>8)
#define  CRT_INT_CTRL_VCPU_get_dctl_int_vcpu_routing_en(data)                    ((0x00000080&(data))>>7)
#define  CRT_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(data)                     ((0x00000040&(data))>>6)
#define  CRT_INT_CTRL_VCPU_get_vdec_int_vcpu_routing_en(data)                    ((0x00000020&(data))>>5)
#define  CRT_INT_CTRL_VCPU_get_if_demod_int_vcpu_routing_en(data)                ((0x00000010&(data))>>4)
#define  CRT_INT_CTRL_VCPU_get_dispm_int_vcpu_routing_en(data)                   ((0x00000008&(data))>>3)
#define  CRT_INT_CTRL_VCPU_get_dispi_int_vcpu_routing_en(data)                   ((0x00000004&(data))>>2)
#define  CRT_INT_CTRL_VCPU_get_apll_dds_int_vcpu_routing_en(data)                ((0x00000002&(data))>>1)
#define  CRT_INT_CTRL_VCPU_get_ddc_int_vcpu_routing_en(data)                     (0x00000001&(data))

#define  CRT_INT_CTRL_ACPU                                                       0x18000298
#define  CRT_INT_CTRL_ACPU_reg_addr                                              "0xB8000298"
#define  CRT_INT_CTRL_ACPU_reg                                                   0xB8000298
#define  CRT_INT_CTRL_ACPU_inst_addr                                             "0x001D"
#define  set_CRT_INT_CTRL_ACPU_reg(data)                                         (*((volatile unsigned int*)CRT_INT_CTRL_ACPU_reg)=data)
#define  get_CRT_INT_CTRL_ACPU_reg                                               (*((volatile unsigned int*)CRT_INT_CTRL_ACPU_reg))
#define  CRT_INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en_shift                   (15)
#define  CRT_INT_CTRL_ACPU_audio_irq_acpu_routing_en_shift                       (14)
#define  CRT_INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en_shift                    (13)
#define  CRT_INT_CTRL_ACPU_dcphy_int_acpu_routing_en_shift                       (12)
#define  CRT_INT_CTRL_ACPU_dc_int_acpu_routing_en_shift                          (11)
#define  CRT_INT_CTRL_ACPU_dummy1_shift                                           (10)
#define  CRT_INT_CTRL_ACPU_dummy2_shift                                           (9)
#define  CRT_INT_CTRL_ACPU_dummy3_shift                                           (8)
#define  CRT_INT_CTRL_ACPU_dummy4_shift                                           (7)
#define  CRT_INT_CTRL_ACPU_dummy5_shift                                           (6)
#define  CRT_INT_CTRL_ACPU_dummy6_shift                                           (5)
#define  CRT_INT_CTRL_ACPU_dummy7_shift                                           (4)
#define  CRT_INT_CTRL_ACPU_dummy8_shift                                           (3)
#define  CRT_INT_CTRL_ACPU_dummy9_shift                                           (2)
#define  CRT_INT_CTRL_ACPU_dummy10_shift                                           (1)
#define  CRT_INT_CTRL_ACPU_dummy11_shift                                           (0)
#define  CRT_INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en_mask                    (0x00008000)
#define  CRT_INT_CTRL_ACPU_audio_irq_acpu_routing_en_mask                        (0x00004000)
#define  CRT_INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en_mask                     (0x00002000)
#define  CRT_INT_CTRL_ACPU_dcphy_int_acpu_routing_en_mask                        (0x00001000)
#define  CRT_INT_CTRL_ACPU_dc_int_acpu_routing_en_mask                           (0x00000800)
#define  CRT_INT_CTRL_ACPU_dummy1_mask                                            (0x00000400)
#define  CRT_INT_CTRL_ACPU_dummy2_mask                                            (0x00000200)
#define  CRT_INT_CTRL_ACPU_dummy3_mask                                            (0x00000100)
#define  CRT_INT_CTRL_ACPU_dummy4_mask                                            (0x00000080)
#define  CRT_INT_CTRL_ACPU_dummy5_mask                                            (0x00000040)
#define  CRT_INT_CTRL_ACPU_dummy6_mask                                            (0x00000020)
#define  CRT_INT_CTRL_ACPU_dummy7_mask                                            (0x00000010)
#define  CRT_INT_CTRL_ACPU_dummy8_mask                                            (0x00000008)
#define  CRT_INT_CTRL_ACPU_dummy9_mask                                            (0x00000004)
#define  CRT_INT_CTRL_ACPU_dummy10_mask                                            (0x00000002)
#define  CRT_INT_CTRL_ACPU_dummy11_mask                                            (0x00000001)
#define  CRT_INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en(data)                   (0x00008000&((data)<<15))
#define  CRT_INT_CTRL_ACPU_audio_irq_acpu_routing_en(data)                       (0x00004000&((data)<<14))
#define  CRT_INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en(data)                    (0x00002000&((data)<<13))
#define  CRT_INT_CTRL_ACPU_dcphy_int_acpu_routing_en(data)                       (0x00001000&((data)<<12))
#define  CRT_INT_CTRL_ACPU_dc_int_acpu_routing_en(data)                          (0x00000800&((data)<<11))
#define  CRT_INT_CTRL_ACPU_dummy1(data)                                           (0x00000400&((data)<<10))
#define  CRT_INT_CTRL_ACPU_dummy2(data)                                           (0x00000200&((data)<<9))
#define  CRT_INT_CTRL_ACPU_dummy3(data)                                           (0x00000100&((data)<<8))
#define  CRT_INT_CTRL_ACPU_dummy4(data)                                           (0x00000080&((data)<<7))
#define  CRT_INT_CTRL_ACPU_dummy5(data)                                           (0x00000040&((data)<<6))
#define  CRT_INT_CTRL_ACPU_dummy6(data)                                           (0x00000020&((data)<<5))
#define  CRT_INT_CTRL_ACPU_dummy7(data)                                           (0x00000010&((data)<<4))
#define  CRT_INT_CTRL_ACPU_dummy8(data)                                           (0x00000008&((data)<<3))
#define  CRT_INT_CTRL_ACPU_dummy9(data)                                           (0x00000004&((data)<<2))
#define  CRT_INT_CTRL_ACPU_dummy10(data)                                           (0x00000002&((data)<<1))
#define  CRT_INT_CTRL_ACPU_dummy11(data)                                           (0x00000001&(data))
#define  CRT_INT_CTRL_ACPU_get_audio_dma_irq_acpu_routing_en(data)               ((0x00008000&(data))>>15)
#define  CRT_INT_CTRL_ACPU_get_audio_irq_acpu_routing_en(data)                   ((0x00004000&(data))>>14)
#define  CRT_INT_CTRL_ACPU_get_tv_sb_dc_int_acpu_routing_en(data)                ((0x00002000&(data))>>13)
#define  CRT_INT_CTRL_ACPU_get_dcphy_int_acpu_routing_en(data)                   ((0x00001000&(data))>>12)
#define  CRT_INT_CTRL_ACPU_get_dc_int_acpu_routing_en(data)                      ((0x00000800&(data))>>11)
#define  CRT_INT_CTRL_ACPU_get_dummy1(data)                                       ((0x00000400&(data))>>10)
#define  CRT_INT_CTRL_ACPU_get_dummy2(data)                                       ((0x00000200&(data))>>9)
#define  CRT_INT_CTRL_ACPU_get_dummy3(data)                                       ((0x00000100&(data))>>8)
#define  CRT_INT_CTRL_ACPU_get_dummy4(data)                                       ((0x00000080&(data))>>7)
#define  CRT_INT_CTRL_ACPU_get_dummy5(data)                                       ((0x00000040&(data))>>6)
#define  CRT_INT_CTRL_ACPU_get_dummy6(data)                                       ((0x00000020&(data))>>5)
#define  CRT_INT_CTRL_ACPU_get_dummy7(data)                                       ((0x00000010&(data))>>4)
#define  CRT_INT_CTRL_ACPU_get_dummy8(data)                                       ((0x00000008&(data))>>3)
#define  CRT_INT_CTRL_ACPU_get_dummy9(data)                                       ((0x00000004&(data))>>2)
#define  CRT_INT_CTRL_ACPU_get_dummy10(data)                                       ((0x00000002&(data))>>1)
#define  CRT_INT_CTRL_ACPU_get_dummy11(data)                                       (0x00000001&(data))

#define  CRT_INT_CTRL_KCPU                                                       0x1800029C
#define  CRT_INT_CTRL_KCPU_reg_addr                                              "0xB800029C"
#define  CRT_INT_CTRL_KCPU_reg                                                   0xB800029C
#define  CRT_INT_CTRL_KCPU_inst_addr                                             "0x001E"
#define  set_CRT_INT_CTRL_KCPU_reg(data)                                         (*((volatile unsigned int*)CRT_INT_CTRL_KCPU_reg)=data)
#define  get_CRT_INT_CTRL_KCPU_reg                                               (*((volatile unsigned int*)CRT_INT_CTRL_KCPU_reg))
#define  CRT_INT_CTRL_KCPU_smartcard_int_kcpu_routing_en_shift                   (31)
#define  CRT_INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en_shift                    (30)
#define  CRT_INT_CTRL_KCPU_vodma_int_kcpu_routing_en_shift                       (29)
#define  CRT_INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en_shift               (28)
#define  CRT_INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en_shift        (27)
#define  CRT_INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en_shift                (26)
#define  CRT_INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en_shift        (25)
#define  CRT_INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en_shift                (24)
#define  CRT_INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en_shift            (23)
#define  CRT_INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en_shift                 (22)
#define  CRT_INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en_shift                 (21)
#define  CRT_INT_CTRL_KCPU_akl_int_kcpu_routing_en_shift                         (20)
#define  CRT_INT_CTRL_KCPU_usb3_int_kcpu_routing_en_shift                        (19)
#define  CRT_INT_CTRL_KCPU_otg_int_kcpu_routing_en_shift                         (18)
#define  CRT_INT_CTRL_KCPU_etn_int_kcpu_routing_en_shift                         (17)
#define  CRT_INT_CTRL_KCPU_sd_int_kcpu_routing_en_shift                          (16)
#define  CRT_INT_CTRL_KCPU_dummy1_shift                                           (15)
#define  CRT_INT_CTRL_KCPU_dummy2_shift                                           (14)
#define  CRT_INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en_shift                    (13)
#define  CRT_INT_CTRL_KCPU_dcphy_int_kcpu_routing_en_shift                       (12)
#define  CRT_INT_CTRL_KCPU_dc_int_kcpu_routing_en_shift                          (11)
#define  CRT_INT_CTRL_KCPU_tve_int_kcpu_routing_en_shift                         (10)
#define  CRT_INT_CTRL_KCPU_osd_int_kcpu_routing_en_shift                         (9)
#define  CRT_INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en_shift                  (8)
#define  CRT_INT_CTRL_KCPU_dctl_int_kcpu_routing_en_shift                        (7)
#define  CRT_INT_CTRL_KCPU_vbi_int_kcpu_routing_en_shift                         (6)
#define  CRT_INT_CTRL_KCPU_vdec_int_kcpu_routing_en_shift                        (5)
#define  CRT_INT_CTRL_KCPU_if_demod_int_kcpu_routing_en_shift                    (4)
#define  CRT_INT_CTRL_KCPU_dispm_int_kcpu_routing_en_shift                       (3)
#define  CRT_INT_CTRL_KCPU_dispi_int_kcpu_routing_en_shift                       (2)
#define  CRT_INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en_shift                    (1)
#define  CRT_INT_CTRL_KCPU_ddc_int_kcpu_routing_en_shift                         (0)
#define  CRT_INT_CTRL_KCPU_smartcard_int_kcpu_routing_en_mask                    (0x80000000)
#define  CRT_INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en_mask                     (0x40000000)
#define  CRT_INT_CTRL_KCPU_vodma_int_kcpu_routing_en_mask                        (0x20000000)
#define  CRT_INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en_mask                (0x10000000)
#define  CRT_INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en_mask         (0x08000000)
#define  CRT_INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en_mask                 (0x04000000)
#define  CRT_INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en_mask         (0x02000000)
#define  CRT_INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en_mask                 (0x01000000)
#define  CRT_INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en_mask             (0x00800000)
#define  CRT_INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en_mask                  (0x00400000)
#define  CRT_INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en_mask                  (0x00200000)
#define  CRT_INT_CTRL_KCPU_akl_int_kcpu_routing_en_mask                          (0x00100000)
#define  CRT_INT_CTRL_KCPU_usb3_int_kcpu_routing_en_mask                         (0x00080000)
#define  CRT_INT_CTRL_KCPU_otg_int_kcpu_routing_en_mask                          (0x00040000)
#define  CRT_INT_CTRL_KCPU_etn_int_kcpu_routing_en_mask                          (0x00020000)
#define  CRT_INT_CTRL_KCPU_sd_int_kcpu_routing_en_mask                           (0x00010000)
#define  CRT_INT_CTRL_KCPU_dummy1_mask                                            (0x00008000)
#define  CRT_INT_CTRL_KCPU_dummy2_mask                                            (0x00004000)
#define  CRT_INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en_mask                     (0x00002000)
#define  CRT_INT_CTRL_KCPU_dcphy_int_kcpu_routing_en_mask                        (0x00001000)
#define  CRT_INT_CTRL_KCPU_dc_int_kcpu_routing_en_mask                           (0x00000800)
#define  CRT_INT_CTRL_KCPU_tve_int_kcpu_routing_en_mask                          (0x00000400)
#define  CRT_INT_CTRL_KCPU_osd_int_kcpu_routing_en_mask                          (0x00000200)
#define  CRT_INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en_mask                   (0x00000100)
#define  CRT_INT_CTRL_KCPU_dctl_int_kcpu_routing_en_mask                         (0x00000080)
#define  CRT_INT_CTRL_KCPU_vbi_int_kcpu_routing_en_mask                          (0x00000040)
#define  CRT_INT_CTRL_KCPU_vdec_int_kcpu_routing_en_mask                         (0x00000020)
#define  CRT_INT_CTRL_KCPU_if_demod_int_kcpu_routing_en_mask                     (0x00000010)
#define  CRT_INT_CTRL_KCPU_dispm_int_kcpu_routing_en_mask                        (0x00000008)
#define  CRT_INT_CTRL_KCPU_dispi_int_kcpu_routing_en_mask                        (0x00000004)
#define  CRT_INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en_mask                     (0x00000002)
#define  CRT_INT_CTRL_KCPU_ddc_int_kcpu_routing_en_mask                          (0x00000001)
#define  CRT_INT_CTRL_KCPU_smartcard_int_kcpu_routing_en(data)                   (0x80000000&((data)<<31))
#define  CRT_INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en(data)                    (0x40000000&((data)<<30))
#define  CRT_INT_CTRL_KCPU_vodma_int_kcpu_routing_en(data)                       (0x20000000&((data)<<29))
#define  CRT_INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en(data)               (0x10000000&((data)<<28))
#define  CRT_INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en(data)        (0x08000000&((data)<<27))
#define  CRT_INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en(data)                (0x04000000&((data)<<26))
#define  CRT_INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en(data)        (0x02000000&((data)<<25))
#define  CRT_INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en(data)                (0x01000000&((data)<<24))
#define  CRT_INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en(data)            (0x00800000&((data)<<23))
#define  CRT_INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en(data)                 (0x00400000&((data)<<22))
#define  CRT_INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en(data)                 (0x00200000&((data)<<21))
#define  CRT_INT_CTRL_KCPU_akl_int_kcpu_routing_en(data)                         (0x00100000&((data)<<20))
#define  CRT_INT_CTRL_KCPU_usb3_int_kcpu_routing_en(data)                        (0x00080000&((data)<<19))
#define  CRT_INT_CTRL_KCPU_otg_int_kcpu_routing_en(data)                         (0x00040000&((data)<<18))
#define  CRT_INT_CTRL_KCPU_etn_int_kcpu_routing_en(data)                         (0x00020000&((data)<<17))
#define  CRT_INT_CTRL_KCPU_sd_int_kcpu_routing_en(data)                          (0x00010000&((data)<<16))
#define  CRT_INT_CTRL_KCPU_dummy1(data)                                           (0x00008000&((data)<<15))
#define  CRT_INT_CTRL_KCPU_dummy2(data)                                           (0x00004000&((data)<<14))
#define  CRT_INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en(data)                    (0x00002000&((data)<<13))
#define  CRT_INT_CTRL_KCPU_dcphy_int_kcpu_routing_en(data)                       (0x00001000&((data)<<12))
#define  CRT_INT_CTRL_KCPU_dc_int_kcpu_routing_en(data)                          (0x00000800&((data)<<11))
#define  CRT_INT_CTRL_KCPU_tve_int_kcpu_routing_en(data)                         (0x00000400&((data)<<10))
#define  CRT_INT_CTRL_KCPU_osd_int_kcpu_routing_en(data)                         (0x00000200&((data)<<9))
#define  CRT_INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en(data)                  (0x00000100&((data)<<8))
#define  CRT_INT_CTRL_KCPU_dctl_int_kcpu_routing_en(data)                        (0x00000080&((data)<<7))
#define  CRT_INT_CTRL_KCPU_vbi_int_kcpu_routing_en(data)                         (0x00000040&((data)<<6))
#define  CRT_INT_CTRL_KCPU_vdec_int_kcpu_routing_en(data)                        (0x00000020&((data)<<5))
#define  CRT_INT_CTRL_KCPU_if_demod_int_kcpu_routing_en(data)                    (0x00000010&((data)<<4))
#define  CRT_INT_CTRL_KCPU_dispm_int_kcpu_routing_en(data)                       (0x00000008&((data)<<3))
#define  CRT_INT_CTRL_KCPU_dispi_int_kcpu_routing_en(data)                       (0x00000004&((data)<<2))
#define  CRT_INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en(data)                    (0x00000002&((data)<<1))
#define  CRT_INT_CTRL_KCPU_ddc_int_kcpu_routing_en(data)                         (0x00000001&(data))
#define  CRT_INT_CTRL_KCPU_get_smartcard_int_kcpu_routing_en(data)               ((0x80000000&(data))>>31)
#define  CRT_INT_CTRL_KCPU_get_disp2tve_int_kcpu_routing_en(data)                ((0x40000000&(data))>>30)
#define  CRT_INT_CTRL_KCPU_get_vodma_int_kcpu_routing_en(data)                   ((0x20000000&(data))>>29)
#define  CRT_INT_CTRL_KCPU_get_standby_syncp_int_kcpu_routing_en(data)           ((0x10000000&(data))>>28)
#define  CRT_INT_CTRL_KCPU_get_standby_hdmi_clk_det_int_kcpu_routing_en(data)    ((0x08000000&(data))>>27)
#define  CRT_INT_CTRL_KCPU_get_standby_wdog_int_kcpu_routing_en(data)            ((0x04000000&(data))>>26)
#define  CRT_INT_CTRL_KCPU_get_standby_iso_misc_off_int_kcpu_routing_en(data)    ((0x02000000&(data))>>25)
#define  CRT_INT_CTRL_KCPU_get_standby_cbus_int_kcpu_routing_en(data)            ((0x01000000&(data))>>24)
#define  CRT_INT_CTRL_KCPU_get_standby_iso_misc_int_kcpu_routing_en(data)        ((0x00800000&(data))>>23)
#define  CRT_INT_CTRL_KCPU_get_standby_cec_int_kcpu_routing_en(data)             ((0x00400000&(data))>>22)
#define  CRT_INT_CTRL_KCPU_get_standby_rtc_int_kcpu_routing_en(data)             ((0x00200000&(data))>>21)
#define  CRT_INT_CTRL_KCPU_get_akl_int_kcpu_routing_en(data)                     ((0x00100000&(data))>>20)
#define  CRT_INT_CTRL_KCPU_get_usb3_int_kcpu_routing_en(data)                    ((0x00080000&(data))>>19)
#define  CRT_INT_CTRL_KCPU_get_otg_int_kcpu_routing_en(data)                     ((0x00040000&(data))>>18)
#define  CRT_INT_CTRL_KCPU_get_etn_int_kcpu_routing_en(data)                     ((0x00020000&(data))>>17)
#define  CRT_INT_CTRL_KCPU_get_sd_int_kcpu_routing_en(data)                      ((0x00010000&(data))>>16)
#define  CRT_INT_CTRL_KCPU_get_dummy1(data)                                       ((0x00008000&(data))>>15)
#define  CRT_INT_CTRL_KCPU_get_dummy2(data)                                       ((0x00004000&(data))>>14)
#define  CRT_INT_CTRL_KCPU_get_tv_sb_dc_int_kcpu_routing_en(data)                ((0x00002000&(data))>>13)
#define  CRT_INT_CTRL_KCPU_get_dcphy_int_kcpu_routing_en(data)                   ((0x00001000&(data))>>12)
#define  CRT_INT_CTRL_KCPU_get_dc_int_kcpu_routing_en(data)                      ((0x00000800&(data))>>11)
#define  CRT_INT_CTRL_KCPU_get_tve_int_kcpu_routing_en(data)                     ((0x00000400&(data))>>10)
#define  CRT_INT_CTRL_KCPU_get_osd_int_kcpu_routing_en(data)                     ((0x00000200&(data))>>9)
#define  CRT_INT_CTRL_KCPU_get_ultra_zoom_int_kcpu_routing_en(data)              ((0x00000100&(data))>>8)
#define  CRT_INT_CTRL_KCPU_get_dctl_int_kcpu_routing_en(data)                    ((0x00000080&(data))>>7)
#define  CRT_INT_CTRL_KCPU_get_vbi_int_kcpu_routing_en(data)                     ((0x00000040&(data))>>6)
#define  CRT_INT_CTRL_KCPU_get_vdec_int_kcpu_routing_en(data)                    ((0x00000020&(data))>>5)
#define  CRT_INT_CTRL_KCPU_get_if_demod_int_kcpu_routing_en(data)                ((0x00000010&(data))>>4)
#define  CRT_INT_CTRL_KCPU_get_dispm_int_kcpu_routing_en(data)                   ((0x00000008&(data))>>3)
#define  CRT_INT_CTRL_KCPU_get_dispi_int_kcpu_routing_en(data)                   ((0x00000004&(data))>>2)
#define  CRT_INT_CTRL_KCPU_get_apll_dds_int_kcpu_routing_en(data)                ((0x00000002&(data))>>1)
#define  CRT_INT_CTRL_KCPU_get_ddc_int_kcpu_routing_en(data)                     (0x00000001&(data))

#define  SYS_REG_INT_CTRL_MEMC                                                   0x180002A0
#define  SYS_REG_INT_CTRL_MEMC_reg_addr                                          "0xB80002A0"
#define  SYS_REG_INT_CTRL_MEMC_reg                                               0xB80002A0
#define  SYS_REG_INT_CTRL_MEMC_inst_addr                                         "0x0015"
#define  set_SYS_REG_INT_CTRL_MEMC_reg(data)                                     (*((volatile unsigned int*)SYS_REG_INT_CTRL_MEMC_reg)=data)
#define  get_SYS_REG_INT_CTRL_MEMC_reg                                           (*((volatile unsigned int*)SYS_REG_INT_CTRL_MEMC_reg))
#define  SYS_REG_INT_CTRL_MEMC_memc_int_vcpu_routing_en_shift                    (28)
#define  SYS_REG_INT_CTRL_MEMC_dummy_27_shift                                    (27)
#define  SYS_REG_INT_CTRL_MEMC_dummy_26_shift                                    (26)
#define  SYS_REG_INT_CTRL_MEMC_dummy_25_shift                                    (25)
#define  SYS_REG_INT_CTRL_MEMC_memc_int_vcpu2_routing_en_shift                   (24)
#define  SYS_REG_INT_CTRL_MEMC_dummy_23_shift                                    (23)
#define  SYS_REG_INT_CTRL_MEMC_dummy_22_shift                                    (22)
#define  SYS_REG_INT_CTRL_MEMC_dummy_21_shift                                    (21)
#define  SYS_REG_INT_CTRL_MEMC_memc_int_scpu_routing_en_shift                    (20)
#define  SYS_REG_INT_CTRL_MEMC_hdmi_irq_vcpu_routing_en_shift                    (17)
#define  SYS_REG_INT_CTRL_MEMC_hdmi_irq_scpu_routing_en_shift                    (16)
#define  SYS_REG_INT_CTRL_MEMC_memc_int_vcpu_routing_en_mask                     (0x10000000)
#define  SYS_REG_INT_CTRL_MEMC_dummy_27_mask                                     (0x08000000)
#define  SYS_REG_INT_CTRL_MEMC_dummy_26_mask                                     (0x04000000)
#define  SYS_REG_INT_CTRL_MEMC_dummy_25_mask                                     (0x02000000)
#define  SYS_REG_INT_CTRL_MEMC_memc_int_vcpu2_routing_en_mask                    (0x01000000)
#define  SYS_REG_INT_CTRL_MEMC_dummy_23_mask                                     (0x00800000)
#define  SYS_REG_INT_CTRL_MEMC_dummy_22_mask                                     (0x00400000)
#define  SYS_REG_INT_CTRL_MEMC_dummy_21_mask                                     (0x00200000)
#define  SYS_REG_INT_CTRL_MEMC_memc_int_scpu_routing_en_mask                     (0x00100000)
#define  SYS_REG_INT_CTRL_MEMC_hdmi_irq_vcpu_routing_en_mask                     (0x00020000)
#define  SYS_REG_INT_CTRL_MEMC_hdmi_irq_scpu_routing_en_mask                     (0x00010000)
#define  SYS_REG_INT_CTRL_MEMC_memc_int_vcpu_routing_en(data)                    (0x10000000&((data)<<28))
#define  SYS_REG_INT_CTRL_MEMC_dummy_27(data)                                    (0x08000000&((data)<<27))
#define  SYS_REG_INT_CTRL_MEMC_dummy_26(data)                                    (0x04000000&((data)<<26))
#define  SYS_REG_INT_CTRL_MEMC_dummy_25(data)                                    (0x02000000&((data)<<25))
#define  SYS_REG_INT_CTRL_MEMC_memc_int_vcpu2_routing_en(data)                   (0x01000000&((data)<<24))
#define  SYS_REG_INT_CTRL_MEMC_dummy_23(data)                                    (0x00800000&((data)<<23))
#define  SYS_REG_INT_CTRL_MEMC_dummy_22(data)                                    (0x00400000&((data)<<22))
#define  SYS_REG_INT_CTRL_MEMC_dummy_21(data)                                    (0x00200000&((data)<<21))
#define  SYS_REG_INT_CTRL_MEMC_memc_int_scpu_routing_en(data)                    (0x00100000&((data)<<20))
#define  SYS_REG_INT_CTRL_MEMC_hdmi_irq_vcpu_routing_en(data)                    (0x00020000&((data)<<17))
#define  SYS_REG_INT_CTRL_MEMC_hdmi_irq_scpu_routing_en(data)                    (0x00010000&((data)<<16))
#define  SYS_REG_INT_CTRL_MEMC_get_memc_int_vcpu_routing_en(data)                ((0x10000000&(data))>>28)
#define  SYS_REG_INT_CTRL_MEMC_get_dummy_27(data)                                ((0x08000000&(data))>>27)
#define  SYS_REG_INT_CTRL_MEMC_get_dummy_26(data)                                ((0x04000000&(data))>>26)
#define  SYS_REG_INT_CTRL_MEMC_get_dummy_25(data)                                ((0x02000000&(data))>>25)
#define  SYS_REG_INT_CTRL_MEMC_get_memc_int_vcpu2_routing_en(data)               ((0x01000000&(data))>>24)
#define  SYS_REG_INT_CTRL_MEMC_get_dummy_23(data)                                ((0x00800000&(data))>>23)
#define  SYS_REG_INT_CTRL_MEMC_get_dummy_22(data)                                ((0x00400000&(data))>>22)
#define  SYS_REG_INT_CTRL_MEMC_get_dummy_21(data)                                ((0x00200000&(data))>>21)
#define  SYS_REG_INT_CTRL_MEMC_get_memc_int_scpu_routing_en(data)                ((0x00100000&(data))>>20)
#define  SYS_REG_INT_CTRL_MEMC_get_hdmi_irq_vcpu_routing_en(data)                ((0x00020000&(data))>>17)
#define  SYS_REG_INT_CTRL_MEMC_get_hdmi_irq_scpu_routing_en(data)                ((0x00010000&(data))>>16)

#define  CRT_SS_MAINIP_C30_7T_RHVT_0                                             0x180002B0
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_reg_addr                                    "0xB80002B0"
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_reg                                         0xB80002B0
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_inst_addr                                   "0x001F"
#define  set_CRT_SS_MAINIP_C30_7T_RHVT_0_reg(data)                               (*((volatile unsigned int*)CRT_SS_MAINIP_C30_7T_RHVT_0_reg)=data)
#define  get_CRT_SS_MAINIP_C30_7T_RHVT_0_reg                                     (*((volatile unsigned int*)CRT_SS_MAINIP_C30_7T_RHVT_0_reg))
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_dss_rst_n_shift              (31)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_ro_sel_shift                 (25)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_wire_sel_shift               (24)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_ready_shift                  (20)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_count_out_shift              (0)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_dss_rst_n_mask               (0x80000000)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_ro_sel_mask                  (0x0E000000)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_wire_sel_mask                (0x01000000)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_ready_mask                   (0x00100000)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_count_out_mask               (0x000FFFFF)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_dss_rst_n(data)              (0x80000000&((data)<<31))
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_ro_sel(data)                 (0x0E000000&((data)<<25))
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_wire_sel(data)               (0x01000000&((data)<<24))
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_ready(data)                  (0x00100000&((data)<<20))
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_main_ip_c30_7t_count_out(data)              (0x000FFFFF&(data))
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_get_main_ip_c30_7t_dss_rst_n(data)          ((0x80000000&(data))>>31)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_get_main_ip_c30_7t_ro_sel(data)             ((0x0E000000&(data))>>25)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_get_main_ip_c30_7t_wire_sel(data)           ((0x01000000&(data))>>24)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_get_main_ip_c30_7t_ready(data)              ((0x00100000&(data))>>20)
#define  CRT_SS_MAINIP_C30_7T_RHVT_0_get_main_ip_c30_7t_count_out(data)          (0x000FFFFF&(data))

#define  CRT_SS_MAINIP_C30_7T_RHVT_1                                             0x180002B4
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_reg_addr                                    "0xB80002B4"
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_reg                                         0xB80002B4
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_inst_addr                                   "0x0020"
#define  set_CRT_SS_MAINIP_C30_7T_RHVT_1_reg(data)                               (*((volatile unsigned int*)CRT_SS_MAINIP_C30_7T_RHVT_1_reg)=data)
#define  get_CRT_SS_MAINIP_C30_7T_RHVT_1_reg                                     (*((volatile unsigned int*)CRT_SS_MAINIP_C30_7T_RHVT_1_reg))
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_speed_en_shift               (21)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_wsort_go_shift               (20)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_data_in_shift                (0)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_speed_en_mask                (0x00200000)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_wsort_go_mask                (0x00100000)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_data_in_mask                 (0x000FFFFF)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_speed_en(data)               (0x00200000&((data)<<21))
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_wsort_go(data)               (0x00100000&((data)<<20))
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_main_ip_c30_7t_data_in(data)                (0x000FFFFF&(data))
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_get_main_ip_c30_7t_speed_en(data)           ((0x00200000&(data))>>21)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_get_main_ip_c30_7t_wsort_go(data)           ((0x00100000&(data))>>20)
#define  CRT_SS_MAINIP_C30_7T_RHVT_1_get_main_ip_c30_7t_data_in(data)            (0x000FFFFF&(data))

#define  CRT_SS_MAINIP_C30_7T_RHVT_2                                             0x180002B8
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_reg_addr                                    "0xB80002B8"
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_reg                                         0xB80002B8
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_inst_addr                                   "0x0021"
#define  set_CRT_SS_MAINIP_C30_7T_RHVT_2_reg(data)                               (*((volatile unsigned int*)CRT_SS_MAINIP_C30_7T_RHVT_2_reg)=data)
#define  get_CRT_SS_MAINIP_C30_7T_RHVT_2_reg                                     (*((volatile unsigned int*)CRT_SS_MAINIP_C30_7T_RHVT_2_reg))
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_main_ip_c30_7t_dbgo_shift                   (0)
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_main_ip_c30_7t_dbgo_mask                    (0x0000FFFF)
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_main_ip_c30_7t_dbgo(data)                   (0x0000FFFF&(data))
#define  CRT_SS_MAINIP_C30_7T_RHVT_2_get_main_ip_c30_7t_dbgo(data)               (0x0000FFFF&(data))

#define  CRT_SS_DISPD_C35_9P5T_RHVT_0                                            0x180002C0
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_reg_addr                                   "0xB80002C0"
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_reg                                        0xB80002C0
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_inst_addr                                  "0x0022"
#define  set_CRT_SS_DISPD_C35_9P5T_RHVT_0_reg(data)                              (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RHVT_0_reg)=data)
#define  get_CRT_SS_DISPD_C35_9P5T_RHVT_0_reg                                    (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RHVT_0_reg))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_dss_rst_n_shift             (31)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_ro_sel_shift                (25)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_wire_sel_shift              (24)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_ready_shift                 (20)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_count_out_shift             (0)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_dss_rst_n_mask              (0x80000000)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_ro_sel_mask                 (0x0E000000)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_wire_sel_mask               (0x01000000)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_ready_mask                  (0x00100000)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_count_out_mask              (0x000FFFFF)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_dss_rst_n(data)             (0x80000000&((data)<<31))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_ro_sel(data)                (0x0E000000&((data)<<25))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_wire_sel(data)              (0x01000000&((data)<<24))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_ready(data)                 (0x00100000&((data)<<20))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_dispd_c35_9p5t_count_out(data)             (0x000FFFFF&(data))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_get_dispd_c35_9p5t_dss_rst_n(data)         ((0x80000000&(data))>>31)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_get_dispd_c35_9p5t_ro_sel(data)            ((0x0E000000&(data))>>25)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_get_dispd_c35_9p5t_wire_sel(data)          ((0x01000000&(data))>>24)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_get_dispd_c35_9p5t_ready(data)             ((0x00100000&(data))>>20)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_0_get_dispd_c35_9p5t_count_out(data)         (0x000FFFFF&(data))

#define  CRT_SS_DISPD_C35_9P5T_RHVT_1                                            0x180002C4
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_reg_addr                                   "0xB80002C4"
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_reg                                        0xB80002C4
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_inst_addr                                  "0x0023"
#define  set_CRT_SS_DISPD_C35_9P5T_RHVT_1_reg(data)                              (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RHVT_1_reg)=data)
#define  get_CRT_SS_DISPD_C35_9P5T_RHVT_1_reg                                    (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RHVT_1_reg))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_speed_en_shift              (21)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_wsort_go_shift              (20)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_data_in_shift               (0)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_speed_en_mask               (0x00200000)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_wsort_go_mask               (0x00100000)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_data_in_mask                (0x000FFFFF)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_speed_en(data)              (0x00200000&((data)<<21))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_wsort_go(data)              (0x00100000&((data)<<20))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_dispd_c35_9p5t_data_in(data)               (0x000FFFFF&(data))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_get_dispd_c35_9p5t_speed_en(data)          ((0x00200000&(data))>>21)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_get_dispd_c35_9p5t_wsort_go(data)          ((0x00100000&(data))>>20)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_1_get_dispd_c35_9p5t_data_in(data)           (0x000FFFFF&(data))

#define  CRT_SS_DISPD_C35_9P5T_RHVT_2                                            0x180002C8
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_reg_addr                                   "0xB80002C8"
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_reg                                        0xB80002C8
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_inst_addr                                  "0x0024"
#define  set_CRT_SS_DISPD_C35_9P5T_RHVT_2_reg(data)                              (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RHVT_2_reg)=data)
#define  get_CRT_SS_DISPD_C35_9P5T_RHVT_2_reg                                    (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RHVT_2_reg))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_dispd_c35_9p5t_dbgo_shift                  (0)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_dispd_c35_9p5t_dbgo_mask                   (0x0000FFFF)
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_dispd_c35_9p5t_dbgo(data)                  (0x0000FFFF&(data))
#define  CRT_SS_DISPD_C35_9P5T_RHVT_2_get_dispd_c35_9p5t_dbgo(data)              (0x0000FFFF&(data))

#define  CRT_SS_DISPD_C31_9P5T_RLVT_0                                            0x180002D0
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_reg_addr                                   "0xB80002D0"
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_reg                                        0xB80002D0
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_inst_addr                                  "0x0025"
#define  set_CRT_SS_DISPD_C31_9P5T_RLVT_0_reg(data)                              (*((volatile unsigned int*)CRT_SS_DISPD_C31_9P5T_RLVT_0_reg)=data)
#define  get_CRT_SS_DISPD_C31_9P5T_RLVT_0_reg                                    (*((volatile unsigned int*)CRT_SS_DISPD_C31_9P5T_RLVT_0_reg))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_dss_rst_n_shift             (31)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_ro_sel_shift                (25)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_wire_sel_shift              (24)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_ready_shift                 (20)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_count_out_shift             (0)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_dss_rst_n_mask              (0x80000000)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_ro_sel_mask                 (0x0E000000)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_wire_sel_mask               (0x01000000)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_ready_mask                  (0x00100000)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_count_out_mask              (0x000FFFFF)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_dss_rst_n(data)             (0x80000000&((data)<<31))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_ro_sel(data)                (0x0E000000&((data)<<25))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_wire_sel(data)              (0x01000000&((data)<<24))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_ready(data)                 (0x00100000&((data)<<20))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_dispd_c31_9p5t_count_out(data)             (0x000FFFFF&(data))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_get_dispd_c31_9p5t_dss_rst_n(data)         ((0x80000000&(data))>>31)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_get_dispd_c31_9p5t_ro_sel(data)            ((0x0E000000&(data))>>25)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_get_dispd_c31_9p5t_wire_sel(data)          ((0x01000000&(data))>>24)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_get_dispd_c31_9p5t_ready(data)             ((0x00100000&(data))>>20)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_0_get_dispd_c31_9p5t_count_out(data)         (0x000FFFFF&(data))

#define  CRT_SS_DISPD_C31_9P5T_RLVT_1                                            0x180002D4
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_reg_addr                                   "0xB80002D4"
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_reg                                        0xB80002D4
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_inst_addr                                  "0x0026"
#define  set_CRT_SS_DISPD_C31_9P5T_RLVT_1_reg(data)                              (*((volatile unsigned int*)CRT_SS_DISPD_C31_9P5T_RLVT_1_reg)=data)
#define  get_CRT_SS_DISPD_C31_9P5T_RLVT_1_reg                                    (*((volatile unsigned int*)CRT_SS_DISPD_C31_9P5T_RLVT_1_reg))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_speed_en_shift              (21)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_wsort_go_shift              (20)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_data_in_shift               (0)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_speed_en_mask               (0x00200000)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_wsort_go_mask               (0x00100000)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_data_in_mask                (0x000FFFFF)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_speed_en(data)              (0x00200000&((data)<<21))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_wsort_go(data)              (0x00100000&((data)<<20))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_dispd_c31_9p5t_data_in(data)               (0x000FFFFF&(data))
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_get_dispd_c31_9p5t_speed_en(data)          ((0x00200000&(data))>>21)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_get_dispd_c31_9p5t_wsort_go(data)          ((0x00100000&(data))>>20)
#define  CRT_SS_DISPD_C31_9P5T_RLVT_1_get_dispd_c31_9p5t_data_in(data)           (0x000FFFFF&(data))

#define  CRT_SS_DISPD_C35_9P5T_RLVT_2                                            0x180002D8
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_reg_addr                                   "0xB80002D8"
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_reg                                        0xB80002D8
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_inst_addr                                  "0x0027"
#define  set_CRT_SS_DISPD_C35_9P5T_RLVT_2_reg(data)                              (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RLVT_2_reg)=data)
#define  get_CRT_SS_DISPD_C35_9P5T_RLVT_2_reg                                    (*((volatile unsigned int*)CRT_SS_DISPD_C35_9P5T_RLVT_2_reg))
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_dispd_c31_9p5t_dbgo_shift                  (0)
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_dispd_c31_9p5t_dbgo_mask                   (0x0000FFFF)
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_dispd_c31_9p5t_dbgo(data)                  (0x0000FFFF&(data))
#define  CRT_SS_DISPD_C35_9P5T_RLVT_2_get_dispd_c31_9p5t_dbgo(data)              (0x0000FFFF&(data))

#define  CRT_SS_ACPU_C35_9P5T_RHVT_0                                             0x180002E0
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_reg_addr                                    "0xB80002E0"
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_reg                                         0xB80002E0
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_inst_addr                                   "0x0028"
#define  set_CRT_SS_ACPU_C35_9P5T_RHVT_0_reg(data)                               (*((volatile unsigned int*)CRT_SS_ACPU_C35_9P5T_RHVT_0_reg)=data)
#define  get_CRT_SS_ACPU_C35_9P5T_RHVT_0_reg                                     (*((volatile unsigned int*)CRT_SS_ACPU_C35_9P5T_RHVT_0_reg))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_dss_rst_n_shift               (31)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_ro_sel_shift                  (25)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_wire_sel_shift                (24)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_ready_shift                   (20)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_count_out_shift               (0)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_dss_rst_n_mask                (0x80000000)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_ro_sel_mask                   (0x0E000000)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_wire_sel_mask                 (0x01000000)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_ready_mask                    (0x00100000)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_count_out_mask                (0x000FFFFF)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_dss_rst_n(data)               (0x80000000&((data)<<31))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_ro_sel(data)                  (0x0E000000&((data)<<25))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_wire_sel(data)                (0x01000000&((data)<<24))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_ready(data)                   (0x00100000&((data)<<20))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_acpu_c35_9p5t_count_out(data)               (0x000FFFFF&(data))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_get_acpu_c35_9p5t_dss_rst_n(data)           ((0x80000000&(data))>>31)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_get_acpu_c35_9p5t_ro_sel(data)              ((0x0E000000&(data))>>25)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_get_acpu_c35_9p5t_wire_sel(data)            ((0x01000000&(data))>>24)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_get_acpu_c35_9p5t_ready(data)               ((0x00100000&(data))>>20)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_0_get_acpu_c35_9p5t_count_out(data)           (0x000FFFFF&(data))

#define  CRT_SS_ACPU_C35_9P5T_RHVT_1                                             0x180002E4
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_reg_addr                                    "0xB80002E4"
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_reg                                         0xB80002E4
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_inst_addr                                   "0x0029"
#define  set_CRT_SS_ACPU_C35_9P5T_RHVT_1_reg(data)                               (*((volatile unsigned int*)CRT_SS_ACPU_C35_9P5T_RHVT_1_reg)=data)
#define  get_CRT_SS_ACPU_C35_9P5T_RHVT_1_reg                                     (*((volatile unsigned int*)CRT_SS_ACPU_C35_9P5T_RHVT_1_reg))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_speed_en_shift                (21)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_wsort_go_shift                (20)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_data_in_shift                 (0)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_speed_en_mask                 (0x00200000)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_wsort_go_mask                 (0x00100000)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_data_in_mask                  (0x000FFFFF)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_speed_en(data)                (0x00200000&((data)<<21))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_wsort_go(data)                (0x00100000&((data)<<20))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_acpu_c35_9p5t_data_in(data)                 (0x000FFFFF&(data))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_get_acpu_c35_9p5t_speed_en(data)            ((0x00200000&(data))>>21)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_get_acpu_c35_9p5t_wsort_go(data)            ((0x00100000&(data))>>20)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_1_get_acpu_c35_9p5t_data_in(data)             (0x000FFFFF&(data))

#define  CRT_SS_ACPU_C35_9P5T_RHVT_2                                             0x180002E8
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_reg_addr                                    "0xB80002E8"
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_reg                                         0xB80002E8
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_inst_addr                                   "0x002A"
#define  set_CRT_SS_ACPU_C35_9P5T_RHVT_2_reg(data)                               (*((volatile unsigned int*)CRT_SS_ACPU_C35_9P5T_RHVT_2_reg)=data)
#define  get_CRT_SS_ACPU_C35_9P5T_RHVT_2_reg                                     (*((volatile unsigned int*)CRT_SS_ACPU_C35_9P5T_RHVT_2_reg))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_acpu_c35_9p5t_dbgo_shift                    (0)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_acpu_c35_9p5t_dbgo_mask                     (0x0000FFFF)
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_acpu_c35_9p5t_dbgo(data)                    (0x0000FFFF&(data))
#define  CRT_SS_ACPU_C35_9P5T_RHVT_2_get_acpu_c35_9p5t_dbgo(data)                (0x0000FFFF&(data))

#define  CRT_VOLTAGE_STROBE_CTRL                                                 0x18000300
#define  CRT_VOLTAGE_STROBE_CTRL_reg_addr                                        "0xB8000300"
#define  CRT_VOLTAGE_STROBE_CTRL_reg                                             0xB8000300
#define  CRT_VOLTAGE_STROBE_CTRL_inst_addr                                       "0x002B"
#define  set_CRT_VOLTAGE_STROBE_CTRL_reg(data)                                   (*((volatile unsigned int*)CRT_VOLTAGE_STROBE_CTRL_reg)=data)
#define  get_CRT_VOLTAGE_STROBE_CTRL_reg                                         (*((volatile unsigned int*)CRT_VOLTAGE_STROBE_CTRL_reg))
#define  CRT_VOLTAGE_STROBE_CTRL_main_voltage_strobe_en_shift                    (4)
#define  CRT_VOLTAGE_STROBE_CTRL_demod_voltage_strobe_en_shift                   (0)
#define  CRT_VOLTAGE_STROBE_CTRL_main_voltage_strobe_en_mask                     (0x00000010)
#define  CRT_VOLTAGE_STROBE_CTRL_demod_voltage_strobe_en_mask                    (0x00000001)
#define  CRT_VOLTAGE_STROBE_CTRL_main_voltage_strobe_en(data)                    (0x00000010&((data)<<4))
#define  CRT_VOLTAGE_STROBE_CTRL_demod_voltage_strobe_en(data)                   (0x00000001&(data))
#define  CRT_VOLTAGE_STROBE_CTRL_get_main_voltage_strobe_en(data)                ((0x00000010&(data))>>4)
#define  CRT_VOLTAGE_STROBE_CTRL_get_demod_voltage_strobe_en(data)               (0x00000001&(data))

#define  CRT_SC_DEBUG_0                                                          0x18000310
#define  CRT_SC_DEBUG_0_reg_addr                                                 "0xB8000310"
#define  CRT_SC_DEBUG_0_reg                                                      0xB8000310
#define  CRT_SC_DEBUG_0_inst_addr                                                "0x002C"
#define  set_CRT_SC_DEBUG_0_reg(data)                                            (*((volatile unsigned int*)CRT_SC_DEBUG_0_reg)=data)
#define  get_CRT_SC_DEBUG_0_reg                                                  (*((volatile unsigned int*)CRT_SC_DEBUG_0_reg))
#define  CRT_SC_DEBUG_0_dbg0_div_sel_shift                                       (16)
#define  CRT_SC_DEBUG_0_top_ssc_dbg_sel_shift                                    (8)
#define  CRT_SC_DEBUG_0_crt_dbg_sel_shift                                        (0)
#define  CRT_SC_DEBUG_0_dbg0_div_sel_mask                                        (0x00030000)
#define  CRT_SC_DEBUG_0_top_ssc_dbg_sel_mask                                     (0x00000F00)
#define  CRT_SC_DEBUG_0_crt_dbg_sel_mask                                         (0x000000FF)
#define  CRT_SC_DEBUG_0_dbg0_div_sel(data)                                       (0x00030000&((data)<<16))
#define  CRT_SC_DEBUG_0_top_ssc_dbg_sel(data)                                    (0x00000F00&((data)<<8))
#define  CRT_SC_DEBUG_0_crt_dbg_sel(data)                                        (0x000000FF&(data))
#define  CRT_SC_DEBUG_0_get_dbg0_div_sel(data)                                   ((0x00030000&(data))>>16)
#define  CRT_SC_DEBUG_0_get_top_ssc_dbg_sel(data)                                ((0x00000F00&(data))>>8)
#define  CRT_SC_DEBUG_0_get_crt_dbg_sel(data)                                    (0x000000FF&(data))

#define  CRT_SYS_PLL_DISPB_SD1                                                   0x18000350
#define  CRT_SYS_PLL_DISPB_SD1_reg_addr                                          "0xB8000350"
#define  CRT_SYS_PLL_DISPB_SD1_reg                                               0xB8000350
#define  CRT_SYS_PLL_DISPB_SD1_inst_addr                                         "0x002D"
#define  set_CRT_SYS_PLL_DISPB_SD1_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD1_reg)=data)
#define  get_CRT_SYS_PLL_DISPB_SD1_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD1_reg))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_n_shift                                   (30)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_ip_shift                                  (20)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_rs_shift                                  (17)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_cs_shift                                  (15)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_cp_shift                                  (13)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_o_shift                                   (4)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_wdmode_shift                              (0)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_n_mask                                    (0xC0000000)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_ip_mask                                   (0x00F00000)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_rs_mask                                   (0x000E0000)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_cs_mask                                   (0x00018000)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_cp_mask                                   (0x00006000)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_o_mask                                    (0x00000030)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_wdmode_mask                               (0x00000003)
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_n(data)                                   (0xC0000000&((data)<<30))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_ip(data)                                  (0x00F00000&((data)<<20))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_rs(data)                                  (0x000E0000&((data)<<17))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_cs(data)                                  (0x00018000&((data)<<15))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_cp(data)                                  (0x00006000&((data)<<13))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_o(data)                                   (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_DISPB_SD1_pllddsb_wdmode(data)                              (0x00000003&(data))
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_n(data)                               ((0xC0000000&(data))>>30)
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_ip(data)                              ((0x00F00000&(data))>>20)
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_rs(data)                              ((0x000E0000&(data))>>17)
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_cs(data)                              ((0x00018000&(data))>>15)
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_cp(data)                              ((0x00006000&(data))>>13)
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_o(data)                               ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_DISPB_SD1_get_pllddsb_wdmode(data)                          (0x00000003&(data))

#define  CRT_SYS_PLL_DISPB_SD2                                                   0x18000354
#define  CRT_SYS_PLL_DISPB_SD2_reg_addr                                          "0xB8000354"
#define  CRT_SYS_PLL_DISPB_SD2_reg                                               0xB8000354
#define  CRT_SYS_PLL_DISPB_SD2_inst_addr                                         "0x002E"
#define  set_CRT_SYS_PLL_DISPB_SD2_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD2_reg)=data)
#define  get_CRT_SYS_PLL_DISPB_SD2_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD2_reg))
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_fcode_shift                               (16)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_ncode_shift                               (8)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_oeb_shift                                 (2)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_rstb_shift                                (1)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_pow_shift                                 (0)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_fcode_mask                                (0x07FF0000)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_ncode_mask                                (0x0000FF00)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_oeb_mask                                  (0x00000004)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_rstb_mask                                 (0x00000002)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_pow_mask                                  (0x00000001)
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_fcode(data)                               (0x07FF0000&((data)<<16))
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_ncode(data)                               (0x0000FF00&((data)<<8))
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_oeb(data)                                 (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_rstb(data)                                (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DISPB_SD2_pllddsb_pow(data)                                 (0x00000001&(data))
#define  CRT_SYS_PLL_DISPB_SD2_get_pllddsb_fcode(data)                           ((0x07FF0000&(data))>>16)
#define  CRT_SYS_PLL_DISPB_SD2_get_pllddsb_ncode(data)                           ((0x0000FF00&(data))>>8)
#define  CRT_SYS_PLL_DISPB_SD2_get_pllddsb_oeb(data)                             ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DISPB_SD2_get_pllddsb_rstb(data)                            ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DISPB_SD2_get_pllddsb_pow(data)                             (0x00000001&(data))

#define  CRT_SYS_PLL_DISPB_SD3                                                   0x18000358
#define  CRT_SYS_PLL_DISPB_SD3_reg_addr                                          "0xB8000358"
#define  CRT_SYS_PLL_DISPB_SD3_reg                                               0xB8000358
#define  CRT_SYS_PLL_DISPB_SD3_inst_addr                                         "0x002F"
#define  set_CRT_SYS_PLL_DISPB_SD3_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD3_reg)=data)
#define  get_CRT_SYS_PLL_DISPB_SD3_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD3_reg))
#define  CRT_SYS_PLL_DISPB_SD3_dummy1_shift                                       (25)
#define  CRT_SYS_PLL_DISPB_SD3_dummy2_shift                                       (24)
#define  CRT_SYS_PLL_DISPB_SD3_dummy3_shift                                       (23)
#define  CRT_SYS_PLL_DISPB_SD3_dummy4_shift                                       (22)
#define  CRT_SYS_PLL_DISPB_SD3_dummy5_shift                                       (21)
#define  CRT_SYS_PLL_DISPB_SD3_dummy6_shift                                       (20)
#define  CRT_SYS_PLL_DISPB_SD3_dummy7_shift                                       (19)
#define  CRT_SYS_PLL_DISPB_SD3_dummy8_shift                                       (18)
#define  CRT_SYS_PLL_DISPB_SD3_dummy9_shift                                       (17)
#define  CRT_SYS_PLL_DISPB_SD3_dummy10_shift                                       (16)
#define  CRT_SYS_PLL_DISPB_SD3_dummy11_shift                                       (15)
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_vcorb_shift                               (14)
#define  CRT_SYS_PLL_DISPB_SD3_dummy12_shift                                       (13)
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_tst_shift                                 (12)
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_pstst_shift                               (11)
#define  CRT_SYS_PLL_DISPB_SD3_dummy13_shift                                       (10)
#define  CRT_SYS_PLL_DISPB_SD3_dummy1_mask                                        (0x1E000000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy2_mask                                        (0x01000000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy3_mask                                        (0x00800000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy4_mask                                        (0x00400000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy5_mask                                        (0x00200000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy6_mask                                        (0x00100000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy7_mask                                        (0x00080000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy8_mask                                        (0x00040000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy9_mask                                        (0x00020000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy10_mask                                        (0x00010000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy11_mask                                        (0x00008000)
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_vcorb_mask                                (0x00004000)
#define  CRT_SYS_PLL_DISPB_SD3_dummy12_mask                                        (0x00002000)
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_tst_mask                                  (0x00001000)
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_pstst_mask                                (0x00000800)
#define  CRT_SYS_PLL_DISPB_SD3_dummy13_mask                                        (0x00000400)
#define  CRT_SYS_PLL_DISPB_SD3_dummy1(data)                                       (0x1E000000&((data)<<25))
#define  CRT_SYS_PLL_DISPB_SD3_dummy2(data)                                       (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_DISPB_SD3_dummy3(data)                                       (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DISPB_SD3_dummy4(data)                                       (0x00400000&((data)<<22))
#define  CRT_SYS_PLL_DISPB_SD3_dummy5(data)                                       (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_DISPB_SD3_dummy6(data)                                       (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_DISPB_SD3_dummy7(data)                                       (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DISPB_SD3_dummy8(data)                                       (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_DISPB_SD3_dummy9(data)                                       (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DISPB_SD3_dummy10(data)                                       (0x00010000&((data)<<16))
#define  CRT_SYS_PLL_DISPB_SD3_dummy11(data)                                       (0x00008000&((data)<<15))
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_vcorb(data)                               (0x00004000&((data)<<14))
#define  CRT_SYS_PLL_DISPB_SD3_dummy12(data)                                       (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_tst(data)                                 (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_DISPB_SD3_pllddsb_pstst(data)                               (0x00000800&((data)<<11))
#define  CRT_SYS_PLL_DISPB_SD3_dummy13(data)                                       (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy1(data)                                   ((0x1E000000&(data))>>25)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy2(data)                                   ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy3(data)                                   ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy4(data)                                   ((0x00400000&(data))>>22)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy5(data)                                   ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy6(data)                                   ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy7(data)                                   ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy8(data)                                   ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy9(data)                                   ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy10(data)                                   ((0x00010000&(data))>>16)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy11(data)                                   ((0x00008000&(data))>>15)
#define  CRT_SYS_PLL_DISPB_SD3_get_pllddsb_vcorb(data)                           ((0x00004000&(data))>>14)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy12(data)                                   ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_DISPB_SD3_get_pllddsb_tst(data)                             ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_DISPB_SD3_get_pllddsb_pstst(data)                           ((0x00000800&(data))>>11)
#define  CRT_SYS_PLL_DISPB_SD3_get_dummy13(data)                                   ((0x00000400&(data))>>10)

#define  CRT_SYS_PLL_DISPB_SD4                                                   0x1800035C
#define  CRT_SYS_PLL_DISPB_SD4_reg_addr                                          "0xB800035C"
#define  CRT_SYS_PLL_DISPB_SD4_reg                                               0xB800035C
#define  CRT_SYS_PLL_DISPB_SD4_inst_addr                                         "0x0030"
#define  set_CRT_SYS_PLL_DISPB_SD4_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD4_reg)=data)
#define  get_CRT_SYS_PLL_DISPB_SD4_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPB_SD4_reg))
#define  CRT_SYS_PLL_DISPB_SD4_dummy1_shift                                       (30)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_fupdn_shift                               (29)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_div_shift                                 (28)
#define  CRT_SYS_PLL_DISPB_SD4_dummy2_shift                                       (27)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_tst_shift                                 (26)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_psen_shift                                (25)
#define  CRT_SYS_PLL_DISPB_SD4_dummy3_shift                                       (24)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_fupdn_shift                               (23)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_div_shift                                 (22)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_tst_shift                                 (21)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_psen_shift                                (20)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_oeb_shift                                 (3)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_rstb_shift                                (2)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_oeb_shift                                 (1)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_rstb_shift                                (0)
#define  CRT_SYS_PLL_DISPB_SD4_dummy1_mask                                        (0x40000000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_fupdn_mask                                (0x20000000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_div_mask                                  (0x10000000)
#define  CRT_SYS_PLL_DISPB_SD4_dummy2_mask                                        (0x08000000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_tst_mask                                  (0x04000000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_psen_mask                                 (0x02000000)
#define  CRT_SYS_PLL_DISPB_SD4_dummy3_mask                                        (0x01000000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_fupdn_mask                                (0x00800000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_div_mask                                  (0x00400000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_tst_mask                                  (0x00200000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_psen_mask                                 (0x00100000)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_oeb_mask                                  (0x00000008)
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_rstb_mask                                 (0x00000004)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_oeb_mask                                  (0x00000002)
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_rstb_mask                                 (0x00000001)
#define  CRT_SYS_PLL_DISPB_SD4_dummy1(data)                                       (0x40000000&((data)<<30))
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_fupdn(data)                               (0x20000000&((data)<<29))
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_div(data)                                 (0x10000000&((data)<<28))
#define  CRT_SYS_PLL_DISPB_SD4_dummy2(data)                                       (0x08000000&((data)<<27))
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_tst(data)                                 (0x04000000&((data)<<26))
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_psen(data)                                (0x02000000&((data)<<25))
#define  CRT_SYS_PLL_DISPB_SD4_dummy3(data)                                       (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_fupdn(data)                               (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_div(data)                                 (0x00400000&((data)<<22))
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_tst(data)                                 (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_psen(data)                                (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_oeb(data)                                 (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_DISPB_SD4_psaud1b_rstb(data)                                (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_oeb(data)                                 (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DISPB_SD4_psaud2b_rstb(data)                                (0x00000001&(data))
#define  CRT_SYS_PLL_DISPB_SD4_get_dummy1(data)                                   ((0x40000000&(data))>>30)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud1b_fupdn(data)                           ((0x20000000&(data))>>29)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud1b_div(data)                             ((0x10000000&(data))>>28)
#define  CRT_SYS_PLL_DISPB_SD4_get_dummy2(data)                                   ((0x08000000&(data))>>27)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud1b_tst(data)                             ((0x04000000&(data))>>26)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud1b_psen(data)                            ((0x02000000&(data))>>25)
#define  CRT_SYS_PLL_DISPB_SD4_get_dummy3(data)                                   ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud2b_fupdn(data)                           ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud2b_div(data)                             ((0x00400000&(data))>>22)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud2b_tst(data)                             ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud2b_psen(data)                            ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud1b_oeb(data)                             ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud1b_rstb(data)                            ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud2b_oeb(data)                             ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DISPB_SD4_get_psaud2b_rstb(data)                            (0x00000001&(data))

#define  CRT_SYS_DVFS_DDSB                                                       0x18000360
#define  CRT_SYS_DVFS_DDSB_reg_addr                                              "0xB8000360"
#define  CRT_SYS_DVFS_DDSB_reg                                                   0xB8000360
#define  CRT_SYS_DVFS_DDSB_inst_addr                                             "0x0031"
#define  set_CRT_SYS_DVFS_DDSB_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_DVFS_DDSB_reg)=data)
#define  get_CRT_SYS_DVFS_DDSB_reg                                               (*((volatile unsigned int*)CRT_SYS_DVFS_DDSB_reg))
#define  CRT_SYS_DVFS_DDSB_pllddsb_bypass_pi_shift                               (31)
#define  CRT_SYS_DVFS_DDSB_pllddsb_en_pi_debug_shift                             (30)
#define  CRT_SYS_DVFS_DDSB_pllddsb_hs_oc_stop_shift                              (28)
#define  CRT_SYS_DVFS_DDSB_pllddsb_pi_cur_sel_shift                              (26)
#define  CRT_SYS_DVFS_DDSB_pllddsb_sel_oc_mode_shift                             (24)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_done_delay_shift                           (16)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_step_shift                                 (4)
#define  CRT_SYS_DVFS_DDSB_pllddsb_sdm_order_shift                               (2)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_done_shift                                 (1)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_en_shift                                   (0)
#define  CRT_SYS_DVFS_DDSB_pllddsb_bypass_pi_mask                                (0x80000000)
#define  CRT_SYS_DVFS_DDSB_pllddsb_en_pi_debug_mask                              (0x40000000)
#define  CRT_SYS_DVFS_DDSB_pllddsb_hs_oc_stop_mask                               (0x30000000)
#define  CRT_SYS_DVFS_DDSB_pllddsb_pi_cur_sel_mask                               (0x0C000000)
#define  CRT_SYS_DVFS_DDSB_pllddsb_sel_oc_mode_mask                              (0x03000000)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_done_delay_mask                            (0x003F0000)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_step_mask                                  (0x00003FF0)
#define  CRT_SYS_DVFS_DDSB_pllddsb_sdm_order_mask                                (0x00000004)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_done_mask                                  (0x00000002)
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_en_mask                                    (0x00000001)
#define  CRT_SYS_DVFS_DDSB_pllddsb_bypass_pi(data)                               (0x80000000&((data)<<31))
#define  CRT_SYS_DVFS_DDSB_pllddsb_en_pi_debug(data)                             (0x40000000&((data)<<30))
#define  CRT_SYS_DVFS_DDSB_pllddsb_hs_oc_stop(data)                              (0x30000000&((data)<<28))
#define  CRT_SYS_DVFS_DDSB_pllddsb_pi_cur_sel(data)                              (0x0C000000&((data)<<26))
#define  CRT_SYS_DVFS_DDSB_pllddsb_sel_oc_mode(data)                             (0x03000000&((data)<<24))
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_done_delay(data)                           (0x003F0000&((data)<<16))
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_step(data)                                 (0x00003FF0&((data)<<4))
#define  CRT_SYS_DVFS_DDSB_pllddsb_sdm_order(data)                               (0x00000004&((data)<<2))
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_done(data)                                 (0x00000002&((data)<<1))
#define  CRT_SYS_DVFS_DDSB_pllddsb_oc_en(data)                                   (0x00000001&(data))
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_bypass_pi(data)                           ((0x80000000&(data))>>31)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_en_pi_debug(data)                         ((0x40000000&(data))>>30)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_hs_oc_stop(data)                          ((0x30000000&(data))>>28)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_pi_cur_sel(data)                          ((0x0C000000&(data))>>26)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_sel_oc_mode(data)                         ((0x03000000&(data))>>24)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_oc_done_delay(data)                       ((0x003F0000&(data))>>16)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_oc_step(data)                             ((0x00003FF0&(data))>>4)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_sdm_order(data)                           ((0x00000004&(data))>>2)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_oc_done(data)                             ((0x00000002&(data))>>1)
#define  CRT_SYS_DVFS_DDSB_get_pllddsb_oc_en(data)                               (0x00000001&(data))

#define  CRT_SYS_DVFS_DDSB2                                                      0x18000364
#define  CRT_SYS_DVFS_DDSB2_reg_addr                                             "0xB8000364"
#define  CRT_SYS_DVFS_DDSB2_reg                                                  0xB8000364
#define  CRT_SYS_DVFS_DDSB2_inst_addr                                            "0x0032"
#define  set_CRT_SYS_DVFS_DDSB2_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_DVFS_DDSB2_reg)=data)
#define  get_CRT_SYS_DVFS_DDSB2_reg                                              (*((volatile unsigned int*)CRT_SYS_DVFS_DDSB2_reg))
#define  CRT_SYS_DVFS_DDSB2_pllddsb_fcode_dbg_shift                              (16)
#define  CRT_SYS_DVFS_DDSB2_pllddsb_ncode_dbg_shift                              (8)
#define  CRT_SYS_DVFS_DDSB2_pllddsb_fcode_dbg_mask                               (0x07FF0000)
#define  CRT_SYS_DVFS_DDSB2_pllddsb_ncode_dbg_mask                               (0x0000FF00)
#define  CRT_SYS_DVFS_DDSB2_pllddsb_fcode_dbg(data)                              (0x07FF0000&((data)<<16))
#define  CRT_SYS_DVFS_DDSB2_pllddsb_ncode_dbg(data)                              (0x0000FF00&((data)<<8))
#define  CRT_SYS_DVFS_DDSB2_get_pllddsb_fcode_dbg(data)                          ((0x07FF0000&(data))>>16)
#define  CRT_SYS_DVFS_DDSB2_get_pllddsb_ncode_dbg(data)                          ((0x0000FF00&(data))>>8)

#define  CRT_AI_B_CLKCR                                                          0x18000370
#define  CRT_AI_B_CLKCR_reg_addr                                                 "0xB8000370"
#define  CRT_AI_B_CLKCR_reg                                                      0xB8000370
#define  CRT_AI_B_CLKCR_inst_addr                                                "0x0033"
#define  set_CRT_AI_B_CLKCR_reg(data)                                            (*((volatile unsigned int*)CRT_AI_B_CLKCR_reg)=data)
#define  get_CRT_AI_B_CLKCR_reg                                                  (*((volatile unsigned int*)CRT_AI_B_CLKCR_reg))
#define  CRT_AI_B_CLKCR_swsce_b_shift                                            (25)
#define  CRT_AI_B_CLKCR_tme_b_shift                                              (23)
#define  CRT_AI_B_CLKCR_tmps_b_shift                                             (20)
#define  CRT_AI_B_CLKCR_psc_b_shift                                              (19)
#define  CRT_AI_B_CLKCR_swcs_b_shift                                             (9)
#define  CRT_AI_B_CLKCR_sd_b_shift                                               (1)
#define  CRT_AI_B_CLKCR_su_b_shift                                               (0)
#define  CRT_AI_B_CLKCR_swsce_b_mask                                             (0x02000000)
#define  CRT_AI_B_CLKCR_tme_b_mask                                               (0x00800000)
#define  CRT_AI_B_CLKCR_tmps_b_mask                                              (0x00100000)
#define  CRT_AI_B_CLKCR_psc_b_mask                                               (0x00080000)
#define  CRT_AI_B_CLKCR_swcs_b_mask                                              (0x0000FE00)
#define  CRT_AI_B_CLKCR_sd_b_mask                                                (0x00000002)
#define  CRT_AI_B_CLKCR_su_b_mask                                                (0x00000001)
#define  CRT_AI_B_CLKCR_swsce_b(data)                                            (0x02000000&((data)<<25))
#define  CRT_AI_B_CLKCR_tme_b(data)                                              (0x00800000&((data)<<23))
#define  CRT_AI_B_CLKCR_tmps_b(data)                                             (0x00100000&((data)<<20))
#define  CRT_AI_B_CLKCR_psc_b(data)                                              (0x00080000&((data)<<19))
#define  CRT_AI_B_CLKCR_swcs_b(data)                                             (0x0000FE00&((data)<<9))
#define  CRT_AI_B_CLKCR_sd_b(data)                                               (0x00000002&((data)<<1))
#define  CRT_AI_B_CLKCR_su_b(data)                                               (0x00000001&(data))
#define  CRT_AI_B_CLKCR_get_swsce_b(data)                                        ((0x02000000&(data))>>25)
#define  CRT_AI_B_CLKCR_get_tme_b(data)                                          ((0x00800000&(data))>>23)
#define  CRT_AI_B_CLKCR_get_tmps_b(data)                                         ((0x00100000&(data))>>20)
#define  CRT_AI_B_CLKCR_get_psc_b(data)                                          ((0x00080000&(data))>>19)
#define  CRT_AI_B_CLKCR_get_swcs_b(data)                                         ((0x0000FE00&(data))>>9)
#define  CRT_AI_B_CLKCR_get_sd_b(data)                                           ((0x00000002&(data))>>1)
#define  CRT_AI_B_CLKCR_get_su_b(data)                                           (0x00000001&(data))

#define  CRT_AI2_B_CLKCR                                                         0x18000374
#define  CRT_AI2_B_CLKCR_reg_addr                                                "0xB8000374"
#define  CRT_AI2_B_CLKCR_reg                                                     0xB8000374
#define  CRT_AI2_B_CLKCR_inst_addr                                               "0x0034"
#define  set_CRT_AI2_B_CLKCR_reg(data)                                           (*((volatile unsigned int*)CRT_AI2_B_CLKCR_reg)=data)
#define  get_CRT_AI2_B_CLKCR_reg                                                 (*((volatile unsigned int*)CRT_AI2_B_CLKCR_reg))
#define  CRT_AI2_B_CLKCR_swsce_b_2_shift                                         (25)
#define  CRT_AI2_B_CLKCR_tme_b_2_shift                                           (23)
#define  CRT_AI2_B_CLKCR_tmps_b_2_shift                                          (20)
#define  CRT_AI2_B_CLKCR_psc_b_2_shift                                           (19)
#define  CRT_AI2_B_CLKCR_swcs_b_2_shift                                          (9)
#define  CRT_AI2_B_CLKCR_sd_b_2_shift                                            (1)
#define  CRT_AI2_B_CLKCR_su_b_2_shift                                            (0)
#define  CRT_AI2_B_CLKCR_swsce_b_2_mask                                          (0x02000000)
#define  CRT_AI2_B_CLKCR_tme_b_2_mask                                            (0x00800000)
#define  CRT_AI2_B_CLKCR_tmps_b_2_mask                                           (0x00100000)
#define  CRT_AI2_B_CLKCR_psc_b_2_mask                                            (0x00080000)
#define  CRT_AI2_B_CLKCR_swcs_b_2_mask                                           (0x0000FE00)
#define  CRT_AI2_B_CLKCR_sd_b_2_mask                                             (0x00000002)
#define  CRT_AI2_B_CLKCR_su_b_2_mask                                             (0x00000001)
#define  CRT_AI2_B_CLKCR_swsce_b_2(data)                                         (0x02000000&((data)<<25))
#define  CRT_AI2_B_CLKCR_tme_b_2(data)                                           (0x00800000&((data)<<23))
#define  CRT_AI2_B_CLKCR_tmps_b_2(data)                                          (0x00100000&((data)<<20))
#define  CRT_AI2_B_CLKCR_psc_b_2(data)                                           (0x00080000&((data)<<19))
#define  CRT_AI2_B_CLKCR_swcs_b_2(data)                                          (0x0000FE00&((data)<<9))
#define  CRT_AI2_B_CLKCR_sd_b_2(data)                                            (0x00000002&((data)<<1))
#define  CRT_AI2_B_CLKCR_su_b_2(data)                                            (0x00000001&(data))
#define  CRT_AI2_B_CLKCR_get_swsce_b_2(data)                                     ((0x02000000&(data))>>25)
#define  CRT_AI2_B_CLKCR_get_tme_b_2(data)                                       ((0x00800000&(data))>>23)
#define  CRT_AI2_B_CLKCR_get_tmps_b_2(data)                                      ((0x00100000&(data))>>20)
#define  CRT_AI2_B_CLKCR_get_psc_b_2(data)                                       ((0x00080000&(data))>>19)
#define  CRT_AI2_B_CLKCR_get_swcs_b_2(data)                                      ((0x0000FE00&(data))>>9)
#define  CRT_AI2_B_CLKCR_get_sd_b_2(data)                                        ((0x00000002&(data))>>1)
#define  CRT_AI2_B_CLKCR_get_su_b_2(data)                                        (0x00000001&(data))

#define  CRT_SYS_PLL_KCPU1                                                       0x180003B0
#define  CRT_SYS_PLL_KCPU1_reg_addr                                              "0xB80003B0"
#define  CRT_SYS_PLL_KCPU1_reg                                                   0xB80003B0
#define  CRT_SYS_PLL_KCPU1_inst_addr                                             "0x0035"
#define  set_CRT_SYS_PLL_KCPU1_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_KCPU1_reg)=data)
#define  get_CRT_SYS_PLL_KCPU1_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_KCPU1_reg))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_tst_shift                                     (24)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_n_shift                                       (20)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_m_shift                                       (12)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_ip_shift                                      (9)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_o_shift                                       (7)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_wdset_shift                                   (6)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_wdrst_shift                                   (5)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_cs_shift                                      (3)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_rs_shift                                      (0)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_tst_mask                                      (0x01000000)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_n_mask                                        (0x00300000)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_m_mask                                        (0x000FF000)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_ip_mask                                       (0x00000E00)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_o_mask                                        (0x00000180)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_wdset_mask                                    (0x00000040)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_wdrst_mask                                    (0x00000020)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_cs_mask                                       (0x00000018)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_rs_mask                                       (0x00000007)
#define  CRT_SYS_PLL_KCPU1_pllkcpu_tst(data)                                     (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_n(data)                                       (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_m(data)                                       (0x000FF000&((data)<<12))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_ip(data)                                      (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_o(data)                                       (0x00000180&((data)<<7))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_wdset(data)                                   (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_wdrst(data)                                   (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_cs(data)                                      (0x00000018&((data)<<3))
#define  CRT_SYS_PLL_KCPU1_pllkcpu_rs(data)                                      (0x00000007&(data))
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_tst(data)                                 ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_n(data)                                   ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_m(data)                                   ((0x000FF000&(data))>>12)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_ip(data)                                  ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_o(data)                                   ((0x00000180&(data))>>7)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_wdset(data)                               ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_wdrst(data)                               ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_cs(data)                                  ((0x00000018&(data))>>3)
#define  CRT_SYS_PLL_KCPU1_get_pllkcpu_rs(data)                                  (0x00000007&(data))

#define  CRT_SYS_PLL_KCPU2                                                       0x180003B4
#define  CRT_SYS_PLL_KCPU2_reg_addr                                              "0xB80003B4"
#define  CRT_SYS_PLL_KCPU2_reg                                                   0xB80003B4
#define  CRT_SYS_PLL_KCPU2_inst_addr                                             "0x0036"
#define  set_CRT_SYS_PLL_KCPU2_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_KCPU2_reg)=data)
#define  get_CRT_SYS_PLL_KCPU2_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_KCPU2_reg))
#define  CRT_SYS_PLL_KCPU2_pllkcpu_oeb_shift                                     (2)
#define  CRT_SYS_PLL_KCPU2_pllkcpu_rstb_shift                                    (1)
#define  CRT_SYS_PLL_KCPU2_pllkcpu_pow_shift                                     (0)
#define  CRT_SYS_PLL_KCPU2_pllkcpu_oeb_mask                                      (0x00000004)
#define  CRT_SYS_PLL_KCPU2_pllkcpu_rstb_mask                                     (0x00000002)
#define  CRT_SYS_PLL_KCPU2_pllkcpu_pow_mask                                      (0x00000001)
#define  CRT_SYS_PLL_KCPU2_pllkcpu_oeb(data)                                     (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_KCPU2_pllkcpu_rstb(data)                                    (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_KCPU2_pllkcpu_pow(data)                                     (0x00000001&(data))
#define  CRT_SYS_PLL_KCPU2_get_pllkcpu_oeb(data)                                 ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_KCPU2_get_pllkcpu_rstb(data)                                ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_KCPU2_get_pllkcpu_pow(data)                                 (0x00000001&(data))

#define  CRT_PLL_SSC_BUS                                                         0x180003C0
#define  CRT_PLL_SSC_BUS_reg_addr                                                "0xB80003C0"
#define  CRT_PLL_SSC_BUS_reg                                                     0xB80003C0
#define  CRT_PLL_SSC_BUS_inst_addr                                               "0x0037"
#define  set_CRT_PLL_SSC_BUS_reg(data)                                           (*((volatile unsigned int*)CRT_PLL_SSC_BUS_reg)=data)
#define  get_CRT_PLL_SSC_BUS_reg                                                 (*((volatile unsigned int*)CRT_PLL_SSC_BUS_reg))
#define  CRT_PLL_SSC_BUS_pllbus_gran_auto_rst_shift                              (28)
#define  CRT_PLL_SSC_BUS_pllbus_dot_gran_shift                                   (24)
#define  CRT_PLL_SSC_BUS_pllbus_gran_est_shift                                   (4)
#define  CRT_PLL_SSC_BUS_pllbus_en_ssc_shift                                     (0)
#define  CRT_PLL_SSC_BUS_pllbus_gran_auto_rst_mask                               (0x10000000)
#define  CRT_PLL_SSC_BUS_pllbus_dot_gran_mask                                    (0x07000000)
#define  CRT_PLL_SSC_BUS_pllbus_gran_est_mask                                    (0x007FFFF0)
#define  CRT_PLL_SSC_BUS_pllbus_en_ssc_mask                                      (0x00000001)
#define  CRT_PLL_SSC_BUS_pllbus_gran_auto_rst(data)                              (0x10000000&((data)<<28))
#define  CRT_PLL_SSC_BUS_pllbus_dot_gran(data)                                   (0x07000000&((data)<<24))
#define  CRT_PLL_SSC_BUS_pllbus_gran_est(data)                                   (0x007FFFF0&((data)<<4))
#define  CRT_PLL_SSC_BUS_pllbus_en_ssc(data)                                     (0x00000001&(data))
#define  CRT_PLL_SSC_BUS_get_pllbus_gran_auto_rst(data)                          ((0x10000000&(data))>>28)
#define  CRT_PLL_SSC_BUS_get_pllbus_dot_gran(data)                               ((0x07000000&(data))>>24)
#define  CRT_PLL_SSC_BUS_get_pllbus_gran_est(data)                               ((0x007FFFF0&(data))>>4)
#define  CRT_PLL_SSC_BUS_get_pllbus_en_ssc(data)                                 (0x00000001&(data))

#define  CRT_PLL_SSC_BUS_2                                                       0x180003C4
#define  CRT_PLL_SSC_BUS_2_reg_addr                                              "0xB80003C4"
#define  CRT_PLL_SSC_BUS_2_reg                                                   0xB80003C4
#define  CRT_PLL_SSC_BUS_2_inst_addr                                             "0x0038"
#define  set_CRT_PLL_SSC_BUS_2_reg(data)                                         (*((volatile unsigned int*)CRT_PLL_SSC_BUS_2_reg)=data)
#define  get_CRT_PLL_SSC_BUS_2_reg                                               (*((volatile unsigned int*)CRT_PLL_SSC_BUS_2_reg))
#define  CRT_PLL_SSC_BUS_2_pllbus_ncode_ssc_shift                                (16)
#define  CRT_PLL_SSC_BUS_2_pllbus_fcode_ssc_shift                                (0)
#define  CRT_PLL_SSC_BUS_2_pllbus_ncode_ssc_mask                                 (0x00FF0000)
#define  CRT_PLL_SSC_BUS_2_pllbus_fcode_ssc_mask                                 (0x000007FF)
#define  CRT_PLL_SSC_BUS_2_pllbus_ncode_ssc(data)                                (0x00FF0000&((data)<<16))
#define  CRT_PLL_SSC_BUS_2_pllbus_fcode_ssc(data)                                (0x000007FF&(data))
#define  CRT_PLL_SSC_BUS_2_get_pllbus_ncode_ssc(data)                            ((0x00FF0000&(data))>>16)
#define  CRT_PLL_SSC_BUS_2_get_pllbus_fcode_ssc(data)                            (0x000007FF&(data))

#define  CRT_PLL_SSC_BUSH                                                        0x180003D0
#define  CRT_PLL_SSC_BUSH_reg_addr                                               "0xB80003D0"
#define  CRT_PLL_SSC_BUSH_reg                                                    0xB80003D0
#define  CRT_PLL_SSC_BUSH_inst_addr                                              "0x0039"
#define  set_CRT_PLL_SSC_BUSH_reg(data)                                          (*((volatile unsigned int*)CRT_PLL_SSC_BUSH_reg)=data)
#define  get_CRT_PLL_SSC_BUSH_reg                                                (*((volatile unsigned int*)CRT_PLL_SSC_BUSH_reg))
#define  CRT_PLL_SSC_BUSH_pllbus_gran_auto_rst_h_shift                           (28)
#define  CRT_PLL_SSC_BUSH_pllbus_dot_gran_h_shift                                (24)
#define  CRT_PLL_SSC_BUSH_pllbus_gran_est_h_shift                                (4)
#define  CRT_PLL_SSC_BUSH_pllbus_en_ssc_h_shift                                  (0)
#define  CRT_PLL_SSC_BUSH_pllbus_gran_auto_rst_h_mask                            (0x10000000)
#define  CRT_PLL_SSC_BUSH_pllbus_dot_gran_h_mask                                 (0x07000000)
#define  CRT_PLL_SSC_BUSH_pllbus_gran_est_h_mask                                 (0x007FFFF0)
#define  CRT_PLL_SSC_BUSH_pllbus_en_ssc_h_mask                                   (0x00000001)
#define  CRT_PLL_SSC_BUSH_pllbus_gran_auto_rst_h(data)                           (0x10000000&((data)<<28))
#define  CRT_PLL_SSC_BUSH_pllbus_dot_gran_h(data)                                (0x07000000&((data)<<24))
#define  CRT_PLL_SSC_BUSH_pllbus_gran_est_h(data)                                (0x007FFFF0&((data)<<4))
#define  CRT_PLL_SSC_BUSH_pllbus_en_ssc_h(data)                                  (0x00000001&(data))
#define  CRT_PLL_SSC_BUSH_get_pllbus_gran_auto_rst_h(data)                       ((0x10000000&(data))>>28)
#define  CRT_PLL_SSC_BUSH_get_pllbus_dot_gran_h(data)                            ((0x07000000&(data))>>24)
#define  CRT_PLL_SSC_BUSH_get_pllbus_gran_est_h(data)                            ((0x007FFFF0&(data))>>4)
#define  CRT_PLL_SSC_BUSH_get_pllbus_en_ssc_h(data)                              (0x00000001&(data))

#define  CRT_PLL_SSC_BUSH_2                                                      0x180003D4
#define  CRT_PLL_SSC_BUSH_2_reg_addr                                             "0xB80003D4"
#define  CRT_PLL_SSC_BUSH_2_reg                                                  0xB80003D4
#define  CRT_PLL_SSC_BUSH_2_inst_addr                                            "0x003A"
#define  set_CRT_PLL_SSC_BUSH_2_reg(data)                                        (*((volatile unsigned int*)CRT_PLL_SSC_BUSH_2_reg)=data)
#define  get_CRT_PLL_SSC_BUSH_2_reg                                              (*((volatile unsigned int*)CRT_PLL_SSC_BUSH_2_reg))
#define  CRT_PLL_SSC_BUSH_2_pllbus_ncode_ssc_h_shift                             (16)
#define  CRT_PLL_SSC_BUSH_2_pllbus_fcode_ssc_h_shift                             (0)
#define  CRT_PLL_SSC_BUSH_2_pllbus_ncode_ssc_h_mask                              (0x00FF0000)
#define  CRT_PLL_SSC_BUSH_2_pllbus_fcode_ssc_h_mask                              (0x000007FF)
#define  CRT_PLL_SSC_BUSH_2_pllbus_ncode_ssc_h(data)                             (0x00FF0000&((data)<<16))
#define  CRT_PLL_SSC_BUSH_2_pllbus_fcode_ssc_h(data)                             (0x000007FF&(data))
#define  CRT_PLL_SSC_BUSH_2_get_pllbus_ncode_ssc_h(data)                         ((0x00FF0000&(data))>>16)
#define  CRT_PLL_SSC_BUSH_2_get_pllbus_fcode_ssc_h(data)                         (0x000007FF&(data))

#define  CRT_PLL_SSC_DDSA                                                        0x180003E0
#define  CRT_PLL_SSC_DDSA_reg_addr                                               "0xB80003E0"
#define  CRT_PLL_SSC_DDSA_reg                                                    0xB80003E0
#define  CRT_PLL_SSC_DDSA_inst_addr                                              "0x003B"
#define  set_CRT_PLL_SSC_DDSA_reg(data)                                          (*((volatile unsigned int*)CRT_PLL_SSC_DDSA_reg)=data)
#define  get_CRT_PLL_SSC_DDSA_reg                                                (*((volatile unsigned int*)CRT_PLL_SSC_DDSA_reg))
#define  CRT_PLL_SSC_DDSA_pllddsa_gran_auto_rst_shift                            (28)
#define  CRT_PLL_SSC_DDSA_pllddsa_dot_gran_shift                                 (24)
#define  CRT_PLL_SSC_DDSA_pllddsa_gran_est_shift                                 (4)
#define  CRT_PLL_SSC_DDSA_pllddsa_en_ssc_shift                                   (0)
#define  CRT_PLL_SSC_DDSA_pllddsa_gran_auto_rst_mask                             (0x10000000)
#define  CRT_PLL_SSC_DDSA_pllddsa_dot_gran_mask                                  (0x07000000)
#define  CRT_PLL_SSC_DDSA_pllddsa_gran_est_mask                                  (0x007FFFF0)
#define  CRT_PLL_SSC_DDSA_pllddsa_en_ssc_mask                                    (0x00000001)
#define  CRT_PLL_SSC_DDSA_pllddsa_gran_auto_rst(data)                            (0x10000000&((data)<<28))
#define  CRT_PLL_SSC_DDSA_pllddsa_dot_gran(data)                                 (0x07000000&((data)<<24))
#define  CRT_PLL_SSC_DDSA_pllddsa_gran_est(data)                                 (0x007FFFF0&((data)<<4))
#define  CRT_PLL_SSC_DDSA_pllddsa_en_ssc(data)                                   (0x00000001&(data))
#define  CRT_PLL_SSC_DDSA_get_pllddsa_gran_auto_rst(data)                        ((0x10000000&(data))>>28)
#define  CRT_PLL_SSC_DDSA_get_pllddsa_dot_gran(data)                             ((0x07000000&(data))>>24)
#define  CRT_PLL_SSC_DDSA_get_pllddsa_gran_est(data)                             ((0x007FFFF0&(data))>>4)
#define  CRT_PLL_SSC_DDSA_get_pllddsa_en_ssc(data)                               (0x00000001&(data))

#define  CRT_PLL_SSC_DDSA_2                                                      0x180003E4
#define  CRT_PLL_SSC_DDSA_2_reg_addr                                             "0xB80003E4"
#define  CRT_PLL_SSC_DDSA_2_reg                                                  0xB80003E4
#define  CRT_PLL_SSC_DDSA_2_inst_addr                                            "0x003C"
#define  set_CRT_PLL_SSC_DDSA_2_reg(data)                                        (*((volatile unsigned int*)CRT_PLL_SSC_DDSA_2_reg)=data)
#define  get_CRT_PLL_SSC_DDSA_2_reg                                              (*((volatile unsigned int*)CRT_PLL_SSC_DDSA_2_reg))
#define  CRT_PLL_SSC_DDSA_2_pllddsa_ncode_ssc_shift                              (16)
#define  CRT_PLL_SSC_DDSA_2_pllddsa_fcode_ssc_shift                              (0)
#define  CRT_PLL_SSC_DDSA_2_pllddsa_ncode_ssc_mask                               (0x00FF0000)
#define  CRT_PLL_SSC_DDSA_2_pllddsa_fcode_ssc_mask                               (0x000007FF)
#define  CRT_PLL_SSC_DDSA_2_pllddsa_ncode_ssc(data)                              (0x00FF0000&((data)<<16))
#define  CRT_PLL_SSC_DDSA_2_pllddsa_fcode_ssc(data)                              (0x000007FF&(data))
#define  CRT_PLL_SSC_DDSA_2_get_pllddsa_ncode_ssc(data)                          ((0x00FF0000&(data))>>16)
#define  CRT_PLL_SSC_DDSA_2_get_pllddsa_fcode_ssc(data)                          (0x000007FF&(data))

#define  CRT_PLL_SSC_DDSB                                                        0x180003E8
#define  CRT_PLL_SSC_DDSB_reg_addr                                               "0xB80003E8"
#define  CRT_PLL_SSC_DDSB_reg                                                    0xB80003E8
#define  CRT_PLL_SSC_DDSB_inst_addr                                              "0x003D"
#define  set_CRT_PLL_SSC_DDSB_reg(data)                                          (*((volatile unsigned int*)CRT_PLL_SSC_DDSB_reg)=data)
#define  get_CRT_PLL_SSC_DDSB_reg                                                (*((volatile unsigned int*)CRT_PLL_SSC_DDSB_reg))
#define  CRT_PLL_SSC_DDSB_pllddsb_gran_auto_rst_shift                            (28)
#define  CRT_PLL_SSC_DDSB_pllddsb_dot_gran_shift                                 (24)
#define  CRT_PLL_SSC_DDSB_pllddsb_gran_est_shift                                 (4)
#define  CRT_PLL_SSC_DDSB_pllddsb_en_ssc_shift                                   (0)
#define  CRT_PLL_SSC_DDSB_pllddsb_gran_auto_rst_mask                             (0x10000000)
#define  CRT_PLL_SSC_DDSB_pllddsb_dot_gran_mask                                  (0x07000000)
#define  CRT_PLL_SSC_DDSB_pllddsb_gran_est_mask                                  (0x007FFFF0)
#define  CRT_PLL_SSC_DDSB_pllddsb_en_ssc_mask                                    (0x00000001)
#define  CRT_PLL_SSC_DDSB_pllddsb_gran_auto_rst(data)                            (0x10000000&((data)<<28))
#define  CRT_PLL_SSC_DDSB_pllddsb_dot_gran(data)                                 (0x07000000&((data)<<24))
#define  CRT_PLL_SSC_DDSB_pllddsb_gran_est(data)                                 (0x007FFFF0&((data)<<4))
#define  CRT_PLL_SSC_DDSB_pllddsb_en_ssc(data)                                   (0x00000001&(data))
#define  CRT_PLL_SSC_DDSB_get_pllddsb_gran_auto_rst(data)                        ((0x10000000&(data))>>28)
#define  CRT_PLL_SSC_DDSB_get_pllddsb_dot_gran(data)                             ((0x07000000&(data))>>24)
#define  CRT_PLL_SSC_DDSB_get_pllddsb_gran_est(data)                             ((0x007FFFF0&(data))>>4)
#define  CRT_PLL_SSC_DDSB_get_pllddsb_en_ssc(data)                               (0x00000001&(data))

#define  CRT_PLL_SSC_DDSB_2                                                      0x180003EC
#define  CRT_PLL_SSC_DDSB_2_reg_addr                                             "0xB80003EC"
#define  CRT_PLL_SSC_DDSB_2_reg                                                  0xB80003EC
#define  CRT_PLL_SSC_DDSB_2_inst_addr                                            "0x003E"
#define  set_CRT_PLL_SSC_DDSB_2_reg(data)                                        (*((volatile unsigned int*)CRT_PLL_SSC_DDSB_2_reg)=data)
#define  get_CRT_PLL_SSC_DDSB_2_reg                                              (*((volatile unsigned int*)CRT_PLL_SSC_DDSB_2_reg))
#define  CRT_PLL_SSC_DDSB_2_pllddsb_ncode_ssc_shift                              (16)
#define  CRT_PLL_SSC_DDSB_2_pllddsb_fcode_ssc_shift                              (0)
#define  CRT_PLL_SSC_DDSB_2_pllddsb_ncode_ssc_mask                               (0x00FF0000)
#define  CRT_PLL_SSC_DDSB_2_pllddsb_fcode_ssc_mask                               (0x000007FF)
#define  CRT_PLL_SSC_DDSB_2_pllddsb_ncode_ssc(data)                              (0x00FF0000&((data)<<16))
#define  CRT_PLL_SSC_DDSB_2_pllddsb_fcode_ssc(data)                              (0x000007FF&(data))
#define  CRT_PLL_SSC_DDSB_2_get_pllddsb_ncode_ssc(data)                          ((0x00FF0000&(data))>>16)
#define  CRT_PLL_SSC_DDSB_2_get_pllddsb_fcode_ssc(data)                          (0x000007FF&(data))

#define  CRT_PLL_SSC_INV                                                         0x180003F0
#define  CRT_PLL_SSC_INV_reg_addr                                                "0xB80003F0"
#define  CRT_PLL_SSC_INV_reg                                                     0xB80003F0
#define  CRT_PLL_SSC_INV_inst_addr                                               "0x003F"
#define  set_CRT_PLL_SSC_INV_reg(data)                                           (*((volatile unsigned int*)CRT_PLL_SSC_INV_reg)=data)
#define  get_CRT_PLL_SSC_INV_reg                                                 (*((volatile unsigned int*)CRT_PLL_SSC_INV_reg))
#define  CRT_PLL_SSC_INV_psaud2b_ssc_ckinv_shift                                 (11)
#define  CRT_PLL_SSC_INV_psaud2a_ssc_ckinv_shift                                 (10)
#define  CRT_PLL_SSC_INV_psaud1b_ssc_ckinv_shift                                 (9)
#define  CRT_PLL_SSC_INV_psaud1a_ssc_ckinv_shift                                 (8)
#define  CRT_PLL_SSC_INV_dds_ssc_ckinv_shift                                     (4)
#define  CRT_PLL_SSC_INV_gpu_ssc_ckinv_shift                                     (3)
#define  CRT_PLL_SSC_INV_bush_ssc_ckinv_shift                                    (1)
#define  CRT_PLL_SSC_INV_bus_ssc_ckinv_shift                                     (0)
#define  CRT_PLL_SSC_INV_psaud2b_ssc_ckinv_mask                                  (0x00000800)
#define  CRT_PLL_SSC_INV_psaud2a_ssc_ckinv_mask                                  (0x00000400)
#define  CRT_PLL_SSC_INV_psaud1b_ssc_ckinv_mask                                  (0x00000200)
#define  CRT_PLL_SSC_INV_psaud1a_ssc_ckinv_mask                                  (0x00000100)
#define  CRT_PLL_SSC_INV_dds_ssc_ckinv_mask                                      (0x00000010)
#define  CRT_PLL_SSC_INV_gpu_ssc_ckinv_mask                                      (0x00000008)
#define  CRT_PLL_SSC_INV_bush_ssc_ckinv_mask                                     (0x00000002)
#define  CRT_PLL_SSC_INV_bus_ssc_ckinv_mask                                      (0x00000001)
#define  CRT_PLL_SSC_INV_psaud2b_ssc_ckinv(data)                                 (0x00000800&((data)<<11))
#define  CRT_PLL_SSC_INV_psaud2a_ssc_ckinv(data)                                 (0x00000400&((data)<<10))
#define  CRT_PLL_SSC_INV_psaud1b_ssc_ckinv(data)                                 (0x00000200&((data)<<9))
#define  CRT_PLL_SSC_INV_psaud1a_ssc_ckinv(data)                                 (0x00000100&((data)<<8))
#define  CRT_PLL_SSC_INV_dds_ssc_ckinv(data)                                     (0x00000010&((data)<<4))
#define  CRT_PLL_SSC_INV_gpu_ssc_ckinv(data)                                     (0x00000008&((data)<<3))
#define  CRT_PLL_SSC_INV_bush_ssc_ckinv(data)                                    (0x00000002&((data)<<1))
#define  CRT_PLL_SSC_INV_bus_ssc_ckinv(data)                                     (0x00000001&(data))
#define  CRT_PLL_SSC_INV_get_psaud2b_ssc_ckinv(data)                             ((0x00000800&(data))>>11)
#define  CRT_PLL_SSC_INV_get_psaud2a_ssc_ckinv(data)                             ((0x00000400&(data))>>10)
#define  CRT_PLL_SSC_INV_get_psaud1b_ssc_ckinv(data)                             ((0x00000200&(data))>>9)
#define  CRT_PLL_SSC_INV_get_psaud1a_ssc_ckinv(data)                             ((0x00000100&(data))>>8)
#define  CRT_PLL_SSC_INV_get_dds_ssc_ckinv(data)                                 ((0x00000010&(data))>>4)
#define  CRT_PLL_SSC_INV_get_gpu_ssc_ckinv(data)                                 ((0x00000008&(data))>>3)
#define  CRT_PLL_SSC_INV_get_bush_ssc_ckinv(data)                                ((0x00000002&(data))>>1)
#define  CRT_PLL_SSC_INV_get_bus_ssc_ckinv(data)                                 (0x00000001&(data))

#define  CRT_SYS_PLL_CPU                                                         0x180003F4
#define  CRT_SYS_PLL_CPU_reg_addr                                                "0xB80003F4"
#define  CRT_SYS_PLL_CPU_reg                                                     0xB80003F4
#define  CRT_SYS_PLL_CPU_inst_addr                                               "0x0040"
#define  set_CRT_SYS_PLL_CPU_reg(data)                                           (*((volatile unsigned int*)CRT_SYS_PLL_CPU_reg)=data)
#define  get_CRT_SYS_PLL_CPU_reg                                                 (*((volatile unsigned int*)CRT_SYS_PLL_CPU_reg))
#define  CRT_SYS_PLL_CPU_pow_ldo1v_shift                                         (6)
#define  CRT_SYS_PLL_CPU_ldo1v_sel_shift                                         (4)
#define  CRT_SYS_PLL_CPU_pllcpu_reg_shift                                        (0)
#define  CRT_SYS_PLL_CPU_pow_ldo1v_mask                                          (0x00000040)
#define  CRT_SYS_PLL_CPU_ldo1v_sel_mask                                          (0x00000030)
#define  CRT_SYS_PLL_CPU_pllcpu_reg_mask                                         (0x00000003)
#define  CRT_SYS_PLL_CPU_pow_ldo1v(data)                                         (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_CPU_ldo1v_sel(data)                                         (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_CPU_pllcpu_reg(data)                                        (0x00000003&(data))
#define  CRT_SYS_PLL_CPU_get_pow_ldo1v(data)                                     ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_CPU_get_ldo1v_sel(data)                                     ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_CPU_get_pllcpu_reg(data)                                    (0x00000003&(data))

#define  CRT_SYS_PLL_ACPU1                                                       0x18000408
#define  CRT_SYS_PLL_ACPU1_reg_addr                                              "0xB8000408"
#define  CRT_SYS_PLL_ACPU1_reg                                                   0xB8000408
#define  CRT_SYS_PLL_ACPU1_inst_addr                                             "0x0041"
#define  set_CRT_SYS_PLL_ACPU1_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_ACPU1_reg)=data)
#define  get_CRT_SYS_PLL_ACPU1_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_ACPU1_reg))
#define  CRT_SYS_PLL_ACPU1_pllacpu_tst_shift                                     (24)
#define  CRT_SYS_PLL_ACPU1_pllacpu_n_shift                                       (20)
#define  CRT_SYS_PLL_ACPU1_pllacpu_m_shift                                       (12)
#define  CRT_SYS_PLL_ACPU1_pllacpu_ip_shift                                      (9)
#define  CRT_SYS_PLL_ACPU1_pllacpu_o_shift                                       (7)
#define  CRT_SYS_PLL_ACPU1_pllacpu_wdset_shift                                   (6)
#define  CRT_SYS_PLL_ACPU1_pllacpu_wdrst_shift                                   (5)
#define  CRT_SYS_PLL_ACPU1_pllacpu_cs_shift                                      (3)
#define  CRT_SYS_PLL_ACPU1_pllacpu_rs_shift                                      (0)
#define  CRT_SYS_PLL_ACPU1_pllacpu_tst_mask                                      (0x01000000)
#define  CRT_SYS_PLL_ACPU1_pllacpu_n_mask                                        (0x00300000)
#define  CRT_SYS_PLL_ACPU1_pllacpu_m_mask                                        (0x000FF000)
#define  CRT_SYS_PLL_ACPU1_pllacpu_ip_mask                                       (0x00000E00)
#define  CRT_SYS_PLL_ACPU1_pllacpu_o_mask                                        (0x00000180)
#define  CRT_SYS_PLL_ACPU1_pllacpu_wdset_mask                                    (0x00000040)
#define  CRT_SYS_PLL_ACPU1_pllacpu_wdrst_mask                                    (0x00000020)
#define  CRT_SYS_PLL_ACPU1_pllacpu_cs_mask                                       (0x00000018)
#define  CRT_SYS_PLL_ACPU1_pllacpu_rs_mask                                       (0x00000007)
#define  CRT_SYS_PLL_ACPU1_pllacpu_tst(data)                                     (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_ACPU1_pllacpu_n(data)                                       (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_ACPU1_pllacpu_m(data)                                       (0x000FF000&((data)<<12))
#define  CRT_SYS_PLL_ACPU1_pllacpu_ip(data)                                      (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_ACPU1_pllacpu_o(data)                                       (0x00000180&((data)<<7))
#define  CRT_SYS_PLL_ACPU1_pllacpu_wdset(data)                                   (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_ACPU1_pllacpu_wdrst(data)                                   (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_ACPU1_pllacpu_cs(data)                                      (0x00000018&((data)<<3))
#define  CRT_SYS_PLL_ACPU1_pllacpu_rs(data)                                      (0x00000007&(data))
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_tst(data)                                 ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_n(data)                                   ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_m(data)                                   ((0x000FF000&(data))>>12)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_ip(data)                                  ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_o(data)                                   ((0x00000180&(data))>>7)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_wdset(data)                               ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_wdrst(data)                               ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_cs(data)                                  ((0x00000018&(data))>>3)
#define  CRT_SYS_PLL_ACPU1_get_pllacpu_rs(data)                                  (0x00000007&(data))

#define  CRT_SYS_PLL_ACPU2                                                       0x1800040C
#define  CRT_SYS_PLL_ACPU2_reg_addr                                              "0xB800040C"
#define  CRT_SYS_PLL_ACPU2_reg                                                   0xB800040C
#define  CRT_SYS_PLL_ACPU2_inst_addr                                             "0x0042"
#define  set_CRT_SYS_PLL_ACPU2_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_ACPU2_reg)=data)
#define  get_CRT_SYS_PLL_ACPU2_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_ACPU2_reg))
#define  CRT_SYS_PLL_ACPU2_pllacpu_oeb_shift                                     (2)
#define  CRT_SYS_PLL_ACPU2_pllacpu_rstb_shift                                    (1)
#define  CRT_SYS_PLL_ACPU2_pllacpu_pow_shift                                     (0)
#define  CRT_SYS_PLL_ACPU2_pllacpu_oeb_mask                                      (0x00000004)
#define  CRT_SYS_PLL_ACPU2_pllacpu_rstb_mask                                     (0x00000002)
#define  CRT_SYS_PLL_ACPU2_pllacpu_pow_mask                                      (0x00000001)
#define  CRT_SYS_PLL_ACPU2_pllacpu_oeb(data)                                     (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_ACPU2_pllacpu_rstb(data)                                    (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_ACPU2_pllacpu_pow(data)                                     (0x00000001&(data))
#define  CRT_SYS_PLL_ACPU2_get_pllacpu_oeb(data)                                 ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_ACPU2_get_pllacpu_rstb(data)                                ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_ACPU2_get_pllacpu_pow(data)                                 (0x00000001&(data))

#define  CRT_SYS_PLL_VCPU_1                                                      0x18000410
#define  CRT_SYS_PLL_VCPU_1_reg_addr                                             "0xB8000410"
#define  CRT_SYS_PLL_VCPU_1_reg                                                  0xB8000410
#define  CRT_SYS_PLL_VCPU_1_inst_addr                                            "0x0043"
#define  set_CRT_SYS_PLL_VCPU_1_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_VCPU_1_reg)=data)
#define  get_CRT_SYS_PLL_VCPU_1_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_VCPU_1_reg))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_tst_shift                                    (24)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_n_shift                                      (20)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_m_shift                                      (12)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_ip_shift                                     (9)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_o_shift                                      (7)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_wdset_shift                                  (6)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_wdrst_shift                                  (5)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_cs_shift                                     (3)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_rs_shift                                     (0)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_tst_mask                                     (0x01000000)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_n_mask                                       (0x00300000)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_m_mask                                       (0x000FF000)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_ip_mask                                      (0x00000E00)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_o_mask                                       (0x00000180)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_wdset_mask                                   (0x00000040)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_wdrst_mask                                   (0x00000020)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_cs_mask                                      (0x00000018)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_rs_mask                                      (0x00000007)
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_tst(data)                                    (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_n(data)                                      (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_m(data)                                      (0x000FF000&((data)<<12))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_ip(data)                                     (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_o(data)                                      (0x00000180&((data)<<7))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_wdset(data)                                  (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_wdrst(data)                                  (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_cs(data)                                     (0x00000018&((data)<<3))
#define  CRT_SYS_PLL_VCPU_1_pllvcpu_rs(data)                                     (0x00000007&(data))
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_tst(data)                                ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_n(data)                                  ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_m(data)                                  ((0x000FF000&(data))>>12)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_ip(data)                                 ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_o(data)                                  ((0x00000180&(data))>>7)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_wdset(data)                              ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_wdrst(data)                              ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_cs(data)                                 ((0x00000018&(data))>>3)
#define  CRT_SYS_PLL_VCPU_1_get_pllvcpu_rs(data)                                 (0x00000007&(data))

#define  CRT_SYS_PLL_VCPU_2                                                      0x18000414
#define  CRT_SYS_PLL_VCPU_2_reg_addr                                             "0xB8000414"
#define  CRT_SYS_PLL_VCPU_2_reg                                                  0xB8000414
#define  CRT_SYS_PLL_VCPU_2_inst_addr                                            "0x0044"
#define  set_CRT_SYS_PLL_VCPU_2_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_VCPU_2_reg)=data)
#define  get_CRT_SYS_PLL_VCPU_2_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_VCPU_2_reg))
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_oeb_shift                                    (2)
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_rstb_shift                                   (1)
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_pow_shift                                    (0)
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_oeb_mask                                     (0x00000004)
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_rstb_mask                                    (0x00000002)
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_pow_mask                                     (0x00000001)
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_oeb(data)                                    (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_rstb(data)                                   (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_VCPU_2_pllvcpu_pow(data)                                    (0x00000001&(data))
#define  CRT_SYS_PLL_VCPU_2_get_pllvcpu_oeb(data)                                ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_VCPU_2_get_pllvcpu_rstb(data)                               ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_VCPU_2_get_pllvcpu_pow(data)                                (0x00000001&(data))

#define  CRT_SYS_PLL_VCPU2_1                                                     0x18000418
#define  CRT_SYS_PLL_VCPU2_1_reg_addr                                            "0xB8000418"
#define  CRT_SYS_PLL_VCPU2_1_reg                                                 0xB8000418
#define  CRT_SYS_PLL_VCPU2_1_inst_addr                                           "0x0045"
#define  set_CRT_SYS_PLL_VCPU2_1_reg(data)                                       (*((volatile unsigned int*)CRT_SYS_PLL_VCPU2_1_reg)=data)
#define  get_CRT_SYS_PLL_VCPU2_1_reg                                             (*((volatile unsigned int*)CRT_SYS_PLL_VCPU2_1_reg))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_tst_2_shift                                 (24)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_n_2_shift                                   (20)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_m_2_shift                                   (12)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_ip_2_shift                                  (9)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_o_2_shift                                   (7)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_wdset_2_shift                               (6)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_wdrst_2_shift                               (5)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_cs_2_shift                                  (3)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_rs_2_shift                                  (0)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_tst_2_mask                                  (0x01000000)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_n_2_mask                                    (0x00300000)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_m_2_mask                                    (0x000FF000)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_ip_2_mask                                   (0x00000E00)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_o_2_mask                                    (0x00000180)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_wdset_2_mask                                (0x00000040)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_wdrst_2_mask                                (0x00000020)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_cs_2_mask                                   (0x00000018)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_rs_2_mask                                   (0x00000007)
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_tst_2(data)                                 (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_n_2(data)                                   (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_m_2(data)                                   (0x000FF000&((data)<<12))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_ip_2(data)                                  (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_o_2(data)                                   (0x00000180&((data)<<7))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_wdset_2(data)                               (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_wdrst_2(data)                               (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_cs_2(data)                                  (0x00000018&((data)<<3))
#define  CRT_SYS_PLL_VCPU2_1_pllvcpu_rs_2(data)                                  (0x00000007&(data))
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_tst_2(data)                             ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_n_2(data)                               ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_m_2(data)                               ((0x000FF000&(data))>>12)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_ip_2(data)                              ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_o_2(data)                               ((0x00000180&(data))>>7)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_wdset_2(data)                           ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_wdrst_2(data)                           ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_cs_2(data)                              ((0x00000018&(data))>>3)
#define  CRT_SYS_PLL_VCPU2_1_get_pllvcpu_rs_2(data)                              (0x00000007&(data))

#define  CRT_SYS_PLL_VCPU2_2                                                     0x1800041C
#define  CRT_SYS_PLL_VCPU2_2_reg_addr                                            "0xB800041C"
#define  CRT_SYS_PLL_VCPU2_2_reg                                                 0xB800041C
#define  CRT_SYS_PLL_VCPU2_2_inst_addr                                           "0x0046"
#define  set_CRT_SYS_PLL_VCPU2_2_reg(data)                                       (*((volatile unsigned int*)CRT_SYS_PLL_VCPU2_2_reg)=data)
#define  get_CRT_SYS_PLL_VCPU2_2_reg                                             (*((volatile unsigned int*)CRT_SYS_PLL_VCPU2_2_reg))
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_oeb_2_shift                                 (2)
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_rstb_2_shift                                (1)
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_pow_2_shift                                 (0)
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_oeb_2_mask                                  (0x00000004)
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_rstb_2_mask                                 (0x00000002)
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_pow_2_mask                                  (0x00000001)
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_oeb_2(data)                                 (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_rstb_2(data)                                (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_VCPU2_2_pllvcpu_pow_2(data)                                 (0x00000001&(data))
#define  CRT_SYS_PLL_VCPU2_2_get_pllvcpu_oeb_2(data)                             ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_VCPU2_2_get_pllvcpu_rstb_2(data)                            ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_VCPU2_2_get_pllvcpu_pow_2(data)                             (0x00000001&(data))

#define  CRT_SYS_PLL_BUS1                                                        0x18000420
#define  CRT_SYS_PLL_BUS1_reg_addr                                               "0xB8000420"
#define  CRT_SYS_PLL_BUS1_reg                                                    0xB8000420
#define  CRT_SYS_PLL_BUS1_inst_addr                                              "0x0047"
#define  set_CRT_SYS_PLL_BUS1_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_BUS1_reg)=data)
#define  get_CRT_SYS_PLL_BUS1_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_BUS1_reg))
#define  CRT_SYS_PLL_BUS1_pllbus_wdset_shift                                     (21)
#define  CRT_SYS_PLL_BUS1_pllbus_wdrst_shift                                     (20)
#define  CRT_SYS_PLL_BUS1_pllbus_lpf_cs_shift                                    (16)
#define  CRT_SYS_PLL_BUS1_pllbus_testsel_shift                                   (13)
#define  CRT_SYS_PLL_BUS1_pllbus_sel_cco_shift                                   (12)
#define  CRT_SYS_PLL_BUS1_pllbus_icp_shift                                       (8)
#define  CRT_SYS_PLL_BUS1_pllbus_dbug_en_shift                                   (7)
#define  CRT_SYS_PLL_BUS1_pllbus_pdiv_bps_shift                                  (6)
#define  CRT_SYS_PLL_BUS1_pllbus_pdiv_shift                                      (4)
#define  CRT_SYS_PLL_BUS1_pllbus_lpf_rs_shift                                    (0)
#define  CRT_SYS_PLL_BUS1_pllbus_wdset_mask                                      (0x00200000)
#define  CRT_SYS_PLL_BUS1_pllbus_wdrst_mask                                      (0x00100000)
#define  CRT_SYS_PLL_BUS1_pllbus_lpf_cs_mask                                     (0x00030000)
#define  CRT_SYS_PLL_BUS1_pllbus_testsel_mask                                    (0x00002000)
#define  CRT_SYS_PLL_BUS1_pllbus_sel_cco_mask                                    (0x00001000)
#define  CRT_SYS_PLL_BUS1_pllbus_icp_mask                                        (0x00000700)
#define  CRT_SYS_PLL_BUS1_pllbus_dbug_en_mask                                    (0x00000080)
#define  CRT_SYS_PLL_BUS1_pllbus_pdiv_bps_mask                                   (0x00000040)
#define  CRT_SYS_PLL_BUS1_pllbus_pdiv_mask                                       (0x00000030)
#define  CRT_SYS_PLL_BUS1_pllbus_lpf_rs_mask                                     (0x00000007)
#define  CRT_SYS_PLL_BUS1_pllbus_wdset(data)                                     (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_BUS1_pllbus_wdrst(data)                                     (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_BUS1_pllbus_lpf_cs(data)                                    (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_BUS1_pllbus_testsel(data)                                   (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_BUS1_pllbus_sel_cco(data)                                   (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_BUS1_pllbus_icp(data)                                       (0x00000700&((data)<<8))
#define  CRT_SYS_PLL_BUS1_pllbus_dbug_en(data)                                   (0x00000080&((data)<<7))
#define  CRT_SYS_PLL_BUS1_pllbus_pdiv_bps(data)                                  (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_BUS1_pllbus_pdiv(data)                                      (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_BUS1_pllbus_lpf_rs(data)                                    (0x00000007&(data))
#define  CRT_SYS_PLL_BUS1_get_pllbus_wdset(data)                                 ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_BUS1_get_pllbus_wdrst(data)                                 ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_BUS1_get_pllbus_lpf_cs(data)                                ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_BUS1_get_pllbus_testsel(data)                               ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_BUS1_get_pllbus_sel_cco(data)                               ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_BUS1_get_pllbus_icp(data)                                   ((0x00000700&(data))>>8)
#define  CRT_SYS_PLL_BUS1_get_pllbus_dbug_en(data)                               ((0x00000080&(data))>>7)
#define  CRT_SYS_PLL_BUS1_get_pllbus_pdiv_bps(data)                              ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_BUS1_get_pllbus_pdiv(data)                                  ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_BUS1_get_pllbus_lpf_rs(data)                                (0x00000007&(data))

#define  CRT_SYS_PLL_BUS2                                                        0x18000424
#define  CRT_SYS_PLL_BUS2_reg_addr                                               "0xB8000424"
#define  CRT_SYS_PLL_BUS2_reg                                                    0xB8000424
#define  CRT_SYS_PLL_BUS2_inst_addr                                              "0x0048"
#define  set_CRT_SYS_PLL_BUS2_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_BUS2_reg)=data)
#define  get_CRT_SYS_PLL_BUS2_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_BUS2_reg))
#define  CRT_SYS_PLL_BUS2_pllbus_fcode_shift                                     (16)
#define  CRT_SYS_PLL_BUS2_pllbus_ncode_shift                                     (8)
#define  CRT_SYS_PLL_BUS2_pllbus_oeb_shift                                       (2)
#define  CRT_SYS_PLL_BUS2_pllbus_rstb_shift                                      (1)
#define  CRT_SYS_PLL_BUS2_pllbus_pow_shift                                       (0)
#define  CRT_SYS_PLL_BUS2_pllbus_fcode_mask                                      (0x07FF0000)
#define  CRT_SYS_PLL_BUS2_pllbus_ncode_mask                                      (0x0000FF00)
#define  CRT_SYS_PLL_BUS2_pllbus_oeb_mask                                        (0x00000004)
#define  CRT_SYS_PLL_BUS2_pllbus_rstb_mask                                       (0x00000002)
#define  CRT_SYS_PLL_BUS2_pllbus_pow_mask                                        (0x00000001)
#define  CRT_SYS_PLL_BUS2_pllbus_fcode(data)                                     (0x07FF0000&((data)<<16))
#define  CRT_SYS_PLL_BUS2_pllbus_ncode(data)                                     (0x0000FF00&((data)<<8))
#define  CRT_SYS_PLL_BUS2_pllbus_oeb(data)                                       (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_BUS2_pllbus_rstb(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_BUS2_pllbus_pow(data)                                       (0x00000001&(data))
#define  CRT_SYS_PLL_BUS2_get_pllbus_fcode(data)                                 ((0x07FF0000&(data))>>16)
#define  CRT_SYS_PLL_BUS2_get_pllbus_ncode(data)                                 ((0x0000FF00&(data))>>8)
#define  CRT_SYS_PLL_BUS2_get_pllbus_oeb(data)                                   ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_BUS2_get_pllbus_rstb(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_BUS2_get_pllbus_pow(data)                                   (0x00000001&(data))

#define  CRT_SYS_DVFS_BUS                                                        0x18000428
#define  CRT_SYS_DVFS_BUS_reg_addr                                               "0xB8000428"
#define  CRT_SYS_DVFS_BUS_reg                                                    0xB8000428
#define  CRT_SYS_DVFS_BUS_inst_addr                                              "0x0049"
#define  set_CRT_SYS_DVFS_BUS_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_DVFS_BUS_reg)=data)
#define  get_CRT_SYS_DVFS_BUS_reg                                                (*((volatile unsigned int*)CRT_SYS_DVFS_BUS_reg))
#define  CRT_SYS_DVFS_BUS_pllbus_bypass_pi_shift                                 (31)
#define  CRT_SYS_DVFS_BUS_pllbus_en_pi_debug_shift                               (30)
#define  CRT_SYS_DVFS_BUS_pllbus_hs_oc_stop_shift                                (28)
#define  CRT_SYS_DVFS_BUS_pllbus_pi_cur_sel_shift                                (26)
#define  CRT_SYS_DVFS_BUS_pllbus_sel_oc_mode_shift                               (24)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_done_delay_shift                             (16)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_step_shift                                   (4)
#define  CRT_SYS_DVFS_BUS_pllbus_sdm_order_shift                                 (2)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_done_shift                                   (1)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_en_shift                                     (0)
#define  CRT_SYS_DVFS_BUS_pllbus_bypass_pi_mask                                  (0x80000000)
#define  CRT_SYS_DVFS_BUS_pllbus_en_pi_debug_mask                                (0x40000000)
#define  CRT_SYS_DVFS_BUS_pllbus_hs_oc_stop_mask                                 (0x30000000)
#define  CRT_SYS_DVFS_BUS_pllbus_pi_cur_sel_mask                                 (0x0C000000)
#define  CRT_SYS_DVFS_BUS_pllbus_sel_oc_mode_mask                                (0x03000000)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_done_delay_mask                              (0x003F0000)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_step_mask                                    (0x00003FF0)
#define  CRT_SYS_DVFS_BUS_pllbus_sdm_order_mask                                  (0x00000004)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_done_mask                                    (0x00000002)
#define  CRT_SYS_DVFS_BUS_pllbus_oc_en_mask                                      (0x00000001)
#define  CRT_SYS_DVFS_BUS_pllbus_bypass_pi(data)                                 (0x80000000&((data)<<31))
#define  CRT_SYS_DVFS_BUS_pllbus_en_pi_debug(data)                               (0x40000000&((data)<<30))
#define  CRT_SYS_DVFS_BUS_pllbus_hs_oc_stop(data)                                (0x30000000&((data)<<28))
#define  CRT_SYS_DVFS_BUS_pllbus_pi_cur_sel(data)                                (0x0C000000&((data)<<26))
#define  CRT_SYS_DVFS_BUS_pllbus_sel_oc_mode(data)                               (0x03000000&((data)<<24))
#define  CRT_SYS_DVFS_BUS_pllbus_oc_done_delay(data)                             (0x003F0000&((data)<<16))
#define  CRT_SYS_DVFS_BUS_pllbus_oc_step(data)                                   (0x00003FF0&((data)<<4))
#define  CRT_SYS_DVFS_BUS_pllbus_sdm_order(data)                                 (0x00000004&((data)<<2))
#define  CRT_SYS_DVFS_BUS_pllbus_oc_done(data)                                   (0x00000002&((data)<<1))
#define  CRT_SYS_DVFS_BUS_pllbus_oc_en(data)                                     (0x00000001&(data))
#define  CRT_SYS_DVFS_BUS_get_pllbus_bypass_pi(data)                             ((0x80000000&(data))>>31)
#define  CRT_SYS_DVFS_BUS_get_pllbus_en_pi_debug(data)                           ((0x40000000&(data))>>30)
#define  CRT_SYS_DVFS_BUS_get_pllbus_hs_oc_stop(data)                            ((0x30000000&(data))>>28)
#define  CRT_SYS_DVFS_BUS_get_pllbus_pi_cur_sel(data)                            ((0x0C000000&(data))>>26)
#define  CRT_SYS_DVFS_BUS_get_pllbus_sel_oc_mode(data)                           ((0x03000000&(data))>>24)
#define  CRT_SYS_DVFS_BUS_get_pllbus_oc_done_delay(data)                         ((0x003F0000&(data))>>16)
#define  CRT_SYS_DVFS_BUS_get_pllbus_oc_step(data)                               ((0x00003FF0&(data))>>4)
#define  CRT_SYS_DVFS_BUS_get_pllbus_sdm_order(data)                             ((0x00000004&(data))>>2)
#define  CRT_SYS_DVFS_BUS_get_pllbus_oc_done(data)                               ((0x00000002&(data))>>1)
#define  CRT_SYS_DVFS_BUS_get_pllbus_oc_en(data)                                 (0x00000001&(data))

#define  CRT_SYS_DVFS_BUS2                                                       0x1800042C
#define  CRT_SYS_DVFS_BUS2_reg_addr                                              "0xB800042C"
#define  CRT_SYS_DVFS_BUS2_reg                                                   0xB800042C
#define  CRT_SYS_DVFS_BUS2_inst_addr                                             "0x004A"
#define  set_CRT_SYS_DVFS_BUS2_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_DVFS_BUS2_reg)=data)
#define  get_CRT_SYS_DVFS_BUS2_reg                                               (*((volatile unsigned int*)CRT_SYS_DVFS_BUS2_reg))
#define  CRT_SYS_DVFS_BUS2_pllbus_fcode_dbg_shift                                (16)
#define  CRT_SYS_DVFS_BUS2_pllbus_ncode_dbg_shift                                (8)
#define  CRT_SYS_DVFS_BUS2_pllbus_fcode_dbg_mask                                 (0x07FF0000)
#define  CRT_SYS_DVFS_BUS2_pllbus_ncode_dbg_mask                                 (0x0000FF00)
#define  CRT_SYS_DVFS_BUS2_pllbus_fcode_dbg(data)                                (0x07FF0000&((data)<<16))
#define  CRT_SYS_DVFS_BUS2_pllbus_ncode_dbg(data)                                (0x0000FF00&((data)<<8))
#define  CRT_SYS_DVFS_BUS2_get_pllbus_fcode_dbg(data)                            ((0x07FF0000&(data))>>16)
#define  CRT_SYS_DVFS_BUS2_get_pllbus_ncode_dbg(data)                            ((0x0000FF00&(data))>>8)

#define  CRT_SYS_PLL_BUSH1                                                       0x18000430
#define  CRT_SYS_PLL_BUSH1_reg_addr                                              "0xB8000430"
#define  CRT_SYS_PLL_BUSH1_reg                                                   0xB8000430
#define  CRT_SYS_PLL_BUSH1_inst_addr                                             "0x004B"
#define  set_CRT_SYS_PLL_BUSH1_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_BUSH1_reg)=data)
#define  get_CRT_SYS_PLL_BUSH1_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_BUSH1_reg))
#define  CRT_SYS_PLL_BUSH1_pllbus_wdset_h_shift                                  (21)
#define  CRT_SYS_PLL_BUSH1_pllbus_wdrst_h_shift                                  (20)
#define  CRT_SYS_PLL_BUSH1_pllbus_lpf_cs_h_shift                                 (16)
#define  CRT_SYS_PLL_BUSH1_pllbus_testsel_h_shift                                (13)
#define  CRT_SYS_PLL_BUSH1_pllbus_sel_cco_h_shift                                (12)
#define  CRT_SYS_PLL_BUSH1_pllbus_icp_h_shift                                    (8)
#define  CRT_SYS_PLL_BUSH1_pllbus_dbug_en_h_shift                                (7)
#define  CRT_SYS_PLL_BUSH1_pllbus_pdiv_bps_h_shift                               (6)
#define  CRT_SYS_PLL_BUSH1_pllbus_pdiv_h_shift                                   (4)
#define  CRT_SYS_PLL_BUSH1_pllbus_lpf_rs_h_shift                                 (0)
#define  CRT_SYS_PLL_BUSH1_pllbus_wdset_h_mask                                   (0x00200000)
#define  CRT_SYS_PLL_BUSH1_pllbus_wdrst_h_mask                                   (0x00100000)
#define  CRT_SYS_PLL_BUSH1_pllbus_lpf_cs_h_mask                                  (0x00030000)
#define  CRT_SYS_PLL_BUSH1_pllbus_testsel_h_mask                                 (0x00002000)
#define  CRT_SYS_PLL_BUSH1_pllbus_sel_cco_h_mask                                 (0x00001000)
#define  CRT_SYS_PLL_BUSH1_pllbus_icp_h_mask                                     (0x00000700)
#define  CRT_SYS_PLL_BUSH1_pllbus_dbug_en_h_mask                                 (0x00000080)
#define  CRT_SYS_PLL_BUSH1_pllbus_pdiv_bps_h_mask                                (0x00000040)
#define  CRT_SYS_PLL_BUSH1_pllbus_pdiv_h_mask                                    (0x00000030)
#define  CRT_SYS_PLL_BUSH1_pllbus_lpf_rs_h_mask                                  (0x00000007)
#define  CRT_SYS_PLL_BUSH1_pllbus_wdset_h(data)                                  (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_BUSH1_pllbus_wdrst_h(data)                                  (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_BUSH1_pllbus_lpf_cs_h(data)                                 (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_BUSH1_pllbus_testsel_h(data)                                (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_BUSH1_pllbus_sel_cco_h(data)                                (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_BUSH1_pllbus_icp_h(data)                                    (0x00000700&((data)<<8))
#define  CRT_SYS_PLL_BUSH1_pllbus_dbug_en_h(data)                                (0x00000080&((data)<<7))
#define  CRT_SYS_PLL_BUSH1_pllbus_pdiv_bps_h(data)                               (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_BUSH1_pllbus_pdiv_h(data)                                   (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_BUSH1_pllbus_lpf_rs_h(data)                                 (0x00000007&(data))
#define  CRT_SYS_PLL_BUSH1_get_pllbus_wdset_h(data)                              ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_wdrst_h(data)                              ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_lpf_cs_h(data)                             ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_testsel_h(data)                            ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_sel_cco_h(data)                            ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_icp_h(data)                                ((0x00000700&(data))>>8)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_dbug_en_h(data)                            ((0x00000080&(data))>>7)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_pdiv_bps_h(data)                           ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_pdiv_h(data)                               ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_BUSH1_get_pllbus_lpf_rs_h(data)                             (0x00000007&(data))

#define  CRT_SYS_PLL_BUSH2                                                       0x18000434
#define  CRT_SYS_PLL_BUSH2_reg_addr                                              "0xB8000434"
#define  CRT_SYS_PLL_BUSH2_reg                                                   0xB8000434
#define  CRT_SYS_PLL_BUSH2_inst_addr                                             "0x004C"
#define  set_CRT_SYS_PLL_BUSH2_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_BUSH2_reg)=data)
#define  get_CRT_SYS_PLL_BUSH2_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_BUSH2_reg))
#define  CRT_SYS_PLL_BUSH2_pllbus_fcode_h_shift                                  (16)
#define  CRT_SYS_PLL_BUSH2_pllbus_ncode_h_shift                                  (8)
#define  CRT_SYS_PLL_BUSH2_pllbus_oeb_h_shift                                    (2)
#define  CRT_SYS_PLL_BUSH2_pllbus_rstb_h_shift                                   (1)
#define  CRT_SYS_PLL_BUSH2_pllbus_pow_h_shift                                    (0)
#define  CRT_SYS_PLL_BUSH2_pllbus_fcode_h_mask                                   (0x07FF0000)
#define  CRT_SYS_PLL_BUSH2_pllbus_ncode_h_mask                                   (0x0000FF00)
#define  CRT_SYS_PLL_BUSH2_pllbus_oeb_h_mask                                     (0x00000004)
#define  CRT_SYS_PLL_BUSH2_pllbus_rstb_h_mask                                    (0x00000002)
#define  CRT_SYS_PLL_BUSH2_pllbus_pow_h_mask                                     (0x00000001)
#define  CRT_SYS_PLL_BUSH2_pllbus_fcode_h(data)                                  (0x07FF0000&((data)<<16))
#define  CRT_SYS_PLL_BUSH2_pllbus_ncode_h(data)                                  (0x0000FF00&((data)<<8))
#define  CRT_SYS_PLL_BUSH2_pllbus_oeb_h(data)                                    (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_BUSH2_pllbus_rstb_h(data)                                   (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_BUSH2_pllbus_pow_h(data)                                    (0x00000001&(data))
#define  CRT_SYS_PLL_BUSH2_get_pllbus_fcode_h(data)                              ((0x07FF0000&(data))>>16)
#define  CRT_SYS_PLL_BUSH2_get_pllbus_ncode_h(data)                              ((0x0000FF00&(data))>>8)
#define  CRT_SYS_PLL_BUSH2_get_pllbus_oeb_h(data)                                ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_BUSH2_get_pllbus_rstb_h(data)                               ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_BUSH2_get_pllbus_pow_h(data)                                (0x00000001&(data))

#define  CRT_SYS_DVFS_BUSH                                                       0x18000438
#define  CRT_SYS_DVFS_BUSH_reg_addr                                              "0xB8000438"
#define  CRT_SYS_DVFS_BUSH_reg                                                   0xB8000438
#define  CRT_SYS_DVFS_BUSH_inst_addr                                             "0x004D"
#define  set_CRT_SYS_DVFS_BUSH_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_DVFS_BUSH_reg)=data)
#define  get_CRT_SYS_DVFS_BUSH_reg                                               (*((volatile unsigned int*)CRT_SYS_DVFS_BUSH_reg))
#define  CRT_SYS_DVFS_BUSH_pllbus_bypass_pi_h_shift                              (31)
#define  CRT_SYS_DVFS_BUSH_pllbus_en_pi_debug_h_shift                            (30)
#define  CRT_SYS_DVFS_BUSH_pllbus_hs_oc_stop_h_shift                             (28)
#define  CRT_SYS_DVFS_BUSH_pllbus_pi_cur_sel_h_shift                             (26)
#define  CRT_SYS_DVFS_BUSH_pllbus_sel_oc_mode_h_shift                            (24)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_done_delay_h_shift                          (16)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_step_h_shift                                (4)
#define  CRT_SYS_DVFS_BUSH_pllbus_sdm_order_h_shift                              (2)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_done_h_shift                                (1)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_en_h_shift                                  (0)
#define  CRT_SYS_DVFS_BUSH_pllbus_bypass_pi_h_mask                               (0x80000000)
#define  CRT_SYS_DVFS_BUSH_pllbus_en_pi_debug_h_mask                             (0x40000000)
#define  CRT_SYS_DVFS_BUSH_pllbus_hs_oc_stop_h_mask                              (0x30000000)
#define  CRT_SYS_DVFS_BUSH_pllbus_pi_cur_sel_h_mask                              (0x0C000000)
#define  CRT_SYS_DVFS_BUSH_pllbus_sel_oc_mode_h_mask                             (0x03000000)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_done_delay_h_mask                           (0x003F0000)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_step_h_mask                                 (0x00003FF0)
#define  CRT_SYS_DVFS_BUSH_pllbus_sdm_order_h_mask                               (0x00000004)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_done_h_mask                                 (0x00000002)
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_en_h_mask                                   (0x00000001)
#define  CRT_SYS_DVFS_BUSH_pllbus_bypass_pi_h(data)                              (0x80000000&((data)<<31))
#define  CRT_SYS_DVFS_BUSH_pllbus_en_pi_debug_h(data)                            (0x40000000&((data)<<30))
#define  CRT_SYS_DVFS_BUSH_pllbus_hs_oc_stop_h(data)                             (0x30000000&((data)<<28))
#define  CRT_SYS_DVFS_BUSH_pllbus_pi_cur_sel_h(data)                             (0x0C000000&((data)<<26))
#define  CRT_SYS_DVFS_BUSH_pllbus_sel_oc_mode_h(data)                            (0x03000000&((data)<<24))
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_done_delay_h(data)                          (0x003F0000&((data)<<16))
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_step_h(data)                                (0x00003FF0&((data)<<4))
#define  CRT_SYS_DVFS_BUSH_pllbus_sdm_order_h(data)                              (0x00000004&((data)<<2))
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_done_h(data)                                (0x00000002&((data)<<1))
#define  CRT_SYS_DVFS_BUSH_pllbus_oc_en_h(data)                                  (0x00000001&(data))
#define  CRT_SYS_DVFS_BUSH_get_pllbus_bypass_pi_h(data)                          ((0x80000000&(data))>>31)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_en_pi_debug_h(data)                        ((0x40000000&(data))>>30)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_hs_oc_stop_h(data)                         ((0x30000000&(data))>>28)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_pi_cur_sel_h(data)                         ((0x0C000000&(data))>>26)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_sel_oc_mode_h(data)                        ((0x03000000&(data))>>24)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_oc_done_delay_h(data)                      ((0x003F0000&(data))>>16)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_oc_step_h(data)                            ((0x00003FF0&(data))>>4)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_sdm_order_h(data)                          ((0x00000004&(data))>>2)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_oc_done_h(data)                            ((0x00000002&(data))>>1)
#define  CRT_SYS_DVFS_BUSH_get_pllbus_oc_en_h(data)                              (0x00000001&(data))

#define  CRT_SYS_DVFS_BUSH2                                                      0x1800043C
#define  CRT_SYS_DVFS_BUSH2_reg_addr                                             "0xB800043C"
#define  CRT_SYS_DVFS_BUSH2_reg                                                  0xB800043C
#define  CRT_SYS_DVFS_BUSH2_inst_addr                                            "0x004E"
#define  set_CRT_SYS_DVFS_BUSH2_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_DVFS_BUSH2_reg)=data)
#define  get_CRT_SYS_DVFS_BUSH2_reg                                              (*((volatile unsigned int*)CRT_SYS_DVFS_BUSH2_reg))
#define  CRT_SYS_DVFS_BUSH2_pllbus_fcode_dbg_h_shift                             (16)
#define  CRT_SYS_DVFS_BUSH2_pllbus_ncode_dbg_h_shift                             (8)
#define  CRT_SYS_DVFS_BUSH2_pllbus_fcode_dbg_h_mask                              (0x07FF0000)
#define  CRT_SYS_DVFS_BUSH2_pllbus_ncode_dbg_h_mask                              (0x0000FF00)
#define  CRT_SYS_DVFS_BUSH2_pllbus_fcode_dbg_h(data)                             (0x07FF0000&((data)<<16))
#define  CRT_SYS_DVFS_BUSH2_pllbus_ncode_dbg_h(data)                             (0x0000FF00&((data)<<8))
#define  CRT_SYS_DVFS_BUSH2_get_pllbus_fcode_dbg_h(data)                         ((0x07FF0000&(data))>>16)
#define  CRT_SYS_DVFS_BUSH2_get_pllbus_ncode_dbg_h(data)                         ((0x0000FF00&(data))>>8)

#define  CRT_SYS_PLL_GPU1                                                        0x18000450
#define  CRT_SYS_PLL_GPU1_reg_addr                                               "0xB8000450"
#define  CRT_SYS_PLL_GPU1_reg                                                    0xB8000450
#define  CRT_SYS_PLL_GPU1_inst_addr                                              "0x004F"
#define  set_CRT_SYS_PLL_GPU1_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_GPU1_reg)=data)
#define  get_CRT_SYS_PLL_GPU1_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_GPU1_reg))
#define  CRT_SYS_PLL_GPU1_pllgpu_wdset_shift                                     (21)
#define  CRT_SYS_PLL_GPU1_pllgpu_wdrst_shift                                     (20)
#define  CRT_SYS_PLL_GPU1_pllgpu_lpf_cs_shift                                    (16)
#define  CRT_SYS_PLL_GPU1_pllgpu_testsel_shift                                   (13)
#define  CRT_SYS_PLL_GPU1_pllgpu_sel_cco_shift                                   (12)
#define  CRT_SYS_PLL_GPU1_pllgpu_icp_shift                                       (8)
#define  CRT_SYS_PLL_GPU1_pllgpu_dbug_en_shift                                   (7)
#define  CRT_SYS_PLL_GPU1_pllgpu_pdiv_bps_shift                                  (6)
#define  CRT_SYS_PLL_GPU1_pllgpu_pdiv_shift                                      (4)
#define  CRT_SYS_PLL_GPU1_pllgpu_lpf_rs_shift                                    (0)
#define  CRT_SYS_PLL_GPU1_pllgpu_wdset_mask                                      (0x00200000)
#define  CRT_SYS_PLL_GPU1_pllgpu_wdrst_mask                                      (0x00100000)
#define  CRT_SYS_PLL_GPU1_pllgpu_lpf_cs_mask                                     (0x00030000)
#define  CRT_SYS_PLL_GPU1_pllgpu_testsel_mask                                    (0x00002000)
#define  CRT_SYS_PLL_GPU1_pllgpu_sel_cco_mask                                    (0x00001000)
#define  CRT_SYS_PLL_GPU1_pllgpu_icp_mask                                        (0x00000700)
#define  CRT_SYS_PLL_GPU1_pllgpu_dbug_en_mask                                    (0x00000080)
#define  CRT_SYS_PLL_GPU1_pllgpu_pdiv_bps_mask                                   (0x00000040)
#define  CRT_SYS_PLL_GPU1_pllgpu_pdiv_mask                                       (0x00000030)
#define  CRT_SYS_PLL_GPU1_pllgpu_lpf_rs_mask                                     (0x00000007)
#define  CRT_SYS_PLL_GPU1_pllgpu_wdset(data)                                     (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_GPU1_pllgpu_wdrst(data)                                     (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_GPU1_pllgpu_lpf_cs(data)                                    (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_GPU1_pllgpu_testsel(data)                                   (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_GPU1_pllgpu_sel_cco(data)                                   (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_GPU1_pllgpu_icp(data)                                       (0x00000700&((data)<<8))
#define  CRT_SYS_PLL_GPU1_pllgpu_dbug_en(data)                                   (0x00000080&((data)<<7))
#define  CRT_SYS_PLL_GPU1_pllgpu_pdiv_bps(data)                                  (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_GPU1_pllgpu_pdiv(data)                                      (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_GPU1_pllgpu_lpf_rs(data)                                    (0x00000007&(data))
#define  CRT_SYS_PLL_GPU1_get_pllgpu_wdset(data)                                 ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_wdrst(data)                                 ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_lpf_cs(data)                                ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_testsel(data)                               ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_sel_cco(data)                               ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_icp(data)                                   ((0x00000700&(data))>>8)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_dbug_en(data)                               ((0x00000080&(data))>>7)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_pdiv_bps(data)                              ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_pdiv(data)                                  ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_GPU1_get_pllgpu_lpf_rs(data)                                (0x00000007&(data))

#define  CRT_SYS_PLL_GPU2                                                        0x18000454
#define  CRT_SYS_PLL_GPU2_reg_addr                                               "0xB8000454"
#define  CRT_SYS_PLL_GPU2_reg                                                    0xB8000454
#define  CRT_SYS_PLL_GPU2_inst_addr                                              "0x0050"
#define  set_CRT_SYS_PLL_GPU2_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_GPU2_reg)=data)
#define  get_CRT_SYS_PLL_GPU2_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_GPU2_reg))
#define  CRT_SYS_PLL_GPU2_pllgpu_fcode_shift                                     (16)
#define  CRT_SYS_PLL_GPU2_pllgpu_ncode_shift                                     (8)
#define  CRT_SYS_PLL_GPU2_pllgpu_oeb_shift                                       (2)
#define  CRT_SYS_PLL_GPU2_pllgpu_rstb_shift                                      (1)
#define  CRT_SYS_PLL_GPU2_pllgpu_pow_shift                                       (0)
#define  CRT_SYS_PLL_GPU2_pllgpu_fcode_mask                                      (0x07FF0000)
#define  CRT_SYS_PLL_GPU2_pllgpu_ncode_mask                                      (0x0000FF00)
#define  CRT_SYS_PLL_GPU2_pllgpu_oeb_mask                                        (0x00000004)
#define  CRT_SYS_PLL_GPU2_pllgpu_rstb_mask                                       (0x00000002)
#define  CRT_SYS_PLL_GPU2_pllgpu_pow_mask                                        (0x00000001)
#define  CRT_SYS_PLL_GPU2_pllgpu_fcode(data)                                     (0x07FF0000&((data)<<16))
#define  CRT_SYS_PLL_GPU2_pllgpu_ncode(data)                                     (0x0000FF00&((data)<<8))
#define  CRT_SYS_PLL_GPU2_pllgpu_oeb(data)                                       (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_GPU2_pllgpu_rstb(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_GPU2_pllgpu_pow(data)                                       (0x00000001&(data))
#define  CRT_SYS_PLL_GPU2_get_pllgpu_fcode(data)                                 ((0x07FF0000&(data))>>16)
#define  CRT_SYS_PLL_GPU2_get_pllgpu_ncode(data)                                 ((0x0000FF00&(data))>>8)
#define  CRT_SYS_PLL_GPU2_get_pllgpu_oeb(data)                                   ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_GPU2_get_pllgpu_rstb(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_GPU2_get_pllgpu_pow(data)                                   (0x00000001&(data))

#define  CRT_SYS_DVFS_GPU                                                        0x18000448
#define  CRT_SYS_DVFS_GPU_reg_addr                                               "0xB8000448"
#define  CRT_SYS_DVFS_GPU_reg                                                    0xB8000448
#define  CRT_SYS_DVFS_GPU_inst_addr                                              "0x0051"
#define  set_CRT_SYS_DVFS_GPU_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_DVFS_GPU_reg)=data)
#define  get_CRT_SYS_DVFS_GPU_reg                                                (*((volatile unsigned int*)CRT_SYS_DVFS_GPU_reg))
#define  CRT_SYS_DVFS_GPU_pllgpu_bypass_pi_shift                                 (31)
#define  CRT_SYS_DVFS_GPU_pllgpu_en_pi_debug_shift                               (30)
#define  CRT_SYS_DVFS_GPU_pllgpu_hs_oc_stop_shift                                (28)
#define  CRT_SYS_DVFS_GPU_pllgpu_pi_cur_sel_shift                                (26)
#define  CRT_SYS_DVFS_GPU_pllgpu_sel_oc_mode_shift                               (24)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_done_delay_shift                             (16)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_step_shift                                   (4)
#define  CRT_SYS_DVFS_GPU_pllgpu_sdm_order_shift                                 (2)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_done_shift                                   (1)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_en_shift                                     (0)
#define  CRT_SYS_DVFS_GPU_pllgpu_bypass_pi_mask                                  (0x80000000)
#define  CRT_SYS_DVFS_GPU_pllgpu_en_pi_debug_mask                                (0x40000000)
#define  CRT_SYS_DVFS_GPU_pllgpu_hs_oc_stop_mask                                 (0x30000000)
#define  CRT_SYS_DVFS_GPU_pllgpu_pi_cur_sel_mask                                 (0x0C000000)
#define  CRT_SYS_DVFS_GPU_pllgpu_sel_oc_mode_mask                                (0x03000000)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_done_delay_mask                              (0x003F0000)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_step_mask                                    (0x00003FF0)
#define  CRT_SYS_DVFS_GPU_pllgpu_sdm_order_mask                                  (0x00000004)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_done_mask                                    (0x00000002)
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_en_mask                                      (0x00000001)
#define  CRT_SYS_DVFS_GPU_pllgpu_bypass_pi(data)                                 (0x80000000&((data)<<31))
#define  CRT_SYS_DVFS_GPU_pllgpu_en_pi_debug(data)                               (0x40000000&((data)<<30))
#define  CRT_SYS_DVFS_GPU_pllgpu_hs_oc_stop(data)                                (0x30000000&((data)<<28))
#define  CRT_SYS_DVFS_GPU_pllgpu_pi_cur_sel(data)                                (0x0C000000&((data)<<26))
#define  CRT_SYS_DVFS_GPU_pllgpu_sel_oc_mode(data)                               (0x03000000&((data)<<24))
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_done_delay(data)                             (0x003F0000&((data)<<16))
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_step(data)                                   (0x00003FF0&((data)<<4))
#define  CRT_SYS_DVFS_GPU_pllgpu_sdm_order(data)                                 (0x00000004&((data)<<2))
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_done(data)                                   (0x00000002&((data)<<1))
#define  CRT_SYS_DVFS_GPU_pllgpu_oc_en(data)                                     (0x00000001&(data))
#define  CRT_SYS_DVFS_GPU_get_pllgpu_bypass_pi(data)                             ((0x80000000&(data))>>31)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_en_pi_debug(data)                           ((0x40000000&(data))>>30)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_hs_oc_stop(data)                            ((0x30000000&(data))>>28)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_pi_cur_sel(data)                            ((0x0C000000&(data))>>26)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_sel_oc_mode(data)                           ((0x03000000&(data))>>24)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_oc_done_delay(data)                         ((0x003F0000&(data))>>16)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_oc_step(data)                               ((0x00003FF0&(data))>>4)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_sdm_order(data)                             ((0x00000004&(data))>>2)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_oc_done(data)                               ((0x00000002&(data))>>1)
#define  CRT_SYS_DVFS_GPU_get_pllgpu_oc_en(data)                                 (0x00000001&(data))

#define  CRT_SYS_DVFS_GPU2                                                       0x1800044C
#define  CRT_SYS_DVFS_GPU2_reg_addr                                              "0xB800044C"
#define  CRT_SYS_DVFS_GPU2_reg                                                   0xB800044C
#define  CRT_SYS_DVFS_GPU2_inst_addr                                             "0x0052"
#define  set_CRT_SYS_DVFS_GPU2_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_DVFS_GPU2_reg)=data)
#define  get_CRT_SYS_DVFS_GPU2_reg                                               (*((volatile unsigned int*)CRT_SYS_DVFS_GPU2_reg))
#define  CRT_SYS_DVFS_GPU2_pllgpu_fcode_dbg_shift                                (16)
#define  CRT_SYS_DVFS_GPU2_pllgpu_ncode_dbg_shift                                (8)
#define  CRT_SYS_DVFS_GPU2_pllgpu_fcode_dbg_mask                                 (0x07FF0000)
#define  CRT_SYS_DVFS_GPU2_pllgpu_ncode_dbg_mask                                 (0x0000FF00)
#define  CRT_SYS_DVFS_GPU2_pllgpu_fcode_dbg(data)                                (0x07FF0000&((data)<<16))
#define  CRT_SYS_DVFS_GPU2_pllgpu_ncode_dbg(data)                                (0x0000FF00&((data)<<8))
#define  CRT_SYS_DVFS_GPU2_get_pllgpu_fcode_dbg(data)                            ((0x07FF0000&(data))>>16)
#define  CRT_SYS_DVFS_GPU2_get_pllgpu_ncode_dbg(data)                            ((0x0000FF00&(data))>>8)

#define  CRT_SYS_PLL_VODMA1                                                      0x18000460
#define  CRT_SYS_PLL_VODMA1_reg_addr                                             "0xB8000460"
#define  CRT_SYS_PLL_VODMA1_reg                                                  0xB8000460
#define  CRT_SYS_PLL_VODMA1_inst_addr                                            "0x0053"
#define  set_CRT_SYS_PLL_VODMA1_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_VODMA1_reg)=data)
#define  get_CRT_SYS_PLL_VODMA1_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_VODMA1_reg))
#define  CRT_SYS_PLL_VODMA1_pllvodma_n_shift                                     (20)
#define  CRT_SYS_PLL_VODMA1_pllvodma_m_shift                                     (12)
#define  CRT_SYS_PLL_VODMA1_pllvodma_ip_shift                                    (9)
#define  CRT_SYS_PLL_VODMA1_pllvodma_o_shift                                     (7)
#define  CRT_SYS_PLL_VODMA1_pllvodma_wdset_shift                                 (6)
#define  CRT_SYS_PLL_VODMA1_pllvodma_wdrst_shift                                 (5)
#define  CRT_SYS_PLL_VODMA1_pllvodma_cs_shift                                    (3)
#define  CRT_SYS_PLL_VODMA1_pllvodma_rs_shift                                    (0)
#define  CRT_SYS_PLL_VODMA1_pllvodma_n_mask                                      (0x00300000)
#define  CRT_SYS_PLL_VODMA1_pllvodma_m_mask                                      (0x000FF000)
#define  CRT_SYS_PLL_VODMA1_pllvodma_ip_mask                                     (0x00000E00)
#define  CRT_SYS_PLL_VODMA1_pllvodma_o_mask                                      (0x00000180)
#define  CRT_SYS_PLL_VODMA1_pllvodma_wdset_mask                                  (0x00000040)
#define  CRT_SYS_PLL_VODMA1_pllvodma_wdrst_mask                                  (0x00000020)
#define  CRT_SYS_PLL_VODMA1_pllvodma_cs_mask                                     (0x00000018)
#define  CRT_SYS_PLL_VODMA1_pllvodma_rs_mask                                     (0x00000007)
#define  CRT_SYS_PLL_VODMA1_pllvodma_n(data)                                     (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_VODMA1_pllvodma_m(data)                                     (0x000FF000&((data)<<12))
#define  CRT_SYS_PLL_VODMA1_pllvodma_ip(data)                                    (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_VODMA1_pllvodma_o(data)                                     (0x00000180&((data)<<7))
#define  CRT_SYS_PLL_VODMA1_pllvodma_wdset(data)                                 (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_VODMA1_pllvodma_wdrst(data)                                 (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_VODMA1_pllvodma_cs(data)                                    (0x00000018&((data)<<3))
#define  CRT_SYS_PLL_VODMA1_pllvodma_rs(data)                                    (0x00000007&(data))
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_n(data)                                 ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_m(data)                                 ((0x000FF000&(data))>>12)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_ip(data)                                ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_o(data)                                 ((0x00000180&(data))>>7)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_wdset(data)                             ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_wdrst(data)                             ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_cs(data)                                ((0x00000018&(data))>>3)
#define  CRT_SYS_PLL_VODMA1_get_pllvodma_rs(data)                                (0x00000007&(data))

#define  CRT_SYS_PLL_VODMA2                                                      0x18000464
#define  CRT_SYS_PLL_VODMA2_reg_addr                                             "0xB8000464"
#define  CRT_SYS_PLL_VODMA2_reg                                                  0xB8000464
#define  CRT_SYS_PLL_VODMA2_inst_addr                                            "0x0054"
#define  set_CRT_SYS_PLL_VODMA2_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_VODMA2_reg)=data)
#define  get_CRT_SYS_PLL_VODMA2_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_VODMA2_reg))
#define  CRT_SYS_PLL_VODMA2_pllvodma_tst_shift                                   (3)
#define  CRT_SYS_PLL_VODMA2_pllvodma_oeb_shift                                   (2)
#define  CRT_SYS_PLL_VODMA2_pllvodma_rstb_shift                                  (1)
#define  CRT_SYS_PLL_VODMA2_pllvodma_pow_shift                                   (0)
#define  CRT_SYS_PLL_VODMA2_pllvodma_tst_mask                                    (0x00000008)
#define  CRT_SYS_PLL_VODMA2_pllvodma_oeb_mask                                    (0x00000004)
#define  CRT_SYS_PLL_VODMA2_pllvodma_rstb_mask                                   (0x00000002)
#define  CRT_SYS_PLL_VODMA2_pllvodma_pow_mask                                    (0x00000001)
#define  CRT_SYS_PLL_VODMA2_pllvodma_tst(data)                                   (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_VODMA2_pllvodma_oeb(data)                                   (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_VODMA2_pllvodma_rstb(data)                                  (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_VODMA2_pllvodma_pow(data)                                   (0x00000001&(data))
#define  CRT_SYS_PLL_VODMA2_get_pllvodma_tst(data)                               ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_VODMA2_get_pllvodma_oeb(data)                               ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_VODMA2_get_pllvodma_rstb(data)                              ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_VODMA2_get_pllvodma_pow(data)                               (0x00000001&(data))

#define  CRT_SYS_PLLBUS_TST                                                      0x18000468
#define  CRT_SYS_PLLBUS_TST_reg_addr                                             "0xB8000468"
#define  CRT_SYS_PLLBUS_TST_reg                                                  0xB8000468
#define  CRT_SYS_PLLBUS_TST_inst_addr                                            "0x0055"
#define  set_CRT_SYS_PLLBUS_TST_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLLBUS_TST_reg)=data)
#define  get_CRT_SYS_PLLBUS_TST_reg                                              (*((volatile unsigned int*)CRT_SYS_PLLBUS_TST_reg))
#define  CRT_SYS_PLLBUS_TST_pllbus_reser_shift                                   (16)
#define  CRT_SYS_PLLBUS_TST_pllbus_reg_shift                                     (12)
#define  CRT_SYS_PLLBUS_TST_pllbustst_div_shift                                  (8)
#define  CRT_SYS_PLLBUS_TST_pllbustst_sel_shift                                  (0)
#define  CRT_SYS_PLLBUS_TST_pllbus_reser_mask                                    (0x00FF0000)
#define  CRT_SYS_PLLBUS_TST_pllbus_reg_mask                                      (0x00003000)
#define  CRT_SYS_PLLBUS_TST_pllbustst_div_mask                                   (0x00000300)
#define  CRT_SYS_PLLBUS_TST_pllbustst_sel_mask                                   (0x0000001F)
#define  CRT_SYS_PLLBUS_TST_pllbus_reser(data)                                   (0x00FF0000&((data)<<16))
#define  CRT_SYS_PLLBUS_TST_pllbus_reg(data)                                     (0x00003000&((data)<<12))
#define  CRT_SYS_PLLBUS_TST_pllbustst_div(data)                                  (0x00000300&((data)<<8))
#define  CRT_SYS_PLLBUS_TST_pllbustst_sel(data)                                  (0x0000001F&(data))
#define  CRT_SYS_PLLBUS_TST_get_pllbus_reser(data)                               ((0x00FF0000&(data))>>16)
#define  CRT_SYS_PLLBUS_TST_get_pllbus_reg(data)                                 ((0x00003000&(data))>>12)
#define  CRT_SYS_PLLBUS_TST_get_pllbustst_div(data)                              ((0x00000300&(data))>>8)
#define  CRT_SYS_PLLBUS_TST_get_pllbustst_sel(data)                              (0x0000001F&(data))

#define  CRT_SYS_PLL_DISPA_SD1                                                   0x18000470
#define  CRT_SYS_PLL_DISPA_SD1_reg_addr                                          "0xB8000470"
#define  CRT_SYS_PLL_DISPA_SD1_reg                                               0xB8000470
#define  CRT_SYS_PLL_DISPA_SD1_inst_addr                                         "0x0056"
#define  set_CRT_SYS_PLL_DISPA_SD1_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD1_reg)=data)
#define  get_CRT_SYS_PLL_DISPA_SD1_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD1_reg))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_n_shift                                   (30)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_ip_shift                                  (20)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_rs_shift                                  (17)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_cs_shift                                  (15)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_cp_shift                                  (13)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_o_shift                                   (4)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_wdmode_shift                              (0)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_n_mask                                    (0xC0000000)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_ip_mask                                   (0x00F00000)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_rs_mask                                   (0x000E0000)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_cs_mask                                   (0x00018000)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_cp_mask                                   (0x00006000)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_o_mask                                    (0x00000030)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_wdmode_mask                               (0x00000003)
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_n(data)                                   (0xC0000000&((data)<<30))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_ip(data)                                  (0x00F00000&((data)<<20))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_rs(data)                                  (0x000E0000&((data)<<17))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_cs(data)                                  (0x00018000&((data)<<15))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_cp(data)                                  (0x00006000&((data)<<13))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_o(data)                                   (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_DISPA_SD1_pllddsa_wdmode(data)                              (0x00000003&(data))
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_n(data)                               ((0xC0000000&(data))>>30)
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_ip(data)                              ((0x00F00000&(data))>>20)
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_rs(data)                              ((0x000E0000&(data))>>17)
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_cs(data)                              ((0x00018000&(data))>>15)
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_cp(data)                              ((0x00006000&(data))>>13)
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_o(data)                               ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_DISPA_SD1_get_pllddsa_wdmode(data)                          (0x00000003&(data))

#define  CRT_SYS_PLL_DISPA_SD2                                                   0x18000474
#define  CRT_SYS_PLL_DISPA_SD2_reg_addr                                          "0xB8000474"
#define  CRT_SYS_PLL_DISPA_SD2_reg                                               0xB8000474
#define  CRT_SYS_PLL_DISPA_SD2_inst_addr                                         "0x0057"
#define  set_CRT_SYS_PLL_DISPA_SD2_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD2_reg)=data)
#define  get_CRT_SYS_PLL_DISPA_SD2_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD2_reg))
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_fcode_shift                               (16)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_ncode_shift                               (8)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_oeb_shift                                 (2)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_rstb_shift                                (1)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_pow_shift                                 (0)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_fcode_mask                                (0x07FF0000)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_ncode_mask                                (0x0000FF00)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_oeb_mask                                  (0x00000004)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_rstb_mask                                 (0x00000002)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_pow_mask                                  (0x00000001)
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_fcode(data)                               (0x07FF0000&((data)<<16))
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_ncode(data)                               (0x0000FF00&((data)<<8))
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_oeb(data)                                 (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_rstb(data)                                (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DISPA_SD2_pllddsa_pow(data)                                 (0x00000001&(data))
#define  CRT_SYS_PLL_DISPA_SD2_get_pllddsa_fcode(data)                           ((0x07FF0000&(data))>>16)
#define  CRT_SYS_PLL_DISPA_SD2_get_pllddsa_ncode(data)                           ((0x0000FF00&(data))>>8)
#define  CRT_SYS_PLL_DISPA_SD2_get_pllddsa_oeb(data)                             ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DISPA_SD2_get_pllddsa_rstb(data)                            ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DISPA_SD2_get_pllddsa_pow(data)                             (0x00000001&(data))

#define  CRT_SYS_PLL_DISPA_SD3                                                   0x18000478
#define  CRT_SYS_PLL_DISPA_SD3_reg_addr                                          "0xB8000478"
#define  CRT_SYS_PLL_DISPA_SD3_reg                                               0xB8000478
#define  CRT_SYS_PLL_DISPA_SD3_inst_addr                                         "0x0058"
#define  set_CRT_SYS_PLL_DISPA_SD3_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD3_reg)=data)
#define  get_CRT_SYS_PLL_DISPA_SD3_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD3_reg))
#define  CRT_SYS_PLL_DISPA_SD3_dummy1_shift                                       (25)
#define  CRT_SYS_PLL_DISPA_SD3_dummy2_shift                                       (24)
#define  CRT_SYS_PLL_DISPA_SD3_dummy3_shift                                       (23)
#define  CRT_SYS_PLL_DISPA_SD3_dummy4_shift                                       (22)
#define  CRT_SYS_PLL_DISPA_SD3_dummy5_shift                                       (21)
#define  CRT_SYS_PLL_DISPA_SD3_dummy6_shift                                       (20)
#define  CRT_SYS_PLL_DISPA_SD3_dummy7_shift                                       (19)
#define  CRT_SYS_PLL_DISPA_SD3_dummy8_shift                                       (18)
#define  CRT_SYS_PLL_DISPA_SD3_dummy9_shift                                       (17)
#define  CRT_SYS_PLL_DISPA_SD3_dummy10_shift                                       (16)
#define  CRT_SYS_PLL_DISPA_SD3_dummy11_shift                                       (15)
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_vcorb_shift                               (14)
#define  CRT_SYS_PLL_DISPA_SD3_dummy12_shift                                       (13)
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_tst_shift                                 (12)
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_pstst_shift                               (11)
#define  CRT_SYS_PLL_DISPA_SD3_dummy13_shift                                       (10)
#define  CRT_SYS_PLL_DISPA_SD3_dummy1_mask                                        (0x1E000000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy2_mask                                        (0x01000000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy3_mask                                        (0x00800000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy4_mask                                        (0x00400000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy5_mask                                        (0x00200000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy6_mask                                        (0x00100000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy7_mask                                        (0x00080000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy8_mask                                        (0x00040000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy9_mask                                        (0x00020000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy10_mask                                        (0x00010000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy11_mask                                        (0x00008000)
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_vcorb_mask                                (0x00004000)
#define  CRT_SYS_PLL_DISPA_SD3_dummy12_mask                                        (0x00002000)
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_tst_mask                                  (0x00001000)
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_pstst_mask                                (0x00000800)
#define  CRT_SYS_PLL_DISPA_SD3_dummy13_mask                                        (0x00000400)
#define  CRT_SYS_PLL_DISPA_SD3_dummy1(data)                                       (0x1E000000&((data)<<25))
#define  CRT_SYS_PLL_DISPA_SD3_dummy2(data)                                       (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_DISPA_SD3_dummy3(data)                                       (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DISPA_SD3_dummy4(data)                                       (0x00400000&((data)<<22))
#define  CRT_SYS_PLL_DISPA_SD3_dummy5(data)                                       (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_DISPA_SD3_dummy6(data)                                       (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_DISPA_SD3_dummy7(data)                                       (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DISPA_SD3_dummy8(data)                                       (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_DISPA_SD3_dummy9(data)                                       (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DISPA_SD3_dummy10(data)                                       (0x00010000&((data)<<16))
#define  CRT_SYS_PLL_DISPA_SD3_dummy11(data)                                       (0x00008000&((data)<<15))
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_vcorb(data)                               (0x00004000&((data)<<14))
#define  CRT_SYS_PLL_DISPA_SD3_dummy12(data)                                       (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_tst(data)                                 (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_DISPA_SD3_pllddsa_pstst(data)                               (0x00000800&((data)<<11))
#define  CRT_SYS_PLL_DISPA_SD3_dummy13(data)                                       (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy1(data)                                   ((0x1E000000&(data))>>25)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy2(data)                                   ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy3(data)                                   ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy4(data)                                   ((0x00400000&(data))>>22)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy5(data)                                   ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy6(data)                                   ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy7(data)                                   ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy8(data)                                   ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy9(data)                                   ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy10(data)                                   ((0x00010000&(data))>>16)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy11(data)                                   ((0x00008000&(data))>>15)
#define  CRT_SYS_PLL_DISPA_SD3_get_pllddsa_vcorb(data)                           ((0x00004000&(data))>>14)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy12(data)                                   ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_DISPA_SD3_get_pllddsa_tst(data)                             ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_DISPA_SD3_get_pllddsa_pstst(data)                           ((0x00000800&(data))>>11)
#define  CRT_SYS_PLL_DISPA_SD3_get_dummy13(data)                                   ((0x00000400&(data))>>10)

#define  CRT_SYS_PLL_DISPA_SD4                                                   0x1800047C
#define  CRT_SYS_PLL_DISPA_SD4_reg_addr                                          "0xB800047C"
#define  CRT_SYS_PLL_DISPA_SD4_reg                                               0xB800047C
#define  CRT_SYS_PLL_DISPA_SD4_inst_addr                                         "0x0059"
#define  set_CRT_SYS_PLL_DISPA_SD4_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD4_reg)=data)
#define  get_CRT_SYS_PLL_DISPA_SD4_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DISPA_SD4_reg))
#define  CRT_SYS_PLL_DISPA_SD4_dummy1_shift                                       (30)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_fupdn_shift                               (29)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_div_shift                                 (28)
#define  CRT_SYS_PLL_DISPA_SD4_dummy2_shift                                       (27)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_tst_shift                                 (26)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_psen_shift                                (25)
#define  CRT_SYS_PLL_DISPA_SD4_dummy3_shift                                       (24)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_fupdn_shift                               (23)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_div_shift                                 (22)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_tst_shift                                 (21)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_psen_shift                                (20)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_oeb_shift                                 (3)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_rstb_shift                                (2)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_oeb_shift                                 (1)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_rstb_shift                                (0)
#define  CRT_SYS_PLL_DISPA_SD4_dummy1_mask                                        (0x40000000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_fupdn_mask                                (0x20000000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_div_mask                                  (0x10000000)
#define  CRT_SYS_PLL_DISPA_SD4_dummy2_mask                                        (0x08000000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_tst_mask                                  (0x04000000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_psen_mask                                 (0x02000000)
#define  CRT_SYS_PLL_DISPA_SD4_dummy3_mask                                        (0x01000000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_fupdn_mask                                (0x00800000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_div_mask                                  (0x00400000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_tst_mask                                  (0x00200000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_psen_mask                                 (0x00100000)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_oeb_mask                                  (0x00000008)
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_rstb_mask                                 (0x00000004)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_oeb_mask                                  (0x00000002)
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_rstb_mask                                 (0x00000001)
#define  CRT_SYS_PLL_DISPA_SD4_dummy1(data)                                       (0x40000000&((data)<<30))
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_fupdn(data)                               (0x20000000&((data)<<29))
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_div(data)                                 (0x10000000&((data)<<28))
#define  CRT_SYS_PLL_DISPA_SD4_dummy2(data)                                       (0x08000000&((data)<<27))
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_tst(data)                                 (0x04000000&((data)<<26))
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_psen(data)                                (0x02000000&((data)<<25))
#define  CRT_SYS_PLL_DISPA_SD4_dummy3(data)                                       (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_fupdn(data)                               (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_div(data)                                 (0x00400000&((data)<<22))
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_tst(data)                                 (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_psen(data)                                (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_oeb(data)                                 (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_DISPA_SD4_psaud1a_rstb(data)                                (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_oeb(data)                                 (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DISPA_SD4_psaud2a_rstb(data)                                (0x00000001&(data))
#define  CRT_SYS_PLL_DISPA_SD4_get_dummy1(data)                                   ((0x40000000&(data))>>30)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud1a_fupdn(data)                           ((0x20000000&(data))>>29)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud1a_div(data)                             ((0x10000000&(data))>>28)
#define  CRT_SYS_PLL_DISPA_SD4_get_dummy2(data)                                   ((0x08000000&(data))>>27)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud1a_tst(data)                             ((0x04000000&(data))>>26)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud1a_psen(data)                            ((0x02000000&(data))>>25)
#define  CRT_SYS_PLL_DISPA_SD4_get_dummy3(data)                                   ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud2a_fupdn(data)                           ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud2a_div(data)                             ((0x00400000&(data))>>22)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud2a_tst(data)                             ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud2a_psen(data)                            ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud1a_oeb(data)                             ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud1a_rstb(data)                            ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud2a_oeb(data)                             ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DISPA_SD4_get_psaud2a_rstb(data)                            (0x00000001&(data))

#define  CRT_SYS_DVFS_DDSA                                                       0x18000480
#define  CRT_SYS_DVFS_DDSA_reg_addr                                              "0xB8000480"
#define  CRT_SYS_DVFS_DDSA_reg                                                   0xB8000480
#define  CRT_SYS_DVFS_DDSA_inst_addr                                             "0x005A"
#define  set_CRT_SYS_DVFS_DDSA_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_DVFS_DDSA_reg)=data)
#define  get_CRT_SYS_DVFS_DDSA_reg                                               (*((volatile unsigned int*)CRT_SYS_DVFS_DDSA_reg))
#define  CRT_SYS_DVFS_DDSA_pllddsa_bypass_pi_shift                               (31)
#define  CRT_SYS_DVFS_DDSA_pllddsa_en_pi_debug_shift                             (30)
#define  CRT_SYS_DVFS_DDSA_pllddsa_hs_oc_stop_shift                              (28)
#define  CRT_SYS_DVFS_DDSA_pllddsa_pi_cur_sel_shift                              (26)
#define  CRT_SYS_DVFS_DDSA_pllddsa_sel_oc_mode_shift                             (24)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_done_delay_shift                           (16)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_step_shift                                 (4)
#define  CRT_SYS_DVFS_DDSA_pllddsa_sdm_order_shift                               (2)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_done_shift                                 (1)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_en_shift                                   (0)
#define  CRT_SYS_DVFS_DDSA_pllddsa_bypass_pi_mask                                (0x80000000)
#define  CRT_SYS_DVFS_DDSA_pllddsa_en_pi_debug_mask                              (0x40000000)
#define  CRT_SYS_DVFS_DDSA_pllddsa_hs_oc_stop_mask                               (0x30000000)
#define  CRT_SYS_DVFS_DDSA_pllddsa_pi_cur_sel_mask                               (0x0C000000)
#define  CRT_SYS_DVFS_DDSA_pllddsa_sel_oc_mode_mask                              (0x03000000)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_done_delay_mask                            (0x003F0000)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_step_mask                                  (0x00003FF0)
#define  CRT_SYS_DVFS_DDSA_pllddsa_sdm_order_mask                                (0x00000004)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_done_mask                                  (0x00000002)
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_en_mask                                    (0x00000001)
#define  CRT_SYS_DVFS_DDSA_pllddsa_bypass_pi(data)                               (0x80000000&((data)<<31))
#define  CRT_SYS_DVFS_DDSA_pllddsa_en_pi_debug(data)                             (0x40000000&((data)<<30))
#define  CRT_SYS_DVFS_DDSA_pllddsa_hs_oc_stop(data)                              (0x30000000&((data)<<28))
#define  CRT_SYS_DVFS_DDSA_pllddsa_pi_cur_sel(data)                              (0x0C000000&((data)<<26))
#define  CRT_SYS_DVFS_DDSA_pllddsa_sel_oc_mode(data)                             (0x03000000&((data)<<24))
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_done_delay(data)                           (0x003F0000&((data)<<16))
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_step(data)                                 (0x00003FF0&((data)<<4))
#define  CRT_SYS_DVFS_DDSA_pllddsa_sdm_order(data)                               (0x00000004&((data)<<2))
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_done(data)                                 (0x00000002&((data)<<1))
#define  CRT_SYS_DVFS_DDSA_pllddsa_oc_en(data)                                   (0x00000001&(data))
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_bypass_pi(data)                           ((0x80000000&(data))>>31)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_en_pi_debug(data)                         ((0x40000000&(data))>>30)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_hs_oc_stop(data)                          ((0x30000000&(data))>>28)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_pi_cur_sel(data)                          ((0x0C000000&(data))>>26)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_sel_oc_mode(data)                         ((0x03000000&(data))>>24)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_oc_done_delay(data)                       ((0x003F0000&(data))>>16)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_oc_step(data)                             ((0x00003FF0&(data))>>4)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_sdm_order(data)                           ((0x00000004&(data))>>2)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_oc_done(data)                             ((0x00000002&(data))>>1)
#define  CRT_SYS_DVFS_DDSA_get_pllddsa_oc_en(data)                               (0x00000001&(data))

#define  CRT_SYS_DVFS_DDSA2                                                      0x18000484
#define  CRT_SYS_DVFS_DDSA2_reg_addr                                             "0xB8000484"
#define  CRT_SYS_DVFS_DDSA2_reg                                                  0xB8000484
#define  CRT_SYS_DVFS_DDSA2_inst_addr                                            "0x005B"
#define  set_CRT_SYS_DVFS_DDSA2_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_DVFS_DDSA2_reg)=data)
#define  get_CRT_SYS_DVFS_DDSA2_reg                                              (*((volatile unsigned int*)CRT_SYS_DVFS_DDSA2_reg))
#define  CRT_SYS_DVFS_DDSA2_pllddsa_fcode_dbg_shift                              (16)
#define  CRT_SYS_DVFS_DDSA2_pllddsa_ncode_dbg_shift                              (8)
#define  CRT_SYS_DVFS_DDSA2_pllddsa_fcode_dbg_mask                               (0x07FF0000)
#define  CRT_SYS_DVFS_DDSA2_pllddsa_ncode_dbg_mask                               (0x0000FF00)
#define  CRT_SYS_DVFS_DDSA2_pllddsa_fcode_dbg(data)                              (0x07FF0000&((data)<<16))
#define  CRT_SYS_DVFS_DDSA2_pllddsa_ncode_dbg(data)                              (0x0000FF00&((data)<<8))
#define  CRT_SYS_DVFS_DDSA2_get_pllddsa_fcode_dbg(data)                          ((0x07FF0000&(data))>>16)
#define  CRT_SYS_DVFS_DDSA2_get_pllddsa_ncode_dbg(data)                          ((0x0000FF00&(data))>>8)

#define  CRT_AI_CLKCR                                                            0x18000490
#define  CRT_AI_CLKCR_reg_addr                                                   "0xB8000490"
#define  CRT_AI_CLKCR_reg                                                        0xB8000490
#define  CRT_AI_CLKCR_inst_addr                                                  "0x005C"
#define  set_CRT_AI_CLKCR_reg(data)                                              (*((volatile unsigned int*)CRT_AI_CLKCR_reg)=data)
#define  get_CRT_AI_CLKCR_reg                                                    (*((volatile unsigned int*)CRT_AI_CLKCR_reg))
#define  CRT_AI_CLKCR_swsce_shift                                                (25)
#define  CRT_AI_CLKCR_tme_shift                                                  (23)
#define  CRT_AI_CLKCR_tmps_shift                                                 (20)
#define  CRT_AI_CLKCR_psc_shift                                                  (19)
#define  CRT_AI_CLKCR_swcs_shift                                                 (9)
#define  CRT_AI_CLKCR_sd_shift                                                   (1)
#define  CRT_AI_CLKCR_su_shift                                                   (0)
#define  CRT_AI_CLKCR_swsce_mask                                                 (0x02000000)
#define  CRT_AI_CLKCR_tme_mask                                                   (0x00800000)
#define  CRT_AI_CLKCR_tmps_mask                                                  (0x00100000)
#define  CRT_AI_CLKCR_psc_mask                                                   (0x00080000)
#define  CRT_AI_CLKCR_swcs_mask                                                  (0x0000FE00)
#define  CRT_AI_CLKCR_sd_mask                                                    (0x00000002)
#define  CRT_AI_CLKCR_su_mask                                                    (0x00000001)
#define  CRT_AI_CLKCR_swsce(data)                                                (0x02000000&((data)<<25))
#define  CRT_AI_CLKCR_tme(data)                                                  (0x00800000&((data)<<23))
#define  CRT_AI_CLKCR_tmps(data)                                                 (0x00100000&((data)<<20))
#define  CRT_AI_CLKCR_psc(data)                                                  (0x00080000&((data)<<19))
#define  CRT_AI_CLKCR_swcs(data)                                                 (0x0000FE00&((data)<<9))
#define  CRT_AI_CLKCR_sd(data)                                                   (0x00000002&((data)<<1))
#define  CRT_AI_CLKCR_su(data)                                                   (0x00000001&(data))
#define  CRT_AI_CLKCR_get_swsce(data)                                            ((0x02000000&(data))>>25)
#define  CRT_AI_CLKCR_get_tme(data)                                              ((0x00800000&(data))>>23)
#define  CRT_AI_CLKCR_get_tmps(data)                                             ((0x00100000&(data))>>20)
#define  CRT_AI_CLKCR_get_psc(data)                                              ((0x00080000&(data))>>19)
#define  CRT_AI_CLKCR_get_swcs(data)                                             ((0x0000FE00&(data))>>9)
#define  CRT_AI_CLKCR_get_sd(data)                                               ((0x00000002&(data))>>1)
#define  CRT_AI_CLKCR_get_su(data)                                               (0x00000001&(data))

#define  CRT_AI2_CLKCR                                                           0x18000494
#define  CRT_AI2_CLKCR_reg_addr                                                  "0xB8000494"
#define  CRT_AI2_CLKCR_reg                                                       0xB8000494
#define  CRT_AI2_CLKCR_inst_addr                                                 "0x005D"
#define  set_CRT_AI2_CLKCR_reg(data)                                             (*((volatile unsigned int*)CRT_AI2_CLKCR_reg)=data)
#define  get_CRT_AI2_CLKCR_reg                                                   (*((volatile unsigned int*)CRT_AI2_CLKCR_reg))
#define  CRT_AI2_CLKCR_swsce_2_shift                                             (25)
#define  CRT_AI2_CLKCR_tme_2_shift                                               (23)
#define  CRT_AI2_CLKCR_tmps_2_shift                                              (20)
#define  CRT_AI2_CLKCR_psc_2_shift                                               (19)
#define  CRT_AI2_CLKCR_swcs_2_shift                                              (9)
#define  CRT_AI2_CLKCR_sd_2_shift                                                (1)
#define  CRT_AI2_CLKCR_su_2_shift                                                (0)
#define  CRT_AI2_CLKCR_swsce_2_mask                                              (0x02000000)
#define  CRT_AI2_CLKCR_tme_2_mask                                                (0x00800000)
#define  CRT_AI2_CLKCR_tmps_2_mask                                               (0x00100000)
#define  CRT_AI2_CLKCR_psc_2_mask                                                (0x00080000)
#define  CRT_AI2_CLKCR_swcs_2_mask                                               (0x0000FE00)
#define  CRT_AI2_CLKCR_sd_2_mask                                                 (0x00000002)
#define  CRT_AI2_CLKCR_su_2_mask                                                 (0x00000001)
#define  CRT_AI2_CLKCR_swsce_2(data)                                             (0x02000000&((data)<<25))
#define  CRT_AI2_CLKCR_tme_2(data)                                               (0x00800000&((data)<<23))
#define  CRT_AI2_CLKCR_tmps_2(data)                                              (0x00100000&((data)<<20))
#define  CRT_AI2_CLKCR_psc_2(data)                                               (0x00080000&((data)<<19))
#define  CRT_AI2_CLKCR_swcs_2(data)                                              (0x0000FE00&((data)<<9))
#define  CRT_AI2_CLKCR_sd_2(data)                                                (0x00000002&((data)<<1))
#define  CRT_AI2_CLKCR_su_2(data)                                                (0x00000001&(data))
#define  CRT_AI2_CLKCR_get_swsce_2(data)                                         ((0x02000000&(data))>>25)
#define  CRT_AI2_CLKCR_get_tme_2(data)                                           ((0x00800000&(data))>>23)
#define  CRT_AI2_CLKCR_get_tmps_2(data)                                          ((0x00100000&(data))>>20)
#define  CRT_AI2_CLKCR_get_psc_2(data)                                           ((0x00080000&(data))>>19)
#define  CRT_AI2_CLKCR_get_swcs_2(data)                                          ((0x0000FE00&(data))>>9)
#define  CRT_AI2_CLKCR_get_sd_2(data)                                            ((0x00000002&(data))>>1)
#define  CRT_AI2_CLKCR_get_su_2(data)                                            (0x00000001&(data))

#define  CRT_SYS_PLL_WD_OUT                                                      0x180004AC
#define  CRT_SYS_PLL_WD_OUT_reg_addr                                             "0xB80004AC"
#define  CRT_SYS_PLL_WD_OUT_reg                                                  0xB80004AC
#define  CRT_SYS_PLL_WD_OUT_inst_addr                                            "0x005E"
#define  set_CRT_SYS_PLL_WD_OUT_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_WD_OUT_reg)=data)
#define  get_CRT_SYS_PLL_WD_OUT_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_WD_OUT_reg))
#define  CRT_SYS_PLL_WD_OUT_pll27x_wdout_shift                                   (18)
#define  CRT_SYS_PLL_WD_OUT_pllvodma_wdout_shift                                 (17)
#define  CRT_SYS_PLL_WD_OUT_pllkcpu_wdout_shift                                  (16)
#define  CRT_SYS_PLL_WD_OUT_pll512fs_wdout_1_shift                               (15)
#define  CRT_SYS_PLL_WD_OUT_pllaud_status_shift                                  (14)
#define  CRT_SYS_PLL_WD_OUT_pll512fs_wdout_shift                                 (13)
#define  CRT_SYS_PLL_WD_OUT_pllbush_wdout_shift                                  (12)
#define  CRT_SYS_PLL_WD_OUT_pllgpu_wdout_shift                                   (11)
#define  CRT_SYS_PLL_WD_OUT_plldif_wdout_shift                                   (10)
#define  CRT_SYS_PLL_WD_OUT_pllddsb_wdout_shift                                  (8)
#define  CRT_SYS_PLL_WD_OUT_pllscpu_2_wdout_shift                                (7)
#define  CRT_SYS_PLL_WD_OUT_pllbus_wdout_shift                                   (6)
#define  CRT_SYS_PLL_WD_OUT_plldisp_wdout_shift                                  (5)
#define  CRT_SYS_PLL_WD_OUT_pllvcpu2_wdout_shift                                 (4)
#define  CRT_SYS_PLL_WD_OUT_pllddsa_wdout_shift                                  (3)
#define  CRT_SYS_PLL_WD_OUT_pllvcpu_wdout_shift                                  (2)
#define  CRT_SYS_PLL_WD_OUT_pllacpu_wdout_shift                                  (1)
#define  CRT_SYS_PLL_WD_OUT_pllscpu_wdout_shift                                  (0)
#define  CRT_SYS_PLL_WD_OUT_pll27x_wdout_mask                                    (0x00040000)
#define  CRT_SYS_PLL_WD_OUT_pllvodma_wdout_mask                                  (0x00020000)
#define  CRT_SYS_PLL_WD_OUT_pllkcpu_wdout_mask                                   (0x00010000)
#define  CRT_SYS_PLL_WD_OUT_pll512fs_wdout_1_mask                                (0x00008000)
#define  CRT_SYS_PLL_WD_OUT_pllaud_status_mask                                   (0x00004000)
#define  CRT_SYS_PLL_WD_OUT_pll512fs_wdout_mask                                  (0x00002000)
#define  CRT_SYS_PLL_WD_OUT_pllbush_wdout_mask                                   (0x00001000)
#define  CRT_SYS_PLL_WD_OUT_pllgpu_wdout_mask                                    (0x00000800)
#define  CRT_SYS_PLL_WD_OUT_plldif_wdout_mask                                    (0x00000400)
#define  CRT_SYS_PLL_WD_OUT_pllddsb_wdout_mask                                   (0x00000100)
#define  CRT_SYS_PLL_WD_OUT_pllscpu_2_wdout_mask                                 (0x00000080)
#define  CRT_SYS_PLL_WD_OUT_pllbus_wdout_mask                                    (0x00000040)
#define  CRT_SYS_PLL_WD_OUT_plldisp_wdout_mask                                   (0x00000020)
#define  CRT_SYS_PLL_WD_OUT_pllvcpu2_wdout_mask                                  (0x00000010)
#define  CRT_SYS_PLL_WD_OUT_pllddsa_wdout_mask                                   (0x00000008)
#define  CRT_SYS_PLL_WD_OUT_pllvcpu_wdout_mask                                   (0x00000004)
#define  CRT_SYS_PLL_WD_OUT_pllacpu_wdout_mask                                   (0x00000002)
#define  CRT_SYS_PLL_WD_OUT_pllscpu_wdout_mask                                   (0x00000001)
#define  CRT_SYS_PLL_WD_OUT_pll27x_wdout(data)                                   (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_WD_OUT_pllvodma_wdout(data)                                 (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_WD_OUT_pllkcpu_wdout(data)                                  (0x00010000&((data)<<16))
#define  CRT_SYS_PLL_WD_OUT_pll512fs_wdout_1(data)                               (0x00008000&((data)<<15))
#define  CRT_SYS_PLL_WD_OUT_pllaud_status(data)                                  (0x00004000&((data)<<14))
#define  CRT_SYS_PLL_WD_OUT_pll512fs_wdout(data)                                 (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_WD_OUT_pllbush_wdout(data)                                  (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_WD_OUT_pllgpu_wdout(data)                                   (0x00000800&((data)<<11))
#define  CRT_SYS_PLL_WD_OUT_plldif_wdout(data)                                   (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_WD_OUT_pllddsb_wdout(data)                                  (0x00000100&((data)<<8))
#define  CRT_SYS_PLL_WD_OUT_pllscpu_2_wdout(data)                                (0x00000080&((data)<<7))
#define  CRT_SYS_PLL_WD_OUT_pllbus_wdout(data)                                   (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_WD_OUT_plldisp_wdout(data)                                  (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_WD_OUT_pllvcpu2_wdout(data)                                 (0x00000010&((data)<<4))
#define  CRT_SYS_PLL_WD_OUT_pllddsa_wdout(data)                                  (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_WD_OUT_pllvcpu_wdout(data)                                  (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_WD_OUT_pllacpu_wdout(data)                                  (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_WD_OUT_pllscpu_wdout(data)                                  (0x00000001&(data))
#define  CRT_SYS_PLL_WD_OUT_get_pll27x_wdout(data)                               ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_WD_OUT_get_pllvodma_wdout(data)                             ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_WD_OUT_get_pllkcpu_wdout(data)                              ((0x00010000&(data))>>16)
#define  CRT_SYS_PLL_WD_OUT_get_pll512fs_wdout_1(data)                           ((0x00008000&(data))>>15)
#define  CRT_SYS_PLL_WD_OUT_get_pllaud_status(data)                              ((0x00004000&(data))>>14)
#define  CRT_SYS_PLL_WD_OUT_get_pll512fs_wdout(data)                             ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_WD_OUT_get_pllbush_wdout(data)                              ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_WD_OUT_get_pllgpu_wdout(data)                               ((0x00000800&(data))>>11)
#define  CRT_SYS_PLL_WD_OUT_get_plldif_wdout(data)                               ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_WD_OUT_get_pllddsb_wdout(data)                              ((0x00000100&(data))>>8)
#define  CRT_SYS_PLL_WD_OUT_get_pllscpu_2_wdout(data)                            ((0x00000080&(data))>>7)
#define  CRT_SYS_PLL_WD_OUT_get_pllbus_wdout(data)                               ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_WD_OUT_get_plldisp_wdout(data)                              ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_WD_OUT_get_pllvcpu2_wdout(data)                             ((0x00000010&(data))>>4)
#define  CRT_SYS_PLL_WD_OUT_get_pllddsa_wdout(data)                              ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_WD_OUT_get_pllvcpu_wdout(data)                              ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_WD_OUT_get_pllacpu_wdout(data)                              ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_WD_OUT_get_pllscpu_wdout(data)                              (0x00000001&(data))

#define  CRT_SYS_PLL_512FS_1                                                     0x180004B0
#define  CRT_SYS_PLL_512FS_1_reg_addr                                            "0xB80004B0"
#define  CRT_SYS_PLL_512FS_1_reg                                                 0xB80004B0
#define  CRT_SYS_PLL_512FS_1_inst_addr                                           "0x005F"
#define  set_CRT_SYS_PLL_512FS_1_reg(data)                                       (*((volatile unsigned int*)CRT_SYS_PLL_512FS_1_reg)=data)
#define  get_CRT_SYS_PLL_512FS_1_reg                                             (*((volatile unsigned int*)CRT_SYS_PLL_512FS_1_reg))
#define  CRT_SYS_PLL_512FS_1_pll512fs_n_shift                                    (28)
#define  CRT_SYS_PLL_512FS_1_pll512fs_m_shift                                    (20)
#define  CRT_SYS_PLL_512FS_1_pll512fs_bpn_shift                                  (19)
#define  CRT_SYS_PLL_512FS_1_pll512fs_bps_shift                                  (18)
#define  CRT_SYS_PLL_512FS_1_pll512fs_cs_shift                                   (16)
#define  CRT_SYS_PLL_512FS_1_pll512fs_ip_shift                                   (12)
#define  CRT_SYS_PLL_512FS_1_pll512fs_s_shift                                    (9)
#define  CRT_SYS_PLL_512FS_1_pll512fs_q_shift                                    (6)
#define  CRT_SYS_PLL_512FS_1_pll512fs_rs_shift                                   (3)
#define  CRT_SYS_PLL_512FS_1_pll512fs_tst_shift                                  (2)
#define  CRT_SYS_PLL_512FS_1_pll512fs_wdrst_shift                                (1)
#define  CRT_SYS_PLL_512FS_1_pll512fs_wdset_shift                                (0)
#define  CRT_SYS_PLL_512FS_1_pll512fs_n_mask                                     (0x70000000)
#define  CRT_SYS_PLL_512FS_1_pll512fs_m_mask                                     (0x07F00000)
#define  CRT_SYS_PLL_512FS_1_pll512fs_bpn_mask                                   (0x00080000)
#define  CRT_SYS_PLL_512FS_1_pll512fs_bps_mask                                   (0x00040000)
#define  CRT_SYS_PLL_512FS_1_pll512fs_cs_mask                                    (0x00030000)
#define  CRT_SYS_PLL_512FS_1_pll512fs_ip_mask                                    (0x00007000)
#define  CRT_SYS_PLL_512FS_1_pll512fs_s_mask                                     (0x00000E00)
#define  CRT_SYS_PLL_512FS_1_pll512fs_q_mask                                     (0x000001C0)
#define  CRT_SYS_PLL_512FS_1_pll512fs_rs_mask                                    (0x00000038)
#define  CRT_SYS_PLL_512FS_1_pll512fs_tst_mask                                   (0x00000004)
#define  CRT_SYS_PLL_512FS_1_pll512fs_wdrst_mask                                 (0x00000002)
#define  CRT_SYS_PLL_512FS_1_pll512fs_wdset_mask                                 (0x00000001)
#define  CRT_SYS_PLL_512FS_1_pll512fs_n(data)                                    (0x70000000&((data)<<28))
#define  CRT_SYS_PLL_512FS_1_pll512fs_m(data)                                    (0x07F00000&((data)<<20))
#define  CRT_SYS_PLL_512FS_1_pll512fs_bpn(data)                                  (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_512FS_1_pll512fs_bps(data)                                  (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_512FS_1_pll512fs_cs(data)                                   (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_512FS_1_pll512fs_ip(data)                                   (0x00007000&((data)<<12))
#define  CRT_SYS_PLL_512FS_1_pll512fs_s(data)                                    (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_512FS_1_pll512fs_q(data)                                    (0x000001C0&((data)<<6))
#define  CRT_SYS_PLL_512FS_1_pll512fs_rs(data)                                   (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_512FS_1_pll512fs_tst(data)                                  (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_512FS_1_pll512fs_wdrst(data)                                (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_512FS_1_pll512fs_wdset(data)                                (0x00000001&(data))
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_n(data)                                ((0x70000000&(data))>>28)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_m(data)                                ((0x07F00000&(data))>>20)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_bpn(data)                              ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_bps(data)                              ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_cs(data)                               ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_ip(data)                               ((0x00007000&(data))>>12)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_s(data)                                ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_q(data)                                ((0x000001C0&(data))>>6)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_rs(data)                               ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_tst(data)                              ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_wdrst(data)                            ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_512FS_1_get_pll512fs_wdset(data)                            (0x00000001&(data))

#define  CRT_SYS_PLL_512FS_2                                                     0x180004B4
#define  CRT_SYS_PLL_512FS_2_reg_addr                                            "0xB80004B4"
#define  CRT_SYS_PLL_512FS_2_reg                                                 0xB80004B4
#define  CRT_SYS_PLL_512FS_2_inst_addr                                           "0x0060"
#define  set_CRT_SYS_PLL_512FS_2_reg(data)                                       (*((volatile unsigned int*)CRT_SYS_PLL_512FS_2_reg)=data)
#define  get_CRT_SYS_PLL_512FS_2_reg                                             (*((volatile unsigned int*)CRT_SYS_PLL_512FS_2_reg))
#define  CRT_SYS_PLL_512FS_2_pll512fs_oeb_shift                                  (2)
#define  CRT_SYS_PLL_512FS_2_pll512fs_rstb_shift                                 (1)
#define  CRT_SYS_PLL_512FS_2_pll512fs_pow_shift                                  (0)
#define  CRT_SYS_PLL_512FS_2_pll512fs_oeb_mask                                   (0x00000004)
#define  CRT_SYS_PLL_512FS_2_pll512fs_rstb_mask                                  (0x00000002)
#define  CRT_SYS_PLL_512FS_2_pll512fs_pow_mask                                   (0x00000001)
#define  CRT_SYS_PLL_512FS_2_pll512fs_oeb(data)                                  (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_512FS_2_pll512fs_rstb(data)                                 (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_512FS_2_pll512fs_pow(data)                                  (0x00000001&(data))
#define  CRT_SYS_PLL_512FS_2_get_pll512fs_oeb(data)                              ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_512FS_2_get_pll512fs_rstb(data)                             ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_512FS_2_get_pll512fs_pow(data)                              (0x00000001&(data))

#define  CRT_SYS_PLL_512FS2_1                                                    0x180004B8
#define  CRT_SYS_PLL_512FS2_1_reg_addr                                           "0xB80004B8"
#define  CRT_SYS_PLL_512FS2_1_reg                                                0xB80004B8
#define  CRT_SYS_PLL_512FS2_1_inst_addr                                          "0x0061"
#define  set_CRT_SYS_PLL_512FS2_1_reg(data)                                      (*((volatile unsigned int*)CRT_SYS_PLL_512FS2_1_reg)=data)
#define  get_CRT_SYS_PLL_512FS2_1_reg                                            (*((volatile unsigned int*)CRT_SYS_PLL_512FS2_1_reg))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_n2_shift                                  (28)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_m2_shift                                  (20)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_bpn2_shift                                (19)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_bps2_shift                                (18)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_cs2_shift                                 (16)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_ip2_shift                                 (12)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_s2_shift                                  (9)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_q2_shift                                  (6)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_rs2_shift                                 (3)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_tst2_shift                                (2)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_wdrst2_shift                              (1)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_wdset2_shift                              (0)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_n2_mask                                   (0x70000000)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_m2_mask                                   (0x07F00000)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_bpn2_mask                                 (0x00080000)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_bps2_mask                                 (0x00040000)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_cs2_mask                                  (0x00030000)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_ip2_mask                                  (0x00007000)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_s2_mask                                   (0x00000E00)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_q2_mask                                   (0x000001C0)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_rs2_mask                                  (0x00000038)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_tst2_mask                                 (0x00000004)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_wdrst2_mask                               (0x00000002)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_wdset2_mask                               (0x00000001)
#define  CRT_SYS_PLL_512FS2_1_pll512fs_n2(data)                                  (0x70000000&((data)<<28))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_m2(data)                                  (0x07F00000&((data)<<20))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_bpn2(data)                                (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_bps2(data)                                (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_cs2(data)                                 (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_ip2(data)                                 (0x00007000&((data)<<12))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_s2(data)                                  (0x00000E00&((data)<<9))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_q2(data)                                  (0x000001C0&((data)<<6))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_rs2(data)                                 (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_tst2(data)                                (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_wdrst2(data)                              (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_512FS2_1_pll512fs_wdset2(data)                              (0x00000001&(data))
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_n2(data)                              ((0x70000000&(data))>>28)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_m2(data)                              ((0x07F00000&(data))>>20)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_bpn2(data)                            ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_bps2(data)                            ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_cs2(data)                             ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_ip2(data)                             ((0x00007000&(data))>>12)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_s2(data)                              ((0x00000E00&(data))>>9)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_q2(data)                              ((0x000001C0&(data))>>6)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_rs2(data)                             ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_tst2(data)                            ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_wdrst2(data)                          ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_512FS2_1_get_pll512fs_wdset2(data)                          (0x00000001&(data))

#define  CRT_SYS_PLL_512FS2_2                                                    0x180004BC
#define  CRT_SYS_PLL_512FS2_2_reg_addr                                           "0xB80004BC"
#define  CRT_SYS_PLL_512FS2_2_reg                                                0xB80004BC
#define  CRT_SYS_PLL_512FS2_2_inst_addr                                          "0x0062"
#define  set_CRT_SYS_PLL_512FS2_2_reg(data)                                      (*((volatile unsigned int*)CRT_SYS_PLL_512FS2_2_reg)=data)
#define  get_CRT_SYS_PLL_512FS2_2_reg                                            (*((volatile unsigned int*)CRT_SYS_PLL_512FS2_2_reg))
#define  CRT_SYS_PLL_512FS2_2_pll512fs_oeb2_shift                                (2)
#define  CRT_SYS_PLL_512FS2_2_pll512fs_rstb2_shift                               (1)
#define  CRT_SYS_PLL_512FS2_2_pll512fs_pow2_shift                                (0)
#define  CRT_SYS_PLL_512FS2_2_pll512fs_oeb2_mask                                 (0x00000004)
#define  CRT_SYS_PLL_512FS2_2_pll512fs_rstb2_mask                                (0x00000002)
#define  CRT_SYS_PLL_512FS2_2_pll512fs_pow2_mask                                 (0x00000001)
#define  CRT_SYS_PLL_512FS2_2_pll512fs_oeb2(data)                                (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_512FS2_2_pll512fs_rstb2(data)                               (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_512FS2_2_pll512fs_pow2(data)                                (0x00000001&(data))
#define  CRT_SYS_PLL_512FS2_2_get_pll512fs_oeb2(data)                            ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_512FS2_2_get_pll512fs_rstb2(data)                           ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_512FS2_2_get_pll512fs_pow2(data)                            (0x00000001&(data))

#define  CRT_SYS_PLL_DIF1                                                        0x180004C0
#define  CRT_SYS_PLL_DIF1_reg_addr                                               "0xB80004C0"
#define  CRT_SYS_PLL_DIF1_reg                                                    0xB80004C0
#define  CRT_SYS_PLL_DIF1_inst_addr                                              "0x0063"
#define  set_CRT_SYS_PLL_DIF1_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DIF1_reg)=data)
#define  get_CRT_SYS_PLL_DIF1_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DIF1_reg))
#define  CRT_SYS_PLL_DIF1_plldif_n_shift                                         (28)
#define  CRT_SYS_PLL_DIF1_plldif_m_shift                                         (20)
#define  CRT_SYS_PLL_DIF1_plldif_ip_shift                                        (16)
#define  CRT_SYS_PLL_DIF1_plldif_lf_rs_shift                                     (14)
#define  CRT_SYS_PLL_DIF1_plldif_lf_cp_shift                                     (12)
#define  CRT_SYS_PLL_DIF1_plldif_n_mask                                          (0x30000000)
#define  CRT_SYS_PLL_DIF1_plldif_m_mask                                          (0x07F00000)
#define  CRT_SYS_PLL_DIF1_plldif_ip_mask                                         (0x00070000)
#define  CRT_SYS_PLL_DIF1_plldif_lf_rs_mask                                      (0x0000C000)
#define  CRT_SYS_PLL_DIF1_plldif_lf_cp_mask                                      (0x00003000)
#define  CRT_SYS_PLL_DIF1_plldif_n(data)                                         (0x30000000&((data)<<28))
#define  CRT_SYS_PLL_DIF1_plldif_m(data)                                         (0x07F00000&((data)<<20))
#define  CRT_SYS_PLL_DIF1_plldif_ip(data)                                        (0x00070000&((data)<<16))
#define  CRT_SYS_PLL_DIF1_plldif_lf_rs(data)                                     (0x0000C000&((data)<<14))
#define  CRT_SYS_PLL_DIF1_plldif_lf_cp(data)                                     (0x00003000&((data)<<12))
#define  CRT_SYS_PLL_DIF1_get_plldif_n(data)                                     ((0x30000000&(data))>>28)
#define  CRT_SYS_PLL_DIF1_get_plldif_m(data)                                     ((0x07F00000&(data))>>20)
#define  CRT_SYS_PLL_DIF1_get_plldif_ip(data)                                    ((0x00070000&(data))>>16)
#define  CRT_SYS_PLL_DIF1_get_plldif_lf_rs(data)                                 ((0x0000C000&(data))>>14)
#define  CRT_SYS_PLL_DIF1_get_plldif_lf_cp(data)                                 ((0x00003000&(data))>>12)

#define  CRT_SYS_PLL_DIF2                                                        0x180004C4
#define  CRT_SYS_PLL_DIF2_reg_addr                                               "0xB80004C4"
#define  CRT_SYS_PLL_DIF2_reg                                                    0xB80004C4
#define  CRT_SYS_PLL_DIF2_inst_addr                                              "0x0064"
#define  set_CRT_SYS_PLL_DIF2_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DIF2_reg)=data)
#define  get_CRT_SYS_PLL_DIF2_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DIF2_reg))
#define  CRT_SYS_PLL_DIF2_plldif_dvbs2_en_shift                                  (12)
#define  CRT_SYS_PLL_DIF2_plldif_wdmode_shift                                    (8)
#define  CRT_SYS_PLL_DIF2_plldif_divdig_sel_shift                                (4)
#define  CRT_SYS_PLL_DIF2_plldif_divadc_sel_shift                                (0)
#define  CRT_SYS_PLL_DIF2_plldif_dvbs2_en_mask                                   (0x00001000)
#define  CRT_SYS_PLL_DIF2_plldif_wdmode_mask                                     (0x00000300)
#define  CRT_SYS_PLL_DIF2_plldif_divdig_sel_mask                                 (0x00000070)
#define  CRT_SYS_PLL_DIF2_plldif_divadc_sel_mask                                 (0x00000007)
#define  CRT_SYS_PLL_DIF2_plldif_dvbs2_en(data)                                  (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_DIF2_plldif_wdmode(data)                                    (0x00000300&((data)<<8))
#define  CRT_SYS_PLL_DIF2_plldif_divdig_sel(data)                                (0x00000070&((data)<<4))
#define  CRT_SYS_PLL_DIF2_plldif_divadc_sel(data)                                (0x00000007&(data))
#define  CRT_SYS_PLL_DIF2_get_plldif_dvbs2_en(data)                              ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_DIF2_get_plldif_wdmode(data)                                ((0x00000300&(data))>>8)
#define  CRT_SYS_PLL_DIF2_get_plldif_divdig_sel(data)                            ((0x00000070&(data))>>4)
#define  CRT_SYS_PLL_DIF2_get_plldif_divadc_sel(data)                            (0x00000007&(data))

#define  CRT_SYS_PLL_DIF3                                                        0x180004C8
#define  CRT_SYS_PLL_DIF3_reg_addr                                               "0xB80004C8"
#define  CRT_SYS_PLL_DIF3_reg                                                    0xB80004C8
#define  CRT_SYS_PLL_DIF3_inst_addr                                              "0x0065"
#define  set_CRT_SYS_PLL_DIF3_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DIF3_reg)=data)
#define  get_CRT_SYS_PLL_DIF3_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DIF3_reg))
#define  CRT_SYS_PLL_DIF3_plldif_vco_rstb_shift                                  (2)
#define  CRT_SYS_PLL_DIF3_plldif_rstb_shift                                      (1)
#define  CRT_SYS_PLL_DIF3_plldif_pow_shift                                       (0)
#define  CRT_SYS_PLL_DIF3_plldif_vco_rstb_mask                                   (0x00000004)
#define  CRT_SYS_PLL_DIF3_plldif_rstb_mask                                       (0x00000002)
#define  CRT_SYS_PLL_DIF3_plldif_pow_mask                                        (0x00000001)
#define  CRT_SYS_PLL_DIF3_plldif_vco_rstb(data)                                  (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DIF3_plldif_rstb(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DIF3_plldif_pow(data)                                       (0x00000001&(data))
#define  CRT_SYS_PLL_DIF3_get_plldif_vco_rstb(data)                              ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DIF3_get_plldif_rstb(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DIF3_get_plldif_pow(data)                                   (0x00000001&(data))

#define  CRT_SYS_PLL_27X1                                                        0x180004D0
#define  CRT_SYS_PLL_27X1_reg_addr                                               "0xB80004D0"
#define  CRT_SYS_PLL_27X1_reg                                                    0xB80004D0
#define  CRT_SYS_PLL_27X1_inst_addr                                              "0x0066"
#define  set_CRT_SYS_PLL_27X1_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_27X1_reg)=data)
#define  get_CRT_SYS_PLL_27X1_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_27X1_reg))
#define  CRT_SYS_PLL_27X1_pll27x_wdmode_shift                                    (28)
#define  CRT_SYS_PLL_27X1_pll27x_lf_cp_shift                                     (24)
#define  CRT_SYS_PLL_27X1_pll27x_lf_rs_shift                                     (20)
#define  CRT_SYS_PLL_27X1_pll27x_ip_shift                                        (16)
#define  CRT_SYS_PLL_27X1_pll27x_n_shift                                         (8)
#define  CRT_SYS_PLL_27X1_pll27x_m_shift                                         (0)
#define  CRT_SYS_PLL_27X1_pll27x_wdmode_mask                                     (0x30000000)
#define  CRT_SYS_PLL_27X1_pll27x_lf_cp_mask                                      (0x03000000)
#define  CRT_SYS_PLL_27X1_pll27x_lf_rs_mask                                      (0x00300000)
#define  CRT_SYS_PLL_27X1_pll27x_ip_mask                                         (0x00070000)
#define  CRT_SYS_PLL_27X1_pll27x_n_mask                                          (0x00000300)
#define  CRT_SYS_PLL_27X1_pll27x_m_mask                                          (0x0000007F)
#define  CRT_SYS_PLL_27X1_pll27x_wdmode(data)                                    (0x30000000&((data)<<28))
#define  CRT_SYS_PLL_27X1_pll27x_lf_cp(data)                                     (0x03000000&((data)<<24))
#define  CRT_SYS_PLL_27X1_pll27x_lf_rs(data)                                     (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_27X1_pll27x_ip(data)                                        (0x00070000&((data)<<16))
#define  CRT_SYS_PLL_27X1_pll27x_n(data)                                         (0x00000300&((data)<<8))
#define  CRT_SYS_PLL_27X1_pll27x_m(data)                                         (0x0000007F&(data))
#define  CRT_SYS_PLL_27X1_get_pll27x_wdmode(data)                                ((0x30000000&(data))>>28)
#define  CRT_SYS_PLL_27X1_get_pll27x_lf_cp(data)                                 ((0x03000000&(data))>>24)
#define  CRT_SYS_PLL_27X1_get_pll27x_lf_rs(data)                                 ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_27X1_get_pll27x_ip(data)                                    ((0x00070000&(data))>>16)
#define  CRT_SYS_PLL_27X1_get_pll27x_n(data)                                     ((0x00000300&(data))>>8)
#define  CRT_SYS_PLL_27X1_get_pll27x_m(data)                                     (0x0000007F&(data))

#define  CRT_SYS_PLL_27X2                                                        0x180004D4
#define  CRT_SYS_PLL_27X2_reg_addr                                               "0xB80004D4"
#define  CRT_SYS_PLL_27X2_reg                                                    0xB80004D4
#define  CRT_SYS_PLL_27X2_inst_addr                                              "0x0067"
#define  set_CRT_SYS_PLL_27X2_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_27X2_reg)=data)
#define  get_CRT_SYS_PLL_27X2_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_27X2_reg))
#define  CRT_SYS_PLL_27X2_xi_cap_shift                                           (28)
#define  CRT_SYS_PLL_27X2_xo_cap_shift                                           (24)
#define  CRT_SYS_PLL_27X2_vdd11_pad_sel_shift                                    (22)
#define  CRT_SYS_PLL_27X2_pll_ldo_xtal_sel_shift                                 (20)
#define  CRT_SYS_PLL_27X2_pll_xixo_load_shift                                    (18)
#define  CRT_SYS_PLL_27X2_pll_xixo_drive_sel_shift                               (16)
#define  CRT_SYS_PLL_27X2_pll_pow_ldo11v_shift                                   (14)
#define  CRT_SYS_PLL_27X2_pll_ldo11v_sel_shift                                   (12)
#define  CRT_SYS_PLL_27X2_pll_pow_ldo_shift                                      (10)
#define  CRT_SYS_PLL_27X2_pll_ldo_sel_shift                                      (8)
#define  CRT_SYS_PLL_27X2_pll27x_ps_54m_delay_shift                              (4)
#define  CRT_SYS_PLL_27X2_pll27x_ps_psel_pulse_w_shift                           (1)
#define  CRT_SYS_PLL_27X2_pll27x_ps_duty_sel_shift                               (0)
#define  CRT_SYS_PLL_27X2_xi_cap_mask                                            (0xF0000000)
#define  CRT_SYS_PLL_27X2_xo_cap_mask                                            (0x0F000000)
#define  CRT_SYS_PLL_27X2_vdd11_pad_sel_mask                                     (0x00C00000)
#define  CRT_SYS_PLL_27X2_pll_ldo_xtal_sel_mask                                  (0x00300000)
#define  CRT_SYS_PLL_27X2_pll_xixo_load_mask                                     (0x00040000)
#define  CRT_SYS_PLL_27X2_pll_xixo_drive_sel_mask                                (0x00030000)
#define  CRT_SYS_PLL_27X2_pll_pow_ldo11v_mask                                    (0x00004000)
#define  CRT_SYS_PLL_27X2_pll_ldo11v_sel_mask                                    (0x00003000)
#define  CRT_SYS_PLL_27X2_pll_pow_ldo_mask                                       (0x00000400)
#define  CRT_SYS_PLL_27X2_pll_ldo_sel_mask                                       (0x00000300)
#define  CRT_SYS_PLL_27X2_pll27x_ps_54m_delay_mask                               (0x00000030)
#define  CRT_SYS_PLL_27X2_pll27x_ps_psel_pulse_w_mask                            (0x00000002)
#define  CRT_SYS_PLL_27X2_pll27x_ps_duty_sel_mask                                (0x00000001)
#define  CRT_SYS_PLL_27X2_xi_cap(data)                                           (0xF0000000&((data)<<28))
#define  CRT_SYS_PLL_27X2_xo_cap(data)                                           (0x0F000000&((data)<<24))
#define  CRT_SYS_PLL_27X2_vdd11_pad_sel(data)                                    (0x00C00000&((data)<<22))
#define  CRT_SYS_PLL_27X2_pll_ldo_xtal_sel(data)                                 (0x00300000&((data)<<20))
#define  CRT_SYS_PLL_27X2_pll_xixo_load(data)                                    (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_27X2_pll_xixo_drive_sel(data)                               (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_27X2_pll_pow_ldo11v(data)                                   (0x00004000&((data)<<14))
#define  CRT_SYS_PLL_27X2_pll_ldo11v_sel(data)                                   (0x00003000&((data)<<12))
#define  CRT_SYS_PLL_27X2_pll_pow_ldo(data)                                      (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_27X2_pll_ldo_sel(data)                                      (0x00000300&((data)<<8))
#define  CRT_SYS_PLL_27X2_pll27x_ps_54m_delay(data)                              (0x00000030&((data)<<4))
#define  CRT_SYS_PLL_27X2_pll27x_ps_psel_pulse_w(data)                           (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_27X2_pll27x_ps_duty_sel(data)                               (0x00000001&(data))
#define  CRT_SYS_PLL_27X2_get_xi_cap(data)                                       ((0xF0000000&(data))>>28)
#define  CRT_SYS_PLL_27X2_get_xo_cap(data)                                       ((0x0F000000&(data))>>24)
#define  CRT_SYS_PLL_27X2_get_vdd11_pad_sel(data)                                ((0x00C00000&(data))>>22)
#define  CRT_SYS_PLL_27X2_get_pll_ldo_xtal_sel(data)                             ((0x00300000&(data))>>20)
#define  CRT_SYS_PLL_27X2_get_pll_xixo_load(data)                                ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_27X2_get_pll_xixo_drive_sel(data)                           ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_27X2_get_pll_pow_ldo11v(data)                               ((0x00004000&(data))>>14)
#define  CRT_SYS_PLL_27X2_get_pll_ldo11v_sel(data)                               ((0x00003000&(data))>>12)
#define  CRT_SYS_PLL_27X2_get_pll_pow_ldo(data)                                  ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_27X2_get_pll_ldo_sel(data)                                  ((0x00000300&(data))>>8)
#define  CRT_SYS_PLL_27X2_get_pll27x_ps_54m_delay(data)                          ((0x00000030&(data))>>4)
#define  CRT_SYS_PLL_27X2_get_pll27x_ps_psel_pulse_w(data)                       ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_27X2_get_pll27x_ps_duty_sel(data)                           (0x00000001&(data))

#define  CRT_SYS_PLL_27X3                                                        0x180004D8
#define  CRT_SYS_PLL_27X3_reg_addr                                               "0xB80004D8"
#define  CRT_SYS_PLL_27X3_reg                                                    0xB80004D8
#define  CRT_SYS_PLL_27X3_inst_addr                                              "0x0068"
#define  set_CRT_SYS_PLL_27X3_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_27X3_reg)=data)
#define  get_CRT_SYS_PLL_27X3_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_27X3_reg))
#define  CRT_SYS_PLL_27X3_pll_reserve_shift                                      (8)
#define  CRT_SYS_PLL_27X3_pll27x_ps_en_shift                                     (4)
#define  CRT_SYS_PLL_27X3_pll27x_ps_div2_shift                                   (3)
#define  CRT_SYS_PLL_27X3_pll27x_vcorstb_shift                                   (2)
#define  CRT_SYS_PLL_27X3_pll27x_rstb_shift                                      (1)
#define  CRT_SYS_PLL_27X3_pll27x_pow_shift                                       (0)
#define  CRT_SYS_PLL_27X3_pll_reserve_mask                                       (0x0000FF00)
#define  CRT_SYS_PLL_27X3_pll27x_ps_en_mask                                      (0x00000010)
#define  CRT_SYS_PLL_27X3_pll27x_ps_div2_mask                                    (0x00000008)
#define  CRT_SYS_PLL_27X3_pll27x_vcorstb_mask                                    (0x00000004)
#define  CRT_SYS_PLL_27X3_pll27x_rstb_mask                                       (0x00000002)
#define  CRT_SYS_PLL_27X3_pll27x_pow_mask                                        (0x00000001)
#define  CRT_SYS_PLL_27X3_pll_reserve(data)                                      (0x0000FF00&((data)<<8))
#define  CRT_SYS_PLL_27X3_pll27x_ps_en(data)                                     (0x00000010&((data)<<4))
#define  CRT_SYS_PLL_27X3_pll27x_ps_div2(data)                                   (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_27X3_pll27x_vcorstb(data)                                   (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_27X3_pll27x_rstb(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_27X3_pll27x_pow(data)                                       (0x00000001&(data))
#define  CRT_SYS_PLL_27X3_get_pll_reserve(data)                                  ((0x0000FF00&(data))>>8)
#define  CRT_SYS_PLL_27X3_get_pll27x_ps_en(data)                                 ((0x00000010&(data))>>4)
#define  CRT_SYS_PLL_27X3_get_pll27x_ps_div2(data)                               ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_27X3_get_pll27x_vcorstb(data)                               ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_27X3_get_pll27x_rstb(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_27X3_get_pll27x_pow(data)                                   (0x00000001&(data))

#define  CRT_SYS_PLL_27X4                                                        0x180004DC
#define  CRT_SYS_PLL_27X4_reg_addr                                               "0xB80004DC"
#define  CRT_SYS_PLL_27X4_reg                                                    0xB80004DC
#define  CRT_SYS_PLL_27X4_inst_addr                                              "0x0069"
#define  set_CRT_SYS_PLL_27X4_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_27X4_reg)=data)
#define  get_CRT_SYS_PLL_27X4_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_27X4_reg))
#define  CRT_SYS_PLL_27X4_dummy1_shift                                            (31)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_duty_shift                                (29)
#define  CRT_SYS_PLL_27X4_dummy2_shift                                            (28)
#define  CRT_SYS_PLL_27X4_pll_yppadc_cko_polar_shift                             (27)
#define  CRT_SYS_PLL_27X4_pll_ifadc_cko_polar_shift                              (26)
#define  CRT_SYS_PLL_27X4_pll_l2h_cml_pow_shift                                  (25)
#define  CRT_SYS_PLL_27X4_pll27x_d16_en_shift                                    (24)
#define  CRT_SYS_PLL_27X4_pll27x_pll_tst_shift                                   (21)
#define  CRT_SYS_PLL_27X4_pll27x_en_tst_shift                                    (20)
#define  CRT_SYS_PLL_27X4_pll_rssi_cko_en_shift                                  (19)
#define  CRT_SYS_PLL_27X4_pll27x_ck108m_en_shift                                 (18)
#define  CRT_SYS_PLL_27X4_pll27x_ck108m_div_shift                                (16)
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_cko_sel_shift                            (14)
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_cko_en_shift                             (13)
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_ck54m_en_shift                           (12)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_cko_sel_shift                             (10)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_div_shift                                 (9)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_cko_en_shift                              (8)
#define  CRT_SYS_PLL_27X4_pllaud_ckin_mux_shift                                  (4)
#define  CRT_SYS_PLL_27X4_pll_xtalwd_rst_shift                                   (3)
#define  CRT_SYS_PLL_27X4_pll_xtalwd_set_shift                                   (2)
#define  CRT_SYS_PLL_27X4_pll_ck_ifadc_mux_shift                                 (0)
#define  CRT_SYS_PLL_27X4_dummy1_mask                                             (0x80000000)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_duty_mask                                 (0x60000000)
#define  CRT_SYS_PLL_27X4_dummy2_mask                                             (0x10000000)
#define  CRT_SYS_PLL_27X4_pll_yppadc_cko_polar_mask                              (0x08000000)
#define  CRT_SYS_PLL_27X4_pll_ifadc_cko_polar_mask                               (0x04000000)
#define  CRT_SYS_PLL_27X4_pll_l2h_cml_pow_mask                                   (0x02000000)
#define  CRT_SYS_PLL_27X4_pll27x_d16_en_mask                                     (0x01000000)
#define  CRT_SYS_PLL_27X4_pll27x_pll_tst_mask                                    (0x00E00000)
#define  CRT_SYS_PLL_27X4_pll27x_en_tst_mask                                     (0x00100000)
#define  CRT_SYS_PLL_27X4_pll_rssi_cko_en_mask                                   (0x00080000)
#define  CRT_SYS_PLL_27X4_pll27x_ck108m_en_mask                                  (0x00040000)
#define  CRT_SYS_PLL_27X4_pll27x_ck108m_div_mask                                 (0x00030000)
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_cko_sel_mask                             (0x0000C000)
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_cko_en_mask                              (0x00002000)
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_ck54m_en_mask                            (0x00001000)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_cko_sel_mask                              (0x00000C00)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_div_mask                                  (0x00000200)
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_cko_en_mask                               (0x00000100)
#define  CRT_SYS_PLL_27X4_pllaud_ckin_mux_mask                                   (0x00000010)
#define  CRT_SYS_PLL_27X4_pll_xtalwd_rst_mask                                    (0x00000008)
#define  CRT_SYS_PLL_27X4_pll_xtalwd_set_mask                                    (0x00000004)
#define  CRT_SYS_PLL_27X4_pll_ck_ifadc_mux_mask                                  (0x00000001)
#define  CRT_SYS_PLL_27X4_dummy1(data)                                            (0x80000000&((data)<<31))
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_duty(data)                                (0x60000000&((data)<<29))
#define  CRT_SYS_PLL_27X4_dummy2(data)                                            (0x10000000&((data)<<28))
#define  CRT_SYS_PLL_27X4_pll_yppadc_cko_polar(data)                             (0x08000000&((data)<<27))
#define  CRT_SYS_PLL_27X4_pll_ifadc_cko_polar(data)                              (0x04000000&((data)<<26))
#define  CRT_SYS_PLL_27X4_pll_l2h_cml_pow(data)                                  (0x02000000&((data)<<25))
#define  CRT_SYS_PLL_27X4_pll27x_d16_en(data)                                    (0x01000000&((data)<<24))
#define  CRT_SYS_PLL_27X4_pll27x_pll_tst(data)                                   (0x00E00000&((data)<<21))
#define  CRT_SYS_PLL_27X4_pll27x_en_tst(data)                                    (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_27X4_pll_rssi_cko_en(data)                                  (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_27X4_pll27x_ck108m_en(data)                                 (0x00040000&((data)<<18))
#define  CRT_SYS_PLL_27X4_pll27x_ck108m_div(data)                                (0x00030000&((data)<<16))
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_cko_sel(data)                            (0x0000C000&((data)<<14))
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_cko_en(data)                             (0x00002000&((data)<<13))
#define  CRT_SYS_PLL_27X4_pll27x_yppadc_ck54m_en(data)                           (0x00001000&((data)<<12))
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_cko_sel(data)                             (0x00000C00&((data)<<10))
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_div(data)                                 (0x00000200&((data)<<9))
#define  CRT_SYS_PLL_27X4_pll27x_ifadc_cko_en(data)                              (0x00000100&((data)<<8))
#define  CRT_SYS_PLL_27X4_pllaud_ckin_mux(data)                                  (0x00000010&((data)<<4))
#define  CRT_SYS_PLL_27X4_pll_xtalwd_rst(data)                                   (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_27X4_pll_xtalwd_set(data)                                   (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_27X4_pll_ck_ifadc_mux(data)                                 (0x00000001&(data))
#define  CRT_SYS_PLL_27X4_get_dummy1(data)                                        ((0x80000000&(data))>>31)
#define  CRT_SYS_PLL_27X4_get_pll27x_ifadc_duty(data)                            ((0x60000000&(data))>>29)
#define  CRT_SYS_PLL_27X4_get_dummy2(data)                                        ((0x10000000&(data))>>28)
#define  CRT_SYS_PLL_27X4_get_pll_yppadc_cko_polar(data)                         ((0x08000000&(data))>>27)
#define  CRT_SYS_PLL_27X4_get_pll_ifadc_cko_polar(data)                          ((0x04000000&(data))>>26)
#define  CRT_SYS_PLL_27X4_get_pll_l2h_cml_pow(data)                              ((0x02000000&(data))>>25)
#define  CRT_SYS_PLL_27X4_get_pll27x_d16_en(data)                                ((0x01000000&(data))>>24)
#define  CRT_SYS_PLL_27X4_get_pll27x_pll_tst(data)                               ((0x00E00000&(data))>>21)
#define  CRT_SYS_PLL_27X4_get_pll27x_en_tst(data)                                ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_27X4_get_pll_rssi_cko_en(data)                              ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_27X4_get_pll27x_ck108m_en(data)                             ((0x00040000&(data))>>18)
#define  CRT_SYS_PLL_27X4_get_pll27x_ck108m_div(data)                            ((0x00030000&(data))>>16)
#define  CRT_SYS_PLL_27X4_get_pll27x_yppadc_cko_sel(data)                        ((0x0000C000&(data))>>14)
#define  CRT_SYS_PLL_27X4_get_pll27x_yppadc_cko_en(data)                         ((0x00002000&(data))>>13)
#define  CRT_SYS_PLL_27X4_get_pll27x_yppadc_ck54m_en(data)                       ((0x00001000&(data))>>12)
#define  CRT_SYS_PLL_27X4_get_pll27x_ifadc_cko_sel(data)                         ((0x00000C00&(data))>>10)
#define  CRT_SYS_PLL_27X4_get_pll27x_ifadc_div(data)                             ((0x00000200&(data))>>9)
#define  CRT_SYS_PLL_27X4_get_pll27x_ifadc_cko_en(data)                          ((0x00000100&(data))>>8)
#define  CRT_SYS_PLL_27X4_get_pllaud_ckin_mux(data)                              ((0x00000010&(data))>>4)
#define  CRT_SYS_PLL_27X4_get_pll_xtalwd_rst(data)                               ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_27X4_get_pll_xtalwd_set(data)                               ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_27X4_get_pll_ck_ifadc_mux(data)                             (0x00000001&(data))

#define  CRT_SYS_PLL_AUD1                                                        0x180004E0
#define  CRT_SYS_PLL_AUD1_reg_addr                                               "0xB80004E0"
#define  CRT_SYS_PLL_AUD1_reg                                                    0xB80004E0
#define  CRT_SYS_PLL_AUD1_inst_addr                                              "0x006A"
#define  set_CRT_SYS_PLL_AUD1_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_AUD1_reg)=data)
#define  get_CRT_SYS_PLL_AUD1_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_AUD1_reg))
#define  CRT_SYS_PLL_AUD1_pllaud_ip_shift                                        (15)
#define  CRT_SYS_PLL_AUD1_pllaud_rs_shift                                        (11)
#define  CRT_SYS_PLL_AUD1_pllaud_cp_shift                                        (8)
#define  CRT_SYS_PLL_AUD1_pllaud_wdrst_shift                                     (2)
#define  CRT_SYS_PLL_AUD1_pllaud_wdset_shift                                     (1)
#define  CRT_SYS_PLL_AUD1_pllaud_tst_shift                                       (0)
#define  CRT_SYS_PLL_AUD1_pllaud_ip_mask                                         (0x00038000)
#define  CRT_SYS_PLL_AUD1_pllaud_rs_mask                                         (0x00001800)
#define  CRT_SYS_PLL_AUD1_pllaud_cp_mask                                         (0x00000300)
#define  CRT_SYS_PLL_AUD1_pllaud_wdrst_mask                                      (0x00000004)
#define  CRT_SYS_PLL_AUD1_pllaud_wdset_mask                                      (0x00000002)
#define  CRT_SYS_PLL_AUD1_pllaud_tst_mask                                        (0x00000001)
#define  CRT_SYS_PLL_AUD1_pllaud_ip(data)                                        (0x00038000&((data)<<15))
#define  CRT_SYS_PLL_AUD1_pllaud_rs(data)                                        (0x00001800&((data)<<11))
#define  CRT_SYS_PLL_AUD1_pllaud_cp(data)                                        (0x00000300&((data)<<8))
#define  CRT_SYS_PLL_AUD1_pllaud_wdrst(data)                                     (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_AUD1_pllaud_wdset(data)                                     (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_AUD1_pllaud_tst(data)                                       (0x00000001&(data))
#define  CRT_SYS_PLL_AUD1_get_pllaud_ip(data)                                    ((0x00038000&(data))>>15)
#define  CRT_SYS_PLL_AUD1_get_pllaud_rs(data)                                    ((0x00001800&(data))>>11)
#define  CRT_SYS_PLL_AUD1_get_pllaud_cp(data)                                    ((0x00000300&(data))>>8)
#define  CRT_SYS_PLL_AUD1_get_pllaud_wdrst(data)                                 ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_AUD1_get_pllaud_wdset(data)                                 ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_AUD1_get_pllaud_tst(data)                                   (0x00000001&(data))

#define  CRT_SYS_PLL_AUD3                                                        0x180004E4
#define  CRT_SYS_PLL_AUD3_reg_addr                                               "0xB80004E4"
#define  CRT_SYS_PLL_AUD3_reg                                                    0xB80004E4
#define  CRT_SYS_PLL_AUD3_inst_addr                                              "0x006B"
#define  set_CRT_SYS_PLL_AUD3_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_AUD3_reg)=data)
#define  get_CRT_SYS_PLL_AUD3_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_AUD3_reg))
#define  CRT_SYS_PLL_AUD3_pllaud_vcorstb_shift                                   (4)
#define  CRT_SYS_PLL_AUD3_pllaud_rstb_shift                                      (3)
#define  CRT_SYS_PLL_AUD3_pllaud_oeb1_shift                                      (2)
#define  CRT_SYS_PLL_AUD3_pllaud_oeb2_shift                                      (1)
#define  CRT_SYS_PLL_AUD3_pllaud_pow_shift                                       (0)
#define  CRT_SYS_PLL_AUD3_pllaud_vcorstb_mask                                    (0x00000010)
#define  CRT_SYS_PLL_AUD3_pllaud_rstb_mask                                       (0x00000008)
#define  CRT_SYS_PLL_AUD3_pllaud_oeb1_mask                                       (0x00000004)
#define  CRT_SYS_PLL_AUD3_pllaud_oeb2_mask                                       (0x00000002)
#define  CRT_SYS_PLL_AUD3_pllaud_pow_mask                                        (0x00000001)
#define  CRT_SYS_PLL_AUD3_pllaud_vcorstb(data)                                   (0x00000010&((data)<<4))
#define  CRT_SYS_PLL_AUD3_pllaud_rstb(data)                                      (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_AUD3_pllaud_oeb1(data)                                      (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_AUD3_pllaud_oeb2(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_AUD3_pllaud_pow(data)                                       (0x00000001&(data))
#define  CRT_SYS_PLL_AUD3_get_pllaud_vcorstb(data)                               ((0x00000010&(data))>>4)
#define  CRT_SYS_PLL_AUD3_get_pllaud_rstb(data)                                  ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_AUD3_get_pllaud_oeb1(data)                                  ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_AUD3_get_pllaud_oeb2(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_AUD3_get_pllaud_pow(data)                                   (0x00000001&(data))

#define  CRT_SYS_PLL_AUD4                                                        0x180004E8
#define  CRT_SYS_PLL_AUD4_reg_addr                                               "0xB80004E8"
#define  CRT_SYS_PLL_AUD4_reg                                                    0xB80004E8
#define  CRT_SYS_PLL_AUD4_inst_addr                                              "0x006C"
#define  set_CRT_SYS_PLL_AUD4_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_AUD4_reg)=data)
#define  get_CRT_SYS_PLL_AUD4_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_AUD4_reg))
#define  CRT_SYS_PLL_AUD4_bb_micbias_clksel_shift                                (0)
#define  CRT_SYS_PLL_AUD4_bb_micbias_clksel_mask                                 (0x00000003)
#define  CRT_SYS_PLL_AUD4_bb_micbias_clksel(data)                                (0x00000003&(data))
#define  CRT_SYS_PLL_AUD4_get_bb_micbias_clksel(data)                            (0x00000003&(data))

#define  CRT_SYS_PLL_PSAUD1                                                      0x180004F0
#define  CRT_SYS_PLL_PSAUD1_reg_addr                                             "0xB80004F0"
#define  CRT_SYS_PLL_PSAUD1_reg                                                  0xB80004F0
#define  CRT_SYS_PLL_PSAUD1_inst_addr                                            "0x006D"
#define  set_CRT_SYS_PLL_PSAUD1_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_PSAUD1_reg)=data)
#define  get_CRT_SYS_PLL_PSAUD1_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_PSAUD1_reg))
#define  CRT_SYS_PLL_PSAUD1_psaud_adder_mode_shift                               (4)
#define  CRT_SYS_PLL_PSAUD1_psaud_psen_shift                                     (3)
#define  CRT_SYS_PLL_PSAUD1_psaud_en_shift                                       (2)
#define  CRT_SYS_PLL_PSAUD1_psaud_tst_shift                                      (1)
#define  CRT_SYS_PLL_PSAUD1_psaud_ctrl_shift                                     (0)
#define  CRT_SYS_PLL_PSAUD1_psaud_adder_mode_mask                                (0x00000010)
#define  CRT_SYS_PLL_PSAUD1_psaud_psen_mask                                      (0x00000008)
#define  CRT_SYS_PLL_PSAUD1_psaud_en_mask                                        (0x00000004)
#define  CRT_SYS_PLL_PSAUD1_psaud_tst_mask                                       (0x00000002)
#define  CRT_SYS_PLL_PSAUD1_psaud_ctrl_mask                                      (0x00000001)
#define  CRT_SYS_PLL_PSAUD1_psaud_adder_mode(data)                               (0x00000010&((data)<<4))
#define  CRT_SYS_PLL_PSAUD1_psaud_psen(data)                                     (0x00000008&((data)<<3))
#define  CRT_SYS_PLL_PSAUD1_psaud_en(data)                                       (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_PSAUD1_psaud_tst(data)                                      (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_PSAUD1_psaud_ctrl(data)                                     (0x00000001&(data))
#define  CRT_SYS_PLL_PSAUD1_get_psaud_adder_mode(data)                           ((0x00000010&(data))>>4)
#define  CRT_SYS_PLL_PSAUD1_get_psaud_psen(data)                                 ((0x00000008&(data))>>3)
#define  CRT_SYS_PLL_PSAUD1_get_psaud_en(data)                                   ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_PSAUD1_get_psaud_tst(data)                                  ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_PSAUD1_get_psaud_ctrl(data)                                 (0x00000001&(data))

#define  CRT_SYS_PLL_PSAUD2                                                      0x180004F4
#define  CRT_SYS_PLL_PSAUD2_reg_addr                                             "0xB80004F4"
#define  CRT_SYS_PLL_PSAUD2_reg                                                  0xB80004F4
#define  CRT_SYS_PLL_PSAUD2_inst_addr                                            "0x006E"
#define  set_CRT_SYS_PLL_PSAUD2_reg(data)                                        (*((volatile unsigned int*)CRT_SYS_PLL_PSAUD2_reg)=data)
#define  get_CRT_SYS_PLL_PSAUD2_reg                                              (*((volatile unsigned int*)CRT_SYS_PLL_PSAUD2_reg))
#define  CRT_SYS_PLL_PSAUD2_psaud_div_shift                                      (0)
#define  CRT_SYS_PLL_PSAUD2_psaud_div_mask                                       (0x0000000F)
#define  CRT_SYS_PLL_PSAUD2_psaud_div(data)                                      (0x0000000F&(data))
#define  CRT_SYS_PLL_PSAUD2_get_psaud_div(data)                                  (0x0000000F&(data))

#define  CRT_SYS_PLL_DDR0                                                        0x18000500
#define  CRT_SYS_PLL_DDR0_reg_addr                                               "0xB8000500"
#define  CRT_SYS_PLL_DDR0_reg                                                    0xB8000500
#define  CRT_SYS_PLL_DDR0_inst_addr                                              "0x006F"
#define  set_CRT_SYS_PLL_DDR0_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR0_reg)=data)
#define  get_CRT_SYS_PLL_DDR0_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR0_reg))
#define  CRT_SYS_PLL_DDR0_reg_dpi_cco_band_shift                                 (30)
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel2_shift                             (25)
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel1_shift                             (20)
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel0_shift                             (15)
#define  CRT_SYS_PLL_DDR0_reg_dpi_en_post_pi_shift                               (7)
#define  CRT_SYS_PLL_DDR0_reg_dpi_mck_clk_en_shift                               (0)
#define  CRT_SYS_PLL_DDR0_reg_dpi_cco_band_mask                                  (0xC0000000)
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel2_mask                              (0x3E000000)
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel1_mask                              (0x01F00000)
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel0_mask                              (0x000F8000)
#define  CRT_SYS_PLL_DDR0_reg_dpi_en_post_pi_mask                                (0x00007F80)
#define  CRT_SYS_PLL_DDR0_reg_dpi_mck_clk_en_mask                                (0x0000007F)
#define  CRT_SYS_PLL_DDR0_reg_dpi_cco_band(data)                                 (0xC0000000&((data)<<30))
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel2(data)                             (0x3E000000&((data)<<25))
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel1(data)                             (0x01F00000&((data)<<20))
#define  CRT_SYS_PLL_DDR0_reg_dpi_post_pi_sel0(data)                             (0x000F8000&((data)<<15))
#define  CRT_SYS_PLL_DDR0_reg_dpi_en_post_pi(data)                               (0x00007F80&((data)<<7))
#define  CRT_SYS_PLL_DDR0_reg_dpi_mck_clk_en(data)                               (0x0000007F&(data))
#define  CRT_SYS_PLL_DDR0_get_reg_dpi_cco_band(data)                             ((0xC0000000&(data))>>30)
#define  CRT_SYS_PLL_DDR0_get_reg_dpi_post_pi_sel2(data)                         ((0x3E000000&(data))>>25)
#define  CRT_SYS_PLL_DDR0_get_reg_dpi_post_pi_sel1(data)                         ((0x01F00000&(data))>>20)
#define  CRT_SYS_PLL_DDR0_get_reg_dpi_post_pi_sel0(data)                         ((0x000F8000&(data))>>15)
#define  CRT_SYS_PLL_DDR0_get_reg_dpi_en_post_pi(data)                           ((0x00007F80&(data))>>7)
#define  CRT_SYS_PLL_DDR0_get_reg_dpi_mck_clk_en(data)                           (0x0000007F&(data))

#define  CRT_SYS_PLL_DDR1                                                        0x18000504
#define  CRT_SYS_PLL_DDR1_reg_addr                                               "0xB8000504"
#define  CRT_SYS_PLL_DDR1_reg                                                    0xB8000504
#define  CRT_SYS_PLL_DDR1_inst_addr                                              "0x0070"
#define  set_CRT_SYS_PLL_DDR1_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR1_reg)=data)
#define  get_CRT_SYS_PLL_DDR1_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR1_reg))
#define  CRT_SYS_PLL_DDR1_reg_dpi_lpf_sr_shift                                   (29)
#define  CRT_SYS_PLL_DDR1_reg_dpi_lpf_cp_shift                                   (28)
#define  CRT_SYS_PLL_DDR1_reg_dpi_loop_pi_isel_shift                             (24)
#define  CRT_SYS_PLL_DDR1_reg_dpi_icp_shift                                      (20)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel6_shift                             (15)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel5_shift                             (10)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel4_shift                             (5)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel3_shift                             (0)
#define  CRT_SYS_PLL_DDR1_reg_dpi_lpf_sr_mask                                    (0xE0000000)
#define  CRT_SYS_PLL_DDR1_reg_dpi_lpf_cp_mask                                    (0x10000000)
#define  CRT_SYS_PLL_DDR1_reg_dpi_loop_pi_isel_mask                              (0x0F000000)
#define  CRT_SYS_PLL_DDR1_reg_dpi_icp_mask                                       (0x00F00000)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel6_mask                              (0x000F8000)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel5_mask                              (0x00007C00)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel4_mask                              (0x000003E0)
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel3_mask                              (0x0000001F)
#define  CRT_SYS_PLL_DDR1_reg_dpi_lpf_sr(data)                                   (0xE0000000&((data)<<29))
#define  CRT_SYS_PLL_DDR1_reg_dpi_lpf_cp(data)                                   (0x10000000&((data)<<28))
#define  CRT_SYS_PLL_DDR1_reg_dpi_loop_pi_isel(data)                             (0x0F000000&((data)<<24))
#define  CRT_SYS_PLL_DDR1_reg_dpi_icp(data)                                      (0x00F00000&((data)<<20))
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel6(data)                             (0x000F8000&((data)<<15))
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel5(data)                             (0x00007C00&((data)<<10))
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel4(data)                             (0x000003E0&((data)<<5))
#define  CRT_SYS_PLL_DDR1_reg_dpi_post_pi_sel3(data)                             (0x0000001F&(data))
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_lpf_sr(data)                               ((0xE0000000&(data))>>29)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_lpf_cp(data)                               ((0x10000000&(data))>>28)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_loop_pi_isel(data)                         ((0x0F000000&(data))>>24)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_icp(data)                                  ((0x00F00000&(data))>>20)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel6(data)                         ((0x000F8000&(data))>>15)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel5(data)                         ((0x00007C00&(data))>>10)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel4(data)                         ((0x000003E0&(data))>>5)
#define  CRT_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel3(data)                         (0x0000001F&(data))

#define  CRT_SYS_PLL_DDR2                                                        0x18000508
#define  CRT_SYS_PLL_DDR2_reg_addr                                               "0xB8000508"
#define  CRT_SYS_PLL_DDR2_reg                                                    0xB8000508
#define  CRT_SYS_PLL_DDR2_inst_addr                                              "0x0071"
#define  set_CRT_SYS_PLL_DDR2_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR2_reg)=data)
#define  get_CRT_SYS_PLL_DDR2_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR2_reg))
#define  CRT_SYS_PLL_DDR2_reg_dpi_n_code_shift                                   (24)
#define  CRT_SYS_PLL_DDR2_reg_dpi_en_ssc_shift                                   (23)
#define  CRT_SYS_PLL_DDR2_reg_dpi_bypass_pi_shift                                (22)
#define  CRT_SYS_PLL_DDR2_reg_dpi_f_code_shift                                   (11)
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_rs_shift                               (10)
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_rl_shift                               (8)
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_bias_shift                             (6)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_sel_cpmode_shift                           (5)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_ldo_vsel_shift                             (3)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_dbug_en_shift                              (2)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pdiv_shift                                     (0)
#define  CRT_SYS_PLL_DDR2_reg_dpi_n_code_mask                                    (0xFF000000)
#define  CRT_SYS_PLL_DDR2_reg_dpi_en_ssc_mask                                    (0x00800000)
#define  CRT_SYS_PLL_DDR2_reg_dpi_bypass_pi_mask                                 (0x00400000)
#define  CRT_SYS_PLL_DDR2_reg_dpi_f_code_mask                                    (0x003FF800)
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_rs_mask                                (0x00000400)
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_rl_mask                                (0x00000300)
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_bias_mask                              (0x000000C0)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_sel_cpmode_mask                            (0x00000020)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_ldo_vsel_mask                              (0x00000018)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_dbug_en_mask                               (0x00000004)
#define  CRT_SYS_PLL_DDR2_reg_dpi_pdiv_mask                                      (0x00000003)
#define  CRT_SYS_PLL_DDR2_reg_dpi_n_code(data)                                   (0xFF000000&((data)<<24))
#define  CRT_SYS_PLL_DDR2_reg_dpi_en_ssc(data)                                   (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR2_reg_dpi_bypass_pi(data)                                (0x00400000&((data)<<22))
#define  CRT_SYS_PLL_DDR2_reg_dpi_f_code(data)                                   (0x003FF800&((data)<<11))
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_rs(data)                               (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_rl(data)                               (0x00000300&((data)<<8))
#define  CRT_SYS_PLL_DDR2_reg_dpi_post_pi_bias(data)                             (0x000000C0&((data)<<6))
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_sel_cpmode(data)                           (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_ldo_vsel(data)                             (0x00000018&((data)<<3))
#define  CRT_SYS_PLL_DDR2_reg_dpi_pll_dbug_en(data)                              (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DDR2_reg_dpi_pdiv(data)                                     (0x00000003&(data))
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_n_code(data)                               ((0xFF000000&(data))>>24)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_en_ssc(data)                               ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_bypass_pi(data)                            ((0x00400000&(data))>>22)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_f_code(data)                               ((0x003FF800&(data))>>11)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_post_pi_rs(data)                           ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_post_pi_rl(data)                           ((0x00000300&(data))>>8)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_post_pi_bias(data)                         ((0x000000C0&(data))>>6)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_pll_sel_cpmode(data)                       ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_pll_ldo_vsel(data)                         ((0x00000018&(data))>>3)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_pll_dbug_en(data)                          ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DDR2_get_reg_dpi_pdiv(data)                                 (0x00000003&(data))

#define  CRT_SYS_PLL_DDR3                                                        0x1800050C
#define  CRT_SYS_PLL_DDR3_reg_addr                                               "0xB800050C"
#define  CRT_SYS_PLL_DDR3_reg                                                    0xB800050C
#define  CRT_SYS_PLL_DDR3_inst_addr                                              "0x0072"
#define  set_CRT_SYS_PLL_DDR3_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR3_reg)=data)
#define  get_CRT_SYS_PLL_DDR3_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR3_reg))
#define  CRT_SYS_PLL_DDR3_reg_dpi_cco_kvco_shift                                 (31)
#define  CRT_SYS_PLL_DDR3_reg_dpi_oc_en_shift                                    (30)
#define  CRT_SYS_PLL_DDR3_reg_dpi_oc_step_set_shift                              (20)
#define  CRT_SYS_PLL_DDR3_reg_dpi_f_code_t_shift                                 (9)
#define  CRT_SYS_PLL_DDR3_reg_dpi_n_code_t_shift                                 (1)
#define  CRT_SYS_PLL_DDR3_reg_dpi_order_shift                                    (0)
#define  CRT_SYS_PLL_DDR3_reg_dpi_cco_kvco_mask                                  (0x80000000)
#define  CRT_SYS_PLL_DDR3_reg_dpi_oc_en_mask                                     (0x40000000)
#define  CRT_SYS_PLL_DDR3_reg_dpi_oc_step_set_mask                               (0x3FF00000)
#define  CRT_SYS_PLL_DDR3_reg_dpi_f_code_t_mask                                  (0x000FFE00)
#define  CRT_SYS_PLL_DDR3_reg_dpi_n_code_t_mask                                  (0x000001FE)
#define  CRT_SYS_PLL_DDR3_reg_dpi_order_mask                                     (0x00000001)
#define  CRT_SYS_PLL_DDR3_reg_dpi_cco_kvco(data)                                 (0x80000000&((data)<<31))
#define  CRT_SYS_PLL_DDR3_reg_dpi_oc_en(data)                                    (0x40000000&((data)<<30))
#define  CRT_SYS_PLL_DDR3_reg_dpi_oc_step_set(data)                              (0x3FF00000&((data)<<20))
#define  CRT_SYS_PLL_DDR3_reg_dpi_f_code_t(data)                                 (0x000FFE00&((data)<<9))
#define  CRT_SYS_PLL_DDR3_reg_dpi_n_code_t(data)                                 (0x000001FE&((data)<<1))
#define  CRT_SYS_PLL_DDR3_reg_dpi_order(data)                                    (0x00000001&(data))
#define  CRT_SYS_PLL_DDR3_get_reg_dpi_cco_kvco(data)                             ((0x80000000&(data))>>31)
#define  CRT_SYS_PLL_DDR3_get_reg_dpi_oc_en(data)                                ((0x40000000&(data))>>30)
#define  CRT_SYS_PLL_DDR3_get_reg_dpi_oc_step_set(data)                          ((0x3FF00000&(data))>>20)
#define  CRT_SYS_PLL_DDR3_get_reg_dpi_f_code_t(data)                             ((0x000FFE00&(data))>>9)
#define  CRT_SYS_PLL_DDR3_get_reg_dpi_n_code_t(data)                             ((0x000001FE&(data))>>1)
#define  CRT_SYS_PLL_DDR3_get_reg_dpi_order(data)                                (0x00000001&(data))

#define  CRT_SYS_PLL_DDR4                                                        0x18000510
#define  CRT_SYS_PLL_DDR4_reg_addr                                               "0xB8000510"
#define  CRT_SYS_PLL_DDR4_reg                                                    0xB8000510
#define  CRT_SYS_PLL_DDR4_inst_addr                                              "0x0073"
#define  set_CRT_SYS_PLL_DDR4_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR4_reg)=data)
#define  get_CRT_SYS_PLL_DDR4_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR4_reg))
#define  CRT_SYS_PLL_DDR4_reg_dpi_dot_gran_shift                                 (29)
#define  CRT_SYS_PLL_DDR4_reg_dpi_gran_set_shift                                 (10)
#define  CRT_SYS_PLL_DDR4_reg_dpi_oc_done_delay_shift                            (4)
#define  CRT_SYS_PLL_DDR4_reg_dpi_hs_oc_stop_diff_shift                          (2)
#define  CRT_SYS_PLL_DDR4_reg_dpi_sel_oc_mode_shift                              (0)
#define  CRT_SYS_PLL_DDR4_reg_dpi_dot_gran_mask                                  (0xE0000000)
#define  CRT_SYS_PLL_DDR4_reg_dpi_gran_set_mask                                  (0x1FFFFC00)
#define  CRT_SYS_PLL_DDR4_reg_dpi_oc_done_delay_mask                             (0x000003F0)
#define  CRT_SYS_PLL_DDR4_reg_dpi_hs_oc_stop_diff_mask                           (0x0000000C)
#define  CRT_SYS_PLL_DDR4_reg_dpi_sel_oc_mode_mask                               (0x00000003)
#define  CRT_SYS_PLL_DDR4_reg_dpi_dot_gran(data)                                 (0xE0000000&((data)<<29))
#define  CRT_SYS_PLL_DDR4_reg_dpi_gran_set(data)                                 (0x1FFFFC00&((data)<<10))
#define  CRT_SYS_PLL_DDR4_reg_dpi_oc_done_delay(data)                            (0x000003F0&((data)<<4))
#define  CRT_SYS_PLL_DDR4_reg_dpi_hs_oc_stop_diff(data)                          (0x0000000C&((data)<<2))
#define  CRT_SYS_PLL_DDR4_reg_dpi_sel_oc_mode(data)                              (0x00000003&(data))
#define  CRT_SYS_PLL_DDR4_get_reg_dpi_dot_gran(data)                             ((0xE0000000&(data))>>29)
#define  CRT_SYS_PLL_DDR4_get_reg_dpi_gran_set(data)                             ((0x1FFFFC00&(data))>>10)
#define  CRT_SYS_PLL_DDR4_get_reg_dpi_oc_done_delay(data)                        ((0x000003F0&(data))>>4)
#define  CRT_SYS_PLL_DDR4_get_reg_dpi_hs_oc_stop_diff(data)                      ((0x0000000C&(data))>>2)
#define  CRT_SYS_PLL_DDR4_get_reg_dpi_sel_oc_mode(data)                          (0x00000003&(data))

#define  CRT_SYS_PLL_DDR5                                                        0x18000514
#define  CRT_SYS_PLL_DDR5_reg_addr                                               "0xB8000514"
#define  CRT_SYS_PLL_DDR5_reg                                                    0xB8000514
#define  CRT_SYS_PLL_DDR5_inst_addr                                              "0x0074"
#define  set_CRT_SYS_PLL_DDR5_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR5_reg)=data)
#define  get_CRT_SYS_PLL_DDR5_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR5_reg))
#define  CRT_SYS_PLL_DDR5_reg_dpi_oesync_op_sel_shift                            (18)
#define  CRT_SYS_PLL_DDR5_reg_dpi_clk_oe_shift                                   (11)
#define  CRT_SYS_PLL_DDR5_reg_dpi_time2_rst_width_shift                          (9)
#define  CRT_SYS_PLL_DDR5_reg_dpi_time_rdy_ckout_shift                           (7)
#define  CRT_SYS_PLL_DDR5_reg_dpi_time0_ck_shift                                 (4)
#define  CRT_SYS_PLL_DDR5_reg_dpi_f390k_shift                                    (2)
#define  CRT_SYS_PLL_DDR5_reg_dpi_wd_enable_shift                                (1)
#define  CRT_SYS_PLL_DDR5_reg_dpi_gran_auto_rst_shift                            (0)
#define  CRT_SYS_PLL_DDR5_reg_dpi_oesync_op_sel_mask                             (0x01FC0000)
#define  CRT_SYS_PLL_DDR5_reg_dpi_clk_oe_mask                                    (0x0003F800)
#define  CRT_SYS_PLL_DDR5_reg_dpi_time2_rst_width_mask                           (0x00000600)
#define  CRT_SYS_PLL_DDR5_reg_dpi_time_rdy_ckout_mask                            (0x00000180)
#define  CRT_SYS_PLL_DDR5_reg_dpi_time0_ck_mask                                  (0x00000070)
#define  CRT_SYS_PLL_DDR5_reg_dpi_f390k_mask                                     (0x0000000C)
#define  CRT_SYS_PLL_DDR5_reg_dpi_wd_enable_mask                                 (0x00000002)
#define  CRT_SYS_PLL_DDR5_reg_dpi_gran_auto_rst_mask                             (0x00000001)
#define  CRT_SYS_PLL_DDR5_reg_dpi_oesync_op_sel(data)                            (0x01FC0000&((data)<<18))
#define  CRT_SYS_PLL_DDR5_reg_dpi_clk_oe(data)                                   (0x0003F800&((data)<<11))
#define  CRT_SYS_PLL_DDR5_reg_dpi_time2_rst_width(data)                          (0x00000600&((data)<<9))
#define  CRT_SYS_PLL_DDR5_reg_dpi_time_rdy_ckout(data)                           (0x00000180&((data)<<7))
#define  CRT_SYS_PLL_DDR5_reg_dpi_time0_ck(data)                                 (0x00000070&((data)<<4))
#define  CRT_SYS_PLL_DDR5_reg_dpi_f390k(data)                                    (0x0000000C&((data)<<2))
#define  CRT_SYS_PLL_DDR5_reg_dpi_wd_enable(data)                                (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DDR5_reg_dpi_gran_auto_rst(data)                            (0x00000001&(data))
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_oesync_op_sel(data)                        ((0x01FC0000&(data))>>18)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_clk_oe(data)                               ((0x0003F800&(data))>>11)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_time2_rst_width(data)                      ((0x00000600&(data))>>9)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_time_rdy_ckout(data)                       ((0x00000180&(data))>>7)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_time0_ck(data)                             ((0x00000070&(data))>>4)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_f390k(data)                                ((0x0000000C&(data))>>2)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_wd_enable(data)                            ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DDR5_get_reg_dpi_gran_auto_rst(data)                        (0x00000001&(data))

#define  CRT_SYS_PLL_DDR6                                                        0x18000518
#define  CRT_SYS_PLL_DDR6_reg_addr                                               "0xB8000518"
#define  CRT_SYS_PLL_DDR6_reg                                                    0xB8000518
#define  CRT_SYS_PLL_DDR6_inst_addr                                              "0x0075"
#define  set_CRT_SYS_PLL_DDR6_reg(data)                                          (*((volatile unsigned int*)CRT_SYS_PLL_DDR6_reg)=data)
#define  get_CRT_SYS_PLL_DDR6_reg                                                (*((volatile unsigned int*)CRT_SYS_PLL_DDR6_reg))
#define  CRT_SYS_PLL_DDR6_pll_stable_shift                                       (31)
#define  CRT_SYS_PLL_DDR6_reg_dpi_pll_en_shift                                   (21)
#define  CRT_SYS_PLL_DDR6_reg_dpi_ng_clk_sel_shift                               (19)
#define  CRT_SYS_PLL_DDR6_reg_dpi_v11_ldo_vsel_shift                             (17)
#define  CRT_SYS_PLL_DDR6_reg_dpi_post_pi_sel_shift                              (12)
#define  CRT_SYS_PLL_DDR6_reg_dpi_adj_div2_en_shift                              (11)
#define  CRT_SYS_PLL_DDR6_reg_dpi_ckref_sel_shift                                (10)
#define  CRT_SYS_PLL_DDR6_reg_dpi_dat_rate_sel_shift                             (9)
#define  CRT_SYS_PLL_DDR6_reg_dpi_adr_rate_sel_shift                             (8)
#define  CRT_SYS_PLL_DDR6_reg_dpi_pll_dum_shift                                  (0)
#define  CRT_SYS_PLL_DDR6_pll_stable_mask                                        (0x80000000)
#define  CRT_SYS_PLL_DDR6_reg_dpi_pll_en_mask                                    (0x00200000)
#define  CRT_SYS_PLL_DDR6_reg_dpi_ng_clk_sel_mask                                (0x00180000)
#define  CRT_SYS_PLL_DDR6_reg_dpi_v11_ldo_vsel_mask                              (0x00060000)
#define  CRT_SYS_PLL_DDR6_reg_dpi_post_pi_sel_mask                               (0x0001F000)
#define  CRT_SYS_PLL_DDR6_reg_dpi_adj_div2_en_mask                               (0x00000800)
#define  CRT_SYS_PLL_DDR6_reg_dpi_ckref_sel_mask                                 (0x00000400)
#define  CRT_SYS_PLL_DDR6_reg_dpi_dat_rate_sel_mask                              (0x00000200)
#define  CRT_SYS_PLL_DDR6_reg_dpi_adr_rate_sel_mask                              (0x00000100)
#define  CRT_SYS_PLL_DDR6_reg_dpi_pll_dum_mask                                   (0x000000FF)
#define  CRT_SYS_PLL_DDR6_pll_stable(data)                                       (0x80000000&((data)<<31))
#define  CRT_SYS_PLL_DDR6_reg_dpi_pll_en(data)                                   (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_DDR6_reg_dpi_ng_clk_sel(data)                               (0x00180000&((data)<<19))
#define  CRT_SYS_PLL_DDR6_reg_dpi_v11_ldo_vsel(data)                             (0x00060000&((data)<<17))
#define  CRT_SYS_PLL_DDR6_reg_dpi_post_pi_sel(data)                              (0x0001F000&((data)<<12))
#define  CRT_SYS_PLL_DDR6_reg_dpi_adj_div2_en(data)                              (0x00000800&((data)<<11))
#define  CRT_SYS_PLL_DDR6_reg_dpi_ckref_sel(data)                                (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DDR6_reg_dpi_dat_rate_sel(data)                             (0x00000200&((data)<<9))
#define  CRT_SYS_PLL_DDR6_reg_dpi_adr_rate_sel(data)                             (0x00000100&((data)<<8))
#define  CRT_SYS_PLL_DDR6_reg_dpi_pll_dum(data)                                  (0x000000FF&(data))
#define  CRT_SYS_PLL_DDR6_get_pll_stable(data)                                   ((0x80000000&(data))>>31)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_pll_en(data)                               ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_ng_clk_sel(data)                           ((0x00180000&(data))>>19)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_v11_ldo_vsel(data)                         ((0x00060000&(data))>>17)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_post_pi_sel(data)                          ((0x0001F000&(data))>>12)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_adj_div2_en(data)                          ((0x00000800&(data))>>11)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_ckref_sel(data)                            ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_dat_rate_sel(data)                         ((0x00000200&(data))>>9)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_adr_rate_sel(data)                         ((0x00000100&(data))>>8)
#define  CRT_SYS_PLL_DDR6_get_reg_dpi_pll_dum(data)                              (0x000000FF&(data))

#define  CRT_SYS_PLL_DDR_DCC_CMD                                                 0x1800051C
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_addr                                        "0xB800051C"
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg                                             0xB800051C
#define  CRT_SYS_PLL_DDR_DCC_CMD_inst_addr                                       "0x0076"
#define  set_CRT_SYS_PLL_DDR_DCC_CMD_reg(data)                                   (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_CMD_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_CMD_reg                                         (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_CMD_reg))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_dbg_sel_shift               (23)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_div_shift                       (20)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_stop_shift                  (19)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_int_gain_shift                  (14)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_shift                      (7)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_sel_shift                  (6)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_presetb_shift              (3)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_preseta_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_dbg_sel_mask                (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_div_mask                        (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_stop_mask                   (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_int_gain_mask                   (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_mask                       (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_sel_mask                   (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_presetb_mask               (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_preseta_mask               (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_dbg_sel(data)               (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_div(data)                       (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_stop(data)                  (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_int_gain(data)                  (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty(data)                      (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_sel(data)                  (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_presetb(data)              (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_preseta(data)              (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_dsp_dbg_sel(data)           ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_div(data)                   ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_dsp_stop(data)              ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_int_gain(data)              ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty(data)                  ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty_sel(data)              ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty_presetb(data)          ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty_preseta(data)          (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD0_0                                               0x18000520
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_addr                                      "0xB8000520"
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg                                           0xB8000520
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_inst_addr                                     "0x0077"
#define  set_CRT_SYS_PLL_DDR_DCC_AD0_0_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_0_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD0_0_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_0_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_en_pdout_0_shift                  (29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_ph90_sft_0_shift                  (23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_int_gain_0_shift                  (18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_sel_0_shift                   (17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_0_shift                       (8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_init_value_0_shift                (0)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_en_pdout_0_mask                   (0x20000000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_ph90_sft_0_mask                   (0x1F800000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_int_gain_0_mask                   (0x007C0000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_sel_0_mask                    (0x00020000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_0_mask                        (0x0001FF00)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_init_value_0_mask                 (0x000000FF)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_en_pdout_0(data)                  (0x20000000&((data)<<29))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_ph90_sft_0(data)                  (0x1F800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_int_gain_0(data)                  (0x007C0000&((data)<<18))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_sel_0(data)                   (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_0(data)                       (0x0001FF00&((data)<<8))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_init_value_0(data)                (0x000000FF&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_en_pdout_0(data)              ((0x20000000&(data))>>29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_ph90_sft_0(data)              ((0x1F800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_int_gain_0(data)              ((0x007C0000&(data))>>18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_dly_sel_0(data)               ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_dly_0(data)                   ((0x0001FF00&(data))>>8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_init_value_0(data)            (0x000000FF&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD0_1                                               0x18000524
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_addr                                      "0xB8000524"
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg                                           0xB8000524
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_inst_addr                                     "0x0078"
#define  set_CRT_SYS_PLL_DDR_DCC_AD0_1_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_1_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD0_1_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_1_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_en_pdout_1_shift                  (29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_ph90_sft_1_shift                  (23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_int_gain_1_shift                  (18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_sel_1_shift                   (17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_1_shift                       (8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_init_value_1_shift                (0)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_en_pdout_1_mask                   (0x20000000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_ph90_sft_1_mask                   (0x1F800000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_int_gain_1_mask                   (0x007C0000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_sel_1_mask                    (0x00020000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_1_mask                        (0x0001FF00)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_init_value_1_mask                 (0x000000FF)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_en_pdout_1(data)                  (0x20000000&((data)<<29))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_ph90_sft_1(data)                  (0x1F800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_int_gain_1(data)                  (0x007C0000&((data)<<18))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_sel_1(data)                   (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_1(data)                       (0x0001FF00&((data)<<8))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_init_value_1(data)                (0x000000FF&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_en_pdout_1(data)              ((0x20000000&(data))>>29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_ph90_sft_1(data)              ((0x1F800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_int_gain_1(data)              ((0x007C0000&(data))>>18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_dly_sel_1(data)               ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_dly_1(data)                   ((0x0001FF00&(data))>>8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_init_value_1(data)            (0x000000FF&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD0_2                                               0x18000528
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_addr                                      "0xB8000528"
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg                                           0xB8000528
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_inst_addr                                     "0x0079"
#define  set_CRT_SYS_PLL_DDR_DCC_AD0_2_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_2_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD0_2_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_2_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_en_pdout_2_shift                  (29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_ph90_sft_2_shift                  (23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_int_gain_2_shift                  (18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_sel_2_shift                   (17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_2_shift                       (8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_init_value_2_shift                (0)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_en_pdout_2_mask                   (0x20000000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_ph90_sft_2_mask                   (0x1F800000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_int_gain_2_mask                   (0x007C0000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_sel_2_mask                    (0x00020000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_2_mask                        (0x0001FF00)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_init_value_2_mask                 (0x000000FF)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_en_pdout_2(data)                  (0x20000000&((data)<<29))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_ph90_sft_2(data)                  (0x1F800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_int_gain_2(data)                  (0x007C0000&((data)<<18))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_sel_2(data)                   (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_2(data)                       (0x0001FF00&((data)<<8))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_init_value_2(data)                (0x000000FF&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_en_pdout_2(data)              ((0x20000000&(data))>>29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_ph90_sft_2(data)              ((0x1F800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_int_gain_2(data)              ((0x007C0000&(data))>>18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_dly_sel_2(data)               ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_dly_2(data)                   ((0x0001FF00&(data))>>8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_init_value_2(data)            (0x000000FF&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD0_3                                               0x1800052C
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_addr                                      "0xB800052C"
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg                                           0xB800052C
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_inst_addr                                     "0x007A"
#define  set_CRT_SYS_PLL_DDR_DCC_AD0_3_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_3_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD0_3_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD0_3_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_en_pdout_3_shift                  (29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_ph90_sft_3_shift                  (23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_int_gain_3_shift                  (18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_sel_3_shift                   (17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_3_shift                       (8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_init_value_3_shift                (0)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_en_pdout_3_mask                   (0x20000000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_ph90_sft_3_mask                   (0x1F800000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_int_gain_3_mask                   (0x007C0000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_sel_3_mask                    (0x00020000)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_3_mask                        (0x0001FF00)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_init_value_3_mask                 (0x000000FF)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_en_pdout_3(data)                  (0x20000000&((data)<<29))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_ph90_sft_3(data)                  (0x1F800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_int_gain_3(data)                  (0x007C0000&((data)<<18))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_sel_3(data)                   (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_3(data)                       (0x0001FF00&((data)<<8))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_init_value_3(data)                (0x000000FF&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_en_pdout_3(data)              ((0x20000000&(data))>>29)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_ph90_sft_3(data)              ((0x1F800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_int_gain_3(data)              ((0x007C0000&(data))>>18)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_dly_sel_3(data)               ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_dly_3(data)                   ((0x0001FF00&(data))>>8)
#define  CRT_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_init_value_3(data)            (0x000000FF&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD1_0                                               0x18000530
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_addr                                      "0xB8000530"
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg                                           0xB8000530
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_inst_addr                                     "0x007B"
#define  set_CRT_SYS_PLL_DDR_DCC_AD1_0_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_0_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD1_0_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_0_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_alert_rx_rst_n_0_shift                        (10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_y_onehot_ini_0_shift              (5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_x_onehot_ini_0_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_alert_rx_rst_n_0_mask                         (0x00000400)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_y_onehot_ini_0_mask               (0x000003E0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_x_onehot_ini_0_mask               (0x0000001F)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_alert_rx_rst_n_0(data)                        (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_y_onehot_ini_0(data)              (0x000003E0&((data)<<5))
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_x_onehot_ini_0(data)              (0x0000001F&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_get_alert_rx_rst_n_0(data)                    ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_get_reg_dpi_dll_y_onehot_ini_0(data)          ((0x000003E0&(data))>>5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_0_get_reg_dpi_dll_x_onehot_ini_0(data)          (0x0000001F&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD1_1                                               0x18000534
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_addr                                      "0xB8000534"
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg                                           0xB8000534
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_inst_addr                                     "0x007C"
#define  set_CRT_SYS_PLL_DDR_DCC_AD1_1_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_1_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD1_1_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_1_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_alert_rx_rst_n_1_shift                        (10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_y_onehot_ini_1_shift              (5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_x_onehot_ini_1_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_alert_rx_rst_n_1_mask                         (0x00000400)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_y_onehot_ini_1_mask               (0x000003E0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_x_onehot_ini_1_mask               (0x0000001F)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_alert_rx_rst_n_1(data)                        (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_y_onehot_ini_1(data)              (0x000003E0&((data)<<5))
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_x_onehot_ini_1(data)              (0x0000001F&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_get_alert_rx_rst_n_1(data)                    ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_get_reg_dpi_dll_y_onehot_ini_1(data)          ((0x000003E0&(data))>>5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_1_get_reg_dpi_dll_x_onehot_ini_1(data)          (0x0000001F&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD1_2                                               0x18000538
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_addr                                      "0xB8000538"
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg                                           0xB8000538
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_inst_addr                                     "0x007D"
#define  set_CRT_SYS_PLL_DDR_DCC_AD1_2_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_2_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD1_2_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_2_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_alert_rx_rst_n_2_shift                        (10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_y_onehot_ini_2_shift              (5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_x_onehot_ini_2_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_alert_rx_rst_n_2_mask                         (0x00000400)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_y_onehot_ini_2_mask               (0x000003E0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_x_onehot_ini_2_mask               (0x0000001F)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_alert_rx_rst_n_2(data)                        (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_y_onehot_ini_2(data)              (0x000003E0&((data)<<5))
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_x_onehot_ini_2(data)              (0x0000001F&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_get_alert_rx_rst_n_2(data)                    ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_get_reg_dpi_dll_y_onehot_ini_2(data)          ((0x000003E0&(data))>>5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_2_get_reg_dpi_dll_x_onehot_ini_2(data)          (0x0000001F&(data))

#define  CRT_SYS_PLL_DDR_DCC_AD1_3                                               0x1800053C
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_addr                                      "0xB800053C"
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg                                           0xB800053C
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_inst_addr                                     "0x007E"
#define  set_CRT_SYS_PLL_DDR_DCC_AD1_3_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_3_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_AD1_3_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_AD1_3_reg))
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_alert_rx_rst_n_3_shift                        (10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_y_onehot_ini_3_shift              (5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_x_onehot_ini_3_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_alert_rx_rst_n_3_mask                         (0x00000400)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_y_onehot_ini_3_mask               (0x000003E0)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_x_onehot_ini_3_mask               (0x0000001F)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_alert_rx_rst_n_3(data)                        (0x00000400&((data)<<10))
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_y_onehot_ini_3(data)              (0x000003E0&((data)<<5))
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_x_onehot_ini_3(data)              (0x0000001F&(data))
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_get_alert_rx_rst_n_3(data)                    ((0x00000400&(data))>>10)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_get_reg_dpi_dll_y_onehot_ini_3(data)          ((0x000003E0&(data))>>5)
#define  CRT_SYS_PLL_DDR_DCC_AD1_3_get_reg_dpi_dll_x_onehot_ini_3(data)          (0x0000001F&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQS_0                                               0x18000540
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_addr                                      "0xB8000540"
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg                                           0xB8000540
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_inst_addr                                     "0x007F"
#define  set_CRT_SYS_PLL_DDR_DCC_DQS_0_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_0_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQS_0_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_0_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_dbg_sel_0_shift           (23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_div_0_shift                   (20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_stop_0_shift              (19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_int_gain_0_shift              (14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_0_shift                  (7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_sel_0_shift              (6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_presetb_0_shift          (3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_preseta_0_shift          (0)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_dbg_sel_0_mask            (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_div_0_mask                    (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_stop_0_mask               (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_int_gain_0_mask               (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_0_mask                   (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_sel_0_mask               (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_presetb_0_mask           (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_preseta_0_mask           (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_dbg_sel_0(data)           (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_div_0(data)                   (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_stop_0(data)              (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_int_gain_0(data)              (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_0(data)                  (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_sel_0(data)              (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_presetb_0(data)          (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_preseta_0(data)          (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_dsp_dbg_sel_0(data)       ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_div_0(data)               ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_dsp_stop_0(data)          ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_int_gain_0(data)          ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_0(data)              ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_sel_0(data)          ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_presetb_0(data)      ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_preseta_0(data)      (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQS_1                                               0x18000544
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_addr                                      "0xB8000544"
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg                                           0xB8000544
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_inst_addr                                     "0x0080"
#define  set_CRT_SYS_PLL_DDR_DCC_DQS_1_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_1_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQS_1_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_1_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_dbg_sel_1_shift           (23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_div_1_shift                   (20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_stop_1_shift              (19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_int_gain_1_shift              (14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_1_shift                  (7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_sel_1_shift              (6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_presetb_1_shift          (3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_preseta_1_shift          (0)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_dbg_sel_1_mask            (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_div_1_mask                    (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_stop_1_mask               (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_int_gain_1_mask               (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_1_mask                   (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_sel_1_mask               (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_presetb_1_mask           (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_preseta_1_mask           (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_dbg_sel_1(data)           (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_div_1(data)                   (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_stop_1(data)              (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_int_gain_1(data)              (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_1(data)                  (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_sel_1(data)              (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_presetb_1(data)          (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_preseta_1(data)          (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_dsp_dbg_sel_1(data)       ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_div_1(data)               ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_dsp_stop_1(data)          ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_int_gain_1(data)          ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_1(data)              ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_sel_1(data)          ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_presetb_1(data)      ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_preseta_1(data)      (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQS_2                                               0x18000548
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_addr                                      "0xB8000548"
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg                                           0xB8000548
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_inst_addr                                     "0x0081"
#define  set_CRT_SYS_PLL_DDR_DCC_DQS_2_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_2_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQS_2_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_2_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_dbg_sel_2_shift           (23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_div_2_shift                   (20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_stop_2_shift              (19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_int_gain_2_shift              (14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_2_shift                  (7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_sel_2_shift              (6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_presetb_2_shift          (3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_preseta_2_shift          (0)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_dbg_sel_2_mask            (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_div_2_mask                    (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_stop_2_mask               (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_int_gain_2_mask               (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_2_mask                   (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_sel_2_mask               (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_presetb_2_mask           (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_preseta_2_mask           (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_dbg_sel_2(data)           (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_div_2(data)                   (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_stop_2(data)              (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_int_gain_2(data)              (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_2(data)                  (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_sel_2(data)              (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_presetb_2(data)          (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_preseta_2(data)          (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_dsp_dbg_sel_2(data)       ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_div_2(data)               ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_dsp_stop_2(data)          ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_int_gain_2(data)          ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_2(data)              ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_sel_2(data)          ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_presetb_2(data)      ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_preseta_2(data)      (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQS_3                                               0x1800054C
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_addr                                      "0xB800054C"
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg                                           0xB800054C
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_inst_addr                                     "0x0082"
#define  set_CRT_SYS_PLL_DDR_DCC_DQS_3_reg(data)                                 (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_3_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQS_3_reg                                       (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQS_3_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_dbg_sel_3_shift           (23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_div_3_shift                   (20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_stop_3_shift              (19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_int_gain_3_shift              (14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_3_shift                  (7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_sel_3_shift              (6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_presetb_3_shift          (3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_preseta_3_shift          (0)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_dbg_sel_3_mask            (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_div_3_mask                    (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_stop_3_mask               (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_int_gain_3_mask               (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_3_mask                   (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_sel_3_mask               (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_presetb_3_mask           (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_preseta_3_mask           (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_dbg_sel_3(data)           (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_div_3(data)                   (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_stop_3(data)              (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_int_gain_3(data)              (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_3(data)                  (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_sel_3(data)              (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_presetb_3(data)          (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_preseta_3(data)          (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_dsp_dbg_sel_3(data)       ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_div_3(data)               ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_dsp_stop_3(data)          ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_int_gain_3(data)          ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_3(data)              ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_sel_3(data)          ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_presetb_3(data)      ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_preseta_3(data)      (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQ_0                                                0x18000550
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_addr                                       "0xB8000550"
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg                                            0xB8000550
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_inst_addr                                      "0x0083"
#define  set_CRT_SYS_PLL_DDR_DCC_DQ_0_reg(data)                                  (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_0_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQ_0_reg                                        (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_0_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_dbg_sel_0_shift             (23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_div_0_shift                     (20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_stop_0_shift                (19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_int_gain_0_shift                (14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_0_shift                    (7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_sel_0_shift                (6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_presetb_0_shift            (3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_preseta_0_shift            (0)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_dbg_sel_0_mask              (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_div_0_mask                      (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_stop_0_mask                 (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_int_gain_0_mask                 (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_0_mask                     (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_sel_0_mask                 (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_presetb_0_mask             (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_preseta_0_mask             (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_dbg_sel_0(data)             (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_div_0(data)                     (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_stop_0(data)                (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_int_gain_0(data)                (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_0(data)                    (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_sel_0(data)                (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_presetb_0(data)            (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_preseta_0(data)            (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_dsp_dbg_sel_0(data)         ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_div_0(data)                 ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_dsp_stop_0(data)            ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_int_gain_0(data)            ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_0(data)                ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_sel_0(data)            ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_presetb_0(data)        ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_preseta_0(data)        (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQ_1                                                0x18000554
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_addr                                       "0xB8000554"
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg                                            0xB8000554
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_inst_addr                                      "0x0084"
#define  set_CRT_SYS_PLL_DDR_DCC_DQ_1_reg(data)                                  (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_1_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQ_1_reg                                        (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_1_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_dbg_sel_1_shift             (23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_div_1_shift                     (20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_stop_1_shift                (19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_int_gain_1_shift                (14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_1_shift                    (7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_sel_1_shift                (6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_presetb_1_shift            (3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_preseta_1_shift            (0)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_dbg_sel_1_mask              (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_div_1_mask                      (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_stop_1_mask                 (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_int_gain_1_mask                 (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_1_mask                     (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_sel_1_mask                 (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_presetb_1_mask             (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_preseta_1_mask             (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_dbg_sel_1(data)             (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_div_1(data)                     (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_stop_1(data)                (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_int_gain_1(data)                (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_1(data)                    (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_sel_1(data)                (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_presetb_1(data)            (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_preseta_1(data)            (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_dsp_dbg_sel_1(data)         ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_div_1(data)                 ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_dsp_stop_1(data)            ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_int_gain_1(data)            ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_1(data)                ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_sel_1(data)            ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_presetb_1(data)        ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_preseta_1(data)        (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQ_2                                                0x18000558
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_addr                                       "0xB8000558"
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg                                            0xB8000558
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_inst_addr                                      "0x0085"
#define  set_CRT_SYS_PLL_DDR_DCC_DQ_2_reg(data)                                  (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_2_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQ_2_reg                                        (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_2_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_dbg_sel_2_shift             (23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_div_2_shift                     (20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_stop_2_shift                (19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_int_gain_2_shift                (14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_2_shift                    (7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_sel_2_shift                (6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_presetb_2_shift            (3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_preseta_2_shift            (0)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_dbg_sel_2_mask              (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_div_2_mask                      (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_stop_2_mask                 (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_int_gain_2_mask                 (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_2_mask                     (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_sel_2_mask                 (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_presetb_2_mask             (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_preseta_2_mask             (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_dbg_sel_2(data)             (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_div_2(data)                     (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_stop_2(data)                (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_int_gain_2(data)                (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_2(data)                    (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_sel_2(data)                (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_presetb_2(data)            (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_preseta_2(data)            (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_dsp_dbg_sel_2(data)         ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_div_2(data)                 ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_dsp_stop_2(data)            ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_int_gain_2(data)            ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_2(data)                ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_sel_2(data)            ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_presetb_2(data)        ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_preseta_2(data)        (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_DQ_3                                                0x1800055C
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_addr                                       "0xB800055C"
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg                                            0xB800055C
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_inst_addr                                      "0x0086"
#define  set_CRT_SYS_PLL_DDR_DCC_DQ_3_reg(data)                                  (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_3_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_DQ_3_reg                                        (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_DQ_3_reg))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_dbg_sel_3_shift             (23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_div_3_shift                     (20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_stop_3_shift                (19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_int_gain_3_shift                (14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_3_shift                    (7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_sel_3_shift                (6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_presetb_3_shift            (3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_preseta_3_shift            (0)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_dbg_sel_3_mask              (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_div_3_mask                      (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_stop_3_mask                 (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_int_gain_3_mask                 (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_3_mask                     (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_sel_3_mask                 (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_presetb_3_mask             (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_preseta_3_mask             (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_dbg_sel_3(data)             (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_div_3(data)                     (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_stop_3(data)                (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_int_gain_3(data)                (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_3(data)                    (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_sel_3(data)                (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_presetb_3(data)            (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_preseta_3(data)            (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_dsp_dbg_sel_3(data)         ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_div_3(data)                 ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_dsp_stop_3(data)            ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_int_gain_3(data)            ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_3(data)                ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_sel_3(data)            ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_presetb_3(data)        ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_preseta_3(data)        (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_CK0                                                 0x18000560
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_addr                                        "0xB8000560"
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg                                             0xB8000560
#define  CRT_SYS_PLL_DDR_DCC_CK0_inst_addr                                       "0x0087"
#define  set_CRT_SYS_PLL_DDR_DCC_CK0_reg(data)                                   (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_CK0_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_CK0_reg                                         (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_CK0_reg))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_dbg_sel_shift               (23)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_div_shift                       (20)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_stop_shift                  (19)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_int_gain_shift                  (14)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_shift                      (7)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_sel_shift                  (6)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_presetb_shift              (3)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_preseta_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_dbg_sel_mask                (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_div_mask                        (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_stop_mask                   (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_int_gain_mask                   (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_mask                       (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_sel_mask                   (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_presetb_mask               (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_preseta_mask               (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_dbg_sel(data)               (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_div(data)                       (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_stop(data)                  (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_int_gain(data)                  (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty(data)                      (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_sel(data)                  (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_presetb(data)              (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_preseta(data)              (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_dsp_dbg_sel(data)           ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_div(data)                   ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_dsp_stop(data)              ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_int_gain(data)              ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty(data)                  ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty_sel(data)              ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty_presetb(data)          ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty_preseta(data)          (0x00000007&(data))

#define  CRT_SYS_PLL_DDR_DCC_CK1                                                 0x18000564
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_addr                                        "0xB8000564"
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg                                             0xB8000564
#define  CRT_SYS_PLL_DDR_DCC_CK1_inst_addr                                       "0x0088"
#define  set_CRT_SYS_PLL_DDR_DCC_CK1_reg(data)                                   (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_CK1_reg)=data)
#define  get_CRT_SYS_PLL_DDR_DCC_CK1_reg                                         (*((volatile unsigned int*)CRT_SYS_PLL_DDR_DCC_CK1_reg))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_dbg_sel_shift               (23)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_div_shift                       (20)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_stop_shift                  (19)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_int_gain_shift                  (14)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_shift                      (7)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_sel_shift                  (6)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_presetb_shift              (3)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_preseta_shift              (0)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_dbg_sel_mask                (0x00800000)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_div_mask                        (0x00700000)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_stop_mask                   (0x00080000)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_int_gain_mask                   (0x0007C000)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_mask                       (0x00003F80)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_sel_mask                   (0x00000040)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_presetb_mask               (0x00000038)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_preseta_mask               (0x00000007)
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_dbg_sel(data)               (0x00800000&((data)<<23))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_div(data)                       (0x00700000&((data)<<20))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_stop(data)                  (0x00080000&((data)<<19))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_int_gain(data)                  (0x0007C000&((data)<<14))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty(data)                      (0x00003F80&((data)<<7))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_sel(data)                  (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_presetb(data)              (0x00000038&((data)<<3))
#define  CRT_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_preseta(data)              (0x00000007&(data))
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_dsp_dbg_sel(data)           ((0x00800000&(data))>>23)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_div(data)                   ((0x00700000&(data))>>20)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_dsp_stop(data)              ((0x00080000&(data))>>19)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_int_gain(data)              ((0x0007C000&(data))>>14)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty(data)                  ((0x00003F80&(data))>>7)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty_sel(data)              ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty_presetb(data)          ((0x00000038&(data))>>3)
#define  CRT_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty_preseta(data)          (0x00000007&(data))

#define  CRT_SYS_PLL_DUMMY_IN                                                    0x18000568
#define  CRT_SYS_PLL_DUMMY_IN_reg_addr                                           "0xB8000568"
#define  CRT_SYS_PLL_DUMMY_IN_reg                                                0xB8000568
#define  CRT_SYS_PLL_DUMMY_IN_inst_addr                                          "0x0089"
#define  set_CRT_SYS_PLL_DUMMY_IN_reg(data)                                      (*((volatile unsigned int*)CRT_SYS_PLL_DUMMY_IN_reg)=data)
#define  get_CRT_SYS_PLL_DUMMY_IN_reg                                            (*((volatile unsigned int*)CRT_SYS_PLL_DUMMY_IN_reg))
#define  CRT_SYS_PLL_DUMMY_IN_dpi_dummy_in_dll_shift                             (0)
#define  CRT_SYS_PLL_DUMMY_IN_dpi_dummy_in_dll_mask                              (0xFFFFFFFF)
#define  CRT_SYS_PLL_DUMMY_IN_dpi_dummy_in_dll(data)                             (0xFFFFFFFF&(data))
#define  CRT_SYS_PLL_DUMMY_IN_get_dpi_dummy_in_dll(data)                         (0xFFFFFFFF&(data))

#define  CRT_SYS_PLL_DUMMY_OUT                                                   0x18000570
#define  CRT_SYS_PLL_DUMMY_OUT_reg_addr                                          "0xB8000570"
#define  CRT_SYS_PLL_DUMMY_OUT_reg                                               0xB8000570
#define  CRT_SYS_PLL_DUMMY_OUT_inst_addr                                         "0x008A"
#define  set_CRT_SYS_PLL_DUMMY_OUT_reg(data)                                     (*((volatile unsigned int*)CRT_SYS_PLL_DUMMY_OUT_reg)=data)
#define  get_CRT_SYS_PLL_DUMMY_OUT_reg                                           (*((volatile unsigned int*)CRT_SYS_PLL_DUMMY_OUT_reg))
#define  CRT_SYS_PLL_DUMMY_OUT_dpi_dummy_out_dll_shift                           (0)
#define  CRT_SYS_PLL_DUMMY_OUT_dpi_dummy_out_dll_mask                            (0xFFFFFFFF)
#define  CRT_SYS_PLL_DUMMY_OUT_dpi_dummy_out_dll(data)                           (0xFFFFFFFF&(data))
#define  CRT_SYS_PLL_DUMMY_OUT_get_dpi_dummy_out_dll(data)                       (0xFFFFFFFF&(data))

#define  CRT_DC2_SYS_PLL_DDR0                                                    0x18000580
#define  CRT_DC2_SYS_PLL_DDR0_reg_addr                                           "0xB8000580"
#define  CRT_DC2_SYS_PLL_DDR0_reg                                                0xB8000580
#define  CRT_DC2_SYS_PLL_DDR0_inst_addr                                          "0x008B"
#define  set_CRT_DC2_SYS_PLL_DDR0_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR0_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR0_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR0_reg))
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_cco_band_shift                             (30)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel2_shift                         (25)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel1_shift                         (20)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel0_shift                         (15)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_en_post_pi_shift                           (7)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_mck_clk_en_shift                           (0)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_cco_band_mask                              (0xC0000000)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel2_mask                          (0x3E000000)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel1_mask                          (0x01F00000)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel0_mask                          (0x000F8000)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_en_post_pi_mask                            (0x00007F80)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_mck_clk_en_mask                            (0x0000007F)
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_cco_band(data)                             (0xC0000000&((data)<<30))
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel2(data)                         (0x3E000000&((data)<<25))
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel1(data)                         (0x01F00000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_post_pi_sel0(data)                         (0x000F8000&((data)<<15))
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_en_post_pi(data)                           (0x00007F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR0_reg_dpi_mck_clk_en(data)                           (0x0000007F&(data))
#define  CRT_DC2_SYS_PLL_DDR0_get_reg_dpi_cco_band(data)                         ((0xC0000000&(data))>>30)
#define  CRT_DC2_SYS_PLL_DDR0_get_reg_dpi_post_pi_sel2(data)                     ((0x3E000000&(data))>>25)
#define  CRT_DC2_SYS_PLL_DDR0_get_reg_dpi_post_pi_sel1(data)                     ((0x01F00000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR0_get_reg_dpi_post_pi_sel0(data)                     ((0x000F8000&(data))>>15)
#define  CRT_DC2_SYS_PLL_DDR0_get_reg_dpi_en_post_pi(data)                       ((0x00007F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR0_get_reg_dpi_mck_clk_en(data)                       (0x0000007F&(data))

#define  CRT_DC2_SYS_PLL_DDR1                                                    0x18000584
#define  CRT_DC2_SYS_PLL_DDR1_reg_addr                                           "0xB8000584"
#define  CRT_DC2_SYS_PLL_DDR1_reg                                                0xB8000584
#define  CRT_DC2_SYS_PLL_DDR1_inst_addr                                          "0x008C"
#define  set_CRT_DC2_SYS_PLL_DDR1_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR1_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR1_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR1_reg))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_lpf_sr_shift                               (29)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_lpf_cp_shift                               (28)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_loop_pi_isel_shift                         (24)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_icp_shift                                  (20)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel6_shift                         (15)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel5_shift                         (10)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel4_shift                         (5)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel3_shift                         (0)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_lpf_sr_mask                                (0xE0000000)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_lpf_cp_mask                                (0x10000000)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_loop_pi_isel_mask                          (0x0F000000)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_icp_mask                                   (0x00F00000)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel6_mask                          (0x000F8000)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel5_mask                          (0x00007C00)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel4_mask                          (0x000003E0)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel3_mask                          (0x0000001F)
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_lpf_sr(data)                               (0xE0000000&((data)<<29))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_lpf_cp(data)                               (0x10000000&((data)<<28))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_loop_pi_isel(data)                         (0x0F000000&((data)<<24))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_icp(data)                                  (0x00F00000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel6(data)                         (0x000F8000&((data)<<15))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel5(data)                         (0x00007C00&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel4(data)                         (0x000003E0&((data)<<5))
#define  CRT_DC2_SYS_PLL_DDR1_reg_dpi_post_pi_sel3(data)                         (0x0000001F&(data))
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_lpf_sr(data)                           ((0xE0000000&(data))>>29)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_lpf_cp(data)                           ((0x10000000&(data))>>28)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_loop_pi_isel(data)                     ((0x0F000000&(data))>>24)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_icp(data)                              ((0x00F00000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel6(data)                     ((0x000F8000&(data))>>15)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel5(data)                     ((0x00007C00&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel4(data)                     ((0x000003E0&(data))>>5)
#define  CRT_DC2_SYS_PLL_DDR1_get_reg_dpi_post_pi_sel3(data)                     (0x0000001F&(data))

#define  CRT_DC2_SYS_PLL_DDR2                                                    0x18000588
#define  CRT_DC2_SYS_PLL_DDR2_reg_addr                                           "0xB8000588"
#define  CRT_DC2_SYS_PLL_DDR2_reg                                                0xB8000588
#define  CRT_DC2_SYS_PLL_DDR2_inst_addr                                          "0x008D"
#define  set_CRT_DC2_SYS_PLL_DDR2_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR2_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR2_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR2_reg))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_n_code_shift                               (24)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_en_ssc_shift                               (23)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_bypass_pi_shift                            (22)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_f_code_shift                               (11)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_rs_shift                           (10)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_rl_shift                           (8)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_bias_shift                         (6)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_sel_cpmode_shift                       (5)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_ldo_vsel_shift                         (3)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_dbug_en_shift                          (2)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pdiv_shift                                 (0)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_n_code_mask                                (0xFF000000)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_en_ssc_mask                                (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_bypass_pi_mask                             (0x00400000)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_f_code_mask                                (0x003FF800)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_rs_mask                            (0x00000400)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_rl_mask                            (0x00000300)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_bias_mask                          (0x000000C0)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_sel_cpmode_mask                        (0x00000020)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_ldo_vsel_mask                          (0x00000018)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_dbug_en_mask                           (0x00000004)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pdiv_mask                                  (0x00000003)
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_n_code(data)                               (0xFF000000&((data)<<24))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_en_ssc(data)                               (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_bypass_pi(data)                            (0x00400000&((data)<<22))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_f_code(data)                               (0x003FF800&((data)<<11))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_rs(data)                           (0x00000400&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_rl(data)                           (0x00000300&((data)<<8))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_post_pi_bias(data)                         (0x000000C0&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_sel_cpmode(data)                       (0x00000020&((data)<<5))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_ldo_vsel(data)                         (0x00000018&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pll_dbug_en(data)                          (0x00000004&((data)<<2))
#define  CRT_DC2_SYS_PLL_DDR2_reg_dpi_pdiv(data)                                 (0x00000003&(data))
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_n_code(data)                           ((0xFF000000&(data))>>24)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_en_ssc(data)                           ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_bypass_pi(data)                        ((0x00400000&(data))>>22)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_f_code(data)                           ((0x003FF800&(data))>>11)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_post_pi_rs(data)                       ((0x00000400&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_post_pi_rl(data)                       ((0x00000300&(data))>>8)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_post_pi_bias(data)                     ((0x000000C0&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_pll_sel_cpmode(data)                   ((0x00000020&(data))>>5)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_pll_ldo_vsel(data)                     ((0x00000018&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_pll_dbug_en(data)                      ((0x00000004&(data))>>2)
#define  CRT_DC2_SYS_PLL_DDR2_get_reg_dpi_pdiv(data)                             (0x00000003&(data))

#define  CRT_DC2_SYS_PLL_DDR3                                                    0x1800058C
#define  CRT_DC2_SYS_PLL_DDR3_reg_addr                                           "0xB800058C"
#define  CRT_DC2_SYS_PLL_DDR3_reg                                                0xB800058C
#define  CRT_DC2_SYS_PLL_DDR3_inst_addr                                          "0x008E"
#define  set_CRT_DC2_SYS_PLL_DDR3_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR3_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR3_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR3_reg))
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_cco_kvco_shift                             (31)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_oc_en_shift                                (30)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_oc_step_set_shift                          (20)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_f_code_t_shift                             (9)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_n_code_t_shift                             (1)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_order_shift                                (0)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_cco_kvco_mask                              (0x80000000)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_oc_en_mask                                 (0x40000000)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_oc_step_set_mask                           (0x3FF00000)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_f_code_t_mask                              (0x000FFE00)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_n_code_t_mask                              (0x000001FE)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_order_mask                                 (0x00000001)
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_cco_kvco(data)                             (0x80000000&((data)<<31))
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_oc_en(data)                                (0x40000000&((data)<<30))
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_oc_step_set(data)                          (0x3FF00000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_f_code_t(data)                             (0x000FFE00&((data)<<9))
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_n_code_t(data)                             (0x000001FE&((data)<<1))
#define  CRT_DC2_SYS_PLL_DDR3_reg_dpi_order(data)                                (0x00000001&(data))
#define  CRT_DC2_SYS_PLL_DDR3_get_reg_dpi_cco_kvco(data)                         ((0x80000000&(data))>>31)
#define  CRT_DC2_SYS_PLL_DDR3_get_reg_dpi_oc_en(data)                            ((0x40000000&(data))>>30)
#define  CRT_DC2_SYS_PLL_DDR3_get_reg_dpi_oc_step_set(data)                      ((0x3FF00000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR3_get_reg_dpi_f_code_t(data)                         ((0x000FFE00&(data))>>9)
#define  CRT_DC2_SYS_PLL_DDR3_get_reg_dpi_n_code_t(data)                         ((0x000001FE&(data))>>1)
#define  CRT_DC2_SYS_PLL_DDR3_get_reg_dpi_order(data)                            (0x00000001&(data))

#define  CRT_DC2_SYS_PLL_DDR4                                                    0x18000590
#define  CRT_DC2_SYS_PLL_DDR4_reg_addr                                           "0xB8000590"
#define  CRT_DC2_SYS_PLL_DDR4_reg                                                0xB8000590
#define  CRT_DC2_SYS_PLL_DDR4_inst_addr                                          "0x008F"
#define  set_CRT_DC2_SYS_PLL_DDR4_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR4_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR4_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR4_reg))
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_dot_gran_shift                             (29)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_gran_set_shift                             (10)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_oc_done_delay_shift                        (4)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_hs_oc_stop_diff_shift                      (2)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_sel_oc_mode_shift                          (0)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_dot_gran_mask                              (0xE0000000)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_gran_set_mask                              (0x1FFFFC00)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_oc_done_delay_mask                         (0x000003F0)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_hs_oc_stop_diff_mask                       (0x0000000C)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_sel_oc_mode_mask                           (0x00000003)
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_dot_gran(data)                             (0xE0000000&((data)<<29))
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_gran_set(data)                             (0x1FFFFC00&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_oc_done_delay(data)                        (0x000003F0&((data)<<4))
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_hs_oc_stop_diff(data)                      (0x0000000C&((data)<<2))
#define  CRT_DC2_SYS_PLL_DDR4_reg_dpi_sel_oc_mode(data)                          (0x00000003&(data))
#define  CRT_DC2_SYS_PLL_DDR4_get_reg_dpi_dot_gran(data)                         ((0xE0000000&(data))>>29)
#define  CRT_DC2_SYS_PLL_DDR4_get_reg_dpi_gran_set(data)                         ((0x1FFFFC00&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR4_get_reg_dpi_oc_done_delay(data)                    ((0x000003F0&(data))>>4)
#define  CRT_DC2_SYS_PLL_DDR4_get_reg_dpi_hs_oc_stop_diff(data)                  ((0x0000000C&(data))>>2)
#define  CRT_DC2_SYS_PLL_DDR4_get_reg_dpi_sel_oc_mode(data)                      (0x00000003&(data))

#define  CRT_DC2_SYS_PLL_DDR5                                                    0x18000594
#define  CRT_DC2_SYS_PLL_DDR5_reg_addr                                           "0xB8000594"
#define  CRT_DC2_SYS_PLL_DDR5_reg                                                0xB8000594
#define  CRT_DC2_SYS_PLL_DDR5_inst_addr                                          "0x0090"
#define  set_CRT_DC2_SYS_PLL_DDR5_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR5_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR5_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR5_reg))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_oesync_op_sel_shift                        (18)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_clk_oe_shift                               (11)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time2_rst_width_shift                      (9)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time_rdy_ckout_shift                       (7)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time0_ck_shift                             (4)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_f390k_shift                                (2)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_wd_enable_shift                            (1)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_gran_auto_rst_shift                        (0)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_oesync_op_sel_mask                         (0x01FC0000)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_clk_oe_mask                                (0x0003F800)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time2_rst_width_mask                       (0x00000600)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time_rdy_ckout_mask                        (0x00000180)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time0_ck_mask                              (0x00000070)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_f390k_mask                                 (0x0000000C)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_wd_enable_mask                             (0x00000002)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_gran_auto_rst_mask                         (0x00000001)
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_oesync_op_sel(data)                        (0x01FC0000&((data)<<18))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_clk_oe(data)                               (0x0003F800&((data)<<11))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time2_rst_width(data)                      (0x00000600&((data)<<9))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time_rdy_ckout(data)                       (0x00000180&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_time0_ck(data)                             (0x00000070&((data)<<4))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_f390k(data)                                (0x0000000C&((data)<<2))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_wd_enable(data)                            (0x00000002&((data)<<1))
#define  CRT_DC2_SYS_PLL_DDR5_reg_dpi_gran_auto_rst(data)                        (0x00000001&(data))
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_oesync_op_sel(data)                    ((0x01FC0000&(data))>>18)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_clk_oe(data)                           ((0x0003F800&(data))>>11)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_time2_rst_width(data)                  ((0x00000600&(data))>>9)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_time_rdy_ckout(data)                   ((0x00000180&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_time0_ck(data)                         ((0x00000070&(data))>>4)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_f390k(data)                            ((0x0000000C&(data))>>2)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_wd_enable(data)                        ((0x00000002&(data))>>1)
#define  CRT_DC2_SYS_PLL_DDR5_get_reg_dpi_gran_auto_rst(data)                    (0x00000001&(data))

#define  CRT_DC2_SYS_PLL_DDR6                                                    0x18000598
#define  CRT_DC2_SYS_PLL_DDR6_reg_addr                                           "0xB8000598"
#define  CRT_DC2_SYS_PLL_DDR6_reg                                                0xB8000598
#define  CRT_DC2_SYS_PLL_DDR6_inst_addr                                          "0x0091"
#define  set_CRT_DC2_SYS_PLL_DDR6_reg(data)                                      (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR6_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR6_reg                                            (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR6_reg))
#define  CRT_DC2_SYS_PLL_DDR6_pll_stable_shift                                   (31)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_pll_en_shift                               (21)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_ng_clk_sel_shift                           (19)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_v11_ldo_vsel_shift                         (17)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_post_pi_sel_shift                          (12)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_adj_div2_en_shift                          (11)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_ckref_sel_shift                            (10)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_dat_rate_sel_shift                         (9)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_adr_rate_sel_shift                         (8)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_pll_dum_shift                              (0)
#define  CRT_DC2_SYS_PLL_DDR6_pll_stable_mask                                    (0x80000000)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_pll_en_mask                                (0x00200000)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_ng_clk_sel_mask                            (0x00180000)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_v11_ldo_vsel_mask                          (0x00060000)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_post_pi_sel_mask                           (0x0001F000)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_adj_div2_en_mask                           (0x00000800)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_ckref_sel_mask                             (0x00000400)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_dat_rate_sel_mask                          (0x00000200)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_adr_rate_sel_mask                          (0x00000100)
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_pll_dum_mask                               (0x000000FF)
#define  CRT_DC2_SYS_PLL_DDR6_pll_stable(data)                                   (0x80000000&((data)<<31))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_pll_en(data)                               (0x00200000&((data)<<21))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_ng_clk_sel(data)                           (0x00180000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_v11_ldo_vsel(data)                         (0x00060000&((data)<<17))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_post_pi_sel(data)                          (0x0001F000&((data)<<12))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_adj_div2_en(data)                          (0x00000800&((data)<<11))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_ckref_sel(data)                            (0x00000400&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_dat_rate_sel(data)                         (0x00000200&((data)<<9))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_adr_rate_sel(data)                         (0x00000100&((data)<<8))
#define  CRT_DC2_SYS_PLL_DDR6_reg_dpi_pll_dum(data)                              (0x000000FF&(data))
#define  CRT_DC2_SYS_PLL_DDR6_get_pll_stable(data)                               ((0x80000000&(data))>>31)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_pll_en(data)                           ((0x00200000&(data))>>21)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_ng_clk_sel(data)                       ((0x00180000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_v11_ldo_vsel(data)                     ((0x00060000&(data))>>17)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_post_pi_sel(data)                      ((0x0001F000&(data))>>12)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_adj_div2_en(data)                      ((0x00000800&(data))>>11)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_ckref_sel(data)                        ((0x00000400&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_dat_rate_sel(data)                     ((0x00000200&(data))>>9)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_adr_rate_sel(data)                     ((0x00000100&(data))>>8)
#define  CRT_DC2_SYS_PLL_DDR6_get_reg_dpi_pll_dum(data)                          (0x000000FF&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD                                             0x1800059C
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_addr                                    "0xB800059C"
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg                                         0xB800059C
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_inst_addr                                   "0x0092"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg(data)                               (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg                                     (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_dbg_sel_shift           (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_div_shift                   (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_stop_shift              (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_int_gain_shift              (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_shift                  (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_sel_shift              (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_presetb_shift          (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_preseta_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_dbg_sel_mask            (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_div_mask                    (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_stop_mask               (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_int_gain_mask               (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_mask                   (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_sel_mask               (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_presetb_mask           (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_preseta_mask           (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_dbg_sel(data)           (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_div(data)                   (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_dsp_stop(data)              (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_int_gain(data)              (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty(data)                  (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_sel(data)              (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_presetb(data)          (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_reg_dpi_dcc_cmd_duty_preseta(data)          (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_dsp_dbg_sel(data)       ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_div(data)               ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_dsp_stop(data)          ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_int_gain(data)          ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty(data)              ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty_sel(data)          ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty_presetb(data)      ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CMD_get_reg_dpi_dcc_cmd_duty_preseta(data)      (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0                                           0x180005A0
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_addr                                  "0xB80005A0"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg                                       0xB80005A0
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_inst_addr                                 "0x0093"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_en_pdout_0_shift              (29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_ph90_sft_0_shift              (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_int_gain_0_shift              (18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_sel_0_shift               (17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_0_shift                   (8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_init_value_0_shift            (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_en_pdout_0_mask               (0x20000000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_ph90_sft_0_mask               (0x1F800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_int_gain_0_mask               (0x007C0000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_sel_0_mask                (0x00020000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_0_mask                    (0x0001FF00)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_init_value_0_mask             (0x000000FF)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_en_pdout_0(data)              (0x20000000&((data)<<29))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_ph90_sft_0(data)              (0x1F800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_int_gain_0(data)              (0x007C0000&((data)<<18))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_sel_0(data)               (0x00020000&((data)<<17))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_dly_0(data)                   (0x0001FF00&((data)<<8))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_reg_dpi_dll_init_value_0(data)            (0x000000FF&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_en_pdout_0(data)          ((0x20000000&(data))>>29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_ph90_sft_0(data)          ((0x1F800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_int_gain_0(data)          ((0x007C0000&(data))>>18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_dly_sel_0(data)           ((0x00020000&(data))>>17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_dly_0(data)               ((0x0001FF00&(data))>>8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_0_get_reg_dpi_dll_init_value_0(data)        (0x000000FF&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1                                           0x180005A4
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_addr                                  "0xB80005A4"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg                                       0xB80005A4
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_inst_addr                                 "0x0094"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_en_pdout_1_shift              (29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_ph90_sft_1_shift              (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_int_gain_1_shift              (18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_sel_1_shift               (17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_1_shift                   (8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_init_value_1_shift            (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_en_pdout_1_mask               (0x20000000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_ph90_sft_1_mask               (0x1F800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_int_gain_1_mask               (0x007C0000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_sel_1_mask                (0x00020000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_1_mask                    (0x0001FF00)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_init_value_1_mask             (0x000000FF)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_en_pdout_1(data)              (0x20000000&((data)<<29))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_ph90_sft_1(data)              (0x1F800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_int_gain_1(data)              (0x007C0000&((data)<<18))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_sel_1(data)               (0x00020000&((data)<<17))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_dly_1(data)                   (0x0001FF00&((data)<<8))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_reg_dpi_dll_init_value_1(data)            (0x000000FF&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_en_pdout_1(data)          ((0x20000000&(data))>>29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_ph90_sft_1(data)          ((0x1F800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_int_gain_1(data)          ((0x007C0000&(data))>>18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_dly_sel_1(data)           ((0x00020000&(data))>>17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_dly_1(data)               ((0x0001FF00&(data))>>8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_1_get_reg_dpi_dll_init_value_1(data)        (0x000000FF&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2                                           0x180005A8
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_addr                                  "0xB80005A8"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg                                       0xB80005A8
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_inst_addr                                 "0x0095"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_en_pdout_2_shift              (29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_ph90_sft_2_shift              (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_int_gain_2_shift              (18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_sel_2_shift               (17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_2_shift                   (8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_init_value_2_shift            (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_en_pdout_2_mask               (0x20000000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_ph90_sft_2_mask               (0x1F800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_int_gain_2_mask               (0x007C0000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_sel_2_mask                (0x00020000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_2_mask                    (0x0001FF00)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_init_value_2_mask             (0x000000FF)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_en_pdout_2(data)              (0x20000000&((data)<<29))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_ph90_sft_2(data)              (0x1F800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_int_gain_2(data)              (0x007C0000&((data)<<18))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_sel_2(data)               (0x00020000&((data)<<17))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_dly_2(data)                   (0x0001FF00&((data)<<8))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_reg_dpi_dll_init_value_2(data)            (0x000000FF&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_en_pdout_2(data)          ((0x20000000&(data))>>29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_ph90_sft_2(data)          ((0x1F800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_int_gain_2(data)          ((0x007C0000&(data))>>18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_dly_sel_2(data)           ((0x00020000&(data))>>17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_dly_2(data)               ((0x0001FF00&(data))>>8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_2_get_reg_dpi_dll_init_value_2(data)        (0x000000FF&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3                                           0x180005AC
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_addr                                  "0xB80005AC"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg                                       0xB80005AC
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_inst_addr                                 "0x0096"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_en_pdout_3_shift              (29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_ph90_sft_3_shift              (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_int_gain_3_shift              (18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_sel_3_shift               (17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_3_shift                   (8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_init_value_3_shift            (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_en_pdout_3_mask               (0x20000000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_ph90_sft_3_mask               (0x1F800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_int_gain_3_mask               (0x007C0000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_sel_3_mask                (0x00020000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_3_mask                    (0x0001FF00)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_init_value_3_mask             (0x000000FF)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_en_pdout_3(data)              (0x20000000&((data)<<29))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_ph90_sft_3(data)              (0x1F800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_int_gain_3(data)              (0x007C0000&((data)<<18))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_sel_3(data)               (0x00020000&((data)<<17))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_dly_3(data)                   (0x0001FF00&((data)<<8))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_reg_dpi_dll_init_value_3(data)            (0x000000FF&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_en_pdout_3(data)          ((0x20000000&(data))>>29)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_ph90_sft_3(data)          ((0x1F800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_int_gain_3(data)          ((0x007C0000&(data))>>18)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_dly_sel_3(data)           ((0x00020000&(data))>>17)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_dly_3(data)               ((0x0001FF00&(data))>>8)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD0_3_get_reg_dpi_dll_init_value_3(data)        (0x000000FF&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0                                           0x180005B0
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_addr                                  "0xB80005B0"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg                                       0xB80005B0
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_inst_addr                                 "0x0097"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_alert_rx_rst_n_0_shift                    (10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_y_onehot_ini_0_shift          (5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_x_onehot_ini_0_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_alert_rx_rst_n_0_mask                     (0x00000400)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_y_onehot_ini_0_mask           (0x000003E0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_x_onehot_ini_0_mask           (0x0000001F)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_alert_rx_rst_n_0(data)                    (0x00000400&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_y_onehot_ini_0(data)          (0x000003E0&((data)<<5))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_reg_dpi_dll_x_onehot_ini_0(data)          (0x0000001F&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_get_alert_rx_rst_n_0(data)                ((0x00000400&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_get_reg_dpi_dll_y_onehot_ini_0(data)      ((0x000003E0&(data))>>5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_0_get_reg_dpi_dll_x_onehot_ini_0(data)      (0x0000001F&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1                                           0x180005B4
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_addr                                  "0xB80005B4"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg                                       0xB80005B4
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_inst_addr                                 "0x0098"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_alert_rx_rst_n_1_shift                    (10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_y_onehot_ini_1_shift          (5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_x_onehot_ini_1_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_alert_rx_rst_n_1_mask                     (0x00000400)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_y_onehot_ini_1_mask           (0x000003E0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_x_onehot_ini_1_mask           (0x0000001F)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_alert_rx_rst_n_1(data)                    (0x00000400&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_y_onehot_ini_1(data)          (0x000003E0&((data)<<5))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_reg_dpi_dll_x_onehot_ini_1(data)          (0x0000001F&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_get_alert_rx_rst_n_1(data)                ((0x00000400&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_get_reg_dpi_dll_y_onehot_ini_1(data)      ((0x000003E0&(data))>>5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_1_get_reg_dpi_dll_x_onehot_ini_1(data)      (0x0000001F&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2                                           0x180005B8
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_addr                                  "0xB80005B8"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg                                       0xB80005B8
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_inst_addr                                 "0x0099"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_alert_rx_rst_n_2_shift                    (10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_y_onehot_ini_2_shift          (5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_x_onehot_ini_2_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_alert_rx_rst_n_2_mask                     (0x00000400)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_y_onehot_ini_2_mask           (0x000003E0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_x_onehot_ini_2_mask           (0x0000001F)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_alert_rx_rst_n_2(data)                    (0x00000400&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_y_onehot_ini_2(data)          (0x000003E0&((data)<<5))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_reg_dpi_dll_x_onehot_ini_2(data)          (0x0000001F&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_get_alert_rx_rst_n_2(data)                ((0x00000400&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_get_reg_dpi_dll_y_onehot_ini_2(data)      ((0x000003E0&(data))>>5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_2_get_reg_dpi_dll_x_onehot_ini_2(data)      (0x0000001F&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3                                           0x180005BC
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_addr                                  "0xB80005BC"
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg                                       0xB80005BC
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_inst_addr                                 "0x009A"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_alert_rx_rst_n_3_shift                    (10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_y_onehot_ini_3_shift          (5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_x_onehot_ini_3_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_alert_rx_rst_n_3_mask                     (0x00000400)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_y_onehot_ini_3_mask           (0x000003E0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_x_onehot_ini_3_mask           (0x0000001F)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_alert_rx_rst_n_3(data)                    (0x00000400&((data)<<10))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_y_onehot_ini_3(data)          (0x000003E0&((data)<<5))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_reg_dpi_dll_x_onehot_ini_3(data)          (0x0000001F&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_get_alert_rx_rst_n_3(data)                ((0x00000400&(data))>>10)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_get_reg_dpi_dll_y_onehot_ini_3(data)      ((0x000003E0&(data))>>5)
#define  CRT_DC2_SYS_PLL_DDR_DCC_AD1_3_get_reg_dpi_dll_x_onehot_ini_3(data)      (0x0000001F&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0                                           0x180005C0
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_addr                                  "0xB80005C0"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg                                       0xB80005C0
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_inst_addr                                 "0x009B"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_dbg_sel_0_shift       (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_div_0_shift               (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_stop_0_shift          (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_int_gain_0_shift          (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_0_shift              (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_sel_0_shift          (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_presetb_0_shift      (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_preseta_0_shift      (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_dbg_sel_0_mask        (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_div_0_mask                (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_stop_0_mask           (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_int_gain_0_mask           (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_0_mask               (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_sel_0_mask           (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_presetb_0_mask       (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_preseta_0_mask       (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_dbg_sel_0(data)       (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_div_0(data)               (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_dsp_stop_0(data)          (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_int_gain_0(data)          (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_0(data)              (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_sel_0(data)          (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_presetb_0(data)      (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_reg_dpi_dcc_dqs_duty_preseta_0(data)      (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_dsp_dbg_sel_0(data)   ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_div_0(data)           ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_dsp_stop_0(data)      ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_int_gain_0(data)      ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_0(data)          ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_sel_0(data)      ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_presetb_0(data)  ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_0_get_reg_dpi_dcc_dqs_duty_preseta_0(data)  (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1                                           0x180005C4
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_addr                                  "0xB80005C4"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg                                       0xB80005C4
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_inst_addr                                 "0x009C"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_dbg_sel_1_shift       (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_div_1_shift               (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_stop_1_shift          (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_int_gain_1_shift          (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_1_shift              (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_sel_1_shift          (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_presetb_1_shift      (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_preseta_1_shift      (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_dbg_sel_1_mask        (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_div_1_mask                (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_stop_1_mask           (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_int_gain_1_mask           (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_1_mask               (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_sel_1_mask           (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_presetb_1_mask       (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_preseta_1_mask       (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_dbg_sel_1(data)       (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_div_1(data)               (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_dsp_stop_1(data)          (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_int_gain_1(data)          (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_1(data)              (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_sel_1(data)          (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_presetb_1(data)      (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_reg_dpi_dcc_dqs_duty_preseta_1(data)      (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_dsp_dbg_sel_1(data)   ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_div_1(data)           ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_dsp_stop_1(data)      ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_int_gain_1(data)      ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_1(data)          ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_sel_1(data)      ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_presetb_1(data)  ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_1_get_reg_dpi_dcc_dqs_duty_preseta_1(data)  (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2                                           0x180005C8
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_addr                                  "0xB80005C8"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg                                       0xB80005C8
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_inst_addr                                 "0x009D"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_dbg_sel_2_shift       (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_div_2_shift               (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_stop_2_shift          (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_int_gain_2_shift          (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_2_shift              (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_sel_2_shift          (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_presetb_2_shift      (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_preseta_2_shift      (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_dbg_sel_2_mask        (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_div_2_mask                (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_stop_2_mask           (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_int_gain_2_mask           (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_2_mask               (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_sel_2_mask           (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_presetb_2_mask       (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_preseta_2_mask       (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_dbg_sel_2(data)       (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_div_2(data)               (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_dsp_stop_2(data)          (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_int_gain_2(data)          (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_2(data)              (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_sel_2(data)          (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_presetb_2(data)      (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_reg_dpi_dcc_dqs_duty_preseta_2(data)      (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_dsp_dbg_sel_2(data)   ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_div_2(data)           ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_dsp_stop_2(data)      ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_int_gain_2(data)      ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_2(data)          ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_sel_2(data)      ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_presetb_2(data)  ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_2_get_reg_dpi_dcc_dqs_duty_preseta_2(data)  (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3                                           0x180005CC
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_addr                                  "0xB80005CC"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg                                       0xB80005CC
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_inst_addr                                 "0x009E"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg(data)                             (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg                                   (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_dbg_sel_3_shift       (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_div_3_shift               (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_stop_3_shift          (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_int_gain_3_shift          (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_3_shift              (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_sel_3_shift          (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_presetb_3_shift      (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_preseta_3_shift      (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_dbg_sel_3_mask        (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_div_3_mask                (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_stop_3_mask           (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_int_gain_3_mask           (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_3_mask               (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_sel_3_mask           (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_presetb_3_mask       (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_preseta_3_mask       (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_dbg_sel_3(data)       (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_div_3(data)               (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_dsp_stop_3(data)          (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_int_gain_3(data)          (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_3(data)              (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_sel_3(data)          (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_presetb_3(data)      (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_reg_dpi_dcc_dqs_duty_preseta_3(data)      (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_dsp_dbg_sel_3(data)   ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_div_3(data)           ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_dsp_stop_3(data)      ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_int_gain_3(data)      ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_3(data)          ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_sel_3(data)      ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_presetb_3(data)  ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQS_3_get_reg_dpi_dcc_dqs_duty_preseta_3(data)  (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0                                            0x180005D0
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_addr                                   "0xB80005D0"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg                                        0xB80005D0
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_inst_addr                                  "0x009F"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg(data)                              (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg                                    (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_dbg_sel_0_shift         (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_div_0_shift                 (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_stop_0_shift            (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_int_gain_0_shift            (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_0_shift                (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_sel_0_shift            (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_presetb_0_shift        (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_preseta_0_shift        (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_dbg_sel_0_mask          (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_div_0_mask                  (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_stop_0_mask             (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_int_gain_0_mask             (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_0_mask                 (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_sel_0_mask             (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_presetb_0_mask         (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_preseta_0_mask         (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_dbg_sel_0(data)         (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_div_0(data)                 (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_dsp_stop_0(data)            (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_int_gain_0(data)            (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_0(data)                (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_sel_0(data)            (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_presetb_0(data)        (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_reg_dpi_dcc_dq_duty_preseta_0(data)        (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_dsp_dbg_sel_0(data)     ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_div_0(data)             ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_dsp_stop_0(data)        ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_int_gain_0(data)        ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_0(data)            ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_sel_0(data)        ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_presetb_0(data)    ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_0_get_reg_dpi_dcc_dq_duty_preseta_0(data)    (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1                                            0x180005D4
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_addr                                   "0xB80005D4"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg                                        0xB80005D4
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_inst_addr                                  "0x00A0"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg(data)                              (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg                                    (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_dbg_sel_1_shift         (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_div_1_shift                 (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_stop_1_shift            (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_int_gain_1_shift            (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_1_shift                (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_sel_1_shift            (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_presetb_1_shift        (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_preseta_1_shift        (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_dbg_sel_1_mask          (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_div_1_mask                  (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_stop_1_mask             (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_int_gain_1_mask             (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_1_mask                 (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_sel_1_mask             (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_presetb_1_mask         (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_preseta_1_mask         (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_dbg_sel_1(data)         (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_div_1(data)                 (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_dsp_stop_1(data)            (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_int_gain_1(data)            (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_1(data)                (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_sel_1(data)            (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_presetb_1(data)        (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_reg_dpi_dcc_dq_duty_preseta_1(data)        (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_dsp_dbg_sel_1(data)     ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_div_1(data)             ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_dsp_stop_1(data)        ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_int_gain_1(data)        ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_1(data)            ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_sel_1(data)        ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_presetb_1(data)    ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_1_get_reg_dpi_dcc_dq_duty_preseta_1(data)    (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2                                            0x180005D8
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_addr                                   "0xB80005D8"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg                                        0xB80005D8
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_inst_addr                                  "0x00A1"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg(data)                              (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg                                    (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_dbg_sel_2_shift         (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_div_2_shift                 (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_stop_2_shift            (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_int_gain_2_shift            (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_2_shift                (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_sel_2_shift            (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_presetb_2_shift        (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_preseta_2_shift        (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_dbg_sel_2_mask          (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_div_2_mask                  (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_stop_2_mask             (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_int_gain_2_mask             (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_2_mask                 (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_sel_2_mask             (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_presetb_2_mask         (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_preseta_2_mask         (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_dbg_sel_2(data)         (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_div_2(data)                 (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_dsp_stop_2(data)            (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_int_gain_2(data)            (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_2(data)                (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_sel_2(data)            (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_presetb_2(data)        (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_reg_dpi_dcc_dq_duty_preseta_2(data)        (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_dsp_dbg_sel_2(data)     ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_div_2(data)             ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_dsp_stop_2(data)        ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_int_gain_2(data)        ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_2(data)            ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_sel_2(data)        ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_presetb_2(data)    ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_2_get_reg_dpi_dcc_dq_duty_preseta_2(data)    (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3                                            0x180005DC
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_addr                                   "0xB80005DC"
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg                                        0xB80005DC
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_inst_addr                                  "0x00A2"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg(data)                              (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg                                    (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_dbg_sel_3_shift         (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_div_3_shift                 (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_stop_3_shift            (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_int_gain_3_shift            (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_3_shift                (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_sel_3_shift            (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_presetb_3_shift        (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_preseta_3_shift        (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_dbg_sel_3_mask          (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_div_3_mask                  (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_stop_3_mask             (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_int_gain_3_mask             (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_3_mask                 (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_sel_3_mask             (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_presetb_3_mask         (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_preseta_3_mask         (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_dbg_sel_3(data)         (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_div_3(data)                 (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_dsp_stop_3(data)            (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_int_gain_3(data)            (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_3(data)                (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_sel_3(data)            (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_presetb_3(data)        (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_reg_dpi_dcc_dq_duty_preseta_3(data)        (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_dsp_dbg_sel_3(data)     ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_div_3(data)             ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_dsp_stop_3(data)        ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_int_gain_3(data)        ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_3(data)            ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_sel_3(data)        ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_presetb_3(data)    ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_DQ_3_get_reg_dpi_dcc_dq_duty_preseta_3(data)    (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0                                             0x180005E0
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_addr                                    "0xB80005E0"
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg                                         0xB80005E0
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_inst_addr                                   "0x00A3"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg(data)                               (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg                                     (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_dbg_sel_shift           (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_div_shift                   (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_stop_shift              (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_int_gain_shift              (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_shift                  (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_sel_shift              (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_presetb_shift          (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_preseta_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_dbg_sel_mask            (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_div_mask                    (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_stop_mask               (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_int_gain_mask               (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_mask                   (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_sel_mask               (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_presetb_mask           (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_preseta_mask           (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_dbg_sel(data)           (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_div(data)                   (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_dsp_stop(data)              (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_int_gain(data)              (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty(data)                  (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_sel(data)              (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_presetb(data)          (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_reg_dpi_dcc_ck0_duty_preseta(data)          (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_dsp_dbg_sel(data)       ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_div(data)               ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_dsp_stop(data)          ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_int_gain(data)          ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty(data)              ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty_sel(data)          ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty_presetb(data)      ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK0_get_reg_dpi_dcc_ck0_duty_preseta(data)      (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1                                             0x180005E4
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_addr                                    "0xB80005E4"
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg                                         0xB80005E4
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_inst_addr                                   "0x00A4"
#define  set_CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg(data)                               (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg                                     (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_dbg_sel_shift           (23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_div_shift                   (20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_stop_shift              (19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_int_gain_shift              (14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_shift                  (7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_sel_shift              (6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_presetb_shift          (3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_preseta_shift          (0)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_dbg_sel_mask            (0x00800000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_div_mask                    (0x00700000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_stop_mask               (0x00080000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_int_gain_mask               (0x0007C000)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_mask                   (0x00003F80)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_sel_mask               (0x00000040)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_presetb_mask           (0x00000038)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_preseta_mask           (0x00000007)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_dbg_sel(data)           (0x00800000&((data)<<23))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_div(data)                   (0x00700000&((data)<<20))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_dsp_stop(data)              (0x00080000&((data)<<19))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_int_gain(data)              (0x0007C000&((data)<<14))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty(data)                  (0x00003F80&((data)<<7))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_sel(data)              (0x00000040&((data)<<6))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_presetb(data)          (0x00000038&((data)<<3))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_reg_dpi_dcc_ck1_duty_preseta(data)          (0x00000007&(data))
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_dsp_dbg_sel(data)       ((0x00800000&(data))>>23)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_div(data)               ((0x00700000&(data))>>20)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_dsp_stop(data)          ((0x00080000&(data))>>19)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_int_gain(data)          ((0x0007C000&(data))>>14)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty(data)              ((0x00003F80&(data))>>7)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty_sel(data)          ((0x00000040&(data))>>6)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty_presetb(data)      ((0x00000038&(data))>>3)
#define  CRT_DC2_SYS_PLL_DDR_DCC_CK1_get_reg_dpi_dcc_ck1_duty_preseta(data)      (0x00000007&(data))

#define  CRT_DC2_SYS_PLL_DUMMY_IN                                                0x180005E8
#define  CRT_DC2_SYS_PLL_DUMMY_IN_reg_addr                                       "0xB80005E8"
#define  CRT_DC2_SYS_PLL_DUMMY_IN_reg                                            0xB80005E8
#define  CRT_DC2_SYS_PLL_DUMMY_IN_inst_addr                                      "0x00A5"
#define  set_CRT_DC2_SYS_PLL_DUMMY_IN_reg(data)                                  (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DUMMY_IN_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DUMMY_IN_reg                                        (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DUMMY_IN_reg))
#define  CRT_DC2_SYS_PLL_DUMMY_IN_dpi_dummy_in_dll_shift                         (0)
#define  CRT_DC2_SYS_PLL_DUMMY_IN_dpi_dummy_in_dll_mask                          (0xFFFFFFFF)
#define  CRT_DC2_SYS_PLL_DUMMY_IN_dpi_dummy_in_dll(data)                         (0xFFFFFFFF&(data))
#define  CRT_DC2_SYS_PLL_DUMMY_IN_get_dpi_dummy_in_dll(data)                     (0xFFFFFFFF&(data))

#define  CRT_DC2_SYS_PLL_DUMMY_OUT                                               0x180005F0
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_reg_addr                                      "0xB80005F0"
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_reg                                           0xB80005F0
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_inst_addr                                     "0x00A6"
#define  set_CRT_DC2_SYS_PLL_DUMMY_OUT_reg(data)                                 (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DUMMY_OUT_reg)=data)
#define  get_CRT_DC2_SYS_PLL_DUMMY_OUT_reg                                       (*((volatile unsigned int*)CRT_DC2_SYS_PLL_DUMMY_OUT_reg))
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_dpi_dummy_out_dll_shift                       (0)
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_dpi_dummy_out_dll_mask                        (0xFFFFFFFF)
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_dpi_dummy_out_dll(data)                       (0xFFFFFFFF&(data))
#define  CRT_DC2_SYS_PLL_DUMMY_OUT_get_dpi_dummy_out_dll(data)                   (0xFFFFFFFF&(data))

#define  CRT_SYS_DCLKSS                                                          0x18000640
#define  CRT_SYS_DCLKSS_reg_addr                                                 "0xB8000640"
#define  CRT_SYS_DCLKSS_reg                                                      0xB8000640
#define  CRT_SYS_DCLKSS_inst_addr                                                "0x00A7"
#define  set_CRT_SYS_DCLKSS_reg(data)                                            (*((volatile unsigned int*)CRT_SYS_DCLKSS_reg)=data)
#define  get_CRT_SYS_DCLKSS_reg                                                  (*((volatile unsigned int*)CRT_SYS_DCLKSS_reg))
#define  CRT_SYS_DCLKSS_dclk_field_flag_mode_en_shift                            (31)
#define  CRT_SYS_DCLKSS_dclk_filed_flag_slt_shift                                (28)
#define  CRT_SYS_DCLKSS_dclk_new_en_shift                                        (15)
#define  CRT_SYS_DCLKSS_dummy1_shift                                              (3)
#define  CRT_SYS_DCLKSS_dclk_ss_load_shift                                       (2)
#define  CRT_SYS_DCLKSS_dummy2_shift                                              (1)
#define  CRT_SYS_DCLKSS_dclk_ss_en_shift                                         (0)
#define  CRT_SYS_DCLKSS_dclk_field_flag_mode_en_mask                             (0x80000000)
#define  CRT_SYS_DCLKSS_dclk_filed_flag_slt_mask                                 (0x70000000)
#define  CRT_SYS_DCLKSS_dclk_new_en_mask                                         (0x00008000)
#define  CRT_SYS_DCLKSS_dummy1_mask                                               (0x00000008)
#define  CRT_SYS_DCLKSS_dclk_ss_load_mask                                        (0x00000004)
#define  CRT_SYS_DCLKSS_dummy2_mask                                               (0x00000002)
#define  CRT_SYS_DCLKSS_dclk_ss_en_mask                                          (0x00000001)
#define  CRT_SYS_DCLKSS_dclk_field_flag_mode_en(data)                            (0x80000000&((data)<<31))
#define  CRT_SYS_DCLKSS_dclk_filed_flag_slt(data)                                (0x70000000&((data)<<28))
#define  CRT_SYS_DCLKSS_dclk_new_en(data)                                        (0x00008000&((data)<<15))
#define  CRT_SYS_DCLKSS_dummy1(data)                                              (0x00000008&((data)<<3))
#define  CRT_SYS_DCLKSS_dclk_ss_load(data)                                       (0x00000004&((data)<<2))
#define  CRT_SYS_DCLKSS_dummy2(data)                                              (0x00000002&((data)<<1))
#define  CRT_SYS_DCLKSS_dclk_ss_en(data)                                         (0x00000001&(data))
#define  CRT_SYS_DCLKSS_get_dclk_field_flag_mode_en(data)                        ((0x80000000&(data))>>31)
#define  CRT_SYS_DCLKSS_get_dclk_filed_flag_slt(data)                            ((0x70000000&(data))>>28)
#define  CRT_SYS_DCLKSS_get_dclk_new_en(data)                                    ((0x00008000&(data))>>15)
#define  CRT_SYS_DCLKSS_get_dummy1(data)                                          ((0x00000008&(data))>>3)
#define  CRT_SYS_DCLKSS_get_dclk_ss_load(data)                                   ((0x00000004&(data))>>2)
#define  CRT_SYS_DCLKSS_get_dummy2(data)                                          ((0x00000002&(data))>>1)
#define  CRT_SYS_DCLKSS_get_dclk_ss_en(data)                                     (0x00000001&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL                                         0x18000644
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_reg_addr                                "0xB8000644"
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_reg                                     0xB8000644
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_inst_addr                               "0x00A8"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_CTRL_reg(data)                           (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_CTRL_reg                                 (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt_shift                 (16)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en_shift                   (4)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_shift  (3)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_shift        (2)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_shift       (1)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_shift      (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt_mask                  (0x3FFF0000)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en_mask                    (0x00000010)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse_mask   (0x00000008)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en_mask         (0x00000004)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en_mask        (0x00000002)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en_mask       (0x00000001)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_dclk_freq_syn_slt(data)                 (0x3FFF0000&((data)<<16))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_fll_tracking_en(data)                   (0x00000010&((data)<<4))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_offset_inverse(data)  (0x00000008&((data)<<3))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_ypbpr_en(data)        (0x00000004&((data)<<2))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_vd_dec_en(data)       (0x00000002&((data)<<1))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_in_frame_tracking_general_en(data)      (0x00000001&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_get_dclk_freq_syn_slt(data)             ((0x3FFF0000&(data))>>16)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_get_fll_tracking_en(data)               ((0x00000010&(data))>>4)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_offset_inverse(data) ((0x00000008&(data))>>3)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_ypbpr_en(data)    ((0x00000004&(data))>>2)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_vd_dec_en(data)   ((0x00000002&(data))>>1)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL_get_in_frame_tracking_general_en(data)  (0x00000001&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2                                        0x18000648
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_reg_addr                               "0xB8000648"
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_reg                                    0xB8000648
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_inst_addr                              "0x00A9"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_reg(data)                          (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_reg                                (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_shift            (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul_mask             (0x0007FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_in_frame_tracking_mul(data)            (0x0007FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL2_get_in_frame_tracking_mul(data)        (0x0007FFFF&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3                                        0x1800064C
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_reg_addr                               "0xB800064C"
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_reg                                    0xB800064C
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_inst_addr                              "0x00AA"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_reg(data)                          (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_reg                                (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th_shift         (16)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th_shift         (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th_mask          (0xFFFF0000)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th_mask          (0x0000FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_neg_th(data)         (0xFFFF0000&((data)<<16))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_in_frame_tracking_pos_th(data)         (0x0000FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_get_in_frame_tracking_neg_th(data)     ((0xFFFF0000&(data))>>16)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL3_get_in_frame_tracking_pos_th(data)     (0x0000FFFF&(data))

#define  CRT_DCLK_FRC2FSYNC_SPEEDUP                                              0x18000650
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_reg_addr                                     "0xB8000650"
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_reg                                          0xB8000650
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_inst_addr                                    "0x00AB"
#define  set_CRT_DCLK_FRC2FSYNC_SPEEDUP_reg(data)                                (*((volatile unsigned int*)CRT_DCLK_FRC2FSYNC_SPEEDUP_reg)=data)
#define  get_CRT_DCLK_FRC2FSYNC_SPEEDUP_reg                                      (*((volatile unsigned int*)CRT_DCLK_FRC2FSYNC_SPEEDUP_reg))
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir_shift                    (16)
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_shift               (0)
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir_mask                     (0x00010000)
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset_mask                (0x00001FFF)
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speed_dir(data)                    (0x00010000&((data)<<16))
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_frc2fsync_speedup_offset(data)               (0x00001FFF&(data))
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speed_dir(data)                ((0x00010000&(data))>>16)
#define  CRT_DCLK_FRC2FSYNC_SPEEDUP_get_frc2fsync_speedup_offset(data)           (0x00001FFF&(data))

#define  CRT_DPLL_STATUS_RO                                                      0x18000654
#define  CRT_DPLL_STATUS_RO_reg_addr                                             "0xB8000654"
#define  CRT_DPLL_STATUS_RO_reg                                                  0xB8000654
#define  CRT_DPLL_STATUS_RO_inst_addr                                            "0x00AC"
#define  set_CRT_DPLL_STATUS_RO_reg(data)                                        (*((volatile unsigned int*)CRT_DPLL_STATUS_RO_reg)=data)
#define  get_CRT_DPLL_STATUS_RO_reg                                              (*((volatile unsigned int*)CRT_DPLL_STATUS_RO_reg))
#define  CRT_DPLL_STATUS_RO_final_profile_shift                                  (0)
#define  CRT_DPLL_STATUS_RO_final_profile_mask                                   (0x0003FFFF)
#define  CRT_DPLL_STATUS_RO_final_profile(data)                                  (0x0003FFFF&(data))
#define  CRT_DPLL_STATUS_RO_get_final_profile(data)                              (0x0003FFFF&(data))

#define  CRT_DCLKSS_PROFILE_CTL                                                  0x18000658
#define  CRT_DCLKSS_PROFILE_CTL_reg_addr                                         "0xB8000658"
#define  CRT_DCLKSS_PROFILE_CTL_reg                                              0xB8000658
#define  CRT_DCLKSS_PROFILE_CTL_inst_addr                                        "0x00AD"
#define  set_CRT_DCLKSS_PROFILE_CTL_reg(data)                                    (*((volatile unsigned int*)CRT_DCLKSS_PROFILE_CTL_reg)=data)
#define  get_CRT_DCLKSS_PROFILE_CTL_reg                                          (*((volatile unsigned int*)CRT_DCLKSS_PROFILE_CTL_reg))
#define  CRT_DCLKSS_PROFILE_CTL_dummy_shift                                      (12)
#define  CRT_DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt_shift                     (4)
#define  CRT_DCLKSS_PROFILE_CTL_dclk_profile_remap_en_shift                      (0)
#define  CRT_DCLKSS_PROFILE_CTL_dummy_mask                                       (0xFFFFF000)
#define  CRT_DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt_mask                      (0x00000FF0)
#define  CRT_DCLKSS_PROFILE_CTL_dclk_profile_remap_en_mask                       (0x00000001)
#define  CRT_DCLKSS_PROFILE_CTL_dummy(data)                                      (0xFFFFF000&((data)<<12))
#define  CRT_DCLKSS_PROFILE_CTL_dclk_profile_remap_cnt(data)                     (0x00000FF0&((data)<<4))
#define  CRT_DCLKSS_PROFILE_CTL_dclk_profile_remap_en(data)                      (0x00000001&(data))
#define  CRT_DCLKSS_PROFILE_CTL_get_dummy(data)                                  ((0xFFFFF000&(data))>>12)
#define  CRT_DCLKSS_PROFILE_CTL_get_dclk_profile_remap_cnt(data)                 ((0x00000FF0&(data))>>4)
#define  CRT_DCLKSS_PROFILE_CTL_get_dclk_profile_remap_en(data)                  (0x00000001&(data))

#define  CRT_DCLKSS_PROFILE0                                                     0x1800065C
#define  CRT_DCLKSS_PROFILE0_reg_addr                                            "0xB800065C"
#define  CRT_DCLKSS_PROFILE0_reg                                                 0xB800065C
#define  CRT_DCLKSS_PROFILE0_inst_addr                                           "0x00AE"
#define  set_CRT_DCLKSS_PROFILE0_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE0_reg)=data)
#define  get_CRT_DCLKSS_PROFILE0_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE0_reg))
#define  CRT_DCLKSS_PROFILE0_dclk_profile_remap_1_shift                          (16)
#define  CRT_DCLKSS_PROFILE0_dclk_profile_remap_0_shift                          (0)
#define  CRT_DCLKSS_PROFILE0_dclk_profile_remap_1_mask                           (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE0_dclk_profile_remap_0_mask                           (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE0_dclk_profile_remap_1(data)                          (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE0_dclk_profile_remap_0(data)                          (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE0_get_dclk_profile_remap_1(data)                      ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE0_get_dclk_profile_remap_0(data)                      (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE1                                                     0x18000660
#define  CRT_DCLKSS_PROFILE1_reg_addr                                            "0xB8000660"
#define  CRT_DCLKSS_PROFILE1_reg                                                 0xB8000660
#define  CRT_DCLKSS_PROFILE1_inst_addr                                           "0x00AF"
#define  set_CRT_DCLKSS_PROFILE1_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE1_reg)=data)
#define  get_CRT_DCLKSS_PROFILE1_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE1_reg))
#define  CRT_DCLKSS_PROFILE1_dclk_profile_remap_3_shift                          (16)
#define  CRT_DCLKSS_PROFILE1_dclk_profile_remap_2_shift                          (0)
#define  CRT_DCLKSS_PROFILE1_dclk_profile_remap_3_mask                           (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE1_dclk_profile_remap_2_mask                           (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE1_dclk_profile_remap_3(data)                          (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE1_dclk_profile_remap_2(data)                          (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE1_get_dclk_profile_remap_3(data)                      ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE1_get_dclk_profile_remap_2(data)                      (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE2                                                     0x18000664
#define  CRT_DCLKSS_PROFILE2_reg_addr                                            "0xB8000664"
#define  CRT_DCLKSS_PROFILE2_reg                                                 0xB8000664
#define  CRT_DCLKSS_PROFILE2_inst_addr                                           "0x00B0"
#define  set_CRT_DCLKSS_PROFILE2_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE2_reg)=data)
#define  get_CRT_DCLKSS_PROFILE2_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE2_reg))
#define  CRT_DCLKSS_PROFILE2_dclk_profile_remap_5_shift                          (16)
#define  CRT_DCLKSS_PROFILE2_dclk_profile_remap_4_shift                          (0)
#define  CRT_DCLKSS_PROFILE2_dclk_profile_remap_5_mask                           (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE2_dclk_profile_remap_4_mask                           (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE2_dclk_profile_remap_5(data)                          (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE2_dclk_profile_remap_4(data)                          (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE2_get_dclk_profile_remap_5(data)                      ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE2_get_dclk_profile_remap_4(data)                      (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE3                                                     0x18000668
#define  CRT_DCLKSS_PROFILE3_reg_addr                                            "0xB8000668"
#define  CRT_DCLKSS_PROFILE3_reg                                                 0xB8000668
#define  CRT_DCLKSS_PROFILE3_inst_addr                                           "0x00B1"
#define  set_CRT_DCLKSS_PROFILE3_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE3_reg)=data)
#define  get_CRT_DCLKSS_PROFILE3_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE3_reg))
#define  CRT_DCLKSS_PROFILE3_dclk_profile_remap_7_shift                          (16)
#define  CRT_DCLKSS_PROFILE3_dclk_profile_remap_6_shift                          (0)
#define  CRT_DCLKSS_PROFILE3_dclk_profile_remap_7_mask                           (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE3_dclk_profile_remap_6_mask                           (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE3_dclk_profile_remap_7(data)                          (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE3_dclk_profile_remap_6(data)                          (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE3_get_dclk_profile_remap_7(data)                      ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE3_get_dclk_profile_remap_6(data)                      (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE4                                                     0x1800066C
#define  CRT_DCLKSS_PROFILE4_reg_addr                                            "0xB800066C"
#define  CRT_DCLKSS_PROFILE4_reg                                                 0xB800066C
#define  CRT_DCLKSS_PROFILE4_inst_addr                                           "0x00B2"
#define  set_CRT_DCLKSS_PROFILE4_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE4_reg)=data)
#define  get_CRT_DCLKSS_PROFILE4_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE4_reg))
#define  CRT_DCLKSS_PROFILE4_dclk_profile_remap_9_shift                          (16)
#define  CRT_DCLKSS_PROFILE4_dclk_profile_remap_8_shift                          (0)
#define  CRT_DCLKSS_PROFILE4_dclk_profile_remap_9_mask                           (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE4_dclk_profile_remap_8_mask                           (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE4_dclk_profile_remap_9(data)                          (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE4_dclk_profile_remap_8(data)                          (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE4_get_dclk_profile_remap_9(data)                      ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE4_get_dclk_profile_remap_8(data)                      (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE5                                                     0x18000670
#define  CRT_DCLKSS_PROFILE5_reg_addr                                            "0xB8000670"
#define  CRT_DCLKSS_PROFILE5_reg                                                 0xB8000670
#define  CRT_DCLKSS_PROFILE5_inst_addr                                           "0x00B3"
#define  set_CRT_DCLKSS_PROFILE5_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE5_reg)=data)
#define  get_CRT_DCLKSS_PROFILE5_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE5_reg))
#define  CRT_DCLKSS_PROFILE5_dclk_profile_remap_11_shift                         (16)
#define  CRT_DCLKSS_PROFILE5_dclk_profile_remap_10_shift                         (0)
#define  CRT_DCLKSS_PROFILE5_dclk_profile_remap_11_mask                          (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE5_dclk_profile_remap_10_mask                          (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE5_dclk_profile_remap_11(data)                         (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE5_dclk_profile_remap_10(data)                         (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE5_get_dclk_profile_remap_11(data)                     ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE5_get_dclk_profile_remap_10(data)                     (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE6                                                     0x18000674
#define  CRT_DCLKSS_PROFILE6_reg_addr                                            "0xB8000674"
#define  CRT_DCLKSS_PROFILE6_reg                                                 0xB8000674
#define  CRT_DCLKSS_PROFILE6_inst_addr                                           "0x00B4"
#define  set_CRT_DCLKSS_PROFILE6_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE6_reg)=data)
#define  get_CRT_DCLKSS_PROFILE6_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE6_reg))
#define  CRT_DCLKSS_PROFILE6_dclk_profile_remap_13_shift                         (16)
#define  CRT_DCLKSS_PROFILE6_dclk_profile_remap_12_shift                         (0)
#define  CRT_DCLKSS_PROFILE6_dclk_profile_remap_13_mask                          (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE6_dclk_profile_remap_12_mask                          (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE6_dclk_profile_remap_13(data)                         (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE6_dclk_profile_remap_12(data)                         (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE6_get_dclk_profile_remap_13(data)                     ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE6_get_dclk_profile_remap_12(data)                     (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE7                                                     0x18000678
#define  CRT_DCLKSS_PROFILE7_reg_addr                                            "0xB8000678"
#define  CRT_DCLKSS_PROFILE7_reg                                                 0xB8000678
#define  CRT_DCLKSS_PROFILE7_inst_addr                                           "0x00B5"
#define  set_CRT_DCLKSS_PROFILE7_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE7_reg)=data)
#define  get_CRT_DCLKSS_PROFILE7_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE7_reg))
#define  CRT_DCLKSS_PROFILE7_dclk_profile_remap_15_shift                         (16)
#define  CRT_DCLKSS_PROFILE7_dclk_profile_remap_14_shift                         (0)
#define  CRT_DCLKSS_PROFILE7_dclk_profile_remap_15_mask                          (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE7_dclk_profile_remap_14_mask                          (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE7_dclk_profile_remap_15(data)                         (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE7_dclk_profile_remap_14(data)                         (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE7_get_dclk_profile_remap_15(data)                     ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE7_get_dclk_profile_remap_14(data)                     (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE8                                                     0x1800067C
#define  CRT_DCLKSS_PROFILE8_reg_addr                                            "0xB800067C"
#define  CRT_DCLKSS_PROFILE8_reg                                                 0xB800067C
#define  CRT_DCLKSS_PROFILE8_inst_addr                                           "0x00B6"
#define  set_CRT_DCLKSS_PROFILE8_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE8_reg)=data)
#define  get_CRT_DCLKSS_PROFILE8_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE8_reg))
#define  CRT_DCLKSS_PROFILE8_dclk_profile_remap_17_shift                         (16)
#define  CRT_DCLKSS_PROFILE8_dclk_profile_remap_16_shift                         (0)
#define  CRT_DCLKSS_PROFILE8_dclk_profile_remap_17_mask                          (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE8_dclk_profile_remap_16_mask                          (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE8_dclk_profile_remap_17(data)                         (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE8_dclk_profile_remap_16(data)                         (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE8_get_dclk_profile_remap_17(data)                     ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE8_get_dclk_profile_remap_16(data)                     (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE9                                                     0x18000680
#define  CRT_DCLKSS_PROFILE9_reg_addr                                            "0xB8000680"
#define  CRT_DCLKSS_PROFILE9_reg                                                 0xB8000680
#define  CRT_DCLKSS_PROFILE9_inst_addr                                           "0x00B7"
#define  set_CRT_DCLKSS_PROFILE9_reg(data)                                       (*((volatile unsigned int*)CRT_DCLKSS_PROFILE9_reg)=data)
#define  get_CRT_DCLKSS_PROFILE9_reg                                             (*((volatile unsigned int*)CRT_DCLKSS_PROFILE9_reg))
#define  CRT_DCLKSS_PROFILE9_dclk_profile_remap_19_shift                         (16)
#define  CRT_DCLKSS_PROFILE9_dclk_profile_remap_18_shift                         (0)
#define  CRT_DCLKSS_PROFILE9_dclk_profile_remap_19_mask                          (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE9_dclk_profile_remap_18_mask                          (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE9_dclk_profile_remap_19(data)                         (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE9_dclk_profile_remap_18(data)                         (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE9_get_dclk_profile_remap_19(data)                     ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE9_get_dclk_profile_remap_18(data)                     (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE10                                                    0x18000684
#define  CRT_DCLKSS_PROFILE10_reg_addr                                           "0xB8000684"
#define  CRT_DCLKSS_PROFILE10_reg                                                0xB8000684
#define  CRT_DCLKSS_PROFILE10_inst_addr                                          "0x00B8"
#define  set_CRT_DCLKSS_PROFILE10_reg(data)                                      (*((volatile unsigned int*)CRT_DCLKSS_PROFILE10_reg)=data)
#define  get_CRT_DCLKSS_PROFILE10_reg                                            (*((volatile unsigned int*)CRT_DCLKSS_PROFILE10_reg))
#define  CRT_DCLKSS_PROFILE10_dclk_profile_remap_21_shift                        (16)
#define  CRT_DCLKSS_PROFILE10_dclk_profile_remap_20_shift                        (0)
#define  CRT_DCLKSS_PROFILE10_dclk_profile_remap_21_mask                         (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE10_dclk_profile_remap_20_mask                         (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE10_dclk_profile_remap_21(data)                        (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE10_dclk_profile_remap_20(data)                        (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE10_get_dclk_profile_remap_21(data)                    ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE10_get_dclk_profile_remap_20(data)                    (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE11                                                    0x18000688
#define  CRT_DCLKSS_PROFILE11_reg_addr                                           "0xB8000688"
#define  CRT_DCLKSS_PROFILE11_reg                                                0xB8000688
#define  CRT_DCLKSS_PROFILE11_inst_addr                                          "0x00B9"
#define  set_CRT_DCLKSS_PROFILE11_reg(data)                                      (*((volatile unsigned int*)CRT_DCLKSS_PROFILE11_reg)=data)
#define  get_CRT_DCLKSS_PROFILE11_reg                                            (*((volatile unsigned int*)CRT_DCLKSS_PROFILE11_reg))
#define  CRT_DCLKSS_PROFILE11_dclk_profile_remap_23_shift                        (16)
#define  CRT_DCLKSS_PROFILE11_dclk_profile_remap_22_shift                        (0)
#define  CRT_DCLKSS_PROFILE11_dclk_profile_remap_23_mask                         (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE11_dclk_profile_remap_22_mask                         (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE11_dclk_profile_remap_23(data)                        (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE11_dclk_profile_remap_22(data)                        (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE11_get_dclk_profile_remap_23(data)                    ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE11_get_dclk_profile_remap_22(data)                    (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE12                                                    0x1800068C
#define  CRT_DCLKSS_PROFILE12_reg_addr                                           "0xB800068C"
#define  CRT_DCLKSS_PROFILE12_reg                                                0xB800068C
#define  CRT_DCLKSS_PROFILE12_inst_addr                                          "0x00BA"
#define  set_CRT_DCLKSS_PROFILE12_reg(data)                                      (*((volatile unsigned int*)CRT_DCLKSS_PROFILE12_reg)=data)
#define  get_CRT_DCLKSS_PROFILE12_reg                                            (*((volatile unsigned int*)CRT_DCLKSS_PROFILE12_reg))
#define  CRT_DCLKSS_PROFILE12_dclk_profile_remap_25_shift                        (16)
#define  CRT_DCLKSS_PROFILE12_dclk_profile_remap_24_shift                        (0)
#define  CRT_DCLKSS_PROFILE12_dclk_profile_remap_25_mask                         (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE12_dclk_profile_remap_24_mask                         (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE12_dclk_profile_remap_25(data)                        (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE12_dclk_profile_remap_24(data)                        (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE12_get_dclk_profile_remap_25(data)                    ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE12_get_dclk_profile_remap_24(data)                    (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE13                                                    0x18000690
#define  CRT_DCLKSS_PROFILE13_reg_addr                                           "0xB8000690"
#define  CRT_DCLKSS_PROFILE13_reg                                                0xB8000690
#define  CRT_DCLKSS_PROFILE13_inst_addr                                          "0x00BB"
#define  set_CRT_DCLKSS_PROFILE13_reg(data)                                      (*((volatile unsigned int*)CRT_DCLKSS_PROFILE13_reg)=data)
#define  get_CRT_DCLKSS_PROFILE13_reg                                            (*((volatile unsigned int*)CRT_DCLKSS_PROFILE13_reg))
#define  CRT_DCLKSS_PROFILE13_dclk_profile_remap_27_shift                        (16)
#define  CRT_DCLKSS_PROFILE13_dclk_profile_remap_26_shift                        (0)
#define  CRT_DCLKSS_PROFILE13_dclk_profile_remap_27_mask                         (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE13_dclk_profile_remap_26_mask                         (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE13_dclk_profile_remap_27(data)                        (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE13_dclk_profile_remap_26(data)                        (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE13_get_dclk_profile_remap_27(data)                    ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE13_get_dclk_profile_remap_26(data)                    (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE14                                                    0x18000694
#define  CRT_DCLKSS_PROFILE14_reg_addr                                           "0xB8000694"
#define  CRT_DCLKSS_PROFILE14_reg                                                0xB8000694
#define  CRT_DCLKSS_PROFILE14_inst_addr                                          "0x00BC"
#define  set_CRT_DCLKSS_PROFILE14_reg(data)                                      (*((volatile unsigned int*)CRT_DCLKSS_PROFILE14_reg)=data)
#define  get_CRT_DCLKSS_PROFILE14_reg                                            (*((volatile unsigned int*)CRT_DCLKSS_PROFILE14_reg))
#define  CRT_DCLKSS_PROFILE14_dclk_profile_remap_29_shift                        (16)
#define  CRT_DCLKSS_PROFILE14_dclk_profile_remap_28_shift                        (0)
#define  CRT_DCLKSS_PROFILE14_dclk_profile_remap_29_mask                         (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE14_dclk_profile_remap_28_mask                         (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE14_dclk_profile_remap_29(data)                        (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE14_dclk_profile_remap_28(data)                        (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE14_get_dclk_profile_remap_29(data)                    ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE14_get_dclk_profile_remap_28(data)                    (0x0000FFFF&(data))

#define  CRT_DCLKSS_PROFILE15                                                    0x18000698
#define  CRT_DCLKSS_PROFILE15_reg_addr                                           "0xB8000698"
#define  CRT_DCLKSS_PROFILE15_reg                                                0xB8000698
#define  CRT_DCLKSS_PROFILE15_inst_addr                                          "0x00BD"
#define  set_CRT_DCLKSS_PROFILE15_reg(data)                                      (*((volatile unsigned int*)CRT_DCLKSS_PROFILE15_reg)=data)
#define  get_CRT_DCLKSS_PROFILE15_reg                                            (*((volatile unsigned int*)CRT_DCLKSS_PROFILE15_reg))
#define  CRT_DCLKSS_PROFILE15_dclk_profile_remap_31_shift                        (16)
#define  CRT_DCLKSS_PROFILE15_dclk_profile_remap_30_shift                        (0)
#define  CRT_DCLKSS_PROFILE15_dclk_profile_remap_31_mask                         (0xFFFF0000)
#define  CRT_DCLKSS_PROFILE15_dclk_profile_remap_30_mask                         (0x0000FFFF)
#define  CRT_DCLKSS_PROFILE15_dclk_profile_remap_31(data)                        (0xFFFF0000&((data)<<16))
#define  CRT_DCLKSS_PROFILE15_dclk_profile_remap_30(data)                        (0x0000FFFF&(data))
#define  CRT_DCLKSS_PROFILE15_get_dclk_profile_remap_31(data)                    ((0xFFFF0000&(data))>>16)
#define  CRT_DCLKSS_PROFILE15_get_dclk_profile_remap_30(data)                    (0x0000FFFF&(data))

#define  CRT_dpll_Double_Buffer_CTRL                                             0x1800069C
#define  CRT_dpll_Double_Buffer_CTRL_reg_addr                                    "0xB800069C"
#define  CRT_dpll_Double_Buffer_CTRL_reg                                         0xB800069C
#define  CRT_dpll_Double_Buffer_CTRL_inst_addr                                   "0x00BE"
#define  set_CRT_dpll_Double_Buffer_CTRL_reg(data)                               (*((volatile unsigned int*)CRT_dpll_Double_Buffer_CTRL_reg)=data)
#define  get_CRT_dpll_Double_Buffer_CTRL_reg                                     (*((volatile unsigned int*)CRT_dpll_Double_Buffer_CTRL_reg))
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_en_shift                         (2)
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_read_sel_shift                   (1)
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_apply_shift                      (0)
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_en_mask                          (0x00000004)
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_read_sel_mask                    (0x00000002)
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_apply_mask                       (0x00000001)
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_en(data)                         (0x00000004&((data)<<2))
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_read_sel(data)                   (0x00000002&((data)<<1))
#define  CRT_dpll_Double_Buffer_CTRL_double_buf_apply(data)                      (0x00000001&(data))
#define  CRT_dpll_Double_Buffer_CTRL_get_double_buf_en(data)                     ((0x00000004&(data))>>2)
#define  CRT_dpll_Double_Buffer_CTRL_get_double_buf_read_sel(data)               ((0x00000002&(data))>>1)
#define  CRT_dpll_Double_Buffer_CTRL_get_double_buf_apply(data)                  (0x00000001&(data))

#define  CRT_PLL_SSC0                                                            0x180006A0
#define  CRT_PLL_SSC0_reg_addr                                                   "0xB80006A0"
#define  CRT_PLL_SSC0_reg                                                        0xB80006A0
#define  CRT_PLL_SSC0_inst_addr                                                  "0x00BF"
#define  set_CRT_PLL_SSC0_reg(data)                                              (*((volatile unsigned int*)CRT_PLL_SSC0_reg)=data)
#define  get_CRT_PLL_SSC0_reg                                                    (*((volatile unsigned int*)CRT_PLL_SSC0_reg))
#define  CRT_PLL_SSC0_fcode_t_ssc_shift                                          (16)
#define  CRT_PLL_SSC0_oc_step_set_shift                                          (4)
#define  CRT_PLL_SSC0_oc_en_shift                                                (0)
#define  CRT_PLL_SSC0_fcode_t_ssc_mask                                           (0x07FF0000)
#define  CRT_PLL_SSC0_oc_step_set_mask                                           (0x00003FF0)
#define  CRT_PLL_SSC0_oc_en_mask                                                 (0x00000001)
#define  CRT_PLL_SSC0_fcode_t_ssc(data)                                          (0x07FF0000&((data)<<16))
#define  CRT_PLL_SSC0_oc_step_set(data)                                          (0x00003FF0&((data)<<4))
#define  CRT_PLL_SSC0_oc_en(data)                                                (0x00000001&(data))
#define  CRT_PLL_SSC0_get_fcode_t_ssc(data)                                      ((0x07FF0000&(data))>>16)
#define  CRT_PLL_SSC0_get_oc_step_set(data)                                      ((0x00003FF0&(data))>>4)
#define  CRT_PLL_SSC0_get_oc_en(data)                                            (0x00000001&(data))

#define  CRT_PLL_SSC1                                                            0x180006A4
#define  CRT_PLL_SSC1_reg_addr                                                   "0xB80006A4"
#define  CRT_PLL_SSC1_reg                                                        0xB80006A4
#define  CRT_PLL_SSC1_inst_addr                                                  "0x00C0"
#define  set_CRT_PLL_SSC1_reg(data)                                              (*((volatile unsigned int*)CRT_PLL_SSC1_reg)=data)
#define  get_CRT_PLL_SSC1_reg                                                    (*((volatile unsigned int*)CRT_PLL_SSC1_reg))
#define  CRT_PLL_SSC1_oc_done_delay_shift                                        (16)
#define  CRT_PLL_SSC1_hs_oc_stop_diff_shift                                      (12)
#define  CRT_PLL_SSC1_sel_oc_mode_shift                                          (8)
#define  CRT_PLL_SSC1_oc_done_delay_mask                                         (0x003F0000)
#define  CRT_PLL_SSC1_hs_oc_stop_diff_mask                                       (0x00003000)
#define  CRT_PLL_SSC1_sel_oc_mode_mask                                           (0x00000300)
#define  CRT_PLL_SSC1_oc_done_delay(data)                                        (0x003F0000&((data)<<16))
#define  CRT_PLL_SSC1_hs_oc_stop_diff(data)                                      (0x00003000&((data)<<12))
#define  CRT_PLL_SSC1_sel_oc_mode(data)                                          (0x00000300&((data)<<8))
#define  CRT_PLL_SSC1_get_oc_done_delay(data)                                    ((0x003F0000&(data))>>16)
#define  CRT_PLL_SSC1_get_hs_oc_stop_diff(data)                                  ((0x00003000&(data))>>12)
#define  CRT_PLL_SSC1_get_sel_oc_mode(data)                                      ((0x00000300&(data))>>8)

#define  CRT_PLL_SSC2                                                            0x180006A8
#define  CRT_PLL_SSC2_reg_addr                                                   "0xB80006A8"
#define  CRT_PLL_SSC2_reg                                                        0xB80006A8
#define  CRT_PLL_SSC2_inst_addr                                                  "0x00C1"
#define  set_CRT_PLL_SSC2_reg(data)                                              (*((volatile unsigned int*)CRT_PLL_SSC2_reg)=data)
#define  get_CRT_PLL_SSC2_reg                                                    (*((volatile unsigned int*)CRT_PLL_SSC2_reg))
#define  CRT_PLL_SSC2_en_pi_debug_shift                                          (2)
#define  CRT_PLL_SSC2_sdm_order_shift                                            (1)
#define  CRT_PLL_SSC2_bypass_pi_shift                                            (0)
#define  CRT_PLL_SSC2_en_pi_debug_mask                                           (0x00000004)
#define  CRT_PLL_SSC2_sdm_order_mask                                             (0x00000002)
#define  CRT_PLL_SSC2_bypass_pi_mask                                             (0x00000001)
#define  CRT_PLL_SSC2_en_pi_debug(data)                                          (0x00000004&((data)<<2))
#define  CRT_PLL_SSC2_sdm_order(data)                                            (0x00000002&((data)<<1))
#define  CRT_PLL_SSC2_bypass_pi(data)                                            (0x00000001&(data))
#define  CRT_PLL_SSC2_get_en_pi_debug(data)                                      ((0x00000004&(data))>>2)
#define  CRT_PLL_SSC2_get_sdm_order(data)                                        ((0x00000002&(data))>>1)
#define  CRT_PLL_SSC2_get_bypass_pi(data)                                        (0x00000001&(data))

#define  CRT_PLL_SSC3                                                            0x180006AC
#define  CRT_PLL_SSC3_reg_addr                                                   "0xB80006AC"
#define  CRT_PLL_SSC3_reg                                                        0xB80006AC
#define  CRT_PLL_SSC3_inst_addr                                                  "0x00C2"
#define  set_CRT_PLL_SSC3_reg(data)                                              (*((volatile unsigned int*)CRT_PLL_SSC3_reg)=data)
#define  get_CRT_PLL_SSC3_reg                                                    (*((volatile unsigned int*)CRT_PLL_SSC3_reg))
#define  CRT_PLL_SSC3_ncode_ssc_shift                                            (16)
#define  CRT_PLL_SSC3_fcode_ssc_shift                                            (0)
#define  CRT_PLL_SSC3_ncode_ssc_mask                                             (0x00FF0000)
#define  CRT_PLL_SSC3_fcode_ssc_mask                                             (0x000007FF)
#define  CRT_PLL_SSC3_ncode_ssc(data)                                            (0x00FF0000&((data)<<16))
#define  CRT_PLL_SSC3_fcode_ssc(data)                                            (0x000007FF&(data))
#define  CRT_PLL_SSC3_get_ncode_ssc(data)                                        ((0x00FF0000&(data))>>16)
#define  CRT_PLL_SSC3_get_fcode_ssc(data)                                        (0x000007FF&(data))

#define  CRT_PLL_SSC4                                                            0x180006B0
#define  CRT_PLL_SSC4_reg_addr                                                   "0xB80006B0"
#define  CRT_PLL_SSC4_reg                                                        0xB80006B0
#define  CRT_PLL_SSC4_inst_addr                                                  "0x00C3"
#define  set_CRT_PLL_SSC4_reg(data)                                              (*((volatile unsigned int*)CRT_PLL_SSC4_reg)=data)
#define  get_CRT_PLL_SSC4_reg                                                    (*((volatile unsigned int*)CRT_PLL_SSC4_reg))
#define  CRT_PLL_SSC4_gran_auto_rst_shift                                        (28)
#define  CRT_PLL_SSC4_dot_gran_shift                                             (24)
#define  CRT_PLL_SSC4_gran_est_shift                                             (4)
#define  CRT_PLL_SSC4_en_ssc_shift                                               (0)
#define  CRT_PLL_SSC4_gran_auto_rst_mask                                         (0x10000000)
#define  CRT_PLL_SSC4_dot_gran_mask                                              (0x07000000)
#define  CRT_PLL_SSC4_gran_est_mask                                              (0x007FFFF0)
#define  CRT_PLL_SSC4_en_ssc_mask                                                (0x00000001)
#define  CRT_PLL_SSC4_gran_auto_rst(data)                                        (0x10000000&((data)<<28))
#define  CRT_PLL_SSC4_dot_gran(data)                                             (0x07000000&((data)<<24))
#define  CRT_PLL_SSC4_gran_est(data)                                             (0x007FFFF0&((data)<<4))
#define  CRT_PLL_SSC4_en_ssc(data)                                               (0x00000001&(data))
#define  CRT_PLL_SSC4_get_gran_auto_rst(data)                                    ((0x10000000&(data))>>28)
#define  CRT_PLL_SSC4_get_dot_gran(data)                                         ((0x07000000&(data))>>24)
#define  CRT_PLL_SSC4_get_gran_est(data)                                         ((0x007FFFF0&(data))>>4)
#define  CRT_PLL_SSC4_get_en_ssc(data)                                           (0x00000001&(data))

#define  CRT_PLL_SSC5                                                            0x180006B4
#define  CRT_PLL_SSC5_reg_addr                                                   "0xB80006B4"
#define  CRT_PLL_SSC5_reg                                                        0xB80006B4
#define  CRT_PLL_SSC5_inst_addr                                                  "0x00C4"
#define  set_CRT_PLL_SSC5_reg(data)                                              (*((volatile unsigned int*)CRT_PLL_SSC5_reg)=data)
#define  get_CRT_PLL_SSC5_reg                                                    (*((volatile unsigned int*)CRT_PLL_SSC5_reg))
#define  CRT_PLL_SSC5_fcode_debug_shift                                          (16)
#define  CRT_PLL_SSC5_ncode_debug_shift                                          (8)
#define  CRT_PLL_SSC5_oc_done_shift                                              (4)
#define  CRT_PLL_SSC5_load_fcw_shift                                             (1)
#define  CRT_PLL_SSC5_fmod_shift                                                 (0)
#define  CRT_PLL_SSC5_fcode_debug_mask                                           (0x07FF0000)
#define  CRT_PLL_SSC5_ncode_debug_mask                                           (0x0000FF00)
#define  CRT_PLL_SSC5_oc_done_mask                                               (0x00000010)
#define  CRT_PLL_SSC5_load_fcw_mask                                              (0x00000002)
#define  CRT_PLL_SSC5_fmod_mask                                                  (0x00000001)
#define  CRT_PLL_SSC5_fcode_debug(data)                                          (0x07FF0000&((data)<<16))
#define  CRT_PLL_SSC5_ncode_debug(data)                                          (0x0000FF00&((data)<<8))
#define  CRT_PLL_SSC5_oc_done(data)                                              (0x00000010&((data)<<4))
#define  CRT_PLL_SSC5_load_fcw(data)                                             (0x00000002&((data)<<1))
#define  CRT_PLL_SSC5_fmod(data)                                                 (0x00000001&(data))
#define  CRT_PLL_SSC5_get_fcode_debug(data)                                      ((0x07FF0000&(data))>>16)
#define  CRT_PLL_SSC5_get_ncode_debug(data)                                      ((0x0000FF00&(data))>>8)
#define  CRT_PLL_SSC5_get_oc_done(data)                                          ((0x00000010&(data))>>4)
#define  CRT_PLL_SSC5_get_load_fcw(data)                                         ((0x00000002&(data))>>1)
#define  CRT_PLL_SSC5_get_fmod(data)                                             (0x00000001&(data))

#define  CRT_SYS_PLL_DISP1                                                       0x180006C0
#define  CRT_SYS_PLL_DISP1_reg_addr                                              "0xB80006C0"
#define  CRT_SYS_PLL_DISP1_reg                                                   0xB80006C0
#define  CRT_SYS_PLL_DISP1_inst_addr                                             "0x00C5"
#define  set_CRT_SYS_PLL_DISP1_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_DISP1_reg)=data)
#define  get_CRT_SYS_PLL_DISP1_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_DISP1_reg))
#define  CRT_SYS_PLL_DISP1_dpll_m_shift                                          (20)
#define  CRT_SYS_PLL_DISP1_dpll_n_shift                                          (12)
#define  CRT_SYS_PLL_DISP1_dpll_ip_shift                                         (8)
#define  CRT_SYS_PLL_DISP1_dpll_ssc_inv_shift                                    (7)
#define  CRT_SYS_PLL_DISP1_dpll_rs_shift                                         (4)
#define  CRT_SYS_PLL_DISP1_dpll_cp_shift                                         (2)
#define  CRT_SYS_PLL_DISP1_dpll_cs_shift                                         (0)
#define  CRT_SYS_PLL_DISP1_dpll_m_mask                                           (0x0FF00000)
#define  CRT_SYS_PLL_DISP1_dpll_n_mask                                           (0x00007000)
#define  CRT_SYS_PLL_DISP1_dpll_ip_mask                                          (0x00000700)
#define  CRT_SYS_PLL_DISP1_dpll_ssc_inv_mask                                     (0x00000080)
#define  CRT_SYS_PLL_DISP1_dpll_rs_mask                                          (0x00000070)
#define  CRT_SYS_PLL_DISP1_dpll_cp_mask                                          (0x0000000C)
#define  CRT_SYS_PLL_DISP1_dpll_cs_mask                                          (0x00000003)
#define  CRT_SYS_PLL_DISP1_dpll_m(data)                                          (0x0FF00000&((data)<<20))
#define  CRT_SYS_PLL_DISP1_dpll_n(data)                                          (0x00007000&((data)<<12))
#define  CRT_SYS_PLL_DISP1_dpll_ip(data)                                         (0x00000700&((data)<<8))
#define  CRT_SYS_PLL_DISP1_dpll_ssc_inv(data)                                    (0x00000080&((data)<<7))
#define  CRT_SYS_PLL_DISP1_dpll_rs(data)                                         (0x00000070&((data)<<4))
#define  CRT_SYS_PLL_DISP1_dpll_cp(data)                                         (0x0000000C&((data)<<2))
#define  CRT_SYS_PLL_DISP1_dpll_cs(data)                                         (0x00000003&(data))
#define  CRT_SYS_PLL_DISP1_get_dpll_m(data)                                      ((0x0FF00000&(data))>>20)
#define  CRT_SYS_PLL_DISP1_get_dpll_n(data)                                      ((0x00007000&(data))>>12)
#define  CRT_SYS_PLL_DISP1_get_dpll_ip(data)                                     ((0x00000700&(data))>>8)
#define  CRT_SYS_PLL_DISP1_get_dpll_ssc_inv(data)                                ((0x00000080&(data))>>7)
#define  CRT_SYS_PLL_DISP1_get_dpll_rs(data)                                     ((0x00000070&(data))>>4)
#define  CRT_SYS_PLL_DISP1_get_dpll_cp(data)                                     ((0x0000000C&(data))>>2)
#define  CRT_SYS_PLL_DISP1_get_dpll_cs(data)                                     (0x00000003&(data))

#define  CRT_SYS_PLL_DISP2                                                       0x180006C4
#define  CRT_SYS_PLL_DISP2_reg_addr                                              "0xB80006C4"
#define  CRT_SYS_PLL_DISP2_reg                                                   0xB80006C4
#define  CRT_SYS_PLL_DISP2_inst_addr                                             "0x00C6"
#define  set_CRT_SYS_PLL_DISP2_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_DISP2_reg)=data)
#define  get_CRT_SYS_PLL_DISP2_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_DISP2_reg))
#define  CRT_SYS_PLL_DISP2_dpll_x_bpspi_shift                                    (1)
#define  CRT_SYS_PLL_DISP2_dpll_x_bpsin_shift                                    (0)
#define  CRT_SYS_PLL_DISP2_dpll_x_bpspi_mask                                     (0x00000002)
#define  CRT_SYS_PLL_DISP2_dpll_x_bpsin_mask                                     (0x00000001)
#define  CRT_SYS_PLL_DISP2_dpll_x_bpspi(data)                                    (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DISP2_dpll_x_bpsin(data)                                    (0x00000001&(data))
#define  CRT_SYS_PLL_DISP2_get_dpll_x_bpspi(data)                                ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DISP2_get_dpll_x_bpsin(data)                                (0x00000001&(data))

#define  CRT_SYS_PLL_DISP3                                                       0x180006C8
#define  CRT_SYS_PLL_DISP3_reg_addr                                              "0xB80006C8"
#define  CRT_SYS_PLL_DISP3_reg                                                   0xB80006C8
#define  CRT_SYS_PLL_DISP3_inst_addr                                             "0x00C7"
#define  set_CRT_SYS_PLL_DISP3_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_DISP3_reg)=data)
#define  get_CRT_SYS_PLL_DISP3_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_DISP3_reg))
#define  CRT_SYS_PLL_DISP3_dpll_ldosel_shift                                     (28)
#define  CRT_SYS_PLL_DISP3_dpll_reser_shift                                      (24)
#define  CRT_SYS_PLL_DISP3_dpll_fupdn_shift                                      (21)
#define  CRT_SYS_PLL_DISP3_dpll_stop_shift                                       (20)
#define  CRT_SYS_PLL_DISP3_dpll_reserve_shift                                    (17)
#define  CRT_SYS_PLL_DISP3_dpll_bpphs_shift                                      (16)
#define  CRT_SYS_PLL_DISP3_dpll_bpn_shift                                        (14)
#define  CRT_SYS_PLL_DISP3_dpll_o_shift                                          (12)
#define  CRT_SYS_PLL_DISP3_dpll_rstb_shift                                       (6)
#define  CRT_SYS_PLL_DISP3_dpll_wdrst_shift                                      (5)
#define  CRT_SYS_PLL_DISP3_dpll_wdset_shift                                      (4)
#define  CRT_SYS_PLL_DISP3_dpll_freeze_shift                                     (2)
#define  CRT_SYS_PLL_DISP3_dpll_vcorstb_shift                                    (1)
#define  CRT_SYS_PLL_DISP3_dpll_pow_shift                                        (0)
#define  CRT_SYS_PLL_DISP3_dpll_ldosel_mask                                      (0x30000000)
#define  CRT_SYS_PLL_DISP3_dpll_reser_mask                                       (0x0F000000)
#define  CRT_SYS_PLL_DISP3_dpll_fupdn_mask                                       (0x00200000)
#define  CRT_SYS_PLL_DISP3_dpll_stop_mask                                        (0x00100000)
#define  CRT_SYS_PLL_DISP3_dpll_reserve_mask                                     (0x00020000)
#define  CRT_SYS_PLL_DISP3_dpll_bpphs_mask                                       (0x00010000)
#define  CRT_SYS_PLL_DISP3_dpll_bpn_mask                                         (0x00004000)
#define  CRT_SYS_PLL_DISP3_dpll_o_mask                                           (0x00003000)
#define  CRT_SYS_PLL_DISP3_dpll_rstb_mask                                        (0x00000040)
#define  CRT_SYS_PLL_DISP3_dpll_wdrst_mask                                       (0x00000020)
#define  CRT_SYS_PLL_DISP3_dpll_wdset_mask                                       (0x00000010)
#define  CRT_SYS_PLL_DISP3_dpll_freeze_mask                                      (0x00000004)
#define  CRT_SYS_PLL_DISP3_dpll_vcorstb_mask                                     (0x00000002)
#define  CRT_SYS_PLL_DISP3_dpll_pow_mask                                         (0x00000001)
#define  CRT_SYS_PLL_DISP3_dpll_ldosel(data)                                     (0x30000000&((data)<<28))
#define  CRT_SYS_PLL_DISP3_dpll_reser(data)                                      (0x0F000000&((data)<<24))
#define  CRT_SYS_PLL_DISP3_dpll_fupdn(data)                                      (0x00200000&((data)<<21))
#define  CRT_SYS_PLL_DISP3_dpll_stop(data)                                       (0x00100000&((data)<<20))
#define  CRT_SYS_PLL_DISP3_dpll_reserve(data)                                    (0x00020000&((data)<<17))
#define  CRT_SYS_PLL_DISP3_dpll_bpphs(data)                                      (0x00010000&((data)<<16))
#define  CRT_SYS_PLL_DISP3_dpll_bpn(data)                                        (0x00004000&((data)<<14))
#define  CRT_SYS_PLL_DISP3_dpll_o(data)                                          (0x00003000&((data)<<12))
#define  CRT_SYS_PLL_DISP3_dpll_rstb(data)                                       (0x00000040&((data)<<6))
#define  CRT_SYS_PLL_DISP3_dpll_wdrst(data)                                      (0x00000020&((data)<<5))
#define  CRT_SYS_PLL_DISP3_dpll_wdset(data)                                      (0x00000010&((data)<<4))
#define  CRT_SYS_PLL_DISP3_dpll_freeze(data)                                     (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DISP3_dpll_vcorstb(data)                                    (0x00000002&((data)<<1))
#define  CRT_SYS_PLL_DISP3_dpll_pow(data)                                        (0x00000001&(data))
#define  CRT_SYS_PLL_DISP3_get_dpll_ldosel(data)                                 ((0x30000000&(data))>>28)
#define  CRT_SYS_PLL_DISP3_get_dpll_reser(data)                                  ((0x0F000000&(data))>>24)
#define  CRT_SYS_PLL_DISP3_get_dpll_fupdn(data)                                  ((0x00200000&(data))>>21)
#define  CRT_SYS_PLL_DISP3_get_dpll_stop(data)                                   ((0x00100000&(data))>>20)
#define  CRT_SYS_PLL_DISP3_get_dpll_reserve(data)                                ((0x00020000&(data))>>17)
#define  CRT_SYS_PLL_DISP3_get_dpll_bpphs(data)                                  ((0x00010000&(data))>>16)
#define  CRT_SYS_PLL_DISP3_get_dpll_bpn(data)                                    ((0x00004000&(data))>>14)
#define  CRT_SYS_PLL_DISP3_get_dpll_o(data)                                      ((0x00003000&(data))>>12)
#define  CRT_SYS_PLL_DISP3_get_dpll_rstb(data)                                   ((0x00000040&(data))>>6)
#define  CRT_SYS_PLL_DISP3_get_dpll_wdrst(data)                                  ((0x00000020&(data))>>5)
#define  CRT_SYS_PLL_DISP3_get_dpll_wdset(data)                                  ((0x00000010&(data))>>4)
#define  CRT_SYS_PLL_DISP3_get_dpll_freeze(data)                                 ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DISP3_get_dpll_vcorstb(data)                                ((0x00000002&(data))>>1)
#define  CRT_SYS_PLL_DISP3_get_dpll_pow(data)                                    (0x00000001&(data))

#define  CRT_SYS_PLL_DISP4                                                       0x180006CC
#define  CRT_SYS_PLL_DISP4_reg_addr                                              "0xB80006CC"
#define  CRT_SYS_PLL_DISP4_reg                                                   0xB80006CC
#define  CRT_SYS_PLL_DISP4_inst_addr                                             "0x00C8"
#define  set_CRT_SYS_PLL_DISP4_reg(data)                                         (*((volatile unsigned int*)CRT_SYS_PLL_DISP4_reg)=data)
#define  get_CRT_SYS_PLL_DISP4_reg                                               (*((volatile unsigned int*)CRT_SYS_PLL_DISP4_reg))
#define  CRT_SYS_PLL_DISP4_dpll_ldodpll_pow_shift                                (2)
#define  CRT_SYS_PLL_DISP4_dpll_pi_ibsel_shift                                   (0)
#define  CRT_SYS_PLL_DISP4_dpll_ldodpll_pow_mask                                 (0x00000004)
#define  CRT_SYS_PLL_DISP4_dpll_pi_ibsel_mask                                    (0x00000003)
#define  CRT_SYS_PLL_DISP4_dpll_ldodpll_pow(data)                                (0x00000004&((data)<<2))
#define  CRT_SYS_PLL_DISP4_dpll_pi_ibsel(data)                                   (0x00000003&(data))
#define  CRT_SYS_PLL_DISP4_get_dpll_ldodpll_pow(data)                            ((0x00000004&(data))>>2)
#define  CRT_SYS_PLL_DISP4_get_dpll_pi_ibsel(data)                               (0x00000003&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0                                       0x180006D0
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_reg_addr                              "0xB80006D0"
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_reg                                   0xB80006D0
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_inst_addr                             "0x00C9"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_debug0_reg(data)                         (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug0_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_debug0_reg                               (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug0_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_flag_shift           (31)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_th_value_shift       (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_flag_mask            (0x80000000)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_th_value_mask        (0x0001FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_flag(data)           (0x80000000&((data)<<31))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_sscg_offset_over_th_value(data)       (0x0001FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_get_sscg_offset_over_flag(data)       ((0x80000000&(data))>>31)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug0_get_sscg_offset_over_th_value(data)   (0x0001FFFF&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1                                       0x180006D4
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_reg_addr                              "0xB80006D4"
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_reg                                   0xB80006D4
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_inst_addr                             "0x00CA"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_debug1_reg(data)                         (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug1_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_debug1_reg                               (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug1_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_sscg_offset_over_th_max_shift         (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_sscg_offset_over_th_max_mask          (0x0001FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_sscg_offset_over_th_max(data)         (0x0001FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug1_get_sscg_offset_over_th_max(data)     (0x0001FFFF&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2                                       0x180006D8
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_reg_addr                              "0xB80006D8"
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_reg                                   0xB80006D8
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_inst_addr                             "0x00CB"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_debug2_reg(data)                         (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug2_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_debug2_reg                               (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug2_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_flag_shift        (31)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_th_value_shift    (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_flag_mask         (0x80000000)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_th_value_mask     (0x0001FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_flag(data)        (0x80000000&((data)<<31))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_new_fll_offset_over_th_value(data)    (0x0001FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_get_new_fll_offset_over_flag(data)    ((0x80000000&(data))>>31)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug2_get_new_fll_offset_over_th_value(data) (0x0001FFFF&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3                                       0x180006DC
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_reg_addr                              "0xB80006DC"
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_reg                                   0xB80006DC
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_inst_addr                             "0x00CC"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_debug3_reg(data)                         (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug3_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_debug3_reg                               (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_debug3_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_new_fll_offset_over_th_max_shift      (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_new_fll_offset_over_th_max_mask       (0x0001FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_new_fll_offset_over_th_max(data)      (0x0001FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_debug3_get_new_fll_offset_over_th_max(data)  (0x0001FFFF&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4                                        0x180006E0
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_reg_addr                               "0xB80006E0"
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_reg                                    0xB80006E0
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_inst_addr                              "0x00CD"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_reg(data)                          (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_reg                                (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse_shift  (20)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul_shift             (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse_mask   (0x00100000)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul_mask              (0x0007FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_offset_inverse(data)  (0x00100000&((data)<<20))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_new_fll_tracking_mul(data)             (0x0007FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_get_new_fll_tracking_offset_inverse(data) ((0x00100000&(data))>>20)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL4_get_new_fll_tracking_mul(data)         (0x0007FFFF&(data))

#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5                                        0x180006E4
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_reg_addr                               "0xB80006E4"
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_reg                                    0xB80006E4
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_inst_addr                              "0x00CE"
#define  set_CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_reg(data)                          (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_reg)=data)
#define  get_CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_reg                                (*((volatile unsigned int*)CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_reg))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th_shift          (16)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th_shift          (0)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th_mask           (0xFFFF0000)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th_mask           (0x0000FFFF)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_neg_th(data)          (0xFFFF0000&((data)<<16))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_new_fll_tracking_pos_th(data)          (0x0000FFFF&(data))
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_get_new_fll_tracking_neg_th(data)      ((0xFFFF0000&(data))>>16)
#define  CRT_DPLL_IN_FSYNC_TRACKING_CTRL5_get_new_fll_tracking_pos_th(data)      (0x0000FFFF&(data))

#define  CRT_EMMC_PLL_SET                                                        0x18000700
#define  CRT_EMMC_PLL_SET_reg_addr                                               "0xB8000700"
#define  CRT_EMMC_PLL_SET_reg                                                    0xB8000700
#define  CRT_EMMC_PLL_SET_inst_addr                                              "0x00CF"
#define  set_CRT_EMMC_PLL_SET_reg(data)                                          (*((volatile unsigned int*)CRT_EMMC_PLL_SET_reg)=data)
#define  get_CRT_EMMC_PLL_SET_reg                                                (*((volatile unsigned int*)CRT_EMMC_PLL_SET_reg))
#define  CRT_EMMC_PLL_SET_pll_emmc_ckssc_inv_shift                               (30)
#define  CRT_EMMC_PLL_SET_pllscp_shift                                           (29)
#define  CRT_EMMC_PLL_SET_pllscs_shift                                           (27)
#define  CRT_EMMC_PLL_SET_pllsrs_shift                                           (24)
#define  CRT_EMMC_PLL_SET_pllsdiv2_shift                                         (17)
#define  CRT_EMMC_PLL_SET_pllssi_shift                                           (12)
#define  CRT_EMMC_PLL_SET_pllsnbp_shift                                          (11)
#define  CRT_EMMC_PLL_SET_pllsn_shift                                            (8)
#define  CRT_EMMC_PLL_SET_pllallrstb_shift                                       (0)
#define  CRT_EMMC_PLL_SET_pll_emmc_ckssc_inv_mask                                (0x40000000)
#define  CRT_EMMC_PLL_SET_pllscp_mask                                            (0x20000000)
#define  CRT_EMMC_PLL_SET_pllscs_mask                                            (0x18000000)
#define  CRT_EMMC_PLL_SET_pllsrs_mask                                            (0x07000000)
#define  CRT_EMMC_PLL_SET_pllsdiv2_mask                                          (0x00020000)
#define  CRT_EMMC_PLL_SET_pllssi_mask                                            (0x0001F000)
#define  CRT_EMMC_PLL_SET_pllsnbp_mask                                           (0x00000800)
#define  CRT_EMMC_PLL_SET_pllsn_mask                                             (0x00000700)
#define  CRT_EMMC_PLL_SET_pllallrstb_mask                                        (0x00000001)
#define  CRT_EMMC_PLL_SET_pll_emmc_ckssc_inv(data)                               (0x40000000&((data)<<30))
#define  CRT_EMMC_PLL_SET_pllscp(data)                                           (0x20000000&((data)<<29))
#define  CRT_EMMC_PLL_SET_pllscs(data)                                           (0x18000000&((data)<<27))
#define  CRT_EMMC_PLL_SET_pllsrs(data)                                           (0x07000000&((data)<<24))
#define  CRT_EMMC_PLL_SET_pllsdiv2(data)                                         (0x00020000&((data)<<17))
#define  CRT_EMMC_PLL_SET_pllssi(data)                                           (0x0001F000&((data)<<12))
#define  CRT_EMMC_PLL_SET_pllsnbp(data)                                          (0x00000800&((data)<<11))
#define  CRT_EMMC_PLL_SET_pllsn(data)                                            (0x00000700&((data)<<8))
#define  CRT_EMMC_PLL_SET_pllallrstb(data)                                       (0x00000001&(data))
#define  CRT_EMMC_PLL_SET_get_pll_emmc_ckssc_inv(data)                           ((0x40000000&(data))>>30)
#define  CRT_EMMC_PLL_SET_get_pllscp(data)                                       ((0x20000000&(data))>>29)
#define  CRT_EMMC_PLL_SET_get_pllscs(data)                                       ((0x18000000&(data))>>27)
#define  CRT_EMMC_PLL_SET_get_pllsrs(data)                                       ((0x07000000&(data))>>24)
#define  CRT_EMMC_PLL_SET_get_pllsdiv2(data)                                     ((0x00020000&(data))>>17)
#define  CRT_EMMC_PLL_SET_get_pllssi(data)                                       ((0x0001F000&(data))>>12)
#define  CRT_EMMC_PLL_SET_get_pllsnbp(data)                                      ((0x00000800&(data))>>11)
#define  CRT_EMMC_PLL_SET_get_pllsn(data)                                        ((0x00000700&(data))>>8)
#define  CRT_EMMC_PLL_SET_get_pllallrstb(data)                                   (0x00000001&(data))

#define  CRT_EMMC_PLL_CTRL                                                       0x18000704
#define  CRT_EMMC_PLL_CTRL_reg_addr                                              "0xB8000704"
#define  CRT_EMMC_PLL_CTRL_reg                                                   0xB8000704
#define  CRT_EMMC_PLL_CTRL_inst_addr                                             "0x00D0"
#define  set_CRT_EMMC_PLL_CTRL_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_CTRL_reg)=data)
#define  get_CRT_EMMC_PLL_CTRL_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_CTRL_reg))
#define  CRT_EMMC_PLL_CTRL_reg_pll_tp2_mux_shift                                 (20)
#define  CRT_EMMC_PLL_CTRL_reg_pll_tp1_mux_shift                                 (17)
#define  CRT_EMMC_PLL_CTRL_pllemmc_rsvd_shift                                    (8)
#define  CRT_EMMC_PLL_CTRL_pllsstatus_shift                                      (6)
#define  CRT_EMMC_PLL_CTRL_pllswdrst_shift                                       (5)
#define  CRT_EMMC_PLL_CTRL_pllswdset_shift                                       (4)
#define  CRT_EMMC_PLL_CTRL_pllemmc_reg_shift                                     (2)
#define  CRT_EMMC_PLL_CTRL_pllemmcldopow_shift                                   (1)
#define  CRT_EMMC_PLL_CTRL_pllemmcpwdn_shift                                     (0)
#define  CRT_EMMC_PLL_CTRL_reg_pll_tp2_mux_mask                                  (0x00700000)
#define  CRT_EMMC_PLL_CTRL_reg_pll_tp1_mux_mask                                  (0x000E0000)
#define  CRT_EMMC_PLL_CTRL_pllemmc_rsvd_mask                                     (0x0000FF00)
#define  CRT_EMMC_PLL_CTRL_pllsstatus_mask                                       (0x00000040)
#define  CRT_EMMC_PLL_CTRL_pllswdrst_mask                                        (0x00000020)
#define  CRT_EMMC_PLL_CTRL_pllswdset_mask                                        (0x00000010)
#define  CRT_EMMC_PLL_CTRL_pllemmc_reg_mask                                      (0x0000000C)
#define  CRT_EMMC_PLL_CTRL_pllemmcldopow_mask                                    (0x00000002)
#define  CRT_EMMC_PLL_CTRL_pllemmcpwdn_mask                                      (0x00000001)
#define  CRT_EMMC_PLL_CTRL_reg_pll_tp2_mux(data)                                 (0x00700000&((data)<<20))
#define  CRT_EMMC_PLL_CTRL_reg_pll_tp1_mux(data)                                 (0x000E0000&((data)<<17))
#define  CRT_EMMC_PLL_CTRL_pllemmc_rsvd(data)                                    (0x0000FF00&((data)<<8))
#define  CRT_EMMC_PLL_CTRL_pllsstatus(data)                                      (0x00000040&((data)<<6))
#define  CRT_EMMC_PLL_CTRL_pllswdrst(data)                                       (0x00000020&((data)<<5))
#define  CRT_EMMC_PLL_CTRL_pllswdset(data)                                       (0x00000010&((data)<<4))
#define  CRT_EMMC_PLL_CTRL_pllemmc_reg(data)                                     (0x0000000C&((data)<<2))
#define  CRT_EMMC_PLL_CTRL_pllemmcldopow(data)                                   (0x00000002&((data)<<1))
#define  CRT_EMMC_PLL_CTRL_pllemmcpwdn(data)                                     (0x00000001&(data))
#define  CRT_EMMC_PLL_CTRL_get_reg_pll_tp2_mux(data)                             ((0x00700000&(data))>>20)
#define  CRT_EMMC_PLL_CTRL_get_reg_pll_tp1_mux(data)                             ((0x000E0000&(data))>>17)
#define  CRT_EMMC_PLL_CTRL_get_pllemmc_rsvd(data)                                ((0x0000FF00&(data))>>8)
#define  CRT_EMMC_PLL_CTRL_get_pllsstatus(data)                                  ((0x00000040&(data))>>6)
#define  CRT_EMMC_PLL_CTRL_get_pllswdrst(data)                                   ((0x00000020&(data))>>5)
#define  CRT_EMMC_PLL_CTRL_get_pllswdset(data)                                   ((0x00000010&(data))>>4)
#define  CRT_EMMC_PLL_CTRL_get_pllemmc_reg(data)                                 ((0x0000000C&(data))>>2)
#define  CRT_EMMC_PLL_CTRL_get_pllemmcldopow(data)                               ((0x00000002&(data))>>1)
#define  CRT_EMMC_PLL_CTRL_get_pllemmcpwdn(data)                                 (0x00000001&(data))

#define  CRT_EMMC_PLLPHASE_CTRL                                                  0x18000708
#define  CRT_EMMC_PLLPHASE_CTRL_reg_addr                                         "0xB8000708"
#define  CRT_EMMC_PLLPHASE_CTRL_reg                                              0xB8000708
#define  CRT_EMMC_PLLPHASE_CTRL_inst_addr                                        "0x00D1"
#define  set_CRT_EMMC_PLLPHASE_CTRL_reg(data)                                    (*((volatile unsigned int*)CRT_EMMC_PLLPHASE_CTRL_reg)=data)
#define  get_CRT_EMMC_PLLPHASE_CTRL_reg                                          (*((volatile unsigned int*)CRT_EMMC_PLLPHASE_CTRL_reg))
#define  CRT_EMMC_PLLPHASE_CTRL_pll_pi_autoset_shift                             (30)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_3_shift                                  (29)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_3_shift                                  (28)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_3_shift                                    (27)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_3_shift                                    (26)
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_3_shift                                  (20)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_2_shift                                  (19)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_2_shift                                  (18)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_2_shift                                    (17)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_2_shift                                    (16)
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_2_shift                                  (10)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_shift                                    (9)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_shift                                    (8)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_shift                                      (7)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_shift                                      (6)
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_shift                                    (0)
#define  CRT_EMMC_PLLPHASE_CTRL_pll_pi_autoset_mask                              (0x40000000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_3_mask                                   (0x20000000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_3_mask                                   (0x10000000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_3_mask                                     (0x08000000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_3_mask                                     (0x04000000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_3_mask                                   (0x03F00000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_2_mask                                   (0x00080000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_2_mask                                   (0x00040000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_2_mask                                     (0x00020000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_2_mask                                     (0x00010000)
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_2_mask                                   (0x0000FC00)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_mask                                     (0x00000200)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_mask                                     (0x00000100)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_mask                                       (0x00000080)
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_mask                                       (0x00000040)
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_mask                                     (0x0000003F)
#define  CRT_EMMC_PLLPHASE_CTRL_pll_pi_autoset(data)                             (0x40000000&((data)<<30))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_3(data)                                  (0x20000000&((data)<<29))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_3(data)                                  (0x10000000&((data)<<28))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_3(data)                                    (0x08000000&((data)<<27))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_3(data)                                    (0x04000000&((data)<<26))
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_3(data)                                  (0x03F00000&((data)<<20))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x_2(data)                                  (0x00080000&((data)<<19))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y_2(data)                                  (0x00040000&((data)<<18))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx_2(data)                                    (0x00020000&((data)<<17))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy_2(data)                                    (0x00010000&((data)<<16))
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck_2(data)                                  (0x0000FC00&((data)<<10))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2x(data)                                    (0x00000200&((data)<<9))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsd2y(data)                                    (0x00000100&((data)<<8))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsx(data)                                      (0x00000080&((data)<<7))
#define  CRT_EMMC_PLLPHASE_CTRL_pllsy(data)                                      (0x00000040&((data)<<6))
#define  CRT_EMMC_PLLPHASE_CTRL_pllssck(data)                                    (0x0000003F&(data))
#define  CRT_EMMC_PLLPHASE_CTRL_get_pll_pi_autoset(data)                         ((0x40000000&(data))>>30)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsd2x_3(data)                              ((0x20000000&(data))>>29)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsd2y_3(data)                              ((0x10000000&(data))>>28)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsx_3(data)                                ((0x08000000&(data))>>27)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsy_3(data)                                ((0x04000000&(data))>>26)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllssck_3(data)                              ((0x03F00000&(data))>>20)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsd2x_2(data)                              ((0x00080000&(data))>>19)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsd2y_2(data)                              ((0x00040000&(data))>>18)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsx_2(data)                                ((0x00020000&(data))>>17)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsy_2(data)                                ((0x00010000&(data))>>16)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllssck_2(data)                              ((0x0000FC00&(data))>>10)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsd2x(data)                                ((0x00000200&(data))>>9)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsd2y(data)                                ((0x00000100&(data))>>8)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsx(data)                                  ((0x00000080&(data))>>7)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllsy(data)                                  ((0x00000040&(data))>>6)
#define  CRT_EMMC_PLLPHASE_CTRL_get_pllssck(data)                                (0x0000003F&(data))

#define  CRT_EMMC_PLL_PHASE_INTERPOLATION                                        0x1800070C
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_reg_addr                               "0xB800070C"
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_reg                                    0xB800070C
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_inst_addr                              "0x00D2"
#define  set_CRT_EMMC_PLL_PHASE_INTERPOLATION_reg(data)                          (*((volatile unsigned int*)CRT_EMMC_PLL_PHASE_INTERPOLATION_reg)=data)
#define  get_CRT_EMMC_PLL_PHASE_INTERPOLATION_reg                                (*((volatile unsigned int*)CRT_EMMC_PLL_PHASE_INTERPOLATION_reg))
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_pllsphrl_shift                         (4)
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_pllsphrs_shift                         (0)
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_pllsphrl_mask                          (0x00000030)
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_pllsphrs_mask                          (0x00000007)
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_pllsphrl(data)                         (0x00000030&((data)<<4))
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_pllsphrs(data)                         (0x00000007&(data))
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_get_pllsphrl(data)                     ((0x00000030&(data))>>4)
#define  CRT_EMMC_PLL_PHASE_INTERPOLATION_get_pllsphrs(data)                     (0x00000007&(data))

#define  CRT_EMMC_PLL_SSC0                                                       0x18000710
#define  CRT_EMMC_PLL_SSC0_reg_addr                                              "0xB8000710"
#define  CRT_EMMC_PLL_SSC0_reg                                                   0xB8000710
#define  CRT_EMMC_PLL_SSC0_inst_addr                                             "0x00D3"
#define  set_CRT_EMMC_PLL_SSC0_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC0_reg)=data)
#define  get_CRT_EMMC_PLL_SSC0_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC0_reg))
#define  CRT_EMMC_PLL_SSC0_pllemmc_oc_step_set_shift                             (4)
#define  CRT_EMMC_PLL_SSC0_pllemmc_oc_en_shift                                   (0)
#define  CRT_EMMC_PLL_SSC0_pllemmc_oc_step_set_mask                              (0x00003FF0)
#define  CRT_EMMC_PLL_SSC0_pllemmc_oc_en_mask                                    (0x00000001)
#define  CRT_EMMC_PLL_SSC0_pllemmc_oc_step_set(data)                             (0x00003FF0&((data)<<4))
#define  CRT_EMMC_PLL_SSC0_pllemmc_oc_en(data)                                   (0x00000001&(data))
#define  CRT_EMMC_PLL_SSC0_get_pllemmc_oc_step_set(data)                         ((0x00003FF0&(data))>>4)
#define  CRT_EMMC_PLL_SSC0_get_pllemmc_oc_en(data)                               (0x00000001&(data))

#define  CRT_EMMC_PLL_SSC1                                                       0x18000714
#define  CRT_EMMC_PLL_SSC1_reg_addr                                              "0xB8000714"
#define  CRT_EMMC_PLL_SSC1_reg                                                   0xB8000714
#define  CRT_EMMC_PLL_SSC1_inst_addr                                             "0x00D4"
#define  set_CRT_EMMC_PLL_SSC1_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC1_reg)=data)
#define  get_CRT_EMMC_PLL_SSC1_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC1_reg))
#define  CRT_EMMC_PLL_SSC1_pllemmc_oc_done_delay_shift                           (16)
#define  CRT_EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff_shift                         (12)
#define  CRT_EMMC_PLL_SSC1_pllemmc_pi_cur_sel_shift                              (10)
#define  CRT_EMMC_PLL_SSC1_pllemmc_sel_oc_mode_shift                             (8)
#define  CRT_EMMC_PLL_SSC1_pllemmc_oc_done_delay_mask                            (0x003F0000)
#define  CRT_EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff_mask                          (0x00003000)
#define  CRT_EMMC_PLL_SSC1_pllemmc_pi_cur_sel_mask                               (0x00000C00)
#define  CRT_EMMC_PLL_SSC1_pllemmc_sel_oc_mode_mask                              (0x00000300)
#define  CRT_EMMC_PLL_SSC1_pllemmc_oc_done_delay(data)                           (0x003F0000&((data)<<16))
#define  CRT_EMMC_PLL_SSC1_pllemmc_hs_oc_stop_diff(data)                         (0x00003000&((data)<<12))
#define  CRT_EMMC_PLL_SSC1_pllemmc_pi_cur_sel(data)                              (0x00000C00&((data)<<10))
#define  CRT_EMMC_PLL_SSC1_pllemmc_sel_oc_mode(data)                             (0x00000300&((data)<<8))
#define  CRT_EMMC_PLL_SSC1_get_pllemmc_oc_done_delay(data)                       ((0x003F0000&(data))>>16)
#define  CRT_EMMC_PLL_SSC1_get_pllemmc_hs_oc_stop_diff(data)                     ((0x00003000&(data))>>12)
#define  CRT_EMMC_PLL_SSC1_get_pllemmc_pi_cur_sel(data)                          ((0x00000C00&(data))>>10)
#define  CRT_EMMC_PLL_SSC1_get_pllemmc_sel_oc_mode(data)                         ((0x00000300&(data))>>8)

#define  CRT_EMMC_PLL_SSC2                                                       0x18000718
#define  CRT_EMMC_PLL_SSC2_reg_addr                                              "0xB8000718"
#define  CRT_EMMC_PLL_SSC2_reg                                                   0xB8000718
#define  CRT_EMMC_PLL_SSC2_inst_addr                                             "0x00D5"
#define  set_CRT_EMMC_PLL_SSC2_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC2_reg)=data)
#define  get_CRT_EMMC_PLL_SSC2_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC2_reg))
#define  CRT_EMMC_PLL_SSC2_pllemmc_en_pi_debug_shift                             (2)
#define  CRT_EMMC_PLL_SSC2_pllemmc_sdm_order_shift                               (1)
#define  CRT_EMMC_PLL_SSC2_pllemmc_bypass_pi_shift                               (0)
#define  CRT_EMMC_PLL_SSC2_pllemmc_en_pi_debug_mask                              (0x00000004)
#define  CRT_EMMC_PLL_SSC2_pllemmc_sdm_order_mask                                (0x00000002)
#define  CRT_EMMC_PLL_SSC2_pllemmc_bypass_pi_mask                                (0x00000001)
#define  CRT_EMMC_PLL_SSC2_pllemmc_en_pi_debug(data)                             (0x00000004&((data)<<2))
#define  CRT_EMMC_PLL_SSC2_pllemmc_sdm_order(data)                               (0x00000002&((data)<<1))
#define  CRT_EMMC_PLL_SSC2_pllemmc_bypass_pi(data)                               (0x00000001&(data))
#define  CRT_EMMC_PLL_SSC2_get_pllemmc_en_pi_debug(data)                         ((0x00000004&(data))>>2)
#define  CRT_EMMC_PLL_SSC2_get_pllemmc_sdm_order(data)                           ((0x00000002&(data))>>1)
#define  CRT_EMMC_PLL_SSC2_get_pllemmc_bypass_pi(data)                           (0x00000001&(data))

#define  CRT_EMMC_PLL_SSC3                                                       0x1800071C
#define  CRT_EMMC_PLL_SSC3_reg_addr                                              "0xB800071C"
#define  CRT_EMMC_PLL_SSC3_reg                                                   0xB800071C
#define  CRT_EMMC_PLL_SSC3_inst_addr                                             "0x00D6"
#define  set_CRT_EMMC_PLL_SSC3_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC3_reg)=data)
#define  get_CRT_EMMC_PLL_SSC3_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC3_reg))
#define  CRT_EMMC_PLL_SSC3_pllemmc_ncode_ssc_shift                               (16)
#define  CRT_EMMC_PLL_SSC3_pllemmc_fcode_ssc_shift                               (0)
#define  CRT_EMMC_PLL_SSC3_pllemmc_ncode_ssc_mask                                (0x00FF0000)
#define  CRT_EMMC_PLL_SSC3_pllemmc_fcode_ssc_mask                                (0x000007FF)
#define  CRT_EMMC_PLL_SSC3_pllemmc_ncode_ssc(data)                               (0x00FF0000&((data)<<16))
#define  CRT_EMMC_PLL_SSC3_pllemmc_fcode_ssc(data)                               (0x000007FF&(data))
#define  CRT_EMMC_PLL_SSC3_get_pllemmc_ncode_ssc(data)                           ((0x00FF0000&(data))>>16)
#define  CRT_EMMC_PLL_SSC3_get_pllemmc_fcode_ssc(data)                           (0x000007FF&(data))

#define  CRT_EMMC_PLL_SSC4                                                       0x18000720
#define  CRT_EMMC_PLL_SSC4_reg_addr                                              "0xB8000720"
#define  CRT_EMMC_PLL_SSC4_reg                                                   0xB8000720
#define  CRT_EMMC_PLL_SSC4_inst_addr                                             "0x00D7"
#define  set_CRT_EMMC_PLL_SSC4_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC4_reg)=data)
#define  get_CRT_EMMC_PLL_SSC4_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC4_reg))
#define  CRT_EMMC_PLL_SSC4_pllemmc_ncode_t_shift                                 (16)
#define  CRT_EMMC_PLL_SSC4_pllemmc_fcode_t_shift                                 (0)
#define  CRT_EMMC_PLL_SSC4_pllemmc_ncode_t_mask                                  (0x00FF0000)
#define  CRT_EMMC_PLL_SSC4_pllemmc_fcode_t_mask                                  (0x000007FF)
#define  CRT_EMMC_PLL_SSC4_pllemmc_ncode_t(data)                                 (0x00FF0000&((data)<<16))
#define  CRT_EMMC_PLL_SSC4_pllemmc_fcode_t(data)                                 (0x000007FF&(data))
#define  CRT_EMMC_PLL_SSC4_get_pllemmc_ncode_t(data)                             ((0x00FF0000&(data))>>16)
#define  CRT_EMMC_PLL_SSC4_get_pllemmc_fcode_t(data)                             (0x000007FF&(data))

#define  CRT_EMMC_PLL_SSC5                                                       0x18000724
#define  CRT_EMMC_PLL_SSC5_reg_addr                                              "0xB8000724"
#define  CRT_EMMC_PLL_SSC5_reg                                                   0xB8000724
#define  CRT_EMMC_PLL_SSC5_inst_addr                                             "0x00D8"
#define  set_CRT_EMMC_PLL_SSC5_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC5_reg)=data)
#define  get_CRT_EMMC_PLL_SSC5_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC5_reg))
#define  CRT_EMMC_PLL_SSC5_pllemmc_gran_auto_rst_shift                           (28)
#define  CRT_EMMC_PLL_SSC5_pllemmc_dot_gran_shift                                (24)
#define  CRT_EMMC_PLL_SSC5_pllemmc_gran_est_shift                                (4)
#define  CRT_EMMC_PLL_SSC5_pllemmc_en_ssc_shift                                  (0)
#define  CRT_EMMC_PLL_SSC5_pllemmc_gran_auto_rst_mask                            (0x10000000)
#define  CRT_EMMC_PLL_SSC5_pllemmc_dot_gran_mask                                 (0x07000000)
#define  CRT_EMMC_PLL_SSC5_pllemmc_gran_est_mask                                 (0x007FFFF0)
#define  CRT_EMMC_PLL_SSC5_pllemmc_en_ssc_mask                                   (0x00000001)
#define  CRT_EMMC_PLL_SSC5_pllemmc_gran_auto_rst(data)                           (0x10000000&((data)<<28))
#define  CRT_EMMC_PLL_SSC5_pllemmc_dot_gran(data)                                (0x07000000&((data)<<24))
#define  CRT_EMMC_PLL_SSC5_pllemmc_gran_est(data)                                (0x007FFFF0&((data)<<4))
#define  CRT_EMMC_PLL_SSC5_pllemmc_en_ssc(data)                                  (0x00000001&(data))
#define  CRT_EMMC_PLL_SSC5_get_pllemmc_gran_auto_rst(data)                       ((0x10000000&(data))>>28)
#define  CRT_EMMC_PLL_SSC5_get_pllemmc_dot_gran(data)                            ((0x07000000&(data))>>24)
#define  CRT_EMMC_PLL_SSC5_get_pllemmc_gran_est(data)                            ((0x007FFFF0&(data))>>4)
#define  CRT_EMMC_PLL_SSC5_get_pllemmc_en_ssc(data)                              (0x00000001&(data))

#define  CRT_EMMC_PLL_SSC6                                                       0x18000728
#define  CRT_EMMC_PLL_SSC6_reg_addr                                              "0xB8000728"
#define  CRT_EMMC_PLL_SSC6_reg                                                   0xB8000728
#define  CRT_EMMC_PLL_SSC6_inst_addr                                             "0x00D9"
#define  set_CRT_EMMC_PLL_SSC6_reg(data)                                         (*((volatile unsigned int*)CRT_EMMC_PLL_SSC6_reg)=data)
#define  get_CRT_EMMC_PLL_SSC6_reg                                               (*((volatile unsigned int*)CRT_EMMC_PLL_SSC6_reg))
#define  CRT_EMMC_PLL_SSC6_pllemmc_fcode_debug_shift                             (16)
#define  CRT_EMMC_PLL_SSC6_pllemmc_ncode_debug_shift                             (8)
#define  CRT_EMMC_PLL_SSC6_pllemmc_oc_done_shift                                 (4)
#define  CRT_EMMC_PLL_SSC6_pllemmc_fmod_shift                                    (0)
#define  CRT_EMMC_PLL_SSC6_pllemmc_fcode_debug_mask                              (0x07FF0000)
#define  CRT_EMMC_PLL_SSC6_pllemmc_ncode_debug_mask                              (0x0000FF00)
#define  CRT_EMMC_PLL_SSC6_pllemmc_oc_done_mask                                  (0x00000010)
#define  CRT_EMMC_PLL_SSC6_pllemmc_fmod_mask                                     (0x00000001)
#define  CRT_EMMC_PLL_SSC6_pllemmc_fcode_debug(data)                             (0x07FF0000&((data)<<16))
#define  CRT_EMMC_PLL_SSC6_pllemmc_ncode_debug(data)                             (0x0000FF00&((data)<<8))
#define  CRT_EMMC_PLL_SSC6_pllemmc_oc_done(data)                                 (0x00000010&((data)<<4))
#define  CRT_EMMC_PLL_SSC6_pllemmc_fmod(data)                                    (0x00000001&(data))
#define  CRT_EMMC_PLL_SSC6_get_pllemmc_fcode_debug(data)                         ((0x07FF0000&(data))>>16)
#define  CRT_EMMC_PLL_SSC6_get_pllemmc_ncode_debug(data)                         ((0x0000FF00&(data))>>8)
#define  CRT_EMMC_PLL_SSC6_get_pllemmc_oc_done(data)                             ((0x00000010&(data))>>4)
#define  CRT_EMMC_PLL_SSC6_get_pllemmc_fmod(data)                                (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======CRT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_ib_sb1:1;
        RBus_UInt32  rstn_ib_sb2:1;
        RBus_UInt32  rstn_ib_sb3:1;
        RBus_UInt32  rstn_ib_ve:1;
        RBus_UInt32  rstn_ib_ve2:1;
        RBus_UInt32  rstn_ib_vp9:1;
        RBus_UInt32  rstn_ib_tvsb1:1;
        RBus_UInt32  rstn_nd:1;
        RBus_UInt32  rstn_akl:1;
        RBus_UInt32  rstn_dsc:1;
        RBus_UInt32  rstn_sce:1;
        RBus_UInt32  rstn_kt:1;
        RBus_UInt32  rstn_ib_gpu:1;
        RBus_UInt32  rstn_kcpu:1;
        RBus_UInt32  rstn_vde2:1;
        RBus_UInt32  rstn_ve2_p2:1;
        RBus_UInt32  rstn_ve2:1;
        RBus_UInt32  rstn_vcpu2:1;
        RBus_UInt32  rstn_vp9:1;
        RBus_UInt32  rstn_acpu:1;
        RBus_UInt32  rstn_ib_tvsb2:1;
        RBus_UInt32  rstn_ib_tvsb3:1;
        RBus_UInt32  rstn_ib_tvsb4:1;
        RBus_UInt32  rstn_ib_tvsb5:1;
        RBus_UInt32  rstn_scpu_wrap:1;
        RBus_UInt32  rstn_vde:1;
        RBus_UInt32  rstn_ve_p2:1;
        RBus_UInt32  rstn_ve:1;
        RBus_UInt32  rstn_vcpu:1;
        RBus_UInt32  rstn_ae:1;
        RBus_UInt32  rstn_scpu:1;
        RBus_UInt32  rstn_pllreg:1;
    };
}crt_sys_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_tvsb1:1;
        RBus_UInt32  rstn_tvsb2:1;
        RBus_UInt32  rstn_tvsb3:1;
        RBus_UInt32  rstn_tvsb4:1;
        RBus_UInt32  rstn_tvsb5:1;
        RBus_UInt32  rstn_tve:1;
        RBus_UInt32  rstn_dcphy:1;
        RBus_UInt32  rstn_dcu:1;
        RBus_UInt32  rstn_if_demod:1;
        RBus_UInt32  rstn_vdec:1;
        RBus_UInt32  rstn_vdec2:1;
        RBus_UInt32  rstn_vbis0:1;
        RBus_UInt32  rstn_audio2_dac:1;
        RBus_UInt32  rstn_audio_adc:1;
        RBus_UInt32  rstn_audio_dac:1;
        RBus_UInt32  rstn_audio:1;
        RBus_UInt32  rstn_ifadc:1;
        RBus_UInt32  rstn_cbus:1;
        RBus_UInt32  rstn_offms:1;
        RBus_UInt32  rstn_me:1;
        RBus_UInt32  rstn_apll_adc:1;
        RBus_UInt32  rstn_hdmi:1;
        RBus_UInt32  rstn_hdmitx:1;
        RBus_UInt32  rstn_tp:1;
        RBus_UInt32  rstn_cp:1;
        RBus_UInt32  rstn_md:1;
        RBus_UInt32  rstn_se:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_3d_gde:1;
        RBus_UInt32  rstn_vodma:1;
        RBus_UInt32  rstn_dispim:1;
        RBus_UInt32  rstn_disp:1;
    };
}crt_sys_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  rstn_tm:1;
        RBus_UInt32  rstn_atvin2:1;
        RBus_UInt32  rstn_atvin:1;
        RBus_UInt32  dummy18000108_25_24:2;
        RBus_UInt32  rstn_emmc:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rstn_bistreg:1;
        RBus_UInt32  dummy18000108_20_19:2;
        RBus_UInt32  rstn_usb:1;
        RBus_UInt32  rstn_otg:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  dummy18000108_15_14:2;
        RBus_UInt32  rstn_irtx:1;
        RBus_UInt32  rstn_padmux:1;
        RBus_UInt32  rstn_dtv_demod:1;
        RBus_UInt32  rstn_misc:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_uart1:1;
        RBus_UInt32  rstn_uart2:1;
        RBus_UInt32  rstn_sc1:1;
        RBus_UInt32  rstn_gpio:1;
        RBus_UInt32  rstn_i2c1:1;
        RBus_UInt32  rstn_i2c2:1;
        RBus_UInt32  rstn_nf:1;
        RBus_UInt32  rstn_sc:1;
        RBus_UInt32  rstn_pc:1;
    };
}crt_sys_srst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rstn_dcphy2:1;
        RBus_UInt32  rstn_dcu2:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_sd:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rstn_hdmitx_pll:1;
        RBus_UInt32  res4:4;
        RBus_UInt32  rstn_usb2_phy_p3:1;
        RBus_UInt32  rstn_usb2_phy_p2:1;
        RBus_UInt32  rstn_usb2_phy_p1:1;
        RBus_UInt32  rstn_usb2_phy_p0:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  rstn_usb3_mdio_p0:1;
        RBus_UInt32  rstn_usb3_phy_p0:1;
    };
}crt_sys_srst3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  clken_akl:1;
        RBus_UInt32  clken_dsc:1;
        RBus_UInt32  clken_sce:1;
        RBus_UInt32  clken_kt:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  clken_kcpu:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  clken_ve2_p2:1;
        RBus_UInt32  clken_ve2:1;
        RBus_UInt32  clken_vcpu2:1;
        RBus_UInt32  clken_vp9:1;
        RBus_UInt32  clken_acpu:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:3;
        RBus_UInt32  res13:1;
        RBus_UInt32  clken_ve_p2:1;
        RBus_UInt32  clken_ve:1;
        RBus_UInt32  clken_vcpu:1;
        RBus_UInt32  clken_scpu_wrap:1;
        RBus_UInt32  clken_scpu:1;
        RBus_UInt32  clken_pllreg:1;
    };
}crt_sys_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_tvsb1:1;
        RBus_UInt32  clken_tvsb2:1;
        RBus_UInt32  clken_tvsb3:1;
        RBus_UInt32  clken_tvsb4:1;
        RBus_UInt32  clken_tvsb5:1;
        RBus_UInt32  clken_tve:1;
        RBus_UInt32  clken_dcphy:1;
        RBus_UInt32  clken_dcu:1;
        RBus_UInt32  clken_if_demod:1;
        RBus_UInt32  clken_vdec:1;
        RBus_UInt32  clken_se2:1;
        RBus_UInt32  clken_vbis0:1;
        RBus_UInt32  dummy18000114_19_18:2;
        RBus_UInt32  clken_audio_pre512fs:1;
        RBus_UInt32  clken_audio:1;
        RBus_UInt32  clken_ifadc:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_offms:1;
        RBus_UInt32  clken_me:1;
        RBus_UInt32  clken_apll_adc:1;
        RBus_UInt32  clken_hdmi:1;
        RBus_UInt32  clken_hdmitx:1;
        RBus_UInt32  clken_tp:1;
        RBus_UInt32  clken_cp:1;
        RBus_UInt32  clken_md:1;
        RBus_UInt32  clken_se:1;
        RBus_UInt32  clken_tp_div:1;
        RBus_UInt32  clken_3d_gde:1;
        RBus_UInt32  clken_vodma:1;
        RBus_UInt32  clken_dispim:1;
        RBus_UInt32  clken_disp:1;
    };
}crt_sys_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  clken_tm:1;
        RBus_UInt32  clken_atvin_vd:1;
        RBus_UInt32  clken_atvin_ifd:1;
        RBus_UInt32  dummy18000118_25_24:2;
        RBus_UInt32  clken_emmc:1;
        RBus_UInt32  clken_efuse:1;
        RBus_UInt32  clken_bistreg:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_usb:1;
        RBus_UInt32  clken_otg:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  clken_audio2_512fs:1;
        RBus_UInt32  dummy18000118_14:1;
        RBus_UInt32  clken_irtx:1;
        RBus_UInt32  clken_padmux:1;
        RBus_UInt32  clken_dtv_demod:1;
        RBus_UInt32  clken_misc:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_uart1:1;
        RBus_UInt32  clken_uart2:1;
        RBus_UInt32  clken_sc1:1;
        RBus_UInt32  clken_gpio:1;
        RBus_UInt32  clken_i2c1:1;
        RBus_UInt32  clken_i2c2:1;
        RBus_UInt32  clken_nf:1;
        RBus_UInt32  clken_sc:1;
        RBus_UInt32  clken_pc:1;
    };
}crt_sys_clken2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  clken_dcphy2:1;
        RBus_UInt32  clken_dcu2:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_sd:1;
        RBus_UInt32  res3:8;
        RBus_UInt32  clken_audio2_dma_r_512fs:1;
        RBus_UInt32  clken_audio_dma_r_512fs:1;
        RBus_UInt32  clken_audio_da1_256fs:1;
        RBus_UInt32  clken_audio_da1_128fs:1;
        RBus_UInt32  clken_audio_da0_256fs:1;
        RBus_UInt32  clken_audio_da0_128fs:1;
        RBus_UInt32  clken_audio_ad_256fs:1;
        RBus_UInt32  clken_audio_ad_128fs:1;
    };
}crt_sys_clken3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  ejtag_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  kcpu_clksel:1;
    };
}crt_sys_cpusel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_bypass_ref_clk_mode:1;
        RBus_UInt32  dtv_rbus_i2c_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sd_emmc_clk_sel:2;
        RBus_UInt32  pcr108_clksel:1;
        RBus_UInt32  epi_dbg_clksel:1;
        RBus_UInt32  dpll_clksel:2;
        RBus_UInt32  sd_clk_div:3;
        RBus_UInt32  ve_rif_use_p2clk:1;
        RBus_UInt32  ve2_rif_use_p2clk:1;
        RBus_UInt32  atvin_clk_sel:1;
        RBus_UInt32  atvin_vd_clk_sel:1;
        RBus_UInt32  atvin_vdadc_tve_clk_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tve_108m_clk_sel:1;
        RBus_UInt32  cbus_clksel:1;
        RBus_UInt32  tp_post_div:4;
        RBus_UInt32  tp_pre_div:4;
        RBus_UInt32  vdec_x27_clksel:1;
        RBus_UInt32  vbis0_yppsel:1;
        RBus_UInt32  inv_vbis0_clk:1;
        RBus_UInt32  uart_clksel:1;
    };
}crt_sys_clksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  hdmitx_clksel:2;
        RBus_UInt32  dispd_gdma_clk_sel:1;
        RBus_UInt32  dispd_video_div:2;
        RBus_UInt32  dummy18000208_11_10:2;
        RBus_UInt32  dispd_osd_div:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  clken_disp_sfg:1;
        RBus_UInt32  clken_disp_gdma:1;
        RBus_UInt32  clken_disp_video:1;
        RBus_UInt32  clken_disp_osd:1;
        RBus_UInt32  clken_disp_5k:1;
    };
}crt_sys_dispclksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  hdmi_tmds_div:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  nf_clksel:3;
        RBus_UInt32  dtv_demod_multi_req_disable:1;
        RBus_UInt32  aud_dtv2_freq_sel:3;
        RBus_UInt32  demod_i2c_saddr_sel:1;
        RBus_UInt32  aud_dtv_freq_sel:3;
    };
}crt_sys_clkdiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  scpu_wd_en:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  scpu_wd_cnt:12;
    };
}crt_sys_arm_wd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800021c_31_0:32;
    };
}crt_sys_tvsb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  clkratio_vcpu:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  clkratio_vcpu_active:1;
        RBus_UInt32  clkratio_acpu:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  clkratio_acpu_active:1;
        RBus_UInt32  res4:4;
        RBus_UInt32  res5:3;
        RBus_UInt32  res6:1;
    };
}crt_sys_dyn_sw_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  efuse_ready:1;
    };
}crt_efuse_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:3;
        RBus_UInt32  atv_iso_en:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  atv_str_status:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  atv_str_pow:1;
        RBus_UInt32  res16:3;
        RBus_UInt32  dtv_iso_en:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  dtv_str_status:1;
        RBus_UInt32  res18:1;
        RBus_UInt32  dtv_str_pow:1;
    };
}crt_power_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tm_a:29;
    };
}crt_temp_sensor_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_b:22;
        RBus_UInt32  tm_adccksel:3;
        RBus_UInt32  tm_cal_en:1;
        RBus_UInt32  tm_biaschop:1;
        RBus_UInt32  tm_chopen:1;
        RBus_UInt32  tm_cksourcesel:1;
        RBus_UInt32  tm_dsr:3;
    };
}crt_temp_sensor_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_en_chop:1;
        RBus_UInt32  tm_filteredgesel:1;
        RBus_UInt32  tm_hold_en:1;
        RBus_UInt32  tm_order3:1;
        RBus_UInt32  tm_offset:22;
        RBus_UInt32  tm_pow:1;
        RBus_UInt32  res1:5;
    };
}crt_temp_sensor_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_r:24;
        RBus_UInt32  tm_opcursel:2;
        RBus_UInt32  tm_hold_dly:2;
        RBus_UInt32  tm_osccursel:2;
        RBus_UInt32  tm_resol:2;
    };
}crt_temp_sensor_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_rstb:1;
        RBus_UInt32  tm_sdm_test:1;
        RBus_UInt32  tm_sdm_test_en:1;
        RBus_UInt32  tm_test_en:1;
        RBus_UInt32  tm_vcmsel:3;
        RBus_UInt32  tm_vbe_biassel:2;
        RBus_UInt32  tm_chopfreqsel:11;
        RBus_UInt32  res1:3;
        RBus_UInt32  tm_chop_swcnt:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tm_rst_n:1;
    };
}crt_temp_sensor_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_sample_dly:16;
        RBus_UInt32  tm_compare_dly:16;
    };
}crt_temp_sensor_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_pwron_dly:16;
        RBus_UInt32  tm_reverse_cmp_out:1;
        RBus_UInt32  tm_sbg:3;
        RBus_UInt32  tm_sinl:2;
        RBus_UInt32  tm_sos:3;
        RBus_UInt32  tm_en:1;
        RBus_UInt32  tm_sw2_sw3_reverse:1;
        RBus_UInt32  tm_scan_mode:1;
        RBus_UInt32  tm_biasdem_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  td_wrep_edge_sel:1;
        RBus_UInt32  data_valid_edge_sel:1;
    };
}crt_temp_sensor_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  tm_s:23;
    };
}crt_temp_sensor_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  data_out_tm:7;
        RBus_UInt32  res2:5;
        RBus_UInt32  ct_out_o_tm:19;
    };
}crt_thermal_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  u_out_tm:22;
    };
}crt_thermal_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smartcard_int_scpu_routing_en:1;
        RBus_UInt32  dummy18000290_30:1;
        RBus_UInt32  dummy18000290_29:1;
        RBus_UInt32  standby_syncp_int_scpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_scpu_routing_en:1;
        RBus_UInt32  standby_wdog_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_scpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cec_int_scpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_scpu_routing_en:1;
        RBus_UInt32  akl_int_scpu_routing_en:1;
        RBus_UInt32  usb3_int_scpu_routing_en:1;
        RBus_UInt32  otg_int_scpu_routing_en:1;
        RBus_UInt32  etn_int_scpu_routing_en:1;
        RBus_UInt32  sd_int_scpu_routing_en:1;
        RBus_UInt32  audio_dma_irq_scpu_routing_en:1;
        RBus_UInt32  audio_irq_scpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_scpu_routing_en:1;
        RBus_UInt32  dcphy_int_scpu_routing_en:1;
        RBus_UInt32  dc_int_scpu_routing_en:1;
        RBus_UInt32  tve_int_scpu_routing_en:1;
        RBus_UInt32  osd_int_scpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_scpu_routing_en:1;
        RBus_UInt32  dctl_int_scpu_routing_en:1;
        RBus_UInt32  vbi_int_scpu_routing_en:1;
        RBus_UInt32  vdec_int_scpu_routing_en:1;
        RBus_UInt32  if_demod_int_scpu_routing_en:1;
        RBus_UInt32  dispm_int_scpu_routing_en:1;
        RBus_UInt32  dispi_int_scpu_routing_en:1;
        RBus_UInt32  apll_dds_int_scpu_routing_en:1;
        RBus_UInt32  ddc_int_scpu_routing_en:1;
    };
}crt_int_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp2tve_int_vcpu_routing_en:1;
        RBus_UInt32  vodma_int_vcpu_routing_en:1;
        RBus_UInt32  dummy18000294_28:1;
        RBus_UInt32  dummy18000294_27:1;
        RBus_UInt32  dummy18000294_26:1;
        RBus_UInt32  dummy18000294_25:1;
        RBus_UInt32  dummy18000294_24:1;
        RBus_UInt32  dummy18000294_23:1;
        RBus_UInt32  dummy18000294_22:1;
        RBus_UInt32  dummy18000294_21:1;
        RBus_UInt32  dummy18000294_20:1;
        RBus_UInt32  dummy18000294_19:1;
        RBus_UInt32  dummy18000294_18:1;
        RBus_UInt32  dummy18000294_17:1;
        RBus_UInt32  dummy18000294_16:1;
        RBus_UInt32  dummy18000294_15:1;
        RBus_UInt32  dummy18000294_14:1;
        RBus_UInt32  tv_sb_dc_int_vcpu_routing_en:1;
        RBus_UInt32  dcphy_int_vcpu_routing_en:1;
        RBus_UInt32  dc_int_vcpu_routing_en:1;
        RBus_UInt32  tve_int_vcpu_routing_en:1;
        RBus_UInt32  osd_int_vcpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_vcpu_routing_en:1;
        RBus_UInt32  dctl_int_vcpu_routing_en:1;
        RBus_UInt32  vbi_int_vcpu_routing_en:1;
        RBus_UInt32  vdec_int_vcpu_routing_en:1;
        RBus_UInt32  if_demod_int_vcpu_routing_en:1;
        RBus_UInt32  dispm_int_vcpu_routing_en:1;
        RBus_UInt32  dispi_int_vcpu_routing_en:1;
        RBus_UInt32  apll_dds_int_vcpu_routing_en:1;
        RBus_UInt32  ddc_int_vcpu_routing_en:1;
    };
}crt_int_ctrl_vcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  memc_int_vcpu_routing_en:1;
        RBus_UInt32  dummy180002a0_27:1;
        RBus_UInt32  dummy180002a0_26:1;
        RBus_UInt32  dummy180002a0_25:1;
        RBus_UInt32  memc_int_vcpu2_routing_en:1;
        RBus_UInt32  dummy180002a0_23:1;
        RBus_UInt32  dummy180002a0_22:1;
        RBus_UInt32  dummy180002a0_21:1;
        RBus_UInt32  memc_int_scpu_routing_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  hdmi_irq_vcpu_routing_en:1;
        RBus_UInt32  hdmi_irq_scpu_routing_en:1;
        RBus_UInt32  res5:16;
    };
}int_ctrl_memc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  audio_dma_irq_acpu_routing_en:1;
        RBus_UInt32  audio_irq_acpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_acpu_routing_en:1;
        RBus_UInt32  dcphy_int_acpu_routing_en:1;
        RBus_UInt32  dc_int_acpu_routing_en:1;
        RBus_UInt32  dummy18000298_10:1;
        RBus_UInt32  dummy18000298_9:1;
        RBus_UInt32  dummy18000298_8:1;
        RBus_UInt32  dummy18000298_7:1;
        RBus_UInt32  dummy18000298_6:1;
        RBus_UInt32  dummy18000298_5:1;
        RBus_UInt32  dummy18000298_4:1;
        RBus_UInt32  dummy18000298_3:1;
        RBus_UInt32  dummy18000298_2:1;
        RBus_UInt32  dummy18000298_1:1;
        RBus_UInt32  dummy18000298_0:1;
    };
}crt_int_ctrl_acpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smartcard_int_kcpu_routing_en:1;
        RBus_UInt32  disp2tve_int_kcpu_routing_en:1;
        RBus_UInt32  vodma_int_kcpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_kcpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_kcpu_routing_en:1;
        RBus_UInt32  standby_wdog_int_kcpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_kcpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_kcpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_kcpu_routing_en:1;
        RBus_UInt32  standby_cec_int_kcpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_kcpu_routing_en:1;
        RBus_UInt32  akl_int_kcpu_routing_en:1;
        RBus_UInt32  usb3_int_kcpu_routing_en:1;
        RBus_UInt32  otg_int_kcpu_routing_en:1;
        RBus_UInt32  etn_int_kcpu_routing_en:1;
        RBus_UInt32  sd_int_kcpu_routing_en:1;
        RBus_UInt32  dummy1800029c_15:1;
        RBus_UInt32  dummy1800029c_14:1;
        RBus_UInt32  tv_sb_dc_int_kcpu_routing_en:1;
        RBus_UInt32  dcphy_int_kcpu_routing_en:1;
        RBus_UInt32  dc_int_kcpu_routing_en:1;
        RBus_UInt32  tve_int_kcpu_routing_en:1;
        RBus_UInt32  osd_int_kcpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_kcpu_routing_en:1;
        RBus_UInt32  dctl_int_kcpu_routing_en:1;
        RBus_UInt32  vbi_int_kcpu_routing_en:1;
        RBus_UInt32  vdec_int_kcpu_routing_en:1;
        RBus_UInt32  if_demod_int_kcpu_routing_en:1;
        RBus_UInt32  dispm_int_kcpu_routing_en:1;
        RBus_UInt32  dispi_int_kcpu_routing_en:1;
        RBus_UInt32  apll_dds_int_kcpu_routing_en:1;
        RBus_UInt32  ddc_int_kcpu_routing_en:1;
    };
}crt_int_ctrl_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_ip_c30_7t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  main_ip_c30_7t_ro_sel:3;
        RBus_UInt32  main_ip_c30_7t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  main_ip_c30_7t_ready:1;
        RBus_UInt32  main_ip_c30_7t_count_out:20;
    };
}crt_ss_mainip_c30_7t_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  main_ip_c30_7t_speed_en:1;
        RBus_UInt32  main_ip_c30_7t_wsort_go:1;
        RBus_UInt32  main_ip_c30_7t_data_in:20;
    };
}crt_ss_mainip_c30_7t_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  main_ip_c30_7t_dbgo:16;
    };
}crt_ss_mainip_c30_7t_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c35_9p5t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dispd_c35_9p5t_ro_sel:3;
        RBus_UInt32  dispd_c35_9p5t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dispd_c35_9p5t_ready:1;
        RBus_UInt32  dispd_c35_9p5t_count_out:20;
    };
}crt_ss_dispd_c35_9p5t_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dispd_c35_9p5t_speed_en:1;
        RBus_UInt32  dispd_c35_9p5t_wsort_go:1;
        RBus_UInt32  dispd_c35_9p5t_data_in:20;
    };
}crt_ss_dispd_c35_9p5t_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dispd_c35_9p5t_dbgo:16;
    };
}crt_ss_dispd_c35_9p5t_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c31_9p5t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dispd_c31_9p5t_ro_sel:3;
        RBus_UInt32  dispd_c31_9p5t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dispd_c31_9p5t_ready:1;
        RBus_UInt32  dispd_c31_9p5t_count_out:20;
    };
}crt_ss_dispd_c31_9p5t_rlvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dispd_c31_9p5t_speed_en:1;
        RBus_UInt32  dispd_c31_9p5t_wsort_go:1;
        RBus_UInt32  dispd_c31_9p5t_data_in:20;
    };
}crt_ss_dispd_c31_9p5t_rlvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dispd_c31_9p5t_dbgo:16;
    };
}crt_ss_dispd_c35_9p5t_rlvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_c35_9p5t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  acpu_c35_9p5t_ro_sel:3;
        RBus_UInt32  acpu_c35_9p5t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  acpu_c35_9p5t_ready:1;
        RBus_UInt32  acpu_c35_9p5t_count_out:20;
    };
}crt_ss_acpu_c35_9p5t_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  acpu_c35_9p5t_speed_en:1;
        RBus_UInt32  acpu_c35_9p5t_wsort_go:1;
        RBus_UInt32  acpu_c35_9p5t_data_in:20;
    };
}crt_ss_acpu_c35_9p5t_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  acpu_c35_9p5t_dbgo:16;
    };
}crt_ss_acpu_c35_9p5t_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  main_voltage_strobe_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  demod_voltage_strobe_en:1;
    };
}crt_voltage_strobe_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  dbg0_div_sel:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  top_ssc_dbg_sel:4;
        RBus_UInt32  crt_dbg_sel:8;
    };
}crt_sc_debug_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_n:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  pllddsb_ip:4;
        RBus_UInt32  pllddsb_rs:3;
        RBus_UInt32  pllddsb_cs:2;
        RBus_UInt32  pllddsb_cp:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsb_o:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllddsb_wdmode:2;
    };
}crt_sys_pll_dispb_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsb_fcode:11;
        RBus_UInt32  pllddsb_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_oeb:1;
        RBus_UInt32  pllddsb_rstb:1;
        RBus_UInt32  pllddsb_pow:1;
    };
}crt_sys_pll_dispb_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000358_28_25:4;
        RBus_UInt32  dummy18000358_24:1;
        RBus_UInt32  dummy18000358_23:1;
        RBus_UInt32  dummy18000358_22:1;
        RBus_UInt32  dummy18000358_21:1;
        RBus_UInt32  dummy18000358_20:1;
        RBus_UInt32  dummy18000358_19:1;
        RBus_UInt32  dummy18000358_18:1;
        RBus_UInt32  dummy18000358_17:1;
        RBus_UInt32  dummy18000358_16:1;
        RBus_UInt32  dummy18000358_15:1;
        RBus_UInt32  pllddsb_vcorb:1;
        RBus_UInt32  dummy18000358_13:1;
        RBus_UInt32  pllddsb_tst:1;
        RBus_UInt32  pllddsb_pstst:1;
        RBus_UInt32  dummy18000358_10:1;
        RBus_UInt32  res2:10;
    };
}crt_sys_pll_dispb_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy1800035c_30:1;
        RBus_UInt32  psaud1b_fupdn:1;
        RBus_UInt32  psaud1b_div:1;
        RBus_UInt32  dummy1800035c_27:1;
        RBus_UInt32  psaud1b_tst:1;
        RBus_UInt32  psaud1b_psen:1;
        RBus_UInt32  dummy1800035c_24:1;
        RBus_UInt32  psaud2b_fupdn:1;
        RBus_UInt32  psaud2b_div:1;
        RBus_UInt32  psaud2b_tst:1;
        RBus_UInt32  psaud2b_psen:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  psaud1b_oeb:1;
        RBus_UInt32  psaud1b_rstb:1;
        RBus_UInt32  psaud2b_oeb:1;
        RBus_UInt32  psaud2b_rstb:1;
    };
}crt_sys_pll_dispb_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_bypass_pi:1;
        RBus_UInt32  pllddsb_en_pi_debug:1;
        RBus_UInt32  pllddsb_hs_oc_stop:2;
        RBus_UInt32  pllddsb_pi_cur_sel:2;
        RBus_UInt32  pllddsb_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsb_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsb_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_sdm_order:1;
        RBus_UInt32  pllddsb_oc_done:1;
        RBus_UInt32  pllddsb_oc_en:1;
    };
}crt_sys_dvfs_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsb_fcode_dbg:11;
        RBus_UInt32  pllddsb_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}crt_sys_dvfs_ddsb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce_b:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme_b:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps_b:1;
        RBus_UInt32  psc_b:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs_b:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd_b:1;
        RBus_UInt32  su_b:1;
    };
}crt_ai_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce_b_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme_b_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps_b_2:1;
        RBus_UInt32  psc_b_2:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs_b_2:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd_b_2:1;
        RBus_UInt32  su_b_2:1;
    };
}crt_ai2_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllkcpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllkcpu_n:2;
        RBus_UInt32  pllkcpu_m:8;
        RBus_UInt32  pllkcpu_ip:3;
        RBus_UInt32  pllkcpu_o:2;
        RBus_UInt32  pllkcpu_wdset:1;
        RBus_UInt32  pllkcpu_wdrst:1;
        RBus_UInt32  pllkcpu_cs:2;
        RBus_UInt32  pllkcpu_rs:3;
    };
}crt_sys_pll_kcpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllkcpu_oeb:1;
        RBus_UInt32  pllkcpu_rstb:1;
        RBus_UInt32  pllkcpu_pow:1;
    };
}crt_sys_pll_kcpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbus_en_ssc:1;
    };
}crt_pll_ssc_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllbus_fcode_ssc:11;
    };
}crt_pll_ssc_bus_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_auto_rst_h:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran_h:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_est_h:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbus_en_ssc_h:1;
    };
}crt_pll_ssc_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_ssc_h:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllbus_fcode_ssc_h:11;
    };
}crt_pll_ssc_bush_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsa_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsa_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllddsa_en_ssc:1;
    };
}crt_pll_ssc_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsa_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllddsa_fcode_ssc:11;
    };
}crt_pll_ssc_ddsa_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsb_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsb_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllddsb_en_ssc:1;
    };
}crt_pll_ssc_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsb_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllddsb_fcode_ssc:11;
    };
}crt_pll_ssc_ddsb_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  psaud2b_ssc_ckinv:1;
        RBus_UInt32  psaud2a_ssc_ckinv:1;
        RBus_UInt32  psaud1b_ssc_ckinv:1;
        RBus_UInt32  psaud1a_ssc_ckinv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dds_ssc_ckinv:1;
        RBus_UInt32  gpu_ssc_ckinv:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  bush_ssc_ckinv:1;
        RBus_UInt32  bus_ssc_ckinv:1;
    };
}crt_pll_ssc_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pow_ldo1v:1;
        RBus_UInt32  ldo1v_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllcpu_reg:2;
    };
}crt_sys_pll_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllacpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllacpu_n:2;
        RBus_UInt32  pllacpu_m:8;
        RBus_UInt32  pllacpu_ip:3;
        RBus_UInt32  pllacpu_o:2;
        RBus_UInt32  pllacpu_wdset:1;
        RBus_UInt32  pllacpu_wdrst:1;
        RBus_UInt32  pllacpu_cs:2;
        RBus_UInt32  pllacpu_rs:3;
    };
}crt_sys_pll_acpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllacpu_oeb:1;
        RBus_UInt32  pllacpu_rstb:1;
        RBus_UInt32  pllacpu_pow:1;
    };
}crt_sys_pll_acpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllvcpu_tst:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllvcpu_n:2;
        RBus_UInt32  pllvcpu_m:8;
        RBus_UInt32  pllvcpu_ip:3;
        RBus_UInt32  pllvcpu_o:2;
        RBus_UInt32  pllvcpu_wdset:1;
        RBus_UInt32  pllvcpu_wdrst:1;
        RBus_UInt32  pllvcpu_cs:2;
        RBus_UInt32  pllvcpu_rs:3;
    };
}crt_sys_pll_vcpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllvcpu_oeb:1;
        RBus_UInt32  pllvcpu_rstb:1;
        RBus_UInt32  pllvcpu_pow:1;
    };
}crt_sys_pll_vcpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  pllvcpu_tst_2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllvcpu_n_2:2;
        RBus_UInt32  pllvcpu_m_2:8;
        RBus_UInt32  pllvcpu_ip_2:3;
        RBus_UInt32  pllvcpu_o_2:2;
        RBus_UInt32  pllvcpu_wdset_2:1;
        RBus_UInt32  pllvcpu_wdrst_2:1;
        RBus_UInt32  pllvcpu_cs_2:2;
        RBus_UInt32  pllvcpu_rs_2:3;
    };
}crt_sys_pll_vcpu2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllvcpu_oeb_2:1;
        RBus_UInt32  pllvcpu_rstb_2:1;
        RBus_UInt32  pllvcpu_pow_2:1;
    };
}crt_sys_pll_vcpu2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllbus_wdset:1;
        RBus_UInt32  pllbus_wdrst:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pllbus_lpf_cs:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  pllbus_testsel:1;
        RBus_UInt32  pllbus_sel_cco:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  pllbus_icp:3;
        RBus_UInt32  pllbus_dbug_en:1;
        RBus_UInt32  pllbus_pdiv_bps:1;
        RBus_UInt32  pllbus_pdiv:2;
        RBus_UInt32  res9:1;
        RBus_UInt32  pllbus_lpf_rs:3;
    };
}crt_sys_pll_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode:11;
        RBus_UInt32  pllbus_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_oeb:1;
        RBus_UInt32  pllbus_rstb:1;
        RBus_UInt32  pllbus_pow:1;
    };
}crt_sys_pll_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_bypass_pi:1;
        RBus_UInt32  pllbus_en_pi_debug:1;
        RBus_UInt32  pllbus_hs_oc_stop:2;
        RBus_UInt32  pllbus_pi_cur_sel:2;
        RBus_UInt32  pllbus_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllbus_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_sdm_order:1;
        RBus_UInt32  pllbus_oc_done:1;
        RBus_UInt32  pllbus_oc_en:1;
    };
}crt_sys_dvfs_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode_dbg:11;
        RBus_UInt32  pllbus_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}crt_sys_dvfs_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllbus_wdset_h:1;
        RBus_UInt32  pllbus_wdrst_h:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pllbus_lpf_cs_h:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  pllbus_testsel_h:1;
        RBus_UInt32  pllbus_sel_cco_h:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  pllbus_icp_h:3;
        RBus_UInt32  pllbus_dbug_en_h:1;
        RBus_UInt32  pllbus_pdiv_bps_h:1;
        RBus_UInt32  pllbus_pdiv_h:2;
        RBus_UInt32  res9:1;
        RBus_UInt32  pllbus_lpf_rs_h:3;
    };
}crt_sys_pll_bush1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode_h:11;
        RBus_UInt32  pllbus_ncode_h:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_oeb_h:1;
        RBus_UInt32  pllbus_rstb_h:1;
        RBus_UInt32  pllbus_pow_h:1;
    };
}crt_sys_pll_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_bypass_pi_h:1;
        RBus_UInt32  pllbus_en_pi_debug_h:1;
        RBus_UInt32  pllbus_hs_oc_stop_h:2;
        RBus_UInt32  pllbus_pi_cur_sel_h:2;
        RBus_UInt32  pllbus_sel_oc_mode_h:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllbus_oc_done_delay_h:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_step_h:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_sdm_order_h:1;
        RBus_UInt32  pllbus_oc_done_h:1;
        RBus_UInt32  pllbus_oc_en_h:1;
    };
}crt_sys_dvfs_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_fcode_dbg_h:11;
        RBus_UInt32  pllbus_ncode_dbg_h:8;
        RBus_UInt32  res2:8;
    };
}crt_sys_dvfs_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllgpu_wdset:1;
        RBus_UInt32  pllgpu_wdrst:1;
        RBus_UInt32  res6:2;
        RBus_UInt32  pllgpu_lpf_cs:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  pllgpu_testsel:1;
        RBus_UInt32  pllgpu_sel_cco:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  pllgpu_icp:3;
        RBus_UInt32  pllgpu_dbug_en:1;
        RBus_UInt32  pllgpu_pdiv_bps:1;
        RBus_UInt32  pllgpu_pdiv:2;
        RBus_UInt32  res9:1;
        RBus_UInt32  pllgpu_lpf_rs:3;
    };
}crt_sys_pll_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllgpu_fcode:11;
        RBus_UInt32  pllgpu_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllgpu_oeb:1;
        RBus_UInt32  pllgpu_rstb:1;
        RBus_UInt32  pllgpu_pow:1;
    };
}crt_sys_pll_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_bypass_pi:1;
        RBus_UInt32  pllgpu_en_pi_debug:1;
        RBus_UInt32  pllgpu_hs_oc_stop:2;
        RBus_UInt32  pllgpu_pi_cur_sel:2;
        RBus_UInt32  pllgpu_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllgpu_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllgpu_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllgpu_sdm_order:1;
        RBus_UInt32  pllgpu_oc_done:1;
        RBus_UInt32  pllgpu_oc_en:1;
    };
}crt_sys_dvfs_gpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllgpu_fcode_dbg:11;
        RBus_UInt32  pllgpu_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}crt_sys_dvfs_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllvodma_n:2;
        RBus_UInt32  pllvodma_m:8;
        RBus_UInt32  pllvodma_ip:3;
        RBus_UInt32  pllvodma_o:2;
        RBus_UInt32  pllvodma_wdset:1;
        RBus_UInt32  pllvodma_wdrst:1;
        RBus_UInt32  pllvodma_cs:2;
        RBus_UInt32  pllvodma_rs:3;
    };
}crt_sys_pll_vodma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  pllvodma_tst:1;
        RBus_UInt32  pllvodma_oeb:1;
        RBus_UInt32  pllvodma_rstb:1;
        RBus_UInt32  pllvodma_pow:1;
    };
}crt_sys_pll_vodma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_reser:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_reg:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbustst_div:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllbustst_sel:5;
    };
}crt_sys_pllbus_tst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_n:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  pllddsa_ip:4;
        RBus_UInt32  pllddsa_rs:3;
        RBus_UInt32  pllddsa_cs:2;
        RBus_UInt32  pllddsa_cp:2;
        RBus_UInt32  res2:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsa_o:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllddsa_wdmode:2;
    };
}crt_sys_pll_dispa_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsa_fcode:11;
        RBus_UInt32  pllddsa_ncode:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_oeb:1;
        RBus_UInt32  pllddsa_rstb:1;
        RBus_UInt32  pllddsa_pow:1;
    };
}crt_sys_pll_dispa_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dummy18000478_28_25:4;
        RBus_UInt32  dummy18000478_24:1;
        RBus_UInt32  dummy18000478_23:1;
        RBus_UInt32  dummy18000478_22:1;
        RBus_UInt32  dummy18000478_21:1;
        RBus_UInt32  dummy18000478_20:1;
        RBus_UInt32  dummy18000478_19:1;
        RBus_UInt32  dummy18000478_18:1;
        RBus_UInt32  dummy18000478_17:1;
        RBus_UInt32  dummy18000478_16:1;
        RBus_UInt32  dummy18000478_15:1;
        RBus_UInt32  pllddsa_vcorb:1;
        RBus_UInt32  dummy18000478_13:1;
        RBus_UInt32  pllddsa_tst:1;
        RBus_UInt32  pllddsa_pstst:1;
        RBus_UInt32  dummy18000478_10:1;
        RBus_UInt32  res2:10;
    };
}crt_sys_pll_dispa_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy1800047c_30:1;
        RBus_UInt32  psaud1a_fupdn:1;
        RBus_UInt32  psaud1a_div:1;
        RBus_UInt32  dummy1800047c_27:1;
        RBus_UInt32  psaud1a_tst:1;
        RBus_UInt32  psaud1a_psen:1;
        RBus_UInt32  dummy1800047c_24:1;
        RBus_UInt32  psaud2a_fupdn:1;
        RBus_UInt32  psaud2a_div:1;
        RBus_UInt32  psaud2a_tst:1;
        RBus_UInt32  psaud2a_psen:1;
        RBus_UInt32  res2:16;
        RBus_UInt32  psaud1a_oeb:1;
        RBus_UInt32  psaud1a_rstb:1;
        RBus_UInt32  psaud2a_oeb:1;
        RBus_UInt32  psaud2a_rstb:1;
    };
}crt_sys_pll_dispa_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_bypass_pi:1;
        RBus_UInt32  pllddsa_en_pi_debug:1;
        RBus_UInt32  pllddsa_hs_oc_stop:2;
        RBus_UInt32  pllddsa_pi_cur_sel:2;
        RBus_UInt32  pllddsa_sel_oc_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsa_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsa_oc_step:10;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_sdm_order:1;
        RBus_UInt32  pllddsa_oc_done:1;
        RBus_UInt32  pllddsa_oc_en:1;
    };
}crt_sys_dvfs_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsa_fcode_dbg:11;
        RBus_UInt32  pllddsa_ncode_dbg:8;
        RBus_UInt32  res2:8;
    };
}crt_sys_dvfs_ddsa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps:1;
        RBus_UInt32  psc:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd:1;
        RBus_UInt32  su:1;
    };
}crt_ai_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  swsce_2:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  tme_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tmps_2:1;
        RBus_UInt32  psc_2:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  swcs_2:7;
        RBus_UInt32  res5:7;
        RBus_UInt32  sd_2:1;
        RBus_UInt32  su_2:1;
    };
}crt_ai2_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pll27x_wdout:1;
        RBus_UInt32  pllvodma_wdout:1;
        RBus_UInt32  pllkcpu_wdout:1;
        RBus_UInt32  pll512fs_wdout_1:1;
        RBus_UInt32  pllaud_status:1;
        RBus_UInt32  pll512fs_wdout:1;
        RBus_UInt32  pllbush_wdout:1;
        RBus_UInt32  pllgpu_wdout:1;
        RBus_UInt32  plldif_wdout:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsb_wdout:1;
        RBus_UInt32  pllscpu_2_wdout:1;
        RBus_UInt32  pllbus_wdout:1;
        RBus_UInt32  plldisp_wdout:1;
        RBus_UInt32  pllvcpu2_wdout:1;
        RBus_UInt32  pllddsa_wdout:1;
        RBus_UInt32  pllvcpu_wdout:1;
        RBus_UInt32  pllacpu_wdout:1;
        RBus_UInt32  pllscpu_wdout:1;
    };
}crt_sys_pll_wd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_n:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_m:7;
        RBus_UInt32  pll512fs_bpn:1;
        RBus_UInt32  pll512fs_bps:1;
        RBus_UInt32  pll512fs_cs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll512fs_ip:3;
        RBus_UInt32  pll512fs_s:3;
        RBus_UInt32  pll512fs_q:3;
        RBus_UInt32  pll512fs_rs:3;
        RBus_UInt32  pll512fs_tst:1;
        RBus_UInt32  pll512fs_wdrst:1;
        RBus_UInt32  pll512fs_wdset:1;
    };
}crt_sys_pll_512fs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pll512fs_oeb:1;
        RBus_UInt32  pll512fs_rstb:1;
        RBus_UInt32  pll512fs_pow:1;
    };
}crt_sys_pll_512fs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_n2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_m2:7;
        RBus_UInt32  pll512fs_bpn2:1;
        RBus_UInt32  pll512fs_bps2:1;
        RBus_UInt32  pll512fs_cs2:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll512fs_ip2:3;
        RBus_UInt32  pll512fs_s2:3;
        RBus_UInt32  pll512fs_q2:3;
        RBus_UInt32  pll512fs_rs2:3;
        RBus_UInt32  pll512fs_tst2:1;
        RBus_UInt32  pll512fs_wdrst2:1;
        RBus_UInt32  pll512fs_wdset2:1;
    };
}crt_sys_pll_512fs2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pll512fs_oeb2:1;
        RBus_UInt32  pll512fs_rstb2:1;
        RBus_UInt32  pll512fs_pow2:1;
    };
}crt_sys_pll_512fs2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  plldif_n:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_m:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_ip:3;
        RBus_UInt32  plldif_lf_rs:2;
        RBus_UInt32  plldif_lf_cp:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:11;
    };
}crt_sys_pll_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  plldif_dvbs2_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  plldif_wdmode:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_divdig_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  plldif_divadc_sel:3;
    };
}crt_sys_pll_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  plldif_vco_rstb:1;
        RBus_UInt32  plldif_rstb:1;
        RBus_UInt32  plldif_pow:1;
    };
}crt_sys_pll_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pll27x_wdmode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll27x_lf_cp:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_lf_rs:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_ip:3;
        RBus_UInt32  res5:4;
        RBus_UInt32  res6:2;
        RBus_UInt32  pll27x_n:2;
        RBus_UInt32  res7:1;
        RBus_UInt32  pll27x_m:7;
    };
}crt_sys_pll_27x1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xi_cap:4;
        RBus_UInt32  xo_cap:4;
        RBus_UInt32  vdd11_pad_sel:2;
        RBus_UInt32  pll_ldo_xtal_sel:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_xixo_load:1;
        RBus_UInt32  pll_xixo_drive_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_pow_ldo11v:1;
        RBus_UInt32  pll_ldo11v_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_pow_ldo:1;
        RBus_UInt32  pll_ldo_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pll27x_ps_54m_delay:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  pll27x_ps_psel_pulse_w:1;
        RBus_UInt32  pll27x_ps_duty_sel:1;
    };
}crt_sys_pll_27x2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pll_reserve:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  pll27x_ps_en:1;
        RBus_UInt32  pll27x_ps_div2:1;
        RBus_UInt32  pll27x_vcorstb:1;
        RBus_UInt32  pll27x_rstb:1;
        RBus_UInt32  pll27x_pow:1;
    };
}crt_sys_pll_27x3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180004dc_31:1;
        RBus_UInt32  pll27x_ifadc_duty:2;
        RBus_UInt32  dummy180004dc_28:1;
        RBus_UInt32  pll_yppadc_cko_polar:1;
        RBus_UInt32  pll_ifadc_cko_polar:1;
        RBus_UInt32  pll_l2h_cml_pow:1;
        RBus_UInt32  pll27x_d16_en:1;
        RBus_UInt32  pll27x_pll_tst:3;
        RBus_UInt32  pll27x_en_tst:1;
        RBus_UInt32  pll_rssi_cko_en:1;
        RBus_UInt32  pll27x_ck108m_en:1;
        RBus_UInt32  pll27x_ck108m_div:2;
        RBus_UInt32  pll27x_yppadc_cko_sel:2;
        RBus_UInt32  pll27x_yppadc_cko_en:1;
        RBus_UInt32  pll27x_yppadc_ck54m_en:1;
        RBus_UInt32  pll27x_ifadc_cko_sel:2;
        RBus_UInt32  pll27x_ifadc_div:1;
        RBus_UInt32  pll27x_ifadc_cko_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllaud_ckin_mux:1;
        RBus_UInt32  pll_xtalwd_rst:1;
        RBus_UInt32  pll_xtalwd_set:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_ck_ifadc_mux:1;
    };
}crt_sys_pll_27x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  pllaud_ip:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllaud_rs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllaud_cp:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  pllaud_wdrst:1;
        RBus_UInt32  pllaud_wdset:1;
        RBus_UInt32  pllaud_tst:1;
    };
}crt_sys_pll_aud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pllaud_vcorstb:1;
        RBus_UInt32  pllaud_rstb:1;
        RBus_UInt32  pllaud_oeb1:1;
        RBus_UInt32  pllaud_oeb2:1;
        RBus_UInt32  pllaud_pow:1;
    };
}crt_sys_pll_aud3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  bb_micbias_clksel:2;
    };
}crt_sys_pll_aud4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  psaud_adder_mode:1;
        RBus_UInt32  psaud_psen:1;
        RBus_UInt32  psaud_en:1;
        RBus_UInt32  psaud_tst:1;
        RBus_UInt32  psaud_ctrl:1;
    };
}crt_sys_pll_psaud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  psaud_div:4;
    };
}crt_sys_pll_psaud2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_cco_band:2;
        RBus_UInt32  reg_dpi_post_pi_sel2:5;
        RBus_UInt32  reg_dpi_post_pi_sel1:5;
        RBus_UInt32  reg_dpi_post_pi_sel0:5;
        RBus_UInt32  reg_dpi_en_post_pi:8;
        RBus_UInt32  reg_dpi_mck_clk_en:7;
    };
}crt_sys_pll_ddr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_lpf_sr:3;
        RBus_UInt32  reg_dpi_lpf_cp:1;
        RBus_UInt32  reg_dpi_loop_pi_isel:4;
        RBus_UInt32  reg_dpi_icp:4;
        RBus_UInt32  reg_dpi_post_pi_sel6:5;
        RBus_UInt32  reg_dpi_post_pi_sel5:5;
        RBus_UInt32  reg_dpi_post_pi_sel4:5;
        RBus_UInt32  reg_dpi_post_pi_sel3:5;
    };
}crt_sys_pll_ddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_n_code:8;
        RBus_UInt32  reg_dpi_en_ssc:1;
        RBus_UInt32  reg_dpi_bypass_pi:1;
        RBus_UInt32  reg_dpi_f_code:11;
        RBus_UInt32  reg_dpi_post_pi_rs:1;
        RBus_UInt32  reg_dpi_post_pi_rl:2;
        RBus_UInt32  reg_dpi_post_pi_bias:2;
        RBus_UInt32  reg_dpi_pll_sel_cpmode:1;
        RBus_UInt32  reg_dpi_pll_ldo_vsel:2;
        RBus_UInt32  reg_dpi_pll_dbug_en:1;
        RBus_UInt32  reg_dpi_pdiv:2;
    };
}crt_sys_pll_ddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_cco_kvco:1;
        RBus_UInt32  reg_dpi_oc_en:1;
        RBus_UInt32  reg_dpi_oc_step_set:10;
        RBus_UInt32  reg_dpi_f_code_t:11;
        RBus_UInt32  reg_dpi_n_code_t:8;
        RBus_UInt32  reg_dpi_order:1;
    };
}crt_sys_pll_ddr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dot_gran:3;
        RBus_UInt32  reg_dpi_gran_set:19;
        RBus_UInt32  reg_dpi_oc_done_delay:6;
        RBus_UInt32  reg_dpi_hs_oc_stop_diff:2;
        RBus_UInt32  reg_dpi_sel_oc_mode:2;
    };
}crt_sys_pll_ddr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_dpi_oesync_op_sel:7;
        RBus_UInt32  reg_dpi_clk_oe:7;
        RBus_UInt32  reg_dpi_time2_rst_width:2;
        RBus_UInt32  reg_dpi_time_rdy_ckout:2;
        RBus_UInt32  reg_dpi_time0_ck:3;
        RBus_UInt32  reg_dpi_f390k:2;
        RBus_UInt32  reg_dpi_wd_enable:1;
        RBus_UInt32  reg_dpi_gran_auto_rst:1;
    };
}crt_sys_pll_ddr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_stable:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  reg_dpi_pll_en:1;
        RBus_UInt32  reg_dpi_ng_clk_sel:2;
        RBus_UInt32  reg_dpi_v11_ldo_vsel:2;
        RBus_UInt32  reg_dpi_post_pi_sel:5;
        RBus_UInt32  reg_dpi_adj_div2_en:1;
        RBus_UInt32  reg_dpi_ckref_sel:1;
        RBus_UInt32  reg_dpi_dat_rate_sel:1;
        RBus_UInt32  reg_dpi_adr_rate_sel:1;
        RBus_UInt32  reg_dpi_pll_dum:8;
    };
}crt_sys_pll_ddr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_dbg_sel:1;
        RBus_UInt32  reg_dpi_dcc_cmd_div:3;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_cmd_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_cmd_duty:7;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_preseta:3;
    };
}crt_sys_pll_ddr_dcc_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_0:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_0:6;
        RBus_UInt32  reg_dpi_dll_int_gain_0:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_0:1;
        RBus_UInt32  reg_dpi_dll_dly_0:9;
        RBus_UInt32  reg_dpi_dll_init_value_0:8;
    };
}crt_sys_pll_ddr_dcc_ad0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_1:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_1:6;
        RBus_UInt32  reg_dpi_dll_int_gain_1:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_1:1;
        RBus_UInt32  reg_dpi_dll_dly_1:9;
        RBus_UInt32  reg_dpi_dll_init_value_1:8;
    };
}crt_sys_pll_ddr_dcc_ad0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_2:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_2:6;
        RBus_UInt32  reg_dpi_dll_int_gain_2:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_2:1;
        RBus_UInt32  reg_dpi_dll_dly_2:9;
        RBus_UInt32  reg_dpi_dll_init_value_2:8;
    };
}crt_sys_pll_ddr_dcc_ad0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_3:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_3:6;
        RBus_UInt32  reg_dpi_dll_int_gain_3:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_3:1;
        RBus_UInt32  reg_dpi_dll_dly_3:9;
        RBus_UInt32  reg_dpi_dll_init_value_3:8;
    };
}crt_sys_pll_ddr_dcc_ad0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_0:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_0:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_0:5;
    };
}crt_sys_pll_ddr_dcc_ad1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_1:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_1:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_1:5;
    };
}crt_sys_pll_ddr_dcc_ad1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_2:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_2:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_2:5;
    };
}crt_sys_pll_ddr_dcc_ad1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_3:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_3:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_3:5;
    };
}crt_sys_pll_ddr_dcc_ad1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_0:3;
    };
}crt_sys_pll_ddr_dcc_dqs_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_1:3;
    };
}crt_sys_pll_ddr_dcc_dqs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_2:3;
    };
}crt_sys_pll_ddr_dcc_dqs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_3:3;
    };
}crt_sys_pll_ddr_dcc_dqs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_0:3;
    };
}crt_sys_pll_ddr_dcc_dq_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_1:3;
    };
}crt_sys_pll_ddr_dcc_dq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_2:3;
    };
}crt_sys_pll_ddr_dcc_dq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_3:3;
    };
}crt_sys_pll_ddr_dcc_dq_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_dbg_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck0_div:3;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck0_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck0_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_preseta:3;
    };
}crt_sys_pll_ddr_dcc_ck0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_dbg_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck1_div:3;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck1_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck1_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_preseta:3;
    };
}crt_sys_pll_ddr_dcc_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_in_dll:32;
    };
}crt_sys_pll_dummy_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_out_dll:32;
    };
}crt_sys_pll_dummy_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_cco_band:2;
        RBus_UInt32  reg_dpi_post_pi_sel2:5;
        RBus_UInt32  reg_dpi_post_pi_sel1:5;
        RBus_UInt32  reg_dpi_post_pi_sel0:5;
        RBus_UInt32  reg_dpi_en_post_pi:8;
        RBus_UInt32  reg_dpi_mck_clk_en:7;
    };
}crt_dc2_sys_pll_ddr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_lpf_sr:3;
        RBus_UInt32  reg_dpi_lpf_cp:1;
        RBus_UInt32  reg_dpi_loop_pi_isel:4;
        RBus_UInt32  reg_dpi_icp:4;
        RBus_UInt32  reg_dpi_post_pi_sel6:5;
        RBus_UInt32  reg_dpi_post_pi_sel5:5;
        RBus_UInt32  reg_dpi_post_pi_sel4:5;
        RBus_UInt32  reg_dpi_post_pi_sel3:5;
    };
}crt_dc2_sys_pll_ddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_n_code:8;
        RBus_UInt32  reg_dpi_en_ssc:1;
        RBus_UInt32  reg_dpi_bypass_pi:1;
        RBus_UInt32  reg_dpi_f_code:11;
        RBus_UInt32  reg_dpi_post_pi_rs:1;
        RBus_UInt32  reg_dpi_post_pi_rl:2;
        RBus_UInt32  reg_dpi_post_pi_bias:2;
        RBus_UInt32  reg_dpi_pll_sel_cpmode:1;
        RBus_UInt32  reg_dpi_pll_ldo_vsel:2;
        RBus_UInt32  reg_dpi_pll_dbug_en:1;
        RBus_UInt32  reg_dpi_pdiv:2;
    };
}crt_dc2_sys_pll_ddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_cco_kvco:1;
        RBus_UInt32  reg_dpi_oc_en:1;
        RBus_UInt32  reg_dpi_oc_step_set:10;
        RBus_UInt32  reg_dpi_f_code_t:11;
        RBus_UInt32  reg_dpi_n_code_t:8;
        RBus_UInt32  reg_dpi_order:1;
    };
}crt_dc2_sys_pll_ddr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dot_gran:3;
        RBus_UInt32  reg_dpi_gran_set:19;
        RBus_UInt32  reg_dpi_oc_done_delay:6;
        RBus_UInt32  reg_dpi_hs_oc_stop_diff:2;
        RBus_UInt32  reg_dpi_sel_oc_mode:2;
    };
}crt_dc2_sys_pll_ddr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_dpi_oesync_op_sel:7;
        RBus_UInt32  reg_dpi_clk_oe:7;
        RBus_UInt32  reg_dpi_time2_rst_width:2;
        RBus_UInt32  reg_dpi_time_rdy_ckout:2;
        RBus_UInt32  reg_dpi_time0_ck:3;
        RBus_UInt32  reg_dpi_f390k:2;
        RBus_UInt32  reg_dpi_wd_enable:1;
        RBus_UInt32  reg_dpi_gran_auto_rst:1;
    };
}crt_dc2_sys_pll_ddr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_stable:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  reg_dpi_pll_en:1;
        RBus_UInt32  reg_dpi_ng_clk_sel:2;
        RBus_UInt32  reg_dpi_v11_ldo_vsel:2;
        RBus_UInt32  reg_dpi_post_pi_sel:5;
        RBus_UInt32  reg_dpi_adj_div2_en:1;
        RBus_UInt32  reg_dpi_ckref_sel:1;
        RBus_UInt32  reg_dpi_dat_rate_sel:1;
        RBus_UInt32  reg_dpi_adr_rate_sel:1;
        RBus_UInt32  reg_dpi_pll_dum:8;
    };
}crt_dc2_sys_pll_ddr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_dbg_sel:1;
        RBus_UInt32  reg_dpi_dcc_cmd_div:3;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_cmd_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_cmd_duty:7;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_preseta:3;
    };
}crt_dc2_sys_pll_ddr_dcc_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_0:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_0:6;
        RBus_UInt32  reg_dpi_dll_int_gain_0:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_0:1;
        RBus_UInt32  reg_dpi_dll_dly_0:9;
        RBus_UInt32  reg_dpi_dll_init_value_0:8;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_1:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_1:6;
        RBus_UInt32  reg_dpi_dll_int_gain_1:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_1:1;
        RBus_UInt32  reg_dpi_dll_dly_1:9;
        RBus_UInt32  reg_dpi_dll_init_value_1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_2:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_2:6;
        RBus_UInt32  reg_dpi_dll_int_gain_2:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_2:1;
        RBus_UInt32  reg_dpi_dll_dly_2:9;
        RBus_UInt32  reg_dpi_dll_init_value_2:8;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_dpi_dll_en_pdout_3:1;
        RBus_UInt32  reg_dpi_dll_ph90_sft_3:6;
        RBus_UInt32  reg_dpi_dll_int_gain_3:5;
        RBus_UInt32  reg_dpi_dll_dly_sel_3:1;
        RBus_UInt32  reg_dpi_dll_dly_3:9;
        RBus_UInt32  reg_dpi_dll_init_value_3:8;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_0:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_0:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_0:5;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_1:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_1:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_1:5;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_2:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_2:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_2:5;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  alert_rx_rst_n_3:1;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_3:5;
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_3:5;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_0:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_1:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_2:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_3:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_0:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_1:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_2:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dq_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_3:3;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_dbg_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck0_div:3;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck0_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck0_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_preseta:3;
    };
}crt_dc2_sys_pll_ddr_dcc_ck0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_dbg_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck1_div:3;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck1_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck1_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_preseta:3;
    };
}crt_dc2_sys_pll_ddr_dcc_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_in_dll:32;
    };
}crt_dc2_sys_pll_dummy_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_out_dll:32;
    };
}crt_dc2_sys_pll_dummy_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_field_flag_mode_en:1;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  res1:12;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  dummy18000640_3:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy18000640_1:1;
        RBus_UInt32  dclk_ss_en:1;
    };
}crt_sys_dclkss_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dclk_freq_syn_slt:14;
        RBus_UInt32  res2:11;
        RBus_UInt32  fll_tracking_en:1;
        RBus_UInt32  in_frame_tracking_offset_inverse:1;
        RBus_UInt32  in_frame_tracking_ypbpr_en:1;
        RBus_UInt32  in_frame_tracking_vd_dec_en:1;
        RBus_UInt32  in_frame_tracking_general_en:1;
    };
}crt_dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  in_frame_tracking_mul:19;
    };
}crt_dpll_in_fsync_tracking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_neg_th:16;
        RBus_UInt32  in_frame_tracking_pos_th:16;
    };
}crt_dpll_in_fsync_tracking_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  frc2fsync_speed_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  frc2fsync_speedup_offset:13;
    };
}crt_dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  final_profile:18;
    };
}crt_dpll_status_ro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000658_31_12:20;
        RBus_UInt32  dclk_profile_remap_cnt:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  dclk_profile_remap_en:1;
    };
}crt_dclkss_profile_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_1:16;
        RBus_UInt32  dclk_profile_remap_0:16;
    };
}crt_dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_3:16;
        RBus_UInt32  dclk_profile_remap_2:16;
    };
}crt_dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_5:16;
        RBus_UInt32  dclk_profile_remap_4:16;
    };
}crt_dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_7:16;
        RBus_UInt32  dclk_profile_remap_6:16;
    };
}crt_dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_9:16;
        RBus_UInt32  dclk_profile_remap_8:16;
    };
}crt_dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_11:16;
        RBus_UInt32  dclk_profile_remap_10:16;
    };
}crt_dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_13:16;
        RBus_UInt32  dclk_profile_remap_12:16;
    };
}crt_dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_15:16;
        RBus_UInt32  dclk_profile_remap_14:16;
    };
}crt_dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_17:16;
        RBus_UInt32  dclk_profile_remap_16:16;
    };
}crt_dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_19:16;
        RBus_UInt32  dclk_profile_remap_18:16;
    };
}crt_dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_21:16;
        RBus_UInt32  dclk_profile_remap_20:16;
    };
}crt_dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_23:16;
        RBus_UInt32  dclk_profile_remap_22:16;
    };
}crt_dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_25:16;
        RBus_UInt32  dclk_profile_remap_24:16;
    };
}crt_dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_27:16;
        RBus_UInt32  dclk_profile_remap_26:16;
    };
}crt_dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_29:16;
        RBus_UInt32  dclk_profile_remap_28:16;
    };
}crt_dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_31:16;
        RBus_UInt32  dclk_profile_remap_30:16;
    };
}crt_dclkss_profile15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  double_buf_read_sel:1;
        RBus_UInt32  double_buf_apply:1;
    };
}crt_dpll_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fcode_t_ssc:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  oc_step_set:10;
        RBus_UInt32  res3:3;
        RBus_UInt32  oc_en:1;
    };
}crt_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hs_oc_stop_diff:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  sel_oc_mode:2;
        RBus_UInt32  res4:8;
    };
}crt_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  en_pi_debug:1;
        RBus_UInt32  sdm_order:1;
        RBus_UInt32  bypass_pi:1;
    };
}crt_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  fcode_ssc:11;
    };
}crt_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  en_ssc:1;
    };
}crt_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fcode_debug:11;
        RBus_UInt32  ncode_debug:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  oc_done:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  load_fcw:1;
        RBus_UInt32  fmod:1;
    };
}crt_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  dpll_ssc_inv:1;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_cs:2;
    };
}crt_sys_pll_disp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dpll_x_bpspi:1;
        RBus_UInt32  dpll_x_bpsin:1;
    };
}crt_sys_pll_disp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dpll_ldosel:2;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  dpll_fupdn:1;
        RBus_UInt32  dpll_stop:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  dpll_bpphs:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  dpll_bpn:1;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  res5:5;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_pow:1;
    };
}crt_sys_pll_disp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dpll_ldodpll_pow:1;
        RBus_UInt32  dpll_pi_ibsel:2;
    };
}crt_sys_pll_disp4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_flag:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  sscg_offset_over_th_value:17;
    };
}crt_dpll_in_fsync_tracking_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  sscg_offset_over_th_max:17;
    };
}crt_dpll_in_fsync_tracking_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_offset_over_flag:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  new_fll_offset_over_th_value:17;
    };
}crt_dpll_in_fsync_tracking_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  new_fll_offset_over_th_max:17;
    };
}crt_dpll_in_fsync_tracking_debug3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  new_fll_tracking_offset_inverse:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  new_fll_tracking_mul:19;
    };
}crt_dpll_in_fsync_tracking_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_tracking_neg_th:16;
        RBus_UInt32  new_fll_tracking_pos_th:16;
    };
}crt_dpll_in_fsync_tracking_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_emmc_ckssc_inv:1;
        RBus_UInt32  pllscp:1;
        RBus_UInt32  pllscs:2;
        RBus_UInt32  pllsrs:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  pllsdiv2:1;
        RBus_UInt32  pllssi:5;
        RBus_UInt32  pllsnbp:1;
        RBus_UInt32  pllsn:3;
        RBus_UInt32  res3:7;
        RBus_UInt32  pllallrstb:1;
    };
}crt_emmc_pll_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  reg_pll_tp2_mux:3;
        RBus_UInt32  reg_pll_tp1_mux:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllemmc_rsvd:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllsstatus:1;
        RBus_UInt32  pllswdrst:1;
        RBus_UInt32  pllswdset:1;
        RBus_UInt32  pllemmc_reg:2;
        RBus_UInt32  pllemmcldopow:1;
        RBus_UInt32  pllemmcpwdn:1;
    };
}crt_emmc_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_pi_autoset:1;
        RBus_UInt32  pllsd2x_3:1;
        RBus_UInt32  pllsd2y_3:1;
        RBus_UInt32  pllsx_3:1;
        RBus_UInt32  pllsy_3:1;
        RBus_UInt32  pllssck_3:6;
        RBus_UInt32  pllsd2x_2:1;
        RBus_UInt32  pllsd2y_2:1;
        RBus_UInt32  pllsx_2:1;
        RBus_UInt32  pllsy_2:1;
        RBus_UInt32  pllssck_2:6;
        RBus_UInt32  pllsd2x:1;
        RBus_UInt32  pllsd2y:1;
        RBus_UInt32  pllsx:1;
        RBus_UInt32  pllsy:1;
        RBus_UInt32  pllssck:6;
    };
}crt_emmc_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  pllsphrl:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllsphrs:3;
    };
}crt_emmc_pll_phase_interpolation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  pllemmc_oc_step_set:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllemmc_oc_en:1;
    };
}crt_emmc_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  pllemmc_oc_done_delay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllemmc_hs_oc_stop_diff:2;
        RBus_UInt32  pllemmc_pi_cur_sel:2;
        RBus_UInt32  pllemmc_sel_oc_mode:2;
        RBus_UInt32  res3:8;
    };
}crt_emmc_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  pllemmc_en_pi_debug:1;
        RBus_UInt32  pllemmc_sdm_order:1;
        RBus_UInt32  pllemmc_bypass_pi:1;
    };
}crt_emmc_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllemmc_ncode_ssc:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllemmc_fcode_ssc:11;
    };
}crt_emmc_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllemmc_ncode_t:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  pllemmc_fcode_t:11;
    };
}crt_emmc_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_gran_auto_rst:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllemmc_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllemmc_gran_est:19;
        RBus_UInt32  res4:3;
        RBus_UInt32  pllemmc_en_ssc:1;
    };
}crt_emmc_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pllemmc_fcode_debug:11;
        RBus_UInt32  pllemmc_ncode_debug:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllemmc_oc_done:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pllemmc_fmod:1;
    };
}crt_emmc_pll_ssc6_RBUS;

#else //apply LITTLE_ENDIAN

//======CRT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_pllreg:1;
        RBus_UInt32  rstn_scpu:1;
        RBus_UInt32  rstn_ae:1;
        RBus_UInt32  rstn_vcpu:1;
        RBus_UInt32  rstn_ve:1;
        RBus_UInt32  rstn_ve_p2:1;
        RBus_UInt32  rstn_vde:1;
        RBus_UInt32  rstn_scpu_wrap:1;
        RBus_UInt32  rstn_ib_tvsb5:1;
        RBus_UInt32  rstn_ib_tvsb4:1;
        RBus_UInt32  rstn_ib_tvsb3:1;
        RBus_UInt32  rstn_ib_tvsb2:1;
        RBus_UInt32  rstn_acpu:1;
        RBus_UInt32  rstn_vp9:1;
        RBus_UInt32  rstn_vcpu2:1;
        RBus_UInt32  rstn_ve2:1;
        RBus_UInt32  rstn_ve2_p2:1;
        RBus_UInt32  rstn_vde2:1;
        RBus_UInt32  rstn_kcpu:1;
        RBus_UInt32  rstn_ib_gpu:1;
        RBus_UInt32  rstn_kt:1;
        RBus_UInt32  rstn_sce:1;
        RBus_UInt32  rstn_dsc:1;
        RBus_UInt32  rstn_akl:1;
        RBus_UInt32  rstn_nd:1;
        RBus_UInt32  rstn_ib_tvsb1:1;
        RBus_UInt32  rstn_ib_vp9:1;
        RBus_UInt32  rstn_ib_ve2:1;
        RBus_UInt32  rstn_ib_ve:1;
        RBus_UInt32  rstn_ib_sb3:1;
        RBus_UInt32  rstn_ib_sb2:1;
        RBus_UInt32  rstn_ib_sb1:1;
    };
}crt_sys_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_disp:1;
        RBus_UInt32  rstn_dispim:1;
        RBus_UInt32  rstn_vodma:1;
        RBus_UInt32  rstn_3d_gde:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_se:1;
        RBus_UInt32  rstn_md:1;
        RBus_UInt32  rstn_cp:1;
        RBus_UInt32  rstn_tp:1;
        RBus_UInt32  rstn_hdmitx:1;
        RBus_UInt32  rstn_hdmi:1;
        RBus_UInt32  rstn_apll_adc:1;
        RBus_UInt32  rstn_me:1;
        RBus_UInt32  rstn_offms:1;
        RBus_UInt32  rstn_cbus:1;
        RBus_UInt32  rstn_ifadc:1;
        RBus_UInt32  rstn_audio:1;
        RBus_UInt32  rstn_audio_dac:1;
        RBus_UInt32  rstn_audio_adc:1;
        RBus_UInt32  rstn_audio2_dac:1;
        RBus_UInt32  rstn_vbis0:1;
        RBus_UInt32  rstn_vdec2:1;
        RBus_UInt32  rstn_vdec:1;
        RBus_UInt32  rstn_if_demod:1;
        RBus_UInt32  rstn_dcu:1;
        RBus_UInt32  rstn_dcphy:1;
        RBus_UInt32  rstn_tve:1;
        RBus_UInt32  rstn_tvsb5:1;
        RBus_UInt32  rstn_tvsb4:1;
        RBus_UInt32  rstn_tvsb3:1;
        RBus_UInt32  rstn_tvsb2:1;
        RBus_UInt32  rstn_tvsb1:1;
    };
}crt_sys_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_pc:1;
        RBus_UInt32  rstn_sc:1;
        RBus_UInt32  rstn_nf:1;
        RBus_UInt32  rstn_i2c2:1;
        RBus_UInt32  rstn_i2c1:1;
        RBus_UInt32  rstn_gpio:1;
        RBus_UInt32  rstn_sc1:1;
        RBus_UInt32  rstn_uart2:1;
        RBus_UInt32  rstn_uart1:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_misc:1;
        RBus_UInt32  rstn_dtv_demod:1;
        RBus_UInt32  rstn_padmux:1;
        RBus_UInt32  rstn_irtx:1;
        RBus_UInt32  dummy18000108_15:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_otg:1;
        RBus_UInt32  rstn_usb:1;
        RBus_UInt32  dummy18000108_20:2;
        RBus_UInt32  rstn_bistreg:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rstn_emmc:1;
        RBus_UInt32  dummy18000108_25:2;
        RBus_UInt32  rstn_atvin:1;
        RBus_UInt32  rstn_atvin2:1;
        RBus_UInt32  rstn_tm:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
    };
}crt_sys_srst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_usb3_phy_p0:1;
        RBus_UInt32  rstn_usb3_mdio_p0:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rstn_usb2_phy_p0:1;
        RBus_UInt32  rstn_usb2_phy_p1:1;
        RBus_UInt32  rstn_usb2_phy_p2:1;
        RBus_UInt32  rstn_usb2_phy_p3:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  rstn_hdmitx_pll:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rstn_sd:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  res4:6;
        RBus_UInt32  rstn_dcu2:1;
        RBus_UInt32  rstn_dcphy2:1;
        RBus_UInt32  res5:6;
    };
}crt_sys_srst3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_pllreg:1;
        RBus_UInt32  clken_scpu:1;
        RBus_UInt32  clken_scpu_wrap:1;
        RBus_UInt32  clken_vcpu:1;
        RBus_UInt32  clken_ve:1;
        RBus_UInt32  clken_ve_p2:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  clken_acpu:1;
        RBus_UInt32  clken_vp9:1;
        RBus_UInt32  clken_vcpu2:1;
        RBus_UInt32  clken_ve2:1;
        RBus_UInt32  clken_ve2_p2:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  clken_kcpu:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  clken_kt:1;
        RBus_UInt32  clken_sce:1;
        RBus_UInt32  clken_dsc:1;
        RBus_UInt32  clken_akl:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:2;
    };
}crt_sys_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_disp:1;
        RBus_UInt32  clken_dispim:1;
        RBus_UInt32  clken_vodma:1;
        RBus_UInt32  clken_3d_gde:1;
        RBus_UInt32  clken_tp_div:1;
        RBus_UInt32  clken_se:1;
        RBus_UInt32  clken_md:1;
        RBus_UInt32  clken_cp:1;
        RBus_UInt32  clken_tp:1;
        RBus_UInt32  clken_hdmitx:1;
        RBus_UInt32  clken_hdmi:1;
        RBus_UInt32  clken_apll_adc:1;
        RBus_UInt32  clken_me:1;
        RBus_UInt32  clken_offms:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_ifadc:1;
        RBus_UInt32  clken_audio:1;
        RBus_UInt32  clken_audio_pre512fs:1;
        RBus_UInt32  dummy18000114_19:2;
        RBus_UInt32  clken_vbis0:1;
        RBus_UInt32  clken_se2:1;
        RBus_UInt32  clken_vdec:1;
        RBus_UInt32  clken_if_demod:1;
        RBus_UInt32  clken_dcu:1;
        RBus_UInt32  clken_dcphy:1;
        RBus_UInt32  clken_tve:1;
        RBus_UInt32  clken_tvsb5:1;
        RBus_UInt32  clken_tvsb4:1;
        RBus_UInt32  clken_tvsb3:1;
        RBus_UInt32  clken_tvsb2:1;
        RBus_UInt32  clken_tvsb1:1;
    };
}crt_sys_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_pc:1;
        RBus_UInt32  clken_sc:1;
        RBus_UInt32  clken_nf:1;
        RBus_UInt32  clken_i2c2:1;
        RBus_UInt32  clken_i2c1:1;
        RBus_UInt32  clken_gpio:1;
        RBus_UInt32  clken_sc1:1;
        RBus_UInt32  clken_uart2:1;
        RBus_UInt32  clken_uart1:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_misc:1;
        RBus_UInt32  clken_dtv_demod:1;
        RBus_UInt32  clken_padmux:1;
        RBus_UInt32  clken_irtx:1;
        RBus_UInt32  dummy18000118_14:1;
        RBus_UInt32  clken_audio2_512fs:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  clken_otg:1;
        RBus_UInt32  clken_usb:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_bistreg:1;
        RBus_UInt32  clken_efuse:1;
        RBus_UInt32  clken_emmc:1;
        RBus_UInt32  dummy18000118_25:2;
        RBus_UInt32  clken_atvin_ifd:1;
        RBus_UInt32  clken_atvin_vd:1;
        RBus_UInt32  clken_tm:1;
        RBus_UInt32  res4:3;
    };
}crt_sys_clken2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_audio_ad_128fs:1;
        RBus_UInt32  clken_audio_ad_256fs:1;
        RBus_UInt32  clken_audio_da0_128fs:1;
        RBus_UInt32  clken_audio_da0_256fs:1;
        RBus_UInt32  clken_audio_da1_128fs:1;
        RBus_UInt32  clken_audio_da1_256fs:1;
        RBus_UInt32  clken_audio_dma_r_512fs:1;
        RBus_UInt32  clken_audio2_dma_r_512fs:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  clken_sd:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  clken_dcu2:1;
        RBus_UInt32  clken_dcphy2:1;
        RBus_UInt32  res3:6;
    };
}crt_sys_clken3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_clksel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ejtag_mode:1;
        RBus_UInt32  res3:27;
    };
}crt_sys_cpusel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uart_clksel:1;
        RBus_UInt32  inv_vbis0_clk:1;
        RBus_UInt32  vbis0_yppsel:1;
        RBus_UInt32  vdec_x27_clksel:1;
        RBus_UInt32  tp_pre_div:4;
        RBus_UInt32  tp_post_div:4;
        RBus_UInt32  cbus_clksel:1;
        RBus_UInt32  tve_108m_clk_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  atvin_vdadc_tve_clk_sel:1;
        RBus_UInt32  atvin_vd_clk_sel:1;
        RBus_UInt32  atvin_clk_sel:1;
        RBus_UInt32  ve2_rif_use_p2clk:1;
        RBus_UInt32  ve_rif_use_p2clk:1;
        RBus_UInt32  sd_clk_div:3;
        RBus_UInt32  dpll_clksel:2;
        RBus_UInt32  epi_dbg_clksel:1;
        RBus_UInt32  pcr108_clksel:1;
        RBus_UInt32  sd_emmc_clk_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  dtv_rbus_i2c_sel:1;
        RBus_UInt32  pll_bypass_ref_clk_mode:1;
    };
}crt_sys_clksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_disp_5k:1;
        RBus_UInt32  clken_disp_osd:1;
        RBus_UInt32  clken_disp_video:1;
        RBus_UInt32  clken_disp_gdma:1;
        RBus_UInt32  clken_disp_sfg:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dispd_osd_div:2;
        RBus_UInt32  dummy18000208_11:2;
        RBus_UInt32  dispd_video_div:2;
        RBus_UInt32  dispd_gdma_clk_sel:1;
        RBus_UInt32  hdmitx_clksel:2;
        RBus_UInt32  res2:7;
        RBus_UInt32  res3:8;
    };
}crt_sys_dispclksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aud_dtv_freq_sel:3;
        RBus_UInt32  demod_i2c_saddr_sel:1;
        RBus_UInt32  aud_dtv2_freq_sel:3;
        RBus_UInt32  dtv_demod_multi_req_disable:1;
        RBus_UInt32  nf_clksel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  hdmi_tmds_div:2;
        RBus_UInt32  res2:18;
    };
}crt_sys_clkdiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scpu_wd_cnt:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  scpu_wd_en:1;
        RBus_UInt32  res2:15;
    };
}crt_sys_arm_wd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800021c_31_0:32;
    };
}crt_sys_tvsb1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:4;
        RBus_UInt32  clkratio_acpu_active:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  clkratio_acpu:4;
        RBus_UInt32  clkratio_vcpu_active:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  clkratio_vcpu:4;
        RBus_UInt32  res6:8;
    };
}crt_sys_dyn_sw_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  efuse_ready:1;
        RBus_UInt32  res1:31;
    };
}crt_efuse_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtv_str_pow:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dtv_str_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dtv_iso_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  atv_str_pow:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  atv_str_status:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  atv_iso_en:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
        RBus_UInt32  res17:1;
        RBus_UInt32  res18:5;
    };
}crt_power_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_a:29;
        RBus_UInt32  res1:3;
    };
}crt_temp_sensor_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_dsr:3;
        RBus_UInt32  tm_cksourcesel:1;
        RBus_UInt32  tm_chopen:1;
        RBus_UInt32  tm_biaschop:1;
        RBus_UInt32  tm_cal_en:1;
        RBus_UInt32  tm_adccksel:3;
        RBus_UInt32  tm_b:22;
    };
}crt_temp_sensor_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tm_pow:1;
        RBus_UInt32  tm_offset:22;
        RBus_UInt32  tm_order3:1;
        RBus_UInt32  tm_hold_en:1;
        RBus_UInt32  tm_filteredgesel:1;
        RBus_UInt32  tm_en_chop:1;
    };
}crt_temp_sensor_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_resol:2;
        RBus_UInt32  tm_osccursel:2;
        RBus_UInt32  tm_hold_dly:2;
        RBus_UInt32  tm_opcursel:2;
        RBus_UInt32  tm_r:24;
    };
}crt_temp_sensor_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  tm_chop_swcnt:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  tm_chopfreqsel:11;
        RBus_UInt32  tm_vbe_biassel:2;
        RBus_UInt32  tm_vcmsel:3;
        RBus_UInt32  tm_test_en:1;
        RBus_UInt32  tm_sdm_test_en:1;
        RBus_UInt32  tm_sdm_test:1;
        RBus_UInt32  tm_rstb:1;
    };
}crt_temp_sensor_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_compare_dly:16;
        RBus_UInt32  tm_sample_dly:16;
    };
}crt_temp_sensor_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_valid_edge_sel:1;
        RBus_UInt32  td_wrep_edge_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  tm_biasdem_sel:1;
        RBus_UInt32  tm_scan_mode:1;
        RBus_UInt32  tm_sw2_sw3_reverse:1;
        RBus_UInt32  tm_en:1;
        RBus_UInt32  tm_sos:3;
        RBus_UInt32  tm_sinl:2;
        RBus_UInt32  tm_sbg:3;
        RBus_UInt32  tm_reverse_cmp_out:1;
        RBus_UInt32  tm_pwron_dly:16;
    };
}crt_temp_sensor_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tm_s:23;
        RBus_UInt32  res1:9;
    };
}crt_temp_sensor_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ct_out_o_tm:19;
        RBus_UInt32  res1:5;
        RBus_UInt32  data_out_tm:7;
        RBus_UInt32  res2:1;
    };
}crt_thermal_result_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_out_tm:22;
        RBus_UInt32  res1:10;
    };
}crt_thermal_result_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_int_scpu_routing_en:1;
        RBus_UInt32  apll_dds_int_scpu_routing_en:1;
        RBus_UInt32  dispi_int_scpu_routing_en:1;
        RBus_UInt32  dispm_int_scpu_routing_en:1;
        RBus_UInt32  if_demod_int_scpu_routing_en:1;
        RBus_UInt32  vdec_int_scpu_routing_en:1;
        RBus_UInt32  vbi_int_scpu_routing_en:1;
        RBus_UInt32  dctl_int_scpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_scpu_routing_en:1;
        RBus_UInt32  osd_int_scpu_routing_en:1;
        RBus_UInt32  tve_int_scpu_routing_en:1;
        RBus_UInt32  dc_int_scpu_routing_en:1;
        RBus_UInt32  dcphy_int_scpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_scpu_routing_en:1;
        RBus_UInt32  audio_irq_scpu_routing_en:1;
        RBus_UInt32  audio_dma_irq_scpu_routing_en:1;
        RBus_UInt32  sd_int_scpu_routing_en:1;
        RBus_UInt32  etn_int_scpu_routing_en:1;
        RBus_UInt32  otg_int_scpu_routing_en:1;
        RBus_UInt32  usb3_int_scpu_routing_en:1;
        RBus_UInt32  akl_int_scpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cec_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_scpu_routing_en:1;
        RBus_UInt32  standby_wdog_int_scpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_scpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_scpu_routing_en:1;
        RBus_UInt32  dummy18000290_29:1;
        RBus_UInt32  dummy18000290_30:1;
        RBus_UInt32  smartcard_int_scpu_routing_en:1;
    };
}crt_int_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_int_vcpu_routing_en:1;
        RBus_UInt32  apll_dds_int_vcpu_routing_en:1;
        RBus_UInt32  dispi_int_vcpu_routing_en:1;
        RBus_UInt32  dispm_int_vcpu_routing_en:1;
        RBus_UInt32  if_demod_int_vcpu_routing_en:1;
        RBus_UInt32  vdec_int_vcpu_routing_en:1;
        RBus_UInt32  vbi_int_vcpu_routing_en:1;
        RBus_UInt32  dctl_int_vcpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_vcpu_routing_en:1;
        RBus_UInt32  osd_int_vcpu_routing_en:1;
        RBus_UInt32  tve_int_vcpu_routing_en:1;
        RBus_UInt32  dc_int_vcpu_routing_en:1;
        RBus_UInt32  dcphy_int_vcpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_vcpu_routing_en:1;
        RBus_UInt32  dummy18000294_14:1;
        RBus_UInt32  dummy18000294_15:1;
        RBus_UInt32  dummy18000294_16:1;
        RBus_UInt32  dummy18000294_17:1;
        RBus_UInt32  dummy18000294_18:1;
        RBus_UInt32  dummy18000294_19:1;
        RBus_UInt32  dummy18000294_20:1;
        RBus_UInt32  dummy18000294_21:1;
        RBus_UInt32  dummy18000294_22:1;
        RBus_UInt32  dummy18000294_23:1;
        RBus_UInt32  dummy18000294_24:1;
        RBus_UInt32  dummy18000294_25:1;
        RBus_UInt32  dummy18000294_26:1;
        RBus_UInt32  dummy18000294_27:1;
        RBus_UInt32  dummy18000294_28:1;
        RBus_UInt32  vodma_int_vcpu_routing_en:1;
        RBus_UInt32  disp2tve_int_vcpu_routing_en:1;
        RBus_UInt32  res1:1;
    };
}crt_int_ctrl_vcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hdmi_irq_scpu_routing_en:1;
        RBus_UInt32  hdmi_irq_vcpu_routing_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  memc_int_scpu_routing_en:1;
        RBus_UInt32  dummy180002a0_21_21:1;
        RBus_UInt32  dummy180002a0_22_22:1;
        RBus_UInt32  dummy180002a0_23_23:1;
        RBus_UInt32  memc_int_vcpu2_routing_en:1;
        RBus_UInt32  dummy180002a0_25_25:1;
        RBus_UInt32  dummy180002a0_26_26:1;
        RBus_UInt32  dummy180002a0_27_27:1;
        RBus_UInt32  memc_int_vcpu_routing_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
    };
}int_ctrl_memc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000298_0:1;
        RBus_UInt32  dummy18000298_1:1;
        RBus_UInt32  dummy18000298_2:1;
        RBus_UInt32  dummy18000298_3:1;
        RBus_UInt32  dummy18000298_4:1;
        RBus_UInt32  dummy18000298_5:1;
        RBus_UInt32  dummy18000298_6:1;
        RBus_UInt32  dummy18000298_7:1;
        RBus_UInt32  dummy18000298_8:1;
        RBus_UInt32  dummy18000298_9:1;
        RBus_UInt32  dummy18000298_10:1;
        RBus_UInt32  dc_int_acpu_routing_en:1;
        RBus_UInt32  dcphy_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_acpu_routing_en:1;
        RBus_UInt32  audio_irq_acpu_routing_en:1;
        RBus_UInt32  audio_dma_irq_acpu_routing_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  res16:1;
    };
}crt_int_ctrl_acpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ddc_int_kcpu_routing_en:1;
        RBus_UInt32  apll_dds_int_kcpu_routing_en:1;
        RBus_UInt32  dispi_int_kcpu_routing_en:1;
        RBus_UInt32  dispm_int_kcpu_routing_en:1;
        RBus_UInt32  if_demod_int_kcpu_routing_en:1;
        RBus_UInt32  vdec_int_kcpu_routing_en:1;
        RBus_UInt32  vbi_int_kcpu_routing_en:1;
        RBus_UInt32  dctl_int_kcpu_routing_en:1;
        RBus_UInt32  ultra_zoom_int_kcpu_routing_en:1;
        RBus_UInt32  osd_int_kcpu_routing_en:1;
        RBus_UInt32  tve_int_kcpu_routing_en:1;
        RBus_UInt32  dc_int_kcpu_routing_en:1;
        RBus_UInt32  dcphy_int_kcpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_kcpu_routing_en:1;
        RBus_UInt32  dummy1800029c_14:1;
        RBus_UInt32  dummy1800029c_15:1;
        RBus_UInt32  sd_int_kcpu_routing_en:1;
        RBus_UInt32  etn_int_kcpu_routing_en:1;
        RBus_UInt32  otg_int_kcpu_routing_en:1;
        RBus_UInt32  usb3_int_kcpu_routing_en:1;
        RBus_UInt32  akl_int_kcpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_kcpu_routing_en:1;
        RBus_UInt32  standby_cec_int_kcpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_kcpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_kcpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_kcpu_routing_en:1;
        RBus_UInt32  standby_wdog_int_kcpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_kcpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_kcpu_routing_en:1;
        RBus_UInt32  vodma_int_kcpu_routing_en:1;
        RBus_UInt32  disp2tve_int_kcpu_routing_en:1;
        RBus_UInt32  smartcard_int_kcpu_routing_en:1;
    };
}crt_int_ctrl_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_ip_c30_7t_count_out:20;
        RBus_UInt32  main_ip_c30_7t_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  main_ip_c30_7t_wire_sel:1;
        RBus_UInt32  main_ip_c30_7t_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  main_ip_c30_7t_dss_rst_n:1;
    };
}crt_ss_mainip_c30_7t_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_ip_c30_7t_data_in:20;
        RBus_UInt32  main_ip_c30_7t_wsort_go:1;
        RBus_UInt32  main_ip_c30_7t_speed_en:1;
        RBus_UInt32  res1:10;
    };
}crt_ss_mainip_c30_7t_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_ip_c30_7t_dbgo:16;
        RBus_UInt32  res1:16;
    };
}crt_ss_mainip_c30_7t_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c35_9p5t_count_out:20;
        RBus_UInt32  dispd_c35_9p5t_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dispd_c35_9p5t_wire_sel:1;
        RBus_UInt32  dispd_c35_9p5t_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dispd_c35_9p5t_dss_rst_n:1;
    };
}crt_ss_dispd_c35_9p5t_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c35_9p5t_data_in:20;
        RBus_UInt32  dispd_c35_9p5t_wsort_go:1;
        RBus_UInt32  dispd_c35_9p5t_speed_en:1;
        RBus_UInt32  res1:10;
    };
}crt_ss_dispd_c35_9p5t_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c35_9p5t_dbgo:16;
        RBus_UInt32  res1:16;
    };
}crt_ss_dispd_c35_9p5t_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c31_9p5t_count_out:20;
        RBus_UInt32  dispd_c31_9p5t_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dispd_c31_9p5t_wire_sel:1;
        RBus_UInt32  dispd_c31_9p5t_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dispd_c31_9p5t_dss_rst_n:1;
    };
}crt_ss_dispd_c31_9p5t_rlvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c31_9p5t_data_in:20;
        RBus_UInt32  dispd_c31_9p5t_wsort_go:1;
        RBus_UInt32  dispd_c31_9p5t_speed_en:1;
        RBus_UInt32  res1:10;
    };
}crt_ss_dispd_c31_9p5t_rlvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_c31_9p5t_dbgo:16;
        RBus_UInt32  res1:16;
    };
}crt_ss_dispd_c35_9p5t_rlvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_c35_9p5t_count_out:20;
        RBus_UInt32  acpu_c35_9p5t_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  acpu_c35_9p5t_wire_sel:1;
        RBus_UInt32  acpu_c35_9p5t_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  acpu_c35_9p5t_dss_rst_n:1;
    };
}crt_ss_acpu_c35_9p5t_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_c35_9p5t_data_in:20;
        RBus_UInt32  acpu_c35_9p5t_wsort_go:1;
        RBus_UInt32  acpu_c35_9p5t_speed_en:1;
        RBus_UInt32  res1:10;
    };
}crt_ss_acpu_c35_9p5t_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acpu_c35_9p5t_dbgo:16;
        RBus_UInt32  res1:16;
    };
}crt_ss_acpu_c35_9p5t_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demod_voltage_strobe_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  main_voltage_strobe_en:1;
        RBus_UInt32  res2:27;
    };
}crt_voltage_strobe_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crt_dbg_sel:8;
        RBus_UInt32  top_ssc_dbg_sel:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  dbg0_div_sel:2;
        RBus_UInt32  res2:14;
    };
}crt_sc_debug_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_wdmode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsb_o:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  pllddsb_cp:2;
        RBus_UInt32  pllddsb_cs:2;
        RBus_UInt32  pllddsb_rs:3;
        RBus_UInt32  pllddsb_ip:4;
        RBus_UInt32  res4:6;
        RBus_UInt32  pllddsb_n:2;
    };
}crt_sys_pll_dispb_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_pow:1;
        RBus_UInt32  pllddsb_rstb:1;
        RBus_UInt32  pllddsb_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllddsb_ncode:8;
        RBus_UInt32  pllddsb_fcode:11;
        RBus_UInt32  res3:5;
    };
}crt_sys_pll_dispb_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy18000358_10_10:1;
        RBus_UInt32  pllddsb_pstst:1;
        RBus_UInt32  pllddsb_tst:1;
        RBus_UInt32  dummy18000358_13_13:1;
        RBus_UInt32  pllddsb_vcorb:1;
        RBus_UInt32  dummy18000358_15_15:1;
        RBus_UInt32  dummy18000358_16_16:1;
        RBus_UInt32  dummy18000358_17_17:1;
        RBus_UInt32  dummy18000358_18_18:1;
        RBus_UInt32  dummy18000358_19_19:1;
        RBus_UInt32  dummy18000358_20_20:1;
        RBus_UInt32  dummy18000358_21_21:1;
        RBus_UInt32  dummy18000358_22_22:1;
        RBus_UInt32  dummy18000358_23_23:1;
        RBus_UInt32  dummy18000358_24_24:1;
        RBus_UInt32  dummy18000358_28_25:4;
        RBus_UInt32  res2:3;
    };
}crt_sys_pll_dispb_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud2b_rstb:1;
        RBus_UInt32  psaud2b_oeb:1;
        RBus_UInt32  psaud1b_rstb:1;
        RBus_UInt32  psaud1b_oeb:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  psaud2b_psen:1;
        RBus_UInt32  psaud2b_tst:1;
        RBus_UInt32  psaud2b_div:1;
        RBus_UInt32  psaud2b_fupdn:1;
        RBus_UInt32  dummy1800035c_24:1;
        RBus_UInt32  psaud1b_psen:1;
        RBus_UInt32  psaud1b_tst:1;
        RBus_UInt32  dummy1800035c_27:1;
        RBus_UInt32  psaud1b_div:1;
        RBus_UInt32  psaud1b_fupdn:1;
        RBus_UInt32  dummy1800035c_30:1;
        RBus_UInt32  res2:1;
    };
}crt_sys_pll_dispb_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_oc_en:1;
        RBus_UInt32  pllddsb_oc_done:1;
        RBus_UInt32  pllddsb_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllddsb_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsb_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsb_sel_oc_mode:2;
        RBus_UInt32  pllddsb_pi_cur_sel:2;
        RBus_UInt32  pllddsb_hs_oc_stop:2;
        RBus_UInt32  pllddsb_en_pi_debug:1;
        RBus_UInt32  pllddsb_bypass_pi:1;
    };
}crt_sys_dvfs_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsb_ncode_dbg:8;
        RBus_UInt32  pllddsb_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}crt_sys_dvfs_ddsb2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_b:1;
        RBus_UInt32  sd_b:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs_b:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc_b:1;
        RBus_UInt32  tmps_b:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme_b:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce_b:1;
        RBus_UInt32  res5:6;
    };
}crt_ai_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_b_2:1;
        RBus_UInt32  sd_b_2:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs_b_2:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc_b_2:1;
        RBus_UInt32  tmps_b_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme_b_2:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce_b_2:1;
        RBus_UInt32  res5:6;
    };
}crt_ai2_b_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllkcpu_rs:3;
        RBus_UInt32  pllkcpu_cs:2;
        RBus_UInt32  pllkcpu_wdrst:1;
        RBus_UInt32  pllkcpu_wdset:1;
        RBus_UInt32  pllkcpu_o:2;
        RBus_UInt32  pllkcpu_ip:3;
        RBus_UInt32  pllkcpu_m:8;
        RBus_UInt32  pllkcpu_n:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllkcpu_tst:1;
        RBus_UInt32  res2:7;
    };
}crt_sys_pll_kcpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllkcpu_pow:1;
        RBus_UInt32  pllkcpu_rstb:1;
        RBus_UInt32  pllkcpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_kcpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}crt_pll_ssc_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}crt_pll_ssc_bus_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_en_ssc_h:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbus_gran_est_h:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_dot_gran_h:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllbus_gran_auto_rst_h:1;
        RBus_UInt32  res4:3;
    };
}crt_pll_ssc_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_fcode_ssc_h:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllbus_ncode_ssc_h:8;
        RBus_UInt32  res2:8;
    };
}crt_pll_ssc_bush_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsa_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsa_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsa_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}crt_pll_ssc_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsa_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}crt_pll_ssc_ddsa_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllddsb_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllddsb_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllddsb_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}crt_pll_ssc_ddsb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsb_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllddsb_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}crt_pll_ssc_ddsb_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bus_ssc_ckinv:1;
        RBus_UInt32  bush_ssc_ckinv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  gpu_ssc_ckinv:1;
        RBus_UInt32  dds_ssc_ckinv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  psaud1a_ssc_ckinv:1;
        RBus_UInt32  psaud1b_ssc_ckinv:1;
        RBus_UInt32  psaud2a_ssc_ckinv:1;
        RBus_UInt32  psaud2b_ssc_ckinv:1;
        RBus_UInt32  res3:20;
    };
}crt_pll_ssc_inv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllcpu_reg:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ldo1v_sel:2;
        RBus_UInt32  pow_ldo1v:1;
        RBus_UInt32  res2:25;
    };
}crt_sys_pll_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllacpu_rs:3;
        RBus_UInt32  pllacpu_cs:2;
        RBus_UInt32  pllacpu_wdrst:1;
        RBus_UInt32  pllacpu_wdset:1;
        RBus_UInt32  pllacpu_o:2;
        RBus_UInt32  pllacpu_ip:3;
        RBus_UInt32  pllacpu_m:8;
        RBus_UInt32  pllacpu_n:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllacpu_tst:1;
        RBus_UInt32  res2:7;
    };
}crt_sys_pll_acpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllacpu_pow:1;
        RBus_UInt32  pllacpu_rstb:1;
        RBus_UInt32  pllacpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_acpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_rs:3;
        RBus_UInt32  pllvcpu_cs:2;
        RBus_UInt32  pllvcpu_wdrst:1;
        RBus_UInt32  pllvcpu_wdset:1;
        RBus_UInt32  pllvcpu_o:2;
        RBus_UInt32  pllvcpu_ip:3;
        RBus_UInt32  pllvcpu_m:8;
        RBus_UInt32  pllvcpu_n:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllvcpu_tst:1;
        RBus_UInt32  res2:7;
    };
}crt_sys_pll_vcpu_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_pow:1;
        RBus_UInt32  pllvcpu_rstb:1;
        RBus_UInt32  pllvcpu_oeb:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_vcpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_rs_2:3;
        RBus_UInt32  pllvcpu_cs_2:2;
        RBus_UInt32  pllvcpu_wdrst_2:1;
        RBus_UInt32  pllvcpu_wdset_2:1;
        RBus_UInt32  pllvcpu_o_2:2;
        RBus_UInt32  pllvcpu_ip_2:3;
        RBus_UInt32  pllvcpu_m_2:8;
        RBus_UInt32  pllvcpu_n_2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllvcpu_tst_2:1;
        RBus_UInt32  res2:7;
    };
}crt_sys_pll_vcpu2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvcpu_pow_2:1;
        RBus_UInt32  pllvcpu_rstb_2:1;
        RBus_UInt32  pllvcpu_oeb_2:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_vcpu2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_lpf_rs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_pdiv:2;
        RBus_UInt32  pllbus_pdiv_bps:1;
        RBus_UInt32  pllbus_dbug_en:1;
        RBus_UInt32  pllbus_icp:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_sel_cco:1;
        RBus_UInt32  pllbus_testsel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_lpf_cs:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllbus_wdrst:1;
        RBus_UInt32  pllbus_wdset:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:2;
        RBus_UInt32  res9:2;
    };
}crt_sys_pll_bus1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow:1;
        RBus_UInt32  pllbus_rstb:1;
        RBus_UInt32  pllbus_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllbus_ncode:8;
        RBus_UInt32  pllbus_fcode:11;
        RBus_UInt32  res3:5;
    };
}crt_sys_pll_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_oc_en:1;
        RBus_UInt32  pllbus_oc_done:1;
        RBus_UInt32  pllbus_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_sel_oc_mode:2;
        RBus_UInt32  pllbus_pi_cur_sel:2;
        RBus_UInt32  pllbus_hs_oc_stop:2;
        RBus_UInt32  pllbus_en_pi_debug:1;
        RBus_UInt32  pllbus_bypass_pi:1;
    };
}crt_sys_dvfs_bus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_dbg:8;
        RBus_UInt32  pllbus_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}crt_sys_dvfs_bus2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_lpf_rs_h:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_pdiv_h:2;
        RBus_UInt32  pllbus_pdiv_bps_h:1;
        RBus_UInt32  pllbus_dbug_en_h:1;
        RBus_UInt32  pllbus_icp_h:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllbus_sel_cco_h:1;
        RBus_UInt32  pllbus_testsel_h:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_lpf_cs_h:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllbus_wdrst_h:1;
        RBus_UInt32  pllbus_wdset_h:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:2;
        RBus_UInt32  res9:2;
    };
}crt_sys_pll_bush1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_pow_h:1;
        RBus_UInt32  pllbus_rstb_h:1;
        RBus_UInt32  pllbus_oeb_h:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllbus_ncode_h:8;
        RBus_UInt32  pllbus_fcode_h:11;
        RBus_UInt32  res3:5;
    };
}crt_sys_pll_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbus_oc_en_h:1;
        RBus_UInt32  pllbus_oc_done_h:1;
        RBus_UInt32  pllbus_sdm_order_h:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllbus_oc_step_h:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_oc_done_delay_h:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_sel_oc_mode_h:2;
        RBus_UInt32  pllbus_pi_cur_sel_h:2;
        RBus_UInt32  pllbus_hs_oc_stop_h:2;
        RBus_UInt32  pllbus_en_pi_debug_h:1;
        RBus_UInt32  pllbus_bypass_pi_h:1;
    };
}crt_sys_dvfs_bush_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllbus_ncode_dbg_h:8;
        RBus_UInt32  pllbus_fcode_dbg_h:11;
        RBus_UInt32  res2:5;
    };
}crt_sys_dvfs_bush2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_lpf_rs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllgpu_pdiv:2;
        RBus_UInt32  pllgpu_pdiv_bps:1;
        RBus_UInt32  pllgpu_dbug_en:1;
        RBus_UInt32  pllgpu_icp:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllgpu_sel_cco:1;
        RBus_UInt32  pllgpu_testsel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllgpu_lpf_cs:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pllgpu_wdrst:1;
        RBus_UInt32  pllgpu_wdset:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:2;
        RBus_UInt32  res9:2;
    };
}crt_sys_pll_gpu1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_pow:1;
        RBus_UInt32  pllgpu_rstb:1;
        RBus_UInt32  pllgpu_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllgpu_ncode:8;
        RBus_UInt32  pllgpu_fcode:11;
        RBus_UInt32  res3:5;
    };
}crt_sys_pll_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllgpu_oc_en:1;
        RBus_UInt32  pllgpu_oc_done:1;
        RBus_UInt32  pllgpu_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllgpu_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllgpu_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllgpu_sel_oc_mode:2;
        RBus_UInt32  pllgpu_pi_cur_sel:2;
        RBus_UInt32  pllgpu_hs_oc_stop:2;
        RBus_UInt32  pllgpu_en_pi_debug:1;
        RBus_UInt32  pllgpu_bypass_pi:1;
    };
}crt_sys_dvfs_gpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllgpu_ncode_dbg:8;
        RBus_UInt32  pllgpu_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}crt_sys_dvfs_gpu2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvodma_rs:3;
        RBus_UInt32  pllvodma_cs:2;
        RBus_UInt32  pllvodma_wdrst:1;
        RBus_UInt32  pllvodma_wdset:1;
        RBus_UInt32  pllvodma_o:2;
        RBus_UInt32  pllvodma_ip:3;
        RBus_UInt32  pllvodma_m:8;
        RBus_UInt32  pllvodma_n:2;
        RBus_UInt32  res1:10;
    };
}crt_sys_pll_vodma1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllvodma_pow:1;
        RBus_UInt32  pllvodma_rstb:1;
        RBus_UInt32  pllvodma_oeb:1;
        RBus_UInt32  pllvodma_tst:1;
        RBus_UInt32  res1:28;
    };
}crt_sys_pll_vodma2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllbustst_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllbustst_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllbus_reg:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllbus_reser:8;
        RBus_UInt32  res4:8;
    };
}crt_sys_pllbus_tst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_wdmode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pllddsa_o:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  pllddsa_cp:2;
        RBus_UInt32  pllddsa_cs:2;
        RBus_UInt32  pllddsa_rs:3;
        RBus_UInt32  pllddsa_ip:4;
        RBus_UInt32  res4:6;
        RBus_UInt32  pllddsa_n:2;
    };
}crt_sys_pll_dispa_sd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_pow:1;
        RBus_UInt32  pllddsa_rstb:1;
        RBus_UInt32  pllddsa_oeb:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  pllddsa_ncode:8;
        RBus_UInt32  pllddsa_fcode:11;
        RBus_UInt32  res3:5;
    };
}crt_sys_pll_dispa_sd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dummy18000478_10_10:1;
        RBus_UInt32  pllddsa_pstst:1;
        RBus_UInt32  pllddsa_tst:1;
        RBus_UInt32  dummy18000478_13_13:1;
        RBus_UInt32  pllddsa_vcorb:1;
        RBus_UInt32  dummy18000478_15_15:1;
        RBus_UInt32  dummy18000478_16_16:1;
        RBus_UInt32  dummy18000478_17_17:1;
        RBus_UInt32  dummy18000478_18_18:1;
        RBus_UInt32  dummy18000478_19_19:1;
        RBus_UInt32  dummy18000478_20_20:1;
        RBus_UInt32  dummy18000478_21_21:1;
        RBus_UInt32  dummy18000478_22_22:1;
        RBus_UInt32  dummy18000478_23_23:1;
        RBus_UInt32  dummy18000478_24_24:1;
        RBus_UInt32  dummy18000478_28_25:4;
        RBus_UInt32  res2:3;
    };
}crt_sys_pll_dispa_sd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud2a_rstb:1;
        RBus_UInt32  psaud2a_oeb:1;
        RBus_UInt32  psaud1a_rstb:1;
        RBus_UInt32  psaud1a_oeb:1;
        RBus_UInt32  res1:16;
        RBus_UInt32  psaud2a_psen:1;
        RBus_UInt32  psaud2a_tst:1;
        RBus_UInt32  psaud2a_div:1;
        RBus_UInt32  psaud2a_fupdn:1;
        RBus_UInt32  dummy1800047c_24:1;
        RBus_UInt32  psaud1a_psen:1;
        RBus_UInt32  psaud1a_tst:1;
        RBus_UInt32  dummy1800047c_27:1;
        RBus_UInt32  psaud1a_div:1;
        RBus_UInt32  psaud1a_fupdn:1;
        RBus_UInt32  dummy1800047c_30:1;
        RBus_UInt32  res2:1;
    };
}crt_sys_pll_dispa_sd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllddsa_oc_en:1;
        RBus_UInt32  pllddsa_oc_done:1;
        RBus_UInt32  pllddsa_sdm_order:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllddsa_oc_step:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllddsa_oc_done_delay:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  pllddsa_sel_oc_mode:2;
        RBus_UInt32  pllddsa_pi_cur_sel:2;
        RBus_UInt32  pllddsa_hs_oc_stop:2;
        RBus_UInt32  pllddsa_en_pi_debug:1;
        RBus_UInt32  pllddsa_bypass_pi:1;
    };
}crt_sys_dvfs_ddsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllddsa_ncode_dbg:8;
        RBus_UInt32  pllddsa_fcode_dbg:11;
        RBus_UInt32  res2:5;
    };
}crt_sys_dvfs_ddsa2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su:1;
        RBus_UInt32  sd:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc:1;
        RBus_UInt32  tmps:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce:1;
        RBus_UInt32  res5:6;
    };
}crt_ai_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  su_2:1;
        RBus_UInt32  sd_2:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  swcs_2:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  psc_2:1;
        RBus_UInt32  tmps_2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  tme_2:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  swsce_2:1;
        RBus_UInt32  res5:6;
    };
}crt_ai2_clkcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllscpu_wdout:1;
        RBus_UInt32  pllacpu_wdout:1;
        RBus_UInt32  pllvcpu_wdout:1;
        RBus_UInt32  pllddsa_wdout:1;
        RBus_UInt32  pllvcpu2_wdout:1;
        RBus_UInt32  plldisp_wdout:1;
        RBus_UInt32  pllbus_wdout:1;
        RBus_UInt32  pllscpu_2_wdout:1;
        RBus_UInt32  pllddsb_wdout:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  plldif_wdout:1;
        RBus_UInt32  pllgpu_wdout:1;
        RBus_UInt32  pllbush_wdout:1;
        RBus_UInt32  pll512fs_wdout:1;
        RBus_UInt32  pllaud_status:1;
        RBus_UInt32  pll512fs_wdout_1:1;
        RBus_UInt32  pllkcpu_wdout:1;
        RBus_UInt32  pllvodma_wdout:1;
        RBus_UInt32  pll27x_wdout:1;
        RBus_UInt32  res2:13;
    };
}crt_sys_pll_wd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_wdset:1;
        RBus_UInt32  pll512fs_wdrst:1;
        RBus_UInt32  pll512fs_tst:1;
        RBus_UInt32  pll512fs_rs:3;
        RBus_UInt32  pll512fs_q:3;
        RBus_UInt32  pll512fs_s:3;
        RBus_UInt32  pll512fs_ip:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_cs:2;
        RBus_UInt32  pll512fs_bps:1;
        RBus_UInt32  pll512fs_bpn:1;
        RBus_UInt32  pll512fs_m:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_n:3;
        RBus_UInt32  res3:1;
    };
}crt_sys_pll_512fs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_pow:1;
        RBus_UInt32  pll512fs_rstb:1;
        RBus_UInt32  pll512fs_oeb:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_512fs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_wdset2:1;
        RBus_UInt32  pll512fs_wdrst2:1;
        RBus_UInt32  pll512fs_tst2:1;
        RBus_UInt32  pll512fs_rs2:3;
        RBus_UInt32  pll512fs_q2:3;
        RBus_UInt32  pll512fs_s2:3;
        RBus_UInt32  pll512fs_ip2:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll512fs_cs2:2;
        RBus_UInt32  pll512fs_bps2:1;
        RBus_UInt32  pll512fs_bpn2:1;
        RBus_UInt32  pll512fs_m2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll512fs_n2:3;
        RBus_UInt32  res3:1;
    };
}crt_sys_pll_512fs2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll512fs_pow2:1;
        RBus_UInt32  pll512fs_rstb2:1;
        RBus_UInt32  pll512fs_oeb2:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_512fs2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_lf_cp:2;
        RBus_UInt32  plldif_lf_rs:2;
        RBus_UInt32  plldif_ip:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  plldif_m:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  plldif_n:2;
        RBus_UInt32  res5:2;
    };
}crt_sys_pll_dif1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldif_divadc_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  plldif_divdig_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  plldif_wdmode:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  plldif_dvbs2_en:1;
        RBus_UInt32  res4:19;
    };
}crt_sys_pll_dif2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  plldif_pow:1;
        RBus_UInt32  plldif_rstb:1;
        RBus_UInt32  plldif_vco_rstb:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_dif3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_m:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll27x_n:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  pll27x_ip:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll27x_lf_rs:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  pll27x_lf_cp:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  pll27x_wdmode:2;
        RBus_UInt32  res7:2;
    };
}crt_sys_pll_27x1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_ps_duty_sel:1;
        RBus_UInt32  pll27x_ps_psel_pulse_w:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pll27x_ps_54m_delay:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pll_ldo_sel:2;
        RBus_UInt32  pll_pow_ldo:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  pll_ldo11v_sel:2;
        RBus_UInt32  pll_pow_ldo11v:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  pll_xixo_drive_sel:2;
        RBus_UInt32  pll_xixo_load:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  pll_ldo_xtal_sel:2;
        RBus_UInt32  vdd11_pad_sel:2;
        RBus_UInt32  xo_cap:4;
        RBus_UInt32  xi_cap:4;
    };
}crt_sys_pll_27x2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll27x_pow:1;
        RBus_UInt32  pll27x_rstb:1;
        RBus_UInt32  pll27x_vcorstb:1;
        RBus_UInt32  pll27x_ps_div2:1;
        RBus_UInt32  pll27x_ps_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pll_reserve:8;
        RBus_UInt32  res2:16;
    };
}crt_sys_pll_27x3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_ck_ifadc_mux:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pll_xtalwd_set:1;
        RBus_UInt32  pll_xtalwd_rst:1;
        RBus_UInt32  pllaud_ckin_mux:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  pll27x_ifadc_cko_en:1;
        RBus_UInt32  pll27x_ifadc_div:1;
        RBus_UInt32  pll27x_ifadc_cko_sel:2;
        RBus_UInt32  pll27x_yppadc_ck54m_en:1;
        RBus_UInt32  pll27x_yppadc_cko_en:1;
        RBus_UInt32  pll27x_yppadc_cko_sel:2;
        RBus_UInt32  pll27x_ck108m_div:2;
        RBus_UInt32  pll27x_ck108m_en:1;
        RBus_UInt32  pll_rssi_cko_en:1;
        RBus_UInt32  pll27x_en_tst:1;
        RBus_UInt32  pll27x_pll_tst:3;
        RBus_UInt32  pll27x_d16_en:1;
        RBus_UInt32  pll_l2h_cml_pow:1;
        RBus_UInt32  pll_ifadc_cko_polar:1;
        RBus_UInt32  pll_yppadc_cko_polar:1;
        RBus_UInt32  dummy180004dc_28:1;
        RBus_UInt32  pll27x_ifadc_duty:2;
        RBus_UInt32  dummy180004dc_31:1;
    };
}crt_sys_pll_27x4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllaud_tst:1;
        RBus_UInt32  pllaud_wdset:1;
        RBus_UInt32  pllaud_wdrst:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  pllaud_cp:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  pllaud_rs:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  pllaud_ip:3;
        RBus_UInt32  res6:14;
    };
}crt_sys_pll_aud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllaud_pow:1;
        RBus_UInt32  pllaud_oeb2:1;
        RBus_UInt32  pllaud_oeb1:1;
        RBus_UInt32  pllaud_rstb:1;
        RBus_UInt32  pllaud_vcorstb:1;
        RBus_UInt32  res1:27;
    };
}crt_sys_pll_aud3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bb_micbias_clksel:2;
        RBus_UInt32  res1:30;
    };
}crt_sys_pll_aud4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud_ctrl:1;
        RBus_UInt32  psaud_tst:1;
        RBus_UInt32  psaud_en:1;
        RBus_UInt32  psaud_psen:1;
        RBus_UInt32  psaud_adder_mode:1;
        RBus_UInt32  res1:27;
    };
}crt_sys_pll_psaud1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psaud_div:4;
        RBus_UInt32  res1:28;
    };
}crt_sys_pll_psaud2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_mck_clk_en:7;
        RBus_UInt32  reg_dpi_en_post_pi:8;
        RBus_UInt32  reg_dpi_post_pi_sel0:5;
        RBus_UInt32  reg_dpi_post_pi_sel1:5;
        RBus_UInt32  reg_dpi_post_pi_sel2:5;
        RBus_UInt32  reg_dpi_cco_band:2;
    };
}crt_sys_pll_ddr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_post_pi_sel3:5;
        RBus_UInt32  reg_dpi_post_pi_sel4:5;
        RBus_UInt32  reg_dpi_post_pi_sel5:5;
        RBus_UInt32  reg_dpi_post_pi_sel6:5;
        RBus_UInt32  reg_dpi_icp:4;
        RBus_UInt32  reg_dpi_loop_pi_isel:4;
        RBus_UInt32  reg_dpi_lpf_cp:1;
        RBus_UInt32  reg_dpi_lpf_sr:3;
    };
}crt_sys_pll_ddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_pdiv:2;
        RBus_UInt32  reg_dpi_pll_dbug_en:1;
        RBus_UInt32  reg_dpi_pll_ldo_vsel:2;
        RBus_UInt32  reg_dpi_pll_sel_cpmode:1;
        RBus_UInt32  reg_dpi_post_pi_bias:2;
        RBus_UInt32  reg_dpi_post_pi_rl:2;
        RBus_UInt32  reg_dpi_post_pi_rs:1;
        RBus_UInt32  reg_dpi_f_code:11;
        RBus_UInt32  reg_dpi_bypass_pi:1;
        RBus_UInt32  reg_dpi_en_ssc:1;
        RBus_UInt32  reg_dpi_n_code:8;
    };
}crt_sys_pll_ddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_order:1;
        RBus_UInt32  reg_dpi_n_code_t:8;
        RBus_UInt32  reg_dpi_f_code_t:11;
        RBus_UInt32  reg_dpi_oc_step_set:10;
        RBus_UInt32  reg_dpi_oc_en:1;
        RBus_UInt32  reg_dpi_cco_kvco:1;
    };
}crt_sys_pll_ddr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_sel_oc_mode:2;
        RBus_UInt32  reg_dpi_hs_oc_stop_diff:2;
        RBus_UInt32  reg_dpi_oc_done_delay:6;
        RBus_UInt32  reg_dpi_gran_set:19;
        RBus_UInt32  reg_dpi_dot_gran:3;
    };
}crt_sys_pll_ddr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_gran_auto_rst:1;
        RBus_UInt32  reg_dpi_wd_enable:1;
        RBus_UInt32  reg_dpi_f390k:2;
        RBus_UInt32  reg_dpi_time0_ck:3;
        RBus_UInt32  reg_dpi_time_rdy_ckout:2;
        RBus_UInt32  reg_dpi_time2_rst_width:2;
        RBus_UInt32  reg_dpi_clk_oe:7;
        RBus_UInt32  reg_dpi_oesync_op_sel:7;
        RBus_UInt32  res1:7;
    };
}crt_sys_pll_ddr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_pll_dum:8;
        RBus_UInt32  reg_dpi_adr_rate_sel:1;
        RBus_UInt32  reg_dpi_dat_rate_sel:1;
        RBus_UInt32  reg_dpi_ckref_sel:1;
        RBus_UInt32  reg_dpi_adj_div2_en:1;
        RBus_UInt32  reg_dpi_post_pi_sel:5;
        RBus_UInt32  reg_dpi_v11_ldo_vsel:2;
        RBus_UInt32  reg_dpi_ng_clk_sel:2;
        RBus_UInt32  reg_dpi_pll_en:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  pll_stable:1;
    };
}crt_sys_pll_ddr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_cmd_duty_preseta:3;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_cmd_duty:7;
        RBus_UInt32  reg_dpi_dcc_cmd_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_cmd_div:3;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_dbg_sel:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_0:8;
        RBus_UInt32  reg_dpi_dll_dly_0:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_0:1;
        RBus_UInt32  reg_dpi_dll_int_gain_0:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_0:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_0:1;
        RBus_UInt32  res1:2;
    };
}crt_sys_pll_ddr_dcc_ad0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_1:8;
        RBus_UInt32  reg_dpi_dll_dly_1:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_1:1;
        RBus_UInt32  reg_dpi_dll_int_gain_1:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_1:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_1:1;
        RBus_UInt32  res1:2;
    };
}crt_sys_pll_ddr_dcc_ad0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_2:8;
        RBus_UInt32  reg_dpi_dll_dly_2:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_2:1;
        RBus_UInt32  reg_dpi_dll_int_gain_2:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_2:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_2:1;
        RBus_UInt32  res1:2;
    };
}crt_sys_pll_ddr_dcc_ad0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_3:8;
        RBus_UInt32  reg_dpi_dll_dly_3:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_3:1;
        RBus_UInt32  reg_dpi_dll_int_gain_3:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_3:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_3:1;
        RBus_UInt32  res1:2;
    };
}crt_sys_pll_ddr_dcc_ad0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_0:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_0:5;
        RBus_UInt32  alert_rx_rst_n_0:1;
        RBus_UInt32  res1:21;
    };
}crt_sys_pll_ddr_dcc_ad1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_1:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_1:5;
        RBus_UInt32  alert_rx_rst_n_1:1;
        RBus_UInt32  res1:21;
    };
}crt_sys_pll_ddr_dcc_ad1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_2:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_2:5;
        RBus_UInt32  alert_rx_rst_n_2:1;
        RBus_UInt32  res1:21;
    };
}crt_sys_pll_ddr_dcc_ad1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_3:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_3:5;
        RBus_UInt32  alert_rx_rst_n_3:1;
        RBus_UInt32  res1:21;
    };
}crt_sys_pll_ddr_dcc_ad1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_0:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dqs_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_1:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dqs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_2:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dqs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_3:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dqs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_0:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dq_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_1:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_2:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_3:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_dq_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_ck0_duty_preseta:3;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck0_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck0_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck0_div:3;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_dbg_sel:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_ck0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_ck1_duty_preseta:3;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck1_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck1_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck1_div:3;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_dbg_sel:1;
        RBus_UInt32  res1:8;
    };
}crt_sys_pll_ddr_dcc_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_in_dll:32;
    };
}crt_sys_pll_dummy_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_out_dll:32;
    };
}crt_sys_pll_dummy_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_mck_clk_en:7;
        RBus_UInt32  reg_dpi_en_post_pi:8;
        RBus_UInt32  reg_dpi_post_pi_sel0:5;
        RBus_UInt32  reg_dpi_post_pi_sel1:5;
        RBus_UInt32  reg_dpi_post_pi_sel2:5;
        RBus_UInt32  reg_dpi_cco_band:2;
    };
}crt_dc2_sys_pll_ddr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_post_pi_sel3:5;
        RBus_UInt32  reg_dpi_post_pi_sel4:5;
        RBus_UInt32  reg_dpi_post_pi_sel5:5;
        RBus_UInt32  reg_dpi_post_pi_sel6:5;
        RBus_UInt32  reg_dpi_icp:4;
        RBus_UInt32  reg_dpi_loop_pi_isel:4;
        RBus_UInt32  reg_dpi_lpf_cp:1;
        RBus_UInt32  reg_dpi_lpf_sr:3;
    };
}crt_dc2_sys_pll_ddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_pdiv:2;
        RBus_UInt32  reg_dpi_pll_dbug_en:1;
        RBus_UInt32  reg_dpi_pll_ldo_vsel:2;
        RBus_UInt32  reg_dpi_pll_sel_cpmode:1;
        RBus_UInt32  reg_dpi_post_pi_bias:2;
        RBus_UInt32  reg_dpi_post_pi_rl:2;
        RBus_UInt32  reg_dpi_post_pi_rs:1;
        RBus_UInt32  reg_dpi_f_code:11;
        RBus_UInt32  reg_dpi_bypass_pi:1;
        RBus_UInt32  reg_dpi_en_ssc:1;
        RBus_UInt32  reg_dpi_n_code:8;
    };
}crt_dc2_sys_pll_ddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_order:1;
        RBus_UInt32  reg_dpi_n_code_t:8;
        RBus_UInt32  reg_dpi_f_code_t:11;
        RBus_UInt32  reg_dpi_oc_step_set:10;
        RBus_UInt32  reg_dpi_oc_en:1;
        RBus_UInt32  reg_dpi_cco_kvco:1;
    };
}crt_dc2_sys_pll_ddr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_sel_oc_mode:2;
        RBus_UInt32  reg_dpi_hs_oc_stop_diff:2;
        RBus_UInt32  reg_dpi_oc_done_delay:6;
        RBus_UInt32  reg_dpi_gran_set:19;
        RBus_UInt32  reg_dpi_dot_gran:3;
    };
}crt_dc2_sys_pll_ddr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_gran_auto_rst:1;
        RBus_UInt32  reg_dpi_wd_enable:1;
        RBus_UInt32  reg_dpi_f390k:2;
        RBus_UInt32  reg_dpi_time0_ck:3;
        RBus_UInt32  reg_dpi_time_rdy_ckout:2;
        RBus_UInt32  reg_dpi_time2_rst_width:2;
        RBus_UInt32  reg_dpi_clk_oe:7;
        RBus_UInt32  reg_dpi_oesync_op_sel:7;
        RBus_UInt32  res1:7;
    };
}crt_dc2_sys_pll_ddr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_pll_dum:8;
        RBus_UInt32  reg_dpi_adr_rate_sel:1;
        RBus_UInt32  reg_dpi_dat_rate_sel:1;
        RBus_UInt32  reg_dpi_ckref_sel:1;
        RBus_UInt32  reg_dpi_adj_div2_en:1;
        RBus_UInt32  reg_dpi_post_pi_sel:5;
        RBus_UInt32  reg_dpi_v11_ldo_vsel:2;
        RBus_UInt32  reg_dpi_ng_clk_sel:2;
        RBus_UInt32  reg_dpi_pll_en:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  pll_stable:1;
    };
}crt_dc2_sys_pll_ddr6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_cmd_duty_preseta:3;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_cmd_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_cmd_duty:7;
        RBus_UInt32  reg_dpi_dcc_cmd_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_cmd_div:3;
        RBus_UInt32  reg_dpi_dcc_cmd_dsp_dbg_sel:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_cmd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_0:8;
        RBus_UInt32  reg_dpi_dll_dly_0:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_0:1;
        RBus_UInt32  reg_dpi_dll_int_gain_0:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_0:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_0:1;
        RBus_UInt32  res1:2;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_1:8;
        RBus_UInt32  reg_dpi_dll_dly_1:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_1:1;
        RBus_UInt32  reg_dpi_dll_int_gain_1:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_1:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_1:1;
        RBus_UInt32  res1:2;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_2:8;
        RBus_UInt32  reg_dpi_dll_dly_2:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_2:1;
        RBus_UInt32  reg_dpi_dll_int_gain_2:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_2:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_2:1;
        RBus_UInt32  res1:2;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_init_value_3:8;
        RBus_UInt32  reg_dpi_dll_dly_3:9;
        RBus_UInt32  reg_dpi_dll_dly_sel_3:1;
        RBus_UInt32  reg_dpi_dll_int_gain_3:5;
        RBus_UInt32  reg_dpi_dll_ph90_sft_3:6;
        RBus_UInt32  reg_dpi_dll_en_pdout_3:1;
        RBus_UInt32  res1:2;
    };
}crt_dc2_sys_pll_ddr_dcc_ad0_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_0:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_0:5;
        RBus_UInt32  alert_rx_rst_n_0:1;
        RBus_UInt32  res1:21;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_1:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_1:5;
        RBus_UInt32  alert_rx_rst_n_1:1;
        RBus_UInt32  res1:21;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_2:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_2:5;
        RBus_UInt32  alert_rx_rst_n_2:1;
        RBus_UInt32  res1:21;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dll_x_onehot_ini_3:5;
        RBus_UInt32  reg_dpi_dll_y_onehot_ini_3:5;
        RBus_UInt32  alert_rx_rst_n_3:1;
        RBus_UInt32  res1:21;
    };
}crt_dc2_sys_pll_ddr_dcc_ad1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_0:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_1:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_2:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dqs_duty_preseta_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dqs_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dqs_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dqs_dsp_dbg_sel_3:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dqs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_0:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_0:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_0:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_0:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_0:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_1:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_1:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_1:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_1:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_1:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_2:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_2:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_2:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_2:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_2:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_dq_duty_preseta_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_presetb_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_duty_sel_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_duty_3:7;
        RBus_UInt32  reg_dpi_dcc_dq_int_gain_3:5;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_stop_3:1;
        RBus_UInt32  reg_dpi_dcc_dq_div_3:3;
        RBus_UInt32  reg_dpi_dcc_dq_dsp_dbg_sel_3:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_dq_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_ck0_duty_preseta:3;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck0_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck0_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck0_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck0_div:3;
        RBus_UInt32  reg_dpi_dcc_ck0_dsp_dbg_sel:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_ck0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_dpi_dcc_ck1_duty_preseta:3;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_presetb:3;
        RBus_UInt32  reg_dpi_dcc_ck1_duty_sel:1;
        RBus_UInt32  reg_dpi_dcc_ck1_duty:7;
        RBus_UInt32  reg_dpi_dcc_ck1_int_gain:5;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_stop:1;
        RBus_UInt32  reg_dpi_dcc_ck1_div:3;
        RBus_UInt32  reg_dpi_dcc_ck1_dsp_dbg_sel:1;
        RBus_UInt32  res1:8;
    };
}crt_dc2_sys_pll_ddr_dcc_ck1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_in_dll:32;
    };
}crt_dc2_sys_pll_dummy_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpi_dummy_out_dll:32;
    };
}crt_dc2_sys_pll_dummy_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_ss_en:1;
        RBus_UInt32  dummy18000640_1:1;
        RBus_UInt32  dclk_ss_load:1;
        RBus_UInt32  dummy18000640_3:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  dclk_new_en:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  dclk_filed_flag_slt:3;
        RBus_UInt32  dclk_field_flag_mode_en:1;
    };
}crt_sys_dclkss_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_general_en:1;
        RBus_UInt32  in_frame_tracking_vd_dec_en:1;
        RBus_UInt32  in_frame_tracking_ypbpr_en:1;
        RBus_UInt32  in_frame_tracking_offset_inverse:1;
        RBus_UInt32  fll_tracking_en:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  dclk_freq_syn_slt:14;
        RBus_UInt32  res2:2;
    };
}crt_dpll_in_fsync_tracking_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_mul:19;
        RBus_UInt32  res1:13;
    };
}crt_dpll_in_fsync_tracking_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  in_frame_tracking_pos_th:16;
        RBus_UInt32  in_frame_tracking_neg_th:16;
    };
}crt_dpll_in_fsync_tracking_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frc2fsync_speedup_offset:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  frc2fsync_speed_dir:1;
        RBus_UInt32  res2:15;
    };
}crt_dclk_frc2fsync_speedup_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  final_profile:18;
        RBus_UInt32  res1:14;
    };
}crt_dpll_status_ro_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dclk_profile_remap_cnt:8;
        RBus_UInt32  dummy18000658_31:20;
    };
}crt_dclkss_profile_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_0:16;
        RBus_UInt32  dclk_profile_remap_1:16;
    };
}crt_dclkss_profile0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_2:16;
        RBus_UInt32  dclk_profile_remap_3:16;
    };
}crt_dclkss_profile1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_4:16;
        RBus_UInt32  dclk_profile_remap_5:16;
    };
}crt_dclkss_profile2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_6:16;
        RBus_UInt32  dclk_profile_remap_7:16;
    };
}crt_dclkss_profile3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_8:16;
        RBus_UInt32  dclk_profile_remap_9:16;
    };
}crt_dclkss_profile4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_10:16;
        RBus_UInt32  dclk_profile_remap_11:16;
    };
}crt_dclkss_profile5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_12:16;
        RBus_UInt32  dclk_profile_remap_13:16;
    };
}crt_dclkss_profile6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_14:16;
        RBus_UInt32  dclk_profile_remap_15:16;
    };
}crt_dclkss_profile7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_16:16;
        RBus_UInt32  dclk_profile_remap_17:16;
    };
}crt_dclkss_profile8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_18:16;
        RBus_UInt32  dclk_profile_remap_19:16;
    };
}crt_dclkss_profile9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_20:16;
        RBus_UInt32  dclk_profile_remap_21:16;
    };
}crt_dclkss_profile10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_22:16;
        RBus_UInt32  dclk_profile_remap_23:16;
    };
}crt_dclkss_profile11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_24:16;
        RBus_UInt32  dclk_profile_remap_25:16;
    };
}crt_dclkss_profile12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_26:16;
        RBus_UInt32  dclk_profile_remap_27:16;
    };
}crt_dclkss_profile13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_28:16;
        RBus_UInt32  dclk_profile_remap_29:16;
    };
}crt_dclkss_profile14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dclk_profile_remap_30:16;
        RBus_UInt32  dclk_profile_remap_31:16;
    };
}crt_dclkss_profile15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  double_buf_apply:1;
        RBus_UInt32  double_buf_read_sel:1;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  res1:29;
    };
}crt_dpll_double_buffer_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  oc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  oc_step_set:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  fcode_t_ssc:11;
        RBus_UInt32  res3:5;
    };
}crt_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sel_oc_mode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  hs_oc_stop_diff:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  oc_done_delay:6;
        RBus_UInt32  res4:10;
    };
}crt_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypass_pi:1;
        RBus_UInt32  sdm_order:1;
        RBus_UInt32  en_pi_debug:1;
        RBus_UInt32  res1:29;
    };
}crt_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}crt_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}crt_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fmod:1;
        RBus_UInt32  load_fcw:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  oc_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ncode_debug:8;
        RBus_UInt32  fcode_debug:11;
        RBus_UInt32  res3:5;
    };
}crt_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_cs:2;
        RBus_UInt32  dpll_cp:2;
        RBus_UInt32  dpll_rs:3;
        RBus_UInt32  dpll_ssc_inv:1;
        RBus_UInt32  dpll_ip:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_n:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_m:8;
        RBus_UInt32  res3:4;
    };
}crt_sys_pll_disp1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_x_bpsin:1;
        RBus_UInt32  dpll_x_bpspi:1;
        RBus_UInt32  res1:30;
    };
}crt_sys_pll_disp2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pow:1;
        RBus_UInt32  dpll_vcorstb:1;
        RBus_UInt32  dpll_freeze:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dpll_wdset:1;
        RBus_UInt32  dpll_wdrst:1;
        RBus_UInt32  dpll_rstb:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  dpll_o:2;
        RBus_UInt32  dpll_bpn:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dpll_bpphs:1;
        RBus_UInt32  dpll_reserve:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  dpll_stop:1;
        RBus_UInt32  dpll_fupdn:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  dpll_reser:4;
        RBus_UInt32  dpll_ldosel:2;
        RBus_UInt32  res6:2;
    };
}crt_sys_pll_disp3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dpll_pi_ibsel:2;
        RBus_UInt32  dpll_ldodpll_pow:1;
        RBus_UInt32  res1:29;
    };
}crt_sys_pll_disp4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_th_value:17;
        RBus_UInt32  res1:14;
        RBus_UInt32  sscg_offset_over_flag:1;
    };
}crt_dpll_in_fsync_tracking_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sscg_offset_over_th_max:17;
        RBus_UInt32  res1:15;
    };
}crt_dpll_in_fsync_tracking_debug1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_offset_over_th_value:17;
        RBus_UInt32  res1:14;
        RBus_UInt32  new_fll_offset_over_flag:1;
    };
}crt_dpll_in_fsync_tracking_debug2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_offset_over_th_max:17;
        RBus_UInt32  res1:15;
    };
}crt_dpll_in_fsync_tracking_debug3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_tracking_mul:19;
        RBus_UInt32  res1:1;
        RBus_UInt32  new_fll_tracking_offset_inverse:1;
        RBus_UInt32  res2:11;
    };
}crt_dpll_in_fsync_tracking_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  new_fll_tracking_pos_th:16;
        RBus_UInt32  new_fll_tracking_neg_th:16;
    };
}crt_dpll_in_fsync_tracking_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllallrstb:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  pllsn:3;
        RBus_UInt32  pllsnbp:1;
        RBus_UInt32  pllssi:5;
        RBus_UInt32  pllsdiv2:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  pllsrs:3;
        RBus_UInt32  pllscs:2;
        RBus_UInt32  pllscp:1;
        RBus_UInt32  pll_emmc_ckssc_inv:1;
        RBus_UInt32  res3:1;
    };
}crt_emmc_pll_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmcpwdn:1;
        RBus_UInt32  pllemmcldopow:1;
        RBus_UInt32  pllemmc_reg:2;
        RBus_UInt32  pllswdset:1;
        RBus_UInt32  pllswdrst:1;
        RBus_UInt32  pllsstatus:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllemmc_rsvd:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_pll_tp1_mux:3;
        RBus_UInt32  reg_pll_tp2_mux:3;
        RBus_UInt32  res3:9;
    };
}crt_emmc_pll_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllssck:6;
        RBus_UInt32  pllsy:1;
        RBus_UInt32  pllsx:1;
        RBus_UInt32  pllsd2y:1;
        RBus_UInt32  pllsd2x:1;
        RBus_UInt32  pllssck_2:6;
        RBus_UInt32  pllsy_2:1;
        RBus_UInt32  pllsx_2:1;
        RBus_UInt32  pllsd2y_2:1;
        RBus_UInt32  pllsd2x_2:1;
        RBus_UInt32  pllssck_3:6;
        RBus_UInt32  pllsy_3:1;
        RBus_UInt32  pllsx_3:1;
        RBus_UInt32  pllsd2y_3:1;
        RBus_UInt32  pllsd2x_3:1;
        RBus_UInt32  pll_pi_autoset:1;
        RBus_UInt32  res1:1;
    };
}crt_emmc_pllphase_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllsphrs:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pllsphrl:2;
        RBus_UInt32  res2:26;
    };
}crt_emmc_pll_phase_interpolation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_oc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_oc_step_set:10;
        RBus_UInt32  res2:18;
    };
}crt_emmc_pll_ssc0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pllemmc_sel_oc_mode:2;
        RBus_UInt32  pllemmc_pi_cur_sel:2;
        RBus_UInt32  pllemmc_hs_oc_stop_diff:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pllemmc_oc_done_delay:6;
        RBus_UInt32  res3:10;
    };
}crt_emmc_pll_ssc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_bypass_pi:1;
        RBus_UInt32  pllemmc_sdm_order:1;
        RBus_UInt32  pllemmc_en_pi_debug:1;
        RBus_UInt32  res1:29;
    };
}crt_emmc_pll_ssc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_fcode_ssc:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllemmc_ncode_ssc:8;
        RBus_UInt32  res2:8;
    };
}crt_emmc_pll_ssc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_fcode_t:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  pllemmc_ncode_t:8;
        RBus_UInt32  res2:8;
    };
}crt_emmc_pll_ssc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_en_ssc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_gran_est:19;
        RBus_UInt32  res2:1;
        RBus_UInt32  pllemmc_dot_gran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  pllemmc_gran_auto_rst:1;
        RBus_UInt32  res4:3;
    };
}crt_emmc_pll_ssc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pllemmc_fmod:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  pllemmc_oc_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  pllemmc_ncode_debug:8;
        RBus_UInt32  pllemmc_fcode_debug:11;
        RBus_UInt32  res3:5;
    };
}crt_emmc_pll_ssc6_RBUS;




#endif 


#endif 
