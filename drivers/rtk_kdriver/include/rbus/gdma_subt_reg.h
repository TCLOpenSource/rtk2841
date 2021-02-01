/**
* @file Mac5-DesignSpec-D-Domain_GDMA_subt
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_GDMA_SUBT_REG_H_
#define _RBUS_GDMA_SUBT_REG_H_

#include "rbus_types.h"



//  GDMA_SUBT Register Address
#define  GDMA_SUBT_UPDATE                                                        0x1802F000
#define  GDMA_SUBT_UPDATE_reg_addr                                               "0xB802F000"
#define  GDMA_SUBT_UPDATE_reg                                                    0xB802F000
#define  GDMA_SUBT_UPDATE_inst_addr                                              "0x0000"
#define  set_GDMA_SUBT_UPDATE_reg(data)                                          (*((volatile unsigned int*)GDMA_SUBT_UPDATE_reg)=data)
#define  get_GDMA_SUBT_UPDATE_reg                                                (*((volatile unsigned int*)GDMA_SUBT_UPDATE_reg))
#define  GDMA_SUBT_UPDATE_gating_enable_shift                                    (7)
#define  GDMA_SUBT_UPDATE_sub1_bypass_acc_sync_fix_shift                         (4)
#define  GDMA_SUBT_UPDATE_sub1_sel_shift                                         (1)
#define  GDMA_SUBT_UPDATE_write_data_shift                                       (0)
#define  GDMA_SUBT_UPDATE_gating_enable_mask                                     (0x00000080)
#define  GDMA_SUBT_UPDATE_sub1_bypass_acc_sync_fix_mask                          (0x00000010)
#define  GDMA_SUBT_UPDATE_sub1_sel_mask                                          (0x00000002)
#define  GDMA_SUBT_UPDATE_write_data_mask                                        (0x00000001)
#define  GDMA_SUBT_UPDATE_gating_enable(data)                                    (0x00000080&((data)<<7))
#define  GDMA_SUBT_UPDATE_sub1_bypass_acc_sync_fix(data)                         (0x00000010&((data)<<4))
#define  GDMA_SUBT_UPDATE_sub1_sel(data)                                         (0x00000002&((data)<<1))
#define  GDMA_SUBT_UPDATE_write_data(data)                                       (0x00000001&(data))
#define  GDMA_SUBT_UPDATE_get_gating_enable(data)                                ((0x00000080&(data))>>7)
#define  GDMA_SUBT_UPDATE_get_sub1_bypass_acc_sync_fix(data)                     ((0x00000010&(data))>>4)
#define  GDMA_SUBT_UPDATE_get_sub1_sel(data)                                     ((0x00000002&(data))>>1)
#define  GDMA_SUBT_UPDATE_get_write_data(data)                                   (0x00000001&(data))

#define  GDMA_SUBT_CTRL                                                          0x1802F004
#define  GDMA_SUBT_CTRL_reg_addr                                                 "0xB802F004"
#define  GDMA_SUBT_CTRL_reg                                                      0xB802F004
#define  GDMA_SUBT_CTRL_inst_addr                                                "0x0001"
#define  set_GDMA_SUBT_CTRL_reg(data)                                            (*((volatile unsigned int*)GDMA_SUBT_CTRL_reg)=data)
#define  get_GDMA_SUBT_CTRL_reg                                                  (*((volatile unsigned int*)GDMA_SUBT_CTRL_reg))
#define  GDMA_SUBT_CTRL_sub1_prog_done_shift                                     (4)
#define  GDMA_SUBT_CTRL_write_data_shift                                         (0)
#define  GDMA_SUBT_CTRL_sub1_prog_done_mask                                      (0x00000010)
#define  GDMA_SUBT_CTRL_write_data_mask                                          (0x00000001)
#define  GDMA_SUBT_CTRL_sub1_prog_done(data)                                     (0x00000010&((data)<<4))
#define  GDMA_SUBT_CTRL_write_data(data)                                         (0x00000001&(data))
#define  GDMA_SUBT_CTRL_get_sub1_prog_done(data)                                 ((0x00000010&(data))>>4)
#define  GDMA_SUBT_CTRL_get_write_data(data)                                     (0x00000001&(data))

#define  GDMA_SUBT_SUB1_CTRL                                                     0x1802F020
#define  GDMA_SUBT_SUB1_CTRL_reg_addr                                            "0xB802F020"
#define  GDMA_SUBT_SUB1_CTRL_reg                                                 0xB802F020
#define  GDMA_SUBT_SUB1_CTRL_inst_addr                                           "0x0002"
#define  set_GDMA_SUBT_SUB1_CTRL_reg(data)                                       (*((volatile unsigned int*)GDMA_SUBT_SUB1_CTRL_reg)=data)
#define  get_GDMA_SUBT_SUB1_CTRL_reg                                             (*((volatile unsigned int*)GDMA_SUBT_SUB1_CTRL_reg))
#define  GDMA_SUBT_SUB1_CTRL_d3_mode_shift                                       (9)
#define  GDMA_SUBT_SUB1_CTRL_rotate_shift                                        (8)
#define  GDMA_SUBT_SUB1_CTRL_vs_shift                                            (3)
#define  GDMA_SUBT_SUB1_CTRL_hs_shift                                            (2)
#define  GDMA_SUBT_SUB1_CTRL_sub1_en_shift                                       (1)
#define  GDMA_SUBT_SUB1_CTRL_write_data_shift                                    (0)
#define  GDMA_SUBT_SUB1_CTRL_d3_mode_mask                                        (0x00000200)
#define  GDMA_SUBT_SUB1_CTRL_rotate_mask                                         (0x00000100)
#define  GDMA_SUBT_SUB1_CTRL_vs_mask                                             (0x00000008)
#define  GDMA_SUBT_SUB1_CTRL_hs_mask                                             (0x00000004)
#define  GDMA_SUBT_SUB1_CTRL_sub1_en_mask                                        (0x00000002)
#define  GDMA_SUBT_SUB1_CTRL_write_data_mask                                     (0x00000001)
#define  GDMA_SUBT_SUB1_CTRL_d3_mode(data)                                       (0x00000200&((data)<<9))
#define  GDMA_SUBT_SUB1_CTRL_rotate(data)                                        (0x00000100&((data)<<8))
#define  GDMA_SUBT_SUB1_CTRL_vs(data)                                            (0x00000008&((data)<<3))
#define  GDMA_SUBT_SUB1_CTRL_hs(data)                                            (0x00000004&((data)<<2))
#define  GDMA_SUBT_SUB1_CTRL_sub1_en(data)                                       (0x00000002&((data)<<1))
#define  GDMA_SUBT_SUB1_CTRL_write_data(data)                                    (0x00000001&(data))
#define  GDMA_SUBT_SUB1_CTRL_get_d3_mode(data)                                   ((0x00000200&(data))>>9)
#define  GDMA_SUBT_SUB1_CTRL_get_rotate(data)                                    ((0x00000100&(data))>>8)
#define  GDMA_SUBT_SUB1_CTRL_get_vs(data)                                        ((0x00000008&(data))>>3)
#define  GDMA_SUBT_SUB1_CTRL_get_hs(data)                                        ((0x00000004&(data))>>2)
#define  GDMA_SUBT_SUB1_CTRL_get_sub1_en(data)                                   ((0x00000002&(data))>>1)
#define  GDMA_SUBT_SUB1_CTRL_get_write_data(data)                                (0x00000001&(data))

#define  GDMA_SUBT_SUB1                                                          0x1802F024
#define  GDMA_SUBT_SUB1_reg_addr                                                 "0xB802F024"
#define  GDMA_SUBT_SUB1_reg                                                      0xB802F024
#define  GDMA_SUBT_SUB1_inst_addr                                                "0x0003"
#define  set_GDMA_SUBT_SUB1_reg(data)                                            (*((volatile unsigned int*)GDMA_SUBT_SUB1_reg)=data)
#define  get_GDMA_SUBT_SUB1_reg                                                  (*((volatile unsigned int*)GDMA_SUBT_SUB1_reg))
#define  GDMA_SUBT_SUB1_clut_keep_shift                                          (26)
#define  GDMA_SUBT_SUB1_wi_endian_shift                                          (25)
#define  GDMA_SUBT_SUB1_rgb_out_shift                                            (24)
#define  GDMA_SUBT_SUB1_dvd_shift                                                (23)
#define  GDMA_SUBT_SUB1_hddvd_shift                                              (22)
#define  GDMA_SUBT_SUB1_hl_shift                                                 (19)
#define  GDMA_SUBT_SUB1_osd_shift                                                (16)
#define  GDMA_SUBT_SUB1_vs_near_shift                                            (9)
#define  GDMA_SUBT_SUB1_vs_yodd_shift                                            (8)
#define  GDMA_SUBT_SUB1_vs_codd_shift                                            (7)
#define  GDMA_SUBT_SUB1_hs_yodd_shift                                            (5)
#define  GDMA_SUBT_SUB1_hs_codd_shift                                            (4)
#define  GDMA_SUBT_SUB1_write_data_shift                                         (0)
#define  GDMA_SUBT_SUB1_clut_keep_mask                                           (0x04000000)
#define  GDMA_SUBT_SUB1_wi_endian_mask                                           (0x02000000)
#define  GDMA_SUBT_SUB1_rgb_out_mask                                             (0x01000000)
#define  GDMA_SUBT_SUB1_dvd_mask                                                 (0x00800000)
#define  GDMA_SUBT_SUB1_hddvd_mask                                               (0x00400000)
#define  GDMA_SUBT_SUB1_hl_mask                                                  (0x00080000)
#define  GDMA_SUBT_SUB1_osd_mask                                                 (0x00010000)
#define  GDMA_SUBT_SUB1_vs_near_mask                                             (0x00000200)
#define  GDMA_SUBT_SUB1_vs_yodd_mask                                             (0x00000100)
#define  GDMA_SUBT_SUB1_vs_codd_mask                                             (0x00000080)
#define  GDMA_SUBT_SUB1_hs_yodd_mask                                             (0x00000020)
#define  GDMA_SUBT_SUB1_hs_codd_mask                                             (0x00000010)
#define  GDMA_SUBT_SUB1_write_data_mask                                          (0x00000001)
#define  GDMA_SUBT_SUB1_clut_keep(data)                                          (0x04000000&((data)<<26))
#define  GDMA_SUBT_SUB1_wi_endian(data)                                          (0x02000000&((data)<<25))
#define  GDMA_SUBT_SUB1_rgb_out(data)                                            (0x01000000&((data)<<24))
#define  GDMA_SUBT_SUB1_dvd(data)                                                (0x00800000&((data)<<23))
#define  GDMA_SUBT_SUB1_hddvd(data)                                              (0x00400000&((data)<<22))
#define  GDMA_SUBT_SUB1_hl(data)                                                 (0x00080000&((data)<<19))
#define  GDMA_SUBT_SUB1_osd(data)                                                (0x00010000&((data)<<16))
#define  GDMA_SUBT_SUB1_vs_near(data)                                            (0x00000200&((data)<<9))
#define  GDMA_SUBT_SUB1_vs_yodd(data)                                            (0x00000100&((data)<<8))
#define  GDMA_SUBT_SUB1_vs_codd(data)                                            (0x00000080&((data)<<7))
#define  GDMA_SUBT_SUB1_hs_yodd(data)                                            (0x00000020&((data)<<5))
#define  GDMA_SUBT_SUB1_hs_codd(data)                                            (0x00000010&((data)<<4))
#define  GDMA_SUBT_SUB1_write_data(data)                                         (0x00000001&(data))
#define  GDMA_SUBT_SUB1_get_clut_keep(data)                                      ((0x04000000&(data))>>26)
#define  GDMA_SUBT_SUB1_get_wi_endian(data)                                      ((0x02000000&(data))>>25)
#define  GDMA_SUBT_SUB1_get_rgb_out(data)                                        ((0x01000000&(data))>>24)
#define  GDMA_SUBT_SUB1_get_dvd(data)                                            ((0x00800000&(data))>>23)
#define  GDMA_SUBT_SUB1_get_hddvd(data)                                          ((0x00400000&(data))>>22)
#define  GDMA_SUBT_SUB1_get_hl(data)                                             ((0x00080000&(data))>>19)
#define  GDMA_SUBT_SUB1_get_osd(data)                                            ((0x00010000&(data))>>16)
#define  GDMA_SUBT_SUB1_get_vs_near(data)                                        ((0x00000200&(data))>>9)
#define  GDMA_SUBT_SUB1_get_vs_yodd(data)                                        ((0x00000100&(data))>>8)
#define  GDMA_SUBT_SUB1_get_vs_codd(data)                                        ((0x00000080&(data))>>7)
#define  GDMA_SUBT_SUB1_get_hs_yodd(data)                                        ((0x00000020&(data))>>5)
#define  GDMA_SUBT_SUB1_get_hs_codd(data)                                        ((0x00000010&(data))>>4)
#define  GDMA_SUBT_SUB1_get_write_data(data)                                     (0x00000001&(data))

#define  GDMA_SUBT_SUB1_START                                                    0x1802F028
#define  GDMA_SUBT_SUB1_START_reg_addr                                           "0xB802F028"
#define  GDMA_SUBT_SUB1_START_reg                                                0xB802F028
#define  GDMA_SUBT_SUB1_START_inst_addr                                          "0x0004"
#define  set_GDMA_SUBT_SUB1_START_reg(data)                                      (*((volatile unsigned int*)GDMA_SUBT_SUB1_START_reg)=data)
#define  get_GDMA_SUBT_SUB1_START_reg                                            (*((volatile unsigned int*)GDMA_SUBT_SUB1_START_reg))
#define  GDMA_SUBT_SUB1_START_th_shift                                           (0)
#define  GDMA_SUBT_SUB1_START_th_mask                                            (0x00001FFF)
#define  GDMA_SUBT_SUB1_START_th(data)                                           (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_START_get_th(data)                                       (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_VBI_END                                                  0x1802F02C
#define  GDMA_SUBT_SUB1_VBI_END_reg_addr                                         "0xB802F02C"
#define  GDMA_SUBT_SUB1_VBI_END_reg                                              0xB802F02C
#define  GDMA_SUBT_SUB1_VBI_END_inst_addr                                        "0x0005"
#define  set_GDMA_SUBT_SUB1_VBI_END_reg(data)                                    (*((volatile unsigned int*)GDMA_SUBT_SUB1_VBI_END_reg)=data)
#define  get_GDMA_SUBT_SUB1_VBI_END_reg                                          (*((volatile unsigned int*)GDMA_SUBT_SUB1_VBI_END_reg))
#define  GDMA_SUBT_SUB1_VBI_END_th_shift                                         (0)
#define  GDMA_SUBT_SUB1_VBI_END_th_mask                                          (0x00001FFF)
#define  GDMA_SUBT_SUB1_VBI_END_th(data)                                         (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_VBI_END_get_th(data)                                     (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_SUBP                                                     0x1802F030
#define  GDMA_SUBT_SUB1_SUBP_reg_addr                                            "0xB802F030"
#define  GDMA_SUBT_SUB1_SUBP_reg                                                 0xB802F030
#define  GDMA_SUBT_SUB1_SUBP_inst_addr                                           "0x0006"
#define  set_GDMA_SUBT_SUB1_SUBP_reg(data)                                       (*((volatile unsigned int*)GDMA_SUBT_SUB1_SUBP_reg)=data)
#define  get_GDMA_SUBT_SUB1_SUBP_reg                                             (*((volatile unsigned int*)GDMA_SUBT_SUB1_SUBP_reg))
#define  GDMA_SUBT_SUB1_SUBP_w_shift                                             (0)
#define  GDMA_SUBT_SUB1_SUBP_w_mask                                              (0x00001FFF)
#define  GDMA_SUBT_SUB1_SUBP_w(data)                                             (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_SUBP_get_w(data)                                         (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_SIZE                                                     0x1802F034
#define  GDMA_SUBT_SUB1_SIZE_reg_addr                                            "0xB802F034"
#define  GDMA_SUBT_SUB1_SIZE_reg                                                 0xB802F034
#define  GDMA_SUBT_SUB1_SIZE_inst_addr                                           "0x0007"
#define  set_GDMA_SUBT_SUB1_SIZE_reg(data)                                       (*((volatile unsigned int*)GDMA_SUBT_SUB1_SIZE_reg)=data)
#define  get_GDMA_SUBT_SUB1_SIZE_reg                                             (*((volatile unsigned int*)GDMA_SUBT_SUB1_SIZE_reg))
#define  GDMA_SUBT_SUB1_SIZE_w_shift                                             (16)
#define  GDMA_SUBT_SUB1_SIZE_h_shift                                             (0)
#define  GDMA_SUBT_SUB1_SIZE_w_mask                                              (0x1FFF0000)
#define  GDMA_SUBT_SUB1_SIZE_h_mask                                              (0x00001FFF)
#define  GDMA_SUBT_SUB1_SIZE_w(data)                                             (0x1FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_SIZE_h(data)                                             (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_SIZE_get_w(data)                                         ((0x1FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_SIZE_get_h(data)                                         (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_WI                                                       0x1802F038
#define  GDMA_SUBT_SUB1_WI_reg_addr                                              "0xB802F038"
#define  GDMA_SUBT_SUB1_WI_reg                                                   0xB802F038
#define  GDMA_SUBT_SUB1_WI_inst_addr                                             "0x0008"
#define  set_GDMA_SUBT_SUB1_WI_reg(data)                                         (*((volatile unsigned int*)GDMA_SUBT_SUB1_WI_reg)=data)
#define  get_GDMA_SUBT_SUB1_WI_reg                                               (*((volatile unsigned int*)GDMA_SUBT_SUB1_WI_reg))
#define  GDMA_SUBT_SUB1_WI_a_shift                                               (0)
#define  GDMA_SUBT_SUB1_WI_a_mask                                                (0xFFFFFFFF)
#define  GDMA_SUBT_SUB1_WI_a(data)                                               (0xFFFFFFFF&(data))
#define  GDMA_SUBT_SUB1_WI_get_a(data)                                           (0xFFFFFFFF&(data))

#define  GDMA_SUBT_SUB1_WI_3D                                                    0x1802F03C
#define  GDMA_SUBT_SUB1_WI_3D_reg_addr                                           "0xB802F03C"
#define  GDMA_SUBT_SUB1_WI_3D_reg                                                0xB802F03C
#define  GDMA_SUBT_SUB1_WI_3D_inst_addr                                          "0x0009"
#define  set_GDMA_SUBT_SUB1_WI_3D_reg(data)                                      (*((volatile unsigned int*)GDMA_SUBT_SUB1_WI_3D_reg)=data)
#define  get_GDMA_SUBT_SUB1_WI_3D_reg                                            (*((volatile unsigned int*)GDMA_SUBT_SUB1_WI_3D_reg))
#define  GDMA_SUBT_SUB1_WI_3D_a_shift                                            (0)
#define  GDMA_SUBT_SUB1_WI_3D_a_mask                                             (0xFFFFFFFF)
#define  GDMA_SUBT_SUB1_WI_3D_a(data)                                            (0xFFFFFFFF&(data))
#define  GDMA_SUBT_SUB1_WI_3D_get_a(data)                                        (0xFFFFFFFF&(data))

#define  GDMA_SUBT_SUB1_CLUT                                                     0x1802F040
#define  GDMA_SUBT_SUB1_CLUT_reg_addr                                            "0xB802F040"
#define  GDMA_SUBT_SUB1_CLUT_reg                                                 0xB802F040
#define  GDMA_SUBT_SUB1_CLUT_inst_addr                                           "0x000A"
#define  set_GDMA_SUBT_SUB1_CLUT_reg(data)                                       (*((volatile unsigned int*)GDMA_SUBT_SUB1_CLUT_reg)=data)
#define  get_GDMA_SUBT_SUB1_CLUT_reg                                             (*((volatile unsigned int*)GDMA_SUBT_SUB1_CLUT_reg))
#define  GDMA_SUBT_SUB1_CLUT_a_shift                                             (0)
#define  GDMA_SUBT_SUB1_CLUT_a_mask                                              (0xFFFFFFFF)
#define  GDMA_SUBT_SUB1_CLUT_a(data)                                             (0xFFFFFFFF&(data))
#define  GDMA_SUBT_SUB1_CLUT_get_a(data)                                         (0xFFFFFFFF&(data))

#define  GDMA_SUBT_SUB1_PXDT                                                     0x1802F044
#define  GDMA_SUBT_SUB1_PXDT_reg_addr                                            "0xB802F044"
#define  GDMA_SUBT_SUB1_PXDT_reg                                                 0xB802F044
#define  GDMA_SUBT_SUB1_PXDT_inst_addr                                           "0x000B"
#define  set_GDMA_SUBT_SUB1_PXDT_reg(data)                                       (*((volatile unsigned int*)GDMA_SUBT_SUB1_PXDT_reg)=data)
#define  get_GDMA_SUBT_SUB1_PXDT_reg                                             (*((volatile unsigned int*)GDMA_SUBT_SUB1_PXDT_reg))
#define  GDMA_SUBT_SUB1_PXDT_a_shift                                             (0)
#define  GDMA_SUBT_SUB1_PXDT_a_mask                                              (0xFFFFFFFF)
#define  GDMA_SUBT_SUB1_PXDT_a(data)                                             (0xFFFFFFFF&(data))
#define  GDMA_SUBT_SUB1_PXDT_get_a(data)                                         (0xFFFFFFFF&(data))

#define  GDMA_SUBT_SUB1_PXDB                                                     0x1802F048
#define  GDMA_SUBT_SUB1_PXDB_reg_addr                                            "0xB802F048"
#define  GDMA_SUBT_SUB1_PXDB_reg                                                 0xB802F048
#define  GDMA_SUBT_SUB1_PXDB_inst_addr                                           "0x000C"
#define  set_GDMA_SUBT_SUB1_PXDB_reg(data)                                       (*((volatile unsigned int*)GDMA_SUBT_SUB1_PXDB_reg)=data)
#define  get_GDMA_SUBT_SUB1_PXDB_reg                                             (*((volatile unsigned int*)GDMA_SUBT_SUB1_PXDB_reg))
#define  GDMA_SUBT_SUB1_PXDB_a_shift                                             (0)
#define  GDMA_SUBT_SUB1_PXDB_a_mask                                              (0xFFFFFFFF)
#define  GDMA_SUBT_SUB1_PXDB_a(data)                                             (0xFFFFFFFF&(data))
#define  GDMA_SUBT_SUB1_PXDB_get_a(data)                                         (0xFFFFFFFF&(data))

#define  GDMA_SUBT_SUB1_LC                                                       0x1802F04C
#define  GDMA_SUBT_SUB1_LC_reg_addr                                              "0xB802F04C"
#define  GDMA_SUBT_SUB1_LC_reg                                                   0xB802F04C
#define  GDMA_SUBT_SUB1_LC_inst_addr                                             "0x000D"
#define  set_GDMA_SUBT_SUB1_LC_reg(data)                                         (*((volatile unsigned int*)GDMA_SUBT_SUB1_LC_reg)=data)
#define  get_GDMA_SUBT_SUB1_LC_reg                                               (*((volatile unsigned int*)GDMA_SUBT_SUB1_LC_reg))
#define  GDMA_SUBT_SUB1_LC_num_shift                                             (0)
#define  GDMA_SUBT_SUB1_LC_num_mask                                              (0x00000FFF)
#define  GDMA_SUBT_SUB1_LC_num(data)                                             (0x00000FFF&(data))
#define  GDMA_SUBT_SUB1_LC_get_num(data)                                         (0x00000FFF&(data))

#define  GDMA_SUBT_SUB1_DFT                                                      0x1802F050
#define  GDMA_SUBT_SUB1_DFT_reg_addr                                             "0xB802F050"
#define  GDMA_SUBT_SUB1_DFT_reg                                                  0xB802F050
#define  GDMA_SUBT_SUB1_DFT_inst_addr                                            "0x000E"
#define  set_GDMA_SUBT_SUB1_DFT_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_DFT_reg)=data)
#define  get_GDMA_SUBT_SUB1_DFT_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_DFT_reg))
#define  GDMA_SUBT_SUB1_DFT_a3_shift                                             (28)
#define  GDMA_SUBT_SUB1_DFT_a2_shift                                             (24)
#define  GDMA_SUBT_SUB1_DFT_a1_shift                                             (20)
#define  GDMA_SUBT_SUB1_DFT_a0_shift                                             (16)
#define  GDMA_SUBT_SUB1_DFT_i3_shift                                             (12)
#define  GDMA_SUBT_SUB1_DFT_i2_shift                                             (8)
#define  GDMA_SUBT_SUB1_DFT_i1_shift                                             (4)
#define  GDMA_SUBT_SUB1_DFT_i0_shift                                             (0)
#define  GDMA_SUBT_SUB1_DFT_a3_mask                                              (0xF0000000)
#define  GDMA_SUBT_SUB1_DFT_a2_mask                                              (0x0F000000)
#define  GDMA_SUBT_SUB1_DFT_a1_mask                                              (0x00F00000)
#define  GDMA_SUBT_SUB1_DFT_a0_mask                                              (0x000F0000)
#define  GDMA_SUBT_SUB1_DFT_i3_mask                                              (0x0000F000)
#define  GDMA_SUBT_SUB1_DFT_i2_mask                                              (0x00000F00)
#define  GDMA_SUBT_SUB1_DFT_i1_mask                                              (0x000000F0)
#define  GDMA_SUBT_SUB1_DFT_i0_mask                                              (0x0000000F)
#define  GDMA_SUBT_SUB1_DFT_a3(data)                                             (0xF0000000&((data)<<28))
#define  GDMA_SUBT_SUB1_DFT_a2(data)                                             (0x0F000000&((data)<<24))
#define  GDMA_SUBT_SUB1_DFT_a1(data)                                             (0x00F00000&((data)<<20))
#define  GDMA_SUBT_SUB1_DFT_a0(data)                                             (0x000F0000&((data)<<16))
#define  GDMA_SUBT_SUB1_DFT_i3(data)                                             (0x0000F000&((data)<<12))
#define  GDMA_SUBT_SUB1_DFT_i2(data)                                             (0x00000F00&((data)<<8))
#define  GDMA_SUBT_SUB1_DFT_i1(data)                                             (0x000000F0&((data)<<4))
#define  GDMA_SUBT_SUB1_DFT_i0(data)                                             (0x0000000F&(data))
#define  GDMA_SUBT_SUB1_DFT_get_a3(data)                                         ((0xF0000000&(data))>>28)
#define  GDMA_SUBT_SUB1_DFT_get_a2(data)                                         ((0x0F000000&(data))>>24)
#define  GDMA_SUBT_SUB1_DFT_get_a1(data)                                         ((0x00F00000&(data))>>20)
#define  GDMA_SUBT_SUB1_DFT_get_a0(data)                                         ((0x000F0000&(data))>>16)
#define  GDMA_SUBT_SUB1_DFT_get_i3(data)                                         ((0x0000F000&(data))>>12)
#define  GDMA_SUBT_SUB1_DFT_get_i2(data)                                         ((0x00000F00&(data))>>8)
#define  GDMA_SUBT_SUB1_DFT_get_i1(data)                                         ((0x000000F0&(data))>>4)
#define  GDMA_SUBT_SUB1_DFT_get_i0(data)                                         (0x0000000F&(data))

#define  GDMA_SUBT_SUB1_HLX                                                      0x1802F054
#define  GDMA_SUBT_SUB1_HLX_reg_addr                                             "0xB802F054"
#define  GDMA_SUBT_SUB1_HLX_reg                                                  0xB802F054
#define  GDMA_SUBT_SUB1_HLX_inst_addr                                            "0x000F"
#define  set_GDMA_SUBT_SUB1_HLX_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_HLX_reg)=data)
#define  get_GDMA_SUBT_SUB1_HLX_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_HLX_reg))
#define  GDMA_SUBT_SUB1_HLX_e_shift                                              (16)
#define  GDMA_SUBT_SUB1_HLX_s_shift                                              (0)
#define  GDMA_SUBT_SUB1_HLX_e_mask                                               (0x1FFF0000)
#define  GDMA_SUBT_SUB1_HLX_s_mask                                               (0x00001FFF)
#define  GDMA_SUBT_SUB1_HLX_e(data)                                              (0x1FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HLX_s(data)                                              (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_HLX_get_e(data)                                          ((0x1FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HLX_get_s(data)                                          (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_HLY                                                      0x1802F058
#define  GDMA_SUBT_SUB1_HLY_reg_addr                                             "0xB802F058"
#define  GDMA_SUBT_SUB1_HLY_reg                                                  0xB802F058
#define  GDMA_SUBT_SUB1_HLY_inst_addr                                            "0x0010"
#define  set_GDMA_SUBT_SUB1_HLY_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_HLY_reg)=data)
#define  get_GDMA_SUBT_SUB1_HLY_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_HLY_reg))
#define  GDMA_SUBT_SUB1_HLY_e_shift                                              (16)
#define  GDMA_SUBT_SUB1_HLY_s_shift                                              (0)
#define  GDMA_SUBT_SUB1_HLY_e_mask                                               (0x1FFF0000)
#define  GDMA_SUBT_SUB1_HLY_s_mask                                               (0x00001FFF)
#define  GDMA_SUBT_SUB1_HLY_e(data)                                              (0x1FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HLY_s(data)                                              (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_HLY_get_e(data)                                          ((0x1FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HLY_get_s(data)                                          (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_HL                                                       0x1802F05C
#define  GDMA_SUBT_SUB1_HL_reg_addr                                              "0xB802F05C"
#define  GDMA_SUBT_SUB1_HL_reg                                                   0xB802F05C
#define  GDMA_SUBT_SUB1_HL_inst_addr                                             "0x0011"
#define  set_GDMA_SUBT_SUB1_HL_reg(data)                                         (*((volatile unsigned int*)GDMA_SUBT_SUB1_HL_reg)=data)
#define  get_GDMA_SUBT_SUB1_HL_reg                                               (*((volatile unsigned int*)GDMA_SUBT_SUB1_HL_reg))
#define  GDMA_SUBT_SUB1_HL_a3_shift                                              (28)
#define  GDMA_SUBT_SUB1_HL_a2_shift                                              (24)
#define  GDMA_SUBT_SUB1_HL_a1_shift                                              (20)
#define  GDMA_SUBT_SUB1_HL_a0_shift                                              (16)
#define  GDMA_SUBT_SUB1_HL_i3_shift                                              (12)
#define  GDMA_SUBT_SUB1_HL_i2_shift                                              (8)
#define  GDMA_SUBT_SUB1_HL_i1_shift                                              (4)
#define  GDMA_SUBT_SUB1_HL_i0_shift                                              (0)
#define  GDMA_SUBT_SUB1_HL_a3_mask                                               (0xF0000000)
#define  GDMA_SUBT_SUB1_HL_a2_mask                                               (0x0F000000)
#define  GDMA_SUBT_SUB1_HL_a1_mask                                               (0x00F00000)
#define  GDMA_SUBT_SUB1_HL_a0_mask                                               (0x000F0000)
#define  GDMA_SUBT_SUB1_HL_i3_mask                                               (0x0000F000)
#define  GDMA_SUBT_SUB1_HL_i2_mask                                               (0x00000F00)
#define  GDMA_SUBT_SUB1_HL_i1_mask                                               (0x000000F0)
#define  GDMA_SUBT_SUB1_HL_i0_mask                                               (0x0000000F)
#define  GDMA_SUBT_SUB1_HL_a3(data)                                              (0xF0000000&((data)<<28))
#define  GDMA_SUBT_SUB1_HL_a2(data)                                              (0x0F000000&((data)<<24))
#define  GDMA_SUBT_SUB1_HL_a1(data)                                              (0x00F00000&((data)<<20))
#define  GDMA_SUBT_SUB1_HL_a0(data)                                              (0x000F0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HL_i3(data)                                              (0x0000F000&((data)<<12))
#define  GDMA_SUBT_SUB1_HL_i2(data)                                              (0x00000F00&((data)<<8))
#define  GDMA_SUBT_SUB1_HL_i1(data)                                              (0x000000F0&((data)<<4))
#define  GDMA_SUBT_SUB1_HL_i0(data)                                              (0x0000000F&(data))
#define  GDMA_SUBT_SUB1_HL_get_a3(data)                                          ((0xF0000000&(data))>>28)
#define  GDMA_SUBT_SUB1_HL_get_a2(data)                                          ((0x0F000000&(data))>>24)
#define  GDMA_SUBT_SUB1_HL_get_a1(data)                                          ((0x00F00000&(data))>>20)
#define  GDMA_SUBT_SUB1_HL_get_a0(data)                                          ((0x000F0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HL_get_i3(data)                                          ((0x0000F000&(data))>>12)
#define  GDMA_SUBT_SUB1_HL_get_i2(data)                                          ((0x00000F00&(data))>>8)
#define  GDMA_SUBT_SUB1_HL_get_i1(data)                                          ((0x000000F0&(data))>>4)
#define  GDMA_SUBT_SUB1_HL_get_i0(data)                                          (0x0000000F&(data))

#define  GDMA_SUBT_SUB1_CC1                                                      0x1802F060
#define  GDMA_SUBT_SUB1_CC1_reg_addr                                             "0xB802F060"
#define  GDMA_SUBT_SUB1_CC1_reg                                                  0xB802F060
#define  GDMA_SUBT_SUB1_CC1_inst_addr                                            "0x0012"
#define  set_GDMA_SUBT_SUB1_CC1_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC1_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC1_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC1_reg))
#define  GDMA_SUBT_SUB1_CC1_m01_shift                                            (16)
#define  GDMA_SUBT_SUB1_CC1_m00_shift                                            (0)
#define  GDMA_SUBT_SUB1_CC1_m01_mask                                             (0x3FFF0000)
#define  GDMA_SUBT_SUB1_CC1_m00_mask                                             (0x00003FFF)
#define  GDMA_SUBT_SUB1_CC1_m01(data)                                            (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_CC1_m00(data)                                            (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_CC1_get_m01(data)                                        ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_CC1_get_m00(data)                                        (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_CC2                                                      0x1802F064
#define  GDMA_SUBT_SUB1_CC2_reg_addr                                             "0xB802F064"
#define  GDMA_SUBT_SUB1_CC2_reg                                                  0xB802F064
#define  GDMA_SUBT_SUB1_CC2_inst_addr                                            "0x0013"
#define  set_GDMA_SUBT_SUB1_CC2_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC2_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC2_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC2_reg))
#define  GDMA_SUBT_SUB1_CC2_m10_shift                                            (16)
#define  GDMA_SUBT_SUB1_CC2_m02_shift                                            (0)
#define  GDMA_SUBT_SUB1_CC2_m10_mask                                             (0x3FFF0000)
#define  GDMA_SUBT_SUB1_CC2_m02_mask                                             (0x00003FFF)
#define  GDMA_SUBT_SUB1_CC2_m10(data)                                            (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_CC2_m02(data)                                            (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_CC2_get_m10(data)                                        ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_CC2_get_m02(data)                                        (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_CC3                                                      0x1802F068
#define  GDMA_SUBT_SUB1_CC3_reg_addr                                             "0xB802F068"
#define  GDMA_SUBT_SUB1_CC3_reg                                                  0xB802F068
#define  GDMA_SUBT_SUB1_CC3_inst_addr                                            "0x0014"
#define  set_GDMA_SUBT_SUB1_CC3_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC3_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC3_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC3_reg))
#define  GDMA_SUBT_SUB1_CC3_m12_shift                                            (16)
#define  GDMA_SUBT_SUB1_CC3_m11_shift                                            (0)
#define  GDMA_SUBT_SUB1_CC3_m12_mask                                             (0x3FFF0000)
#define  GDMA_SUBT_SUB1_CC3_m11_mask                                             (0x00003FFF)
#define  GDMA_SUBT_SUB1_CC3_m12(data)                                            (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_CC3_m11(data)                                            (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_CC3_get_m12(data)                                        ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_CC3_get_m11(data)                                        (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_CC4                                                      0x1802F06C
#define  GDMA_SUBT_SUB1_CC4_reg_addr                                             "0xB802F06C"
#define  GDMA_SUBT_SUB1_CC4_reg                                                  0xB802F06C
#define  GDMA_SUBT_SUB1_CC4_inst_addr                                            "0x0015"
#define  set_GDMA_SUBT_SUB1_CC4_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC4_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC4_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC4_reg))
#define  GDMA_SUBT_SUB1_CC4_m21_shift                                            (16)
#define  GDMA_SUBT_SUB1_CC4_m20_shift                                            (0)
#define  GDMA_SUBT_SUB1_CC4_m21_mask                                             (0x3FFF0000)
#define  GDMA_SUBT_SUB1_CC4_m20_mask                                             (0x00003FFF)
#define  GDMA_SUBT_SUB1_CC4_m21(data)                                            (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_CC4_m20(data)                                            (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_CC4_get_m21(data)                                        ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_CC4_get_m20(data)                                        (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_CC5                                                      0x1802F070
#define  GDMA_SUBT_SUB1_CC5_reg_addr                                             "0xB802F070"
#define  GDMA_SUBT_SUB1_CC5_reg                                                  0xB802F070
#define  GDMA_SUBT_SUB1_CC5_inst_addr                                            "0x0016"
#define  set_GDMA_SUBT_SUB1_CC5_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC5_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC5_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC5_reg))
#define  GDMA_SUBT_SUB1_CC5_m22_shift                                            (0)
#define  GDMA_SUBT_SUB1_CC5_m22_mask                                             (0x00003FFF)
#define  GDMA_SUBT_SUB1_CC5_m22(data)                                            (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_CC5_get_m22(data)                                        (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_CC6                                                      0x1802F074
#define  GDMA_SUBT_SUB1_CC6_reg_addr                                             "0xB802F074"
#define  GDMA_SUBT_SUB1_CC6_reg                                                  0xB802F074
#define  GDMA_SUBT_SUB1_CC6_inst_addr                                            "0x0017"
#define  set_GDMA_SUBT_SUB1_CC6_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC6_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC6_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC6_reg))
#define  GDMA_SUBT_SUB1_CC6_a2_shift                                             (18)
#define  GDMA_SUBT_SUB1_CC6_a1_shift                                             (9)
#define  GDMA_SUBT_SUB1_CC6_a0_shift                                             (0)
#define  GDMA_SUBT_SUB1_CC6_a2_mask                                              (0x07FC0000)
#define  GDMA_SUBT_SUB1_CC6_a1_mask                                              (0x0003FE00)
#define  GDMA_SUBT_SUB1_CC6_a0_mask                                              (0x000001FF)
#define  GDMA_SUBT_SUB1_CC6_a2(data)                                             (0x07FC0000&((data)<<18))
#define  GDMA_SUBT_SUB1_CC6_a1(data)                                             (0x0003FE00&((data)<<9))
#define  GDMA_SUBT_SUB1_CC6_a0(data)                                             (0x000001FF&(data))
#define  GDMA_SUBT_SUB1_CC6_get_a2(data)                                         ((0x07FC0000&(data))>>18)
#define  GDMA_SUBT_SUB1_CC6_get_a1(data)                                         ((0x0003FE00&(data))>>9)
#define  GDMA_SUBT_SUB1_CC6_get_a0(data)                                         (0x000001FF&(data))

#define  GDMA_SUBT_SUB1_CC7                                                      0x1802F0EC
#define  GDMA_SUBT_SUB1_CC7_reg_addr                                             "0xB802F0EC"
#define  GDMA_SUBT_SUB1_CC7_reg                                                  0xB802F0EC
#define  GDMA_SUBT_SUB1_CC7_inst_addr                                            "0x0018"
#define  set_GDMA_SUBT_SUB1_CC7_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC7_reg)=data)
#define  get_GDMA_SUBT_SUB1_CC7_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_CC7_reg))
#define  GDMA_SUBT_SUB1_CC7_b2_shift                                             (18)
#define  GDMA_SUBT_SUB1_CC7_b1_shift                                             (9)
#define  GDMA_SUBT_SUB1_CC7_b0_shift                                             (0)
#define  GDMA_SUBT_SUB1_CC7_b2_mask                                              (0x07FC0000)
#define  GDMA_SUBT_SUB1_CC7_b1_mask                                              (0x0003FE00)
#define  GDMA_SUBT_SUB1_CC7_b0_mask                                              (0x000001FF)
#define  GDMA_SUBT_SUB1_CC7_b2(data)                                             (0x07FC0000&((data)<<18))
#define  GDMA_SUBT_SUB1_CC7_b1(data)                                             (0x0003FE00&((data)<<9))
#define  GDMA_SUBT_SUB1_CC7_b0(data)                                             (0x000001FF&(data))
#define  GDMA_SUBT_SUB1_CC7_get_b2(data)                                         ((0x07FC0000&(data))>>18)
#define  GDMA_SUBT_SUB1_CC7_get_b1(data)                                         ((0x0003FE00&(data))>>9)
#define  GDMA_SUBT_SUB1_CC7_get_b0(data)                                         (0x000001FF&(data))

#define  GDMA_SUBT_SUB1_VSI                                                      0x1802F078
#define  GDMA_SUBT_SUB1_VSI_reg_addr                                             "0xB802F078"
#define  GDMA_SUBT_SUB1_VSI_reg                                                  0xB802F078
#define  GDMA_SUBT_SUB1_VSI_inst_addr                                            "0x0019"
#define  set_GDMA_SUBT_SUB1_VSI_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSI_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSI_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSI_reg))
#define  GDMA_SUBT_SUB1_VSI_offset_shift                                         (16)
#define  GDMA_SUBT_SUB1_VSI_phase_shift                                          (2)
#define  GDMA_SUBT_SUB1_VSI_offset_mask                                          (0x1FFF0000)
#define  GDMA_SUBT_SUB1_VSI_phase_mask                                           (0x0000FFFC)
#define  GDMA_SUBT_SUB1_VSI_offset(data)                                         (0x1FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_VSI_phase(data)                                          (0x0000FFFC&((data)<<2))
#define  GDMA_SUBT_SUB1_VSI_get_offset(data)                                     ((0x1FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_VSI_get_phase(data)                                      ((0x0000FFFC&(data))>>2)

#define  GDMA_SUBT_SUB1_VSD_OUT                                                  0x1802F07C
#define  GDMA_SUBT_SUB1_VSD_OUT_reg_addr                                         "0xB802F07C"
#define  GDMA_SUBT_SUB1_VSD_OUT_reg                                              0xB802F07C
#define  GDMA_SUBT_SUB1_VSD_OUT_inst_addr                                        "0x001A"
#define  set_GDMA_SUBT_SUB1_VSD_OUT_reg(data)                                    (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSD_OUT_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSD_OUT_reg                                          (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSD_OUT_reg))
#define  GDMA_SUBT_SUB1_VSD_OUT_out_shift                                        (0)
#define  GDMA_SUBT_SUB1_VSD_OUT_out_mask                                         (0x00001FFF)
#define  GDMA_SUBT_SUB1_VSD_OUT_out(data)                                        (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_VSD_OUT_get_out(data)                                    (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_VSD                                                      0x1802F080
#define  GDMA_SUBT_SUB1_VSD_reg_addr                                             "0xB802F080"
#define  GDMA_SUBT_SUB1_VSD_reg                                                  0xB802F080
#define  GDMA_SUBT_SUB1_VSD_inst_addr                                            "0x001B"
#define  set_GDMA_SUBT_SUB1_VSD_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSD_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSD_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSD_reg))
#define  GDMA_SUBT_SUB1_VSD_delta_shift                                          (0)
#define  GDMA_SUBT_SUB1_VSD_delta_mask                                           (0x0007FFFF)
#define  GDMA_SUBT_SUB1_VSD_delta(data)                                          (0x0007FFFF&(data))
#define  GDMA_SUBT_SUB1_VSD_get_delta(data)                                      (0x0007FFFF&(data))

#define  GDMA_SUBT_SUB1_VSYC_0                                                   0x1802F084
#define  GDMA_SUBT_SUB1_VSYC_0_reg_addr                                          "0xB802F084"
#define  GDMA_SUBT_SUB1_VSYC_0_reg                                               0xB802F084
#define  GDMA_SUBT_SUB1_VSYC_0_inst_addr                                         "0x001C"
#define  set_GDMA_SUBT_SUB1_VSYC_0_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_0_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSYC_0_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_0_reg))
#define  GDMA_SUBT_SUB1_VSYC_0_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_VSYC_0_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_VSYC_0_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_VSYC_0_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_VSYC_0_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_VSYC_0_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_VSYC_0_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_VSYC_0_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_VSYC_1                                                   0x1802F088
#define  GDMA_SUBT_SUB1_VSYC_1_reg_addr                                          "0xB802F088"
#define  GDMA_SUBT_SUB1_VSYC_1_reg                                               0xB802F088
#define  GDMA_SUBT_SUB1_VSYC_1_inst_addr                                         "0x001D"
#define  set_GDMA_SUBT_SUB1_VSYC_1_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_1_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSYC_1_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_1_reg))
#define  GDMA_SUBT_SUB1_VSYC_1_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_VSYC_1_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_VSYC_1_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_VSYC_1_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_VSYC_1_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_VSYC_1_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_VSYC_1_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_VSYC_1_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_VSYC_2                                                   0x1802F08C
#define  GDMA_SUBT_SUB1_VSYC_2_reg_addr                                          "0xB802F08C"
#define  GDMA_SUBT_SUB1_VSYC_2_reg                                               0xB802F08C
#define  GDMA_SUBT_SUB1_VSYC_2_inst_addr                                         "0x001E"
#define  set_GDMA_SUBT_SUB1_VSYC_2_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_2_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSYC_2_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_2_reg))
#define  GDMA_SUBT_SUB1_VSYC_2_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_VSYC_2_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_VSYC_2_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_VSYC_2_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_VSYC_2_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_VSYC_2_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_VSYC_2_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_VSYC_2_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_VSYC_3                                                   0x1802F090
#define  GDMA_SUBT_SUB1_VSYC_3_reg_addr                                          "0xB802F090"
#define  GDMA_SUBT_SUB1_VSYC_3_reg                                               0xB802F090
#define  GDMA_SUBT_SUB1_VSYC_3_inst_addr                                         "0x001F"
#define  set_GDMA_SUBT_SUB1_VSYC_3_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_3_reg)=data)
#define  get_GDMA_SUBT_SUB1_VSYC_3_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_VSYC_3_reg))
#define  GDMA_SUBT_SUB1_VSYC_3_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_VSYC_3_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_VSYC_3_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_VSYC_3_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_VSYC_3_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_VSYC_3_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_VSYC_3_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_VSYC_3_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSI                                                      0x1802F094
#define  GDMA_SUBT_SUB1_HSI_reg_addr                                             "0xB802F094"
#define  GDMA_SUBT_SUB1_HSI_reg                                                  0xB802F094
#define  GDMA_SUBT_SUB1_HSI_inst_addr                                            "0x0020"
#define  set_GDMA_SUBT_SUB1_HSI_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSI_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSI_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSI_reg))
#define  GDMA_SUBT_SUB1_HSI_offset_shift                                         (16)
#define  GDMA_SUBT_SUB1_HSI_phase_shift                                          (2)
#define  GDMA_SUBT_SUB1_HSI_offset_mask                                          (0x1FFF0000)
#define  GDMA_SUBT_SUB1_HSI_phase_mask                                           (0x0000FFFC)
#define  GDMA_SUBT_SUB1_HSI_offset(data)                                         (0x1FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSI_phase(data)                                          (0x0000FFFC&((data)<<2))
#define  GDMA_SUBT_SUB1_HSI_get_offset(data)                                     ((0x1FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSI_get_phase(data)                                      ((0x0000FFFC&(data))>>2)

#define  GDMA_SUBT_SUB1_HSD_OUT                                                  0x1802F098
#define  GDMA_SUBT_SUB1_HSD_OUT_reg_addr                                         "0xB802F098"
#define  GDMA_SUBT_SUB1_HSD_OUT_reg                                              0xB802F098
#define  GDMA_SUBT_SUB1_HSD_OUT_inst_addr                                        "0x0021"
#define  set_GDMA_SUBT_SUB1_HSD_OUT_reg(data)                                    (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSD_OUT_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSD_OUT_reg                                          (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSD_OUT_reg))
#define  GDMA_SUBT_SUB1_HSD_OUT_out_shift                                        (0)
#define  GDMA_SUBT_SUB1_HSD_OUT_out_mask                                         (0x00001FFF)
#define  GDMA_SUBT_SUB1_HSD_OUT_out(data)                                        (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_HSD_OUT_get_out(data)                                    (0x00001FFF&(data))

#define  GDMA_SUBT_SUB1_HSD                                                      0x1802F09C
#define  GDMA_SUBT_SUB1_HSD_reg_addr                                             "0xB802F09C"
#define  GDMA_SUBT_SUB1_HSD_reg                                                  0xB802F09C
#define  GDMA_SUBT_SUB1_HSD_inst_addr                                            "0x0022"
#define  set_GDMA_SUBT_SUB1_HSD_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSD_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSD_reg                                              (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSD_reg))
#define  GDMA_SUBT_SUB1_HSD_delta_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSD_delta_mask                                           (0x0007FFFF)
#define  GDMA_SUBT_SUB1_HSD_delta(data)                                          (0x0007FFFF&(data))
#define  GDMA_SUBT_SUB1_HSD_get_delta(data)                                      (0x0007FFFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_0                                                   0x1802F0A0
#define  GDMA_SUBT_SUB1_HSYC_0_reg_addr                                          "0xB802F0A0"
#define  GDMA_SUBT_SUB1_HSYC_0_reg                                               0xB802F0A0
#define  GDMA_SUBT_SUB1_HSYC_0_inst_addr                                         "0x0023"
#define  set_GDMA_SUBT_SUB1_HSYC_0_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_0_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_0_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_0_reg))
#define  GDMA_SUBT_SUB1_HSYC_0_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_0_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_0_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_0_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_0_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_0_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_0_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_0_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_1                                                   0x1802F0A4
#define  GDMA_SUBT_SUB1_HSYC_1_reg_addr                                          "0xB802F0A4"
#define  GDMA_SUBT_SUB1_HSYC_1_reg                                               0xB802F0A4
#define  GDMA_SUBT_SUB1_HSYC_1_inst_addr                                         "0x0024"
#define  set_GDMA_SUBT_SUB1_HSYC_1_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_1_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_1_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_1_reg))
#define  GDMA_SUBT_SUB1_HSYC_1_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_1_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_1_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_1_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_1_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_1_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_1_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_1_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_2                                                   0x1802F0A8
#define  GDMA_SUBT_SUB1_HSYC_2_reg_addr                                          "0xB802F0A8"
#define  GDMA_SUBT_SUB1_HSYC_2_reg                                               0xB802F0A8
#define  GDMA_SUBT_SUB1_HSYC_2_inst_addr                                         "0x0025"
#define  set_GDMA_SUBT_SUB1_HSYC_2_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_2_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_2_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_2_reg))
#define  GDMA_SUBT_SUB1_HSYC_2_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_2_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_2_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_2_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_2_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_2_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_2_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_2_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_3                                                   0x1802F0AC
#define  GDMA_SUBT_SUB1_HSYC_3_reg_addr                                          "0xB802F0AC"
#define  GDMA_SUBT_SUB1_HSYC_3_reg                                               0xB802F0AC
#define  GDMA_SUBT_SUB1_HSYC_3_inst_addr                                         "0x0026"
#define  set_GDMA_SUBT_SUB1_HSYC_3_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_3_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_3_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_3_reg))
#define  GDMA_SUBT_SUB1_HSYC_3_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_3_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_3_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_3_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_3_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_3_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_3_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_3_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_4                                                   0x1802F0B0
#define  GDMA_SUBT_SUB1_HSYC_4_reg_addr                                          "0xB802F0B0"
#define  GDMA_SUBT_SUB1_HSYC_4_reg                                               0xB802F0B0
#define  GDMA_SUBT_SUB1_HSYC_4_inst_addr                                         "0x0027"
#define  set_GDMA_SUBT_SUB1_HSYC_4_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_4_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_4_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_4_reg))
#define  GDMA_SUBT_SUB1_HSYC_4_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_4_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_4_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_4_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_4_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_4_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_4_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_4_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_5                                                   0x1802F0B4
#define  GDMA_SUBT_SUB1_HSYC_5_reg_addr                                          "0xB802F0B4"
#define  GDMA_SUBT_SUB1_HSYC_5_reg                                               0xB802F0B4
#define  GDMA_SUBT_SUB1_HSYC_5_inst_addr                                         "0x0028"
#define  set_GDMA_SUBT_SUB1_HSYC_5_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_5_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_5_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_5_reg))
#define  GDMA_SUBT_SUB1_HSYC_5_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_5_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_5_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_5_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_5_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_5_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_5_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_5_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_6                                                   0x1802F0B8
#define  GDMA_SUBT_SUB1_HSYC_6_reg_addr                                          "0xB802F0B8"
#define  GDMA_SUBT_SUB1_HSYC_6_reg                                               0xB802F0B8
#define  GDMA_SUBT_SUB1_HSYC_6_inst_addr                                         "0x0029"
#define  set_GDMA_SUBT_SUB1_HSYC_6_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_6_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_6_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_6_reg))
#define  GDMA_SUBT_SUB1_HSYC_6_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_6_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_6_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_6_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_6_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_6_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_6_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_6_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_SUB1_HSYC_7                                                   0x1802F0BC
#define  GDMA_SUBT_SUB1_HSYC_7_reg_addr                                          "0xB802F0BC"
#define  GDMA_SUBT_SUB1_HSYC_7_reg                                               0xB802F0BC
#define  GDMA_SUBT_SUB1_HSYC_7_inst_addr                                         "0x002A"
#define  set_GDMA_SUBT_SUB1_HSYC_7_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_7_reg)=data)
#define  get_GDMA_SUBT_SUB1_HSYC_7_reg                                           (*((volatile unsigned int*)GDMA_SUBT_SUB1_HSYC_7_reg))
#define  GDMA_SUBT_SUB1_HSYC_7_c1_shift                                          (16)
#define  GDMA_SUBT_SUB1_HSYC_7_c0_shift                                          (0)
#define  GDMA_SUBT_SUB1_HSYC_7_c1_mask                                           (0x3FFF0000)
#define  GDMA_SUBT_SUB1_HSYC_7_c0_mask                                           (0x00003FFF)
#define  GDMA_SUBT_SUB1_HSYC_7_c1(data)                                          (0x3FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_HSYC_7_c0(data)                                          (0x00003FFF&(data))
#define  GDMA_SUBT_SUB1_HSYC_7_get_c1(data)                                      ((0x3FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_HSYC_7_get_c0(data)                                      (0x00003FFF&(data))

#define  GDMA_SUBT_DMA                                                           0x1802F0C0
#define  GDMA_SUBT_DMA_reg_addr                                                  "0xB802F0C0"
#define  GDMA_SUBT_DMA_reg                                                       0xB802F0C0
#define  GDMA_SUBT_DMA_inst_addr                                                 "0x002B"
#define  set_GDMA_SUBT_DMA_reg(data)                                             (*((volatile unsigned int*)GDMA_SUBT_DMA_reg)=data)
#define  get_GDMA_SUBT_DMA_reg                                                   (*((volatile unsigned int*)GDMA_SUBT_DMA_reg))
#define  GDMA_SUBT_DMA_sub1_mask_shift                                           (28)
#define  GDMA_SUBT_DMA_sub1_req_num_shift                                        (22)
#define  GDMA_SUBT_DMA_sub1_bl_shift                                             (0)
#define  GDMA_SUBT_DMA_sub1_mask_mask                                            (0x10000000)
#define  GDMA_SUBT_DMA_sub1_req_num_mask                                         (0x00C00000)
#define  GDMA_SUBT_DMA_sub1_bl_mask                                              (0x0000007F)
#define  GDMA_SUBT_DMA_sub1_mask(data)                                           (0x10000000&((data)<<28))
#define  GDMA_SUBT_DMA_sub1_req_num(data)                                        (0x00C00000&((data)<<22))
#define  GDMA_SUBT_DMA_sub1_bl(data)                                             (0x0000007F&(data))
#define  GDMA_SUBT_DMA_get_sub1_mask(data)                                       ((0x10000000&(data))>>28)
#define  GDMA_SUBT_DMA_get_sub1_req_num(data)                                    ((0x00C00000&(data))>>22)
#define  GDMA_SUBT_DMA_get_sub1_bl(data)                                         (0x0000007F&(data))

#define  GDMA_SUBT_DMA_SWAP                                                      0x1802F0C4
#define  GDMA_SUBT_DMA_SWAP_reg_addr                                             "0xB802F0C4"
#define  GDMA_SUBT_DMA_SWAP_reg                                                  0xB802F0C4
#define  GDMA_SUBT_DMA_SWAP_inst_addr                                            "0x002C"
#define  set_GDMA_SUBT_DMA_SWAP_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_DMA_SWAP_reg)=data)
#define  get_GDMA_SUBT_DMA_SWAP_reg                                              (*((volatile unsigned int*)GDMA_SUBT_DMA_SWAP_reg))
#define  GDMA_SUBT_DMA_SWAP_m422_cb_cr_swap_shift                                (16)
#define  GDMA_SUBT_DMA_SWAP_sub1_1b_shift                                        (7)
#define  GDMA_SUBT_DMA_SWAP_sub1_2b_shift                                        (6)
#define  GDMA_SUBT_DMA_SWAP_sub1_4b_shift                                        (5)
#define  GDMA_SUBT_DMA_SWAP_sub1_8b_shift                                        (4)
#define  GDMA_SUBT_DMA_SWAP_write_data_shift                                     (0)
#define  GDMA_SUBT_DMA_SWAP_m422_cb_cr_swap_mask                                 (0x00010000)
#define  GDMA_SUBT_DMA_SWAP_sub1_1b_mask                                         (0x00000080)
#define  GDMA_SUBT_DMA_SWAP_sub1_2b_mask                                         (0x00000040)
#define  GDMA_SUBT_DMA_SWAP_sub1_4b_mask                                         (0x00000020)
#define  GDMA_SUBT_DMA_SWAP_sub1_8b_mask                                         (0x00000010)
#define  GDMA_SUBT_DMA_SWAP_write_data_mask                                      (0x00000001)
#define  GDMA_SUBT_DMA_SWAP_m422_cb_cr_swap(data)                                (0x00010000&((data)<<16))
#define  GDMA_SUBT_DMA_SWAP_sub1_1b(data)                                        (0x00000080&((data)<<7))
#define  GDMA_SUBT_DMA_SWAP_sub1_2b(data)                                        (0x00000040&((data)<<6))
#define  GDMA_SUBT_DMA_SWAP_sub1_4b(data)                                        (0x00000020&((data)<<5))
#define  GDMA_SUBT_DMA_SWAP_sub1_8b(data)                                        (0x00000010&((data)<<4))
#define  GDMA_SUBT_DMA_SWAP_write_data(data)                                     (0x00000001&(data))
#define  GDMA_SUBT_DMA_SWAP_get_m422_cb_cr_swap(data)                            ((0x00010000&(data))>>16)
#define  GDMA_SUBT_DMA_SWAP_get_sub1_1b(data)                                    ((0x00000080&(data))>>7)
#define  GDMA_SUBT_DMA_SWAP_get_sub1_2b(data)                                    ((0x00000040&(data))>>6)
#define  GDMA_SUBT_DMA_SWAP_get_sub1_4b(data)                                    ((0x00000020&(data))>>5)
#define  GDMA_SUBT_DMA_SWAP_get_sub1_8b(data)                                    ((0x00000010&(data))>>4)
#define  GDMA_SUBT_DMA_SWAP_get_write_data(data)                                 (0x00000001&(data))

#define  GDMA_SUBT_DMA_SUB1_WI                                                   0x1802F0C8
#define  GDMA_SUBT_DMA_SUB1_WI_reg_addr                                          "0xB802F0C8"
#define  GDMA_SUBT_DMA_SUB1_WI_reg                                               0xB802F0C8
#define  GDMA_SUBT_DMA_SUB1_WI_inst_addr                                         "0x002D"
#define  set_GDMA_SUBT_DMA_SUB1_WI_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_DMA_SUB1_WI_reg)=data)
#define  get_GDMA_SUBT_DMA_SUB1_WI_reg                                           (*((volatile unsigned int*)GDMA_SUBT_DMA_SUB1_WI_reg))
#define  GDMA_SUBT_DMA_SUB1_WI_depth_shift                                       (12)
#define  GDMA_SUBT_DMA_SUB1_WI_sa_shift                                          (0)
#define  GDMA_SUBT_DMA_SUB1_WI_depth_mask                                        (0x00FFF000)
#define  GDMA_SUBT_DMA_SUB1_WI_sa_mask                                           (0x00000FFF)
#define  GDMA_SUBT_DMA_SUB1_WI_depth(data)                                       (0x00FFF000&((data)<<12))
#define  GDMA_SUBT_DMA_SUB1_WI_sa(data)                                          (0x00000FFF&(data))
#define  GDMA_SUBT_DMA_SUB1_WI_get_depth(data)                                   ((0x00FFF000&(data))>>12)
#define  GDMA_SUBT_DMA_SUB1_WI_get_sa(data)                                      (0x00000FFF&(data))

#define  GDMA_SUBT_DMA_SUB1_D0                                                   0x1802F0CC
#define  GDMA_SUBT_DMA_SUB1_D0_reg_addr                                          "0xB802F0CC"
#define  GDMA_SUBT_DMA_SUB1_D0_reg                                               0xB802F0CC
#define  GDMA_SUBT_DMA_SUB1_D0_inst_addr                                         "0x002E"
#define  set_GDMA_SUBT_DMA_SUB1_D0_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_DMA_SUB1_D0_reg)=data)
#define  get_GDMA_SUBT_DMA_SUB1_D0_reg                                           (*((volatile unsigned int*)GDMA_SUBT_DMA_SUB1_D0_reg))
#define  GDMA_SUBT_DMA_SUB1_D0_depth_shift                                       (12)
#define  GDMA_SUBT_DMA_SUB1_D0_sa_shift                                          (0)
#define  GDMA_SUBT_DMA_SUB1_D0_depth_mask                                        (0x00FFF000)
#define  GDMA_SUBT_DMA_SUB1_D0_sa_mask                                           (0x00000FFF)
#define  GDMA_SUBT_DMA_SUB1_D0_depth(data)                                       (0x00FFF000&((data)<<12))
#define  GDMA_SUBT_DMA_SUB1_D0_sa(data)                                          (0x00000FFF&(data))
#define  GDMA_SUBT_DMA_SUB1_D0_get_depth(data)                                   ((0x00FFF000&(data))>>12)
#define  GDMA_SUBT_DMA_SUB1_D0_get_sa(data)                                      (0x00000FFF&(data))

#define  GDMA_SUBT_DMA_SUB1_D1                                                   0x1802F0D0
#define  GDMA_SUBT_DMA_SUB1_D1_reg_addr                                          "0xB802F0D0"
#define  GDMA_SUBT_DMA_SUB1_D1_reg                                               0xB802F0D0
#define  GDMA_SUBT_DMA_SUB1_D1_inst_addr                                         "0x002F"
#define  set_GDMA_SUBT_DMA_SUB1_D1_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_DMA_SUB1_D1_reg)=data)
#define  get_GDMA_SUBT_DMA_SUB1_D1_reg                                           (*((volatile unsigned int*)GDMA_SUBT_DMA_SUB1_D1_reg))
#define  GDMA_SUBT_DMA_SUB1_D1_depth_shift                                       (12)
#define  GDMA_SUBT_DMA_SUB1_D1_sa_shift                                          (0)
#define  GDMA_SUBT_DMA_SUB1_D1_depth_mask                                        (0x00FFF000)
#define  GDMA_SUBT_DMA_SUB1_D1_sa_mask                                           (0x00000FFF)
#define  GDMA_SUBT_DMA_SUB1_D1_depth(data)                                       (0x00FFF000&((data)<<12))
#define  GDMA_SUBT_DMA_SUB1_D1_sa(data)                                          (0x00000FFF&(data))
#define  GDMA_SUBT_DMA_SUB1_D1_get_depth(data)                                   ((0x00FFF000&(data))>>12)
#define  GDMA_SUBT_DMA_SUB1_D1_get_sa(data)                                      (0x00000FFF&(data))

#define  GDMA_SUBT_SUB1_XY                                                       0x1802F0D4
#define  GDMA_SUBT_SUB1_XY_reg_addr                                              "0xB802F0D4"
#define  GDMA_SUBT_SUB1_XY_reg                                                   0xB802F0D4
#define  GDMA_SUBT_SUB1_XY_inst_addr                                             "0x0030"
#define  set_GDMA_SUBT_SUB1_XY_reg(data)                                         (*((volatile unsigned int*)GDMA_SUBT_SUB1_XY_reg)=data)
#define  get_GDMA_SUBT_SUB1_XY_reg                                               (*((volatile unsigned int*)GDMA_SUBT_SUB1_XY_reg))
#define  GDMA_SUBT_SUB1_XY_x_shift                                               (16)
#define  GDMA_SUBT_SUB1_XY_y_shift                                               (0)
#define  GDMA_SUBT_SUB1_XY_x_mask                                                (0x1FFF0000)
#define  GDMA_SUBT_SUB1_XY_y_mask                                                (0x00001FFF)
#define  GDMA_SUBT_SUB1_XY_x(data)                                               (0x1FFF0000&((data)<<16))
#define  GDMA_SUBT_SUB1_XY_y(data)                                               (0x00001FFF&(data))
#define  GDMA_SUBT_SUB1_XY_get_x(data)                                           ((0x1FFF0000&(data))>>16)
#define  GDMA_SUBT_SUB1_XY_get_y(data)                                           (0x00001FFF&(data))

#define  GDMA_SUBT_INTEN                                                         0x1802F0D8
#define  GDMA_SUBT_INTEN_reg_addr                                                "0xB802F0D8"
#define  GDMA_SUBT_INTEN_reg                                                     0xB802F0D8
#define  GDMA_SUBT_INTEN_inst_addr                                               "0x0031"
#define  set_GDMA_SUBT_INTEN_reg(data)                                           (*((volatile unsigned int*)GDMA_SUBT_INTEN_reg)=data)
#define  get_GDMA_SUBT_INTEN_reg                                                 (*((volatile unsigned int*)GDMA_SUBT_INTEN_reg))
#define  GDMA_SUBT_INTEN_sub1_acc_sync_shift                                     (20)
#define  GDMA_SUBT_INTEN_sub1_udfl_shift                                         (14)
#define  GDMA_SUBT_INTEN_sub1_shift                                              (13)
#define  GDMA_SUBT_INTEN_sub1_fin_shift                                          (9)
#define  GDMA_SUBT_INTEN_sub1_vact_end_shift                                     (5)
#define  GDMA_SUBT_INTEN_sub1_vsync_shift                                        (1)
#define  GDMA_SUBT_INTEN_write_data_shift                                        (0)
#define  GDMA_SUBT_INTEN_sub1_acc_sync_mask                                      (0x00100000)
#define  GDMA_SUBT_INTEN_sub1_udfl_mask                                          (0x00004000)
#define  GDMA_SUBT_INTEN_sub1_mask                                               (0x00002000)
#define  GDMA_SUBT_INTEN_sub1_fin_mask                                           (0x00000200)
#define  GDMA_SUBT_INTEN_sub1_vact_end_mask                                      (0x00000020)
#define  GDMA_SUBT_INTEN_sub1_vsync_mask                                         (0x00000002)
#define  GDMA_SUBT_INTEN_write_data_mask                                         (0x00000001)
#define  GDMA_SUBT_INTEN_sub1_acc_sync(data)                                     (0x00100000&((data)<<20))
#define  GDMA_SUBT_INTEN_sub1_udfl(data)                                         (0x00004000&((data)<<14))
#define  GDMA_SUBT_INTEN_sub1(data)                                              (0x00002000&((data)<<13))
#define  GDMA_SUBT_INTEN_sub1_fin(data)                                          (0x00000200&((data)<<9))
#define  GDMA_SUBT_INTEN_sub1_vact_end(data)                                     (0x00000020&((data)<<5))
#define  GDMA_SUBT_INTEN_sub1_vsync(data)                                        (0x00000002&((data)<<1))
#define  GDMA_SUBT_INTEN_write_data(data)                                        (0x00000001&(data))
#define  GDMA_SUBT_INTEN_get_sub1_acc_sync(data)                                 ((0x00100000&(data))>>20)
#define  GDMA_SUBT_INTEN_get_sub1_udfl(data)                                     ((0x00004000&(data))>>14)
#define  GDMA_SUBT_INTEN_get_sub1(data)                                          ((0x00002000&(data))>>13)
#define  GDMA_SUBT_INTEN_get_sub1_fin(data)                                      ((0x00000200&(data))>>9)
#define  GDMA_SUBT_INTEN_get_sub1_vact_end(data)                                 ((0x00000020&(data))>>5)
#define  GDMA_SUBT_INTEN_get_sub1_vsync(data)                                    ((0x00000002&(data))>>1)
#define  GDMA_SUBT_INTEN_get_write_data(data)                                    (0x00000001&(data))

#define  GDMA_SUBT_INTST                                                         0x1802F0DC
#define  GDMA_SUBT_INTST_reg_addr                                                "0xB802F0DC"
#define  GDMA_SUBT_INTST_reg                                                     0xB802F0DC
#define  GDMA_SUBT_INTST_inst_addr                                               "0x0032"
#define  set_GDMA_SUBT_INTST_reg(data)                                           (*((volatile unsigned int*)GDMA_SUBT_INTST_reg)=data)
#define  get_GDMA_SUBT_INTST_reg                                                 (*((volatile unsigned int*)GDMA_SUBT_INTST_reg))
#define  GDMA_SUBT_INTST_sub1_acc_sync_shift                                     (20)
#define  GDMA_SUBT_INTST_sub1_udfl_shift                                         (14)
#define  GDMA_SUBT_INTST_sub1_shift                                              (13)
#define  GDMA_SUBT_INTST_sub1_fin_shift                                          (9)
#define  GDMA_SUBT_INTST_sub1_vact_end_shift                                     (5)
#define  GDMA_SUBT_INTST_sub1_vsync_shift                                        (1)
#define  GDMA_SUBT_INTST_write_data_shift                                        (0)
#define  GDMA_SUBT_INTST_sub1_acc_sync_mask                                      (0x00100000)
#define  GDMA_SUBT_INTST_sub1_udfl_mask                                          (0x00004000)
#define  GDMA_SUBT_INTST_sub1_mask                                               (0x00002000)
#define  GDMA_SUBT_INTST_sub1_fin_mask                                           (0x00000200)
#define  GDMA_SUBT_INTST_sub1_vact_end_mask                                      (0x00000020)
#define  GDMA_SUBT_INTST_sub1_vsync_mask                                         (0x00000002)
#define  GDMA_SUBT_INTST_write_data_mask                                         (0x00000001)
#define  GDMA_SUBT_INTST_sub1_acc_sync(data)                                     (0x00100000&((data)<<20))
#define  GDMA_SUBT_INTST_sub1_udfl(data)                                         (0x00004000&((data)<<14))
#define  GDMA_SUBT_INTST_sub1(data)                                              (0x00002000&((data)<<13))
#define  GDMA_SUBT_INTST_sub1_fin(data)                                          (0x00000200&((data)<<9))
#define  GDMA_SUBT_INTST_sub1_vact_end(data)                                     (0x00000020&((data)<<5))
#define  GDMA_SUBT_INTST_sub1_vsync(data)                                        (0x00000002&((data)<<1))
#define  GDMA_SUBT_INTST_write_data(data)                                        (0x00000001&(data))
#define  GDMA_SUBT_INTST_get_sub1_acc_sync(data)                                 ((0x00100000&(data))>>20)
#define  GDMA_SUBT_INTST_get_sub1_udfl(data)                                     ((0x00004000&(data))>>14)
#define  GDMA_SUBT_INTST_get_sub1(data)                                          ((0x00002000&(data))>>13)
#define  GDMA_SUBT_INTST_get_sub1_fin(data)                                      ((0x00000200&(data))>>9)
#define  GDMA_SUBT_INTST_get_sub1_vact_end(data)                                 ((0x00000020&(data))>>5)
#define  GDMA_SUBT_INTST_get_sub1_vsync(data)                                    ((0x00000002&(data))>>1)
#define  GDMA_SUBT_INTST_get_write_data(data)                                    (0x00000001&(data))

#define  GDMA_SUBT_INTEN_3D                                                      0x1802F0E0
#define  GDMA_SUBT_INTEN_3D_reg_addr                                             "0xB802F0E0"
#define  GDMA_SUBT_INTEN_3D_reg                                                  0xB802F0E0
#define  GDMA_SUBT_INTEN_3D_inst_addr                                            "0x0033"
#define  set_GDMA_SUBT_INTEN_3D_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_INTEN_3D_reg)=data)
#define  get_GDMA_SUBT_INTEN_3D_reg                                              (*((volatile unsigned int*)GDMA_SUBT_INTEN_3D_reg))
#define  GDMA_SUBT_INTEN_3D_sub1_acc_sync_shift                                  (20)
#define  GDMA_SUBT_INTEN_3D_sub1_udfl_shift                                      (14)
#define  GDMA_SUBT_INTEN_3D_sub1_shift                                           (13)
#define  GDMA_SUBT_INTEN_3D_sub1_fin_shift                                       (9)
#define  GDMA_SUBT_INTEN_3D_sub1_vact_end_shift                                  (5)
#define  GDMA_SUBT_INTEN_3D_sub1_vsync_shift                                     (1)
#define  GDMA_SUBT_INTEN_3D_write_data_shift                                     (0)
#define  GDMA_SUBT_INTEN_3D_sub1_acc_sync_mask                                   (0x00100000)
#define  GDMA_SUBT_INTEN_3D_sub1_udfl_mask                                       (0x00004000)
#define  GDMA_SUBT_INTEN_3D_sub1_mask                                            (0x00002000)
#define  GDMA_SUBT_INTEN_3D_sub1_fin_mask                                        (0x00000200)
#define  GDMA_SUBT_INTEN_3D_sub1_vact_end_mask                                   (0x00000020)
#define  GDMA_SUBT_INTEN_3D_sub1_vsync_mask                                      (0x00000002)
#define  GDMA_SUBT_INTEN_3D_write_data_mask                                      (0x00000001)
#define  GDMA_SUBT_INTEN_3D_sub1_acc_sync(data)                                  (0x00100000&((data)<<20))
#define  GDMA_SUBT_INTEN_3D_sub1_udfl(data)                                      (0x00004000&((data)<<14))
#define  GDMA_SUBT_INTEN_3D_sub1(data)                                           (0x00002000&((data)<<13))
#define  GDMA_SUBT_INTEN_3D_sub1_fin(data)                                       (0x00000200&((data)<<9))
#define  GDMA_SUBT_INTEN_3D_sub1_vact_end(data)                                  (0x00000020&((data)<<5))
#define  GDMA_SUBT_INTEN_3D_sub1_vsync(data)                                     (0x00000002&((data)<<1))
#define  GDMA_SUBT_INTEN_3D_write_data(data)                                     (0x00000001&(data))
#define  GDMA_SUBT_INTEN_3D_get_sub1_acc_sync(data)                              ((0x00100000&(data))>>20)
#define  GDMA_SUBT_INTEN_3D_get_sub1_udfl(data)                                  ((0x00004000&(data))>>14)
#define  GDMA_SUBT_INTEN_3D_get_sub1(data)                                       ((0x00002000&(data))>>13)
#define  GDMA_SUBT_INTEN_3D_get_sub1_fin(data)                                   ((0x00000200&(data))>>9)
#define  GDMA_SUBT_INTEN_3D_get_sub1_vact_end(data)                              ((0x00000020&(data))>>5)
#define  GDMA_SUBT_INTEN_3D_get_sub1_vsync(data)                                 ((0x00000002&(data))>>1)
#define  GDMA_SUBT_INTEN_3D_get_write_data(data)                                 (0x00000001&(data))

#define  GDMA_SUBT_INTST_3D                                                      0x1802F0E4
#define  GDMA_SUBT_INTST_3D_reg_addr                                             "0xB802F0E4"
#define  GDMA_SUBT_INTST_3D_reg                                                  0xB802F0E4
#define  GDMA_SUBT_INTST_3D_inst_addr                                            "0x0034"
#define  set_GDMA_SUBT_INTST_3D_reg(data)                                        (*((volatile unsigned int*)GDMA_SUBT_INTST_3D_reg)=data)
#define  get_GDMA_SUBT_INTST_3D_reg                                              (*((volatile unsigned int*)GDMA_SUBT_INTST_3D_reg))
#define  GDMA_SUBT_INTST_3D_sub1_acc_sync_shift                                  (20)
#define  GDMA_SUBT_INTST_3D_sub1_udfl_shift                                      (14)
#define  GDMA_SUBT_INTST_3D_sub1_shift                                           (13)
#define  GDMA_SUBT_INTST_3D_sub1_fin_shift                                       (9)
#define  GDMA_SUBT_INTST_3D_sub1_vact_end_shift                                  (5)
#define  GDMA_SUBT_INTST_3D_sub1_vsync_shift                                     (1)
#define  GDMA_SUBT_INTST_3D_write_data_shift                                     (0)
#define  GDMA_SUBT_INTST_3D_sub1_acc_sync_mask                                   (0x00100000)
#define  GDMA_SUBT_INTST_3D_sub1_udfl_mask                                       (0x00004000)
#define  GDMA_SUBT_INTST_3D_sub1_mask                                            (0x00002000)
#define  GDMA_SUBT_INTST_3D_sub1_fin_mask                                        (0x00000200)
#define  GDMA_SUBT_INTST_3D_sub1_vact_end_mask                                   (0x00000020)
#define  GDMA_SUBT_INTST_3D_sub1_vsync_mask                                      (0x00000002)
#define  GDMA_SUBT_INTST_3D_write_data_mask                                      (0x00000001)
#define  GDMA_SUBT_INTST_3D_sub1_acc_sync(data)                                  (0x00100000&((data)<<20))
#define  GDMA_SUBT_INTST_3D_sub1_udfl(data)                                      (0x00004000&((data)<<14))
#define  GDMA_SUBT_INTST_3D_sub1(data)                                           (0x00002000&((data)<<13))
#define  GDMA_SUBT_INTST_3D_sub1_fin(data)                                       (0x00000200&((data)<<9))
#define  GDMA_SUBT_INTST_3D_sub1_vact_end(data)                                  (0x00000020&((data)<<5))
#define  GDMA_SUBT_INTST_3D_sub1_vsync(data)                                     (0x00000002&((data)<<1))
#define  GDMA_SUBT_INTST_3D_write_data(data)                                     (0x00000001&(data))
#define  GDMA_SUBT_INTST_3D_get_sub1_acc_sync(data)                              ((0x00100000&(data))>>20)
#define  GDMA_SUBT_INTST_3D_get_sub1_udfl(data)                                  ((0x00004000&(data))>>14)
#define  GDMA_SUBT_INTST_3D_get_sub1(data)                                       ((0x00002000&(data))>>13)
#define  GDMA_SUBT_INTST_3D_get_sub1_fin(data)                                   ((0x00000200&(data))>>9)
#define  GDMA_SUBT_INTST_3D_get_sub1_vact_end(data)                              ((0x00000020&(data))>>5)
#define  GDMA_SUBT_INTST_3D_get_sub1_vsync(data)                                 ((0x00000002&(data))>>1)
#define  GDMA_SUBT_INTST_3D_get_write_data(data)                                 (0x00000001&(data))

#define  GDMA_SUBT_DBG                                                           0x1802F100
#define  GDMA_SUBT_DBG_reg_addr                                                  "0xB802F100"
#define  GDMA_SUBT_DBG_reg                                                       0xB802F100
#define  GDMA_SUBT_DBG_inst_addr                                                 "0x0035"
#define  set_GDMA_SUBT_DBG_reg(data)                                             (*((volatile unsigned int*)GDMA_SUBT_DBG_reg)=data)
#define  get_GDMA_SUBT_DBG_reg                                                   (*((volatile unsigned int*)GDMA_SUBT_DBG_reg))
#define  GDMA_SUBT_DBG_write_en3_shift                                           (24)
#define  GDMA_SUBT_DBG_sel1_shift                                                (16)
#define  GDMA_SUBT_DBG_write_en2_shift                                           (12)
#define  GDMA_SUBT_DBG_sel0_shift                                                (4)
#define  GDMA_SUBT_DBG_write_en1_shift                                           (1)
#define  GDMA_SUBT_DBG_en_shift                                                  (0)
#define  GDMA_SUBT_DBG_write_en3_mask                                            (0x01000000)
#define  GDMA_SUBT_DBG_sel1_mask                                                 (0x00FF0000)
#define  GDMA_SUBT_DBG_write_en2_mask                                            (0x00001000)
#define  GDMA_SUBT_DBG_sel0_mask                                                 (0x00000FF0)
#define  GDMA_SUBT_DBG_write_en1_mask                                            (0x00000002)
#define  GDMA_SUBT_DBG_en_mask                                                   (0x00000001)
#define  GDMA_SUBT_DBG_write_en3(data)                                           (0x01000000&((data)<<24))
#define  GDMA_SUBT_DBG_sel1(data)                                                (0x00FF0000&((data)<<16))
#define  GDMA_SUBT_DBG_write_en2(data)                                           (0x00001000&((data)<<12))
#define  GDMA_SUBT_DBG_sel0(data)                                                (0x00000FF0&((data)<<4))
#define  GDMA_SUBT_DBG_write_en1(data)                                           (0x00000002&((data)<<1))
#define  GDMA_SUBT_DBG_en(data)                                                  (0x00000001&(data))
#define  GDMA_SUBT_DBG_get_write_en3(data)                                       ((0x01000000&(data))>>24)
#define  GDMA_SUBT_DBG_get_sel1(data)                                            ((0x00FF0000&(data))>>16)
#define  GDMA_SUBT_DBG_get_write_en2(data)                                       ((0x00001000&(data))>>12)
#define  GDMA_SUBT_DBG_get_sel0(data)                                            ((0x00000FF0&(data))>>4)
#define  GDMA_SUBT_DBG_get_write_en1(data)                                       ((0x00000002&(data))>>1)
#define  GDMA_SUBT_DBG_get_en(data)                                              (0x00000001&(data))

#define  GDMA_SUBT_DBG_SUB1_WI_0                                                 0x1802F104
#define  GDMA_SUBT_DBG_SUB1_WI_0_reg_addr                                        "0xB802F104"
#define  GDMA_SUBT_DBG_SUB1_WI_0_reg                                             0xB802F104
#define  GDMA_SUBT_DBG_SUB1_WI_0_inst_addr                                       "0x0036"
#define  set_GDMA_SUBT_DBG_SUB1_WI_0_reg(data)                                   (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_0_reg)=data)
#define  get_GDMA_SUBT_DBG_SUB1_WI_0_reg                                         (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_0_reg))
#define  GDMA_SUBT_DBG_SUB1_WI_0_height_shift                                    (16)
#define  GDMA_SUBT_DBG_SUB1_WI_0_width_shift                                     (0)
#define  GDMA_SUBT_DBG_SUB1_WI_0_height_mask                                     (0xFFFF0000)
#define  GDMA_SUBT_DBG_SUB1_WI_0_width_mask                                      (0x0000FFFF)
#define  GDMA_SUBT_DBG_SUB1_WI_0_height(data)                                    (0xFFFF0000&((data)<<16))
#define  GDMA_SUBT_DBG_SUB1_WI_0_width(data)                                     (0x0000FFFF&(data))
#define  GDMA_SUBT_DBG_SUB1_WI_0_get_height(data)                                ((0xFFFF0000&(data))>>16)
#define  GDMA_SUBT_DBG_SUB1_WI_0_get_width(data)                                 (0x0000FFFF&(data))

#define  GDMA_SUBT_DBG_SUB1_WI_1                                                 0x1802F108
#define  GDMA_SUBT_DBG_SUB1_WI_1_reg_addr                                        "0xB802F108"
#define  GDMA_SUBT_DBG_SUB1_WI_1_reg                                             0xB802F108
#define  GDMA_SUBT_DBG_SUB1_WI_1_inst_addr                                       "0x0037"
#define  set_GDMA_SUBT_DBG_SUB1_WI_1_reg(data)                                   (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_1_reg)=data)
#define  get_GDMA_SUBT_DBG_SUB1_WI_1_reg                                         (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_1_reg))
#define  GDMA_SUBT_DBG_SUB1_WI_1_extension_mode_shift                            (31)
#define  GDMA_SUBT_DBG_SUB1_WI_1_rgb_order_shift                                 (28)
#define  GDMA_SUBT_DBG_SUB1_WI_1_alpha_replace_type_shift                        (27)
#define  GDMA_SUBT_DBG_SUB1_WI_1_const_alpha_enable_shift                        (26)
#define  GDMA_SUBT_DBG_SUB1_WI_1_object_type_shift                               (24)
#define  GDMA_SUBT_DBG_SUB1_WI_1_alpha_shift                                     (16)
#define  GDMA_SUBT_DBG_SUB1_WI_1_clut_format_shift                               (10)
#define  GDMA_SUBT_DBG_SUB1_WI_1_endian_shift                                    (9)
#define  GDMA_SUBT_DBG_SUB1_WI_1_keep_prev_clut_shift                            (8)
#define  GDMA_SUBT_DBG_SUB1_WI_1_compress_shift                                  (7)
#define  GDMA_SUBT_DBG_SUB1_WI_1_colortype_shift                                 (0)
#define  GDMA_SUBT_DBG_SUB1_WI_1_extension_mode_mask                             (0x80000000)
#define  GDMA_SUBT_DBG_SUB1_WI_1_rgb_order_mask                                  (0x70000000)
#define  GDMA_SUBT_DBG_SUB1_WI_1_alpha_replace_type_mask                         (0x08000000)
#define  GDMA_SUBT_DBG_SUB1_WI_1_const_alpha_enable_mask                         (0x04000000)
#define  GDMA_SUBT_DBG_SUB1_WI_1_object_type_mask                                (0x01000000)
#define  GDMA_SUBT_DBG_SUB1_WI_1_alpha_mask                                      (0x00FF0000)
#define  GDMA_SUBT_DBG_SUB1_WI_1_clut_format_mask                                (0x00000400)
#define  GDMA_SUBT_DBG_SUB1_WI_1_endian_mask                                     (0x00000200)
#define  GDMA_SUBT_DBG_SUB1_WI_1_keep_prev_clut_mask                             (0x00000100)
#define  GDMA_SUBT_DBG_SUB1_WI_1_compress_mask                                   (0x00000080)
#define  GDMA_SUBT_DBG_SUB1_WI_1_colortype_mask                                  (0x0000001F)
#define  GDMA_SUBT_DBG_SUB1_WI_1_extension_mode(data)                            (0x80000000&((data)<<31))
#define  GDMA_SUBT_DBG_SUB1_WI_1_rgb_order(data)                                 (0x70000000&((data)<<28))
#define  GDMA_SUBT_DBG_SUB1_WI_1_alpha_replace_type(data)                        (0x08000000&((data)<<27))
#define  GDMA_SUBT_DBG_SUB1_WI_1_const_alpha_enable(data)                        (0x04000000&((data)<<26))
#define  GDMA_SUBT_DBG_SUB1_WI_1_object_type(data)                               (0x01000000&((data)<<24))
#define  GDMA_SUBT_DBG_SUB1_WI_1_alpha(data)                                     (0x00FF0000&((data)<<16))
#define  GDMA_SUBT_DBG_SUB1_WI_1_clut_format(data)                               (0x00000400&((data)<<10))
#define  GDMA_SUBT_DBG_SUB1_WI_1_endian(data)                                    (0x00000200&((data)<<9))
#define  GDMA_SUBT_DBG_SUB1_WI_1_keep_prev_clut(data)                            (0x00000100&((data)<<8))
#define  GDMA_SUBT_DBG_SUB1_WI_1_compress(data)                                  (0x00000080&((data)<<7))
#define  GDMA_SUBT_DBG_SUB1_WI_1_colortype(data)                                 (0x0000001F&(data))
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_extension_mode(data)                        ((0x80000000&(data))>>31)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_rgb_order(data)                             ((0x70000000&(data))>>28)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_alpha_replace_type(data)                    ((0x08000000&(data))>>27)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_const_alpha_enable(data)                    ((0x04000000&(data))>>26)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_object_type(data)                           ((0x01000000&(data))>>24)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_alpha(data)                                 ((0x00FF0000&(data))>>16)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_clut_format(data)                           ((0x00000400&(data))>>10)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_endian(data)                                ((0x00000200&(data))>>9)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_keep_prev_clut(data)                        ((0x00000100&(data))>>8)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_compress(data)                              ((0x00000080&(data))>>7)
#define  GDMA_SUBT_DBG_SUB1_WI_1_get_colortype(data)                             (0x0000001F&(data))

#define  GDMA_SUBT_DBG_SUB1_WI_2                                                 0x1802F10C
#define  GDMA_SUBT_DBG_SUB1_WI_2_reg_addr                                        "0xB802F10C"
#define  GDMA_SUBT_DBG_SUB1_WI_2_reg                                             0xB802F10C
#define  GDMA_SUBT_DBG_SUB1_WI_2_inst_addr                                       "0x0038"
#define  set_GDMA_SUBT_DBG_SUB1_WI_2_reg(data)                                   (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_2_reg)=data)
#define  get_GDMA_SUBT_DBG_SUB1_WI_2_reg                                         (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_2_reg))
#define  GDMA_SUBT_DBG_SUB1_WI_2_top_addr_shift                                  (0)
#define  GDMA_SUBT_DBG_SUB1_WI_2_top_addr_mask                                   (0xFFFFFFFF)
#define  GDMA_SUBT_DBG_SUB1_WI_2_top_addr(data)                                  (0xFFFFFFFF&(data))
#define  GDMA_SUBT_DBG_SUB1_WI_2_get_top_addr(data)                              (0xFFFFFFFF&(data))

#define  GDMA_SUBT_DBG_SUB1_WI_3                                                 0x1802F110
#define  GDMA_SUBT_DBG_SUB1_WI_3_reg_addr                                        "0xB802F110"
#define  GDMA_SUBT_DBG_SUB1_WI_3_reg                                             0xB802F110
#define  GDMA_SUBT_DBG_SUB1_WI_3_inst_addr                                       "0x0039"
#define  set_GDMA_SUBT_DBG_SUB1_WI_3_reg(data)                                   (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_3_reg)=data)
#define  get_GDMA_SUBT_DBG_SUB1_WI_3_reg                                         (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_3_reg))
#define  GDMA_SUBT_DBG_SUB1_WI_3_bot_addr_shift                                  (0)
#define  GDMA_SUBT_DBG_SUB1_WI_3_bot_addr_mask                                   (0xFFFFFFFF)
#define  GDMA_SUBT_DBG_SUB1_WI_3_bot_addr(data)                                  (0xFFFFFFFF&(data))
#define  GDMA_SUBT_DBG_SUB1_WI_3_get_bot_addr(data)                              (0xFFFFFFFF&(data))

#define  GDMA_SUBT_DBG_SUB1_WI_4                                                 0x1802F114
#define  GDMA_SUBT_DBG_SUB1_WI_4_reg_addr                                        "0xB802F114"
#define  GDMA_SUBT_DBG_SUB1_WI_4_reg                                             0xB802F114
#define  GDMA_SUBT_DBG_SUB1_WI_4_inst_addr                                       "0x003A"
#define  set_GDMA_SUBT_DBG_SUB1_WI_4_reg(data)                                   (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_4_reg)=data)
#define  get_GDMA_SUBT_DBG_SUB1_WI_4_reg                                         (*((volatile unsigned int*)GDMA_SUBT_DBG_SUB1_WI_4_reg))
#define  GDMA_SUBT_DBG_SUB1_WI_4_pitch_shift                                     (0)
#define  GDMA_SUBT_DBG_SUB1_WI_4_pitch_mask                                      (0xFFFFFFFF)
#define  GDMA_SUBT_DBG_SUB1_WI_4_pitch(data)                                     (0xFFFFFFFF&(data))
#define  GDMA_SUBT_DBG_SUB1_WI_4_get_pitch(data)                                 (0xFFFFFFFF&(data))

#define  GDMA_SUBT_DMY_0                                                         0x1802F118
#define  GDMA_SUBT_DMY_0_reg_addr                                                "0xB802F118"
#define  GDMA_SUBT_DMY_0_reg                                                     0xB802F118
#define  GDMA_SUBT_DMY_0_inst_addr                                               "0x003B"
#define  set_GDMA_SUBT_DMY_0_reg(data)                                           (*((volatile unsigned int*)GDMA_SUBT_DMY_0_reg)=data)
#define  get_GDMA_SUBT_DMY_0_reg                                                 (*((volatile unsigned int*)GDMA_SUBT_DMY_0_reg))
#define  GDMA_SUBT_DMY_0_dummy_31_0_shift                                        (0)
#define  GDMA_SUBT_DMY_0_dummy_31_0_mask                                         (0xFFFFFFFF)
#define  GDMA_SUBT_DMY_0_dummy_31_0(data)                                        (0xFFFFFFFF&(data))
#define  GDMA_SUBT_DMY_0_get_dummy_31_0(data)                                    (0xFFFFFFFF&(data))

#define  GDMA_SUBT_DMY_1                                                         0x1802F11C
#define  GDMA_SUBT_DMY_1_reg_addr                                                "0xB802F11C"
#define  GDMA_SUBT_DMY_1_reg                                                     0xB802F11C
#define  GDMA_SUBT_DMY_1_inst_addr                                               "0x003C"
#define  set_GDMA_SUBT_DMY_1_reg(data)                                           (*((volatile unsigned int*)GDMA_SUBT_DMY_1_reg)=data)
#define  get_GDMA_SUBT_DMY_1_reg                                                 (*((volatile unsigned int*)GDMA_SUBT_DMY_1_reg))
#define  GDMA_SUBT_DMY_1_dummy_31_0_shift                                        (0)
#define  GDMA_SUBT_DMY_1_dummy_31_0_mask                                         (0xFFFFFFFF)
#define  GDMA_SUBT_DMY_1_dummy_31_0(data)                                        (0xFFFFFFFF&(data))
#define  GDMA_SUBT_DMY_1_get_dummy_31_0(data)                                    (0xFFFFFFFF&(data))

#define  GDMA_SUBT_MBIST                                                         0x1802F120
#define  GDMA_SUBT_MBIST_reg_addr                                                "0xB802F120"
#define  GDMA_SUBT_MBIST_reg                                                     0xB802F120
#define  GDMA_SUBT_MBIST_inst_addr                                               "0x003D"
#define  set_GDMA_SUBT_MBIST_reg(data)                                           (*((volatile unsigned int*)GDMA_SUBT_MBIST_reg)=data)
#define  get_GDMA_SUBT_MBIST_reg                                                 (*((volatile unsigned int*)GDMA_SUBT_MBIST_reg))
#define  GDMA_SUBT_MBIST_rme_shift                                               (4)
#define  GDMA_SUBT_MBIST_rm_shift                                                (0)
#define  GDMA_SUBT_MBIST_rme_mask                                                (0x00000010)
#define  GDMA_SUBT_MBIST_rm_mask                                                 (0x0000000F)
#define  GDMA_SUBT_MBIST_rme(data)                                               (0x00000010&((data)<<4))
#define  GDMA_SUBT_MBIST_rm(data)                                                (0x0000000F&(data))
#define  GDMA_SUBT_MBIST_get_rme(data)                                           ((0x00000010&(data))>>4)
#define  GDMA_SUBT_MBIST_get_rm(data)                                            (0x0000000F&(data))

#define  GDMA_SUBT_MBIST_FAIL                                                    0x1802F124
#define  GDMA_SUBT_MBIST_FAIL_reg_addr                                           "0xB802F124"
#define  GDMA_SUBT_MBIST_FAIL_reg                                                0xB802F124
#define  GDMA_SUBT_MBIST_FAIL_inst_addr                                          "0x003E"
#define  set_GDMA_SUBT_MBIST_FAIL_reg(data)                                      (*((volatile unsigned int*)GDMA_SUBT_MBIST_FAIL_reg)=data)
#define  get_GDMA_SUBT_MBIST_FAIL_reg                                            (*((volatile unsigned int*)GDMA_SUBT_MBIST_FAIL_reg))
#define  GDMA_SUBT_MBIST_FAIL_dispbuf_shift                                      (10)
#define  GDMA_SUBT_MBIST_FAIL_dma_buf_shift                                      (9)
#define  GDMA_SUBT_MBIST_FAIL_linebuffer_shift                                   (4)
#define  GDMA_SUBT_MBIST_FAIL_clut_shift                                         (2)
#define  GDMA_SUBT_MBIST_FAIL_rbuf_shift                                         (0)
#define  GDMA_SUBT_MBIST_FAIL_dispbuf_mask                                       (0x00000400)
#define  GDMA_SUBT_MBIST_FAIL_dma_buf_mask                                       (0x00000200)
#define  GDMA_SUBT_MBIST_FAIL_linebuffer_mask                                    (0x000001F0)
#define  GDMA_SUBT_MBIST_FAIL_clut_mask                                          (0x0000000C)
#define  GDMA_SUBT_MBIST_FAIL_rbuf_mask                                          (0x00000003)
#define  GDMA_SUBT_MBIST_FAIL_dispbuf(data)                                      (0x00000400&((data)<<10))
#define  GDMA_SUBT_MBIST_FAIL_dma_buf(data)                                      (0x00000200&((data)<<9))
#define  GDMA_SUBT_MBIST_FAIL_linebuffer(data)                                   (0x000001F0&((data)<<4))
#define  GDMA_SUBT_MBIST_FAIL_clut(data)                                         (0x0000000C&((data)<<2))
#define  GDMA_SUBT_MBIST_FAIL_rbuf(data)                                         (0x00000003&(data))
#define  GDMA_SUBT_MBIST_FAIL_get_dispbuf(data)                                  ((0x00000400&(data))>>10)
#define  GDMA_SUBT_MBIST_FAIL_get_dma_buf(data)                                  ((0x00000200&(data))>>9)
#define  GDMA_SUBT_MBIST_FAIL_get_linebuffer(data)                               ((0x000001F0&(data))>>4)
#define  GDMA_SUBT_MBIST_FAIL_get_clut(data)                                     ((0x0000000C&(data))>>2)
#define  GDMA_SUBT_MBIST_FAIL_get_rbuf(data)                                     (0x00000003&(data))

#define  GDMA_SUBT_MBIST_DRF_FAIL                                                0x1802F128
#define  GDMA_SUBT_MBIST_DRF_FAIL_reg_addr                                       "0xB802F128"
#define  GDMA_SUBT_MBIST_DRF_FAIL_reg                                            0xB802F128
#define  GDMA_SUBT_MBIST_DRF_FAIL_inst_addr                                      "0x003F"
#define  set_GDMA_SUBT_MBIST_DRF_FAIL_reg(data)                                  (*((volatile unsigned int*)GDMA_SUBT_MBIST_DRF_FAIL_reg)=data)
#define  get_GDMA_SUBT_MBIST_DRF_FAIL_reg                                        (*((volatile unsigned int*)GDMA_SUBT_MBIST_DRF_FAIL_reg))
#define  GDMA_SUBT_MBIST_DRF_FAIL_dispbuf_shift                                  (10)
#define  GDMA_SUBT_MBIST_DRF_FAIL_dma_buf_shift                                  (9)
#define  GDMA_SUBT_MBIST_DRF_FAIL_linebuffer_shift                               (4)
#define  GDMA_SUBT_MBIST_DRF_FAIL_clut_shift                                     (2)
#define  GDMA_SUBT_MBIST_DRF_FAIL_rbuf_shift                                     (0)
#define  GDMA_SUBT_MBIST_DRF_FAIL_dispbuf_mask                                   (0x00000400)
#define  GDMA_SUBT_MBIST_DRF_FAIL_dma_buf_mask                                   (0x00000200)
#define  GDMA_SUBT_MBIST_DRF_FAIL_linebuffer_mask                                (0x000001F0)
#define  GDMA_SUBT_MBIST_DRF_FAIL_clut_mask                                      (0x0000000C)
#define  GDMA_SUBT_MBIST_DRF_FAIL_rbuf_mask                                      (0x00000003)
#define  GDMA_SUBT_MBIST_DRF_FAIL_dispbuf(data)                                  (0x00000400&((data)<<10))
#define  GDMA_SUBT_MBIST_DRF_FAIL_dma_buf(data)                                  (0x00000200&((data)<<9))
#define  GDMA_SUBT_MBIST_DRF_FAIL_linebuffer(data)                               (0x000001F0&((data)<<4))
#define  GDMA_SUBT_MBIST_DRF_FAIL_clut(data)                                     (0x0000000C&((data)<<2))
#define  GDMA_SUBT_MBIST_DRF_FAIL_rbuf(data)                                     (0x00000003&(data))
#define  GDMA_SUBT_MBIST_DRF_FAIL_get_dispbuf(data)                              ((0x00000400&(data))>>10)
#define  GDMA_SUBT_MBIST_DRF_FAIL_get_dma_buf(data)                              ((0x00000200&(data))>>9)
#define  GDMA_SUBT_MBIST_DRF_FAIL_get_linebuffer(data)                           ((0x000001F0&(data))>>4)
#define  GDMA_SUBT_MBIST_DRF_FAIL_get_clut(data)                                 ((0x0000000C&(data))>>2)
#define  GDMA_SUBT_MBIST_DRF_FAIL_get_rbuf(data)                                 (0x00000003&(data))

#define  GDMA_SUBT_RTL_IMPROVE                                                   0x1802F140
#define  GDMA_SUBT_RTL_IMPROVE_reg_addr                                          "0xB802F140"
#define  GDMA_SUBT_RTL_IMPROVE_reg                                               0xB802F140
#define  GDMA_SUBT_RTL_IMPROVE_inst_addr                                         "0x0040"
#define  set_GDMA_SUBT_RTL_IMPROVE_reg(data)                                     (*((volatile unsigned int*)GDMA_SUBT_RTL_IMPROVE_reg)=data)
#define  get_GDMA_SUBT_RTL_IMPROVE_reg                                           (*((volatile unsigned int*)GDMA_SUBT_RTL_IMPROVE_reg))
#define  GDMA_SUBT_RTL_IMPROVE_gating_off_shift                                  (0)
#define  GDMA_SUBT_RTL_IMPROVE_gating_off_mask                                   (0x00000001)
#define  GDMA_SUBT_RTL_IMPROVE_gating_off(data)                                  (0x00000001&(data))
#define  GDMA_SUBT_RTL_IMPROVE_get_gating_off(data)                              (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======GDMA_SUBT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:17;
        RBus_UInt32  gating_enable:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  sub1_bypass_acc_sync_fix:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  sub1_sel:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_update_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sub1_prog_done:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  d3_mode:1;
        RBus_UInt32  rotate:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  vs:1;
        RBus_UInt32  hs:1;
        RBus_UInt32  sub1_en:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_sub1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  clut_keep:1;
        RBus_UInt32  wi_endian:1;
        RBus_UInt32  rgb_out:1;
        RBus_UInt32  dvd:1;
        RBus_UInt32  hddvd:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  hl:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  osd:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  vs_near:1;
        RBus_UInt32  vs_yodd:1;
        RBus_UInt32  vs_codd:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  hs_yodd:1;
        RBus_UInt32  hs_codd:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  res15:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_sub1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  th:13;
    };
}gdma_subt_sub1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  th:13;
    };
}gdma_subt_sub1_vbi_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  w:13;
    };
}gdma_subt_sub1_subp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  w:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  h:13;
    };
}gdma_subt_sub1_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_wi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_wi_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_clut_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_pxdt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_pxdb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  num:12;
    };
}gdma_subt_sub1_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a3:4;
        RBus_UInt32  a2:4;
        RBus_UInt32  a1:4;
        RBus_UInt32  a0:4;
        RBus_UInt32  i3:4;
        RBus_UInt32  i2:4;
        RBus_UInt32  i1:4;
        RBus_UInt32  i0:4;
    };
}gdma_subt_sub1_dft_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  e:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s:13;
    };
}gdma_subt_sub1_hlx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  e:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  s:13;
    };
}gdma_subt_sub1_hly_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a3:4;
        RBus_UInt32  a2:4;
        RBus_UInt32  a1:4;
        RBus_UInt32  a0:4;
        RBus_UInt32  i3:4;
        RBus_UInt32  i2:4;
        RBus_UInt32  i1:4;
        RBus_UInt32  i0:4;
    };
}gdma_subt_sub1_hl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m01:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  m00:14;
    };
}gdma_subt_sub1_cc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m10:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  m02:14;
    };
}gdma_subt_sub1_cc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m12:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  m11:14;
    };
}gdma_subt_sub1_cc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  m21:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  m20:14;
    };
}gdma_subt_sub1_cc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  m22:14;
    };
}gdma_subt_sub1_cc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  a2:9;
        RBus_UInt32  a1:9;
        RBus_UInt32  a0:9;
    };
}gdma_subt_sub1_cc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  b2:9;
        RBus_UInt32  b1:9;
        RBus_UInt32  b0:9;
    };
}gdma_subt_sub1_cc7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  offset:13;
        RBus_UInt32  phase:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_vsi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  out:13;
    };
}gdma_subt_sub1_vsd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  delta:19;
    };
}gdma_subt_sub1_vsd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c1:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  c0:14;
    };
}gdma_subt_sub1_vsyc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  offset:13;
        RBus_UInt32  phase:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_hsi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  out:13;
    };
}gdma_subt_sub1_hsd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  delta:19;
    };
}gdma_subt_sub1_hsd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  c1:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  c0:14;
    };
}gdma_subt_sub1_hsyc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_mask:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  sub1_req_num:2;
        RBus_UInt32  res3:15;
        RBus_UInt32  sub1_bl:7;
    };
}gdma_subt_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  m422_cb_cr_swap:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  sub1_1b:1;
        RBus_UInt32  sub1_2b:1;
        RBus_UInt32  sub1_4b:1;
        RBus_UInt32  sub1_8b:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_dma_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  depth:12;
        RBus_UInt32  sa:12;
    };
}gdma_subt_dma_sub1_wi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  depth:12;
        RBus_UInt32  sa:12;
    };
}gdma_subt_dma_sub1_d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  depth:12;
        RBus_UInt32  sa:12;
    };
}gdma_subt_dma_sub1_d1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  y:13;
    };
}gdma_subt_sub1_xy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  sub1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  sub1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  sub1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_inten_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  sub1:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res5:3;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  write_data:1;
    };
}gdma_subt_intst_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  sel1:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  sel0:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  en:1;
    };
}gdma_subt_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  height:16;
        RBus_UInt32  width:16;
    };
}gdma_subt_dbg_sub1_wi_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  extension_mode:1;
        RBus_UInt32  rgb_order:3;
        RBus_UInt32  alpha_replace_type:1;
        RBus_UInt32  const_alpha_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  object_type:1;
        RBus_UInt32  alpha:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  clut_format:1;
        RBus_UInt32  endian:1;
        RBus_UInt32  keep_prev_clut:1;
        RBus_UInt32  compress:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  colortype:5;
    };
}gdma_subt_dbg_sub1_wi_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  top_addr:32;
    };
}gdma_subt_dbg_sub1_wi_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bot_addr:32;
    };
}gdma_subt_dbg_sub1_wi_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pitch:32;
    };
}gdma_subt_dbg_sub1_wi_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802f118_31_0:32;
    };
}gdma_subt_dmy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm:4;
    };
}gdma_subt_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dispbuf:1;
        RBus_UInt32  dma_buf:1;
        RBus_UInt32  linebuffer:5;
        RBus_UInt32  clut:2;
        RBus_UInt32  rbuf:2;
    };
}gdma_subt_mbist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dispbuf:1;
        RBus_UInt32  dma_buf:1;
        RBus_UInt32  linebuffer:5;
        RBus_UInt32  clut:2;
        RBus_UInt32  rbuf:2;
    };
}gdma_subt_mbist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  gating_off:1;
    };
}gdma_subt_rtl_improve_RBUS;

#else //apply LITTLE_ENDIAN

//======GDMA_SUBT register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sub1_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  sub1_bypass_acc_sync_fix:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  gating_enable:1;
        RBus_UInt32  res3:17;
        RBus_UInt32  res4:7;
    };
}gdma_subt_update_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_prog_done:1;
        RBus_UInt32  res2:27;
    };
}gdma_subt_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sub1_en:1;
        RBus_UInt32  hs:1;
        RBus_UInt32  vs:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  rotate:1;
        RBus_UInt32  d3_mode:1;
        RBus_UInt32  res2:22;
    };
}gdma_subt_sub1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  hs_codd:1;
        RBus_UInt32  hs_yodd:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  vs_codd:1;
        RBus_UInt32  vs_yodd:1;
        RBus_UInt32  vs_near:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
        RBus_UInt32  osd:1;
        RBus_UInt32  res11:1;
        RBus_UInt32  res12:1;
        RBus_UInt32  hl:1;
        RBus_UInt32  res13:1;
        RBus_UInt32  res14:1;
        RBus_UInt32  hddvd:1;
        RBus_UInt32  dvd:1;
        RBus_UInt32  rgb_out:1;
        RBus_UInt32  wi_endian:1;
        RBus_UInt32  clut_keep:1;
        RBus_UInt32  res15:5;
    };
}gdma_subt_sub1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th:13;
        RBus_UInt32  res1:19;
    };
}gdma_subt_sub1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th:13;
        RBus_UInt32  res1:19;
    };
}gdma_subt_sub1_vbi_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w:13;
        RBus_UInt32  res1:19;
    };
}gdma_subt_sub1_subp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  w:13;
        RBus_UInt32  res2:3;
    };
}gdma_subt_sub1_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_wi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_wi_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_clut_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_pxdt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a:32;
    };
}gdma_subt_sub1_pxdb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  num:12;
        RBus_UInt32  res1:20;
    };
}gdma_subt_sub1_lc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i0:4;
        RBus_UInt32  i1:4;
        RBus_UInt32  i2:4;
        RBus_UInt32  i3:4;
        RBus_UInt32  a0:4;
        RBus_UInt32  a1:4;
        RBus_UInt32  a2:4;
        RBus_UInt32  a3:4;
    };
}gdma_subt_sub1_dft_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  e:13;
        RBus_UInt32  res2:3;
    };
}gdma_subt_sub1_hlx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  e:13;
        RBus_UInt32  res2:3;
    };
}gdma_subt_sub1_hly_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i0:4;
        RBus_UInt32  i1:4;
        RBus_UInt32  i2:4;
        RBus_UInt32  i3:4;
        RBus_UInt32  a0:4;
        RBus_UInt32  a1:4;
        RBus_UInt32  a2:4;
        RBus_UInt32  a3:4;
    };
}gdma_subt_sub1_hl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m00:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  m01:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_cc1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m02:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  m10:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_cc2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m11:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  m12:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_cc3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m20:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  m21:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_cc4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  m22:14;
        RBus_UInt32  res1:18;
    };
}gdma_subt_sub1_cc5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a0:9;
        RBus_UInt32  a1:9;
        RBus_UInt32  a2:9;
        RBus_UInt32  res1:5;
    };
}gdma_subt_sub1_cc6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b0:9;
        RBus_UInt32  b1:9;
        RBus_UInt32  b2:9;
        RBus_UInt32  res1:5;
    };
}gdma_subt_sub1_cc7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  phase:14;
        RBus_UInt32  offset:13;
        RBus_UInt32  res2:3;
    };
}gdma_subt_sub1_vsi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out:13;
        RBus_UInt32  res1:19;
    };
}gdma_subt_sub1_vsd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta:19;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  res3:1;
    };
}gdma_subt_sub1_vsd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  c1:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_vsyc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  phase:14;
        RBus_UInt32  offset:13;
        RBus_UInt32  res2:3;
    };
}gdma_subt_sub1_hsi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  out:13;
        RBus_UInt32  res1:19;
    };
}gdma_subt_sub1_hsd_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta:19;
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  res3:1;
    };
}gdma_subt_sub1_hsd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  c1:14;
        RBus_UInt32  res2:2;
    };
}gdma_subt_sub1_hsyc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub1_bl:7;
        RBus_UInt32  res1:15;
        RBus_UInt32  sub1_req_num:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  sub1_mask:1;
        RBus_UInt32  res3:3;
    };
}gdma_subt_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_8b:1;
        RBus_UInt32  sub1_4b:1;
        RBus_UInt32  sub1_2b:1;
        RBus_UInt32  sub1_1b:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  m422_cb_cr_swap:1;
        RBus_UInt32  res3:15;
    };
}gdma_subt_dma_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sa:12;
        RBus_UInt32  depth:12;
        RBus_UInt32  res1:8;
    };
}gdma_subt_dma_sub1_wi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sa:12;
        RBus_UInt32  depth:12;
        RBus_UInt32  res1:8;
    };
}gdma_subt_dma_sub1_d0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sa:12;
        RBus_UInt32  depth:12;
        RBus_UInt32  res1:8;
    };
}gdma_subt_dma_sub1_d1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  x:13;
        RBus_UInt32  res2:3;
    };
}gdma_subt_sub1_xy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1:1;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res5:11;
    };
}gdma_subt_inten_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1:1;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res5:11;
    };
}gdma_subt_intst_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1:1;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res5:11;
    };
}gdma_subt_inten_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  sub1_vsync:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sub1_vact_end:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sub1_fin:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  sub1:1;
        RBus_UInt32  sub1_udfl:1;
        RBus_UInt32  res4:5;
        RBus_UInt32  sub1_acc_sync:1;
        RBus_UInt32  res5:11;
    };
}gdma_subt_intst_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  write_en1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  sel0:8;
        RBus_UInt32  write_en2:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sel1:8;
        RBus_UInt32  write_en3:1;
        RBus_UInt32  res3:7;
    };
}gdma_subt_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  width:16;
        RBus_UInt32  height:16;
    };
}gdma_subt_dbg_sub1_wi_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  colortype:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  compress:1;
        RBus_UInt32  keep_prev_clut:1;
        RBus_UInt32  endian:1;
        RBus_UInt32  clut_format:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  alpha:8;
        RBus_UInt32  object_type:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  const_alpha_enable:1;
        RBus_UInt32  alpha_replace_type:1;
        RBus_UInt32  rgb_order:3;
        RBus_UInt32  extension_mode:1;
    };
}gdma_subt_dbg_sub1_wi_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  top_addr:32;
    };
}gdma_subt_dbg_sub1_wi_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bot_addr:32;
    };
}gdma_subt_dbg_sub1_wi_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pitch:32;
    };
}gdma_subt_dbg_sub1_wi_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802f118_31_0:32;
    };
}gdma_subt_dmy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm:4;
        RBus_UInt32  rme:1;
        RBus_UInt32  res1:27;
    };
}gdma_subt_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rbuf:2;
        RBus_UInt32  clut:2;
        RBus_UInt32  linebuffer:5;
        RBus_UInt32  dma_buf:1;
        RBus_UInt32  dispbuf:1;
        RBus_UInt32  res1:21;
    };
}gdma_subt_mbist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rbuf:2;
        RBus_UInt32  clut:2;
        RBus_UInt32  linebuffer:5;
        RBus_UInt32  dma_buf:1;
        RBus_UInt32  dispbuf:1;
        RBus_UInt32  res1:21;
    };
}gdma_subt_mbist_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gating_off:1;
        RBus_UInt32  res1:31;
    };
}gdma_subt_rtl_improve_RBUS;




#endif 


#endif 
