/**
* @file Mac5-DesignSpec-D-Domain_OSD_security
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_OSD_SECURITY_REG_H_
#define _RBUS_OSD_SECURITY_REG_H_

#include "rbus_types.h"



//  OSD_SECURITY Register Address
#define  OSD_SECURITY_OSD_SECURITY                                               0x1802E600
#define  OSD_SECURITY_OSD_SECURITY_reg_addr                                      "0xB802E600"
#define  OSD_SECURITY_OSD_SECURITY_reg                                           0xB802E600
#define  OSD_SECURITY_OSD_SECURITY_inst_addr                                     "0x0000"
#define  set_OSD_SECURITY_OSD_SECURITY_reg(data)                                 (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_reg                                       (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_reg))
#define  OSD_SECURITY_OSD_SECURITY_c3_security_en_shift                          (27)
#define  OSD_SECURITY_OSD_SECURITY_c2_security_en_shift                          (26)
#define  OSD_SECURITY_OSD_SECURITY_c1_security_en_shift                          (25)
#define  OSD_SECURITY_OSD_SECURITY_c0_security_en_shift                          (24)
#define  OSD_SECURITY_OSD_SECURITY_osd_security_en_shift                         (0)
#define  OSD_SECURITY_OSD_SECURITY_c3_security_en_mask                           (0x08000000)
#define  OSD_SECURITY_OSD_SECURITY_c2_security_en_mask                           (0x04000000)
#define  OSD_SECURITY_OSD_SECURITY_c1_security_en_mask                           (0x02000000)
#define  OSD_SECURITY_OSD_SECURITY_c0_security_en_mask                           (0x01000000)
#define  OSD_SECURITY_OSD_SECURITY_osd_security_en_mask                          (0x00000001)
#define  OSD_SECURITY_OSD_SECURITY_c3_security_en(data)                          (0x08000000&((data)<<27))
#define  OSD_SECURITY_OSD_SECURITY_c2_security_en(data)                          (0x04000000&((data)<<26))
#define  OSD_SECURITY_OSD_SECURITY_c1_security_en(data)                          (0x02000000&((data)<<25))
#define  OSD_SECURITY_OSD_SECURITY_c0_security_en(data)                          (0x01000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_osd_security_en(data)                         (0x00000001&(data))
#define  OSD_SECURITY_OSD_SECURITY_get_c3_security_en(data)                      ((0x08000000&(data))>>27)
#define  OSD_SECURITY_OSD_SECURITY_get_c2_security_en(data)                      ((0x04000000&(data))>>26)
#define  OSD_SECURITY_OSD_SECURITY_get_c1_security_en(data)                      ((0x02000000&(data))>>25)
#define  OSD_SECURITY_OSD_SECURITY_get_c0_security_en(data)                      ((0x01000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_get_osd_security_en(data)                     (0x00000001&(data))

#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2                                   0x1802E604
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_reg_addr                          "0xB802E604"
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_reg                               0xB802E604
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_inst_addr                         "0x0001"
#define  set_OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_reg(data)                     (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_reg                           (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_reg))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_dummy_31_2_shift                  (2)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_mixero1_en_shift                  (1)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_mixer_en_shift                    (0)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_dummy_31_2_mask                   (0xFFFFFFFC)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_mixero1_en_mask                   (0x00000002)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_mixer_en_mask                     (0x00000001)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_dummy_31_2(data)                  (0xFFFFFFFC&((data)<<2))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_mixero1_en(data)                  (0x00000002&((data)<<1))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_mixer_en(data)                    (0x00000001&(data))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_get_dummy_31_2(data)              ((0xFFFFFFFC&(data))>>2)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_get_mixero1_en(data)              ((0x00000002&(data))>>1)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_CTRL2_get_mixer_en(data)                (0x00000001&(data))

#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL                                     0x1802E608
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_reg_addr                            "0xB802E608"
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_reg                                 0xB802E608
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_inst_addr                           "0x0002"
#define  set_OSD_SECURITY_OSD_SECURITY_MIXER_SEL_reg(data)                       (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_SEL_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_MIXER_SEL_reg                             (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_SEL_reg))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c3_plane_alpha_en_shift             (27)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c2_plane_alpha_en_shift             (26)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c1_plane_alpha_en_shift             (25)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c0_plane_alpha_en_shift             (24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c3_sel_shift                        (12)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c2_sel_shift                        (8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c1_sel_shift                        (4)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c0_sel_shift                        (0)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c3_plane_alpha_en_mask              (0x08000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c2_plane_alpha_en_mask              (0x04000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c1_plane_alpha_en_mask              (0x02000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c0_plane_alpha_en_mask              (0x01000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c3_sel_mask                         (0x00007000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c2_sel_mask                         (0x00000700)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c1_sel_mask                         (0x00000070)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c0_sel_mask                         (0x00000007)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c3_plane_alpha_en(data)             (0x08000000&((data)<<27))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c2_plane_alpha_en(data)             (0x04000000&((data)<<26))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c1_plane_alpha_en(data)             (0x02000000&((data)<<25))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c0_plane_alpha_en(data)             (0x01000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c3_sel(data)                        (0x00007000&((data)<<12))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c2_sel(data)                        (0x00000700&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c1_sel(data)                        (0x00000070&((data)<<4))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_c0_sel(data)                        (0x00000007&(data))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c3_plane_alpha_en(data)         ((0x08000000&(data))>>27)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c2_plane_alpha_en(data)         ((0x04000000&(data))>>26)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c1_plane_alpha_en(data)         ((0x02000000&(data))>>25)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c0_plane_alpha_en(data)         ((0x01000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c3_sel(data)                    ((0x00007000&(data))>>12)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c2_sel(data)                    ((0x00000700&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c1_sel(data)                    ((0x00000070&(data))>>4)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_SEL_get_c0_sel(data)                    (0x00000007&(data))

#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA                               0x1802E618
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_reg_addr                      "0xB802E618"
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_reg                           0xB802E618
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_inst_addr                     "0x0003"
#define  set_OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_reg(data)                 (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_reg                       (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_reg))
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_sta_l4_shift                  (12)
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_sta_l4_mask                   (0x0000F000)
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_sta_l4(data)                  (0x0000F000&((data)<<12))
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_STA_get_sta_l4(data)              ((0x0000F000&(data))>>12)

#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE                              0x1802E61C
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_reg_addr                     "0xB802E61C"
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_reg                          0xB802E61C
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_inst_addr                    "0x0004"
#define  set_OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_reg(data)                (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_reg                      (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_reg))
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_size_l4_shift                (12)
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_size_l4_mask                 (0x0000F000)
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_size_l4(data)                (0x0000F000&((data)<<12))
#define  OSD_SECURITY_OSD_SECURITY_LINE_BUFFER_SIZE_get_size_l4(data)            ((0x0000F000&(data))>>12)

#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH                                   0x1802E620
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_reg_addr                          "0xB802E620"
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_reg                               0xB802E620
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_inst_addr                         "0x0005"
#define  set_OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_reg(data)                     (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_reg                           (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_reg))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_osdsr3_switch_to_shift            (8)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_osdsr2_switch_to_shift            (4)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_osdsr3_switch_to_mask             (0x00000700)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_osdsr2_switch_to_mask             (0x00000070)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_osdsr3_switch_to(data)            (0x00000700&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_osdsr2_switch_to(data)            (0x00000070&((data)<<4))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_get_osdsr3_switch_to(data)        ((0x00000700&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SWITCH_get_osdsr2_switch_to(data)        ((0x00000070&(data))>>4)

#define  OSD_SECURITY_OSD_SECURITY_GDMA                                          0x1802E624
#define  OSD_SECURITY_OSD_SECURITY_GDMA_reg_addr                                 "0xB802E624"
#define  OSD_SECURITY_OSD_SECURITY_GDMA_reg                                      0xB802E624
#define  OSD_SECURITY_OSD_SECURITY_GDMA_inst_addr                                "0x0006"
#define  set_OSD_SECURITY_OSD_SECURITY_GDMA_reg(data)                            (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_GDMA_reg                                  (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_reg))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_1b_shift                            (7)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_2b_shift                            (6)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_4b_shift                            (5)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_8b_shift                            (4)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_wi_endian_shift                     (3)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_rgb_out_shift                       (2)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_rotate_shift                        (1)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_en_shift                            (0)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_1b_mask                             (0x00000080)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_2b_mask                             (0x00000040)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_4b_mask                             (0x00000020)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_8b_mask                             (0x00000010)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_wi_endian_mask                      (0x00000008)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_rgb_out_mask                        (0x00000004)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_rotate_mask                         (0x00000002)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_en_mask                             (0x00000001)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_1b(data)                            (0x00000080&((data)<<7))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_2b(data)                            (0x00000040&((data)<<6))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_4b(data)                            (0x00000020&((data)<<5))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_8b(data)                            (0x00000010&((data)<<4))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_wi_endian(data)                     (0x00000008&((data)<<3))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_rgb_out(data)                       (0x00000004&((data)<<2))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_rotate(data)                        (0x00000002&((data)<<1))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_osd1_en(data)                            (0x00000001&(data))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_1b(data)                        ((0x00000080&(data))>>7)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_2b(data)                        ((0x00000040&(data))>>6)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_4b(data)                        ((0x00000020&(data))>>5)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_8b(data)                        ((0x00000010&(data))>>4)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_wi_endian(data)                 ((0x00000008&(data))>>3)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_rgb_out(data)                   ((0x00000004&(data))>>2)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_rotate(data)                    ((0x00000002&(data))>>1)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_get_osd1_en(data)                        (0x00000001&(data))

#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR                                     0x1802E628
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_reg_addr                            "0xB802E628"
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_reg                                 0xB802E628
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_inst_addr                           "0x0007"
#define  set_OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_reg(data)                       (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_reg                             (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_reg))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_osd1_wi_addr_shift                  (0)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_osd1_wi_addr_mask                   (0xFFFFFFFF)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_osd1_wi_addr(data)                  (0xFFFFFFFF&(data))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_ADDR_get_osd1_wi_addr(data)              (0xFFFFFFFF&(data))

#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE                                     0x1802E62C
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_reg_addr                            "0xB802E62C"
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_reg                                 0xB802E62C
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_inst_addr                           "0x0008"
#define  set_OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_reg(data)                       (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_reg                             (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_reg))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_osd1_w_shift                        (16)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_osd1_h_shift                        (0)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_osd1_w_mask                         (0x1FFF0000)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_osd1_h_mask                         (0x00001FFF)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_osd1_w(data)                        (0x1FFF0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_osd1_h(data)                        (0x00001FFF&(data))
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_get_osd1_w(data)                    ((0x1FFF0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_GDMA_SIZE_get_osd1_h(data)                    (0x00001FFF&(data))

#define  OSD_SECURITY_OSD_SECURITY_db_ctrl                                       0x1802E630
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_reg_addr                              "0xB802E630"
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_reg                                   0xB802E630
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_inst_addr                             "0x0009"
#define  set_OSD_SECURITY_OSD_SECURITY_db_ctrl_reg(data)                         (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_db_ctrl_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_db_ctrl_reg                               (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_db_ctrl_reg))
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_link_with_smooth_toggle_shift         (31)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_read_shift                         (2)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_en_shift                           (1)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_load_shift                         (0)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_link_with_smooth_toggle_mask          (0x80000000)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_read_mask                          (0x00000004)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_en_mask                            (0x00000002)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_load_mask                          (0x00000001)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_link_with_smooth_toggle(data)         (0x80000000&((data)<<31))
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_read(data)                         (0x00000004&((data)<<2))
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_en(data)                           (0x00000002&((data)<<1))
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_db_load(data)                         (0x00000001&(data))
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_get_link_with_smooth_toggle(data)     ((0x80000000&(data))>>31)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_get_db_read(data)                     ((0x00000004&(data))>>2)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_get_db_en(data)                       ((0x00000002&(data))>>1)
#define  OSD_SECURITY_OSD_SECURITY_db_ctrl_get_db_load(data)                     (0x00000001&(data))

#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0                            0x1802E640
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_reg_addr                   "0xB802E640"
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_reg                        0xB802E640
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_inst_addr                  "0x000A"
#define  set_OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_reg(data)              (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_reg                    (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_reg))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_v_zoom_en_shift            (31)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_ini_shift              (22)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_tap_num_shift          (20)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_factor_shift           (0)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_v_zoom_en_mask             (0x80000000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_ini_mask               (0x3FC00000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_tap_num_mask           (0x00300000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_factor_mask            (0x000FFFFF)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_v_zoom_en(data)            (0x80000000&((data)<<31))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_ini(data)              (0x3FC00000&((data)<<22))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_tap_num(data)          (0x00300000&((data)<<20))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_ver_factor(data)           (0x000FFFFF&(data))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_get_v_zoom_en(data)        ((0x80000000&(data))>>31)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_get_ver_ini(data)          ((0x3FC00000&(data))>>22)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_get_ver_tap_num(data)      ((0x00300000&(data))>>20)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl0_get_ver_factor(data)       (0x000FFFFF&(data))

#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1                            0x1802E644
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_reg_addr                   "0xB802E644"
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_reg                        0xB802E644
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_inst_addr                  "0x000B"
#define  set_OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_reg(data)              (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_reg                    (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_reg))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_h_zoom_en_shift            (31)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_hor_ini_shift              (22)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_hor_factor_shift           (0)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_h_zoom_en_mask             (0x80000000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_hor_ini_mask               (0x3FC00000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_hor_factor_mask            (0x000FFFFF)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_h_zoom_en(data)            (0x80000000&((data)<<31))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_hor_ini(data)              (0x3FC00000&((data)<<22))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_hor_factor(data)           (0x000FFFFF&(data))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_get_h_zoom_en(data)        ((0x80000000&(data))>>31)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_get_hor_ini(data)          ((0x3FC00000&(data))>>22)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Scaleup_Ctrl1_get_hor_factor(data)       (0x000FFFFF&(data))

#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl                          0x1802E648
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_reg_addr                 "0xB802E648"
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_reg                      0xB802E648
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_inst_addr                "0x000C"
#define  set_OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_reg(data)            (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_reg                  (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_reg))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_osd_h_sta_shift          (16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_osd_width_shift          (0)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_osd_h_sta_mask           (0x1FFF0000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_osd_width_mask           (0x00001FFF)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_osd_h_sta(data)          (0x1FFF0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_osd_width(data)          (0x00001FFF&(data))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_get_osd_h_sta(data)      ((0x1FFF0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_H_Location_Ctrl_get_osd_width(data)      (0x00001FFF&(data))

#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl                          0x1802E64C
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_reg_addr                 "0xB802E64C"
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_reg                      0xB802E64C
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_inst_addr                "0x000D"
#define  set_OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_reg(data)            (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_reg                  (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_reg))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_osd_v_sta_shift          (16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_osd_height_shift         (0)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_osd_v_sta_mask           (0x0FFF0000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_osd_height_mask          (0x00000FFF)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_osd_v_sta(data)          (0x0FFF0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_osd_height(data)         (0x00000FFF&(data))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_get_osd_v_sta(data)      ((0x0FFF0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_V_Location_Ctrl_get_osd_height(data)     (0x00000FFF&(data))

#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff                                   0x1802E650
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_reg_addr                          "0xB802E650"
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_reg                               0xB802E650
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_inst_addr                         "0x000E"
#define  set_OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_reg(data)                     (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_reg                           (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_reg))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c0_0_shift                 (24)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c0_1_shift                 (16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c1_0_shift                 (8)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c1_1_shift                 (0)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c0_0_mask                  (0xFF000000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c0_1_mask                  (0x00FF0000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c1_0_mask                  (0x0000FF00)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c1_1_mask                  (0x000000FF)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c0_0(data)                 (0xFF000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c0_1(data)                 (0x00FF0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c1_0(data)                 (0x0000FF00&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_sr_hor_c1_1(data)                 (0x000000FF&(data))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_get_sr_hor_c0_0(data)             ((0xFF000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_get_sr_hor_c0_1(data)             ((0x00FF0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_get_sr_hor_c1_0(data)             ((0x0000FF00&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Hcoeff_get_sr_hor_c1_1(data)             (0x000000FF&(data))

#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff                                   0x1802E654
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_reg_addr                          "0xB802E654"
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_reg                               0xB802E654
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_inst_addr                         "0x000F"
#define  set_OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_reg(data)                     (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_reg                           (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_reg))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c0_0_shift                 (24)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c0_1_shift                 (16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c1_0_shift                 (8)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c1_1_shift                 (0)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c0_0_mask                  (0xFF000000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c0_1_mask                  (0x00FF0000)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c1_0_mask                  (0x0000FF00)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c1_1_mask                  (0x000000FF)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c0_0(data)                 (0xFF000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c0_1(data)                 (0x00FF0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c1_0(data)                 (0x0000FF00&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_sr_ver_c1_1(data)                 (0x000000FF&(data))
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_get_sr_ver_c0_0(data)             ((0xFF000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_get_sr_ver_c0_1(data)             ((0x00FF0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_get_sr_ver_c1_0(data)             ((0x0000FF00&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_SR_1_Vcoeff_get_sr_ver_c1_1(data)             (0x000000FF&(data))

#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1                                      0x1802E670
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_reg_addr                             "0xB802E670"
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_reg                                  0xB802E670
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_inst_addr                            "0x0010"
#define  set_OSD_SECURITY_OSD_SECURITY_MIXER_b1_reg(data)                        (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_b1_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_MIXER_b1_reg                              (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_b1_reg))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k1_shift                          (24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k2_shift                          (16)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k3_shift                          (8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k4_shift                          (0)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k1_mask                           (0x3F000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k2_mask                           (0x003F0000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k3_mask                           (0x00003F00)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k4_mask                           (0x0000003F)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k1(data)                          (0x3F000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k2(data)                          (0x003F0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k3(data)                          (0x00003F00&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_b1_k4(data)                          (0x0000003F&(data))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_get_b1_k1(data)                      ((0x3F000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_get_b1_k2(data)                      ((0x003F0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_get_b1_k3(data)                      ((0x00003F00&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b1_get_b1_k4(data)                      (0x0000003F&(data))

#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2                                      0x1802E674
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_reg_addr                             "0xB802E674"
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_reg                                  0xB802E674
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_inst_addr                            "0x0011"
#define  set_OSD_SECURITY_OSD_SECURITY_MIXER_b2_reg(data)                        (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_b2_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_MIXER_b2_reg                              (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_b2_reg))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k1_shift                          (24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k2_shift                          (16)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k3_shift                          (8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k4_shift                          (0)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k1_mask                           (0x3F000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k2_mask                           (0x003F0000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k3_mask                           (0x00003F00)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k4_mask                           (0x0000003F)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k1(data)                          (0x3F000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k2(data)                          (0x003F0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k3(data)                          (0x00003F00&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_b2_k4(data)                          (0x0000003F&(data))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_get_b2_k1(data)                      ((0x3F000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_get_b2_k2(data)                      ((0x003F0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_get_b2_k3(data)                      ((0x00003F00&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b2_get_b2_k4(data)                      (0x0000003F&(data))

#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3                                      0x1802E678
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_reg_addr                             "0xB802E678"
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_reg                                  0xB802E678
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_inst_addr                            "0x0012"
#define  set_OSD_SECURITY_OSD_SECURITY_MIXER_b3_reg(data)                        (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_b3_reg)=data)
#define  get_OSD_SECURITY_OSD_SECURITY_MIXER_b3_reg                              (*((volatile unsigned int*)OSD_SECURITY_OSD_SECURITY_MIXER_b3_reg))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k1_shift                          (24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k2_shift                          (16)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k3_shift                          (8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k4_shift                          (0)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k1_mask                           (0x3F000000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k2_mask                           (0x003F0000)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k3_mask                           (0x00003F00)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k4_mask                           (0x0000003F)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k1(data)                          (0x3F000000&((data)<<24))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k2(data)                          (0x003F0000&((data)<<16))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k3(data)                          (0x00003F00&((data)<<8))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_b3_k4(data)                          (0x0000003F&(data))
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_get_b3_k1(data)                      ((0x3F000000&(data))>>24)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_get_b3_k2(data)                      ((0x003F0000&(data))>>16)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_get_b3_k3(data)                      ((0x00003F00&(data))>>8)
#define  OSD_SECURITY_OSD_SECURITY_MIXER_b3_get_b3_k4(data)                      (0x0000003F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======OSD_SECURITY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  c3_security_en:1;
        RBus_UInt32  c2_security_en:1;
        RBus_UInt32  c1_security_en:1;
        RBus_UInt32  c0_security_en:1;
        RBus_UInt32  res2:23;
        RBus_UInt32  osd_security_en:1;
    };
}osd_security_osd_security_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802e604_31_2:30;
        RBus_UInt32  mixero1_en:1;
        RBus_UInt32  mixer_en:1;
    };
}osd_security_osd_security_mixer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  c3_plane_alpha_en:1;
        RBus_UInt32  c2_plane_alpha_en:1;
        RBus_UInt32  c1_plane_alpha_en:1;
        RBus_UInt32  c0_plane_alpha_en:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  c3_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  c2_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  c1_sel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  c0_sel:3;
    };
}osd_security_osd_security_mixer_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sta_l4:4;
        RBus_UInt32  res2:12;
    };
}osd_security_osd_security_line_buffer_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  size_l4:4;
        RBus_UInt32  res2:12;
    };
}osd_security_osd_security_line_buffer_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  osdsr3_switch_to:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  osdsr2_switch_to:3;
        RBus_UInt32  res3:4;
    };
}osd_security_osd_security_gdma_switch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  osd1_1b:1;
        RBus_UInt32  osd1_2b:1;
        RBus_UInt32  osd1_4b:1;
        RBus_UInt32  osd1_8b:1;
        RBus_UInt32  osd1_wi_endian:1;
        RBus_UInt32  osd1_rgb_out:1;
        RBus_UInt32  osd1_rotate:1;
        RBus_UInt32  osd1_en:1;
    };
}osd_security_osd_security_gdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_wi_addr:32;
    };
}osd_security_osd_security_gdma_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  osd1_w:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  osd1_h:13;
    };
}osd_security_osd_security_gdma_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  link_with_smooth_toggle:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
    };
}osd_security_osd_security_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_zoom_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  ver_tap_num:2;
        RBus_UInt32  ver_factor:20;
    };
}osd_security_osd_security_sr_1_scaleup_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_zoom_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  hor_factor:20;
    };
}osd_security_osd_security_sr_1_scaleup_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  osd_h_sta:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  osd_width:13;
    };
}osd_security_osd_security_sr_1_h_location_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_v_sta:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  osd_height:12;
    };
}osd_security_osd_security_sr_1_v_location_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_c0_0:8;
        RBus_UInt32  sr_hor_c0_1:8;
        RBus_UInt32  sr_hor_c1_0:8;
        RBus_UInt32  sr_hor_c1_1:8;
    };
}osd_security_osd_security_sr_1_hcoeff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c0_0:8;
        RBus_UInt32  sr_ver_c0_1:8;
        RBus_UInt32  sr_ver_c1_0:8;
        RBus_UInt32  sr_ver_c1_1:8;
    };
}osd_security_osd_security_sr_1_vcoeff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  b1_k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  b1_k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  b1_k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  b1_k4:6;
    };
}osd_security_osd_security_mixer_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  b2_k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  b2_k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  b2_k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  b2_k4:6;
    };
}osd_security_osd_security_mixer_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  b3_k1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  b3_k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  b3_k3:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  b3_k4:6;
    };
}osd_security_osd_security_mixer_b3_RBUS;

#else //apply LITTLE_ENDIAN

//======OSD_SECURITY register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_security_en:1;
        RBus_UInt32  res1:23;
        RBus_UInt32  c0_security_en:1;
        RBus_UInt32  c1_security_en:1;
        RBus_UInt32  c2_security_en:1;
        RBus_UInt32  c3_security_en:1;
        RBus_UInt32  res2:4;
    };
}osd_security_osd_security_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mixer_en:1;
        RBus_UInt32  mixero1_en:1;
        RBus_UInt32  dummy1802e604_31_2:30;
    };
}osd_security_osd_security_mixer_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  c1_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  c2_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  c3_sel:3;
        RBus_UInt32  res4:9;
        RBus_UInt32  c0_plane_alpha_en:1;
        RBus_UInt32  c1_plane_alpha_en:1;
        RBus_UInt32  c2_plane_alpha_en:1;
        RBus_UInt32  c3_plane_alpha_en:1;
        RBus_UInt32  res5:4;
    };
}osd_security_osd_security_mixer_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  sta_l4:4;
        RBus_UInt32  res2:16;
    };
}osd_security_osd_security_line_buffer_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  size_l4:4;
        RBus_UInt32  res2:16;
    };
}osd_security_osd_security_line_buffer_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  osdsr2_switch_to:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  osdsr3_switch_to:3;
        RBus_UInt32  res3:21;
    };
}osd_security_osd_security_gdma_switch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_en:1;
        RBus_UInt32  osd1_rotate:1;
        RBus_UInt32  osd1_rgb_out:1;
        RBus_UInt32  osd1_wi_endian:1;
        RBus_UInt32  osd1_8b:1;
        RBus_UInt32  osd1_4b:1;
        RBus_UInt32  osd1_2b:1;
        RBus_UInt32  osd1_1b:1;
        RBus_UInt32  res1:24;
    };
}osd_security_osd_security_gdma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_wi_addr:32;
    };
}osd_security_osd_security_gdma_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd1_h:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  osd1_w:13;
        RBus_UInt32  res2:3;
    };
}osd_security_osd_security_gdma_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  link_with_smooth_toggle:1;
    };
}osd_security_osd_security_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_factor:20;
        RBus_UInt32  ver_tap_num:2;
        RBus_UInt32  ver_ini:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_zoom_en:1;
    };
}osd_security_osd_security_sr_1_scaleup_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_factor:20;
        RBus_UInt32  res1:2;
        RBus_UInt32  hor_ini:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  h_zoom_en:1;
    };
}osd_security_osd_security_sr_1_scaleup_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_width:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  osd_h_sta:13;
        RBus_UInt32  res2:3;
    };
}osd_security_osd_security_sr_1_h_location_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  osd_height:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  osd_v_sta:12;
        RBus_UInt32  res2:4;
    };
}osd_security_osd_security_sr_1_v_location_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_hor_c1_1:8;
        RBus_UInt32  sr_hor_c1_0:8;
        RBus_UInt32  sr_hor_c0_1:8;
        RBus_UInt32  sr_hor_c0_0:8;
    };
}osd_security_osd_security_sr_1_hcoeff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sr_ver_c1_1:8;
        RBus_UInt32  sr_ver_c1_0:8;
        RBus_UInt32  sr_ver_c0_1:8;
        RBus_UInt32  sr_ver_c0_0:8;
    };
}osd_security_osd_security_sr_1_vcoeff_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b1_k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  b1_k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  b1_k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  b1_k1:6;
        RBus_UInt32  res4:2;
    };
}osd_security_osd_security_mixer_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b2_k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  b2_k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  b2_k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  b2_k1:6;
        RBus_UInt32  res4:2;
    };
}osd_security_osd_security_mixer_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  b3_k4:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  b3_k3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  b3_k2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  b3_k1:6;
        RBus_UInt32  res4:2;
    };
}osd_security_osd_security_mixer_b3_RBUS;




#endif 


#endif 
