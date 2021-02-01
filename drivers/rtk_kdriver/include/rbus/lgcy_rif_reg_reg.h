/**
* @file Mac5_LGCY_VE_top_arch_spec
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LGCY_RIF_REG_REG_H_
#define _RBUS_LGCY_RIF_REG_REG_H_

#include "rbus_types.h"



//  LGCY_RIF_REG Register Address
#define  LGCY_RIF_REG_ve_ctrl                                                    0x1800E400
#define  LGCY_RIF_REG_ve_ctrl_reg_addr                                           "0xB800E400"
#define  LGCY_RIF_REG_ve_ctrl_reg                                                0xB800E400
#define  LGCY_RIF_REG_ve_ctrl_inst_addr                                          "0x0000"
#define  set_LGCY_RIF_REG_ve_ctrl_reg(data)                                      (*((volatile unsigned int*)LGCY_RIF_REG_ve_ctrl_reg)=data)
#define  get_LGCY_RIF_REG_ve_ctrl_reg                                            (*((volatile unsigned int*)LGCY_RIF_REG_ve_ctrl_reg))
#define  LGCY_RIF_REG_ve_ctrl_ve_fpga_reset_shift                                (29)
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_sel1_shift                                 (22)
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_sel0_shift                                 (17)
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_en_shift                                   (16)
#define  LGCY_RIF_REG_ve_ctrl_encode_en_shift                                    (8)
#define  LGCY_RIF_REG_ve_ctrl_ve_soft_reset_shift                                (7)
#define  LGCY_RIF_REG_ve_ctrl_vm_idle_shift                                      (6)
#define  LGCY_RIF_REG_ve_ctrl_decode_en_shift                                    (5)
#define  LGCY_RIF_REG_ve_ctrl_haltve_done_shift                                  (4)
#define  LGCY_RIF_REG_ve_ctrl_haltve_shift                                       (3)
#define  LGCY_RIF_REG_ve_ctrl_veidle_shift                                       (2)
#define  LGCY_RIF_REG_ve_ctrl_inten_shift                                        (1)
#define  LGCY_RIF_REG_ve_ctrl_reset_ptr_shift                                    (0)
#define  LGCY_RIF_REG_ve_ctrl_ve_fpga_reset_mask                                 (0x20000000)
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_sel1_mask                                  (0x07C00000)
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_sel0_mask                                  (0x003E0000)
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_en_mask                                    (0x00010000)
#define  LGCY_RIF_REG_ve_ctrl_encode_en_mask                                     (0x00000100)
#define  LGCY_RIF_REG_ve_ctrl_ve_soft_reset_mask                                 (0x00000080)
#define  LGCY_RIF_REG_ve_ctrl_vm_idle_mask                                       (0x00000040)
#define  LGCY_RIF_REG_ve_ctrl_decode_en_mask                                     (0x00000020)
#define  LGCY_RIF_REG_ve_ctrl_haltve_done_mask                                   (0x00000010)
#define  LGCY_RIF_REG_ve_ctrl_haltve_mask                                        (0x00000008)
#define  LGCY_RIF_REG_ve_ctrl_veidle_mask                                        (0x00000004)
#define  LGCY_RIF_REG_ve_ctrl_inten_mask                                         (0x00000002)
#define  LGCY_RIF_REG_ve_ctrl_reset_ptr_mask                                     (0x00000001)
#define  LGCY_RIF_REG_ve_ctrl_ve_fpga_reset(data)                                (0x20000000&((data)<<29))
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_sel1(data)                                 (0x07C00000&((data)<<22))
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_sel0(data)                                 (0x003E0000&((data)<<17))
#define  LGCY_RIF_REG_ve_ctrl_dbg_out_en(data)                                   (0x00010000&((data)<<16))
#define  LGCY_RIF_REG_ve_ctrl_encode_en(data)                                    (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_ve_ctrl_ve_soft_reset(data)                                (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_ve_ctrl_vm_idle(data)                                      (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_ve_ctrl_decode_en(data)                                    (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_ve_ctrl_haltve_done(data)                                  (0x00000010&((data)<<4))
#define  LGCY_RIF_REG_ve_ctrl_haltve(data)                                       (0x00000008&((data)<<3))
#define  LGCY_RIF_REG_ve_ctrl_veidle(data)                                       (0x00000004&((data)<<2))
#define  LGCY_RIF_REG_ve_ctrl_inten(data)                                        (0x00000002&((data)<<1))
#define  LGCY_RIF_REG_ve_ctrl_reset_ptr(data)                                    (0x00000001&(data))
#define  LGCY_RIF_REG_ve_ctrl_get_ve_fpga_reset(data)                            ((0x20000000&(data))>>29)
#define  LGCY_RIF_REG_ve_ctrl_get_dbg_out_sel1(data)                             ((0x07C00000&(data))>>22)
#define  LGCY_RIF_REG_ve_ctrl_get_dbg_out_sel0(data)                             ((0x003E0000&(data))>>17)
#define  LGCY_RIF_REG_ve_ctrl_get_dbg_out_en(data)                               ((0x00010000&(data))>>16)
#define  LGCY_RIF_REG_ve_ctrl_get_encode_en(data)                                ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_ve_ctrl_get_ve_soft_reset(data)                            ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_ve_ctrl_get_vm_idle(data)                                  ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_ve_ctrl_get_decode_en(data)                                ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_ve_ctrl_get_haltve_done(data)                              ((0x00000010&(data))>>4)
#define  LGCY_RIF_REG_ve_ctrl_get_haltve(data)                                   ((0x00000008&(data))>>3)
#define  LGCY_RIF_REG_ve_ctrl_get_veidle(data)                                   ((0x00000004&(data))>>2)
#define  LGCY_RIF_REG_ve_ctrl_get_inten(data)                                    ((0x00000002&(data))>>1)
#define  LGCY_RIF_REG_ve_ctrl_get_reset_ptr(data)                                (0x00000001&(data))

#define  LGCY_RIF_REG_ve_int_status                                              0x1800E404
#define  LGCY_RIF_REG_ve_int_status_reg_addr                                     "0xB800E404"
#define  LGCY_RIF_REG_ve_int_status_reg                                          0xB800E404
#define  LGCY_RIF_REG_ve_int_status_inst_addr                                    "0x0001"
#define  set_LGCY_RIF_REG_ve_int_status_reg(data)                                (*((volatile unsigned int*)LGCY_RIF_REG_ve_int_status_reg)=data)
#define  get_LGCY_RIF_REG_ve_int_status_reg                                      (*((volatile unsigned int*)LGCY_RIF_REG_ve_int_status_reg))
#define  LGCY_RIF_REG_ve_int_status_first_error_b4_shift                         (28)
#define  LGCY_RIF_REG_ve_int_status_first_error_b3_shift                         (27)
#define  LGCY_RIF_REG_ve_int_status_first_error_b2_shift                         (26)
#define  LGCY_RIF_REG_ve_int_status_first_error_b1_shift                         (25)
#define  LGCY_RIF_REG_ve_int_status_first_error_b0_shift                         (24)
#define  LGCY_RIF_REG_ve_int_status_dcomp_core_irq_shift                         (22)
#define  LGCY_RIF_REG_ve_int_status_comp_core_irq_shift                          (21)
#define  LGCY_RIF_REG_ve_int_status_hevc_p3_hang_int_shift                       (20)
#define  LGCY_RIF_REG_ve_int_status_hevc_dec_done_int_shift                      (19)
#define  LGCY_RIF_REG_ve_int_status_ime_int_shift                                (18)
#define  LGCY_RIF_REG_ve_int_status_ipmd_err_shift                               (17)
#define  LGCY_RIF_REG_ve_int_status_gc_err_shift                                 (16)
#define  LGCY_RIF_REG_ve_int_status_cmd_fifo_full_int_shift                      (15)
#define  LGCY_RIF_REG_ve_int_status_rd_rslt_hang_int_shift                       (14)
#define  LGCY_RIF_REG_ve_int_status_rl_hang_int_shift                            (13)
#define  LGCY_RIF_REG_ve_int_status_pred_hang_int_shift                          (12)
#define  LGCY_RIF_REG_ve_int_status_mb_last_int_shift                            (11)
#define  LGCY_RIF_REG_ve_int_status_mvd_vc1_intfd_err_shift                      (10)
#define  LGCY_RIF_REG_ve_int_status_mvd_h264_direct_err_shift                    (9)
#define  LGCY_RIF_REG_ve_int_status_mvd_h264_mv_err_shift                        (8)
#define  LGCY_RIF_REG_ve_int_status_bs2_fifo_err_shift                           (7)
#define  LGCY_RIF_REG_ve_int_status_m64coeff_shift                               (6)
#define  LGCY_RIF_REG_ve_int_status_rstff_oflow_shift                            (5)
#define  LGCY_RIF_REG_ve_int_status_rstff_empty_shift                            (4)
#define  LGCY_RIF_REG_ve_int_status_bitst_fifo_shift                             (3)
#define  LGCY_RIF_REG_ve_int_status_scode_limit_shift                            (2)
#define  LGCY_RIF_REG_ve_int_status_dec_err_shift                                (1)
#define  LGCY_RIF_REG_ve_int_status_write_data_shift                             (0)
#define  LGCY_RIF_REG_ve_int_status_first_error_b4_mask                          (0x10000000)
#define  LGCY_RIF_REG_ve_int_status_first_error_b3_mask                          (0x08000000)
#define  LGCY_RIF_REG_ve_int_status_first_error_b2_mask                          (0x04000000)
#define  LGCY_RIF_REG_ve_int_status_first_error_b1_mask                          (0x02000000)
#define  LGCY_RIF_REG_ve_int_status_first_error_b0_mask                          (0x01000000)
#define  LGCY_RIF_REG_ve_int_status_dcomp_core_irq_mask                          (0x00400000)
#define  LGCY_RIF_REG_ve_int_status_comp_core_irq_mask                           (0x00200000)
#define  LGCY_RIF_REG_ve_int_status_hevc_p3_hang_int_mask                        (0x00100000)
#define  LGCY_RIF_REG_ve_int_status_hevc_dec_done_int_mask                       (0x00080000)
#define  LGCY_RIF_REG_ve_int_status_ime_int_mask                                 (0x00040000)
#define  LGCY_RIF_REG_ve_int_status_ipmd_err_mask                                (0x00020000)
#define  LGCY_RIF_REG_ve_int_status_gc_err_mask                                  (0x00010000)
#define  LGCY_RIF_REG_ve_int_status_cmd_fifo_full_int_mask                       (0x00008000)
#define  LGCY_RIF_REG_ve_int_status_rd_rslt_hang_int_mask                        (0x00004000)
#define  LGCY_RIF_REG_ve_int_status_rl_hang_int_mask                             (0x00002000)
#define  LGCY_RIF_REG_ve_int_status_pred_hang_int_mask                           (0x00001000)
#define  LGCY_RIF_REG_ve_int_status_mb_last_int_mask                             (0x00000800)
#define  LGCY_RIF_REG_ve_int_status_mvd_vc1_intfd_err_mask                       (0x00000400)
#define  LGCY_RIF_REG_ve_int_status_mvd_h264_direct_err_mask                     (0x00000200)
#define  LGCY_RIF_REG_ve_int_status_mvd_h264_mv_err_mask                         (0x00000100)
#define  LGCY_RIF_REG_ve_int_status_bs2_fifo_err_mask                            (0x00000080)
#define  LGCY_RIF_REG_ve_int_status_m64coeff_mask                                (0x00000040)
#define  LGCY_RIF_REG_ve_int_status_rstff_oflow_mask                             (0x00000020)
#define  LGCY_RIF_REG_ve_int_status_rstff_empty_mask                             (0x00000010)
#define  LGCY_RIF_REG_ve_int_status_bitst_fifo_mask                              (0x00000008)
#define  LGCY_RIF_REG_ve_int_status_scode_limit_mask                             (0x00000004)
#define  LGCY_RIF_REG_ve_int_status_dec_err_mask                                 (0x00000002)
#define  LGCY_RIF_REG_ve_int_status_write_data_mask                              (0x00000001)
#define  LGCY_RIF_REG_ve_int_status_first_error_b4(data)                         (0x10000000&((data)<<28))
#define  LGCY_RIF_REG_ve_int_status_first_error_b3(data)                         (0x08000000&((data)<<27))
#define  LGCY_RIF_REG_ve_int_status_first_error_b2(data)                         (0x04000000&((data)<<26))
#define  LGCY_RIF_REG_ve_int_status_first_error_b1(data)                         (0x02000000&((data)<<25))
#define  LGCY_RIF_REG_ve_int_status_first_error_b0(data)                         (0x01000000&((data)<<24))
#define  LGCY_RIF_REG_ve_int_status_dcomp_core_irq(data)                         (0x00400000&((data)<<22))
#define  LGCY_RIF_REG_ve_int_status_comp_core_irq(data)                          (0x00200000&((data)<<21))
#define  LGCY_RIF_REG_ve_int_status_hevc_p3_hang_int(data)                       (0x00100000&((data)<<20))
#define  LGCY_RIF_REG_ve_int_status_hevc_dec_done_int(data)                      (0x00080000&((data)<<19))
#define  LGCY_RIF_REG_ve_int_status_ime_int(data)                                (0x00040000&((data)<<18))
#define  LGCY_RIF_REG_ve_int_status_ipmd_err(data)                               (0x00020000&((data)<<17))
#define  LGCY_RIF_REG_ve_int_status_gc_err(data)                                 (0x00010000&((data)<<16))
#define  LGCY_RIF_REG_ve_int_status_cmd_fifo_full_int(data)                      (0x00008000&((data)<<15))
#define  LGCY_RIF_REG_ve_int_status_rd_rslt_hang_int(data)                       (0x00004000&((data)<<14))
#define  LGCY_RIF_REG_ve_int_status_rl_hang_int(data)                            (0x00002000&((data)<<13))
#define  LGCY_RIF_REG_ve_int_status_pred_hang_int(data)                          (0x00001000&((data)<<12))
#define  LGCY_RIF_REG_ve_int_status_mb_last_int(data)                            (0x00000800&((data)<<11))
#define  LGCY_RIF_REG_ve_int_status_mvd_vc1_intfd_err(data)                      (0x00000400&((data)<<10))
#define  LGCY_RIF_REG_ve_int_status_mvd_h264_direct_err(data)                    (0x00000200&((data)<<9))
#define  LGCY_RIF_REG_ve_int_status_mvd_h264_mv_err(data)                        (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_ve_int_status_bs2_fifo_err(data)                           (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_ve_int_status_m64coeff(data)                               (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_ve_int_status_rstff_oflow(data)                            (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_ve_int_status_rstff_empty(data)                            (0x00000010&((data)<<4))
#define  LGCY_RIF_REG_ve_int_status_bitst_fifo(data)                             (0x00000008&((data)<<3))
#define  LGCY_RIF_REG_ve_int_status_scode_limit(data)                            (0x00000004&((data)<<2))
#define  LGCY_RIF_REG_ve_int_status_dec_err(data)                                (0x00000002&((data)<<1))
#define  LGCY_RIF_REG_ve_int_status_write_data(data)                             (0x00000001&(data))
#define  LGCY_RIF_REG_ve_int_status_get_first_error_b4(data)                     ((0x10000000&(data))>>28)
#define  LGCY_RIF_REG_ve_int_status_get_first_error_b3(data)                     ((0x08000000&(data))>>27)
#define  LGCY_RIF_REG_ve_int_status_get_first_error_b2(data)                     ((0x04000000&(data))>>26)
#define  LGCY_RIF_REG_ve_int_status_get_first_error_b1(data)                     ((0x02000000&(data))>>25)
#define  LGCY_RIF_REG_ve_int_status_get_first_error_b0(data)                     ((0x01000000&(data))>>24)
#define  LGCY_RIF_REG_ve_int_status_get_dcomp_core_irq(data)                     ((0x00400000&(data))>>22)
#define  LGCY_RIF_REG_ve_int_status_get_comp_core_irq(data)                      ((0x00200000&(data))>>21)
#define  LGCY_RIF_REG_ve_int_status_get_hevc_p3_hang_int(data)                   ((0x00100000&(data))>>20)
#define  LGCY_RIF_REG_ve_int_status_get_hevc_dec_done_int(data)                  ((0x00080000&(data))>>19)
#define  LGCY_RIF_REG_ve_int_status_get_ime_int(data)                            ((0x00040000&(data))>>18)
#define  LGCY_RIF_REG_ve_int_status_get_ipmd_err(data)                           ((0x00020000&(data))>>17)
#define  LGCY_RIF_REG_ve_int_status_get_gc_err(data)                             ((0x00010000&(data))>>16)
#define  LGCY_RIF_REG_ve_int_status_get_cmd_fifo_full_int(data)                  ((0x00008000&(data))>>15)
#define  LGCY_RIF_REG_ve_int_status_get_rd_rslt_hang_int(data)                   ((0x00004000&(data))>>14)
#define  LGCY_RIF_REG_ve_int_status_get_rl_hang_int(data)                        ((0x00002000&(data))>>13)
#define  LGCY_RIF_REG_ve_int_status_get_pred_hang_int(data)                      ((0x00001000&(data))>>12)
#define  LGCY_RIF_REG_ve_int_status_get_mb_last_int(data)                        ((0x00000800&(data))>>11)
#define  LGCY_RIF_REG_ve_int_status_get_mvd_vc1_intfd_err(data)                  ((0x00000400&(data))>>10)
#define  LGCY_RIF_REG_ve_int_status_get_mvd_h264_direct_err(data)                ((0x00000200&(data))>>9)
#define  LGCY_RIF_REG_ve_int_status_get_mvd_h264_mv_err(data)                    ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_ve_int_status_get_bs2_fifo_err(data)                       ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_ve_int_status_get_m64coeff(data)                           ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_ve_int_status_get_rstff_oflow(data)                        ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_ve_int_status_get_rstff_empty(data)                        ((0x00000010&(data))>>4)
#define  LGCY_RIF_REG_ve_int_status_get_bitst_fifo(data)                         ((0x00000008&(data))>>3)
#define  LGCY_RIF_REG_ve_int_status_get_scode_limit(data)                        ((0x00000004&(data))>>2)
#define  LGCY_RIF_REG_ve_int_status_get_dec_err(data)                            ((0x00000002&(data))>>1)
#define  LGCY_RIF_REG_ve_int_status_get_write_data(data)                         (0x00000001&(data))

#define  LGCY_RIF_REG_ve_int_en                                                  0x1800E408
#define  LGCY_RIF_REG_ve_int_en_reg_addr                                         "0xB800E408"
#define  LGCY_RIF_REG_ve_int_en_reg                                              0xB800E408
#define  LGCY_RIF_REG_ve_int_en_inst_addr                                        "0x0002"
#define  set_LGCY_RIF_REG_ve_int_en_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_ve_int_en_reg)=data)
#define  get_LGCY_RIF_REG_ve_int_en_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_ve_int_en_reg))
#define  LGCY_RIF_REG_ve_int_en_dcomp_core_irq_ie_shift                          (24)
#define  LGCY_RIF_REG_ve_int_en_comp_core_irq_ie_shift                           (23)
#define  LGCY_RIF_REG_ve_int_en_hevc_p3_hang_int_ie_shift                        (22)
#define  LGCY_RIF_REG_ve_int_en_hevc_dec_done_int_ie_shift                       (21)
#define  LGCY_RIF_REG_ve_int_en_gc_interrupt_on_shift                            (20)
#define  LGCY_RIF_REG_ve_int_en_ipmd_interrupt_on_shift                          (19)
#define  LGCY_RIF_REG_ve_int_en_ime_int_ie_shift                                 (18)
#define  LGCY_RIF_REG_ve_int_en_ipmd_err_ie_shift                                (17)
#define  LGCY_RIF_REG_ve_int_en_gc_err_ie_shift                                  (16)
#define  LGCY_RIF_REG_ve_int_en_cmd_fifo_full_int_ie_shift                       (15)
#define  LGCY_RIF_REG_ve_int_en_rd_rslt_hang_int_ie_shift                        (14)
#define  LGCY_RIF_REG_ve_int_en_rl_hang_int_ie_shift                             (13)
#define  LGCY_RIF_REG_ve_int_en_pred_hang_int_ie_shift                           (12)
#define  LGCY_RIF_REG_ve_int_en_mb_last_int_ie_shift                             (11)
#define  LGCY_RIF_REG_ve_int_en_mvd_vc1_intfd_ie_shift                           (10)
#define  LGCY_RIF_REG_ve_int_en_mvd_h264_direct_ie_shift                         (9)
#define  LGCY_RIF_REG_ve_int_en_mvd_h264_mv_ie_shift                             (8)
#define  LGCY_RIF_REG_ve_int_en_bs2_fifo_err_ie_shift                            (7)
#define  LGCY_RIF_REG_ve_int_en_m64coeff_ie_shift                                (6)
#define  LGCY_RIF_REG_ve_int_en_rstff_oflow_ie_shift                             (5)
#define  LGCY_RIF_REG_ve_int_en_rstff_empty_ie_shift                             (4)
#define  LGCY_RIF_REG_ve_int_en_bitst_fifo_ie_shift                              (3)
#define  LGCY_RIF_REG_ve_int_en_scode_limit_ie_shift                             (2)
#define  LGCY_RIF_REG_ve_int_en_dec_err_ie_shift                                 (1)
#define  LGCY_RIF_REG_ve_int_en_write_data_shift                                 (0)
#define  LGCY_RIF_REG_ve_int_en_dcomp_core_irq_ie_mask                           (0x01000000)
#define  LGCY_RIF_REG_ve_int_en_comp_core_irq_ie_mask                            (0x00800000)
#define  LGCY_RIF_REG_ve_int_en_hevc_p3_hang_int_ie_mask                         (0x00400000)
#define  LGCY_RIF_REG_ve_int_en_hevc_dec_done_int_ie_mask                        (0x00200000)
#define  LGCY_RIF_REG_ve_int_en_gc_interrupt_on_mask                             (0x00100000)
#define  LGCY_RIF_REG_ve_int_en_ipmd_interrupt_on_mask                           (0x00080000)
#define  LGCY_RIF_REG_ve_int_en_ime_int_ie_mask                                  (0x00040000)
#define  LGCY_RIF_REG_ve_int_en_ipmd_err_ie_mask                                 (0x00020000)
#define  LGCY_RIF_REG_ve_int_en_gc_err_ie_mask                                   (0x00010000)
#define  LGCY_RIF_REG_ve_int_en_cmd_fifo_full_int_ie_mask                        (0x00008000)
#define  LGCY_RIF_REG_ve_int_en_rd_rslt_hang_int_ie_mask                         (0x00004000)
#define  LGCY_RIF_REG_ve_int_en_rl_hang_int_ie_mask                              (0x00002000)
#define  LGCY_RIF_REG_ve_int_en_pred_hang_int_ie_mask                            (0x00001000)
#define  LGCY_RIF_REG_ve_int_en_mb_last_int_ie_mask                              (0x00000800)
#define  LGCY_RIF_REG_ve_int_en_mvd_vc1_intfd_ie_mask                            (0x00000400)
#define  LGCY_RIF_REG_ve_int_en_mvd_h264_direct_ie_mask                          (0x00000200)
#define  LGCY_RIF_REG_ve_int_en_mvd_h264_mv_ie_mask                              (0x00000100)
#define  LGCY_RIF_REG_ve_int_en_bs2_fifo_err_ie_mask                             (0x00000080)
#define  LGCY_RIF_REG_ve_int_en_m64coeff_ie_mask                                 (0x00000040)
#define  LGCY_RIF_REG_ve_int_en_rstff_oflow_ie_mask                              (0x00000020)
#define  LGCY_RIF_REG_ve_int_en_rstff_empty_ie_mask                              (0x00000010)
#define  LGCY_RIF_REG_ve_int_en_bitst_fifo_ie_mask                               (0x00000008)
#define  LGCY_RIF_REG_ve_int_en_scode_limit_ie_mask                              (0x00000004)
#define  LGCY_RIF_REG_ve_int_en_dec_err_ie_mask                                  (0x00000002)
#define  LGCY_RIF_REG_ve_int_en_write_data_mask                                  (0x00000001)
#define  LGCY_RIF_REG_ve_int_en_dcomp_core_irq_ie(data)                          (0x01000000&((data)<<24))
#define  LGCY_RIF_REG_ve_int_en_comp_core_irq_ie(data)                           (0x00800000&((data)<<23))
#define  LGCY_RIF_REG_ve_int_en_hevc_p3_hang_int_ie(data)                        (0x00400000&((data)<<22))
#define  LGCY_RIF_REG_ve_int_en_hevc_dec_done_int_ie(data)                       (0x00200000&((data)<<21))
#define  LGCY_RIF_REG_ve_int_en_gc_interrupt_on(data)                            (0x00100000&((data)<<20))
#define  LGCY_RIF_REG_ve_int_en_ipmd_interrupt_on(data)                          (0x00080000&((data)<<19))
#define  LGCY_RIF_REG_ve_int_en_ime_int_ie(data)                                 (0x00040000&((data)<<18))
#define  LGCY_RIF_REG_ve_int_en_ipmd_err_ie(data)                                (0x00020000&((data)<<17))
#define  LGCY_RIF_REG_ve_int_en_gc_err_ie(data)                                  (0x00010000&((data)<<16))
#define  LGCY_RIF_REG_ve_int_en_cmd_fifo_full_int_ie(data)                       (0x00008000&((data)<<15))
#define  LGCY_RIF_REG_ve_int_en_rd_rslt_hang_int_ie(data)                        (0x00004000&((data)<<14))
#define  LGCY_RIF_REG_ve_int_en_rl_hang_int_ie(data)                             (0x00002000&((data)<<13))
#define  LGCY_RIF_REG_ve_int_en_pred_hang_int_ie(data)                           (0x00001000&((data)<<12))
#define  LGCY_RIF_REG_ve_int_en_mb_last_int_ie(data)                             (0x00000800&((data)<<11))
#define  LGCY_RIF_REG_ve_int_en_mvd_vc1_intfd_ie(data)                           (0x00000400&((data)<<10))
#define  LGCY_RIF_REG_ve_int_en_mvd_h264_direct_ie(data)                         (0x00000200&((data)<<9))
#define  LGCY_RIF_REG_ve_int_en_mvd_h264_mv_ie(data)                             (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_ve_int_en_bs2_fifo_err_ie(data)                            (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_ve_int_en_m64coeff_ie(data)                                (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_ve_int_en_rstff_oflow_ie(data)                             (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_ve_int_en_rstff_empty_ie(data)                             (0x00000010&((data)<<4))
#define  LGCY_RIF_REG_ve_int_en_bitst_fifo_ie(data)                              (0x00000008&((data)<<3))
#define  LGCY_RIF_REG_ve_int_en_scode_limit_ie(data)                             (0x00000004&((data)<<2))
#define  LGCY_RIF_REG_ve_int_en_dec_err_ie(data)                                 (0x00000002&((data)<<1))
#define  LGCY_RIF_REG_ve_int_en_write_data(data)                                 (0x00000001&(data))
#define  LGCY_RIF_REG_ve_int_en_get_dcomp_core_irq_ie(data)                      ((0x01000000&(data))>>24)
#define  LGCY_RIF_REG_ve_int_en_get_comp_core_irq_ie(data)                       ((0x00800000&(data))>>23)
#define  LGCY_RIF_REG_ve_int_en_get_hevc_p3_hang_int_ie(data)                    ((0x00400000&(data))>>22)
#define  LGCY_RIF_REG_ve_int_en_get_hevc_dec_done_int_ie(data)                   ((0x00200000&(data))>>21)
#define  LGCY_RIF_REG_ve_int_en_get_gc_interrupt_on(data)                        ((0x00100000&(data))>>20)
#define  LGCY_RIF_REG_ve_int_en_get_ipmd_interrupt_on(data)                      ((0x00080000&(data))>>19)
#define  LGCY_RIF_REG_ve_int_en_get_ime_int_ie(data)                             ((0x00040000&(data))>>18)
#define  LGCY_RIF_REG_ve_int_en_get_ipmd_err_ie(data)                            ((0x00020000&(data))>>17)
#define  LGCY_RIF_REG_ve_int_en_get_gc_err_ie(data)                              ((0x00010000&(data))>>16)
#define  LGCY_RIF_REG_ve_int_en_get_cmd_fifo_full_int_ie(data)                   ((0x00008000&(data))>>15)
#define  LGCY_RIF_REG_ve_int_en_get_rd_rslt_hang_int_ie(data)                    ((0x00004000&(data))>>14)
#define  LGCY_RIF_REG_ve_int_en_get_rl_hang_int_ie(data)                         ((0x00002000&(data))>>13)
#define  LGCY_RIF_REG_ve_int_en_get_pred_hang_int_ie(data)                       ((0x00001000&(data))>>12)
#define  LGCY_RIF_REG_ve_int_en_get_mb_last_int_ie(data)                         ((0x00000800&(data))>>11)
#define  LGCY_RIF_REG_ve_int_en_get_mvd_vc1_intfd_ie(data)                       ((0x00000400&(data))>>10)
#define  LGCY_RIF_REG_ve_int_en_get_mvd_h264_direct_ie(data)                     ((0x00000200&(data))>>9)
#define  LGCY_RIF_REG_ve_int_en_get_mvd_h264_mv_ie(data)                         ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_ve_int_en_get_bs2_fifo_err_ie(data)                        ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_ve_int_en_get_m64coeff_ie(data)                            ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_ve_int_en_get_rstff_oflow_ie(data)                         ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_ve_int_en_get_rstff_empty_ie(data)                         ((0x00000010&(data))>>4)
#define  LGCY_RIF_REG_ve_int_en_get_bitst_fifo_ie(data)                          ((0x00000008&(data))>>3)
#define  LGCY_RIF_REG_ve_int_en_get_scode_limit_ie(data)                         ((0x00000004&(data))>>2)
#define  LGCY_RIF_REG_ve_int_en_get_dec_err_ie(data)                             ((0x00000002&(data))>>1)
#define  LGCY_RIF_REG_ve_int_en_get_write_data(data)                             (0x00000001&(data))

#define  LGCY_RIF_REG_ve_fifostatus                                              0x1800E410
#define  LGCY_RIF_REG_ve_fifostatus_reg_addr                                     "0xB800E410"
#define  LGCY_RIF_REG_ve_fifostatus_reg                                          0xB800E410
#define  LGCY_RIF_REG_ve_fifostatus_inst_addr                                    "0x0003"
#define  set_LGCY_RIF_REG_ve_fifostatus_reg(data)                                (*((volatile unsigned int*)LGCY_RIF_REG_ve_fifostatus_reg)=data)
#define  get_LGCY_RIF_REG_ve_fifostatus_reg                                      (*((volatile unsigned int*)LGCY_RIF_REG_ve_fifostatus_reg))
#define  LGCY_RIF_REG_ve_fifostatus_debk_inst_cnt_shift                          (24)
#define  LGCY_RIF_REG_ve_fifostatus_pred_inst_cnt_shift                          (16)
#define  LGCY_RIF_REG_ve_fifostatus_dmab_inst_cnt_shift                          (8)
#define  LGCY_RIF_REG_ve_fifostatus_dmaa_inst_cnt_shift                          (0)
#define  LGCY_RIF_REG_ve_fifostatus_debk_inst_cnt_mask                           (0x3F000000)
#define  LGCY_RIF_REG_ve_fifostatus_pred_inst_cnt_mask                           (0x003F0000)
#define  LGCY_RIF_REG_ve_fifostatus_dmab_inst_cnt_mask                           (0x00003F00)
#define  LGCY_RIF_REG_ve_fifostatus_dmaa_inst_cnt_mask                           (0x0000003F)
#define  LGCY_RIF_REG_ve_fifostatus_debk_inst_cnt(data)                          (0x3F000000&((data)<<24))
#define  LGCY_RIF_REG_ve_fifostatus_pred_inst_cnt(data)                          (0x003F0000&((data)<<16))
#define  LGCY_RIF_REG_ve_fifostatus_dmab_inst_cnt(data)                          (0x00003F00&((data)<<8))
#define  LGCY_RIF_REG_ve_fifostatus_dmaa_inst_cnt(data)                          (0x0000003F&(data))
#define  LGCY_RIF_REG_ve_fifostatus_get_debk_inst_cnt(data)                      ((0x3F000000&(data))>>24)
#define  LGCY_RIF_REG_ve_fifostatus_get_pred_inst_cnt(data)                      ((0x003F0000&(data))>>16)
#define  LGCY_RIF_REG_ve_fifostatus_get_dmab_inst_cnt(data)                      ((0x00003F00&(data))>>8)
#define  LGCY_RIF_REG_ve_fifostatus_get_dmaa_inst_cnt(data)                      (0x0000003F&(data))

#define  LGCY_RIF_REG_ve_fifostat2                                               0x1800E414
#define  LGCY_RIF_REG_ve_fifostat2_reg_addr                                      "0xB800E414"
#define  LGCY_RIF_REG_ve_fifostat2_reg                                           0xB800E414
#define  LGCY_RIF_REG_ve_fifostat2_inst_addr                                     "0x0004"
#define  set_LGCY_RIF_REG_ve_fifostat2_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_ve_fifostat2_reg)=data)
#define  get_LGCY_RIF_REG_ve_fifostat2_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_ve_fifostat2_reg))
#define  LGCY_RIF_REG_ve_fifostat2_act_rslt_in_fifo_shift                        (27)
#define  LGCY_RIF_REG_ve_fifostat2_rslt_fifo_cnt_shift                           (22)
#define  LGCY_RIF_REG_ve_fifostat2_img_fifo_cnt_shift                            (16)
#define  LGCY_RIF_REG_ve_fifostat2_dec_inst_cnt_shift                            (8)
#define  LGCY_RIF_REG_ve_fifostat2_act_rslt_in_fifo_mask                         (0xF8000000)
#define  LGCY_RIF_REG_ve_fifostat2_rslt_fifo_cnt_mask                            (0x07C00000)
#define  LGCY_RIF_REG_ve_fifostat2_img_fifo_cnt_mask                             (0x003F0000)
#define  LGCY_RIF_REG_ve_fifostat2_dec_inst_cnt_mask                             (0x00003F00)
#define  LGCY_RIF_REG_ve_fifostat2_act_rslt_in_fifo(data)                        (0xF8000000&((data)<<27))
#define  LGCY_RIF_REG_ve_fifostat2_rslt_fifo_cnt(data)                           (0x07C00000&((data)<<22))
#define  LGCY_RIF_REG_ve_fifostat2_img_fifo_cnt(data)                            (0x003F0000&((data)<<16))
#define  LGCY_RIF_REG_ve_fifostat2_dec_inst_cnt(data)                            (0x00003F00&((data)<<8))
#define  LGCY_RIF_REG_ve_fifostat2_get_act_rslt_in_fifo(data)                    ((0xF8000000&(data))>>27)
#define  LGCY_RIF_REG_ve_fifostat2_get_rslt_fifo_cnt(data)                       ((0x07C00000&(data))>>22)
#define  LGCY_RIF_REG_ve_fifostat2_get_img_fifo_cnt(data)                        ((0x003F0000&(data))>>16)
#define  LGCY_RIF_REG_ve_fifostat2_get_dec_inst_cnt(data)                        ((0x00003F00&(data))>>8)

#define  LGCY_RIF_REG_ve_rslt_timer                                              0x1800E418
#define  LGCY_RIF_REG_ve_rslt_timer_reg_addr                                     "0xB800E418"
#define  LGCY_RIF_REG_ve_rslt_timer_reg                                          0xB800E418
#define  LGCY_RIF_REG_ve_rslt_timer_inst_addr                                    "0x0005"
#define  set_LGCY_RIF_REG_ve_rslt_timer_reg(data)                                (*((volatile unsigned int*)LGCY_RIF_REG_ve_rslt_timer_reg)=data)
#define  get_LGCY_RIF_REG_ve_rslt_timer_reg                                      (*((volatile unsigned int*)LGCY_RIF_REG_ve_rslt_timer_reg))
#define  LGCY_RIF_REG_ve_rslt_timer_rslt_timer_shift                             (0)
#define  LGCY_RIF_REG_ve_rslt_timer_rslt_timer_mask                              (0x00FFFFFF)
#define  LGCY_RIF_REG_ve_rslt_timer_rslt_timer(data)                             (0x00FFFFFF&(data))
#define  LGCY_RIF_REG_ve_rslt_timer_get_rslt_timer(data)                         (0x00FFFFFF&(data))

#define  LGCY_RIF_REG_ve_cmd_timer                                               0x1800E41C
#define  LGCY_RIF_REG_ve_cmd_timer_reg_addr                                      "0xB800E41C"
#define  LGCY_RIF_REG_ve_cmd_timer_reg                                           0xB800E41C
#define  LGCY_RIF_REG_ve_cmd_timer_inst_addr                                     "0x0006"
#define  set_LGCY_RIF_REG_ve_cmd_timer_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_ve_cmd_timer_reg)=data)
#define  get_LGCY_RIF_REG_ve_cmd_timer_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_ve_cmd_timer_reg))
#define  LGCY_RIF_REG_ve_cmd_timer_cmd_timer_shift                               (0)
#define  LGCY_RIF_REG_ve_cmd_timer_cmd_timer_mask                                (0x00FFFFFF)
#define  LGCY_RIF_REG_ve_cmd_timer_cmd_timer(data)                               (0x00FFFFFF&(data))
#define  LGCY_RIF_REG_ve_cmd_timer_get_cmd_timer(data)                           (0x00FFFFFF&(data))

#define  LGCY_RIF_REG_ve_fifostat3                                               0x1800E424
#define  LGCY_RIF_REG_ve_fifostat3_reg_addr                                      "0xB800E424"
#define  LGCY_RIF_REG_ve_fifostat3_reg                                           0xB800E424
#define  LGCY_RIF_REG_ve_fifostat3_inst_addr                                     "0x0007"
#define  set_LGCY_RIF_REG_ve_fifostat3_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_ve_fifostat3_reg)=data)
#define  get_LGCY_RIF_REG_ve_fifostat3_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_ve_fifostat3_reg))
#define  LGCY_RIF_REG_ve_fifostat3_ime_inst_cnt_shift                            (8)
#define  LGCY_RIF_REG_ve_fifostat3_emd_inst_cnt_shift                            (0)
#define  LGCY_RIF_REG_ve_fifostat3_ime_inst_cnt_mask                             (0x00003F00)
#define  LGCY_RIF_REG_ve_fifostat3_emd_inst_cnt_mask                             (0x0000003F)
#define  LGCY_RIF_REG_ve_fifostat3_ime_inst_cnt(data)                            (0x00003F00&((data)<<8))
#define  LGCY_RIF_REG_ve_fifostat3_emd_inst_cnt(data)                            (0x0000003F&(data))
#define  LGCY_RIF_REG_ve_fifostat3_get_ime_inst_cnt(data)                        ((0x00003F00&(data))>>8)
#define  LGCY_RIF_REG_ve_fifostat3_get_emd_inst_cnt(data)                        (0x0000003F&(data))

#define  LGCY_RIF_REG_vmbanksel                                                  0x1800E420
#define  LGCY_RIF_REG_vmbanksel_reg_addr                                         "0xB800E420"
#define  LGCY_RIF_REG_vmbanksel_reg                                              0xB800E420
#define  LGCY_RIF_REG_vmbanksel_inst_addr                                        "0x0008"
#define  set_LGCY_RIF_REG_vmbanksel_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_vmbanksel_reg)=data)
#define  get_LGCY_RIF_REG_vmbanksel_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_vmbanksel_reg))
#define  LGCY_RIF_REG_vmbanksel_ve_cmprs_bnk_shift                               (20)
#define  LGCY_RIF_REG_vmbanksel_ve_img_bnk_shift                                 (16)
#define  LGCY_RIF_REG_vmbanksel_ve_deb_bnk_shift                                 (12)
#define  LGCY_RIF_REG_vmbanksel_ve_prd_bnk_shift                                 (8)
#define  LGCY_RIF_REG_vmbanksel_ve_dmab_bnk_shift                                (4)
#define  LGCY_RIF_REG_vmbanksel_ve_dmaa_bnk_shift                                (0)
#define  LGCY_RIF_REG_vmbanksel_ve_cmprs_bnk_mask                                (0x00700000)
#define  LGCY_RIF_REG_vmbanksel_ve_img_bnk_mask                                  (0x00070000)
#define  LGCY_RIF_REG_vmbanksel_ve_deb_bnk_mask                                  (0x00007000)
#define  LGCY_RIF_REG_vmbanksel_ve_prd_bnk_mask                                  (0x00000700)
#define  LGCY_RIF_REG_vmbanksel_ve_dmab_bnk_mask                                 (0x00000070)
#define  LGCY_RIF_REG_vmbanksel_ve_dmaa_bnk_mask                                 (0x00000007)
#define  LGCY_RIF_REG_vmbanksel_ve_cmprs_bnk(data)                               (0x00700000&((data)<<20))
#define  LGCY_RIF_REG_vmbanksel_ve_img_bnk(data)                                 (0x00070000&((data)<<16))
#define  LGCY_RIF_REG_vmbanksel_ve_deb_bnk(data)                                 (0x00007000&((data)<<12))
#define  LGCY_RIF_REG_vmbanksel_ve_prd_bnk(data)                                 (0x00000700&((data)<<8))
#define  LGCY_RIF_REG_vmbanksel_ve_dmab_bnk(data)                                (0x00000070&((data)<<4))
#define  LGCY_RIF_REG_vmbanksel_ve_dmaa_bnk(data)                                (0x00000007&(data))
#define  LGCY_RIF_REG_vmbanksel_get_ve_cmprs_bnk(data)                           ((0x00700000&(data))>>20)
#define  LGCY_RIF_REG_vmbanksel_get_ve_img_bnk(data)                             ((0x00070000&(data))>>16)
#define  LGCY_RIF_REG_vmbanksel_get_ve_deb_bnk(data)                             ((0x00007000&(data))>>12)
#define  LGCY_RIF_REG_vmbanksel_get_ve_prd_bnk(data)                             ((0x00000700&(data))>>8)
#define  LGCY_RIF_REG_vmbanksel_get_ve_dmab_bnk(data)                            ((0x00000070&(data))>>4)
#define  LGCY_RIF_REG_vmbanksel_get_ve_dmaa_bnk(data)                            (0x00000007&(data))

#define  LGCY_RIF_REG_umbanksel                                                  0x1800E428
#define  LGCY_RIF_REG_umbanksel_reg_addr                                         "0xB800E428"
#define  LGCY_RIF_REG_umbanksel_reg                                              0xB800E428
#define  LGCY_RIF_REG_umbanksel_inst_addr                                        "0x0009"
#define  set_LGCY_RIF_REG_umbanksel_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_umbanksel_reg)=data)
#define  get_LGCY_RIF_REG_umbanksel_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_umbanksel_reg))
#define  LGCY_RIF_REG_umbanksel_ve_gcf_umbnk_shift                               (12)
#define  LGCY_RIF_REG_umbanksel_ve_emd_umbnk_shift                               (8)
#define  LGCY_RIF_REG_umbanksel_ve_ime_umbk_shift                                (4)
#define  LGCY_RIF_REG_umbanksel_ve_dma_umbnk_shift                               (0)
#define  LGCY_RIF_REG_umbanksel_ve_gcf_umbnk_mask                                (0x00003000)
#define  LGCY_RIF_REG_umbanksel_ve_emd_umbnk_mask                                (0x00000300)
#define  LGCY_RIF_REG_umbanksel_ve_ime_umbk_mask                                 (0x00000030)
#define  LGCY_RIF_REG_umbanksel_ve_dma_umbnk_mask                                (0x00000003)
#define  LGCY_RIF_REG_umbanksel_ve_gcf_umbnk(data)                               (0x00003000&((data)<<12))
#define  LGCY_RIF_REG_umbanksel_ve_emd_umbnk(data)                               (0x00000300&((data)<<8))
#define  LGCY_RIF_REG_umbanksel_ve_ime_umbk(data)                                (0x00000030&((data)<<4))
#define  LGCY_RIF_REG_umbanksel_ve_dma_umbnk(data)                               (0x00000003&(data))
#define  LGCY_RIF_REG_umbanksel_get_ve_gcf_umbnk(data)                           ((0x00003000&(data))>>12)
#define  LGCY_RIF_REG_umbanksel_get_ve_emd_umbnk(data)                           ((0x00000300&(data))>>8)
#define  LGCY_RIF_REG_umbanksel_get_ve_ime_umbk(data)                            ((0x00000030&(data))>>4)
#define  LGCY_RIF_REG_umbanksel_get_ve_dma_umbnk(data)                           (0x00000003&(data))

#define  LGCY_RIF_REG_dec_cntl                                                   0x1800E450
#define  LGCY_RIF_REG_dec_cntl_reg_addr                                          "0xB800E450"
#define  LGCY_RIF_REG_dec_cntl_reg                                               0xB800E450
#define  LGCY_RIF_REG_dec_cntl_inst_addr                                         "0x000A"
#define  set_LGCY_RIF_REG_dec_cntl_reg(data)                                     (*((volatile unsigned int*)LGCY_RIF_REG_dec_cntl_reg)=data)
#define  get_LGCY_RIF_REG_dec_cntl_reg                                           (*((volatile unsigned int*)LGCY_RIF_REG_dec_cntl_reg))
#define  LGCY_RIF_REG_dec_cntl_cmprs_head_remap_shift                            (29)
#define  LGCY_RIF_REG_dec_cntl_mode32x1_shift                                    (28)
#define  LGCY_RIF_REG_dec_cntl_gpu_out_en_shift                                  (27)
#define  LGCY_RIF_REG_dec_cntl_dual_core_dmy_row_method_shift                    (26)
#define  LGCY_RIF_REG_dec_cntl_comp_wrap_width_shift                             (16)
#define  LGCY_RIF_REG_dec_cntl_compression_en_shift                              (15)
#define  LGCY_RIF_REG_dec_cntl_multicoreenable_shift                             (13)
#define  LGCY_RIF_REG_dec_cntl_corenum_shift                                     (11)
#define  LGCY_RIF_REG_dec_cntl_mode8x2_16b_align_shift                           (10)
#define  LGCY_RIF_REG_dec_cntl_mode8x2_shift                                     (9)
#define  LGCY_RIF_REG_dec_cntl_monochrome_shift                                  (8)
#define  LGCY_RIF_REG_dec_cntl_level_shift                                       (7)
#define  LGCY_RIF_REG_dec_cntl_profile_shift                                     (5)
#define  LGCY_RIF_REG_dec_cntl_coding_type_shift                                 (0)
#define  LGCY_RIF_REG_dec_cntl_cmprs_head_remap_mask                             (0x20000000)
#define  LGCY_RIF_REG_dec_cntl_mode32x1_mask                                     (0x10000000)
#define  LGCY_RIF_REG_dec_cntl_gpu_out_en_mask                                   (0x08000000)
#define  LGCY_RIF_REG_dec_cntl_dual_core_dmy_row_method_mask                     (0x04000000)
#define  LGCY_RIF_REG_dec_cntl_comp_wrap_width_mask                              (0x03FF0000)
#define  LGCY_RIF_REG_dec_cntl_compression_en_mask                               (0x00008000)
#define  LGCY_RIF_REG_dec_cntl_multicoreenable_mask                              (0x00006000)
#define  LGCY_RIF_REG_dec_cntl_corenum_mask                                      (0x00001800)
#define  LGCY_RIF_REG_dec_cntl_mode8x2_16b_align_mask                            (0x00000400)
#define  LGCY_RIF_REG_dec_cntl_mode8x2_mask                                      (0x00000200)
#define  LGCY_RIF_REG_dec_cntl_monochrome_mask                                   (0x00000100)
#define  LGCY_RIF_REG_dec_cntl_level_mask                                        (0x00000080)
#define  LGCY_RIF_REG_dec_cntl_profile_mask                                      (0x00000060)
#define  LGCY_RIF_REG_dec_cntl_coding_type_mask                                  (0x0000001F)
#define  LGCY_RIF_REG_dec_cntl_cmprs_head_remap(data)                            (0x20000000&((data)<<29))
#define  LGCY_RIF_REG_dec_cntl_mode32x1(data)                                    (0x10000000&((data)<<28))
#define  LGCY_RIF_REG_dec_cntl_gpu_out_en(data)                                  (0x08000000&((data)<<27))
#define  LGCY_RIF_REG_dec_cntl_dual_core_dmy_row_method(data)                    (0x04000000&((data)<<26))
#define  LGCY_RIF_REG_dec_cntl_comp_wrap_width(data)                             (0x03FF0000&((data)<<16))
#define  LGCY_RIF_REG_dec_cntl_compression_en(data)                              (0x00008000&((data)<<15))
#define  LGCY_RIF_REG_dec_cntl_multicoreenable(data)                             (0x00006000&((data)<<13))
#define  LGCY_RIF_REG_dec_cntl_corenum(data)                                     (0x00001800&((data)<<11))
#define  LGCY_RIF_REG_dec_cntl_mode8x2_16b_align(data)                           (0x00000400&((data)<<10))
#define  LGCY_RIF_REG_dec_cntl_mode8x2(data)                                     (0x00000200&((data)<<9))
#define  LGCY_RIF_REG_dec_cntl_monochrome(data)                                  (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_dec_cntl_level(data)                                       (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_dec_cntl_profile(data)                                     (0x00000060&((data)<<5))
#define  LGCY_RIF_REG_dec_cntl_coding_type(data)                                 (0x0000001F&(data))
#define  LGCY_RIF_REG_dec_cntl_get_cmprs_head_remap(data)                        ((0x20000000&(data))>>29)
#define  LGCY_RIF_REG_dec_cntl_get_mode32x1(data)                                ((0x10000000&(data))>>28)
#define  LGCY_RIF_REG_dec_cntl_get_gpu_out_en(data)                              ((0x08000000&(data))>>27)
#define  LGCY_RIF_REG_dec_cntl_get_dual_core_dmy_row_method(data)                ((0x04000000&(data))>>26)
#define  LGCY_RIF_REG_dec_cntl_get_comp_wrap_width(data)                         ((0x03FF0000&(data))>>16)
#define  LGCY_RIF_REG_dec_cntl_get_compression_en(data)                          ((0x00008000&(data))>>15)
#define  LGCY_RIF_REG_dec_cntl_get_multicoreenable(data)                         ((0x00006000&(data))>>13)
#define  LGCY_RIF_REG_dec_cntl_get_corenum(data)                                 ((0x00001800&(data))>>11)
#define  LGCY_RIF_REG_dec_cntl_get_mode8x2_16b_align(data)                       ((0x00000400&(data))>>10)
#define  LGCY_RIF_REG_dec_cntl_get_mode8x2(data)                                 ((0x00000200&(data))>>9)
#define  LGCY_RIF_REG_dec_cntl_get_monochrome(data)                              ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_dec_cntl_get_level(data)                                   ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_dec_cntl_get_profile(data)                                 ((0x00000060&(data))>>5)
#define  LGCY_RIF_REG_dec_cntl_get_coding_type(data)                             (0x0000001F&(data))

#define  LGCY_RIF_REG_picinfo1                                                   0x1800E454
#define  LGCY_RIF_REG_picinfo1_reg_addr                                          "0xB800E454"
#define  LGCY_RIF_REG_picinfo1_reg                                               0xB800E454
#define  LGCY_RIF_REG_picinfo1_inst_addr                                         "0x000B"
#define  set_LGCY_RIF_REG_picinfo1_reg(data)                                     (*((volatile unsigned int*)LGCY_RIF_REG_picinfo1_reg)=data)
#define  get_LGCY_RIF_REG_picinfo1_reg                                           (*((volatile unsigned int*)LGCY_RIF_REG_picinfo1_reg))
#define  LGCY_RIF_REG_picinfo1_filter_level_shift                                (24)
#define  LGCY_RIF_REG_picinfo1_allow_high_precision_mv_shift                     (23)
#define  LGCY_RIF_REG_picinfo1_vp9_seg_en_shift                                  (22)
#define  LGCY_RIF_REG_picinfo1_vp8_bicubic_filtering_shift                       (21)
#define  LGCY_RIF_REG_picinfo1_bottom_field_flag_shift                           (20)
#define  LGCY_RIF_REG_picinfo1_field_pic_flag_shift                              (19)
#define  LGCY_RIF_REG_picinfo1_picmb_h_shift                                     (10)
#define  LGCY_RIF_REG_picinfo1_picmb_w_shift                                     (0)
#define  LGCY_RIF_REG_picinfo1_filter_level_mask                                 (0x3F000000)
#define  LGCY_RIF_REG_picinfo1_allow_high_precision_mv_mask                      (0x00800000)
#define  LGCY_RIF_REG_picinfo1_vp9_seg_en_mask                                   (0x00400000)
#define  LGCY_RIF_REG_picinfo1_vp8_bicubic_filtering_mask                        (0x00200000)
#define  LGCY_RIF_REG_picinfo1_bottom_field_flag_mask                            (0x00100000)
#define  LGCY_RIF_REG_picinfo1_field_pic_flag_mask                               (0x00080000)
#define  LGCY_RIF_REG_picinfo1_picmb_h_mask                                      (0x0007FC00)
#define  LGCY_RIF_REG_picinfo1_picmb_w_mask                                      (0x000003FF)
#define  LGCY_RIF_REG_picinfo1_filter_level(data)                                (0x3F000000&((data)<<24))
#define  LGCY_RIF_REG_picinfo1_allow_high_precision_mv(data)                     (0x00800000&((data)<<23))
#define  LGCY_RIF_REG_picinfo1_vp9_seg_en(data)                                  (0x00400000&((data)<<22))
#define  LGCY_RIF_REG_picinfo1_vp8_bicubic_filtering(data)                       (0x00200000&((data)<<21))
#define  LGCY_RIF_REG_picinfo1_bottom_field_flag(data)                           (0x00100000&((data)<<20))
#define  LGCY_RIF_REG_picinfo1_field_pic_flag(data)                              (0x00080000&((data)<<19))
#define  LGCY_RIF_REG_picinfo1_picmb_h(data)                                     (0x0007FC00&((data)<<10))
#define  LGCY_RIF_REG_picinfo1_picmb_w(data)                                     (0x000003FF&(data))
#define  LGCY_RIF_REG_picinfo1_get_filter_level(data)                            ((0x3F000000&(data))>>24)
#define  LGCY_RIF_REG_picinfo1_get_allow_high_precision_mv(data)                 ((0x00800000&(data))>>23)
#define  LGCY_RIF_REG_picinfo1_get_vp9_seg_en(data)                              ((0x00400000&(data))>>22)
#define  LGCY_RIF_REG_picinfo1_get_vp8_bicubic_filtering(data)                   ((0x00200000&(data))>>21)
#define  LGCY_RIF_REG_picinfo1_get_bottom_field_flag(data)                       ((0x00100000&(data))>>20)
#define  LGCY_RIF_REG_picinfo1_get_field_pic_flag(data)                          ((0x00080000&(data))>>19)
#define  LGCY_RIF_REG_picinfo1_get_picmb_h(data)                                 ((0x0007FC00&(data))>>10)
#define  LGCY_RIF_REG_picinfo1_get_picmb_w(data)                                 (0x000003FF&(data))

#define  LGCY_RIF_REG_h264piccntl                                                0x1800E460
#define  LGCY_RIF_REG_h264piccntl_reg_addr                                       "0xB800E460"
#define  LGCY_RIF_REG_h264piccntl_reg                                            0xB800E460
#define  LGCY_RIF_REG_h264piccntl_inst_addr                                      "0x000C"
#define  set_LGCY_RIF_REG_h264piccntl_reg(data)                                  (*((volatile unsigned int*)LGCY_RIF_REG_h264piccntl_reg)=data)
#define  get_LGCY_RIF_REG_h264piccntl_reg                                        (*((volatile unsigned int*)LGCY_RIF_REG_h264piccntl_reg))
#define  LGCY_RIF_REG_h264piccntl_mode16x1_shift                                 (6)
#define  LGCY_RIF_REG_h264piccntl_constrainted_intra_pred_flag_shift             (5)
#define  LGCY_RIF_REG_h264piccntl_weighted_pred_flag_shift                       (4)
#define  LGCY_RIF_REG_h264piccntl_weighted_bipred_idc_shift                      (2)
#define  LGCY_RIF_REG_h264piccntl_frame_mbs_only_flag_shift                      (1)
#define  LGCY_RIF_REG_h264piccntl_mb_adaptive_frame_field_flag_shift             (0)
#define  LGCY_RIF_REG_h264piccntl_mode16x1_mask                                  (0x00000040)
#define  LGCY_RIF_REG_h264piccntl_constrainted_intra_pred_flag_mask              (0x00000020)
#define  LGCY_RIF_REG_h264piccntl_weighted_pred_flag_mask                        (0x00000010)
#define  LGCY_RIF_REG_h264piccntl_weighted_bipred_idc_mask                       (0x0000000C)
#define  LGCY_RIF_REG_h264piccntl_frame_mbs_only_flag_mask                       (0x00000002)
#define  LGCY_RIF_REG_h264piccntl_mb_adaptive_frame_field_flag_mask              (0x00000001)
#define  LGCY_RIF_REG_h264piccntl_mode16x1(data)                                 (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_h264piccntl_constrainted_intra_pred_flag(data)             (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_h264piccntl_weighted_pred_flag(data)                       (0x00000010&((data)<<4))
#define  LGCY_RIF_REG_h264piccntl_weighted_bipred_idc(data)                      (0x0000000C&((data)<<2))
#define  LGCY_RIF_REG_h264piccntl_frame_mbs_only_flag(data)                      (0x00000002&((data)<<1))
#define  LGCY_RIF_REG_h264piccntl_mb_adaptive_frame_field_flag(data)             (0x00000001&(data))
#define  LGCY_RIF_REG_h264piccntl_get_mode16x1(data)                             ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_h264piccntl_get_constrainted_intra_pred_flag(data)         ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_h264piccntl_get_weighted_pred_flag(data)                   ((0x00000010&(data))>>4)
#define  LGCY_RIF_REG_h264piccntl_get_weighted_bipred_idc(data)                  ((0x0000000C&(data))>>2)
#define  LGCY_RIF_REG_h264piccntl_get_frame_mbs_only_flag(data)                  ((0x00000002&(data))>>1)
#define  LGCY_RIF_REG_h264piccntl_get_mb_adaptive_frame_field_flag(data)         (0x00000001&(data))

#define  LGCY_RIF_REG_vc1piccntl                                                 0x1800E470
#define  LGCY_RIF_REG_vc1piccntl_reg_addr                                        "0xB800E470"
#define  LGCY_RIF_REG_vc1piccntl_reg                                             0xB800E470
#define  LGCY_RIF_REG_vc1piccntl_inst_addr                                       "0x000D"
#define  set_LGCY_RIF_REG_vc1piccntl_reg(data)                                   (*((volatile unsigned int*)LGCY_RIF_REG_vc1piccntl_reg)=data)
#define  get_LGCY_RIF_REG_vc1piccntl_reg                                         (*((volatile unsigned int*)LGCY_RIF_REG_vc1piccntl_reg))
#define  LGCY_RIF_REG_vc1piccntl_overlap_enable_shift                            (31)
#define  LGCY_RIF_REG_vc1piccntl_field_pictype_shift                             (28)
#define  LGCY_RIF_REG_vc1piccntl_mvmode_shift                                    (26)
#define  LGCY_RIF_REG_vc1piccntl_fcm_shift                                       (24)
#define  LGCY_RIF_REG_vc1piccntl_disppic_h_shift                                 (12)
#define  LGCY_RIF_REG_vc1piccntl_disppic_w_shift                                 (0)
#define  LGCY_RIF_REG_vc1piccntl_overlap_enable_mask                             (0x80000000)
#define  LGCY_RIF_REG_vc1piccntl_field_pictype_mask                              (0x70000000)
#define  LGCY_RIF_REG_vc1piccntl_mvmode_mask                                     (0x0C000000)
#define  LGCY_RIF_REG_vc1piccntl_fcm_mask                                        (0x03000000)
#define  LGCY_RIF_REG_vc1piccntl_disppic_h_mask                                  (0x00FFF000)
#define  LGCY_RIF_REG_vc1piccntl_disppic_w_mask                                  (0x00000FFF)
#define  LGCY_RIF_REG_vc1piccntl_overlap_enable(data)                            (0x80000000&((data)<<31))
#define  LGCY_RIF_REG_vc1piccntl_field_pictype(data)                             (0x70000000&((data)<<28))
#define  LGCY_RIF_REG_vc1piccntl_mvmode(data)                                    (0x0C000000&((data)<<26))
#define  LGCY_RIF_REG_vc1piccntl_fcm(data)                                       (0x03000000&((data)<<24))
#define  LGCY_RIF_REG_vc1piccntl_disppic_h(data)                                 (0x00FFF000&((data)<<12))
#define  LGCY_RIF_REG_vc1piccntl_disppic_w(data)                                 (0x00000FFF&(data))
#define  LGCY_RIF_REG_vc1piccntl_get_overlap_enable(data)                        ((0x80000000&(data))>>31)
#define  LGCY_RIF_REG_vc1piccntl_get_field_pictype(data)                         ((0x70000000&(data))>>28)
#define  LGCY_RIF_REG_vc1piccntl_get_mvmode(data)                                ((0x0C000000&(data))>>26)
#define  LGCY_RIF_REG_vc1piccntl_get_fcm(data)                                   ((0x03000000&(data))>>24)
#define  LGCY_RIF_REG_vc1piccntl_get_disppic_h(data)                             ((0x00FFF000&(data))>>12)
#define  LGCY_RIF_REG_vc1piccntl_get_disppic_w(data)                             (0x00000FFF&(data))

#define  LGCY_RIF_REG_vc1piccntl2                                                0x1800E474
#define  LGCY_RIF_REG_vc1piccntl2_reg_addr                                       "0xB800E474"
#define  LGCY_RIF_REG_vc1piccntl2_reg                                            0xB800E474
#define  LGCY_RIF_REG_vc1piccntl2_inst_addr                                      "0x000E"
#define  set_LGCY_RIF_REG_vc1piccntl2_reg(data)                                  (*((volatile unsigned int*)LGCY_RIF_REG_vc1piccntl2_reg)=data)
#define  get_LGCY_RIF_REG_vc1piccntl2_reg                                        (*((volatile unsigned int*)LGCY_RIF_REG_vc1piccntl2_reg))
#define  LGCY_RIF_REG_vc1piccntl2_wmv9_bug_rtmflag_shift                         (8)
#define  LGCY_RIF_REG_vc1piccntl2_wmv9_bug_it_shift                              (7)
#define  LGCY_RIF_REG_vc1piccntl2_loopfilter_shift                               (6)
#define  LGCY_RIF_REG_vc1piccntl2_numref_shift                                   (5)
#define  LGCY_RIF_REG_vc1piccntl2_pquant_shift                                   (0)
#define  LGCY_RIF_REG_vc1piccntl2_wmv9_bug_rtmflag_mask                          (0x00000100)
#define  LGCY_RIF_REG_vc1piccntl2_wmv9_bug_it_mask                               (0x00000080)
#define  LGCY_RIF_REG_vc1piccntl2_loopfilter_mask                                (0x00000040)
#define  LGCY_RIF_REG_vc1piccntl2_numref_mask                                    (0x00000020)
#define  LGCY_RIF_REG_vc1piccntl2_pquant_mask                                    (0x0000001F)
#define  LGCY_RIF_REG_vc1piccntl2_wmv9_bug_rtmflag(data)                         (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_vc1piccntl2_wmv9_bug_it(data)                              (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_vc1piccntl2_loopfilter(data)                               (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_vc1piccntl2_numref(data)                                   (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_vc1piccntl2_pquant(data)                                   (0x0000001F&(data))
#define  LGCY_RIF_REG_vc1piccntl2_get_wmv9_bug_rtmflag(data)                     ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_vc1piccntl2_get_wmv9_bug_it(data)                          ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_vc1piccntl2_get_loopfilter(data)                           ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_vc1piccntl2_get_numref(data)                               ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_vc1piccntl2_get_pquant(data)                               (0x0000001F&(data))

#define  LGCY_RIF_REG_brg_ctrl                                                   0x1800E490
#define  LGCY_RIF_REG_brg_ctrl_reg_addr                                          "0xB800E490"
#define  LGCY_RIF_REG_brg_ctrl_reg                                               0xB800E490
#define  LGCY_RIF_REG_brg_ctrl_inst_addr                                         "0x000F"
#define  set_LGCY_RIF_REG_brg_ctrl_reg(data)                                     (*((volatile unsigned int*)LGCY_RIF_REG_brg_ctrl_reg)=data)
#define  get_LGCY_RIF_REG_brg_ctrl_reg                                           (*((volatile unsigned int*)LGCY_RIF_REG_brg_ctrl_reg))
#define  LGCY_RIF_REG_brg_ctrl_priority_thd2_shift                               (16)
#define  LGCY_RIF_REG_brg_ctrl_priority_thd1_shift                               (8)
#define  LGCY_RIF_REG_brg_ctrl_srg_mode_shift                                    (3)
#define  LGCY_RIF_REG_brg_ctrl_ddr_page_shift                                    (1)
#define  LGCY_RIF_REG_brg_ctrl_srg_enable_shift                                  (0)
#define  LGCY_RIF_REG_brg_ctrl_priority_thd2_mask                                (0x00FF0000)
#define  LGCY_RIF_REG_brg_ctrl_priority_thd1_mask                                (0x0000FF00)
#define  LGCY_RIF_REG_brg_ctrl_srg_mode_mask                                     (0x00000008)
#define  LGCY_RIF_REG_brg_ctrl_ddr_page_mask                                     (0x00000006)
#define  LGCY_RIF_REG_brg_ctrl_srg_enable_mask                                   (0x00000001)
#define  LGCY_RIF_REG_brg_ctrl_priority_thd2(data)                               (0x00FF0000&((data)<<16))
#define  LGCY_RIF_REG_brg_ctrl_priority_thd1(data)                               (0x0000FF00&((data)<<8))
#define  LGCY_RIF_REG_brg_ctrl_srg_mode(data)                                    (0x00000008&((data)<<3))
#define  LGCY_RIF_REG_brg_ctrl_ddr_page(data)                                    (0x00000006&((data)<<1))
#define  LGCY_RIF_REG_brg_ctrl_srg_enable(data)                                  (0x00000001&(data))
#define  LGCY_RIF_REG_brg_ctrl_get_priority_thd2(data)                           ((0x00FF0000&(data))>>16)
#define  LGCY_RIF_REG_brg_ctrl_get_priority_thd1(data)                           ((0x0000FF00&(data))>>8)
#define  LGCY_RIF_REG_brg_ctrl_get_srg_mode(data)                                ((0x00000008&(data))>>3)
#define  LGCY_RIF_REG_brg_ctrl_get_ddr_page(data)                                ((0x00000006&(data))>>1)
#define  LGCY_RIF_REG_brg_ctrl_get_srg_enable(data)                              (0x00000001&(data))

#define  LGCY_RIF_REG_rd_priority0                                               0x1800E494
#define  LGCY_RIF_REG_rd_priority0_reg_addr                                      "0xB800E494"
#define  LGCY_RIF_REG_rd_priority0_reg                                           0xB800E494
#define  LGCY_RIF_REG_rd_priority0_inst_addr                                     "0x0010"
#define  set_LGCY_RIF_REG_rd_priority0_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority0_reg)=data)
#define  get_LGCY_RIF_REG_rd_priority0_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority0_reg))
#define  LGCY_RIF_REG_rd_priority0_vm2_shift                                     (16)
#define  LGCY_RIF_REG_rd_priority0_vm1_shift                                     (0)
#define  LGCY_RIF_REG_rd_priority0_vm2_mask                                      (0x0FFF0000)
#define  LGCY_RIF_REG_rd_priority0_vm1_mask                                      (0x00000FFF)
#define  LGCY_RIF_REG_rd_priority0_vm2(data)                                     (0x0FFF0000&((data)<<16))
#define  LGCY_RIF_REG_rd_priority0_vm1(data)                                     (0x00000FFF&(data))
#define  LGCY_RIF_REG_rd_priority0_get_vm2(data)                                 ((0x0FFF0000&(data))>>16)
#define  LGCY_RIF_REG_rd_priority0_get_vm1(data)                                 (0x00000FFF&(data))

#define  LGCY_RIF_REG_rd_priority1                                               0x1800E498
#define  LGCY_RIF_REG_rd_priority1_reg_addr                                      "0xB800E498"
#define  LGCY_RIF_REG_rd_priority1_reg                                           0xB800E498
#define  LGCY_RIF_REG_rd_priority1_inst_addr                                     "0x0011"
#define  set_LGCY_RIF_REG_rd_priority1_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority1_reg)=data)
#define  get_LGCY_RIF_REG_rd_priority1_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority1_reg))
#define  LGCY_RIF_REG_rd_priority1_deblk_shift                                   (16)
#define  LGCY_RIF_REG_rd_priority1_predblk_shift                                 (0)
#define  LGCY_RIF_REG_rd_priority1_deblk_mask                                    (0x0FFF0000)
#define  LGCY_RIF_REG_rd_priority1_predblk_mask                                  (0x00000FFF)
#define  LGCY_RIF_REG_rd_priority1_deblk(data)                                   (0x0FFF0000&((data)<<16))
#define  LGCY_RIF_REG_rd_priority1_predblk(data)                                 (0x00000FFF&(data))
#define  LGCY_RIF_REG_rd_priority1_get_deblk(data)                               ((0x0FFF0000&(data))>>16)
#define  LGCY_RIF_REG_rd_priority1_get_predblk(data)                             (0x00000FFF&(data))

#define  LGCY_RIF_REG_rd_priority2                                               0x1800E49C
#define  LGCY_RIF_REG_rd_priority2_reg_addr                                      "0xB800E49C"
#define  LGCY_RIF_REG_rd_priority2_reg                                           0xB800E49C
#define  LGCY_RIF_REG_rd_priority2_inst_addr                                     "0x0012"
#define  set_LGCY_RIF_REG_rd_priority2_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority2_reg)=data)
#define  get_LGCY_RIF_REG_rd_priority2_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority2_reg))
#define  LGCY_RIF_REG_rd_priority2_nm_shift                                      (16)
#define  LGCY_RIF_REG_rd_priority2_mvd_shift                                     (0)
#define  LGCY_RIF_REG_rd_priority2_nm_mask                                       (0x0FFF0000)
#define  LGCY_RIF_REG_rd_priority2_mvd_mask                                      (0x00000FFF)
#define  LGCY_RIF_REG_rd_priority2_nm(data)                                      (0x0FFF0000&((data)<<16))
#define  LGCY_RIF_REG_rd_priority2_mvd(data)                                     (0x00000FFF&(data))
#define  LGCY_RIF_REG_rd_priority2_get_nm(data)                                  ((0x0FFF0000&(data))>>16)
#define  LGCY_RIF_REG_rd_priority2_get_mvd(data)                                 (0x00000FFF&(data))

#define  LGCY_RIF_REG_rd_priority3                                               0x1800E4A0
#define  LGCY_RIF_REG_rd_priority3_reg_addr                                      "0xB800E4A0"
#define  LGCY_RIF_REG_rd_priority3_reg                                           0xB800E4A0
#define  LGCY_RIF_REG_rd_priority3_inst_addr                                     "0x0013"
#define  set_LGCY_RIF_REG_rd_priority3_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority3_reg)=data)
#define  get_LGCY_RIF_REG_rd_priority3_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority3_reg))
#define  LGCY_RIF_REG_rd_priority3_gcoeff_shift                                  (16)
#define  LGCY_RIF_REG_rd_priority3_bs_shift                                      (0)
#define  LGCY_RIF_REG_rd_priority3_gcoeff_mask                                   (0x0FFF0000)
#define  LGCY_RIF_REG_rd_priority3_bs_mask                                       (0x00000FFF)
#define  LGCY_RIF_REG_rd_priority3_gcoeff(data)                                  (0x0FFF0000&((data)<<16))
#define  LGCY_RIF_REG_rd_priority3_bs(data)                                      (0x00000FFF&(data))
#define  LGCY_RIF_REG_rd_priority3_get_gcoeff(data)                              ((0x0FFF0000&(data))>>16)
#define  LGCY_RIF_REG_rd_priority3_get_bs(data)                                  (0x00000FFF&(data))

#define  LGCY_RIF_REG_rd_priority4                                               0x1800E4A4
#define  LGCY_RIF_REG_rd_priority4_reg_addr                                      "0xB800E4A4"
#define  LGCY_RIF_REG_rd_priority4_reg                                           0xB800E4A4
#define  LGCY_RIF_REG_rd_priority4_inst_addr                                     "0x0014"
#define  set_LGCY_RIF_REG_rd_priority4_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority4_reg)=data)
#define  get_LGCY_RIF_REG_rd_priority4_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority4_reg))
#define  LGCY_RIF_REG_rd_priority4_cmp_shift                                     (16)
#define  LGCY_RIF_REG_rd_priority4_rl_shift                                      (0)
#define  LGCY_RIF_REG_rd_priority4_cmp_mask                                      (0x0FFF0000)
#define  LGCY_RIF_REG_rd_priority4_rl_mask                                       (0x00000FFF)
#define  LGCY_RIF_REG_rd_priority4_cmp(data)                                     (0x0FFF0000&((data)<<16))
#define  LGCY_RIF_REG_rd_priority4_rl(data)                                      (0x00000FFF&(data))
#define  LGCY_RIF_REG_rd_priority4_get_cmp(data)                                 ((0x0FFF0000&(data))>>16)
#define  LGCY_RIF_REG_rd_priority4_get_rl(data)                                  (0x00000FFF&(data))

#define  LGCY_RIF_REG_rd_priority5                                               0x1800E4A8
#define  LGCY_RIF_REG_rd_priority5_reg_addr                                      "0xB800E4A8"
#define  LGCY_RIF_REG_rd_priority5_reg                                           0xB800E4A8
#define  LGCY_RIF_REG_rd_priority5_inst_addr                                     "0x0015"
#define  set_LGCY_RIF_REG_rd_priority5_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority5_reg)=data)
#define  get_LGCY_RIF_REG_rd_priority5_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_rd_priority5_reg))
#define  LGCY_RIF_REG_rd_priority5_fme_shift                                     (16)
#define  LGCY_RIF_REG_rd_priority5_ime_shift                                     (0)
#define  LGCY_RIF_REG_rd_priority5_fme_mask                                      (0x0FFF0000)
#define  LGCY_RIF_REG_rd_priority5_ime_mask                                      (0x00000FFF)
#define  LGCY_RIF_REG_rd_priority5_fme(data)                                     (0x0FFF0000&((data)<<16))
#define  LGCY_RIF_REG_rd_priority5_ime(data)                                     (0x00000FFF&(data))
#define  LGCY_RIF_REG_rd_priority5_get_fme(data)                                 ((0x0FFF0000&(data))>>16)
#define  LGCY_RIF_REG_rd_priority5_get_ime(data)                                 (0x00000FFF&(data))

#define  LGCY_RIF_REG_wt_priority0                                               0x1800E4B0
#define  LGCY_RIF_REG_wt_priority0_reg_addr                                      "0xB800E4B0"
#define  LGCY_RIF_REG_wt_priority0_reg                                           0xB800E4B0
#define  LGCY_RIF_REG_wt_priority0_inst_addr                                     "0x0016"
#define  set_LGCY_RIF_REG_wt_priority0_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority0_reg)=data)
#define  get_LGCY_RIF_REG_wt_priority0_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority0_reg))
#define  LGCY_RIF_REG_wt_priority0_vm2_shift                                     (16)
#define  LGCY_RIF_REG_wt_priority0_vm1_shift                                     (0)
#define  LGCY_RIF_REG_wt_priority0_vm2_mask                                      (0x07FF0000)
#define  LGCY_RIF_REG_wt_priority0_vm1_mask                                      (0x000007FF)
#define  LGCY_RIF_REG_wt_priority0_vm2(data)                                     (0x07FF0000&((data)<<16))
#define  LGCY_RIF_REG_wt_priority0_vm1(data)                                     (0x000007FF&(data))
#define  LGCY_RIF_REG_wt_priority0_get_vm2(data)                                 ((0x07FF0000&(data))>>16)
#define  LGCY_RIF_REG_wt_priority0_get_vm1(data)                                 (0x000007FF&(data))

#define  LGCY_RIF_REG_wt_priority1                                               0x1800E4B4
#define  LGCY_RIF_REG_wt_priority1_reg_addr                                      "0xB800E4B4"
#define  LGCY_RIF_REG_wt_priority1_reg                                           0xB800E4B4
#define  LGCY_RIF_REG_wt_priority1_inst_addr                                     "0x0017"
#define  set_LGCY_RIF_REG_wt_priority1_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority1_reg)=data)
#define  get_LGCY_RIF_REG_wt_priority1_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority1_reg))
#define  LGCY_RIF_REG_wt_priority1_deblk_shift                                   (16)
#define  LGCY_RIF_REG_wt_priority1_predblk_shift                                 (0)
#define  LGCY_RIF_REG_wt_priority1_deblk_mask                                    (0x07FF0000)
#define  LGCY_RIF_REG_wt_priority1_predblk_mask                                  (0x000007FF)
#define  LGCY_RIF_REG_wt_priority1_deblk(data)                                   (0x07FF0000&((data)<<16))
#define  LGCY_RIF_REG_wt_priority1_predblk(data)                                 (0x000007FF&(data))
#define  LGCY_RIF_REG_wt_priority1_get_deblk(data)                               ((0x07FF0000&(data))>>16)
#define  LGCY_RIF_REG_wt_priority1_get_predblk(data)                             (0x000007FF&(data))

#define  LGCY_RIF_REG_wt_priority2                                               0x1800E4B8
#define  LGCY_RIF_REG_wt_priority2_reg_addr                                      "0xB800E4B8"
#define  LGCY_RIF_REG_wt_priority2_reg                                           0xB800E4B8
#define  LGCY_RIF_REG_wt_priority2_inst_addr                                     "0x0018"
#define  set_LGCY_RIF_REG_wt_priority2_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority2_reg)=data)
#define  get_LGCY_RIF_REG_wt_priority2_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority2_reg))
#define  LGCY_RIF_REG_wt_priority2_nm_shift                                      (16)
#define  LGCY_RIF_REG_wt_priority2_mvd_shift                                     (0)
#define  LGCY_RIF_REG_wt_priority2_nm_mask                                       (0x07FF0000)
#define  LGCY_RIF_REG_wt_priority2_mvd_mask                                      (0x000007FF)
#define  LGCY_RIF_REG_wt_priority2_nm(data)                                      (0x07FF0000&((data)<<16))
#define  LGCY_RIF_REG_wt_priority2_mvd(data)                                     (0x000007FF&(data))
#define  LGCY_RIF_REG_wt_priority2_get_nm(data)                                  ((0x07FF0000&(data))>>16)
#define  LGCY_RIF_REG_wt_priority2_get_mvd(data)                                 (0x000007FF&(data))

#define  LGCY_RIF_REG_wt_priority3                                               0x1800E4BC
#define  LGCY_RIF_REG_wt_priority3_reg_addr                                      "0xB800E4BC"
#define  LGCY_RIF_REG_wt_priority3_reg                                           0xB800E4BC
#define  LGCY_RIF_REG_wt_priority3_inst_addr                                     "0x0019"
#define  set_LGCY_RIF_REG_wt_priority3_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority3_reg)=data)
#define  get_LGCY_RIF_REG_wt_priority3_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority3_reg))
#define  LGCY_RIF_REG_wt_priority3_gcoeff_shift                                  (16)
#define  LGCY_RIF_REG_wt_priority3_bs_shift                                      (0)
#define  LGCY_RIF_REG_wt_priority3_gcoeff_mask                                   (0x07FF0000)
#define  LGCY_RIF_REG_wt_priority3_bs_mask                                       (0x000007FF)
#define  LGCY_RIF_REG_wt_priority3_gcoeff(data)                                  (0x07FF0000&((data)<<16))
#define  LGCY_RIF_REG_wt_priority3_bs(data)                                      (0x000007FF&(data))
#define  LGCY_RIF_REG_wt_priority3_get_gcoeff(data)                              ((0x07FF0000&(data))>>16)
#define  LGCY_RIF_REG_wt_priority3_get_bs(data)                                  (0x000007FF&(data))

#define  LGCY_RIF_REG_wt_priority4                                               0x1800E4C0
#define  LGCY_RIF_REG_wt_priority4_reg_addr                                      "0xB800E4C0"
#define  LGCY_RIF_REG_wt_priority4_reg                                           0xB800E4C0
#define  LGCY_RIF_REG_wt_priority4_inst_addr                                     "0x001A"
#define  set_LGCY_RIF_REG_wt_priority4_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority4_reg)=data)
#define  get_LGCY_RIF_REG_wt_priority4_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority4_reg))
#define  LGCY_RIF_REG_wt_priority4_cmp_shift                                     (16)
#define  LGCY_RIF_REG_wt_priority4_it_shift                                      (0)
#define  LGCY_RIF_REG_wt_priority4_cmp_mask                                      (0x07FF0000)
#define  LGCY_RIF_REG_wt_priority4_it_mask                                       (0x000007FF)
#define  LGCY_RIF_REG_wt_priority4_cmp(data)                                     (0x07FF0000&((data)<<16))
#define  LGCY_RIF_REG_wt_priority4_it(data)                                      (0x000007FF&(data))
#define  LGCY_RIF_REG_wt_priority4_get_cmp(data)                                 ((0x07FF0000&(data))>>16)
#define  LGCY_RIF_REG_wt_priority4_get_it(data)                                  (0x000007FF&(data))

#define  LGCY_RIF_REG_wt_priority5                                               0x1800E4C4
#define  LGCY_RIF_REG_wt_priority5_reg_addr                                      "0xB800E4C4"
#define  LGCY_RIF_REG_wt_priority5_reg                                           0xB800E4C4
#define  LGCY_RIF_REG_wt_priority5_inst_addr                                     "0x001B"
#define  set_LGCY_RIF_REG_wt_priority5_reg(data)                                 (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority5_reg)=data)
#define  get_LGCY_RIF_REG_wt_priority5_reg                                       (*((volatile unsigned int*)LGCY_RIF_REG_wt_priority5_reg))
#define  LGCY_RIF_REG_wt_priority5_fme_shift                                     (0)
#define  LGCY_RIF_REG_wt_priority5_fme_mask                                      (0x000007FF)
#define  LGCY_RIF_REG_wt_priority5_fme(data)                                     (0x000007FF&(data))
#define  LGCY_RIF_REG_wt_priority5_get_fme(data)                                 (0x000007FF&(data))

#define  LGCY_RIF_REG_clkgated                                                   0x1800E4D8
#define  LGCY_RIF_REG_clkgated_reg_addr                                          "0xB800E4D8"
#define  LGCY_RIF_REG_clkgated_reg                                               0xB800E4D8
#define  LGCY_RIF_REG_clkgated_inst_addr                                         "0x001C"
#define  set_LGCY_RIF_REG_clkgated_reg(data)                                     (*((volatile unsigned int*)LGCY_RIF_REG_clkgated_reg)=data)
#define  get_LGCY_RIF_REG_clkgated_reg                                           (*((volatile unsigned int*)LGCY_RIF_REG_clkgated_reg))
#define  LGCY_RIF_REG_clkgated_cache_gated_en_shift                              (25)
#define  LGCY_RIF_REG_clkgated_rl_gated_en_shift                                 (24)
#define  LGCY_RIF_REG_clkgated_mvd_gated_en_shift                                (23)
#define  LGCY_RIF_REG_clkgated_ndbp2_gated_en_shift                              (22)
#define  LGCY_RIF_REG_clkgated_ndb_gated_en_shift                                (21)
#define  LGCY_RIF_REG_clkgated_brg_gated_en_shift                                (20)
#define  LGCY_RIF_REG_clkgated_cm_gated_en_shift                                 (19)
#define  LGCY_RIF_REG_clkgated_arb_gated_en_shift                                (18)
#define  LGCY_RIF_REG_clkgated_bsfifop2_gated_en_shift                           (17)
#define  LGCY_RIF_REG_clkgated_bsfifo_gated_en_shift                             (16)
#define  LGCY_RIF_REG_clkgated_img_gated_en_shift                                (15)
#define  LGCY_RIF_REG_clkgated_deblk_gated_en_shift                              (14)
#define  LGCY_RIF_REG_clkgated_gc_gated_en_shift                                 (13)
#define  LGCY_RIF_REG_clkgated_pred_gated_en_shift                               (12)
#define  LGCY_RIF_REG_clkgated_emd_gated_en_shift                                (11)
#define  LGCY_RIF_REG_clkgated_imedma_gated_en_shift                             (10)
#define  LGCY_RIF_REG_clkgated_ime_gated_en_shift                                (9)
#define  LGCY_RIF_REG_clkgated_vm2_gated_en_shift                                (8)
#define  LGCY_RIF_REG_clkgated_vm1_gated_en_shift                                (7)
#define  LGCY_RIF_REG_clkgated_it_gated_en_shift                                 (6)
#define  LGCY_RIF_REG_clkgated_cabac_gated_en_shift                              (5)
#define  LGCY_RIF_REG_clkgated_vp8p2_gated_en_shift                              (4)
#define  LGCY_RIF_REG_clkgated_cabacp2_gated_en_shift                            (3)
#define  LGCY_RIF_REG_clkgated_vld_gated_en_shift                                (2)
#define  LGCY_RIF_REG_clkgated_vlc_gated_en_shift                                (1)
#define  LGCY_RIF_REG_clkgated_acdc_gated_en_shift                               (0)
#define  LGCY_RIF_REG_clkgated_cache_gated_en_mask                               (0x02000000)
#define  LGCY_RIF_REG_clkgated_rl_gated_en_mask                                  (0x01000000)
#define  LGCY_RIF_REG_clkgated_mvd_gated_en_mask                                 (0x00800000)
#define  LGCY_RIF_REG_clkgated_ndbp2_gated_en_mask                               (0x00400000)
#define  LGCY_RIF_REG_clkgated_ndb_gated_en_mask                                 (0x00200000)
#define  LGCY_RIF_REG_clkgated_brg_gated_en_mask                                 (0x00100000)
#define  LGCY_RIF_REG_clkgated_cm_gated_en_mask                                  (0x00080000)
#define  LGCY_RIF_REG_clkgated_arb_gated_en_mask                                 (0x00040000)
#define  LGCY_RIF_REG_clkgated_bsfifop2_gated_en_mask                            (0x00020000)
#define  LGCY_RIF_REG_clkgated_bsfifo_gated_en_mask                              (0x00010000)
#define  LGCY_RIF_REG_clkgated_img_gated_en_mask                                 (0x00008000)
#define  LGCY_RIF_REG_clkgated_deblk_gated_en_mask                               (0x00004000)
#define  LGCY_RIF_REG_clkgated_gc_gated_en_mask                                  (0x00002000)
#define  LGCY_RIF_REG_clkgated_pred_gated_en_mask                                (0x00001000)
#define  LGCY_RIF_REG_clkgated_emd_gated_en_mask                                 (0x00000800)
#define  LGCY_RIF_REG_clkgated_imedma_gated_en_mask                              (0x00000400)
#define  LGCY_RIF_REG_clkgated_ime_gated_en_mask                                 (0x00000200)
#define  LGCY_RIF_REG_clkgated_vm2_gated_en_mask                                 (0x00000100)
#define  LGCY_RIF_REG_clkgated_vm1_gated_en_mask                                 (0x00000080)
#define  LGCY_RIF_REG_clkgated_it_gated_en_mask                                  (0x00000040)
#define  LGCY_RIF_REG_clkgated_cabac_gated_en_mask                               (0x00000020)
#define  LGCY_RIF_REG_clkgated_vp8p2_gated_en_mask                               (0x00000010)
#define  LGCY_RIF_REG_clkgated_cabacp2_gated_en_mask                             (0x00000008)
#define  LGCY_RIF_REG_clkgated_vld_gated_en_mask                                 (0x00000004)
#define  LGCY_RIF_REG_clkgated_vlc_gated_en_mask                                 (0x00000002)
#define  LGCY_RIF_REG_clkgated_acdc_gated_en_mask                                (0x00000001)
#define  LGCY_RIF_REG_clkgated_cache_gated_en(data)                              (0x02000000&((data)<<25))
#define  LGCY_RIF_REG_clkgated_rl_gated_en(data)                                 (0x01000000&((data)<<24))
#define  LGCY_RIF_REG_clkgated_mvd_gated_en(data)                                (0x00800000&((data)<<23))
#define  LGCY_RIF_REG_clkgated_ndbp2_gated_en(data)                              (0x00400000&((data)<<22))
#define  LGCY_RIF_REG_clkgated_ndb_gated_en(data)                                (0x00200000&((data)<<21))
#define  LGCY_RIF_REG_clkgated_brg_gated_en(data)                                (0x00100000&((data)<<20))
#define  LGCY_RIF_REG_clkgated_cm_gated_en(data)                                 (0x00080000&((data)<<19))
#define  LGCY_RIF_REG_clkgated_arb_gated_en(data)                                (0x00040000&((data)<<18))
#define  LGCY_RIF_REG_clkgated_bsfifop2_gated_en(data)                           (0x00020000&((data)<<17))
#define  LGCY_RIF_REG_clkgated_bsfifo_gated_en(data)                             (0x00010000&((data)<<16))
#define  LGCY_RIF_REG_clkgated_img_gated_en(data)                                (0x00008000&((data)<<15))
#define  LGCY_RIF_REG_clkgated_deblk_gated_en(data)                              (0x00004000&((data)<<14))
#define  LGCY_RIF_REG_clkgated_gc_gated_en(data)                                 (0x00002000&((data)<<13))
#define  LGCY_RIF_REG_clkgated_pred_gated_en(data)                               (0x00001000&((data)<<12))
#define  LGCY_RIF_REG_clkgated_emd_gated_en(data)                                (0x00000800&((data)<<11))
#define  LGCY_RIF_REG_clkgated_imedma_gated_en(data)                             (0x00000400&((data)<<10))
#define  LGCY_RIF_REG_clkgated_ime_gated_en(data)                                (0x00000200&((data)<<9))
#define  LGCY_RIF_REG_clkgated_vm2_gated_en(data)                                (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_clkgated_vm1_gated_en(data)                                (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_clkgated_it_gated_en(data)                                 (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_clkgated_cabac_gated_en(data)                              (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_clkgated_vp8p2_gated_en(data)                              (0x00000010&((data)<<4))
#define  LGCY_RIF_REG_clkgated_cabacp2_gated_en(data)                            (0x00000008&((data)<<3))
#define  LGCY_RIF_REG_clkgated_vld_gated_en(data)                                (0x00000004&((data)<<2))
#define  LGCY_RIF_REG_clkgated_vlc_gated_en(data)                                (0x00000002&((data)<<1))
#define  LGCY_RIF_REG_clkgated_acdc_gated_en(data)                               (0x00000001&(data))
#define  LGCY_RIF_REG_clkgated_get_cache_gated_en(data)                          ((0x02000000&(data))>>25)
#define  LGCY_RIF_REG_clkgated_get_rl_gated_en(data)                             ((0x01000000&(data))>>24)
#define  LGCY_RIF_REG_clkgated_get_mvd_gated_en(data)                            ((0x00800000&(data))>>23)
#define  LGCY_RIF_REG_clkgated_get_ndbp2_gated_en(data)                          ((0x00400000&(data))>>22)
#define  LGCY_RIF_REG_clkgated_get_ndb_gated_en(data)                            ((0x00200000&(data))>>21)
#define  LGCY_RIF_REG_clkgated_get_brg_gated_en(data)                            ((0x00100000&(data))>>20)
#define  LGCY_RIF_REG_clkgated_get_cm_gated_en(data)                             ((0x00080000&(data))>>19)
#define  LGCY_RIF_REG_clkgated_get_arb_gated_en(data)                            ((0x00040000&(data))>>18)
#define  LGCY_RIF_REG_clkgated_get_bsfifop2_gated_en(data)                       ((0x00020000&(data))>>17)
#define  LGCY_RIF_REG_clkgated_get_bsfifo_gated_en(data)                         ((0x00010000&(data))>>16)
#define  LGCY_RIF_REG_clkgated_get_img_gated_en(data)                            ((0x00008000&(data))>>15)
#define  LGCY_RIF_REG_clkgated_get_deblk_gated_en(data)                          ((0x00004000&(data))>>14)
#define  LGCY_RIF_REG_clkgated_get_gc_gated_en(data)                             ((0x00002000&(data))>>13)
#define  LGCY_RIF_REG_clkgated_get_pred_gated_en(data)                           ((0x00001000&(data))>>12)
#define  LGCY_RIF_REG_clkgated_get_emd_gated_en(data)                            ((0x00000800&(data))>>11)
#define  LGCY_RIF_REG_clkgated_get_imedma_gated_en(data)                         ((0x00000400&(data))>>10)
#define  LGCY_RIF_REG_clkgated_get_ime_gated_en(data)                            ((0x00000200&(data))>>9)
#define  LGCY_RIF_REG_clkgated_get_vm2_gated_en(data)                            ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_clkgated_get_vm1_gated_en(data)                            ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_clkgated_get_it_gated_en(data)                             ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_clkgated_get_cabac_gated_en(data)                          ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_clkgated_get_vp8p2_gated_en(data)                          ((0x00000010&(data))>>4)
#define  LGCY_RIF_REG_clkgated_get_cabacp2_gated_en(data)                        ((0x00000008&(data))>>3)
#define  LGCY_RIF_REG_clkgated_get_vld_gated_en(data)                            ((0x00000004&(data))>>2)
#define  LGCY_RIF_REG_clkgated_get_vlc_gated_en(data)                            ((0x00000002&(data))>>1)
#define  LGCY_RIF_REG_clkgated_get_acdc_gated_en(data)                           (0x00000001&(data))

#define  LGCY_RIF_REG_dbg_ctrl17                                                 0x1800E4DC
#define  LGCY_RIF_REG_dbg_ctrl17_reg_addr                                        "0xB800E4DC"
#define  LGCY_RIF_REG_dbg_ctrl17_reg                                             0xB800E4DC
#define  LGCY_RIF_REG_dbg_ctrl17_inst_addr                                       "0x001D"
#define  set_LGCY_RIF_REG_dbg_ctrl17_reg(data)                                   (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl17_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl17_reg                                         (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl17_reg))
#define  LGCY_RIF_REG_dbg_ctrl17_seg_dbg_sel1_shift                              (24)
#define  LGCY_RIF_REG_dbg_ctrl17_seg_dbg_sel0_shift                              (20)
#define  LGCY_RIF_REG_dbg_ctrl17_sao_dbg_sel1_shift                              (16)
#define  LGCY_RIF_REG_dbg_ctrl17_sao_dbg_sel0_shift                              (12)
#define  LGCY_RIF_REG_dbg_ctrl17_ime_dbg_sel1_shift                              (6)
#define  LGCY_RIF_REG_dbg_ctrl17_ime_dbg_sel0_shift                              (0)
#define  LGCY_RIF_REG_dbg_ctrl17_seg_dbg_sel1_mask                               (0x0F000000)
#define  LGCY_RIF_REG_dbg_ctrl17_seg_dbg_sel0_mask                               (0x00F00000)
#define  LGCY_RIF_REG_dbg_ctrl17_sao_dbg_sel1_mask                               (0x000F0000)
#define  LGCY_RIF_REG_dbg_ctrl17_sao_dbg_sel0_mask                               (0x0000F000)
#define  LGCY_RIF_REG_dbg_ctrl17_ime_dbg_sel1_mask                               (0x00000FC0)
#define  LGCY_RIF_REG_dbg_ctrl17_ime_dbg_sel0_mask                               (0x0000003F)
#define  LGCY_RIF_REG_dbg_ctrl17_seg_dbg_sel1(data)                              (0x0F000000&((data)<<24))
#define  LGCY_RIF_REG_dbg_ctrl17_seg_dbg_sel0(data)                              (0x00F00000&((data)<<20))
#define  LGCY_RIF_REG_dbg_ctrl17_sao_dbg_sel1(data)                              (0x000F0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_ctrl17_sao_dbg_sel0(data)                              (0x0000F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl17_ime_dbg_sel1(data)                              (0x00000FC0&((data)<<6))
#define  LGCY_RIF_REG_dbg_ctrl17_ime_dbg_sel0(data)                              (0x0000003F&(data))
#define  LGCY_RIF_REG_dbg_ctrl17_get_seg_dbg_sel1(data)                          ((0x0F000000&(data))>>24)
#define  LGCY_RIF_REG_dbg_ctrl17_get_seg_dbg_sel0(data)                          ((0x00F00000&(data))>>20)
#define  LGCY_RIF_REG_dbg_ctrl17_get_sao_dbg_sel1(data)                          ((0x000F0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_ctrl17_get_sao_dbg_sel0(data)                          ((0x0000F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl17_get_ime_dbg_sel1(data)                          ((0x00000FC0&(data))>>6)
#define  LGCY_RIF_REG_dbg_ctrl17_get_ime_dbg_sel0(data)                          (0x0000003F&(data))

#define  LGCY_RIF_REG_dbg_out                                                    0x1800E4E0
#define  LGCY_RIF_REG_dbg_out_reg_addr                                           "0xB800E4E0"
#define  LGCY_RIF_REG_dbg_out_reg                                                0xB800E4E0
#define  LGCY_RIF_REG_dbg_out_inst_addr                                          "0x001E"
#define  set_LGCY_RIF_REG_dbg_out_reg(data)                                      (*((volatile unsigned int*)LGCY_RIF_REG_dbg_out_reg)=data)
#define  get_LGCY_RIF_REG_dbg_out_reg                                            (*((volatile unsigned int*)LGCY_RIF_REG_dbg_out_reg))
#define  LGCY_RIF_REG_dbg_out_ve_dbg_out1_shift                                  (16)
#define  LGCY_RIF_REG_dbg_out_ve_dbg_out0_shift                                  (0)
#define  LGCY_RIF_REG_dbg_out_ve_dbg_out1_mask                                   (0xFFFF0000)
#define  LGCY_RIF_REG_dbg_out_ve_dbg_out0_mask                                   (0x0000FFFF)
#define  LGCY_RIF_REG_dbg_out_ve_dbg_out1(data)                                  (0xFFFF0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_out_ve_dbg_out0(data)                                  (0x0000FFFF&(data))
#define  LGCY_RIF_REG_dbg_out_get_ve_dbg_out1(data)                              ((0xFFFF0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_out_get_ve_dbg_out0(data)                              (0x0000FFFF&(data))

#define  LGCY_RIF_REG_dbg_ctrl1                                                  0x1800E4E4
#define  LGCY_RIF_REG_dbg_ctrl1_reg_addr                                         "0xB800E4E4"
#define  LGCY_RIF_REG_dbg_ctrl1_reg                                              0xB800E4E4
#define  LGCY_RIF_REG_dbg_ctrl1_inst_addr                                        "0x001F"
#define  set_LGCY_RIF_REG_dbg_ctrl1_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl1_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl1_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl1_reg))
#define  LGCY_RIF_REG_dbg_ctrl1_cache_dbg_sel1_shift                             (28)
#define  LGCY_RIF_REG_dbg_ctrl1_cache_dbg_sel0_shift                             (24)
#define  LGCY_RIF_REG_dbg_ctrl1_bs_dbg_sel1_shift                                (20)
#define  LGCY_RIF_REG_dbg_ctrl1_bs_dbg_sel0_shift                                (16)
#define  LGCY_RIF_REG_dbg_ctrl1_brg_dbg_sel1_shift                               (12)
#define  LGCY_RIF_REG_dbg_ctrl1_brg_dbg_sel0_shift                               (8)
#define  LGCY_RIF_REG_dbg_ctrl1_acdc_dbg_sel1_shift                              (4)
#define  LGCY_RIF_REG_dbg_ctrl1_acdc_dbg_sel0_shift                              (0)
#define  LGCY_RIF_REG_dbg_ctrl1_cache_dbg_sel1_mask                              (0xF0000000)
#define  LGCY_RIF_REG_dbg_ctrl1_cache_dbg_sel0_mask                              (0x0F000000)
#define  LGCY_RIF_REG_dbg_ctrl1_bs_dbg_sel1_mask                                 (0x00F00000)
#define  LGCY_RIF_REG_dbg_ctrl1_bs_dbg_sel0_mask                                 (0x000F0000)
#define  LGCY_RIF_REG_dbg_ctrl1_brg_dbg_sel1_mask                                (0x0000F000)
#define  LGCY_RIF_REG_dbg_ctrl1_brg_dbg_sel0_mask                                (0x00000F00)
#define  LGCY_RIF_REG_dbg_ctrl1_acdc_dbg_sel1_mask                               (0x000000F0)
#define  LGCY_RIF_REG_dbg_ctrl1_acdc_dbg_sel0_mask                               (0x0000000F)
#define  LGCY_RIF_REG_dbg_ctrl1_cache_dbg_sel1(data)                             (0xF0000000&((data)<<28))
#define  LGCY_RIF_REG_dbg_ctrl1_cache_dbg_sel0(data)                             (0x0F000000&((data)<<24))
#define  LGCY_RIF_REG_dbg_ctrl1_bs_dbg_sel1(data)                                (0x00F00000&((data)<<20))
#define  LGCY_RIF_REG_dbg_ctrl1_bs_dbg_sel0(data)                                (0x000F0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_ctrl1_brg_dbg_sel1(data)                               (0x0000F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl1_brg_dbg_sel0(data)                               (0x00000F00&((data)<<8))
#define  LGCY_RIF_REG_dbg_ctrl1_acdc_dbg_sel1(data)                              (0x000000F0&((data)<<4))
#define  LGCY_RIF_REG_dbg_ctrl1_acdc_dbg_sel0(data)                              (0x0000000F&(data))
#define  LGCY_RIF_REG_dbg_ctrl1_get_cache_dbg_sel1(data)                         ((0xF0000000&(data))>>28)
#define  LGCY_RIF_REG_dbg_ctrl1_get_cache_dbg_sel0(data)                         ((0x0F000000&(data))>>24)
#define  LGCY_RIF_REG_dbg_ctrl1_get_bs_dbg_sel1(data)                            ((0x00F00000&(data))>>20)
#define  LGCY_RIF_REG_dbg_ctrl1_get_bs_dbg_sel0(data)                            ((0x000F0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_ctrl1_get_brg_dbg_sel1(data)                           ((0x0000F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl1_get_brg_dbg_sel0(data)                           ((0x00000F00&(data))>>8)
#define  LGCY_RIF_REG_dbg_ctrl1_get_acdc_dbg_sel1(data)                          ((0x000000F0&(data))>>4)
#define  LGCY_RIF_REG_dbg_ctrl1_get_acdc_dbg_sel0(data)                          (0x0000000F&(data))

#define  LGCY_RIF_REG_dbg_ctrl2                                                  0x1800E4E8
#define  LGCY_RIF_REG_dbg_ctrl2_reg_addr                                         "0xB800E4E8"
#define  LGCY_RIF_REG_dbg_ctrl2_reg                                              0xB800E4E8
#define  LGCY_RIF_REG_dbg_ctrl2_inst_addr                                        "0x0020"
#define  set_LGCY_RIF_REG_dbg_ctrl2_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl2_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl2_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl2_reg))
#define  LGCY_RIF_REG_dbg_ctrl2_bs_dbg_sel3_shift                                (26)
#define  LGCY_RIF_REG_dbg_ctrl2_bs_dbg_sel2_shift                                (24)
#define  LGCY_RIF_REG_dbg_ctrl2_cm_dbg_sel1_shift                                (20)
#define  LGCY_RIF_REG_dbg_ctrl2_cm_dbg_sel0_shift                                (16)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp3_dbg_sel1_shift                           (12)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp3_dbg_sel0_shift                           (8)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp2_dbg_sel1_shift                           (4)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp2_dbg_sel0_shift                           (0)
#define  LGCY_RIF_REG_dbg_ctrl2_bs_dbg_sel3_mask                                 (0x0C000000)
#define  LGCY_RIF_REG_dbg_ctrl2_bs_dbg_sel2_mask                                 (0x03000000)
#define  LGCY_RIF_REG_dbg_ctrl2_cm_dbg_sel1_mask                                 (0x00F00000)
#define  LGCY_RIF_REG_dbg_ctrl2_cm_dbg_sel0_mask                                 (0x000F0000)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp3_dbg_sel1_mask                            (0x0000F000)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp3_dbg_sel0_mask                            (0x00000F00)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp2_dbg_sel1_mask                            (0x000000F0)
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp2_dbg_sel0_mask                            (0x0000000F)
#define  LGCY_RIF_REG_dbg_ctrl2_bs_dbg_sel3(data)                                (0x0C000000&((data)<<26))
#define  LGCY_RIF_REG_dbg_ctrl2_bs_dbg_sel2(data)                                (0x03000000&((data)<<24))
#define  LGCY_RIF_REG_dbg_ctrl2_cm_dbg_sel1(data)                                (0x00F00000&((data)<<20))
#define  LGCY_RIF_REG_dbg_ctrl2_cm_dbg_sel0(data)                                (0x000F0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp3_dbg_sel1(data)                           (0x0000F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp3_dbg_sel0(data)                           (0x00000F00&((data)<<8))
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp2_dbg_sel1(data)                           (0x000000F0&((data)<<4))
#define  LGCY_RIF_REG_dbg_ctrl2_cabacp2_dbg_sel0(data)                           (0x0000000F&(data))
#define  LGCY_RIF_REG_dbg_ctrl2_get_bs_dbg_sel3(data)                            ((0x0C000000&(data))>>26)
#define  LGCY_RIF_REG_dbg_ctrl2_get_bs_dbg_sel2(data)                            ((0x03000000&(data))>>24)
#define  LGCY_RIF_REG_dbg_ctrl2_get_cm_dbg_sel1(data)                            ((0x00F00000&(data))>>20)
#define  LGCY_RIF_REG_dbg_ctrl2_get_cm_dbg_sel0(data)                            ((0x000F0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_ctrl2_get_cabacp3_dbg_sel1(data)                       ((0x0000F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl2_get_cabacp3_dbg_sel0(data)                       ((0x00000F00&(data))>>8)
#define  LGCY_RIF_REG_dbg_ctrl2_get_cabacp2_dbg_sel1(data)                       ((0x000000F0&(data))>>4)
#define  LGCY_RIF_REG_dbg_ctrl2_get_cabacp2_dbg_sel0(data)                       (0x0000000F&(data))

#define  LGCY_RIF_REG_dbg_ctrl3                                                  0x1800E4EC
#define  LGCY_RIF_REG_dbg_ctrl3_reg_addr                                         "0xB800E4EC"
#define  LGCY_RIF_REG_dbg_ctrl3_reg                                              0xB800E4EC
#define  LGCY_RIF_REG_dbg_ctrl3_inst_addr                                        "0x0021"
#define  set_LGCY_RIF_REG_dbg_ctrl3_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl3_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl3_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl3_reg))
#define  LGCY_RIF_REG_dbg_ctrl3_ndb_dbg_sel1_shift                               (28)
#define  LGCY_RIF_REG_dbg_ctrl3_ndb_dbg_sel0_shift                               (24)
#define  LGCY_RIF_REG_dbg_ctrl3_rif_dbg_sel1_shift                               (20)
#define  LGCY_RIF_REG_dbg_ctrl3_rif_dbg_sel0_shift                               (16)
#define  LGCY_RIF_REG_dbg_ctrl3_itblk_dbg_sel1_shift                             (12)
#define  LGCY_RIF_REG_dbg_ctrl3_itblk_dbg_sel0_shift                             (8)
#define  LGCY_RIF_REG_dbg_ctrl3_img_dbg_sel1_shift                               (4)
#define  LGCY_RIF_REG_dbg_ctrl3_img_dbg_sel0_shift                               (0)
#define  LGCY_RIF_REG_dbg_ctrl3_ndb_dbg_sel1_mask                                (0xF0000000)
#define  LGCY_RIF_REG_dbg_ctrl3_ndb_dbg_sel0_mask                                (0x0F000000)
#define  LGCY_RIF_REG_dbg_ctrl3_rif_dbg_sel1_mask                                (0x00F00000)
#define  LGCY_RIF_REG_dbg_ctrl3_rif_dbg_sel0_mask                                (0x000F0000)
#define  LGCY_RIF_REG_dbg_ctrl3_itblk_dbg_sel1_mask                              (0x0000F000)
#define  LGCY_RIF_REG_dbg_ctrl3_itblk_dbg_sel0_mask                              (0x00000F00)
#define  LGCY_RIF_REG_dbg_ctrl3_img_dbg_sel1_mask                                (0x000000F0)
#define  LGCY_RIF_REG_dbg_ctrl3_img_dbg_sel0_mask                                (0x0000000F)
#define  LGCY_RIF_REG_dbg_ctrl3_ndb_dbg_sel1(data)                               (0xF0000000&((data)<<28))
#define  LGCY_RIF_REG_dbg_ctrl3_ndb_dbg_sel0(data)                               (0x0F000000&((data)<<24))
#define  LGCY_RIF_REG_dbg_ctrl3_rif_dbg_sel1(data)                               (0x00F00000&((data)<<20))
#define  LGCY_RIF_REG_dbg_ctrl3_rif_dbg_sel0(data)                               (0x000F0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_ctrl3_itblk_dbg_sel1(data)                             (0x0000F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl3_itblk_dbg_sel0(data)                             (0x00000F00&((data)<<8))
#define  LGCY_RIF_REG_dbg_ctrl3_img_dbg_sel1(data)                               (0x000000F0&((data)<<4))
#define  LGCY_RIF_REG_dbg_ctrl3_img_dbg_sel0(data)                               (0x0000000F&(data))
#define  LGCY_RIF_REG_dbg_ctrl3_get_ndb_dbg_sel1(data)                           ((0xF0000000&(data))>>28)
#define  LGCY_RIF_REG_dbg_ctrl3_get_ndb_dbg_sel0(data)                           ((0x0F000000&(data))>>24)
#define  LGCY_RIF_REG_dbg_ctrl3_get_rif_dbg_sel1(data)                           ((0x00F00000&(data))>>20)
#define  LGCY_RIF_REG_dbg_ctrl3_get_rif_dbg_sel0(data)                           ((0x000F0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_ctrl3_get_itblk_dbg_sel1(data)                         ((0x0000F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl3_get_itblk_dbg_sel0(data)                         ((0x00000F00&(data))>>8)
#define  LGCY_RIF_REG_dbg_ctrl3_get_img_dbg_sel1(data)                           ((0x000000F0&(data))>>4)
#define  LGCY_RIF_REG_dbg_ctrl3_get_img_dbg_sel0(data)                           (0x0000000F&(data))

#define  LGCY_RIF_REG_dbg_ctrl4                                                  0x1800E4F0
#define  LGCY_RIF_REG_dbg_ctrl4_reg_addr                                         "0xB800E4F0"
#define  LGCY_RIF_REG_dbg_ctrl4_reg                                              0xB800E4F0
#define  LGCY_RIF_REG_dbg_ctrl4_inst_addr                                        "0x0022"
#define  set_LGCY_RIF_REG_dbg_ctrl4_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl4_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl4_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl4_reg))
#define  LGCY_RIF_REG_dbg_ctrl4_rl_dbg_sel1_shift                                (28)
#define  LGCY_RIF_REG_dbg_ctrl4_rl_dbg_sel0_shift                                (24)
#define  LGCY_RIF_REG_dbg_ctrl4_vld_dbg_sel1_shift                               (20)
#define  LGCY_RIF_REG_dbg_ctrl4_vld_dbg_sel0_shift                               (16)
#define  LGCY_RIF_REG_dbg_ctrl4_arb_dbg_sel1_shift                               (12)
#define  LGCY_RIF_REG_dbg_ctrl4_arb_dbg_sel0_shift                               (8)
#define  LGCY_RIF_REG_dbg_ctrl4_vm1_dbg_sel1_shift                               (4)
#define  LGCY_RIF_REG_dbg_ctrl4_vm1_dbg_sel0_shift                               (0)
#define  LGCY_RIF_REG_dbg_ctrl4_rl_dbg_sel1_mask                                 (0xF0000000)
#define  LGCY_RIF_REG_dbg_ctrl4_rl_dbg_sel0_mask                                 (0x0F000000)
#define  LGCY_RIF_REG_dbg_ctrl4_vld_dbg_sel1_mask                                (0x00F00000)
#define  LGCY_RIF_REG_dbg_ctrl4_vld_dbg_sel0_mask                                (0x000F0000)
#define  LGCY_RIF_REG_dbg_ctrl4_arb_dbg_sel1_mask                                (0x0000F000)
#define  LGCY_RIF_REG_dbg_ctrl4_arb_dbg_sel0_mask                                (0x00000F00)
#define  LGCY_RIF_REG_dbg_ctrl4_vm1_dbg_sel1_mask                                (0x000000F0)
#define  LGCY_RIF_REG_dbg_ctrl4_vm1_dbg_sel0_mask                                (0x0000000F)
#define  LGCY_RIF_REG_dbg_ctrl4_rl_dbg_sel1(data)                                (0xF0000000&((data)<<28))
#define  LGCY_RIF_REG_dbg_ctrl4_rl_dbg_sel0(data)                                (0x0F000000&((data)<<24))
#define  LGCY_RIF_REG_dbg_ctrl4_vld_dbg_sel1(data)                               (0x00F00000&((data)<<20))
#define  LGCY_RIF_REG_dbg_ctrl4_vld_dbg_sel0(data)                               (0x000F0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_ctrl4_arb_dbg_sel1(data)                               (0x0000F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl4_arb_dbg_sel0(data)                               (0x00000F00&((data)<<8))
#define  LGCY_RIF_REG_dbg_ctrl4_vm1_dbg_sel1(data)                               (0x000000F0&((data)<<4))
#define  LGCY_RIF_REG_dbg_ctrl4_vm1_dbg_sel0(data)                               (0x0000000F&(data))
#define  LGCY_RIF_REG_dbg_ctrl4_get_rl_dbg_sel1(data)                            ((0xF0000000&(data))>>28)
#define  LGCY_RIF_REG_dbg_ctrl4_get_rl_dbg_sel0(data)                            ((0x0F000000&(data))>>24)
#define  LGCY_RIF_REG_dbg_ctrl4_get_vld_dbg_sel1(data)                           ((0x00F00000&(data))>>20)
#define  LGCY_RIF_REG_dbg_ctrl4_get_vld_dbg_sel0(data)                           ((0x000F0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_ctrl4_get_arb_dbg_sel1(data)                           ((0x0000F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl4_get_arb_dbg_sel0(data)                           ((0x00000F00&(data))>>8)
#define  LGCY_RIF_REG_dbg_ctrl4_get_vm1_dbg_sel1(data)                           ((0x000000F0&(data))>>4)
#define  LGCY_RIF_REG_dbg_ctrl4_get_vm1_dbg_sel0(data)                           (0x0000000F&(data))

#define  LGCY_RIF_REG_dbg_ctrl5                                                  0x1800E4F4
#define  LGCY_RIF_REG_dbg_ctrl5_reg_addr                                         "0xB800E4F4"
#define  LGCY_RIF_REG_dbg_ctrl5_reg                                              0xB800E4F4
#define  LGCY_RIF_REG_dbg_ctrl5_inst_addr                                        "0x0023"
#define  set_LGCY_RIF_REG_dbg_ctrl5_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl5_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl5_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl5_reg))
#define  LGCY_RIF_REG_dbg_ctrl5_deblk_dbg_sel1_shift                             (26)
#define  LGCY_RIF_REG_dbg_ctrl5_deblk_dbg_sel0_shift                             (20)
#define  LGCY_RIF_REG_dbg_ctrl5_mvd_dbg_sel1_shift                               (16)
#define  LGCY_RIF_REG_dbg_ctrl5_mvd_dbg_sel0_shift                               (12)
#define  LGCY_RIF_REG_dbg_ctrl5_prd_dbg_sel1_shift                               (6)
#define  LGCY_RIF_REG_dbg_ctrl5_prd_dbg_sel0_shift                               (0)
#define  LGCY_RIF_REG_dbg_ctrl5_deblk_dbg_sel1_mask                              (0xFC000000)
#define  LGCY_RIF_REG_dbg_ctrl5_deblk_dbg_sel0_mask                              (0x03F00000)
#define  LGCY_RIF_REG_dbg_ctrl5_mvd_dbg_sel1_mask                                (0x000F0000)
#define  LGCY_RIF_REG_dbg_ctrl5_mvd_dbg_sel0_mask                                (0x0000F000)
#define  LGCY_RIF_REG_dbg_ctrl5_prd_dbg_sel1_mask                                (0x00000FC0)
#define  LGCY_RIF_REG_dbg_ctrl5_prd_dbg_sel0_mask                                (0x0000003F)
#define  LGCY_RIF_REG_dbg_ctrl5_deblk_dbg_sel1(data)                             (0xFC000000&((data)<<26))
#define  LGCY_RIF_REG_dbg_ctrl5_deblk_dbg_sel0(data)                             (0x03F00000&((data)<<20))
#define  LGCY_RIF_REG_dbg_ctrl5_mvd_dbg_sel1(data)                               (0x000F0000&((data)<<16))
#define  LGCY_RIF_REG_dbg_ctrl5_mvd_dbg_sel0(data)                               (0x0000F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl5_prd_dbg_sel1(data)                               (0x00000FC0&((data)<<6))
#define  LGCY_RIF_REG_dbg_ctrl5_prd_dbg_sel0(data)                               (0x0000003F&(data))
#define  LGCY_RIF_REG_dbg_ctrl5_get_deblk_dbg_sel1(data)                         ((0xFC000000&(data))>>26)
#define  LGCY_RIF_REG_dbg_ctrl5_get_deblk_dbg_sel0(data)                         ((0x03F00000&(data))>>20)
#define  LGCY_RIF_REG_dbg_ctrl5_get_mvd_dbg_sel1(data)                           ((0x000F0000&(data))>>16)
#define  LGCY_RIF_REG_dbg_ctrl5_get_mvd_dbg_sel0(data)                           ((0x0000F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl5_get_prd_dbg_sel1(data)                           ((0x00000FC0&(data))>>6)
#define  LGCY_RIF_REG_dbg_ctrl5_get_prd_dbg_sel0(data)                           (0x0000003F&(data))

#define  LGCY_RIF_REG_fpga_dbg1                                                  0x1800E4F8
#define  LGCY_RIF_REG_fpga_dbg1_reg_addr                                         "0xB800E4F8"
#define  LGCY_RIF_REG_fpga_dbg1_reg                                              0xB800E4F8
#define  LGCY_RIF_REG_fpga_dbg1_inst_addr                                        "0x0024"
#define  set_LGCY_RIF_REG_fpga_dbg1_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_fpga_dbg1_reg)=data)
#define  get_LGCY_RIF_REG_fpga_dbg1_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_fpga_dbg1_reg))
#define  LGCY_RIF_REG_fpga_dbg1_dcmprs_busy_shift                                (28)
#define  LGCY_RIF_REG_fpga_dbg1_cmprs_busy_shift                                 (27)
#define  LGCY_RIF_REG_fpga_dbg1_seg_busy_shift                                   (26)
#define  LGCY_RIF_REG_fpga_dbg1_sao_busy_shift                                   (25)
#define  LGCY_RIF_REG_fpga_dbg1_vm2_busy_shift                                   (24)
#define  LGCY_RIF_REG_fpga_dbg1_vp8p2_busy_shift                                 (23)
#define  LGCY_RIF_REG_fpga_dbg1_ndbp2_busy_shift                                 (22)
#define  LGCY_RIF_REG_fpga_dbg1_ipmd_busy_shift                                  (21)
#define  LGCY_RIF_REG_fpga_dbg1_fme_busy_shift                                   (20)
#define  LGCY_RIF_REG_fpga_dbg1_vlc_busy_shift                                   (19)
#define  LGCY_RIF_REG_fpga_dbg1_gcoeff_busy_shift                                (18)
#define  LGCY_RIF_REG_fpga_dbg1_emd_busy_shift                                   (17)
#define  LGCY_RIF_REG_fpga_dbg1_imedma_busy_shift                                (16)
#define  LGCY_RIF_REG_fpga_dbg1_ime_busy_shift                                   (15)
#define  LGCY_RIF_REG_fpga_dbg1_cache_busy_shift                                 (14)
#define  LGCY_RIF_REG_fpga_dbg1_brg_busy_shift                                   (13)
#define  LGCY_RIF_REG_fpga_dbg1_ndb_busy_shift                                   (12)
#define  LGCY_RIF_REG_fpga_dbg1_bsfifo_busy_shift                                (11)
#define  LGCY_RIF_REG_fpga_dbg1_img_busy_shift                                   (10)
#define  LGCY_RIF_REG_fpga_dbg1_vm1_busy_shift                                   (9)
#define  LGCY_RIF_REG_fpga_dbg1_deblk_busy_shift                                 (8)
#define  LGCY_RIF_REG_fpga_dbg1_rl_busy_shift                                    (7)
#define  LGCY_RIF_REG_fpga_dbg1_pred_busy_shift                                  (6)
#define  LGCY_RIF_REG_fpga_dbg1_mvd_busy_shift                                   (5)
#define  LGCY_RIF_REG_fpga_dbg1_itblk_busy_shift                                 (4)
#define  LGCY_RIF_REG_fpga_dbg1_acdc_busy_shift                                  (3)
#define  LGCY_RIF_REG_fpga_dbg1_cabacp2_busy_shift                               (2)
#define  LGCY_RIF_REG_fpga_dbg1_vld_busy_shift                                   (1)
#define  LGCY_RIF_REG_fpga_dbg1_rifvld_busy_shift                                (0)
#define  LGCY_RIF_REG_fpga_dbg1_dcmprs_busy_mask                                 (0x10000000)
#define  LGCY_RIF_REG_fpga_dbg1_cmprs_busy_mask                                  (0x08000000)
#define  LGCY_RIF_REG_fpga_dbg1_seg_busy_mask                                    (0x04000000)
#define  LGCY_RIF_REG_fpga_dbg1_sao_busy_mask                                    (0x02000000)
#define  LGCY_RIF_REG_fpga_dbg1_vm2_busy_mask                                    (0x01000000)
#define  LGCY_RIF_REG_fpga_dbg1_vp8p2_busy_mask                                  (0x00800000)
#define  LGCY_RIF_REG_fpga_dbg1_ndbp2_busy_mask                                  (0x00400000)
#define  LGCY_RIF_REG_fpga_dbg1_ipmd_busy_mask                                   (0x00200000)
#define  LGCY_RIF_REG_fpga_dbg1_fme_busy_mask                                    (0x00100000)
#define  LGCY_RIF_REG_fpga_dbg1_vlc_busy_mask                                    (0x00080000)
#define  LGCY_RIF_REG_fpga_dbg1_gcoeff_busy_mask                                 (0x00040000)
#define  LGCY_RIF_REG_fpga_dbg1_emd_busy_mask                                    (0x00020000)
#define  LGCY_RIF_REG_fpga_dbg1_imedma_busy_mask                                 (0x00010000)
#define  LGCY_RIF_REG_fpga_dbg1_ime_busy_mask                                    (0x00008000)
#define  LGCY_RIF_REG_fpga_dbg1_cache_busy_mask                                  (0x00004000)
#define  LGCY_RIF_REG_fpga_dbg1_brg_busy_mask                                    (0x00002000)
#define  LGCY_RIF_REG_fpga_dbg1_ndb_busy_mask                                    (0x00001000)
#define  LGCY_RIF_REG_fpga_dbg1_bsfifo_busy_mask                                 (0x00000800)
#define  LGCY_RIF_REG_fpga_dbg1_img_busy_mask                                    (0x00000400)
#define  LGCY_RIF_REG_fpga_dbg1_vm1_busy_mask                                    (0x00000200)
#define  LGCY_RIF_REG_fpga_dbg1_deblk_busy_mask                                  (0x00000100)
#define  LGCY_RIF_REG_fpga_dbg1_rl_busy_mask                                     (0x00000080)
#define  LGCY_RIF_REG_fpga_dbg1_pred_busy_mask                                   (0x00000040)
#define  LGCY_RIF_REG_fpga_dbg1_mvd_busy_mask                                    (0x00000020)
#define  LGCY_RIF_REG_fpga_dbg1_itblk_busy_mask                                  (0x00000010)
#define  LGCY_RIF_REG_fpga_dbg1_acdc_busy_mask                                   (0x00000008)
#define  LGCY_RIF_REG_fpga_dbg1_cabacp2_busy_mask                                (0x00000004)
#define  LGCY_RIF_REG_fpga_dbg1_vld_busy_mask                                    (0x00000002)
#define  LGCY_RIF_REG_fpga_dbg1_rifvld_busy_mask                                 (0x00000001)
#define  LGCY_RIF_REG_fpga_dbg1_dcmprs_busy(data)                                (0x10000000&((data)<<28))
#define  LGCY_RIF_REG_fpga_dbg1_cmprs_busy(data)                                 (0x08000000&((data)<<27))
#define  LGCY_RIF_REG_fpga_dbg1_seg_busy(data)                                   (0x04000000&((data)<<26))
#define  LGCY_RIF_REG_fpga_dbg1_sao_busy(data)                                   (0x02000000&((data)<<25))
#define  LGCY_RIF_REG_fpga_dbg1_vm2_busy(data)                                   (0x01000000&((data)<<24))
#define  LGCY_RIF_REG_fpga_dbg1_vp8p2_busy(data)                                 (0x00800000&((data)<<23))
#define  LGCY_RIF_REG_fpga_dbg1_ndbp2_busy(data)                                 (0x00400000&((data)<<22))
#define  LGCY_RIF_REG_fpga_dbg1_ipmd_busy(data)                                  (0x00200000&((data)<<21))
#define  LGCY_RIF_REG_fpga_dbg1_fme_busy(data)                                   (0x00100000&((data)<<20))
#define  LGCY_RIF_REG_fpga_dbg1_vlc_busy(data)                                   (0x00080000&((data)<<19))
#define  LGCY_RIF_REG_fpga_dbg1_gcoeff_busy(data)                                (0x00040000&((data)<<18))
#define  LGCY_RIF_REG_fpga_dbg1_emd_busy(data)                                   (0x00020000&((data)<<17))
#define  LGCY_RIF_REG_fpga_dbg1_imedma_busy(data)                                (0x00010000&((data)<<16))
#define  LGCY_RIF_REG_fpga_dbg1_ime_busy(data)                                   (0x00008000&((data)<<15))
#define  LGCY_RIF_REG_fpga_dbg1_cache_busy(data)                                 (0x00004000&((data)<<14))
#define  LGCY_RIF_REG_fpga_dbg1_brg_busy(data)                                   (0x00002000&((data)<<13))
#define  LGCY_RIF_REG_fpga_dbg1_ndb_busy(data)                                   (0x00001000&((data)<<12))
#define  LGCY_RIF_REG_fpga_dbg1_bsfifo_busy(data)                                (0x00000800&((data)<<11))
#define  LGCY_RIF_REG_fpga_dbg1_img_busy(data)                                   (0x00000400&((data)<<10))
#define  LGCY_RIF_REG_fpga_dbg1_vm1_busy(data)                                   (0x00000200&((data)<<9))
#define  LGCY_RIF_REG_fpga_dbg1_deblk_busy(data)                                 (0x00000100&((data)<<8))
#define  LGCY_RIF_REG_fpga_dbg1_rl_busy(data)                                    (0x00000080&((data)<<7))
#define  LGCY_RIF_REG_fpga_dbg1_pred_busy(data)                                  (0x00000040&((data)<<6))
#define  LGCY_RIF_REG_fpga_dbg1_mvd_busy(data)                                   (0x00000020&((data)<<5))
#define  LGCY_RIF_REG_fpga_dbg1_itblk_busy(data)                                 (0x00000010&((data)<<4))
#define  LGCY_RIF_REG_fpga_dbg1_acdc_busy(data)                                  (0x00000008&((data)<<3))
#define  LGCY_RIF_REG_fpga_dbg1_cabacp2_busy(data)                               (0x00000004&((data)<<2))
#define  LGCY_RIF_REG_fpga_dbg1_vld_busy(data)                                   (0x00000002&((data)<<1))
#define  LGCY_RIF_REG_fpga_dbg1_rifvld_busy(data)                                (0x00000001&(data))
#define  LGCY_RIF_REG_fpga_dbg1_get_dcmprs_busy(data)                            ((0x10000000&(data))>>28)
#define  LGCY_RIF_REG_fpga_dbg1_get_cmprs_busy(data)                             ((0x08000000&(data))>>27)
#define  LGCY_RIF_REG_fpga_dbg1_get_seg_busy(data)                               ((0x04000000&(data))>>26)
#define  LGCY_RIF_REG_fpga_dbg1_get_sao_busy(data)                               ((0x02000000&(data))>>25)
#define  LGCY_RIF_REG_fpga_dbg1_get_vm2_busy(data)                               ((0x01000000&(data))>>24)
#define  LGCY_RIF_REG_fpga_dbg1_get_vp8p2_busy(data)                             ((0x00800000&(data))>>23)
#define  LGCY_RIF_REG_fpga_dbg1_get_ndbp2_busy(data)                             ((0x00400000&(data))>>22)
#define  LGCY_RIF_REG_fpga_dbg1_get_ipmd_busy(data)                              ((0x00200000&(data))>>21)
#define  LGCY_RIF_REG_fpga_dbg1_get_fme_busy(data)                               ((0x00100000&(data))>>20)
#define  LGCY_RIF_REG_fpga_dbg1_get_vlc_busy(data)                               ((0x00080000&(data))>>19)
#define  LGCY_RIF_REG_fpga_dbg1_get_gcoeff_busy(data)                            ((0x00040000&(data))>>18)
#define  LGCY_RIF_REG_fpga_dbg1_get_emd_busy(data)                               ((0x00020000&(data))>>17)
#define  LGCY_RIF_REG_fpga_dbg1_get_imedma_busy(data)                            ((0x00010000&(data))>>16)
#define  LGCY_RIF_REG_fpga_dbg1_get_ime_busy(data)                               ((0x00008000&(data))>>15)
#define  LGCY_RIF_REG_fpga_dbg1_get_cache_busy(data)                             ((0x00004000&(data))>>14)
#define  LGCY_RIF_REG_fpga_dbg1_get_brg_busy(data)                               ((0x00002000&(data))>>13)
#define  LGCY_RIF_REG_fpga_dbg1_get_ndb_busy(data)                               ((0x00001000&(data))>>12)
#define  LGCY_RIF_REG_fpga_dbg1_get_bsfifo_busy(data)                            ((0x00000800&(data))>>11)
#define  LGCY_RIF_REG_fpga_dbg1_get_img_busy(data)                               ((0x00000400&(data))>>10)
#define  LGCY_RIF_REG_fpga_dbg1_get_vm1_busy(data)                               ((0x00000200&(data))>>9)
#define  LGCY_RIF_REG_fpga_dbg1_get_deblk_busy(data)                             ((0x00000100&(data))>>8)
#define  LGCY_RIF_REG_fpga_dbg1_get_rl_busy(data)                                ((0x00000080&(data))>>7)
#define  LGCY_RIF_REG_fpga_dbg1_get_pred_busy(data)                              ((0x00000040&(data))>>6)
#define  LGCY_RIF_REG_fpga_dbg1_get_mvd_busy(data)                               ((0x00000020&(data))>>5)
#define  LGCY_RIF_REG_fpga_dbg1_get_itblk_busy(data)                             ((0x00000010&(data))>>4)
#define  LGCY_RIF_REG_fpga_dbg1_get_acdc_busy(data)                              ((0x00000008&(data))>>3)
#define  LGCY_RIF_REG_fpga_dbg1_get_cabacp2_busy(data)                           ((0x00000004&(data))>>2)
#define  LGCY_RIF_REG_fpga_dbg1_get_vld_busy(data)                               ((0x00000002&(data))>>1)
#define  LGCY_RIF_REG_fpga_dbg1_get_rifvld_busy(data)                            (0x00000001&(data))

#define  LGCY_RIF_REG_dbg_ctrl6                                                  0x1800E4FC
#define  LGCY_RIF_REG_dbg_ctrl6_reg_addr                                         "0xB800E4FC"
#define  LGCY_RIF_REG_dbg_ctrl6_reg                                              0xB800E4FC
#define  LGCY_RIF_REG_dbg_ctrl6_inst_addr                                        "0x0025"
#define  set_LGCY_RIF_REG_dbg_ctrl6_reg(data)                                    (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl6_reg)=data)
#define  get_LGCY_RIF_REG_dbg_ctrl6_reg                                          (*((volatile unsigned int*)LGCY_RIF_REG_dbg_ctrl6_reg))
#define  LGCY_RIF_REG_dbg_ctrl6_fme_dbg_sel1_shift                               (28)
#define  LGCY_RIF_REG_dbg_ctrl6_fme_dbg_sel0_shift                               (24)
#define  LGCY_RIF_REG_dbg_ctrl6_gc_dbg_sel1_shift                                (18)
#define  LGCY_RIF_REG_dbg_ctrl6_gc_dbg_sel0_shift                                (12)
#define  LGCY_RIF_REG_dbg_ctrl6_ip_dbg_sel1_shift                                (6)
#define  LGCY_RIF_REG_dbg_ctrl6_ip_dbg_sel0_shift                                (0)
#define  LGCY_RIF_REG_dbg_ctrl6_fme_dbg_sel1_mask                                (0xF0000000)
#define  LGCY_RIF_REG_dbg_ctrl6_fme_dbg_sel0_mask                                (0x0F000000)
#define  LGCY_RIF_REG_dbg_ctrl6_gc_dbg_sel1_mask                                 (0x00FC0000)
#define  LGCY_RIF_REG_dbg_ctrl6_gc_dbg_sel0_mask                                 (0x0003F000)
#define  LGCY_RIF_REG_dbg_ctrl6_ip_dbg_sel1_mask                                 (0x00000FC0)
#define  LGCY_RIF_REG_dbg_ctrl6_ip_dbg_sel0_mask                                 (0x0000003F)
#define  LGCY_RIF_REG_dbg_ctrl6_fme_dbg_sel1(data)                               (0xF0000000&((data)<<28))
#define  LGCY_RIF_REG_dbg_ctrl6_fme_dbg_sel0(data)                               (0x0F000000&((data)<<24))
#define  LGCY_RIF_REG_dbg_ctrl6_gc_dbg_sel1(data)                                (0x00FC0000&((data)<<18))
#define  LGCY_RIF_REG_dbg_ctrl6_gc_dbg_sel0(data)                                (0x0003F000&((data)<<12))
#define  LGCY_RIF_REG_dbg_ctrl6_ip_dbg_sel1(data)                                (0x00000FC0&((data)<<6))
#define  LGCY_RIF_REG_dbg_ctrl6_ip_dbg_sel0(data)                                (0x0000003F&(data))
#define  LGCY_RIF_REG_dbg_ctrl6_get_fme_dbg_sel1(data)                           ((0xF0000000&(data))>>28)
#define  LGCY_RIF_REG_dbg_ctrl6_get_fme_dbg_sel0(data)                           ((0x0F000000&(data))>>24)
#define  LGCY_RIF_REG_dbg_ctrl6_get_gc_dbg_sel1(data)                            ((0x00FC0000&(data))>>18)
#define  LGCY_RIF_REG_dbg_ctrl6_get_gc_dbg_sel0(data)                            ((0x0003F000&(data))>>12)
#define  LGCY_RIF_REG_dbg_ctrl6_get_ip_dbg_sel1(data)                            ((0x00000FC0&(data))>>6)
#define  LGCY_RIF_REG_dbg_ctrl6_get_ip_dbg_sel0(data)                            (0x0000003F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LGCY_RIF_REG register structure define==========

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
        RBus_UInt32  haltve_done:1;
        RBus_UInt32  haltve:1;
        RBus_UInt32  veidle:1;
        RBus_UInt32  inten:1;
        RBus_UInt32  reset_ptr:1;
    };
}lgcy_rif_reg_ve_ctrl_RBUS;

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
}lgcy_rif_reg_ve_int_status_RBUS;

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
}lgcy_rif_reg_ve_int_en_RBUS;

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
}lgcy_rif_reg_ve_fifostatus_RBUS;

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
}lgcy_rif_reg_ve_fifostat2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rslt_timer:24;
    };
}lgcy_rif_reg_ve_rslt_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cmd_timer:24;
    };
}lgcy_rif_reg_ve_cmd_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ime_inst_cnt:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  emd_inst_cnt:6;
    };
}lgcy_rif_reg_ve_fifostat3_RBUS;

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
}lgcy_rif_reg_vmbanksel_RBUS;

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
}lgcy_rif_reg_umbanksel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cmprs_head_remap:1;
        RBus_UInt32  mode32x1:1;
        RBus_UInt32  gpu_out_en:1;
        RBus_UInt32  dual_core_dmy_row_method:1;
        RBus_UInt32  comp_wrap_width:10;
        RBus_UInt32  compression_en:1;
        RBus_UInt32  multicoreenable:2;
        RBus_UInt32  corenum:2;
        RBus_UInt32  mode8x2_16b_align:1;
        RBus_UInt32  mode8x2:1;
        RBus_UInt32  monochrome:1;
        RBus_UInt32  level:1;
        RBus_UInt32  profile:2;
        RBus_UInt32  coding_type:5;
    };
}lgcy_rif_reg_dec_cntl_RBUS;

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
}lgcy_rif_reg_picinfo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  mode16x1:1;
        RBus_UInt32  constrainted_intra_pred_flag:1;
        RBus_UInt32  weighted_pred_flag:1;
        RBus_UInt32  weighted_bipred_idc:2;
        RBus_UInt32  frame_mbs_only_flag:1;
        RBus_UInt32  mb_adaptive_frame_field_flag:1;
    };
}lgcy_rif_reg_h264piccntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  overlap_enable:1;
        RBus_UInt32  field_pictype:3;
        RBus_UInt32  mvmode:2;
        RBus_UInt32  fcm:2;
        RBus_UInt32  disppic_h:12;
        RBus_UInt32  disppic_w:12;
    };
}lgcy_rif_reg_vc1piccntl_RBUS;

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
}lgcy_rif_reg_vc1piccntl2_RBUS;

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
}lgcy_rif_reg_brg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  vm2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  vm1:12;
    };
}lgcy_rif_reg_rd_priority0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  deblk:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  predblk:12;
    };
}lgcy_rif_reg_rd_priority1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nm:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  mvd:12;
    };
}lgcy_rif_reg_rd_priority2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  gcoeff:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  bs:12;
    };
}lgcy_rif_reg_rd_priority3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cmp:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  rl:12;
    };
}lgcy_rif_reg_rd_priority4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fme:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ime:12;
    };
}lgcy_rif_reg_rd_priority5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  vm2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  vm1:11;
    };
}lgcy_rif_reg_wt_priority0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  deblk:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  predblk:11;
    };
}lgcy_rif_reg_wt_priority1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  nm:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  mvd:11;
    };
}lgcy_rif_reg_wt_priority2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  gcoeff:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  bs:11;
    };
}lgcy_rif_reg_wt_priority3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cmp:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  it:11;
    };
}lgcy_rif_reg_wt_priority4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  fme:11;
    };
}lgcy_rif_reg_wt_priority5_RBUS;

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
}lgcy_rif_reg_clkgated_RBUS;

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
}lgcy_rif_reg_dbg_ctrl17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_dbg_out1:16;
        RBus_UInt32  ve_dbg_out0:16;
    };
}lgcy_rif_reg_dbg_out_RBUS;

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
}lgcy_rif_reg_dbg_ctrl1_RBUS;

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
}lgcy_rif_reg_dbg_ctrl2_RBUS;

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
}lgcy_rif_reg_dbg_ctrl3_RBUS;

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
}lgcy_rif_reg_dbg_ctrl4_RBUS;

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
}lgcy_rif_reg_dbg_ctrl5_RBUS;

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
}lgcy_rif_reg_fpga_dbg1_RBUS;

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
}lgcy_rif_reg_dbg_ctrl6_RBUS;

#else //apply LITTLE_ENDIAN

//======LGCY_RIF_REG register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reset_ptr:1;
        RBus_UInt32  inten:1;
        RBus_UInt32  veidle:1;
        RBus_UInt32  haltve:1;
        RBus_UInt32  haltve_done:1;
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
}lgcy_rif_reg_ve_ctrl_RBUS;

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
}lgcy_rif_reg_ve_int_status_RBUS;

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
}lgcy_rif_reg_ve_int_en_RBUS;

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
}lgcy_rif_reg_ve_fifostatus_RBUS;

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
}lgcy_rif_reg_ve_fifostat2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rslt_timer:24;
        RBus_UInt32  res1:8;
    };
}lgcy_rif_reg_ve_rslt_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cmd_timer:24;
        RBus_UInt32  res1:8;
    };
}lgcy_rif_reg_ve_cmd_timer_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emd_inst_cnt:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ime_inst_cnt:6;
        RBus_UInt32  res2:18;
    };
}lgcy_rif_reg_ve_fifostat3_RBUS;

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
}lgcy_rif_reg_vmbanksel_RBUS;

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
}lgcy_rif_reg_umbanksel_RBUS;

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
        RBus_UInt32  corenum:2;
        RBus_UInt32  multicoreenable:2;
        RBus_UInt32  compression_en:1;
        RBus_UInt32  comp_wrap_width:10;
        RBus_UInt32  dual_core_dmy_row_method:1;
        RBus_UInt32  gpu_out_en:1;
        RBus_UInt32  mode32x1:1;
        RBus_UInt32  cmprs_head_remap:1;
        RBus_UInt32  res1:2;
    };
}lgcy_rif_reg_dec_cntl_RBUS;

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
}lgcy_rif_reg_picinfo1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mb_adaptive_frame_field_flag:1;
        RBus_UInt32  frame_mbs_only_flag:1;
        RBus_UInt32  weighted_bipred_idc:2;
        RBus_UInt32  weighted_pred_flag:1;
        RBus_UInt32  constrainted_intra_pred_flag:1;
        RBus_UInt32  mode16x1:1;
        RBus_UInt32  res1:25;
    };
}lgcy_rif_reg_h264piccntl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  disppic_w:12;
        RBus_UInt32  disppic_h:12;
        RBus_UInt32  fcm:2;
        RBus_UInt32  mvmode:2;
        RBus_UInt32  field_pictype:3;
        RBus_UInt32  overlap_enable:1;
    };
}lgcy_rif_reg_vc1piccntl_RBUS;

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
}lgcy_rif_reg_vc1piccntl2_RBUS;

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
}lgcy_rif_reg_brg_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vm1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  vm2:12;
        RBus_UInt32  res2:4;
    };
}lgcy_rif_reg_rd_priority0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  predblk:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  deblk:12;
        RBus_UInt32  res2:4;
    };
}lgcy_rif_reg_rd_priority1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvd:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nm:12;
        RBus_UInt32  res2:4;
    };
}lgcy_rif_reg_rd_priority2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bs:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  gcoeff:12;
        RBus_UInt32  res2:4;
    };
}lgcy_rif_reg_rd_priority3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rl:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cmp:12;
        RBus_UInt32  res2:4;
    };
}lgcy_rif_reg_rd_priority4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ime:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  fme:12;
        RBus_UInt32  res2:4;
    };
}lgcy_rif_reg_rd_priority5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vm1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  vm2:11;
        RBus_UInt32  res2:5;
    };
}lgcy_rif_reg_wt_priority0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  predblk:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  deblk:11;
        RBus_UInt32  res2:5;
    };
}lgcy_rif_reg_wt_priority1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvd:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  nm:11;
        RBus_UInt32  res2:5;
    };
}lgcy_rif_reg_wt_priority2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bs:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  gcoeff:11;
        RBus_UInt32  res2:5;
    };
}lgcy_rif_reg_wt_priority3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  it:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  cmp:11;
        RBus_UInt32  res2:5;
    };
}lgcy_rif_reg_wt_priority4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fme:11;
        RBus_UInt32  res1:21;
    };
}lgcy_rif_reg_wt_priority5_RBUS;

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
}lgcy_rif_reg_clkgated_RBUS;

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
}lgcy_rif_reg_dbg_ctrl17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ve_dbg_out0:16;
        RBus_UInt32  ve_dbg_out1:16;
    };
}lgcy_rif_reg_dbg_out_RBUS;

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
}lgcy_rif_reg_dbg_ctrl1_RBUS;

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
}lgcy_rif_reg_dbg_ctrl2_RBUS;

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
}lgcy_rif_reg_dbg_ctrl3_RBUS;

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
}lgcy_rif_reg_dbg_ctrl4_RBUS;

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
}lgcy_rif_reg_dbg_ctrl5_RBUS;

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
}lgcy_rif_reg_fpga_dbg1_RBUS;

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
}lgcy_rif_reg_dbg_ctrl6_RBUS;




#endif 


#endif 
