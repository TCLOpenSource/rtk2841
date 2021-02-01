/**
* @file Mac5_VE_FME_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_FME_REG_H_
#define _RBUS_FME_REG_H_

#include "rbus_types.h"



//  FME Register Address
#define  FME_comm                                                                0x1800F000
#define  FME_comm_reg_addr                                                       "0xB800F000"
#define  FME_comm_reg                                                            0xB800F000
#define  FME_comm_inst_addr                                                      "0x0000"
#define  set_FME_comm_reg(data)                                                  (*((volatile unsigned int*)FME_comm_reg)=data)
#define  get_FME_comm_reg                                                        (*((volatile unsigned int*)FME_comm_reg))
#define  FME_comm_encodetype_shift                                               (6)
#define  FME_comm_enablemvc_shift                                                (5)
#define  FME_comm_pictype_shift                                                  (3)
#define  FME_comm_firstmbofpic_shift                                             (2)
#define  FME_comm_lastmbofslice_shift                                            (1)
#define  FME_comm_firstmbofslice_shift                                           (0)
#define  FME_comm_encodetype_mask                                                (0x000000C0)
#define  FME_comm_enablemvc_mask                                                 (0x00000020)
#define  FME_comm_pictype_mask                                                   (0x00000018)
#define  FME_comm_firstmbofpic_mask                                              (0x00000004)
#define  FME_comm_lastmbofslice_mask                                             (0x00000002)
#define  FME_comm_firstmbofslice_mask                                            (0x00000001)
#define  FME_comm_encodetype(data)                                               (0x000000C0&((data)<<6))
#define  FME_comm_enablemvc(data)                                                (0x00000020&((data)<<5))
#define  FME_comm_pictype(data)                                                  (0x00000018&((data)<<3))
#define  FME_comm_firstmbofpic(data)                                             (0x00000004&((data)<<2))
#define  FME_comm_lastmbofslice(data)                                            (0x00000002&((data)<<1))
#define  FME_comm_firstmbofslice(data)                                           (0x00000001&(data))
#define  FME_comm_get_encodetype(data)                                           ((0x000000C0&(data))>>6)
#define  FME_comm_get_enablemvc(data)                                            ((0x00000020&(data))>>5)
#define  FME_comm_get_pictype(data)                                              ((0x00000018&(data))>>3)
#define  FME_comm_get_firstmbofpic(data)                                         ((0x00000004&(data))>>2)
#define  FME_comm_get_lastmbofslice(data)                                        ((0x00000002&(data))>>1)
#define  FME_comm_get_firstmbofslice(data)                                       (0x00000001&(data))

#define  FME_ctrl                                                                0x1800F004
#define  FME_ctrl_reg_addr                                                       "0xB800F004"
#define  FME_ctrl_reg                                                            0xB800F004
#define  FME_ctrl_inst_addr                                                      "0x0001"
#define  set_FME_ctrl_reg(data)                                                  (*((volatile unsigned int*)FME_ctrl_reg)=data)
#define  get_FME_ctrl_reg                                                        (*((volatile unsigned int*)FME_ctrl_reg))
#define  FME_ctrl_hardware_shift                                                 (12)
#define  FME_ctrl_disable16x16bidir_shift                                        (4)
#define  FME_ctrl_disable8x8bidir_shift                                          (3)
#define  FME_ctrl_only16x16_shift                                                (2)
#define  FME_ctrl_search_shift                                                   (0)
#define  FME_ctrl_hardware_mask                                                  (0xFFFFF000)
#define  FME_ctrl_disable16x16bidir_mask                                         (0x00000010)
#define  FME_ctrl_disable8x8bidir_mask                                           (0x00000008)
#define  FME_ctrl_only16x16_mask                                                 (0x00000004)
#define  FME_ctrl_search_mask                                                    (0x00000003)
#define  FME_ctrl_hardware(data)                                                 (0xFFFFF000&((data)<<12))
#define  FME_ctrl_disable16x16bidir(data)                                        (0x00000010&((data)<<4))
#define  FME_ctrl_disable8x8bidir(data)                                          (0x00000008&((data)<<3))
#define  FME_ctrl_only16x16(data)                                                (0x00000004&((data)<<2))
#define  FME_ctrl_search(data)                                                   (0x00000003&(data))
#define  FME_ctrl_get_hardware(data)                                             ((0xFFFFF000&(data))>>12)
#define  FME_ctrl_get_disable16x16bidir(data)                                    ((0x00000010&(data))>>4)
#define  FME_ctrl_get_disable8x8bidir(data)                                      ((0x00000008&(data))>>3)
#define  FME_ctrl_get_only16x16(data)                                            ((0x00000004&(data))>>2)
#define  FME_ctrl_get_search(data)                                               (0x00000003&(data))

#define  FME_md0                                                                 0x1800F008
#define  FME_md0_reg_addr                                                        "0xB800F008"
#define  FME_md0_reg                                                             0xB800F008
#define  FME_md0_inst_addr                                                       "0x0002"
#define  set_FME_md0_reg(data)                                                   (*((volatile unsigned int*)FME_md0_reg)=data)
#define  get_FME_md0_reg                                                         (*((volatile unsigned int*)FME_md0_reg))
#define  FME_md0_reg_pskip_8x8th_shift                                           (24)
#define  FME_md0_reg_pskip_coeffmax_shift                                        (16)
#define  FME_md0_reg_xvid_sum4x4th_shift                                         (8)
#define  FME_md0_reg_xvid_firstnz4x4th_shift                                     (0)
#define  FME_md0_reg_pskip_8x8th_mask                                            (0xFF000000)
#define  FME_md0_reg_pskip_coeffmax_mask                                         (0x00FF0000)
#define  FME_md0_reg_xvid_sum4x4th_mask                                          (0x0000FF00)
#define  FME_md0_reg_xvid_firstnz4x4th_mask                                      (0x000000FF)
#define  FME_md0_reg_pskip_8x8th(data)                                           (0xFF000000&((data)<<24))
#define  FME_md0_reg_pskip_coeffmax(data)                                        (0x00FF0000&((data)<<16))
#define  FME_md0_reg_xvid_sum4x4th(data)                                         (0x0000FF00&((data)<<8))
#define  FME_md0_reg_xvid_firstnz4x4th(data)                                     (0x000000FF&(data))
#define  FME_md0_get_reg_pskip_8x8th(data)                                       ((0xFF000000&(data))>>24)
#define  FME_md0_get_reg_pskip_coeffmax(data)                                    ((0x00FF0000&(data))>>16)
#define  FME_md0_get_reg_xvid_sum4x4th(data)                                     ((0x0000FF00&(data))>>8)
#define  FME_md0_get_reg_xvid_firstnz4x4th(data)                                 (0x000000FF&(data))

#define  FME_md1                                                                 0x1800F00C
#define  FME_md1_reg_addr                                                        "0xB800F00C"
#define  FME_md1_reg                                                             0xB800F00C
#define  FME_md1_inst_addr                                                       "0x0003"
#define  set_FME_md1_reg(data)                                                   (*((volatile unsigned int*)FME_md1_reg)=data)
#define  get_FME_md1_reg                                                         (*((volatile unsigned int*)FME_md1_reg))
#define  FME_md1_submbcostp8x8_shift                                             (16)
#define  FME_md1_reg_pskip_mbth_shift                                            (8)
#define  FME_md1_skip_cost_weight_shift                                          (0)
#define  FME_md1_submbcostp8x8_mask                                              (0x00FF0000)
#define  FME_md1_reg_pskip_mbth_mask                                             (0x0000FF00)
#define  FME_md1_skip_cost_weight_mask                                           (0x000000FF)
#define  FME_md1_submbcostp8x8(data)                                             (0x00FF0000&((data)<<16))
#define  FME_md1_reg_pskip_mbth(data)                                            (0x0000FF00&((data)<<8))
#define  FME_md1_skip_cost_weight(data)                                          (0x000000FF&(data))
#define  FME_md1_get_submbcostp8x8(data)                                         ((0x00FF0000&(data))>>16)
#define  FME_md1_get_reg_pskip_mbth(data)                                        ((0x0000FF00&(data))>>8)
#define  FME_md1_get_skip_cost_weight(data)                                      (0x000000FF&(data))

#define  FME_md2                                                                 0x1800F010
#define  FME_md2_reg_addr                                                        "0xB800F010"
#define  FME_md2_reg                                                             0xB800F010
#define  FME_md2_inst_addr                                                       "0x0004"
#define  set_FME_md2_reg(data)                                                   (*((volatile unsigned int*)FME_md2_reg)=data)
#define  get_FME_md2_reg                                                         (*((volatile unsigned int*)FME_md2_reg))
#define  FME_md2_mbcost16x16l0_shift                                             (24)
#define  FME_md2_mbcost16x16l1_shift                                             (16)
#define  FME_md2_submbcost8x8l0_shift                                            (8)
#define  FME_md2_submbcost8x8l1_shift                                            (0)
#define  FME_md2_mbcost16x16l0_mask                                              (0xFF000000)
#define  FME_md2_mbcost16x16l1_mask                                              (0x00FF0000)
#define  FME_md2_submbcost8x8l0_mask                                             (0x0000FF00)
#define  FME_md2_submbcost8x8l1_mask                                             (0x000000FF)
#define  FME_md2_mbcost16x16l0(data)                                             (0xFF000000&((data)<<24))
#define  FME_md2_mbcost16x16l1(data)                                             (0x00FF0000&((data)<<16))
#define  FME_md2_submbcost8x8l0(data)                                            (0x0000FF00&((data)<<8))
#define  FME_md2_submbcost8x8l1(data)                                            (0x000000FF&(data))
#define  FME_md2_get_mbcost16x16l0(data)                                         ((0xFF000000&(data))>>24)
#define  FME_md2_get_mbcost16x16l1(data)                                         ((0x00FF0000&(data))>>16)
#define  FME_md2_get_submbcost8x8l0(data)                                        ((0x0000FF00&(data))>>8)
#define  FME_md2_get_submbcost8x8l1(data)                                        (0x000000FF&(data))

#define  FME_md3                                                                 0x1800F014
#define  FME_md3_reg_addr                                                        "0xB800F014"
#define  FME_md3_reg                                                             0xB800F014
#define  FME_md3_inst_addr                                                       "0x0005"
#define  set_FME_md3_reg(data)                                                   (*((volatile unsigned int*)FME_md3_reg)=data)
#define  get_FME_md3_reg                                                         (*((volatile unsigned int*)FME_md3_reg))
#define  FME_md3_mbcostb8x8_shift                                                (16)
#define  FME_md3_mbcost16x16bi_shift                                             (8)
#define  FME_md3_submbcost8x8bi_shift                                            (0)
#define  FME_md3_mbcostb8x8_mask                                                 (0x00FF0000)
#define  FME_md3_mbcost16x16bi_mask                                              (0x0000FF00)
#define  FME_md3_submbcost8x8bi_mask                                             (0x000000FF)
#define  FME_md3_mbcostb8x8(data)                                                (0x00FF0000&((data)<<16))
#define  FME_md3_mbcost16x16bi(data)                                             (0x0000FF00&((data)<<8))
#define  FME_md3_submbcost8x8bi(data)                                            (0x000000FF&(data))
#define  FME_md3_get_mbcostb8x8(data)                                            ((0x00FF0000&(data))>>16)
#define  FME_md3_get_mbcost16x16bi(data)                                         ((0x0000FF00&(data))>>8)
#define  FME_md3_get_submbcost8x8bi(data)                                        (0x000000FF&(data))

#define  FME_md4                                                                 0x1800F018
#define  FME_md4_reg_addr                                                        "0xB800F018"
#define  FME_md4_reg                                                             0xB800F018
#define  FME_md4_inst_addr                                                       "0x0006"
#define  set_FME_md4_reg(data)                                                   (*((volatile unsigned int*)FME_md4_reg)=data)
#define  get_FME_md4_reg                                                         (*((volatile unsigned int*)FME_md4_reg))
#define  FME_md4_m_shift                                                         (16)
#define  FME_md4_submbcost8x8direct_shift                                        (8)
#define  FME_md4_mbcost16x16direct_shift                                         (0)
#define  FME_md4_m_mask                                                          (0xFFFF0000)
#define  FME_md4_submbcost8x8direct_mask                                         (0x0000FF00)
#define  FME_md4_mbcost16x16direct_mask                                          (0x000000FF)
#define  FME_md4_m(data)                                                         (0xFFFF0000&((data)<<16))
#define  FME_md4_submbcost8x8direct(data)                                        (0x0000FF00&((data)<<8))
#define  FME_md4_mbcost16x16direct(data)                                         (0x000000FF&(data))
#define  FME_md4_get_m(data)                                                     ((0xFFFF0000&(data))>>16)
#define  FME_md4_get_submbcost8x8direct(data)                                    ((0x0000FF00&(data))>>8)
#define  FME_md4_get_mbcost16x16direct(data)                                     (0x000000FF&(data))

#define  FME_toprr_b2_fw                                                         0x1800F01C
#define  FME_toprr_b2_fw_reg_addr                                                "0xB800F01C"
#define  FME_toprr_b2_fw_reg                                                     0xB800F01C
#define  FME_toprr_b2_fw_inst_addr                                               "0x0007"
#define  set_FME_toprr_b2_fw_reg(data)                                           (*((volatile unsigned int*)FME_toprr_b2_fw_reg)=data)
#define  get_FME_toprr_b2_fw_reg                                                 (*((volatile unsigned int*)FME_toprr_b2_fw_reg))
#define  FME_toprr_b2_fw_refidx_shift                                            (21)
#define  FME_toprr_b2_fw_mvx_shift                                               (9)
#define  FME_toprr_b2_fw_mvy_shift                                               (0)
#define  FME_toprr_b2_fw_refidx_mask                                             (0x00600000)
#define  FME_toprr_b2_fw_mvx_mask                                                (0x001FFE00)
#define  FME_toprr_b2_fw_mvy_mask                                                (0x000001FF)
#define  FME_toprr_b2_fw_refidx(data)                                            (0x00600000&((data)<<21))
#define  FME_toprr_b2_fw_mvx(data)                                               (0x001FFE00&((data)<<9))
#define  FME_toprr_b2_fw_mvy(data)                                               (0x000001FF&(data))
#define  FME_toprr_b2_fw_get_refidx(data)                                        ((0x00600000&(data))>>21)
#define  FME_toprr_b2_fw_get_mvx(data)                                           ((0x001FFE00&(data))>>9)
#define  FME_toprr_b2_fw_get_mvy(data)                                           (0x000001FF&(data))

#define  FME_toprr_b2_bw                                                         0x1800F020
#define  FME_toprr_b2_bw_reg_addr                                                "0xB800F020"
#define  FME_toprr_b2_bw_reg                                                     0xB800F020
#define  FME_toprr_b2_bw_inst_addr                                               "0x0008"
#define  set_FME_toprr_b2_bw_reg(data)                                           (*((volatile unsigned int*)FME_toprr_b2_bw_reg)=data)
#define  get_FME_toprr_b2_bw_reg                                                 (*((volatile unsigned int*)FME_toprr_b2_bw_reg))
#define  FME_toprr_b2_bw_refidx_shift                                            (21)
#define  FME_toprr_b2_bw_mvx_shift                                               (9)
#define  FME_toprr_b2_bw_mvy_shift                                               (0)
#define  FME_toprr_b2_bw_refidx_mask                                             (0x00600000)
#define  FME_toprr_b2_bw_mvx_mask                                                (0x001FFE00)
#define  FME_toprr_b2_bw_mvy_mask                                                (0x000001FF)
#define  FME_toprr_b2_bw_refidx(data)                                            (0x00600000&((data)<<21))
#define  FME_toprr_b2_bw_mvx(data)                                               (0x001FFE00&((data)<<9))
#define  FME_toprr_b2_bw_mvy(data)                                               (0x000001FF&(data))
#define  FME_toprr_b2_bw_get_refidx(data)                                        ((0x00600000&(data))>>21)
#define  FME_toprr_b2_bw_get_mvx(data)                                           ((0x001FFE00&(data))>>9)
#define  FME_toprr_b2_bw_get_mvy(data)                                           (0x000001FF&(data))

#define  FME_toprr_b3_fw                                                         0x1800F024
#define  FME_toprr_b3_fw_reg_addr                                                "0xB800F024"
#define  FME_toprr_b3_fw_reg                                                     0xB800F024
#define  FME_toprr_b3_fw_inst_addr                                               "0x0009"
#define  set_FME_toprr_b3_fw_reg(data)                                           (*((volatile unsigned int*)FME_toprr_b3_fw_reg)=data)
#define  get_FME_toprr_b3_fw_reg                                                 (*((volatile unsigned int*)FME_toprr_b3_fw_reg))
#define  FME_toprr_b3_fw_refidx_shift                                            (21)
#define  FME_toprr_b3_fw_mvx_shift                                               (9)
#define  FME_toprr_b3_fw_mvy_shift                                               (0)
#define  FME_toprr_b3_fw_refidx_mask                                             (0x00600000)
#define  FME_toprr_b3_fw_mvx_mask                                                (0x001FFE00)
#define  FME_toprr_b3_fw_mvy_mask                                                (0x000001FF)
#define  FME_toprr_b3_fw_refidx(data)                                            (0x00600000&((data)<<21))
#define  FME_toprr_b3_fw_mvx(data)                                               (0x001FFE00&((data)<<9))
#define  FME_toprr_b3_fw_mvy(data)                                               (0x000001FF&(data))
#define  FME_toprr_b3_fw_get_refidx(data)                                        ((0x00600000&(data))>>21)
#define  FME_toprr_b3_fw_get_mvx(data)                                           ((0x001FFE00&(data))>>9)
#define  FME_toprr_b3_fw_get_mvy(data)                                           (0x000001FF&(data))

#define  FME_toprr_b3_bw                                                         0x1800F028
#define  FME_toprr_b3_bw_reg_addr                                                "0xB800F028"
#define  FME_toprr_b3_bw_reg                                                     0xB800F028
#define  FME_toprr_b3_bw_inst_addr                                               "0x000A"
#define  set_FME_toprr_b3_bw_reg(data)                                           (*((volatile unsigned int*)FME_toprr_b3_bw_reg)=data)
#define  get_FME_toprr_b3_bw_reg                                                 (*((volatile unsigned int*)FME_toprr_b3_bw_reg))
#define  FME_toprr_b3_bw_refidx_shift                                            (21)
#define  FME_toprr_b3_bw_mvx_shift                                               (9)
#define  FME_toprr_b3_bw_mvy_shift                                               (0)
#define  FME_toprr_b3_bw_refidx_mask                                             (0x00600000)
#define  FME_toprr_b3_bw_mvx_mask                                                (0x001FFE00)
#define  FME_toprr_b3_bw_mvy_mask                                                (0x000001FF)
#define  FME_toprr_b3_bw_refidx(data)                                            (0x00600000&((data)<<21))
#define  FME_toprr_b3_bw_mvx(data)                                               (0x001FFE00&((data)<<9))
#define  FME_toprr_b3_bw_mvy(data)                                               (0x000001FF&(data))
#define  FME_toprr_b3_bw_get_refidx(data)                                        ((0x00600000&(data))>>21)
#define  FME_toprr_b3_bw_get_mvx(data)                                           ((0x001FFE00&(data))>>9)
#define  FME_toprr_b3_bw_get_mvy(data)                                           (0x000001FF&(data))

#define  FME_col                                                                 0x1800F02C
#define  FME_col_reg_addr                                                        "0xB800F02C"
#define  FME_col_reg                                                             0xB800F02C
#define  FME_col_inst_addr                                                       "0x000B"
#define  set_FME_col_reg(data)                                                   (*((volatile unsigned int*)FME_col_reg)=data)
#define  get_FME_col_reg                                                         (*((volatile unsigned int*)FME_col_reg))
#define  FME_col_zero_shift                                                      (0)
#define  FME_col_zero_mask                                                       (0x0000000F)
#define  FME_col_zero(data)                                                      (0x0000000F&(data))
#define  FME_col_get_zero(data)                                                  (0x0000000F&(data))

#define  FME_mvcost                                                              0x1800F030
#define  FME_mvcost_reg_addr                                                     "0xB800F030"
#define  FME_mvcost_reg                                                          0xB800F030
#define  FME_mvcost_inst_addr                                                    "0x000C"
#define  set_FME_mvcost_reg(data)                                                (*((volatile unsigned int*)FME_mvcost_reg)=data)
#define  get_FME_mvcost_reg                                                      (*((volatile unsigned int*)FME_mvcost_reg))
#define  FME_mvcost_maxfrac_shift                                                (24)
#define  FME_mvcost_maxintg_shift                                                (16)
#define  FME_mvcost_bfrac_shift                                                  (12)
#define  FME_mvcost_bintg_shift                                                  (8)
#define  FME_mvcost_lambda_shift                                                 (0)
#define  FME_mvcost_maxfrac_mask                                                 (0x1F000000)
#define  FME_mvcost_maxintg_mask                                                 (0x000F0000)
#define  FME_mvcost_bfrac_mask                                                   (0x0000F000)
#define  FME_mvcost_bintg_mask                                                   (0x00000F00)
#define  FME_mvcost_lambda_mask                                                  (0x0000007F)
#define  FME_mvcost_maxfrac(data)                                                (0x1F000000&((data)<<24))
#define  FME_mvcost_maxintg(data)                                                (0x000F0000&((data)<<16))
#define  FME_mvcost_bfrac(data)                                                  (0x0000F000&((data)<<12))
#define  FME_mvcost_bintg(data)                                                  (0x00000F00&((data)<<8))
#define  FME_mvcost_lambda(data)                                                 (0x0000007F&(data))
#define  FME_mvcost_get_maxfrac(data)                                            ((0x1F000000&(data))>>24)
#define  FME_mvcost_get_maxintg(data)                                            ((0x000F0000&(data))>>16)
#define  FME_mvcost_get_bfrac(data)                                              ((0x0000F000&(data))>>12)
#define  FME_mvcost_get_bintg(data)                                              ((0x00000F00&(data))>>8)
#define  FME_mvcost_get_lambda(data)                                             (0x0000007F&(data))

#define  FME_pskipcost0                                                          0x1800F034
#define  FME_pskipcost0_reg_addr                                                 "0xB800F034"
#define  FME_pskipcost0_reg                                                      0xB800F034
#define  FME_pskipcost0_inst_addr                                                "0x000D"
#define  set_FME_pskipcost0_reg(data)                                            (*((volatile unsigned int*)FME_pskipcost0_reg)=data)
#define  get_FME_pskipcost0_reg                                                  (*((volatile unsigned int*)FME_pskipcost0_reg))
#define  FME_pskipcost0_run0_shift                                               (28)
#define  FME_pskipcost0_run1_shift                                               (24)
#define  FME_pskipcost0_run2_shift                                               (20)
#define  FME_pskipcost0_run3_shift                                               (16)
#define  FME_pskipcost0_run4_shift                                               (12)
#define  FME_pskipcost0_run5_shift                                               (8)
#define  FME_pskipcost0_run6_shift                                               (4)
#define  FME_pskipcost0_run7_shift                                               (0)
#define  FME_pskipcost0_run0_mask                                                (0xF0000000)
#define  FME_pskipcost0_run1_mask                                                (0x0F000000)
#define  FME_pskipcost0_run2_mask                                                (0x00F00000)
#define  FME_pskipcost0_run3_mask                                                (0x000F0000)
#define  FME_pskipcost0_run4_mask                                                (0x0000F000)
#define  FME_pskipcost0_run5_mask                                                (0x00000F00)
#define  FME_pskipcost0_run6_mask                                                (0x000000F0)
#define  FME_pskipcost0_run7_mask                                                (0x0000000F)
#define  FME_pskipcost0_run0(data)                                               (0xF0000000&((data)<<28))
#define  FME_pskipcost0_run1(data)                                               (0x0F000000&((data)<<24))
#define  FME_pskipcost0_run2(data)                                               (0x00F00000&((data)<<20))
#define  FME_pskipcost0_run3(data)                                               (0x000F0000&((data)<<16))
#define  FME_pskipcost0_run4(data)                                               (0x0000F000&((data)<<12))
#define  FME_pskipcost0_run5(data)                                               (0x00000F00&((data)<<8))
#define  FME_pskipcost0_run6(data)                                               (0x000000F0&((data)<<4))
#define  FME_pskipcost0_run7(data)                                               (0x0000000F&(data))
#define  FME_pskipcost0_get_run0(data)                                           ((0xF0000000&(data))>>28)
#define  FME_pskipcost0_get_run1(data)                                           ((0x0F000000&(data))>>24)
#define  FME_pskipcost0_get_run2(data)                                           ((0x00F00000&(data))>>20)
#define  FME_pskipcost0_get_run3(data)                                           ((0x000F0000&(data))>>16)
#define  FME_pskipcost0_get_run4(data)                                           ((0x0000F000&(data))>>12)
#define  FME_pskipcost0_get_run5(data)                                           ((0x00000F00&(data))>>8)
#define  FME_pskipcost0_get_run6(data)                                           ((0x000000F0&(data))>>4)
#define  FME_pskipcost0_get_run7(data)                                           (0x0000000F&(data))

#define  FME_pskipcost1                                                          0x1800F038
#define  FME_pskipcost1_reg_addr                                                 "0xB800F038"
#define  FME_pskipcost1_reg                                                      0xB800F038
#define  FME_pskipcost1_inst_addr                                                "0x000E"
#define  set_FME_pskipcost1_reg(data)                                            (*((volatile unsigned int*)FME_pskipcost1_reg)=data)
#define  get_FME_pskipcost1_reg                                                  (*((volatile unsigned int*)FME_pskipcost1_reg))
#define  FME_pskipcost1_run8_shift                                               (28)
#define  FME_pskipcost1_run9_shift                                               (24)
#define  FME_pskipcost1_run10_shift                                              (20)
#define  FME_pskipcost1_run11_shift                                              (16)
#define  FME_pskipcost1_run12_shift                                              (12)
#define  FME_pskipcost1_run13_shift                                              (8)
#define  FME_pskipcost1_run14_shift                                              (4)
#define  FME_pskipcost1_run15_shift                                              (0)
#define  FME_pskipcost1_run8_mask                                                (0xF0000000)
#define  FME_pskipcost1_run9_mask                                                (0x0F000000)
#define  FME_pskipcost1_run10_mask                                               (0x00F00000)
#define  FME_pskipcost1_run11_mask                                               (0x000F0000)
#define  FME_pskipcost1_run12_mask                                               (0x0000F000)
#define  FME_pskipcost1_run13_mask                                               (0x00000F00)
#define  FME_pskipcost1_run14_mask                                               (0x000000F0)
#define  FME_pskipcost1_run15_mask                                               (0x0000000F)
#define  FME_pskipcost1_run8(data)                                               (0xF0000000&((data)<<28))
#define  FME_pskipcost1_run9(data)                                               (0x0F000000&((data)<<24))
#define  FME_pskipcost1_run10(data)                                              (0x00F00000&((data)<<20))
#define  FME_pskipcost1_run11(data)                                              (0x000F0000&((data)<<16))
#define  FME_pskipcost1_run12(data)                                              (0x0000F000&((data)<<12))
#define  FME_pskipcost1_run13(data)                                              (0x00000F00&((data)<<8))
#define  FME_pskipcost1_run14(data)                                              (0x000000F0&((data)<<4))
#define  FME_pskipcost1_run15(data)                                              (0x0000000F&(data))
#define  FME_pskipcost1_get_run8(data)                                           ((0xF0000000&(data))>>28)
#define  FME_pskipcost1_get_run9(data)                                           ((0x0F000000&(data))>>24)
#define  FME_pskipcost1_get_run10(data)                                          ((0x00F00000&(data))>>20)
#define  FME_pskipcost1_get_run11(data)                                          ((0x000F0000&(data))>>16)
#define  FME_pskipcost1_get_run12(data)                                          ((0x0000F000&(data))>>12)
#define  FME_pskipcost1_get_run13(data)                                          ((0x00000F00&(data))>>8)
#define  FME_pskipcost1_get_run14(data)                                          ((0x000000F0&(data))>>4)
#define  FME_pskipcost1_get_run15(data)                                          (0x0000000F&(data))

#define  FME_skipdma                                                             0x1800F03C
#define  FME_skipdma_reg_addr                                                    "0xB800F03C"
#define  FME_skipdma_reg                                                         0xB800F03C
#define  FME_skipdma_inst_addr                                                   "0x000F"
#define  set_FME_skipdma_reg(data)                                               (*((volatile unsigned int*)FME_skipdma_reg)=data)
#define  get_FME_skipdma_reg                                                     (*((volatile unsigned int*)FME_skipdma_reg))
#define  FME_skipdma_chromapicidx_fw_shift                                       (7)
#define  FME_skipdma_chromapicidx_bw_shift                                       (0)
#define  FME_skipdma_chromapicidx_fw_mask                                        (0x00003F80)
#define  FME_skipdma_chromapicidx_bw_mask                                        (0x0000007F)
#define  FME_skipdma_chromapicidx_fw(data)                                       (0x00003F80&((data)<<7))
#define  FME_skipdma_chromapicidx_bw(data)                                       (0x0000007F&(data))
#define  FME_skipdma_get_chromapicidx_fw(data)                                   ((0x00003F80&(data))>>7)
#define  FME_skipdma_get_chromapicidx_bw(data)                                   (0x0000007F&(data))

#define  FME_tq_cntl                                                             0x1800F040
#define  FME_tq_cntl_reg_addr                                                    "0xB800F040"
#define  FME_tq_cntl_reg                                                         0xB800F040
#define  FME_tq_cntl_inst_addr                                                   "0x0010"
#define  set_FME_tq_cntl_reg(data)                                               (*((volatile unsigned int*)FME_tq_cntl_reg)=data)
#define  get_FME_tq_cntl_reg                                                     (*((volatile unsigned int*)FME_tq_cntl_reg))
#define  FME_tq_cntl_flat_qtable_shift                                           (12)
#define  FME_tq_cntl_qpy_shift                                                   (6)
#define  FME_tq_cntl_qpc_shift                                                   (0)
#define  FME_tq_cntl_flat_qtable_mask                                            (0x00001000)
#define  FME_tq_cntl_qpy_mask                                                    (0x00000FC0)
#define  FME_tq_cntl_qpc_mask                                                    (0x0000003F)
#define  FME_tq_cntl_flat_qtable(data)                                           (0x00001000&((data)<<12))
#define  FME_tq_cntl_qpy(data)                                                   (0x00000FC0&((data)<<6))
#define  FME_tq_cntl_qpc(data)                                                   (0x0000003F&(data))
#define  FME_tq_cntl_get_flat_qtable(data)                                       ((0x00001000&(data))>>12)
#define  FME_tq_cntl_get_qpy(data)                                               ((0x00000FC0&(data))>>6)
#define  FME_tq_cntl_get_qpc(data)                                               (0x0000003F&(data))

#define  FME_rlt_mb                                                              0x1800F044
#define  FME_rlt_mb_reg_addr                                                     "0xB800F044"
#define  FME_rlt_mb_reg                                                          0xB800F044
#define  FME_rlt_mb_inst_addr                                                    "0x0011"
#define  set_FME_rlt_mb_reg(data)                                                (*((volatile unsigned int*)FME_rlt_mb_reg)=data)
#define  get_FME_rlt_mb_reg                                                      (*((volatile unsigned int*)FME_rlt_mb_reg))
#define  FME_rlt_mb_type_shift                                                   (27)
#define  FME_rlt_mb_partition_shift                                              (24)
#define  FME_rlt_mb_b8x8_0_pred_shift                                            (22)
#define  FME_rlt_mb_b8x8_1_pred_shift                                            (20)
#define  FME_rlt_mb_b8x8_2_pred_shift                                            (18)
#define  FME_rlt_mb_b8x8_3_pred_shift                                            (16)
#define  FME_rlt_mb_b8x8_0_list0_shift                                           (14)
#define  FME_rlt_mb_b8x8_1_list0_shift                                           (12)
#define  FME_rlt_mb_b8x8_2_list0_shift                                           (10)
#define  FME_rlt_mb_b8x8_3_list0_shift                                           (8)
#define  FME_rlt_mb_b8x8_0_list1_shift                                           (6)
#define  FME_rlt_mb_b8x8_1_list1_shift                                           (4)
#define  FME_rlt_mb_b8x8_2_list1_shift                                           (2)
#define  FME_rlt_mb_b8x8_3_list1_shift                                           (0)
#define  FME_rlt_mb_type_mask                                                    (0x18000000)
#define  FME_rlt_mb_partition_mask                                               (0x07000000)
#define  FME_rlt_mb_b8x8_0_pred_mask                                             (0x00C00000)
#define  FME_rlt_mb_b8x8_1_pred_mask                                             (0x00300000)
#define  FME_rlt_mb_b8x8_2_pred_mask                                             (0x000C0000)
#define  FME_rlt_mb_b8x8_3_pred_mask                                             (0x00030000)
#define  FME_rlt_mb_b8x8_0_list0_mask                                            (0x0000C000)
#define  FME_rlt_mb_b8x8_1_list0_mask                                            (0x00003000)
#define  FME_rlt_mb_b8x8_2_list0_mask                                            (0x00000C00)
#define  FME_rlt_mb_b8x8_3_list0_mask                                            (0x00000300)
#define  FME_rlt_mb_b8x8_0_list1_mask                                            (0x000000C0)
#define  FME_rlt_mb_b8x8_1_list1_mask                                            (0x00000030)
#define  FME_rlt_mb_b8x8_2_list1_mask                                            (0x0000000C)
#define  FME_rlt_mb_b8x8_3_list1_mask                                            (0x00000003)
#define  FME_rlt_mb_type(data)                                                   (0x18000000&((data)<<27))
#define  FME_rlt_mb_partition(data)                                              (0x07000000&((data)<<24))
#define  FME_rlt_mb_b8x8_0_pred(data)                                            (0x00C00000&((data)<<22))
#define  FME_rlt_mb_b8x8_1_pred(data)                                            (0x00300000&((data)<<20))
#define  FME_rlt_mb_b8x8_2_pred(data)                                            (0x000C0000&((data)<<18))
#define  FME_rlt_mb_b8x8_3_pred(data)                                            (0x00030000&((data)<<16))
#define  FME_rlt_mb_b8x8_0_list0(data)                                           (0x0000C000&((data)<<14))
#define  FME_rlt_mb_b8x8_1_list0(data)                                           (0x00003000&((data)<<12))
#define  FME_rlt_mb_b8x8_2_list0(data)                                           (0x00000C00&((data)<<10))
#define  FME_rlt_mb_b8x8_3_list0(data)                                           (0x00000300&((data)<<8))
#define  FME_rlt_mb_b8x8_0_list1(data)                                           (0x000000C0&((data)<<6))
#define  FME_rlt_mb_b8x8_1_list1(data)                                           (0x00000030&((data)<<4))
#define  FME_rlt_mb_b8x8_2_list1(data)                                           (0x0000000C&((data)<<2))
#define  FME_rlt_mb_b8x8_3_list1(data)                                           (0x00000003&(data))
#define  FME_rlt_mb_get_type(data)                                               ((0x18000000&(data))>>27)
#define  FME_rlt_mb_get_partition(data)                                          ((0x07000000&(data))>>24)
#define  FME_rlt_mb_get_b8x8_0_pred(data)                                        ((0x00C00000&(data))>>22)
#define  FME_rlt_mb_get_b8x8_1_pred(data)                                        ((0x00300000&(data))>>20)
#define  FME_rlt_mb_get_b8x8_2_pred(data)                                        ((0x000C0000&(data))>>18)
#define  FME_rlt_mb_get_b8x8_3_pred(data)                                        ((0x00030000&(data))>>16)
#define  FME_rlt_mb_get_b8x8_0_list0(data)                                       ((0x0000C000&(data))>>14)
#define  FME_rlt_mb_get_b8x8_1_list0(data)                                       ((0x00003000&(data))>>12)
#define  FME_rlt_mb_get_b8x8_2_list0(data)                                       ((0x00000C00&(data))>>10)
#define  FME_rlt_mb_get_b8x8_3_list0(data)                                       ((0x00000300&(data))>>8)
#define  FME_rlt_mb_get_b8x8_0_list1(data)                                       ((0x000000C0&(data))>>6)
#define  FME_rlt_mb_get_b8x8_1_list1(data)                                       ((0x00000030&(data))>>4)
#define  FME_rlt_mb_get_b8x8_2_list1(data)                                       ((0x0000000C&(data))>>2)
#define  FME_rlt_mb_get_b8x8_3_list1(data)                                       (0x00000003&(data))

#define  FME_rlt_fw_0                                                            0x1800F048
#define  FME_rlt_fw_0_reg_addr                                                   "0xB800F048"
#define  FME_rlt_fw_0_reg                                                        0xB800F048
#define  FME_rlt_fw_0_inst_addr                                                  "0x0012"
#define  set_FME_rlt_fw_0_reg(data)                                              (*((volatile unsigned int*)FME_rlt_fw_0_reg)=data)
#define  get_FME_rlt_fw_0_reg                                                    (*((volatile unsigned int*)FME_rlt_fw_0_reg))
#define  FME_rlt_fw_0_mvx_shift                                                  (9)
#define  FME_rlt_fw_0_mvy_shift                                                  (0)
#define  FME_rlt_fw_0_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_fw_0_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_fw_0_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_fw_0_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_fw_0_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_fw_0_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_fw_1                                                            0x1800F04C
#define  FME_rlt_fw_1_reg_addr                                                   "0xB800F04C"
#define  FME_rlt_fw_1_reg                                                        0xB800F04C
#define  FME_rlt_fw_1_inst_addr                                                  "0x0013"
#define  set_FME_rlt_fw_1_reg(data)                                              (*((volatile unsigned int*)FME_rlt_fw_1_reg)=data)
#define  get_FME_rlt_fw_1_reg                                                    (*((volatile unsigned int*)FME_rlt_fw_1_reg))
#define  FME_rlt_fw_1_mvx_shift                                                  (9)
#define  FME_rlt_fw_1_mvy_shift                                                  (0)
#define  FME_rlt_fw_1_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_fw_1_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_fw_1_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_fw_1_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_fw_1_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_fw_1_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_fw_2                                                            0x1800F050
#define  FME_rlt_fw_2_reg_addr                                                   "0xB800F050"
#define  FME_rlt_fw_2_reg                                                        0xB800F050
#define  FME_rlt_fw_2_inst_addr                                                  "0x0014"
#define  set_FME_rlt_fw_2_reg(data)                                              (*((volatile unsigned int*)FME_rlt_fw_2_reg)=data)
#define  get_FME_rlt_fw_2_reg                                                    (*((volatile unsigned int*)FME_rlt_fw_2_reg))
#define  FME_rlt_fw_2_mvx_shift                                                  (9)
#define  FME_rlt_fw_2_mvy_shift                                                  (0)
#define  FME_rlt_fw_2_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_fw_2_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_fw_2_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_fw_2_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_fw_2_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_fw_2_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_fw_3                                                            0x1800F054
#define  FME_rlt_fw_3_reg_addr                                                   "0xB800F054"
#define  FME_rlt_fw_3_reg                                                        0xB800F054
#define  FME_rlt_fw_3_inst_addr                                                  "0x0015"
#define  set_FME_rlt_fw_3_reg(data)                                              (*((volatile unsigned int*)FME_rlt_fw_3_reg)=data)
#define  get_FME_rlt_fw_3_reg                                                    (*((volatile unsigned int*)FME_rlt_fw_3_reg))
#define  FME_rlt_fw_3_mvx_shift                                                  (9)
#define  FME_rlt_fw_3_mvy_shift                                                  (0)
#define  FME_rlt_fw_3_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_fw_3_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_fw_3_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_fw_3_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_fw_3_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_fw_3_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_bw_0                                                            0x1800F058
#define  FME_rlt_bw_0_reg_addr                                                   "0xB800F058"
#define  FME_rlt_bw_0_reg                                                        0xB800F058
#define  FME_rlt_bw_0_inst_addr                                                  "0x0016"
#define  set_FME_rlt_bw_0_reg(data)                                              (*((volatile unsigned int*)FME_rlt_bw_0_reg)=data)
#define  get_FME_rlt_bw_0_reg                                                    (*((volatile unsigned int*)FME_rlt_bw_0_reg))
#define  FME_rlt_bw_0_mvx_shift                                                  (9)
#define  FME_rlt_bw_0_mvy_shift                                                  (0)
#define  FME_rlt_bw_0_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_bw_0_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_bw_0_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_bw_0_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_bw_0_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_bw_0_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_bw_1                                                            0x1800F05C
#define  FME_rlt_bw_1_reg_addr                                                   "0xB800F05C"
#define  FME_rlt_bw_1_reg                                                        0xB800F05C
#define  FME_rlt_bw_1_inst_addr                                                  "0x0017"
#define  set_FME_rlt_bw_1_reg(data)                                              (*((volatile unsigned int*)FME_rlt_bw_1_reg)=data)
#define  get_FME_rlt_bw_1_reg                                                    (*((volatile unsigned int*)FME_rlt_bw_1_reg))
#define  FME_rlt_bw_1_mvx_shift                                                  (9)
#define  FME_rlt_bw_1_mvy_shift                                                  (0)
#define  FME_rlt_bw_1_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_bw_1_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_bw_1_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_bw_1_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_bw_1_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_bw_1_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_bw_2                                                            0x1800F060
#define  FME_rlt_bw_2_reg_addr                                                   "0xB800F060"
#define  FME_rlt_bw_2_reg                                                        0xB800F060
#define  FME_rlt_bw_2_inst_addr                                                  "0x0018"
#define  set_FME_rlt_bw_2_reg(data)                                              (*((volatile unsigned int*)FME_rlt_bw_2_reg)=data)
#define  get_FME_rlt_bw_2_reg                                                    (*((volatile unsigned int*)FME_rlt_bw_2_reg))
#define  FME_rlt_bw_2_mvx_shift                                                  (9)
#define  FME_rlt_bw_2_mvy_shift                                                  (0)
#define  FME_rlt_bw_2_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_bw_2_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_bw_2_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_bw_2_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_bw_2_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_bw_2_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_bw_3                                                            0x1800F064
#define  FME_rlt_bw_3_reg_addr                                                   "0xB800F064"
#define  FME_rlt_bw_3_reg                                                        0xB800F064
#define  FME_rlt_bw_3_inst_addr                                                  "0x0019"
#define  set_FME_rlt_bw_3_reg(data)                                              (*((volatile unsigned int*)FME_rlt_bw_3_reg)=data)
#define  get_FME_rlt_bw_3_reg                                                    (*((volatile unsigned int*)FME_rlt_bw_3_reg))
#define  FME_rlt_bw_3_mvx_shift                                                  (9)
#define  FME_rlt_bw_3_mvy_shift                                                  (0)
#define  FME_rlt_bw_3_mvx_mask                                                   (0x001FFE00)
#define  FME_rlt_bw_3_mvy_mask                                                   (0x000001FF)
#define  FME_rlt_bw_3_mvx(data)                                                  (0x001FFE00&((data)<<9))
#define  FME_rlt_bw_3_mvy(data)                                                  (0x000001FF&(data))
#define  FME_rlt_bw_3_get_mvx(data)                                              ((0x001FFE00&(data))>>9)
#define  FME_rlt_bw_3_get_mvy(data)                                              (0x000001FF&(data))

#define  FME_rlt_16x16fw                                                         0x1800F068
#define  FME_rlt_16x16fw_reg_addr                                                "0xB800F068"
#define  FME_rlt_16x16fw_reg                                                     0xB800F068
#define  FME_rlt_16x16fw_inst_addr                                               "0x001A"
#define  set_FME_rlt_16x16fw_reg(data)                                           (*((volatile unsigned int*)FME_rlt_16x16fw_reg)=data)
#define  get_FME_rlt_16x16fw_reg                                                 (*((volatile unsigned int*)FME_rlt_16x16fw_reg))
#define  FME_rlt_16x16fw_pred_shift                                              (21)
#define  FME_rlt_16x16fw_mvx_shift                                               (9)
#define  FME_rlt_16x16fw_mvy_shift                                               (0)
#define  FME_rlt_16x16fw_pred_mask                                               (0x00600000)
#define  FME_rlt_16x16fw_mvx_mask                                                (0x001FFE00)
#define  FME_rlt_16x16fw_mvy_mask                                                (0x000001FF)
#define  FME_rlt_16x16fw_pred(data)                                              (0x00600000&((data)<<21))
#define  FME_rlt_16x16fw_mvx(data)                                               (0x001FFE00&((data)<<9))
#define  FME_rlt_16x16fw_mvy(data)                                               (0x000001FF&(data))
#define  FME_rlt_16x16fw_get_pred(data)                                          ((0x00600000&(data))>>21)
#define  FME_rlt_16x16fw_get_mvx(data)                                           ((0x001FFE00&(data))>>9)
#define  FME_rlt_16x16fw_get_mvy(data)                                           (0x000001FF&(data))

#define  FME_rlt_16x16bw                                                         0x1800F06C
#define  FME_rlt_16x16bw_reg_addr                                                "0xB800F06C"
#define  FME_rlt_16x16bw_reg                                                     0xB800F06C
#define  FME_rlt_16x16bw_inst_addr                                               "0x001B"
#define  set_FME_rlt_16x16bw_reg(data)                                           (*((volatile unsigned int*)FME_rlt_16x16bw_reg)=data)
#define  get_FME_rlt_16x16bw_reg                                                 (*((volatile unsigned int*)FME_rlt_16x16bw_reg))
#define  FME_rlt_16x16bw_mvx_shift                                               (9)
#define  FME_rlt_16x16bw_mvy_shift                                               (0)
#define  FME_rlt_16x16bw_mvx_mask                                                (0x001FFE00)
#define  FME_rlt_16x16bw_mvy_mask                                                (0x000001FF)
#define  FME_rlt_16x16bw_mvx(data)                                               (0x001FFE00&((data)<<9))
#define  FME_rlt_16x16bw_mvy(data)                                               (0x000001FF&(data))
#define  FME_rlt_16x16bw_get_mvx(data)                                           ((0x001FFE00&(data))>>9)
#define  FME_rlt_16x16bw_get_mvy(data)                                           (0x000001FF&(data))

#define  FME_rlt_col                                                             0x1800F070
#define  FME_rlt_col_reg_addr                                                    "0xB800F070"
#define  FME_rlt_col_reg                                                         0xB800F070
#define  FME_rlt_col_inst_addr                                                   "0x001C"
#define  set_FME_rlt_col_reg(data)                                               (*((volatile unsigned int*)FME_rlt_col_reg)=data)
#define  get_FME_rlt_col_reg                                                     (*((volatile unsigned int*)FME_rlt_col_reg))
#define  FME_rlt_col_zero_shift                                                  (0)
#define  FME_rlt_col_zero_mask                                                   (0x0000000F)
#define  FME_rlt_col_zero(data)                                                  (0x0000000F&(data))
#define  FME_rlt_col_get_zero(data)                                              (0x0000000F&(data))

#define  FME_rlt_16x16                                                           0x1800F074
#define  FME_rlt_16x16_reg_addr                                                  "0xB800F074"
#define  FME_rlt_16x16_reg                                                       0xB800F074
#define  FME_rlt_16x16_inst_addr                                                 "0x001D"
#define  set_FME_rlt_16x16_reg(data)                                             (*((volatile unsigned int*)FME_rlt_16x16_reg)=data)
#define  get_FME_rlt_16x16_reg                                                   (*((volatile unsigned int*)FME_rlt_16x16_reg))
#define  FME_rlt_16x16_cost_shift                                                (0)
#define  FME_rlt_16x16_cost_mask                                                 (0x0003FFFF)
#define  FME_rlt_16x16_cost(data)                                                (0x0003FFFF&(data))
#define  FME_rlt_16x16_get_cost(data)                                            (0x0003FFFF&(data))

#define  FME_rlt_16x16Direct                                                     0x1800F078
#define  FME_rlt_16x16Direct_reg_addr                                            "0xB800F078"
#define  FME_rlt_16x16Direct_reg                                                 0xB800F078
#define  FME_rlt_16x16Direct_inst_addr                                           "0x001E"
#define  set_FME_rlt_16x16Direct_reg(data)                                       (*((volatile unsigned int*)FME_rlt_16x16Direct_reg)=data)
#define  get_FME_rlt_16x16Direct_reg                                             (*((volatile unsigned int*)FME_rlt_16x16Direct_reg))
#define  FME_rlt_16x16Direct_cost_shift                                          (0)
#define  FME_rlt_16x16Direct_cost_mask                                           (0x0003FFFF)
#define  FME_rlt_16x16Direct_cost(data)                                          (0x0003FFFF&(data))
#define  FME_rlt_16x16Direct_get_cost(data)                                      (0x0003FFFF&(data))

#define  FME_rlt_8x8                                                             0x1800F07C
#define  FME_rlt_8x8_reg_addr                                                    "0xB800F07C"
#define  FME_rlt_8x8_reg                                                         0xB800F07C
#define  FME_rlt_8x8_inst_addr                                                   "0x001F"
#define  set_FME_rlt_8x8_reg(data)                                               (*((volatile unsigned int*)FME_rlt_8x8_reg)=data)
#define  get_FME_rlt_8x8_reg                                                     (*((volatile unsigned int*)FME_rlt_8x8_reg))
#define  FME_rlt_8x8_cost_shift                                                  (0)
#define  FME_rlt_8x8_cost_mask                                                   (0x0003FFFF)
#define  FME_rlt_8x8_cost(data)                                                  (0x0003FFFF&(data))
#define  FME_rlt_8x8_get_cost(data)                                              (0x0003FFFF&(data))

#define  FME_rlt_skip                                                            0x1800F080
#define  FME_rlt_skip_reg_addr                                                   "0xB800F080"
#define  FME_rlt_skip_reg                                                        0xB800F080
#define  FME_rlt_skip_inst_addr                                                  "0x0020"
#define  set_FME_rlt_skip_reg(data)                                              (*((volatile unsigned int*)FME_rlt_skip_reg)=data)
#define  get_FME_rlt_skip_reg                                                    (*((volatile unsigned int*)FME_rlt_skip_reg))
#define  FME_rlt_skip_skipable_shift                                             (18)
#define  FME_rlt_skip_cost_shift                                                 (0)
#define  FME_rlt_skip_skipable_mask                                              (0x00040000)
#define  FME_rlt_skip_cost_mask                                                  (0x0003FFFF)
#define  FME_rlt_skip_skipable(data)                                             (0x00040000&((data)<<18))
#define  FME_rlt_skip_cost(data)                                                 (0x0003FFFF&(data))
#define  FME_rlt_skip_get_skipable(data)                                         ((0x00040000&(data))>>18)
#define  FME_rlt_skip_get_cost(data)                                             (0x0003FFFF&(data))

#define  FME_debug0                                                              0x1800F084
#define  FME_debug0_reg_addr                                                     "0xB800F084"
#define  FME_debug0_reg                                                          0xB800F084
#define  FME_debug0_inst_addr                                                    "0x0021"
#define  set_FME_debug0_reg(data)                                                (*((volatile unsigned int*)FME_debug0_reg)=data)
#define  get_FME_debug0_reg                                                      (*((volatile unsigned int*)FME_debug0_reg))
#define  FME_debug0_status_shift                                                 (0)
#define  FME_debug0_status_mask                                                  (0xFFFFFFFF)
#define  FME_debug0_status(data)                                                 (0xFFFFFFFF&(data))
#define  FME_debug0_get_status(data)                                             (0xFFFFFFFF&(data))

#define  FME_debug1                                                              0x1800F088
#define  FME_debug1_reg_addr                                                     "0xB800F088"
#define  FME_debug1_reg                                                          0xB800F088
#define  FME_debug1_inst_addr                                                    "0x0022"
#define  set_FME_debug1_reg(data)                                                (*((volatile unsigned int*)FME_debug1_reg)=data)
#define  get_FME_debug1_reg                                                      (*((volatile unsigned int*)FME_debug1_reg))
#define  FME_debug1_status_shift                                                 (0)
#define  FME_debug1_status_mask                                                  (0xFFFFFFFF)
#define  FME_debug1_status(data)                                                 (0xFFFFFFFF&(data))
#define  FME_debug1_get_status(data)                                             (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======FME register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  encodetype:2;
        RBus_UInt32  enablemvc:1;
        RBus_UInt32  pictype:2;
        RBus_UInt32  firstmbofpic:1;
        RBus_UInt32  lastmbofslice:1;
        RBus_UInt32  firstmbofslice:1;
    };
}fme_comm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hardware:20;
        RBus_UInt32  res1:7;
        RBus_UInt32  disable16x16bidir:1;
        RBus_UInt32  disable8x8bidir:1;
        RBus_UInt32  only16x16:1;
        RBus_UInt32  search:2;
    };
}fme_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_pskip_8x8th:8;
        RBus_UInt32  reg_pskip_coeffmax:8;
        RBus_UInt32  reg_xvid_sum4x4th:8;
        RBus_UInt32  reg_xvid_firstnz4x4th:8;
    };
}fme_md0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  submbcostp8x8:8;
        RBus_UInt32  reg_pskip_mbth:8;
        RBus_UInt32  skip_cost_weight:8;
    };
}fme_md1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbcost16x16l0:8;
        RBus_UInt32  mbcost16x16l1:8;
        RBus_UInt32  submbcost8x8l0:8;
        RBus_UInt32  submbcost8x8l1:8;
    };
}fme_md2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  mbcostb8x8:8;
        RBus_UInt32  mbcost16x16bi:8;
        RBus_UInt32  submbcost8x8bi:8;
    };
}fme_md3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m:16;
        RBus_UInt32  submbcost8x8direct:8;
        RBus_UInt32  mbcost16x16direct:8;
    };
}fme_md4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  refidx:2;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_toprr_b2_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  refidx:2;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_toprr_b2_bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  refidx:2;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_toprr_b3_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  refidx:2;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_toprr_b3_bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  zero:4;
    };
}fme_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  maxfrac:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  maxintg:4;
        RBus_UInt32  bfrac:4;
        RBus_UInt32  bintg:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  lambda:7;
    };
}fme_mvcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  run0:4;
        RBus_UInt32  run1:4;
        RBus_UInt32  run2:4;
        RBus_UInt32  run3:4;
        RBus_UInt32  run4:4;
        RBus_UInt32  run5:4;
        RBus_UInt32  run6:4;
        RBus_UInt32  run7:4;
    };
}fme_pskipcost0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  run8:4;
        RBus_UInt32  run9:4;
        RBus_UInt32  run10:4;
        RBus_UInt32  run11:4;
        RBus_UInt32  run12:4;
        RBus_UInt32  run13:4;
        RBus_UInt32  run14:4;
        RBus_UInt32  run15:4;
    };
}fme_pskipcost1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  chromapicidx_fw:7;
        RBus_UInt32  chromapicidx_bw:7;
    };
}fme_skipdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  qpc:6;
    };
}fme_tq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  type:2;
        RBus_UInt32  partition:3;
        RBus_UInt32  b8x8_0_pred:2;
        RBus_UInt32  b8x8_1_pred:2;
        RBus_UInt32  b8x8_2_pred:2;
        RBus_UInt32  b8x8_3_pred:2;
        RBus_UInt32  b8x8_0_list0:2;
        RBus_UInt32  b8x8_1_list0:2;
        RBus_UInt32  b8x8_2_list0:2;
        RBus_UInt32  b8x8_3_list0:2;
        RBus_UInt32  b8x8_0_list1:2;
        RBus_UInt32  b8x8_1_list1:2;
        RBus_UInt32  b8x8_2_list1:2;
        RBus_UInt32  b8x8_3_list1:2;
    };
}fme_rlt_mb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_rlt_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_rlt_bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pred:2;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_rlt_16x16fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mvx:12;
        RBus_UInt32  mvy:9;
    };
}fme_rlt_16x16bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  zero:4;
    };
}fme_rlt_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  cost:18;
    };
}fme_rlt_16x16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  cost:18;
    };
}fme_rlt_16x16direct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  cost:18;
    };
}fme_rlt_8x8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  skipable:1;
        RBus_UInt32  cost:18;
    };
}fme_rlt_skip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status:32;
    };
}fme_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status:32;
    };
}fme_debug1_RBUS;

#else //apply LITTLE_ENDIAN

//======FME register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  firstmbofslice:1;
        RBus_UInt32  lastmbofslice:1;
        RBus_UInt32  firstmbofpic:1;
        RBus_UInt32  pictype:2;
        RBus_UInt32  enablemvc:1;
        RBus_UInt32  encodetype:2;
        RBus_UInt32  res1:24;
    };
}fme_comm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  search:2;
        RBus_UInt32  only16x16:1;
        RBus_UInt32  disable8x8bidir:1;
        RBus_UInt32  disable16x16bidir:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  hardware:20;
    };
}fme_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_xvid_firstnz4x4th:8;
        RBus_UInt32  reg_xvid_sum4x4th:8;
        RBus_UInt32  reg_pskip_coeffmax:8;
        RBus_UInt32  reg_pskip_8x8th:8;
    };
}fme_md0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  skip_cost_weight:8;
        RBus_UInt32  reg_pskip_mbth:8;
        RBus_UInt32  submbcostp8x8:8;
        RBus_UInt32  res1:8;
    };
}fme_md1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  submbcost8x8l1:8;
        RBus_UInt32  submbcost8x8l0:8;
        RBus_UInt32  mbcost16x16l1:8;
        RBus_UInt32  mbcost16x16l0:8;
    };
}fme_md2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  submbcost8x8bi:8;
        RBus_UInt32  mbcost16x16bi:8;
        RBus_UInt32  mbcostb8x8:8;
        RBus_UInt32  res1:8;
    };
}fme_md3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbcost16x16direct:8;
        RBus_UInt32  submbcost8x8direct:8;
        RBus_UInt32  m:16;
    };
}fme_md4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  refidx:2;
        RBus_UInt32  res1:9;
    };
}fme_toprr_b2_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  refidx:2;
        RBus_UInt32  res1:9;
    };
}fme_toprr_b2_bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  refidx:2;
        RBus_UInt32  res1:9;
    };
}fme_toprr_b3_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  refidx:2;
        RBus_UInt32  res1:9;
    };
}fme_toprr_b3_bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zero:4;
        RBus_UInt32  res1:28;
    };
}fme_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lambda:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  bintg:4;
        RBus_UInt32  bfrac:4;
        RBus_UInt32  maxintg:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  maxfrac:5;
        RBus_UInt32  res3:3;
    };
}fme_mvcost_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  run7:4;
        RBus_UInt32  run6:4;
        RBus_UInt32  run5:4;
        RBus_UInt32  run4:4;
        RBus_UInt32  run3:4;
        RBus_UInt32  run2:4;
        RBus_UInt32  run1:4;
        RBus_UInt32  run0:4;
    };
}fme_pskipcost0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  run15:4;
        RBus_UInt32  run14:4;
        RBus_UInt32  run13:4;
        RBus_UInt32  run12:4;
        RBus_UInt32  run11:4;
        RBus_UInt32  run10:4;
        RBus_UInt32  run9:4;
        RBus_UInt32  run8:4;
    };
}fme_pskipcost1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chromapicidx_bw:7;
        RBus_UInt32  chromapicidx_fw:7;
        RBus_UInt32  res1:18;
    };
}fme_skipdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qpc:6;
        RBus_UInt32  qpy:6;
        RBus_UInt32  flat_qtable:1;
        RBus_UInt32  res1:19;
    };
}fme_tq_cntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b8x8_3_list1:2;
        RBus_UInt32  b8x8_2_list1:2;
        RBus_UInt32  b8x8_1_list1:2;
        RBus_UInt32  b8x8_0_list1:2;
        RBus_UInt32  b8x8_3_list0:2;
        RBus_UInt32  b8x8_2_list0:2;
        RBus_UInt32  b8x8_1_list0:2;
        RBus_UInt32  b8x8_0_list0:2;
        RBus_UInt32  b8x8_3_pred:2;
        RBus_UInt32  b8x8_2_pred:2;
        RBus_UInt32  b8x8_1_pred:2;
        RBus_UInt32  b8x8_0_pred:2;
        RBus_UInt32  partition:3;
        RBus_UInt32  type:2;
        RBus_UInt32  res1:3;
    };
}fme_rlt_mb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  res1:11;
    };
}fme_rlt_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  res1:11;
    };
}fme_rlt_bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  pred:2;
        RBus_UInt32  res1:9;
    };
}fme_rlt_16x16fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:9;
        RBus_UInt32  mvx:12;
        RBus_UInt32  res1:11;
    };
}fme_rlt_16x16bw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zero:4;
        RBus_UInt32  res1:28;
    };
}fme_rlt_col_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cost:18;
        RBus_UInt32  res1:14;
    };
}fme_rlt_16x16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cost:18;
        RBus_UInt32  res1:14;
    };
}fme_rlt_16x16direct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cost:18;
        RBus_UInt32  res1:14;
    };
}fme_rlt_8x8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cost:18;
        RBus_UInt32  skipable:1;
        RBus_UInt32  res1:13;
    };
}fme_rlt_skip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status:32;
    };
}fme_debug0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  status:32;
    };
}fme_debug1_RBUS;




#endif 


#endif 
