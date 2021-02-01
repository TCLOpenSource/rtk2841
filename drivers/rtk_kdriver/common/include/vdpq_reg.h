/**
* @file Mac5-DesignSpec-VideoDecoder_PQ
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VDPQ_REG_H_
#define _RBUS_VDPQ_REG_H_

#include "rbus_types.h"



//  VDPQ Register Address
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0                                              0x18019800
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_reg_addr                                     "0xB8019800"
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_reg                                          0xB8019800
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_inst_addr                                    "0x0000"
#define  set_VDPQ_FRAME_BUF_CHK3D_CTRL0_reg(data)                                (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CTRL0_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_CTRL0_reg                                      (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CTRL0_reg))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_f_num_chk_3d_sel_shift                       (6)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_f_hennum_range_shift                         (0)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_f_num_chk_3d_sel_mask                        (0x000000C0)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_f_hennum_range_mask                          (0x0000003F)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_f_num_chk_3d_sel(data)                       (0x000000C0&((data)<<6))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_f_hennum_range(data)                         (0x0000003F&(data))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_get_f_num_chk_3d_sel(data)                   ((0x000000C0&(data))>>6)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_get_f_hennum_range(data)                     (0x0000003F&(data))

#define  VDPQ_FRAME_BUF_CHK3D_CTRL1                                              0x18019804
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_reg_addr                                     "0xB8019804"
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_reg                                          0xB8019804
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_inst_addr                                    "0x0001"
#define  set_VDPQ_FRAME_BUF_CHK3D_CTRL1_reg(data)                                (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CTRL1_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_CTRL1_reg                                      (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CTRL1_reg))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_num_chk_3d_en_shift                        (7)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_num_3d_fail_det_shift                      (6)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_cennum_range_shift                         (0)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_num_chk_3d_en_mask                         (0x00000080)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_num_3d_fail_det_mask                       (0x00000040)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_cennum_range_mask                          (0x0000003F)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_num_chk_3d_en(data)                        (0x00000080&((data)<<7))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_num_3d_fail_det(data)                      (0x00000040&((data)<<6))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_f_cennum_range(data)                         (0x0000003F&(data))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_get_f_num_chk_3d_en(data)                    ((0x00000080&(data))>>7)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_get_f_num_3d_fail_det(data)                  ((0x00000040&(data))>>6)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_get_f_cennum_range(data)                     (0x0000003F&(data))

#define  VDPQ_FRAME_BUF_CHK3D_CTRL2                                              0x18019808
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_reg_addr                                     "0xB8019808"
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_reg                                          0xB8019808
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_inst_addr                                    "0x0002"
#define  set_VDPQ_FRAME_BUF_CHK3D_CTRL2_reg(data)                                (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CTRL2_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_CTRL2_reg                                      (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CTRL2_reg))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_f_num_open3d_cnt_shift                       (4)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_f_num_close3d_cnt_shift                      (0)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_f_num_open3d_cnt_mask                        (0x000000F0)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_f_num_close3d_cnt_mask                       (0x0000000F)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_f_num_open3d_cnt(data)                       (0x000000F0&((data)<<4))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_f_num_close3d_cnt(data)                      (0x0000000F&(data))
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_get_f_num_open3d_cnt(data)                   ((0x000000F0&(data))>>4)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_get_f_num_close3d_cnt(data)                  (0x0000000F&(data))

#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL                                           0x1801980C
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_reg_addr                                  "0xB801980C"
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_reg                                       0xB801980C
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_inst_addr                                 "0x0003"
#define  set_VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_reg(data)                             (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_reg                                   (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_reg))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid_en_shift                   (2)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid1_en_shift                  (1)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid2_en_shift                  (0)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid_en_mask                    (0x00000004)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid1_en_mask                   (0x00000002)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid2_en_mask                   (0x00000001)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid_en(data)                   (0x00000004&((data)<<2))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid1_en(data)                  (0x00000002&((data)<<1))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_f_cennum_valid2_en(data)                  (0x00000001&(data))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_get_f_cennum_valid_en(data)               ((0x00000004&(data))>>2)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_get_f_cennum_valid1_en(data)              ((0x00000002&(data))>>1)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_get_f_cennum_valid2_en(data)              (0x00000001&(data))

#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE                                      0x18019810
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg_addr                             "0xB8019810"
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg                                  0xB8019810
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_inst_addr                            "0x0004"
#define  set_VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg(data)                        (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg                              (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_reg))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_f_cennum_valid1_num_shift            (0)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_f_cennum_valid1_num_mask             (0x000FFFFF)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_f_cennum_valid1_num(data)            (0x000FFFFF&(data))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_get_f_cennum_valid1_num(data)        (0x000FFFFF&(data))

#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE                                      0x18019814
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg_addr                             "0xB8019814"
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg                                  0xB8019814
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_inst_addr                            "0x0005"
#define  set_VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg(data)                        (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg                              (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_reg))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_f_cennum_valid2_num_shift            (0)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_f_cennum_valid2_num_mask             (0x000FFFFF)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_f_cennum_valid2_num(data)            (0x000FFFFF&(data))
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_get_f_cennum_valid2_num(data)        (0x000FFFFF&(data))

#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL                                      0x18019818
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg_addr                             "0xB8019818"
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg                                  0xB8019818
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_inst_addr                            "0x0006"
#define  set_VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg(data)                        (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg                              (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_reg))
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid_en_shift              (1)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid1_en_shift             (0)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid_en_mask               (0x00000002)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid1_en_mask              (0x00000001)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid_en(data)              (0x00000002&((data)<<1))
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_f_hennum_valid1_en(data)             (0x00000001&(data))
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_get_f_hennum_valid_en(data)          ((0x00000002&(data))>>1)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_get_f_hennum_valid1_en(data)         (0x00000001&(data))

#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE                                      0x1801981C
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg_addr                             "0xB801981C"
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg                                  0xB801981C
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_inst_addr                            "0x0007"
#define  set_VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg(data)                        (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg)=data)
#define  get_VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg                              (*((volatile unsigned int*)VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_reg))
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_f_hennum_valid1_num_shift            (0)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_f_hennum_valid1_num_mask             (0x000FFFFF)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_f_hennum_valid1_num(data)            (0x000FFFFF&(data))
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_get_f_hennum_valid1_num(data)        (0x000FFFFF&(data))

#define  VDPQ_DMA_VACTIVE_ST1                                                    0x18019830
#define  VDPQ_DMA_VACTIVE_ST1_reg_addr                                           "0xB8019830"
#define  VDPQ_DMA_VACTIVE_ST1_reg                                                0xB8019830
#define  VDPQ_DMA_VACTIVE_ST1_inst_addr                                          "0x0008"
#define  set_VDPQ_DMA_VACTIVE_ST1_reg(data)                                      (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_ST1_reg)=data)
#define  get_VDPQ_DMA_VACTIVE_ST1_reg                                            (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_ST1_reg))
#define  VDPQ_DMA_VACTIVE_ST1_vactive_grid_st1_shift                             (16)
#define  VDPQ_DMA_VACTIVE_ST1_vactive_st1_shift                                  (0)
#define  VDPQ_DMA_VACTIVE_ST1_vactive_grid_st1_mask                              (0x03FF0000)
#define  VDPQ_DMA_VACTIVE_ST1_vactive_st1_mask                                   (0x000003FF)
#define  VDPQ_DMA_VACTIVE_ST1_vactive_grid_st1(data)                             (0x03FF0000&((data)<<16))
#define  VDPQ_DMA_VACTIVE_ST1_vactive_st1(data)                                  (0x000003FF&(data))
#define  VDPQ_DMA_VACTIVE_ST1_get_vactive_grid_st1(data)                         ((0x03FF0000&(data))>>16)
#define  VDPQ_DMA_VACTIVE_ST1_get_vactive_st1(data)                              (0x000003FF&(data))

#define  VDPQ_DMA_VACTIVE_END1                                                   0x18019834
#define  VDPQ_DMA_VACTIVE_END1_reg_addr                                          "0xB8019834"
#define  VDPQ_DMA_VACTIVE_END1_reg                                               0xB8019834
#define  VDPQ_DMA_VACTIVE_END1_inst_addr                                         "0x0009"
#define  set_VDPQ_DMA_VACTIVE_END1_reg(data)                                     (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_END1_reg)=data)
#define  get_VDPQ_DMA_VACTIVE_END1_reg                                           (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_END1_reg))
#define  VDPQ_DMA_VACTIVE_END1_vactive_grid_end1_shift                           (16)
#define  VDPQ_DMA_VACTIVE_END1_vactive_end1_shift                                (0)
#define  VDPQ_DMA_VACTIVE_END1_vactive_grid_end1_mask                            (0x03FF0000)
#define  VDPQ_DMA_VACTIVE_END1_vactive_end1_mask                                 (0x000003FF)
#define  VDPQ_DMA_VACTIVE_END1_vactive_grid_end1(data)                           (0x03FF0000&((data)<<16))
#define  VDPQ_DMA_VACTIVE_END1_vactive_end1(data)                                (0x000003FF&(data))
#define  VDPQ_DMA_VACTIVE_END1_get_vactive_grid_end1(data)                       ((0x03FF0000&(data))>>16)
#define  VDPQ_DMA_VACTIVE_END1_get_vactive_end1(data)                            (0x000003FF&(data))

#define  VDPQ_DMA_VACTIVE_ST2                                                    0x18019838
#define  VDPQ_DMA_VACTIVE_ST2_reg_addr                                           "0xB8019838"
#define  VDPQ_DMA_VACTIVE_ST2_reg                                                0xB8019838
#define  VDPQ_DMA_VACTIVE_ST2_inst_addr                                          "0x000A"
#define  set_VDPQ_DMA_VACTIVE_ST2_reg(data)                                      (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_ST2_reg)=data)
#define  get_VDPQ_DMA_VACTIVE_ST2_reg                                            (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_ST2_reg))
#define  VDPQ_DMA_VACTIVE_ST2_vactive_grid_st2_shift                             (16)
#define  VDPQ_DMA_VACTIVE_ST2_vactive_st2_shift                                  (0)
#define  VDPQ_DMA_VACTIVE_ST2_vactive_grid_st2_mask                              (0x03FF0000)
#define  VDPQ_DMA_VACTIVE_ST2_vactive_st2_mask                                   (0x000003FF)
#define  VDPQ_DMA_VACTIVE_ST2_vactive_grid_st2(data)                             (0x03FF0000&((data)<<16))
#define  VDPQ_DMA_VACTIVE_ST2_vactive_st2(data)                                  (0x000003FF&(data))
#define  VDPQ_DMA_VACTIVE_ST2_get_vactive_grid_st2(data)                         ((0x03FF0000&(data))>>16)
#define  VDPQ_DMA_VACTIVE_ST2_get_vactive_st2(data)                              (0x000003FF&(data))

#define  VDPQ_DMA_VACTIVE_END2                                                   0x1801983C
#define  VDPQ_DMA_VACTIVE_END2_reg_addr                                          "0xB801983C"
#define  VDPQ_DMA_VACTIVE_END2_reg                                               0xB801983C
#define  VDPQ_DMA_VACTIVE_END2_inst_addr                                         "0x000B"
#define  set_VDPQ_DMA_VACTIVE_END2_reg(data)                                     (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_END2_reg)=data)
#define  get_VDPQ_DMA_VACTIVE_END2_reg                                           (*((volatile unsigned int*)VDPQ_DMA_VACTIVE_END2_reg))
#define  VDPQ_DMA_VACTIVE_END2_vactive_grid_end2_shift                           (16)
#define  VDPQ_DMA_VACTIVE_END2_vactive_end2_shift                                (0)
#define  VDPQ_DMA_VACTIVE_END2_vactive_grid_end2_mask                            (0x03FF0000)
#define  VDPQ_DMA_VACTIVE_END2_vactive_end2_mask                                 (0x000003FF)
#define  VDPQ_DMA_VACTIVE_END2_vactive_grid_end2(data)                           (0x03FF0000&((data)<<16))
#define  VDPQ_DMA_VACTIVE_END2_vactive_end2(data)                                (0x000003FF&(data))
#define  VDPQ_DMA_VACTIVE_END2_get_vactive_grid_end2(data)                       ((0x03FF0000&(data))>>16)
#define  VDPQ_DMA_VACTIVE_END2_get_vactive_end2(data)                            (0x000003FF&(data))

#define  VDPQ_DMA_CTRL1                                                          0x18019840
#define  VDPQ_DMA_CTRL1_reg_addr                                                 "0xB8019840"
#define  VDPQ_DMA_CTRL1_reg                                                      0xB8019840
#define  VDPQ_DMA_CTRL1_inst_addr                                                "0x000C"
#define  set_VDPQ_DMA_CTRL1_reg(data)                                            (*((volatile unsigned int*)VDPQ_DMA_CTRL1_reg)=data)
#define  get_VDPQ_DMA_CTRL1_reg                                                  (*((volatile unsigned int*)VDPQ_DMA_CTRL1_reg))
#define  VDPQ_DMA_CTRL1_dma_ctrl_ififo_thr_shift                                 (0)
#define  VDPQ_DMA_CTRL1_dma_ctrl_ififo_thr_mask                                  (0x0000003F)
#define  VDPQ_DMA_CTRL1_dma_ctrl_ififo_thr(data)                                 (0x0000003F&(data))
#define  VDPQ_DMA_CTRL1_get_dma_ctrl_ififo_thr(data)                             (0x0000003F&(data))

#define  VDPQ_DMA_CTRL2                                                          0x18019844
#define  VDPQ_DMA_CTRL2_reg_addr                                                 "0xB8019844"
#define  VDPQ_DMA_CTRL2_reg                                                      0xB8019844
#define  VDPQ_DMA_CTRL2_inst_addr                                                "0x000D"
#define  set_VDPQ_DMA_CTRL2_reg(data)                                            (*((volatile unsigned int*)VDPQ_DMA_CTRL2_reg)=data)
#define  get_VDPQ_DMA_CTRL2_reg                                                  (*((volatile unsigned int*)VDPQ_DMA_CTRL2_reg))
#define  VDPQ_DMA_CTRL2_dma_ctrl_ofifo_thr_shift                                 (0)
#define  VDPQ_DMA_CTRL2_dma_ctrl_ofifo_thr_mask                                  (0x0000003F)
#define  VDPQ_DMA_CTRL2_dma_ctrl_ofifo_thr(data)                                 (0x0000003F&(data))
#define  VDPQ_DMA_CTRL2_get_dma_ctrl_ofifo_thr(data)                             (0x0000003F&(data))

#define  VDPQ_DMA_CTRL3                                                          0x18019848
#define  VDPQ_DMA_CTRL3_reg_addr                                                 "0xB8019848"
#define  VDPQ_DMA_CTRL3_reg                                                      0xB8019848
#define  VDPQ_DMA_CTRL3_inst_addr                                                "0x000E"
#define  set_VDPQ_DMA_CTRL3_reg(data)                                            (*((volatile unsigned int*)VDPQ_DMA_CTRL3_reg)=data)
#define  get_VDPQ_DMA_CTRL3_reg                                                  (*((volatile unsigned int*)VDPQ_DMA_CTRL3_reg))
#define  VDPQ_DMA_CTRL3_dma_ctrl_ceiladr_shift                                   (0)
#define  VDPQ_DMA_CTRL3_dma_ctrl_ceiladr_mask                                    (0x0000003F)
#define  VDPQ_DMA_CTRL3_dma_ctrl_ceiladr(data)                                   (0x0000003F&(data))
#define  VDPQ_DMA_CTRL3_get_dma_ctrl_ceiladr(data)                               (0x0000003F&(data))

#define  VDPQ_DMA_CTRL4                                                          0x1801984C
#define  VDPQ_DMA_CTRL4_reg_addr                                                 "0xB801984C"
#define  VDPQ_DMA_CTRL4_reg                                                      0xB801984C
#define  VDPQ_DMA_CTRL4_inst_addr                                                "0x000F"
#define  set_VDPQ_DMA_CTRL4_reg(data)                                            (*((volatile unsigned int*)VDPQ_DMA_CTRL4_reg)=data)
#define  get_VDPQ_DMA_CTRL4_reg                                                  (*((volatile unsigned int*)VDPQ_DMA_CTRL4_reg))
#define  VDPQ_DMA_CTRL4_dma_3d_on_off_shift                                      (31)
#define  VDPQ_DMA_CTRL4_ntsc443_tune_shift                                       (28)
#define  VDPQ_DMA_CTRL4_dma_vcnt_diff_shift                                      (16)
#define  VDPQ_DMA_CTRL4_dma_vcnt_sft_chk_en_shift                                (15)
#define  VDPQ_DMA_CTRL4_dma_vcnt_sft_thr_shift                                   (8)
#define  VDPQ_DMA_CTRL4_dma_3d_on_vcnt_shift                                     (3)
#define  VDPQ_DMA_CTRL4_dma_ctrl_bstlen_shift                                    (0)
#define  VDPQ_DMA_CTRL4_dma_3d_on_off_mask                                       (0x80000000)
#define  VDPQ_DMA_CTRL4_ntsc443_tune_mask                                        (0x70000000)
#define  VDPQ_DMA_CTRL4_dma_vcnt_diff_mask                                       (0x03FF0000)
#define  VDPQ_DMA_CTRL4_dma_vcnt_sft_chk_en_mask                                 (0x00008000)
#define  VDPQ_DMA_CTRL4_dma_vcnt_sft_thr_mask                                    (0x00001F00)
#define  VDPQ_DMA_CTRL4_dma_3d_on_vcnt_mask                                      (0x000000F8)
#define  VDPQ_DMA_CTRL4_dma_ctrl_bstlen_mask                                     (0x00000007)
#define  VDPQ_DMA_CTRL4_dma_3d_on_off(data)                                      (0x80000000&((data)<<31))
#define  VDPQ_DMA_CTRL4_ntsc443_tune(data)                                       (0x70000000&((data)<<28))
#define  VDPQ_DMA_CTRL4_dma_vcnt_diff(data)                                      (0x03FF0000&((data)<<16))
#define  VDPQ_DMA_CTRL4_dma_vcnt_sft_chk_en(data)                                (0x00008000&((data)<<15))
#define  VDPQ_DMA_CTRL4_dma_vcnt_sft_thr(data)                                   (0x00001F00&((data)<<8))
#define  VDPQ_DMA_CTRL4_dma_3d_on_vcnt(data)                                     (0x000000F8&((data)<<3))
#define  VDPQ_DMA_CTRL4_dma_ctrl_bstlen(data)                                    (0x00000007&(data))
#define  VDPQ_DMA_CTRL4_get_dma_3d_on_off(data)                                  ((0x80000000&(data))>>31)
#define  VDPQ_DMA_CTRL4_get_ntsc443_tune(data)                                   ((0x70000000&(data))>>28)
#define  VDPQ_DMA_CTRL4_get_dma_vcnt_diff(data)                                  ((0x03FF0000&(data))>>16)
#define  VDPQ_DMA_CTRL4_get_dma_vcnt_sft_chk_en(data)                            ((0x00008000&(data))>>15)
#define  VDPQ_DMA_CTRL4_get_dma_vcnt_sft_thr(data)                               ((0x00001F00&(data))>>8)
#define  VDPQ_DMA_CTRL4_get_dma_3d_on_vcnt(data)                                 ((0x000000F8&(data))>>3)
#define  VDPQ_DMA_CTRL4_get_dma_ctrl_bstlen(data)                                (0x00000007&(data))

#define  VDPQ_DMA_CTRL5                                                          0x18019850
#define  VDPQ_DMA_CTRL5_reg_addr                                                 "0xB8019850"
#define  VDPQ_DMA_CTRL5_reg                                                      0xB8019850
#define  VDPQ_DMA_CTRL5_inst_addr                                                "0x0010"
#define  set_VDPQ_DMA_CTRL5_reg(data)                                            (*((volatile unsigned int*)VDPQ_DMA_CTRL5_reg)=data)
#define  get_VDPQ_DMA_CTRL5_reg                                                  (*((volatile unsigned int*)VDPQ_DMA_CTRL5_reg))
#define  VDPQ_DMA_CTRL5_ofifo_err_flag_shift                                     (7)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_1_shift                                   (6)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_2_shift                                   (5)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_3_shift                                   (4)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_4_shift                                   (3)
#define  VDPQ_DMA_CTRL5_mem_off_shift                                            (2)
#define  VDPQ_DMA_CTRL5_mem_test_mode_shift                                      (1)
#define  VDPQ_DMA_CTRL5_mem_test_mode_ok_shift                                   (0)
#define  VDPQ_DMA_CTRL5_ofifo_err_flag_mask                                      (0x00000080)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_1_mask                                    (0x00000040)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_2_mask                                    (0x00000020)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_3_mask                                    (0x00000010)
#define  VDPQ_DMA_CTRL5_ififo_err_flag_4_mask                                    (0x00000008)
#define  VDPQ_DMA_CTRL5_mem_off_mask                                             (0x00000004)
#define  VDPQ_DMA_CTRL5_mem_test_mode_mask                                       (0x00000002)
#define  VDPQ_DMA_CTRL5_mem_test_mode_ok_mask                                    (0x00000001)
#define  VDPQ_DMA_CTRL5_ofifo_err_flag(data)                                     (0x00000080&((data)<<7))
#define  VDPQ_DMA_CTRL5_ififo_err_flag_1(data)                                   (0x00000040&((data)<<6))
#define  VDPQ_DMA_CTRL5_ififo_err_flag_2(data)                                   (0x00000020&((data)<<5))
#define  VDPQ_DMA_CTRL5_ififo_err_flag_3(data)                                   (0x00000010&((data)<<4))
#define  VDPQ_DMA_CTRL5_ififo_err_flag_4(data)                                   (0x00000008&((data)<<3))
#define  VDPQ_DMA_CTRL5_mem_off(data)                                            (0x00000004&((data)<<2))
#define  VDPQ_DMA_CTRL5_mem_test_mode(data)                                      (0x00000002&((data)<<1))
#define  VDPQ_DMA_CTRL5_mem_test_mode_ok(data)                                   (0x00000001&(data))
#define  VDPQ_DMA_CTRL5_get_ofifo_err_flag(data)                                 ((0x00000080&(data))>>7)
#define  VDPQ_DMA_CTRL5_get_ififo_err_flag_1(data)                               ((0x00000040&(data))>>6)
#define  VDPQ_DMA_CTRL5_get_ififo_err_flag_2(data)                               ((0x00000020&(data))>>5)
#define  VDPQ_DMA_CTRL5_get_ififo_err_flag_3(data)                               ((0x00000010&(data))>>4)
#define  VDPQ_DMA_CTRL5_get_ififo_err_flag_4(data)                               ((0x00000008&(data))>>3)
#define  VDPQ_DMA_CTRL5_get_mem_off(data)                                        ((0x00000004&(data))>>2)
#define  VDPQ_DMA_CTRL5_get_mem_test_mode(data)                                  ((0x00000002&(data))>>1)
#define  VDPQ_DMA_CTRL5_get_mem_test_mode_ok(data)                               (0x00000001&(data))

#define  VDPQ_DMA_CTRL6                                                          0x18019854
#define  VDPQ_DMA_CTRL6_reg_addr                                                 "0xB8019854"
#define  VDPQ_DMA_CTRL6_reg                                                      0xB8019854
#define  VDPQ_DMA_CTRL6_inst_addr                                                "0x0011"
#define  set_VDPQ_DMA_CTRL6_reg(data)                                            (*((volatile unsigned int*)VDPQ_DMA_CTRL6_reg)=data)
#define  get_VDPQ_DMA_CTRL6_reg                                                  (*((volatile unsigned int*)VDPQ_DMA_CTRL6_reg))
#define  VDPQ_DMA_CTRL6_dma_field_inv_shift                                      (2)
#define  VDPQ_DMA_CTRL6_dma_adc_in_en_shift                                      (1)
#define  VDPQ_DMA_CTRL6_dma_adc_in_sel_shift                                     (0)
#define  VDPQ_DMA_CTRL6_dma_field_inv_mask                                       (0x00000004)
#define  VDPQ_DMA_CTRL6_dma_adc_in_en_mask                                       (0x00000002)
#define  VDPQ_DMA_CTRL6_dma_adc_in_sel_mask                                      (0x00000001)
#define  VDPQ_DMA_CTRL6_dma_field_inv(data)                                      (0x00000004&((data)<<2))
#define  VDPQ_DMA_CTRL6_dma_adc_in_en(data)                                      (0x00000002&((data)<<1))
#define  VDPQ_DMA_CTRL6_dma_adc_in_sel(data)                                     (0x00000001&(data))
#define  VDPQ_DMA_CTRL6_get_dma_field_inv(data)                                  ((0x00000004&(data))>>2)
#define  VDPQ_DMA_CTRL6_get_dma_adc_in_en(data)                                  ((0x00000002&(data))>>1)
#define  VDPQ_DMA_CTRL6_get_dma_adc_in_sel(data)                                 (0x00000001&(data))

#define  VDPQ_DEBUG_DMA_IF_CTRL                                                  0x18019858
#define  VDPQ_DEBUG_DMA_IF_CTRL_reg_addr                                         "0xB8019858"
#define  VDPQ_DEBUG_DMA_IF_CTRL_reg                                              0xB8019858
#define  VDPQ_DEBUG_DMA_IF_CTRL_inst_addr                                        "0x0012"
#define  set_VDPQ_DEBUG_DMA_IF_CTRL_reg(data)                                    (*((volatile unsigned int*)VDPQ_DEBUG_DMA_IF_CTRL_reg)=data)
#define  get_VDPQ_DEBUG_DMA_IF_CTRL_reg                                          (*((volatile unsigned int*)VDPQ_DEBUG_DMA_IF_CTRL_reg))
#define  VDPQ_DEBUG_DMA_IF_CTRL_dma_debugif_stline_en_shift                      (10)
#define  VDPQ_DEBUG_DMA_IF_CTRL_dma_debugif_stline_shift                         (0)
#define  VDPQ_DEBUG_DMA_IF_CTRL_dma_debugif_stline_en_mask                       (0x00000400)
#define  VDPQ_DEBUG_DMA_IF_CTRL_dma_debugif_stline_mask                          (0x000003FF)
#define  VDPQ_DEBUG_DMA_IF_CTRL_dma_debugif_stline_en(data)                      (0x00000400&((data)<<10))
#define  VDPQ_DEBUG_DMA_IF_CTRL_dma_debugif_stline(data)                         (0x000003FF&(data))
#define  VDPQ_DEBUG_DMA_IF_CTRL_get_dma_debugif_stline_en(data)                  ((0x00000400&(data))>>10)
#define  VDPQ_DEBUG_DMA_IF_CTRL_get_dma_debugif_stline(data)                     (0x000003FF&(data))

#define  VDPQ_VD_SRAM_ON_OFF                                                     0x1801985C
#define  VDPQ_VD_SRAM_ON_OFF_reg_addr                                            "0xB801985C"
#define  VDPQ_VD_SRAM_ON_OFF_reg                                                 0xB801985C
#define  VDPQ_VD_SRAM_ON_OFF_inst_addr                                           "0x0013"
#define  set_VDPQ_VD_SRAM_ON_OFF_reg(data)                                       (*((volatile unsigned int*)VDPQ_VD_SRAM_ON_OFF_reg)=data)
#define  get_VDPQ_VD_SRAM_ON_OFF_reg                                             (*((volatile unsigned int*)VDPQ_VD_SRAM_ON_OFF_reg))
#define  VDPQ_VD_SRAM_ON_OFF_vlpf_sram_bypass_shift                              (1)
#define  VDPQ_VD_SRAM_ON_OFF_vd_sram_on_off_shift                                (0)
#define  VDPQ_VD_SRAM_ON_OFF_vlpf_sram_bypass_mask                               (0x00000002)
#define  VDPQ_VD_SRAM_ON_OFF_vd_sram_on_off_mask                                 (0x00000001)
#define  VDPQ_VD_SRAM_ON_OFF_vlpf_sram_bypass(data)                              (0x00000002&((data)<<1))
#define  VDPQ_VD_SRAM_ON_OFF_vd_sram_on_off(data)                                (0x00000001&(data))
#define  VDPQ_VD_SRAM_ON_OFF_get_vlpf_sram_bypass(data)                          ((0x00000002&(data))>>1)
#define  VDPQ_VD_SRAM_ON_OFF_get_vd_sram_on_off(data)                            (0x00000001&(data))

#define  VDPQ_MEM0_ADDR_INI                                                      0x18019870
#define  VDPQ_MEM0_ADDR_INI_reg_addr                                             "0xB8019870"
#define  VDPQ_MEM0_ADDR_INI_reg                                                  0xB8019870
#define  VDPQ_MEM0_ADDR_INI_inst_addr                                            "0x0014"
#define  set_VDPQ_MEM0_ADDR_INI_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM0_ADDR_INI_reg)=data)
#define  get_VDPQ_MEM0_ADDR_INI_reg                                              (*((volatile unsigned int*)VDPQ_MEM0_ADDR_INI_reg))
#define  VDPQ_MEM0_ADDR_INI_frame_addr0_shift                                    (0)
#define  VDPQ_MEM0_ADDR_INI_frame_addr0_mask                                     (0x1FFFFFFF)
#define  VDPQ_MEM0_ADDR_INI_frame_addr0(data)                                    (0x1FFFFFFF&(data))
#define  VDPQ_MEM0_ADDR_INI_get_frame_addr0(data)                                (0x1FFFFFFF&(data))

#define  VDPQ_MEM1_ADDR_INI                                                      0x18019874
#define  VDPQ_MEM1_ADDR_INI_reg_addr                                             "0xB8019874"
#define  VDPQ_MEM1_ADDR_INI_reg                                                  0xB8019874
#define  VDPQ_MEM1_ADDR_INI_inst_addr                                            "0x0015"
#define  set_VDPQ_MEM1_ADDR_INI_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM1_ADDR_INI_reg)=data)
#define  get_VDPQ_MEM1_ADDR_INI_reg                                              (*((volatile unsigned int*)VDPQ_MEM1_ADDR_INI_reg))
#define  VDPQ_MEM1_ADDR_INI_frame_addr1_shift                                    (0)
#define  VDPQ_MEM1_ADDR_INI_frame_addr1_mask                                     (0x1FFFFFFF)
#define  VDPQ_MEM1_ADDR_INI_frame_addr1(data)                                    (0x1FFFFFFF&(data))
#define  VDPQ_MEM1_ADDR_INI_get_frame_addr1(data)                                (0x1FFFFFFF&(data))

#define  VDPQ_MEM2_ADDR_INI                                                      0x18019878
#define  VDPQ_MEM2_ADDR_INI_reg_addr                                             "0xB8019878"
#define  VDPQ_MEM2_ADDR_INI_reg                                                  0xB8019878
#define  VDPQ_MEM2_ADDR_INI_inst_addr                                            "0x0016"
#define  set_VDPQ_MEM2_ADDR_INI_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM2_ADDR_INI_reg)=data)
#define  get_VDPQ_MEM2_ADDR_INI_reg                                              (*((volatile unsigned int*)VDPQ_MEM2_ADDR_INI_reg))
#define  VDPQ_MEM2_ADDR_INI_frame_addr2_shift                                    (0)
#define  VDPQ_MEM2_ADDR_INI_frame_addr2_mask                                     (0x1FFFFFFF)
#define  VDPQ_MEM2_ADDR_INI_frame_addr2(data)                                    (0x1FFFFFFF&(data))
#define  VDPQ_MEM2_ADDR_INI_get_frame_addr2(data)                                (0x1FFFFFFF&(data))

#define  VDPQ_MEM3_ADDR_INI                                                      0x1801987C
#define  VDPQ_MEM3_ADDR_INI_reg_addr                                             "0xB801987C"
#define  VDPQ_MEM3_ADDR_INI_reg                                                  0xB801987C
#define  VDPQ_MEM3_ADDR_INI_inst_addr                                            "0x0017"
#define  set_VDPQ_MEM3_ADDR_INI_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM3_ADDR_INI_reg)=data)
#define  get_VDPQ_MEM3_ADDR_INI_reg                                              (*((volatile unsigned int*)VDPQ_MEM3_ADDR_INI_reg))
#define  VDPQ_MEM3_ADDR_INI_frame_addr3_shift                                    (0)
#define  VDPQ_MEM3_ADDR_INI_frame_addr3_mask                                     (0x1FFFFFFF)
#define  VDPQ_MEM3_ADDR_INI_frame_addr3(data)                                    (0x1FFFFFFF&(data))
#define  VDPQ_MEM3_ADDR_INI_get_frame_addr3(data)                                (0x1FFFFFFF&(data))

#define  VDPQ_MEM0_ADDR_END                                                      0x18019880
#define  VDPQ_MEM0_ADDR_END_reg_addr                                             "0xB8019880"
#define  VDPQ_MEM0_ADDR_END_reg                                                  0xB8019880
#define  VDPQ_MEM0_ADDR_END_inst_addr                                            "0x0018"
#define  set_VDPQ_MEM0_ADDR_END_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM0_ADDR_END_reg)=data)
#define  get_VDPQ_MEM0_ADDR_END_reg                                              (*((volatile unsigned int*)VDPQ_MEM0_ADDR_END_reg))
#define  VDPQ_MEM0_ADDR_END_frame_addr0_end_shift                                (0)
#define  VDPQ_MEM0_ADDR_END_frame_addr0_end_mask                                 (0x1FFFFFFF)
#define  VDPQ_MEM0_ADDR_END_frame_addr0_end(data)                                (0x1FFFFFFF&(data))
#define  VDPQ_MEM0_ADDR_END_get_frame_addr0_end(data)                            (0x1FFFFFFF&(data))

#define  VDPQ_MEM1_ADDR_END                                                      0x18019884
#define  VDPQ_MEM1_ADDR_END_reg_addr                                             "0xB8019884"
#define  VDPQ_MEM1_ADDR_END_reg                                                  0xB8019884
#define  VDPQ_MEM1_ADDR_END_inst_addr                                            "0x0019"
#define  set_VDPQ_MEM1_ADDR_END_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM1_ADDR_END_reg)=data)
#define  get_VDPQ_MEM1_ADDR_END_reg                                              (*((volatile unsigned int*)VDPQ_MEM1_ADDR_END_reg))
#define  VDPQ_MEM1_ADDR_END_frame_addr1_end_shift                                (0)
#define  VDPQ_MEM1_ADDR_END_frame_addr1_end_mask                                 (0x1FFFFFFF)
#define  VDPQ_MEM1_ADDR_END_frame_addr1_end(data)                                (0x1FFFFFFF&(data))
#define  VDPQ_MEM1_ADDR_END_get_frame_addr1_end(data)                            (0x1FFFFFFF&(data))

#define  VDPQ_MEM2_ADDR_END                                                      0x18019888
#define  VDPQ_MEM2_ADDR_END_reg_addr                                             "0xB8019888"
#define  VDPQ_MEM2_ADDR_END_reg                                                  0xB8019888
#define  VDPQ_MEM2_ADDR_END_inst_addr                                            "0x001A"
#define  set_VDPQ_MEM2_ADDR_END_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM2_ADDR_END_reg)=data)
#define  get_VDPQ_MEM2_ADDR_END_reg                                              (*((volatile unsigned int*)VDPQ_MEM2_ADDR_END_reg))
#define  VDPQ_MEM2_ADDR_END_frame_addr2_end_shift                                (0)
#define  VDPQ_MEM2_ADDR_END_frame_addr2_end_mask                                 (0x1FFFFFFF)
#define  VDPQ_MEM2_ADDR_END_frame_addr2_end(data)                                (0x1FFFFFFF&(data))
#define  VDPQ_MEM2_ADDR_END_get_frame_addr2_end(data)                            (0x1FFFFFFF&(data))

#define  VDPQ_MEM3_ADDR_END                                                      0x1801988C
#define  VDPQ_MEM3_ADDR_END_reg_addr                                             "0xB801988C"
#define  VDPQ_MEM3_ADDR_END_reg                                                  0xB801988C
#define  VDPQ_MEM3_ADDR_END_inst_addr                                            "0x001B"
#define  set_VDPQ_MEM3_ADDR_END_reg(data)                                        (*((volatile unsigned int*)VDPQ_MEM3_ADDR_END_reg)=data)
#define  get_VDPQ_MEM3_ADDR_END_reg                                              (*((volatile unsigned int*)VDPQ_MEM3_ADDR_END_reg))
#define  VDPQ_MEM3_ADDR_END_frame_addr3_end_shift                                (0)
#define  VDPQ_MEM3_ADDR_END_frame_addr3_end_mask                                 (0x1FFFFFFF)
#define  VDPQ_MEM3_ADDR_END_frame_addr3_end(data)                                (0x1FFFFFFF&(data))
#define  VDPQ_MEM3_ADDR_END_get_frame_addr3_end(data)                            (0x1FFFFFFF&(data))

#define  VDPQ_DMA_DEBUG_ADDR                                                     0x18019890
#define  VDPQ_DMA_DEBUG_ADDR_reg_addr                                            "0xB8019890"
#define  VDPQ_DMA_DEBUG_ADDR_reg                                                 0xB8019890
#define  VDPQ_DMA_DEBUG_ADDR_inst_addr                                           "0x001C"
#define  set_VDPQ_DMA_DEBUG_ADDR_reg(data)                                       (*((volatile unsigned int*)VDPQ_DMA_DEBUG_ADDR_reg)=data)
#define  get_VDPQ_DMA_DEBUG_ADDR_reg                                             (*((volatile unsigned int*)VDPQ_DMA_DEBUG_ADDR_reg))
#define  VDPQ_DMA_DEBUG_ADDR_dma_debug_adr_shift                                 (0)
#define  VDPQ_DMA_DEBUG_ADDR_dma_debug_adr_mask                                  (0x1FFFFFFF)
#define  VDPQ_DMA_DEBUG_ADDR_dma_debug_adr(data)                                 (0x1FFFFFFF&(data))
#define  VDPQ_DMA_DEBUG_ADDR_get_dma_debug_adr(data)                             (0x1FFFFFFF&(data))

#define  VDPQ_DMA_DEBUG_VBI_END_ADDR                                             0x18019894
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_reg_addr                                    "0xB8019894"
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_reg                                         0xB8019894
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_inst_addr                                   "0x001D"
#define  set_VDPQ_DMA_DEBUG_VBI_END_ADDR_reg(data)                               (*((volatile unsigned int*)VDPQ_DMA_DEBUG_VBI_END_ADDR_reg)=data)
#define  get_VDPQ_DMA_DEBUG_VBI_END_ADDR_reg                                     (*((volatile unsigned int*)VDPQ_DMA_DEBUG_VBI_END_ADDR_reg))
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_dma_debug_vbiend_adr_shift                  (0)
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_dma_debug_vbiend_adr_mask                   (0x1FFFFFFF)
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_dma_debug_vbiend_adr(data)                  (0x1FFFFFFF&(data))
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_get_dma_debug_vbiend_adr(data)              (0x1FFFFFFF&(data))

#define  VDPQ_VIDEO_DMA_DEBUG_CTRL                                               0x18019898
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_reg_addr                                      "0xB8019898"
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_reg                                           0xB8019898
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_inst_addr                                     "0x001E"
#define  set_VDPQ_VIDEO_DMA_DEBUG_CTRL_reg(data)                                 (*((volatile unsigned int*)VDPQ_VIDEO_DMA_DEBUG_CTRL_reg)=data)
#define  get_VDPQ_VIDEO_DMA_DEBUG_CTRL_reg                                       (*((volatile unsigned int*)VDPQ_VIDEO_DMA_DEBUG_CTRL_reg))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_debugdma_outfifo_full_shift                   (9)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_debugdma_outfifo_empty_shift                  (8)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debug_vd_sel_shift                        (4)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_mode_shift                                (3)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debugmode_sel_shift                       (1)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debugmode_en_shift                        (0)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_debugdma_outfifo_full_mask                    (0x00000200)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_debugdma_outfifo_empty_mask                   (0x00000100)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debug_vd_sel_mask                         (0x000000F0)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_mode_mask                                 (0x00000008)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debugmode_sel_mask                        (0x00000006)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debugmode_en_mask                         (0x00000001)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_debugdma_outfifo_full(data)                   (0x00000200&((data)<<9))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_debugdma_outfifo_empty(data)                  (0x00000100&((data)<<8))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debug_vd_sel(data)                        (0x000000F0&((data)<<4))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_mode(data)                                (0x00000008&((data)<<3))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debugmode_sel(data)                       (0x00000006&((data)<<1))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_dma_debugmode_en(data)                        (0x00000001&(data))
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_get_debugdma_outfifo_full(data)               ((0x00000200&(data))>>9)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_get_debugdma_outfifo_empty(data)              ((0x00000100&(data))>>8)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_get_dma_debug_vd_sel(data)                    ((0x000000F0&(data))>>4)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_get_dma_mode(data)                            ((0x00000008&(data))>>3)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_get_dma_debugmode_sel(data)                   ((0x00000006&(data))>>1)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_get_dma_debugmode_en(data)                    (0x00000001&(data))

#define  VDPQ_VBIDMA_TEST_CTRL                                                   0x1801989C
#define  VDPQ_VBIDMA_TEST_CTRL_reg_addr                                          "0xB801989C"
#define  VDPQ_VBIDMA_TEST_CTRL_reg                                               0xB801989C
#define  VDPQ_VBIDMA_TEST_CTRL_inst_addr                                         "0x001F"
#define  set_VDPQ_VBIDMA_TEST_CTRL_reg(data)                                     (*((volatile unsigned int*)VDPQ_VBIDMA_TEST_CTRL_reg)=data)
#define  get_VDPQ_VBIDMA_TEST_CTRL_reg                                           (*((volatile unsigned int*)VDPQ_VBIDMA_TEST_CTRL_reg))
#define  VDPQ_VBIDMA_TEST_CTRL_dma_debug_one_rw_rlt_shift                        (6)
#define  VDPQ_VBIDMA_TEST_CTRL_dma_debug_rw_en_shift                             (4)
#define  VDPQ_VBIDMA_TEST_CTRL_dma_debug_one_rw_rlt_mask                         (0x00000040)
#define  VDPQ_VBIDMA_TEST_CTRL_dma_debug_rw_en_mask                              (0x00000030)
#define  VDPQ_VBIDMA_TEST_CTRL_dma_debug_one_rw_rlt(data)                        (0x00000040&((data)<<6))
#define  VDPQ_VBIDMA_TEST_CTRL_dma_debug_rw_en(data)                             (0x00000030&((data)<<4))
#define  VDPQ_VBIDMA_TEST_CTRL_get_dma_debug_one_rw_rlt(data)                    ((0x00000040&(data))>>6)
#define  VDPQ_VBIDMA_TEST_CTRL_get_dma_debug_rw_en(data)                         ((0x00000030&(data))>>4)

#define  VDPQ_DMA_CNT_CALIBRATION1                                               0x180198A0
#define  VDPQ_DMA_CNT_CALIBRATION1_reg_addr                                      "0xB80198A0"
#define  VDPQ_DMA_CNT_CALIBRATION1_reg                                           0xB80198A0
#define  VDPQ_DMA_CNT_CALIBRATION1_inst_addr                                     "0x0020"
#define  set_VDPQ_DMA_CNT_CALIBRATION1_reg(data)                                 (*((volatile unsigned int*)VDPQ_DMA_CNT_CALIBRATION1_reg)=data)
#define  get_VDPQ_DMA_CNT_CALIBRATION1_reg                                       (*((volatile unsigned int*)VDPQ_DMA_CNT_CALIBRATION1_reg))
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_hsync_en_shift                    (31)
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_line_pos_en_shift                       (29)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_frame_sel_shift                   (28)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_sel_shift                         (27)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_en_shift                          (26)
#define  VDPQ_DMA_CNT_CALIBRATION1_dma_pix_sht_fix_en_shift                      (25)
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_per_frame_en_shift                      (24)
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_pix_num_shift                           (20)
#define  VDPQ_DMA_CNT_CALIBRATION1_pix_sht_st_th_shift                           (0)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_hsync_en_mask                     (0x80000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_line_pos_en_mask                        (0x60000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_frame_sel_mask                    (0x10000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_sel_mask                          (0x08000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_en_mask                           (0x04000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_dma_pix_sht_fix_en_mask                       (0x02000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_per_frame_en_mask                       (0x01000000)
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_pix_num_mask                            (0x00F00000)
#define  VDPQ_DMA_CNT_CALIBRATION1_pix_sht_st_th_mask                            (0x000FFFFF)
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_hsync_en(data)                    (0x80000000&((data)<<31))
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_line_pos_en(data)                       (0x60000000&((data)<<29))
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_frame_sel(data)                   (0x10000000&((data)<<28))
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_sel(data)                         (0x08000000&((data)<<27))
#define  VDPQ_DMA_CNT_CALIBRATION1_calib_delay_en(data)                          (0x04000000&((data)<<26))
#define  VDPQ_DMA_CNT_CALIBRATION1_dma_pix_sht_fix_en(data)                      (0x02000000&((data)<<25))
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_per_frame_en(data)                      (0x01000000&((data)<<24))
#define  VDPQ_DMA_CNT_CALIBRATION1_chase_pix_num(data)                           (0x00F00000&((data)<<20))
#define  VDPQ_DMA_CNT_CALIBRATION1_pix_sht_st_th(data)                           (0x000FFFFF&(data))
#define  VDPQ_DMA_CNT_CALIBRATION1_get_calib_delay_hsync_en(data)                ((0x80000000&(data))>>31)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_chase_line_pos_en(data)                   ((0x60000000&(data))>>29)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_calib_delay_frame_sel(data)               ((0x10000000&(data))>>28)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_calib_delay_sel(data)                     ((0x08000000&(data))>>27)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_calib_delay_en(data)                      ((0x04000000&(data))>>26)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_dma_pix_sht_fix_en(data)                  ((0x02000000&(data))>>25)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_chase_per_frame_en(data)                  ((0x01000000&(data))>>24)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_chase_pix_num(data)                       ((0x00F00000&(data))>>20)
#define  VDPQ_DMA_CNT_CALIBRATION1_get_pix_sht_st_th(data)                       (0x000FFFFF&(data))

#define  VDPQ_DMA_CNT_CALIBRATION2                                               0x180198A4
#define  VDPQ_DMA_CNT_CALIBRATION2_reg_addr                                      "0xB80198A4"
#define  VDPQ_DMA_CNT_CALIBRATION2_reg                                           0xB80198A4
#define  VDPQ_DMA_CNT_CALIBRATION2_inst_addr                                     "0x0021"
#define  set_VDPQ_DMA_CNT_CALIBRATION2_reg(data)                                 (*((volatile unsigned int*)VDPQ_DMA_CNT_CALIBRATION2_reg)=data)
#define  get_VDPQ_DMA_CNT_CALIBRATION2_reg                                       (*((volatile unsigned int*)VDPQ_DMA_CNT_CALIBRATION2_reg))
#define  VDPQ_DMA_CNT_CALIBRATION2_fscnum_dif_abs_sel_shift                      (29)
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_limit_en_shift                        (28)
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_limit_th_shift                        (20)
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_end_th_shift                          (0)
#define  VDPQ_DMA_CNT_CALIBRATION2_fscnum_dif_abs_sel_mask                       (0x60000000)
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_limit_en_mask                         (0x10000000)
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_limit_th_mask                         (0x0FF00000)
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_end_th_mask                           (0x000FFFFF)
#define  VDPQ_DMA_CNT_CALIBRATION2_fscnum_dif_abs_sel(data)                      (0x60000000&((data)<<29))
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_limit_en(data)                        (0x10000000&((data)<<28))
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_limit_th(data)                        (0x0FF00000&((data)<<20))
#define  VDPQ_DMA_CNT_CALIBRATION2_pix_sht_end_th(data)                          (0x000FFFFF&(data))
#define  VDPQ_DMA_CNT_CALIBRATION2_get_fscnum_dif_abs_sel(data)                  ((0x60000000&(data))>>29)
#define  VDPQ_DMA_CNT_CALIBRATION2_get_pix_sht_limit_en(data)                    ((0x10000000&(data))>>28)
#define  VDPQ_DMA_CNT_CALIBRATION2_get_pix_sht_limit_th(data)                    ((0x0FF00000&(data))>>20)
#define  VDPQ_DMA_CNT_CALIBRATION2_get_pix_sht_end_th(data)                      (0x000FFFFF&(data))

#define  VDPQ_DMA_CNT_CALIBRATION3                                               0x180198A8
#define  VDPQ_DMA_CNT_CALIBRATION3_reg_addr                                      "0xB80198A8"
#define  VDPQ_DMA_CNT_CALIBRATION3_reg                                           0xB80198A8
#define  VDPQ_DMA_CNT_CALIBRATION3_inst_addr                                     "0x0022"
#define  set_VDPQ_DMA_CNT_CALIBRATION3_reg(data)                                 (*((volatile unsigned int*)VDPQ_DMA_CNT_CALIBRATION3_reg)=data)
#define  get_VDPQ_DMA_CNT_CALIBRATION3_reg                                       (*((volatile unsigned int*)VDPQ_DMA_CNT_CALIBRATION3_reg))
#define  VDPQ_DMA_CNT_CALIBRATION3_fscdif_num_abs_shift                          (24)
#define  VDPQ_DMA_CNT_CALIBRATION3_fscdif_sum_abs_shift                          (0)
#define  VDPQ_DMA_CNT_CALIBRATION3_fscdif_num_abs_mask                           (0x3F000000)
#define  VDPQ_DMA_CNT_CALIBRATION3_fscdif_sum_abs_mask                           (0x000FFFFF)
#define  VDPQ_DMA_CNT_CALIBRATION3_fscdif_num_abs(data)                          (0x3F000000&((data)<<24))
#define  VDPQ_DMA_CNT_CALIBRATION3_fscdif_sum_abs(data)                          (0x000FFFFF&(data))
#define  VDPQ_DMA_CNT_CALIBRATION3_get_fscdif_num_abs(data)                      ((0x3F000000&(data))>>24)
#define  VDPQ_DMA_CNT_CALIBRATION3_get_fscdif_sum_abs(data)                      (0x000FFFFF&(data))

#define  VDPQ_FRAME_BUFFER_F1_STATUS                                             0x180198D0
#define  VDPQ_FRAME_BUFFER_F1_STATUS_reg_addr                                    "0xB80198D0"
#define  VDPQ_FRAME_BUFFER_F1_STATUS_reg                                         0xB80198D0
#define  VDPQ_FRAME_BUFFER_F1_STATUS_inst_addr                                   "0x0023"
#define  set_VDPQ_FRAME_BUFFER_F1_STATUS_reg(data)                               (*((volatile unsigned int*)VDPQ_FRAME_BUFFER_F1_STATUS_reg)=data)
#define  get_VDPQ_FRAME_BUFFER_F1_STATUS_reg                                     (*((volatile unsigned int*)VDPQ_FRAME_BUFFER_F1_STATUS_reg))
#define  VDPQ_FRAME_BUFFER_F1_STATUS_f1_cennum_shift                             (0)
#define  VDPQ_FRAME_BUFFER_F1_STATUS_f1_cennum_mask                              (0x0000FFFF)
#define  VDPQ_FRAME_BUFFER_F1_STATUS_f1_cennum(data)                             (0x0000FFFF&(data))
#define  VDPQ_FRAME_BUFFER_F1_STATUS_get_f1_cennum(data)                         (0x0000FFFF&(data))

#define  VDPQ_FRAME_BUFFER_F2_STATUS                                             0x180198D4
#define  VDPQ_FRAME_BUFFER_F2_STATUS_reg_addr                                    "0xB80198D4"
#define  VDPQ_FRAME_BUFFER_F2_STATUS_reg                                         0xB80198D4
#define  VDPQ_FRAME_BUFFER_F2_STATUS_inst_addr                                   "0x0024"
#define  set_VDPQ_FRAME_BUFFER_F2_STATUS_reg(data)                               (*((volatile unsigned int*)VDPQ_FRAME_BUFFER_F2_STATUS_reg)=data)
#define  get_VDPQ_FRAME_BUFFER_F2_STATUS_reg                                     (*((volatile unsigned int*)VDPQ_FRAME_BUFFER_F2_STATUS_reg))
#define  VDPQ_FRAME_BUFFER_F2_STATUS_f2_cennum_shift                             (0)
#define  VDPQ_FRAME_BUFFER_F2_STATUS_f2_cennum_mask                              (0x0000FFFF)
#define  VDPQ_FRAME_BUFFER_F2_STATUS_f2_cennum(data)                             (0x0000FFFF&(data))
#define  VDPQ_FRAME_BUFFER_F2_STATUS_get_f2_cennum(data)                         (0x0000FFFF&(data))

#define  VDPQ_Dummy_1                                                            0x180198D8
#define  VDPQ_Dummy_1_reg_addr                                                   "0xB80198D8"
#define  VDPQ_Dummy_1_reg                                                        0xB80198D8
#define  VDPQ_Dummy_1_inst_addr                                                  "0x0025"
#define  set_VDPQ_Dummy_1_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_1_reg)=data)
#define  get_VDPQ_Dummy_1_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_1_reg))
#define  VDPQ_Dummy_1_dummy_1_shift                                              (0)
#define  VDPQ_Dummy_1_dummy_1_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_1_dummy_1(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_1_get_dummy_1(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_Dummy_2                                                            0x180198DC
#define  VDPQ_Dummy_2_reg_addr                                                   "0xB80198DC"
#define  VDPQ_Dummy_2_reg                                                        0xB80198DC
#define  VDPQ_Dummy_2_inst_addr                                                  "0x0026"
#define  set_VDPQ_Dummy_2_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_2_reg)=data)
#define  get_VDPQ_Dummy_2_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_2_reg))
#define  VDPQ_Dummy_2_dummy_2_shift                                              (0)
#define  VDPQ_Dummy_2_dummy_2_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_2_dummy_2(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_2_get_dummy_2(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_YC_SEP_CONTROL                                                     0x18019900
#define  VDPQ_YC_SEP_CONTROL_reg_addr                                            "0xB8019900"
#define  VDPQ_YC_SEP_CONTROL_reg                                                 0xB8019900
#define  VDPQ_YC_SEP_CONTROL_inst_addr                                           "0x0027"
#define  set_VDPQ_YC_SEP_CONTROL_reg(data)                                       (*((volatile unsigned int*)VDPQ_YC_SEP_CONTROL_reg)=data)
#define  get_VDPQ_YC_SEP_CONTROL_reg                                             (*((volatile unsigned int*)VDPQ_YC_SEP_CONTROL_reg))
#define  VDPQ_YC_SEP_CONTROL_yc3d_tb_en_shift                                    (31)
#define  VDPQ_YC_SEP_CONTROL_ycsep_rdsel_shift                                   (8)
#define  VDPQ_YC_SEP_CONTROL_yc_linebf_sel_shift                                 (4)
#define  VDPQ_YC_SEP_CONTROL_adaptive_mode_shift                                 (0)
#define  VDPQ_YC_SEP_CONTROL_yc3d_tb_en_mask                                     (0x80000000)
#define  VDPQ_YC_SEP_CONTROL_ycsep_rdsel_mask                                    (0x00000100)
#define  VDPQ_YC_SEP_CONTROL_yc_linebf_sel_mask                                  (0x00000010)
#define  VDPQ_YC_SEP_CONTROL_adaptive_mode_mask                                  (0x00000007)
#define  VDPQ_YC_SEP_CONTROL_yc3d_tb_en(data)                                    (0x80000000&((data)<<31))
#define  VDPQ_YC_SEP_CONTROL_ycsep_rdsel(data)                                   (0x00000100&((data)<<8))
#define  VDPQ_YC_SEP_CONTROL_yc_linebf_sel(data)                                 (0x00000010&((data)<<4))
#define  VDPQ_YC_SEP_CONTROL_adaptive_mode(data)                                 (0x00000007&(data))
#define  VDPQ_YC_SEP_CONTROL_get_yc3d_tb_en(data)                                ((0x80000000&(data))>>31)
#define  VDPQ_YC_SEP_CONTROL_get_ycsep_rdsel(data)                               ((0x00000100&(data))>>8)
#define  VDPQ_YC_SEP_CONTROL_get_yc_linebf_sel(data)                             ((0x00000010&(data))>>4)
#define  VDPQ_YC_SEP_CONTROL_get_adaptive_mode(data)                             (0x00000007&(data))

#define  VDPQ_BPF_BW_SEL_Y                                                       0x18019904
#define  VDPQ_BPF_BW_SEL_Y_reg_addr                                              "0xB8019904"
#define  VDPQ_BPF_BW_SEL_Y_reg                                                   0xB8019904
#define  VDPQ_BPF_BW_SEL_Y_inst_addr                                             "0x0028"
#define  set_VDPQ_BPF_BW_SEL_Y_reg(data)                                         (*((volatile unsigned int*)VDPQ_BPF_BW_SEL_Y_reg)=data)
#define  get_VDPQ_BPF_BW_SEL_Y_reg                                               (*((volatile unsigned int*)VDPQ_BPF_BW_SEL_Y_reg))
#define  VDPQ_BPF_BW_SEL_Y_wide_bpf_sel_y_shift                                  (8)
#define  VDPQ_BPF_BW_SEL_Y_mid_bpf_sel_y_shift                                   (4)
#define  VDPQ_BPF_BW_SEL_Y_narrow_bpf_sel_y_shift                                (0)
#define  VDPQ_BPF_BW_SEL_Y_wide_bpf_sel_y_mask                                   (0x00000F00)
#define  VDPQ_BPF_BW_SEL_Y_mid_bpf_sel_y_mask                                    (0x000000F0)
#define  VDPQ_BPF_BW_SEL_Y_narrow_bpf_sel_y_mask                                 (0x0000000F)
#define  VDPQ_BPF_BW_SEL_Y_wide_bpf_sel_y(data)                                  (0x00000F00&((data)<<8))
#define  VDPQ_BPF_BW_SEL_Y_mid_bpf_sel_y(data)                                   (0x000000F0&((data)<<4))
#define  VDPQ_BPF_BW_SEL_Y_narrow_bpf_sel_y(data)                                (0x0000000F&(data))
#define  VDPQ_BPF_BW_SEL_Y_get_wide_bpf_sel_y(data)                              ((0x00000F00&(data))>>8)
#define  VDPQ_BPF_BW_SEL_Y_get_mid_bpf_sel_y(data)                               ((0x000000F0&(data))>>4)
#define  VDPQ_BPF_BW_SEL_Y_get_narrow_bpf_sel_y(data)                            (0x0000000F&(data))

#define  VDPQ_BPF_BW_SEL_C                                                       0x18019908
#define  VDPQ_BPF_BW_SEL_C_reg_addr                                              "0xB8019908"
#define  VDPQ_BPF_BW_SEL_C_reg                                                   0xB8019908
#define  VDPQ_BPF_BW_SEL_C_inst_addr                                             "0x0029"
#define  set_VDPQ_BPF_BW_SEL_C_reg(data)                                         (*((volatile unsigned int*)VDPQ_BPF_BW_SEL_C_reg)=data)
#define  get_VDPQ_BPF_BW_SEL_C_reg                                               (*((volatile unsigned int*)VDPQ_BPF_BW_SEL_C_reg))
#define  VDPQ_BPF_BW_SEL_C_wide_bpf_sel_c_shift                                  (8)
#define  VDPQ_BPF_BW_SEL_C_mid_bpf_sel_c_shift                                   (4)
#define  VDPQ_BPF_BW_SEL_C_narrow_bpf_sel_c_shift                                (0)
#define  VDPQ_BPF_BW_SEL_C_wide_bpf_sel_c_mask                                   (0x00000F00)
#define  VDPQ_BPF_BW_SEL_C_mid_bpf_sel_c_mask                                    (0x000000F0)
#define  VDPQ_BPF_BW_SEL_C_narrow_bpf_sel_c_mask                                 (0x0000000F)
#define  VDPQ_BPF_BW_SEL_C_wide_bpf_sel_c(data)                                  (0x00000F00&((data)<<8))
#define  VDPQ_BPF_BW_SEL_C_mid_bpf_sel_c(data)                                   (0x000000F0&((data)<<4))
#define  VDPQ_BPF_BW_SEL_C_narrow_bpf_sel_c(data)                                (0x0000000F&(data))
#define  VDPQ_BPF_BW_SEL_C_get_wide_bpf_sel_c(data)                              ((0x00000F00&(data))>>8)
#define  VDPQ_BPF_BW_SEL_C_get_mid_bpf_sel_c(data)                               ((0x000000F0&(data))>>4)
#define  VDPQ_BPF_BW_SEL_C_get_narrow_bpf_sel_c(data)                            (0x0000000F&(data))

#define  VDPQ_ADAP_BPF_C_TH1                                                     0x1801990C
#define  VDPQ_ADAP_BPF_C_TH1_reg_addr                                            "0xB801990C"
#define  VDPQ_ADAP_BPF_C_TH1_reg                                                 0xB801990C
#define  VDPQ_ADAP_BPF_C_TH1_inst_addr                                           "0x002A"
#define  set_VDPQ_ADAP_BPF_C_TH1_reg(data)                                       (*((volatile unsigned int*)VDPQ_ADAP_BPF_C_TH1_reg)=data)
#define  get_VDPQ_ADAP_BPF_C_TH1_reg                                             (*((volatile unsigned int*)VDPQ_ADAP_BPF_C_TH1_reg))
#define  VDPQ_ADAP_BPF_C_TH1_h2v_lk_en_shift                                     (7)
#define  VDPQ_ADAP_BPF_C_TH1_v2v_lk_y_en_shift                                   (5)
#define  VDPQ_ADAP_BPF_C_TH1_v2v_lk_c_en_shift                                   (4)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_mid_sel_y_shift                                 (3)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_mid_sel_c_shift                                 (2)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_near_sel_y_shift                                (1)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_near_sel_c_shift                                (0)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_lk_en_mask                                      (0x00000080)
#define  VDPQ_ADAP_BPF_C_TH1_v2v_lk_y_en_mask                                    (0x00000020)
#define  VDPQ_ADAP_BPF_C_TH1_v2v_lk_c_en_mask                                    (0x00000010)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_mid_sel_y_mask                                  (0x00000008)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_mid_sel_c_mask                                  (0x00000004)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_near_sel_y_mask                                 (0x00000002)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_near_sel_c_mask                                 (0x00000001)
#define  VDPQ_ADAP_BPF_C_TH1_h2v_lk_en(data)                                     (0x00000080&((data)<<7))
#define  VDPQ_ADAP_BPF_C_TH1_v2v_lk_y_en(data)                                   (0x00000020&((data)<<5))
#define  VDPQ_ADAP_BPF_C_TH1_v2v_lk_c_en(data)                                   (0x00000010&((data)<<4))
#define  VDPQ_ADAP_BPF_C_TH1_h2v_mid_sel_y(data)                                 (0x00000008&((data)<<3))
#define  VDPQ_ADAP_BPF_C_TH1_h2v_mid_sel_c(data)                                 (0x00000004&((data)<<2))
#define  VDPQ_ADAP_BPF_C_TH1_h2v_near_sel_y(data)                                (0x00000002&((data)<<1))
#define  VDPQ_ADAP_BPF_C_TH1_h2v_near_sel_c(data)                                (0x00000001&(data))
#define  VDPQ_ADAP_BPF_C_TH1_get_h2v_lk_en(data)                                 ((0x00000080&(data))>>7)
#define  VDPQ_ADAP_BPF_C_TH1_get_v2v_lk_y_en(data)                               ((0x00000020&(data))>>5)
#define  VDPQ_ADAP_BPF_C_TH1_get_v2v_lk_c_en(data)                               ((0x00000010&(data))>>4)
#define  VDPQ_ADAP_BPF_C_TH1_get_h2v_mid_sel_y(data)                             ((0x00000008&(data))>>3)
#define  VDPQ_ADAP_BPF_C_TH1_get_h2v_mid_sel_c(data)                             ((0x00000004&(data))>>2)
#define  VDPQ_ADAP_BPF_C_TH1_get_h2v_near_sel_y(data)                            ((0x00000002&(data))>>1)
#define  VDPQ_ADAP_BPF_C_TH1_get_h2v_near_sel_c(data)                            (0x00000001&(data))

#define  VDPQ_ADAP_BPF_C_TH2                                                     0x18019910
#define  VDPQ_ADAP_BPF_C_TH2_reg_addr                                            "0xB8019910"
#define  VDPQ_ADAP_BPF_C_TH2_reg                                                 0xB8019910
#define  VDPQ_ADAP_BPF_C_TH2_inst_addr                                           "0x002B"
#define  set_VDPQ_ADAP_BPF_C_TH2_reg(data)                                       (*((volatile unsigned int*)VDPQ_ADAP_BPF_C_TH2_reg)=data)
#define  get_VDPQ_ADAP_BPF_C_TH2_reg                                             (*((volatile unsigned int*)VDPQ_ADAP_BPF_C_TH2_reg))
#define  VDPQ_ADAP_BPF_C_TH2_h2v_vflag_remag_thr_shift                           (4)
#define  VDPQ_ADAP_BPF_C_TH2_h2v_vflag_mag_thr_shift                             (0)
#define  VDPQ_ADAP_BPF_C_TH2_h2v_vflag_remag_thr_mask                            (0x000000F0)
#define  VDPQ_ADAP_BPF_C_TH2_h2v_vflag_mag_thr_mask                              (0x0000000F)
#define  VDPQ_ADAP_BPF_C_TH2_h2v_vflag_remag_thr(data)                           (0x000000F0&((data)<<4))
#define  VDPQ_ADAP_BPF_C_TH2_h2v_vflag_mag_thr(data)                             (0x0000000F&(data))
#define  VDPQ_ADAP_BPF_C_TH2_get_h2v_vflag_remag_thr(data)                       ((0x000000F0&(data))>>4)
#define  VDPQ_ADAP_BPF_C_TH2_get_h2v_vflag_mag_thr(data)                         (0x0000000F&(data))

#define  VDPQ_COMB_FILTER_CONFIG                                                 0x18019914
#define  VDPQ_COMB_FILTER_CONFIG_reg_addr                                        "0xB8019914"
#define  VDPQ_COMB_FILTER_CONFIG_reg                                             0xB8019914
#define  VDPQ_COMB_FILTER_CONFIG_inst_addr                                       "0x002C"
#define  set_VDPQ_COMB_FILTER_CONFIG_reg(data)                                   (*((volatile unsigned int*)VDPQ_COMB_FILTER_CONFIG_reg)=data)
#define  get_VDPQ_COMB_FILTER_CONFIG_reg                                         (*((volatile unsigned int*)VDPQ_COMB_FILTER_CONFIG_reg))
#define  VDPQ_COMB_FILTER_CONFIG_pal_perr_shift                                  (6)
#define  VDPQ_COMB_FILTER_CONFIG_pal_perr_auto_en_shift                          (5)
#define  VDPQ_COMB_FILTER_CONFIG_palsw_level_shift                               (0)
#define  VDPQ_COMB_FILTER_CONFIG_pal_perr_mask                                   (0x00000040)
#define  VDPQ_COMB_FILTER_CONFIG_pal_perr_auto_en_mask                           (0x00000020)
#define  VDPQ_COMB_FILTER_CONFIG_palsw_level_mask                                (0x00000003)
#define  VDPQ_COMB_FILTER_CONFIG_pal_perr(data)                                  (0x00000040&((data)<<6))
#define  VDPQ_COMB_FILTER_CONFIG_pal_perr_auto_en(data)                          (0x00000020&((data)<<5))
#define  VDPQ_COMB_FILTER_CONFIG_palsw_level(data)                               (0x00000003&(data))
#define  VDPQ_COMB_FILTER_CONFIG_get_pal_perr(data)                              ((0x00000040&(data))>>6)
#define  VDPQ_COMB_FILTER_CONFIG_get_pal_perr_auto_en(data)                      ((0x00000020&(data))>>5)
#define  VDPQ_COMB_FILTER_CONFIG_get_palsw_level(data)                           (0x00000003&(data))

#define  VDPQ_COMB_FILTER_THRESHOLD1                                             0x18019918
#define  VDPQ_COMB_FILTER_THRESHOLD1_reg_addr                                    "0xB8019918"
#define  VDPQ_COMB_FILTER_THRESHOLD1_reg                                         0xB8019918
#define  VDPQ_COMB_FILTER_THRESHOLD1_inst_addr                                   "0x002D"
#define  set_VDPQ_COMB_FILTER_THRESHOLD1_reg(data)                               (*((volatile unsigned int*)VDPQ_COMB_FILTER_THRESHOLD1_reg)=data)
#define  get_VDPQ_COMB_FILTER_THRESHOLD1_reg                                     (*((volatile unsigned int*)VDPQ_COMB_FILTER_THRESHOLD1_reg))
#define  VDPQ_COMB_FILTER_THRESHOLD1_noise_ntsc_c_shift                          (0)
#define  VDPQ_COMB_FILTER_THRESHOLD1_noise_ntsc_c_mask                           (0x000000FF)
#define  VDPQ_COMB_FILTER_THRESHOLD1_noise_ntsc_c(data)                          (0x000000FF&(data))
#define  VDPQ_COMB_FILTER_THRESHOLD1_get_noise_ntsc_c(data)                      (0x000000FF&(data))

#define  VDPQ_ADAP_BPF_Y_TH3                                                     0x18019928
#define  VDPQ_ADAP_BPF_Y_TH3_reg_addr                                            "0xB8019928"
#define  VDPQ_ADAP_BPF_Y_TH3_reg                                                 0xB8019928
#define  VDPQ_ADAP_BPF_Y_TH3_inst_addr                                           "0x002E"
#define  set_VDPQ_ADAP_BPF_Y_TH3_reg(data)                                       (*((volatile unsigned int*)VDPQ_ADAP_BPF_Y_TH3_reg)=data)
#define  get_VDPQ_ADAP_BPF_Y_TH3_reg                                             (*((volatile unsigned int*)VDPQ_ADAP_BPF_Y_TH3_reg))
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_divider2_sel_shift                         (7)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_divider2_sel_shift                         (6)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_en_shift                                   (5)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_shift                                      (4)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_en_shift                                   (3)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_shift                                      (2)
#define  VDPQ_ADAP_BPF_Y_TH3_yalpha_en_shift                                     (1)
#define  VDPQ_ADAP_BPF_Y_TH3_yalpha_shift                                        (0)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_divider2_sel_mask                          (0x00000080)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_divider2_sel_mask                          (0x00000040)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_en_mask                                    (0x00000020)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_mask                                       (0x00000010)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_en_mask                                    (0x00000008)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_mask                                       (0x00000004)
#define  VDPQ_ADAP_BPF_Y_TH3_yalpha_en_mask                                      (0x00000002)
#define  VDPQ_ADAP_BPF_Y_TH3_yalpha_mask                                         (0x00000001)
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_divider2_sel(data)                         (0x00000080&((data)<<7))
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_divider2_sel(data)                         (0x00000040&((data)<<6))
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y_en(data)                                   (0x00000020&((data)<<5))
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_y(data)                                      (0x00000010&((data)<<4))
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c_en(data)                                   (0x00000008&((data)<<3))
#define  VDPQ_ADAP_BPF_Y_TH3_malpha_c(data)                                      (0x00000004&((data)<<2))
#define  VDPQ_ADAP_BPF_Y_TH3_yalpha_en(data)                                     (0x00000002&((data)<<1))
#define  VDPQ_ADAP_BPF_Y_TH3_yalpha(data)                                        (0x00000001&(data))
#define  VDPQ_ADAP_BPF_Y_TH3_get_malpha_c_divider2_sel(data)                     ((0x00000080&(data))>>7)
#define  VDPQ_ADAP_BPF_Y_TH3_get_malpha_y_divider2_sel(data)                     ((0x00000040&(data))>>6)
#define  VDPQ_ADAP_BPF_Y_TH3_get_malpha_y_en(data)                               ((0x00000020&(data))>>5)
#define  VDPQ_ADAP_BPF_Y_TH3_get_malpha_y(data)                                  ((0x00000010&(data))>>4)
#define  VDPQ_ADAP_BPF_Y_TH3_get_malpha_c_en(data)                               ((0x00000008&(data))>>3)
#define  VDPQ_ADAP_BPF_Y_TH3_get_malpha_c(data)                                  ((0x00000004&(data))>>2)
#define  VDPQ_ADAP_BPF_Y_TH3_get_yalpha_en(data)                                 ((0x00000002&(data))>>1)
#define  VDPQ_ADAP_BPF_Y_TH3_get_yalpha(data)                                    (0x00000001&(data))

#define  VDPQ_YC_BW_CTRL                                                         0x1801992C
#define  VDPQ_YC_BW_CTRL_reg_addr                                                "0xB801992C"
#define  VDPQ_YC_BW_CTRL_reg                                                     0xB801992C
#define  VDPQ_YC_BW_CTRL_inst_addr                                               "0x002F"
#define  set_VDPQ_YC_BW_CTRL_reg(data)                                           (*((volatile unsigned int*)VDPQ_YC_BW_CTRL_reg)=data)
#define  get_VDPQ_YC_BW_CTRL_reg                                                 (*((volatile unsigned int*)VDPQ_YC_BW_CTRL_reg))
#define  VDPQ_YC_BW_CTRL_chroma_vlpf_round_en_shift                              (8)
#define  VDPQ_YC_BW_CTRL_pal_demod_sel_shift                                     (6)
#define  VDPQ_YC_BW_CTRL_chroma_vlpf_en_shift                                    (3)
#define  VDPQ_YC_BW_CTRL_chroma_bw_lo_shift                                      (0)
#define  VDPQ_YC_BW_CTRL_chroma_vlpf_round_en_mask                               (0x00000100)
#define  VDPQ_YC_BW_CTRL_pal_demod_sel_mask                                      (0x00000040)
#define  VDPQ_YC_BW_CTRL_chroma_vlpf_en_mask                                     (0x00000008)
#define  VDPQ_YC_BW_CTRL_chroma_bw_lo_mask                                       (0x00000007)
#define  VDPQ_YC_BW_CTRL_chroma_vlpf_round_en(data)                              (0x00000100&((data)<<8))
#define  VDPQ_YC_BW_CTRL_pal_demod_sel(data)                                     (0x00000040&((data)<<6))
#define  VDPQ_YC_BW_CTRL_chroma_vlpf_en(data)                                    (0x00000008&((data)<<3))
#define  VDPQ_YC_BW_CTRL_chroma_bw_lo(data)                                      (0x00000007&(data))
#define  VDPQ_YC_BW_CTRL_get_chroma_vlpf_round_en(data)                          ((0x00000100&(data))>>8)
#define  VDPQ_YC_BW_CTRL_get_pal_demod_sel(data)                                 ((0x00000040&(data))>>6)
#define  VDPQ_YC_BW_CTRL_get_chroma_vlpf_en(data)                                ((0x00000008&(data))>>3)
#define  VDPQ_YC_BW_CTRL_get_chroma_bw_lo(data)                                  (0x00000007&(data))

#define  VDPQ_DEBUG_2D_MODE                                                      0x18019930
#define  VDPQ_DEBUG_2D_MODE_reg_addr                                             "0xB8019930"
#define  VDPQ_DEBUG_2D_MODE_reg                                                  0xB8019930
#define  VDPQ_DEBUG_2D_MODE_inst_addr                                            "0x0030"
#define  set_VDPQ_DEBUG_2D_MODE_reg(data)                                        (*((volatile unsigned int*)VDPQ_DEBUG_2D_MODE_reg)=data)
#define  get_VDPQ_DEBUG_2D_MODE_reg                                              (*((volatile unsigned int*)VDPQ_DEBUG_2D_MODE_reg))
#define  VDPQ_DEBUG_2D_MODE_debug_mode_2d_en_shift                               (4)
#define  VDPQ_DEBUG_2D_MODE_debug_mode_2d_shift                                  (0)
#define  VDPQ_DEBUG_2D_MODE_debug_mode_2d_en_mask                                (0x00000010)
#define  VDPQ_DEBUG_2D_MODE_debug_mode_2d_mask                                   (0x0000000F)
#define  VDPQ_DEBUG_2D_MODE_debug_mode_2d_en(data)                               (0x00000010&((data)<<4))
#define  VDPQ_DEBUG_2D_MODE_debug_mode_2d(data)                                  (0x0000000F&(data))
#define  VDPQ_DEBUG_2D_MODE_get_debug_mode_2d_en(data)                           ((0x00000010&(data))>>4)
#define  VDPQ_DEBUG_2D_MODE_get_debug_mode_2d(data)                              (0x0000000F&(data))

#define  VDPQ_BW_DETECTION                                                       0x18019934
#define  VDPQ_BW_DETECTION_reg_addr                                              "0xB8019934"
#define  VDPQ_BW_DETECTION_reg                                                   0xB8019934
#define  VDPQ_BW_DETECTION_inst_addr                                             "0x0031"
#define  set_VDPQ_BW_DETECTION_reg(data)                                         (*((volatile unsigned int*)VDPQ_BW_DETECTION_reg)=data)
#define  get_VDPQ_BW_DETECTION_reg                                               (*((volatile unsigned int*)VDPQ_BW_DETECTION_reg))
#define  VDPQ_BW_DETECTION_bw_gain_sel_shift                                     (6)
#define  VDPQ_BW_DETECTION_bw_detect_thr_shift                                   (0)
#define  VDPQ_BW_DETECTION_bw_gain_sel_mask                                      (0x000000C0)
#define  VDPQ_BW_DETECTION_bw_detect_thr_mask                                    (0x0000003F)
#define  VDPQ_BW_DETECTION_bw_gain_sel(data)                                     (0x000000C0&((data)<<6))
#define  VDPQ_BW_DETECTION_bw_detect_thr(data)                                   (0x0000003F&(data))
#define  VDPQ_BW_DETECTION_get_bw_gain_sel(data)                                 ((0x000000C0&(data))>>6)
#define  VDPQ_BW_DETECTION_get_bw_detect_thr(data)                               (0x0000003F&(data))

#define  VDPQ_BW_EDGE_THR                                                        0x18019938
#define  VDPQ_BW_EDGE_THR_reg_addr                                               "0xB8019938"
#define  VDPQ_BW_EDGE_THR_reg                                                    0xB8019938
#define  VDPQ_BW_EDGE_THR_inst_addr                                              "0x0032"
#define  set_VDPQ_BW_EDGE_THR_reg(data)                                          (*((volatile unsigned int*)VDPQ_BW_EDGE_THR_reg)=data)
#define  get_VDPQ_BW_EDGE_THR_reg                                                (*((volatile unsigned int*)VDPQ_BW_EDGE_THR_reg))
#define  VDPQ_BW_EDGE_THR_bw_edge_thr_shift                                      (0)
#define  VDPQ_BW_EDGE_THR_bw_edge_thr_mask                                       (0x000000FF)
#define  VDPQ_BW_EDGE_THR_bw_edge_thr(data)                                      (0x000000FF&(data))
#define  VDPQ_BW_EDGE_THR_get_bw_edge_thr(data)                                  (0x000000FF&(data))

#define  VDPQ_BLEND_1D_THR                                                       0x1801993C
#define  VDPQ_BLEND_1D_THR_reg_addr                                              "0xB801993C"
#define  VDPQ_BLEND_1D_THR_reg                                                   0xB801993C
#define  VDPQ_BLEND_1D_THR_inst_addr                                             "0x0033"
#define  set_VDPQ_BLEND_1D_THR_reg(data)                                         (*((volatile unsigned int*)VDPQ_BLEND_1D_THR_reg)=data)
#define  get_VDPQ_BLEND_1D_THR_reg                                               (*((volatile unsigned int*)VDPQ_BLEND_1D_THR_reg))
#define  VDPQ_BLEND_1D_THR_same_phase_diff_1d_gauge_en_shift                     (8)
#define  VDPQ_BLEND_1D_THR_blend_1d_thr_shift                                    (2)
#define  VDPQ_BLEND_1D_THR_bpf_1d_sel_y_shift                                    (0)
#define  VDPQ_BLEND_1D_THR_same_phase_diff_1d_gauge_en_mask                      (0x00000100)
#define  VDPQ_BLEND_1D_THR_blend_1d_thr_mask                                     (0x0000007C)
#define  VDPQ_BLEND_1D_THR_bpf_1d_sel_y_mask                                     (0x00000003)
#define  VDPQ_BLEND_1D_THR_same_phase_diff_1d_gauge_en(data)                     (0x00000100&((data)<<8))
#define  VDPQ_BLEND_1D_THR_blend_1d_thr(data)                                    (0x0000007C&((data)<<2))
#define  VDPQ_BLEND_1D_THR_bpf_1d_sel_y(data)                                    (0x00000003&(data))
#define  VDPQ_BLEND_1D_THR_get_same_phase_diff_1d_gauge_en(data)                 ((0x00000100&(data))>>8)
#define  VDPQ_BLEND_1D_THR_get_blend_1d_thr(data)                                ((0x0000007C&(data))>>2)
#define  VDPQ_BLEND_1D_THR_get_bpf_1d_sel_y(data)                                (0x00000003&(data))

#define  VDPQ_BLEND_1D_BPF_SEL                                                   0x18019940
#define  VDPQ_BLEND_1D_BPF_SEL_reg_addr                                          "0xB8019940"
#define  VDPQ_BLEND_1D_BPF_SEL_reg                                               0xB8019940
#define  VDPQ_BLEND_1D_BPF_SEL_inst_addr                                         "0x0034"
#define  set_VDPQ_BLEND_1D_BPF_SEL_reg(data)                                     (*((volatile unsigned int*)VDPQ_BLEND_1D_BPF_SEL_reg)=data)
#define  get_VDPQ_BLEND_1D_BPF_SEL_reg                                           (*((volatile unsigned int*)VDPQ_BLEND_1D_BPF_SEL_reg))
#define  VDPQ_BLEND_1D_BPF_SEL_narrow_1d_bpf_sel_c_shift                         (4)
#define  VDPQ_BLEND_1D_BPF_SEL_wide_1d_bpf_sel_c_shift                           (0)
#define  VDPQ_BLEND_1D_BPF_SEL_narrow_1d_bpf_sel_c_mask                          (0x00000070)
#define  VDPQ_BLEND_1D_BPF_SEL_wide_1d_bpf_sel_c_mask                            (0x00000007)
#define  VDPQ_BLEND_1D_BPF_SEL_narrow_1d_bpf_sel_c(data)                         (0x00000070&((data)<<4))
#define  VDPQ_BLEND_1D_BPF_SEL_wide_1d_bpf_sel_c(data)                           (0x00000007&(data))
#define  VDPQ_BLEND_1D_BPF_SEL_get_narrow_1d_bpf_sel_c(data)                     ((0x00000070&(data))>>4)
#define  VDPQ_BLEND_1D_BPF_SEL_get_wide_1d_bpf_sel_c(data)                       (0x00000007&(data))

#define  VDPQ_ALPHA_2D_MOD_ENABLE                                                0x18019944
#define  VDPQ_ALPHA_2D_MOD_ENABLE_reg_addr                                       "0xB8019944"
#define  VDPQ_ALPHA_2D_MOD_ENABLE_reg                                            0xB8019944
#define  VDPQ_ALPHA_2D_MOD_ENABLE_inst_addr                                      "0x0035"
#define  set_VDPQ_ALPHA_2D_MOD_ENABLE_reg(data)                                  (*((volatile unsigned int*)VDPQ_ALPHA_2D_MOD_ENABLE_reg)=data)
#define  get_VDPQ_ALPHA_2D_MOD_ENABLE_reg                                        (*((volatile unsigned int*)VDPQ_ALPHA_2D_MOD_ENABLE_reg))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_force_halpha_en_shift                          (31)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_halpha_shift                                   (24)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_large_th_shift                             (16)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_fuzzy_th_shift                             (12)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_sel_y_shift                                (8)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_sel_c_shift                                (4)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_h2v_coring_thr_shift                           (0)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_force_halpha_en_mask                           (0x80000000)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_halpha_mask                                    (0x0F000000)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_large_th_mask                              (0x001F0000)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_fuzzy_th_mask                              (0x0000F000)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_sel_y_mask                                 (0x00000700)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_sel_c_mask                                 (0x00000070)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_h2v_coring_thr_mask                            (0x00000007)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_force_halpha_en(data)                          (0x80000000&((data)<<31))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_halpha(data)                                   (0x0F000000&((data)<<24))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_large_th(data)                             (0x001F0000&((data)<<16))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_fuzzy_th(data)                             (0x0000F000&((data)<<12))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_sel_y(data)                                (0x00000700&((data)<<8))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_lut_sel_c(data)                                (0x00000070&((data)<<4))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_h2v_coring_thr(data)                           (0x00000007&(data))
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_force_halpha_en(data)                      ((0x80000000&(data))>>31)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_halpha(data)                               ((0x0F000000&(data))>>24)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_lut_large_th(data)                         ((0x001F0000&(data))>>16)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_lut_fuzzy_th(data)                         ((0x0000F000&(data))>>12)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_lut_sel_y(data)                            ((0x00000700&(data))>>8)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_lut_sel_c(data)                            ((0x00000070&(data))>>4)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_get_h2v_coring_thr(data)                       (0x00000007&(data))

#define  VDPQ_H2V_CORING_THR                                                     0x18019948
#define  VDPQ_H2V_CORING_THR_reg_addr                                            "0xB8019948"
#define  VDPQ_H2V_CORING_THR_reg                                                 0xB8019948
#define  VDPQ_H2V_CORING_THR_inst_addr                                           "0x0036"
#define  set_VDPQ_H2V_CORING_THR_reg(data)                                       (*((volatile unsigned int*)VDPQ_H2V_CORING_THR_reg)=data)
#define  get_VDPQ_H2V_CORING_THR_reg                                             (*((volatile unsigned int*)VDPQ_H2V_CORING_THR_reg))
#define  VDPQ_H2V_CORING_THR_h2v_lut_hprefer_ratio_shift                         (16)
#define  VDPQ_H2V_CORING_THR_h2v_lut_hv_large_th_shift                           (8)
#define  VDPQ_H2V_CORING_THR_h2v_cvbs_coring_thr_shift                           (4)
#define  VDPQ_H2V_CORING_THR_h2v_bw_color_gain_shift                             (0)
#define  VDPQ_H2V_CORING_THR_h2v_lut_hprefer_ratio_mask                          (0x000F0000)
#define  VDPQ_H2V_CORING_THR_h2v_lut_hv_large_th_mask                            (0x00003F00)
#define  VDPQ_H2V_CORING_THR_h2v_cvbs_coring_thr_mask                            (0x00000070)
#define  VDPQ_H2V_CORING_THR_h2v_bw_color_gain_mask                              (0x0000000F)
#define  VDPQ_H2V_CORING_THR_h2v_lut_hprefer_ratio(data)                         (0x000F0000&((data)<<16))
#define  VDPQ_H2V_CORING_THR_h2v_lut_hv_large_th(data)                           (0x00003F00&((data)<<8))
#define  VDPQ_H2V_CORING_THR_h2v_cvbs_coring_thr(data)                           (0x00000070&((data)<<4))
#define  VDPQ_H2V_CORING_THR_h2v_bw_color_gain(data)                             (0x0000000F&(data))
#define  VDPQ_H2V_CORING_THR_get_h2v_lut_hprefer_ratio(data)                     ((0x000F0000&(data))>>16)
#define  VDPQ_H2V_CORING_THR_get_h2v_lut_hv_large_th(data)                       ((0x00003F00&(data))>>8)
#define  VDPQ_H2V_CORING_THR_get_h2v_cvbs_coring_thr(data)                       ((0x00000070&(data))>>4)
#define  VDPQ_H2V_CORING_THR_get_h2v_bw_color_gain(data)                         (0x0000000F&(data))

#define  VDPQ_H2V_Y_NOISE_THR                                                    0x1801994C
#define  VDPQ_H2V_Y_NOISE_THR_reg_addr                                           "0xB801994C"
#define  VDPQ_H2V_Y_NOISE_THR_reg                                                0xB801994C
#define  VDPQ_H2V_Y_NOISE_THR_inst_addr                                          "0x0037"
#define  set_VDPQ_H2V_Y_NOISE_THR_reg(data)                                      (*((volatile unsigned int*)VDPQ_H2V_Y_NOISE_THR_reg)=data)
#define  get_VDPQ_H2V_Y_NOISE_THR_reg                                            (*((volatile unsigned int*)VDPQ_H2V_Y_NOISE_THR_reg))
#define  VDPQ_H2V_Y_NOISE_THR_h2v_y_noise_thr_shift                              (0)
#define  VDPQ_H2V_Y_NOISE_THR_h2v_y_noise_thr_mask                               (0x000000FF)
#define  VDPQ_H2V_Y_NOISE_THR_h2v_y_noise_thr(data)                              (0x000000FF&(data))
#define  VDPQ_H2V_Y_NOISE_THR_get_h2v_y_noise_thr(data)                          (0x000000FF&(data))

#define  VDPQ_H2V_CVBS_NOISE_THR                                                 0x18019950
#define  VDPQ_H2V_CVBS_NOISE_THR_reg_addr                                        "0xB8019950"
#define  VDPQ_H2V_CVBS_NOISE_THR_reg                                             0xB8019950
#define  VDPQ_H2V_CVBS_NOISE_THR_inst_addr                                       "0x0038"
#define  set_VDPQ_H2V_CVBS_NOISE_THR_reg(data)                                   (*((volatile unsigned int*)VDPQ_H2V_CVBS_NOISE_THR_reg)=data)
#define  get_VDPQ_H2V_CVBS_NOISE_THR_reg                                         (*((volatile unsigned int*)VDPQ_H2V_CVBS_NOISE_THR_reg))
#define  VDPQ_H2V_CVBS_NOISE_THR_h2v_cvbs_noise_thr_shift                        (0)
#define  VDPQ_H2V_CVBS_NOISE_THR_h2v_cvbs_noise_thr_mask                         (0x000000FF)
#define  VDPQ_H2V_CVBS_NOISE_THR_h2v_cvbs_noise_thr(data)                        (0x000000FF&(data))
#define  VDPQ_H2V_CVBS_NOISE_THR_get_h2v_cvbs_noise_thr(data)                    (0x000000FF&(data))

#define  VDPQ_H2V_NOISE_MAX_HDY                                                  0x18019954
#define  VDPQ_H2V_NOISE_MAX_HDY_reg_addr                                         "0xB8019954"
#define  VDPQ_H2V_NOISE_MAX_HDY_reg                                              0xB8019954
#define  VDPQ_H2V_NOISE_MAX_HDY_inst_addr                                        "0x0039"
#define  set_VDPQ_H2V_NOISE_MAX_HDY_reg(data)                                    (*((volatile unsigned int*)VDPQ_H2V_NOISE_MAX_HDY_reg)=data)
#define  get_VDPQ_H2V_NOISE_MAX_HDY_reg                                          (*((volatile unsigned int*)VDPQ_H2V_NOISE_MAX_HDY_reg))
#define  VDPQ_H2V_NOISE_MAX_HDY_h2v_noise_max_hdy_shift                          (0)
#define  VDPQ_H2V_NOISE_MAX_HDY_h2v_noise_max_hdy_mask                           (0x000000FF)
#define  VDPQ_H2V_NOISE_MAX_HDY_h2v_noise_max_hdy(data)                          (0x000000FF&(data))
#define  VDPQ_H2V_NOISE_MAX_HDY_get_h2v_noise_max_hdy(data)                      (0x000000FF&(data))

#define  VDPQ_H2V_NOISE_Y_ADD_DC                                                 0x18019958
#define  VDPQ_H2V_NOISE_Y_ADD_DC_reg_addr                                        "0xB8019958"
#define  VDPQ_H2V_NOISE_Y_ADD_DC_reg                                             0xB8019958
#define  VDPQ_H2V_NOISE_Y_ADD_DC_inst_addr                                       "0x003A"
#define  set_VDPQ_H2V_NOISE_Y_ADD_DC_reg(data)                                   (*((volatile unsigned int*)VDPQ_H2V_NOISE_Y_ADD_DC_reg)=data)
#define  get_VDPQ_H2V_NOISE_Y_ADD_DC_reg                                         (*((volatile unsigned int*)VDPQ_H2V_NOISE_Y_ADD_DC_reg))
#define  VDPQ_H2V_NOISE_Y_ADD_DC_v2v_lut_sel_y_shift                             (8)
#define  VDPQ_H2V_NOISE_Y_ADD_DC_v2v_noise_y_add_dc_shift                        (0)
#define  VDPQ_H2V_NOISE_Y_ADD_DC_v2v_lut_sel_y_mask                              (0x00000100)
#define  VDPQ_H2V_NOISE_Y_ADD_DC_v2v_noise_y_add_dc_mask                         (0x000000FF)
#define  VDPQ_H2V_NOISE_Y_ADD_DC_v2v_lut_sel_y(data)                             (0x00000100&((data)<<8))
#define  VDPQ_H2V_NOISE_Y_ADD_DC_v2v_noise_y_add_dc(data)                        (0x000000FF&(data))
#define  VDPQ_H2V_NOISE_Y_ADD_DC_get_v2v_lut_sel_y(data)                         ((0x00000100&(data))>>8)
#define  VDPQ_H2V_NOISE_Y_ADD_DC_get_v2v_noise_y_add_dc(data)                    (0x000000FF&(data))

#define  VDPQ_H2V_BLEND_RATIO                                                    0x1801995C
#define  VDPQ_H2V_BLEND_RATIO_reg_addr                                           "0xB801995C"
#define  VDPQ_H2V_BLEND_RATIO_reg                                                0xB801995C
#define  VDPQ_H2V_BLEND_RATIO_inst_addr                                          "0x003B"
#define  set_VDPQ_H2V_BLEND_RATIO_reg(data)                                      (*((volatile unsigned int*)VDPQ_H2V_BLEND_RATIO_reg)=data)
#define  get_VDPQ_H2V_BLEND_RATIO_reg                                            (*((volatile unsigned int*)VDPQ_H2V_BLEND_RATIO_reg))
#define  VDPQ_H2V_BLEND_RATIO_h2v_blendratio_shift                               (0)
#define  VDPQ_H2V_BLEND_RATIO_h2v_blendratio_mask                                (0x00000007)
#define  VDPQ_H2V_BLEND_RATIO_h2v_blendratio(data)                               (0x00000007&(data))
#define  VDPQ_H2V_BLEND_RATIO_get_h2v_blendratio(data)                           (0x00000007&(data))

#define  VDPQ_ADAP_BPF_Y_TH2                                                     0x18019960
#define  VDPQ_ADAP_BPF_Y_TH2_reg_addr                                            "0xB8019960"
#define  VDPQ_ADAP_BPF_Y_TH2_reg                                                 0xB8019960
#define  VDPQ_ADAP_BPF_Y_TH2_inst_addr                                           "0x003C"
#define  set_VDPQ_ADAP_BPF_Y_TH2_reg(data)                                       (*((volatile unsigned int*)VDPQ_ADAP_BPF_Y_TH2_reg)=data)
#define  get_VDPQ_ADAP_BPF_Y_TH2_reg                                             (*((volatile unsigned int*)VDPQ_ADAP_BPF_Y_TH2_reg))
#define  VDPQ_ADAP_BPF_Y_TH2_xc_sel_gain_shift                                   (6)
#define  VDPQ_ADAP_BPF_Y_TH2_xc_sel_gain_mask                                    (0x000000C0)
#define  VDPQ_ADAP_BPF_Y_TH2_xc_sel_gain(data)                                   (0x000000C0&((data)<<6))
#define  VDPQ_ADAP_BPF_Y_TH2_get_xc_sel_gain(data)                               ((0x000000C0&(data))>>6)

#define  VDPQ_CDIFF_ADAP_BPF_TH1                                                 0x18019964
#define  VDPQ_CDIFF_ADAP_BPF_TH1_reg_addr                                        "0xB8019964"
#define  VDPQ_CDIFF_ADAP_BPF_TH1_reg                                             0xB8019964
#define  VDPQ_CDIFF_ADAP_BPF_TH1_inst_addr                                       "0x003D"
#define  set_VDPQ_CDIFF_ADAP_BPF_TH1_reg(data)                                   (*((volatile unsigned int*)VDPQ_CDIFF_ADAP_BPF_TH1_reg)=data)
#define  get_VDPQ_CDIFF_ADAP_BPF_TH1_reg                                         (*((volatile unsigned int*)VDPQ_CDIFF_ADAP_BPF_TH1_reg))
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_small_th_shift                     (16)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_diff_th_shift                      (8)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_hor_range_shift                       (5)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_ver_range_shift                       (4)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_small_th_mask                      (0x003F0000)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_diff_th_mask                       (0x0000FF00)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_hor_range_mask                        (0x00000020)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_ver_range_mask                        (0x00000010)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_small_th(data)                     (0x003F0000&((data)<<16))
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_mm_diff_th(data)                      (0x0000FF00&((data)<<8))
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_hor_range(data)                       (0x00000020&((data)<<5))
#define  VDPQ_CDIFF_ADAP_BPF_TH1_cdiff_bpf_ver_range(data)                       (0x00000010&((data)<<4))
#define  VDPQ_CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_mm_small_th(data)                 ((0x003F0000&(data))>>16)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_mm_diff_th(data)                  ((0x0000FF00&(data))>>8)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_hor_range(data)                   ((0x00000020&(data))>>5)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_get_cdiff_bpf_ver_range(data)                   ((0x00000010&(data))>>4)

#define  VDPQ_CDIFF_ADAP_BPF_TH2                                                 0x18019968
#define  VDPQ_CDIFF_ADAP_BPF_TH2_reg_addr                                        "0xB8019968"
#define  VDPQ_CDIFF_ADAP_BPF_TH2_reg                                             0xB8019968
#define  VDPQ_CDIFF_ADAP_BPF_TH2_inst_addr                                       "0x003E"
#define  set_VDPQ_CDIFF_ADAP_BPF_TH2_reg(data)                                   (*((volatile unsigned int*)VDPQ_CDIFF_ADAP_BPF_TH2_reg)=data)
#define  get_VDPQ_CDIFF_ADAP_BPF_TH2_reg                                         (*((volatile unsigned int*)VDPQ_CDIFF_ADAP_BPF_TH2_reg))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_vspd_small_th_shift                   (24)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_low_sat_th_shift                      (16)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_offset_shift                    (12)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_amp_wei_shift                   (8)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_offset_shift                    (4)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_amp_wei_shift                   (0)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_vspd_small_th_mask                    (0x3F000000)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_low_sat_th_mask                       (0x003F0000)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_offset_mask                     (0x0000F000)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_amp_wei_mask                    (0x00000700)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_offset_mask                     (0x000000F0)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_amp_wei_mask                    (0x00000007)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_vspd_small_th(data)                   (0x3F000000&((data)<<24))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_low_sat_th(data)                      (0x003F0000&((data)<<16))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_offset(data)                    (0x0000F000&((data)<<12))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_large_amp_wei(data)                   (0x00000700&((data)<<8))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_offset(data)                    (0x000000F0&((data)<<4))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_cdiff_bpf_small_amp_wei(data)                   (0x00000007&(data))
#define  VDPQ_CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_vspd_small_th(data)               ((0x3F000000&(data))>>24)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_low_sat_th(data)                  ((0x003F0000&(data))>>16)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_large_offset(data)                ((0x0000F000&(data))>>12)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_large_amp_wei(data)               ((0x00000700&(data))>>8)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_small_offset(data)                ((0x000000F0&(data))>>4)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_get_cdiff_bpf_small_amp_wei(data)               (0x00000007&(data))

#define  VDPQ_BPF_VEDGE_CTRL1                                                    0x18019970
#define  VDPQ_BPF_VEDGE_CTRL1_reg_addr                                           "0xB8019970"
#define  VDPQ_BPF_VEDGE_CTRL1_reg                                                0xB8019970
#define  VDPQ_BPF_VEDGE_CTRL1_inst_addr                                          "0x003F"
#define  set_VDPQ_BPF_VEDGE_CTRL1_reg(data)                                      (*((volatile unsigned int*)VDPQ_BPF_VEDGE_CTRL1_reg)=data)
#define  get_VDPQ_BPF_VEDGE_CTRL1_reg                                            (*((volatile unsigned int*)VDPQ_BPF_VEDGE_CTRL1_reg))
#define  VDPQ_BPF_VEDGE_CTRL1_hvdiff_comp_offset_shift                           (16)
#define  VDPQ_BPF_VEDGE_CTRL1_hvdiff_comp_multiple_shift                         (12)
#define  VDPQ_BPF_VEDGE_CTRL1_diff_tolerance_shift                               (4)
#define  VDPQ_BPF_VEDGE_CTRL1_vedge_en_shift                                     (0)
#define  VDPQ_BPF_VEDGE_CTRL1_hvdiff_comp_offset_mask                            (0x00FF0000)
#define  VDPQ_BPF_VEDGE_CTRL1_hvdiff_comp_multiple_mask                          (0x0000F000)
#define  VDPQ_BPF_VEDGE_CTRL1_diff_tolerance_mask                                (0x000001F0)
#define  VDPQ_BPF_VEDGE_CTRL1_vedge_en_mask                                      (0x00000001)
#define  VDPQ_BPF_VEDGE_CTRL1_hvdiff_comp_offset(data)                           (0x00FF0000&((data)<<16))
#define  VDPQ_BPF_VEDGE_CTRL1_hvdiff_comp_multiple(data)                         (0x0000F000&((data)<<12))
#define  VDPQ_BPF_VEDGE_CTRL1_diff_tolerance(data)                               (0x000001F0&((data)<<4))
#define  VDPQ_BPF_VEDGE_CTRL1_vedge_en(data)                                     (0x00000001&(data))
#define  VDPQ_BPF_VEDGE_CTRL1_get_hvdiff_comp_offset(data)                       ((0x00FF0000&(data))>>16)
#define  VDPQ_BPF_VEDGE_CTRL1_get_hvdiff_comp_multiple(data)                     ((0x0000F000&(data))>>12)
#define  VDPQ_BPF_VEDGE_CTRL1_get_diff_tolerance(data)                           ((0x000001F0&(data))>>4)
#define  VDPQ_BPF_VEDGE_CTRL1_get_vedge_en(data)                                 (0x00000001&(data))

#define  VDPQ_BPF_VEDGE_CTRL2                                                    0x18019974
#define  VDPQ_BPF_VEDGE_CTRL2_reg_addr                                           "0xB8019974"
#define  VDPQ_BPF_VEDGE_CTRL2_reg                                                0xB8019974
#define  VDPQ_BPF_VEDGE_CTRL2_inst_addr                                          "0x0040"
#define  set_VDPQ_BPF_VEDGE_CTRL2_reg(data)                                      (*((volatile unsigned int*)VDPQ_BPF_VEDGE_CTRL2_reg)=data)
#define  get_VDPQ_BPF_VEDGE_CTRL2_reg                                            (*((volatile unsigned int*)VDPQ_BPF_VEDGE_CTRL2_reg))
#define  VDPQ_BPF_VEDGE_CTRL2_c_follow_y_en_shift                                (16)
#define  VDPQ_BPF_VEDGE_CTRL2_hdiff_lowbound_shift                               (8)
#define  VDPQ_BPF_VEDGE_CTRL2_vdiff_upbound_shift                                (0)
#define  VDPQ_BPF_VEDGE_CTRL2_c_follow_y_en_mask                                 (0x00010000)
#define  VDPQ_BPF_VEDGE_CTRL2_hdiff_lowbound_mask                                (0x00007F00)
#define  VDPQ_BPF_VEDGE_CTRL2_vdiff_upbound_mask                                 (0x0000001F)
#define  VDPQ_BPF_VEDGE_CTRL2_c_follow_y_en(data)                                (0x00010000&((data)<<16))
#define  VDPQ_BPF_VEDGE_CTRL2_hdiff_lowbound(data)                               (0x00007F00&((data)<<8))
#define  VDPQ_BPF_VEDGE_CTRL2_vdiff_upbound(data)                                (0x0000001F&(data))
#define  VDPQ_BPF_VEDGE_CTRL2_get_c_follow_y_en(data)                            ((0x00010000&(data))>>16)
#define  VDPQ_BPF_VEDGE_CTRL2_get_hdiff_lowbound(data)                           ((0x00007F00&(data))>>8)
#define  VDPQ_BPF_VEDGE_CTRL2_get_vdiff_upbound(data)                            (0x0000001F&(data))

#define  VDPQ_BYPASS_BPF_CTRL1                                                   0x18019978
#define  VDPQ_BYPASS_BPF_CTRL1_reg_addr                                          "0xB8019978"
#define  VDPQ_BYPASS_BPF_CTRL1_reg                                               0xB8019978
#define  VDPQ_BYPASS_BPF_CTRL1_inst_addr                                         "0x0041"
#define  set_VDPQ_BYPASS_BPF_CTRL1_reg(data)                                     (*((volatile unsigned int*)VDPQ_BYPASS_BPF_CTRL1_reg)=data)
#define  get_VDPQ_BYPASS_BPF_CTRL1_reg                                           (*((volatile unsigned int*)VDPQ_BYPASS_BPF_CTRL1_reg))
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_ratio_shift                               (28)
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_lower_th_shift                            (20)
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_th_shift                                  (12)
#define  VDPQ_BYPASS_BPF_CTRL1_complex_level_th_shift                            (4)
#define  VDPQ_BYPASS_BPF_CTRL1_complex_level_mode_sel_shift                      (1)
#define  VDPQ_BYPASS_BPF_CTRL1_bypassbpf_adap_en_shift                           (0)
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_ratio_mask                                (0xF0000000)
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_lower_th_mask                             (0x03F00000)
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_th_mask                                   (0x0007F000)
#define  VDPQ_BYPASS_BPF_CTRL1_complex_level_th_mask                             (0x00000FF0)
#define  VDPQ_BYPASS_BPF_CTRL1_complex_level_mode_sel_mask                       (0x00000002)
#define  VDPQ_BYPASS_BPF_CTRL1_bypassbpf_adap_en_mask                            (0x00000001)
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_ratio(data)                               (0xF0000000&((data)<<28))
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_lower_th(data)                            (0x03F00000&((data)<<20))
#define  VDPQ_BYPASS_BPF_CTRL1_lr_diff_th(data)                                  (0x0007F000&((data)<<12))
#define  VDPQ_BYPASS_BPF_CTRL1_complex_level_th(data)                            (0x00000FF0&((data)<<4))
#define  VDPQ_BYPASS_BPF_CTRL1_complex_level_mode_sel(data)                      (0x00000002&((data)<<1))
#define  VDPQ_BYPASS_BPF_CTRL1_bypassbpf_adap_en(data)                           (0x00000001&(data))
#define  VDPQ_BYPASS_BPF_CTRL1_get_lr_diff_ratio(data)                           ((0xF0000000&(data))>>28)
#define  VDPQ_BYPASS_BPF_CTRL1_get_lr_diff_lower_th(data)                        ((0x03F00000&(data))>>20)
#define  VDPQ_BYPASS_BPF_CTRL1_get_lr_diff_th(data)                              ((0x0007F000&(data))>>12)
#define  VDPQ_BYPASS_BPF_CTRL1_get_complex_level_th(data)                        ((0x00000FF0&(data))>>4)
#define  VDPQ_BYPASS_BPF_CTRL1_get_complex_level_mode_sel(data)                  ((0x00000002&(data))>>1)
#define  VDPQ_BYPASS_BPF_CTRL1_get_bypassbpf_adap_en(data)                       (0x00000001&(data))

#define  VDPQ_BYPASS_BPF_CTRL2                                                   0x1801997C
#define  VDPQ_BYPASS_BPF_CTRL2_reg_addr                                          "0xB801997C"
#define  VDPQ_BYPASS_BPF_CTRL2_reg                                               0xB801997C
#define  VDPQ_BYPASS_BPF_CTRL2_inst_addr                                         "0x0042"
#define  set_VDPQ_BYPASS_BPF_CTRL2_reg(data)                                     (*((volatile unsigned int*)VDPQ_BYPASS_BPF_CTRL2_reg)=data)
#define  get_VDPQ_BYPASS_BPF_CTRL2_reg                                           (*((volatile unsigned int*)VDPQ_BYPASS_BPF_CTRL2_reg))
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_lr_diff_th_shift                         (16)
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_vdiff_ratio_shift                        (12)
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_vdiff_th_shift                           (4)
#define  VDPQ_BYPASS_BPF_CTRL2_lr_ratio_th_shift                                 (0)
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_lr_diff_th_mask                          (0x007F0000)
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_vdiff_ratio_mask                         (0x0000F000)
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_vdiff_th_mask                            (0x000007F0)
#define  VDPQ_BYPASS_BPF_CTRL2_lr_ratio_th_mask                                  (0x0000000F)
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_lr_diff_th(data)                         (0x007F0000&((data)<<16))
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_vdiff_ratio(data)                        (0x0000F000&((data)<<12))
#define  VDPQ_BYPASS_BPF_CTRL2_newvedge_vdiff_th(data)                           (0x000007F0&((data)<<4))
#define  VDPQ_BYPASS_BPF_CTRL2_lr_ratio_th(data)                                 (0x0000000F&(data))
#define  VDPQ_BYPASS_BPF_CTRL2_get_newvedge_lr_diff_th(data)                     ((0x007F0000&(data))>>16)
#define  VDPQ_BYPASS_BPF_CTRL2_get_newvedge_vdiff_ratio(data)                    ((0x0000F000&(data))>>12)
#define  VDPQ_BYPASS_BPF_CTRL2_get_newvedge_vdiff_th(data)                       ((0x000007F0&(data))>>4)
#define  VDPQ_BYPASS_BPF_CTRL2_get_lr_ratio_th(data)                             (0x0000000F&(data))

#define  VDPQ_gridgirl_ctrl                                                      0x18019988
#define  VDPQ_gridgirl_ctrl_reg_addr                                             "0xB8019988"
#define  VDPQ_gridgirl_ctrl_reg                                                  0xB8019988
#define  VDPQ_gridgirl_ctrl_inst_addr                                            "0x0043"
#define  set_VDPQ_gridgirl_ctrl_reg(data)                                        (*((volatile unsigned int*)VDPQ_gridgirl_ctrl_reg)=data)
#define  get_VDPQ_gridgirl_ctrl_reg                                              (*((volatile unsigned int*)VDPQ_gridgirl_ctrl_reg))
#define  VDPQ_gridgirl_ctrl_debug_mode_gridgirl_shift                            (31)
#define  VDPQ_gridgirl_ctrl_grid_cvbs_diff_th_shift                              (8)
#define  VDPQ_gridgirl_ctrl_gridgirl_corr_en_shift                               (3)
#define  VDPQ_gridgirl_ctrl_grid_reset_sel_shift                                 (2)
#define  VDPQ_gridgirl_ctrl_grid_use_preflag_en_shift                            (1)
#define  VDPQ_gridgirl_ctrl_gridgirl_en_shift                                    (0)
#define  VDPQ_gridgirl_ctrl_debug_mode_gridgirl_mask                             (0x80000000)
#define  VDPQ_gridgirl_ctrl_grid_cvbs_diff_th_mask                               (0x0000FF00)
#define  VDPQ_gridgirl_ctrl_gridgirl_corr_en_mask                                (0x00000008)
#define  VDPQ_gridgirl_ctrl_grid_reset_sel_mask                                  (0x00000004)
#define  VDPQ_gridgirl_ctrl_grid_use_preflag_en_mask                             (0x00000002)
#define  VDPQ_gridgirl_ctrl_gridgirl_en_mask                                     (0x00000001)
#define  VDPQ_gridgirl_ctrl_debug_mode_gridgirl(data)                            (0x80000000&((data)<<31))
#define  VDPQ_gridgirl_ctrl_grid_cvbs_diff_th(data)                              (0x0000FF00&((data)<<8))
#define  VDPQ_gridgirl_ctrl_gridgirl_corr_en(data)                               (0x00000008&((data)<<3))
#define  VDPQ_gridgirl_ctrl_grid_reset_sel(data)                                 (0x00000004&((data)<<2))
#define  VDPQ_gridgirl_ctrl_grid_use_preflag_en(data)                            (0x00000002&((data)<<1))
#define  VDPQ_gridgirl_ctrl_gridgirl_en(data)                                    (0x00000001&(data))
#define  VDPQ_gridgirl_ctrl_get_debug_mode_gridgirl(data)                        ((0x80000000&(data))>>31)
#define  VDPQ_gridgirl_ctrl_get_grid_cvbs_diff_th(data)                          ((0x0000FF00&(data))>>8)
#define  VDPQ_gridgirl_ctrl_get_gridgirl_corr_en(data)                           ((0x00000008&(data))>>3)
#define  VDPQ_gridgirl_ctrl_get_grid_reset_sel(data)                             ((0x00000004&(data))>>2)
#define  VDPQ_gridgirl_ctrl_get_grid_use_preflag_en(data)                        ((0x00000002&(data))>>1)
#define  VDPQ_gridgirl_ctrl_get_gridgirl_en(data)                                (0x00000001&(data))

#define  VDPQ_gridgirl_th1                                                       0x1801998C
#define  VDPQ_gridgirl_th1_reg_addr                                              "0xB801998C"
#define  VDPQ_gridgirl_th1_reg                                                   0xB801998C
#define  VDPQ_gridgirl_th1_inst_addr                                             "0x0044"
#define  set_VDPQ_gridgirl_th1_reg(data)                                         (*((volatile unsigned int*)VDPQ_gridgirl_th1_reg)=data)
#define  get_VDPQ_gridgirl_th1_reg                                               (*((volatile unsigned int*)VDPQ_gridgirl_th1_reg))
#define  VDPQ_gridgirl_th1_grid_chroma_th2_shift                                 (24)
#define  VDPQ_gridgirl_th1_grid_chroma_th1_shift                                 (16)
#define  VDPQ_gridgirl_th1_grid_hordiff_th2_shift                                (8)
#define  VDPQ_gridgirl_th1_grid_hordiff_th1_shift                                (0)
#define  VDPQ_gridgirl_th1_grid_chroma_th2_mask                                  (0xFF000000)
#define  VDPQ_gridgirl_th1_grid_chroma_th1_mask                                  (0x00FF0000)
#define  VDPQ_gridgirl_th1_grid_hordiff_th2_mask                                 (0x0000FF00)
#define  VDPQ_gridgirl_th1_grid_hordiff_th1_mask                                 (0x000000FF)
#define  VDPQ_gridgirl_th1_grid_chroma_th2(data)                                 (0xFF000000&((data)<<24))
#define  VDPQ_gridgirl_th1_grid_chroma_th1(data)                                 (0x00FF0000&((data)<<16))
#define  VDPQ_gridgirl_th1_grid_hordiff_th2(data)                                (0x0000FF00&((data)<<8))
#define  VDPQ_gridgirl_th1_grid_hordiff_th1(data)                                (0x000000FF&(data))
#define  VDPQ_gridgirl_th1_get_grid_chroma_th2(data)                             ((0xFF000000&(data))>>24)
#define  VDPQ_gridgirl_th1_get_grid_chroma_th1(data)                             ((0x00FF0000&(data))>>16)
#define  VDPQ_gridgirl_th1_get_grid_hordiff_th2(data)                            ((0x0000FF00&(data))>>8)
#define  VDPQ_gridgirl_th1_get_grid_hordiff_th1(data)                            (0x000000FF&(data))

#define  VDPQ_gridgirl_th2                                                       0x18019990
#define  VDPQ_gridgirl_th2_reg_addr                                              "0xB8019990"
#define  VDPQ_gridgirl_th2_reg                                                   0xB8019990
#define  VDPQ_gridgirl_th2_inst_addr                                             "0x0045"
#define  set_VDPQ_gridgirl_th2_reg(data)                                         (*((volatile unsigned int*)VDPQ_gridgirl_th2_reg)=data)
#define  get_VDPQ_gridgirl_th2_reg                                               (*((volatile unsigned int*)VDPQ_gridgirl_th2_reg))
#define  VDPQ_gridgirl_th2_grid_linecnt_th2_shift                                (24)
#define  VDPQ_gridgirl_th2_grid_linecnt_th1_shift                                (16)
#define  VDPQ_gridgirl_th2_grid_linesum_th2_shift                                (8)
#define  VDPQ_gridgirl_th2_grid_linesum_th1_shift                                (0)
#define  VDPQ_gridgirl_th2_grid_linecnt_th2_mask                                 (0xFF000000)
#define  VDPQ_gridgirl_th2_grid_linecnt_th1_mask                                 (0x00FF0000)
#define  VDPQ_gridgirl_th2_grid_linesum_th2_mask                                 (0x0000FF00)
#define  VDPQ_gridgirl_th2_grid_linesum_th1_mask                                 (0x000000FF)
#define  VDPQ_gridgirl_th2_grid_linecnt_th2(data)                                (0xFF000000&((data)<<24))
#define  VDPQ_gridgirl_th2_grid_linecnt_th1(data)                                (0x00FF0000&((data)<<16))
#define  VDPQ_gridgirl_th2_grid_linesum_th2(data)                                (0x0000FF00&((data)<<8))
#define  VDPQ_gridgirl_th2_grid_linesum_th1(data)                                (0x000000FF&(data))
#define  VDPQ_gridgirl_th2_get_grid_linecnt_th2(data)                            ((0xFF000000&(data))>>24)
#define  VDPQ_gridgirl_th2_get_grid_linecnt_th1(data)                            ((0x00FF0000&(data))>>16)
#define  VDPQ_gridgirl_th2_get_grid_linesum_th2(data)                            ((0x0000FF00&(data))>>8)
#define  VDPQ_gridgirl_th2_get_grid_linesum_th1(data)                            (0x000000FF&(data))

#define  VDPQ_gridgirl_th3                                                       0x18019994
#define  VDPQ_gridgirl_th3_reg_addr                                              "0xB8019994"
#define  VDPQ_gridgirl_th3_reg                                                   0xB8019994
#define  VDPQ_gridgirl_th3_inst_addr                                             "0x0046"
#define  set_VDPQ_gridgirl_th3_reg(data)                                         (*((volatile unsigned int*)VDPQ_gridgirl_th3_reg)=data)
#define  get_VDPQ_gridgirl_th3_reg                                               (*((volatile unsigned int*)VDPQ_gridgirl_th3_reg))
#define  VDPQ_gridgirl_th3_grid_sum_right_bound_shift                            (16)
#define  VDPQ_gridgirl_th3_grid_sum_left_bound_shift                             (0)
#define  VDPQ_gridgirl_th3_grid_sum_right_bound_mask                             (0x07FF0000)
#define  VDPQ_gridgirl_th3_grid_sum_left_bound_mask                              (0x000007FF)
#define  VDPQ_gridgirl_th3_grid_sum_right_bound(data)                            (0x07FF0000&((data)<<16))
#define  VDPQ_gridgirl_th3_grid_sum_left_bound(data)                             (0x000007FF&(data))
#define  VDPQ_gridgirl_th3_get_grid_sum_right_bound(data)                        ((0x07FF0000&(data))>>16)
#define  VDPQ_gridgirl_th3_get_grid_sum_left_bound(data)                         (0x000007FF&(data))

#define  VDPQ_gridgirl_th4                                                       0x18019998
#define  VDPQ_gridgirl_th4_reg_addr                                              "0xB8019998"
#define  VDPQ_gridgirl_th4_reg                                                   0xB8019998
#define  VDPQ_gridgirl_th4_inst_addr                                             "0x0047"
#define  set_VDPQ_gridgirl_th4_reg(data)                                         (*((volatile unsigned int*)VDPQ_gridgirl_th4_reg)=data)
#define  get_VDPQ_gridgirl_th4_reg                                               (*((volatile unsigned int*)VDPQ_gridgirl_th4_reg))
#define  VDPQ_gridgirl_th4_grid_right_bound_shift                                (16)
#define  VDPQ_gridgirl_th4_grid_left_bound_shift                                 (0)
#define  VDPQ_gridgirl_th4_grid_right_bound_mask                                 (0x07FF0000)
#define  VDPQ_gridgirl_th4_grid_left_bound_mask                                  (0x000007FF)
#define  VDPQ_gridgirl_th4_grid_right_bound(data)                                (0x07FF0000&((data)<<16))
#define  VDPQ_gridgirl_th4_grid_left_bound(data)                                 (0x000007FF&(data))
#define  VDPQ_gridgirl_th4_get_grid_right_bound(data)                            ((0x07FF0000&(data))>>16)
#define  VDPQ_gridgirl_th4_get_grid_left_bound(data)                             (0x000007FF&(data))

#define  VDPQ_DIAMC_CVBS_AMP_TH                                                  0x1801999C
#define  VDPQ_DIAMC_CVBS_AMP_TH_reg_addr                                         "0xB801999C"
#define  VDPQ_DIAMC_CVBS_AMP_TH_reg                                              0xB801999C
#define  VDPQ_DIAMC_CVBS_AMP_TH_inst_addr                                        "0x0048"
#define  set_VDPQ_DIAMC_CVBS_AMP_TH_reg(data)                                    (*((volatile unsigned int*)VDPQ_DIAMC_CVBS_AMP_TH_reg)=data)
#define  get_VDPQ_DIAMC_CVBS_AMP_TH_reg                                          (*((volatile unsigned int*)VDPQ_DIAMC_CVBS_AMP_TH_reg))
#define  VDPQ_DIAMC_CVBS_AMP_TH_vmc_widehspd_small_th_shift                      (8)
#define  VDPQ_DIAMC_CVBS_AMP_TH_diamc_cvbsamp_still_th_shift                     (0)
#define  VDPQ_DIAMC_CVBS_AMP_TH_vmc_widehspd_small_th_mask                       (0x00003F00)
#define  VDPQ_DIAMC_CVBS_AMP_TH_diamc_cvbsamp_still_th_mask                      (0x0000003F)
#define  VDPQ_DIAMC_CVBS_AMP_TH_vmc_widehspd_small_th(data)                      (0x00003F00&((data)<<8))
#define  VDPQ_DIAMC_CVBS_AMP_TH_diamc_cvbsamp_still_th(data)                     (0x0000003F&(data))
#define  VDPQ_DIAMC_CVBS_AMP_TH_get_vmc_widehspd_small_th(data)                  ((0x00003F00&(data))>>8)
#define  VDPQ_DIAMC_CVBS_AMP_TH_get_diamc_cvbsamp_still_th(data)                 (0x0000003F&(data))

#define  VDPQ_DIAMC_CTRL                                                         0x180199A0
#define  VDPQ_DIAMC_CTRL_reg_addr                                                "0xB80199A0"
#define  VDPQ_DIAMC_CTRL_reg                                                     0xB80199A0
#define  VDPQ_DIAMC_CTRL_inst_addr                                               "0x0049"
#define  set_VDPQ_DIAMC_CTRL_reg(data)                                           (*((volatile unsigned int*)VDPQ_DIAMC_CTRL_reg)=data)
#define  get_VDPQ_DIAMC_CTRL_reg                                                 (*((volatile unsigned int*)VDPQ_DIAMC_CTRL_reg))
#define  VDPQ_DIAMC_CTRL_diamc_dc_still_th_offset_shift                          (24)
#define  VDPQ_DIAMC_CTRL_diamc_dc_still_th_weight_shift                          (20)
#define  VDPQ_DIAMC_CTRL_diamc_y_v_line_id_cnt_th_shift                          (16)
#define  VDPQ_DIAMC_CTRL_diamc_fid_th_weight_shift                               (12)
#define  VDPQ_DIAMC_CTRL_diamc_amp_low_bnd_shift                                 (4)
#define  VDPQ_DIAMC_CTRL_diamc_all_line_match_en_shift                           (2)
#define  VDPQ_DIAMC_CTRL_diamc_perfect_fid_en_shift                              (1)
#define  VDPQ_DIAMC_CTRL_diamc_en_shift                                          (0)
#define  VDPQ_DIAMC_CTRL_diamc_dc_still_th_offset_mask                           (0x3F000000)
#define  VDPQ_DIAMC_CTRL_diamc_dc_still_th_weight_mask                           (0x00F00000)
#define  VDPQ_DIAMC_CTRL_diamc_y_v_line_id_cnt_th_mask                           (0x00030000)
#define  VDPQ_DIAMC_CTRL_diamc_fid_th_weight_mask                                (0x00007000)
#define  VDPQ_DIAMC_CTRL_diamc_amp_low_bnd_mask                                  (0x000007F0)
#define  VDPQ_DIAMC_CTRL_diamc_all_line_match_en_mask                            (0x00000004)
#define  VDPQ_DIAMC_CTRL_diamc_perfect_fid_en_mask                               (0x00000002)
#define  VDPQ_DIAMC_CTRL_diamc_en_mask                                           (0x00000001)
#define  VDPQ_DIAMC_CTRL_diamc_dc_still_th_offset(data)                          (0x3F000000&((data)<<24))
#define  VDPQ_DIAMC_CTRL_diamc_dc_still_th_weight(data)                          (0x00F00000&((data)<<20))
#define  VDPQ_DIAMC_CTRL_diamc_y_v_line_id_cnt_th(data)                          (0x00030000&((data)<<16))
#define  VDPQ_DIAMC_CTRL_diamc_fid_th_weight(data)                               (0x00007000&((data)<<12))
#define  VDPQ_DIAMC_CTRL_diamc_amp_low_bnd(data)                                 (0x000007F0&((data)<<4))
#define  VDPQ_DIAMC_CTRL_diamc_all_line_match_en(data)                           (0x00000004&((data)<<2))
#define  VDPQ_DIAMC_CTRL_diamc_perfect_fid_en(data)                              (0x00000002&((data)<<1))
#define  VDPQ_DIAMC_CTRL_diamc_en(data)                                          (0x00000001&(data))
#define  VDPQ_DIAMC_CTRL_get_diamc_dc_still_th_offset(data)                      ((0x3F000000&(data))>>24)
#define  VDPQ_DIAMC_CTRL_get_diamc_dc_still_th_weight(data)                      ((0x00F00000&(data))>>20)
#define  VDPQ_DIAMC_CTRL_get_diamc_y_v_line_id_cnt_th(data)                      ((0x00030000&(data))>>16)
#define  VDPQ_DIAMC_CTRL_get_diamc_fid_th_weight(data)                           ((0x00007000&(data))>>12)
#define  VDPQ_DIAMC_CTRL_get_diamc_amp_low_bnd(data)                             ((0x000007F0&(data))>>4)
#define  VDPQ_DIAMC_CTRL_get_diamc_all_line_match_en(data)                       ((0x00000004&(data))>>2)
#define  VDPQ_DIAMC_CTRL_get_diamc_perfect_fid_en(data)                          ((0x00000002&(data))>>1)
#define  VDPQ_DIAMC_CTRL_get_diamc_en(data)                                      (0x00000001&(data))

#define  VDPQ_VMC_CTRL                                                           0x180199A4
#define  VDPQ_VMC_CTRL_reg_addr                                                  "0xB80199A4"
#define  VDPQ_VMC_CTRL_reg                                                       0xB80199A4
#define  VDPQ_VMC_CTRL_inst_addr                                                 "0x004A"
#define  set_VDPQ_VMC_CTRL_reg(data)                                             (*((volatile unsigned int*)VDPQ_VMC_CTRL_reg)=data)
#define  get_VDPQ_VMC_CTRL_reg                                                   (*((volatile unsigned int*)VDPQ_VMC_CTRL_reg))
#define  VDPQ_VMC_CTRL_ver_cvbsamp_still_th_shift                                (24)
#define  VDPQ_VMC_CTRL_vmc_cfollowy_en_shift                                     (20)
#define  VDPQ_VMC_CTRL_ver_dc_still_th_shift                                     (12)
#define  VDPQ_VMC_CTRL_amp_low_bnd_shift                                         (4)
#define  VDPQ_VMC_CTRL_slant_det_en_shift                                        (2)
#define  VDPQ_VMC_CTRL_perfect_fid_en_shift                                      (1)
#define  VDPQ_VMC_CTRL_vmc_en_shift                                              (0)
#define  VDPQ_VMC_CTRL_ver_cvbsamp_still_th_mask                                 (0x3F000000)
#define  VDPQ_VMC_CTRL_vmc_cfollowy_en_mask                                      (0x00100000)
#define  VDPQ_VMC_CTRL_ver_dc_still_th_mask                                      (0x0007F000)
#define  VDPQ_VMC_CTRL_amp_low_bnd_mask                                          (0x000003F0)
#define  VDPQ_VMC_CTRL_slant_det_en_mask                                         (0x00000004)
#define  VDPQ_VMC_CTRL_perfect_fid_en_mask                                       (0x00000002)
#define  VDPQ_VMC_CTRL_vmc_en_mask                                               (0x00000001)
#define  VDPQ_VMC_CTRL_ver_cvbsamp_still_th(data)                                (0x3F000000&((data)<<24))
#define  VDPQ_VMC_CTRL_vmc_cfollowy_en(data)                                     (0x00100000&((data)<<20))
#define  VDPQ_VMC_CTRL_ver_dc_still_th(data)                                     (0x0007F000&((data)<<12))
#define  VDPQ_VMC_CTRL_amp_low_bnd(data)                                         (0x000003F0&((data)<<4))
#define  VDPQ_VMC_CTRL_slant_det_en(data)                                        (0x00000004&((data)<<2))
#define  VDPQ_VMC_CTRL_perfect_fid_en(data)                                      (0x00000002&((data)<<1))
#define  VDPQ_VMC_CTRL_vmc_en(data)                                              (0x00000001&(data))
#define  VDPQ_VMC_CTRL_get_ver_cvbsamp_still_th(data)                            ((0x3F000000&(data))>>24)
#define  VDPQ_VMC_CTRL_get_vmc_cfollowy_en(data)                                 ((0x00100000&(data))>>20)
#define  VDPQ_VMC_CTRL_get_ver_dc_still_th(data)                                 ((0x0007F000&(data))>>12)
#define  VDPQ_VMC_CTRL_get_amp_low_bnd(data)                                     ((0x000003F0&(data))>>4)
#define  VDPQ_VMC_CTRL_get_slant_det_en(data)                                    ((0x00000004&(data))>>2)
#define  VDPQ_VMC_CTRL_get_perfect_fid_en(data)                                  ((0x00000002&(data))>>1)
#define  VDPQ_VMC_CTRL_get_vmc_en(data)                                          (0x00000001&(data))

#define  VDPQ_VMC_SPATIAL_CORR_CTRL                                              0x180199A8
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_reg_addr                                     "0xB80199A8"
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_reg                                          0xB80199A8
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_inst_addr                                    "0x004B"
#define  set_VDPQ_VMC_SPATIAL_CORR_CTRL_reg(data)                                (*((volatile unsigned int*)VDPQ_VMC_SPATIAL_CORR_CTRL_reg)=data)
#define  get_VDPQ_VMC_SPATIAL_CORR_CTRL_reg                                      (*((volatile unsigned int*)VDPQ_VMC_SPATIAL_CORR_CTRL_reg))
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_offset_2_shift                               (12)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_offset_1_shift                               (8)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_cnt_th_2_shift                               (4)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_cnt_th_1_shift                               (0)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_offset_2_mask                                (0x00007000)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_offset_1_mask                                (0x00000300)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_cnt_th_2_mask                                (0x000000F0)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_cnt_th_1_mask                                (0x0000000F)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_offset_2(data)                               (0x00007000&((data)<<12))
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_offset_1(data)                               (0x00000300&((data)<<8))
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_cnt_th_2(data)                               (0x000000F0&((data)<<4))
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_cnt_th_1(data)                               (0x0000000F&(data))
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_get_offset_2(data)                           ((0x00007000&(data))>>12)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_get_offset_1(data)                           ((0x00000300&(data))>>8)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_get_cnt_th_2(data)                           ((0x000000F0&(data))>>4)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_get_cnt_th_1(data)                           (0x0000000F&(data))

#define  VDPQ_yc2d_postlp_ctrl                                                   0x180199D0
#define  VDPQ_yc2d_postlp_ctrl_reg_addr                                          "0xB80199D0"
#define  VDPQ_yc2d_postlp_ctrl_reg                                               0xB80199D0
#define  VDPQ_yc2d_postlp_ctrl_inst_addr                                         "0x004C"
#define  set_VDPQ_yc2d_postlp_ctrl_reg(data)                                     (*((volatile unsigned int*)VDPQ_yc2d_postlp_ctrl_reg)=data)
#define  get_VDPQ_yc2d_postlp_ctrl_reg                                           (*((volatile unsigned int*)VDPQ_yc2d_postlp_ctrl_reg))
#define  VDPQ_yc2d_postlp_ctrl_postlpf_dia_en_shift                              (3)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_grad_en_shift                             (2)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_force_en_shift                            (1)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_en_shift                                  (0)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_dia_en_mask                               (0x00000008)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_grad_en_mask                              (0x00000004)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_force_en_mask                             (0x00000002)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_en_mask                                   (0x00000001)
#define  VDPQ_yc2d_postlp_ctrl_postlpf_dia_en(data)                              (0x00000008&((data)<<3))
#define  VDPQ_yc2d_postlp_ctrl_postlpf_grad_en(data)                             (0x00000004&((data)<<2))
#define  VDPQ_yc2d_postlp_ctrl_postlpf_force_en(data)                            (0x00000002&((data)<<1))
#define  VDPQ_yc2d_postlp_ctrl_postlpf_en(data)                                  (0x00000001&(data))
#define  VDPQ_yc2d_postlp_ctrl_get_postlpf_dia_en(data)                          ((0x00000008&(data))>>3)
#define  VDPQ_yc2d_postlp_ctrl_get_postlpf_grad_en(data)                         ((0x00000004&(data))>>2)
#define  VDPQ_yc2d_postlp_ctrl_get_postlpf_force_en(data)                        ((0x00000002&(data))>>1)
#define  VDPQ_yc2d_postlp_ctrl_get_postlpf_en(data)                              (0x00000001&(data))

#define  VDPQ_yc2d_postlp_flat_1                                                 0x180199D4
#define  VDPQ_yc2d_postlp_flat_1_reg_addr                                        "0xB80199D4"
#define  VDPQ_yc2d_postlp_flat_1_reg                                             0xB80199D4
#define  VDPQ_yc2d_postlp_flat_1_inst_addr                                       "0x004D"
#define  set_VDPQ_yc2d_postlp_flat_1_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_1_reg)=data)
#define  get_VDPQ_yc2d_postlp_flat_1_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_1_reg))
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_3_shift                              (24)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_2_shift                              (16)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_1_shift                              (8)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_0_shift                              (0)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_3_mask                               (0x1F000000)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_2_mask                               (0x001F0000)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_1_mask                               (0x00001F00)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_0_mask                               (0x0000001F)
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_3(data)                              (0x1F000000&((data)<<24))
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_2(data)                              (0x001F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_1(data)                              (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_flat_1_low_amp_th_0(data)                              (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_flat_1_get_low_amp_th_3(data)                          ((0x1F000000&(data))>>24)
#define  VDPQ_yc2d_postlp_flat_1_get_low_amp_th_2(data)                          ((0x001F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_flat_1_get_low_amp_th_1(data)                          ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_flat_1_get_low_amp_th_0(data)                          (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_flat_2                                                 0x180199D8
#define  VDPQ_yc2d_postlp_flat_2_reg_addr                                        "0xB80199D8"
#define  VDPQ_yc2d_postlp_flat_2_reg                                             0xB80199D8
#define  VDPQ_yc2d_postlp_flat_2_inst_addr                                       "0x004E"
#define  set_VDPQ_yc2d_postlp_flat_2_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_2_reg)=data)
#define  get_VDPQ_yc2d_postlp_flat_2_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_2_reg))
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_2_shift                                (24)
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_1_shift                                (16)
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_0_shift                                (8)
#define  VDPQ_yc2d_postlp_flat_2_low_amp_th_4_shift                              (0)
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_2_mask                                 (0x1F000000)
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_1_mask                                 (0x001F0000)
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_0_mask                                 (0x00001F00)
#define  VDPQ_yc2d_postlp_flat_2_low_amp_th_4_mask                               (0x0000001F)
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_2(data)                                (0x1F000000&((data)<<24))
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_1(data)                                (0x001F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_flat_2_hdiff_th_0(data)                                (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_flat_2_low_amp_th_4(data)                              (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_flat_2_get_hdiff_th_2(data)                            ((0x1F000000&(data))>>24)
#define  VDPQ_yc2d_postlp_flat_2_get_hdiff_th_1(data)                            ((0x001F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_flat_2_get_hdiff_th_0(data)                            ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_flat_2_get_low_amp_th_4(data)                          (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_flat_3                                                 0x180199DC
#define  VDPQ_yc2d_postlp_flat_3_reg_addr                                        "0xB80199DC"
#define  VDPQ_yc2d_postlp_flat_3_reg                                             0xB80199DC
#define  VDPQ_yc2d_postlp_flat_3_inst_addr                                       "0x004F"
#define  set_VDPQ_yc2d_postlp_flat_3_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_3_reg)=data)
#define  get_VDPQ_yc2d_postlp_flat_3_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_3_reg))
#define  VDPQ_yc2d_postlp_flat_3_vdiff_th_1_shift                                (24)
#define  VDPQ_yc2d_postlp_flat_3_vdiff_th_0_shift                                (16)
#define  VDPQ_yc2d_postlp_flat_3_hdiff_th_4_shift                                (8)
#define  VDPQ_yc2d_postlp_flat_3_hdiff_th_3_shift                                (0)
#define  VDPQ_yc2d_postlp_flat_3_vdiff_th_1_mask                                 (0x1F000000)
#define  VDPQ_yc2d_postlp_flat_3_vdiff_th_0_mask                                 (0x001F0000)
#define  VDPQ_yc2d_postlp_flat_3_hdiff_th_4_mask                                 (0x00001F00)
#define  VDPQ_yc2d_postlp_flat_3_hdiff_th_3_mask                                 (0x0000001F)
#define  VDPQ_yc2d_postlp_flat_3_vdiff_th_1(data)                                (0x1F000000&((data)<<24))
#define  VDPQ_yc2d_postlp_flat_3_vdiff_th_0(data)                                (0x001F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_flat_3_hdiff_th_4(data)                                (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_flat_3_hdiff_th_3(data)                                (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_flat_3_get_vdiff_th_1(data)                            ((0x1F000000&(data))>>24)
#define  VDPQ_yc2d_postlp_flat_3_get_vdiff_th_0(data)                            ((0x001F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_flat_3_get_hdiff_th_4(data)                            ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_flat_3_get_hdiff_th_3(data)                            (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_flat_4                                                 0x180199E0
#define  VDPQ_yc2d_postlp_flat_4_reg_addr                                        "0xB80199E0"
#define  VDPQ_yc2d_postlp_flat_4_reg                                             0xB80199E0
#define  VDPQ_yc2d_postlp_flat_4_inst_addr                                       "0x0050"
#define  set_VDPQ_yc2d_postlp_flat_4_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_4_reg)=data)
#define  get_VDPQ_yc2d_postlp_flat_4_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_flat_4_reg))
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_4_shift                                (16)
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_3_shift                                (8)
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_2_shift                                (0)
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_4_mask                                 (0x001F0000)
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_3_mask                                 (0x00001F00)
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_2_mask                                 (0x0000001F)
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_4(data)                                (0x001F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_3(data)                                (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_flat_4_vdiff_th_2(data)                                (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_flat_4_get_vdiff_th_4(data)                            ((0x001F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_flat_4_get_vdiff_th_3(data)                            ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_flat_4_get_vdiff_th_2(data)                            (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_grad_1                                                 0x180199E4
#define  VDPQ_yc2d_postlp_grad_1_reg_addr                                        "0xB80199E4"
#define  VDPQ_yc2d_postlp_grad_1_reg                                             0xB80199E4
#define  VDPQ_yc2d_postlp_grad_1_inst_addr                                       "0x0051"
#define  set_VDPQ_yc2d_postlp_grad_1_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_grad_1_reg)=data)
#define  get_VDPQ_yc2d_postlp_grad_1_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_grad_1_reg))
#define  VDPQ_yc2d_postlp_grad_1_larger_cnt_th_1_shift                           (28)
#define  VDPQ_yc2d_postlp_grad_1_smaller_cnt_th_0_shift                          (24)
#define  VDPQ_yc2d_postlp_grad_1_larger_cnt_th_0_shift                           (20)
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_ratio_shift                        (12)
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_offset_shift                       (8)
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_upbnd_shift                        (0)
#define  VDPQ_yc2d_postlp_grad_1_larger_cnt_th_1_mask                            (0xF0000000)
#define  VDPQ_yc2d_postlp_grad_1_smaller_cnt_th_0_mask                           (0x03000000)
#define  VDPQ_yc2d_postlp_grad_1_larger_cnt_th_0_mask                            (0x00F00000)
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_ratio_mask                         (0x0001F000)
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_offset_mask                        (0x00000F00)
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_upbnd_mask                         (0x0000001F)
#define  VDPQ_yc2d_postlp_grad_1_larger_cnt_th_1(data)                           (0xF0000000&((data)<<28))
#define  VDPQ_yc2d_postlp_grad_1_smaller_cnt_th_0(data)                          (0x03000000&((data)<<24))
#define  VDPQ_yc2d_postlp_grad_1_larger_cnt_th_0(data)                           (0x00F00000&((data)<<20))
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_ratio(data)                        (0x0001F000&((data)<<12))
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_offset(data)                       (0x00000F00&((data)<<8))
#define  VDPQ_yc2d_postlp_grad_1_grad_flat_th_upbnd(data)                        (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_grad_1_get_larger_cnt_th_1(data)                       ((0xF0000000&(data))>>28)
#define  VDPQ_yc2d_postlp_grad_1_get_smaller_cnt_th_0(data)                      ((0x03000000&(data))>>24)
#define  VDPQ_yc2d_postlp_grad_1_get_larger_cnt_th_0(data)                       ((0x00F00000&(data))>>20)
#define  VDPQ_yc2d_postlp_grad_1_get_grad_flat_th_ratio(data)                    ((0x0001F000&(data))>>12)
#define  VDPQ_yc2d_postlp_grad_1_get_grad_flat_th_offset(data)                   ((0x00000F00&(data))>>8)
#define  VDPQ_yc2d_postlp_grad_1_get_grad_flat_th_upbnd(data)                    (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_grad_2                                                 0x180199E8
#define  VDPQ_yc2d_postlp_grad_2_reg_addr                                        "0xB80199E8"
#define  VDPQ_yc2d_postlp_grad_2_reg                                             0xB80199E8
#define  VDPQ_yc2d_postlp_grad_2_inst_addr                                       "0x0052"
#define  set_VDPQ_yc2d_postlp_grad_2_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_grad_2_reg)=data)
#define  get_VDPQ_yc2d_postlp_grad_2_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_grad_2_reg))
#define  VDPQ_yc2d_postlp_grad_2_vdiff_th_1_grad_shift                           (20)
#define  VDPQ_yc2d_postlp_grad_2_vdiff_th_0_grad_shift                           (12)
#define  VDPQ_yc2d_postlp_grad_2_low_amp_th_grad_offset_shift                    (4)
#define  VDPQ_yc2d_postlp_grad_2_smaller_cnt_th_1_shift                          (0)
#define  VDPQ_yc2d_postlp_grad_2_vdiff_th_1_grad_mask                            (0x01F00000)
#define  VDPQ_yc2d_postlp_grad_2_vdiff_th_0_grad_mask                            (0x0001F000)
#define  VDPQ_yc2d_postlp_grad_2_low_amp_th_grad_offset_mask                     (0x000001F0)
#define  VDPQ_yc2d_postlp_grad_2_smaller_cnt_th_1_mask                           (0x00000003)
#define  VDPQ_yc2d_postlp_grad_2_vdiff_th_1_grad(data)                           (0x01F00000&((data)<<20))
#define  VDPQ_yc2d_postlp_grad_2_vdiff_th_0_grad(data)                           (0x0001F000&((data)<<12))
#define  VDPQ_yc2d_postlp_grad_2_low_amp_th_grad_offset(data)                    (0x000001F0&((data)<<4))
#define  VDPQ_yc2d_postlp_grad_2_smaller_cnt_th_1(data)                          (0x00000003&(data))
#define  VDPQ_yc2d_postlp_grad_2_get_vdiff_th_1_grad(data)                       ((0x01F00000&(data))>>20)
#define  VDPQ_yc2d_postlp_grad_2_get_vdiff_th_0_grad(data)                       ((0x0001F000&(data))>>12)
#define  VDPQ_yc2d_postlp_grad_2_get_low_amp_th_grad_offset(data)                ((0x000001F0&(data))>>4)
#define  VDPQ_yc2d_postlp_grad_2_get_smaller_cnt_th_1(data)                      (0x00000003&(data))

#define  VDPQ_yc2d_postlp_grad_3                                                 0x180199EC
#define  VDPQ_yc2d_postlp_grad_3_reg_addr                                        "0xB80199EC"
#define  VDPQ_yc2d_postlp_grad_3_reg                                             0xB80199EC
#define  VDPQ_yc2d_postlp_grad_3_inst_addr                                       "0x0053"
#define  set_VDPQ_yc2d_postlp_grad_3_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postlp_grad_3_reg)=data)
#define  get_VDPQ_yc2d_postlp_grad_3_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postlp_grad_3_reg))
#define  VDPQ_yc2d_postlp_grad_3_vdiff_th_3_grad_shift                           (8)
#define  VDPQ_yc2d_postlp_grad_3_vdiff_th_2_grad_shift                           (0)
#define  VDPQ_yc2d_postlp_grad_3_vdiff_th_3_grad_mask                            (0x00001F00)
#define  VDPQ_yc2d_postlp_grad_3_vdiff_th_2_grad_mask                            (0x0000001F)
#define  VDPQ_yc2d_postlp_grad_3_vdiff_th_3_grad(data)                           (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_grad_3_vdiff_th_2_grad(data)                           (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_grad_3_get_vdiff_th_3_grad(data)                       ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_grad_3_get_vdiff_th_2_grad(data)                       (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_dia_1                                                  0x180199F0
#define  VDPQ_yc2d_postlp_dia_1_reg_addr                                         "0xB80199F0"
#define  VDPQ_yc2d_postlp_dia_1_reg                                              0xB80199F0
#define  VDPQ_yc2d_postlp_dia_1_inst_addr                                        "0x0054"
#define  set_VDPQ_yc2d_postlp_dia_1_reg(data)                                    (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_1_reg)=data)
#define  get_VDPQ_yc2d_postlp_dia_1_reg                                          (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_1_reg))
#define  VDPQ_yc2d_postlp_dia_1_spd_large_ratio_shift                            (24)
#define  VDPQ_yc2d_postlp_dia_1_spd_large_th_shift                               (16)
#define  VDPQ_yc2d_postlp_dia_1_low_amp_th_dia_offset_shift                      (8)
#define  VDPQ_yc2d_postlp_dia_1_smaller_cnt_th_dia_shift                         (4)
#define  VDPQ_yc2d_postlp_dia_1_larger_cnt_th_dia_shift                          (0)
#define  VDPQ_yc2d_postlp_dia_1_spd_large_ratio_mask                             (0x0F000000)
#define  VDPQ_yc2d_postlp_dia_1_spd_large_th_mask                                (0x003F0000)
#define  VDPQ_yc2d_postlp_dia_1_low_amp_th_dia_offset_mask                       (0x0000FF00)
#define  VDPQ_yc2d_postlp_dia_1_smaller_cnt_th_dia_mask                          (0x00000030)
#define  VDPQ_yc2d_postlp_dia_1_larger_cnt_th_dia_mask                           (0x0000000F)
#define  VDPQ_yc2d_postlp_dia_1_spd_large_ratio(data)                            (0x0F000000&((data)<<24))
#define  VDPQ_yc2d_postlp_dia_1_spd_large_th(data)                               (0x003F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_dia_1_low_amp_th_dia_offset(data)                      (0x0000FF00&((data)<<8))
#define  VDPQ_yc2d_postlp_dia_1_smaller_cnt_th_dia(data)                         (0x00000030&((data)<<4))
#define  VDPQ_yc2d_postlp_dia_1_larger_cnt_th_dia(data)                          (0x0000000F&(data))
#define  VDPQ_yc2d_postlp_dia_1_get_spd_large_ratio(data)                        ((0x0F000000&(data))>>24)
#define  VDPQ_yc2d_postlp_dia_1_get_spd_large_th(data)                           ((0x003F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_dia_1_get_low_amp_th_dia_offset(data)                  ((0x0000FF00&(data))>>8)
#define  VDPQ_yc2d_postlp_dia_1_get_smaller_cnt_th_dia(data)                     ((0x00000030&(data))>>4)
#define  VDPQ_yc2d_postlp_dia_1_get_larger_cnt_th_dia(data)                      (0x0000000F&(data))

#define  VDPQ_yc2d_postlp_dia_2                                                  0x180199F4
#define  VDPQ_yc2d_postlp_dia_2_reg_addr                                         "0xB80199F4"
#define  VDPQ_yc2d_postlp_dia_2_reg                                              0xB80199F4
#define  VDPQ_yc2d_postlp_dia_2_inst_addr                                        "0x0055"
#define  set_VDPQ_yc2d_postlp_dia_2_reg(data)                                    (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_2_reg)=data)
#define  get_VDPQ_yc2d_postlp_dia_2_reg                                          (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_2_reg))
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_ratio_shift                     (20)
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_offset_shift                    (16)
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_upbnd_shift                     (8)
#define  VDPQ_yc2d_postlp_dia_2_spd_diff_th_shift                                (0)
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_ratio_mask                      (0x01F00000)
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_offset_mask                     (0x000F0000)
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_upbnd_mask                      (0x00001F00)
#define  VDPQ_yc2d_postlp_dia_2_spd_diff_th_mask                                 (0x0000007F)
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_ratio(data)                     (0x01F00000&((data)<<20))
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_offset(data)                    (0x000F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_dia_2_dia_grad_flat_th_upbnd(data)                     (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_dia_2_spd_diff_th(data)                                (0x0000007F&(data))
#define  VDPQ_yc2d_postlp_dia_2_get_dia_grad_flat_th_ratio(data)                 ((0x01F00000&(data))>>20)
#define  VDPQ_yc2d_postlp_dia_2_get_dia_grad_flat_th_offset(data)                ((0x000F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_dia_2_get_dia_grad_flat_th_upbnd(data)                 ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_dia_2_get_spd_diff_th(data)                            (0x0000007F&(data))

#define  VDPQ_yc2d_postlp_dia_3                                                  0x180199F8
#define  VDPQ_yc2d_postlp_dia_3_reg_addr                                         "0xB80199F8"
#define  VDPQ_yc2d_postlp_dia_3_reg                                              0xB80199F8
#define  VDPQ_yc2d_postlp_dia_3_inst_addr                                        "0x0056"
#define  set_VDPQ_yc2d_postlp_dia_3_reg(data)                                    (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_3_reg)=data)
#define  get_VDPQ_yc2d_postlp_dia_3_reg                                          (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_3_reg))
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_3_dia_shift                             (24)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_2_dia_shift                             (16)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_1_dia_shift                             (8)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_0_dia_shift                             (0)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_3_dia_mask                              (0x1F000000)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_2_dia_mask                              (0x001F0000)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_1_dia_mask                              (0x00001F00)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_0_dia_mask                              (0x0000001F)
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_3_dia(data)                             (0x1F000000&((data)<<24))
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_2_dia(data)                             (0x001F0000&((data)<<16))
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_1_dia(data)                             (0x00001F00&((data)<<8))
#define  VDPQ_yc2d_postlp_dia_3_vdiff_th_0_dia(data)                             (0x0000001F&(data))
#define  VDPQ_yc2d_postlp_dia_3_get_vdiff_th_3_dia(data)                         ((0x1F000000&(data))>>24)
#define  VDPQ_yc2d_postlp_dia_3_get_vdiff_th_2_dia(data)                         ((0x001F0000&(data))>>16)
#define  VDPQ_yc2d_postlp_dia_3_get_vdiff_th_1_dia(data)                         ((0x00001F00&(data))>>8)
#define  VDPQ_yc2d_postlp_dia_3_get_vdiff_th_0_dia(data)                         (0x0000001F&(data))

#define  VDPQ_yc2d_postlp_dia_4                                                  0x180199FC
#define  VDPQ_yc2d_postlp_dia_4_reg_addr                                         "0xB80199FC"
#define  VDPQ_yc2d_postlp_dia_4_reg                                              0xB80199FC
#define  VDPQ_yc2d_postlp_dia_4_inst_addr                                        "0x0057"
#define  set_VDPQ_yc2d_postlp_dia_4_reg(data)                                    (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_4_reg)=data)
#define  get_VDPQ_yc2d_postlp_dia_4_reg                                          (*((volatile unsigned int*)VDPQ_yc2d_postlp_dia_4_reg))
#define  VDPQ_yc2d_postlp_dia_4_dia_cedge_th_shift                               (0)
#define  VDPQ_yc2d_postlp_dia_4_dia_cedge_th_mask                                (0x0000003F)
#define  VDPQ_yc2d_postlp_dia_4_dia_cedge_th(data)                               (0x0000003F&(data))
#define  VDPQ_yc2d_postlp_dia_4_get_dia_cedge_th(data)                           (0x0000003F&(data))

#define  VDPQ_YC_SEP_MODE_CTRL                                                   0x18019B28
#define  VDPQ_YC_SEP_MODE_CTRL_reg_addr                                          "0xB8019B28"
#define  VDPQ_YC_SEP_MODE_CTRL_reg                                               0xB8019B28
#define  VDPQ_YC_SEP_MODE_CTRL_inst_addr                                         "0x0058"
#define  set_VDPQ_YC_SEP_MODE_CTRL_reg(data)                                     (*((volatile unsigned int*)VDPQ_YC_SEP_MODE_CTRL_reg)=data)
#define  get_VDPQ_YC_SEP_MODE_CTRL_reg                                           (*((volatile unsigned int*)VDPQ_YC_SEP_MODE_CTRL_reg))
#define  VDPQ_YC_SEP_MODE_CTRL_demodphase_fix_en_shift                           (31)
#define  VDPQ_YC_SEP_MODE_CTRL_demodphase_fix_shift                              (24)
#define  VDPQ_YC_SEP_MODE_CTRL_pal_mod_inv_shift                                 (4)
#define  VDPQ_YC_SEP_MODE_CTRL_yc_sep_mode_shift                                 (0)
#define  VDPQ_YC_SEP_MODE_CTRL_demodphase_fix_en_mask                            (0x80000000)
#define  VDPQ_YC_SEP_MODE_CTRL_demodphase_fix_mask                               (0x03000000)
#define  VDPQ_YC_SEP_MODE_CTRL_pal_mod_inv_mask                                  (0x00000010)
#define  VDPQ_YC_SEP_MODE_CTRL_yc_sep_mode_mask                                  (0x00000003)
#define  VDPQ_YC_SEP_MODE_CTRL_demodphase_fix_en(data)                           (0x80000000&((data)<<31))
#define  VDPQ_YC_SEP_MODE_CTRL_demodphase_fix(data)                              (0x03000000&((data)<<24))
#define  VDPQ_YC_SEP_MODE_CTRL_pal_mod_inv(data)                                 (0x00000010&((data)<<4))
#define  VDPQ_YC_SEP_MODE_CTRL_yc_sep_mode(data)                                 (0x00000003&(data))
#define  VDPQ_YC_SEP_MODE_CTRL_get_demodphase_fix_en(data)                       ((0x80000000&(data))>>31)
#define  VDPQ_YC_SEP_MODE_CTRL_get_demodphase_fix(data)                          ((0x03000000&(data))>>24)
#define  VDPQ_YC_SEP_MODE_CTRL_get_pal_mod_inv(data)                             ((0x00000010&(data))>>4)
#define  VDPQ_YC_SEP_MODE_CTRL_get_yc_sep_mode(data)                             (0x00000003&(data))

#define  VDPQ_Dummy_3                                                            0x18019B2C
#define  VDPQ_Dummy_3_reg_addr                                                   "0xB8019B2C"
#define  VDPQ_Dummy_3_reg                                                        0xB8019B2C
#define  VDPQ_Dummy_3_inst_addr                                                  "0x0059"
#define  set_VDPQ_Dummy_3_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_3_reg)=data)
#define  get_VDPQ_Dummy_3_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_3_reg))
#define  VDPQ_Dummy_3_dummy_3_shift                                              (0)
#define  VDPQ_Dummy_3_dummy_3_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_3_dummy_3(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_3_get_dummy_3(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL                                            0x18019B30
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg_addr                                   "0xB8019B30"
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg                                        0xB8019B30
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_inst_addr                                  "0x005A"
#define  set_VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg(data)                              (*((volatile unsigned int*)VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg)=data)
#define  get_VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg                                    (*((volatile unsigned int*)VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg))
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_yc3d_cchroma_bpf_sel_shift                 (7)
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_yc3d_ychroma_bpf_sel_shift                 (6)
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_yc3d_cchroma_bpf_sel_mask                  (0x00000080)
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_yc3d_ychroma_bpf_sel_mask                  (0x00000040)
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_yc3d_cchroma_bpf_sel(data)                 (0x00000080&((data)<<7))
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_yc3d_ychroma_bpf_sel(data)                 (0x00000040&((data)<<6))
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_get_yc3d_cchroma_bpf_sel(data)             ((0x00000080&(data))>>7)
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_get_yc3d_ychroma_bpf_sel(data)             ((0x00000040&(data))>>6)

#define  VDPQ_YC_SEP_YUV_DELAY                                                   0x18019B34
#define  VDPQ_YC_SEP_YUV_DELAY_reg_addr                                          "0xB8019B34"
#define  VDPQ_YC_SEP_YUV_DELAY_reg                                               0xB8019B34
#define  VDPQ_YC_SEP_YUV_DELAY_inst_addr                                         "0x005B"
#define  set_VDPQ_YC_SEP_YUV_DELAY_reg(data)                                     (*((volatile unsigned int*)VDPQ_YC_SEP_YUV_DELAY_reg)=data)
#define  get_VDPQ_YC_SEP_YUV_DELAY_reg                                           (*((volatile unsigned int*)VDPQ_YC_SEP_YUV_DELAY_reg))
#define  VDPQ_YC_SEP_YUV_DELAY_malpha_delay_4fsc_shift                           (16)
#define  VDPQ_YC_SEP_YUV_DELAY_alpha2d3d_delay_4fsc_shift                        (12)
#define  VDPQ_YC_SEP_YUV_DELAY_y_delay_4fsc_shift                                (8)
#define  VDPQ_YC_SEP_YUV_DELAY_cb_delay_4fsc_shift                               (4)
#define  VDPQ_YC_SEP_YUV_DELAY_cr_delay_4fsc_shift                               (0)
#define  VDPQ_YC_SEP_YUV_DELAY_malpha_delay_4fsc_mask                            (0x00030000)
#define  VDPQ_YC_SEP_YUV_DELAY_alpha2d3d_delay_4fsc_mask                         (0x00003000)
#define  VDPQ_YC_SEP_YUV_DELAY_y_delay_4fsc_mask                                 (0x00000300)
#define  VDPQ_YC_SEP_YUV_DELAY_cb_delay_4fsc_mask                                (0x00000030)
#define  VDPQ_YC_SEP_YUV_DELAY_cr_delay_4fsc_mask                                (0x00000003)
#define  VDPQ_YC_SEP_YUV_DELAY_malpha_delay_4fsc(data)                           (0x00030000&((data)<<16))
#define  VDPQ_YC_SEP_YUV_DELAY_alpha2d3d_delay_4fsc(data)                        (0x00003000&((data)<<12))
#define  VDPQ_YC_SEP_YUV_DELAY_y_delay_4fsc(data)                                (0x00000300&((data)<<8))
#define  VDPQ_YC_SEP_YUV_DELAY_cb_delay_4fsc(data)                               (0x00000030&((data)<<4))
#define  VDPQ_YC_SEP_YUV_DELAY_cr_delay_4fsc(data)                               (0x00000003&(data))
#define  VDPQ_YC_SEP_YUV_DELAY_get_malpha_delay_4fsc(data)                       ((0x00030000&(data))>>16)
#define  VDPQ_YC_SEP_YUV_DELAY_get_alpha2d3d_delay_4fsc(data)                    ((0x00003000&(data))>>12)
#define  VDPQ_YC_SEP_YUV_DELAY_get_y_delay_4fsc(data)                            ((0x00000300&(data))>>8)
#define  VDPQ_YC_SEP_YUV_DELAY_get_cb_delay_4fsc(data)                           ((0x00000030&(data))>>4)
#define  VDPQ_YC_SEP_YUV_DELAY_get_cr_delay_4fsc(data)                           (0x00000003&(data))

#define  VDPQ_YC_3D_F4_SLP_MONO                                                  0x18019CFC
#define  VDPQ_YC_3D_F4_SLP_MONO_reg_addr                                         "0xB8019CFC"
#define  VDPQ_YC_3D_F4_SLP_MONO_reg                                              0xB8019CFC
#define  VDPQ_YC_3D_F4_SLP_MONO_inst_addr                                        "0x005C"
#define  set_VDPQ_YC_3D_F4_SLP_MONO_reg(data)                                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_MONO_reg)=data)
#define  get_VDPQ_YC_3D_F4_SLP_MONO_reg                                          (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_MONO_reg))
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_flat_cnt_th_shift                       (20)
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_flat_th_shift                           (12)
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_edge_th_shift                           (4)
#define  VDPQ_YC_3D_F4_SLP_MONO_slp_monotone_en_shift                            (0)
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_flat_cnt_th_mask                        (0x00F00000)
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_flat_th_mask                            (0x0001F000)
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_edge_th_mask                            (0x000007F0)
#define  VDPQ_YC_3D_F4_SLP_MONO_slp_monotone_en_mask                             (0x00000001)
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_flat_cnt_th(data)                       (0x00F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_flat_th(data)                           (0x0001F000&((data)<<12))
#define  VDPQ_YC_3D_F4_SLP_MONO_monotone_edge_th(data)                           (0x000007F0&((data)<<4))
#define  VDPQ_YC_3D_F4_SLP_MONO_slp_monotone_en(data)                            (0x00000001&(data))
#define  VDPQ_YC_3D_F4_SLP_MONO_get_monotone_flat_cnt_th(data)                   ((0x00F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_SLP_MONO_get_monotone_flat_th(data)                       ((0x0001F000&(data))>>12)
#define  VDPQ_YC_3D_F4_SLP_MONO_get_monotone_edge_th(data)                       ((0x000007F0&(data))>>4)
#define  VDPQ_YC_3D_F4_SLP_MONO_get_slp_monotone_en(data)                        (0x00000001&(data))

#define  VDPQ_YC_3D_F4_STAT_1                                                    0x18019D00
#define  VDPQ_YC_3D_F4_STAT_1_reg_addr                                           "0xB8019D00"
#define  VDPQ_YC_3D_F4_STAT_1_reg                                                0xB8019D00
#define  VDPQ_YC_3D_F4_STAT_1_inst_addr                                          "0x005D"
#define  set_VDPQ_YC_3D_F4_STAT_1_reg(data)                                      (*((volatile unsigned int*)VDPQ_YC_3D_F4_STAT_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_STAT_1_reg                                            (*((volatile unsigned int*)VDPQ_YC_3D_F4_STAT_1_reg))
#define  VDPQ_YC_3D_F4_STAT_1_slp_cnt_shift                                      (16)
#define  VDPQ_YC_3D_F4_STAT_1_hor_c_change_cnt_shift                             (0)
#define  VDPQ_YC_3D_F4_STAT_1_slp_cnt_mask                                       (0xFFFF0000)
#define  VDPQ_YC_3D_F4_STAT_1_hor_c_change_cnt_mask                              (0x0000FFFF)
#define  VDPQ_YC_3D_F4_STAT_1_slp_cnt(data)                                      (0xFFFF0000&((data)<<16))
#define  VDPQ_YC_3D_F4_STAT_1_hor_c_change_cnt(data)                             (0x0000FFFF&(data))
#define  VDPQ_YC_3D_F4_STAT_1_get_slp_cnt(data)                                  ((0xFFFF0000&(data))>>16)
#define  VDPQ_YC_3D_F4_STAT_1_get_hor_c_change_cnt(data)                         (0x0000FFFF&(data))

#define  VDPQ_YC_3D_F4_STAT_2                                                    0x18019D04
#define  VDPQ_YC_3D_F4_STAT_2_reg_addr                                           "0xB8019D04"
#define  VDPQ_YC_3D_F4_STAT_2_reg                                                0xB8019D04
#define  VDPQ_YC_3D_F4_STAT_2_inst_addr                                          "0x005E"
#define  set_VDPQ_YC_3D_F4_STAT_2_reg(data)                                      (*((volatile unsigned int*)VDPQ_YC_3D_F4_STAT_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_STAT_2_reg                                            (*((volatile unsigned int*)VDPQ_YC_3D_F4_STAT_2_reg))
#define  VDPQ_YC_3D_F4_STAT_2_stat_tempspd_small_th_shift                        (16)
#define  VDPQ_YC_3D_F4_STAT_2_tempspd_small_cnt_shift                            (0)
#define  VDPQ_YC_3D_F4_STAT_2_stat_tempspd_small_th_mask                         (0x007F0000)
#define  VDPQ_YC_3D_F4_STAT_2_tempspd_small_cnt_mask                             (0x0000FFFF)
#define  VDPQ_YC_3D_F4_STAT_2_stat_tempspd_small_th(data)                        (0x007F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_STAT_2_tempspd_small_cnt(data)                            (0x0000FFFF&(data))
#define  VDPQ_YC_3D_F4_STAT_2_get_stat_tempspd_small_th(data)                    ((0x007F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_STAT_2_get_tempspd_small_cnt(data)                        (0x0000FFFF&(data))

#define  VDPQ_YC_3D_F4_STAT_3                                                    0x18019D08
#define  VDPQ_YC_3D_F4_STAT_3_reg_addr                                           "0xB8019D08"
#define  VDPQ_YC_3D_F4_STAT_3_reg                                                0xB8019D08
#define  VDPQ_YC_3D_F4_STAT_3_inst_addr                                          "0x005F"
#define  set_VDPQ_YC_3D_F4_STAT_3_reg(data)                                      (*((volatile unsigned int*)VDPQ_YC_3D_F4_STAT_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_STAT_3_reg                                            (*((volatile unsigned int*)VDPQ_YC_3D_F4_STAT_3_reg))
#define  VDPQ_YC_3D_F4_STAT_3_stat_hifreqdiff_not_small_th_shift                 (16)
#define  VDPQ_YC_3D_F4_STAT_3_hifreqdiff_not_small_cnt_shift                     (0)
#define  VDPQ_YC_3D_F4_STAT_3_stat_hifreqdiff_not_small_th_mask                  (0x00FF0000)
#define  VDPQ_YC_3D_F4_STAT_3_hifreqdiff_not_small_cnt_mask                      (0x0000FFFF)
#define  VDPQ_YC_3D_F4_STAT_3_stat_hifreqdiff_not_small_th(data)                 (0x00FF0000&((data)<<16))
#define  VDPQ_YC_3D_F4_STAT_3_hifreqdiff_not_small_cnt(data)                     (0x0000FFFF&(data))
#define  VDPQ_YC_3D_F4_STAT_3_get_stat_hifreqdiff_not_small_th(data)             ((0x00FF0000&(data))>>16)
#define  VDPQ_YC_3D_F4_STAT_3_get_hifreqdiff_not_small_cnt(data)                 (0x0000FFFF&(data))

#define  VDPQ_YC_3D_F4_SLP_1                                                     0x18019D0C
#define  VDPQ_YC_3D_F4_SLP_1_reg_addr                                            "0xB8019D0C"
#define  VDPQ_YC_3D_F4_SLP_1_reg                                                 0xB8019D0C
#define  VDPQ_YC_3D_F4_SLP_1_inst_addr                                           "0x0060"
#define  set_VDPQ_YC_3D_F4_SLP_1_reg(data)                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_SLP_1_reg                                             (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_1_reg))
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_large_ratio_shift                       (28)
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_large_th_shift                          (20)
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_small_th_shift                          (12)
#define  VDPQ_YC_3D_F4_SLP_1_slp_offset_shift                                    (4)
#define  VDPQ_YC_3D_F4_SLP_1_slp_en_shift                                        (0)
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_large_ratio_mask                        (0xF0000000)
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_large_th_mask                           (0x03F00000)
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_small_th_mask                           (0x0003F000)
#define  VDPQ_YC_3D_F4_SLP_1_slp_offset_mask                                     (0x000003F0)
#define  VDPQ_YC_3D_F4_SLP_1_slp_en_mask                                         (0x00000001)
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_large_ratio(data)                       (0xF0000000&((data)<<28))
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_large_th(data)                          (0x03F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_SLP_1_sc_hfd_diff_small_th(data)                          (0x0003F000&((data)<<12))
#define  VDPQ_YC_3D_F4_SLP_1_slp_offset(data)                                    (0x000003F0&((data)<<4))
#define  VDPQ_YC_3D_F4_SLP_1_slp_en(data)                                        (0x00000001&(data))
#define  VDPQ_YC_3D_F4_SLP_1_get_sc_hfd_diff_large_ratio(data)                   ((0xF0000000&(data))>>28)
#define  VDPQ_YC_3D_F4_SLP_1_get_sc_hfd_diff_large_th(data)                      ((0x03F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_SLP_1_get_sc_hfd_diff_small_th(data)                      ((0x0003F000&(data))>>12)
#define  VDPQ_YC_3D_F4_SLP_1_get_slp_offset(data)                                ((0x000003F0&(data))>>4)
#define  VDPQ_YC_3D_F4_SLP_1_get_slp_en(data)                                    (0x00000001&(data))

#define  VDPQ_YC_3D_F4_SLP_2                                                     0x18019D10
#define  VDPQ_YC_3D_F4_SLP_2_reg_addr                                            "0xB8019D10"
#define  VDPQ_YC_3D_F4_SLP_2_reg                                                 0xB8019D10
#define  VDPQ_YC_3D_F4_SLP_2_inst_addr                                           "0x0061"
#define  set_VDPQ_YC_3D_F4_SLP_2_reg(data)                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_SLP_2_reg                                             (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_2_reg))
#define  VDPQ_YC_3D_F4_SLP_2_cvbs_match_cnt_th_hvspd_shift                       (20)
#define  VDPQ_YC_3D_F4_SLP_2_large_hvspd_th_shift                                (12)
#define  VDPQ_YC_3D_F4_SLP_2_dc_still_th_shift                                   (4)
#define  VDPQ_YC_3D_F4_SLP_2_match_cnt_th_shift                                  (0)
#define  VDPQ_YC_3D_F4_SLP_2_cvbs_match_cnt_th_hvspd_mask                        (0x00F00000)
#define  VDPQ_YC_3D_F4_SLP_2_large_hvspd_th_mask                                 (0x0003F000)
#define  VDPQ_YC_3D_F4_SLP_2_dc_still_th_mask                                    (0x000007F0)
#define  VDPQ_YC_3D_F4_SLP_2_match_cnt_th_mask                                   (0x0000000F)
#define  VDPQ_YC_3D_F4_SLP_2_cvbs_match_cnt_th_hvspd(data)                       (0x00F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_SLP_2_large_hvspd_th(data)                                (0x0003F000&((data)<<12))
#define  VDPQ_YC_3D_F4_SLP_2_dc_still_th(data)                                   (0x000007F0&((data)<<4))
#define  VDPQ_YC_3D_F4_SLP_2_match_cnt_th(data)                                  (0x0000000F&(data))
#define  VDPQ_YC_3D_F4_SLP_2_get_cvbs_match_cnt_th_hvspd(data)                   ((0x00F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_SLP_2_get_large_hvspd_th(data)                            ((0x0003F000&(data))>>12)
#define  VDPQ_YC_3D_F4_SLP_2_get_dc_still_th(data)                               ((0x000007F0&(data))>>4)
#define  VDPQ_YC_3D_F4_SLP_2_get_match_cnt_th(data)                              (0x0000000F&(data))

#define  VDPQ_YC_3D_F4_SLP_3                                                     0x18019D14
#define  VDPQ_YC_3D_F4_SLP_3_reg_addr                                            "0xB8019D14"
#define  VDPQ_YC_3D_F4_SLP_3_reg                                                 0xB8019D14
#define  VDPQ_YC_3D_F4_SLP_3_inst_addr                                           "0x0062"
#define  set_VDPQ_YC_3D_F4_SLP_3_reg(data)                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_SLP_3_reg                                             (*((volatile unsigned int*)VDPQ_YC_3D_F4_SLP_3_reg))
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_ratio_shift                                 (20)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_th_shift                                    (16)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_diff_ratio_shift                            (12)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_diff_th_shift                               (4)
#define  VDPQ_YC_3D_F4_SLP_3_cvbs_match_cnt_th_shift                             (0)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_ratio_mask                                  (0x00700000)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_th_mask                                     (0x000F0000)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_diff_ratio_mask                             (0x0000F000)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_diff_th_mask                                (0x000007F0)
#define  VDPQ_YC_3D_F4_SLP_3_cvbs_match_cnt_th_mask                              (0x0000000F)
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_ratio(data)                                 (0x00700000&((data)<<20))
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_th(data)                                    (0x000F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_diff_ratio(data)                            (0x0000F000&((data)<<12))
#define  VDPQ_YC_3D_F4_SLP_3_cvbsamp_diff_th(data)                               (0x000007F0&((data)<<4))
#define  VDPQ_YC_3D_F4_SLP_3_cvbs_match_cnt_th(data)                             (0x0000000F&(data))
#define  VDPQ_YC_3D_F4_SLP_3_get_cvbsamp_ratio(data)                             ((0x00700000&(data))>>20)
#define  VDPQ_YC_3D_F4_SLP_3_get_cvbsamp_th(data)                                ((0x000F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_SLP_3_get_cvbsamp_diff_ratio(data)                        ((0x0000F000&(data))>>12)
#define  VDPQ_YC_3D_F4_SLP_3_get_cvbsamp_diff_th(data)                           ((0x000007F0&(data))>>4)
#define  VDPQ_YC_3D_F4_SLP_3_get_cvbs_match_cnt_th(data)                         (0x0000000F&(data))

#define  VDPQ_YC_3D_F4_NTSC_ABA_1                                                0x18019D18
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_reg_addr                                       "0xB8019D18"
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_reg                                            0xB8019D18
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_inst_addr                                      "0x0063"
#define  set_VDPQ_YC_3D_F4_NTSC_ABA_1_reg(data)                                  (*((volatile unsigned int*)VDPQ_YC_3D_F4_NTSC_ABA_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_NTSC_ABA_1_reg                                        (*((volatile unsigned int*)VDPQ_YC_3D_F4_NTSC_ABA_1_reg))
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_dc_change_th_shift                         (20)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_aa_diff_th_shift                           (12)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_hifreqdiff_th_shift                        (4)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_ntsc_aba_en_shift                              (0)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_dc_change_th_mask                          (0x03F00000)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_aa_diff_th_mask                            (0x0007F000)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_hifreqdiff_th_mask                         (0x000007F0)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_ntsc_aba_en_mask                               (0x00000001)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_dc_change_th(data)                         (0x03F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_aa_diff_th(data)                           (0x0007F000&((data)<<12))
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_aba_hifreqdiff_th(data)                        (0x000007F0&((data)<<4))
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_ntsc_aba_en(data)                              (0x00000001&(data))
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_get_aba_dc_change_th(data)                     ((0x03F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_get_aba_aa_diff_th(data)                       ((0x0007F000&(data))>>12)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_get_aba_hifreqdiff_th(data)                    ((0x000007F0&(data))>>4)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_get_ntsc_aba_en(data)                          (0x00000001&(data))

#define  VDPQ_YC_3D_F4_NTSC_ABA_2                                                0x18019D1C
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_reg_addr                                       "0xB8019D1C"
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_reg                                            0xB8019D1C
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_inst_addr                                      "0x0064"
#define  set_VDPQ_YC_3D_F4_NTSC_ABA_2_reg(data)                                  (*((volatile unsigned int*)VDPQ_YC_3D_F4_NTSC_ABA_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_NTSC_ABA_2_reg                                        (*((volatile unsigned int*)VDPQ_YC_3D_F4_NTSC_ABA_2_reg))
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_multiple_shift                     (24)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_aa_th_shift                        (16)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_ab_th_shift                        (8)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_dc_multiple_shift                          (0)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_multiple_mask                      (0x1F000000)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_aa_th_mask                         (0x001F0000)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_ab_th_mask                         (0x00003F00)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_dc_multiple_mask                           (0x0000001F)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_multiple(data)                     (0x1F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_aa_th(data)                        (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_cvbsamp_ab_th(data)                        (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_aba_dc_multiple(data)                          (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_get_aba_cvbsamp_multiple(data)                 ((0x1F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_get_aba_cvbsamp_aa_th(data)                    ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_get_aba_cvbsamp_ab_th(data)                    ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_get_aba_dc_multiple(data)                      (0x0000001F&(data))

#define  VDPQ_Dummy_4                                                            0x18019D20
#define  VDPQ_Dummy_4_reg_addr                                                   "0xB8019D20"
#define  VDPQ_Dummy_4_reg                                                        0xB8019D20
#define  VDPQ_Dummy_4_inst_addr                                                  "0x0065"
#define  set_VDPQ_Dummy_4_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_4_reg)=data)
#define  get_VDPQ_Dummy_4_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_4_reg))
#define  VDPQ_Dummy_4_dummy_4_shift                                              (0)
#define  VDPQ_Dummy_4_dummy_4_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_4_dummy_4(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_4_get_dummy_4(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_YC_3D_F4_Ctrl                                                      0x18019D24
#define  VDPQ_YC_3D_F4_Ctrl_reg_addr                                             "0xB8019D24"
#define  VDPQ_YC_3D_F4_Ctrl_reg                                                  0xB8019D24
#define  VDPQ_YC_3D_F4_Ctrl_inst_addr                                            "0x0066"
#define  set_VDPQ_YC_3D_F4_Ctrl_reg(data)                                        (*((volatile unsigned int*)VDPQ_YC_3D_F4_Ctrl_reg)=data)
#define  get_VDPQ_YC_3D_F4_Ctrl_reg                                              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Ctrl_reg))
#define  VDPQ_YC_3D_F4_Ctrl_f4_en_shift                                          (31)
#define  VDPQ_YC_3D_F4_Ctrl_f4_global_diff_dbg_sftbit_shift                      (28)
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_highfreq_diff_th_shift                        (20)
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_cvbs_amp_th_shift                             (12)
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_value_mode_enable_shift                       (11)
#define  VDPQ_YC_3D_F4_Ctrl_f4_debug_en_shift                                    (8)
#define  VDPQ_YC_3D_F4_Ctrl_f4_debug_mode_sel_shift                              (0)
#define  VDPQ_YC_3D_F4_Ctrl_f4_en_mask                                           (0x80000000)
#define  VDPQ_YC_3D_F4_Ctrl_f4_global_diff_dbg_sftbit_mask                       (0x30000000)
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_highfreq_diff_th_mask                         (0x0FF00000)
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_cvbs_amp_th_mask                              (0x000FF000)
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_value_mode_enable_mask                        (0x00000800)
#define  VDPQ_YC_3D_F4_Ctrl_f4_debug_en_mask                                     (0x00000100)
#define  VDPQ_YC_3D_F4_Ctrl_f4_debug_mode_sel_mask                               (0x0000001F)
#define  VDPQ_YC_3D_F4_Ctrl_f4_en(data)                                          (0x80000000&((data)<<31))
#define  VDPQ_YC_3D_F4_Ctrl_f4_global_diff_dbg_sftbit(data)                      (0x30000000&((data)<<28))
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_highfreq_diff_th(data)                        (0x0FF00000&((data)<<20))
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_cvbs_amp_th(data)                             (0x000FF000&((data)<<12))
#define  VDPQ_YC_3D_F4_Ctrl_f4_dbg_value_mode_enable(data)                       (0x00000800&((data)<<11))
#define  VDPQ_YC_3D_F4_Ctrl_f4_debug_en(data)                                    (0x00000100&((data)<<8))
#define  VDPQ_YC_3D_F4_Ctrl_f4_debug_mode_sel(data)                              (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_en(data)                                      ((0x80000000&(data))>>31)
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_global_diff_dbg_sftbit(data)                  ((0x30000000&(data))>>28)
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_dbg_highfreq_diff_th(data)                    ((0x0FF00000&(data))>>20)
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_dbg_cvbs_amp_th(data)                         ((0x000FF000&(data))>>12)
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_dbg_value_mode_enable(data)                   ((0x00000800&(data))>>11)
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_debug_en(data)                                ((0x00000100&(data))>>8)
#define  VDPQ_YC_3D_F4_Ctrl_get_f4_debug_mode_sel(data)                          (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp                                          0x18019D28
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg_addr                                 "0xB8019D28"
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg                                      0xB8019D28
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_inst_addr                                "0x0067"
#define  set_VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg(data)                            (*((volatile unsigned int*)VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg)=data)
#define  get_VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg                                  (*((volatile unsigned int*)VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_cvbs_amp_change_th_shift                 (24)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_5_shift             (16)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_4_shift             (12)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_3_shift             (8)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_2_shift             (4)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_1_shift             (0)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_cvbs_amp_change_th_mask                  (0x7F000000)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_5_mask              (0x000F0000)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_4_mask              (0x0000F000)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_3_mask              (0x00000F00)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_2_mask              (0x000000F0)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_1_mask              (0x0000000F)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_cvbs_amp_change_th(data)                 (0x7F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_5(data)             (0x000F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_4(data)             (0x0000F000&((data)<<12))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_3(data)             (0x00000F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_2(data)             (0x000000F0&((data)<<4))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_f4_3d_spatial_cnt_th_1(data)             (0x0000000F&(data))
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_get_cvbs_amp_change_th(data)             ((0x7F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_get_f4_3d_spatial_cnt_th_5(data)         ((0x000F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_get_f4_3d_spatial_cnt_th_4(data)         ((0x0000F000&(data))>>12)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_get_f4_3d_spatial_cnt_th_3(data)         ((0x00000F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_get_f4_3d_spatial_cnt_th_2(data)         ((0x000000F0&(data))>>4)
#define  VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_get_f4_3d_spatial_cnt_th_1(data)         (0x0000000F&(data))

#define  VDPQ_YC_3D_F4_HV_Edge_1                                                 0x18019D2C
#define  VDPQ_YC_3D_F4_HV_Edge_1_reg_addr                                        "0xB8019D2C"
#define  VDPQ_YC_3D_F4_HV_Edge_1_reg                                             0xB8019D2C
#define  VDPQ_YC_3D_F4_HV_Edge_1_inst_addr                                       "0x0068"
#define  set_VDPQ_YC_3D_F4_HV_Edge_1_reg(data)                                   (*((volatile unsigned int*)VDPQ_YC_3D_F4_HV_Edge_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_HV_Edge_1_reg                                         (*((volatile unsigned int*)VDPQ_YC_3D_F4_HV_Edge_1_reg))
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_cvbs_diff_large_multiple_th_shift            (20)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_large_multiple_th_shift                 (16)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_large_offset_th_shift                   (8)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_local_diff_comp_ratio_shift                  (4)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_tolerance_shift                         (0)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_cvbs_diff_large_multiple_th_mask             (0x00700000)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_large_multiple_th_mask                  (0x00070000)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_large_offset_th_mask                    (0x00003F00)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_local_diff_comp_ratio_mask                   (0x00000070)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_tolerance_mask                          (0x0000000F)
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_cvbs_diff_large_multiple_th(data)            (0x00700000&((data)<<20))
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_large_multiple_th(data)                 (0x00070000&((data)<<16))
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_large_offset_th(data)                   (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_local_diff_comp_ratio(data)                  (0x00000070&((data)<<4))
#define  VDPQ_YC_3D_F4_HV_Edge_1_hv_diff_tolerance(data)                         (0x0000000F&(data))
#define  VDPQ_YC_3D_F4_HV_Edge_1_get_hv_cvbs_diff_large_multiple_th(data)        ((0x00700000&(data))>>20)
#define  VDPQ_YC_3D_F4_HV_Edge_1_get_hv_diff_large_multiple_th(data)             ((0x00070000&(data))>>16)
#define  VDPQ_YC_3D_F4_HV_Edge_1_get_hv_diff_large_offset_th(data)               ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_HV_Edge_1_get_hv_local_diff_comp_ratio(data)              ((0x00000070&(data))>>4)
#define  VDPQ_YC_3D_F4_HV_Edge_1_get_hv_diff_tolerance(data)                     (0x0000000F&(data))

#define  VDPQ_YC_3D_F4_HV_Edge_2                                                 0x18019D30
#define  VDPQ_YC_3D_F4_HV_Edge_2_reg_addr                                        "0xB8019D30"
#define  VDPQ_YC_3D_F4_HV_Edge_2_reg                                             0xB8019D30
#define  VDPQ_YC_3D_F4_HV_Edge_2_inst_addr                                       "0x0069"
#define  set_VDPQ_YC_3D_F4_HV_Edge_2_reg(data)                                   (*((volatile unsigned int*)VDPQ_YC_3D_F4_HV_Edge_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_HV_Edge_2_reg                                         (*((volatile unsigned int*)VDPQ_YC_3D_F4_HV_Edge_2_reg))
#define  VDPQ_YC_3D_F4_HV_Edge_2_h_diff_normalize_en_shift                       (12)
#define  VDPQ_YC_3D_F4_HV_Edge_2_hv_edge_c_diff_small_th_shift                   (4)
#define  VDPQ_YC_3D_F4_HV_Edge_2_hv_edge_c_diff_small_en_shift                   (0)
#define  VDPQ_YC_3D_F4_HV_Edge_2_h_diff_normalize_en_mask                        (0x00001000)
#define  VDPQ_YC_3D_F4_HV_Edge_2_hv_edge_c_diff_small_th_mask                    (0x000001F0)
#define  VDPQ_YC_3D_F4_HV_Edge_2_hv_edge_c_diff_small_en_mask                    (0x00000001)
#define  VDPQ_YC_3D_F4_HV_Edge_2_h_diff_normalize_en(data)                       (0x00001000&((data)<<12))
#define  VDPQ_YC_3D_F4_HV_Edge_2_hv_edge_c_diff_small_th(data)                   (0x000001F0&((data)<<4))
#define  VDPQ_YC_3D_F4_HV_Edge_2_hv_edge_c_diff_small_en(data)                   (0x00000001&(data))
#define  VDPQ_YC_3D_F4_HV_Edge_2_get_h_diff_normalize_en(data)                   ((0x00001000&(data))>>12)
#define  VDPQ_YC_3D_F4_HV_Edge_2_get_hv_edge_c_diff_small_th(data)               ((0x000001F0&(data))>>4)
#define  VDPQ_YC_3D_F4_HV_Edge_2_get_hv_edge_c_diff_small_en(data)               (0x00000001&(data))

#define  VDPQ_YC_3D_F4_Hifreq_Det                                                0x18019D34
#define  VDPQ_YC_3D_F4_Hifreq_Det_reg_addr                                       "0xB8019D34"
#define  VDPQ_YC_3D_F4_Hifreq_Det_reg                                            0xB8019D34
#define  VDPQ_YC_3D_F4_Hifreq_Det_inst_addr                                      "0x006A"
#define  set_VDPQ_YC_3D_F4_Hifreq_Det_reg(data)                                  (*((volatile unsigned int*)VDPQ_YC_3D_F4_Hifreq_Det_reg)=data)
#define  get_VDPQ_YC_3D_F4_Hifreq_Det_reg                                        (*((volatile unsigned int*)VDPQ_YC_3D_F4_Hifreq_Det_reg))
#define  VDPQ_YC_3D_F4_Hifreq_Det_hor_c_postp_mode_shift                         (14)
#define  VDPQ_YC_3D_F4_Hifreq_Det_hifreq_postp_mode_shift                        (12)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_fill_hole_neightbor_diff_th_shift           (4)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_hor_chifreq_range_shift                     (3)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_ver_chifreq_range_shift                     (2)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_hor_hifreq_range_shift                      (1)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_ver_hifreq_usepalmode_shift                 (0)
#define  VDPQ_YC_3D_F4_Hifreq_Det_hor_c_postp_mode_mask                          (0x0000C000)
#define  VDPQ_YC_3D_F4_Hifreq_Det_hifreq_postp_mode_mask                         (0x00003000)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_fill_hole_neightbor_diff_th_mask            (0x000003F0)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_hor_chifreq_range_mask                      (0x00000008)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_ver_chifreq_range_mask                      (0x00000004)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_hor_hifreq_range_mask                       (0x00000002)
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_ver_hifreq_usepalmode_mask                  (0x00000001)
#define  VDPQ_YC_3D_F4_Hifreq_Det_hor_c_postp_mode(data)                         (0x0000C000&((data)<<14))
#define  VDPQ_YC_3D_F4_Hifreq_Det_hifreq_postp_mode(data)                        (0x00003000&((data)<<12))
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_fill_hole_neightbor_diff_th(data)           (0x000003F0&((data)<<4))
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_hor_chifreq_range(data)                     (0x00000008&((data)<<3))
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_ver_chifreq_range(data)                     (0x00000004&((data)<<2))
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_hor_hifreq_range(data)                      (0x00000002&((data)<<1))
#define  VDPQ_YC_3D_F4_Hifreq_Det_f4_ver_hifreq_usepalmode(data)                 (0x00000001&(data))
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_hor_c_postp_mode(data)                     ((0x0000C000&(data))>>14)
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_hifreq_postp_mode(data)                    ((0x00003000&(data))>>12)
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_f4_fill_hole_neightbor_diff_th(data)       ((0x000003F0&(data))>>4)
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_f4_hor_chifreq_range(data)                 ((0x00000008&(data))>>3)
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_f4_ver_chifreq_range(data)                 ((0x00000004&(data))>>2)
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_f4_hor_hifreq_range(data)                  ((0x00000002&(data))>>1)
#define  VDPQ_YC_3D_F4_Hifreq_Det_get_f4_ver_hifreq_usepalmode(data)             (0x00000001&(data))

#define  VDPQ_YC_3D_F4_DC_Compare                                                0x18019D38
#define  VDPQ_YC_3D_F4_DC_Compare_reg_addr                                       "0xB8019D38"
#define  VDPQ_YC_3D_F4_DC_Compare_reg                                            0xB8019D38
#define  VDPQ_YC_3D_F4_DC_Compare_inst_addr                                      "0x006B"
#define  set_VDPQ_YC_3D_F4_DC_Compare_reg(data)                                  (*((volatile unsigned int*)VDPQ_YC_3D_F4_DC_Compare_reg)=data)
#define  get_VDPQ_YC_3D_F4_DC_Compare_reg                                        (*((volatile unsigned int*)VDPQ_YC_3D_F4_DC_Compare_reg))
#define  VDPQ_YC_3D_F4_DC_Compare_dc_level_change_th_multiple_shift              (8)
#define  VDPQ_YC_3D_F4_DC_Compare_dc_level_change_th_base_shift                  (0)
#define  VDPQ_YC_3D_F4_DC_Compare_dc_level_change_th_multiple_mask               (0x00000F00)
#define  VDPQ_YC_3D_F4_DC_Compare_dc_level_change_th_base_mask                   (0x0000003F)
#define  VDPQ_YC_3D_F4_DC_Compare_dc_level_change_th_multiple(data)              (0x00000F00&((data)<<8))
#define  VDPQ_YC_3D_F4_DC_Compare_dc_level_change_th_base(data)                  (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_DC_Compare_get_dc_level_change_th_multiple(data)          ((0x00000F00&(data))>>8)
#define  VDPQ_YC_3D_F4_DC_Compare_get_dc_level_change_th_base(data)              (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_PAL_Err_Com_1                                             0x18019D3C
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_reg_addr                                    "0xB8019D3C"
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_reg                                         0xB8019D3C
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_inst_addr                                   "0x006C"
#define  set_VDPQ_YC_3D_F4_PAL_Err_Com_1_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_3D_F4_PAL_Err_Com_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_PAL_Err_Com_1_reg                                     (*((volatile unsigned int*)VDPQ_YC_3D_F4_PAL_Err_Com_1_reg))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_similary_th_base_shift                      (24)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_similary_th_multiple_shift                  (16)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_palerr_accu_tolerance_shift                 (12)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_palerr_hifreq_diff_large_th_shift           (4)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_pal_error_detect_en_shift                   (0)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_similary_th_base_mask                       (0x3F000000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_similary_th_multiple_mask                   (0x001F0000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_palerr_accu_tolerance_mask                  (0x0000F000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_palerr_hifreq_diff_large_th_mask            (0x000003F0)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_pal_error_detect_en_mask                    (0x00000001)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_similary_th_base(data)                      (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_similary_th_multiple(data)                  (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_palerr_accu_tolerance(data)                 (0x0000F000&((data)<<12))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_palerr_hifreq_diff_large_th(data)           (0x000003F0&((data)<<4))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_pal_error_detect_en(data)                   (0x00000001&(data))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_get_similary_th_base(data)                  ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_get_similary_th_multiple(data)              ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_get_palerr_accu_tolerance(data)             ((0x0000F000&(data))>>12)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_get_palerr_hifreq_diff_large_th(data)       ((0x000003F0&(data))>>4)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_1_get_pal_error_detect_en(data)               (0x00000001&(data))

#define  VDPQ_YC_3D_F4_PAL_Err_Com_2                                             0x18019D40
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_reg_addr                                    "0xB8019D40"
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_reg                                         0xB8019D40
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_inst_addr                                   "0x006D"
#define  set_VDPQ_YC_3D_F4_PAL_Err_Com_2_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_3D_F4_PAL_Err_Com_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_PAL_Err_Com_2_reg                                     (*((volatile unsigned int*)VDPQ_YC_3D_F4_PAL_Err_Com_2_reg))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_diff_of_spd_small_th_base_shift             (24)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_diff_of_spd_small_th_multiple_shift         (16)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_massive_palmode_error_multiple_th_shift     (8)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_massive_palmode_error_large_th_shift        (0)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_diff_of_spd_small_th_base_mask              (0x1F000000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_diff_of_spd_small_th_multiple_mask          (0x001F0000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_massive_palmode_error_multiple_th_mask      (0x00001F00)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_massive_palmode_error_large_th_mask         (0x0000007F)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_diff_of_spd_small_th_base(data)             (0x1F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_diff_of_spd_small_th_multiple(data)         (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_massive_palmode_error_multiple_th(data)     (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_massive_palmode_error_large_th(data)        (0x0000007F&(data))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_get_diff_of_spd_small_th_base(data)         ((0x1F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_get_diff_of_spd_small_th_multiple(data)     ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_get_massive_palmode_error_multiple_th(data) ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_2_get_massive_palmode_error_large_th(data)    (0x0000007F&(data))

#define  VDPQ_YC_3D_F4_PAL_Err_Com_3                                             0x18019D44
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_reg_addr                                    "0xB8019D44"
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_reg                                         0xB8019D44
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_inst_addr                                   "0x006E"
#define  set_VDPQ_YC_3D_F4_PAL_Err_Com_3_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_3D_F4_PAL_Err_Com_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_PAL_Err_Com_3_reg                                     (*((volatile unsigned int*)VDPQ_YC_3D_F4_PAL_Err_Com_3_reg))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_en_shift                         (31)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_palerr_massive_tolerance_shift              (20)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_weight_shift                  (12)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_offset_shift                  (8)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_upbnd_shift                   (0)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_en_mask                          (0x80000000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_palerr_massive_tolerance_mask               (0x00F00000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_weight_mask                   (0x0003F000)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_offset_mask                   (0x00000F00)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_upbnd_mask                    (0x0000001F)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_en(data)                         (0x80000000&((data)<<31))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_palerr_massive_tolerance(data)              (0x00F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_weight(data)                  (0x0003F000&((data)<<12))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_offset(data)                  (0x00000F00&((data)<<8))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_f4f0_still_th_upbnd(data)                   (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_get_f4f0_still_en(data)                     ((0x80000000&(data))>>31)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_get_palerr_massive_tolerance(data)          ((0x00F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_get_f4f0_still_th_weight(data)              ((0x0003F000&(data))>>12)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_get_f4f0_still_th_offset(data)              ((0x00000F00&(data))>>8)
#define  VDPQ_YC_3D_F4_PAL_Err_Com_3_get_f4f0_still_th_upbnd(data)               (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Still_Vector_1                                            0x18019D48
#define  VDPQ_YC_3D_F4_Still_Vector_1_reg_addr                                   "0xB8019D48"
#define  VDPQ_YC_3D_F4_Still_Vector_1_reg                                        0xB8019D48
#define  VDPQ_YC_3D_F4_Still_Vector_1_inst_addr                                  "0x006F"
#define  set_VDPQ_YC_3D_F4_Still_Vector_1_reg(data)                              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Vector_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Still_Vector_1_reg                                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Vector_1_reg))
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_avg_dynamic_en_shift                    (31)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_longtime_en_shift                       (30)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_fid_match_cnt_th_shift           (20)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_fid_offset_shift                 (16)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_large_cnt_th_shift               (8)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_large_th_shift                   (0)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_avg_dynamic_en_mask                     (0x80000000)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_longtime_en_mask                        (0x40000000)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_fid_match_cnt_th_mask            (0x01F00000)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_fid_offset_mask                  (0x000F0000)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_large_cnt_th_mask                (0x00001F00)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_large_th_mask                    (0x0000001F)
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_avg_dynamic_en(data)                    (0x80000000&((data)<<31))
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_longtime_en(data)                       (0x40000000&((data)<<30))
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_fid_match_cnt_th(data)           (0x01F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_fid_offset(data)                 (0x000F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_large_cnt_th(data)               (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Still_Vector_1_sv_vector_large_th(data)                   (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_Still_Vector_1_get_sv_avg_dynamic_en(data)                ((0x80000000&(data))>>31)
#define  VDPQ_YC_3D_F4_Still_Vector_1_get_sv_longtime_en(data)                   ((0x40000000&(data))>>30)
#define  VDPQ_YC_3D_F4_Still_Vector_1_get_sv_vector_fid_match_cnt_th(data)       ((0x01F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_Still_Vector_1_get_sv_vector_fid_offset(data)             ((0x000F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Still_Vector_1_get_sv_vector_large_cnt_th(data)           ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Still_Vector_1_get_sv_vector_large_th(data)               (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Still_Vector_2                                            0x18019D4C
#define  VDPQ_YC_3D_F4_Still_Vector_2_reg_addr                                   "0xB8019D4C"
#define  VDPQ_YC_3D_F4_Still_Vector_2_reg                                        0xB8019D4C
#define  VDPQ_YC_3D_F4_Still_Vector_2_inst_addr                                  "0x0070"
#define  set_VDPQ_YC_3D_F4_Still_Vector_2_reg(data)                              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Vector_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Still_Vector_2_reg                                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Vector_2_reg))
#define  VDPQ_YC_3D_F4_Still_Vector_2_sv_self_diff_small_th_shift                (0)
#define  VDPQ_YC_3D_F4_Still_Vector_2_sv_self_diff_small_th_mask                 (0x0000007F)
#define  VDPQ_YC_3D_F4_Still_Vector_2_sv_self_diff_small_th(data)                (0x0000007F&(data))
#define  VDPQ_YC_3D_F4_Still_Vector_2_get_sv_self_diff_small_th(data)            (0x0000007F&(data))

#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1                                       0x18019D50
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg_addr                              "0xB8019D50"
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg                                   0xB8019D50
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_inst_addr                             "0x0071"
#define  set_VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg(data)                         (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg                               (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_inter_diff_th_shift              (12)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_global_diff_small_th_shift       (4)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_longtime_en_shift                (0)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_inter_diff_th_mask               (0x0007F000)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_global_diff_small_th_mask        (0x00000FF0)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_longtime_en_mask                 (0x00000001)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_inter_diff_th(data)              (0x0007F000&((data)<<12))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_global_diff_small_th(data)       (0x00000FF0&((data)<<4))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_sghf_longtime_en(data)                (0x00000001&(data))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_get_sghf_inter_diff_th(data)          ((0x0007F000&(data))>>12)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_get_sghf_global_diff_small_th(data)   ((0x00000FF0&(data))>>4)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_get_sghf_longtime_en(data)            (0x00000001&(data))

#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2                                       0x18019D54
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg_addr                              "0xB8019D54"
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg                                   0xB8019D54
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_inst_addr                             "0x0072"
#define  set_VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg(data)                         (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg                               (*((volatile unsigned int*)VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_avg_dynamic_en_shift             (31)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_fid_match_cnt_th_shift    (20)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_fid_offset_shift          (16)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_large_cnt_th_shift        (8)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_large_th_shift            (0)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_avg_dynamic_en_mask              (0x80000000)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_fid_match_cnt_th_mask     (0x01F00000)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_fid_offset_mask           (0x000F0000)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_large_cnt_th_mask         (0x00001F00)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_large_th_mask             (0x0000001F)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_avg_dynamic_en(data)             (0x80000000&((data)<<31))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_fid_match_cnt_th(data)    (0x01F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_fid_offset(data)          (0x000F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_large_cnt_th(data)        (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_sghf_vector_large_th(data)            (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_get_sghf_avg_dynamic_en(data)         ((0x80000000&(data))>>31)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_get_sghf_vector_fid_match_cnt_th(data) ((0x01F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_get_sghf_vector_fid_offset(data)      ((0x000F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_get_sghf_vector_large_cnt_th(data)    ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_get_sghf_vector_large_th(data)        (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1                                        0x18019D58
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg_addr                               "0xB8019D58"
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg                                    0xB8019D58
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_inst_addr                              "0x0073"
#define  set_VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg(data)                          (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg                                (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_140_shift             (24)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_160_shift             (16)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_180_shift             (8)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_200_shift             (0)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_140_mask              (0x1F000000)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_160_mask              (0x001F0000)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_180_mask              (0x00001F00)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_200_mask              (0x0000001F)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_140(data)             (0x1F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_160(data)             (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_180(data)             (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_diff_th_multiple_200(data)             (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_get_diff_th_multiple_140(data)         ((0x1F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_get_diff_th_multiple_160(data)         ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_get_diff_th_multiple_180(data)         ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_1_get_diff_th_multiple_200(data)         (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2                                        0x18019D5C
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg_addr                               "0xB8019D5C"
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg                                    0xB8019D5C
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_inst_addr                              "0x0074"
#define  set_VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg(data)                          (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg                                (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_60_shift              (24)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_80_shift              (16)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_100_shift             (8)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_120_shift             (0)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_60_mask               (0x1F000000)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_80_mask               (0x001F0000)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_100_mask              (0x00001F00)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_120_mask              (0x0000001F)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_60(data)              (0x1F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_80(data)              (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_100(data)             (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_diff_th_multiple_120(data)             (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_get_diff_th_multiple_60(data)          ((0x1F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_get_diff_th_multiple_80(data)          ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_get_diff_th_multiple_100(data)         ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_2_get_diff_th_multiple_120(data)         (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3                                        0x18019D60
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg_addr                               "0xB8019D60"
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg                                    0xB8019D60
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_inst_addr                              "0x0075"
#define  set_VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg(data)                          (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg                                (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_0_shift               (24)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_10_shift              (16)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_20_shift              (8)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_40_shift              (0)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_0_mask                (0x1F000000)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_10_mask               (0x001F0000)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_20_mask               (0x00001F00)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_40_mask               (0x0000001F)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_0(data)               (0x1F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_10(data)              (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_20(data)              (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_diff_th_multiple_40(data)              (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_get_diff_th_multiple_0(data)           ((0x1F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_get_diff_th_multiple_10(data)          ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_get_diff_th_multiple_20(data)          ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Th_Multiple_3_get_diff_th_multiple_40(data)          (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Pair_Th_Base_1                                            0x18019D64
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_reg_addr                                   "0xB8019D64"
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_reg                                        0xB8019D64
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_inst_addr                                  "0x0076"
#define  set_VDPQ_YC_3D_F4_Pair_Th_Base_1_reg(data)                              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Base_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Th_Base_1_reg                                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Base_1_reg))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_140_shift                     (24)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_160_shift                     (16)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_180_shift                     (8)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_200_shift                     (0)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_140_mask                      (0x3F000000)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_160_mask                      (0x003F0000)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_180_mask                      (0x00003F00)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_200_mask                      (0x0000003F)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_140(data)                     (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_160(data)                     (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_180(data)                     (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_diff_th_base_200(data)                     (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_get_diff_th_base_140(data)                 ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_get_diff_th_base_160(data)                 ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_get_diff_th_base_180(data)                 ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_1_get_diff_th_base_200(data)                 (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Pair_Th_Base_2                                            0x18019D68
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_reg_addr                                   "0xB8019D68"
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_reg                                        0xB8019D68
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_inst_addr                                  "0x0077"
#define  set_VDPQ_YC_3D_F4_Pair_Th_Base_2_reg(data)                              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Base_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Th_Base_2_reg                                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Base_2_reg))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_60_shift                      (24)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_80_shift                      (16)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_100_shift                     (8)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_120_shift                     (0)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_60_mask                       (0x3F000000)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_80_mask                       (0x003F0000)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_100_mask                      (0x00003F00)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_120_mask                      (0x0000003F)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_60(data)                      (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_80(data)                      (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_100(data)                     (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_diff_th_base_120(data)                     (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_get_diff_th_base_60(data)                  ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_get_diff_th_base_80(data)                  ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_get_diff_th_base_100(data)                 ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_2_get_diff_th_base_120(data)                 (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Pair_Th_Base_3                                            0x18019D6C
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_reg_addr                                   "0xB8019D6C"
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_reg                                        0xB8019D6C
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_inst_addr                                  "0x0078"
#define  set_VDPQ_YC_3D_F4_Pair_Th_Base_3_reg(data)                              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Base_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Th_Base_3_reg                                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Th_Base_3_reg))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_0_shift                       (24)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_10_shift                      (16)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_20_shift                      (8)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_40_shift                      (0)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_0_mask                        (0x3F000000)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_10_mask                       (0x003F0000)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_20_mask                       (0x00003F00)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_40_mask                       (0x0000003F)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_0(data)                       (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_10(data)                      (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_20(data)                      (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_diff_th_base_40(data)                      (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_get_diff_th_base_0(data)                   ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_get_diff_th_base_10(data)                  ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_get_diff_th_base_20(data)                  ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Th_Base_3_get_diff_th_base_40(data)                  (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Pair_Ctrl_1                                               0x18019D70
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_reg_addr                                      "0xB8019D70"
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_reg                                           0xB8019D70
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_inst_addr                                     "0x0079"
#define  set_VDPQ_YC_3D_F4_Pair_Ctrl_1_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Ctrl_1_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_1_reg))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_hv_offset_shift                               (24)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_still_vector_offset_multiple_shift            (20)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_still_vector_offset_base_shift                (12)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_pal_error_offset_shift                        (4)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_hor_c_diff_dpo_hedge_rshift_bit_shift         (0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_hv_offset_mask                                (0x3F000000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_still_vector_offset_multiple_mask             (0x00700000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_still_vector_offset_base_mask                 (0x0003F000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_pal_error_offset_mask                         (0x000003F0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_hor_c_diff_dpo_hedge_rshift_bit_mask          (0x00000007)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_hv_offset(data)                               (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_still_vector_offset_multiple(data)            (0x00700000&((data)<<20))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_still_vector_offset_base(data)                (0x0003F000&((data)<<12))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_pal_error_offset(data)                        (0x000003F0&((data)<<4))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_hor_c_diff_dpo_hedge_rshift_bit(data)         (0x00000007&(data))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_get_hv_offset(data)                           ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_get_still_vector_offset_multiple(data)        ((0x00700000&(data))>>20)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_get_still_vector_offset_base(data)            ((0x0003F000&(data))>>12)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_get_pal_error_offset(data)                    ((0x000003F0&(data))>>4)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_1_get_hor_c_diff_dpo_hedge_rshift_bit(data)     (0x00000007&(data))

#define  VDPQ_YC_3D_F4_Pair_Ctrl_2                                               0x18019D74
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_reg_addr                                      "0xB8019D74"
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_reg                                           0xB8019D74
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_inst_addr                                     "0x007A"
#define  set_VDPQ_YC_3D_F4_Pair_Ctrl_2_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Ctrl_2_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_2_reg))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_avoid_aba_hifreq_enable_shift    (31)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_cvbs_amp_change_offset_shift     (8)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_hifreq_diff_th_shift_bit_shift   (6)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_hifreq_diff_th_shift             (0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_avoid_aba_hifreq_enable_mask     (0x80000000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_cvbs_amp_change_offset_mask      (0x00003F00)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_hifreq_diff_th_shift_bit_mask    (0x000000C0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_hifreq_diff_th_mask              (0x0000003F)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_avoid_aba_hifreq_enable(data)    (0x80000000&((data)<<31))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_cvbs_amp_change_offset(data)     (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_hifreq_diff_th_shift_bit(data)   (0x000000C0&((data)<<6))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_still_vector_hifreq_diff_th(data)             (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_get_still_vector_avoid_aba_hifreq_enable(data) ((0x80000000&(data))>>31)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_get_still_vector_cvbs_amp_change_offset(data) ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_get_still_vector_hifreq_diff_th_shift_bit(data) ((0x000000C0&(data))>>6)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_2_get_still_vector_hifreq_diff_th(data)         (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Pair_Ctrl_3                                               0x18019D78
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_reg_addr                                      "0xB8019D78"
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_reg                                           0xB8019D78
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_inst_addr                                     "0x007B"
#define  set_VDPQ_YC_3D_F4_Pair_Ctrl_3_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Ctrl_3_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_3_reg))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_later_diff_upper_bound_shift                  (20)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_pair_diff_sel_th_shift                        (12)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_highfreq_diff_low_border_shift                (4)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_flat_offset_shift                             (0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_later_diff_upper_bound_mask                   (0x07F00000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_pair_diff_sel_th_mask                         (0x0007F000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_highfreq_diff_low_border_mask                 (0x000001F0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_flat_offset_mask                              (0x0000000F)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_later_diff_upper_bound(data)                  (0x07F00000&((data)<<20))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_pair_diff_sel_th(data)                        (0x0007F000&((data)<<12))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_highfreq_diff_low_border(data)                (0x000001F0&((data)<<4))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_flat_offset(data)                             (0x0000000F&(data))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_get_later_diff_upper_bound(data)              ((0x07F00000&(data))>>20)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_get_pair_diff_sel_th(data)                    ((0x0007F000&(data))>>12)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_get_highfreq_diff_low_border(data)            ((0x000001F0&(data))>>4)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_3_get_flat_offset(data)                         (0x0000000F&(data))

#define  VDPQ_YC_3D_F4_Pair_Ctrl_4                                               0x18019D7C
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_reg_addr                                      "0xB8019D7C"
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_reg                                           0xB8019D7C
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_inst_addr                                     "0x007C"
#define  set_VDPQ_YC_3D_F4_Pair_Ctrl_4_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_4_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Ctrl_4_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_4_reg))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_upper_bound_shift                     (24)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_lower_bound_shift                     (16)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_2d_comp_3d_offset_shift               (8)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_hvdiff_border_shift                           (0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_upper_bound_mask                      (0x7F000000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_lower_bound_mask                      (0x001F0000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_2d_comp_3d_offset_mask                (0x00001F00)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_hvdiff_border_mask                            (0x0000003F)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_upper_bound(data)                     (0x7F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_lower_bound(data)                     (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_diff_th_2d_comp_3d_offset(data)               (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_hvdiff_border(data)                           (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_get_diff_th_upper_bound(data)                 ((0x7F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_get_diff_th_lower_bound(data)                 ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_get_diff_th_2d_comp_3d_offset(data)           ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_4_get_hvdiff_border(data)                       (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Pair_Ctrl_5                                               0x18019D80
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_reg_addr                                      "0xB8019D80"
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_reg                                           0xB8019D80
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_inst_addr                                     "0x007D"
#define  set_VDPQ_YC_3D_F4_Pair_Ctrl_5_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_5_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Ctrl_5_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_5_reg))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_th_shift                    (12)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_low_border_shift            (4)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_enable_shift                (0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_th_mask                     (0x0007F000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_low_border_mask             (0x000003F0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_enable_mask                 (0x00000001)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_th(data)                    (0x0007F000&((data)<<12))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_low_border(data)            (0x000003F0&((data)<<4))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_still_gray_hifreq_enable(data)                (0x00000001&(data))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_get_still_gray_hifreq_th(data)                ((0x0007F000&(data))>>12)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_get_still_gray_hifreq_low_border(data)        ((0x000003F0&(data))>>4)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_5_get_still_gray_hifreq_enable(data)            (0x00000001&(data))

#define  VDPQ_YC_3D_F4_Pair_Ctrl_6                                               0x18019D84
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_reg_addr                                      "0xB8019D84"
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_reg                                           0xB8019D84
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_inst_addr                                     "0x007E"
#define  set_VDPQ_YC_3D_F4_Pair_Ctrl_6_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_6_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_Ctrl_6_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_Ctrl_6_reg))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_global_diff_tolerance_shift                   (24)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_global_diff_offset_dc_fierce_change_shift     (16)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_dc_level_fierce_change_th_shift               (8)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_hdy_small_th_shift                            (0)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_global_diff_tolerance_mask                    (0x0F000000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_global_diff_offset_dc_fierce_change_mask      (0x001F0000)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_dc_level_fierce_change_th_mask                (0x00003F00)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_hdy_small_th_mask                             (0x0000003F)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_global_diff_tolerance(data)                   (0x0F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_global_diff_offset_dc_fierce_change(data)     (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_dc_level_fierce_change_th(data)               (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_hdy_small_th(data)                            (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_get_global_diff_tolerance(data)               ((0x0F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_get_global_diff_offset_dc_fierce_change(data) ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_get_dc_level_fierce_change_th(data)           ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_Ctrl_6_get_hdy_small_th(data)                        (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1                            0x18019D88
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg_addr                   "0xB8019D88"
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg                        0xB8019D88
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_inst_addr                  "0x007F"
#define  set_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg(data)              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_120_shift (24)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_140_shift (16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_160_shift (8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_180_shift (0)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_120_mask (0x3F000000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_140_mask (0x003F0000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_160_mask (0x00003F00)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_180_mask (0x0000003F)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_120(data) (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_140(data) (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_160(data) (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_global_diff_th_hifreq_offset_180(data) (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_get_global_diff_th_hifreq_offset_120(data) ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_get_global_diff_th_hifreq_offset_140(data) ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_get_global_diff_th_hifreq_offset_160(data) ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_get_global_diff_th_hifreq_offset_180(data) (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2                            0x18019D8C
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg_addr                   "0xB8019D8C"
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg                        0xB8019D8C
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_inst_addr                  "0x0080"
#define  set_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg(data)              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_60_shift (24)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_70_shift (16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_80_shift (8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_100_shift (0)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_60_mask (0x3F000000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_70_mask (0x003F0000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_80_mask (0x00003F00)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_100_mask (0x0000003F)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_60(data) (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_70(data) (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_80(data) (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_global_diff_th_hifreq_offset_100(data) (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_get_global_diff_th_hifreq_offset_60(data) ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_get_global_diff_th_hifreq_offset_70(data) ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_get_global_diff_th_hifreq_offset_80(data) ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_get_global_diff_th_hifreq_offset_100(data) (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3                            0x18019D90
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg_addr                   "0xB8019D90"
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg                        0xB8019D90
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_inst_addr                  "0x0081"
#define  set_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg(data)              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg)=data)
#define  get_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_20_shift (24)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_30_shift (16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_40_shift (8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_50_shift (0)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_20_mask (0x3F000000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_30_mask (0x003F0000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_40_mask (0x00003F00)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_50_mask (0x0000003F)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_20(data) (0x3F000000&((data)<<24))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_30(data) (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_40(data) (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_global_diff_th_hifreq_offset_50(data) (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_get_global_diff_th_hifreq_offset_20(data) ((0x3F000000&(data))>>24)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_get_global_diff_th_hifreq_offset_30(data) ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_get_global_diff_th_hifreq_offset_40(data) ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_get_global_diff_th_hifreq_offset_50(data) (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4                            0x18019D94
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg_addr                   "0xB8019D94"
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg                        0xB8019D94
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_inst_addr                  "0x0082"
#define  set_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg(data)              (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg)=data)
#define  get_VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg                    (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_5_shift (16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_0_shift (8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_10_shift (0)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_5_mask (0x003F0000)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_0_mask (0x00003F00)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_10_mask (0x0000003F)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_5(data) (0x003F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_0(data) (0x00003F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_global_diff_th_hifreq_offset_10(data) (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_get_global_diff_th_hifreq_offset_5(data) ((0x003F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_get_global_diff_th_hifreq_offset_0(data) ((0x00003F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_get_global_diff_th_hifreq_offset_10(data) (0x0000003F&(data))

#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1                                               0x18019D98
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg_addr                                      "0xB8019D98"
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg                                           0xB8019D98
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_inst_addr                                     "0x0083"
#define  set_VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg)=data)
#define  get_VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_ver_dc_level_fierce_change_th_shift (12)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_flat_ver_cvbs_th_shift           (4)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_mghf_flag_shift                               (3)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_mghf_enable_shift                             (2)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_en_shift                         (1)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_dc_level_hor_dc_check_en_shift                (0)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_ver_dc_level_fierce_change_th_mask (0x0001F000)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_flat_ver_cvbs_th_mask            (0x000001F0)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_mghf_flag_mask                                (0x00000008)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_mghf_enable_mask                              (0x00000004)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_en_mask                          (0x00000002)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_dc_level_hor_dc_check_en_mask                 (0x00000001)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_ver_dc_level_fierce_change_th(data) (0x0001F000&((data)<<12))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_flat_ver_cvbs_th(data)           (0x000001F0&((data)<<4))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_mghf_flag(data)                               (0x00000008&((data)<<3))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_mghf_enable(data)                             (0x00000004&((data)<<2))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_moving_vline_en(data)                         (0x00000002&((data)<<1))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_dc_level_hor_dc_check_en(data)                (0x00000001&(data))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_get_moving_vline_ver_dc_level_fierce_change_th(data) ((0x0001F000&(data))>>12)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_get_moving_vline_flat_ver_cvbs_th(data)       ((0x000001F0&(data))>>4)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_get_mghf_flag(data)                           ((0x00000008&(data))>>3)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_get_mghf_enable(data)                         ((0x00000004&(data))>>2)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_get_moving_vline_en(data)                     ((0x00000002&(data))>>1)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_1_get_dc_level_hor_dc_check_en(data)            (0x00000001&(data))

#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2                                               0x18019D9C
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_reg_addr                                      "0xB8019D9C"
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_reg                                           0xB8019D9C
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_inst_addr                                     "0x0084"
#define  set_VDPQ_YC_3D_F4_MGHF_Ctrl_2_reg(data)                                 (*((volatile unsigned int*)VDPQ_YC_3D_F4_MGHF_Ctrl_2_reg)=data)
#define  get_VDPQ_YC_3D_F4_MGHF_Ctrl_2_reg                                       (*((volatile unsigned int*)VDPQ_YC_3D_F4_MGHF_Ctrl_2_reg))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_large_hifreq_diff_ratio_shift                 (28)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hor_c_change_ratio_shift                      (24)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hifreq_diff_large_th_shift                    (16)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_cvbs_still_th_shift                           (8)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hor_c_change_th_shift                         (0)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_large_hifreq_diff_ratio_mask                  (0x70000000)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hor_c_change_ratio_mask                       (0x07000000)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hifreq_diff_large_th_mask                     (0x001F0000)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_cvbs_still_th_mask                            (0x00001F00)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hor_c_change_th_mask                          (0x0000001F)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_large_hifreq_diff_ratio(data)                 (0x70000000&((data)<<28))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hor_c_change_ratio(data)                      (0x07000000&((data)<<24))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hifreq_diff_large_th(data)                    (0x001F0000&((data)<<16))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_cvbs_still_th(data)                           (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_hor_c_change_th(data)                         (0x0000001F&(data))
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_get_large_hifreq_diff_ratio(data)             ((0x70000000&(data))>>28)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_get_hor_c_change_ratio(data)                  ((0x07000000&(data))>>24)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_get_hifreq_diff_large_th(data)                ((0x001F0000&(data))>>16)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_get_cvbs_still_th(data)                       ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_MGHF_Ctrl_2_get_hor_c_change_th(data)                     (0x0000001F&(data))

#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com                                        0x18019DA0
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg_addr                               "0xB8019DA0"
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg                                    0xB8019DA0
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_inst_addr                              "0x0085"
#define  set_VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg(data)                          (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg)=data)
#define  get_VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg                                (*((volatile unsigned int*)VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_diff_th_multiple_5_shift               (8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_diff_th_base_5_shift                   (0)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_diff_th_multiple_5_mask                (0x00001F00)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_diff_th_base_5_mask                    (0x0000003F)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_diff_th_multiple_5(data)               (0x00001F00&((data)<<8))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_diff_th_base_5(data)                   (0x0000003F&(data))
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_get_diff_th_multiple_5(data)           ((0x00001F00&(data))>>8)
#define  VDPQ_YC_3D_F4_Global_Diff_Th_Com_get_diff_th_base_5(data)               (0x0000003F&(data))

#define  VDPQ_YC_Post2DBPF_DBWline_1                                             0x18019DA4
#define  VDPQ_YC_Post2DBPF_DBWline_1_reg_addr                                    "0xB8019DA4"
#define  VDPQ_YC_Post2DBPF_DBWline_1_reg                                         0xB8019DA4
#define  VDPQ_YC_Post2DBPF_DBWline_1_inst_addr                                   "0x0086"
#define  set_VDPQ_YC_Post2DBPF_DBWline_1_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_DBWline_1_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_DBWline_1_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_DBWline_1_reg))
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_vspd_large_th_shift                 (24)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_upbnd_shift                   (16)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_weight_shift                  (12)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_base_shift                    (4)
#define  VDPQ_YC_Post2DBPF_DBWline_1_dbwline_en_shift                            (0)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_vspd_large_th_mask                  (0x3F000000)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_upbnd_mask                    (0x003F0000)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_weight_mask                   (0x0000F000)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_base_mask                     (0x000003F0)
#define  VDPQ_YC_Post2DBPF_DBWline_1_dbwline_en_mask                             (0x00000001)
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_vspd_large_th(data)                 (0x3F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_upbnd(data)                   (0x003F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_weight(data)                  (0x0000F000&((data)<<12))
#define  VDPQ_YC_Post2DBPF_DBWline_1_diadiff_small_base(data)                    (0x000003F0&((data)<<4))
#define  VDPQ_YC_Post2DBPF_DBWline_1_dbwline_en(data)                            (0x00000001&(data))
#define  VDPQ_YC_Post2DBPF_DBWline_1_get_diadiff_vspd_large_th(data)             ((0x3F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_DBWline_1_get_diadiff_small_upbnd(data)               ((0x003F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_DBWline_1_get_diadiff_small_weight(data)              ((0x0000F000&(data))>>12)
#define  VDPQ_YC_Post2DBPF_DBWline_1_get_diadiff_small_base(data)                ((0x000003F0&(data))>>4)
#define  VDPQ_YC_Post2DBPF_DBWline_1_get_dbwline_en(data)                        (0x00000001&(data))

#define  VDPQ_YC_Post2DBPF_DBWline_2                                             0x18019DA8
#define  VDPQ_YC_Post2DBPF_DBWline_2_reg_addr                                    "0xB8019DA8"
#define  VDPQ_YC_Post2DBPF_DBWline_2_reg                                         0xB8019DA8
#define  VDPQ_YC_Post2DBPF_DBWline_2_inst_addr                                   "0x0087"
#define  set_VDPQ_YC_Post2DBPF_DBWline_2_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_DBWline_2_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_DBWline_2_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_DBWline_2_reg))
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_d45_hspd_large_th_shift             (24)
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_hspd_small_th_shift                 (16)
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_hor_cdiff_th_shift                  (8)
#define  VDPQ_YC_Post2DBPF_DBWline_2_low_sat_th_shift                            (0)
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_d45_hspd_large_th_mask              (0x3F000000)
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_hspd_small_th_mask                  (0x003F0000)
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_hor_cdiff_th_mask                   (0x00007F00)
#define  VDPQ_YC_Post2DBPF_DBWline_2_low_sat_th_mask                             (0x0000003F)
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_d45_hspd_large_th(data)             (0x3F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_hspd_small_th(data)                 (0x003F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_DBWline_2_dbwline_hor_cdiff_th(data)                  (0x00007F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_DBWline_2_low_sat_th(data)                            (0x0000003F&(data))
#define  VDPQ_YC_Post2DBPF_DBWline_2_get_dbwline_d45_hspd_large_th(data)         ((0x3F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_DBWline_2_get_dbwline_hspd_small_th(data)             ((0x003F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_DBWline_2_get_dbwline_hor_cdiff_th(data)              ((0x00007F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_DBWline_2_get_low_sat_th(data)                        (0x0000003F&(data))

#define  VDPQ_YC_Post2DBPF_DBWline_3                                             0x18019DAC
#define  VDPQ_YC_Post2DBPF_DBWline_3_reg_addr                                    "0xB8019DAC"
#define  VDPQ_YC_Post2DBPF_DBWline_3_reg                                         0xB8019DAC
#define  VDPQ_YC_Post2DBPF_DBWline_3_inst_addr                                   "0x0088"
#define  set_VDPQ_YC_Post2DBPF_DBWline_3_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_DBWline_3_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_DBWline_3_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_DBWline_3_reg))
#define  VDPQ_YC_Post2DBPF_DBWline_3_dbwline_d45_diadiff_small_th_shift          (0)
#define  VDPQ_YC_Post2DBPF_DBWline_3_dbwline_d45_diadiff_small_th_mask           (0x0000007F)
#define  VDPQ_YC_Post2DBPF_DBWline_3_dbwline_d45_diadiff_small_th(data)          (0x0000007F&(data))
#define  VDPQ_YC_Post2DBPF_DBWline_3_get_dbwline_d45_diadiff_small_th(data)      (0x0000007F&(data))

#define  VDPQ_YC_Post2DBPF_Ctrl                                                  0x18019DB0
#define  VDPQ_YC_Post2DBPF_Ctrl_reg_addr                                         "0xB8019DB0"
#define  VDPQ_YC_Post2DBPF_Ctrl_reg                                              0xB8019DB0
#define  VDPQ_YC_Post2DBPF_Ctrl_inst_addr                                        "0x0089"
#define  set_VDPQ_YC_Post2DBPF_Ctrl_reg(data)                                    (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_Ctrl_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_Ctrl_reg                                          (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_Ctrl_reg))
#define  VDPQ_YC_Post2DBPF_Ctrl_gremove_c_small_th_shift                         (20)
#define  VDPQ_YC_Post2DBPF_Ctrl_gremove_bpfedc_small_th_shift                    (16)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_2d_c_shift                                (14)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_bld_c_shift                               (12)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_3d_c_shift                                (10)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_2d_y_shift                                (8)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_bld_y_shift                               (6)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_3d_y_shift                                (4)
#define  VDPQ_YC_Post2DBPF_Ctrl_mghf_narrowbpf_en_shift                          (3)
#define  VDPQ_YC_Post2DBPF_Ctrl_greenish_detected_en_shift                       (2)
#define  VDPQ_YC_Post2DBPF_Ctrl_post2dbpf_c_en_shift                             (1)
#define  VDPQ_YC_Post2DBPF_Ctrl_post2dbpf_y_en_shift                             (0)
#define  VDPQ_YC_Post2DBPF_Ctrl_gremove_c_small_th_mask                          (0x01F00000)
#define  VDPQ_YC_Post2DBPF_Ctrl_gremove_bpfedc_small_th_mask                     (0x000F0000)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_2d_c_mask                                 (0x0000C000)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_bld_c_mask                                (0x00003000)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_3d_c_mask                                 (0x00000C00)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_2d_y_mask                                 (0x00000300)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_bld_y_mask                                (0x000000C0)
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_3d_y_mask                                 (0x00000030)
#define  VDPQ_YC_Post2DBPF_Ctrl_mghf_narrowbpf_en_mask                           (0x00000008)
#define  VDPQ_YC_Post2DBPF_Ctrl_greenish_detected_en_mask                        (0x00000004)
#define  VDPQ_YC_Post2DBPF_Ctrl_post2dbpf_c_en_mask                              (0x00000002)
#define  VDPQ_YC_Post2DBPF_Ctrl_post2dbpf_y_en_mask                              (0x00000001)
#define  VDPQ_YC_Post2DBPF_Ctrl_gremove_c_small_th(data)                         (0x01F00000&((data)<<20))
#define  VDPQ_YC_Post2DBPF_Ctrl_gremove_bpfedc_small_th(data)                    (0x000F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_2d_c(data)                                (0x0000C000&((data)<<14))
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_bld_c(data)                               (0x00003000&((data)<<12))
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_3d_c(data)                                (0x00000C00&((data)<<10))
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_2d_y(data)                                (0x00000300&((data)<<8))
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_bld_y(data)                               (0x000000C0&((data)<<6))
#define  VDPQ_YC_Post2DBPF_Ctrl_weight_3d_y(data)                                (0x00000030&((data)<<4))
#define  VDPQ_YC_Post2DBPF_Ctrl_mghf_narrowbpf_en(data)                          (0x00000008&((data)<<3))
#define  VDPQ_YC_Post2DBPF_Ctrl_greenish_detected_en(data)                       (0x00000004&((data)<<2))
#define  VDPQ_YC_Post2DBPF_Ctrl_post2dbpf_c_en(data)                             (0x00000002&((data)<<1))
#define  VDPQ_YC_Post2DBPF_Ctrl_post2dbpf_y_en(data)                             (0x00000001&(data))
#define  VDPQ_YC_Post2DBPF_Ctrl_get_gremove_c_small_th(data)                     ((0x01F00000&(data))>>20)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_gremove_bpfedc_small_th(data)                ((0x000F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_weight_2d_c(data)                            ((0x0000C000&(data))>>14)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_weight_bld_c(data)                           ((0x00003000&(data))>>12)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_weight_3d_c(data)                            ((0x00000C00&(data))>>10)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_weight_2d_y(data)                            ((0x00000300&(data))>>8)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_weight_bld_y(data)                           ((0x000000C0&(data))>>6)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_weight_3d_y(data)                            ((0x00000030&(data))>>4)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_mghf_narrowbpf_en(data)                      ((0x00000008&(data))>>3)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_greenish_detected_en(data)                   ((0x00000004&(data))>>2)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_post2dbpf_c_en(data)                         ((0x00000002&(data))>>1)
#define  VDPQ_YC_Post2DBPF_Ctrl_get_post2dbpf_y_en(data)                         (0x00000001&(data))

#define  VDPQ_YC_Post2DBPF_ThBase                                                0x18019DB4
#define  VDPQ_YC_Post2DBPF_ThBase_reg_addr                                       "0xB8019DB4"
#define  VDPQ_YC_Post2DBPF_ThBase_reg                                            0xB8019DB4
#define  VDPQ_YC_Post2DBPF_ThBase_inst_addr                                      "0x008A"
#define  set_VDPQ_YC_Post2DBPF_ThBase_reg(data)                                  (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_ThBase_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_ThBase_reg                                        (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_ThBase_reg))
#define  VDPQ_YC_Post2DBPF_ThBase_hor_cdiff_th_base_shift                        (8)
#define  VDPQ_YC_Post2DBPF_ThBase_ver_cdiff_th_base_shift                        (0)
#define  VDPQ_YC_Post2DBPF_ThBase_hor_cdiff_th_base_mask                         (0x00007F00)
#define  VDPQ_YC_Post2DBPF_ThBase_ver_cdiff_th_base_mask                         (0x0000007F)
#define  VDPQ_YC_Post2DBPF_ThBase_hor_cdiff_th_base(data)                        (0x00007F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_ThBase_ver_cdiff_th_base(data)                        (0x0000007F&(data))
#define  VDPQ_YC_Post2DBPF_ThBase_get_hor_cdiff_th_base(data)                    ((0x00007F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_ThBase_get_ver_cdiff_th_base(data)                    (0x0000007F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_1                                              0x18019DB8
#define  VDPQ_YC_Post2DBPF_AdapTh_1_reg_addr                                     "0xB8019DB8"
#define  VDPQ_YC_Post2DBPF_AdapTh_1_reg                                          0xB8019DB8
#define  VDPQ_YC_Post2DBPF_AdapTh_1_inst_addr                                    "0x008B"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_1_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_1_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_1_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_1_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_1_bpfed_c_diff_small_th_shift                  (20)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedc_small_th_shift                (12)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedcdiff_large_ratio_shift         (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedcdiff_large_th_shift            (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_bpfed_c_diff_small_th_mask                   (0x07F00000)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedc_small_th_mask                 (0x0001F000)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedcdiff_large_ratio_mask          (0x00000F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedcdiff_large_th_mask             (0x0000001F)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_bpfed_c_diff_small_th(data)                  (0x07F00000&((data)<<20))
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedc_small_th(data)                (0x0001F000&((data)<<12))
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedcdiff_large_ratio(data)         (0x00000F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_1_dual_ch_bpfedcdiff_large_th(data)            (0x0000001F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_1_get_bpfed_c_diff_small_th(data)              ((0x07F00000&(data))>>20)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_get_dual_ch_bpfedc_small_th(data)            ((0x0001F000&(data))>>12)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_get_dual_ch_bpfedcdiff_large_ratio(data)     ((0x00000F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_1_get_dual_ch_bpfedcdiff_large_th(data)        (0x0000001F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_2                                              0x18019DBC
#define  VDPQ_YC_Post2DBPF_AdapTh_2_reg_addr                                     "0xB8019DBC"
#define  VDPQ_YC_Post2DBPF_AdapTh_2_reg                                          0xB8019DBC
#define  VDPQ_YC_Post2DBPF_AdapTh_2_inst_addr                                    "0x008C"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_2_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_2_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_2_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_2_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_large_hor_offset_shift          (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_large_ver_offset_shift          (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_small_hor_offset_shift          (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_small_ver_offset_shift          (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_large_hor_offset_mask           (0x7F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_large_ver_offset_mask           (0x007F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_small_hor_offset_mask           (0x00007F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_small_ver_offset_mask           (0x0000007F)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_large_hor_offset(data)          (0x7F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_large_ver_offset(data)          (0x007F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_small_hor_offset(data)          (0x00007F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_2_bpfed_c_diff_small_ver_offset(data)          (0x0000007F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_2_get_bpfed_c_diff_large_hor_offset(data)      ((0x7F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_get_bpfed_c_diff_large_ver_offset(data)      ((0x007F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_get_bpfed_c_diff_small_hor_offset(data)      ((0x00007F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_2_get_bpfed_c_diff_small_ver_offset(data)      (0x0000007F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_3                                              0x18019DC0
#define  VDPQ_YC_Post2DBPF_AdapTh_3_reg_addr                                     "0xB8019DC0"
#define  VDPQ_YC_Post2DBPF_AdapTh_3_reg                                          0xB8019DC0
#define  VDPQ_YC_Post2DBPF_AdapTh_3_inst_addr                                    "0x008D"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_3_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_3_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_3_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_3_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_3_neighbor_vdiff_small_hor_offset_shift        (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_neighbor_hdiff_small_ver_offset_shift        (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_vspd_small_th_shift                          (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_hdy_spd_small_th_shift                       (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_neighbor_vdiff_small_hor_offset_mask         (0x3F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_neighbor_hdiff_small_ver_offset_mask         (0x003F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_vspd_small_th_mask                           (0x00001F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_hdy_spd_small_th_mask                        (0x0000001F)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_neighbor_vdiff_small_hor_offset(data)        (0x3F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_3_neighbor_hdiff_small_ver_offset(data)        (0x003F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_3_vspd_small_th(data)                          (0x00001F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_3_hdy_spd_small_th(data)                       (0x0000001F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_3_get_neighbor_vdiff_small_hor_offset(data)    ((0x3F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_get_neighbor_hdiff_small_ver_offset(data)    ((0x003F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_get_vspd_small_th(data)                      ((0x00001F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_3_get_hdy_spd_small_th(data)                   (0x0000001F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_4                                              0x18019DC4
#define  VDPQ_YC_Post2DBPF_AdapTh_4_reg_addr                                     "0xB8019DC4"
#define  VDPQ_YC_Post2DBPF_AdapTh_4_reg                                          0xB8019DC4
#define  VDPQ_YC_Post2DBPF_AdapTh_4_inst_addr                                    "0x008E"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_4_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_4_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_4_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_4_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hvedge_diff_large_ratio_shift                (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_vspd_large_th_shift                          (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hdy_spd_large_th_shift                       (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hdiff_tolerance_shift                        (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hvedge_diff_large_ratio_mask                 (0x0F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_vspd_large_th_mask                           (0x007F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hdy_spd_large_th_mask                        (0x00007F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hdiff_tolerance_mask                         (0x0000001F)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hvedge_diff_large_ratio(data)                (0x0F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_4_vspd_large_th(data)                          (0x007F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hdy_spd_large_th(data)                       (0x00007F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_4_hdiff_tolerance(data)                        (0x0000001F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_4_get_hvedge_diff_large_ratio(data)            ((0x0F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_get_vspd_large_th(data)                      ((0x007F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_get_hdy_spd_large_th(data)                   ((0x00007F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_4_get_hdiff_tolerance(data)                    (0x0000001F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_5                                              0x18019DC8
#define  VDPQ_YC_Post2DBPF_AdapTh_5_reg_addr                                     "0xB8019DC8"
#define  VDPQ_YC_Post2DBPF_AdapTh_5_reg                                          0xB8019DC8
#define  VDPQ_YC_Post2DBPF_AdapTh_5_inst_addr                                    "0x008F"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_5_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_5_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_5_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_5_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_5_vedge_hor_offset_shift                       (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_5_hedge_ver_offset_shift                       (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_5_vedge_hor_offset_mask                        (0x00007F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_5_hedge_ver_offset_mask                        (0x0000007F)
#define  VDPQ_YC_Post2DBPF_AdapTh_5_vedge_hor_offset(data)                       (0x00007F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_5_hedge_ver_offset(data)                       (0x0000007F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_5_get_vedge_hor_offset(data)                   ((0x00007F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_5_get_hedge_ver_offset(data)                   (0x0000007F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_6                                              0x18019DCC
#define  VDPQ_YC_Post2DBPF_AdapTh_6_reg_addr                                     "0xB8019DCC"
#define  VDPQ_YC_Post2DBPF_AdapTh_6_reg                                          0xB8019DCC
#define  VDPQ_YC_Post2DBPF_AdapTh_6_inst_addr                                    "0x0090"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_6_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_6_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_6_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_6_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_ver_offset_shift               (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_small_hordiff_th_shift      (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_small_hordiff_offset_shift  (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_base_shift                  (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_ver_offset_mask                (0x7F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_small_hordiff_th_mask       (0x003F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_small_hordiff_offset_mask   (0x0000FF00)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_base_mask                   (0x000000FF)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_ver_offset(data)               (0x7F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_small_hordiff_th(data)      (0x003F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_small_hordiff_offset(data)  (0x0000FF00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_6_dia_spd_large_th_base(data)                  (0x000000FF&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_6_get_dia_spd_large_ver_offset(data)           ((0x7F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_get_dia_spd_large_th_small_hordiff_th(data)  ((0x003F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_get_dia_spd_large_th_small_hordiff_offset(data) ((0x0000FF00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_6_get_dia_spd_large_th_base(data)              (0x000000FF&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_7                                              0x18019DD0
#define  VDPQ_YC_Post2DBPF_AdapTh_7_reg_addr                                     "0xB8019DD0"
#define  VDPQ_YC_Post2DBPF_AdapTh_7_reg                                          0xB8019DD0
#define  VDPQ_YC_Post2DBPF_AdapTh_7_inst_addr                                    "0x0091"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_7_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_7_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_7_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_7_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_c_small_th_shift                     (12)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_cdiff_large_ratio_shift              (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_cdiff_large_th_shift                 (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_c_small_th_mask                      (0x0001F000)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_cdiff_large_ratio_mask               (0x00000F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_cdiff_large_th_mask                  (0x0000001F)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_c_small_th(data)                     (0x0001F000&((data)<<12))
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_cdiff_large_ratio(data)              (0x00000F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_7_dual_ch_cdiff_large_th(data)                 (0x0000001F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_7_get_dual_ch_c_small_th(data)                 ((0x0001F000&(data))>>12)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_get_dual_ch_cdiff_large_ratio(data)          ((0x00000F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_7_get_dual_ch_cdiff_large_th(data)             (0x0000001F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_8                                              0x18019DD4
#define  VDPQ_YC_Post2DBPF_AdapTh_8_reg_addr                                     "0xB8019DD4"
#define  VDPQ_YC_Post2DBPF_AdapTh_8_reg                                          0xB8019DD4
#define  VDPQ_YC_Post2DBPF_AdapTh_8_inst_addr                                    "0x0092"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_8_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_8_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_8_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_8_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_much_larger_ratio_shift                (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_much_larger_th_shift                   (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_vdiff_diff_larger_th_shift             (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_large_th_shift                         (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_much_larger_ratio_mask                 (0x0F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_much_larger_th_mask                    (0x003F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_vdiff_diff_larger_th_mask              (0x00003F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_large_th_mask                          (0x0000007F)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_much_larger_ratio(data)                (0x0F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_much_larger_th(data)                   (0x003F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_vdiff_diff_larger_th(data)             (0x00003F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_8_hdiff_large_th(data)                         (0x0000007F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_8_get_hdiff_much_larger_ratio(data)            ((0x0F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_get_hdiff_much_larger_th(data)               ((0x003F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_get_hdiff_vdiff_diff_larger_th(data)         ((0x00003F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_8_get_hdiff_large_th(data)                     (0x0000007F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_9                                              0x18019DD8
#define  VDPQ_YC_Post2DBPF_AdapTh_9_reg_addr                                     "0xB8019DD8"
#define  VDPQ_YC_Post2DBPF_AdapTh_9_reg                                          0xB8019DD8
#define  VDPQ_YC_Post2DBPF_AdapTh_9_inst_addr                                    "0x0093"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_9_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_9_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_9_reg                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_9_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_ver_offset_shift              (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_ver_cdiff_small_th_shift      (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_hdiff_large_th_shift          (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_hdiff_much_larger_hor_offset_shift           (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_ver_offset_mask               (0x7F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_ver_cdiff_small_th_mask       (0x007F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_hdiff_large_th_mask           (0x00003F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_hdiff_much_larger_hor_offset_mask            (0x0000007F)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_ver_offset(data)              (0x7F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_ver_cdiff_small_th(data)      (0x007F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_9_ver_color_tran_hdiff_large_th(data)          (0x00003F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_9_hdiff_much_larger_hor_offset(data)           (0x0000007F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_9_get_ver_color_tran_ver_offset(data)          ((0x7F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_get_ver_color_tran_ver_cdiff_small_th(data)  ((0x007F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_get_ver_color_tran_hdiff_large_th(data)      ((0x00003F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_9_get_hdiff_much_larger_hor_offset(data)       (0x0000007F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_10                                             0x18019DDC
#define  VDPQ_YC_Post2DBPF_AdapTh_10_reg_addr                                    "0xB8019DDC"
#define  VDPQ_YC_Post2DBPF_AdapTh_10_reg                                         0xB8019DDC
#define  VDPQ_YC_Post2DBPF_AdapTh_10_inst_addr                                   "0x0094"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_10_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_10_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_10_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_10_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_detect_hor_offset_shift            (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_detect_ver_offset_shift            (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_hdiff_large_th_shift               (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_vdiff_small_th_shift               (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_detect_hor_offset_mask             (0x7F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_detect_ver_offset_mask             (0x007F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_hdiff_large_th_mask                (0x00003F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_vdiff_small_th_mask                (0x0000003F)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_detect_hor_offset(data)            (0x7F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_detect_ver_offset(data)            (0x007F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_hdiff_large_th(data)               (0x00003F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_10_colorbar_vdiff_small_th(data)               (0x0000003F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_10_get_colorbar_detect_hor_offset(data)        ((0x7F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_get_colorbar_detect_ver_offset(data)        ((0x007F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_get_colorbar_hdiff_large_th(data)           ((0x00003F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_10_get_colorbar_vdiff_small_th(data)           (0x0000003F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_11                                             0x18019DE0
#define  VDPQ_YC_Post2DBPF_AdapTh_11_reg_addr                                    "0xB8019DE0"
#define  VDPQ_YC_Post2DBPF_AdapTh_11_reg                                         0xB8019DE0
#define  VDPQ_YC_Post2DBPF_AdapTh_11_inst_addr                                   "0x0095"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_11_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_11_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_11_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_11_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_11_ver_avoid_th_c_shift                        (28)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_ver_avoid_th_y_shift                        (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_detect_ver_offset_shift              (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_hdiff_small_th_shift                 (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_vdiff_small_th_shift                 (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_ver_avoid_th_c_mask                         (0xF0000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_ver_avoid_th_y_mask                         (0x0F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_detect_ver_offset_mask               (0x007F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_hdiff_small_th_mask                  (0x00003F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_vdiff_small_th_mask                  (0x0000003F)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_ver_avoid_th_c(data)                        (0xF0000000&((data)<<28))
#define  VDPQ_YC_Post2DBPF_AdapTh_11_ver_avoid_th_y(data)                        (0x0F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_detect_ver_offset(data)              (0x007F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_hdiff_small_th(data)                 (0x00003F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_11_smooth_vdiff_small_th(data)                 (0x0000003F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_11_get_ver_avoid_th_c(data)                    ((0xF0000000&(data))>>28)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_get_ver_avoid_th_y(data)                    ((0x0F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_get_smooth_detect_ver_offset(data)          ((0x007F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_get_smooth_hdiff_small_th(data)             ((0x00003F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_11_get_smooth_vdiff_small_th(data)             (0x0000003F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_12                                             0x18019DE4
#define  VDPQ_YC_Post2DBPF_AdapTh_12_reg_addr                                    "0xB8019DE4"
#define  VDPQ_YC_Post2DBPF_AdapTh_12_reg                                         0xB8019DE4
#define  VDPQ_YC_Post2DBPF_AdapTh_12_inst_addr                                   "0x0096"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_12_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_12_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_12_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_12_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vedge_avoid_en_shift                        (31)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vcdiff_large_diff_th_shift                  (24)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vcdiff_large_ratio_shift                    (20)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_diff_large_ratio_shift              (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_diff_large_th_shift                 (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_gray_diff_small_th_shift            (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vedge_avoid_en_mask                         (0x80000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vcdiff_large_diff_th_mask                   (0x3F000000)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vcdiff_large_ratio_mask                     (0x00F00000)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_diff_large_ratio_mask               (0x000F0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_diff_large_th_mask                  (0x00007F00)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_gray_diff_small_th_mask             (0x0000001F)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vedge_avoid_en(data)                        (0x80000000&((data)<<31))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vcdiff_large_diff_th(data)                  (0x3F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_vcdiff_large_ratio(data)                    (0x00F00000&((data)<<20))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_diff_large_ratio(data)              (0x000F0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_diff_large_th(data)                 (0x00007F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_v2sides_gray_diff_small_th(data)            (0x0000001F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_12_get_vedge_avoid_en(data)                    ((0x80000000&(data))>>31)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_get_vcdiff_large_diff_th(data)              ((0x3F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_get_vcdiff_large_ratio(data)                ((0x00F00000&(data))>>20)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_get_v2sides_diff_large_ratio(data)          ((0x000F0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_get_v2sides_diff_large_th(data)             ((0x00007F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_12_get_v2sides_gray_diff_small_th(data)        (0x0000001F&(data))

#define  VDPQ_YC_Post2DBPF_AdapTh_13                                             0x18019DE8
#define  VDPQ_YC_Post2DBPF_AdapTh_13_reg_addr                                    "0xB8019DE8"
#define  VDPQ_YC_Post2DBPF_AdapTh_13_reg                                         0xB8019DE8
#define  VDPQ_YC_Post2DBPF_AdapTh_13_inst_addr                                   "0x0097"
#define  set_VDPQ_YC_Post2DBPF_AdapTh_13_reg(data)                               (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_13_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_AdapTh_13_reg                                     (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_AdapTh_13_reg))
#define  VDPQ_YC_Post2DBPF_AdapTh_13_upbnd_shift                                 (16)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_hedge_ratio_th_shift                        (12)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_hedge_bypass_en_shift                       (8)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_ignore_th_c_shift                           (4)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_ignore_th_y_shift                           (0)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_upbnd_mask                                  (0x00FF0000)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_hedge_ratio_th_mask                         (0x0000F000)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_hedge_bypass_en_mask                        (0x00000100)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_ignore_th_c_mask                            (0x000000F0)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_ignore_th_y_mask                            (0x0000000F)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_upbnd(data)                                 (0x00FF0000&((data)<<16))
#define  VDPQ_YC_Post2DBPF_AdapTh_13_hedge_ratio_th(data)                        (0x0000F000&((data)<<12))
#define  VDPQ_YC_Post2DBPF_AdapTh_13_hedge_bypass_en(data)                       (0x00000100&((data)<<8))
#define  VDPQ_YC_Post2DBPF_AdapTh_13_ignore_th_c(data)                           (0x000000F0&((data)<<4))
#define  VDPQ_YC_Post2DBPF_AdapTh_13_ignore_th_y(data)                           (0x0000000F&(data))
#define  VDPQ_YC_Post2DBPF_AdapTh_13_get_upbnd(data)                             ((0x00FF0000&(data))>>16)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_get_hedge_ratio_th(data)                    ((0x0000F000&(data))>>12)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_get_hedge_bypass_en(data)                   ((0x00000100&(data))>>8)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_get_ignore_th_c(data)                       ((0x000000F0&(data))>>4)
#define  VDPQ_YC_Post2DBPF_AdapTh_13_get_ignore_th_y(data)                       (0x0000000F&(data))

#define  VDPQ_YC_Post2DBPF_XC                                                    0x18019DEC
#define  VDPQ_YC_Post2DBPF_XC_reg_addr                                           "0xB8019DEC"
#define  VDPQ_YC_Post2DBPF_XC_reg                                                0xB8019DEC
#define  VDPQ_YC_Post2DBPF_XC_inst_addr                                          "0x0098"
#define  set_VDPQ_YC_Post2DBPF_XC_reg(data)                                      (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_XC_reg)=data)
#define  get_VDPQ_YC_Post2DBPF_XC_reg                                            (*((volatile unsigned int*)VDPQ_YC_Post2DBPF_XC_reg))
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_avoid_en_shift                           (31)
#define  VDPQ_YC_Post2DBPF_XC_xc_cdiff_upbnd_shift                               (24)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_ratio_th_2_shift                         (20)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_th_2_shift                               (12)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_ratio_th_1_shift                         (8)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_th_1_shift                               (0)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_avoid_en_mask                            (0x80000000)
#define  VDPQ_YC_Post2DBPF_XC_xc_cdiff_upbnd_mask                                (0x3F000000)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_ratio_th_2_mask                          (0x00F00000)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_th_2_mask                                (0x0001F000)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_ratio_th_1_mask                          (0x00000F00)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_th_1_mask                                (0x0000001F)
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_avoid_en(data)                           (0x80000000&((data)<<31))
#define  VDPQ_YC_Post2DBPF_XC_xc_cdiff_upbnd(data)                               (0x3F000000&((data)<<24))
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_ratio_th_2(data)                         (0x00F00000&((data)<<20))
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_th_2(data)                               (0x0001F000&((data)<<12))
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_ratio_th_1(data)                         (0x00000F00&((data)<<8))
#define  VDPQ_YC_Post2DBPF_XC_xc_hvedge_th_1(data)                               (0x0000001F&(data))
#define  VDPQ_YC_Post2DBPF_XC_get_xc_hvedge_avoid_en(data)                       ((0x80000000&(data))>>31)
#define  VDPQ_YC_Post2DBPF_XC_get_xc_cdiff_upbnd(data)                           ((0x3F000000&(data))>>24)
#define  VDPQ_YC_Post2DBPF_XC_get_xc_hvedge_ratio_th_2(data)                     ((0x00F00000&(data))>>20)
#define  VDPQ_YC_Post2DBPF_XC_get_xc_hvedge_th_2(data)                           ((0x0001F000&(data))>>12)
#define  VDPQ_YC_Post2DBPF_XC_get_xc_hvedge_ratio_th_1(data)                     ((0x00000F00&(data))>>8)
#define  VDPQ_YC_Post2DBPF_XC_get_xc_hvedge_th_1(data)                           (0x0000001F&(data))

#define  VDPQ_SECAM_YADAP_MODE                                                   0x18019DF0
#define  VDPQ_SECAM_YADAP_MODE_reg_addr                                          "0xB8019DF0"
#define  VDPQ_SECAM_YADAP_MODE_reg                                               0xB8019DF0
#define  VDPQ_SECAM_YADAP_MODE_inst_addr                                         "0x0099"
#define  set_VDPQ_SECAM_YADAP_MODE_reg(data)                                     (*((volatile unsigned int*)VDPQ_SECAM_YADAP_MODE_reg)=data)
#define  get_VDPQ_SECAM_YADAP_MODE_reg                                           (*((volatile unsigned int*)VDPQ_SECAM_YADAP_MODE_reg))
#define  VDPQ_SECAM_YADAP_MODE_yadap_hpf_sel_shift                               (2)
#define  VDPQ_SECAM_YADAP_MODE_yadap_peak_mode_shift                             (0)
#define  VDPQ_SECAM_YADAP_MODE_yadap_hpf_sel_mask                                (0x0000000C)
#define  VDPQ_SECAM_YADAP_MODE_yadap_peak_mode_mask                              (0x00000003)
#define  VDPQ_SECAM_YADAP_MODE_yadap_hpf_sel(data)                               (0x0000000C&((data)<<2))
#define  VDPQ_SECAM_YADAP_MODE_yadap_peak_mode(data)                             (0x00000003&(data))
#define  VDPQ_SECAM_YADAP_MODE_get_yadap_hpf_sel(data)                           ((0x0000000C&(data))>>2)
#define  VDPQ_SECAM_YADAP_MODE_get_yadap_peak_mode(data)                         (0x00000003&(data))

#define  VDPQ_SECAM_YADAP_CTRL1                                                  0x18019DF4
#define  VDPQ_SECAM_YADAP_CTRL1_reg_addr                                         "0xB8019DF4"
#define  VDPQ_SECAM_YADAP_CTRL1_reg                                              0xB8019DF4
#define  VDPQ_SECAM_YADAP_CTRL1_inst_addr                                        "0x009A"
#define  set_VDPQ_SECAM_YADAP_CTRL1_reg(data)                                    (*((volatile unsigned int*)VDPQ_SECAM_YADAP_CTRL1_reg)=data)
#define  get_VDPQ_SECAM_YADAP_CTRL1_reg                                          (*((volatile unsigned int*)VDPQ_SECAM_YADAP_CTRL1_reg))
#define  VDPQ_SECAM_YADAP_CTRL1_yadap_peak_gain_shift                            (4)
#define  VDPQ_SECAM_YADAP_CTRL1_yadap_peak_th_shift                              (0)
#define  VDPQ_SECAM_YADAP_CTRL1_yadap_peak_gain_mask                             (0x000000F0)
#define  VDPQ_SECAM_YADAP_CTRL1_yadap_peak_th_mask                               (0x0000000F)
#define  VDPQ_SECAM_YADAP_CTRL1_yadap_peak_gain(data)                            (0x000000F0&((data)<<4))
#define  VDPQ_SECAM_YADAP_CTRL1_yadap_peak_th(data)                              (0x0000000F&(data))
#define  VDPQ_SECAM_YADAP_CTRL1_get_yadap_peak_gain(data)                        ((0x000000F0&(data))>>4)
#define  VDPQ_SECAM_YADAP_CTRL1_get_yadap_peak_th(data)                          (0x0000000F&(data))

#define  VDPQ_SECAM_YADAP_CTRL2                                                  0x18019DF8
#define  VDPQ_SECAM_YADAP_CTRL2_reg_addr                                         "0xB8019DF8"
#define  VDPQ_SECAM_YADAP_CTRL2_reg                                              0xB8019DF8
#define  VDPQ_SECAM_YADAP_CTRL2_inst_addr                                        "0x009B"
#define  set_VDPQ_SECAM_YADAP_CTRL2_reg(data)                                    (*((volatile unsigned int*)VDPQ_SECAM_YADAP_CTRL2_reg)=data)
#define  get_VDPQ_SECAM_YADAP_CTRL2_reg                                          (*((volatile unsigned int*)VDPQ_SECAM_YADAP_CTRL2_reg))
#define  VDPQ_SECAM_YADAP_CTRL2_yadap_peak_gain_2d_shift                         (4)
#define  VDPQ_SECAM_YADAP_CTRL2_yadap_uniform_gain_shift                         (0)
#define  VDPQ_SECAM_YADAP_CTRL2_yadap_peak_gain_2d_mask                          (0x000000F0)
#define  VDPQ_SECAM_YADAP_CTRL2_yadap_uniform_gain_mask                          (0x0000000F)
#define  VDPQ_SECAM_YADAP_CTRL2_yadap_peak_gain_2d(data)                         (0x000000F0&((data)<<4))
#define  VDPQ_SECAM_YADAP_CTRL2_yadap_uniform_gain(data)                         (0x0000000F&(data))
#define  VDPQ_SECAM_YADAP_CTRL2_get_yadap_peak_gain_2d(data)                     ((0x000000F0&(data))>>4)
#define  VDPQ_SECAM_YADAP_CTRL2_get_yadap_uniform_gain(data)                     (0x0000000F&(data))

#define  VDPQ_XNR_CTRL                                                           0x18019E04
#define  VDPQ_XNR_CTRL_reg_addr                                                  "0xB8019E04"
#define  VDPQ_XNR_CTRL_reg                                                       0xB8019E04
#define  VDPQ_XNR_CTRL_inst_addr                                                 "0x009C"
#define  set_VDPQ_XNR_CTRL_reg(data)                                             (*((volatile unsigned int*)VDPQ_XNR_CTRL_reg)=data)
#define  get_VDPQ_XNR_CTRL_reg                                                   (*((volatile unsigned int*)VDPQ_XNR_CTRL_reg))
#define  VDPQ_XNR_CTRL_postpq_alphadelay_indep_en_shift                          (31)
#define  VDPQ_XNR_CTRL_postpq_alphadelay_shift                                   (20)
#define  VDPQ_XNR_CTRL_postpq_malphadelay_shift                                  (12)
#define  VDPQ_XNR_CTRL_xnr_lpf_sel_shift                                         (6)
#define  VDPQ_XNR_CTRL_xnr_vlpf_sel_shift                                        (4)
#define  VDPQ_XNR_CTRL_xnr_blend_dbm_shift                                       (3)
#define  VDPQ_XNR_CTRL_xnr_blend_en_shift                                        (2)
#define  VDPQ_XNR_CTRL_xnr_det_bypass_en_shift                                   (1)
#define  VDPQ_XNR_CTRL_xnr_en_shift                                              (0)
#define  VDPQ_XNR_CTRL_postpq_alphadelay_indep_en_mask                           (0x80000000)
#define  VDPQ_XNR_CTRL_postpq_alphadelay_mask                                    (0x03F00000)
#define  VDPQ_XNR_CTRL_postpq_malphadelay_mask                                   (0x0003F000)
#define  VDPQ_XNR_CTRL_xnr_lpf_sel_mask                                          (0x000000C0)
#define  VDPQ_XNR_CTRL_xnr_vlpf_sel_mask                                         (0x00000030)
#define  VDPQ_XNR_CTRL_xnr_blend_dbm_mask                                        (0x00000008)
#define  VDPQ_XNR_CTRL_xnr_blend_en_mask                                         (0x00000004)
#define  VDPQ_XNR_CTRL_xnr_det_bypass_en_mask                                    (0x00000002)
#define  VDPQ_XNR_CTRL_xnr_en_mask                                               (0x00000001)
#define  VDPQ_XNR_CTRL_postpq_alphadelay_indep_en(data)                          (0x80000000&((data)<<31))
#define  VDPQ_XNR_CTRL_postpq_alphadelay(data)                                   (0x03F00000&((data)<<20))
#define  VDPQ_XNR_CTRL_postpq_malphadelay(data)                                  (0x0003F000&((data)<<12))
#define  VDPQ_XNR_CTRL_xnr_lpf_sel(data)                                         (0x000000C0&((data)<<6))
#define  VDPQ_XNR_CTRL_xnr_vlpf_sel(data)                                        (0x00000030&((data)<<4))
#define  VDPQ_XNR_CTRL_xnr_blend_dbm(data)                                       (0x00000008&((data)<<3))
#define  VDPQ_XNR_CTRL_xnr_blend_en(data)                                        (0x00000004&((data)<<2))
#define  VDPQ_XNR_CTRL_xnr_det_bypass_en(data)                                   (0x00000002&((data)<<1))
#define  VDPQ_XNR_CTRL_xnr_en(data)                                              (0x00000001&(data))
#define  VDPQ_XNR_CTRL_get_postpq_alphadelay_indep_en(data)                      ((0x80000000&(data))>>31)
#define  VDPQ_XNR_CTRL_get_postpq_alphadelay(data)                               ((0x03F00000&(data))>>20)
#define  VDPQ_XNR_CTRL_get_postpq_malphadelay(data)                              ((0x0003F000&(data))>>12)
#define  VDPQ_XNR_CTRL_get_xnr_lpf_sel(data)                                     ((0x000000C0&(data))>>6)
#define  VDPQ_XNR_CTRL_get_xnr_vlpf_sel(data)                                    ((0x00000030&(data))>>4)
#define  VDPQ_XNR_CTRL_get_xnr_blend_dbm(data)                                   ((0x00000008&(data))>>3)
#define  VDPQ_XNR_CTRL_get_xnr_blend_en(data)                                    ((0x00000004&(data))>>2)
#define  VDPQ_XNR_CTRL_get_xnr_det_bypass_en(data)                               ((0x00000002&(data))>>1)
#define  VDPQ_XNR_CTRL_get_xnr_en(data)                                          (0x00000001&(data))

#define  VDPQ_XNR_THR                                                            0x18019E08
#define  VDPQ_XNR_THR_reg_addr                                                   "0xB8019E08"
#define  VDPQ_XNR_THR_reg                                                        0xB8019E08
#define  VDPQ_XNR_THR_inst_addr                                                  "0x009D"
#define  set_VDPQ_XNR_THR_reg(data)                                              (*((volatile unsigned int*)VDPQ_XNR_THR_reg)=data)
#define  get_VDPQ_XNR_THR_reg                                                    (*((volatile unsigned int*)VDPQ_XNR_THR_reg))
#define  VDPQ_XNR_THR_xnr_cdiff_thr_shift                                        (4)
#define  VDPQ_XNR_THR_xnr_csum_thr_shift                                         (0)
#define  VDPQ_XNR_THR_xnr_cdiff_thr_mask                                         (0x000000F0)
#define  VDPQ_XNR_THR_xnr_csum_thr_mask                                          (0x0000000F)
#define  VDPQ_XNR_THR_xnr_cdiff_thr(data)                                        (0x000000F0&((data)<<4))
#define  VDPQ_XNR_THR_xnr_csum_thr(data)                                         (0x0000000F&(data))
#define  VDPQ_XNR_THR_get_xnr_cdiff_thr(data)                                    ((0x000000F0&(data))>>4)
#define  VDPQ_XNR_THR_get_xnr_csum_thr(data)                                     (0x0000000F&(data))

#define  VDPQ_XNR_IDX_THR                                                        0x18019E0C
#define  VDPQ_XNR_IDX_THR_reg_addr                                               "0xB8019E0C"
#define  VDPQ_XNR_IDX_THR_reg                                                    0xB8019E0C
#define  VDPQ_XNR_IDX_THR_inst_addr                                              "0x009E"
#define  set_VDPQ_XNR_IDX_THR_reg(data)                                          (*((volatile unsigned int*)VDPQ_XNR_IDX_THR_reg)=data)
#define  get_VDPQ_XNR_IDX_THR_reg                                                (*((volatile unsigned int*)VDPQ_XNR_IDX_THR_reg))
#define  VDPQ_XNR_IDX_THR_xnr_idxgain_shift                                      (4)
#define  VDPQ_XNR_IDX_THR_xnr_ver_idxgain_shift                                  (0)
#define  VDPQ_XNR_IDX_THR_xnr_idxgain_mask                                       (0x000000F0)
#define  VDPQ_XNR_IDX_THR_xnr_ver_idxgain_mask                                   (0x0000000F)
#define  VDPQ_XNR_IDX_THR_xnr_idxgain(data)                                      (0x000000F0&((data)<<4))
#define  VDPQ_XNR_IDX_THR_xnr_ver_idxgain(data)                                  (0x0000000F&(data))
#define  VDPQ_XNR_IDX_THR_get_xnr_idxgain(data)                                  ((0x000000F0&(data))>>4)
#define  VDPQ_XNR_IDX_THR_get_xnr_ver_idxgain(data)                              (0x0000000F&(data))

#define  VDPQ_XNR_RATIO_CTRL                                                     0x18019E10
#define  VDPQ_XNR_RATIO_CTRL_reg_addr                                            "0xB8019E10"
#define  VDPQ_XNR_RATIO_CTRL_reg                                                 0xB8019E10
#define  VDPQ_XNR_RATIO_CTRL_inst_addr                                           "0x009F"
#define  set_VDPQ_XNR_RATIO_CTRL_reg(data)                                       (*((volatile unsigned int*)VDPQ_XNR_RATIO_CTRL_reg)=data)
#define  get_VDPQ_XNR_RATIO_CTRL_reg                                             (*((volatile unsigned int*)VDPQ_XNR_RATIO_CTRL_reg))
#define  VDPQ_XNR_RATIO_CTRL_xnr_ver_ratio_shift                                 (4)
#define  VDPQ_XNR_RATIO_CTRL_xnr_ver_ratio_w_shift                               (0)
#define  VDPQ_XNR_RATIO_CTRL_xnr_ver_ratio_mask                                  (0x000000F0)
#define  VDPQ_XNR_RATIO_CTRL_xnr_ver_ratio_w_mask                                (0x0000000F)
#define  VDPQ_XNR_RATIO_CTRL_xnr_ver_ratio(data)                                 (0x000000F0&((data)<<4))
#define  VDPQ_XNR_RATIO_CTRL_xnr_ver_ratio_w(data)                               (0x0000000F&(data))
#define  VDPQ_XNR_RATIO_CTRL_get_xnr_ver_ratio(data)                             ((0x000000F0&(data))>>4)
#define  VDPQ_XNR_RATIO_CTRL_get_xnr_ver_ratio_w(data)                           (0x0000000F&(data))

#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1                                        0x18019E14
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg_addr                               "0xB8019E14"
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg                                    0xB8019E14
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_inst_addr                              "0x00A0"
#define  set_VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg(data)                          (*((volatile unsigned int*)VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg)=data)
#define  get_VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg                                (*((volatile unsigned int*)VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_sum_th_shift                 (24)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_single_th_shift              (16)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_en_shift                     (15)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_mf_en_shift                            (13)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ma0_cnt_th_shift                       (8)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_point_type_coring_lv_shift             (4)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_vline_len_3_sel_shift                  (3)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_vline_con_en_shift                     (2)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_cdiff_small_con_en_shift               (1)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ma0_con_en_shift                       (0)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_sum_th_mask                  (0x7F000000)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_single_th_mask               (0x003F0000)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_en_mask                      (0x00008000)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_mf_en_mask                             (0x00002000)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ma0_cnt_th_mask                        (0x00001F00)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_point_type_coring_lv_mask              (0x000000F0)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_vline_len_3_sel_mask                   (0x00000008)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_vline_con_en_mask                      (0x00000004)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_cdiff_small_con_en_mask                (0x00000002)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ma0_con_en_mask                        (0x00000001)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_sum_th(data)                 (0x7F000000&((data)<<24))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_single_th(data)              (0x003F0000&((data)<<16))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ver_cedge_en(data)                     (0x00008000&((data)<<15))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_mf_en(data)                            (0x00002000&((data)<<13))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ma0_cnt_th(data)                       (0x00001F00&((data)<<8))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_point_type_coring_lv(data)             (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_vline_len_3_sel(data)                  (0x00000008&((data)<<3))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_vline_con_en(data)                     (0x00000004&((data)<<2))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_cdiff_small_con_en(data)               (0x00000002&((data)<<1))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_ma0_con_en(data)                       (0x00000001&(data))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_ver_cedge_sum_th(data)             ((0x7F000000&(data))>>24)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_ver_cedge_single_th(data)          ((0x003F0000&(data))>>16)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_ver_cedge_en(data)                 ((0x00008000&(data))>>15)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_mf_en(data)                        ((0x00002000&(data))>>13)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_ma0_cnt_th(data)                   ((0x00001F00&(data))>>8)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_point_type_coring_lv(data)         ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_vline_len_3_sel(data)              ((0x00000008&(data))>>3)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_vline_con_en(data)                 ((0x00000004&(data))>>2)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_cdiff_small_con_en(data)           ((0x00000002&(data))>>1)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_get_ma0_con_en(data)                   (0x00000001&(data))

#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2                                        0x18019E18
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg_addr                               "0xB8019E18"
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg                                    0xB8019E18
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_inst_addr                              "0x00A1"
#define  set_VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg(data)                          (*((volatile unsigned int*)VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg)=data)
#define  get_VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg                                (*((volatile unsigned int*)VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_sum_th_shift               (12)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_single_th_shift            (4)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_len_shift                  (0)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_sum_th_mask                (0x0007F000)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_single_th_mask             (0x000003F0)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_len_mask                   (0x0000000F)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_sum_th(data)               (0x0007F000&((data)<<12))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_single_th(data)            (0x000003F0&((data)<<4))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_cdiff_small_len(data)                  (0x0000000F&(data))
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_get_cdiff_small_sum_th(data)           ((0x0007F000&(data))>>12)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_get_cdiff_small_single_th(data)        ((0x000003F0&(data))>>4)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_get_cdiff_small_len(data)              (0x0000000F&(data))

#define  VDPQ_yc2d_postpk2_ctrl1                                                 0x18019E1C
#define  VDPQ_yc2d_postpk2_ctrl1_reg_addr                                        "0xB8019E1C"
#define  VDPQ_yc2d_postpk2_ctrl1_reg                                             0xB8019E1C
#define  VDPQ_yc2d_postpk2_ctrl1_inst_addr                                       "0x00A2"
#define  set_VDPQ_yc2d_postpk2_ctrl1_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postpk2_ctrl1_reg)=data)
#define  get_VDPQ_yc2d_postpk2_ctrl1_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postpk2_ctrl1_reg))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_prelpf_mode_shift                        (9)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_prelpf_en_shift                          (8)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_alphablend_en_shift                      (5)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_dnoise_en_shift                          (4)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_adap_mode_shift                          (2)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_adappk_en_shift                          (1)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_en_shift                                 (0)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_prelpf_mode_mask                         (0x00000200)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_prelpf_en_mask                           (0x00000100)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_alphablend_en_mask                       (0x00000020)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_dnoise_en_mask                           (0x00000010)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_adap_mode_mask                           (0x0000000C)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_adappk_en_mask                           (0x00000002)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_en_mask                                  (0x00000001)
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_prelpf_mode(data)                        (0x00000200&((data)<<9))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_prelpf_en(data)                          (0x00000100&((data)<<8))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_alphablend_en(data)                      (0x00000020&((data)<<5))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_dnoise_en(data)                          (0x00000010&((data)<<4))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_adap_mode(data)                          (0x0000000C&((data)<<2))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_adappk_en(data)                          (0x00000002&((data)<<1))
#define  VDPQ_yc2d_postpk2_ctrl1_postpk_en(data)                                 (0x00000001&(data))
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_prelpf_mode(data)                    ((0x00000200&(data))>>9)
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_prelpf_en(data)                      ((0x00000100&(data))>>8)
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_alphablend_en(data)                  ((0x00000020&(data))>>5)
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_dnoise_en(data)                      ((0x00000010&(data))>>4)
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_adap_mode(data)                      ((0x0000000C&(data))>>2)
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_adappk_en(data)                      ((0x00000002&(data))>>1)
#define  VDPQ_yc2d_postpk2_ctrl1_get_postpk_en(data)                             (0x00000001&(data))

#define  VDPQ_yc2d_postpk2_adap1                                                 0x18019E20
#define  VDPQ_yc2d_postpk2_adap1_reg_addr                                        "0xB8019E20"
#define  VDPQ_yc2d_postpk2_adap1_reg                                             0xB8019E20
#define  VDPQ_yc2d_postpk2_adap1_inst_addr                                       "0x00A3"
#define  set_VDPQ_yc2d_postpk2_adap1_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postpk2_adap1_reg)=data)
#define  get_VDPQ_yc2d_postpk2_adap1_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postpk2_adap1_reg))
#define  VDPQ_yc2d_postpk2_adap1_postpk_c_stepbit_shift                          (24)
#define  VDPQ_yc2d_postpk2_adap1_postpk_c_lwbnd_shift                            (16)
#define  VDPQ_yc2d_postpk2_adap1_postpk_y_stepbit_shift                          (8)
#define  VDPQ_yc2d_postpk2_adap1_postpk_y_lwbnd_shift                            (0)
#define  VDPQ_yc2d_postpk2_adap1_postpk_c_stepbit_mask                           (0x07000000)
#define  VDPQ_yc2d_postpk2_adap1_postpk_c_lwbnd_mask                             (0x00FF0000)
#define  VDPQ_yc2d_postpk2_adap1_postpk_y_stepbit_mask                           (0x00000700)
#define  VDPQ_yc2d_postpk2_adap1_postpk_y_lwbnd_mask                             (0x000000FF)
#define  VDPQ_yc2d_postpk2_adap1_postpk_c_stepbit(data)                          (0x07000000&((data)<<24))
#define  VDPQ_yc2d_postpk2_adap1_postpk_c_lwbnd(data)                            (0x00FF0000&((data)<<16))
#define  VDPQ_yc2d_postpk2_adap1_postpk_y_stepbit(data)                          (0x00000700&((data)<<8))
#define  VDPQ_yc2d_postpk2_adap1_postpk_y_lwbnd(data)                            (0x000000FF&(data))
#define  VDPQ_yc2d_postpk2_adap1_get_postpk_c_stepbit(data)                      ((0x07000000&(data))>>24)
#define  VDPQ_yc2d_postpk2_adap1_get_postpk_c_lwbnd(data)                        ((0x00FF0000&(data))>>16)
#define  VDPQ_yc2d_postpk2_adap1_get_postpk_y_stepbit(data)                      ((0x00000700&(data))>>8)
#define  VDPQ_yc2d_postpk2_adap1_get_postpk_y_lwbnd(data)                        (0x000000FF&(data))

#define  VDPQ_yc2d_postpk2_dnoise1                                               0x18019E24
#define  VDPQ_yc2d_postpk2_dnoise1_reg_addr                                      "0xB8019E24"
#define  VDPQ_yc2d_postpk2_dnoise1_reg                                           0xB8019E24
#define  VDPQ_yc2d_postpk2_dnoise1_inst_addr                                     "0x00A4"
#define  set_VDPQ_yc2d_postpk2_dnoise1_reg(data)                                 (*((volatile unsigned int*)VDPQ_yc2d_postpk2_dnoise1_reg)=data)
#define  get_VDPQ_yc2d_postpk2_dnoise1_reg                                       (*((volatile unsigned int*)VDPQ_yc2d_postpk2_dnoise1_reg))
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_upbnd_shift                         (16)
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_sft_shift                           (8)
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_th_shift                            (0)
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_upbnd_mask                          (0x00FF0000)
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_sft_mask                            (0x00000700)
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_th_mask                             (0x000000FF)
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_upbnd(data)                         (0x00FF0000&((data)<<16))
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_sft(data)                           (0x00000700&((data)<<8))
#define  VDPQ_yc2d_postpk2_dnoise1_postpk_lv_th(data)                            (0x000000FF&(data))
#define  VDPQ_yc2d_postpk2_dnoise1_get_postpk_lv_upbnd(data)                     ((0x00FF0000&(data))>>16)
#define  VDPQ_yc2d_postpk2_dnoise1_get_postpk_lv_sft(data)                       ((0x00000700&(data))>>8)
#define  VDPQ_yc2d_postpk2_dnoise1_get_postpk_lv_th(data)                        (0x000000FF&(data))

#define  VDPQ_yc2d_postpk2_filter_0                                              0x18019E28
#define  VDPQ_yc2d_postpk2_filter_0_reg_addr                                     "0xB8019E28"
#define  VDPQ_yc2d_postpk2_filter_0_reg                                          0xB8019E28
#define  VDPQ_yc2d_postpk2_filter_0_inst_addr                                    "0x00A5"
#define  set_VDPQ_yc2d_postpk2_filter_0_reg(data)                                (*((volatile unsigned int*)VDPQ_yc2d_postpk2_filter_0_reg)=data)
#define  get_VDPQ_yc2d_postpk2_filter_0_reg                                      (*((volatile unsigned int*)VDPQ_yc2d_postpk2_filter_0_reg))
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c0_shift                              (20)
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c1_shift                              (8)
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c2_shift                              (0)
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c0_mask                               (0x1FF00000)
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c1_mask                               (0x0001FF00)
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c2_mask                               (0x000000FF)
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c0(data)                              (0x1FF00000&((data)<<20))
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c1(data)                              (0x0001FF00&((data)<<8))
#define  VDPQ_yc2d_postpk2_filter_0_postpk_c2(data)                              (0x000000FF&(data))
#define  VDPQ_yc2d_postpk2_filter_0_get_postpk_c0(data)                          ((0x1FF00000&(data))>>20)
#define  VDPQ_yc2d_postpk2_filter_0_get_postpk_c1(data)                          ((0x0001FF00&(data))>>8)
#define  VDPQ_yc2d_postpk2_filter_0_get_postpk_c2(data)                          (0x000000FF&(data))

#define  VDPQ_yc2d_postpk2_gain                                                  0x18019E2C
#define  VDPQ_yc2d_postpk2_gain_reg_addr                                         "0xB8019E2C"
#define  VDPQ_yc2d_postpk2_gain_reg                                              0xB8019E2C
#define  VDPQ_yc2d_postpk2_gain_inst_addr                                        "0x00A6"
#define  set_VDPQ_yc2d_postpk2_gain_reg(data)                                    (*((volatile unsigned int*)VDPQ_yc2d_postpk2_gain_reg)=data)
#define  get_VDPQ_yc2d_postpk2_gain_reg                                          (*((volatile unsigned int*)VDPQ_yc2d_postpk2_gain_reg))
#define  VDPQ_yc2d_postpk2_gain_postpk_gain_pos_shift                            (8)
#define  VDPQ_yc2d_postpk2_gain_postpk_gain_neg_shift                            (0)
#define  VDPQ_yc2d_postpk2_gain_postpk_gain_pos_mask                             (0x0000FF00)
#define  VDPQ_yc2d_postpk2_gain_postpk_gain_neg_mask                             (0x000000FF)
#define  VDPQ_yc2d_postpk2_gain_postpk_gain_pos(data)                            (0x0000FF00&((data)<<8))
#define  VDPQ_yc2d_postpk2_gain_postpk_gain_neg(data)                            (0x000000FF&(data))
#define  VDPQ_yc2d_postpk2_gain_get_postpk_gain_pos(data)                        ((0x0000FF00&(data))>>8)
#define  VDPQ_yc2d_postpk2_gain_get_postpk_gain_neg(data)                        (0x000000FF&(data))

#define  VDPQ_yc2d_postpk2_bound                                                 0x18019E30
#define  VDPQ_yc2d_postpk2_bound_reg_addr                                        "0xB8019E30"
#define  VDPQ_yc2d_postpk2_bound_reg                                             0xB8019E30
#define  VDPQ_yc2d_postpk2_bound_inst_addr                                       "0x00A7"
#define  set_VDPQ_yc2d_postpk2_bound_reg(data)                                   (*((volatile unsigned int*)VDPQ_yc2d_postpk2_bound_reg)=data)
#define  get_VDPQ_yc2d_postpk2_bound_reg                                         (*((volatile unsigned int*)VDPQ_yc2d_postpk2_bound_reg))
#define  VDPQ_yc2d_postpk2_bound_postpk_hv_pos_shift                             (18)
#define  VDPQ_yc2d_postpk2_bound_postpk_hv_neg_shift                             (8)
#define  VDPQ_yc2d_postpk2_bound_postpk_lv_shift                                 (0)
#define  VDPQ_yc2d_postpk2_bound_postpk_hv_pos_mask                              (0x0FFC0000)
#define  VDPQ_yc2d_postpk2_bound_postpk_hv_neg_mask                              (0x0003FF00)
#define  VDPQ_yc2d_postpk2_bound_postpk_lv_mask                                  (0x000000FF)
#define  VDPQ_yc2d_postpk2_bound_postpk_hv_pos(data)                             (0x0FFC0000&((data)<<18))
#define  VDPQ_yc2d_postpk2_bound_postpk_hv_neg(data)                             (0x0003FF00&((data)<<8))
#define  VDPQ_yc2d_postpk2_bound_postpk_lv(data)                                 (0x000000FF&(data))
#define  VDPQ_yc2d_postpk2_bound_get_postpk_hv_pos(data)                         ((0x0FFC0000&(data))>>18)
#define  VDPQ_yc2d_postpk2_bound_get_postpk_hv_neg(data)                         ((0x0003FF00&(data))>>8)
#define  VDPQ_yc2d_postpk2_bound_get_postpk_lv(data)                             (0x000000FF&(data))

#define  VDPQ_POSTP_DLTI_CTRL1                                                   0x18019E34
#define  VDPQ_POSTP_DLTI_CTRL1_reg_addr                                          "0xB8019E34"
#define  VDPQ_POSTP_DLTI_CTRL1_reg                                               0xB8019E34
#define  VDPQ_POSTP_DLTI_CTRL1_inst_addr                                         "0x00A8"
#define  set_VDPQ_POSTP_DLTI_CTRL1_reg(data)                                     (*((volatile unsigned int*)VDPQ_POSTP_DLTI_CTRL1_reg)=data)
#define  get_VDPQ_POSTP_DLTI_CTRL1_reg                                           (*((volatile unsigned int*)VDPQ_POSTP_DLTI_CTRL1_reg))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd2_ratio_shift                             (28)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd2_en_shift                                (24)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd1_ratio_shift                             (20)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd1_th_shift                                (12)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_maxlen_shift                                 (8)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_pnth_shift                                   (1)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_en_shift                                     (0)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd2_ratio_mask                              (0xF0000000)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd2_en_mask                                 (0x01000000)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd1_ratio_mask                              (0x00F00000)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd1_th_mask                                 (0x0001F000)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_maxlen_mask                                  (0x00000700)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_pnth_mask                                    (0x000000FE)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_en_mask                                      (0x00000001)
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd2_ratio(data)                             (0xF0000000&((data)<<28))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd2_en(data)                                (0x01000000&((data)<<24))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd1_ratio(data)                             (0x00F00000&((data)<<20))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_ffd1_th(data)                                (0x0001F000&((data)<<12))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_maxlen(data)                                 (0x00000700&((data)<<8))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_pnth(data)                                   (0x000000FE&((data)<<1))
#define  VDPQ_POSTP_DLTI_CTRL1_dlti_en(data)                                     (0x00000001&(data))
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_ffd2_ratio(data)                         ((0xF0000000&(data))>>28)
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_ffd2_en(data)                            ((0x01000000&(data))>>24)
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_ffd1_ratio(data)                         ((0x00F00000&(data))>>20)
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_ffd1_th(data)                            ((0x0001F000&(data))>>12)
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_maxlen(data)                             ((0x00000700&(data))>>8)
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_pnth(data)                               ((0x000000FE&(data))>>1)
#define  VDPQ_POSTP_DLTI_CTRL1_get_dlti_en(data)                                 (0x00000001&(data))

#define  VDPQ_POSTP_DLTI_CTRL2                                                   0x18019E38
#define  VDPQ_POSTP_DLTI_CTRL2_reg_addr                                          "0xB8019E38"
#define  VDPQ_POSTP_DLTI_CTRL2_reg                                               0xB8019E38
#define  VDPQ_POSTP_DLTI_CTRL2_inst_addr                                         "0x00A9"
#define  set_VDPQ_POSTP_DLTI_CTRL2_reg(data)                                     (*((volatile unsigned int*)VDPQ_POSTP_DLTI_CTRL2_reg)=data)
#define  get_VDPQ_POSTP_DLTI_CTRL2_reg                                           (*((volatile unsigned int*)VDPQ_POSTP_DLTI_CTRL2_reg))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_d1_cp_shift_shift                            (28)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_dcp_th_shift                                 (20)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_tn_blend_mode_shift                          (17)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_tn_blend_en_shift                            (16)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ovc_en_shift                                 (12)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_can_shift_shift                              (8)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ffd2_range2l_shift                           (4)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ffd2_range2r_shift                           (0)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_d1_cp_shift_mask                             (0xF0000000)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_dcp_th_mask                                  (0x03F00000)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_tn_blend_mode_mask                           (0x00020000)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_tn_blend_en_mask                             (0x00010000)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ovc_en_mask                                  (0x00001000)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_can_shift_mask                               (0x00000F00)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ffd2_range2l_mask                            (0x000000F0)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ffd2_range2r_mask                            (0x0000000F)
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_d1_cp_shift(data)                            (0xF0000000&((data)<<28))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_dcp_th(data)                                 (0x03F00000&((data)<<20))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_tn_blend_mode(data)                          (0x00020000&((data)<<17))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_tn_blend_en(data)                            (0x00010000&((data)<<16))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ovc_en(data)                                 (0x00001000&((data)<<12))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_can_shift(data)                              (0x00000F00&((data)<<8))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ffd2_range2l(data)                           (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_DLTI_CTRL2_dlti_ffd2_range2r(data)                           (0x0000000F&(data))
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_d1_cp_shift(data)                        ((0xF0000000&(data))>>28)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_dcp_th(data)                             ((0x03F00000&(data))>>20)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_tn_blend_mode(data)                      ((0x00020000&(data))>>17)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_tn_blend_en(data)                        ((0x00010000&(data))>>16)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_ovc_en(data)                             ((0x00001000&(data))>>12)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_can_shift(data)                          ((0x00000F00&(data))>>8)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_ffd2_range2l(data)                       ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_DLTI_CTRL2_get_dlti_ffd2_range2r(data)                       (0x0000000F&(data))

#define  VDPQ_POSTP_DLTI_CTRL3                                                   0x18019E3C
#define  VDPQ_POSTP_DLTI_CTRL3_reg_addr                                          "0xB8019E3C"
#define  VDPQ_POSTP_DLTI_CTRL3_reg                                               0xB8019E3C
#define  VDPQ_POSTP_DLTI_CTRL3_inst_addr                                         "0x00AA"
#define  set_VDPQ_POSTP_DLTI_CTRL3_reg(data)                                     (*((volatile unsigned int*)VDPQ_POSTP_DLTI_CTRL3_reg)=data)
#define  get_VDPQ_POSTP_DLTI_CTRL3_reg                                           (*((volatile unsigned int*)VDPQ_POSTP_DLTI_CTRL3_reg))
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_2_shift                (28)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_1_shift                (24)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_uv_diff_th_2_shift                           (16)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_uv_diff_th_1_shift                           (8)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_len_shift                            (4)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_corr_en_shift                        (0)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_2_mask                 (0xF0000000)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_1_mask                 (0x0F000000)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_uv_diff_th_2_mask                            (0x00FF0000)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_uv_diff_th_1_mask                            (0x0000FF00)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_len_mask                             (0x00000070)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_corr_en_mask                         (0x00000001)
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_2(data)                (0xF0000000&((data)<<28))
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_srcwei_offset_1(data)                (0x0F000000&((data)<<24))
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_uv_diff_th_2(data)                           (0x00FF0000&((data)<<16))
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_uv_diff_th_1(data)                           (0x0000FF00&((data)<<8))
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_len(data)                            (0x00000070&((data)<<4))
#define  VDPQ_POSTP_DLTI_CTRL3_dlti_cchange_corr_en(data)                        (0x00000001&(data))
#define  VDPQ_POSTP_DLTI_CTRL3_get_dlti_cchange_srcwei_offset_2(data)            ((0xF0000000&(data))>>28)
#define  VDPQ_POSTP_DLTI_CTRL3_get_dlti_cchange_srcwei_offset_1(data)            ((0x0F000000&(data))>>24)
#define  VDPQ_POSTP_DLTI_CTRL3_get_dlti_uv_diff_th_2(data)                       ((0x00FF0000&(data))>>16)
#define  VDPQ_POSTP_DLTI_CTRL3_get_dlti_uv_diff_th_1(data)                       ((0x0000FF00&(data))>>8)
#define  VDPQ_POSTP_DLTI_CTRL3_get_dlti_cchange_len(data)                        ((0x00000070&(data))>>4)
#define  VDPQ_POSTP_DLTI_CTRL3_get_dlti_cchange_corr_en(data)                    (0x00000001&(data))

#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1                                        0x18019E40
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg_addr                               "0xB8019E40"
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg                                    0xB8019E40
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_inst_addr                              "0x00AB"
#define  set_VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg(data)                          (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg)=data)
#define  get_VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg                                (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain7_shift                     (28)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain6_shift                     (24)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain5_shift                     (20)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain4_shift                     (16)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain3_shift                     (12)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain2_shift                     (8)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain1_shift                     (4)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain0_shift                     (0)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain7_mask                      (0xF0000000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain6_mask                      (0x0F000000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain5_mask                      (0x00F00000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain4_mask                      (0x000F0000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain3_mask                      (0x0000F000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain2_mask                      (0x00000F00)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain1_mask                      (0x000000F0)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain0_mask                      (0x0000000F)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain7(data)                     (0xF0000000&((data)<<28))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain6(data)                     (0x0F000000&((data)<<24))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain5(data)                     (0x00F00000&((data)<<20))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain4(data)                     (0x000F0000&((data)<<16))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain3(data)                     (0x0000F000&((data)<<12))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain2(data)                     (0x00000F00&((data)<<8))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain1(data)                     (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_dlti_tngain0(data)                     (0x0000000F&(data))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain7(data)                 ((0xF0000000&(data))>>28)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain6(data)                 ((0x0F000000&(data))>>24)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain5(data)                 ((0x00F00000&(data))>>20)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain4(data)                 ((0x000F0000&(data))>>16)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain3(data)                 ((0x0000F000&(data))>>12)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain2(data)                 ((0x00000F00&(data))>>8)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain1(data)                 ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_get_dlti_tngain0(data)                 (0x0000000F&(data))

#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2                                        0x18019E44
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg_addr                               "0xB8019E44"
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg                                    0xB8019E44
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_inst_addr                              "0x00AC"
#define  set_VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg(data)                          (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg)=data)
#define  get_VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg                                (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain14_shift                    (24)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain13_shift                    (20)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain12_shift                    (16)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain11_shift                    (12)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain10_shift                    (8)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain9_shift                     (4)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain8_shift                     (0)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain14_mask                     (0x0F000000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain13_mask                     (0x00F00000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain12_mask                     (0x000F0000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain11_mask                     (0x0000F000)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain10_mask                     (0x00000F00)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain9_mask                      (0x000000F0)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain8_mask                      (0x0000000F)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain14(data)                    (0x0F000000&((data)<<24))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain13(data)                    (0x00F00000&((data)<<20))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain12(data)                    (0x000F0000&((data)<<16))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain11(data)                    (0x0000F000&((data)<<12))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain10(data)                    (0x00000F00&((data)<<8))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain9(data)                     (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_dlti_tngain8(data)                     (0x0000000F&(data))
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain14(data)                ((0x0F000000&(data))>>24)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain13(data)                ((0x00F00000&(data))>>20)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain12(data)                ((0x000F0000&(data))>>16)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain11(data)                ((0x0000F000&(data))>>12)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain10(data)                ((0x00000F00&(data))>>8)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain9(data)                 ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_get_dlti_tngain8(data)                 (0x0000000F&(data))

#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1                                      0x18019E48
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg_addr                             "0xB8019E48"
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg                                  0xB8019E48
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_inst_addr                            "0x00AD"
#define  set_VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg(data)                        (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg)=data)
#define  get_VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg                              (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset7_shift                 (28)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset6_shift                 (24)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset5_shift                 (20)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset4_shift                 (16)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset3_shift                 (12)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset2_shift                 (8)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset1_shift                 (4)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset0_shift                 (0)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset7_mask                  (0xF0000000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset6_mask                  (0x0F000000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset5_mask                  (0x00F00000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset4_mask                  (0x000F0000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset3_mask                  (0x0000F000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset2_mask                  (0x00000F00)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset1_mask                  (0x000000F0)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset0_mask                  (0x0000000F)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset7(data)                 (0xF0000000&((data)<<28))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset6(data)                 (0x0F000000&((data)<<24))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset5(data)                 (0x00F00000&((data)<<20))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset4(data)                 (0x000F0000&((data)<<16))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset3(data)                 (0x0000F000&((data)<<12))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset2(data)                 (0x00000F00&((data)<<8))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset1(data)                 (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_dlti_tnoffset0(data)                 (0x0000000F&(data))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset7(data)             ((0xF0000000&(data))>>28)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset6(data)             ((0x0F000000&(data))>>24)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset5(data)             ((0x00F00000&(data))>>20)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset4(data)             ((0x000F0000&(data))>>16)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset3(data)             ((0x0000F000&(data))>>12)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset2(data)             ((0x00000F00&(data))>>8)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset1(data)             ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_get_dlti_tnoffset0(data)             (0x0000000F&(data))

#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2                                      0x18019E4C
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg_addr                             "0xB8019E4C"
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg                                  0xB8019E4C
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_inst_addr                            "0x00AE"
#define  set_VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg(data)                        (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg)=data)
#define  get_VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg                              (*((volatile unsigned int*)VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset14_shift                (24)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset13_shift                (20)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset12_shift                (16)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset11_shift                (12)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset10_shift                (8)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset9_shift                 (4)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset8_shift                 (0)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset14_mask                 (0x0F000000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset13_mask                 (0x00F00000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset12_mask                 (0x000F0000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset11_mask                 (0x0000F000)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset10_mask                 (0x00000F00)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset9_mask                  (0x000000F0)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset8_mask                  (0x0000000F)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset14(data)                (0x0F000000&((data)<<24))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset13(data)                (0x00F00000&((data)<<20))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset12(data)                (0x000F0000&((data)<<16))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset11(data)                (0x0000F000&((data)<<12))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset10(data)                (0x00000F00&((data)<<8))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset9(data)                 (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_dlti_tnoffset8(data)                 (0x0000000F&(data))
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset14(data)            ((0x0F000000&(data))>>24)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset13(data)            ((0x00F00000&(data))>>20)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset12(data)            ((0x000F0000&(data))>>16)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset11(data)            ((0x0000F000&(data))>>12)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset10(data)            ((0x00000F00&(data))>>8)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset9(data)             ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_get_dlti_tnoffset8(data)             (0x0000000F&(data))

#define  VDPQ_POSTP_DLTI_PK_SELECT                                               0x18019E50
#define  VDPQ_POSTP_DLTI_PK_SELECT_reg_addr                                      "0xB8019E50"
#define  VDPQ_POSTP_DLTI_PK_SELECT_reg                                           0xB8019E50
#define  VDPQ_POSTP_DLTI_PK_SELECT_inst_addr                                     "0x00AF"
#define  set_VDPQ_POSTP_DLTI_PK_SELECT_reg(data)                                 (*((volatile unsigned int*)VDPQ_POSTP_DLTI_PK_SELECT_reg)=data)
#define  get_VDPQ_POSTP_DLTI_PK_SELECT_reg                                       (*((volatile unsigned int*)VDPQ_POSTP_DLTI_PK_SELECT_reg))
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th2_shift                     (16)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th1_shift                     (12)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_diff_th_shift                     (4)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_shift                                  (0)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th2_mask                      (0x00070000)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th1_mask                      (0x00007000)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_diff_th_mask                      (0x00000FF0)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_mask                                   (0x00000007)
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th2(data)                     (0x00070000&((data)<<16))
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_cnt_th1(data)                     (0x00007000&((data)<<12))
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel_dlti_diff_th(data)                     (0x00000FF0&((data)<<4))
#define  VDPQ_POSTP_DLTI_PK_SELECT_pd_sel(data)                                  (0x00000007&(data))
#define  VDPQ_POSTP_DLTI_PK_SELECT_get_pd_sel_dlti_cnt_th2(data)                 ((0x00070000&(data))>>16)
#define  VDPQ_POSTP_DLTI_PK_SELECT_get_pd_sel_dlti_cnt_th1(data)                 ((0x00007000&(data))>>12)
#define  VDPQ_POSTP_DLTI_PK_SELECT_get_pd_sel_dlti_diff_th(data)                 ((0x00000FF0&(data))>>4)
#define  VDPQ_POSTP_DLTI_PK_SELECT_get_pd_sel(data)                              (0x00000007&(data))

#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1                                       0x18019E54
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg_addr                              "0xB8019E54"
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg                                   0xB8019E54
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_inst_addr                             "0x00B0"
#define  set_VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg(data)                         (*((volatile unsigned int*)VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg)=data)
#define  get_VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg                               (*((volatile unsigned int*)VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_2d_weight_shift              (28)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_bld_weight_shift             (26)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_3d_weight_shift              (24)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_2d_weight_shift            (20)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_bld_weight_shift           (18)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_3d_weight_shift            (16)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_2d_weight_shift             (8)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_bld_weight_shift            (4)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_3d_weight_shift             (0)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_2d_weight_mask               (0x30000000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_bld_weight_mask              (0x0C000000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_3d_weight_mask               (0x03000000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_2d_weight_mask             (0x00300000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_bld_weight_mask            (0x000C0000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_3d_weight_mask             (0x00030000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_2d_weight_mask              (0x00000700)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_bld_weight_mask             (0x00000070)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_3d_weight_mask              (0x00000007)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_2d_weight(data)              (0x30000000&((data)<<28))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_bld_weight(data)             (0x0C000000&((data)<<26))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_pk_alpha_3d_weight(data)              (0x03000000&((data)<<24))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_2d_weight(data)            (0x00300000&((data)<<20))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_bld_weight(data)           (0x000C0000&((data)<<18))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_dlti_alpha_3d_weight(data)            (0x00030000&((data)<<16))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_2d_weight(data)             (0x00000700&((data)<<8))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_bld_weight(data)            (0x00000070&((data)<<4))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_xnr_alpha_3d_weight(data)             (0x00000007&(data))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_pk_alpha_2d_weight(data)          ((0x30000000&(data))>>28)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_pk_alpha_bld_weight(data)         ((0x0C000000&(data))>>26)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_pk_alpha_3d_weight(data)          ((0x03000000&(data))>>24)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_dlti_alpha_2d_weight(data)        ((0x00300000&(data))>>20)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_dlti_alpha_bld_weight(data)       ((0x000C0000&(data))>>18)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_dlti_alpha_3d_weight(data)        ((0x00030000&(data))>>16)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_xnr_alpha_2d_weight(data)         ((0x00000700&(data))>>8)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_xnr_alpha_bld_weight(data)        ((0x00000070&(data))>>4)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_get_xnr_alpha_3d_weight(data)         (0x00000007&(data))

#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2                                       0x18019E58
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg_addr                              "0xB8019E58"
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg                                   0xB8019E58
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_inst_addr                             "0x00B1"
#define  set_VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg(data)                         (*((volatile unsigned int*)VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg)=data)
#define  get_VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg                               (*((volatile unsigned int*)VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_alphablend_round_en_shift             (31)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_2d_weight_shift             (24)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_bld_weight_shift            (20)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_3d_weight_shift             (16)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_notch_force_upbnd_shift               (8)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_notch_force_3dweight_shift            (4)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_mfnotch_alpha_2d_weight_shift         (0)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_alphablend_round_en_mask              (0x80000000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_2d_weight_mask              (0x07000000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_bld_weight_mask             (0x00700000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_3d_weight_mask              (0x00070000)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_notch_force_upbnd_mask                (0x0000FF00)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_notch_force_3dweight_mask             (0x000000F0)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_mfnotch_alpha_2d_weight_mask          (0x00000003)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_alphablend_round_en(data)             (0x80000000&((data)<<31))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_2d_weight(data)             (0x07000000&((data)<<24))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_bld_weight(data)            (0x00700000&((data)<<20))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_snr_alpha_3d_weight(data)             (0x00070000&((data)<<16))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_notch_force_upbnd(data)               (0x0000FF00&((data)<<8))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_notch_force_3dweight(data)            (0x000000F0&((data)<<4))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_mfnotch_alpha_2d_weight(data)         (0x00000003&(data))
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_alphablend_round_en(data)         ((0x80000000&(data))>>31)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_snr_alpha_2d_weight(data)         ((0x07000000&(data))>>24)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_snr_alpha_bld_weight(data)        ((0x00700000&(data))>>20)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_snr_alpha_3d_weight(data)         ((0x00070000&(data))>>16)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_notch_force_upbnd(data)           ((0x0000FF00&(data))>>8)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_notch_force_3dweight(data)        ((0x000000F0&(data))>>4)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_get_mfnotch_alpha_2d_weight(data)     (0x00000003&(data))

#define  VDPQ_POSTP_NTSC443_LPF                                                  0x18019E60
#define  VDPQ_POSTP_NTSC443_LPF_reg_addr                                         "0xB8019E60"
#define  VDPQ_POSTP_NTSC443_LPF_reg                                              0xB8019E60
#define  VDPQ_POSTP_NTSC443_LPF_inst_addr                                        "0x00B2"
#define  set_VDPQ_POSTP_NTSC443_LPF_reg(data)                                    (*((volatile unsigned int*)VDPQ_POSTP_NTSC443_LPF_reg)=data)
#define  get_VDPQ_POSTP_NTSC443_LPF_reg                                          (*((volatile unsigned int*)VDPQ_POSTP_NTSC443_LPF_reg))
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_shift                                (31)
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_ext_shift                            (4)
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_th_y_shift                           (0)
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_mask                                 (0x80000000)
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_ext_mask                             (0x00000030)
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_th_y_mask                            (0x00000007)
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf(data)                                (0x80000000&((data)<<31))
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_ext(data)                            (0x00000030&((data)<<4))
#define  VDPQ_POSTP_NTSC443_LPF_ntsc443_lpf_th_y(data)                           (0x00000007&(data))
#define  VDPQ_POSTP_NTSC443_LPF_get_ntsc443_lpf(data)                            ((0x80000000&(data))>>31)
#define  VDPQ_POSTP_NTSC443_LPF_get_ntsc443_lpf_ext(data)                        ((0x00000030&(data))>>4)
#define  VDPQ_POSTP_NTSC443_LPF_get_ntsc443_lpf_th_y(data)                       (0x00000007&(data))

#define  VDPQ_SPNR_DebugMode                                                     0x18019E64
#define  VDPQ_SPNR_DebugMode_reg_addr                                            "0xB8019E64"
#define  VDPQ_SPNR_DebugMode_reg                                                 0xB8019E64
#define  VDPQ_SPNR_DebugMode_inst_addr                                           "0x00B3"
#define  set_VDPQ_SPNR_DebugMode_reg(data)                                       (*((volatile unsigned int*)VDPQ_SPNR_DebugMode_reg)=data)
#define  get_VDPQ_SPNR_DebugMode_reg                                             (*((volatile unsigned int*)VDPQ_SPNR_DebugMode_reg))
#define  VDPQ_SPNR_DebugMode_cp_sweightydebug_shift                              (0)
#define  VDPQ_SPNR_DebugMode_cp_sweightydebug_mask                               (0x00000003)
#define  VDPQ_SPNR_DebugMode_cp_sweightydebug(data)                              (0x00000003&(data))
#define  VDPQ_SPNR_DebugMode_get_cp_sweightydebug(data)                          (0x00000003&(data))

#define  VDPQ_SPNR_CP_Ctrl                                                       0x18019E68
#define  VDPQ_SPNR_CP_Ctrl_reg_addr                                              "0xB8019E68"
#define  VDPQ_SPNR_CP_Ctrl_reg                                                   0xB8019E68
#define  VDPQ_SPNR_CP_Ctrl_inst_addr                                             "0x00B4"
#define  set_VDPQ_SPNR_CP_Ctrl_reg(data)                                         (*((volatile unsigned int*)VDPQ_SPNR_CP_Ctrl_reg)=data)
#define  get_VDPQ_SPNR_CP_Ctrl_reg                                               (*((volatile unsigned int*)VDPQ_SPNR_CP_Ctrl_reg))
#define  VDPQ_SPNR_CP_Ctrl_cp_sresultweight_shift                                (24)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranfiltersizey_shift                             (22)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight2y_shift                                (20)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight3y_shift                                (18)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight4y_shift                                (16)
#define  VDPQ_SPNR_CP_Ctrl_cp_spatialenablec_shift                               (1)
#define  VDPQ_SPNR_CP_Ctrl_cp_spatialenabley_shift                               (0)
#define  VDPQ_SPNR_CP_Ctrl_cp_sresultweight_mask                                 (0x07000000)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranfiltersizey_mask                              (0x00C00000)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight2y_mask                                 (0x00300000)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight3y_mask                                 (0x000C0000)
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight4y_mask                                 (0x00030000)
#define  VDPQ_SPNR_CP_Ctrl_cp_spatialenablec_mask                                (0x00000002)
#define  VDPQ_SPNR_CP_Ctrl_cp_spatialenabley_mask                                (0x00000001)
#define  VDPQ_SPNR_CP_Ctrl_cp_sresultweight(data)                                (0x07000000&((data)<<24))
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranfiltersizey(data)                             (0x00C00000&((data)<<22))
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight2y(data)                                (0x00300000&((data)<<20))
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight3y(data)                                (0x000C0000&((data)<<18))
#define  VDPQ_SPNR_CP_Ctrl_cp_zoranweight4y(data)                                (0x00030000&((data)<<16))
#define  VDPQ_SPNR_CP_Ctrl_cp_spatialenablec(data)                               (0x00000002&((data)<<1))
#define  VDPQ_SPNR_CP_Ctrl_cp_spatialenabley(data)                               (0x00000001&(data))
#define  VDPQ_SPNR_CP_Ctrl_get_cp_sresultweight(data)                            ((0x07000000&(data))>>24)
#define  VDPQ_SPNR_CP_Ctrl_get_cp_zoranfiltersizey(data)                         ((0x00C00000&(data))>>22)
#define  VDPQ_SPNR_CP_Ctrl_get_cp_zoranweight2y(data)                            ((0x00300000&(data))>>20)
#define  VDPQ_SPNR_CP_Ctrl_get_cp_zoranweight3y(data)                            ((0x000C0000&(data))>>18)
#define  VDPQ_SPNR_CP_Ctrl_get_cp_zoranweight4y(data)                            ((0x00030000&(data))>>16)
#define  VDPQ_SPNR_CP_Ctrl_get_cp_spatialenablec(data)                           ((0x00000002&(data))>>1)
#define  VDPQ_SPNR_CP_Ctrl_get_cp_spatialenabley(data)                           (0x00000001&(data))

#define  VDPQ_SPNR_Spatial_Th                                                    0x18019E6C
#define  VDPQ_SPNR_Spatial_Th_reg_addr                                           "0xB8019E6C"
#define  VDPQ_SPNR_Spatial_Th_reg                                                0xB8019E6C
#define  VDPQ_SPNR_Spatial_Th_inst_addr                                          "0x00B5"
#define  set_VDPQ_SPNR_Spatial_Th_reg(data)                                      (*((volatile unsigned int*)VDPQ_SPNR_Spatial_Th_reg)=data)
#define  get_VDPQ_SPNR_Spatial_Th_reg                                            (*((volatile unsigned int*)VDPQ_SPNR_Spatial_Th_reg))
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthlyx4_shift                             (16)
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthlyx2_shift                             (8)
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthly_shift                               (0)
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthlyx4_mask                              (0x00FF0000)
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthlyx2_mask                              (0x0000FF00)
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthly_mask                                (0x000000FF)
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthlyx4(data)                             (0x00FF0000&((data)<<16))
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthlyx2(data)                             (0x0000FF00&((data)<<8))
#define  VDPQ_SPNR_Spatial_Th_cp_spatialthly(data)                               (0x000000FF&(data))
#define  VDPQ_SPNR_Spatial_Th_get_cp_spatialthlyx4(data)                         ((0x00FF0000&(data))>>16)
#define  VDPQ_SPNR_Spatial_Th_get_cp_spatialthlyx2(data)                         ((0x0000FF00&(data))>>8)
#define  VDPQ_SPNR_Spatial_Th_get_cp_spatialthly(data)                           (0x000000FF&(data))

#define  VDPQ_SPNR_Spatial_Weight                                                0x18019E70
#define  VDPQ_SPNR_Spatial_Weight_reg_addr                                       "0xB8019E70"
#define  VDPQ_SPNR_Spatial_Weight_reg                                            0xB8019E70
#define  VDPQ_SPNR_Spatial_Weight_inst_addr                                      "0x00B6"
#define  set_VDPQ_SPNR_Spatial_Weight_reg(data)                                  (*((volatile unsigned int*)VDPQ_SPNR_Spatial_Weight_reg)=data)
#define  get_VDPQ_SPNR_Spatial_Weight_reg                                        (*((volatile unsigned int*)VDPQ_SPNR_Spatial_Weight_reg))
#define  VDPQ_SPNR_Spatial_Weight_cp_ringweighty_shift                           (24)
#define  VDPQ_SPNR_Spatial_Weight_cp_weight1y_shift                              (20)
#define  VDPQ_SPNR_Spatial_Weight_cp_weight2y_shift                              (16)
#define  VDPQ_SPNR_Spatial_Weight_cp_fixedweight1y_shift                         (15)
#define  VDPQ_SPNR_Spatial_Weight_cp_fixedweight2y_shift                         (14)
#define  VDPQ_SPNR_Spatial_Weight_cp_ringrange_shift                             (8)
#define  VDPQ_SPNR_Spatial_Weight_cp_ringgain_shift                              (7)
#define  VDPQ_SPNR_Spatial_Weight_cp_ringweighty_mask                            (0x0F000000)
#define  VDPQ_SPNR_Spatial_Weight_cp_weight1y_mask                               (0x00F00000)
#define  VDPQ_SPNR_Spatial_Weight_cp_weight2y_mask                               (0x000F0000)
#define  VDPQ_SPNR_Spatial_Weight_cp_fixedweight1y_mask                          (0x00008000)
#define  VDPQ_SPNR_Spatial_Weight_cp_fixedweight2y_mask                          (0x00004000)
#define  VDPQ_SPNR_Spatial_Weight_cp_ringrange_mask                              (0x00000100)
#define  VDPQ_SPNR_Spatial_Weight_cp_ringgain_mask                               (0x00000080)
#define  VDPQ_SPNR_Spatial_Weight_cp_ringweighty(data)                           (0x0F000000&((data)<<24))
#define  VDPQ_SPNR_Spatial_Weight_cp_weight1y(data)                              (0x00F00000&((data)<<20))
#define  VDPQ_SPNR_Spatial_Weight_cp_weight2y(data)                              (0x000F0000&((data)<<16))
#define  VDPQ_SPNR_Spatial_Weight_cp_fixedweight1y(data)                         (0x00008000&((data)<<15))
#define  VDPQ_SPNR_Spatial_Weight_cp_fixedweight2y(data)                         (0x00004000&((data)<<14))
#define  VDPQ_SPNR_Spatial_Weight_cp_ringrange(data)                             (0x00000100&((data)<<8))
#define  VDPQ_SPNR_Spatial_Weight_cp_ringgain(data)                              (0x00000080&((data)<<7))
#define  VDPQ_SPNR_Spatial_Weight_get_cp_ringweighty(data)                       ((0x0F000000&(data))>>24)
#define  VDPQ_SPNR_Spatial_Weight_get_cp_weight1y(data)                          ((0x00F00000&(data))>>20)
#define  VDPQ_SPNR_Spatial_Weight_get_cp_weight2y(data)                          ((0x000F0000&(data))>>16)
#define  VDPQ_SPNR_Spatial_Weight_get_cp_fixedweight1y(data)                     ((0x00008000&(data))>>15)
#define  VDPQ_SPNR_Spatial_Weight_get_cp_fixedweight2y(data)                     ((0x00004000&(data))>>14)
#define  VDPQ_SPNR_Spatial_Weight_get_cp_ringrange(data)                         ((0x00000100&(data))>>8)
#define  VDPQ_SPNR_Spatial_Weight_get_cp_ringgain(data)                          ((0x00000080&(data))>>7)

#define  VDPQ_Dummy_Status                                                       0x18019E74
#define  VDPQ_Dummy_Status_reg_addr                                              "0xB8019E74"
#define  VDPQ_Dummy_Status_reg                                                   0xB8019E74
#define  VDPQ_Dummy_Status_inst_addr                                             "0x00B7"
#define  set_VDPQ_Dummy_Status_reg(data)                                         (*((volatile unsigned int*)VDPQ_Dummy_Status_reg)=data)
#define  get_VDPQ_Dummy_Status_reg                                               (*((volatile unsigned int*)VDPQ_Dummy_Status_reg))
#define  VDPQ_Dummy_Status_dummy_status_shift                                    (0)
#define  VDPQ_Dummy_Status_dummy_status_mask                                     (0xFFFFFFFF)
#define  VDPQ_Dummy_Status_dummy_status(data)                                    (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_Status_get_dummy_status(data)                                (0xFFFFFFFF&(data))

#define  VDPQ_SPNR_Local_Var2                                                    0x18019E78
#define  VDPQ_SPNR_Local_Var2_reg_addr                                           "0xB8019E78"
#define  VDPQ_SPNR_Local_Var2_reg                                                0xB8019E78
#define  VDPQ_SPNR_Local_Var2_inst_addr                                          "0x00B8"
#define  set_VDPQ_SPNR_Local_Var2_reg(data)                                      (*((volatile unsigned int*)VDPQ_SPNR_Local_Var2_reg)=data)
#define  get_VDPQ_SPNR_Local_Var2_reg                                            (*((volatile unsigned int*)VDPQ_SPNR_Local_Var2_reg))
#define  VDPQ_SPNR_Local_Var2_cp_sw_edge_thl_shift                               (16)
#define  VDPQ_SPNR_Local_Var2_cp_edge_weight_shift                               (0)
#define  VDPQ_SPNR_Local_Var2_cp_sw_edge_thl_mask                                (0xFFFF0000)
#define  VDPQ_SPNR_Local_Var2_cp_edge_weight_mask                                (0x00000003)
#define  VDPQ_SPNR_Local_Var2_cp_sw_edge_thl(data)                               (0xFFFF0000&((data)<<16))
#define  VDPQ_SPNR_Local_Var2_cp_edge_weight(data)                               (0x00000003&(data))
#define  VDPQ_SPNR_Local_Var2_get_cp_sw_edge_thl(data)                           ((0xFFFF0000&(data))>>16)
#define  VDPQ_SPNR_Local_Var2_get_cp_edge_weight(data)                           (0x00000003&(data))

#define  VDPQ_NOTCH_CTRL_1                                                       0x18019E7C
#define  VDPQ_NOTCH_CTRL_1_reg_addr                                              "0xB8019E7C"
#define  VDPQ_NOTCH_CTRL_1_reg                                                   0xB8019E7C
#define  VDPQ_NOTCH_CTRL_1_inst_addr                                             "0x00B9"
#define  set_VDPQ_NOTCH_CTRL_1_reg(data)                                         (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_1_reg)=data)
#define  get_VDPQ_NOTCH_CTRL_1_reg                                               (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_1_reg))
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_offset_shift                              (20)
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_weight_shift                              (12)
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_upbnd_shift                               (4)
#define  VDPQ_NOTCH_CTRL_1_notch_en_shift                                        (0)
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_offset_mask                               (0x03F00000)
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_weight_mask                               (0x0001F000)
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_upbnd_mask                                (0x00000FF0)
#define  VDPQ_NOTCH_CTRL_1_notch_en_mask                                         (0x00000001)
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_offset(data)                              (0x03F00000&((data)<<20))
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_weight(data)                              (0x0001F000&((data)<<12))
#define  VDPQ_NOTCH_CTRL_1_notch_upbnd_upbnd(data)                               (0x00000FF0&((data)<<4))
#define  VDPQ_NOTCH_CTRL_1_notch_en(data)                                        (0x00000001&(data))
#define  VDPQ_NOTCH_CTRL_1_get_notch_upbnd_offset(data)                          ((0x03F00000&(data))>>20)
#define  VDPQ_NOTCH_CTRL_1_get_notch_upbnd_weight(data)                          ((0x0001F000&(data))>>12)
#define  VDPQ_NOTCH_CTRL_1_get_notch_upbnd_upbnd(data)                           ((0x00000FF0&(data))>>4)
#define  VDPQ_NOTCH_CTRL_1_get_notch_en(data)                                    (0x00000001&(data))

#define  VDPQ_NOTCH_CTRL_2                                                       0x18019E80
#define  VDPQ_NOTCH_CTRL_2_reg_addr                                              "0xB8019E80"
#define  VDPQ_NOTCH_CTRL_2_reg                                                   0xB8019E80
#define  VDPQ_NOTCH_CTRL_2_inst_addr                                             "0x00BA"
#define  set_VDPQ_NOTCH_CTRL_2_reg(data)                                         (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_2_reg)=data)
#define  get_VDPQ_NOTCH_CTRL_2_reg                                               (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_2_reg))
#define  VDPQ_NOTCH_CTRL_2_large_notchy_amp_th_shift                             (24)
#define  VDPQ_NOTCH_CTRL_2_high_sat_weight_undo_shift                            (20)
#define  VDPQ_NOTCH_CTRL_2_high_sat_weight_do_shift                              (16)
#define  VDPQ_NOTCH_CTRL_2_high_sat_lowbnd_shift                                 (8)
#define  VDPQ_NOTCH_CTRL_2_notch_lowbnd_shift                                    (0)
#define  VDPQ_NOTCH_CTRL_2_large_notchy_amp_th_mask                              (0x3F000000)
#define  VDPQ_NOTCH_CTRL_2_high_sat_weight_undo_mask                             (0x00F00000)
#define  VDPQ_NOTCH_CTRL_2_high_sat_weight_do_mask                               (0x000F0000)
#define  VDPQ_NOTCH_CTRL_2_high_sat_lowbnd_mask                                  (0x00003F00)
#define  VDPQ_NOTCH_CTRL_2_notch_lowbnd_mask                                     (0x0000001F)
#define  VDPQ_NOTCH_CTRL_2_large_notchy_amp_th(data)                             (0x3F000000&((data)<<24))
#define  VDPQ_NOTCH_CTRL_2_high_sat_weight_undo(data)                            (0x00F00000&((data)<<20))
#define  VDPQ_NOTCH_CTRL_2_high_sat_weight_do(data)                              (0x000F0000&((data)<<16))
#define  VDPQ_NOTCH_CTRL_2_high_sat_lowbnd(data)                                 (0x00003F00&((data)<<8))
#define  VDPQ_NOTCH_CTRL_2_notch_lowbnd(data)                                    (0x0000001F&(data))
#define  VDPQ_NOTCH_CTRL_2_get_large_notchy_amp_th(data)                         ((0x3F000000&(data))>>24)
#define  VDPQ_NOTCH_CTRL_2_get_high_sat_weight_undo(data)                        ((0x00F00000&(data))>>20)
#define  VDPQ_NOTCH_CTRL_2_get_high_sat_weight_do(data)                          ((0x000F0000&(data))>>16)
#define  VDPQ_NOTCH_CTRL_2_get_high_sat_lowbnd(data)                             ((0x00003F00&(data))>>8)
#define  VDPQ_NOTCH_CTRL_2_get_notch_lowbnd(data)                                (0x0000001F&(data))

#define  VDPQ_NOTCH_CTRL_3                                                       0x18019E84
#define  VDPQ_NOTCH_CTRL_3_reg_addr                                              "0xB8019E84"
#define  VDPQ_NOTCH_CTRL_3_reg                                                   0xB8019E84
#define  VDPQ_NOTCH_CTRL_3_inst_addr                                             "0x00BB"
#define  set_VDPQ_NOTCH_CTRL_3_reg(data)                                         (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_3_reg)=data)
#define  get_VDPQ_NOTCH_CTRL_3_reg                                               (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_3_reg))
#define  VDPQ_NOTCH_CTRL_3_very_nonmonotone_weight_undo_shift                    (28)
#define  VDPQ_NOTCH_CTRL_3_very_nonmonotone_weight_do_shift                      (24)
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_weight_undo_shift                     (20)
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_weight_do_shift                       (16)
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_th_shift                              (8)
#define  VDPQ_NOTCH_CTRL_3_large_notchy_amp_weight_undo_shift                    (4)
#define  VDPQ_NOTCH_CTRL_3_large_notchy_amp_weight_do_shift                      (0)
#define  VDPQ_NOTCH_CTRL_3_very_nonmonotone_weight_undo_mask                     (0xF0000000)
#define  VDPQ_NOTCH_CTRL_3_very_nonmonotone_weight_do_mask                       (0x0F000000)
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_weight_undo_mask                      (0x00F00000)
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_weight_do_mask                        (0x000F0000)
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_th_mask                               (0x00003F00)
#define  VDPQ_NOTCH_CTRL_3_large_notchy_amp_weight_undo_mask                     (0x000000F0)
#define  VDPQ_NOTCH_CTRL_3_large_notchy_amp_weight_do_mask                       (0x0000000F)
#define  VDPQ_NOTCH_CTRL_3_very_nonmonotone_weight_undo(data)                    (0xF0000000&((data)<<28))
#define  VDPQ_NOTCH_CTRL_3_very_nonmonotone_weight_do(data)                      (0x0F000000&((data)<<24))
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_weight_undo(data)                     (0x00F00000&((data)<<20))
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_weight_do(data)                       (0x000F0000&((data)<<16))
#define  VDPQ_NOTCH_CTRL_3_very_diff_large_th(data)                              (0x00003F00&((data)<<8))
#define  VDPQ_NOTCH_CTRL_3_large_notchy_amp_weight_undo(data)                    (0x000000F0&((data)<<4))
#define  VDPQ_NOTCH_CTRL_3_large_notchy_amp_weight_do(data)                      (0x0000000F&(data))
#define  VDPQ_NOTCH_CTRL_3_get_very_nonmonotone_weight_undo(data)                ((0xF0000000&(data))>>28)
#define  VDPQ_NOTCH_CTRL_3_get_very_nonmonotone_weight_do(data)                  ((0x0F000000&(data))>>24)
#define  VDPQ_NOTCH_CTRL_3_get_very_diff_large_weight_undo(data)                 ((0x00F00000&(data))>>20)
#define  VDPQ_NOTCH_CTRL_3_get_very_diff_large_weight_do(data)                   ((0x000F0000&(data))>>16)
#define  VDPQ_NOTCH_CTRL_3_get_very_diff_large_th(data)                          ((0x00003F00&(data))>>8)
#define  VDPQ_NOTCH_CTRL_3_get_large_notchy_amp_weight_undo(data)                ((0x000000F0&(data))>>4)
#define  VDPQ_NOTCH_CTRL_3_get_large_notchy_amp_weight_do(data)                  (0x0000000F&(data))

#define  VDPQ_NOTCH_CTRL_4                                                       0x18019E88
#define  VDPQ_NOTCH_CTRL_4_reg_addr                                              "0xB8019E88"
#define  VDPQ_NOTCH_CTRL_4_reg                                                   0xB8019E88
#define  VDPQ_NOTCH_CTRL_4_inst_addr                                             "0x00BC"
#define  set_VDPQ_NOTCH_CTRL_4_reg(data)                                         (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_4_reg)=data)
#define  get_VDPQ_NOTCH_CTRL_4_reg                                               (*((volatile unsigned int*)VDPQ_NOTCH_CTRL_4_reg))
#define  VDPQ_NOTCH_CTRL_4_force_notch_weight_shift                              (20)
#define  VDPQ_NOTCH_CTRL_4_vline_weight_undo_shift                               (16)
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_weight_undo_shift                         (12)
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_weight_do_shift                           (8)
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_th_shift                                  (0)
#define  VDPQ_NOTCH_CTRL_4_force_notch_weight_mask                               (0x00F00000)
#define  VDPQ_NOTCH_CTRL_4_vline_weight_undo_mask                                (0x000F0000)
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_weight_undo_mask                          (0x0000F000)
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_weight_do_mask                            (0x00000F00)
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_th_mask                                   (0x000000FF)
#define  VDPQ_NOTCH_CTRL_4_force_notch_weight(data)                              (0x00F00000&((data)<<20))
#define  VDPQ_NOTCH_CTRL_4_vline_weight_undo(data)                               (0x000F0000&((data)<<16))
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_weight_undo(data)                         (0x0000F000&((data)<<12))
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_weight_do(data)                           (0x00000F00&((data)<<8))
#define  VDPQ_NOTCH_CTRL_4_large_cdiff_th(data)                                  (0x000000FF&(data))
#define  VDPQ_NOTCH_CTRL_4_get_force_notch_weight(data)                          ((0x00F00000&(data))>>20)
#define  VDPQ_NOTCH_CTRL_4_get_vline_weight_undo(data)                           ((0x000F0000&(data))>>16)
#define  VDPQ_NOTCH_CTRL_4_get_large_cdiff_weight_undo(data)                     ((0x0000F000&(data))>>12)
#define  VDPQ_NOTCH_CTRL_4_get_large_cdiff_weight_do(data)                       ((0x00000F00&(data))>>8)
#define  VDPQ_NOTCH_CTRL_4_get_large_cdiff_th(data)                              (0x000000FF&(data))

#define  VDPQ_ALPHA_BLENDING_CTRL0                                               0x18019EE8
#define  VDPQ_ALPHA_BLENDING_CTRL0_reg_addr                                      "0xB8019EE8"
#define  VDPQ_ALPHA_BLENDING_CTRL0_reg                                           0xB8019EE8
#define  VDPQ_ALPHA_BLENDING_CTRL0_inst_addr                                     "0x00BD"
#define  set_VDPQ_ALPHA_BLENDING_CTRL0_reg(data)                                 (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL0_reg)=data)
#define  get_VDPQ_ALPHA_BLENDING_CTRL0_reg                                       (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL0_reg))
#define  VDPQ_ALPHA_BLENDING_CTRL0_alpha2d3d_bld_weight_0_shift                  (24)
#define  VDPQ_ALPHA_BLENDING_CTRL0_alpha2d3d_bld_weight_0_mask                   (0x1F000000)
#define  VDPQ_ALPHA_BLENDING_CTRL0_alpha2d3d_bld_weight_0(data)                  (0x1F000000&((data)<<24))
#define  VDPQ_ALPHA_BLENDING_CTRL0_get_alpha2d3d_bld_weight_0(data)              ((0x1F000000&(data))>>24)

#define  VDPQ_ALPHA_BLENDING_CTRL1                                               0x18019EEC
#define  VDPQ_ALPHA_BLENDING_CTRL1_reg_addr                                      "0xB8019EEC"
#define  VDPQ_ALPHA_BLENDING_CTRL1_reg                                           0xB8019EEC
#define  VDPQ_ALPHA_BLENDING_CTRL1_inst_addr                                     "0x00BE"
#define  set_VDPQ_ALPHA_BLENDING_CTRL1_reg(data)                                 (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL1_reg)=data)
#define  get_VDPQ_ALPHA_BLENDING_CTRL1_reg                                       (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL1_reg))
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_1_shift                  (24)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_2_shift                  (16)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_3_shift                  (8)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_4_shift                  (0)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_1_mask                   (0x1F000000)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_2_mask                   (0x001F0000)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_3_mask                   (0x00001F00)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_4_mask                   (0x0000001F)
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_1(data)                  (0x1F000000&((data)<<24))
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_2(data)                  (0x001F0000&((data)<<16))
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_3(data)                  (0x00001F00&((data)<<8))
#define  VDPQ_ALPHA_BLENDING_CTRL1_alpha2d3d_bld_weight_4(data)                  (0x0000001F&(data))
#define  VDPQ_ALPHA_BLENDING_CTRL1_get_alpha2d3d_bld_weight_1(data)              ((0x1F000000&(data))>>24)
#define  VDPQ_ALPHA_BLENDING_CTRL1_get_alpha2d3d_bld_weight_2(data)              ((0x001F0000&(data))>>16)
#define  VDPQ_ALPHA_BLENDING_CTRL1_get_alpha2d3d_bld_weight_3(data)              ((0x00001F00&(data))>>8)
#define  VDPQ_ALPHA_BLENDING_CTRL1_get_alpha2d3d_bld_weight_4(data)              (0x0000001F&(data))

#define  VDPQ_ALPHA_BLENDING_CTRL2                                               0x18019EF0
#define  VDPQ_ALPHA_BLENDING_CTRL2_reg_addr                                      "0xB8019EF0"
#define  VDPQ_ALPHA_BLENDING_CTRL2_reg                                           0xB8019EF0
#define  VDPQ_ALPHA_BLENDING_CTRL2_inst_addr                                     "0x00BF"
#define  set_VDPQ_ALPHA_BLENDING_CTRL2_reg(data)                                 (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL2_reg)=data)
#define  get_VDPQ_ALPHA_BLENDING_CTRL2_reg                                       (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL2_reg))
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_5_shift                  (24)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_6_shift                  (16)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_7_shift                  (8)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_8_shift                  (0)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_5_mask                   (0x1F000000)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_6_mask                   (0x001F0000)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_7_mask                   (0x00001F00)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_8_mask                   (0x0000001F)
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_5(data)                  (0x1F000000&((data)<<24))
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_6(data)                  (0x001F0000&((data)<<16))
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_7(data)                  (0x00001F00&((data)<<8))
#define  VDPQ_ALPHA_BLENDING_CTRL2_alpha2d3d_bld_weight_8(data)                  (0x0000001F&(data))
#define  VDPQ_ALPHA_BLENDING_CTRL2_get_alpha2d3d_bld_weight_5(data)              ((0x1F000000&(data))>>24)
#define  VDPQ_ALPHA_BLENDING_CTRL2_get_alpha2d3d_bld_weight_6(data)              ((0x001F0000&(data))>>16)
#define  VDPQ_ALPHA_BLENDING_CTRL2_get_alpha2d3d_bld_weight_7(data)              ((0x00001F00&(data))>>8)
#define  VDPQ_ALPHA_BLENDING_CTRL2_get_alpha2d3d_bld_weight_8(data)              (0x0000001F&(data))

#define  VDPQ_ALPHA_BLENDING_CTRL3                                               0x18019EF4
#define  VDPQ_ALPHA_BLENDING_CTRL3_reg_addr                                      "0xB8019EF4"
#define  VDPQ_ALPHA_BLENDING_CTRL3_reg                                           0xB8019EF4
#define  VDPQ_ALPHA_BLENDING_CTRL3_inst_addr                                     "0x00C0"
#define  set_VDPQ_ALPHA_BLENDING_CTRL3_reg(data)                                 (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL3_reg)=data)
#define  get_VDPQ_ALPHA_BLENDING_CTRL3_reg                                       (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL3_reg))
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_9_shift                  (24)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_10_shift                 (16)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_11_shift                 (8)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_12_shift                 (0)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_9_mask                   (0x1F000000)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_10_mask                  (0x001F0000)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_11_mask                  (0x00001F00)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_12_mask                  (0x0000001F)
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_9(data)                  (0x1F000000&((data)<<24))
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_10(data)                 (0x001F0000&((data)<<16))
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_11(data)                 (0x00001F00&((data)<<8))
#define  VDPQ_ALPHA_BLENDING_CTRL3_alpha2d3d_bld_weight_12(data)                 (0x0000001F&(data))
#define  VDPQ_ALPHA_BLENDING_CTRL3_get_alpha2d3d_bld_weight_9(data)              ((0x1F000000&(data))>>24)
#define  VDPQ_ALPHA_BLENDING_CTRL3_get_alpha2d3d_bld_weight_10(data)             ((0x001F0000&(data))>>16)
#define  VDPQ_ALPHA_BLENDING_CTRL3_get_alpha2d3d_bld_weight_11(data)             ((0x00001F00&(data))>>8)
#define  VDPQ_ALPHA_BLENDING_CTRL3_get_alpha2d3d_bld_weight_12(data)             (0x0000001F&(data))

#define  VDPQ_ALPHA_BLENDING_CTRL4                                               0x18019EF8
#define  VDPQ_ALPHA_BLENDING_CTRL4_reg_addr                                      "0xB8019EF8"
#define  VDPQ_ALPHA_BLENDING_CTRL4_reg                                           0xB8019EF8
#define  VDPQ_ALPHA_BLENDING_CTRL4_inst_addr                                     "0x00C1"
#define  set_VDPQ_ALPHA_BLENDING_CTRL4_reg(data)                                 (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL4_reg)=data)
#define  get_VDPQ_ALPHA_BLENDING_CTRL4_reg                                       (*((volatile unsigned int*)VDPQ_ALPHA_BLENDING_CTRL4_reg))
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_13_shift                 (24)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_14_shift                 (16)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_15_shift                 (8)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_16_shift                 (0)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_13_mask                  (0x1F000000)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_14_mask                  (0x001F0000)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_15_mask                  (0x00001F00)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_16_mask                  (0x0000001F)
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_13(data)                 (0x1F000000&((data)<<24))
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_14(data)                 (0x001F0000&((data)<<16))
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_15(data)                 (0x00001F00&((data)<<8))
#define  VDPQ_ALPHA_BLENDING_CTRL4_alpha2d3d_bld_weight_16(data)                 (0x0000001F&(data))
#define  VDPQ_ALPHA_BLENDING_CTRL4_get_alpha2d3d_bld_weight_13(data)             ((0x1F000000&(data))>>24)
#define  VDPQ_ALPHA_BLENDING_CTRL4_get_alpha2d3d_bld_weight_14(data)             ((0x001F0000&(data))>>16)
#define  VDPQ_ALPHA_BLENDING_CTRL4_get_alpha2d3d_bld_weight_15(data)             ((0x00001F00&(data))>>8)
#define  VDPQ_ALPHA_BLENDING_CTRL4_get_alpha2d3d_bld_weight_16(data)             (0x0000001F&(data))

#define  VDPQ_ALPHA_TEMPORAL_SMOOTH                                              0x18019EFC
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_reg_addr                                     "0xB8019EFC"
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_reg                                          0xB8019EFC
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_inst_addr                                    "0x00C2"
#define  set_VDPQ_ALPHA_TEMPORAL_SMOOTH_reg(data)                                (*((volatile unsigned int*)VDPQ_ALPHA_TEMPORAL_SMOOTH_reg)=data)
#define  get_VDPQ_ALPHA_TEMPORAL_SMOOTH_reg                                      (*((volatile unsigned int*)VDPQ_ALPHA_TEMPORAL_SMOOTH_reg))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_enable_shift                              (31)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_iir_reset_clear_shift                        (30)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_iir_reset_value_shift                        (12)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_multiple_shift                            (8)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_alpha_gain_shift                          (4)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_alpha_offset_shift                        (0)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_enable_mask                               (0x80000000)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_iir_reset_clear_mask                         (0x40000000)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_iir_reset_value_mask                         (0x000FF000)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_multiple_mask                             (0x00000F00)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_alpha_gain_mask                           (0x000000F0)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_alpha_offset_mask                         (0x0000000F)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_enable(data)                              (0x80000000&((data)<<31))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_iir_reset_clear(data)                        (0x40000000&((data)<<30))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_iir_reset_value(data)                        (0x000FF000&((data)<<12))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_multiple(data)                            (0x00000F00&((data)<<8))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_alpha_gain(data)                          (0x000000F0&((data)<<4))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_ts_alpha_offset(data)                        (0x0000000F&(data))
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_get_ts_enable(data)                          ((0x80000000&(data))>>31)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_get_iir_reset_clear(data)                    ((0x40000000&(data))>>30)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_get_iir_reset_value(data)                    ((0x000FF000&(data))>>12)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_get_ts_multiple(data)                        ((0x00000F00&(data))>>8)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_get_ts_alpha_gain(data)                      ((0x000000F0&(data))>>4)
#define  VDPQ_ALPHA_TEMPORAL_SMOOTH_get_ts_alpha_offset(data)                    (0x0000000F&(data))

#define  VDPQ_DE_XC_CTRL                                                         0x18019F00
#define  VDPQ_DE_XC_CTRL_reg_addr                                                "0xB8019F00"
#define  VDPQ_DE_XC_CTRL_reg                                                     0xB8019F00
#define  VDPQ_DE_XC_CTRL_inst_addr                                               "0x00C3"
#define  set_VDPQ_DE_XC_CTRL_reg(data)                                           (*((volatile unsigned int*)VDPQ_DE_XC_CTRL_reg)=data)
#define  get_VDPQ_DE_XC_CTRL_reg                                                 (*((volatile unsigned int*)VDPQ_DE_XC_CTRL_reg))
#define  VDPQ_DE_XC_CTRL_postpq_alphablend_dbm_shift                             (31)
#define  VDPQ_DE_XC_CTRL_xc_blend_en_shift                                       (5)
#define  VDPQ_DE_XC_CTRL_de_xc_en_shift                                          (4)
#define  VDPQ_DE_XC_CTRL_de_xc_thr_shift                                         (0)
#define  VDPQ_DE_XC_CTRL_postpq_alphablend_dbm_mask                              (0x80000000)
#define  VDPQ_DE_XC_CTRL_xc_blend_en_mask                                        (0x00000020)
#define  VDPQ_DE_XC_CTRL_de_xc_en_mask                                           (0x00000010)
#define  VDPQ_DE_XC_CTRL_de_xc_thr_mask                                          (0x0000000F)
#define  VDPQ_DE_XC_CTRL_postpq_alphablend_dbm(data)                             (0x80000000&((data)<<31))
#define  VDPQ_DE_XC_CTRL_xc_blend_en(data)                                       (0x00000020&((data)<<5))
#define  VDPQ_DE_XC_CTRL_de_xc_en(data)                                          (0x00000010&((data)<<4))
#define  VDPQ_DE_XC_CTRL_de_xc_thr(data)                                         (0x0000000F&(data))
#define  VDPQ_DE_XC_CTRL_get_postpq_alphablend_dbm(data)                         ((0x80000000&(data))>>31)
#define  VDPQ_DE_XC_CTRL_get_xc_blend_en(data)                                   ((0x00000020&(data))>>5)
#define  VDPQ_DE_XC_CTRL_get_de_xc_en(data)                                      ((0x00000010&(data))>>4)
#define  VDPQ_DE_XC_CTRL_get_de_xc_thr(data)                                     (0x0000000F&(data))

#define  VDPQ_CNR_CTRL                                                           0x18019F04
#define  VDPQ_CNR_CTRL_reg_addr                                                  "0xB8019F04"
#define  VDPQ_CNR_CTRL_reg                                                       0xB8019F04
#define  VDPQ_CNR_CTRL_inst_addr                                                 "0x00C4"
#define  set_VDPQ_CNR_CTRL_reg(data)                                             (*((volatile unsigned int*)VDPQ_CNR_CTRL_reg)=data)
#define  get_VDPQ_CNR_CTRL_reg                                                   (*((volatile unsigned int*)VDPQ_CNR_CTRL_reg))
#define  VDPQ_CNR_CTRL_cnr_lpf_sel_shift                                         (2)
#define  VDPQ_CNR_CTRL_cnr_en_shift                                              (0)
#define  VDPQ_CNR_CTRL_cnr_lpf_sel_mask                                          (0x0000000C)
#define  VDPQ_CNR_CTRL_cnr_en_mask                                               (0x00000001)
#define  VDPQ_CNR_CTRL_cnr_lpf_sel(data)                                         (0x0000000C&((data)<<2))
#define  VDPQ_CNR_CTRL_cnr_en(data)                                              (0x00000001&(data))
#define  VDPQ_CNR_CTRL_get_cnr_lpf_sel(data)                                     ((0x0000000C&(data))>>2)
#define  VDPQ_CNR_CTRL_get_cnr_en(data)                                          (0x00000001&(data))

#define  VDPQ_CADAP_ENABLE_CTRL                                                  0x18019F0C
#define  VDPQ_CADAP_ENABLE_CTRL_reg_addr                                         "0xB8019F0C"
#define  VDPQ_CADAP_ENABLE_CTRL_reg                                              0xB8019F0C
#define  VDPQ_CADAP_ENABLE_CTRL_inst_addr                                        "0x00C5"
#define  set_VDPQ_CADAP_ENABLE_CTRL_reg(data)                                    (*((volatile unsigned int*)VDPQ_CADAP_ENABLE_CTRL_reg)=data)
#define  get_VDPQ_CADAP_ENABLE_CTRL_reg                                          (*((volatile unsigned int*)VDPQ_CADAP_ENABLE_CTRL_reg))
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_spatial_lpf_out_shift                      (5)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_clpf_en_shift                              (4)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_ylpf_en_shift                              (3)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_uvsync_en_shift                            (2)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_yuvsync_en_shift                           (1)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_cti_en_shift                               (0)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_spatial_lpf_out_mask                       (0x00000020)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_clpf_en_mask                               (0x00000010)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_ylpf_en_mask                               (0x00000008)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_uvsync_en_mask                             (0x00000004)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_yuvsync_en_mask                            (0x00000002)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_cti_en_mask                                (0x00000001)
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_spatial_lpf_out(data)                      (0x00000020&((data)<<5))
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_clpf_en(data)                              (0x00000010&((data)<<4))
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_ylpf_en(data)                              (0x00000008&((data)<<3))
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_uvsync_en(data)                            (0x00000004&((data)<<2))
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_yuvsync_en(data)                           (0x00000002&((data)<<1))
#define  VDPQ_CADAP_ENABLE_CTRL_cadap_cti_en(data)                               (0x00000001&(data))
#define  VDPQ_CADAP_ENABLE_CTRL_get_cadap_spatial_lpf_out(data)                  ((0x00000020&(data))>>5)
#define  VDPQ_CADAP_ENABLE_CTRL_get_cadap_clpf_en(data)                          ((0x00000010&(data))>>4)
#define  VDPQ_CADAP_ENABLE_CTRL_get_cadap_ylpf_en(data)                          ((0x00000008&(data))>>3)
#define  VDPQ_CADAP_ENABLE_CTRL_get_cadap_uvsync_en(data)                        ((0x00000004&(data))>>2)
#define  VDPQ_CADAP_ENABLE_CTRL_get_cadap_yuvsync_en(data)                       ((0x00000002&(data))>>1)
#define  VDPQ_CADAP_ENABLE_CTRL_get_cadap_cti_en(data)                           (0x00000001&(data))

#define  VDPQ_CADAP_ENABLE_CTRL2                                                 0x18019F10
#define  VDPQ_CADAP_ENABLE_CTRL2_reg_addr                                        "0xB8019F10"
#define  VDPQ_CADAP_ENABLE_CTRL2_reg                                             0xB8019F10
#define  VDPQ_CADAP_ENABLE_CTRL2_inst_addr                                       "0x00C6"
#define  set_VDPQ_CADAP_ENABLE_CTRL2_reg(data)                                   (*((volatile unsigned int*)VDPQ_CADAP_ENABLE_CTRL2_reg)=data)
#define  get_VDPQ_CADAP_ENABLE_CTRL2_reg                                         (*((volatile unsigned int*)VDPQ_CADAP_ENABLE_CTRL2_reg))
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_uni_gain_ctrl_en_shift                    (2)
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_uv_sync_uni_en_shift                      (1)
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_y_sync_uni_en_shift                       (0)
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_uni_gain_ctrl_en_mask                     (0x00000004)
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_uv_sync_uni_en_mask                       (0x00000002)
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_y_sync_uni_en_mask                        (0x00000001)
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_uni_gain_ctrl_en(data)                    (0x00000004&((data)<<2))
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_uv_sync_uni_en(data)                      (0x00000002&((data)<<1))
#define  VDPQ_CADAP_ENABLE_CTRL2_cadap_y_sync_uni_en(data)                       (0x00000001&(data))
#define  VDPQ_CADAP_ENABLE_CTRL2_get_cadap_uni_gain_ctrl_en(data)                ((0x00000004&(data))>>2)
#define  VDPQ_CADAP_ENABLE_CTRL2_get_cadap_uv_sync_uni_en(data)                  ((0x00000002&(data))>>1)
#define  VDPQ_CADAP_ENABLE_CTRL2_get_cadap_y_sync_uni_en(data)                   (0x00000001&(data))

#define  VDPQ_CADAP_GAIN_CTRL                                                    0x18019F14
#define  VDPQ_CADAP_GAIN_CTRL_reg_addr                                           "0xB8019F14"
#define  VDPQ_CADAP_GAIN_CTRL_reg                                                0xB8019F14
#define  VDPQ_CADAP_GAIN_CTRL_inst_addr                                          "0x00C7"
#define  set_VDPQ_CADAP_GAIN_CTRL_reg(data)                                      (*((volatile unsigned int*)VDPQ_CADAP_GAIN_CTRL_reg)=data)
#define  get_VDPQ_CADAP_GAIN_CTRL_reg                                            (*((volatile unsigned int*)VDPQ_CADAP_GAIN_CTRL_reg))
#define  VDPQ_CADAP_GAIN_CTRL_cadap_gain_shift                                   (4)
#define  VDPQ_CADAP_GAIN_CTRL_cadap_level_shift                                  (0)
#define  VDPQ_CADAP_GAIN_CTRL_cadap_gain_mask                                    (0x000000F0)
#define  VDPQ_CADAP_GAIN_CTRL_cadap_level_mask                                   (0x0000000F)
#define  VDPQ_CADAP_GAIN_CTRL_cadap_gain(data)                                   (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_GAIN_CTRL_cadap_level(data)                                  (0x0000000F&(data))
#define  VDPQ_CADAP_GAIN_CTRL_get_cadap_gain(data)                               ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_GAIN_CTRL_get_cadap_level(data)                              (0x0000000F&(data))

#define  VDPQ_CADAP_ZC_TH                                                        0x18019F18
#define  VDPQ_CADAP_ZC_TH_reg_addr                                               "0xB8019F18"
#define  VDPQ_CADAP_ZC_TH_reg                                                    0xB8019F18
#define  VDPQ_CADAP_ZC_TH_inst_addr                                              "0x00C8"
#define  set_VDPQ_CADAP_ZC_TH_reg(data)                                          (*((volatile unsigned int*)VDPQ_CADAP_ZC_TH_reg)=data)
#define  get_VDPQ_CADAP_ZC_TH_reg                                                (*((volatile unsigned int*)VDPQ_CADAP_ZC_TH_reg))
#define  VDPQ_CADAP_ZC_TH_cadap_zc_mag_th_y_shift                                (4)
#define  VDPQ_CADAP_ZC_TH_cadap_zc_mag_th_y_c_shift                              (0)
#define  VDPQ_CADAP_ZC_TH_cadap_zc_mag_th_y_mask                                 (0x000000F0)
#define  VDPQ_CADAP_ZC_TH_cadap_zc_mag_th_y_c_mask                               (0x0000000F)
#define  VDPQ_CADAP_ZC_TH_cadap_zc_mag_th_y(data)                                (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_ZC_TH_cadap_zc_mag_th_y_c(data)                              (0x0000000F&(data))
#define  VDPQ_CADAP_ZC_TH_get_cadap_zc_mag_th_y(data)                            ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_ZC_TH_get_cadap_zc_mag_th_y_c(data)                          (0x0000000F&(data))

#define  VDPQ_CADAP_ZC_TH2                                                       0x18019F1C
#define  VDPQ_CADAP_ZC_TH2_reg_addr                                              "0xB8019F1C"
#define  VDPQ_CADAP_ZC_TH2_reg                                                   0xB8019F1C
#define  VDPQ_CADAP_ZC_TH2_inst_addr                                             "0x00C9"
#define  set_VDPQ_CADAP_ZC_TH2_reg(data)                                         (*((volatile unsigned int*)VDPQ_CADAP_ZC_TH2_reg)=data)
#define  get_VDPQ_CADAP_ZC_TH2_reg                                               (*((volatile unsigned int*)VDPQ_CADAP_ZC_TH2_reg))
#define  VDPQ_CADAP_ZC_TH2_cadap_zc_mag_th_c_shift                               (4)
#define  VDPQ_CADAP_ZC_TH2_cadap_dir_det_gain_shift                              (0)
#define  VDPQ_CADAP_ZC_TH2_cadap_zc_mag_th_c_mask                                (0x000000F0)
#define  VDPQ_CADAP_ZC_TH2_cadap_dir_det_gain_mask                               (0x0000000F)
#define  VDPQ_CADAP_ZC_TH2_cadap_zc_mag_th_c(data)                               (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_ZC_TH2_cadap_dir_det_gain(data)                              (0x0000000F&(data))
#define  VDPQ_CADAP_ZC_TH2_get_cadap_zc_mag_th_c(data)                           ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_ZC_TH2_get_cadap_dir_det_gain(data)                          (0x0000000F&(data))

#define  VDPQ_CADAP_VER_UNIFORMITY_TH                                            0x18019F20
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_reg_addr                                   "0xB8019F20"
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_reg                                        0xB8019F20
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_inst_addr                                  "0x00CA"
#define  set_VDPQ_CADAP_VER_UNIFORMITY_TH_reg(data)                              (*((volatile unsigned int*)VDPQ_CADAP_VER_UNIFORMITY_TH_reg)=data)
#define  get_VDPQ_CADAP_VER_UNIFORMITY_TH_reg                                    (*((volatile unsigned int*)VDPQ_CADAP_VER_UNIFORMITY_TH_reg))
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_cadap_ver_uni_th_shift                     (4)
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_cadap_dir_uni_th_shift                     (0)
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_cadap_ver_uni_th_mask                      (0x000000F0)
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_cadap_dir_uni_th_mask                      (0x0000000F)
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_cadap_ver_uni_th(data)                     (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_cadap_dir_uni_th(data)                     (0x0000000F&(data))
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_get_cadap_ver_uni_th(data)                 ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_get_cadap_dir_uni_th(data)                 (0x0000000F&(data))

#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH                                           0x18019F24
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg_addr                                  "0xB8019F24"
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg                                       0xB8019F24
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_inst_addr                                 "0x00CB"
#define  set_VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg(data)                             (*((volatile unsigned int*)VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg)=data)
#define  get_VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg                                   (*((volatile unsigned int*)VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg))
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_cadap_y_sync_uni_th_shift                 (4)
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_cadap_uv_sync_uni_th_shift                (0)
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_cadap_y_sync_uni_th_mask                  (0x000000F0)
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_cadap_uv_sync_uni_th_mask                 (0x0000000F)
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_cadap_y_sync_uni_th(data)                 (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_cadap_uv_sync_uni_th(data)                (0x0000000F&(data))
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_get_cadap_y_sync_uni_th(data)             ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_get_cadap_uv_sync_uni_th(data)            (0x0000000F&(data))

#define  VDPQ_CADAP_LUT_LEVEL_TH                                                 0x18019F28
#define  VDPQ_CADAP_LUT_LEVEL_TH_reg_addr                                        "0xB8019F28"
#define  VDPQ_CADAP_LUT_LEVEL_TH_reg                                             0xB8019F28
#define  VDPQ_CADAP_LUT_LEVEL_TH_inst_addr                                       "0x00CC"
#define  set_VDPQ_CADAP_LUT_LEVEL_TH_reg(data)                                   (*((volatile unsigned int*)VDPQ_CADAP_LUT_LEVEL_TH_reg)=data)
#define  get_VDPQ_CADAP_LUT_LEVEL_TH_reg                                         (*((volatile unsigned int*)VDPQ_CADAP_LUT_LEVEL_TH_reg))
#define  VDPQ_CADAP_LUT_LEVEL_TH_cadap_lut_level_tha_shift                       (4)
#define  VDPQ_CADAP_LUT_LEVEL_TH_cadap_lut_level_thb_shift                       (0)
#define  VDPQ_CADAP_LUT_LEVEL_TH_cadap_lut_level_tha_mask                        (0x000000F0)
#define  VDPQ_CADAP_LUT_LEVEL_TH_cadap_lut_level_thb_mask                        (0x0000000F)
#define  VDPQ_CADAP_LUT_LEVEL_TH_cadap_lut_level_tha(data)                       (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_LUT_LEVEL_TH_cadap_lut_level_thb(data)                       (0x0000000F&(data))
#define  VDPQ_CADAP_LUT_LEVEL_TH_get_cadap_lut_level_tha(data)                   ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_LUT_LEVEL_TH_get_cadap_lut_level_thb(data)                   (0x0000000F&(data))

#define  VDPQ_CADAP_LUT_GAIN_TH                                                  0x18019F2C
#define  VDPQ_CADAP_LUT_GAIN_TH_reg_addr                                         "0xB8019F2C"
#define  VDPQ_CADAP_LUT_GAIN_TH_reg                                              0xB8019F2C
#define  VDPQ_CADAP_LUT_GAIN_TH_inst_addr                                        "0x00CD"
#define  set_VDPQ_CADAP_LUT_GAIN_TH_reg(data)                                    (*((volatile unsigned int*)VDPQ_CADAP_LUT_GAIN_TH_reg)=data)
#define  get_VDPQ_CADAP_LUT_GAIN_TH_reg                                          (*((volatile unsigned int*)VDPQ_CADAP_LUT_GAIN_TH_reg))
#define  VDPQ_CADAP_LUT_GAIN_TH_cadap_lut_gain_tha_shift                         (4)
#define  VDPQ_CADAP_LUT_GAIN_TH_cadap_lut_gain_thb_shift                         (0)
#define  VDPQ_CADAP_LUT_GAIN_TH_cadap_lut_gain_tha_mask                          (0x000000F0)
#define  VDPQ_CADAP_LUT_GAIN_TH_cadap_lut_gain_thb_mask                          (0x0000000F)
#define  VDPQ_CADAP_LUT_GAIN_TH_cadap_lut_gain_tha(data)                         (0x000000F0&((data)<<4))
#define  VDPQ_CADAP_LUT_GAIN_TH_cadap_lut_gain_thb(data)                         (0x0000000F&(data))
#define  VDPQ_CADAP_LUT_GAIN_TH_get_cadap_lut_gain_tha(data)                     ((0x000000F0&(data))>>4)
#define  VDPQ_CADAP_LUT_GAIN_TH_get_cadap_lut_gain_thb(data)                     (0x0000000F&(data))

#define  VDPQ_DCTI_FILTER_COEF_B1                                                0x18019F30
#define  VDPQ_DCTI_FILTER_COEF_B1_reg_addr                                       "0xB8019F30"
#define  VDPQ_DCTI_FILTER_COEF_B1_reg                                            0xB8019F30
#define  VDPQ_DCTI_FILTER_COEF_B1_inst_addr                                      "0x00CE"
#define  set_VDPQ_DCTI_FILTER_COEF_B1_reg(data)                                  (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_B1_reg)=data)
#define  get_VDPQ_DCTI_FILTER_COEF_B1_reg                                        (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_B1_reg))
#define  VDPQ_DCTI_FILTER_COEF_B1_dcti_filter_coef_b1_shift                      (0)
#define  VDPQ_DCTI_FILTER_COEF_B1_dcti_filter_coef_b1_mask                       (0x000007FF)
#define  VDPQ_DCTI_FILTER_COEF_B1_dcti_filter_coef_b1(data)                      (0x000007FF&(data))
#define  VDPQ_DCTI_FILTER_COEF_B1_get_dcti_filter_coef_b1(data)                  (0x000007FF&(data))

#define  VDPQ_DCTI_FILTER_COEF_B2                                                0x18019F34
#define  VDPQ_DCTI_FILTER_COEF_B2_reg_addr                                       "0xB8019F34"
#define  VDPQ_DCTI_FILTER_COEF_B2_reg                                            0xB8019F34
#define  VDPQ_DCTI_FILTER_COEF_B2_inst_addr                                      "0x00CF"
#define  set_VDPQ_DCTI_FILTER_COEF_B2_reg(data)                                  (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_B2_reg)=data)
#define  get_VDPQ_DCTI_FILTER_COEF_B2_reg                                        (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_B2_reg))
#define  VDPQ_DCTI_FILTER_COEF_B2_dcti_filter_coef_b2_shift                      (0)
#define  VDPQ_DCTI_FILTER_COEF_B2_dcti_filter_coef_b2_mask                       (0x000007FF)
#define  VDPQ_DCTI_FILTER_COEF_B2_dcti_filter_coef_b2(data)                      (0x000007FF&(data))
#define  VDPQ_DCTI_FILTER_COEF_B2_get_dcti_filter_coef_b2(data)                  (0x000007FF&(data))

#define  VDPQ_DCTI_FILTER_COEF_B3                                                0x18019F38
#define  VDPQ_DCTI_FILTER_COEF_B3_reg_addr                                       "0xB8019F38"
#define  VDPQ_DCTI_FILTER_COEF_B3_reg                                            0xB8019F38
#define  VDPQ_DCTI_FILTER_COEF_B3_inst_addr                                      "0x00D0"
#define  set_VDPQ_DCTI_FILTER_COEF_B3_reg(data)                                  (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_B3_reg)=data)
#define  get_VDPQ_DCTI_FILTER_COEF_B3_reg                                        (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_B3_reg))
#define  VDPQ_DCTI_FILTER_COEF_B3_dcti_filter_coef_b3_shift                      (0)
#define  VDPQ_DCTI_FILTER_COEF_B3_dcti_filter_coef_b3_mask                       (0x000007FF)
#define  VDPQ_DCTI_FILTER_COEF_B3_dcti_filter_coef_b3(data)                      (0x000007FF&(data))
#define  VDPQ_DCTI_FILTER_COEF_B3_get_dcti_filter_coef_b3(data)                  (0x000007FF&(data))

#define  VDPQ_DCTI_FILTER_COEF_A2                                                0x18019F3C
#define  VDPQ_DCTI_FILTER_COEF_A2_reg_addr                                       "0xB8019F3C"
#define  VDPQ_DCTI_FILTER_COEF_A2_reg                                            0xB8019F3C
#define  VDPQ_DCTI_FILTER_COEF_A2_inst_addr                                      "0x00D1"
#define  set_VDPQ_DCTI_FILTER_COEF_A2_reg(data)                                  (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_A2_reg)=data)
#define  get_VDPQ_DCTI_FILTER_COEF_A2_reg                                        (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_A2_reg))
#define  VDPQ_DCTI_FILTER_COEF_A2_dcti_filter_coef_a2_shift                      (0)
#define  VDPQ_DCTI_FILTER_COEF_A2_dcti_filter_coef_a2_mask                       (0x000007FF)
#define  VDPQ_DCTI_FILTER_COEF_A2_dcti_filter_coef_a2(data)                      (0x000007FF&(data))
#define  VDPQ_DCTI_FILTER_COEF_A2_get_dcti_filter_coef_a2(data)                  (0x000007FF&(data))

#define  VDPQ_DCTI_FILTER_COEF_A3                                                0x18019F40
#define  VDPQ_DCTI_FILTER_COEF_A3_reg_addr                                       "0xB8019F40"
#define  VDPQ_DCTI_FILTER_COEF_A3_reg                                            0xB8019F40
#define  VDPQ_DCTI_FILTER_COEF_A3_inst_addr                                      "0x00D2"
#define  set_VDPQ_DCTI_FILTER_COEF_A3_reg(data)                                  (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_A3_reg)=data)
#define  get_VDPQ_DCTI_FILTER_COEF_A3_reg                                        (*((volatile unsigned int*)VDPQ_DCTI_FILTER_COEF_A3_reg))
#define  VDPQ_DCTI_FILTER_COEF_A3_dcti_filter_coef_a3_shift                      (0)
#define  VDPQ_DCTI_FILTER_COEF_A3_dcti_filter_coef_a3_mask                       (0x000007FF)
#define  VDPQ_DCTI_FILTER_COEF_A3_dcti_filter_coef_a3(data)                      (0x000007FF&(data))
#define  VDPQ_DCTI_FILTER_COEF_A3_get_dcti_filter_coef_a3(data)                  (0x000007FF&(data))

#define  VDPQ_DCTI_FILTER_EN                                                     0x18019F44
#define  VDPQ_DCTI_FILTER_EN_reg_addr                                            "0xB8019F44"
#define  VDPQ_DCTI_FILTER_EN_reg                                                 0xB8019F44
#define  VDPQ_DCTI_FILTER_EN_inst_addr                                           "0x00D3"
#define  set_VDPQ_DCTI_FILTER_EN_reg(data)                                       (*((volatile unsigned int*)VDPQ_DCTI_FILTER_EN_reg)=data)
#define  get_VDPQ_DCTI_FILTER_EN_reg                                             (*((volatile unsigned int*)VDPQ_DCTI_FILTER_EN_reg))
#define  VDPQ_DCTI_FILTER_EN_dcti_filter_en_shift                                (0)
#define  VDPQ_DCTI_FILTER_EN_dcti_filter_en_mask                                 (0x00000001)
#define  VDPQ_DCTI_FILTER_EN_dcti_filter_en(data)                                (0x00000001&(data))
#define  VDPQ_DCTI_FILTER_EN_get_dcti_filter_en(data)                            (0x00000001&(data))

#define  VDPQ_YC_3D_F4_SMD_EN                                                    0x18019F48
#define  VDPQ_YC_3D_F4_SMD_EN_reg_addr                                           "0xB8019F48"
#define  VDPQ_YC_3D_F4_SMD_EN_reg                                                0xB8019F48
#define  VDPQ_YC_3D_F4_SMD_EN_inst_addr                                          "0x00D4"
#define  set_VDPQ_YC_3D_F4_SMD_EN_reg(data)                                      (*((volatile unsigned int*)VDPQ_YC_3D_F4_SMD_EN_reg)=data)
#define  get_VDPQ_YC_3D_F4_SMD_EN_reg                                            (*((volatile unsigned int*)VDPQ_YC_3D_F4_SMD_EN_reg))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_10_move_enable_shift                       (12)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_08_move_enable_shift                       (11)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_06_move_enable_shift                       (10)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_04_move_enable_shift                       (9)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_02_move_enable_shift                       (8)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_00_move_enable_shift                       (7)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_10_move_enable_shift                       (6)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_08_move_enable_shift                       (5)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_06_move_enable_shift                       (4)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_04_move_enable_shift                       (3)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_02_move_enable_shift                       (2)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_00_move_enable_shift                       (1)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_en_shift                                       (0)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_10_move_enable_mask                        (0x00001000)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_08_move_enable_mask                        (0x00000800)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_06_move_enable_mask                        (0x00000400)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_04_move_enable_mask                        (0x00000200)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_02_move_enable_mask                        (0x00000100)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_00_move_enable_mask                        (0x00000080)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_10_move_enable_mask                        (0x00000040)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_08_move_enable_mask                        (0x00000020)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_06_move_enable_mask                        (0x00000010)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_04_move_enable_mask                        (0x00000008)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_02_move_enable_mask                        (0x00000004)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_00_move_enable_mask                        (0x00000002)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_en_mask                                        (0x00000001)
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_10_move_enable(data)                       (0x00001000&((data)<<12))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_08_move_enable(data)                       (0x00000800&((data)<<11))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_06_move_enable(data)                       (0x00000400&((data)<<10))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_04_move_enable(data)                       (0x00000200&((data)<<9))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_02_move_enable(data)                       (0x00000100&((data)<<8))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_ver_00_move_enable(data)                       (0x00000080&((data)<<7))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_10_move_enable(data)                       (0x00000040&((data)<<6))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_08_move_enable(data)                       (0x00000020&((data)<<5))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_06_move_enable(data)                       (0x00000010&((data)<<4))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_04_move_enable(data)                       (0x00000008&((data)<<3))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_02_move_enable(data)                       (0x00000004&((data)<<2))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_hor_00_move_enable(data)                       (0x00000002&((data)<<1))
#define  VDPQ_YC_3D_F4_SMD_EN_smd_en(data)                                       (0x00000001&(data))
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_ver_10_move_enable(data)                   ((0x00001000&(data))>>12)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_ver_08_move_enable(data)                   ((0x00000800&(data))>>11)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_ver_06_move_enable(data)                   ((0x00000400&(data))>>10)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_ver_04_move_enable(data)                   ((0x00000200&(data))>>9)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_ver_02_move_enable(data)                   ((0x00000100&(data))>>8)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_ver_00_move_enable(data)                   ((0x00000080&(data))>>7)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_hor_10_move_enable(data)                   ((0x00000040&(data))>>6)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_hor_08_move_enable(data)                   ((0x00000020&(data))>>5)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_hor_06_move_enable(data)                   ((0x00000010&(data))>>4)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_hor_04_move_enable(data)                   ((0x00000008&(data))>>3)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_hor_02_move_enable(data)                   ((0x00000004&(data))>>2)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_hor_00_move_enable(data)                   ((0x00000002&(data))>>1)
#define  VDPQ_YC_3D_F4_SMD_EN_get_smd_en(data)                                   (0x00000001&(data))

#define  VDPQ_YC_3D_F4_SMD_TH1                                                   0x18019F4C
#define  VDPQ_YC_3D_F4_SMD_TH1_reg_addr                                          "0xB8019F4C"
#define  VDPQ_YC_3D_F4_SMD_TH1_reg                                               0xB8019F4C
#define  VDPQ_YC_3D_F4_SMD_TH1_inst_addr                                         "0x00D5"
#define  set_VDPQ_YC_3D_F4_SMD_TH1_reg(data)                                     (*((volatile unsigned int*)VDPQ_YC_3D_F4_SMD_TH1_reg)=data)
#define  get_VDPQ_YC_3D_F4_SMD_TH1_reg                                           (*((volatile unsigned int*)VDPQ_YC_3D_F4_SMD_TH1_reg))
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_ver_spatial_temporal_traily_diff_shift        (24)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_hor_spatial_temporal_traily_diff_shift        (16)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_vertical_sad_tolerance_shift                  (8)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_horizontal_sad_tolerance_shift                (0)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_ver_spatial_temporal_traily_diff_mask         (0xFF000000)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_hor_spatial_temporal_traily_diff_mask         (0x00FF0000)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_vertical_sad_tolerance_mask                   (0x0000FF00)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_horizontal_sad_tolerance_mask                 (0x000000FF)
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_ver_spatial_temporal_traily_diff(data)        (0xFF000000&((data)<<24))
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_hor_spatial_temporal_traily_diff(data)        (0x00FF0000&((data)<<16))
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_vertical_sad_tolerance(data)                  (0x0000FF00&((data)<<8))
#define  VDPQ_YC_3D_F4_SMD_TH1_smd_horizontal_sad_tolerance(data)                (0x000000FF&(data))
#define  VDPQ_YC_3D_F4_SMD_TH1_get_smd_ver_spatial_temporal_traily_diff(data)    ((0xFF000000&(data))>>24)
#define  VDPQ_YC_3D_F4_SMD_TH1_get_smd_hor_spatial_temporal_traily_diff(data)    ((0x00FF0000&(data))>>16)
#define  VDPQ_YC_3D_F4_SMD_TH1_get_smd_vertical_sad_tolerance(data)              ((0x0000FF00&(data))>>8)
#define  VDPQ_YC_3D_F4_SMD_TH1_get_smd_horizontal_sad_tolerance(data)            (0x000000FF&(data))

#define  VDPQ_YC_3D_F4_SMD_TH2                                                   0x18019F50
#define  VDPQ_YC_3D_F4_SMD_TH2_reg_addr                                          "0xB8019F50"
#define  VDPQ_YC_3D_F4_SMD_TH2_reg                                               0xB8019F50
#define  VDPQ_YC_3D_F4_SMD_TH2_inst_addr                                         "0x00D6"
#define  set_VDPQ_YC_3D_F4_SMD_TH2_reg(data)                                     (*((volatile unsigned int*)VDPQ_YC_3D_F4_SMD_TH2_reg)=data)
#define  get_VDPQ_YC_3D_F4_SMD_TH2_reg                                           (*((volatile unsigned int*)VDPQ_YC_3D_F4_SMD_TH2_reg))
#define  VDPQ_YC_3D_F4_SMD_TH2_smd_min_sad_vetical_shift                         (8)
#define  VDPQ_YC_3D_F4_SMD_TH2_smd_min_sad_horizontal_shift                      (0)
#define  VDPQ_YC_3D_F4_SMD_TH2_smd_min_sad_vetical_mask                          (0x0000FF00)
#define  VDPQ_YC_3D_F4_SMD_TH2_smd_min_sad_horizontal_mask                       (0x000000FF)
#define  VDPQ_YC_3D_F4_SMD_TH2_smd_min_sad_vetical(data)                         (0x0000FF00&((data)<<8))
#define  VDPQ_YC_3D_F4_SMD_TH2_smd_min_sad_horizontal(data)                      (0x000000FF&(data))
#define  VDPQ_YC_3D_F4_SMD_TH2_get_smd_min_sad_vetical(data)                     ((0x0000FF00&(data))>>8)
#define  VDPQ_YC_3D_F4_SMD_TH2_get_smd_min_sad_horizontal(data)                  (0x000000FF&(data))

#define  VDPQ_YC_3D_F4_Pair_SMD_TH1                                              0x18019F54
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_reg_addr                                     "0xB8019F54"
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_reg                                          0xB8019F54
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_inst_addr                                    "0x00D7"
#define  set_VDPQ_YC_3D_F4_Pair_SMD_TH1_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_SMD_TH1_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_SMD_TH1_reg                                      (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_SMD_TH1_reg))
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_2d_small_global_diff_offset_shift        (16)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_highfreq_diff_2_th_shift                 (8)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_highfreq_diff_th_shift                   (0)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_2d_small_global_diff_offset_mask         (0xFFFF0000)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_highfreq_diff_2_th_mask                  (0x0000FF00)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_highfreq_diff_th_mask                    (0x000000FF)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_2d_small_global_diff_offset(data)        (0xFFFF0000&((data)<<16))
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_highfreq_diff_2_th(data)                 (0x0000FF00&((data)<<8))
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_smd_highfreq_diff_th(data)                   (0x000000FF&(data))
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_get_smd_2d_small_global_diff_offset(data)    ((0xFFFF0000&(data))>>16)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_get_smd_highfreq_diff_2_th(data)             ((0x0000FF00&(data))>>8)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH1_get_smd_highfreq_diff_th(data)               (0x000000FF&(data))

#define  VDPQ_YC_3D_F4_Pair_SMD_TH2                                              0x18019F58
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_reg_addr                                     "0xB8019F58"
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_reg                                          0xB8019F58
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_inst_addr                                    "0x00D8"
#define  set_VDPQ_YC_3D_F4_Pair_SMD_TH2_reg(data)                                (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_SMD_TH2_reg)=data)
#define  get_VDPQ_YC_3D_F4_Pair_SMD_TH2_reg                                      (*((volatile unsigned int*)VDPQ_YC_3D_F4_Pair_SMD_TH2_reg))
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_smd_2d_not_small_global_diff_offset_shift    (0)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_smd_2d_not_small_global_diff_offset_mask     (0x0000FFFF)
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_smd_2d_not_small_global_diff_offset(data)    (0x0000FFFF&(data))
#define  VDPQ_YC_3D_F4_Pair_SMD_TH2_get_smd_2d_not_small_global_diff_offset(data) (0x0000FFFF&(data))

#define  VDPQ_NS_R1                                                              0x18019F5C
#define  VDPQ_NS_R1_reg_addr                                                     "0xB8019F5C"
#define  VDPQ_NS_R1_reg                                                          0xB8019F5C
#define  VDPQ_NS_R1_inst_addr                                                    "0x00D9"
#define  set_VDPQ_NS_R1_reg(data)                                                (*((volatile unsigned int*)VDPQ_NS_R1_reg)=data)
#define  get_VDPQ_NS_R1_reg                                                      (*((volatile unsigned int*)VDPQ_NS_R1_reg))
#define  VDPQ_NS_R1_sum_vm_shift                                                 (0)
#define  VDPQ_NS_R1_sum_vm_mask                                                  (0xFFFFFFFF)
#define  VDPQ_NS_R1_sum_vm(data)                                                 (0xFFFFFFFF&(data))
#define  VDPQ_NS_R1_get_sum_vm(data)                                             (0xFFFFFFFF&(data))

#define  VDPQ_NS_R2                                                              0x18019F60
#define  VDPQ_NS_R2_reg_addr                                                     "0xB8019F60"
#define  VDPQ_NS_R2_reg                                                          0xB8019F60
#define  VDPQ_NS_R2_inst_addr                                                    "0x00DA"
#define  set_VDPQ_NS_R2_reg(data)                                                (*((volatile unsigned int*)VDPQ_NS_R2_reg)=data)
#define  get_VDPQ_NS_R2_reg                                                      (*((volatile unsigned int*)VDPQ_NS_R2_reg))
#define  VDPQ_NS_R2_countv_shift                                                 (16)
#define  VDPQ_NS_R2_maxv_shift                                                   (0)
#define  VDPQ_NS_R2_countv_mask                                                  (0xFFFF0000)
#define  VDPQ_NS_R2_maxv_mask                                                    (0x0000FFFF)
#define  VDPQ_NS_R2_countv(data)                                                 (0xFFFF0000&((data)<<16))
#define  VDPQ_NS_R2_maxv(data)                                                   (0x0000FFFF&(data))
#define  VDPQ_NS_R2_get_countv(data)                                             ((0xFFFF0000&(data))>>16)
#define  VDPQ_NS_R2_get_maxv(data)                                               (0x0000FFFF&(data))

#define  VDPQ_NS_R3                                                              0x18019F64
#define  VDPQ_NS_R3_reg_addr                                                     "0xB8019F64"
#define  VDPQ_NS_R3_reg                                                          0xB8019F64
#define  VDPQ_NS_R3_inst_addr                                                    "0x00DB"
#define  set_VDPQ_NS_R3_reg(data)                                                (*((volatile unsigned int*)VDPQ_NS_R3_reg)=data)
#define  get_VDPQ_NS_R3_reg                                                      (*((volatile unsigned int*)VDPQ_NS_R3_reg))
#define  VDPQ_NS_R3_sumv_shift                                                   (0)
#define  VDPQ_NS_R3_sumv_mask                                                    (0xFFFFFFFF)
#define  VDPQ_NS_R3_sumv(data)                                                   (0xFFFFFFFF&(data))
#define  VDPQ_NS_R3_get_sumv(data)                                               (0xFFFFFFFF&(data))

#define  VDPQ_NS_RW1                                                             0x18019F68
#define  VDPQ_NS_RW1_reg_addr                                                    "0xB8019F68"
#define  VDPQ_NS_RW1_reg                                                         0xB8019F68
#define  VDPQ_NS_RW1_inst_addr                                                   "0x00DC"
#define  set_VDPQ_NS_RW1_reg(data)                                               (*((volatile unsigned int*)VDPQ_NS_RW1_reg)=data)
#define  get_VDPQ_NS_RW1_reg                                                     (*((volatile unsigned int*)VDPQ_NS_RW1_reg))
#define  VDPQ_NS_RW1_nfactor_shift                                               (16)
#define  VDPQ_NS_RW1_vmm_shift                                                   (0)
#define  VDPQ_NS_RW1_nfactor_mask                                                (0x00FF0000)
#define  VDPQ_NS_RW1_vmm_mask                                                    (0x0000FFFF)
#define  VDPQ_NS_RW1_nfactor(data)                                               (0x00FF0000&((data)<<16))
#define  VDPQ_NS_RW1_vmm(data)                                                   (0x0000FFFF&(data))
#define  VDPQ_NS_RW1_get_nfactor(data)                                           ((0x00FF0000&(data))>>16)
#define  VDPQ_NS_RW1_get_vmm(data)                                               (0x0000FFFF&(data))

#define  VDPQ_NS_RW2                                                             0x18019F6C
#define  VDPQ_NS_RW2_reg_addr                                                    "0xB8019F6C"
#define  VDPQ_NS_RW2_reg                                                         0xB8019F6C
#define  VDPQ_NS_RW2_inst_addr                                                   "0x00DD"
#define  set_VDPQ_NS_RW2_reg(data)                                               (*((volatile unsigned int*)VDPQ_NS_RW2_reg)=data)
#define  get_VDPQ_NS_RW2_reg                                                     (*((volatile unsigned int*)VDPQ_NS_RW2_reg))
#define  VDPQ_NS_RW2_density_shift                                               (16)
#define  VDPQ_NS_RW2_meannxv_shift                                               (0)
#define  VDPQ_NS_RW2_density_mask                                                (0x00FF0000)
#define  VDPQ_NS_RW2_meannxv_mask                                                (0x0000FFFF)
#define  VDPQ_NS_RW2_density(data)                                               (0x00FF0000&((data)<<16))
#define  VDPQ_NS_RW2_meannxv(data)                                               (0x0000FFFF&(data))
#define  VDPQ_NS_RW2_get_density(data)                                           ((0x00FF0000&(data))>>16)
#define  VDPQ_NS_RW2_get_meannxv(data)                                           (0x0000FFFF&(data))

#define  VDPQ_NS_GATE                                                            0x18019F7C
#define  VDPQ_NS_GATE_reg_addr                                                   "0xB8019F7C"
#define  VDPQ_NS_GATE_reg                                                        0xB8019F7C
#define  VDPQ_NS_GATE_inst_addr                                                  "0x00DE"
#define  set_VDPQ_NS_GATE_reg(data)                                              (*((volatile unsigned int*)VDPQ_NS_GATE_reg)=data)
#define  get_VDPQ_NS_GATE_reg                                                    (*((volatile unsigned int*)VDPQ_NS_GATE_reg))
#define  VDPQ_NS_GATE_hsyncdebug_en_shift                                        (31)
#define  VDPQ_NS_GATE_pq_noisestatus_hsync_start_shift                           (8)
#define  VDPQ_NS_GATE_pq_noisestatus_hsync_end_shift                             (0)
#define  VDPQ_NS_GATE_hsyncdebug_en_mask                                         (0x80000000)
#define  VDPQ_NS_GATE_pq_noisestatus_hsync_start_mask                            (0x0000FF00)
#define  VDPQ_NS_GATE_pq_noisestatus_hsync_end_mask                              (0x000000FF)
#define  VDPQ_NS_GATE_hsyncdebug_en(data)                                        (0x80000000&((data)<<31))
#define  VDPQ_NS_GATE_pq_noisestatus_hsync_start(data)                           (0x0000FF00&((data)<<8))
#define  VDPQ_NS_GATE_pq_noisestatus_hsync_end(data)                             (0x000000FF&(data))
#define  VDPQ_NS_GATE_get_hsyncdebug_en(data)                                    ((0x80000000&(data))>>31)
#define  VDPQ_NS_GATE_get_pq_noisestatus_hsync_start(data)                       ((0x0000FF00&(data))>>8)
#define  VDPQ_NS_GATE_get_pq_noisestatus_hsync_end(data)                         (0x000000FF&(data))

#define  VDPQ_POSTP_SECAM_FIX_CTRL                                               0x18019F70
#define  VDPQ_POSTP_SECAM_FIX_CTRL_reg_addr                                      "0xB8019F70"
#define  VDPQ_POSTP_SECAM_FIX_CTRL_reg                                           0xB8019F70
#define  VDPQ_POSTP_SECAM_FIX_CTRL_inst_addr                                     "0x00DF"
#define  set_VDPQ_POSTP_SECAM_FIX_CTRL_reg(data)                                 (*((volatile unsigned int*)VDPQ_POSTP_SECAM_FIX_CTRL_reg)=data)
#define  get_VDPQ_POSTP_SECAM_FIX_CTRL_reg                                       (*((volatile unsigned int*)VDPQ_POSTP_SECAM_FIX_CTRL_reg))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_uv_flag_en_shift                    (31)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_color_reduce_en_shift               (30)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_line_grey_ratio_shift               (16)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_grey_thd_shift                      (8)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_debug_mode_shift                    (4)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_post_cvlpf_en_shift                 (3)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_pre_yvlpf_en_shift                  (2)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_color_reduce_ctrl_shift             (0)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_uv_flag_en_mask                     (0x80000000)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_color_reduce_en_mask                (0x40000000)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_line_grey_ratio_mask                (0x000F0000)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_grey_thd_mask                       (0x0000FF00)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_debug_mode_mask                     (0x00000070)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_post_cvlpf_en_mask                  (0x00000008)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_pre_yvlpf_en_mask                   (0x00000004)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_color_reduce_ctrl_mask              (0x00000003)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_uv_flag_en(data)                    (0x80000000&((data)<<31))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_color_reduce_en(data)               (0x40000000&((data)<<30))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_line_grey_ratio(data)               (0x000F0000&((data)<<16))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_grey_thd(data)                      (0x0000FF00&((data)<<8))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_debug_mode(data)                    (0x00000070&((data)<<4))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_post_cvlpf_en(data)                 (0x00000008&((data)<<3))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_pre_yvlpf_en(data)                  (0x00000004&((data)<<2))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_secam_fix_color_reduce_ctrl(data)             (0x00000003&(data))
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_uv_flag_en(data)                ((0x80000000&(data))>>31)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_color_reduce_en(data)           ((0x40000000&(data))>>30)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_line_grey_ratio(data)           ((0x000F0000&(data))>>16)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_grey_thd(data)                  ((0x0000FF00&(data))>>8)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_debug_mode(data)                ((0x00000070&(data))>>4)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_post_cvlpf_en(data)             ((0x00000008&(data))>>3)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_pre_yvlpf_en(data)              ((0x00000004&(data))>>2)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_get_secam_fix_color_reduce_ctrl(data)         (0x00000003&(data))

#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0                                          0x18019F74
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg_addr                                 "0xB8019F74"
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg                                      0xB8019F74
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_inst_addr                                "0x00E0"
#define  set_VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg(data)                            (*((volatile unsigned int*)VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg)=data)
#define  get_VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg                                  (*((volatile unsigned int*)VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_en_shift                (31)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_diff_thd_shift               (24)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_action_continue_d_time_shift (16)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_ext_l_shift             (8)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_ext_r_shift             (0)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_en_mask                 (0x80000000)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_diff_thd_mask                (0x3F000000)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_action_continue_d_time_mask  (0x003F0000)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_ext_l_mask              (0x0000FF00)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_ext_r_mask              (0x000000FF)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_en(data)                (0x80000000&((data)<<31))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_diff_thd(data)               (0x3F000000&((data)<<24))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_action_continue_d_time(data) (0x003F0000&((data)<<16))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_ext_l(data)             (0x0000FF00&((data)<<8))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_secam_fix_y_flag_ext_r(data)             (0x000000FF&(data))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_get_secam_fix_y_flag_en(data)            ((0x80000000&(data))>>31)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_get_secam_fix_y_diff_thd(data)           ((0x3F000000&(data))>>24)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_get_secam_fix_y_action_continue_d_time(data) ((0x003F0000&(data))>>16)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_get_secam_fix_y_flag_ext_l(data)         ((0x0000FF00&(data))>>8)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_get_secam_fix_y_flag_ext_r(data)         (0x000000FF&(data))

#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1                                          0x18019F78
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg_addr                                 "0xB8019F78"
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg                                      0xB8019F78
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_inst_addr                                "0x00E1"
#define  set_VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg(data)                            (*((volatile unsigned int*)VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg)=data)
#define  get_VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg                                  (*((volatile unsigned int*)VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d3_shift              (24)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d2_shift              (16)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d1_shift              (8)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d0_shift              (0)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d3_mask               (0x3F000000)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d2_mask               (0x003F0000)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d1_mask               (0x00003F00)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d0_mask               (0x0000003F)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d3(data)              (0x3F000000&((data)<<24))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d2(data)              (0x003F0000&((data)<<16))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d1(data)              (0x00003F00&((data)<<8))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_secam_fix_y_target_d0(data)              (0x0000003F&(data))
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_get_secam_fix_y_target_d3(data)          ((0x3F000000&(data))>>24)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_get_secam_fix_y_target_d2(data)          ((0x003F0000&(data))>>16)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_get_secam_fix_y_target_d1(data)          ((0x00003F00&(data))>>8)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_get_secam_fix_y_target_d0(data)          (0x0000003F&(data))

#define  VDPQ_DIRECTIONAL_3D                                                     0x18019F80
#define  VDPQ_DIRECTIONAL_3D_reg_addr                                            "0xB8019F80"
#define  VDPQ_DIRECTIONAL_3D_reg                                                 0xB8019F80
#define  VDPQ_DIRECTIONAL_3D_inst_addr                                           "0x00E2"
#define  set_VDPQ_DIRECTIONAL_3D_reg(data)                                       (*((volatile unsigned int*)VDPQ_DIRECTIONAL_3D_reg)=data)
#define  get_VDPQ_DIRECTIONAL_3D_reg                                             (*((volatile unsigned int*)VDPQ_DIRECTIONAL_3D_reg))
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_enable_shift                          (31)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_dalpha_shift                          (27)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_motion_shift                          (25)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_dalpha_c_shift                        (21)
#define  VDPQ_DIRECTIONAL_3D_dir3d_enable_shift                                  (0)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_enable_mask                           (0x80000000)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_dalpha_mask                           (0x78000000)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_motion_mask                           (0x06000000)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_dalpha_c_mask                         (0x01E00000)
#define  VDPQ_DIRECTIONAL_3D_dir3d_enable_mask                                   (0x00000001)
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_enable(data)                          (0x80000000&((data)<<31))
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_dalpha(data)                          (0x78000000&((data)<<27))
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_motion(data)                          (0x06000000&((data)<<25))
#define  VDPQ_DIRECTIONAL_3D_dir3d_fw_mode_dalpha_c(data)                        (0x01E00000&((data)<<21))
#define  VDPQ_DIRECTIONAL_3D_dir3d_enable(data)                                  (0x00000001&(data))
#define  VDPQ_DIRECTIONAL_3D_get_dir3d_fw_mode_enable(data)                      ((0x80000000&(data))>>31)
#define  VDPQ_DIRECTIONAL_3D_get_dir3d_fw_mode_dalpha(data)                      ((0x78000000&(data))>>27)
#define  VDPQ_DIRECTIONAL_3D_get_dir3d_fw_mode_motion(data)                      ((0x06000000&(data))>>25)
#define  VDPQ_DIRECTIONAL_3D_get_dir3d_fw_mode_dalpha_c(data)                    ((0x01E00000&(data))>>21)
#define  VDPQ_DIRECTIONAL_3D_get_dir3d_enable(data)                              (0x00000001&(data))

#define  VDPQ_FIX_WINDOW_CTRL                                                    0x18019F90
#define  VDPQ_FIX_WINDOW_CTRL_reg_addr                                           "0xB8019F90"
#define  VDPQ_FIX_WINDOW_CTRL_reg                                                0xB8019F90
#define  VDPQ_FIX_WINDOW_CTRL_inst_addr                                          "0x00E3"
#define  set_VDPQ_FIX_WINDOW_CTRL_reg(data)                                      (*((volatile unsigned int*)VDPQ_FIX_WINDOW_CTRL_reg)=data)
#define  get_VDPQ_FIX_WINDOW_CTRL_reg                                            (*((volatile unsigned int*)VDPQ_FIX_WINDOW_CTRL_reg))
#define  VDPQ_FIX_WINDOW_CTRL_windows_enable_shift                               (31)
#define  VDPQ_FIX_WINDOW_CTRL_windows_2d3d_blend_ratio_shift                     (0)
#define  VDPQ_FIX_WINDOW_CTRL_windows_enable_mask                                (0x80000000)
#define  VDPQ_FIX_WINDOW_CTRL_windows_2d3d_blend_ratio_mask                      (0x0000000F)
#define  VDPQ_FIX_WINDOW_CTRL_windows_enable(data)                               (0x80000000&((data)<<31))
#define  VDPQ_FIX_WINDOW_CTRL_windows_2d3d_blend_ratio(data)                     (0x0000000F&(data))
#define  VDPQ_FIX_WINDOW_CTRL_get_windows_enable(data)                           ((0x80000000&(data))>>31)
#define  VDPQ_FIX_WINDOW_CTRL_get_windows_2d3d_blend_ratio(data)                 (0x0000000F&(data))

#define  VDPQ_FIX_WINDOW_POSX                                                    0x18019F94
#define  VDPQ_FIX_WINDOW_POSX_reg_addr                                           "0xB8019F94"
#define  VDPQ_FIX_WINDOW_POSX_reg                                                0xB8019F94
#define  VDPQ_FIX_WINDOW_POSX_inst_addr                                          "0x00E4"
#define  set_VDPQ_FIX_WINDOW_POSX_reg(data)                                      (*((volatile unsigned int*)VDPQ_FIX_WINDOW_POSX_reg)=data)
#define  get_VDPQ_FIX_WINDOW_POSX_reg                                            (*((volatile unsigned int*)VDPQ_FIX_WINDOW_POSX_reg))
#define  VDPQ_FIX_WINDOW_POSX_windows_x_sta_shift                                (16)
#define  VDPQ_FIX_WINDOW_POSX_windows_x_end_shift                                (0)
#define  VDPQ_FIX_WINDOW_POSX_windows_x_sta_mask                                 (0x07FF0000)
#define  VDPQ_FIX_WINDOW_POSX_windows_x_end_mask                                 (0x000007FF)
#define  VDPQ_FIX_WINDOW_POSX_windows_x_sta(data)                                (0x07FF0000&((data)<<16))
#define  VDPQ_FIX_WINDOW_POSX_windows_x_end(data)                                (0x000007FF&(data))
#define  VDPQ_FIX_WINDOW_POSX_get_windows_x_sta(data)                            ((0x07FF0000&(data))>>16)
#define  VDPQ_FIX_WINDOW_POSX_get_windows_x_end(data)                            (0x000007FF&(data))

#define  VDPQ_FIX_WINDOW_POSY                                                    0x18019F98
#define  VDPQ_FIX_WINDOW_POSY_reg_addr                                           "0xB8019F98"
#define  VDPQ_FIX_WINDOW_POSY_reg                                                0xB8019F98
#define  VDPQ_FIX_WINDOW_POSY_inst_addr                                          "0x00E5"
#define  set_VDPQ_FIX_WINDOW_POSY_reg(data)                                      (*((volatile unsigned int*)VDPQ_FIX_WINDOW_POSY_reg)=data)
#define  get_VDPQ_FIX_WINDOW_POSY_reg                                            (*((volatile unsigned int*)VDPQ_FIX_WINDOW_POSY_reg))
#define  VDPQ_FIX_WINDOW_POSY_windows_y_sta_shift                                (16)
#define  VDPQ_FIX_WINDOW_POSY_windows_y_end_shift                                (0)
#define  VDPQ_FIX_WINDOW_POSY_windows_y_sta_mask                                 (0x01FF0000)
#define  VDPQ_FIX_WINDOW_POSY_windows_y_end_mask                                 (0x000001FF)
#define  VDPQ_FIX_WINDOW_POSY_windows_y_sta(data)                                (0x01FF0000&((data)<<16))
#define  VDPQ_FIX_WINDOW_POSY_windows_y_end(data)                                (0x000001FF&(data))
#define  VDPQ_FIX_WINDOW_POSY_get_windows_y_sta(data)                            ((0x01FF0000&(data))>>16)
#define  VDPQ_FIX_WINDOW_POSY_get_windows_y_end(data)                            (0x000001FF&(data))

#define  VDPQ_Dummy_5                                                            0x18019FF0
#define  VDPQ_Dummy_5_reg_addr                                                   "0xB8019FF0"
#define  VDPQ_Dummy_5_reg                                                        0xB8019FF0
#define  VDPQ_Dummy_5_inst_addr                                                  "0x00E6"
#define  set_VDPQ_Dummy_5_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_5_reg)=data)
#define  get_VDPQ_Dummy_5_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_5_reg))
#define  VDPQ_Dummy_5_dummy_5_shift                                              (0)
#define  VDPQ_Dummy_5_dummy_5_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_5_dummy_5(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_5_get_dummy_5(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_Dummy_6                                                            0x18019FF4
#define  VDPQ_Dummy_6_reg_addr                                                   "0xB8019FF4"
#define  VDPQ_Dummy_6_reg                                                        0xB8019FF4
#define  VDPQ_Dummy_6_inst_addr                                                  "0x00E7"
#define  set_VDPQ_Dummy_6_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_6_reg)=data)
#define  get_VDPQ_Dummy_6_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_6_reg))
#define  VDPQ_Dummy_6_dummy_6_shift                                              (0)
#define  VDPQ_Dummy_6_dummy_6_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_6_dummy_6(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_6_get_dummy_6(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_Dummy_7                                                            0x18019FF8
#define  VDPQ_Dummy_7_reg_addr                                                   "0xB8019FF8"
#define  VDPQ_Dummy_7_reg                                                        0xB8019FF8
#define  VDPQ_Dummy_7_inst_addr                                                  "0x00E8"
#define  set_VDPQ_Dummy_7_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_7_reg)=data)
#define  get_VDPQ_Dummy_7_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_7_reg))
#define  VDPQ_Dummy_7_dummy_7_shift                                              (0)
#define  VDPQ_Dummy_7_dummy_7_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_7_dummy_7(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_7_get_dummy_7(data)                                          (0xFFFFFFFF&(data))

#define  VDPQ_Dummy_8                                                            0x18019FFC
#define  VDPQ_Dummy_8_reg_addr                                                   "0xB8019FFC"
#define  VDPQ_Dummy_8_reg                                                        0xB8019FFC
#define  VDPQ_Dummy_8_inst_addr                                                  "0x00E9"
#define  set_VDPQ_Dummy_8_reg(data)                                              (*((volatile unsigned int*)VDPQ_Dummy_8_reg)=data)
#define  get_VDPQ_Dummy_8_reg                                                    (*((volatile unsigned int*)VDPQ_Dummy_8_reg))
#define  VDPQ_Dummy_8_dummy_8_shift                                              (0)
#define  VDPQ_Dummy_8_dummy_8_mask                                               (0xFFFFFFFF)
#define  VDPQ_Dummy_8_dummy_8(data)                                              (0xFFFFFFFF&(data))
#define  VDPQ_Dummy_8_get_dummy_8(data)                                          (0xFFFFFFFF&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VDPQ register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  f_num_chk_3d_sel:2;
        RBus_UInt32  f_hennum_range:6;
    };
}vdpq_frame_buf_chk3d_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  f_num_chk_3d_en:1;
        RBus_UInt32  f_num_3d_fail_det:1;
        RBus_UInt32  f_cennum_range:6;
    };
}vdpq_frame_buf_chk3d_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  f_num_open3d_cnt:4;
        RBus_UInt32  f_num_close3d_cnt:4;
    };
}vdpq_frame_buf_chk3d_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  f_cennum_valid_en:1;
        RBus_UInt32  f_cennum_valid1_en:1;
        RBus_UInt32  f_cennum_valid2_en:1;
    };
}vdpq_frame_buf_chk3d_cen_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  f_cennum_valid1_num:20;
    };
}vdpq_frame_buf_chk3d_cen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  f_cennum_valid2_num:20;
    };
}vdpq_frame_buf_chk3d_cen_num2_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  f_hennum_valid_en:1;
        RBus_UInt32  f_hennum_valid1_en:1;
    };
}vdpq_frame_buf_chk3d_hen_num1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  f_hennum_valid1_num:20;
    };
}vdpq_frame_buf_chk3d_hen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_st1:10;
    };
}vdpq_dma_vactive_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_end1:10;
    };
}vdpq_dma_vactive_end1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_st2:10;
    };
}vdpq_dma_vactive_st2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_end2:10;
    };
}vdpq_dma_vactive_end2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dma_ctrl_ififo_thr:6;
    };
}vdpq_dma_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dma_ctrl_ofifo_thr:6;
    };
}vdpq_dma_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dma_ctrl_ceiladr:6;
    };
}vdpq_dma_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_3d_on_off:1;
        RBus_UInt32  ntsc443_tune:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_vcnt_diff:10;
        RBus_UInt32  dma_vcnt_sft_chk_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_vcnt_sft_thr:5;
        RBus_UInt32  dma_3d_on_vcnt:5;
        RBus_UInt32  dma_ctrl_bstlen:3;
    };
}vdpq_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ofifo_err_flag:1;
        RBus_UInt32  ififo_err_flag_1:1;
        RBus_UInt32  ififo_err_flag_2:1;
        RBus_UInt32  ififo_err_flag_3:1;
        RBus_UInt32  ififo_err_flag_4:1;
        RBus_UInt32  mem_off:1;
        RBus_UInt32  mem_test_mode:1;
        RBus_UInt32  mem_test_mode_ok:1;
    };
}vdpq_dma_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_field_inv:1;
        RBus_UInt32  dma_adc_in_en:1;
        RBus_UInt32  dma_adc_in_sel:1;
    };
}vdpq_dma_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dma_debugif_stline_en:1;
        RBus_UInt32  dma_debugif_stline:10;
    };
}vdpq_debug_dma_if_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vlpf_sram_bypass:1;
        RBus_UInt32  vd_sram_on_off:1;
    };
}vdpq_vd_sram_on_off_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr0:29;
    };
}vdpq_mem0_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr1:29;
    };
}vdpq_mem1_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr2:29;
    };
}vdpq_mem2_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr3:29;
    };
}vdpq_mem3_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr0_end:29;
    };
}vdpq_mem0_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr1_end:29;
    };
}vdpq_mem1_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr2_end:29;
    };
}vdpq_mem2_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr3_end:29;
    };
}vdpq_mem3_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_debug_adr:29;
    };
}vdpq_dma_debug_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_debug_vbiend_adr:29;
    };
}vdpq_dma_debug_vbi_end_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  debugdma_outfifo_full:1;
        RBus_UInt32  debugdma_outfifo_empty:1;
        RBus_UInt32  dma_debug_vd_sel:4;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  dma_debugmode_sel:2;
        RBus_UInt32  dma_debugmode_en:1;
    };
}vdpq_video_dma_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_debug_one_rw_rlt:1;
        RBus_UInt32  dma_debug_rw_en:2;
        RBus_UInt32  res2:4;
    };
}vdpq_vbidma_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_delay_hsync_en:1;
        RBus_UInt32  chase_line_pos_en:2;
        RBus_UInt32  calib_delay_frame_sel:1;
        RBus_UInt32  calib_delay_sel:1;
        RBus_UInt32  calib_delay_en:1;
        RBus_UInt32  dma_pix_sht_fix_en:1;
        RBus_UInt32  chase_per_frame_en:1;
        RBus_UInt32  chase_pix_num:4;
        RBus_UInt32  pix_sht_st_th:20;
    };
}vdpq_dma_cnt_calibration1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fscnum_dif_abs_sel:2;
        RBus_UInt32  pix_sht_limit_en:1;
        RBus_UInt32  pix_sht_limit_th:8;
        RBus_UInt32  pix_sht_end_th:20;
    };
}vdpq_dma_cnt_calibration2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fscdif_num_abs:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  fscdif_sum_abs:20;
    };
}vdpq_dma_cnt_calibration3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  f1_cennum:16;
    };
}vdpq_frame_buffer_f1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  f2_cennum:16;
    };
}vdpq_frame_buffer_f2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:32;
    };
}vdpq_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:32;
    };
}vdpq_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yc3d_tb_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  ycsep_rdsel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  yc_linebf_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  adaptive_mode:3;
    };
}vdpq_yc_sep_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  wide_bpf_sel_y:4;
        RBus_UInt32  mid_bpf_sel_y:4;
        RBus_UInt32  narrow_bpf_sel_y:4;
    };
}vdpq_bpf_bw_sel_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  wide_bpf_sel_c:4;
        RBus_UInt32  mid_bpf_sel_c:4;
        RBus_UInt32  narrow_bpf_sel_c:4;
    };
}vdpq_bpf_bw_sel_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_lk_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  v2v_lk_y_en:1;
        RBus_UInt32  v2v_lk_c_en:1;
        RBus_UInt32  h2v_mid_sel_y:1;
        RBus_UInt32  h2v_mid_sel_c:1;
        RBus_UInt32  h2v_near_sel_y:1;
        RBus_UInt32  h2v_near_sel_c:1;
    };
}vdpq_adap_bpf_c_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_vflag_remag_thr:4;
        RBus_UInt32  h2v_vflag_mag_thr:4;
    };
}vdpq_adap_bpf_c_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pal_perr:1;
        RBus_UInt32  pal_perr_auto_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  palsw_level:2;
    };
}vdpq_comb_filter_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  noise_ntsc_c:8;
    };
}vdpq_comb_filter_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  malpha_c_divider2_sel:1;
        RBus_UInt32  malpha_y_divider2_sel:1;
        RBus_UInt32  malpha_y_en:1;
        RBus_UInt32  malpha_y:1;
        RBus_UInt32  malpha_c_en:1;
        RBus_UInt32  malpha_c:1;
        RBus_UInt32  yalpha_en:1;
        RBus_UInt32  yalpha:1;
    };
}vdpq_adap_bpf_y_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  chroma_vlpf_round_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pal_demod_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_vlpf_en:1;
        RBus_UInt32  chroma_bw_lo:3;
    };
}vdpq_yc_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  debug_mode_2d_en:1;
        RBus_UInt32  debug_mode_2d:4;
    };
}vdpq_debug_2d_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bw_gain_sel:2;
        RBus_UInt32  bw_detect_thr:6;
    };
}vdpq_bw_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bw_edge_thr:8;
    };
}vdpq_bw_edge_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  same_phase_diff_1d_gauge_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  blend_1d_thr:5;
        RBus_UInt32  bpf_1d_sel_y:2;
    };
}vdpq_blend_1d_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  narrow_1d_bpf_sel_c:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  wide_1d_bpf_sel_c:3;
    };
}vdpq_blend_1d_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_halpha_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  halpha:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  lut_large_th:5;
        RBus_UInt32  lut_fuzzy_th:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  lut_sel_y:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  lut_sel_c:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  h2v_coring_thr:3;
    };
}vdpq_alpha_2d_mod_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  h2v_lut_hprefer_ratio:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  h2v_lut_hv_large_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  h2v_cvbs_coring_thr:3;
        RBus_UInt32  h2v_bw_color_gain:4;
    };
}vdpq_h2v_coring_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_y_noise_thr:8;
    };
}vdpq_h2v_y_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_cvbs_noise_thr:8;
    };
}vdpq_h2v_cvbs_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_noise_max_hdy:8;
    };
}vdpq_h2v_noise_max_hdy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  v2v_lut_sel_y:1;
        RBus_UInt32  v2v_noise_y_add_dc:8;
    };
}vdpq_h2v_noise_y_add_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  h2v_blendratio:3;
    };
}vdpq_h2v_blend_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xc_sel_gain:2;
        RBus_UInt32  res2:6;
    };
}vdpq_adap_bpf_y_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cdiff_bpf_mm_small_th:6;
        RBus_UInt32  cdiff_bpf_mm_diff_th:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_bpf_hor_range:1;
        RBus_UInt32  cdiff_bpf_ver_range:1;
        RBus_UInt32  res3:4;
    };
}vdpq_cdiff_adap_bpf_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cdiff_bpf_vspd_small_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_bpf_low_sat_th:6;
        RBus_UInt32  cdiff_bpf_large_offset:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  cdiff_bpf_large_amp_wei:3;
        RBus_UInt32  cdiff_bpf_small_offset:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  cdiff_bpf_small_amp_wei:3;
    };
}vdpq_cdiff_adap_bpf_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hvdiff_comp_offset:8;
        RBus_UInt32  hvdiff_comp_multiple:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_tolerance:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vedge_en:1;
    };
}vdpq_bpf_vedge_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  c_follow_y_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdiff_lowbound:7;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_upbound:5;
    };
}vdpq_bpf_vedge_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_diff_ratio:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  lr_diff_lower_th:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  lr_diff_th:7;
        RBus_UInt32  complex_level_th:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  complex_level_mode_sel:1;
        RBus_UInt32  bypassbpf_adap_en:1;
    };
}vdpq_bypass_bpf_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  newvedge_lr_diff_th:7;
        RBus_UInt32  newvedge_vdiff_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  newvedge_vdiff_th:7;
        RBus_UInt32  lr_ratio_th:4;
    };
}vdpq_bypass_bpf_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode_gridgirl:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  grid_cvbs_diff_th:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  gridgirl_corr_en:1;
        RBus_UInt32  grid_reset_sel:1;
        RBus_UInt32  grid_use_preflag_en:1;
        RBus_UInt32  gridgirl_en:1;
    };
}vdpq_gridgirl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_chroma_th2:8;
        RBus_UInt32  grid_chroma_th1:8;
        RBus_UInt32  grid_hordiff_th2:8;
        RBus_UInt32  grid_hordiff_th1:8;
    };
}vdpq_gridgirl_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_linecnt_th2:8;
        RBus_UInt32  grid_linecnt_th1:8;
        RBus_UInt32  grid_linesum_th2:8;
        RBus_UInt32  grid_linesum_th1:8;
    };
}vdpq_gridgirl_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_sum_right_bound:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  grid_sum_left_bound:11;
    };
}vdpq_gridgirl_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_right_bound:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  grid_left_bound:11;
    };
}vdpq_gridgirl_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vmc_widehspd_small_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diamc_cvbsamp_still_th:6;
    };
}vdpq_diamc_cvbs_amp_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diamc_dc_still_th_offset:6;
        RBus_UInt32  diamc_dc_still_th_weight:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  diamc_y_v_line_id_cnt_th:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  diamc_fid_th_weight:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  diamc_amp_low_bnd:7;
        RBus_UInt32  res5:1;
        RBus_UInt32  diamc_all_line_match_en:1;
        RBus_UInt32  diamc_perfect_fid_en:1;
        RBus_UInt32  diamc_en:1;
    };
}vdpq_diamc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ver_cvbsamp_still_th:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  vmc_cfollowy_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_dc_still_th:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  amp_low_bnd:6;
        RBus_UInt32  res5:1;
        RBus_UInt32  slant_det_en:1;
        RBus_UInt32  perfect_fid_en:1;
        RBus_UInt32  vmc_en:1;
    };
}vdpq_vmc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  offset_2:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  offset_1:2;
        RBus_UInt32  cnt_th_2:4;
        RBus_UInt32  cnt_th_1:4;
    };
}vdpq_vmc_spatial_corr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  postlpf_dia_en:1;
        RBus_UInt32  postlpf_grad_en:1;
        RBus_UInt32  postlpf_force_en:1;
        RBus_UInt32  postlpf_en:1;
    };
}vdpq_yc2d_postlp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  low_amp_th_3:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  low_amp_th_2:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  low_amp_th_1:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  low_amp_th_0:5;
    };
}vdpq_yc2d_postlp_flat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_th_2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hdiff_th_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hdiff_th_0:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  low_amp_th_4:5;
    };
}vdpq_yc2d_postlp_flat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hdiff_th_4:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdiff_th_3:5;
    };
}vdpq_yc2d_postlp_flat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  vdiff_th_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_3:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_2:5;
    };
}vdpq_yc2d_postlp_flat_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  larger_cnt_th_1:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  smaller_cnt_th_0:2;
        RBus_UInt32  larger_cnt_th_0:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  grad_flat_th_ratio:5;
        RBus_UInt32  grad_flat_th_offset:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  grad_flat_th_upbnd:5;
    };
}vdpq_yc2d_postlp_grad_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  vdiff_th_1_grad:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0_grad:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  low_amp_th_grad_offset:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  smaller_cnt_th_1:2;
    };
}vdpq_yc2d_postlp_grad_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  vdiff_th_3_grad:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_2_grad:5;
    };
}vdpq_yc2d_postlp_grad_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  spd_large_ratio:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  spd_large_th:6;
        RBus_UInt32  low_amp_th_dia_offset:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  smaller_cnt_th_dia:2;
        RBus_UInt32  larger_cnt_th_dia:4;
    };
}vdpq_yc2d_postlp_dia_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  dia_grad_flat_th_ratio:5;
        RBus_UInt32  dia_grad_flat_th_offset:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dia_grad_flat_th_upbnd:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  spd_diff_th:7;
    };
}vdpq_yc2d_postlp_dia_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_3_dia:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_2_dia:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_1_dia:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  vdiff_th_0_dia:5;
    };
}vdpq_yc2d_postlp_dia_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dia_cedge_th:6;
    };
}vdpq_yc2d_postlp_dia_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demodphase_fix_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  demodphase_fix:2;
        RBus_UInt32  res2:19;
        RBus_UInt32  pal_mod_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  yc_sep_mode:2;
    };
}vdpq_yc_sep_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:32;
    };
}vdpq_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  yc3d_cchroma_bpf_sel:1;
        RBus_UInt32  yc3d_ychroma_bpf_sel:1;
        RBus_UInt32  res2:6;
    };
}vdpq_yc_3dsep_chroma_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  malpha_delay_4fsc:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  alpha2d3d_delay_4fsc:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  y_delay_4fsc:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  cb_delay_4fsc:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  cr_delay_4fsc:2;
    };
}vdpq_yc_sep_yuv_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  monotone_flat_cnt_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  monotone_flat_th:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  monotone_edge_th:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  slp_monotone_en:1;
    };
}vdpq_yc_3d_f4_slp_mono_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slp_cnt:16;
        RBus_UInt32  hor_c_change_cnt:16;
    };
}vdpq_yc_3d_f4_stat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  stat_tempspd_small_th:7;
        RBus_UInt32  tempspd_small_cnt:16;
    };
}vdpq_yc_3d_f4_stat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  stat_hifreqdiff_not_small_th:8;
        RBus_UInt32  hifreqdiff_not_small_cnt:16;
    };
}vdpq_yc_3d_f4_stat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_hfd_diff_large_ratio:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  sc_hfd_diff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  sc_hfd_diff_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  slp_offset:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  slp_en:1;
    };
}vdpq_yc_3d_f4_slp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cvbs_match_cnt_th_hvspd:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  large_hvspd_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  dc_still_th:7;
        RBus_UInt32  match_cnt_th:4;
    };
}vdpq_yc_3d_f4_slp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cvbsamp_ratio:3;
        RBus_UInt32  cvbsamp_th:4;
        RBus_UInt32  cvbsamp_diff_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cvbsamp_diff_th:7;
        RBus_UInt32  cvbs_match_cnt_th:4;
    };
}vdpq_yc_3d_f4_slp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  aba_dc_change_th:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  aba_aa_diff_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  aba_hifreqdiff_th:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  ntsc_aba_en:1;
    };
}vdpq_yc_3d_f4_ntsc_aba_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  aba_cvbsamp_multiple:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  aba_cvbsamp_aa_th:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  aba_cvbsamp_ab_th:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  aba_dc_multiple:5;
    };
}vdpq_yc_3d_f4_ntsc_aba_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:32;
    };
}vdpq_dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  f4_global_diff_dbg_sftbit:2;
        RBus_UInt32  f4_dbg_highfreq_diff_th:8;
        RBus_UInt32  f4_dbg_cvbs_amp_th:8;
        RBus_UInt32  f4_dbg_value_mode_enable:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  f4_debug_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  f4_debug_mode_sel:5;
    };
}vdpq_yc_3d_f4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cvbs_amp_change_th:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_5:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_4:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_3:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_2:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_1:4;
    };
}vdpq_yc_3d_f4_spa_cnt_cvbs_amp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  hv_cvbs_diff_large_multiple_th:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hv_diff_large_multiple_th:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  hv_diff_large_offset_th:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  hv_local_diff_comp_ratio:3;
        RBus_UInt32  hv_diff_tolerance:4;
    };
}vdpq_yc_3d_f4_hv_edge_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  h_diff_normalize_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  hv_edge_c_diff_small_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hv_edge_c_diff_small_en:1;
    };
}vdpq_yc_3d_f4_hv_edge_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hor_c_postp_mode:2;
        RBus_UInt32  hifreq_postp_mode:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  f4_fill_hole_neightbor_diff_th:6;
        RBus_UInt32  f4_hor_chifreq_range:1;
        RBus_UInt32  f4_ver_chifreq_range:1;
        RBus_UInt32  f4_hor_hifreq_range:1;
        RBus_UInt32  f4_ver_hifreq_usepalmode:1;
    };
}vdpq_yc_3d_f4_hifreq_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dc_level_change_th_multiple:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  dc_level_change_th_base:6;
    };
}vdpq_yc_3d_f4_dc_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  similary_th_base:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  similary_th_multiple:5;
        RBus_UInt32  palerr_accu_tolerance:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  palerr_hifreq_diff_large_th:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  pal_error_detect_en:1;
    };
}vdpq_yc_3d_f4_pal_err_com_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_of_spd_small_th_base:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_of_spd_small_th_multiple:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  massive_palmode_error_multiple_th:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  massive_palmode_error_large_th:7;
    };
}vdpq_yc_3d_f4_pal_err_com_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4f0_still_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  palerr_massive_tolerance:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  f4f0_still_th_weight:6;
        RBus_UInt32  f4f0_still_th_offset:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  f4f0_still_th_upbnd:5;
    };
}vdpq_yc_3d_f4_pal_err_com_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_avg_dynamic_en:1;
        RBus_UInt32  sv_longtime_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  sv_vector_fid_match_cnt_th:5;
        RBus_UInt32  sv_vector_fid_offset:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_vector_large_cnt_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  sv_vector_large_th:5;
    };
}vdpq_yc_3d_f4_still_vector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sv_self_diff_small_th:7;
    };
}vdpq_yc_3d_f4_still_vector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  sghf_inter_diff_th:7;
        RBus_UInt32  sghf_global_diff_small_th:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  sghf_longtime_en:1;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sghf_avg_dynamic_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  sghf_vector_fid_match_cnt_th:5;
        RBus_UInt32  sghf_vector_fid_offset:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  sghf_vector_large_cnt_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  sghf_vector_large_th:5;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_140:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_160:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_180:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  diff_th_multiple_200:5;
    };
}vdpq_yc_3d_f4_pair_th_multiple_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_60:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_80:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_100:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  diff_th_multiple_120:5;
    };
}vdpq_yc_3d_f4_pair_th_multiple_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_10:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_20:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  diff_th_multiple_40:5;
    };
}vdpq_yc_3d_f4_pair_th_multiple_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_140:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_160:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_180:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  diff_th_base_200:6;
    };
}vdpq_yc_3d_f4_pair_th_base_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_60:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_80:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_100:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  diff_th_base_120:6;
    };
}vdpq_yc_3d_f4_pair_th_base_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_20:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  diff_th_base_40:6;
    };
}vdpq_yc_3d_f4_pair_th_base_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hv_offset:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  still_vector_offset_multiple:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  still_vector_offset_base:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pal_error_offset:6;
        RBus_UInt32  res5:1;
        RBus_UInt32  hor_c_diff_dpo_hedge_rshift_bit:3;
    };
}vdpq_yc_3d_f4_pair_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  still_vector_avoid_aba_hifreq_enable:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  still_vector_cvbs_amp_change_offset:6;
        RBus_UInt32  still_vector_hifreq_diff_th_shift_bit:2;
        RBus_UInt32  still_vector_hifreq_diff_th:6;
    };
}vdpq_yc_3d_f4_pair_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  later_diff_upper_bound:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pair_diff_sel_th:7;
        RBus_UInt32  res3:3;
        RBus_UInt32  highfreq_diff_low_border:5;
        RBus_UInt32  flat_offset:4;
    };
}vdpq_yc_3d_f4_pair_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  diff_th_upper_bound:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_lower_bound:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_2d_comp_3d_offset:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  hvdiff_border:6;
    };
}vdpq_yc_3d_f4_pair_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  still_gray_hifreq_th:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_gray_hifreq_low_border:6;
        RBus_UInt32  res3:3;
        RBus_UInt32  still_gray_hifreq_enable:1;
    };
}vdpq_yc_3d_f4_pair_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  global_diff_tolerance:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  global_diff_offset_dc_fierce_change:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  dc_level_fierce_change_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  hdy_small_th:6;
    };
}vdpq_yc_3d_f4_pair_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_120:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_140:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_160:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  global_diff_th_hifreq_offset_180:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_60:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_70:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_80:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  global_diff_th_hifreq_offset_100:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_40:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  global_diff_th_hifreq_offset_50:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  global_diff_th_hifreq_offset_5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_0:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_10:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  moving_vline_ver_dc_level_fierce_change_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  moving_vline_flat_ver_cvbs_th:5;
        RBus_UInt32  mghf_flag:1;
        RBus_UInt32  mghf_enable:1;
        RBus_UInt32  moving_vline_en:1;
        RBus_UInt32  dc_level_hor_dc_check_en:1;
    };
}vdpq_yc_3d_f4_mghf_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  large_hifreq_diff_ratio:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_c_change_ratio:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  hifreq_diff_large_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  cvbs_still_th:5;
        RBus_UInt32  res5:3;
        RBus_UInt32  hor_c_change_th:5;
    };
}vdpq_yc_3d_f4_mghf_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  diff_th_multiple_5:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_5:6;
    };
}vdpq_yc_3d_f4_global_diff_th_com_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diadiff_vspd_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diadiff_small_upbnd:6;
        RBus_UInt32  diadiff_small_weight:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  diadiff_small_base:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  dbwline_en:1;
    };
}vdpq_yc_post2dbpf_dbwline_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dbwline_d45_hspd_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  dbwline_hspd_small_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  dbwline_hor_cdiff_th:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  low_sat_th:6;
    };
}vdpq_yc_post2dbpf_dbwline_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dbwline_d45_diadiff_small_th:7;
    };
}vdpq_yc_post2dbpf_dbwline_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  gremove_c_small_th:5;
        RBus_UInt32  gremove_bpfedc_small_th:4;
        RBus_UInt32  weight_2d_c:2;
        RBus_UInt32  weight_bld_c:2;
        RBus_UInt32  weight_3d_c:2;
        RBus_UInt32  weight_2d_y:2;
        RBus_UInt32  weight_bld_y:2;
        RBus_UInt32  weight_3d_y:2;
        RBus_UInt32  mghf_narrowbpf_en:1;
        RBus_UInt32  greenish_detected_en:1;
        RBus_UInt32  post2dbpf_c_en:1;
        RBus_UInt32  post2dbpf_y_en:1;
    };
}vdpq_yc_post2dbpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  hor_cdiff_th_base:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ver_cdiff_th_base:7;
    };
}vdpq_yc_post2dbpf_thbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  bpfed_c_diff_small_th:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  dual_ch_bpfedc_small_th:5;
        RBus_UInt32  dual_ch_bpfedcdiff_large_ratio:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  dual_ch_bpfedcdiff_large_th:5;
    };
}vdpq_yc_post2dbpf_adapth_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  bpfed_c_diff_large_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  bpfed_c_diff_large_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bpfed_c_diff_small_hor_offset:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  bpfed_c_diff_small_ver_offset:7;
    };
}vdpq_yc_post2dbpf_adapth_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  neighbor_vdiff_small_hor_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  neighbor_hdiff_small_ver_offset:6;
        RBus_UInt32  res3:3;
        RBus_UInt32  vspd_small_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdy_spd_small_th:5;
    };
}vdpq_yc_post2dbpf_adapth_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hvedge_diff_large_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  vspd_large_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  hdy_spd_large_th:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdiff_tolerance:5;
    };
}vdpq_yc_post2dbpf_adapth_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  vedge_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  hedge_ver_offset:7;
    };
}vdpq_yc_post2dbpf_adapth_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dia_spd_large_ver_offset:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  dia_spd_large_th_small_hordiff_th:6;
        RBus_UInt32  dia_spd_large_th_small_hordiff_offset:8;
        RBus_UInt32  dia_spd_large_th_base:8;
    };
}vdpq_yc_post2dbpf_adapth_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  dual_ch_c_small_th:5;
        RBus_UInt32  dual_ch_cdiff_large_ratio:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dual_ch_cdiff_large_th:5;
    };
}vdpq_yc_post2dbpf_adapth_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hdiff_much_larger_ratio:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  hdiff_much_larger_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hdiff_vdiff_diff_larger_th:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  hdiff_large_th:7;
    };
}vdpq_yc_post2dbpf_adapth_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_color_tran_ver_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ver_color_tran_ver_cdiff_small_th:7;
        RBus_UInt32  res3:2;
        RBus_UInt32  ver_color_tran_hdiff_large_th:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  hdiff_much_larger_hor_offset:7;
    };
}vdpq_yc_post2dbpf_adapth_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  colorbar_detect_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  colorbar_detect_ver_offset:7;
        RBus_UInt32  res3:2;
        RBus_UInt32  colorbar_hdiff_large_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  colorbar_vdiff_small_th:6;
    };
}vdpq_yc_post2dbpf_adapth_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_avoid_th_c:4;
        RBus_UInt32  ver_avoid_th_y:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  smooth_detect_ver_offset:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  smooth_hdiff_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  smooth_vdiff_small_th:6;
    };
}vdpq_yc_post2dbpf_adapth_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vedge_avoid_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vcdiff_large_diff_th:6;
        RBus_UInt32  vcdiff_large_ratio:4;
        RBus_UInt32  v2sides_diff_large_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  v2sides_diff_large_th:7;
        RBus_UInt32  res3:3;
        RBus_UInt32  v2sides_gray_diff_small_th:5;
    };
}vdpq_yc_post2dbpf_adapth_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  upbnd:8;
        RBus_UInt32  hedge_ratio_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  hedge_bypass_en:1;
        RBus_UInt32  ignore_th_c:4;
        RBus_UInt32  ignore_th_y:4;
    };
}vdpq_yc_post2dbpf_adapth_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xc_hvedge_avoid_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  xc_cdiff_upbnd:6;
        RBus_UInt32  xc_hvedge_ratio_th_2:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  xc_hvedge_th_2:5;
        RBus_UInt32  xc_hvedge_ratio_th_1:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  xc_hvedge_th_1:5;
    };
}vdpq_yc_post2dbpf_xc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  yadap_hpf_sel:2;
        RBus_UInt32  yadap_peak_mode:2;
    };
}vdpq_secam_yadap_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  yadap_peak_gain:4;
        RBus_UInt32  yadap_peak_th:4;
    };
}vdpq_secam_yadap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  yadap_peak_gain_2d:4;
        RBus_UInt32  yadap_uniform_gain:4;
    };
}vdpq_secam_yadap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpq_alphadelay_indep_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  postpq_alphadelay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  postpq_malphadelay:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  xnr_lpf_sel:2;
        RBus_UInt32  xnr_vlpf_sel:2;
        RBus_UInt32  xnr_blend_dbm:1;
        RBus_UInt32  xnr_blend_en:1;
        RBus_UInt32  xnr_det_bypass_en:1;
        RBus_UInt32  xnr_en:1;
    };
}vdpq_xnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xnr_cdiff_thr:4;
        RBus_UInt32  xnr_csum_thr:4;
    };
}vdpq_xnr_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xnr_idxgain:4;
        RBus_UInt32  xnr_ver_idxgain:4;
    };
}vdpq_xnr_idx_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xnr_ver_ratio:4;
        RBus_UInt32  xnr_ver_ratio_w:4;
    };
}vdpq_xnr_ratio_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_cedge_sum_th:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_cedge_single_th:6;
        RBus_UInt32  ver_cedge_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  mf_en:1;
        RBus_UInt32  ma0_cnt_th:5;
        RBus_UInt32  point_type_coring_lv:4;
        RBus_UInt32  vline_len_3_sel:1;
        RBus_UInt32  vline_con_en:1;
        RBus_UInt32  cdiff_small_con_en:1;
        RBus_UInt32  ma0_con_en:1;
    };
}vdpq_postp_mf_compensation_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cdiff_small_sum_th:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_small_single_th:6;
        RBus_UInt32  cdiff_small_len:4;
    };
}vdpq_postp_mf_compensation_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  postpk_prelpf_mode:1;
        RBus_UInt32  postpk_prelpf_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  postpk_alphablend_en:1;
        RBus_UInt32  postpk_dnoise_en:1;
        RBus_UInt32  postpk_adap_mode:2;
        RBus_UInt32  postpk_adappk_en:1;
        RBus_UInt32  postpk_en:1;
    };
}vdpq_yc2d_postpk2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  postpk_c_stepbit:3;
        RBus_UInt32  postpk_c_lwbnd:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  postpk_y_stepbit:3;
        RBus_UInt32  postpk_y_lwbnd:8;
    };
}vdpq_yc2d_postpk2_adap1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  postpk_lv_upbnd:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  postpk_lv_sft:3;
        RBus_UInt32  postpk_lv_th:8;
    };
}vdpq_yc2d_postpk2_dnoise1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  postpk_c0:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  postpk_c1:9;
        RBus_UInt32  postpk_c2:8;
    };
}vdpq_yc2d_postpk2_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  postpk_gain_pos:8;
        RBus_UInt32  postpk_gain_neg:8;
    };
}vdpq_yc2d_postpk2_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  postpk_hv_pos:10;
        RBus_UInt32  postpk_hv_neg:10;
        RBus_UInt32  postpk_lv:8;
    };
}vdpq_yc2d_postpk2_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_ffd2_ratio:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlti_ffd2_en:1;
        RBus_UInt32  dlti_ffd1_ratio:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti_ffd1_th:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  dlti_maxlen:3;
        RBus_UInt32  dlti_pnth:7;
        RBus_UInt32  dlti_en:1;
    };
}vdpq_postp_dlti_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_d1_cp_shift:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  dlti_dcp_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti_tn_blend_mode:1;
        RBus_UInt32  dlti_tn_blend_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dlti_ovc_en:1;
        RBus_UInt32  dlti_can_shift:4;
        RBus_UInt32  dlti_ffd2_range2l:4;
        RBus_UInt32  dlti_ffd2_range2r:4;
    };
}vdpq_postp_dlti_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_cchange_srcwei_offset_2:4;
        RBus_UInt32  dlti_cchange_srcwei_offset_1:4;
        RBus_UInt32  dlti_uv_diff_th_2:8;
        RBus_UInt32  dlti_uv_diff_th_1:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  dlti_cchange_len:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti_cchange_corr_en:1;
    };
}vdpq_postp_dlti_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tngain7:4;
        RBus_UInt32  dlti_tngain6:4;
        RBus_UInt32  dlti_tngain5:4;
        RBus_UInt32  dlti_tngain4:4;
        RBus_UInt32  dlti_tngain3:4;
        RBus_UInt32  dlti_tngain2:4;
        RBus_UInt32  dlti_tngain1:4;
        RBus_UInt32  dlti_tngain0:4;
    };
}vdpq_postp_dlti_tngain_gain_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dlti_tngain14:4;
        RBus_UInt32  dlti_tngain13:4;
        RBus_UInt32  dlti_tngain12:4;
        RBus_UInt32  dlti_tngain11:4;
        RBus_UInt32  dlti_tngain10:4;
        RBus_UInt32  dlti_tngain9:4;
        RBus_UInt32  dlti_tngain8:4;
    };
}vdpq_postp_dlti_tngain_gain_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tnoffset7:4;
        RBus_UInt32  dlti_tnoffset6:4;
        RBus_UInt32  dlti_tnoffset5:4;
        RBus_UInt32  dlti_tnoffset4:4;
        RBus_UInt32  dlti_tnoffset3:4;
        RBus_UInt32  dlti_tnoffset2:4;
        RBus_UInt32  dlti_tnoffset1:4;
        RBus_UInt32  dlti_tnoffset0:4;
    };
}vdpq_postp_dlti_tngain_offset_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dlti_tnoffset14:4;
        RBus_UInt32  dlti_tnoffset13:4;
        RBus_UInt32  dlti_tnoffset12:4;
        RBus_UInt32  dlti_tnoffset11:4;
        RBus_UInt32  dlti_tnoffset10:4;
        RBus_UInt32  dlti_tnoffset9:4;
        RBus_UInt32  dlti_tnoffset8:4;
    };
}vdpq_postp_dlti_tngain_offset_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pd_sel_dlti_cnt_th2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pd_sel_dlti_cnt_th1:3;
        RBus_UInt32  pd_sel_dlti_diff_th:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  pd_sel:3;
    };
}vdpq_postp_dlti_pk_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pk_alpha_2d_weight:2;
        RBus_UInt32  pk_alpha_bld_weight:2;
        RBus_UInt32  pk_alpha_3d_weight:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti_alpha_2d_weight:2;
        RBus_UInt32  dlti_alpha_bld_weight:2;
        RBus_UInt32  dlti_alpha_3d_weight:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  xnr_alpha_2d_weight:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  xnr_alpha_bld_weight:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  xnr_alpha_3d_weight:3;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alphablend_round_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  snr_alpha_2d_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  snr_alpha_bld_weight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  snr_alpha_3d_weight:3;
        RBus_UInt32  notch_force_upbnd:8;
        RBus_UInt32  notch_force_3dweight:4;
        RBus_UInt32  res4:2;
        RBus_UInt32  mfnotch_alpha_2d_weight:2;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ntsc443_lpf:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  ntsc443_lpf_ext:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ntsc443_lpf_th_y:3;
    };
}vdpq_postp_ntsc443_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  cp_sweightydebug:2;
    };
}vdpq_spnr_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_sresultweight:3;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  res2:14;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  cp_spatialenabley:1;
    };
}vdpq_spnr_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  cp_spatialthlyx2:8;
        RBus_UInt32  cp_spatialthly:8;
    };
}vdpq_spnr_spatial_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  cp_weight1y:4;
        RBus_UInt32  cp_weight2y:4;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  res3:7;
    };
}vdpq_spnr_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_status:32;
    };
}vdpq_dummy_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_sw_edge_thl:16;
        RBus_UInt32  res1:14;
        RBus_UInt32  cp_edge_weight:2;
    };
}vdpq_spnr_local_var2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  notch_upbnd_offset:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  notch_upbnd_weight:5;
        RBus_UInt32  notch_upbnd_upbnd:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  notch_en:1;
    };
}vdpq_notch_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  large_notchy_amp_th:6;
        RBus_UInt32  high_sat_weight_undo:4;
        RBus_UInt32  high_sat_weight_do:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  high_sat_lowbnd:6;
        RBus_UInt32  res3:3;
        RBus_UInt32  notch_lowbnd:5;
    };
}vdpq_notch_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  very_nonmonotone_weight_undo:4;
        RBus_UInt32  very_nonmonotone_weight_do:4;
        RBus_UInt32  very_diff_large_weight_undo:4;
        RBus_UInt32  very_diff_large_weight_do:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  very_diff_large_th:6;
        RBus_UInt32  large_notchy_amp_weight_undo:4;
        RBus_UInt32  large_notchy_amp_weight_do:4;
    };
}vdpq_notch_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  force_notch_weight:4;
        RBus_UInt32  vline_weight_undo:4;
        RBus_UInt32  large_cdiff_weight_undo:4;
        RBus_UInt32  large_cdiff_weight_do:4;
        RBus_UInt32  large_cdiff_th:8;
    };
}vdpq_notch_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_0:5;
        RBus_UInt32  res2:24;
    };
}vdpq_alpha_blending_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_2:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_3:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  alpha2d3d_bld_weight_4:5;
    };
}vdpq_alpha_blending_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_5:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_6:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_7:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  alpha2d3d_bld_weight_8:5;
    };
}vdpq_alpha_blending_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_9:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_10:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_11:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  alpha2d3d_bld_weight_12:5;
    };
}vdpq_alpha_blending_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_13:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_14:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_15:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  alpha2d3d_bld_weight_16:5;
    };
}vdpq_alpha_blending_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_enable:1;
        RBus_UInt32  iir_reset_clear:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  iir_reset_value:8;
        RBus_UInt32  ts_multiple:4;
        RBus_UInt32  ts_alpha_gain:4;
        RBus_UInt32  ts_alpha_offset:4;
    };
}vdpq_alpha_temporal_smooth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpq_alphablend_dbm:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  xc_blend_en:1;
        RBus_UInt32  de_xc_en:1;
        RBus_UInt32  de_xc_thr:4;
    };
}vdpq_de_xc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cnr_lpf_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cnr_en:1;
    };
}vdpq_cnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  cadap_spatial_lpf_out:1;
        RBus_UInt32  cadap_clpf_en:1;
        RBus_UInt32  cadap_ylpf_en:1;
        RBus_UInt32  cadap_uvsync_en:1;
        RBus_UInt32  cadap_yuvsync_en:1;
        RBus_UInt32  cadap_cti_en:1;
    };
}vdpq_cadap_enable_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cadap_uni_gain_ctrl_en:1;
        RBus_UInt32  cadap_uv_sync_uni_en:1;
        RBus_UInt32  cadap_y_sync_uni_en:1;
    };
}vdpq_cadap_enable_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_gain:4;
        RBus_UInt32  cadap_level:4;
    };
}vdpq_cadap_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_zc_mag_th_y:4;
        RBus_UInt32  cadap_zc_mag_th_y_c:4;
    };
}vdpq_cadap_zc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_zc_mag_th_c:4;
        RBus_UInt32  cadap_dir_det_gain:4;
    };
}vdpq_cadap_zc_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_ver_uni_th:4;
        RBus_UInt32  cadap_dir_uni_th:4;
    };
}vdpq_cadap_ver_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_y_sync_uni_th:4;
        RBus_UInt32  cadap_uv_sync_uni_th:4;
    };
}vdpq_cadap_sync_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_lut_level_tha:4;
        RBus_UInt32  cadap_lut_level_thb:4;
    };
}vdpq_cadap_lut_level_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_lut_gain_tha:4;
        RBus_UInt32  cadap_lut_gain_thb:4;
    };
}vdpq_cadap_lut_gain_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_b1:11;
    };
}vdpq_dcti_filter_coef_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_b2:11;
    };
}vdpq_dcti_filter_coef_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_b3:11;
    };
}vdpq_dcti_filter_coef_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_a2:11;
    };
}vdpq_dcti_filter_coef_a2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_a3:11;
    };
}vdpq_dcti_filter_coef_a3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  dcti_filter_en:1;
    };
}vdpq_dcti_filter_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  smd_ver_10_move_enable:1;
        RBus_UInt32  smd_ver_08_move_enable:1;
        RBus_UInt32  smd_ver_06_move_enable:1;
        RBus_UInt32  smd_ver_04_move_enable:1;
        RBus_UInt32  smd_ver_02_move_enable:1;
        RBus_UInt32  smd_ver_00_move_enable:1;
        RBus_UInt32  smd_hor_10_move_enable:1;
        RBus_UInt32  smd_hor_08_move_enable:1;
        RBus_UInt32  smd_hor_06_move_enable:1;
        RBus_UInt32  smd_hor_04_move_enable:1;
        RBus_UInt32  smd_hor_02_move_enable:1;
        RBus_UInt32  smd_hor_00_move_enable:1;
        RBus_UInt32  smd_en:1;
    };
}vdpq_yc_3d_f4_smd_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_ver_spatial_temporal_traily_diff:8;
        RBus_UInt32  smd_hor_spatial_temporal_traily_diff:8;
        RBus_UInt32  smd_vertical_sad_tolerance:8;
        RBus_UInt32  smd_horizontal_sad_tolerance:8;
    };
}vdpq_yc_3d_f4_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_min_sad_vetical:8;
        RBus_UInt32  smd_min_sad_horizontal:8;
    };
}vdpq_yc_3d_f4_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_2d_small_global_diff_offset:16;
        RBus_UInt32  smd_highfreq_diff_2_th:8;
        RBus_UInt32  smd_highfreq_diff_th:8;
    };
}vdpq_yc_3d_f4_pair_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_2d_not_small_global_diff_offset:16;
    };
}vdpq_yc_3d_f4_pair_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_vm:32;
    };
}vdpq_ns_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  countv:16;
        RBus_UInt32  maxv:16;
    };
}vdpq_ns_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sumv:32;
    };
}vdpq_ns_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  nfactor:8;
        RBus_UInt32  vmm:16;
    };
}vdpq_ns_rw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  density:8;
        RBus_UInt32  meannxv:16;
    };
}vdpq_ns_rw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hsyncdebug_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pq_noisestatus_hsync_start:8;
        RBus_UInt32  pq_noisestatus_hsync_end:8;
    };
}vdpq_ns_gate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_uv_flag_en:1;
        RBus_UInt32  secam_fix_color_reduce_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_fix_line_grey_ratio:4;
        RBus_UInt32  secam_fix_grey_thd:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  secam_fix_debug_mode:3;
        RBus_UInt32  secam_fix_post_cvlpf_en:1;
        RBus_UInt32  secam_fix_pre_yvlpf_en:1;
        RBus_UInt32  secam_fix_color_reduce_ctrl:2;
    };
}vdpq_postp_secam_fix_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_y_flag_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  secam_fix_y_diff_thd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_fix_y_action_continue_d_time:6;
        RBus_UInt32  secam_fix_y_flag_ext_l:8;
        RBus_UInt32  secam_fix_y_flag_ext_r:8;
    };
}vdpq_postp_secam_fix_y_detect0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_fix_y_target_d3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_fix_y_target_d2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  secam_fix_y_target_d1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  secam_fix_y_target_d0:6;
    };
}vdpq_postp_secam_fix_y_detect1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir3d_fw_mode_enable:1;
        RBus_UInt32  dir3d_fw_mode_dalpha:4;
        RBus_UInt32  dir3d_fw_mode_motion:2;
        RBus_UInt32  dir3d_fw_mode_dalpha_c:4;
        RBus_UInt32  res1:20;
        RBus_UInt32  dir3d_enable:1;
    };
}vdpq_directional_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  windows_enable:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  windows_2d3d_blend_ratio:4;
    };
}vdpq_fix_window_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  windows_x_sta:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  windows_x_end:11;
    };
}vdpq_fix_window_posx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  windows_y_sta:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  windows_y_end:9;
    };
}vdpq_fix_window_posy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:32;
    };
}vdpq_dummy_5_RBUS;


typedef union
{
    RBus_UInt32 regValue;
    struct{
	RBus_UInt32  dummy_6_res:6;
	RBus_UInt32  dummy_6_VDPQ_AutoMA_bypass:1;
	RBus_UInt32  dummy_6_fix_VDPQTable_enable:1;
	RBus_UInt32  dummy_6_fix_status:2;
	RBus_UInt32  dummy_6_fix_mode:3;
	RBus_UInt32  dummy_6_reset_debug_cnt:1;
	RBus_UInt32  dummy_6_modechange_cnt:3;
	RBus_UInt32  dummy_6_3DPath_cnt:5;
	RBus_UInt32  dummy_6_2DPath_cnt:5;
	RBus_UInt32  dummy_6_1DPath_cnt:5;
    };
}vdpq_dummy_6_RBUS;


typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_7:32;
    };
}vdpq_dummy_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
	RBus_UInt32  dummy_8_res:17;
	RBus_UInt32  dummy_8_auto_disable:1;
	RBus_UInt32  dummy_8_set_scan_enable:1;
	RBus_UInt32  dummy_8_print_time:8;
	RBus_UInt32  dummy_8_log_enable:1;
	RBus_UInt32  dummy_8_motion_status:4;
    };
}vdpq_dummy_8_RBUS;


#else //apply LITTLE_ENDIAN

//======VDPQ register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_hennum_range:6;
        RBus_UInt32  f_num_chk_3d_sel:2;
        RBus_UInt32  res1:24;
    };
}vdpq_frame_buf_chk3d_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_range:6;
        RBus_UInt32  f_num_3d_fail_det:1;
        RBus_UInt32  f_num_chk_3d_en:1;
        RBus_UInt32  res1:24;
    };
}vdpq_frame_buf_chk3d_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_num_close3d_cnt:4;
        RBus_UInt32  f_num_open3d_cnt:4;
        RBus_UInt32  res1:24;
    };
}vdpq_frame_buf_chk3d_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_valid2_en:1;
        RBus_UInt32  f_cennum_valid1_en:1;
        RBus_UInt32  f_cennum_valid_en:1;
        RBus_UInt32  res1:29;
    };
}vdpq_frame_buf_chk3d_cen_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_valid1_num:20;
        RBus_UInt32  res1:12;
    };
}vdpq_frame_buf_chk3d_cen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_valid2_num:20;
        RBus_UInt32  res1:12;
    };
}vdpq_frame_buf_chk3d_cen_num2_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_hennum_valid1_en:1;
        RBus_UInt32  f_hennum_valid_en:1;
        RBus_UInt32  res1:30;
    };
}vdpq_frame_buf_chk3d_hen_num1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_hennum_valid1_num:20;
        RBus_UInt32  res1:12;
    };
}vdpq_frame_buf_chk3d_hen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_st1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st1:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_end1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end1:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_end1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_st2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st2:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_st2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_end2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end2:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_end2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_ififo_thr:6;
        RBus_UInt32  res1:26;
    };
}vdpq_dma_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_ofifo_thr:6;
        RBus_UInt32  res1:26;
    };
}vdpq_dma_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_ceiladr:6;
        RBus_UInt32  res1:26;
    };
}vdpq_dma_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_bstlen:3;
        RBus_UInt32  dma_3d_on_vcnt:5;
        RBus_UInt32  dma_vcnt_sft_thr:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_vcnt_sft_chk_en:1;
        RBus_UInt32  dma_vcnt_diff:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  ntsc443_tune:3;
        RBus_UInt32  dma_3d_on_off:1;
    };
}vdpq_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_test_mode_ok:1;
        RBus_UInt32  mem_test_mode:1;
        RBus_UInt32  mem_off:1;
        RBus_UInt32  ififo_err_flag_4:1;
        RBus_UInt32  ififo_err_flag_3:1;
        RBus_UInt32  ififo_err_flag_2:1;
        RBus_UInt32  ififo_err_flag_1:1;
        RBus_UInt32  ofifo_err_flag:1;
        RBus_UInt32  res1:24;
    };
}vdpq_dma_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_adc_in_sel:1;
        RBus_UInt32  dma_adc_in_en:1;
        RBus_UInt32  dma_field_inv:1;
        RBus_UInt32  res1:29;
    };
}vdpq_dma_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debugif_stline:10;
        RBus_UInt32  dma_debugif_stline_en:1;
        RBus_UInt32  res1:21;
    };
}vdpq_debug_dma_if_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vd_sram_on_off:1;
        RBus_UInt32  vlpf_sram_bypass:1;
        RBus_UInt32  res1:30;
    };
}vdpq_vd_sram_on_off_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr0:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem0_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr1:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem1_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr2:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem2_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr3:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem3_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr0_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem0_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr1_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem1_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr2_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem2_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr3_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem3_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debug_adr:29;
        RBus_UInt32  res1:3;
    };
}vdpq_dma_debug_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debug_vbiend_adr:29;
        RBus_UInt32  res1:3;
    };
}vdpq_dma_debug_vbi_end_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debugmode_en:1;
        RBus_UInt32  dma_debugmode_sel:2;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  dma_debug_vd_sel:4;
        RBus_UInt32  debugdma_outfifo_empty:1;
        RBus_UInt32  debugdma_outfifo_full:1;
        RBus_UInt32  res1:22;
    };
}vdpq_video_dma_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_debug_rw_en:2;
        RBus_UInt32  dma_debug_one_rw_rlt:1;
        RBus_UInt32  res2:25;
    };
}vdpq_vbidma_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_sht_st_th:20;
        RBus_UInt32  chase_pix_num:4;
        RBus_UInt32  chase_per_frame_en:1;
        RBus_UInt32  dma_pix_sht_fix_en:1;
        RBus_UInt32  calib_delay_en:1;
        RBus_UInt32  calib_delay_sel:1;
        RBus_UInt32  calib_delay_frame_sel:1;
        RBus_UInt32  chase_line_pos_en:2;
        RBus_UInt32  calib_delay_hsync_en:1;
    };
}vdpq_dma_cnt_calibration1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_sht_end_th:20;
        RBus_UInt32  pix_sht_limit_th:8;
        RBus_UInt32  pix_sht_limit_en:1;
        RBus_UInt32  fscnum_dif_abs_sel:2;
        RBus_UInt32  res1:1;
    };
}vdpq_dma_cnt_calibration2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fscdif_sum_abs:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  fscdif_num_abs:6;
        RBus_UInt32  res2:2;
    };
}vdpq_dma_cnt_calibration3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f1_cennum:16;
        RBus_UInt32  res1:16;
    };
}vdpq_frame_buffer_f1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f2_cennum:16;
        RBus_UInt32  res1:16;
    };
}vdpq_frame_buffer_f2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:32;
    };
}vdpq_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:32;
    };
}vdpq_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptive_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  yc_linebf_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ycsep_rdsel:1;
        RBus_UInt32  res3:22;
        RBus_UInt32  yc3d_tb_en:1;
    };
}vdpq_yc_sep_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  narrow_bpf_sel_y:4;
        RBus_UInt32  mid_bpf_sel_y:4;
        RBus_UInt32  wide_bpf_sel_y:4;
        RBus_UInt32  res1:20;
    };
}vdpq_bpf_bw_sel_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  narrow_bpf_sel_c:4;
        RBus_UInt32  mid_bpf_sel_c:4;
        RBus_UInt32  wide_bpf_sel_c:4;
        RBus_UInt32  res1:20;
    };
}vdpq_bpf_bw_sel_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_near_sel_c:1;
        RBus_UInt32  h2v_near_sel_y:1;
        RBus_UInt32  h2v_mid_sel_c:1;
        RBus_UInt32  h2v_mid_sel_y:1;
        RBus_UInt32  v2v_lk_c_en:1;
        RBus_UInt32  v2v_lk_y_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  h2v_lk_en:1;
        RBus_UInt32  res2:24;
    };
}vdpq_adap_bpf_c_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_vflag_mag_thr:4;
        RBus_UInt32  h2v_vflag_remag_thr:4;
        RBus_UInt32  res1:24;
    };
}vdpq_adap_bpf_c_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  palsw_level:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  pal_perr_auto_en:1;
        RBus_UInt32  pal_perr:1;
        RBus_UInt32  res2:25;
    };
}vdpq_comb_filter_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise_ntsc_c:8;
        RBus_UInt32  res1:24;
    };
}vdpq_comb_filter_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yalpha:1;
        RBus_UInt32  yalpha_en:1;
        RBus_UInt32  malpha_c:1;
        RBus_UInt32  malpha_c_en:1;
        RBus_UInt32  malpha_y:1;
        RBus_UInt32  malpha_y_en:1;
        RBus_UInt32  malpha_y_divider2_sel:1;
        RBus_UInt32  malpha_c_divider2_sel:1;
        RBus_UInt32  res1:24;
    };
}vdpq_adap_bpf_y_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_bw_lo:3;
        RBus_UInt32  chroma_vlpf_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pal_demod_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_vlpf_round_en:1;
        RBus_UInt32  res3:23;
    };
}vdpq_yc_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode_2d:4;
        RBus_UInt32  debug_mode_2d_en:1;
        RBus_UInt32  res1:27;
    };
}vdpq_debug_2d_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_detect_thr:6;
        RBus_UInt32  bw_gain_sel:2;
        RBus_UInt32  res1:24;
    };
}vdpq_bw_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_edge_thr:8;
        RBus_UInt32  res1:24;
    };
}vdpq_bw_edge_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bpf_1d_sel_y:2;
        RBus_UInt32  blend_1d_thr:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  same_phase_diff_1d_gauge_en:1;
        RBus_UInt32  res2:23;
    };
}vdpq_blend_1d_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wide_1d_bpf_sel_c:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  narrow_1d_bpf_sel_c:3;
        RBus_UInt32  res2:25;
    };
}vdpq_blend_1d_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_coring_thr:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lut_sel_c:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  lut_sel_y:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  lut_fuzzy_th:4;
        RBus_UInt32  lut_large_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  halpha:4;
        RBus_UInt32  res5:3;
        RBus_UInt32  force_halpha_en:1;
    };
}vdpq_alpha_2d_mod_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_bw_color_gain:4;
        RBus_UInt32  h2v_cvbs_coring_thr:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  h2v_lut_hv_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h2v_lut_hprefer_ratio:4;
        RBus_UInt32  res3:12;
    };
}vdpq_h2v_coring_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_y_noise_thr:8;
        RBus_UInt32  res1:24;
    };
}vdpq_h2v_y_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_cvbs_noise_thr:8;
        RBus_UInt32  res1:24;
    };
}vdpq_h2v_cvbs_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_noise_max_hdy:8;
        RBus_UInt32  res1:24;
    };
}vdpq_h2v_noise_max_hdy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v2v_noise_y_add_dc:8;
        RBus_UInt32  v2v_lut_sel_y:1;
        RBus_UInt32  res1:23;
    };
}vdpq_h2v_noise_y_add_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_blendratio:3;
        RBus_UInt32  res1:29;
    };
}vdpq_h2v_blend_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  xc_sel_gain:2;
        RBus_UInt32  res2:24;
    };
}vdpq_adap_bpf_y_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cdiff_bpf_ver_range:1;
        RBus_UInt32  cdiff_bpf_hor_range:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_bpf_mm_diff_th:8;
        RBus_UInt32  cdiff_bpf_mm_small_th:6;
        RBus_UInt32  res3:10;
    };
}vdpq_cdiff_adap_bpf_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdiff_bpf_small_amp_wei:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cdiff_bpf_small_offset:4;
        RBus_UInt32  cdiff_bpf_large_amp_wei:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cdiff_bpf_large_offset:4;
        RBus_UInt32  cdiff_bpf_low_sat_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cdiff_bpf_vspd_small_th:6;
        RBus_UInt32  res4:2;
    };
}vdpq_cdiff_adap_bpf_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vedge_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_tolerance:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hvdiff_comp_multiple:4;
        RBus_UInt32  hvdiff_comp_offset:8;
        RBus_UInt32  res3:8;
    };
}vdpq_bpf_vedge_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_upbound:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_lowbound:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_follow_y_en:1;
        RBus_UInt32  res3:15;
    };
}vdpq_bpf_vedge_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypassbpf_adap_en:1;
        RBus_UInt32  complex_level_mode_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  complex_level_th:8;
        RBus_UInt32  lr_diff_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  lr_diff_lower_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  lr_diff_ratio:4;
    };
}vdpq_bypass_bpf_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_ratio_th:4;
        RBus_UInt32  newvedge_vdiff_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  newvedge_vdiff_ratio:4;
        RBus_UInt32  newvedge_lr_diff_th:7;
        RBus_UInt32  res2:9;
    };
}vdpq_bypass_bpf_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gridgirl_en:1;
        RBus_UInt32  grid_use_preflag_en:1;
        RBus_UInt32  grid_reset_sel:1;
        RBus_UInt32  gridgirl_corr_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  grid_cvbs_diff_th:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  debug_mode_gridgirl:1;
    };
}vdpq_gridgirl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_hordiff_th1:8;
        RBus_UInt32  grid_hordiff_th2:8;
        RBus_UInt32  grid_chroma_th1:8;
        RBus_UInt32  grid_chroma_th2:8;
    };
}vdpq_gridgirl_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_linesum_th1:8;
        RBus_UInt32  grid_linesum_th2:8;
        RBus_UInt32  grid_linecnt_th1:8;
        RBus_UInt32  grid_linecnt_th2:8;
    };
}vdpq_gridgirl_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_sum_left_bound:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_sum_right_bound:11;
        RBus_UInt32  res2:5;
    };
}vdpq_gridgirl_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_left_bound:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_right_bound:11;
        RBus_UInt32  res2:5;
    };
}vdpq_gridgirl_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diamc_cvbsamp_still_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  vmc_widehspd_small_th:6;
        RBus_UInt32  res2:18;
    };
}vdpq_diamc_cvbs_amp_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diamc_en:1;
        RBus_UInt32  diamc_perfect_fid_en:1;
        RBus_UInt32  diamc_all_line_match_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  diamc_amp_low_bnd:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  diamc_fid_th_weight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  diamc_y_v_line_id_cnt_th:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  diamc_dc_still_th_weight:4;
        RBus_UInt32  diamc_dc_still_th_offset:6;
        RBus_UInt32  res5:2;
    };
}vdpq_diamc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmc_en:1;
        RBus_UInt32  perfect_fid_en:1;
        RBus_UInt32  slant_det_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  amp_low_bnd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_dc_still_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  vmc_cfollowy_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  ver_cvbsamp_still_th:6;
        RBus_UInt32  res5:2;
    };
}vdpq_vmc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_th_1:4;
        RBus_UInt32  cnt_th_2:4;
        RBus_UInt32  offset_1:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_2:3;
        RBus_UInt32  res2:17;
    };
}vdpq_vmc_spatial_corr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postlpf_en:1;
        RBus_UInt32  postlpf_force_en:1;
        RBus_UInt32  postlpf_grad_en:1;
        RBus_UInt32  postlpf_dia_en:1;
        RBus_UInt32  res1:28;
    };
}vdpq_yc2d_postlp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_amp_th_0:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  low_amp_th_1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  low_amp_th_2:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  low_amp_th_3:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_flat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_amp_th_4:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_th_0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hdiff_th_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hdiff_th_2:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_flat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_th_3:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_th_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_1:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_flat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_th_2:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_3:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_4:5;
        RBus_UInt32  res3:11;
    };
}vdpq_yc2d_postlp_flat_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grad_flat_th_upbnd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  grad_flat_th_offset:4;
        RBus_UInt32  grad_flat_th_ratio:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  larger_cnt_th_0:4;
        RBus_UInt32  smaller_cnt_th_0:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  larger_cnt_th_1:4;
    };
}vdpq_yc2d_postlp_grad_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smaller_cnt_th_1:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  low_amp_th_grad_offset:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0_grad:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_1_grad:5;
        RBus_UInt32  res4:7;
    };
}vdpq_yc2d_postlp_grad_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_th_2_grad:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_3_grad:5;
        RBus_UInt32  res2:19;
    };
}vdpq_yc2d_postlp_grad_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  larger_cnt_th_dia:4;
        RBus_UInt32  smaller_cnt_th_dia:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  low_amp_th_dia_offset:8;
        RBus_UInt32  spd_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  spd_large_ratio:4;
        RBus_UInt32  res3:4;
    };
}vdpq_yc2d_postlp_dia_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spd_diff_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  dia_grad_flat_th_upbnd:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dia_grad_flat_th_offset:4;
        RBus_UInt32  dia_grad_flat_th_ratio:5;
        RBus_UInt32  res3:7;
    };
}vdpq_yc2d_postlp_dia_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_th_0_dia:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_1_dia:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_2_dia:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_3_dia:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_dia_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dia_cedge_th:6;
        RBus_UInt32  res1:26;
    };
}vdpq_yc2d_postlp_dia_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yc_sep_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pal_mod_inv:1;
        RBus_UInt32  res2:19;
        RBus_UInt32  demodphase_fix:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  demodphase_fix_en:1;
    };
}vdpq_yc_sep_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:32;
    };
}vdpq_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  yc3d_ychroma_bpf_sel:1;
        RBus_UInt32  yc3d_cchroma_bpf_sel:1;
        RBus_UInt32  res2:24;
    };
}vdpq_yc_3dsep_chroma_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_delay_4fsc:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  cb_delay_4fsc:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  y_delay_4fsc:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  alpha2d3d_delay_4fsc:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  malpha_delay_4fsc:2;
        RBus_UInt32  res5:14;
    };
}vdpq_yc_sep_yuv_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slp_monotone_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  monotone_edge_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  monotone_flat_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  monotone_flat_cnt_th:4;
        RBus_UInt32  res4:8;
    };
}vdpq_yc_3d_f4_slp_mono_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c_change_cnt:16;
        RBus_UInt32  slp_cnt:16;
    };
}vdpq_yc_3d_f4_stat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tempspd_small_cnt:16;
        RBus_UInt32  stat_tempspd_small_th:7;
        RBus_UInt32  res1:9;
    };
}vdpq_yc_3d_f4_stat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hifreqdiff_not_small_cnt:16;
        RBus_UInt32  stat_hifreqdiff_not_small_th:8;
        RBus_UInt32  res1:8;
    };
}vdpq_yc_3d_f4_stat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slp_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  slp_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  sc_hfd_diff_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  sc_hfd_diff_large_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  sc_hfd_diff_large_ratio:4;
    };
}vdpq_yc_3d_f4_slp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  match_cnt_th:4;
        RBus_UInt32  dc_still_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  large_hvspd_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cvbs_match_cnt_th_hvspd:4;
        RBus_UInt32  res3:8;
    };
}vdpq_yc_3d_f4_slp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cvbs_match_cnt_th:4;
        RBus_UInt32  cvbsamp_diff_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cvbsamp_diff_ratio:4;
        RBus_UInt32  cvbsamp_th:4;
        RBus_UInt32  cvbsamp_ratio:3;
        RBus_UInt32  res2:9;
    };
}vdpq_yc_3d_f4_slp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ntsc_aba_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  aba_hifreqdiff_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  aba_aa_diff_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  aba_dc_change_th:6;
        RBus_UInt32  res4:6;
    };
}vdpq_yc_3d_f4_ntsc_aba_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aba_dc_multiple:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  aba_cvbsamp_ab_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  aba_cvbsamp_aa_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  aba_cvbsamp_multiple:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_ntsc_aba_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:32;
    };
}vdpq_dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_debug_mode_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  f4_debug_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  f4_dbg_value_mode_enable:1;
        RBus_UInt32  f4_dbg_cvbs_amp_th:8;
        RBus_UInt32  f4_dbg_highfreq_diff_th:8;
        RBus_UInt32  f4_global_diff_dbg_sftbit:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  f4_en:1;
    };
}vdpq_yc_3d_f4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_3d_spatial_cnt_th_1:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_2:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_3:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_4:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_5:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  cvbs_amp_change_th:7;
        RBus_UInt32  res2:1;
    };
}vdpq_yc_3d_f4_spa_cnt_cvbs_amp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hv_diff_tolerance:4;
        RBus_UInt32  hv_local_diff_comp_ratio:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  hv_diff_large_offset_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hv_diff_large_multiple_th:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  hv_cvbs_diff_large_multiple_th:3;
        RBus_UInt32  res4:9;
    };
}vdpq_yc_3d_f4_hv_edge_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hv_edge_c_diff_small_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hv_edge_c_diff_small_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_diff_normalize_en:1;
        RBus_UInt32  res3:19;
    };
}vdpq_yc_3d_f4_hv_edge_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_ver_hifreq_usepalmode:1;
        RBus_UInt32  f4_hor_hifreq_range:1;
        RBus_UInt32  f4_ver_chifreq_range:1;
        RBus_UInt32  f4_hor_chifreq_range:1;
        RBus_UInt32  f4_fill_hole_neightbor_diff_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  hifreq_postp_mode:2;
        RBus_UInt32  hor_c_postp_mode:2;
        RBus_UInt32  res2:16;
    };
}vdpq_yc_3d_f4_hifreq_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_level_change_th_base:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dc_level_change_th_multiple:4;
        RBus_UInt32  res2:20;
    };
}vdpq_yc_3d_f4_dc_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pal_error_detect_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  palerr_hifreq_diff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  palerr_accu_tolerance:4;
        RBus_UInt32  similary_th_multiple:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  similary_th_base:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pal_err_com_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  massive_palmode_error_large_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  massive_palmode_error_multiple_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_of_spd_small_th_multiple:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_of_spd_small_th_base:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pal_err_com_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4f0_still_th_upbnd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  f4f0_still_th_offset:4;
        RBus_UInt32  f4f0_still_th_weight:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  palerr_massive_tolerance:4;
        RBus_UInt32  res3:7;
        RBus_UInt32  f4f0_still_en:1;
    };
}vdpq_yc_3d_f4_pal_err_com_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_vector_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  sv_vector_large_cnt_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_vector_fid_offset:4;
        RBus_UInt32  sv_vector_fid_match_cnt_th:5;
        RBus_UInt32  res3:5;
        RBus_UInt32  sv_longtime_en:1;
        RBus_UInt32  sv_avg_dynamic_en:1;
    };
}vdpq_yc_3d_f4_still_vector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_self_diff_small_th:7;
        RBus_UInt32  res1:25;
    };
}vdpq_yc_3d_f4_still_vector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sghf_longtime_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sghf_global_diff_small_th:8;
        RBus_UInt32  sghf_inter_diff_th:7;
        RBus_UInt32  res2:13;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sghf_vector_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  sghf_vector_large_cnt_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  sghf_vector_fid_offset:4;
        RBus_UInt32  sghf_vector_fid_match_cnt_th:5;
        RBus_UInt32  res3:6;
        RBus_UInt32  sghf_avg_dynamic_en:1;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_multiple_200:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_180:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_160:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_140:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pair_th_multiple_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_multiple_120:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_100:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_80:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_60:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pair_th_multiple_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_multiple_40:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_20:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_10:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_0:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pair_th_multiple_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_200:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_180:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_160:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_140:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pair_th_base_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_120:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_100:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_80:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_60:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pair_th_base_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_40:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_0:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pair_th_base_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c_diff_dpo_hedge_rshift_bit:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pal_error_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_vector_offset_base:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  still_vector_offset_multiple:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  hv_offset:6;
        RBus_UInt32  res5:2;
    };
}vdpq_yc_3d_f4_pair_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  still_vector_hifreq_diff_th:6;
        RBus_UInt32  still_vector_hifreq_diff_th_shift_bit:2;
        RBus_UInt32  still_vector_cvbs_amp_change_offset:6;
        RBus_UInt32  res1:17;
        RBus_UInt32  still_vector_avoid_aba_hifreq_enable:1;
    };
}vdpq_yc_3d_f4_pair_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flat_offset:4;
        RBus_UInt32  highfreq_diff_low_border:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  pair_diff_sel_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  later_diff_upper_bound:7;
        RBus_UInt32  res3:5;
    };
}vdpq_yc_3d_f4_pair_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hvdiff_border:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_2d_comp_3d_offset:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_lower_bound:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_upper_bound:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_3d_f4_pair_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  still_gray_hifreq_enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  still_gray_hifreq_low_border:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_gray_hifreq_th:7;
        RBus_UInt32  res3:13;
    };
}vdpq_yc_3d_f4_pair_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdy_small_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dc_level_fierce_change_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_offset_dc_fierce_change:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  global_diff_tolerance:4;
        RBus_UInt32  res4:4;
    };
}vdpq_yc_3d_f4_pair_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_180:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_160:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_140:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_120:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_100:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_80:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_70:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_60:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_50:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_40:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_20:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_10:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_5:6;
        RBus_UInt32  res3:10;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_level_hor_dc_check_en:1;
        RBus_UInt32  moving_vline_en:1;
        RBus_UInt32  mghf_enable:1;
        RBus_UInt32  mghf_flag:1;
        RBus_UInt32  moving_vline_flat_ver_cvbs_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  moving_vline_ver_dc_level_fierce_change_th:5;
        RBus_UInt32  res2:15;
    };
}vdpq_yc_3d_f4_mghf_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c_change_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  cvbs_still_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hifreq_diff_large_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hor_c_change_ratio:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  large_hifreq_diff_ratio:3;
        RBus_UInt32  res5:1;
    };
}vdpq_yc_3d_f4_mghf_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_multiple_5:5;
        RBus_UInt32  res2:19;
    };
}vdpq_yc_3d_f4_global_diff_th_com_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbwline_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  diadiff_small_base:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diadiff_small_weight:4;
        RBus_UInt32  diadiff_small_upbnd:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diadiff_vspd_large_th:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_post2dbpf_dbwline_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_sat_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dbwline_hor_cdiff_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  dbwline_hspd_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  dbwline_d45_hspd_large_th:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_post2dbpf_dbwline_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbwline_d45_diadiff_small_th:7;
        RBus_UInt32  res1:25;
    };
}vdpq_yc_post2dbpf_dbwline_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  post2dbpf_y_en:1;
        RBus_UInt32  post2dbpf_c_en:1;
        RBus_UInt32  greenish_detected_en:1;
        RBus_UInt32  mghf_narrowbpf_en:1;
        RBus_UInt32  weight_3d_y:2;
        RBus_UInt32  weight_bld_y:2;
        RBus_UInt32  weight_2d_y:2;
        RBus_UInt32  weight_3d_c:2;
        RBus_UInt32  weight_bld_c:2;
        RBus_UInt32  weight_2d_c:2;
        RBus_UInt32  gremove_bpfedc_small_th:4;
        RBus_UInt32  gremove_c_small_th:5;
        RBus_UInt32  res1:7;
    };
}vdpq_yc_post2dbpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_cdiff_th_base:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  hor_cdiff_th_base:7;
        RBus_UInt32  res2:17;
    };
}vdpq_yc_post2dbpf_thbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dual_ch_bpfedcdiff_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  dual_ch_bpfedcdiff_large_ratio:4;
        RBus_UInt32  dual_ch_bpfedc_small_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  bpfed_c_diff_small_th:7;
        RBus_UInt32  res3:5;
    };
}vdpq_yc_post2dbpf_adapth_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bpfed_c_diff_small_ver_offset:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  bpfed_c_diff_small_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  bpfed_c_diff_large_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bpfed_c_diff_large_hor_offset:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_post2dbpf_adapth_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdy_spd_small_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vspd_small_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  neighbor_hdiff_small_ver_offset:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  neighbor_vdiff_small_hor_offset:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_post2dbpf_adapth_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_tolerance:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdy_spd_large_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  vspd_large_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  hvedge_diff_large_ratio:4;
        RBus_UInt32  res4:4;
    };
}vdpq_yc_post2dbpf_adapth_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hedge_ver_offset:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  vedge_hor_offset:7;
        RBus_UInt32  res2:17;
    };
}vdpq_yc_post2dbpf_adapth_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dia_spd_large_th_base:8;
        RBus_UInt32  dia_spd_large_th_small_hordiff_offset:8;
        RBus_UInt32  dia_spd_large_th_small_hordiff_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dia_spd_large_ver_offset:7;
        RBus_UInt32  res2:1;
    };
}vdpq_yc_post2dbpf_adapth_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dual_ch_cdiff_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  dual_ch_cdiff_large_ratio:4;
        RBus_UInt32  dual_ch_c_small_th:5;
        RBus_UInt32  res2:15;
    };
}vdpq_yc_post2dbpf_adapth_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_large_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  hdiff_vdiff_diff_larger_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hdiff_much_larger_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hdiff_much_larger_ratio:4;
        RBus_UInt32  res4:4;
    };
}vdpq_yc_post2dbpf_adapth_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_much_larger_hor_offset:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_color_tran_hdiff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_color_tran_ver_cdiff_small_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_color_tran_ver_offset:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_post2dbpf_adapth_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  colorbar_vdiff_small_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  colorbar_hdiff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  colorbar_detect_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  colorbar_detect_hor_offset:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_post2dbpf_adapth_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smooth_vdiff_small_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  smooth_hdiff_small_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  smooth_detect_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_avoid_th_y:4;
        RBus_UInt32  ver_avoid_th_c:4;
    };
}vdpq_yc_post2dbpf_adapth_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v2sides_gray_diff_small_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  v2sides_diff_large_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  v2sides_diff_large_ratio:4;
        RBus_UInt32  vcdiff_large_ratio:4;
        RBus_UInt32  vcdiff_large_diff_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  vedge_avoid_en:1;
    };
}vdpq_yc_post2dbpf_adapth_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ignore_th_y:4;
        RBus_UInt32  ignore_th_c:4;
        RBus_UInt32  hedge_bypass_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hedge_ratio_th:4;
        RBus_UInt32  upbnd:8;
        RBus_UInt32  res2:8;
    };
}vdpq_yc_post2dbpf_adapth_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xc_hvedge_th_1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  xc_hvedge_ratio_th_1:4;
        RBus_UInt32  xc_hvedge_th_2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  xc_hvedge_ratio_th_2:4;
        RBus_UInt32  xc_cdiff_upbnd:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  xc_hvedge_avoid_en:1;
    };
}vdpq_yc_post2dbpf_xc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yadap_peak_mode:2;
        RBus_UInt32  yadap_hpf_sel:2;
        RBus_UInt32  res1:28;
    };
}vdpq_secam_yadap_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yadap_peak_th:4;
        RBus_UInt32  yadap_peak_gain:4;
        RBus_UInt32  res1:24;
    };
}vdpq_secam_yadap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yadap_uniform_gain:4;
        RBus_UInt32  yadap_peak_gain_2d:4;
        RBus_UInt32  res1:24;
    };
}vdpq_secam_yadap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_en:1;
        RBus_UInt32  xnr_det_bypass_en:1;
        RBus_UInt32  xnr_blend_en:1;
        RBus_UInt32  xnr_blend_dbm:1;
        RBus_UInt32  xnr_vlpf_sel:2;
        RBus_UInt32  xnr_lpf_sel:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  postpq_malphadelay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  postpq_alphadelay:6;
        RBus_UInt32  res3:5;
        RBus_UInt32  postpq_alphadelay_indep_en:1;
    };
}vdpq_xnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_csum_thr:4;
        RBus_UInt32  xnr_cdiff_thr:4;
        RBus_UInt32  res1:24;
    };
}vdpq_xnr_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_ver_idxgain:4;
        RBus_UInt32  xnr_idxgain:4;
        RBus_UInt32  res1:24;
    };
}vdpq_xnr_idx_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_ver_ratio_w:4;
        RBus_UInt32  xnr_ver_ratio:4;
        RBus_UInt32  res1:24;
    };
}vdpq_xnr_ratio_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma0_con_en:1;
        RBus_UInt32  cdiff_small_con_en:1;
        RBus_UInt32  vline_con_en:1;
        RBus_UInt32  vline_len_3_sel:1;
        RBus_UInt32  point_type_coring_lv:4;
        RBus_UInt32  ma0_cnt_th:5;
        RBus_UInt32  mf_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_cedge_en:1;
        RBus_UInt32  ver_cedge_single_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_cedge_sum_th:7;
        RBus_UInt32  res3:1;
    };
}vdpq_postp_mf_compensation_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdiff_small_len:4;
        RBus_UInt32  cdiff_small_single_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cdiff_small_sum_th:7;
        RBus_UInt32  res2:13;
    };
}vdpq_postp_mf_compensation_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_en:1;
        RBus_UInt32  postpk_adappk_en:1;
        RBus_UInt32  postpk_adap_mode:2;
        RBus_UInt32  postpk_dnoise_en:1;
        RBus_UInt32  postpk_alphablend_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  postpk_prelpf_en:1;
        RBus_UInt32  postpk_prelpf_mode:1;
        RBus_UInt32  res2:22;
    };
}vdpq_yc2d_postpk2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_y_lwbnd:8;
        RBus_UInt32  postpk_y_stepbit:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  postpk_c_lwbnd:8;
        RBus_UInt32  postpk_c_stepbit:3;
        RBus_UInt32  res2:5;
    };
}vdpq_yc2d_postpk2_adap1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_lv_th:8;
        RBus_UInt32  postpk_lv_sft:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  postpk_lv_upbnd:8;
        RBus_UInt32  res2:8;
    };
}vdpq_yc2d_postpk2_dnoise1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_c2:8;
        RBus_UInt32  postpk_c1:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  postpk_c0:9;
        RBus_UInt32  res2:3;
    };
}vdpq_yc2d_postpk2_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_gain_neg:8;
        RBus_UInt32  postpk_gain_pos:8;
        RBus_UInt32  res1:16;
    };
}vdpq_yc2d_postpk2_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_lv:8;
        RBus_UInt32  postpk_hv_neg:10;
        RBus_UInt32  postpk_hv_pos:10;
        RBus_UInt32  res1:4;
    };
}vdpq_yc2d_postpk2_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_en:1;
        RBus_UInt32  dlti_pnth:7;
        RBus_UInt32  dlti_maxlen:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dlti_ffd1_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti_ffd1_ratio:4;
        RBus_UInt32  dlti_ffd2_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dlti_ffd2_ratio:4;
    };
}vdpq_postp_dlti_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_ffd2_range2r:4;
        RBus_UInt32  dlti_ffd2_range2l:4;
        RBus_UInt32  dlti_can_shift:4;
        RBus_UInt32  dlti_ovc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlti_tn_blend_en:1;
        RBus_UInt32  dlti_tn_blend_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti_dcp_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  dlti_d1_cp_shift:4;
    };
}vdpq_postp_dlti_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_cchange_corr_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlti_cchange_len:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dlti_uv_diff_th_1:8;
        RBus_UInt32  dlti_uv_diff_th_2:8;
        RBus_UInt32  dlti_cchange_srcwei_offset_1:4;
        RBus_UInt32  dlti_cchange_srcwei_offset_2:4;
    };
}vdpq_postp_dlti_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tngain0:4;
        RBus_UInt32  dlti_tngain1:4;
        RBus_UInt32  dlti_tngain2:4;
        RBus_UInt32  dlti_tngain3:4;
        RBus_UInt32  dlti_tngain4:4;
        RBus_UInt32  dlti_tngain5:4;
        RBus_UInt32  dlti_tngain6:4;
        RBus_UInt32  dlti_tngain7:4;
    };
}vdpq_postp_dlti_tngain_gain_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tngain8:4;
        RBus_UInt32  dlti_tngain9:4;
        RBus_UInt32  dlti_tngain10:4;
        RBus_UInt32  dlti_tngain11:4;
        RBus_UInt32  dlti_tngain12:4;
        RBus_UInt32  dlti_tngain13:4;
        RBus_UInt32  dlti_tngain14:4;
        RBus_UInt32  res1:4;
    };
}vdpq_postp_dlti_tngain_gain_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tnoffset0:4;
        RBus_UInt32  dlti_tnoffset1:4;
        RBus_UInt32  dlti_tnoffset2:4;
        RBus_UInt32  dlti_tnoffset3:4;
        RBus_UInt32  dlti_tnoffset4:4;
        RBus_UInt32  dlti_tnoffset5:4;
        RBus_UInt32  dlti_tnoffset6:4;
        RBus_UInt32  dlti_tnoffset7:4;
    };
}vdpq_postp_dlti_tngain_offset_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tnoffset8:4;
        RBus_UInt32  dlti_tnoffset9:4;
        RBus_UInt32  dlti_tnoffset10:4;
        RBus_UInt32  dlti_tnoffset11:4;
        RBus_UInt32  dlti_tnoffset12:4;
        RBus_UInt32  dlti_tnoffset13:4;
        RBus_UInt32  dlti_tnoffset14:4;
        RBus_UInt32  res1:4;
    };
}vdpq_postp_dlti_tngain_offset_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pd_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pd_sel_dlti_diff_th:8;
        RBus_UInt32  pd_sel_dlti_cnt_th1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pd_sel_dlti_cnt_th2:3;
        RBus_UInt32  res3:13;
    };
}vdpq_postp_dlti_pk_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_alpha_3d_weight:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  xnr_alpha_bld_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  xnr_alpha_2d_weight:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  dlti_alpha_3d_weight:2;
        RBus_UInt32  dlti_alpha_bld_weight:2;
        RBus_UInt32  dlti_alpha_2d_weight:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pk_alpha_3d_weight:2;
        RBus_UInt32  pk_alpha_bld_weight:2;
        RBus_UInt32  pk_alpha_2d_weight:2;
        RBus_UInt32  res5:2;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mfnotch_alpha_2d_weight:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  notch_force_3dweight:4;
        RBus_UInt32  notch_force_upbnd:8;
        RBus_UInt32  snr_alpha_3d_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  snr_alpha_bld_weight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  snr_alpha_2d_weight:3;
        RBus_UInt32  res4:4;
        RBus_UInt32  alphablend_round_en:1;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ntsc443_lpf_th_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ntsc443_lpf_ext:2;
        RBus_UInt32  res2:25;
        RBus_UInt32  ntsc443_lpf:1;
    };
}vdpq_postp_ntsc443_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_sweightydebug:2;
        RBus_UInt32  res1:30;
    };
}vdpq_spnr_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialenabley:1;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_sresultweight:3;
        RBus_UInt32  res2:5;
    };
}vdpq_spnr_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthly:8;
        RBus_UInt32  cp_spatialthlyx2:8;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  res1:8;
    };
}vdpq_spnr_spatial_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_weight2y:4;
        RBus_UInt32  cp_weight1y:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  res3:4;
    };
}vdpq_spnr_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_status:32;
    };
}vdpq_dummy_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_edge_weight:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  cp_sw_edge_thl:16;
    };
}vdpq_spnr_local_var2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  notch_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  notch_upbnd_upbnd:8;
        RBus_UInt32  notch_upbnd_weight:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  notch_upbnd_offset:6;
        RBus_UInt32  res3:6;
    };
}vdpq_notch_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  notch_lowbnd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  high_sat_lowbnd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  high_sat_weight_do:4;
        RBus_UInt32  high_sat_weight_undo:4;
        RBus_UInt32  large_notchy_amp_th:6;
        RBus_UInt32  res3:2;
    };
}vdpq_notch_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  large_notchy_amp_weight_do:4;
        RBus_UInt32  large_notchy_amp_weight_undo:4;
        RBus_UInt32  very_diff_large_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  very_diff_large_weight_do:4;
        RBus_UInt32  very_diff_large_weight_undo:4;
        RBus_UInt32  very_nonmonotone_weight_do:4;
        RBus_UInt32  very_nonmonotone_weight_undo:4;
    };
}vdpq_notch_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  large_cdiff_th:8;
        RBus_UInt32  large_cdiff_weight_do:4;
        RBus_UInt32  large_cdiff_weight_undo:4;
        RBus_UInt32  vline_weight_undo:4;
        RBus_UInt32  force_notch_weight:4;
        RBus_UInt32  res1:8;
    };
}vdpq_notch_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  alpha2d3d_bld_weight_0:5;
        RBus_UInt32  res2:3;
    };
}vdpq_alpha_blending_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alpha2d3d_bld_weight_4:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_3:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_2:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_1:5;
        RBus_UInt32  res4:3;
    };
}vdpq_alpha_blending_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alpha2d3d_bld_weight_8:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_7:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_6:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_5:5;
        RBus_UInt32  res4:3;
    };
}vdpq_alpha_blending_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alpha2d3d_bld_weight_12:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_11:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_10:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_9:5;
        RBus_UInt32  res4:3;
    };
}vdpq_alpha_blending_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alpha2d3d_bld_weight_16:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  alpha2d3d_bld_weight_15:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  alpha2d3d_bld_weight_14:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  alpha2d3d_bld_weight_13:5;
        RBus_UInt32  res4:3;
    };
}vdpq_alpha_blending_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_alpha_offset:4;
        RBus_UInt32  ts_alpha_gain:4;
        RBus_UInt32  ts_multiple:4;
        RBus_UInt32  iir_reset_value:8;
        RBus_UInt32  res1:10;
        RBus_UInt32  iir_reset_clear:1;
        RBus_UInt32  ts_enable:1;
    };
}vdpq_alpha_temporal_smooth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  de_xc_thr:4;
        RBus_UInt32  de_xc_en:1;
        RBus_UInt32  xc_blend_en:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  postpq_alphablend_dbm:1;
    };
}vdpq_de_xc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnr_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cnr_lpf_sel:2;
        RBus_UInt32  res2:28;
    };
}vdpq_cnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_cti_en:1;
        RBus_UInt32  cadap_yuvsync_en:1;
        RBus_UInt32  cadap_uvsync_en:1;
        RBus_UInt32  cadap_ylpf_en:1;
        RBus_UInt32  cadap_clpf_en:1;
        RBus_UInt32  cadap_spatial_lpf_out:1;
        RBus_UInt32  res1:26;
    };
}vdpq_cadap_enable_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_y_sync_uni_en:1;
        RBus_UInt32  cadap_uv_sync_uni_en:1;
        RBus_UInt32  cadap_uni_gain_ctrl_en:1;
        RBus_UInt32  res1:29;
    };
}vdpq_cadap_enable_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_level:4;
        RBus_UInt32  cadap_gain:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_zc_mag_th_y_c:4;
        RBus_UInt32  cadap_zc_mag_th_y:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_zc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_dir_det_gain:4;
        RBus_UInt32  cadap_zc_mag_th_c:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_zc_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_dir_uni_th:4;
        RBus_UInt32  cadap_ver_uni_th:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_ver_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_uv_sync_uni_th:4;
        RBus_UInt32  cadap_y_sync_uni_th:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_sync_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_lut_level_thb:4;
        RBus_UInt32  cadap_lut_level_tha:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_lut_level_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_lut_gain_thb:4;
        RBus_UInt32  cadap_lut_gain_tha:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_lut_gain_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_b1:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_b2:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_b3:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_a2:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_a2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_a3:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_a3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_en:1;
        RBus_UInt32  res1:31;
    };
}vdpq_dcti_filter_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_en:1;
        RBus_UInt32  smd_hor_00_move_enable:1;
        RBus_UInt32  smd_hor_02_move_enable:1;
        RBus_UInt32  smd_hor_04_move_enable:1;
        RBus_UInt32  smd_hor_06_move_enable:1;
        RBus_UInt32  smd_hor_08_move_enable:1;
        RBus_UInt32  smd_hor_10_move_enable:1;
        RBus_UInt32  smd_ver_00_move_enable:1;
        RBus_UInt32  smd_ver_02_move_enable:1;
        RBus_UInt32  smd_ver_04_move_enable:1;
        RBus_UInt32  smd_ver_06_move_enable:1;
        RBus_UInt32  smd_ver_08_move_enable:1;
        RBus_UInt32  smd_ver_10_move_enable:1;
        RBus_UInt32  res1:19;
    };
}vdpq_yc_3d_f4_smd_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_horizontal_sad_tolerance:8;
        RBus_UInt32  smd_vertical_sad_tolerance:8;
        RBus_UInt32  smd_hor_spatial_temporal_traily_diff:8;
        RBus_UInt32  smd_ver_spatial_temporal_traily_diff:8;
    };
}vdpq_yc_3d_f4_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_min_sad_horizontal:8;
        RBus_UInt32  smd_min_sad_vetical:8;
        RBus_UInt32  res1:16;
    };
}vdpq_yc_3d_f4_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_highfreq_diff_th:8;
        RBus_UInt32  smd_highfreq_diff_2_th:8;
        RBus_UInt32  smd_2d_small_global_diff_offset:16;
    };
}vdpq_yc_3d_f4_pair_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_2d_not_small_global_diff_offset:16;
        RBus_UInt32  res1:16;
    };
}vdpq_yc_3d_f4_pair_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_vm:32;
    };
}vdpq_ns_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxv:16;
        RBus_UInt32  countv:16;
    };
}vdpq_ns_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sumv:32;
    };
}vdpq_ns_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmm:16;
        RBus_UInt32  nfactor:8;
        RBus_UInt32  res1:8;
    };
}vdpq_ns_rw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  meannxv:16;
        RBus_UInt32  density:8;
        RBus_UInt32  res1:8;
    };
}vdpq_ns_rw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pq_noisestatus_hsync_end:8;
        RBus_UInt32  pq_noisestatus_hsync_start:8;
        RBus_UInt32  res1:15;
        RBus_UInt32  hsyncdebug_en:1;
    };
}vdpq_ns_gate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_color_reduce_ctrl:2;
        RBus_UInt32  secam_fix_pre_yvlpf_en:1;
        RBus_UInt32  secam_fix_post_cvlpf_en:1;
        RBus_UInt32  secam_fix_debug_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  secam_fix_grey_thd:8;
        RBus_UInt32  secam_fix_line_grey_ratio:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  secam_fix_color_reduce_en:1;
        RBus_UInt32  secam_fix_uv_flag_en:1;
    };
}vdpq_postp_secam_fix_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_y_flag_ext_r:8;
        RBus_UInt32  secam_fix_y_flag_ext_l:8;
        RBus_UInt32  secam_fix_y_action_continue_d_time:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_fix_y_diff_thd:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  secam_fix_y_flag_en:1;
    };
}vdpq_postp_secam_fix_y_detect0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_y_target_d0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_fix_y_target_d1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_fix_y_target_d2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  secam_fix_y_target_d3:6;
        RBus_UInt32  res4:2;
    };
}vdpq_postp_secam_fix_y_detect1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dir3d_enable:1;
        RBus_UInt32  res1:20;
        RBus_UInt32  dir3d_fw_mode_dalpha_c:4;
        RBus_UInt32  dir3d_fw_mode_motion:2;
        RBus_UInt32  dir3d_fw_mode_dalpha:4;
        RBus_UInt32  dir3d_fw_mode_enable:1;
    };
}vdpq_directional_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  windows_2d3d_blend_ratio:4;
        RBus_UInt32  res1:27;
        RBus_UInt32  windows_enable:1;
    };
}vdpq_fix_window_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  windows_x_end:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  windows_x_sta:11;
        RBus_UInt32  res2:5;
    };
}vdpq_fix_window_posx_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  windows_y_end:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  windows_y_sta:9;
        RBus_UInt32  res2:7;
    };
}vdpq_fix_window_posy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:32;
    };
}vdpq_dummy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
    	RBus_UInt32  dummy_6_1DPath_cnt:5;
	RBus_UInt32  dummy_6_2DPath_cnt:5;
	RBus_UInt32  dummy_6_3DPath_cnt:5;
        RBus_UInt32  dummy_6_modechange_cnt:3;
	RBus_UInt32  dummy_6_reset_debug_cnt:1;
	RBus_UInt32  dummy_6_fix_mode:3;
	RBus_UInt32  dummy_6_fix_status:2;
	RBus_UInt32  dummy_6_fix_VDPQTable_enable:1;
	RBus_UInt32  dummy_6_VDPQ_AutoMA_bypass:1;
	RBus_UInt32  dummy_6_res:6;
    };
}vdpq_dummy_6_RBUS;


typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_7:32;
    };
}vdpq_dummy_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
         RBus_UInt32  dummy_8_motion_status:4;
	 RBus_UInt32  dummy_8_log_enable:1;
	 RBus_UInt32  dummy_8_print_time:8;
	 RBus_UInt32  dummy_8_set_scan_enable:1;
	 RBus_UInt32  dummy_8_auto_disable:1;
	 RBus_UInt32  dummy_8_res:17;
    };
}vdpq_dummy_8_RBUS;





#endif


#endif
