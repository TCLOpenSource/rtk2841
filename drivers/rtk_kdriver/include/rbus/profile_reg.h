/**
* @file MarArthur5-DesignSpec-I-Domain_profile
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_PROFILE_REG_H_
#define _RBUS_PROFILE_REG_H_

#include "rbus_types.h"



//  PROFILE Register Address
#define  PROFILE_ICH1_Hist_Profile_CTRL                                          0x18023400
#define  PROFILE_ICH1_Hist_Profile_CTRL_reg_addr                                 "0xB8023400"
#define  PROFILE_ICH1_Hist_Profile_CTRL_reg                                      0xB8023400
#define  PROFILE_ICH1_Hist_Profile_CTRL_inst_addr                                "0x0000"
#define  set_PROFILE_ICH1_Hist_Profile_CTRL_reg(data)                            (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_CTRL_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_CTRL_reg                                  (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_CTRL_reg))
#define  PROFILE_ICH1_Hist_Profile_CTRL_dummy_18_16_shift                        (16)
#define  PROFILE_ICH1_Hist_Profile_CTRL_en_4k2k_mode_shift                       (14)
#define  PROFILE_ICH1_Hist_Profile_CTRL_en_3d_mode_shift                         (13)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_yuv_sel_shift                     (11)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_hnsr_shift                        (6)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_vnsr_shift                        (4)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_field_sel_shift                   (2)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_overflow_sel_shift                (1)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_enable_profile_shift              (0)
#define  PROFILE_ICH1_Hist_Profile_CTRL_dummy_18_16_mask                         (0x00070000)
#define  PROFILE_ICH1_Hist_Profile_CTRL_en_4k2k_mode_mask                        (0x00004000)
#define  PROFILE_ICH1_Hist_Profile_CTRL_en_3d_mode_mask                          (0x00002000)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_yuv_sel_mask                      (0x00001800)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_hnsr_mask                         (0x000000C0)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_vnsr_mask                         (0x00000030)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_field_sel_mask                    (0x0000000C)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_overflow_sel_mask                 (0x00000002)
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_enable_profile_mask               (0x00000001)
#define  PROFILE_ICH1_Hist_Profile_CTRL_dummy_18_16(data)                        (0x00070000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_CTRL_en_4k2k_mode(data)                       (0x00004000&((data)<<14))
#define  PROFILE_ICH1_Hist_Profile_CTRL_en_3d_mode(data)                         (0x00002000&((data)<<13))
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_yuv_sel(data)                     (0x00001800&((data)<<11))
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_hnsr(data)                        (0x000000C0&((data)<<6))
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_vnsr(data)                        (0x00000030&((data)<<4))
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_field_sel(data)                   (0x0000000C&((data)<<2))
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_overflow_sel(data)                (0x00000002&((data)<<1))
#define  PROFILE_ICH1_Hist_Profile_CTRL_ch1_pf_enable_profile(data)              (0x00000001&(data))
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_dummy_18_16(data)                    ((0x00070000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_en_4k2k_mode(data)                   ((0x00004000&(data))>>14)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_en_3d_mode(data)                     ((0x00002000&(data))>>13)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_ch1_pf_yuv_sel(data)                 ((0x00001800&(data))>>11)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_ch1_pf_hnsr(data)                    ((0x000000C0&(data))>>6)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_ch1_pf_vnsr(data)                    ((0x00000030&(data))>>4)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_ch1_pf_field_sel(data)               ((0x0000000C&(data))>>2)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_ch1_pf_overflow_sel(data)            ((0x00000002&(data))>>1)
#define  PROFILE_ICH1_Hist_Profile_CTRL_get_ch1_pf_enable_profile(data)          (0x00000001&(data))

#define  PROFILE_ICH1_Hist_Profile_size                                          0x18023404
#define  PROFILE_ICH1_Hist_Profile_size_reg_addr                                 "0xB8023404"
#define  PROFILE_ICH1_Hist_Profile_size_reg                                      0xB8023404
#define  PROFILE_ICH1_Hist_Profile_size_inst_addr                                "0x0001"
#define  set_PROFILE_ICH1_Hist_Profile_size_reg(data)                            (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_size_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_size_reg                                  (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_size_reg))
#define  PROFILE_ICH1_Hist_Profile_size_ch1_pf_vsize_shift                       (16)
#define  PROFILE_ICH1_Hist_Profile_size_ch1_pf_hsize_shift                       (0)
#define  PROFILE_ICH1_Hist_Profile_size_ch1_pf_vsize_mask                        (0x03FF0000)
#define  PROFILE_ICH1_Hist_Profile_size_ch1_pf_hsize_mask                        (0x000003FF)
#define  PROFILE_ICH1_Hist_Profile_size_ch1_pf_vsize(data)                       (0x03FF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_size_ch1_pf_hsize(data)                       (0x000003FF&(data))
#define  PROFILE_ICH1_Hist_Profile_size_get_ch1_pf_vsize(data)                   ((0x03FF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_size_get_ch1_pf_hsize(data)                   (0x000003FF&(data))

#define  PROFILE_ICH1_Hist_Profile_StartH                                        0x18023408
#define  PROFILE_ICH1_Hist_Profile_StartH_reg_addr                               "0xB8023408"
#define  PROFILE_ICH1_Hist_Profile_StartH_reg                                    0xB8023408
#define  PROFILE_ICH1_Hist_Profile_StartH_inst_addr                              "0x0002"
#define  set_PROFILE_ICH1_Hist_Profile_StartH_reg(data)                          (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_StartH_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_StartH_reg                                (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_StartH_reg))
#define  PROFILE_ICH1_Hist_Profile_StartH_ch1_pf_starth_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile_StartH_ch1_pf_starth_mask                     (0x00003FFF)
#define  PROFILE_ICH1_Hist_Profile_StartH_ch1_pf_starth(data)                    (0x00003FFF&(data))
#define  PROFILE_ICH1_Hist_Profile_StartH_get_ch1_pf_starth(data)                (0x00003FFF&(data))

#define  PROFILE_ICH1_Hist_Profile_StartV                                        0x1802340C
#define  PROFILE_ICH1_Hist_Profile_StartV_reg_addr                               "0xB802340C"
#define  PROFILE_ICH1_Hist_Profile_StartV_reg                                    0xB802340C
#define  PROFILE_ICH1_Hist_Profile_StartV_inst_addr                              "0x0003"
#define  set_PROFILE_ICH1_Hist_Profile_StartV_reg(data)                          (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_StartV_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_StartV_reg                                (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_StartV_reg))
#define  PROFILE_ICH1_Hist_Profile_StartV_ch1_pf_startv_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile_StartV_ch1_pf_startv_mask                     (0x00003FFF)
#define  PROFILE_ICH1_Hist_Profile_StartV_ch1_pf_startv(data)                    (0x00003FFF&(data))
#define  PROFILE_ICH1_Hist_Profile_StartV_get_ch1_pf_startv(data)                (0x00003FFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_00                                       0x18023410
#define  PROFILE_ICH1_Hist_Profile_Data_00_reg_addr                              "0xB8023410"
#define  PROFILE_ICH1_Hist_Profile_Data_00_reg                                   0xB8023410
#define  PROFILE_ICH1_Hist_Profile_Data_00_inst_addr                             "0x0004"
#define  set_PROFILE_ICH1_Hist_Profile_Data_00_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_00_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_00_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_00_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_00_ch1_pf_h01_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_00_ch1_pf_h00_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_00_ch1_pf_h01_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_00_ch1_pf_h00_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_00_ch1_pf_h01(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_00_ch1_pf_h00(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_00_get_ch1_pf_h01(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_00_get_ch1_pf_h00(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_01                                       0x18023414
#define  PROFILE_ICH1_Hist_Profile_Data_01_reg_addr                              "0xB8023414"
#define  PROFILE_ICH1_Hist_Profile_Data_01_reg                                   0xB8023414
#define  PROFILE_ICH1_Hist_Profile_Data_01_inst_addr                             "0x0005"
#define  set_PROFILE_ICH1_Hist_Profile_Data_01_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_01_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_01_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_01_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_01_ch1_pf_h03_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_01_ch1_pf_h02_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_01_ch1_pf_h03_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_01_ch1_pf_h02_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_01_ch1_pf_h03(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_01_ch1_pf_h02(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_01_get_ch1_pf_h03(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_01_get_ch1_pf_h02(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_02                                       0x18023418
#define  PROFILE_ICH1_Hist_Profile_Data_02_reg_addr                              "0xB8023418"
#define  PROFILE_ICH1_Hist_Profile_Data_02_reg                                   0xB8023418
#define  PROFILE_ICH1_Hist_Profile_Data_02_inst_addr                             "0x0006"
#define  set_PROFILE_ICH1_Hist_Profile_Data_02_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_02_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_02_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_02_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_02_ch1_pf_h05_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_02_ch1_pf_h04_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_02_ch1_pf_h05_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_02_ch1_pf_h04_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_02_ch1_pf_h05(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_02_ch1_pf_h04(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_02_get_ch1_pf_h05(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_02_get_ch1_pf_h04(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_03                                       0x1802341C
#define  PROFILE_ICH1_Hist_Profile_Data_03_reg_addr                              "0xB802341C"
#define  PROFILE_ICH1_Hist_Profile_Data_03_reg                                   0xB802341C
#define  PROFILE_ICH1_Hist_Profile_Data_03_inst_addr                             "0x0007"
#define  set_PROFILE_ICH1_Hist_Profile_Data_03_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_03_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_03_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_03_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_03_ch1_pf_h07_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_03_ch1_pf_h06_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_03_ch1_pf_h07_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_03_ch1_pf_h06_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_03_ch1_pf_h07(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_03_ch1_pf_h06(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_03_get_ch1_pf_h07(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_03_get_ch1_pf_h06(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_04                                       0x18023420
#define  PROFILE_ICH1_Hist_Profile_Data_04_reg_addr                              "0xB8023420"
#define  PROFILE_ICH1_Hist_Profile_Data_04_reg                                   0xB8023420
#define  PROFILE_ICH1_Hist_Profile_Data_04_inst_addr                             "0x0008"
#define  set_PROFILE_ICH1_Hist_Profile_Data_04_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_04_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_04_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_04_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_04_ch1_pf_h09_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_04_ch1_pf_h08_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_04_ch1_pf_h09_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_04_ch1_pf_h08_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_04_ch1_pf_h09(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_04_ch1_pf_h08(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_04_get_ch1_pf_h09(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_04_get_ch1_pf_h08(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_05                                       0x18023424
#define  PROFILE_ICH1_Hist_Profile_Data_05_reg_addr                              "0xB8023424"
#define  PROFILE_ICH1_Hist_Profile_Data_05_reg                                   0xB8023424
#define  PROFILE_ICH1_Hist_Profile_Data_05_inst_addr                             "0x0009"
#define  set_PROFILE_ICH1_Hist_Profile_Data_05_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_05_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_05_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_05_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_05_ch1_pf_h11_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_05_ch1_pf_h10_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_05_ch1_pf_h11_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_05_ch1_pf_h10_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_05_ch1_pf_h11(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_05_ch1_pf_h10(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_05_get_ch1_pf_h11(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_05_get_ch1_pf_h10(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_06                                       0x18023428
#define  PROFILE_ICH1_Hist_Profile_Data_06_reg_addr                              "0xB8023428"
#define  PROFILE_ICH1_Hist_Profile_Data_06_reg                                   0xB8023428
#define  PROFILE_ICH1_Hist_Profile_Data_06_inst_addr                             "0x000A"
#define  set_PROFILE_ICH1_Hist_Profile_Data_06_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_06_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_06_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_06_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_06_ch1_pf_h13_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_06_ch1_pf_h12_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_06_ch1_pf_h13_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_06_ch1_pf_h12_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_06_ch1_pf_h13(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_06_ch1_pf_h12(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_06_get_ch1_pf_h13(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_06_get_ch1_pf_h12(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_07                                       0x1802342C
#define  PROFILE_ICH1_Hist_Profile_Data_07_reg_addr                              "0xB802342C"
#define  PROFILE_ICH1_Hist_Profile_Data_07_reg                                   0xB802342C
#define  PROFILE_ICH1_Hist_Profile_Data_07_inst_addr                             "0x000B"
#define  set_PROFILE_ICH1_Hist_Profile_Data_07_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_07_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_07_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_07_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_07_ch1_pf_h15_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_07_ch1_pf_h14_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_07_ch1_pf_h15_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_07_ch1_pf_h14_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_07_ch1_pf_h15(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_07_ch1_pf_h14(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_07_get_ch1_pf_h15(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_07_get_ch1_pf_h14(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_08                                       0x18023430
#define  PROFILE_ICH1_Hist_Profile_Data_08_reg_addr                              "0xB8023430"
#define  PROFILE_ICH1_Hist_Profile_Data_08_reg                                   0xB8023430
#define  PROFILE_ICH1_Hist_Profile_Data_08_inst_addr                             "0x000C"
#define  set_PROFILE_ICH1_Hist_Profile_Data_08_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_08_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_08_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_08_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_08_ch1_pf_v01_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_08_ch1_pf_v00_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_08_ch1_pf_v01_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_08_ch1_pf_v00_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_08_ch1_pf_v01(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_08_ch1_pf_v00(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_08_get_ch1_pf_v01(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_08_get_ch1_pf_v00(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_09                                       0x18023434
#define  PROFILE_ICH1_Hist_Profile_Data_09_reg_addr                              "0xB8023434"
#define  PROFILE_ICH1_Hist_Profile_Data_09_reg                                   0xB8023434
#define  PROFILE_ICH1_Hist_Profile_Data_09_inst_addr                             "0x000D"
#define  set_PROFILE_ICH1_Hist_Profile_Data_09_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_09_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_09_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_09_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_09_ch1_pf_v03_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_09_ch1_pf_v02_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_09_ch1_pf_v03_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_09_ch1_pf_v02_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_09_ch1_pf_v03(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_09_ch1_pf_v02(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_09_get_ch1_pf_v03(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_09_get_ch1_pf_v02(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_10                                       0x18023438
#define  PROFILE_ICH1_Hist_Profile_Data_10_reg_addr                              "0xB8023438"
#define  PROFILE_ICH1_Hist_Profile_Data_10_reg                                   0xB8023438
#define  PROFILE_ICH1_Hist_Profile_Data_10_inst_addr                             "0x000E"
#define  set_PROFILE_ICH1_Hist_Profile_Data_10_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_10_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_10_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_10_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_10_ch1_pf_v05_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_10_ch1_pf_v04_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_10_ch1_pf_v05_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_10_ch1_pf_v04_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_10_ch1_pf_v05(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_10_ch1_pf_v04(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_10_get_ch1_pf_v05(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_10_get_ch1_pf_v04(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_11                                       0x1802343C
#define  PROFILE_ICH1_Hist_Profile_Data_11_reg_addr                              "0xB802343C"
#define  PROFILE_ICH1_Hist_Profile_Data_11_reg                                   0xB802343C
#define  PROFILE_ICH1_Hist_Profile_Data_11_inst_addr                             "0x000F"
#define  set_PROFILE_ICH1_Hist_Profile_Data_11_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_11_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_11_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_11_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_11_ch1_pf_v07_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_11_ch1_pf_v06_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_11_ch1_pf_v07_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_11_ch1_pf_v06_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_11_ch1_pf_v07(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_11_ch1_pf_v06(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_11_get_ch1_pf_v07(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_11_get_ch1_pf_v06(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_12                                       0x18023440
#define  PROFILE_ICH1_Hist_Profile_Data_12_reg_addr                              "0xB8023440"
#define  PROFILE_ICH1_Hist_Profile_Data_12_reg                                   0xB8023440
#define  PROFILE_ICH1_Hist_Profile_Data_12_inst_addr                             "0x0010"
#define  set_PROFILE_ICH1_Hist_Profile_Data_12_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_12_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_12_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_12_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_12_ch1_pf_v09_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_12_ch1_pf_v08_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_12_ch1_pf_v09_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_12_ch1_pf_v08_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_12_ch1_pf_v09(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_12_ch1_pf_v08(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_12_get_ch1_pf_v09(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_12_get_ch1_pf_v08(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_13                                       0x18023444
#define  PROFILE_ICH1_Hist_Profile_Data_13_reg_addr                              "0xB8023444"
#define  PROFILE_ICH1_Hist_Profile_Data_13_reg                                   0xB8023444
#define  PROFILE_ICH1_Hist_Profile_Data_13_inst_addr                             "0x0011"
#define  set_PROFILE_ICH1_Hist_Profile_Data_13_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_13_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_13_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_13_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_13_ch1_pf_v11_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_13_ch1_pf_v10_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_13_ch1_pf_v11_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_13_ch1_pf_v10_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_13_ch1_pf_v11(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_13_ch1_pf_v10(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_13_get_ch1_pf_v11(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_13_get_ch1_pf_v10(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_14                                       0x18023448
#define  PROFILE_ICH1_Hist_Profile_Data_14_reg_addr                              "0xB8023448"
#define  PROFILE_ICH1_Hist_Profile_Data_14_reg                                   0xB8023448
#define  PROFILE_ICH1_Hist_Profile_Data_14_inst_addr                             "0x0012"
#define  set_PROFILE_ICH1_Hist_Profile_Data_14_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_14_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_14_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_14_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_14_ch1_pf_v13_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_14_ch1_pf_v12_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_14_ch1_pf_v13_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_14_ch1_pf_v12_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_14_ch1_pf_v13(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_14_ch1_pf_v12(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_14_get_ch1_pf_v13(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_14_get_ch1_pf_v12(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_15                                       0x1802344C
#define  PROFILE_ICH1_Hist_Profile_Data_15_reg_addr                              "0xB802344C"
#define  PROFILE_ICH1_Hist_Profile_Data_15_reg                                   0xB802344C
#define  PROFILE_ICH1_Hist_Profile_Data_15_inst_addr                             "0x0013"
#define  set_PROFILE_ICH1_Hist_Profile_Data_15_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_15_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_15_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_15_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_15_ch1_pf_v15_shift                      (16)
#define  PROFILE_ICH1_Hist_Profile_Data_15_ch1_pf_v14_shift                      (0)
#define  PROFILE_ICH1_Hist_Profile_Data_15_ch1_pf_v15_mask                       (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_15_ch1_pf_v14_mask                       (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_15_ch1_pf_v15(data)                      (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_15_ch1_pf_v14(data)                      (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_15_get_ch1_pf_v15(data)                  ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_15_get_ch1_pf_v14(data)                  (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_16                                       0x18023450
#define  PROFILE_ICH1_Hist_Profile_Data_16_reg_addr                              "0xB8023450"
#define  PROFILE_ICH1_Hist_Profile_Data_16_reg                                   0xB8023450
#define  PROFILE_ICH1_Hist_Profile_Data_16_inst_addr                             "0x0014"
#define  set_PROFILE_ICH1_Hist_Profile_Data_16_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_16_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_16_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_16_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_16_ch1_pf_h01_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_16_ch1_pf_h00_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_16_ch1_pf_h01_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_16_ch1_pf_h00_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_16_ch1_pf_h01_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_16_ch1_pf_h00_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_16_get_ch1_pf_h01_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_16_get_ch1_pf_h00_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_17                                       0x18023454
#define  PROFILE_ICH1_Hist_Profile_Data_17_reg_addr                              "0xB8023454"
#define  PROFILE_ICH1_Hist_Profile_Data_17_reg                                   0xB8023454
#define  PROFILE_ICH1_Hist_Profile_Data_17_inst_addr                             "0x0015"
#define  set_PROFILE_ICH1_Hist_Profile_Data_17_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_17_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_17_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_17_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_17_ch1_pf_h03_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_17_ch1_pf_h02_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_17_ch1_pf_h03_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_17_ch1_pf_h02_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_17_ch1_pf_h03_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_17_ch1_pf_h02_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_17_get_ch1_pf_h03_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_17_get_ch1_pf_h02_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_18                                       0x18023458
#define  PROFILE_ICH1_Hist_Profile_Data_18_reg_addr                              "0xB8023458"
#define  PROFILE_ICH1_Hist_Profile_Data_18_reg                                   0xB8023458
#define  PROFILE_ICH1_Hist_Profile_Data_18_inst_addr                             "0x0016"
#define  set_PROFILE_ICH1_Hist_Profile_Data_18_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_18_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_18_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_18_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_18_ch1_pf_h05_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_18_ch1_pf_h04_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_18_ch1_pf_h05_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_18_ch1_pf_h04_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_18_ch1_pf_h05_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_18_ch1_pf_h04_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_18_get_ch1_pf_h05_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_18_get_ch1_pf_h04_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_19                                       0x1802345C
#define  PROFILE_ICH1_Hist_Profile_Data_19_reg_addr                              "0xB802345C"
#define  PROFILE_ICH1_Hist_Profile_Data_19_reg                                   0xB802345C
#define  PROFILE_ICH1_Hist_Profile_Data_19_inst_addr                             "0x0017"
#define  set_PROFILE_ICH1_Hist_Profile_Data_19_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_19_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_19_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_19_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_19_ch1_pf_h07_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_19_ch1_pf_h06_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_19_ch1_pf_h07_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_19_ch1_pf_h06_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_19_ch1_pf_h07_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_19_ch1_pf_h06_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_19_get_ch1_pf_h07_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_19_get_ch1_pf_h06_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_20                                       0x18023460
#define  PROFILE_ICH1_Hist_Profile_Data_20_reg_addr                              "0xB8023460"
#define  PROFILE_ICH1_Hist_Profile_Data_20_reg                                   0xB8023460
#define  PROFILE_ICH1_Hist_Profile_Data_20_inst_addr                             "0x0018"
#define  set_PROFILE_ICH1_Hist_Profile_Data_20_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_20_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_20_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_20_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_20_ch1_pf_h09_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_20_ch1_pf_h08_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_20_ch1_pf_h09_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_20_ch1_pf_h08_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_20_ch1_pf_h09_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_20_ch1_pf_h08_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_20_get_ch1_pf_h09_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_20_get_ch1_pf_h08_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_21                                       0x18023464
#define  PROFILE_ICH1_Hist_Profile_Data_21_reg_addr                              "0xB8023464"
#define  PROFILE_ICH1_Hist_Profile_Data_21_reg                                   0xB8023464
#define  PROFILE_ICH1_Hist_Profile_Data_21_inst_addr                             "0x0019"
#define  set_PROFILE_ICH1_Hist_Profile_Data_21_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_21_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_21_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_21_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_21_ch1_pf_h11_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_21_ch1_pf_h10_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_21_ch1_pf_h11_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_21_ch1_pf_h10_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_21_ch1_pf_h11_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_21_ch1_pf_h10_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_21_get_ch1_pf_h11_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_21_get_ch1_pf_h10_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_22                                       0x18023468
#define  PROFILE_ICH1_Hist_Profile_Data_22_reg_addr                              "0xB8023468"
#define  PROFILE_ICH1_Hist_Profile_Data_22_reg                                   0xB8023468
#define  PROFILE_ICH1_Hist_Profile_Data_22_inst_addr                             "0x001A"
#define  set_PROFILE_ICH1_Hist_Profile_Data_22_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_22_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_22_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_22_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_22_ch1_pf_h13_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_22_ch1_pf_h12_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_22_ch1_pf_h13_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_22_ch1_pf_h12_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_22_ch1_pf_h13_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_22_ch1_pf_h12_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_22_get_ch1_pf_h13_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_22_get_ch1_pf_h12_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_23                                       0x1802346C
#define  PROFILE_ICH1_Hist_Profile_Data_23_reg_addr                              "0xB802346C"
#define  PROFILE_ICH1_Hist_Profile_Data_23_reg                                   0xB802346C
#define  PROFILE_ICH1_Hist_Profile_Data_23_inst_addr                             "0x001B"
#define  set_PROFILE_ICH1_Hist_Profile_Data_23_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_23_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_23_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_23_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_23_ch1_pf_h15_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_23_ch1_pf_h14_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_23_ch1_pf_h15_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_23_ch1_pf_h14_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_23_ch1_pf_h15_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_23_ch1_pf_h14_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_23_get_ch1_pf_h15_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_23_get_ch1_pf_h14_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_24                                       0x18023470
#define  PROFILE_ICH1_Hist_Profile_Data_24_reg_addr                              "0xB8023470"
#define  PROFILE_ICH1_Hist_Profile_Data_24_reg                                   0xB8023470
#define  PROFILE_ICH1_Hist_Profile_Data_24_inst_addr                             "0x001C"
#define  set_PROFILE_ICH1_Hist_Profile_Data_24_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_24_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_24_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_24_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_24_ch1_pf_v01_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_24_ch1_pf_v00_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_24_ch1_pf_v01_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_24_ch1_pf_v00_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_24_ch1_pf_v01_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_24_ch1_pf_v00_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_24_get_ch1_pf_v01_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_24_get_ch1_pf_v00_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_25                                       0x18023474
#define  PROFILE_ICH1_Hist_Profile_Data_25_reg_addr                              "0xB8023474"
#define  PROFILE_ICH1_Hist_Profile_Data_25_reg                                   0xB8023474
#define  PROFILE_ICH1_Hist_Profile_Data_25_inst_addr                             "0x001D"
#define  set_PROFILE_ICH1_Hist_Profile_Data_25_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_25_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_25_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_25_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_25_ch1_pf_v03_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_25_ch1_pf_v02_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_25_ch1_pf_v03_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_25_ch1_pf_v02_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_25_ch1_pf_v03_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_25_ch1_pf_v02_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_25_get_ch1_pf_v03_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_25_get_ch1_pf_v02_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_26                                       0x18023478
#define  PROFILE_ICH1_Hist_Profile_Data_26_reg_addr                              "0xB8023478"
#define  PROFILE_ICH1_Hist_Profile_Data_26_reg                                   0xB8023478
#define  PROFILE_ICH1_Hist_Profile_Data_26_inst_addr                             "0x001E"
#define  set_PROFILE_ICH1_Hist_Profile_Data_26_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_26_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_26_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_26_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_26_ch1_pf_v05_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_26_ch1_pf_v04_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_26_ch1_pf_v05_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_26_ch1_pf_v04_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_26_ch1_pf_v05_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_26_ch1_pf_v04_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_26_get_ch1_pf_v05_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_26_get_ch1_pf_v04_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_27                                       0x1802347C
#define  PROFILE_ICH1_Hist_Profile_Data_27_reg_addr                              "0xB802347C"
#define  PROFILE_ICH1_Hist_Profile_Data_27_reg                                   0xB802347C
#define  PROFILE_ICH1_Hist_Profile_Data_27_inst_addr                             "0x001F"
#define  set_PROFILE_ICH1_Hist_Profile_Data_27_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_27_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_27_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_27_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_27_ch1_pf_v07_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_27_ch1_pf_v06_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_27_ch1_pf_v07_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_27_ch1_pf_v06_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_27_ch1_pf_v07_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_27_ch1_pf_v06_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_27_get_ch1_pf_v07_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_27_get_ch1_pf_v06_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_28                                       0x18023480
#define  PROFILE_ICH1_Hist_Profile_Data_28_reg_addr                              "0xB8023480"
#define  PROFILE_ICH1_Hist_Profile_Data_28_reg                                   0xB8023480
#define  PROFILE_ICH1_Hist_Profile_Data_28_inst_addr                             "0x0020"
#define  set_PROFILE_ICH1_Hist_Profile_Data_28_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_28_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_28_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_28_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_28_ch1_pf_v09_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_28_ch1_pf_v08_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_28_ch1_pf_v09_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_28_ch1_pf_v08_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_28_ch1_pf_v09_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_28_ch1_pf_v08_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_28_get_ch1_pf_v09_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_28_get_ch1_pf_v08_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_29                                       0x18023484
#define  PROFILE_ICH1_Hist_Profile_Data_29_reg_addr                              "0xB8023484"
#define  PROFILE_ICH1_Hist_Profile_Data_29_reg                                   0xB8023484
#define  PROFILE_ICH1_Hist_Profile_Data_29_inst_addr                             "0x0021"
#define  set_PROFILE_ICH1_Hist_Profile_Data_29_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_29_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_29_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_29_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_29_ch1_pf_v11_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_29_ch1_pf_v10_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_29_ch1_pf_v11_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_29_ch1_pf_v10_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_29_ch1_pf_v11_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_29_ch1_pf_v10_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_29_get_ch1_pf_v11_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_29_get_ch1_pf_v10_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_30                                       0x18023488
#define  PROFILE_ICH1_Hist_Profile_Data_30_reg_addr                              "0xB8023488"
#define  PROFILE_ICH1_Hist_Profile_Data_30_reg                                   0xB8023488
#define  PROFILE_ICH1_Hist_Profile_Data_30_inst_addr                             "0x0022"
#define  set_PROFILE_ICH1_Hist_Profile_Data_30_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_30_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_30_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_30_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_30_ch1_pf_v13_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_30_ch1_pf_v12_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_30_ch1_pf_v13_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_30_ch1_pf_v12_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_30_ch1_pf_v13_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_30_ch1_pf_v12_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_30_get_ch1_pf_v13_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_30_get_ch1_pf_v12_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Data_31                                       0x1802348C
#define  PROFILE_ICH1_Hist_Profile_Data_31_reg_addr                              "0xB802348C"
#define  PROFILE_ICH1_Hist_Profile_Data_31_reg                                   0xB802348C
#define  PROFILE_ICH1_Hist_Profile_Data_31_inst_addr                             "0x0023"
#define  set_PROFILE_ICH1_Hist_Profile_Data_31_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_31_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Data_31_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Data_31_reg))
#define  PROFILE_ICH1_Hist_Profile_Data_31_ch1_pf_v15_right_shift                (16)
#define  PROFILE_ICH1_Hist_Profile_Data_31_ch1_pf_v14_right_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Data_31_ch1_pf_v15_right_mask                 (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile_Data_31_ch1_pf_v14_right_mask                 (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile_Data_31_ch1_pf_v15_right(data)                (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile_Data_31_ch1_pf_v14_right(data)                (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Data_31_get_ch1_pf_v15_right(data)            ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile_Data_31_get_ch1_pf_v14_right(data)            (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Diff                                          0x18023490
#define  PROFILE_ICH1_Hist_Profile_Diff_reg_addr                                 "0xB8023490"
#define  PROFILE_ICH1_Hist_Profile_Diff_reg                                      0xB8023490
#define  PROFILE_ICH1_Hist_Profile_Diff_inst_addr                                "0x0024"
#define  set_PROFILE_ICH1_Hist_Profile_Diff_reg(data)                            (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Diff_reg                                  (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_reg))
#define  PROFILE_ICH1_Hist_Profile_Diff_ch1_pf_diffsum_shift                     (0)
#define  PROFILE_ICH1_Hist_Profile_Diff_ch1_pf_diffsum_mask                      (0x3FFFFFFF)
#define  PROFILE_ICH1_Hist_Profile_Diff_ch1_pf_diffsum(data)                     (0x3FFFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Diff_get_ch1_pf_diffsum(data)                 (0x3FFFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Diff_th                                       0x18023494
#define  PROFILE_ICH1_Hist_Profile_Diff_th_reg_addr                              "0xB8023494"
#define  PROFILE_ICH1_Hist_Profile_Diff_th_reg                                   0xB8023494
#define  PROFILE_ICH1_Hist_Profile_Diff_th_inst_addr                             "0x0025"
#define  set_PROFILE_ICH1_Hist_Profile_Diff_th_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_th_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Diff_th_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_th_reg))
#define  PROFILE_ICH1_Hist_Profile_Diff_th_ch1_pf_diff_th_h_shift                (8)
#define  PROFILE_ICH1_Hist_Profile_Diff_th_ch1_pf_diff_th_l_shift                (0)
#define  PROFILE_ICH1_Hist_Profile_Diff_th_ch1_pf_diff_th_h_mask                 (0x0000FF00)
#define  PROFILE_ICH1_Hist_Profile_Diff_th_ch1_pf_diff_th_l_mask                 (0x000000FF)
#define  PROFILE_ICH1_Hist_Profile_Diff_th_ch1_pf_diff_th_h(data)                (0x0000FF00&((data)<<8))
#define  PROFILE_ICH1_Hist_Profile_Diff_th_ch1_pf_diff_th_l(data)                (0x000000FF&(data))
#define  PROFILE_ICH1_Hist_Profile_Diff_th_get_ch1_pf_diff_th_h(data)            ((0x0000FF00&(data))>>8)
#define  PROFILE_ICH1_Hist_Profile_Diff_th_get_ch1_pf_diff_th_l(data)            (0x000000FF&(data))

#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L                                    0x18023498
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_reg_addr                           "0xB8023498"
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_reg                                0xB8023498
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_inst_addr                          "0x0026"
#define  set_PROFILE_ICH1_Hist_Profile_Diff_bin_L_reg(data)                      (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_bin_L_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Diff_bin_L_reg                            (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_bin_L_reg))
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_ch1_pf_diff_bin_l_shift            (0)
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_ch1_pf_diff_bin_l_mask             (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_ch1_pf_diff_bin_l(data)            (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_L_get_ch1_pf_diff_bin_l(data)        (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M                                    0x1802349C
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_reg_addr                           "0xB802349C"
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_reg                                0xB802349C
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_inst_addr                          "0x0027"
#define  set_PROFILE_ICH1_Hist_Profile_Diff_bin_M_reg(data)                      (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_bin_M_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Diff_bin_M_reg                            (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_bin_M_reg))
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_ch1_pf_diff_bin_m_shift            (0)
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_ch1_pf_diff_bin_m_mask             (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_ch1_pf_diff_bin_m(data)            (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_M_get_ch1_pf_diff_bin_m(data)        (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H                                    0x180234A0
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_reg_addr                           "0xB80234A0"
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_reg                                0xB80234A0
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_inst_addr                          "0x0028"
#define  set_PROFILE_ICH1_Hist_Profile_Diff_bin_H_reg(data)                      (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_bin_H_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile_Diff_bin_H_reg                            (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile_Diff_bin_H_reg))
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_ch1_pf_diff_bin_h_shift            (0)
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_ch1_pf_diff_bin_h_mask             (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_ch1_pf_diff_bin_h(data)            (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile_Diff_bin_H_get_ch1_pf_diff_bin_h(data)        (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile2_CTRL                                         0x180234A4
#define  PROFILE_ICH1_Hist_Profile2_CTRL_reg_addr                                "0xB80234A4"
#define  PROFILE_ICH1_Hist_Profile2_CTRL_reg                                     0xB80234A4
#define  PROFILE_ICH1_Hist_Profile2_CTRL_inst_addr                               "0x0029"
#define  set_PROFILE_ICH1_Hist_Profile2_CTRL_reg(data)                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_CTRL_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_CTRL_reg                                 (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_CTRL_reg))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_yuv_sel_shift                   (11)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_hnsr_shift                      (6)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_vnsr_shift                      (4)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_field_sel_shift                 (2)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_overflow_sel_shift              (1)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_enable_profile_shift            (0)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_yuv_sel_mask                    (0x00001800)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_hnsr_mask                       (0x000000C0)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_vnsr_mask                       (0x00000030)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_field_sel_mask                  (0x0000000C)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_overflow_sel_mask               (0x00000002)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_enable_profile_mask             (0x00000001)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_yuv_sel(data)                   (0x00001800&((data)<<11))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_hnsr(data)                      (0x000000C0&((data)<<6))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_vnsr(data)                      (0x00000030&((data)<<4))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_field_sel(data)                 (0x0000000C&((data)<<2))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_overflow_sel(data)              (0x00000002&((data)<<1))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_ch1_pf2_enable_profile(data)            (0x00000001&(data))
#define  PROFILE_ICH1_Hist_Profile2_CTRL_get_ch1_pf2_yuv_sel(data)               ((0x00001800&(data))>>11)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_get_ch1_pf2_hnsr(data)                  ((0x000000C0&(data))>>6)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_get_ch1_pf2_vnsr(data)                  ((0x00000030&(data))>>4)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_get_ch1_pf2_field_sel(data)             ((0x0000000C&(data))>>2)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_get_ch1_pf2_overflow_sel(data)          ((0x00000002&(data))>>1)
#define  PROFILE_ICH1_Hist_Profile2_CTRL_get_ch1_pf2_enable_profile(data)        (0x00000001&(data))

#define  PROFILE_ICH1_Hist_Profile2_size                                         0x180234A8
#define  PROFILE_ICH1_Hist_Profile2_size_reg_addr                                "0xB80234A8"
#define  PROFILE_ICH1_Hist_Profile2_size_reg                                     0xB80234A8
#define  PROFILE_ICH1_Hist_Profile2_size_inst_addr                               "0x002A"
#define  set_PROFILE_ICH1_Hist_Profile2_size_reg(data)                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_size_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_size_reg                                 (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_size_reg))
#define  PROFILE_ICH1_Hist_Profile2_size_ch1_pf2_vsize_shift                     (16)
#define  PROFILE_ICH1_Hist_Profile2_size_ch1_pf2_hsize_shift                     (0)
#define  PROFILE_ICH1_Hist_Profile2_size_ch1_pf2_vsize_mask                      (0x03FF0000)
#define  PROFILE_ICH1_Hist_Profile2_size_ch1_pf2_hsize_mask                      (0x000003FF)
#define  PROFILE_ICH1_Hist_Profile2_size_ch1_pf2_vsize(data)                     (0x03FF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile2_size_ch1_pf2_hsize(data)                     (0x000003FF&(data))
#define  PROFILE_ICH1_Hist_Profile2_size_get_ch1_pf2_vsize(data)                 ((0x03FF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile2_size_get_ch1_pf2_hsize(data)                 (0x000003FF&(data))

#define  PROFILE_ICH1_Hist_Profile2_StartH                                       0x180234AC
#define  PROFILE_ICH1_Hist_Profile2_StartH_reg_addr                              "0xB80234AC"
#define  PROFILE_ICH1_Hist_Profile2_StartH_reg                                   0xB80234AC
#define  PROFILE_ICH1_Hist_Profile2_StartH_inst_addr                             "0x002B"
#define  set_PROFILE_ICH1_Hist_Profile2_StartH_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_StartH_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_StartH_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_StartH_reg))
#define  PROFILE_ICH1_Hist_Profile2_StartH_ch1_pf2_starth_shift                  (0)
#define  PROFILE_ICH1_Hist_Profile2_StartH_ch1_pf2_starth_mask                   (0x00003FFF)
#define  PROFILE_ICH1_Hist_Profile2_StartH_ch1_pf2_starth(data)                  (0x00003FFF&(data))
#define  PROFILE_ICH1_Hist_Profile2_StartH_get_ch1_pf2_starth(data)              (0x00003FFF&(data))

#define  PROFILE_ICH1_Hist_Profile2_StartV                                       0x180234B0
#define  PROFILE_ICH1_Hist_Profile2_StartV_reg_addr                              "0xB80234B0"
#define  PROFILE_ICH1_Hist_Profile2_StartV_reg                                   0xB80234B0
#define  PROFILE_ICH1_Hist_Profile2_StartV_inst_addr                             "0x002C"
#define  set_PROFILE_ICH1_Hist_Profile2_StartV_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_StartV_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_StartV_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_StartV_reg))
#define  PROFILE_ICH1_Hist_Profile2_StartV_ch1_pf2_startv_shift                  (0)
#define  PROFILE_ICH1_Hist_Profile2_StartV_ch1_pf2_startv_mask                   (0x00003FFF)
#define  PROFILE_ICH1_Hist_Profile2_StartV_ch1_pf2_startv(data)                  (0x00003FFF&(data))
#define  PROFILE_ICH1_Hist_Profile2_StartV_get_ch1_pf2_startv(data)              (0x00003FFF&(data))

#define  PROFILE_ICH1_Hist_Profile2_Diff                                         0x180234B4
#define  PROFILE_ICH1_Hist_Profile2_Diff_reg_addr                                "0xB80234B4"
#define  PROFILE_ICH1_Hist_Profile2_Diff_reg                                     0xB80234B4
#define  PROFILE_ICH1_Hist_Profile2_Diff_inst_addr                               "0x002D"
#define  set_PROFILE_ICH1_Hist_Profile2_Diff_reg(data)                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_Diff_reg                                 (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_reg))
#define  PROFILE_ICH1_Hist_Profile2_Diff_ch1_pf2_diffsum_shift                   (0)
#define  PROFILE_ICH1_Hist_Profile2_Diff_ch1_pf2_diffsum_mask                    (0x3FFFFFFF)
#define  PROFILE_ICH1_Hist_Profile2_Diff_ch1_pf2_diffsum(data)                   (0x3FFFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile2_Diff_get_ch1_pf2_diffsum(data)               (0x3FFFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile2_Diff_th                                      0x180234B8
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_reg_addr                             "0xB80234B8"
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_reg                                  0xB80234B8
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_inst_addr                            "0x002E"
#define  set_PROFILE_ICH1_Hist_Profile2_Diff_th_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_th_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_Diff_th_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_th_reg))
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_ch1_pf2_diff_th_h_shift              (8)
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_ch1_pf2_diff_th_l_shift              (0)
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_ch1_pf2_diff_th_h_mask               (0x0000FF00)
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_ch1_pf2_diff_th_l_mask               (0x000000FF)
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_ch1_pf2_diff_th_h(data)              (0x0000FF00&((data)<<8))
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_ch1_pf2_diff_th_l(data)              (0x000000FF&(data))
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_get_ch1_pf2_diff_th_h(data)          ((0x0000FF00&(data))>>8)
#define  PROFILE_ICH1_Hist_Profile2_Diff_th_get_ch1_pf2_diff_th_l(data)          (0x000000FF&(data))

#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L                                   0x180234BC
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_reg_addr                          "0xB80234BC"
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_reg                               0xB80234BC
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_inst_addr                         "0x002F"
#define  set_PROFILE_ICH1_Hist_Profile2_Diff_bin_L_reg(data)                     (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_bin_L_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_Diff_bin_L_reg                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_bin_L_reg))
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_ch1_pf2_diff_bin_l_shift          (0)
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_ch1_pf2_diff_bin_l_mask           (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_ch1_pf2_diff_bin_l(data)          (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_L_get_ch1_pf2_diff_bin_l(data)      (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M                                   0x180234C0
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_reg_addr                          "0xB80234C0"
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_reg                               0xB80234C0
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_inst_addr                         "0x0030"
#define  set_PROFILE_ICH1_Hist_Profile2_Diff_bin_M_reg(data)                     (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_bin_M_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_Diff_bin_M_reg                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_bin_M_reg))
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_ch1_pf2_diff_bin_m_shift          (0)
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_ch1_pf2_diff_bin_m_mask           (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_ch1_pf2_diff_bin_m(data)          (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_M_get_ch1_pf2_diff_bin_m(data)      (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H                                   0x180234C4
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg_addr                          "0xB80234C4"
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg                               0xB80234C4
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_inst_addr                         "0x0031"
#define  set_PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg(data)                     (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile2_Diff_bin_H_reg))
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_ch1_pf2_diff_bin_h_shift          (0)
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_ch1_pf2_diff_bin_h_mask           (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_ch1_pf2_diff_bin_h(data)          (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile2_Diff_bin_H_get_ch1_pf2_diff_bin_h(data)      (0x00FFFFFF&(data))

#define  PROFILE_SRCDET_CONTROL                                                  0x18023700
#define  PROFILE_SRCDET_CONTROL_reg_addr                                         "0xB8023700"
#define  PROFILE_SRCDET_CONTROL_reg                                              0xB8023700
#define  PROFILE_SRCDET_CONTROL_inst_addr                                        "0x0032"
#define  set_PROFILE_SRCDET_CONTROL_reg(data)                                    (*((volatile unsigned int*)PROFILE_SRCDET_CONTROL_reg)=data)
#define  get_PROFILE_SRCDET_CONTROL_reg                                          (*((volatile unsigned int*)PROFILE_SRCDET_CONTROL_reg))
#define  PROFILE_SRCDET_CONTROL_srcdet_pmh_depend_tsh_shift                      (4)
#define  PROFILE_SRCDET_CONTROL_srcdet_start_shift                               (0)
#define  PROFILE_SRCDET_CONTROL_srcdet_pmh_depend_tsh_mask                       (0x00000010)
#define  PROFILE_SRCDET_CONTROL_srcdet_start_mask                                (0x00000001)
#define  PROFILE_SRCDET_CONTROL_srcdet_pmh_depend_tsh(data)                      (0x00000010&((data)<<4))
#define  PROFILE_SRCDET_CONTROL_srcdet_start(data)                               (0x00000001&(data))
#define  PROFILE_SRCDET_CONTROL_get_srcdet_pmh_depend_tsh(data)                  ((0x00000010&(data))>>4)
#define  PROFILE_SRCDET_CONTROL_get_srcdet_start(data)                           (0x00000001&(data))

#define  PROFILE_SRCDET_TSH_STEP_THL                                             0x18023704
#define  PROFILE_SRCDET_TSH_STEP_THL_reg_addr                                    "0xB8023704"
#define  PROFILE_SRCDET_TSH_STEP_THL_reg                                         0xB8023704
#define  PROFILE_SRCDET_TSH_STEP_THL_inst_addr                                   "0x0033"
#define  set_PROFILE_SRCDET_TSH_STEP_THL_reg(data)                               (*((volatile unsigned int*)PROFILE_SRCDET_TSH_STEP_THL_reg)=data)
#define  get_PROFILE_SRCDET_TSH_STEP_THL_reg                                     (*((volatile unsigned int*)PROFILE_SRCDET_TSH_STEP_THL_reg))
#define  PROFILE_SRCDET_TSH_STEP_THL_srcdet_tsh_step_thl_shift                   (0)
#define  PROFILE_SRCDET_TSH_STEP_THL_srcdet_tsh_step_thl_mask                    (0x000000FF)
#define  PROFILE_SRCDET_TSH_STEP_THL_srcdet_tsh_step_thl(data)                   (0x000000FF&(data))
#define  PROFILE_SRCDET_TSH_STEP_THL_get_srcdet_tsh_step_thl(data)               (0x000000FF&(data))

#define  PROFILE_SRCDET_TSH_STEP_MAX                                             0x18023708
#define  PROFILE_SRCDET_TSH_STEP_MAX_reg_addr                                    "0xB8023708"
#define  PROFILE_SRCDET_TSH_STEP_MAX_reg                                         0xB8023708
#define  PROFILE_SRCDET_TSH_STEP_MAX_inst_addr                                   "0x0034"
#define  set_PROFILE_SRCDET_TSH_STEP_MAX_reg(data)                               (*((volatile unsigned int*)PROFILE_SRCDET_TSH_STEP_MAX_reg)=data)
#define  get_PROFILE_SRCDET_TSH_STEP_MAX_reg                                     (*((volatile unsigned int*)PROFILE_SRCDET_TSH_STEP_MAX_reg))
#define  PROFILE_SRCDET_TSH_STEP_MAX_srcdet_tsh_step_max_shift                   (0)
#define  PROFILE_SRCDET_TSH_STEP_MAX_srcdet_tsh_step_max_mask                    (0x0000001F)
#define  PROFILE_SRCDET_TSH_STEP_MAX_srcdet_tsh_step_max(data)                   (0x0000001F&(data))
#define  PROFILE_SRCDET_TSH_STEP_MAX_get_srcdet_tsh_step_max(data)               (0x0000001F&(data))

#define  PROFILE_SRCDET_TSH_STEP_MIN                                             0x1802370C
#define  PROFILE_SRCDET_TSH_STEP_MIN_reg_addr                                    "0xB802370C"
#define  PROFILE_SRCDET_TSH_STEP_MIN_reg                                         0xB802370C
#define  PROFILE_SRCDET_TSH_STEP_MIN_inst_addr                                   "0x0035"
#define  set_PROFILE_SRCDET_TSH_STEP_MIN_reg(data)                               (*((volatile unsigned int*)PROFILE_SRCDET_TSH_STEP_MIN_reg)=data)
#define  get_PROFILE_SRCDET_TSH_STEP_MIN_reg                                     (*((volatile unsigned int*)PROFILE_SRCDET_TSH_STEP_MIN_reg))
#define  PROFILE_SRCDET_TSH_STEP_MIN_srcdet_tsh_step_min_shift                   (0)
#define  PROFILE_SRCDET_TSH_STEP_MIN_srcdet_tsh_step_min_mask                    (0x0000001F)
#define  PROFILE_SRCDET_TSH_STEP_MIN_srcdet_tsh_step_min(data)                   (0x0000001F&(data))
#define  PROFILE_SRCDET_TSH_STEP_MIN_get_srcdet_tsh_step_min(data)               (0x0000001F&(data))

#define  PROFILE_SRCDET_TSH_HIST01                                               0x18023710
#define  PROFILE_SRCDET_TSH_HIST01_reg_addr                                      "0xB8023710"
#define  PROFILE_SRCDET_TSH_HIST01_reg                                           0xB8023710
#define  PROFILE_SRCDET_TSH_HIST01_inst_addr                                     "0x0036"
#define  set_PROFILE_SRCDET_TSH_HIST01_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST01_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST01_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST01_reg))
#define  PROFILE_SRCDET_TSH_HIST01_srcdet_tsh_hist01_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST01_srcdet_tsh_hist01_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST01_srcdet_tsh_hist01(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST01_get_srcdet_tsh_hist01(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST02                                               0x18023714
#define  PROFILE_SRCDET_TSH_HIST02_reg_addr                                      "0xB8023714"
#define  PROFILE_SRCDET_TSH_HIST02_reg                                           0xB8023714
#define  PROFILE_SRCDET_TSH_HIST02_inst_addr                                     "0x0037"
#define  set_PROFILE_SRCDET_TSH_HIST02_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST02_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST02_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST02_reg))
#define  PROFILE_SRCDET_TSH_HIST02_srcdet_tsh_hist02_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST02_srcdet_tsh_hist02_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST02_srcdet_tsh_hist02(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST02_get_srcdet_tsh_hist02(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST03                                               0x18023718
#define  PROFILE_SRCDET_TSH_HIST03_reg_addr                                      "0xB8023718"
#define  PROFILE_SRCDET_TSH_HIST03_reg                                           0xB8023718
#define  PROFILE_SRCDET_TSH_HIST03_inst_addr                                     "0x0038"
#define  set_PROFILE_SRCDET_TSH_HIST03_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST03_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST03_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST03_reg))
#define  PROFILE_SRCDET_TSH_HIST03_srcdet_tsh_hist03_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST03_srcdet_tsh_hist03_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST03_srcdet_tsh_hist03(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST03_get_srcdet_tsh_hist03(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST04                                               0x1802371C
#define  PROFILE_SRCDET_TSH_HIST04_reg_addr                                      "0xB802371C"
#define  PROFILE_SRCDET_TSH_HIST04_reg                                           0xB802371C
#define  PROFILE_SRCDET_TSH_HIST04_inst_addr                                     "0x0039"
#define  set_PROFILE_SRCDET_TSH_HIST04_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST04_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST04_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST04_reg))
#define  PROFILE_SRCDET_TSH_HIST04_srcdet_tsh_hist04_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST04_srcdet_tsh_hist04_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST04_srcdet_tsh_hist04(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST04_get_srcdet_tsh_hist04(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST05                                               0x18023720
#define  PROFILE_SRCDET_TSH_HIST05_reg_addr                                      "0xB8023720"
#define  PROFILE_SRCDET_TSH_HIST05_reg                                           0xB8023720
#define  PROFILE_SRCDET_TSH_HIST05_inst_addr                                     "0x003A"
#define  set_PROFILE_SRCDET_TSH_HIST05_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST05_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST05_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST05_reg))
#define  PROFILE_SRCDET_TSH_HIST05_srcdet_tsh_hist05_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST05_srcdet_tsh_hist05_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST05_srcdet_tsh_hist05(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST05_get_srcdet_tsh_hist05(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST06                                               0x18023724
#define  PROFILE_SRCDET_TSH_HIST06_reg_addr                                      "0xB8023724"
#define  PROFILE_SRCDET_TSH_HIST06_reg                                           0xB8023724
#define  PROFILE_SRCDET_TSH_HIST06_inst_addr                                     "0x003B"
#define  set_PROFILE_SRCDET_TSH_HIST06_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST06_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST06_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST06_reg))
#define  PROFILE_SRCDET_TSH_HIST06_srcdet_tsh_hist06_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST06_srcdet_tsh_hist06_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST06_srcdet_tsh_hist06(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST06_get_srcdet_tsh_hist06(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST07                                               0x18023728
#define  PROFILE_SRCDET_TSH_HIST07_reg_addr                                      "0xB8023728"
#define  PROFILE_SRCDET_TSH_HIST07_reg                                           0xB8023728
#define  PROFILE_SRCDET_TSH_HIST07_inst_addr                                     "0x003C"
#define  set_PROFILE_SRCDET_TSH_HIST07_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST07_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST07_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST07_reg))
#define  PROFILE_SRCDET_TSH_HIST07_srcdet_tsh_hist07_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST07_srcdet_tsh_hist07_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST07_srcdet_tsh_hist07(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST07_get_srcdet_tsh_hist07(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST08                                               0x1802372C
#define  PROFILE_SRCDET_TSH_HIST08_reg_addr                                      "0xB802372C"
#define  PROFILE_SRCDET_TSH_HIST08_reg                                           0xB802372C
#define  PROFILE_SRCDET_TSH_HIST08_inst_addr                                     "0x003D"
#define  set_PROFILE_SRCDET_TSH_HIST08_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST08_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST08_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST08_reg))
#define  PROFILE_SRCDET_TSH_HIST08_srcdet_tsh_hist08_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST08_srcdet_tsh_hist08_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST08_srcdet_tsh_hist08(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST08_get_srcdet_tsh_hist08(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST09                                               0x18023730
#define  PROFILE_SRCDET_TSH_HIST09_reg_addr                                      "0xB8023730"
#define  PROFILE_SRCDET_TSH_HIST09_reg                                           0xB8023730
#define  PROFILE_SRCDET_TSH_HIST09_inst_addr                                     "0x003E"
#define  set_PROFILE_SRCDET_TSH_HIST09_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST09_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST09_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST09_reg))
#define  PROFILE_SRCDET_TSH_HIST09_srcdet_tsh_hist09_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST09_srcdet_tsh_hist09_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST09_srcdet_tsh_hist09(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST09_get_srcdet_tsh_hist09(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST10                                               0x18023734
#define  PROFILE_SRCDET_TSH_HIST10_reg_addr                                      "0xB8023734"
#define  PROFILE_SRCDET_TSH_HIST10_reg                                           0xB8023734
#define  PROFILE_SRCDET_TSH_HIST10_inst_addr                                     "0x003F"
#define  set_PROFILE_SRCDET_TSH_HIST10_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST10_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST10_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST10_reg))
#define  PROFILE_SRCDET_TSH_HIST10_srcdet_tsh_hist10_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST10_srcdet_tsh_hist10_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST10_srcdet_tsh_hist10(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST10_get_srcdet_tsh_hist10(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST11                                               0x18023738
#define  PROFILE_SRCDET_TSH_HIST11_reg_addr                                      "0xB8023738"
#define  PROFILE_SRCDET_TSH_HIST11_reg                                           0xB8023738
#define  PROFILE_SRCDET_TSH_HIST11_inst_addr                                     "0x0040"
#define  set_PROFILE_SRCDET_TSH_HIST11_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST11_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST11_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST11_reg))
#define  PROFILE_SRCDET_TSH_HIST11_srcdet_tsh_hist11_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST11_srcdet_tsh_hist11_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST11_srcdet_tsh_hist11(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST11_get_srcdet_tsh_hist11(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST12                                               0x1802373C
#define  PROFILE_SRCDET_TSH_HIST12_reg_addr                                      "0xB802373C"
#define  PROFILE_SRCDET_TSH_HIST12_reg                                           0xB802373C
#define  PROFILE_SRCDET_TSH_HIST12_inst_addr                                     "0x0041"
#define  set_PROFILE_SRCDET_TSH_HIST12_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST12_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST12_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST12_reg))
#define  PROFILE_SRCDET_TSH_HIST12_srcdet_tsh_hist12_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST12_srcdet_tsh_hist12_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST12_srcdet_tsh_hist12(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST12_get_srcdet_tsh_hist12(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST13                                               0x18023740
#define  PROFILE_SRCDET_TSH_HIST13_reg_addr                                      "0xB8023740"
#define  PROFILE_SRCDET_TSH_HIST13_reg                                           0xB8023740
#define  PROFILE_SRCDET_TSH_HIST13_inst_addr                                     "0x0042"
#define  set_PROFILE_SRCDET_TSH_HIST13_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST13_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST13_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST13_reg))
#define  PROFILE_SRCDET_TSH_HIST13_srcdet_tsh_hist13_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST13_srcdet_tsh_hist13_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST13_srcdet_tsh_hist13(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST13_get_srcdet_tsh_hist13(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST14                                               0x18023744
#define  PROFILE_SRCDET_TSH_HIST14_reg_addr                                      "0xB8023744"
#define  PROFILE_SRCDET_TSH_HIST14_reg                                           0xB8023744
#define  PROFILE_SRCDET_TSH_HIST14_inst_addr                                     "0x0043"
#define  set_PROFILE_SRCDET_TSH_HIST14_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST14_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST14_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST14_reg))
#define  PROFILE_SRCDET_TSH_HIST14_srcdet_tsh_hist14_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST14_srcdet_tsh_hist14_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST14_srcdet_tsh_hist14(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST14_get_srcdet_tsh_hist14(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST15                                               0x18023748
#define  PROFILE_SRCDET_TSH_HIST15_reg_addr                                      "0xB8023748"
#define  PROFILE_SRCDET_TSH_HIST15_reg                                           0xB8023748
#define  PROFILE_SRCDET_TSH_HIST15_inst_addr                                     "0x0044"
#define  set_PROFILE_SRCDET_TSH_HIST15_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST15_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST15_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST15_reg))
#define  PROFILE_SRCDET_TSH_HIST15_srcdet_tsh_hist15_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST15_srcdet_tsh_hist15_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST15_srcdet_tsh_hist15(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST15_get_srcdet_tsh_hist15(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST16                                               0x1802374C
#define  PROFILE_SRCDET_TSH_HIST16_reg_addr                                      "0xB802374C"
#define  PROFILE_SRCDET_TSH_HIST16_reg                                           0xB802374C
#define  PROFILE_SRCDET_TSH_HIST16_inst_addr                                     "0x0045"
#define  set_PROFILE_SRCDET_TSH_HIST16_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST16_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST16_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST16_reg))
#define  PROFILE_SRCDET_TSH_HIST16_srcdet_tsh_hist16_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST16_srcdet_tsh_hist16_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST16_srcdet_tsh_hist16(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST16_get_srcdet_tsh_hist16(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST17                                               0x18023750
#define  PROFILE_SRCDET_TSH_HIST17_reg_addr                                      "0xB8023750"
#define  PROFILE_SRCDET_TSH_HIST17_reg                                           0xB8023750
#define  PROFILE_SRCDET_TSH_HIST17_inst_addr                                     "0x0046"
#define  set_PROFILE_SRCDET_TSH_HIST17_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST17_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST17_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST17_reg))
#define  PROFILE_SRCDET_TSH_HIST17_srcdet_tsh_hist17_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST17_srcdet_tsh_hist17_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST17_srcdet_tsh_hist17(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST17_get_srcdet_tsh_hist17(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST18                                               0x18023754
#define  PROFILE_SRCDET_TSH_HIST18_reg_addr                                      "0xB8023754"
#define  PROFILE_SRCDET_TSH_HIST18_reg                                           0xB8023754
#define  PROFILE_SRCDET_TSH_HIST18_inst_addr                                     "0x0047"
#define  set_PROFILE_SRCDET_TSH_HIST18_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST18_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST18_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST18_reg))
#define  PROFILE_SRCDET_TSH_HIST18_srcdet_tsh_hist18_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST18_srcdet_tsh_hist18_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST18_srcdet_tsh_hist18(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST18_get_srcdet_tsh_hist18(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST19                                               0x18023758
#define  PROFILE_SRCDET_TSH_HIST19_reg_addr                                      "0xB8023758"
#define  PROFILE_SRCDET_TSH_HIST19_reg                                           0xB8023758
#define  PROFILE_SRCDET_TSH_HIST19_inst_addr                                     "0x0048"
#define  set_PROFILE_SRCDET_TSH_HIST19_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST19_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST19_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST19_reg))
#define  PROFILE_SRCDET_TSH_HIST19_srcdet_tsh_hist19_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST19_srcdet_tsh_hist19_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST19_srcdet_tsh_hist19(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST19_get_srcdet_tsh_hist19(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_TSH_HIST20                                               0x1802375C
#define  PROFILE_SRCDET_TSH_HIST20_reg_addr                                      "0xB802375C"
#define  PROFILE_SRCDET_TSH_HIST20_reg                                           0xB802375C
#define  PROFILE_SRCDET_TSH_HIST20_inst_addr                                     "0x0049"
#define  set_PROFILE_SRCDET_TSH_HIST20_reg(data)                                 (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST20_reg)=data)
#define  get_PROFILE_SRCDET_TSH_HIST20_reg                                       (*((volatile unsigned int*)PROFILE_SRCDET_TSH_HIST20_reg))
#define  PROFILE_SRCDET_TSH_HIST20_srcdet_tsh_hist20_shift                       (0)
#define  PROFILE_SRCDET_TSH_HIST20_srcdet_tsh_hist20_mask                        (0x003FFFFF)
#define  PROFILE_SRCDET_TSH_HIST20_srcdet_tsh_hist20(data)                       (0x003FFFFF&(data))
#define  PROFILE_SRCDET_TSH_HIST20_get_srcdet_tsh_hist20(data)                   (0x003FFFFF&(data))

#define  PROFILE_SRCDET_PMH_HIST0                                                0x18023760
#define  PROFILE_SRCDET_PMH_HIST0_reg_addr                                       "0xB8023760"
#define  PROFILE_SRCDET_PMH_HIST0_reg                                            0xB8023760
#define  PROFILE_SRCDET_PMH_HIST0_inst_addr                                      "0x004A"
#define  set_PROFILE_SRCDET_PMH_HIST0_reg(data)                                  (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST0_reg)=data)
#define  get_PROFILE_SRCDET_PMH_HIST0_reg                                        (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST0_reg))
#define  PROFILE_SRCDET_PMH_HIST0_srcdet_pmh_hist0_shift                         (0)
#define  PROFILE_SRCDET_PMH_HIST0_srcdet_pmh_hist0_mask                          (0x003FFFFF)
#define  PROFILE_SRCDET_PMH_HIST0_srcdet_pmh_hist0(data)                         (0x003FFFFF&(data))
#define  PROFILE_SRCDET_PMH_HIST0_get_srcdet_pmh_hist0(data)                     (0x003FFFFF&(data))

#define  PROFILE_SRCDET_PMH_HIST1                                                0x18023764
#define  PROFILE_SRCDET_PMH_HIST1_reg_addr                                       "0xB8023764"
#define  PROFILE_SRCDET_PMH_HIST1_reg                                            0xB8023764
#define  PROFILE_SRCDET_PMH_HIST1_inst_addr                                      "0x004B"
#define  set_PROFILE_SRCDET_PMH_HIST1_reg(data)                                  (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST1_reg)=data)
#define  get_PROFILE_SRCDET_PMH_HIST1_reg                                        (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST1_reg))
#define  PROFILE_SRCDET_PMH_HIST1_srcdet_pmh_hist1_shift                         (0)
#define  PROFILE_SRCDET_PMH_HIST1_srcdet_pmh_hist1_mask                          (0x003FFFFF)
#define  PROFILE_SRCDET_PMH_HIST1_srcdet_pmh_hist1(data)                         (0x003FFFFF&(data))
#define  PROFILE_SRCDET_PMH_HIST1_get_srcdet_pmh_hist1(data)                     (0x003FFFFF&(data))

#define  PROFILE_SRCDET_PMH_HIST2                                                0x18023768
#define  PROFILE_SRCDET_PMH_HIST2_reg_addr                                       "0xB8023768"
#define  PROFILE_SRCDET_PMH_HIST2_reg                                            0xB8023768
#define  PROFILE_SRCDET_PMH_HIST2_inst_addr                                      "0x004C"
#define  set_PROFILE_SRCDET_PMH_HIST2_reg(data)                                  (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST2_reg)=data)
#define  get_PROFILE_SRCDET_PMH_HIST2_reg                                        (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST2_reg))
#define  PROFILE_SRCDET_PMH_HIST2_srcdet_pmh_hist2_shift                         (0)
#define  PROFILE_SRCDET_PMH_HIST2_srcdet_pmh_hist2_mask                          (0x003FFFFF)
#define  PROFILE_SRCDET_PMH_HIST2_srcdet_pmh_hist2(data)                         (0x003FFFFF&(data))
#define  PROFILE_SRCDET_PMH_HIST2_get_srcdet_pmh_hist2(data)                     (0x003FFFFF&(data))

#define  PROFILE_SRCDET_PMH_HIST3                                                0x1802376C
#define  PROFILE_SRCDET_PMH_HIST3_reg_addr                                       "0xB802376C"
#define  PROFILE_SRCDET_PMH_HIST3_reg                                            0xB802376C
#define  PROFILE_SRCDET_PMH_HIST3_inst_addr                                      "0x004D"
#define  set_PROFILE_SRCDET_PMH_HIST3_reg(data)                                  (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST3_reg)=data)
#define  get_PROFILE_SRCDET_PMH_HIST3_reg                                        (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST3_reg))
#define  PROFILE_SRCDET_PMH_HIST3_srcdet_pmh_hist3_shift                         (0)
#define  PROFILE_SRCDET_PMH_HIST3_srcdet_pmh_hist3_mask                          (0x003FFFFF)
#define  PROFILE_SRCDET_PMH_HIST3_srcdet_pmh_hist3(data)                         (0x003FFFFF&(data))
#define  PROFILE_SRCDET_PMH_HIST3_get_srcdet_pmh_hist3(data)                     (0x003FFFFF&(data))

#define  PROFILE_SRCDET_PMH_HIST4                                                0x18023770
#define  PROFILE_SRCDET_PMH_HIST4_reg_addr                                       "0xB8023770"
#define  PROFILE_SRCDET_PMH_HIST4_reg                                            0xB8023770
#define  PROFILE_SRCDET_PMH_HIST4_inst_addr                                      "0x004E"
#define  set_PROFILE_SRCDET_PMH_HIST4_reg(data)                                  (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST4_reg)=data)
#define  get_PROFILE_SRCDET_PMH_HIST4_reg                                        (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST4_reg))
#define  PROFILE_SRCDET_PMH_HIST4_srcdet_pmh_hist4_shift                         (0)
#define  PROFILE_SRCDET_PMH_HIST4_srcdet_pmh_hist4_mask                          (0x003FFFFF)
#define  PROFILE_SRCDET_PMH_HIST4_srcdet_pmh_hist4(data)                         (0x003FFFFF&(data))
#define  PROFILE_SRCDET_PMH_HIST4_get_srcdet_pmh_hist4(data)                     (0x003FFFFF&(data))

#define  PROFILE_SRCDET_PMH_HIST5                                                0x18023774
#define  PROFILE_SRCDET_PMH_HIST5_reg_addr                                       "0xB8023774"
#define  PROFILE_SRCDET_PMH_HIST5_reg                                            0xB8023774
#define  PROFILE_SRCDET_PMH_HIST5_inst_addr                                      "0x004F"
#define  set_PROFILE_SRCDET_PMH_HIST5_reg(data)                                  (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST5_reg)=data)
#define  get_PROFILE_SRCDET_PMH_HIST5_reg                                        (*((volatile unsigned int*)PROFILE_SRCDET_PMH_HIST5_reg))
#define  PROFILE_SRCDET_PMH_HIST5_srcdet_pmh_hist5_shift                         (0)
#define  PROFILE_SRCDET_PMH_HIST5_srcdet_pmh_hist5_mask                          (0x003FFFFF)
#define  PROFILE_SRCDET_PMH_HIST5_srcdet_pmh_hist5(data)                         (0x003FFFFF&(data))
#define  PROFILE_SRCDET_PMH_HIST5_get_srcdet_pmh_hist5(data)                     (0x003FFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_CTRL                                         0x18023780
#define  PROFILE_ICH1_Hist_Profile3_CTRL_reg_addr                                "0xB8023780"
#define  PROFILE_ICH1_Hist_Profile3_CTRL_reg                                     0xB8023780
#define  PROFILE_ICH1_Hist_Profile3_CTRL_inst_addr                               "0x0050"
#define  set_PROFILE_ICH1_Hist_Profile3_CTRL_reg(data)                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_CTRL_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_CTRL_reg                                 (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_CTRL_reg))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_yuv_sel_shift                   (11)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_hnsr_shift                      (6)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_vnsr_shift                      (4)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_field_sel_shift                 (2)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_overflow_sel_shift              (1)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_enable_profile_shift            (0)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_yuv_sel_mask                    (0x00001800)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_hnsr_mask                       (0x000000C0)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_vnsr_mask                       (0x00000030)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_field_sel_mask                  (0x0000000C)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_overflow_sel_mask               (0x00000002)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_enable_profile_mask             (0x00000001)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_yuv_sel(data)                   (0x00001800&((data)<<11))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_hnsr(data)                      (0x000000C0&((data)<<6))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_vnsr(data)                      (0x00000030&((data)<<4))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_field_sel(data)                 (0x0000000C&((data)<<2))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_overflow_sel(data)              (0x00000002&((data)<<1))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_ch1_pf3_enable_profile(data)            (0x00000001&(data))
#define  PROFILE_ICH1_Hist_Profile3_CTRL_get_ch1_pf3_yuv_sel(data)               ((0x00001800&(data))>>11)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_get_ch1_pf3_hnsr(data)                  ((0x000000C0&(data))>>6)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_get_ch1_pf3_vnsr(data)                  ((0x00000030&(data))>>4)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_get_ch1_pf3_field_sel(data)             ((0x0000000C&(data))>>2)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_get_ch1_pf3_overflow_sel(data)          ((0x00000002&(data))>>1)
#define  PROFILE_ICH1_Hist_Profile3_CTRL_get_ch1_pf3_enable_profile(data)        (0x00000001&(data))

#define  PROFILE_ICH1_Hist_Profile3_size                                         0x18023784
#define  PROFILE_ICH1_Hist_Profile3_size_reg_addr                                "0xB8023784"
#define  PROFILE_ICH1_Hist_Profile3_size_reg                                     0xB8023784
#define  PROFILE_ICH1_Hist_Profile3_size_inst_addr                               "0x0051"
#define  set_PROFILE_ICH1_Hist_Profile3_size_reg(data)                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_size_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_size_reg                                 (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_size_reg))
#define  PROFILE_ICH1_Hist_Profile3_size_ch1_pf3_vsize_shift                     (16)
#define  PROFILE_ICH1_Hist_Profile3_size_ch1_pf3_hsize_shift                     (0)
#define  PROFILE_ICH1_Hist_Profile3_size_ch1_pf3_vsize_mask                      (0x03FF0000)
#define  PROFILE_ICH1_Hist_Profile3_size_ch1_pf3_hsize_mask                      (0x000003FF)
#define  PROFILE_ICH1_Hist_Profile3_size_ch1_pf3_vsize(data)                     (0x03FF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_size_ch1_pf3_hsize(data)                     (0x000003FF&(data))
#define  PROFILE_ICH1_Hist_Profile3_size_get_ch1_pf3_vsize(data)                 ((0x03FF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_size_get_ch1_pf3_hsize(data)                 (0x000003FF&(data))

#define  PROFILE_ICH1_Hist_Profile3_StartH                                       0x18023788
#define  PROFILE_ICH1_Hist_Profile3_StartH_reg_addr                              "0xB8023788"
#define  PROFILE_ICH1_Hist_Profile3_StartH_reg                                   0xB8023788
#define  PROFILE_ICH1_Hist_Profile3_StartH_inst_addr                             "0x0052"
#define  set_PROFILE_ICH1_Hist_Profile3_StartH_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_StartH_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_StartH_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_StartH_reg))
#define  PROFILE_ICH1_Hist_Profile3_StartH_ch1_pf3_starth_shift                  (0)
#define  PROFILE_ICH1_Hist_Profile3_StartH_ch1_pf3_starth_mask                   (0x00003FFF)
#define  PROFILE_ICH1_Hist_Profile3_StartH_ch1_pf3_starth(data)                  (0x00003FFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_StartH_get_ch1_pf3_starth(data)              (0x00003FFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_StartV                                       0x1802378C
#define  PROFILE_ICH1_Hist_Profile3_StartV_reg_addr                              "0xB802378C"
#define  PROFILE_ICH1_Hist_Profile3_StartV_reg                                   0xB802378C
#define  PROFILE_ICH1_Hist_Profile3_StartV_inst_addr                             "0x0053"
#define  set_PROFILE_ICH1_Hist_Profile3_StartV_reg(data)                         (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_StartV_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_StartV_reg                               (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_StartV_reg))
#define  PROFILE_ICH1_Hist_Profile3_StartV_ch1_pf3_startv_shift                  (0)
#define  PROFILE_ICH1_Hist_Profile3_StartV_ch1_pf3_startv_mask                   (0x00003FFF)
#define  PROFILE_ICH1_Hist_Profile3_StartV_ch1_pf3_startv(data)                  (0x00003FFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_StartV_get_ch1_pf3_startv(data)              (0x00003FFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_00                                      0x18023790
#define  PROFILE_ICH1_Hist_Profile3_Data_00_reg_addr                             "0xB8023790"
#define  PROFILE_ICH1_Hist_Profile3_Data_00_reg                                  0xB8023790
#define  PROFILE_ICH1_Hist_Profile3_Data_00_inst_addr                            "0x0054"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_00_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_00_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_00_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_00_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_00_ch1_pf3_h01_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_00_ch1_pf3_h00_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_00_ch1_pf3_h01_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_00_ch1_pf3_h00_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_00_ch1_pf3_h01(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_00_ch1_pf3_h00(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_00_get_ch1_pf3_h01(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_00_get_ch1_pf3_h00(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_01                                      0x18023794
#define  PROFILE_ICH1_Hist_Profile3_Data_01_reg_addr                             "0xB8023794"
#define  PROFILE_ICH1_Hist_Profile3_Data_01_reg                                  0xB8023794
#define  PROFILE_ICH1_Hist_Profile3_Data_01_inst_addr                            "0x0055"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_01_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_01_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_01_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_01_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_01_ch1_pf3_h03_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_01_ch1_pf3_h02_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_01_ch1_pf3_h03_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_01_ch1_pf3_h02_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_01_ch1_pf3_h03(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_01_ch1_pf3_h02(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_01_get_ch1_pf3_h03(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_01_get_ch1_pf3_h02(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_02                                      0x18023798
#define  PROFILE_ICH1_Hist_Profile3_Data_02_reg_addr                             "0xB8023798"
#define  PROFILE_ICH1_Hist_Profile3_Data_02_reg                                  0xB8023798
#define  PROFILE_ICH1_Hist_Profile3_Data_02_inst_addr                            "0x0056"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_02_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_02_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_02_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_02_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_02_ch1_pf3_h05_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_02_ch1_pf3_h04_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_02_ch1_pf3_h05_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_02_ch1_pf3_h04_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_02_ch1_pf3_h05(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_02_ch1_pf3_h04(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_02_get_ch1_pf3_h05(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_02_get_ch1_pf3_h04(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_03                                      0x1802379C
#define  PROFILE_ICH1_Hist_Profile3_Data_03_reg_addr                             "0xB802379C"
#define  PROFILE_ICH1_Hist_Profile3_Data_03_reg                                  0xB802379C
#define  PROFILE_ICH1_Hist_Profile3_Data_03_inst_addr                            "0x0057"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_03_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_03_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_03_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_03_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_03_ch1_pf3_h07_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_03_ch1_pf3_h06_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_03_ch1_pf3_h07_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_03_ch1_pf3_h06_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_03_ch1_pf3_h07(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_03_ch1_pf3_h06(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_03_get_ch1_pf3_h07(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_03_get_ch1_pf3_h06(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_04                                      0x180237A0
#define  PROFILE_ICH1_Hist_Profile3_Data_04_reg_addr                             "0xB80237A0"
#define  PROFILE_ICH1_Hist_Profile3_Data_04_reg                                  0xB80237A0
#define  PROFILE_ICH1_Hist_Profile3_Data_04_inst_addr                            "0x0058"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_04_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_04_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_04_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_04_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_04_ch1_pf3_h09_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_04_ch1_pf3_h08_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_04_ch1_pf3_h09_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_04_ch1_pf3_h08_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_04_ch1_pf3_h09(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_04_ch1_pf3_h08(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_04_get_ch1_pf3_h09(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_04_get_ch1_pf3_h08(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_05                                      0x180237A4
#define  PROFILE_ICH1_Hist_Profile3_Data_05_reg_addr                             "0xB80237A4"
#define  PROFILE_ICH1_Hist_Profile3_Data_05_reg                                  0xB80237A4
#define  PROFILE_ICH1_Hist_Profile3_Data_05_inst_addr                            "0x0059"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_05_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_05_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_05_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_05_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_05_ch1_pf3_h11_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_05_ch1_pf3_h10_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_05_ch1_pf3_h11_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_05_ch1_pf3_h10_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_05_ch1_pf3_h11(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_05_ch1_pf3_h10(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_05_get_ch1_pf3_h11(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_05_get_ch1_pf3_h10(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_06                                      0x180237A8
#define  PROFILE_ICH1_Hist_Profile3_Data_06_reg_addr                             "0xB80237A8"
#define  PROFILE_ICH1_Hist_Profile3_Data_06_reg                                  0xB80237A8
#define  PROFILE_ICH1_Hist_Profile3_Data_06_inst_addr                            "0x005A"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_06_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_06_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_06_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_06_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_06_ch1_pf3_h13_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_06_ch1_pf3_h12_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_06_ch1_pf3_h13_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_06_ch1_pf3_h12_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_06_ch1_pf3_h13(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_06_ch1_pf3_h12(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_06_get_ch1_pf3_h13(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_06_get_ch1_pf3_h12(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_07                                      0x180237AC
#define  PROFILE_ICH1_Hist_Profile3_Data_07_reg_addr                             "0xB80237AC"
#define  PROFILE_ICH1_Hist_Profile3_Data_07_reg                                  0xB80237AC
#define  PROFILE_ICH1_Hist_Profile3_Data_07_inst_addr                            "0x005B"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_07_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_07_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_07_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_07_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_07_ch1_pf3_h15_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_07_ch1_pf3_h14_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_07_ch1_pf3_h15_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_07_ch1_pf3_h14_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_07_ch1_pf3_h15(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_07_ch1_pf3_h14(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_07_get_ch1_pf3_h15(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_07_get_ch1_pf3_h14(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_08                                      0x180237B0
#define  PROFILE_ICH1_Hist_Profile3_Data_08_reg_addr                             "0xB80237B0"
#define  PROFILE_ICH1_Hist_Profile3_Data_08_reg                                  0xB80237B0
#define  PROFILE_ICH1_Hist_Profile3_Data_08_inst_addr                            "0x005C"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_08_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_08_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_08_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_08_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_08_ch1_pf3_v01_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_08_ch1_pf3_v00_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_08_ch1_pf3_v01_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_08_ch1_pf3_v00_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_08_ch1_pf3_v01(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_08_ch1_pf3_v00(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_08_get_ch1_pf3_v01(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_08_get_ch1_pf3_v00(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_09                                      0x180237B4
#define  PROFILE_ICH1_Hist_Profile3_Data_09_reg_addr                             "0xB80237B4"
#define  PROFILE_ICH1_Hist_Profile3_Data_09_reg                                  0xB80237B4
#define  PROFILE_ICH1_Hist_Profile3_Data_09_inst_addr                            "0x005D"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_09_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_09_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_09_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_09_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_09_ch1_pf3_v03_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_09_ch1_pf3_v02_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_09_ch1_pf3_v03_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_09_ch1_pf3_v02_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_09_ch1_pf3_v03(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_09_ch1_pf3_v02(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_09_get_ch1_pf3_v03(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_09_get_ch1_pf3_v02(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_10                                      0x180237B8
#define  PROFILE_ICH1_Hist_Profile3_Data_10_reg_addr                             "0xB80237B8"
#define  PROFILE_ICH1_Hist_Profile3_Data_10_reg                                  0xB80237B8
#define  PROFILE_ICH1_Hist_Profile3_Data_10_inst_addr                            "0x005E"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_10_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_10_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_10_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_10_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_10_ch1_pf3_v05_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_10_ch1_pf3_v04_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_10_ch1_pf3_v05_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_10_ch1_pf3_v04_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_10_ch1_pf3_v05(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_10_ch1_pf3_v04(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_10_get_ch1_pf3_v05(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_10_get_ch1_pf3_v04(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_11                                      0x180237BC
#define  PROFILE_ICH1_Hist_Profile3_Data_11_reg_addr                             "0xB80237BC"
#define  PROFILE_ICH1_Hist_Profile3_Data_11_reg                                  0xB80237BC
#define  PROFILE_ICH1_Hist_Profile3_Data_11_inst_addr                            "0x005F"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_11_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_11_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_11_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_11_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_11_ch1_pf3_v07_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_11_ch1_pf3_v06_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_11_ch1_pf3_v07_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_11_ch1_pf3_v06_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_11_ch1_pf3_v07(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_11_ch1_pf3_v06(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_11_get_ch1_pf3_v07(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_11_get_ch1_pf3_v06(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_12                                      0x180237C0
#define  PROFILE_ICH1_Hist_Profile3_Data_12_reg_addr                             "0xB80237C0"
#define  PROFILE_ICH1_Hist_Profile3_Data_12_reg                                  0xB80237C0
#define  PROFILE_ICH1_Hist_Profile3_Data_12_inst_addr                            "0x0060"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_12_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_12_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_12_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_12_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_12_ch1_pf3_v09_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_12_ch1_pf3_v08_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_12_ch1_pf3_v09_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_12_ch1_pf3_v08_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_12_ch1_pf3_v09(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_12_ch1_pf3_v08(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_12_get_ch1_pf3_v09(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_12_get_ch1_pf3_v08(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_13                                      0x180237C4
#define  PROFILE_ICH1_Hist_Profile3_Data_13_reg_addr                             "0xB80237C4"
#define  PROFILE_ICH1_Hist_Profile3_Data_13_reg                                  0xB80237C4
#define  PROFILE_ICH1_Hist_Profile3_Data_13_inst_addr                            "0x0061"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_13_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_13_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_13_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_13_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_13_ch1_pf3_v11_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_13_ch1_pf3_v10_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_13_ch1_pf3_v11_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_13_ch1_pf3_v10_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_13_ch1_pf3_v11(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_13_ch1_pf3_v10(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_13_get_ch1_pf3_v11(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_13_get_ch1_pf3_v10(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_14                                      0x180237C8
#define  PROFILE_ICH1_Hist_Profile3_Data_14_reg_addr                             "0xB80237C8"
#define  PROFILE_ICH1_Hist_Profile3_Data_14_reg                                  0xB80237C8
#define  PROFILE_ICH1_Hist_Profile3_Data_14_inst_addr                            "0x0062"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_14_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_14_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_14_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_14_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_14_ch1_pf3_v13_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_14_ch1_pf3_v12_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_14_ch1_pf3_v13_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_14_ch1_pf3_v12_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_14_ch1_pf3_v13(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_14_ch1_pf3_v12(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_14_get_ch1_pf3_v13(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_14_get_ch1_pf3_v12(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Data_15                                      0x180237CC
#define  PROFILE_ICH1_Hist_Profile3_Data_15_reg_addr                             "0xB80237CC"
#define  PROFILE_ICH1_Hist_Profile3_Data_15_reg                                  0xB80237CC
#define  PROFILE_ICH1_Hist_Profile3_Data_15_inst_addr                            "0x0063"
#define  set_PROFILE_ICH1_Hist_Profile3_Data_15_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_15_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Data_15_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Data_15_reg))
#define  PROFILE_ICH1_Hist_Profile3_Data_15_ch1_pf3_v15_shift                    (16)
#define  PROFILE_ICH1_Hist_Profile3_Data_15_ch1_pf3_v14_shift                    (0)
#define  PROFILE_ICH1_Hist_Profile3_Data_15_ch1_pf3_v15_mask                     (0xFFFF0000)
#define  PROFILE_ICH1_Hist_Profile3_Data_15_ch1_pf3_v14_mask                     (0x0000FFFF)
#define  PROFILE_ICH1_Hist_Profile3_Data_15_ch1_pf3_v15(data)                    (0xFFFF0000&((data)<<16))
#define  PROFILE_ICH1_Hist_Profile3_Data_15_ch1_pf3_v14(data)                    (0x0000FFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Data_15_get_ch1_pf3_v15(data)                ((0xFFFF0000&(data))>>16)
#define  PROFILE_ICH1_Hist_Profile3_Data_15_get_ch1_pf3_v14(data)                (0x0000FFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Diff                                         0x180237D0
#define  PROFILE_ICH1_Hist_Profile3_Diff_reg_addr                                "0xB80237D0"
#define  PROFILE_ICH1_Hist_Profile3_Diff_reg                                     0xB80237D0
#define  PROFILE_ICH1_Hist_Profile3_Diff_inst_addr                               "0x0064"
#define  set_PROFILE_ICH1_Hist_Profile3_Diff_reg(data)                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Diff_reg                                 (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_reg))
#define  PROFILE_ICH1_Hist_Profile3_Diff_ch1_pf3_diffsum_shift                   (0)
#define  PROFILE_ICH1_Hist_Profile3_Diff_ch1_pf3_diffsum_mask                    (0x3FFFFFFF)
#define  PROFILE_ICH1_Hist_Profile3_Diff_ch1_pf3_diffsum(data)                   (0x3FFFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Diff_get_ch1_pf3_diffsum(data)               (0x3FFFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Diff_th                                      0x180237D4
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_reg_addr                             "0xB80237D4"
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_reg                                  0xB80237D4
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_inst_addr                            "0x0065"
#define  set_PROFILE_ICH1_Hist_Profile3_Diff_th_reg(data)                        (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_th_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Diff_th_reg                              (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_th_reg))
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_ch1_pf3_diff_th_h_shift              (8)
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_ch1_pf3_diff_th_l_shift              (0)
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_ch1_pf3_diff_th_h_mask               (0x0000FF00)
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_ch1_pf3_diff_th_l_mask               (0x000000FF)
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_ch1_pf3_diff_th_h(data)              (0x0000FF00&((data)<<8))
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_ch1_pf3_diff_th_l(data)              (0x000000FF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_get_ch1_pf3_diff_th_h(data)          ((0x0000FF00&(data))>>8)
#define  PROFILE_ICH1_Hist_Profile3_Diff_th_get_ch1_pf3_diff_th_l(data)          (0x000000FF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L                                   0x180237D8
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_reg_addr                          "0xB80237D8"
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_reg                               0xB80237D8
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_inst_addr                         "0x0066"
#define  set_PROFILE_ICH1_Hist_Profile3_Diff_bin_L_reg(data)                     (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_bin_L_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Diff_bin_L_reg                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_bin_L_reg))
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_ch1_pf3_diff_bin_l_shift          (0)
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_ch1_pf3_diff_bin_l_mask           (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_ch1_pf3_diff_bin_l(data)          (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_L_get_ch1_pf3_diff_bin_l(data)      (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M                                   0x180237DC
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_reg_addr                          "0xB80237DC"
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_reg                               0xB80237DC
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_inst_addr                         "0x0067"
#define  set_PROFILE_ICH1_Hist_Profile3_Diff_bin_M_reg(data)                     (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_bin_M_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Diff_bin_M_reg                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_bin_M_reg))
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_ch1_pf3_diff_bin_m_shift          (0)
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_ch1_pf3_diff_bin_m_mask           (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_ch1_pf3_diff_bin_m(data)          (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_M_get_ch1_pf3_diff_bin_m(data)      (0x00FFFFFF&(data))

#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H                                   0x180237E0
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg_addr                          "0xB80237E0"
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg                               0xB80237E0
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_inst_addr                         "0x0068"
#define  set_PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg(data)                     (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg)=data)
#define  get_PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg                           (*((volatile unsigned int*)PROFILE_ICH1_Hist_Profile3_Diff_bin_H_reg))
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_ch1_pf3_diff_bin_h_shift          (0)
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_ch1_pf3_diff_bin_h_mask           (0x00FFFFFF)
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_ch1_pf3_diff_bin_h(data)          (0x00FFFFFF&(data))
#define  PROFILE_ICH1_Hist_Profile3_Diff_bin_H_get_ch1_pf3_diff_bin_h(data)      (0x00FFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======PROFILE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  dummy18023400_18_16:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  en_4k2k_mode:1;
        RBus_UInt32  en_3d_mode:1;
        RBus_UInt32  ch1_pf_yuv_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  ch1_pf_hnsr:2;
        RBus_UInt32  ch1_pf_vnsr:2;
        RBus_UInt32  ch1_pf_field_sel:2;
        RBus_UInt32  ch1_pf_overflow_sel:1;
        RBus_UInt32  ch1_pf_enable_profile:1;
    };
}profile_ich1_hist_profile_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf_vsize:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_pf_hsize:10;
    };
}profile_ich1_hist_profile_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf_starth:14;
    };
}profile_ich1_hist_profile_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf_startv:14;
    };
}profile_ich1_hist_profile_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h01:16;
        RBus_UInt32  ch1_pf_h00:16;
    };
}profile_ich1_hist_profile_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h03:16;
        RBus_UInt32  ch1_pf_h02:16;
    };
}profile_ich1_hist_profile_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h05:16;
        RBus_UInt32  ch1_pf_h04:16;
    };
}profile_ich1_hist_profile_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h07:16;
        RBus_UInt32  ch1_pf_h06:16;
    };
}profile_ich1_hist_profile_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h09:16;
        RBus_UInt32  ch1_pf_h08:16;
    };
}profile_ich1_hist_profile_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h11:16;
        RBus_UInt32  ch1_pf_h10:16;
    };
}profile_ich1_hist_profile_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h13:16;
        RBus_UInt32  ch1_pf_h12:16;
    };
}profile_ich1_hist_profile_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h15:16;
        RBus_UInt32  ch1_pf_h14:16;
    };
}profile_ich1_hist_profile_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v01:16;
        RBus_UInt32  ch1_pf_v00:16;
    };
}profile_ich1_hist_profile_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v03:16;
        RBus_UInt32  ch1_pf_v02:16;
    };
}profile_ich1_hist_profile_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v05:16;
        RBus_UInt32  ch1_pf_v04:16;
    };
}profile_ich1_hist_profile_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v07:16;
        RBus_UInt32  ch1_pf_v06:16;
    };
}profile_ich1_hist_profile_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v09:16;
        RBus_UInt32  ch1_pf_v08:16;
    };
}profile_ich1_hist_profile_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v11:16;
        RBus_UInt32  ch1_pf_v10:16;
    };
}profile_ich1_hist_profile_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v13:16;
        RBus_UInt32  ch1_pf_v12:16;
    };
}profile_ich1_hist_profile_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v15:16;
        RBus_UInt32  ch1_pf_v14:16;
    };
}profile_ich1_hist_profile_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h01_right:16;
        RBus_UInt32  ch1_pf_h00_right:16;
    };
}profile_ich1_hist_profile_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h03_right:16;
        RBus_UInt32  ch1_pf_h02_right:16;
    };
}profile_ich1_hist_profile_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h05_right:16;
        RBus_UInt32  ch1_pf_h04_right:16;
    };
}profile_ich1_hist_profile_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h07_right:16;
        RBus_UInt32  ch1_pf_h06_right:16;
    };
}profile_ich1_hist_profile_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h09_right:16;
        RBus_UInt32  ch1_pf_h08_right:16;
    };
}profile_ich1_hist_profile_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h11_right:16;
        RBus_UInt32  ch1_pf_h10_right:16;
    };
}profile_ich1_hist_profile_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h13_right:16;
        RBus_UInt32  ch1_pf_h12_right:16;
    };
}profile_ich1_hist_profile_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h15_right:16;
        RBus_UInt32  ch1_pf_h14_right:16;
    };
}profile_ich1_hist_profile_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v01_right:16;
        RBus_UInt32  ch1_pf_v00_right:16;
    };
}profile_ich1_hist_profile_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v03_right:16;
        RBus_UInt32  ch1_pf_v02_right:16;
    };
}profile_ich1_hist_profile_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v05_right:16;
        RBus_UInt32  ch1_pf_v04_right:16;
    };
}profile_ich1_hist_profile_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v07_right:16;
        RBus_UInt32  ch1_pf_v06_right:16;
    };
}profile_ich1_hist_profile_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v09_right:16;
        RBus_UInt32  ch1_pf_v08_right:16;
    };
}profile_ich1_hist_profile_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v11_right:16;
        RBus_UInt32  ch1_pf_v10_right:16;
    };
}profile_ich1_hist_profile_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v13_right:16;
        RBus_UInt32  ch1_pf_v12_right:16;
    };
}profile_ich1_hist_profile_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v15_right:16;
        RBus_UInt32  ch1_pf_v14_right:16;
    };
}profile_ich1_hist_profile_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pf_diffsum:30;
    };
}profile_ich1_hist_profile_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ch1_pf_diff_th_h:8;
        RBus_UInt32  ch1_pf_diff_th_l:8;
    };
}profile_ich1_hist_profile_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf_diff_bin_l:24;
    };
}profile_ich1_hist_profile_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf_diff_bin_m:24;
    };
}profile_ich1_hist_profile_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf_diff_bin_h:24;
    };
}profile_ich1_hist_profile_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ch1_pf2_yuv_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_pf2_hnsr:2;
        RBus_UInt32  ch1_pf2_vnsr:2;
        RBus_UInt32  ch1_pf2_field_sel:2;
        RBus_UInt32  ch1_pf2_overflow_sel:1;
        RBus_UInt32  ch1_pf2_enable_profile:1;
    };
}profile_ich1_hist_profile2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf2_vsize:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_pf2_hsize:10;
    };
}profile_ich1_hist_profile2_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf2_starth:14;
    };
}profile_ich1_hist_profile2_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf2_startv:14;
    };
}profile_ich1_hist_profile2_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pf2_diffsum:30;
    };
}profile_ich1_hist_profile2_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ch1_pf2_diff_th_h:8;
        RBus_UInt32  ch1_pf2_diff_th_l:8;
    };
}profile_ich1_hist_profile2_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf2_diff_bin_l:24;
    };
}profile_ich1_hist_profile2_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf2_diff_bin_m:24;
    };
}profile_ich1_hist_profile2_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf2_diff_bin_h:24;
    };
}profile_ich1_hist_profile2_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  srcdet_pmh_depend_tsh:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  srcdet_start:1;
    };
}profile_srcdet_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  srcdet_tsh_step_thl:8;
    };
}profile_srcdet_tsh_step_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  srcdet_tsh_step_max:5;
    };
}profile_srcdet_tsh_step_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  srcdet_tsh_step_min:5;
    };
}profile_srcdet_tsh_step_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist01:22;
    };
}profile_srcdet_tsh_hist01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist02:22;
    };
}profile_srcdet_tsh_hist02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist03:22;
    };
}profile_srcdet_tsh_hist03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist04:22;
    };
}profile_srcdet_tsh_hist04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist05:22;
    };
}profile_srcdet_tsh_hist05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist06:22;
    };
}profile_srcdet_tsh_hist06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist07:22;
    };
}profile_srcdet_tsh_hist07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist08:22;
    };
}profile_srcdet_tsh_hist08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist09:22;
    };
}profile_srcdet_tsh_hist09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist10:22;
    };
}profile_srcdet_tsh_hist10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist11:22;
    };
}profile_srcdet_tsh_hist11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist12:22;
    };
}profile_srcdet_tsh_hist12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist13:22;
    };
}profile_srcdet_tsh_hist13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist14:22;
    };
}profile_srcdet_tsh_hist14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist15:22;
    };
}profile_srcdet_tsh_hist15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist16:22;
    };
}profile_srcdet_tsh_hist16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist17:22;
    };
}profile_srcdet_tsh_hist17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist18:22;
    };
}profile_srcdet_tsh_hist18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist19:22;
    };
}profile_srcdet_tsh_hist19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_tsh_hist20:22;
    };
}profile_srcdet_tsh_hist20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist0:22;
    };
}profile_srcdet_pmh_hist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist1:22;
    };
}profile_srcdet_pmh_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist2:22;
    };
}profile_srcdet_pmh_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist3:22;
    };
}profile_srcdet_pmh_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist4:22;
    };
}profile_srcdet_pmh_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  srcdet_pmh_hist5:22;
    };
}profile_srcdet_pmh_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ch1_pf3_yuv_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ch1_pf3_hnsr:2;
        RBus_UInt32  ch1_pf3_vnsr:2;
        RBus_UInt32  ch1_pf3_field_sel:2;
        RBus_UInt32  ch1_pf3_overflow_sel:1;
        RBus_UInt32  ch1_pf3_enable_profile:1;
    };
}profile_ich1_hist_profile3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf3_vsize:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ch1_pf3_hsize:10;
    };
}profile_ich1_hist_profile3_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf3_starth:14;
    };
}profile_ich1_hist_profile3_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ch1_pf3_startv:14;
    };
}profile_ich1_hist_profile3_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h01:16;
        RBus_UInt32  ch1_pf3_h00:16;
    };
}profile_ich1_hist_profile3_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h03:16;
        RBus_UInt32  ch1_pf3_h02:16;
    };
}profile_ich1_hist_profile3_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h05:16;
        RBus_UInt32  ch1_pf3_h04:16;
    };
}profile_ich1_hist_profile3_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h07:16;
        RBus_UInt32  ch1_pf3_h06:16;
    };
}profile_ich1_hist_profile3_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h09:16;
        RBus_UInt32  ch1_pf3_h08:16;
    };
}profile_ich1_hist_profile3_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h11:16;
        RBus_UInt32  ch1_pf3_h10:16;
    };
}profile_ich1_hist_profile3_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h13:16;
        RBus_UInt32  ch1_pf3_h12:16;
    };
}profile_ich1_hist_profile3_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h15:16;
        RBus_UInt32  ch1_pf3_h14:16;
    };
}profile_ich1_hist_profile3_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v01:16;
        RBus_UInt32  ch1_pf3_v00:16;
    };
}profile_ich1_hist_profile3_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v03:16;
        RBus_UInt32  ch1_pf3_v02:16;
    };
}profile_ich1_hist_profile3_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v05:16;
        RBus_UInt32  ch1_pf3_v04:16;
    };
}profile_ich1_hist_profile3_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v07:16;
        RBus_UInt32  ch1_pf3_v06:16;
    };
}profile_ich1_hist_profile3_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v09:16;
        RBus_UInt32  ch1_pf3_v08:16;
    };
}profile_ich1_hist_profile3_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v11:16;
        RBus_UInt32  ch1_pf3_v10:16;
    };
}profile_ich1_hist_profile3_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v13:16;
        RBus_UInt32  ch1_pf3_v12:16;
    };
}profile_ich1_hist_profile3_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v15:16;
        RBus_UInt32  ch1_pf3_v14:16;
    };
}profile_ich1_hist_profile3_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ch1_pf3_diffsum:30;
    };
}profile_ich1_hist_profile3_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ch1_pf3_diff_th_h:8;
        RBus_UInt32  ch1_pf3_diff_th_l:8;
    };
}profile_ich1_hist_profile3_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf3_diff_bin_l:24;
    };
}profile_ich1_hist_profile3_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf3_diff_bin_m:24;
    };
}profile_ich1_hist_profile3_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ch1_pf3_diff_bin_h:24;
    };
}profile_ich1_hist_profile3_diff_bin_h_RBUS;

#else //apply LITTLE_ENDIAN

//======PROFILE register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_enable_profile:1;
        RBus_UInt32  ch1_pf_overflow_sel:1;
        RBus_UInt32  ch1_pf_field_sel:2;
        RBus_UInt32  ch1_pf_vnsr:2;
        RBus_UInt32  ch1_pf_hnsr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pf_yuv_sel:2;
        RBus_UInt32  en_3d_mode:1;
        RBus_UInt32  en_4k2k_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  dummy18023400_18_16:3;
        RBus_UInt32  res4:13;
    };
}profile_ich1_hist_profile_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_hsize:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf_vsize:10;
        RBus_UInt32  res2:6;
    };
}profile_ich1_hist_profile_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_starth:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_startv:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h00:16;
        RBus_UInt32  ch1_pf_h01:16;
    };
}profile_ich1_hist_profile_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h02:16;
        RBus_UInt32  ch1_pf_h03:16;
    };
}profile_ich1_hist_profile_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h04:16;
        RBus_UInt32  ch1_pf_h05:16;
    };
}profile_ich1_hist_profile_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h06:16;
        RBus_UInt32  ch1_pf_h07:16;
    };
}profile_ich1_hist_profile_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h08:16;
        RBus_UInt32  ch1_pf_h09:16;
    };
}profile_ich1_hist_profile_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h10:16;
        RBus_UInt32  ch1_pf_h11:16;
    };
}profile_ich1_hist_profile_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h12:16;
        RBus_UInt32  ch1_pf_h13:16;
    };
}profile_ich1_hist_profile_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h14:16;
        RBus_UInt32  ch1_pf_h15:16;
    };
}profile_ich1_hist_profile_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v00:16;
        RBus_UInt32  ch1_pf_v01:16;
    };
}profile_ich1_hist_profile_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v02:16;
        RBus_UInt32  ch1_pf_v03:16;
    };
}profile_ich1_hist_profile_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v04:16;
        RBus_UInt32  ch1_pf_v05:16;
    };
}profile_ich1_hist_profile_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v06:16;
        RBus_UInt32  ch1_pf_v07:16;
    };
}profile_ich1_hist_profile_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v08:16;
        RBus_UInt32  ch1_pf_v09:16;
    };
}profile_ich1_hist_profile_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v10:16;
        RBus_UInt32  ch1_pf_v11:16;
    };
}profile_ich1_hist_profile_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v12:16;
        RBus_UInt32  ch1_pf_v13:16;
    };
}profile_ich1_hist_profile_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v14:16;
        RBus_UInt32  ch1_pf_v15:16;
    };
}profile_ich1_hist_profile_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h00_right:16;
        RBus_UInt32  ch1_pf_h01_right:16;
    };
}profile_ich1_hist_profile_data_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h02_right:16;
        RBus_UInt32  ch1_pf_h03_right:16;
    };
}profile_ich1_hist_profile_data_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h04_right:16;
        RBus_UInt32  ch1_pf_h05_right:16;
    };
}profile_ich1_hist_profile_data_18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h06_right:16;
        RBus_UInt32  ch1_pf_h07_right:16;
    };
}profile_ich1_hist_profile_data_19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h08_right:16;
        RBus_UInt32  ch1_pf_h09_right:16;
    };
}profile_ich1_hist_profile_data_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h10_right:16;
        RBus_UInt32  ch1_pf_h11_right:16;
    };
}profile_ich1_hist_profile_data_21_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h12_right:16;
        RBus_UInt32  ch1_pf_h13_right:16;
    };
}profile_ich1_hist_profile_data_22_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_h14_right:16;
        RBus_UInt32  ch1_pf_h15_right:16;
    };
}profile_ich1_hist_profile_data_23_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v00_right:16;
        RBus_UInt32  ch1_pf_v01_right:16;
    };
}profile_ich1_hist_profile_data_24_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v02_right:16;
        RBus_UInt32  ch1_pf_v03_right:16;
    };
}profile_ich1_hist_profile_data_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v04_right:16;
        RBus_UInt32  ch1_pf_v05_right:16;
    };
}profile_ich1_hist_profile_data_26_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v06_right:16;
        RBus_UInt32  ch1_pf_v07_right:16;
    };
}profile_ich1_hist_profile_data_27_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v08_right:16;
        RBus_UInt32  ch1_pf_v09_right:16;
    };
}profile_ich1_hist_profile_data_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v10_right:16;
        RBus_UInt32  ch1_pf_v11_right:16;
    };
}profile_ich1_hist_profile_data_29_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v12_right:16;
        RBus_UInt32  ch1_pf_v13_right:16;
    };
}profile_ich1_hist_profile_data_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_v14_right:16;
        RBus_UInt32  ch1_pf_v15_right:16;
    };
}profile_ich1_hist_profile_data_31_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diffsum:30;
        RBus_UInt32  res1:2;
    };
}profile_ich1_hist_profile_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_th_l:8;
        RBus_UInt32  ch1_pf_diff_th_h:8;
        RBus_UInt32  res1:16;
    };
}profile_ich1_hist_profile_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_bin_l:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_bin_m:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf_diff_bin_h:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_enable_profile:1;
        RBus_UInt32  ch1_pf2_overflow_sel:1;
        RBus_UInt32  ch1_pf2_field_sel:2;
        RBus_UInt32  ch1_pf2_vnsr:2;
        RBus_UInt32  ch1_pf2_hnsr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pf2_yuv_sel:2;
        RBus_UInt32  res3:19;
    };
}profile_ich1_hist_profile2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_hsize:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf2_vsize:10;
        RBus_UInt32  res2:6;
    };
}profile_ich1_hist_profile2_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_starth:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile2_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_startv:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile2_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diffsum:30;
        RBus_UInt32  res1:2;
    };
}profile_ich1_hist_profile2_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_th_l:8;
        RBus_UInt32  ch1_pf2_diff_th_h:8;
        RBus_UInt32  res1:16;
    };
}profile_ich1_hist_profile2_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_bin_l:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile2_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_bin_m:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile2_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf2_diff_bin_h:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile2_diff_bin_h_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_start:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  srcdet_pmh_depend_tsh:1;
        RBus_UInt32  res2:27;
    };
}profile_srcdet_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_step_thl:8;
        RBus_UInt32  res1:24;
    };
}profile_srcdet_tsh_step_thl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_step_max:5;
        RBus_UInt32  res1:27;
    };
}profile_srcdet_tsh_step_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_step_min:5;
        RBus_UInt32  res1:27;
    };
}profile_srcdet_tsh_step_min_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist01:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist02:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist03:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist04:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist05:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist06:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist07:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist08:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist09:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist10:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist11:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist12:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist13:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist14:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist15:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist16:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist17:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist18:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist18_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist19:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist19_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_tsh_hist20:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_tsh_hist20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist0:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist1:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist2:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist3:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist4:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srcdet_pmh_hist5:22;
        RBus_UInt32  res1:10;
    };
}profile_srcdet_pmh_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_enable_profile:1;
        RBus_UInt32  ch1_pf3_overflow_sel:1;
        RBus_UInt32  ch1_pf3_field_sel:2;
        RBus_UInt32  ch1_pf3_vnsr:2;
        RBus_UInt32  ch1_pf3_hnsr:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch1_pf3_yuv_sel:2;
        RBus_UInt32  res3:19;
    };
}profile_ich1_hist_profile3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_hsize:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ch1_pf3_vsize:10;
        RBus_UInt32  res2:6;
    };
}profile_ich1_hist_profile3_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_starth:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile3_starth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_startv:14;
        RBus_UInt32  res1:18;
    };
}profile_ich1_hist_profile3_startv_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h00:16;
        RBus_UInt32  ch1_pf3_h01:16;
    };
}profile_ich1_hist_profile3_data_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h02:16;
        RBus_UInt32  ch1_pf3_h03:16;
    };
}profile_ich1_hist_profile3_data_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h04:16;
        RBus_UInt32  ch1_pf3_h05:16;
    };
}profile_ich1_hist_profile3_data_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h06:16;
        RBus_UInt32  ch1_pf3_h07:16;
    };
}profile_ich1_hist_profile3_data_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h08:16;
        RBus_UInt32  ch1_pf3_h09:16;
    };
}profile_ich1_hist_profile3_data_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h10:16;
        RBus_UInt32  ch1_pf3_h11:16;
    };
}profile_ich1_hist_profile3_data_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h12:16;
        RBus_UInt32  ch1_pf3_h13:16;
    };
}profile_ich1_hist_profile3_data_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_h14:16;
        RBus_UInt32  ch1_pf3_h15:16;
    };
}profile_ich1_hist_profile3_data_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v00:16;
        RBus_UInt32  ch1_pf3_v01:16;
    };
}profile_ich1_hist_profile3_data_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v02:16;
        RBus_UInt32  ch1_pf3_v03:16;
    };
}profile_ich1_hist_profile3_data_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v04:16;
        RBus_UInt32  ch1_pf3_v05:16;
    };
}profile_ich1_hist_profile3_data_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v06:16;
        RBus_UInt32  ch1_pf3_v07:16;
    };
}profile_ich1_hist_profile3_data_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v08:16;
        RBus_UInt32  ch1_pf3_v09:16;
    };
}profile_ich1_hist_profile3_data_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v10:16;
        RBus_UInt32  ch1_pf3_v11:16;
    };
}profile_ich1_hist_profile3_data_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v12:16;
        RBus_UInt32  ch1_pf3_v13:16;
    };
}profile_ich1_hist_profile3_data_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_v14:16;
        RBus_UInt32  ch1_pf3_v15:16;
    };
}profile_ich1_hist_profile3_data_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diffsum:30;
        RBus_UInt32  res1:2;
    };
}profile_ich1_hist_profile3_diff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_th_l:8;
        RBus_UInt32  ch1_pf3_diff_th_h:8;
        RBus_UInt32  res1:16;
    };
}profile_ich1_hist_profile3_diff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_bin_l:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile3_diff_bin_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_bin_m:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile3_diff_bin_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch1_pf3_diff_bin_h:24;
        RBus_UInt32  res1:8;
    };
}profile_ich1_hist_profile3_diff_bin_h_RBUS;




#endif 


#endif 
