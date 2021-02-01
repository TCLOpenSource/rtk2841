/**
* @file rbusKMC_TOPReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_KMC_TOP_REG_H_
#define _RBUS_KMC_TOP_REG_H_

#include "rbus_types.h"



//  KMC_TOP Register Address
#define  KMC_TOP_KMC_BIST_MODE_0                                                 0x1809F100
#define  KMC_TOP_KMC_BIST_MODE_0_reg_addr                                        "0xB809F100"
#define  KMC_TOP_KMC_BIST_MODE_0_reg                                             0xB809F100
#define  KMC_TOP_KMC_BIST_MODE_0_inst_addr                                       "0x0000"
#define  set_KMC_TOP_KMC_BIST_MODE_0_reg(data)                                   (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_0_reg)=data)
#define  get_KMC_TOP_KMC_BIST_MODE_0_reg                                         (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_0_reg))
#define  KMC_TOP_KMC_BIST_MODE_0_kmc_bist_mode0_shift                            (0)
#define  KMC_TOP_KMC_BIST_MODE_0_kmc_bist_mode0_mask                             (0xFFFFFFFF)
#define  KMC_TOP_KMC_BIST_MODE_0_kmc_bist_mode0(data)                            (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_BIST_MODE_0_get_kmc_bist_mode0(data)                        (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_BIST_MODE_1                                                 0x1809F104
#define  KMC_TOP_KMC_BIST_MODE_1_reg_addr                                        "0xB809F104"
#define  KMC_TOP_KMC_BIST_MODE_1_reg                                             0xB809F104
#define  KMC_TOP_KMC_BIST_MODE_1_inst_addr                                       "0x0001"
#define  set_KMC_TOP_KMC_BIST_MODE_1_reg(data)                                   (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_1_reg)=data)
#define  get_KMC_TOP_KMC_BIST_MODE_1_reg                                         (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_1_reg))
#define  KMC_TOP_KMC_BIST_MODE_1_kmc_bist_mode1_shift                            (0)
#define  KMC_TOP_KMC_BIST_MODE_1_kmc_bist_mode1_mask                             (0xFFFFFFFF)
#define  KMC_TOP_KMC_BIST_MODE_1_kmc_bist_mode1(data)                            (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_BIST_MODE_1_get_kmc_bist_mode1(data)                        (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_BIST_MODE_2                                                 0x1809F108
#define  KMC_TOP_KMC_BIST_MODE_2_reg_addr                                        "0xB809F108"
#define  KMC_TOP_KMC_BIST_MODE_2_reg                                             0xB809F108
#define  KMC_TOP_KMC_BIST_MODE_2_inst_addr                                       "0x0002"
#define  set_KMC_TOP_KMC_BIST_MODE_2_reg(data)                                   (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_2_reg)=data)
#define  get_KMC_TOP_KMC_BIST_MODE_2_reg                                         (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_2_reg))
#define  KMC_TOP_KMC_BIST_MODE_2_kmc_bist_mode2_shift                            (0)
#define  KMC_TOP_KMC_BIST_MODE_2_kmc_bist_mode2_mask                             (0xFFFFFFFF)
#define  KMC_TOP_KMC_BIST_MODE_2_kmc_bist_mode2(data)                            (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_BIST_MODE_2_get_kmc_bist_mode2(data)                        (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_BIST_MODE_3                                                 0x1809F10C
#define  KMC_TOP_KMC_BIST_MODE_3_reg_addr                                        "0xB809F10C"
#define  KMC_TOP_KMC_BIST_MODE_3_reg                                             0xB809F10C
#define  KMC_TOP_KMC_BIST_MODE_3_inst_addr                                       "0x0003"
#define  set_KMC_TOP_KMC_BIST_MODE_3_reg(data)                                   (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_3_reg)=data)
#define  get_KMC_TOP_KMC_BIST_MODE_3_reg                                         (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_3_reg))
#define  KMC_TOP_KMC_BIST_MODE_3_kmc_bist_mode3_shift                            (0)
#define  KMC_TOP_KMC_BIST_MODE_3_kmc_bist_mode3_mask                             (0xFFFFFFFF)
#define  KMC_TOP_KMC_BIST_MODE_3_kmc_bist_mode3(data)                            (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_BIST_MODE_3_get_kmc_bist_mode3(data)                        (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_BIST_MODE_4                                                 0x1809F110
#define  KMC_TOP_KMC_BIST_MODE_4_reg_addr                                        "0xB809F110"
#define  KMC_TOP_KMC_BIST_MODE_4_reg                                             0xB809F110
#define  KMC_TOP_KMC_BIST_MODE_4_inst_addr                                       "0x0004"
#define  set_KMC_TOP_KMC_BIST_MODE_4_reg(data)                                   (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_4_reg)=data)
#define  get_KMC_TOP_KMC_BIST_MODE_4_reg                                         (*((volatile unsigned int*)KMC_TOP_KMC_BIST_MODE_4_reg))
#define  KMC_TOP_KMC_BIST_MODE_4_kmc_bist_mode4_shift                            (0)
#define  KMC_TOP_KMC_BIST_MODE_4_kmc_bist_mode4_mask                             (0x001FFFFF)
#define  KMC_TOP_KMC_BIST_MODE_4_kmc_bist_mode4(data)                            (0x001FFFFF&(data))
#define  KMC_TOP_KMC_BIST_MODE_4_get_kmc_bist_mode4(data)                        (0x001FFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_MODE_0                                             0x1809F114
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_reg_addr                                    "0xB809F114"
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_reg                                         0xB809F114
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_inst_addr                                   "0x0005"
#define  set_KMC_TOP_KMC_DRF_BIST_MODE_0_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_0_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_MODE_0_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_0_reg))
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_kmc_drf_bist_mode0_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_kmc_drf_bist_mode0_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_kmc_drf_bist_mode0(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_MODE_0_get_kmc_drf_bist_mode0(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_MODE_1                                             0x1809F118
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_reg_addr                                    "0xB809F118"
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_reg                                         0xB809F118
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_inst_addr                                   "0x0006"
#define  set_KMC_TOP_KMC_DRF_BIST_MODE_1_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_1_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_MODE_1_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_1_reg))
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_kmc_drf_bist_mode1_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_kmc_drf_bist_mode1_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_kmc_drf_bist_mode1(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_MODE_1_get_kmc_drf_bist_mode1(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_MODE_2                                             0x1809F11C
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_reg_addr                                    "0xB809F11C"
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_reg                                         0xB809F11C
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_inst_addr                                   "0x0007"
#define  set_KMC_TOP_KMC_DRF_BIST_MODE_2_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_2_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_MODE_2_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_2_reg))
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_kmc_drf_bist_mode2_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_kmc_drf_bist_mode2_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_kmc_drf_bist_mode2(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_MODE_2_get_kmc_drf_bist_mode2(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_MODE_3                                             0x1809F120
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_reg_addr                                    "0xB809F120"
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_reg                                         0xB809F120
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_inst_addr                                   "0x0008"
#define  set_KMC_TOP_KMC_DRF_BIST_MODE_3_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_3_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_MODE_3_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_3_reg))
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_kmc_drf_bist_mode3_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_kmc_drf_bist_mode3_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_kmc_drf_bist_mode3(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_MODE_3_get_kmc_drf_bist_mode3(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_MODE_4                                             0x1809F124
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_reg_addr                                    "0xB809F124"
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_reg                                         0xB809F124
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_inst_addr                                   "0x0009"
#define  set_KMC_TOP_KMC_DRF_BIST_MODE_4_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_4_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_MODE_4_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_MODE_4_reg))
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_kmc_drf_bist_mode4_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_kmc_drf_bist_mode4_mask                     (0x001FFFFF)
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_kmc_drf_bist_mode4(data)                    (0x001FFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_MODE_4_get_kmc_drf_bist_mode4(data)                (0x001FFFFF&(data))

#define  KMC_TOP_KMC_DRF_TEST_RESUME_0                                           0x1809F128
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_reg_addr                                  "0xB809F128"
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_reg                                       0xB809F128
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_inst_addr                                 "0x000A"
#define  set_KMC_TOP_KMC_DRF_TEST_RESUME_0_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_0_reg)=data)
#define  get_KMC_TOP_KMC_DRF_TEST_RESUME_0_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_0_reg))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_kmc_drf_test_resume0_shift                (0)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_kmc_drf_test_resume0_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_kmc_drf_test_resume0(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_0_get_kmc_drf_test_resume0(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_TEST_RESUME_1                                           0x1809F12C
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_reg_addr                                  "0xB809F12C"
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_reg                                       0xB809F12C
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_inst_addr                                 "0x000B"
#define  set_KMC_TOP_KMC_DRF_TEST_RESUME_1_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_1_reg)=data)
#define  get_KMC_TOP_KMC_DRF_TEST_RESUME_1_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_1_reg))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_kmc_drf_test_resume1_shift                (0)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_kmc_drf_test_resume1_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_kmc_drf_test_resume1(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_1_get_kmc_drf_test_resume1(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_TEST_RESUME_2                                           0x1809F130
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_reg_addr                                  "0xB809F130"
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_reg                                       0xB809F130
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_inst_addr                                 "0x000C"
#define  set_KMC_TOP_KMC_DRF_TEST_RESUME_2_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_2_reg)=data)
#define  get_KMC_TOP_KMC_DRF_TEST_RESUME_2_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_2_reg))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_kmc_drf_test_resume2_shift                (0)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_kmc_drf_test_resume2_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_kmc_drf_test_resume2(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_2_get_kmc_drf_test_resume2(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_TEST_RESUME_3                                           0x1809F134
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_reg_addr                                  "0xB809F134"
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_reg                                       0xB809F134
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_inst_addr                                 "0x000D"
#define  set_KMC_TOP_KMC_DRF_TEST_RESUME_3_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_3_reg)=data)
#define  get_KMC_TOP_KMC_DRF_TEST_RESUME_3_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_3_reg))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_kmc_drf_test_resume3_shift                (0)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_kmc_drf_test_resume3_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_kmc_drf_test_resume3(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_3_get_kmc_drf_test_resume3(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_TEST_RESUME_4                                           0x1809F138
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_reg_addr                                  "0xB809F138"
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_reg                                       0xB809F138
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_inst_addr                                 "0x000E"
#define  set_KMC_TOP_KMC_DRF_TEST_RESUME_4_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_4_reg)=data)
#define  get_KMC_TOP_KMC_DRF_TEST_RESUME_4_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_TEST_RESUME_4_reg))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_kmc_drf_test_resume4_shift                (0)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_kmc_drf_test_resume4_mask                 (0x001FFFFF)
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_kmc_drf_test_resume4(data)                (0x001FFFFF&(data))
#define  KMC_TOP_KMC_DRF_TEST_RESUME_4_get_kmc_drf_test_resume4(data)            (0x001FFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_DONE_0                                             0x1809F13C
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_reg_addr                                    "0xB809F13C"
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_reg                                         0xB809F13C
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_inst_addr                                   "0x000F"
#define  set_KMC_TOP_KMC_DRF_BIST_DONE_0_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_0_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_DONE_0_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_0_reg))
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_kmc_drf_bist_done0_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_kmc_drf_bist_done0_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_kmc_drf_bist_done0(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_DONE_0_get_kmc_drf_bist_done0(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_DONE_1                                             0x1809F140
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_reg_addr                                    "0xB809F140"
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_reg                                         0xB809F140
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_inst_addr                                   "0x0010"
#define  set_KMC_TOP_KMC_DRF_BIST_DONE_1_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_1_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_DONE_1_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_1_reg))
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_kmc_drf_bist_done1_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_kmc_drf_bist_done1_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_kmc_drf_bist_done1(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_DONE_1_get_kmc_drf_bist_done1(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_DONE_2                                             0x1809F144
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_reg_addr                                    "0xB809F144"
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_reg                                         0xB809F144
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_inst_addr                                   "0x0011"
#define  set_KMC_TOP_KMC_DRF_BIST_DONE_2_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_2_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_DONE_2_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_2_reg))
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_kmc_drf_bist_done2_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_kmc_drf_bist_done2_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_kmc_drf_bist_done2(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_DONE_2_get_kmc_drf_bist_done2(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_DONE_3                                             0x1809F148
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_reg_addr                                    "0xB809F148"
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_reg                                         0xB809F148
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_inst_addr                                   "0x0012"
#define  set_KMC_TOP_KMC_DRF_BIST_DONE_3_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_3_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_DONE_3_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_3_reg))
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_kmc_drf_bist_done3_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_kmc_drf_bist_done3_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_kmc_drf_bist_done3(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_DONE_3_get_kmc_drf_bist_done3(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_DONE_4                                             0x1809F14C
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_reg_addr                                    "0xB809F14C"
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_reg                                         0xB809F14C
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_inst_addr                                   "0x0013"
#define  set_KMC_TOP_KMC_DRF_BIST_DONE_4_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_4_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_DONE_4_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_DONE_4_reg))
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_kmc_drf_bist_done4_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_kmc_drf_bist_done4_mask                     (0x001FFFFF)
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_kmc_drf_bist_done4(data)                    (0x001FFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_DONE_4_get_kmc_drf_bist_done4(data)                (0x001FFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_FAIL_0                                             0x1809F150
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_reg_addr                                    "0xB809F150"
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_reg                                         0xB809F150
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_inst_addr                                   "0x0014"
#define  set_KMC_TOP_KMC_DRF_BIST_FAIL_0_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_0_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_FAIL_0_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_0_reg))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_kmc_drf_bist_fail0_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_kmc_drf_bist_fail0_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_kmc_drf_bist_fail0(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_0_get_kmc_drf_bist_fail0(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_FAIL_1                                             0x1809F154
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_reg_addr                                    "0xB809F154"
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_reg                                         0xB809F154
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_inst_addr                                   "0x0015"
#define  set_KMC_TOP_KMC_DRF_BIST_FAIL_1_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_1_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_FAIL_1_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_1_reg))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_kmc_drf_bist_fail1_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_kmc_drf_bist_fail1_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_kmc_drf_bist_fail1(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_1_get_kmc_drf_bist_fail1(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_FAIL_2                                             0x1809F158
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_reg_addr                                    "0xB809F158"
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_reg                                         0xB809F158
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_inst_addr                                   "0x0016"
#define  set_KMC_TOP_KMC_DRF_BIST_FAIL_2_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_2_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_FAIL_2_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_2_reg))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_kmc_drf_bist_fail2_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_kmc_drf_bist_fail2_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_kmc_drf_bist_fail2(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_2_get_kmc_drf_bist_fail2(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_FAIL_3                                             0x1809F15C
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_reg_addr                                    "0xB809F15C"
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_reg                                         0xB809F15C
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_inst_addr                                   "0x0017"
#define  set_KMC_TOP_KMC_DRF_BIST_FAIL_3_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_3_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_FAIL_3_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_3_reg))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_kmc_drf_bist_fail3_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_kmc_drf_bist_fail3_mask                     (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_kmc_drf_bist_fail3(data)                    (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_3_get_kmc_drf_bist_fail3(data)                (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_BIST_FAIL_4                                             0x1809F160
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_reg_addr                                    "0xB809F160"
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_reg                                         0xB809F160
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_inst_addr                                   "0x0018"
#define  set_KMC_TOP_KMC_DRF_BIST_FAIL_4_reg(data)                               (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_4_reg)=data)
#define  get_KMC_TOP_KMC_DRF_BIST_FAIL_4_reg                                     (*((volatile unsigned int*)KMC_TOP_KMC_DRF_BIST_FAIL_4_reg))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_kmc_drf_bist_fail4_shift                    (0)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_kmc_drf_bist_fail4_mask                     (0x001FFFFF)
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_kmc_drf_bist_fail4(data)                    (0x001FFFFF&(data))
#define  KMC_TOP_KMC_DRF_BIST_FAIL_4_get_kmc_drf_bist_fail4(data)                (0x001FFFFF&(data))

#define  KMC_TOP_KMC_DRF_START_PAUSE_0                                           0x1809F164
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_reg_addr                                  "0xB809F164"
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_reg                                       0xB809F164
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_inst_addr                                 "0x0019"
#define  set_KMC_TOP_KMC_DRF_START_PAUSE_0_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_0_reg)=data)
#define  get_KMC_TOP_KMC_DRF_START_PAUSE_0_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_0_reg))
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_kmc_drf_start_pause0_shift                (0)
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_kmc_drf_start_pause0_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_kmc_drf_start_pause0(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_START_PAUSE_0_get_kmc_drf_start_pause0(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_START_PAUSE_1                                           0x1809F168
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_reg_addr                                  "0xB809F168"
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_reg                                       0xB809F168
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_inst_addr                                 "0x001A"
#define  set_KMC_TOP_KMC_DRF_START_PAUSE_1_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_1_reg)=data)
#define  get_KMC_TOP_KMC_DRF_START_PAUSE_1_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_1_reg))
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_kmc_drf_start_pause1_shift                (0)
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_kmc_drf_start_pause1_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_kmc_drf_start_pause1(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_START_PAUSE_1_get_kmc_drf_start_pause1(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_START_PAUSE_2                                           0x1809F16C
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_reg_addr                                  "0xB809F16C"
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_reg                                       0xB809F16C
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_inst_addr                                 "0x001B"
#define  set_KMC_TOP_KMC_DRF_START_PAUSE_2_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_2_reg)=data)
#define  get_KMC_TOP_KMC_DRF_START_PAUSE_2_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_2_reg))
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_kmc_drf_start_pause2_shift                (0)
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_kmc_drf_start_pause2_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_kmc_drf_start_pause2(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_START_PAUSE_2_get_kmc_drf_start_pause2(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_START_PAUSE_3                                           0x1809F170
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_reg_addr                                  "0xB809F170"
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_reg                                       0xB809F170
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_inst_addr                                 "0x001C"
#define  set_KMC_TOP_KMC_DRF_START_PAUSE_3_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_3_reg)=data)
#define  get_KMC_TOP_KMC_DRF_START_PAUSE_3_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_3_reg))
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_kmc_drf_start_pause3_shift                (0)
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_kmc_drf_start_pause3_mask                 (0xFFFFFFFF)
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_kmc_drf_start_pause3(data)                (0xFFFFFFFF&(data))
#define  KMC_TOP_KMC_DRF_START_PAUSE_3_get_kmc_drf_start_pause3(data)            (0xFFFFFFFF&(data))

#define  KMC_TOP_KMC_DRF_START_PAUSE_4                                           0x1809F174
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_reg_addr                                  "0xB809F174"
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_reg                                       0xB809F174
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_inst_addr                                 "0x001D"
#define  set_KMC_TOP_KMC_DRF_START_PAUSE_4_reg(data)                             (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_4_reg)=data)
#define  get_KMC_TOP_KMC_DRF_START_PAUSE_4_reg                                   (*((volatile unsigned int*)KMC_TOP_KMC_DRF_START_PAUSE_4_reg))
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_kmc_drf_start_pause4_shift                (0)
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_kmc_drf_start_pause4_mask                 (0x001FFFFF)
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_kmc_drf_start_pause4(data)                (0x001FFFFF&(data))
#define  KMC_TOP_KMC_DRF_START_PAUSE_4_get_kmc_drf_start_pause4(data)            (0x001FFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======KMC_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode0:32;
    };
}kmc_top_kmc_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode1:32;
    };
}kmc_top_kmc_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode2:32;
    };
}kmc_top_kmc_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode3:32;
    };
}kmc_top_kmc_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  kmc_bist_mode4:21;
    };
}kmc_top_kmc_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode0:32;
    };
}kmc_top_kmc_drf_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode1:32;
    };
}kmc_top_kmc_drf_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode2:32;
    };
}kmc_top_kmc_drf_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode3:32;
    };
}kmc_top_kmc_drf_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  kmc_drf_bist_mode4:21;
    };
}kmc_top_kmc_drf_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume0:32;
    };
}kmc_top_kmc_drf_test_resume_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume1:32;
    };
}kmc_top_kmc_drf_test_resume_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume2:32;
    };
}kmc_top_kmc_drf_test_resume_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume3:32;
    };
}kmc_top_kmc_drf_test_resume_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  kmc_drf_test_resume4:21;
    };
}kmc_top_kmc_drf_test_resume_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done0:32;
    };
}kmc_top_kmc_drf_bist_done_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done1:32;
    };
}kmc_top_kmc_drf_bist_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done2:32;
    };
}kmc_top_kmc_drf_bist_done_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done3:32;
    };
}kmc_top_kmc_drf_bist_done_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  kmc_drf_bist_done4:21;
    };
}kmc_top_kmc_drf_bist_done_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail0:32;
    };
}kmc_top_kmc_drf_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail1:32;
    };
}kmc_top_kmc_drf_bist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail2:32;
    };
}kmc_top_kmc_drf_bist_fail_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail3:32;
    };
}kmc_top_kmc_drf_bist_fail_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  kmc_drf_bist_fail4:21;
    };
}kmc_top_kmc_drf_bist_fail_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause0:32;
    };
}kmc_top_kmc_drf_start_pause_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause1:32;
    };
}kmc_top_kmc_drf_start_pause_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause2:32;
    };
}kmc_top_kmc_drf_start_pause_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause3:32;
    };
}kmc_top_kmc_drf_start_pause_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  kmc_drf_start_pause4:21;
    };
}kmc_top_kmc_drf_start_pause_4_RBUS;

#else //apply LITTLE_ENDIAN

//======KMC_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode0:32;
    };
}kmc_top_kmc_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode1:32;
    };
}kmc_top_kmc_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode2:32;
    };
}kmc_top_kmc_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode3:32;
    };
}kmc_top_kmc_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_bist_mode4:21;
        RBus_UInt32  res1:11;
    };
}kmc_top_kmc_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode0:32;
    };
}kmc_top_kmc_drf_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode1:32;
    };
}kmc_top_kmc_drf_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode2:32;
    };
}kmc_top_kmc_drf_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode3:32;
    };
}kmc_top_kmc_drf_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_mode4:21;
        RBus_UInt32  res1:11;
    };
}kmc_top_kmc_drf_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume0:32;
    };
}kmc_top_kmc_drf_test_resume_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume1:32;
    };
}kmc_top_kmc_drf_test_resume_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume2:32;
    };
}kmc_top_kmc_drf_test_resume_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume3:32;
    };
}kmc_top_kmc_drf_test_resume_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_test_resume4:21;
        RBus_UInt32  res1:11;
    };
}kmc_top_kmc_drf_test_resume_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done0:32;
    };
}kmc_top_kmc_drf_bist_done_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done1:32;
    };
}kmc_top_kmc_drf_bist_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done2:32;
    };
}kmc_top_kmc_drf_bist_done_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done3:32;
    };
}kmc_top_kmc_drf_bist_done_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_done4:21;
        RBus_UInt32  res1:11;
    };
}kmc_top_kmc_drf_bist_done_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail0:32;
    };
}kmc_top_kmc_drf_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail1:32;
    };
}kmc_top_kmc_drf_bist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail2:32;
    };
}kmc_top_kmc_drf_bist_fail_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail3:32;
    };
}kmc_top_kmc_drf_bist_fail_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_bist_fail4:21;
        RBus_UInt32  res1:11;
    };
}kmc_top_kmc_drf_bist_fail_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause0:32;
    };
}kmc_top_kmc_drf_start_pause_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause1:32;
    };
}kmc_top_kmc_drf_start_pause_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause2:32;
    };
}kmc_top_kmc_drf_start_pause_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause3:32;
    };
}kmc_top_kmc_drf_start_pause_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kmc_drf_start_pause4:21;
        RBus_UInt32  res1:11;
    };
}kmc_top_kmc_drf_start_pause_4_RBUS;




#endif 


#endif 
