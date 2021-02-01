/**
* @file rbusRif_regReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2016/8/22
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_RIF_REG_REG_H_
#define _RBUS_RIF_REG_REG_H_

#include "rbusTypes.h"



//  RIF_REG Register Address
#define  RIF_REG_VE_CTRL                                                         0x1800E400
#define  RIF_REG_VE_CTRL_reg_addr                                                "0xB800E400"
#define  RIF_REG_VE_CTRL_reg                                                     0xB800E400
#define  RIF_REG_VE_CTRL_inst_addr                                               "0x0000"
#define  RIF_REG_VE_CTRL_inst_adr                                                "0x0000"
#define  RIF_REG_VE_CTRL_inst                                                    0x0000
#define  set_RIF_REG_VE_CTRL_reg(data)                                           (*((volatile unsigned int*)RIF_REG_VE_CTRL_reg)=data)
#define  get_RIF_REG_VE_CTRL_reg                                                 (*((volatile unsigned int*)RIF_REG_VE_CTRL_reg))
#define  RIF_REG_VE_CTRL_ve_fpga_reset_shift                                     (29)
#define  RIF_REG_VE_CTRL_dbg_out_sel1_shift                                      (22)
#define  RIF_REG_VE_CTRL_dbg_out_sel0_shift                                      (17)
#define  RIF_REG_VE_CTRL_dbg_out_en_shift                                        (16)
#define  RIF_REG_VE_CTRL_encode_en_shift                                         (8)
#define  RIF_REG_VE_CTRL_ve_soft_reset_shift                                     (7)
#define  RIF_REG_VE_CTRL_vm_idle_shift                                           (6)
#define  RIF_REG_VE_CTRL_decode_en_shift                                         (5)
#define  RIF_REG_VE_CTRL_haltVE_done_shift                                       (4)
#define  RIF_REG_VE_CTRL_HaltVE_shift                                            (3)
#define  RIF_REG_VE_CTRL_Veidle_shift                                            (2)
#define  RIF_REG_VE_CTRL_IntEn_shift                                             (1)
#define  RIF_REG_VE_CTRL_Reset_ptr_shift                                         (0)
#define  RIF_REG_VE_CTRL_ve_fpga_reset_mask                                      (0x20000000)
#define  RIF_REG_VE_CTRL_dbg_out_sel1_mask                                       (0x07C00000)
#define  RIF_REG_VE_CTRL_dbg_out_sel0_mask                                       (0x003E0000)
#define  RIF_REG_VE_CTRL_dbg_out_en_mask                                         (0x00010000)
#define  RIF_REG_VE_CTRL_encode_en_mask                                          (0x00000100)
#define  RIF_REG_VE_CTRL_ve_soft_reset_mask                                      (0x00000080)
#define  RIF_REG_VE_CTRL_vm_idle_mask                                            (0x00000040)
#define  RIF_REG_VE_CTRL_decode_en_mask                                          (0x00000020)
#define  RIF_REG_VE_CTRL_haltVE_done_mask                                        (0x00000010)
#define  RIF_REG_VE_CTRL_HaltVE_mask                                             (0x00000008)
#define  RIF_REG_VE_CTRL_Veidle_mask                                             (0x00000004)
#define  RIF_REG_VE_CTRL_IntEn_mask                                              (0x00000002)
#define  RIF_REG_VE_CTRL_Reset_ptr_mask                                          (0x00000001)
#define  RIF_REG_VE_CTRL_ve_fpga_reset(data)                                     (0x20000000&((data)<<29))
#define  RIF_REG_VE_CTRL_dbg_out_sel1(data)                                      (0x07C00000&((data)<<22))
#define  RIF_REG_VE_CTRL_dbg_out_sel0(data)                                      (0x003E0000&((data)<<17))
#define  RIF_REG_VE_CTRL_dbg_out_en(data)                                        (0x00010000&((data)<<16))
#define  RIF_REG_VE_CTRL_encode_en(data)                                         (0x00000100&((data)<<8))
#define  RIF_REG_VE_CTRL_ve_soft_reset(data)                                     (0x00000080&((data)<<7))
#define  RIF_REG_VE_CTRL_vm_idle(data)                                           (0x00000040&((data)<<6))
#define  RIF_REG_VE_CTRL_decode_en(data)                                         (0x00000020&((data)<<5))
#define  RIF_REG_VE_CTRL_haltVE_done(data)                                       (0x00000010&((data)<<4))
#define  RIF_REG_VE_CTRL_HaltVE(data)                                            (0x00000008&((data)<<3))
#define  RIF_REG_VE_CTRL_Veidle(data)                                            (0x00000004&((data)<<2))
#define  RIF_REG_VE_CTRL_IntEn(data)                                             (0x00000002&((data)<<1))
#define  RIF_REG_VE_CTRL_Reset_ptr(data)                                         (0x00000001&(data))
#define  RIF_REG_VE_CTRL_get_ve_fpga_reset(data)                                 ((0x20000000&(data))>>29)
#define  RIF_REG_VE_CTRL_get_dbg_out_sel1(data)                                  ((0x07C00000&(data))>>22)
#define  RIF_REG_VE_CTRL_get_dbg_out_sel0(data)                                  ((0x003E0000&(data))>>17)
#define  RIF_REG_VE_CTRL_get_dbg_out_en(data)                                    ((0x00010000&(data))>>16)
#define  RIF_REG_VE_CTRL_get_encode_en(data)                                     ((0x00000100&(data))>>8)
#define  RIF_REG_VE_CTRL_get_ve_soft_reset(data)                                 ((0x00000080&(data))>>7)
#define  RIF_REG_VE_CTRL_get_vm_idle(data)                                       ((0x00000040&(data))>>6)
#define  RIF_REG_VE_CTRL_get_decode_en(data)                                     ((0x00000020&(data))>>5)
#define  RIF_REG_VE_CTRL_get_haltVE_done(data)                                   ((0x00000010&(data))>>4)
#define  RIF_REG_VE_CTRL_get_HaltVE(data)                                        ((0x00000008&(data))>>3)
#define  RIF_REG_VE_CTRL_get_Veidle(data)                                        ((0x00000004&(data))>>2)
#define  RIF_REG_VE_CTRL_get_IntEn(data)                                         ((0x00000002&(data))>>1)
#define  RIF_REG_VE_CTRL_get_Reset_ptr(data)                                     (0x00000001&(data))
#define  RIF_REG_VE_CTRL_ve_fpga_reset_src(data)                                 ((0x20000000&(data))>>29)
#define  RIF_REG_VE_CTRL_dbg_out_sel1_src(data)                                  ((0x07C00000&(data))>>22)
#define  RIF_REG_VE_CTRL_dbg_out_sel0_src(data)                                  ((0x003E0000&(data))>>17)
#define  RIF_REG_VE_CTRL_dbg_out_en_src(data)                                    ((0x00010000&(data))>>16)
#define  RIF_REG_VE_CTRL_encode_en_src(data)                                     ((0x00000100&(data))>>8)
#define  RIF_REG_VE_CTRL_ve_soft_reset_src(data)                                 ((0x00000080&(data))>>7)
#define  RIF_REG_VE_CTRL_vm_idle_src(data)                                       ((0x00000040&(data))>>6)
#define  RIF_REG_VE_CTRL_decode_en_src(data)                                     ((0x00000020&(data))>>5)
#define  RIF_REG_VE_CTRL_haltVE_done_src(data)                                   ((0x00000010&(data))>>4)
#define  RIF_REG_VE_CTRL_HaltVE_src(data)                                        ((0x00000008&(data))>>3)
#define  RIF_REG_VE_CTRL_Veidle_src(data)                                        ((0x00000004&(data))>>2)
#define  RIF_REG_VE_CTRL_IntEn_src(data)                                         ((0x00000002&(data))>>1)
#define  RIF_REG_VE_CTRL_Reset_ptr_src(data)                                     (0x00000001&(data))

#define  RIF_REG_VE_INT_STATUS                                                   0x1800E404
#define  RIF_REG_VE_INT_STATUS_reg_addr                                          "0xB800E404"
#define  RIF_REG_VE_INT_STATUS_reg                                               0xB800E404
#define  RIF_REG_VE_INT_STATUS_inst_addr                                         "0x0001"
#define  RIF_REG_VE_INT_STATUS_inst_adr                                          "0x0001"
#define  RIF_REG_VE_INT_STATUS_inst                                              0x0001
#define  set_RIF_REG_VE_INT_STATUS_reg(data)                                     (*((volatile unsigned int*)RIF_REG_VE_INT_STATUS_reg)=data)
#define  get_RIF_REG_VE_INT_STATUS_reg                                           (*((volatile unsigned int*)RIF_REG_VE_INT_STATUS_reg))
#define  RIF_REG_VE_INT_STATUS_first_error_b4_shift                              (28)
#define  RIF_REG_VE_INT_STATUS_first_error_b3_shift                              (27)
#define  RIF_REG_VE_INT_STATUS_first_error_b2_shift                              (26)
#define  RIF_REG_VE_INT_STATUS_first_error_b1_shift                              (25)
#define  RIF_REG_VE_INT_STATUS_first_error_b0_shift                              (24)
#define  RIF_REG_VE_INT_STATUS_dcomp_core_irq_shift                              (22)
#define  RIF_REG_VE_INT_STATUS_comp_core_irq_shift                               (21)
#define  RIF_REG_VE_INT_STATUS_hevc_p3_hang_int_shift                            (20)
#define  RIF_REG_VE_INT_STATUS_hevc_dec_done_int_shift                           (19)
#define  RIF_REG_VE_INT_STATUS_ime_int_shift                                     (18)
#define  RIF_REG_VE_INT_STATUS_ipmd_err_shift                                    (17)
#define  RIF_REG_VE_INT_STATUS_gc_err_shift                                      (16)
#define  RIF_REG_VE_INT_STATUS_cmd_fifo_full_int_shift                           (15)
#define  RIF_REG_VE_INT_STATUS_rd_rslt_hang_int_shift                            (14)
#define  RIF_REG_VE_INT_STATUS_rl_hang_int_shift                                 (13)
#define  RIF_REG_VE_INT_STATUS_pred_hang_int_shift                               (12)
#define  RIF_REG_VE_INT_STATUS_mb_last_int_shift                                 (11)
#define  RIF_REG_VE_INT_STATUS_mvd_vc1_intfd_err_shift                           (10)
#define  RIF_REG_VE_INT_STATUS_mvd_h264_direct_err_shift                         (9)
#define  RIF_REG_VE_INT_STATUS_mvd_h264_mv_err_shift                             (8)
#define  RIF_REG_VE_INT_STATUS_bs2_fifo_err_shift                                (7)
#define  RIF_REG_VE_INT_STATUS_m64coeff_shift                                    (6)
#define  RIF_REG_VE_INT_STATUS_rstff_oflow_shift                                 (5)
#define  RIF_REG_VE_INT_STATUS_rstff_empty_shift                                 (4)
#define  RIF_REG_VE_INT_STATUS_bitst_fifo_shift                                  (3)
#define  RIF_REG_VE_INT_STATUS_scode_limit_shift                                 (2)
#define  RIF_REG_VE_INT_STATUS_dec_err_shift                                     (1)
#define  RIF_REG_VE_INT_STATUS_write_data_shift                                  (0)
#define  RIF_REG_VE_INT_STATUS_first_error_b4_mask                               (0x10000000)
#define  RIF_REG_VE_INT_STATUS_first_error_b3_mask                               (0x08000000)
#define  RIF_REG_VE_INT_STATUS_first_error_b2_mask                               (0x04000000)
#define  RIF_REG_VE_INT_STATUS_first_error_b1_mask                               (0x02000000)
#define  RIF_REG_VE_INT_STATUS_first_error_b0_mask                               (0x01000000)
#define  RIF_REG_VE_INT_STATUS_dcomp_core_irq_mask                               (0x00400000)
#define  RIF_REG_VE_INT_STATUS_comp_core_irq_mask                                (0x00200000)
#define  RIF_REG_VE_INT_STATUS_hevc_p3_hang_int_mask                             (0x00100000)
#define  RIF_REG_VE_INT_STATUS_hevc_dec_done_int_mask                            (0x00080000)
#define  RIF_REG_VE_INT_STATUS_ime_int_mask                                      (0x00040000)
#define  RIF_REG_VE_INT_STATUS_ipmd_err_mask                                     (0x00020000)
#define  RIF_REG_VE_INT_STATUS_gc_err_mask                                       (0x00010000)
#define  RIF_REG_VE_INT_STATUS_cmd_fifo_full_int_mask                            (0x00008000)
#define  RIF_REG_VE_INT_STATUS_rd_rslt_hang_int_mask                             (0x00004000)
#define  RIF_REG_VE_INT_STATUS_rl_hang_int_mask                                  (0x00002000)
#define  RIF_REG_VE_INT_STATUS_pred_hang_int_mask                                (0x00001000)
#define  RIF_REG_VE_INT_STATUS_mb_last_int_mask                                  (0x00000800)
#define  RIF_REG_VE_INT_STATUS_mvd_vc1_intfd_err_mask                            (0x00000400)
#define  RIF_REG_VE_INT_STATUS_mvd_h264_direct_err_mask                          (0x00000200)
#define  RIF_REG_VE_INT_STATUS_mvd_h264_mv_err_mask                              (0x00000100)
#define  RIF_REG_VE_INT_STATUS_bs2_fifo_err_mask                                 (0x00000080)
#define  RIF_REG_VE_INT_STATUS_m64coeff_mask                                     (0x00000040)
#define  RIF_REG_VE_INT_STATUS_rstff_oflow_mask                                  (0x00000020)
#define  RIF_REG_VE_INT_STATUS_rstff_empty_mask                                  (0x00000010)
#define  RIF_REG_VE_INT_STATUS_bitst_fifo_mask                                   (0x00000008)
#define  RIF_REG_VE_INT_STATUS_scode_limit_mask                                  (0x00000004)
#define  RIF_REG_VE_INT_STATUS_dec_err_mask                                      (0x00000002)
#define  RIF_REG_VE_INT_STATUS_write_data_mask                                   (0x00000001)
#define  RIF_REG_VE_INT_STATUS_first_error_b4(data)                              (0x10000000&((data)<<28))
#define  RIF_REG_VE_INT_STATUS_first_error_b3(data)                              (0x08000000&((data)<<27))
#define  RIF_REG_VE_INT_STATUS_first_error_b2(data)                              (0x04000000&((data)<<26))
#define  RIF_REG_VE_INT_STATUS_first_error_b1(data)                              (0x02000000&((data)<<25))
#define  RIF_REG_VE_INT_STATUS_first_error_b0(data)                              (0x01000000&((data)<<24))
#define  RIF_REG_VE_INT_STATUS_dcomp_core_irq(data)                              (0x00400000&((data)<<22))
#define  RIF_REG_VE_INT_STATUS_comp_core_irq(data)                               (0x00200000&((data)<<21))
#define  RIF_REG_VE_INT_STATUS_hevc_p3_hang_int(data)                            (0x00100000&((data)<<20))
#define  RIF_REG_VE_INT_STATUS_hevc_dec_done_int(data)                           (0x00080000&((data)<<19))
#define  RIF_REG_VE_INT_STATUS_ime_int(data)                                     (0x00040000&((data)<<18))
#define  RIF_REG_VE_INT_STATUS_ipmd_err(data)                                    (0x00020000&((data)<<17))
#define  RIF_REG_VE_INT_STATUS_gc_err(data)                                      (0x00010000&((data)<<16))
#define  RIF_REG_VE_INT_STATUS_cmd_fifo_full_int(data)                           (0x00008000&((data)<<15))
#define  RIF_REG_VE_INT_STATUS_rd_rslt_hang_int(data)                            (0x00004000&((data)<<14))
#define  RIF_REG_VE_INT_STATUS_rl_hang_int(data)                                 (0x00002000&((data)<<13))
#define  RIF_REG_VE_INT_STATUS_pred_hang_int(data)                               (0x00001000&((data)<<12))
#define  RIF_REG_VE_INT_STATUS_mb_last_int(data)                                 (0x00000800&((data)<<11))
#define  RIF_REG_VE_INT_STATUS_mvd_vc1_intfd_err(data)                           (0x00000400&((data)<<10))
#define  RIF_REG_VE_INT_STATUS_mvd_h264_direct_err(data)                         (0x00000200&((data)<<9))
#define  RIF_REG_VE_INT_STATUS_mvd_h264_mv_err(data)                             (0x00000100&((data)<<8))
#define  RIF_REG_VE_INT_STATUS_bs2_fifo_err(data)                                (0x00000080&((data)<<7))
#define  RIF_REG_VE_INT_STATUS_m64coeff(data)                                    (0x00000040&((data)<<6))
#define  RIF_REG_VE_INT_STATUS_rstff_oflow(data)                                 (0x00000020&((data)<<5))
#define  RIF_REG_VE_INT_STATUS_rstff_empty(data)                                 (0x00000010&((data)<<4))
#define  RIF_REG_VE_INT_STATUS_bitst_fifo(data)                                  (0x00000008&((data)<<3))
#define  RIF_REG_VE_INT_STATUS_scode_limit(data)                                 (0x00000004&((data)<<2))
#define  RIF_REG_VE_INT_STATUS_dec_err(data)                                     (0x00000002&((data)<<1))
#define  RIF_REG_VE_INT_STATUS_write_data(data)                                  (0x00000001&(data))
#define  RIF_REG_VE_INT_STATUS_get_first_error_b4(data)                          ((0x10000000&(data))>>28)
#define  RIF_REG_VE_INT_STATUS_get_first_error_b3(data)                          ((0x08000000&(data))>>27)
#define  RIF_REG_VE_INT_STATUS_get_first_error_b2(data)                          ((0x04000000&(data))>>26)
#define  RIF_REG_VE_INT_STATUS_get_first_error_b1(data)                          ((0x02000000&(data))>>25)
#define  RIF_REG_VE_INT_STATUS_get_first_error_b0(data)                          ((0x01000000&(data))>>24)
#define  RIF_REG_VE_INT_STATUS_get_dcomp_core_irq(data)                          ((0x00400000&(data))>>22)
#define  RIF_REG_VE_INT_STATUS_get_comp_core_irq(data)                           ((0x00200000&(data))>>21)
#define  RIF_REG_VE_INT_STATUS_get_hevc_p3_hang_int(data)                        ((0x00100000&(data))>>20)
#define  RIF_REG_VE_INT_STATUS_get_hevc_dec_done_int(data)                       ((0x00080000&(data))>>19)
#define  RIF_REG_VE_INT_STATUS_get_ime_int(data)                                 ((0x00040000&(data))>>18)
#define  RIF_REG_VE_INT_STATUS_get_ipmd_err(data)                                ((0x00020000&(data))>>17)
#define  RIF_REG_VE_INT_STATUS_get_gc_err(data)                                  ((0x00010000&(data))>>16)
#define  RIF_REG_VE_INT_STATUS_get_cmd_fifo_full_int(data)                       ((0x00008000&(data))>>15)
#define  RIF_REG_VE_INT_STATUS_get_rd_rslt_hang_int(data)                        ((0x00004000&(data))>>14)
#define  RIF_REG_VE_INT_STATUS_get_rl_hang_int(data)                             ((0x00002000&(data))>>13)
#define  RIF_REG_VE_INT_STATUS_get_pred_hang_int(data)                           ((0x00001000&(data))>>12)
#define  RIF_REG_VE_INT_STATUS_get_mb_last_int(data)                             ((0x00000800&(data))>>11)
#define  RIF_REG_VE_INT_STATUS_get_mvd_vc1_intfd_err(data)                       ((0x00000400&(data))>>10)
#define  RIF_REG_VE_INT_STATUS_get_mvd_h264_direct_err(data)                     ((0x00000200&(data))>>9)
#define  RIF_REG_VE_INT_STATUS_get_mvd_h264_mv_err(data)                         ((0x00000100&(data))>>8)
#define  RIF_REG_VE_INT_STATUS_get_bs2_fifo_err(data)                            ((0x00000080&(data))>>7)
#define  RIF_REG_VE_INT_STATUS_get_m64coeff(data)                                ((0x00000040&(data))>>6)
#define  RIF_REG_VE_INT_STATUS_get_rstff_oflow(data)                             ((0x00000020&(data))>>5)
#define  RIF_REG_VE_INT_STATUS_get_rstff_empty(data)                             ((0x00000010&(data))>>4)
#define  RIF_REG_VE_INT_STATUS_get_bitst_fifo(data)                              ((0x00000008&(data))>>3)
#define  RIF_REG_VE_INT_STATUS_get_scode_limit(data)                             ((0x00000004&(data))>>2)
#define  RIF_REG_VE_INT_STATUS_get_dec_err(data)                                 ((0x00000002&(data))>>1)
#define  RIF_REG_VE_INT_STATUS_get_write_data(data)                              (0x00000001&(data))
#define  RIF_REG_VE_INT_STATUS_first_error_b4_src(data)                          ((0x10000000&(data))>>28)
#define  RIF_REG_VE_INT_STATUS_first_error_b3_src(data)                          ((0x08000000&(data))>>27)
#define  RIF_REG_VE_INT_STATUS_first_error_b2_src(data)                          ((0x04000000&(data))>>26)
#define  RIF_REG_VE_INT_STATUS_first_error_b1_src(data)                          ((0x02000000&(data))>>25)
#define  RIF_REG_VE_INT_STATUS_first_error_b0_src(data)                          ((0x01000000&(data))>>24)
#define  RIF_REG_VE_INT_STATUS_dcomp_core_irq_src(data)                          ((0x00400000&(data))>>22)
#define  RIF_REG_VE_INT_STATUS_comp_core_irq_src(data)                           ((0x00200000&(data))>>21)
#define  RIF_REG_VE_INT_STATUS_hevc_p3_hang_int_src(data)                        ((0x00100000&(data))>>20)
#define  RIF_REG_VE_INT_STATUS_hevc_dec_done_int_src(data)                       ((0x00080000&(data))>>19)
#define  RIF_REG_VE_INT_STATUS_ime_int_src(data)                                 ((0x00040000&(data))>>18)
#define  RIF_REG_VE_INT_STATUS_ipmd_err_src(data)                                ((0x00020000&(data))>>17)
#define  RIF_REG_VE_INT_STATUS_gc_err_src(data)                                  ((0x00010000&(data))>>16)
#define  RIF_REG_VE_INT_STATUS_cmd_fifo_full_int_src(data)                       ((0x00008000&(data))>>15)
#define  RIF_REG_VE_INT_STATUS_rd_rslt_hang_int_src(data)                        ((0x00004000&(data))>>14)
#define  RIF_REG_VE_INT_STATUS_rl_hang_int_src(data)                             ((0x00002000&(data))>>13)
#define  RIF_REG_VE_INT_STATUS_pred_hang_int_src(data)                           ((0x00001000&(data))>>12)
#define  RIF_REG_VE_INT_STATUS_mb_last_int_src(data)                             ((0x00000800&(data))>>11)
#define  RIF_REG_VE_INT_STATUS_mvd_vc1_intfd_err_src(data)                       ((0x00000400&(data))>>10)
#define  RIF_REG_VE_INT_STATUS_mvd_h264_direct_err_src(data)                     ((0x00000200&(data))>>9)
#define  RIF_REG_VE_INT_STATUS_mvd_h264_mv_err_src(data)                         ((0x00000100&(data))>>8)
#define  RIF_REG_VE_INT_STATUS_bs2_fifo_err_src(data)                            ((0x00000080&(data))>>7)
#define  RIF_REG_VE_INT_STATUS_m64coeff_src(data)                                ((0x00000040&(data))>>6)
#define  RIF_REG_VE_INT_STATUS_rstff_oflow_src(data)                             ((0x00000020&(data))>>5)
#define  RIF_REG_VE_INT_STATUS_rstff_empty_src(data)                             ((0x00000010&(data))>>4)
#define  RIF_REG_VE_INT_STATUS_bitst_fifo_src(data)                              ((0x00000008&(data))>>3)
#define  RIF_REG_VE_INT_STATUS_scode_limit_src(data)                             ((0x00000004&(data))>>2)
#define  RIF_REG_VE_INT_STATUS_dec_err_src(data)                                 ((0x00000002&(data))>>1)
#define  RIF_REG_VE_INT_STATUS_write_data_src(data)                              (0x00000001&(data))

#define  RIF_REG_VE_INT_EN                                                       0x1800E408
#define  RIF_REG_VE_INT_EN_reg_addr                                              "0xB800E408"
#define  RIF_REG_VE_INT_EN_reg                                                   0xB800E408
#define  RIF_REG_VE_INT_EN_inst_addr                                             "0x0002"
#define  RIF_REG_VE_INT_EN_inst_adr                                              "0x0002"
#define  RIF_REG_VE_INT_EN_inst                                                  0x0002
#define  set_RIF_REG_VE_INT_EN_reg(data)                                         (*((volatile unsigned int*)RIF_REG_VE_INT_EN_reg)=data)
#define  get_RIF_REG_VE_INT_EN_reg                                               (*((volatile unsigned int*)RIF_REG_VE_INT_EN_reg))
#define  RIF_REG_VE_INT_EN_dcomp_core_irq_ie_shift                               (24)
#define  RIF_REG_VE_INT_EN_comp_core_irq_ie_shift                                (23)
#define  RIF_REG_VE_INT_EN_hevc_p3_hang_int_ie_shift                             (22)
#define  RIF_REG_VE_INT_EN_hevc_dec_done_int_ie_shift                            (21)
#define  RIF_REG_VE_INT_EN_gc_interrupt_on_shift                                 (20)
#define  RIF_REG_VE_INT_EN_ipmd_interrupt_on_shift                               (19)
#define  RIF_REG_VE_INT_EN_ime_int_ie_shift                                      (18)
#define  RIF_REG_VE_INT_EN_ipmd_err_ie_shift                                     (17)
#define  RIF_REG_VE_INT_EN_gc_err_ie_shift                                       (16)
#define  RIF_REG_VE_INT_EN_cmd_fifo_full_int_ie_shift                            (15)
#define  RIF_REG_VE_INT_EN_rd_rslt_hang_int_ie_shift                             (14)
#define  RIF_REG_VE_INT_EN_rl_hang_int_ie_shift                                  (13)
#define  RIF_REG_VE_INT_EN_pred_hang_int_ie_shift                                (12)
#define  RIF_REG_VE_INT_EN_mb_last_int_ie_shift                                  (11)
#define  RIF_REG_VE_INT_EN_mvd_vc1_intfd_ie_shift                                (10)
#define  RIF_REG_VE_INT_EN_mvd_h264_direct_ie_shift                              (9)
#define  RIF_REG_VE_INT_EN_mvd_h264_mv_ie_shift                                  (8)
#define  RIF_REG_VE_INT_EN_bs2_fifo_err_ie_shift                                 (7)
#define  RIF_REG_VE_INT_EN_m64coeff_ie_shift                                     (6)
#define  RIF_REG_VE_INT_EN_rstff_oflow_ie_shift                                  (5)
#define  RIF_REG_VE_INT_EN_rstff_empty_ie_shift                                  (4)
#define  RIF_REG_VE_INT_EN_bitst_fifo_ie_shift                                   (3)
#define  RIF_REG_VE_INT_EN_scode_limit_ie_shift                                  (2)
#define  RIF_REG_VE_INT_EN_dec_err_ie_shift                                      (1)
#define  RIF_REG_VE_INT_EN_write_data_shift                                      (0)
#define  RIF_REG_VE_INT_EN_dcomp_core_irq_ie_mask                                (0x01000000)
#define  RIF_REG_VE_INT_EN_comp_core_irq_ie_mask                                 (0x00800000)
#define  RIF_REG_VE_INT_EN_hevc_p3_hang_int_ie_mask                              (0x00400000)
#define  RIF_REG_VE_INT_EN_hevc_dec_done_int_ie_mask                             (0x00200000)
#define  RIF_REG_VE_INT_EN_gc_interrupt_on_mask                                  (0x00100000)
#define  RIF_REG_VE_INT_EN_ipmd_interrupt_on_mask                                (0x00080000)
#define  RIF_REG_VE_INT_EN_ime_int_ie_mask                                       (0x00040000)
#define  RIF_REG_VE_INT_EN_ipmd_err_ie_mask                                      (0x00020000)
#define  RIF_REG_VE_INT_EN_gc_err_ie_mask                                        (0x00010000)
#define  RIF_REG_VE_INT_EN_cmd_fifo_full_int_ie_mask                             (0x00008000)
#define  RIF_REG_VE_INT_EN_rd_rslt_hang_int_ie_mask                              (0x00004000)
#define  RIF_REG_VE_INT_EN_rl_hang_int_ie_mask                                   (0x00002000)
#define  RIF_REG_VE_INT_EN_pred_hang_int_ie_mask                                 (0x00001000)
#define  RIF_REG_VE_INT_EN_mb_last_int_ie_mask                                   (0x00000800)
#define  RIF_REG_VE_INT_EN_mvd_vc1_intfd_ie_mask                                 (0x00000400)
#define  RIF_REG_VE_INT_EN_mvd_h264_direct_ie_mask                               (0x00000200)
#define  RIF_REG_VE_INT_EN_mvd_h264_mv_ie_mask                                   (0x00000100)
#define  RIF_REG_VE_INT_EN_bs2_fifo_err_ie_mask                                  (0x00000080)
#define  RIF_REG_VE_INT_EN_m64coeff_ie_mask                                      (0x00000040)
#define  RIF_REG_VE_INT_EN_rstff_oflow_ie_mask                                   (0x00000020)
#define  RIF_REG_VE_INT_EN_rstff_empty_ie_mask                                   (0x00000010)
#define  RIF_REG_VE_INT_EN_bitst_fifo_ie_mask                                    (0x00000008)
#define  RIF_REG_VE_INT_EN_scode_limit_ie_mask                                   (0x00000004)
#define  RIF_REG_VE_INT_EN_dec_err_ie_mask                                       (0x00000002)
#define  RIF_REG_VE_INT_EN_write_data_mask                                       (0x00000001)
#define  RIF_REG_VE_INT_EN_dcomp_core_irq_ie(data)                               (0x01000000&((data)<<24))
#define  RIF_REG_VE_INT_EN_comp_core_irq_ie(data)                                (0x00800000&((data)<<23))
#define  RIF_REG_VE_INT_EN_hevc_p3_hang_int_ie(data)                             (0x00400000&((data)<<22))
#define  RIF_REG_VE_INT_EN_hevc_dec_done_int_ie(data)                            (0x00200000&((data)<<21))
#define  RIF_REG_VE_INT_EN_gc_interrupt_on(data)                                 (0x00100000&((data)<<20))
#define  RIF_REG_VE_INT_EN_ipmd_interrupt_on(data)                               (0x00080000&((data)<<19))
#define  RIF_REG_VE_INT_EN_ime_int_ie(data)                                      (0x00040000&((data)<<18))
#define  RIF_REG_VE_INT_EN_ipmd_err_ie(data)                                     (0x00020000&((data)<<17))
#define  RIF_REG_VE_INT_EN_gc_err_ie(data)                                       (0x00010000&((data)<<16))
#define  RIF_REG_VE_INT_EN_cmd_fifo_full_int_ie(data)                            (0x00008000&((data)<<15))
#define  RIF_REG_VE_INT_EN_rd_rslt_hang_int_ie(data)                             (0x00004000&((data)<<14))
#define  RIF_REG_VE_INT_EN_rl_hang_int_ie(data)                                  (0x00002000&((data)<<13))
#define  RIF_REG_VE_INT_EN_pred_hang_int_ie(data)                                (0x00001000&((data)<<12))
#define  RIF_REG_VE_INT_EN_mb_last_int_ie(data)                                  (0x00000800&((data)<<11))
#define  RIF_REG_VE_INT_EN_mvd_vc1_intfd_ie(data)                                (0x00000400&((data)<<10))
#define  RIF_REG_VE_INT_EN_mvd_h264_direct_ie(data)                              (0x00000200&((data)<<9))
#define  RIF_REG_VE_INT_EN_mvd_h264_mv_ie(data)                                  (0x00000100&((data)<<8))
#define  RIF_REG_VE_INT_EN_bs2_fifo_err_ie(data)                                 (0x00000080&((data)<<7))
#define  RIF_REG_VE_INT_EN_m64coeff_ie(data)                                     (0x00000040&((data)<<6))
#define  RIF_REG_VE_INT_EN_rstff_oflow_ie(data)                                  (0x00000020&((data)<<5))
#define  RIF_REG_VE_INT_EN_rstff_empty_ie(data)                                  (0x00000010&((data)<<4))
#define  RIF_REG_VE_INT_EN_bitst_fifo_ie(data)                                   (0x00000008&((data)<<3))
#define  RIF_REG_VE_INT_EN_scode_limit_ie(data)                                  (0x00000004&((data)<<2))
#define  RIF_REG_VE_INT_EN_dec_err_ie(data)                                      (0x00000002&((data)<<1))
#define  RIF_REG_VE_INT_EN_write_data(data)                                      (0x00000001&(data))
#define  RIF_REG_VE_INT_EN_get_dcomp_core_irq_ie(data)                           ((0x01000000&(data))>>24)
#define  RIF_REG_VE_INT_EN_get_comp_core_irq_ie(data)                            ((0x00800000&(data))>>23)
#define  RIF_REG_VE_INT_EN_get_hevc_p3_hang_int_ie(data)                         ((0x00400000&(data))>>22)
#define  RIF_REG_VE_INT_EN_get_hevc_dec_done_int_ie(data)                        ((0x00200000&(data))>>21)
#define  RIF_REG_VE_INT_EN_get_gc_interrupt_on(data)                             ((0x00100000&(data))>>20)
#define  RIF_REG_VE_INT_EN_get_ipmd_interrupt_on(data)                           ((0x00080000&(data))>>19)
#define  RIF_REG_VE_INT_EN_get_ime_int_ie(data)                                  ((0x00040000&(data))>>18)
#define  RIF_REG_VE_INT_EN_get_ipmd_err_ie(data)                                 ((0x00020000&(data))>>17)
#define  RIF_REG_VE_INT_EN_get_gc_err_ie(data)                                   ((0x00010000&(data))>>16)
#define  RIF_REG_VE_INT_EN_get_cmd_fifo_full_int_ie(data)                        ((0x00008000&(data))>>15)
#define  RIF_REG_VE_INT_EN_get_rd_rslt_hang_int_ie(data)                         ((0x00004000&(data))>>14)
#define  RIF_REG_VE_INT_EN_get_rl_hang_int_ie(data)                              ((0x00002000&(data))>>13)
#define  RIF_REG_VE_INT_EN_get_pred_hang_int_ie(data)                            ((0x00001000&(data))>>12)
#define  RIF_REG_VE_INT_EN_get_mb_last_int_ie(data)                              ((0x00000800&(data))>>11)
#define  RIF_REG_VE_INT_EN_get_mvd_vc1_intfd_ie(data)                            ((0x00000400&(data))>>10)
#define  RIF_REG_VE_INT_EN_get_mvd_h264_direct_ie(data)                          ((0x00000200&(data))>>9)
#define  RIF_REG_VE_INT_EN_get_mvd_h264_mv_ie(data)                              ((0x00000100&(data))>>8)
#define  RIF_REG_VE_INT_EN_get_bs2_fifo_err_ie(data)                             ((0x00000080&(data))>>7)
#define  RIF_REG_VE_INT_EN_get_m64coeff_ie(data)                                 ((0x00000040&(data))>>6)
#define  RIF_REG_VE_INT_EN_get_rstff_oflow_ie(data)                              ((0x00000020&(data))>>5)
#define  RIF_REG_VE_INT_EN_get_rstff_empty_ie(data)                              ((0x00000010&(data))>>4)
#define  RIF_REG_VE_INT_EN_get_bitst_fifo_ie(data)                               ((0x00000008&(data))>>3)
#define  RIF_REG_VE_INT_EN_get_scode_limit_ie(data)                              ((0x00000004&(data))>>2)
#define  RIF_REG_VE_INT_EN_get_dec_err_ie(data)                                  ((0x00000002&(data))>>1)
#define  RIF_REG_VE_INT_EN_get_write_data(data)                                  (0x00000001&(data))
#define  RIF_REG_VE_INT_EN_dcomp_core_irq_ie_src(data)                           ((0x01000000&(data))>>24)
#define  RIF_REG_VE_INT_EN_comp_core_irq_ie_src(data)                            ((0x00800000&(data))>>23)
#define  RIF_REG_VE_INT_EN_hevc_p3_hang_int_ie_src(data)                         ((0x00400000&(data))>>22)
#define  RIF_REG_VE_INT_EN_hevc_dec_done_int_ie_src(data)                        ((0x00200000&(data))>>21)
#define  RIF_REG_VE_INT_EN_gc_interrupt_on_src(data)                             ((0x00100000&(data))>>20)
#define  RIF_REG_VE_INT_EN_ipmd_interrupt_on_src(data)                           ((0x00080000&(data))>>19)
#define  RIF_REG_VE_INT_EN_ime_int_ie_src(data)                                  ((0x00040000&(data))>>18)
#define  RIF_REG_VE_INT_EN_ipmd_err_ie_src(data)                                 ((0x00020000&(data))>>17)
#define  RIF_REG_VE_INT_EN_gc_err_ie_src(data)                                   ((0x00010000&(data))>>16)
#define  RIF_REG_VE_INT_EN_cmd_fifo_full_int_ie_src(data)                        ((0x00008000&(data))>>15)
#define  RIF_REG_VE_INT_EN_rd_rslt_hang_int_ie_src(data)                         ((0x00004000&(data))>>14)
#define  RIF_REG_VE_INT_EN_rl_hang_int_ie_src(data)                              ((0x00002000&(data))>>13)
#define  RIF_REG_VE_INT_EN_pred_hang_int_ie_src(data)                            ((0x00001000&(data))>>12)
#define  RIF_REG_VE_INT_EN_mb_last_int_ie_src(data)                              ((0x00000800&(data))>>11)
#define  RIF_REG_VE_INT_EN_mvd_vc1_intfd_ie_src(data)                            ((0x00000400&(data))>>10)
#define  RIF_REG_VE_INT_EN_mvd_h264_direct_ie_src(data)                          ((0x00000200&(data))>>9)
#define  RIF_REG_VE_INT_EN_mvd_h264_mv_ie_src(data)                              ((0x00000100&(data))>>8)
#define  RIF_REG_VE_INT_EN_bs2_fifo_err_ie_src(data)                             ((0x00000080&(data))>>7)
#define  RIF_REG_VE_INT_EN_m64coeff_ie_src(data)                                 ((0x00000040&(data))>>6)
#define  RIF_REG_VE_INT_EN_rstff_oflow_ie_src(data)                              ((0x00000020&(data))>>5)
#define  RIF_REG_VE_INT_EN_rstff_empty_ie_src(data)                              ((0x00000010&(data))>>4)
#define  RIF_REG_VE_INT_EN_bitst_fifo_ie_src(data)                               ((0x00000008&(data))>>3)
#define  RIF_REG_VE_INT_EN_scode_limit_ie_src(data)                              ((0x00000004&(data))>>2)
#define  RIF_REG_VE_INT_EN_dec_err_ie_src(data)                                  ((0x00000002&(data))>>1)
#define  RIF_REG_VE_INT_EN_write_data_src(data)                                  (0x00000001&(data))

#define  RIF_REG_VE_FIFOSTATUS                                                   0x1800E410
#define  RIF_REG_VE_FIFOSTATUS_reg_addr                                          "0xB800E410"
#define  RIF_REG_VE_FIFOSTATUS_reg                                               0xB800E410
#define  RIF_REG_VE_FIFOSTATUS_inst_addr                                         "0x0003"
#define  RIF_REG_VE_FIFOSTATUS_inst_adr                                          "0x0004"
#define  RIF_REG_VE_FIFOSTATUS_inst                                              0x0004
#define  set_RIF_REG_VE_FIFOSTATUS_reg(data)                                     (*((volatile unsigned int*)RIF_REG_VE_FIFOSTATUS_reg)=data)
#define  get_RIF_REG_VE_FIFOSTATUS_reg                                           (*((volatile unsigned int*)RIF_REG_VE_FIFOSTATUS_reg))
#define  RIF_REG_VE_FIFOSTATUS_debk_inst_cnt_shift                               (24)
#define  RIF_REG_VE_FIFOSTATUS_pred_inst_cnt_shift                               (16)
#define  RIF_REG_VE_FIFOSTATUS_dmab_inst_cnt_shift                               (8)
#define  RIF_REG_VE_FIFOSTATUS_dmaa_inst_cnt_shift                               (0)
#define  RIF_REG_VE_FIFOSTATUS_debk_inst_cnt_mask                                (0x3F000000)
#define  RIF_REG_VE_FIFOSTATUS_pred_inst_cnt_mask                                (0x003F0000)
#define  RIF_REG_VE_FIFOSTATUS_dmab_inst_cnt_mask                                (0x00003F00)
#define  RIF_REG_VE_FIFOSTATUS_dmaa_inst_cnt_mask                                (0x0000003F)
#define  RIF_REG_VE_FIFOSTATUS_debk_inst_cnt(data)                               (0x3F000000&((data)<<24))
#define  RIF_REG_VE_FIFOSTATUS_pred_inst_cnt(data)                               (0x003F0000&((data)<<16))
#define  RIF_REG_VE_FIFOSTATUS_dmab_inst_cnt(data)                               (0x00003F00&((data)<<8))
#define  RIF_REG_VE_FIFOSTATUS_dmaa_inst_cnt(data)                               (0x0000003F&(data))
#define  RIF_REG_VE_FIFOSTATUS_get_debk_inst_cnt(data)                           ((0x3F000000&(data))>>24)
#define  RIF_REG_VE_FIFOSTATUS_get_pred_inst_cnt(data)                           ((0x003F0000&(data))>>16)
#define  RIF_REG_VE_FIFOSTATUS_get_dmab_inst_cnt(data)                           ((0x00003F00&(data))>>8)
#define  RIF_REG_VE_FIFOSTATUS_get_dmaa_inst_cnt(data)                           (0x0000003F&(data))
#define  RIF_REG_VE_FIFOSTATUS_debk_inst_cnt_src(data)                           ((0x3F000000&(data))>>24)
#define  RIF_REG_VE_FIFOSTATUS_pred_inst_cnt_src(data)                           ((0x003F0000&(data))>>16)
#define  RIF_REG_VE_FIFOSTATUS_dmab_inst_cnt_src(data)                           ((0x00003F00&(data))>>8)
#define  RIF_REG_VE_FIFOSTATUS_dmaa_inst_cnt_src(data)                           (0x0000003F&(data))

#define  RIF_REG_VE_FIFOSTAT2                                                    0x1800E414
#define  RIF_REG_VE_FIFOSTAT2_reg_addr                                           "0xB800E414"
#define  RIF_REG_VE_FIFOSTAT2_reg                                                0xB800E414
#define  RIF_REG_VE_FIFOSTAT2_inst_addr                                          "0x0004"
#define  RIF_REG_VE_FIFOSTAT2_inst_adr                                           "0x0005"
#define  RIF_REG_VE_FIFOSTAT2_inst                                               0x0005
#define  set_RIF_REG_VE_FIFOSTAT2_reg(data)                                      (*((volatile unsigned int*)RIF_REG_VE_FIFOSTAT2_reg)=data)
#define  get_RIF_REG_VE_FIFOSTAT2_reg                                            (*((volatile unsigned int*)RIF_REG_VE_FIFOSTAT2_reg))
#define  RIF_REG_VE_FIFOSTAT2_act_rslt_in_fifo_shift                             (27)
#define  RIF_REG_VE_FIFOSTAT2_rslt_fifo_cnt_shift                                (22)
#define  RIF_REG_VE_FIFOSTAT2_img_fifo_cnt_shift                                 (16)
#define  RIF_REG_VE_FIFOSTAT2_dec_inst_cnt_shift                                 (8)
#define  RIF_REG_VE_FIFOSTAT2_act_rslt_in_fifo_mask                              (0xF8000000)
#define  RIF_REG_VE_FIFOSTAT2_rslt_fifo_cnt_mask                                 (0x07C00000)
#define  RIF_REG_VE_FIFOSTAT2_img_fifo_cnt_mask                                  (0x003F0000)
#define  RIF_REG_VE_FIFOSTAT2_dec_inst_cnt_mask                                  (0x00003F00)
#define  RIF_REG_VE_FIFOSTAT2_act_rslt_in_fifo(data)                             (0xF8000000&((data)<<27))
#define  RIF_REG_VE_FIFOSTAT2_rslt_fifo_cnt(data)                                (0x07C00000&((data)<<22))
#define  RIF_REG_VE_FIFOSTAT2_img_fifo_cnt(data)                                 (0x003F0000&((data)<<16))
#define  RIF_REG_VE_FIFOSTAT2_dec_inst_cnt(data)                                 (0x00003F00&((data)<<8))
#define  RIF_REG_VE_FIFOSTAT2_get_act_rslt_in_fifo(data)                         ((0xF8000000&(data))>>27)
#define  RIF_REG_VE_FIFOSTAT2_get_rslt_fifo_cnt(data)                            ((0x07C00000&(data))>>22)
#define  RIF_REG_VE_FIFOSTAT2_get_img_fifo_cnt(data)                             ((0x003F0000&(data))>>16)
#define  RIF_REG_VE_FIFOSTAT2_get_dec_inst_cnt(data)                             ((0x00003F00&(data))>>8)
#define  RIF_REG_VE_FIFOSTAT2_act_rslt_in_fifo_src(data)                         ((0xF8000000&(data))>>27)
#define  RIF_REG_VE_FIFOSTAT2_rslt_fifo_cnt_src(data)                            ((0x07C00000&(data))>>22)
#define  RIF_REG_VE_FIFOSTAT2_img_fifo_cnt_src(data)                             ((0x003F0000&(data))>>16)
#define  RIF_REG_VE_FIFOSTAT2_dec_inst_cnt_src(data)                             ((0x00003F00&(data))>>8)

#define  RIF_REG_VE_RSLT_TIMER                                                   0x1800E418
#define  RIF_REG_VE_RSLT_TIMER_reg_addr                                          "0xB800E418"
#define  RIF_REG_VE_RSLT_TIMER_reg                                               0xB800E418
#define  RIF_REG_VE_RSLT_TIMER_inst_addr                                         "0x0005"
#define  RIF_REG_VE_RSLT_TIMER_inst_adr                                          "0x0006"
#define  RIF_REG_VE_RSLT_TIMER_inst                                              0x0006
#define  set_RIF_REG_VE_RSLT_TIMER_reg(data)                                     (*((volatile unsigned int*)RIF_REG_VE_RSLT_TIMER_reg)=data)
#define  get_RIF_REG_VE_RSLT_TIMER_reg                                           (*((volatile unsigned int*)RIF_REG_VE_RSLT_TIMER_reg))
#define  RIF_REG_VE_RSLT_TIMER_rslt_timer_shift                                  (0)
#define  RIF_REG_VE_RSLT_TIMER_rslt_timer_mask                                   (0x00FFFFFF)
#define  RIF_REG_VE_RSLT_TIMER_rslt_timer(data)                                  (0x00FFFFFF&(data))
#define  RIF_REG_VE_RSLT_TIMER_get_rslt_timer(data)                              (0x00FFFFFF&(data))
#define  RIF_REG_VE_RSLT_TIMER_rslt_timer_src(data)                              (0x00FFFFFF&(data))

#define  RIF_REG_VE_CMD_TIMER                                                    0x1800E41C
#define  RIF_REG_VE_CMD_TIMER_reg_addr                                           "0xB800E41C"
#define  RIF_REG_VE_CMD_TIMER_reg                                                0xB800E41C
#define  RIF_REG_VE_CMD_TIMER_inst_addr                                          "0x0006"
#define  RIF_REG_VE_CMD_TIMER_inst_adr                                           "0x0007"
#define  RIF_REG_VE_CMD_TIMER_inst                                               0x0007
#define  set_RIF_REG_VE_CMD_TIMER_reg(data)                                      (*((volatile unsigned int*)RIF_REG_VE_CMD_TIMER_reg)=data)
#define  get_RIF_REG_VE_CMD_TIMER_reg                                            (*((volatile unsigned int*)RIF_REG_VE_CMD_TIMER_reg))
#define  RIF_REG_VE_CMD_TIMER_cmd_timer_shift                                    (0)
#define  RIF_REG_VE_CMD_TIMER_cmd_timer_mask                                     (0x00FFFFFF)
#define  RIF_REG_VE_CMD_TIMER_cmd_timer(data)                                    (0x00FFFFFF&(data))
#define  RIF_REG_VE_CMD_TIMER_get_cmd_timer(data)                                (0x00FFFFFF&(data))
#define  RIF_REG_VE_CMD_TIMER_cmd_timer_src(data)                                (0x00FFFFFF&(data))

#define  RIF_REG_VE_FIFOSTAT3                                                    0x1800E424
#define  RIF_REG_VE_FIFOSTAT3_reg_addr                                           "0xB800E424"
#define  RIF_REG_VE_FIFOSTAT3_reg                                                0xB800E424
#define  RIF_REG_VE_FIFOSTAT3_inst_addr                                          "0x0007"
#define  RIF_REG_VE_FIFOSTAT3_inst_adr                                           "0x0009"
#define  RIF_REG_VE_FIFOSTAT3_inst                                               0x0009
#define  set_RIF_REG_VE_FIFOSTAT3_reg(data)                                      (*((volatile unsigned int*)RIF_REG_VE_FIFOSTAT3_reg)=data)
#define  get_RIF_REG_VE_FIFOSTAT3_reg                                            (*((volatile unsigned int*)RIF_REG_VE_FIFOSTAT3_reg))
#define  RIF_REG_VE_FIFOSTAT3_ime_inst_cnt_shift                                 (8)
#define  RIF_REG_VE_FIFOSTAT3_emd_inst_cnt_shift                                 (0)
#define  RIF_REG_VE_FIFOSTAT3_ime_inst_cnt_mask                                  (0x00003F00)
#define  RIF_REG_VE_FIFOSTAT3_emd_inst_cnt_mask                                  (0x0000003F)
#define  RIF_REG_VE_FIFOSTAT3_ime_inst_cnt(data)                                 (0x00003F00&((data)<<8))
#define  RIF_REG_VE_FIFOSTAT3_emd_inst_cnt(data)                                 (0x0000003F&(data))
#define  RIF_REG_VE_FIFOSTAT3_get_ime_inst_cnt(data)                             ((0x00003F00&(data))>>8)
#define  RIF_REG_VE_FIFOSTAT3_get_emd_inst_cnt(data)                             (0x0000003F&(data))
#define  RIF_REG_VE_FIFOSTAT3_ime_inst_cnt_src(data)                             ((0x00003F00&(data))>>8)
#define  RIF_REG_VE_FIFOSTAT3_emd_inst_cnt_src(data)                             (0x0000003F&(data))

#define  RIF_REG_VMBANKSEL                                                       0x1800E420
#define  RIF_REG_VMBANKSEL_reg_addr                                              "0xB800E420"
#define  RIF_REG_VMBANKSEL_reg                                                   0xB800E420
#define  RIF_REG_VMBANKSEL_inst_addr                                             "0x0008"
#define  RIF_REG_VMBANKSEL_inst_adr                                              "0x0008"
#define  RIF_REG_VMBANKSEL_inst                                                  0x0008
#define  set_RIF_REG_VMBANKSEL_reg(data)                                         (*((volatile unsigned int*)RIF_REG_VMBANKSEL_reg)=data)
#define  get_RIF_REG_VMBANKSEL_reg                                               (*((volatile unsigned int*)RIF_REG_VMBANKSEL_reg))
#define  RIF_REG_VMBANKSEL_ve_cmprs_bnk_shift                                    (20)
#define  RIF_REG_VMBANKSEL_ve_img_bnk_shift                                      (16)
#define  RIF_REG_VMBANKSEL_ve_deb_bnk_shift                                      (12)
#define  RIF_REG_VMBANKSEL_ve_prd_bnk_shift                                      (8)
#define  RIF_REG_VMBANKSEL_ve_dmab_bnk_shift                                     (4)
#define  RIF_REG_VMBANKSEL_ve_dmaa_bnk_shift                                     (0)
#define  RIF_REG_VMBANKSEL_ve_cmprs_bnk_mask                                     (0x00700000)
#define  RIF_REG_VMBANKSEL_ve_img_bnk_mask                                       (0x00070000)
#define  RIF_REG_VMBANKSEL_ve_deb_bnk_mask                                       (0x00007000)
#define  RIF_REG_VMBANKSEL_ve_prd_bnk_mask                                       (0x00000700)
#define  RIF_REG_VMBANKSEL_ve_dmab_bnk_mask                                      (0x00000070)
#define  RIF_REG_VMBANKSEL_ve_dmaa_bnk_mask                                      (0x00000007)
#define  RIF_REG_VMBANKSEL_ve_cmprs_bnk(data)                                    (0x00700000&((data)<<20))
#define  RIF_REG_VMBANKSEL_ve_img_bnk(data)                                      (0x00070000&((data)<<16))
#define  RIF_REG_VMBANKSEL_ve_deb_bnk(data)                                      (0x00007000&((data)<<12))
#define  RIF_REG_VMBANKSEL_ve_prd_bnk(data)                                      (0x00000700&((data)<<8))
#define  RIF_REG_VMBANKSEL_ve_dmab_bnk(data)                                     (0x00000070&((data)<<4))
#define  RIF_REG_VMBANKSEL_ve_dmaa_bnk(data)                                     (0x00000007&(data))
#define  RIF_REG_VMBANKSEL_get_ve_cmprs_bnk(data)                                ((0x00700000&(data))>>20)
#define  RIF_REG_VMBANKSEL_get_ve_img_bnk(data)                                  ((0x00070000&(data))>>16)
#define  RIF_REG_VMBANKSEL_get_ve_deb_bnk(data)                                  ((0x00007000&(data))>>12)
#define  RIF_REG_VMBANKSEL_get_ve_prd_bnk(data)                                  ((0x00000700&(data))>>8)
#define  RIF_REG_VMBANKSEL_get_ve_dmab_bnk(data)                                 ((0x00000070&(data))>>4)
#define  RIF_REG_VMBANKSEL_get_ve_dmaa_bnk(data)                                 (0x00000007&(data))
#define  RIF_REG_VMBANKSEL_ve_cmprs_bnk_src(data)                                ((0x00700000&(data))>>20)
#define  RIF_REG_VMBANKSEL_ve_img_bnk_src(data)                                  ((0x00070000&(data))>>16)
#define  RIF_REG_VMBANKSEL_ve_deb_bnk_src(data)                                  ((0x00007000&(data))>>12)
#define  RIF_REG_VMBANKSEL_ve_prd_bnk_src(data)                                  ((0x00000700&(data))>>8)
#define  RIF_REG_VMBANKSEL_ve_dmab_bnk_src(data)                                 ((0x00000070&(data))>>4)
#define  RIF_REG_VMBANKSEL_ve_dmaa_bnk_src(data)                                 (0x00000007&(data))

#define  RIF_REG_UMBANKSEL                                                       0x1800E428
#define  RIF_REG_UMBANKSEL_reg_addr                                              "0xB800E428"
#define  RIF_REG_UMBANKSEL_reg                                                   0xB800E428
#define  RIF_REG_UMBANKSEL_inst_addr                                             "0x0009"
#define  RIF_REG_UMBANKSEL_inst_adr                                              "0x000A"
#define  RIF_REG_UMBANKSEL_inst                                                  0x000A
#define  set_RIF_REG_UMBANKSEL_reg(data)                                         (*((volatile unsigned int*)RIF_REG_UMBANKSEL_reg)=data)
#define  get_RIF_REG_UMBANKSEL_reg                                               (*((volatile unsigned int*)RIF_REG_UMBANKSEL_reg))
#define  RIF_REG_UMBANKSEL_ve_gcf_umbnk_shift                                    (12)
#define  RIF_REG_UMBANKSEL_ve_emd_umbnk_shift                                    (8)
#define  RIF_REG_UMBANKSEL_ve_ime_umbk_shift                                     (4)
#define  RIF_REG_UMBANKSEL_ve_dma_umbnk_shift                                    (0)
#define  RIF_REG_UMBANKSEL_ve_gcf_umbnk_mask                                     (0x00003000)
#define  RIF_REG_UMBANKSEL_ve_emd_umbnk_mask                                     (0x00000300)
#define  RIF_REG_UMBANKSEL_ve_ime_umbk_mask                                      (0x00000030)
#define  RIF_REG_UMBANKSEL_ve_dma_umbnk_mask                                     (0x00000003)
#define  RIF_REG_UMBANKSEL_ve_gcf_umbnk(data)                                    (0x00003000&((data)<<12))
#define  RIF_REG_UMBANKSEL_ve_emd_umbnk(data)                                    (0x00000300&((data)<<8))
#define  RIF_REG_UMBANKSEL_ve_ime_umbk(data)                                     (0x00000030&((data)<<4))
#define  RIF_REG_UMBANKSEL_ve_dma_umbnk(data)                                    (0x00000003&(data))
#define  RIF_REG_UMBANKSEL_get_ve_gcf_umbnk(data)                                ((0x00003000&(data))>>12)
#define  RIF_REG_UMBANKSEL_get_ve_emd_umbnk(data)                                ((0x00000300&(data))>>8)
#define  RIF_REG_UMBANKSEL_get_ve_ime_umbk(data)                                 ((0x00000030&(data))>>4)
#define  RIF_REG_UMBANKSEL_get_ve_dma_umbnk(data)                                (0x00000003&(data))
#define  RIF_REG_UMBANKSEL_ve_gcf_umbnk_src(data)                                ((0x00003000&(data))>>12)
#define  RIF_REG_UMBANKSEL_ve_emd_umbnk_src(data)                                ((0x00000300&(data))>>8)
#define  RIF_REG_UMBANKSEL_ve_ime_umbk_src(data)                                 ((0x00000030&(data))>>4)
#define  RIF_REG_UMBANKSEL_ve_dma_umbnk_src(data)                                (0x00000003&(data))

#define  RIF_REG_DEC_CNTL                                                        0x1800E450
#define  RIF_REG_DEC_CNTL_reg_addr                                               "0xB800E450"
#define  RIF_REG_DEC_CNTL_reg                                                    0xB800E450
#define  RIF_REG_DEC_CNTL_inst_addr                                              "0x000A"
#define  RIF_REG_DEC_CNTL_inst_adr                                               "0x0014"
#define  RIF_REG_DEC_CNTL_inst                                                   0x0014
#define  set_RIF_REG_DEC_CNTL_reg(data)                                          (*((volatile unsigned int*)RIF_REG_DEC_CNTL_reg)=data)
#define  get_RIF_REG_DEC_CNTL_reg                                                (*((volatile unsigned int*)RIF_REG_DEC_CNTL_reg))
#define  RIF_REG_DEC_CNTL_lossy_en_shift                                         (30)
#define  RIF_REG_DEC_CNTL_cmprs_head_remap_shift                                 (29)
#define  RIF_REG_DEC_CNTL_mode32x1_shift                                         (28)
#define  RIF_REG_DEC_CNTL_gpu_out_en_shift                                       (27)
#define  RIF_REG_DEC_CNTL_dual_core_dmy_row_method_shift                         (26)
#define  RIF_REG_DEC_CNTL_comp_wrap_width_shift                                  (16)
#define  RIF_REG_DEC_CNTL_compression_en_shift                                   (15)
#define  RIF_REG_DEC_CNTL_MultiCoreEnable_shift                                  (13)
#define  RIF_REG_DEC_CNTL_CoreNum_shift                                          (11)
#define  RIF_REG_DEC_CNTL_mode8x2_16b_align_shift                                (10)
#define  RIF_REG_DEC_CNTL_mode8x2_shift                                          (9)
#define  RIF_REG_DEC_CNTL_monochrome_shift                                       (8)
#define  RIF_REG_DEC_CNTL_level_shift                                            (7)
#define  RIF_REG_DEC_CNTL_profile_shift                                          (5)
#define  RIF_REG_DEC_CNTL_coding_type_shift                                      (0)
#define  RIF_REG_DEC_CNTL_lossy_en_mask                                          (0x40000000)
#define  RIF_REG_DEC_CNTL_cmprs_head_remap_mask                                  (0x20000000)
#define  RIF_REG_DEC_CNTL_mode32x1_mask                                          (0x10000000)
#define  RIF_REG_DEC_CNTL_gpu_out_en_mask                                        (0x08000000)
#define  RIF_REG_DEC_CNTL_dual_core_dmy_row_method_mask                          (0x04000000)
#define  RIF_REG_DEC_CNTL_comp_wrap_width_mask                                   (0x03FF0000)
#define  RIF_REG_DEC_CNTL_compression_en_mask                                    (0x00008000)
#define  RIF_REG_DEC_CNTL_MultiCoreEnable_mask                                   (0x00006000)
#define  RIF_REG_DEC_CNTL_CoreNum_mask                                           (0x00001800)
#define  RIF_REG_DEC_CNTL_mode8x2_16b_align_mask                                 (0x00000400)
#define  RIF_REG_DEC_CNTL_mode8x2_mask                                           (0x00000200)
#define  RIF_REG_DEC_CNTL_monochrome_mask                                        (0x00000100)
#define  RIF_REG_DEC_CNTL_level_mask                                             (0x00000080)
#define  RIF_REG_DEC_CNTL_profile_mask                                           (0x00000060)
#define  RIF_REG_DEC_CNTL_coding_type_mask                                       (0x0000001F)
#define  RIF_REG_DEC_CNTL_lossy_en(data)                                         (0x40000000&((data)<<30))
#define  RIF_REG_DEC_CNTL_cmprs_head_remap(data)                                 (0x20000000&((data)<<29))
#define  RIF_REG_DEC_CNTL_mode32x1(data)                                         (0x10000000&((data)<<28))
#define  RIF_REG_DEC_CNTL_gpu_out_en(data)                                       (0x08000000&((data)<<27))
#define  RIF_REG_DEC_CNTL_dual_core_dmy_row_method(data)                         (0x04000000&((data)<<26))
#define  RIF_REG_DEC_CNTL_comp_wrap_width(data)                                  (0x03FF0000&((data)<<16))
#define  RIF_REG_DEC_CNTL_compression_en(data)                                   (0x00008000&((data)<<15))
#define  RIF_REG_DEC_CNTL_MultiCoreEnable(data)                                  (0x00006000&((data)<<13))
#define  RIF_REG_DEC_CNTL_CoreNum(data)                                          (0x00001800&((data)<<11))
#define  RIF_REG_DEC_CNTL_mode8x2_16b_align(data)                                (0x00000400&((data)<<10))
#define  RIF_REG_DEC_CNTL_mode8x2(data)                                          (0x00000200&((data)<<9))
#define  RIF_REG_DEC_CNTL_monochrome(data)                                       (0x00000100&((data)<<8))
#define  RIF_REG_DEC_CNTL_level(data)                                            (0x00000080&((data)<<7))
#define  RIF_REG_DEC_CNTL_profile(data)                                          (0x00000060&((data)<<5))
#define  RIF_REG_DEC_CNTL_coding_type(data)                                      (0x0000001F&(data))
#define  RIF_REG_DEC_CNTL_get_lossy_en(data)                                     ((0x40000000&(data))>>30)
#define  RIF_REG_DEC_CNTL_get_cmprs_head_remap(data)                             ((0x20000000&(data))>>29)
#define  RIF_REG_DEC_CNTL_get_mode32x1(data)                                     ((0x10000000&(data))>>28)
#define  RIF_REG_DEC_CNTL_get_gpu_out_en(data)                                   ((0x08000000&(data))>>27)
#define  RIF_REG_DEC_CNTL_get_dual_core_dmy_row_method(data)                     ((0x04000000&(data))>>26)
#define  RIF_REG_DEC_CNTL_get_comp_wrap_width(data)                              ((0x03FF0000&(data))>>16)
#define  RIF_REG_DEC_CNTL_get_compression_en(data)                               ((0x00008000&(data))>>15)
#define  RIF_REG_DEC_CNTL_get_MultiCoreEnable(data)                              ((0x00006000&(data))>>13)
#define  RIF_REG_DEC_CNTL_get_CoreNum(data)                                      ((0x00001800&(data))>>11)
#define  RIF_REG_DEC_CNTL_get_mode8x2_16b_align(data)                            ((0x00000400&(data))>>10)
#define  RIF_REG_DEC_CNTL_get_mode8x2(data)                                      ((0x00000200&(data))>>9)
#define  RIF_REG_DEC_CNTL_get_monochrome(data)                                   ((0x00000100&(data))>>8)
#define  RIF_REG_DEC_CNTL_get_level(data)                                        ((0x00000080&(data))>>7)
#define  RIF_REG_DEC_CNTL_get_profile(data)                                      ((0x00000060&(data))>>5)
#define  RIF_REG_DEC_CNTL_get_coding_type(data)                                  (0x0000001F&(data))
#define  RIF_REG_DEC_CNTL_lossy_en_src(data)                                     ((0x40000000&(data))>>30)
#define  RIF_REG_DEC_CNTL_cmprs_head_remap_src(data)                             ((0x20000000&(data))>>29)
#define  RIF_REG_DEC_CNTL_mode32x1_src(data)                                     ((0x10000000&(data))>>28)
#define  RIF_REG_DEC_CNTL_gpu_out_en_src(data)                                   ((0x08000000&(data))>>27)
#define  RIF_REG_DEC_CNTL_dual_core_dmy_row_method_src(data)                     ((0x04000000&(data))>>26)
#define  RIF_REG_DEC_CNTL_comp_wrap_width_src(data)                              ((0x03FF0000&(data))>>16)
#define  RIF_REG_DEC_CNTL_compression_en_src(data)                               ((0x00008000&(data))>>15)
#define  RIF_REG_DEC_CNTL_MultiCoreEnable_src(data)                              ((0x00006000&(data))>>13)
#define  RIF_REG_DEC_CNTL_CoreNum_src(data)                                      ((0x00001800&(data))>>11)
#define  RIF_REG_DEC_CNTL_mode8x2_16b_align_src(data)                            ((0x00000400&(data))>>10)
#define  RIF_REG_DEC_CNTL_mode8x2_src(data)                                      ((0x00000200&(data))>>9)
#define  RIF_REG_DEC_CNTL_monochrome_src(data)                                   ((0x00000100&(data))>>8)
#define  RIF_REG_DEC_CNTL_level_src(data)                                        ((0x00000080&(data))>>7)
#define  RIF_REG_DEC_CNTL_profile_src(data)                                      ((0x00000060&(data))>>5)
#define  RIF_REG_DEC_CNTL_coding_type_src(data)                                  (0x0000001F&(data))

#define  RIF_REG_PICINFO1                                                        0x1800E454
#define  RIF_REG_PICINFO1_reg_addr                                               "0xB800E454"
#define  RIF_REG_PICINFO1_reg                                                    0xB800E454
#define  RIF_REG_PICINFO1_inst_addr                                              "0x000B"
#define  RIF_REG_PICINFO1_inst_adr                                               "0x0015"
#define  RIF_REG_PICINFO1_inst                                                   0x0015
#define  set_RIF_REG_PICINFO1_reg(data)                                          (*((volatile unsigned int*)RIF_REG_PICINFO1_reg)=data)
#define  get_RIF_REG_PICINFO1_reg                                                (*((volatile unsigned int*)RIF_REG_PICINFO1_reg))
#define  RIF_REG_PICINFO1_filter_level_shift                                     (24)
#define  RIF_REG_PICINFO1_allow_high_precision_mv_shift                          (23)
#define  RIF_REG_PICINFO1_vp9_seg_en_shift                                       (22)
#define  RIF_REG_PICINFO1_vp8_bicubic_filtering_shift                            (21)
#define  RIF_REG_PICINFO1_bottom_field_flag_shift                                (20)
#define  RIF_REG_PICINFO1_field_pic_flag_shift                                   (19)
#define  RIF_REG_PICINFO1_picmb_h_shift                                          (10)
#define  RIF_REG_PICINFO1_picmb_w_shift                                          (0)
#define  RIF_REG_PICINFO1_filter_level_mask                                      (0x3F000000)
#define  RIF_REG_PICINFO1_allow_high_precision_mv_mask                           (0x00800000)
#define  RIF_REG_PICINFO1_vp9_seg_en_mask                                        (0x00400000)
#define  RIF_REG_PICINFO1_vp8_bicubic_filtering_mask                             (0x00200000)
#define  RIF_REG_PICINFO1_bottom_field_flag_mask                                 (0x00100000)
#define  RIF_REG_PICINFO1_field_pic_flag_mask                                    (0x00080000)
#define  RIF_REG_PICINFO1_picmb_h_mask                                           (0x0007FC00)
#define  RIF_REG_PICINFO1_picmb_w_mask                                           (0x000003FF)
#define  RIF_REG_PICINFO1_filter_level(data)                                     (0x3F000000&((data)<<24))
#define  RIF_REG_PICINFO1_allow_high_precision_mv(data)                          (0x00800000&((data)<<23))
#define  RIF_REG_PICINFO1_vp9_seg_en(data)                                       (0x00400000&((data)<<22))
#define  RIF_REG_PICINFO1_vp8_bicubic_filtering(data)                            (0x00200000&((data)<<21))
#define  RIF_REG_PICINFO1_bottom_field_flag(data)                                (0x00100000&((data)<<20))
#define  RIF_REG_PICINFO1_field_pic_flag(data)                                   (0x00080000&((data)<<19))
#define  RIF_REG_PICINFO1_picmb_h(data)                                          (0x0007FC00&((data)<<10))
#define  RIF_REG_PICINFO1_picmb_w(data)                                          (0x000003FF&(data))
#define  RIF_REG_PICINFO1_get_filter_level(data)                                 ((0x3F000000&(data))>>24)
#define  RIF_REG_PICINFO1_get_allow_high_precision_mv(data)                      ((0x00800000&(data))>>23)
#define  RIF_REG_PICINFO1_get_vp9_seg_en(data)                                   ((0x00400000&(data))>>22)
#define  RIF_REG_PICINFO1_get_vp8_bicubic_filtering(data)                        ((0x00200000&(data))>>21)
#define  RIF_REG_PICINFO1_get_bottom_field_flag(data)                            ((0x00100000&(data))>>20)
#define  RIF_REG_PICINFO1_get_field_pic_flag(data)                               ((0x00080000&(data))>>19)
#define  RIF_REG_PICINFO1_get_picmb_h(data)                                      ((0x0007FC00&(data))>>10)
#define  RIF_REG_PICINFO1_get_picmb_w(data)                                      (0x000003FF&(data))
#define  RIF_REG_PICINFO1_filter_level_src(data)                                 ((0x3F000000&(data))>>24)
#define  RIF_REG_PICINFO1_allow_high_precision_mv_src(data)                      ((0x00800000&(data))>>23)
#define  RIF_REG_PICINFO1_vp9_seg_en_src(data)                                   ((0x00400000&(data))>>22)
#define  RIF_REG_PICINFO1_vp8_bicubic_filtering_src(data)                        ((0x00200000&(data))>>21)
#define  RIF_REG_PICINFO1_bottom_field_flag_src(data)                            ((0x00100000&(data))>>20)
#define  RIF_REG_PICINFO1_field_pic_flag_src(data)                               ((0x00080000&(data))>>19)
#define  RIF_REG_PICINFO1_picmb_h_src(data)                                      ((0x0007FC00&(data))>>10)
#define  RIF_REG_PICINFO1_picmb_w_src(data)                                      (0x000003FF&(data))

#define  RIF_REG_H264PICCNTL                                                     0x1800E460
#define  RIF_REG_H264PICCNTL_reg_addr                                            "0xB800E460"
#define  RIF_REG_H264PICCNTL_reg                                                 0xB800E460
#define  RIF_REG_H264PICCNTL_inst_addr                                           "0x000C"
#define  RIF_REG_H264PICCNTL_inst_adr                                            "0x0018"
#define  RIF_REG_H264PICCNTL_inst                                                0x0018
#define  set_RIF_REG_H264PICCNTL_reg(data)                                       (*((volatile unsigned int*)RIF_REG_H264PICCNTL_reg)=data)
#define  get_RIF_REG_H264PICCNTL_reg                                             (*((volatile unsigned int*)RIF_REG_H264PICCNTL_reg))
#define  RIF_REG_H264PICCNTL_mode16x1_shift                                      (6)
#define  RIF_REG_H264PICCNTL_Constrainted_intra_pred_flag_shift                  (5)
#define  RIF_REG_H264PICCNTL_Weighted_pred_flag_shift                            (4)
#define  RIF_REG_H264PICCNTL_Weighted_bipred_idc_shift                           (2)
#define  RIF_REG_H264PICCNTL_frame_mbs_only_flag_shift                           (1)
#define  RIF_REG_H264PICCNTL_mb_adaptive_frame_field_flag_shift                  (0)
#define  RIF_REG_H264PICCNTL_mode16x1_mask                                       (0x00000040)
#define  RIF_REG_H264PICCNTL_Constrainted_intra_pred_flag_mask                   (0x00000020)
#define  RIF_REG_H264PICCNTL_Weighted_pred_flag_mask                             (0x00000010)
#define  RIF_REG_H264PICCNTL_Weighted_bipred_idc_mask                            (0x0000000C)
#define  RIF_REG_H264PICCNTL_frame_mbs_only_flag_mask                            (0x00000002)
#define  RIF_REG_H264PICCNTL_mb_adaptive_frame_field_flag_mask                   (0x00000001)
#define  RIF_REG_H264PICCNTL_mode16x1(data)                                      (0x00000040&((data)<<6))
#define  RIF_REG_H264PICCNTL_Constrainted_intra_pred_flag(data)                  (0x00000020&((data)<<5))
#define  RIF_REG_H264PICCNTL_Weighted_pred_flag(data)                            (0x00000010&((data)<<4))
#define  RIF_REG_H264PICCNTL_Weighted_bipred_idc(data)                           (0x0000000C&((data)<<2))
#define  RIF_REG_H264PICCNTL_frame_mbs_only_flag(data)                           (0x00000002&((data)<<1))
#define  RIF_REG_H264PICCNTL_mb_adaptive_frame_field_flag(data)                  (0x00000001&(data))
#define  RIF_REG_H264PICCNTL_get_mode16x1(data)                                  ((0x00000040&(data))>>6)
#define  RIF_REG_H264PICCNTL_get_Constrainted_intra_pred_flag(data)              ((0x00000020&(data))>>5)
#define  RIF_REG_H264PICCNTL_get_Weighted_pred_flag(data)                        ((0x00000010&(data))>>4)
#define  RIF_REG_H264PICCNTL_get_Weighted_bipred_idc(data)                       ((0x0000000C&(data))>>2)
#define  RIF_REG_H264PICCNTL_get_frame_mbs_only_flag(data)                       ((0x00000002&(data))>>1)
#define  RIF_REG_H264PICCNTL_get_mb_adaptive_frame_field_flag(data)              (0x00000001&(data))
#define  RIF_REG_H264PICCNTL_mode16x1_src(data)                                  ((0x00000040&(data))>>6)
#define  RIF_REG_H264PICCNTL_Constrainted_intra_pred_flag_src(data)              ((0x00000020&(data))>>5)
#define  RIF_REG_H264PICCNTL_Weighted_pred_flag_src(data)                        ((0x00000010&(data))>>4)
#define  RIF_REG_H264PICCNTL_Weighted_bipred_idc_src(data)                       ((0x0000000C&(data))>>2)
#define  RIF_REG_H264PICCNTL_frame_mbs_only_flag_src(data)                       ((0x00000002&(data))>>1)
#define  RIF_REG_H264PICCNTL_mb_adaptive_frame_field_flag_src(data)              (0x00000001&(data))

#define  RIF_REG_HEVCSEQCNTL                                                     0x1800E464
#define  RIF_REG_HEVCSEQCNTL_reg_addr                                            "0xB800E464"
#define  RIF_REG_HEVCSEQCNTL_reg                                                 0xB800E464
#define  RIF_REG_HEVCSEQCNTL_inst_addr                                           "0x000D"
#define  RIF_REG_HEVCSEQCNTL_inst_adr                                            "0x0019"
#define  RIF_REG_HEVCSEQCNTL_inst                                                0x0019
#define  set_RIF_REG_HEVCSEQCNTL_reg(data)                                       (*((volatile unsigned int*)RIF_REG_HEVCSEQCNTL_reg)=data)
#define  get_RIF_REG_HEVCSEQCNTL_reg                                             (*((volatile unsigned int*)RIF_REG_HEVCSEQCNTL_reg))
#define  RIF_REG_HEVCSEQCNTL_chroma_bits_shift                                   (28)
#define  RIF_REG_HEVCSEQCNTL_luma_bits_shift                                     (26)
#define  RIF_REG_HEVCSEQCNTL_hevc_dbg_mode_shift                                 (25)
#define  RIF_REG_HEVCSEQCNTL_decimate_en_shift                                   (23)
#define  RIF_REG_HEVCSEQCNTL_mincbsize_shift                                     (21)
#define  RIF_REG_HEVCSEQCNTL_ctbsize_shift                                       (19)
#define  RIF_REG_HEVCSEQCNTL_min_trafo_size_shift                                (17)
#define  RIF_REG_HEVCSEQCNTL_max_trafo_size_shift                                (15)
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_inter_shift                    (12)
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_intra_shift                    (9)
#define  RIF_REG_HEVCSEQCNTL_amp_enabled_flag_shift                              (8)
#define  RIF_REG_HEVCSEQCNTL_sample_adaptive_offset_enabled_flag_shift           (7)
#define  RIF_REG_HEVCSEQCNTL_pcm_enabled_flag_shift                              (6)
#define  RIF_REG_HEVCSEQCNTL_min_ipcm_cbsize_shift                               (4)
#define  RIF_REG_HEVCSEQCNTL_max_ipcm_cbsize_shift                               (2)
#define  RIF_REG_HEVCSEQCNTL_pcm_loop_filter_disable_flag_shift                  (1)
#define  RIF_REG_HEVCSEQCNTL_strong_intra_smoothing_enable_flag_shift            (0)
#define  RIF_REG_HEVCSEQCNTL_chroma_bits_mask                                    (0x30000000)
#define  RIF_REG_HEVCSEQCNTL_luma_bits_mask                                      (0x0C000000)
#define  RIF_REG_HEVCSEQCNTL_hevc_dbg_mode_mask                                  (0x02000000)
#define  RIF_REG_HEVCSEQCNTL_decimate_en_mask                                    (0x01800000)
#define  RIF_REG_HEVCSEQCNTL_mincbsize_mask                                      (0x00600000)
#define  RIF_REG_HEVCSEQCNTL_ctbsize_mask                                        (0x00180000)
#define  RIF_REG_HEVCSEQCNTL_min_trafo_size_mask                                 (0x00060000)
#define  RIF_REG_HEVCSEQCNTL_max_trafo_size_mask                                 (0x00018000)
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_inter_mask                     (0x00007000)
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_intra_mask                     (0x00000E00)
#define  RIF_REG_HEVCSEQCNTL_amp_enabled_flag_mask                               (0x00000100)
#define  RIF_REG_HEVCSEQCNTL_sample_adaptive_offset_enabled_flag_mask            (0x00000080)
#define  RIF_REG_HEVCSEQCNTL_pcm_enabled_flag_mask                               (0x00000040)
#define  RIF_REG_HEVCSEQCNTL_min_ipcm_cbsize_mask                                (0x00000030)
#define  RIF_REG_HEVCSEQCNTL_max_ipcm_cbsize_mask                                (0x0000000C)
#define  RIF_REG_HEVCSEQCNTL_pcm_loop_filter_disable_flag_mask                   (0x00000002)
#define  RIF_REG_HEVCSEQCNTL_strong_intra_smoothing_enable_flag_mask             (0x00000001)
#define  RIF_REG_HEVCSEQCNTL_chroma_bits(data)                                   (0x30000000&((data)<<28))
#define  RIF_REG_HEVCSEQCNTL_luma_bits(data)                                     (0x0C000000&((data)<<26))
#define  RIF_REG_HEVCSEQCNTL_hevc_dbg_mode(data)                                 (0x02000000&((data)<<25))
#define  RIF_REG_HEVCSEQCNTL_decimate_en(data)                                   (0x01800000&((data)<<23))
#define  RIF_REG_HEVCSEQCNTL_mincbsize(data)                                     (0x00600000&((data)<<21))
#define  RIF_REG_HEVCSEQCNTL_ctbsize(data)                                       (0x00180000&((data)<<19))
#define  RIF_REG_HEVCSEQCNTL_min_trafo_size(data)                                (0x00060000&((data)<<17))
#define  RIF_REG_HEVCSEQCNTL_max_trafo_size(data)                                (0x00018000&((data)<<15))
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_inter(data)                    (0x00007000&((data)<<12))
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_intra(data)                    (0x00000E00&((data)<<9))
#define  RIF_REG_HEVCSEQCNTL_amp_enabled_flag(data)                              (0x00000100&((data)<<8))
#define  RIF_REG_HEVCSEQCNTL_sample_adaptive_offset_enabled_flag(data)           (0x00000080&((data)<<7))
#define  RIF_REG_HEVCSEQCNTL_pcm_enabled_flag(data)                              (0x00000040&((data)<<6))
#define  RIF_REG_HEVCSEQCNTL_min_ipcm_cbsize(data)                               (0x00000030&((data)<<4))
#define  RIF_REG_HEVCSEQCNTL_max_ipcm_cbsize(data)                               (0x0000000C&((data)<<2))
#define  RIF_REG_HEVCSEQCNTL_pcm_loop_filter_disable_flag(data)                  (0x00000002&((data)<<1))
#define  RIF_REG_HEVCSEQCNTL_strong_intra_smoothing_enable_flag(data)            (0x00000001&(data))
#define  RIF_REG_HEVCSEQCNTL_get_chroma_bits(data)                               ((0x30000000&(data))>>28)
#define  RIF_REG_HEVCSEQCNTL_get_luma_bits(data)                                 ((0x0C000000&(data))>>26)
#define  RIF_REG_HEVCSEQCNTL_get_hevc_dbg_mode(data)                             ((0x02000000&(data))>>25)
#define  RIF_REG_HEVCSEQCNTL_get_decimate_en(data)                               ((0x01800000&(data))>>23)
#define  RIF_REG_HEVCSEQCNTL_get_mincbsize(data)                                 ((0x00600000&(data))>>21)
#define  RIF_REG_HEVCSEQCNTL_get_ctbsize(data)                                   ((0x00180000&(data))>>19)
#define  RIF_REG_HEVCSEQCNTL_get_min_trafo_size(data)                            ((0x00060000&(data))>>17)
#define  RIF_REG_HEVCSEQCNTL_get_max_trafo_size(data)                            ((0x00018000&(data))>>15)
#define  RIF_REG_HEVCSEQCNTL_get_max_trans_hier_depth_inter(data)                ((0x00007000&(data))>>12)
#define  RIF_REG_HEVCSEQCNTL_get_max_trans_hier_depth_intra(data)                ((0x00000E00&(data))>>9)
#define  RIF_REG_HEVCSEQCNTL_get_amp_enabled_flag(data)                          ((0x00000100&(data))>>8)
#define  RIF_REG_HEVCSEQCNTL_get_sample_adaptive_offset_enabled_flag(data)       ((0x00000080&(data))>>7)
#define  RIF_REG_HEVCSEQCNTL_get_pcm_enabled_flag(data)                          ((0x00000040&(data))>>6)
#define  RIF_REG_HEVCSEQCNTL_get_min_ipcm_cbsize(data)                           ((0x00000030&(data))>>4)
#define  RIF_REG_HEVCSEQCNTL_get_max_ipcm_cbsize(data)                           ((0x0000000C&(data))>>2)
#define  RIF_REG_HEVCSEQCNTL_get_pcm_loop_filter_disable_flag(data)              ((0x00000002&(data))>>1)
#define  RIF_REG_HEVCSEQCNTL_get_strong_intra_smoothing_enable_flag(data)        (0x00000001&(data))
#define  RIF_REG_HEVCSEQCNTL_chroma_bits_src(data)                               ((0x30000000&(data))>>28)
#define  RIF_REG_HEVCSEQCNTL_luma_bits_src(data)                                 ((0x0C000000&(data))>>26)
#define  RIF_REG_HEVCSEQCNTL_hevc_dbg_mode_src(data)                             ((0x02000000&(data))>>25)
#define  RIF_REG_HEVCSEQCNTL_decimate_en_src(data)                               ((0x01800000&(data))>>23)
#define  RIF_REG_HEVCSEQCNTL_mincbsize_src(data)                                 ((0x00600000&(data))>>21)
#define  RIF_REG_HEVCSEQCNTL_ctbsize_src(data)                                   ((0x00180000&(data))>>19)
#define  RIF_REG_HEVCSEQCNTL_min_trafo_size_src(data)                            ((0x00060000&(data))>>17)
#define  RIF_REG_HEVCSEQCNTL_max_trafo_size_src(data)                            ((0x00018000&(data))>>15)
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_inter_src(data)                ((0x00007000&(data))>>12)
#define  RIF_REG_HEVCSEQCNTL_max_trans_hier_depth_intra_src(data)                ((0x00000E00&(data))>>9)
#define  RIF_REG_HEVCSEQCNTL_amp_enabled_flag_src(data)                          ((0x00000100&(data))>>8)
#define  RIF_REG_HEVCSEQCNTL_sample_adaptive_offset_enabled_flag_src(data)       ((0x00000080&(data))>>7)
#define  RIF_REG_HEVCSEQCNTL_pcm_enabled_flag_src(data)                          ((0x00000040&(data))>>6)
#define  RIF_REG_HEVCSEQCNTL_min_ipcm_cbsize_src(data)                           ((0x00000030&(data))>>4)
#define  RIF_REG_HEVCSEQCNTL_max_ipcm_cbsize_src(data)                           ((0x0000000C&(data))>>2)
#define  RIF_REG_HEVCSEQCNTL_pcm_loop_filter_disable_flag_src(data)              ((0x00000002&(data))>>1)
#define  RIF_REG_HEVCSEQCNTL_strong_intra_smoothing_enable_flag_src(data)        (0x00000001&(data))

#define  RIF_REG_HEVCPICCNTL                                                     0x1800E468
#define  RIF_REG_HEVCPICCNTL_reg_addr                                            "0xB800E468"
#define  RIF_REG_HEVCPICCNTL_reg                                                 0xB800E468
#define  RIF_REG_HEVCPICCNTL_inst_addr                                           "0x000E"
#define  RIF_REG_HEVCPICCNTL_inst_adr                                            "0x001A"
#define  RIF_REG_HEVCPICCNTL_inst                                                0x001A
#define  set_RIF_REG_HEVCPICCNTL_reg(data)                                       (*((volatile unsigned int*)RIF_REG_HEVCPICCNTL_reg)=data)
#define  get_RIF_REG_HEVCPICCNTL_reg                                             (*((volatile unsigned int*)RIF_REG_HEVCPICCNTL_reg))
#define  RIF_REG_HEVCPICCNTL_transform_skip_enabled_flag_shift                   (19)
#define  RIF_REG_HEVCPICCNTL_cu_qp_delta_enabled_flag_shift                      (18)
#define  RIF_REG_HEVCPICCNTL_min_cu_qp_delta_size_shift                          (15)
#define  RIF_REG_HEVCPICCNTL_pic_cb_qp_offset_shift                              (10)
#define  RIF_REG_HEVCPICCNTL_pic_cr_qp_offset_shift                              (5)
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_tiles_enabled_flag_shift         (4)
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_slices_enabled_flag_shift        (3)
#define  RIF_REG_HEVCPICCNTL_log2_parallel_merge_level_minus2_shift              (0)
#define  RIF_REG_HEVCPICCNTL_transform_skip_enabled_flag_mask                    (0x00080000)
#define  RIF_REG_HEVCPICCNTL_cu_qp_delta_enabled_flag_mask                       (0x00040000)
#define  RIF_REG_HEVCPICCNTL_min_cu_qp_delta_size_mask                           (0x00038000)
#define  RIF_REG_HEVCPICCNTL_pic_cb_qp_offset_mask                               (0x00007C00)
#define  RIF_REG_HEVCPICCNTL_pic_cr_qp_offset_mask                               (0x000003E0)
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_tiles_enabled_flag_mask          (0x00000010)
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_slices_enabled_flag_mask         (0x00000008)
#define  RIF_REG_HEVCPICCNTL_log2_parallel_merge_level_minus2_mask               (0x00000007)
#define  RIF_REG_HEVCPICCNTL_transform_skip_enabled_flag(data)                   (0x00080000&((data)<<19))
#define  RIF_REG_HEVCPICCNTL_cu_qp_delta_enabled_flag(data)                      (0x00040000&((data)<<18))
#define  RIF_REG_HEVCPICCNTL_min_cu_qp_delta_size(data)                          (0x00038000&((data)<<15))
#define  RIF_REG_HEVCPICCNTL_pic_cb_qp_offset(data)                              (0x00007C00&((data)<<10))
#define  RIF_REG_HEVCPICCNTL_pic_cr_qp_offset(data)                              (0x000003E0&((data)<<5))
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_tiles_enabled_flag(data)         (0x00000010&((data)<<4))
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_slices_enabled_flag(data)        (0x00000008&((data)<<3))
#define  RIF_REG_HEVCPICCNTL_log2_parallel_merge_level_minus2(data)              (0x00000007&(data))
#define  RIF_REG_HEVCPICCNTL_get_transform_skip_enabled_flag(data)               ((0x00080000&(data))>>19)
#define  RIF_REG_HEVCPICCNTL_get_cu_qp_delta_enabled_flag(data)                  ((0x00040000&(data))>>18)
#define  RIF_REG_HEVCPICCNTL_get_min_cu_qp_delta_size(data)                      ((0x00038000&(data))>>15)
#define  RIF_REG_HEVCPICCNTL_get_pic_cb_qp_offset(data)                          ((0x00007C00&(data))>>10)
#define  RIF_REG_HEVCPICCNTL_get_pic_cr_qp_offset(data)                          ((0x000003E0&(data))>>5)
#define  RIF_REG_HEVCPICCNTL_get_loop_filter_across_tiles_enabled_flag(data)     ((0x00000010&(data))>>4)
#define  RIF_REG_HEVCPICCNTL_get_loop_filter_across_slices_enabled_flag(data)    ((0x00000008&(data))>>3)
#define  RIF_REG_HEVCPICCNTL_get_log2_parallel_merge_level_minus2(data)          (0x00000007&(data))
#define  RIF_REG_HEVCPICCNTL_transform_skip_enabled_flag_src(data)               ((0x00080000&(data))>>19)
#define  RIF_REG_HEVCPICCNTL_cu_qp_delta_enabled_flag_src(data)                  ((0x00040000&(data))>>18)
#define  RIF_REG_HEVCPICCNTL_min_cu_qp_delta_size_src(data)                      ((0x00038000&(data))>>15)
#define  RIF_REG_HEVCPICCNTL_pic_cb_qp_offset_src(data)                          ((0x00007C00&(data))>>10)
#define  RIF_REG_HEVCPICCNTL_pic_cr_qp_offset_src(data)                          ((0x000003E0&(data))>>5)
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_tiles_enabled_flag_src(data)     ((0x00000010&(data))>>4)
#define  RIF_REG_HEVCPICCNTL_loop_filter_across_slices_enabled_flag_src(data)    ((0x00000008&(data))>>3)
#define  RIF_REG_HEVCPICCNTL_log2_parallel_merge_level_minus2_src(data)          (0x00000007&(data))

#define  RIF_REG_HEVCPICSIZE                                                     0x1800E46C
#define  RIF_REG_HEVCPICSIZE_reg_addr                                            "0xB800E46C"
#define  RIF_REG_HEVCPICSIZE_reg                                                 0xB800E46C
#define  RIF_REG_HEVCPICSIZE_inst_addr                                           "0x000F"
#define  RIF_REG_HEVCPICSIZE_inst_adr                                            "0x001B"
#define  RIF_REG_HEVCPICSIZE_inst                                                0x001B
#define  set_RIF_REG_HEVCPICSIZE_reg(data)                                       (*((volatile unsigned int*)RIF_REG_HEVCPICSIZE_reg)=data)
#define  get_RIF_REG_HEVCPICSIZE_reg                                             (*((volatile unsigned int*)RIF_REG_HEVCPICSIZE_reg))
#define  RIF_REG_HEVCPICSIZE_pic_width_shift                                     (13)
#define  RIF_REG_HEVCPICSIZE_pic_height_shift                                    (0)
#define  RIF_REG_HEVCPICSIZE_pic_width_mask                                      (0x07FFE000)
#define  RIF_REG_HEVCPICSIZE_pic_height_mask                                     (0x00001FFF)
#define  RIF_REG_HEVCPICSIZE_pic_width(data)                                     (0x07FFE000&((data)<<13))
#define  RIF_REG_HEVCPICSIZE_pic_height(data)                                    (0x00001FFF&(data))
#define  RIF_REG_HEVCPICSIZE_get_pic_width(data)                                 ((0x07FFE000&(data))>>13)
#define  RIF_REG_HEVCPICSIZE_get_pic_height(data)                                (0x00001FFF&(data))
#define  RIF_REG_HEVCPICSIZE_pic_width_src(data)                                 ((0x07FFE000&(data))>>13)
#define  RIF_REG_HEVCPICSIZE_pic_height_src(data)                                (0x00001FFF&(data))

#define  RIF_REG_VC1PICCNTL                                                      0x1800E470
#define  RIF_REG_VC1PICCNTL_reg_addr                                             "0xB800E470"
#define  RIF_REG_VC1PICCNTL_reg                                                  0xB800E470
#define  RIF_REG_VC1PICCNTL_inst_addr                                            "0x0010"
#define  RIF_REG_VC1PICCNTL_inst_adr                                             "0x001C"
#define  RIF_REG_VC1PICCNTL_inst                                                 0x001C
#define  set_RIF_REG_VC1PICCNTL_reg(data)                                        (*((volatile unsigned int*)RIF_REG_VC1PICCNTL_reg)=data)
#define  get_RIF_REG_VC1PICCNTL_reg                                              (*((volatile unsigned int*)RIF_REG_VC1PICCNTL_reg))
#define  RIF_REG_VC1PICCNTL_Overlap_enable_shift                                 (31)
#define  RIF_REG_VC1PICCNTL_field_pictype_shift                                  (28)
#define  RIF_REG_VC1PICCNTL_mvmode_shift                                         (26)
#define  RIF_REG_VC1PICCNTL_fcm_shift                                            (24)
#define  RIF_REG_VC1PICCNTL_disppic_h_shift                                      (12)
#define  RIF_REG_VC1PICCNTL_disppic_w_shift                                      (0)
#define  RIF_REG_VC1PICCNTL_Overlap_enable_mask                                  (0x80000000)
#define  RIF_REG_VC1PICCNTL_field_pictype_mask                                   (0x70000000)
#define  RIF_REG_VC1PICCNTL_mvmode_mask                                          (0x0C000000)
#define  RIF_REG_VC1PICCNTL_fcm_mask                                             (0x03000000)
#define  RIF_REG_VC1PICCNTL_disppic_h_mask                                       (0x00FFF000)
#define  RIF_REG_VC1PICCNTL_disppic_w_mask                                       (0x00000FFF)
#define  RIF_REG_VC1PICCNTL_Overlap_enable(data)                                 (0x80000000&((data)<<31))
#define  RIF_REG_VC1PICCNTL_field_pictype(data)                                  (0x70000000&((data)<<28))
#define  RIF_REG_VC1PICCNTL_mvmode(data)                                         (0x0C000000&((data)<<26))
#define  RIF_REG_VC1PICCNTL_fcm(data)                                            (0x03000000&((data)<<24))
#define  RIF_REG_VC1PICCNTL_disppic_h(data)                                      (0x00FFF000&((data)<<12))
#define  RIF_REG_VC1PICCNTL_disppic_w(data)                                      (0x00000FFF&(data))
#define  RIF_REG_VC1PICCNTL_get_Overlap_enable(data)                             ((0x80000000&(data))>>31)
#define  RIF_REG_VC1PICCNTL_get_field_pictype(data)                              ((0x70000000&(data))>>28)
#define  RIF_REG_VC1PICCNTL_get_mvmode(data)                                     ((0x0C000000&(data))>>26)
#define  RIF_REG_VC1PICCNTL_get_fcm(data)                                        ((0x03000000&(data))>>24)
#define  RIF_REG_VC1PICCNTL_get_disppic_h(data)                                  ((0x00FFF000&(data))>>12)
#define  RIF_REG_VC1PICCNTL_get_disppic_w(data)                                  (0x00000FFF&(data))
#define  RIF_REG_VC1PICCNTL_Overlap_enable_src(data)                             ((0x80000000&(data))>>31)
#define  RIF_REG_VC1PICCNTL_field_pictype_src(data)                              ((0x70000000&(data))>>28)
#define  RIF_REG_VC1PICCNTL_mvmode_src(data)                                     ((0x0C000000&(data))>>26)
#define  RIF_REG_VC1PICCNTL_fcm_src(data)                                        ((0x03000000&(data))>>24)
#define  RIF_REG_VC1PICCNTL_disppic_h_src(data)                                  ((0x00FFF000&(data))>>12)
#define  RIF_REG_VC1PICCNTL_disppic_w_src(data)                                  (0x00000FFF&(data))

#define  RIF_REG_VC1PICCNTL2                                                     0x1800E474
#define  RIF_REG_VC1PICCNTL2_reg_addr                                            "0xB800E474"
#define  RIF_REG_VC1PICCNTL2_reg                                                 0xB800E474
#define  RIF_REG_VC1PICCNTL2_inst_addr                                           "0x0011"
#define  RIF_REG_VC1PICCNTL2_inst_adr                                            "0x001D"
#define  RIF_REG_VC1PICCNTL2_inst                                                0x001D
#define  set_RIF_REG_VC1PICCNTL2_reg(data)                                       (*((volatile unsigned int*)RIF_REG_VC1PICCNTL2_reg)=data)
#define  get_RIF_REG_VC1PICCNTL2_reg                                             (*((volatile unsigned int*)RIF_REG_VC1PICCNTL2_reg))
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_rtmflag_shift                              (8)
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_it_shift                                   (7)
#define  RIF_REG_VC1PICCNTL2_loopfilter_shift                                    (6)
#define  RIF_REG_VC1PICCNTL2_numref_shift                                        (5)
#define  RIF_REG_VC1PICCNTL2_pquant_shift                                        (0)
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_rtmflag_mask                               (0x00000100)
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_it_mask                                    (0x00000080)
#define  RIF_REG_VC1PICCNTL2_loopfilter_mask                                     (0x00000040)
#define  RIF_REG_VC1PICCNTL2_numref_mask                                         (0x00000020)
#define  RIF_REG_VC1PICCNTL2_pquant_mask                                         (0x0000001F)
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_rtmflag(data)                              (0x00000100&((data)<<8))
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_it(data)                                   (0x00000080&((data)<<7))
#define  RIF_REG_VC1PICCNTL2_loopfilter(data)                                    (0x00000040&((data)<<6))
#define  RIF_REG_VC1PICCNTL2_numref(data)                                        (0x00000020&((data)<<5))
#define  RIF_REG_VC1PICCNTL2_pquant(data)                                        (0x0000001F&(data))
#define  RIF_REG_VC1PICCNTL2_get_wmv9_bug_rtmflag(data)                          ((0x00000100&(data))>>8)
#define  RIF_REG_VC1PICCNTL2_get_wmv9_bug_it(data)                               ((0x00000080&(data))>>7)
#define  RIF_REG_VC1PICCNTL2_get_loopfilter(data)                                ((0x00000040&(data))>>6)
#define  RIF_REG_VC1PICCNTL2_get_numref(data)                                    ((0x00000020&(data))>>5)
#define  RIF_REG_VC1PICCNTL2_get_pquant(data)                                    (0x0000001F&(data))
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_rtmflag_src(data)                          ((0x00000100&(data))>>8)
#define  RIF_REG_VC1PICCNTL2_wmv9_bug_it_src(data)                               ((0x00000080&(data))>>7)
#define  RIF_REG_VC1PICCNTL2_loopfilter_src(data)                                ((0x00000040&(data))>>6)
#define  RIF_REG_VC1PICCNTL2_numref_src(data)                                    ((0x00000020&(data))>>5)
#define  RIF_REG_VC1PICCNTL2_pquant_src(data)                                    (0x0000001F&(data))

#define  RIF_REG_SCALE_FP_0                                                      0x1800E480
#define  RIF_REG_SCALE_FP_0_reg_addr                                             "0xB800E480"
#define  RIF_REG_SCALE_FP_0_reg                                                  0xB800E480
#define  RIF_REG_SCALE_FP_0_inst_addr                                            "0x0012"
#define  RIF_REG_SCALE_FP_0_inst_adr                                             "0x0020"
#define  RIF_REG_SCALE_FP_0_inst                                                 0x0020
#define  set_RIF_REG_SCALE_FP_0_reg(data)                                        (*((volatile unsigned int*)RIF_REG_SCALE_FP_0_reg)=data)
#define  get_RIF_REG_SCALE_FP_0_reg                                              (*((volatile unsigned int*)RIF_REG_SCALE_FP_0_reg))
#define  RIF_REG_SCALE_FP_x_scale_fp_shift                                       (16)
#define  RIF_REG_SCALE_FP_y_scale_fp_shift                                       (0)
#define  RIF_REG_SCALE_FP_x_scale_fp_mask                                        (0xFFFF0000)
#define  RIF_REG_SCALE_FP_y_scale_fp_mask                                        (0x0000FFFF)
#define  RIF_REG_SCALE_FP_x_scale_fp(data)                                       (0xFFFF0000&((data)<<16))
#define  RIF_REG_SCALE_FP_y_scale_fp(data)                                       (0x0000FFFF&(data))
#define  RIF_REG_SCALE_FP_get_x_scale_fp(data)                                   ((0xFFFF0000&(data))>>16)
#define  RIF_REG_SCALE_FP_get_y_scale_fp(data)                                   (0x0000FFFF&(data))
#define  RIF_REG_SCALE_FP_x_scale_fp_src(data)                                   ((0xFFFF0000&(data))>>16)
#define  RIF_REG_SCALE_FP_y_scale_fp_src(data)                                   (0x0000FFFF&(data))

#define  RIF_REG_SCALE_FP_1                                                      0x1800E484
#define  RIF_REG_SCALE_FP_1_reg_addr                                             "0xB800E484"
#define  RIF_REG_SCALE_FP_1_reg                                                  0xB800E484
#define  RIF_REG_SCALE_FP_1_inst_addr                                            "0x0013"
#define  RIF_REG_SCALE_FP_1_inst_adr                                             "0x0021"
#define  RIF_REG_SCALE_FP_1_inst                                                 0x0021
#define  set_RIF_REG_SCALE_FP_1_reg(data)                                        (*((volatile unsigned int*)RIF_REG_SCALE_FP_1_reg)=data)
#define  get_RIF_REG_SCALE_FP_1_reg                                              (*((volatile unsigned int*)RIF_REG_SCALE_FP_1_reg))

#define  RIF_REG_SCALE_FP_2                                                      0x1800E488
#define  RIF_REG_SCALE_FP_2_reg_addr                                             "0xB800E488"
#define  RIF_REG_SCALE_FP_2_reg                                                  0xB800E488
#define  RIF_REG_SCALE_FP_2_inst_addr                                            "0x0014"
#define  RIF_REG_SCALE_FP_2_inst_adr                                             "0x0022"
#define  RIF_REG_SCALE_FP_2_inst                                                 0x0022
#define  set_RIF_REG_SCALE_FP_2_reg(data)                                        (*((volatile unsigned int*)RIF_REG_SCALE_FP_2_reg)=data)
#define  get_RIF_REG_SCALE_FP_2_reg                                              (*((volatile unsigned int*)RIF_REG_SCALE_FP_2_reg))

#define  RIF_REG_BRG_CTRL                                                        0x1800E490
#define  RIF_REG_BRG_CTRL_reg_addr                                               "0xB800E490"
#define  RIF_REG_BRG_CTRL_reg                                                    0xB800E490
#define  RIF_REG_BRG_CTRL_inst_addr                                              "0x0015"
#define  RIF_REG_BRG_CTRL_inst_adr                                               "0x0024"
#define  RIF_REG_BRG_CTRL_inst                                                   0x0024
#define  set_RIF_REG_BRG_CTRL_reg(data)                                          (*((volatile unsigned int*)RIF_REG_BRG_CTRL_reg)=data)
#define  get_RIF_REG_BRG_CTRL_reg                                                (*((volatile unsigned int*)RIF_REG_BRG_CTRL_reg))
#define  RIF_REG_BRG_CTRL_priority_thd2_shift                                    (16)
#define  RIF_REG_BRG_CTRL_priority_thd1_shift                                    (8)
#define  RIF_REG_BRG_CTRL_srg_mode_shift                                         (3)
#define  RIF_REG_BRG_CTRL_ddr_page_shift                                         (1)
#define  RIF_REG_BRG_CTRL_srg_enable_shift                                       (0)
#define  RIF_REG_BRG_CTRL_priority_thd2_mask                                     (0x00FF0000)
#define  RIF_REG_BRG_CTRL_priority_thd1_mask                                     (0x0000FF00)
#define  RIF_REG_BRG_CTRL_srg_mode_mask                                          (0x00000008)
#define  RIF_REG_BRG_CTRL_ddr_page_mask                                          (0x00000006)
#define  RIF_REG_BRG_CTRL_srg_enable_mask                                        (0x00000001)
#define  RIF_REG_BRG_CTRL_priority_thd2(data)                                    (0x00FF0000&((data)<<16))
#define  RIF_REG_BRG_CTRL_priority_thd1(data)                                    (0x0000FF00&((data)<<8))
#define  RIF_REG_BRG_CTRL_srg_mode(data)                                         (0x00000008&((data)<<3))
#define  RIF_REG_BRG_CTRL_ddr_page(data)                                         (0x00000006&((data)<<1))
#define  RIF_REG_BRG_CTRL_srg_enable(data)                                       (0x00000001&(data))
#define  RIF_REG_BRG_CTRL_get_priority_thd2(data)                                ((0x00FF0000&(data))>>16)
#define  RIF_REG_BRG_CTRL_get_priority_thd1(data)                                ((0x0000FF00&(data))>>8)
#define  RIF_REG_BRG_CTRL_get_srg_mode(data)                                     ((0x00000008&(data))>>3)
#define  RIF_REG_BRG_CTRL_get_ddr_page(data)                                     ((0x00000006&(data))>>1)
#define  RIF_REG_BRG_CTRL_get_srg_enable(data)                                   (0x00000001&(data))
#define  RIF_REG_BRG_CTRL_priority_thd2_src(data)                                ((0x00FF0000&(data))>>16)
#define  RIF_REG_BRG_CTRL_priority_thd1_src(data)                                ((0x0000FF00&(data))>>8)
#define  RIF_REG_BRG_CTRL_srg_mode_src(data)                                     ((0x00000008&(data))>>3)
#define  RIF_REG_BRG_CTRL_ddr_page_src(data)                                     ((0x00000006&(data))>>1)
#define  RIF_REG_BRG_CTRL_srg_enable_src(data)                                   (0x00000001&(data))

#define  RIF_REG_RD_PRIORITY0                                                    0x1800E494
#define  RIF_REG_RD_PRIORITY0_reg_addr                                           "0xB800E494"
#define  RIF_REG_RD_PRIORITY0_reg                                                0xB800E494
#define  RIF_REG_RD_PRIORITY0_inst_addr                                          "0x0016"
#define  RIF_REG_RD_PRIORITY0_inst_adr                                           "0x0025"
#define  RIF_REG_RD_PRIORITY0_inst                                               0x0025
#define  set_RIF_REG_RD_PRIORITY0_reg(data)                                      (*((volatile unsigned int*)RIF_REG_RD_PRIORITY0_reg)=data)
#define  get_RIF_REG_RD_PRIORITY0_reg                                            (*((volatile unsigned int*)RIF_REG_RD_PRIORITY0_reg))
#define  RIF_REG_RD_PRIORITY0_vm2_shift                                          (16)
#define  RIF_REG_RD_PRIORITY0_vm1_shift                                          (0)
#define  RIF_REG_RD_PRIORITY0_vm2_mask                                           (0x0FFF0000)
#define  RIF_REG_RD_PRIORITY0_vm1_mask                                           (0x00000FFF)
#define  RIF_REG_RD_PRIORITY0_vm2(data)                                          (0x0FFF0000&((data)<<16))
#define  RIF_REG_RD_PRIORITY0_vm1(data)                                          (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY0_get_vm2(data)                                      ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY0_get_vm1(data)                                      (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY0_vm2_src(data)                                      ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY0_vm1_src(data)                                      (0x00000FFF&(data))

#define  RIF_REG_RD_PRIORITY1                                                    0x1800E498
#define  RIF_REG_RD_PRIORITY1_reg_addr                                           "0xB800E498"
#define  RIF_REG_RD_PRIORITY1_reg                                                0xB800E498
#define  RIF_REG_RD_PRIORITY1_inst_addr                                          "0x0017"
#define  RIF_REG_RD_PRIORITY1_inst_adr                                           "0x0026"
#define  RIF_REG_RD_PRIORITY1_inst                                               0x0026
#define  set_RIF_REG_RD_PRIORITY1_reg(data)                                      (*((volatile unsigned int*)RIF_REG_RD_PRIORITY1_reg)=data)
#define  get_RIF_REG_RD_PRIORITY1_reg                                            (*((volatile unsigned int*)RIF_REG_RD_PRIORITY1_reg))
#define  RIF_REG_RD_PRIORITY1_deblk_shift                                        (16)
#define  RIF_REG_RD_PRIORITY1_predblk_shift                                      (0)
#define  RIF_REG_RD_PRIORITY1_deblk_mask                                         (0x0FFF0000)
#define  RIF_REG_RD_PRIORITY1_predblk_mask                                       (0x00000FFF)
#define  RIF_REG_RD_PRIORITY1_deblk(data)                                        (0x0FFF0000&((data)<<16))
#define  RIF_REG_RD_PRIORITY1_predblk(data)                                      (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY1_get_deblk(data)                                    ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY1_get_predblk(data)                                  (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY1_deblk_src(data)                                    ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY1_predblk_src(data)                                  (0x00000FFF&(data))

#define  RIF_REG_RD_PRIORITY2                                                    0x1800E49C
#define  RIF_REG_RD_PRIORITY2_reg_addr                                           "0xB800E49C"
#define  RIF_REG_RD_PRIORITY2_reg                                                0xB800E49C
#define  RIF_REG_RD_PRIORITY2_inst_addr                                          "0x0018"
#define  RIF_REG_RD_PRIORITY2_inst_adr                                           "0x0027"
#define  RIF_REG_RD_PRIORITY2_inst                                               0x0027
#define  set_RIF_REG_RD_PRIORITY2_reg(data)                                      (*((volatile unsigned int*)RIF_REG_RD_PRIORITY2_reg)=data)
#define  get_RIF_REG_RD_PRIORITY2_reg                                            (*((volatile unsigned int*)RIF_REG_RD_PRIORITY2_reg))
#define  RIF_REG_RD_PRIORITY2_nm_shift                                           (16)
#define  RIF_REG_RD_PRIORITY2_mvd_shift                                          (0)
#define  RIF_REG_RD_PRIORITY2_nm_mask                                            (0x0FFF0000)
#define  RIF_REG_RD_PRIORITY2_mvd_mask                                           (0x00000FFF)
#define  RIF_REG_RD_PRIORITY2_nm(data)                                           (0x0FFF0000&((data)<<16))
#define  RIF_REG_RD_PRIORITY2_mvd(data)                                          (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY2_get_nm(data)                                       ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY2_get_mvd(data)                                      (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY2_nm_src(data)                                       ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY2_mvd_src(data)                                      (0x00000FFF&(data))

#define  RIF_REG_RD_PRIORITY3                                                    0x1800E4A0
#define  RIF_REG_RD_PRIORITY3_reg_addr                                           "0xB800E4A0"
#define  RIF_REG_RD_PRIORITY3_reg                                                0xB800E4A0
#define  RIF_REG_RD_PRIORITY3_inst_addr                                          "0x0019"
#define  RIF_REG_RD_PRIORITY3_inst_adr                                           "0x0028"
#define  RIF_REG_RD_PRIORITY3_inst                                               0x0028
#define  set_RIF_REG_RD_PRIORITY3_reg(data)                                      (*((volatile unsigned int*)RIF_REG_RD_PRIORITY3_reg)=data)
#define  get_RIF_REG_RD_PRIORITY3_reg                                            (*((volatile unsigned int*)RIF_REG_RD_PRIORITY3_reg))
#define  RIF_REG_RD_PRIORITY3_gcoeff_shift                                       (16)
#define  RIF_REG_RD_PRIORITY3_bs_shift                                           (0)
#define  RIF_REG_RD_PRIORITY3_gcoeff_mask                                        (0x0FFF0000)
#define  RIF_REG_RD_PRIORITY3_bs_mask                                            (0x00000FFF)
#define  RIF_REG_RD_PRIORITY3_gcoeff(data)                                       (0x0FFF0000&((data)<<16))
#define  RIF_REG_RD_PRIORITY3_bs(data)                                           (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY3_get_gcoeff(data)                                   ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY3_get_bs(data)                                       (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY3_gcoeff_src(data)                                   ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY3_bs_src(data)                                       (0x00000FFF&(data))

#define  RIF_REG_RD_PRIORITY4                                                    0x1800E4A4
#define  RIF_REG_RD_PRIORITY4_reg_addr                                           "0xB800E4A4"
#define  RIF_REG_RD_PRIORITY4_reg                                                0xB800E4A4
#define  RIF_REG_RD_PRIORITY4_inst_addr                                          "0x001A"
#define  RIF_REG_RD_PRIORITY4_inst_adr                                           "0x0029"
#define  RIF_REG_RD_PRIORITY4_inst                                               0x0029
#define  set_RIF_REG_RD_PRIORITY4_reg(data)                                      (*((volatile unsigned int*)RIF_REG_RD_PRIORITY4_reg)=data)
#define  get_RIF_REG_RD_PRIORITY4_reg                                            (*((volatile unsigned int*)RIF_REG_RD_PRIORITY4_reg))
#define  RIF_REG_RD_PRIORITY4_cmp_shift                                          (16)
#define  RIF_REG_RD_PRIORITY4_rl_shift                                           (0)
#define  RIF_REG_RD_PRIORITY4_cmp_mask                                           (0x0FFF0000)
#define  RIF_REG_RD_PRIORITY4_rl_mask                                            (0x00000FFF)
#define  RIF_REG_RD_PRIORITY4_cmp(data)                                          (0x0FFF0000&((data)<<16))
#define  RIF_REG_RD_PRIORITY4_rl(data)                                           (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY4_get_cmp(data)                                      ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY4_get_rl(data)                                       (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY4_cmp_src(data)                                      ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY4_rl_src(data)                                       (0x00000FFF&(data))

#define  RIF_REG_RD_PRIORITY5                                                    0x1800E4A8
#define  RIF_REG_RD_PRIORITY5_reg_addr                                           "0xB800E4A8"
#define  RIF_REG_RD_PRIORITY5_reg                                                0xB800E4A8
#define  RIF_REG_RD_PRIORITY5_inst_addr                                          "0x001B"
#define  RIF_REG_RD_PRIORITY5_inst_adr                                           "0x002A"
#define  RIF_REG_RD_PRIORITY5_inst                                               0x002A
#define  set_RIF_REG_RD_PRIORITY5_reg(data)                                      (*((volatile unsigned int*)RIF_REG_RD_PRIORITY5_reg)=data)
#define  get_RIF_REG_RD_PRIORITY5_reg                                            (*((volatile unsigned int*)RIF_REG_RD_PRIORITY5_reg))
#define  RIF_REG_RD_PRIORITY5_fme_shift                                          (16)
#define  RIF_REG_RD_PRIORITY5_ime_shift                                          (0)
#define  RIF_REG_RD_PRIORITY5_fme_mask                                           (0x0FFF0000)
#define  RIF_REG_RD_PRIORITY5_ime_mask                                           (0x00000FFF)
#define  RIF_REG_RD_PRIORITY5_fme(data)                                          (0x0FFF0000&((data)<<16))
#define  RIF_REG_RD_PRIORITY5_ime(data)                                          (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY5_get_fme(data)                                      ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY5_get_ime(data)                                      (0x00000FFF&(data))
#define  RIF_REG_RD_PRIORITY5_fme_src(data)                                      ((0x0FFF0000&(data))>>16)
#define  RIF_REG_RD_PRIORITY5_ime_src(data)                                      (0x00000FFF&(data))

#define  RIF_REG_WT_PRIORITY0                                                    0x1800E4B0
#define  RIF_REG_WT_PRIORITY0_reg_addr                                           "0xB800E4B0"
#define  RIF_REG_WT_PRIORITY0_reg                                                0xB800E4B0
#define  RIF_REG_WT_PRIORITY0_inst_addr                                          "0x001C"
#define  RIF_REG_WT_PRIORITY0_inst_adr                                           "0x002C"
#define  RIF_REG_WT_PRIORITY0_inst                                               0x002C
#define  set_RIF_REG_WT_PRIORITY0_reg(data)                                      (*((volatile unsigned int*)RIF_REG_WT_PRIORITY0_reg)=data)
#define  get_RIF_REG_WT_PRIORITY0_reg                                            (*((volatile unsigned int*)RIF_REG_WT_PRIORITY0_reg))
#define  RIF_REG_WT_PRIORITY0_vm2_shift                                          (16)
#define  RIF_REG_WT_PRIORITY0_vm1_shift                                          (0)
#define  RIF_REG_WT_PRIORITY0_vm2_mask                                           (0x07FF0000)
#define  RIF_REG_WT_PRIORITY0_vm1_mask                                           (0x000007FF)
#define  RIF_REG_WT_PRIORITY0_vm2(data)                                          (0x07FF0000&((data)<<16))
#define  RIF_REG_WT_PRIORITY0_vm1(data)                                          (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY0_get_vm2(data)                                      ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY0_get_vm1(data)                                      (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY0_vm2_src(data)                                      ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY0_vm1_src(data)                                      (0x000007FF&(data))

#define  RIF_REG_WT_PRIORITY1                                                    0x1800E4B4
#define  RIF_REG_WT_PRIORITY1_reg_addr                                           "0xB800E4B4"
#define  RIF_REG_WT_PRIORITY1_reg                                                0xB800E4B4
#define  RIF_REG_WT_PRIORITY1_inst_addr                                          "0x001D"
#define  RIF_REG_WT_PRIORITY1_inst_adr                                           "0x002D"
#define  RIF_REG_WT_PRIORITY1_inst                                               0x002D
#define  set_RIF_REG_WT_PRIORITY1_reg(data)                                      (*((volatile unsigned int*)RIF_REG_WT_PRIORITY1_reg)=data)
#define  get_RIF_REG_WT_PRIORITY1_reg                                            (*((volatile unsigned int*)RIF_REG_WT_PRIORITY1_reg))
#define  RIF_REG_WT_PRIORITY1_deblk_shift                                        (16)
#define  RIF_REG_WT_PRIORITY1_predblk_shift                                      (0)
#define  RIF_REG_WT_PRIORITY1_deblk_mask                                         (0x07FF0000)
#define  RIF_REG_WT_PRIORITY1_predblk_mask                                       (0x000007FF)
#define  RIF_REG_WT_PRIORITY1_deblk(data)                                        (0x07FF0000&((data)<<16))
#define  RIF_REG_WT_PRIORITY1_predblk(data)                                      (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY1_get_deblk(data)                                    ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY1_get_predblk(data)                                  (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY1_deblk_src(data)                                    ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY1_predblk_src(data)                                  (0x000007FF&(data))

#define  RIF_REG_WT_PRIORITY2                                                    0x1800E4B8
#define  RIF_REG_WT_PRIORITY2_reg_addr                                           "0xB800E4B8"
#define  RIF_REG_WT_PRIORITY2_reg                                                0xB800E4B8
#define  RIF_REG_WT_PRIORITY2_inst_addr                                          "0x001E"
#define  RIF_REG_WT_PRIORITY2_inst_adr                                           "0x002E"
#define  RIF_REG_WT_PRIORITY2_inst                                               0x002E
#define  set_RIF_REG_WT_PRIORITY2_reg(data)                                      (*((volatile unsigned int*)RIF_REG_WT_PRIORITY2_reg)=data)
#define  get_RIF_REG_WT_PRIORITY2_reg                                            (*((volatile unsigned int*)RIF_REG_WT_PRIORITY2_reg))
#define  RIF_REG_WT_PRIORITY2_nm_shift                                           (16)
#define  RIF_REG_WT_PRIORITY2_mvd_shift                                          (0)
#define  RIF_REG_WT_PRIORITY2_nm_mask                                            (0x07FF0000)
#define  RIF_REG_WT_PRIORITY2_mvd_mask                                           (0x000007FF)
#define  RIF_REG_WT_PRIORITY2_nm(data)                                           (0x07FF0000&((data)<<16))
#define  RIF_REG_WT_PRIORITY2_mvd(data)                                          (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY2_get_nm(data)                                       ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY2_get_mvd(data)                                      (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY2_nm_src(data)                                       ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY2_mvd_src(data)                                      (0x000007FF&(data))

#define  RIF_REG_WT_PRIORITY3                                                    0x1800E4BC
#define  RIF_REG_WT_PRIORITY3_reg_addr                                           "0xB800E4BC"
#define  RIF_REG_WT_PRIORITY3_reg                                                0xB800E4BC
#define  RIF_REG_WT_PRIORITY3_inst_addr                                          "0x001F"
#define  RIF_REG_WT_PRIORITY3_inst_adr                                           "0x002F"
#define  RIF_REG_WT_PRIORITY3_inst                                               0x002F
#define  set_RIF_REG_WT_PRIORITY3_reg(data)                                      (*((volatile unsigned int*)RIF_REG_WT_PRIORITY3_reg)=data)
#define  get_RIF_REG_WT_PRIORITY3_reg                                            (*((volatile unsigned int*)RIF_REG_WT_PRIORITY3_reg))
#define  RIF_REG_WT_PRIORITY3_gcoeff_shift                                       (16)
#define  RIF_REG_WT_PRIORITY3_bs_shift                                           (0)
#define  RIF_REG_WT_PRIORITY3_gcoeff_mask                                        (0x07FF0000)
#define  RIF_REG_WT_PRIORITY3_bs_mask                                            (0x000007FF)
#define  RIF_REG_WT_PRIORITY3_gcoeff(data)                                       (0x07FF0000&((data)<<16))
#define  RIF_REG_WT_PRIORITY3_bs(data)                                           (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY3_get_gcoeff(data)                                   ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY3_get_bs(data)                                       (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY3_gcoeff_src(data)                                   ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY3_bs_src(data)                                       (0x000007FF&(data))

#define  RIF_REG_WT_PRIORITY4                                                    0x1800E4C0
#define  RIF_REG_WT_PRIORITY4_reg_addr                                           "0xB800E4C0"
#define  RIF_REG_WT_PRIORITY4_reg                                                0xB800E4C0
#define  RIF_REG_WT_PRIORITY4_inst_addr                                          "0x0020"
#define  RIF_REG_WT_PRIORITY4_inst_adr                                           "0x0030"
#define  RIF_REG_WT_PRIORITY4_inst                                               0x0030
#define  set_RIF_REG_WT_PRIORITY4_reg(data)                                      (*((volatile unsigned int*)RIF_REG_WT_PRIORITY4_reg)=data)
#define  get_RIF_REG_WT_PRIORITY4_reg                                            (*((volatile unsigned int*)RIF_REG_WT_PRIORITY4_reg))
#define  RIF_REG_WT_PRIORITY4_cmp_shift                                          (16)
#define  RIF_REG_WT_PRIORITY4_it_shift                                           (0)
#define  RIF_REG_WT_PRIORITY4_cmp_mask                                           (0x07FF0000)
#define  RIF_REG_WT_PRIORITY4_it_mask                                            (0x000007FF)
#define  RIF_REG_WT_PRIORITY4_cmp(data)                                          (0x07FF0000&((data)<<16))
#define  RIF_REG_WT_PRIORITY4_it(data)                                           (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY4_get_cmp(data)                                      ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY4_get_it(data)                                       (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY4_cmp_src(data)                                      ((0x07FF0000&(data))>>16)
#define  RIF_REG_WT_PRIORITY4_it_src(data)                                       (0x000007FF&(data))

#define  RIF_REG_WT_PRIORITY5                                                    0x1800E4C4
#define  RIF_REG_WT_PRIORITY5_reg_addr                                           "0xB800E4C4"
#define  RIF_REG_WT_PRIORITY5_reg                                                0xB800E4C4
#define  RIF_REG_WT_PRIORITY5_inst_addr                                          "0x0021"
#define  RIF_REG_WT_PRIORITY5_inst_adr                                           "0x0031"
#define  RIF_REG_WT_PRIORITY5_inst                                               0x0031
#define  set_RIF_REG_WT_PRIORITY5_reg(data)                                      (*((volatile unsigned int*)RIF_REG_WT_PRIORITY5_reg)=data)
#define  get_RIF_REG_WT_PRIORITY5_reg                                            (*((volatile unsigned int*)RIF_REG_WT_PRIORITY5_reg))
#define  RIF_REG_WT_PRIORITY5_fme_shift                                          (0)
#define  RIF_REG_WT_PRIORITY5_fme_mask                                           (0x000007FF)
#define  RIF_REG_WT_PRIORITY5_fme(data)                                          (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY5_get_fme(data)                                      (0x000007FF&(data))
#define  RIF_REG_WT_PRIORITY5_fme_src(data)                                      (0x000007FF&(data))

#define  RIF_REG_SF_TEST                                                         0x1800E4D0
#define  RIF_REG_SF_TEST_reg_addr                                                "0xB800E4D0"
#define  RIF_REG_SF_TEST_reg                                                     0xB800E4D0
#define  RIF_REG_SF_TEST_inst_addr                                               "0x0022"
#define  RIF_REG_SF_TEST_inst_adr                                                "0x0034"
#define  RIF_REG_SF_TEST_inst                                                    0x0034
#define  set_RIF_REG_SF_TEST_reg(data)                                           (*((volatile unsigned int*)RIF_REG_SF_TEST_reg)=data)
#define  get_RIF_REG_SF_TEST_reg                                                 (*((volatile unsigned int*)RIF_REG_SF_TEST_reg))
#define  RIF_REG_SF_TEST_sb3_sf_rx_err_ro_shift                                  (15)
#define  RIF_REG_SF_TEST_sb3_sf_rx_done_ro_shift                                 (14)
#define  RIF_REG_SF_TEST_sb3_sf_rx_gated_shift                                   (13)
#define  RIF_REG_SF_TEST_sb3_sf_rx_start_shift                                   (12)
#define  RIF_REG_SF_TEST_sb3_sf_rx_mode_shift                                    (11)
#define  RIF_REG_SF_TEST_sb3_sf_tx_work_ro_shift                                 (10)
#define  RIF_REG_SF_TEST_sb3_sf_tx_start_shift                                   (9)
#define  RIF_REG_SF_TEST_sb3_sf_tx_mode_shift                                    (8)
#define  RIF_REG_SF_TEST_dc_sf_rx_err_ro_shift                                   (7)
#define  RIF_REG_SF_TEST_dc_sf_rx_done_ro_shift                                  (6)
#define  RIF_REG_SF_TEST_dc_sf_rx_gated_shift                                    (5)
#define  RIF_REG_SF_TEST_dc_sf_rx_start_shift                                    (4)
#define  RIF_REG_SF_TEST_dc_sf_rx_mode_shift                                     (3)
#define  RIF_REG_SF_TEST_dc_sf_tx_work_ro_shift                                  (2)
#define  RIF_REG_SF_TEST_dc_sf_tx_start_shift                                    (1)
#define  RIF_REG_SF_TEST_dc_sf_tx_mode_shift                                     (0)
#define  RIF_REG_SF_TEST_sb3_sf_rx_err_ro_mask                                   (0x00008000)
#define  RIF_REG_SF_TEST_sb3_sf_rx_done_ro_mask                                  (0x00004000)
#define  RIF_REG_SF_TEST_sb3_sf_rx_gated_mask                                    (0x00002000)
#define  RIF_REG_SF_TEST_sb3_sf_rx_start_mask                                    (0x00001000)
#define  RIF_REG_SF_TEST_sb3_sf_rx_mode_mask                                     (0x00000800)
#define  RIF_REG_SF_TEST_sb3_sf_tx_work_ro_mask                                  (0x00000400)
#define  RIF_REG_SF_TEST_sb3_sf_tx_start_mask                                    (0x00000200)
#define  RIF_REG_SF_TEST_sb3_sf_tx_mode_mask                                     (0x00000100)
#define  RIF_REG_SF_TEST_dc_sf_rx_err_ro_mask                                    (0x00000080)
#define  RIF_REG_SF_TEST_dc_sf_rx_done_ro_mask                                   (0x00000040)
#define  RIF_REG_SF_TEST_dc_sf_rx_gated_mask                                     (0x00000020)
#define  RIF_REG_SF_TEST_dc_sf_rx_start_mask                                     (0x00000010)
#define  RIF_REG_SF_TEST_dc_sf_rx_mode_mask                                      (0x00000008)
#define  RIF_REG_SF_TEST_dc_sf_tx_work_ro_mask                                   (0x00000004)
#define  RIF_REG_SF_TEST_dc_sf_tx_start_mask                                     (0x00000002)
#define  RIF_REG_SF_TEST_dc_sf_tx_mode_mask                                      (0x00000001)
#define  RIF_REG_SF_TEST_sb3_sf_rx_err_ro(data)                                  (0x00008000&((data)<<15))
#define  RIF_REG_SF_TEST_sb3_sf_rx_done_ro(data)                                 (0x00004000&((data)<<14))
#define  RIF_REG_SF_TEST_sb3_sf_rx_gated(data)                                   (0x00002000&((data)<<13))
#define  RIF_REG_SF_TEST_sb3_sf_rx_start(data)                                   (0x00001000&((data)<<12))
#define  RIF_REG_SF_TEST_sb3_sf_rx_mode(data)                                    (0x00000800&((data)<<11))
#define  RIF_REG_SF_TEST_sb3_sf_tx_work_ro(data)                                 (0x00000400&((data)<<10))
#define  RIF_REG_SF_TEST_sb3_sf_tx_start(data)                                   (0x00000200&((data)<<9))
#define  RIF_REG_SF_TEST_sb3_sf_tx_mode(data)                                    (0x00000100&((data)<<8))
#define  RIF_REG_SF_TEST_dc_sf_rx_err_ro(data)                                   (0x00000080&((data)<<7))
#define  RIF_REG_SF_TEST_dc_sf_rx_done_ro(data)                                  (0x00000040&((data)<<6))
#define  RIF_REG_SF_TEST_dc_sf_rx_gated(data)                                    (0x00000020&((data)<<5))
#define  RIF_REG_SF_TEST_dc_sf_rx_start(data)                                    (0x00000010&((data)<<4))
#define  RIF_REG_SF_TEST_dc_sf_rx_mode(data)                                     (0x00000008&((data)<<3))
#define  RIF_REG_SF_TEST_dc_sf_tx_work_ro(data)                                  (0x00000004&((data)<<2))
#define  RIF_REG_SF_TEST_dc_sf_tx_start(data)                                    (0x00000002&((data)<<1))
#define  RIF_REG_SF_TEST_dc_sf_tx_mode(data)                                     (0x00000001&(data))
#define  RIF_REG_SF_TEST_get_sb3_sf_rx_err_ro(data)                              ((0x00008000&(data))>>15)
#define  RIF_REG_SF_TEST_get_sb3_sf_rx_done_ro(data)                             ((0x00004000&(data))>>14)
#define  RIF_REG_SF_TEST_get_sb3_sf_rx_gated(data)                               ((0x00002000&(data))>>13)
#define  RIF_REG_SF_TEST_get_sb3_sf_rx_start(data)                               ((0x00001000&(data))>>12)
#define  RIF_REG_SF_TEST_get_sb3_sf_rx_mode(data)                                ((0x00000800&(data))>>11)
#define  RIF_REG_SF_TEST_get_sb3_sf_tx_work_ro(data)                             ((0x00000400&(data))>>10)
#define  RIF_REG_SF_TEST_get_sb3_sf_tx_start(data)                               ((0x00000200&(data))>>9)
#define  RIF_REG_SF_TEST_get_sb3_sf_tx_mode(data)                                ((0x00000100&(data))>>8)
#define  RIF_REG_SF_TEST_get_dc_sf_rx_err_ro(data)                               ((0x00000080&(data))>>7)
#define  RIF_REG_SF_TEST_get_dc_sf_rx_done_ro(data)                              ((0x00000040&(data))>>6)
#define  RIF_REG_SF_TEST_get_dc_sf_rx_gated(data)                                ((0x00000020&(data))>>5)
#define  RIF_REG_SF_TEST_get_dc_sf_rx_start(data)                                ((0x00000010&(data))>>4)
#define  RIF_REG_SF_TEST_get_dc_sf_rx_mode(data)                                 ((0x00000008&(data))>>3)
#define  RIF_REG_SF_TEST_get_dc_sf_tx_work_ro(data)                              ((0x00000004&(data))>>2)
#define  RIF_REG_SF_TEST_get_dc_sf_tx_start(data)                                ((0x00000002&(data))>>1)
#define  RIF_REG_SF_TEST_get_dc_sf_tx_mode(data)                                 (0x00000001&(data))
#define  RIF_REG_SF_TEST_sb3_sf_rx_err_ro_src(data)                              ((0x00008000&(data))>>15)
#define  RIF_REG_SF_TEST_sb3_sf_rx_done_ro_src(data)                             ((0x00004000&(data))>>14)
#define  RIF_REG_SF_TEST_sb3_sf_rx_gated_src(data)                               ((0x00002000&(data))>>13)
#define  RIF_REG_SF_TEST_sb3_sf_rx_start_src(data)                               ((0x00001000&(data))>>12)
#define  RIF_REG_SF_TEST_sb3_sf_rx_mode_src(data)                                ((0x00000800&(data))>>11)
#define  RIF_REG_SF_TEST_sb3_sf_tx_work_ro_src(data)                             ((0x00000400&(data))>>10)
#define  RIF_REG_SF_TEST_sb3_sf_tx_start_src(data)                               ((0x00000200&(data))>>9)
#define  RIF_REG_SF_TEST_sb3_sf_tx_mode_src(data)                                ((0x00000100&(data))>>8)
#define  RIF_REG_SF_TEST_dc_sf_rx_err_ro_src(data)                               ((0x00000080&(data))>>7)
#define  RIF_REG_SF_TEST_dc_sf_rx_done_ro_src(data)                              ((0x00000040&(data))>>6)
#define  RIF_REG_SF_TEST_dc_sf_rx_gated_src(data)                                ((0x00000020&(data))>>5)
#define  RIF_REG_SF_TEST_dc_sf_rx_start_src(data)                                ((0x00000010&(data))>>4)
#define  RIF_REG_SF_TEST_dc_sf_rx_mode_src(data)                                 ((0x00000008&(data))>>3)
#define  RIF_REG_SF_TEST_dc_sf_tx_work_ro_src(data)                              ((0x00000004&(data))>>2)
#define  RIF_REG_SF_TEST_dc_sf_tx_start_src(data)                                ((0x00000002&(data))>>1)
#define  RIF_REG_SF_TEST_dc_sf_tx_mode_src(data)                                 (0x00000001&(data))

#define  RIF_REG_CLKGATED                                                        0x1800E4D8
#define  RIF_REG_CLKGATED_reg_addr                                               "0xB800E4D8"
#define  RIF_REG_CLKGATED_reg                                                    0xB800E4D8
#define  RIF_REG_CLKGATED_inst_addr                                              "0x0023"
#define  RIF_REG_CLKGATED_inst_adr                                               "0x0036"
#define  RIF_REG_CLKGATED_inst                                                   0x0036
#define  set_RIF_REG_CLKGATED_reg(data)                                          (*((volatile unsigned int*)RIF_REG_CLKGATED_reg)=data)
#define  get_RIF_REG_CLKGATED_reg                                                (*((volatile unsigned int*)RIF_REG_CLKGATED_reg))
#define  RIF_REG_CLKGATED_cache_gated_en_shift                                   (25)
#define  RIF_REG_CLKGATED_rl_gated_en_shift                                      (24)
#define  RIF_REG_CLKGATED_mvd_gated_en_shift                                     (23)
#define  RIF_REG_CLKGATED_ndbp2_gated_en_shift                                   (22)
#define  RIF_REG_CLKGATED_ndb_gated_en_shift                                     (21)
#define  RIF_REG_CLKGATED_brg_gated_en_shift                                     (20)
#define  RIF_REG_CLKGATED_cm_gated_en_shift                                      (19)
#define  RIF_REG_CLKGATED_arb_gated_en_shift                                     (18)
#define  RIF_REG_CLKGATED_bsfifop2_gated_en_shift                                (17)
#define  RIF_REG_CLKGATED_bsfifo_gated_en_shift                                  (16)
#define  RIF_REG_CLKGATED_img_gated_en_shift                                     (15)
#define  RIF_REG_CLKGATED_deblk_gated_en_shift                                   (14)
#define  RIF_REG_CLKGATED_gc_gated_en_shift                                      (13)
#define  RIF_REG_CLKGATED_pred_gated_en_shift                                    (12)
#define  RIF_REG_CLKGATED_emd_gated_en_shift                                     (11)
#define  RIF_REG_CLKGATED_imedma_gated_en_shift                                  (10)
#define  RIF_REG_CLKGATED_ime_gated_en_shift                                     (9)
#define  RIF_REG_CLKGATED_vm2_gated_en_shift                                     (8)
#define  RIF_REG_CLKGATED_vm1_gated_en_shift                                     (7)
#define  RIF_REG_CLKGATED_it_gated_en_shift                                      (6)
#define  RIF_REG_CLKGATED_cabac_gated_en_shift                                   (5)
#define  RIF_REG_CLKGATED_vp8p2_gated_en_shift                                   (4)
#define  RIF_REG_CLKGATED_cabacp2_gated_en_shift                                 (3)
#define  RIF_REG_CLKGATED_vld_gated_en_shift                                     (2)
#define  RIF_REG_CLKGATED_vlc_gated_en_shift                                     (1)
#define  RIF_REG_CLKGATED_acdc_gated_en_shift                                    (0)
#define  RIF_REG_CLKGATED_cache_gated_en_mask                                    (0x02000000)
#define  RIF_REG_CLKGATED_rl_gated_en_mask                                       (0x01000000)
#define  RIF_REG_CLKGATED_mvd_gated_en_mask                                      (0x00800000)
#define  RIF_REG_CLKGATED_ndbp2_gated_en_mask                                    (0x00400000)
#define  RIF_REG_CLKGATED_ndb_gated_en_mask                                      (0x00200000)
#define  RIF_REG_CLKGATED_brg_gated_en_mask                                      (0x00100000)
#define  RIF_REG_CLKGATED_cm_gated_en_mask                                       (0x00080000)
#define  RIF_REG_CLKGATED_arb_gated_en_mask                                      (0x00040000)
#define  RIF_REG_CLKGATED_bsfifop2_gated_en_mask                                 (0x00020000)
#define  RIF_REG_CLKGATED_bsfifo_gated_en_mask                                   (0x00010000)
#define  RIF_REG_CLKGATED_img_gated_en_mask                                      (0x00008000)
#define  RIF_REG_CLKGATED_deblk_gated_en_mask                                    (0x00004000)
#define  RIF_REG_CLKGATED_gc_gated_en_mask                                       (0x00002000)
#define  RIF_REG_CLKGATED_pred_gated_en_mask                                     (0x00001000)
#define  RIF_REG_CLKGATED_emd_gated_en_mask                                      (0x00000800)
#define  RIF_REG_CLKGATED_imedma_gated_en_mask                                   (0x00000400)
#define  RIF_REG_CLKGATED_ime_gated_en_mask                                      (0x00000200)
#define  RIF_REG_CLKGATED_vm2_gated_en_mask                                      (0x00000100)
#define  RIF_REG_CLKGATED_vm1_gated_en_mask                                      (0x00000080)
#define  RIF_REG_CLKGATED_it_gated_en_mask                                       (0x00000040)
#define  RIF_REG_CLKGATED_cabac_gated_en_mask                                    (0x00000020)
#define  RIF_REG_CLKGATED_vp8p2_gated_en_mask                                    (0x00000010)
#define  RIF_REG_CLKGATED_cabacp2_gated_en_mask                                  (0x00000008)
#define  RIF_REG_CLKGATED_vld_gated_en_mask                                      (0x00000004)
#define  RIF_REG_CLKGATED_vlc_gated_en_mask                                      (0x00000002)
#define  RIF_REG_CLKGATED_acdc_gated_en_mask                                     (0x00000001)
#define  RIF_REG_CLKGATED_cache_gated_en(data)                                   (0x02000000&((data)<<25))
#define  RIF_REG_CLKGATED_rl_gated_en(data)                                      (0x01000000&((data)<<24))
#define  RIF_REG_CLKGATED_mvd_gated_en(data)                                     (0x00800000&((data)<<23))
#define  RIF_REG_CLKGATED_ndbp2_gated_en(data)                                   (0x00400000&((data)<<22))
#define  RIF_REG_CLKGATED_ndb_gated_en(data)                                     (0x00200000&((data)<<21))
#define  RIF_REG_CLKGATED_brg_gated_en(data)                                     (0x00100000&((data)<<20))
#define  RIF_REG_CLKGATED_cm_gated_en(data)                                      (0x00080000&((data)<<19))
#define  RIF_REG_CLKGATED_arb_gated_en(data)                                     (0x00040000&((data)<<18))
#define  RIF_REG_CLKGATED_bsfifop2_gated_en(data)                                (0x00020000&((data)<<17))
#define  RIF_REG_CLKGATED_bsfifo_gated_en(data)                                  (0x00010000&((data)<<16))
#define  RIF_REG_CLKGATED_img_gated_en(data)                                     (0x00008000&((data)<<15))
#define  RIF_REG_CLKGATED_deblk_gated_en(data)                                   (0x00004000&((data)<<14))
#define  RIF_REG_CLKGATED_gc_gated_en(data)                                      (0x00002000&((data)<<13))
#define  RIF_REG_CLKGATED_pred_gated_en(data)                                    (0x00001000&((data)<<12))
#define  RIF_REG_CLKGATED_emd_gated_en(data)                                     (0x00000800&((data)<<11))
#define  RIF_REG_CLKGATED_imedma_gated_en(data)                                  (0x00000400&((data)<<10))
#define  RIF_REG_CLKGATED_ime_gated_en(data)                                     (0x00000200&((data)<<9))
#define  RIF_REG_CLKGATED_vm2_gated_en(data)                                     (0x00000100&((data)<<8))
#define  RIF_REG_CLKGATED_vm1_gated_en(data)                                     (0x00000080&((data)<<7))
#define  RIF_REG_CLKGATED_it_gated_en(data)                                      (0x00000040&((data)<<6))
#define  RIF_REG_CLKGATED_cabac_gated_en(data)                                   (0x00000020&((data)<<5))
#define  RIF_REG_CLKGATED_vp8p2_gated_en(data)                                   (0x00000010&((data)<<4))
#define  RIF_REG_CLKGATED_cabacp2_gated_en(data)                                 (0x00000008&((data)<<3))
#define  RIF_REG_CLKGATED_vld_gated_en(data)                                     (0x00000004&((data)<<2))
#define  RIF_REG_CLKGATED_vlc_gated_en(data)                                     (0x00000002&((data)<<1))
#define  RIF_REG_CLKGATED_acdc_gated_en(data)                                    (0x00000001&(data))
#define  RIF_REG_CLKGATED_get_cache_gated_en(data)                               ((0x02000000&(data))>>25)
#define  RIF_REG_CLKGATED_get_rl_gated_en(data)                                  ((0x01000000&(data))>>24)
#define  RIF_REG_CLKGATED_get_mvd_gated_en(data)                                 ((0x00800000&(data))>>23)
#define  RIF_REG_CLKGATED_get_ndbp2_gated_en(data)                               ((0x00400000&(data))>>22)
#define  RIF_REG_CLKGATED_get_ndb_gated_en(data)                                 ((0x00200000&(data))>>21)
#define  RIF_REG_CLKGATED_get_brg_gated_en(data)                                 ((0x00100000&(data))>>20)
#define  RIF_REG_CLKGATED_get_cm_gated_en(data)                                  ((0x00080000&(data))>>19)
#define  RIF_REG_CLKGATED_get_arb_gated_en(data)                                 ((0x00040000&(data))>>18)
#define  RIF_REG_CLKGATED_get_bsfifop2_gated_en(data)                            ((0x00020000&(data))>>17)
#define  RIF_REG_CLKGATED_get_bsfifo_gated_en(data)                              ((0x00010000&(data))>>16)
#define  RIF_REG_CLKGATED_get_img_gated_en(data)                                 ((0x00008000&(data))>>15)
#define  RIF_REG_CLKGATED_get_deblk_gated_en(data)                               ((0x00004000&(data))>>14)
#define  RIF_REG_CLKGATED_get_gc_gated_en(data)                                  ((0x00002000&(data))>>13)
#define  RIF_REG_CLKGATED_get_pred_gated_en(data)                                ((0x00001000&(data))>>12)
#define  RIF_REG_CLKGATED_get_emd_gated_en(data)                                 ((0x00000800&(data))>>11)
#define  RIF_REG_CLKGATED_get_imedma_gated_en(data)                              ((0x00000400&(data))>>10)
#define  RIF_REG_CLKGATED_get_ime_gated_en(data)                                 ((0x00000200&(data))>>9)
#define  RIF_REG_CLKGATED_get_vm2_gated_en(data)                                 ((0x00000100&(data))>>8)
#define  RIF_REG_CLKGATED_get_vm1_gated_en(data)                                 ((0x00000080&(data))>>7)
#define  RIF_REG_CLKGATED_get_it_gated_en(data)                                  ((0x00000040&(data))>>6)
#define  RIF_REG_CLKGATED_get_cabac_gated_en(data)                               ((0x00000020&(data))>>5)
#define  RIF_REG_CLKGATED_get_vp8p2_gated_en(data)                               ((0x00000010&(data))>>4)
#define  RIF_REG_CLKGATED_get_cabacp2_gated_en(data)                             ((0x00000008&(data))>>3)
#define  RIF_REG_CLKGATED_get_vld_gated_en(data)                                 ((0x00000004&(data))>>2)
#define  RIF_REG_CLKGATED_get_vlc_gated_en(data)                                 ((0x00000002&(data))>>1)
#define  RIF_REG_CLKGATED_get_acdc_gated_en(data)                                (0x00000001&(data))
#define  RIF_REG_CLKGATED_cache_gated_en_src(data)                               ((0x02000000&(data))>>25)
#define  RIF_REG_CLKGATED_rl_gated_en_src(data)                                  ((0x01000000&(data))>>24)
#define  RIF_REG_CLKGATED_mvd_gated_en_src(data)                                 ((0x00800000&(data))>>23)
#define  RIF_REG_CLKGATED_ndbp2_gated_en_src(data)                               ((0x00400000&(data))>>22)
#define  RIF_REG_CLKGATED_ndb_gated_en_src(data)                                 ((0x00200000&(data))>>21)
#define  RIF_REG_CLKGATED_brg_gated_en_src(data)                                 ((0x00100000&(data))>>20)
#define  RIF_REG_CLKGATED_cm_gated_en_src(data)                                  ((0x00080000&(data))>>19)
#define  RIF_REG_CLKGATED_arb_gated_en_src(data)                                 ((0x00040000&(data))>>18)
#define  RIF_REG_CLKGATED_bsfifop2_gated_en_src(data)                            ((0x00020000&(data))>>17)
#define  RIF_REG_CLKGATED_bsfifo_gated_en_src(data)                              ((0x00010000&(data))>>16)
#define  RIF_REG_CLKGATED_img_gated_en_src(data)                                 ((0x00008000&(data))>>15)
#define  RIF_REG_CLKGATED_deblk_gated_en_src(data)                               ((0x00004000&(data))>>14)
#define  RIF_REG_CLKGATED_gc_gated_en_src(data)                                  ((0x00002000&(data))>>13)
#define  RIF_REG_CLKGATED_pred_gated_en_src(data)                                ((0x00001000&(data))>>12)
#define  RIF_REG_CLKGATED_emd_gated_en_src(data)                                 ((0x00000800&(data))>>11)
#define  RIF_REG_CLKGATED_imedma_gated_en_src(data)                              ((0x00000400&(data))>>10)
#define  RIF_REG_CLKGATED_ime_gated_en_src(data)                                 ((0x00000200&(data))>>9)
#define  RIF_REG_CLKGATED_vm2_gated_en_src(data)                                 ((0x00000100&(data))>>8)
#define  RIF_REG_CLKGATED_vm1_gated_en_src(data)                                 ((0x00000080&(data))>>7)
#define  RIF_REG_CLKGATED_it_gated_en_src(data)                                  ((0x00000040&(data))>>6)
#define  RIF_REG_CLKGATED_cabac_gated_en_src(data)                               ((0x00000020&(data))>>5)
#define  RIF_REG_CLKGATED_vp8p2_gated_en_src(data)                               ((0x00000010&(data))>>4)
#define  RIF_REG_CLKGATED_cabacp2_gated_en_src(data)                             ((0x00000008&(data))>>3)
#define  RIF_REG_CLKGATED_vld_gated_en_src(data)                                 ((0x00000004&(data))>>2)
#define  RIF_REG_CLKGATED_vlc_gated_en_src(data)                                 ((0x00000002&(data))>>1)
#define  RIF_REG_CLKGATED_acdc_gated_en_src(data)                                (0x00000001&(data))

#define  RIF_REG_DBG_CTRL17                                                      0x1800E4DC
#define  RIF_REG_DBG_CTRL17_reg_addr                                             "0xB800E4DC"
#define  RIF_REG_DBG_CTRL17_reg                                                  0xB800E4DC
#define  RIF_REG_DBG_CTRL17_inst_addr                                            "0x0024"
#define  RIF_REG_DBG_CTRL17_inst_adr                                             "0x0037"
#define  RIF_REG_DBG_CTRL17_inst                                                 0x0037
#define  set_RIF_REG_DBG_CTRL17_reg(data)                                        (*((volatile unsigned int*)RIF_REG_DBG_CTRL17_reg)=data)
#define  get_RIF_REG_DBG_CTRL17_reg                                              (*((volatile unsigned int*)RIF_REG_DBG_CTRL17_reg))
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel1_shift                                   (24)
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel0_shift                                   (20)
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel1_shift                                   (16)
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel0_shift                                   (12)
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel1_shift                                   (6)
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel0_shift                                   (0)
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel1_mask                                    (0x0F000000)
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel0_mask                                    (0x00F00000)
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel1_mask                                    (0x000F0000)
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel0_mask                                    (0x0000F000)
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel1_mask                                    (0x00000FC0)
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel0_mask                                    (0x0000003F)
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel1(data)                                   (0x0F000000&((data)<<24))
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel0(data)                                   (0x00F00000&((data)<<20))
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel1(data)                                   (0x000F0000&((data)<<16))
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel0(data)                                   (0x0000F000&((data)<<12))
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel1(data)                                   (0x00000FC0&((data)<<6))
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel0(data)                                   (0x0000003F&(data))
#define  RIF_REG_DBG_CTRL17_get_seg_dbg_sel1(data)                               ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL17_get_seg_dbg_sel0(data)                               ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL17_get_sao_dbg_sel1(data)                               ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL17_get_sao_dbg_sel0(data)                               ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL17_get_ime_dbg_sel1(data)                               ((0x00000FC0&(data))>>6)
#define  RIF_REG_DBG_CTRL17_get_ime_dbg_sel0(data)                               (0x0000003F&(data))
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel1_src(data)                               ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL17_seg_dbg_sel0_src(data)                               ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel1_src(data)                               ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL17_sao_dbg_sel0_src(data)                               ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel1_src(data)                               ((0x00000FC0&(data))>>6)
#define  RIF_REG_DBG_CTRL17_ime_dbg_sel0_src(data)                               (0x0000003F&(data))

#define  RIF_REG_DBG_OUT                                                         0x1800E4E0
#define  RIF_REG_DBG_OUT_reg_addr                                                "0xB800E4E0"
#define  RIF_REG_DBG_OUT_reg                                                     0xB800E4E0
#define  RIF_REG_DBG_OUT_inst_addr                                               "0x0025"
#define  RIF_REG_DBG_OUT_inst_adr                                                "0x0038"
#define  RIF_REG_DBG_OUT_inst                                                    0x0038
#define  set_RIF_REG_DBG_OUT_reg(data)                                           (*((volatile unsigned int*)RIF_REG_DBG_OUT_reg)=data)
#define  get_RIF_REG_DBG_OUT_reg                                                 (*((volatile unsigned int*)RIF_REG_DBG_OUT_reg))
#define  RIF_REG_DBG_OUT_ve_dbg_out1_shift                                       (16)
#define  RIF_REG_DBG_OUT_ve_dbg_out0_shift                                       (0)
#define  RIF_REG_DBG_OUT_ve_dbg_out1_mask                                        (0xFFFF0000)
#define  RIF_REG_DBG_OUT_ve_dbg_out0_mask                                        (0x0000FFFF)
#define  RIF_REG_DBG_OUT_ve_dbg_out1(data)                                       (0xFFFF0000&((data)<<16))
#define  RIF_REG_DBG_OUT_ve_dbg_out0(data)                                       (0x0000FFFF&(data))
#define  RIF_REG_DBG_OUT_get_ve_dbg_out1(data)                                   ((0xFFFF0000&(data))>>16)
#define  RIF_REG_DBG_OUT_get_ve_dbg_out0(data)                                   (0x0000FFFF&(data))
#define  RIF_REG_DBG_OUT_ve_dbg_out1_src(data)                                   ((0xFFFF0000&(data))>>16)
#define  RIF_REG_DBG_OUT_ve_dbg_out0_src(data)                                   (0x0000FFFF&(data))

#define  RIF_REG_DBG_CTRL1                                                       0x1800E4E4
#define  RIF_REG_DBG_CTRL1_reg_addr                                              "0xB800E4E4"
#define  RIF_REG_DBG_CTRL1_reg                                                   0xB800E4E4
#define  RIF_REG_DBG_CTRL1_inst_addr                                             "0x0026"
#define  RIF_REG_DBG_CTRL1_inst_adr                                              "0x0039"
#define  RIF_REG_DBG_CTRL1_inst                                                  0x0039
#define  set_RIF_REG_DBG_CTRL1_reg(data)                                         (*((volatile unsigned int*)RIF_REG_DBG_CTRL1_reg)=data)
#define  get_RIF_REG_DBG_CTRL1_reg                                               (*((volatile unsigned int*)RIF_REG_DBG_CTRL1_reg))
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel1_shift                                  (28)
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel0_shift                                  (24)
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel1_shift                                     (20)
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel0_shift                                     (16)
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel1_shift                                    (12)
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel0_shift                                    (8)
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel1_shift                                   (4)
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel0_shift                                   (0)
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel1_mask                                   (0xF0000000)
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel0_mask                                   (0x0F000000)
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel1_mask                                      (0x00F00000)
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel0_mask                                      (0x000F0000)
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel1_mask                                     (0x0000F000)
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel0_mask                                     (0x00000F00)
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel1_mask                                    (0x000000F0)
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel0_mask                                    (0x0000000F)
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel1(data)                                  (0xF0000000&((data)<<28))
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel0(data)                                  (0x0F000000&((data)<<24))
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel1(data)                                     (0x00F00000&((data)<<20))
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel0(data)                                     (0x000F0000&((data)<<16))
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel1(data)                                    (0x0000F000&((data)<<12))
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel0(data)                                    (0x00000F00&((data)<<8))
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel1(data)                                   (0x000000F0&((data)<<4))
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel0(data)                                   (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL1_get_cache_dbg_sel1(data)                              ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL1_get_cache_dbg_sel0(data)                              ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL1_get_bs_dbg_sel1(data)                                 ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL1_get_bs_dbg_sel0(data)                                 ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL1_get_brg_dbg_sel1(data)                                ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL1_get_brg_dbg_sel0(data)                                ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL1_get_acdc_dbg_sel1(data)                               ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL1_get_acdc_dbg_sel0(data)                               (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel1_src(data)                              ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL1_cache_dbg_sel0_src(data)                              ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel1_src(data)                                 ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL1_bs_dbg_sel0_src(data)                                 ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel1_src(data)                                ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL1_brg_dbg_sel0_src(data)                                ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel1_src(data)                               ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL1_acdc_dbg_sel0_src(data)                               (0x0000000F&(data))

#define  RIF_REG_DBG_CTRL2                                                       0x1800E4E8
#define  RIF_REG_DBG_CTRL2_reg_addr                                              "0xB800E4E8"
#define  RIF_REG_DBG_CTRL2_reg                                                   0xB800E4E8
#define  RIF_REG_DBG_CTRL2_inst_addr                                             "0x0027"
#define  RIF_REG_DBG_CTRL2_inst_adr                                              "0x003A"
#define  RIF_REG_DBG_CTRL2_inst                                                  0x003A
#define  set_RIF_REG_DBG_CTRL2_reg(data)                                         (*((volatile unsigned int*)RIF_REG_DBG_CTRL2_reg)=data)
#define  get_RIF_REG_DBG_CTRL2_reg                                               (*((volatile unsigned int*)RIF_REG_DBG_CTRL2_reg))
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel3_shift                                     (26)
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel2_shift                                     (24)
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel1_shift                                     (20)
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel0_shift                                     (16)
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel1_shift                                (12)
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel0_shift                                (8)
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel1_shift                                (4)
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel0_shift                                (0)
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel3_mask                                      (0x0C000000)
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel2_mask                                      (0x03000000)
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel1_mask                                      (0x00F00000)
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel0_mask                                      (0x000F0000)
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel1_mask                                 (0x0000F000)
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel0_mask                                 (0x00000F00)
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel1_mask                                 (0x000000F0)
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel0_mask                                 (0x0000000F)
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel3(data)                                     (0x0C000000&((data)<<26))
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel2(data)                                     (0x03000000&((data)<<24))
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel1(data)                                     (0x00F00000&((data)<<20))
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel0(data)                                     (0x000F0000&((data)<<16))
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel1(data)                                (0x0000F000&((data)<<12))
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel0(data)                                (0x00000F00&((data)<<8))
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel1(data)                                (0x000000F0&((data)<<4))
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel0(data)                                (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL2_get_bs_dbg_sel3(data)                                 ((0x0C000000&(data))>>26)
#define  RIF_REG_DBG_CTRL2_get_bs_dbg_sel2(data)                                 ((0x03000000&(data))>>24)
#define  RIF_REG_DBG_CTRL2_get_cm_dbg_sel1(data)                                 ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL2_get_cm_dbg_sel0(data)                                 ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL2_get_cabacp3_dbg_sel1(data)                            ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL2_get_cabacp3_dbg_sel0(data)                            ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL2_get_cabacp2_dbg_sel1(data)                            ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL2_get_cabacp2_dbg_sel0(data)                            (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel3_src(data)                                 ((0x0C000000&(data))>>26)
#define  RIF_REG_DBG_CTRL2_bs_dbg_sel2_src(data)                                 ((0x03000000&(data))>>24)
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel1_src(data)                                 ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL2_cm_dbg_sel0_src(data)                                 ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel1_src(data)                            ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL2_cabacp3_dbg_sel0_src(data)                            ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel1_src(data)                            ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL2_cabacp2_dbg_sel0_src(data)                            (0x0000000F&(data))

#define  RIF_REG_DBG_CTRL3                                                       0x1800E4EC
#define  RIF_REG_DBG_CTRL3_reg_addr                                              "0xB800E4EC"
#define  RIF_REG_DBG_CTRL3_reg                                                   0xB800E4EC
#define  RIF_REG_DBG_CTRL3_inst_addr                                             "0x0028"
#define  RIF_REG_DBG_CTRL3_inst_adr                                              "0x003B"
#define  RIF_REG_DBG_CTRL3_inst                                                  0x003B
#define  set_RIF_REG_DBG_CTRL3_reg(data)                                         (*((volatile unsigned int*)RIF_REG_DBG_CTRL3_reg)=data)
#define  get_RIF_REG_DBG_CTRL3_reg                                               (*((volatile unsigned int*)RIF_REG_DBG_CTRL3_reg))
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel1_shift                                    (28)
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel0_shift                                    (24)
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel1_shift                                    (20)
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel0_shift                                    (16)
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel1_shift                                  (12)
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel0_shift                                  (8)
#define  RIF_REG_DBG_CTRL3_img_dbg_sel1_shift                                    (4)
#define  RIF_REG_DBG_CTRL3_img_dbg_sel0_shift                                    (0)
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel1_mask                                     (0xF0000000)
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel0_mask                                     (0x0F000000)
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel1_mask                                     (0x00F00000)
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel0_mask                                     (0x000F0000)
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel1_mask                                   (0x0000F000)
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel0_mask                                   (0x00000F00)
#define  RIF_REG_DBG_CTRL3_img_dbg_sel1_mask                                     (0x000000F0)
#define  RIF_REG_DBG_CTRL3_img_dbg_sel0_mask                                     (0x0000000F)
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel1(data)                                    (0xF0000000&((data)<<28))
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel0(data)                                    (0x0F000000&((data)<<24))
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel1(data)                                    (0x00F00000&((data)<<20))
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel0(data)                                    (0x000F0000&((data)<<16))
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel1(data)                                  (0x0000F000&((data)<<12))
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel0(data)                                  (0x00000F00&((data)<<8))
#define  RIF_REG_DBG_CTRL3_img_dbg_sel1(data)                                    (0x000000F0&((data)<<4))
#define  RIF_REG_DBG_CTRL3_img_dbg_sel0(data)                                    (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL3_get_ndb_dbg_sel1(data)                                ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL3_get_ndb_dbg_sel0(data)                                ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL3_get_rif_dbg_sel1(data)                                ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL3_get_rif_dbg_sel0(data)                                ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL3_get_itblk_dbg_sel1(data)                              ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL3_get_itblk_dbg_sel0(data)                              ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL3_get_img_dbg_sel1(data)                                ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL3_get_img_dbg_sel0(data)                                (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel1_src(data)                                ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL3_ndb_dbg_sel0_src(data)                                ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel1_src(data)                                ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL3_rif_dbg_sel0_src(data)                                ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel1_src(data)                              ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL3_itblk_dbg_sel0_src(data)                              ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL3_img_dbg_sel1_src(data)                                ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL3_img_dbg_sel0_src(data)                                (0x0000000F&(data))

#define  RIF_REG_DBG_CTRL4                                                       0x1800E4F0
#define  RIF_REG_DBG_CTRL4_reg_addr                                              "0xB800E4F0"
#define  RIF_REG_DBG_CTRL4_reg                                                   0xB800E4F0
#define  RIF_REG_DBG_CTRL4_inst_addr                                             "0x0029"
#define  RIF_REG_DBG_CTRL4_inst_adr                                              "0x003C"
#define  RIF_REG_DBG_CTRL4_inst                                                  0x003C
#define  set_RIF_REG_DBG_CTRL4_reg(data)                                         (*((volatile unsigned int*)RIF_REG_DBG_CTRL4_reg)=data)
#define  get_RIF_REG_DBG_CTRL4_reg                                               (*((volatile unsigned int*)RIF_REG_DBG_CTRL4_reg))
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel1_shift                                     (28)
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel0_shift                                     (24)
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel1_shift                                    (20)
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel0_shift                                    (16)
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel1_shift                                    (12)
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel0_shift                                    (8)
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel1_shift                                    (4)
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel0_shift                                    (0)
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel1_mask                                      (0xF0000000)
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel0_mask                                      (0x0F000000)
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel1_mask                                     (0x00F00000)
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel0_mask                                     (0x000F0000)
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel1_mask                                     (0x0000F000)
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel0_mask                                     (0x00000F00)
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel1_mask                                     (0x000000F0)
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel0_mask                                     (0x0000000F)
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel1(data)                                     (0xF0000000&((data)<<28))
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel0(data)                                     (0x0F000000&((data)<<24))
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel1(data)                                    (0x00F00000&((data)<<20))
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel0(data)                                    (0x000F0000&((data)<<16))
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel1(data)                                    (0x0000F000&((data)<<12))
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel0(data)                                    (0x00000F00&((data)<<8))
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel1(data)                                    (0x000000F0&((data)<<4))
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel0(data)                                    (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL4_get_rl_dbg_sel1(data)                                 ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL4_get_rl_dbg_sel0(data)                                 ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL4_get_vld_dbg_sel1(data)                                ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL4_get_vld_dbg_sel0(data)                                ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL4_get_arb_dbg_sel1(data)                                ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL4_get_arb_dbg_sel0(data)                                ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL4_get_vm1_dbg_sel1(data)                                ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL4_get_vm1_dbg_sel0(data)                                (0x0000000F&(data))
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel1_src(data)                                 ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL4_rl_dbg_sel0_src(data)                                 ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel1_src(data)                                ((0x00F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL4_vld_dbg_sel0_src(data)                                ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel1_src(data)                                ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL4_arb_dbg_sel0_src(data)                                ((0x00000F00&(data))>>8)
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel1_src(data)                                ((0x000000F0&(data))>>4)
#define  RIF_REG_DBG_CTRL4_vm1_dbg_sel0_src(data)                                (0x0000000F&(data))

#define  RIF_REG_DBG_CTRL5                                                       0x1800E4F4
#define  RIF_REG_DBG_CTRL5_reg_addr                                              "0xB800E4F4"
#define  RIF_REG_DBG_CTRL5_reg                                                   0xB800E4F4
#define  RIF_REG_DBG_CTRL5_inst_addr                                             "0x002A"
#define  RIF_REG_DBG_CTRL5_inst_adr                                              "0x003D"
#define  RIF_REG_DBG_CTRL5_inst                                                  0x003D
#define  set_RIF_REG_DBG_CTRL5_reg(data)                                         (*((volatile unsigned int*)RIF_REG_DBG_CTRL5_reg)=data)
#define  get_RIF_REG_DBG_CTRL5_reg                                               (*((volatile unsigned int*)RIF_REG_DBG_CTRL5_reg))
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel1_shift                                  (26)
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel0_shift                                  (20)
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel1_shift                                    (16)
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel0_shift                                    (12)
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel1_shift                                    (6)
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel0_shift                                    (0)
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel1_mask                                   (0xFC000000)
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel0_mask                                   (0x03F00000)
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel1_mask                                     (0x000F0000)
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel0_mask                                     (0x0000F000)
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel1_mask                                     (0x00000FC0)
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel0_mask                                     (0x0000003F)
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel1(data)                                  (0xFC000000&((data)<<26))
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel0(data)                                  (0x03F00000&((data)<<20))
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel1(data)                                    (0x000F0000&((data)<<16))
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel0(data)                                    (0x0000F000&((data)<<12))
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel1(data)                                    (0x00000FC0&((data)<<6))
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel0(data)                                    (0x0000003F&(data))
#define  RIF_REG_DBG_CTRL5_get_deblk_dbg_sel1(data)                              ((0xFC000000&(data))>>26)
#define  RIF_REG_DBG_CTRL5_get_deblk_dbg_sel0(data)                              ((0x03F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL5_get_mvd_dbg_sel1(data)                                ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL5_get_mvd_dbg_sel0(data)                                ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL5_get_prd_dbg_sel1(data)                                ((0x00000FC0&(data))>>6)
#define  RIF_REG_DBG_CTRL5_get_prd_dbg_sel0(data)                                (0x0000003F&(data))
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel1_src(data)                              ((0xFC000000&(data))>>26)
#define  RIF_REG_DBG_CTRL5_deblk_dbg_sel0_src(data)                              ((0x03F00000&(data))>>20)
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel1_src(data)                                ((0x000F0000&(data))>>16)
#define  RIF_REG_DBG_CTRL5_mvd_dbg_sel0_src(data)                                ((0x0000F000&(data))>>12)
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel1_src(data)                                ((0x00000FC0&(data))>>6)
#define  RIF_REG_DBG_CTRL5_prd_dbg_sel0_src(data)                                (0x0000003F&(data))

#define  RIF_REG_FPGA_DBG1                                                       0x1800E4F8
#define  RIF_REG_FPGA_DBG1_reg_addr                                              "0xB800E4F8"
#define  RIF_REG_FPGA_DBG1_reg                                                   0xB800E4F8
#define  RIF_REG_FPGA_DBG1_inst_addr                                             "0x002B"
#define  RIF_REG_FPGA_DBG1_inst_adr                                              "0x003E"
#define  RIF_REG_FPGA_DBG1_inst                                                  0x003E
#define  set_RIF_REG_FPGA_DBG1_reg(data)                                         (*((volatile unsigned int*)RIF_REG_FPGA_DBG1_reg)=data)
#define  get_RIF_REG_FPGA_DBG1_reg                                               (*((volatile unsigned int*)RIF_REG_FPGA_DBG1_reg))
#define  RIF_REG_FPGA_DBG1_dcmprs_busy_shift                                     (28)
#define  RIF_REG_FPGA_DBG1_cmprs_busy_shift                                      (27)
#define  RIF_REG_FPGA_DBG1_seg_busy_shift                                        (26)
#define  RIF_REG_FPGA_DBG1_sao_busy_shift                                        (25)
#define  RIF_REG_FPGA_DBG1_vm2_busy_shift                                        (24)
#define  RIF_REG_FPGA_DBG1_vp8p2_busy_shift                                      (23)
#define  RIF_REG_FPGA_DBG1_ndbp2_busy_shift                                      (22)
#define  RIF_REG_FPGA_DBG1_ipmd_busy_shift                                       (21)
#define  RIF_REG_FPGA_DBG1_fme_busy_shift                                        (20)
#define  RIF_REG_FPGA_DBG1_vlc_busy_shift                                        (19)
#define  RIF_REG_FPGA_DBG1_gcoeff_busy_shift                                     (18)
#define  RIF_REG_FPGA_DBG1_emd_busy_shift                                        (17)
#define  RIF_REG_FPGA_DBG1_imedma_busy_shift                                     (16)
#define  RIF_REG_FPGA_DBG1_ime_busy_shift                                        (15)
#define  RIF_REG_FPGA_DBG1_cache_busy_shift                                      (14)
#define  RIF_REG_FPGA_DBG1_brg_busy_shift                                        (13)
#define  RIF_REG_FPGA_DBG1_ndb_busy_shift                                        (12)
#define  RIF_REG_FPGA_DBG1_bsfifo_busy_shift                                     (11)
#define  RIF_REG_FPGA_DBG1_img_busy_shift                                        (10)
#define  RIF_REG_FPGA_DBG1_vm1_busy_shift                                        (9)
#define  RIF_REG_FPGA_DBG1_deblk_busy_shift                                      (8)
#define  RIF_REG_FPGA_DBG1_rl_busy_shift                                         (7)
#define  RIF_REG_FPGA_DBG1_pred_busy_shift                                       (6)
#define  RIF_REG_FPGA_DBG1_mvd_busy_shift                                        (5)
#define  RIF_REG_FPGA_DBG1_itblk_busy_shift                                      (4)
#define  RIF_REG_FPGA_DBG1_acdc_busy_shift                                       (3)
#define  RIF_REG_FPGA_DBG1_cabacp2_busy_shift                                    (2)
#define  RIF_REG_FPGA_DBG1_vld_busy_shift                                        (1)
#define  RIF_REG_FPGA_DBG1_rifvld_busy_shift                                     (0)
#define  RIF_REG_FPGA_DBG1_dcmprs_busy_mask                                      (0x10000000)
#define  RIF_REG_FPGA_DBG1_cmprs_busy_mask                                       (0x08000000)
#define  RIF_REG_FPGA_DBG1_seg_busy_mask                                         (0x04000000)
#define  RIF_REG_FPGA_DBG1_sao_busy_mask                                         (0x02000000)
#define  RIF_REG_FPGA_DBG1_vm2_busy_mask                                         (0x01000000)
#define  RIF_REG_FPGA_DBG1_vp8p2_busy_mask                                       (0x00800000)
#define  RIF_REG_FPGA_DBG1_ndbp2_busy_mask                                       (0x00400000)
#define  RIF_REG_FPGA_DBG1_ipmd_busy_mask                                        (0x00200000)
#define  RIF_REG_FPGA_DBG1_fme_busy_mask                                         (0x00100000)
#define  RIF_REG_FPGA_DBG1_vlc_busy_mask                                         (0x00080000)
#define  RIF_REG_FPGA_DBG1_gcoeff_busy_mask                                      (0x00040000)
#define  RIF_REG_FPGA_DBG1_emd_busy_mask                                         (0x00020000)
#define  RIF_REG_FPGA_DBG1_imedma_busy_mask                                      (0x00010000)
#define  RIF_REG_FPGA_DBG1_ime_busy_mask                                         (0x00008000)
#define  RIF_REG_FPGA_DBG1_cache_busy_mask                                       (0x00004000)
#define  RIF_REG_FPGA_DBG1_brg_busy_mask                                         (0x00002000)
#define  RIF_REG_FPGA_DBG1_ndb_busy_mask                                         (0x00001000)
#define  RIF_REG_FPGA_DBG1_bsfifo_busy_mask                                      (0x00000800)
#define  RIF_REG_FPGA_DBG1_img_busy_mask                                         (0x00000400)
#define  RIF_REG_FPGA_DBG1_vm1_busy_mask                                         (0x00000200)
#define  RIF_REG_FPGA_DBG1_deblk_busy_mask                                       (0x00000100)
#define  RIF_REG_FPGA_DBG1_rl_busy_mask                                          (0x00000080)
#define  RIF_REG_FPGA_DBG1_pred_busy_mask                                        (0x00000040)
#define  RIF_REG_FPGA_DBG1_mvd_busy_mask                                         (0x00000020)
#define  RIF_REG_FPGA_DBG1_itblk_busy_mask                                       (0x00000010)
#define  RIF_REG_FPGA_DBG1_acdc_busy_mask                                        (0x00000008)
#define  RIF_REG_FPGA_DBG1_cabacp2_busy_mask                                     (0x00000004)
#define  RIF_REG_FPGA_DBG1_vld_busy_mask                                         (0x00000002)
#define  RIF_REG_FPGA_DBG1_rifvld_busy_mask                                      (0x00000001)
#define  RIF_REG_FPGA_DBG1_dcmprs_busy(data)                                     (0x10000000&((data)<<28))
#define  RIF_REG_FPGA_DBG1_cmprs_busy(data)                                      (0x08000000&((data)<<27))
#define  RIF_REG_FPGA_DBG1_seg_busy(data)                                        (0x04000000&((data)<<26))
#define  RIF_REG_FPGA_DBG1_sao_busy(data)                                        (0x02000000&((data)<<25))
#define  RIF_REG_FPGA_DBG1_vm2_busy(data)                                        (0x01000000&((data)<<24))
#define  RIF_REG_FPGA_DBG1_vp8p2_busy(data)                                      (0x00800000&((data)<<23))
#define  RIF_REG_FPGA_DBG1_ndbp2_busy(data)                                      (0x00400000&((data)<<22))
#define  RIF_REG_FPGA_DBG1_ipmd_busy(data)                                       (0x00200000&((data)<<21))
#define  RIF_REG_FPGA_DBG1_fme_busy(data)                                        (0x00100000&((data)<<20))
#define  RIF_REG_FPGA_DBG1_vlc_busy(data)                                        (0x00080000&((data)<<19))
#define  RIF_REG_FPGA_DBG1_gcoeff_busy(data)                                     (0x00040000&((data)<<18))
#define  RIF_REG_FPGA_DBG1_emd_busy(data)                                        (0x00020000&((data)<<17))
#define  RIF_REG_FPGA_DBG1_imedma_busy(data)                                     (0x00010000&((data)<<16))
#define  RIF_REG_FPGA_DBG1_ime_busy(data)                                        (0x00008000&((data)<<15))
#define  RIF_REG_FPGA_DBG1_cache_busy(data)                                      (0x00004000&((data)<<14))
#define  RIF_REG_FPGA_DBG1_brg_busy(data)                                        (0x00002000&((data)<<13))
#define  RIF_REG_FPGA_DBG1_ndb_busy(data)                                        (0x00001000&((data)<<12))
#define  RIF_REG_FPGA_DBG1_bsfifo_busy(data)                                     (0x00000800&((data)<<11))
#define  RIF_REG_FPGA_DBG1_img_busy(data)                                        (0x00000400&((data)<<10))
#define  RIF_REG_FPGA_DBG1_vm1_busy(data)                                        (0x00000200&((data)<<9))
#define  RIF_REG_FPGA_DBG1_deblk_busy(data)                                      (0x00000100&((data)<<8))
#define  RIF_REG_FPGA_DBG1_rl_busy(data)                                         (0x00000080&((data)<<7))
#define  RIF_REG_FPGA_DBG1_pred_busy(data)                                       (0x00000040&((data)<<6))
#define  RIF_REG_FPGA_DBG1_mvd_busy(data)                                        (0x00000020&((data)<<5))
#define  RIF_REG_FPGA_DBG1_itblk_busy(data)                                      (0x00000010&((data)<<4))
#define  RIF_REG_FPGA_DBG1_acdc_busy(data)                                       (0x00000008&((data)<<3))
#define  RIF_REG_FPGA_DBG1_cabacp2_busy(data)                                    (0x00000004&((data)<<2))
#define  RIF_REG_FPGA_DBG1_vld_busy(data)                                        (0x00000002&((data)<<1))
#define  RIF_REG_FPGA_DBG1_rifvld_busy(data)                                     (0x00000001&(data))
#define  RIF_REG_FPGA_DBG1_get_dcmprs_busy(data)                                 ((0x10000000&(data))>>28)
#define  RIF_REG_FPGA_DBG1_get_cmprs_busy(data)                                  ((0x08000000&(data))>>27)
#define  RIF_REG_FPGA_DBG1_get_seg_busy(data)                                    ((0x04000000&(data))>>26)
#define  RIF_REG_FPGA_DBG1_get_sao_busy(data)                                    ((0x02000000&(data))>>25)
#define  RIF_REG_FPGA_DBG1_get_vm2_busy(data)                                    ((0x01000000&(data))>>24)
#define  RIF_REG_FPGA_DBG1_get_vp8p2_busy(data)                                  ((0x00800000&(data))>>23)
#define  RIF_REG_FPGA_DBG1_get_ndbp2_busy(data)                                  ((0x00400000&(data))>>22)
#define  RIF_REG_FPGA_DBG1_get_ipmd_busy(data)                                   ((0x00200000&(data))>>21)
#define  RIF_REG_FPGA_DBG1_get_fme_busy(data)                                    ((0x00100000&(data))>>20)
#define  RIF_REG_FPGA_DBG1_get_vlc_busy(data)                                    ((0x00080000&(data))>>19)
#define  RIF_REG_FPGA_DBG1_get_gcoeff_busy(data)                                 ((0x00040000&(data))>>18)
#define  RIF_REG_FPGA_DBG1_get_emd_busy(data)                                    ((0x00020000&(data))>>17)
#define  RIF_REG_FPGA_DBG1_get_imedma_busy(data)                                 ((0x00010000&(data))>>16)
#define  RIF_REG_FPGA_DBG1_get_ime_busy(data)                                    ((0x00008000&(data))>>15)
#define  RIF_REG_FPGA_DBG1_get_cache_busy(data)                                  ((0x00004000&(data))>>14)
#define  RIF_REG_FPGA_DBG1_get_brg_busy(data)                                    ((0x00002000&(data))>>13)
#define  RIF_REG_FPGA_DBG1_get_ndb_busy(data)                                    ((0x00001000&(data))>>12)
#define  RIF_REG_FPGA_DBG1_get_bsfifo_busy(data)                                 ((0x00000800&(data))>>11)
#define  RIF_REG_FPGA_DBG1_get_img_busy(data)                                    ((0x00000400&(data))>>10)
#define  RIF_REG_FPGA_DBG1_get_vm1_busy(data)                                    ((0x00000200&(data))>>9)
#define  RIF_REG_FPGA_DBG1_get_deblk_busy(data)                                  ((0x00000100&(data))>>8)
#define  RIF_REG_FPGA_DBG1_get_rl_busy(data)                                     ((0x00000080&(data))>>7)
#define  RIF_REG_FPGA_DBG1_get_pred_busy(data)                                   ((0x00000040&(data))>>6)
#define  RIF_REG_FPGA_DBG1_get_mvd_busy(data)                                    ((0x00000020&(data))>>5)
#define  RIF_REG_FPGA_DBG1_get_itblk_busy(data)                                  ((0x00000010&(data))>>4)
#define  RIF_REG_FPGA_DBG1_get_acdc_busy(data)                                   ((0x00000008&(data))>>3)
#define  RIF_REG_FPGA_DBG1_get_cabacp2_busy(data)                                ((0x00000004&(data))>>2)
#define  RIF_REG_FPGA_DBG1_get_vld_busy(data)                                    ((0x00000002&(data))>>1)
#define  RIF_REG_FPGA_DBG1_get_rifvld_busy(data)                                 (0x00000001&(data))
#define  RIF_REG_FPGA_DBG1_dcmprs_busy_src(data)                                 ((0x10000000&(data))>>28)
#define  RIF_REG_FPGA_DBG1_cmprs_busy_src(data)                                  ((0x08000000&(data))>>27)
#define  RIF_REG_FPGA_DBG1_seg_busy_src(data)                                    ((0x04000000&(data))>>26)
#define  RIF_REG_FPGA_DBG1_sao_busy_src(data)                                    ((0x02000000&(data))>>25)
#define  RIF_REG_FPGA_DBG1_vm2_busy_src(data)                                    ((0x01000000&(data))>>24)
#define  RIF_REG_FPGA_DBG1_vp8p2_busy_src(data)                                  ((0x00800000&(data))>>23)
#define  RIF_REG_FPGA_DBG1_ndbp2_busy_src(data)                                  ((0x00400000&(data))>>22)
#define  RIF_REG_FPGA_DBG1_ipmd_busy_src(data)                                   ((0x00200000&(data))>>21)
#define  RIF_REG_FPGA_DBG1_fme_busy_src(data)                                    ((0x00100000&(data))>>20)
#define  RIF_REG_FPGA_DBG1_vlc_busy_src(data)                                    ((0x00080000&(data))>>19)
#define  RIF_REG_FPGA_DBG1_gcoeff_busy_src(data)                                 ((0x00040000&(data))>>18)
#define  RIF_REG_FPGA_DBG1_emd_busy_src(data)                                    ((0x00020000&(data))>>17)
#define  RIF_REG_FPGA_DBG1_imedma_busy_src(data)                                 ((0x00010000&(data))>>16)
#define  RIF_REG_FPGA_DBG1_ime_busy_src(data)                                    ((0x00008000&(data))>>15)
#define  RIF_REG_FPGA_DBG1_cache_busy_src(data)                                  ((0x00004000&(data))>>14)
#define  RIF_REG_FPGA_DBG1_brg_busy_src(data)                                    ((0x00002000&(data))>>13)
#define  RIF_REG_FPGA_DBG1_ndb_busy_src(data)                                    ((0x00001000&(data))>>12)
#define  RIF_REG_FPGA_DBG1_bsfifo_busy_src(data)                                 ((0x00000800&(data))>>11)
#define  RIF_REG_FPGA_DBG1_img_busy_src(data)                                    ((0x00000400&(data))>>10)
#define  RIF_REG_FPGA_DBG1_vm1_busy_src(data)                                    ((0x00000200&(data))>>9)
#define  RIF_REG_FPGA_DBG1_deblk_busy_src(data)                                  ((0x00000100&(data))>>8)
#define  RIF_REG_FPGA_DBG1_rl_busy_src(data)                                     ((0x00000080&(data))>>7)
#define  RIF_REG_FPGA_DBG1_pred_busy_src(data)                                   ((0x00000040&(data))>>6)
#define  RIF_REG_FPGA_DBG1_mvd_busy_src(data)                                    ((0x00000020&(data))>>5)
#define  RIF_REG_FPGA_DBG1_itblk_busy_src(data)                                  ((0x00000010&(data))>>4)
#define  RIF_REG_FPGA_DBG1_acdc_busy_src(data)                                   ((0x00000008&(data))>>3)
#define  RIF_REG_FPGA_DBG1_cabacp2_busy_src(data)                                ((0x00000004&(data))>>2)
#define  RIF_REG_FPGA_DBG1_vld_busy_src(data)                                    ((0x00000002&(data))>>1)
#define  RIF_REG_FPGA_DBG1_rifvld_busy_src(data)                                 (0x00000001&(data))

#define  RIF_REG_DBG_CTRL6                                                       0x1800E4FC
#define  RIF_REG_DBG_CTRL6_reg_addr                                              "0xB800E4FC"
#define  RIF_REG_DBG_CTRL6_reg                                                   0xB800E4FC
#define  RIF_REG_DBG_CTRL6_inst_addr                                             "0x002C"
#define  RIF_REG_DBG_CTRL6_inst_adr                                              "0x003F"
#define  RIF_REG_DBG_CTRL6_inst                                                  0x003F
#define  set_RIF_REG_DBG_CTRL6_reg(data)                                         (*((volatile unsigned int*)RIF_REG_DBG_CTRL6_reg)=data)
#define  get_RIF_REG_DBG_CTRL6_reg                                               (*((volatile unsigned int*)RIF_REG_DBG_CTRL6_reg))
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel1_shift                                    (28)
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel0_shift                                    (24)
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel1_shift                                     (18)
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel0_shift                                     (12)
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel1_shift                                     (6)
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel0_shift                                     (0)
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel1_mask                                     (0xF0000000)
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel0_mask                                     (0x0F000000)
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel1_mask                                      (0x00FC0000)
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel0_mask                                      (0x0003F000)
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel1_mask                                      (0x00000FC0)
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel0_mask                                      (0x0000003F)
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel1(data)                                    (0xF0000000&((data)<<28))
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel0(data)                                    (0x0F000000&((data)<<24))
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel1(data)                                     (0x00FC0000&((data)<<18))
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel0(data)                                     (0x0003F000&((data)<<12))
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel1(data)                                     (0x00000FC0&((data)<<6))
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel0(data)                                     (0x0000003F&(data))
#define  RIF_REG_DBG_CTRL6_get_fme_dbg_sel1(data)                                ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL6_get_fme_dbg_sel0(data)                                ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL6_get_gc_dbg_sel1(data)                                 ((0x00FC0000&(data))>>18)
#define  RIF_REG_DBG_CTRL6_get_gc_dbg_sel0(data)                                 ((0x0003F000&(data))>>12)
#define  RIF_REG_DBG_CTRL6_get_ip_dbg_sel1(data)                                 ((0x00000FC0&(data))>>6)
#define  RIF_REG_DBG_CTRL6_get_ip_dbg_sel0(data)                                 (0x0000003F&(data))
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel1_src(data)                                ((0xF0000000&(data))>>28)
#define  RIF_REG_DBG_CTRL6_fme_dbg_sel0_src(data)                                ((0x0F000000&(data))>>24)
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel1_src(data)                                 ((0x00FC0000&(data))>>18)
#define  RIF_REG_DBG_CTRL6_gc_dbg_sel0_src(data)                                 ((0x0003F000&(data))>>12)
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel1_src(data)                                 ((0x00000FC0&(data))>>6)
#define  RIF_REG_DBG_CTRL6_ip_dbg_sel0_src(data)                                 (0x0000003F&(data))

#ifdef _RIF_REG_USE_STRUCT
#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======RIF_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ve_fpga_reset:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dbg_out_sel1:5;
        RBus_UInt32  dbg_out_sel0:5;
        RBus_UInt32  dbg_out_en:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  encode_en:1;
        RBus_UInt32  ve_soft_reset:1;
        RBus_UInt32  vm_idle:1;
        RBus_UInt32  decode_en:1;
        RBus_UInt32  haltVE_done:1;
        RBus_UInt32  HaltVE:1;
        RBus_UInt32  Veidle:1;
        RBus_UInt32  IntEn:1;
        RBus_UInt32  Reset_ptr:1;
    };
}RIF_REG_VE_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  first_error_b4:1;
        RBus_UInt32  first_error_b3:1;
        RBus_UInt32  first_error_b2:1;
        RBus_UInt32  first_error_b1:1;
        RBus_UInt32  first_error_b0:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dcomp_core_irq:1;
        RBus_UInt32  comp_core_irq:1;
        RBus_UInt32  hevc_p3_hang_int:1;
        RBus_UInt32  hevc_dec_done_int:1;
        RBus_UInt32  ime_int:1;
        RBus_UInt32  ipmd_err:1;
        RBus_UInt32  gc_err:1;
        RBus_UInt32  cmd_fifo_full_int:1;
        RBus_UInt32  rd_rslt_hang_int:1;
        RBus_UInt32  rl_hang_int:1;
        RBus_UInt32  pred_hang_int:1;
        RBus_UInt32  mb_last_int:1;
        RBus_UInt32  mvd_vc1_intfd_err:1;
        RBus_UInt32  mvd_h264_direct_err:1;
        RBus_UInt32  mvd_h264_mv_err:1;
        RBus_UInt32  bs2_fifo_err:1;
        RBus_UInt32  m64coeff:1;
        RBus_UInt32  rstff_oflow:1;
        RBus_UInt32  rstff_empty:1;
        RBus_UInt32  bitst_fifo:1;
        RBus_UInt32  scode_limit:1;
        RBus_UInt32  dec_err:1;
        RBus_UInt32  write_data:1;
    };
}RIF_REG_VE_INT_STATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  dcomp_core_irq_ie:1;
        RBus_UInt32  comp_core_irq_ie:1;
        RBus_UInt32  hevc_p3_hang_int_ie:1;
        RBus_UInt32  hevc_dec_done_int_ie:1;
        RBus_UInt32  gc_interrupt_on:1;
        RBus_UInt32  ipmd_interrupt_on:1;
        RBus_UInt32  ime_int_ie:1;
        RBus_UInt32  ipmd_err_ie:1;
        RBus_UInt32  gc_err_ie:1;
        RBus_UInt32  cmd_fifo_full_int_ie:1;
        RBus_UInt32  rd_rslt_hang_int_ie:1;
        RBus_UInt32  rl_hang_int_ie:1;
        RBus_UInt32  pred_hang_int_ie:1;
        RBus_UInt32  mb_last_int_ie:1;
        RBus_UInt32  mvd_vc1_intfd_ie:1;
        RBus_UInt32  mvd_h264_direct_ie:1;
        RBus_UInt32  mvd_h264_mv_ie:1;
        RBus_UInt32  bs2_fifo_err_ie:1;
        RBus_UInt32  m64coeff_ie:1;
        RBus_UInt32  rstff_oflow_ie:1;
        RBus_UInt32  rstff_empty_ie:1;
        RBus_UInt32  bitst_fifo_ie:1;
        RBus_UInt32  scode_limit_ie:1;
        RBus_UInt32  dec_err_ie:1;
        RBus_UInt32  write_data:1;
    };
}RIF_REG_VE_INT_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  debk_inst_cnt:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pred_inst_cnt:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  dmab_inst_cnt:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  dmaa_inst_cnt:6;
    };
}RIF_REG_VE_FIFOSTATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  act_rslt_in_fifo:5;
        RBus_UInt32  rslt_fifo_cnt:5;
        RBus_UInt32  img_fifo_cnt:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dec_inst_cnt:6;
        RBus_UInt32  res2:8;
    };
}RIF_REG_VE_FIFOSTAT2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rslt_timer:24;
    };
}RIF_REG_VE_RSLT_TIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cmd_timer:24;
    };
}RIF_REG_VE_CMD_TIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ime_inst_cnt:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  emd_inst_cnt:6;
    };
}RIF_REG_VE_FIFOSTAT3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  ve_cmprs_bnk:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ve_img_bnk:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  ve_deb_bnk:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  ve_prd_bnk:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  ve_dmab_bnk:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  ve_dmaa_bnk:3;
    };
}RIF_REG_VMBANKSEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ve_gcf_umbnk:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ve_emd_umbnk:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  ve_ime_umbk:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  ve_dma_umbnk:2;
    };
}RIF_REG_UMBANKSEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  lossy_en:1;
        RBus_UInt32  cmprs_head_remap:1;
        RBus_UInt32  mode32x1:1;
        RBus_UInt32  gpu_out_en:1;
        RBus_UInt32  dual_core_dmy_row_method:1;
        RBus_UInt32  comp_wrap_width:10;
        RBus_UInt32  compression_en:1;
        RBus_UInt32  MultiCoreEnable:2;
        RBus_UInt32  CoreNum:2;
        RBus_UInt32  mode8x2_16b_align:1;
        RBus_UInt32  mode8x2:1;
        RBus_UInt32  monochrome:1;
        RBus_UInt32  level:1;
        RBus_UInt32  profile:2;
        RBus_UInt32  coding_type:5;
    };
}RIF_REG_DEC_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  filter_level:6;
        RBus_UInt32  allow_high_precision_mv:1;
        RBus_UInt32  vp9_seg_en:1;
        RBus_UInt32  vp8_bicubic_filtering:1;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  field_pic_flag:1;
        RBus_UInt32  picmb_h:9;
        RBus_UInt32  picmb_w:10;
    };
}RIF_REG_PICINFO1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  mode16x1:1;
        RBus_UInt32  Constrainted_intra_pred_flag:1;
        RBus_UInt32  Weighted_pred_flag:1;
        RBus_UInt32  Weighted_bipred_idc:2;
        RBus_UInt32  frame_mbs_only_flag:1;
        RBus_UInt32  mb_adaptive_frame_field_flag:1;
    };
}RIF_REG_H264PICCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  chroma_bits:2;
        RBus_UInt32  luma_bits:2;
        RBus_UInt32  hevc_dbg_mode:1;
        RBus_UInt32  decimate_en:2;
        RBus_UInt32  mincbsize:2;
        RBus_UInt32  ctbsize:2;
        RBus_UInt32  min_trafo_size:2;
        RBus_UInt32  max_trafo_size:2;
        RBus_UInt32  max_trans_hier_depth_inter:3;
        RBus_UInt32  max_trans_hier_depth_intra:3;
        RBus_UInt32  amp_enabled_flag:1;
        RBus_UInt32  sample_adaptive_offset_enabled_flag:1;
        RBus_UInt32  pcm_enabled_flag:1;
        RBus_UInt32  min_ipcm_cbsize:2;
        RBus_UInt32  max_ipcm_cbsize:2;
        RBus_UInt32  pcm_loop_filter_disable_flag:1;
        RBus_UInt32  strong_intra_smoothing_enable_flag:1;
    };
}RIF_REG_HEVCSEQCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  transform_skip_enabled_flag:1;
        RBus_UInt32  cu_qp_delta_enabled_flag:1;
        RBus_UInt32  min_cu_qp_delta_size:3;
        RBus_UInt32  pic_cb_qp_offset:5;
        RBus_UInt32  pic_cr_qp_offset:5;
        RBus_UInt32  loop_filter_across_tiles_enabled_flag:1;
        RBus_UInt32  loop_filter_across_slices_enabled_flag:1;
        RBus_UInt32  log2_parallel_merge_level_minus2:3;
    };
}RIF_REG_HEVCPICCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  pic_width:14;
        RBus_UInt32  pic_height:13;
    };
}RIF_REG_HEVCPICSIZE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Overlap_enable:1;
        RBus_UInt32  field_pictype:3;
        RBus_UInt32  mvmode:2;
        RBus_UInt32  fcm:2;
        RBus_UInt32  disppic_h:12;
        RBus_UInt32  disppic_w:12;
    };
}RIF_REG_VC1PICCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  wmv9_bug_rtmflag:1;
        RBus_UInt32  wmv9_bug_it:1;
        RBus_UInt32  loopfilter:1;
        RBus_UInt32  numref:1;
        RBus_UInt32  pquant:5;
    };
}RIF_REG_VC1PICCNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x_scale_fp:16;
        RBus_UInt32  y_scale_fp:16;
    };
}RIF_REG_SCALE_FP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  priority_thd2:8;
        RBus_UInt32  priority_thd1:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  srg_mode:1;
        RBus_UInt32  ddr_page:2;
        RBus_UInt32  srg_enable:1;
    };
}RIF_REG_BRG_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vm2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vm1:12;
    };
}RIF_REG_RD_PRIORITY0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  deblk:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  predblk:12;
    };
}RIF_REG_RD_PRIORITY1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nm:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mvd:12;
    };
}RIF_REG_RD_PRIORITY2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gcoeff:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  bs:12;
    };
}RIF_REG_RD_PRIORITY3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cmp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rl:12;
    };
}RIF_REG_RD_PRIORITY4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fme:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ime:12;
    };
}RIF_REG_RD_PRIORITY5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  vm2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  vm1:11;
    };
}RIF_REG_WT_PRIORITY0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  deblk:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  predblk:11;
    };
}RIF_REG_WT_PRIORITY1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  nm:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  mvd:11;
    };
}RIF_REG_WT_PRIORITY2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gcoeff:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  bs:11;
    };
}RIF_REG_WT_PRIORITY3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cmp:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  it:11;
    };
}RIF_REG_WT_PRIORITY4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  fme:11;
    };
}RIF_REG_WT_PRIORITY5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sb3_sf_rx_err_ro:1;
        RBus_UInt32  sb3_sf_rx_done_ro:1;
        RBus_UInt32  sb3_sf_rx_gated:1;
        RBus_UInt32  sb3_sf_rx_start:1;
        RBus_UInt32  sb3_sf_rx_mode:1;
        RBus_UInt32  sb3_sf_tx_work_ro:1;
        RBus_UInt32  sb3_sf_tx_start:1;
        RBus_UInt32  sb3_sf_tx_mode:1;
        RBus_UInt32  dc_sf_rx_err_ro:1;
        RBus_UInt32  dc_sf_rx_done_ro:1;
        RBus_UInt32  dc_sf_rx_gated:1;
        RBus_UInt32  dc_sf_rx_start:1;
        RBus_UInt32  dc_sf_rx_mode:1;
        RBus_UInt32  dc_sf_tx_work_ro:1;
        RBus_UInt32  dc_sf_tx_start:1;
        RBus_UInt32  dc_sf_tx_mode:1;
    };
}RIF_REG_SF_TEST_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cache_gated_en:1;
        RBus_UInt32  rl_gated_en:1;
        RBus_UInt32  mvd_gated_en:1;
        RBus_UInt32  ndbp2_gated_en:1;
        RBus_UInt32  ndb_gated_en:1;
        RBus_UInt32  brg_gated_en:1;
        RBus_UInt32  cm_gated_en:1;
        RBus_UInt32  arb_gated_en:1;
        RBus_UInt32  bsfifop2_gated_en:1;
        RBus_UInt32  bsfifo_gated_en:1;
        RBus_UInt32  img_gated_en:1;
        RBus_UInt32  deblk_gated_en:1;
        RBus_UInt32  gc_gated_en:1;
        RBus_UInt32  pred_gated_en:1;
        RBus_UInt32  emd_gated_en:1;
        RBus_UInt32  imedma_gated_en:1;
        RBus_UInt32  ime_gated_en:1;
        RBus_UInt32  vm2_gated_en:1;
        RBus_UInt32  vm1_gated_en:1;
        RBus_UInt32  it_gated_en:1;
        RBus_UInt32  cabac_gated_en:1;
        RBus_UInt32  vp8p2_gated_en:1;
        RBus_UInt32  cabacp2_gated_en:1;
        RBus_UInt32  vld_gated_en:1;
        RBus_UInt32  vlc_gated_en:1;
        RBus_UInt32  acdc_gated_en:1;
    };
}RIF_REG_CLKGATED_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  seg_dbg_sel1:4;
        RBus_UInt32  seg_dbg_sel0:4;
        RBus_UInt32  sao_dbg_sel1:4;
        RBus_UInt32  sao_dbg_sel0:4;
        RBus_UInt32  ime_dbg_sel1:6;
        RBus_UInt32  ime_dbg_sel0:6;
    };
}RIF_REG_DBG_CTRL17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_dbg_out1:16;
        RBus_UInt32  ve_dbg_out0:16;
    };
}RIF_REG_DBG_OUT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cache_dbg_sel1:4;
        RBus_UInt32  cache_dbg_sel0:4;
        RBus_UInt32  bs_dbg_sel1:4;
        RBus_UInt32  bs_dbg_sel0:4;
        RBus_UInt32  brg_dbg_sel1:4;
        RBus_UInt32  brg_dbg_sel0:4;
        RBus_UInt32  acdc_dbg_sel1:4;
        RBus_UInt32  acdc_dbg_sel0:4;
    };
}RIF_REG_DBG_CTRL1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  bs_dbg_sel3:2;
        RBus_UInt32  bs_dbg_sel2:2;
        RBus_UInt32  cm_dbg_sel1:4;
        RBus_UInt32  cm_dbg_sel0:4;
        RBus_UInt32  cabacp3_dbg_sel1:4;
        RBus_UInt32  cabacp3_dbg_sel0:4;
        RBus_UInt32  cabacp2_dbg_sel1:4;
        RBus_UInt32  cabacp2_dbg_sel0:4;
    };
}RIF_REG_DBG_CTRL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ndb_dbg_sel1:4;
        RBus_UInt32  ndb_dbg_sel0:4;
        RBus_UInt32  rif_dbg_sel1:4;
        RBus_UInt32  rif_dbg_sel0:4;
        RBus_UInt32  itblk_dbg_sel1:4;
        RBus_UInt32  itblk_dbg_sel0:4;
        RBus_UInt32  img_dbg_sel1:4;
        RBus_UInt32  img_dbg_sel0:4;
    };
}RIF_REG_DBG_CTRL3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rl_dbg_sel1:4;
        RBus_UInt32  rl_dbg_sel0:4;
        RBus_UInt32  vld_dbg_sel1:4;
        RBus_UInt32  vld_dbg_sel0:4;
        RBus_UInt32  arb_dbg_sel1:4;
        RBus_UInt32  arb_dbg_sel0:4;
        RBus_UInt32  vm1_dbg_sel1:4;
        RBus_UInt32  vm1_dbg_sel0:4;
    };
}RIF_REG_DBG_CTRL4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  deblk_dbg_sel1:6;
        RBus_UInt32  deblk_dbg_sel0:6;
        RBus_UInt32  mvd_dbg_sel1:4;
        RBus_UInt32  mvd_dbg_sel0:4;
        RBus_UInt32  prd_dbg_sel1:6;
        RBus_UInt32  prd_dbg_sel0:6;
    };
}RIF_REG_DBG_CTRL5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dcmprs_busy:1;
        RBus_UInt32  cmprs_busy:1;
        RBus_UInt32  seg_busy:1;
        RBus_UInt32  sao_busy:1;
        RBus_UInt32  vm2_busy:1;
        RBus_UInt32  vp8p2_busy:1;
        RBus_UInt32  ndbp2_busy:1;
        RBus_UInt32  ipmd_busy:1;
        RBus_UInt32  fme_busy:1;
        RBus_UInt32  vlc_busy:1;
        RBus_UInt32  gcoeff_busy:1;
        RBus_UInt32  emd_busy:1;
        RBus_UInt32  imedma_busy:1;
        RBus_UInt32  ime_busy:1;
        RBus_UInt32  cache_busy:1;
        RBus_UInt32  brg_busy:1;
        RBus_UInt32  ndb_busy:1;
        RBus_UInt32  bsfifo_busy:1;
        RBus_UInt32  img_busy:1;
        RBus_UInt32  vm1_busy:1;
        RBus_UInt32  deblk_busy:1;
        RBus_UInt32  rl_busy:1;
        RBus_UInt32  pred_busy:1;
        RBus_UInt32  mvd_busy:1;
        RBus_UInt32  itblk_busy:1;
        RBus_UInt32  acdc_busy:1;
        RBus_UInt32  cabacp2_busy:1;
        RBus_UInt32  vld_busy:1;
        RBus_UInt32  rifvld_busy:1;
    };
}RIF_REG_FPGA_DBG1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fme_dbg_sel1:4;
        RBus_UInt32  fme_dbg_sel0:4;
        RBus_UInt32  gc_dbg_sel1:6;
        RBus_UInt32  gc_dbg_sel0:6;
        RBus_UInt32  ip_dbg_sel1:6;
        RBus_UInt32  ip_dbg_sel0:6;
    };
}RIF_REG_DBG_CTRL6_RBUS;

#else //apply LITTLE_ENDIAN

//======RIF_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  Reset_ptr:1;
        RBus_UInt32  IntEn:1;
        RBus_UInt32  Veidle:1;
        RBus_UInt32  HaltVE:1;
        RBus_UInt32  haltVE_done:1;
        RBus_UInt32  decode_en:1;
        RBus_UInt32  vm_idle:1;
        RBus_UInt32  ve_soft_reset:1;
        RBus_UInt32  encode_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  dbg_out_en:1;
        RBus_UInt32  dbg_out_sel0:5;
        RBus_UInt32  dbg_out_sel1:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  ve_fpga_reset:1;
        RBus_UInt32  res3:2;
    };
}RIF_REG_VE_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  dec_err:1;
        RBus_UInt32  scode_limit:1;
        RBus_UInt32  bitst_fifo:1;
        RBus_UInt32  rstff_empty:1;
        RBus_UInt32  rstff_oflow:1;
        RBus_UInt32  m64coeff:1;
        RBus_UInt32  bs2_fifo_err:1;
        RBus_UInt32  mvd_h264_mv_err:1;
        RBus_UInt32  mvd_h264_direct_err:1;
        RBus_UInt32  mvd_vc1_intfd_err:1;
        RBus_UInt32  mb_last_int:1;
        RBus_UInt32  pred_hang_int:1;
        RBus_UInt32  rl_hang_int:1;
        RBus_UInt32  rd_rslt_hang_int:1;
        RBus_UInt32  cmd_fifo_full_int:1;
        RBus_UInt32  gc_err:1;
        RBus_UInt32  ipmd_err:1;
        RBus_UInt32  ime_int:1;
        RBus_UInt32  hevc_dec_done_int:1;
        RBus_UInt32  hevc_p3_hang_int:1;
        RBus_UInt32  comp_core_irq:1;
        RBus_UInt32  dcomp_core_irq:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  first_error_b0:1;
        RBus_UInt32  first_error_b1:1;
        RBus_UInt32  first_error_b2:1;
        RBus_UInt32  first_error_b3:1;
        RBus_UInt32  first_error_b4:1;
        RBus_UInt32  res2:3;
    };
}RIF_REG_VE_INT_STATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  dec_err_ie:1;
        RBus_UInt32  scode_limit_ie:1;
        RBus_UInt32  bitst_fifo_ie:1;
        RBus_UInt32  rstff_empty_ie:1;
        RBus_UInt32  rstff_oflow_ie:1;
        RBus_UInt32  m64coeff_ie:1;
        RBus_UInt32  bs2_fifo_err_ie:1;
        RBus_UInt32  mvd_h264_mv_ie:1;
        RBus_UInt32  mvd_h264_direct_ie:1;
        RBus_UInt32  mvd_vc1_intfd_ie:1;
        RBus_UInt32  mb_last_int_ie:1;
        RBus_UInt32  pred_hang_int_ie:1;
        RBus_UInt32  rl_hang_int_ie:1;
        RBus_UInt32  rd_rslt_hang_int_ie:1;
        RBus_UInt32  cmd_fifo_full_int_ie:1;
        RBus_UInt32  gc_err_ie:1;
        RBus_UInt32  ipmd_err_ie:1;
        RBus_UInt32  ime_int_ie:1;
        RBus_UInt32  ipmd_interrupt_on:1;
        RBus_UInt32  gc_interrupt_on:1;
        RBus_UInt32  hevc_dec_done_int_ie:1;
        RBus_UInt32  hevc_p3_hang_int_ie:1;
        RBus_UInt32  comp_core_irq_ie:1;
        RBus_UInt32  dcomp_core_irq_ie:1;
        RBus_UInt32  res1:7;
    };
}RIF_REG_VE_INT_EN_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dmaa_inst_cnt:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dmab_inst_cnt:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  pred_inst_cnt:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  debk_inst_cnt:6;
        RBus_UInt32  res4:2;
    };
}RIF_REG_VE_FIFOSTATUS_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  dec_inst_cnt:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  img_fifo_cnt:6;
        RBus_UInt32  rslt_fifo_cnt:5;
        RBus_UInt32  act_rslt_in_fifo:5;
    };
}RIF_REG_VE_FIFOSTAT2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rslt_timer:24;
        RBus_UInt32  res1:8;
    };
}RIF_REG_VE_RSLT_TIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_timer:24;
        RBus_UInt32  res1:8;
    };
}RIF_REG_VE_CMD_TIMER_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emd_inst_cnt:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ime_inst_cnt:6;
        RBus_UInt32  res2:18;
    };
}RIF_REG_VE_FIFOSTAT3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_dmaa_bnk:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ve_dmab_bnk:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ve_prd_bnk:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  ve_deb_bnk:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  ve_img_bnk:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  ve_cmprs_bnk:3;
        RBus_UInt32  res6:9;
    };
}RIF_REG_VMBANKSEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_dma_umbnk:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  ve_ime_umbk:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ve_emd_umbnk:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  ve_gcf_umbnk:2;
        RBus_UInt32  res4:18;
    };
}RIF_REG_UMBANKSEL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coding_type:5;
        RBus_UInt32  profile:2;
        RBus_UInt32  level:1;
        RBus_UInt32  monochrome:1;
        RBus_UInt32  mode8x2:1;
        RBus_UInt32  mode8x2_16b_align:1;
        RBus_UInt32  CoreNum:2;
        RBus_UInt32  MultiCoreEnable:2;
        RBus_UInt32  compression_en:1;
        RBus_UInt32  comp_wrap_width:10;
        RBus_UInt32  dual_core_dmy_row_method:1;
        RBus_UInt32  gpu_out_en:1;
        RBus_UInt32  mode32x1:1;
        RBus_UInt32  cmprs_head_remap:1;
        RBus_UInt32  lossy_en:1;
        RBus_UInt32  res1:1;
    };
}RIF_REG_DEC_CNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  picmb_w:10;
        RBus_UInt32  picmb_h:9;
        RBus_UInt32  field_pic_flag:1;
        RBus_UInt32  bottom_field_flag:1;
        RBus_UInt32  vp8_bicubic_filtering:1;
        RBus_UInt32  vp9_seg_en:1;
        RBus_UInt32  allow_high_precision_mv:1;
        RBus_UInt32  filter_level:6;
        RBus_UInt32  res1:2;
    };
}RIF_REG_PICINFO1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_adaptive_frame_field_flag:1;
        RBus_UInt32  frame_mbs_only_flag:1;
        RBus_UInt32  Weighted_bipred_idc:2;
        RBus_UInt32  Weighted_pred_flag:1;
        RBus_UInt32  Constrainted_intra_pred_flag:1;
        RBus_UInt32  mode16x1:1;
        RBus_UInt32  res1:25;
    };
}RIF_REG_H264PICCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  strong_intra_smoothing_enable_flag:1;
        RBus_UInt32  pcm_loop_filter_disable_flag:1;
        RBus_UInt32  max_ipcm_cbsize:2;
        RBus_UInt32  min_ipcm_cbsize:2;
        RBus_UInt32  pcm_enabled_flag:1;
        RBus_UInt32  sample_adaptive_offset_enabled_flag:1;
        RBus_UInt32  amp_enabled_flag:1;
        RBus_UInt32  max_trans_hier_depth_intra:3;
        RBus_UInt32  max_trans_hier_depth_inter:3;
        RBus_UInt32  max_trafo_size:2;
        RBus_UInt32  min_trafo_size:2;
        RBus_UInt32  ctbsize:2;
        RBus_UInt32  mincbsize:2;
        RBus_UInt32  decimate_en:2;
        RBus_UInt32  hevc_dbg_mode:1;
        RBus_UInt32  luma_bits:2;
        RBus_UInt32  chroma_bits:2;
        RBus_UInt32  res1:2;
    };
}RIF_REG_HEVCSEQCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  log2_parallel_merge_level_minus2:3;
        RBus_UInt32  loop_filter_across_slices_enabled_flag:1;
        RBus_UInt32  loop_filter_across_tiles_enabled_flag:1;
        RBus_UInt32  pic_cr_qp_offset:5;
        RBus_UInt32  pic_cb_qp_offset:5;
        RBus_UInt32  min_cu_qp_delta_size:3;
        RBus_UInt32  cu_qp_delta_enabled_flag:1;
        RBus_UInt32  transform_skip_enabled_flag:1;
        RBus_UInt32  res1:12;
    };
}RIF_REG_HEVCPICCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pic_height:13;
        RBus_UInt32  pic_width:14;
        RBus_UInt32  res1:5;
    };
}RIF_REG_HEVCPICSIZE_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disppic_w:12;
        RBus_UInt32  disppic_h:12;
        RBus_UInt32  fcm:2;
        RBus_UInt32  mvmode:2;
        RBus_UInt32  field_pictype:3;
        RBus_UInt32  Overlap_enable:1;
    };
}RIF_REG_VC1PICCNTL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pquant:5;
        RBus_UInt32  numref:1;
        RBus_UInt32  loopfilter:1;
        RBus_UInt32  wmv9_bug_it:1;
        RBus_UInt32  wmv9_bug_rtmflag:1;
        RBus_UInt32  res1:23;
    };
}RIF_REG_VC1PICCNTL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_scale_fp:16;
        RBus_UInt32  x_scale_fp:16;
    };
}RIF_REG_SCALE_FP_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  srg_enable:1;
        RBus_UInt32  ddr_page:2;
        RBus_UInt32  srg_mode:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  priority_thd1:8;
        RBus_UInt32  priority_thd2:8;
        RBus_UInt32  res2:8;
    };
}RIF_REG_BRG_CTRL_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vm1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  vm2:12;
        RBus_UInt32  res2:4;
    };
}RIF_REG_RD_PRIORITY0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  predblk:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  deblk:12;
        RBus_UInt32  res2:4;
    };
}RIF_REG_RD_PRIORITY1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvd:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nm:12;
        RBus_UInt32  res2:4;
    };
}RIF_REG_RD_PRIORITY2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bs:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  gcoeff:12;
        RBus_UInt32  res2:4;
    };
}RIF_REG_RD_PRIORITY3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rl:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cmp:12;
        RBus_UInt32  res2:4;
    };
}RIF_REG_RD_PRIORITY4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ime:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  fme:12;
        RBus_UInt32  res2:4;
    };
}RIF_REG_RD_PRIORITY5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vm1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  vm2:11;
        RBus_UInt32  res2:5;
    };
}RIF_REG_WT_PRIORITY0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  predblk:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  deblk:11;
        RBus_UInt32  res2:5;
    };
}RIF_REG_WT_PRIORITY1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvd:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  nm:11;
        RBus_UInt32  res2:5;
    };
}RIF_REG_WT_PRIORITY2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bs:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  gcoeff:11;
        RBus_UInt32  res2:5;
    };
}RIF_REG_WT_PRIORITY3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  it:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  cmp:11;
        RBus_UInt32  res2:5;
    };
}RIF_REG_WT_PRIORITY4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fme:11;
        RBus_UInt32  res1:21;
    };
}RIF_REG_WT_PRIORITY5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_sf_tx_mode:1;
        RBus_UInt32  dc_sf_tx_start:1;
        RBus_UInt32  dc_sf_tx_work_ro:1;
        RBus_UInt32  dc_sf_rx_mode:1;
        RBus_UInt32  dc_sf_rx_start:1;
        RBus_UInt32  dc_sf_rx_gated:1;
        RBus_UInt32  dc_sf_rx_done_ro:1;
        RBus_UInt32  dc_sf_rx_err_ro:1;
        RBus_UInt32  sb3_sf_tx_mode:1;
        RBus_UInt32  sb3_sf_tx_start:1;
        RBus_UInt32  sb3_sf_tx_work_ro:1;
        RBus_UInt32  sb3_sf_rx_mode:1;
        RBus_UInt32  sb3_sf_rx_start:1;
        RBus_UInt32  sb3_sf_rx_gated:1;
        RBus_UInt32  sb3_sf_rx_done_ro:1;
        RBus_UInt32  sb3_sf_rx_err_ro:1;
        RBus_UInt32  res1:16;
    };
}RIF_REG_SF_TEST_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acdc_gated_en:1;
        RBus_UInt32  vlc_gated_en:1;
        RBus_UInt32  vld_gated_en:1;
        RBus_UInt32  cabacp2_gated_en:1;
        RBus_UInt32  vp8p2_gated_en:1;
        RBus_UInt32  cabac_gated_en:1;
        RBus_UInt32  it_gated_en:1;
        RBus_UInt32  vm1_gated_en:1;
        RBus_UInt32  vm2_gated_en:1;
        RBus_UInt32  ime_gated_en:1;
        RBus_UInt32  imedma_gated_en:1;
        RBus_UInt32  emd_gated_en:1;
        RBus_UInt32  pred_gated_en:1;
        RBus_UInt32  gc_gated_en:1;
        RBus_UInt32  deblk_gated_en:1;
        RBus_UInt32  img_gated_en:1;
        RBus_UInt32  bsfifo_gated_en:1;
        RBus_UInt32  bsfifop2_gated_en:1;
        RBus_UInt32  arb_gated_en:1;
        RBus_UInt32  cm_gated_en:1;
        RBus_UInt32  brg_gated_en:1;
        RBus_UInt32  ndb_gated_en:1;
        RBus_UInt32  ndbp2_gated_en:1;
        RBus_UInt32  mvd_gated_en:1;
        RBus_UInt32  rl_gated_en:1;
        RBus_UInt32  cache_gated_en:1;
        RBus_UInt32  res1:6;
    };
}RIF_REG_CLKGATED_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ime_dbg_sel0:6;
        RBus_UInt32  ime_dbg_sel1:6;
        RBus_UInt32  sao_dbg_sel0:4;
        RBus_UInt32  sao_dbg_sel1:4;
        RBus_UInt32  seg_dbg_sel0:4;
        RBus_UInt32  seg_dbg_sel1:4;
        RBus_UInt32  res1:4;
    };
}RIF_REG_DBG_CTRL17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_dbg_out0:16;
        RBus_UInt32  ve_dbg_out1:16;
    };
}RIF_REG_DBG_OUT_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  acdc_dbg_sel0:4;
        RBus_UInt32  acdc_dbg_sel1:4;
        RBus_UInt32  brg_dbg_sel0:4;
        RBus_UInt32  brg_dbg_sel1:4;
        RBus_UInt32  bs_dbg_sel0:4;
        RBus_UInt32  bs_dbg_sel1:4;
        RBus_UInt32  cache_dbg_sel0:4;
        RBus_UInt32  cache_dbg_sel1:4;
    };
}RIF_REG_DBG_CTRL1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cabacp2_dbg_sel0:4;
        RBus_UInt32  cabacp2_dbg_sel1:4;
        RBus_UInt32  cabacp3_dbg_sel0:4;
        RBus_UInt32  cabacp3_dbg_sel1:4;
        RBus_UInt32  cm_dbg_sel0:4;
        RBus_UInt32  cm_dbg_sel1:4;
        RBus_UInt32  bs_dbg_sel2:2;
        RBus_UInt32  bs_dbg_sel3:2;
        RBus_UInt32  res1:4;
    };
}RIF_REG_DBG_CTRL2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  img_dbg_sel0:4;
        RBus_UInt32  img_dbg_sel1:4;
        RBus_UInt32  itblk_dbg_sel0:4;
        RBus_UInt32  itblk_dbg_sel1:4;
        RBus_UInt32  rif_dbg_sel0:4;
        RBus_UInt32  rif_dbg_sel1:4;
        RBus_UInt32  ndb_dbg_sel0:4;
        RBus_UInt32  ndb_dbg_sel1:4;
    };
}RIF_REG_DBG_CTRL3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vm1_dbg_sel0:4;
        RBus_UInt32  vm1_dbg_sel1:4;
        RBus_UInt32  arb_dbg_sel0:4;
        RBus_UInt32  arb_dbg_sel1:4;
        RBus_UInt32  vld_dbg_sel0:4;
        RBus_UInt32  vld_dbg_sel1:4;
        RBus_UInt32  rl_dbg_sel0:4;
        RBus_UInt32  rl_dbg_sel1:4;
    };
}RIF_REG_DBG_CTRL4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  prd_dbg_sel0:6;
        RBus_UInt32  prd_dbg_sel1:6;
        RBus_UInt32  mvd_dbg_sel0:4;
        RBus_UInt32  mvd_dbg_sel1:4;
        RBus_UInt32  deblk_dbg_sel0:6;
        RBus_UInt32  deblk_dbg_sel1:6;
    };
}RIF_REG_DBG_CTRL5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rifvld_busy:1;
        RBus_UInt32  vld_busy:1;
        RBus_UInt32  cabacp2_busy:1;
        RBus_UInt32  acdc_busy:1;
        RBus_UInt32  itblk_busy:1;
        RBus_UInt32  mvd_busy:1;
        RBus_UInt32  pred_busy:1;
        RBus_UInt32  rl_busy:1;
        RBus_UInt32  deblk_busy:1;
        RBus_UInt32  vm1_busy:1;
        RBus_UInt32  img_busy:1;
        RBus_UInt32  bsfifo_busy:1;
        RBus_UInt32  ndb_busy:1;
        RBus_UInt32  brg_busy:1;
        RBus_UInt32  cache_busy:1;
        RBus_UInt32  ime_busy:1;
        RBus_UInt32  imedma_busy:1;
        RBus_UInt32  emd_busy:1;
        RBus_UInt32  gcoeff_busy:1;
        RBus_UInt32  vlc_busy:1;
        RBus_UInt32  fme_busy:1;
        RBus_UInt32  ipmd_busy:1;
        RBus_UInt32  ndbp2_busy:1;
        RBus_UInt32  vp8p2_busy:1;
        RBus_UInt32  vm2_busy:1;
        RBus_UInt32  sao_busy:1;
        RBus_UInt32  seg_busy:1;
        RBus_UInt32  cmprs_busy:1;
        RBus_UInt32  dcmprs_busy:1;
        RBus_UInt32  res1:3;
    };
}RIF_REG_FPGA_DBG1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ip_dbg_sel0:6;
        RBus_UInt32  ip_dbg_sel1:6;
        RBus_UInt32  gc_dbg_sel0:6;
        RBus_UInt32  gc_dbg_sel1:6;
        RBus_UInt32  fme_dbg_sel0:4;
        RBus_UInt32  fme_dbg_sel1:4;
    };
}RIF_REG_DBG_CTRL6_RBUS;




#endif 


#endif 
#endif 
