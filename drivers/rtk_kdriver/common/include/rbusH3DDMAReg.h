/**
* @file rbusH3DDMAReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015-3-4
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_H3DDMA_REG_H_
#define _RBUS_H3DDMA_REG_H_

//#include "rbusTypes.h"
#include "rbusTypes.h"



//  H3DDMA Register Address
#define  H3DDMA_LR_Separate_CTRL1                                                0x18025800
#define  H3DDMA_LR_Separate_CTRL1_reg_addr                                       "0xB8025800"
#define  H3DDMA_LR_Separate_CTRL1_reg                                            0xB8025800
#define  H3DDMA_LR_Separate_CTRL1_inst_addr                                      "0x0000"
#define  set_H3DDMA_LR_Separate_CTRL1_reg(data)                                  (*((volatile unsigned int*)H3DDMA_LR_Separate_CTRL1_reg)=data)
#define  get_H3DDMA_LR_Separate_CTRL1_reg                                        (*((volatile unsigned int*)H3DDMA_LR_Separate_CTRL1_reg))
#define  H3DDMA_LR_Separate_CTRL1_dummy_lr_ctrl1_shift                           (27)
#define  H3DDMA_LR_Separate_CTRL1_hdmi420_en_shift                               (26)
#define  H3DDMA_LR_Separate_CTRL1_chess_board_format_shift                       (25)
#define  H3DDMA_LR_Separate_CTRL1_hdmi_3d_sel_shift                              (24)
#define  H3DDMA_LR_Separate_CTRL1_vs_inv_shift                                   (23)
#define  H3DDMA_LR_Separate_CTRL1_hs_inv_shift                                   (22)
#define  H3DDMA_LR_Separate_CTRL1_progressive_shift                              (20)
#define  H3DDMA_LR_Separate_CTRL1_hdmi_3d_structure_shift                        (16)
#define  H3DDMA_LR_Separate_CTRL1_fp_vact_space1_shift                           (8)
#define  H3DDMA_LR_Separate_CTRL1_fp_vact_space2_shift                           (0)
#define  H3DDMA_LR_Separate_CTRL1_dummy_lr_ctrl1_mask                            (0xF8000000)
#define  H3DDMA_LR_Separate_CTRL1_hdmi420_en_mask                                (0x04000000)
#define  H3DDMA_LR_Separate_CTRL1_chess_board_format_mask                        (0x02000000)
#define  H3DDMA_LR_Separate_CTRL1_hdmi_3d_sel_mask                               (0x01000000)
#define  H3DDMA_LR_Separate_CTRL1_vs_inv_mask                                    (0x00800000)
#define  H3DDMA_LR_Separate_CTRL1_hs_inv_mask                                    (0x00400000)
#define  H3DDMA_LR_Separate_CTRL1_progressive_mask                               (0x00100000)
#define  H3DDMA_LR_Separate_CTRL1_hdmi_3d_structure_mask                         (0x000F0000)
#define  H3DDMA_LR_Separate_CTRL1_fp_vact_space1_mask                            (0x0000FF00)
#define  H3DDMA_LR_Separate_CTRL1_fp_vact_space2_mask                            (0x000000FF)
#define  H3DDMA_LR_Separate_CTRL1_dummy_lr_ctrl1(data)                           (0xF8000000&((data)<<27))
#define  H3DDMA_LR_Separate_CTRL1_hdmi420_en(data)                               (0x04000000&((data)<<26))
#define  H3DDMA_LR_Separate_CTRL1_chess_board_format(data)                       (0x02000000&((data)<<25))
#define  H3DDMA_LR_Separate_CTRL1_hdmi_3d_sel(data)                              (0x01000000&((data)<<24))
#define  H3DDMA_LR_Separate_CTRL1_vs_inv(data)                                   (0x00800000&((data)<<23))
#define  H3DDMA_LR_Separate_CTRL1_hs_inv(data)                                   (0x00400000&((data)<<22))
#define  H3DDMA_LR_Separate_CTRL1_progressive(data)                              (0x00100000&((data)<<20))
#define  H3DDMA_LR_Separate_CTRL1_hdmi_3d_structure(data)                        (0x000F0000&((data)<<16))
#define  H3DDMA_LR_Separate_CTRL1_fp_vact_space1(data)                           (0x0000FF00&((data)<<8))
#define  H3DDMA_LR_Separate_CTRL1_fp_vact_space2(data)                           (0x000000FF&(data))
#define  H3DDMA_LR_Separate_CTRL1_get_dummy_lr_ctrl1(data)                       ((0xF8000000&(data))>>27)
#define  H3DDMA_LR_Separate_CTRL1_get_hdmi420_en(data)                           ((0x04000000&(data))>>26)
#define  H3DDMA_LR_Separate_CTRL1_get_chess_board_format(data)                   ((0x02000000&(data))>>25)
#define  H3DDMA_LR_Separate_CTRL1_get_hdmi_3d_sel(data)                          ((0x01000000&(data))>>24)
#define  H3DDMA_LR_Separate_CTRL1_get_vs_inv(data)                               ((0x00800000&(data))>>23)
#define  H3DDMA_LR_Separate_CTRL1_get_hs_inv(data)                               ((0x00400000&(data))>>22)
#define  H3DDMA_LR_Separate_CTRL1_get_progressive(data)                          ((0x00100000&(data))>>20)
#define  H3DDMA_LR_Separate_CTRL1_get_hdmi_3d_structure(data)                    ((0x000F0000&(data))>>16)
#define  H3DDMA_LR_Separate_CTRL1_get_fp_vact_space1(data)                       ((0x0000FF00&(data))>>8)
#define  H3DDMA_LR_Separate_CTRL1_get_fp_vact_space2(data)                       (0x000000FF&(data))

#define  H3DDMA_LR_Separate_CTRL2                                                0x18025804
#define  H3DDMA_LR_Separate_CTRL2_reg_addr                                       "0xB8025804"
#define  H3DDMA_LR_Separate_CTRL2_reg                                            0xB8025804
#define  H3DDMA_LR_Separate_CTRL2_inst_addr                                      "0x0001"
#define  set_H3DDMA_LR_Separate_CTRL2_reg(data)                                  (*((volatile unsigned int*)H3DDMA_LR_Separate_CTRL2_reg)=data)
#define  get_H3DDMA_LR_Separate_CTRL2_reg                                        (*((volatile unsigned int*)H3DDMA_LR_Separate_CTRL2_reg))
#define  H3DDMA_LR_Separate_CTRL2_vact_shift                                     (16)
#define  H3DDMA_LR_Separate_CTRL2_hact_shift                                     (0)
#define  H3DDMA_LR_Separate_CTRL2_vact_mask                                      (0xFFFF0000)
#define  H3DDMA_LR_Separate_CTRL2_hact_mask                                      (0x00007FFF)
#define  H3DDMA_LR_Separate_CTRL2_vact(data)                                     (0xFFFF0000&((data)<<16))
#define  H3DDMA_LR_Separate_CTRL2_hact(data)                                     (0x00007FFF&(data))
#define  H3DDMA_LR_Separate_CTRL2_get_vact(data)                                 ((0xFFFF0000&(data))>>16)
#define  H3DDMA_LR_Separate_CTRL2_get_hact(data)                                 (0x00007FFF&(data))

#define  H3DDMA_LR_Separate_insert_vs_start                                      0x18025808
#define  H3DDMA_LR_Separate_insert_vs_start_reg_addr                             "0xB8025808"
#define  H3DDMA_LR_Separate_insert_vs_start_reg                                  0xB8025808
#define  H3DDMA_LR_Separate_insert_vs_start_inst_addr                            "0x0002"
#define  set_H3DDMA_LR_Separate_insert_vs_start_reg(data)                        (*((volatile unsigned int*)H3DDMA_LR_Separate_insert_vs_start_reg)=data)
#define  get_H3DDMA_LR_Separate_insert_vs_start_reg                              (*((volatile unsigned int*)H3DDMA_LR_Separate_insert_vs_start_reg))
#define  H3DDMA_LR_Separate_insert_vs_start_hstart_shift                         (8)
#define  H3DDMA_LR_Separate_insert_vs_start_vstart_shift                         (0)
#define  H3DDMA_LR_Separate_insert_vs_start_hstart_mask                          (0x001FFF00)
#define  H3DDMA_LR_Separate_insert_vs_start_vstart_mask                          (0x000000FF)
#define  H3DDMA_LR_Separate_insert_vs_start_hstart(data)                         (0x001FFF00&((data)<<8))
#define  H3DDMA_LR_Separate_insert_vs_start_vstart(data)                         (0x000000FF&(data))
#define  H3DDMA_LR_Separate_insert_vs_start_get_hstart(data)                     ((0x001FFF00&(data))>>8)
#define  H3DDMA_LR_Separate_insert_vs_start_get_vstart(data)                     (0x000000FF&(data))

#define  H3DDMA_LR_Separate_insert_vs_end                                        0x1802580C
#define  H3DDMA_LR_Separate_insert_vs_end_reg_addr                               "0xB802580C"
#define  H3DDMA_LR_Separate_insert_vs_end_reg                                    0xB802580C
#define  H3DDMA_LR_Separate_insert_vs_end_inst_addr                              "0x0003"
#define  set_H3DDMA_LR_Separate_insert_vs_end_reg(data)                          (*((volatile unsigned int*)H3DDMA_LR_Separate_insert_vs_end_reg)=data)
#define  get_H3DDMA_LR_Separate_insert_vs_end_reg                                (*((volatile unsigned int*)H3DDMA_LR_Separate_insert_vs_end_reg))
#define  H3DDMA_LR_Separate_insert_vs_end_hend_shift                             (8)
#define  H3DDMA_LR_Separate_insert_vs_end_vend_shift                             (0)
#define  H3DDMA_LR_Separate_insert_vs_end_hend_mask                              (0x001FFF00)
#define  H3DDMA_LR_Separate_insert_vs_end_vend_mask                              (0x000000FF)
#define  H3DDMA_LR_Separate_insert_vs_end_hend(data)                             (0x001FFF00&((data)<<8))
#define  H3DDMA_LR_Separate_insert_vs_end_vend(data)                             (0x000000FF&(data))
#define  H3DDMA_LR_Separate_insert_vs_end_get_hend(data)                         ((0x001FFF00&(data))>>8)
#define  H3DDMA_LR_Separate_insert_vs_end_get_vend(data)                         (0x000000FF&(data))

#define  H3DDMA_Cap_CTL0                                                         0x18025810
#define  H3DDMA_Cap_CTL0_reg_addr                                                "0xB8025810"
#define  H3DDMA_Cap_CTL0_reg                                                     0xB8025810
#define  H3DDMA_Cap_CTL0_inst_addr                                               "0x0004"
#define  set_H3DDMA_Cap_CTL0_reg(data)                                           (*((volatile unsigned int*)H3DDMA_Cap_CTL0_reg)=data)
#define  get_H3DDMA_Cap_CTL0_reg                                                 (*((volatile unsigned int*)H3DDMA_Cap_CTL0_reg))
#define  H3DDMA_Cap_CTL0_triple_buf_en_shift                                     (31)
#define  H3DDMA_Cap_CTL0_cap_block_fw_shift                                      (29)
#define  H3DDMA_Cap_CTL0_set_block_sel_shift                                     (28)
#define  H3DDMA_Cap_CTL0_quad_buf_en_shift                                       (27)
#define  H3DDMA_Cap_CTL0_freeze_en_shift                                         (24)
#define  H3DDMA_Cap_CTL0_vs_fall_rst_en_shift                                    (23)
#define  H3DDMA_Cap_CTL0_auto_block_sel_en_shift                                 (22)
#define  H3DDMA_Cap_CTL0_half_wr_en_shift                                        (21)
#define  H3DDMA_Cap_CTL0_half_wr_sel_shift                                       (20)
#define  H3DDMA_Cap_CTL0_bit_sel_shift                                           (18)
#define  H3DDMA_Cap_CTL0_pixel_encoding_shift                                    (16)
#define  H3DDMA_Cap_CTL0_cap_write_len_shift                                     (8)
#define  H3DDMA_Cap_CTL0_cap_write_rem_shift                                     (0)
#define  H3DDMA_Cap_CTL0_triple_buf_en_mask                                      (0x80000000)
#define  H3DDMA_Cap_CTL0_cap_block_fw_mask                                       (0x60000000)
#define  H3DDMA_Cap_CTL0_set_block_sel_mask                                      (0x10000000)
#define  H3DDMA_Cap_CTL0_quad_buf_en_mask                                        (0x08000000)
#define  H3DDMA_Cap_CTL0_freeze_en_mask                                          (0x01000000)
#define  H3DDMA_Cap_CTL0_vs_fall_rst_en_mask                                     (0x00800000)
#define  H3DDMA_Cap_CTL0_auto_block_sel_en_mask                                  (0x00400000)
#define  H3DDMA_Cap_CTL0_half_wr_en_mask                                         (0x00200000)
#define  H3DDMA_Cap_CTL0_half_wr_sel_mask                                        (0x00100000)
#define  H3DDMA_Cap_CTL0_bit_sel_mask                                            (0x00040000)
#define  H3DDMA_Cap_CTL0_pixel_encoding_mask                                     (0x00030000)
#define  H3DDMA_Cap_CTL0_cap_write_len_mask                                      (0x00007F00)
#define  H3DDMA_Cap_CTL0_cap_write_rem_mask                                      (0x0000007F)
#define  H3DDMA_Cap_CTL0_triple_buf_en(data)                                     (0x80000000&((data)<<31))
#define  H3DDMA_Cap_CTL0_cap_block_fw(data)                                      (0x60000000&((data)<<29))
#define  H3DDMA_Cap_CTL0_set_block_sel(data)                                     (0x10000000&((data)<<28))
#define  H3DDMA_Cap_CTL0_quad_buf_en(data)                                       (0x08000000&((data)<<27))
#define  H3DDMA_Cap_CTL0_freeze_en(data)                                         (0x01000000&((data)<<24))
#define  H3DDMA_Cap_CTL0_vs_fall_rst_en(data)                                    (0x00800000&((data)<<23))
#define  H3DDMA_Cap_CTL0_auto_block_sel_en(data)                                 (0x00400000&((data)<<22))
#define  H3DDMA_Cap_CTL0_half_wr_en(data)                                        (0x00200000&((data)<<21))
#define  H3DDMA_Cap_CTL0_half_wr_sel(data)                                       (0x00100000&((data)<<20))
#define  H3DDMA_Cap_CTL0_bit_sel(data)                                           (0x00040000&((data)<<18))
#define  H3DDMA_Cap_CTL0_pixel_encoding(data)                                    (0x00030000&((data)<<16))
#define  H3DDMA_Cap_CTL0_cap_write_len(data)                                     (0x00007F00&((data)<<8))
#define  H3DDMA_Cap_CTL0_cap_write_rem(data)                                     (0x0000007F&(data))
#define  H3DDMA_Cap_CTL0_get_triple_buf_en(data)                                 ((0x80000000&(data))>>31)
#define  H3DDMA_Cap_CTL0_get_cap_block_fw(data)                                  ((0x60000000&(data))>>29)
#define  H3DDMA_Cap_CTL0_get_set_block_sel(data)                                 ((0x10000000&(data))>>28)
#define  H3DDMA_Cap_CTL0_get_quad_buf_en(data)                                   ((0x08000000&(data))>>27)
#define  H3DDMA_Cap_CTL0_get_freeze_en(data)                                     ((0x01000000&(data))>>24)
#define  H3DDMA_Cap_CTL0_get_vs_fall_rst_en(data)                                ((0x00800000&(data))>>23)
#define  H3DDMA_Cap_CTL0_get_auto_block_sel_en(data)                             ((0x00400000&(data))>>22)
#define  H3DDMA_Cap_CTL0_get_half_wr_en(data)                                    ((0x00200000&(data))>>21)
#define  H3DDMA_Cap_CTL0_get_half_wr_sel(data)                                   ((0x00100000&(data))>>20)
#define  H3DDMA_Cap_CTL0_get_bit_sel(data)                                       ((0x00040000&(data))>>18)
#define  H3DDMA_Cap_CTL0_get_pixel_encoding(data)                                ((0x00030000&(data))>>16)
#define  H3DDMA_Cap_CTL0_get_cap_write_len(data)                                 ((0x00007F00&(data))>>8)
#define  H3DDMA_Cap_CTL0_get_cap_write_rem(data)                                 (0x0000007F&(data))

#define  H3DDMA_Cap_CTL1                                                         0x18025814
#define  H3DDMA_Cap_CTL1_reg_addr                                                "0xB8025814"
#define  H3DDMA_Cap_CTL1_reg                                                     0xB8025814
#define  H3DDMA_Cap_CTL1_inst_addr                                               "0x0005"
#define  set_H3DDMA_Cap_CTL1_reg(data)                                           (*((volatile unsigned int*)H3DDMA_Cap_CTL1_reg)=data)
#define  get_H3DDMA_Cap_CTL1_reg                                                 (*((volatile unsigned int*)H3DDMA_Cap_CTL1_reg))
#define  H3DDMA_Cap_CTL1_dummy_cap_ctl1_shift                                    (15)
#define  H3DDMA_Cap_CTL1_cap_water_lv_shift                                      (8)
#define  H3DDMA_Cap_CTL1_cap_write_num_shift                                     (0)
#define  H3DDMA_Cap_CTL1_dummy_cap_ctl1_mask                                     (0xFFFF8000)
#define  H3DDMA_Cap_CTL1_cap_water_lv_mask                                       (0x00007F00)
#define  H3DDMA_Cap_CTL1_cap_write_num_mask                                      (0x000000FF)
#define  H3DDMA_Cap_CTL1_dummy_cap_ctl1(data)                                    (0xFFFF8000&((data)<<15))
#define  H3DDMA_Cap_CTL1_cap_water_lv(data)                                      (0x00007F00&((data)<<8))
#define  H3DDMA_Cap_CTL1_cap_write_num(data)                                     (0x000000FF&(data))
#define  H3DDMA_Cap_CTL1_get_dummy_cap_ctl1(data)                                ((0xFFFF8000&(data))>>15)
#define  H3DDMA_Cap_CTL1_get_cap_water_lv(data)                                  ((0x00007F00&(data))>>8)
#define  H3DDMA_Cap_CTL1_get_cap_write_num(data)                                 (0x000000FF&(data))

#define  H3DDMA_Cap_BoundaryAddr1                                                0x18025818
#define  H3DDMA_Cap_BoundaryAddr1_reg_addr                                       "0xB8025818"
#define  H3DDMA_Cap_BoundaryAddr1_reg                                            0xB8025818
#define  H3DDMA_Cap_BoundaryAddr1_inst_addr                                      "0x0006"
#define  set_H3DDMA_Cap_BoundaryAddr1_reg(data)                                  (*((volatile unsigned int*)H3DDMA_Cap_BoundaryAddr1_reg)=data)
#define  get_H3DDMA_Cap_BoundaryAddr1_reg                                        (*((volatile unsigned int*)H3DDMA_Cap_BoundaryAddr1_reg))
#define  H3DDMA_Cap_BoundaryAddr1_cap_mem_up_limit_shift                         (3)
#define  H3DDMA_Cap_BoundaryAddr1_cap_mem_up_limit_mask                          (0xFFFFFFF8)
#define  H3DDMA_Cap_BoundaryAddr1_cap_mem_up_limit(data)                         (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_BoundaryAddr1_get_cap_mem_up_limit(data)                     ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_BoundaryAddr2                                                0x1802581C
#define  H3DDMA_Cap_BoundaryAddr2_reg_addr                                       "0xB802581C"
#define  H3DDMA_Cap_BoundaryAddr2_reg                                            0xB802581C
#define  H3DDMA_Cap_BoundaryAddr2_inst_addr                                      "0x0007"
#define  set_H3DDMA_Cap_BoundaryAddr2_reg(data)                                  (*((volatile unsigned int*)H3DDMA_Cap_BoundaryAddr2_reg)=data)
#define  get_H3DDMA_Cap_BoundaryAddr2_reg                                        (*((volatile unsigned int*)H3DDMA_Cap_BoundaryAddr2_reg))
#define  H3DDMA_Cap_BoundaryAddr2_cap_mem_low_limit_shift                        (3)
#define  H3DDMA_Cap_BoundaryAddr2_cap_mem_low_limit_mask                         (0xFFFFFFF8)
#define  H3DDMA_Cap_BoundaryAddr2_cap_mem_low_limit(data)                        (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_BoundaryAddr2_get_cap_mem_low_limit(data)                    ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_L1_Start                                                     0x18025820
#define  H3DDMA_Cap_L1_Start_reg_addr                                            "0xB8025820"
#define  H3DDMA_Cap_L1_Start_reg                                                 0xB8025820
#define  H3DDMA_Cap_L1_Start_inst_addr                                           "0x0008"
#define  set_H3DDMA_Cap_L1_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_L1_Start_reg)=data)
#define  get_H3DDMA_Cap_L1_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_L1_Start_reg))
#define  H3DDMA_Cap_L1_Start_cap_l1_start_shift                                  (3)
#define  H3DDMA_Cap_L1_Start_cap_l1_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_L1_Start_cap_l1_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_L1_Start_get_cap_l1_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_L2_Start                                                     0x18025824
#define  H3DDMA_Cap_L2_Start_reg_addr                                            "0xB8025824"
#define  H3DDMA_Cap_L2_Start_reg                                                 0xB8025824
#define  H3DDMA_Cap_L2_Start_inst_addr                                           "0x0009"
#define  set_H3DDMA_Cap_L2_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_L2_Start_reg)=data)
#define  get_H3DDMA_Cap_L2_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_L2_Start_reg))
#define  H3DDMA_Cap_L2_Start_cap_l2_start_shift                                  (3)
#define  H3DDMA_Cap_L2_Start_cap_l2_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_L2_Start_cap_l2_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_L2_Start_get_cap_l2_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_R1_Start                                                     0x18025828
#define  H3DDMA_Cap_R1_Start_reg_addr                                            "0xB8025828"
#define  H3DDMA_Cap_R1_Start_reg                                                 0xB8025828
#define  H3DDMA_Cap_R1_Start_inst_addr                                           "0x000A"
#define  set_H3DDMA_Cap_R1_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_R1_Start_reg)=data)
#define  get_H3DDMA_Cap_R1_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_R1_Start_reg))
#define  H3DDMA_Cap_R1_Start_cap_r1_start_shift                                  (3)
#define  H3DDMA_Cap_R1_Start_cap_r1_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_R1_Start_cap_r1_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_R1_Start_get_cap_r1_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_R2_Start                                                     0x1802582C
#define  H3DDMA_Cap_R2_Start_reg_addr                                            "0xB802582C"
#define  H3DDMA_Cap_R2_Start_reg                                                 0xB802582C
#define  H3DDMA_Cap_R2_Start_inst_addr                                           "0x000B"
#define  set_H3DDMA_Cap_R2_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_R2_Start_reg)=data)
#define  get_H3DDMA_Cap_R2_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_R2_Start_reg))
#define  H3DDMA_Cap_R2_Start_cap_r2_start_shift                                  (3)
#define  H3DDMA_Cap_R2_Start_cap_r2_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_R2_Start_cap_r2_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_R2_Start_get_cap_r2_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_L1_Start_db                                                  0x18025830
#define  H3DDMA_Cap_L1_Start_db_reg_addr                                         "0xB8025830"
#define  H3DDMA_Cap_L1_Start_db_reg                                              0xB8025830
#define  H3DDMA_Cap_L1_Start_db_inst_addr                                        "0x000C"
#define  set_H3DDMA_Cap_L1_Start_db_reg(data)                                    (*((volatile unsigned int*)H3DDMA_Cap_L1_Start_db_reg)=data)
#define  get_H3DDMA_Cap_L1_Start_db_reg                                          (*((volatile unsigned int*)H3DDMA_Cap_L1_Start_db_reg))
#define  H3DDMA_Cap_L1_Start_db_cap_l1_start_db_shift                            (3)
#define  H3DDMA_Cap_L1_Start_db_cap_l1_start_db_mask                             (0xFFFFFFF8)
#define  H3DDMA_Cap_L1_Start_db_cap_l1_start_db(data)                            (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_L1_Start_db_get_cap_l1_start_db(data)                        ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_R1_Start_db                                                  0x18025834
#define  H3DDMA_Cap_R1_Start_db_reg_addr                                         "0xB8025834"
#define  H3DDMA_Cap_R1_Start_db_reg                                              0xB8025834
#define  H3DDMA_Cap_R1_Start_db_inst_addr                                        "0x000D"
#define  set_H3DDMA_Cap_R1_Start_db_reg(data)                                    (*((volatile unsigned int*)H3DDMA_Cap_R1_Start_db_reg)=data)
#define  get_H3DDMA_Cap_R1_Start_db_reg                                          (*((volatile unsigned int*)H3DDMA_Cap_R1_Start_db_reg))
#define  H3DDMA_Cap_R1_Start_db_cap_r1_start_db_shift                            (3)
#define  H3DDMA_Cap_R1_Start_db_cap_r1_start_db_mask                             (0xFFFFFFF8)
#define  H3DDMA_Cap_R1_Start_db_cap_r1_start_db(data)                            (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_R1_Start_db_get_cap_r1_start_db(data)                        ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_Status                                                       0x18025838
#define  H3DDMA_Cap_Status_reg_addr                                              "0xB8025838"
#define  H3DDMA_Cap_Status_reg                                                   0xB8025838
#define  H3DDMA_Cap_Status_inst_addr                                             "0x000E"
#define  set_H3DDMA_Cap_Status_reg(data)                                         (*((volatile unsigned int*)H3DDMA_Cap_Status_reg)=data)
#define  get_H3DDMA_Cap_Status_reg                                               (*((volatile unsigned int*)H3DDMA_Cap_Status_reg))
#define  H3DDMA_Cap_Status_cap2_block_sel_shift                                  (20)
#define  H3DDMA_Cap_Status_cap_block_sel_shift                                   (18)
#define  H3DDMA_Cap_Status_cap2_last_wr_flag_shift                               (17)
#define  H3DDMA_Cap_Status_cap_last_wr_flag_shift                                (16)
#define  H3DDMA_Cap_Status_cap_block_2_shift                                     (12)
#define  H3DDMA_Cap_Status_cap_over_size_shift                                   (11)
#define  H3DDMA_Cap_Status_cap_under_size_shift                                  (10)
#define  H3DDMA_Cap_Status_freeze_ok_shift                                       (9)
#define  H3DDMA_Cap_Status_vs_rising_occur_shift                                 (8)
#define  H3DDMA_Cap_Status_tg_l_flag_shift                                       (7)
#define  H3DDMA_Cap_Status_cap_block_shift                                       (6)
#define  H3DDMA_Cap_Status_cap_field_shift                                       (5)
#define  H3DDMA_Cap_Status_cap_fifo_full_shift                                   (4)
#define  H3DDMA_Cap_Status_cap_fifo_empty_shift                                  (3)
#define  H3DDMA_Cap_Status_cap_fifo_overflow_shift                               (2)
#define  H3DDMA_Cap_Status_cap_fifo_underflow_shift                              (1)
#define  H3DDMA_Cap_Status_cap_ddr_over_range_shift                              (0)
#define  H3DDMA_Cap_Status_cap2_block_sel_mask                                   (0x00300000)
#define  H3DDMA_Cap_Status_cap_block_sel_mask                                    (0x000C0000)
#define  H3DDMA_Cap_Status_cap2_last_wr_flag_mask                                (0x00020000)
#define  H3DDMA_Cap_Status_cap_last_wr_flag_mask                                 (0x00010000)
#define  H3DDMA_Cap_Status_cap_block_2_mask                                      (0x00003000)
#define  H3DDMA_Cap_Status_cap_over_size_mask                                    (0x00000800)
#define  H3DDMA_Cap_Status_cap_under_size_mask                                   (0x00000400)
#define  H3DDMA_Cap_Status_freeze_ok_mask                                        (0x00000200)
#define  H3DDMA_Cap_Status_vs_rising_occur_mask                                  (0x00000100)
#define  H3DDMA_Cap_Status_tg_l_flag_mask                                        (0x00000080)
#define  H3DDMA_Cap_Status_cap_block_mask                                        (0x00000040)
#define  H3DDMA_Cap_Status_cap_field_mask                                        (0x00000020)
#define  H3DDMA_Cap_Status_cap_fifo_full_mask                                    (0x00000010)
#define  H3DDMA_Cap_Status_cap_fifo_empty_mask                                   (0x00000008)
#define  H3DDMA_Cap_Status_cap_fifo_overflow_mask                                (0x00000004)
#define  H3DDMA_Cap_Status_cap_fifo_underflow_mask                               (0x00000002)
#define  H3DDMA_Cap_Status_cap_ddr_over_range_mask                               (0x00000001)
#define  H3DDMA_Cap_Status_cap2_block_sel(data)                                  (0x00300000&((data)<<20))
#define  H3DDMA_Cap_Status_cap_block_sel(data)                                   (0x000C0000&((data)<<18))
#define  H3DDMA_Cap_Status_cap2_last_wr_flag(data)                               (0x00020000&((data)<<17))
#define  H3DDMA_Cap_Status_cap_last_wr_flag(data)                                (0x00010000&((data)<<16))
#define  H3DDMA_Cap_Status_cap_block_2(data)                                     (0x00003000&((data)<<12))
#define  H3DDMA_Cap_Status_cap_over_size(data)                                   (0x00000800&((data)<<11))
#define  H3DDMA_Cap_Status_cap_under_size(data)                                  (0x00000400&((data)<<10))
#define  H3DDMA_Cap_Status_freeze_ok(data)                                       (0x00000200&((data)<<9))
#define  H3DDMA_Cap_Status_vs_rising_occur(data)                                 (0x00000100&((data)<<8))
#define  H3DDMA_Cap_Status_tg_l_flag(data)                                       (0x00000080&((data)<<7))
#define  H3DDMA_Cap_Status_cap_block(data)                                       (0x00000040&((data)<<6))
#define  H3DDMA_Cap_Status_cap_field(data)                                       (0x00000020&((data)<<5))
#define  H3DDMA_Cap_Status_cap_fifo_full(data)                                   (0x00000010&((data)<<4))
#define  H3DDMA_Cap_Status_cap_fifo_empty(data)                                  (0x00000008&((data)<<3))
#define  H3DDMA_Cap_Status_cap_fifo_overflow(data)                               (0x00000004&((data)<<2))
#define  H3DDMA_Cap_Status_cap_fifo_underflow(data)                              (0x00000002&((data)<<1))
#define  H3DDMA_Cap_Status_cap_ddr_over_range(data)                              (0x00000001&(data))
#define  H3DDMA_Cap_Status_get_cap2_block_sel(data)                              ((0x00300000&(data))>>20)
#define  H3DDMA_Cap_Status_get_cap_block_sel(data)                               ((0x000C0000&(data))>>18)
#define  H3DDMA_Cap_Status_get_cap2_last_wr_flag(data)                           ((0x00020000&(data))>>17)
#define  H3DDMA_Cap_Status_get_cap_last_wr_flag(data)                            ((0x00010000&(data))>>16)
#define  H3DDMA_Cap_Status_get_cap_block_2(data)                                 ((0x00003000&(data))>>12)
#define  H3DDMA_Cap_Status_get_cap_over_size(data)                               ((0x00000800&(data))>>11)
#define  H3DDMA_Cap_Status_get_cap_under_size(data)                              ((0x00000400&(data))>>10)
#define  H3DDMA_Cap_Status_get_freeze_ok(data)                                   ((0x00000200&(data))>>9)
#define  H3DDMA_Cap_Status_get_vs_rising_occur(data)                             ((0x00000100&(data))>>8)
#define  H3DDMA_Cap_Status_get_tg_l_flag(data)                                   ((0x00000080&(data))>>7)
#define  H3DDMA_Cap_Status_get_cap_block(data)                                   ((0x00000040&(data))>>6)
#define  H3DDMA_Cap_Status_get_cap_field(data)                                   ((0x00000020&(data))>>5)
#define  H3DDMA_Cap_Status_get_cap_fifo_full(data)                               ((0x00000010&(data))>>4)
#define  H3DDMA_Cap_Status_get_cap_fifo_empty(data)                              ((0x00000008&(data))>>3)
#define  H3DDMA_Cap_Status_get_cap_fifo_overflow(data)                           ((0x00000004&(data))>>2)
#define  H3DDMA_Cap_Status_get_cap_fifo_underflow(data)                          ((0x00000002&(data))>>1)
#define  H3DDMA_Cap_Status_get_cap_ddr_over_range(data)                          (0x00000001&(data))

#define  H3DDMA_TG_v1_end                                                        0x1802583C
#define  H3DDMA_TG_v1_end_reg_addr                                               "0xB802583C"
#define  H3DDMA_TG_v1_end_reg                                                    0xB802583C
#define  H3DDMA_TG_v1_end_inst_addr                                              "0x000F"
#define  set_H3DDMA_TG_v1_end_reg(data)                                          (*((volatile unsigned int*)H3DDMA_TG_v1_end_reg)=data)
#define  get_H3DDMA_TG_v1_end_reg                                                (*((volatile unsigned int*)H3DDMA_TG_v1_end_reg))
#define  H3DDMA_TG_v1_end_pullup_en_shift                                        (25)
#define  H3DDMA_TG_v1_end_tg_hend1_shift                                         (8)
#define  H3DDMA_TG_v1_end_tg_vend1_shift                                         (0)
#define  H3DDMA_TG_v1_end_pullup_en_mask                                         (0x02000000)
#define  H3DDMA_TG_v1_end_tg_hend1_mask                                          (0x001FFF00)
#define  H3DDMA_TG_v1_end_tg_vend1_mask                                          (0x000000FF)
#define  H3DDMA_TG_v1_end_pullup_en(data)                                        (0x02000000&((data)<<25))
#define  H3DDMA_TG_v1_end_tg_hend1(data)                                         (0x001FFF00&((data)<<8))
#define  H3DDMA_TG_v1_end_tg_vend1(data)                                         (0x000000FF&(data))
#define  H3DDMA_TG_v1_end_get_pullup_en(data)                                    ((0x02000000&(data))>>25)
#define  H3DDMA_TG_v1_end_get_tg_hend1(data)                                     ((0x001FFF00&(data))>>8)
#define  H3DDMA_TG_v1_end_get_tg_vend1(data)                                     (0x000000FF&(data))

#define  H3DDMA_TG_v2_start                                                      0x18025840
#define  H3DDMA_TG_v2_start_reg_addr                                             "0xB8025840"
#define  H3DDMA_TG_v2_start_reg                                                  0xB8025840
#define  H3DDMA_TG_v2_start_inst_addr                                            "0x0010"
#define  set_H3DDMA_TG_v2_start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_TG_v2_start_reg)=data)
#define  get_H3DDMA_TG_v2_start_reg                                              (*((volatile unsigned int*)H3DDMA_TG_v2_start_reg))
#define  H3DDMA_TG_v2_start_tg_hstart2_shift                                     (16)
#define  H3DDMA_TG_v2_start_tg_vstart2_shift                                     (0)
#define  H3DDMA_TG_v2_start_tg_hstart2_mask                                      (0x1FFF0000)
#define  H3DDMA_TG_v2_start_tg_vstart2_mask                                      (0x00001FFF)
#define  H3DDMA_TG_v2_start_tg_hstart2(data)                                     (0x1FFF0000&((data)<<16))
#define  H3DDMA_TG_v2_start_tg_vstart2(data)                                     (0x00001FFF&(data))
#define  H3DDMA_TG_v2_start_get_tg_hstart2(data)                                 ((0x1FFF0000&(data))>>16)
#define  H3DDMA_TG_v2_start_get_tg_vstart2(data)                                 (0x00001FFF&(data))

#define  H3DDMA_TG_v2_end                                                        0x18025844
#define  H3DDMA_TG_v2_end_reg_addr                                               "0xB8025844"
#define  H3DDMA_TG_v2_end_reg                                                    0xB8025844
#define  H3DDMA_TG_v2_end_inst_addr                                              "0x0011"
#define  set_H3DDMA_TG_v2_end_reg(data)                                          (*((volatile unsigned int*)H3DDMA_TG_v2_end_reg)=data)
#define  get_H3DDMA_TG_v2_end_reg                                                (*((volatile unsigned int*)H3DDMA_TG_v2_end_reg))
#define  H3DDMA_TG_v2_end_tg_hend2_shift                                         (16)
#define  H3DDMA_TG_v2_end_tg_vend2_shift                                         (0)
#define  H3DDMA_TG_v2_end_tg_hend2_mask                                          (0x1FFF0000)
#define  H3DDMA_TG_v2_end_tg_vend2_mask                                          (0x00001FFF)
#define  H3DDMA_TG_v2_end_tg_hend2(data)                                         (0x1FFF0000&((data)<<16))
#define  H3DDMA_TG_v2_end_tg_vend2(data)                                         (0x00001FFF&(data))
#define  H3DDMA_TG_v2_end_get_tg_hend2(data)                                     ((0x1FFF0000&(data))>>16)
#define  H3DDMA_TG_v2_end_get_tg_vend2(data)                                     (0x00001FFF&(data))

#define  H3DDMA_TG_v3_start                                                      0x18025848
#define  H3DDMA_TG_v3_start_reg_addr                                             "0xB8025848"
#define  H3DDMA_TG_v3_start_reg                                                  0xB8025848
#define  H3DDMA_TG_v3_start_inst_addr                                            "0x0012"
#define  set_H3DDMA_TG_v3_start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_TG_v3_start_reg)=data)
#define  get_H3DDMA_TG_v3_start_reg                                              (*((volatile unsigned int*)H3DDMA_TG_v3_start_reg))
#define  H3DDMA_TG_v3_start_tg_hstart3_shift                                     (16)
#define  H3DDMA_TG_v3_start_tg_vstart3_shift                                     (0)
#define  H3DDMA_TG_v3_start_tg_hstart3_mask                                      (0x1FFF0000)
#define  H3DDMA_TG_v3_start_tg_vstart3_mask                                      (0x00001FFF)
#define  H3DDMA_TG_v3_start_tg_hstart3(data)                                     (0x1FFF0000&((data)<<16))
#define  H3DDMA_TG_v3_start_tg_vstart3(data)                                     (0x00001FFF&(data))
#define  H3DDMA_TG_v3_start_get_tg_hstart3(data)                                 ((0x1FFF0000&(data))>>16)
#define  H3DDMA_TG_v3_start_get_tg_vstart3(data)                                 (0x00001FFF&(data))

#define  H3DDMA_TG_v3_end                                                        0x1802584C
#define  H3DDMA_TG_v3_end_reg_addr                                               "0xB802584C"
#define  H3DDMA_TG_v3_end_reg                                                    0xB802584C
#define  H3DDMA_TG_v3_end_inst_addr                                              "0x0013"
#define  set_H3DDMA_TG_v3_end_reg(data)                                          (*((volatile unsigned int*)H3DDMA_TG_v3_end_reg)=data)
#define  get_H3DDMA_TG_v3_end_reg                                                (*((volatile unsigned int*)H3DDMA_TG_v3_end_reg))
#define  H3DDMA_TG_v3_end_tg_hend3_shift                                         (16)
#define  H3DDMA_TG_v3_end_tg_vend3_shift                                         (0)
#define  H3DDMA_TG_v3_end_tg_hend3_mask                                          (0x1FFF0000)
#define  H3DDMA_TG_v3_end_tg_vend3_mask                                          (0x00001FFF)
#define  H3DDMA_TG_v3_end_tg_hend3(data)                                         (0x1FFF0000&((data)<<16))
#define  H3DDMA_TG_v3_end_tg_vend3(data)                                         (0x00001FFF&(data))
#define  H3DDMA_TG_v3_end_get_tg_hend3(data)                                     ((0x1FFF0000&(data))>>16)
#define  H3DDMA_TG_v3_end_get_tg_vend3(data)                                     (0x00001FFF&(data))

#define  H3DDMA_TG_v4_start                                                      0x18025850
#define  H3DDMA_TG_v4_start_reg_addr                                             "0xB8025850"
#define  H3DDMA_TG_v4_start_reg                                                  0xB8025850
#define  H3DDMA_TG_v4_start_inst_addr                                            "0x0014"
#define  set_H3DDMA_TG_v4_start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_TG_v4_start_reg)=data)
#define  get_H3DDMA_TG_v4_start_reg                                              (*((volatile unsigned int*)H3DDMA_TG_v4_start_reg))
#define  H3DDMA_TG_v4_start_tg_hstart4_shift                                     (16)
#define  H3DDMA_TG_v4_start_tg_vstart4_shift                                     (0)
#define  H3DDMA_TG_v4_start_tg_hstart4_mask                                      (0x1FFF0000)
#define  H3DDMA_TG_v4_start_tg_vstart4_mask                                      (0x00001FFF)
#define  H3DDMA_TG_v4_start_tg_hstart4(data)                                     (0x1FFF0000&((data)<<16))
#define  H3DDMA_TG_v4_start_tg_vstart4(data)                                     (0x00001FFF&(data))
#define  H3DDMA_TG_v4_start_get_tg_hstart4(data)                                 ((0x1FFF0000&(data))>>16)
#define  H3DDMA_TG_v4_start_get_tg_vstart4(data)                                 (0x00001FFF&(data))

#define  H3DDMA_TG_v4_end                                                        0x18025854
#define  H3DDMA_TG_v4_end_reg_addr                                               "0xB8025854"
#define  H3DDMA_TG_v4_end_reg                                                    0xB8025854
#define  H3DDMA_TG_v4_end_inst_addr                                              "0x0015"
#define  set_H3DDMA_TG_v4_end_reg(data)                                          (*((volatile unsigned int*)H3DDMA_TG_v4_end_reg)=data)
#define  get_H3DDMA_TG_v4_end_reg                                                (*((volatile unsigned int*)H3DDMA_TG_v4_end_reg))
#define  H3DDMA_TG_v4_end_tg_hend4_shift                                         (16)
#define  H3DDMA_TG_v4_end_tg_vend4_shift                                         (0)
#define  H3DDMA_TG_v4_end_tg_hend4_mask                                          (0x1FFF0000)
#define  H3DDMA_TG_v4_end_tg_vend4_mask                                          (0x00001FFF)
#define  H3DDMA_TG_v4_end_tg_hend4(data)                                         (0x1FFF0000&((data)<<16))
#define  H3DDMA_TG_v4_end_tg_vend4(data)                                         (0x00001FFF&(data))
#define  H3DDMA_TG_v4_end_get_tg_hend4(data)                                     ((0x1FFF0000&(data))>>16)
#define  H3DDMA_TG_v4_end_get_tg_vend4(data)                                     (0x00001FFF&(data))

#define  H3DDMA_CTS_FIFO_CTRL                                                    0x1802585C
#define  H3DDMA_CTS_FIFO_CTRL_reg_addr                                           "0xB802585C"
#define  H3DDMA_CTS_FIFO_CTRL_reg                                                0xB802585C
#define  H3DDMA_CTS_FIFO_CTRL_inst_addr                                          "0x0016"
#define  set_H3DDMA_CTS_FIFO_CTRL_reg(data)                                      (*((volatile unsigned int*)H3DDMA_CTS_FIFO_CTRL_reg)=data)
#define  get_H3DDMA_CTS_FIFO_CTRL_reg                                            (*((volatile unsigned int*)H3DDMA_CTS_FIFO_CTRL_reg))
#define  H3DDMA_CTS_FIFO_CTRL_dummy_cts_fifo_shift                               (8)
#define  H3DDMA_CTS_FIFO_CTRL_force_ctsfifo_rstn_shift                           (2)
#define  H3DDMA_CTS_FIFO_CTRL_en_ctsfifo_vsrst_shift                             (1)
#define  H3DDMA_CTS_FIFO_CTRL_en_ctsfifo_bypass_shift                            (0)
#define  H3DDMA_CTS_FIFO_CTRL_dummy_cts_fifo_mask                                (0xFFFFFF00)
#define  H3DDMA_CTS_FIFO_CTRL_force_ctsfifo_rstn_mask                            (0x00000004)
#define  H3DDMA_CTS_FIFO_CTRL_en_ctsfifo_vsrst_mask                              (0x00000002)
#define  H3DDMA_CTS_FIFO_CTRL_en_ctsfifo_bypass_mask                             (0x00000001)
#define  H3DDMA_CTS_FIFO_CTRL_dummy_cts_fifo(data)                               (0xFFFFFF00&((data)<<8))
#define  H3DDMA_CTS_FIFO_CTRL_force_ctsfifo_rstn(data)                           (0x00000004&((data)<<2))
#define  H3DDMA_CTS_FIFO_CTRL_en_ctsfifo_vsrst(data)                             (0x00000002&((data)<<1))
#define  H3DDMA_CTS_FIFO_CTRL_en_ctsfifo_bypass(data)                            (0x00000001&(data))
#define  H3DDMA_CTS_FIFO_CTRL_get_dummy_cts_fifo(data)                           ((0xFFFFFF00&(data))>>8)
#define  H3DDMA_CTS_FIFO_CTRL_get_force_ctsfifo_rstn(data)                       ((0x00000004&(data))>>2)
#define  H3DDMA_CTS_FIFO_CTRL_get_en_ctsfifo_vsrst(data)                         ((0x00000002&(data))>>1)
#define  H3DDMA_CTS_FIFO_CTRL_get_en_ctsfifo_bypass(data)                        (0x00000001&(data))

#define  H3DDMA_LR_CRC_CTRL                                                      0x18025860
#define  H3DDMA_LR_CRC_CTRL_reg_addr                                             "0xB8025860"
#define  H3DDMA_LR_CRC_CTRL_reg                                                  0xB8025860
#define  H3DDMA_LR_CRC_CTRL_inst_addr                                            "0x0017"
#define  set_H3DDMA_LR_CRC_CTRL_reg(data)                                        (*((volatile unsigned int*)H3DDMA_LR_CRC_CTRL_reg)=data)
#define  get_H3DDMA_LR_CRC_CTRL_reg                                              (*((volatile unsigned int*)H3DDMA_LR_CRC_CTRL_reg))
#define  H3DDMA_LR_CRC_CTRL_r_crc_conti_shift                                    (9)
#define  H3DDMA_LR_CRC_CTRL_r_crc_start_shift                                    (8)
#define  H3DDMA_LR_CRC_CTRL_l_crc_conti_shift                                    (1)
#define  H3DDMA_LR_CRC_CTRL_l_crc_start_shift                                    (0)
#define  H3DDMA_LR_CRC_CTRL_r_crc_conti_mask                                     (0x00000200)
#define  H3DDMA_LR_CRC_CTRL_r_crc_start_mask                                     (0x00000100)
#define  H3DDMA_LR_CRC_CTRL_l_crc_conti_mask                                     (0x00000002)
#define  H3DDMA_LR_CRC_CTRL_l_crc_start_mask                                     (0x00000001)
#define  H3DDMA_LR_CRC_CTRL_r_crc_conti(data)                                    (0x00000200&((data)<<9))
#define  H3DDMA_LR_CRC_CTRL_r_crc_start(data)                                    (0x00000100&((data)<<8))
#define  H3DDMA_LR_CRC_CTRL_l_crc_conti(data)                                    (0x00000002&((data)<<1))
#define  H3DDMA_LR_CRC_CTRL_l_crc_start(data)                                    (0x00000001&(data))
#define  H3DDMA_LR_CRC_CTRL_get_r_crc_conti(data)                                ((0x00000200&(data))>>9)
#define  H3DDMA_LR_CRC_CTRL_get_r_crc_start(data)                                ((0x00000100&(data))>>8)
#define  H3DDMA_LR_CRC_CTRL_get_l_crc_conti(data)                                ((0x00000002&(data))>>1)
#define  H3DDMA_LR_CRC_CTRL_get_l_crc_start(data)                                (0x00000001&(data))

#define  H3DDMA_CRC_L_Result                                                     0x18025864
#define  H3DDMA_CRC_L_Result_reg_addr                                            "0xB8025864"
#define  H3DDMA_CRC_L_Result_reg                                                 0xB8025864
#define  H3DDMA_CRC_L_Result_inst_addr                                           "0x0018"
#define  set_H3DDMA_CRC_L_Result_reg(data)                                       (*((volatile unsigned int*)H3DDMA_CRC_L_Result_reg)=data)
#define  get_H3DDMA_CRC_L_Result_reg                                             (*((volatile unsigned int*)H3DDMA_CRC_L_Result_reg))
#define  H3DDMA_CRC_L_Result_crc_l_result_shift                                  (0)
#define  H3DDMA_CRC_L_Result_crc_l_result_mask                                   (0xFFFFFFFF)
#define  H3DDMA_CRC_L_Result_crc_l_result(data)                                  (0xFFFFFFFF&(data))
#define  H3DDMA_CRC_L_Result_get_crc_l_result(data)                              (0xFFFFFFFF&(data))

#define  H3DDMA_CRC_R_Result                                                     0x18025868
#define  H3DDMA_CRC_R_Result_reg_addr                                            "0xB8025868"
#define  H3DDMA_CRC_R_Result_reg                                                 0xB8025868
#define  H3DDMA_CRC_R_Result_inst_addr                                           "0x0019"
#define  set_H3DDMA_CRC_R_Result_reg(data)                                       (*((volatile unsigned int*)H3DDMA_CRC_R_Result_reg)=data)
#define  get_H3DDMA_CRC_R_Result_reg                                             (*((volatile unsigned int*)H3DDMA_CRC_R_Result_reg))
#define  H3DDMA_CRC_R_Result_crc_r_result_shift                                  (0)
#define  H3DDMA_CRC_R_Result_crc_r_result_mask                                   (0xFFFFFFFF)
#define  H3DDMA_CRC_R_Result_crc_r_result(data)                                  (0xFFFFFFFF&(data))
#define  H3DDMA_CRC_R_Result_get_crc_r_result(data)                              (0xFFFFFFFF&(data))

#define  H3DDMA_Interrupt_Enable                                                 0x1802586C
#define  H3DDMA_Interrupt_Enable_reg_addr                                        "0xB802586C"
#define  H3DDMA_Interrupt_Enable_reg                                             0xB802586C
#define  H3DDMA_Interrupt_Enable_inst_addr                                       "0x001A"
#define  set_H3DDMA_Interrupt_Enable_reg(data)                                   (*((volatile unsigned int*)H3DDMA_Interrupt_Enable_reg)=data)
#define  get_H3DDMA_Interrupt_Enable_reg                                         (*((volatile unsigned int*)H3DDMA_Interrupt_Enable_reg))
#define  H3DDMA_Interrupt_Enable_cap2_last_wrt_ie_shift                          (4)
#define  H3DDMA_Interrupt_Enable_cap_last_wrt_ie_shift                           (3)
#define  H3DDMA_Interrupt_Enable_mem_err_ie_shift                                (2)
#define  H3DDMA_Interrupt_Enable_fifo_err_ie_shift                               (1)
#define  H3DDMA_Interrupt_Enable_vs_rising_ie_shift                              (0)
#define  H3DDMA_Interrupt_Enable_cap2_last_wrt_ie_mask                           (0x00000010)
#define  H3DDMA_Interrupt_Enable_cap_last_wrt_ie_mask                            (0x00000008)
#define  H3DDMA_Interrupt_Enable_mem_err_ie_mask                                 (0x00000004)
#define  H3DDMA_Interrupt_Enable_fifo_err_ie_mask                                (0x00000002)
#define  H3DDMA_Interrupt_Enable_vs_rising_ie_mask                               (0x00000001)
#define  H3DDMA_Interrupt_Enable_cap2_last_wrt_ie(data)                          (0x00000010&((data)<<4))
#define  H3DDMA_Interrupt_Enable_cap_last_wrt_ie(data)                           (0x00000008&((data)<<3))
#define  H3DDMA_Interrupt_Enable_mem_err_ie(data)                                (0x00000004&((data)<<2))
#define  H3DDMA_Interrupt_Enable_fifo_err_ie(data)                               (0x00000002&((data)<<1))
#define  H3DDMA_Interrupt_Enable_vs_rising_ie(data)                              (0x00000001&(data))
#define  H3DDMA_Interrupt_Enable_get_cap2_last_wrt_ie(data)                      ((0x00000010&(data))>>4)
#define  H3DDMA_Interrupt_Enable_get_cap_last_wrt_ie(data)                       ((0x00000008&(data))>>3)
#define  H3DDMA_Interrupt_Enable_get_mem_err_ie(data)                            ((0x00000004&(data))>>2)
#define  H3DDMA_Interrupt_Enable_get_fifo_err_ie(data)                           ((0x00000002&(data))>>1)
#define  H3DDMA_Interrupt_Enable_get_vs_rising_ie(data)                          (0x00000001&(data))

#define  H3DDMA_I3DDMA_enable                                                    0x18025870
#define  H3DDMA_I3DDMA_enable_reg_addr                                           "0xB8025870"
#define  H3DDMA_I3DDMA_enable_reg                                                0xB8025870
#define  H3DDMA_I3DDMA_enable_inst_addr                                          "0x001B"
#define  set_H3DDMA_I3DDMA_enable_reg(data)                                      (*((volatile unsigned int*)H3DDMA_I3DDMA_enable_reg)=data)
#define  get_H3DDMA_I3DDMA_enable_reg                                            (*((volatile unsigned int*)H3DDMA_I3DDMA_enable_reg))
#define  H3DDMA_I3DDMA_enable_frc_style_shift                                    (4)
#define  H3DDMA_I3DDMA_enable_frc_en_shift                                       (3)
#define  H3DDMA_I3DDMA_enable_tg_en_shift                                        (2)
#define  H3DDMA_I3DDMA_enable_lr_separate_en_shift                               (1)
#define  H3DDMA_I3DDMA_enable_cap_en_shift                                       (0)
#define  H3DDMA_I3DDMA_enable_frc_style_mask                                     (0x00000010)
#define  H3DDMA_I3DDMA_enable_frc_en_mask                                        (0x00000008)
#define  H3DDMA_I3DDMA_enable_tg_en_mask                                         (0x00000004)
#define  H3DDMA_I3DDMA_enable_lr_separate_en_mask                                (0x00000002)
#define  H3DDMA_I3DDMA_enable_cap_en_mask                                        (0x00000001)
#define  H3DDMA_I3DDMA_enable_frc_style(data)                                    (0x00000010&((data)<<4))
#define  H3DDMA_I3DDMA_enable_frc_en(data)                                       (0x00000008&((data)<<3))
#define  H3DDMA_I3DDMA_enable_tg_en(data)                                        (0x00000004&((data)<<2))
#define  H3DDMA_I3DDMA_enable_lr_separate_en(data)                               (0x00000002&((data)<<1))
#define  H3DDMA_I3DDMA_enable_cap_en(data)                                       (0x00000001&(data))
#define  H3DDMA_I3DDMA_enable_get_frc_style(data)                                ((0x00000010&(data))>>4)
#define  H3DDMA_I3DDMA_enable_get_frc_en(data)                                   ((0x00000008&(data))>>3)
#define  H3DDMA_I3DDMA_enable_get_tg_en(data)                                    ((0x00000004&(data))>>2)
#define  H3DDMA_I3DDMA_enable_get_lr_separate_en(data)                           ((0x00000002&(data))>>1)
#define  H3DDMA_I3DDMA_enable_get_cap_en(data)                                   (0x00000001&(data))

#define  H3DDMA_I3DDMA_byte_channel_swap                                         0x18025874
#define  H3DDMA_I3DDMA_byte_channel_swap_reg_addr                                "0xB8025874"
#define  H3DDMA_I3DDMA_byte_channel_swap_reg                                     0xB8025874
#define  H3DDMA_I3DDMA_byte_channel_swap_inst_addr                               "0x001C"
#define  set_H3DDMA_I3DDMA_byte_channel_swap_reg(data)                           (*((volatile unsigned int*)H3DDMA_I3DDMA_byte_channel_swap_reg)=data)
#define  get_H3DDMA_I3DDMA_byte_channel_swap_reg                                 (*((volatile unsigned int*)H3DDMA_I3DDMA_byte_channel_swap_reg))
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_channel_swap_shift                  (4)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap_shift                    (3)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_4byte_swap_shift                    (2)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_2byte_swap_shift                    (1)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_1byte_swap_shift                    (0)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_channel_swap_mask                   (0x00000070)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap_mask                     (0x00000008)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_4byte_swap_mask                     (0x00000004)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_2byte_swap_mask                     (0x00000002)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_1byte_swap_mask                     (0x00000001)
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_channel_swap(data)                  (0x00000070&((data)<<4))
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_8byte_swap(data)                    (0x00000008&((data)<<3))
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_4byte_swap(data)                    (0x00000004&((data)<<2))
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_2byte_swap(data)                    (0x00000002&((data)<<1))
#define  H3DDMA_I3DDMA_byte_channel_swap_dma_1byte_swap(data)                    (0x00000001&(data))
#define  H3DDMA_I3DDMA_byte_channel_swap_get_dma_channel_swap(data)              ((0x00000070&(data))>>4)
#define  H3DDMA_I3DDMA_byte_channel_swap_get_dma_8byte_swap(data)                ((0x00000008&(data))>>3)
#define  H3DDMA_I3DDMA_byte_channel_swap_get_dma_4byte_swap(data)                ((0x00000004&(data))>>2)
#define  H3DDMA_I3DDMA_byte_channel_swap_get_dma_2byte_swap(data)                ((0x00000002&(data))>>1)
#define  H3DDMA_I3DDMA_byte_channel_swap_get_dma_1byte_swap(data)                (0x00000001&(data))

#define  H3DDMA_Cap_L1_Start_db_2                                                0x18025878
#define  H3DDMA_Cap_L1_Start_db_2_reg_addr                                       "0xB8025878"
#define  H3DDMA_Cap_L1_Start_db_2_reg                                            0xB8025878
#define  H3DDMA_Cap_L1_Start_db_2_inst_addr                                      "0x001D"
#define  set_H3DDMA_Cap_L1_Start_db_2_reg(data)                                  (*((volatile unsigned int*)H3DDMA_Cap_L1_Start_db_2_reg)=data)
#define  get_H3DDMA_Cap_L1_Start_db_2_reg                                        (*((volatile unsigned int*)H3DDMA_Cap_L1_Start_db_2_reg))
#define  H3DDMA_Cap_L1_Start_db_2_cap2_l1_start_db_shift                         (3)
#define  H3DDMA_Cap_L1_Start_db_2_cap2_l1_start_db_mask                          (0xFFFFFFF8)
#define  H3DDMA_Cap_L1_Start_db_2_cap2_l1_start_db(data)                         (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_L1_Start_db_2_get_cap2_l1_start_db(data)                     ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_R1_Start_db_2                                                0x1802587C
#define  H3DDMA_Cap_R1_Start_db_2_reg_addr                                       "0xB802587C"
#define  H3DDMA_Cap_R1_Start_db_2_reg                                            0xB802587C
#define  H3DDMA_Cap_R1_Start_db_2_inst_addr                                      "0x001E"
#define  set_H3DDMA_Cap_R1_Start_db_2_reg(data)                                  (*((volatile unsigned int*)H3DDMA_Cap_R1_Start_db_2_reg)=data)
#define  get_H3DDMA_Cap_R1_Start_db_2_reg                                        (*((volatile unsigned int*)H3DDMA_Cap_R1_Start_db_2_reg))
#define  H3DDMA_Cap_R1_Start_db_2_cap2_r1_start_db_shift                         (3)
#define  H3DDMA_Cap_R1_Start_db_2_cap2_r1_start_db_mask                          (0xFFFFFFF8)
#define  H3DDMA_Cap_R1_Start_db_2_cap2_r1_start_db(data)                         (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_R1_Start_db_2_get_cap2_r1_start_db(data)                     ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_Status_2                                                     0x18025880
#define  H3DDMA_Cap_Status_2_reg_addr                                            "0xB8025880"
#define  H3DDMA_Cap_Status_2_reg                                                 0xB8025880
#define  H3DDMA_Cap_Status_2_inst_addr                                           "0x001F"
#define  set_H3DDMA_Cap_Status_2_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_Status_2_reg)=data)
#define  get_H3DDMA_Cap_Status_2_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_Status_2_reg))
#define  H3DDMA_Cap_Status_2_cap2_block_shift                                    (6)
#define  H3DDMA_Cap_Status_2_cap2_fifo_full_shift                                (4)
#define  H3DDMA_Cap_Status_2_cap2_fifo_empty_shift                               (3)
#define  H3DDMA_Cap_Status_2_cap2_fifo_overflow_shift                            (2)
#define  H3DDMA_Cap_Status_2_cap2_fifo_underflow_shift                           (1)
#define  H3DDMA_Cap_Status_2_cap2_ddr_over_range_shift                           (0)
#define  H3DDMA_Cap_Status_2_cap2_block_mask                                     (0x00000040)
#define  H3DDMA_Cap_Status_2_cap2_fifo_full_mask                                 (0x00000010)
#define  H3DDMA_Cap_Status_2_cap2_fifo_empty_mask                                (0x00000008)
#define  H3DDMA_Cap_Status_2_cap2_fifo_overflow_mask                             (0x00000004)
#define  H3DDMA_Cap_Status_2_cap2_fifo_underflow_mask                            (0x00000002)
#define  H3DDMA_Cap_Status_2_cap2_ddr_over_range_mask                            (0x00000001)
#define  H3DDMA_Cap_Status_2_cap2_block(data)                                    (0x00000040&((data)<<6))
#define  H3DDMA_Cap_Status_2_cap2_fifo_full(data)                                (0x00000010&((data)<<4))
#define  H3DDMA_Cap_Status_2_cap2_fifo_empty(data)                               (0x00000008&((data)<<3))
#define  H3DDMA_Cap_Status_2_cap2_fifo_overflow(data)                            (0x00000004&((data)<<2))
#define  H3DDMA_Cap_Status_2_cap2_fifo_underflow(data)                           (0x00000002&((data)<<1))
#define  H3DDMA_Cap_Status_2_cap2_ddr_over_range(data)                           (0x00000001&(data))
#define  H3DDMA_Cap_Status_2_get_cap2_block(data)                                ((0x00000040&(data))>>6)
#define  H3DDMA_Cap_Status_2_get_cap2_fifo_full(data)                            ((0x00000010&(data))>>4)
#define  H3DDMA_Cap_Status_2_get_cap2_fifo_empty(data)                           ((0x00000008&(data))>>3)
#define  H3DDMA_Cap_Status_2_get_cap2_fifo_overflow(data)                        ((0x00000004&(data))>>2)
#define  H3DDMA_Cap_Status_2_get_cap2_fifo_underflow(data)                       ((0x00000002&(data))>>1)
#define  H3DDMA_Cap_Status_2_get_cap2_ddr_over_range(data)                       (0x00000001&(data))

#define  H3DDMA_Cap_L3_Start                                                     0x18025884
#define  H3DDMA_Cap_L3_Start_reg_addr                                            "0xB8025884"
#define  H3DDMA_Cap_L3_Start_reg                                                 0xB8025884
#define  H3DDMA_Cap_L3_Start_inst_addr                                           "0x0020"
#define  set_H3DDMA_Cap_L3_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_L3_Start_reg)=data)
#define  get_H3DDMA_Cap_L3_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_L3_Start_reg))
#define  H3DDMA_Cap_L3_Start_cap_l3_start_shift                                  (3)
#define  H3DDMA_Cap_L3_Start_cap_l3_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_L3_Start_cap_l3_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_L3_Start_get_cap_l3_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_R3_Start                                                     0x18025888
#define  H3DDMA_Cap_R3_Start_reg_addr                                            "0xB8025888"
#define  H3DDMA_Cap_R3_Start_reg                                                 0xB8025888
#define  H3DDMA_Cap_R3_Start_inst_addr                                           "0x0021"
#define  set_H3DDMA_Cap_R3_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_R3_Start_reg)=data)
#define  get_H3DDMA_Cap_R3_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_R3_Start_reg))
#define  H3DDMA_Cap_R3_Start_cap_r3_start_shift                                  (3)
#define  H3DDMA_Cap_R3_Start_cap_r3_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_R3_Start_cap_r3_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_R3_Start_get_cap_r3_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_L4_Start                                                     0x1802588C
#define  H3DDMA_Cap_L4_Start_reg_addr                                            "0xB802588C"
#define  H3DDMA_Cap_L4_Start_reg                                                 0xB802588C
#define  H3DDMA_Cap_L4_Start_inst_addr                                           "0x0022"
#define  set_H3DDMA_Cap_L4_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_L4_Start_reg)=data)
#define  get_H3DDMA_Cap_L4_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_L4_Start_reg))
#define  H3DDMA_Cap_L4_Start_cap_l4_start_shift                                  (3)
#define  H3DDMA_Cap_L4_Start_cap_l4_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_L4_Start_cap_l4_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_L4_Start_get_cap_l4_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_R4_Start                                                     0x18025890
#define  H3DDMA_Cap_R4_Start_reg_addr                                            "0xB8025890"
#define  H3DDMA_Cap_R4_Start_reg                                                 0xB8025890
#define  H3DDMA_Cap_R4_Start_inst_addr                                           "0x0023"
#define  set_H3DDMA_Cap_R4_Start_reg(data)                                       (*((volatile unsigned int*)H3DDMA_Cap_R4_Start_reg)=data)
#define  get_H3DDMA_Cap_R4_Start_reg                                             (*((volatile unsigned int*)H3DDMA_Cap_R4_Start_reg))
#define  H3DDMA_Cap_R4_Start_cap_r4_start_shift                                  (3)
#define  H3DDMA_Cap_R4_Start_cap_r4_start_mask                                   (0xFFFFFFF8)
#define  H3DDMA_Cap_R4_Start_cap_r4_start(data)                                  (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_Cap_R4_Start_get_cap_r4_start(data)                              ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_Cap_CTL2                                                         0x18025894
#define  H3DDMA_Cap_CTL2_reg_addr                                                "0xB8025894"
#define  H3DDMA_Cap_CTL2_reg                                                     0xB8025894
#define  H3DDMA_Cap_CTL2_inst_addr                                               "0x0024"
#define  set_H3DDMA_Cap_CTL2_reg(data)                                           (*((volatile unsigned int*)H3DDMA_Cap_CTL2_reg)=data)
#define  get_H3DDMA_Cap_CTL2_reg                                                 (*((volatile unsigned int*)H3DDMA_Cap_CTL2_reg))
#define  H3DDMA_Cap_CTL2_md_parser_en_shift                                      (31)
#define  H3DDMA_Cap_CTL2_cap2_write_len_shift                                    (24)
#define  H3DDMA_Cap_CTL2_cap2_write_rem_shift                                    (16)
#define  H3DDMA_Cap_CTL2_cap2_dcu_sel_shift                                      (15)
#define  H3DDMA_Cap_CTL2_cap2_water_lv_shift                                     (8)
#define  H3DDMA_Cap_CTL2_cap2_write_num_shift                                    (0)
#define  H3DDMA_Cap_CTL2_md_parser_en_mask                                       (0x80000000)
#define  H3DDMA_Cap_CTL2_cap2_write_len_mask                                     (0x7F000000)
#define  H3DDMA_Cap_CTL2_cap2_write_rem_mask                                     (0x007F0000)
#define  H3DDMA_Cap_CTL2_cap2_dcu_sel_mask                                       (0x00008000)
#define  H3DDMA_Cap_CTL2_cap2_water_lv_mask                                      (0x00007F00)
#define  H3DDMA_Cap_CTL2_cap2_write_num_mask                                     (0x000000FF)
#define  H3DDMA_Cap_CTL2_md_parser_en(data)                                      (0x80000000&((data)<<31))
#define  H3DDMA_Cap_CTL2_cap2_write_len(data)                                    (0x7F000000&((data)<<24))
#define  H3DDMA_Cap_CTL2_cap2_write_rem(data)                                    (0x007F0000&((data)<<16))
#define  H3DDMA_Cap_CTL2_cap2_dcu_sel(data)                                      (0x00008000&((data)<<15))
#define  H3DDMA_Cap_CTL2_cap2_water_lv(data)                                     (0x00007F00&((data)<<8))
#define  H3DDMA_Cap_CTL2_cap2_write_num(data)                                    (0x000000FF&(data))
#define  H3DDMA_Cap_CTL2_get_md_parser_en(data)                                  ((0x80000000&(data))>>31)
#define  H3DDMA_Cap_CTL2_get_cap2_write_len(data)                                ((0x7F000000&(data))>>24)
#define  H3DDMA_Cap_CTL2_get_cap2_write_rem(data)                                ((0x007F0000&(data))>>16)
#define  H3DDMA_Cap_CTL2_get_cap2_dcu_sel(data)                                  ((0x00008000&(data))>>15)
#define  H3DDMA_Cap_CTL2_get_cap2_water_lv(data)                                 ((0x00007F00&(data))>>8)
#define  H3DDMA_Cap_CTL2_get_cap2_write_num(data)                                (0x000000FF&(data))

#define  H3DDMA_md_m1_Start                                                      0x18025898
#define  H3DDMA_md_m1_Start_reg_addr                                             "0xB8025898"
#define  H3DDMA_md_m1_Start_reg                                                  0xB8025898
#define  H3DDMA_md_m1_Start_inst_addr                                            "0x0025"
#define  set_H3DDMA_md_m1_Start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_md_m1_Start_reg)=data)
#define  get_H3DDMA_md_m1_Start_reg                                              (*((volatile unsigned int*)H3DDMA_md_m1_Start_reg))
#define  H3DDMA_md_m1_Start_md_m1_start_shift                                    (3)
#define  H3DDMA_md_m1_Start_md_m1_start_mask                                     (0xFFFFFFF8)
#define  H3DDMA_md_m1_Start_md_m1_start(data)                                    (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_md_m1_Start_get_md_m1_start(data)                                ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_md_m2_Start                                                      0x1802589C
#define  H3DDMA_md_m2_Start_reg_addr                                             "0xB802589C"
#define  H3DDMA_md_m2_Start_reg                                                  0xB802589C
#define  H3DDMA_md_m2_Start_inst_addr                                            "0x0026"
#define  set_H3DDMA_md_m2_Start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_md_m2_Start_reg)=data)
#define  get_H3DDMA_md_m2_Start_reg                                              (*((volatile unsigned int*)H3DDMA_md_m2_Start_reg))
#define  H3DDMA_md_m2_Start_md_m2_start_shift                                    (3)
#define  H3DDMA_md_m2_Start_md_m2_start_mask                                     (0xFFFFFFF8)
#define  H3DDMA_md_m2_Start_md_m2_start(data)                                    (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_md_m2_Start_get_md_m2_start(data)                                ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_md_m3_Start                                                      0x180258A0
#define  H3DDMA_md_m3_Start_reg_addr                                             "0xB80258A0"
#define  H3DDMA_md_m3_Start_reg                                                  0xB80258A0
#define  H3DDMA_md_m3_Start_inst_addr                                            "0x0027"
#define  set_H3DDMA_md_m3_Start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_md_m3_Start_reg)=data)
#define  get_H3DDMA_md_m3_Start_reg                                              (*((volatile unsigned int*)H3DDMA_md_m3_Start_reg))
#define  H3DDMA_md_m3_Start_md_m3_start_shift                                    (3)
#define  H3DDMA_md_m3_Start_md_m3_start_mask                                     (0xFFFFFFF8)
#define  H3DDMA_md_m3_Start_md_m3_start(data)                                    (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_md_m3_Start_get_md_m3_start(data)                                ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_md_m4_Start                                                      0x180258A4
#define  H3DDMA_md_m4_Start_reg_addr                                             "0xB80258A4"
#define  H3DDMA_md_m4_Start_reg                                                  0xB80258A4
#define  H3DDMA_md_m4_Start_inst_addr                                            "0x0028"
#define  set_H3DDMA_md_m4_Start_reg(data)                                        (*((volatile unsigned int*)H3DDMA_md_m4_Start_reg)=data)
#define  get_H3DDMA_md_m4_Start_reg                                              (*((volatile unsigned int*)H3DDMA_md_m4_Start_reg))
#define  H3DDMA_md_m4_Start_md_m4_start_shift                                    (3)
#define  H3DDMA_md_m4_Start_md_m4_start_mask                                     (0xFFFFFFF8)
#define  H3DDMA_md_m4_Start_md_m4_start(data)                                    (0xFFFFFFF8&((data)<<3))
#define  H3DDMA_md_m4_Start_get_md_m4_start(data)                                ((0xFFFFFFF8&(data))>>3)

#define  H3DDMA_I3DDMA_MDP_CR                                                    0x180258A8
#define  H3DDMA_I3DDMA_MDP_CR_reg_addr                                           "0xB80258A8"
#define  H3DDMA_I3DDMA_MDP_CR_reg                                                0xB80258A8
#define  H3DDMA_I3DDMA_MDP_CR_inst_addr                                          "0x0029"
#define  set_H3DDMA_I3DDMA_MDP_CR_reg(data)                                      (*((volatile unsigned int*)H3DDMA_I3DDMA_MDP_CR_reg)=data)
#define  get_H3DDMA_I3DDMA_MDP_CR_reg                                            (*((volatile unsigned int*)H3DDMA_I3DDMA_MDP_CR_reg))
#define  H3DDMA_I3DDMA_MDP_CR_max_packet_num_shift                               (8)
#define  H3DDMA_I3DDMA_MDP_CR_dummy_7_5_shift                                    (5)
#define  H3DDMA_I3DDMA_MDP_CR_dummy_4_shift                                      (4)
#define  H3DDMA_I3DDMA_MDP_CR_dummy_3_shift                                      (3)
#define  H3DDMA_I3DDMA_MDP_CR_mode_shift                                         (1)
#define  H3DDMA_I3DDMA_MDP_CR_en_shift                                           (0)
#define  H3DDMA_I3DDMA_MDP_CR_max_packet_num_mask                                (0x0001FF00)
#define  H3DDMA_I3DDMA_MDP_CR_dummy_7_5_mask                                     (0x000000E0)
#define  H3DDMA_I3DDMA_MDP_CR_dummy_4_mask                                       (0x00000010)
#define  H3DDMA_I3DDMA_MDP_CR_dummy_3_mask                                       (0x00000008)
#define  H3DDMA_I3DDMA_MDP_CR_mode_mask                                          (0x00000006)
#define  H3DDMA_I3DDMA_MDP_CR_en_mask                                            (0x00000001)
#define  H3DDMA_I3DDMA_MDP_CR_max_packet_num(data)                               (0x0001FF00&((data)<<8))
#define  H3DDMA_I3DDMA_MDP_CR_dummy_7_5(data)                                    (0x000000E0&((data)<<5))
#define  H3DDMA_I3DDMA_MDP_CR_dummy_4(data)                                      (0x00000010&((data)<<4))
#define  H3DDMA_I3DDMA_MDP_CR_dummy_3(data)                                      (0x00000008&((data)<<3))
#define  H3DDMA_I3DDMA_MDP_CR_mode(data)                                         (0x00000006&((data)<<1))
#define  H3DDMA_I3DDMA_MDP_CR_en(data)                                           (0x00000001&(data))
#define  H3DDMA_I3DDMA_MDP_CR_get_max_packet_num(data)                           ((0x0001FF00&(data))>>8)
#define  H3DDMA_I3DDMA_MDP_CR_get_dummy_7_5(data)                                ((0x000000E0&(data))>>5)
#define  H3DDMA_I3DDMA_MDP_CR_get_dummy_4(data)                                  ((0x00000010&(data))>>4)
#define  H3DDMA_I3DDMA_MDP_CR_get_dummy_3(data)                                  ((0x00000008&(data))>>3)
#define  H3DDMA_I3DDMA_MDP_CR_get_mode(data)                                     ((0x00000006&(data))>>1)
#define  H3DDMA_I3DDMA_MDP_CR_get_en(data)                                       (0x00000001&(data))

#define  H3DDMA_cap2_byte_swap                                                   0x180258AC
#define  H3DDMA_cap2_byte_swap_reg_addr                                          "0xB80258AC"
#define  H3DDMA_cap2_byte_swap_reg                                               0xB80258AC
#define  H3DDMA_cap2_byte_swap_inst_addr                                         "0x002A"
#define  set_H3DDMA_cap2_byte_swap_reg(data)                                     (*((volatile unsigned int*)H3DDMA_cap2_byte_swap_reg)=data)
#define  get_H3DDMA_cap2_byte_swap_reg                                           (*((volatile unsigned int*)H3DDMA_cap2_byte_swap_reg))
#define  H3DDMA_cap2_byte_swap_cap2_8byte_swap_shift                             (3)
#define  H3DDMA_cap2_byte_swap_cap2_4byte_swap_shift                             (2)
#define  H3DDMA_cap2_byte_swap_cap2_2byte_swap_shift                             (1)
#define  H3DDMA_cap2_byte_swap_cap2_1byte_swap_shift                             (0)
#define  H3DDMA_cap2_byte_swap_cap2_8byte_swap_mask                              (0x00000008)
#define  H3DDMA_cap2_byte_swap_cap2_4byte_swap_mask                              (0x00000004)
#define  H3DDMA_cap2_byte_swap_cap2_2byte_swap_mask                              (0x00000002)
#define  H3DDMA_cap2_byte_swap_cap2_1byte_swap_mask                              (0x00000001)
#define  H3DDMA_cap2_byte_swap_cap2_8byte_swap(data)                             (0x00000008&((data)<<3))
#define  H3DDMA_cap2_byte_swap_cap2_4byte_swap(data)                             (0x00000004&((data)<<2))
#define  H3DDMA_cap2_byte_swap_cap2_2byte_swap(data)                             (0x00000002&((data)<<1))
#define  H3DDMA_cap2_byte_swap_cap2_1byte_swap(data)                             (0x00000001&(data))
#define  H3DDMA_cap2_byte_swap_get_cap2_8byte_swap(data)                         ((0x00000008&(data))>>3)
#define  H3DDMA_cap2_byte_swap_get_cap2_4byte_swap(data)                         ((0x00000004&(data))>>2)
#define  H3DDMA_cap2_byte_swap_get_cap2_2byte_swap(data)                         ((0x00000002&(data))>>1)
#define  H3DDMA_cap2_byte_swap_get_cap2_1byte_swap(data)                         (0x00000001&(data))

#define  H3DDMA_I3DDMA_BIST_CAP_FAIL                                             0x180258D8
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_reg_addr                                    "0xB80258D8"
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_reg                                         0xB80258D8
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_inst_addr                                   "0x002B"
#define  set_H3DDMA_I3DDMA_BIST_CAP_FAIL_reg(data)                               (*((volatile unsigned int*)H3DDMA_I3DDMA_BIST_CAP_FAIL_reg)=data)
#define  get_H3DDMA_I3DDMA_BIST_CAP_FAIL_reg                                     (*((volatile unsigned int*)H3DDMA_I3DDMA_BIST_CAP_FAIL_reg))
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap2_fail_shift                 (1)
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap_fail_shift                  (0)
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap2_fail_mask                  (0x00000002)
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap_fail_mask                   (0x00000001)
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap2_fail(data)                 (0x00000002&((data)<<1))
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_i3ddma_bist_cap_fail(data)                  (0x00000001&(data))
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_get_i3ddma_bist_cap2_fail(data)             ((0x00000002&(data))>>1)
#define  H3DDMA_I3DDMA_BIST_CAP_FAIL_get_i3ddma_bist_cap_fail(data)              (0x00000001&(data))

#define  H3DDMA_I3DDMA_DRF_CAP_FAIL                                              0x180258EC
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_reg_addr                                     "0xB80258EC"
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_reg                                          0xB80258EC
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_inst_addr                                    "0x002C"
#define  set_H3DDMA_I3DDMA_DRF_CAP_FAIL_reg(data)                                (*((volatile unsigned int*)H3DDMA_I3DDMA_DRF_CAP_FAIL_reg)=data)
#define  get_H3DDMA_I3DDMA_DRF_CAP_FAIL_reg                                      (*((volatile unsigned int*)H3DDMA_I3DDMA_DRF_CAP_FAIL_reg))
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap2_fail_shift                   (1)
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap_fail_shift                    (0)
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap2_fail_mask                    (0x00000002)
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap_fail_mask                     (0x00000001)
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap2_fail(data)                   (0x00000002&((data)<<1))
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_i3ddma_drf_cap_fail(data)                    (0x00000001&(data))
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_get_i3ddma_drf_cap2_fail(data)               ((0x00000002&(data))>>1)
#define  H3DDMA_I3DDMA_DRF_CAP_FAIL_get_i3ddma_drf_cap_fail(data)                (0x00000001&(data))

#define  H3DDMA_I3DDMA_DVS                                                       0x180258F0
#define  H3DDMA_I3DDMA_DVS_reg_addr                                              "0xB80258F0"
#define  H3DDMA_I3DDMA_DVS_reg                                                   0xB80258F0
#define  H3DDMA_I3DDMA_DVS_inst_addr                                             "0x002D"
#define  set_H3DDMA_I3DDMA_DVS_reg(data)                                         (*((volatile unsigned int*)H3DDMA_I3DDMA_DVS_reg)=data)
#define  get_H3DDMA_I3DDMA_DVS_reg                                               (*((volatile unsigned int*)H3DDMA_I3DDMA_DVS_reg))
#define  H3DDMA_I3DDMA_DVS_cap2_dvsb_shift                                       (12)
#define  H3DDMA_I3DDMA_DVS_cap2_dvsa_shift                                       (8)
#define  H3DDMA_I3DDMA_DVS_cap_dvsb_shift                                        (4)
#define  H3DDMA_I3DDMA_DVS_cap_dvsa_shift                                        (0)
#define  H3DDMA_I3DDMA_DVS_cap2_dvsb_mask                                        (0x0000F000)
#define  H3DDMA_I3DDMA_DVS_cap2_dvsa_mask                                        (0x00000F00)
#define  H3DDMA_I3DDMA_DVS_cap_dvsb_mask                                         (0x000000F0)
#define  H3DDMA_I3DDMA_DVS_cap_dvsa_mask                                         (0x0000000F)
#define  H3DDMA_I3DDMA_DVS_cap2_dvsb(data)                                       (0x0000F000&((data)<<12))
#define  H3DDMA_I3DDMA_DVS_cap2_dvsa(data)                                       (0x00000F00&((data)<<8))
#define  H3DDMA_I3DDMA_DVS_cap_dvsb(data)                                        (0x000000F0&((data)<<4))
#define  H3DDMA_I3DDMA_DVS_cap_dvsa(data)                                        (0x0000000F&(data))
#define  H3DDMA_I3DDMA_DVS_get_cap2_dvsb(data)                                   ((0x0000F000&(data))>>12)
#define  H3DDMA_I3DDMA_DVS_get_cap2_dvsa(data)                                   ((0x00000F00&(data))>>8)
#define  H3DDMA_I3DDMA_DVS_get_cap_dvsb(data)                                    ((0x000000F0&(data))>>4)
#define  H3DDMA_I3DDMA_DVS_get_cap_dvsa(data)                                    (0x0000000F&(data))

#define  H3DDMA_I3DDMA_DVSE                                                      0x180258F4
#define  H3DDMA_I3DDMA_DVSE_reg_addr                                             "0xB80258F4"
#define  H3DDMA_I3DDMA_DVSE_reg                                                  0xB80258F4
#define  H3DDMA_I3DDMA_DVSE_inst_addr                                            "0x002E"
#define  set_H3DDMA_I3DDMA_DVSE_reg(data)                                        (*((volatile unsigned int*)H3DDMA_I3DDMA_DVSE_reg)=data)
#define  get_H3DDMA_I3DDMA_DVSE_reg                                              (*((volatile unsigned int*)H3DDMA_I3DDMA_DVSE_reg))
#define  H3DDMA_I3DDMA_DVSE_cap2_dvseb_shift                                     (3)
#define  H3DDMA_I3DDMA_DVSE_cap2_dvsea_shift                                     (2)
#define  H3DDMA_I3DDMA_DVSE_cap_dvseb_shift                                      (1)
#define  H3DDMA_I3DDMA_DVSE_cap_dvsea_shift                                      (0)
#define  H3DDMA_I3DDMA_DVSE_cap2_dvseb_mask                                      (0x00000008)
#define  H3DDMA_I3DDMA_DVSE_cap2_dvsea_mask                                      (0x00000004)
#define  H3DDMA_I3DDMA_DVSE_cap_dvseb_mask                                       (0x00000002)
#define  H3DDMA_I3DDMA_DVSE_cap_dvsea_mask                                       (0x00000001)
#define  H3DDMA_I3DDMA_DVSE_cap2_dvseb(data)                                     (0x00000008&((data)<<3))
#define  H3DDMA_I3DDMA_DVSE_cap2_dvsea(data)                                     (0x00000004&((data)<<2))
#define  H3DDMA_I3DDMA_DVSE_cap_dvseb(data)                                      (0x00000002&((data)<<1))
#define  H3DDMA_I3DDMA_DVSE_cap_dvsea(data)                                      (0x00000001&(data))
#define  H3DDMA_I3DDMA_DVSE_get_cap2_dvseb(data)                                 ((0x00000008&(data))>>3)
#define  H3DDMA_I3DDMA_DVSE_get_cap2_dvsea(data)                                 ((0x00000004&(data))>>2)
#define  H3DDMA_I3DDMA_DVSE_get_cap_dvseb(data)                                  ((0x00000002&(data))>>1)
#define  H3DDMA_I3DDMA_DVSE_get_cap_dvsea(data)                                  (0x00000001&(data))

#define  H3DDMA_I3DDMA_LS                                                        0x180258F8
#define  H3DDMA_I3DDMA_LS_reg_addr                                               "0xB80258F8"
#define  H3DDMA_I3DDMA_LS_reg                                                    0xB80258F8
#define  H3DDMA_I3DDMA_LS_inst_addr                                              "0x002F"
#define  set_H3DDMA_I3DDMA_LS_reg(data)                                          (*((volatile unsigned int*)H3DDMA_I3DDMA_LS_reg)=data)
#define  get_H3DDMA_I3DDMA_LS_reg                                                (*((volatile unsigned int*)H3DDMA_I3DDMA_LS_reg))
#define  H3DDMA_I3DDMA_LS_cap2_ls_shift                                          (1)
#define  H3DDMA_I3DDMA_LS_cap_ls_shift                                           (0)
#define  H3DDMA_I3DDMA_LS_cap2_ls_mask                                           (0x00000002)
#define  H3DDMA_I3DDMA_LS_cap_ls_mask                                            (0x00000001)
#define  H3DDMA_I3DDMA_LS_cap2_ls(data)                                          (0x00000002&((data)<<1))
#define  H3DDMA_I3DDMA_LS_cap_ls(data)                                           (0x00000001&(data))
#define  H3DDMA_I3DDMA_LS_get_cap2_ls(data)                                      ((0x00000002&(data))>>1)
#define  H3DDMA_I3DDMA_LS_get_cap_ls(data)                                       (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======H3DDMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_lr_ctrl1:5;
        RBus_UInt32  hdmi420_en:1;
        RBus_UInt32  chess_board_format:1;
        RBus_UInt32  hdmi_3d_sel:1;
        RBus_UInt32  vs_inv:1;
        RBus_UInt32  hs_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  progressive:1;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  fp_vact_space1:8;
        RBus_UInt32  fp_vact_space2:8;
    };
}h3ddma_lr_separate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vact:16;
        RBus_UInt32  res1:1;
        RBus_UInt32  hact:15;
    };
}h3ddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  hstart:13;
        RBus_UInt32  vstart:8;
    };
}h3ddma_lr_separate_insert_vs_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  hend:13;
        RBus_UInt32  vend:8;
    };
}h3ddma_lr_separate_insert_vs_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  triple_buf_en:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  quad_buf_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  half_wr_en:1;
        RBus_UInt32  half_wr_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  cap_write_rem:7;
    };
}h3ddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cap_ctl1:17;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  cap_write_num:8;
    };
}h3ddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_up_limit:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_mem_low_limit:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l2_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r1_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_r1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r2_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_r2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r1_start_db:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_r1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cap2_block_sel:2;
        RBus_UInt32  cap_block_sel:2;
        RBus_UInt32  cap2_last_wr_flag:1;
        RBus_UInt32  cap_last_wr_flag:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  tg_l_flag:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_ddr_over_range:1;
    };
}h3ddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pullup_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  tg_hend1:13;
        RBus_UInt32  tg_vend1:8;
    };
}h3ddma_tg_v1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vstart2:13;
    };
}h3ddma_tg_v2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend2:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vend2:13;
    };
}h3ddma_tg_v2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart3:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vstart3:13;
    };
}h3ddma_tg_v3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend3:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vend3:13;
    };
}h3ddma_tg_v3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vstart4:13;
    };
}h3ddma_tg_v4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend4:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  tg_vend4:13;
    };
}h3ddma_tg_v4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_cts_fifo:24;
        RBus_UInt32  res1:5;
        RBus_UInt32  force_ctsfifo_rstn:1;
        RBus_UInt32  en_ctsfifo_vsrst:1;
        RBus_UInt32  en_ctsfifo_bypass:1;
    };
}h3ddma_cts_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  l_crc_start:1;
    };
}h3ddma_lr_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}h3ddma_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}h3ddma_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  cap2_last_wrt_ie:1;
        RBus_UInt32  cap_last_wrt_ie:1;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  vs_rising_ie:1;
    };
}h3ddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  frc_style:1;
        RBus_UInt32  frc_en:1;
        RBus_UInt32  tg_en:1;
        RBus_UInt32  lr_separate_en:1;
        RBus_UInt32  cap_en:1;
    };
}h3ddma_i3ddma_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_1byte_swap:1;
    };
}h3ddma_i3ddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap2_l1_start_db:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_l1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap2_r1_start_db:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_r1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  cap2_block:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cap2_fifo_full:1;
        RBus_UInt32  cap2_fifo_empty:1;
        RBus_UInt32  cap2_fifo_overflow:1;
        RBus_UInt32  cap2_fifo_underflow:1;
        RBus_UInt32  cap2_ddr_over_range:1;
    };
}h3ddma_cap_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l3_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r3_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_r3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_l4_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_l4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_r4_start:29;
        RBus_UInt32  res1:3;
    };
}h3ddma_cap_r4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_parser_en:1;
        RBus_UInt32  cap2_write_len:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap2_write_rem:7;
        RBus_UInt32  cap2_dcu_sel:1;
        RBus_UInt32  cap2_water_lv:7;
        RBus_UInt32  cap2_write_num:8;
    };
}cap_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_m1_start:29;
        RBus_UInt32  res1:3;
    };
}md_m1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_m2_start:29;
        RBus_UInt32  res1:3;
    };
}md_m2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_m3_start:29;
        RBus_UInt32  res1:3;
    };
}md_m3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_m4_start:29;
        RBus_UInt32  res1:3;
    };
}md_m4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  max_packet_num:9;
        RBus_UInt32  dummy180258a8_7_5:3;
        RBus_UInt32  dummy180258a8_4:1;
        RBus_UInt32  dummy180258a8_3:1;
        RBus_UInt32  mode:2;
        RBus_UInt32  en:1;
    };
}i3ddma_mdp_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cap2_8byte_swap:1;
        RBus_UInt32  cap2_4byte_swap:1;
        RBus_UInt32  cap2_2byte_swap:1;
        RBus_UInt32  cap2_1byte_swap:1;
    };
}cap2_byte_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  i3ddma_bist_cap2_fail:1;
        RBus_UInt32  i3ddma_bist_cap_fail:1;
    };
}h3ddma_i3ddma_bist_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  i3ddma_drf_cap2_fail:1;
        RBus_UInt32  i3ddma_drf_cap_fail:1;
    };
}h3ddma_i3ddma_drf_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cap2_dvsb:4;
        RBus_UInt32  cap2_dvsa:4;
        RBus_UInt32  cap_dvsb:4;
        RBus_UInt32  cap_dvsa:4;
    };
}h3ddma_i3ddma_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cap2_dvseb:1;
        RBus_UInt32  cap2_dvsea:1;
        RBus_UInt32  cap_dvseb:1;
        RBus_UInt32  cap_dvsea:1;
    };
}h3ddma_i3ddma_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  cap2_ls:1;
        RBus_UInt32  cap_ls:1;
    };
}h3ddma_i3ddma_ls_RBUS;

#else //apply LITTLE_ENDIAN

//======H3DDMA register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fp_vact_space2:8;
        RBus_UInt32  fp_vact_space1:8;
        RBus_UInt32  hdmi_3d_structure:4;
        RBus_UInt32  progressive:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hs_inv:1;
        RBus_UInt32  vs_inv:1;
        RBus_UInt32  hdmi_3d_sel:1;
        RBus_UInt32  chess_board_format:1;
        RBus_UInt32  hdmi420_en:1;
        RBus_UInt32  dummy_lr_ctrl1:5;
    };
}h3ddma_lr_separate_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hact:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  vact:16;
    };
}h3ddma_lr_separate_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vstart:8;
        RBus_UInt32  hstart:13;
        RBus_UInt32  res1:11;
    };
}h3ddma_lr_separate_insert_vs_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vend:8;
        RBus_UInt32  hend:13;
        RBus_UInt32  res1:11;
    };
}h3ddma_lr_separate_insert_vs_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_rem:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap_write_len:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pixel_encoding:2;
        RBus_UInt32  bit_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  half_wr_sel:1;
        RBus_UInt32  half_wr_en:1;
        RBus_UInt32  auto_block_sel_en:1;
        RBus_UInt32  vs_fall_rst_en:1;
        RBus_UInt32  freeze_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  quad_buf_en:1;
        RBus_UInt32  set_block_sel:1;
        RBus_UInt32  cap_block_fw:2;
        RBus_UInt32  triple_buf_en:1;
    };
}h3ddma_cap_ctl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_write_num:8;
        RBus_UInt32  cap_water_lv:7;
        RBus_UInt32  dummy_cap_ctl1:17;
    };
}h3ddma_cap_ctl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_up_limit:29;
    };
}h3ddma_cap_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_mem_low_limit:29;
    };
}h3ddma_cap_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start:29;
    };
}h3ddma_cap_l1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l2_start:29;
    };
}h3ddma_cap_l2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r1_start:29;
    };
}h3ddma_cap_r1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r2_start:29;
    };
}h3ddma_cap_r2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l1_start_db:29;
    };
}h3ddma_cap_l1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r1_start_db:29;
    };
}h3ddma_cap_r1_start_db_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ddr_over_range:1;
        RBus_UInt32  cap_fifo_underflow:1;
        RBus_UInt32  cap_fifo_overflow:1;
        RBus_UInt32  cap_fifo_empty:1;
        RBus_UInt32  cap_fifo_full:1;
        RBus_UInt32  cap_field:1;
        RBus_UInt32  cap_block:1;
        RBus_UInt32  tg_l_flag:1;
        RBus_UInt32  vs_rising_occur:1;
        RBus_UInt32  freeze_ok:1;
        RBus_UInt32  cap_under_size:1;
        RBus_UInt32  cap_over_size:1;
        RBus_UInt32  cap_block_2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  cap_last_wr_flag:1;
        RBus_UInt32  cap2_last_wr_flag:1;
        RBus_UInt32  cap_block_sel:2;
        RBus_UInt32  cap2_block_sel:2;
        RBus_UInt32  res2:10;
    };
}h3ddma_cap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend1:8;
        RBus_UInt32  tg_hend1:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pullup_en:1;
        RBus_UInt32  res3:6;
    };
}h3ddma_tg_v1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vstart2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart2:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_tg_v2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend2:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend2:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_tg_v2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vstart3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart3:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_tg_v3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend3:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend3:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_tg_v3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vstart4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hstart4:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_tg_v4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tg_vend4:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  tg_hend4:13;
        RBus_UInt32  res2:3;
    };
}h3ddma_tg_v4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en_ctsfifo_bypass:1;
        RBus_UInt32  en_ctsfifo_vsrst:1;
        RBus_UInt32  force_ctsfifo_rstn:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  dummy_cts_fifo:24;
    };
}h3ddma_cts_fifo_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_crc_start:1;
        RBus_UInt32  l_crc_conti:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  r_crc_start:1;
        RBus_UInt32  r_crc_conti:1;
        RBus_UInt32  res2:22;
    };
}h3ddma_lr_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_l_result:32;
    };
}h3ddma_crc_l_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_r_result:32;
    };
}h3ddma_crc_r_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vs_rising_ie:1;
        RBus_UInt32  fifo_err_ie:1;
        RBus_UInt32  mem_err_ie:1;
        RBus_UInt32  cap_last_wrt_ie:1;
        RBus_UInt32  cap2_last_wrt_ie:1;
        RBus_UInt32  res1:27;
    };
}h3ddma_interrupt_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_en:1;
        RBus_UInt32  lr_separate_en:1;
        RBus_UInt32  tg_en:1;
        RBus_UInt32  frc_en:1;
        RBus_UInt32  frc_style:1;
        RBus_UInt32  res1:27;
    };
}h3ddma_i3ddma_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_1byte_swap:1;
        RBus_UInt32  dma_2byte_swap:1;
        RBus_UInt32  dma_4byte_swap:1;
        RBus_UInt32  dma_8byte_swap:1;
        RBus_UInt32  dma_channel_swap:3;
        RBus_UInt32  res1:25;
    };
}h3ddma_i3ddma_byte_channel_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap2_l1_start_db:29;
    };
}h3ddma_cap_l1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap2_r1_start_db:29;
    };
}h3ddma_cap_r1_start_db_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap2_ddr_over_range:1;
        RBus_UInt32  cap2_fifo_underflow:1;
        RBus_UInt32  cap2_fifo_overflow:1;
        RBus_UInt32  cap2_fifo_empty:1;
        RBus_UInt32  cap2_fifo_full:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap2_block:1;
        RBus_UInt32  res2:25;
    };
}h3ddma_cap_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l3_start:29;
    };
}h3ddma_cap_l3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r3_start:29;
    };
}h3ddma_cap_r3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_l4_start:29;
    };
}h3ddma_cap_l4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cap_r4_start:29;
    };
}h3ddma_cap_r4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap2_write_num:8;
        RBus_UInt32  cap2_water_lv:7;
        RBus_UInt32  cap2_dcu_sel:1;
        RBus_UInt32  cap2_write_rem:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cap2_write_len:7;
        RBus_UInt32  md_parser_en:1;
    };
}cap_ctl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  md_m1_start:29;
    };
}md_m1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  md_m2_start:29;
    };
}md_m2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  md_m3_start:29;
    };
}md_m3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  md_m4_start:29;
    };
}md_m4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  en:1;
        RBus_UInt32  mode:2;
        RBus_UInt32  dummy180258a8_3:1;
        RBus_UInt32  dummy180258a8_4:1;
        RBus_UInt32  dummy180258a8_7:3;
        RBus_UInt32  max_packet_num:9;
        RBus_UInt32  res1:15;
    };
}i3ddma_mdp_cr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap2_1byte_swap:1;
        RBus_UInt32  cap2_2byte_swap:1;
        RBus_UInt32  cap2_4byte_swap:1;
        RBus_UInt32  cap2_8byte_swap:1;
        RBus_UInt32  res1:28;
    };
}cap2_byte_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_bist_cap_fail:1;
        RBus_UInt32  i3ddma_bist_cap2_fail:1;
        RBus_UInt32  res1:30;
    };
}h3ddma_i3ddma_bist_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i3ddma_drf_cap_fail:1;
        RBus_UInt32  i3ddma_drf_cap2_fail:1;
        RBus_UInt32  res1:30;
    };
}h3ddma_i3ddma_drf_cap_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dvsa:4;
        RBus_UInt32  cap_dvsb:4;
        RBus_UInt32  cap2_dvsa:4;
        RBus_UInt32  cap2_dvsb:4;
        RBus_UInt32  res1:16;
    };
}h3ddma_i3ddma_dvs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_dvsea:1;
        RBus_UInt32  cap_dvseb:1;
        RBus_UInt32  cap2_dvsea:1;
        RBus_UInt32  cap2_dvseb:1;
        RBus_UInt32  res1:28;
    };
}h3ddma_i3ddma_dvse_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cap_ls:1;
        RBus_UInt32  cap2_ls:1;
        RBus_UInt32  res1:30;
    };
}h3ddma_i3ddma_ls_RBUS;




#endif 


#endif 
