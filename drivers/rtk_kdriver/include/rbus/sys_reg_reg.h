/**
* @file Mac5-DesignSpec-CRT
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_SYS_REG_REG_H_
#define _RBUS_SYS_REG_REG_H_

#include "rbus_types.h"



//  SYS_REG Register Address
#define  SYS_REG_SYS_SRST0                                                       0x18000100
#define  SYS_REG_SYS_SRST0_reg_addr                                              "0xB8000100"
#define  SYS_REG_SYS_SRST0_reg                                                   0xB8000100
#define  SYS_REG_SYS_SRST0_inst_addr                                             "0x0000"
#define  set_SYS_REG_SYS_SRST0_reg(data)                                         (*((volatile unsigned int*)SYS_REG_SYS_SRST0_reg)=data)
#define  get_SYS_REG_SYS_SRST0_reg                                               (*((volatile unsigned int*)SYS_REG_SYS_SRST0_reg))
#define  SYS_REG_SYS_SRST0_rstn_diseqc_shift                                     (31)
#define  SYS_REG_SYS_SRST0_rstn_cablerx_shift                                    (30)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_common_shift                                (29)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre3_shift                                  (28)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre2_shift                                  (27)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre1_shift                                  (26)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre0_shift                                  (25)
#define  SYS_REG_SYS_SRST0_rstn_img_demod_shift                                  (24)
#define  SYS_REG_SYS_SRST0_rstn_img_demod_wrap_shift                             (23)
#define  SYS_REG_SYS_SRST0_rstn_hdic_apb_shift                                   (22)
#define  SYS_REG_SYS_SRST0_rstn_hdic_axi_shift                                   (21)
#define  SYS_REG_SYS_SRST0_rstn_hdic_shift                                       (20)
#define  SYS_REG_SYS_SRST0_rstn_dtv_frontend_shift                               (19)
#define  SYS_REG_SYS_SRST0_rstn_kcpu_shift                                       (18)
#define  SYS_REG_SYS_SRST0_rstn_vde2_shift                                       (17)
#define  SYS_REG_SYS_SRST0_rstn_ve2_p2_shift                                     (16)
#define  SYS_REG_SYS_SRST0_rstn_ve2_shift                                        (15)
#define  SYS_REG_SYS_SRST0_rstn_vcpu2_shift                                      (14)
#define  SYS_REG_SYS_SRST0_rstn_rtk_demod_shift                                  (13)
#define  SYS_REG_SYS_SRST0_rstn_acpu_shift                                       (12)
#define  SYS_REG_SYS_SRST0_rstn_acpu2_shift                                      (11)
#define  SYS_REG_SYS_SRST0_rstn_ae2_shift                                        (10)
#define  SYS_REG_SYS_SRST0_rstn_ve_lgcy_p2_shift                                 (9)
#define  SYS_REG_SYS_SRST0_rstn_ve_lgcy_shift                                    (8)
#define  SYS_REG_SYS_SRST0_rstn_scpu_wrap_shift                                  (7)
#define  SYS_REG_SYS_SRST0_rstn_vde_shift                                        (6)
#define  SYS_REG_SYS_SRST0_rstn_ve_p2_shift                                      (5)
#define  SYS_REG_SYS_SRST0_rstn_ve_shift                                         (4)
#define  SYS_REG_SYS_SRST0_rstn_vcpu_shift                                       (3)
#define  SYS_REG_SYS_SRST0_rstn_ae_shift                                         (2)
#define  SYS_REG_SYS_SRST0_rstn_scpu_shift                                       (1)
#define  SYS_REG_SYS_SRST0_write_data_shift                                      (0)
#define  SYS_REG_SYS_SRST0_rstn_diseqc_mask                                      (0x80000000)
#define  SYS_REG_SYS_SRST0_rstn_cablerx_mask                                     (0x40000000)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_common_mask                                 (0x20000000)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre3_mask                                   (0x10000000)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre2_mask                                   (0x08000000)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre1_mask                                   (0x04000000)
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre0_mask                                   (0x02000000)
#define  SYS_REG_SYS_SRST0_rstn_img_demod_mask                                   (0x01000000)
#define  SYS_REG_SYS_SRST0_rstn_img_demod_wrap_mask                              (0x00800000)
#define  SYS_REG_SYS_SRST0_rstn_hdic_apb_mask                                    (0x00400000)
#define  SYS_REG_SYS_SRST0_rstn_hdic_axi_mask                                    (0x00200000)
#define  SYS_REG_SYS_SRST0_rstn_hdic_mask                                        (0x00100000)
#define  SYS_REG_SYS_SRST0_rstn_dtv_frontend_mask                                (0x00080000)
#define  SYS_REG_SYS_SRST0_rstn_kcpu_mask                                        (0x00040000)
#define  SYS_REG_SYS_SRST0_rstn_vde2_mask                                        (0x00020000)
#define  SYS_REG_SYS_SRST0_rstn_ve2_p2_mask                                      (0x00010000)
#define  SYS_REG_SYS_SRST0_rstn_ve2_mask                                         (0x00008000)
#define  SYS_REG_SYS_SRST0_rstn_vcpu2_mask                                       (0x00004000)
#define  SYS_REG_SYS_SRST0_rstn_rtk_demod_mask                                   (0x00002000)
#define  SYS_REG_SYS_SRST0_rstn_acpu_mask                                        (0x00001000)
#define  SYS_REG_SYS_SRST0_rstn_acpu2_mask                                       (0x00000800)
#define  SYS_REG_SYS_SRST0_rstn_ae2_mask                                         (0x00000400)
#define  SYS_REG_SYS_SRST0_rstn_ve_lgcy_p2_mask                                  (0x00000200)
#define  SYS_REG_SYS_SRST0_rstn_ve_lgcy_mask                                     (0x00000100)
#define  SYS_REG_SYS_SRST0_rstn_scpu_wrap_mask                                   (0x00000080)
#define  SYS_REG_SYS_SRST0_rstn_vde_mask                                         (0x00000040)
#define  SYS_REG_SYS_SRST0_rstn_ve_p2_mask                                       (0x00000020)
#define  SYS_REG_SYS_SRST0_rstn_ve_mask                                          (0x00000010)
#define  SYS_REG_SYS_SRST0_rstn_vcpu_mask                                        (0x00000008)
#define  SYS_REG_SYS_SRST0_rstn_ae_mask                                          (0x00000004)
#define  SYS_REG_SYS_SRST0_rstn_scpu_mask                                        (0x00000002)
#define  SYS_REG_SYS_SRST0_write_data_mask                                       (0x00000001)
#define  SYS_REG_SYS_SRST0_rstn_diseqc(data)                                     (0x80000000&((data)<<31))
#define  SYS_REG_SYS_SRST0_rstn_cablerx(data)                                    (0x40000000&((data)<<30))
#define  SYS_REG_SYS_SRST0_rstn_hdmi_common(data)                                (0x20000000&((data)<<29))
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre3(data)                                  (0x10000000&((data)<<28))
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre2(data)                                  (0x08000000&((data)<<27))
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre1(data)                                  (0x04000000&((data)<<26))
#define  SYS_REG_SYS_SRST0_rstn_hdmi_pre0(data)                                  (0x02000000&((data)<<25))
#define  SYS_REG_SYS_SRST0_rstn_img_demod(data)                                  (0x01000000&((data)<<24))
#define  SYS_REG_SYS_SRST0_rstn_img_demod_wrap(data)                             (0x00800000&((data)<<23))
#define  SYS_REG_SYS_SRST0_rstn_hdic_apb(data)                                   (0x00400000&((data)<<22))
#define  SYS_REG_SYS_SRST0_rstn_hdic_axi(data)                                   (0x00200000&((data)<<21))
#define  SYS_REG_SYS_SRST0_rstn_hdic(data)                                       (0x00100000&((data)<<20))
#define  SYS_REG_SYS_SRST0_rstn_dtv_frontend(data)                               (0x00080000&((data)<<19))
#define  SYS_REG_SYS_SRST0_rstn_kcpu(data)                                       (0x00040000&((data)<<18))
#define  SYS_REG_SYS_SRST0_rstn_vde2(data)                                       (0x00020000&((data)<<17))
#define  SYS_REG_SYS_SRST0_rstn_ve2_p2(data)                                     (0x00010000&((data)<<16))
#define  SYS_REG_SYS_SRST0_rstn_ve2(data)                                        (0x00008000&((data)<<15))
#define  SYS_REG_SYS_SRST0_rstn_vcpu2(data)                                      (0x00004000&((data)<<14))
#define  SYS_REG_SYS_SRST0_rstn_rtk_demod(data)                                  (0x00002000&((data)<<13))
#define  SYS_REG_SYS_SRST0_rstn_acpu(data)                                       (0x00001000&((data)<<12))
#define  SYS_REG_SYS_SRST0_rstn_acpu2(data)                                      (0x00000800&((data)<<11))
#define  SYS_REG_SYS_SRST0_rstn_ae2(data)                                        (0x00000400&((data)<<10))
#define  SYS_REG_SYS_SRST0_rstn_ve_lgcy_p2(data)                                 (0x00000200&((data)<<9))
#define  SYS_REG_SYS_SRST0_rstn_ve_lgcy(data)                                    (0x00000100&((data)<<8))
#define  SYS_REG_SYS_SRST0_rstn_scpu_wrap(data)                                  (0x00000080&((data)<<7))
#define  SYS_REG_SYS_SRST0_rstn_vde(data)                                        (0x00000040&((data)<<6))
#define  SYS_REG_SYS_SRST0_rstn_ve_p2(data)                                      (0x00000020&((data)<<5))
#define  SYS_REG_SYS_SRST0_rstn_ve(data)                                         (0x00000010&((data)<<4))
#define  SYS_REG_SYS_SRST0_rstn_vcpu(data)                                       (0x00000008&((data)<<3))
#define  SYS_REG_SYS_SRST0_rstn_ae(data)                                         (0x00000004&((data)<<2))
#define  SYS_REG_SYS_SRST0_rstn_scpu(data)                                       (0x00000002&((data)<<1))
#define  SYS_REG_SYS_SRST0_write_data(data)                                      (0x00000001&(data))
#define  SYS_REG_SYS_SRST0_get_rstn_diseqc(data)                                 ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_SRST0_get_rstn_cablerx(data)                                ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_SRST0_get_rstn_hdmi_common(data)                            ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_SRST0_get_rstn_hdmi_pre3(data)                              ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_SRST0_get_rstn_hdmi_pre2(data)                              ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_SRST0_get_rstn_hdmi_pre1(data)                              ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_SRST0_get_rstn_hdmi_pre0(data)                              ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_SRST0_get_rstn_img_demod(data)                              ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_SRST0_get_rstn_img_demod_wrap(data)                         ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_SRST0_get_rstn_hdic_apb(data)                               ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_SRST0_get_rstn_hdic_axi(data)                               ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_SRST0_get_rstn_hdic(data)                                   ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_SRST0_get_rstn_dtv_frontend(data)                           ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_SRST0_get_rstn_kcpu(data)                                   ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_SRST0_get_rstn_vde2(data)                                   ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_SRST0_get_rstn_ve2_p2(data)                                 ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_SRST0_get_rstn_ve2(data)                                    ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_SRST0_get_rstn_vcpu2(data)                                  ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_SRST0_get_rstn_rtk_demod(data)                              ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_SRST0_get_rstn_acpu(data)                                   ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_SRST0_get_rstn_acpu2(data)                                  ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_SRST0_get_rstn_ae2(data)                                    ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_SRST0_get_rstn_ve_lgcy_p2(data)                             ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_SRST0_get_rstn_ve_lgcy(data)                                ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_SRST0_get_rstn_scpu_wrap(data)                              ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_SRST0_get_rstn_vde(data)                                    ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_SRST0_get_rstn_ve_p2(data)                                  ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_SRST0_get_rstn_ve(data)                                     ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_SRST0_get_rstn_vcpu(data)                                   ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_SRST0_get_rstn_ae(data)                                     ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_SRST0_get_rstn_scpu(data)                                   ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_SRST0_get_write_data(data)                                  (0x00000001&(data))

#define  SYS_REG_SYS_SRST1                                                       0x18000104
#define  SYS_REG_SYS_SRST1_reg_addr                                              "0xB8000104"
#define  SYS_REG_SYS_SRST1_reg                                                   0xB8000104
#define  SYS_REG_SYS_SRST1_inst_addr                                             "0x0001"
#define  set_SYS_REG_SYS_SRST1_reg(data)                                         (*((volatile unsigned int*)SYS_REG_SYS_SRST1_reg)=data)
#define  get_SYS_REG_SYS_SRST1_reg                                               (*((volatile unsigned int*)SYS_REG_SYS_SRST1_reg))
#define  SYS_REG_SYS_SRST1_rstn_tvsb1_shift                                      (31)
#define  SYS_REG_SYS_SRST1_rstn_tvsb2_shift                                      (30)
#define  SYS_REG_SYS_SRST1_rstn_tvsb3_shift                                      (29)
#define  SYS_REG_SYS_SRST1_rstn_tvsb4_shift                                      (28)
#define  SYS_REG_SYS_SRST1_rstn_tvsb5_shift                                      (27)
#define  SYS_REG_SYS_SRST1_rstn_tve_shift                                        (26)
#define  SYS_REG_SYS_SRST1_rstn_dcphy_shift                                      (25)
#define  SYS_REG_SYS_SRST1_rstn_dcu_shift                                        (24)
#define  SYS_REG_SYS_SRST1_rstn_if_demod_shift                                   (23)
#define  SYS_REG_SYS_SRST1_rstn_vdec_shift                                       (22)
#define  SYS_REG_SYS_SRST1_rstn_vdec2_shift                                      (21)
#define  SYS_REG_SYS_SRST1_rstn_vbis0_shift                                      (20)
#define  SYS_REG_SYS_SRST1_rstn_audio2_dac_shift                                 (19)
#define  SYS_REG_SYS_SRST1_rstn_audio_adc_shift                                  (18)
#define  SYS_REG_SYS_SRST1_rstn_audio_dac_shift                                  (17)
#define  SYS_REG_SYS_SRST1_rstn_audio_shift                                      (16)
#define  SYS_REG_SYS_SRST1_rstn_ifadc_shift                                      (15)
#define  SYS_REG_SYS_SRST1_rstn_cbus_shift                                       (14)
#define  SYS_REG_SYS_SRST1_rstn_offms_shift                                      (13)
#define  SYS_REG_SYS_SRST1_rstn_me_shift                                         (12)
#define  SYS_REG_SYS_SRST1_rstn_apll_adc_shift                                   (11)
#define  SYS_REG_SYS_SRST1_rstn_hdmi_shift                                       (10)
#define  SYS_REG_SYS_SRST1_rstn_dispd_shift                                      (9)
#define  SYS_REG_SYS_SRST1_rstn_tp_shift                                         (8)
#define  SYS_REG_SYS_SRST1_rstn_cp_shift                                         (7)
#define  SYS_REG_SYS_SRST1_rstn_md_shift                                         (6)
#define  SYS_REG_SYS_SRST1_rstn_se_shift                                         (5)
#define  SYS_REG_SYS_SRST1_dummy_4_shift                                         (4)
#define  SYS_REG_SYS_SRST1_rstn_3d_gde_shift                                     (3)
#define  SYS_REG_SYS_SRST1_rstn_vodma_shift                                      (2)
#define  SYS_REG_SYS_SRST1_rstn_dispi_shift                                      (1)
#define  SYS_REG_SYS_SRST1_write_data_shift                                      (0)
#define  SYS_REG_SYS_SRST1_rstn_tvsb1_mask                                       (0x80000000)
#define  SYS_REG_SYS_SRST1_rstn_tvsb2_mask                                       (0x40000000)
#define  SYS_REG_SYS_SRST1_rstn_tvsb3_mask                                       (0x20000000)
#define  SYS_REG_SYS_SRST1_rstn_tvsb4_mask                                       (0x10000000)
#define  SYS_REG_SYS_SRST1_rstn_tvsb5_mask                                       (0x08000000)
#define  SYS_REG_SYS_SRST1_rstn_tve_mask                                         (0x04000000)
#define  SYS_REG_SYS_SRST1_rstn_dcphy_mask                                       (0x02000000)
#define  SYS_REG_SYS_SRST1_rstn_dcu_mask                                         (0x01000000)
#define  SYS_REG_SYS_SRST1_rstn_if_demod_mask                                    (0x00800000)
#define  SYS_REG_SYS_SRST1_rstn_vdec_mask                                        (0x00400000)
#define  SYS_REG_SYS_SRST1_rstn_vdec2_mask                                       (0x00200000)
#define  SYS_REG_SYS_SRST1_rstn_vbis0_mask                                       (0x00100000)
#define  SYS_REG_SYS_SRST1_rstn_audio2_dac_mask                                  (0x00080000)
#define  SYS_REG_SYS_SRST1_rstn_audio_adc_mask                                   (0x00040000)
#define  SYS_REG_SYS_SRST1_rstn_audio_dac_mask                                   (0x00020000)
#define  SYS_REG_SYS_SRST1_rstn_audio_mask                                       (0x00010000)
#define  SYS_REG_SYS_SRST1_rstn_ifadc_mask                                       (0x00008000)
#define  SYS_REG_SYS_SRST1_rstn_cbus_mask                                        (0x00004000)
#define  SYS_REG_SYS_SRST1_rstn_offms_mask                                       (0x00002000)
#define  SYS_REG_SYS_SRST1_rstn_me_mask                                          (0x00001000)
#define  SYS_REG_SYS_SRST1_rstn_apll_adc_mask                                    (0x00000800)
#define  SYS_REG_SYS_SRST1_rstn_hdmi_mask                                        (0x00000400)
#define  SYS_REG_SYS_SRST1_rstn_dispd_mask                                       (0x00000200)
#define  SYS_REG_SYS_SRST1_rstn_tp_mask                                          (0x00000100)
#define  SYS_REG_SYS_SRST1_rstn_cp_mask                                          (0x00000080)
#define  SYS_REG_SYS_SRST1_rstn_md_mask                                          (0x00000040)
#define  SYS_REG_SYS_SRST1_rstn_se_mask                                          (0x00000020)
#define  SYS_REG_SYS_SRST1_dummy_4_mask                                          (0x00000010)
#define  SYS_REG_SYS_SRST1_rstn_3d_gde_mask                                      (0x00000008)
#define  SYS_REG_SYS_SRST1_rstn_vodma_mask                                       (0x00000004)
#define  SYS_REG_SYS_SRST1_rstn_dispi_mask                                       (0x00000002)
#define  SYS_REG_SYS_SRST1_write_data_mask                                       (0x00000001)
#define  SYS_REG_SYS_SRST1_rstn_tvsb1(data)                                      (0x80000000&((data)<<31))
#define  SYS_REG_SYS_SRST1_rstn_tvsb2(data)                                      (0x40000000&((data)<<30))
#define  SYS_REG_SYS_SRST1_rstn_tvsb3(data)                                      (0x20000000&((data)<<29))
#define  SYS_REG_SYS_SRST1_rstn_tvsb4(data)                                      (0x10000000&((data)<<28))
#define  SYS_REG_SYS_SRST1_rstn_tvsb5(data)                                      (0x08000000&((data)<<27))
#define  SYS_REG_SYS_SRST1_rstn_tve(data)                                        (0x04000000&((data)<<26))
#define  SYS_REG_SYS_SRST1_rstn_dcphy(data)                                      (0x02000000&((data)<<25))
#define  SYS_REG_SYS_SRST1_rstn_dcu(data)                                        (0x01000000&((data)<<24))
#define  SYS_REG_SYS_SRST1_rstn_if_demod(data)                                   (0x00800000&((data)<<23))
#define  SYS_REG_SYS_SRST1_rstn_vdec(data)                                       (0x00400000&((data)<<22))
#define  SYS_REG_SYS_SRST1_rstn_vdec2(data)                                      (0x00200000&((data)<<21))
#define  SYS_REG_SYS_SRST1_rstn_vbis0(data)                                      (0x00100000&((data)<<20))
#define  SYS_REG_SYS_SRST1_rstn_audio2_dac(data)                                 (0x00080000&((data)<<19))
#define  SYS_REG_SYS_SRST1_rstn_audio_adc(data)                                  (0x00040000&((data)<<18))
#define  SYS_REG_SYS_SRST1_rstn_audio_dac(data)                                  (0x00020000&((data)<<17))
#define  SYS_REG_SYS_SRST1_rstn_audio(data)                                      (0x00010000&((data)<<16))
#define  SYS_REG_SYS_SRST1_rstn_ifadc(data)                                      (0x00008000&((data)<<15))
#define  SYS_REG_SYS_SRST1_rstn_cbus(data)                                       (0x00004000&((data)<<14))
#define  SYS_REG_SYS_SRST1_rstn_offms(data)                                      (0x00002000&((data)<<13))
#define  SYS_REG_SYS_SRST1_rstn_me(data)                                         (0x00001000&((data)<<12))
#define  SYS_REG_SYS_SRST1_rstn_apll_adc(data)                                   (0x00000800&((data)<<11))
#define  SYS_REG_SYS_SRST1_rstn_hdmi(data)                                       (0x00000400&((data)<<10))
#define  SYS_REG_SYS_SRST1_rstn_dispd(data)                                      (0x00000200&((data)<<9))
#define  SYS_REG_SYS_SRST1_rstn_tp(data)                                         (0x00000100&((data)<<8))
#define  SYS_REG_SYS_SRST1_rstn_cp(data)                                         (0x00000080&((data)<<7))
#define  SYS_REG_SYS_SRST1_rstn_md(data)                                         (0x00000040&((data)<<6))
#define  SYS_REG_SYS_SRST1_rstn_se(data)                                         (0x00000020&((data)<<5))
#define  SYS_REG_SYS_SRST1_dummy_4(data)                                         (0x00000010&((data)<<4))
#define  SYS_REG_SYS_SRST1_rstn_3d_gde(data)                                     (0x00000008&((data)<<3))
#define  SYS_REG_SYS_SRST1_rstn_vodma(data)                                      (0x00000004&((data)<<2))
#define  SYS_REG_SYS_SRST1_rstn_dispi(data)                                      (0x00000002&((data)<<1))
#define  SYS_REG_SYS_SRST1_write_data(data)                                      (0x00000001&(data))
#define  SYS_REG_SYS_SRST1_get_rstn_tvsb1(data)                                  ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_SRST1_get_rstn_tvsb2(data)                                  ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_SRST1_get_rstn_tvsb3(data)                                  ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_SRST1_get_rstn_tvsb4(data)                                  ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_SRST1_get_rstn_tvsb5(data)                                  ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_SRST1_get_rstn_tve(data)                                    ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_SRST1_get_rstn_dcphy(data)                                  ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_SRST1_get_rstn_dcu(data)                                    ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_SRST1_get_rstn_if_demod(data)                               ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_SRST1_get_rstn_vdec(data)                                   ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_SRST1_get_rstn_vdec2(data)                                  ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_SRST1_get_rstn_vbis0(data)                                  ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_SRST1_get_rstn_audio2_dac(data)                             ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_SRST1_get_rstn_audio_adc(data)                              ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_SRST1_get_rstn_audio_dac(data)                              ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_SRST1_get_rstn_audio(data)                                  ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_SRST1_get_rstn_ifadc(data)                                  ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_SRST1_get_rstn_cbus(data)                                   ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_SRST1_get_rstn_offms(data)                                  ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_SRST1_get_rstn_me(data)                                     ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_SRST1_get_rstn_apll_adc(data)                               ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_SRST1_get_rstn_hdmi(data)                                   ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_SRST1_get_rstn_dispd(data)                                  ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_SRST1_get_rstn_tp(data)                                     ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_SRST1_get_rstn_cp(data)                                     ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_SRST1_get_rstn_md(data)                                     ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_SRST1_get_rstn_se(data)                                     ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_SRST1_get_dummy_4(data)                                     ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_SRST1_get_rstn_3d_gde(data)                                 ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_SRST1_get_rstn_vodma(data)                                  ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_SRST1_get_rstn_dispi(data)                                  ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_SRST1_get_write_data(data)                                  (0x00000001&(data))

#define  SYS_REG_SYS_SRST2                                                       0x18000108
#define  SYS_REG_SYS_SRST2_reg_addr                                              "0xB8000108"
#define  SYS_REG_SYS_SRST2_reg                                                   0xB8000108
#define  SYS_REG_SYS_SRST2_inst_addr                                             "0x0002"
#define  set_SYS_REG_SYS_SRST2_reg(data)                                         (*((volatile unsigned int*)SYS_REG_SYS_SRST2_reg)=data)
#define  get_SYS_REG_SYS_SRST2_reg                                               (*((volatile unsigned int*)SYS_REG_SYS_SRST2_reg))
#define  SYS_REG_SYS_SRST2_rstn_usb2_ex_shift                                    (29)
#define  SYS_REG_SYS_SRST2_rstn_tm_shift                                         (28)
#define  SYS_REG_SYS_SRST2_rstn_atvin2_shift                                     (27)
#define  SYS_REG_SYS_SRST2_rstn_atvin_shift                                      (26)
#define  SYS_REG_SYS_SRST2_rstn_dispm_cap_shift                                  (25)
#define  SYS_REG_SYS_SRST2_rstn_dispm_disp_shift                                 (24)
#define  SYS_REG_SYS_SRST2_rstn_emmc_shift                                       (23)
#define  SYS_REG_SYS_SRST2_rstn_if_demod_logic_shift                             (22)
#define  SYS_REG_SYS_SRST2_rstn_bistreg_shift                                    (21)
#define  SYS_REG_SYS_SRST2_rstn_i2c4_shift                                       (20)
#define  SYS_REG_SYS_SRST2_rstn_pllreg_shift                                     (19)
#define  SYS_REG_SYS_SRST2_rstn_usb3_shift                                       (18)
#define  SYS_REG_SYS_SRST2_rstn_usb2_shift                                       (17)
#define  SYS_REG_SYS_SRST2_rstn_pcmcia_shift                                     (16)
#define  SYS_REG_SYS_SRST2_dummy_15_shift                                        (15)
#define  SYS_REG_SYS_SRST2_rstn_i2c3_shift                                       (14)
#define  SYS_REG_SYS_SRST2_rstn_irtx_shift                                       (13)
#define  SYS_REG_SYS_SRST2_dummy_12_shift                                        (12)
#define  SYS_REG_SYS_SRST2_rstn_dtv_demod_shift                                  (11)
#define  SYS_REG_SYS_SRST2_rstn_misc_shift                                       (10)
#define  SYS_REG_SYS_SRST2_rstn_pwm_shift                                        (9)
#define  SYS_REG_SYS_SRST2_rstn_uart1_shift                                      (8)
#define  SYS_REG_SYS_SRST2_rstn_uart2_shift                                      (7)
#define  SYS_REG_SYS_SRST2_dummy_6_shift                                         (6)
#define  SYS_REG_SYS_SRST2_rstn_gpio_shift                                       (5)
#define  SYS_REG_SYS_SRST2_rstn_i2c1_shift                                       (4)
#define  SYS_REG_SYS_SRST2_rstn_i2c2_shift                                       (3)
#define  SYS_REG_SYS_SRST2_rstn_nf_shift                                         (2)
#define  SYS_REG_SYS_SRST2_rstn_sc_shift                                         (1)
#define  SYS_REG_SYS_SRST2_write_data_shift                                      (0)
#define  SYS_REG_SYS_SRST2_rstn_usb2_ex_mask                                     (0x20000000)
#define  SYS_REG_SYS_SRST2_rstn_tm_mask                                          (0x10000000)
#define  SYS_REG_SYS_SRST2_rstn_atvin2_mask                                      (0x08000000)
#define  SYS_REG_SYS_SRST2_rstn_atvin_mask                                       (0x04000000)
#define  SYS_REG_SYS_SRST2_rstn_dispm_cap_mask                                   (0x02000000)
#define  SYS_REG_SYS_SRST2_rstn_dispm_disp_mask                                  (0x01000000)
#define  SYS_REG_SYS_SRST2_rstn_emmc_mask                                        (0x00800000)
#define  SYS_REG_SYS_SRST2_rstn_if_demod_logic_mask                              (0x00400000)
#define  SYS_REG_SYS_SRST2_rstn_bistreg_mask                                     (0x00200000)
#define  SYS_REG_SYS_SRST2_rstn_i2c4_mask                                        (0x00100000)
#define  SYS_REG_SYS_SRST2_rstn_pllreg_mask                                      (0x00080000)
#define  SYS_REG_SYS_SRST2_rstn_usb3_mask                                        (0x00040000)
#define  SYS_REG_SYS_SRST2_rstn_usb2_mask                                        (0x00020000)
#define  SYS_REG_SYS_SRST2_rstn_pcmcia_mask                                      (0x00010000)
#define  SYS_REG_SYS_SRST2_dummy_15_mask                                         (0x00008000)
#define  SYS_REG_SYS_SRST2_rstn_i2c3_mask                                        (0x00004000)
#define  SYS_REG_SYS_SRST2_rstn_irtx_mask                                        (0x00002000)
#define  SYS_REG_SYS_SRST2_dummy_12_mask                                         (0x00001000)
#define  SYS_REG_SYS_SRST2_rstn_dtv_demod_mask                                   (0x00000800)
#define  SYS_REG_SYS_SRST2_rstn_misc_mask                                        (0x00000400)
#define  SYS_REG_SYS_SRST2_rstn_pwm_mask                                         (0x00000200)
#define  SYS_REG_SYS_SRST2_rstn_uart1_mask                                       (0x00000100)
#define  SYS_REG_SYS_SRST2_rstn_uart2_mask                                       (0x00000080)
#define  SYS_REG_SYS_SRST2_dummy_6_mask                                          (0x00000040)
#define  SYS_REG_SYS_SRST2_rstn_gpio_mask                                        (0x00000020)
#define  SYS_REG_SYS_SRST2_rstn_i2c1_mask                                        (0x00000010)
#define  SYS_REG_SYS_SRST2_rstn_i2c2_mask                                        (0x00000008)
#define  SYS_REG_SYS_SRST2_rstn_nf_mask                                          (0x00000004)
#define  SYS_REG_SYS_SRST2_rstn_sc_mask                                          (0x00000002)
#define  SYS_REG_SYS_SRST2_write_data_mask                                       (0x00000001)
#define  SYS_REG_SYS_SRST2_rstn_usb2_ex(data)                                    (0x20000000&((data)<<29))
#define  SYS_REG_SYS_SRST2_rstn_tm(data)                                         (0x10000000&((data)<<28))
#define  SYS_REG_SYS_SRST2_rstn_atvin2(data)                                     (0x08000000&((data)<<27))
#define  SYS_REG_SYS_SRST2_rstn_atvin(data)                                      (0x04000000&((data)<<26))
#define  SYS_REG_SYS_SRST2_rstn_dispm_cap(data)                                  (0x02000000&((data)<<25))
#define  SYS_REG_SYS_SRST2_rstn_dispm_disp(data)                                 (0x01000000&((data)<<24))
#define  SYS_REG_SYS_SRST2_rstn_emmc(data)                                       (0x00800000&((data)<<23))
#define  SYS_REG_SYS_SRST2_rstn_if_demod_logic(data)                             (0x00400000&((data)<<22))
#define  SYS_REG_SYS_SRST2_rstn_bistreg(data)                                    (0x00200000&((data)<<21))
#define  SYS_REG_SYS_SRST2_rstn_i2c4(data)                                       (0x00100000&((data)<<20))
#define  SYS_REG_SYS_SRST2_rstn_pllreg(data)                                     (0x00080000&((data)<<19))
#define  SYS_REG_SYS_SRST2_rstn_usb3(data)                                       (0x00040000&((data)<<18))
#define  SYS_REG_SYS_SRST2_rstn_usb2(data)                                       (0x00020000&((data)<<17))
#define  SYS_REG_SYS_SRST2_rstn_pcmcia(data)                                     (0x00010000&((data)<<16))
#define  SYS_REG_SYS_SRST2_dummy_15(data)                                        (0x00008000&((data)<<15))
#define  SYS_REG_SYS_SRST2_rstn_i2c3(data)                                       (0x00004000&((data)<<14))
#define  SYS_REG_SYS_SRST2_rstn_irtx(data)                                       (0x00002000&((data)<<13))
#define  SYS_REG_SYS_SRST2_dummy_12(data)                                        (0x00001000&((data)<<12))
#define  SYS_REG_SYS_SRST2_rstn_dtv_demod(data)                                  (0x00000800&((data)<<11))
#define  SYS_REG_SYS_SRST2_rstn_misc(data)                                       (0x00000400&((data)<<10))
#define  SYS_REG_SYS_SRST2_rstn_pwm(data)                                        (0x00000200&((data)<<9))
#define  SYS_REG_SYS_SRST2_rstn_uart1(data)                                      (0x00000100&((data)<<8))
#define  SYS_REG_SYS_SRST2_rstn_uart2(data)                                      (0x00000080&((data)<<7))
#define  SYS_REG_SYS_SRST2_dummy_6(data)                                         (0x00000040&((data)<<6))
#define  SYS_REG_SYS_SRST2_rstn_gpio(data)                                       (0x00000020&((data)<<5))
#define  SYS_REG_SYS_SRST2_rstn_i2c1(data)                                       (0x00000010&((data)<<4))
#define  SYS_REG_SYS_SRST2_rstn_i2c2(data)                                       (0x00000008&((data)<<3))
#define  SYS_REG_SYS_SRST2_rstn_nf(data)                                         (0x00000004&((data)<<2))
#define  SYS_REG_SYS_SRST2_rstn_sc(data)                                         (0x00000002&((data)<<1))
#define  SYS_REG_SYS_SRST2_write_data(data)                                      (0x00000001&(data))
#define  SYS_REG_SYS_SRST2_get_rstn_usb2_ex(data)                                ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_SRST2_get_rstn_tm(data)                                     ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_SRST2_get_rstn_atvin2(data)                                 ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_SRST2_get_rstn_atvin(data)                                  ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_SRST2_get_rstn_dispm_cap(data)                              ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_SRST2_get_rstn_dispm_disp(data)                             ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_SRST2_get_rstn_emmc(data)                                   ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_SRST2_get_rstn_if_demod_logic(data)                         ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_SRST2_get_rstn_bistreg(data)                                ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_SRST2_get_rstn_i2c4(data)                                   ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_SRST2_get_rstn_pllreg(data)                                 ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_SRST2_get_rstn_usb3(data)                                   ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_SRST2_get_rstn_usb2(data)                                   ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_SRST2_get_rstn_pcmcia(data)                                 ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_SRST2_get_dummy_15(data)                                    ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_SRST2_get_rstn_i2c3(data)                                   ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_SRST2_get_rstn_irtx(data)                                   ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_SRST2_get_dummy_12(data)                                    ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_SRST2_get_rstn_dtv_demod(data)                              ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_SRST2_get_rstn_misc(data)                                   ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_SRST2_get_rstn_pwm(data)                                    ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_SRST2_get_rstn_uart1(data)                                  ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_SRST2_get_rstn_uart2(data)                                  ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_SRST2_get_dummy_6(data)                                     ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_SRST2_get_rstn_gpio(data)                                   ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_SRST2_get_rstn_i2c1(data)                                   ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_SRST2_get_rstn_i2c2(data)                                   ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_SRST2_get_rstn_nf(data)                                     ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_SRST2_get_rstn_sc(data)                                     ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_SRST2_get_write_data(data)                                  (0x00000001&(data))

#define  SYS_REG_SYS_SRST3                                                       0x1800010C
#define  SYS_REG_SYS_SRST3_reg_addr                                              "0xB800010C"
#define  SYS_REG_SYS_SRST3_reg                                                   0xB800010C
#define  SYS_REG_SYS_SRST3_inst_addr                                             "0x0003"
#define  set_SYS_REG_SYS_SRST3_reg(data)                                         (*((volatile unsigned int*)SYS_REG_SYS_SRST3_reg)=data)
#define  get_SYS_REG_SYS_SRST3_reg                                               (*((volatile unsigned int*)SYS_REG_SYS_SRST3_reg))
#define  SYS_REG_SYS_SRST3_rstn_memc_shift                                       (31)
#define  SYS_REG_SYS_SRST3_rstn_memc_me_shift                                    (30)
#define  SYS_REG_SYS_SRST3_rstn_memc_rbus_shift                                  (29)
#define  SYS_REG_SYS_SRST3_rstn_dcphy2_shift                                     (25)
#define  SYS_REG_SYS_SRST3_rstn_dcu2_shift                                       (24)
#define  SYS_REG_SYS_SRST3_rstn_dcphy_mc_shift                                   (23)
#define  SYS_REG_SYS_SRST3_rstn_disp_lg_hcic_shift                               (22)
#define  SYS_REG_SYS_SRST3_rstn_disp_lg_mplus_shift                              (21)
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_pxl_shift                             (20)
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_apb_shift                             (19)
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_mcu_shift                             (18)
#define  SYS_REG_SYS_SRST3_rstn_ddc_shift                                        (17)
#define  SYS_REG_SYS_SRST3_rstn_sd_shift                                         (16)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p3_shift                                (7)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p2_shift                                (6)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p1_shift                                (5)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p0_shift                                (4)
#define  SYS_REG_SYS_SRST3_rstn_usb3_phy_p0_shift                                (2)
#define  SYS_REG_SYS_SRST3_rstn_usb3_mdio_p0_shift                               (1)
#define  SYS_REG_SYS_SRST3_write_data_shift                                      (0)
#define  SYS_REG_SYS_SRST3_rstn_memc_mask                                        (0x80000000)
#define  SYS_REG_SYS_SRST3_rstn_memc_me_mask                                     (0x40000000)
#define  SYS_REG_SYS_SRST3_rstn_memc_rbus_mask                                   (0x20000000)
#define  SYS_REG_SYS_SRST3_rstn_dcphy2_mask                                      (0x02000000)
#define  SYS_REG_SYS_SRST3_rstn_dcu2_mask                                        (0x01000000)
#define  SYS_REG_SYS_SRST3_rstn_dcphy_mc_mask                                    (0x00800000)
#define  SYS_REG_SYS_SRST3_rstn_disp_lg_hcic_mask                                (0x00400000)
#define  SYS_REG_SYS_SRST3_rstn_disp_lg_mplus_mask                               (0x00200000)
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_pxl_mask                              (0x00100000)
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_apb_mask                              (0x00080000)
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_mcu_mask                              (0x00040000)
#define  SYS_REG_SYS_SRST3_rstn_ddc_mask                                         (0x00020000)
#define  SYS_REG_SYS_SRST3_rstn_sd_mask                                          (0x00010000)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p3_mask                                 (0x00000080)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p2_mask                                 (0x00000040)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p1_mask                                 (0x00000020)
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p0_mask                                 (0x00000010)
#define  SYS_REG_SYS_SRST3_rstn_usb3_phy_p0_mask                                 (0x00000004)
#define  SYS_REG_SYS_SRST3_rstn_usb3_mdio_p0_mask                                (0x00000002)
#define  SYS_REG_SYS_SRST3_write_data_mask                                       (0x00000001)
#define  SYS_REG_SYS_SRST3_rstn_memc(data)                                       (0x80000000&((data)<<31))
#define  SYS_REG_SYS_SRST3_rstn_memc_me(data)                                    (0x40000000&((data)<<30))
#define  SYS_REG_SYS_SRST3_rstn_memc_rbus(data)                                  (0x20000000&((data)<<29))
#define  SYS_REG_SYS_SRST3_rstn_dcphy2(data)                                     (0x02000000&((data)<<25))
#define  SYS_REG_SYS_SRST3_rstn_dcu2(data)                                       (0x01000000&((data)<<24))
#define  SYS_REG_SYS_SRST3_rstn_dcphy_mc(data)                                   (0x00800000&((data)<<23))
#define  SYS_REG_SYS_SRST3_rstn_disp_lg_hcic(data)                               (0x00400000&((data)<<22))
#define  SYS_REG_SYS_SRST3_rstn_disp_lg_mplus(data)                              (0x00200000&((data)<<21))
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_pxl(data)                             (0x00100000&((data)<<20))
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_apb(data)                             (0x00080000&((data)<<19))
#define  SYS_REG_SYS_SRST3_rstn_d_boe_rgbw_mcu(data)                             (0x00040000&((data)<<18))
#define  SYS_REG_SYS_SRST3_rstn_ddc(data)                                        (0x00020000&((data)<<17))
#define  SYS_REG_SYS_SRST3_rstn_sd(data)                                         (0x00010000&((data)<<16))
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p3(data)                                (0x00000080&((data)<<7))
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p2(data)                                (0x00000040&((data)<<6))
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p1(data)                                (0x00000020&((data)<<5))
#define  SYS_REG_SYS_SRST3_rstn_usb2_phy_p0(data)                                (0x00000010&((data)<<4))
#define  SYS_REG_SYS_SRST3_rstn_usb3_phy_p0(data)                                (0x00000004&((data)<<2))
#define  SYS_REG_SYS_SRST3_rstn_usb3_mdio_p0(data)                               (0x00000002&((data)<<1))
#define  SYS_REG_SYS_SRST3_write_data(data)                                      (0x00000001&(data))
#define  SYS_REG_SYS_SRST3_get_rstn_memc(data)                                   ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_SRST3_get_rstn_memc_me(data)                                ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_SRST3_get_rstn_memc_rbus(data)                              ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_SRST3_get_rstn_dcphy2(data)                                 ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_SRST3_get_rstn_dcu2(data)                                   ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_SRST3_get_rstn_dcphy_mc(data)                               ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_SRST3_get_rstn_disp_lg_hcic(data)                           ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_SRST3_get_rstn_disp_lg_mplus(data)                          ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_SRST3_get_rstn_d_boe_rgbw_pxl(data)                         ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_SRST3_get_rstn_d_boe_rgbw_apb(data)                         ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_SRST3_get_rstn_d_boe_rgbw_mcu(data)                         ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_SRST3_get_rstn_ddc(data)                                    ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_SRST3_get_rstn_sd(data)                                     ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_SRST3_get_rstn_usb2_phy_p3(data)                            ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_SRST3_get_rstn_usb2_phy_p2(data)                            ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_SRST3_get_rstn_usb2_phy_p1(data)                            ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_SRST3_get_rstn_usb2_phy_p0(data)                            ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_SRST3_get_rstn_usb3_phy_p0(data)                            ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_SRST3_get_rstn_usb3_mdio_p0(data)                           ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_SRST3_get_write_data(data)                                  (0x00000001&(data))

#define  SYS_REG_SYS_CLKEN0                                                      0x18000110
#define  SYS_REG_SYS_CLKEN0_reg_addr                                             "0xB8000110"
#define  SYS_REG_SYS_CLKEN0_reg                                                  0xB8000110
#define  SYS_REG_SYS_CLKEN0_inst_addr                                            "0x0004"
#define  set_SYS_REG_SYS_CLKEN0_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CLKEN0_reg)=data)
#define  get_SYS_REG_SYS_CLKEN0_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CLKEN0_reg))
#define  SYS_REG_SYS_CLKEN0_clken_diseqc_shift                                   (31)
#define  SYS_REG_SYS_CLKEN0_clken_cablerx_shift                                  (30)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_common_shift                              (29)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre3_shift                                (28)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre2_shift                                (27)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre1_shift                                (26)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre0_shift                                (25)
#define  SYS_REG_SYS_CLKEN0_clken_img_demod_shift                                (24)
#define  SYS_REG_SYS_CLKEN0_clken_img_demod_wrap_shift                           (23)
#define  SYS_REG_SYS_CLKEN0_clken_hdic_shift                                     (20)
#define  SYS_REG_SYS_CLKEN0_clken_dtv_frontend_shift                             (19)
#define  SYS_REG_SYS_CLKEN0_clken_kcpu_shift                                     (18)
#define  SYS_REG_SYS_CLKEN0_clken_ve2_p2_shift                                   (16)
#define  SYS_REG_SYS_CLKEN0_clken_ve2_shift                                      (15)
#define  SYS_REG_SYS_CLKEN0_clken_vcpu2_shift                                    (14)
#define  SYS_REG_SYS_CLKEN0_clken_rtk_demod_shift                                (13)
#define  SYS_REG_SYS_CLKEN0_clken_acpu_shift                                     (12)
#define  SYS_REG_SYS_CLKEN0_clken_acpu2_shift                                    (11)
#define  SYS_REG_SYS_CLKEN0_clken_ve_lgcy_p2_shift                               (7)
#define  SYS_REG_SYS_CLKEN0_clken_ve_lgcy_shift                                  (6)
#define  SYS_REG_SYS_CLKEN0_clken_ve_p2_shift                                    (5)
#define  SYS_REG_SYS_CLKEN0_clken_ve_shift                                       (4)
#define  SYS_REG_SYS_CLKEN0_clken_vcpu_shift                                     (3)
#define  SYS_REG_SYS_CLKEN0_clken_scpu_wrap_shift                                (2)
#define  SYS_REG_SYS_CLKEN0_clken_scpu_shift                                     (1)
#define  SYS_REG_SYS_CLKEN0_write_data_shift                                     (0)
#define  SYS_REG_SYS_CLKEN0_clken_diseqc_mask                                    (0x80000000)
#define  SYS_REG_SYS_CLKEN0_clken_cablerx_mask                                   (0x40000000)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_common_mask                               (0x20000000)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre3_mask                                 (0x10000000)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre2_mask                                 (0x08000000)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre1_mask                                 (0x04000000)
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre0_mask                                 (0x02000000)
#define  SYS_REG_SYS_CLKEN0_clken_img_demod_mask                                 (0x01000000)
#define  SYS_REG_SYS_CLKEN0_clken_img_demod_wrap_mask                            (0x00800000)
#define  SYS_REG_SYS_CLKEN0_clken_hdic_mask                                      (0x00100000)
#define  SYS_REG_SYS_CLKEN0_clken_dtv_frontend_mask                              (0x00080000)
#define  SYS_REG_SYS_CLKEN0_clken_kcpu_mask                                      (0x00040000)
#define  SYS_REG_SYS_CLKEN0_clken_ve2_p2_mask                                    (0x00010000)
#define  SYS_REG_SYS_CLKEN0_clken_ve2_mask                                       (0x00008000)
#define  SYS_REG_SYS_CLKEN0_clken_vcpu2_mask                                     (0x00004000)
#define  SYS_REG_SYS_CLKEN0_clken_rtk_demod_mask                                 (0x00002000)
#define  SYS_REG_SYS_CLKEN0_clken_acpu_mask                                      (0x00001000)
#define  SYS_REG_SYS_CLKEN0_clken_acpu2_mask                                     (0x00000800)
#define  SYS_REG_SYS_CLKEN0_clken_ve_lgcy_p2_mask                                (0x00000080)
#define  SYS_REG_SYS_CLKEN0_clken_ve_lgcy_mask                                   (0x00000040)
#define  SYS_REG_SYS_CLKEN0_clken_ve_p2_mask                                     (0x00000020)
#define  SYS_REG_SYS_CLKEN0_clken_ve_mask                                        (0x00000010)
#define  SYS_REG_SYS_CLKEN0_clken_vcpu_mask                                      (0x00000008)
#define  SYS_REG_SYS_CLKEN0_clken_scpu_wrap_mask                                 (0x00000004)
#define  SYS_REG_SYS_CLKEN0_clken_scpu_mask                                      (0x00000002)
#define  SYS_REG_SYS_CLKEN0_write_data_mask                                      (0x00000001)
#define  SYS_REG_SYS_CLKEN0_clken_diseqc(data)                                   (0x80000000&((data)<<31))
#define  SYS_REG_SYS_CLKEN0_clken_cablerx(data)                                  (0x40000000&((data)<<30))
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_common(data)                              (0x20000000&((data)<<29))
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre3(data)                                (0x10000000&((data)<<28))
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre2(data)                                (0x08000000&((data)<<27))
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre1(data)                                (0x04000000&((data)<<26))
#define  SYS_REG_SYS_CLKEN0_clken_hdmi_pre0(data)                                (0x02000000&((data)<<25))
#define  SYS_REG_SYS_CLKEN0_clken_img_demod(data)                                (0x01000000&((data)<<24))
#define  SYS_REG_SYS_CLKEN0_clken_img_demod_wrap(data)                           (0x00800000&((data)<<23))
#define  SYS_REG_SYS_CLKEN0_clken_hdic(data)                                     (0x00100000&((data)<<20))
#define  SYS_REG_SYS_CLKEN0_clken_dtv_frontend(data)                             (0x00080000&((data)<<19))
#define  SYS_REG_SYS_CLKEN0_clken_kcpu(data)                                     (0x00040000&((data)<<18))
#define  SYS_REG_SYS_CLKEN0_clken_ve2_p2(data)                                   (0x00010000&((data)<<16))
#define  SYS_REG_SYS_CLKEN0_clken_ve2(data)                                      (0x00008000&((data)<<15))
#define  SYS_REG_SYS_CLKEN0_clken_vcpu2(data)                                    (0x00004000&((data)<<14))
#define  SYS_REG_SYS_CLKEN0_clken_rtk_demod(data)                                (0x00002000&((data)<<13))
#define  SYS_REG_SYS_CLKEN0_clken_acpu(data)                                     (0x00001000&((data)<<12))
#define  SYS_REG_SYS_CLKEN0_clken_acpu2(data)                                    (0x00000800&((data)<<11))
#define  SYS_REG_SYS_CLKEN0_clken_ve_lgcy_p2(data)                               (0x00000080&((data)<<7))
#define  SYS_REG_SYS_CLKEN0_clken_ve_lgcy(data)                                  (0x00000040&((data)<<6))
#define  SYS_REG_SYS_CLKEN0_clken_ve_p2(data)                                    (0x00000020&((data)<<5))
#define  SYS_REG_SYS_CLKEN0_clken_ve(data)                                       (0x00000010&((data)<<4))
#define  SYS_REG_SYS_CLKEN0_clken_vcpu(data)                                     (0x00000008&((data)<<3))
#define  SYS_REG_SYS_CLKEN0_clken_scpu_wrap(data)                                (0x00000004&((data)<<2))
#define  SYS_REG_SYS_CLKEN0_clken_scpu(data)                                     (0x00000002&((data)<<1))
#define  SYS_REG_SYS_CLKEN0_write_data(data)                                     (0x00000001&(data))
#define  SYS_REG_SYS_CLKEN0_get_clken_diseqc(data)                               ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_CLKEN0_get_clken_cablerx(data)                              ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_CLKEN0_get_clken_hdmi_common(data)                          ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_CLKEN0_get_clken_hdmi_pre3(data)                            ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_CLKEN0_get_clken_hdmi_pre2(data)                            ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_CLKEN0_get_clken_hdmi_pre1(data)                            ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_CLKEN0_get_clken_hdmi_pre0(data)                            ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_CLKEN0_get_clken_img_demod(data)                            ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_CLKEN0_get_clken_img_demod_wrap(data)                       ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_CLKEN0_get_clken_hdic(data)                                 ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_CLKEN0_get_clken_dtv_frontend(data)                         ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_CLKEN0_get_clken_kcpu(data)                                 ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_CLKEN0_get_clken_ve2_p2(data)                               ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_CLKEN0_get_clken_ve2(data)                                  ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_CLKEN0_get_clken_vcpu2(data)                                ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_CLKEN0_get_clken_rtk_demod(data)                            ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_CLKEN0_get_clken_acpu(data)                                 ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_CLKEN0_get_clken_acpu2(data)                                ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_CLKEN0_get_clken_ve_lgcy_p2(data)                           ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_CLKEN0_get_clken_ve_lgcy(data)                              ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_CLKEN0_get_clken_ve_p2(data)                                ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_CLKEN0_get_clken_ve(data)                                   ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_CLKEN0_get_clken_vcpu(data)                                 ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_CLKEN0_get_clken_scpu_wrap(data)                            ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_CLKEN0_get_clken_scpu(data)                                 ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_CLKEN0_get_write_data(data)                                 (0x00000001&(data))

#define  SYS_REG_SYS_CLKEN1                                                      0x18000114
#define  SYS_REG_SYS_CLKEN1_reg_addr                                             "0xB8000114"
#define  SYS_REG_SYS_CLKEN1_reg                                                  0xB8000114
#define  SYS_REG_SYS_CLKEN1_inst_addr                                            "0x0005"
#define  set_SYS_REG_SYS_CLKEN1_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CLKEN1_reg)=data)
#define  get_SYS_REG_SYS_CLKEN1_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CLKEN1_reg))
#define  SYS_REG_SYS_CLKEN1_clken_tvsb1_shift                                    (31)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb2_shift                                    (30)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb3_shift                                    (29)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb4_shift                                    (28)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb5_shift                                    (27)
#define  SYS_REG_SYS_CLKEN1_clken_tve_shift                                      (26)
#define  SYS_REG_SYS_CLKEN1_clken_dcphy_shift                                    (25)
#define  SYS_REG_SYS_CLKEN1_clken_dcu_shift                                      (24)
#define  SYS_REG_SYS_CLKEN1_clken_if_demod_shift                                 (23)
#define  SYS_REG_SYS_CLKEN1_clken_vdec_shift                                     (22)
#define  SYS_REG_SYS_CLKEN1_clken_se2_shift                                      (21)
#define  SYS_REG_SYS_CLKEN1_clken_vbis0_shift                                    (20)
#define  SYS_REG_SYS_CLKEN1_clken_dolby_comp_shift                               (19)
#define  SYS_REG_SYS_CLKEN1_clken_dolby_dm_shift                                 (18)
#define  SYS_REG_SYS_CLKEN1_clken_audio_pre512fs_shift                           (17)
#define  SYS_REG_SYS_CLKEN1_clken_audio_shift                                    (16)
#define  SYS_REG_SYS_CLKEN1_clken_ifadc_shift                                    (15)
#define  SYS_REG_SYS_CLKEN1_clken_cbus_shift                                     (14)
#define  SYS_REG_SYS_CLKEN1_clken_offms_shift                                    (13)
#define  SYS_REG_SYS_CLKEN1_clken_me_shift                                       (12)
#define  SYS_REG_SYS_CLKEN1_clken_apll_adc_shift                                 (11)
#define  SYS_REG_SYS_CLKEN1_clken_hdmi_shift                                     (10)
#define  SYS_REG_SYS_CLKEN1_clken_dispd_shift                                    (9)
#define  SYS_REG_SYS_CLKEN1_clken_tp_shift                                       (8)
#define  SYS_REG_SYS_CLKEN1_clken_cp_shift                                       (7)
#define  SYS_REG_SYS_CLKEN1_clken_md_shift                                       (6)
#define  SYS_REG_SYS_CLKEN1_clken_se_shift                                       (5)
#define  SYS_REG_SYS_CLKEN1_clken_tp_div_shift                                   (4)
#define  SYS_REG_SYS_CLKEN1_clken_3d_gde_shift                                   (3)
#define  SYS_REG_SYS_CLKEN1_clken_vodma_shift                                    (2)
#define  SYS_REG_SYS_CLKEN1_clken_dispi_shift                                    (1)
#define  SYS_REG_SYS_CLKEN1_write_data_shift                                     (0)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb1_mask                                     (0x80000000)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb2_mask                                     (0x40000000)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb3_mask                                     (0x20000000)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb4_mask                                     (0x10000000)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb5_mask                                     (0x08000000)
#define  SYS_REG_SYS_CLKEN1_clken_tve_mask                                       (0x04000000)
#define  SYS_REG_SYS_CLKEN1_clken_dcphy_mask                                     (0x02000000)
#define  SYS_REG_SYS_CLKEN1_clken_dcu_mask                                       (0x01000000)
#define  SYS_REG_SYS_CLKEN1_clken_if_demod_mask                                  (0x00800000)
#define  SYS_REG_SYS_CLKEN1_clken_vdec_mask                                      (0x00400000)
#define  SYS_REG_SYS_CLKEN1_clken_se2_mask                                       (0x00200000)
#define  SYS_REG_SYS_CLKEN1_clken_vbis0_mask                                     (0x00100000)
#define  SYS_REG_SYS_CLKEN1_clken_dolby_comp_mask                                (0x00080000)
#define  SYS_REG_SYS_CLKEN1_clken_dolby_dm_mask                                  (0x00040000)
#define  SYS_REG_SYS_CLKEN1_clken_audio_pre512fs_mask                            (0x00020000)
#define  SYS_REG_SYS_CLKEN1_clken_audio_mask                                     (0x00010000)
#define  SYS_REG_SYS_CLKEN1_clken_ifadc_mask                                     (0x00008000)
#define  SYS_REG_SYS_CLKEN1_clken_cbus_mask                                      (0x00004000)
#define  SYS_REG_SYS_CLKEN1_clken_offms_mask                                     (0x00002000)
#define  SYS_REG_SYS_CLKEN1_clken_me_mask                                        (0x00001000)
#define  SYS_REG_SYS_CLKEN1_clken_apll_adc_mask                                  (0x00000800)
#define  SYS_REG_SYS_CLKEN1_clken_hdmi_mask                                      (0x00000400)
#define  SYS_REG_SYS_CLKEN1_clken_dispd_mask                                     (0x00000200)
#define  SYS_REG_SYS_CLKEN1_clken_tp_mask                                        (0x00000100)
#define  SYS_REG_SYS_CLKEN1_clken_cp_mask                                        (0x00000080)
#define  SYS_REG_SYS_CLKEN1_clken_md_mask                                        (0x00000040)
#define  SYS_REG_SYS_CLKEN1_clken_se_mask                                        (0x00000020)
#define  SYS_REG_SYS_CLKEN1_clken_tp_div_mask                                    (0x00000010)
#define  SYS_REG_SYS_CLKEN1_clken_3d_gde_mask                                    (0x00000008)
#define  SYS_REG_SYS_CLKEN1_clken_vodma_mask                                     (0x00000004)
#define  SYS_REG_SYS_CLKEN1_clken_dispi_mask                                     (0x00000002)
#define  SYS_REG_SYS_CLKEN1_write_data_mask                                      (0x00000001)
#define  SYS_REG_SYS_CLKEN1_clken_tvsb1(data)                                    (0x80000000&((data)<<31))
#define  SYS_REG_SYS_CLKEN1_clken_tvsb2(data)                                    (0x40000000&((data)<<30))
#define  SYS_REG_SYS_CLKEN1_clken_tvsb3(data)                                    (0x20000000&((data)<<29))
#define  SYS_REG_SYS_CLKEN1_clken_tvsb4(data)                                    (0x10000000&((data)<<28))
#define  SYS_REG_SYS_CLKEN1_clken_tvsb5(data)                                    (0x08000000&((data)<<27))
#define  SYS_REG_SYS_CLKEN1_clken_tve(data)                                      (0x04000000&((data)<<26))
#define  SYS_REG_SYS_CLKEN1_clken_dcphy(data)                                    (0x02000000&((data)<<25))
#define  SYS_REG_SYS_CLKEN1_clken_dcu(data)                                      (0x01000000&((data)<<24))
#define  SYS_REG_SYS_CLKEN1_clken_if_demod(data)                                 (0x00800000&((data)<<23))
#define  SYS_REG_SYS_CLKEN1_clken_vdec(data)                                     (0x00400000&((data)<<22))
#define  SYS_REG_SYS_CLKEN1_clken_se2(data)                                      (0x00200000&((data)<<21))
#define  SYS_REG_SYS_CLKEN1_clken_vbis0(data)                                    (0x00100000&((data)<<20))
#define  SYS_REG_SYS_CLKEN1_clken_dolby_comp(data)                               (0x00080000&((data)<<19))
#define  SYS_REG_SYS_CLKEN1_clken_dolby_dm(data)                                 (0x00040000&((data)<<18))
#define  SYS_REG_SYS_CLKEN1_clken_audio_pre512fs(data)                           (0x00020000&((data)<<17))
#define  SYS_REG_SYS_CLKEN1_clken_audio(data)                                    (0x00010000&((data)<<16))
#define  SYS_REG_SYS_CLKEN1_clken_ifadc(data)                                    (0x00008000&((data)<<15))
#define  SYS_REG_SYS_CLKEN1_clken_cbus(data)                                     (0x00004000&((data)<<14))
#define  SYS_REG_SYS_CLKEN1_clken_offms(data)                                    (0x00002000&((data)<<13))
#define  SYS_REG_SYS_CLKEN1_clken_me(data)                                       (0x00001000&((data)<<12))
#define  SYS_REG_SYS_CLKEN1_clken_apll_adc(data)                                 (0x00000800&((data)<<11))
#define  SYS_REG_SYS_CLKEN1_clken_hdmi(data)                                     (0x00000400&((data)<<10))
#define  SYS_REG_SYS_CLKEN1_clken_dispd(data)                                    (0x00000200&((data)<<9))
#define  SYS_REG_SYS_CLKEN1_clken_tp(data)                                       (0x00000100&((data)<<8))
#define  SYS_REG_SYS_CLKEN1_clken_cp(data)                                       (0x00000080&((data)<<7))
#define  SYS_REG_SYS_CLKEN1_clken_md(data)                                       (0x00000040&((data)<<6))
#define  SYS_REG_SYS_CLKEN1_clken_se(data)                                       (0x00000020&((data)<<5))
#define  SYS_REG_SYS_CLKEN1_clken_tp_div(data)                                   (0x00000010&((data)<<4))
#define  SYS_REG_SYS_CLKEN1_clken_3d_gde(data)                                   (0x00000008&((data)<<3))
#define  SYS_REG_SYS_CLKEN1_clken_vodma(data)                                    (0x00000004&((data)<<2))
#define  SYS_REG_SYS_CLKEN1_clken_dispi(data)                                    (0x00000002&((data)<<1))
#define  SYS_REG_SYS_CLKEN1_write_data(data)                                     (0x00000001&(data))
#define  SYS_REG_SYS_CLKEN1_get_clken_tvsb1(data)                                ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_CLKEN1_get_clken_tvsb2(data)                                ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_CLKEN1_get_clken_tvsb3(data)                                ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_CLKEN1_get_clken_tvsb4(data)                                ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_CLKEN1_get_clken_tvsb5(data)                                ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_CLKEN1_get_clken_tve(data)                                  ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_CLKEN1_get_clken_dcphy(data)                                ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_CLKEN1_get_clken_dcu(data)                                  ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_CLKEN1_get_clken_if_demod(data)                             ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_CLKEN1_get_clken_vdec(data)                                 ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_CLKEN1_get_clken_se2(data)                                  ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_CLKEN1_get_clken_vbis0(data)                                ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_CLKEN1_get_clken_dolby_comp(data)                           ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_CLKEN1_get_clken_dolby_dm(data)                             ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_CLKEN1_get_clken_audio_pre512fs(data)                       ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_CLKEN1_get_clken_audio(data)                                ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_CLKEN1_get_clken_ifadc(data)                                ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_CLKEN1_get_clken_cbus(data)                                 ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_CLKEN1_get_clken_offms(data)                                ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_CLKEN1_get_clken_me(data)                                   ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_CLKEN1_get_clken_apll_adc(data)                             ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_CLKEN1_get_clken_hdmi(data)                                 ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_CLKEN1_get_clken_dispd(data)                                ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_CLKEN1_get_clken_tp(data)                                   ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_CLKEN1_get_clken_cp(data)                                   ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_CLKEN1_get_clken_md(data)                                   ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_CLKEN1_get_clken_se(data)                                   ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_CLKEN1_get_clken_tp_div(data)                               ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_CLKEN1_get_clken_3d_gde(data)                               ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_CLKEN1_get_clken_vodma(data)                                ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_CLKEN1_get_clken_dispi(data)                                ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_CLKEN1_get_write_data(data)                                 (0x00000001&(data))

#define  SYS_REG_SYS_CLKEN2                                                      0x18000118
#define  SYS_REG_SYS_CLKEN2_reg_addr                                             "0xB8000118"
#define  SYS_REG_SYS_CLKEN2_reg                                                  0xB8000118
#define  SYS_REG_SYS_CLKEN2_inst_addr                                            "0x0006"
#define  set_SYS_REG_SYS_CLKEN2_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CLKEN2_reg)=data)
#define  get_SYS_REG_SYS_CLKEN2_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CLKEN2_reg))
#define  SYS_REG_SYS_CLKEN2_clken_usb2_ex_shift                                  (29)
#define  SYS_REG_SYS_CLKEN2_clken_tm_shift                                       (28)
#define  SYS_REG_SYS_CLKEN2_clken_atvin_vd_shift                                 (27)
#define  SYS_REG_SYS_CLKEN2_clken_atvin_ifd_shift                                (26)
#define  SYS_REG_SYS_CLKEN2_clken_dispm_cap_shift                                (25)
#define  SYS_REG_SYS_CLKEN2_clken_dispm_disp_shift                               (24)
#define  SYS_REG_SYS_CLKEN2_clken_emmc_shift                                     (23)
#define  SYS_REG_SYS_CLKEN2_clken_efuse_shift                                    (22)
#define  SYS_REG_SYS_CLKEN2_clken_bistreg_shift                                  (21)
#define  SYS_REG_SYS_CLKEN2_clken_i2c4_shift                                     (20)
#define  SYS_REG_SYS_CLKEN2_clken_pllreg_shift                                   (19)
#define  SYS_REG_SYS_CLKEN2_clken_usb3_shift                                     (18)
#define  SYS_REG_SYS_CLKEN2_clken_usb2_shift                                     (17)
#define  SYS_REG_SYS_CLKEN2_clken_pcmcia_shift                                   (16)
#define  SYS_REG_SYS_CLKEN2_clken_audio2_512fs_shift                             (15)
#define  SYS_REG_SYS_CLKEN2_clken_i2c3_shift                                     (14)
#define  SYS_REG_SYS_CLKEN2_clken_irtx_shift                                     (13)
#define  SYS_REG_SYS_CLKEN2_dummy_12_shift                                       (12)
#define  SYS_REG_SYS_CLKEN2_clken_dtv_demod_shift                                (11)
#define  SYS_REG_SYS_CLKEN2_clken_misc_shift                                     (10)
#define  SYS_REG_SYS_CLKEN2_clken_pwm_shift                                      (9)
#define  SYS_REG_SYS_CLKEN2_clken_uart1_shift                                    (8)
#define  SYS_REG_SYS_CLKEN2_clken_uart2_shift                                    (7)
#define  SYS_REG_SYS_CLKEN2_dummy_6_shift                                        (6)
#define  SYS_REG_SYS_CLKEN2_clken_gpio_shift                                     (5)
#define  SYS_REG_SYS_CLKEN2_clken_i2c1_shift                                     (4)
#define  SYS_REG_SYS_CLKEN2_clken_i2c2_shift                                     (3)
#define  SYS_REG_SYS_CLKEN2_clken_nf_shift                                       (2)
#define  SYS_REG_SYS_CLKEN2_clken_sc_shift                                       (1)
#define  SYS_REG_SYS_CLKEN2_write_data_shift                                     (0)
#define  SYS_REG_SYS_CLKEN2_clken_usb2_ex_mask                                   (0x20000000)
#define  SYS_REG_SYS_CLKEN2_clken_tm_mask                                        (0x10000000)
#define  SYS_REG_SYS_CLKEN2_clken_atvin_vd_mask                                  (0x08000000)
#define  SYS_REG_SYS_CLKEN2_clken_atvin_ifd_mask                                 (0x04000000)
#define  SYS_REG_SYS_CLKEN2_clken_dispm_cap_mask                                 (0x02000000)
#define  SYS_REG_SYS_CLKEN2_clken_dispm_disp_mask                                (0x01000000)
#define  SYS_REG_SYS_CLKEN2_clken_emmc_mask                                      (0x00800000)
#define  SYS_REG_SYS_CLKEN2_clken_efuse_mask                                     (0x00400000)
#define  SYS_REG_SYS_CLKEN2_clken_bistreg_mask                                   (0x00200000)
#define  SYS_REG_SYS_CLKEN2_clken_i2c4_mask                                      (0x00100000)
#define  SYS_REG_SYS_CLKEN2_clken_pllreg_mask                                    (0x00080000)
#define  SYS_REG_SYS_CLKEN2_clken_usb3_mask                                      (0x00040000)
#define  SYS_REG_SYS_CLKEN2_clken_usb2_mask                                      (0x00020000)
#define  SYS_REG_SYS_CLKEN2_clken_pcmcia_mask                                    (0x00010000)
#define  SYS_REG_SYS_CLKEN2_clken_audio2_512fs_mask                              (0x00008000)
#define  SYS_REG_SYS_CLKEN2_clken_i2c3_mask                                      (0x00004000)
#define  SYS_REG_SYS_CLKEN2_clken_irtx_mask                                      (0x00002000)
#define  SYS_REG_SYS_CLKEN2_dummy_12_mask                                        (0x00001000)
#define  SYS_REG_SYS_CLKEN2_clken_dtv_demod_mask                                 (0x00000800)
#define  SYS_REG_SYS_CLKEN2_clken_misc_mask                                      (0x00000400)
#define  SYS_REG_SYS_CLKEN2_clken_pwm_mask                                       (0x00000200)
#define  SYS_REG_SYS_CLKEN2_clken_uart1_mask                                     (0x00000100)
#define  SYS_REG_SYS_CLKEN2_clken_uart2_mask                                     (0x00000080)
#define  SYS_REG_SYS_CLKEN2_dummy_6_mask                                         (0x00000040)
#define  SYS_REG_SYS_CLKEN2_clken_gpio_mask                                      (0x00000020)
#define  SYS_REG_SYS_CLKEN2_clken_i2c1_mask                                      (0x00000010)
#define  SYS_REG_SYS_CLKEN2_clken_i2c2_mask                                      (0x00000008)
#define  SYS_REG_SYS_CLKEN2_clken_nf_mask                                        (0x00000004)
#define  SYS_REG_SYS_CLKEN2_clken_sc_mask                                        (0x00000002)
#define  SYS_REG_SYS_CLKEN2_write_data_mask                                      (0x00000001)
#define  SYS_REG_SYS_CLKEN2_clken_usb2_ex(data)                                  (0x20000000&((data)<<29))
#define  SYS_REG_SYS_CLKEN2_clken_tm(data)                                       (0x10000000&((data)<<28))
#define  SYS_REG_SYS_CLKEN2_clken_atvin_vd(data)                                 (0x08000000&((data)<<27))
#define  SYS_REG_SYS_CLKEN2_clken_atvin_ifd(data)                                (0x04000000&((data)<<26))
#define  SYS_REG_SYS_CLKEN2_clken_dispm_cap(data)                                (0x02000000&((data)<<25))
#define  SYS_REG_SYS_CLKEN2_clken_dispm_disp(data)                               (0x01000000&((data)<<24))
#define  SYS_REG_SYS_CLKEN2_clken_emmc(data)                                     (0x00800000&((data)<<23))
#define  SYS_REG_SYS_CLKEN2_clken_efuse(data)                                    (0x00400000&((data)<<22))
#define  SYS_REG_SYS_CLKEN2_clken_bistreg(data)                                  (0x00200000&((data)<<21))
#define  SYS_REG_SYS_CLKEN2_clken_i2c4(data)                                     (0x00100000&((data)<<20))
#define  SYS_REG_SYS_CLKEN2_clken_pllreg(data)                                   (0x00080000&((data)<<19))
#define  SYS_REG_SYS_CLKEN2_clken_usb3(data)                                     (0x00040000&((data)<<18))
#define  SYS_REG_SYS_CLKEN2_clken_usb2(data)                                     (0x00020000&((data)<<17))
#define  SYS_REG_SYS_CLKEN2_clken_pcmcia(data)                                   (0x00010000&((data)<<16))
#define  SYS_REG_SYS_CLKEN2_clken_audio2_512fs(data)                             (0x00008000&((data)<<15))
#define  SYS_REG_SYS_CLKEN2_clken_i2c3(data)                                     (0x00004000&((data)<<14))
#define  SYS_REG_SYS_CLKEN2_clken_irtx(data)                                     (0x00002000&((data)<<13))
#define  SYS_REG_SYS_CLKEN2_dummy_12(data)                                       (0x00001000&((data)<<12))
#define  SYS_REG_SYS_CLKEN2_clken_dtv_demod(data)                                (0x00000800&((data)<<11))
#define  SYS_REG_SYS_CLKEN2_clken_misc(data)                                     (0x00000400&((data)<<10))
#define  SYS_REG_SYS_CLKEN2_clken_pwm(data)                                      (0x00000200&((data)<<9))
#define  SYS_REG_SYS_CLKEN2_clken_uart1(data)                                    (0x00000100&((data)<<8))
#define  SYS_REG_SYS_CLKEN2_clken_uart2(data)                                    (0x00000080&((data)<<7))
#define  SYS_REG_SYS_CLKEN2_dummy_6(data)                                        (0x00000040&((data)<<6))
#define  SYS_REG_SYS_CLKEN2_clken_gpio(data)                                     (0x00000020&((data)<<5))
#define  SYS_REG_SYS_CLKEN2_clken_i2c1(data)                                     (0x00000010&((data)<<4))
#define  SYS_REG_SYS_CLKEN2_clken_i2c2(data)                                     (0x00000008&((data)<<3))
#define  SYS_REG_SYS_CLKEN2_clken_nf(data)                                       (0x00000004&((data)<<2))
#define  SYS_REG_SYS_CLKEN2_clken_sc(data)                                       (0x00000002&((data)<<1))
#define  SYS_REG_SYS_CLKEN2_write_data(data)                                     (0x00000001&(data))
#define  SYS_REG_SYS_CLKEN2_get_clken_usb2_ex(data)                              ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_CLKEN2_get_clken_tm(data)                                   ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_CLKEN2_get_clken_atvin_vd(data)                             ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_CLKEN2_get_clken_atvin_ifd(data)                            ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_CLKEN2_get_clken_dispm_cap(data)                            ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_CLKEN2_get_clken_dispm_disp(data)                           ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_CLKEN2_get_clken_emmc(data)                                 ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_CLKEN2_get_clken_efuse(data)                                ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_CLKEN2_get_clken_bistreg(data)                              ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_CLKEN2_get_clken_i2c4(data)                                 ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_CLKEN2_get_clken_pllreg(data)                               ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_CLKEN2_get_clken_usb3(data)                                 ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_CLKEN2_get_clken_usb2(data)                                 ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_CLKEN2_get_clken_pcmcia(data)                               ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_CLKEN2_get_clken_audio2_512fs(data)                         ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_CLKEN2_get_clken_i2c3(data)                                 ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_CLKEN2_get_clken_irtx(data)                                 ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_CLKEN2_get_dummy_12(data)                                   ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_CLKEN2_get_clken_dtv_demod(data)                            ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_CLKEN2_get_clken_misc(data)                                 ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_CLKEN2_get_clken_pwm(data)                                  ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_CLKEN2_get_clken_uart1(data)                                ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_CLKEN2_get_clken_uart2(data)                                ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_CLKEN2_get_dummy_6(data)                                    ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_CLKEN2_get_clken_gpio(data)                                 ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_CLKEN2_get_clken_i2c1(data)                                 ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_CLKEN2_get_clken_i2c2(data)                                 ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_CLKEN2_get_clken_nf(data)                                   ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_CLKEN2_get_clken_sc(data)                                   ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_CLKEN2_get_write_data(data)                                 (0x00000001&(data))

#define  SYS_REG_SYS_CLKEN3                                                      0x1800011C
#define  SYS_REG_SYS_CLKEN3_reg_addr                                             "0xB800011C"
#define  SYS_REG_SYS_CLKEN3_reg                                                  0xB800011C
#define  SYS_REG_SYS_CLKEN3_inst_addr                                            "0x0007"
#define  set_SYS_REG_SYS_CLKEN3_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CLKEN3_reg)=data)
#define  get_SYS_REG_SYS_CLKEN3_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CLKEN3_reg))
#define  SYS_REG_SYS_CLKEN3_clken_memc_shift                                     (31)
#define  SYS_REG_SYS_CLKEN3_clken_memc_me_shift                                  (30)
#define  SYS_REG_SYS_CLKEN3_clken_memc_rbus_shift                                (29)
#define  SYS_REG_SYS_CLKEN3_clken_dcphy_mc_mck_shift                             (26)
#define  SYS_REG_SYS_CLKEN3_clken_dcphy2_shift                                   (25)
#define  SYS_REG_SYS_CLKEN3_clken_dcu2_shift                                     (24)
#define  SYS_REG_SYS_CLKEN3_clken_dcphy_mc_shift                                 (23)
#define  SYS_REG_SYS_CLKEN3_clken_disp_lg_hcic_shift                             (22)
#define  SYS_REG_SYS_CLKEN3_clken_disp_lg_mplus_shift                            (21)
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_pxl_shift                           (20)
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_apb_shift                           (19)
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_mcu_shift                           (18)
#define  SYS_REG_SYS_CLKEN3_clken_ddc_shift                                      (17)
#define  SYS_REG_SYS_CLKEN3_clken_sd_shift                                       (16)
#define  SYS_REG_SYS_CLKEN3_clken_dss_shift                                      (15)
#define  SYS_REG_SYS_CLKEN3_clken_audio_ad_128fs_shift                           (9)
#define  SYS_REG_SYS_CLKEN3_clken_audio_arc_dma_r_512fs_shift                    (8)
#define  SYS_REG_SYS_CLKEN3_clken_audio2_dma_r_512fs_shift                       (7)
#define  SYS_REG_SYS_CLKEN3_clken_audio_dma_r_512fs_shift                        (6)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da1_256fs_shift                          (5)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da1_128fs_shift                          (4)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da0_256fs_shift                          (3)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da0_128fs_shift                          (2)
#define  SYS_REG_SYS_CLKEN3_clken_audio_ad_256fs_shift                           (1)
#define  SYS_REG_SYS_CLKEN3_write_data_shift                                     (0)
#define  SYS_REG_SYS_CLKEN3_clken_memc_mask                                      (0x80000000)
#define  SYS_REG_SYS_CLKEN3_clken_memc_me_mask                                   (0x40000000)
#define  SYS_REG_SYS_CLKEN3_clken_memc_rbus_mask                                 (0x20000000)
#define  SYS_REG_SYS_CLKEN3_clken_dcphy_mc_mck_mask                              (0x04000000)
#define  SYS_REG_SYS_CLKEN3_clken_dcphy2_mask                                    (0x02000000)
#define  SYS_REG_SYS_CLKEN3_clken_dcu2_mask                                      (0x01000000)
#define  SYS_REG_SYS_CLKEN3_clken_dcphy_mc_mask                                  (0x00800000)
#define  SYS_REG_SYS_CLKEN3_clken_disp_lg_hcic_mask                              (0x00400000)
#define  SYS_REG_SYS_CLKEN3_clken_disp_lg_mplus_mask                             (0x00200000)
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_pxl_mask                            (0x00100000)
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_apb_mask                            (0x00080000)
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_mcu_mask                            (0x00040000)
#define  SYS_REG_SYS_CLKEN3_clken_ddc_mask                                       (0x00020000)
#define  SYS_REG_SYS_CLKEN3_clken_sd_mask                                        (0x00010000)
#define  SYS_REG_SYS_CLKEN3_clken_dss_mask                                       (0x00008000)
#define  SYS_REG_SYS_CLKEN3_clken_audio_ad_128fs_mask                            (0x00000200)
#define  SYS_REG_SYS_CLKEN3_clken_audio_arc_dma_r_512fs_mask                     (0x00000100)
#define  SYS_REG_SYS_CLKEN3_clken_audio2_dma_r_512fs_mask                        (0x00000080)
#define  SYS_REG_SYS_CLKEN3_clken_audio_dma_r_512fs_mask                         (0x00000040)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da1_256fs_mask                           (0x00000020)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da1_128fs_mask                           (0x00000010)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da0_256fs_mask                           (0x00000008)
#define  SYS_REG_SYS_CLKEN3_clken_audio_da0_128fs_mask                           (0x00000004)
#define  SYS_REG_SYS_CLKEN3_clken_audio_ad_256fs_mask                            (0x00000002)
#define  SYS_REG_SYS_CLKEN3_write_data_mask                                      (0x00000001)
#define  SYS_REG_SYS_CLKEN3_clken_memc(data)                                     (0x80000000&((data)<<31))
#define  SYS_REG_SYS_CLKEN3_clken_memc_me(data)                                  (0x40000000&((data)<<30))
#define  SYS_REG_SYS_CLKEN3_clken_memc_rbus(data)                                (0x20000000&((data)<<29))
#define  SYS_REG_SYS_CLKEN3_clken_dcphy_mc_mck(data)                             (0x04000000&((data)<<26))
#define  SYS_REG_SYS_CLKEN3_clken_dcphy2(data)                                   (0x02000000&((data)<<25))
#define  SYS_REG_SYS_CLKEN3_clken_dcu2(data)                                     (0x01000000&((data)<<24))
#define  SYS_REG_SYS_CLKEN3_clken_dcphy_mc(data)                                 (0x00800000&((data)<<23))
#define  SYS_REG_SYS_CLKEN3_clken_disp_lg_hcic(data)                             (0x00400000&((data)<<22))
#define  SYS_REG_SYS_CLKEN3_clken_disp_lg_mplus(data)                            (0x00200000&((data)<<21))
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_pxl(data)                           (0x00100000&((data)<<20))
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_apb(data)                           (0x00080000&((data)<<19))
#define  SYS_REG_SYS_CLKEN3_clken_d_boe_rgbw_mcu(data)                           (0x00040000&((data)<<18))
#define  SYS_REG_SYS_CLKEN3_clken_ddc(data)                                      (0x00020000&((data)<<17))
#define  SYS_REG_SYS_CLKEN3_clken_sd(data)                                       (0x00010000&((data)<<16))
#define  SYS_REG_SYS_CLKEN3_clken_dss(data)                                      (0x00008000&((data)<<15))
#define  SYS_REG_SYS_CLKEN3_clken_audio_ad_128fs(data)                           (0x00000200&((data)<<9))
#define  SYS_REG_SYS_CLKEN3_clken_audio_arc_dma_r_512fs(data)                    (0x00000100&((data)<<8))
#define  SYS_REG_SYS_CLKEN3_clken_audio2_dma_r_512fs(data)                       (0x00000080&((data)<<7))
#define  SYS_REG_SYS_CLKEN3_clken_audio_dma_r_512fs(data)                        (0x00000040&((data)<<6))
#define  SYS_REG_SYS_CLKEN3_clken_audio_da1_256fs(data)                          (0x00000020&((data)<<5))
#define  SYS_REG_SYS_CLKEN3_clken_audio_da1_128fs(data)                          (0x00000010&((data)<<4))
#define  SYS_REG_SYS_CLKEN3_clken_audio_da0_256fs(data)                          (0x00000008&((data)<<3))
#define  SYS_REG_SYS_CLKEN3_clken_audio_da0_128fs(data)                          (0x00000004&((data)<<2))
#define  SYS_REG_SYS_CLKEN3_clken_audio_ad_256fs(data)                           (0x00000002&((data)<<1))
#define  SYS_REG_SYS_CLKEN3_write_data(data)                                     (0x00000001&(data))
#define  SYS_REG_SYS_CLKEN3_get_clken_memc(data)                                 ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_CLKEN3_get_clken_memc_me(data)                              ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_CLKEN3_get_clken_memc_rbus(data)                            ((0x20000000&(data))>>29)
#define  SYS_REG_SYS_CLKEN3_get_clken_dcphy_mc_mck(data)                         ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_CLKEN3_get_clken_dcphy2(data)                               ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_CLKEN3_get_clken_dcu2(data)                                 ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_CLKEN3_get_clken_dcphy_mc(data)                             ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_CLKEN3_get_clken_disp_lg_hcic(data)                         ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_CLKEN3_get_clken_disp_lg_mplus(data)                        ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_CLKEN3_get_clken_d_boe_rgbw_pxl(data)                       ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_CLKEN3_get_clken_d_boe_rgbw_apb(data)                       ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_CLKEN3_get_clken_d_boe_rgbw_mcu(data)                       ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_CLKEN3_get_clken_ddc(data)                                  ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_CLKEN3_get_clken_sd(data)                                   ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_CLKEN3_get_clken_dss(data)                                  ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_ad_128fs(data)                       ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_arc_dma_r_512fs(data)                ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio2_dma_r_512fs(data)                   ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_dma_r_512fs(data)                    ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_da1_256fs(data)                      ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_da1_128fs(data)                      ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_da0_256fs(data)                      ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_da0_128fs(data)                      ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_CLKEN3_get_clken_audio_ad_256fs(data)                       ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_CLKEN3_get_write_data(data)                                 (0x00000001&(data))

#define  SYS_REG_SYS_CPUSEL                                                      0x18000200
#define  SYS_REG_SYS_CPUSEL_reg_addr                                             "0xB8000200"
#define  SYS_REG_SYS_CPUSEL_reg                                                  0xB8000200
#define  SYS_REG_SYS_CPUSEL_inst_addr                                            "0x0008"
#define  set_SYS_REG_SYS_CPUSEL_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CPUSEL_reg)=data)
#define  get_SYS_REG_SYS_CPUSEL_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CPUSEL_reg))
#define  SYS_REG_SYS_CPUSEL_ejtag_demod_sel_shift                                (6)
#define  SYS_REG_SYS_CPUSEL_ejtag_demod_en_shift                                 (5)
#define  SYS_REG_SYS_CPUSEL_ejtag_mode_shift                                     (4)
#define  SYS_REG_SYS_CPUSEL_ejtag_gpu_en_shift                                   (2)
#define  SYS_REG_SYS_CPUSEL_ejtag_gpu_sel_shift                                  (1)
#define  SYS_REG_SYS_CPUSEL_kcpu_clksel_shift                                    (0)
#define  SYS_REG_SYS_CPUSEL_ejtag_demod_sel_mask                                 (0x00000040)
#define  SYS_REG_SYS_CPUSEL_ejtag_demod_en_mask                                  (0x00000020)
#define  SYS_REG_SYS_CPUSEL_ejtag_mode_mask                                      (0x00000010)
#define  SYS_REG_SYS_CPUSEL_ejtag_gpu_en_mask                                    (0x00000004)
#define  SYS_REG_SYS_CPUSEL_ejtag_gpu_sel_mask                                   (0x00000002)
#define  SYS_REG_SYS_CPUSEL_kcpu_clksel_mask                                     (0x00000001)
#define  SYS_REG_SYS_CPUSEL_ejtag_demod_sel(data)                                (0x00000040&((data)<<6))
#define  SYS_REG_SYS_CPUSEL_ejtag_demod_en(data)                                 (0x00000020&((data)<<5))
#define  SYS_REG_SYS_CPUSEL_ejtag_mode(data)                                     (0x00000010&((data)<<4))
#define  SYS_REG_SYS_CPUSEL_ejtag_gpu_en(data)                                   (0x00000004&((data)<<2))
#define  SYS_REG_SYS_CPUSEL_ejtag_gpu_sel(data)                                  (0x00000002&((data)<<1))
#define  SYS_REG_SYS_CPUSEL_kcpu_clksel(data)                                    (0x00000001&(data))
#define  SYS_REG_SYS_CPUSEL_get_ejtag_demod_sel(data)                            ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_CPUSEL_get_ejtag_demod_en(data)                             ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_CPUSEL_get_ejtag_mode(data)                                 ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_CPUSEL_get_ejtag_gpu_en(data)                               ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_CPUSEL_get_ejtag_gpu_sel(data)                              ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_CPUSEL_get_kcpu_clksel(data)                                (0x00000001&(data))

#define  SYS_REG_SYS_CLKSEL                                                      0x18000204
#define  SYS_REG_SYS_CLKSEL_reg_addr                                             "0xB8000204"
#define  SYS_REG_SYS_CLKSEL_reg                                                  0xB8000204
#define  SYS_REG_SYS_CLKSEL_inst_addr                                            "0x0009"
#define  set_SYS_REG_SYS_CLKSEL_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CLKSEL_reg)=data)
#define  get_SYS_REG_SYS_CLKSEL_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CLKSEL_reg))
#define  SYS_REG_SYS_CLKSEL_pll_bypass_ref_clk_mode_shift                        (31)
#define  SYS_REG_SYS_CLKSEL_mc_clk_sel_shift                                     (30)
#define  SYS_REG_SYS_CLKSEL_ve_sel_shift                                         (28)
#define  SYS_REG_SYS_CLKSEL_sd_emmc_clk_sel_shift                                (27)
#define  SYS_REG_SYS_CLKSEL_pcr108_clksel_shift                                  (26)
#define  SYS_REG_SYS_CLKSEL_dummy_25_shift                                       (25)
#define  SYS_REG_SYS_CLKSEL_dpll_clksel_shift                                    (23)
#define  SYS_REG_SYS_CLKSEL_sd_clk_div_shift                                     (20)
#define  SYS_REG_SYS_CLKSEL_ve_rif_use_p2clk_shift                               (19)
#define  SYS_REG_SYS_CLKSEL_ve2_rif_use_p2clk_shift                              (18)
#define  SYS_REG_SYS_CLKSEL_atvin_clk_sel_shift                                  (17)
#define  SYS_REG_SYS_CLKSEL_atvin_vd_clk_sel_shift                               (16)
#define  SYS_REG_SYS_CLKSEL_atvin_vdadc_tve_clk_sel_shift                        (15)
#define  SYS_REG_SYS_CLKSEL_tve_108m_clk_sel_shift                               (13)
#define  SYS_REG_SYS_CLKSEL_cbus_clksel_shift                                    (12)
#define  SYS_REG_SYS_CLKSEL_tp_post_div_shift                                    (8)
#define  SYS_REG_SYS_CLKSEL_tp_pre_div_shift                                     (4)
#define  SYS_REG_SYS_CLKSEL_vdec_x27_clksel_shift                                (3)
#define  SYS_REG_SYS_CLKSEL_vbis0_yppsel_shift                                   (2)
#define  SYS_REG_SYS_CLKSEL_inv_vbis0_sel_shift                                  (1)
#define  SYS_REG_SYS_CLKSEL_uart_clksel_shift                                    (0)
#define  SYS_REG_SYS_CLKSEL_pll_bypass_ref_clk_mode_mask                         (0x80000000)
#define  SYS_REG_SYS_CLKSEL_mc_clk_sel_mask                                      (0x40000000)
#define  SYS_REG_SYS_CLKSEL_ve_sel_mask                                          (0x10000000)
#define  SYS_REG_SYS_CLKSEL_sd_emmc_clk_sel_mask                                 (0x08000000)
#define  SYS_REG_SYS_CLKSEL_pcr108_clksel_mask                                   (0x04000000)
#define  SYS_REG_SYS_CLKSEL_dummy_25_mask                                        (0x02000000)
#define  SYS_REG_SYS_CLKSEL_dpll_clksel_mask                                     (0x01800000)
#define  SYS_REG_SYS_CLKSEL_sd_clk_div_mask                                      (0x00700000)
#define  SYS_REG_SYS_CLKSEL_ve_rif_use_p2clk_mask                                (0x00080000)
#define  SYS_REG_SYS_CLKSEL_ve2_rif_use_p2clk_mask                               (0x00040000)
#define  SYS_REG_SYS_CLKSEL_atvin_clk_sel_mask                                   (0x00020000)
#define  SYS_REG_SYS_CLKSEL_atvin_vd_clk_sel_mask                                (0x00010000)
#define  SYS_REG_SYS_CLKSEL_atvin_vdadc_tve_clk_sel_mask                         (0x00008000)
#define  SYS_REG_SYS_CLKSEL_tve_108m_clk_sel_mask                                (0x00002000)
#define  SYS_REG_SYS_CLKSEL_cbus_clksel_mask                                     (0x00001000)
#define  SYS_REG_SYS_CLKSEL_tp_post_div_mask                                     (0x00000F00)
#define  SYS_REG_SYS_CLKSEL_tp_pre_div_mask                                      (0x000000F0)
#define  SYS_REG_SYS_CLKSEL_vdec_x27_clksel_mask                                 (0x00000008)
#define  SYS_REG_SYS_CLKSEL_vbis0_yppsel_mask                                    (0x00000004)
#define  SYS_REG_SYS_CLKSEL_inv_vbis0_sel_mask                                   (0x00000002)
#define  SYS_REG_SYS_CLKSEL_uart_clksel_mask                                     (0x00000001)
#define  SYS_REG_SYS_CLKSEL_pll_bypass_ref_clk_mode(data)                        (0x80000000&((data)<<31))
#define  SYS_REG_SYS_CLKSEL_mc_clk_sel(data)                                     (0x40000000&((data)<<30))
#define  SYS_REG_SYS_CLKSEL_ve_sel(data)                                         (0x10000000&((data)<<28))
#define  SYS_REG_SYS_CLKSEL_sd_emmc_clk_sel(data)                                (0x08000000&((data)<<27))
#define  SYS_REG_SYS_CLKSEL_pcr108_clksel(data)                                  (0x04000000&((data)<<26))
#define  SYS_REG_SYS_CLKSEL_dummy_25(data)                                       (0x02000000&((data)<<25))
#define  SYS_REG_SYS_CLKSEL_dpll_clksel(data)                                    (0x01800000&((data)<<23))
#define  SYS_REG_SYS_CLKSEL_sd_clk_div(data)                                     (0x00700000&((data)<<20))
#define  SYS_REG_SYS_CLKSEL_ve_rif_use_p2clk(data)                               (0x00080000&((data)<<19))
#define  SYS_REG_SYS_CLKSEL_ve2_rif_use_p2clk(data)                              (0x00040000&((data)<<18))
#define  SYS_REG_SYS_CLKSEL_atvin_clk_sel(data)                                  (0x00020000&((data)<<17))
#define  SYS_REG_SYS_CLKSEL_atvin_vd_clk_sel(data)                               (0x00010000&((data)<<16))
#define  SYS_REG_SYS_CLKSEL_atvin_vdadc_tve_clk_sel(data)                        (0x00008000&((data)<<15))
#define  SYS_REG_SYS_CLKSEL_tve_108m_clk_sel(data)                               (0x00002000&((data)<<13))
#define  SYS_REG_SYS_CLKSEL_cbus_clksel(data)                                    (0x00001000&((data)<<12))
#define  SYS_REG_SYS_CLKSEL_tp_post_div(data)                                    (0x00000F00&((data)<<8))
#define  SYS_REG_SYS_CLKSEL_tp_pre_div(data)                                     (0x000000F0&((data)<<4))
#define  SYS_REG_SYS_CLKSEL_vdec_x27_clksel(data)                                (0x00000008&((data)<<3))
#define  SYS_REG_SYS_CLKSEL_vbis0_yppsel(data)                                   (0x00000004&((data)<<2))
#define  SYS_REG_SYS_CLKSEL_inv_vbis0_sel(data)                                  (0x00000002&((data)<<1))
#define  SYS_REG_SYS_CLKSEL_uart_clksel(data)                                    (0x00000001&(data))
#define  SYS_REG_SYS_CLKSEL_get_pll_bypass_ref_clk_mode(data)                    ((0x80000000&(data))>>31)
#define  SYS_REG_SYS_CLKSEL_get_mc_clk_sel(data)                                 ((0x40000000&(data))>>30)
#define  SYS_REG_SYS_CLKSEL_get_ve_sel(data)                                     ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_CLKSEL_get_sd_emmc_clk_sel(data)                            ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_CLKSEL_get_pcr108_clksel(data)                              ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_CLKSEL_get_dummy_25(data)                                   ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_CLKSEL_get_dpll_clksel(data)                                ((0x01800000&(data))>>23)
#define  SYS_REG_SYS_CLKSEL_get_sd_clk_div(data)                                 ((0x00700000&(data))>>20)
#define  SYS_REG_SYS_CLKSEL_get_ve_rif_use_p2clk(data)                           ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_CLKSEL_get_ve2_rif_use_p2clk(data)                          ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_CLKSEL_get_atvin_clk_sel(data)                              ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_CLKSEL_get_atvin_vd_clk_sel(data)                           ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_CLKSEL_get_atvin_vdadc_tve_clk_sel(data)                    ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_CLKSEL_get_tve_108m_clk_sel(data)                           ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_CLKSEL_get_cbus_clksel(data)                                ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_CLKSEL_get_tp_post_div(data)                                ((0x00000F00&(data))>>8)
#define  SYS_REG_SYS_CLKSEL_get_tp_pre_div(data)                                 ((0x000000F0&(data))>>4)
#define  SYS_REG_SYS_CLKSEL_get_vdec_x27_clksel(data)                            ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_CLKSEL_get_vbis0_yppsel(data)                               ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_CLKSEL_get_inv_vbis0_sel(data)                              ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_CLKSEL_get_uart_clksel(data)                                (0x00000001&(data))

#define  SYS_REG_SYS_DISPCLKSEL                                                  0x18000208
#define  SYS_REG_SYS_DISPCLKSEL_reg_addr                                         "0xB8000208"
#define  SYS_REG_SYS_DISPCLKSEL_reg                                              0xB8000208
#define  SYS_REG_SYS_DISPCLKSEL_inst_addr                                        "0x000A"
#define  set_SYS_REG_SYS_DISPCLKSEL_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SYS_DISPCLKSEL_reg)=data)
#define  get_SYS_REG_SYS_DISPCLKSEL_reg                                          (*((volatile unsigned int*)SYS_REG_SYS_DISPCLKSEL_reg))
#define  SYS_REG_SYS_DISPCLKSEL_dispd_osd_div_shift                              (30)
#define  SYS_REG_SYS_DISPCLKSEL_memc_me_div_shift                                (26)
#define  SYS_REG_SYS_DISPCLKSEL_dclk_fract_b_shift                               (20)
#define  SYS_REG_SYS_DISPCLKSEL_dclk_fract_a_shift                               (15)
#define  SYS_REG_SYS_DISPCLKSEL_dispd_gdma_clk_sel_shift                         (14)
#define  SYS_REG_SYS_DISPCLKSEL_dispd_memc_out_sel_shift                         (12)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_11_shift                                   (11)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_10_shift                                   (10)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_lg_avcom_shift                        (9)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_8_shift                                    (8)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_7_shift                                    (7)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_memc_in_shift                         (6)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_memc_out_shift                        (5)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_sfg_shift                             (4)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_gdma_shift                            (3)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_stage1_shift                          (2)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_osd_shift                             (1)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_0_shift                                    (0)
#define  SYS_REG_SYS_DISPCLKSEL_dispd_osd_div_mask                               (0xC0000000)
#define  SYS_REG_SYS_DISPCLKSEL_memc_me_div_mask                                 (0x0C000000)
#define  SYS_REG_SYS_DISPCLKSEL_dclk_fract_b_mask                                (0x03F00000)
#define  SYS_REG_SYS_DISPCLKSEL_dclk_fract_a_mask                                (0x000F8000)
#define  SYS_REG_SYS_DISPCLKSEL_dispd_gdma_clk_sel_mask                          (0x00004000)
#define  SYS_REG_SYS_DISPCLKSEL_dispd_memc_out_sel_mask                          (0x00001000)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_11_mask                                    (0x00000800)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_10_mask                                    (0x00000400)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_lg_avcom_mask                         (0x00000200)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_8_mask                                     (0x00000100)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_7_mask                                     (0x00000080)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_memc_in_mask                          (0x00000040)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_memc_out_mask                         (0x00000020)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_sfg_mask                              (0x00000010)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_gdma_mask                             (0x00000008)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_stage1_mask                           (0x00000004)
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_osd_mask                              (0x00000002)
#define  SYS_REG_SYS_DISPCLKSEL_dummy_0_mask                                     (0x00000001)
#define  SYS_REG_SYS_DISPCLKSEL_dispd_osd_div(data)                              (0xC0000000&((data)<<30))
#define  SYS_REG_SYS_DISPCLKSEL_memc_me_div(data)                                (0x0C000000&((data)<<26))
#define  SYS_REG_SYS_DISPCLKSEL_dclk_fract_b(data)                               (0x03F00000&((data)<<20))
#define  SYS_REG_SYS_DISPCLKSEL_dclk_fract_a(data)                               (0x000F8000&((data)<<15))
#define  SYS_REG_SYS_DISPCLKSEL_dispd_gdma_clk_sel(data)                         (0x00004000&((data)<<14))
#define  SYS_REG_SYS_DISPCLKSEL_dispd_memc_out_sel(data)                         (0x00001000&((data)<<12))
#define  SYS_REG_SYS_DISPCLKSEL_dummy_11(data)                                   (0x00000800&((data)<<11))
#define  SYS_REG_SYS_DISPCLKSEL_dummy_10(data)                                   (0x00000400&((data)<<10))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_lg_avcom(data)                        (0x00000200&((data)<<9))
#define  SYS_REG_SYS_DISPCLKSEL_dummy_8(data)                                    (0x00000100&((data)<<8))
#define  SYS_REG_SYS_DISPCLKSEL_dummy_7(data)                                    (0x00000080&((data)<<7))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_memc_in(data)                         (0x00000040&((data)<<6))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_memc_out(data)                        (0x00000020&((data)<<5))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_sfg(data)                             (0x00000010&((data)<<4))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_gdma(data)                            (0x00000008&((data)<<3))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_stage1(data)                          (0x00000004&((data)<<2))
#define  SYS_REG_SYS_DISPCLKSEL_clken_disp_osd(data)                             (0x00000002&((data)<<1))
#define  SYS_REG_SYS_DISPCLKSEL_dummy_0(data)                                    (0x00000001&(data))
#define  SYS_REG_SYS_DISPCLKSEL_get_dispd_osd_div(data)                          ((0xC0000000&(data))>>30)
#define  SYS_REG_SYS_DISPCLKSEL_get_memc_me_div(data)                            ((0x0C000000&(data))>>26)
#define  SYS_REG_SYS_DISPCLKSEL_get_dclk_fract_b(data)                           ((0x03F00000&(data))>>20)
#define  SYS_REG_SYS_DISPCLKSEL_get_dclk_fract_a(data)                           ((0x000F8000&(data))>>15)
#define  SYS_REG_SYS_DISPCLKSEL_get_dispd_gdma_clk_sel(data)                     ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_DISPCLKSEL_get_dispd_memc_out_sel(data)                     ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_DISPCLKSEL_get_dummy_11(data)                               ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_DISPCLKSEL_get_dummy_10(data)                               ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_lg_avcom(data)                    ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_DISPCLKSEL_get_dummy_8(data)                                ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_DISPCLKSEL_get_dummy_7(data)                                ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_memc_in(data)                     ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_memc_out(data)                    ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_sfg(data)                         ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_gdma(data)                        ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_stage1(data)                      ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_DISPCLKSEL_get_clken_disp_osd(data)                         ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_DISPCLKSEL_get_dummy_0(data)                                (0x00000001&(data))

#define  SYS_REG_SYS_EXTCLK_EN                                                   0x18000210
#define  SYS_REG_SYS_EXTCLK_EN_reg_addr                                          "0xB8000210"
#define  SYS_REG_SYS_EXTCLK_EN_reg                                               0xB8000210
#define  SYS_REG_SYS_EXTCLK_EN_inst_addr                                         "0x000B"
#define  set_SYS_REG_SYS_EXTCLK_EN_reg(data)                                     (*((volatile unsigned int*)SYS_REG_SYS_EXTCLK_EN_reg)=data)
#define  get_SYS_REG_SYS_EXTCLK_EN_reg                                           (*((volatile unsigned int*)SYS_REG_SYS_EXTCLK_EN_reg))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_ddr_en_shift                            (16)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_15_en_shift                             (15)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_14_en_shift                             (14)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_13_en_shift                             (13)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_12_en_shift                             (12)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_11_en_shift                             (11)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_10_en_shift                             (10)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_9_en_shift                              (9)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_8_en_shift                              (8)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_7_en_shift                              (7)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_6_en_shift                              (6)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_5_en_shift                              (5)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_4_en_shift                              (4)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_3_en_shift                              (3)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_2_en_shift                              (2)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_1_en_shift                              (1)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_0_en_shift                              (0)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_ddr_en_mask                             (0x00010000)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_15_en_mask                              (0x00008000)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_14_en_mask                              (0x00004000)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_13_en_mask                              (0x00002000)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_12_en_mask                              (0x00001000)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_11_en_mask                              (0x00000800)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_10_en_mask                              (0x00000400)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_9_en_mask                               (0x00000200)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_8_en_mask                               (0x00000100)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_7_en_mask                               (0x00000080)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_6_en_mask                               (0x00000040)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_5_en_mask                               (0x00000020)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_4_en_mask                               (0x00000010)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_3_en_mask                               (0x00000008)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_2_en_mask                               (0x00000004)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_1_en_mask                               (0x00000002)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_0_en_mask                               (0x00000001)
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_ddr_en(data)                            (0x00010000&((data)<<16))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_15_en(data)                             (0x00008000&((data)<<15))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_14_en(data)                             (0x00004000&((data)<<14))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_13_en(data)                             (0x00002000&((data)<<13))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_12_en(data)                             (0x00001000&((data)<<12))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_11_en(data)                             (0x00000800&((data)<<11))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_10_en(data)                             (0x00000400&((data)<<10))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_9_en(data)                              (0x00000200&((data)<<9))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_8_en(data)                              (0x00000100&((data)<<8))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_7_en(data)                              (0x00000080&((data)<<7))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_6_en(data)                              (0x00000040&((data)<<6))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_5_en(data)                              (0x00000020&((data)<<5))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_4_en(data)                              (0x00000010&((data)<<4))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_3_en(data)                              (0x00000008&((data)<<3))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_2_en(data)                              (0x00000004&((data)<<2))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_1_en(data)                              (0x00000002&((data)<<1))
#define  SYS_REG_SYS_EXTCLK_EN_clken_ext_0_en(data)                              (0x00000001&(data))
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_ddr_en(data)                        ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_15_en(data)                         ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_14_en(data)                         ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_13_en(data)                         ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_12_en(data)                         ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_11_en(data)                         ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_10_en(data)                         ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_9_en(data)                          ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_8_en(data)                          ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_7_en(data)                          ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_6_en(data)                          ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_5_en(data)                          ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_4_en(data)                          ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_3_en(data)                          ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_2_en(data)                          ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_1_en(data)                          ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_EXTCLK_EN_get_clken_ext_0_en(data)                          (0x00000001&(data))

#define  SYS_REG_SYS_CLKDIV                                                      0x18000214
#define  SYS_REG_SYS_CLKDIV_reg_addr                                             "0xB8000214"
#define  SYS_REG_SYS_CLKDIV_reg                                                  0xB8000214
#define  SYS_REG_SYS_CLKDIV_inst_addr                                            "0x000C"
#define  set_SYS_REG_SYS_CLKDIV_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SYS_CLKDIV_reg)=data)
#define  get_SYS_REG_SYS_CLKDIV_reg                                              (*((volatile unsigned int*)SYS_REG_SYS_CLKDIV_reg))
#define  SYS_REG_SYS_CLKDIV_i2c4_clksel_shift                                    (16)
#define  SYS_REG_SYS_CLKDIV_i2c3_clksel_shift                                    (15)
#define  SYS_REG_SYS_CLKDIV_dtv_demod_sel_shift                                  (14)
#define  SYS_REG_SYS_CLKDIV_i2c2_clksel_shift                                    (13)
#define  SYS_REG_SYS_CLKDIV_i2c1_clksel_shift                                    (12)
#define  SYS_REG_SYS_CLKDIV_dtv_demod_atsc_en_shift                              (11)
#define  SYS_REG_SYS_CLKDIV_nf_clksel_shift                                      (8)
#define  SYS_REG_SYS_CLKDIV_dummy_7_shift                                        (7)
#define  SYS_REG_SYS_CLKDIV_aud_dtv2_freq_sel_shift                              (4)
#define  SYS_REG_SYS_CLKDIV_dummy_3_shift                                        (3)
#define  SYS_REG_SYS_CLKDIV_aud_dtv_freq_sel_shift                               (0)
#define  SYS_REG_SYS_CLKDIV_i2c4_clksel_mask                                     (0x00010000)
#define  SYS_REG_SYS_CLKDIV_i2c3_clksel_mask                                     (0x00008000)
#define  SYS_REG_SYS_CLKDIV_dtv_demod_sel_mask                                   (0x00004000)
#define  SYS_REG_SYS_CLKDIV_i2c2_clksel_mask                                     (0x00002000)
#define  SYS_REG_SYS_CLKDIV_i2c1_clksel_mask                                     (0x00001000)
#define  SYS_REG_SYS_CLKDIV_dtv_demod_atsc_en_mask                               (0x00000800)
#define  SYS_REG_SYS_CLKDIV_nf_clksel_mask                                       (0x00000700)
#define  SYS_REG_SYS_CLKDIV_dummy_7_mask                                         (0x00000080)
#define  SYS_REG_SYS_CLKDIV_aud_dtv2_freq_sel_mask                               (0x00000070)
#define  SYS_REG_SYS_CLKDIV_dummy_3_mask                                         (0x00000008)
#define  SYS_REG_SYS_CLKDIV_aud_dtv_freq_sel_mask                                (0x00000007)
#define  SYS_REG_SYS_CLKDIV_i2c4_clksel(data)                                    (0x00010000&((data)<<16))
#define  SYS_REG_SYS_CLKDIV_i2c3_clksel(data)                                    (0x00008000&((data)<<15))
#define  SYS_REG_SYS_CLKDIV_dtv_demod_sel(data)                                  (0x00004000&((data)<<14))
#define  SYS_REG_SYS_CLKDIV_i2c2_clksel(data)                                    (0x00002000&((data)<<13))
#define  SYS_REG_SYS_CLKDIV_i2c1_clksel(data)                                    (0x00001000&((data)<<12))
#define  SYS_REG_SYS_CLKDIV_dtv_demod_atsc_en(data)                              (0x00000800&((data)<<11))
#define  SYS_REG_SYS_CLKDIV_nf_clksel(data)                                      (0x00000700&((data)<<8))
#define  SYS_REG_SYS_CLKDIV_dummy_7(data)                                        (0x00000080&((data)<<7))
#define  SYS_REG_SYS_CLKDIV_aud_dtv2_freq_sel(data)                              (0x00000070&((data)<<4))
#define  SYS_REG_SYS_CLKDIV_dummy_3(data)                                        (0x00000008&((data)<<3))
#define  SYS_REG_SYS_CLKDIV_aud_dtv_freq_sel(data)                               (0x00000007&(data))
#define  SYS_REG_SYS_CLKDIV_get_i2c4_clksel(data)                                ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_CLKDIV_get_i2c3_clksel(data)                                ((0x00008000&(data))>>15)
#define  SYS_REG_SYS_CLKDIV_get_dtv_demod_sel(data)                              ((0x00004000&(data))>>14)
#define  SYS_REG_SYS_CLKDIV_get_i2c2_clksel(data)                                ((0x00002000&(data))>>13)
#define  SYS_REG_SYS_CLKDIV_get_i2c1_clksel(data)                                ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_CLKDIV_get_dtv_demod_atsc_en(data)                          ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_CLKDIV_get_nf_clksel(data)                                  ((0x00000700&(data))>>8)
#define  SYS_REG_SYS_CLKDIV_get_dummy_7(data)                                    ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_CLKDIV_get_aud_dtv2_freq_sel(data)                          ((0x00000070&(data))>>4)
#define  SYS_REG_SYS_CLKDIV_get_dummy_3(data)                                    ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_CLKDIV_get_aud_dtv_freq_sel(data)                           (0x00000007&(data))

#define  SYS_REG_SYS_IB                                                          0x1800021C
#define  SYS_REG_SYS_IB_reg_addr                                                 "0xB800021C"
#define  SYS_REG_SYS_IB_reg                                                      0xB800021C
#define  SYS_REG_SYS_IB_inst_addr                                                "0x000D"
#define  set_SYS_REG_SYS_IB_reg(data)                                            (*((volatile unsigned int*)SYS_REG_SYS_IB_reg)=data)
#define  get_SYS_REG_SYS_IB_reg                                                  (*((volatile unsigned int*)SYS_REG_SYS_IB_reg))
#define  SYS_REG_SYS_IB_dummy_31_29_shift                                        (29)
#define  SYS_REG_SYS_IB_ib_rst_gck_memc_shift                                    (28)
#define  SYS_REG_SYS_IB_ib_rst_gck_gpu_shift                                     (27)
#define  SYS_REG_SYS_IB_ib_rst_gck_se2_shift                                     (26)
#define  SYS_REG_SYS_IB_ib_rst_gck_ve2_shift                                     (25)
#define  SYS_REG_SYS_IB_ib_rst_gck_ve_shift                                      (24)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb5_shift                                   (23)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb4_shift                                   (22)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb3_shift                                   (21)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb2_shift                                   (20)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb1_shift                                   (19)
#define  SYS_REG_SYS_IB_ib_rst_gck_sb3_shift                                     (18)
#define  SYS_REG_SYS_IB_ib_rst_gck_sb2_shift                                     (17)
#define  SYS_REG_SYS_IB_ib_rst_gck_sb1_shift                                     (16)
#define  SYS_REG_SYS_IB_dummy_15_13_shift                                        (13)
#define  SYS_REG_SYS_IB_ib_clk_gck_memc_shift                                    (12)
#define  SYS_REG_SYS_IB_ib_clk_gck_gpu_shift                                     (11)
#define  SYS_REG_SYS_IB_ib_clk_gck_se2_shift                                     (10)
#define  SYS_REG_SYS_IB_ib_clk_gck_ve2_shift                                     (9)
#define  SYS_REG_SYS_IB_ib_clk_gck_ve_shift                                      (8)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb5_shift                                   (7)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb4_shift                                   (6)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb3_shift                                   (5)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb2_shift                                   (4)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb1_shift                                   (3)
#define  SYS_REG_SYS_IB_ib_clk_gck_sb3_shift                                     (2)
#define  SYS_REG_SYS_IB_ib_clk_gck_sb2_shift                                     (1)
#define  SYS_REG_SYS_IB_ib_clk_gck_sb1_shift                                     (0)
#define  SYS_REG_SYS_IB_dummy_31_29_mask                                         (0xE0000000)
#define  SYS_REG_SYS_IB_ib_rst_gck_memc_mask                                     (0x10000000)
#define  SYS_REG_SYS_IB_ib_rst_gck_gpu_mask                                      (0x08000000)
#define  SYS_REG_SYS_IB_ib_rst_gck_se2_mask                                      (0x04000000)
#define  SYS_REG_SYS_IB_ib_rst_gck_ve2_mask                                      (0x02000000)
#define  SYS_REG_SYS_IB_ib_rst_gck_ve_mask                                       (0x01000000)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb5_mask                                    (0x00800000)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb4_mask                                    (0x00400000)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb3_mask                                    (0x00200000)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb2_mask                                    (0x00100000)
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb1_mask                                    (0x00080000)
#define  SYS_REG_SYS_IB_ib_rst_gck_sb3_mask                                      (0x00040000)
#define  SYS_REG_SYS_IB_ib_rst_gck_sb2_mask                                      (0x00020000)
#define  SYS_REG_SYS_IB_ib_rst_gck_sb1_mask                                      (0x00010000)
#define  SYS_REG_SYS_IB_dummy_15_13_mask                                         (0x0000E000)
#define  SYS_REG_SYS_IB_ib_clk_gck_memc_mask                                     (0x00001000)
#define  SYS_REG_SYS_IB_ib_clk_gck_gpu_mask                                      (0x00000800)
#define  SYS_REG_SYS_IB_ib_clk_gck_se2_mask                                      (0x00000400)
#define  SYS_REG_SYS_IB_ib_clk_gck_ve2_mask                                      (0x00000200)
#define  SYS_REG_SYS_IB_ib_clk_gck_ve_mask                                       (0x00000100)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb5_mask                                    (0x00000080)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb4_mask                                    (0x00000040)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb3_mask                                    (0x00000020)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb2_mask                                    (0x00000010)
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb1_mask                                    (0x00000008)
#define  SYS_REG_SYS_IB_ib_clk_gck_sb3_mask                                      (0x00000004)
#define  SYS_REG_SYS_IB_ib_clk_gck_sb2_mask                                      (0x00000002)
#define  SYS_REG_SYS_IB_ib_clk_gck_sb1_mask                                      (0x00000001)
#define  SYS_REG_SYS_IB_dummy_31_29(data)                                        (0xE0000000&((data)<<29))
#define  SYS_REG_SYS_IB_ib_rst_gck_memc(data)                                    (0x10000000&((data)<<28))
#define  SYS_REG_SYS_IB_ib_rst_gck_gpu(data)                                     (0x08000000&((data)<<27))
#define  SYS_REG_SYS_IB_ib_rst_gck_se2(data)                                     (0x04000000&((data)<<26))
#define  SYS_REG_SYS_IB_ib_rst_gck_ve2(data)                                     (0x02000000&((data)<<25))
#define  SYS_REG_SYS_IB_ib_rst_gck_ve(data)                                      (0x01000000&((data)<<24))
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb5(data)                                   (0x00800000&((data)<<23))
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb4(data)                                   (0x00400000&((data)<<22))
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb3(data)                                   (0x00200000&((data)<<21))
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb2(data)                                   (0x00100000&((data)<<20))
#define  SYS_REG_SYS_IB_ib_rst_gck_tvsb1(data)                                   (0x00080000&((data)<<19))
#define  SYS_REG_SYS_IB_ib_rst_gck_sb3(data)                                     (0x00040000&((data)<<18))
#define  SYS_REG_SYS_IB_ib_rst_gck_sb2(data)                                     (0x00020000&((data)<<17))
#define  SYS_REG_SYS_IB_ib_rst_gck_sb1(data)                                     (0x00010000&((data)<<16))
#define  SYS_REG_SYS_IB_dummy_15_13(data)                                        (0x0000E000&((data)<<13))
#define  SYS_REG_SYS_IB_ib_clk_gck_memc(data)                                    (0x00001000&((data)<<12))
#define  SYS_REG_SYS_IB_ib_clk_gck_gpu(data)                                     (0x00000800&((data)<<11))
#define  SYS_REG_SYS_IB_ib_clk_gck_se2(data)                                     (0x00000400&((data)<<10))
#define  SYS_REG_SYS_IB_ib_clk_gck_ve2(data)                                     (0x00000200&((data)<<9))
#define  SYS_REG_SYS_IB_ib_clk_gck_ve(data)                                      (0x00000100&((data)<<8))
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb5(data)                                   (0x00000080&((data)<<7))
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb4(data)                                   (0x00000040&((data)<<6))
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb3(data)                                   (0x00000020&((data)<<5))
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb2(data)                                   (0x00000010&((data)<<4))
#define  SYS_REG_SYS_IB_ib_clk_gck_tvsb1(data)                                   (0x00000008&((data)<<3))
#define  SYS_REG_SYS_IB_ib_clk_gck_sb3(data)                                     (0x00000004&((data)<<2))
#define  SYS_REG_SYS_IB_ib_clk_gck_sb2(data)                                     (0x00000002&((data)<<1))
#define  SYS_REG_SYS_IB_ib_clk_gck_sb1(data)                                     (0x00000001&(data))
#define  SYS_REG_SYS_IB_get_dummy_31_29(data)                                    ((0xE0000000&(data))>>29)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_memc(data)                                ((0x10000000&(data))>>28)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_gpu(data)                                 ((0x08000000&(data))>>27)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_se2(data)                                 ((0x04000000&(data))>>26)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_ve2(data)                                 ((0x02000000&(data))>>25)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_ve(data)                                  ((0x01000000&(data))>>24)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_tvsb5(data)                               ((0x00800000&(data))>>23)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_tvsb4(data)                               ((0x00400000&(data))>>22)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_tvsb3(data)                               ((0x00200000&(data))>>21)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_tvsb2(data)                               ((0x00100000&(data))>>20)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_tvsb1(data)                               ((0x00080000&(data))>>19)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_sb3(data)                                 ((0x00040000&(data))>>18)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_sb2(data)                                 ((0x00020000&(data))>>17)
#define  SYS_REG_SYS_IB_get_ib_rst_gck_sb1(data)                                 ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_IB_get_dummy_15_13(data)                                    ((0x0000E000&(data))>>13)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_memc(data)                                ((0x00001000&(data))>>12)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_gpu(data)                                 ((0x00000800&(data))>>11)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_se2(data)                                 ((0x00000400&(data))>>10)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_ve2(data)                                 ((0x00000200&(data))>>9)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_ve(data)                                  ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_tvsb5(data)                               ((0x00000080&(data))>>7)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_tvsb4(data)                               ((0x00000040&(data))>>6)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_tvsb3(data)                               ((0x00000020&(data))>>5)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_tvsb2(data)                               ((0x00000010&(data))>>4)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_tvsb1(data)                               ((0x00000008&(data))>>3)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_sb3(data)                                 ((0x00000004&(data))>>2)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_sb2(data)                                 ((0x00000002&(data))>>1)
#define  SYS_REG_SYS_IB_get_ib_clk_gck_sb1(data)                                 (0x00000001&(data))

#define  SYS_REG_SYS_DYN_SW_CPU                                                  0x18000220
#define  SYS_REG_SYS_DYN_SW_CPU_reg_addr                                         "0xB8000220"
#define  SYS_REG_SYS_DYN_SW_CPU_reg                                              0xB8000220
#define  SYS_REG_SYS_DYN_SW_CPU_inst_addr                                        "0x000E"
#define  set_SYS_REG_SYS_DYN_SW_CPU_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SYS_DYN_SW_CPU_reg)=data)
#define  get_SYS_REG_SYS_DYN_SW_CPU_reg                                          (*((volatile unsigned int*)SYS_REG_SYS_DYN_SW_CPU_reg))
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_vcpu_shift                              (19)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_vcpu_active_shift                       (16)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu_shift                              (11)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu_active_shift                       (8)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu2_shift                             (3)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu2_active_shift                      (0)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_vcpu_mask                               (0x00F80000)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_vcpu_active_mask                        (0x00010000)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu_mask                               (0x0000F800)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu_active_mask                        (0x00000100)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu2_mask                              (0x000000F8)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu2_active_mask                       (0x00000001)
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_vcpu(data)                              (0x00F80000&((data)<<19))
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_vcpu_active(data)                       (0x00010000&((data)<<16))
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu(data)                              (0x0000F800&((data)<<11))
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu_active(data)                       (0x00000100&((data)<<8))
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu2(data)                             (0x000000F8&((data)<<3))
#define  SYS_REG_SYS_DYN_SW_CPU_clkratio_acpu2_active(data)                      (0x00000001&(data))
#define  SYS_REG_SYS_DYN_SW_CPU_get_clkratio_vcpu(data)                          ((0x00F80000&(data))>>19)
#define  SYS_REG_SYS_DYN_SW_CPU_get_clkratio_vcpu_active(data)                   ((0x00010000&(data))>>16)
#define  SYS_REG_SYS_DYN_SW_CPU_get_clkratio_acpu(data)                          ((0x0000F800&(data))>>11)
#define  SYS_REG_SYS_DYN_SW_CPU_get_clkratio_acpu_active(data)                   ((0x00000100&(data))>>8)
#define  SYS_REG_SYS_DYN_SW_CPU_get_clkratio_acpu2(data)                         ((0x000000F8&(data))>>3)
#define  SYS_REG_SYS_DYN_SW_CPU_get_clkratio_acpu2_active(data)                  (0x00000001&(data))

#define  SYS_REG_EFUSE_CTRL0                                                     0x18000240
#define  SYS_REG_EFUSE_CTRL0_reg_addr                                            "0xB8000240"
#define  SYS_REG_EFUSE_CTRL0_reg                                                 0xB8000240
#define  SYS_REG_EFUSE_CTRL0_inst_addr                                           "0x000F"
#define  set_SYS_REG_EFUSE_CTRL0_reg(data)                                       (*((volatile unsigned int*)SYS_REG_EFUSE_CTRL0_reg)=data)
#define  get_SYS_REG_EFUSE_CTRL0_reg                                             (*((volatile unsigned int*)SYS_REG_EFUSE_CTRL0_reg))
#define  SYS_REG_EFUSE_CTRL0_efuse_ready_shift                                   (0)
#define  SYS_REG_EFUSE_CTRL0_efuse_ready_mask                                    (0x00000001)
#define  SYS_REG_EFUSE_CTRL0_efuse_ready(data)                                   (0x00000001&(data))
#define  SYS_REG_EFUSE_CTRL0_get_efuse_ready(data)                               (0x00000001&(data))

#define  SYS_REG_POWER_CTRL0                                                     0x18000260
#define  SYS_REG_POWER_CTRL0_reg_addr                                            "0xB8000260"
#define  SYS_REG_POWER_CTRL0_reg                                                 0xB8000260
#define  SYS_REG_POWER_CTRL0_inst_addr                                           "0x0010"
#define  set_SYS_REG_POWER_CTRL0_reg(data)                                       (*((volatile unsigned int*)SYS_REG_POWER_CTRL0_reg)=data)
#define  get_SYS_REG_POWER_CTRL0_reg                                             (*((volatile unsigned int*)SYS_REG_POWER_CTRL0_reg))
#define  SYS_REG_POWER_CTRL0_atv_iso_en_shift                                    (12)
#define  SYS_REG_POWER_CTRL0_atv_str_status_shift                                (10)
#define  SYS_REG_POWER_CTRL0_atv_str_pow_shift                                   (8)
#define  SYS_REG_POWER_CTRL0_dtv_iso_en_shift                                    (4)
#define  SYS_REG_POWER_CTRL0_dtv_str_status_shift                                (2)
#define  SYS_REG_POWER_CTRL0_dtv_str_pow_shift                                   (0)
#define  SYS_REG_POWER_CTRL0_atv_iso_en_mask                                     (0x00001000)
#define  SYS_REG_POWER_CTRL0_atv_str_status_mask                                 (0x00000400)
#define  SYS_REG_POWER_CTRL0_atv_str_pow_mask                                    (0x00000100)
#define  SYS_REG_POWER_CTRL0_dtv_iso_en_mask                                     (0x00000010)
#define  SYS_REG_POWER_CTRL0_dtv_str_status_mask                                 (0x00000004)
#define  SYS_REG_POWER_CTRL0_dtv_str_pow_mask                                    (0x00000001)
#define  SYS_REG_POWER_CTRL0_atv_iso_en(data)                                    (0x00001000&((data)<<12))
#define  SYS_REG_POWER_CTRL0_atv_str_status(data)                                (0x00000400&((data)<<10))
#define  SYS_REG_POWER_CTRL0_atv_str_pow(data)                                   (0x00000100&((data)<<8))
#define  SYS_REG_POWER_CTRL0_dtv_iso_en(data)                                    (0x00000010&((data)<<4))
#define  SYS_REG_POWER_CTRL0_dtv_str_status(data)                                (0x00000004&((data)<<2))
#define  SYS_REG_POWER_CTRL0_dtv_str_pow(data)                                   (0x00000001&(data))
#define  SYS_REG_POWER_CTRL0_get_atv_iso_en(data)                                ((0x00001000&(data))>>12)
#define  SYS_REG_POWER_CTRL0_get_atv_str_status(data)                            ((0x00000400&(data))>>10)
#define  SYS_REG_POWER_CTRL0_get_atv_str_pow(data)                               ((0x00000100&(data))>>8)
#define  SYS_REG_POWER_CTRL0_get_dtv_iso_en(data)                                ((0x00000010&(data))>>4)
#define  SYS_REG_POWER_CTRL0_get_dtv_str_status(data)                            ((0x00000004&(data))>>2)
#define  SYS_REG_POWER_CTRL0_get_dtv_str_pow(data)                               (0x00000001&(data))

#define  SYS_REG_INT_CTRL_SCPU                                                   0x18000290
#define  SYS_REG_INT_CTRL_SCPU_reg_addr                                          "0xB8000290"
#define  SYS_REG_INT_CTRL_SCPU_reg                                               0xB8000290
#define  SYS_REG_INT_CTRL_SCPU_inst_addr                                         "0x0011"
#define  set_SYS_REG_INT_CTRL_SCPU_reg(data)                                     (*((volatile unsigned int*)SYS_REG_INT_CTRL_SCPU_reg)=data)
#define  get_SYS_REG_INT_CTRL_SCPU_reg                                           (*((volatile unsigned int*)SYS_REG_INT_CTRL_SCPU_reg))
#define  SYS_REG_INT_CTRL_SCPU_smartcard_int_scpu_routing_en_shift               (31)
#define  SYS_REG_INT_CTRL_SCPU_dummy_30_shift                                    (30)
#define  SYS_REG_INT_CTRL_SCPU_ddc_int_scpu_routing_en_shift                     (29)
#define  SYS_REG_INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en_shift           (28)
#define  SYS_REG_INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en_shift    (27)
#define  SYS_REG_INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en_shift            (26)
#define  SYS_REG_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_shift    (25)
#define  SYS_REG_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_shift            (24)
#define  SYS_REG_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_shift        (23)
#define  SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_shift             (22)
#define  SYS_REG_INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en_shift             (21)
#define  SYS_REG_INT_CTRL_SCPU_gpu_int_scpu_routing_en_shift                     (20)
#define  SYS_REG_INT_CTRL_SCPU_usb3_int_scpu_routing_en_shift                    (19)
#define  SYS_REG_INT_CTRL_SCPU_usb2_int_scpu_routing_en_shift                    (18)
#define  SYS_REG_INT_CTRL_SCPU_etn_int_scpu_routing_en_shift                     (17)
#define  SYS_REG_INT_CTRL_SCPU_sd_int_scpu_routing_en_shift                      (16)
#define  SYS_REG_INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en_shift               (15)
#define  SYS_REG_INT_CTRL_SCPU_audio_irq_scpu_routing_en_shift                   (14)
#define  SYS_REG_INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en_shift                (13)
#define  SYS_REG_INT_CTRL_SCPU_dcphy_int_scpu_routing_en_shift                   (12)
#define  SYS_REG_INT_CTRL_SCPU_dc_int_scpu_routing_en_shift                      (11)
#define  SYS_REG_INT_CTRL_SCPU_tve_int_scpu_routing_en_shift                     (10)
#define  SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_shift                     (9)
#define  SYS_REG_INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en_shift              (8)
#define  SYS_REG_INT_CTRL_SCPU_dctl_int_scpu_routing_en_shift                    (7)
#define  SYS_REG_INT_CTRL_SCPU_vbi_int_scpu_routing_en_shift                     (6)
#define  SYS_REG_INT_CTRL_SCPU_vdec_int_scpu_routing_en_shift                    (5)
#define  SYS_REG_INT_CTRL_SCPU_if_demod_int_scpu_routing_en_shift                (4)
#define  SYS_REG_INT_CTRL_SCPU_dispm_int_scpu_routing_en_shift                   (3)
#define  SYS_REG_INT_CTRL_SCPU_dispi_int_scpu_routing_en_shift                   (2)
#define  SYS_REG_INT_CTRL_SCPU_apll_dds_int_scpu_routing_en_shift                (1)
#define  SYS_REG_INT_CTRL_SCPU_write_data_shift                                  (0)
#define  SYS_REG_INT_CTRL_SCPU_smartcard_int_scpu_routing_en_mask                (0x80000000)
#define  SYS_REG_INT_CTRL_SCPU_dummy_30_mask                                     (0x40000000)
#define  SYS_REG_INT_CTRL_SCPU_ddc_int_scpu_routing_en_mask                      (0x20000000)
#define  SYS_REG_INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en_mask            (0x10000000)
#define  SYS_REG_INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en_mask     (0x08000000)
#define  SYS_REG_INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en_mask             (0x04000000)
#define  SYS_REG_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en_mask     (0x02000000)
#define  SYS_REG_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en_mask             (0x01000000)
#define  SYS_REG_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en_mask         (0x00800000)
#define  SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en_mask              (0x00400000)
#define  SYS_REG_INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en_mask              (0x00200000)
#define  SYS_REG_INT_CTRL_SCPU_gpu_int_scpu_routing_en_mask                      (0x00100000)
#define  SYS_REG_INT_CTRL_SCPU_usb3_int_scpu_routing_en_mask                     (0x00080000)
#define  SYS_REG_INT_CTRL_SCPU_usb2_int_scpu_routing_en_mask                     (0x00040000)
#define  SYS_REG_INT_CTRL_SCPU_etn_int_scpu_routing_en_mask                      (0x00020000)
#define  SYS_REG_INT_CTRL_SCPU_sd_int_scpu_routing_en_mask                       (0x00010000)
#define  SYS_REG_INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en_mask                (0x00008000)
#define  SYS_REG_INT_CTRL_SCPU_audio_irq_scpu_routing_en_mask                    (0x00004000)
#define  SYS_REG_INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en_mask                 (0x00002000)
#define  SYS_REG_INT_CTRL_SCPU_dcphy_int_scpu_routing_en_mask                    (0x00001000)
#define  SYS_REG_INT_CTRL_SCPU_dc_int_scpu_routing_en_mask                       (0x00000800)
#define  SYS_REG_INT_CTRL_SCPU_tve_int_scpu_routing_en_mask                      (0x00000400)
#define  SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en_mask                      (0x00000200)
#define  SYS_REG_INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en_mask               (0x00000100)
#define  SYS_REG_INT_CTRL_SCPU_dctl_int_scpu_routing_en_mask                     (0x00000080)
#define  SYS_REG_INT_CTRL_SCPU_vbi_int_scpu_routing_en_mask                      (0x00000040)
#define  SYS_REG_INT_CTRL_SCPU_vdec_int_scpu_routing_en_mask                     (0x00000020)
#define  SYS_REG_INT_CTRL_SCPU_if_demod_int_scpu_routing_en_mask                 (0x00000010)
#define  SYS_REG_INT_CTRL_SCPU_dispm_int_scpu_routing_en_mask                    (0x00000008)
#define  SYS_REG_INT_CTRL_SCPU_dispi_int_scpu_routing_en_mask                    (0x00000004)
#define  SYS_REG_INT_CTRL_SCPU_apll_dds_int_scpu_routing_en_mask                 (0x00000002)
#define  SYS_REG_INT_CTRL_SCPU_write_data_mask                                   (0x00000001)
#define  SYS_REG_INT_CTRL_SCPU_smartcard_int_scpu_routing_en(data)               (0x80000000&((data)<<31))
#define  SYS_REG_INT_CTRL_SCPU_dummy_30(data)                                    (0x40000000&((data)<<30))
#define  SYS_REG_INT_CTRL_SCPU_ddc_int_scpu_routing_en(data)                     (0x20000000&((data)<<29))
#define  SYS_REG_INT_CTRL_SCPU_standby_syncp_int_scpu_routing_en(data)           (0x10000000&((data)<<28))
#define  SYS_REG_INT_CTRL_SCPU_standby_hdmi_clk_det_int_scpu_routing_en(data)    (0x08000000&((data)<<27))
#define  SYS_REG_INT_CTRL_SCPU_standby_wdog_int_scpu_routing_en(data)            (0x04000000&((data)<<26))
#define  SYS_REG_INT_CTRL_SCPU_standby_iso_misc_off_int_scpu_routing_en(data)    (0x02000000&((data)<<25))
#define  SYS_REG_INT_CTRL_SCPU_standby_cbus_int_scpu_routing_en(data)            (0x01000000&((data)<<24))
#define  SYS_REG_INT_CTRL_SCPU_standby_iso_misc_int_scpu_routing_en(data)        (0x00800000&((data)<<23))
#define  SYS_REG_INT_CTRL_SCPU_standby_cec_int_scpu_routing_en(data)             (0x00400000&((data)<<22))
#define  SYS_REG_INT_CTRL_SCPU_standby_rtc_int_scpu_routing_en(data)             (0x00200000&((data)<<21))
#define  SYS_REG_INT_CTRL_SCPU_gpu_int_scpu_routing_en(data)                     (0x00100000&((data)<<20))
#define  SYS_REG_INT_CTRL_SCPU_usb3_int_scpu_routing_en(data)                    (0x00080000&((data)<<19))
#define  SYS_REG_INT_CTRL_SCPU_usb2_int_scpu_routing_en(data)                    (0x00040000&((data)<<18))
#define  SYS_REG_INT_CTRL_SCPU_etn_int_scpu_routing_en(data)                     (0x00020000&((data)<<17))
#define  SYS_REG_INT_CTRL_SCPU_sd_int_scpu_routing_en(data)                      (0x00010000&((data)<<16))
#define  SYS_REG_INT_CTRL_SCPU_audio_dma_irq_scpu_routing_en(data)               (0x00008000&((data)<<15))
#define  SYS_REG_INT_CTRL_SCPU_audio_irq_scpu_routing_en(data)                   (0x00004000&((data)<<14))
#define  SYS_REG_INT_CTRL_SCPU_tv_sb_dc_int_scpu_routing_en(data)                (0x00002000&((data)<<13))
#define  SYS_REG_INT_CTRL_SCPU_dcphy_int_scpu_routing_en(data)                   (0x00001000&((data)<<12))
#define  SYS_REG_INT_CTRL_SCPU_dc_int_scpu_routing_en(data)                      (0x00000800&((data)<<11))
#define  SYS_REG_INT_CTRL_SCPU_tve_int_scpu_routing_en(data)                     (0x00000400&((data)<<10))
#define  SYS_REG_INT_CTRL_SCPU_osd_int_scpu_routing_en(data)                     (0x00000200&((data)<<9))
#define  SYS_REG_INT_CTRL_SCPU_ultra_zoom_int_scpu_routing_en(data)              (0x00000100&((data)<<8))
#define  SYS_REG_INT_CTRL_SCPU_dctl_int_scpu_routing_en(data)                    (0x00000080&((data)<<7))
#define  SYS_REG_INT_CTRL_SCPU_vbi_int_scpu_routing_en(data)                     (0x00000040&((data)<<6))
#define  SYS_REG_INT_CTRL_SCPU_vdec_int_scpu_routing_en(data)                    (0x00000020&((data)<<5))
#define  SYS_REG_INT_CTRL_SCPU_if_demod_int_scpu_routing_en(data)                (0x00000010&((data)<<4))
#define  SYS_REG_INT_CTRL_SCPU_dispm_int_scpu_routing_en(data)                   (0x00000008&((data)<<3))
#define  SYS_REG_INT_CTRL_SCPU_dispi_int_scpu_routing_en(data)                   (0x00000004&((data)<<2))
#define  SYS_REG_INT_CTRL_SCPU_apll_dds_int_scpu_routing_en(data)                (0x00000002&((data)<<1))
#define  SYS_REG_INT_CTRL_SCPU_write_data(data)                                  (0x00000001&(data))
#define  SYS_REG_INT_CTRL_SCPU_get_smartcard_int_scpu_routing_en(data)           ((0x80000000&(data))>>31)
#define  SYS_REG_INT_CTRL_SCPU_get_dummy_30(data)                                ((0x40000000&(data))>>30)
#define  SYS_REG_INT_CTRL_SCPU_get_ddc_int_scpu_routing_en(data)                 ((0x20000000&(data))>>29)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_syncp_int_scpu_routing_en(data)       ((0x10000000&(data))>>28)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_hdmi_clk_det_int_scpu_routing_en(data) ((0x08000000&(data))>>27)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_wdog_int_scpu_routing_en(data)        ((0x04000000&(data))>>26)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_iso_misc_off_int_scpu_routing_en(data) ((0x02000000&(data))>>25)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_cbus_int_scpu_routing_en(data)        ((0x01000000&(data))>>24)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_iso_misc_int_scpu_routing_en(data)    ((0x00800000&(data))>>23)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_cec_int_scpu_routing_en(data)         ((0x00400000&(data))>>22)
#define  SYS_REG_INT_CTRL_SCPU_get_standby_rtc_int_scpu_routing_en(data)         ((0x00200000&(data))>>21)
#define  SYS_REG_INT_CTRL_SCPU_get_gpu_int_scpu_routing_en(data)                 ((0x00100000&(data))>>20)
#define  SYS_REG_INT_CTRL_SCPU_get_usb3_int_scpu_routing_en(data)                ((0x00080000&(data))>>19)
#define  SYS_REG_INT_CTRL_SCPU_get_usb2_int_scpu_routing_en(data)                ((0x00040000&(data))>>18)
#define  SYS_REG_INT_CTRL_SCPU_get_etn_int_scpu_routing_en(data)                 ((0x00020000&(data))>>17)
#define  SYS_REG_INT_CTRL_SCPU_get_sd_int_scpu_routing_en(data)                  ((0x00010000&(data))>>16)
#define  SYS_REG_INT_CTRL_SCPU_get_audio_dma_irq_scpu_routing_en(data)           ((0x00008000&(data))>>15)
#define  SYS_REG_INT_CTRL_SCPU_get_audio_irq_scpu_routing_en(data)               ((0x00004000&(data))>>14)
#define  SYS_REG_INT_CTRL_SCPU_get_tv_sb_dc_int_scpu_routing_en(data)            ((0x00002000&(data))>>13)
#define  SYS_REG_INT_CTRL_SCPU_get_dcphy_int_scpu_routing_en(data)               ((0x00001000&(data))>>12)
#define  SYS_REG_INT_CTRL_SCPU_get_dc_int_scpu_routing_en(data)                  ((0x00000800&(data))>>11)
#define  SYS_REG_INT_CTRL_SCPU_get_tve_int_scpu_routing_en(data)                 ((0x00000400&(data))>>10)
#define  SYS_REG_INT_CTRL_SCPU_get_osd_int_scpu_routing_en(data)                 ((0x00000200&(data))>>9)
#define  SYS_REG_INT_CTRL_SCPU_get_ultra_zoom_int_scpu_routing_en(data)          ((0x00000100&(data))>>8)
#define  SYS_REG_INT_CTRL_SCPU_get_dctl_int_scpu_routing_en(data)                ((0x00000080&(data))>>7)
#define  SYS_REG_INT_CTRL_SCPU_get_vbi_int_scpu_routing_en(data)                 ((0x00000040&(data))>>6)
#define  SYS_REG_INT_CTRL_SCPU_get_vdec_int_scpu_routing_en(data)                ((0x00000020&(data))>>5)
#define  SYS_REG_INT_CTRL_SCPU_get_if_demod_int_scpu_routing_en(data)            ((0x00000010&(data))>>4)
#define  SYS_REG_INT_CTRL_SCPU_get_dispm_int_scpu_routing_en(data)               ((0x00000008&(data))>>3)
#define  SYS_REG_INT_CTRL_SCPU_get_dispi_int_scpu_routing_en(data)               ((0x00000004&(data))>>2)
#define  SYS_REG_INT_CTRL_SCPU_get_apll_dds_int_scpu_routing_en(data)            ((0x00000002&(data))>>1)
#define  SYS_REG_INT_CTRL_SCPU_get_write_data(data)                              (0x00000001&(data))

#define  SYS_REG_INT_CTRL_VCPU                                                   0x18000294
#define  SYS_REG_INT_CTRL_VCPU_reg_addr                                          "0xB8000294"
#define  SYS_REG_INT_CTRL_VCPU_reg                                               0xB8000294
#define  SYS_REG_INT_CTRL_VCPU_inst_addr                                         "0x0012"
#define  set_SYS_REG_INT_CTRL_VCPU_reg(data)                                     (*((volatile unsigned int*)SYS_REG_INT_CTRL_VCPU_reg)=data)
#define  get_SYS_REG_INT_CTRL_VCPU_reg                                           (*((volatile unsigned int*)SYS_REG_INT_CTRL_VCPU_reg))
#define  SYS_REG_INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en_shift                (30)
#define  SYS_REG_INT_CTRL_VCPU_vodma_int_vcpu_routing_en_shift                   (29)
#define  SYS_REG_INT_CTRL_VCPU_dummy_28_shift                                    (28)
#define  SYS_REG_INT_CTRL_VCPU_dc_int_vcpu2_routing_en_shift                     (27)
#define  SYS_REG_INT_CTRL_VCPU_dummy_26_shift                                    (26)
#define  SYS_REG_INT_CTRL_VCPU_dummy_25_shift                                    (25)
#define  SYS_REG_INT_CTRL_VCPU_dummy_24_shift                                    (24)
#define  SYS_REG_INT_CTRL_VCPU_dummy_23_shift                                    (23)
#define  SYS_REG_INT_CTRL_VCPU_dummy_22_shift                                    (22)
#define  SYS_REG_INT_CTRL_VCPU_dummy_21_shift                                    (21)
#define  SYS_REG_INT_CTRL_VCPU_dummy_20_shift                                    (20)
#define  SYS_REG_INT_CTRL_VCPU_dummy_19_shift                                    (19)
#define  SYS_REG_INT_CTRL_VCPU_dummy_18_shift                                    (18)
#define  SYS_REG_INT_CTRL_VCPU_dummy_17_shift                                    (17)
#define  SYS_REG_INT_CTRL_VCPU_dummy_16_shift                                    (16)
#define  SYS_REG_INT_CTRL_VCPU_me_int_vcpu_routing_en_shift                      (15)
#define  SYS_REG_INT_CTRL_VCPU_ddc_int_vcpu_routing_en_shift                     (14)
#define  SYS_REG_INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en_shift                (13)
#define  SYS_REG_INT_CTRL_VCPU_dcphy_int_vcpu_routing_en_shift                   (12)
#define  SYS_REG_INT_CTRL_VCPU_dc_int_vcpu_routing_en_shift                      (11)
#define  SYS_REG_INT_CTRL_VCPU_tve_int_vcpu_routing_en_shift                     (10)
#define  SYS_REG_INT_CTRL_VCPU_osd_int_vcpu_routing_en_shift                     (9)
#define  SYS_REG_INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en_shift              (8)
#define  SYS_REG_INT_CTRL_VCPU_dctl_int_vcpu_routing_en_shift                    (7)
#define  SYS_REG_INT_CTRL_VCPU_vbi_int_vcpu_routing_en_shift                     (6)
#define  SYS_REG_INT_CTRL_VCPU_vdec_int_vcpu_routing_en_shift                    (5)
#define  SYS_REG_INT_CTRL_VCPU_if_demod_int_vcpu_routing_en_shift                (4)
#define  SYS_REG_INT_CTRL_VCPU_dispm_int_vcpu_routing_en_shift                   (3)
#define  SYS_REG_INT_CTRL_VCPU_dispi_int_vcpu_routing_en_shift                   (2)
#define  SYS_REG_INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en_shift                (1)
#define  SYS_REG_INT_CTRL_VCPU_write_data_shift                                  (0)
#define  SYS_REG_INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en_mask                 (0x40000000)
#define  SYS_REG_INT_CTRL_VCPU_vodma_int_vcpu_routing_en_mask                    (0x20000000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_28_mask                                     (0x10000000)
#define  SYS_REG_INT_CTRL_VCPU_dc_int_vcpu2_routing_en_mask                      (0x08000000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_26_mask                                     (0x04000000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_25_mask                                     (0x02000000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_24_mask                                     (0x01000000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_23_mask                                     (0x00800000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_22_mask                                     (0x00400000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_21_mask                                     (0x00200000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_20_mask                                     (0x00100000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_19_mask                                     (0x00080000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_18_mask                                     (0x00040000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_17_mask                                     (0x00020000)
#define  SYS_REG_INT_CTRL_VCPU_dummy_16_mask                                     (0x00010000)
#define  SYS_REG_INT_CTRL_VCPU_me_int_vcpu_routing_en_mask                       (0x00008000)
#define  SYS_REG_INT_CTRL_VCPU_ddc_int_vcpu_routing_en_mask                      (0x00004000)
#define  SYS_REG_INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en_mask                 (0x00002000)
#define  SYS_REG_INT_CTRL_VCPU_dcphy_int_vcpu_routing_en_mask                    (0x00001000)
#define  SYS_REG_INT_CTRL_VCPU_dc_int_vcpu_routing_en_mask                       (0x00000800)
#define  SYS_REG_INT_CTRL_VCPU_tve_int_vcpu_routing_en_mask                      (0x00000400)
#define  SYS_REG_INT_CTRL_VCPU_osd_int_vcpu_routing_en_mask                      (0x00000200)
#define  SYS_REG_INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en_mask               (0x00000100)
#define  SYS_REG_INT_CTRL_VCPU_dctl_int_vcpu_routing_en_mask                     (0x00000080)
#define  SYS_REG_INT_CTRL_VCPU_vbi_int_vcpu_routing_en_mask                      (0x00000040)
#define  SYS_REG_INT_CTRL_VCPU_vdec_int_vcpu_routing_en_mask                     (0x00000020)
#define  SYS_REG_INT_CTRL_VCPU_if_demod_int_vcpu_routing_en_mask                 (0x00000010)
#define  SYS_REG_INT_CTRL_VCPU_dispm_int_vcpu_routing_en_mask                    (0x00000008)
#define  SYS_REG_INT_CTRL_VCPU_dispi_int_vcpu_routing_en_mask                    (0x00000004)
#define  SYS_REG_INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en_mask                 (0x00000002)
#define  SYS_REG_INT_CTRL_VCPU_write_data_mask                                   (0x00000001)
#define  SYS_REG_INT_CTRL_VCPU_disp2tve_int_vcpu_routing_en(data)                (0x40000000&((data)<<30))
#define  SYS_REG_INT_CTRL_VCPU_vodma_int_vcpu_routing_en(data)                   (0x20000000&((data)<<29))
#define  SYS_REG_INT_CTRL_VCPU_dummy_28(data)                                    (0x10000000&((data)<<28))
#define  SYS_REG_INT_CTRL_VCPU_dc_int_vcpu2_routing_en(data)                     (0x08000000&((data)<<27))
#define  SYS_REG_INT_CTRL_VCPU_dummy_26(data)                                    (0x04000000&((data)<<26))
#define  SYS_REG_INT_CTRL_VCPU_dummy_25(data)                                    (0x02000000&((data)<<25))
#define  SYS_REG_INT_CTRL_VCPU_dummy_24(data)                                    (0x01000000&((data)<<24))
#define  SYS_REG_INT_CTRL_VCPU_dummy_23(data)                                    (0x00800000&((data)<<23))
#define  SYS_REG_INT_CTRL_VCPU_dummy_22(data)                                    (0x00400000&((data)<<22))
#define  SYS_REG_INT_CTRL_VCPU_dummy_21(data)                                    (0x00200000&((data)<<21))
#define  SYS_REG_INT_CTRL_VCPU_dummy_20(data)                                    (0x00100000&((data)<<20))
#define  SYS_REG_INT_CTRL_VCPU_dummy_19(data)                                    (0x00080000&((data)<<19))
#define  SYS_REG_INT_CTRL_VCPU_dummy_18(data)                                    (0x00040000&((data)<<18))
#define  SYS_REG_INT_CTRL_VCPU_dummy_17(data)                                    (0x00020000&((data)<<17))
#define  SYS_REG_INT_CTRL_VCPU_dummy_16(data)                                    (0x00010000&((data)<<16))
#define  SYS_REG_INT_CTRL_VCPU_me_int_vcpu_routing_en(data)                      (0x00008000&((data)<<15))
#define  SYS_REG_INT_CTRL_VCPU_ddc_int_vcpu_routing_en(data)                     (0x00004000&((data)<<14))
#define  SYS_REG_INT_CTRL_VCPU_tv_sb_dc_int_vcpu_routing_en(data)                (0x00002000&((data)<<13))
#define  SYS_REG_INT_CTRL_VCPU_dcphy_int_vcpu_routing_en(data)                   (0x00001000&((data)<<12))
#define  SYS_REG_INT_CTRL_VCPU_dc_int_vcpu_routing_en(data)                      (0x00000800&((data)<<11))
#define  SYS_REG_INT_CTRL_VCPU_tve_int_vcpu_routing_en(data)                     (0x00000400&((data)<<10))
#define  SYS_REG_INT_CTRL_VCPU_osd_int_vcpu_routing_en(data)                     (0x00000200&((data)<<9))
#define  SYS_REG_INT_CTRL_VCPU_ultra_zoom_int_vcpu_routing_en(data)              (0x00000100&((data)<<8))
#define  SYS_REG_INT_CTRL_VCPU_dctl_int_vcpu_routing_en(data)                    (0x00000080&((data)<<7))
#define  SYS_REG_INT_CTRL_VCPU_vbi_int_vcpu_routing_en(data)                     (0x00000040&((data)<<6))
#define  SYS_REG_INT_CTRL_VCPU_vdec_int_vcpu_routing_en(data)                    (0x00000020&((data)<<5))
#define  SYS_REG_INT_CTRL_VCPU_if_demod_int_vcpu_routing_en(data)                (0x00000010&((data)<<4))
#define  SYS_REG_INT_CTRL_VCPU_dispm_int_vcpu_routing_en(data)                   (0x00000008&((data)<<3))
#define  SYS_REG_INT_CTRL_VCPU_dispi_int_vcpu_routing_en(data)                   (0x00000004&((data)<<2))
#define  SYS_REG_INT_CTRL_VCPU_apll_dds_int_vcpu_routing_en(data)                (0x00000002&((data)<<1))
#define  SYS_REG_INT_CTRL_VCPU_write_data(data)                                  (0x00000001&(data))
#define  SYS_REG_INT_CTRL_VCPU_get_disp2tve_int_vcpu_routing_en(data)            ((0x40000000&(data))>>30)
#define  SYS_REG_INT_CTRL_VCPU_get_vodma_int_vcpu_routing_en(data)               ((0x20000000&(data))>>29)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_28(data)                                ((0x10000000&(data))>>28)
#define  SYS_REG_INT_CTRL_VCPU_get_dc_int_vcpu2_routing_en(data)                 ((0x08000000&(data))>>27)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_26(data)                                ((0x04000000&(data))>>26)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_25(data)                                ((0x02000000&(data))>>25)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_24(data)                                ((0x01000000&(data))>>24)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_23(data)                                ((0x00800000&(data))>>23)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_22(data)                                ((0x00400000&(data))>>22)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_21(data)                                ((0x00200000&(data))>>21)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_20(data)                                ((0x00100000&(data))>>20)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_19(data)                                ((0x00080000&(data))>>19)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_18(data)                                ((0x00040000&(data))>>18)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_17(data)                                ((0x00020000&(data))>>17)
#define  SYS_REG_INT_CTRL_VCPU_get_dummy_16(data)                                ((0x00010000&(data))>>16)
#define  SYS_REG_INT_CTRL_VCPU_get_me_int_vcpu_routing_en(data)                  ((0x00008000&(data))>>15)
#define  SYS_REG_INT_CTRL_VCPU_get_ddc_int_vcpu_routing_en(data)                 ((0x00004000&(data))>>14)
#define  SYS_REG_INT_CTRL_VCPU_get_tv_sb_dc_int_vcpu_routing_en(data)            ((0x00002000&(data))>>13)
#define  SYS_REG_INT_CTRL_VCPU_get_dcphy_int_vcpu_routing_en(data)               ((0x00001000&(data))>>12)
#define  SYS_REG_INT_CTRL_VCPU_get_dc_int_vcpu_routing_en(data)                  ((0x00000800&(data))>>11)
#define  SYS_REG_INT_CTRL_VCPU_get_tve_int_vcpu_routing_en(data)                 ((0x00000400&(data))>>10)
#define  SYS_REG_INT_CTRL_VCPU_get_osd_int_vcpu_routing_en(data)                 ((0x00000200&(data))>>9)
#define  SYS_REG_INT_CTRL_VCPU_get_ultra_zoom_int_vcpu_routing_en(data)          ((0x00000100&(data))>>8)
#define  SYS_REG_INT_CTRL_VCPU_get_dctl_int_vcpu_routing_en(data)                ((0x00000080&(data))>>7)
#define  SYS_REG_INT_CTRL_VCPU_get_vbi_int_vcpu_routing_en(data)                 ((0x00000040&(data))>>6)
#define  SYS_REG_INT_CTRL_VCPU_get_vdec_int_vcpu_routing_en(data)                ((0x00000020&(data))>>5)
#define  SYS_REG_INT_CTRL_VCPU_get_if_demod_int_vcpu_routing_en(data)            ((0x00000010&(data))>>4)
#define  SYS_REG_INT_CTRL_VCPU_get_dispm_int_vcpu_routing_en(data)               ((0x00000008&(data))>>3)
#define  SYS_REG_INT_CTRL_VCPU_get_dispi_int_vcpu_routing_en(data)               ((0x00000004&(data))>>2)
#define  SYS_REG_INT_CTRL_VCPU_get_apll_dds_int_vcpu_routing_en(data)            ((0x00000002&(data))>>1)
#define  SYS_REG_INT_CTRL_VCPU_get_write_data(data)                              (0x00000001&(data))

#define  SYS_REG_INT_CTRL_ACPU                                                   0x18000298
#define  SYS_REG_INT_CTRL_ACPU_reg_addr                                          "0xB8000298"
#define  SYS_REG_INT_CTRL_ACPU_reg                                               0xB8000298
#define  SYS_REG_INT_CTRL_ACPU_inst_addr                                         "0x0013"
#define  set_SYS_REG_INT_CTRL_ACPU_reg(data)                                     (*((volatile unsigned int*)SYS_REG_INT_CTRL_ACPU_reg)=data)
#define  get_SYS_REG_INT_CTRL_ACPU_reg                                           (*((volatile unsigned int*)SYS_REG_INT_CTRL_ACPU_reg))
#define  SYS_REG_INT_CTRL_ACPU_me_int_acpu_routing_en_shift                      (16)
#define  SYS_REG_INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en_shift               (15)
#define  SYS_REG_INT_CTRL_ACPU_audio_irq_acpu_routing_en_shift                   (14)
#define  SYS_REG_INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en_shift                (13)
#define  SYS_REG_INT_CTRL_ACPU_dcphy_int_acpu_routing_en_shift                   (12)
#define  SYS_REG_INT_CTRL_ACPU_dc_int_acpu_routing_en_shift                      (11)
#define  SYS_REG_INT_CTRL_ACPU_dummy_10_shift                                    (10)
#define  SYS_REG_INT_CTRL_ACPU_dummy_9_shift                                     (9)
#define  SYS_REG_INT_CTRL_ACPU_dummy_8_shift                                     (8)
#define  SYS_REG_INT_CTRL_ACPU_audio_dma_irq_acpu2_routing_en_shift              (7)
#define  SYS_REG_INT_CTRL_ACPU_audio_irq_acpu2_routing_en_shift                  (6)
#define  SYS_REG_INT_CTRL_ACPU_dummy_5_shift                                     (5)
#define  SYS_REG_INT_CTRL_ACPU_dummy_4_shift                                     (4)
#define  SYS_REG_INT_CTRL_ACPU_dc_int_acpu2_routing_en_shift                     (3)
#define  SYS_REG_INT_CTRL_ACPU_dummy_2_shift                                     (2)
#define  SYS_REG_INT_CTRL_ACPU_dummy_1_shift                                     (1)
#define  SYS_REG_INT_CTRL_ACPU_write_data_shift                                  (0)
#define  SYS_REG_INT_CTRL_ACPU_me_int_acpu_routing_en_mask                       (0x00010000)
#define  SYS_REG_INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en_mask                (0x00008000)
#define  SYS_REG_INT_CTRL_ACPU_audio_irq_acpu_routing_en_mask                    (0x00004000)
#define  SYS_REG_INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en_mask                 (0x00002000)
#define  SYS_REG_INT_CTRL_ACPU_dcphy_int_acpu_routing_en_mask                    (0x00001000)
#define  SYS_REG_INT_CTRL_ACPU_dc_int_acpu_routing_en_mask                       (0x00000800)
#define  SYS_REG_INT_CTRL_ACPU_dummy_10_mask                                     (0x00000400)
#define  SYS_REG_INT_CTRL_ACPU_dummy_9_mask                                      (0x00000200)
#define  SYS_REG_INT_CTRL_ACPU_dummy_8_mask                                      (0x00000100)
#define  SYS_REG_INT_CTRL_ACPU_audio_dma_irq_acpu2_routing_en_mask               (0x00000080)
#define  SYS_REG_INT_CTRL_ACPU_audio_irq_acpu2_routing_en_mask                   (0x00000040)
#define  SYS_REG_INT_CTRL_ACPU_dummy_5_mask                                      (0x00000020)
#define  SYS_REG_INT_CTRL_ACPU_dummy_4_mask                                      (0x00000010)
#define  SYS_REG_INT_CTRL_ACPU_dc_int_acpu2_routing_en_mask                      (0x00000008)
#define  SYS_REG_INT_CTRL_ACPU_dummy_2_mask                                      (0x00000004)
#define  SYS_REG_INT_CTRL_ACPU_dummy_1_mask                                      (0x00000002)
#define  SYS_REG_INT_CTRL_ACPU_write_data_mask                                   (0x00000001)
#define  SYS_REG_INT_CTRL_ACPU_me_int_acpu_routing_en(data)                      (0x00010000&((data)<<16))
#define  SYS_REG_INT_CTRL_ACPU_audio_dma_irq_acpu_routing_en(data)               (0x00008000&((data)<<15))
#define  SYS_REG_INT_CTRL_ACPU_audio_irq_acpu_routing_en(data)                   (0x00004000&((data)<<14))
#define  SYS_REG_INT_CTRL_ACPU_tv_sb_dc_int_acpu_routing_en(data)                (0x00002000&((data)<<13))
#define  SYS_REG_INT_CTRL_ACPU_dcphy_int_acpu_routing_en(data)                   (0x00001000&((data)<<12))
#define  SYS_REG_INT_CTRL_ACPU_dc_int_acpu_routing_en(data)                      (0x00000800&((data)<<11))
#define  SYS_REG_INT_CTRL_ACPU_dummy_10(data)                                    (0x00000400&((data)<<10))
#define  SYS_REG_INT_CTRL_ACPU_dummy_9(data)                                     (0x00000200&((data)<<9))
#define  SYS_REG_INT_CTRL_ACPU_dummy_8(data)                                     (0x00000100&((data)<<8))
#define  SYS_REG_INT_CTRL_ACPU_audio_dma_irq_acpu2_routing_en(data)              (0x00000080&((data)<<7))
#define  SYS_REG_INT_CTRL_ACPU_audio_irq_acpu2_routing_en(data)                  (0x00000040&((data)<<6))
#define  SYS_REG_INT_CTRL_ACPU_dummy_5(data)                                     (0x00000020&((data)<<5))
#define  SYS_REG_INT_CTRL_ACPU_dummy_4(data)                                     (0x00000010&((data)<<4))
#define  SYS_REG_INT_CTRL_ACPU_dc_int_acpu2_routing_en(data)                     (0x00000008&((data)<<3))
#define  SYS_REG_INT_CTRL_ACPU_dummy_2(data)                                     (0x00000004&((data)<<2))
#define  SYS_REG_INT_CTRL_ACPU_dummy_1(data)                                     (0x00000002&((data)<<1))
#define  SYS_REG_INT_CTRL_ACPU_write_data(data)                                  (0x00000001&(data))
#define  SYS_REG_INT_CTRL_ACPU_get_me_int_acpu_routing_en(data)                  ((0x00010000&(data))>>16)
#define  SYS_REG_INT_CTRL_ACPU_get_audio_dma_irq_acpu_routing_en(data)           ((0x00008000&(data))>>15)
#define  SYS_REG_INT_CTRL_ACPU_get_audio_irq_acpu_routing_en(data)               ((0x00004000&(data))>>14)
#define  SYS_REG_INT_CTRL_ACPU_get_tv_sb_dc_int_acpu_routing_en(data)            ((0x00002000&(data))>>13)
#define  SYS_REG_INT_CTRL_ACPU_get_dcphy_int_acpu_routing_en(data)               ((0x00001000&(data))>>12)
#define  SYS_REG_INT_CTRL_ACPU_get_dc_int_acpu_routing_en(data)                  ((0x00000800&(data))>>11)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_10(data)                                ((0x00000400&(data))>>10)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_9(data)                                 ((0x00000200&(data))>>9)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_8(data)                                 ((0x00000100&(data))>>8)
#define  SYS_REG_INT_CTRL_ACPU_get_audio_dma_irq_acpu2_routing_en(data)          ((0x00000080&(data))>>7)
#define  SYS_REG_INT_CTRL_ACPU_get_audio_irq_acpu2_routing_en(data)              ((0x00000040&(data))>>6)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_5(data)                                 ((0x00000020&(data))>>5)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_4(data)                                 ((0x00000010&(data))>>4)
#define  SYS_REG_INT_CTRL_ACPU_get_dc_int_acpu2_routing_en(data)                 ((0x00000008&(data))>>3)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_2(data)                                 ((0x00000004&(data))>>2)
#define  SYS_REG_INT_CTRL_ACPU_get_dummy_1(data)                                 ((0x00000002&(data))>>1)
#define  SYS_REG_INT_CTRL_ACPU_get_write_data(data)                              (0x00000001&(data))

#define  SYS_REG_INT_CTRL_KCPU                                                   0x1800029C
#define  SYS_REG_INT_CTRL_KCPU_reg_addr                                          "0xB800029C"
#define  SYS_REG_INT_CTRL_KCPU_reg                                               0xB800029C
#define  SYS_REG_INT_CTRL_KCPU_inst_addr                                         "0x0014"
#define  set_SYS_REG_INT_CTRL_KCPU_reg(data)                                     (*((volatile unsigned int*)SYS_REG_INT_CTRL_KCPU_reg)=data)
#define  get_SYS_REG_INT_CTRL_KCPU_reg                                           (*((volatile unsigned int*)SYS_REG_INT_CTRL_KCPU_reg))
#define  SYS_REG_INT_CTRL_KCPU_smartcard_int_kcpu_routing_en_shift               (31)
#define  SYS_REG_INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en_shift                (30)
#define  SYS_REG_INT_CTRL_KCPU_vodma_int_kcpu_routing_en_shift                   (29)
#define  SYS_REG_INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en_shift           (28)
#define  SYS_REG_INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en_shift    (27)
#define  SYS_REG_INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en_shift            (26)
#define  SYS_REG_INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en_shift    (25)
#define  SYS_REG_INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en_shift            (24)
#define  SYS_REG_INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en_shift        (23)
#define  SYS_REG_INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en_shift             (22)
#define  SYS_REG_INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en_shift             (21)
#define  SYS_REG_INT_CTRL_KCPU_gpu_int_kcpu_routing_en_shift                     (20)
#define  SYS_REG_INT_CTRL_KCPU_usb3_int_kcpu_routing_en_shift                    (19)
#define  SYS_REG_INT_CTRL_KCPU_usb2_int_kcpu_routing_en_shift                    (18)
#define  SYS_REG_INT_CTRL_KCPU_etn_int_kcpu_routing_en_shift                     (17)
#define  SYS_REG_INT_CTRL_KCPU_sd_int_kcpu_routing_en_shift                      (16)
#define  SYS_REG_INT_CTRL_KCPU_dummy_15_shift                                    (15)
#define  SYS_REG_INT_CTRL_KCPU_ddc_int_kcpu_routing_en_shift                     (14)
#define  SYS_REG_INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en_shift                (13)
#define  SYS_REG_INT_CTRL_KCPU_dcphy_int_kcpu_routing_en_shift                   (12)
#define  SYS_REG_INT_CTRL_KCPU_dc_int_kcpu_routing_en_shift                      (11)
#define  SYS_REG_INT_CTRL_KCPU_tve_int_kcpu_routing_en_shift                     (10)
#define  SYS_REG_INT_CTRL_KCPU_osd_int_kcpu_routing_en_shift                     (9)
#define  SYS_REG_INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en_shift              (8)
#define  SYS_REG_INT_CTRL_KCPU_dctl_int_kcpu_routing_en_shift                    (7)
#define  SYS_REG_INT_CTRL_KCPU_vbi_int_kcpu_routing_en_shift                     (6)
#define  SYS_REG_INT_CTRL_KCPU_vdec_int_kcpu_routing_en_shift                    (5)
#define  SYS_REG_INT_CTRL_KCPU_if_demod_int_kcpu_routing_en_shift                (4)
#define  SYS_REG_INT_CTRL_KCPU_dispm_int_kcpu_routing_en_shift                   (3)
#define  SYS_REG_INT_CTRL_KCPU_dispi_int_kcpu_routing_en_shift                   (2)
#define  SYS_REG_INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en_shift                (1)
#define  SYS_REG_INT_CTRL_KCPU_write_data_shift                                  (0)
#define  SYS_REG_INT_CTRL_KCPU_smartcard_int_kcpu_routing_en_mask                (0x80000000)
#define  SYS_REG_INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en_mask                 (0x40000000)
#define  SYS_REG_INT_CTRL_KCPU_vodma_int_kcpu_routing_en_mask                    (0x20000000)
#define  SYS_REG_INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en_mask            (0x10000000)
#define  SYS_REG_INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en_mask     (0x08000000)
#define  SYS_REG_INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en_mask             (0x04000000)
#define  SYS_REG_INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en_mask     (0x02000000)
#define  SYS_REG_INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en_mask             (0x01000000)
#define  SYS_REG_INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en_mask         (0x00800000)
#define  SYS_REG_INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en_mask              (0x00400000)
#define  SYS_REG_INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en_mask              (0x00200000)
#define  SYS_REG_INT_CTRL_KCPU_gpu_int_kcpu_routing_en_mask                      (0x00100000)
#define  SYS_REG_INT_CTRL_KCPU_usb3_int_kcpu_routing_en_mask                     (0x00080000)
#define  SYS_REG_INT_CTRL_KCPU_usb2_int_kcpu_routing_en_mask                     (0x00040000)
#define  SYS_REG_INT_CTRL_KCPU_etn_int_kcpu_routing_en_mask                      (0x00020000)
#define  SYS_REG_INT_CTRL_KCPU_sd_int_kcpu_routing_en_mask                       (0x00010000)
#define  SYS_REG_INT_CTRL_KCPU_dummy_15_mask                                     (0x00008000)
#define  SYS_REG_INT_CTRL_KCPU_ddc_int_kcpu_routing_en_mask                      (0x00004000)
#define  SYS_REG_INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en_mask                 (0x00002000)
#define  SYS_REG_INT_CTRL_KCPU_dcphy_int_kcpu_routing_en_mask                    (0x00001000)
#define  SYS_REG_INT_CTRL_KCPU_dc_int_kcpu_routing_en_mask                       (0x00000800)
#define  SYS_REG_INT_CTRL_KCPU_tve_int_kcpu_routing_en_mask                      (0x00000400)
#define  SYS_REG_INT_CTRL_KCPU_osd_int_kcpu_routing_en_mask                      (0x00000200)
#define  SYS_REG_INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en_mask               (0x00000100)
#define  SYS_REG_INT_CTRL_KCPU_dctl_int_kcpu_routing_en_mask                     (0x00000080)
#define  SYS_REG_INT_CTRL_KCPU_vbi_int_kcpu_routing_en_mask                      (0x00000040)
#define  SYS_REG_INT_CTRL_KCPU_vdec_int_kcpu_routing_en_mask                     (0x00000020)
#define  SYS_REG_INT_CTRL_KCPU_if_demod_int_kcpu_routing_en_mask                 (0x00000010)
#define  SYS_REG_INT_CTRL_KCPU_dispm_int_kcpu_routing_en_mask                    (0x00000008)
#define  SYS_REG_INT_CTRL_KCPU_dispi_int_kcpu_routing_en_mask                    (0x00000004)
#define  SYS_REG_INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en_mask                 (0x00000002)
#define  SYS_REG_INT_CTRL_KCPU_write_data_mask                                   (0x00000001)
#define  SYS_REG_INT_CTRL_KCPU_smartcard_int_kcpu_routing_en(data)               (0x80000000&((data)<<31))
#define  SYS_REG_INT_CTRL_KCPU_disp2tve_int_kcpu_routing_en(data)                (0x40000000&((data)<<30))
#define  SYS_REG_INT_CTRL_KCPU_vodma_int_kcpu_routing_en(data)                   (0x20000000&((data)<<29))
#define  SYS_REG_INT_CTRL_KCPU_standby_syncp_int_kcpu_routing_en(data)           (0x10000000&((data)<<28))
#define  SYS_REG_INT_CTRL_KCPU_standby_hdmi_clk_det_int_kcpu_routing_en(data)    (0x08000000&((data)<<27))
#define  SYS_REG_INT_CTRL_KCPU_standby_wdog_int_kcpu_routing_en(data)            (0x04000000&((data)<<26))
#define  SYS_REG_INT_CTRL_KCPU_standby_iso_misc_off_int_kcpu_routing_en(data)    (0x02000000&((data)<<25))
#define  SYS_REG_INT_CTRL_KCPU_standby_cbus_int_kcpu_routing_en(data)            (0x01000000&((data)<<24))
#define  SYS_REG_INT_CTRL_KCPU_standby_iso_misc_int_kcpu_routing_en(data)        (0x00800000&((data)<<23))
#define  SYS_REG_INT_CTRL_KCPU_standby_cec_int_kcpu_routing_en(data)             (0x00400000&((data)<<22))
#define  SYS_REG_INT_CTRL_KCPU_standby_rtc_int_kcpu_routing_en(data)             (0x00200000&((data)<<21))
#define  SYS_REG_INT_CTRL_KCPU_gpu_int_kcpu_routing_en(data)                     (0x00100000&((data)<<20))
#define  SYS_REG_INT_CTRL_KCPU_usb3_int_kcpu_routing_en(data)                    (0x00080000&((data)<<19))
#define  SYS_REG_INT_CTRL_KCPU_usb2_int_kcpu_routing_en(data)                    (0x00040000&((data)<<18))
#define  SYS_REG_INT_CTRL_KCPU_etn_int_kcpu_routing_en(data)                     (0x00020000&((data)<<17))
#define  SYS_REG_INT_CTRL_KCPU_sd_int_kcpu_routing_en(data)                      (0x00010000&((data)<<16))
#define  SYS_REG_INT_CTRL_KCPU_dummy_15(data)                                    (0x00008000&((data)<<15))
#define  SYS_REG_INT_CTRL_KCPU_ddc_int_kcpu_routing_en(data)                     (0x00004000&((data)<<14))
#define  SYS_REG_INT_CTRL_KCPU_tv_sb_dc_int_kcpu_routing_en(data)                (0x00002000&((data)<<13))
#define  SYS_REG_INT_CTRL_KCPU_dcphy_int_kcpu_routing_en(data)                   (0x00001000&((data)<<12))
#define  SYS_REG_INT_CTRL_KCPU_dc_int_kcpu_routing_en(data)                      (0x00000800&((data)<<11))
#define  SYS_REG_INT_CTRL_KCPU_tve_int_kcpu_routing_en(data)                     (0x00000400&((data)<<10))
#define  SYS_REG_INT_CTRL_KCPU_osd_int_kcpu_routing_en(data)                     (0x00000200&((data)<<9))
#define  SYS_REG_INT_CTRL_KCPU_ultra_zoom_int_kcpu_routing_en(data)              (0x00000100&((data)<<8))
#define  SYS_REG_INT_CTRL_KCPU_dctl_int_kcpu_routing_en(data)                    (0x00000080&((data)<<7))
#define  SYS_REG_INT_CTRL_KCPU_vbi_int_kcpu_routing_en(data)                     (0x00000040&((data)<<6))
#define  SYS_REG_INT_CTRL_KCPU_vdec_int_kcpu_routing_en(data)                    (0x00000020&((data)<<5))
#define  SYS_REG_INT_CTRL_KCPU_if_demod_int_kcpu_routing_en(data)                (0x00000010&((data)<<4))
#define  SYS_REG_INT_CTRL_KCPU_dispm_int_kcpu_routing_en(data)                   (0x00000008&((data)<<3))
#define  SYS_REG_INT_CTRL_KCPU_dispi_int_kcpu_routing_en(data)                   (0x00000004&((data)<<2))
#define  SYS_REG_INT_CTRL_KCPU_apll_dds_int_kcpu_routing_en(data)                (0x00000002&((data)<<1))
#define  SYS_REG_INT_CTRL_KCPU_write_data(data)                                  (0x00000001&(data))
#define  SYS_REG_INT_CTRL_KCPU_get_smartcard_int_kcpu_routing_en(data)           ((0x80000000&(data))>>31)
#define  SYS_REG_INT_CTRL_KCPU_get_disp2tve_int_kcpu_routing_en(data)            ((0x40000000&(data))>>30)
#define  SYS_REG_INT_CTRL_KCPU_get_vodma_int_kcpu_routing_en(data)               ((0x20000000&(data))>>29)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_syncp_int_kcpu_routing_en(data)       ((0x10000000&(data))>>28)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_hdmi_clk_det_int_kcpu_routing_en(data) ((0x08000000&(data))>>27)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_wdog_int_kcpu_routing_en(data)        ((0x04000000&(data))>>26)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_iso_misc_off_int_kcpu_routing_en(data) ((0x02000000&(data))>>25)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_cbus_int_kcpu_routing_en(data)        ((0x01000000&(data))>>24)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_iso_misc_int_kcpu_routing_en(data)    ((0x00800000&(data))>>23)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_cec_int_kcpu_routing_en(data)         ((0x00400000&(data))>>22)
#define  SYS_REG_INT_CTRL_KCPU_get_standby_rtc_int_kcpu_routing_en(data)         ((0x00200000&(data))>>21)
#define  SYS_REG_INT_CTRL_KCPU_get_gpu_int_kcpu_routing_en(data)                 ((0x00100000&(data))>>20)
#define  SYS_REG_INT_CTRL_KCPU_get_usb3_int_kcpu_routing_en(data)                ((0x00080000&(data))>>19)
#define  SYS_REG_INT_CTRL_KCPU_get_usb2_int_kcpu_routing_en(data)                ((0x00040000&(data))>>18)
#define  SYS_REG_INT_CTRL_KCPU_get_etn_int_kcpu_routing_en(data)                 ((0x00020000&(data))>>17)
#define  SYS_REG_INT_CTRL_KCPU_get_sd_int_kcpu_routing_en(data)                  ((0x00010000&(data))>>16)
#define  SYS_REG_INT_CTRL_KCPU_get_dummy_15(data)                                ((0x00008000&(data))>>15)
#define  SYS_REG_INT_CTRL_KCPU_get_ddc_int_kcpu_routing_en(data)                 ((0x00004000&(data))>>14)
#define  SYS_REG_INT_CTRL_KCPU_get_tv_sb_dc_int_kcpu_routing_en(data)            ((0x00002000&(data))>>13)
#define  SYS_REG_INT_CTRL_KCPU_get_dcphy_int_kcpu_routing_en(data)               ((0x00001000&(data))>>12)
#define  SYS_REG_INT_CTRL_KCPU_get_dc_int_kcpu_routing_en(data)                  ((0x00000800&(data))>>11)
#define  SYS_REG_INT_CTRL_KCPU_get_tve_int_kcpu_routing_en(data)                 ((0x00000400&(data))>>10)
#define  SYS_REG_INT_CTRL_KCPU_get_osd_int_kcpu_routing_en(data)                 ((0x00000200&(data))>>9)
#define  SYS_REG_INT_CTRL_KCPU_get_ultra_zoom_int_kcpu_routing_en(data)          ((0x00000100&(data))>>8)
#define  SYS_REG_INT_CTRL_KCPU_get_dctl_int_kcpu_routing_en(data)                ((0x00000080&(data))>>7)
#define  SYS_REG_INT_CTRL_KCPU_get_vbi_int_kcpu_routing_en(data)                 ((0x00000040&(data))>>6)
#define  SYS_REG_INT_CTRL_KCPU_get_vdec_int_kcpu_routing_en(data)                ((0x00000020&(data))>>5)
#define  SYS_REG_INT_CTRL_KCPU_get_if_demod_int_kcpu_routing_en(data)            ((0x00000010&(data))>>4)
#define  SYS_REG_INT_CTRL_KCPU_get_dispm_int_kcpu_routing_en(data)               ((0x00000008&(data))>>3)
#define  SYS_REG_INT_CTRL_KCPU_get_dispi_int_kcpu_routing_en(data)               ((0x00000004&(data))>>2)
#define  SYS_REG_INT_CTRL_KCPU_get_apll_dds_int_kcpu_routing_en(data)            ((0x00000002&(data))>>1)
#define  SYS_REG_INT_CTRL_KCPU_get_write_data(data)                              (0x00000001&(data))

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
#define  SYS_REG_INT_CTRL_MEMC_write_data_shift                                  (0)
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
#define  SYS_REG_INT_CTRL_MEMC_write_data_mask                                   (0x00000001)
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
#define  SYS_REG_INT_CTRL_MEMC_write_data(data)                                  (0x00000001&(data))
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
#define  SYS_REG_INT_CTRL_MEMC_get_write_data(data)                              (0x00000001&(data))

#define  SYS_REG_INT_CTRL_SCPU_2                                                 0x180002A4
#define  SYS_REG_INT_CTRL_SCPU_2_reg_addr                                        "0xB80002A4"
#define  SYS_REG_INT_CTRL_SCPU_2_reg                                             0xB80002A4
#define  SYS_REG_INT_CTRL_SCPU_2_inst_addr                                       "0x0016"
#define  set_SYS_REG_INT_CTRL_SCPU_2_reg(data)                                   (*((volatile unsigned int*)SYS_REG_INT_CTRL_SCPU_2_reg)=data)
#define  get_SYS_REG_INT_CTRL_SCPU_2_reg                                         (*((volatile unsigned int*)SYS_REG_INT_CTRL_SCPU_2_reg))
#define  SYS_REG_INT_CTRL_SCPU_2_usb2_ex_int_scpu_routing_en_shift               (15)
#define  SYS_REG_INT_CTRL_SCPU_2_dc_security_int_scpu_routing_en_shift           (14)
#define  SYS_REG_INT_CTRL_SCPU_2_tm_security_int_scpu_routing_en_shift           (10)
#define  SYS_REG_INT_CTRL_SCPU_2_tp_security_int_scpu_routing_en_shift           (9)
#define  SYS_REG_INT_CTRL_SCPU_2_nf_security_int_scpu_routing_en_shift           (8)
#define  SYS_REG_INT_CTRL_SCPU_2_emmc_security_int_scpu_routing_en_shift         (7)
#define  SYS_REG_INT_CTRL_SCPU_2_md_security_int_scpu_routing_en_shift           (6)
#define  SYS_REG_INT_CTRL_SCPU_2_mcp_security_int_scpu_routing_en_shift          (5)
#define  SYS_REG_INT_CTRL_SCPU_2_sb2_security_int_scpu_routing_en_shift          (4)
#define  SYS_REG_INT_CTRL_SCPU_2_mis_security_int_scpu_routing_en_shift          (3)
#define  SYS_REG_INT_CTRL_SCPU_2_se_security_int_scpu_routing_en_shift           (2)
#define  SYS_REG_INT_CTRL_SCPU_2_dc2_security_int_scpu_routing_en_shift          (1)
#define  SYS_REG_INT_CTRL_SCPU_2_write_data_shift                                (0)
#define  SYS_REG_INT_CTRL_SCPU_2_usb2_ex_int_scpu_routing_en_mask                (0x00008000)
#define  SYS_REG_INT_CTRL_SCPU_2_dc_security_int_scpu_routing_en_mask            (0x00004000)
#define  SYS_REG_INT_CTRL_SCPU_2_tm_security_int_scpu_routing_en_mask            (0x00000400)
#define  SYS_REG_INT_CTRL_SCPU_2_tp_security_int_scpu_routing_en_mask            (0x00000200)
#define  SYS_REG_INT_CTRL_SCPU_2_nf_security_int_scpu_routing_en_mask            (0x00000100)
#define  SYS_REG_INT_CTRL_SCPU_2_emmc_security_int_scpu_routing_en_mask          (0x00000080)
#define  SYS_REG_INT_CTRL_SCPU_2_md_security_int_scpu_routing_en_mask            (0x00000040)
#define  SYS_REG_INT_CTRL_SCPU_2_mcp_security_int_scpu_routing_en_mask           (0x00000020)
#define  SYS_REG_INT_CTRL_SCPU_2_sb2_security_int_scpu_routing_en_mask           (0x00000010)
#define  SYS_REG_INT_CTRL_SCPU_2_mis_security_int_scpu_routing_en_mask           (0x00000008)
#define  SYS_REG_INT_CTRL_SCPU_2_se_security_int_scpu_routing_en_mask            (0x00000004)
#define  SYS_REG_INT_CTRL_SCPU_2_dc2_security_int_scpu_routing_en_mask           (0x00000002)
#define  SYS_REG_INT_CTRL_SCPU_2_write_data_mask                                 (0x00000001)
#define  SYS_REG_INT_CTRL_SCPU_2_usb2_ex_int_scpu_routing_en(data)               (0x00008000&((data)<<15))
#define  SYS_REG_INT_CTRL_SCPU_2_dc_security_int_scpu_routing_en(data)           (0x00004000&((data)<<14))
#define  SYS_REG_INT_CTRL_SCPU_2_tm_security_int_scpu_routing_en(data)           (0x00000400&((data)<<10))
#define  SYS_REG_INT_CTRL_SCPU_2_tp_security_int_scpu_routing_en(data)           (0x00000200&((data)<<9))
#define  SYS_REG_INT_CTRL_SCPU_2_nf_security_int_scpu_routing_en(data)           (0x00000100&((data)<<8))
#define  SYS_REG_INT_CTRL_SCPU_2_emmc_security_int_scpu_routing_en(data)         (0x00000080&((data)<<7))
#define  SYS_REG_INT_CTRL_SCPU_2_md_security_int_scpu_routing_en(data)           (0x00000040&((data)<<6))
#define  SYS_REG_INT_CTRL_SCPU_2_mcp_security_int_scpu_routing_en(data)          (0x00000020&((data)<<5))
#define  SYS_REG_INT_CTRL_SCPU_2_sb2_security_int_scpu_routing_en(data)          (0x00000010&((data)<<4))
#define  SYS_REG_INT_CTRL_SCPU_2_mis_security_int_scpu_routing_en(data)          (0x00000008&((data)<<3))
#define  SYS_REG_INT_CTRL_SCPU_2_se_security_int_scpu_routing_en(data)           (0x00000004&((data)<<2))
#define  SYS_REG_INT_CTRL_SCPU_2_dc2_security_int_scpu_routing_en(data)          (0x00000002&((data)<<1))
#define  SYS_REG_INT_CTRL_SCPU_2_write_data(data)                                (0x00000001&(data))
#define  SYS_REG_INT_CTRL_SCPU_2_get_usb2_ex_int_scpu_routing_en(data)           ((0x00008000&(data))>>15)
#define  SYS_REG_INT_CTRL_SCPU_2_get_dc_security_int_scpu_routing_en(data)       ((0x00004000&(data))>>14)
#define  SYS_REG_INT_CTRL_SCPU_2_get_tm_security_int_scpu_routing_en(data)       ((0x00000400&(data))>>10)
#define  SYS_REG_INT_CTRL_SCPU_2_get_tp_security_int_scpu_routing_en(data)       ((0x00000200&(data))>>9)
#define  SYS_REG_INT_CTRL_SCPU_2_get_nf_security_int_scpu_routing_en(data)       ((0x00000100&(data))>>8)
#define  SYS_REG_INT_CTRL_SCPU_2_get_emmc_security_int_scpu_routing_en(data)     ((0x00000080&(data))>>7)
#define  SYS_REG_INT_CTRL_SCPU_2_get_md_security_int_scpu_routing_en(data)       ((0x00000040&(data))>>6)
#define  SYS_REG_INT_CTRL_SCPU_2_get_mcp_security_int_scpu_routing_en(data)      ((0x00000020&(data))>>5)
#define  SYS_REG_INT_CTRL_SCPU_2_get_sb2_security_int_scpu_routing_en(data)      ((0x00000010&(data))>>4)
#define  SYS_REG_INT_CTRL_SCPU_2_get_mis_security_int_scpu_routing_en(data)      ((0x00000008&(data))>>3)
#define  SYS_REG_INT_CTRL_SCPU_2_get_se_security_int_scpu_routing_en(data)       ((0x00000004&(data))>>2)
#define  SYS_REG_INT_CTRL_SCPU_2_get_dc2_security_int_scpu_routing_en(data)      ((0x00000002&(data))>>1)
#define  SYS_REG_INT_CTRL_SCPU_2_get_write_data(data)                            (0x00000001&(data))

#define  SYS_REG_INT_CTRL_KCPU_2                                                 0x180002A8
#define  SYS_REG_INT_CTRL_KCPU_2_reg_addr                                        "0xB80002A8"
#define  SYS_REG_INT_CTRL_KCPU_2_reg                                             0xB80002A8
#define  SYS_REG_INT_CTRL_KCPU_2_inst_addr                                       "0x0017"
#define  set_SYS_REG_INT_CTRL_KCPU_2_reg(data)                                   (*((volatile unsigned int*)SYS_REG_INT_CTRL_KCPU_2_reg)=data)
#define  get_SYS_REG_INT_CTRL_KCPU_2_reg                                         (*((volatile unsigned int*)SYS_REG_INT_CTRL_KCPU_2_reg))
#define  SYS_REG_INT_CTRL_KCPU_2_usb2_ex_int_kcpu_routing_en_shift               (15)
#define  SYS_REG_INT_CTRL_KCPU_2_dc_security_int_kcpu_routing_en_shift           (14)
#define  SYS_REG_INT_CTRL_KCPU_2_tm_security_int_kcpu_routing_en_shift           (10)
#define  SYS_REG_INT_CTRL_KCPU_2_tp_security_int_kcpu_routing_en_shift           (9)
#define  SYS_REG_INT_CTRL_KCPU_2_nf_security_int_kcpu_routing_en_shift           (8)
#define  SYS_REG_INT_CTRL_KCPU_2_emmc_security_int_kcpu_routing_en_shift         (7)
#define  SYS_REG_INT_CTRL_KCPU_2_md_security_int_kcpu_routing_en_shift           (6)
#define  SYS_REG_INT_CTRL_KCPU_2_mcp_security_int_kcpu_routing_en_shift          (5)
#define  SYS_REG_INT_CTRL_KCPU_2_sb2_security_int_kcpu_routing_en_shift          (4)
#define  SYS_REG_INT_CTRL_KCPU_2_mis_security_int_kcpu_routing_en_shift          (3)
#define  SYS_REG_INT_CTRL_KCPU_2_se_security_int_kcpu_routing_en_shift           (2)
#define  SYS_REG_INT_CTRL_KCPU_2_dc2_security_int_kcpu_routing_en_shift          (1)
#define  SYS_REG_INT_CTRL_KCPU_2_write_data_shift                                (0)
#define  SYS_REG_INT_CTRL_KCPU_2_usb2_ex_int_kcpu_routing_en_mask                (0x00008000)
#define  SYS_REG_INT_CTRL_KCPU_2_dc_security_int_kcpu_routing_en_mask            (0x00004000)
#define  SYS_REG_INT_CTRL_KCPU_2_tm_security_int_kcpu_routing_en_mask            (0x00000400)
#define  SYS_REG_INT_CTRL_KCPU_2_tp_security_int_kcpu_routing_en_mask            (0x00000200)
#define  SYS_REG_INT_CTRL_KCPU_2_nf_security_int_kcpu_routing_en_mask            (0x00000100)
#define  SYS_REG_INT_CTRL_KCPU_2_emmc_security_int_kcpu_routing_en_mask          (0x00000080)
#define  SYS_REG_INT_CTRL_KCPU_2_md_security_int_kcpu_routing_en_mask            (0x00000040)
#define  SYS_REG_INT_CTRL_KCPU_2_mcp_security_int_kcpu_routing_en_mask           (0x00000020)
#define  SYS_REG_INT_CTRL_KCPU_2_sb2_security_int_kcpu_routing_en_mask           (0x00000010)
#define  SYS_REG_INT_CTRL_KCPU_2_mis_security_int_kcpu_routing_en_mask           (0x00000008)
#define  SYS_REG_INT_CTRL_KCPU_2_se_security_int_kcpu_routing_en_mask            (0x00000004)
#define  SYS_REG_INT_CTRL_KCPU_2_dc2_security_int_kcpu_routing_en_mask           (0x00000002)
#define  SYS_REG_INT_CTRL_KCPU_2_write_data_mask                                 (0x00000001)
#define  SYS_REG_INT_CTRL_KCPU_2_usb2_ex_int_kcpu_routing_en(data)               (0x00008000&((data)<<15))
#define  SYS_REG_INT_CTRL_KCPU_2_dc_security_int_kcpu_routing_en(data)           (0x00004000&((data)<<14))
#define  SYS_REG_INT_CTRL_KCPU_2_tm_security_int_kcpu_routing_en(data)           (0x00000400&((data)<<10))
#define  SYS_REG_INT_CTRL_KCPU_2_tp_security_int_kcpu_routing_en(data)           (0x00000200&((data)<<9))
#define  SYS_REG_INT_CTRL_KCPU_2_nf_security_int_kcpu_routing_en(data)           (0x00000100&((data)<<8))
#define  SYS_REG_INT_CTRL_KCPU_2_emmc_security_int_kcpu_routing_en(data)         (0x00000080&((data)<<7))
#define  SYS_REG_INT_CTRL_KCPU_2_md_security_int_kcpu_routing_en(data)           (0x00000040&((data)<<6))
#define  SYS_REG_INT_CTRL_KCPU_2_mcp_security_int_kcpu_routing_en(data)          (0x00000020&((data)<<5))
#define  SYS_REG_INT_CTRL_KCPU_2_sb2_security_int_kcpu_routing_en(data)          (0x00000010&((data)<<4))
#define  SYS_REG_INT_CTRL_KCPU_2_mis_security_int_kcpu_routing_en(data)          (0x00000008&((data)<<3))
#define  SYS_REG_INT_CTRL_KCPU_2_se_security_int_kcpu_routing_en(data)           (0x00000004&((data)<<2))
#define  SYS_REG_INT_CTRL_KCPU_2_dc2_security_int_kcpu_routing_en(data)          (0x00000002&((data)<<1))
#define  SYS_REG_INT_CTRL_KCPU_2_write_data(data)                                (0x00000001&(data))
#define  SYS_REG_INT_CTRL_KCPU_2_get_usb2_ex_int_kcpu_routing_en(data)           ((0x00008000&(data))>>15)
#define  SYS_REG_INT_CTRL_KCPU_2_get_dc_security_int_kcpu_routing_en(data)       ((0x00004000&(data))>>14)
#define  SYS_REG_INT_CTRL_KCPU_2_get_tm_security_int_kcpu_routing_en(data)       ((0x00000400&(data))>>10)
#define  SYS_REG_INT_CTRL_KCPU_2_get_tp_security_int_kcpu_routing_en(data)       ((0x00000200&(data))>>9)
#define  SYS_REG_INT_CTRL_KCPU_2_get_nf_security_int_kcpu_routing_en(data)       ((0x00000100&(data))>>8)
#define  SYS_REG_INT_CTRL_KCPU_2_get_emmc_security_int_kcpu_routing_en(data)     ((0x00000080&(data))>>7)
#define  SYS_REG_INT_CTRL_KCPU_2_get_md_security_int_kcpu_routing_en(data)       ((0x00000040&(data))>>6)
#define  SYS_REG_INT_CTRL_KCPU_2_get_mcp_security_int_kcpu_routing_en(data)      ((0x00000020&(data))>>5)
#define  SYS_REG_INT_CTRL_KCPU_2_get_sb2_security_int_kcpu_routing_en(data)      ((0x00000010&(data))>>4)
#define  SYS_REG_INT_CTRL_KCPU_2_get_mis_security_int_kcpu_routing_en(data)      ((0x00000008&(data))>>3)
#define  SYS_REG_INT_CTRL_KCPU_2_get_se_security_int_kcpu_routing_en(data)       ((0x00000004&(data))>>2)
#define  SYS_REG_INT_CTRL_KCPU_2_get_dc2_security_int_kcpu_routing_en(data)      ((0x00000002&(data))>>1)
#define  SYS_REG_INT_CTRL_KCPU_2_get_write_data(data)                            (0x00000001&(data))

#define  SYS_REG_SS_MAIN_RHVT_0                                                  0x180002B0
#define  SYS_REG_SS_MAIN_RHVT_0_reg_addr                                         "0xB80002B0"
#define  SYS_REG_SS_MAIN_RHVT_0_reg                                              0xB80002B0
#define  SYS_REG_SS_MAIN_RHVT_0_inst_addr                                        "0x0018"
#define  set_SYS_REG_SS_MAIN_RHVT_0_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_MAIN_RHVT_0_reg)=data)
#define  get_SYS_REG_SS_MAIN_RHVT_0_reg                                          (*((volatile unsigned int*)SYS_REG_SS_MAIN_RHVT_0_reg))
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_dss_rst_n_shift                         (31)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_ro_sel_shift                            (25)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_wire_sel_shift                          (24)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_ready_shift                             (20)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_count_out_shift                         (0)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_dss_rst_n_mask                          (0x80000000)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_ro_sel_mask                             (0x0E000000)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_wire_sel_mask                           (0x01000000)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_ready_mask                              (0x00100000)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_count_out_mask                          (0x000FFFFF)
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_dss_rst_n(data)                         (0x80000000&((data)<<31))
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_ro_sel(data)                            (0x0E000000&((data)<<25))
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_wire_sel(data)                          (0x01000000&((data)<<24))
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_ready(data)                             (0x00100000&((data)<<20))
#define  SYS_REG_SS_MAIN_RHVT_0_dss_main_count_out(data)                         (0x000FFFFF&(data))
#define  SYS_REG_SS_MAIN_RHVT_0_get_dss_main_dss_rst_n(data)                     ((0x80000000&(data))>>31)
#define  SYS_REG_SS_MAIN_RHVT_0_get_dss_main_ro_sel(data)                        ((0x0E000000&(data))>>25)
#define  SYS_REG_SS_MAIN_RHVT_0_get_dss_main_wire_sel(data)                      ((0x01000000&(data))>>24)
#define  SYS_REG_SS_MAIN_RHVT_0_get_dss_main_ready(data)                         ((0x00100000&(data))>>20)
#define  SYS_REG_SS_MAIN_RHVT_0_get_dss_main_count_out(data)                     (0x000FFFFF&(data))

#define  SYS_REG_SS_MAIN_RHVT_1                                                  0x180002B4
#define  SYS_REG_SS_MAIN_RHVT_1_reg_addr                                         "0xB80002B4"
#define  SYS_REG_SS_MAIN_RHVT_1_reg                                              0xB80002B4
#define  SYS_REG_SS_MAIN_RHVT_1_inst_addr                                        "0x0019"
#define  set_SYS_REG_SS_MAIN_RHVT_1_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_MAIN_RHVT_1_reg)=data)
#define  get_SYS_REG_SS_MAIN_RHVT_1_reg                                          (*((volatile unsigned int*)SYS_REG_SS_MAIN_RHVT_1_reg))
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_speed_en_shift                          (21)
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_wsort_go_shift                          (20)
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_data_in_shift                           (0)
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_speed_en_mask                           (0x00200000)
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_wsort_go_mask                           (0x00100000)
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_data_in_mask                            (0x000FFFFF)
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_speed_en(data)                          (0x00200000&((data)<<21))
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_wsort_go(data)                          (0x00100000&((data)<<20))
#define  SYS_REG_SS_MAIN_RHVT_1_dss_main_data_in(data)                           (0x000FFFFF&(data))
#define  SYS_REG_SS_MAIN_RHVT_1_get_dss_main_speed_en(data)                      ((0x00200000&(data))>>21)
#define  SYS_REG_SS_MAIN_RHVT_1_get_dss_main_wsort_go(data)                      ((0x00100000&(data))>>20)
#define  SYS_REG_SS_MAIN_RHVT_1_get_dss_main_data_in(data)                       (0x000FFFFF&(data))

#define  SYS_REG_SS_MAIN_RHVT_2                                                  0x180002B8
#define  SYS_REG_SS_MAIN_RHVT_2_reg_addr                                         "0xB80002B8"
#define  SYS_REG_SS_MAIN_RHVT_2_reg                                              0xB80002B8
#define  SYS_REG_SS_MAIN_RHVT_2_inst_addr                                        "0x001A"
#define  set_SYS_REG_SS_MAIN_RHVT_2_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_MAIN_RHVT_2_reg)=data)
#define  get_SYS_REG_SS_MAIN_RHVT_2_reg                                          (*((volatile unsigned int*)SYS_REG_SS_MAIN_RHVT_2_reg))
#define  SYS_REG_SS_MAIN_RHVT_2_dss_main_dbgo_shift                              (0)
#define  SYS_REG_SS_MAIN_RHVT_2_dss_main_dbgo_mask                               (0x0000FFFF)
#define  SYS_REG_SS_MAIN_RHVT_2_dss_main_dbgo(data)                              (0x0000FFFF&(data))
#define  SYS_REG_SS_MAIN_RHVT_2_get_dss_main_dbgo(data)                          (0x0000FFFF&(data))

#define  SYS_REG_SS_VCPU_RHVT_0                                                  0x180002D0
#define  SYS_REG_SS_VCPU_RHVT_0_reg_addr                                         "0xB80002D0"
#define  SYS_REG_SS_VCPU_RHVT_0_reg                                              0xB80002D0
#define  SYS_REG_SS_VCPU_RHVT_0_inst_addr                                        "0x001B"
#define  set_SYS_REG_SS_VCPU_RHVT_0_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_VCPU_RHVT_0_reg)=data)
#define  get_SYS_REG_SS_VCPU_RHVT_0_reg                                          (*((volatile unsigned int*)SYS_REG_SS_VCPU_RHVT_0_reg))
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_dss_rst_n_shift                         (31)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_ro_sel_shift                            (25)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_wire_sel_shift                          (24)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_ready_shift                             (20)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_count_out_shift                         (0)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_dss_rst_n_mask                          (0x80000000)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_ro_sel_mask                             (0x0E000000)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_wire_sel_mask                           (0x01000000)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_ready_mask                              (0x00100000)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_count_out_mask                          (0x000FFFFF)
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_dss_rst_n(data)                         (0x80000000&((data)<<31))
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_ro_sel(data)                            (0x0E000000&((data)<<25))
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_wire_sel(data)                          (0x01000000&((data)<<24))
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_ready(data)                             (0x00100000&((data)<<20))
#define  SYS_REG_SS_VCPU_RHVT_0_dss_vcpu_count_out(data)                         (0x000FFFFF&(data))
#define  SYS_REG_SS_VCPU_RHVT_0_get_dss_vcpu_dss_rst_n(data)                     ((0x80000000&(data))>>31)
#define  SYS_REG_SS_VCPU_RHVT_0_get_dss_vcpu_ro_sel(data)                        ((0x0E000000&(data))>>25)
#define  SYS_REG_SS_VCPU_RHVT_0_get_dss_vcpu_wire_sel(data)                      ((0x01000000&(data))>>24)
#define  SYS_REG_SS_VCPU_RHVT_0_get_dss_vcpu_ready(data)                         ((0x00100000&(data))>>20)
#define  SYS_REG_SS_VCPU_RHVT_0_get_dss_vcpu_count_out(data)                     (0x000FFFFF&(data))

#define  SYS_REG_SS_VCPU_RHVT_1                                                  0x180002D4
#define  SYS_REG_SS_VCPU_RHVT_1_reg_addr                                         "0xB80002D4"
#define  SYS_REG_SS_VCPU_RHVT_1_reg                                              0xB80002D4
#define  SYS_REG_SS_VCPU_RHVT_1_inst_addr                                        "0x001C"
#define  set_SYS_REG_SS_VCPU_RHVT_1_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_VCPU_RHVT_1_reg)=data)
#define  get_SYS_REG_SS_VCPU_RHVT_1_reg                                          (*((volatile unsigned int*)SYS_REG_SS_VCPU_RHVT_1_reg))
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_speed_en_shift                          (21)
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_wsort_go_shift                          (20)
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_data_in_shift                           (0)
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_speed_en_mask                           (0x00200000)
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_wsort_go_mask                           (0x00100000)
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_data_in_mask                            (0x000FFFFF)
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_speed_en(data)                          (0x00200000&((data)<<21))
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_wsort_go(data)                          (0x00100000&((data)<<20))
#define  SYS_REG_SS_VCPU_RHVT_1_dss_vcpu_data_in(data)                           (0x000FFFFF&(data))
#define  SYS_REG_SS_VCPU_RHVT_1_get_dss_vcpu_speed_en(data)                      ((0x00200000&(data))>>21)
#define  SYS_REG_SS_VCPU_RHVT_1_get_dss_vcpu_wsort_go(data)                      ((0x00100000&(data))>>20)
#define  SYS_REG_SS_VCPU_RHVT_1_get_dss_vcpu_data_in(data)                       (0x000FFFFF&(data))

#define  SYS_REG_SS_VCPU_RHVT_2                                                  0x180002D8
#define  SYS_REG_SS_VCPU_RHVT_2_reg_addr                                         "0xB80002D8"
#define  SYS_REG_SS_VCPU_RHVT_2_reg                                              0xB80002D8
#define  SYS_REG_SS_VCPU_RHVT_2_inst_addr                                        "0x001D"
#define  set_SYS_REG_SS_VCPU_RHVT_2_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_VCPU_RHVT_2_reg)=data)
#define  get_SYS_REG_SS_VCPU_RHVT_2_reg                                          (*((volatile unsigned int*)SYS_REG_SS_VCPU_RHVT_2_reg))
#define  SYS_REG_SS_VCPU_RHVT_2_dss_vcpu_dbgo_shift                              (0)
#define  SYS_REG_SS_VCPU_RHVT_2_dss_vcpu_dbgo_mask                               (0x0000FFFF)
#define  SYS_REG_SS_VCPU_RHVT_2_dss_vcpu_dbgo(data)                              (0x0000FFFF&(data))
#define  SYS_REG_SS_VCPU_RHVT_2_get_dss_vcpu_dbgo(data)                          (0x0000FFFF&(data))

#define  SYS_REG_SS_ACPU_RHVT_0                                                  0x180002E0
#define  SYS_REG_SS_ACPU_RHVT_0_reg_addr                                         "0xB80002E0"
#define  SYS_REG_SS_ACPU_RHVT_0_reg                                              0xB80002E0
#define  SYS_REG_SS_ACPU_RHVT_0_inst_addr                                        "0x001E"
#define  set_SYS_REG_SS_ACPU_RHVT_0_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_ACPU_RHVT_0_reg)=data)
#define  get_SYS_REG_SS_ACPU_RHVT_0_reg                                          (*((volatile unsigned int*)SYS_REG_SS_ACPU_RHVT_0_reg))
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_dss_rst_n_shift                         (31)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_ro_sel_shift                            (25)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_wire_sel_shift                          (24)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_ready_shift                             (20)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_count_out_shift                         (0)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_dss_rst_n_mask                          (0x80000000)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_ro_sel_mask                             (0x0E000000)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_wire_sel_mask                           (0x01000000)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_ready_mask                              (0x00100000)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_count_out_mask                          (0x000FFFFF)
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_dss_rst_n(data)                         (0x80000000&((data)<<31))
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_ro_sel(data)                            (0x0E000000&((data)<<25))
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_wire_sel(data)                          (0x01000000&((data)<<24))
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_ready(data)                             (0x00100000&((data)<<20))
#define  SYS_REG_SS_ACPU_RHVT_0_dss_acpu_count_out(data)                         (0x000FFFFF&(data))
#define  SYS_REG_SS_ACPU_RHVT_0_get_dss_acpu_dss_rst_n(data)                     ((0x80000000&(data))>>31)
#define  SYS_REG_SS_ACPU_RHVT_0_get_dss_acpu_ro_sel(data)                        ((0x0E000000&(data))>>25)
#define  SYS_REG_SS_ACPU_RHVT_0_get_dss_acpu_wire_sel(data)                      ((0x01000000&(data))>>24)
#define  SYS_REG_SS_ACPU_RHVT_0_get_dss_acpu_ready(data)                         ((0x00100000&(data))>>20)
#define  SYS_REG_SS_ACPU_RHVT_0_get_dss_acpu_count_out(data)                     (0x000FFFFF&(data))

#define  SYS_REG_SS_ACPU_RHVT_1                                                  0x180002E4
#define  SYS_REG_SS_ACPU_RHVT_1_reg_addr                                         "0xB80002E4"
#define  SYS_REG_SS_ACPU_RHVT_1_reg                                              0xB80002E4
#define  SYS_REG_SS_ACPU_RHVT_1_inst_addr                                        "0x001F"
#define  set_SYS_REG_SS_ACPU_RHVT_1_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_ACPU_RHVT_1_reg)=data)
#define  get_SYS_REG_SS_ACPU_RHVT_1_reg                                          (*((volatile unsigned int*)SYS_REG_SS_ACPU_RHVT_1_reg))
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_speed_en_shift                          (21)
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_wsort_go_shift                          (20)
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_data_in_shift                           (0)
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_speed_en_mask                           (0x00200000)
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_wsort_go_mask                           (0x00100000)
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_data_in_mask                            (0x000FFFFF)
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_speed_en(data)                          (0x00200000&((data)<<21))
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_wsort_go(data)                          (0x00100000&((data)<<20))
#define  SYS_REG_SS_ACPU_RHVT_1_dss_acpu_data_in(data)                           (0x000FFFFF&(data))
#define  SYS_REG_SS_ACPU_RHVT_1_get_dss_acpu_speed_en(data)                      ((0x00200000&(data))>>21)
#define  SYS_REG_SS_ACPU_RHVT_1_get_dss_acpu_wsort_go(data)                      ((0x00100000&(data))>>20)
#define  SYS_REG_SS_ACPU_RHVT_1_get_dss_acpu_data_in(data)                       (0x000FFFFF&(data))

#define  SYS_REG_SS_ACPU_RHVT_2                                                  0x180002E8
#define  SYS_REG_SS_ACPU_RHVT_2_reg_addr                                         "0xB80002E8"
#define  SYS_REG_SS_ACPU_RHVT_2_reg                                              0xB80002E8
#define  SYS_REG_SS_ACPU_RHVT_2_inst_addr                                        "0x0020"
#define  set_SYS_REG_SS_ACPU_RHVT_2_reg(data)                                    (*((volatile unsigned int*)SYS_REG_SS_ACPU_RHVT_2_reg)=data)
#define  get_SYS_REG_SS_ACPU_RHVT_2_reg                                          (*((volatile unsigned int*)SYS_REG_SS_ACPU_RHVT_2_reg))
#define  SYS_REG_SS_ACPU_RHVT_2_dss_acpu_dbgo_shift                              (0)
#define  SYS_REG_SS_ACPU_RHVT_2_dss_acpu_dbgo_mask                               (0x0000FFFF)
#define  SYS_REG_SS_ACPU_RHVT_2_dss_acpu_dbgo(data)                              (0x0000FFFF&(data))
#define  SYS_REG_SS_ACPU_RHVT_2_get_dss_acpu_dbgo(data)                          (0x0000FFFF&(data))

#define  SYS_REG_SS_TVSB2_RHVT_0                                                 0x180002F0
#define  SYS_REG_SS_TVSB2_RHVT_0_reg_addr                                        "0xB80002F0"
#define  SYS_REG_SS_TVSB2_RHVT_0_reg                                             0xB80002F0
#define  SYS_REG_SS_TVSB2_RHVT_0_inst_addr                                       "0x0021"
#define  set_SYS_REG_SS_TVSB2_RHVT_0_reg(data)                                   (*((volatile unsigned int*)SYS_REG_SS_TVSB2_RHVT_0_reg)=data)
#define  get_SYS_REG_SS_TVSB2_RHVT_0_reg                                         (*((volatile unsigned int*)SYS_REG_SS_TVSB2_RHVT_0_reg))
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_dss_rst_n_shift                       (31)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_ro_sel_shift                          (25)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_wire_sel_shift                        (24)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_ready_shift                           (20)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_count_out_shift                       (0)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_dss_rst_n_mask                        (0x80000000)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_ro_sel_mask                           (0x0E000000)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_wire_sel_mask                         (0x01000000)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_ready_mask                            (0x00100000)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_count_out_mask                        (0x000FFFFF)
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_dss_rst_n(data)                       (0x80000000&((data)<<31))
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_ro_sel(data)                          (0x0E000000&((data)<<25))
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_wire_sel(data)                        (0x01000000&((data)<<24))
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_ready(data)                           (0x00100000&((data)<<20))
#define  SYS_REG_SS_TVSB2_RHVT_0_dss_tvsb2_count_out(data)                       (0x000FFFFF&(data))
#define  SYS_REG_SS_TVSB2_RHVT_0_get_dss_tvsb2_dss_rst_n(data)                   ((0x80000000&(data))>>31)
#define  SYS_REG_SS_TVSB2_RHVT_0_get_dss_tvsb2_ro_sel(data)                      ((0x0E000000&(data))>>25)
#define  SYS_REG_SS_TVSB2_RHVT_0_get_dss_tvsb2_wire_sel(data)                    ((0x01000000&(data))>>24)
#define  SYS_REG_SS_TVSB2_RHVT_0_get_dss_tvsb2_ready(data)                       ((0x00100000&(data))>>20)
#define  SYS_REG_SS_TVSB2_RHVT_0_get_dss_tvsb2_count_out(data)                   (0x000FFFFF&(data))

#define  SYS_REG_SS_TVSB2_RHVT_1                                                 0x180002F4
#define  SYS_REG_SS_TVSB2_RHVT_1_reg_addr                                        "0xB80002F4"
#define  SYS_REG_SS_TVSB2_RHVT_1_reg                                             0xB80002F4
#define  SYS_REG_SS_TVSB2_RHVT_1_inst_addr                                       "0x0022"
#define  set_SYS_REG_SS_TVSB2_RHVT_1_reg(data)                                   (*((volatile unsigned int*)SYS_REG_SS_TVSB2_RHVT_1_reg)=data)
#define  get_SYS_REG_SS_TVSB2_RHVT_1_reg                                         (*((volatile unsigned int*)SYS_REG_SS_TVSB2_RHVT_1_reg))
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_speed_en_shift                        (21)
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_wsort_go_shift                        (20)
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_data_in_shift                         (0)
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_speed_en_mask                         (0x00200000)
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_wsort_go_mask                         (0x00100000)
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_data_in_mask                          (0x000FFFFF)
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_speed_en(data)                        (0x00200000&((data)<<21))
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_wsort_go(data)                        (0x00100000&((data)<<20))
#define  SYS_REG_SS_TVSB2_RHVT_1_dss_tvsb2_data_in(data)                         (0x000FFFFF&(data))
#define  SYS_REG_SS_TVSB2_RHVT_1_get_dss_tvsb2_speed_en(data)                    ((0x00200000&(data))>>21)
#define  SYS_REG_SS_TVSB2_RHVT_1_get_dss_tvsb2_wsort_go(data)                    ((0x00100000&(data))>>20)
#define  SYS_REG_SS_TVSB2_RHVT_1_get_dss_tvsb2_data_in(data)                     (0x000FFFFF&(data))

#define  SYS_REG_SS_TVSB2_RHVT_2                                                 0x180002F8
#define  SYS_REG_SS_TVSB2_RHVT_2_reg_addr                                        "0xB80002F8"
#define  SYS_REG_SS_TVSB2_RHVT_2_reg                                             0xB80002F8
#define  SYS_REG_SS_TVSB2_RHVT_2_inst_addr                                       "0x0023"
#define  set_SYS_REG_SS_TVSB2_RHVT_2_reg(data)                                   (*((volatile unsigned int*)SYS_REG_SS_TVSB2_RHVT_2_reg)=data)
#define  get_SYS_REG_SS_TVSB2_RHVT_2_reg                                         (*((volatile unsigned int*)SYS_REG_SS_TVSB2_RHVT_2_reg))
#define  SYS_REG_SS_TVSB2_RHVT_2_dss_tvsb2_dbgo_shift                            (0)
#define  SYS_REG_SS_TVSB2_RHVT_2_dss_tvsb2_dbgo_mask                             (0x0000FFFF)
#define  SYS_REG_SS_TVSB2_RHVT_2_dss_tvsb2_dbgo(data)                            (0x0000FFFF&(data))
#define  SYS_REG_SS_TVSB2_RHVT_2_get_dss_tvsb2_dbgo(data)                        (0x0000FFFF&(data))

#define  SYS_REG_VOLTAGE_STROBE_CTRL                                             0x18000300
#define  SYS_REG_VOLTAGE_STROBE_CTRL_reg_addr                                    "0xB8000300"
#define  SYS_REG_VOLTAGE_STROBE_CTRL_reg                                         0xB8000300
#define  SYS_REG_VOLTAGE_STROBE_CTRL_inst_addr                                   "0x0024"
#define  set_SYS_REG_VOLTAGE_STROBE_CTRL_reg(data)                               (*((volatile unsigned int*)SYS_REG_VOLTAGE_STROBE_CTRL_reg)=data)
#define  get_SYS_REG_VOLTAGE_STROBE_CTRL_reg                                     (*((volatile unsigned int*)SYS_REG_VOLTAGE_STROBE_CTRL_reg))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_vcpu_voltage_strobe_en_shift                (8)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_main_voltage_strobe_en_shift                (4)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllemmc_voltage_strobe_en_shift             (3)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllscpu_voltage_strobe_en_shift             (2)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllbus_voltage_strobe_en_shift              (1)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_tvsb2_voltage_strobe_en_shift               (0)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_vcpu_voltage_strobe_en_mask                 (0x00000100)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_main_voltage_strobe_en_mask                 (0x00000010)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllemmc_voltage_strobe_en_mask              (0x00000008)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllscpu_voltage_strobe_en_mask              (0x00000004)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllbus_voltage_strobe_en_mask               (0x00000002)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_tvsb2_voltage_strobe_en_mask                (0x00000001)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_vcpu_voltage_strobe_en(data)                (0x00000100&((data)<<8))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_main_voltage_strobe_en(data)                (0x00000010&((data)<<4))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllemmc_voltage_strobe_en(data)             (0x00000008&((data)<<3))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllscpu_voltage_strobe_en(data)             (0x00000004&((data)<<2))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_pllbus_voltage_strobe_en(data)              (0x00000002&((data)<<1))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_tvsb2_voltage_strobe_en(data)               (0x00000001&(data))
#define  SYS_REG_VOLTAGE_STROBE_CTRL_get_vcpu_voltage_strobe_en(data)            ((0x00000100&(data))>>8)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_get_main_voltage_strobe_en(data)            ((0x00000010&(data))>>4)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_get_pllemmc_voltage_strobe_en(data)         ((0x00000008&(data))>>3)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_get_pllscpu_voltage_strobe_en(data)         ((0x00000004&(data))>>2)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_get_pllbus_voltage_strobe_en(data)          ((0x00000002&(data))>>1)
#define  SYS_REG_VOLTAGE_STROBE_CTRL_get_tvsb2_voltage_strobe_en(data)           (0x00000001&(data))

#define  SYS_REG_SC_DEBUG_0                                                      0x18000310
#define  SYS_REG_SC_DEBUG_0_reg_addr                                             "0xB8000310"
#define  SYS_REG_SC_DEBUG_0_reg                                                  0xB8000310
#define  SYS_REG_SC_DEBUG_0_inst_addr                                            "0x0025"
#define  set_SYS_REG_SC_DEBUG_0_reg(data)                                        (*((volatile unsigned int*)SYS_REG_SC_DEBUG_0_reg)=data)
#define  get_SYS_REG_SC_DEBUG_0_reg                                              (*((volatile unsigned int*)SYS_REG_SC_DEBUG_0_reg))
#define  SYS_REG_SC_DEBUG_0_pll_dbg_en_shift                                     (28)
#define  SYS_REG_SC_DEBUG_0_dbg0_div_sel_shift                                   (16)
#define  SYS_REG_SC_DEBUG_0_top_ssc_dbg_sel_shift                                (8)
#define  SYS_REG_SC_DEBUG_0_crt_dbg_sel_shift                                    (0)
#define  SYS_REG_SC_DEBUG_0_pll_dbg_en_mask                                      (0x10000000)
#define  SYS_REG_SC_DEBUG_0_dbg0_div_sel_mask                                    (0x00030000)
#define  SYS_REG_SC_DEBUG_0_top_ssc_dbg_sel_mask                                 (0x00000F00)
#define  SYS_REG_SC_DEBUG_0_crt_dbg_sel_mask                                     (0x000000FF)
#define  SYS_REG_SC_DEBUG_0_pll_dbg_en(data)                                     (0x10000000&((data)<<28))
#define  SYS_REG_SC_DEBUG_0_dbg0_div_sel(data)                                   (0x00030000&((data)<<16))
#define  SYS_REG_SC_DEBUG_0_top_ssc_dbg_sel(data)                                (0x00000F00&((data)<<8))
#define  SYS_REG_SC_DEBUG_0_crt_dbg_sel(data)                                    (0x000000FF&(data))
#define  SYS_REG_SC_DEBUG_0_get_pll_dbg_en(data)                                 ((0x10000000&(data))>>28)
#define  SYS_REG_SC_DEBUG_0_get_dbg0_div_sel(data)                               ((0x00030000&(data))>>16)
#define  SYS_REG_SC_DEBUG_0_get_top_ssc_dbg_sel(data)                            ((0x00000F00&(data))>>8)
#define  SYS_REG_SC_DEBUG_0_get_crt_dbg_sel(data)                                (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======SYS_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_diseqc:1;
        RBus_UInt32  rstn_cablerx:1;
        RBus_UInt32  rstn_hdmi_common:1;
        RBus_UInt32  rstn_hdmi_pre3:1;
        RBus_UInt32  rstn_hdmi_pre2:1;
        RBus_UInt32  rstn_hdmi_pre1:1;
        RBus_UInt32  rstn_hdmi_pre0:1;
        RBus_UInt32  rstn_img_demod:1;
        RBus_UInt32  rstn_img_demod_wrap:1;
        RBus_UInt32  rstn_hdic_apb:1;
        RBus_UInt32  rstn_hdic_axi:1;
        RBus_UInt32  rstn_hdic:1;
        RBus_UInt32  rstn_dtv_frontend:1;
        RBus_UInt32  rstn_kcpu:1;
        RBus_UInt32  rstn_vde2:1;
        RBus_UInt32  rstn_ve2_p2:1;
        RBus_UInt32  rstn_ve2:1;
        RBus_UInt32  rstn_vcpu2:1;
        RBus_UInt32  rstn_rtk_demod:1;
        RBus_UInt32  rstn_acpu:1;
        RBus_UInt32  rstn_acpu2:1;
        RBus_UInt32  rstn_ae2:1;
        RBus_UInt32  rstn_ve_lgcy_p2:1;
        RBus_UInt32  rstn_ve_lgcy:1;
        RBus_UInt32  rstn_scpu_wrap:1;
        RBus_UInt32  rstn_vde:1;
        RBus_UInt32  rstn_ve_p2:1;
        RBus_UInt32  rstn_ve:1;
        RBus_UInt32  rstn_vcpu:1;
        RBus_UInt32  rstn_ae:1;
        RBus_UInt32  rstn_scpu:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_srst0_RBUS;

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
        RBus_UInt32  rstn_dispd:1;
        RBus_UInt32  rstn_tp:1;
        RBus_UInt32  rstn_cp:1;
        RBus_UInt32  rstn_md:1;
        RBus_UInt32  rstn_se:1;
        RBus_UInt32  dummy18000104_4:1;
        RBus_UInt32  rstn_3d_gde:1;
        RBus_UInt32  rstn_vodma:1;
        RBus_UInt32  rstn_dispi:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  rstn_usb2_ex:1;
        RBus_UInt32  rstn_tm:1;
        RBus_UInt32  rstn_atvin2:1;
        RBus_UInt32  rstn_atvin:1;
        RBus_UInt32  rstn_dispm_cap:1;
        RBus_UInt32  rstn_dispm_disp:1;
        RBus_UInt32  rstn_emmc:1;
        RBus_UInt32  rstn_if_demod_logic:1;
        RBus_UInt32  rstn_bistreg:1;
        RBus_UInt32  rstn_i2c4:1;
        RBus_UInt32  rstn_pllreg:1;
        RBus_UInt32  rstn_usb3:1;
        RBus_UInt32  rstn_usb2:1;
        RBus_UInt32  rstn_pcmcia:1;
        RBus_UInt32  dummy18000108_15:1;
        RBus_UInt32  rstn_i2c3:1;
        RBus_UInt32  rstn_irtx:1;
        RBus_UInt32  dummy18000108_12:1;
        RBus_UInt32  rstn_dtv_demod:1;
        RBus_UInt32  rstn_misc:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_uart1:1;
        RBus_UInt32  rstn_uart2:1;
        RBus_UInt32  dummy18000108_6:1;
        RBus_UInt32  rstn_gpio:1;
        RBus_UInt32  rstn_i2c1:1;
        RBus_UInt32  rstn_i2c2:1;
        RBus_UInt32  rstn_nf:1;
        RBus_UInt32  rstn_sc:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_srst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rstn_memc:1;
        RBus_UInt32  rstn_memc_me:1;
        RBus_UInt32  rstn_memc_rbus:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rstn_dcphy2:1;
        RBus_UInt32  rstn_dcu2:1;
        RBus_UInt32  rstn_dcphy_mc:1;
        RBus_UInt32  rstn_disp_lg_hcic:1;
        RBus_UInt32  rstn_disp_lg_mplus:1;
        RBus_UInt32  rstn_d_boe_rgbw_pxl:1;
        RBus_UInt32  rstn_d_boe_rgbw_apb:1;
        RBus_UInt32  rstn_d_boe_rgbw_mcu:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_sd:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:4;
        RBus_UInt32  rstn_usb2_phy_p3:1;
        RBus_UInt32  rstn_usb2_phy_p2:1;
        RBus_UInt32  rstn_usb2_phy_p1:1;
        RBus_UInt32  rstn_usb2_phy_p0:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  rstn_usb3_phy_p0:1;
        RBus_UInt32  rstn_usb3_mdio_p0:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_srst3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_diseqc:1;
        RBus_UInt32  clken_cablerx:1;
        RBus_UInt32  clken_hdmi_common:1;
        RBus_UInt32  clken_hdmi_pre3:1;
        RBus_UInt32  clken_hdmi_pre2:1;
        RBus_UInt32  clken_hdmi_pre1:1;
        RBus_UInt32  clken_hdmi_pre0:1;
        RBus_UInt32  clken_img_demod:1;
        RBus_UInt32  clken_img_demod_wrap:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_hdic:1;
        RBus_UInt32  clken_dtv_frontend:1;
        RBus_UInt32  clken_kcpu:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_ve2_p2:1;
        RBus_UInt32  clken_ve2:1;
        RBus_UInt32  clken_vcpu2:1;
        RBus_UInt32  clken_rtk_demod:1;
        RBus_UInt32  clken_acpu:1;
        RBus_UInt32  clken_acpu2:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  clken_ve_lgcy_p2:1;
        RBus_UInt32  clken_ve_lgcy:1;
        RBus_UInt32  clken_ve_p2:1;
        RBus_UInt32  clken_ve:1;
        RBus_UInt32  clken_vcpu:1;
        RBus_UInt32  clken_scpu_wrap:1;
        RBus_UInt32  clken_scpu:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_clken0_RBUS;

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
        RBus_UInt32  clken_dolby_comp:1;
        RBus_UInt32  clken_dolby_dm:1;
        RBus_UInt32  clken_audio_pre512fs:1;
        RBus_UInt32  clken_audio:1;
        RBus_UInt32  clken_ifadc:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_offms:1;
        RBus_UInt32  clken_me:1;
        RBus_UInt32  clken_apll_adc:1;
        RBus_UInt32  clken_hdmi:1;
        RBus_UInt32  clken_dispd:1;
        RBus_UInt32  clken_tp:1;
        RBus_UInt32  clken_cp:1;
        RBus_UInt32  clken_md:1;
        RBus_UInt32  clken_se:1;
        RBus_UInt32  clken_tp_div:1;
        RBus_UInt32  clken_3d_gde:1;
        RBus_UInt32  clken_vodma:1;
        RBus_UInt32  clken_dispi:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  clken_usb2_ex:1;
        RBus_UInt32  clken_tm:1;
        RBus_UInt32  clken_atvin_vd:1;
        RBus_UInt32  clken_atvin_ifd:1;
        RBus_UInt32  clken_dispm_cap:1;
        RBus_UInt32  clken_dispm_disp:1;
        RBus_UInt32  clken_emmc:1;
        RBus_UInt32  clken_efuse:1;
        RBus_UInt32  clken_bistreg:1;
        RBus_UInt32  clken_i2c4:1;
        RBus_UInt32  clken_pllreg:1;
        RBus_UInt32  clken_usb3:1;
        RBus_UInt32  clken_usb2:1;
        RBus_UInt32  clken_pcmcia:1;
        RBus_UInt32  clken_audio2_512fs:1;
        RBus_UInt32  clken_i2c3:1;
        RBus_UInt32  clken_irtx:1;
        RBus_UInt32  dummy18000118_12:1;
        RBus_UInt32  clken_dtv_demod:1;
        RBus_UInt32  clken_misc:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_uart1:1;
        RBus_UInt32  clken_uart2:1;
        RBus_UInt32  dummy18000118_6:1;
        RBus_UInt32  clken_gpio:1;
        RBus_UInt32  clken_i2c1:1;
        RBus_UInt32  clken_i2c2:1;
        RBus_UInt32  clken_nf:1;
        RBus_UInt32  clken_sc:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_clken2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_memc:1;
        RBus_UInt32  clken_memc_me:1;
        RBus_UInt32  clken_memc_rbus:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  clken_dcphy_mc_mck:1;
        RBus_UInt32  clken_dcphy2:1;
        RBus_UInt32  clken_dcu2:1;
        RBus_UInt32  clken_dcphy_mc:1;
        RBus_UInt32  clken_disp_lg_hcic:1;
        RBus_UInt32  clken_disp_lg_mplus:1;
        RBus_UInt32  clken_d_boe_rgbw_pxl:1;
        RBus_UInt32  clken_d_boe_rgbw_apb:1;
        RBus_UInt32  clken_d_boe_rgbw_mcu:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_sd:1;
        RBus_UInt32  clken_dss:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  clken_audio_ad_128fs:1;
        RBus_UInt32  clken_audio_arc_dma_r_512fs:1;
        RBus_UInt32  clken_audio2_dma_r_512fs:1;
        RBus_UInt32  clken_audio_dma_r_512fs:1;
        RBus_UInt32  clken_audio_da1_256fs:1;
        RBus_UInt32  clken_audio_da1_128fs:1;
        RBus_UInt32  clken_audio_da0_256fs:1;
        RBus_UInt32  clken_audio_da0_128fs:1;
        RBus_UInt32  clken_audio_ad_256fs:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_sys_clken3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ejtag_demod_sel:1;
        RBus_UInt32  ejtag_demod_en:1;
        RBus_UInt32  ejtag_mode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ejtag_gpu_en:1;
        RBus_UInt32  ejtag_gpu_sel:1;
        RBus_UInt32  kcpu_clksel:1;
    };
}sys_reg_sys_cpusel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pll_bypass_ref_clk_mode:1;
        RBus_UInt32  mc_clk_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ve_sel:1;
        RBus_UInt32  sd_emmc_clk_sel:1;
        RBus_UInt32  pcr108_clksel:1;
        RBus_UInt32  dummy18000204_25:1;
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
        RBus_UInt32  inv_vbis0_sel:1;
        RBus_UInt32  uart_clksel:1;
    };
}sys_reg_sys_clksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dispd_osd_div:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  memc_me_div:2;
        RBus_UInt32  dclk_fract_b:6;
        RBus_UInt32  dclk_fract_a:5;
        RBus_UInt32  dispd_gdma_clk_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dispd_memc_out_sel:1;
        RBus_UInt32  dummy18000208_11:1;
        RBus_UInt32  dummy18000208_10:1;
        RBus_UInt32  clken_disp_lg_avcom:1;
        RBus_UInt32  dummy18000208_8:1;
        RBus_UInt32  dummy18000208_7:1;
        RBus_UInt32  clken_disp_memc_in:1;
        RBus_UInt32  clken_disp_memc_out:1;
        RBus_UInt32  clken_disp_sfg:1;
        RBus_UInt32  clken_disp_gdma:1;
        RBus_UInt32  clken_disp_stage1:1;
        RBus_UInt32  clken_disp_osd:1;
        RBus_UInt32  dummy18000208_0:1;
    };
}sys_reg_sys_dispclksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  clken_ext_ddr_en:1;
        RBus_UInt32  clken_ext_15_en:1;
        RBus_UInt32  clken_ext_14_en:1;
        RBus_UInt32  clken_ext_13_en:1;
        RBus_UInt32  clken_ext_12_en:1;
        RBus_UInt32  clken_ext_11_en:1;
        RBus_UInt32  clken_ext_10_en:1;
        RBus_UInt32  clken_ext_9_en:1;
        RBus_UInt32  clken_ext_8_en:1;
        RBus_UInt32  clken_ext_7_en:1;
        RBus_UInt32  clken_ext_6_en:1;
        RBus_UInt32  clken_ext_5_en:1;
        RBus_UInt32  clken_ext_4_en:1;
        RBus_UInt32  clken_ext_3_en:1;
        RBus_UInt32  clken_ext_2_en:1;
        RBus_UInt32  clken_ext_1_en:1;
        RBus_UInt32  clken_ext_0_en:1;
    };
}sys_reg_sys_extclk_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  i2c4_clksel:1;
        RBus_UInt32  i2c3_clksel:1;
        RBus_UInt32  dtv_demod_sel:1;
        RBus_UInt32  i2c2_clksel:1;
        RBus_UInt32  i2c1_clksel:1;
        RBus_UInt32  dtv_demod_atsc_en:1;
        RBus_UInt32  nf_clksel:3;
        RBus_UInt32  dummy18000214_7:1;
        RBus_UInt32  aud_dtv2_freq_sel:3;
        RBus_UInt32  dummy18000214_3:1;
        RBus_UInt32  aud_dtv_freq_sel:3;
    };
}sys_reg_sys_clkdiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  res4:12;
    };
}sys_reg_sys_arm_wd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800021c_31_29:3;
        RBus_UInt32  ib_rst_gck_memc:1;
        RBus_UInt32  ib_rst_gck_gpu:1;
        RBus_UInt32  ib_rst_gck_se2:1;
        RBus_UInt32  ib_rst_gck_ve2:1;
        RBus_UInt32  ib_rst_gck_ve:1;
        RBus_UInt32  ib_rst_gck_tvsb5:1;
        RBus_UInt32  ib_rst_gck_tvsb4:1;
        RBus_UInt32  ib_rst_gck_tvsb3:1;
        RBus_UInt32  ib_rst_gck_tvsb2:1;
        RBus_UInt32  ib_rst_gck_tvsb1:1;
        RBus_UInt32  ib_rst_gck_sb3:1;
        RBus_UInt32  ib_rst_gck_sb2:1;
        RBus_UInt32  ib_rst_gck_sb1:1;
        RBus_UInt32  dummy1800021c_15_13:3;
        RBus_UInt32  ib_clk_gck_memc:1;
        RBus_UInt32  ib_clk_gck_gpu:1;
        RBus_UInt32  ib_clk_gck_se2:1;
        RBus_UInt32  ib_clk_gck_ve2:1;
        RBus_UInt32  ib_clk_gck_ve:1;
        RBus_UInt32  ib_clk_gck_tvsb5:1;
        RBus_UInt32  ib_clk_gck_tvsb4:1;
        RBus_UInt32  ib_clk_gck_tvsb3:1;
        RBus_UInt32  ib_clk_gck_tvsb2:1;
        RBus_UInt32  ib_clk_gck_tvsb1:1;
        RBus_UInt32  ib_clk_gck_sb3:1;
        RBus_UInt32  ib_clk_gck_sb2:1;
        RBus_UInt32  ib_clk_gck_sb1:1;
    };
}sys_reg_sys_ib_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  clkratio_vcpu:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  clkratio_vcpu_active:1;
        RBus_UInt32  clkratio_acpu:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  clkratio_acpu_active:1;
        RBus_UInt32  clkratio_acpu2:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  clkratio_acpu2_active:1;
    };
}sys_reg_sys_dyn_sw_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  efuse_ready:1;
    };
}sys_reg_efuse_ctrl0_RBUS;

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
}sys_reg_power_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smartcard_int_scpu_routing_en:1;
        RBus_UInt32  dummy18000290_30:1;
        RBus_UInt32  ddc_int_scpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_scpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_scpu_routing_en:1;
        RBus_UInt32  standby_wdog_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_scpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cec_int_scpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_scpu_routing_en:1;
        RBus_UInt32  gpu_int_scpu_routing_en:1;
        RBus_UInt32  usb3_int_scpu_routing_en:1;
        RBus_UInt32  usb2_int_scpu_routing_en:1;
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
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  disp2tve_int_vcpu_routing_en:1;
        RBus_UInt32  vodma_int_vcpu_routing_en:1;
        RBus_UInt32  dummy18000294_28:1;
        RBus_UInt32  dc_int_vcpu2_routing_en:1;
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
        RBus_UInt32  me_int_vcpu_routing_en:1;
        RBus_UInt32  ddc_int_vcpu_routing_en:1;
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
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_vcpu_RBUS;

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
        RBus_UInt32  me_int_acpu_routing_en:1;
        RBus_UInt32  audio_dma_irq_acpu_routing_en:1;
        RBus_UInt32  audio_irq_acpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_acpu_routing_en:1;
        RBus_UInt32  dcphy_int_acpu_routing_en:1;
        RBus_UInt32  dc_int_acpu_routing_en:1;
        RBus_UInt32  dummy18000298_10:1;
        RBus_UInt32  dummy18000298_9:1;
        RBus_UInt32  dummy18000298_8:1;
        RBus_UInt32  audio_dma_irq_acpu2_routing_en:1;
        RBus_UInt32  audio_irq_acpu2_routing_en:1;
        RBus_UInt32  dummy18000298_5:1;
        RBus_UInt32  dummy18000298_4:1;
        RBus_UInt32  dc_int_acpu2_routing_en:1;
        RBus_UInt32  dummy18000298_2:1;
        RBus_UInt32  dummy18000298_1:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_acpu_RBUS;

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
        RBus_UInt32  gpu_int_kcpu_routing_en:1;
        RBus_UInt32  usb3_int_kcpu_routing_en:1;
        RBus_UInt32  usb2_int_kcpu_routing_en:1;
        RBus_UInt32  etn_int_kcpu_routing_en:1;
        RBus_UInt32  sd_int_kcpu_routing_en:1;
        RBus_UInt32  dummy1800029c_15:1;
        RBus_UInt32  ddc_int_kcpu_routing_en:1;
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
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_kcpu_RBUS;

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
        RBus_UInt32  res5:15;
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_memc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  usb2_ex_int_scpu_routing_en:1;
        RBus_UInt32  dc_security_int_scpu_routing_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tm_security_int_scpu_routing_en:1;
        RBus_UInt32  tp_security_int_scpu_routing_en:1;
        RBus_UInt32  nf_security_int_scpu_routing_en:1;
        RBus_UInt32  emmc_security_int_scpu_routing_en:1;
        RBus_UInt32  md_security_int_scpu_routing_en:1;
        RBus_UInt32  mcp_security_int_scpu_routing_en:1;
        RBus_UInt32  sb2_security_int_scpu_routing_en:1;
        RBus_UInt32  mis_security_int_scpu_routing_en:1;
        RBus_UInt32  se_security_int_scpu_routing_en:1;
        RBus_UInt32  dc2_security_int_scpu_routing_en:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_scpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  usb2_ex_int_kcpu_routing_en:1;
        RBus_UInt32  dc_security_int_kcpu_routing_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  tm_security_int_kcpu_routing_en:1;
        RBus_UInt32  tp_security_int_kcpu_routing_en:1;
        RBus_UInt32  nf_security_int_kcpu_routing_en:1;
        RBus_UInt32  emmc_security_int_kcpu_routing_en:1;
        RBus_UInt32  md_security_int_kcpu_routing_en:1;
        RBus_UInt32  mcp_security_int_kcpu_routing_en:1;
        RBus_UInt32  sb2_security_int_kcpu_routing_en:1;
        RBus_UInt32  mis_security_int_kcpu_routing_en:1;
        RBus_UInt32  se_security_int_kcpu_routing_en:1;
        RBus_UInt32  dc2_security_int_kcpu_routing_en:1;
        RBus_UInt32  write_data:1;
    };
}sys_reg_int_ctrl_kcpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_main_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_main_ro_sel:3;
        RBus_UInt32  dss_main_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_main_ready:1;
        RBus_UInt32  dss_main_count_out:20;
    };
}sys_reg_ss_main_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dss_main_speed_en:1;
        RBus_UInt32  dss_main_wsort_go:1;
        RBus_UInt32  dss_main_data_in:20;
    };
}sys_reg_ss_main_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dss_main_dbgo:16;
    };
}sys_reg_ss_main_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_vcpu_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_vcpu_ro_sel:3;
        RBus_UInt32  dss_vcpu_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_vcpu_ready:1;
        RBus_UInt32  dss_vcpu_count_out:20;
    };
}sys_reg_ss_vcpu_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dss_vcpu_speed_en:1;
        RBus_UInt32  dss_vcpu_wsort_go:1;
        RBus_UInt32  dss_vcpu_data_in:20;
    };
}sys_reg_ss_vcpu_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dss_vcpu_dbgo:16;
    };
}sys_reg_ss_vcpu_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_acpu_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_acpu_ro_sel:3;
        RBus_UInt32  dss_acpu_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_acpu_ready:1;
        RBus_UInt32  dss_acpu_count_out:20;
    };
}sys_reg_ss_acpu_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dss_acpu_speed_en:1;
        RBus_UInt32  dss_acpu_wsort_go:1;
        RBus_UInt32  dss_acpu_data_in:20;
    };
}sys_reg_ss_acpu_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dss_acpu_dbgo:16;
    };
}sys_reg_ss_acpu_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_tvsb2_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_tvsb2_ro_sel:3;
        RBus_UInt32  dss_tvsb2_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_tvsb2_ready:1;
        RBus_UInt32  dss_tvsb2_count_out:20;
    };
}sys_reg_ss_tvsb2_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dss_tvsb2_speed_en:1;
        RBus_UInt32  dss_tvsb2_wsort_go:1;
        RBus_UInt32  dss_tvsb2_data_in:20;
    };
}sys_reg_ss_tvsb2_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dss_tvsb2_dbgo:16;
    };
}sys_reg_ss_tvsb2_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  vcpu_voltage_strobe_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  main_voltage_strobe_en:1;
        RBus_UInt32  pllemmc_voltage_strobe_en:1;
        RBus_UInt32  pllscpu_voltage_strobe_en:1;
        RBus_UInt32  pllbus_voltage_strobe_en:1;
        RBus_UInt32  tvsb2_voltage_strobe_en:1;
    };
}sys_reg_voltage_strobe_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  pll_dbg_en:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  dbg0_div_sel:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  top_ssc_dbg_sel:4;
        RBus_UInt32  crt_dbg_sel:8;
    };
}sys_reg_sc_debug_0_RBUS;

#else //apply LITTLE_ENDIAN

//======SYS_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rstn_scpu:1;
        RBus_UInt32  rstn_ae:1;
        RBus_UInt32  rstn_vcpu:1;
        RBus_UInt32  rstn_ve:1;
        RBus_UInt32  rstn_ve_p2:1;
        RBus_UInt32  rstn_vde:1;
        RBus_UInt32  rstn_scpu_wrap:1;
        RBus_UInt32  rstn_ve_lgcy:1;
        RBus_UInt32  rstn_ve_lgcy_p2:1;
        RBus_UInt32  rstn_ae2:1;
        RBus_UInt32  rstn_acpu2:1;
        RBus_UInt32  rstn_acpu:1;
        RBus_UInt32  rstn_rtk_demod:1;
        RBus_UInt32  rstn_vcpu2:1;
        RBus_UInt32  rstn_ve2:1;
        RBus_UInt32  rstn_ve2_p2:1;
        RBus_UInt32  rstn_vde2:1;
        RBus_UInt32  rstn_kcpu:1;
        RBus_UInt32  rstn_dtv_frontend:1;
        RBus_UInt32  rstn_hdic:1;
        RBus_UInt32  rstn_hdic_axi:1;
        RBus_UInt32  rstn_hdic_apb:1;
        RBus_UInt32  rstn_img_demod_wrap:1;
        RBus_UInt32  rstn_img_demod:1;
        RBus_UInt32  rstn_hdmi_pre0:1;
        RBus_UInt32  rstn_hdmi_pre1:1;
        RBus_UInt32  rstn_hdmi_pre2:1;
        RBus_UInt32  rstn_hdmi_pre3:1;
        RBus_UInt32  rstn_hdmi_common:1;
        RBus_UInt32  rstn_cablerx:1;
        RBus_UInt32  rstn_diseqc:1;
    };
}sys_reg_sys_srst0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rstn_dispi:1;
        RBus_UInt32  rstn_vodma:1;
        RBus_UInt32  rstn_3d_gde:1;
        RBus_UInt32  dummy18000104_4:1;
        RBus_UInt32  rstn_se:1;
        RBus_UInt32  rstn_md:1;
        RBus_UInt32  rstn_cp:1;
        RBus_UInt32  rstn_tp:1;
        RBus_UInt32  rstn_dispd:1;
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
}sys_reg_sys_srst1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rstn_sc:1;
        RBus_UInt32  rstn_nf:1;
        RBus_UInt32  rstn_i2c2:1;
        RBus_UInt32  rstn_i2c1:1;
        RBus_UInt32  rstn_gpio:1;
        RBus_UInt32  dummy18000108_6:1;
        RBus_UInt32  rstn_uart2:1;
        RBus_UInt32  rstn_uart1:1;
        RBus_UInt32  rstn_pwm:1;
        RBus_UInt32  rstn_misc:1;
        RBus_UInt32  rstn_dtv_demod:1;
        RBus_UInt32  dummy18000108_12:1;
        RBus_UInt32  rstn_irtx:1;
        RBus_UInt32  rstn_i2c3:1;
        RBus_UInt32  dummy18000108_15:1;
        RBus_UInt32  rstn_pcmcia:1;
        RBus_UInt32  rstn_usb2:1;
        RBus_UInt32  rstn_usb3:1;
        RBus_UInt32  rstn_pllreg:1;
        RBus_UInt32  rstn_i2c4:1;
        RBus_UInt32  rstn_bistreg:1;
        RBus_UInt32  rstn_if_demod_logic:1;
        RBus_UInt32  rstn_emmc:1;
        RBus_UInt32  rstn_dispm_disp:1;
        RBus_UInt32  rstn_dispm_cap:1;
        RBus_UInt32  rstn_atvin:1;
        RBus_UInt32  rstn_atvin2:1;
        RBus_UInt32  rstn_tm:1;
        RBus_UInt32  rstn_usb2_ex:1;
        RBus_UInt32  res1:2;
    };
}sys_reg_sys_srst2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  rstn_usb3_mdio_p0:1;
        RBus_UInt32  rstn_usb3_phy_p0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rstn_usb2_phy_p0:1;
        RBus_UInt32  rstn_usb2_phy_p1:1;
        RBus_UInt32  rstn_usb2_phy_p2:1;
        RBus_UInt32  rstn_usb2_phy_p3:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  rstn_sd:1;
        RBus_UInt32  rstn_ddc:1;
        RBus_UInt32  rstn_d_boe_rgbw_mcu:1;
        RBus_UInt32  rstn_d_boe_rgbw_apb:1;
        RBus_UInt32  rstn_d_boe_rgbw_pxl:1;
        RBus_UInt32  rstn_disp_lg_mplus:1;
        RBus_UInt32  rstn_disp_lg_hcic:1;
        RBus_UInt32  rstn_dcphy_mc:1;
        RBus_UInt32  rstn_dcu2:1;
        RBus_UInt32  rstn_dcphy2:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  rstn_memc_rbus:1;
        RBus_UInt32  rstn_memc_me:1;
        RBus_UInt32  rstn_memc:1;
    };
}sys_reg_sys_srst3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  clken_scpu:1;
        RBus_UInt32  clken_scpu_wrap:1;
        RBus_UInt32  clken_vcpu:1;
        RBus_UInt32  clken_ve:1;
        RBus_UInt32  clken_ve_p2:1;
        RBus_UInt32  clken_ve_lgcy:1;
        RBus_UInt32  clken_ve_lgcy_p2:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  clken_acpu2:1;
        RBus_UInt32  clken_acpu:1;
        RBus_UInt32  clken_rtk_demod:1;
        RBus_UInt32  clken_vcpu2:1;
        RBus_UInt32  clken_ve2:1;
        RBus_UInt32  clken_ve2_p2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  clken_kcpu:1;
        RBus_UInt32  clken_dtv_frontend:1;
        RBus_UInt32  clken_hdic:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  clken_img_demod_wrap:1;
        RBus_UInt32  clken_img_demod:1;
        RBus_UInt32  clken_hdmi_pre0:1;
        RBus_UInt32  clken_hdmi_pre1:1;
        RBus_UInt32  clken_hdmi_pre2:1;
        RBus_UInt32  clken_hdmi_pre3:1;
        RBus_UInt32  clken_hdmi_common:1;
        RBus_UInt32  clken_cablerx:1;
        RBus_UInt32  clken_diseqc:1;
    };
}sys_reg_sys_clken0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  clken_dispi:1;
        RBus_UInt32  clken_vodma:1;
        RBus_UInt32  clken_3d_gde:1;
        RBus_UInt32  clken_tp_div:1;
        RBus_UInt32  clken_se:1;
        RBus_UInt32  clken_md:1;
        RBus_UInt32  clken_cp:1;
        RBus_UInt32  clken_tp:1;
        RBus_UInt32  clken_dispd:1;
        RBus_UInt32  clken_hdmi:1;
        RBus_UInt32  clken_apll_adc:1;
        RBus_UInt32  clken_me:1;
        RBus_UInt32  clken_offms:1;
        RBus_UInt32  clken_cbus:1;
        RBus_UInt32  clken_ifadc:1;
        RBus_UInt32  clken_audio:1;
        RBus_UInt32  clken_audio_pre512fs:1;
        RBus_UInt32  clken_dolby_dm:1;
        RBus_UInt32  clken_dolby_comp:1;
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
}sys_reg_sys_clken1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  clken_sc:1;
        RBus_UInt32  clken_nf:1;
        RBus_UInt32  clken_i2c2:1;
        RBus_UInt32  clken_i2c1:1;
        RBus_UInt32  clken_gpio:1;
        RBus_UInt32  dummy18000118_6:1;
        RBus_UInt32  clken_uart2:1;
        RBus_UInt32  clken_uart1:1;
        RBus_UInt32  clken_pwm:1;
        RBus_UInt32  clken_misc:1;
        RBus_UInt32  clken_dtv_demod:1;
        RBus_UInt32  dummy18000118_12:1;
        RBus_UInt32  clken_irtx:1;
        RBus_UInt32  clken_i2c3:1;
        RBus_UInt32  clken_audio2_512fs:1;
        RBus_UInt32  clken_pcmcia:1;
        RBus_UInt32  clken_usb2:1;
        RBus_UInt32  clken_usb3:1;
        RBus_UInt32  clken_pllreg:1;
        RBus_UInt32  clken_i2c4:1;
        RBus_UInt32  clken_bistreg:1;
        RBus_UInt32  clken_efuse:1;
        RBus_UInt32  clken_emmc:1;
        RBus_UInt32  clken_dispm_disp:1;
        RBus_UInt32  clken_dispm_cap:1;
        RBus_UInt32  clken_atvin_ifd:1;
        RBus_UInt32  clken_atvin_vd:1;
        RBus_UInt32  clken_tm:1;
        RBus_UInt32  clken_usb2_ex:1;
        RBus_UInt32  res1:2;
    };
}sys_reg_sys_clken2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  clken_audio_ad_256fs:1;
        RBus_UInt32  clken_audio_da0_128fs:1;
        RBus_UInt32  clken_audio_da0_256fs:1;
        RBus_UInt32  clken_audio_da1_128fs:1;
        RBus_UInt32  clken_audio_da1_256fs:1;
        RBus_UInt32  clken_audio_dma_r_512fs:1;
        RBus_UInt32  clken_audio2_dma_r_512fs:1;
        RBus_UInt32  clken_audio_arc_dma_r_512fs:1;
        RBus_UInt32  clken_audio_ad_128fs:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  clken_dss:1;
        RBus_UInt32  clken_sd:1;
        RBus_UInt32  clken_ddc:1;
        RBus_UInt32  clken_d_boe_rgbw_mcu:1;
        RBus_UInt32  clken_d_boe_rgbw_apb:1;
        RBus_UInt32  clken_d_boe_rgbw_pxl:1;
        RBus_UInt32  clken_disp_lg_mplus:1;
        RBus_UInt32  clken_disp_lg_hcic:1;
        RBus_UInt32  clken_dcphy_mc:1;
        RBus_UInt32  clken_dcu2:1;
        RBus_UInt32  clken_dcphy2:1;
        RBus_UInt32  clken_dcphy_mc_mck:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  clken_memc_rbus:1;
        RBus_UInt32  clken_memc_me:1;
        RBus_UInt32  clken_memc:1;
    };
}sys_reg_sys_clken3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_clksel:1;
        RBus_UInt32  ejtag_gpu_sel:1;
        RBus_UInt32  ejtag_gpu_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ejtag_mode:1;
        RBus_UInt32  ejtag_demod_en:1;
        RBus_UInt32  ejtag_demod_sel:1;
        RBus_UInt32  res2:25;
    };
}sys_reg_sys_cpusel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uart_clksel:1;
        RBus_UInt32  inv_vbis0_sel:1;
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
        RBus_UInt32  dummy18000204_25:1;
        RBus_UInt32  pcr108_clksel:1;
        RBus_UInt32  sd_emmc_clk_sel:1;
        RBus_UInt32  ve_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mc_clk_sel:1;
        RBus_UInt32  pll_bypass_ref_clk_mode:1;
    };
}sys_reg_sys_clksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18000208_0:1;
        RBus_UInt32  clken_disp_osd:1;
        RBus_UInt32  clken_disp_stage1:1;
        RBus_UInt32  clken_disp_gdma:1;
        RBus_UInt32  clken_disp_sfg:1;
        RBus_UInt32  clken_disp_memc_out:1;
        RBus_UInt32  clken_disp_memc_in:1;
        RBus_UInt32  dummy18000208_7:1;
        RBus_UInt32  dummy18000208_8:1;
        RBus_UInt32  clken_disp_lg_avcom:1;
        RBus_UInt32  dummy18000208_10:1;
        RBus_UInt32  dummy18000208_11:1;
        RBus_UInt32  dispd_memc_out_sel:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dispd_gdma_clk_sel:1;
        RBus_UInt32  dclk_fract_a:5;
        RBus_UInt32  dclk_fract_b:6;
        RBus_UInt32  memc_me_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dispd_osd_div:2;
    };
}sys_reg_sys_dispclksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clken_ext_0_en:1;
        RBus_UInt32  clken_ext_1_en:1;
        RBus_UInt32  clken_ext_2_en:1;
        RBus_UInt32  clken_ext_3_en:1;
        RBus_UInt32  clken_ext_4_en:1;
        RBus_UInt32  clken_ext_5_en:1;
        RBus_UInt32  clken_ext_6_en:1;
        RBus_UInt32  clken_ext_7_en:1;
        RBus_UInt32  clken_ext_8_en:1;
        RBus_UInt32  clken_ext_9_en:1;
        RBus_UInt32  clken_ext_10_en:1;
        RBus_UInt32  clken_ext_11_en:1;
        RBus_UInt32  clken_ext_12_en:1;
        RBus_UInt32  clken_ext_13_en:1;
        RBus_UInt32  clken_ext_14_en:1;
        RBus_UInt32  clken_ext_15_en:1;
        RBus_UInt32  clken_ext_ddr_en:1;
        RBus_UInt32  res1:15;
    };
}sys_reg_sys_extclk_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aud_dtv_freq_sel:3;
        RBus_UInt32  dummy18000214_3:1;
        RBus_UInt32  aud_dtv2_freq_sel:3;
        RBus_UInt32  dummy18000214_7:1;
        RBus_UInt32  nf_clksel:3;
        RBus_UInt32  dtv_demod_atsc_en:1;
        RBus_UInt32  i2c1_clksel:1;
        RBus_UInt32  i2c2_clksel:1;
        RBus_UInt32  dtv_demod_sel:1;
        RBus_UInt32  i2c3_clksel:1;
        RBus_UInt32  i2c4_clksel:1;
        RBus_UInt32  res1:15;
    };
}sys_reg_sys_clkdiv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:15;
    };
}sys_reg_sys_arm_wd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ib_clk_gck_sb1:1;
        RBus_UInt32  ib_clk_gck_sb2:1;
        RBus_UInt32  ib_clk_gck_sb3:1;
        RBus_UInt32  ib_clk_gck_tvsb1:1;
        RBus_UInt32  ib_clk_gck_tvsb2:1;
        RBus_UInt32  ib_clk_gck_tvsb3:1;
        RBus_UInt32  ib_clk_gck_tvsb4:1;
        RBus_UInt32  ib_clk_gck_tvsb5:1;
        RBus_UInt32  ib_clk_gck_ve:1;
        RBus_UInt32  ib_clk_gck_ve2:1;
        RBus_UInt32  ib_clk_gck_se2:1;
        RBus_UInt32  ib_clk_gck_gpu:1;
        RBus_UInt32  ib_clk_gck_memc:1;
        RBus_UInt32  dummy1800021c_15_13:3;
        RBus_UInt32  ib_rst_gck_sb1:1;
        RBus_UInt32  ib_rst_gck_sb2:1;
        RBus_UInt32  ib_rst_gck_sb3:1;
        RBus_UInt32  ib_rst_gck_tvsb1:1;
        RBus_UInt32  ib_rst_gck_tvsb2:1;
        RBus_UInt32  ib_rst_gck_tvsb3:1;
        RBus_UInt32  ib_rst_gck_tvsb4:1;
        RBus_UInt32  ib_rst_gck_tvsb5:1;
        RBus_UInt32  ib_rst_gck_ve:1;
        RBus_UInt32  ib_rst_gck_ve2:1;
        RBus_UInt32  ib_rst_gck_se2:1;
        RBus_UInt32  ib_rst_gck_gpu:1;
        RBus_UInt32  ib_rst_gck_memc:1;
        RBus_UInt32  dummy1800021c_31_29:3;
    };
}sys_reg_sys_ib_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clkratio_acpu2_active:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  clkratio_acpu2:5;
        RBus_UInt32  clkratio_acpu_active:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  clkratio_acpu:5;
        RBus_UInt32  clkratio_vcpu_active:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  clkratio_vcpu:5;
        RBus_UInt32  res4:8;
    };
}sys_reg_sys_dyn_sw_cpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  efuse_ready:1;
        RBus_UInt32  res1:31;
    };
}sys_reg_efuse_ctrl0_RBUS;

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
}sys_reg_power_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
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
        RBus_UInt32  usb2_int_scpu_routing_en:1;
        RBus_UInt32  usb3_int_scpu_routing_en:1;
        RBus_UInt32  gpu_int_scpu_routing_en:1;
        RBus_UInt32  standby_rtc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cec_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_int_scpu_routing_en:1;
        RBus_UInt32  standby_cbus_int_scpu_routing_en:1;
        RBus_UInt32  standby_iso_misc_off_int_scpu_routing_en:1;
        RBus_UInt32  standby_wdog_int_scpu_routing_en:1;
        RBus_UInt32  standby_hdmi_clk_det_int_scpu_routing_en:1;
        RBus_UInt32  standby_syncp_int_scpu_routing_en:1;
        RBus_UInt32  ddc_int_scpu_routing_en:1;
        RBus_UInt32  dummy18000290_30:1;
        RBus_UInt32  smartcard_int_scpu_routing_en:1;
    };
}sys_reg_int_ctrl_scpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
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
        RBus_UInt32  ddc_int_vcpu_routing_en:1;
        RBus_UInt32  me_int_vcpu_routing_en:1;
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
        RBus_UInt32  dc_int_vcpu2_routing_en:1;
        RBus_UInt32  dummy18000294_28:1;
        RBus_UInt32  vodma_int_vcpu_routing_en:1;
        RBus_UInt32  disp2tve_int_vcpu_routing_en:1;
        RBus_UInt32  res1:1;
    };
}sys_reg_int_ctrl_vcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  dummy18000298_1:1;
        RBus_UInt32  dummy18000298_2:1;
        RBus_UInt32  dc_int_acpu2_routing_en:1;
        RBus_UInt32  dummy18000298_4:1;
        RBus_UInt32  dummy18000298_5:1;
        RBus_UInt32  audio_irq_acpu2_routing_en:1;
        RBus_UInt32  audio_dma_irq_acpu2_routing_en:1;
        RBus_UInt32  dummy18000298_8:1;
        RBus_UInt32  dummy18000298_9:1;
        RBus_UInt32  dummy18000298_10:1;
        RBus_UInt32  dc_int_acpu_routing_en:1;
        RBus_UInt32  dcphy_int_acpu_routing_en:1;
        RBus_UInt32  tv_sb_dc_int_acpu_routing_en:1;
        RBus_UInt32  audio_irq_acpu_routing_en:1;
        RBus_UInt32  audio_dma_irq_acpu_routing_en:1;
        RBus_UInt32  me_int_acpu_routing_en:1;
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
    };
}sys_reg_int_ctrl_acpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
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
        RBus_UInt32  ddc_int_kcpu_routing_en:1;
        RBus_UInt32  dummy1800029c_15:1;
        RBus_UInt32  sd_int_kcpu_routing_en:1;
        RBus_UInt32  etn_int_kcpu_routing_en:1;
        RBus_UInt32  usb2_int_kcpu_routing_en:1;
        RBus_UInt32  usb3_int_kcpu_routing_en:1;
        RBus_UInt32  gpu_int_kcpu_routing_en:1;
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
}sys_reg_int_ctrl_kcpu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  hdmi_irq_scpu_routing_en:1;
        RBus_UInt32  hdmi_irq_vcpu_routing_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  memc_int_scpu_routing_en:1;
        RBus_UInt32  dummy180002a0_21:1;
        RBus_UInt32  dummy180002a0_22:1;
        RBus_UInt32  dummy180002a0_23:1;
        RBus_UInt32  memc_int_vcpu2_routing_en:1;
        RBus_UInt32  dummy180002a0_25:1;
        RBus_UInt32  dummy180002a0_26:1;
        RBus_UInt32  dummy180002a0_27:1;
        RBus_UInt32  memc_int_vcpu_routing_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
    };
}sys_reg_int_ctrl_memc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  dc2_security_int_scpu_routing_en:1;
        RBus_UInt32  se_security_int_scpu_routing_en:1;
        RBus_UInt32  mis_security_int_scpu_routing_en:1;
        RBus_UInt32  sb2_security_int_scpu_routing_en:1;
        RBus_UInt32  mcp_security_int_scpu_routing_en:1;
        RBus_UInt32  md_security_int_scpu_routing_en:1;
        RBus_UInt32  emmc_security_int_scpu_routing_en:1;
        RBus_UInt32  nf_security_int_scpu_routing_en:1;
        RBus_UInt32  tp_security_int_scpu_routing_en:1;
        RBus_UInt32  tm_security_int_scpu_routing_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dc_security_int_scpu_routing_en:1;
        RBus_UInt32  usb2_ex_int_scpu_routing_en:1;
        RBus_UInt32  res2:16;
    };
}sys_reg_int_ctrl_scpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  dc2_security_int_kcpu_routing_en:1;
        RBus_UInt32  se_security_int_kcpu_routing_en:1;
        RBus_UInt32  mis_security_int_kcpu_routing_en:1;
        RBus_UInt32  sb2_security_int_kcpu_routing_en:1;
        RBus_UInt32  mcp_security_int_kcpu_routing_en:1;
        RBus_UInt32  md_security_int_kcpu_routing_en:1;
        RBus_UInt32  emmc_security_int_kcpu_routing_en:1;
        RBus_UInt32  nf_security_int_kcpu_routing_en:1;
        RBus_UInt32  tp_security_int_kcpu_routing_en:1;
        RBus_UInt32  tm_security_int_kcpu_routing_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dc_security_int_kcpu_routing_en:1;
        RBus_UInt32  usb2_ex_int_kcpu_routing_en:1;
        RBus_UInt32  res2:16;
    };
}sys_reg_int_ctrl_kcpu_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_main_count_out:20;
        RBus_UInt32  dss_main_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_main_wire_sel:1;
        RBus_UInt32  dss_main_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_main_dss_rst_n:1;
    };
}sys_reg_ss_main_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_main_data_in:20;
        RBus_UInt32  dss_main_wsort_go:1;
        RBus_UInt32  dss_main_speed_en:1;
        RBus_UInt32  res1:10;
    };
}sys_reg_ss_main_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_main_dbgo:16;
        RBus_UInt32  res1:16;
    };
}sys_reg_ss_main_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_vcpu_count_out:20;
        RBus_UInt32  dss_vcpu_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_vcpu_wire_sel:1;
        RBus_UInt32  dss_vcpu_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_vcpu_dss_rst_n:1;
    };
}sys_reg_ss_vcpu_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_vcpu_data_in:20;
        RBus_UInt32  dss_vcpu_wsort_go:1;
        RBus_UInt32  dss_vcpu_speed_en:1;
        RBus_UInt32  res1:10;
    };
}sys_reg_ss_vcpu_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_vcpu_dbgo:16;
        RBus_UInt32  res1:16;
    };
}sys_reg_ss_vcpu_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_acpu_count_out:20;
        RBus_UInt32  dss_acpu_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_acpu_wire_sel:1;
        RBus_UInt32  dss_acpu_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_acpu_dss_rst_n:1;
    };
}sys_reg_ss_acpu_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_acpu_data_in:20;
        RBus_UInt32  dss_acpu_wsort_go:1;
        RBus_UInt32  dss_acpu_speed_en:1;
        RBus_UInt32  res1:10;
    };
}sys_reg_ss_acpu_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_acpu_dbgo:16;
        RBus_UInt32  res1:16;
    };
}sys_reg_ss_acpu_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_tvsb2_count_out:20;
        RBus_UInt32  dss_tvsb2_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dss_tvsb2_wire_sel:1;
        RBus_UInt32  dss_tvsb2_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dss_tvsb2_dss_rst_n:1;
    };
}sys_reg_ss_tvsb2_rhvt_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_tvsb2_data_in:20;
        RBus_UInt32  dss_tvsb2_wsort_go:1;
        RBus_UInt32  dss_tvsb2_speed_en:1;
        RBus_UInt32  res1:10;
    };
}sys_reg_ss_tvsb2_rhvt_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dss_tvsb2_dbgo:16;
        RBus_UInt32  res1:16;
    };
}sys_reg_ss_tvsb2_rhvt_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tvsb2_voltage_strobe_en:1;
        RBus_UInt32  pllbus_voltage_strobe_en:1;
        RBus_UInt32  pllscpu_voltage_strobe_en:1;
        RBus_UInt32  pllemmc_voltage_strobe_en:1;
        RBus_UInt32  main_voltage_strobe_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vcpu_voltage_strobe_en:1;
        RBus_UInt32  res2:23;
    };
}sys_reg_voltage_strobe_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crt_dbg_sel:8;
        RBus_UInt32  top_ssc_dbg_sel:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  dbg0_div_sel:2;
        RBus_UInt32  res2:10;
        RBus_UInt32  pll_dbg_en:1;
        RBus_UInt32  res3:3;
    };
}sys_reg_sc_debug_0_RBUS;




#endif 


#endif 
