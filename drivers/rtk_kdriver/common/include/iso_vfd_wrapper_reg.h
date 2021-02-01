/**
* @file rbusIso_vfd_wrapperReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ISO_VFD_WRAPPER_REG_H_
#define _RBUS_ISO_VFD_WRAPPER_REG_H_

#include "rbus_types.h"



//  ISO_VFD_WRAPPER Register Address
#define  ISO_VFD_WRAPPER_VFD_CTL                                                 0x18061600
#define  ISO_VFD_WRAPPER_VFD_CTL_reg_addr                                        "0xB8061600"
#define  ISO_VFD_WRAPPER_VFD_CTL_reg                                             0xB8061600
#define  ISO_VFD_WRAPPER_VFD_CTL_inst_addr                                       "0x0000"
#define  set_ISO_VFD_WRAPPER_VFD_CTL_reg(data)                                   (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_CTL_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_CTL_reg                                         (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_CTL_reg))
#define  ISO_VFD_WRAPPER_VFD_CTL_kpaden_shift                                    (3)
#define  ISO_VFD_WRAPPER_VFD_CTL_swen_shift                                      (2)
#define  ISO_VFD_WRAPPER_VFD_CTL_clksel_shift                                    (1)
#define  ISO_VFD_WRAPPER_VFD_CTL_envfd_shift                                     (0)
#define  ISO_VFD_WRAPPER_VFD_CTL_kpaden_mask                                     (0x00000008)
#define  ISO_VFD_WRAPPER_VFD_CTL_swen_mask                                       (0x00000004)
#define  ISO_VFD_WRAPPER_VFD_CTL_clksel_mask                                     (0x00000002)
#define  ISO_VFD_WRAPPER_VFD_CTL_envfd_mask                                      (0x00000001)
#define  ISO_VFD_WRAPPER_VFD_CTL_kpaden(data)                                    (0x00000008&((data)<<3))
#define  ISO_VFD_WRAPPER_VFD_CTL_swen(data)                                      (0x00000004&((data)<<2))
#define  ISO_VFD_WRAPPER_VFD_CTL_clksel(data)                                    (0x00000002&((data)<<1))
#define  ISO_VFD_WRAPPER_VFD_CTL_envfd(data)                                     (0x00000001&(data))
#define  ISO_VFD_WRAPPER_VFD_CTL_get_kpaden(data)                                ((0x00000008&(data))>>3)
#define  ISO_VFD_WRAPPER_VFD_CTL_get_swen(data)                                  ((0x00000004&(data))>>2)
#define  ISO_VFD_WRAPPER_VFD_CTL_get_clksel(data)                                ((0x00000002&(data))>>1)
#define  ISO_VFD_WRAPPER_VFD_CTL_get_envfd(data)                                 (0x00000001&(data))

#define  ISO_VFD_WRAPPER_VFD_WRCTL                                               0x18061604
#define  ISO_VFD_WRAPPER_VFD_WRCTL_reg_addr                                      "0xB8061604"
#define  ISO_VFD_WRAPPER_VFD_WRCTL_reg                                           0xB8061604
#define  ISO_VFD_WRAPPER_VFD_WRCTL_inst_addr                                     "0x0001"
#define  set_ISO_VFD_WRAPPER_VFD_WRCTL_reg(data)                                 (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_WRCTL_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_WRCTL_reg                                       (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_WRCTL_reg))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_nact_csn_shift                                (12)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b3c_shift                                     (11)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b2c_shift                                     (10)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b1c_shift                                     (9)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b0c_shift                                     (8)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb3_shift                                    (7)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb2_shift                                    (6)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb1_shift                                    (5)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb0_shift                                    (4)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_wd_shift                                      (1)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_wdie_shift                                    (0)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_nact_csn_mask                                 (0x00001000)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b3c_mask                                      (0x00000800)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b2c_mask                                      (0x00000400)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b1c_mask                                      (0x00000200)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b0c_mask                                      (0x00000100)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb3_mask                                     (0x00000080)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb2_mask                                     (0x00000040)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb1_mask                                     (0x00000020)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb0_mask                                     (0x00000010)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_wd_mask                                       (0x00000002)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_wdie_mask                                     (0x00000001)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_nact_csn(data)                                (0x00001000&((data)<<12))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b3c(data)                                     (0x00000800&((data)<<11))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b2c(data)                                     (0x00000400&((data)<<10))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b1c(data)                                     (0x00000200&((data)<<9))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_b0c(data)                                     (0x00000100&((data)<<8))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb3(data)                                    (0x00000080&((data)<<7))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb2(data)                                    (0x00000040&((data)<<6))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb1(data)                                    (0x00000020&((data)<<5))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_enb0(data)                                    (0x00000010&((data)<<4))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_wd(data)                                      (0x00000002&((data)<<1))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_wdie(data)                                    (0x00000001&(data))
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_nact_csn(data)                            ((0x00001000&(data))>>12)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_b3c(data)                                 ((0x00000800&(data))>>11)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_b2c(data)                                 ((0x00000400&(data))>>10)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_b1c(data)                                 ((0x00000200&(data))>>9)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_b0c(data)                                 ((0x00000100&(data))>>8)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_enb3(data)                                ((0x00000080&(data))>>7)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_enb2(data)                                ((0x00000040&(data))>>6)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_enb1(data)                                ((0x00000020&(data))>>5)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_enb0(data)                                ((0x00000010&(data))>>4)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_wd(data)                                  ((0x00000002&(data))>>1)
#define  ISO_VFD_WRAPPER_VFD_WRCTL_get_wdie(data)                                (0x00000001&(data))

#define  ISO_VFD_WRAPPER_VFDO                                                    0x18061608
#define  ISO_VFD_WRAPPER_VFDO_reg_addr                                           "0xB8061608"
#define  ISO_VFD_WRAPPER_VFDO_reg                                                0xB8061608
#define  ISO_VFD_WRAPPER_VFDO_inst_addr                                          "0x0002"
#define  set_ISO_VFD_WRAPPER_VFDO_reg(data)                                      (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFDO_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFDO_reg                                            (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFDO_reg))
#define  ISO_VFD_WRAPPER_VFDO_byte3_shift                                        (24)
#define  ISO_VFD_WRAPPER_VFDO_byte2_shift                                        (16)
#define  ISO_VFD_WRAPPER_VFDO_byte1_shift                                        (8)
#define  ISO_VFD_WRAPPER_VFDO_byte0_shift                                        (0)
#define  ISO_VFD_WRAPPER_VFDO_byte3_mask                                         (0xFF000000)
#define  ISO_VFD_WRAPPER_VFDO_byte2_mask                                         (0x00FF0000)
#define  ISO_VFD_WRAPPER_VFDO_byte1_mask                                         (0x0000FF00)
#define  ISO_VFD_WRAPPER_VFDO_byte0_mask                                         (0x000000FF)
#define  ISO_VFD_WRAPPER_VFDO_byte3(data)                                        (0xFF000000&((data)<<24))
#define  ISO_VFD_WRAPPER_VFDO_byte2(data)                                        (0x00FF0000&((data)<<16))
#define  ISO_VFD_WRAPPER_VFDO_byte1(data)                                        (0x0000FF00&((data)<<8))
#define  ISO_VFD_WRAPPER_VFDO_byte0(data)                                        (0x000000FF&(data))
#define  ISO_VFD_WRAPPER_VFDO_get_byte3(data)                                    ((0xFF000000&(data))>>24)
#define  ISO_VFD_WRAPPER_VFDO_get_byte2(data)                                    ((0x00FF0000&(data))>>16)
#define  ISO_VFD_WRAPPER_VFDO_get_byte1(data)                                    ((0x0000FF00&(data))>>8)
#define  ISO_VFD_WRAPPER_VFDO_get_byte0(data)                                    (0x000000FF&(data))

#define  ISO_VFD_WRAPPER_VFD_ARDCTL                                              0x1806160C
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_reg_addr                                     "0xB806160C"
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_reg                                          0xB806160C
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_inst_addr                                    "0x0003"
#define  set_ISO_VFD_WRAPPER_VFD_ARDCTL_reg(data)                                (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDCTL_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_ARDCTL_reg                                      (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDCTL_reg))
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_kpadbn_shift                                 (8)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_swha_shift                                   (5)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_kpadha_shift                                 (4)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_ardp_shift                                   (0)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_kpadbn_mask                                  (0x00000700)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_swha_mask                                    (0x00000020)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_kpadha_mask                                  (0x00000010)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_ardp_mask                                    (0x00000003)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_kpadbn(data)                                 (0x00000700&((data)<<8))
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_swha(data)                                   (0x00000020&((data)<<5))
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_kpadha(data)                                 (0x00000010&((data)<<4))
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_ardp(data)                                   (0x00000003&(data))
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_get_kpadbn(data)                             ((0x00000700&(data))>>8)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_get_swha(data)                               ((0x00000020&(data))>>5)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_get_kpadha(data)                             ((0x00000010&(data))>>4)
#define  ISO_VFD_WRAPPER_VFD_ARDCTL_get_ardp(data)                               (0x00000003&(data))

#define  ISO_VFD_WRAPPER_VFD_KPADLIE                                             0x18061610
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_reg_addr                                    "0xB8061610"
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_reg                                         0xB8061610
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_inst_addr                                   "0x0004"
#define  set_ISO_VFD_WRAPPER_VFD_KPADLIE_reg(data)                               (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_KPADLIE_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_KPADLIE_reg                                     (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_KPADLIE_reg))
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_kpadie_shift                                (0)
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_kpadie_mask                                 (0xFFFFFFFF)
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_kpadie(data)                                (0xFFFFFFFF&(data))
#define  ISO_VFD_WRAPPER_VFD_KPADLIE_get_kpadie(data)                            (0xFFFFFFFF&(data))

#define  ISO_VFD_WRAPPER_VFD_KPADHIE                                             0x18061614
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_reg_addr                                    "0xB8061614"
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_reg                                         0xB8061614
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_inst_addr                                   "0x0005"
#define  set_ISO_VFD_WRAPPER_VFD_KPADHIE_reg(data)                               (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_KPADHIE_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_KPADHIE_reg                                     (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_KPADHIE_reg))
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_kpadie_shift                                (0)
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_kpadie_mask                                 (0x0000FFFF)
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_kpadie(data)                                (0x0000FFFF&(data))
#define  ISO_VFD_WRAPPER_VFD_KPADHIE_get_kpadie(data)                            (0x0000FFFF&(data))

#define  ISO_VFD_WRAPPER_VFD_SWIE                                                0x18061618
#define  ISO_VFD_WRAPPER_VFD_SWIE_reg_addr                                       "0xB8061618"
#define  ISO_VFD_WRAPPER_VFD_SWIE_reg                                            0xB8061618
#define  ISO_VFD_WRAPPER_VFD_SWIE_inst_addr                                      "0x0006"
#define  set_ISO_VFD_WRAPPER_VFD_SWIE_reg(data)                                  (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_SWIE_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_SWIE_reg                                        (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_SWIE_reg))
#define  ISO_VFD_WRAPPER_VFD_SWIE_swie_shift                                     (0)
#define  ISO_VFD_WRAPPER_VFD_SWIE_swie_mask                                      (0x0000000F)
#define  ISO_VFD_WRAPPER_VFD_SWIE_swie(data)                                     (0x0000000F&(data))
#define  ISO_VFD_WRAPPER_VFD_SWIE_get_swie(data)                                 (0x0000000F&(data))

#define  ISO_VFD_WRAPPER_VFD_ARDKPADL                                            0x1806161C
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_reg_addr                                   "0xB806161C"
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_reg                                        0xB806161C
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_inst_addr                                  "0x0007"
#define  set_ISO_VFD_WRAPPER_VFD_ARDKPADL_reg(data)                              (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDKPADL_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_ARDKPADL_reg                                    (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDKPADL_reg))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_31_24_shift                             (24)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_23_16_shift                             (16)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_15_8_shift                              (8)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_7_0_shift                               (0)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_31_24_mask                              (0xFF000000)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_23_16_mask                              (0x00FF0000)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_15_8_mask                               (0x0000FF00)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_7_0_mask                                (0x000000FF)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_31_24(data)                             (0xFF000000&((data)<<24))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_23_16(data)                             (0x00FF0000&((data)<<16))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_15_8(data)                              (0x0000FF00&((data)<<8))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_st_7_0(data)                               (0x000000FF&(data))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_get_st_31_24(data)                         ((0xFF000000&(data))>>24)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_get_st_23_16(data)                         ((0x00FF0000&(data))>>16)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_get_st_15_8(data)                          ((0x0000FF00&(data))>>8)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADL_get_st_7_0(data)                           (0x000000FF&(data))

#define  ISO_VFD_WRAPPER_VFD_ARDKPADH                                            0x18061620
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_reg_addr                                   "0xB8061620"
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_reg                                        0xB8061620
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_inst_addr                                  "0x0008"
#define  set_ISO_VFD_WRAPPER_VFD_ARDKPADH_reg(data)                              (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDKPADH_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_ARDKPADH_reg                                    (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDKPADH_reg))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_st_15_8_shift                              (8)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_st_7_0_shift                               (0)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_st_15_8_mask                               (0x0000FF00)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_st_7_0_mask                                (0x000000FF)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_st_15_8(data)                              (0x0000FF00&((data)<<8))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_st_7_0(data)                               (0x000000FF&(data))
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_get_st_15_8(data)                          ((0x0000FF00&(data))>>8)
#define  ISO_VFD_WRAPPER_VFD_ARDKPADH_get_st_7_0(data)                           (0x000000FF&(data))

#define  ISO_VFD_WRAPPER_VFD_ARDSW                                               0x18061624
#define  ISO_VFD_WRAPPER_VFD_ARDSW_reg_addr                                      "0xB8061624"
#define  ISO_VFD_WRAPPER_VFD_ARDSW_reg                                           0xB8061624
#define  ISO_VFD_WRAPPER_VFD_ARDSW_inst_addr                                     "0x0009"
#define  set_ISO_VFD_WRAPPER_VFD_ARDSW_reg(data)                                 (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDSW_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_ARDSW_reg                                       (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ARDSW_reg))
#define  ISO_VFD_WRAPPER_VFD_ARDSW_st_shift                                      (0)
#define  ISO_VFD_WRAPPER_VFD_ARDSW_st_mask                                       (0x0000000F)
#define  ISO_VFD_WRAPPER_VFD_ARDSW_st(data)                                      (0x0000000F&(data))
#define  ISO_VFD_WRAPPER_VFD_ARDSW_get_st(data)                                  (0x0000000F&(data))

#define  ISO_VFD_WRAPPER_VFD_CTL1                                                0x18061628
#define  ISO_VFD_WRAPPER_VFD_CTL1_reg_addr                                       "0xB8061628"
#define  ISO_VFD_WRAPPER_VFD_CTL1_reg                                            0xB8061628
#define  ISO_VFD_WRAPPER_VFD_CTL1_inst_addr                                      "0x000A"
#define  set_ISO_VFD_WRAPPER_VFD_CTL1_reg(data)                                  (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_CTL1_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_CTL1_reg                                        (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_CTL1_reg))
#define  ISO_VFD_WRAPPER_VFD_CTL1_clksel_1_shift                                 (16)
#define  ISO_VFD_WRAPPER_VFD_CTL1_tcsn_shift                                     (8)
#define  ISO_VFD_WRAPPER_VFD_CTL1_twait_shift                                    (0)
#define  ISO_VFD_WRAPPER_VFD_CTL1_clksel_1_mask                                  (0x00010000)
#define  ISO_VFD_WRAPPER_VFD_CTL1_tcsn_mask                                      (0x0000FF00)
#define  ISO_VFD_WRAPPER_VFD_CTL1_twait_mask                                     (0x000000FF)
#define  ISO_VFD_WRAPPER_VFD_CTL1_clksel_1(data)                                 (0x00010000&((data)<<16))
#define  ISO_VFD_WRAPPER_VFD_CTL1_tcsn(data)                                     (0x0000FF00&((data)<<8))
#define  ISO_VFD_WRAPPER_VFD_CTL1_twait(data)                                    (0x000000FF&(data))
#define  ISO_VFD_WRAPPER_VFD_CTL1_get_clksel_1(data)                             ((0x00010000&(data))>>16)
#define  ISO_VFD_WRAPPER_VFD_CTL1_get_tcsn(data)                                 ((0x0000FF00&(data))>>8)
#define  ISO_VFD_WRAPPER_VFD_CTL1_get_twait(data)                                (0x000000FF&(data))

#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR                                            0x1806162C
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_reg_addr                                   "0xB806162C"
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_reg                                        0xB806162C
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_inst_addr                                  "0x000B"
#define  set_ISO_VFD_WRAPPER_VFD_UMSK_ISR_reg(data)                              (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_UMSK_ISR_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_UMSK_ISR_reg                                    (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_UMSK_ISR_reg))
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardswda_umsk_int_shift                 (4)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardswa_umsk_int_shift                  (3)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardkpadda_umsk_int_shift               (2)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardkpada_umsk_int_shift                (1)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_wdone_umsk_int_shift                   (0)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardswda_umsk_int_mask                  (0x00000010)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardswa_umsk_int_mask                   (0x00000008)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardkpadda_umsk_int_mask                (0x00000004)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardkpada_umsk_int_mask                 (0x00000002)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_wdone_umsk_int_mask                    (0x00000001)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardswda_umsk_int(data)                 (0x00000010&((data)<<4))
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardswa_umsk_int(data)                  (0x00000008&((data)<<3))
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardkpadda_umsk_int(data)               (0x00000004&((data)<<2))
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_ardkpada_umsk_int(data)                (0x00000002&((data)<<1))
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_vfd_wdone_umsk_int(data)                   (0x00000001&(data))
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_get_vfd_ardswda_umsk_int(data)             ((0x00000010&(data))>>4)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_get_vfd_ardswa_umsk_int(data)              ((0x00000008&(data))>>3)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_get_vfd_ardkpadda_umsk_int(data)           ((0x00000004&(data))>>2)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_get_vfd_ardkpada_umsk_int(data)            ((0x00000002&(data))>>1)
#define  ISO_VFD_WRAPPER_VFD_UMSK_ISR_get_vfd_wdone_umsk_int(data)               (0x00000001&(data))

#define  ISO_VFD_WRAPPER_VFD_ISR                                                 0x18061630
#define  ISO_VFD_WRAPPER_VFD_ISR_reg_addr                                        "0xB8061630"
#define  ISO_VFD_WRAPPER_VFD_ISR_reg                                             0xB8061630
#define  ISO_VFD_WRAPPER_VFD_ISR_inst_addr                                       "0x000C"
#define  set_ISO_VFD_WRAPPER_VFD_ISR_reg(data)                                   (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ISR_reg)=data)
#define  get_ISO_VFD_WRAPPER_VFD_ISR_reg                                         (*((volatile unsigned int*)ISO_VFD_WRAPPER_VFD_ISR_reg))
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardswda_int_shift                           (5)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardswa_int_shift                            (4)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardkpadda_int_shift                         (3)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardkpada_int_shift                          (2)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_wdone_int_shift                             (1)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardswda_int_mask                            (0x00000020)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardswa_int_mask                             (0x00000010)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardkpadda_int_mask                          (0x00000008)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardkpada_int_mask                           (0x00000004)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_wdone_int_mask                              (0x00000002)
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardswda_int(data)                           (0x00000020&((data)<<5))
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardswa_int(data)                            (0x00000010&((data)<<4))
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardkpadda_int(data)                         (0x00000008&((data)<<3))
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_ardkpada_int(data)                          (0x00000004&((data)<<2))
#define  ISO_VFD_WRAPPER_VFD_ISR_vfd_wdone_int(data)                             (0x00000002&((data)<<1))
#define  ISO_VFD_WRAPPER_VFD_ISR_get_vfd_ardswda_int(data)                       ((0x00000020&(data))>>5)
#define  ISO_VFD_WRAPPER_VFD_ISR_get_vfd_ardswa_int(data)                        ((0x00000010&(data))>>4)
#define  ISO_VFD_WRAPPER_VFD_ISR_get_vfd_ardkpadda_int(data)                     ((0x00000008&(data))>>3)
#define  ISO_VFD_WRAPPER_VFD_ISR_get_vfd_ardkpada_int(data)                      ((0x00000004&(data))>>2)
#define  ISO_VFD_WRAPPER_VFD_ISR_get_vfd_wdone_int(data)                         ((0x00000002&(data))>>1)

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ISO_VFD_WRAPPER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  kpaden:1;
        RBus_UInt32  swen:1;
        RBus_UInt32  clksel:1;
        RBus_UInt32  envfd:1;
    };
}iso_vfd_wrapper_vfd_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  nact_csn:1;
        RBus_UInt32  b3c:1;
        RBus_UInt32  b2c:1;
        RBus_UInt32  b1c:1;
        RBus_UInt32  b0c:1;
        RBus_UInt32  enb3:1;
        RBus_UInt32  enb2:1;
        RBus_UInt32  enb1:1;
        RBus_UInt32  enb0:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  wd:1;
        RBus_UInt32  wdie:1;
    };
}iso_vfd_wrapper_vfd_wrctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte3:8;
        RBus_UInt32  byte2:8;
        RBus_UInt32  byte1:8;
        RBus_UInt32  byte0:8;
    };
}iso_vfd_wrapper_vfdo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpadbn:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  swha:1;
        RBus_UInt32  kpadha:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ardp:2;
    };
}iso_vfd_wrapper_vfd_ardctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpadie:32;
    };
}iso_vfd_wrapper_vfd_kpadlie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  kpadie:16;
    };
}iso_vfd_wrapper_vfd_kpadhie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  swie:4;
    };
}iso_vfd_wrapper_vfd_swie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_31_24:8;
        RBus_UInt32  st_23_16:8;
        RBus_UInt32  st_15_8:8;
        RBus_UInt32  st_7_0:8;
    };
}iso_vfd_wrapper_vfd_ardkpadl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  st_15_8:8;
        RBus_UInt32  st_7_0:8;
    };
}iso_vfd_wrapper_vfd_ardkpadh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  st:4;
    };
}iso_vfd_wrapper_vfd_ardsw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  clksel_1:1;
        RBus_UInt32  tcsn:8;
        RBus_UInt32  twait:8;
    };
}iso_vfd_wrapper_vfd_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  vfd_ardswda_umsk_int:1;
        RBus_UInt32  vfd_ardswa_umsk_int:1;
        RBus_UInt32  vfd_ardkpadda_umsk_int:1;
        RBus_UInt32  vfd_ardkpada_umsk_int:1;
        RBus_UInt32  vfd_wdone_umsk_int:1;
    };
}iso_vfd_wrapper_vfd_umsk_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  vfd_ardswda_int:1;
        RBus_UInt32  vfd_ardswa_int:1;
        RBus_UInt32  vfd_ardkpadda_int:1;
        RBus_UInt32  vfd_ardkpada_int:1;
        RBus_UInt32  vfd_wdone_int:1;
        RBus_UInt32  res2:1;
    };
}iso_vfd_wrapper_vfd_isr_RBUS;

#else //apply LITTLE_ENDIAN

//======ISO_VFD_WRAPPER register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  envfd:1;
        RBus_UInt32  clksel:1;
        RBus_UInt32  swen:1;
        RBus_UInt32  kpaden:1;
        RBus_UInt32  res1:28;
    };
}iso_vfd_wrapper_vfd_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdie:1;
        RBus_UInt32  wd:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  enb0:1;
        RBus_UInt32  enb1:1;
        RBus_UInt32  enb2:1;
        RBus_UInt32  enb3:1;
        RBus_UInt32  b0c:1;
        RBus_UInt32  b1c:1;
        RBus_UInt32  b2c:1;
        RBus_UInt32  b3c:1;
        RBus_UInt32  nact_csn:1;
        RBus_UInt32  res2:19;
    };
}iso_vfd_wrapper_vfd_wrctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  byte0:8;
        RBus_UInt32  byte1:8;
        RBus_UInt32  byte2:8;
        RBus_UInt32  byte3:8;
    };
}iso_vfd_wrapper_vfdo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ardp:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  kpadha:1;
        RBus_UInt32  swha:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  kpadbn:3;
        RBus_UInt32  res3:21;
    };
}iso_vfd_wrapper_vfd_ardctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpadie:32;
    };
}iso_vfd_wrapper_vfd_kpadlie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpadie:16;
        RBus_UInt32  res1:16;
    };
}iso_vfd_wrapper_vfd_kpadhie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  swie:4;
        RBus_UInt32  res1:28;
    };
}iso_vfd_wrapper_vfd_swie_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_7_0:8;
        RBus_UInt32  st_15_8:8;
        RBus_UInt32  st_23_16:8;
        RBus_UInt32  st_31_24:8;
    };
}iso_vfd_wrapper_vfd_ardkpadl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st_7_0:8;
        RBus_UInt32  st_15_8:8;
        RBus_UInt32  res1:16;
    };
}iso_vfd_wrapper_vfd_ardkpadh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  st:4;
        RBus_UInt32  res1:28;
    };
}iso_vfd_wrapper_vfd_ardsw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  twait:8;
        RBus_UInt32  tcsn:8;
        RBus_UInt32  clksel_1:1;
        RBus_UInt32  res1:15;
    };
}iso_vfd_wrapper_vfd_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vfd_wdone_umsk_int:1;
        RBus_UInt32  vfd_ardkpada_umsk_int:1;
        RBus_UInt32  vfd_ardkpadda_umsk_int:1;
        RBus_UInt32  vfd_ardswa_umsk_int:1;
        RBus_UInt32  vfd_ardswda_umsk_int:1;
        RBus_UInt32  res1:27;
    };
}iso_vfd_wrapper_vfd_umsk_isr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vfd_wdone_int:1;
        RBus_UInt32  vfd_ardkpada_int:1;
        RBus_UInt32  vfd_ardkpadda_int:1;
        RBus_UInt32  vfd_ardswa_int:1;
        RBus_UInt32  vfd_ardswda_int:1;
        RBus_UInt32  res2:26;
    };
}iso_vfd_wrapper_vfd_isr_RBUS;




#endif 


#endif 
