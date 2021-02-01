/**
* @file rbusKME_TOPReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_KME_TOP_REG_H_
#define _RBUS_KME_TOP_REG_H_

#include "rbus_types.h"



//  KME_TOP Register Address
#define  KME_TOP_MEMC_DEBUG_MODE                                                 0x1809F000
#define  KME_TOP_MEMC_DEBUG_MODE_reg_addr                                        "0xB809F000"
#define  KME_TOP_MEMC_DEBUG_MODE_reg                                             0xB809F000
#define  KME_TOP_MEMC_DEBUG_MODE_inst_addr                                       "0x0000"
#define  set_KME_TOP_MEMC_DEBUG_MODE_reg(data)                                   (*((volatile unsigned int*)KME_TOP_MEMC_DEBUG_MODE_reg)=data)
#define  get_KME_TOP_MEMC_DEBUG_MODE_reg                                         (*((volatile unsigned int*)KME_TOP_MEMC_DEBUG_MODE_reg))
#define  KME_TOP_MEMC_DEBUG_MODE_debug_mode_shift                                (0)
#define  KME_TOP_MEMC_DEBUG_MODE_debug_mode_mask                                 (0x0000000F)
#define  KME_TOP_MEMC_DEBUG_MODE_debug_mode(data)                                (0x0000000F&(data))
#define  KME_TOP_MEMC_DEBUG_MODE_get_debug_mode(data)                            (0x0000000F&(data))

#define  KME_TOP_KME_BIST_MODE_0                                                 0x1809F010
#define  KME_TOP_KME_BIST_MODE_0_reg_addr                                        "0xB809F010"
#define  KME_TOP_KME_BIST_MODE_0_reg                                             0xB809F010
#define  KME_TOP_KME_BIST_MODE_0_inst_addr                                       "0x0001"
#define  set_KME_TOP_KME_BIST_MODE_0_reg(data)                                   (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_0_reg)=data)
#define  get_KME_TOP_KME_BIST_MODE_0_reg                                         (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_0_reg))
#define  KME_TOP_KME_BIST_MODE_0_kme_bist_mode0_shift                            (0)
#define  KME_TOP_KME_BIST_MODE_0_kme_bist_mode0_mask                             (0xFFFFFFFF)
#define  KME_TOP_KME_BIST_MODE_0_kme_bist_mode0(data)                            (0xFFFFFFFF&(data))
#define  KME_TOP_KME_BIST_MODE_0_get_kme_bist_mode0(data)                        (0xFFFFFFFF&(data))

#define  KME_TOP_KME_BIST_MODE_1                                                 0x1809F014
#define  KME_TOP_KME_BIST_MODE_1_reg_addr                                        "0xB809F014"
#define  KME_TOP_KME_BIST_MODE_1_reg                                             0xB809F014
#define  KME_TOP_KME_BIST_MODE_1_inst_addr                                       "0x0002"
#define  set_KME_TOP_KME_BIST_MODE_1_reg(data)                                   (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_1_reg)=data)
#define  get_KME_TOP_KME_BIST_MODE_1_reg                                         (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_1_reg))
#define  KME_TOP_KME_BIST_MODE_1_kme_bist_mode1_shift                            (0)
#define  KME_TOP_KME_BIST_MODE_1_kme_bist_mode1_mask                             (0xFFFFFFFF)
#define  KME_TOP_KME_BIST_MODE_1_kme_bist_mode1(data)                            (0xFFFFFFFF&(data))
#define  KME_TOP_KME_BIST_MODE_1_get_kme_bist_mode1(data)                        (0xFFFFFFFF&(data))

#define  KME_TOP_KME_BIST_MODE_2                                                 0x1809F018
#define  KME_TOP_KME_BIST_MODE_2_reg_addr                                        "0xB809F018"
#define  KME_TOP_KME_BIST_MODE_2_reg                                             0xB809F018
#define  KME_TOP_KME_BIST_MODE_2_inst_addr                                       "0x0003"
#define  set_KME_TOP_KME_BIST_MODE_2_reg(data)                                   (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_2_reg)=data)
#define  get_KME_TOP_KME_BIST_MODE_2_reg                                         (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_2_reg))
#define  KME_TOP_KME_BIST_MODE_2_kme_bist_mode2_shift                            (0)
#define  KME_TOP_KME_BIST_MODE_2_kme_bist_mode2_mask                             (0xFFFFFFFF)
#define  KME_TOP_KME_BIST_MODE_2_kme_bist_mode2(data)                            (0xFFFFFFFF&(data))
#define  KME_TOP_KME_BIST_MODE_2_get_kme_bist_mode2(data)                        (0xFFFFFFFF&(data))

#define  KME_TOP_KME_BIST_MODE_3                                                 0x1809F01C
#define  KME_TOP_KME_BIST_MODE_3_reg_addr                                        "0xB809F01C"
#define  KME_TOP_KME_BIST_MODE_3_reg                                             0xB809F01C
#define  KME_TOP_KME_BIST_MODE_3_inst_addr                                       "0x0004"
#define  set_KME_TOP_KME_BIST_MODE_3_reg(data)                                   (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_3_reg)=data)
#define  get_KME_TOP_KME_BIST_MODE_3_reg                                         (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_3_reg))
#define  KME_TOP_KME_BIST_MODE_3_kme_bist_mode3_shift                            (0)
#define  KME_TOP_KME_BIST_MODE_3_kme_bist_mode3_mask                             (0xFFFFFFFF)
#define  KME_TOP_KME_BIST_MODE_3_kme_bist_mode3(data)                            (0xFFFFFFFF&(data))
#define  KME_TOP_KME_BIST_MODE_3_get_kme_bist_mode3(data)                        (0xFFFFFFFF&(data))

#define  KME_TOP_KME_BIST_MODE_4                                                 0x1809F020
#define  KME_TOP_KME_BIST_MODE_4_reg_addr                                        "0xB809F020"
#define  KME_TOP_KME_BIST_MODE_4_reg                                             0xB809F020
#define  KME_TOP_KME_BIST_MODE_4_inst_addr                                       "0x0005"
#define  set_KME_TOP_KME_BIST_MODE_4_reg(data)                                   (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_4_reg)=data)
#define  get_KME_TOP_KME_BIST_MODE_4_reg                                         (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_4_reg))
#define  KME_TOP_KME_BIST_MODE_4_kme_bist_mode4_shift                            (0)
#define  KME_TOP_KME_BIST_MODE_4_kme_bist_mode4_mask                             (0xFFFFFFFF)
#define  KME_TOP_KME_BIST_MODE_4_kme_bist_mode4(data)                            (0xFFFFFFFF&(data))
#define  KME_TOP_KME_BIST_MODE_4_get_kme_bist_mode4(data)                        (0xFFFFFFFF&(data))

#define  KME_TOP_KME_BIST_MODE_5                                                 0x1809F024
#define  KME_TOP_KME_BIST_MODE_5_reg_addr                                        "0xB809F024"
#define  KME_TOP_KME_BIST_MODE_5_reg                                             0xB809F024
#define  KME_TOP_KME_BIST_MODE_5_inst_addr                                       "0x0006"
#define  set_KME_TOP_KME_BIST_MODE_5_reg(data)                                   (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_5_reg)=data)
#define  get_KME_TOP_KME_BIST_MODE_5_reg                                         (*((volatile unsigned int*)KME_TOP_KME_BIST_MODE_5_reg))
#define  KME_TOP_KME_BIST_MODE_5_kme_bist_mode5_shift                            (0)
#define  KME_TOP_KME_BIST_MODE_5_kme_bist_mode5_mask                             (0x00000FFF)
#define  KME_TOP_KME_BIST_MODE_5_kme_bist_mode5(data)                            (0x00000FFF&(data))
#define  KME_TOP_KME_BIST_MODE_5_get_kme_bist_mode5(data)                        (0x00000FFF&(data))

#define  KME_TOP_KPOST_BIST_MODE_0                                               0x1809F028
#define  KME_TOP_KPOST_BIST_MODE_0_reg_addr                                      "0xB809F028"
#define  KME_TOP_KPOST_BIST_MODE_0_reg                                           0xB809F028
#define  KME_TOP_KPOST_BIST_MODE_0_inst_addr                                     "0x0007"
#define  set_KME_TOP_KPOST_BIST_MODE_0_reg(data)                                 (*((volatile unsigned int*)KME_TOP_KPOST_BIST_MODE_0_reg)=data)
#define  get_KME_TOP_KPOST_BIST_MODE_0_reg                                       (*((volatile unsigned int*)KME_TOP_KPOST_BIST_MODE_0_reg))
#define  KME_TOP_KPOST_BIST_MODE_0_kpost_bist_mode0_shift                        (0)
#define  KME_TOP_KPOST_BIST_MODE_0_kpost_bist_mode0_mask                         (0x000007FF)
#define  KME_TOP_KPOST_BIST_MODE_0_kpost_bist_mode0(data)                        (0x000007FF&(data))
#define  KME_TOP_KPOST_BIST_MODE_0_get_kpost_bist_mode0(data)                    (0x000007FF&(data))

#define  KME_TOP_KME_DRF_BIST_MODE_0                                             0x1809F02C
#define  KME_TOP_KME_DRF_BIST_MODE_0_reg_addr                                    "0xB809F02C"
#define  KME_TOP_KME_DRF_BIST_MODE_0_reg                                         0xB809F02C
#define  KME_TOP_KME_DRF_BIST_MODE_0_inst_addr                                   "0x0008"
#define  set_KME_TOP_KME_DRF_BIST_MODE_0_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_0_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_MODE_0_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_0_reg))
#define  KME_TOP_KME_DRF_BIST_MODE_0_kme_drf_bist_mode0_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_MODE_0_kme_drf_bist_mode0_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_MODE_0_kme_drf_bist_mode0(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_MODE_0_get_kme_drf_bist_mode0(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_MODE_1                                             0x1809F030
#define  KME_TOP_KME_DRF_BIST_MODE_1_reg_addr                                    "0xB809F030"
#define  KME_TOP_KME_DRF_BIST_MODE_1_reg                                         0xB809F030
#define  KME_TOP_KME_DRF_BIST_MODE_1_inst_addr                                   "0x0009"
#define  set_KME_TOP_KME_DRF_BIST_MODE_1_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_1_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_MODE_1_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_1_reg))
#define  KME_TOP_KME_DRF_BIST_MODE_1_kme_drf_bist_mode1_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_MODE_1_kme_drf_bist_mode1_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_MODE_1_kme_drf_bist_mode1(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_MODE_1_get_kme_drf_bist_mode1(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_MODE_2                                             0x1809F034
#define  KME_TOP_KME_DRF_BIST_MODE_2_reg_addr                                    "0xB809F034"
#define  KME_TOP_KME_DRF_BIST_MODE_2_reg                                         0xB809F034
#define  KME_TOP_KME_DRF_BIST_MODE_2_inst_addr                                   "0x000A"
#define  set_KME_TOP_KME_DRF_BIST_MODE_2_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_2_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_MODE_2_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_2_reg))
#define  KME_TOP_KME_DRF_BIST_MODE_2_kme_drf_bist_mode2_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_MODE_2_kme_drf_bist_mode2_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_MODE_2_kme_drf_bist_mode2(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_MODE_2_get_kme_drf_bist_mode2(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_MODE_3                                             0x1809F038
#define  KME_TOP_KME_DRF_BIST_MODE_3_reg_addr                                    "0xB809F038"
#define  KME_TOP_KME_DRF_BIST_MODE_3_reg                                         0xB809F038
#define  KME_TOP_KME_DRF_BIST_MODE_3_inst_addr                                   "0x000B"
#define  set_KME_TOP_KME_DRF_BIST_MODE_3_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_3_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_MODE_3_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_3_reg))
#define  KME_TOP_KME_DRF_BIST_MODE_3_kme_drf_bist_mode3_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_MODE_3_kme_drf_bist_mode3_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_MODE_3_kme_drf_bist_mode3(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_MODE_3_get_kme_drf_bist_mode3(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_MODE_4                                             0x1809F03C
#define  KME_TOP_KME_DRF_BIST_MODE_4_reg_addr                                    "0xB809F03C"
#define  KME_TOP_KME_DRF_BIST_MODE_4_reg                                         0xB809F03C
#define  KME_TOP_KME_DRF_BIST_MODE_4_inst_addr                                   "0x000C"
#define  set_KME_TOP_KME_DRF_BIST_MODE_4_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_4_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_MODE_4_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_4_reg))
#define  KME_TOP_KME_DRF_BIST_MODE_4_kme_drf_bist_mode4_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_MODE_4_kme_drf_bist_mode4_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_MODE_4_kme_drf_bist_mode4(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_MODE_4_get_kme_drf_bist_mode4(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_MODE_5                                             0x1809F040
#define  KME_TOP_KME_DRF_BIST_MODE_5_reg_addr                                    "0xB809F040"
#define  KME_TOP_KME_DRF_BIST_MODE_5_reg                                         0xB809F040
#define  KME_TOP_KME_DRF_BIST_MODE_5_inst_addr                                   "0x000D"
#define  set_KME_TOP_KME_DRF_BIST_MODE_5_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_5_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_MODE_5_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_MODE_5_reg))
#define  KME_TOP_KME_DRF_BIST_MODE_5_kme_drf_bist_mode5_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_MODE_5_kme_drf_bist_mode5_mask                     (0x00000FFF)
#define  KME_TOP_KME_DRF_BIST_MODE_5_kme_drf_bist_mode5(data)                    (0x00000FFF&(data))
#define  KME_TOP_KME_DRF_BIST_MODE_5_get_kme_drf_bist_mode5(data)                (0x00000FFF&(data))

#define  KME_TOP_KPOST_DRF_BIST_MODE_0                                           0x1809F044
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_reg_addr                                  "0xB809F044"
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_reg                                       0xB809F044
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_inst_addr                                 "0x000E"
#define  set_KME_TOP_KPOST_DRF_BIST_MODE_0_reg(data)                             (*((volatile unsigned int*)KME_TOP_KPOST_DRF_BIST_MODE_0_reg)=data)
#define  get_KME_TOP_KPOST_DRF_BIST_MODE_0_reg                                   (*((volatile unsigned int*)KME_TOP_KPOST_DRF_BIST_MODE_0_reg))
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_kpost_drf_bist_mode0_shift                (0)
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_kpost_drf_bist_mode0_mask                 (0x000007FF)
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_kpost_drf_bist_mode0(data)                (0x000007FF&(data))
#define  KME_TOP_KPOST_DRF_BIST_MODE_0_get_kpost_drf_bist_mode0(data)            (0x000007FF&(data))

#define  KME_TOP_KME_DRF_TEST_RESUME_0                                           0x1809F048
#define  KME_TOP_KME_DRF_TEST_RESUME_0_reg_addr                                  "0xB809F048"
#define  KME_TOP_KME_DRF_TEST_RESUME_0_reg                                       0xB809F048
#define  KME_TOP_KME_DRF_TEST_RESUME_0_inst_addr                                 "0x000F"
#define  set_KME_TOP_KME_DRF_TEST_RESUME_0_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_0_reg)=data)
#define  get_KME_TOP_KME_DRF_TEST_RESUME_0_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_0_reg))
#define  KME_TOP_KME_DRF_TEST_RESUME_0_kme_drf_test_resume0_shift                (0)
#define  KME_TOP_KME_DRF_TEST_RESUME_0_kme_drf_test_resume0_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_TEST_RESUME_0_kme_drf_test_resume0(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_TEST_RESUME_0_get_kme_drf_test_resume0(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_TEST_RESUME_1                                           0x1809F04C
#define  KME_TOP_KME_DRF_TEST_RESUME_1_reg_addr                                  "0xB809F04C"
#define  KME_TOP_KME_DRF_TEST_RESUME_1_reg                                       0xB809F04C
#define  KME_TOP_KME_DRF_TEST_RESUME_1_inst_addr                                 "0x0010"
#define  set_KME_TOP_KME_DRF_TEST_RESUME_1_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_1_reg)=data)
#define  get_KME_TOP_KME_DRF_TEST_RESUME_1_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_1_reg))
#define  KME_TOP_KME_DRF_TEST_RESUME_1_kme_drf_test_resume1_shift                (0)
#define  KME_TOP_KME_DRF_TEST_RESUME_1_kme_drf_test_resume1_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_TEST_RESUME_1_kme_drf_test_resume1(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_TEST_RESUME_1_get_kme_drf_test_resume1(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_TEST_RESUME_2                                           0x1809F050
#define  KME_TOP_KME_DRF_TEST_RESUME_2_reg_addr                                  "0xB809F050"
#define  KME_TOP_KME_DRF_TEST_RESUME_2_reg                                       0xB809F050
#define  KME_TOP_KME_DRF_TEST_RESUME_2_inst_addr                                 "0x0011"
#define  set_KME_TOP_KME_DRF_TEST_RESUME_2_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_2_reg)=data)
#define  get_KME_TOP_KME_DRF_TEST_RESUME_2_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_2_reg))
#define  KME_TOP_KME_DRF_TEST_RESUME_2_kme_drf_test_resume2_shift                (0)
#define  KME_TOP_KME_DRF_TEST_RESUME_2_kme_drf_test_resume2_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_TEST_RESUME_2_kme_drf_test_resume2(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_TEST_RESUME_2_get_kme_drf_test_resume2(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_TEST_RESUME_3                                           0x1809F054
#define  KME_TOP_KME_DRF_TEST_RESUME_3_reg_addr                                  "0xB809F054"
#define  KME_TOP_KME_DRF_TEST_RESUME_3_reg                                       0xB809F054
#define  KME_TOP_KME_DRF_TEST_RESUME_3_inst_addr                                 "0x0012"
#define  set_KME_TOP_KME_DRF_TEST_RESUME_3_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_3_reg)=data)
#define  get_KME_TOP_KME_DRF_TEST_RESUME_3_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_3_reg))
#define  KME_TOP_KME_DRF_TEST_RESUME_3_kme_drf_test_resume3_shift                (0)
#define  KME_TOP_KME_DRF_TEST_RESUME_3_kme_drf_test_resume3_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_TEST_RESUME_3_kme_drf_test_resume3(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_TEST_RESUME_3_get_kme_drf_test_resume3(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_TEST_RESUME_4                                           0x1809F058
#define  KME_TOP_KME_DRF_TEST_RESUME_4_reg_addr                                  "0xB809F058"
#define  KME_TOP_KME_DRF_TEST_RESUME_4_reg                                       0xB809F058
#define  KME_TOP_KME_DRF_TEST_RESUME_4_inst_addr                                 "0x0013"
#define  set_KME_TOP_KME_DRF_TEST_RESUME_4_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_4_reg)=data)
#define  get_KME_TOP_KME_DRF_TEST_RESUME_4_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_4_reg))
#define  KME_TOP_KME_DRF_TEST_RESUME_4_kme_drf_test_resume4_shift                (0)
#define  KME_TOP_KME_DRF_TEST_RESUME_4_kme_drf_test_resume4_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_TEST_RESUME_4_kme_drf_test_resume4(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_TEST_RESUME_4_get_kme_drf_test_resume4(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_TEST_RESUME_5                                           0x1809F05C
#define  KME_TOP_KME_DRF_TEST_RESUME_5_reg_addr                                  "0xB809F05C"
#define  KME_TOP_KME_DRF_TEST_RESUME_5_reg                                       0xB809F05C
#define  KME_TOP_KME_DRF_TEST_RESUME_5_inst_addr                                 "0x0014"
#define  set_KME_TOP_KME_DRF_TEST_RESUME_5_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_5_reg)=data)
#define  get_KME_TOP_KME_DRF_TEST_RESUME_5_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_TEST_RESUME_5_reg))
#define  KME_TOP_KME_DRF_TEST_RESUME_5_kme_drf_test_resume5_shift                (0)
#define  KME_TOP_KME_DRF_TEST_RESUME_5_kme_drf_test_resume5_mask                 (0x00000FFF)
#define  KME_TOP_KME_DRF_TEST_RESUME_5_kme_drf_test_resume5(data)                (0x00000FFF&(data))
#define  KME_TOP_KME_DRF_TEST_RESUME_5_get_kme_drf_test_resume5(data)            (0x00000FFF&(data))

#define  KME_TOP_KPOST_DRF_TEST_RESUME_0                                         0x1809F060
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_reg_addr                                "0xB809F060"
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_reg                                     0xB809F060
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_inst_addr                               "0x0015"
#define  set_KME_TOP_KPOST_DRF_TEST_RESUME_0_reg(data)                           (*((volatile unsigned int*)KME_TOP_KPOST_DRF_TEST_RESUME_0_reg)=data)
#define  get_KME_TOP_KPOST_DRF_TEST_RESUME_0_reg                                 (*((volatile unsigned int*)KME_TOP_KPOST_DRF_TEST_RESUME_0_reg))
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_kpost_drf_test_resume0_shift            (0)
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_kpost_drf_test_resume0_mask             (0x000007FF)
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_kpost_drf_test_resume0(data)            (0x000007FF&(data))
#define  KME_TOP_KPOST_DRF_TEST_RESUME_0_get_kpost_drf_test_resume0(data)        (0x000007FF&(data))

#define  KME_TOP_KME_DRF_BIST_DONE_0                                             0x1809F064
#define  KME_TOP_KME_DRF_BIST_DONE_0_reg_addr                                    "0xB809F064"
#define  KME_TOP_KME_DRF_BIST_DONE_0_reg                                         0xB809F064
#define  KME_TOP_KME_DRF_BIST_DONE_0_inst_addr                                   "0x0016"
#define  set_KME_TOP_KME_DRF_BIST_DONE_0_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_0_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_DONE_0_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_0_reg))
#define  KME_TOP_KME_DRF_BIST_DONE_0_kme_drf_bist_done0_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_DONE_0_kme_drf_bist_done0_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_DONE_0_kme_drf_bist_done0(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_DONE_0_get_kme_drf_bist_done0(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_DONE_1                                             0x1809F068
#define  KME_TOP_KME_DRF_BIST_DONE_1_reg_addr                                    "0xB809F068"
#define  KME_TOP_KME_DRF_BIST_DONE_1_reg                                         0xB809F068
#define  KME_TOP_KME_DRF_BIST_DONE_1_inst_addr                                   "0x0017"
#define  set_KME_TOP_KME_DRF_BIST_DONE_1_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_1_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_DONE_1_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_1_reg))
#define  KME_TOP_KME_DRF_BIST_DONE_1_kme_drf_bist_done1_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_DONE_1_kme_drf_bist_done1_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_DONE_1_kme_drf_bist_done1(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_DONE_1_get_kme_drf_bist_done1(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_DONE_2                                             0x1809F06C
#define  KME_TOP_KME_DRF_BIST_DONE_2_reg_addr                                    "0xB809F06C"
#define  KME_TOP_KME_DRF_BIST_DONE_2_reg                                         0xB809F06C
#define  KME_TOP_KME_DRF_BIST_DONE_2_inst_addr                                   "0x0018"
#define  set_KME_TOP_KME_DRF_BIST_DONE_2_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_2_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_DONE_2_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_2_reg))
#define  KME_TOP_KME_DRF_BIST_DONE_2_kme_drf_bist_done2_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_DONE_2_kme_drf_bist_done2_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_DONE_2_kme_drf_bist_done2(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_DONE_2_get_kme_drf_bist_done2(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_DONE_3                                             0x1809F070
#define  KME_TOP_KME_DRF_BIST_DONE_3_reg_addr                                    "0xB809F070"
#define  KME_TOP_KME_DRF_BIST_DONE_3_reg                                         0xB809F070
#define  KME_TOP_KME_DRF_BIST_DONE_3_inst_addr                                   "0x0019"
#define  set_KME_TOP_KME_DRF_BIST_DONE_3_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_3_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_DONE_3_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_3_reg))
#define  KME_TOP_KME_DRF_BIST_DONE_3_kme_drf_bist_done3_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_DONE_3_kme_drf_bist_done3_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_DONE_3_kme_drf_bist_done3(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_DONE_3_get_kme_drf_bist_done3(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_DONE_4                                             0x1809F074
#define  KME_TOP_KME_DRF_BIST_DONE_4_reg_addr                                    "0xB809F074"
#define  KME_TOP_KME_DRF_BIST_DONE_4_reg                                         0xB809F074
#define  KME_TOP_KME_DRF_BIST_DONE_4_inst_addr                                   "0x001A"
#define  set_KME_TOP_KME_DRF_BIST_DONE_4_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_4_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_DONE_4_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_4_reg))
#define  KME_TOP_KME_DRF_BIST_DONE_4_kme_drf_bist_done4_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_DONE_4_kme_drf_bist_done4_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_DONE_4_kme_drf_bist_done4(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_DONE_4_get_kme_drf_bist_done4(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_DONE_5                                             0x1809F078
#define  KME_TOP_KME_DRF_BIST_DONE_5_reg_addr                                    "0xB809F078"
#define  KME_TOP_KME_DRF_BIST_DONE_5_reg                                         0xB809F078
#define  KME_TOP_KME_DRF_BIST_DONE_5_inst_addr                                   "0x001B"
#define  set_KME_TOP_KME_DRF_BIST_DONE_5_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_5_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_DONE_5_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_DONE_5_reg))
#define  KME_TOP_KME_DRF_BIST_DONE_5_kme_drf_bist_done5_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_DONE_5_kme_drf_bist_done5_mask                     (0x00000FFF)
#define  KME_TOP_KME_DRF_BIST_DONE_5_kme_drf_bist_done5(data)                    (0x00000FFF&(data))
#define  KME_TOP_KME_DRF_BIST_DONE_5_get_kme_drf_bist_done5(data)                (0x00000FFF&(data))

#define  KME_TOP_KPOST_DRF_BIST_DONE_0                                           0x1809F07C
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_reg_addr                                  "0xB809F07C"
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_reg                                       0xB809F07C
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_inst_addr                                 "0x001C"
#define  set_KME_TOP_KPOST_DRF_BIST_DONE_0_reg(data)                             (*((volatile unsigned int*)KME_TOP_KPOST_DRF_BIST_DONE_0_reg)=data)
#define  get_KME_TOP_KPOST_DRF_BIST_DONE_0_reg                                   (*((volatile unsigned int*)KME_TOP_KPOST_DRF_BIST_DONE_0_reg))
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_kpost_drf_bist_done0_shift                (0)
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_kpost_drf_bist_done0_mask                 (0x000007FF)
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_kpost_drf_bist_done0(data)                (0x000007FF&(data))
#define  KME_TOP_KPOST_DRF_BIST_DONE_0_get_kpost_drf_bist_done0(data)            (0x000007FF&(data))

#define  KME_TOP_KME_DRF_BIST_FAIL_0                                             0x1809F080
#define  KME_TOP_KME_DRF_BIST_FAIL_0_reg_addr                                    "0xB809F080"
#define  KME_TOP_KME_DRF_BIST_FAIL_0_reg                                         0xB809F080
#define  KME_TOP_KME_DRF_BIST_FAIL_0_inst_addr                                   "0x001D"
#define  set_KME_TOP_KME_DRF_BIST_FAIL_0_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_0_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_FAIL_0_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_0_reg))
#define  KME_TOP_KME_DRF_BIST_FAIL_0_kme_drf_bist_fail0_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_FAIL_0_kme_drf_bist_fail0_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_FAIL_0_kme_drf_bist_fail0(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_FAIL_0_get_kme_drf_bist_fail0(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_FAIL_1                                             0x1809F084
#define  KME_TOP_KME_DRF_BIST_FAIL_1_reg_addr                                    "0xB809F084"
#define  KME_TOP_KME_DRF_BIST_FAIL_1_reg                                         0xB809F084
#define  KME_TOP_KME_DRF_BIST_FAIL_1_inst_addr                                   "0x001E"
#define  set_KME_TOP_KME_DRF_BIST_FAIL_1_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_1_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_FAIL_1_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_1_reg))
#define  KME_TOP_KME_DRF_BIST_FAIL_1_kme_drf_bist_fail1_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_FAIL_1_kme_drf_bist_fail1_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_FAIL_1_kme_drf_bist_fail1(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_FAIL_1_get_kme_drf_bist_fail1(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_FAIL_2                                             0x1809F088
#define  KME_TOP_KME_DRF_BIST_FAIL_2_reg_addr                                    "0xB809F088"
#define  KME_TOP_KME_DRF_BIST_FAIL_2_reg                                         0xB809F088
#define  KME_TOP_KME_DRF_BIST_FAIL_2_inst_addr                                   "0x001F"
#define  set_KME_TOP_KME_DRF_BIST_FAIL_2_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_2_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_FAIL_2_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_2_reg))
#define  KME_TOP_KME_DRF_BIST_FAIL_2_kme_drf_bist_fail2_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_FAIL_2_kme_drf_bist_fail2_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_FAIL_2_kme_drf_bist_fail2(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_FAIL_2_get_kme_drf_bist_fail2(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_FAIL_3                                             0x1809F08C
#define  KME_TOP_KME_DRF_BIST_FAIL_3_reg_addr                                    "0xB809F08C"
#define  KME_TOP_KME_DRF_BIST_FAIL_3_reg                                         0xB809F08C
#define  KME_TOP_KME_DRF_BIST_FAIL_3_inst_addr                                   "0x0020"
#define  set_KME_TOP_KME_DRF_BIST_FAIL_3_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_3_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_FAIL_3_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_3_reg))
#define  KME_TOP_KME_DRF_BIST_FAIL_3_kme_drf_bist_fail3_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_FAIL_3_kme_drf_bist_fail3_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_FAIL_3_kme_drf_bist_fail3(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_FAIL_3_get_kme_drf_bist_fail3(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_FAIL_4                                             0x1809F090
#define  KME_TOP_KME_DRF_BIST_FAIL_4_reg_addr                                    "0xB809F090"
#define  KME_TOP_KME_DRF_BIST_FAIL_4_reg                                         0xB809F090
#define  KME_TOP_KME_DRF_BIST_FAIL_4_inst_addr                                   "0x0021"
#define  set_KME_TOP_KME_DRF_BIST_FAIL_4_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_4_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_FAIL_4_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_4_reg))
#define  KME_TOP_KME_DRF_BIST_FAIL_4_kme_drf_bist_fail4_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_FAIL_4_kme_drf_bist_fail4_mask                     (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_BIST_FAIL_4_kme_drf_bist_fail4(data)                    (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_BIST_FAIL_4_get_kme_drf_bist_fail4(data)                (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_BIST_FAIL_5                                             0x1809F094
#define  KME_TOP_KME_DRF_BIST_FAIL_5_reg_addr                                    "0xB809F094"
#define  KME_TOP_KME_DRF_BIST_FAIL_5_reg                                         0xB809F094
#define  KME_TOP_KME_DRF_BIST_FAIL_5_inst_addr                                   "0x0022"
#define  set_KME_TOP_KME_DRF_BIST_FAIL_5_reg(data)                               (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_5_reg)=data)
#define  get_KME_TOP_KME_DRF_BIST_FAIL_5_reg                                     (*((volatile unsigned int*)KME_TOP_KME_DRF_BIST_FAIL_5_reg))
#define  KME_TOP_KME_DRF_BIST_FAIL_5_kme_drf_bist_fail5_shift                    (0)
#define  KME_TOP_KME_DRF_BIST_FAIL_5_kme_drf_bist_fail5_mask                     (0x00000FFF)
#define  KME_TOP_KME_DRF_BIST_FAIL_5_kme_drf_bist_fail5(data)                    (0x00000FFF&(data))
#define  KME_TOP_KME_DRF_BIST_FAIL_5_get_kme_drf_bist_fail5(data)                (0x00000FFF&(data))

#define  KME_TOP_KPOST_DRF_BIST_FAIL_0                                           0x1809F098
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_reg_addr                                  "0xB809F098"
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_reg                                       0xB809F098
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_inst_addr                                 "0x0023"
#define  set_KME_TOP_KPOST_DRF_BIST_FAIL_0_reg(data)                             (*((volatile unsigned int*)KME_TOP_KPOST_DRF_BIST_FAIL_0_reg)=data)
#define  get_KME_TOP_KPOST_DRF_BIST_FAIL_0_reg                                   (*((volatile unsigned int*)KME_TOP_KPOST_DRF_BIST_FAIL_0_reg))
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_kpost_drf_bist_fail0_shift                (0)
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_kpost_drf_bist_fail0_mask                 (0x000007FF)
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_kpost_drf_bist_fail0(data)                (0x000007FF&(data))
#define  KME_TOP_KPOST_DRF_BIST_FAIL_0_get_kpost_drf_bist_fail0(data)            (0x000007FF&(data))

#define  KME_TOP_KME_DRF_START_PAUSE_0                                           0x1809F09C
#define  KME_TOP_KME_DRF_START_PAUSE_0_reg_addr                                  "0xB809F09C"
#define  KME_TOP_KME_DRF_START_PAUSE_0_reg                                       0xB809F09C
#define  KME_TOP_KME_DRF_START_PAUSE_0_inst_addr                                 "0x0024"
#define  set_KME_TOP_KME_DRF_START_PAUSE_0_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_0_reg)=data)
#define  get_KME_TOP_KME_DRF_START_PAUSE_0_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_0_reg))
#define  KME_TOP_KME_DRF_START_PAUSE_0_kme_drf_start_pause0_shift                (0)
#define  KME_TOP_KME_DRF_START_PAUSE_0_kme_drf_start_pause0_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_START_PAUSE_0_kme_drf_start_pause0(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_START_PAUSE_0_get_kme_drf_start_pause0(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_START_PAUSE_1                                           0x1809F0A0
#define  KME_TOP_KME_DRF_START_PAUSE_1_reg_addr                                  "0xB809F0A0"
#define  KME_TOP_KME_DRF_START_PAUSE_1_reg                                       0xB809F0A0
#define  KME_TOP_KME_DRF_START_PAUSE_1_inst_addr                                 "0x0025"
#define  set_KME_TOP_KME_DRF_START_PAUSE_1_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_1_reg)=data)
#define  get_KME_TOP_KME_DRF_START_PAUSE_1_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_1_reg))
#define  KME_TOP_KME_DRF_START_PAUSE_1_kme_drf_start_pause1_shift                (0)
#define  KME_TOP_KME_DRF_START_PAUSE_1_kme_drf_start_pause1_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_START_PAUSE_1_kme_drf_start_pause1(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_START_PAUSE_1_get_kme_drf_start_pause1(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_START_PAUSE_2                                           0x1809F0A4
#define  KME_TOP_KME_DRF_START_PAUSE_2_reg_addr                                  "0xB809F0A4"
#define  KME_TOP_KME_DRF_START_PAUSE_2_reg                                       0xB809F0A4
#define  KME_TOP_KME_DRF_START_PAUSE_2_inst_addr                                 "0x0026"
#define  set_KME_TOP_KME_DRF_START_PAUSE_2_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_2_reg)=data)
#define  get_KME_TOP_KME_DRF_START_PAUSE_2_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_2_reg))
#define  KME_TOP_KME_DRF_START_PAUSE_2_kme_drf_start_pause2_shift                (0)
#define  KME_TOP_KME_DRF_START_PAUSE_2_kme_drf_start_pause2_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_START_PAUSE_2_kme_drf_start_pause2(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_START_PAUSE_2_get_kme_drf_start_pause2(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_START_PAUSE_3                                           0x1809F0A8
#define  KME_TOP_KME_DRF_START_PAUSE_3_reg_addr                                  "0xB809F0A8"
#define  KME_TOP_KME_DRF_START_PAUSE_3_reg                                       0xB809F0A8
#define  KME_TOP_KME_DRF_START_PAUSE_3_inst_addr                                 "0x0027"
#define  set_KME_TOP_KME_DRF_START_PAUSE_3_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_3_reg)=data)
#define  get_KME_TOP_KME_DRF_START_PAUSE_3_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_3_reg))
#define  KME_TOP_KME_DRF_START_PAUSE_3_kme_drf_start_pause3_shift                (0)
#define  KME_TOP_KME_DRF_START_PAUSE_3_kme_drf_start_pause3_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_START_PAUSE_3_kme_drf_start_pause3(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_START_PAUSE_3_get_kme_drf_start_pause3(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_START_PAUSE_4                                           0x1809F0AC
#define  KME_TOP_KME_DRF_START_PAUSE_4_reg_addr                                  "0xB809F0AC"
#define  KME_TOP_KME_DRF_START_PAUSE_4_reg                                       0xB809F0AC
#define  KME_TOP_KME_DRF_START_PAUSE_4_inst_addr                                 "0x0028"
#define  set_KME_TOP_KME_DRF_START_PAUSE_4_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_4_reg)=data)
#define  get_KME_TOP_KME_DRF_START_PAUSE_4_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_4_reg))
#define  KME_TOP_KME_DRF_START_PAUSE_4_kme_drf_start_pause4_shift                (0)
#define  KME_TOP_KME_DRF_START_PAUSE_4_kme_drf_start_pause4_mask                 (0xFFFFFFFF)
#define  KME_TOP_KME_DRF_START_PAUSE_4_kme_drf_start_pause4(data)                (0xFFFFFFFF&(data))
#define  KME_TOP_KME_DRF_START_PAUSE_4_get_kme_drf_start_pause4(data)            (0xFFFFFFFF&(data))

#define  KME_TOP_KME_DRF_START_PAUSE_5                                           0x1809F0B0
#define  KME_TOP_KME_DRF_START_PAUSE_5_reg_addr                                  "0xB809F0B0"
#define  KME_TOP_KME_DRF_START_PAUSE_5_reg                                       0xB809F0B0
#define  KME_TOP_KME_DRF_START_PAUSE_5_inst_addr                                 "0x0029"
#define  set_KME_TOP_KME_DRF_START_PAUSE_5_reg(data)                             (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_5_reg)=data)
#define  get_KME_TOP_KME_DRF_START_PAUSE_5_reg                                   (*((volatile unsigned int*)KME_TOP_KME_DRF_START_PAUSE_5_reg))
#define  KME_TOP_KME_DRF_START_PAUSE_5_kme_drf_start_pause5_shift                (0)
#define  KME_TOP_KME_DRF_START_PAUSE_5_kme_drf_start_pause5_mask                 (0x00000FFF)
#define  KME_TOP_KME_DRF_START_PAUSE_5_kme_drf_start_pause5(data)                (0x00000FFF&(data))
#define  KME_TOP_KME_DRF_START_PAUSE_5_get_kme_drf_start_pause5(data)            (0x00000FFF&(data))

#define  KME_TOP_KPOST_DRF_START_PAUSE_0                                         0x1809F0B4
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_reg_addr                                "0xB809F0B4"
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_reg                                     0xB809F0B4
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_inst_addr                               "0x002A"
#define  set_KME_TOP_KPOST_DRF_START_PAUSE_0_reg(data)                           (*((volatile unsigned int*)KME_TOP_KPOST_DRF_START_PAUSE_0_reg)=data)
#define  get_KME_TOP_KPOST_DRF_START_PAUSE_0_reg                                 (*((volatile unsigned int*)KME_TOP_KPOST_DRF_START_PAUSE_0_reg))
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_kpost_drf_start_pause0_shift            (0)
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_kpost_drf_start_pause0_mask             (0x000007FF)
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_kpost_drf_start_pause0(data)            (0x000007FF&(data))
#define  KME_TOP_KPOST_DRF_START_PAUSE_0_get_kpost_drf_start_pause0(data)        (0x000007FF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======KME_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  debug_mode:4;
    };
}kme_top_memc_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode0:32;
    };
}kme_top_kme_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode1:32;
    };
}kme_top_kme_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode2:32;
    };
}kme_top_kme_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode3:32;
    };
}kme_top_kme_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode4:32;
    };
}kme_top_kme_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  kme_bist_mode5:12;
    };
}kme_top_kme_bist_mode_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpost_bist_mode0:11;
    };
}kme_top_kpost_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode0:32;
    };
}kme_top_kme_drf_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode1:32;
    };
}kme_top_kme_drf_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode2:32;
    };
}kme_top_kme_drf_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode3:32;
    };
}kme_top_kme_drf_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode4:32;
    };
}kme_top_kme_drf_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  kme_drf_bist_mode5:12;
    };
}kme_top_kme_drf_bist_mode_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpost_drf_bist_mode0:11;
    };
}kme_top_kpost_drf_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume0:32;
    };
}kme_top_kme_drf_test_resume_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume1:32;
    };
}kme_top_kme_drf_test_resume_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume2:32;
    };
}kme_top_kme_drf_test_resume_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume3:32;
    };
}kme_top_kme_drf_test_resume_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume4:32;
    };
}kme_top_kme_drf_test_resume_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  kme_drf_test_resume5:12;
    };
}kme_top_kme_drf_test_resume_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpost_drf_test_resume0:11;
    };
}kme_top_kpost_drf_test_resume_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done0:32;
    };
}kme_top_kme_drf_bist_done_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done1:32;
    };
}kme_top_kme_drf_bist_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done2:32;
    };
}kme_top_kme_drf_bist_done_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done3:32;
    };
}kme_top_kme_drf_bist_done_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done4:32;
    };
}kme_top_kme_drf_bist_done_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  kme_drf_bist_done5:12;
    };
}kme_top_kme_drf_bist_done_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpost_drf_bist_done0:11;
    };
}kme_top_kpost_drf_bist_done_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail0:32;
    };
}kme_top_kme_drf_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail1:32;
    };
}kme_top_kme_drf_bist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail2:32;
    };
}kme_top_kme_drf_bist_fail_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail3:32;
    };
}kme_top_kme_drf_bist_fail_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail4:32;
    };
}kme_top_kme_drf_bist_fail_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  kme_drf_bist_fail5:12;
    };
}kme_top_kme_drf_bist_fail_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpost_drf_bist_fail0:11;
    };
}kme_top_kpost_drf_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause0:32;
    };
}kme_top_kme_drf_start_pause_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause1:32;
    };
}kme_top_kme_drf_start_pause_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause2:32;
    };
}kme_top_kme_drf_start_pause_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause3:32;
    };
}kme_top_kme_drf_start_pause_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause4:32;
    };
}kme_top_kme_drf_start_pause_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  kme_drf_start_pause5:12;
    };
}kme_top_kme_drf_start_pause_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  kpost_drf_start_pause0:11;
    };
}kme_top_kpost_drf_start_pause_0_RBUS;

#else //apply LITTLE_ENDIAN

//======KME_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode:4;
        RBus_UInt32  res1:28;
    };
}kme_top_memc_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode0:32;
    };
}kme_top_kme_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode1:32;
    };
}kme_top_kme_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode2:32;
    };
}kme_top_kme_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode3:32;
    };
}kme_top_kme_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode4:32;
    };
}kme_top_kme_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_bist_mode5:12;
        RBus_UInt32  res1:20;
    };
}kme_top_kme_bist_mode_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpost_bist_mode0:11;
        RBus_UInt32  res1:21;
    };
}kme_top_kpost_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode0:32;
    };
}kme_top_kme_drf_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode1:32;
    };
}kme_top_kme_drf_bist_mode_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode2:32;
    };
}kme_top_kme_drf_bist_mode_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode3:32;
    };
}kme_top_kme_drf_bist_mode_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode4:32;
    };
}kme_top_kme_drf_bist_mode_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_mode5:12;
        RBus_UInt32  res1:20;
    };
}kme_top_kme_drf_bist_mode_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpost_drf_bist_mode0:11;
        RBus_UInt32  res1:21;
    };
}kme_top_kpost_drf_bist_mode_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume0:32;
    };
}kme_top_kme_drf_test_resume_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume1:32;
    };
}kme_top_kme_drf_test_resume_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume2:32;
    };
}kme_top_kme_drf_test_resume_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume3:32;
    };
}kme_top_kme_drf_test_resume_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume4:32;
    };
}kme_top_kme_drf_test_resume_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_test_resume5:12;
        RBus_UInt32  res1:20;
    };
}kme_top_kme_drf_test_resume_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpost_drf_test_resume0:11;
        RBus_UInt32  res1:21;
    };
}kme_top_kpost_drf_test_resume_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done0:32;
    };
}kme_top_kme_drf_bist_done_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done1:32;
    };
}kme_top_kme_drf_bist_done_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done2:32;
    };
}kme_top_kme_drf_bist_done_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done3:32;
    };
}kme_top_kme_drf_bist_done_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done4:32;
    };
}kme_top_kme_drf_bist_done_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_done5:12;
        RBus_UInt32  res1:20;
    };
}kme_top_kme_drf_bist_done_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpost_drf_bist_done0:11;
        RBus_UInt32  res1:21;
    };
}kme_top_kpost_drf_bist_done_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail0:32;
    };
}kme_top_kme_drf_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail1:32;
    };
}kme_top_kme_drf_bist_fail_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail2:32;
    };
}kme_top_kme_drf_bist_fail_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail3:32;
    };
}kme_top_kme_drf_bist_fail_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail4:32;
    };
}kme_top_kme_drf_bist_fail_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_bist_fail5:12;
        RBus_UInt32  res1:20;
    };
}kme_top_kme_drf_bist_fail_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpost_drf_bist_fail0:11;
        RBus_UInt32  res1:21;
    };
}kme_top_kpost_drf_bist_fail_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause0:32;
    };
}kme_top_kme_drf_start_pause_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause1:32;
    };
}kme_top_kme_drf_start_pause_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause2:32;
    };
}kme_top_kme_drf_start_pause_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause3:32;
    };
}kme_top_kme_drf_start_pause_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause4:32;
    };
}kme_top_kme_drf_start_pause_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kme_drf_start_pause5:12;
        RBus_UInt32  res1:20;
    };
}kme_top_kme_drf_start_pause_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  kpost_drf_start_pause0:11;
        RBus_UInt32  res1:21;
    };
}kme_top_kpost_drf_start_pause_0_RBUS;




#endif 


#endif 
