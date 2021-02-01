/**
* @file Mac5_LGCY_VE_DEBLK_Arch_Spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_DEBLK_REG_H_
#define _RBUS_LGCY_DEBLK_REG_H_

#include "rbus_types.h"



//  LGCY_DEBLK Register Address
#define  LGCY_DEBLK_CCPAR                                                        0x1800EA00
#define  LGCY_DEBLK_CCPAR_reg_addr                                               "0xB800EA00"
#define  LGCY_DEBLK_CCPAR_reg                                                    0xB800EA00
#define  LGCY_DEBLK_CCPAR_inst_addr                                              "0x0000"
#define  set_LGCY_DEBLK_CCPAR_reg(data)                                          (*((volatile unsigned int*)LGCY_DEBLK_CCPAR_reg)=data)
#define  get_LGCY_DEBLK_CCPAR_reg                                                (*((volatile unsigned int*)LGCY_DEBLK_CCPAR_reg))
#define  LGCY_DEBLK_CCPAR_pictype_shift                                          (20)
#define  LGCY_DEBLK_CCPAR_first_mb_shift                                         (19)
#define  LGCY_DEBLK_CCPAR_cur_mb_x_shift                                         (9)
#define  LGCY_DEBLK_CCPAR_cur_mb_y_shift                                         (0)
#define  LGCY_DEBLK_CCPAR_pictype_mask                                           (0x00700000)
#define  LGCY_DEBLK_CCPAR_first_mb_mask                                          (0x00080000)
#define  LGCY_DEBLK_CCPAR_cur_mb_x_mask                                          (0x0007FE00)
#define  LGCY_DEBLK_CCPAR_cur_mb_y_mask                                          (0x000001FF)
#define  LGCY_DEBLK_CCPAR_pictype(data)                                          (0x00700000&((data)<<20))
#define  LGCY_DEBLK_CCPAR_first_mb(data)                                         (0x00080000&((data)<<19))
#define  LGCY_DEBLK_CCPAR_cur_mb_x(data)                                         (0x0007FE00&((data)<<9))
#define  LGCY_DEBLK_CCPAR_cur_mb_y(data)                                         (0x000001FF&(data))
#define  LGCY_DEBLK_CCPAR_get_pictype(data)                                      ((0x00700000&(data))>>20)
#define  LGCY_DEBLK_CCPAR_get_first_mb(data)                                     ((0x00080000&(data))>>19)
#define  LGCY_DEBLK_CCPAR_get_cur_mb_x(data)                                     ((0x0007FE00&(data))>>9)
#define  LGCY_DEBLK_CCPAR_get_cur_mb_y(data)                                     (0x000001FF&(data))

#define  LGCY_DEBLK_VC1CCPAR_0                                                   0x1800EA04
#define  LGCY_DEBLK_VC1CCPAR_0_reg_addr                                          "0xB800EA04"
#define  LGCY_DEBLK_VC1CCPAR_0_reg                                               0xB800EA04
#define  LGCY_DEBLK_VC1CCPAR_0_inst_addr                                         "0x0001"
#define  set_LGCY_DEBLK_VC1CCPAR_0_reg(data)                                     (*((volatile unsigned int*)LGCY_DEBLK_VC1CCPAR_0_reg)=data)
#define  get_LGCY_DEBLK_VC1CCPAR_0_reg                                           (*((volatile unsigned int*)LGCY_DEBLK_VC1CCPAR_0_reg))
#define  LGCY_DEBLK_VC1CCPAR_0_intramb_flag_shift                                (21)
#define  LGCY_DEBLK_VC1CCPAR_0_intra_flag_shift                                  (16)
#define  LGCY_DEBLK_VC1CCPAR_0_submb_partition_shift                             (4)
#define  LGCY_DEBLK_VC1CCPAR_0_mvtype_shift                                      (2)
#define  LGCY_DEBLK_VC1CCPAR_0_fieldtx_shift                                     (1)
#define  LGCY_DEBLK_VC1CCPAR_0_overflag_shift                                    (0)
#define  LGCY_DEBLK_VC1CCPAR_0_intramb_flag_mask                                 (0x00200000)
#define  LGCY_DEBLK_VC1CCPAR_0_intra_flag_mask                                   (0x001F0000)
#define  LGCY_DEBLK_VC1CCPAR_0_submb_partition_mask                              (0x0000FFF0)
#define  LGCY_DEBLK_VC1CCPAR_0_mvtype_mask                                       (0x0000000C)
#define  LGCY_DEBLK_VC1CCPAR_0_fieldtx_mask                                      (0x00000002)
#define  LGCY_DEBLK_VC1CCPAR_0_overflag_mask                                     (0x00000001)
#define  LGCY_DEBLK_VC1CCPAR_0_intramb_flag(data)                                (0x00200000&((data)<<21))
#define  LGCY_DEBLK_VC1CCPAR_0_intra_flag(data)                                  (0x001F0000&((data)<<16))
#define  LGCY_DEBLK_VC1CCPAR_0_submb_partition(data)                             (0x0000FFF0&((data)<<4))
#define  LGCY_DEBLK_VC1CCPAR_0_mvtype(data)                                      (0x0000000C&((data)<<2))
#define  LGCY_DEBLK_VC1CCPAR_0_fieldtx(data)                                     (0x00000002&((data)<<1))
#define  LGCY_DEBLK_VC1CCPAR_0_overflag(data)                                    (0x00000001&(data))
#define  LGCY_DEBLK_VC1CCPAR_0_get_intramb_flag(data)                            ((0x00200000&(data))>>21)
#define  LGCY_DEBLK_VC1CCPAR_0_get_intra_flag(data)                              ((0x001F0000&(data))>>16)
#define  LGCY_DEBLK_VC1CCPAR_0_get_submb_partition(data)                         ((0x0000FFF0&(data))>>4)
#define  LGCY_DEBLK_VC1CCPAR_0_get_mvtype(data)                                  ((0x0000000C&(data))>>2)
#define  LGCY_DEBLK_VC1CCPAR_0_get_fieldtx(data)                                 ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_VC1CCPAR_0_get_overflag(data)                                (0x00000001&(data))

#define  LGCY_DEBLK_VC1CCPAR_1                                                   0x1800EA08
#define  LGCY_DEBLK_VC1CCPAR_1_reg_addr                                          "0xB800EA08"
#define  LGCY_DEBLK_VC1CCPAR_1_reg                                               0xB800EA08
#define  LGCY_DEBLK_VC1CCPAR_1_inst_addr                                         "0x0002"
#define  set_LGCY_DEBLK_VC1CCPAR_1_reg(data)                                     (*((volatile unsigned int*)LGCY_DEBLK_VC1CCPAR_1_reg)=data)
#define  get_LGCY_DEBLK_VC1CCPAR_1_reg                                           (*((volatile unsigned int*)LGCY_DEBLK_VC1CCPAR_1_reg))
#define  LGCY_DEBLK_VC1CCPAR_1_intramb_flag_shift                                (21)
#define  LGCY_DEBLK_VC1CCPAR_1_intra_flag_shift                                  (16)
#define  LGCY_DEBLK_VC1CCPAR_1_submb_partition_shift                             (4)
#define  LGCY_DEBLK_VC1CCPAR_1_mvtype_shift                                      (2)
#define  LGCY_DEBLK_VC1CCPAR_1_fieldtx_shift                                     (1)
#define  LGCY_DEBLK_VC1CCPAR_1_overflag_shift                                    (0)
#define  LGCY_DEBLK_VC1CCPAR_1_intramb_flag_mask                                 (0x00200000)
#define  LGCY_DEBLK_VC1CCPAR_1_intra_flag_mask                                   (0x001F0000)
#define  LGCY_DEBLK_VC1CCPAR_1_submb_partition_mask                              (0x0000FFF0)
#define  LGCY_DEBLK_VC1CCPAR_1_mvtype_mask                                       (0x0000000C)
#define  LGCY_DEBLK_VC1CCPAR_1_fieldtx_mask                                      (0x00000002)
#define  LGCY_DEBLK_VC1CCPAR_1_overflag_mask                                     (0x00000001)
#define  LGCY_DEBLK_VC1CCPAR_1_intramb_flag(data)                                (0x00200000&((data)<<21))
#define  LGCY_DEBLK_VC1CCPAR_1_intra_flag(data)                                  (0x001F0000&((data)<<16))
#define  LGCY_DEBLK_VC1CCPAR_1_submb_partition(data)                             (0x0000FFF0&((data)<<4))
#define  LGCY_DEBLK_VC1CCPAR_1_mvtype(data)                                      (0x0000000C&((data)<<2))
#define  LGCY_DEBLK_VC1CCPAR_1_fieldtx(data)                                     (0x00000002&((data)<<1))
#define  LGCY_DEBLK_VC1CCPAR_1_overflag(data)                                    (0x00000001&(data))
#define  LGCY_DEBLK_VC1CCPAR_1_get_intramb_flag(data)                            ((0x00200000&(data))>>21)
#define  LGCY_DEBLK_VC1CCPAR_1_get_intra_flag(data)                              ((0x001F0000&(data))>>16)
#define  LGCY_DEBLK_VC1CCPAR_1_get_submb_partition(data)                         ((0x0000FFF0&(data))>>4)
#define  LGCY_DEBLK_VC1CCPAR_1_get_mvtype(data)                                  ((0x0000000C&(data))>>2)
#define  LGCY_DEBLK_VC1CCPAR_1_get_fieldtx(data)                                 ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_VC1CCPAR_1_get_overflag(data)                                (0x00000001&(data))

#define  LGCY_DEBLK_PARSA                                                        0x1800EA0C
#define  LGCY_DEBLK_PARSA_reg_addr                                               "0xB800EA0C"
#define  LGCY_DEBLK_PARSA_reg                                                    0xB800EA0C
#define  LGCY_DEBLK_PARSA_inst_addr                                              "0x0003"
#define  set_LGCY_DEBLK_PARSA_reg(data)                                          (*((volatile unsigned int*)LGCY_DEBLK_PARSA_reg)=data)
#define  get_LGCY_DEBLK_PARSA_reg                                                (*((volatile unsigned int*)LGCY_DEBLK_PARSA_reg))
#define  LGCY_DEBLK_PARSA_parcom_starta_shift                                    (0)
#define  LGCY_DEBLK_PARSA_parcom_starta_mask                                     (0x0000007F)
#define  LGCY_DEBLK_PARSA_parcom_starta(data)                                    (0x0000007F&(data))
#define  LGCY_DEBLK_PARSA_get_parcom_starta(data)                                (0x0000007F&(data))

#define  LGCY_DEBLK_NEIGHBOR                                                     0x1800EA10
#define  LGCY_DEBLK_NEIGHBOR_reg_addr                                            "0xB800EA10"
#define  LGCY_DEBLK_NEIGHBOR_reg                                                 0xB800EA10
#define  LGCY_DEBLK_NEIGHBOR_inst_addr                                           "0x0004"
#define  set_LGCY_DEBLK_NEIGHBOR_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_NEIGHBOR_reg)=data)
#define  get_LGCY_DEBLK_NEIGHBOR_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_NEIGHBOR_reg))
#define  LGCY_DEBLK_NEIGHBOR_write_enable1_shift                                 (16)
#define  LGCY_DEBLK_NEIGHBOR_new_slice_row_shift                                 (15)
#define  LGCY_DEBLK_NEIGHBOR_new_slice_mb_x_shift                                (6)
#define  LGCY_DEBLK_NEIGHBOR_write_enable0_shift                                 (5)
#define  LGCY_DEBLK_NEIGHBOR_sw_neighbor_enable_shift                            (4)
#define  LGCY_DEBLK_NEIGHBOR_mbaddra_available_shift                             (3)
#define  LGCY_DEBLK_NEIGHBOR_mbaddrb_available_shift                             (2)
#define  LGCY_DEBLK_NEIGHBOR_mbaddrd_available_shift                             (0)
#define  LGCY_DEBLK_NEIGHBOR_write_enable1_mask                                  (0x00010000)
#define  LGCY_DEBLK_NEIGHBOR_new_slice_row_mask                                  (0x00008000)
#define  LGCY_DEBLK_NEIGHBOR_new_slice_mb_x_mask                                 (0x00007FC0)
#define  LGCY_DEBLK_NEIGHBOR_write_enable0_mask                                  (0x00000020)
#define  LGCY_DEBLK_NEIGHBOR_sw_neighbor_enable_mask                             (0x00000010)
#define  LGCY_DEBLK_NEIGHBOR_mbaddra_available_mask                              (0x00000008)
#define  LGCY_DEBLK_NEIGHBOR_mbaddrb_available_mask                              (0x00000004)
#define  LGCY_DEBLK_NEIGHBOR_mbaddrd_available_mask                              (0x00000001)
#define  LGCY_DEBLK_NEIGHBOR_write_enable1(data)                                 (0x00010000&((data)<<16))
#define  LGCY_DEBLK_NEIGHBOR_new_slice_row(data)                                 (0x00008000&((data)<<15))
#define  LGCY_DEBLK_NEIGHBOR_new_slice_mb_x(data)                                (0x00007FC0&((data)<<6))
#define  LGCY_DEBLK_NEIGHBOR_write_enable0(data)                                 (0x00000020&((data)<<5))
#define  LGCY_DEBLK_NEIGHBOR_sw_neighbor_enable(data)                            (0x00000010&((data)<<4))
#define  LGCY_DEBLK_NEIGHBOR_mbaddra_available(data)                             (0x00000008&((data)<<3))
#define  LGCY_DEBLK_NEIGHBOR_mbaddrb_available(data)                             (0x00000004&((data)<<2))
#define  LGCY_DEBLK_NEIGHBOR_mbaddrd_available(data)                             (0x00000001&(data))
#define  LGCY_DEBLK_NEIGHBOR_get_write_enable1(data)                             ((0x00010000&(data))>>16)
#define  LGCY_DEBLK_NEIGHBOR_get_new_slice_row(data)                             ((0x00008000&(data))>>15)
#define  LGCY_DEBLK_NEIGHBOR_get_new_slice_mb_x(data)                            ((0x00007FC0&(data))>>6)
#define  LGCY_DEBLK_NEIGHBOR_get_write_enable0(data)                             ((0x00000020&(data))>>5)
#define  LGCY_DEBLK_NEIGHBOR_get_sw_neighbor_enable(data)                        ((0x00000010&(data))>>4)
#define  LGCY_DEBLK_NEIGHBOR_get_mbaddra_available(data)                         ((0x00000008&(data))>>3)
#define  LGCY_DEBLK_NEIGHBOR_get_mbaddrb_available(data)                         ((0x00000004&(data))>>2)
#define  LGCY_DEBLK_NEIGHBOR_get_mbaddrd_available(data)                         (0x00000001&(data))

#define  LGCY_DEBLK_DEBCNTL                                                      0x1800EA14
#define  LGCY_DEBLK_DEBCNTL_reg_addr                                             "0xB800EA14"
#define  LGCY_DEBLK_DEBCNTL_reg                                                  0xB800EA14
#define  LGCY_DEBLK_DEBCNTL_inst_addr                                            "0x0005"
#define  set_LGCY_DEBLK_DEBCNTL_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_DEBCNTL_reg)=data)
#define  get_LGCY_DEBLK_DEBCNTL_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_DEBCNTL_reg))
#define  LGCY_DEBLK_DEBCNTL_avs_alpha_c_offset_shift                             (15)
#define  LGCY_DEBLK_DEBCNTL_avs_beta_offset_shift                                (10)
#define  LGCY_DEBLK_DEBCNTL_slice_alpha_c0_offset_div2_shift                     (6)
#define  LGCY_DEBLK_DEBCNTL_slice_beta_offset_div2_shift                         (2)
#define  LGCY_DEBLK_DEBCNTL_disable_deblocking_filter_idc_shift                  (0)
#define  LGCY_DEBLK_DEBCNTL_avs_alpha_c_offset_mask                              (0x000F8000)
#define  LGCY_DEBLK_DEBCNTL_avs_beta_offset_mask                                 (0x00007C00)
#define  LGCY_DEBLK_DEBCNTL_slice_alpha_c0_offset_div2_mask                      (0x000003C0)
#define  LGCY_DEBLK_DEBCNTL_slice_beta_offset_div2_mask                          (0x0000003C)
#define  LGCY_DEBLK_DEBCNTL_disable_deblocking_filter_idc_mask                   (0x00000003)
#define  LGCY_DEBLK_DEBCNTL_avs_alpha_c_offset(data)                             (0x000F8000&((data)<<15))
#define  LGCY_DEBLK_DEBCNTL_avs_beta_offset(data)                                (0x00007C00&((data)<<10))
#define  LGCY_DEBLK_DEBCNTL_slice_alpha_c0_offset_div2(data)                     (0x000003C0&((data)<<6))
#define  LGCY_DEBLK_DEBCNTL_slice_beta_offset_div2(data)                         (0x0000003C&((data)<<2))
#define  LGCY_DEBLK_DEBCNTL_disable_deblocking_filter_idc(data)                  (0x00000003&(data))
#define  LGCY_DEBLK_DEBCNTL_get_avs_alpha_c_offset(data)                         ((0x000F8000&(data))>>15)
#define  LGCY_DEBLK_DEBCNTL_get_avs_beta_offset(data)                            ((0x00007C00&(data))>>10)
#define  LGCY_DEBLK_DEBCNTL_get_slice_alpha_c0_offset_div2(data)                 ((0x000003C0&(data))>>6)
#define  LGCY_DEBLK_DEBCNTL_get_slice_beta_offset_div2(data)                     ((0x0000003C&(data))>>2)
#define  LGCY_DEBLK_DEBCNTL_get_disable_deblocking_filter_idc(data)              (0x00000003&(data))

#define  LGCY_DEBLK_DEBCNTL2                                                     0x1800EA18
#define  LGCY_DEBLK_DEBCNTL2_reg_addr                                            "0xB800EA18"
#define  LGCY_DEBLK_DEBCNTL2_reg                                                 0xB800EA18
#define  LGCY_DEBLK_DEBCNTL2_inst_addr                                           "0x0006"
#define  set_LGCY_DEBLK_DEBCNTL2_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DEBCNTL2_reg)=data)
#define  get_LGCY_DEBLK_DEBCNTL2_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DEBCNTL2_reg))
#define  LGCY_DEBLK_DEBCNTL2_lambda_mode_shift                                   (12)
#define  LGCY_DEBLK_DEBCNTL2_thr_3_shift                                         (8)
#define  LGCY_DEBLK_DEBCNTL2_thr_2_shift                                         (4)
#define  LGCY_DEBLK_DEBCNTL2_thr_1_shift                                         (0)
#define  LGCY_DEBLK_DEBCNTL2_lambda_mode_mask                                    (0x00001000)
#define  LGCY_DEBLK_DEBCNTL2_thr_3_mask                                          (0x00000F00)
#define  LGCY_DEBLK_DEBCNTL2_thr_2_mask                                          (0x000000F0)
#define  LGCY_DEBLK_DEBCNTL2_thr_1_mask                                          (0x0000000F)
#define  LGCY_DEBLK_DEBCNTL2_lambda_mode(data)                                   (0x00001000&((data)<<12))
#define  LGCY_DEBLK_DEBCNTL2_thr_3(data)                                         (0x00000F00&((data)<<8))
#define  LGCY_DEBLK_DEBCNTL2_thr_2(data)                                         (0x000000F0&((data)<<4))
#define  LGCY_DEBLK_DEBCNTL2_thr_1(data)                                         (0x0000000F&(data))
#define  LGCY_DEBLK_DEBCNTL2_get_lambda_mode(data)                               ((0x00001000&(data))>>12)
#define  LGCY_DEBLK_DEBCNTL2_get_thr_3(data)                                     ((0x00000F00&(data))>>8)
#define  LGCY_DEBLK_DEBCNTL2_get_thr_2(data)                                     ((0x000000F0&(data))>>4)
#define  LGCY_DEBLK_DEBCNTL2_get_thr_1(data)                                     (0x0000000F&(data))

#define  LGCY_DEBLK_H264CCPAR                                                    0x1800EA1C
#define  LGCY_DEBLK_H264CCPAR_reg_addr                                           "0xB800EA1C"
#define  LGCY_DEBLK_H264CCPAR_reg                                                0xB800EA1C
#define  LGCY_DEBLK_H264CCPAR_inst_addr                                          "0x0007"
#define  set_LGCY_DEBLK_H264CCPAR_reg(data)                                      (*((volatile unsigned int*)LGCY_DEBLK_H264CCPAR_reg)=data)
#define  get_LGCY_DEBLK_H264CCPAR_reg                                            (*((volatile unsigned int*)LGCY_DEBLK_H264CCPAR_reg))
#define  LGCY_DEBLK_H264CCPAR_dmy_auto_mode_shift                                (2)
#define  LGCY_DEBLK_H264CCPAR_dmy_mb_row_shift                                   (1)
#define  LGCY_DEBLK_H264CCPAR_dmy_mb_clm_shift                                   (0)
#define  LGCY_DEBLK_H264CCPAR_dmy_auto_mode_mask                                 (0x00000004)
#define  LGCY_DEBLK_H264CCPAR_dmy_mb_row_mask                                    (0x00000002)
#define  LGCY_DEBLK_H264CCPAR_dmy_mb_clm_mask                                    (0x00000001)
#define  LGCY_DEBLK_H264CCPAR_dmy_auto_mode(data)                                (0x00000004&((data)<<2))
#define  LGCY_DEBLK_H264CCPAR_dmy_mb_row(data)                                   (0x00000002&((data)<<1))
#define  LGCY_DEBLK_H264CCPAR_dmy_mb_clm(data)                                   (0x00000001&(data))
#define  LGCY_DEBLK_H264CCPAR_get_dmy_auto_mode(data)                            ((0x00000004&(data))>>2)
#define  LGCY_DEBLK_H264CCPAR_get_dmy_mb_row(data)                               ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_H264CCPAR_get_dmy_mb_clm(data)                               (0x00000001&(data))

#define  LGCY_DEBLK_H264DBPAR0_0                                                 0x1800EA20
#define  LGCY_DEBLK_H264DBPAR0_0_reg_addr                                        "0xB800EA20"
#define  LGCY_DEBLK_H264DBPAR0_0_reg                                             0xB800EA20
#define  LGCY_DEBLK_H264DBPAR0_0_inst_addr                                       "0x0008"
#define  set_LGCY_DEBLK_H264DBPAR0_0_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_0_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR0_0_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_0_reg))
#define  LGCY_DEBLK_H264DBPAR0_0_intra_flag_shift                                (29)
#define  LGCY_DEBLK_H264DBPAR0_0_transform_size_8x8_flag_shift                   (28)
#define  LGCY_DEBLK_H264DBPAR0_0_qpy_shift                                       (22)
#define  LGCY_DEBLK_H264DBPAR0_0_qpcb_shift                                      (16)
#define  LGCY_DEBLK_H264DBPAR0_0_qpcr_shift                                      (10)
#define  LGCY_DEBLK_H264DBPAR0_0_mb_field_decoding_flag_shift                    (9)
#define  LGCY_DEBLK_H264DBPAR0_0_mb_partition_shift                              (0)
#define  LGCY_DEBLK_H264DBPAR0_0_intra_flag_mask                                 (0x20000000)
#define  LGCY_DEBLK_H264DBPAR0_0_transform_size_8x8_flag_mask                    (0x10000000)
#define  LGCY_DEBLK_H264DBPAR0_0_qpy_mask                                        (0x0FC00000)
#define  LGCY_DEBLK_H264DBPAR0_0_qpcb_mask                                       (0x003F0000)
#define  LGCY_DEBLK_H264DBPAR0_0_qpcr_mask                                       (0x0000FC00)
#define  LGCY_DEBLK_H264DBPAR0_0_mb_field_decoding_flag_mask                     (0x00000200)
#define  LGCY_DEBLK_H264DBPAR0_0_mb_partition_mask                               (0x000001FF)
#define  LGCY_DEBLK_H264DBPAR0_0_intra_flag(data)                                (0x20000000&((data)<<29))
#define  LGCY_DEBLK_H264DBPAR0_0_transform_size_8x8_flag(data)                   (0x10000000&((data)<<28))
#define  LGCY_DEBLK_H264DBPAR0_0_qpy(data)                                       (0x0FC00000&((data)<<22))
#define  LGCY_DEBLK_H264DBPAR0_0_qpcb(data)                                      (0x003F0000&((data)<<16))
#define  LGCY_DEBLK_H264DBPAR0_0_qpcr(data)                                      (0x0000FC00&((data)<<10))
#define  LGCY_DEBLK_H264DBPAR0_0_mb_field_decoding_flag(data)                    (0x00000200&((data)<<9))
#define  LGCY_DEBLK_H264DBPAR0_0_mb_partition(data)                              (0x000001FF&(data))
#define  LGCY_DEBLK_H264DBPAR0_0_get_intra_flag(data)                            ((0x20000000&(data))>>29)
#define  LGCY_DEBLK_H264DBPAR0_0_get_transform_size_8x8_flag(data)               ((0x10000000&(data))>>28)
#define  LGCY_DEBLK_H264DBPAR0_0_get_qpy(data)                                   ((0x0FC00000&(data))>>22)
#define  LGCY_DEBLK_H264DBPAR0_0_get_qpcb(data)                                  ((0x003F0000&(data))>>16)
#define  LGCY_DEBLK_H264DBPAR0_0_get_qpcr(data)                                  ((0x0000FC00&(data))>>10)
#define  LGCY_DEBLK_H264DBPAR0_0_get_mb_field_decoding_flag(data)                ((0x00000200&(data))>>9)
#define  LGCY_DEBLK_H264DBPAR0_0_get_mb_partition(data)                          (0x000001FF&(data))

#define  LGCY_DEBLK_H264DBPAR0_1                                                 0x1800EA24
#define  LGCY_DEBLK_H264DBPAR0_1_reg_addr                                        "0xB800EA24"
#define  LGCY_DEBLK_H264DBPAR0_1_reg                                             0xB800EA24
#define  LGCY_DEBLK_H264DBPAR0_1_inst_addr                                       "0x0009"
#define  set_LGCY_DEBLK_H264DBPAR0_1_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_1_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR0_1_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_1_reg))
#define  LGCY_DEBLK_H264DBPAR0_1_intra_flag_shift                                (29)
#define  LGCY_DEBLK_H264DBPAR0_1_transform_size_8x8_flag_shift                   (28)
#define  LGCY_DEBLK_H264DBPAR0_1_qpy_shift                                       (22)
#define  LGCY_DEBLK_H264DBPAR0_1_qpcb_shift                                      (16)
#define  LGCY_DEBLK_H264DBPAR0_1_qpcr_shift                                      (10)
#define  LGCY_DEBLK_H264DBPAR0_1_mb_field_decoding_flag_shift                    (9)
#define  LGCY_DEBLK_H264DBPAR0_1_mb_partition_shift                              (0)
#define  LGCY_DEBLK_H264DBPAR0_1_intra_flag_mask                                 (0x20000000)
#define  LGCY_DEBLK_H264DBPAR0_1_transform_size_8x8_flag_mask                    (0x10000000)
#define  LGCY_DEBLK_H264DBPAR0_1_qpy_mask                                        (0x0FC00000)
#define  LGCY_DEBLK_H264DBPAR0_1_qpcb_mask                                       (0x003F0000)
#define  LGCY_DEBLK_H264DBPAR0_1_qpcr_mask                                       (0x0000FC00)
#define  LGCY_DEBLK_H264DBPAR0_1_mb_field_decoding_flag_mask                     (0x00000200)
#define  LGCY_DEBLK_H264DBPAR0_1_mb_partition_mask                               (0x000001FF)
#define  LGCY_DEBLK_H264DBPAR0_1_intra_flag(data)                                (0x20000000&((data)<<29))
#define  LGCY_DEBLK_H264DBPAR0_1_transform_size_8x8_flag(data)                   (0x10000000&((data)<<28))
#define  LGCY_DEBLK_H264DBPAR0_1_qpy(data)                                       (0x0FC00000&((data)<<22))
#define  LGCY_DEBLK_H264DBPAR0_1_qpcb(data)                                      (0x003F0000&((data)<<16))
#define  LGCY_DEBLK_H264DBPAR0_1_qpcr(data)                                      (0x0000FC00&((data)<<10))
#define  LGCY_DEBLK_H264DBPAR0_1_mb_field_decoding_flag(data)                    (0x00000200&((data)<<9))
#define  LGCY_DEBLK_H264DBPAR0_1_mb_partition(data)                              (0x000001FF&(data))
#define  LGCY_DEBLK_H264DBPAR0_1_get_intra_flag(data)                            ((0x20000000&(data))>>29)
#define  LGCY_DEBLK_H264DBPAR0_1_get_transform_size_8x8_flag(data)               ((0x10000000&(data))>>28)
#define  LGCY_DEBLK_H264DBPAR0_1_get_qpy(data)                                   ((0x0FC00000&(data))>>22)
#define  LGCY_DEBLK_H264DBPAR0_1_get_qpcb(data)                                  ((0x003F0000&(data))>>16)
#define  LGCY_DEBLK_H264DBPAR0_1_get_qpcr(data)                                  ((0x0000FC00&(data))>>10)
#define  LGCY_DEBLK_H264DBPAR0_1_get_mb_field_decoding_flag(data)                ((0x00000200&(data))>>9)
#define  LGCY_DEBLK_H264DBPAR0_1_get_mb_partition(data)                          (0x000001FF&(data))

#define  LGCY_DEBLK_H264DBPAR0_2                                                 0x1800EA28
#define  LGCY_DEBLK_H264DBPAR0_2_reg_addr                                        "0xB800EA28"
#define  LGCY_DEBLK_H264DBPAR0_2_reg                                             0xB800EA28
#define  LGCY_DEBLK_H264DBPAR0_2_inst_addr                                       "0x000A"
#define  set_LGCY_DEBLK_H264DBPAR0_2_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_2_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR0_2_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_2_reg))
#define  LGCY_DEBLK_H264DBPAR0_2_intra_flag_shift                                (29)
#define  LGCY_DEBLK_H264DBPAR0_2_transform_size_8x8_flag_shift                   (28)
#define  LGCY_DEBLK_H264DBPAR0_2_qpy_shift                                       (22)
#define  LGCY_DEBLK_H264DBPAR0_2_qpcb_shift                                      (16)
#define  LGCY_DEBLK_H264DBPAR0_2_qpcr_shift                                      (10)
#define  LGCY_DEBLK_H264DBPAR0_2_mb_field_decoding_flag_shift                    (9)
#define  LGCY_DEBLK_H264DBPAR0_2_mb_partition_shift                              (0)
#define  LGCY_DEBLK_H264DBPAR0_2_intra_flag_mask                                 (0x20000000)
#define  LGCY_DEBLK_H264DBPAR0_2_transform_size_8x8_flag_mask                    (0x10000000)
#define  LGCY_DEBLK_H264DBPAR0_2_qpy_mask                                        (0x0FC00000)
#define  LGCY_DEBLK_H264DBPAR0_2_qpcb_mask                                       (0x003F0000)
#define  LGCY_DEBLK_H264DBPAR0_2_qpcr_mask                                       (0x0000FC00)
#define  LGCY_DEBLK_H264DBPAR0_2_mb_field_decoding_flag_mask                     (0x00000200)
#define  LGCY_DEBLK_H264DBPAR0_2_mb_partition_mask                               (0x000001FF)
#define  LGCY_DEBLK_H264DBPAR0_2_intra_flag(data)                                (0x20000000&((data)<<29))
#define  LGCY_DEBLK_H264DBPAR0_2_transform_size_8x8_flag(data)                   (0x10000000&((data)<<28))
#define  LGCY_DEBLK_H264DBPAR0_2_qpy(data)                                       (0x0FC00000&((data)<<22))
#define  LGCY_DEBLK_H264DBPAR0_2_qpcb(data)                                      (0x003F0000&((data)<<16))
#define  LGCY_DEBLK_H264DBPAR0_2_qpcr(data)                                      (0x0000FC00&((data)<<10))
#define  LGCY_DEBLK_H264DBPAR0_2_mb_field_decoding_flag(data)                    (0x00000200&((data)<<9))
#define  LGCY_DEBLK_H264DBPAR0_2_mb_partition(data)                              (0x000001FF&(data))
#define  LGCY_DEBLK_H264DBPAR0_2_get_intra_flag(data)                            ((0x20000000&(data))>>29)
#define  LGCY_DEBLK_H264DBPAR0_2_get_transform_size_8x8_flag(data)               ((0x10000000&(data))>>28)
#define  LGCY_DEBLK_H264DBPAR0_2_get_qpy(data)                                   ((0x0FC00000&(data))>>22)
#define  LGCY_DEBLK_H264DBPAR0_2_get_qpcb(data)                                  ((0x003F0000&(data))>>16)
#define  LGCY_DEBLK_H264DBPAR0_2_get_qpcr(data)                                  ((0x0000FC00&(data))>>10)
#define  LGCY_DEBLK_H264DBPAR0_2_get_mb_field_decoding_flag(data)                ((0x00000200&(data))>>9)
#define  LGCY_DEBLK_H264DBPAR0_2_get_mb_partition(data)                          (0x000001FF&(data))

#define  LGCY_DEBLK_H264DBPAR0_3                                                 0x1800EA2C
#define  LGCY_DEBLK_H264DBPAR0_3_reg_addr                                        "0xB800EA2C"
#define  LGCY_DEBLK_H264DBPAR0_3_reg                                             0xB800EA2C
#define  LGCY_DEBLK_H264DBPAR0_3_inst_addr                                       "0x000B"
#define  set_LGCY_DEBLK_H264DBPAR0_3_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_3_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR0_3_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR0_3_reg))
#define  LGCY_DEBLK_H264DBPAR0_3_intra_flag_shift                                (29)
#define  LGCY_DEBLK_H264DBPAR0_3_transform_size_8x8_flag_shift                   (28)
#define  LGCY_DEBLK_H264DBPAR0_3_qpy_shift                                       (22)
#define  LGCY_DEBLK_H264DBPAR0_3_qpcb_shift                                      (16)
#define  LGCY_DEBLK_H264DBPAR0_3_qpcr_shift                                      (10)
#define  LGCY_DEBLK_H264DBPAR0_3_mb_field_decoding_flag_shift                    (9)
#define  LGCY_DEBLK_H264DBPAR0_3_mb_partition_shift                              (0)
#define  LGCY_DEBLK_H264DBPAR0_3_intra_flag_mask                                 (0x20000000)
#define  LGCY_DEBLK_H264DBPAR0_3_transform_size_8x8_flag_mask                    (0x10000000)
#define  LGCY_DEBLK_H264DBPAR0_3_qpy_mask                                        (0x0FC00000)
#define  LGCY_DEBLK_H264DBPAR0_3_qpcb_mask                                       (0x003F0000)
#define  LGCY_DEBLK_H264DBPAR0_3_qpcr_mask                                       (0x0000FC00)
#define  LGCY_DEBLK_H264DBPAR0_3_mb_field_decoding_flag_mask                     (0x00000200)
#define  LGCY_DEBLK_H264DBPAR0_3_mb_partition_mask                               (0x000001FF)
#define  LGCY_DEBLK_H264DBPAR0_3_intra_flag(data)                                (0x20000000&((data)<<29))
#define  LGCY_DEBLK_H264DBPAR0_3_transform_size_8x8_flag(data)                   (0x10000000&((data)<<28))
#define  LGCY_DEBLK_H264DBPAR0_3_qpy(data)                                       (0x0FC00000&((data)<<22))
#define  LGCY_DEBLK_H264DBPAR0_3_qpcb(data)                                      (0x003F0000&((data)<<16))
#define  LGCY_DEBLK_H264DBPAR0_3_qpcr(data)                                      (0x0000FC00&((data)<<10))
#define  LGCY_DEBLK_H264DBPAR0_3_mb_field_decoding_flag(data)                    (0x00000200&((data)<<9))
#define  LGCY_DEBLK_H264DBPAR0_3_mb_partition(data)                              (0x000001FF&(data))
#define  LGCY_DEBLK_H264DBPAR0_3_get_intra_flag(data)                            ((0x20000000&(data))>>29)
#define  LGCY_DEBLK_H264DBPAR0_3_get_transform_size_8x8_flag(data)               ((0x10000000&(data))>>28)
#define  LGCY_DEBLK_H264DBPAR0_3_get_qpy(data)                                   ((0x0FC00000&(data))>>22)
#define  LGCY_DEBLK_H264DBPAR0_3_get_qpcb(data)                                  ((0x003F0000&(data))>>16)
#define  LGCY_DEBLK_H264DBPAR0_3_get_qpcr(data)                                  ((0x0000FC00&(data))>>10)
#define  LGCY_DEBLK_H264DBPAR0_3_get_mb_field_decoding_flag(data)                ((0x00000200&(data))>>9)
#define  LGCY_DEBLK_H264DBPAR0_3_get_mb_partition(data)                          (0x000001FF&(data))

#define  LGCY_DEBLK_H264DBPAR1_0                                                 0x1800EA30
#define  LGCY_DEBLK_H264DBPAR1_0_reg_addr                                        "0xB800EA30"
#define  LGCY_DEBLK_H264DBPAR1_0_reg                                             0xB800EA30
#define  LGCY_DEBLK_H264DBPAR1_0_inst_addr                                       "0x000C"
#define  set_LGCY_DEBLK_H264DBPAR1_0_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_0_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR1_0_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_0_reg))
#define  LGCY_DEBLK_H264DBPAR1_0_bs1_valid_ext_shift                             (24)
#define  LGCY_DEBLK_H264DBPAR1_0_subblkpat_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR1_0_bs1_valid_ext_mask                              (0x0F000000)
#define  LGCY_DEBLK_H264DBPAR1_0_subblkpat_mask                                  (0x00FFFFFF)
#define  LGCY_DEBLK_H264DBPAR1_0_bs1_valid_ext(data)                             (0x0F000000&((data)<<24))
#define  LGCY_DEBLK_H264DBPAR1_0_subblkpat(data)                                 (0x00FFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR1_0_get_bs1_valid_ext(data)                         ((0x0F000000&(data))>>24)
#define  LGCY_DEBLK_H264DBPAR1_0_get_subblkpat(data)                             (0x00FFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR1_1                                                 0x1800EA34
#define  LGCY_DEBLK_H264DBPAR1_1_reg_addr                                        "0xB800EA34"
#define  LGCY_DEBLK_H264DBPAR1_1_reg                                             0xB800EA34
#define  LGCY_DEBLK_H264DBPAR1_1_inst_addr                                       "0x000D"
#define  set_LGCY_DEBLK_H264DBPAR1_1_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_1_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR1_1_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_1_reg))
#define  LGCY_DEBLK_H264DBPAR1_1_bs1_valid_ext_shift                             (24)
#define  LGCY_DEBLK_H264DBPAR1_1_subblkpat_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR1_1_bs1_valid_ext_mask                              (0x0F000000)
#define  LGCY_DEBLK_H264DBPAR1_1_subblkpat_mask                                  (0x00FFFFFF)
#define  LGCY_DEBLK_H264DBPAR1_1_bs1_valid_ext(data)                             (0x0F000000&((data)<<24))
#define  LGCY_DEBLK_H264DBPAR1_1_subblkpat(data)                                 (0x00FFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR1_1_get_bs1_valid_ext(data)                         ((0x0F000000&(data))>>24)
#define  LGCY_DEBLK_H264DBPAR1_1_get_subblkpat(data)                             (0x00FFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR1_2                                                 0x1800EA38
#define  LGCY_DEBLK_H264DBPAR1_2_reg_addr                                        "0xB800EA38"
#define  LGCY_DEBLK_H264DBPAR1_2_reg                                             0xB800EA38
#define  LGCY_DEBLK_H264DBPAR1_2_inst_addr                                       "0x000E"
#define  set_LGCY_DEBLK_H264DBPAR1_2_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_2_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR1_2_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_2_reg))
#define  LGCY_DEBLK_H264DBPAR1_2_bs1_valid_ext_shift                             (24)
#define  LGCY_DEBLK_H264DBPAR1_2_subblkpat_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR1_2_bs1_valid_ext_mask                              (0x0F000000)
#define  LGCY_DEBLK_H264DBPAR1_2_subblkpat_mask                                  (0x00FFFFFF)
#define  LGCY_DEBLK_H264DBPAR1_2_bs1_valid_ext(data)                             (0x0F000000&((data)<<24))
#define  LGCY_DEBLK_H264DBPAR1_2_subblkpat(data)                                 (0x00FFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR1_2_get_bs1_valid_ext(data)                         ((0x0F000000&(data))>>24)
#define  LGCY_DEBLK_H264DBPAR1_2_get_subblkpat(data)                             (0x00FFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR1_3                                                 0x1800EA3C
#define  LGCY_DEBLK_H264DBPAR1_3_reg_addr                                        "0xB800EA3C"
#define  LGCY_DEBLK_H264DBPAR1_3_reg                                             0xB800EA3C
#define  LGCY_DEBLK_H264DBPAR1_3_inst_addr                                       "0x000F"
#define  set_LGCY_DEBLK_H264DBPAR1_3_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_3_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR1_3_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR1_3_reg))
#define  LGCY_DEBLK_H264DBPAR1_3_bs1_valid_ext_shift                             (24)
#define  LGCY_DEBLK_H264DBPAR1_3_subblkpat_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR1_3_bs1_valid_ext_mask                              (0x0F000000)
#define  LGCY_DEBLK_H264DBPAR1_3_subblkpat_mask                                  (0x00FFFFFF)
#define  LGCY_DEBLK_H264DBPAR1_3_bs1_valid_ext(data)                             (0x0F000000&((data)<<24))
#define  LGCY_DEBLK_H264DBPAR1_3_subblkpat(data)                                 (0x00FFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR1_3_get_bs1_valid_ext(data)                         ((0x0F000000&(data))>>24)
#define  LGCY_DEBLK_H264DBPAR1_3_get_subblkpat(data)                             (0x00FFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR2_0                                                 0x1800EA40
#define  LGCY_DEBLK_H264DBPAR2_0_reg_addr                                        "0xB800EA40"
#define  LGCY_DEBLK_H264DBPAR2_0_reg                                             0xB800EA40
#define  LGCY_DEBLK_H264DBPAR2_0_inst_addr                                       "0x0010"
#define  set_LGCY_DEBLK_H264DBPAR2_0_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_0_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR2_0_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_0_reg))
#define  LGCY_DEBLK_H264DBPAR2_0_bs1_valid_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR2_0_bs1_valid_mask                                  (0xFFFFFFFF)
#define  LGCY_DEBLK_H264DBPAR2_0_bs1_valid(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR2_0_get_bs1_valid(data)                             (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR2_1                                                 0x1800EA44
#define  LGCY_DEBLK_H264DBPAR2_1_reg_addr                                        "0xB800EA44"
#define  LGCY_DEBLK_H264DBPAR2_1_reg                                             0xB800EA44
#define  LGCY_DEBLK_H264DBPAR2_1_inst_addr                                       "0x0011"
#define  set_LGCY_DEBLK_H264DBPAR2_1_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_1_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR2_1_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_1_reg))
#define  LGCY_DEBLK_H264DBPAR2_1_bs1_valid_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR2_1_bs1_valid_mask                                  (0xFFFFFFFF)
#define  LGCY_DEBLK_H264DBPAR2_1_bs1_valid(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR2_1_get_bs1_valid(data)                             (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR2_2                                                 0x1800EA48
#define  LGCY_DEBLK_H264DBPAR2_2_reg_addr                                        "0xB800EA48"
#define  LGCY_DEBLK_H264DBPAR2_2_reg                                             0xB800EA48
#define  LGCY_DEBLK_H264DBPAR2_2_inst_addr                                       "0x0012"
#define  set_LGCY_DEBLK_H264DBPAR2_2_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_2_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR2_2_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_2_reg))
#define  LGCY_DEBLK_H264DBPAR2_2_bs1_valid_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR2_2_bs1_valid_mask                                  (0xFFFFFFFF)
#define  LGCY_DEBLK_H264DBPAR2_2_bs1_valid(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR2_2_get_bs1_valid(data)                             (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_H264DBPAR2_3                                                 0x1800EA4C
#define  LGCY_DEBLK_H264DBPAR2_3_reg_addr                                        "0xB800EA4C"
#define  LGCY_DEBLK_H264DBPAR2_3_reg                                             0xB800EA4C
#define  LGCY_DEBLK_H264DBPAR2_3_inst_addr                                       "0x0013"
#define  set_LGCY_DEBLK_H264DBPAR2_3_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_3_reg)=data)
#define  get_LGCY_DEBLK_H264DBPAR2_3_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_H264DBPAR2_3_reg))
#define  LGCY_DEBLK_H264DBPAR2_3_bs1_valid_shift                                 (0)
#define  LGCY_DEBLK_H264DBPAR2_3_bs1_valid_mask                                  (0xFFFFFFFF)
#define  LGCY_DEBLK_H264DBPAR2_3_bs1_valid(data)                                 (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_H264DBPAR2_3_get_bs1_valid(data)                             (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_VC1DBPAR0_0                                                  0x1800EA50
#define  LGCY_DEBLK_VC1DBPAR0_0_reg_addr                                         "0xB800EA50"
#define  LGCY_DEBLK_VC1DBPAR0_0_reg                                              0xB800EA50
#define  LGCY_DEBLK_VC1DBPAR0_0_inst_addr                                        "0x0014"
#define  set_LGCY_DEBLK_VC1DBPAR0_0_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR0_0_reg)=data)
#define  get_LGCY_DEBLK_VC1DBPAR0_0_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR0_0_reg))
#define  LGCY_DEBLK_VC1DBPAR0_0_lu_mv_equal_shift                                (0)
#define  LGCY_DEBLK_VC1DBPAR0_0_lu_mv_equal_mask                                 (0xFFFFFFFF)
#define  LGCY_DEBLK_VC1DBPAR0_0_lu_mv_equal(data)                                (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_VC1DBPAR0_0_get_lu_mv_equal(data)                            (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_VC1DBPAR0_1                                                  0x1800EA54
#define  LGCY_DEBLK_VC1DBPAR0_1_reg_addr                                         "0xB800EA54"
#define  LGCY_DEBLK_VC1DBPAR0_1_reg                                              0xB800EA54
#define  LGCY_DEBLK_VC1DBPAR0_1_inst_addr                                        "0x0015"
#define  set_LGCY_DEBLK_VC1DBPAR0_1_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR0_1_reg)=data)
#define  get_LGCY_DEBLK_VC1DBPAR0_1_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR0_1_reg))
#define  LGCY_DEBLK_VC1DBPAR0_1_lu_mv_equal_shift                                (0)
#define  LGCY_DEBLK_VC1DBPAR0_1_lu_mv_equal_mask                                 (0xFFFFFFFF)
#define  LGCY_DEBLK_VC1DBPAR0_1_lu_mv_equal(data)                                (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_VC1DBPAR0_1_get_lu_mv_equal(data)                            (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_VC1DBPAR1_0                                                  0x1800EA58
#define  LGCY_DEBLK_VC1DBPAR1_0_reg_addr                                         "0xB800EA58"
#define  LGCY_DEBLK_VC1DBPAR1_0_reg                                              0xB800EA58
#define  LGCY_DEBLK_VC1DBPAR1_0_inst_addr                                        "0x0016"
#define  set_LGCY_DEBLK_VC1DBPAR1_0_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR1_0_reg)=data)
#define  get_LGCY_DEBLK_VC1DBPAR1_0_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR1_0_reg))
#define  LGCY_DEBLK_VC1DBPAR1_0_subblkpat_shift                                  (8)
#define  LGCY_DEBLK_VC1DBPAR1_0_ch_mv_equal_shift                                (0)
#define  LGCY_DEBLK_VC1DBPAR1_0_subblkpat_mask                                   (0xFFFFFF00)
#define  LGCY_DEBLK_VC1DBPAR1_0_ch_mv_equal_mask                                 (0x000000FF)
#define  LGCY_DEBLK_VC1DBPAR1_0_subblkpat(data)                                  (0xFFFFFF00&((data)<<8))
#define  LGCY_DEBLK_VC1DBPAR1_0_ch_mv_equal(data)                                (0x000000FF&(data))
#define  LGCY_DEBLK_VC1DBPAR1_0_get_subblkpat(data)                              ((0xFFFFFF00&(data))>>8)
#define  LGCY_DEBLK_VC1DBPAR1_0_get_ch_mv_equal(data)                            (0x000000FF&(data))

#define  LGCY_DEBLK_VC1DBPAR1_1                                                  0x1800EA5C
#define  LGCY_DEBLK_VC1DBPAR1_1_reg_addr                                         "0xB800EA5C"
#define  LGCY_DEBLK_VC1DBPAR1_1_reg                                              0xB800EA5C
#define  LGCY_DEBLK_VC1DBPAR1_1_inst_addr                                        "0x0017"
#define  set_LGCY_DEBLK_VC1DBPAR1_1_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR1_1_reg)=data)
#define  get_LGCY_DEBLK_VC1DBPAR1_1_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_VC1DBPAR1_1_reg))
#define  LGCY_DEBLK_VC1DBPAR1_1_subblkpat_shift                                  (8)
#define  LGCY_DEBLK_VC1DBPAR1_1_ch_mv_equal_shift                                (0)
#define  LGCY_DEBLK_VC1DBPAR1_1_subblkpat_mask                                   (0xFFFFFF00)
#define  LGCY_DEBLK_VC1DBPAR1_1_ch_mv_equal_mask                                 (0x000000FF)
#define  LGCY_DEBLK_VC1DBPAR1_1_subblkpat(data)                                  (0xFFFFFF00&((data)<<8))
#define  LGCY_DEBLK_VC1DBPAR1_1_ch_mv_equal(data)                                (0x000000FF&(data))
#define  LGCY_DEBLK_VC1DBPAR1_1_get_subblkpat(data)                              ((0xFFFFFF00&(data))>>8)
#define  LGCY_DEBLK_VC1DBPAR1_1_get_ch_mv_equal(data)                            (0x000000FF&(data))

#define  LGCY_DEBLK_RVCTRL                                                       0x1800EA60
#define  LGCY_DEBLK_RVCTRL_reg_addr                                              "0xB800EA60"
#define  LGCY_DEBLK_RVCTRL_reg                                                   0xB800EA60
#define  LGCY_DEBLK_RVCTRL_inst_addr                                             "0x0018"
#define  set_LGCY_DEBLK_RVCTRL_reg(data)                                         (*((volatile unsigned int*)LGCY_DEBLK_RVCTRL_reg)=data)
#define  get_LGCY_DEBLK_RVCTRL_reg                                               (*((volatile unsigned int*)LGCY_DEBLK_RVCTRL_reg))
#define  LGCY_DEBLK_RVCTRL_write_enable3_shift                                   (27)
#define  LGCY_DEBLK_RVCTRL_refqp_shift                                           (22)
#define  LGCY_DEBLK_RVCTRL_beta2sel_shift                                        (21)
#define  LGCY_DEBLK_RVCTRL_write_enable2_shift                                   (20)
#define  LGCY_DEBLK_RVCTRL_is_key_frame_shift                                    (19)
#define  LGCY_DEBLK_RVCTRL_chroma_only_shift                                     (18)
#define  LGCY_DEBLK_RVCTRL_write_enable1_shift                                   (17)
#define  LGCY_DEBLK_RVCTRL_sel_s_chroma_deblock_shift                            (16)
#define  LGCY_DEBLK_RVCTRL_write_enable0_shift                                   (15)
#define  LGCY_DEBLK_RVCTRL_str9_initqp_shift                                     (10)
#define  LGCY_DEBLK_RVCTRL_str8_initqp_shift                                     (5)
#define  LGCY_DEBLK_RVCTRL_str7_initqp_shift                                     (0)
#define  LGCY_DEBLK_RVCTRL_write_enable3_mask                                    (0x08000000)
#define  LGCY_DEBLK_RVCTRL_refqp_mask                                            (0x07C00000)
#define  LGCY_DEBLK_RVCTRL_beta2sel_mask                                         (0x00200000)
#define  LGCY_DEBLK_RVCTRL_write_enable2_mask                                    (0x00100000)
#define  LGCY_DEBLK_RVCTRL_is_key_frame_mask                                     (0x00080000)
#define  LGCY_DEBLK_RVCTRL_chroma_only_mask                                      (0x00040000)
#define  LGCY_DEBLK_RVCTRL_write_enable1_mask                                    (0x00020000)
#define  LGCY_DEBLK_RVCTRL_sel_s_chroma_deblock_mask                             (0x00010000)
#define  LGCY_DEBLK_RVCTRL_write_enable0_mask                                    (0x00008000)
#define  LGCY_DEBLK_RVCTRL_str9_initqp_mask                                      (0x00007C00)
#define  LGCY_DEBLK_RVCTRL_str8_initqp_mask                                      (0x000003E0)
#define  LGCY_DEBLK_RVCTRL_str7_initqp_mask                                      (0x0000001F)
#define  LGCY_DEBLK_RVCTRL_write_enable3(data)                                   (0x08000000&((data)<<27))
#define  LGCY_DEBLK_RVCTRL_refqp(data)                                           (0x07C00000&((data)<<22))
#define  LGCY_DEBLK_RVCTRL_beta2sel(data)                                        (0x00200000&((data)<<21))
#define  LGCY_DEBLK_RVCTRL_write_enable2(data)                                   (0x00100000&((data)<<20))
#define  LGCY_DEBLK_RVCTRL_is_key_frame(data)                                    (0x00080000&((data)<<19))
#define  LGCY_DEBLK_RVCTRL_chroma_only(data)                                     (0x00040000&((data)<<18))
#define  LGCY_DEBLK_RVCTRL_write_enable1(data)                                   (0x00020000&((data)<<17))
#define  LGCY_DEBLK_RVCTRL_sel_s_chroma_deblock(data)                            (0x00010000&((data)<<16))
#define  LGCY_DEBLK_RVCTRL_write_enable0(data)                                   (0x00008000&((data)<<15))
#define  LGCY_DEBLK_RVCTRL_str9_initqp(data)                                     (0x00007C00&((data)<<10))
#define  LGCY_DEBLK_RVCTRL_str8_initqp(data)                                     (0x000003E0&((data)<<5))
#define  LGCY_DEBLK_RVCTRL_str7_initqp(data)                                     (0x0000001F&(data))
#define  LGCY_DEBLK_RVCTRL_get_write_enable3(data)                               ((0x08000000&(data))>>27)
#define  LGCY_DEBLK_RVCTRL_get_refqp(data)                                       ((0x07C00000&(data))>>22)
#define  LGCY_DEBLK_RVCTRL_get_beta2sel(data)                                    ((0x00200000&(data))>>21)
#define  LGCY_DEBLK_RVCTRL_get_write_enable2(data)                               ((0x00100000&(data))>>20)
#define  LGCY_DEBLK_RVCTRL_get_is_key_frame(data)                                ((0x00080000&(data))>>19)
#define  LGCY_DEBLK_RVCTRL_get_chroma_only(data)                                 ((0x00040000&(data))>>18)
#define  LGCY_DEBLK_RVCTRL_get_write_enable1(data)                               ((0x00020000&(data))>>17)
#define  LGCY_DEBLK_RVCTRL_get_sel_s_chroma_deblock(data)                        ((0x00010000&(data))>>16)
#define  LGCY_DEBLK_RVCTRL_get_write_enable0(data)                               ((0x00008000&(data))>>15)
#define  LGCY_DEBLK_RVCTRL_get_str9_initqp(data)                                 ((0x00007C00&(data))>>10)
#define  LGCY_DEBLK_RVCTRL_get_str8_initqp(data)                                 ((0x000003E0&(data))>>5)
#define  LGCY_DEBLK_RVCTRL_get_str7_initqp(data)                                 (0x0000001F&(data))

#define  LGCY_DEBLK_RV8CTRL                                                      0x1800EA64
#define  LGCY_DEBLK_RV8CTRL_reg_addr                                             "0xB800EA64"
#define  LGCY_DEBLK_RV8CTRL_reg                                                  0xB800EA64
#define  LGCY_DEBLK_RV8CTRL_inst_addr                                            "0x0019"
#define  set_LGCY_DEBLK_RV8CTRL_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_RV8CTRL_reg)=data)
#define  get_LGCY_DEBLK_RV8CTRL_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_RV8CTRL_reg))
#define  LGCY_DEBLK_RV8CTRL_str6_initqp_shift                                    (25)
#define  LGCY_DEBLK_RV8CTRL_str5_initqp_shift                                    (20)
#define  LGCY_DEBLK_RV8CTRL_str4_initqp_shift                                    (15)
#define  LGCY_DEBLK_RV8CTRL_str3_initqp_shift                                    (10)
#define  LGCY_DEBLK_RV8CTRL_str2_initqp_shift                                    (5)
#define  LGCY_DEBLK_RV8CTRL_str1_initqp_shift                                    (0)
#define  LGCY_DEBLK_RV8CTRL_str6_initqp_mask                                     (0x3E000000)
#define  LGCY_DEBLK_RV8CTRL_str5_initqp_mask                                     (0x01F00000)
#define  LGCY_DEBLK_RV8CTRL_str4_initqp_mask                                     (0x000F8000)
#define  LGCY_DEBLK_RV8CTRL_str3_initqp_mask                                     (0x00007C00)
#define  LGCY_DEBLK_RV8CTRL_str2_initqp_mask                                     (0x000003E0)
#define  LGCY_DEBLK_RV8CTRL_str1_initqp_mask                                     (0x0000001F)
#define  LGCY_DEBLK_RV8CTRL_str6_initqp(data)                                    (0x3E000000&((data)<<25))
#define  LGCY_DEBLK_RV8CTRL_str5_initqp(data)                                    (0x01F00000&((data)<<20))
#define  LGCY_DEBLK_RV8CTRL_str4_initqp(data)                                    (0x000F8000&((data)<<15))
#define  LGCY_DEBLK_RV8CTRL_str3_initqp(data)                                    (0x00007C00&((data)<<10))
#define  LGCY_DEBLK_RV8CTRL_str2_initqp(data)                                    (0x000003E0&((data)<<5))
#define  LGCY_DEBLK_RV8CTRL_str1_initqp(data)                                    (0x0000001F&(data))
#define  LGCY_DEBLK_RV8CTRL_get_str6_initqp(data)                                ((0x3E000000&(data))>>25)
#define  LGCY_DEBLK_RV8CTRL_get_str5_initqp(data)                                ((0x01F00000&(data))>>20)
#define  LGCY_DEBLK_RV8CTRL_get_str4_initqp(data)                                ((0x000F8000&(data))>>15)
#define  LGCY_DEBLK_RV8CTRL_get_str3_initqp(data)                                ((0x00007C00&(data))>>10)
#define  LGCY_DEBLK_RV8CTRL_get_str2_initqp(data)                                ((0x000003E0&(data))>>5)
#define  LGCY_DEBLK_RV8CTRL_get_str1_initqp(data)                                (0x0000001F&(data))

#define  LGCY_DEBLK_RVDBPAR0_0                                                   0x1800EA68
#define  LGCY_DEBLK_RVDBPAR0_0_reg_addr                                          "0xB800EA68"
#define  LGCY_DEBLK_RVDBPAR0_0_reg                                               0xB800EA68
#define  LGCY_DEBLK_RVDBPAR0_0_inst_addr                                         "0x001A"
#define  set_LGCY_DEBLK_RVDBPAR0_0_reg(data)                                     (*((volatile unsigned int*)LGCY_DEBLK_RVDBPAR0_0_reg)=data)
#define  get_LGCY_DEBLK_RVDBPAR0_0_reg                                           (*((volatile unsigned int*)LGCY_DEBLK_RVDBPAR0_0_reg))
#define  LGCY_DEBLK_RVDBPAR0_0_mvd_shift                                         (5)
#define  LGCY_DEBLK_RVDBPAR0_0_qp_shift                                          (0)
#define  LGCY_DEBLK_RVDBPAR0_0_mvd_mask                                          (0x001FFFE0)
#define  LGCY_DEBLK_RVDBPAR0_0_qp_mask                                           (0x0000001F)
#define  LGCY_DEBLK_RVDBPAR0_0_mvd(data)                                         (0x001FFFE0&((data)<<5))
#define  LGCY_DEBLK_RVDBPAR0_0_qp(data)                                          (0x0000001F&(data))
#define  LGCY_DEBLK_RVDBPAR0_0_get_mvd(data)                                     ((0x001FFFE0&(data))>>5)
#define  LGCY_DEBLK_RVDBPAR0_0_get_qp(data)                                      (0x0000001F&(data))

#define  LGCY_DEBLK_RVDBPAR0_1                                                   0x1800EA6C
#define  LGCY_DEBLK_RVDBPAR0_1_reg_addr                                          "0xB800EA6C"
#define  LGCY_DEBLK_RVDBPAR0_1_reg                                               0xB800EA6C
#define  LGCY_DEBLK_RVDBPAR0_1_inst_addr                                         "0x001B"
#define  set_LGCY_DEBLK_RVDBPAR0_1_reg(data)                                     (*((volatile unsigned int*)LGCY_DEBLK_RVDBPAR0_1_reg)=data)
#define  get_LGCY_DEBLK_RVDBPAR0_1_reg                                           (*((volatile unsigned int*)LGCY_DEBLK_RVDBPAR0_1_reg))
#define  LGCY_DEBLK_RVDBPAR0_1_mvd_shift                                         (5)
#define  LGCY_DEBLK_RVDBPAR0_1_qp_shift                                          (0)
#define  LGCY_DEBLK_RVDBPAR0_1_mvd_mask                                          (0x001FFFE0)
#define  LGCY_DEBLK_RVDBPAR0_1_qp_mask                                           (0x0000001F)
#define  LGCY_DEBLK_RVDBPAR0_1_mvd(data)                                         (0x001FFFE0&((data)<<5))
#define  LGCY_DEBLK_RVDBPAR0_1_qp(data)                                          (0x0000001F&(data))
#define  LGCY_DEBLK_RVDBPAR0_1_get_mvd(data)                                     ((0x001FFFE0&(data))>>5)
#define  LGCY_DEBLK_RVDBPAR0_1_get_qp(data)                                      (0x0000001F&(data))

#define  LGCY_DEBLK_RVDBPAR1                                                     0x1800EA70
#define  LGCY_DEBLK_RVDBPAR1_reg_addr                                            "0xB800EA70"
#define  LGCY_DEBLK_RVDBPAR1_reg                                                 0xB800EA70
#define  LGCY_DEBLK_RVDBPAR1_inst_addr                                           "0x001C"
#define  set_LGCY_DEBLK_RVDBPAR1_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_RVDBPAR1_reg)=data)
#define  get_LGCY_DEBLK_RVDBPAR1_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_RVDBPAR1_reg))
#define  LGCY_DEBLK_RVDBPAR1_up_mvd_mod_shift                                    (13)
#define  LGCY_DEBLK_RVDBPAR1_left_mvd_mod_shift                                  (9)
#define  LGCY_DEBLK_RVDBPAR1_ul_str_eq2_shift                                    (8)
#define  LGCY_DEBLK_RVDBPAR1_up_str_eq2_shift                                    (7)
#define  LGCY_DEBLK_RVDBPAR1_left_str_eq2_shift                                  (6)
#define  LGCY_DEBLK_RVDBPAR1_cur_str_eq2_shift                                   (5)
#define  LGCY_DEBLK_RVDBPAR1_up_ul_refdiff_shift                                 (4)
#define  LGCY_DEBLK_RVDBPAR1_left_ul_refdiff_shift                               (3)
#define  LGCY_DEBLK_RVDBPAR1_cur_l_refdiff_shift                                 (2)
#define  LGCY_DEBLK_RVDBPAR1_cur_up_refdiff_shift                                (1)
#define  LGCY_DEBLK_RVDBPAR1_up_cur_refdiff_shift                                (0)
#define  LGCY_DEBLK_RVDBPAR1_up_mvd_mod_mask                                     (0x0001E000)
#define  LGCY_DEBLK_RVDBPAR1_left_mvd_mod_mask                                   (0x00001E00)
#define  LGCY_DEBLK_RVDBPAR1_ul_str_eq2_mask                                     (0x00000100)
#define  LGCY_DEBLK_RVDBPAR1_up_str_eq2_mask                                     (0x00000080)
#define  LGCY_DEBLK_RVDBPAR1_left_str_eq2_mask                                   (0x00000040)
#define  LGCY_DEBLK_RVDBPAR1_cur_str_eq2_mask                                    (0x00000020)
#define  LGCY_DEBLK_RVDBPAR1_up_ul_refdiff_mask                                  (0x00000010)
#define  LGCY_DEBLK_RVDBPAR1_left_ul_refdiff_mask                                (0x00000008)
#define  LGCY_DEBLK_RVDBPAR1_cur_l_refdiff_mask                                  (0x00000004)
#define  LGCY_DEBLK_RVDBPAR1_cur_up_refdiff_mask                                 (0x00000002)
#define  LGCY_DEBLK_RVDBPAR1_up_cur_refdiff_mask                                 (0x00000001)
#define  LGCY_DEBLK_RVDBPAR1_up_mvd_mod(data)                                    (0x0001E000&((data)<<13))
#define  LGCY_DEBLK_RVDBPAR1_left_mvd_mod(data)                                  (0x00001E00&((data)<<9))
#define  LGCY_DEBLK_RVDBPAR1_ul_str_eq2(data)                                    (0x00000100&((data)<<8))
#define  LGCY_DEBLK_RVDBPAR1_up_str_eq2(data)                                    (0x00000080&((data)<<7))
#define  LGCY_DEBLK_RVDBPAR1_left_str_eq2(data)                                  (0x00000040&((data)<<6))
#define  LGCY_DEBLK_RVDBPAR1_cur_str_eq2(data)                                   (0x00000020&((data)<<5))
#define  LGCY_DEBLK_RVDBPAR1_up_ul_refdiff(data)                                 (0x00000010&((data)<<4))
#define  LGCY_DEBLK_RVDBPAR1_left_ul_refdiff(data)                               (0x00000008&((data)<<3))
#define  LGCY_DEBLK_RVDBPAR1_cur_l_refdiff(data)                                 (0x00000004&((data)<<2))
#define  LGCY_DEBLK_RVDBPAR1_cur_up_refdiff(data)                                (0x00000002&((data)<<1))
#define  LGCY_DEBLK_RVDBPAR1_up_cur_refdiff(data)                                (0x00000001&(data))
#define  LGCY_DEBLK_RVDBPAR1_get_up_mvd_mod(data)                                ((0x0001E000&(data))>>13)
#define  LGCY_DEBLK_RVDBPAR1_get_left_mvd_mod(data)                              ((0x00001E00&(data))>>9)
#define  LGCY_DEBLK_RVDBPAR1_get_ul_str_eq2(data)                                ((0x00000100&(data))>>8)
#define  LGCY_DEBLK_RVDBPAR1_get_up_str_eq2(data)                                ((0x00000080&(data))>>7)
#define  LGCY_DEBLK_RVDBPAR1_get_left_str_eq2(data)                              ((0x00000040&(data))>>6)
#define  LGCY_DEBLK_RVDBPAR1_get_cur_str_eq2(data)                               ((0x00000020&(data))>>5)
#define  LGCY_DEBLK_RVDBPAR1_get_up_ul_refdiff(data)                             ((0x00000010&(data))>>4)
#define  LGCY_DEBLK_RVDBPAR1_get_left_ul_refdiff(data)                           ((0x00000008&(data))>>3)
#define  LGCY_DEBLK_RVDBPAR1_get_cur_l_refdiff(data)                             ((0x00000004&(data))>>2)
#define  LGCY_DEBLK_RVDBPAR1_get_cur_up_refdiff(data)                            ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_RVDBPAR1_get_up_cur_refdiff(data)                            (0x00000001&(data))

#define  LGCY_DEBLK_RV9CLIP                                                      0x1800EA74
#define  LGCY_DEBLK_RV9CLIP_reg_addr                                             "0xB800EA74"
#define  LGCY_DEBLK_RV9CLIP_reg                                                  0xB800EA74
#define  LGCY_DEBLK_RV9CLIP_inst_addr                                            "0x001D"
#define  set_LGCY_DEBLK_RV9CLIP_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_RV9CLIP_reg)=data)
#define  get_LGCY_DEBLK_RV9CLIP_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_RV9CLIP_reg))
#define  LGCY_DEBLK_RV9CLIP_subblk2clip_ch_shift                                 (1)
#define  LGCY_DEBLK_RV9CLIP_subblk12clip_lu_shift                                (0)
#define  LGCY_DEBLK_RV9CLIP_subblk2clip_ch_mask                                  (0x00000002)
#define  LGCY_DEBLK_RV9CLIP_subblk12clip_lu_mask                                 (0x00000001)
#define  LGCY_DEBLK_RV9CLIP_subblk2clip_ch(data)                                 (0x00000002&((data)<<1))
#define  LGCY_DEBLK_RV9CLIP_subblk12clip_lu(data)                                (0x00000001&(data))
#define  LGCY_DEBLK_RV9CLIP_get_subblk2clip_ch(data)                             ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_RV9CLIP_get_subblk12clip_lu(data)                            (0x00000001&(data))

#define  LGCY_DEBLK_WMV8DBPAR_0                                                  0x1800EA78
#define  LGCY_DEBLK_WMV8DBPAR_0_reg_addr                                         "0xB800EA78"
#define  LGCY_DEBLK_WMV8DBPAR_0_reg                                              0xB800EA78
#define  LGCY_DEBLK_WMV8DBPAR_0_inst_addr                                        "0x001E"
#define  set_LGCY_DEBLK_WMV8DBPAR_0_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_WMV8DBPAR_0_reg)=data)
#define  get_LGCY_DEBLK_WMV8DBPAR_0_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_WMV8DBPAR_0_reg))
#define  LGCY_DEBLK_WMV8DBPAR_0_is_skip_shift                                    (10)
#define  LGCY_DEBLK_WMV8DBPAR_0_qpch_shift                                       (5)
#define  LGCY_DEBLK_WMV8DBPAR_0_qpy_shift                                        (0)
#define  LGCY_DEBLK_WMV8DBPAR_0_is_skip_mask                                     (0x00000400)
#define  LGCY_DEBLK_WMV8DBPAR_0_qpch_mask                                        (0x000003E0)
#define  LGCY_DEBLK_WMV8DBPAR_0_qpy_mask                                         (0x0000001F)
#define  LGCY_DEBLK_WMV8DBPAR_0_is_skip(data)                                    (0x00000400&((data)<<10))
#define  LGCY_DEBLK_WMV8DBPAR_0_qpch(data)                                       (0x000003E0&((data)<<5))
#define  LGCY_DEBLK_WMV8DBPAR_0_qpy(data)                                        (0x0000001F&(data))
#define  LGCY_DEBLK_WMV8DBPAR_0_get_is_skip(data)                                ((0x00000400&(data))>>10)
#define  LGCY_DEBLK_WMV8DBPAR_0_get_qpch(data)                                   ((0x000003E0&(data))>>5)
#define  LGCY_DEBLK_WMV8DBPAR_0_get_qpy(data)                                    (0x0000001F&(data))

#define  LGCY_DEBLK_WMV8DBPAR_1                                                  0x1800EA7C
#define  LGCY_DEBLK_WMV8DBPAR_1_reg_addr                                         "0xB800EA7C"
#define  LGCY_DEBLK_WMV8DBPAR_1_reg                                              0xB800EA7C
#define  LGCY_DEBLK_WMV8DBPAR_1_inst_addr                                        "0x001F"
#define  set_LGCY_DEBLK_WMV8DBPAR_1_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_WMV8DBPAR_1_reg)=data)
#define  get_LGCY_DEBLK_WMV8DBPAR_1_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_WMV8DBPAR_1_reg))
#define  LGCY_DEBLK_WMV8DBPAR_1_is_skip_shift                                    (10)
#define  LGCY_DEBLK_WMV8DBPAR_1_qpch_shift                                       (5)
#define  LGCY_DEBLK_WMV8DBPAR_1_qpy_shift                                        (0)
#define  LGCY_DEBLK_WMV8DBPAR_1_is_skip_mask                                     (0x00000400)
#define  LGCY_DEBLK_WMV8DBPAR_1_qpch_mask                                        (0x000003E0)
#define  LGCY_DEBLK_WMV8DBPAR_1_qpy_mask                                         (0x0000001F)
#define  LGCY_DEBLK_WMV8DBPAR_1_is_skip(data)                                    (0x00000400&((data)<<10))
#define  LGCY_DEBLK_WMV8DBPAR_1_qpch(data)                                       (0x000003E0&((data)<<5))
#define  LGCY_DEBLK_WMV8DBPAR_1_qpy(data)                                        (0x0000001F&(data))
#define  LGCY_DEBLK_WMV8DBPAR_1_get_is_skip(data)                                ((0x00000400&(data))>>10)
#define  LGCY_DEBLK_WMV8DBPAR_1_get_qpch(data)                                   ((0x000003E0&(data))>>5)
#define  LGCY_DEBLK_WMV8DBPAR_1_get_qpy(data)                                    (0x0000001F&(data))

#define  LGCY_DEBLK_VMADRBA                                                      0x1800EA80
#define  LGCY_DEBLK_VMADRBA_reg_addr                                             "0xB800EA80"
#define  LGCY_DEBLK_VMADRBA_reg                                                  0xB800EA80
#define  LGCY_DEBLK_VMADRBA_inst_addr                                            "0x0020"
#define  set_LGCY_DEBLK_VMADRBA_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_VMADRBA_reg)=data)
#define  get_LGCY_DEBLK_VMADRBA_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_VMADRBA_reg))
#define  LGCY_DEBLK_VMADRBA_basea0_shift                                         (7)
#define  LGCY_DEBLK_VMADRBA_basea1_shift                                         (0)
#define  LGCY_DEBLK_VMADRBA_basea0_mask                                          (0x00003F80)
#define  LGCY_DEBLK_VMADRBA_basea1_mask                                          (0x0000007F)
#define  LGCY_DEBLK_VMADRBA_basea0(data)                                         (0x00003F80&((data)<<7))
#define  LGCY_DEBLK_VMADRBA_basea1(data)                                         (0x0000007F&(data))
#define  LGCY_DEBLK_VMADRBA_get_basea0(data)                                     ((0x00003F80&(data))>>7)
#define  LGCY_DEBLK_VMADRBA_get_basea1(data)                                     (0x0000007F&(data))

#define  LGCY_DEBLK_VMADROA                                                      0x1800EA84
#define  LGCY_DEBLK_VMADROA_reg_addr                                             "0xB800EA84"
#define  LGCY_DEBLK_VMADROA_reg                                                  0xB800EA84
#define  LGCY_DEBLK_VMADROA_inst_addr                                            "0x0021"
#define  set_LGCY_DEBLK_VMADROA_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_VMADROA_reg)=data)
#define  get_LGCY_DEBLK_VMADROA_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_VMADROA_reg))
#define  LGCY_DEBLK_VMADROA_offseta0_shift                                       (14)
#define  LGCY_DEBLK_VMADROA_offseta1_shift                                       (7)
#define  LGCY_DEBLK_VMADROA_offseta2_shift                                       (0)
#define  LGCY_DEBLK_VMADROA_offseta0_mask                                        (0x001FC000)
#define  LGCY_DEBLK_VMADROA_offseta1_mask                                        (0x00003F80)
#define  LGCY_DEBLK_VMADROA_offseta2_mask                                        (0x0000007F)
#define  LGCY_DEBLK_VMADROA_offseta0(data)                                       (0x001FC000&((data)<<14))
#define  LGCY_DEBLK_VMADROA_offseta1(data)                                       (0x00003F80&((data)<<7))
#define  LGCY_DEBLK_VMADROA_offseta2(data)                                       (0x0000007F&(data))
#define  LGCY_DEBLK_VMADROA_get_offseta0(data)                                   ((0x001FC000&(data))>>14)
#define  LGCY_DEBLK_VMADROA_get_offseta1(data)                                   ((0x00003F80&(data))>>7)
#define  LGCY_DEBLK_VMADROA_get_offseta2(data)                                   (0x0000007F&(data))

#define  LGCY_DEBLK_DEBSBCTL                                                     0x1800EA88
#define  LGCY_DEBLK_DEBSBCTL_reg_addr                                            "0xB800EA88"
#define  LGCY_DEBLK_DEBSBCTL_reg                                                 0xB800EA88
#define  LGCY_DEBLK_DEBSBCTL_inst_addr                                           "0x0022"
#define  set_LGCY_DEBLK_DEBSBCTL_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DEBSBCTL_reg)=data)
#define  get_LGCY_DEBLK_DEBSBCTL_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DEBSBCTL_reg))
#define  LGCY_DEBLK_DEBSBCTL_mb_case_dbg_en_shift                                (8)
#define  LGCY_DEBLK_DEBSBCTL_mb_case_dbg_shift                                   (4)
#define  LGCY_DEBLK_DEBSBCTL_sb_load_disable_shift                               (0)
#define  LGCY_DEBLK_DEBSBCTL_mb_case_dbg_en_mask                                 (0x00000100)
#define  LGCY_DEBLK_DEBSBCTL_mb_case_dbg_mask                                    (0x000000F0)
#define  LGCY_DEBLK_DEBSBCTL_sb_load_disable_mask                                (0x00000007)
#define  LGCY_DEBLK_DEBSBCTL_mb_case_dbg_en(data)                                (0x00000100&((data)<<8))
#define  LGCY_DEBLK_DEBSBCTL_mb_case_dbg(data)                                   (0x000000F0&((data)<<4))
#define  LGCY_DEBLK_DEBSBCTL_sb_load_disable(data)                               (0x00000007&(data))
#define  LGCY_DEBLK_DEBSBCTL_get_mb_case_dbg_en(data)                            ((0x00000100&(data))>>8)
#define  LGCY_DEBLK_DEBSBCTL_get_mb_case_dbg(data)                               ((0x000000F0&(data))>>4)
#define  LGCY_DEBLK_DEBSBCTL_get_sb_load_disable(data)                           (0x00000007&(data))

#define  LGCY_DEBLK_DMACTRL                                                      0x1800EA8C
#define  LGCY_DEBLK_DMACTRL_reg_addr                                             "0xB800EA8C"
#define  LGCY_DEBLK_DMACTRL_reg                                                  0xB800EA8C
#define  LGCY_DEBLK_DMACTRL_inst_addr                                            "0x0023"
#define  set_LGCY_DEBLK_DMACTRL_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_DMACTRL_reg)=data)
#define  get_LGCY_DEBLK_DMACTRL_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_DMACTRL_reg))
#define  LGCY_DEBLK_DMACTRL_dual_issue_disable_shift                             (6)
#define  LGCY_DEBLK_DMACTRL_bot_sb_st_disable_shift                              (5)
#define  LGCY_DEBLK_DMACTRL_post_write_disable_shift                             (4)
#define  LGCY_DEBLK_DMACTRL_dma_idle_shift                                       (3)
#define  LGCY_DEBLK_DMACTRL_go_shift                                             (2)
#define  LGCY_DEBLK_DMACTRL_klm_addr_update_shift                                (1)
#define  LGCY_DEBLK_DMACTRL_km_addr_update_shift                                 (0)
#define  LGCY_DEBLK_DMACTRL_dual_issue_disable_mask                              (0x00000040)
#define  LGCY_DEBLK_DMACTRL_bot_sb_st_disable_mask                               (0x00000020)
#define  LGCY_DEBLK_DMACTRL_post_write_disable_mask                              (0x00000010)
#define  LGCY_DEBLK_DMACTRL_dma_idle_mask                                        (0x00000008)
#define  LGCY_DEBLK_DMACTRL_go_mask                                              (0x00000004)
#define  LGCY_DEBLK_DMACTRL_klm_addr_update_mask                                 (0x00000002)
#define  LGCY_DEBLK_DMACTRL_km_addr_update_mask                                  (0x00000001)
#define  LGCY_DEBLK_DMACTRL_dual_issue_disable(data)                             (0x00000040&((data)<<6))
#define  LGCY_DEBLK_DMACTRL_bot_sb_st_disable(data)                              (0x00000020&((data)<<5))
#define  LGCY_DEBLK_DMACTRL_post_write_disable(data)                             (0x00000010&((data)<<4))
#define  LGCY_DEBLK_DMACTRL_dma_idle(data)                                       (0x00000008&((data)<<3))
#define  LGCY_DEBLK_DMACTRL_go(data)                                             (0x00000004&((data)<<2))
#define  LGCY_DEBLK_DMACTRL_klm_addr_update(data)                                (0x00000002&((data)<<1))
#define  LGCY_DEBLK_DMACTRL_km_addr_update(data)                                 (0x00000001&(data))
#define  LGCY_DEBLK_DMACTRL_get_dual_issue_disable(data)                         ((0x00000040&(data))>>6)
#define  LGCY_DEBLK_DMACTRL_get_bot_sb_st_disable(data)                          ((0x00000020&(data))>>5)
#define  LGCY_DEBLK_DMACTRL_get_post_write_disable(data)                         ((0x00000010&(data))>>4)
#define  LGCY_DEBLK_DMACTRL_get_dma_idle(data)                                   ((0x00000008&(data))>>3)
#define  LGCY_DEBLK_DMACTRL_get_go(data)                                         ((0x00000004&(data))>>2)
#define  LGCY_DEBLK_DMACTRL_get_klm_addr_update(data)                            ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_DMACTRL_get_km_addr_update(data)                             (0x00000001&(data))

#define  LGCY_DEBLK_DMALU                                                        0x1800EA90
#define  LGCY_DEBLK_DMALU_reg_addr                                               "0xB800EA90"
#define  LGCY_DEBLK_DMALU_reg                                                    0xB800EA90
#define  LGCY_DEBLK_DMALU_inst_addr                                              "0x0024"
#define  set_LGCY_DEBLK_DMALU_reg(data)                                          (*((volatile unsigned int*)LGCY_DEBLK_DMALU_reg)=data)
#define  get_LGCY_DEBLK_DMALU_reg                                                (*((volatile unsigned int*)LGCY_DEBLK_DMALU_reg))
#define  LGCY_DEBLK_DMALU_lu_addr_idx_shift                                      (25)
#define  LGCY_DEBLK_DMALU_klm_lu_x_sel_shift                                     (24)
#define  LGCY_DEBLK_DMALU_klm_lu_top_row_inc_shift                               (18)
#define  LGCY_DEBLK_DMALU_klm_lu_inc_shift                                       (12)
#define  LGCY_DEBLK_DMALU_km_lu_mb_offset_shift                                  (6)
#define  LGCY_DEBLK_DMALU_km_lu_row_offset_shift                                 (0)
#define  LGCY_DEBLK_DMALU_lu_addr_idx_mask                                       (0xFE000000)
#define  LGCY_DEBLK_DMALU_klm_lu_x_sel_mask                                      (0x01000000)
#define  LGCY_DEBLK_DMALU_klm_lu_top_row_inc_mask                                (0x00FC0000)
#define  LGCY_DEBLK_DMALU_klm_lu_inc_mask                                        (0x0003F000)
#define  LGCY_DEBLK_DMALU_km_lu_mb_offset_mask                                   (0x00000FC0)
#define  LGCY_DEBLK_DMALU_km_lu_row_offset_mask                                  (0x0000003F)
#define  LGCY_DEBLK_DMALU_lu_addr_idx(data)                                      (0xFE000000&((data)<<25))
#define  LGCY_DEBLK_DMALU_klm_lu_x_sel(data)                                     (0x01000000&((data)<<24))
#define  LGCY_DEBLK_DMALU_klm_lu_top_row_inc(data)                               (0x00FC0000&((data)<<18))
#define  LGCY_DEBLK_DMALU_klm_lu_inc(data)                                       (0x0003F000&((data)<<12))
#define  LGCY_DEBLK_DMALU_km_lu_mb_offset(data)                                  (0x00000FC0&((data)<<6))
#define  LGCY_DEBLK_DMALU_km_lu_row_offset(data)                                 (0x0000003F&(data))
#define  LGCY_DEBLK_DMALU_get_lu_addr_idx(data)                                  ((0xFE000000&(data))>>25)
#define  LGCY_DEBLK_DMALU_get_klm_lu_x_sel(data)                                 ((0x01000000&(data))>>24)
#define  LGCY_DEBLK_DMALU_get_klm_lu_top_row_inc(data)                           ((0x00FC0000&(data))>>18)
#define  LGCY_DEBLK_DMALU_get_klm_lu_inc(data)                                   ((0x0003F000&(data))>>12)
#define  LGCY_DEBLK_DMALU_get_km_lu_mb_offset(data)                              ((0x00000FC0&(data))>>6)
#define  LGCY_DEBLK_DMALU_get_km_lu_row_offset(data)                             (0x0000003F&(data))

#define  LGCY_DEBLK_DMACH                                                        0x1800EA94
#define  LGCY_DEBLK_DMACH_reg_addr                                               "0xB800EA94"
#define  LGCY_DEBLK_DMACH_reg                                                    0xB800EA94
#define  LGCY_DEBLK_DMACH_inst_addr                                              "0x0025"
#define  set_LGCY_DEBLK_DMACH_reg(data)                                          (*((volatile unsigned int*)LGCY_DEBLK_DMACH_reg)=data)
#define  get_LGCY_DEBLK_DMACH_reg                                                (*((volatile unsigned int*)LGCY_DEBLK_DMACH_reg))
#define  LGCY_DEBLK_DMACH_ch_addr_idx_shift                                      (25)
#define  LGCY_DEBLK_DMACH_klm_ch_x_sel_shift                                     (24)
#define  LGCY_DEBLK_DMACH_klm_ch_top_row_inc_shift                               (18)
#define  LGCY_DEBLK_DMACH_klm_ch_inc_shift                                       (12)
#define  LGCY_DEBLK_DMACH_km_ch_mb_offset_shift                                  (6)
#define  LGCY_DEBLK_DMACH_km_ch_row_offset_shift                                 (0)
#define  LGCY_DEBLK_DMACH_ch_addr_idx_mask                                       (0xFE000000)
#define  LGCY_DEBLK_DMACH_klm_ch_x_sel_mask                                      (0x01000000)
#define  LGCY_DEBLK_DMACH_klm_ch_top_row_inc_mask                                (0x00FC0000)
#define  LGCY_DEBLK_DMACH_klm_ch_inc_mask                                        (0x0003F000)
#define  LGCY_DEBLK_DMACH_km_ch_mb_offset_mask                                   (0x00000FC0)
#define  LGCY_DEBLK_DMACH_km_ch_row_offset_mask                                  (0x0000003F)
#define  LGCY_DEBLK_DMACH_ch_addr_idx(data)                                      (0xFE000000&((data)<<25))
#define  LGCY_DEBLK_DMACH_klm_ch_x_sel(data)                                     (0x01000000&((data)<<24))
#define  LGCY_DEBLK_DMACH_klm_ch_top_row_inc(data)                               (0x00FC0000&((data)<<18))
#define  LGCY_DEBLK_DMACH_klm_ch_inc(data)                                       (0x0003F000&((data)<<12))
#define  LGCY_DEBLK_DMACH_km_ch_mb_offset(data)                                  (0x00000FC0&((data)<<6))
#define  LGCY_DEBLK_DMACH_km_ch_row_offset(data)                                 (0x0000003F&(data))
#define  LGCY_DEBLK_DMACH_get_ch_addr_idx(data)                                  ((0xFE000000&(data))>>25)
#define  LGCY_DEBLK_DMACH_get_klm_ch_x_sel(data)                                 ((0x01000000&(data))>>24)
#define  LGCY_DEBLK_DMACH_get_klm_ch_top_row_inc(data)                           ((0x00FC0000&(data))>>18)
#define  LGCY_DEBLK_DMACH_get_klm_ch_inc(data)                                   ((0x0003F000&(data))>>12)
#define  LGCY_DEBLK_DMACH_get_km_ch_mb_offset(data)                              ((0x00000FC0&(data))>>6)
#define  LGCY_DEBLK_DMACH_get_km_ch_row_offset(data)                             (0x0000003F&(data))

#define  LGCY_DEBLK_DMAWH                                                        0x1800EA98
#define  LGCY_DEBLK_DMAWH_reg_addr                                               "0xB800EA98"
#define  LGCY_DEBLK_DMAWH_reg                                                    0xB800EA98
#define  LGCY_DEBLK_DMAWH_inst_addr                                              "0x0026"
#define  set_LGCY_DEBLK_DMAWH_reg(data)                                          (*((volatile unsigned int*)LGCY_DEBLK_DMAWH_reg)=data)
#define  get_LGCY_DEBLK_DMAWH_reg                                                (*((volatile unsigned int*)LGCY_DEBLK_DMAWH_reg))
#define  LGCY_DEBLK_DMAWH_klm_ch_h_shift                                         (19)
#define  LGCY_DEBLK_DMAWH_klm_ch_w_shift                                         (18)
#define  LGCY_DEBLK_DMAWH_klm_lu_h_shift                                         (12)
#define  LGCY_DEBLK_DMAWH_klm_lu_w_shift                                         (11)
#define  LGCY_DEBLK_DMAWH_km_ch_h_shift                                          (7)
#define  LGCY_DEBLK_DMAWH_km_ch_w_shift                                          (6)
#define  LGCY_DEBLK_DMAWH_km_lu_h_shift                                          (1)
#define  LGCY_DEBLK_DMAWH_km_lu_w_shift                                          (0)
#define  LGCY_DEBLK_DMAWH_klm_ch_h_mask                                          (0x00F80000)
#define  LGCY_DEBLK_DMAWH_klm_ch_w_mask                                          (0x00040000)
#define  LGCY_DEBLK_DMAWH_klm_lu_h_mask                                          (0x0003F000)
#define  LGCY_DEBLK_DMAWH_klm_lu_w_mask                                          (0x00000800)
#define  LGCY_DEBLK_DMAWH_km_ch_h_mask                                           (0x00000780)
#define  LGCY_DEBLK_DMAWH_km_ch_w_mask                                           (0x00000040)
#define  LGCY_DEBLK_DMAWH_km_lu_h_mask                                           (0x0000003E)
#define  LGCY_DEBLK_DMAWH_km_lu_w_mask                                           (0x00000001)
#define  LGCY_DEBLK_DMAWH_klm_ch_h(data)                                         (0x00F80000&((data)<<19))
#define  LGCY_DEBLK_DMAWH_klm_ch_w(data)                                         (0x00040000&((data)<<18))
#define  LGCY_DEBLK_DMAWH_klm_lu_h(data)                                         (0x0003F000&((data)<<12))
#define  LGCY_DEBLK_DMAWH_klm_lu_w(data)                                         (0x00000800&((data)<<11))
#define  LGCY_DEBLK_DMAWH_km_ch_h(data)                                          (0x00000780&((data)<<7))
#define  LGCY_DEBLK_DMAWH_km_ch_w(data)                                          (0x00000040&((data)<<6))
#define  LGCY_DEBLK_DMAWH_km_lu_h(data)                                          (0x0000003E&((data)<<1))
#define  LGCY_DEBLK_DMAWH_km_lu_w(data)                                          (0x00000001&(data))
#define  LGCY_DEBLK_DMAWH_get_klm_ch_h(data)                                     ((0x00F80000&(data))>>19)
#define  LGCY_DEBLK_DMAWH_get_klm_ch_w(data)                                     ((0x00040000&(data))>>18)
#define  LGCY_DEBLK_DMAWH_get_klm_lu_h(data)                                     ((0x0003F000&(data))>>12)
#define  LGCY_DEBLK_DMAWH_get_klm_lu_w(data)                                     ((0x00000800&(data))>>11)
#define  LGCY_DEBLK_DMAWH_get_km_ch_h(data)                                      ((0x00000780&(data))>>7)
#define  LGCY_DEBLK_DMAWH_get_km_ch_w(data)                                      ((0x00000040&(data))>>6)
#define  LGCY_DEBLK_DMAWH_get_km_lu_h(data)                                      ((0x0000003E&(data))>>1)
#define  LGCY_DEBLK_DMAWH_get_km_lu_w(data)                                      (0x00000001&(data))

#define  LGCY_DEBLK_DMAADR_0                                                     0x1800EA9C
#define  LGCY_DEBLK_DMAADR_0_reg_addr                                            "0xB800EA9C"
#define  LGCY_DEBLK_DMAADR_0_reg                                                 0xB800EA9C
#define  LGCY_DEBLK_DMAADR_0_inst_addr                                           "0x0027"
#define  set_LGCY_DEBLK_DMAADR_0_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_0_reg)=data)
#define  get_LGCY_DEBLK_DMAADR_0_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_0_reg))
#define  LGCY_DEBLK_DMAADR_0_x_shift                                             (14)
#define  LGCY_DEBLK_DMAADR_0_y_shift                                             (0)
#define  LGCY_DEBLK_DMAADR_0_x_mask                                              (0x07FFC000)
#define  LGCY_DEBLK_DMAADR_0_y_mask                                              (0x00003FFF)
#define  LGCY_DEBLK_DMAADR_0_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_DEBLK_DMAADR_0_y(data)                                             (0x00003FFF&(data))
#define  LGCY_DEBLK_DMAADR_0_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_DEBLK_DMAADR_0_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_DEBLK_DMAADR_1                                                     0x1800EAA0
#define  LGCY_DEBLK_DMAADR_1_reg_addr                                            "0xB800EAA0"
#define  LGCY_DEBLK_DMAADR_1_reg                                                 0xB800EAA0
#define  LGCY_DEBLK_DMAADR_1_inst_addr                                           "0x0028"
#define  set_LGCY_DEBLK_DMAADR_1_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_1_reg)=data)
#define  get_LGCY_DEBLK_DMAADR_1_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_1_reg))
#define  LGCY_DEBLK_DMAADR_1_x_shift                                             (14)
#define  LGCY_DEBLK_DMAADR_1_y_shift                                             (0)
#define  LGCY_DEBLK_DMAADR_1_x_mask                                              (0x07FFC000)
#define  LGCY_DEBLK_DMAADR_1_y_mask                                              (0x00003FFF)
#define  LGCY_DEBLK_DMAADR_1_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_DEBLK_DMAADR_1_y(data)                                             (0x00003FFF&(data))
#define  LGCY_DEBLK_DMAADR_1_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_DEBLK_DMAADR_1_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_DEBLK_DMAADR_2                                                     0x1800EAA4
#define  LGCY_DEBLK_DMAADR_2_reg_addr                                            "0xB800EAA4"
#define  LGCY_DEBLK_DMAADR_2_reg                                                 0xB800EAA4
#define  LGCY_DEBLK_DMAADR_2_inst_addr                                           "0x0029"
#define  set_LGCY_DEBLK_DMAADR_2_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_2_reg)=data)
#define  get_LGCY_DEBLK_DMAADR_2_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_2_reg))
#define  LGCY_DEBLK_DMAADR_2_x_shift                                             (14)
#define  LGCY_DEBLK_DMAADR_2_y_shift                                             (0)
#define  LGCY_DEBLK_DMAADR_2_x_mask                                              (0x07FFC000)
#define  LGCY_DEBLK_DMAADR_2_y_mask                                              (0x00003FFF)
#define  LGCY_DEBLK_DMAADR_2_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_DEBLK_DMAADR_2_y(data)                                             (0x00003FFF&(data))
#define  LGCY_DEBLK_DMAADR_2_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_DEBLK_DMAADR_2_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_DEBLK_DMAADR_3                                                     0x1800EAA8
#define  LGCY_DEBLK_DMAADR_3_reg_addr                                            "0xB800EAA8"
#define  LGCY_DEBLK_DMAADR_3_reg                                                 0xB800EAA8
#define  LGCY_DEBLK_DMAADR_3_inst_addr                                           "0x002A"
#define  set_LGCY_DEBLK_DMAADR_3_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_3_reg)=data)
#define  get_LGCY_DEBLK_DMAADR_3_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_3_reg))
#define  LGCY_DEBLK_DMAADR_3_x_shift                                             (14)
#define  LGCY_DEBLK_DMAADR_3_y_shift                                             (0)
#define  LGCY_DEBLK_DMAADR_3_x_mask                                              (0x07FFC000)
#define  LGCY_DEBLK_DMAADR_3_y_mask                                              (0x00003FFF)
#define  LGCY_DEBLK_DMAADR_3_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_DEBLK_DMAADR_3_y(data)                                             (0x00003FFF&(data))
#define  LGCY_DEBLK_DMAADR_3_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_DEBLK_DMAADR_3_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_DEBLK_DMAADR_4                                                     0x1800EAAC
#define  LGCY_DEBLK_DMAADR_4_reg_addr                                            "0xB800EAAC"
#define  LGCY_DEBLK_DMAADR_4_reg                                                 0xB800EAAC
#define  LGCY_DEBLK_DMAADR_4_inst_addr                                           "0x002B"
#define  set_LGCY_DEBLK_DMAADR_4_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_4_reg)=data)
#define  get_LGCY_DEBLK_DMAADR_4_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_4_reg))
#define  LGCY_DEBLK_DMAADR_4_x_shift                                             (14)
#define  LGCY_DEBLK_DMAADR_4_y_shift                                             (0)
#define  LGCY_DEBLK_DMAADR_4_x_mask                                              (0x07FFC000)
#define  LGCY_DEBLK_DMAADR_4_y_mask                                              (0x00003FFF)
#define  LGCY_DEBLK_DMAADR_4_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_DEBLK_DMAADR_4_y(data)                                             (0x00003FFF&(data))
#define  LGCY_DEBLK_DMAADR_4_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_DEBLK_DMAADR_4_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_DEBLK_DMAADR_5                                                     0x1800EAB0
#define  LGCY_DEBLK_DMAADR_5_reg_addr                                            "0xB800EAB0"
#define  LGCY_DEBLK_DMAADR_5_reg                                                 0xB800EAB0
#define  LGCY_DEBLK_DMAADR_5_inst_addr                                           "0x002C"
#define  set_LGCY_DEBLK_DMAADR_5_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_5_reg)=data)
#define  get_LGCY_DEBLK_DMAADR_5_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_DMAADR_5_reg))
#define  LGCY_DEBLK_DMAADR_5_x_shift                                             (14)
#define  LGCY_DEBLK_DMAADR_5_y_shift                                             (0)
#define  LGCY_DEBLK_DMAADR_5_x_mask                                              (0x07FFC000)
#define  LGCY_DEBLK_DMAADR_5_y_mask                                              (0x00003FFF)
#define  LGCY_DEBLK_DMAADR_5_x(data)                                             (0x07FFC000&((data)<<14))
#define  LGCY_DEBLK_DMAADR_5_y(data)                                             (0x00003FFF&(data))
#define  LGCY_DEBLK_DMAADR_5_get_x(data)                                         ((0x07FFC000&(data))>>14)
#define  LGCY_DEBLK_DMAADR_5_get_y(data)                                         (0x00003FFF&(data))

#define  LGCY_DEBLK_DMACTB                                                       0x1800EAB4
#define  LGCY_DEBLK_DMACTB_reg_addr                                              "0xB800EAB4"
#define  LGCY_DEBLK_DMACTB_reg                                                   0xB800EAB4
#define  LGCY_DEBLK_DMACTB_inst_addr                                             "0x002D"
#define  set_LGCY_DEBLK_DMACTB_reg(data)                                         (*((volatile unsigned int*)LGCY_DEBLK_DMACTB_reg)=data)
#define  get_LGCY_DEBLK_DMACTB_reg                                               (*((volatile unsigned int*)LGCY_DEBLK_DMACTB_reg))
#define  LGCY_DEBLK_DMACTB_ctb_row_offset_shift                                  (0)
#define  LGCY_DEBLK_DMACTB_ctb_row_offset_mask                                   (0x0000007F)
#define  LGCY_DEBLK_DMACTB_ctb_row_offset(data)                                  (0x0000007F&(data))
#define  LGCY_DEBLK_DMACTB_get_ctb_row_offset(data)                              (0x0000007F&(data))

#define  LGCY_DEBLK_SDMAADR                                                      0x1800EAB8
#define  LGCY_DEBLK_SDMAADR_reg_addr                                             "0xB800EAB8"
#define  LGCY_DEBLK_SDMAADR_reg                                                  0xB800EAB8
#define  LGCY_DEBLK_SDMAADR_inst_addr                                            "0x002E"
#define  set_LGCY_DEBLK_SDMAADR_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_SDMAADR_reg)=data)
#define  get_LGCY_DEBLK_SDMAADR_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_SDMAADR_reg))
#define  LGCY_DEBLK_SDMAADR_seq_dma_addr_shift                                   (0)
#define  LGCY_DEBLK_SDMAADR_seq_dma_addr_mask                                    (0xFFFFFFFF)
#define  LGCY_DEBLK_SDMAADR_seq_dma_addr(data)                                   (0xFFFFFFFF&(data))
#define  LGCY_DEBLK_SDMAADR_get_seq_dma_addr(data)                               (0xFFFFFFFF&(data))

#define  LGCY_DEBLK_SDMABL                                                       0x1800EABC
#define  LGCY_DEBLK_SDMABL_reg_addr                                              "0xB800EABC"
#define  LGCY_DEBLK_SDMABL_reg                                                   0xB800EABC
#define  LGCY_DEBLK_SDMABL_inst_addr                                             "0x002F"
#define  set_LGCY_DEBLK_SDMABL_reg(data)                                         (*((volatile unsigned int*)LGCY_DEBLK_SDMABL_reg)=data)
#define  get_LGCY_DEBLK_SDMABL_reg                                               (*((volatile unsigned int*)LGCY_DEBLK_SDMABL_reg))
#define  LGCY_DEBLK_SDMABL_seq_dma_bl_shift                                      (0)
#define  LGCY_DEBLK_SDMABL_seq_dma_bl_mask                                       (0x000001FF)
#define  LGCY_DEBLK_SDMABL_seq_dma_bl(data)                                      (0x000001FF&(data))
#define  LGCY_DEBLK_SDMABL_get_seq_dma_bl(data)                                  (0x000001FF&(data))

#define  LGCY_DEBLK_VPXCTRL                                                      0x1800EAC0
#define  LGCY_DEBLK_VPXCTRL_reg_addr                                             "0xB800EAC0"
#define  LGCY_DEBLK_VPXCTRL_reg                                                  0xB800EAC0
#define  LGCY_DEBLK_VPXCTRL_inst_addr                                            "0x0030"
#define  set_LGCY_DEBLK_VPXCTRL_reg(data)                                        (*((volatile unsigned int*)LGCY_DEBLK_VPXCTRL_reg)=data)
#define  get_LGCY_DEBLK_VPXCTRL_reg                                              (*((volatile unsigned int*)LGCY_DEBLK_VPXCTRL_reg))
#define  LGCY_DEBLK_VPXCTRL_write_enable3_shift                                  (14)
#define  LGCY_DEBLK_VPXCTRL_last_filter_type_shift                               (13)
#define  LGCY_DEBLK_VPXCTRL_last_sharp_level_shift                               (10)
#define  LGCY_DEBLK_VPXCTRL_last_frame_type_shift                                (9)
#define  LGCY_DEBLK_VPXCTRL_write_enable2_shift                                  (8)
#define  LGCY_DEBLK_VPXCTRL_filter_type_shift                                    (7)
#define  LGCY_DEBLK_VPXCTRL_sharp_level_shift                                    (4)
#define  LGCY_DEBLK_VPXCTRL_write_enable1_shift                                  (3)
#define  LGCY_DEBLK_VPXCTRL_lf_delta_enable_shift                                (2)
#define  LGCY_DEBLK_VPXCTRL_write_enable0_shift                                  (1)
#define  LGCY_DEBLK_VPXCTRL_segment_enable_shift                                 (0)
#define  LGCY_DEBLK_VPXCTRL_write_enable3_mask                                   (0x00004000)
#define  LGCY_DEBLK_VPXCTRL_last_filter_type_mask                                (0x00002000)
#define  LGCY_DEBLK_VPXCTRL_last_sharp_level_mask                                (0x00001C00)
#define  LGCY_DEBLK_VPXCTRL_last_frame_type_mask                                 (0x00000200)
#define  LGCY_DEBLK_VPXCTRL_write_enable2_mask                                   (0x00000100)
#define  LGCY_DEBLK_VPXCTRL_filter_type_mask                                     (0x00000080)
#define  LGCY_DEBLK_VPXCTRL_sharp_level_mask                                     (0x00000070)
#define  LGCY_DEBLK_VPXCTRL_write_enable1_mask                                   (0x00000008)
#define  LGCY_DEBLK_VPXCTRL_lf_delta_enable_mask                                 (0x00000004)
#define  LGCY_DEBLK_VPXCTRL_write_enable0_mask                                   (0x00000002)
#define  LGCY_DEBLK_VPXCTRL_segment_enable_mask                                  (0x00000001)
#define  LGCY_DEBLK_VPXCTRL_write_enable3(data)                                  (0x00004000&((data)<<14))
#define  LGCY_DEBLK_VPXCTRL_last_filter_type(data)                               (0x00002000&((data)<<13))
#define  LGCY_DEBLK_VPXCTRL_last_sharp_level(data)                               (0x00001C00&((data)<<10))
#define  LGCY_DEBLK_VPXCTRL_last_frame_type(data)                                (0x00000200&((data)<<9))
#define  LGCY_DEBLK_VPXCTRL_write_enable2(data)                                  (0x00000100&((data)<<8))
#define  LGCY_DEBLK_VPXCTRL_filter_type(data)                                    (0x00000080&((data)<<7))
#define  LGCY_DEBLK_VPXCTRL_sharp_level(data)                                    (0x00000070&((data)<<4))
#define  LGCY_DEBLK_VPXCTRL_write_enable1(data)                                  (0x00000008&((data)<<3))
#define  LGCY_DEBLK_VPXCTRL_lf_delta_enable(data)                                (0x00000004&((data)<<2))
#define  LGCY_DEBLK_VPXCTRL_write_enable0(data)                                  (0x00000002&((data)<<1))
#define  LGCY_DEBLK_VPXCTRL_segment_enable(data)                                 (0x00000001&(data))
#define  LGCY_DEBLK_VPXCTRL_get_write_enable3(data)                              ((0x00004000&(data))>>14)
#define  LGCY_DEBLK_VPXCTRL_get_last_filter_type(data)                           ((0x00002000&(data))>>13)
#define  LGCY_DEBLK_VPXCTRL_get_last_sharp_level(data)                           ((0x00001C00&(data))>>10)
#define  LGCY_DEBLK_VPXCTRL_get_last_frame_type(data)                            ((0x00000200&(data))>>9)
#define  LGCY_DEBLK_VPXCTRL_get_write_enable2(data)                              ((0x00000100&(data))>>8)
#define  LGCY_DEBLK_VPXCTRL_get_filter_type(data)                                ((0x00000080&(data))>>7)
#define  LGCY_DEBLK_VPXCTRL_get_sharp_level(data)                                ((0x00000070&(data))>>4)
#define  LGCY_DEBLK_VPXCTRL_get_write_enable1(data)                              ((0x00000008&(data))>>3)
#define  LGCY_DEBLK_VPXCTRL_get_lf_delta_enable(data)                            ((0x00000004&(data))>>2)
#define  LGCY_DEBLK_VPXCTRL_get_write_enable0(data)                              ((0x00000002&(data))>>1)
#define  LGCY_DEBLK_VPXCTRL_get_segment_enable(data)                             (0x00000001&(data))

#define  LGCY_DEBLK_VPXFILTLVL                                                   0x1800EAC4
#define  LGCY_DEBLK_VPXFILTLVL_reg_addr                                          "0xB800EAC4"
#define  LGCY_DEBLK_VPXFILTLVL_reg                                               0xB800EAC4
#define  LGCY_DEBLK_VPXFILTLVL_inst_addr                                         "0x0031"
#define  set_LGCY_DEBLK_VPXFILTLVL_reg(data)                                     (*((volatile unsigned int*)LGCY_DEBLK_VPXFILTLVL_reg)=data)
#define  get_LGCY_DEBLK_VPXFILTLVL_reg                                           (*((volatile unsigned int*)LGCY_DEBLK_VPXFILTLVL_reg))
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_3_shift                             (24)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_2_shift                             (16)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_1_shift                             (8)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_0_shift                             (0)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_3_mask                              (0x7F000000)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_2_mask                              (0x007F0000)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_1_mask                              (0x00007F00)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_0_mask                              (0x0000007F)
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_3(data)                             (0x7F000000&((data)<<24))
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_2(data)                             (0x007F0000&((data)<<16))
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_1(data)                             (0x00007F00&((data)<<8))
#define  LGCY_DEBLK_VPXFILTLVL_base_filt_lvl_0(data)                             (0x0000007F&(data))
#define  LGCY_DEBLK_VPXFILTLVL_get_base_filt_lvl_3(data)                         ((0x7F000000&(data))>>24)
#define  LGCY_DEBLK_VPXFILTLVL_get_base_filt_lvl_2(data)                         ((0x007F0000&(data))>>16)
#define  LGCY_DEBLK_VPXFILTLVL_get_base_filt_lvl_1(data)                         ((0x00007F00&(data))>>8)
#define  LGCY_DEBLK_VPXFILTLVL_get_base_filt_lvl_0(data)                         (0x0000007F&(data))

#define  LGCY_DEBLK_VPXREFDELTA                                                  0x1800EAC8
#define  LGCY_DEBLK_VPXREFDELTA_reg_addr                                         "0xB800EAC8"
#define  LGCY_DEBLK_VPXREFDELTA_reg                                              0xB800EAC8
#define  LGCY_DEBLK_VPXREFDELTA_inst_addr                                        "0x0032"
#define  set_LGCY_DEBLK_VPXREFDELTA_reg(data)                                    (*((volatile unsigned int*)LGCY_DEBLK_VPXREFDELTA_reg)=data)
#define  get_LGCY_DEBLK_VPXREFDELTA_reg                                          (*((volatile unsigned int*)LGCY_DEBLK_VPXREFDELTA_reg))
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_3_shift                            (24)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_2_shift                            (16)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_1_shift                            (8)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_0_shift                            (0)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_3_mask                             (0x7F000000)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_2_mask                             (0x007F0000)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_1_mask                             (0x00007F00)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_0_mask                             (0x0000007F)
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_3(data)                            (0x7F000000&((data)<<24))
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_2(data)                            (0x007F0000&((data)<<16))
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_1(data)                            (0x00007F00&((data)<<8))
#define  LGCY_DEBLK_VPXREFDELTA_ref_lf_deltas_0(data)                            (0x0000007F&(data))
#define  LGCY_DEBLK_VPXREFDELTA_get_ref_lf_deltas_3(data)                        ((0x7F000000&(data))>>24)
#define  LGCY_DEBLK_VPXREFDELTA_get_ref_lf_deltas_2(data)                        ((0x007F0000&(data))>>16)
#define  LGCY_DEBLK_VPXREFDELTA_get_ref_lf_deltas_1(data)                        ((0x00007F00&(data))>>8)
#define  LGCY_DEBLK_VPXREFDELTA_get_ref_lf_deltas_0(data)                        (0x0000007F&(data))

#define  LGCY_DEBLK_VPXMODEDELTA                                                 0x1800EACC
#define  LGCY_DEBLK_VPXMODEDELTA_reg_addr                                        "0xB800EACC"
#define  LGCY_DEBLK_VPXMODEDELTA_reg                                             0xB800EACC
#define  LGCY_DEBLK_VPXMODEDELTA_inst_addr                                       "0x0033"
#define  set_LGCY_DEBLK_VPXMODEDELTA_reg(data)                                   (*((volatile unsigned int*)LGCY_DEBLK_VPXMODEDELTA_reg)=data)
#define  get_LGCY_DEBLK_VPXMODEDELTA_reg                                         (*((volatile unsigned int*)LGCY_DEBLK_VPXMODEDELTA_reg))
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_3_shift                          (24)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_2_shift                          (16)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_1_shift                          (8)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_0_shift                          (0)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_3_mask                           (0x7F000000)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_2_mask                           (0x007F0000)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_1_mask                           (0x00007F00)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_0_mask                           (0x0000007F)
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_3(data)                          (0x7F000000&((data)<<24))
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_2(data)                          (0x007F0000&((data)<<16))
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_1(data)                          (0x00007F00&((data)<<8))
#define  LGCY_DEBLK_VPXMODEDELTA_mode_lf_deltas_0(data)                          (0x0000007F&(data))
#define  LGCY_DEBLK_VPXMODEDELTA_get_mode_lf_deltas_3(data)                      ((0x7F000000&(data))>>24)
#define  LGCY_DEBLK_VPXMODEDELTA_get_mode_lf_deltas_2(data)                      ((0x007F0000&(data))>>16)
#define  LGCY_DEBLK_VPXMODEDELTA_get_mode_lf_deltas_1(data)                      ((0x00007F00&(data))>>8)
#define  LGCY_DEBLK_VPXMODEDELTA_get_mode_lf_deltas_0(data)                      (0x0000007F&(data))

#define  LGCY_DEBLK_VPXDBPAR                                                     0x1800EAD0
#define  LGCY_DEBLK_VPXDBPAR_reg_addr                                            "0xB800EAD0"
#define  LGCY_DEBLK_VPXDBPAR_reg                                                 0xB800EAD0
#define  LGCY_DEBLK_VPXDBPAR_inst_addr                                           "0x0034"
#define  set_LGCY_DEBLK_VPXDBPAR_reg(data)                                       (*((volatile unsigned int*)LGCY_DEBLK_VPXDBPAR_reg)=data)
#define  get_LGCY_DEBLK_VPXDBPAR_reg                                             (*((volatile unsigned int*)LGCY_DEBLK_VPXDBPAR_reg))
#define  LGCY_DEBLK_VPXDBPAR_intra_mb_shift                                      (6)
#define  LGCY_DEBLK_VPXDBPAR_eob_total_shift                                     (5)
#define  LGCY_DEBLK_VPXDBPAR_ref_frame_shift                                     (3)
#define  LGCY_DEBLK_VPXDBPAR_mb_mode_shift                                       (0)
#define  LGCY_DEBLK_VPXDBPAR_intra_mb_mask                                       (0x00000040)
#define  LGCY_DEBLK_VPXDBPAR_eob_total_mask                                      (0x00000020)
#define  LGCY_DEBLK_VPXDBPAR_ref_frame_mask                                      (0x00000018)
#define  LGCY_DEBLK_VPXDBPAR_mb_mode_mask                                        (0x00000007)
#define  LGCY_DEBLK_VPXDBPAR_intra_mb(data)                                      (0x00000040&((data)<<6))
#define  LGCY_DEBLK_VPXDBPAR_eob_total(data)                                     (0x00000020&((data)<<5))
#define  LGCY_DEBLK_VPXDBPAR_ref_frame(data)                                     (0x00000018&((data)<<3))
#define  LGCY_DEBLK_VPXDBPAR_mb_mode(data)                                       (0x00000007&(data))
#define  LGCY_DEBLK_VPXDBPAR_get_intra_mb(data)                                  ((0x00000040&(data))>>6)
#define  LGCY_DEBLK_VPXDBPAR_get_eob_total(data)                                 ((0x00000020&(data))>>5)
#define  LGCY_DEBLK_VPXDBPAR_get_ref_frame(data)                                 ((0x00000018&(data))>>3)
#define  LGCY_DEBLK_VPXDBPAR_get_mb_mode(data)                                   (0x00000007&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_DEBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pictype:3;
        RBus_UInt32  first_mb:1;
        RBus_UInt32  cur_mb_x:10;
        RBus_UInt32  cur_mb_y:9;
    };
}lgcy_deblk_ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  intramb_flag:1;
        RBus_UInt32  intra_flag:5;
        RBus_UInt32  submb_partition:12;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  fieldtx:1;
        RBus_UInt32  overflag:1;
    };
}lgcy_deblk_vc1ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  parcom_starta:7;
    };
}lgcy_deblk_parsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  new_slice_row:1;
        RBus_UInt32  new_slice_mb_x:9;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  sw_neighbor_enable:1;
        RBus_UInt32  mbaddra_available:1;
        RBus_UInt32  mbaddrb_available:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  mbaddrd_available:1;
    };
}lgcy_deblk_neighbor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  avs_alpha_c_offset:5;
        RBus_UInt32  avs_beta_offset:5;
        RBus_UInt32  slice_alpha_c0_offset_div2:4;
        RBus_UInt32  slice_beta_offset_div2:4;
        RBus_UInt32  disable_deblocking_filter_idc:2;
    };
}lgcy_deblk_debcntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  lambda_mode:1;
        RBus_UInt32  thr_3:4;
        RBus_UInt32  thr_2:4;
        RBus_UInt32  thr_1:4;
    };
}lgcy_deblk_debcntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dmy_auto_mode:1;
        RBus_UInt32  dmy_mb_row:1;
        RBus_UInt32  dmy_mb_clm:1;
    };
}lgcy_deblk_h264ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  intra_flag:1;
        RBus_UInt32  transform_size_8x8_flag:1;
        RBus_UInt32  qpy:6;
        RBus_UInt32  qpcb:6;
        RBus_UInt32  qpcr:6;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  mb_partition:9;
    };
}lgcy_deblk_h264dbpar0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  bs1_valid_ext:4;
        RBus_UInt32  subblkpat:24;
    };
}lgcy_deblk_h264dbpar1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bs1_valid:32;
    };
}lgcy_deblk_h264dbpar2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lu_mv_equal:32;
    };
}lgcy_deblk_vc1dbpar0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subblkpat:24;
        RBus_UInt32  ch_mv_equal:8;
    };
}lgcy_deblk_vc1dbpar1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  refqp:5;
        RBus_UInt32  beta2sel:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  is_key_frame:1;
        RBus_UInt32  chroma_only:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sel_s_chroma_deblock:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  str9_initqp:5;
        RBus_UInt32  str8_initqp:5;
        RBus_UInt32  str7_initqp:5;
    };
}lgcy_deblk_rvctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  str6_initqp:5;
        RBus_UInt32  str5_initqp:5;
        RBus_UInt32  str4_initqp:5;
        RBus_UInt32  str3_initqp:5;
        RBus_UInt32  str2_initqp:5;
        RBus_UInt32  str1_initqp:5;
    };
}lgcy_deblk_rv8ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mvd:16;
        RBus_UInt32  qp:5;
    };
}lgcy_deblk_rvdbpar0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  up_mvd_mod:4;
        RBus_UInt32  left_mvd_mod:4;
        RBus_UInt32  ul_str_eq2:1;
        RBus_UInt32  up_str_eq2:1;
        RBus_UInt32  left_str_eq2:1;
        RBus_UInt32  cur_str_eq2:1;
        RBus_UInt32  up_ul_refdiff:1;
        RBus_UInt32  left_ul_refdiff:1;
        RBus_UInt32  cur_l_refdiff:1;
        RBus_UInt32  cur_up_refdiff:1;
        RBus_UInt32  up_cur_refdiff:1;
    };
}lgcy_deblk_rvdbpar1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  subblk2clip_ch:1;
        RBus_UInt32  subblk12clip_lu:1;
    };
}lgcy_deblk_rv9clip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  is_skip:1;
        RBus_UInt32  qpch:5;
        RBus_UInt32  qpy:5;
    };
}lgcy_deblk_wmv8dbpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  basea0:7;
        RBus_UInt32  basea1:7;
    };
}lgcy_deblk_vmadrba_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  offseta0:7;
        RBus_UInt32  offseta1:7;
        RBus_UInt32  offseta2:7;
    };
}lgcy_deblk_vmadroa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  mb_case_dbg_en:1;
        RBus_UInt32  mb_case_dbg:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  sb_load_disable:3;
    };
}lgcy_deblk_debsbctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dual_issue_disable:1;
        RBus_UInt32  bot_sb_st_disable:1;
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  dma_idle:1;
        RBus_UInt32  go:1;
        RBus_UInt32  klm_addr_update:1;
        RBus_UInt32  km_addr_update:1;
    };
}lgcy_deblk_dmactrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lu_addr_idx:7;
        RBus_UInt32  klm_lu_x_sel:1;
        RBus_UInt32  klm_lu_top_row_inc:6;
        RBus_UInt32  klm_lu_inc:6;
        RBus_UInt32  km_lu_mb_offset:6;
        RBus_UInt32  km_lu_row_offset:6;
    };
}lgcy_deblk_dmalu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_addr_idx:7;
        RBus_UInt32  klm_ch_x_sel:1;
        RBus_UInt32  klm_ch_top_row_inc:6;
        RBus_UInt32  klm_ch_inc:6;
        RBus_UInt32  km_ch_mb_offset:6;
        RBus_UInt32  km_ch_row_offset:6;
    };
}lgcy_deblk_dmach_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  klm_ch_h:5;
        RBus_UInt32  klm_ch_w:1;
        RBus_UInt32  klm_lu_h:6;
        RBus_UInt32  klm_lu_w:1;
        RBus_UInt32  km_ch_h:4;
        RBus_UInt32  km_ch_w:1;
        RBus_UInt32  km_lu_h:5;
        RBus_UInt32  km_lu_w:1;
    };
}lgcy_deblk_dmawh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  x:13;
        RBus_UInt32  y:14;
    };
}lgcy_deblk_dmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ctb_row_offset:7;
    };
}lgcy_deblk_dmactb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_dma_addr:32;
    };
}lgcy_deblk_sdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  seq_dma_bl:9;
    };
}lgcy_deblk_sdmabl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  last_filter_type:1;
        RBus_UInt32  last_sharp_level:3;
        RBus_UInt32  last_frame_type:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  filter_type:1;
        RBus_UInt32  sharp_level:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  lf_delta_enable:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  segment_enable:1;
    };
}lgcy_deblk_vpxctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  base_filt_lvl_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  base_filt_lvl_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  base_filt_lvl_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  base_filt_lvl_0:7;
    };
}lgcy_deblk_vpxfiltlvl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ref_lf_deltas_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ref_lf_deltas_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  ref_lf_deltas_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  ref_lf_deltas_0:7;
    };
}lgcy_deblk_vpxrefdelta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  mode_lf_deltas_3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  mode_lf_deltas_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  mode_lf_deltas_1:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  mode_lf_deltas_0:7;
    };
}lgcy_deblk_vpxmodedelta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  intra_mb:1;
        RBus_UInt32  eob_total:1;
        RBus_UInt32  ref_frame:2;
        RBus_UInt32  mb_mode:3;
    };
}lgcy_deblk_vpxdbpar_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_DEBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cur_mb_y:9;
        RBus_UInt32  cur_mb_x:10;
        RBus_UInt32  first_mb:1;
        RBus_UInt32  pictype:3;
        RBus_UInt32  res1:9;
    };
}lgcy_deblk_ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  overflag:1;
        RBus_UInt32  fieldtx:1;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  submb_partition:12;
        RBus_UInt32  intra_flag:5;
        RBus_UInt32  intramb_flag:1;
        RBus_UInt32  res1:10;
    };
}lgcy_deblk_vc1ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  parcom_starta:7;
        RBus_UInt32  res1:25;
    };
}lgcy_deblk_parsa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mbaddrd_available:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  mbaddrb_available:1;
        RBus_UInt32  mbaddra_available:1;
        RBus_UInt32  sw_neighbor_enable:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  new_slice_mb_x:9;
        RBus_UInt32  new_slice_row:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:11;
    };
}lgcy_deblk_neighbor_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disable_deblocking_filter_idc:2;
        RBus_UInt32  slice_beta_offset_div2:4;
        RBus_UInt32  slice_alpha_c0_offset_div2:4;
        RBus_UInt32  avs_beta_offset:5;
        RBus_UInt32  avs_alpha_c_offset:5;
        RBus_UInt32  res1:12;
    };
}lgcy_deblk_debcntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  thr_1:4;
        RBus_UInt32  thr_2:4;
        RBus_UInt32  thr_3:4;
        RBus_UInt32  lambda_mode:1;
        RBus_UInt32  res1:19;
    };
}lgcy_deblk_debcntl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy_mb_clm:1;
        RBus_UInt32  dmy_mb_row:1;
        RBus_UInt32  dmy_auto_mode:1;
        RBus_UInt32  res1:29;
    };
}lgcy_deblk_h264ccpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_partition:9;
        RBus_UInt32  mb_field_decoding_flag:1;
        RBus_UInt32  qpcr:6;
        RBus_UInt32  qpcb:6;
        RBus_UInt32  qpy:6;
        RBus_UInt32  transform_size_8x8_flag:1;
        RBus_UInt32  intra_flag:1;
        RBus_UInt32  res1:2;
    };
}lgcy_deblk_h264dbpar0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subblkpat:24;
        RBus_UInt32  bs1_valid_ext:4;
        RBus_UInt32  res1:4;
    };
}lgcy_deblk_h264dbpar1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bs1_valid:32;
    };
}lgcy_deblk_h264dbpar2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lu_mv_equal:32;
    };
}lgcy_deblk_vc1dbpar0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_mv_equal:8;
        RBus_UInt32  subblkpat:24;
    };
}lgcy_deblk_vc1dbpar1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  str7_initqp:5;
        RBus_UInt32  str8_initqp:5;
        RBus_UInt32  str9_initqp:5;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  sel_s_chroma_deblock:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  chroma_only:1;
        RBus_UInt32  is_key_frame:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  beta2sel:1;
        RBus_UInt32  refqp:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:4;
    };
}lgcy_deblk_rvctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  str1_initqp:5;
        RBus_UInt32  str2_initqp:5;
        RBus_UInt32  str3_initqp:5;
        RBus_UInt32  str4_initqp:5;
        RBus_UInt32  str5_initqp:5;
        RBus_UInt32  str6_initqp:5;
        RBus_UInt32  res1:2;
    };
}lgcy_deblk_rv8ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qp:5;
        RBus_UInt32  mvd:16;
        RBus_UInt32  res1:11;
    };
}lgcy_deblk_rvdbpar0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  up_cur_refdiff:1;
        RBus_UInt32  cur_up_refdiff:1;
        RBus_UInt32  cur_l_refdiff:1;
        RBus_UInt32  left_ul_refdiff:1;
        RBus_UInt32  up_ul_refdiff:1;
        RBus_UInt32  cur_str_eq2:1;
        RBus_UInt32  left_str_eq2:1;
        RBus_UInt32  up_str_eq2:1;
        RBus_UInt32  ul_str_eq2:1;
        RBus_UInt32  left_mvd_mod:4;
        RBus_UInt32  up_mvd_mod:4;
        RBus_UInt32  res1:15;
    };
}lgcy_deblk_rvdbpar1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  subblk12clip_lu:1;
        RBus_UInt32  subblk2clip_ch:1;
        RBus_UInt32  res1:30;
    };
}lgcy_deblk_rv9clip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  qpy:5;
        RBus_UInt32  qpch:5;
        RBus_UInt32  is_skip:1;
        RBus_UInt32  res1:21;
    };
}lgcy_deblk_wmv8dbpar_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  basea1:7;
        RBus_UInt32  basea0:7;
        RBus_UInt32  res1:18;
    };
}lgcy_deblk_vmadrba_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offseta2:7;
        RBus_UInt32  offseta1:7;
        RBus_UInt32  offseta0:7;
        RBus_UInt32  res1:11;
    };
}lgcy_deblk_vmadroa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sb_load_disable:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  mb_case_dbg:4;
        RBus_UInt32  mb_case_dbg_en:1;
        RBus_UInt32  res2:23;
    };
}lgcy_deblk_debsbctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  km_addr_update:1;
        RBus_UInt32  klm_addr_update:1;
        RBus_UInt32  go:1;
        RBus_UInt32  dma_idle:1;
        RBus_UInt32  post_write_disable:1;
        RBus_UInt32  bot_sb_st_disable:1;
        RBus_UInt32  dual_issue_disable:1;
        RBus_UInt32  res1:25;
    };
}lgcy_deblk_dmactrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  km_lu_row_offset:6;
        RBus_UInt32  km_lu_mb_offset:6;
        RBus_UInt32  klm_lu_inc:6;
        RBus_UInt32  klm_lu_top_row_inc:6;
        RBus_UInt32  klm_lu_x_sel:1;
        RBus_UInt32  lu_addr_idx:7;
    };
}lgcy_deblk_dmalu_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  km_ch_row_offset:6;
        RBus_UInt32  km_ch_mb_offset:6;
        RBus_UInt32  klm_ch_inc:6;
        RBus_UInt32  klm_ch_top_row_inc:6;
        RBus_UInt32  klm_ch_x_sel:1;
        RBus_UInt32  ch_addr_idx:7;
    };
}lgcy_deblk_dmach_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  km_lu_w:1;
        RBus_UInt32  km_lu_h:5;
        RBus_UInt32  km_ch_w:1;
        RBus_UInt32  km_ch_h:4;
        RBus_UInt32  klm_lu_w:1;
        RBus_UInt32  klm_lu_h:6;
        RBus_UInt32  klm_ch_w:1;
        RBus_UInt32  klm_ch_h:5;
        RBus_UInt32  res1:8;
    };
}lgcy_deblk_dmawh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:14;
        RBus_UInt32  x:13;
        RBus_UInt32  res1:5;
    };
}lgcy_deblk_dmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctb_row_offset:7;
        RBus_UInt32  res1:25;
    };
}lgcy_deblk_dmactb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_dma_addr:32;
    };
}lgcy_deblk_sdmaadr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_dma_bl:9;
        RBus_UInt32  res1:23;
    };
}lgcy_deblk_sdmabl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  segment_enable:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  lf_delta_enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sharp_level:3;
        RBus_UInt32  filter_type:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  last_frame_type:1;
        RBus_UInt32  last_sharp_level:3;
        RBus_UInt32  last_filter_type:1;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:17;
    };
}lgcy_deblk_vpxctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  base_filt_lvl_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  base_filt_lvl_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  base_filt_lvl_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  base_filt_lvl_3:7;
        RBus_UInt32  res4:1;
    };
}lgcy_deblk_vpxfiltlvl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ref_lf_deltas_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ref_lf_deltas_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ref_lf_deltas_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  ref_lf_deltas_3:7;
        RBus_UInt32  res4:1;
    };
}lgcy_deblk_vpxrefdelta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_lf_deltas_0:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  mode_lf_deltas_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  mode_lf_deltas_2:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  mode_lf_deltas_3:7;
        RBus_UInt32  res4:1;
    };
}lgcy_deblk_vpxmodedelta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_mode:3;
        RBus_UInt32  ref_frame:2;
        RBus_UInt32  eob_total:1;
        RBus_UInt32  intra_mb:1;
        RBus_UInt32  res1:25;
    };
}lgcy_deblk_vpxdbpar_RBUS;




#endif 


#endif 
