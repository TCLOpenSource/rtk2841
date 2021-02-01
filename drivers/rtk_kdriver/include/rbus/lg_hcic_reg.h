/**
* @file Mac5_DesignSpec-D_Domain_HCIC_TOP
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LG_HCIC_REG_H_
#define _RBUS_LG_HCIC_REG_H_

#include "rbus_types.h"



//  LG_HCIC Register Address
#define  LG_HCIC_HCIC_ctl                                                        0x1802A500
#define  LG_HCIC_HCIC_ctl_reg_addr                                               "0xB802A500"
#define  LG_HCIC_HCIC_ctl_reg                                                    0xB802A500
#define  LG_HCIC_HCIC_ctl_inst_addr                                              "0x0000"
#define  set_LG_HCIC_HCIC_ctl_reg(data)                                          (*((volatile unsigned int*)LG_HCIC_HCIC_ctl_reg)=data)
#define  get_LG_HCIC_HCIC_ctl_reg                                                (*((volatile unsigned int*)LG_HCIC_HCIC_ctl_reg))
#define  LG_HCIC_HCIC_ctl_user_timing_sel_shift                                  (12)
#define  LG_HCIC_HCIC_ctl_auto_detect_result_shift                               (8)
#define  LG_HCIC_HCIC_ctl_auto_detect_en_shift                                   (4)
#define  LG_HCIC_HCIC_ctl_frcon_shift                                            (1)
#define  LG_HCIC_HCIC_ctl_reverse_shift                                          (0)
#define  LG_HCIC_HCIC_ctl_user_timing_sel_mask                                   (0x00003000)
#define  LG_HCIC_HCIC_ctl_auto_detect_result_mask                                (0x00000300)
#define  LG_HCIC_HCIC_ctl_auto_detect_en_mask                                    (0x00000010)
#define  LG_HCIC_HCIC_ctl_frcon_mask                                             (0x00000002)
#define  LG_HCIC_HCIC_ctl_reverse_mask                                           (0x00000001)
#define  LG_HCIC_HCIC_ctl_user_timing_sel(data)                                  (0x00003000&((data)<<12))
#define  LG_HCIC_HCIC_ctl_auto_detect_result(data)                               (0x00000300&((data)<<8))
#define  LG_HCIC_HCIC_ctl_auto_detect_en(data)                                   (0x00000010&((data)<<4))
#define  LG_HCIC_HCIC_ctl_frcon(data)                                            (0x00000002&((data)<<1))
#define  LG_HCIC_HCIC_ctl_reverse(data)                                          (0x00000001&(data))
#define  LG_HCIC_HCIC_ctl_get_user_timing_sel(data)                              ((0x00003000&(data))>>12)
#define  LG_HCIC_HCIC_ctl_get_auto_detect_result(data)                           ((0x00000300&(data))>>8)
#define  LG_HCIC_HCIC_ctl_get_auto_detect_en(data)                               ((0x00000010&(data))>>4)
#define  LG_HCIC_HCIC_ctl_get_frcon(data)                                        ((0x00000002&(data))>>1)
#define  LG_HCIC_HCIC_ctl_get_reverse(data)                                      (0x00000001&(data))

#define  LG_HCIC_HCIC_reg000                                                     0x1802A504
#define  LG_HCIC_HCIC_reg000_reg_addr                                            "0xB802A504"
#define  LG_HCIC_HCIC_reg000_reg                                                 0xB802A504
#define  LG_HCIC_HCIC_reg000_inst_addr                                           "0x0001"
#define  set_LG_HCIC_HCIC_reg000_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg000_reg)=data)
#define  get_LG_HCIC_HCIC_reg000_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg000_reg))
#define  LG_HCIC_HCIC_reg000_hcic_reg000_shift                                   (24)
#define  LG_HCIC_HCIC_reg000_hcic_reg001_shift                                   (16)
#define  LG_HCIC_HCIC_reg000_hcic_reg002_shift                                   (8)
#define  LG_HCIC_HCIC_reg000_hcic_reg003_shift                                   (0)
#define  LG_HCIC_HCIC_reg000_hcic_reg000_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg000_hcic_reg001_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg000_hcic_reg002_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg000_hcic_reg003_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg000_hcic_reg000(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg000_hcic_reg001(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg000_hcic_reg002(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg000_hcic_reg003(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg000_get_hcic_reg000(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg000_get_hcic_reg001(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg000_get_hcic_reg002(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg000_get_hcic_reg003(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg004                                                     0x1802A508
#define  LG_HCIC_HCIC_reg004_reg_addr                                            "0xB802A508"
#define  LG_HCIC_HCIC_reg004_reg                                                 0xB802A508
#define  LG_HCIC_HCIC_reg004_inst_addr                                           "0x0002"
#define  set_LG_HCIC_HCIC_reg004_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg004_reg)=data)
#define  get_LG_HCIC_HCIC_reg004_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg004_reg))
#define  LG_HCIC_HCIC_reg004_hcic_reg004_shift                                   (24)
#define  LG_HCIC_HCIC_reg004_hcic_reg005_shift                                   (16)
#define  LG_HCIC_HCIC_reg004_hcic_reg006_shift                                   (8)
#define  LG_HCIC_HCIC_reg004_hcic_reg007_shift                                   (0)
#define  LG_HCIC_HCIC_reg004_hcic_reg004_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg004_hcic_reg005_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg004_hcic_reg006_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg004_hcic_reg007_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg004_hcic_reg004(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg004_hcic_reg005(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg004_hcic_reg006(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg004_hcic_reg007(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg004_get_hcic_reg004(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg004_get_hcic_reg005(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg004_get_hcic_reg006(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg004_get_hcic_reg007(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg008                                                     0x1802A50C
#define  LG_HCIC_HCIC_reg008_reg_addr                                            "0xB802A50C"
#define  LG_HCIC_HCIC_reg008_reg                                                 0xB802A50C
#define  LG_HCIC_HCIC_reg008_inst_addr                                           "0x0003"
#define  set_LG_HCIC_HCIC_reg008_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg008_reg)=data)
#define  get_LG_HCIC_HCIC_reg008_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg008_reg))
#define  LG_HCIC_HCIC_reg008_hcic_reg008_shift                                   (24)
#define  LG_HCIC_HCIC_reg008_hcic_reg009_shift                                   (16)
#define  LG_HCIC_HCIC_reg008_hcic_reg00a_shift                                   (8)
#define  LG_HCIC_HCIC_reg008_hcic_reg00b_shift                                   (0)
#define  LG_HCIC_HCIC_reg008_hcic_reg008_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg008_hcic_reg009_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg008_hcic_reg00a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg008_hcic_reg00b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg008_hcic_reg008(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg008_hcic_reg009(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg008_hcic_reg00a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg008_hcic_reg00b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg008_get_hcic_reg008(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg008_get_hcic_reg009(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg008_get_hcic_reg00a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg008_get_hcic_reg00b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg00c                                                     0x1802A510
#define  LG_HCIC_HCIC_reg00c_reg_addr                                            "0xB802A510"
#define  LG_HCIC_HCIC_reg00c_reg                                                 0xB802A510
#define  LG_HCIC_HCIC_reg00c_inst_addr                                           "0x0004"
#define  set_LG_HCIC_HCIC_reg00c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg00c_reg)=data)
#define  get_LG_HCIC_HCIC_reg00c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg00c_reg))
#define  LG_HCIC_HCIC_reg00c_hcic_reg00c_shift                                   (24)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00d_shift                                   (16)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00e_shift                                   (8)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00f_shift                                   (0)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg00c_hcic_reg00c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg00c_hcic_reg00d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg00c_hcic_reg00e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg00c_hcic_reg00f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg00c_get_hcic_reg00c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg00c_get_hcic_reg00d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg00c_get_hcic_reg00e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg00c_get_hcic_reg00f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg010                                                     0x1802A514
#define  LG_HCIC_HCIC_reg010_reg_addr                                            "0xB802A514"
#define  LG_HCIC_HCIC_reg010_reg                                                 0xB802A514
#define  LG_HCIC_HCIC_reg010_inst_addr                                           "0x0005"
#define  set_LG_HCIC_HCIC_reg010_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg010_reg)=data)
#define  get_LG_HCIC_HCIC_reg010_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg010_reg))
#define  LG_HCIC_HCIC_reg010_hcic_reg010_shift                                   (24)
#define  LG_HCIC_HCIC_reg010_hcic_reg011_shift                                   (16)
#define  LG_HCIC_HCIC_reg010_hcic_reg012_shift                                   (8)
#define  LG_HCIC_HCIC_reg010_hcic_reg013_shift                                   (0)
#define  LG_HCIC_HCIC_reg010_hcic_reg010_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg010_hcic_reg011_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg010_hcic_reg012_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg010_hcic_reg013_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg010_hcic_reg010(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg010_hcic_reg011(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg010_hcic_reg012(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg010_hcic_reg013(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg010_get_hcic_reg010(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg010_get_hcic_reg011(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg010_get_hcic_reg012(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg010_get_hcic_reg013(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg014                                                     0x1802A518
#define  LG_HCIC_HCIC_reg014_reg_addr                                            "0xB802A518"
#define  LG_HCIC_HCIC_reg014_reg                                                 0xB802A518
#define  LG_HCIC_HCIC_reg014_inst_addr                                           "0x0006"
#define  set_LG_HCIC_HCIC_reg014_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg014_reg)=data)
#define  get_LG_HCIC_HCIC_reg014_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg014_reg))
#define  LG_HCIC_HCIC_reg014_hcic_reg014_shift                                   (24)
#define  LG_HCIC_HCIC_reg014_hcic_reg015_shift                                   (16)
#define  LG_HCIC_HCIC_reg014_hcic_reg016_shift                                   (8)
#define  LG_HCIC_HCIC_reg014_hcic_reg017_shift                                   (0)
#define  LG_HCIC_HCIC_reg014_hcic_reg014_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg014_hcic_reg015_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg014_hcic_reg016_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg014_hcic_reg017_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg014_hcic_reg014(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg014_hcic_reg015(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg014_hcic_reg016(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg014_hcic_reg017(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg014_get_hcic_reg014(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg014_get_hcic_reg015(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg014_get_hcic_reg016(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg014_get_hcic_reg017(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg018                                                     0x1802A51C
#define  LG_HCIC_HCIC_reg018_reg_addr                                            "0xB802A51C"
#define  LG_HCIC_HCIC_reg018_reg                                                 0xB802A51C
#define  LG_HCIC_HCIC_reg018_inst_addr                                           "0x0007"
#define  set_LG_HCIC_HCIC_reg018_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg018_reg)=data)
#define  get_LG_HCIC_HCIC_reg018_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg018_reg))
#define  LG_HCIC_HCIC_reg018_hcic_reg018_shift                                   (24)
#define  LG_HCIC_HCIC_reg018_hcic_reg019_shift                                   (16)
#define  LG_HCIC_HCIC_reg018_hcic_reg01a_shift                                   (8)
#define  LG_HCIC_HCIC_reg018_hcic_reg01b_shift                                   (0)
#define  LG_HCIC_HCIC_reg018_hcic_reg018_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg018_hcic_reg019_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg018_hcic_reg01a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg018_hcic_reg01b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg018_hcic_reg018(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg018_hcic_reg019(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg018_hcic_reg01a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg018_hcic_reg01b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg018_get_hcic_reg018(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg018_get_hcic_reg019(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg018_get_hcic_reg01a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg018_get_hcic_reg01b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg01c                                                     0x1802A520
#define  LG_HCIC_HCIC_reg01c_reg_addr                                            "0xB802A520"
#define  LG_HCIC_HCIC_reg01c_reg                                                 0xB802A520
#define  LG_HCIC_HCIC_reg01c_inst_addr                                           "0x0008"
#define  set_LG_HCIC_HCIC_reg01c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg01c_reg)=data)
#define  get_LG_HCIC_HCIC_reg01c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg01c_reg))
#define  LG_HCIC_HCIC_reg01c_hcic_reg01c_shift                                   (24)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01d_shift                                   (16)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01e_shift                                   (8)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01f_shift                                   (0)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg01c_hcic_reg01c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg01c_hcic_reg01d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg01c_hcic_reg01e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg01c_hcic_reg01f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg01c_get_hcic_reg01c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg01c_get_hcic_reg01d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg01c_get_hcic_reg01e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg01c_get_hcic_reg01f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg020                                                     0x1802A524
#define  LG_HCIC_HCIC_reg020_reg_addr                                            "0xB802A524"
#define  LG_HCIC_HCIC_reg020_reg                                                 0xB802A524
#define  LG_HCIC_HCIC_reg020_inst_addr                                           "0x0009"
#define  set_LG_HCIC_HCIC_reg020_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg020_reg)=data)
#define  get_LG_HCIC_HCIC_reg020_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg020_reg))
#define  LG_HCIC_HCIC_reg020_hcic_reg020_shift                                   (24)
#define  LG_HCIC_HCIC_reg020_hcic_reg021_shift                                   (16)
#define  LG_HCIC_HCIC_reg020_hcic_reg022_shift                                   (8)
#define  LG_HCIC_HCIC_reg020_hcic_reg023_shift                                   (0)
#define  LG_HCIC_HCIC_reg020_hcic_reg020_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg020_hcic_reg021_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg020_hcic_reg022_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg020_hcic_reg023_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg020_hcic_reg020(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg020_hcic_reg021(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg020_hcic_reg022(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg020_hcic_reg023(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg020_get_hcic_reg020(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg020_get_hcic_reg021(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg020_get_hcic_reg022(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg020_get_hcic_reg023(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg024                                                     0x1802A528
#define  LG_HCIC_HCIC_reg024_reg_addr                                            "0xB802A528"
#define  LG_HCIC_HCIC_reg024_reg                                                 0xB802A528
#define  LG_HCIC_HCIC_reg024_inst_addr                                           "0x000A"
#define  set_LG_HCIC_HCIC_reg024_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg024_reg)=data)
#define  get_LG_HCIC_HCIC_reg024_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg024_reg))
#define  LG_HCIC_HCIC_reg024_hcic_reg024_shift                                   (24)
#define  LG_HCIC_HCIC_reg024_hcic_reg025_shift                                   (16)
#define  LG_HCIC_HCIC_reg024_hcic_reg026_shift                                   (8)
#define  LG_HCIC_HCIC_reg024_hcic_reg027_shift                                   (0)
#define  LG_HCIC_HCIC_reg024_hcic_reg024_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg024_hcic_reg025_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg024_hcic_reg026_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg024_hcic_reg027_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg024_hcic_reg024(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg024_hcic_reg025(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg024_hcic_reg026(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg024_hcic_reg027(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg024_get_hcic_reg024(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg024_get_hcic_reg025(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg024_get_hcic_reg026(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg024_get_hcic_reg027(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg028                                                     0x1802A52C
#define  LG_HCIC_HCIC_reg028_reg_addr                                            "0xB802A52C"
#define  LG_HCIC_HCIC_reg028_reg                                                 0xB802A52C
#define  LG_HCIC_HCIC_reg028_inst_addr                                           "0x000B"
#define  set_LG_HCIC_HCIC_reg028_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg028_reg)=data)
#define  get_LG_HCIC_HCIC_reg028_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg028_reg))
#define  LG_HCIC_HCIC_reg028_hcic_reg028_shift                                   (24)
#define  LG_HCIC_HCIC_reg028_hcic_reg029_shift                                   (16)
#define  LG_HCIC_HCIC_reg028_hcic_reg02a_shift                                   (8)
#define  LG_HCIC_HCIC_reg028_hcic_reg02b_shift                                   (0)
#define  LG_HCIC_HCIC_reg028_hcic_reg028_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg028_hcic_reg029_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg028_hcic_reg02a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg028_hcic_reg02b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg028_hcic_reg028(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg028_hcic_reg029(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg028_hcic_reg02a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg028_hcic_reg02b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg028_get_hcic_reg028(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg028_get_hcic_reg029(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg028_get_hcic_reg02a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg028_get_hcic_reg02b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg02c                                                     0x1802A530
#define  LG_HCIC_HCIC_reg02c_reg_addr                                            "0xB802A530"
#define  LG_HCIC_HCIC_reg02c_reg                                                 0xB802A530
#define  LG_HCIC_HCIC_reg02c_inst_addr                                           "0x000C"
#define  set_LG_HCIC_HCIC_reg02c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg02c_reg)=data)
#define  get_LG_HCIC_HCIC_reg02c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg02c_reg))
#define  LG_HCIC_HCIC_reg02c_hcic_reg02c_shift                                   (24)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02d_shift                                   (16)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02e_shift                                   (8)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02f_shift                                   (0)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg02c_hcic_reg02c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg02c_hcic_reg02d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg02c_hcic_reg02e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg02c_hcic_reg02f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg02c_get_hcic_reg02c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg02c_get_hcic_reg02d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg02c_get_hcic_reg02e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg02c_get_hcic_reg02f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg030                                                     0x1802A534
#define  LG_HCIC_HCIC_reg030_reg_addr                                            "0xB802A534"
#define  LG_HCIC_HCIC_reg030_reg                                                 0xB802A534
#define  LG_HCIC_HCIC_reg030_inst_addr                                           "0x000D"
#define  set_LG_HCIC_HCIC_reg030_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg030_reg)=data)
#define  get_LG_HCIC_HCIC_reg030_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg030_reg))
#define  LG_HCIC_HCIC_reg030_hcic_reg030_shift                                   (24)
#define  LG_HCIC_HCIC_reg030_hcic_reg031_shift                                   (16)
#define  LG_HCIC_HCIC_reg030_hcic_reg032_shift                                   (8)
#define  LG_HCIC_HCIC_reg030_hcic_reg033_shift                                   (0)
#define  LG_HCIC_HCIC_reg030_hcic_reg030_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg030_hcic_reg031_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg030_hcic_reg032_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg030_hcic_reg033_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg030_hcic_reg030(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg030_hcic_reg031(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg030_hcic_reg032(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg030_hcic_reg033(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg030_get_hcic_reg030(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg030_get_hcic_reg031(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg030_get_hcic_reg032(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg030_get_hcic_reg033(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg034                                                     0x1802A538
#define  LG_HCIC_HCIC_reg034_reg_addr                                            "0xB802A538"
#define  LG_HCIC_HCIC_reg034_reg                                                 0xB802A538
#define  LG_HCIC_HCIC_reg034_inst_addr                                           "0x000E"
#define  set_LG_HCIC_HCIC_reg034_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg034_reg)=data)
#define  get_LG_HCIC_HCIC_reg034_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg034_reg))
#define  LG_HCIC_HCIC_reg034_hcic_reg034_shift                                   (24)
#define  LG_HCIC_HCIC_reg034_hcic_reg035_shift                                   (16)
#define  LG_HCIC_HCIC_reg034_hcic_reg036_shift                                   (8)
#define  LG_HCIC_HCIC_reg034_hcic_reg037_shift                                   (0)
#define  LG_HCIC_HCIC_reg034_hcic_reg034_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg034_hcic_reg035_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg034_hcic_reg036_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg034_hcic_reg037_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg034_hcic_reg034(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg034_hcic_reg035(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg034_hcic_reg036(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg034_hcic_reg037(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg034_get_hcic_reg034(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg034_get_hcic_reg035(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg034_get_hcic_reg036(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg034_get_hcic_reg037(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg038                                                     0x1802A53C
#define  LG_HCIC_HCIC_reg038_reg_addr                                            "0xB802A53C"
#define  LG_HCIC_HCIC_reg038_reg                                                 0xB802A53C
#define  LG_HCIC_HCIC_reg038_inst_addr                                           "0x000F"
#define  set_LG_HCIC_HCIC_reg038_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg038_reg)=data)
#define  get_LG_HCIC_HCIC_reg038_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg038_reg))
#define  LG_HCIC_HCIC_reg038_hcic_reg038_shift                                   (24)
#define  LG_HCIC_HCIC_reg038_hcic_reg039_shift                                   (16)
#define  LG_HCIC_HCIC_reg038_hcic_reg03a_shift                                   (8)
#define  LG_HCIC_HCIC_reg038_hcic_reg03b_shift                                   (0)
#define  LG_HCIC_HCIC_reg038_hcic_reg038_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg038_hcic_reg039_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg038_hcic_reg03a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg038_hcic_reg03b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg038_hcic_reg038(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg038_hcic_reg039(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg038_hcic_reg03a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg038_hcic_reg03b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg038_get_hcic_reg038(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg038_get_hcic_reg039(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg038_get_hcic_reg03a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg038_get_hcic_reg03b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg03c                                                     0x1802A540
#define  LG_HCIC_HCIC_reg03c_reg_addr                                            "0xB802A540"
#define  LG_HCIC_HCIC_reg03c_reg                                                 0xB802A540
#define  LG_HCIC_HCIC_reg03c_inst_addr                                           "0x0010"
#define  set_LG_HCIC_HCIC_reg03c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg03c_reg)=data)
#define  get_LG_HCIC_HCIC_reg03c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg03c_reg))
#define  LG_HCIC_HCIC_reg03c_hcic_reg03c_shift                                   (24)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03d_shift                                   (16)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03e_shift                                   (8)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03f_shift                                   (0)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg03c_hcic_reg03c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg03c_hcic_reg03d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg03c_hcic_reg03e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg03c_hcic_reg03f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg03c_get_hcic_reg03c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg03c_get_hcic_reg03d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg03c_get_hcic_reg03e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg03c_get_hcic_reg03f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg040                                                     0x1802A544
#define  LG_HCIC_HCIC_reg040_reg_addr                                            "0xB802A544"
#define  LG_HCIC_HCIC_reg040_reg                                                 0xB802A544
#define  LG_HCIC_HCIC_reg040_inst_addr                                           "0x0011"
#define  set_LG_HCIC_HCIC_reg040_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg040_reg)=data)
#define  get_LG_HCIC_HCIC_reg040_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg040_reg))
#define  LG_HCIC_HCIC_reg040_hcic_reg040_shift                                   (24)
#define  LG_HCIC_HCIC_reg040_hcic_reg041_shift                                   (16)
#define  LG_HCIC_HCIC_reg040_hcic_reg042_shift                                   (8)
#define  LG_HCIC_HCIC_reg040_hcic_reg043_shift                                   (0)
#define  LG_HCIC_HCIC_reg040_hcic_reg040_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg040_hcic_reg041_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg040_hcic_reg042_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg040_hcic_reg043_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg040_hcic_reg040(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg040_hcic_reg041(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg040_hcic_reg042(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg040_hcic_reg043(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg040_get_hcic_reg040(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg040_get_hcic_reg041(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg040_get_hcic_reg042(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg040_get_hcic_reg043(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg044                                                     0x1802A548
#define  LG_HCIC_HCIC_reg044_reg_addr                                            "0xB802A548"
#define  LG_HCIC_HCIC_reg044_reg                                                 0xB802A548
#define  LG_HCIC_HCIC_reg044_inst_addr                                           "0x0012"
#define  set_LG_HCIC_HCIC_reg044_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg044_reg)=data)
#define  get_LG_HCIC_HCIC_reg044_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg044_reg))
#define  LG_HCIC_HCIC_reg044_hcic_reg044_shift                                   (24)
#define  LG_HCIC_HCIC_reg044_hcic_reg045_shift                                   (16)
#define  LG_HCIC_HCIC_reg044_hcic_reg046_shift                                   (8)
#define  LG_HCIC_HCIC_reg044_hcic_reg047_shift                                   (0)
#define  LG_HCIC_HCIC_reg044_hcic_reg044_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg044_hcic_reg045_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg044_hcic_reg046_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg044_hcic_reg047_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg044_hcic_reg044(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg044_hcic_reg045(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg044_hcic_reg046(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg044_hcic_reg047(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg044_get_hcic_reg044(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg044_get_hcic_reg045(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg044_get_hcic_reg046(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg044_get_hcic_reg047(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg048                                                     0x1802A54C
#define  LG_HCIC_HCIC_reg048_reg_addr                                            "0xB802A54C"
#define  LG_HCIC_HCIC_reg048_reg                                                 0xB802A54C
#define  LG_HCIC_HCIC_reg048_inst_addr                                           "0x0013"
#define  set_LG_HCIC_HCIC_reg048_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg048_reg)=data)
#define  get_LG_HCIC_HCIC_reg048_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg048_reg))
#define  LG_HCIC_HCIC_reg048_hcic_reg048_shift                                   (24)
#define  LG_HCIC_HCIC_reg048_hcic_reg049_shift                                   (16)
#define  LG_HCIC_HCIC_reg048_hcic_reg04a_shift                                   (8)
#define  LG_HCIC_HCIC_reg048_hcic_reg04b_shift                                   (0)
#define  LG_HCIC_HCIC_reg048_hcic_reg048_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg048_hcic_reg049_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg048_hcic_reg04a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg048_hcic_reg04b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg048_hcic_reg048(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg048_hcic_reg049(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg048_hcic_reg04a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg048_hcic_reg04b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg048_get_hcic_reg048(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg048_get_hcic_reg049(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg048_get_hcic_reg04a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg048_get_hcic_reg04b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg04c                                                     0x1802A550
#define  LG_HCIC_HCIC_reg04c_reg_addr                                            "0xB802A550"
#define  LG_HCIC_HCIC_reg04c_reg                                                 0xB802A550
#define  LG_HCIC_HCIC_reg04c_inst_addr                                           "0x0014"
#define  set_LG_HCIC_HCIC_reg04c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg04c_reg)=data)
#define  get_LG_HCIC_HCIC_reg04c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg04c_reg))
#define  LG_HCIC_HCIC_reg04c_hcic_reg04c_shift                                   (24)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04d_shift                                   (16)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04e_shift                                   (8)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04f_shift                                   (0)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg04c_hcic_reg04c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg04c_hcic_reg04d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg04c_hcic_reg04e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg04c_hcic_reg04f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg04c_get_hcic_reg04c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg04c_get_hcic_reg04d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg04c_get_hcic_reg04e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg04c_get_hcic_reg04f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg050                                                     0x1802A554
#define  LG_HCIC_HCIC_reg050_reg_addr                                            "0xB802A554"
#define  LG_HCIC_HCIC_reg050_reg                                                 0xB802A554
#define  LG_HCIC_HCIC_reg050_inst_addr                                           "0x0015"
#define  set_LG_HCIC_HCIC_reg050_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg050_reg)=data)
#define  get_LG_HCIC_HCIC_reg050_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg050_reg))
#define  LG_HCIC_HCIC_reg050_hcic_reg050_shift                                   (24)
#define  LG_HCIC_HCIC_reg050_hcic_reg051_shift                                   (16)
#define  LG_HCIC_HCIC_reg050_hcic_reg052_shift                                   (8)
#define  LG_HCIC_HCIC_reg050_hcic_reg053_shift                                   (0)
#define  LG_HCIC_HCIC_reg050_hcic_reg050_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg050_hcic_reg051_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg050_hcic_reg052_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg050_hcic_reg053_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg050_hcic_reg050(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg050_hcic_reg051(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg050_hcic_reg052(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg050_hcic_reg053(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg050_get_hcic_reg050(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg050_get_hcic_reg051(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg050_get_hcic_reg052(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg050_get_hcic_reg053(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg054                                                     0x1802A558
#define  LG_HCIC_HCIC_reg054_reg_addr                                            "0xB802A558"
#define  LG_HCIC_HCIC_reg054_reg                                                 0xB802A558
#define  LG_HCIC_HCIC_reg054_inst_addr                                           "0x0016"
#define  set_LG_HCIC_HCIC_reg054_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg054_reg)=data)
#define  get_LG_HCIC_HCIC_reg054_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg054_reg))
#define  LG_HCIC_HCIC_reg054_hcic_reg054_shift                                   (24)
#define  LG_HCIC_HCIC_reg054_hcic_reg055_shift                                   (16)
#define  LG_HCIC_HCIC_reg054_hcic_reg056_shift                                   (8)
#define  LG_HCIC_HCIC_reg054_hcic_reg057_shift                                   (0)
#define  LG_HCIC_HCIC_reg054_hcic_reg054_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg054_hcic_reg055_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg054_hcic_reg056_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg054_hcic_reg057_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg054_hcic_reg054(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg054_hcic_reg055(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg054_hcic_reg056(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg054_hcic_reg057(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg054_get_hcic_reg054(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg054_get_hcic_reg055(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg054_get_hcic_reg056(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg054_get_hcic_reg057(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg058                                                     0x1802A55C
#define  LG_HCIC_HCIC_reg058_reg_addr                                            "0xB802A55C"
#define  LG_HCIC_HCIC_reg058_reg                                                 0xB802A55C
#define  LG_HCIC_HCIC_reg058_inst_addr                                           "0x0017"
#define  set_LG_HCIC_HCIC_reg058_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg058_reg)=data)
#define  get_LG_HCIC_HCIC_reg058_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg058_reg))
#define  LG_HCIC_HCIC_reg058_hcic_reg058_shift                                   (24)
#define  LG_HCIC_HCIC_reg058_hcic_reg059_shift                                   (16)
#define  LG_HCIC_HCIC_reg058_hcic_reg05a_shift                                   (8)
#define  LG_HCIC_HCIC_reg058_hcic_reg05b_shift                                   (0)
#define  LG_HCIC_HCIC_reg058_hcic_reg058_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg058_hcic_reg059_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg058_hcic_reg05a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg058_hcic_reg05b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg058_hcic_reg058(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg058_hcic_reg059(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg058_hcic_reg05a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg058_hcic_reg05b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg058_get_hcic_reg058(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg058_get_hcic_reg059(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg058_get_hcic_reg05a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg058_get_hcic_reg05b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg05c                                                     0x1802A560
#define  LG_HCIC_HCIC_reg05c_reg_addr                                            "0xB802A560"
#define  LG_HCIC_HCIC_reg05c_reg                                                 0xB802A560
#define  LG_HCIC_HCIC_reg05c_inst_addr                                           "0x0018"
#define  set_LG_HCIC_HCIC_reg05c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg05c_reg)=data)
#define  get_LG_HCIC_HCIC_reg05c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg05c_reg))
#define  LG_HCIC_HCIC_reg05c_hcic_reg05c_shift                                   (24)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05d_shift                                   (16)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05e_shift                                   (8)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05f_shift                                   (0)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg05c_hcic_reg05c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg05c_hcic_reg05d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg05c_hcic_reg05e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg05c_hcic_reg05f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg05c_get_hcic_reg05c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg05c_get_hcic_reg05d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg05c_get_hcic_reg05e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg05c_get_hcic_reg05f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg060                                                     0x1802A564
#define  LG_HCIC_HCIC_reg060_reg_addr                                            "0xB802A564"
#define  LG_HCIC_HCIC_reg060_reg                                                 0xB802A564
#define  LG_HCIC_HCIC_reg060_inst_addr                                           "0x0019"
#define  set_LG_HCIC_HCIC_reg060_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg060_reg)=data)
#define  get_LG_HCIC_HCIC_reg060_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg060_reg))
#define  LG_HCIC_HCIC_reg060_hcic_reg060_shift                                   (24)
#define  LG_HCIC_HCIC_reg060_hcic_reg061_shift                                   (16)
#define  LG_HCIC_HCIC_reg060_hcic_reg062_shift                                   (8)
#define  LG_HCIC_HCIC_reg060_hcic_reg063_shift                                   (0)
#define  LG_HCIC_HCIC_reg060_hcic_reg060_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg060_hcic_reg061_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg060_hcic_reg062_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg060_hcic_reg063_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg060_hcic_reg060(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg060_hcic_reg061(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg060_hcic_reg062(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg060_hcic_reg063(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg060_get_hcic_reg060(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg060_get_hcic_reg061(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg060_get_hcic_reg062(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg060_get_hcic_reg063(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg064                                                     0x1802A568
#define  LG_HCIC_HCIC_reg064_reg_addr                                            "0xB802A568"
#define  LG_HCIC_HCIC_reg064_reg                                                 0xB802A568
#define  LG_HCIC_HCIC_reg064_inst_addr                                           "0x001A"
#define  set_LG_HCIC_HCIC_reg064_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg064_reg)=data)
#define  get_LG_HCIC_HCIC_reg064_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg064_reg))
#define  LG_HCIC_HCIC_reg064_hcic_reg064_shift                                   (24)
#define  LG_HCIC_HCIC_reg064_hcic_reg065_shift                                   (16)
#define  LG_HCIC_HCIC_reg064_hcic_reg066_shift                                   (8)
#define  LG_HCIC_HCIC_reg064_hcic_reg067_shift                                   (0)
#define  LG_HCIC_HCIC_reg064_hcic_reg064_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg064_hcic_reg065_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg064_hcic_reg066_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg064_hcic_reg067_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg064_hcic_reg064(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg064_hcic_reg065(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg064_hcic_reg066(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg064_hcic_reg067(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg064_get_hcic_reg064(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg064_get_hcic_reg065(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg064_get_hcic_reg066(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg064_get_hcic_reg067(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg068                                                     0x1802A56C
#define  LG_HCIC_HCIC_reg068_reg_addr                                            "0xB802A56C"
#define  LG_HCIC_HCIC_reg068_reg                                                 0xB802A56C
#define  LG_HCIC_HCIC_reg068_inst_addr                                           "0x001B"
#define  set_LG_HCIC_HCIC_reg068_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg068_reg)=data)
#define  get_LG_HCIC_HCIC_reg068_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg068_reg))
#define  LG_HCIC_HCIC_reg068_hcic_reg068_shift                                   (24)
#define  LG_HCIC_HCIC_reg068_hcic_reg069_shift                                   (16)
#define  LG_HCIC_HCIC_reg068_hcic_reg06a_shift                                   (8)
#define  LG_HCIC_HCIC_reg068_hcic_reg06b_shift                                   (0)
#define  LG_HCIC_HCIC_reg068_hcic_reg068_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg068_hcic_reg069_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg068_hcic_reg06a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg068_hcic_reg06b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg068_hcic_reg068(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg068_hcic_reg069(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg068_hcic_reg06a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg068_hcic_reg06b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg068_get_hcic_reg068(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg068_get_hcic_reg069(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg068_get_hcic_reg06a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg068_get_hcic_reg06b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg06c                                                     0x1802A570
#define  LG_HCIC_HCIC_reg06c_reg_addr                                            "0xB802A570"
#define  LG_HCIC_HCIC_reg06c_reg                                                 0xB802A570
#define  LG_HCIC_HCIC_reg06c_inst_addr                                           "0x001C"
#define  set_LG_HCIC_HCIC_reg06c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg06c_reg)=data)
#define  get_LG_HCIC_HCIC_reg06c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg06c_reg))
#define  LG_HCIC_HCIC_reg06c_hcic_reg06c_shift                                   (24)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06d_shift                                   (16)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06e_shift                                   (8)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06f_shift                                   (0)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg06c_hcic_reg06c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg06c_hcic_reg06d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg06c_hcic_reg06e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg06c_hcic_reg06f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg06c_get_hcic_reg06c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg06c_get_hcic_reg06d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg06c_get_hcic_reg06e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg06c_get_hcic_reg06f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg070                                                     0x1802A574
#define  LG_HCIC_HCIC_reg070_reg_addr                                            "0xB802A574"
#define  LG_HCIC_HCIC_reg070_reg                                                 0xB802A574
#define  LG_HCIC_HCIC_reg070_inst_addr                                           "0x001D"
#define  set_LG_HCIC_HCIC_reg070_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg070_reg)=data)
#define  get_LG_HCIC_HCIC_reg070_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg070_reg))
#define  LG_HCIC_HCIC_reg070_hcic_reg070_shift                                   (24)
#define  LG_HCIC_HCIC_reg070_hcic_reg071_shift                                   (16)
#define  LG_HCIC_HCIC_reg070_hcic_reg072_shift                                   (8)
#define  LG_HCIC_HCIC_reg070_hcic_reg073_shift                                   (0)
#define  LG_HCIC_HCIC_reg070_hcic_reg070_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg070_hcic_reg071_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg070_hcic_reg072_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg070_hcic_reg073_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg070_hcic_reg070(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg070_hcic_reg071(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg070_hcic_reg072(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg070_hcic_reg073(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg070_get_hcic_reg070(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg070_get_hcic_reg071(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg070_get_hcic_reg072(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg070_get_hcic_reg073(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg074                                                     0x1802A578
#define  LG_HCIC_HCIC_reg074_reg_addr                                            "0xB802A578"
#define  LG_HCIC_HCIC_reg074_reg                                                 0xB802A578
#define  LG_HCIC_HCIC_reg074_inst_addr                                           "0x001E"
#define  set_LG_HCIC_HCIC_reg074_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg074_reg)=data)
#define  get_LG_HCIC_HCIC_reg074_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg074_reg))
#define  LG_HCIC_HCIC_reg074_hcic_reg074_shift                                   (24)
#define  LG_HCIC_HCIC_reg074_hcic_reg075_shift                                   (16)
#define  LG_HCIC_HCIC_reg074_hcic_reg076_shift                                   (8)
#define  LG_HCIC_HCIC_reg074_hcic_reg077_shift                                   (0)
#define  LG_HCIC_HCIC_reg074_hcic_reg074_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg074_hcic_reg075_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg074_hcic_reg076_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg074_hcic_reg077_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg074_hcic_reg074(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg074_hcic_reg075(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg074_hcic_reg076(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg074_hcic_reg077(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg074_get_hcic_reg074(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg074_get_hcic_reg075(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg074_get_hcic_reg076(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg074_get_hcic_reg077(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg078                                                     0x1802A57C
#define  LG_HCIC_HCIC_reg078_reg_addr                                            "0xB802A57C"
#define  LG_HCIC_HCIC_reg078_reg                                                 0xB802A57C
#define  LG_HCIC_HCIC_reg078_inst_addr                                           "0x001F"
#define  set_LG_HCIC_HCIC_reg078_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg078_reg)=data)
#define  get_LG_HCIC_HCIC_reg078_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg078_reg))
#define  LG_HCIC_HCIC_reg078_hcic_reg078_shift                                   (24)
#define  LG_HCIC_HCIC_reg078_hcic_reg079_shift                                   (16)
#define  LG_HCIC_HCIC_reg078_hcic_reg07a_shift                                   (8)
#define  LG_HCIC_HCIC_reg078_hcic_reg07b_shift                                   (0)
#define  LG_HCIC_HCIC_reg078_hcic_reg078_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg078_hcic_reg079_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg078_hcic_reg07a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg078_hcic_reg07b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg078_hcic_reg078(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg078_hcic_reg079(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg078_hcic_reg07a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg078_hcic_reg07b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg078_get_hcic_reg078(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg078_get_hcic_reg079(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg078_get_hcic_reg07a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg078_get_hcic_reg07b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg07c                                                     0x1802A580
#define  LG_HCIC_HCIC_reg07c_reg_addr                                            "0xB802A580"
#define  LG_HCIC_HCIC_reg07c_reg                                                 0xB802A580
#define  LG_HCIC_HCIC_reg07c_inst_addr                                           "0x0020"
#define  set_LG_HCIC_HCIC_reg07c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg07c_reg)=data)
#define  get_LG_HCIC_HCIC_reg07c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg07c_reg))
#define  LG_HCIC_HCIC_reg07c_hcic_reg07c_shift                                   (24)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07d_shift                                   (16)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07e_shift                                   (8)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07f_shift                                   (0)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg07c_hcic_reg07c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg07c_hcic_reg07d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg07c_hcic_reg07e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg07c_hcic_reg07f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg07c_get_hcic_reg07c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg07c_get_hcic_reg07d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg07c_get_hcic_reg07e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg07c_get_hcic_reg07f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg080                                                     0x1802A584
#define  LG_HCIC_HCIC_reg080_reg_addr                                            "0xB802A584"
#define  LG_HCIC_HCIC_reg080_reg                                                 0xB802A584
#define  LG_HCIC_HCIC_reg080_inst_addr                                           "0x0021"
#define  set_LG_HCIC_HCIC_reg080_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg080_reg)=data)
#define  get_LG_HCIC_HCIC_reg080_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg080_reg))
#define  LG_HCIC_HCIC_reg080_hcic_reg080_shift                                   (24)
#define  LG_HCIC_HCIC_reg080_hcic_reg081_shift                                   (16)
#define  LG_HCIC_HCIC_reg080_hcic_reg082_shift                                   (8)
#define  LG_HCIC_HCIC_reg080_hcic_reg083_shift                                   (0)
#define  LG_HCIC_HCIC_reg080_hcic_reg080_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg080_hcic_reg081_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg080_hcic_reg082_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg080_hcic_reg083_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg080_hcic_reg080(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg080_hcic_reg081(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg080_hcic_reg082(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg080_hcic_reg083(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg080_get_hcic_reg080(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg080_get_hcic_reg081(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg080_get_hcic_reg082(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg080_get_hcic_reg083(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg084                                                     0x1802A588
#define  LG_HCIC_HCIC_reg084_reg_addr                                            "0xB802A588"
#define  LG_HCIC_HCIC_reg084_reg                                                 0xB802A588
#define  LG_HCIC_HCIC_reg084_inst_addr                                           "0x0022"
#define  set_LG_HCIC_HCIC_reg084_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg084_reg)=data)
#define  get_LG_HCIC_HCIC_reg084_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg084_reg))
#define  LG_HCIC_HCIC_reg084_hcic_reg084_shift                                   (24)
#define  LG_HCIC_HCIC_reg084_hcic_reg085_shift                                   (16)
#define  LG_HCIC_HCIC_reg084_hcic_reg086_shift                                   (8)
#define  LG_HCIC_HCIC_reg084_hcic_reg087_shift                                   (0)
#define  LG_HCIC_HCIC_reg084_hcic_reg084_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg084_hcic_reg085_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg084_hcic_reg086_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg084_hcic_reg087_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg084_hcic_reg084(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg084_hcic_reg085(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg084_hcic_reg086(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg084_hcic_reg087(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg084_get_hcic_reg084(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg084_get_hcic_reg085(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg084_get_hcic_reg086(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg084_get_hcic_reg087(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg088                                                     0x1802A58C
#define  LG_HCIC_HCIC_reg088_reg_addr                                            "0xB802A58C"
#define  LG_HCIC_HCIC_reg088_reg                                                 0xB802A58C
#define  LG_HCIC_HCIC_reg088_inst_addr                                           "0x0023"
#define  set_LG_HCIC_HCIC_reg088_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg088_reg)=data)
#define  get_LG_HCIC_HCIC_reg088_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg088_reg))
#define  LG_HCIC_HCIC_reg088_hcic_reg088_shift                                   (24)
#define  LG_HCIC_HCIC_reg088_hcic_reg089_shift                                   (16)
#define  LG_HCIC_HCIC_reg088_hcic_reg08a_shift                                   (8)
#define  LG_HCIC_HCIC_reg088_hcic_reg08b_shift                                   (0)
#define  LG_HCIC_HCIC_reg088_hcic_reg088_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg088_hcic_reg089_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg088_hcic_reg08a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg088_hcic_reg08b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg088_hcic_reg088(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg088_hcic_reg089(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg088_hcic_reg08a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg088_hcic_reg08b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg088_get_hcic_reg088(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg088_get_hcic_reg089(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg088_get_hcic_reg08a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg088_get_hcic_reg08b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg08c                                                     0x1802A590
#define  LG_HCIC_HCIC_reg08c_reg_addr                                            "0xB802A590"
#define  LG_HCIC_HCIC_reg08c_reg                                                 0xB802A590
#define  LG_HCIC_HCIC_reg08c_inst_addr                                           "0x0024"
#define  set_LG_HCIC_HCIC_reg08c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg08c_reg)=data)
#define  get_LG_HCIC_HCIC_reg08c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg08c_reg))
#define  LG_HCIC_HCIC_reg08c_hcic_reg08c_shift                                   (24)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08d_shift                                   (16)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08e_shift                                   (8)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08f_shift                                   (0)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg08c_hcic_reg08c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg08c_hcic_reg08d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg08c_hcic_reg08e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg08c_hcic_reg08f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg08c_get_hcic_reg08c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg08c_get_hcic_reg08d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg08c_get_hcic_reg08e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg08c_get_hcic_reg08f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg090                                                     0x1802A594
#define  LG_HCIC_HCIC_reg090_reg_addr                                            "0xB802A594"
#define  LG_HCIC_HCIC_reg090_reg                                                 0xB802A594
#define  LG_HCIC_HCIC_reg090_inst_addr                                           "0x0025"
#define  set_LG_HCIC_HCIC_reg090_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg090_reg)=data)
#define  get_LG_HCIC_HCIC_reg090_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg090_reg))
#define  LG_HCIC_HCIC_reg090_hcic_reg090_shift                                   (24)
#define  LG_HCIC_HCIC_reg090_hcic_reg091_shift                                   (16)
#define  LG_HCIC_HCIC_reg090_hcic_reg092_shift                                   (8)
#define  LG_HCIC_HCIC_reg090_hcic_reg093_shift                                   (0)
#define  LG_HCIC_HCIC_reg090_hcic_reg090_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg090_hcic_reg091_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg090_hcic_reg092_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg090_hcic_reg093_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg090_hcic_reg090(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg090_hcic_reg091(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg090_hcic_reg092(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg090_hcic_reg093(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg090_get_hcic_reg090(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg090_get_hcic_reg091(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg090_get_hcic_reg092(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg090_get_hcic_reg093(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg094                                                     0x1802A598
#define  LG_HCIC_HCIC_reg094_reg_addr                                            "0xB802A598"
#define  LG_HCIC_HCIC_reg094_reg                                                 0xB802A598
#define  LG_HCIC_HCIC_reg094_inst_addr                                           "0x0026"
#define  set_LG_HCIC_HCIC_reg094_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg094_reg)=data)
#define  get_LG_HCIC_HCIC_reg094_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg094_reg))
#define  LG_HCIC_HCIC_reg094_hcic_reg094_shift                                   (24)
#define  LG_HCIC_HCIC_reg094_hcic_reg095_shift                                   (16)
#define  LG_HCIC_HCIC_reg094_hcic_reg096_shift                                   (8)
#define  LG_HCIC_HCIC_reg094_hcic_reg097_shift                                   (0)
#define  LG_HCIC_HCIC_reg094_hcic_reg094_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg094_hcic_reg095_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg094_hcic_reg096_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg094_hcic_reg097_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg094_hcic_reg094(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg094_hcic_reg095(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg094_hcic_reg096(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg094_hcic_reg097(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg094_get_hcic_reg094(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg094_get_hcic_reg095(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg094_get_hcic_reg096(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg094_get_hcic_reg097(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg098                                                     0x1802A59C
#define  LG_HCIC_HCIC_reg098_reg_addr                                            "0xB802A59C"
#define  LG_HCIC_HCIC_reg098_reg                                                 0xB802A59C
#define  LG_HCIC_HCIC_reg098_inst_addr                                           "0x0027"
#define  set_LG_HCIC_HCIC_reg098_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg098_reg)=data)
#define  get_LG_HCIC_HCIC_reg098_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg098_reg))
#define  LG_HCIC_HCIC_reg098_hcic_reg098_shift                                   (24)
#define  LG_HCIC_HCIC_reg098_hcic_reg099_shift                                   (16)
#define  LG_HCIC_HCIC_reg098_hcic_reg09a_shift                                   (8)
#define  LG_HCIC_HCIC_reg098_hcic_reg09b_shift                                   (0)
#define  LG_HCIC_HCIC_reg098_hcic_reg098_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg098_hcic_reg099_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg098_hcic_reg09a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg098_hcic_reg09b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg098_hcic_reg098(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg098_hcic_reg099(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg098_hcic_reg09a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg098_hcic_reg09b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg098_get_hcic_reg098(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg098_get_hcic_reg099(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg098_get_hcic_reg09a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg098_get_hcic_reg09b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg09c                                                     0x1802A5A0
#define  LG_HCIC_HCIC_reg09c_reg_addr                                            "0xB802A5A0"
#define  LG_HCIC_HCIC_reg09c_reg                                                 0xB802A5A0
#define  LG_HCIC_HCIC_reg09c_inst_addr                                           "0x0028"
#define  set_LG_HCIC_HCIC_reg09c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg09c_reg)=data)
#define  get_LG_HCIC_HCIC_reg09c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg09c_reg))
#define  LG_HCIC_HCIC_reg09c_hcic_reg09c_shift                                   (24)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09d_shift                                   (16)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09e_shift                                   (8)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09f_shift                                   (0)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg09c_hcic_reg09c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg09c_hcic_reg09d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg09c_hcic_reg09e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg09c_hcic_reg09f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg09c_get_hcic_reg09c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg09c_get_hcic_reg09d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg09c_get_hcic_reg09e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg09c_get_hcic_reg09f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0a0                                                     0x1802A5A4
#define  LG_HCIC_HCIC_reg0a0_reg_addr                                            "0xB802A5A4"
#define  LG_HCIC_HCIC_reg0a0_reg                                                 0xB802A5A4
#define  LG_HCIC_HCIC_reg0a0_inst_addr                                           "0x0029"
#define  set_LG_HCIC_HCIC_reg0a0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0a0_reg)=data)
#define  get_LG_HCIC_HCIC_reg0a0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0a0_reg))
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a0_shift                                   (24)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a1_shift                                   (16)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a2_shift                                   (8)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a3_shift                                   (0)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0a0_hcic_reg0a3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0a0_get_hcic_reg0a0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0a0_get_hcic_reg0a1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0a0_get_hcic_reg0a2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0a0_get_hcic_reg0a3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0a4                                                     0x1802A5A8
#define  LG_HCIC_HCIC_reg0a4_reg_addr                                            "0xB802A5A8"
#define  LG_HCIC_HCIC_reg0a4_reg                                                 0xB802A5A8
#define  LG_HCIC_HCIC_reg0a4_inst_addr                                           "0x002A"
#define  set_LG_HCIC_HCIC_reg0a4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0a4_reg)=data)
#define  get_LG_HCIC_HCIC_reg0a4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0a4_reg))
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a4_shift                                   (24)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a5_shift                                   (16)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a6_shift                                   (8)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a7_shift                                   (0)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0a4_hcic_reg0a7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0a4_get_hcic_reg0a4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0a4_get_hcic_reg0a5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0a4_get_hcic_reg0a6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0a4_get_hcic_reg0a7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0a8                                                     0x1802A5AC
#define  LG_HCIC_HCIC_reg0a8_reg_addr                                            "0xB802A5AC"
#define  LG_HCIC_HCIC_reg0a8_reg                                                 0xB802A5AC
#define  LG_HCIC_HCIC_reg0a8_inst_addr                                           "0x002B"
#define  set_LG_HCIC_HCIC_reg0a8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0a8_reg)=data)
#define  get_LG_HCIC_HCIC_reg0a8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0a8_reg))
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0a8_shift                                   (24)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0a9_shift                                   (16)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0aa_shift                                   (8)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0ab_shift                                   (0)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0a8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0a9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0aa_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0ab_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0a8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0a9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0aa(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0a8_hcic_reg0ab(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0a8_get_hcic_reg0a8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0a8_get_hcic_reg0a9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0a8_get_hcic_reg0aa(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0a8_get_hcic_reg0ab(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0ac                                                     0x1802A5B0
#define  LG_HCIC_HCIC_reg0ac_reg_addr                                            "0xB802A5B0"
#define  LG_HCIC_HCIC_reg0ac_reg                                                 0xB802A5B0
#define  LG_HCIC_HCIC_reg0ac_inst_addr                                           "0x002C"
#define  set_LG_HCIC_HCIC_reg0ac_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0ac_reg)=data)
#define  get_LG_HCIC_HCIC_reg0ac_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0ac_reg))
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ac_shift                                   (24)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ad_shift                                   (16)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ae_shift                                   (8)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0af_shift                                   (0)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ac_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ad_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ae_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0af_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ac(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ad(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0ae(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0ac_hcic_reg0af(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0ac_get_hcic_reg0ac(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0ac_get_hcic_reg0ad(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0ac_get_hcic_reg0ae(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0ac_get_hcic_reg0af(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0b0                                                     0x1802A5B4
#define  LG_HCIC_HCIC_reg0b0_reg_addr                                            "0xB802A5B4"
#define  LG_HCIC_HCIC_reg0b0_reg                                                 0xB802A5B4
#define  LG_HCIC_HCIC_reg0b0_inst_addr                                           "0x002D"
#define  set_LG_HCIC_HCIC_reg0b0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0b0_reg)=data)
#define  get_LG_HCIC_HCIC_reg0b0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0b0_reg))
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b0_shift                                   (24)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b1_shift                                   (16)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b2_shift                                   (8)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b3_shift                                   (0)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0b0_hcic_reg0b3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0b0_get_hcic_reg0b0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0b0_get_hcic_reg0b1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0b0_get_hcic_reg0b2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0b0_get_hcic_reg0b3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0b4                                                     0x1802A5B8
#define  LG_HCIC_HCIC_reg0b4_reg_addr                                            "0xB802A5B8"
#define  LG_HCIC_HCIC_reg0b4_reg                                                 0xB802A5B8
#define  LG_HCIC_HCIC_reg0b4_inst_addr                                           "0x002E"
#define  set_LG_HCIC_HCIC_reg0b4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0b4_reg)=data)
#define  get_LG_HCIC_HCIC_reg0b4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0b4_reg))
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b4_shift                                   (24)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b5_shift                                   (16)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b6_shift                                   (8)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b7_shift                                   (0)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0b4_hcic_reg0b7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0b4_get_hcic_reg0b4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0b4_get_hcic_reg0b5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0b4_get_hcic_reg0b6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0b4_get_hcic_reg0b7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0b8                                                     0x1802A5BC
#define  LG_HCIC_HCIC_reg0b8_reg_addr                                            "0xB802A5BC"
#define  LG_HCIC_HCIC_reg0b8_reg                                                 0xB802A5BC
#define  LG_HCIC_HCIC_reg0b8_inst_addr                                           "0x002F"
#define  set_LG_HCIC_HCIC_reg0b8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0b8_reg)=data)
#define  get_LG_HCIC_HCIC_reg0b8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0b8_reg))
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0b8_shift                                   (24)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0b9_shift                                   (16)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0ba_shift                                   (8)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0bb_shift                                   (0)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0b8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0b9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0ba_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0bb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0b8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0b9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0ba(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0b8_hcic_reg0bb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0b8_get_hcic_reg0b8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0b8_get_hcic_reg0b9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0b8_get_hcic_reg0ba(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0b8_get_hcic_reg0bb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0bc                                                     0x1802A5C0
#define  LG_HCIC_HCIC_reg0bc_reg_addr                                            "0xB802A5C0"
#define  LG_HCIC_HCIC_reg0bc_reg                                                 0xB802A5C0
#define  LG_HCIC_HCIC_reg0bc_inst_addr                                           "0x0030"
#define  set_LG_HCIC_HCIC_reg0bc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0bc_reg)=data)
#define  get_LG_HCIC_HCIC_reg0bc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0bc_reg))
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bc_shift                                   (24)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bd_shift                                   (16)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0be_shift                                   (8)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bf_shift                                   (0)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0be_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bf_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0be(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0bc_hcic_reg0bf(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0bc_get_hcic_reg0bc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0bc_get_hcic_reg0bd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0bc_get_hcic_reg0be(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0bc_get_hcic_reg0bf(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0c0                                                     0x1802A5C4
#define  LG_HCIC_HCIC_reg0c0_reg_addr                                            "0xB802A5C4"
#define  LG_HCIC_HCIC_reg0c0_reg                                                 0xB802A5C4
#define  LG_HCIC_HCIC_reg0c0_inst_addr                                           "0x0031"
#define  set_LG_HCIC_HCIC_reg0c0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0c0_reg)=data)
#define  get_LG_HCIC_HCIC_reg0c0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0c0_reg))
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c0_shift                                   (24)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c1_shift                                   (16)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c2_shift                                   (8)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c3_shift                                   (0)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0c0_hcic_reg0c3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0c0_get_hcic_reg0c0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0c0_get_hcic_reg0c1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0c0_get_hcic_reg0c2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0c0_get_hcic_reg0c3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0c4                                                     0x1802A5C8
#define  LG_HCIC_HCIC_reg0c4_reg_addr                                            "0xB802A5C8"
#define  LG_HCIC_HCIC_reg0c4_reg                                                 0xB802A5C8
#define  LG_HCIC_HCIC_reg0c4_inst_addr                                           "0x0032"
#define  set_LG_HCIC_HCIC_reg0c4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0c4_reg)=data)
#define  get_LG_HCIC_HCIC_reg0c4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0c4_reg))
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c4_shift                                   (24)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c5_shift                                   (16)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c6_shift                                   (8)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c7_shift                                   (0)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0c4_hcic_reg0c7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0c4_get_hcic_reg0c4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0c4_get_hcic_reg0c5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0c4_get_hcic_reg0c6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0c4_get_hcic_reg0c7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0c8                                                     0x1802A5CC
#define  LG_HCIC_HCIC_reg0c8_reg_addr                                            "0xB802A5CC"
#define  LG_HCIC_HCIC_reg0c8_reg                                                 0xB802A5CC
#define  LG_HCIC_HCIC_reg0c8_inst_addr                                           "0x0033"
#define  set_LG_HCIC_HCIC_reg0c8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0c8_reg)=data)
#define  get_LG_HCIC_HCIC_reg0c8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0c8_reg))
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0c8_shift                                   (24)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0c9_shift                                   (16)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0ca_shift                                   (8)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0cb_shift                                   (0)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0c8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0c9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0ca_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0cb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0c8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0c9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0ca(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0c8_hcic_reg0cb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0c8_get_hcic_reg0c8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0c8_get_hcic_reg0c9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0c8_get_hcic_reg0ca(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0c8_get_hcic_reg0cb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0cc                                                     0x1802A5D0
#define  LG_HCIC_HCIC_reg0cc_reg_addr                                            "0xB802A5D0"
#define  LG_HCIC_HCIC_reg0cc_reg                                                 0xB802A5D0
#define  LG_HCIC_HCIC_reg0cc_inst_addr                                           "0x0034"
#define  set_LG_HCIC_HCIC_reg0cc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0cc_reg)=data)
#define  get_LG_HCIC_HCIC_reg0cc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0cc_reg))
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cc_shift                                   (24)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cd_shift                                   (16)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0ce_shift                                   (8)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cf_shift                                   (0)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0ce_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cf_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0ce(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0cc_hcic_reg0cf(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0cc_get_hcic_reg0cc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0cc_get_hcic_reg0cd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0cc_get_hcic_reg0ce(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0cc_get_hcic_reg0cf(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0d0                                                     0x1802A5D4
#define  LG_HCIC_HCIC_reg0d0_reg_addr                                            "0xB802A5D4"
#define  LG_HCIC_HCIC_reg0d0_reg                                                 0xB802A5D4
#define  LG_HCIC_HCIC_reg0d0_inst_addr                                           "0x0035"
#define  set_LG_HCIC_HCIC_reg0d0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0d0_reg)=data)
#define  get_LG_HCIC_HCIC_reg0d0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0d0_reg))
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d0_shift                                   (24)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d1_shift                                   (16)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d2_shift                                   (8)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d3_shift                                   (0)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0d0_hcic_reg0d3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0d0_get_hcic_reg0d0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0d0_get_hcic_reg0d1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0d0_get_hcic_reg0d2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0d0_get_hcic_reg0d3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0d4                                                     0x1802A5D8
#define  LG_HCIC_HCIC_reg0d4_reg_addr                                            "0xB802A5D8"
#define  LG_HCIC_HCIC_reg0d4_reg                                                 0xB802A5D8
#define  LG_HCIC_HCIC_reg0d4_inst_addr                                           "0x0036"
#define  set_LG_HCIC_HCIC_reg0d4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0d4_reg)=data)
#define  get_LG_HCIC_HCIC_reg0d4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0d4_reg))
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d4_shift                                   (24)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d5_shift                                   (16)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d6_shift                                   (8)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d7_shift                                   (0)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0d4_hcic_reg0d7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0d4_get_hcic_reg0d4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0d4_get_hcic_reg0d5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0d4_get_hcic_reg0d6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0d4_get_hcic_reg0d7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0d8                                                     0x1802A5DC
#define  LG_HCIC_HCIC_reg0d8_reg_addr                                            "0xB802A5DC"
#define  LG_HCIC_HCIC_reg0d8_reg                                                 0xB802A5DC
#define  LG_HCIC_HCIC_reg0d8_inst_addr                                           "0x0037"
#define  set_LG_HCIC_HCIC_reg0d8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0d8_reg)=data)
#define  get_LG_HCIC_HCIC_reg0d8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0d8_reg))
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0d8_shift                                   (24)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0d9_shift                                   (16)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0da_shift                                   (8)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0db_shift                                   (0)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0d8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0d9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0da_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0db_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0d8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0d9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0da(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0d8_hcic_reg0db(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0d8_get_hcic_reg0d8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0d8_get_hcic_reg0d9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0d8_get_hcic_reg0da(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0d8_get_hcic_reg0db(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0dc                                                     0x1802A5E0
#define  LG_HCIC_HCIC_reg0dc_reg_addr                                            "0xB802A5E0"
#define  LG_HCIC_HCIC_reg0dc_reg                                                 0xB802A5E0
#define  LG_HCIC_HCIC_reg0dc_inst_addr                                           "0x0038"
#define  set_LG_HCIC_HCIC_reg0dc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0dc_reg)=data)
#define  get_LG_HCIC_HCIC_reg0dc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0dc_reg))
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0dc_shift                                   (24)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0dd_shift                                   (16)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0de_shift                                   (8)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0df_shift                                   (0)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0dc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0dd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0de_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0df_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0dc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0dd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0de(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0dc_hcic_reg0df(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0dc_get_hcic_reg0dc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0dc_get_hcic_reg0dd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0dc_get_hcic_reg0de(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0dc_get_hcic_reg0df(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0e0                                                     0x1802A5E4
#define  LG_HCIC_HCIC_reg0e0_reg_addr                                            "0xB802A5E4"
#define  LG_HCIC_HCIC_reg0e0_reg                                                 0xB802A5E4
#define  LG_HCIC_HCIC_reg0e0_inst_addr                                           "0x0039"
#define  set_LG_HCIC_HCIC_reg0e0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0e0_reg)=data)
#define  get_LG_HCIC_HCIC_reg0e0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0e0_reg))
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e0_shift                                   (24)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e1_shift                                   (16)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e2_shift                                   (8)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e3_shift                                   (0)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0e0_hcic_reg0e3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0e0_get_hcic_reg0e0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0e0_get_hcic_reg0e1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0e0_get_hcic_reg0e2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0e0_get_hcic_reg0e3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0e4                                                     0x1802A5E8
#define  LG_HCIC_HCIC_reg0e4_reg_addr                                            "0xB802A5E8"
#define  LG_HCIC_HCIC_reg0e4_reg                                                 0xB802A5E8
#define  LG_HCIC_HCIC_reg0e4_inst_addr                                           "0x003A"
#define  set_LG_HCIC_HCIC_reg0e4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0e4_reg)=data)
#define  get_LG_HCIC_HCIC_reg0e4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0e4_reg))
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e4_shift                                   (24)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e5_shift                                   (16)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e6_shift                                   (8)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e7_shift                                   (0)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0e4_hcic_reg0e7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0e4_get_hcic_reg0e4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0e4_get_hcic_reg0e5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0e4_get_hcic_reg0e6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0e4_get_hcic_reg0e7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0e8                                                     0x1802A5EC
#define  LG_HCIC_HCIC_reg0e8_reg_addr                                            "0xB802A5EC"
#define  LG_HCIC_HCIC_reg0e8_reg                                                 0xB802A5EC
#define  LG_HCIC_HCIC_reg0e8_inst_addr                                           "0x003B"
#define  set_LG_HCIC_HCIC_reg0e8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0e8_reg)=data)
#define  get_LG_HCIC_HCIC_reg0e8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0e8_reg))
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0e8_shift                                   (24)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0e9_shift                                   (16)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0ea_shift                                   (8)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0eb_shift                                   (0)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0e8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0e9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0ea_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0eb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0e8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0e9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0ea(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0e8_hcic_reg0eb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0e8_get_hcic_reg0e8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0e8_get_hcic_reg0e9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0e8_get_hcic_reg0ea(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0e8_get_hcic_reg0eb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0ec                                                     0x1802A5F0
#define  LG_HCIC_HCIC_reg0ec_reg_addr                                            "0xB802A5F0"
#define  LG_HCIC_HCIC_reg0ec_reg                                                 0xB802A5F0
#define  LG_HCIC_HCIC_reg0ec_inst_addr                                           "0x003C"
#define  set_LG_HCIC_HCIC_reg0ec_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0ec_reg)=data)
#define  get_LG_HCIC_HCIC_reg0ec_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0ec_reg))
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ec_shift                                   (24)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ed_shift                                   (16)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ee_shift                                   (8)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ef_shift                                   (0)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ec_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ed_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ee_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ef_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ec(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ed(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ee(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0ec_hcic_reg0ef(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0ec_get_hcic_reg0ec(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0ec_get_hcic_reg0ed(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0ec_get_hcic_reg0ee(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0ec_get_hcic_reg0ef(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0f0                                                     0x1802A5F4
#define  LG_HCIC_HCIC_reg0f0_reg_addr                                            "0xB802A5F4"
#define  LG_HCIC_HCIC_reg0f0_reg                                                 0xB802A5F4
#define  LG_HCIC_HCIC_reg0f0_inst_addr                                           "0x003D"
#define  set_LG_HCIC_HCIC_reg0f0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0f0_reg)=data)
#define  get_LG_HCIC_HCIC_reg0f0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0f0_reg))
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f0_shift                                   (24)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f1_shift                                   (16)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f2_shift                                   (8)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f3_shift                                   (0)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0f0_hcic_reg0f3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0f0_get_hcic_reg0f0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0f0_get_hcic_reg0f1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0f0_get_hcic_reg0f2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0f0_get_hcic_reg0f3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0f4                                                     0x1802A5F8
#define  LG_HCIC_HCIC_reg0f4_reg_addr                                            "0xB802A5F8"
#define  LG_HCIC_HCIC_reg0f4_reg                                                 0xB802A5F8
#define  LG_HCIC_HCIC_reg0f4_inst_addr                                           "0x003E"
#define  set_LG_HCIC_HCIC_reg0f4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0f4_reg)=data)
#define  get_LG_HCIC_HCIC_reg0f4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0f4_reg))
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f4_shift                                   (24)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f5_shift                                   (16)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f6_shift                                   (8)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f7_shift                                   (0)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0f4_hcic_reg0f7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0f4_get_hcic_reg0f4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0f4_get_hcic_reg0f5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0f4_get_hcic_reg0f6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0f4_get_hcic_reg0f7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0f8                                                     0x1802A5FC
#define  LG_HCIC_HCIC_reg0f8_reg_addr                                            "0xB802A5FC"
#define  LG_HCIC_HCIC_reg0f8_reg                                                 0xB802A5FC
#define  LG_HCIC_HCIC_reg0f8_inst_addr                                           "0x003F"
#define  set_LG_HCIC_HCIC_reg0f8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0f8_reg)=data)
#define  get_LG_HCIC_HCIC_reg0f8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0f8_reg))
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0f8_shift                                   (24)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0f9_shift                                   (16)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0fa_shift                                   (8)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0fb_shift                                   (0)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0f8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0f9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0fa_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0fb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0f8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0f9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0fa(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0f8_hcic_reg0fb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0f8_get_hcic_reg0f8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0f8_get_hcic_reg0f9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0f8_get_hcic_reg0fa(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0f8_get_hcic_reg0fb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg0fc                                                     0x1802A600
#define  LG_HCIC_HCIC_reg0fc_reg_addr                                            "0xB802A600"
#define  LG_HCIC_HCIC_reg0fc_reg                                                 0xB802A600
#define  LG_HCIC_HCIC_reg0fc_inst_addr                                           "0x0040"
#define  set_LG_HCIC_HCIC_reg0fc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg0fc_reg)=data)
#define  get_LG_HCIC_HCIC_reg0fc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg0fc_reg))
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fc_shift                                   (24)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fd_shift                                   (16)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fe_shift                                   (8)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0ff_shift                                   (0)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fe_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0ff_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0fe(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg0fc_hcic_reg0ff(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg0fc_get_hcic_reg0fc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg0fc_get_hcic_reg0fd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg0fc_get_hcic_reg0fe(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg0fc_get_hcic_reg0ff(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg100                                                     0x1802A604
#define  LG_HCIC_HCIC_reg100_reg_addr                                            "0xB802A604"
#define  LG_HCIC_HCIC_reg100_reg                                                 0xB802A604
#define  LG_HCIC_HCIC_reg100_inst_addr                                           "0x0041"
#define  set_LG_HCIC_HCIC_reg100_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg100_reg)=data)
#define  get_LG_HCIC_HCIC_reg100_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg100_reg))
#define  LG_HCIC_HCIC_reg100_hcic_reg100_shift                                   (24)
#define  LG_HCIC_HCIC_reg100_hcic_reg101_shift                                   (16)
#define  LG_HCIC_HCIC_reg100_hcic_reg102_shift                                   (8)
#define  LG_HCIC_HCIC_reg100_hcic_reg103_shift                                   (0)
#define  LG_HCIC_HCIC_reg100_hcic_reg100_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg100_hcic_reg101_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg100_hcic_reg102_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg100_hcic_reg103_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg100_hcic_reg100(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg100_hcic_reg101(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg100_hcic_reg102(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg100_hcic_reg103(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg100_get_hcic_reg100(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg100_get_hcic_reg101(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg100_get_hcic_reg102(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg100_get_hcic_reg103(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg104                                                     0x1802A608
#define  LG_HCIC_HCIC_reg104_reg_addr                                            "0xB802A608"
#define  LG_HCIC_HCIC_reg104_reg                                                 0xB802A608
#define  LG_HCIC_HCIC_reg104_inst_addr                                           "0x0042"
#define  set_LG_HCIC_HCIC_reg104_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg104_reg)=data)
#define  get_LG_HCIC_HCIC_reg104_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg104_reg))
#define  LG_HCIC_HCIC_reg104_hcic_reg104_shift                                   (24)
#define  LG_HCIC_HCIC_reg104_hcic_reg105_shift                                   (16)
#define  LG_HCIC_HCIC_reg104_hcic_reg106_shift                                   (8)
#define  LG_HCIC_HCIC_reg104_hcic_reg107_shift                                   (0)
#define  LG_HCIC_HCIC_reg104_hcic_reg104_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg104_hcic_reg105_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg104_hcic_reg106_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg104_hcic_reg107_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg104_hcic_reg104(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg104_hcic_reg105(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg104_hcic_reg106(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg104_hcic_reg107(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg104_get_hcic_reg104(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg104_get_hcic_reg105(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg104_get_hcic_reg106(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg104_get_hcic_reg107(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg108                                                     0x1802A60C
#define  LG_HCIC_HCIC_reg108_reg_addr                                            "0xB802A60C"
#define  LG_HCIC_HCIC_reg108_reg                                                 0xB802A60C
#define  LG_HCIC_HCIC_reg108_inst_addr                                           "0x0043"
#define  set_LG_HCIC_HCIC_reg108_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg108_reg)=data)
#define  get_LG_HCIC_HCIC_reg108_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg108_reg))
#define  LG_HCIC_HCIC_reg108_hcic_reg108_shift                                   (24)
#define  LG_HCIC_HCIC_reg108_hcic_reg109_shift                                   (16)
#define  LG_HCIC_HCIC_reg108_hcic_reg10a_shift                                   (8)
#define  LG_HCIC_HCIC_reg108_hcic_reg10b_shift                                   (0)
#define  LG_HCIC_HCIC_reg108_hcic_reg108_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg108_hcic_reg109_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg108_hcic_reg10a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg108_hcic_reg10b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg108_hcic_reg108(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg108_hcic_reg109(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg108_hcic_reg10a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg108_hcic_reg10b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg108_get_hcic_reg108(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg108_get_hcic_reg109(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg108_get_hcic_reg10a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg108_get_hcic_reg10b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg10c                                                     0x1802A610
#define  LG_HCIC_HCIC_reg10c_reg_addr                                            "0xB802A610"
#define  LG_HCIC_HCIC_reg10c_reg                                                 0xB802A610
#define  LG_HCIC_HCIC_reg10c_inst_addr                                           "0x0044"
#define  set_LG_HCIC_HCIC_reg10c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg10c_reg)=data)
#define  get_LG_HCIC_HCIC_reg10c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg10c_reg))
#define  LG_HCIC_HCIC_reg10c_hcic_reg10c_shift                                   (24)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10d_shift                                   (16)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10e_shift                                   (8)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10f_shift                                   (0)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg10c_hcic_reg10c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg10c_hcic_reg10d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg10c_hcic_reg10e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg10c_hcic_reg10f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg10c_get_hcic_reg10c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg10c_get_hcic_reg10d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg10c_get_hcic_reg10e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg10c_get_hcic_reg10f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg110                                                     0x1802A614
#define  LG_HCIC_HCIC_reg110_reg_addr                                            "0xB802A614"
#define  LG_HCIC_HCIC_reg110_reg                                                 0xB802A614
#define  LG_HCIC_HCIC_reg110_inst_addr                                           "0x0045"
#define  set_LG_HCIC_HCIC_reg110_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg110_reg)=data)
#define  get_LG_HCIC_HCIC_reg110_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg110_reg))
#define  LG_HCIC_HCIC_reg110_hcic_reg110_shift                                   (24)
#define  LG_HCIC_HCIC_reg110_hcic_reg111_shift                                   (16)
#define  LG_HCIC_HCIC_reg110_hcic_reg112_shift                                   (8)
#define  LG_HCIC_HCIC_reg110_hcic_reg113_shift                                   (0)
#define  LG_HCIC_HCIC_reg110_hcic_reg110_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg110_hcic_reg111_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg110_hcic_reg112_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg110_hcic_reg113_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg110_hcic_reg110(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg110_hcic_reg111(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg110_hcic_reg112(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg110_hcic_reg113(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg110_get_hcic_reg110(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg110_get_hcic_reg111(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg110_get_hcic_reg112(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg110_get_hcic_reg113(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg114                                                     0x1802A618
#define  LG_HCIC_HCIC_reg114_reg_addr                                            "0xB802A618"
#define  LG_HCIC_HCIC_reg114_reg                                                 0xB802A618
#define  LG_HCIC_HCIC_reg114_inst_addr                                           "0x0046"
#define  set_LG_HCIC_HCIC_reg114_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg114_reg)=data)
#define  get_LG_HCIC_HCIC_reg114_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg114_reg))
#define  LG_HCIC_HCIC_reg114_hcic_reg114_shift                                   (24)
#define  LG_HCIC_HCIC_reg114_hcic_reg115_shift                                   (16)
#define  LG_HCIC_HCIC_reg114_hcic_reg116_shift                                   (8)
#define  LG_HCIC_HCIC_reg114_hcic_reg117_shift                                   (0)
#define  LG_HCIC_HCIC_reg114_hcic_reg114_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg114_hcic_reg115_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg114_hcic_reg116_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg114_hcic_reg117_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg114_hcic_reg114(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg114_hcic_reg115(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg114_hcic_reg116(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg114_hcic_reg117(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg114_get_hcic_reg114(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg114_get_hcic_reg115(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg114_get_hcic_reg116(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg114_get_hcic_reg117(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg118                                                     0x1802A61C
#define  LG_HCIC_HCIC_reg118_reg_addr                                            "0xB802A61C"
#define  LG_HCIC_HCIC_reg118_reg                                                 0xB802A61C
#define  LG_HCIC_HCIC_reg118_inst_addr                                           "0x0047"
#define  set_LG_HCIC_HCIC_reg118_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg118_reg)=data)
#define  get_LG_HCIC_HCIC_reg118_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg118_reg))
#define  LG_HCIC_HCIC_reg118_hcic_reg118_shift                                   (24)
#define  LG_HCIC_HCIC_reg118_hcic_reg119_shift                                   (16)
#define  LG_HCIC_HCIC_reg118_hcic_reg11a_shift                                   (8)
#define  LG_HCIC_HCIC_reg118_hcic_reg11b_shift                                   (0)
#define  LG_HCIC_HCIC_reg118_hcic_reg118_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg118_hcic_reg119_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg118_hcic_reg11a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg118_hcic_reg11b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg118_hcic_reg118(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg118_hcic_reg119(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg118_hcic_reg11a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg118_hcic_reg11b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg118_get_hcic_reg118(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg118_get_hcic_reg119(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg118_get_hcic_reg11a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg118_get_hcic_reg11b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg11c                                                     0x1802A620
#define  LG_HCIC_HCIC_reg11c_reg_addr                                            "0xB802A620"
#define  LG_HCIC_HCIC_reg11c_reg                                                 0xB802A620
#define  LG_HCIC_HCIC_reg11c_inst_addr                                           "0x0048"
#define  set_LG_HCIC_HCIC_reg11c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg11c_reg)=data)
#define  get_LG_HCIC_HCIC_reg11c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg11c_reg))
#define  LG_HCIC_HCIC_reg11c_hcic_reg11c_shift                                   (24)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11d_shift                                   (16)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11e_shift                                   (8)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11f_shift                                   (0)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg11c_hcic_reg11c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg11c_hcic_reg11d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg11c_hcic_reg11e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg11c_hcic_reg11f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg11c_get_hcic_reg11c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg11c_get_hcic_reg11d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg11c_get_hcic_reg11e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg11c_get_hcic_reg11f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg120                                                     0x1802A624
#define  LG_HCIC_HCIC_reg120_reg_addr                                            "0xB802A624"
#define  LG_HCIC_HCIC_reg120_reg                                                 0xB802A624
#define  LG_HCIC_HCIC_reg120_inst_addr                                           "0x0049"
#define  set_LG_HCIC_HCIC_reg120_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg120_reg)=data)
#define  get_LG_HCIC_HCIC_reg120_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg120_reg))
#define  LG_HCIC_HCIC_reg120_hcic_reg120_shift                                   (24)
#define  LG_HCIC_HCIC_reg120_hcic_reg121_shift                                   (16)
#define  LG_HCIC_HCIC_reg120_hcic_reg122_shift                                   (8)
#define  LG_HCIC_HCIC_reg120_hcic_reg123_shift                                   (0)
#define  LG_HCIC_HCIC_reg120_hcic_reg120_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg120_hcic_reg121_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg120_hcic_reg122_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg120_hcic_reg123_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg120_hcic_reg120(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg120_hcic_reg121(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg120_hcic_reg122(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg120_hcic_reg123(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg120_get_hcic_reg120(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg120_get_hcic_reg121(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg120_get_hcic_reg122(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg120_get_hcic_reg123(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg124                                                     0x1802A628
#define  LG_HCIC_HCIC_reg124_reg_addr                                            "0xB802A628"
#define  LG_HCIC_HCIC_reg124_reg                                                 0xB802A628
#define  LG_HCIC_HCIC_reg124_inst_addr                                           "0x004A"
#define  set_LG_HCIC_HCIC_reg124_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg124_reg)=data)
#define  get_LG_HCIC_HCIC_reg124_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg124_reg))
#define  LG_HCIC_HCIC_reg124_hcic_reg124_shift                                   (24)
#define  LG_HCIC_HCIC_reg124_hcic_reg125_shift                                   (16)
#define  LG_HCIC_HCIC_reg124_hcic_reg126_shift                                   (8)
#define  LG_HCIC_HCIC_reg124_hcic_reg127_shift                                   (0)
#define  LG_HCIC_HCIC_reg124_hcic_reg124_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg124_hcic_reg125_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg124_hcic_reg126_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg124_hcic_reg127_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg124_hcic_reg124(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg124_hcic_reg125(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg124_hcic_reg126(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg124_hcic_reg127(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg124_get_hcic_reg124(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg124_get_hcic_reg125(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg124_get_hcic_reg126(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg124_get_hcic_reg127(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg128                                                     0x1802A62C
#define  LG_HCIC_HCIC_reg128_reg_addr                                            "0xB802A62C"
#define  LG_HCIC_HCIC_reg128_reg                                                 0xB802A62C
#define  LG_HCIC_HCIC_reg128_inst_addr                                           "0x004B"
#define  set_LG_HCIC_HCIC_reg128_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg128_reg)=data)
#define  get_LG_HCIC_HCIC_reg128_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg128_reg))
#define  LG_HCIC_HCIC_reg128_hcic_reg128_shift                                   (24)
#define  LG_HCIC_HCIC_reg128_hcic_reg129_shift                                   (16)
#define  LG_HCIC_HCIC_reg128_hcic_reg12a_shift                                   (8)
#define  LG_HCIC_HCIC_reg128_hcic_reg12b_shift                                   (0)
#define  LG_HCIC_HCIC_reg128_hcic_reg128_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg128_hcic_reg129_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg128_hcic_reg12a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg128_hcic_reg12b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg128_hcic_reg128(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg128_hcic_reg129(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg128_hcic_reg12a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg128_hcic_reg12b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg128_get_hcic_reg128(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg128_get_hcic_reg129(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg128_get_hcic_reg12a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg128_get_hcic_reg12b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg12c                                                     0x1802A630
#define  LG_HCIC_HCIC_reg12c_reg_addr                                            "0xB802A630"
#define  LG_HCIC_HCIC_reg12c_reg                                                 0xB802A630
#define  LG_HCIC_HCIC_reg12c_inst_addr                                           "0x004C"
#define  set_LG_HCIC_HCIC_reg12c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg12c_reg)=data)
#define  get_LG_HCIC_HCIC_reg12c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg12c_reg))
#define  LG_HCIC_HCIC_reg12c_hcic_reg12c_shift                                   (24)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12d_shift                                   (16)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12e_shift                                   (8)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12f_shift                                   (0)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg12c_hcic_reg12c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg12c_hcic_reg12d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg12c_hcic_reg12e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg12c_hcic_reg12f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg12c_get_hcic_reg12c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg12c_get_hcic_reg12d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg12c_get_hcic_reg12e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg12c_get_hcic_reg12f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg130                                                     0x1802A634
#define  LG_HCIC_HCIC_reg130_reg_addr                                            "0xB802A634"
#define  LG_HCIC_HCIC_reg130_reg                                                 0xB802A634
#define  LG_HCIC_HCIC_reg130_inst_addr                                           "0x004D"
#define  set_LG_HCIC_HCIC_reg130_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg130_reg)=data)
#define  get_LG_HCIC_HCIC_reg130_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg130_reg))
#define  LG_HCIC_HCIC_reg130_hcic_reg130_shift                                   (24)
#define  LG_HCIC_HCIC_reg130_hcic_reg131_shift                                   (16)
#define  LG_HCIC_HCIC_reg130_hcic_reg132_shift                                   (8)
#define  LG_HCIC_HCIC_reg130_hcic_reg133_shift                                   (0)
#define  LG_HCIC_HCIC_reg130_hcic_reg130_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg130_hcic_reg131_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg130_hcic_reg132_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg130_hcic_reg133_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg130_hcic_reg130(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg130_hcic_reg131(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg130_hcic_reg132(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg130_hcic_reg133(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg130_get_hcic_reg130(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg130_get_hcic_reg131(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg130_get_hcic_reg132(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg130_get_hcic_reg133(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg134                                                     0x1802A638
#define  LG_HCIC_HCIC_reg134_reg_addr                                            "0xB802A638"
#define  LG_HCIC_HCIC_reg134_reg                                                 0xB802A638
#define  LG_HCIC_HCIC_reg134_inst_addr                                           "0x004E"
#define  set_LG_HCIC_HCIC_reg134_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg134_reg)=data)
#define  get_LG_HCIC_HCIC_reg134_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg134_reg))
#define  LG_HCIC_HCIC_reg134_hcic_reg134_shift                                   (24)
#define  LG_HCIC_HCIC_reg134_hcic_reg135_shift                                   (16)
#define  LG_HCIC_HCIC_reg134_hcic_reg136_shift                                   (8)
#define  LG_HCIC_HCIC_reg134_hcic_reg137_shift                                   (0)
#define  LG_HCIC_HCIC_reg134_hcic_reg134_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg134_hcic_reg135_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg134_hcic_reg136_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg134_hcic_reg137_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg134_hcic_reg134(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg134_hcic_reg135(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg134_hcic_reg136(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg134_hcic_reg137(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg134_get_hcic_reg134(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg134_get_hcic_reg135(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg134_get_hcic_reg136(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg134_get_hcic_reg137(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg138                                                     0x1802A63C
#define  LG_HCIC_HCIC_reg138_reg_addr                                            "0xB802A63C"
#define  LG_HCIC_HCIC_reg138_reg                                                 0xB802A63C
#define  LG_HCIC_HCIC_reg138_inst_addr                                           "0x004F"
#define  set_LG_HCIC_HCIC_reg138_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg138_reg)=data)
#define  get_LG_HCIC_HCIC_reg138_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg138_reg))
#define  LG_HCIC_HCIC_reg138_hcic_reg138_shift                                   (24)
#define  LG_HCIC_HCIC_reg138_hcic_reg139_shift                                   (16)
#define  LG_HCIC_HCIC_reg138_hcic_reg13a_shift                                   (8)
#define  LG_HCIC_HCIC_reg138_hcic_reg13b_shift                                   (0)
#define  LG_HCIC_HCIC_reg138_hcic_reg138_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg138_hcic_reg139_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg138_hcic_reg13a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg138_hcic_reg13b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg138_hcic_reg138(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg138_hcic_reg139(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg138_hcic_reg13a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg138_hcic_reg13b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg138_get_hcic_reg138(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg138_get_hcic_reg139(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg138_get_hcic_reg13a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg138_get_hcic_reg13b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg13c                                                     0x1802A640
#define  LG_HCIC_HCIC_reg13c_reg_addr                                            "0xB802A640"
#define  LG_HCIC_HCIC_reg13c_reg                                                 0xB802A640
#define  LG_HCIC_HCIC_reg13c_inst_addr                                           "0x0050"
#define  set_LG_HCIC_HCIC_reg13c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg13c_reg)=data)
#define  get_LG_HCIC_HCIC_reg13c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg13c_reg))
#define  LG_HCIC_HCIC_reg13c_hcic_reg13c_shift                                   (24)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13d_shift                                   (16)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13e_shift                                   (8)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13f_shift                                   (0)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg13c_hcic_reg13c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg13c_hcic_reg13d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg13c_hcic_reg13e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg13c_hcic_reg13f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg13c_get_hcic_reg13c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg13c_get_hcic_reg13d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg13c_get_hcic_reg13e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg13c_get_hcic_reg13f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg140                                                     0x1802A644
#define  LG_HCIC_HCIC_reg140_reg_addr                                            "0xB802A644"
#define  LG_HCIC_HCIC_reg140_reg                                                 0xB802A644
#define  LG_HCIC_HCIC_reg140_inst_addr                                           "0x0051"
#define  set_LG_HCIC_HCIC_reg140_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg140_reg)=data)
#define  get_LG_HCIC_HCIC_reg140_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg140_reg))
#define  LG_HCIC_HCIC_reg140_hcic_reg140_shift                                   (24)
#define  LG_HCIC_HCIC_reg140_hcic_reg141_shift                                   (16)
#define  LG_HCIC_HCIC_reg140_hcic_reg142_shift                                   (8)
#define  LG_HCIC_HCIC_reg140_hcic_reg143_shift                                   (0)
#define  LG_HCIC_HCIC_reg140_hcic_reg140_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg140_hcic_reg141_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg140_hcic_reg142_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg140_hcic_reg143_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg140_hcic_reg140(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg140_hcic_reg141(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg140_hcic_reg142(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg140_hcic_reg143(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg140_get_hcic_reg140(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg140_get_hcic_reg141(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg140_get_hcic_reg142(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg140_get_hcic_reg143(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg144                                                     0x1802A648
#define  LG_HCIC_HCIC_reg144_reg_addr                                            "0xB802A648"
#define  LG_HCIC_HCIC_reg144_reg                                                 0xB802A648
#define  LG_HCIC_HCIC_reg144_inst_addr                                           "0x0052"
#define  set_LG_HCIC_HCIC_reg144_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg144_reg)=data)
#define  get_LG_HCIC_HCIC_reg144_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg144_reg))
#define  LG_HCIC_HCIC_reg144_hcic_reg144_shift                                   (24)
#define  LG_HCIC_HCIC_reg144_hcic_reg145_shift                                   (16)
#define  LG_HCIC_HCIC_reg144_hcic_reg146_shift                                   (8)
#define  LG_HCIC_HCIC_reg144_hcic_reg147_shift                                   (0)
#define  LG_HCIC_HCIC_reg144_hcic_reg144_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg144_hcic_reg145_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg144_hcic_reg146_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg144_hcic_reg147_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg144_hcic_reg144(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg144_hcic_reg145(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg144_hcic_reg146(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg144_hcic_reg147(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg144_get_hcic_reg144(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg144_get_hcic_reg145(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg144_get_hcic_reg146(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg144_get_hcic_reg147(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg148                                                     0x1802A64C
#define  LG_HCIC_HCIC_reg148_reg_addr                                            "0xB802A64C"
#define  LG_HCIC_HCIC_reg148_reg                                                 0xB802A64C
#define  LG_HCIC_HCIC_reg148_inst_addr                                           "0x0053"
#define  set_LG_HCIC_HCIC_reg148_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg148_reg)=data)
#define  get_LG_HCIC_HCIC_reg148_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg148_reg))
#define  LG_HCIC_HCIC_reg148_hcic_reg148_shift                                   (24)
#define  LG_HCIC_HCIC_reg148_hcic_reg149_shift                                   (16)
#define  LG_HCIC_HCIC_reg148_hcic_reg14a_shift                                   (8)
#define  LG_HCIC_HCIC_reg148_hcic_reg14b_shift                                   (0)
#define  LG_HCIC_HCIC_reg148_hcic_reg148_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg148_hcic_reg149_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg148_hcic_reg14a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg148_hcic_reg14b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg148_hcic_reg148(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg148_hcic_reg149(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg148_hcic_reg14a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg148_hcic_reg14b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg148_get_hcic_reg148(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg148_get_hcic_reg149(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg148_get_hcic_reg14a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg148_get_hcic_reg14b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg14c                                                     0x1802A650
#define  LG_HCIC_HCIC_reg14c_reg_addr                                            "0xB802A650"
#define  LG_HCIC_HCIC_reg14c_reg                                                 0xB802A650
#define  LG_HCIC_HCIC_reg14c_inst_addr                                           "0x0054"
#define  set_LG_HCIC_HCIC_reg14c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg14c_reg)=data)
#define  get_LG_HCIC_HCIC_reg14c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg14c_reg))
#define  LG_HCIC_HCIC_reg14c_hcic_reg14c_shift                                   (24)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14d_shift                                   (16)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14e_shift                                   (8)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14f_shift                                   (0)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg14c_hcic_reg14c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg14c_hcic_reg14d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg14c_hcic_reg14e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg14c_hcic_reg14f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg14c_get_hcic_reg14c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg14c_get_hcic_reg14d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg14c_get_hcic_reg14e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg14c_get_hcic_reg14f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg150                                                     0x1802A654
#define  LG_HCIC_HCIC_reg150_reg_addr                                            "0xB802A654"
#define  LG_HCIC_HCIC_reg150_reg                                                 0xB802A654
#define  LG_HCIC_HCIC_reg150_inst_addr                                           "0x0055"
#define  set_LG_HCIC_HCIC_reg150_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg150_reg)=data)
#define  get_LG_HCIC_HCIC_reg150_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg150_reg))
#define  LG_HCIC_HCIC_reg150_hcic_reg150_shift                                   (24)
#define  LG_HCIC_HCIC_reg150_hcic_reg151_shift                                   (16)
#define  LG_HCIC_HCIC_reg150_hcic_reg152_shift                                   (8)
#define  LG_HCIC_HCIC_reg150_hcic_reg153_shift                                   (0)
#define  LG_HCIC_HCIC_reg150_hcic_reg150_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg150_hcic_reg151_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg150_hcic_reg152_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg150_hcic_reg153_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg150_hcic_reg150(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg150_hcic_reg151(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg150_hcic_reg152(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg150_hcic_reg153(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg150_get_hcic_reg150(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg150_get_hcic_reg151(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg150_get_hcic_reg152(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg150_get_hcic_reg153(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg154                                                     0x1802A658
#define  LG_HCIC_HCIC_reg154_reg_addr                                            "0xB802A658"
#define  LG_HCIC_HCIC_reg154_reg                                                 0xB802A658
#define  LG_HCIC_HCIC_reg154_inst_addr                                           "0x0056"
#define  set_LG_HCIC_HCIC_reg154_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg154_reg)=data)
#define  get_LG_HCIC_HCIC_reg154_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg154_reg))
#define  LG_HCIC_HCIC_reg154_hcic_reg154_shift                                   (24)
#define  LG_HCIC_HCIC_reg154_hcic_reg155_shift                                   (16)
#define  LG_HCIC_HCIC_reg154_hcic_reg156_shift                                   (8)
#define  LG_HCIC_HCIC_reg154_hcic_reg157_shift                                   (0)
#define  LG_HCIC_HCIC_reg154_hcic_reg154_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg154_hcic_reg155_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg154_hcic_reg156_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg154_hcic_reg157_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg154_hcic_reg154(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg154_hcic_reg155(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg154_hcic_reg156(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg154_hcic_reg157(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg154_get_hcic_reg154(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg154_get_hcic_reg155(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg154_get_hcic_reg156(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg154_get_hcic_reg157(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg158                                                     0x1802A65C
#define  LG_HCIC_HCIC_reg158_reg_addr                                            "0xB802A65C"
#define  LG_HCIC_HCIC_reg158_reg                                                 0xB802A65C
#define  LG_HCIC_HCIC_reg158_inst_addr                                           "0x0057"
#define  set_LG_HCIC_HCIC_reg158_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg158_reg)=data)
#define  get_LG_HCIC_HCIC_reg158_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg158_reg))
#define  LG_HCIC_HCIC_reg158_hcic_reg158_shift                                   (24)
#define  LG_HCIC_HCIC_reg158_hcic_reg159_shift                                   (16)
#define  LG_HCIC_HCIC_reg158_hcic_reg15a_shift                                   (8)
#define  LG_HCIC_HCIC_reg158_hcic_reg15b_shift                                   (0)
#define  LG_HCIC_HCIC_reg158_hcic_reg158_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg158_hcic_reg159_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg158_hcic_reg15a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg158_hcic_reg15b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg158_hcic_reg158(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg158_hcic_reg159(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg158_hcic_reg15a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg158_hcic_reg15b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg158_get_hcic_reg158(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg158_get_hcic_reg159(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg158_get_hcic_reg15a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg158_get_hcic_reg15b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg15c                                                     0x1802A660
#define  LG_HCIC_HCIC_reg15c_reg_addr                                            "0xB802A660"
#define  LG_HCIC_HCIC_reg15c_reg                                                 0xB802A660
#define  LG_HCIC_HCIC_reg15c_inst_addr                                           "0x0058"
#define  set_LG_HCIC_HCIC_reg15c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg15c_reg)=data)
#define  get_LG_HCIC_HCIC_reg15c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg15c_reg))
#define  LG_HCIC_HCIC_reg15c_hcic_reg15c_shift                                   (24)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15d_shift                                   (16)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15e_shift                                   (8)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15f_shift                                   (0)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg15c_hcic_reg15c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg15c_hcic_reg15d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg15c_hcic_reg15e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg15c_hcic_reg15f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg15c_get_hcic_reg15c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg15c_get_hcic_reg15d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg15c_get_hcic_reg15e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg15c_get_hcic_reg15f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg160                                                     0x1802A664
#define  LG_HCIC_HCIC_reg160_reg_addr                                            "0xB802A664"
#define  LG_HCIC_HCIC_reg160_reg                                                 0xB802A664
#define  LG_HCIC_HCIC_reg160_inst_addr                                           "0x0059"
#define  set_LG_HCIC_HCIC_reg160_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg160_reg)=data)
#define  get_LG_HCIC_HCIC_reg160_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg160_reg))
#define  LG_HCIC_HCIC_reg160_hcic_reg160_shift                                   (24)
#define  LG_HCIC_HCIC_reg160_hcic_reg161_shift                                   (16)
#define  LG_HCIC_HCIC_reg160_hcic_reg162_shift                                   (8)
#define  LG_HCIC_HCIC_reg160_hcic_reg163_shift                                   (0)
#define  LG_HCIC_HCIC_reg160_hcic_reg160_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg160_hcic_reg161_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg160_hcic_reg162_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg160_hcic_reg163_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg160_hcic_reg160(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg160_hcic_reg161(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg160_hcic_reg162(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg160_hcic_reg163(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg160_get_hcic_reg160(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg160_get_hcic_reg161(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg160_get_hcic_reg162(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg160_get_hcic_reg163(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg164                                                     0x1802A668
#define  LG_HCIC_HCIC_reg164_reg_addr                                            "0xB802A668"
#define  LG_HCIC_HCIC_reg164_reg                                                 0xB802A668
#define  LG_HCIC_HCIC_reg164_inst_addr                                           "0x005A"
#define  set_LG_HCIC_HCIC_reg164_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg164_reg)=data)
#define  get_LG_HCIC_HCIC_reg164_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg164_reg))
#define  LG_HCIC_HCIC_reg164_hcic_reg164_shift                                   (24)
#define  LG_HCIC_HCIC_reg164_hcic_reg165_shift                                   (16)
#define  LG_HCIC_HCIC_reg164_hcic_reg166_shift                                   (8)
#define  LG_HCIC_HCIC_reg164_hcic_reg167_shift                                   (0)
#define  LG_HCIC_HCIC_reg164_hcic_reg164_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg164_hcic_reg165_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg164_hcic_reg166_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg164_hcic_reg167_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg164_hcic_reg164(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg164_hcic_reg165(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg164_hcic_reg166(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg164_hcic_reg167(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg164_get_hcic_reg164(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg164_get_hcic_reg165(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg164_get_hcic_reg166(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg164_get_hcic_reg167(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg168                                                     0x1802A66C
#define  LG_HCIC_HCIC_reg168_reg_addr                                            "0xB802A66C"
#define  LG_HCIC_HCIC_reg168_reg                                                 0xB802A66C
#define  LG_HCIC_HCIC_reg168_inst_addr                                           "0x005B"
#define  set_LG_HCIC_HCIC_reg168_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg168_reg)=data)
#define  get_LG_HCIC_HCIC_reg168_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg168_reg))
#define  LG_HCIC_HCIC_reg168_hcic_reg168_shift                                   (24)
#define  LG_HCIC_HCIC_reg168_hcic_reg169_shift                                   (16)
#define  LG_HCIC_HCIC_reg168_hcic_reg16a_shift                                   (8)
#define  LG_HCIC_HCIC_reg168_hcic_reg16b_shift                                   (0)
#define  LG_HCIC_HCIC_reg168_hcic_reg168_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg168_hcic_reg169_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg168_hcic_reg16a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg168_hcic_reg16b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg168_hcic_reg168(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg168_hcic_reg169(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg168_hcic_reg16a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg168_hcic_reg16b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg168_get_hcic_reg168(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg168_get_hcic_reg169(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg168_get_hcic_reg16a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg168_get_hcic_reg16b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg16c                                                     0x1802A670
#define  LG_HCIC_HCIC_reg16c_reg_addr                                            "0xB802A670"
#define  LG_HCIC_HCIC_reg16c_reg                                                 0xB802A670
#define  LG_HCIC_HCIC_reg16c_inst_addr                                           "0x005C"
#define  set_LG_HCIC_HCIC_reg16c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg16c_reg)=data)
#define  get_LG_HCIC_HCIC_reg16c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg16c_reg))
#define  LG_HCIC_HCIC_reg16c_hcic_reg16c_shift                                   (24)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16d_shift                                   (16)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16e_shift                                   (8)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16f_shift                                   (0)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg16c_hcic_reg16c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg16c_hcic_reg16d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg16c_hcic_reg16e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg16c_hcic_reg16f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg16c_get_hcic_reg16c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg16c_get_hcic_reg16d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg16c_get_hcic_reg16e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg16c_get_hcic_reg16f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg170                                                     0x1802A674
#define  LG_HCIC_HCIC_reg170_reg_addr                                            "0xB802A674"
#define  LG_HCIC_HCIC_reg170_reg                                                 0xB802A674
#define  LG_HCIC_HCIC_reg170_inst_addr                                           "0x005D"
#define  set_LG_HCIC_HCIC_reg170_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg170_reg)=data)
#define  get_LG_HCIC_HCIC_reg170_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg170_reg))
#define  LG_HCIC_HCIC_reg170_hcic_reg170_shift                                   (24)
#define  LG_HCIC_HCIC_reg170_hcic_reg171_shift                                   (16)
#define  LG_HCIC_HCIC_reg170_hcic_reg172_shift                                   (8)
#define  LG_HCIC_HCIC_reg170_hcic_reg173_shift                                   (0)
#define  LG_HCIC_HCIC_reg170_hcic_reg170_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg170_hcic_reg171_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg170_hcic_reg172_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg170_hcic_reg173_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg170_hcic_reg170(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg170_hcic_reg171(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg170_hcic_reg172(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg170_hcic_reg173(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg170_get_hcic_reg170(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg170_get_hcic_reg171(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg170_get_hcic_reg172(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg170_get_hcic_reg173(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg174                                                     0x1802A678
#define  LG_HCIC_HCIC_reg174_reg_addr                                            "0xB802A678"
#define  LG_HCIC_HCIC_reg174_reg                                                 0xB802A678
#define  LG_HCIC_HCIC_reg174_inst_addr                                           "0x005E"
#define  set_LG_HCIC_HCIC_reg174_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg174_reg)=data)
#define  get_LG_HCIC_HCIC_reg174_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg174_reg))
#define  LG_HCIC_HCIC_reg174_hcic_reg174_shift                                   (24)
#define  LG_HCIC_HCIC_reg174_hcic_reg175_shift                                   (16)
#define  LG_HCIC_HCIC_reg174_hcic_reg176_shift                                   (8)
#define  LG_HCIC_HCIC_reg174_hcic_reg177_shift                                   (0)
#define  LG_HCIC_HCIC_reg174_hcic_reg174_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg174_hcic_reg175_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg174_hcic_reg176_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg174_hcic_reg177_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg174_hcic_reg174(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg174_hcic_reg175(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg174_hcic_reg176(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg174_hcic_reg177(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg174_get_hcic_reg174(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg174_get_hcic_reg175(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg174_get_hcic_reg176(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg174_get_hcic_reg177(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg178                                                     0x1802A67C
#define  LG_HCIC_HCIC_reg178_reg_addr                                            "0xB802A67C"
#define  LG_HCIC_HCIC_reg178_reg                                                 0xB802A67C
#define  LG_HCIC_HCIC_reg178_inst_addr                                           "0x005F"
#define  set_LG_HCIC_HCIC_reg178_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg178_reg)=data)
#define  get_LG_HCIC_HCIC_reg178_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg178_reg))
#define  LG_HCIC_HCIC_reg178_hcic_reg178_shift                                   (24)
#define  LG_HCIC_HCIC_reg178_hcic_reg179_shift                                   (16)
#define  LG_HCIC_HCIC_reg178_hcic_reg17a_shift                                   (8)
#define  LG_HCIC_HCIC_reg178_hcic_reg17b_shift                                   (0)
#define  LG_HCIC_HCIC_reg178_hcic_reg178_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg178_hcic_reg179_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg178_hcic_reg17a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg178_hcic_reg17b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg178_hcic_reg178(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg178_hcic_reg179(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg178_hcic_reg17a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg178_hcic_reg17b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg178_get_hcic_reg178(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg178_get_hcic_reg179(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg178_get_hcic_reg17a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg178_get_hcic_reg17b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg17c                                                     0x1802A680
#define  LG_HCIC_HCIC_reg17c_reg_addr                                            "0xB802A680"
#define  LG_HCIC_HCIC_reg17c_reg                                                 0xB802A680
#define  LG_HCIC_HCIC_reg17c_inst_addr                                           "0x0060"
#define  set_LG_HCIC_HCIC_reg17c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg17c_reg)=data)
#define  get_LG_HCIC_HCIC_reg17c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg17c_reg))
#define  LG_HCIC_HCIC_reg17c_hcic_reg17c_shift                                   (24)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17d_shift                                   (16)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17e_shift                                   (8)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17f_shift                                   (0)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg17c_hcic_reg17c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg17c_hcic_reg17d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg17c_hcic_reg17e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg17c_hcic_reg17f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg17c_get_hcic_reg17c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg17c_get_hcic_reg17d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg17c_get_hcic_reg17e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg17c_get_hcic_reg17f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg180                                                     0x1802A684
#define  LG_HCIC_HCIC_reg180_reg_addr                                            "0xB802A684"
#define  LG_HCIC_HCIC_reg180_reg                                                 0xB802A684
#define  LG_HCIC_HCIC_reg180_inst_addr                                           "0x0061"
#define  set_LG_HCIC_HCIC_reg180_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg180_reg)=data)
#define  get_LG_HCIC_HCIC_reg180_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg180_reg))
#define  LG_HCIC_HCIC_reg180_hcic_reg180_shift                                   (24)
#define  LG_HCIC_HCIC_reg180_hcic_reg181_shift                                   (16)
#define  LG_HCIC_HCIC_reg180_hcic_reg182_shift                                   (8)
#define  LG_HCIC_HCIC_reg180_hcic_reg183_shift                                   (0)
#define  LG_HCIC_HCIC_reg180_hcic_reg180_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg180_hcic_reg181_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg180_hcic_reg182_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg180_hcic_reg183_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg180_hcic_reg180(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg180_hcic_reg181(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg180_hcic_reg182(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg180_hcic_reg183(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg180_get_hcic_reg180(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg180_get_hcic_reg181(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg180_get_hcic_reg182(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg180_get_hcic_reg183(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg184                                                     0x1802A688
#define  LG_HCIC_HCIC_reg184_reg_addr                                            "0xB802A688"
#define  LG_HCIC_HCIC_reg184_reg                                                 0xB802A688
#define  LG_HCIC_HCIC_reg184_inst_addr                                           "0x0062"
#define  set_LG_HCIC_HCIC_reg184_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg184_reg)=data)
#define  get_LG_HCIC_HCIC_reg184_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg184_reg))
#define  LG_HCIC_HCIC_reg184_hcic_reg184_shift                                   (24)
#define  LG_HCIC_HCIC_reg184_hcic_reg185_shift                                   (16)
#define  LG_HCIC_HCIC_reg184_hcic_reg186_shift                                   (8)
#define  LG_HCIC_HCIC_reg184_hcic_reg187_shift                                   (0)
#define  LG_HCIC_HCIC_reg184_hcic_reg184_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg184_hcic_reg185_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg184_hcic_reg186_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg184_hcic_reg187_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg184_hcic_reg184(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg184_hcic_reg185(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg184_hcic_reg186(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg184_hcic_reg187(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg184_get_hcic_reg184(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg184_get_hcic_reg185(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg184_get_hcic_reg186(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg184_get_hcic_reg187(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg188                                                     0x1802A68C
#define  LG_HCIC_HCIC_reg188_reg_addr                                            "0xB802A68C"
#define  LG_HCIC_HCIC_reg188_reg                                                 0xB802A68C
#define  LG_HCIC_HCIC_reg188_inst_addr                                           "0x0063"
#define  set_LG_HCIC_HCIC_reg188_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg188_reg)=data)
#define  get_LG_HCIC_HCIC_reg188_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg188_reg))
#define  LG_HCIC_HCIC_reg188_hcic_reg188_shift                                   (24)
#define  LG_HCIC_HCIC_reg188_hcic_reg189_shift                                   (16)
#define  LG_HCIC_HCIC_reg188_hcic_reg18a_shift                                   (8)
#define  LG_HCIC_HCIC_reg188_hcic_reg18b_shift                                   (0)
#define  LG_HCIC_HCIC_reg188_hcic_reg188_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg188_hcic_reg189_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg188_hcic_reg18a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg188_hcic_reg18b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg188_hcic_reg188(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg188_hcic_reg189(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg188_hcic_reg18a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg188_hcic_reg18b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg188_get_hcic_reg188(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg188_get_hcic_reg189(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg188_get_hcic_reg18a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg188_get_hcic_reg18b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg18c                                                     0x1802A690
#define  LG_HCIC_HCIC_reg18c_reg_addr                                            "0xB802A690"
#define  LG_HCIC_HCIC_reg18c_reg                                                 0xB802A690
#define  LG_HCIC_HCIC_reg18c_inst_addr                                           "0x0064"
#define  set_LG_HCIC_HCIC_reg18c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg18c_reg)=data)
#define  get_LG_HCIC_HCIC_reg18c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg18c_reg))
#define  LG_HCIC_HCIC_reg18c_hcic_reg18c_shift                                   (24)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18d_shift                                   (16)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18e_shift                                   (8)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18f_shift                                   (0)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg18c_hcic_reg18c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg18c_hcic_reg18d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg18c_hcic_reg18e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg18c_hcic_reg18f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg18c_get_hcic_reg18c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg18c_get_hcic_reg18d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg18c_get_hcic_reg18e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg18c_get_hcic_reg18f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg190                                                     0x1802A694
#define  LG_HCIC_HCIC_reg190_reg_addr                                            "0xB802A694"
#define  LG_HCIC_HCIC_reg190_reg                                                 0xB802A694
#define  LG_HCIC_HCIC_reg190_inst_addr                                           "0x0065"
#define  set_LG_HCIC_HCIC_reg190_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg190_reg)=data)
#define  get_LG_HCIC_HCIC_reg190_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg190_reg))
#define  LG_HCIC_HCIC_reg190_hcic_reg190_shift                                   (24)
#define  LG_HCIC_HCIC_reg190_hcic_reg191_shift                                   (16)
#define  LG_HCIC_HCIC_reg190_hcic_reg192_shift                                   (8)
#define  LG_HCIC_HCIC_reg190_hcic_reg193_shift                                   (0)
#define  LG_HCIC_HCIC_reg190_hcic_reg190_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg190_hcic_reg191_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg190_hcic_reg192_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg190_hcic_reg193_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg190_hcic_reg190(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg190_hcic_reg191(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg190_hcic_reg192(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg190_hcic_reg193(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg190_get_hcic_reg190(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg190_get_hcic_reg191(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg190_get_hcic_reg192(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg190_get_hcic_reg193(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg194                                                     0x1802A698
#define  LG_HCIC_HCIC_reg194_reg_addr                                            "0xB802A698"
#define  LG_HCIC_HCIC_reg194_reg                                                 0xB802A698
#define  LG_HCIC_HCIC_reg194_inst_addr                                           "0x0066"
#define  set_LG_HCIC_HCIC_reg194_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg194_reg)=data)
#define  get_LG_HCIC_HCIC_reg194_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg194_reg))
#define  LG_HCIC_HCIC_reg194_hcic_reg194_shift                                   (24)
#define  LG_HCIC_HCIC_reg194_hcic_reg195_shift                                   (16)
#define  LG_HCIC_HCIC_reg194_hcic_reg196_shift                                   (8)
#define  LG_HCIC_HCIC_reg194_hcic_reg197_shift                                   (0)
#define  LG_HCIC_HCIC_reg194_hcic_reg194_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg194_hcic_reg195_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg194_hcic_reg196_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg194_hcic_reg197_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg194_hcic_reg194(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg194_hcic_reg195(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg194_hcic_reg196(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg194_hcic_reg197(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg194_get_hcic_reg194(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg194_get_hcic_reg195(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg194_get_hcic_reg196(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg194_get_hcic_reg197(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg198                                                     0x1802A69C
#define  LG_HCIC_HCIC_reg198_reg_addr                                            "0xB802A69C"
#define  LG_HCIC_HCIC_reg198_reg                                                 0xB802A69C
#define  LG_HCIC_HCIC_reg198_inst_addr                                           "0x0067"
#define  set_LG_HCIC_HCIC_reg198_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg198_reg)=data)
#define  get_LG_HCIC_HCIC_reg198_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg198_reg))
#define  LG_HCIC_HCIC_reg198_hcic_reg198_shift                                   (24)
#define  LG_HCIC_HCIC_reg198_hcic_reg199_shift                                   (16)
#define  LG_HCIC_HCIC_reg198_hcic_reg19a_shift                                   (8)
#define  LG_HCIC_HCIC_reg198_hcic_reg19b_shift                                   (0)
#define  LG_HCIC_HCIC_reg198_hcic_reg198_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg198_hcic_reg199_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg198_hcic_reg19a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg198_hcic_reg19b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg198_hcic_reg198(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg198_hcic_reg199(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg198_hcic_reg19a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg198_hcic_reg19b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg198_get_hcic_reg198(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg198_get_hcic_reg199(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg198_get_hcic_reg19a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg198_get_hcic_reg19b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg19c                                                     0x1802A6A0
#define  LG_HCIC_HCIC_reg19c_reg_addr                                            "0xB802A6A0"
#define  LG_HCIC_HCIC_reg19c_reg                                                 0xB802A6A0
#define  LG_HCIC_HCIC_reg19c_inst_addr                                           "0x0068"
#define  set_LG_HCIC_HCIC_reg19c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg19c_reg)=data)
#define  get_LG_HCIC_HCIC_reg19c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg19c_reg))
#define  LG_HCIC_HCIC_reg19c_hcic_reg19c_shift                                   (24)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19d_shift                                   (16)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19e_shift                                   (8)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19f_shift                                   (0)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg19c_hcic_reg19c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg19c_hcic_reg19d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg19c_hcic_reg19e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg19c_hcic_reg19f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg19c_get_hcic_reg19c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg19c_get_hcic_reg19d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg19c_get_hcic_reg19e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg19c_get_hcic_reg19f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1a0                                                     0x1802A6A4
#define  LG_HCIC_HCIC_reg1a0_reg_addr                                            "0xB802A6A4"
#define  LG_HCIC_HCIC_reg1a0_reg                                                 0xB802A6A4
#define  LG_HCIC_HCIC_reg1a0_inst_addr                                           "0x0069"
#define  set_LG_HCIC_HCIC_reg1a0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1a0_reg)=data)
#define  get_LG_HCIC_HCIC_reg1a0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1a0_reg))
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a0_shift                                   (24)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a1_shift                                   (16)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a2_shift                                   (8)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a3_shift                                   (0)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1a0_hcic_reg1a3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1a0_get_hcic_reg1a0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1a0_get_hcic_reg1a1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1a0_get_hcic_reg1a2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1a0_get_hcic_reg1a3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1a4                                                     0x1802A6A8
#define  LG_HCIC_HCIC_reg1a4_reg_addr                                            "0xB802A6A8"
#define  LG_HCIC_HCIC_reg1a4_reg                                                 0xB802A6A8
#define  LG_HCIC_HCIC_reg1a4_inst_addr                                           "0x006A"
#define  set_LG_HCIC_HCIC_reg1a4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1a4_reg)=data)
#define  get_LG_HCIC_HCIC_reg1a4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1a4_reg))
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a4_shift                                   (24)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a5_shift                                   (16)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a6_shift                                   (8)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a7_shift                                   (0)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1a4_hcic_reg1a7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1a4_get_hcic_reg1a4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1a4_get_hcic_reg1a5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1a4_get_hcic_reg1a6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1a4_get_hcic_reg1a7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1a8                                                     0x1802A6AC
#define  LG_HCIC_HCIC_reg1a8_reg_addr                                            "0xB802A6AC"
#define  LG_HCIC_HCIC_reg1a8_reg                                                 0xB802A6AC
#define  LG_HCIC_HCIC_reg1a8_inst_addr                                           "0x006B"
#define  set_LG_HCIC_HCIC_reg1a8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1a8_reg)=data)
#define  get_LG_HCIC_HCIC_reg1a8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1a8_reg))
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1a8_shift                                   (24)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1a9_shift                                   (16)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1aa_shift                                   (8)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1ab_shift                                   (0)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1a8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1a9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1aa_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1ab_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1a8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1a9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1aa(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1a8_hcic_reg1ab(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1a8_get_hcic_reg1a8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1a8_get_hcic_reg1a9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1a8_get_hcic_reg1aa(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1a8_get_hcic_reg1ab(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1ac                                                     0x1802A6B0
#define  LG_HCIC_HCIC_reg1ac_reg_addr                                            "0xB802A6B0"
#define  LG_HCIC_HCIC_reg1ac_reg                                                 0xB802A6B0
#define  LG_HCIC_HCIC_reg1ac_inst_addr                                           "0x006C"
#define  set_LG_HCIC_HCIC_reg1ac_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1ac_reg)=data)
#define  get_LG_HCIC_HCIC_reg1ac_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1ac_reg))
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ac_shift                                   (24)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ad_shift                                   (16)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ae_shift                                   (8)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1af_shift                                   (0)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ac_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ad_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ae_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1af_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ac(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ad(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1ae(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1ac_hcic_reg1af(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1ac_get_hcic_reg1ac(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1ac_get_hcic_reg1ad(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1ac_get_hcic_reg1ae(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1ac_get_hcic_reg1af(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1b0                                                     0x1802A6B4
#define  LG_HCIC_HCIC_reg1b0_reg_addr                                            "0xB802A6B4"
#define  LG_HCIC_HCIC_reg1b0_reg                                                 0xB802A6B4
#define  LG_HCIC_HCIC_reg1b0_inst_addr                                           "0x006D"
#define  set_LG_HCIC_HCIC_reg1b0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1b0_reg)=data)
#define  get_LG_HCIC_HCIC_reg1b0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1b0_reg))
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b0_shift                                   (24)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b1_shift                                   (16)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b2_shift                                   (8)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b3_shift                                   (0)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1b0_hcic_reg1b3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1b0_get_hcic_reg1b0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1b0_get_hcic_reg1b1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1b0_get_hcic_reg1b2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1b0_get_hcic_reg1b3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1b4                                                     0x1802A6B8
#define  LG_HCIC_HCIC_reg1b4_reg_addr                                            "0xB802A6B8"
#define  LG_HCIC_HCIC_reg1b4_reg                                                 0xB802A6B8
#define  LG_HCIC_HCIC_reg1b4_inst_addr                                           "0x006E"
#define  set_LG_HCIC_HCIC_reg1b4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1b4_reg)=data)
#define  get_LG_HCIC_HCIC_reg1b4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1b4_reg))
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b4_shift                                   (24)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b5_shift                                   (16)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b6_shift                                   (8)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b7_shift                                   (0)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1b4_hcic_reg1b7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1b4_get_hcic_reg1b4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1b4_get_hcic_reg1b5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1b4_get_hcic_reg1b6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1b4_get_hcic_reg1b7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1b8                                                     0x1802A6BC
#define  LG_HCIC_HCIC_reg1b8_reg_addr                                            "0xB802A6BC"
#define  LG_HCIC_HCIC_reg1b8_reg                                                 0xB802A6BC
#define  LG_HCIC_HCIC_reg1b8_inst_addr                                           "0x006F"
#define  set_LG_HCIC_HCIC_reg1b8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1b8_reg)=data)
#define  get_LG_HCIC_HCIC_reg1b8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1b8_reg))
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1b8_shift                                   (24)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1b9_shift                                   (16)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1ba_shift                                   (8)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1bb_shift                                   (0)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1b8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1b9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1ba_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1bb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1b8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1b9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1ba(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1b8_hcic_reg1bb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1b8_get_hcic_reg1b8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1b8_get_hcic_reg1b9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1b8_get_hcic_reg1ba(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1b8_get_hcic_reg1bb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1bc                                                     0x1802A6C0
#define  LG_HCIC_HCIC_reg1bc_reg_addr                                            "0xB802A6C0"
#define  LG_HCIC_HCIC_reg1bc_reg                                                 0xB802A6C0
#define  LG_HCIC_HCIC_reg1bc_inst_addr                                           "0x0070"
#define  set_LG_HCIC_HCIC_reg1bc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1bc_reg)=data)
#define  get_LG_HCIC_HCIC_reg1bc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1bc_reg))
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bc_shift                                   (24)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bd_shift                                   (16)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1be_shift                                   (8)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bf_shift                                   (0)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1be_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bf_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1be(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1bc_hcic_reg1bf(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1bc_get_hcic_reg1bc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1bc_get_hcic_reg1bd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1bc_get_hcic_reg1be(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1bc_get_hcic_reg1bf(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1c0                                                     0x1802A6C4
#define  LG_HCIC_HCIC_reg1c0_reg_addr                                            "0xB802A6C4"
#define  LG_HCIC_HCIC_reg1c0_reg                                                 0xB802A6C4
#define  LG_HCIC_HCIC_reg1c0_inst_addr                                           "0x0071"
#define  set_LG_HCIC_HCIC_reg1c0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1c0_reg)=data)
#define  get_LG_HCIC_HCIC_reg1c0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1c0_reg))
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c0_shift                                   (24)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c1_shift                                   (16)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c2_shift                                   (8)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c3_shift                                   (0)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1c0_hcic_reg1c3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1c0_get_hcic_reg1c0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1c0_get_hcic_reg1c1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1c0_get_hcic_reg1c2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1c0_get_hcic_reg1c3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1c4                                                     0x1802A6C8
#define  LG_HCIC_HCIC_reg1c4_reg_addr                                            "0xB802A6C8"
#define  LG_HCIC_HCIC_reg1c4_reg                                                 0xB802A6C8
#define  LG_HCIC_HCIC_reg1c4_inst_addr                                           "0x0072"
#define  set_LG_HCIC_HCIC_reg1c4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1c4_reg)=data)
#define  get_LG_HCIC_HCIC_reg1c4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1c4_reg))
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c4_shift                                   (24)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c5_shift                                   (16)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c6_shift                                   (8)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c7_shift                                   (0)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1c4_hcic_reg1c7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1c4_get_hcic_reg1c4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1c4_get_hcic_reg1c5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1c4_get_hcic_reg1c6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1c4_get_hcic_reg1c7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1c8                                                     0x1802A6CC
#define  LG_HCIC_HCIC_reg1c8_reg_addr                                            "0xB802A6CC"
#define  LG_HCIC_HCIC_reg1c8_reg                                                 0xB802A6CC
#define  LG_HCIC_HCIC_reg1c8_inst_addr                                           "0x0073"
#define  set_LG_HCIC_HCIC_reg1c8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1c8_reg)=data)
#define  get_LG_HCIC_HCIC_reg1c8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1c8_reg))
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1c8_shift                                   (24)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1c9_shift                                   (16)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1ca_shift                                   (8)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1cb_shift                                   (0)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1c8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1c9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1ca_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1cb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1c8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1c9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1ca(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1c8_hcic_reg1cb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1c8_get_hcic_reg1c8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1c8_get_hcic_reg1c9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1c8_get_hcic_reg1ca(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1c8_get_hcic_reg1cb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1cc                                                     0x1802A6D0
#define  LG_HCIC_HCIC_reg1cc_reg_addr                                            "0xB802A6D0"
#define  LG_HCIC_HCIC_reg1cc_reg                                                 0xB802A6D0
#define  LG_HCIC_HCIC_reg1cc_inst_addr                                           "0x0074"
#define  set_LG_HCIC_HCIC_reg1cc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1cc_reg)=data)
#define  get_LG_HCIC_HCIC_reg1cc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1cc_reg))
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cc_shift                                   (24)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cd_shift                                   (16)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1ce_shift                                   (8)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cf_shift                                   (0)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1ce_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cf_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1ce(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1cc_hcic_reg1cf(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1cc_get_hcic_reg1cc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1cc_get_hcic_reg1cd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1cc_get_hcic_reg1ce(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1cc_get_hcic_reg1cf(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1d0                                                     0x1802A6D4
#define  LG_HCIC_HCIC_reg1d0_reg_addr                                            "0xB802A6D4"
#define  LG_HCIC_HCIC_reg1d0_reg                                                 0xB802A6D4
#define  LG_HCIC_HCIC_reg1d0_inst_addr                                           "0x0075"
#define  set_LG_HCIC_HCIC_reg1d0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1d0_reg)=data)
#define  get_LG_HCIC_HCIC_reg1d0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1d0_reg))
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d0_shift                                   (24)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d1_shift                                   (16)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d2_shift                                   (8)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d3_shift                                   (0)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1d0_hcic_reg1d3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1d0_get_hcic_reg1d0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1d0_get_hcic_reg1d1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1d0_get_hcic_reg1d2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1d0_get_hcic_reg1d3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1d4                                                     0x1802A6D8
#define  LG_HCIC_HCIC_reg1d4_reg_addr                                            "0xB802A6D8"
#define  LG_HCIC_HCIC_reg1d4_reg                                                 0xB802A6D8
#define  LG_HCIC_HCIC_reg1d4_inst_addr                                           "0x0076"
#define  set_LG_HCIC_HCIC_reg1d4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1d4_reg)=data)
#define  get_LG_HCIC_HCIC_reg1d4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1d4_reg))
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d4_shift                                   (24)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d5_shift                                   (16)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d6_shift                                   (8)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d7_shift                                   (0)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1d4_hcic_reg1d7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1d4_get_hcic_reg1d4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1d4_get_hcic_reg1d5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1d4_get_hcic_reg1d6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1d4_get_hcic_reg1d7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1d8                                                     0x1802A6DC
#define  LG_HCIC_HCIC_reg1d8_reg_addr                                            "0xB802A6DC"
#define  LG_HCIC_HCIC_reg1d8_reg                                                 0xB802A6DC
#define  LG_HCIC_HCIC_reg1d8_inst_addr                                           "0x0077"
#define  set_LG_HCIC_HCIC_reg1d8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1d8_reg)=data)
#define  get_LG_HCIC_HCIC_reg1d8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1d8_reg))
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1d8_shift                                   (24)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1d9_shift                                   (16)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1da_shift                                   (8)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1db_shift                                   (0)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1d8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1d9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1da_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1db_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1d8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1d9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1da(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1d8_hcic_reg1db(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1d8_get_hcic_reg1d8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1d8_get_hcic_reg1d9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1d8_get_hcic_reg1da(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1d8_get_hcic_reg1db(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1dc                                                     0x1802A6E0
#define  LG_HCIC_HCIC_reg1dc_reg_addr                                            "0xB802A6E0"
#define  LG_HCIC_HCIC_reg1dc_reg                                                 0xB802A6E0
#define  LG_HCIC_HCIC_reg1dc_inst_addr                                           "0x0078"
#define  set_LG_HCIC_HCIC_reg1dc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1dc_reg)=data)
#define  get_LG_HCIC_HCIC_reg1dc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1dc_reg))
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1dc_shift                                   (24)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1dd_shift                                   (16)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1de_shift                                   (8)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1df_shift                                   (0)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1dc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1dd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1de_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1df_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1dc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1dd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1de(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1dc_hcic_reg1df(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1dc_get_hcic_reg1dc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1dc_get_hcic_reg1dd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1dc_get_hcic_reg1de(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1dc_get_hcic_reg1df(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1e0                                                     0x1802A6E4
#define  LG_HCIC_HCIC_reg1e0_reg_addr                                            "0xB802A6E4"
#define  LG_HCIC_HCIC_reg1e0_reg                                                 0xB802A6E4
#define  LG_HCIC_HCIC_reg1e0_inst_addr                                           "0x0079"
#define  set_LG_HCIC_HCIC_reg1e0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1e0_reg)=data)
#define  get_LG_HCIC_HCIC_reg1e0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1e0_reg))
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e0_shift                                   (24)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e1_shift                                   (16)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e2_shift                                   (8)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e3_shift                                   (0)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1e0_hcic_reg1e3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1e0_get_hcic_reg1e0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1e0_get_hcic_reg1e1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1e0_get_hcic_reg1e2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1e0_get_hcic_reg1e3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1e4                                                     0x1802A6E8
#define  LG_HCIC_HCIC_reg1e4_reg_addr                                            "0xB802A6E8"
#define  LG_HCIC_HCIC_reg1e4_reg                                                 0xB802A6E8
#define  LG_HCIC_HCIC_reg1e4_inst_addr                                           "0x007A"
#define  set_LG_HCIC_HCIC_reg1e4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1e4_reg)=data)
#define  get_LG_HCIC_HCIC_reg1e4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1e4_reg))
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e4_shift                                   (24)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e5_shift                                   (16)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e6_shift                                   (8)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e7_shift                                   (0)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1e4_hcic_reg1e7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1e4_get_hcic_reg1e4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1e4_get_hcic_reg1e5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1e4_get_hcic_reg1e6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1e4_get_hcic_reg1e7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1e8                                                     0x1802A6EC
#define  LG_HCIC_HCIC_reg1e8_reg_addr                                            "0xB802A6EC"
#define  LG_HCIC_HCIC_reg1e8_reg                                                 0xB802A6EC
#define  LG_HCIC_HCIC_reg1e8_inst_addr                                           "0x007B"
#define  set_LG_HCIC_HCIC_reg1e8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1e8_reg)=data)
#define  get_LG_HCIC_HCIC_reg1e8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1e8_reg))
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1e8_shift                                   (24)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1e9_shift                                   (16)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1ea_shift                                   (8)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1eb_shift                                   (0)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1e8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1e9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1ea_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1eb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1e8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1e9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1ea(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1e8_hcic_reg1eb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1e8_get_hcic_reg1e8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1e8_get_hcic_reg1e9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1e8_get_hcic_reg1ea(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1e8_get_hcic_reg1eb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1ec                                                     0x1802A6F0
#define  LG_HCIC_HCIC_reg1ec_reg_addr                                            "0xB802A6F0"
#define  LG_HCIC_HCIC_reg1ec_reg                                                 0xB802A6F0
#define  LG_HCIC_HCIC_reg1ec_inst_addr                                           "0x007C"
#define  set_LG_HCIC_HCIC_reg1ec_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1ec_reg)=data)
#define  get_LG_HCIC_HCIC_reg1ec_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1ec_reg))
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ec_shift                                   (24)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ed_shift                                   (16)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ee_shift                                   (8)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ef_shift                                   (0)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ec_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ed_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ee_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ef_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ec(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ed(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ee(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1ec_hcic_reg1ef(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1ec_get_hcic_reg1ec(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1ec_get_hcic_reg1ed(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1ec_get_hcic_reg1ee(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1ec_get_hcic_reg1ef(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1f0                                                     0x1802A6F4
#define  LG_HCIC_HCIC_reg1f0_reg_addr                                            "0xB802A6F4"
#define  LG_HCIC_HCIC_reg1f0_reg                                                 0xB802A6F4
#define  LG_HCIC_HCIC_reg1f0_inst_addr                                           "0x007D"
#define  set_LG_HCIC_HCIC_reg1f0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1f0_reg)=data)
#define  get_LG_HCIC_HCIC_reg1f0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1f0_reg))
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f0_shift                                   (24)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f1_shift                                   (16)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f2_shift                                   (8)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f3_shift                                   (0)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1f0_hcic_reg1f3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1f0_get_hcic_reg1f0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1f0_get_hcic_reg1f1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1f0_get_hcic_reg1f2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1f0_get_hcic_reg1f3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1f4                                                     0x1802A6F8
#define  LG_HCIC_HCIC_reg1f4_reg_addr                                            "0xB802A6F8"
#define  LG_HCIC_HCIC_reg1f4_reg                                                 0xB802A6F8
#define  LG_HCIC_HCIC_reg1f4_inst_addr                                           "0x007E"
#define  set_LG_HCIC_HCIC_reg1f4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1f4_reg)=data)
#define  get_LG_HCIC_HCIC_reg1f4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1f4_reg))
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f4_shift                                   (24)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f5_shift                                   (16)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f6_shift                                   (8)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f7_shift                                   (0)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1f4_hcic_reg1f7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1f4_get_hcic_reg1f4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1f4_get_hcic_reg1f5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1f4_get_hcic_reg1f6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1f4_get_hcic_reg1f7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1f8                                                     0x1802A6FC
#define  LG_HCIC_HCIC_reg1f8_reg_addr                                            "0xB802A6FC"
#define  LG_HCIC_HCIC_reg1f8_reg                                                 0xB802A6FC
#define  LG_HCIC_HCIC_reg1f8_inst_addr                                           "0x007F"
#define  set_LG_HCIC_HCIC_reg1f8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1f8_reg)=data)
#define  get_LG_HCIC_HCIC_reg1f8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1f8_reg))
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1f8_shift                                   (24)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1f9_shift                                   (16)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1fa_shift                                   (8)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1fb_shift                                   (0)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1f8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1f9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1fa_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1fb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1f8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1f9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1fa(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1f8_hcic_reg1fb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1f8_get_hcic_reg1f8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1f8_get_hcic_reg1f9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1f8_get_hcic_reg1fa(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1f8_get_hcic_reg1fb(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg1fc                                                     0x1802A700
#define  LG_HCIC_HCIC_reg1fc_reg_addr                                            "0xB802A700"
#define  LG_HCIC_HCIC_reg1fc_reg                                                 0xB802A700
#define  LG_HCIC_HCIC_reg1fc_inst_addr                                           "0x0080"
#define  set_LG_HCIC_HCIC_reg1fc_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg1fc_reg)=data)
#define  get_LG_HCIC_HCIC_reg1fc_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg1fc_reg))
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fc_shift                                   (24)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fd_shift                                   (16)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fe_shift                                   (8)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1ff_shift                                   (0)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fc_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fd_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fe_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1ff_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fc(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fd(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1fe(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg1fc_hcic_reg1ff(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg1fc_get_hcic_reg1fc(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg1fc_get_hcic_reg1fd(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg1fc_get_hcic_reg1fe(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg1fc_get_hcic_reg1ff(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg200                                                     0x1802A704
#define  LG_HCIC_HCIC_reg200_reg_addr                                            "0xB802A704"
#define  LG_HCIC_HCIC_reg200_reg                                                 0xB802A704
#define  LG_HCIC_HCIC_reg200_inst_addr                                           "0x0081"
#define  set_LG_HCIC_HCIC_reg200_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg200_reg)=data)
#define  get_LG_HCIC_HCIC_reg200_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg200_reg))
#define  LG_HCIC_HCIC_reg200_hcic_reg200_shift                                   (24)
#define  LG_HCIC_HCIC_reg200_hcic_reg201_shift                                   (16)
#define  LG_HCIC_HCIC_reg200_hcic_reg202_shift                                   (8)
#define  LG_HCIC_HCIC_reg200_hcic_reg203_shift                                   (0)
#define  LG_HCIC_HCIC_reg200_hcic_reg200_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg200_hcic_reg201_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg200_hcic_reg202_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg200_hcic_reg203_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg200_hcic_reg200(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg200_hcic_reg201(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg200_hcic_reg202(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg200_hcic_reg203(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg200_get_hcic_reg200(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg200_get_hcic_reg201(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg200_get_hcic_reg202(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg200_get_hcic_reg203(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg204                                                     0x1802A708
#define  LG_HCIC_HCIC_reg204_reg_addr                                            "0xB802A708"
#define  LG_HCIC_HCIC_reg204_reg                                                 0xB802A708
#define  LG_HCIC_HCIC_reg204_inst_addr                                           "0x0082"
#define  set_LG_HCIC_HCIC_reg204_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg204_reg)=data)
#define  get_LG_HCIC_HCIC_reg204_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg204_reg))
#define  LG_HCIC_HCIC_reg204_hcic_reg204_shift                                   (24)
#define  LG_HCIC_HCIC_reg204_hcic_reg205_shift                                   (16)
#define  LG_HCIC_HCIC_reg204_hcic_reg206_shift                                   (8)
#define  LG_HCIC_HCIC_reg204_hcic_reg207_shift                                   (0)
#define  LG_HCIC_HCIC_reg204_hcic_reg204_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg204_hcic_reg205_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg204_hcic_reg206_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg204_hcic_reg207_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg204_hcic_reg204(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg204_hcic_reg205(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg204_hcic_reg206(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg204_hcic_reg207(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg204_get_hcic_reg204(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg204_get_hcic_reg205(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg204_get_hcic_reg206(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg204_get_hcic_reg207(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg208                                                     0x1802A70C
#define  LG_HCIC_HCIC_reg208_reg_addr                                            "0xB802A70C"
#define  LG_HCIC_HCIC_reg208_reg                                                 0xB802A70C
#define  LG_HCIC_HCIC_reg208_inst_addr                                           "0x0083"
#define  set_LG_HCIC_HCIC_reg208_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg208_reg)=data)
#define  get_LG_HCIC_HCIC_reg208_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg208_reg))
#define  LG_HCIC_HCIC_reg208_hcic_reg208_shift                                   (24)
#define  LG_HCIC_HCIC_reg208_hcic_reg209_shift                                   (16)
#define  LG_HCIC_HCIC_reg208_hcic_reg20a_shift                                   (8)
#define  LG_HCIC_HCIC_reg208_hcic_reg20b_shift                                   (0)
#define  LG_HCIC_HCIC_reg208_hcic_reg208_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg208_hcic_reg209_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg208_hcic_reg20a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg208_hcic_reg20b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg208_hcic_reg208(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg208_hcic_reg209(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg208_hcic_reg20a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg208_hcic_reg20b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg208_get_hcic_reg208(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg208_get_hcic_reg209(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg208_get_hcic_reg20a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg208_get_hcic_reg20b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg20c                                                     0x1802A710
#define  LG_HCIC_HCIC_reg20c_reg_addr                                            "0xB802A710"
#define  LG_HCIC_HCIC_reg20c_reg                                                 0xB802A710
#define  LG_HCIC_HCIC_reg20c_inst_addr                                           "0x0084"
#define  set_LG_HCIC_HCIC_reg20c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg20c_reg)=data)
#define  get_LG_HCIC_HCIC_reg20c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg20c_reg))
#define  LG_HCIC_HCIC_reg20c_hcic_reg20c_shift                                   (24)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20d_shift                                   (16)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20e_shift                                   (8)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20f_shift                                   (0)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg20c_hcic_reg20c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg20c_hcic_reg20d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg20c_hcic_reg20e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg20c_hcic_reg20f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg20c_get_hcic_reg20c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg20c_get_hcic_reg20d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg20c_get_hcic_reg20e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg20c_get_hcic_reg20f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg210                                                     0x1802A714
#define  LG_HCIC_HCIC_reg210_reg_addr                                            "0xB802A714"
#define  LG_HCIC_HCIC_reg210_reg                                                 0xB802A714
#define  LG_HCIC_HCIC_reg210_inst_addr                                           "0x0085"
#define  set_LG_HCIC_HCIC_reg210_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg210_reg)=data)
#define  get_LG_HCIC_HCIC_reg210_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg210_reg))
#define  LG_HCIC_HCIC_reg210_hcic_reg210_shift                                   (24)
#define  LG_HCIC_HCIC_reg210_hcic_reg211_shift                                   (16)
#define  LG_HCIC_HCIC_reg210_hcic_reg212_shift                                   (8)
#define  LG_HCIC_HCIC_reg210_hcic_reg213_shift                                   (0)
#define  LG_HCIC_HCIC_reg210_hcic_reg210_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg210_hcic_reg211_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg210_hcic_reg212_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg210_hcic_reg213_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg210_hcic_reg210(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg210_hcic_reg211(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg210_hcic_reg212(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg210_hcic_reg213(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg210_get_hcic_reg210(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg210_get_hcic_reg211(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg210_get_hcic_reg212(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg210_get_hcic_reg213(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg214                                                     0x1802A718
#define  LG_HCIC_HCIC_reg214_reg_addr                                            "0xB802A718"
#define  LG_HCIC_HCIC_reg214_reg                                                 0xB802A718
#define  LG_HCIC_HCIC_reg214_inst_addr                                           "0x0086"
#define  set_LG_HCIC_HCIC_reg214_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg214_reg)=data)
#define  get_LG_HCIC_HCIC_reg214_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg214_reg))
#define  LG_HCIC_HCIC_reg214_hcic_reg214_shift                                   (24)
#define  LG_HCIC_HCIC_reg214_hcic_reg215_shift                                   (16)
#define  LG_HCIC_HCIC_reg214_hcic_reg216_shift                                   (8)
#define  LG_HCIC_HCIC_reg214_hcic_reg217_shift                                   (0)
#define  LG_HCIC_HCIC_reg214_hcic_reg214_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg214_hcic_reg215_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg214_hcic_reg216_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg214_hcic_reg217_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg214_hcic_reg214(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg214_hcic_reg215(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg214_hcic_reg216(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg214_hcic_reg217(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg214_get_hcic_reg214(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg214_get_hcic_reg215(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg214_get_hcic_reg216(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg214_get_hcic_reg217(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg218                                                     0x1802A71C
#define  LG_HCIC_HCIC_reg218_reg_addr                                            "0xB802A71C"
#define  LG_HCIC_HCIC_reg218_reg                                                 0xB802A71C
#define  LG_HCIC_HCIC_reg218_inst_addr                                           "0x0087"
#define  set_LG_HCIC_HCIC_reg218_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg218_reg)=data)
#define  get_LG_HCIC_HCIC_reg218_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg218_reg))
#define  LG_HCIC_HCIC_reg218_hcic_reg218_shift                                   (24)
#define  LG_HCIC_HCIC_reg218_hcic_reg219_shift                                   (16)
#define  LG_HCIC_HCIC_reg218_hcic_reg21a_shift                                   (8)
#define  LG_HCIC_HCIC_reg218_hcic_reg21b_shift                                   (0)
#define  LG_HCIC_HCIC_reg218_hcic_reg218_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg218_hcic_reg219_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg218_hcic_reg21a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg218_hcic_reg21b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg218_hcic_reg218(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg218_hcic_reg219(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg218_hcic_reg21a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg218_hcic_reg21b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg218_get_hcic_reg218(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg218_get_hcic_reg219(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg218_get_hcic_reg21a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg218_get_hcic_reg21b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg21c                                                     0x1802A720
#define  LG_HCIC_HCIC_reg21c_reg_addr                                            "0xB802A720"
#define  LG_HCIC_HCIC_reg21c_reg                                                 0xB802A720
#define  LG_HCIC_HCIC_reg21c_inst_addr                                           "0x0088"
#define  set_LG_HCIC_HCIC_reg21c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg21c_reg)=data)
#define  get_LG_HCIC_HCIC_reg21c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg21c_reg))
#define  LG_HCIC_HCIC_reg21c_hcic_reg21c_shift                                   (24)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21d_shift                                   (16)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21e_shift                                   (8)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21f_shift                                   (0)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg21c_hcic_reg21c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg21c_hcic_reg21d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg21c_hcic_reg21e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg21c_hcic_reg21f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg21c_get_hcic_reg21c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg21c_get_hcic_reg21d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg21c_get_hcic_reg21e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg21c_get_hcic_reg21f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg220                                                     0x1802A724
#define  LG_HCIC_HCIC_reg220_reg_addr                                            "0xB802A724"
#define  LG_HCIC_HCIC_reg220_reg                                                 0xB802A724
#define  LG_HCIC_HCIC_reg220_inst_addr                                           "0x0089"
#define  set_LG_HCIC_HCIC_reg220_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg220_reg)=data)
#define  get_LG_HCIC_HCIC_reg220_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg220_reg))
#define  LG_HCIC_HCIC_reg220_hcic_reg220_shift                                   (24)
#define  LG_HCIC_HCIC_reg220_hcic_reg221_shift                                   (16)
#define  LG_HCIC_HCIC_reg220_hcic_reg222_shift                                   (8)
#define  LG_HCIC_HCIC_reg220_hcic_reg223_shift                                   (0)
#define  LG_HCIC_HCIC_reg220_hcic_reg220_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg220_hcic_reg221_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg220_hcic_reg222_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg220_hcic_reg223_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg220_hcic_reg220(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg220_hcic_reg221(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg220_hcic_reg222(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg220_hcic_reg223(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg220_get_hcic_reg220(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg220_get_hcic_reg221(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg220_get_hcic_reg222(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg220_get_hcic_reg223(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg224                                                     0x1802A728
#define  LG_HCIC_HCIC_reg224_reg_addr                                            "0xB802A728"
#define  LG_HCIC_HCIC_reg224_reg                                                 0xB802A728
#define  LG_HCIC_HCIC_reg224_inst_addr                                           "0x008A"
#define  set_LG_HCIC_HCIC_reg224_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg224_reg)=data)
#define  get_LG_HCIC_HCIC_reg224_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg224_reg))
#define  LG_HCIC_HCIC_reg224_hcic_reg224_shift                                   (24)
#define  LG_HCIC_HCIC_reg224_hcic_reg225_shift                                   (16)
#define  LG_HCIC_HCIC_reg224_hcic_reg226_shift                                   (8)
#define  LG_HCIC_HCIC_reg224_hcic_reg227_shift                                   (0)
#define  LG_HCIC_HCIC_reg224_hcic_reg224_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg224_hcic_reg225_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg224_hcic_reg226_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg224_hcic_reg227_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg224_hcic_reg224(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg224_hcic_reg225(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg224_hcic_reg226(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg224_hcic_reg227(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg224_get_hcic_reg224(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg224_get_hcic_reg225(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg224_get_hcic_reg226(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg224_get_hcic_reg227(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg228                                                     0x1802A72C
#define  LG_HCIC_HCIC_reg228_reg_addr                                            "0xB802A72C"
#define  LG_HCIC_HCIC_reg228_reg                                                 0xB802A72C
#define  LG_HCIC_HCIC_reg228_inst_addr                                           "0x008B"
#define  set_LG_HCIC_HCIC_reg228_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg228_reg)=data)
#define  get_LG_HCIC_HCIC_reg228_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg228_reg))
#define  LG_HCIC_HCIC_reg228_hcic_reg228_shift                                   (24)
#define  LG_HCIC_HCIC_reg228_hcic_reg229_shift                                   (16)
#define  LG_HCIC_HCIC_reg228_hcic_reg22a_shift                                   (8)
#define  LG_HCIC_HCIC_reg228_hcic_reg22b_shift                                   (0)
#define  LG_HCIC_HCIC_reg228_hcic_reg228_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg228_hcic_reg229_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg228_hcic_reg22a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg228_hcic_reg22b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg228_hcic_reg228(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg228_hcic_reg229(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg228_hcic_reg22a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg228_hcic_reg22b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg228_get_hcic_reg228(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg228_get_hcic_reg229(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg228_get_hcic_reg22a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg228_get_hcic_reg22b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg22c                                                     0x1802A730
#define  LG_HCIC_HCIC_reg22c_reg_addr                                            "0xB802A730"
#define  LG_HCIC_HCIC_reg22c_reg                                                 0xB802A730
#define  LG_HCIC_HCIC_reg22c_inst_addr                                           "0x008C"
#define  set_LG_HCIC_HCIC_reg22c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg22c_reg)=data)
#define  get_LG_HCIC_HCIC_reg22c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg22c_reg))
#define  LG_HCIC_HCIC_reg22c_hcic_reg22c_shift                                   (24)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22d_shift                                   (16)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22e_shift                                   (8)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22f_shift                                   (0)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg22c_hcic_reg22c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg22c_hcic_reg22d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg22c_hcic_reg22e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg22c_hcic_reg22f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg22c_get_hcic_reg22c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg22c_get_hcic_reg22d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg22c_get_hcic_reg22e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg22c_get_hcic_reg22f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg230                                                     0x1802A734
#define  LG_HCIC_HCIC_reg230_reg_addr                                            "0xB802A734"
#define  LG_HCIC_HCIC_reg230_reg                                                 0xB802A734
#define  LG_HCIC_HCIC_reg230_inst_addr                                           "0x008D"
#define  set_LG_HCIC_HCIC_reg230_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg230_reg)=data)
#define  get_LG_HCIC_HCIC_reg230_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg230_reg))
#define  LG_HCIC_HCIC_reg230_hcic_reg230_shift                                   (24)
#define  LG_HCIC_HCIC_reg230_hcic_reg231_shift                                   (16)
#define  LG_HCIC_HCIC_reg230_hcic_reg232_shift                                   (8)
#define  LG_HCIC_HCIC_reg230_hcic_reg233_shift                                   (0)
#define  LG_HCIC_HCIC_reg230_hcic_reg230_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg230_hcic_reg231_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg230_hcic_reg232_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg230_hcic_reg233_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg230_hcic_reg230(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg230_hcic_reg231(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg230_hcic_reg232(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg230_hcic_reg233(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg230_get_hcic_reg230(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg230_get_hcic_reg231(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg230_get_hcic_reg232(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg230_get_hcic_reg233(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg234                                                     0x1802A738
#define  LG_HCIC_HCIC_reg234_reg_addr                                            "0xB802A738"
#define  LG_HCIC_HCIC_reg234_reg                                                 0xB802A738
#define  LG_HCIC_HCIC_reg234_inst_addr                                           "0x008E"
#define  set_LG_HCIC_HCIC_reg234_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg234_reg)=data)
#define  get_LG_HCIC_HCIC_reg234_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg234_reg))
#define  LG_HCIC_HCIC_reg234_hcic_reg234_shift                                   (24)
#define  LG_HCIC_HCIC_reg234_hcic_reg235_shift                                   (16)
#define  LG_HCIC_HCIC_reg234_hcic_reg236_shift                                   (8)
#define  LG_HCIC_HCIC_reg234_hcic_reg237_shift                                   (0)
#define  LG_HCIC_HCIC_reg234_hcic_reg234_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg234_hcic_reg235_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg234_hcic_reg236_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg234_hcic_reg237_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg234_hcic_reg234(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg234_hcic_reg235(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg234_hcic_reg236(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg234_hcic_reg237(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg234_get_hcic_reg234(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg234_get_hcic_reg235(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg234_get_hcic_reg236(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg234_get_hcic_reg237(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg238                                                     0x1802A73C
#define  LG_HCIC_HCIC_reg238_reg_addr                                            "0xB802A73C"
#define  LG_HCIC_HCIC_reg238_reg                                                 0xB802A73C
#define  LG_HCIC_HCIC_reg238_inst_addr                                           "0x008F"
#define  set_LG_HCIC_HCIC_reg238_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg238_reg)=data)
#define  get_LG_HCIC_HCIC_reg238_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg238_reg))
#define  LG_HCIC_HCIC_reg238_hcic_reg238_shift                                   (24)
#define  LG_HCIC_HCIC_reg238_hcic_reg239_shift                                   (16)
#define  LG_HCIC_HCIC_reg238_hcic_reg23a_shift                                   (8)
#define  LG_HCIC_HCIC_reg238_hcic_reg23b_shift                                   (0)
#define  LG_HCIC_HCIC_reg238_hcic_reg238_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg238_hcic_reg239_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg238_hcic_reg23a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg238_hcic_reg23b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg238_hcic_reg238(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg238_hcic_reg239(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg238_hcic_reg23a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg238_hcic_reg23b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg238_get_hcic_reg238(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg238_get_hcic_reg239(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg238_get_hcic_reg23a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg238_get_hcic_reg23b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg23c                                                     0x1802A740
#define  LG_HCIC_HCIC_reg23c_reg_addr                                            "0xB802A740"
#define  LG_HCIC_HCIC_reg23c_reg                                                 0xB802A740
#define  LG_HCIC_HCIC_reg23c_inst_addr                                           "0x0090"
#define  set_LG_HCIC_HCIC_reg23c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg23c_reg)=data)
#define  get_LG_HCIC_HCIC_reg23c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg23c_reg))
#define  LG_HCIC_HCIC_reg23c_hcic_reg23c_shift                                   (24)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23d_shift                                   (16)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23e_shift                                   (8)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23f_shift                                   (0)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg23c_hcic_reg23c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg23c_hcic_reg23d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg23c_hcic_reg23e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg23c_hcic_reg23f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg23c_get_hcic_reg23c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg23c_get_hcic_reg23d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg23c_get_hcic_reg23e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg23c_get_hcic_reg23f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg240                                                     0x1802A744
#define  LG_HCIC_HCIC_reg240_reg_addr                                            "0xB802A744"
#define  LG_HCIC_HCIC_reg240_reg                                                 0xB802A744
#define  LG_HCIC_HCIC_reg240_inst_addr                                           "0x0091"
#define  set_LG_HCIC_HCIC_reg240_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg240_reg)=data)
#define  get_LG_HCIC_HCIC_reg240_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg240_reg))
#define  LG_HCIC_HCIC_reg240_hcic_reg240_shift                                   (24)
#define  LG_HCIC_HCIC_reg240_hcic_reg241_shift                                   (16)
#define  LG_HCIC_HCIC_reg240_hcic_reg242_shift                                   (8)
#define  LG_HCIC_HCIC_reg240_hcic_reg243_shift                                   (0)
#define  LG_HCIC_HCIC_reg240_hcic_reg240_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg240_hcic_reg241_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg240_hcic_reg242_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg240_hcic_reg243_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg240_hcic_reg240(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg240_hcic_reg241(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg240_hcic_reg242(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg240_hcic_reg243(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg240_get_hcic_reg240(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg240_get_hcic_reg241(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg240_get_hcic_reg242(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg240_get_hcic_reg243(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg244                                                     0x1802A748
#define  LG_HCIC_HCIC_reg244_reg_addr                                            "0xB802A748"
#define  LG_HCIC_HCIC_reg244_reg                                                 0xB802A748
#define  LG_HCIC_HCIC_reg244_inst_addr                                           "0x0092"
#define  set_LG_HCIC_HCIC_reg244_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg244_reg)=data)
#define  get_LG_HCIC_HCIC_reg244_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg244_reg))
#define  LG_HCIC_HCIC_reg244_hcic_reg244_shift                                   (24)
#define  LG_HCIC_HCIC_reg244_hcic_reg245_shift                                   (16)
#define  LG_HCIC_HCIC_reg244_hcic_reg246_shift                                   (8)
#define  LG_HCIC_HCIC_reg244_hcic_reg247_shift                                   (0)
#define  LG_HCIC_HCIC_reg244_hcic_reg244_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg244_hcic_reg245_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg244_hcic_reg246_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg244_hcic_reg247_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg244_hcic_reg244(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg244_hcic_reg245(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg244_hcic_reg246(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg244_hcic_reg247(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg244_get_hcic_reg244(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg244_get_hcic_reg245(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg244_get_hcic_reg246(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg244_get_hcic_reg247(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg248                                                     0x1802A74C
#define  LG_HCIC_HCIC_reg248_reg_addr                                            "0xB802A74C"
#define  LG_HCIC_HCIC_reg248_reg                                                 0xB802A74C
#define  LG_HCIC_HCIC_reg248_inst_addr                                           "0x0093"
#define  set_LG_HCIC_HCIC_reg248_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg248_reg)=data)
#define  get_LG_HCIC_HCIC_reg248_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg248_reg))
#define  LG_HCIC_HCIC_reg248_hcic_reg248_shift                                   (24)
#define  LG_HCIC_HCIC_reg248_hcic_reg249_shift                                   (16)
#define  LG_HCIC_HCIC_reg248_hcic_reg24a_shift                                   (8)
#define  LG_HCIC_HCIC_reg248_hcic_reg24b_shift                                   (0)
#define  LG_HCIC_HCIC_reg248_hcic_reg248_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg248_hcic_reg249_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg248_hcic_reg24a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg248_hcic_reg24b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg248_hcic_reg248(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg248_hcic_reg249(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg248_hcic_reg24a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg248_hcic_reg24b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg248_get_hcic_reg248(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg248_get_hcic_reg249(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg248_get_hcic_reg24a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg248_get_hcic_reg24b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg24c                                                     0x1802A750
#define  LG_HCIC_HCIC_reg24c_reg_addr                                            "0xB802A750"
#define  LG_HCIC_HCIC_reg24c_reg                                                 0xB802A750
#define  LG_HCIC_HCIC_reg24c_inst_addr                                           "0x0094"
#define  set_LG_HCIC_HCIC_reg24c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg24c_reg)=data)
#define  get_LG_HCIC_HCIC_reg24c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg24c_reg))
#define  LG_HCIC_HCIC_reg24c_hcic_reg24c_shift                                   (24)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24d_shift                                   (16)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24e_shift                                   (8)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24f_shift                                   (0)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg24c_hcic_reg24c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg24c_hcic_reg24d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg24c_hcic_reg24e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg24c_hcic_reg24f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg24c_get_hcic_reg24c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg24c_get_hcic_reg24d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg24c_get_hcic_reg24e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg24c_get_hcic_reg24f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg250                                                     0x1802A754
#define  LG_HCIC_HCIC_reg250_reg_addr                                            "0xB802A754"
#define  LG_HCIC_HCIC_reg250_reg                                                 0xB802A754
#define  LG_HCIC_HCIC_reg250_inst_addr                                           "0x0095"
#define  set_LG_HCIC_HCIC_reg250_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg250_reg)=data)
#define  get_LG_HCIC_HCIC_reg250_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg250_reg))
#define  LG_HCIC_HCIC_reg250_hcic_reg250_shift                                   (24)
#define  LG_HCIC_HCIC_reg250_hcic_reg251_shift                                   (16)
#define  LG_HCIC_HCIC_reg250_hcic_reg252_shift                                   (8)
#define  LG_HCIC_HCIC_reg250_hcic_reg253_shift                                   (0)
#define  LG_HCIC_HCIC_reg250_hcic_reg250_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg250_hcic_reg251_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg250_hcic_reg252_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg250_hcic_reg253_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg250_hcic_reg250(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg250_hcic_reg251(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg250_hcic_reg252(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg250_hcic_reg253(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg250_get_hcic_reg250(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg250_get_hcic_reg251(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg250_get_hcic_reg252(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg250_get_hcic_reg253(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg254                                                     0x1802A758
#define  LG_HCIC_HCIC_reg254_reg_addr                                            "0xB802A758"
#define  LG_HCIC_HCIC_reg254_reg                                                 0xB802A758
#define  LG_HCIC_HCIC_reg254_inst_addr                                           "0x0096"
#define  set_LG_HCIC_HCIC_reg254_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg254_reg)=data)
#define  get_LG_HCIC_HCIC_reg254_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg254_reg))
#define  LG_HCIC_HCIC_reg254_hcic_reg254_shift                                   (24)
#define  LG_HCIC_HCIC_reg254_hcic_reg255_shift                                   (16)
#define  LG_HCIC_HCIC_reg254_hcic_reg256_shift                                   (8)
#define  LG_HCIC_HCIC_reg254_hcic_reg257_shift                                   (0)
#define  LG_HCIC_HCIC_reg254_hcic_reg254_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg254_hcic_reg255_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg254_hcic_reg256_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg254_hcic_reg257_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg254_hcic_reg254(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg254_hcic_reg255(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg254_hcic_reg256(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg254_hcic_reg257(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg254_get_hcic_reg254(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg254_get_hcic_reg255(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg254_get_hcic_reg256(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg254_get_hcic_reg257(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg258                                                     0x1802A75C
#define  LG_HCIC_HCIC_reg258_reg_addr                                            "0xB802A75C"
#define  LG_HCIC_HCIC_reg258_reg                                                 0xB802A75C
#define  LG_HCIC_HCIC_reg258_inst_addr                                           "0x0097"
#define  set_LG_HCIC_HCIC_reg258_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg258_reg)=data)
#define  get_LG_HCIC_HCIC_reg258_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg258_reg))
#define  LG_HCIC_HCIC_reg258_hcic_reg258_shift                                   (24)
#define  LG_HCIC_HCIC_reg258_hcic_reg259_shift                                   (16)
#define  LG_HCIC_HCIC_reg258_hcic_reg25a_shift                                   (8)
#define  LG_HCIC_HCIC_reg258_hcic_reg25b_shift                                   (0)
#define  LG_HCIC_HCIC_reg258_hcic_reg258_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg258_hcic_reg259_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg258_hcic_reg25a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg258_hcic_reg25b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg258_hcic_reg258(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg258_hcic_reg259(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg258_hcic_reg25a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg258_hcic_reg25b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg258_get_hcic_reg258(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg258_get_hcic_reg259(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg258_get_hcic_reg25a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg258_get_hcic_reg25b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg25c                                                     0x1802A760
#define  LG_HCIC_HCIC_reg25c_reg_addr                                            "0xB802A760"
#define  LG_HCIC_HCIC_reg25c_reg                                                 0xB802A760
#define  LG_HCIC_HCIC_reg25c_inst_addr                                           "0x0098"
#define  set_LG_HCIC_HCIC_reg25c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg25c_reg)=data)
#define  get_LG_HCIC_HCIC_reg25c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg25c_reg))
#define  LG_HCIC_HCIC_reg25c_hcic_reg25c_shift                                   (24)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25d_shift                                   (16)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25e_shift                                   (8)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25f_shift                                   (0)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg25c_hcic_reg25c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg25c_hcic_reg25d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg25c_hcic_reg25e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg25c_hcic_reg25f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg25c_get_hcic_reg25c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg25c_get_hcic_reg25d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg25c_get_hcic_reg25e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg25c_get_hcic_reg25f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg260                                                     0x1802A764
#define  LG_HCIC_HCIC_reg260_reg_addr                                            "0xB802A764"
#define  LG_HCIC_HCIC_reg260_reg                                                 0xB802A764
#define  LG_HCIC_HCIC_reg260_inst_addr                                           "0x0099"
#define  set_LG_HCIC_HCIC_reg260_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg260_reg)=data)
#define  get_LG_HCIC_HCIC_reg260_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg260_reg))
#define  LG_HCIC_HCIC_reg260_hcic_reg260_shift                                   (24)
#define  LG_HCIC_HCIC_reg260_hcic_reg261_shift                                   (16)
#define  LG_HCIC_HCIC_reg260_hcic_reg262_shift                                   (8)
#define  LG_HCIC_HCIC_reg260_hcic_reg263_shift                                   (0)
#define  LG_HCIC_HCIC_reg260_hcic_reg260_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg260_hcic_reg261_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg260_hcic_reg262_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg260_hcic_reg263_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg260_hcic_reg260(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg260_hcic_reg261(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg260_hcic_reg262(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg260_hcic_reg263(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg260_get_hcic_reg260(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg260_get_hcic_reg261(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg260_get_hcic_reg262(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg260_get_hcic_reg263(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg264                                                     0x1802A768
#define  LG_HCIC_HCIC_reg264_reg_addr                                            "0xB802A768"
#define  LG_HCIC_HCIC_reg264_reg                                                 0xB802A768
#define  LG_HCIC_HCIC_reg264_inst_addr                                           "0x009A"
#define  set_LG_HCIC_HCIC_reg264_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg264_reg)=data)
#define  get_LG_HCIC_HCIC_reg264_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg264_reg))
#define  LG_HCIC_HCIC_reg264_hcic_reg264_shift                                   (24)
#define  LG_HCIC_HCIC_reg264_hcic_reg265_shift                                   (16)
#define  LG_HCIC_HCIC_reg264_hcic_reg266_shift                                   (8)
#define  LG_HCIC_HCIC_reg264_hcic_reg267_shift                                   (0)
#define  LG_HCIC_HCIC_reg264_hcic_reg264_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg264_hcic_reg265_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg264_hcic_reg266_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg264_hcic_reg267_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg264_hcic_reg264(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg264_hcic_reg265(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg264_hcic_reg266(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg264_hcic_reg267(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg264_get_hcic_reg264(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg264_get_hcic_reg265(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg264_get_hcic_reg266(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg264_get_hcic_reg267(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg268                                                     0x1802A76C
#define  LG_HCIC_HCIC_reg268_reg_addr                                            "0xB802A76C"
#define  LG_HCIC_HCIC_reg268_reg                                                 0xB802A76C
#define  LG_HCIC_HCIC_reg268_inst_addr                                           "0x009B"
#define  set_LG_HCIC_HCIC_reg268_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg268_reg)=data)
#define  get_LG_HCIC_HCIC_reg268_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg268_reg))
#define  LG_HCIC_HCIC_reg268_hcic_reg268_shift                                   (24)
#define  LG_HCIC_HCIC_reg268_hcic_reg269_shift                                   (16)
#define  LG_HCIC_HCIC_reg268_hcic_reg26a_shift                                   (8)
#define  LG_HCIC_HCIC_reg268_hcic_reg26b_shift                                   (0)
#define  LG_HCIC_HCIC_reg268_hcic_reg268_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg268_hcic_reg269_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg268_hcic_reg26a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg268_hcic_reg26b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg268_hcic_reg268(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg268_hcic_reg269(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg268_hcic_reg26a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg268_hcic_reg26b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg268_get_hcic_reg268(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg268_get_hcic_reg269(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg268_get_hcic_reg26a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg268_get_hcic_reg26b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg26c                                                     0x1802A770
#define  LG_HCIC_HCIC_reg26c_reg_addr                                            "0xB802A770"
#define  LG_HCIC_HCIC_reg26c_reg                                                 0xB802A770
#define  LG_HCIC_HCIC_reg26c_inst_addr                                           "0x009C"
#define  set_LG_HCIC_HCIC_reg26c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg26c_reg)=data)
#define  get_LG_HCIC_HCIC_reg26c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg26c_reg))
#define  LG_HCIC_HCIC_reg26c_hcic_reg26c_shift                                   (24)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26d_shift                                   (16)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26e_shift                                   (8)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26f_shift                                   (0)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg26c_hcic_reg26c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg26c_hcic_reg26d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg26c_hcic_reg26e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg26c_hcic_reg26f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg26c_get_hcic_reg26c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg26c_get_hcic_reg26d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg26c_get_hcic_reg26e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg26c_get_hcic_reg26f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg270                                                     0x1802A774
#define  LG_HCIC_HCIC_reg270_reg_addr                                            "0xB802A774"
#define  LG_HCIC_HCIC_reg270_reg                                                 0xB802A774
#define  LG_HCIC_HCIC_reg270_inst_addr                                           "0x009D"
#define  set_LG_HCIC_HCIC_reg270_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg270_reg)=data)
#define  get_LG_HCIC_HCIC_reg270_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg270_reg))
#define  LG_HCIC_HCIC_reg270_hcic_reg270_shift                                   (24)
#define  LG_HCIC_HCIC_reg270_hcic_reg271_shift                                   (16)
#define  LG_HCIC_HCIC_reg270_hcic_reg272_shift                                   (8)
#define  LG_HCIC_HCIC_reg270_hcic_reg273_shift                                   (0)
#define  LG_HCIC_HCIC_reg270_hcic_reg270_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg270_hcic_reg271_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg270_hcic_reg272_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg270_hcic_reg273_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg270_hcic_reg270(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg270_hcic_reg271(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg270_hcic_reg272(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg270_hcic_reg273(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg270_get_hcic_reg270(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg270_get_hcic_reg271(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg270_get_hcic_reg272(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg270_get_hcic_reg273(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg274                                                     0x1802A778
#define  LG_HCIC_HCIC_reg274_reg_addr                                            "0xB802A778"
#define  LG_HCIC_HCIC_reg274_reg                                                 0xB802A778
#define  LG_HCIC_HCIC_reg274_inst_addr                                           "0x009E"
#define  set_LG_HCIC_HCIC_reg274_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg274_reg)=data)
#define  get_LG_HCIC_HCIC_reg274_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg274_reg))
#define  LG_HCIC_HCIC_reg274_hcic_reg274_shift                                   (24)
#define  LG_HCIC_HCIC_reg274_hcic_reg275_shift                                   (16)
#define  LG_HCIC_HCIC_reg274_hcic_reg276_shift                                   (8)
#define  LG_HCIC_HCIC_reg274_hcic_reg277_shift                                   (0)
#define  LG_HCIC_HCIC_reg274_hcic_reg274_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg274_hcic_reg275_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg274_hcic_reg276_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg274_hcic_reg277_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg274_hcic_reg274(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg274_hcic_reg275(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg274_hcic_reg276(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg274_hcic_reg277(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg274_get_hcic_reg274(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg274_get_hcic_reg275(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg274_get_hcic_reg276(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg274_get_hcic_reg277(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg278                                                     0x1802A77C
#define  LG_HCIC_HCIC_reg278_reg_addr                                            "0xB802A77C"
#define  LG_HCIC_HCIC_reg278_reg                                                 0xB802A77C
#define  LG_HCIC_HCIC_reg278_inst_addr                                           "0x009F"
#define  set_LG_HCIC_HCIC_reg278_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg278_reg)=data)
#define  get_LG_HCIC_HCIC_reg278_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg278_reg))
#define  LG_HCIC_HCIC_reg278_hcic_reg278_shift                                   (24)
#define  LG_HCIC_HCIC_reg278_hcic_reg279_shift                                   (16)
#define  LG_HCIC_HCIC_reg278_hcic_reg27a_shift                                   (8)
#define  LG_HCIC_HCIC_reg278_hcic_reg27b_shift                                   (0)
#define  LG_HCIC_HCIC_reg278_hcic_reg278_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg278_hcic_reg279_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg278_hcic_reg27a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg278_hcic_reg27b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg278_hcic_reg278(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg278_hcic_reg279(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg278_hcic_reg27a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg278_hcic_reg27b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg278_get_hcic_reg278(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg278_get_hcic_reg279(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg278_get_hcic_reg27a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg278_get_hcic_reg27b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg27c                                                     0x1802A780
#define  LG_HCIC_HCIC_reg27c_reg_addr                                            "0xB802A780"
#define  LG_HCIC_HCIC_reg27c_reg                                                 0xB802A780
#define  LG_HCIC_HCIC_reg27c_inst_addr                                           "0x00A0"
#define  set_LG_HCIC_HCIC_reg27c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg27c_reg)=data)
#define  get_LG_HCIC_HCIC_reg27c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg27c_reg))
#define  LG_HCIC_HCIC_reg27c_hcic_reg27c_shift                                   (24)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27d_shift                                   (16)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27e_shift                                   (8)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27f_shift                                   (0)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg27c_hcic_reg27c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg27c_hcic_reg27d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg27c_hcic_reg27e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg27c_hcic_reg27f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg27c_get_hcic_reg27c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg27c_get_hcic_reg27d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg27c_get_hcic_reg27e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg27c_get_hcic_reg27f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg280                                                     0x1802A784
#define  LG_HCIC_HCIC_reg280_reg_addr                                            "0xB802A784"
#define  LG_HCIC_HCIC_reg280_reg                                                 0xB802A784
#define  LG_HCIC_HCIC_reg280_inst_addr                                           "0x00A1"
#define  set_LG_HCIC_HCIC_reg280_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg280_reg)=data)
#define  get_LG_HCIC_HCIC_reg280_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg280_reg))
#define  LG_HCIC_HCIC_reg280_hcic_reg280_shift                                   (24)
#define  LG_HCIC_HCIC_reg280_hcic_reg281_shift                                   (16)
#define  LG_HCIC_HCIC_reg280_hcic_reg282_shift                                   (8)
#define  LG_HCIC_HCIC_reg280_hcic_reg283_shift                                   (0)
#define  LG_HCIC_HCIC_reg280_hcic_reg280_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg280_hcic_reg281_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg280_hcic_reg282_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg280_hcic_reg283_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg280_hcic_reg280(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg280_hcic_reg281(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg280_hcic_reg282(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg280_hcic_reg283(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg280_get_hcic_reg280(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg280_get_hcic_reg281(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg280_get_hcic_reg282(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg280_get_hcic_reg283(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg284                                                     0x1802A788
#define  LG_HCIC_HCIC_reg284_reg_addr                                            "0xB802A788"
#define  LG_HCIC_HCIC_reg284_reg                                                 0xB802A788
#define  LG_HCIC_HCIC_reg284_inst_addr                                           "0x00A2"
#define  set_LG_HCIC_HCIC_reg284_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg284_reg)=data)
#define  get_LG_HCIC_HCIC_reg284_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg284_reg))
#define  LG_HCIC_HCIC_reg284_hcic_reg284_shift                                   (24)
#define  LG_HCIC_HCIC_reg284_hcic_reg285_shift                                   (16)
#define  LG_HCIC_HCIC_reg284_hcic_reg286_shift                                   (8)
#define  LG_HCIC_HCIC_reg284_hcic_reg287_shift                                   (0)
#define  LG_HCIC_HCIC_reg284_hcic_reg284_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg284_hcic_reg285_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg284_hcic_reg286_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg284_hcic_reg287_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg284_hcic_reg284(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg284_hcic_reg285(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg284_hcic_reg286(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg284_hcic_reg287(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg284_get_hcic_reg284(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg284_get_hcic_reg285(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg284_get_hcic_reg286(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg284_get_hcic_reg287(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg288                                                     0x1802A78C
#define  LG_HCIC_HCIC_reg288_reg_addr                                            "0xB802A78C"
#define  LG_HCIC_HCIC_reg288_reg                                                 0xB802A78C
#define  LG_HCIC_HCIC_reg288_inst_addr                                           "0x00A3"
#define  set_LG_HCIC_HCIC_reg288_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg288_reg)=data)
#define  get_LG_HCIC_HCIC_reg288_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg288_reg))
#define  LG_HCIC_HCIC_reg288_hcic_reg288_shift                                   (24)
#define  LG_HCIC_HCIC_reg288_hcic_reg289_shift                                   (16)
#define  LG_HCIC_HCIC_reg288_hcic_reg28a_shift                                   (8)
#define  LG_HCIC_HCIC_reg288_hcic_reg28b_shift                                   (0)
#define  LG_HCIC_HCIC_reg288_hcic_reg288_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg288_hcic_reg289_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg288_hcic_reg28a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg288_hcic_reg28b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg288_hcic_reg288(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg288_hcic_reg289(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg288_hcic_reg28a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg288_hcic_reg28b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg288_get_hcic_reg288(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg288_get_hcic_reg289(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg288_get_hcic_reg28a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg288_get_hcic_reg28b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg28c                                                     0x1802A790
#define  LG_HCIC_HCIC_reg28c_reg_addr                                            "0xB802A790"
#define  LG_HCIC_HCIC_reg28c_reg                                                 0xB802A790
#define  LG_HCIC_HCIC_reg28c_inst_addr                                           "0x00A4"
#define  set_LG_HCIC_HCIC_reg28c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg28c_reg)=data)
#define  get_LG_HCIC_HCIC_reg28c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg28c_reg))
#define  LG_HCIC_HCIC_reg28c_hcic_reg28c_shift                                   (24)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28d_shift                                   (16)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28e_shift                                   (8)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28f_shift                                   (0)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg28c_hcic_reg28c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg28c_hcic_reg28d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg28c_hcic_reg28e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg28c_hcic_reg28f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg28c_get_hcic_reg28c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg28c_get_hcic_reg28d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg28c_get_hcic_reg28e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg28c_get_hcic_reg28f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg290                                                     0x1802A794
#define  LG_HCIC_HCIC_reg290_reg_addr                                            "0xB802A794"
#define  LG_HCIC_HCIC_reg290_reg                                                 0xB802A794
#define  LG_HCIC_HCIC_reg290_inst_addr                                           "0x00A5"
#define  set_LG_HCIC_HCIC_reg290_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg290_reg)=data)
#define  get_LG_HCIC_HCIC_reg290_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg290_reg))
#define  LG_HCIC_HCIC_reg290_hcic_reg290_shift                                   (24)
#define  LG_HCIC_HCIC_reg290_hcic_reg291_shift                                   (16)
#define  LG_HCIC_HCIC_reg290_hcic_reg292_shift                                   (8)
#define  LG_HCIC_HCIC_reg290_hcic_reg293_shift                                   (0)
#define  LG_HCIC_HCIC_reg290_hcic_reg290_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg290_hcic_reg291_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg290_hcic_reg292_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg290_hcic_reg293_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg290_hcic_reg290(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg290_hcic_reg291(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg290_hcic_reg292(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg290_hcic_reg293(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg290_get_hcic_reg290(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg290_get_hcic_reg291(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg290_get_hcic_reg292(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg290_get_hcic_reg293(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg294                                                     0x1802A798
#define  LG_HCIC_HCIC_reg294_reg_addr                                            "0xB802A798"
#define  LG_HCIC_HCIC_reg294_reg                                                 0xB802A798
#define  LG_HCIC_HCIC_reg294_inst_addr                                           "0x00A6"
#define  set_LG_HCIC_HCIC_reg294_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg294_reg)=data)
#define  get_LG_HCIC_HCIC_reg294_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg294_reg))
#define  LG_HCIC_HCIC_reg294_hcic_reg294_shift                                   (24)
#define  LG_HCIC_HCIC_reg294_hcic_reg295_shift                                   (16)
#define  LG_HCIC_HCIC_reg294_hcic_reg296_shift                                   (8)
#define  LG_HCIC_HCIC_reg294_hcic_reg297_shift                                   (0)
#define  LG_HCIC_HCIC_reg294_hcic_reg294_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg294_hcic_reg295_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg294_hcic_reg296_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg294_hcic_reg297_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg294_hcic_reg294(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg294_hcic_reg295(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg294_hcic_reg296(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg294_hcic_reg297(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg294_get_hcic_reg294(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg294_get_hcic_reg295(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg294_get_hcic_reg296(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg294_get_hcic_reg297(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg298                                                     0x1802A79C
#define  LG_HCIC_HCIC_reg298_reg_addr                                            "0xB802A79C"
#define  LG_HCIC_HCIC_reg298_reg                                                 0xB802A79C
#define  LG_HCIC_HCIC_reg298_inst_addr                                           "0x00A7"
#define  set_LG_HCIC_HCIC_reg298_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg298_reg)=data)
#define  get_LG_HCIC_HCIC_reg298_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg298_reg))
#define  LG_HCIC_HCIC_reg298_hcic_reg298_shift                                   (24)
#define  LG_HCIC_HCIC_reg298_hcic_reg299_shift                                   (16)
#define  LG_HCIC_HCIC_reg298_hcic_reg29a_shift                                   (8)
#define  LG_HCIC_HCIC_reg298_hcic_reg29b_shift                                   (0)
#define  LG_HCIC_HCIC_reg298_hcic_reg298_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg298_hcic_reg299_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg298_hcic_reg29a_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg298_hcic_reg29b_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg298_hcic_reg298(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg298_hcic_reg299(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg298_hcic_reg29a(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg298_hcic_reg29b(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg298_get_hcic_reg298(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg298_get_hcic_reg299(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg298_get_hcic_reg29a(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg298_get_hcic_reg29b(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg29c                                                     0x1802A7A0
#define  LG_HCIC_HCIC_reg29c_reg_addr                                            "0xB802A7A0"
#define  LG_HCIC_HCIC_reg29c_reg                                                 0xB802A7A0
#define  LG_HCIC_HCIC_reg29c_inst_addr                                           "0x00A8"
#define  set_LG_HCIC_HCIC_reg29c_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg29c_reg)=data)
#define  get_LG_HCIC_HCIC_reg29c_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg29c_reg))
#define  LG_HCIC_HCIC_reg29c_hcic_reg29c_shift                                   (24)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29d_shift                                   (16)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29e_shift                                   (8)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29f_shift                                   (0)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29c_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29d_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29e_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29f_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg29c_hcic_reg29c(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg29c_hcic_reg29d(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg29c_hcic_reg29e(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg29c_hcic_reg29f(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg29c_get_hcic_reg29c(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg29c_get_hcic_reg29d(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg29c_get_hcic_reg29e(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg29c_get_hcic_reg29f(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2a0                                                     0x1802A7A4
#define  LG_HCIC_HCIC_reg2a0_reg_addr                                            "0xB802A7A4"
#define  LG_HCIC_HCIC_reg2a0_reg                                                 0xB802A7A4
#define  LG_HCIC_HCIC_reg2a0_inst_addr                                           "0x00A9"
#define  set_LG_HCIC_HCIC_reg2a0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2a0_reg)=data)
#define  get_LG_HCIC_HCIC_reg2a0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2a0_reg))
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a0_shift                                   (24)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a1_shift                                   (16)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a2_shift                                   (8)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a3_shift                                   (0)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2a0_hcic_reg2a3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2a0_get_hcic_reg2a0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2a0_get_hcic_reg2a1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2a0_get_hcic_reg2a2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2a0_get_hcic_reg2a3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2a4                                                     0x1802A7A8
#define  LG_HCIC_HCIC_reg2a4_reg_addr                                            "0xB802A7A8"
#define  LG_HCIC_HCIC_reg2a4_reg                                                 0xB802A7A8
#define  LG_HCIC_HCIC_reg2a4_inst_addr                                           "0x00AA"
#define  set_LG_HCIC_HCIC_reg2a4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2a4_reg)=data)
#define  get_LG_HCIC_HCIC_reg2a4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2a4_reg))
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a4_shift                                   (24)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a5_shift                                   (16)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a6_shift                                   (8)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a7_shift                                   (0)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2a4_hcic_reg2a7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2a4_get_hcic_reg2a4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2a4_get_hcic_reg2a5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2a4_get_hcic_reg2a6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2a4_get_hcic_reg2a7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2a8                                                     0x1802A7AC
#define  LG_HCIC_HCIC_reg2a8_reg_addr                                            "0xB802A7AC"
#define  LG_HCIC_HCIC_reg2a8_reg                                                 0xB802A7AC
#define  LG_HCIC_HCIC_reg2a8_inst_addr                                           "0x00AB"
#define  set_LG_HCIC_HCIC_reg2a8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2a8_reg)=data)
#define  get_LG_HCIC_HCIC_reg2a8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2a8_reg))
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2a8_shift                                   (24)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2a9_shift                                   (16)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2aa_shift                                   (8)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2ab_shift                                   (0)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2a8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2a9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2aa_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2ab_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2a8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2a9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2aa(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2a8_hcic_reg2ab(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2a8_get_hcic_reg2a8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2a8_get_hcic_reg2a9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2a8_get_hcic_reg2aa(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2a8_get_hcic_reg2ab(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2ac                                                     0x1802A7B0
#define  LG_HCIC_HCIC_reg2ac_reg_addr                                            "0xB802A7B0"
#define  LG_HCIC_HCIC_reg2ac_reg                                                 0xB802A7B0
#define  LG_HCIC_HCIC_reg2ac_inst_addr                                           "0x00AC"
#define  set_LG_HCIC_HCIC_reg2ac_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2ac_reg)=data)
#define  get_LG_HCIC_HCIC_reg2ac_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2ac_reg))
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ac_shift                                   (24)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ad_shift                                   (16)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ae_shift                                   (8)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2af_shift                                   (0)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ac_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ad_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ae_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2af_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ac(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ad(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2ae(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2ac_hcic_reg2af(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2ac_get_hcic_reg2ac(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2ac_get_hcic_reg2ad(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2ac_get_hcic_reg2ae(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2ac_get_hcic_reg2af(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2b0                                                     0x1802A7B4
#define  LG_HCIC_HCIC_reg2b0_reg_addr                                            "0xB802A7B4"
#define  LG_HCIC_HCIC_reg2b0_reg                                                 0xB802A7B4
#define  LG_HCIC_HCIC_reg2b0_inst_addr                                           "0x00AD"
#define  set_LG_HCIC_HCIC_reg2b0_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2b0_reg)=data)
#define  get_LG_HCIC_HCIC_reg2b0_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2b0_reg))
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b0_shift                                   (24)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b1_shift                                   (16)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b2_shift                                   (8)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b3_shift                                   (0)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b0_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b1_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b2_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b3_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b0(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b1(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b2(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2b0_hcic_reg2b3(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2b0_get_hcic_reg2b0(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2b0_get_hcic_reg2b1(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2b0_get_hcic_reg2b2(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2b0_get_hcic_reg2b3(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2b4                                                     0x1802A7B8
#define  LG_HCIC_HCIC_reg2b4_reg_addr                                            "0xB802A7B8"
#define  LG_HCIC_HCIC_reg2b4_reg                                                 0xB802A7B8
#define  LG_HCIC_HCIC_reg2b4_inst_addr                                           "0x00AE"
#define  set_LG_HCIC_HCIC_reg2b4_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2b4_reg)=data)
#define  get_LG_HCIC_HCIC_reg2b4_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2b4_reg))
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b4_shift                                   (24)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b5_shift                                   (16)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b6_shift                                   (8)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b7_shift                                   (0)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b4_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b5_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b6_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b7_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b4(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b5(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b6(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2b4_hcic_reg2b7(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2b4_get_hcic_reg2b4(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2b4_get_hcic_reg2b5(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2b4_get_hcic_reg2b6(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2b4_get_hcic_reg2b7(data)                               (0x000000FF&(data))

#define  LG_HCIC_HCIC_reg2b8                                                     0x1802A7BC
#define  LG_HCIC_HCIC_reg2b8_reg_addr                                            "0xB802A7BC"
#define  LG_HCIC_HCIC_reg2b8_reg                                                 0xB802A7BC
#define  LG_HCIC_HCIC_reg2b8_inst_addr                                           "0x00AF"
#define  set_LG_HCIC_HCIC_reg2b8_reg(data)                                       (*((volatile unsigned int*)LG_HCIC_HCIC_reg2b8_reg)=data)
#define  get_LG_HCIC_HCIC_reg2b8_reg                                             (*((volatile unsigned int*)LG_HCIC_HCIC_reg2b8_reg))
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2b8_shift                                   (24)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2b9_shift                                   (16)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2ba_shift                                   (8)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2bb_shift                                   (0)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2b8_mask                                    (0xFF000000)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2b9_mask                                    (0x00FF0000)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2ba_mask                                    (0x0000FF00)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2bb_mask                                    (0x000000FF)
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2b8(data)                                   (0xFF000000&((data)<<24))
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2b9(data)                                   (0x00FF0000&((data)<<16))
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2ba(data)                                   (0x0000FF00&((data)<<8))
#define  LG_HCIC_HCIC_reg2b8_hcic_reg2bb(data)                                   (0x000000FF&(data))
#define  LG_HCIC_HCIC_reg2b8_get_hcic_reg2b8(data)                               ((0xFF000000&(data))>>24)
#define  LG_HCIC_HCIC_reg2b8_get_hcic_reg2b9(data)                               ((0x00FF0000&(data))>>16)
#define  LG_HCIC_HCIC_reg2b8_get_hcic_reg2ba(data)                               ((0x0000FF00&(data))>>8)
#define  LG_HCIC_HCIC_reg2b8_get_hcic_reg2bb(data)                               (0x000000FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LG_HCIC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  user_timing_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  auto_detect_result:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  auto_detect_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  frcon:1;
        RBus_UInt32  reverse:1;
    };
}lg_hcic_hcic_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg000:8;
        RBus_UInt32  hcic_reg001:8;
        RBus_UInt32  hcic_reg002:8;
        RBus_UInt32  hcic_reg003:8;
    };
}lg_hcic_hcic_reg000_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg004:8;
        RBus_UInt32  hcic_reg005:8;
        RBus_UInt32  hcic_reg006:8;
        RBus_UInt32  hcic_reg007:8;
    };
}lg_hcic_hcic_reg004_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg008:8;
        RBus_UInt32  hcic_reg009:8;
        RBus_UInt32  hcic_reg00a:8;
        RBus_UInt32  hcic_reg00b:8;
    };
}lg_hcic_hcic_reg008_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg00c:8;
        RBus_UInt32  hcic_reg00d:8;
        RBus_UInt32  hcic_reg00e:8;
        RBus_UInt32  hcic_reg00f:8;
    };
}lg_hcic_hcic_reg00c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg010:8;
        RBus_UInt32  hcic_reg011:8;
        RBus_UInt32  hcic_reg012:8;
        RBus_UInt32  hcic_reg013:8;
    };
}lg_hcic_hcic_reg010_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg014:8;
        RBus_UInt32  hcic_reg015:8;
        RBus_UInt32  hcic_reg016:8;
        RBus_UInt32  hcic_reg017:8;
    };
}lg_hcic_hcic_reg014_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg018:8;
        RBus_UInt32  hcic_reg019:8;
        RBus_UInt32  hcic_reg01a:8;
        RBus_UInt32  hcic_reg01b:8;
    };
}lg_hcic_hcic_reg018_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg01c:8;
        RBus_UInt32  hcic_reg01d:8;
        RBus_UInt32  hcic_reg01e:8;
        RBus_UInt32  hcic_reg01f:8;
    };
}lg_hcic_hcic_reg01c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg020:8;
        RBus_UInt32  hcic_reg021:8;
        RBus_UInt32  hcic_reg022:8;
        RBus_UInt32  hcic_reg023:8;
    };
}lg_hcic_hcic_reg020_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg024:8;
        RBus_UInt32  hcic_reg025:8;
        RBus_UInt32  hcic_reg026:8;
        RBus_UInt32  hcic_reg027:8;
    };
}lg_hcic_hcic_reg024_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg028:8;
        RBus_UInt32  hcic_reg029:8;
        RBus_UInt32  hcic_reg02a:8;
        RBus_UInt32  hcic_reg02b:8;
    };
}lg_hcic_hcic_reg028_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg02c:8;
        RBus_UInt32  hcic_reg02d:8;
        RBus_UInt32  hcic_reg02e:8;
        RBus_UInt32  hcic_reg02f:8;
    };
}lg_hcic_hcic_reg02c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg030:8;
        RBus_UInt32  hcic_reg031:8;
        RBus_UInt32  hcic_reg032:8;
        RBus_UInt32  hcic_reg033:8;
    };
}lg_hcic_hcic_reg030_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg034:8;
        RBus_UInt32  hcic_reg035:8;
        RBus_UInt32  hcic_reg036:8;
        RBus_UInt32  hcic_reg037:8;
    };
}lg_hcic_hcic_reg034_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg038:8;
        RBus_UInt32  hcic_reg039:8;
        RBus_UInt32  hcic_reg03a:8;
        RBus_UInt32  hcic_reg03b:8;
    };
}lg_hcic_hcic_reg038_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg03c:8;
        RBus_UInt32  hcic_reg03d:8;
        RBus_UInt32  hcic_reg03e:8;
        RBus_UInt32  hcic_reg03f:8;
    };
}lg_hcic_hcic_reg03c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg040:8;
        RBus_UInt32  hcic_reg041:8;
        RBus_UInt32  hcic_reg042:8;
        RBus_UInt32  hcic_reg043:8;
    };
}lg_hcic_hcic_reg040_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg044:8;
        RBus_UInt32  hcic_reg045:8;
        RBus_UInt32  hcic_reg046:8;
        RBus_UInt32  hcic_reg047:8;
    };
}lg_hcic_hcic_reg044_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg048:8;
        RBus_UInt32  hcic_reg049:8;
        RBus_UInt32  hcic_reg04a:8;
        RBus_UInt32  hcic_reg04b:8;
    };
}lg_hcic_hcic_reg048_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg04c:8;
        RBus_UInt32  hcic_reg04d:8;
        RBus_UInt32  hcic_reg04e:8;
        RBus_UInt32  hcic_reg04f:8;
    };
}lg_hcic_hcic_reg04c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg050:8;
        RBus_UInt32  hcic_reg051:8;
        RBus_UInt32  hcic_reg052:8;
        RBus_UInt32  hcic_reg053:8;
    };
}lg_hcic_hcic_reg050_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg054:8;
        RBus_UInt32  hcic_reg055:8;
        RBus_UInt32  hcic_reg056:8;
        RBus_UInt32  hcic_reg057:8;
    };
}lg_hcic_hcic_reg054_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg058:8;
        RBus_UInt32  hcic_reg059:8;
        RBus_UInt32  hcic_reg05a:8;
        RBus_UInt32  hcic_reg05b:8;
    };
}lg_hcic_hcic_reg058_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg05c:8;
        RBus_UInt32  hcic_reg05d:8;
        RBus_UInt32  hcic_reg05e:8;
        RBus_UInt32  hcic_reg05f:8;
    };
}lg_hcic_hcic_reg05c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg060:8;
        RBus_UInt32  hcic_reg061:8;
        RBus_UInt32  hcic_reg062:8;
        RBus_UInt32  hcic_reg063:8;
    };
}lg_hcic_hcic_reg060_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg064:8;
        RBus_UInt32  hcic_reg065:8;
        RBus_UInt32  hcic_reg066:8;
        RBus_UInt32  hcic_reg067:8;
    };
}lg_hcic_hcic_reg064_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg068:8;
        RBus_UInt32  hcic_reg069:8;
        RBus_UInt32  hcic_reg06a:8;
        RBus_UInt32  hcic_reg06b:8;
    };
}lg_hcic_hcic_reg068_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg06c:8;
        RBus_UInt32  hcic_reg06d:8;
        RBus_UInt32  hcic_reg06e:8;
        RBus_UInt32  hcic_reg06f:8;
    };
}lg_hcic_hcic_reg06c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg070:8;
        RBus_UInt32  hcic_reg071:8;
        RBus_UInt32  hcic_reg072:8;
        RBus_UInt32  hcic_reg073:8;
    };
}lg_hcic_hcic_reg070_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg074:8;
        RBus_UInt32  hcic_reg075:8;
        RBus_UInt32  hcic_reg076:8;
        RBus_UInt32  hcic_reg077:8;
    };
}lg_hcic_hcic_reg074_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg078:8;
        RBus_UInt32  hcic_reg079:8;
        RBus_UInt32  hcic_reg07a:8;
        RBus_UInt32  hcic_reg07b:8;
    };
}lg_hcic_hcic_reg078_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg07c:8;
        RBus_UInt32  hcic_reg07d:8;
        RBus_UInt32  hcic_reg07e:8;
        RBus_UInt32  hcic_reg07f:8;
    };
}lg_hcic_hcic_reg07c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg080:8;
        RBus_UInt32  hcic_reg081:8;
        RBus_UInt32  hcic_reg082:8;
        RBus_UInt32  hcic_reg083:8;
    };
}lg_hcic_hcic_reg080_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg084:8;
        RBus_UInt32  hcic_reg085:8;
        RBus_UInt32  hcic_reg086:8;
        RBus_UInt32  hcic_reg087:8;
    };
}lg_hcic_hcic_reg084_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg088:8;
        RBus_UInt32  hcic_reg089:8;
        RBus_UInt32  hcic_reg08a:8;
        RBus_UInt32  hcic_reg08b:8;
    };
}lg_hcic_hcic_reg088_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg08c:8;
        RBus_UInt32  hcic_reg08d:8;
        RBus_UInt32  hcic_reg08e:8;
        RBus_UInt32  hcic_reg08f:8;
    };
}lg_hcic_hcic_reg08c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg090:8;
        RBus_UInt32  hcic_reg091:8;
        RBus_UInt32  hcic_reg092:8;
        RBus_UInt32  hcic_reg093:8;
    };
}lg_hcic_hcic_reg090_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg094:8;
        RBus_UInt32  hcic_reg095:8;
        RBus_UInt32  hcic_reg096:8;
        RBus_UInt32  hcic_reg097:8;
    };
}lg_hcic_hcic_reg094_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg098:8;
        RBus_UInt32  hcic_reg099:8;
        RBus_UInt32  hcic_reg09a:8;
        RBus_UInt32  hcic_reg09b:8;
    };
}lg_hcic_hcic_reg098_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg09c:8;
        RBus_UInt32  hcic_reg09d:8;
        RBus_UInt32  hcic_reg09e:8;
        RBus_UInt32  hcic_reg09f:8;
    };
}lg_hcic_hcic_reg09c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0a0:8;
        RBus_UInt32  hcic_reg0a1:8;
        RBus_UInt32  hcic_reg0a2:8;
        RBus_UInt32  hcic_reg0a3:8;
    };
}lg_hcic_hcic_reg0a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0a4:8;
        RBus_UInt32  hcic_reg0a5:8;
        RBus_UInt32  hcic_reg0a6:8;
        RBus_UInt32  hcic_reg0a7:8;
    };
}lg_hcic_hcic_reg0a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0a8:8;
        RBus_UInt32  hcic_reg0a9:8;
        RBus_UInt32  hcic_reg0aa:8;
        RBus_UInt32  hcic_reg0ab:8;
    };
}lg_hcic_hcic_reg0a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0ac:8;
        RBus_UInt32  hcic_reg0ad:8;
        RBus_UInt32  hcic_reg0ae:8;
        RBus_UInt32  hcic_reg0af:8;
    };
}lg_hcic_hcic_reg0ac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0b0:8;
        RBus_UInt32  hcic_reg0b1:8;
        RBus_UInt32  hcic_reg0b2:8;
        RBus_UInt32  hcic_reg0b3:8;
    };
}lg_hcic_hcic_reg0b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0b4:8;
        RBus_UInt32  hcic_reg0b5:8;
        RBus_UInt32  hcic_reg0b6:8;
        RBus_UInt32  hcic_reg0b7:8;
    };
}lg_hcic_hcic_reg0b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0b8:8;
        RBus_UInt32  hcic_reg0b9:8;
        RBus_UInt32  hcic_reg0ba:8;
        RBus_UInt32  hcic_reg0bb:8;
    };
}lg_hcic_hcic_reg0b8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0bc:8;
        RBus_UInt32  hcic_reg0bd:8;
        RBus_UInt32  hcic_reg0be:8;
        RBus_UInt32  hcic_reg0bf:8;
    };
}lg_hcic_hcic_reg0bc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0c0:8;
        RBus_UInt32  hcic_reg0c1:8;
        RBus_UInt32  hcic_reg0c2:8;
        RBus_UInt32  hcic_reg0c3:8;
    };
}lg_hcic_hcic_reg0c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0c4:8;
        RBus_UInt32  hcic_reg0c5:8;
        RBus_UInt32  hcic_reg0c6:8;
        RBus_UInt32  hcic_reg0c7:8;
    };
}lg_hcic_hcic_reg0c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0c8:8;
        RBus_UInt32  hcic_reg0c9:8;
        RBus_UInt32  hcic_reg0ca:8;
        RBus_UInt32  hcic_reg0cb:8;
    };
}lg_hcic_hcic_reg0c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0cc:8;
        RBus_UInt32  hcic_reg0cd:8;
        RBus_UInt32  hcic_reg0ce:8;
        RBus_UInt32  hcic_reg0cf:8;
    };
}lg_hcic_hcic_reg0cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0d0:8;
        RBus_UInt32  hcic_reg0d1:8;
        RBus_UInt32  hcic_reg0d2:8;
        RBus_UInt32  hcic_reg0d3:8;
    };
}lg_hcic_hcic_reg0d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0d4:8;
        RBus_UInt32  hcic_reg0d5:8;
        RBus_UInt32  hcic_reg0d6:8;
        RBus_UInt32  hcic_reg0d7:8;
    };
}lg_hcic_hcic_reg0d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0d8:8;
        RBus_UInt32  hcic_reg0d9:8;
        RBus_UInt32  hcic_reg0da:8;
        RBus_UInt32  hcic_reg0db:8;
    };
}lg_hcic_hcic_reg0d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0dc:8;
        RBus_UInt32  hcic_reg0dd:8;
        RBus_UInt32  hcic_reg0de:8;
        RBus_UInt32  hcic_reg0df:8;
    };
}lg_hcic_hcic_reg0dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0e0:8;
        RBus_UInt32  hcic_reg0e1:8;
        RBus_UInt32  hcic_reg0e2:8;
        RBus_UInt32  hcic_reg0e3:8;
    };
}lg_hcic_hcic_reg0e0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0e4:8;
        RBus_UInt32  hcic_reg0e5:8;
        RBus_UInt32  hcic_reg0e6:8;
        RBus_UInt32  hcic_reg0e7:8;
    };
}lg_hcic_hcic_reg0e4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0e8:8;
        RBus_UInt32  hcic_reg0e9:8;
        RBus_UInt32  hcic_reg0ea:8;
        RBus_UInt32  hcic_reg0eb:8;
    };
}lg_hcic_hcic_reg0e8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0ec:8;
        RBus_UInt32  hcic_reg0ed:8;
        RBus_UInt32  hcic_reg0ee:8;
        RBus_UInt32  hcic_reg0ef:8;
    };
}lg_hcic_hcic_reg0ec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0f0:8;
        RBus_UInt32  hcic_reg0f1:8;
        RBus_UInt32  hcic_reg0f2:8;
        RBus_UInt32  hcic_reg0f3:8;
    };
}lg_hcic_hcic_reg0f0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0f4:8;
        RBus_UInt32  hcic_reg0f5:8;
        RBus_UInt32  hcic_reg0f6:8;
        RBus_UInt32  hcic_reg0f7:8;
    };
}lg_hcic_hcic_reg0f4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0f8:8;
        RBus_UInt32  hcic_reg0f9:8;
        RBus_UInt32  hcic_reg0fa:8;
        RBus_UInt32  hcic_reg0fb:8;
    };
}lg_hcic_hcic_reg0f8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0fc:8;
        RBus_UInt32  hcic_reg0fd:8;
        RBus_UInt32  hcic_reg0fe:8;
        RBus_UInt32  hcic_reg0ff:8;
    };
}lg_hcic_hcic_reg0fc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg100:8;
        RBus_UInt32  hcic_reg101:8;
        RBus_UInt32  hcic_reg102:8;
        RBus_UInt32  hcic_reg103:8;
    };
}lg_hcic_hcic_reg100_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg104:8;
        RBus_UInt32  hcic_reg105:8;
        RBus_UInt32  hcic_reg106:8;
        RBus_UInt32  hcic_reg107:8;
    };
}lg_hcic_hcic_reg104_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg108:8;
        RBus_UInt32  hcic_reg109:8;
        RBus_UInt32  hcic_reg10a:8;
        RBus_UInt32  hcic_reg10b:8;
    };
}lg_hcic_hcic_reg108_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg10c:8;
        RBus_UInt32  hcic_reg10d:8;
        RBus_UInt32  hcic_reg10e:8;
        RBus_UInt32  hcic_reg10f:8;
    };
}lg_hcic_hcic_reg10c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg110:8;
        RBus_UInt32  hcic_reg111:8;
        RBus_UInt32  hcic_reg112:8;
        RBus_UInt32  hcic_reg113:8;
    };
}lg_hcic_hcic_reg110_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg114:8;
        RBus_UInt32  hcic_reg115:8;
        RBus_UInt32  hcic_reg116:8;
        RBus_UInt32  hcic_reg117:8;
    };
}lg_hcic_hcic_reg114_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg118:8;
        RBus_UInt32  hcic_reg119:8;
        RBus_UInt32  hcic_reg11a:8;
        RBus_UInt32  hcic_reg11b:8;
    };
}lg_hcic_hcic_reg118_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg11c:8;
        RBus_UInt32  hcic_reg11d:8;
        RBus_UInt32  hcic_reg11e:8;
        RBus_UInt32  hcic_reg11f:8;
    };
}lg_hcic_hcic_reg11c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg120:8;
        RBus_UInt32  hcic_reg121:8;
        RBus_UInt32  hcic_reg122:8;
        RBus_UInt32  hcic_reg123:8;
    };
}lg_hcic_hcic_reg120_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg124:8;
        RBus_UInt32  hcic_reg125:8;
        RBus_UInt32  hcic_reg126:8;
        RBus_UInt32  hcic_reg127:8;
    };
}lg_hcic_hcic_reg124_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg128:8;
        RBus_UInt32  hcic_reg129:8;
        RBus_UInt32  hcic_reg12a:8;
        RBus_UInt32  hcic_reg12b:8;
    };
}lg_hcic_hcic_reg128_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg12c:8;
        RBus_UInt32  hcic_reg12d:8;
        RBus_UInt32  hcic_reg12e:8;
        RBus_UInt32  hcic_reg12f:8;
    };
}lg_hcic_hcic_reg12c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg130:8;
        RBus_UInt32  hcic_reg131:8;
        RBus_UInt32  hcic_reg132:8;
        RBus_UInt32  hcic_reg133:8;
    };
}lg_hcic_hcic_reg130_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg134:8;
        RBus_UInt32  hcic_reg135:8;
        RBus_UInt32  hcic_reg136:8;
        RBus_UInt32  hcic_reg137:8;
    };
}lg_hcic_hcic_reg134_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg138:8;
        RBus_UInt32  hcic_reg139:8;
        RBus_UInt32  hcic_reg13a:8;
        RBus_UInt32  hcic_reg13b:8;
    };
}lg_hcic_hcic_reg138_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg13c:8;
        RBus_UInt32  hcic_reg13d:8;
        RBus_UInt32  hcic_reg13e:8;
        RBus_UInt32  hcic_reg13f:8;
    };
}lg_hcic_hcic_reg13c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg140:8;
        RBus_UInt32  hcic_reg141:8;
        RBus_UInt32  hcic_reg142:8;
        RBus_UInt32  hcic_reg143:8;
    };
}lg_hcic_hcic_reg140_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg144:8;
        RBus_UInt32  hcic_reg145:8;
        RBus_UInt32  hcic_reg146:8;
        RBus_UInt32  hcic_reg147:8;
    };
}lg_hcic_hcic_reg144_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg148:8;
        RBus_UInt32  hcic_reg149:8;
        RBus_UInt32  hcic_reg14a:8;
        RBus_UInt32  hcic_reg14b:8;
    };
}lg_hcic_hcic_reg148_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg14c:8;
        RBus_UInt32  hcic_reg14d:8;
        RBus_UInt32  hcic_reg14e:8;
        RBus_UInt32  hcic_reg14f:8;
    };
}lg_hcic_hcic_reg14c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg150:8;
        RBus_UInt32  hcic_reg151:8;
        RBus_UInt32  hcic_reg152:8;
        RBus_UInt32  hcic_reg153:8;
    };
}lg_hcic_hcic_reg150_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg154:8;
        RBus_UInt32  hcic_reg155:8;
        RBus_UInt32  hcic_reg156:8;
        RBus_UInt32  hcic_reg157:8;
    };
}lg_hcic_hcic_reg154_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg158:8;
        RBus_UInt32  hcic_reg159:8;
        RBus_UInt32  hcic_reg15a:8;
        RBus_UInt32  hcic_reg15b:8;
    };
}lg_hcic_hcic_reg158_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg15c:8;
        RBus_UInt32  hcic_reg15d:8;
        RBus_UInt32  hcic_reg15e:8;
        RBus_UInt32  hcic_reg15f:8;
    };
}lg_hcic_hcic_reg15c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg160:8;
        RBus_UInt32  hcic_reg161:8;
        RBus_UInt32  hcic_reg162:8;
        RBus_UInt32  hcic_reg163:8;
    };
}lg_hcic_hcic_reg160_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg164:8;
        RBus_UInt32  hcic_reg165:8;
        RBus_UInt32  hcic_reg166:8;
        RBus_UInt32  hcic_reg167:8;
    };
}lg_hcic_hcic_reg164_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg168:8;
        RBus_UInt32  hcic_reg169:8;
        RBus_UInt32  hcic_reg16a:8;
        RBus_UInt32  hcic_reg16b:8;
    };
}lg_hcic_hcic_reg168_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg16c:8;
        RBus_UInt32  hcic_reg16d:8;
        RBus_UInt32  hcic_reg16e:8;
        RBus_UInt32  hcic_reg16f:8;
    };
}lg_hcic_hcic_reg16c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg170:8;
        RBus_UInt32  hcic_reg171:8;
        RBus_UInt32  hcic_reg172:8;
        RBus_UInt32  hcic_reg173:8;
    };
}lg_hcic_hcic_reg170_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg174:8;
        RBus_UInt32  hcic_reg175:8;
        RBus_UInt32  hcic_reg176:8;
        RBus_UInt32  hcic_reg177:8;
    };
}lg_hcic_hcic_reg174_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg178:8;
        RBus_UInt32  hcic_reg179:8;
        RBus_UInt32  hcic_reg17a:8;
        RBus_UInt32  hcic_reg17b:8;
    };
}lg_hcic_hcic_reg178_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg17c:8;
        RBus_UInt32  hcic_reg17d:8;
        RBus_UInt32  hcic_reg17e:8;
        RBus_UInt32  hcic_reg17f:8;
    };
}lg_hcic_hcic_reg17c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg180:8;
        RBus_UInt32  hcic_reg181:8;
        RBus_UInt32  hcic_reg182:8;
        RBus_UInt32  hcic_reg183:8;
    };
}lg_hcic_hcic_reg180_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg184:8;
        RBus_UInt32  hcic_reg185:8;
        RBus_UInt32  hcic_reg186:8;
        RBus_UInt32  hcic_reg187:8;
    };
}lg_hcic_hcic_reg184_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg188:8;
        RBus_UInt32  hcic_reg189:8;
        RBus_UInt32  hcic_reg18a:8;
        RBus_UInt32  hcic_reg18b:8;
    };
}lg_hcic_hcic_reg188_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg18c:8;
        RBus_UInt32  hcic_reg18d:8;
        RBus_UInt32  hcic_reg18e:8;
        RBus_UInt32  hcic_reg18f:8;
    };
}lg_hcic_hcic_reg18c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg190:8;
        RBus_UInt32  hcic_reg191:8;
        RBus_UInt32  hcic_reg192:8;
        RBus_UInt32  hcic_reg193:8;
    };
}lg_hcic_hcic_reg190_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg194:8;
        RBus_UInt32  hcic_reg195:8;
        RBus_UInt32  hcic_reg196:8;
        RBus_UInt32  hcic_reg197:8;
    };
}lg_hcic_hcic_reg194_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg198:8;
        RBus_UInt32  hcic_reg199:8;
        RBus_UInt32  hcic_reg19a:8;
        RBus_UInt32  hcic_reg19b:8;
    };
}lg_hcic_hcic_reg198_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg19c:8;
        RBus_UInt32  hcic_reg19d:8;
        RBus_UInt32  hcic_reg19e:8;
        RBus_UInt32  hcic_reg19f:8;
    };
}lg_hcic_hcic_reg19c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1a0:8;
        RBus_UInt32  hcic_reg1a1:8;
        RBus_UInt32  hcic_reg1a2:8;
        RBus_UInt32  hcic_reg1a3:8;
    };
}lg_hcic_hcic_reg1a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1a4:8;
        RBus_UInt32  hcic_reg1a5:8;
        RBus_UInt32  hcic_reg1a6:8;
        RBus_UInt32  hcic_reg1a7:8;
    };
}lg_hcic_hcic_reg1a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1a8:8;
        RBus_UInt32  hcic_reg1a9:8;
        RBus_UInt32  hcic_reg1aa:8;
        RBus_UInt32  hcic_reg1ab:8;
    };
}lg_hcic_hcic_reg1a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1ac:8;
        RBus_UInt32  hcic_reg1ad:8;
        RBus_UInt32  hcic_reg1ae:8;
        RBus_UInt32  hcic_reg1af:8;
    };
}lg_hcic_hcic_reg1ac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1b0:8;
        RBus_UInt32  hcic_reg1b1:8;
        RBus_UInt32  hcic_reg1b2:8;
        RBus_UInt32  hcic_reg1b3:8;
    };
}lg_hcic_hcic_reg1b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1b4:8;
        RBus_UInt32  hcic_reg1b5:8;
        RBus_UInt32  hcic_reg1b6:8;
        RBus_UInt32  hcic_reg1b7:8;
    };
}lg_hcic_hcic_reg1b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1b8:8;
        RBus_UInt32  hcic_reg1b9:8;
        RBus_UInt32  hcic_reg1ba:8;
        RBus_UInt32  hcic_reg1bb:8;
    };
}lg_hcic_hcic_reg1b8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1bc:8;
        RBus_UInt32  hcic_reg1bd:8;
        RBus_UInt32  hcic_reg1be:8;
        RBus_UInt32  hcic_reg1bf:8;
    };
}lg_hcic_hcic_reg1bc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1c0:8;
        RBus_UInt32  hcic_reg1c1:8;
        RBus_UInt32  hcic_reg1c2:8;
        RBus_UInt32  hcic_reg1c3:8;
    };
}lg_hcic_hcic_reg1c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1c4:8;
        RBus_UInt32  hcic_reg1c5:8;
        RBus_UInt32  hcic_reg1c6:8;
        RBus_UInt32  hcic_reg1c7:8;
    };
}lg_hcic_hcic_reg1c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1c8:8;
        RBus_UInt32  hcic_reg1c9:8;
        RBus_UInt32  hcic_reg1ca:8;
        RBus_UInt32  hcic_reg1cb:8;
    };
}lg_hcic_hcic_reg1c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1cc:8;
        RBus_UInt32  hcic_reg1cd:8;
        RBus_UInt32  hcic_reg1ce:8;
        RBus_UInt32  hcic_reg1cf:8;
    };
}lg_hcic_hcic_reg1cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1d0:8;
        RBus_UInt32  hcic_reg1d1:8;
        RBus_UInt32  hcic_reg1d2:8;
        RBus_UInt32  hcic_reg1d3:8;
    };
}lg_hcic_hcic_reg1d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1d4:8;
        RBus_UInt32  hcic_reg1d5:8;
        RBus_UInt32  hcic_reg1d6:8;
        RBus_UInt32  hcic_reg1d7:8;
    };
}lg_hcic_hcic_reg1d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1d8:8;
        RBus_UInt32  hcic_reg1d9:8;
        RBus_UInt32  hcic_reg1da:8;
        RBus_UInt32  hcic_reg1db:8;
    };
}lg_hcic_hcic_reg1d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1dc:8;
        RBus_UInt32  hcic_reg1dd:8;
        RBus_UInt32  hcic_reg1de:8;
        RBus_UInt32  hcic_reg1df:8;
    };
}lg_hcic_hcic_reg1dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1e0:8;
        RBus_UInt32  hcic_reg1e1:8;
        RBus_UInt32  hcic_reg1e2:8;
        RBus_UInt32  hcic_reg1e3:8;
    };
}lg_hcic_hcic_reg1e0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1e4:8;
        RBus_UInt32  hcic_reg1e5:8;
        RBus_UInt32  hcic_reg1e6:8;
        RBus_UInt32  hcic_reg1e7:8;
    };
}lg_hcic_hcic_reg1e4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1e8:8;
        RBus_UInt32  hcic_reg1e9:8;
        RBus_UInt32  hcic_reg1ea:8;
        RBus_UInt32  hcic_reg1eb:8;
    };
}lg_hcic_hcic_reg1e8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1ec:8;
        RBus_UInt32  hcic_reg1ed:8;
        RBus_UInt32  hcic_reg1ee:8;
        RBus_UInt32  hcic_reg1ef:8;
    };
}lg_hcic_hcic_reg1ec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1f0:8;
        RBus_UInt32  hcic_reg1f1:8;
        RBus_UInt32  hcic_reg1f2:8;
        RBus_UInt32  hcic_reg1f3:8;
    };
}lg_hcic_hcic_reg1f0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1f4:8;
        RBus_UInt32  hcic_reg1f5:8;
        RBus_UInt32  hcic_reg1f6:8;
        RBus_UInt32  hcic_reg1f7:8;
    };
}lg_hcic_hcic_reg1f4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1f8:8;
        RBus_UInt32  hcic_reg1f9:8;
        RBus_UInt32  hcic_reg1fa:8;
        RBus_UInt32  hcic_reg1fb:8;
    };
}lg_hcic_hcic_reg1f8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1fc:8;
        RBus_UInt32  hcic_reg1fd:8;
        RBus_UInt32  hcic_reg1fe:8;
        RBus_UInt32  hcic_reg1ff:8;
    };
}lg_hcic_hcic_reg1fc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg200:8;
        RBus_UInt32  hcic_reg201:8;
        RBus_UInt32  hcic_reg202:8;
        RBus_UInt32  hcic_reg203:8;
    };
}lg_hcic_hcic_reg200_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg204:8;
        RBus_UInt32  hcic_reg205:8;
        RBus_UInt32  hcic_reg206:8;
        RBus_UInt32  hcic_reg207:8;
    };
}lg_hcic_hcic_reg204_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg208:8;
        RBus_UInt32  hcic_reg209:8;
        RBus_UInt32  hcic_reg20a:8;
        RBus_UInt32  hcic_reg20b:8;
    };
}lg_hcic_hcic_reg208_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg20c:8;
        RBus_UInt32  hcic_reg20d:8;
        RBus_UInt32  hcic_reg20e:8;
        RBus_UInt32  hcic_reg20f:8;
    };
}lg_hcic_hcic_reg20c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg210:8;
        RBus_UInt32  hcic_reg211:8;
        RBus_UInt32  hcic_reg212:8;
        RBus_UInt32  hcic_reg213:8;
    };
}lg_hcic_hcic_reg210_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg214:8;
        RBus_UInt32  hcic_reg215:8;
        RBus_UInt32  hcic_reg216:8;
        RBus_UInt32  hcic_reg217:8;
    };
}lg_hcic_hcic_reg214_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg218:8;
        RBus_UInt32  hcic_reg219:8;
        RBus_UInt32  hcic_reg21a:8;
        RBus_UInt32  hcic_reg21b:8;
    };
}lg_hcic_hcic_reg218_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg21c:8;
        RBus_UInt32  hcic_reg21d:8;
        RBus_UInt32  hcic_reg21e:8;
        RBus_UInt32  hcic_reg21f:8;
    };
}lg_hcic_hcic_reg21c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg220:8;
        RBus_UInt32  hcic_reg221:8;
        RBus_UInt32  hcic_reg222:8;
        RBus_UInt32  hcic_reg223:8;
    };
}lg_hcic_hcic_reg220_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg224:8;
        RBus_UInt32  hcic_reg225:8;
        RBus_UInt32  hcic_reg226:8;
        RBus_UInt32  hcic_reg227:8;
    };
}lg_hcic_hcic_reg224_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg228:8;
        RBus_UInt32  hcic_reg229:8;
        RBus_UInt32  hcic_reg22a:8;
        RBus_UInt32  hcic_reg22b:8;
    };
}lg_hcic_hcic_reg228_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg22c:8;
        RBus_UInt32  hcic_reg22d:8;
        RBus_UInt32  hcic_reg22e:8;
        RBus_UInt32  hcic_reg22f:8;
    };
}lg_hcic_hcic_reg22c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg230:8;
        RBus_UInt32  hcic_reg231:8;
        RBus_UInt32  hcic_reg232:8;
        RBus_UInt32  hcic_reg233:8;
    };
}lg_hcic_hcic_reg230_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg234:8;
        RBus_UInt32  hcic_reg235:8;
        RBus_UInt32  hcic_reg236:8;
        RBus_UInt32  hcic_reg237:8;
    };
}lg_hcic_hcic_reg234_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg238:8;
        RBus_UInt32  hcic_reg239:8;
        RBus_UInt32  hcic_reg23a:8;
        RBus_UInt32  hcic_reg23b:8;
    };
}lg_hcic_hcic_reg238_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg23c:8;
        RBus_UInt32  hcic_reg23d:8;
        RBus_UInt32  hcic_reg23e:8;
        RBus_UInt32  hcic_reg23f:8;
    };
}lg_hcic_hcic_reg23c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg240:8;
        RBus_UInt32  hcic_reg241:8;
        RBus_UInt32  hcic_reg242:8;
        RBus_UInt32  hcic_reg243:8;
    };
}lg_hcic_hcic_reg240_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg244:8;
        RBus_UInt32  hcic_reg245:8;
        RBus_UInt32  hcic_reg246:8;
        RBus_UInt32  hcic_reg247:8;
    };
}lg_hcic_hcic_reg244_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg248:8;
        RBus_UInt32  hcic_reg249:8;
        RBus_UInt32  hcic_reg24a:8;
        RBus_UInt32  hcic_reg24b:8;
    };
}lg_hcic_hcic_reg248_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg24c:8;
        RBus_UInt32  hcic_reg24d:8;
        RBus_UInt32  hcic_reg24e:8;
        RBus_UInt32  hcic_reg24f:8;
    };
}lg_hcic_hcic_reg24c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg250:8;
        RBus_UInt32  hcic_reg251:8;
        RBus_UInt32  hcic_reg252:8;
        RBus_UInt32  hcic_reg253:8;
    };
}lg_hcic_hcic_reg250_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg254:8;
        RBus_UInt32  hcic_reg255:8;
        RBus_UInt32  hcic_reg256:8;
        RBus_UInt32  hcic_reg257:8;
    };
}lg_hcic_hcic_reg254_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg258:8;
        RBus_UInt32  hcic_reg259:8;
        RBus_UInt32  hcic_reg25a:8;
        RBus_UInt32  hcic_reg25b:8;
    };
}lg_hcic_hcic_reg258_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg25c:8;
        RBus_UInt32  hcic_reg25d:8;
        RBus_UInt32  hcic_reg25e:8;
        RBus_UInt32  hcic_reg25f:8;
    };
}lg_hcic_hcic_reg25c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg260:8;
        RBus_UInt32  hcic_reg261:8;
        RBus_UInt32  hcic_reg262:8;
        RBus_UInt32  hcic_reg263:8;
    };
}lg_hcic_hcic_reg260_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg264:8;
        RBus_UInt32  hcic_reg265:8;
        RBus_UInt32  hcic_reg266:8;
        RBus_UInt32  hcic_reg267:8;
    };
}lg_hcic_hcic_reg264_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg268:8;
        RBus_UInt32  hcic_reg269:8;
        RBus_UInt32  hcic_reg26a:8;
        RBus_UInt32  hcic_reg26b:8;
    };
}lg_hcic_hcic_reg268_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg26c:8;
        RBus_UInt32  hcic_reg26d:8;
        RBus_UInt32  hcic_reg26e:8;
        RBus_UInt32  hcic_reg26f:8;
    };
}lg_hcic_hcic_reg26c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg270:8;
        RBus_UInt32  hcic_reg271:8;
        RBus_UInt32  hcic_reg272:8;
        RBus_UInt32  hcic_reg273:8;
    };
}lg_hcic_hcic_reg270_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg274:8;
        RBus_UInt32  hcic_reg275:8;
        RBus_UInt32  hcic_reg276:8;
        RBus_UInt32  hcic_reg277:8;
    };
}lg_hcic_hcic_reg274_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg278:8;
        RBus_UInt32  hcic_reg279:8;
        RBus_UInt32  hcic_reg27a:8;
        RBus_UInt32  hcic_reg27b:8;
    };
}lg_hcic_hcic_reg278_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg27c:8;
        RBus_UInt32  hcic_reg27d:8;
        RBus_UInt32  hcic_reg27e:8;
        RBus_UInt32  hcic_reg27f:8;
    };
}lg_hcic_hcic_reg27c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg280:8;
        RBus_UInt32  hcic_reg281:8;
        RBus_UInt32  hcic_reg282:8;
        RBus_UInt32  hcic_reg283:8;
    };
}lg_hcic_hcic_reg280_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg284:8;
        RBus_UInt32  hcic_reg285:8;
        RBus_UInt32  hcic_reg286:8;
        RBus_UInt32  hcic_reg287:8;
    };
}lg_hcic_hcic_reg284_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg288:8;
        RBus_UInt32  hcic_reg289:8;
        RBus_UInt32  hcic_reg28a:8;
        RBus_UInt32  hcic_reg28b:8;
    };
}lg_hcic_hcic_reg288_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg28c:8;
        RBus_UInt32  hcic_reg28d:8;
        RBus_UInt32  hcic_reg28e:8;
        RBus_UInt32  hcic_reg28f:8;
    };
}lg_hcic_hcic_reg28c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg290:8;
        RBus_UInt32  hcic_reg291:8;
        RBus_UInt32  hcic_reg292:8;
        RBus_UInt32  hcic_reg293:8;
    };
}lg_hcic_hcic_reg290_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg294:8;
        RBus_UInt32  hcic_reg295:8;
        RBus_UInt32  hcic_reg296:8;
        RBus_UInt32  hcic_reg297:8;
    };
}lg_hcic_hcic_reg294_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg298:8;
        RBus_UInt32  hcic_reg299:8;
        RBus_UInt32  hcic_reg29a:8;
        RBus_UInt32  hcic_reg29b:8;
    };
}lg_hcic_hcic_reg298_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg29c:8;
        RBus_UInt32  hcic_reg29d:8;
        RBus_UInt32  hcic_reg29e:8;
        RBus_UInt32  hcic_reg29f:8;
    };
}lg_hcic_hcic_reg29c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2a0:8;
        RBus_UInt32  hcic_reg2a1:8;
        RBus_UInt32  hcic_reg2a2:8;
        RBus_UInt32  hcic_reg2a3:8;
    };
}lg_hcic_hcic_reg2a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2a4:8;
        RBus_UInt32  hcic_reg2a5:8;
        RBus_UInt32  hcic_reg2a6:8;
        RBus_UInt32  hcic_reg2a7:8;
    };
}lg_hcic_hcic_reg2a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2a8:8;
        RBus_UInt32  hcic_reg2a9:8;
        RBus_UInt32  hcic_reg2aa:8;
        RBus_UInt32  hcic_reg2ab:8;
    };
}lg_hcic_hcic_reg2a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2ac:8;
        RBus_UInt32  hcic_reg2ad:8;
        RBus_UInt32  hcic_reg2ae:8;
        RBus_UInt32  hcic_reg2af:8;
    };
}lg_hcic_hcic_reg2ac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2b0:8;
        RBus_UInt32  hcic_reg2b1:8;
        RBus_UInt32  hcic_reg2b2:8;
        RBus_UInt32  hcic_reg2b3:8;
    };
}lg_hcic_hcic_reg2b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2b4:8;
        RBus_UInt32  hcic_reg2b5:8;
        RBus_UInt32  hcic_reg2b6:8;
        RBus_UInt32  hcic_reg2b7:8;
    };
}lg_hcic_hcic_reg2b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2b8:8;
        RBus_UInt32  hcic_reg2b9:8;
        RBus_UInt32  hcic_reg2ba:8;
        RBus_UInt32  hcic_reg2bb:8;
    };
}lg_hcic_hcic_reg2b8_RBUS;

#else //apply LITTLE_ENDIAN

//======LG_HCIC register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reverse:1;
        RBus_UInt32  frcon:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  auto_detect_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  auto_detect_result:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  user_timing_sel:2;
        RBus_UInt32  res4:18;
    };
}lg_hcic_hcic_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg003:8;
        RBus_UInt32  hcic_reg002:8;
        RBus_UInt32  hcic_reg001:8;
        RBus_UInt32  hcic_reg000:8;
    };
}lg_hcic_hcic_reg000_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg007:8;
        RBus_UInt32  hcic_reg006:8;
        RBus_UInt32  hcic_reg005:8;
        RBus_UInt32  hcic_reg004:8;
    };
}lg_hcic_hcic_reg004_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg00b:8;
        RBus_UInt32  hcic_reg00a:8;
        RBus_UInt32  hcic_reg009:8;
        RBus_UInt32  hcic_reg008:8;
    };
}lg_hcic_hcic_reg008_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg00f:8;
        RBus_UInt32  hcic_reg00e:8;
        RBus_UInt32  hcic_reg00d:8;
        RBus_UInt32  hcic_reg00c:8;
    };
}lg_hcic_hcic_reg00c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg013:8;
        RBus_UInt32  hcic_reg012:8;
        RBus_UInt32  hcic_reg011:8;
        RBus_UInt32  hcic_reg010:8;
    };
}lg_hcic_hcic_reg010_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg017:8;
        RBus_UInt32  hcic_reg016:8;
        RBus_UInt32  hcic_reg015:8;
        RBus_UInt32  hcic_reg014:8;
    };
}lg_hcic_hcic_reg014_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg01b:8;
        RBus_UInt32  hcic_reg01a:8;
        RBus_UInt32  hcic_reg019:8;
        RBus_UInt32  hcic_reg018:8;
    };
}lg_hcic_hcic_reg018_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg01f:8;
        RBus_UInt32  hcic_reg01e:8;
        RBus_UInt32  hcic_reg01d:8;
        RBus_UInt32  hcic_reg01c:8;
    };
}lg_hcic_hcic_reg01c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg023:8;
        RBus_UInt32  hcic_reg022:8;
        RBus_UInt32  hcic_reg021:8;
        RBus_UInt32  hcic_reg020:8;
    };
}lg_hcic_hcic_reg020_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg027:8;
        RBus_UInt32  hcic_reg026:8;
        RBus_UInt32  hcic_reg025:8;
        RBus_UInt32  hcic_reg024:8;
    };
}lg_hcic_hcic_reg024_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg02b:8;
        RBus_UInt32  hcic_reg02a:8;
        RBus_UInt32  hcic_reg029:8;
        RBus_UInt32  hcic_reg028:8;
    };
}lg_hcic_hcic_reg028_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg02f:8;
        RBus_UInt32  hcic_reg02e:8;
        RBus_UInt32  hcic_reg02d:8;
        RBus_UInt32  hcic_reg02c:8;
    };
}lg_hcic_hcic_reg02c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg033:8;
        RBus_UInt32  hcic_reg032:8;
        RBus_UInt32  hcic_reg031:8;
        RBus_UInt32  hcic_reg030:8;
    };
}lg_hcic_hcic_reg030_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg037:8;
        RBus_UInt32  hcic_reg036:8;
        RBus_UInt32  hcic_reg035:8;
        RBus_UInt32  hcic_reg034:8;
    };
}lg_hcic_hcic_reg034_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg03b:8;
        RBus_UInt32  hcic_reg03a:8;
        RBus_UInt32  hcic_reg039:8;
        RBus_UInt32  hcic_reg038:8;
    };
}lg_hcic_hcic_reg038_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg03f:8;
        RBus_UInt32  hcic_reg03e:8;
        RBus_UInt32  hcic_reg03d:8;
        RBus_UInt32  hcic_reg03c:8;
    };
}lg_hcic_hcic_reg03c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg043:8;
        RBus_UInt32  hcic_reg042:8;
        RBus_UInt32  hcic_reg041:8;
        RBus_UInt32  hcic_reg040:8;
    };
}lg_hcic_hcic_reg040_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg047:8;
        RBus_UInt32  hcic_reg046:8;
        RBus_UInt32  hcic_reg045:8;
        RBus_UInt32  hcic_reg044:8;
    };
}lg_hcic_hcic_reg044_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg04b:8;
        RBus_UInt32  hcic_reg04a:8;
        RBus_UInt32  hcic_reg049:8;
        RBus_UInt32  hcic_reg048:8;
    };
}lg_hcic_hcic_reg048_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg04f:8;
        RBus_UInt32  hcic_reg04e:8;
        RBus_UInt32  hcic_reg04d:8;
        RBus_UInt32  hcic_reg04c:8;
    };
}lg_hcic_hcic_reg04c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg053:8;
        RBus_UInt32  hcic_reg052:8;
        RBus_UInt32  hcic_reg051:8;
        RBus_UInt32  hcic_reg050:8;
    };
}lg_hcic_hcic_reg050_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg057:8;
        RBus_UInt32  hcic_reg056:8;
        RBus_UInt32  hcic_reg055:8;
        RBus_UInt32  hcic_reg054:8;
    };
}lg_hcic_hcic_reg054_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg05b:8;
        RBus_UInt32  hcic_reg05a:8;
        RBus_UInt32  hcic_reg059:8;
        RBus_UInt32  hcic_reg058:8;
    };
}lg_hcic_hcic_reg058_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg05f:8;
        RBus_UInt32  hcic_reg05e:8;
        RBus_UInt32  hcic_reg05d:8;
        RBus_UInt32  hcic_reg05c:8;
    };
}lg_hcic_hcic_reg05c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg063:8;
        RBus_UInt32  hcic_reg062:8;
        RBus_UInt32  hcic_reg061:8;
        RBus_UInt32  hcic_reg060:8;
    };
}lg_hcic_hcic_reg060_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg067:8;
        RBus_UInt32  hcic_reg066:8;
        RBus_UInt32  hcic_reg065:8;
        RBus_UInt32  hcic_reg064:8;
    };
}lg_hcic_hcic_reg064_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg06b:8;
        RBus_UInt32  hcic_reg06a:8;
        RBus_UInt32  hcic_reg069:8;
        RBus_UInt32  hcic_reg068:8;
    };
}lg_hcic_hcic_reg068_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg06f:8;
        RBus_UInt32  hcic_reg06e:8;
        RBus_UInt32  hcic_reg06d:8;
        RBus_UInt32  hcic_reg06c:8;
    };
}lg_hcic_hcic_reg06c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg073:8;
        RBus_UInt32  hcic_reg072:8;
        RBus_UInt32  hcic_reg071:8;
        RBus_UInt32  hcic_reg070:8;
    };
}lg_hcic_hcic_reg070_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg077:8;
        RBus_UInt32  hcic_reg076:8;
        RBus_UInt32  hcic_reg075:8;
        RBus_UInt32  hcic_reg074:8;
    };
}lg_hcic_hcic_reg074_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg07b:8;
        RBus_UInt32  hcic_reg07a:8;
        RBus_UInt32  hcic_reg079:8;
        RBus_UInt32  hcic_reg078:8;
    };
}lg_hcic_hcic_reg078_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg07f:8;
        RBus_UInt32  hcic_reg07e:8;
        RBus_UInt32  hcic_reg07d:8;
        RBus_UInt32  hcic_reg07c:8;
    };
}lg_hcic_hcic_reg07c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg083:8;
        RBus_UInt32  hcic_reg082:8;
        RBus_UInt32  hcic_reg081:8;
        RBus_UInt32  hcic_reg080:8;
    };
}lg_hcic_hcic_reg080_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg087:8;
        RBus_UInt32  hcic_reg086:8;
        RBus_UInt32  hcic_reg085:8;
        RBus_UInt32  hcic_reg084:8;
    };
}lg_hcic_hcic_reg084_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg08b:8;
        RBus_UInt32  hcic_reg08a:8;
        RBus_UInt32  hcic_reg089:8;
        RBus_UInt32  hcic_reg088:8;
    };
}lg_hcic_hcic_reg088_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg08f:8;
        RBus_UInt32  hcic_reg08e:8;
        RBus_UInt32  hcic_reg08d:8;
        RBus_UInt32  hcic_reg08c:8;
    };
}lg_hcic_hcic_reg08c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg093:8;
        RBus_UInt32  hcic_reg092:8;
        RBus_UInt32  hcic_reg091:8;
        RBus_UInt32  hcic_reg090:8;
    };
}lg_hcic_hcic_reg090_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg097:8;
        RBus_UInt32  hcic_reg096:8;
        RBus_UInt32  hcic_reg095:8;
        RBus_UInt32  hcic_reg094:8;
    };
}lg_hcic_hcic_reg094_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg09b:8;
        RBus_UInt32  hcic_reg09a:8;
        RBus_UInt32  hcic_reg099:8;
        RBus_UInt32  hcic_reg098:8;
    };
}lg_hcic_hcic_reg098_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg09f:8;
        RBus_UInt32  hcic_reg09e:8;
        RBus_UInt32  hcic_reg09d:8;
        RBus_UInt32  hcic_reg09c:8;
    };
}lg_hcic_hcic_reg09c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0a3:8;
        RBus_UInt32  hcic_reg0a2:8;
        RBus_UInt32  hcic_reg0a1:8;
        RBus_UInt32  hcic_reg0a0:8;
    };
}lg_hcic_hcic_reg0a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0a7:8;
        RBus_UInt32  hcic_reg0a6:8;
        RBus_UInt32  hcic_reg0a5:8;
        RBus_UInt32  hcic_reg0a4:8;
    };
}lg_hcic_hcic_reg0a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0ab:8;
        RBus_UInt32  hcic_reg0aa:8;
        RBus_UInt32  hcic_reg0a9:8;
        RBus_UInt32  hcic_reg0a8:8;
    };
}lg_hcic_hcic_reg0a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0af:8;
        RBus_UInt32  hcic_reg0ae:8;
        RBus_UInt32  hcic_reg0ad:8;
        RBus_UInt32  hcic_reg0ac:8;
    };
}lg_hcic_hcic_reg0ac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0b3:8;
        RBus_UInt32  hcic_reg0b2:8;
        RBus_UInt32  hcic_reg0b1:8;
        RBus_UInt32  hcic_reg0b0:8;
    };
}lg_hcic_hcic_reg0b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0b7:8;
        RBus_UInt32  hcic_reg0b6:8;
        RBus_UInt32  hcic_reg0b5:8;
        RBus_UInt32  hcic_reg0b4:8;
    };
}lg_hcic_hcic_reg0b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0bb:8;
        RBus_UInt32  hcic_reg0ba:8;
        RBus_UInt32  hcic_reg0b9:8;
        RBus_UInt32  hcic_reg0b8:8;
    };
}lg_hcic_hcic_reg0b8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0bf:8;
        RBus_UInt32  hcic_reg0be:8;
        RBus_UInt32  hcic_reg0bd:8;
        RBus_UInt32  hcic_reg0bc:8;
    };
}lg_hcic_hcic_reg0bc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0c3:8;
        RBus_UInt32  hcic_reg0c2:8;
        RBus_UInt32  hcic_reg0c1:8;
        RBus_UInt32  hcic_reg0c0:8;
    };
}lg_hcic_hcic_reg0c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0c7:8;
        RBus_UInt32  hcic_reg0c6:8;
        RBus_UInt32  hcic_reg0c5:8;
        RBus_UInt32  hcic_reg0c4:8;
    };
}lg_hcic_hcic_reg0c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0cb:8;
        RBus_UInt32  hcic_reg0ca:8;
        RBus_UInt32  hcic_reg0c9:8;
        RBus_UInt32  hcic_reg0c8:8;
    };
}lg_hcic_hcic_reg0c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0cf:8;
        RBus_UInt32  hcic_reg0ce:8;
        RBus_UInt32  hcic_reg0cd:8;
        RBus_UInt32  hcic_reg0cc:8;
    };
}lg_hcic_hcic_reg0cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0d3:8;
        RBus_UInt32  hcic_reg0d2:8;
        RBus_UInt32  hcic_reg0d1:8;
        RBus_UInt32  hcic_reg0d0:8;
    };
}lg_hcic_hcic_reg0d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0d7:8;
        RBus_UInt32  hcic_reg0d6:8;
        RBus_UInt32  hcic_reg0d5:8;
        RBus_UInt32  hcic_reg0d4:8;
    };
}lg_hcic_hcic_reg0d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0db:8;
        RBus_UInt32  hcic_reg0da:8;
        RBus_UInt32  hcic_reg0d9:8;
        RBus_UInt32  hcic_reg0d8:8;
    };
}lg_hcic_hcic_reg0d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0df:8;
        RBus_UInt32  hcic_reg0de:8;
        RBus_UInt32  hcic_reg0dd:8;
        RBus_UInt32  hcic_reg0dc:8;
    };
}lg_hcic_hcic_reg0dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0e3:8;
        RBus_UInt32  hcic_reg0e2:8;
        RBus_UInt32  hcic_reg0e1:8;
        RBus_UInt32  hcic_reg0e0:8;
    };
}lg_hcic_hcic_reg0e0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0e7:8;
        RBus_UInt32  hcic_reg0e6:8;
        RBus_UInt32  hcic_reg0e5:8;
        RBus_UInt32  hcic_reg0e4:8;
    };
}lg_hcic_hcic_reg0e4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0eb:8;
        RBus_UInt32  hcic_reg0ea:8;
        RBus_UInt32  hcic_reg0e9:8;
        RBus_UInt32  hcic_reg0e8:8;
    };
}lg_hcic_hcic_reg0e8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0ef:8;
        RBus_UInt32  hcic_reg0ee:8;
        RBus_UInt32  hcic_reg0ed:8;
        RBus_UInt32  hcic_reg0ec:8;
    };
}lg_hcic_hcic_reg0ec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0f3:8;
        RBus_UInt32  hcic_reg0f2:8;
        RBus_UInt32  hcic_reg0f1:8;
        RBus_UInt32  hcic_reg0f0:8;
    };
}lg_hcic_hcic_reg0f0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0f7:8;
        RBus_UInt32  hcic_reg0f6:8;
        RBus_UInt32  hcic_reg0f5:8;
        RBus_UInt32  hcic_reg0f4:8;
    };
}lg_hcic_hcic_reg0f4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0fb:8;
        RBus_UInt32  hcic_reg0fa:8;
        RBus_UInt32  hcic_reg0f9:8;
        RBus_UInt32  hcic_reg0f8:8;
    };
}lg_hcic_hcic_reg0f8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg0ff:8;
        RBus_UInt32  hcic_reg0fe:8;
        RBus_UInt32  hcic_reg0fd:8;
        RBus_UInt32  hcic_reg0fc:8;
    };
}lg_hcic_hcic_reg0fc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg103:8;
        RBus_UInt32  hcic_reg102:8;
        RBus_UInt32  hcic_reg101:8;
        RBus_UInt32  hcic_reg100:8;
    };
}lg_hcic_hcic_reg100_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg107:8;
        RBus_UInt32  hcic_reg106:8;
        RBus_UInt32  hcic_reg105:8;
        RBus_UInt32  hcic_reg104:8;
    };
}lg_hcic_hcic_reg104_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg10b:8;
        RBus_UInt32  hcic_reg10a:8;
        RBus_UInt32  hcic_reg109:8;
        RBus_UInt32  hcic_reg108:8;
    };
}lg_hcic_hcic_reg108_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg10f:8;
        RBus_UInt32  hcic_reg10e:8;
        RBus_UInt32  hcic_reg10d:8;
        RBus_UInt32  hcic_reg10c:8;
    };
}lg_hcic_hcic_reg10c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg113:8;
        RBus_UInt32  hcic_reg112:8;
        RBus_UInt32  hcic_reg111:8;
        RBus_UInt32  hcic_reg110:8;
    };
}lg_hcic_hcic_reg110_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg117:8;
        RBus_UInt32  hcic_reg116:8;
        RBus_UInt32  hcic_reg115:8;
        RBus_UInt32  hcic_reg114:8;
    };
}lg_hcic_hcic_reg114_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg11b:8;
        RBus_UInt32  hcic_reg11a:8;
        RBus_UInt32  hcic_reg119:8;
        RBus_UInt32  hcic_reg118:8;
    };
}lg_hcic_hcic_reg118_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg11f:8;
        RBus_UInt32  hcic_reg11e:8;
        RBus_UInt32  hcic_reg11d:8;
        RBus_UInt32  hcic_reg11c:8;
    };
}lg_hcic_hcic_reg11c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg123:8;
        RBus_UInt32  hcic_reg122:8;
        RBus_UInt32  hcic_reg121:8;
        RBus_UInt32  hcic_reg120:8;
    };
}lg_hcic_hcic_reg120_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg127:8;
        RBus_UInt32  hcic_reg126:8;
        RBus_UInt32  hcic_reg125:8;
        RBus_UInt32  hcic_reg124:8;
    };
}lg_hcic_hcic_reg124_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg12b:8;
        RBus_UInt32  hcic_reg12a:8;
        RBus_UInt32  hcic_reg129:8;
        RBus_UInt32  hcic_reg128:8;
    };
}lg_hcic_hcic_reg128_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg12f:8;
        RBus_UInt32  hcic_reg12e:8;
        RBus_UInt32  hcic_reg12d:8;
        RBus_UInt32  hcic_reg12c:8;
    };
}lg_hcic_hcic_reg12c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg133:8;
        RBus_UInt32  hcic_reg132:8;
        RBus_UInt32  hcic_reg131:8;
        RBus_UInt32  hcic_reg130:8;
    };
}lg_hcic_hcic_reg130_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg137:8;
        RBus_UInt32  hcic_reg136:8;
        RBus_UInt32  hcic_reg135:8;
        RBus_UInt32  hcic_reg134:8;
    };
}lg_hcic_hcic_reg134_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg13b:8;
        RBus_UInt32  hcic_reg13a:8;
        RBus_UInt32  hcic_reg139:8;
        RBus_UInt32  hcic_reg138:8;
    };
}lg_hcic_hcic_reg138_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg13f:8;
        RBus_UInt32  hcic_reg13e:8;
        RBus_UInt32  hcic_reg13d:8;
        RBus_UInt32  hcic_reg13c:8;
    };
}lg_hcic_hcic_reg13c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg143:8;
        RBus_UInt32  hcic_reg142:8;
        RBus_UInt32  hcic_reg141:8;
        RBus_UInt32  hcic_reg140:8;
    };
}lg_hcic_hcic_reg140_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg147:8;
        RBus_UInt32  hcic_reg146:8;
        RBus_UInt32  hcic_reg145:8;
        RBus_UInt32  hcic_reg144:8;
    };
}lg_hcic_hcic_reg144_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg14b:8;
        RBus_UInt32  hcic_reg14a:8;
        RBus_UInt32  hcic_reg149:8;
        RBus_UInt32  hcic_reg148:8;
    };
}lg_hcic_hcic_reg148_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg14f:8;
        RBus_UInt32  hcic_reg14e:8;
        RBus_UInt32  hcic_reg14d:8;
        RBus_UInt32  hcic_reg14c:8;
    };
}lg_hcic_hcic_reg14c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg153:8;
        RBus_UInt32  hcic_reg152:8;
        RBus_UInt32  hcic_reg151:8;
        RBus_UInt32  hcic_reg150:8;
    };
}lg_hcic_hcic_reg150_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg157:8;
        RBus_UInt32  hcic_reg156:8;
        RBus_UInt32  hcic_reg155:8;
        RBus_UInt32  hcic_reg154:8;
    };
}lg_hcic_hcic_reg154_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg15b:8;
        RBus_UInt32  hcic_reg15a:8;
        RBus_UInt32  hcic_reg159:8;
        RBus_UInt32  hcic_reg158:8;
    };
}lg_hcic_hcic_reg158_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg15f:8;
        RBus_UInt32  hcic_reg15e:8;
        RBus_UInt32  hcic_reg15d:8;
        RBus_UInt32  hcic_reg15c:8;
    };
}lg_hcic_hcic_reg15c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg163:8;
        RBus_UInt32  hcic_reg162:8;
        RBus_UInt32  hcic_reg161:8;
        RBus_UInt32  hcic_reg160:8;
    };
}lg_hcic_hcic_reg160_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg167:8;
        RBus_UInt32  hcic_reg166:8;
        RBus_UInt32  hcic_reg165:8;
        RBus_UInt32  hcic_reg164:8;
    };
}lg_hcic_hcic_reg164_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg16b:8;
        RBus_UInt32  hcic_reg16a:8;
        RBus_UInt32  hcic_reg169:8;
        RBus_UInt32  hcic_reg168:8;
    };
}lg_hcic_hcic_reg168_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg16f:8;
        RBus_UInt32  hcic_reg16e:8;
        RBus_UInt32  hcic_reg16d:8;
        RBus_UInt32  hcic_reg16c:8;
    };
}lg_hcic_hcic_reg16c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg173:8;
        RBus_UInt32  hcic_reg172:8;
        RBus_UInt32  hcic_reg171:8;
        RBus_UInt32  hcic_reg170:8;
    };
}lg_hcic_hcic_reg170_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg177:8;
        RBus_UInt32  hcic_reg176:8;
        RBus_UInt32  hcic_reg175:8;
        RBus_UInt32  hcic_reg174:8;
    };
}lg_hcic_hcic_reg174_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg17b:8;
        RBus_UInt32  hcic_reg17a:8;
        RBus_UInt32  hcic_reg179:8;
        RBus_UInt32  hcic_reg178:8;
    };
}lg_hcic_hcic_reg178_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg17f:8;
        RBus_UInt32  hcic_reg17e:8;
        RBus_UInt32  hcic_reg17d:8;
        RBus_UInt32  hcic_reg17c:8;
    };
}lg_hcic_hcic_reg17c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg183:8;
        RBus_UInt32  hcic_reg182:8;
        RBus_UInt32  hcic_reg181:8;
        RBus_UInt32  hcic_reg180:8;
    };
}lg_hcic_hcic_reg180_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg187:8;
        RBus_UInt32  hcic_reg186:8;
        RBus_UInt32  hcic_reg185:8;
        RBus_UInt32  hcic_reg184:8;
    };
}lg_hcic_hcic_reg184_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg18b:8;
        RBus_UInt32  hcic_reg18a:8;
        RBus_UInt32  hcic_reg189:8;
        RBus_UInt32  hcic_reg188:8;
    };
}lg_hcic_hcic_reg188_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg18f:8;
        RBus_UInt32  hcic_reg18e:8;
        RBus_UInt32  hcic_reg18d:8;
        RBus_UInt32  hcic_reg18c:8;
    };
}lg_hcic_hcic_reg18c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg193:8;
        RBus_UInt32  hcic_reg192:8;
        RBus_UInt32  hcic_reg191:8;
        RBus_UInt32  hcic_reg190:8;
    };
}lg_hcic_hcic_reg190_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg197:8;
        RBus_UInt32  hcic_reg196:8;
        RBus_UInt32  hcic_reg195:8;
        RBus_UInt32  hcic_reg194:8;
    };
}lg_hcic_hcic_reg194_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg19b:8;
        RBus_UInt32  hcic_reg19a:8;
        RBus_UInt32  hcic_reg199:8;
        RBus_UInt32  hcic_reg198:8;
    };
}lg_hcic_hcic_reg198_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg19f:8;
        RBus_UInt32  hcic_reg19e:8;
        RBus_UInt32  hcic_reg19d:8;
        RBus_UInt32  hcic_reg19c:8;
    };
}lg_hcic_hcic_reg19c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1a3:8;
        RBus_UInt32  hcic_reg1a2:8;
        RBus_UInt32  hcic_reg1a1:8;
        RBus_UInt32  hcic_reg1a0:8;
    };
}lg_hcic_hcic_reg1a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1a7:8;
        RBus_UInt32  hcic_reg1a6:8;
        RBus_UInt32  hcic_reg1a5:8;
        RBus_UInt32  hcic_reg1a4:8;
    };
}lg_hcic_hcic_reg1a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1ab:8;
        RBus_UInt32  hcic_reg1aa:8;
        RBus_UInt32  hcic_reg1a9:8;
        RBus_UInt32  hcic_reg1a8:8;
    };
}lg_hcic_hcic_reg1a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1af:8;
        RBus_UInt32  hcic_reg1ae:8;
        RBus_UInt32  hcic_reg1ad:8;
        RBus_UInt32  hcic_reg1ac:8;
    };
}lg_hcic_hcic_reg1ac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1b3:8;
        RBus_UInt32  hcic_reg1b2:8;
        RBus_UInt32  hcic_reg1b1:8;
        RBus_UInt32  hcic_reg1b0:8;
    };
}lg_hcic_hcic_reg1b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1b7:8;
        RBus_UInt32  hcic_reg1b6:8;
        RBus_UInt32  hcic_reg1b5:8;
        RBus_UInt32  hcic_reg1b4:8;
    };
}lg_hcic_hcic_reg1b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1bb:8;
        RBus_UInt32  hcic_reg1ba:8;
        RBus_UInt32  hcic_reg1b9:8;
        RBus_UInt32  hcic_reg1b8:8;
    };
}lg_hcic_hcic_reg1b8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1bf:8;
        RBus_UInt32  hcic_reg1be:8;
        RBus_UInt32  hcic_reg1bd:8;
        RBus_UInt32  hcic_reg1bc:8;
    };
}lg_hcic_hcic_reg1bc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1c3:8;
        RBus_UInt32  hcic_reg1c2:8;
        RBus_UInt32  hcic_reg1c1:8;
        RBus_UInt32  hcic_reg1c0:8;
    };
}lg_hcic_hcic_reg1c0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1c7:8;
        RBus_UInt32  hcic_reg1c6:8;
        RBus_UInt32  hcic_reg1c5:8;
        RBus_UInt32  hcic_reg1c4:8;
    };
}lg_hcic_hcic_reg1c4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1cb:8;
        RBus_UInt32  hcic_reg1ca:8;
        RBus_UInt32  hcic_reg1c9:8;
        RBus_UInt32  hcic_reg1c8:8;
    };
}lg_hcic_hcic_reg1c8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1cf:8;
        RBus_UInt32  hcic_reg1ce:8;
        RBus_UInt32  hcic_reg1cd:8;
        RBus_UInt32  hcic_reg1cc:8;
    };
}lg_hcic_hcic_reg1cc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1d3:8;
        RBus_UInt32  hcic_reg1d2:8;
        RBus_UInt32  hcic_reg1d1:8;
        RBus_UInt32  hcic_reg1d0:8;
    };
}lg_hcic_hcic_reg1d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1d7:8;
        RBus_UInt32  hcic_reg1d6:8;
        RBus_UInt32  hcic_reg1d5:8;
        RBus_UInt32  hcic_reg1d4:8;
    };
}lg_hcic_hcic_reg1d4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1db:8;
        RBus_UInt32  hcic_reg1da:8;
        RBus_UInt32  hcic_reg1d9:8;
        RBus_UInt32  hcic_reg1d8:8;
    };
}lg_hcic_hcic_reg1d8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1df:8;
        RBus_UInt32  hcic_reg1de:8;
        RBus_UInt32  hcic_reg1dd:8;
        RBus_UInt32  hcic_reg1dc:8;
    };
}lg_hcic_hcic_reg1dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1e3:8;
        RBus_UInt32  hcic_reg1e2:8;
        RBus_UInt32  hcic_reg1e1:8;
        RBus_UInt32  hcic_reg1e0:8;
    };
}lg_hcic_hcic_reg1e0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1e7:8;
        RBus_UInt32  hcic_reg1e6:8;
        RBus_UInt32  hcic_reg1e5:8;
        RBus_UInt32  hcic_reg1e4:8;
    };
}lg_hcic_hcic_reg1e4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1eb:8;
        RBus_UInt32  hcic_reg1ea:8;
        RBus_UInt32  hcic_reg1e9:8;
        RBus_UInt32  hcic_reg1e8:8;
    };
}lg_hcic_hcic_reg1e8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1ef:8;
        RBus_UInt32  hcic_reg1ee:8;
        RBus_UInt32  hcic_reg1ed:8;
        RBus_UInt32  hcic_reg1ec:8;
    };
}lg_hcic_hcic_reg1ec_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1f3:8;
        RBus_UInt32  hcic_reg1f2:8;
        RBus_UInt32  hcic_reg1f1:8;
        RBus_UInt32  hcic_reg1f0:8;
    };
}lg_hcic_hcic_reg1f0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1f7:8;
        RBus_UInt32  hcic_reg1f6:8;
        RBus_UInt32  hcic_reg1f5:8;
        RBus_UInt32  hcic_reg1f4:8;
    };
}lg_hcic_hcic_reg1f4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1fb:8;
        RBus_UInt32  hcic_reg1fa:8;
        RBus_UInt32  hcic_reg1f9:8;
        RBus_UInt32  hcic_reg1f8:8;
    };
}lg_hcic_hcic_reg1f8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg1ff:8;
        RBus_UInt32  hcic_reg1fe:8;
        RBus_UInt32  hcic_reg1fd:8;
        RBus_UInt32  hcic_reg1fc:8;
    };
}lg_hcic_hcic_reg1fc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg203:8;
        RBus_UInt32  hcic_reg202:8;
        RBus_UInt32  hcic_reg201:8;
        RBus_UInt32  hcic_reg200:8;
    };
}lg_hcic_hcic_reg200_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg207:8;
        RBus_UInt32  hcic_reg206:8;
        RBus_UInt32  hcic_reg205:8;
        RBus_UInt32  hcic_reg204:8;
    };
}lg_hcic_hcic_reg204_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg20b:8;
        RBus_UInt32  hcic_reg20a:8;
        RBus_UInt32  hcic_reg209:8;
        RBus_UInt32  hcic_reg208:8;
    };
}lg_hcic_hcic_reg208_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg20f:8;
        RBus_UInt32  hcic_reg20e:8;
        RBus_UInt32  hcic_reg20d:8;
        RBus_UInt32  hcic_reg20c:8;
    };
}lg_hcic_hcic_reg20c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg213:8;
        RBus_UInt32  hcic_reg212:8;
        RBus_UInt32  hcic_reg211:8;
        RBus_UInt32  hcic_reg210:8;
    };
}lg_hcic_hcic_reg210_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg217:8;
        RBus_UInt32  hcic_reg216:8;
        RBus_UInt32  hcic_reg215:8;
        RBus_UInt32  hcic_reg214:8;
    };
}lg_hcic_hcic_reg214_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg21b:8;
        RBus_UInt32  hcic_reg21a:8;
        RBus_UInt32  hcic_reg219:8;
        RBus_UInt32  hcic_reg218:8;
    };
}lg_hcic_hcic_reg218_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg21f:8;
        RBus_UInt32  hcic_reg21e:8;
        RBus_UInt32  hcic_reg21d:8;
        RBus_UInt32  hcic_reg21c:8;
    };
}lg_hcic_hcic_reg21c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg223:8;
        RBus_UInt32  hcic_reg222:8;
        RBus_UInt32  hcic_reg221:8;
        RBus_UInt32  hcic_reg220:8;
    };
}lg_hcic_hcic_reg220_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg227:8;
        RBus_UInt32  hcic_reg226:8;
        RBus_UInt32  hcic_reg225:8;
        RBus_UInt32  hcic_reg224:8;
    };
}lg_hcic_hcic_reg224_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg22b:8;
        RBus_UInt32  hcic_reg22a:8;
        RBus_UInt32  hcic_reg229:8;
        RBus_UInt32  hcic_reg228:8;
    };
}lg_hcic_hcic_reg228_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg22f:8;
        RBus_UInt32  hcic_reg22e:8;
        RBus_UInt32  hcic_reg22d:8;
        RBus_UInt32  hcic_reg22c:8;
    };
}lg_hcic_hcic_reg22c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg233:8;
        RBus_UInt32  hcic_reg232:8;
        RBus_UInt32  hcic_reg231:8;
        RBus_UInt32  hcic_reg230:8;
    };
}lg_hcic_hcic_reg230_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg237:8;
        RBus_UInt32  hcic_reg236:8;
        RBus_UInt32  hcic_reg235:8;
        RBus_UInt32  hcic_reg234:8;
    };
}lg_hcic_hcic_reg234_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg23b:8;
        RBus_UInt32  hcic_reg23a:8;
        RBus_UInt32  hcic_reg239:8;
        RBus_UInt32  hcic_reg238:8;
    };
}lg_hcic_hcic_reg238_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg23f:8;
        RBus_UInt32  hcic_reg23e:8;
        RBus_UInt32  hcic_reg23d:8;
        RBus_UInt32  hcic_reg23c:8;
    };
}lg_hcic_hcic_reg23c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg243:8;
        RBus_UInt32  hcic_reg242:8;
        RBus_UInt32  hcic_reg241:8;
        RBus_UInt32  hcic_reg240:8;
    };
}lg_hcic_hcic_reg240_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg247:8;
        RBus_UInt32  hcic_reg246:8;
        RBus_UInt32  hcic_reg245:8;
        RBus_UInt32  hcic_reg244:8;
    };
}lg_hcic_hcic_reg244_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg24b:8;
        RBus_UInt32  hcic_reg24a:8;
        RBus_UInt32  hcic_reg249:8;
        RBus_UInt32  hcic_reg248:8;
    };
}lg_hcic_hcic_reg248_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg24f:8;
        RBus_UInt32  hcic_reg24e:8;
        RBus_UInt32  hcic_reg24d:8;
        RBus_UInt32  hcic_reg24c:8;
    };
}lg_hcic_hcic_reg24c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg253:8;
        RBus_UInt32  hcic_reg252:8;
        RBus_UInt32  hcic_reg251:8;
        RBus_UInt32  hcic_reg250:8;
    };
}lg_hcic_hcic_reg250_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg257:8;
        RBus_UInt32  hcic_reg256:8;
        RBus_UInt32  hcic_reg255:8;
        RBus_UInt32  hcic_reg254:8;
    };
}lg_hcic_hcic_reg254_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg25b:8;
        RBus_UInt32  hcic_reg25a:8;
        RBus_UInt32  hcic_reg259:8;
        RBus_UInt32  hcic_reg258:8;
    };
}lg_hcic_hcic_reg258_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg25f:8;
        RBus_UInt32  hcic_reg25e:8;
        RBus_UInt32  hcic_reg25d:8;
        RBus_UInt32  hcic_reg25c:8;
    };
}lg_hcic_hcic_reg25c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg263:8;
        RBus_UInt32  hcic_reg262:8;
        RBus_UInt32  hcic_reg261:8;
        RBus_UInt32  hcic_reg260:8;
    };
}lg_hcic_hcic_reg260_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg267:8;
        RBus_UInt32  hcic_reg266:8;
        RBus_UInt32  hcic_reg265:8;
        RBus_UInt32  hcic_reg264:8;
    };
}lg_hcic_hcic_reg264_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg26b:8;
        RBus_UInt32  hcic_reg26a:8;
        RBus_UInt32  hcic_reg269:8;
        RBus_UInt32  hcic_reg268:8;
    };
}lg_hcic_hcic_reg268_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg26f:8;
        RBus_UInt32  hcic_reg26e:8;
        RBus_UInt32  hcic_reg26d:8;
        RBus_UInt32  hcic_reg26c:8;
    };
}lg_hcic_hcic_reg26c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg273:8;
        RBus_UInt32  hcic_reg272:8;
        RBus_UInt32  hcic_reg271:8;
        RBus_UInt32  hcic_reg270:8;
    };
}lg_hcic_hcic_reg270_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg277:8;
        RBus_UInt32  hcic_reg276:8;
        RBus_UInt32  hcic_reg275:8;
        RBus_UInt32  hcic_reg274:8;
    };
}lg_hcic_hcic_reg274_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg27b:8;
        RBus_UInt32  hcic_reg27a:8;
        RBus_UInt32  hcic_reg279:8;
        RBus_UInt32  hcic_reg278:8;
    };
}lg_hcic_hcic_reg278_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg27f:8;
        RBus_UInt32  hcic_reg27e:8;
        RBus_UInt32  hcic_reg27d:8;
        RBus_UInt32  hcic_reg27c:8;
    };
}lg_hcic_hcic_reg27c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg283:8;
        RBus_UInt32  hcic_reg282:8;
        RBus_UInt32  hcic_reg281:8;
        RBus_UInt32  hcic_reg280:8;
    };
}lg_hcic_hcic_reg280_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg287:8;
        RBus_UInt32  hcic_reg286:8;
        RBus_UInt32  hcic_reg285:8;
        RBus_UInt32  hcic_reg284:8;
    };
}lg_hcic_hcic_reg284_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg28b:8;
        RBus_UInt32  hcic_reg28a:8;
        RBus_UInt32  hcic_reg289:8;
        RBus_UInt32  hcic_reg288:8;
    };
}lg_hcic_hcic_reg288_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg28f:8;
        RBus_UInt32  hcic_reg28e:8;
        RBus_UInt32  hcic_reg28d:8;
        RBus_UInt32  hcic_reg28c:8;
    };
}lg_hcic_hcic_reg28c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg293:8;
        RBus_UInt32  hcic_reg292:8;
        RBus_UInt32  hcic_reg291:8;
        RBus_UInt32  hcic_reg290:8;
    };
}lg_hcic_hcic_reg290_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg297:8;
        RBus_UInt32  hcic_reg296:8;
        RBus_UInt32  hcic_reg295:8;
        RBus_UInt32  hcic_reg294:8;
    };
}lg_hcic_hcic_reg294_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg29b:8;
        RBus_UInt32  hcic_reg29a:8;
        RBus_UInt32  hcic_reg299:8;
        RBus_UInt32  hcic_reg298:8;
    };
}lg_hcic_hcic_reg298_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg29f:8;
        RBus_UInt32  hcic_reg29e:8;
        RBus_UInt32  hcic_reg29d:8;
        RBus_UInt32  hcic_reg29c:8;
    };
}lg_hcic_hcic_reg29c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2a3:8;
        RBus_UInt32  hcic_reg2a2:8;
        RBus_UInt32  hcic_reg2a1:8;
        RBus_UInt32  hcic_reg2a0:8;
    };
}lg_hcic_hcic_reg2a0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2a7:8;
        RBus_UInt32  hcic_reg2a6:8;
        RBus_UInt32  hcic_reg2a5:8;
        RBus_UInt32  hcic_reg2a4:8;
    };
}lg_hcic_hcic_reg2a4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2ab:8;
        RBus_UInt32  hcic_reg2aa:8;
        RBus_UInt32  hcic_reg2a9:8;
        RBus_UInt32  hcic_reg2a8:8;
    };
}lg_hcic_hcic_reg2a8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2af:8;
        RBus_UInt32  hcic_reg2ae:8;
        RBus_UInt32  hcic_reg2ad:8;
        RBus_UInt32  hcic_reg2ac:8;
    };
}lg_hcic_hcic_reg2ac_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2b3:8;
        RBus_UInt32  hcic_reg2b2:8;
        RBus_UInt32  hcic_reg2b1:8;
        RBus_UInt32  hcic_reg2b0:8;
    };
}lg_hcic_hcic_reg2b0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2b7:8;
        RBus_UInt32  hcic_reg2b6:8;
        RBus_UInt32  hcic_reg2b5:8;
        RBus_UInt32  hcic_reg2b4:8;
    };
}lg_hcic_hcic_reg2b4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hcic_reg2bb:8;
        RBus_UInt32  hcic_reg2ba:8;
        RBus_UInt32  hcic_reg2b9:8;
        RBus_UInt32  hcic_reg2b8:8;
    };
}lg_hcic_hcic_reg2b8_RBUS;




#endif 


#endif 
