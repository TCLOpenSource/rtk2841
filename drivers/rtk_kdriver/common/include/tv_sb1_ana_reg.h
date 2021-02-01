/**
* @file rbusTV_SB1_ANAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_TV_SB1_ANA_REG_H_
#define _RBUS_TV_SB1_ANA_REG_H_

#include "rbus_types.h"



//  TV_SB1_ANA Register Address
#define  TV_SB1_ANA_VDAC_VDBSO                                                   0x18033000
#define  TV_SB1_ANA_VDAC_VDBSO_reg_addr                                          "0xB8033000"
#define  TV_SB1_ANA_VDAC_VDBSO_reg                                               0xB8033000
#define  TV_SB1_ANA_VDAC_VDBSO_inst_addr                                         "0x0000"
#define  set_TV_SB1_ANA_VDAC_VDBSO_reg(data)                                     (*((volatile unsigned int*)TV_SB1_ANA_VDAC_VDBSO_reg)=data)
#define  get_TV_SB1_ANA_VDAC_VDBSO_reg                                           (*((volatile unsigned int*)TV_SB1_ANA_VDAC_VDBSO_reg))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powldv_shift                              (28)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powmbias_shift                            (24)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powvdac_shift                             (20)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_mbias_ibsel_shift                         (16)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_mbias_ibxsel_shift                        (12)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_bufgain_shift                         (8)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_dcc_shift                             (4)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_vcmsel_shift                          (0)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powldv_mask                               (0x10000000)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powmbias_mask                             (0x01000000)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powvdac_mask                              (0x00100000)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_mbias_ibsel_mask                          (0x00030000)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_mbias_ibxsel_mask                         (0x00003000)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_bufgain_mask                          (0x00000100)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_dcc_mask                              (0x00000010)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_vcmsel_mask                           (0x00000003)
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powldv(data)                              (0x10000000&((data)<<28))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powmbias(data)                            (0x01000000&((data)<<24))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_powvdac(data)                             (0x00100000&((data)<<20))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_mbias_ibsel(data)                         (0x00030000&((data)<<16))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_mbias_ibxsel(data)                        (0x00003000&((data)<<12))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_bufgain(data)                         (0x00000100&((data)<<8))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_dcc(data)                             (0x00000010&((data)<<4))
#define  TV_SB1_ANA_VDAC_VDBSO_reg_vid_ldv_vcmsel(data)                          (0x00000003&(data))
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_powldv(data)                          ((0x10000000&(data))>>28)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_powmbias(data)                        ((0x01000000&(data))>>24)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_powvdac(data)                         ((0x00100000&(data))>>20)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_mbias_ibsel(data)                     ((0x00030000&(data))>>16)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_mbias_ibxsel(data)                    ((0x00003000&(data))>>12)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_ldv_bufgain(data)                     ((0x00000100&(data))>>8)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_ldv_dcc(data)                         ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_VDAC_VDBSO_get_reg_vid_ldv_vcmsel(data)                      (0x00000003&(data))

#define  TV_SB1_ANA_VDAC                                                         0x18033004
#define  TV_SB1_ANA_VDAC_reg_addr                                                "0xB8033004"
#define  TV_SB1_ANA_VDAC_reg                                                     0xB8033004
#define  TV_SB1_ANA_VDAC_inst_addr                                               "0x0001"
#define  set_TV_SB1_ANA_VDAC_reg(data)                                           (*((volatile unsigned int*)TV_SB1_ANA_VDAC_reg)=data)
#define  get_TV_SB1_ANA_VDAC_reg                                                 (*((volatile unsigned int*)TV_SB1_ANA_VDAC_reg))
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_stby_shift                                  (28)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_biassel_shift                               (24)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_endrv_shift                                 (20)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_iqsel_shift                                 (16)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_odsel_shift                                 (12)
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_biassel_shift                              (8)
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_dcc_shift                                  (4)
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_stby_shift                                 (0)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_stby_mask                                   (0x10000000)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_biassel_mask                                (0x03000000)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_endrv_mask                                  (0x00100000)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_iqsel_mask                                  (0x00030000)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_odsel_mask                                  (0x00007000)
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_biassel_mask                               (0x00000300)
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_dcc_mask                                   (0x00000010)
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_stby_mask                                  (0x00000001)
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_stby(data)                                  (0x10000000&((data)<<28))
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_biassel(data)                               (0x03000000&((data)<<24))
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_endrv(data)                                 (0x00100000&((data)<<20))
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_iqsel(data)                                 (0x00030000&((data)<<16))
#define  TV_SB1_ANA_VDAC_reg_vid_ldv_odsel(data)                                 (0x00007000&((data)<<12))
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_biassel(data)                              (0x00000300&((data)<<8))
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_dcc(data)                                  (0x00000010&((data)<<4))
#define  TV_SB1_ANA_VDAC_reg_vid_vdac_stby(data)                                 (0x00000001&(data))
#define  TV_SB1_ANA_VDAC_get_reg_vid_ldv_stby(data)                              ((0x10000000&(data))>>28)
#define  TV_SB1_ANA_VDAC_get_reg_vid_ldv_biassel(data)                           ((0x03000000&(data))>>24)
#define  TV_SB1_ANA_VDAC_get_reg_vid_ldv_endrv(data)                             ((0x00100000&(data))>>20)
#define  TV_SB1_ANA_VDAC_get_reg_vid_ldv_iqsel(data)                             ((0x00030000&(data))>>16)
#define  TV_SB1_ANA_VDAC_get_reg_vid_ldv_odsel(data)                             ((0x00007000&(data))>>12)
#define  TV_SB1_ANA_VDAC_get_reg_vid_vdac_biassel(data)                          ((0x00000300&(data))>>8)
#define  TV_SB1_ANA_VDAC_get_reg_vid_vdac_dcc(data)                              ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_VDAC_get_reg_vid_vdac_stby(data)                             (0x00000001&(data))

#define  TV_SB1_ANA_VADC_IDACO_CTRL1                                             0x18033008
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_addr                                    "0xB8033008"
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg                                         0xB8033008
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_inst_addr                                   "0x0002"
#define  set_TV_SB1_ANA_VADC_IDACO_CTRL1_reg(data)                               (*((volatile unsigned int*)TV_SB1_ANA_VADC_IDACO_CTRL1_reg)=data)
#define  get_TV_SB1_ANA_VADC_IDACO_CTRL1_reg                                     (*((volatile unsigned int*)TV_SB1_ANA_VADC_IDACO_CTRL1_reg))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_vcmsel_shift                   (28)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_endrv_shift                    (24)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_iqsel_shift                    (20)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_odsel_shift                    (16)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_ckmode_shift                   (12)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_dacisel_shift                  (8)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_rsel_shift                     (4)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_csel_shift                     (0)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_vcmsel_mask                    (0x30000000)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_endrv_mask                     (0x01000000)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_iqsel_mask                     (0x00300000)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_odsel_mask                     (0x00070000)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_ckmode_mask                    (0x00001000)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_dacisel_mask                   (0x00000700)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_rsel_mask                      (0x00000030)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_csel_mask                      (0x00000003)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_vcmsel(data)                   (0x30000000&((data)<<28))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_endrv(data)                    (0x01000000&((data)<<24))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_iqsel(data)                    (0x00300000&((data)<<20))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_odsel(data)                    (0x00070000&((data)<<16))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_ckmode(data)                   (0x00001000&((data)<<12))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_dacisel(data)                  (0x00000700&((data)<<8))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_rsel(data)                     (0x00000030&((data)<<4))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_reg_vid_vdac_csel(data)                     (0x00000003&(data))
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_vcmsel(data)               ((0x30000000&(data))>>28)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_endrv(data)                ((0x01000000&(data))>>24)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_iqsel(data)                ((0x00300000&(data))>>20)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_odsel(data)                ((0x00070000&(data))>>16)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_ckmode(data)               ((0x00001000&(data))>>12)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_dacisel(data)              ((0x00000700&(data))>>8)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_rsel(data)                 ((0x00000030&(data))>>4)
#define  TV_SB1_ANA_VADC_IDACO_CTRL1_get_reg_vid_vdac_csel(data)                 (0x00000003&(data))

#define  TV_SB1_ANA_VDAC_SRC_SEL                                                 0x18033024
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_addr                                        "0xB8033024"
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg                                             0xB8033024
#define  TV_SB1_ANA_VDAC_SRC_SEL_inst_addr                                       "0x0003"
#define  set_TV_SB1_ANA_VDAC_SRC_SEL_reg(data)                                   (*((volatile unsigned int*)TV_SB1_ANA_VDAC_SRC_SEL_reg)=data)
#define  get_TV_SB1_ANA_VDAC_SRC_SEL_reg                                         (*((volatile unsigned int*)TV_SB1_ANA_VDAC_SRC_SEL_reg))
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_vdac_clk_polar_shift                        (4)
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_vdac_src_sel_shift                          (0)
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_vdac_clk_polar_mask                         (0x00000010)
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_vdac_src_sel_mask                           (0x00000007)
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_vdac_clk_polar(data)                        (0x00000010&((data)<<4))
#define  TV_SB1_ANA_VDAC_SRC_SEL_reg_vdac_src_sel(data)                          (0x00000007&(data))
#define  TV_SB1_ANA_VDAC_SRC_SEL_get_reg_vdac_clk_polar(data)                    ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_VDAC_SRC_SEL_get_reg_vdac_src_sel(data)                      (0x00000007&(data))

#define  TV_SB1_ANA_IFADC_CTRL1                                                  0x18033100
#define  TV_SB1_ANA_IFADC_CTRL1_reg_addr                                         "0xB8033100"
#define  TV_SB1_ANA_IFADC_CTRL1_reg                                              0xB8033100
#define  TV_SB1_ANA_IFADC_CTRL1_inst_addr                                        "0x0004"
#define  set_TV_SB1_ANA_IFADC_CTRL1_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL1_reg)=data)
#define  get_TV_SB1_ANA_IFADC_CTRL1_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL1_reg))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_svbwr_shift                            (28)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_adcpow_shift                           (24)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_meta_pow_shift                         (20)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_pow_mbias_shift                              (16)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_rssi_cl_shift                                (12)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_mbias_rssi_shift                             (10)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_bg_sel_shift                           (8)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_ifd_reserved_shift                           (0)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_svbwr_mask                             (0x30000000)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_adcpow_mask                            (0x01000000)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_meta_pow_mask                          (0x00100000)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_pow_mbias_mask                               (0x00010000)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_rssi_cl_mask                                 (0x00003000)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_mbias_rssi_mask                              (0x00000C00)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_bg_sel_mask                            (0x00000300)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_ifd_reserved_mask                            (0x000000FF)
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_svbwr(data)                            (0x30000000&((data)<<28))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_adcpow(data)                           (0x01000000&((data)<<24))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_meta_pow(data)                         (0x00100000&((data)<<20))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_pow_mbias(data)                              (0x00010000&((data)<<16))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_rssi_cl(data)                                (0x00003000&((data)<<12))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_mbias_rssi(data)                             (0x00000C00&((data)<<10))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_adc2x_bg_sel(data)                           (0x00000300&((data)<<8))
#define  TV_SB1_ANA_IFADC_CTRL1_reg_ifd_reserved(data)                           (0x000000FF&(data))
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_adc2x_svbwr(data)                        ((0x30000000&(data))>>28)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_adc2x_adcpow(data)                       ((0x01000000&(data))>>24)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_adc2x_meta_pow(data)                     ((0x00100000&(data))>>20)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_pow_mbias(data)                          ((0x00010000&(data))>>16)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_rssi_cl(data)                            ((0x00003000&(data))>>12)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_mbias_rssi(data)                         ((0x00000C00&(data))>>10)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_adc2x_bg_sel(data)                       ((0x00000300&(data))>>8)
#define  TV_SB1_ANA_IFADC_CTRL1_get_reg_ifd_reserved(data)                       (0x000000FF&(data))

#define  TV_SB1_ANA_IFADC_CTRL2                                                  0x18033104
#define  TV_SB1_ANA_IFADC_CTRL2_reg_addr                                         "0xB8033104"
#define  TV_SB1_ANA_IFADC_CTRL2_reg                                              0xB8033104
#define  TV_SB1_ANA_IFADC_CTRL2_inst_addr                                        "0x0005"
#define  set_TV_SB1_ANA_IFADC_CTRL2_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL2_reg)=data)
#define  get_TV_SB1_ANA_IFADC_CTRL2_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL2_reg))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_rssi_bias_shift                              (28)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_difpow_shift                           (24)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_mbias_isel_shift                             (20)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_fixgain_shift                          (16)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_rssi_lsadc_pow_shift                         (12)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_ifbw_shift                             (8)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_ifcmp_isel_shift                             (4)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_svbwc_shift                            (0)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_rssi_bias_mask                               (0x30000000)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_difpow_mask                            (0x01000000)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_mbias_isel_mask                              (0x00300000)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_fixgain_mask                           (0x000F0000)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_rssi_lsadc_pow_mask                          (0x00001000)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_ifbw_mask                              (0x00000300)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_ifcmp_isel_mask                              (0x00000070)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_svbwc_mask                             (0x00000003)
#define  TV_SB1_ANA_IFADC_CTRL2_reg_rssi_bias(data)                              (0x30000000&((data)<<28))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_difpow(data)                           (0x01000000&((data)<<24))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_mbias_isel(data)                             (0x00300000&((data)<<20))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_fixgain(data)                          (0x000F0000&((data)<<16))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_rssi_lsadc_pow(data)                         (0x00001000&((data)<<12))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_ifbw(data)                             (0x00000300&((data)<<8))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_ifcmp_isel(data)                             (0x00000070&((data)<<4))
#define  TV_SB1_ANA_IFADC_CTRL2_reg_adc2x_svbwc(data)                            (0x00000003&(data))
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_rssi_bias(data)                          ((0x30000000&(data))>>28)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_adc2x_difpow(data)                       ((0x01000000&(data))>>24)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_mbias_isel(data)                         ((0x00300000&(data))>>20)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_adc2x_fixgain(data)                      ((0x000F0000&(data))>>16)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_rssi_lsadc_pow(data)                     ((0x00001000&(data))>>12)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_adc2x_ifbw(data)                         ((0x00000300&(data))>>8)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_ifcmp_isel(data)                         ((0x00000070&(data))>>4)
#define  TV_SB1_ANA_IFADC_CTRL2_get_reg_adc2x_svbwc(data)                        (0x00000003&(data))

#define  TV_SB1_ANA_IFADC_CTRL3                                                  0x18033108
#define  TV_SB1_ANA_IFADC_CTRL3_reg_addr                                         "0xB8033108"
#define  TV_SB1_ANA_IFADC_CTRL3_reg                                              0xB8033108
#define  TV_SB1_ANA_IFADC_CTRL3_inst_addr                                        "0x0006"
#define  set_TV_SB1_ANA_IFADC_CTRL3_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL3_reg)=data)
#define  get_TV_SB1_ANA_IFADC_CTRL3_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL3_reg))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_insel_shift                            (24)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_lsadc_cksel_shift                            (20)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_lsadc_div_shift                              (16)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_mbias_lsadc_shift                            (12)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_ckout_div_shift                        (8)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_vref_sel_shift                         (4)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_ifd_ckin_sel_shift                           (0)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_insel_mask                             (0x01000000)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_lsadc_cksel_mask                             (0x00100000)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_lsadc_div_mask                               (0x00030000)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_mbias_lsadc_mask                             (0x00003000)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_ckout_div_mask                         (0x00000300)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_vref_sel_mask                          (0x00000030)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_ifd_ckin_sel_mask                            (0x00000003)
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_insel(data)                            (0x01000000&((data)<<24))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_lsadc_cksel(data)                            (0x00100000&((data)<<20))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_lsadc_div(data)                              (0x00030000&((data)<<16))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_mbias_lsadc(data)                            (0x00003000&((data)<<12))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_ckout_div(data)                        (0x00000300&((data)<<8))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_adc2x_vref_sel(data)                         (0x00000030&((data)<<4))
#define  TV_SB1_ANA_IFADC_CTRL3_reg_ifd_ckin_sel(data)                           (0x00000003&(data))
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_adc2x_insel(data)                        ((0x01000000&(data))>>24)
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_lsadc_cksel(data)                        ((0x00100000&(data))>>20)
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_lsadc_div(data)                          ((0x00030000&(data))>>16)
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_mbias_lsadc(data)                        ((0x00003000&(data))>>12)
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_adc2x_ckout_div(data)                    ((0x00000300&(data))>>8)
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_adc2x_vref_sel(data)                     ((0x00000030&(data))>>4)
#define  TV_SB1_ANA_IFADC_CTRL3_get_reg_ifd_ckin_sel(data)                       (0x00000003&(data))

#define  TV_SB1_ANA_IFADC_CTRL4                                                  0x1803310C
#define  TV_SB1_ANA_IFADC_CTRL4_reg_addr                                         "0xB803310C"
#define  TV_SB1_ANA_IFADC_CTRL4_reg                                              0xB803310C
#define  TV_SB1_ANA_IFADC_CTRL4_inst_addr                                        "0x0007"
#define  set_TV_SB1_ANA_IFADC_CTRL4_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL4_reg)=data)
#define  get_TV_SB1_ANA_IFADC_CTRL4_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL4_reg))
#define  TV_SB1_ANA_IFADC_CTRL4_reg_mbias_ifpga_shift                            (20)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_servopow2_shift                        (16)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_ldo_sel_shift                          (12)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_ckout_edge_shift                       (8)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_delay_shift                            (4)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_servo_shift                            (0)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_mbias_ifpga_mask                             (0xFFF00000)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_servopow2_mask                         (0x00010000)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_ldo_sel_mask                           (0x00003000)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_ckout_edge_mask                        (0x00000100)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_delay_mask                             (0x00000010)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_servo_mask                             (0x00000003)
#define  TV_SB1_ANA_IFADC_CTRL4_reg_mbias_ifpga(data)                            (0xFFF00000&((data)<<20))
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_servopow2(data)                        (0x00010000&((data)<<16))
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_ldo_sel(data)                          (0x00003000&((data)<<12))
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_ckout_edge(data)                       (0x00000100&((data)<<8))
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_delay(data)                            (0x00000010&((data)<<4))
#define  TV_SB1_ANA_IFADC_CTRL4_reg_adc2x_servo(data)                            (0x00000003&(data))
#define  TV_SB1_ANA_IFADC_CTRL4_get_reg_mbias_ifpga(data)                        ((0xFFF00000&(data))>>20)
#define  TV_SB1_ANA_IFADC_CTRL4_get_reg_adc2x_servopow2(data)                    ((0x00010000&(data))>>16)
#define  TV_SB1_ANA_IFADC_CTRL4_get_reg_adc2x_ldo_sel(data)                      ((0x00003000&(data))>>12)
#define  TV_SB1_ANA_IFADC_CTRL4_get_reg_adc2x_ckout_edge(data)                   ((0x00000100&(data))>>8)
#define  TV_SB1_ANA_IFADC_CTRL4_get_reg_adc2x_delay(data)                        ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_IFADC_CTRL4_get_reg_adc2x_servo(data)                        (0x00000003&(data))

#define  TV_SB1_ANA_IFADC_CTRL5                                                  0x18033110
#define  TV_SB1_ANA_IFADC_CTRL5_reg_addr                                         "0xB8033110"
#define  TV_SB1_ANA_IFADC_CTRL5_reg                                              0xB8033110
#define  TV_SB1_ANA_IFADC_CTRL5_inst_addr                                        "0x0008"
#define  set_TV_SB1_ANA_IFADC_CTRL5_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL5_reg)=data)
#define  get_TV_SB1_ANA_IFADC_CTRL5_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IFADC_CTRL5_reg))
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg12_pow_shift                  (12)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg3_pow_shift                   (8)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_sif_in_sel_shift                       (4)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg3_in_sel_shift                (0)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg12_pow_mask                   (0x00001000)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg3_pow_mask                    (0x00000100)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_sif_in_sel_mask                        (0x00000010)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg3_in_sel_mask                 (0x00000001)
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg12_pow(data)                  (0x00001000&((data)<<12))
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg3_pow(data)                   (0x00000100&((data)<<8))
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_sif_in_sel(data)                       (0x00000010&((data)<<4))
#define  TV_SB1_ANA_IFADC_CTRL5_reg_adc2x_ifpga_stg3_in_sel(data)                (0x00000001&(data))
#define  TV_SB1_ANA_IFADC_CTRL5_get_reg_adc2x_ifpga_stg12_pow(data)              ((0x00001000&(data))>>12)
#define  TV_SB1_ANA_IFADC_CTRL5_get_reg_adc2x_ifpga_stg3_pow(data)               ((0x00000100&(data))>>8)
#define  TV_SB1_ANA_IFADC_CTRL5_get_reg_adc2x_sif_in_sel(data)                   ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_IFADC_CTRL5_get_reg_adc2x_ifpga_stg3_in_sel(data)            (0x00000001&(data))

#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL                                           0x18033114
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_addr                                  "0xB8033114"
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg                                       0xB8033114
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_inst_addr                                 "0x0009"
#define  set_TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg(data)                             (*((volatile unsigned int*)TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg)=data)
#define  get_TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg                                   (*((volatile unsigned int*)TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg))
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_adc2x_vcm_sel_shift                   (4)
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_agc_pga_src_sel_shift                 (0)
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_adc2x_vcm_sel_mask                    (0x00000010)
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_agc_pga_src_sel_mask                  (0x00000001)
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_adc2x_vcm_sel(data)                   (0x00000010&((data)<<4))
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_reg_agc_pga_src_sel(data)                 (0x00000001&(data))
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_get_reg_adc2x_vcm_sel(data)               ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_IFADC_AGC_PGA_CTRL_get_reg_agc_pga_src_sel(data)             (0x00000001&(data))

#define  TV_SB1_ANA_IQADC_CTRL0                                                  0x18033118
#define  TV_SB1_ANA_IQADC_CTRL0_reg_addr                                         "0xB8033118"
#define  TV_SB1_ANA_IQADC_CTRL0_reg                                              0xB8033118
#define  TV_SB1_ANA_IQADC_CTRL0_inst_addr                                        "0x000A"
#define  set_TV_SB1_ANA_IQADC_CTRL0_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL0_reg)=data)
#define  get_TV_SB1_ANA_IQADC_CTRL0_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL0_reg))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_vref_shift                            (28)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_en_shift                              (24)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_div_shift                             (20)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_bw_shift                                  (16)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_q_ckout_edge_shift                           (12)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_i_ckout_edge_shift                           (8)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_ckout_sel_q_shift                            (4)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_ckout_sel_i_shift                            (0)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_vref_mask                             (0x70000000)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_en_mask                               (0x01000000)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_div_mask                              (0x00300000)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_bw_mask                                   (0x00030000)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_q_ckout_edge_mask                            (0x00001000)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_i_ckout_edge_mask                            (0x00000100)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_ckout_sel_q_mask                             (0x00000010)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_ckout_sel_i_mask                             (0x00000001)
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_vref(data)                            (0x70000000&((data)<<28))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_en(data)                              (0x01000000&((data)<<24))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_cal_div(data)                             (0x00300000&((data)<<20))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_iq_bw(data)                                  (0x00030000&((data)<<16))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_q_ckout_edge(data)                           (0x00001000&((data)<<12))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_i_ckout_edge(data)                           (0x00000100&((data)<<8))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_ckout_sel_q(data)                            (0x00000010&((data)<<4))
#define  TV_SB1_ANA_IQADC_CTRL0_reg_ckout_sel_i(data)                            (0x00000001&(data))
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_iq_cal_vref(data)                        ((0x70000000&(data))>>28)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_iq_cal_en(data)                          ((0x01000000&(data))>>24)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_iq_cal_div(data)                         ((0x00300000&(data))>>20)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_iq_bw(data)                              ((0x00030000&(data))>>16)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_q_ckout_edge(data)                       ((0x00001000&(data))>>12)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_i_ckout_edge(data)                       ((0x00000100&(data))>>8)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_ckout_sel_q(data)                        ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_IQADC_CTRL0_get_reg_ckout_sel_i(data)                        (0x00000001&(data))

#define  TV_SB1_ANA_IQADC_CTRL1                                                  0x1803311C
#define  TV_SB1_ANA_IQADC_CTRL1_reg_addr                                         "0xB803311C"
#define  TV_SB1_ANA_IQADC_CTRL1_reg                                              0xB803311C
#define  TV_SB1_ANA_IQADC_CTRL1_inst_addr                                        "0x000B"
#define  set_TV_SB1_ANA_IQADC_CTRL1_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL1_reg)=data)
#define  get_TV_SB1_ANA_IQADC_CTRL1_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL1_reg))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_meta_pow_shift                            (28)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ldo_sel_shift                             (24)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_fix_gain_shift                            (20)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_duty_sel_shift                            (16)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_delay_en_shift                            (12)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_d_shift                                   (8)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ckout_div_shift                           (4)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ckin_sel_shift                            (0)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_meta_pow_mask                             (0x10000000)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ldo_sel_mask                              (0x07000000)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_fix_gain_mask                             (0x00700000)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_duty_sel_mask                             (0x00070000)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_delay_en_mask                             (0x00001000)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_d_mask                                    (0x00000F00)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ckout_div_mask                            (0x00000030)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ckin_sel_mask                             (0x00000003)
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_meta_pow(data)                            (0x10000000&((data)<<28))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ldo_sel(data)                             (0x07000000&((data)<<24))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_fix_gain(data)                            (0x00700000&((data)<<20))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_duty_sel(data)                            (0x00070000&((data)<<16))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_delay_en(data)                            (0x00001000&((data)<<12))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_d(data)                                   (0x00000F00&((data)<<8))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ckout_div(data)                           (0x00000030&((data)<<4))
#define  TV_SB1_ANA_IQADC_CTRL1_reg_iq_ckin_sel(data)                            (0x00000003&(data))
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_meta_pow(data)                        ((0x10000000&(data))>>28)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_ldo_sel(data)                         ((0x07000000&(data))>>24)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_fix_gain(data)                        ((0x00700000&(data))>>20)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_duty_sel(data)                        ((0x00070000&(data))>>16)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_delay_en(data)                        ((0x00001000&(data))>>12)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_d(data)                               ((0x00000F00&(data))>>8)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_ckout_div(data)                       ((0x00000030&(data))>>4)
#define  TV_SB1_ANA_IQADC_CTRL1_get_reg_iq_ckin_sel(data)                        (0x00000003&(data))

#define  TV_SB1_ANA_IQADC_CTRL2                                                  0x18033120
#define  TV_SB1_ANA_IQADC_CTRL2_reg_addr                                         "0xB8033120"
#define  TV_SB1_ANA_IQADC_CTRL2_reg                                              0xB8033120
#define  TV_SB1_ANA_IQADC_CTRL2_inst_addr                                        "0x000C"
#define  set_TV_SB1_ANA_IQADC_CTRL2_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL2_reg)=data)
#define  get_TV_SB1_ANA_IQADC_CTRL2_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL2_reg))
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iqcmp_isel_shift                             (20)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iqcal_isel_shift                             (16)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_vref_sel_shift                            (8)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_single_end_en_shift                       (4)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_pre_set_shift                             (0)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iqcmp_isel_mask                              (0x00700000)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iqcal_isel_mask                              (0x00070000)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_vref_sel_mask                             (0x00000300)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_single_end_en_mask                        (0x00000010)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_pre_set_mask                              (0x00000001)
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iqcmp_isel(data)                             (0x00700000&((data)<<20))
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iqcal_isel(data)                             (0x00070000&((data)<<16))
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_vref_sel(data)                            (0x00000300&((data)<<8))
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_single_end_en(data)                       (0x00000010&((data)<<4))
#define  TV_SB1_ANA_IQADC_CTRL2_reg_iq_pre_set(data)                             (0x00000001&(data))
#define  TV_SB1_ANA_IQADC_CTRL2_get_reg_iqcmp_isel(data)                         ((0x00700000&(data))>>20)
#define  TV_SB1_ANA_IQADC_CTRL2_get_reg_iqcal_isel(data)                         ((0x00070000&(data))>>16)
#define  TV_SB1_ANA_IQADC_CTRL2_get_reg_iq_vref_sel(data)                        ((0x00000300&(data))>>8)
#define  TV_SB1_ANA_IQADC_CTRL2_get_reg_iq_single_end_en(data)                   ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_IQADC_CTRL2_get_reg_iq_pre_set(data)                         (0x00000001&(data))

#define  TV_SB1_ANA_IQADC_CTRL3                                                  0x18033124
#define  TV_SB1_ANA_IQADC_CTRL3_reg_addr                                         "0xB8033124"
#define  TV_SB1_ANA_IQADC_CTRL3_reg                                              0xB8033124
#define  TV_SB1_ANA_IQADC_CTRL3_inst_addr                                        "0x000D"
#define  set_TV_SB1_ANA_IQADC_CTRL3_reg(data)                                    (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL3_reg)=data)
#define  get_TV_SB1_ANA_IQADC_CTRL3_reg                                          (*((volatile unsigned int*)TV_SB1_ANA_IQADC_CTRL3_reg))
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_q_pga_shift                              (12)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_i_pga_shift                              (8)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_q_adc_shift                              (4)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_i_adc_shift                              (0)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_q_pga_mask                               (0x00001000)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_i_pga_mask                               (0x00000100)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_q_adc_mask                               (0x00000010)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_i_adc_mask                               (0x00000001)
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_q_pga(data)                              (0x00001000&((data)<<12))
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_i_pga(data)                              (0x00000100&((data)<<8))
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_q_adc(data)                              (0x00000010&((data)<<4))
#define  TV_SB1_ANA_IQADC_CTRL3_reg_pow_i_adc(data)                              (0x00000001&(data))
#define  TV_SB1_ANA_IQADC_CTRL3_get_reg_pow_q_pga(data)                          ((0x00001000&(data))>>12)
#define  TV_SB1_ANA_IQADC_CTRL3_get_reg_pow_i_pga(data)                          ((0x00000100&(data))>>8)
#define  TV_SB1_ANA_IQADC_CTRL3_get_reg_pow_q_adc(data)                          ((0x00000010&(data))>>4)
#define  TV_SB1_ANA_IQADC_CTRL3_get_reg_pow_i_adc(data)                          (0x00000001&(data))

#define  TV_SB1_ANA_IFADC_GAIN_CTRL                                              0x18033128
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_addr                                     "0xB8033128"
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg                                          0xB8033128
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_inst_addr                                    "0x000E"
#define  set_TV_SB1_ANA_IFADC_GAIN_CTRL_reg(data)                                (*((volatile unsigned int*)TV_SB1_ANA_IFADC_GAIN_CTRL_reg)=data)
#define  get_TV_SB1_ANA_IFADC_GAIN_CTRL_reg                                      (*((volatile unsigned int*)TV_SB1_ANA_IFADC_GAIN_CTRL_reg))
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga3_shift                        (12)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga2_shift                        (8)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga1_shift                        (4)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_fix_en_shift                          (0)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga3_mask                         (0x0000F000)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga2_mask                         (0x00000700)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga1_mask                         (0x00000030)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_fix_en_mask                           (0x00000001)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga3(data)                        (0x0000F000&((data)<<12))
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga2(data)                        (0x00000700&((data)<<8))
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_agc_pga1(data)                        (0x00000030&((data)<<4))
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_reg_if_fix_en(data)                          (0x00000001&(data))
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_get_reg_if_agc_pga3(data)                    ((0x0000F000&(data))>>12)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_get_reg_if_agc_pga2(data)                    ((0x00000700&(data))>>8)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_get_reg_if_agc_pga1(data)                    ((0x00000030&(data))>>4)
#define  TV_SB1_ANA_IFADC_GAIN_CTRL_get_reg_if_fix_en(data)                      (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======TV_SB1_ANA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_vid_powldv:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_powmbias:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_vid_powvdac:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_vid_mbias_ibsel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_vid_mbias_ibxsel:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_vid_ldv_bufgain:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_ldv_dcc:1;
        RBus_UInt32  res8:2;
        RBus_UInt32  reg_vid_ldv_vcmsel:2;
    };
}tv_sb1_ana_vdac_vdbso_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_vid_ldv_stby:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vid_ldv_biassel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_vid_ldv_endrv:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_vid_ldv_iqsel:2;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_vid_ldv_odsel:3;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_vid_vdac_biassel:2;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_vdac_dcc:1;
        RBus_UInt32  res8:3;
        RBus_UInt32  reg_vid_vdac_stby:1;
    };
}tv_sb1_ana_vdac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vid_vdac_vcmsel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_vdac_endrv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_vid_vdac_iqsel:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_vid_vdac_odsel:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_vid_vdac_ckmode:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_vid_vdac_dacisel:3;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_vid_vdac_rsel:2;
        RBus_UInt32  res8:2;
        RBus_UInt32  reg_vid_vdac_csel:2;
    };
}tv_sb1_ana_vadc_idaco_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_vdac_clk_polar:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_vdac_src_sel:3;
    };
}tv_sb1_ana_vdac_src_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_adc2x_svbwr:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_adcpow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_meta_pow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_pow_mbias:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_rssi_cl:2;
        RBus_UInt32  reg_mbias_rssi:2;
        RBus_UInt32  reg_adc2x_bg_sel:2;
        RBus_UInt32  reg_ifd_reserved:8;
    };
}tv_sb1_ana_ifadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_rssi_bias:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_difpow:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_mbias_isel:2;
        RBus_UInt32  reg_adc2x_fixgain:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_rssi_lsadc_pow:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_ifbw:2;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_ifcmp_isel:3;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_adc2x_svbwc:2;
    };
}tv_sb1_ana_ifadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_adc2x_insel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_lsadc_cksel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_lsadc_div:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_mbias_lsadc:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_ckout_div:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_adc2x_vref_sel:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_ifd_ckin_sel:2;
    };
}tv_sb1_ana_ifadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mbias_ifpga:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_adc2x_servopow2:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_adc2x_ldo_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_ckout_edge:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_delay:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_servo:2;
    };
}tv_sb1_ana_ifadc_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  reg_adc2x_ifpga_stg12_pow:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_ifpga_stg3_pow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_sif_in_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_ifpga_stg3_in_sel:1;
    };
}tv_sb1_ana_ifadc_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  reg_adc2x_vcm_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_agc_pga_src_sel:1;
    };
}tv_sb1_ana_ifadc_agc_pga_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_iq_cal_vref:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_iq_cal_en:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_iq_cal_div:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_iq_bw:2;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_q_ckout_edge:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_i_ckout_edge:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_ckout_sel_q:1;
        RBus_UInt32  res8:3;
        RBus_UInt32  reg_ckout_sel_i:1;
    };
}tv_sb1_ana_iqadc_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_iq_meta_pow:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_iq_ldo_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_iq_fix_gain:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_iq_duty_sel:3;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_iq_delay_en:1;
        RBus_UInt32  reg_iq_d:4;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_iq_ckout_div:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_iq_ckin_sel:2;
    };
}tv_sb1_ana_iqadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  reg_iqcmp_isel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_iqcal_isel:3;
        RBus_UInt32  res3:6;
        RBus_UInt32  reg_iq_vref_sel:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_iq_single_end_en:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_iq_pre_set:1;
    };
}tv_sb1_ana_iqadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  reg_pow_q_pga:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_pow_i_pga:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_pow_q_adc:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_pow_i_adc:1;
    };
}tv_sb1_ana_iqadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_if_agc_pga3:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_if_agc_pga2:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_if_agc_pga1:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_if_fix_en:1;
    };
}tv_sb1_ana_ifadc_gain_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======TV_SB1_ANA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vid_ldv_vcmsel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vid_ldv_dcc:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_ldv_bufgain:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_vid_mbias_ibxsel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_vid_mbias_ibsel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_vid_powvdac:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_vid_powmbias:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_powldv:1;
        RBus_UInt32  res8:3;
    };
}tv_sb1_ana_vdac_vdbso_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vid_vdac_stby:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_vid_vdac_dcc:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_vid_vdac_biassel:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_vid_ldv_odsel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_vid_ldv_iqsel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_vid_ldv_endrv:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_vid_ldv_biassel:2;
        RBus_UInt32  res7:2;
        RBus_UInt32  reg_vid_ldv_stby:1;
        RBus_UInt32  res8:3;
    };
}tv_sb1_ana_vdac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vid_vdac_csel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vid_vdac_rsel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vid_vdac_dacisel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_vid_vdac_ckmode:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_vid_vdac_odsel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_vid_vdac_iqsel:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_vid_vdac_endrv:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_vid_vdac_vcmsel:2;
        RBus_UInt32  res8:2;
    };
}tv_sb1_ana_vadc_idaco_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vdac_src_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_vdac_clk_polar:1;
        RBus_UInt32  res2:27;
    };
}tv_sb1_ana_vdac_src_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ifd_reserved:8;
        RBus_UInt32  reg_adc2x_bg_sel:2;
        RBus_UInt32  reg_mbias_rssi:2;
        RBus_UInt32  reg_rssi_cl:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_pow_mbias:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_meta_pow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_adcpow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_svbwr:2;
        RBus_UInt32  res5:2;
    };
}tv_sb1_ana_ifadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc2x_svbwc:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_ifcmp_isel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_adc2x_ifbw:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_rssi_lsadc_pow:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_adc2x_fixgain:4;
        RBus_UInt32  reg_mbias_isel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_adc2x_difpow:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_rssi_bias:2;
        RBus_UInt32  res7:2;
    };
}tv_sb1_ana_ifadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ifd_ckin_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_adc2x_vref_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_adc2x_ckout_div:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_mbias_lsadc:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_lsadc_div:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_lsadc_cksel:1;
        RBus_UInt32  res6:3;
        RBus_UInt32  reg_adc2x_insel:1;
        RBus_UInt32  res7:7;
    };
}tv_sb1_ana_ifadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc2x_servo:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_adc2x_delay:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_ckout_edge:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_ldo_sel:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_adc2x_servopow2:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  reg_mbias_ifpga:12;
    };
}tv_sb1_ana_ifadc_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_adc2x_ifpga_stg3_in_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_adc2x_sif_in_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_adc2x_ifpga_stg3_pow:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_adc2x_ifpga_stg12_pow:1;
        RBus_UInt32  res4:19;
    };
}tv_sb1_ana_ifadc_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_agc_pga_src_sel:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_adc2x_vcm_sel:1;
        RBus_UInt32  res2:27;
    };
}tv_sb1_ana_ifadc_agc_pga_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_ckout_sel_i:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_ckout_sel_q:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_i_ckout_edge:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_q_ckout_edge:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_iq_bw:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  reg_iq_cal_div:2;
        RBus_UInt32  res6:2;
        RBus_UInt32  reg_iq_cal_en:1;
        RBus_UInt32  res7:3;
        RBus_UInt32  reg_iq_cal_vref:3;
        RBus_UInt32  res8:1;
    };
}tv_sb1_ana_iqadc_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_iq_ckin_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_iq_ckout_div:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_iq_d:4;
        RBus_UInt32  reg_iq_delay_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_iq_duty_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_iq_fix_gain:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  reg_iq_ldo_sel:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  reg_iq_meta_pow:1;
        RBus_UInt32  res7:3;
    };
}tv_sb1_ana_iqadc_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_iq_pre_set:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_iq_single_end_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_iq_vref_sel:2;
        RBus_UInt32  res3:6;
        RBus_UInt32  reg_iqcal_isel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  reg_iqcmp_isel:3;
        RBus_UInt32  res5:9;
    };
}tv_sb1_ana_iqadc_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_pow_i_adc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_pow_q_adc:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_pow_i_pga:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  reg_pow_q_pga:1;
        RBus_UInt32  res4:19;
    };
}tv_sb1_ana_iqadc_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_if_fix_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_if_agc_pga1:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_if_agc_pga2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_if_agc_pga3:4;
        RBus_UInt32  res4:16;
    };
}tv_sb1_ana_ifadc_gain_ctrl_RBUS;




#endif 


#endif 
