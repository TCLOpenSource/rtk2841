/**
* @file rbusDeblkReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/5
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DEBLK_REG_H_
#define _RBUS_DEBLK_REG_H_

#include "rbusTypes.h"



//  DEBLK Register Address
#define  DEBLK_CCPAR                                                             0x1800EA00
#define  DEBLK_CCPAR_reg_addr                                                    "0xB800EA00"
#define  DEBLK_CCPAR_reg                                                         0xB800EA00
#define  DEBLK_CCPAR_inst_addr                                                   "0x0000"
#define  DEBLK_CCPAR_inst_adr                                                    "0x0080"
#define  DEBLK_CCPAR_inst                                                        0x0080
#define  set_DEBLK_CCPAR_reg(data)                                               (*((volatile unsigned int*)DEBLK_CCPAR_reg)=data)
#define  get_DEBLK_CCPAR_reg                                                     (*((volatile unsigned int*)DEBLK_CCPAR_reg))
#define  DEBLK_CCPAR_PicType_shift                                               (20)
#define  DEBLK_CCPAR_First_mb_shift                                              (19)
#define  DEBLK_CCPAR_Cur_mb_x_shift                                              (9)
#define  DEBLK_CCPAR_Cur_mb_y_shift                                              (0)
#define  DEBLK_CCPAR_PicType_mask                                                (0x00700000)
#define  DEBLK_CCPAR_First_mb_mask                                               (0x00080000)
#define  DEBLK_CCPAR_Cur_mb_x_mask                                               (0x0007FE00)
#define  DEBLK_CCPAR_Cur_mb_y_mask                                               (0x000001FF)
#define  DEBLK_CCPAR_PicType(data)                                               (0x00700000&((data)<<20))
#define  DEBLK_CCPAR_First_mb(data)                                              (0x00080000&((data)<<19))
#define  DEBLK_CCPAR_Cur_mb_x(data)                                              (0x0007FE00&((data)<<9))
#define  DEBLK_CCPAR_Cur_mb_y(data)                                              (0x000001FF&(data))
#define  DEBLK_CCPAR_get_PicType(data)                                           ((0x00700000&(data))>>20)
#define  DEBLK_CCPAR_get_First_mb(data)                                          ((0x00080000&(data))>>19)
#define  DEBLK_CCPAR_get_Cur_mb_x(data)                                          ((0x0007FE00&(data))>>9)
#define  DEBLK_CCPAR_get_Cur_mb_y(data)                                          (0x000001FF&(data))
#define  DEBLK_CCPAR_PicType_src(data)                                           ((0x00700000&(data))>>20)
#define  DEBLK_CCPAR_First_mb_src(data)                                          ((0x00080000&(data))>>19)
#define  DEBLK_CCPAR_Cur_mb_x_src(data)                                          ((0x0007FE00&(data))>>9)
#define  DEBLK_CCPAR_Cur_mb_y_src(data)                                          (0x000001FF&(data))

#define  DEBLK_VC1CCPAR_0                                                        0x1800EA04
#define  DEBLK_VC1CCPAR_0_reg_addr                                               "0xB800EA04"
#define  DEBLK_VC1CCPAR_0_reg                                                    0xB800EA04
#define  DEBLK_VC1CCPAR_0_inst_addr                                              "0x0001"
#define  DEBLK_VC1CCPAR_0_inst_adr                                               "0x0081"
#define  DEBLK_VC1CCPAR_0_inst                                                   0x0081
#define  set_DEBLK_VC1CCPAR_0_reg(data)                                          (*((volatile unsigned int*)DEBLK_VC1CCPAR_0_reg)=data)
#define  get_DEBLK_VC1CCPAR_0_reg                                                (*((volatile unsigned int*)DEBLK_VC1CCPAR_0_reg))
#define  DEBLK_VC1CCPAR_IntraMB_flag_shift                                       (21)
#define  DEBLK_VC1CCPAR_Intra_flag_shift                                         (16)
#define  DEBLK_VC1CCPAR_SubMB_partition_shift                                    (4)
#define  DEBLK_VC1CCPAR_mvtype_shift                                             (2)
#define  DEBLK_VC1CCPAR_FIELDTX_shift                                            (1)
#define  DEBLK_VC1CCPAR_OVERFLAG_shift                                           (0)
#define  DEBLK_VC1CCPAR_IntraMB_flag_mask                                        (0x00200000)
#define  DEBLK_VC1CCPAR_Intra_flag_mask                                          (0x001F0000)
#define  DEBLK_VC1CCPAR_SubMB_partition_mask                                     (0x0000FFF0)
#define  DEBLK_VC1CCPAR_mvtype_mask                                              (0x0000000C)
#define  DEBLK_VC1CCPAR_FIELDTX_mask                                             (0x00000002)
#define  DEBLK_VC1CCPAR_OVERFLAG_mask                                            (0x00000001)
#define  DEBLK_VC1CCPAR_IntraMB_flag(data)                                       (0x00200000&((data)<<21))
#define  DEBLK_VC1CCPAR_Intra_flag(data)                                         (0x001F0000&((data)<<16))
#define  DEBLK_VC1CCPAR_SubMB_partition(data)                                    (0x0000FFF0&((data)<<4))
#define  DEBLK_VC1CCPAR_mvtype(data)                                             (0x0000000C&((data)<<2))
#define  DEBLK_VC1CCPAR_FIELDTX(data)                                            (0x00000002&((data)<<1))
#define  DEBLK_VC1CCPAR_OVERFLAG(data)                                           (0x00000001&(data))
#define  DEBLK_VC1CCPAR_get_IntraMB_flag(data)                                   ((0x00200000&(data))>>21)
#define  DEBLK_VC1CCPAR_get_Intra_flag(data)                                     ((0x001F0000&(data))>>16)
#define  DEBLK_VC1CCPAR_get_SubMB_partition(data)                                ((0x0000FFF0&(data))>>4)
#define  DEBLK_VC1CCPAR_get_mvtype(data)                                         ((0x0000000C&(data))>>2)
#define  DEBLK_VC1CCPAR_get_FIELDTX(data)                                        ((0x00000002&(data))>>1)
#define  DEBLK_VC1CCPAR_get_OVERFLAG(data)                                       (0x00000001&(data))
#define  DEBLK_VC1CCPAR_IntraMB_flag_src(data)                                   ((0x00200000&(data))>>21)
#define  DEBLK_VC1CCPAR_Intra_flag_src(data)                                     ((0x001F0000&(data))>>16)
#define  DEBLK_VC1CCPAR_SubMB_partition_src(data)                                ((0x0000FFF0&(data))>>4)
#define  DEBLK_VC1CCPAR_mvtype_src(data)                                         ((0x0000000C&(data))>>2)
#define  DEBLK_VC1CCPAR_FIELDTX_src(data)                                        ((0x00000002&(data))>>1)
#define  DEBLK_VC1CCPAR_OVERFLAG_src(data)                                       (0x00000001&(data))

#define  DEBLK_VC1CCPAR_1                                                        0x1800EA08
#define  DEBLK_VC1CCPAR_1_reg_addr                                               "0xB800EA08"
#define  DEBLK_VC1CCPAR_1_reg                                                    0xB800EA08
#define  DEBLK_VC1CCPAR_1_inst_addr                                              "0x0002"
#define  DEBLK_VC1CCPAR_1_inst_adr                                               "0x0082"
#define  DEBLK_VC1CCPAR_1_inst                                                   0x0082
#define  set_DEBLK_VC1CCPAR_1_reg(data)                                          (*((volatile unsigned int*)DEBLK_VC1CCPAR_1_reg)=data)
#define  get_DEBLK_VC1CCPAR_1_reg                                                (*((volatile unsigned int*)DEBLK_VC1CCPAR_1_reg))

#define  DEBLK_PARSA                                                             0x1800EA0C
#define  DEBLK_PARSA_reg_addr                                                    "0xB800EA0C"
#define  DEBLK_PARSA_reg                                                         0xB800EA0C
#define  DEBLK_PARSA_inst_addr                                                   "0x0003"
#define  DEBLK_PARSA_inst_adr                                                    "0x0083"
#define  DEBLK_PARSA_inst                                                        0x0083
#define  set_DEBLK_PARSA_reg(data)                                               (*((volatile unsigned int*)DEBLK_PARSA_reg)=data)
#define  get_DEBLK_PARSA_reg                                                     (*((volatile unsigned int*)DEBLK_PARSA_reg))
#define  DEBLK_PARSA_ParCom_StartA_shift                                         (0)
#define  DEBLK_PARSA_ParCom_StartA_mask                                          (0x0000007F)
#define  DEBLK_PARSA_ParCom_StartA(data)                                         (0x0000007F&(data))
#define  DEBLK_PARSA_get_ParCom_StartA(data)                                     (0x0000007F&(data))
#define  DEBLK_PARSA_ParCom_StartA_src(data)                                     (0x0000007F&(data))

#define  DEBLK_NEIGHBOR                                                          0x1800EA10
#define  DEBLK_NEIGHBOR_reg_addr                                                 "0xB800EA10"
#define  DEBLK_NEIGHBOR_reg                                                      0xB800EA10
#define  DEBLK_NEIGHBOR_inst_addr                                                "0x0004"
#define  DEBLK_NEIGHBOR_inst_adr                                                 "0x0084"
#define  DEBLK_NEIGHBOR_inst                                                     0x0084
#define  set_DEBLK_NEIGHBOR_reg(data)                                            (*((volatile unsigned int*)DEBLK_NEIGHBOR_reg)=data)
#define  get_DEBLK_NEIGHBOR_reg                                                  (*((volatile unsigned int*)DEBLK_NEIGHBOR_reg))
#define  DEBLK_NEIGHBOR_write_enable1_shift                                      (16)
#define  DEBLK_NEIGHBOR_New_slice_row_shift                                      (15)
#define  DEBLK_NEIGHBOR_New_slice_mb_x_shift                                     (6)
#define  DEBLK_NEIGHBOR_write_enable0_shift                                      (5)
#define  DEBLK_NEIGHBOR_Sw_neighbor_enable_shift                                 (4)
#define  DEBLK_NEIGHBOR_MbAddrA_available_shift                                  (3)
#define  DEBLK_NEIGHBOR_MbAddrB_available_shift                                  (2)
#define  DEBLK_NEIGHBOR_MbAddrD_available_shift                                  (0)
#define  DEBLK_NEIGHBOR_write_enable1_mask                                       (0x00010000)
#define  DEBLK_NEIGHBOR_New_slice_row_mask                                       (0x00008000)
#define  DEBLK_NEIGHBOR_New_slice_mb_x_mask                                      (0x00007FC0)
#define  DEBLK_NEIGHBOR_write_enable0_mask                                       (0x00000020)
#define  DEBLK_NEIGHBOR_Sw_neighbor_enable_mask                                  (0x00000010)
#define  DEBLK_NEIGHBOR_MbAddrA_available_mask                                   (0x00000008)
#define  DEBLK_NEIGHBOR_MbAddrB_available_mask                                   (0x00000004)
#define  DEBLK_NEIGHBOR_MbAddrD_available_mask                                   (0x00000001)
#define  DEBLK_NEIGHBOR_write_enable1(data)                                      (0x00010000&((data)<<16))
#define  DEBLK_NEIGHBOR_New_slice_row(data)                                      (0x00008000&((data)<<15))
#define  DEBLK_NEIGHBOR_New_slice_mb_x(data)                                     (0x00007FC0&((data)<<6))
#define  DEBLK_NEIGHBOR_write_enable0(data)                                      (0x00000020&((data)<<5))
#define  DEBLK_NEIGHBOR_Sw_neighbor_enable(data)                                 (0x00000010&((data)<<4))
#define  DEBLK_NEIGHBOR_MbAddrA_available(data)                                  (0x00000008&((data)<<3))
#define  DEBLK_NEIGHBOR_MbAddrB_available(data)                                  (0x00000004&((data)<<2))
#define  DEBLK_NEIGHBOR_MbAddrD_available(data)                                  (0x00000001&(data))
#define  DEBLK_NEIGHBOR_get_write_enable1(data)                                  ((0x00010000&(data))>>16)
#define  DEBLK_NEIGHBOR_get_New_slice_row(data)                                  ((0x00008000&(data))>>15)
#define  DEBLK_NEIGHBOR_get_New_slice_mb_x(data)                                 ((0x00007FC0&(data))>>6)
#define  DEBLK_NEIGHBOR_get_write_enable0(data)                                  ((0x00000020&(data))>>5)
#define  DEBLK_NEIGHBOR_get_Sw_neighbor_enable(data)                             ((0x00000010&(data))>>4)
#define  DEBLK_NEIGHBOR_get_MbAddrA_available(data)                              ((0x00000008&(data))>>3)
#define  DEBLK_NEIGHBOR_get_MbAddrB_available(data)                              ((0x00000004&(data))>>2)
#define  DEBLK_NEIGHBOR_get_MbAddrD_available(data)                              (0x00000001&(data))
#define  DEBLK_NEIGHBOR_write_enable1_src(data)                                  ((0x00010000&(data))>>16)
#define  DEBLK_NEIGHBOR_New_slice_row_src(data)                                  ((0x00008000&(data))>>15)
#define  DEBLK_NEIGHBOR_New_slice_mb_x_src(data)                                 ((0x00007FC0&(data))>>6)
#define  DEBLK_NEIGHBOR_write_enable0_src(data)                                  ((0x00000020&(data))>>5)
#define  DEBLK_NEIGHBOR_Sw_neighbor_enable_src(data)                             ((0x00000010&(data))>>4)
#define  DEBLK_NEIGHBOR_MbAddrA_available_src(data)                              ((0x00000008&(data))>>3)
#define  DEBLK_NEIGHBOR_MbAddrB_available_src(data)                              ((0x00000004&(data))>>2)
#define  DEBLK_NEIGHBOR_MbAddrD_available_src(data)                              (0x00000001&(data))

#define  DEBLK_DEBCNTL                                                           0x1800EA14
#define  DEBLK_DEBCNTL_reg_addr                                                  "0xB800EA14"
#define  DEBLK_DEBCNTL_reg                                                       0xB800EA14
#define  DEBLK_DEBCNTL_inst_addr                                                 "0x0005"
#define  DEBLK_DEBCNTL_inst_adr                                                  "0x0085"
#define  DEBLK_DEBCNTL_inst                                                      0x0085
#define  set_DEBLK_DEBCNTL_reg(data)                                             (*((volatile unsigned int*)DEBLK_DEBCNTL_reg)=data)
#define  get_DEBLK_DEBCNTL_reg                                                   (*((volatile unsigned int*)DEBLK_DEBCNTL_reg))
#define  DEBLK_DEBCNTL_avs_alpha_c_offset_shift                                  (15)
#define  DEBLK_DEBCNTL_avs_beta_offset_shift                                     (10)
#define  DEBLK_DEBCNTL_slice_alpha_c0_offset_div2_shift                          (6)
#define  DEBLK_DEBCNTL_slice_beta_offset_div2_shift                              (2)
#define  DEBLK_DEBCNTL_disable_deblocking_filter_idc_shift                       (0)
#define  DEBLK_DEBCNTL_avs_alpha_c_offset_mask                                   (0x000F8000)
#define  DEBLK_DEBCNTL_avs_beta_offset_mask                                      (0x00007C00)
#define  DEBLK_DEBCNTL_slice_alpha_c0_offset_div2_mask                           (0x000003C0)
#define  DEBLK_DEBCNTL_slice_beta_offset_div2_mask                               (0x0000003C)
#define  DEBLK_DEBCNTL_disable_deblocking_filter_idc_mask                        (0x00000003)
#define  DEBLK_DEBCNTL_avs_alpha_c_offset(data)                                  (0x000F8000&((data)<<15))
#define  DEBLK_DEBCNTL_avs_beta_offset(data)                                     (0x00007C00&((data)<<10))
#define  DEBLK_DEBCNTL_slice_alpha_c0_offset_div2(data)                          (0x000003C0&((data)<<6))
#define  DEBLK_DEBCNTL_slice_beta_offset_div2(data)                              (0x0000003C&((data)<<2))
#define  DEBLK_DEBCNTL_disable_deblocking_filter_idc(data)                       (0x00000003&(data))
#define  DEBLK_DEBCNTL_get_avs_alpha_c_offset(data)                              ((0x000F8000&(data))>>15)
#define  DEBLK_DEBCNTL_get_avs_beta_offset(data)                                 ((0x00007C00&(data))>>10)
#define  DEBLK_DEBCNTL_get_slice_alpha_c0_offset_div2(data)                      ((0x000003C0&(data))>>6)
#define  DEBLK_DEBCNTL_get_slice_beta_offset_div2(data)                          ((0x0000003C&(data))>>2)
#define  DEBLK_DEBCNTL_get_disable_deblocking_filter_idc(data)                   (0x00000003&(data))
#define  DEBLK_DEBCNTL_avs_alpha_c_offset_src(data)                              ((0x000F8000&(data))>>15)
#define  DEBLK_DEBCNTL_avs_beta_offset_src(data)                                 ((0x00007C00&(data))>>10)
#define  DEBLK_DEBCNTL_slice_alpha_c0_offset_div2_src(data)                      ((0x000003C0&(data))>>6)
#define  DEBLK_DEBCNTL_slice_beta_offset_div2_src(data)                          ((0x0000003C&(data))>>2)
#define  DEBLK_DEBCNTL_disable_deblocking_filter_idc_src(data)                   (0x00000003&(data))

#define  DEBLK_DEBCNTL2                                                          0x1800EA18
#define  DEBLK_DEBCNTL2_reg_addr                                                 "0xB800EA18"
#define  DEBLK_DEBCNTL2_reg                                                      0xB800EA18
#define  DEBLK_DEBCNTL2_inst_addr                                                "0x0006"
#define  DEBLK_DEBCNTL2_inst_adr                                                 "0x0086"
#define  DEBLK_DEBCNTL2_inst                                                     0x0086
#define  set_DEBLK_DEBCNTL2_reg(data)                                            (*((volatile unsigned int*)DEBLK_DEBCNTL2_reg)=data)
#define  get_DEBLK_DEBCNTL2_reg                                                  (*((volatile unsigned int*)DEBLK_DEBCNTL2_reg))
#define  DEBLK_DEBCNTL2_lambda_mode_shift                                        (12)
#define  DEBLK_DEBCNTL2_thr_3_shift                                              (8)
#define  DEBLK_DEBCNTL2_thr_2_shift                                              (4)
#define  DEBLK_DEBCNTL2_thr_1_shift                                              (0)
#define  DEBLK_DEBCNTL2_lambda_mode_mask                                         (0x00001000)
#define  DEBLK_DEBCNTL2_thr_3_mask                                               (0x00000F00)
#define  DEBLK_DEBCNTL2_thr_2_mask                                               (0x000000F0)
#define  DEBLK_DEBCNTL2_thr_1_mask                                               (0x0000000F)
#define  DEBLK_DEBCNTL2_lambda_mode(data)                                        (0x00001000&((data)<<12))
#define  DEBLK_DEBCNTL2_thr_3(data)                                              (0x00000F00&((data)<<8))
#define  DEBLK_DEBCNTL2_thr_2(data)                                              (0x000000F0&((data)<<4))
#define  DEBLK_DEBCNTL2_thr_1(data)                                              (0x0000000F&(data))
#define  DEBLK_DEBCNTL2_get_lambda_mode(data)                                    ((0x00001000&(data))>>12)
#define  DEBLK_DEBCNTL2_get_thr_3(data)                                          ((0x00000F00&(data))>>8)
#define  DEBLK_DEBCNTL2_get_thr_2(data)                                          ((0x000000F0&(data))>>4)
#define  DEBLK_DEBCNTL2_get_thr_1(data)                                          (0x0000000F&(data))
#define  DEBLK_DEBCNTL2_lambda_mode_src(data)                                    ((0x00001000&(data))>>12)
#define  DEBLK_DEBCNTL2_thr_3_src(data)                                          ((0x00000F00&(data))>>8)
#define  DEBLK_DEBCNTL2_thr_2_src(data)                                          ((0x000000F0&(data))>>4)
#define  DEBLK_DEBCNTL2_thr_1_src(data)                                          (0x0000000F&(data))

#define  DEBLK_H264CCPAR                                                         0x1800EA1C
#define  DEBLK_H264CCPAR_reg_addr                                                "0xB800EA1C"
#define  DEBLK_H264CCPAR_reg                                                     0xB800EA1C
#define  DEBLK_H264CCPAR_inst_addr                                               "0x0007"
#define  DEBLK_H264CCPAR_inst_adr                                                "0x0087"
#define  DEBLK_H264CCPAR_inst                                                    0x0087
#define  set_DEBLK_H264CCPAR_reg(data)                                           (*((volatile unsigned int*)DEBLK_H264CCPAR_reg)=data)
#define  get_DEBLK_H264CCPAR_reg                                                 (*((volatile unsigned int*)DEBLK_H264CCPAR_reg))
#define  DEBLK_H264CCPAR_dmy_auto_mode_shift                                     (2)
#define  DEBLK_H264CCPAR_dmy_mb_row_shift                                        (1)
#define  DEBLK_H264CCPAR_dmy_mb_clm_shift                                        (0)
#define  DEBLK_H264CCPAR_dmy_auto_mode_mask                                      (0x00000004)
#define  DEBLK_H264CCPAR_dmy_mb_row_mask                                         (0x00000002)
#define  DEBLK_H264CCPAR_dmy_mb_clm_mask                                         (0x00000001)
#define  DEBLK_H264CCPAR_dmy_auto_mode(data)                                     (0x00000004&((data)<<2))
#define  DEBLK_H264CCPAR_dmy_mb_row(data)                                        (0x00000002&((data)<<1))
#define  DEBLK_H264CCPAR_dmy_mb_clm(data)                                        (0x00000001&(data))
#define  DEBLK_H264CCPAR_get_dmy_auto_mode(data)                                 ((0x00000004&(data))>>2)
#define  DEBLK_H264CCPAR_get_dmy_mb_row(data)                                    ((0x00000002&(data))>>1)
#define  DEBLK_H264CCPAR_get_dmy_mb_clm(data)                                    (0x00000001&(data))
#define  DEBLK_H264CCPAR_dmy_auto_mode_src(data)                                 ((0x00000004&(data))>>2)
#define  DEBLK_H264CCPAR_dmy_mb_row_src(data)                                    ((0x00000002&(data))>>1)
#define  DEBLK_H264CCPAR_dmy_mb_clm_src(data)                                    (0x00000001&(data))

#define  DEBLK_H264DBPAR0_0                                                      0x1800EA20
#define  DEBLK_H264DBPAR0_0_reg_addr                                             "0xB800EA20"
#define  DEBLK_H264DBPAR0_0_reg                                                  0xB800EA20
#define  DEBLK_H264DBPAR0_0_inst_addr                                            "0x0008"
#define  DEBLK_H264DBPAR0_0_inst_adr                                             "0x0088"
#define  DEBLK_H264DBPAR0_0_inst                                                 0x0088
#define  set_DEBLK_H264DBPAR0_0_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR0_0_reg)=data)
#define  get_DEBLK_H264DBPAR0_0_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR0_0_reg))
#define  DEBLK_H264DBPAR0_Intra_flag_shift                                       (29)
#define  DEBLK_H264DBPAR0_transform_size_8x8_flag_shift                          (28)
#define  DEBLK_H264DBPAR0_QPy_shift                                              (22)
#define  DEBLK_H264DBPAR0_QPcb_shift                                             (16)
#define  DEBLK_H264DBPAR0_QPcr_shift                                             (10)
#define  DEBLK_H264DBPAR0_MB_field_decoding_flag_shift                           (9)
#define  DEBLK_H264DBPAR0_Mb_partition_shift                                     (0)
#define  DEBLK_H264DBPAR0_Intra_flag_mask                                        (0x20000000)
#define  DEBLK_H264DBPAR0_transform_size_8x8_flag_mask                           (0x10000000)
#define  DEBLK_H264DBPAR0_QPy_mask                                               (0x0FC00000)
#define  DEBLK_H264DBPAR0_QPcb_mask                                              (0x003F0000)
#define  DEBLK_H264DBPAR0_QPcr_mask                                              (0x0000FC00)
#define  DEBLK_H264DBPAR0_MB_field_decoding_flag_mask                            (0x00000200)
#define  DEBLK_H264DBPAR0_Mb_partition_mask                                      (0x000001FF)
#define  DEBLK_H264DBPAR0_Intra_flag(data)                                       (0x20000000&((data)<<29))
#define  DEBLK_H264DBPAR0_transform_size_8x8_flag(data)                          (0x10000000&((data)<<28))
#define  DEBLK_H264DBPAR0_QPy(data)                                              (0x0FC00000&((data)<<22))
#define  DEBLK_H264DBPAR0_QPcb(data)                                             (0x003F0000&((data)<<16))
#define  DEBLK_H264DBPAR0_QPcr(data)                                             (0x0000FC00&((data)<<10))
#define  DEBLK_H264DBPAR0_MB_field_decoding_flag(data)                           (0x00000200&((data)<<9))
#define  DEBLK_H264DBPAR0_Mb_partition(data)                                     (0x000001FF&(data))
#define  DEBLK_H264DBPAR0_get_Intra_flag(data)                                   ((0x20000000&(data))>>29)
#define  DEBLK_H264DBPAR0_get_transform_size_8x8_flag(data)                      ((0x10000000&(data))>>28)
#define  DEBLK_H264DBPAR0_get_QPy(data)                                          ((0x0FC00000&(data))>>22)
#define  DEBLK_H264DBPAR0_get_QPcb(data)                                         ((0x003F0000&(data))>>16)
#define  DEBLK_H264DBPAR0_get_QPcr(data)                                         ((0x0000FC00&(data))>>10)
#define  DEBLK_H264DBPAR0_get_MB_field_decoding_flag(data)                       ((0x00000200&(data))>>9)
#define  DEBLK_H264DBPAR0_get_Mb_partition(data)                                 (0x000001FF&(data))
#define  DEBLK_H264DBPAR0_Intra_flag_src(data)                                   ((0x20000000&(data))>>29)
#define  DEBLK_H264DBPAR0_transform_size_8x8_flag_src(data)                      ((0x10000000&(data))>>28)
#define  DEBLK_H264DBPAR0_QPy_src(data)                                          ((0x0FC00000&(data))>>22)
#define  DEBLK_H264DBPAR0_QPcb_src(data)                                         ((0x003F0000&(data))>>16)
#define  DEBLK_H264DBPAR0_QPcr_src(data)                                         ((0x0000FC00&(data))>>10)
#define  DEBLK_H264DBPAR0_MB_field_decoding_flag_src(data)                       ((0x00000200&(data))>>9)
#define  DEBLK_H264DBPAR0_Mb_partition_src(data)                                 (0x000001FF&(data))

#define  DEBLK_H264DBPAR0_1                                                      0x1800EA24
#define  DEBLK_H264DBPAR0_1_reg_addr                                             "0xB800EA24"
#define  DEBLK_H264DBPAR0_1_reg                                                  0xB800EA24
#define  DEBLK_H264DBPAR0_1_inst_addr                                            "0x0009"
#define  DEBLK_H264DBPAR0_1_inst_adr                                             "0x0089"
#define  DEBLK_H264DBPAR0_1_inst                                                 0x0089
#define  set_DEBLK_H264DBPAR0_1_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR0_1_reg)=data)
#define  get_DEBLK_H264DBPAR0_1_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR0_1_reg))

#define  DEBLK_H264DBPAR0_2                                                      0x1800EA28
#define  DEBLK_H264DBPAR0_2_reg_addr                                             "0xB800EA28"
#define  DEBLK_H264DBPAR0_2_reg                                                  0xB800EA28
#define  DEBLK_H264DBPAR0_2_inst_addr                                            "0x000A"
#define  DEBLK_H264DBPAR0_2_inst_adr                                             "0x008A"
#define  DEBLK_H264DBPAR0_2_inst                                                 0x008A
#define  set_DEBLK_H264DBPAR0_2_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR0_2_reg)=data)
#define  get_DEBLK_H264DBPAR0_2_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR0_2_reg))

#define  DEBLK_H264DBPAR0_3                                                      0x1800EA2C
#define  DEBLK_H264DBPAR0_3_reg_addr                                             "0xB800EA2C"
#define  DEBLK_H264DBPAR0_3_reg                                                  0xB800EA2C
#define  DEBLK_H264DBPAR0_3_inst_addr                                            "0x000B"
#define  DEBLK_H264DBPAR0_3_inst_adr                                             "0x008B"
#define  DEBLK_H264DBPAR0_3_inst                                                 0x008B
#define  set_DEBLK_H264DBPAR0_3_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR0_3_reg)=data)
#define  get_DEBLK_H264DBPAR0_3_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR0_3_reg))

#define  DEBLK_H264DBPAR1_0                                                      0x1800EA30
#define  DEBLK_H264DBPAR1_0_reg_addr                                             "0xB800EA30"
#define  DEBLK_H264DBPAR1_0_reg                                                  0xB800EA30
#define  DEBLK_H264DBPAR1_0_inst_addr                                            "0x000C"
#define  DEBLK_H264DBPAR1_0_inst_adr                                             "0x008C"
#define  DEBLK_H264DBPAR1_0_inst                                                 0x008C
#define  set_DEBLK_H264DBPAR1_0_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR1_0_reg)=data)
#define  get_DEBLK_H264DBPAR1_0_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR1_0_reg))
#define  DEBLK_H264DBPAR1_BS1_valid_ext_shift                                    (24)
#define  DEBLK_H264DBPAR1_Subblkpat_shift                                        (0)
#define  DEBLK_H264DBPAR1_BS1_valid_ext_mask                                     (0x0F000000)
#define  DEBLK_H264DBPAR1_Subblkpat_mask                                         (0x00FFFFFF)
#define  DEBLK_H264DBPAR1_BS1_valid_ext(data)                                    (0x0F000000&((data)<<24))
#define  DEBLK_H264DBPAR1_Subblkpat(data)                                        (0x00FFFFFF&(data))
#define  DEBLK_H264DBPAR1_get_BS1_valid_ext(data)                                ((0x0F000000&(data))>>24)
#define  DEBLK_H264DBPAR1_get_Subblkpat(data)                                    (0x00FFFFFF&(data))
#define  DEBLK_H264DBPAR1_BS1_valid_ext_src(data)                                ((0x0F000000&(data))>>24)
#define  DEBLK_H264DBPAR1_Subblkpat_src(data)                                    (0x00FFFFFF&(data))

#define  DEBLK_H264DBPAR1_1                                                      0x1800EA34
#define  DEBLK_H264DBPAR1_1_reg_addr                                             "0xB800EA34"
#define  DEBLK_H264DBPAR1_1_reg                                                  0xB800EA34
#define  DEBLK_H264DBPAR1_1_inst_addr                                            "0x000D"
#define  DEBLK_H264DBPAR1_1_inst_adr                                             "0x008D"
#define  DEBLK_H264DBPAR1_1_inst                                                 0x008D
#define  set_DEBLK_H264DBPAR1_1_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR1_1_reg)=data)
#define  get_DEBLK_H264DBPAR1_1_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR1_1_reg))

#define  DEBLK_H264DBPAR1_2                                                      0x1800EA38
#define  DEBLK_H264DBPAR1_2_reg_addr                                             "0xB800EA38"
#define  DEBLK_H264DBPAR1_2_reg                                                  0xB800EA38
#define  DEBLK_H264DBPAR1_2_inst_addr                                            "0x000E"
#define  DEBLK_H264DBPAR1_2_inst_adr                                             "0x008E"
#define  DEBLK_H264DBPAR1_2_inst                                                 0x008E
#define  set_DEBLK_H264DBPAR1_2_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR1_2_reg)=data)
#define  get_DEBLK_H264DBPAR1_2_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR1_2_reg))

#define  DEBLK_H264DBPAR1_3                                                      0x1800EA3C
#define  DEBLK_H264DBPAR1_3_reg_addr                                             "0xB800EA3C"
#define  DEBLK_H264DBPAR1_3_reg                                                  0xB800EA3C
#define  DEBLK_H264DBPAR1_3_inst_addr                                            "0x000F"
#define  DEBLK_H264DBPAR1_3_inst_adr                                             "0x008F"
#define  DEBLK_H264DBPAR1_3_inst                                                 0x008F
#define  set_DEBLK_H264DBPAR1_3_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR1_3_reg)=data)
#define  get_DEBLK_H264DBPAR1_3_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR1_3_reg))

#define  DEBLK_H264DBPAR2_0                                                      0x1800EA40
#define  DEBLK_H264DBPAR2_0_reg_addr                                             "0xB800EA40"
#define  DEBLK_H264DBPAR2_0_reg                                                  0xB800EA40
#define  DEBLK_H264DBPAR2_0_inst_addr                                            "0x0010"
#define  DEBLK_H264DBPAR2_0_inst_adr                                             "0x0090"
#define  DEBLK_H264DBPAR2_0_inst                                                 0x0090
#define  set_DEBLK_H264DBPAR2_0_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR2_0_reg)=data)
#define  get_DEBLK_H264DBPAR2_0_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR2_0_reg))
#define  DEBLK_H264DBPAR2_BS1_valid_shift                                        (0)
#define  DEBLK_H264DBPAR2_BS1_valid_mask                                         (0xFFFFFFFF)
#define  DEBLK_H264DBPAR2_BS1_valid(data)                                        (0xFFFFFFFF&(data))
#define  DEBLK_H264DBPAR2_get_BS1_valid(data)                                    (0xFFFFFFFF&(data))
#define  DEBLK_H264DBPAR2_BS1_valid_src(data)                                    (0xFFFFFFFF&(data))

#define  DEBLK_H264DBPAR2_1                                                      0x1800EA44
#define  DEBLK_H264DBPAR2_1_reg_addr                                             "0xB800EA44"
#define  DEBLK_H264DBPAR2_1_reg                                                  0xB800EA44
#define  DEBLK_H264DBPAR2_1_inst_addr                                            "0x0011"
#define  DEBLK_H264DBPAR2_1_inst_adr                                             "0x0091"
#define  DEBLK_H264DBPAR2_1_inst                                                 0x0091
#define  set_DEBLK_H264DBPAR2_1_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR2_1_reg)=data)
#define  get_DEBLK_H264DBPAR2_1_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR2_1_reg))

#define  DEBLK_H264DBPAR2_2                                                      0x1800EA48
#define  DEBLK_H264DBPAR2_2_reg_addr                                             "0xB800EA48"
#define  DEBLK_H264DBPAR2_2_reg                                                  0xB800EA48
#define  DEBLK_H264DBPAR2_2_inst_addr                                            "0x0012"
#define  DEBLK_H264DBPAR2_2_inst_adr                                             "0x0092"
#define  DEBLK_H264DBPAR2_2_inst                                                 0x0092
#define  set_DEBLK_H264DBPAR2_2_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR2_2_reg)=data)
#define  get_DEBLK_H264DBPAR2_2_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR2_2_reg))

#define  DEBLK_H264DBPAR2_3                                                      0x1800EA4C
#define  DEBLK_H264DBPAR2_3_reg_addr                                             "0xB800EA4C"
#define  DEBLK_H264DBPAR2_3_reg                                                  0xB800EA4C
#define  DEBLK_H264DBPAR2_3_inst_addr                                            "0x0013"
#define  DEBLK_H264DBPAR2_3_inst_adr                                             "0x0093"
#define  DEBLK_H264DBPAR2_3_inst                                                 0x0093
#define  set_DEBLK_H264DBPAR2_3_reg(data)                                        (*((volatile unsigned int*)DEBLK_H264DBPAR2_3_reg)=data)
#define  get_DEBLK_H264DBPAR2_3_reg                                              (*((volatile unsigned int*)DEBLK_H264DBPAR2_3_reg))

#define  DEBLK_VC1DBPAR0_0                                                       0x1800EA50
#define  DEBLK_VC1DBPAR0_0_reg_addr                                              "0xB800EA50"
#define  DEBLK_VC1DBPAR0_0_reg                                                   0xB800EA50
#define  DEBLK_VC1DBPAR0_0_inst_addr                                             "0x0014"
#define  DEBLK_VC1DBPAR0_0_inst_adr                                              "0x0094"
#define  DEBLK_VC1DBPAR0_0_inst                                                  0x0094
#define  set_DEBLK_VC1DBPAR0_0_reg(data)                                         (*((volatile unsigned int*)DEBLK_VC1DBPAR0_0_reg)=data)
#define  get_DEBLK_VC1DBPAR0_0_reg                                               (*((volatile unsigned int*)DEBLK_VC1DBPAR0_0_reg))
#define  DEBLK_VC1DBPAR0_Lu_Mv_equal_shift                                       (0)
#define  DEBLK_VC1DBPAR0_Lu_Mv_equal_mask                                        (0xFFFFFFFF)
#define  DEBLK_VC1DBPAR0_Lu_Mv_equal(data)                                       (0xFFFFFFFF&(data))
#define  DEBLK_VC1DBPAR0_get_Lu_Mv_equal(data)                                   (0xFFFFFFFF&(data))
#define  DEBLK_VC1DBPAR0_Lu_Mv_equal_src(data)                                   (0xFFFFFFFF&(data))

#define  DEBLK_VC1DBPAR0_1                                                       0x1800EA54
#define  DEBLK_VC1DBPAR0_1_reg_addr                                              "0xB800EA54"
#define  DEBLK_VC1DBPAR0_1_reg                                                   0xB800EA54
#define  DEBLK_VC1DBPAR0_1_inst_addr                                             "0x0015"
#define  DEBLK_VC1DBPAR0_1_inst_adr                                              "0x0095"
#define  DEBLK_VC1DBPAR0_1_inst                                                  0x0095
#define  set_DEBLK_VC1DBPAR0_1_reg(data)                                         (*((volatile unsigned int*)DEBLK_VC1DBPAR0_1_reg)=data)
#define  get_DEBLK_VC1DBPAR0_1_reg                                               (*((volatile unsigned int*)DEBLK_VC1DBPAR0_1_reg))

#define  DEBLK_VC1DBPAR1_0                                                       0x1800EA58
#define  DEBLK_VC1DBPAR1_0_reg_addr                                              "0xB800EA58"
#define  DEBLK_VC1DBPAR1_0_reg                                                   0xB800EA58
#define  DEBLK_VC1DBPAR1_0_inst_addr                                             "0x0016"
#define  DEBLK_VC1DBPAR1_0_inst_adr                                              "0x0096"
#define  DEBLK_VC1DBPAR1_0_inst                                                  0x0096
#define  set_DEBLK_VC1DBPAR1_0_reg(data)                                         (*((volatile unsigned int*)DEBLK_VC1DBPAR1_0_reg)=data)
#define  get_DEBLK_VC1DBPAR1_0_reg                                               (*((volatile unsigned int*)DEBLK_VC1DBPAR1_0_reg))
#define  DEBLK_VC1DBPAR1_Subblkpat_shift                                         (8)
#define  DEBLK_VC1DBPAR1_ch_mv_equal_shift                                       (0)
#define  DEBLK_VC1DBPAR1_Subblkpat_mask                                          (0xFFFFFF00)
#define  DEBLK_VC1DBPAR1_ch_mv_equal_mask                                        (0x000000FF)
#define  DEBLK_VC1DBPAR1_Subblkpat(data)                                         (0xFFFFFF00&((data)<<8))
#define  DEBLK_VC1DBPAR1_ch_mv_equal(data)                                       (0x000000FF&(data))
#define  DEBLK_VC1DBPAR1_get_Subblkpat(data)                                     ((0xFFFFFF00&(data))>>8)
#define  DEBLK_VC1DBPAR1_get_ch_mv_equal(data)                                   (0x000000FF&(data))
#define  DEBLK_VC1DBPAR1_Subblkpat_src(data)                                     ((0xFFFFFF00&(data))>>8)
#define  DEBLK_VC1DBPAR1_ch_mv_equal_src(data)                                   (0x000000FF&(data))

#define  DEBLK_VC1DBPAR1_1                                                       0x1800EA5C
#define  DEBLK_VC1DBPAR1_1_reg_addr                                              "0xB800EA5C"
#define  DEBLK_VC1DBPAR1_1_reg                                                   0xB800EA5C
#define  DEBLK_VC1DBPAR1_1_inst_addr                                             "0x0017"
#define  DEBLK_VC1DBPAR1_1_inst_adr                                              "0x0097"
#define  DEBLK_VC1DBPAR1_1_inst                                                  0x0097
#define  set_DEBLK_VC1DBPAR1_1_reg(data)                                         (*((volatile unsigned int*)DEBLK_VC1DBPAR1_1_reg)=data)
#define  get_DEBLK_VC1DBPAR1_1_reg                                               (*((volatile unsigned int*)DEBLK_VC1DBPAR1_1_reg))

#define  DEBLK_RVCTRL                                                            0x1800EA60
#define  DEBLK_RVCTRL_reg_addr                                                   "0xB800EA60"
#define  DEBLK_RVCTRL_reg                                                        0xB800EA60
#define  DEBLK_RVCTRL_inst_addr                                                  "0x0018"
#define  DEBLK_RVCTRL_inst_adr                                                   "0x0098"
#define  DEBLK_RVCTRL_inst                                                       0x0098
#define  set_DEBLK_RVCTRL_reg(data)                                              (*((volatile unsigned int*)DEBLK_RVCTRL_reg)=data)
#define  get_DEBLK_RVCTRL_reg                                                    (*((volatile unsigned int*)DEBLK_RVCTRL_reg))
#define  DEBLK_RVCTRL_write_enable3_shift                                        (27)
#define  DEBLK_RVCTRL_RefQP_shift                                                (22)
#define  DEBLK_RVCTRL_Beta2Sel_shift                                             (21)
#define  DEBLK_RVCTRL_write_enable2_shift                                        (20)
#define  DEBLK_RVCTRL_is_key_frame_shift                                         (19)
#define  DEBLK_RVCTRL_chroma_only_shift                                          (18)
#define  DEBLK_RVCTRL_write_enable1_shift                                        (17)
#define  DEBLK_RVCTRL_Sel_s_chroma_deblock_shift                                 (16)
#define  DEBLK_RVCTRL_write_enable0_shift                                        (15)
#define  DEBLK_RVCTRL_STR9_initQP_shift                                          (10)
#define  DEBLK_RVCTRL_STR8_initQP_shift                                          (5)
#define  DEBLK_RVCTRL_STR7_initQP_shift                                          (0)
#define  DEBLK_RVCTRL_write_enable3_mask                                         (0x08000000)
#define  DEBLK_RVCTRL_RefQP_mask                                                 (0x07C00000)
#define  DEBLK_RVCTRL_Beta2Sel_mask                                              (0x00200000)
#define  DEBLK_RVCTRL_write_enable2_mask                                         (0x00100000)
#define  DEBLK_RVCTRL_is_key_frame_mask                                          (0x00080000)
#define  DEBLK_RVCTRL_chroma_only_mask                                           (0x00040000)
#define  DEBLK_RVCTRL_write_enable1_mask                                         (0x00020000)
#define  DEBLK_RVCTRL_Sel_s_chroma_deblock_mask                                  (0x00010000)
#define  DEBLK_RVCTRL_write_enable0_mask                                         (0x00008000)
#define  DEBLK_RVCTRL_STR9_initQP_mask                                           (0x00007C00)
#define  DEBLK_RVCTRL_STR8_initQP_mask                                           (0x000003E0)
#define  DEBLK_RVCTRL_STR7_initQP_mask                                           (0x0000001F)
#define  DEBLK_RVCTRL_write_enable3(data)                                        (0x08000000&((data)<<27))
#define  DEBLK_RVCTRL_RefQP(data)                                                (0x07C00000&((data)<<22))
#define  DEBLK_RVCTRL_Beta2Sel(data)                                             (0x00200000&((data)<<21))
#define  DEBLK_RVCTRL_write_enable2(data)                                        (0x00100000&((data)<<20))
#define  DEBLK_RVCTRL_is_key_frame(data)                                         (0x00080000&((data)<<19))
#define  DEBLK_RVCTRL_chroma_only(data)                                          (0x00040000&((data)<<18))
#define  DEBLK_RVCTRL_write_enable1(data)                                        (0x00020000&((data)<<17))
#define  DEBLK_RVCTRL_Sel_s_chroma_deblock(data)                                 (0x00010000&((data)<<16))
#define  DEBLK_RVCTRL_write_enable0(data)                                        (0x00008000&((data)<<15))
#define  DEBLK_RVCTRL_STR9_initQP(data)                                          (0x00007C00&((data)<<10))
#define  DEBLK_RVCTRL_STR8_initQP(data)                                          (0x000003E0&((data)<<5))
#define  DEBLK_RVCTRL_STR7_initQP(data)                                          (0x0000001F&(data))
#define  DEBLK_RVCTRL_get_write_enable3(data)                                    ((0x08000000&(data))>>27)
#define  DEBLK_RVCTRL_get_RefQP(data)                                            ((0x07C00000&(data))>>22)
#define  DEBLK_RVCTRL_get_Beta2Sel(data)                                         ((0x00200000&(data))>>21)
#define  DEBLK_RVCTRL_get_write_enable2(data)                                    ((0x00100000&(data))>>20)
#define  DEBLK_RVCTRL_get_is_key_frame(data)                                     ((0x00080000&(data))>>19)
#define  DEBLK_RVCTRL_get_chroma_only(data)                                      ((0x00040000&(data))>>18)
#define  DEBLK_RVCTRL_get_write_enable1(data)                                    ((0x00020000&(data))>>17)
#define  DEBLK_RVCTRL_get_Sel_s_chroma_deblock(data)                             ((0x00010000&(data))>>16)
#define  DEBLK_RVCTRL_get_write_enable0(data)                                    ((0x00008000&(data))>>15)
#define  DEBLK_RVCTRL_get_STR9_initQP(data)                                      ((0x00007C00&(data))>>10)
#define  DEBLK_RVCTRL_get_STR8_initQP(data)                                      ((0x000003E0&(data))>>5)
#define  DEBLK_RVCTRL_get_STR7_initQP(data)                                      (0x0000001F&(data))
#define  DEBLK_RVCTRL_write_enable3_src(data)                                    ((0x08000000&(data))>>27)
#define  DEBLK_RVCTRL_RefQP_src(data)                                            ((0x07C00000&(data))>>22)
#define  DEBLK_RVCTRL_Beta2Sel_src(data)                                         ((0x00200000&(data))>>21)
#define  DEBLK_RVCTRL_write_enable2_src(data)                                    ((0x00100000&(data))>>20)
#define  DEBLK_RVCTRL_is_key_frame_src(data)                                     ((0x00080000&(data))>>19)
#define  DEBLK_RVCTRL_chroma_only_src(data)                                      ((0x00040000&(data))>>18)
#define  DEBLK_RVCTRL_write_enable1_src(data)                                    ((0x00020000&(data))>>17)
#define  DEBLK_RVCTRL_Sel_s_chroma_deblock_src(data)                             ((0x00010000&(data))>>16)
#define  DEBLK_RVCTRL_write_enable0_src(data)                                    ((0x00008000&(data))>>15)
#define  DEBLK_RVCTRL_STR9_initQP_src(data)                                      ((0x00007C00&(data))>>10)
#define  DEBLK_RVCTRL_STR8_initQP_src(data)                                      ((0x000003E0&(data))>>5)
#define  DEBLK_RVCTRL_STR7_initQP_src(data)                                      (0x0000001F&(data))

#define  DEBLK_RV8CTRL                                                           0x1800EA64
#define  DEBLK_RV8CTRL_reg_addr                                                  "0xB800EA64"
#define  DEBLK_RV8CTRL_reg                                                       0xB800EA64
#define  DEBLK_RV8CTRL_inst_addr                                                 "0x0019"
#define  DEBLK_RV8CTRL_inst_adr                                                  "0x0099"
#define  DEBLK_RV8CTRL_inst                                                      0x0099
#define  set_DEBLK_RV8CTRL_reg(data)                                             (*((volatile unsigned int*)DEBLK_RV8CTRL_reg)=data)
#define  get_DEBLK_RV8CTRL_reg                                                   (*((volatile unsigned int*)DEBLK_RV8CTRL_reg))
#define  DEBLK_RV8CTRL_STR6_initQP_shift                                         (25)
#define  DEBLK_RV8CTRL_STR5_initQP_shift                                         (20)
#define  DEBLK_RV8CTRL_STR4_initQP_shift                                         (15)
#define  DEBLK_RV8CTRL_STR3_initQP_shift                                         (10)
#define  DEBLK_RV8CTRL_STR2_initQP_shift                                         (5)
#define  DEBLK_RV8CTRL_STR1_initQP_shift                                         (0)
#define  DEBLK_RV8CTRL_STR6_initQP_mask                                          (0x3E000000)
#define  DEBLK_RV8CTRL_STR5_initQP_mask                                          (0x01F00000)
#define  DEBLK_RV8CTRL_STR4_initQP_mask                                          (0x000F8000)
#define  DEBLK_RV8CTRL_STR3_initQP_mask                                          (0x00007C00)
#define  DEBLK_RV8CTRL_STR2_initQP_mask                                          (0x000003E0)
#define  DEBLK_RV8CTRL_STR1_initQP_mask                                          (0x0000001F)
#define  DEBLK_RV8CTRL_STR6_initQP(data)                                         (0x3E000000&((data)<<25))
#define  DEBLK_RV8CTRL_STR5_initQP(data)                                         (0x01F00000&((data)<<20))
#define  DEBLK_RV8CTRL_STR4_initQP(data)                                         (0x000F8000&((data)<<15))
#define  DEBLK_RV8CTRL_STR3_initQP(data)                                         (0x00007C00&((data)<<10))
#define  DEBLK_RV8CTRL_STR2_initQP(data)                                         (0x000003E0&((data)<<5))
#define  DEBLK_RV8CTRL_STR1_initQP(data)                                         (0x0000001F&(data))
#define  DEBLK_RV8CTRL_get_STR6_initQP(data)                                     ((0x3E000000&(data))>>25)
#define  DEBLK_RV8CTRL_get_STR5_initQP(data)                                     ((0x01F00000&(data))>>20)
#define  DEBLK_RV8CTRL_get_STR4_initQP(data)                                     ((0x000F8000&(data))>>15)
#define  DEBLK_RV8CTRL_get_STR3_initQP(data)                                     ((0x00007C00&(data))>>10)
#define  DEBLK_RV8CTRL_get_STR2_initQP(data)                                     ((0x000003E0&(data))>>5)
#define  DEBLK_RV8CTRL_get_STR1_initQP(data)                                     (0x0000001F&(data))
#define  DEBLK_RV8CTRL_STR6_initQP_src(data)                                     ((0x3E000000&(data))>>25)
#define  DEBLK_RV8CTRL_STR5_initQP_src(data)                                     ((0x01F00000&(data))>>20)
#define  DEBLK_RV8CTRL_STR4_initQP_src(data)                                     ((0x000F8000&(data))>>15)
#define  DEBLK_RV8CTRL_STR3_initQP_src(data)                                     ((0x00007C00&(data))>>10)
#define  DEBLK_RV8CTRL_STR2_initQP_src(data)                                     ((0x000003E0&(data))>>5)
#define  DEBLK_RV8CTRL_STR1_initQP_src(data)                                     (0x0000001F&(data))

#define  DEBLK_RVDBPAR0_0                                                        0x1800EA68
#define  DEBLK_RVDBPAR0_0_reg_addr                                               "0xB800EA68"
#define  DEBLK_RVDBPAR0_0_reg                                                    0xB800EA68
#define  DEBLK_RVDBPAR0_0_inst_addr                                              "0x001A"
#define  DEBLK_RVDBPAR0_0_inst_adr                                               "0x009A"
#define  DEBLK_RVDBPAR0_0_inst                                                   0x009A
#define  set_DEBLK_RVDBPAR0_0_reg(data)                                          (*((volatile unsigned int*)DEBLK_RVDBPAR0_0_reg)=data)
#define  get_DEBLK_RVDBPAR0_0_reg                                                (*((volatile unsigned int*)DEBLK_RVDBPAR0_0_reg))
#define  DEBLK_RVDBPAR0_mvd_shift                                                (5)
#define  DEBLK_RVDBPAR0_QP_shift                                                 (0)
#define  DEBLK_RVDBPAR0_mvd_mask                                                 (0x001FFFE0)
#define  DEBLK_RVDBPAR0_QP_mask                                                  (0x0000001F)
#define  DEBLK_RVDBPAR0_mvd(data)                                                (0x001FFFE0&((data)<<5))
#define  DEBLK_RVDBPAR0_QP(data)                                                 (0x0000001F&(data))
#define  DEBLK_RVDBPAR0_get_mvd(data)                                            ((0x001FFFE0&(data))>>5)
#define  DEBLK_RVDBPAR0_get_QP(data)                                             (0x0000001F&(data))
#define  DEBLK_RVDBPAR0_mvd_src(data)                                            ((0x001FFFE0&(data))>>5)
#define  DEBLK_RVDBPAR0_QP_src(data)                                             (0x0000001F&(data))

#define  DEBLK_RVDBPAR0_1                                                        0x1800EA6C
#define  DEBLK_RVDBPAR0_1_reg_addr                                               "0xB800EA6C"
#define  DEBLK_RVDBPAR0_1_reg                                                    0xB800EA6C
#define  DEBLK_RVDBPAR0_1_inst_addr                                              "0x001B"
#define  DEBLK_RVDBPAR0_1_inst_adr                                               "0x009B"
#define  DEBLK_RVDBPAR0_1_inst                                                   0x009B
#define  set_DEBLK_RVDBPAR0_1_reg(data)                                          (*((volatile unsigned int*)DEBLK_RVDBPAR0_1_reg)=data)
#define  get_DEBLK_RVDBPAR0_1_reg                                                (*((volatile unsigned int*)DEBLK_RVDBPAR0_1_reg))

#define  DEBLK_RVDBPAR1                                                          0x1800EA70
#define  DEBLK_RVDBPAR1_reg_addr                                                 "0xB800EA70"
#define  DEBLK_RVDBPAR1_reg                                                      0xB800EA70
#define  DEBLK_RVDBPAR1_inst_addr                                                "0x001C"
#define  DEBLK_RVDBPAR1_inst_adr                                                 "0x009C"
#define  DEBLK_RVDBPAR1_inst                                                     0x009C
#define  set_DEBLK_RVDBPAR1_reg(data)                                            (*((volatile unsigned int*)DEBLK_RVDBPAR1_reg)=data)
#define  get_DEBLK_RVDBPAR1_reg                                                  (*((volatile unsigned int*)DEBLK_RVDBPAR1_reg))
#define  DEBLK_RVDBPAR1_up_mvd_mod_shift                                         (13)
#define  DEBLK_RVDBPAR1_left_mvd_mod_shift                                       (9)
#define  DEBLK_RVDBPAR1_Ul_str_eq2_shift                                         (8)
#define  DEBLK_RVDBPAR1_Up_str_eq2_shift                                         (7)
#define  DEBLK_RVDBPAR1_Left_str_eq2_shift                                       (6)
#define  DEBLK_RVDBPAR1_Cur_str_eq2_shift                                        (5)
#define  DEBLK_RVDBPAR1_up_ul_refdiff_shift                                      (4)
#define  DEBLK_RVDBPAR1_left_ul_refdiff_shift                                    (3)
#define  DEBLK_RVDBPAR1_cur_l_refdiff_shift                                      (2)
#define  DEBLK_RVDBPAR1_cur_up_refdiff_shift                                     (1)
#define  DEBLK_RVDBPAR1_up_cur_refdiff_shift                                     (0)
#define  DEBLK_RVDBPAR1_up_mvd_mod_mask                                          (0x0001E000)
#define  DEBLK_RVDBPAR1_left_mvd_mod_mask                                        (0x00001E00)
#define  DEBLK_RVDBPAR1_Ul_str_eq2_mask                                          (0x00000100)
#define  DEBLK_RVDBPAR1_Up_str_eq2_mask                                          (0x00000080)
#define  DEBLK_RVDBPAR1_Left_str_eq2_mask                                        (0x00000040)
#define  DEBLK_RVDBPAR1_Cur_str_eq2_mask                                         (0x00000020)
#define  DEBLK_RVDBPAR1_up_ul_refdiff_mask                                       (0x00000010)
#define  DEBLK_RVDBPAR1_left_ul_refdiff_mask                                     (0x00000008)
#define  DEBLK_RVDBPAR1_cur_l_refdiff_mask                                       (0x00000004)
#define  DEBLK_RVDBPAR1_cur_up_refdiff_mask                                      (0x00000002)
#define  DEBLK_RVDBPAR1_up_cur_refdiff_mask                                      (0x00000001)
#define  DEBLK_RVDBPAR1_up_mvd_mod(data)                                         (0x0001E000&((data)<<13))
#define  DEBLK_RVDBPAR1_left_mvd_mod(data)                                       (0x00001E00&((data)<<9))
#define  DEBLK_RVDBPAR1_Ul_str_eq2(data)                                         (0x00000100&((data)<<8))
#define  DEBLK_RVDBPAR1_Up_str_eq2(data)                                         (0x00000080&((data)<<7))
#define  DEBLK_RVDBPAR1_Left_str_eq2(data)                                       (0x00000040&((data)<<6))
#define  DEBLK_RVDBPAR1_Cur_str_eq2(data)                                        (0x00000020&((data)<<5))
#define  DEBLK_RVDBPAR1_up_ul_refdiff(data)                                      (0x00000010&((data)<<4))
#define  DEBLK_RVDBPAR1_left_ul_refdiff(data)                                    (0x00000008&((data)<<3))
#define  DEBLK_RVDBPAR1_cur_l_refdiff(data)                                      (0x00000004&((data)<<2))
#define  DEBLK_RVDBPAR1_cur_up_refdiff(data)                                     (0x00000002&((data)<<1))
#define  DEBLK_RVDBPAR1_up_cur_refdiff(data)                                     (0x00000001&(data))
#define  DEBLK_RVDBPAR1_get_up_mvd_mod(data)                                     ((0x0001E000&(data))>>13)
#define  DEBLK_RVDBPAR1_get_left_mvd_mod(data)                                   ((0x00001E00&(data))>>9)
#define  DEBLK_RVDBPAR1_get_Ul_str_eq2(data)                                     ((0x00000100&(data))>>8)
#define  DEBLK_RVDBPAR1_get_Up_str_eq2(data)                                     ((0x00000080&(data))>>7)
#define  DEBLK_RVDBPAR1_get_Left_str_eq2(data)                                   ((0x00000040&(data))>>6)
#define  DEBLK_RVDBPAR1_get_Cur_str_eq2(data)                                    ((0x00000020&(data))>>5)
#define  DEBLK_RVDBPAR1_get_up_ul_refdiff(data)                                  ((0x00000010&(data))>>4)
#define  DEBLK_RVDBPAR1_get_left_ul_refdiff(data)                                ((0x00000008&(data))>>3)
#define  DEBLK_RVDBPAR1_get_cur_l_refdiff(data)                                  ((0x00000004&(data))>>2)
#define  DEBLK_RVDBPAR1_get_cur_up_refdiff(data)                                 ((0x00000002&(data))>>1)
#define  DEBLK_RVDBPAR1_get_up_cur_refdiff(data)                                 (0x00000001&(data))
#define  DEBLK_RVDBPAR1_up_mvd_mod_src(data)                                     ((0x0001E000&(data))>>13)
#define  DEBLK_RVDBPAR1_left_mvd_mod_src(data)                                   ((0x00001E00&(data))>>9)
#define  DEBLK_RVDBPAR1_Ul_str_eq2_src(data)                                     ((0x00000100&(data))>>8)
#define  DEBLK_RVDBPAR1_Up_str_eq2_src(data)                                     ((0x00000080&(data))>>7)
#define  DEBLK_RVDBPAR1_Left_str_eq2_src(data)                                   ((0x00000040&(data))>>6)
#define  DEBLK_RVDBPAR1_Cur_str_eq2_src(data)                                    ((0x00000020&(data))>>5)
#define  DEBLK_RVDBPAR1_up_ul_refdiff_src(data)                                  ((0x00000010&(data))>>4)
#define  DEBLK_RVDBPAR1_left_ul_refdiff_src(data)                                ((0x00000008&(data))>>3)
#define  DEBLK_RVDBPAR1_cur_l_refdiff_src(data)                                  ((0x00000004&(data))>>2)
#define  DEBLK_RVDBPAR1_cur_up_refdiff_src(data)                                 ((0x00000002&(data))>>1)
#define  DEBLK_RVDBPAR1_up_cur_refdiff_src(data)                                 (0x00000001&(data))

#define  DEBLK_RV9CLIP                                                           0x1800EA74
#define  DEBLK_RV9CLIP_reg_addr                                                  "0xB800EA74"
#define  DEBLK_RV9CLIP_reg                                                       0xB800EA74
#define  DEBLK_RV9CLIP_inst_addr                                                 "0x001D"
#define  DEBLK_RV9CLIP_inst_adr                                                  "0x009D"
#define  DEBLK_RV9CLIP_inst                                                      0x009D
#define  set_DEBLK_RV9CLIP_reg(data)                                             (*((volatile unsigned int*)DEBLK_RV9CLIP_reg)=data)
#define  get_DEBLK_RV9CLIP_reg                                                   (*((volatile unsigned int*)DEBLK_RV9CLIP_reg))
#define  DEBLK_RV9CLIP_Subblk2Clip_ch_shift                                      (1)
#define  DEBLK_RV9CLIP_Subblk12Clip_lu_shift                                     (0)
#define  DEBLK_RV9CLIP_Subblk2Clip_ch_mask                                       (0x00000002)
#define  DEBLK_RV9CLIP_Subblk12Clip_lu_mask                                      (0x00000001)
#define  DEBLK_RV9CLIP_Subblk2Clip_ch(data)                                      (0x00000002&((data)<<1))
#define  DEBLK_RV9CLIP_Subblk12Clip_lu(data)                                     (0x00000001&(data))
#define  DEBLK_RV9CLIP_get_Subblk2Clip_ch(data)                                  ((0x00000002&(data))>>1)
#define  DEBLK_RV9CLIP_get_Subblk12Clip_lu(data)                                 (0x00000001&(data))
#define  DEBLK_RV9CLIP_Subblk2Clip_ch_src(data)                                  ((0x00000002&(data))>>1)
#define  DEBLK_RV9CLIP_Subblk12Clip_lu_src(data)                                 (0x00000001&(data))

#define  DEBLK_WMV8DBPAR_0                                                       0x1800EA78
#define  DEBLK_WMV8DBPAR_0_reg_addr                                              "0xB800EA78"
#define  DEBLK_WMV8DBPAR_0_reg                                                   0xB800EA78
#define  DEBLK_WMV8DBPAR_0_inst_addr                                             "0x001E"
#define  DEBLK_WMV8DBPAR_0_inst_adr                                              "0x009E"
#define  DEBLK_WMV8DBPAR_0_inst                                                  0x009E
#define  set_DEBLK_WMV8DBPAR_0_reg(data)                                         (*((volatile unsigned int*)DEBLK_WMV8DBPAR_0_reg)=data)
#define  get_DEBLK_WMV8DBPAR_0_reg                                               (*((volatile unsigned int*)DEBLK_WMV8DBPAR_0_reg))
#define  DEBLK_WMV8DBPAR_is_skip_shift                                           (10)
#define  DEBLK_WMV8DBPAR_Qpch_shift                                              (5)
#define  DEBLK_WMV8DBPAR_Qpy_shift                                               (0)
#define  DEBLK_WMV8DBPAR_is_skip_mask                                            (0x00000400)
#define  DEBLK_WMV8DBPAR_Qpch_mask                                               (0x000003E0)
#define  DEBLK_WMV8DBPAR_Qpy_mask                                                (0x0000001F)
#define  DEBLK_WMV8DBPAR_is_skip(data)                                           (0x00000400&((data)<<10))
#define  DEBLK_WMV8DBPAR_Qpch(data)                                              (0x000003E0&((data)<<5))
#define  DEBLK_WMV8DBPAR_Qpy(data)                                               (0x0000001F&(data))
#define  DEBLK_WMV8DBPAR_get_is_skip(data)                                       ((0x00000400&(data))>>10)
#define  DEBLK_WMV8DBPAR_get_Qpch(data)                                          ((0x000003E0&(data))>>5)
#define  DEBLK_WMV8DBPAR_get_Qpy(data)                                           (0x0000001F&(data))
#define  DEBLK_WMV8DBPAR_is_skip_src(data)                                       ((0x00000400&(data))>>10)
#define  DEBLK_WMV8DBPAR_Qpch_src(data)                                          ((0x000003E0&(data))>>5)
#define  DEBLK_WMV8DBPAR_Qpy_src(data)                                           (0x0000001F&(data))

#define  DEBLK_WMV8DBPAR_1                                                       0x1800EA7C
#define  DEBLK_WMV8DBPAR_1_reg_addr                                              "0xB800EA7C"
#define  DEBLK_WMV8DBPAR_1_reg                                                   0xB800EA7C
#define  DEBLK_WMV8DBPAR_1_inst_addr                                             "0x001F"
#define  DEBLK_WMV8DBPAR_1_inst_adr                                              "0x009F"
#define  DEBLK_WMV8DBPAR_1_inst                                                  0x009F
#define  set_DEBLK_WMV8DBPAR_1_reg(data)                                         (*((volatile unsigned int*)DEBLK_WMV8DBPAR_1_reg)=data)
#define  get_DEBLK_WMV8DBPAR_1_reg                                               (*((volatile unsigned int*)DEBLK_WMV8DBPAR_1_reg))

#define  DEBLK_VMADRBA                                                           0x1800EA80
#define  DEBLK_VMADRBA_reg_addr                                                  "0xB800EA80"
#define  DEBLK_VMADRBA_reg                                                       0xB800EA80
#define  DEBLK_VMADRBA_inst_addr                                                 "0x0020"
#define  DEBLK_VMADRBA_inst_adr                                                  "0x00A0"
#define  DEBLK_VMADRBA_inst                                                      0x00A0
#define  set_DEBLK_VMADRBA_reg(data)                                             (*((volatile unsigned int*)DEBLK_VMADRBA_reg)=data)
#define  get_DEBLK_VMADRBA_reg                                                   (*((volatile unsigned int*)DEBLK_VMADRBA_reg))
#define  DEBLK_VMADRBA_BaseA0_shift                                              (7)
#define  DEBLK_VMADRBA_BaseA1_shift                                              (0)
#define  DEBLK_VMADRBA_BaseA0_mask                                               (0x00003F80)
#define  DEBLK_VMADRBA_BaseA1_mask                                               (0x0000007F)
#define  DEBLK_VMADRBA_BaseA0(data)                                              (0x00003F80&((data)<<7))
#define  DEBLK_VMADRBA_BaseA1(data)                                              (0x0000007F&(data))
#define  DEBLK_VMADRBA_get_BaseA0(data)                                          ((0x00003F80&(data))>>7)
#define  DEBLK_VMADRBA_get_BaseA1(data)                                          (0x0000007F&(data))
#define  DEBLK_VMADRBA_BaseA0_src(data)                                          ((0x00003F80&(data))>>7)
#define  DEBLK_VMADRBA_BaseA1_src(data)                                          (0x0000007F&(data))

#define  DEBLK_VMADROA                                                           0x1800EA84
#define  DEBLK_VMADROA_reg_addr                                                  "0xB800EA84"
#define  DEBLK_VMADROA_reg                                                       0xB800EA84
#define  DEBLK_VMADROA_inst_addr                                                 "0x0021"
#define  DEBLK_VMADROA_inst_adr                                                  "0x00A1"
#define  DEBLK_VMADROA_inst                                                      0x00A1
#define  set_DEBLK_VMADROA_reg(data)                                             (*((volatile unsigned int*)DEBLK_VMADROA_reg)=data)
#define  get_DEBLK_VMADROA_reg                                                   (*((volatile unsigned int*)DEBLK_VMADROA_reg))
#define  DEBLK_VMADROA_OffsetA0_shift                                            (14)
#define  DEBLK_VMADROA_OffsetA1_shift                                            (7)
#define  DEBLK_VMADROA_OffsetA2_shift                                            (0)
#define  DEBLK_VMADROA_OffsetA0_mask                                             (0x001FC000)
#define  DEBLK_VMADROA_OffsetA1_mask                                             (0x00003F80)
#define  DEBLK_VMADROA_OffsetA2_mask                                             (0x0000007F)
#define  DEBLK_VMADROA_OffsetA0(data)                                            (0x001FC000&((data)<<14))
#define  DEBLK_VMADROA_OffsetA1(data)                                            (0x00003F80&((data)<<7))
#define  DEBLK_VMADROA_OffsetA2(data)                                            (0x0000007F&(data))
#define  DEBLK_VMADROA_get_OffsetA0(data)                                        ((0x001FC000&(data))>>14)
#define  DEBLK_VMADROA_get_OffsetA1(data)                                        ((0x00003F80&(data))>>7)
#define  DEBLK_VMADROA_get_OffsetA2(data)                                        (0x0000007F&(data))
#define  DEBLK_VMADROA_OffsetA0_src(data)                                        ((0x001FC000&(data))>>14)
#define  DEBLK_VMADROA_OffsetA1_src(data)                                        ((0x00003F80&(data))>>7)
#define  DEBLK_VMADROA_OffsetA2_src(data)                                        (0x0000007F&(data))

#define  DEBLK_DEBSBCTL                                                          0x1800EA88
#define  DEBLK_DEBSBCTL_reg_addr                                                 "0xB800EA88"
#define  DEBLK_DEBSBCTL_reg                                                      0xB800EA88
#define  DEBLK_DEBSBCTL_inst_addr                                                "0x0022"
#define  DEBLK_DEBSBCTL_inst_adr                                                 "0x00A2"
#define  DEBLK_DEBSBCTL_inst                                                     0x00A2
#define  set_DEBLK_DEBSBCTL_reg(data)                                            (*((volatile unsigned int*)DEBLK_DEBSBCTL_reg)=data)
#define  get_DEBLK_DEBSBCTL_reg                                                  (*((volatile unsigned int*)DEBLK_DEBSBCTL_reg))
#define  DEBLK_DEBSBCTL_mb_case_dbg_en_shift                                     (8)
#define  DEBLK_DEBSBCTL_mb_case_dbg_shift                                        (4)
#define  DEBLK_DEBSBCTL_Sb_load_disable_shift                                    (0)
#define  DEBLK_DEBSBCTL_mb_case_dbg_en_mask                                      (0x00000100)
#define  DEBLK_DEBSBCTL_mb_case_dbg_mask                                         (0x000000F0)
#define  DEBLK_DEBSBCTL_Sb_load_disable_mask                                     (0x00000007)
#define  DEBLK_DEBSBCTL_mb_case_dbg_en(data)                                     (0x00000100&((data)<<8))
#define  DEBLK_DEBSBCTL_mb_case_dbg(data)                                        (0x000000F0&((data)<<4))
#define  DEBLK_DEBSBCTL_Sb_load_disable(data)                                    (0x00000007&(data))
#define  DEBLK_DEBSBCTL_get_mb_case_dbg_en(data)                                 ((0x00000100&(data))>>8)
#define  DEBLK_DEBSBCTL_get_mb_case_dbg(data)                                    ((0x000000F0&(data))>>4)
#define  DEBLK_DEBSBCTL_get_Sb_load_disable(data)                                (0x00000007&(data))
#define  DEBLK_DEBSBCTL_mb_case_dbg_en_src(data)                                 ((0x00000100&(data))>>8)
#define  DEBLK_DEBSBCTL_mb_case_dbg_src(data)                                    ((0x000000F0&(data))>>4)
#define  DEBLK_DEBSBCTL_Sb_load_disable_src(data)                                (0x00000007&(data))

#define  DEBLK_DMACTRL                                                           0x1800EA8C
#define  DEBLK_DMACTRL_reg_addr                                                  "0xB800EA8C"
#define  DEBLK_DMACTRL_reg                                                       0xB800EA8C
#define  DEBLK_DMACTRL_inst_addr                                                 "0x0023"
#define  DEBLK_DMACTRL_inst_adr                                                  "0x00A3"
#define  DEBLK_DMACTRL_inst                                                      0x00A3
#define  set_DEBLK_DMACTRL_reg(data)                                             (*((volatile unsigned int*)DEBLK_DMACTRL_reg)=data)
#define  get_DEBLK_DMACTRL_reg                                                   (*((volatile unsigned int*)DEBLK_DMACTRL_reg))
#define  DEBLK_DMACTRL_dual_issue_disable_shift                                  (6)
#define  DEBLK_DMACTRL_bot_sb_st_disable_shift                                   (5)
#define  DEBLK_DMACTRL_post_write_disable_shift                                  (4)
#define  DEBLK_DMACTRL_dma_idle_shift                                            (3)
#define  DEBLK_DMACTRL_go_shift                                                  (2)
#define  DEBLK_DMACTRL_klm_addr_update_shift                                     (1)
#define  DEBLK_DMACTRL_km_addr_update_shift                                      (0)
#define  DEBLK_DMACTRL_dual_issue_disable_mask                                   (0x00000040)
#define  DEBLK_DMACTRL_bot_sb_st_disable_mask                                    (0x00000020)
#define  DEBLK_DMACTRL_post_write_disable_mask                                   (0x00000010)
#define  DEBLK_DMACTRL_dma_idle_mask                                             (0x00000008)
#define  DEBLK_DMACTRL_go_mask                                                   (0x00000004)
#define  DEBLK_DMACTRL_klm_addr_update_mask                                      (0x00000002)
#define  DEBLK_DMACTRL_km_addr_update_mask                                       (0x00000001)
#define  DEBLK_DMACTRL_dual_issue_disable(data)                                  (0x00000040&((data)<<6))
#define  DEBLK_DMACTRL_bot_sb_st_disable(data)                                   (0x00000020&((data)<<5))
#define  DEBLK_DMACTRL_post_write_disable(data)                                  (0x00000010&((data)<<4))
#define  DEBLK_DMACTRL_dma_idle(data)                                            (0x00000008&((data)<<3))
#define  DEBLK_DMACTRL_go(data)                                                  (0x00000004&((data)<<2))
#define  DEBLK_DMACTRL_klm_addr_update(data)                                     (0x00000002&((data)<<1))
#define  DEBLK_DMACTRL_km_addr_update(data)                                      (0x00000001&(data))
#define  DEBLK_DMACTRL_get_dual_issue_disable(data)                              ((0x00000040&(data))>>6)
#define  DEBLK_DMACTRL_get_bot_sb_st_disable(data)                               ((0x00000020&(data))>>5)
#define  DEBLK_DMACTRL_get_post_write_disable(data)                              ((0x00000010&(data))>>4)
#define  DEBLK_DMACTRL_get_dma_idle(data)                                        ((0x00000008&(data))>>3)
#define  DEBLK_DMACTRL_get_go(data)                                              ((0x00000004&(data))>>2)
#define  DEBLK_DMACTRL_get_klm_addr_update(data)                                 ((0x00000002&(data))>>1)
#define  DEBLK_DMACTRL_get_km_addr_update(data)                                  (0x00000001&(data))
#define  DEBLK_DMACTRL_dual_issue_disable_src(data)                              ((0x00000040&(data))>>6)
#define  DEBLK_DMACTRL_bot_sb_st_disable_src(data)                               ((0x00000020&(data))>>5)
#define  DEBLK_DMACTRL_post_write_disable_src(data)                              ((0x00000010&(data))>>4)
#define  DEBLK_DMACTRL_dma_idle_src(data)                                        ((0x00000008&(data))>>3)
#define  DEBLK_DMACTRL_go_src(data)                                              ((0x00000004&(data))>>2)
#define  DEBLK_DMACTRL_klm_addr_update_src(data)                                 ((0x00000002&(data))>>1)
#define  DEBLK_DMACTRL_km_addr_update_src(data)                                  (0x00000001&(data))

#define  DEBLK_DMALU                                                             0x1800EA90
#define  DEBLK_DMALU_reg_addr                                                    "0xB800EA90"
#define  DEBLK_DMALU_reg                                                         0xB800EA90
#define  DEBLK_DMALU_inst_addr                                                   "0x0024"
#define  DEBLK_DMALU_inst_adr                                                    "0x00A4"
#define  DEBLK_DMALU_inst                                                        0x00A4
#define  set_DEBLK_DMALU_reg(data)                                               (*((volatile unsigned int*)DEBLK_DMALU_reg)=data)
#define  get_DEBLK_DMALU_reg                                                     (*((volatile unsigned int*)DEBLK_DMALU_reg))
#define  DEBLK_DMALU_lu_addr_idx_shift                                           (25)
#define  DEBLK_DMALU_klm_lu_x_sel_shift                                          (24)
#define  DEBLK_DMALU_klm_lu_top_row_inc_shift                                    (18)
#define  DEBLK_DMALU_klm_lu_inc_shift                                            (12)
#define  DEBLK_DMALU_km_lu_mb_offset_shift                                       (6)
#define  DEBLK_DMALU_km_lu_row_offset_shift                                      (0)
#define  DEBLK_DMALU_lu_addr_idx_mask                                            (0xFE000000)
#define  DEBLK_DMALU_klm_lu_x_sel_mask                                           (0x01000000)
#define  DEBLK_DMALU_klm_lu_top_row_inc_mask                                     (0x00FC0000)
#define  DEBLK_DMALU_klm_lu_inc_mask                                             (0x0003F000)
#define  DEBLK_DMALU_km_lu_mb_offset_mask                                        (0x00000FC0)
#define  DEBLK_DMALU_km_lu_row_offset_mask                                       (0x0000003F)
#define  DEBLK_DMALU_lu_addr_idx(data)                                           (0xFE000000&((data)<<25))
#define  DEBLK_DMALU_klm_lu_x_sel(data)                                          (0x01000000&((data)<<24))
#define  DEBLK_DMALU_klm_lu_top_row_inc(data)                                    (0x00FC0000&((data)<<18))
#define  DEBLK_DMALU_klm_lu_inc(data)                                            (0x0003F000&((data)<<12))
#define  DEBLK_DMALU_km_lu_mb_offset(data)                                       (0x00000FC0&((data)<<6))
#define  DEBLK_DMALU_km_lu_row_offset(data)                                      (0x0000003F&(data))
#define  DEBLK_DMALU_get_lu_addr_idx(data)                                       ((0xFE000000&(data))>>25)
#define  DEBLK_DMALU_get_klm_lu_x_sel(data)                                      ((0x01000000&(data))>>24)
#define  DEBLK_DMALU_get_klm_lu_top_row_inc(data)                                ((0x00FC0000&(data))>>18)
#define  DEBLK_DMALU_get_klm_lu_inc(data)                                        ((0x0003F000&(data))>>12)
#define  DEBLK_DMALU_get_km_lu_mb_offset(data)                                   ((0x00000FC0&(data))>>6)
#define  DEBLK_DMALU_get_km_lu_row_offset(data)                                  (0x0000003F&(data))
#define  DEBLK_DMALU_lu_addr_idx_src(data)                                       ((0xFE000000&(data))>>25)
#define  DEBLK_DMALU_klm_lu_x_sel_src(data)                                      ((0x01000000&(data))>>24)
#define  DEBLK_DMALU_klm_lu_top_row_inc_src(data)                                ((0x00FC0000&(data))>>18)
#define  DEBLK_DMALU_klm_lu_inc_src(data)                                        ((0x0003F000&(data))>>12)
#define  DEBLK_DMALU_km_lu_mb_offset_src(data)                                   ((0x00000FC0&(data))>>6)
#define  DEBLK_DMALU_km_lu_row_offset_src(data)                                  (0x0000003F&(data))

#define  DEBLK_DMACH                                                             0x1800EA94
#define  DEBLK_DMACH_reg_addr                                                    "0xB800EA94"
#define  DEBLK_DMACH_reg                                                         0xB800EA94
#define  DEBLK_DMACH_inst_addr                                                   "0x0025"
#define  DEBLK_DMACH_inst_adr                                                    "0x00A5"
#define  DEBLK_DMACH_inst                                                        0x00A5
#define  set_DEBLK_DMACH_reg(data)                                               (*((volatile unsigned int*)DEBLK_DMACH_reg)=data)
#define  get_DEBLK_DMACH_reg                                                     (*((volatile unsigned int*)DEBLK_DMACH_reg))
#define  DEBLK_DMACH_ch_addr_idx_shift                                           (25)
#define  DEBLK_DMACH_klm_ch_x_sel_shift                                          (24)
#define  DEBLK_DMACH_klm_ch_top_row_inc_shift                                    (18)
#define  DEBLK_DMACH_klm_ch_inc_shift                                            (12)
#define  DEBLK_DMACH_km_ch_mb_offset_shift                                       (6)
#define  DEBLK_DMACH_km_ch_row_offset_shift                                      (0)
#define  DEBLK_DMACH_ch_addr_idx_mask                                            (0xFE000000)
#define  DEBLK_DMACH_klm_ch_x_sel_mask                                           (0x01000000)
#define  DEBLK_DMACH_klm_ch_top_row_inc_mask                                     (0x00FC0000)
#define  DEBLK_DMACH_klm_ch_inc_mask                                             (0x0003F000)
#define  DEBLK_DMACH_km_ch_mb_offset_mask                                        (0x00000FC0)
#define  DEBLK_DMACH_km_ch_row_offset_mask                                       (0x0000003F)
#define  DEBLK_DMACH_ch_addr_idx(data)                                           (0xFE000000&((data)<<25))
#define  DEBLK_DMACH_klm_ch_x_sel(data)                                          (0x01000000&((data)<<24))
#define  DEBLK_DMACH_klm_ch_top_row_inc(data)                                    (0x00FC0000&((data)<<18))
#define  DEBLK_DMACH_klm_ch_inc(data)                                            (0x0003F000&((data)<<12))
#define  DEBLK_DMACH_km_ch_mb_offset(data)                                       (0x00000FC0&((data)<<6))
#define  DEBLK_DMACH_km_ch_row_offset(data)                                      (0x0000003F&(data))
#define  DEBLK_DMACH_get_ch_addr_idx(data)                                       ((0xFE000000&(data))>>25)
#define  DEBLK_DMACH_get_klm_ch_x_sel(data)                                      ((0x01000000&(data))>>24)
#define  DEBLK_DMACH_get_klm_ch_top_row_inc(data)                                ((0x00FC0000&(data))>>18)
#define  DEBLK_DMACH_get_klm_ch_inc(data)                                        ((0x0003F000&(data))>>12)
#define  DEBLK_DMACH_get_km_ch_mb_offset(data)                                   ((0x00000FC0&(data))>>6)
#define  DEBLK_DMACH_get_km_ch_row_offset(data)                                  (0x0000003F&(data))
#define  DEBLK_DMACH_ch_addr_idx_src(data)                                       ((0xFE000000&(data))>>25)
#define  DEBLK_DMACH_klm_ch_x_sel_src(data)                                      ((0x01000000&(data))>>24)
#define  DEBLK_DMACH_klm_ch_top_row_inc_src(data)                                ((0x00FC0000&(data))>>18)
#define  DEBLK_DMACH_klm_ch_inc_src(data)                                        ((0x0003F000&(data))>>12)
#define  DEBLK_DMACH_km_ch_mb_offset_src(data)                                   ((0x00000FC0&(data))>>6)
#define  DEBLK_DMACH_km_ch_row_offset_src(data)                                  (0x0000003F&(data))

#define  DEBLK_DMAWH                                                             0x1800EA98
#define  DEBLK_DMAWH_reg_addr                                                    "0xB800EA98"
#define  DEBLK_DMAWH_reg                                                         0xB800EA98
#define  DEBLK_DMAWH_inst_addr                                                   "0x0026"
#define  DEBLK_DMAWH_inst_adr                                                    "0x00A6"
#define  DEBLK_DMAWH_inst                                                        0x00A6
#define  set_DEBLK_DMAWH_reg(data)                                               (*((volatile unsigned int*)DEBLK_DMAWH_reg)=data)
#define  get_DEBLK_DMAWH_reg                                                     (*((volatile unsigned int*)DEBLK_DMAWH_reg))
#define  DEBLK_DMAWH_klm_ch_h_shift                                              (19)
#define  DEBLK_DMAWH_klm_ch_w_shift                                              (18)
#define  DEBLK_DMAWH_klm_lu_h_shift                                              (12)
#define  DEBLK_DMAWH_klm_lu_w_shift                                              (11)
#define  DEBLK_DMAWH_km_ch_h_shift                                               (7)
#define  DEBLK_DMAWH_km_ch_w_shift                                               (6)
#define  DEBLK_DMAWH_km_lu_h_shift                                               (1)
#define  DEBLK_DMAWH_km_lu_w_shift                                               (0)
#define  DEBLK_DMAWH_klm_ch_h_mask                                               (0x00F80000)
#define  DEBLK_DMAWH_klm_ch_w_mask                                               (0x00040000)
#define  DEBLK_DMAWH_klm_lu_h_mask                                               (0x0003F000)
#define  DEBLK_DMAWH_klm_lu_w_mask                                               (0x00000800)
#define  DEBLK_DMAWH_km_ch_h_mask                                                (0x00000780)
#define  DEBLK_DMAWH_km_ch_w_mask                                                (0x00000040)
#define  DEBLK_DMAWH_km_lu_h_mask                                                (0x0000003E)
#define  DEBLK_DMAWH_km_lu_w_mask                                                (0x00000001)
#define  DEBLK_DMAWH_klm_ch_h(data)                                              (0x00F80000&((data)<<19))
#define  DEBLK_DMAWH_klm_ch_w(data)                                              (0x00040000&((data)<<18))
#define  DEBLK_DMAWH_klm_lu_h(data)                                              (0x0003F000&((data)<<12))
#define  DEBLK_DMAWH_klm_lu_w(data)                                              (0x00000800&((data)<<11))
#define  DEBLK_DMAWH_km_ch_h(data)                                               (0x00000780&((data)<<7))
#define  DEBLK_DMAWH_km_ch_w(data)                                               (0x00000040&((data)<<6))
#define  DEBLK_DMAWH_km_lu_h(data)                                               (0x0000003E&((data)<<1))
#define  DEBLK_DMAWH_km_lu_w(data)                                               (0x00000001&(data))
#define  DEBLK_DMAWH_get_klm_ch_h(data)                                          ((0x00F80000&(data))>>19)
#define  DEBLK_DMAWH_get_klm_ch_w(data)                                          ((0x00040000&(data))>>18)
#define  DEBLK_DMAWH_get_klm_lu_h(data)                                          ((0x0003F000&(data))>>12)
#define  DEBLK_DMAWH_get_klm_lu_w(data)                                          ((0x00000800&(data))>>11)
#define  DEBLK_DMAWH_get_km_ch_h(data)                                           ((0x00000780&(data))>>7)
#define  DEBLK_DMAWH_get_km_ch_w(data)                                           ((0x00000040&(data))>>6)
#define  DEBLK_DMAWH_get_km_lu_h(data)                                           ((0x0000003E&(data))>>1)
#define  DEBLK_DMAWH_get_km_lu_w(data)                                           (0x00000001&(data))
#define  DEBLK_DMAWH_klm_ch_h_src(data)                                          ((0x00F80000&(data))>>19)
#define  DEBLK_DMAWH_klm_ch_w_src(data)                                          ((0x00040000&(data))>>18)
#define  DEBLK_DMAWH_klm_lu_h_src(data)                                          ((0x0003F000&(data))>>12)
#define  DEBLK_DMAWH_klm_lu_w_src(data)                                          ((0x00000800&(data))>>11)
#define  DEBLK_DMAWH_km_ch_h_src(data)                                           ((0x00000780&(data))>>7)
#define  DEBLK_DMAWH_km_ch_w_src(data)                                           ((0x00000040&(data))>>6)
#define  DEBLK_DMAWH_km_lu_h_src(data)                                           ((0x0000003E&(data))>>1)
#define  DEBLK_DMAWH_km_lu_w_src(data)                                           (0x00000001&(data))

#define  DEBLK_DMAADR_0                                                          0x1800EA9C
#define  DEBLK_DMAADR_0_reg_addr                                                 "0xB800EA9C"
#define  DEBLK_DMAADR_0_reg                                                      0xB800EA9C
#define  DEBLK_DMAADR_0_inst_addr                                                "0x0027"
#define  DEBLK_DMAADR_0_inst_adr                                                 "0x00A7"
#define  DEBLK_DMAADR_0_inst                                                     0x00A7
#define  set_DEBLK_DMAADR_0_reg(data)                                            (*((volatile unsigned int*)DEBLK_DMAADR_0_reg)=data)
#define  get_DEBLK_DMAADR_0_reg                                                  (*((volatile unsigned int*)DEBLK_DMAADR_0_reg))
#define  DEBLK_DMAADR_x_shift                                                    (14)
#define  DEBLK_DMAADR_y_shift                                                    (0)
#define  DEBLK_DMAADR_x_mask                                                     (0x07FFC000)
#define  DEBLK_DMAADR_y_mask                                                     (0x00003FFF)
#define  DEBLK_DMAADR_x(data)                                                    (0x07FFC000&((data)<<14))
#define  DEBLK_DMAADR_y(data)                                                    (0x00003FFF&(data))
#define  DEBLK_DMAADR_get_x(data)                                                ((0x07FFC000&(data))>>14)
#define  DEBLK_DMAADR_get_y(data)                                                (0x00003FFF&(data))
#define  DEBLK_DMAADR_x_src(data)                                                ((0x07FFC000&(data))>>14)
#define  DEBLK_DMAADR_y_src(data)                                                (0x00003FFF&(data))

#define  DEBLK_DMAADR_1                                                          0x1800EAA0
#define  DEBLK_DMAADR_1_reg_addr                                                 "0xB800EAA0"
#define  DEBLK_DMAADR_1_reg                                                      0xB800EAA0
#define  DEBLK_DMAADR_1_inst_addr                                                "0x0028"
#define  DEBLK_DMAADR_1_inst_adr                                                 "0x00A8"
#define  DEBLK_DMAADR_1_inst                                                     0x00A8
#define  set_DEBLK_DMAADR_1_reg(data)                                            (*((volatile unsigned int*)DEBLK_DMAADR_1_reg)=data)
#define  get_DEBLK_DMAADR_1_reg                                                  (*((volatile unsigned int*)DEBLK_DMAADR_1_reg))

#define  DEBLK_DMAADR_2                                                          0x1800EAA4
#define  DEBLK_DMAADR_2_reg_addr                                                 "0xB800EAA4"
#define  DEBLK_DMAADR_2_reg                                                      0xB800EAA4
#define  DEBLK_DMAADR_2_inst_addr                                                "0x0029"
#define  DEBLK_DMAADR_2_inst_adr                                                 "0x00A9"
#define  DEBLK_DMAADR_2_inst                                                     0x00A9
#define  set_DEBLK_DMAADR_2_reg(data)                                            (*((volatile unsigned int*)DEBLK_DMAADR_2_reg)=data)
#define  get_DEBLK_DMAADR_2_reg                                                  (*((volatile unsigned int*)DEBLK_DMAADR_2_reg))

#define  DEBLK_DMAADR_3                                                          0x1800EAA8
#define  DEBLK_DMAADR_3_reg_addr                                                 "0xB800EAA8"
#define  DEBLK_DMAADR_3_reg                                                      0xB800EAA8
#define  DEBLK_DMAADR_3_inst_addr                                                "0x002A"
#define  DEBLK_DMAADR_3_inst_adr                                                 "0x00AA"
#define  DEBLK_DMAADR_3_inst                                                     0x00AA
#define  set_DEBLK_DMAADR_3_reg(data)                                            (*((volatile unsigned int*)DEBLK_DMAADR_3_reg)=data)
#define  get_DEBLK_DMAADR_3_reg                                                  (*((volatile unsigned int*)DEBLK_DMAADR_3_reg))

#define  DEBLK_DMAADR_4                                                          0x1800EAAC
#define  DEBLK_DMAADR_4_reg_addr                                                 "0xB800EAAC"
#define  DEBLK_DMAADR_4_reg                                                      0xB800EAAC
#define  DEBLK_DMAADR_4_inst_addr                                                "0x002B"
#define  DEBLK_DMAADR_4_inst_adr                                                 "0x00AB"
#define  DEBLK_DMAADR_4_inst                                                     0x00AB
#define  set_DEBLK_DMAADR_4_reg(data)                                            (*((volatile unsigned int*)DEBLK_DMAADR_4_reg)=data)
#define  get_DEBLK_DMAADR_4_reg                                                  (*((volatile unsigned int*)DEBLK_DMAADR_4_reg))

#define  DEBLK_DMAADR_5                                                          0x1800EAB0
#define  DEBLK_DMAADR_5_reg_addr                                                 "0xB800EAB0"
#define  DEBLK_DMAADR_5_reg                                                      0xB800EAB0
#define  DEBLK_DMAADR_5_inst_addr                                                "0x002C"
#define  DEBLK_DMAADR_5_inst_adr                                                 "0x00AC"
#define  DEBLK_DMAADR_5_inst                                                     0x00AC
#define  set_DEBLK_DMAADR_5_reg(data)                                            (*((volatile unsigned int*)DEBLK_DMAADR_5_reg)=data)
#define  get_DEBLK_DMAADR_5_reg                                                  (*((volatile unsigned int*)DEBLK_DMAADR_5_reg))

#define  DEBLK_DMACTB                                                            0x1800EAB4
#define  DEBLK_DMACTB_reg_addr                                                   "0xB800EAB4"
#define  DEBLK_DMACTB_reg                                                        0xB800EAB4
#define  DEBLK_DMACTB_inst_addr                                                  "0x002D"
#define  DEBLK_DMACTB_inst_adr                                                   "0x00AD"
#define  DEBLK_DMACTB_inst                                                       0x00AD
#define  set_DEBLK_DMACTB_reg(data)                                              (*((volatile unsigned int*)DEBLK_DMACTB_reg)=data)
#define  get_DEBLK_DMACTB_reg                                                    (*((volatile unsigned int*)DEBLK_DMACTB_reg))
#define  DEBLK_DMACTB_ctb_row_offset_shift                                       (0)
#define  DEBLK_DMACTB_ctb_row_offset_mask                                        (0x0000007F)
#define  DEBLK_DMACTB_ctb_row_offset(data)                                       (0x0000007F&(data))
#define  DEBLK_DMACTB_get_ctb_row_offset(data)                                   (0x0000007F&(data))
#define  DEBLK_DMACTB_ctb_row_offset_src(data)                                   (0x0000007F&(data))

#define  DEBLK_SDMAADR                                                           0x1800EAB8
#define  DEBLK_SDMAADR_reg_addr                                                  "0xB800EAB8"
#define  DEBLK_SDMAADR_reg                                                       0xB800EAB8
#define  DEBLK_SDMAADR_inst_addr                                                 "0x002E"
#define  DEBLK_SDMAADR_inst_adr                                                  "0x00AE"
#define  DEBLK_SDMAADR_inst                                                      0x00AE
#define  set_DEBLK_SDMAADR_reg(data)                                             (*((volatile unsigned int*)DEBLK_SDMAADR_reg)=data)
#define  get_DEBLK_SDMAADR_reg                                                   (*((volatile unsigned int*)DEBLK_SDMAADR_reg))
#define  DEBLK_SDMAADR_seq_dma_addr_shift                                        (0)
#define  DEBLK_SDMAADR_seq_dma_addr_mask                                         (0xFFFFFFFF)
#define  DEBLK_SDMAADR_seq_dma_addr(data)                                        (0xFFFFFFFF&(data))
#define  DEBLK_SDMAADR_get_seq_dma_addr(data)                                    (0xFFFFFFFF&(data))
#define  DEBLK_SDMAADR_seq_dma_addr_src(data)                                    (0xFFFFFFFF&(data))

#define  DEBLK_SDMABL                                                            0x1800EABC
#define  DEBLK_SDMABL_reg_addr                                                   "0xB800EABC"
#define  DEBLK_SDMABL_reg                                                        0xB800EABC
#define  DEBLK_SDMABL_inst_addr                                                  "0x002F"
#define  DEBLK_SDMABL_inst_adr                                                   "0x00AF"
#define  DEBLK_SDMABL_inst                                                       0x00AF
#define  set_DEBLK_SDMABL_reg(data)                                              (*((volatile unsigned int*)DEBLK_SDMABL_reg)=data)
#define  get_DEBLK_SDMABL_reg                                                    (*((volatile unsigned int*)DEBLK_SDMABL_reg))
#define  DEBLK_SDMABL_seq_dma_bl_shift                                           (0)
#define  DEBLK_SDMABL_seq_dma_bl_mask                                            (0x000001FF)
#define  DEBLK_SDMABL_seq_dma_bl(data)                                           (0x000001FF&(data))
#define  DEBLK_SDMABL_get_seq_dma_bl(data)                                       (0x000001FF&(data))
#define  DEBLK_SDMABL_seq_dma_bl_src(data)                                       (0x000001FF&(data))

#define  DEBLK_VPXCTRL                                                           0x1800EAC0
#define  DEBLK_VPXCTRL_reg_addr                                                  "0xB800EAC0"
#define  DEBLK_VPXCTRL_reg                                                       0xB800EAC0
#define  DEBLK_VPXCTRL_inst_addr                                                 "0x0030"
#define  DEBLK_VPXCTRL_inst_adr                                                  "0x00B0"
#define  DEBLK_VPXCTRL_inst                                                      0x00B0
#define  set_DEBLK_VPXCTRL_reg(data)                                             (*((volatile unsigned int*)DEBLK_VPXCTRL_reg)=data)
#define  get_DEBLK_VPXCTRL_reg                                                   (*((volatile unsigned int*)DEBLK_VPXCTRL_reg))
#define  DEBLK_VPXCTRL_write_enable3_shift                                       (14)
#define  DEBLK_VPXCTRL_last_filter_type_shift                                    (13)
#define  DEBLK_VPXCTRL_last_sharp_level_shift                                    (10)
#define  DEBLK_VPXCTRL_last_frame_type_shift                                     (9)
#define  DEBLK_VPXCTRL_write_enable2_shift                                       (8)
#define  DEBLK_VPXCTRL_filter_type_shift                                         (7)
#define  DEBLK_VPXCTRL_sharp_level_shift                                         (4)
#define  DEBLK_VPXCTRL_write_enable1_shift                                       (3)
#define  DEBLK_VPXCTRL_lf_delta_enable_shift                                     (2)
#define  DEBLK_VPXCTRL_write_enable0_shift                                       (1)
#define  DEBLK_VPXCTRL_segment_enable_shift                                      (0)
#define  DEBLK_VPXCTRL_write_enable3_mask                                        (0x00004000)
#define  DEBLK_VPXCTRL_last_filter_type_mask                                     (0x00002000)
#define  DEBLK_VPXCTRL_last_sharp_level_mask                                     (0x00001C00)
#define  DEBLK_VPXCTRL_last_frame_type_mask                                      (0x00000200)
#define  DEBLK_VPXCTRL_write_enable2_mask                                        (0x00000100)
#define  DEBLK_VPXCTRL_filter_type_mask                                          (0x00000080)
#define  DEBLK_VPXCTRL_sharp_level_mask                                          (0x00000070)
#define  DEBLK_VPXCTRL_write_enable1_mask                                        (0x00000008)
#define  DEBLK_VPXCTRL_lf_delta_enable_mask                                      (0x00000004)
#define  DEBLK_VPXCTRL_write_enable0_mask                                        (0x00000002)
#define  DEBLK_VPXCTRL_segment_enable_mask                                       (0x00000001)
#define  DEBLK_VPXCTRL_write_enable3(data)                                       (0x00004000&((data)<<14))
#define  DEBLK_VPXCTRL_last_filter_type(data)                                    (0x00002000&((data)<<13))
#define  DEBLK_VPXCTRL_last_sharp_level(data)                                    (0x00001C00&((data)<<10))
#define  DEBLK_VPXCTRL_last_frame_type(data)                                     (0x00000200&((data)<<9))
#define  DEBLK_VPXCTRL_write_enable2(data)                                       (0x00000100&((data)<<8))
#define  DEBLK_VPXCTRL_filter_type(data)                                         (0x00000080&((data)<<7))
#define  DEBLK_VPXCTRL_sharp_level(data)                                         (0x00000070&((data)<<4))
#define  DEBLK_VPXCTRL_write_enable1(data)                                       (0x00000008&((data)<<3))
#define  DEBLK_VPXCTRL_lf_delta_enable(data)                                     (0x00000004&((data)<<2))
#define  DEBLK_VPXCTRL_write_enable0(data)                                       (0x00000002&((data)<<1))
#define  DEBLK_VPXCTRL_segment_enable(data)                                      (0x00000001&(data))
#define  DEBLK_VPXCTRL_get_write_enable3(data)                                   ((0x00004000&(data))>>14)
#define  DEBLK_VPXCTRL_get_last_filter_type(data)                                ((0x00002000&(data))>>13)
#define  DEBLK_VPXCTRL_get_last_sharp_level(data)                                ((0x00001C00&(data))>>10)
#define  DEBLK_VPXCTRL_get_last_frame_type(data)                                 ((0x00000200&(data))>>9)
#define  DEBLK_VPXCTRL_get_write_enable2(data)                                   ((0x00000100&(data))>>8)
#define  DEBLK_VPXCTRL_get_filter_type(data)                                     ((0x00000080&(data))>>7)
#define  DEBLK_VPXCTRL_get_sharp_level(data)                                     ((0x00000070&(data))>>4)
#define  DEBLK_VPXCTRL_get_write_enable1(data)                                   ((0x00000008&(data))>>3)
#define  DEBLK_VPXCTRL_get_lf_delta_enable(data)                                 ((0x00000004&(data))>>2)
#define  DEBLK_VPXCTRL_get_write_enable0(data)                                   ((0x00000002&(data))>>1)
#define  DEBLK_VPXCTRL_get_segment_enable(data)                                  (0x00000001&(data))
#define  DEBLK_VPXCTRL_write_enable3_src(data)                                   ((0x00004000&(data))>>14)
#define  DEBLK_VPXCTRL_last_filter_type_src(data)                                ((0x00002000&(data))>>13)
#define  DEBLK_VPXCTRL_last_sharp_level_src(data)                                ((0x00001C00&(data))>>10)
#define  DEBLK_VPXCTRL_last_frame_type_src(data)                                 ((0x00000200&(data))>>9)
#define  DEBLK_VPXCTRL_write_enable2_src(data)                                   ((0x00000100&(data))>>8)
#define  DEBLK_VPXCTRL_filter_type_src(data)                                     ((0x00000080&(data))>>7)
#define  DEBLK_VPXCTRL_sharp_level_src(data)                                     ((0x00000070&(data))>>4)
#define  DEBLK_VPXCTRL_write_enable1_src(data)                                   ((0x00000008&(data))>>3)
#define  DEBLK_VPXCTRL_lf_delta_enable_src(data)                                 ((0x00000004&(data))>>2)
#define  DEBLK_VPXCTRL_write_enable0_src(data)                                   ((0x00000002&(data))>>1)
#define  DEBLK_VPXCTRL_segment_enable_src(data)                                  (0x00000001&(data))

#define  DEBLK_VPXFILTLVL                                                        0x1800EAC4
#define  DEBLK_VPXFILTLVL_reg_addr                                               "0xB800EAC4"
#define  DEBLK_VPXFILTLVL_reg                                                    0xB800EAC4
#define  DEBLK_VPXFILTLVL_inst_addr                                              "0x0031"
#define  DEBLK_VPXFILTLVL_inst_adr                                               "0x00B1"
#define  DEBLK_VPXFILTLVL_inst                                                   0x00B1
#define  set_DEBLK_VPXFILTLVL_reg(data)                                          (*((volatile unsigned int*)DEBLK_VPXFILTLVL_reg)=data)
#define  get_DEBLK_VPXFILTLVL_reg                                                (*((volatile unsigned int*)DEBLK_VPXFILTLVL_reg))
#define  DEBLK_VPXFILTLVL_base_filt_lvl_3_shift                                  (24)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_2_shift                                  (16)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_1_shift                                  (8)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_0_shift                                  (0)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_3_mask                                   (0x7F000000)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_2_mask                                   (0x007F0000)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_1_mask                                   (0x00007F00)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_0_mask                                   (0x0000007F)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_3(data)                                  (0x7F000000&((data)<<24))
#define  DEBLK_VPXFILTLVL_base_filt_lvl_2(data)                                  (0x007F0000&((data)<<16))
#define  DEBLK_VPXFILTLVL_base_filt_lvl_1(data)                                  (0x00007F00&((data)<<8))
#define  DEBLK_VPXFILTLVL_base_filt_lvl_0(data)                                  (0x0000007F&(data))
#define  DEBLK_VPXFILTLVL_get_base_filt_lvl_3(data)                              ((0x7F000000&(data))>>24)
#define  DEBLK_VPXFILTLVL_get_base_filt_lvl_2(data)                              ((0x007F0000&(data))>>16)
#define  DEBLK_VPXFILTLVL_get_base_filt_lvl_1(data)                              ((0x00007F00&(data))>>8)
#define  DEBLK_VPXFILTLVL_get_base_filt_lvl_0(data)                              (0x0000007F&(data))
#define  DEBLK_VPXFILTLVL_base_filt_lvl_3_src(data)                              ((0x7F000000&(data))>>24)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_2_src(data)                              ((0x007F0000&(data))>>16)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_1_src(data)                              ((0x00007F00&(data))>>8)
#define  DEBLK_VPXFILTLVL_base_filt_lvl_0_src(data)                              (0x0000007F&(data))

#define  DEBLK_VPXREFDELTA                                                       0x1800EAC8
#define  DEBLK_VPXREFDELTA_reg_addr                                              "0xB800EAC8"
#define  DEBLK_VPXREFDELTA_reg                                                   0xB800EAC8
#define  DEBLK_VPXREFDELTA_inst_addr                                             "0x0032"
#define  DEBLK_VPXREFDELTA_inst_adr                                              "0x00B2"
#define  DEBLK_VPXREFDELTA_inst                                                  0x00B2
#define  set_DEBLK_VPXREFDELTA_reg(data)                                         (*((volatile unsigned int*)DEBLK_VPXREFDELTA_reg)=data)
#define  get_DEBLK_VPXREFDELTA_reg                                               (*((volatile unsigned int*)DEBLK_VPXREFDELTA_reg))
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_3_shift                                 (24)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_2_shift                                 (16)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_1_shift                                 (8)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_0_shift                                 (0)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_3_mask                                  (0x7F000000)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_2_mask                                  (0x007F0000)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_1_mask                                  (0x00007F00)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_0_mask                                  (0x0000007F)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_3(data)                                 (0x7F000000&((data)<<24))
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_2(data)                                 (0x007F0000&((data)<<16))
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_1(data)                                 (0x00007F00&((data)<<8))
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_0(data)                                 (0x0000007F&(data))
#define  DEBLK_VPXREFDELTA_get_ref_lf_deltas_3(data)                             ((0x7F000000&(data))>>24)
#define  DEBLK_VPXREFDELTA_get_ref_lf_deltas_2(data)                             ((0x007F0000&(data))>>16)
#define  DEBLK_VPXREFDELTA_get_ref_lf_deltas_1(data)                             ((0x00007F00&(data))>>8)
#define  DEBLK_VPXREFDELTA_get_ref_lf_deltas_0(data)                             (0x0000007F&(data))
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_3_src(data)                             ((0x7F000000&(data))>>24)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_2_src(data)                             ((0x007F0000&(data))>>16)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_1_src(data)                             ((0x00007F00&(data))>>8)
#define  DEBLK_VPXREFDELTA_ref_lf_deltas_0_src(data)                             (0x0000007F&(data))

#define  DEBLK_VPXMODEDELTA                                                      0x1800EACC
#define  DEBLK_VPXMODEDELTA_reg_addr                                             "0xB800EACC"
#define  DEBLK_VPXMODEDELTA_reg                                                  0xB800EACC
#define  DEBLK_VPXMODEDELTA_inst_addr                                            "0x0033"
#define  DEBLK_VPXMODEDELTA_inst_adr                                             "0x00B3"
#define  DEBLK_VPXMODEDELTA_inst                                                 0x00B3
#define  set_DEBLK_VPXMODEDELTA_reg(data)                                        (*((volatile unsigned int*)DEBLK_VPXMODEDELTA_reg)=data)
#define  get_DEBLK_VPXMODEDELTA_reg                                              (*((volatile unsigned int*)DEBLK_VPXMODEDELTA_reg))
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_3_shift                               (24)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_2_shift                               (16)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_1_shift                               (8)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_0_shift                               (0)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_3_mask                                (0x7F000000)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_2_mask                                (0x007F0000)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_1_mask                                (0x00007F00)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_0_mask                                (0x0000007F)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_3(data)                               (0x7F000000&((data)<<24))
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_2(data)                               (0x007F0000&((data)<<16))
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_1(data)                               (0x00007F00&((data)<<8))
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_0(data)                               (0x0000007F&(data))
#define  DEBLK_VPXMODEDELTA_get_mode_lf_deltas_3(data)                           ((0x7F000000&(data))>>24)
#define  DEBLK_VPXMODEDELTA_get_mode_lf_deltas_2(data)                           ((0x007F0000&(data))>>16)
#define  DEBLK_VPXMODEDELTA_get_mode_lf_deltas_1(data)                           ((0x00007F00&(data))>>8)
#define  DEBLK_VPXMODEDELTA_get_mode_lf_deltas_0(data)                           (0x0000007F&(data))
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_3_src(data)                           ((0x7F000000&(data))>>24)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_2_src(data)                           ((0x007F0000&(data))>>16)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_1_src(data)                           ((0x00007F00&(data))>>8)
#define  DEBLK_VPXMODEDELTA_mode_lf_deltas_0_src(data)                           (0x0000007F&(data))

#define  DEBLK_VPXDBPAR                                                          0x1800EAD0
#define  DEBLK_VPXDBPAR_reg_addr                                                 "0xB800EAD0"
#define  DEBLK_VPXDBPAR_reg                                                      0xB800EAD0
#define  DEBLK_VPXDBPAR_inst_addr                                                "0x0034"
#define  DEBLK_VPXDBPAR_inst_adr                                                 "0x00B4"
#define  DEBLK_VPXDBPAR_inst                                                     0x00B4
#define  set_DEBLK_VPXDBPAR_reg(data)                                            (*((volatile unsigned int*)DEBLK_VPXDBPAR_reg)=data)
#define  get_DEBLK_VPXDBPAR_reg                                                  (*((volatile unsigned int*)DEBLK_VPXDBPAR_reg))
#define  DEBLK_VPXDBPAR_intra_mb_shift                                           (6)
#define  DEBLK_VPXDBPAR_eob_total_shift                                          (5)
#define  DEBLK_VPXDBPAR_ref_frame_shift                                          (3)
#define  DEBLK_VPXDBPAR_mb_mode_shift                                            (0)
#define  DEBLK_VPXDBPAR_intra_mb_mask                                            (0x00000040)
#define  DEBLK_VPXDBPAR_eob_total_mask                                           (0x00000020)
#define  DEBLK_VPXDBPAR_ref_frame_mask                                           (0x00000018)
#define  DEBLK_VPXDBPAR_mb_mode_mask                                             (0x00000007)
#define  DEBLK_VPXDBPAR_intra_mb(data)                                           (0x00000040&((data)<<6))
#define  DEBLK_VPXDBPAR_eob_total(data)                                          (0x00000020&((data)<<5))
#define  DEBLK_VPXDBPAR_ref_frame(data)                                          (0x00000018&((data)<<3))
#define  DEBLK_VPXDBPAR_mb_mode(data)                                            (0x00000007&(data))
#define  DEBLK_VPXDBPAR_get_intra_mb(data)                                       ((0x00000040&(data))>>6)
#define  DEBLK_VPXDBPAR_get_eob_total(data)                                      ((0x00000020&(data))>>5)
#define  DEBLK_VPXDBPAR_get_ref_frame(data)                                      ((0x00000018&(data))>>3)
#define  DEBLK_VPXDBPAR_get_mb_mode(data)                                        (0x00000007&(data))
#define  DEBLK_VPXDBPAR_intra_mb_src(data)                                       ((0x00000040&(data))>>6)
#define  DEBLK_VPXDBPAR_eob_total_src(data)                                      ((0x00000020&(data))>>5)
#define  DEBLK_VPXDBPAR_ref_frame_src(data)                                      ((0x00000018&(data))>>3)
#define  DEBLK_VPXDBPAR_mb_mode_src(data)                                        (0x00000007&(data))

#define  DEBLK_HEVCDBPAR0_0                                                      0x1800EAD4
#define  DEBLK_HEVCDBPAR0_0_reg_addr                                             "0xB800EAD4"
#define  DEBLK_HEVCDBPAR0_0_reg                                                  0xB800EAD4
#define  DEBLK_HEVCDBPAR0_0_inst_addr                                            "0x0035"
#define  DEBLK_HEVCDBPAR0_0_inst_adr                                             "0x00B5"
#define  DEBLK_HEVCDBPAR0_0_inst                                                 0x00B5
#define  set_DEBLK_HEVCDBPAR0_0_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_0_reg)=data)
#define  get_DEBLK_HEVCDBPAR0_0_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_0_reg))
#define  DEBLK_HEVCDBPAR0_slice_loop_filter_across_slices_enabled_flag_shift     (28)
#define  DEBLK_HEVCDBPAR0_slice_disable_deblocking_filter_flag_shift             (27)
#define  DEBLK_HEVCDBPAR0_tc_offset_div2_shift                                   (23)
#define  DEBLK_HEVCDBPAR0_beta_offset_div2_shift                                 (19)
#define  DEBLK_HEVCDBPAR0_tile_id_shift                                          (10)
#define  DEBLK_HEVCDBPAR0_slice_id_shift                                         (0)
#define  DEBLK_HEVCDBPAR0_slice_loop_filter_across_slices_enabled_flag_mask      (0x10000000)
#define  DEBLK_HEVCDBPAR0_slice_disable_deblocking_filter_flag_mask              (0x08000000)
#define  DEBLK_HEVCDBPAR0_tc_offset_div2_mask                                    (0x07800000)
#define  DEBLK_HEVCDBPAR0_beta_offset_div2_mask                                  (0x00780000)
#define  DEBLK_HEVCDBPAR0_tile_id_mask                                           (0x0007FC00)
#define  DEBLK_HEVCDBPAR0_slice_id_mask                                          (0x000003FF)
#define  DEBLK_HEVCDBPAR0_slice_loop_filter_across_slices_enabled_flag(data)     (0x10000000&((data)<<28))
#define  DEBLK_HEVCDBPAR0_slice_disable_deblocking_filter_flag(data)             (0x08000000&((data)<<27))
#define  DEBLK_HEVCDBPAR0_tc_offset_div2(data)                                   (0x07800000&((data)<<23))
#define  DEBLK_HEVCDBPAR0_beta_offset_div2(data)                                 (0x00780000&((data)<<19))
#define  DEBLK_HEVCDBPAR0_tile_id(data)                                          (0x0007FC00&((data)<<10))
#define  DEBLK_HEVCDBPAR0_slice_id(data)                                         (0x000003FF&(data))
#define  DEBLK_HEVCDBPAR0_get_slice_loop_filter_across_slices_enabled_flag(data) ((0x10000000&(data))>>28)
#define  DEBLK_HEVCDBPAR0_get_slice_disable_deblocking_filter_flag(data)         ((0x08000000&(data))>>27)
#define  DEBLK_HEVCDBPAR0_get_tc_offset_div2(data)                               ((0x07800000&(data))>>23)
#define  DEBLK_HEVCDBPAR0_get_beta_offset_div2(data)                             ((0x00780000&(data))>>19)
#define  DEBLK_HEVCDBPAR0_get_tile_id(data)                                      ((0x0007FC00&(data))>>10)
#define  DEBLK_HEVCDBPAR0_get_slice_id(data)                                     (0x000003FF&(data))
#define  DEBLK_HEVCDBPAR0_slice_loop_filter_across_slices_enabled_flag_src(data) ((0x10000000&(data))>>28)
#define  DEBLK_HEVCDBPAR0_slice_disable_deblocking_filter_flag_src(data)         ((0x08000000&(data))>>27)
#define  DEBLK_HEVCDBPAR0_tc_offset_div2_src(data)                               ((0x07800000&(data))>>23)
#define  DEBLK_HEVCDBPAR0_beta_offset_div2_src(data)                             ((0x00780000&(data))>>19)
#define  DEBLK_HEVCDBPAR0_tile_id_src(data)                                      ((0x0007FC00&(data))>>10)
#define  DEBLK_HEVCDBPAR0_slice_id_src(data)                                     (0x000003FF&(data))

#define  DEBLK_HEVCDBPAR0_1                                                      0x1800EAD8
#define  DEBLK_HEVCDBPAR0_1_reg_addr                                             "0xB800EAD8"
#define  DEBLK_HEVCDBPAR0_1_reg                                                  0xB800EAD8
#define  DEBLK_HEVCDBPAR0_1_inst_addr                                            "0x0036"
#define  DEBLK_HEVCDBPAR0_1_inst_adr                                             "0x00B6"
#define  DEBLK_HEVCDBPAR0_1_inst                                                 0x00B6
#define  set_DEBLK_HEVCDBPAR0_1_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_1_reg)=data)
#define  get_DEBLK_HEVCDBPAR0_1_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_1_reg))

#define  DEBLK_HEVCDBPAR0_2                                                      0x1800EADC
#define  DEBLK_HEVCDBPAR0_2_reg_addr                                             "0xB800EADC"
#define  DEBLK_HEVCDBPAR0_2_reg                                                  0xB800EADC
#define  DEBLK_HEVCDBPAR0_2_inst_addr                                            "0x0037"
#define  DEBLK_HEVCDBPAR0_2_inst_adr                                             "0x00B7"
#define  DEBLK_HEVCDBPAR0_2_inst                                                 0x00B7
#define  set_DEBLK_HEVCDBPAR0_2_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_2_reg)=data)
#define  get_DEBLK_HEVCDBPAR0_2_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_2_reg))

#define  DEBLK_HEVCDBPAR0_3                                                      0x1800EAE0
#define  DEBLK_HEVCDBPAR0_3_reg_addr                                             "0xB800EAE0"
#define  DEBLK_HEVCDBPAR0_3_reg                                                  0xB800EAE0
#define  DEBLK_HEVCDBPAR0_3_inst_addr                                            "0x0038"
#define  DEBLK_HEVCDBPAR0_3_inst_adr                                             "0x00B8"
#define  DEBLK_HEVCDBPAR0_3_inst                                                 0x00B8
#define  set_DEBLK_HEVCDBPAR0_3_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_3_reg)=data)
#define  get_DEBLK_HEVCDBPAR0_3_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR0_3_reg))

#define  DEBLK_HEVCDBPAR1_0                                                      0x1800EAE4
#define  DEBLK_HEVCDBPAR1_0_reg_addr                                             "0xB800EAE4"
#define  DEBLK_HEVCDBPAR1_0_reg                                                  0xB800EAE4
#define  DEBLK_HEVCDBPAR1_0_inst_addr                                            "0x0039"
#define  DEBLK_HEVCDBPAR1_0_inst_adr                                             "0x00B9"
#define  DEBLK_HEVCDBPAR1_0_inst                                                 0x00B9
#define  set_DEBLK_HEVCDBPAR1_0_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_0_reg)=data)
#define  get_DEBLK_HEVCDBPAR1_0_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_0_reg))
#define  DEBLK_HEVCDBPAR1_padding_cu_shift                                       (4)
#define  DEBLK_HEVCDBPAR1_pcm_transquant_disable_flag_shift                      (0)
#define  DEBLK_HEVCDBPAR1_padding_cu_mask                                        (0x000000F0)
#define  DEBLK_HEVCDBPAR1_pcm_transquant_disable_flag_mask                       (0x0000000F)
#define  DEBLK_HEVCDBPAR1_padding_cu(data)                                       (0x000000F0&((data)<<4))
#define  DEBLK_HEVCDBPAR1_pcm_transquant_disable_flag(data)                      (0x0000000F&(data))
#define  DEBLK_HEVCDBPAR1_get_padding_cu(data)                                   ((0x000000F0&(data))>>4)
#define  DEBLK_HEVCDBPAR1_get_pcm_transquant_disable_flag(data)                  (0x0000000F&(data))
#define  DEBLK_HEVCDBPAR1_padding_cu_src(data)                                   ((0x000000F0&(data))>>4)
#define  DEBLK_HEVCDBPAR1_pcm_transquant_disable_flag_src(data)                  (0x0000000F&(data))

#define  DEBLK_HEVCDBPAR1_1                                                      0x1800EAE8
#define  DEBLK_HEVCDBPAR1_1_reg_addr                                             "0xB800EAE8"
#define  DEBLK_HEVCDBPAR1_1_reg                                                  0xB800EAE8
#define  DEBLK_HEVCDBPAR1_1_inst_addr                                            "0x003A"
#define  DEBLK_HEVCDBPAR1_1_inst_adr                                             "0x00BA"
#define  DEBLK_HEVCDBPAR1_1_inst                                                 0x00BA
#define  set_DEBLK_HEVCDBPAR1_1_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_1_reg)=data)
#define  get_DEBLK_HEVCDBPAR1_1_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_1_reg))

#define  DEBLK_HEVCDBPAR1_2                                                      0x1800EAEC
#define  DEBLK_HEVCDBPAR1_2_reg_addr                                             "0xB800EAEC"
#define  DEBLK_HEVCDBPAR1_2_reg                                                  0xB800EAEC
#define  DEBLK_HEVCDBPAR1_2_inst_addr                                            "0x003B"
#define  DEBLK_HEVCDBPAR1_2_inst_adr                                             "0x00BB"
#define  DEBLK_HEVCDBPAR1_2_inst                                                 0x00BB
#define  set_DEBLK_HEVCDBPAR1_2_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_2_reg)=data)
#define  get_DEBLK_HEVCDBPAR1_2_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_2_reg))

#define  DEBLK_HEVCDBPAR1_3                                                      0x1800EAF0
#define  DEBLK_HEVCDBPAR1_3_reg_addr                                             "0xB800EAF0"
#define  DEBLK_HEVCDBPAR1_3_reg                                                  0xB800EAF0
#define  DEBLK_HEVCDBPAR1_3_inst_addr                                            "0x003C"
#define  DEBLK_HEVCDBPAR1_3_inst_adr                                             "0x00BC"
#define  DEBLK_HEVCDBPAR1_3_inst                                                 0x00BC
#define  set_DEBLK_HEVCDBPAR1_3_reg(data)                                        (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_3_reg)=data)
#define  get_DEBLK_HEVCDBPAR1_3_reg                                              (*((volatile unsigned int*)DEBLK_HEVCDBPAR1_3_reg))

#define  DEBLK_HEVCDBPAR2                                                        0x1800EAF4
#define  DEBLK_HEVCDBPAR2_reg_addr                                               "0xB800EAF4"
#define  DEBLK_HEVCDBPAR2_reg                                                    0xB800EAF4
#define  DEBLK_HEVCDBPAR2_inst_addr                                              "0x003D"
#define  DEBLK_HEVCDBPAR2_inst_adr                                               "0x00BD"
#define  DEBLK_HEVCDBPAR2_inst                                                   0x00BD
#define  set_DEBLK_HEVCDBPAR2_reg(data)                                          (*((volatile unsigned int*)DEBLK_HEVCDBPAR2_reg)=data)
#define  get_DEBLK_HEVCDBPAR2_reg                                                (*((volatile unsigned int*)DEBLK_HEVCDBPAR2_reg))
#define  DEBLK_HEVCDBPAR2_dmy_row_ctb_shift                                      (5)
#define  DEBLK_HEVCDBPAR2_dmy_clm_ctb_shift                                      (4)
#define  DEBLK_HEVCDBPAR2_mb_num_shift                                           (0)
#define  DEBLK_HEVCDBPAR2_dmy_row_ctb_mask                                       (0x00000020)
#define  DEBLK_HEVCDBPAR2_dmy_clm_ctb_mask                                       (0x00000010)
#define  DEBLK_HEVCDBPAR2_mb_num_mask                                            (0x0000000F)
#define  DEBLK_HEVCDBPAR2_dmy_row_ctb(data)                                      (0x00000020&((data)<<5))
#define  DEBLK_HEVCDBPAR2_dmy_clm_ctb(data)                                      (0x00000010&((data)<<4))
#define  DEBLK_HEVCDBPAR2_mb_num(data)                                           (0x0000000F&(data))
#define  DEBLK_HEVCDBPAR2_get_dmy_row_ctb(data)                                  ((0x00000020&(data))>>5)
#define  DEBLK_HEVCDBPAR2_get_dmy_clm_ctb(data)                                  ((0x00000010&(data))>>4)
#define  DEBLK_HEVCDBPAR2_get_mb_num(data)                                       (0x0000000F&(data))
#define  DEBLK_HEVCDBPAR2_dmy_row_ctb_src(data)                                  ((0x00000020&(data))>>5)
#define  DEBLK_HEVCDBPAR2_dmy_clm_ctb_src(data)                                  ((0x00000010&(data))>>4)
#define  DEBLK_HEVCDBPAR2_mb_num_src(data)                                       (0x0000000F&(data))

#ifdef _DEBLK_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DEBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  PicType:3;
        RBus_UInt32  First_mb:1;
        RBus_UInt32  Cur_mb_x:10;
        RBus_UInt32  Cur_mb_y:9;
    };
}DEBLK_CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  IntraMB_flag:1;
        RBus_UInt32  Intra_flag:5;
        RBus_UInt32  SubMB_partition:12;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  FIELDTX:1;
        RBus_UInt32  OVERFLAG:1;
    };
}DEBLK_VC1CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ParCom_StartA:7;
    };
}DEBLK_PARSA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  New_slice_row:1;
        RBus_UInt32  New_slice_mb_x:9;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  Sw_neighbor_enable:1;
        RBus_UInt32  MbAddrA_available:1;
        RBus_UInt32  MbAddrB_available:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  MbAddrD_available:1;
    };
}DEBLK_NEIGHBOR_RBUS;

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
}DEBLK_DEBCNTL_RBUS;

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
}DEBLK_DEBCNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dmy_auto_mode:1;
        RBus_UInt32  dmy_mb_row:1;
        RBus_UInt32  dmy_mb_clm:1;
    };
}DEBLK_H264CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  Intra_flag:1;
        RBus_UInt32  transform_size_8x8_flag:1;
        RBus_UInt32  QPy:6;
        RBus_UInt32  QPcb:6;
        RBus_UInt32  QPcr:6;
        RBus_UInt32  MB_field_decoding_flag:1;
        RBus_UInt32  Mb_partition:9;
    };
}DEBLK_H264DBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  BS1_valid_ext:4;
        RBus_UInt32  Subblkpat:24;
    };
}DEBLK_H264DBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  BS1_valid:32;
    };
}DEBLK_H264DBPAR2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Lu_Mv_equal:32;
    };
}DEBLK_VC1DBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Subblkpat:24;
        RBus_UInt32  ch_mv_equal:8;
    };
}DEBLK_VC1DBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  RefQP:5;
        RBus_UInt32  Beta2Sel:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  is_key_frame:1;
        RBus_UInt32  chroma_only:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  Sel_s_chroma_deblock:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  STR9_initQP:5;
        RBus_UInt32  STR8_initQP:5;
        RBus_UInt32  STR7_initQP:5;
    };
}DEBLK_RVCTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  STR6_initQP:5;
        RBus_UInt32  STR5_initQP:5;
        RBus_UInt32  STR4_initQP:5;
        RBus_UInt32  STR3_initQP:5;
        RBus_UInt32  STR2_initQP:5;
        RBus_UInt32  STR1_initQP:5;
    };
}DEBLK_RV8CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  mvd:16;
        RBus_UInt32  QP:5;
    };
}DEBLK_RVDBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  up_mvd_mod:4;
        RBus_UInt32  left_mvd_mod:4;
        RBus_UInt32  Ul_str_eq2:1;
        RBus_UInt32  Up_str_eq2:1;
        RBus_UInt32  Left_str_eq2:1;
        RBus_UInt32  Cur_str_eq2:1;
        RBus_UInt32  up_ul_refdiff:1;
        RBus_UInt32  left_ul_refdiff:1;
        RBus_UInt32  cur_l_refdiff:1;
        RBus_UInt32  cur_up_refdiff:1;
        RBus_UInt32  up_cur_refdiff:1;
    };
}DEBLK_RVDBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  Subblk2Clip_ch:1;
        RBus_UInt32  Subblk12Clip_lu:1;
    };
}DEBLK_RV9CLIP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  is_skip:1;
        RBus_UInt32  Qpch:5;
        RBus_UInt32  Qpy:5;
    };
}DEBLK_WMV8DBPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  BaseA0:7;
        RBus_UInt32  BaseA1:7;
    };
}DEBLK_VMADRBA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  OffsetA0:7;
        RBus_UInt32  OffsetA1:7;
        RBus_UInt32  OffsetA2:7;
    };
}DEBLK_VMADROA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  mb_case_dbg_en:1;
        RBus_UInt32  mb_case_dbg:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  Sb_load_disable:3;
    };
}DEBLK_DEBSBCTL_RBUS;

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
}DEBLK_DMACTRL_RBUS;

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
}DEBLK_DMALU_RBUS;

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
}DEBLK_DMACH_RBUS;

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
}DEBLK_DMAWH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  x:13;
        RBus_UInt32  y:14;
    };
}DEBLK_DMAADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ctb_row_offset:7;
    };
}DEBLK_DMACTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_dma_addr:32;
    };
}DEBLK_SDMAADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  seq_dma_bl:9;
    };
}DEBLK_SDMABL_RBUS;

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
}DEBLK_VPXCTRL_RBUS;

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
}DEBLK_VPXFILTLVL_RBUS;

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
}DEBLK_VPXREFDELTA_RBUS;

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
}DEBLK_VPXMODEDELTA_RBUS;

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
}DEBLK_VPXDBPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  slice_loop_filter_across_slices_enabled_flag:1;
        RBus_UInt32  slice_disable_deblocking_filter_flag:1;
        RBus_UInt32  tc_offset_div2:4;
        RBus_UInt32  beta_offset_div2:4;
        RBus_UInt32  tile_id:9;
        RBus_UInt32  slice_id:10;
    };
}DEBLK_HEVCDBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  padding_cu:4;
        RBus_UInt32  pcm_transquant_disable_flag:4;
    };
}DEBLK_HEVCDBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dmy_row_ctb:1;
        RBus_UInt32  dmy_clm_ctb:1;
        RBus_UInt32  mb_num:4;
    };
}DEBLK_HEVCDBPAR2_RBUS;

#else //apply LITTLE_ENDIAN

//======DEBLK register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Cur_mb_y:9;
        RBus_UInt32  Cur_mb_x:10;
        RBus_UInt32  First_mb:1;
        RBus_UInt32  PicType:3;
        RBus_UInt32  res1:9;
    };
}DEBLK_CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  OVERFLAG:1;
        RBus_UInt32  FIELDTX:1;
        RBus_UInt32  mvtype:2;
        RBus_UInt32  SubMB_partition:12;
        RBus_UInt32  Intra_flag:5;
        RBus_UInt32  IntraMB_flag:1;
        RBus_UInt32  res1:10;
    };
}DEBLK_VC1CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ParCom_StartA:7;
        RBus_UInt32  res1:25;
    };
}DEBLK_PARSA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  MbAddrD_available:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  MbAddrB_available:1;
        RBus_UInt32  MbAddrA_available:1;
        RBus_UInt32  Sw_neighbor_enable:1;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  New_slice_mb_x:9;
        RBus_UInt32  New_slice_row:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:11;
    };
}DEBLK_NEIGHBOR_RBUS;

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
}DEBLK_DEBCNTL_RBUS;

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
}DEBLK_DEBCNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmy_mb_clm:1;
        RBus_UInt32  dmy_mb_row:1;
        RBus_UInt32  dmy_auto_mode:1;
        RBus_UInt32  res1:29;
    };
}DEBLK_H264CCPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Mb_partition:9;
        RBus_UInt32  MB_field_decoding_flag:1;
        RBus_UInt32  QPcr:6;
        RBus_UInt32  QPcb:6;
        RBus_UInt32  QPy:6;
        RBus_UInt32  transform_size_8x8_flag:1;
        RBus_UInt32  Intra_flag:1;
        RBus_UInt32  res1:2;
    };
}DEBLK_H264DBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Subblkpat:24;
        RBus_UInt32  BS1_valid_ext:4;
        RBus_UInt32  res1:4;
    };
}DEBLK_H264DBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  BS1_valid:32;
    };
}DEBLK_H264DBPAR2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Lu_Mv_equal:32;
    };
}DEBLK_VC1DBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch_mv_equal:8;
        RBus_UInt32  Subblkpat:24;
    };
}DEBLK_VC1DBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  STR7_initQP:5;
        RBus_UInt32  STR8_initQP:5;
        RBus_UInt32  STR9_initQP:5;
        RBus_UInt32  write_enable0:1;
        RBus_UInt32  Sel_s_chroma_deblock:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  chroma_only:1;
        RBus_UInt32  is_key_frame:1;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  Beta2Sel:1;
        RBus_UInt32  RefQP:5;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:4;
    };
}DEBLK_RVCTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  STR1_initQP:5;
        RBus_UInt32  STR2_initQP:5;
        RBus_UInt32  STR3_initQP:5;
        RBus_UInt32  STR4_initQP:5;
        RBus_UInt32  STR5_initQP:5;
        RBus_UInt32  STR6_initQP:5;
        RBus_UInt32  res1:2;
    };
}DEBLK_RV8CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  QP:5;
        RBus_UInt32  mvd:16;
        RBus_UInt32  res1:11;
    };
}DEBLK_RVDBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  up_cur_refdiff:1;
        RBus_UInt32  cur_up_refdiff:1;
        RBus_UInt32  cur_l_refdiff:1;
        RBus_UInt32  left_ul_refdiff:1;
        RBus_UInt32  up_ul_refdiff:1;
        RBus_UInt32  Cur_str_eq2:1;
        RBus_UInt32  Left_str_eq2:1;
        RBus_UInt32  Up_str_eq2:1;
        RBus_UInt32  Ul_str_eq2:1;
        RBus_UInt32  left_mvd_mod:4;
        RBus_UInt32  up_mvd_mod:4;
        RBus_UInt32  res1:15;
    };
}DEBLK_RVDBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Subblk12Clip_lu:1;
        RBus_UInt32  Subblk2Clip_ch:1;
        RBus_UInt32  res1:30;
    };
}DEBLK_RV9CLIP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Qpy:5;
        RBus_UInt32  Qpch:5;
        RBus_UInt32  is_skip:1;
        RBus_UInt32  res1:21;
    };
}DEBLK_WMV8DBPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  BaseA1:7;
        RBus_UInt32  BaseA0:7;
        RBus_UInt32  res1:18;
    };
}DEBLK_VMADRBA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  OffsetA2:7;
        RBus_UInt32  OffsetA1:7;
        RBus_UInt32  OffsetA0:7;
        RBus_UInt32  res1:11;
    };
}DEBLK_VMADROA_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Sb_load_disable:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  mb_case_dbg:4;
        RBus_UInt32  mb_case_dbg_en:1;
        RBus_UInt32  res2:23;
    };
}DEBLK_DEBSBCTL_RBUS;

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
}DEBLK_DMACTRL_RBUS;

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
}DEBLK_DMALU_RBUS;

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
}DEBLK_DMACH_RBUS;

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
}DEBLK_DMAWH_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:14;
        RBus_UInt32  x:13;
        RBus_UInt32  res1:5;
    };
}DEBLK_DMAADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ctb_row_offset:7;
        RBus_UInt32  res1:25;
    };
}DEBLK_DMACTB_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_dma_addr:32;
    };
}DEBLK_SDMAADR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seq_dma_bl:9;
        RBus_UInt32  res1:23;
    };
}DEBLK_SDMABL_RBUS;

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
}DEBLK_VPXCTRL_RBUS;

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
}DEBLK_VPXFILTLVL_RBUS;

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
}DEBLK_VPXREFDELTA_RBUS;

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
}DEBLK_VPXMODEDELTA_RBUS;

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
}DEBLK_VPXDBPAR_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slice_id:10;
        RBus_UInt32  tile_id:9;
        RBus_UInt32  beta_offset_div2:4;
        RBus_UInt32  tc_offset_div2:4;
        RBus_UInt32  slice_disable_deblocking_filter_flag:1;
        RBus_UInt32  slice_loop_filter_across_slices_enabled_flag:1;
        RBus_UInt32  res1:3;
    };
}DEBLK_HEVCDBPAR0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcm_transquant_disable_flag:4;
        RBus_UInt32  padding_cu:4;
        RBus_UInt32  res1:24;
    };
}DEBLK_HEVCDBPAR1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_num:4;
        RBus_UInt32  dmy_clm_ctb:1;
        RBus_UInt32  dmy_row_ctb:1;
        RBus_UInt32  res1:26;
    };
}DEBLK_HEVCDBPAR2_RBUS;




#endif 


#endif 
#endif 
