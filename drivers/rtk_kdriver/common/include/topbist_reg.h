/**
* @file rbusTOPBISTReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TOPBIST_REG_H_
#define _RBUS_TOPBIST_REG_H_

#include "rbus_types.h"



//  TOPBIST Register Address
#define  TOPBIST_dispi_bisr_rstn                                                 0x18000F00
#define  TOPBIST_dispi_bisr_rstn_reg_addr                                        "0xB8000F00"
#define  TOPBIST_dispi_bisr_rstn_reg                                             0xB8000F00
#define  TOPBIST_dispi_bisr_rstn_inst_addr                                       "0x0000"
#define  set_TOPBIST_dispi_bisr_rstn_reg(data)                                   (*((volatile unsigned int*)TOPBIST_dispi_bisr_rstn_reg)=data)
#define  get_TOPBIST_dispi_bisr_rstn_reg                                         (*((volatile unsigned int*)TOPBIST_dispi_bisr_rstn_reg))
#define  TOPBIST_dispi_bisr_rstn_memc_bisr_rstn_1_shift                          (10)
#define  TOPBIST_dispi_bisr_rstn_memc_bisr_rstn_0_shift                          (1)
#define  TOPBIST_dispi_bisr_rstn_spnr_bisr_rstn_shift                            (0)
#define  TOPBIST_dispi_bisr_rstn_memc_bisr_rstn_1_mask                           (0x00000400)
#define  TOPBIST_dispi_bisr_rstn_memc_bisr_rstn_0_mask                           (0x000003FE)
#define  TOPBIST_dispi_bisr_rstn_spnr_bisr_rstn_mask                             (0x00000001)
#define  TOPBIST_dispi_bisr_rstn_memc_bisr_rstn_1(data)                          (0x00000400&((data)<<10))
#define  TOPBIST_dispi_bisr_rstn_memc_bisr_rstn_0(data)                          (0x000003FE&((data)<<1))
#define  TOPBIST_dispi_bisr_rstn_spnr_bisr_rstn(data)                            (0x00000001&(data))
#define  TOPBIST_dispi_bisr_rstn_get_memc_bisr_rstn_1(data)                      ((0x00000400&(data))>>10)
#define  TOPBIST_dispi_bisr_rstn_get_memc_bisr_rstn_0(data)                      ((0x000003FE&(data))>>1)
#define  TOPBIST_dispi_bisr_rstn_get_spnr_bisr_rstn(data)                        (0x00000001&(data))

#define  TOPBIST_dispd_bisr_rstn                                                 0x18000F04
#define  TOPBIST_dispd_bisr_rstn_reg_addr                                        "0xB8000F04"
#define  TOPBIST_dispd_bisr_rstn_reg                                             0xB8000F04
#define  TOPBIST_dispd_bisr_rstn_inst_addr                                       "0x0001"
#define  set_TOPBIST_dispd_bisr_rstn_reg(data)                                   (*((volatile unsigned int*)TOPBIST_dispd_bisr_rstn_reg)=data)
#define  get_TOPBIST_dispd_bisr_rstn_reg                                         (*((volatile unsigned int*)TOPBIST_dispd_bisr_rstn_reg))
#define  TOPBIST_dispd_bisr_rstn_sfg_bisr_rstn_shift                             (6)
#define  TOPBIST_dispd_bisr_rstn_sfg_osd_bisr_rstn_shift                         (5)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_003_bisr_rstn_shift                   (4)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_002_bisr_rstn_shift                   (3)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_001_bisr_rstn_shift                   (2)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_000_bisr_rstn_shift                   (1)
#define  TOPBIST_dispd_bisr_rstn_shpnr_bisr_rstn_shift                           (0)
#define  TOPBIST_dispd_bisr_rstn_sfg_bisr_rstn_mask                              (0x00000040)
#define  TOPBIST_dispd_bisr_rstn_sfg_osd_bisr_rstn_mask                          (0x00000020)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_003_bisr_rstn_mask                    (0x00000010)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_002_bisr_rstn_mask                    (0x00000008)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_001_bisr_rstn_mask                    (0x00000004)
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_000_bisr_rstn_mask                    (0x00000002)
#define  TOPBIST_dispd_bisr_rstn_shpnr_bisr_rstn_mask                            (0x00000001)
#define  TOPBIST_dispd_bisr_rstn_sfg_bisr_rstn(data)                             (0x00000040&((data)<<6))
#define  TOPBIST_dispd_bisr_rstn_sfg_osd_bisr_rstn(data)                         (0x00000020&((data)<<5))
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_003_bisr_rstn(data)                   (0x00000010&((data)<<4))
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_002_bisr_rstn(data)                   (0x00000008&((data)<<3))
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_001_bisr_rstn(data)                   (0x00000004&((data)<<2))
#define  TOPBIST_dispd_bisr_rstn_gdma_fbdc_000_bisr_rstn(data)                   (0x00000002&((data)<<1))
#define  TOPBIST_dispd_bisr_rstn_shpnr_bisr_rstn(data)                           (0x00000001&(data))
#define  TOPBIST_dispd_bisr_rstn_get_sfg_bisr_rstn(data)                         ((0x00000040&(data))>>6)
#define  TOPBIST_dispd_bisr_rstn_get_sfg_osd_bisr_rstn(data)                     ((0x00000020&(data))>>5)
#define  TOPBIST_dispd_bisr_rstn_get_gdma_fbdc_003_bisr_rstn(data)               ((0x00000010&(data))>>4)
#define  TOPBIST_dispd_bisr_rstn_get_gdma_fbdc_002_bisr_rstn(data)               ((0x00000008&(data))>>3)
#define  TOPBIST_dispd_bisr_rstn_get_gdma_fbdc_001_bisr_rstn(data)               ((0x00000004&(data))>>2)
#define  TOPBIST_dispd_bisr_rstn_get_gdma_fbdc_000_bisr_rstn(data)               ((0x00000002&(data))>>1)
#define  TOPBIST_dispd_bisr_rstn_get_shpnr_bisr_rstn(data)                       (0x00000001&(data))

#define  TOPBIST_dtv_bisr_rstn                                                   0x18000F08
#define  TOPBIST_dtv_bisr_rstn_reg_addr                                          "0xB8000F08"
#define  TOPBIST_dtv_bisr_rstn_reg                                               0xB8000F08
#define  TOPBIST_dtv_bisr_rstn_inst_addr                                         "0x0002"
#define  set_TOPBIST_dtv_bisr_rstn_reg(data)                                     (*((volatile unsigned int*)TOPBIST_dtv_bisr_rstn_reg)=data)
#define  get_TOPBIST_dtv_bisr_rstn_reg                                           (*((volatile unsigned int*)TOPBIST_dtv_bisr_rstn_reg))
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_5_rstn_shift                       (5)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_4_rstn_shift                       (4)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_3_rstn_shift                       (3)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_2_rstn_shift                       (2)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_1_rstn_shift                       (1)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_0_rstn_shift                       (0)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_5_rstn_mask                        (0x00000020)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_4_rstn_mask                        (0x00000010)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_3_rstn_mask                        (0x00000008)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_2_rstn_mask                        (0x00000004)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_1_rstn_mask                        (0x00000002)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_0_rstn_mask                        (0x00000001)
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_5_rstn(data)                       (0x00000020&((data)<<5))
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_4_rstn(data)                       (0x00000010&((data)<<4))
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_3_rstn(data)                       (0x00000008&((data)<<3))
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_2_rstn(data)                       (0x00000004&((data)<<2))
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_1_rstn(data)                       (0x00000002&((data)<<1))
#define  TOPBIST_dtv_bisr_rstn_img_demod_bisr_0_rstn(data)                       (0x00000001&(data))
#define  TOPBIST_dtv_bisr_rstn_get_img_demod_bisr_5_rstn(data)                   ((0x00000020&(data))>>5)
#define  TOPBIST_dtv_bisr_rstn_get_img_demod_bisr_4_rstn(data)                   ((0x00000010&(data))>>4)
#define  TOPBIST_dtv_bisr_rstn_get_img_demod_bisr_3_rstn(data)                   ((0x00000008&(data))>>3)
#define  TOPBIST_dtv_bisr_rstn_get_img_demod_bisr_2_rstn(data)                   ((0x00000004&(data))>>2)
#define  TOPBIST_dtv_bisr_rstn_get_img_demod_bisr_1_rstn(data)                   ((0x00000002&(data))>>1)
#define  TOPBIST_dtv_bisr_rstn_get_img_demod_bisr_0_rstn(data)                   (0x00000001&(data))

#define  TOPBIST_cpu_bisr_rstn                                                   0x18000F0C
#define  TOPBIST_cpu_bisr_rstn_reg_addr                                          "0xB8000F0C"
#define  TOPBIST_cpu_bisr_rstn_reg                                               0xB8000F0C
#define  TOPBIST_cpu_bisr_rstn_inst_addr                                         "0x0003"
#define  set_TOPBIST_cpu_bisr_rstn_reg(data)                                     (*((volatile unsigned int*)TOPBIST_cpu_bisr_rstn_reg)=data)
#define  get_TOPBIST_cpu_bisr_rstn_reg                                           (*((volatile unsigned int*)TOPBIST_cpu_bisr_rstn_reg))
#define  TOPBIST_cpu_bisr_rstn_dummy_10_shift                                    (10)
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_3_rstn_shift                           (9)
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_2_rstn_shift                           (8)
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_1_rstn_shift                           (7)
#define  TOPBIST_cpu_bisr_rstn_vcpu2_bisr_rstn_shift                             (6)
#define  TOPBIST_cpu_bisr_rstn_a53_bisr_rstn_shift                               (5)
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_3_rstn_shift                            (4)
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_2_rstn_shift                            (3)
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_1_rstn_shift                            (2)
#define  TOPBIST_cpu_bisr_rstn_vcpu_bisr_rstn_shift                              (1)
#define  TOPBIST_cpu_bisr_rstn_dummy_10_mask                                     (0x00000400)
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_3_rstn_mask                            (0x00000200)
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_2_rstn_mask                            (0x00000100)
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_1_rstn_mask                            (0x00000080)
#define  TOPBIST_cpu_bisr_rstn_vcpu2_bisr_rstn_mask                              (0x00000040)
#define  TOPBIST_cpu_bisr_rstn_a53_bisr_rstn_mask                                (0x00000020)
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_3_rstn_mask                             (0x00000010)
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_2_rstn_mask                             (0x00000008)
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_1_rstn_mask                             (0x00000004)
#define  TOPBIST_cpu_bisr_rstn_vcpu_bisr_rstn_mask                               (0x00000002)
#define  TOPBIST_cpu_bisr_rstn_dummy_10(data)                                    (0x00000400&((data)<<10))
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_3_rstn(data)                           (0x00000200&((data)<<9))
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_2_rstn(data)                           (0x00000100&((data)<<8))
#define  TOPBIST_cpu_bisr_rstn_acpu2_bisr_1_rstn(data)                           (0x00000080&((data)<<7))
#define  TOPBIST_cpu_bisr_rstn_vcpu2_bisr_rstn(data)                             (0x00000040&((data)<<6))
#define  TOPBIST_cpu_bisr_rstn_a53_bisr_rstn(data)                               (0x00000020&((data)<<5))
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_3_rstn(data)                            (0x00000010&((data)<<4))
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_2_rstn(data)                            (0x00000008&((data)<<3))
#define  TOPBIST_cpu_bisr_rstn_acpu_bisr_1_rstn(data)                            (0x00000004&((data)<<2))
#define  TOPBIST_cpu_bisr_rstn_vcpu_bisr_rstn(data)                              (0x00000002&((data)<<1))
#define  TOPBIST_cpu_bisr_rstn_get_dummy_10(data)                                ((0x00000400&(data))>>10)
#define  TOPBIST_cpu_bisr_rstn_get_acpu2_bisr_3_rstn(data)                       ((0x00000200&(data))>>9)
#define  TOPBIST_cpu_bisr_rstn_get_acpu2_bisr_2_rstn(data)                       ((0x00000100&(data))>>8)
#define  TOPBIST_cpu_bisr_rstn_get_acpu2_bisr_1_rstn(data)                       ((0x00000080&(data))>>7)
#define  TOPBIST_cpu_bisr_rstn_get_vcpu2_bisr_rstn(data)                         ((0x00000040&(data))>>6)
#define  TOPBIST_cpu_bisr_rstn_get_a53_bisr_rstn(data)                           ((0x00000020&(data))>>5)
#define  TOPBIST_cpu_bisr_rstn_get_acpu_bisr_3_rstn(data)                        ((0x00000010&(data))>>4)
#define  TOPBIST_cpu_bisr_rstn_get_acpu_bisr_2_rstn(data)                        ((0x00000008&(data))>>3)
#define  TOPBIST_cpu_bisr_rstn_get_acpu_bisr_1_rstn(data)                        ((0x00000004&(data))>>2)
#define  TOPBIST_cpu_bisr_rstn_get_vcpu_bisr_rstn(data)                          ((0x00000002&(data))>>1)

#define  TOPBIST_dispi_bisr_remap                                                0x18000F10
#define  TOPBIST_dispi_bisr_remap_reg_addr                                       "0xB8000F10"
#define  TOPBIST_dispi_bisr_remap_reg                                            0xB8000F10
#define  TOPBIST_dispi_bisr_remap_inst_addr                                      "0x0004"
#define  set_TOPBIST_dispi_bisr_remap_reg(data)                                  (*((volatile unsigned int*)TOPBIST_dispi_bisr_remap_reg)=data)
#define  get_TOPBIST_dispi_bisr_remap_reg                                        (*((volatile unsigned int*)TOPBIST_dispi_bisr_remap_reg))
#define  TOPBIST_dispi_bisr_remap_memc_bisr_remap_1_shift                        (10)
#define  TOPBIST_dispi_bisr_remap_memc_bisr_remap_0_shift                        (1)
#define  TOPBIST_dispi_bisr_remap_spnr_bisr_remap_shift                          (0)
#define  TOPBIST_dispi_bisr_remap_memc_bisr_remap_1_mask                         (0x00000400)
#define  TOPBIST_dispi_bisr_remap_memc_bisr_remap_0_mask                         (0x000003FE)
#define  TOPBIST_dispi_bisr_remap_spnr_bisr_remap_mask                           (0x00000001)
#define  TOPBIST_dispi_bisr_remap_memc_bisr_remap_1(data)                        (0x00000400&((data)<<10))
#define  TOPBIST_dispi_bisr_remap_memc_bisr_remap_0(data)                        (0x000003FE&((data)<<1))
#define  TOPBIST_dispi_bisr_remap_spnr_bisr_remap(data)                          (0x00000001&(data))
#define  TOPBIST_dispi_bisr_remap_get_memc_bisr_remap_1(data)                    ((0x00000400&(data))>>10)
#define  TOPBIST_dispi_bisr_remap_get_memc_bisr_remap_0(data)                    ((0x000003FE&(data))>>1)
#define  TOPBIST_dispi_bisr_remap_get_spnr_bisr_remap(data)                      (0x00000001&(data))

#define  TOPBIST_dispd_bisr_remap                                                0x18000F14
#define  TOPBIST_dispd_bisr_remap_reg_addr                                       "0xB8000F14"
#define  TOPBIST_dispd_bisr_remap_reg                                            0xB8000F14
#define  TOPBIST_dispd_bisr_remap_inst_addr                                      "0x0005"
#define  set_TOPBIST_dispd_bisr_remap_reg(data)                                  (*((volatile unsigned int*)TOPBIST_dispd_bisr_remap_reg)=data)
#define  get_TOPBIST_dispd_bisr_remap_reg                                        (*((volatile unsigned int*)TOPBIST_dispd_bisr_remap_reg))
#define  TOPBIST_dispd_bisr_remap_sfg_bisr_remap_shift                           (6)
#define  TOPBIST_dispd_bisr_remap_sfg_osd_bisr_remap_shift                       (5)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_003_remap_shift                      (4)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_002_remap_shift                      (3)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_001_remap_shift                      (2)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_000_remap_shift                      (1)
#define  TOPBIST_dispd_bisr_remap_shpnr_bisr_remap_shift                         (0)
#define  TOPBIST_dispd_bisr_remap_sfg_bisr_remap_mask                            (0x00000040)
#define  TOPBIST_dispd_bisr_remap_sfg_osd_bisr_remap_mask                        (0x00000020)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_003_remap_mask                       (0x00000010)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_002_remap_mask                       (0x00000008)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_001_remap_mask                       (0x00000004)
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_000_remap_mask                       (0x00000002)
#define  TOPBIST_dispd_bisr_remap_shpnr_bisr_remap_mask                          (0x00000001)
#define  TOPBIST_dispd_bisr_remap_sfg_bisr_remap(data)                           (0x00000040&((data)<<6))
#define  TOPBIST_dispd_bisr_remap_sfg_osd_bisr_remap(data)                       (0x00000020&((data)<<5))
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_003_remap(data)                      (0x00000010&((data)<<4))
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_002_remap(data)                      (0x00000008&((data)<<3))
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_001_remap(data)                      (0x00000004&((data)<<2))
#define  TOPBIST_dispd_bisr_remap_gdma_fbdc_000_remap(data)                      (0x00000002&((data)<<1))
#define  TOPBIST_dispd_bisr_remap_shpnr_bisr_remap(data)                         (0x00000001&(data))
#define  TOPBIST_dispd_bisr_remap_get_sfg_bisr_remap(data)                       ((0x00000040&(data))>>6)
#define  TOPBIST_dispd_bisr_remap_get_sfg_osd_bisr_remap(data)                   ((0x00000020&(data))>>5)
#define  TOPBIST_dispd_bisr_remap_get_gdma_fbdc_003_remap(data)                  ((0x00000010&(data))>>4)
#define  TOPBIST_dispd_bisr_remap_get_gdma_fbdc_002_remap(data)                  ((0x00000008&(data))>>3)
#define  TOPBIST_dispd_bisr_remap_get_gdma_fbdc_001_remap(data)                  ((0x00000004&(data))>>2)
#define  TOPBIST_dispd_bisr_remap_get_gdma_fbdc_000_remap(data)                  ((0x00000002&(data))>>1)
#define  TOPBIST_dispd_bisr_remap_get_shpnr_bisr_remap(data)                     (0x00000001&(data))

#define  TOPBIST_vp9_bisr_remap                                                  0x18000F18
#define  TOPBIST_vp9_bisr_remap_reg_addr                                         "0xB8000F18"
#define  TOPBIST_vp9_bisr_remap_reg                                              0xB8000F18
#define  TOPBIST_vp9_bisr_remap_inst_addr                                        "0x0006"
#define  set_TOPBIST_vp9_bisr_remap_reg(data)                                    (*((volatile unsigned int*)TOPBIST_vp9_bisr_remap_reg)=data)
#define  get_TOPBIST_vp9_bisr_remap_reg                                          (*((volatile unsigned int*)TOPBIST_vp9_bisr_remap_reg))
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_5_remap_shift                     (5)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_4_remap_shift                     (4)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_3_remap_shift                     (3)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_2_remap_shift                     (2)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_1_remap_shift                     (1)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_0_remap_shift                     (0)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_5_remap_mask                      (0x00000020)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_4_remap_mask                      (0x00000010)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_3_remap_mask                      (0x00000008)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_2_remap_mask                      (0x00000004)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_1_remap_mask                      (0x00000002)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_0_remap_mask                      (0x00000001)
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_5_remap(data)                     (0x00000020&((data)<<5))
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_4_remap(data)                     (0x00000010&((data)<<4))
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_3_remap(data)                     (0x00000008&((data)<<3))
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_2_remap(data)                     (0x00000004&((data)<<2))
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_1_remap(data)                     (0x00000002&((data)<<1))
#define  TOPBIST_vp9_bisr_remap_img_demod_bisr_0_remap(data)                     (0x00000001&(data))
#define  TOPBIST_vp9_bisr_remap_get_img_demod_bisr_5_remap(data)                 ((0x00000020&(data))>>5)
#define  TOPBIST_vp9_bisr_remap_get_img_demod_bisr_4_remap(data)                 ((0x00000010&(data))>>4)
#define  TOPBIST_vp9_bisr_remap_get_img_demod_bisr_3_remap(data)                 ((0x00000008&(data))>>3)
#define  TOPBIST_vp9_bisr_remap_get_img_demod_bisr_2_remap(data)                 ((0x00000004&(data))>>2)
#define  TOPBIST_vp9_bisr_remap_get_img_demod_bisr_1_remap(data)                 ((0x00000002&(data))>>1)
#define  TOPBIST_vp9_bisr_remap_get_img_demod_bisr_0_remap(data)                 (0x00000001&(data))

#define  TOPBIST_cpu_bisr_remap                                                  0x18000F1C
#define  TOPBIST_cpu_bisr_remap_reg_addr                                         "0xB8000F1C"
#define  TOPBIST_cpu_bisr_remap_reg                                              0xB8000F1C
#define  TOPBIST_cpu_bisr_remap_inst_addr                                        "0x0007"
#define  set_TOPBIST_cpu_bisr_remap_reg(data)                                    (*((volatile unsigned int*)TOPBIST_cpu_bisr_remap_reg)=data)
#define  get_TOPBIST_cpu_bisr_remap_reg                                          (*((volatile unsigned int*)TOPBIST_cpu_bisr_remap_reg))
#define  TOPBIST_cpu_bisr_remap_dummy_10_shift                                   (10)
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_3_remap_shift                         (9)
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_2_remap_shift                         (8)
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_1_remap_shift                         (7)
#define  TOPBIST_cpu_bisr_remap_vcpu2_bisr_remap_shift                           (6)
#define  TOPBIST_cpu_bisr_remap_a53_bisr_remap_shift                             (5)
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_3_remap_shift                          (4)
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_2_remap_shift                          (3)
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_1_remap_shift                          (2)
#define  TOPBIST_cpu_bisr_remap_vcpu_bisr_remap_shift                            (1)
#define  TOPBIST_cpu_bisr_remap_dummy_10_mask                                    (0x00000400)
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_3_remap_mask                          (0x00000200)
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_2_remap_mask                          (0x00000100)
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_1_remap_mask                          (0x00000080)
#define  TOPBIST_cpu_bisr_remap_vcpu2_bisr_remap_mask                            (0x00000040)
#define  TOPBIST_cpu_bisr_remap_a53_bisr_remap_mask                              (0x00000020)
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_3_remap_mask                           (0x00000010)
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_2_remap_mask                           (0x00000008)
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_1_remap_mask                           (0x00000004)
#define  TOPBIST_cpu_bisr_remap_vcpu_bisr_remap_mask                             (0x00000002)
#define  TOPBIST_cpu_bisr_remap_dummy_10(data)                                   (0x00000400&((data)<<10))
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_3_remap(data)                         (0x00000200&((data)<<9))
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_2_remap(data)                         (0x00000100&((data)<<8))
#define  TOPBIST_cpu_bisr_remap_acpu2_bisr_1_remap(data)                         (0x00000080&((data)<<7))
#define  TOPBIST_cpu_bisr_remap_vcpu2_bisr_remap(data)                           (0x00000040&((data)<<6))
#define  TOPBIST_cpu_bisr_remap_a53_bisr_remap(data)                             (0x00000020&((data)<<5))
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_3_remap(data)                          (0x00000010&((data)<<4))
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_2_remap(data)                          (0x00000008&((data)<<3))
#define  TOPBIST_cpu_bisr_remap_acpu_bisr_1_remap(data)                          (0x00000004&((data)<<2))
#define  TOPBIST_cpu_bisr_remap_vcpu_bisr_remap(data)                            (0x00000002&((data)<<1))
#define  TOPBIST_cpu_bisr_remap_get_dummy_10(data)                               ((0x00000400&(data))>>10)
#define  TOPBIST_cpu_bisr_remap_get_acpu2_bisr_3_remap(data)                     ((0x00000200&(data))>>9)
#define  TOPBIST_cpu_bisr_remap_get_acpu2_bisr_2_remap(data)                     ((0x00000100&(data))>>8)
#define  TOPBIST_cpu_bisr_remap_get_acpu2_bisr_1_remap(data)                     ((0x00000080&(data))>>7)
#define  TOPBIST_cpu_bisr_remap_get_vcpu2_bisr_remap(data)                       ((0x00000040&(data))>>6)
#define  TOPBIST_cpu_bisr_remap_get_a53_bisr_remap(data)                         ((0x00000020&(data))>>5)
#define  TOPBIST_cpu_bisr_remap_get_acpu_bisr_3_remap(data)                      ((0x00000010&(data))>>4)
#define  TOPBIST_cpu_bisr_remap_get_acpu_bisr_2_remap(data)                      ((0x00000008&(data))>>3)
#define  TOPBIST_cpu_bisr_remap_get_acpu_bisr_1_remap(data)                      ((0x00000004&(data))>>2)
#define  TOPBIST_cpu_bisr_remap_get_vcpu_bisr_remap(data)                        ((0x00000002&(data))>>1)

#define  TOPBIST_dispi_bisr_done                                                 0x18000F20
#define  TOPBIST_dispi_bisr_done_reg_addr                                        "0xB8000F20"
#define  TOPBIST_dispi_bisr_done_reg                                             0xB8000F20
#define  TOPBIST_dispi_bisr_done_inst_addr                                       "0x0008"
#define  set_TOPBIST_dispi_bisr_done_reg(data)                                   (*((volatile unsigned int*)TOPBIST_dispi_bisr_done_reg)=data)
#define  get_TOPBIST_dispi_bisr_done_reg                                         (*((volatile unsigned int*)TOPBIST_dispi_bisr_done_reg))
#define  TOPBIST_dispi_bisr_done_memc_bisr_done_1_shift                          (10)
#define  TOPBIST_dispi_bisr_done_memc_bisr_done_0_shift                          (1)
#define  TOPBIST_dispi_bisr_done_spnr_bisr_done_shift                            (0)
#define  TOPBIST_dispi_bisr_done_memc_bisr_done_1_mask                           (0x00000400)
#define  TOPBIST_dispi_bisr_done_memc_bisr_done_0_mask                           (0x000003FE)
#define  TOPBIST_dispi_bisr_done_spnr_bisr_done_mask                             (0x00000001)
#define  TOPBIST_dispi_bisr_done_memc_bisr_done_1(data)                          (0x00000400&((data)<<10))
#define  TOPBIST_dispi_bisr_done_memc_bisr_done_0(data)                          (0x000003FE&((data)<<1))
#define  TOPBIST_dispi_bisr_done_spnr_bisr_done(data)                            (0x00000001&(data))
#define  TOPBIST_dispi_bisr_done_get_memc_bisr_done_1(data)                      ((0x00000400&(data))>>10)
#define  TOPBIST_dispi_bisr_done_get_memc_bisr_done_0(data)                      ((0x000003FE&(data))>>1)
#define  TOPBIST_dispi_bisr_done_get_spnr_bisr_done(data)                        (0x00000001&(data))

#define  TOPBIST_dispd_bisr_done                                                 0x18000F24
#define  TOPBIST_dispd_bisr_done_reg_addr                                        "0xB8000F24"
#define  TOPBIST_dispd_bisr_done_reg                                             0xB8000F24
#define  TOPBIST_dispd_bisr_done_inst_addr                                       "0x0009"
#define  set_TOPBIST_dispd_bisr_done_reg(data)                                   (*((volatile unsigned int*)TOPBIST_dispd_bisr_done_reg)=data)
#define  get_TOPBIST_dispd_bisr_done_reg                                         (*((volatile unsigned int*)TOPBIST_dispd_bisr_done_reg))
#define  TOPBIST_dispd_bisr_done_sfg_bisr_done_shift                             (6)
#define  TOPBIST_dispd_bisr_done_sfg_osd_bisr_done_shift                         (5)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_003_bisr_done_shift                   (4)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_002_bisr_done_shift                   (3)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_001_bisr_done_shift                   (2)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_000_bisr_done_shift                   (1)
#define  TOPBIST_dispd_bisr_done_shpnr_bisr_done_shift                           (0)
#define  TOPBIST_dispd_bisr_done_sfg_bisr_done_mask                              (0x00000040)
#define  TOPBIST_dispd_bisr_done_sfg_osd_bisr_done_mask                          (0x00000020)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_003_bisr_done_mask                    (0x00000010)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_002_bisr_done_mask                    (0x00000008)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_001_bisr_done_mask                    (0x00000004)
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_000_bisr_done_mask                    (0x00000002)
#define  TOPBIST_dispd_bisr_done_shpnr_bisr_done_mask                            (0x00000001)
#define  TOPBIST_dispd_bisr_done_sfg_bisr_done(data)                             (0x00000040&((data)<<6))
#define  TOPBIST_dispd_bisr_done_sfg_osd_bisr_done(data)                         (0x00000020&((data)<<5))
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_003_bisr_done(data)                   (0x00000010&((data)<<4))
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_002_bisr_done(data)                   (0x00000008&((data)<<3))
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_001_bisr_done(data)                   (0x00000004&((data)<<2))
#define  TOPBIST_dispd_bisr_done_gdma_fbdc_000_bisr_done(data)                   (0x00000002&((data)<<1))
#define  TOPBIST_dispd_bisr_done_shpnr_bisr_done(data)                           (0x00000001&(data))
#define  TOPBIST_dispd_bisr_done_get_sfg_bisr_done(data)                         ((0x00000040&(data))>>6)
#define  TOPBIST_dispd_bisr_done_get_sfg_osd_bisr_done(data)                     ((0x00000020&(data))>>5)
#define  TOPBIST_dispd_bisr_done_get_gdma_fbdc_003_bisr_done(data)               ((0x00000010&(data))>>4)
#define  TOPBIST_dispd_bisr_done_get_gdma_fbdc_002_bisr_done(data)               ((0x00000008&(data))>>3)
#define  TOPBIST_dispd_bisr_done_get_gdma_fbdc_001_bisr_done(data)               ((0x00000004&(data))>>2)
#define  TOPBIST_dispd_bisr_done_get_gdma_fbdc_000_bisr_done(data)               ((0x00000002&(data))>>1)
#define  TOPBIST_dispd_bisr_done_get_shpnr_bisr_done(data)                       (0x00000001&(data))

#define  TOPBIST_vp9_bisr_done                                                   0x18000F28
#define  TOPBIST_vp9_bisr_done_reg_addr                                          "0xB8000F28"
#define  TOPBIST_vp9_bisr_done_reg                                               0xB8000F28
#define  TOPBIST_vp9_bisr_done_inst_addr                                         "0x000A"
#define  set_TOPBIST_vp9_bisr_done_reg(data)                                     (*((volatile unsigned int*)TOPBIST_vp9_bisr_done_reg)=data)
#define  get_TOPBIST_vp9_bisr_done_reg                                           (*((volatile unsigned int*)TOPBIST_vp9_bisr_done_reg))
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_5_done_shift                       (5)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_4_done_shift                       (4)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_3_done_shift                       (3)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_2_done_shift                       (2)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_1_done_shift                       (1)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_0_done_shift                       (0)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_5_done_mask                        (0x00000020)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_4_done_mask                        (0x00000010)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_3_done_mask                        (0x00000008)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_2_done_mask                        (0x00000004)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_1_done_mask                        (0x00000002)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_0_done_mask                        (0x00000001)
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_5_done(data)                       (0x00000020&((data)<<5))
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_4_done(data)                       (0x00000010&((data)<<4))
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_3_done(data)                       (0x00000008&((data)<<3))
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_2_done(data)                       (0x00000004&((data)<<2))
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_1_done(data)                       (0x00000002&((data)<<1))
#define  TOPBIST_vp9_bisr_done_img_demod_bisr_0_done(data)                       (0x00000001&(data))
#define  TOPBIST_vp9_bisr_done_get_img_demod_bisr_5_done(data)                   ((0x00000020&(data))>>5)
#define  TOPBIST_vp9_bisr_done_get_img_demod_bisr_4_done(data)                   ((0x00000010&(data))>>4)
#define  TOPBIST_vp9_bisr_done_get_img_demod_bisr_3_done(data)                   ((0x00000008&(data))>>3)
#define  TOPBIST_vp9_bisr_done_get_img_demod_bisr_2_done(data)                   ((0x00000004&(data))>>2)
#define  TOPBIST_vp9_bisr_done_get_img_demod_bisr_1_done(data)                   ((0x00000002&(data))>>1)
#define  TOPBIST_vp9_bisr_done_get_img_demod_bisr_0_done(data)                   (0x00000001&(data))

#define  TOPBIST_cpu_bisr_done                                                   0x18000F2C
#define  TOPBIST_cpu_bisr_done_reg_addr                                          "0xB8000F2C"
#define  TOPBIST_cpu_bisr_done_reg                                               0xB8000F2C
#define  TOPBIST_cpu_bisr_done_inst_addr                                         "0x000B"
#define  set_TOPBIST_cpu_bisr_done_reg(data)                                     (*((volatile unsigned int*)TOPBIST_cpu_bisr_done_reg)=data)
#define  get_TOPBIST_cpu_bisr_done_reg                                           (*((volatile unsigned int*)TOPBIST_cpu_bisr_done_reg))
#define  TOPBIST_cpu_bisr_done_emcu_bisr_done_shift                              (10)
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_3_done_shift                           (9)
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_2_done_shift                           (8)
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_1_done_shift                           (7)
#define  TOPBIST_cpu_bisr_done_vcpu2_bisr_done_shift                             (6)
#define  TOPBIST_cpu_bisr_done_a53_bisr_done_shift                               (5)
#define  TOPBIST_cpu_bisr_done_acpu_bisr_3_done_shift                            (4)
#define  TOPBIST_cpu_bisr_done_acpu_bisr_2_done_shift                            (3)
#define  TOPBIST_cpu_bisr_done_acpu_bisr_1_done_shift                            (2)
#define  TOPBIST_cpu_bisr_done_vcpu_bisr_done_shift                              (1)
#define  TOPBIST_cpu_bisr_done_emcu_bisr_done_mask                               (0x00000400)
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_3_done_mask                            (0x00000200)
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_2_done_mask                            (0x00000100)
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_1_done_mask                            (0x00000080)
#define  TOPBIST_cpu_bisr_done_vcpu2_bisr_done_mask                              (0x00000040)
#define  TOPBIST_cpu_bisr_done_a53_bisr_done_mask                                (0x00000020)
#define  TOPBIST_cpu_bisr_done_acpu_bisr_3_done_mask                             (0x00000010)
#define  TOPBIST_cpu_bisr_done_acpu_bisr_2_done_mask                             (0x00000008)
#define  TOPBIST_cpu_bisr_done_acpu_bisr_1_done_mask                             (0x00000004)
#define  TOPBIST_cpu_bisr_done_vcpu_bisr_done_mask                               (0x00000002)
#define  TOPBIST_cpu_bisr_done_emcu_bisr_done(data)                              (0x00000400&((data)<<10))
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_3_done(data)                           (0x00000200&((data)<<9))
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_2_done(data)                           (0x00000100&((data)<<8))
#define  TOPBIST_cpu_bisr_done_acpu2_bisr_1_done(data)                           (0x00000080&((data)<<7))
#define  TOPBIST_cpu_bisr_done_vcpu2_bisr_done(data)                             (0x00000040&((data)<<6))
#define  TOPBIST_cpu_bisr_done_a53_bisr_done(data)                               (0x00000020&((data)<<5))
#define  TOPBIST_cpu_bisr_done_acpu_bisr_3_done(data)                            (0x00000010&((data)<<4))
#define  TOPBIST_cpu_bisr_done_acpu_bisr_2_done(data)                            (0x00000008&((data)<<3))
#define  TOPBIST_cpu_bisr_done_acpu_bisr_1_done(data)                            (0x00000004&((data)<<2))
#define  TOPBIST_cpu_bisr_done_vcpu_bisr_done(data)                              (0x00000002&((data)<<1))
#define  TOPBIST_cpu_bisr_done_get_emcu_bisr_done(data)                          ((0x00000400&(data))>>10)
#define  TOPBIST_cpu_bisr_done_get_acpu2_bisr_3_done(data)                       ((0x00000200&(data))>>9)
#define  TOPBIST_cpu_bisr_done_get_acpu2_bisr_2_done(data)                       ((0x00000100&(data))>>8)
#define  TOPBIST_cpu_bisr_done_get_acpu2_bisr_1_done(data)                       ((0x00000080&(data))>>7)
#define  TOPBIST_cpu_bisr_done_get_vcpu2_bisr_done(data)                         ((0x00000040&(data))>>6)
#define  TOPBIST_cpu_bisr_done_get_a53_bisr_done(data)                           ((0x00000020&(data))>>5)
#define  TOPBIST_cpu_bisr_done_get_acpu_bisr_3_done(data)                        ((0x00000010&(data))>>4)
#define  TOPBIST_cpu_bisr_done_get_acpu_bisr_2_done(data)                        ((0x00000008&(data))>>3)
#define  TOPBIST_cpu_bisr_done_get_acpu_bisr_1_done(data)                        ((0x00000004&(data))>>2)
#define  TOPBIST_cpu_bisr_done_get_vcpu_bisr_done(data)                          ((0x00000002&(data))>>1)

#define  TOPBIST_SS_7T_0                                                         0x18000F30
#define  TOPBIST_SS_7T_0_reg_addr                                                "0xB8000F30"
#define  TOPBIST_SS_7T_0_reg                                                     0xB8000F30
#define  TOPBIST_SS_7T_0_inst_addr                                               "0x000C"
#define  set_TOPBIST_SS_7T_0_reg(data)                                           (*((volatile unsigned int*)TOPBIST_SS_7T_0_reg)=data)
#define  get_TOPBIST_SS_7T_0_reg                                                 (*((volatile unsigned int*)TOPBIST_SS_7T_0_reg))
#define  TOPBIST_SS_7T_0_rlvt_7t_dss_rst_n_shift                                 (31)
#define  TOPBIST_SS_7T_0_rlvt_7t_ro_sel_shift                                    (25)
#define  TOPBIST_SS_7T_0_rlvt_7t_wire_sel_shift                                  (24)
#define  TOPBIST_SS_7T_0_rlvt_7t_ready_shift                                     (20)
#define  TOPBIST_SS_7T_0_rlvt_7t_count_out_shift                                 (0)
#define  TOPBIST_SS_7T_0_rlvt_7t_dss_rst_n_mask                                  (0x80000000)
#define  TOPBIST_SS_7T_0_rlvt_7t_ro_sel_mask                                     (0x0E000000)
#define  TOPBIST_SS_7T_0_rlvt_7t_wire_sel_mask                                   (0x01000000)
#define  TOPBIST_SS_7T_0_rlvt_7t_ready_mask                                      (0x00100000)
#define  TOPBIST_SS_7T_0_rlvt_7t_count_out_mask                                  (0x000FFFFF)
#define  TOPBIST_SS_7T_0_rlvt_7t_dss_rst_n(data)                                 (0x80000000&((data)<<31))
#define  TOPBIST_SS_7T_0_rlvt_7t_ro_sel(data)                                    (0x0E000000&((data)<<25))
#define  TOPBIST_SS_7T_0_rlvt_7t_wire_sel(data)                                  (0x01000000&((data)<<24))
#define  TOPBIST_SS_7T_0_rlvt_7t_ready(data)                                     (0x00100000&((data)<<20))
#define  TOPBIST_SS_7T_0_rlvt_7t_count_out(data)                                 (0x000FFFFF&(data))
#define  TOPBIST_SS_7T_0_get_rlvt_7t_dss_rst_n(data)                             ((0x80000000&(data))>>31)
#define  TOPBIST_SS_7T_0_get_rlvt_7t_ro_sel(data)                                ((0x0E000000&(data))>>25)
#define  TOPBIST_SS_7T_0_get_rlvt_7t_wire_sel(data)                              ((0x01000000&(data))>>24)
#define  TOPBIST_SS_7T_0_get_rlvt_7t_ready(data)                                 ((0x00100000&(data))>>20)
#define  TOPBIST_SS_7T_0_get_rlvt_7t_count_out(data)                             (0x000FFFFF&(data))

#define  TOPBIST_SS_7T_1                                                         0x18000F34
#define  TOPBIST_SS_7T_1_reg_addr                                                "0xB8000F34"
#define  TOPBIST_SS_7T_1_reg                                                     0xB8000F34
#define  TOPBIST_SS_7T_1_inst_addr                                               "0x000D"
#define  set_TOPBIST_SS_7T_1_reg(data)                                           (*((volatile unsigned int*)TOPBIST_SS_7T_1_reg)=data)
#define  get_TOPBIST_SS_7T_1_reg                                                 (*((volatile unsigned int*)TOPBIST_SS_7T_1_reg))
#define  TOPBIST_SS_7T_1_rlvt_7t_speed_en_shift                                  (24)
#define  TOPBIST_SS_7T_1_rlvt_7t_data_in_shift                                   (4)
#define  TOPBIST_SS_7T_1_rlvt_7t_wsort_go_shift                                  (0)
#define  TOPBIST_SS_7T_1_rlvt_7t_speed_en_mask                                   (0x01000000)
#define  TOPBIST_SS_7T_1_rlvt_7t_data_in_mask                                    (0x00FFFFF0)
#define  TOPBIST_SS_7T_1_rlvt_7t_wsort_go_mask                                   (0x00000001)
#define  TOPBIST_SS_7T_1_rlvt_7t_speed_en(data)                                  (0x01000000&((data)<<24))
#define  TOPBIST_SS_7T_1_rlvt_7t_data_in(data)                                   (0x00FFFFF0&((data)<<4))
#define  TOPBIST_SS_7T_1_rlvt_7t_wsort_go(data)                                  (0x00000001&(data))
#define  TOPBIST_SS_7T_1_get_rlvt_7t_speed_en(data)                              ((0x01000000&(data))>>24)
#define  TOPBIST_SS_7T_1_get_rlvt_7t_data_in(data)                               ((0x00FFFFF0&(data))>>4)
#define  TOPBIST_SS_7T_1_get_rlvt_7t_wsort_go(data)                              (0x00000001&(data))

#define  TOPBIST_SS_7T_2                                                         0x18000F38
#define  TOPBIST_SS_7T_2_reg_addr                                                "0xB8000F38"
#define  TOPBIST_SS_7T_2_reg                                                     0xB8000F38
#define  TOPBIST_SS_7T_2_inst_addr                                               "0x000E"
#define  set_TOPBIST_SS_7T_2_reg(data)                                           (*((volatile unsigned int*)TOPBIST_SS_7T_2_reg)=data)
#define  get_TOPBIST_SS_7T_2_reg                                                 (*((volatile unsigned int*)TOPBIST_SS_7T_2_reg))
#define  TOPBIST_SS_7T_2_rlvt_7t_dbgo_shift                                      (0)
#define  TOPBIST_SS_7T_2_rlvt_7t_dbgo_mask                                       (0x0000FFFF)
#define  TOPBIST_SS_7T_2_rlvt_7t_dbgo(data)                                      (0x0000FFFF&(data))
#define  TOPBIST_SS_7T_2_get_rlvt_7t_dbgo(data)                                  (0x0000FFFF&(data))

#define  TOPBIST_KCPU_BIST_MODE                                                  0x18000F80
#define  TOPBIST_KCPU_BIST_MODE_reg_addr                                         "0xB8000F80"
#define  TOPBIST_KCPU_BIST_MODE_reg                                              0xB8000F80
#define  TOPBIST_KCPU_BIST_MODE_inst_addr                                        "0x000F"
#define  set_TOPBIST_KCPU_BIST_MODE_reg(data)                                    (*((volatile unsigned int*)TOPBIST_KCPU_BIST_MODE_reg)=data)
#define  get_TOPBIST_KCPU_BIST_MODE_reg                                          (*((volatile unsigned int*)TOPBIST_KCPU_BIST_MODE_reg))
#define  TOPBIST_KCPU_BIST_MODE_kcpu_bist_mode_shift                             (0)
#define  TOPBIST_KCPU_BIST_MODE_kcpu_bist_mode_mask                              (0x00000001)
#define  TOPBIST_KCPU_BIST_MODE_kcpu_bist_mode(data)                             (0x00000001&(data))
#define  TOPBIST_KCPU_BIST_MODE_get_kcpu_bist_mode(data)                         (0x00000001&(data))

#define  TOPBIST_KCPU_BIST_DONE                                                  0x18000F84
#define  TOPBIST_KCPU_BIST_DONE_reg_addr                                         "0xB8000F84"
#define  TOPBIST_KCPU_BIST_DONE_reg                                              0xB8000F84
#define  TOPBIST_KCPU_BIST_DONE_inst_addr                                        "0x0010"
#define  set_TOPBIST_KCPU_BIST_DONE_reg(data)                                    (*((volatile unsigned int*)TOPBIST_KCPU_BIST_DONE_reg)=data)
#define  get_TOPBIST_KCPU_BIST_DONE_reg                                          (*((volatile unsigned int*)TOPBIST_KCPU_BIST_DONE_reg))
#define  TOPBIST_KCPU_BIST_DONE_kcpu_bist_done_shift                             (0)
#define  TOPBIST_KCPU_BIST_DONE_kcpu_bist_done_mask                              (0x00000001)
#define  TOPBIST_KCPU_BIST_DONE_kcpu_bist_done(data)                             (0x00000001&(data))
#define  TOPBIST_KCPU_BIST_DONE_get_kcpu_bist_done(data)                         (0x00000001&(data))

#define  TOPBIST_KCPU_BIST_FAIL_GROUP                                            0x18000F88
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_reg_addr                                   "0xB8000F88"
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_reg                                        0xB8000F88
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_inst_addr                                  "0x0011"
#define  set_TOPBIST_KCPU_BIST_FAIL_GROUP_reg(data)                              (*((volatile unsigned int*)TOPBIST_KCPU_BIST_FAIL_GROUP_reg)=data)
#define  get_TOPBIST_KCPU_BIST_FAIL_GROUP_reg                                    (*((volatile unsigned int*)TOPBIST_KCPU_BIST_FAIL_GROUP_reg))
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_kcpu_bist_fail_group_shift                 (0)
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_kcpu_bist_fail_group_mask                  (0x00000001)
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_kcpu_bist_fail_group(data)                 (0x00000001&(data))
#define  TOPBIST_KCPU_BIST_FAIL_GROUP_get_kcpu_bist_fail_group(data)             (0x00000001&(data))

#define  TOPBIST_KCPU_BIST_FAIL                                                  0x18000F8C
#define  TOPBIST_KCPU_BIST_FAIL_reg_addr                                         "0xB8000F8C"
#define  TOPBIST_KCPU_BIST_FAIL_reg                                              0xB8000F8C
#define  TOPBIST_KCPU_BIST_FAIL_inst_addr                                        "0x0012"
#define  set_TOPBIST_KCPU_BIST_FAIL_reg(data)                                    (*((volatile unsigned int*)TOPBIST_KCPU_BIST_FAIL_reg)=data)
#define  get_TOPBIST_KCPU_BIST_FAIL_reg                                          (*((volatile unsigned int*)TOPBIST_KCPU_BIST_FAIL_reg))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail8_shift                            (8)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail7_shift                            (7)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail6_shift                            (6)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail5_shift                            (5)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail4_shift                            (4)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail3_shift                            (3)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail2_shift                            (2)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail1_shift                            (1)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail0_shift                            (0)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail8_mask                             (0x00000100)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail7_mask                             (0x00000080)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail6_mask                             (0x00000040)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail5_mask                             (0x00000020)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail4_mask                             (0x00000010)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail3_mask                             (0x00000008)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail2_mask                             (0x00000004)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail1_mask                             (0x00000002)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail0_mask                             (0x00000001)
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail8(data)                            (0x00000100&((data)<<8))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail7(data)                            (0x00000080&((data)<<7))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail6(data)                            (0x00000040&((data)<<6))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail5(data)                            (0x00000020&((data)<<5))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail4(data)                            (0x00000010&((data)<<4))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail3(data)                            (0x00000008&((data)<<3))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail2(data)                            (0x00000004&((data)<<2))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail1(data)                            (0x00000002&((data)<<1))
#define  TOPBIST_KCPU_BIST_FAIL_kcpu_bist_fail0(data)                            (0x00000001&(data))
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail8(data)                        ((0x00000100&(data))>>8)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail7(data)                        ((0x00000080&(data))>>7)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail6(data)                        ((0x00000040&(data))>>6)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail5(data)                        ((0x00000020&(data))>>5)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail4(data)                        ((0x00000010&(data))>>4)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail3(data)                        ((0x00000008&(data))>>3)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail2(data)                        ((0x00000004&(data))>>2)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail1(data)                        ((0x00000002&(data))>>1)
#define  TOPBIST_KCPU_BIST_FAIL_get_kcpu_bist_fail0(data)                        (0x00000001&(data))

#define  TOPBIST_KCPU_DRF_MODE                                                   0x18000F90
#define  TOPBIST_KCPU_DRF_MODE_reg_addr                                          "0xB8000F90"
#define  TOPBIST_KCPU_DRF_MODE_reg                                               0xB8000F90
#define  TOPBIST_KCPU_DRF_MODE_inst_addr                                         "0x0013"
#define  set_TOPBIST_KCPU_DRF_MODE_reg(data)                                     (*((volatile unsigned int*)TOPBIST_KCPU_DRF_MODE_reg)=data)
#define  get_TOPBIST_KCPU_DRF_MODE_reg                                           (*((volatile unsigned int*)TOPBIST_KCPU_DRF_MODE_reg))
#define  TOPBIST_KCPU_DRF_MODE_kcpu_drf_mode_shift                               (0)
#define  TOPBIST_KCPU_DRF_MODE_kcpu_drf_mode_mask                                (0x00000001)
#define  TOPBIST_KCPU_DRF_MODE_kcpu_drf_mode(data)                               (0x00000001&(data))
#define  TOPBIST_KCPU_DRF_MODE_get_kcpu_drf_mode(data)                           (0x00000001&(data))

#define  TOPBIST_KCPU_DRF_RESUME                                                 0x18000F94
#define  TOPBIST_KCPU_DRF_RESUME_reg_addr                                        "0xB8000F94"
#define  TOPBIST_KCPU_DRF_RESUME_reg                                             0xB8000F94
#define  TOPBIST_KCPU_DRF_RESUME_inst_addr                                       "0x0014"
#define  set_TOPBIST_KCPU_DRF_RESUME_reg(data)                                   (*((volatile unsigned int*)TOPBIST_KCPU_DRF_RESUME_reg)=data)
#define  get_TOPBIST_KCPU_DRF_RESUME_reg                                         (*((volatile unsigned int*)TOPBIST_KCPU_DRF_RESUME_reg))
#define  TOPBIST_KCPU_DRF_RESUME_kcpu_drf_resume_shift                           (0)
#define  TOPBIST_KCPU_DRF_RESUME_kcpu_drf_resume_mask                            (0x00000001)
#define  TOPBIST_KCPU_DRF_RESUME_kcpu_drf_resume(data)                           (0x00000001&(data))
#define  TOPBIST_KCPU_DRF_RESUME_get_kcpu_drf_resume(data)                       (0x00000001&(data))

#define  TOPBIST_KCPU_DRF_DONE                                                   0x18000F98
#define  TOPBIST_KCPU_DRF_DONE_reg_addr                                          "0xB8000F98"
#define  TOPBIST_KCPU_DRF_DONE_reg                                               0xB8000F98
#define  TOPBIST_KCPU_DRF_DONE_inst_addr                                         "0x0015"
#define  set_TOPBIST_KCPU_DRF_DONE_reg(data)                                     (*((volatile unsigned int*)TOPBIST_KCPU_DRF_DONE_reg)=data)
#define  get_TOPBIST_KCPU_DRF_DONE_reg                                           (*((volatile unsigned int*)TOPBIST_KCPU_DRF_DONE_reg))
#define  TOPBIST_KCPU_DRF_DONE_kcpu_drf_done_shift                               (0)
#define  TOPBIST_KCPU_DRF_DONE_kcpu_drf_done_mask                                (0x00000001)
#define  TOPBIST_KCPU_DRF_DONE_kcpu_drf_done(data)                               (0x00000001&(data))
#define  TOPBIST_KCPU_DRF_DONE_get_kcpu_drf_done(data)                           (0x00000001&(data))

#define  TOPBIST_KCPU_DRF_PAUSE                                                  0x18000F9C
#define  TOPBIST_KCPU_DRF_PAUSE_reg_addr                                         "0xB8000F9C"
#define  TOPBIST_KCPU_DRF_PAUSE_reg                                              0xB8000F9C
#define  TOPBIST_KCPU_DRF_PAUSE_inst_addr                                        "0x0016"
#define  set_TOPBIST_KCPU_DRF_PAUSE_reg(data)                                    (*((volatile unsigned int*)TOPBIST_KCPU_DRF_PAUSE_reg)=data)
#define  get_TOPBIST_KCPU_DRF_PAUSE_reg                                          (*((volatile unsigned int*)TOPBIST_KCPU_DRF_PAUSE_reg))
#define  TOPBIST_KCPU_DRF_PAUSE_kcpu_drf_pause_shift                             (0)
#define  TOPBIST_KCPU_DRF_PAUSE_kcpu_drf_pause_mask                              (0x00000001)
#define  TOPBIST_KCPU_DRF_PAUSE_kcpu_drf_pause(data)                             (0x00000001&(data))
#define  TOPBIST_KCPU_DRF_PAUSE_get_kcpu_drf_pause(data)                         (0x00000001&(data))

#define  TOPBIST_KCPU_DRF_FAIL_GROUP                                             0x18000FA0
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_reg_addr                                    "0xB8000FA0"
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_reg                                         0xB8000FA0
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_inst_addr                                   "0x0017"
#define  set_TOPBIST_KCPU_DRF_FAIL_GROUP_reg(data)                               (*((volatile unsigned int*)TOPBIST_KCPU_DRF_FAIL_GROUP_reg)=data)
#define  get_TOPBIST_KCPU_DRF_FAIL_GROUP_reg                                     (*((volatile unsigned int*)TOPBIST_KCPU_DRF_FAIL_GROUP_reg))
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_kcpu_drf_fail_group_shift                   (0)
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_kcpu_drf_fail_group_mask                    (0x00000001)
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_kcpu_drf_fail_group(data)                   (0x00000001&(data))
#define  TOPBIST_KCPU_DRF_FAIL_GROUP_get_kcpu_drf_fail_group(data)               (0x00000001&(data))

#define  TOPBIST_KCPU_DRF_OOO_FAIL                                               0x18000FA4
#define  TOPBIST_KCPU_DRF_OOO_FAIL_reg_addr                                      "0xB8000FA4"
#define  TOPBIST_KCPU_DRF_OOO_FAIL_reg                                           0xB8000FA4
#define  TOPBIST_KCPU_DRF_OOO_FAIL_inst_addr                                     "0x0018"
#define  set_TOPBIST_KCPU_DRF_OOO_FAIL_reg(data)                                 (*((volatile unsigned int*)TOPBIST_KCPU_DRF_OOO_FAIL_reg)=data)
#define  get_TOPBIST_KCPU_DRF_OOO_FAIL_reg                                       (*((volatile unsigned int*)TOPBIST_KCPU_DRF_OOO_FAIL_reg))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail8_shift                          (8)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail7_shift                          (7)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail6_shift                          (6)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail5_shift                          (5)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail4_shift                          (4)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail3_shift                          (3)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail2_shift                          (2)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail1_shift                          (1)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail0_shift                          (0)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail8_mask                           (0x00000100)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail7_mask                           (0x00000080)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail6_mask                           (0x00000040)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail5_mask                           (0x00000020)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail4_mask                           (0x00000010)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail3_mask                           (0x00000008)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail2_mask                           (0x00000004)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail1_mask                           (0x00000002)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail0_mask                           (0x00000001)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail8(data)                          (0x00000100&((data)<<8))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail7(data)                          (0x00000080&((data)<<7))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail6(data)                          (0x00000040&((data)<<6))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail5(data)                          (0x00000020&((data)<<5))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail4(data)                          (0x00000010&((data)<<4))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail3(data)                          (0x00000008&((data)<<3))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail2(data)                          (0x00000004&((data)<<2))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail1(data)                          (0x00000002&((data)<<1))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_kcpu_drf_fail0(data)                          (0x00000001&(data))
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail8(data)                      ((0x00000100&(data))>>8)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail7(data)                      ((0x00000080&(data))>>7)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail6(data)                      ((0x00000040&(data))>>6)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail5(data)                      ((0x00000020&(data))>>5)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail4(data)                      ((0x00000010&(data))>>4)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail3(data)                      ((0x00000008&(data))>>3)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail2(data)                      ((0x00000004&(data))>>2)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail1(data)                      ((0x00000002&(data))>>1)
#define  TOPBIST_KCPU_DRF_OOO_FAIL_get_kcpu_drf_fail0(data)                      (0x00000001&(data))

#define  TOPBIST_KCPU_RME                                                        0x18000FE0
#define  TOPBIST_KCPU_RME_reg_addr                                               "0xB8000FE0"
#define  TOPBIST_KCPU_RME_reg                                                    0xB8000FE0
#define  TOPBIST_KCPU_RME_inst_addr                                              "0x0019"
#define  set_TOPBIST_KCPU_RME_reg(data)                                          (*((volatile unsigned int*)TOPBIST_KCPU_RME_reg)=data)
#define  get_TOPBIST_KCPU_RME_reg                                                (*((volatile unsigned int*)TOPBIST_KCPU_RME_reg))
#define  TOPBIST_KCPU_RME_kcpu_rme_shift                                         (0)
#define  TOPBIST_KCPU_RME_kcpu_rme_mask                                          (0x00000001)
#define  TOPBIST_KCPU_RME_kcpu_rme(data)                                         (0x00000001&(data))
#define  TOPBIST_KCPU_RME_get_kcpu_rme(data)                                     (0x00000001&(data))

#define  TOPBIST_KCPU_RM                                                         0x18000FE4
#define  TOPBIST_KCPU_RM_reg_addr                                                "0xB8000FE4"
#define  TOPBIST_KCPU_RM_reg                                                     0xB8000FE4
#define  TOPBIST_KCPU_RM_inst_addr                                               "0x001A"
#define  set_TOPBIST_KCPU_RM_reg(data)                                           (*((volatile unsigned int*)TOPBIST_KCPU_RM_reg)=data)
#define  get_TOPBIST_KCPU_RM_reg                                                 (*((volatile unsigned int*)TOPBIST_KCPU_RM_reg))
#define  TOPBIST_KCPU_RM_kcpu_rm_shift                                           (0)
#define  TOPBIST_KCPU_RM_kcpu_rm_mask                                            (0x0000000F)
#define  TOPBIST_KCPU_RM_kcpu_rm(data)                                           (0x0000000F&(data))
#define  TOPBIST_KCPU_RM_get_kcpu_rm(data)                                       (0x0000000F&(data))

#define  TOPBIST_KCPU_LS                                                         0x18000FE8
#define  TOPBIST_KCPU_LS_reg_addr                                                "0xB8000FE8"
#define  TOPBIST_KCPU_LS_reg                                                     0xB8000FE8
#define  TOPBIST_KCPU_LS_inst_addr                                               "0x001B"
#define  set_TOPBIST_KCPU_LS_reg(data)                                           (*((volatile unsigned int*)TOPBIST_KCPU_LS_reg)=data)
#define  get_TOPBIST_KCPU_LS_reg                                                 (*((volatile unsigned int*)TOPBIST_KCPU_LS_reg))
#define  TOPBIST_KCPU_LS_kcpu_ls_shift                                           (0)
#define  TOPBIST_KCPU_LS_kcpu_ls_mask                                            (0x00000001)
#define  TOPBIST_KCPU_LS_kcpu_ls(data)                                           (0x00000001&(data))
#define  TOPBIST_KCPU_LS_get_kcpu_ls(data)                                       (0x00000001&(data))

#define  TOPBIST_BIST_SET_ON                                                     0x18000FF0
#define  TOPBIST_BIST_SET_ON_reg_addr                                            "0xB8000FF0"
#define  TOPBIST_BIST_SET_ON_reg                                                 0xB8000FF0
#define  TOPBIST_BIST_SET_ON_inst_addr                                           "0x001C"
#define  set_TOPBIST_BIST_SET_ON_reg(data)                                       (*((volatile unsigned int*)TOPBIST_BIST_SET_ON_reg)=data)
#define  get_TOPBIST_BIST_SET_ON_reg                                             (*((volatile unsigned int*)TOPBIST_BIST_SET_ON_reg))
#define  TOPBIST_BIST_SET_ON_chip_bist_set_on_shift                              (31)
#define  TOPBIST_BIST_SET_ON_acpu2_bist_set_on_shift                             (6)
#define  TOPBIST_BIST_SET_ON_sb2_bist_set_on_shift                               (5)
#define  TOPBIST_BIST_SET_ON_bridge_bist_set_on_shift                            (4)
#define  TOPBIST_BIST_SET_ON_scpu_bist_set_on_shift                              (3)
#define  TOPBIST_BIST_SET_ON_acpu_bist_set_on_shift                              (2)
#define  TOPBIST_BIST_SET_ON_vcpu_bist_set_on_shift                              (1)
#define  TOPBIST_BIST_SET_ON_kcpu_bist_set_on_shift                              (0)
#define  TOPBIST_BIST_SET_ON_chip_bist_set_on_mask                               (0x80000000)
#define  TOPBIST_BIST_SET_ON_acpu2_bist_set_on_mask                              (0x00000040)
#define  TOPBIST_BIST_SET_ON_sb2_bist_set_on_mask                                (0x00000020)
#define  TOPBIST_BIST_SET_ON_bridge_bist_set_on_mask                             (0x00000010)
#define  TOPBIST_BIST_SET_ON_scpu_bist_set_on_mask                               (0x00000008)
#define  TOPBIST_BIST_SET_ON_acpu_bist_set_on_mask                               (0x00000004)
#define  TOPBIST_BIST_SET_ON_vcpu_bist_set_on_mask                               (0x00000002)
#define  TOPBIST_BIST_SET_ON_kcpu_bist_set_on_mask                               (0x00000001)
#define  TOPBIST_BIST_SET_ON_chip_bist_set_on(data)                              (0x80000000&((data)<<31))
#define  TOPBIST_BIST_SET_ON_acpu2_bist_set_on(data)                             (0x00000040&((data)<<6))
#define  TOPBIST_BIST_SET_ON_sb2_bist_set_on(data)                               (0x00000020&((data)<<5))
#define  TOPBIST_BIST_SET_ON_bridge_bist_set_on(data)                            (0x00000010&((data)<<4))
#define  TOPBIST_BIST_SET_ON_scpu_bist_set_on(data)                              (0x00000008&((data)<<3))
#define  TOPBIST_BIST_SET_ON_acpu_bist_set_on(data)                              (0x00000004&((data)<<2))
#define  TOPBIST_BIST_SET_ON_vcpu_bist_set_on(data)                              (0x00000002&((data)<<1))
#define  TOPBIST_BIST_SET_ON_kcpu_bist_set_on(data)                              (0x00000001&(data))
#define  TOPBIST_BIST_SET_ON_get_chip_bist_set_on(data)                          ((0x80000000&(data))>>31)
#define  TOPBIST_BIST_SET_ON_get_acpu2_bist_set_on(data)                         ((0x00000040&(data))>>6)
#define  TOPBIST_BIST_SET_ON_get_sb2_bist_set_on(data)                           ((0x00000020&(data))>>5)
#define  TOPBIST_BIST_SET_ON_get_bridge_bist_set_on(data)                        ((0x00000010&(data))>>4)
#define  TOPBIST_BIST_SET_ON_get_scpu_bist_set_on(data)                          ((0x00000008&(data))>>3)
#define  TOPBIST_BIST_SET_ON_get_acpu_bist_set_on(data)                          ((0x00000004&(data))>>2)
#define  TOPBIST_BIST_SET_ON_get_vcpu_bist_set_on(data)                          ((0x00000002&(data))>>1)
#define  TOPBIST_BIST_SET_ON_get_kcpu_bist_set_on(data)                          (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TOPBIST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  memc_bisr_rstn_1:1;
        RBus_UInt32  memc_bisr_rstn_0:9;
        RBus_UInt32  spnr_bisr_rstn:1;
    };
}topbist_dispi_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sfg_bisr_rstn:1;
        RBus_UInt32  sfg_osd_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_003_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_002_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_001_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_000_bisr_rstn:1;
        RBus_UInt32  shpnr_bisr_rstn:1;
    };
}topbist_dispd_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_bisr_5_rstn:1;
        RBus_UInt32  img_demod_bisr_4_rstn:1;
        RBus_UInt32  img_demod_bisr_3_rstn:1;
        RBus_UInt32  img_demod_bisr_2_rstn:1;
        RBus_UInt32  img_demod_bisr_1_rstn:1;
        RBus_UInt32  img_demod_bisr_0_rstn:1;
    };
}topbist_dtv_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dummy18000f0c_10:1;
        RBus_UInt32  acpu2_bisr_3_rstn:1;
        RBus_UInt32  acpu2_bisr_2_rstn:1;
        RBus_UInt32  acpu2_bisr_1_rstn:1;
        RBus_UInt32  vcpu2_bisr_rstn:1;
        RBus_UInt32  a53_bisr_rstn:1;
        RBus_UInt32  acpu_bisr_3_rstn:1;
        RBus_UInt32  acpu_bisr_2_rstn:1;
        RBus_UInt32  acpu_bisr_1_rstn:1;
        RBus_UInt32  vcpu_bisr_rstn:1;
        RBus_UInt32  res2:1;
    };
}topbist_cpu_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  memc_bisr_remap_1:1;
        RBus_UInt32  memc_bisr_remap_0:9;
        RBus_UInt32  spnr_bisr_remap:1;
    };
}topbist_dispi_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sfg_bisr_remap:1;
        RBus_UInt32  sfg_osd_bisr_remap:1;
        RBus_UInt32  gdma_fbdc_003_remap:1;
        RBus_UInt32  gdma_fbdc_002_remap:1;
        RBus_UInt32  gdma_fbdc_001_remap:1;
        RBus_UInt32  gdma_fbdc_000_remap:1;
        RBus_UInt32  shpnr_bisr_remap:1;
    };
}topbist_dispd_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_bisr_5_remap:1;
        RBus_UInt32  img_demod_bisr_4_remap:1;
        RBus_UInt32  img_demod_bisr_3_remap:1;
        RBus_UInt32  img_demod_bisr_2_remap:1;
        RBus_UInt32  img_demod_bisr_1_remap:1;
        RBus_UInt32  img_demod_bisr_0_remap:1;
    };
}topbist_vp9_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dummy18000f1c_10:1;
        RBus_UInt32  acpu2_bisr_3_remap:1;
        RBus_UInt32  acpu2_bisr_2_remap:1;
        RBus_UInt32  acpu2_bisr_1_remap:1;
        RBus_UInt32  vcpu2_bisr_remap:1;
        RBus_UInt32  a53_bisr_remap:1;
        RBus_UInt32  acpu_bisr_3_remap:1;
        RBus_UInt32  acpu_bisr_2_remap:1;
        RBus_UInt32  acpu_bisr_1_remap:1;
        RBus_UInt32  vcpu_bisr_remap:1;
        RBus_UInt32  res2:1;
    };
}topbist_cpu_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  memc_bisr_done_1:1;
        RBus_UInt32  memc_bisr_done_0:9;
        RBus_UInt32  spnr_bisr_done:1;
    };
}topbist_dispi_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sfg_bisr_done:1;
        RBus_UInt32  sfg_osd_bisr_done:1;
        RBus_UInt32  gdma_fbdc_003_bisr_done:1;
        RBus_UInt32  gdma_fbdc_002_bisr_done:1;
        RBus_UInt32  gdma_fbdc_001_bisr_done:1;
        RBus_UInt32  gdma_fbdc_000_bisr_done:1;
        RBus_UInt32  shpnr_bisr_done:1;
    };
}topbist_dispd_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  img_demod_bisr_5_done:1;
        RBus_UInt32  img_demod_bisr_4_done:1;
        RBus_UInt32  img_demod_bisr_3_done:1;
        RBus_UInt32  img_demod_bisr_2_done:1;
        RBus_UInt32  img_demod_bisr_1_done:1;
        RBus_UInt32  img_demod_bisr_0_done:1;
    };
}topbist_vp9_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  emcu_bisr_done:1;
        RBus_UInt32  acpu2_bisr_3_done:1;
        RBus_UInt32  acpu2_bisr_2_done:1;
        RBus_UInt32  acpu2_bisr_1_done:1;
        RBus_UInt32  vcpu2_bisr_done:1;
        RBus_UInt32  a53_bisr_done:1;
        RBus_UInt32  acpu_bisr_3_done:1;
        RBus_UInt32  acpu_bisr_2_done:1;
        RBus_UInt32  acpu_bisr_1_done:1;
        RBus_UInt32  vcpu_bisr_done:1;
        RBus_UInt32  res2:1;
    };
}topbist_cpu_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_dss_rst_n:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rlvt_7t_ro_sel:3;
        RBus_UInt32  rlvt_7t_wire_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rlvt_7t_ready:1;
        RBus_UInt32  rlvt_7t_count_out:20;
    };
}topbist_ss_7t_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  rlvt_7t_speed_en:1;
        RBus_UInt32  rlvt_7t_data_in:20;
        RBus_UInt32  res2:3;
        RBus_UInt32  rlvt_7t_wsort_go:1;
    };
}topbist_ss_7t_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rlvt_7t_dbgo:16;
    };
}topbist_ss_7t_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_bist_mode:1;
    };
}topbist_kcpu_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_bist_done:1;
    };
}topbist_kcpu_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_bist_fail_group:1;
    };
}topbist_kcpu_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  kcpu_bist_fail8:1;
        RBus_UInt32  kcpu_bist_fail7:1;
        RBus_UInt32  kcpu_bist_fail6:1;
        RBus_UInt32  kcpu_bist_fail5:1;
        RBus_UInt32  kcpu_bist_fail4:1;
        RBus_UInt32  kcpu_bist_fail3:1;
        RBus_UInt32  kcpu_bist_fail2:1;
        RBus_UInt32  kcpu_bist_fail1:1;
        RBus_UInt32  kcpu_bist_fail0:1;
    };
}topbist_kcpu_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_drf_mode:1;
    };
}topbist_kcpu_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_drf_resume:1;
    };
}topbist_kcpu_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_drf_done:1;
    };
}topbist_kcpu_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_drf_pause:1;
    };
}topbist_kcpu_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_drf_fail_group:1;
    };
}topbist_kcpu_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  kcpu_drf_fail8:1;
        RBus_UInt32  kcpu_drf_fail7:1;
        RBus_UInt32  kcpu_drf_fail6:1;
        RBus_UInt32  kcpu_drf_fail5:1;
        RBus_UInt32  kcpu_drf_fail4:1;
        RBus_UInt32  kcpu_drf_fail3:1;
        RBus_UInt32  kcpu_drf_fail2:1;
        RBus_UInt32  kcpu_drf_fail1:1;
        RBus_UInt32  kcpu_drf_fail0:1;
    };
}topbist_kcpu_drf_ooo_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_rme:1;
    };
}topbist_kcpu_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  kcpu_rm:4;
    };
}topbist_kcpu_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  kcpu_ls:1;
    };
}topbist_kcpu_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chip_bist_set_on:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  acpu2_bist_set_on:1;
        RBus_UInt32  sb2_bist_set_on:1;
        RBus_UInt32  bridge_bist_set_on:1;
        RBus_UInt32  scpu_bist_set_on:1;
        RBus_UInt32  acpu_bist_set_on:1;
        RBus_UInt32  vcpu_bist_set_on:1;
        RBus_UInt32  kcpu_bist_set_on:1;
    };
}topbist_bist_set_on_RBUS;

#else //apply LITTLE_ENDIAN

//======TOPBIST register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_rstn:1;
        RBus_UInt32  memc_bisr_rstn_0:9;
        RBus_UInt32  memc_bisr_rstn_1:1;
        RBus_UInt32  res1:21;
    };
}topbist_dispi_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_000_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_001_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_002_bisr_rstn:1;
        RBus_UInt32  gdma_fbdc_003_bisr_rstn:1;
        RBus_UInt32  sfg_osd_bisr_rstn:1;
        RBus_UInt32  sfg_bisr_rstn:1;
        RBus_UInt32  res1:25;
    };
}topbist_dispd_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_rstn:1;
        RBus_UInt32  img_demod_bisr_1_rstn:1;
        RBus_UInt32  img_demod_bisr_2_rstn:1;
        RBus_UInt32  img_demod_bisr_3_rstn:1;
        RBus_UInt32  img_demod_bisr_4_rstn:1;
        RBus_UInt32  img_demod_bisr_5_rstn:1;
        RBus_UInt32  res1:26;
    };
}topbist_dtv_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vcpu_bisr_rstn:1;
        RBus_UInt32  acpu_bisr_1_rstn:1;
        RBus_UInt32  acpu_bisr_2_rstn:1;
        RBus_UInt32  acpu_bisr_3_rstn:1;
        RBus_UInt32  a53_bisr_rstn:1;
        RBus_UInt32  vcpu2_bisr_rstn:1;
        RBus_UInt32  acpu2_bisr_1_rstn:1;
        RBus_UInt32  acpu2_bisr_2_rstn:1;
        RBus_UInt32  acpu2_bisr_3_rstn:1;
        RBus_UInt32  dummy18000f0c_10:1;
        RBus_UInt32  res2:21;
    };
}topbist_cpu_bisr_rstn_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_remap:1;
        RBus_UInt32  memc_bisr_remap_0:9;
        RBus_UInt32  memc_bisr_remap_1:1;
        RBus_UInt32  res1:21;
    };
}topbist_dispi_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_remap:1;
        RBus_UInt32  gdma_fbdc_000_remap:1;
        RBus_UInt32  gdma_fbdc_001_remap:1;
        RBus_UInt32  gdma_fbdc_002_remap:1;
        RBus_UInt32  gdma_fbdc_003_remap:1;
        RBus_UInt32  sfg_osd_bisr_remap:1;
        RBus_UInt32  sfg_bisr_remap:1;
        RBus_UInt32  res1:25;
    };
}topbist_dispd_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_remap:1;
        RBus_UInt32  img_demod_bisr_1_remap:1;
        RBus_UInt32  img_demod_bisr_2_remap:1;
        RBus_UInt32  img_demod_bisr_3_remap:1;
        RBus_UInt32  img_demod_bisr_4_remap:1;
        RBus_UInt32  img_demod_bisr_5_remap:1;
        RBus_UInt32  res1:26;
    };
}topbist_vp9_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vcpu_bisr_remap:1;
        RBus_UInt32  acpu_bisr_1_remap:1;
        RBus_UInt32  acpu_bisr_2_remap:1;
        RBus_UInt32  acpu_bisr_3_remap:1;
        RBus_UInt32  a53_bisr_remap:1;
        RBus_UInt32  vcpu2_bisr_remap:1;
        RBus_UInt32  acpu2_bisr_1_remap:1;
        RBus_UInt32  acpu2_bisr_2_remap:1;
        RBus_UInt32  acpu2_bisr_3_remap:1;
        RBus_UInt32  dummy18000f1c_10:1;
        RBus_UInt32  res2:21;
    };
}topbist_cpu_bisr_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spnr_bisr_done:1;
        RBus_UInt32  memc_bisr_done_0:9;
        RBus_UInt32  memc_bisr_done_1:1;
        RBus_UInt32  res1:21;
    };
}topbist_dispi_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shpnr_bisr_done:1;
        RBus_UInt32  gdma_fbdc_000_bisr_done:1;
        RBus_UInt32  gdma_fbdc_001_bisr_done:1;
        RBus_UInt32  gdma_fbdc_002_bisr_done:1;
        RBus_UInt32  gdma_fbdc_003_bisr_done:1;
        RBus_UInt32  sfg_osd_bisr_done:1;
        RBus_UInt32  sfg_bisr_done:1;
        RBus_UInt32  res1:25;
    };
}topbist_dispd_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_demod_bisr_0_done:1;
        RBus_UInt32  img_demod_bisr_1_done:1;
        RBus_UInt32  img_demod_bisr_2_done:1;
        RBus_UInt32  img_demod_bisr_3_done:1;
        RBus_UInt32  img_demod_bisr_4_done:1;
        RBus_UInt32  img_demod_bisr_5_done:1;
        RBus_UInt32  res1:26;
    };
}topbist_vp9_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vcpu_bisr_done:1;
        RBus_UInt32  acpu_bisr_1_done:1;
        RBus_UInt32  acpu_bisr_2_done:1;
        RBus_UInt32  acpu_bisr_3_done:1;
        RBus_UInt32  a53_bisr_done:1;
        RBus_UInt32  vcpu2_bisr_done:1;
        RBus_UInt32  acpu2_bisr_1_done:1;
        RBus_UInt32  acpu2_bisr_2_done:1;
        RBus_UInt32  acpu2_bisr_3_done:1;
        RBus_UInt32  emcu_bisr_done:1;
        RBus_UInt32  res2:21;
    };
}topbist_cpu_bisr_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_count_out:20;
        RBus_UInt32  rlvt_7t_ready:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rlvt_7t_wire_sel:1;
        RBus_UInt32  rlvt_7t_ro_sel:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  rlvt_7t_dss_rst_n:1;
    };
}topbist_ss_7t_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_wsort_go:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rlvt_7t_data_in:20;
        RBus_UInt32  rlvt_7t_speed_en:1;
        RBus_UInt32  res2:7;
    };
}topbist_ss_7t_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlvt_7t_dbgo:16;
        RBus_UInt32  res1:16;
    };
}topbist_ss_7t_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_bist_mode:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_bist_done:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_bist_fail_group:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_bist_fail0:1;
        RBus_UInt32  kcpu_bist_fail1:1;
        RBus_UInt32  kcpu_bist_fail2:1;
        RBus_UInt32  kcpu_bist_fail3:1;
        RBus_UInt32  kcpu_bist_fail4:1;
        RBus_UInt32  kcpu_bist_fail5:1;
        RBus_UInt32  kcpu_bist_fail6:1;
        RBus_UInt32  kcpu_bist_fail7:1;
        RBus_UInt32  kcpu_bist_fail8:1;
        RBus_UInt32  res1:23;
    };
}topbist_kcpu_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_drf_mode:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_drf_resume:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_drf_done:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_drf_pause:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_drf_fail_group:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_drf_fail0:1;
        RBus_UInt32  kcpu_drf_fail1:1;
        RBus_UInt32  kcpu_drf_fail2:1;
        RBus_UInt32  kcpu_drf_fail3:1;
        RBus_UInt32  kcpu_drf_fail4:1;
        RBus_UInt32  kcpu_drf_fail5:1;
        RBus_UInt32  kcpu_drf_fail6:1;
        RBus_UInt32  kcpu_drf_fail7:1;
        RBus_UInt32  kcpu_drf_fail8:1;
        RBus_UInt32  res1:23;
    };
}topbist_kcpu_drf_ooo_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_rme:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_rm:4;
        RBus_UInt32  res1:28;
    };
}topbist_kcpu_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_ls:1;
        RBus_UInt32  res1:31;
    };
}topbist_kcpu_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kcpu_bist_set_on:1;
        RBus_UInt32  vcpu_bist_set_on:1;
        RBus_UInt32  acpu_bist_set_on:1;
        RBus_UInt32  scpu_bist_set_on:1;
        RBus_UInt32  bridge_bist_set_on:1;
        RBus_UInt32  sb2_bist_set_on:1;
        RBus_UInt32  acpu2_bist_set_on:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  chip_bist_set_on:1;
    };
}topbist_bist_set_on_RBUS;




#endif 


#endif 
