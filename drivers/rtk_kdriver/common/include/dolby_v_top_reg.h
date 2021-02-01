/**
* @file rbusDolby_v_topReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/6/7
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DOLBY_V_TOP_REG_H_
#define _RBUS_DOLBY_V_TOP_REG_H_

#include "rbus/rbusTypes.h"



//  DOLBY_V_TOP Register Address
#define  DOLBY_V_TOP_TOP_CTL                                                     0x1806B800
#define  DOLBY_V_TOP_TOP_CTL_reg_addr                                            "0xB806B800"
#define  DOLBY_V_TOP_TOP_CTL_reg                                                 0xB806B800
#define  DOLBY_V_TOP_TOP_CTL_inst_addr                                           "0x0000"
#define  set_DOLBY_V_TOP_TOP_CTL_reg(data)                                       (*((volatile unsigned int*)DOLBY_V_TOP_TOP_CTL_reg)=data)
#define  get_DOLBY_V_TOP_TOP_CTL_reg                                             (*((volatile unsigned int*)DOLBY_V_TOP_TOP_CTL_reg))
#define  DOLBY_V_TOP_TOP_CTL_dolby_v_read_sel_shift                              (31)
#define  DOLBY_V_TOP_TOP_CTL_end_out_mux_shift                                   (16)
#define  DOLBY_V_TOP_TOP_CTL_sel_sign_2_shift                                    (15)
#define  DOLBY_V_TOP_TOP_CTL_cr_dly_cb_2_shift                                   (14)
#define  DOLBY_V_TOP_TOP_CTL_dup_2_shift                                         (13)
#define  DOLBY_V_TOP_TOP_CTL_en_422to444_2_shift                                 (12)
#define  DOLBY_V_TOP_TOP_CTL_sel_sign_1_shift                                    (11)
#define  DOLBY_V_TOP_TOP_CTL_cr_dly_cb_1_shift                                   (10)
#define  DOLBY_V_TOP_TOP_CTL_dup_1_shift                                         (9)
#define  DOLBY_V_TOP_TOP_CTL_en_422to444_1_shift                                 (8)
#define  DOLBY_V_TOP_TOP_CTL_bl_el_layer_shift                                   (5)
#define  DOLBY_V_TOP_TOP_CTL_hdmi_in_mux_shift                                   (4)
#define  DOLBY_V_TOP_TOP_CTL_dolby_ratio_shift                                   (3)
#define  DOLBY_V_TOP_TOP_CTL_dolby_mode_shift                                    (0)
#define  DOLBY_V_TOP_TOP_CTL_dolby_v_read_sel_mask                               (0x80000000)
#define  DOLBY_V_TOP_TOP_CTL_end_out_mux_mask                                    (0x00010000)
#define  DOLBY_V_TOP_TOP_CTL_sel_sign_2_mask                                     (0x00008000)
#define  DOLBY_V_TOP_TOP_CTL_cr_dly_cb_2_mask                                    (0x00004000)
#define  DOLBY_V_TOP_TOP_CTL_dup_2_mask                                          (0x00002000)
#define  DOLBY_V_TOP_TOP_CTL_en_422to444_2_mask                                  (0x00001000)
#define  DOLBY_V_TOP_TOP_CTL_sel_sign_1_mask                                     (0x00000800)
#define  DOLBY_V_TOP_TOP_CTL_cr_dly_cb_1_mask                                    (0x00000400)
#define  DOLBY_V_TOP_TOP_CTL_dup_1_mask                                          (0x00000200)
#define  DOLBY_V_TOP_TOP_CTL_en_422to444_1_mask                                  (0x00000100)
#define  DOLBY_V_TOP_TOP_CTL_bl_el_layer_mask                                    (0x00000020)
#define  DOLBY_V_TOP_TOP_CTL_hdmi_in_mux_mask                                    (0x00000010)
#define  DOLBY_V_TOP_TOP_CTL_dolby_ratio_mask                                    (0x00000008)
#define  DOLBY_V_TOP_TOP_CTL_dolby_mode_mask                                     (0x00000007)
#define  DOLBY_V_TOP_TOP_CTL_dolby_v_read_sel(data)                              (0x80000000&((data)<<31))
#define  DOLBY_V_TOP_TOP_CTL_end_out_mux(data)                                   (0x00010000&((data)<<16))
#define  DOLBY_V_TOP_TOP_CTL_sel_sign_2(data)                                    (0x00008000&((data)<<15))
#define  DOLBY_V_TOP_TOP_CTL_cr_dly_cb_2(data)                                   (0x00004000&((data)<<14))
#define  DOLBY_V_TOP_TOP_CTL_dup_2(data)                                         (0x00002000&((data)<<13))
#define  DOLBY_V_TOP_TOP_CTL_en_422to444_2(data)                                 (0x00001000&((data)<<12))
#define  DOLBY_V_TOP_TOP_CTL_sel_sign_1(data)                                    (0x00000800&((data)<<11))
#define  DOLBY_V_TOP_TOP_CTL_cr_dly_cb_1(data)                                   (0x00000400&((data)<<10))
#define  DOLBY_V_TOP_TOP_CTL_dup_1(data)                                         (0x00000200&((data)<<9))
#define  DOLBY_V_TOP_TOP_CTL_en_422to444_1(data)                                 (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_TOP_CTL_bl_el_layer(data)                                   (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_TOP_CTL_hdmi_in_mux(data)                                   (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_TOP_CTL_dolby_ratio(data)                                   (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_TOP_CTL_dolby_mode(data)                                    (0x00000007&(data))
#define  DOLBY_V_TOP_TOP_CTL_get_dolby_v_read_sel(data)                          ((0x80000000&(data))>>31)
#define  DOLBY_V_TOP_TOP_CTL_get_end_out_mux(data)                               ((0x00010000&(data))>>16)
#define  DOLBY_V_TOP_TOP_CTL_get_sel_sign_2(data)                                ((0x00008000&(data))>>15)
#define  DOLBY_V_TOP_TOP_CTL_get_cr_dly_cb_2(data)                               ((0x00004000&(data))>>14)
#define  DOLBY_V_TOP_TOP_CTL_get_dup_2(data)                                     ((0x00002000&(data))>>13)
#define  DOLBY_V_TOP_TOP_CTL_get_en_422to444_2(data)                             ((0x00001000&(data))>>12)
#define  DOLBY_V_TOP_TOP_CTL_get_sel_sign_1(data)                                ((0x00000800&(data))>>11)
#define  DOLBY_V_TOP_TOP_CTL_get_cr_dly_cb_1(data)                               ((0x00000400&(data))>>10)
#define  DOLBY_V_TOP_TOP_CTL_get_dup_1(data)                                     ((0x00000200&(data))>>9)
#define  DOLBY_V_TOP_TOP_CTL_get_en_422to444_1(data)                             ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_TOP_CTL_get_bl_el_layer(data)                               ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_TOP_CTL_get_hdmi_in_mux(data)                               ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_TOP_CTL_get_dolby_ratio(data)                               ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_TOP_CTL_get_dolby_mode(data)                                (0x00000007&(data))

#define  DOLBY_V_TOP_TOP_PIC_SIZE                                                0x1806B804
#define  DOLBY_V_TOP_TOP_PIC_SIZE_reg_addr                                       "0xB806B804"
#define  DOLBY_V_TOP_TOP_PIC_SIZE_reg                                            0xB806B804
#define  DOLBY_V_TOP_TOP_PIC_SIZE_inst_addr                                      "0x0001"
#define  set_DOLBY_V_TOP_TOP_PIC_SIZE_reg(data)                                  (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_SIZE_reg)=data)
#define  get_DOLBY_V_TOP_TOP_PIC_SIZE_reg                                        (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_SIZE_reg))
#define  DOLBY_V_TOP_TOP_PIC_SIZE_dolby_vsize_shift                              (16)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_dolby_hsize_shift                              (0)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_dolby_vsize_mask                               (0x0FFF0000)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_dolby_hsize_mask                               (0x00001FFF)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_dolby_vsize(data)                              (0x0FFF0000&((data)<<16))
#define  DOLBY_V_TOP_TOP_PIC_SIZE_dolby_hsize(data)                              (0x00001FFF&(data))
#define  DOLBY_V_TOP_TOP_PIC_SIZE_get_dolby_vsize(data)                          ((0x0FFF0000&(data))>>16)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_get_dolby_hsize(data)                          (0x00001FFF&(data))

#define  DOLBY_V_TOP_TOP_PIC_TOTAL                                               0x1806B808
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_reg_addr                                      "0xB806B808"
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_reg                                           0xB806B808
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_inst_addr                                     "0x0002"
#define  set_DOLBY_V_TOP_TOP_PIC_TOTAL_reg(data)                                 (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_TOTAL_reg)=data)
#define  get_DOLBY_V_TOP_TOP_PIC_TOTAL_reg                                       (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_TOTAL_reg))
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_dolby_h_total_shift                           (0)
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_dolby_h_total_mask                            (0x00001FFF)
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_dolby_h_total(data)                           (0x00001FFF&(data))
#define  DOLBY_V_TOP_TOP_PIC_TOTAL_get_dolby_h_total(data)                       (0x00001FFF&(data))

#define  DOLBY_V_TOP_TOP_PIC_STA                                                 0x1806B80C
#define  DOLBY_V_TOP_TOP_PIC_STA_reg_addr                                        "0xB806B80C"
#define  DOLBY_V_TOP_TOP_PIC_STA_reg                                             0xB806B80C
#define  DOLBY_V_TOP_TOP_PIC_STA_inst_addr                                       "0x0003"
#define  set_DOLBY_V_TOP_TOP_PIC_STA_reg(data)                                   (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_STA_reg)=data)
#define  get_DOLBY_V_TOP_TOP_PIC_STA_reg                                         (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_STA_reg))
#define  DOLBY_V_TOP_TOP_PIC_STA_dolby_v_den_sta_shift                           (16)
#define  DOLBY_V_TOP_TOP_PIC_STA_dolby_h_den_sta_shift                           (0)
#define  DOLBY_V_TOP_TOP_PIC_STA_dolby_v_den_sta_mask                            (0x00FF0000)
#define  DOLBY_V_TOP_TOP_PIC_STA_dolby_h_den_sta_mask                            (0x00000FFF)
#define  DOLBY_V_TOP_TOP_PIC_STA_dolby_v_den_sta(data)                           (0x00FF0000&((data)<<16))
#define  DOLBY_V_TOP_TOP_PIC_STA_dolby_h_den_sta(data)                           (0x00000FFF&(data))
#define  DOLBY_V_TOP_TOP_PIC_STA_get_dolby_v_den_sta(data)                       ((0x00FF0000&(data))>>16)
#define  DOLBY_V_TOP_TOP_PIC_STA_get_dolby_h_den_sta(data)                       (0x00000FFF&(data))

#define  DOLBY_V_TOP_TOP_D_BUF                                                   0x1806B810
#define  DOLBY_V_TOP_TOP_D_BUF_reg_addr                                          "0xB806B810"
#define  DOLBY_V_TOP_TOP_D_BUF_reg                                               0xB806B810
#define  DOLBY_V_TOP_TOP_D_BUF_inst_addr                                         "0x0004"
#define  set_DOLBY_V_TOP_TOP_D_BUF_reg(data)                                     (*((volatile unsigned int*)DOLBY_V_TOP_TOP_D_BUF_reg)=data)
#define  get_DOLBY_V_TOP_TOP_D_BUF_reg                                           (*((volatile unsigned int*)DOLBY_V_TOP_TOP_D_BUF_reg))
#define  DOLBY_V_TOP_TOP_D_BUF_dolby_double_apply_shift                          (1)
#define  DOLBY_V_TOP_TOP_D_BUF_dolby_double_en_shift                             (0)
#define  DOLBY_V_TOP_TOP_D_BUF_dolby_double_apply_mask                           (0x00000002)
#define  DOLBY_V_TOP_TOP_D_BUF_dolby_double_en_mask                              (0x00000001)
#define  DOLBY_V_TOP_TOP_D_BUF_dolby_double_apply(data)                          (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_TOP_D_BUF_dolby_double_en(data)                             (0x00000001&(data))
#define  DOLBY_V_TOP_TOP_D_BUF_get_dolby_double_apply(data)                      ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_TOP_D_BUF_get_dolby_double_en(data)                         (0x00000001&(data))

#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP                                           0x1806B814
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_reg_addr                                  "0xB806B814"
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_reg                                       0xB806B814
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_inst_addr                                 "0x0005"
#define  set_DOLBY_V_TOP_TOP_PIC_SIZE_CROP_reg(data)                             (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_SIZE_CROP_reg)=data)
#define  get_DOLBY_V_TOP_TOP_PIC_SIZE_CROP_reg                                   (*((volatile unsigned int*)DOLBY_V_TOP_TOP_PIC_SIZE_CROP_reg))
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_crop_v_en_shift                           (29)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_crop_h_en_shift                           (28)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_crop_v_en_mask                            (0x20000000)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_crop_h_en_mask                            (0x10000000)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_crop_v_en(data)                           (0x20000000&((data)<<29))
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_crop_h_en(data)                           (0x10000000&((data)<<28))
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_get_crop_v_en(data)                       ((0x20000000&(data))>>29)
#define  DOLBY_V_TOP_TOP_PIC_SIZE_CROP_get_crop_h_en(data)                       ((0x10000000&(data))>>28)

#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS                                          0x1806B820
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_reg_addr                                 "0xB806B820"
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_reg                                      0xB806B820
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_inst_addr                                "0x0005"
#define  set_DOLBY_V_TOP_SENSIO_FIFO_STATUS_reg(data)                            (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_FIFO_STATUS_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_FIFO_STATUS_reg                                  (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_FIFO_STATUS_reg))
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_efuse_in_shift                           (1)
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_sen_fifo_uf_shift                        (0)
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_efuse_in_mask                            (0x00000006)
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_sen_fifo_uf_mask                         (0x00000001)
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_efuse_in(data)                           (0x00000006&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_sen_fifo_uf(data)                        (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_get_efuse_in(data)                       ((0x00000006&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_FIFO_STATUS_get_sen_fifo_uf(data)                    (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_BIST_MODE                                            0x1806B860
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_reg_addr                                   "0xB806B860"
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_reg                                        0xB806B860
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_inst_addr                                  "0x0006"
#define  set_DOLBY_V_TOP_SENSIO_BIST_MODE_reg(data)                              (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_BIST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_BIST_MODE_reg                                    (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_BIST_MODE_reg))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_3_mode_shift               (7)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_2_mode_shift               (6)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_1_mode_shift               (5)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_0_mode_shift               (4)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_3_mode_shift                   (3)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_2_mode_shift                   (2)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_1_mode_shift                   (1)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_0_mode_shift                   (0)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_3_mode_mask                (0x00000080)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_2_mode_mask                (0x00000040)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_1_mode_mask                (0x00000020)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_0_mode_mask                (0x00000010)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_3_mode_mask                    (0x00000008)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_2_mode_mask                    (0x00000004)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_1_mode_mask                    (0x00000002)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_0_mode_mask                    (0x00000001)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_3_mode(data)               (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_2_mode(data)               (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_1_mode(data)               (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_sub_0_mode(data)               (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_3_mode(data)                   (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_2_mode(data)                   (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_1_mode(data)                   (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_sensio_bist_0_mode(data)                   (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_sub_3_mode(data)           ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_sub_2_mode(data)           ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_sub_1_mode(data)           ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_sub_0_mode(data)           ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_3_mode(data)               ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_2_mode(data)               ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_1_mode(data)               ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_BIST_MODE_get_sensio_bist_0_mode(data)               (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_BIST_DONE                                            0x1806B864
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_reg_addr                                   "0xB806B864"
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_reg                                        0xB806B864
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_inst_addr                                  "0x0007"
#define  set_DOLBY_V_TOP_SENSIO_BIST_DONE_reg(data)                              (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_BIST_DONE_reg                                    (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_BIST_DONE_reg))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_3_done_shift               (7)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_2_done_shift               (6)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_1_done_shift               (5)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_0_done_shift               (4)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_3_done_shift                   (3)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_2_done_shift                   (2)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_1_done_shift                   (1)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_0_done_shift                   (0)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_3_done_mask                (0x00000080)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_2_done_mask                (0x00000040)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_1_done_mask                (0x00000020)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_0_done_mask                (0x00000010)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_3_done_mask                    (0x00000008)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_2_done_mask                    (0x00000004)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_1_done_mask                    (0x00000002)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_0_done_mask                    (0x00000001)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_3_done(data)               (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_2_done(data)               (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_1_done(data)               (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_sub_0_done(data)               (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_3_done(data)                   (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_2_done(data)                   (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_1_done(data)                   (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_sensio_bist_0_done(data)                   (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_sub_3_done(data)           ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_sub_2_done(data)           ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_sub_1_done(data)           ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_sub_0_done(data)           ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_3_done(data)               ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_2_done(data)               ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_1_done(data)               ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_BIST_DONE_get_sensio_bist_0_done(data)               (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP                                      0x1806B868
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_reg_addr                             "0xB806B868"
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_reg                                  0xB806B868
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_inst_addr                            "0x0008"
#define  set_DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_reg(data)                        (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_reg                              (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_reg))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_3_group_shift   (7)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_2_group_shift   (6)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_1_group_shift   (5)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_0_group_shift   (4)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_3_group_shift       (3)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_2_group_shift       (2)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_1_group_shift       (1)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_0_group_shift       (0)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_3_group_mask    (0x00000080)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_2_group_mask    (0x00000040)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_1_group_mask    (0x00000020)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_0_group_mask    (0x00000010)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_3_group_mask        (0x00000008)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_2_group_mask        (0x00000004)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_1_group_mask        (0x00000002)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_0_group_mask        (0x00000001)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_3_group(data)   (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_2_group(data)   (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_1_group(data)   (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_sub_0_group(data)   (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_3_group(data)       (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_2_group(data)       (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_1_group(data)       (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_sensio_bist_fail_0_group(data)       (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_sub_3_group(data) ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_sub_2_group(data) ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_sub_1_group(data) ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_sub_0_group(data) ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_3_group(data)   ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_2_group(data)   ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_1_group(data)   ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_BIST_FAIL_GROUP_get_sensio_bist_fail_0_group(data)   (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_DRF_MODE                                             0x1806B86C
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_reg_addr                                    "0xB806B86C"
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_reg                                         0xB806B86C
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_inst_addr                                   "0x0009"
#define  set_DOLBY_V_TOP_SENSIO_DRF_MODE_reg(data)                               (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_MODE_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_DRF_MODE_reg                                     (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_MODE_reg))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_3_mode_shift                 (7)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_2_mode_shift                 (6)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_1_mode_shift                 (5)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_0_mode_shift                 (4)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_3_mode_shift                     (3)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_2_mode_shift                     (2)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_1_mode_shift                     (1)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_0_mode_shift                     (0)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_3_mode_mask                  (0x00000080)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_2_mode_mask                  (0x00000040)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_1_mode_mask                  (0x00000020)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_0_mode_mask                  (0x00000010)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_3_mode_mask                      (0x00000008)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_2_mode_mask                      (0x00000004)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_1_mode_mask                      (0x00000002)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_0_mode_mask                      (0x00000001)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_3_mode(data)                 (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_2_mode(data)                 (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_1_mode(data)                 (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_sub_0_mode(data)                 (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_3_mode(data)                     (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_2_mode(data)                     (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_1_mode(data)                     (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_sensio_drf_0_mode(data)                     (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_sub_3_mode(data)             ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_sub_2_mode(data)             ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_sub_1_mode(data)             ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_sub_0_mode(data)             ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_3_mode(data)                 ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_2_mode(data)                 ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_1_mode(data)                 ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_DRF_MODE_get_sensio_drf_0_mode(data)                 (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_DRF_RESUME                                           0x1806B870
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_reg_addr                                  "0xB806B870"
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_reg                                       0xB806B870
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_inst_addr                                 "0x000A"
#define  set_DOLBY_V_TOP_SENSIO_DRF_RESUME_reg(data)                             (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_RESUME_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_DRF_RESUME_reg                                   (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_RESUME_reg))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_3_resume_shift             (7)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_2_resume_shift             (6)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_1_resume_shift             (5)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_0_resume_shift             (4)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_3_resume_shift                 (3)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_2_resume_shift                 (2)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_1_resume_shift                 (1)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_0_resume_shift                 (0)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_3_resume_mask              (0x00000080)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_2_resume_mask              (0x00000040)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_1_resume_mask              (0x00000020)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_0_resume_mask              (0x00000010)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_3_resume_mask                  (0x00000008)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_2_resume_mask                  (0x00000004)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_1_resume_mask                  (0x00000002)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_0_resume_mask                  (0x00000001)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_3_resume(data)             (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_2_resume(data)             (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_1_resume(data)             (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_sub_0_resume(data)             (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_3_resume(data)                 (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_2_resume(data)                 (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_1_resume(data)                 (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_sensio_drf_0_resume(data)                 (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_sub_3_resume(data)         ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_sub_2_resume(data)         ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_sub_1_resume(data)         ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_sub_0_resume(data)         ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_3_resume(data)             ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_2_resume(data)             ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_1_resume(data)             ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_DRF_RESUME_get_sensio_drf_0_resume(data)             (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_DRF_DONE                                             0x1806B874
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_reg_addr                                    "0xB806B874"
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_reg                                         0xB806B874
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_inst_addr                                   "0x000B"
#define  set_DOLBY_V_TOP_SENSIO_DRF_DONE_reg(data)                               (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_DONE_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_DRF_DONE_reg                                     (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_DONE_reg))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_3_done_shift                 (7)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_2_done_shift                 (6)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_1_done_shift                 (5)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_0_done_shift                 (4)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_3_done_shift                     (3)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_2_done_shift                     (2)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_1_done_shift                     (1)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_0_done_shift                     (0)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_3_done_mask                  (0x00000080)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_2_done_mask                  (0x00000040)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_1_done_mask                  (0x00000020)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_0_done_mask                  (0x00000010)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_3_done_mask                      (0x00000008)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_2_done_mask                      (0x00000004)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_1_done_mask                      (0x00000002)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_0_done_mask                      (0x00000001)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_3_done(data)                 (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_2_done(data)                 (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_1_done(data)                 (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_sub_0_done(data)                 (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_3_done(data)                     (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_2_done(data)                     (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_1_done(data)                     (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_sensio_drf_0_done(data)                     (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_sub_3_done(data)             ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_sub_2_done(data)             ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_sub_1_done(data)             ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_sub_0_done(data)             ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_3_done(data)                 ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_2_done(data)                 ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_1_done(data)                 ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_DRF_DONE_get_sensio_drf_0_done(data)                 (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE                                            0x1806B878
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_reg_addr                                   "0xB806B878"
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_reg                                        0xB806B878
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_inst_addr                                  "0x000C"
#define  set_DOLBY_V_TOP_SENSIO_DRF_PAUSE_reg(data)                              (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_PAUSE_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_DRF_PAUSE_reg                                    (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_PAUSE_reg))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_3_pause_shift               (7)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_2_pause_shift               (6)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_1_pause_shift               (5)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_0_pause_shift               (4)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_3_pause_shift                   (3)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_2_pause_shift                   (2)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_1_pause_shift                   (1)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_0_pause_shift                   (0)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_3_pause_mask                (0x00000080)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_2_pause_mask                (0x00000040)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_1_pause_mask                (0x00000020)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_0_pause_mask                (0x00000010)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_3_pause_mask                    (0x00000008)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_2_pause_mask                    (0x00000004)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_1_pause_mask                    (0x00000002)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_0_pause_mask                    (0x00000001)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_3_pause(data)               (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_2_pause(data)               (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_1_pause(data)               (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_sub_0_pause(data)               (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_3_pause(data)                   (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_2_pause(data)                   (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_1_pause(data)                   (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_sensio_drf_0_pause(data)                   (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_sub_3_pause(data)           ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_sub_2_pause(data)           ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_sub_1_pause(data)           ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_sub_0_pause(data)           ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_3_pause(data)               ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_2_pause(data)               ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_1_pause(data)               ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_DRF_PAUSE_get_sensio_drf_0_pause(data)               (0x00000001&(data))

#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP                                       0x1806B87C
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_reg_addr                              "0xB806B87C"
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_reg                                   0xB806B87C
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_inst_addr                             "0x000D"
#define  set_DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_reg(data)                         (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_reg)=data)
#define  get_DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_reg                               (*((volatile unsigned int*)DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_reg))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_3_group_shift     (7)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_2_group_shift     (6)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_1_group_shift     (5)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_0_group_shift     (4)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_3_group_shift         (3)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_2_group_shift         (2)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_1_group_shift         (1)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_0_group_shift         (0)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_3_group_mask      (0x00000080)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_2_group_mask      (0x00000040)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_1_group_mask      (0x00000020)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_0_group_mask      (0x00000010)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_3_group_mask          (0x00000008)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_2_group_mask          (0x00000004)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_1_group_mask          (0x00000002)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_0_group_mask          (0x00000001)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_3_group(data)     (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_2_group(data)     (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_1_group(data)     (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_sub_0_group(data)     (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_3_group(data)         (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_2_group(data)         (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_1_group(data)         (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_sensio_drf_fail_0_group(data)         (0x00000001&(data))
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_sub_3_group(data) ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_sub_2_group(data) ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_sub_1_group(data) ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_sub_0_group(data) ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_3_group(data)     ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_2_group(data)     ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_1_group(data)     ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_SENSIO_DRF_FAIL_GROUP_get_sensio_drf_fail_0_group(data)     (0x00000001&(data))

#define  DOLBY_V_TOP_Composer_BL_BIST_MODE                                       0x1806B880
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_reg_addr                              "0xB806B880"
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_reg                                   0xB806B880
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_inst_addr                             "0x000E"
#define  set_DOLBY_V_TOP_Composer_BL_BIST_MODE_reg(data)                         (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_BIST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_BL_BIST_MODE_reg                               (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_BIST_MODE_reg))
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_composer_bl_bist_mode_shift           (0)
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_composer_bl_bist_mode_mask            (0x00000007)
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_composer_bl_bist_mode(data)           (0x00000007&(data))
#define  DOLBY_V_TOP_Composer_BL_BIST_MODE_get_composer_bl_bist_mode(data)       (0x00000007&(data))

#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE                                   0x1806B884
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_reg_addr                          "0xB806B884"
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_reg                               0xB806B884
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_inst_addr                         "0x000F"
#define  set_DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_reg(data)                     (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_reg                           (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_reg))
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_composer_bl_drf_bist_mode_shift   (0)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_composer_bl_drf_bist_mode_mask    (0x00000007)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_composer_bl_drf_bist_mode(data)   (0x00000007&(data))
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_MODE_get_composer_bl_drf_bist_mode(data) (0x00000007&(data))

#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE                                   0x1806B888
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_reg_addr                          "0xB806B888"
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_reg                               0xB806B888
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_inst_addr                         "0x0010"
#define  set_DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_reg(data)                     (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_reg                           (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_reg))
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_composer_bl_drf_test_resume_shift (0)
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_composer_bl_drf_test_resume_mask  (0x00000007)
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_composer_bl_drf_test_resume(data) (0x00000007&(data))
#define  DOLBY_V_TOP_Composer_BL_DRF_TEST_MODE_get_composer_bl_drf_test_resume(data) (0x00000007&(data))

#define  DOLBY_V_TOP_Composer_BL_BIST_DONE                                       0x1806B88C
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_reg_addr                              "0xB806B88C"
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_reg                                   0xB806B88C
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_inst_addr                             "0x0011"
#define  set_DOLBY_V_TOP_Composer_BL_BIST_DONE_reg(data)                         (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_BL_BIST_DONE_reg                               (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_BIST_DONE_reg))
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_composer_bl_bist_fail_group_shift     (3)
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_composer_bl_bist_done_shift           (0)
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_composer_bl_bist_fail_group_mask      (0x00000008)
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_composer_bl_bist_done_mask            (0x00000007)
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_composer_bl_bist_fail_group(data)     (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_composer_bl_bist_done(data)           (0x00000007&(data))
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_get_composer_bl_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_Composer_BL_BIST_DONE_get_composer_bl_bist_done(data)       (0x00000007&(data))

#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE                                   0x1806B890
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_reg_addr                          "0xB806B890"
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_reg                               0xB806B890
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_inst_addr                         "0x0012"
#define  set_DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_reg(data)                     (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_reg                           (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_reg))
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_composer_bl_drf_bist_fail_group_shift (3)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_composer_bl_drf_bist_done_shift   (0)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_composer_bl_drf_bist_fail_group_mask (0x00000008)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_composer_bl_drf_bist_done_mask    (0x00000007)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_composer_bl_drf_bist_fail_group(data) (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_composer_bl_drf_bist_done(data)   (0x00000007&(data))
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_get_composer_bl_drf_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_Composer_BL_DRF_BIST_DONE_get_composer_bl_drf_bist_done(data) (0x00000007&(data))

#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE                                 0x1806B894
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_reg_addr                        "0xB806B894"
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_reg                             0xB806B894
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_inst_addr                       "0x0013"
#define  set_DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_reg(data)                   (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_reg                         (*((volatile unsigned int*)DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_reg))
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_composer_bl_drf_start_pause_shift (0)
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_composer_bl_drf_start_pause_mask (0x00000007)
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_composer_bl_drf_start_pause(data) (0x00000007&(data))
#define  DOLBY_V_TOP_Composer_BL_DRF_START_PAUSE_get_composer_bl_drf_start_pause(data) (0x00000007&(data))

#define  DOLBY_V_TOP_Composer_EL_BIST_MODE                                       0x1806B898
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_reg_addr                              "0xB806B898"
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_reg                                   0xB806B898
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_inst_addr                             "0x0014"
#define  set_DOLBY_V_TOP_Composer_EL_BIST_MODE_reg(data)                         (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_BIST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_EL_BIST_MODE_reg                               (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_BIST_MODE_reg))
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_composer_el_bist_mode_shift           (0)
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_composer_el_bist_mode_mask            (0x0007FFFF)
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_composer_el_bist_mode(data)           (0x0007FFFF&(data))
#define  DOLBY_V_TOP_Composer_EL_BIST_MODE_get_composer_el_bist_mode(data)       (0x0007FFFF&(data))

#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE                                   0x1806B89C
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_reg_addr                          "0xB806B89C"
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_reg                               0xB806B89C
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_inst_addr                         "0x0015"
#define  set_DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_reg(data)                     (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_reg                           (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_reg))
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_composer_el_drf_bist_mode_shift   (0)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_composer_el_drf_bist_mode_mask    (0x0007FFFF)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_composer_el_drf_bist_mode(data)   (0x0007FFFF&(data))
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_MODE_get_composer_el_drf_bist_mode(data) (0x0007FFFF&(data))

#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE                                   0x1806B8A0
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_reg_addr                          "0xB806B8A0"
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_reg                               0xB806B8A0
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_inst_addr                         "0x0016"
#define  set_DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_reg(data)                     (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_reg                           (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_reg))
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_composer_el_drf_test_resume_shift (0)
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_composer_el_drf_test_resume_mask  (0x0007FFFF)
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_composer_el_drf_test_resume(data) (0x0007FFFF&(data))
#define  DOLBY_V_TOP_Composer_EL_DRF_TEST_MODE_get_composer_el_drf_test_resume(data) (0x0007FFFF&(data))

#define  DOLBY_V_TOP_Composer_EL_BIST_DONE                                       0x1806B8A4
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_reg_addr                              "0xB806B8A4"
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_reg                                   0xB806B8A4
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_inst_addr                             "0x0017"
#define  set_DOLBY_V_TOP_Composer_EL_BIST_DONE_reg(data)                         (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_EL_BIST_DONE_reg                               (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_BIST_DONE_reg))
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_composer_el_bist_fail_group_shift     (19)
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_composer_el_bist_done_shift           (0)
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_composer_el_bist_fail_group_mask      (0x00080000)
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_composer_el_bist_done_mask            (0x0007FFFF)
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_composer_el_bist_fail_group(data)     (0x00080000&((data)<<19))
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_composer_el_bist_done(data)           (0x0007FFFF&(data))
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_get_composer_el_bist_fail_group(data) ((0x00080000&(data))>>19)
#define  DOLBY_V_TOP_Composer_EL_BIST_DONE_get_composer_el_bist_done(data)       (0x0007FFFF&(data))

#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE                                   0x1806B8A8
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_reg_addr                          "0xB806B8A8"
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_reg                               0xB806B8A8
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_inst_addr                         "0x0018"
#define  set_DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_reg(data)                     (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_reg                           (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_reg))
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_composer_el_drf_bist_fail_group_shift (19)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_composer_el_drf_bist_done_shift   (0)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_composer_el_drf_bist_fail_group_mask (0x00080000)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_composer_el_drf_bist_done_mask    (0x0007FFFF)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_composer_el_drf_bist_fail_group(data) (0x00080000&((data)<<19))
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_composer_el_drf_bist_done(data)   (0x0007FFFF&(data))
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_get_composer_el_drf_bist_fail_group(data) ((0x00080000&(data))>>19)
#define  DOLBY_V_TOP_Composer_EL_DRF_BIST_DONE_get_composer_el_drf_bist_done(data) (0x0007FFFF&(data))

#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE                                 0x1806B8AC
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_reg_addr                        "0xB806B8AC"
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_reg                             0xB806B8AC
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_inst_addr                       "0x0019"
#define  set_DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_reg(data)                   (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_reg)=data)
#define  get_DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_reg                         (*((volatile unsigned int*)DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_reg))
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_composer_el_drf_start_pause_shift (0)
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_composer_el_drf_start_pause_mask (0x0007FFFF)
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_composer_el_drf_start_pause(data) (0x0007FFFF&(data))
#define  DOLBY_V_TOP_Composer_EL_DRF_START_PAUSE_get_composer_el_drf_start_pause(data) (0x0007FFFF&(data))

#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE                                          0x1806B8B0
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_reg_addr                                 "0xB806B8B0"
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_reg                                      0xB806B8B0
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_inst_addr                                "0x001A"
#define  set_DOLBY_V_TOP_DM_MBIST_BIST_MODE_reg(data)                            (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_BIST_MODE_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_BIST_MODE_reg                                  (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_BIST_MODE_reg))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_2_1_bist_mode_shift               (8)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_hist_bist_mode_shift                  (7)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b02_2_bist_mode_shift                 (6)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b05_bist_mode_shift                   (5)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b03_2_bist_mode_shift                 (4)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b03_1_bist_mode_shift                 (3)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b02_1_bist_mode_shift                 (2)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_2_0_bist_mode_shift               (1)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_1_bist_mode_shift                 (0)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_2_1_bist_mode_mask                (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_hist_bist_mode_mask                   (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b02_2_bist_mode_mask                  (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b05_bist_mode_mask                    (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b03_2_bist_mode_mask                  (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b03_1_bist_mode_mask                  (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b02_1_bist_mode_mask                  (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_2_0_bist_mode_mask                (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_1_bist_mode_mask                  (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_2_1_bist_mode(data)               (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_hist_bist_mode(data)                  (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b02_2_bist_mode(data)                 (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b05_bist_mode(data)                   (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b03_2_bist_mode(data)                 (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b03_1_bist_mode(data)                 (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b02_1_bist_mode(data)                 (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_2_0_bist_mode(data)               (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_dm_b01_1_bist_mode(data)                 (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b01_2_1_bist_mode(data)           ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_hist_bist_mode(data)              ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b02_2_bist_mode(data)             ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b05_bist_mode(data)               ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b03_2_bist_mode(data)             ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b03_1_bist_mode(data)             ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b02_1_bist_mode(data)             ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b01_2_0_bist_mode(data)           ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_BIST_MODE_get_dm_b01_1_bist_mode(data)             (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE                                           0x1806B8B4
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_reg_addr                                  "0xB806B8B4"
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_reg                                       0xB806B8B4
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_inst_addr                                 "0x001B"
#define  set_DOLBY_V_TOP_DM_MBIST_DRF_MODE_reg(data)                             (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_MODE_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_DRF_MODE_reg                                   (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_MODE_reg))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_2_1_drf_bist_mode_shift            (8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_hist_drf_bist_mode_shift               (7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b02_2_drf_bist_mode_shift              (6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b05_drf_bist_mode_shift                (5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b03_2_drf_bist_mode_shift              (4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b03_1_drf_bist_mode_shift              (3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b02_1_drf_bist_mode_shift              (2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_2_0_drf_bist_mode_shift            (1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_1_drf_bist_mode_shift              (0)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_2_1_drf_bist_mode_mask             (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_hist_drf_bist_mode_mask                (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b02_2_drf_bist_mode_mask               (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b05_drf_bist_mode_mask                 (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b03_2_drf_bist_mode_mask               (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b03_1_drf_bist_mode_mask               (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b02_1_drf_bist_mode_mask               (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_2_0_drf_bist_mode_mask             (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_1_drf_bist_mode_mask               (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_2_1_drf_bist_mode(data)            (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_hist_drf_bist_mode(data)               (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b02_2_drf_bist_mode(data)              (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b05_drf_bist_mode(data)                (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b03_2_drf_bist_mode(data)              (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b03_1_drf_bist_mode(data)              (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b02_1_drf_bist_mode(data)              (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_2_0_drf_bist_mode(data)            (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_dm_b01_1_drf_bist_mode(data)              (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b01_2_1_drf_bist_mode(data)        ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_hist_drf_bist_mode(data)           ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b02_2_drf_bist_mode(data)          ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b05_drf_bist_mode(data)            ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b03_2_drf_bist_mode(data)          ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b03_1_drf_bist_mode(data)          ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b02_1_drf_bist_mode(data)          ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b01_2_0_drf_bist_mode(data)        ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_MODE_get_dm_b01_1_drf_bist_mode(data)          (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME                                         0x1806B8B8
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_reg_addr                                "0xB806B8B8"
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_reg                                     0xB806B8B8
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_inst_addr                               "0x001C"
#define  set_DOLBY_V_TOP_DM_MBIST_DRF_RESUME_reg(data)                           (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_RESUME_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_DRF_RESUME_reg                                 (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_RESUME_reg))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_2_1_drf_test_resume_shift        (8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_hist_drf_test_resume_shift           (7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b02_2_drf_test_resume_shift          (6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b05_drf_test_resume_shift            (5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b03_2_drf_test_resume_shift          (4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b03_1_drf_test_resume_shift          (3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b02_1_drf_test_resume_shift          (2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_2_0_drf_test_resume_shift        (1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_1_drf_test_resume_shift          (0)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_2_1_drf_test_resume_mask         (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_hist_drf_test_resume_mask            (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b02_2_drf_test_resume_mask           (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b05_drf_test_resume_mask             (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b03_2_drf_test_resume_mask           (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b03_1_drf_test_resume_mask           (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b02_1_drf_test_resume_mask           (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_2_0_drf_test_resume_mask         (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_1_drf_test_resume_mask           (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_2_1_drf_test_resume(data)        (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_hist_drf_test_resume(data)           (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b02_2_drf_test_resume(data)          (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b05_drf_test_resume(data)            (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b03_2_drf_test_resume(data)          (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b03_1_drf_test_resume(data)          (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b02_1_drf_test_resume(data)          (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_2_0_drf_test_resume(data)        (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_dm_b01_1_drf_test_resume(data)          (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b01_2_1_drf_test_resume(data)    ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_hist_drf_test_resume(data)       ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b02_2_drf_test_resume(data)      ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b05_drf_test_resume(data)        ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b03_2_drf_test_resume(data)      ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b03_1_drf_test_resume(data)      ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b02_1_drf_test_resume(data)      ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b01_2_0_drf_test_resume(data)    ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_RESUME_get_dm_b01_1_drf_test_resume(data)      (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE                                          0x1806B8BC
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_reg_addr                                 "0xB806B8BC"
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_reg                                      0xB806B8BC
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_inst_addr                                "0x001D"
#define  set_DOLBY_V_TOP_DM_MBIST_BIST_DONE_reg(data)                            (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_BIST_DONE_reg                                  (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_BIST_DONE_reg))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_2_1_bist_done_shift               (8)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_hist_bist_done_shift                  (7)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b02_2_bist_done_shift                 (6)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b05_bist_done_shift                   (5)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b03_1_bist_done_shift                 (4)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b03_2_bist_done_shift                 (3)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b02_1_bist_done_shift                 (2)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_2_0_bist_done_shift               (1)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_1_bist_done_shift                 (0)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_2_1_bist_done_mask                (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_hist_bist_done_mask                   (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b02_2_bist_done_mask                  (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b05_bist_done_mask                    (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b03_1_bist_done_mask                  (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b03_2_bist_done_mask                  (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b02_1_bist_done_mask                  (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_2_0_bist_done_mask                (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_1_bist_done_mask                  (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_2_1_bist_done(data)               (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_hist_bist_done(data)                  (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b02_2_bist_done(data)                 (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b05_bist_done(data)                   (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b03_1_bist_done(data)                 (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b03_2_bist_done(data)                 (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b02_1_bist_done(data)                 (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_2_0_bist_done(data)               (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_dm_b01_1_bist_done(data)                 (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b01_2_1_bist_done(data)           ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_hist_bist_done(data)              ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b02_2_bist_done(data)             ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b05_bist_done(data)               ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b03_1_bist_done(data)             ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b03_2_bist_done(data)             ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b02_1_bist_done(data)             ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b01_2_0_bist_done(data)           ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_BIST_DONE_get_dm_b01_1_bist_done(data)             (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE                                      0x1806B8C0
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_reg_addr                             "0xB806B8C0"
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_reg                                  0xB806B8C0
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_inst_addr                            "0x001E"
#define  set_DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_reg(data)                        (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_reg                              (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_reg))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_2_1_drf_bist_done_shift       (8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_hist_drf_bist_done_shift          (7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b02_2_drf_bist_done_shift         (6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b05_drf_bist_done_shift           (5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b03_1_drf_bist_done_shift         (4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b03_2_drf_bist_done_shift         (3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b02_1_drf_bist_done_shift         (2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_2_0_drf_bist_done_shift       (1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_1_drf_bist_done_shift         (0)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_2_1_drf_bist_done_mask        (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_hist_drf_bist_done_mask           (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b02_2_drf_bist_done_mask          (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b05_drf_bist_done_mask            (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b03_1_drf_bist_done_mask          (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b03_2_drf_bist_done_mask          (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b02_1_drf_bist_done_mask          (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_2_0_drf_bist_done_mask        (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_1_drf_bist_done_mask          (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_2_1_drf_bist_done(data)       (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_hist_drf_bist_done(data)          (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b02_2_drf_bist_done(data)         (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b05_drf_bist_done(data)           (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b03_1_drf_bist_done(data)         (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b03_2_drf_bist_done(data)         (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b02_1_drf_bist_done(data)         (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_2_0_drf_bist_done(data)       (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_dm_b01_1_drf_bist_done(data)         (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b01_2_1_drf_bist_done(data)   ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_hist_drf_bist_done(data)      ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b02_2_drf_bist_done(data)     ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b05_drf_bist_done(data)       ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b03_1_drf_bist_done(data)     ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b03_2_drf_bist_done(data)     ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b02_1_drf_bist_done(data)     ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b01_2_0_drf_bist_done(data)   ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_DONE_get_dm_b01_1_drf_bist_done(data)     (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE                                          0x1806B8C4
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_reg_addr                                 "0xB806B8C4"
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_reg                                      0xB806B8C4
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_inst_addr                                "0x001F"
#define  set_DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_reg(data)                            (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_reg                                  (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_reg))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_2_1_drf_start_pause_shift         (8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_hist_drf_start_pause_shift            (7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b02_2_drf_start_pause_shift           (6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b05_drf_start_pause_shift             (5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b03_2_drf_start_pause_shift           (4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b03_1_drf_start_pause_shift           (3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b02_1_drf_start_pause_shift           (2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_2_0_drf_start_pause_shift         (1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_1_drf_start_pause_shift           (0)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_2_1_drf_start_pause_mask          (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_hist_drf_start_pause_mask             (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b02_2_drf_start_pause_mask            (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b05_drf_start_pause_mask              (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b03_2_drf_start_pause_mask            (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b03_1_drf_start_pause_mask            (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b02_1_drf_start_pause_mask            (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_2_0_drf_start_pause_mask          (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_1_drf_start_pause_mask            (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_2_1_drf_start_pause(data)         (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_hist_drf_start_pause(data)            (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b02_2_drf_start_pause(data)           (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b05_drf_start_pause(data)             (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b03_2_drf_start_pause(data)           (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b03_1_drf_start_pause(data)           (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b02_1_drf_start_pause(data)           (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_2_0_drf_start_pause(data)         (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_dm_b01_1_drf_start_pause(data)           (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b01_2_1_drf_start_pause(data)     ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_hist_drf_start_pause(data)        ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b02_2_drf_start_pause(data)       ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b05_drf_start_pause(data)         ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b03_2_drf_start_pause(data)       ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b03_1_drf_start_pause(data)       ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b02_1_drf_start_pause(data)       ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b01_2_0_drf_start_pause(data)     ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_PAUSE_get_dm_b01_1_drf_start_pause(data)       (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP                                    0x1806B8C8
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_reg_addr                           "0xB806B8C8"
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_reg                                0xB806B8C8
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_inst_addr                          "0x0020"
#define  set_DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_reg(data)                      (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_reg                            (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_reg))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_2_1_bist_fail_group_shift   (8)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_hist_bist_fail_group_shift      (7)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b02_2_bist_fail_group_shift     (6)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b05_bist_fail_group_shift       (5)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b03_2_bist_fail_group_shift     (4)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b03_1_bist_fail_group_shift     (3)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b02_1_bist_fail_group_shift     (2)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_2_0_bist_fail_group_shift   (1)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_1_bist_fail_group_shift     (0)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_2_1_bist_fail_group_mask    (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_hist_bist_fail_group_mask       (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b02_2_bist_fail_group_mask      (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b05_bist_fail_group_mask        (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b03_2_bist_fail_group_mask      (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b03_1_bist_fail_group_mask      (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b02_1_bist_fail_group_mask      (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_2_0_bist_fail_group_mask    (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_1_bist_fail_group_mask      (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_2_1_bist_fail_group(data)   (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_hist_bist_fail_group(data)      (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b02_2_bist_fail_group(data)     (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b05_bist_fail_group(data)       (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b03_2_bist_fail_group(data)     (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b03_1_bist_fail_group(data)     (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b02_1_bist_fail_group(data)     (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_2_0_bist_fail_group(data)   (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_dm_b01_1_bist_fail_group(data)     (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b01_2_1_bist_fail_group(data) ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_hist_bist_fail_group(data)  ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b02_2_bist_fail_group(data) ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b05_bist_fail_group(data)   ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b03_2_bist_fail_group(data) ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b03_1_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b02_1_bist_fail_group(data) ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b01_2_0_bist_fail_group(data) ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_BIST_FAIL_GROUP_get_dm_b01_1_bist_fail_group(data) (0x00000001&(data))

#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP                                0x1806B8CC
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_reg_addr                       "0xB806B8CC"
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_reg                            0xB806B8CC
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_inst_addr                      "0x0021"
#define  set_DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_reg(data)                  (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_reg)=data)
#define  get_DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_reg                        (*((volatile unsigned int*)DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_reg))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_2_1_drf_bist_fail_group_shift (8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_hist_drf_bist_fail_group_shift (7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b02_2_drf_bist_fail_group_shift (6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b05_drf_bist_fail_group_shift (5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b03_2_drf_bist_fail_group_shift (4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b03_1_drf_bist_fail_group_shift (3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b02_1_drf_bist_fail_group_shift (2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_2_0_drf_bist_fail_group_shift (1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_1_drf_bist_fail_group_shift (0)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_2_1_drf_bist_fail_group_mask (0x00000100)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_hist_drf_bist_fail_group_mask (0x00000080)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b02_2_drf_bist_fail_group_mask (0x00000040)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b05_drf_bist_fail_group_mask (0x00000020)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b03_2_drf_bist_fail_group_mask (0x00000010)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b03_1_drf_bist_fail_group_mask (0x00000008)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b02_1_drf_bist_fail_group_mask (0x00000004)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_2_0_drf_bist_fail_group_mask (0x00000002)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_1_drf_bist_fail_group_mask (0x00000001)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_2_1_drf_bist_fail_group(data) (0x00000100&((data)<<8))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_hist_drf_bist_fail_group(data) (0x00000080&((data)<<7))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b02_2_drf_bist_fail_group(data) (0x00000040&((data)<<6))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b05_drf_bist_fail_group(data) (0x00000020&((data)<<5))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b03_2_drf_bist_fail_group(data) (0x00000010&((data)<<4))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b03_1_drf_bist_fail_group(data) (0x00000008&((data)<<3))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b02_1_drf_bist_fail_group(data) (0x00000004&((data)<<2))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_2_0_drf_bist_fail_group(data) (0x00000002&((data)<<1))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_dm_b01_1_drf_bist_fail_group(data) (0x00000001&(data))
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b01_2_1_drf_bist_fail_group(data) ((0x00000100&(data))>>8)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_hist_drf_bist_fail_group(data) ((0x00000080&(data))>>7)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b02_2_drf_bist_fail_group(data) ((0x00000040&(data))>>6)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b05_drf_bist_fail_group(data) ((0x00000020&(data))>>5)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b03_2_drf_bist_fail_group(data) ((0x00000010&(data))>>4)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b03_1_drf_bist_fail_group(data) ((0x00000008&(data))>>3)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b02_1_drf_bist_fail_group(data) ((0x00000004&(data))>>2)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b01_2_0_drf_bist_fail_group(data) ((0x00000002&(data))>>1)
#define  DOLBY_V_TOP_DM_MBIST_DRF_BIST_FAIL_GROUP_get_dm_b01_1_drf_bist_fail_group(data) (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DOLBY_V_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dolby_v_read_sel:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  end_out_mux:1;
        RBus_UInt32  sel_sign_2:1;
        RBus_UInt32  cr_dly_cb_2:1;
        RBus_UInt32  dup_2:1;
        RBus_UInt32  en_422to444_2:1;
        RBus_UInt32  sel_sign_1:1;
        RBus_UInt32  cr_dly_cb_1:1;
        RBus_UInt32  dup_1:1;
        RBus_UInt32  en_422to444_1:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  bl_el_layer:1;
        RBus_UInt32  hdmi_in_mux:1;
        RBus_UInt32  dolby_ratio:1;
        RBus_UInt32  dolby_mode:3;
    };
}dolby_v_top_top_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dolby_vsize:12;
        RBus_UInt32  res2:3;
        RBus_UInt32  dolby_hsize:13;
    };
}dolby_v_top_top_pic_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  dolby_h_total:13;
    };
}dolby_v_top_top_pic_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dolby_v_den_sta:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  dolby_h_den_sta:12;
    };
}dolby_v_top_top_pic_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  dolby_double_apply:1;
        RBus_UInt32  dolby_double_en:1;
    };
}dolby_v_top_top_d_buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crop_v_en_sub:1;
        RBus_UInt32  crop_h_en_sub:1;
        RBus_UInt32  crop_v_en:1;
        RBus_UInt32  crop_h_en:1;
        RBus_UInt32  res1:28;
    };
}dolby_v_top_top_pic_size_crop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  efuse_in:2;
        RBus_UInt32  sen_fifo_uf:1;
    };
}dolby_v_top_sensio_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_bist_sub_3_mode:1;
        RBus_UInt32  sensio_bist_sub_2_mode:1;
        RBus_UInt32  sensio_bist_sub_1_mode:1;
        RBus_UInt32  sensio_bist_sub_0_mode:1;
        RBus_UInt32  sensio_bist_3_mode:1;
        RBus_UInt32  sensio_bist_2_mode:1;
        RBus_UInt32  sensio_bist_1_mode:1;
        RBus_UInt32  sensio_bist_0_mode:1;
    };
}dolby_v_top_sensio_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_bist_sub_3_done:1;
        RBus_UInt32  sensio_bist_sub_2_done:1;
        RBus_UInt32  sensio_bist_sub_1_done:1;
        RBus_UInt32  sensio_bist_sub_0_done:1;
        RBus_UInt32  sensio_bist_3_done:1;
        RBus_UInt32  sensio_bist_2_done:1;
        RBus_UInt32  sensio_bist_1_done:1;
        RBus_UInt32  sensio_bist_0_done:1;
    };
}dolby_v_top_sensio_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_bist_fail_sub_3_group:1;
        RBus_UInt32  sensio_bist_fail_sub_2_group:1;
        RBus_UInt32  sensio_bist_fail_sub_1_group:1;
        RBus_UInt32  sensio_bist_fail_sub_0_group:1;
        RBus_UInt32  sensio_bist_fail_3_group:1;
        RBus_UInt32  sensio_bist_fail_2_group:1;
        RBus_UInt32  sensio_bist_fail_1_group:1;
        RBus_UInt32  sensio_bist_fail_0_group:1;
    };
}dolby_v_top_sensio_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_drf_sub_3_mode:1;
        RBus_UInt32  sensio_drf_sub_2_mode:1;
        RBus_UInt32  sensio_drf_sub_1_mode:1;
        RBus_UInt32  sensio_drf_sub_0_mode:1;
        RBus_UInt32  sensio_drf_3_mode:1;
        RBus_UInt32  sensio_drf_2_mode:1;
        RBus_UInt32  sensio_drf_1_mode:1;
        RBus_UInt32  sensio_drf_0_mode:1;
    };
}dolby_v_top_sensio_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_drf_sub_3_resume:1;
        RBus_UInt32  sensio_drf_sub_2_resume:1;
        RBus_UInt32  sensio_drf_sub_1_resume:1;
        RBus_UInt32  sensio_drf_sub_0_resume:1;
        RBus_UInt32  sensio_drf_3_resume:1;
        RBus_UInt32  sensio_drf_2_resume:1;
        RBus_UInt32  sensio_drf_1_resume:1;
        RBus_UInt32  sensio_drf_0_resume:1;
    };
}dolby_v_top_sensio_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_drf_sub_3_done:1;
        RBus_UInt32  sensio_drf_sub_2_done:1;
        RBus_UInt32  sensio_drf_sub_1_done:1;
        RBus_UInt32  sensio_drf_sub_0_done:1;
        RBus_UInt32  sensio_drf_3_done:1;
        RBus_UInt32  sensio_drf_2_done:1;
        RBus_UInt32  sensio_drf_1_done:1;
        RBus_UInt32  sensio_drf_0_done:1;
    };
}dolby_v_top_sensio_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_drf_sub_3_pause:1;
        RBus_UInt32  sensio_drf_sub_2_pause:1;
        RBus_UInt32  sensio_drf_sub_1_pause:1;
        RBus_UInt32  sensio_drf_sub_0_pause:1;
        RBus_UInt32  sensio_drf_3_pause:1;
        RBus_UInt32  sensio_drf_2_pause:1;
        RBus_UInt32  sensio_drf_1_pause:1;
        RBus_UInt32  sensio_drf_0_pause:1;
    };
}dolby_v_top_sensio_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  sensio_drf_fail_sub_3_group:1;
        RBus_UInt32  sensio_drf_fail_sub_2_group:1;
        RBus_UInt32  sensio_drf_fail_sub_1_group:1;
        RBus_UInt32  sensio_drf_fail_sub_0_group:1;
        RBus_UInt32  sensio_drf_fail_3_group:1;
        RBus_UInt32  sensio_drf_fail_2_group:1;
        RBus_UInt32  sensio_drf_fail_1_group:1;
        RBus_UInt32  sensio_drf_fail_0_group:1;
    };
}dolby_v_top_sensio_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  composer_bl_bist_mode:3;
    };
}dolby_v_top_composer_bl_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  composer_bl_drf_bist_mode:3;
    };
}dolby_v_top_composer_bl_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  composer_bl_drf_test_resume:3;
    };
}dolby_v_top_composer_bl_drf_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  composer_bl_bist_fail_group:1;
        RBus_UInt32  composer_bl_bist_done:3;
    };
}dolby_v_top_composer_bl_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  composer_bl_drf_bist_fail_group:1;
        RBus_UInt32  composer_bl_drf_bist_done:3;
    };
}dolby_v_top_composer_bl_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  composer_bl_drf_start_pause:3;
    };
}dolby_v_top_composer_bl_drf_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_bist_mode:19;
    };
}dolby_v_top_composer_el_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_drf_bist_mode:19;
    };
}dolby_v_top_composer_el_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_drf_test_resume:19;
    };
}dolby_v_top_composer_el_drf_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  composer_el_bist_fail_group:1;
        RBus_UInt32  composer_el_bist_done:19;
    };
}dolby_v_top_composer_el_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  composer_el_drf_bist_fail_group:1;
        RBus_UInt32  composer_el_drf_bist_done:19;
    };
}dolby_v_top_composer_el_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  composer_el_drf_start_pause:19;
    };
}dolby_v_top_composer_el_drf_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_bist_mode:1;
        RBus_UInt32  dm_hist_bist_mode:1;
        RBus_UInt32  dm_b02_2_bist_mode:1;
        RBus_UInt32  dm_b05_bist_mode:1;
        RBus_UInt32  dm_b03_2_bist_mode:1;
        RBus_UInt32  dm_b03_1_bist_mode:1;
        RBus_UInt32  dm_b02_1_bist_mode:1;
        RBus_UInt32  dm_b01_2_0_bist_mode:1;
        RBus_UInt32  dm_b01_1_bist_mode:1;
    };
}dolby_v_top_dm_mbist_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_drf_bist_mode:1;
        RBus_UInt32  dm_hist_drf_bist_mode:1;
        RBus_UInt32  dm_b02_2_drf_bist_mode:1;
        RBus_UInt32  dm_b05_drf_bist_mode:1;
        RBus_UInt32  dm_b03_2_drf_bist_mode:1;
        RBus_UInt32  dm_b03_1_drf_bist_mode:1;
        RBus_UInt32  dm_b02_1_drf_bist_mode:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_mode:1;
        RBus_UInt32  dm_b01_1_drf_bist_mode:1;
    };
}dolby_v_top_dm_mbist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_drf_test_resume:1;
        RBus_UInt32  dm_hist_drf_test_resume:1;
        RBus_UInt32  dm_b02_2_drf_test_resume:1;
        RBus_UInt32  dm_b05_drf_test_resume:1;
        RBus_UInt32  dm_b03_2_drf_test_resume:1;
        RBus_UInt32  dm_b03_1_drf_test_resume:1;
        RBus_UInt32  dm_b02_1_drf_test_resume:1;
        RBus_UInt32  dm_b01_2_0_drf_test_resume:1;
        RBus_UInt32  dm_b01_1_drf_test_resume:1;
    };
}dolby_v_top_dm_mbist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_bist_done:1;
        RBus_UInt32  dm_hist_bist_done:1;
        RBus_UInt32  dm_b02_2_bist_done:1;
        RBus_UInt32  dm_b05_bist_done:1;
        RBus_UInt32  dm_b03_1_bist_done:1;
        RBus_UInt32  dm_b03_2_bist_done:1;
        RBus_UInt32  dm_b02_1_bist_done:1;
        RBus_UInt32  dm_b01_2_0_bist_done:1;
        RBus_UInt32  dm_b01_1_bist_done:1;
    };
}dolby_v_top_dm_mbist_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_drf_bist_done:1;
        RBus_UInt32  dm_hist_drf_bist_done:1;
        RBus_UInt32  dm_b02_2_drf_bist_done:1;
        RBus_UInt32  dm_b05_drf_bist_done:1;
        RBus_UInt32  dm_b03_1_drf_bist_done:1;
        RBus_UInt32  dm_b03_2_drf_bist_done:1;
        RBus_UInt32  dm_b02_1_drf_bist_done:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_done:1;
        RBus_UInt32  dm_b01_1_drf_bist_done:1;
    };
}dolby_v_top_dm_mbist_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_drf_start_pause:1;
        RBus_UInt32  dm_hist_drf_start_pause:1;
        RBus_UInt32  dm_b02_2_drf_start_pause:1;
        RBus_UInt32  dm_b05_drf_start_pause:1;
        RBus_UInt32  dm_b03_2_drf_start_pause:1;
        RBus_UInt32  dm_b03_1_drf_start_pause:1;
        RBus_UInt32  dm_b02_1_drf_start_pause:1;
        RBus_UInt32  dm_b01_2_0_drf_start_pause:1;
        RBus_UInt32  dm_b01_1_drf_start_pause:1;
    };
}dolby_v_top_dm_mbist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_bist_fail_group:1;
        RBus_UInt32  dm_hist_bist_fail_group:1;
        RBus_UInt32  dm_b02_2_bist_fail_group:1;
        RBus_UInt32  dm_b05_bist_fail_group:1;
        RBus_UInt32  dm_b03_2_bist_fail_group:1;
        RBus_UInt32  dm_b03_1_bist_fail_group:1;
        RBus_UInt32  dm_b02_1_bist_fail_group:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_group:1;
        RBus_UInt32  dm_b01_1_bist_fail_group:1;
    };
}dolby_v_top_dm_mbist_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_group:1;
        RBus_UInt32  dm_hist_drf_bist_fail_group:1;
        RBus_UInt32  dm_b02_2_drf_bist_fail_group:1;
        RBus_UInt32  dm_b05_drf_bist_fail_group:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_group:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_group:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_group:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_group:1;
        RBus_UInt32  dm_b01_1_drf_bist_fail_group:1;
    };
}dolby_v_top_dm_mbist_drf_bist_fail_group_RBUS;

#else //apply LITTLE_ENDIAN

//======DOLBY_V_TOP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dolby_mode:3;
        RBus_UInt32  dolby_ratio:1;
        RBus_UInt32  hdmi_in_mux:1;
        RBus_UInt32  bl_el_layer:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  en_422to444_1:1;
        RBus_UInt32  dup_1:1;
        RBus_UInt32  cr_dly_cb_1:1;
        RBus_UInt32  sel_sign_1:1;
        RBus_UInt32  en_422to444_2:1;
        RBus_UInt32  dup_2:1;
        RBus_UInt32  cr_dly_cb_2:1;
        RBus_UInt32  sel_sign_2:1;
        RBus_UInt32  end_out_mux:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  dolby_v_read_sel:1;
    };
}dolby_v_top_top_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dolby_hsize:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  dolby_vsize:12;
        RBus_UInt32  res2:4;
    };
}dolby_v_top_top_pic_size_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dolby_h_total:13;
        RBus_UInt32  res1:19;
    };
}dolby_v_top_top_pic_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dolby_h_den_sta:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  dolby_v_den_sta:8;
        RBus_UInt32  res2:8;
    };
}dolby_v_top_top_pic_sta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dolby_double_en:1;
        RBus_UInt32  dolby_double_apply:1;
        RBus_UInt32  res1:30;
    };
}dolby_v_top_top_d_buf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  crop_h_en:1;
        RBus_UInt32  crop_v_en:1;
        RBus_UInt32  crop_h_en_sub:1;
        RBus_UInt32  crop_v_en_sub:1;
    };
}dolby_v_top_top_pic_size_crop_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sen_fifo_uf:1;
        RBus_UInt32  efuse_in:2;
        RBus_UInt32  res1:29;
    };
}dolby_v_top_sensio_fifo_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_bist_0_mode:1;
        RBus_UInt32  sensio_bist_1_mode:1;
        RBus_UInt32  sensio_bist_2_mode:1;
        RBus_UInt32  sensio_bist_3_mode:1;
        RBus_UInt32  sensio_bist_sub_0_mode:1;
        RBus_UInt32  sensio_bist_sub_1_mode:1;
        RBus_UInt32  sensio_bist_sub_2_mode:1;
        RBus_UInt32  sensio_bist_sub_3_mode:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_bist_0_done:1;
        RBus_UInt32  sensio_bist_1_done:1;
        RBus_UInt32  sensio_bist_2_done:1;
        RBus_UInt32  sensio_bist_3_done:1;
        RBus_UInt32  sensio_bist_sub_0_done:1;
        RBus_UInt32  sensio_bist_sub_1_done:1;
        RBus_UInt32  sensio_bist_sub_2_done:1;
        RBus_UInt32  sensio_bist_sub_3_done:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_bist_fail_0_group:1;
        RBus_UInt32  sensio_bist_fail_1_group:1;
        RBus_UInt32  sensio_bist_fail_2_group:1;
        RBus_UInt32  sensio_bist_fail_3_group:1;
        RBus_UInt32  sensio_bist_fail_sub_0_group:1;
        RBus_UInt32  sensio_bist_fail_sub_1_group:1;
        RBus_UInt32  sensio_bist_fail_sub_2_group:1;
        RBus_UInt32  sensio_bist_fail_sub_3_group:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_drf_0_mode:1;
        RBus_UInt32  sensio_drf_1_mode:1;
        RBus_UInt32  sensio_drf_2_mode:1;
        RBus_UInt32  sensio_drf_3_mode:1;
        RBus_UInt32  sensio_drf_sub_0_mode:1;
        RBus_UInt32  sensio_drf_sub_1_mode:1;
        RBus_UInt32  sensio_drf_sub_2_mode:1;
        RBus_UInt32  sensio_drf_sub_3_mode:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_drf_0_resume:1;
        RBus_UInt32  sensio_drf_1_resume:1;
        RBus_UInt32  sensio_drf_2_resume:1;
        RBus_UInt32  sensio_drf_3_resume:1;
        RBus_UInt32  sensio_drf_sub_0_resume:1;
        RBus_UInt32  sensio_drf_sub_1_resume:1;
        RBus_UInt32  sensio_drf_sub_2_resume:1;
        RBus_UInt32  sensio_drf_sub_3_resume:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_drf_0_done:1;
        RBus_UInt32  sensio_drf_1_done:1;
        RBus_UInt32  sensio_drf_2_done:1;
        RBus_UInt32  sensio_drf_3_done:1;
        RBus_UInt32  sensio_drf_sub_0_done:1;
        RBus_UInt32  sensio_drf_sub_1_done:1;
        RBus_UInt32  sensio_drf_sub_2_done:1;
        RBus_UInt32  sensio_drf_sub_3_done:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_drf_0_pause:1;
        RBus_UInt32  sensio_drf_1_pause:1;
        RBus_UInt32  sensio_drf_2_pause:1;
        RBus_UInt32  sensio_drf_3_pause:1;
        RBus_UInt32  sensio_drf_sub_0_pause:1;
        RBus_UInt32  sensio_drf_sub_1_pause:1;
        RBus_UInt32  sensio_drf_sub_2_pause:1;
        RBus_UInt32  sensio_drf_sub_3_pause:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sensio_drf_fail_0_group:1;
        RBus_UInt32  sensio_drf_fail_1_group:1;
        RBus_UInt32  sensio_drf_fail_2_group:1;
        RBus_UInt32  sensio_drf_fail_3_group:1;
        RBus_UInt32  sensio_drf_fail_sub_0_group:1;
        RBus_UInt32  sensio_drf_fail_sub_1_group:1;
        RBus_UInt32  sensio_drf_fail_sub_2_group:1;
        RBus_UInt32  sensio_drf_fail_sub_3_group:1;
        RBus_UInt32  res1:24;
    };
}dolby_v_top_sensio_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_bist_mode:3;
        RBus_UInt32  res1:29;
    };
}dolby_v_top_composer_bl_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_drf_bist_mode:3;
        RBus_UInt32  res1:29;
    };
}dolby_v_top_composer_bl_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_drf_test_resume:3;
        RBus_UInt32  res1:29;
    };
}dolby_v_top_composer_bl_drf_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_bist_done:3;
        RBus_UInt32  composer_bl_bist_fail_group:1;
        RBus_UInt32  res1:28;
    };
}dolby_v_top_composer_bl_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_drf_bist_done:3;
        RBus_UInt32  composer_bl_drf_bist_fail_group:1;
        RBus_UInt32  res1:28;
    };
}dolby_v_top_composer_bl_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_bl_drf_start_pause:3;
        RBus_UInt32  res1:29;
    };
}dolby_v_top_composer_bl_drf_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_bist_mode:19;
        RBus_UInt32  res1:13;
    };
}dolby_v_top_composer_el_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_drf_bist_mode:19;
        RBus_UInt32  res1:13;
    };
}dolby_v_top_composer_el_drf_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_drf_test_resume:19;
        RBus_UInt32  res1:13;
    };
}dolby_v_top_composer_el_drf_test_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_bist_done:19;
        RBus_UInt32  composer_el_bist_fail_group:1;
        RBus_UInt32  res1:12;
    };
}dolby_v_top_composer_el_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_drf_bist_done:19;
        RBus_UInt32  composer_el_drf_bist_fail_group:1;
        RBus_UInt32  res1:12;
    };
}dolby_v_top_composer_el_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  composer_el_drf_start_pause:19;
        RBus_UInt32  res1:13;
    };
}dolby_v_top_composer_el_drf_start_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_bist_mode:1;
        RBus_UInt32  dm_b01_2_0_bist_mode:1;
        RBus_UInt32  dm_b02_1_bist_mode:1;
        RBus_UInt32  dm_b03_1_bist_mode:1;
        RBus_UInt32  dm_b03_2_bist_mode:1;
        RBus_UInt32  dm_b05_bist_mode:1;
        RBus_UInt32  dm_b02_2_bist_mode:1;
        RBus_UInt32  dm_hist_bist_mode:1;
        RBus_UInt32  dm_b01_2_1_bist_mode:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_drf_bist_mode:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_mode:1;
        RBus_UInt32  dm_b02_1_drf_bist_mode:1;
        RBus_UInt32  dm_b03_1_drf_bist_mode:1;
        RBus_UInt32  dm_b03_2_drf_bist_mode:1;
        RBus_UInt32  dm_b05_drf_bist_mode:1;
        RBus_UInt32  dm_b02_2_drf_bist_mode:1;
        RBus_UInt32  dm_hist_drf_bist_mode:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_mode:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_drf_test_resume:1;
        RBus_UInt32  dm_b01_2_0_drf_test_resume:1;
        RBus_UInt32  dm_b02_1_drf_test_resume:1;
        RBus_UInt32  dm_b03_1_drf_test_resume:1;
        RBus_UInt32  dm_b03_2_drf_test_resume:1;
        RBus_UInt32  dm_b05_drf_test_resume:1;
        RBus_UInt32  dm_b02_2_drf_test_resume:1;
        RBus_UInt32  dm_hist_drf_test_resume:1;
        RBus_UInt32  dm_b01_2_1_drf_test_resume:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_bist_done:1;
        RBus_UInt32  dm_b01_2_0_bist_done:1;
        RBus_UInt32  dm_b02_1_bist_done:1;
        RBus_UInt32  dm_b03_2_bist_done:1;
        RBus_UInt32  dm_b03_1_bist_done:1;
        RBus_UInt32  dm_b05_bist_done:1;
        RBus_UInt32  dm_b02_2_bist_done:1;
        RBus_UInt32  dm_hist_bist_done:1;
        RBus_UInt32  dm_b01_2_1_bist_done:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_drf_bist_done:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_done:1;
        RBus_UInt32  dm_b02_1_drf_bist_done:1;
        RBus_UInt32  dm_b03_2_drf_bist_done:1;
        RBus_UInt32  dm_b03_1_drf_bist_done:1;
        RBus_UInt32  dm_b05_drf_bist_done:1;
        RBus_UInt32  dm_b02_2_drf_bist_done:1;
        RBus_UInt32  dm_hist_drf_bist_done:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_done:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_drf_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_drf_start_pause:1;
        RBus_UInt32  dm_b01_2_0_drf_start_pause:1;
        RBus_UInt32  dm_b02_1_drf_start_pause:1;
        RBus_UInt32  dm_b03_1_drf_start_pause:1;
        RBus_UInt32  dm_b03_2_drf_start_pause:1;
        RBus_UInt32  dm_b05_drf_start_pause:1;
        RBus_UInt32  dm_b02_2_drf_start_pause:1;
        RBus_UInt32  dm_hist_drf_start_pause:1;
        RBus_UInt32  dm_b01_2_1_drf_start_pause:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_bist_fail_group:1;
        RBus_UInt32  dm_b01_2_0_bist_fail_group:1;
        RBus_UInt32  dm_b02_1_bist_fail_group:1;
        RBus_UInt32  dm_b03_1_bist_fail_group:1;
        RBus_UInt32  dm_b03_2_bist_fail_group:1;
        RBus_UInt32  dm_b05_bist_fail_group:1;
        RBus_UInt32  dm_b02_2_bist_fail_group:1;
        RBus_UInt32  dm_hist_bist_fail_group:1;
        RBus_UInt32  dm_b01_2_1_bist_fail_group:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dm_b01_1_drf_bist_fail_group:1;
        RBus_UInt32  dm_b01_2_0_drf_bist_fail_group:1;
        RBus_UInt32  dm_b02_1_drf_bist_fail_group:1;
        RBus_UInt32  dm_b03_1_drf_bist_fail_group:1;
        RBus_UInt32  dm_b03_2_drf_bist_fail_group:1;
        RBus_UInt32  dm_b05_drf_bist_fail_group:1;
        RBus_UInt32  dm_b02_2_drf_bist_fail_group:1;
        RBus_UInt32  dm_hist_drf_bist_fail_group:1;
        RBus_UInt32  dm_b01_2_1_drf_bist_fail_group:1;
        RBus_UInt32  res1:23;
    };
}dolby_v_top_dm_mbist_drf_bist_fail_group_RBUS;




#endif 


#endif 
