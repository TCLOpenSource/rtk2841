/**
* @file Macarthur5-DesignSpec-MISC_UART
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MISC_UART_REG_H_
#define _RBUS_MISC_UART_REG_H_

#include "rbus_types.h"



//  MISC_UART Register Address
#define  MISC_UART_U1RBR_THR_DLL                                                 0x1801B100
#define  MISC_UART_U1RBR_THR_DLL_reg_addr                                        "0xB801B100"
#define  MISC_UART_U1RBR_THR_DLL_reg                                             0xB801B100
#define  MISC_UART_U1RBR_THR_DLL_inst_addr                                       "0x0000"
#define  set_MISC_UART_U1RBR_THR_DLL_reg(data)                                   (*((volatile unsigned int*)MISC_UART_U1RBR_THR_DLL_reg)=data)
#define  get_MISC_UART_U1RBR_THR_DLL_reg                                         (*((volatile unsigned int*)MISC_UART_U1RBR_THR_DLL_reg))
#define  MISC_UART_U1RBR_THR_DLL_dll_shift                                       (0)
#define  MISC_UART_U1RBR_THR_DLL_dll_mask                                        (0x000000FF)
#define  MISC_UART_U1RBR_THR_DLL_dll(data)                                       (0x000000FF&(data))
#define  MISC_UART_U1RBR_THR_DLL_get_dll(data)                                   (0x000000FF&(data))

#define  MISC_UART_U1IER_DLH                                                     0x1801B104
#define  MISC_UART_U1IER_DLH_reg_addr                                            "0xB801B104"
#define  MISC_UART_U1IER_DLH_reg                                                 0xB801B104
#define  MISC_UART_U1IER_DLH_inst_addr                                           "0x0001"
#define  set_MISC_UART_U1IER_DLH_reg(data)                                       (*((volatile unsigned int*)MISC_UART_U1IER_DLH_reg)=data)
#define  get_MISC_UART_U1IER_DLH_reg                                             (*((volatile unsigned int*)MISC_UART_U1IER_DLH_reg))
#define  MISC_UART_U1IER_DLH_dlh_shift                                           (0)
#define  MISC_UART_U1IER_DLH_dlh_mask                                            (0x000000FF)
#define  MISC_UART_U1IER_DLH_dlh(data)                                           (0x000000FF&(data))
#define  MISC_UART_U1IER_DLH_get_dlh(data)                                       (0x000000FF&(data))

#define  MISC_UART_U1IIR_FCR                                                     0x1801B108
#define  MISC_UART_U1IIR_FCR_reg_addr                                            "0xB801B108"
#define  MISC_UART_U1IIR_FCR_reg                                                 0xB801B108
#define  MISC_UART_U1IIR_FCR_inst_addr                                           "0x0002"
#define  set_MISC_UART_U1IIR_FCR_reg(data)                                       (*((volatile unsigned int*)MISC_UART_U1IIR_FCR_reg)=data)
#define  get_MISC_UART_U1IIR_FCR_reg                                             (*((volatile unsigned int*)MISC_UART_U1IIR_FCR_reg))
#define  MISC_UART_U1IIR_FCR_fifose_shift                                        (6)
#define  MISC_UART_U1IIR_FCR_iid_shift                                           (0)
#define  MISC_UART_U1IIR_FCR_fifose_mask                                         (0x000000C0)
#define  MISC_UART_U1IIR_FCR_iid_mask                                            (0x0000000F)
#define  MISC_UART_U1IIR_FCR_fifose(data)                                        (0x000000C0&((data)<<6))
#define  MISC_UART_U1IIR_FCR_iid(data)                                           (0x0000000F&(data))
#define  MISC_UART_U1IIR_FCR_get_fifose(data)                                    ((0x000000C0&(data))>>6)
#define  MISC_UART_U1IIR_FCR_get_iid(data)                                       (0x0000000F&(data))

#define  MISC_UART_U1LCR                                                         0x1801B10C
#define  MISC_UART_U1LCR_reg_addr                                                "0xB801B10C"
#define  MISC_UART_U1LCR_reg                                                     0xB801B10C
#define  MISC_UART_U1LCR_inst_addr                                               "0x0003"
#define  set_MISC_UART_U1LCR_reg(data)                                           (*((volatile unsigned int*)MISC_UART_U1LCR_reg)=data)
#define  get_MISC_UART_U1LCR_reg                                                 (*((volatile unsigned int*)MISC_UART_U1LCR_reg))
#define  MISC_UART_U1LCR_dlab_shift                                              (7)
#define  MISC_UART_U1LCR_brk_shift                                               (6)
#define  MISC_UART_U1LCR_eps_shift                                               (4)
#define  MISC_UART_U1LCR_pen_shift                                               (3)
#define  MISC_UART_U1LCR_stb_shift                                               (2)
#define  MISC_UART_U1LCR_wls_shift                                               (0)
#define  MISC_UART_U1LCR_dlab_mask                                               (0x00000080)
#define  MISC_UART_U1LCR_brk_mask                                                (0x00000040)
#define  MISC_UART_U1LCR_eps_mask                                                (0x00000030)
#define  MISC_UART_U1LCR_pen_mask                                                (0x00000008)
#define  MISC_UART_U1LCR_stb_mask                                                (0x00000004)
#define  MISC_UART_U1LCR_wls_mask                                                (0x00000003)
#define  MISC_UART_U1LCR_dlab(data)                                              (0x00000080&((data)<<7))
#define  MISC_UART_U1LCR_brk(data)                                               (0x00000040&((data)<<6))
#define  MISC_UART_U1LCR_eps(data)                                               (0x00000030&((data)<<4))
#define  MISC_UART_U1LCR_pen(data)                                               (0x00000008&((data)<<3))
#define  MISC_UART_U1LCR_stb(data)                                               (0x00000004&((data)<<2))
#define  MISC_UART_U1LCR_wls(data)                                               (0x00000003&(data))
#define  MISC_UART_U1LCR_get_dlab(data)                                          ((0x00000080&(data))>>7)
#define  MISC_UART_U1LCR_get_brk(data)                                           ((0x00000040&(data))>>6)
#define  MISC_UART_U1LCR_get_eps(data)                                           ((0x00000030&(data))>>4)
#define  MISC_UART_U1LCR_get_pen(data)                                           ((0x00000008&(data))>>3)
#define  MISC_UART_U1LCR_get_stb(data)                                           ((0x00000004&(data))>>2)
#define  MISC_UART_U1LCR_get_wls(data)                                           (0x00000003&(data))

#define  MISC_UART_U1MCR                                                         0x1801B110
#define  MISC_UART_U1MCR_reg_addr                                                "0xB801B110"
#define  MISC_UART_U1MCR_reg                                                     0xB801B110
#define  MISC_UART_U1MCR_inst_addr                                               "0x0004"
#define  set_MISC_UART_U1MCR_reg(data)                                           (*((volatile unsigned int*)MISC_UART_U1MCR_reg)=data)
#define  get_MISC_UART_U1MCR_reg                                                 (*((volatile unsigned int*)MISC_UART_U1MCR_reg))
#define  MISC_UART_U1MCR_loop_shift                                              (4)
#define  MISC_UART_U1MCR_rts_shift                                               (1)
#define  MISC_UART_U1MCR_dtr_shift                                               (0)
#define  MISC_UART_U1MCR_loop_mask                                               (0x00000010)
#define  MISC_UART_U1MCR_rts_mask                                                (0x00000002)
#define  MISC_UART_U1MCR_dtr_mask                                                (0x00000001)
#define  MISC_UART_U1MCR_loop(data)                                              (0x00000010&((data)<<4))
#define  MISC_UART_U1MCR_rts(data)                                               (0x00000002&((data)<<1))
#define  MISC_UART_U1MCR_dtr(data)                                               (0x00000001&(data))
#define  MISC_UART_U1MCR_get_loop(data)                                          ((0x00000010&(data))>>4)
#define  MISC_UART_U1MCR_get_rts(data)                                           ((0x00000002&(data))>>1)
#define  MISC_UART_U1MCR_get_dtr(data)                                           (0x00000001&(data))

#define  MISC_UART_U1LSR                                                         0x1801B114
#define  MISC_UART_U1LSR_reg_addr                                                "0xB801B114"
#define  MISC_UART_U1LSR_reg                                                     0xB801B114
#define  MISC_UART_U1LSR_inst_addr                                               "0x0005"
#define  set_MISC_UART_U1LSR_reg(data)                                           (*((volatile unsigned int*)MISC_UART_U1LSR_reg)=data)
#define  get_MISC_UART_U1LSR_reg                                                 (*((volatile unsigned int*)MISC_UART_U1LSR_reg))
#define  MISC_UART_U1LSR_rfe_shift                                               (7)
#define  MISC_UART_U1LSR_temt_shift                                              (6)
#define  MISC_UART_U1LSR_thre_shift                                              (5)
#define  MISC_UART_U1LSR_bi_shift                                                (4)
#define  MISC_UART_U1LSR_fe_shift                                                (3)
#define  MISC_UART_U1LSR_pe_shift                                                (2)
#define  MISC_UART_U1LSR_oe_shift                                                (1)
#define  MISC_UART_U1LSR_dr_shift                                                (0)
#define  MISC_UART_U1LSR_rfe_mask                                                (0x00000080)
#define  MISC_UART_U1LSR_temt_mask                                               (0x00000040)
#define  MISC_UART_U1LSR_thre_mask                                               (0x00000020)
#define  MISC_UART_U1LSR_bi_mask                                                 (0x00000010)
#define  MISC_UART_U1LSR_fe_mask                                                 (0x00000008)
#define  MISC_UART_U1LSR_pe_mask                                                 (0x00000004)
#define  MISC_UART_U1LSR_oe_mask                                                 (0x00000002)
#define  MISC_UART_U1LSR_dr_mask                                                 (0x00000001)
#define  MISC_UART_U1LSR_rfe(data)                                               (0x00000080&((data)<<7))
#define  MISC_UART_U1LSR_temt(data)                                              (0x00000040&((data)<<6))
#define  MISC_UART_U1LSR_thre(data)                                              (0x00000020&((data)<<5))
#define  MISC_UART_U1LSR_bi(data)                                                (0x00000010&((data)<<4))
#define  MISC_UART_U1LSR_fe(data)                                                (0x00000008&((data)<<3))
#define  MISC_UART_U1LSR_pe(data)                                                (0x00000004&((data)<<2))
#define  MISC_UART_U1LSR_oe(data)                                                (0x00000002&((data)<<1))
#define  MISC_UART_U1LSR_dr(data)                                                (0x00000001&(data))
#define  MISC_UART_U1LSR_get_rfe(data)                                           ((0x00000080&(data))>>7)
#define  MISC_UART_U1LSR_get_temt(data)                                          ((0x00000040&(data))>>6)
#define  MISC_UART_U1LSR_get_thre(data)                                          ((0x00000020&(data))>>5)
#define  MISC_UART_U1LSR_get_bi(data)                                            ((0x00000010&(data))>>4)
#define  MISC_UART_U1LSR_get_fe(data)                                            ((0x00000008&(data))>>3)
#define  MISC_UART_U1LSR_get_pe(data)                                            ((0x00000004&(data))>>2)
#define  MISC_UART_U1LSR_get_oe(data)                                            ((0x00000002&(data))>>1)
#define  MISC_UART_U1LSR_get_dr(data)                                            (0x00000001&(data))

#define  MISC_UART_U1MSR                                                         0x1801B118
#define  MISC_UART_U1MSR_reg_addr                                                "0xB801B118"
#define  MISC_UART_U1MSR_reg                                                     0xB801B118
#define  MISC_UART_U1MSR_inst_addr                                               "0x0006"
#define  set_MISC_UART_U1MSR_reg(data)                                           (*((volatile unsigned int*)MISC_UART_U1MSR_reg)=data)
#define  get_MISC_UART_U1MSR_reg                                                 (*((volatile unsigned int*)MISC_UART_U1MSR_reg))
#define  MISC_UART_U1MSR_dcd_shift                                               (7)
#define  MISC_UART_U1MSR_ri_shift                                                (6)
#define  MISC_UART_U1MSR_dsr_shift                                               (5)
#define  MISC_UART_U1MSR_cts_shift                                               (4)
#define  MISC_UART_U1MSR_ddcd_shift                                              (3)
#define  MISC_UART_U1MSR_teri_shift                                              (2)
#define  MISC_UART_U1MSR_ddsr_shift                                              (1)
#define  MISC_UART_U1MSR_dcts_shift                                              (0)
#define  MISC_UART_U1MSR_dcd_mask                                                (0x00000080)
#define  MISC_UART_U1MSR_ri_mask                                                 (0x00000040)
#define  MISC_UART_U1MSR_dsr_mask                                                (0x00000020)
#define  MISC_UART_U1MSR_cts_mask                                                (0x00000010)
#define  MISC_UART_U1MSR_ddcd_mask                                               (0x00000008)
#define  MISC_UART_U1MSR_teri_mask                                               (0x00000004)
#define  MISC_UART_U1MSR_ddsr_mask                                               (0x00000002)
#define  MISC_UART_U1MSR_dcts_mask                                               (0x00000001)
#define  MISC_UART_U1MSR_dcd(data)                                               (0x00000080&((data)<<7))
#define  MISC_UART_U1MSR_ri(data)                                                (0x00000040&((data)<<6))
#define  MISC_UART_U1MSR_dsr(data)                                               (0x00000020&((data)<<5))
#define  MISC_UART_U1MSR_cts(data)                                               (0x00000010&((data)<<4))
#define  MISC_UART_U1MSR_ddcd(data)                                              (0x00000008&((data)<<3))
#define  MISC_UART_U1MSR_teri(data)                                              (0x00000004&((data)<<2))
#define  MISC_UART_U1MSR_ddsr(data)                                              (0x00000002&((data)<<1))
#define  MISC_UART_U1MSR_dcts(data)                                              (0x00000001&(data))
#define  MISC_UART_U1MSR_get_dcd(data)                                           ((0x00000080&(data))>>7)
#define  MISC_UART_U1MSR_get_ri(data)                                            ((0x00000040&(data))>>6)
#define  MISC_UART_U1MSR_get_dsr(data)                                           ((0x00000020&(data))>>5)
#define  MISC_UART_U1MSR_get_cts(data)                                           ((0x00000010&(data))>>4)
#define  MISC_UART_U1MSR_get_ddcd(data)                                          ((0x00000008&(data))>>3)
#define  MISC_UART_U1MSR_get_teri(data)                                          ((0x00000004&(data))>>2)
#define  MISC_UART_U1MSR_get_ddsr(data)                                          ((0x00000002&(data))>>1)
#define  MISC_UART_U1MSR_get_dcts(data)                                          (0x00000001&(data))

#define  MISC_UART_U1SCR                                                         0x1801B11C
#define  MISC_UART_U1SCR_reg_addr                                                "0xB801B11C"
#define  MISC_UART_U1SCR_reg                                                     0xB801B11C
#define  MISC_UART_U1SCR_inst_addr                                               "0x0007"
#define  set_MISC_UART_U1SCR_reg(data)                                           (*((volatile unsigned int*)MISC_UART_U1SCR_reg)=data)
#define  get_MISC_UART_U1SCR_reg                                                 (*((volatile unsigned int*)MISC_UART_U1SCR_reg))
#define  MISC_UART_U1SCR_scr_shift                                               (0)
#define  MISC_UART_U1SCR_scr_mask                                                (0x000000FF)
#define  MISC_UART_U1SCR_scr(data)                                               (0x000000FF&(data))
#define  MISC_UART_U1SCR_get_scr(data)                                           (0x000000FF&(data))

#define  MISC_UART_UR1_CTRL                                                      0x18039200
#define  MISC_UART_UR1_CTRL_reg_addr                                             "0xB8039200"
#define  MISC_UART_UR1_CTRL_reg                                                  0xB8039200
#define  MISC_UART_UR1_CTRL_inst_addr                                            "0x0008"
#define  set_MISC_UART_UR1_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_UART_UR1_CTRL_reg)=data)
#define  get_MISC_UART_UR1_CTRL_reg                                              (*((volatile unsigned int*)MISC_UART_UR1_CTRL_reg))
#define  MISC_UART_UR1_CTRL_dmaifen_shift                                        (6)
#define  MISC_UART_UR1_CTRL_txempthr_shift                                       (0)
#define  MISC_UART_UR1_CTRL_dmaifen_mask                                         (0x00000040)
#define  MISC_UART_UR1_CTRL_txempthr_mask                                        (0x0000003F)
#define  MISC_UART_UR1_CTRL_dmaifen(data)                                        (0x00000040&((data)<<6))
#define  MISC_UART_UR1_CTRL_txempthr(data)                                       (0x0000003F&(data))
#define  MISC_UART_UR1_CTRL_get_dmaifen(data)                                    ((0x00000040&(data))>>6)
#define  MISC_UART_UR1_CTRL_get_txempthr(data)                                   (0x0000003F&(data))

#define  MISC_UART_UR1_STS                                                       0x18039204
#define  MISC_UART_UR1_STS_reg_addr                                              "0xB8039204"
#define  MISC_UART_UR1_STS_reg                                                   0xB8039204
#define  MISC_UART_UR1_STS_inst_addr                                             "0x0009"
#define  set_MISC_UART_UR1_STS_reg(data)                                         (*((volatile unsigned int*)MISC_UART_UR1_STS_reg)=data)
#define  get_MISC_UART_UR1_STS_reg                                               (*((volatile unsigned int*)MISC_UART_UR1_STS_reg))
#define  MISC_UART_UR1_STS_tx_wrd_count_shift                                    (0)
#define  MISC_UART_UR1_STS_tx_wrd_count_mask                                     (0x0000001F)
#define  MISC_UART_UR1_STS_tx_wrd_count(data)                                    (0x0000001F&(data))
#define  MISC_UART_UR1_STS_get_tx_wrd_count(data)                                (0x0000001F&(data))

#define  MISC_UART_DMA_INT                                                       0x18039208
#define  MISC_UART_DMA_INT_reg_addr                                              "0xB8039208"
#define  MISC_UART_DMA_INT_reg                                                   0xB8039208
#define  MISC_UART_DMA_INT_inst_addr                                             "0x000A"
#define  set_MISC_UART_DMA_INT_reg(data)                                         (*((volatile unsigned int*)MISC_UART_DMA_INT_reg)=data)
#define  get_MISC_UART_DMA_INT_reg                                               (*((volatile unsigned int*)MISC_UART_DMA_INT_reg))
#define  MISC_UART_DMA_INT_ur_length_err_shift                                   (2)
#define  MISC_UART_DMA_INT_ur_tx_thd_shift                                       (1)
#define  MISC_UART_DMA_INT_write_data_shift                                      (0)
#define  MISC_UART_DMA_INT_ur_length_err_mask                                    (0x00000004)
#define  MISC_UART_DMA_INT_ur_tx_thd_mask                                        (0x00000002)
#define  MISC_UART_DMA_INT_write_data_mask                                       (0x00000001)
#define  MISC_UART_DMA_INT_ur_length_err(data)                                   (0x00000004&((data)<<2))
#define  MISC_UART_DMA_INT_ur_tx_thd(data)                                       (0x00000002&((data)<<1))
#define  MISC_UART_DMA_INT_write_data(data)                                      (0x00000001&(data))
#define  MISC_UART_DMA_INT_get_ur_length_err(data)                               ((0x00000004&(data))>>2)
#define  MISC_UART_DMA_INT_get_ur_tx_thd(data)                                   ((0x00000002&(data))>>1)
#define  MISC_UART_DMA_INT_get_write_data(data)                                  (0x00000001&(data))

#define  MISC_UART_DMA_INT_EN                                                    0x1803920C
#define  MISC_UART_DMA_INT_EN_reg_addr                                           "0xB803920C"
#define  MISC_UART_DMA_INT_EN_reg                                                0xB803920C
#define  MISC_UART_DMA_INT_EN_inst_addr                                          "0x000B"
#define  set_MISC_UART_DMA_INT_EN_reg(data)                                      (*((volatile unsigned int*)MISC_UART_DMA_INT_EN_reg)=data)
#define  get_MISC_UART_DMA_INT_EN_reg                                            (*((volatile unsigned int*)MISC_UART_DMA_INT_EN_reg))
#define  MISC_UART_DMA_INT_EN_ur_length_err_en_shift                             (1)
#define  MISC_UART_DMA_INT_EN_ur_tx_thd_en_shift                                 (0)
#define  MISC_UART_DMA_INT_EN_ur_length_err_en_mask                              (0x00000002)
#define  MISC_UART_DMA_INT_EN_ur_tx_thd_en_mask                                  (0x00000001)
#define  MISC_UART_DMA_INT_EN_ur_length_err_en(data)                             (0x00000002&((data)<<1))
#define  MISC_UART_DMA_INT_EN_ur_tx_thd_en(data)                                 (0x00000001&(data))
#define  MISC_UART_DMA_INT_EN_get_ur_length_err_en(data)                         ((0x00000002&(data))>>1)
#define  MISC_UART_DMA_INT_EN_get_ur_tx_thd_en(data)                             (0x00000001&(data))

#define  MISC_UART_DMA_TXBASE                                                    0x18039210
#define  MISC_UART_DMA_TXBASE_reg_addr                                           "0xB8039210"
#define  MISC_UART_DMA_TXBASE_reg                                                0xB8039210
#define  MISC_UART_DMA_TXBASE_inst_addr                                          "0x000C"
#define  set_MISC_UART_DMA_TXBASE_reg(data)                                      (*((volatile unsigned int*)MISC_UART_DMA_TXBASE_reg)=data)
#define  get_MISC_UART_DMA_TXBASE_reg                                            (*((volatile unsigned int*)MISC_UART_DMA_TXBASE_reg))
#define  MISC_UART_DMA_TXBASE_tx_base_shift                                      (3)
#define  MISC_UART_DMA_TXBASE_tx_base_mask                                       (0x7FFFFFF8)
#define  MISC_UART_DMA_TXBASE_tx_base(data)                                      (0x7FFFFFF8&((data)<<3))
#define  MISC_UART_DMA_TXBASE_get_tx_base(data)                                  ((0x7FFFFFF8&(data))>>3)

#define  MISC_UART_DMA_TXLIMIT                                                   0x18039214
#define  MISC_UART_DMA_TXLIMIT_reg_addr                                          "0xB8039214"
#define  MISC_UART_DMA_TXLIMIT_reg                                               0xB8039214
#define  MISC_UART_DMA_TXLIMIT_inst_addr                                         "0x000D"
#define  set_MISC_UART_DMA_TXLIMIT_reg(data)                                     (*((volatile unsigned int*)MISC_UART_DMA_TXLIMIT_reg)=data)
#define  get_MISC_UART_DMA_TXLIMIT_reg                                           (*((volatile unsigned int*)MISC_UART_DMA_TXLIMIT_reg))
#define  MISC_UART_DMA_TXLIMIT_tx_limit_shift                                    (3)
#define  MISC_UART_DMA_TXLIMIT_tx_limit_mask                                     (0x7FFFFFF8)
#define  MISC_UART_DMA_TXLIMIT_tx_limit(data)                                    (0x7FFFFFF8&((data)<<3))
#define  MISC_UART_DMA_TXLIMIT_get_tx_limit(data)                                ((0x7FFFFFF8&(data))>>3)

#define  MISC_UART_DMA_TXWRPTR                                                   0x18039218
#define  MISC_UART_DMA_TXWRPTR_reg_addr                                          "0xB8039218"
#define  MISC_UART_DMA_TXWRPTR_reg                                               0xB8039218
#define  MISC_UART_DMA_TXWRPTR_inst_addr                                         "0x000E"
#define  set_MISC_UART_DMA_TXWRPTR_reg(data)                                     (*((volatile unsigned int*)MISC_UART_DMA_TXWRPTR_reg)=data)
#define  get_MISC_UART_DMA_TXWRPTR_reg                                           (*((volatile unsigned int*)MISC_UART_DMA_TXWRPTR_reg))
#define  MISC_UART_DMA_TXWRPTR_tx_wrptr_shift                                    (0)
#define  MISC_UART_DMA_TXWRPTR_tx_wrptr_mask                                     (0x7FFFFFFF)
#define  MISC_UART_DMA_TXWRPTR_tx_wrptr(data)                                    (0x7FFFFFFF&(data))
#define  MISC_UART_DMA_TXWRPTR_get_tx_wrptr(data)                                (0x7FFFFFFF&(data))

#define  MISC_UART_DMA_TXRDPTR                                                   0x1803921C
#define  MISC_UART_DMA_TXRDPTR_reg_addr                                          "0xB803921C"
#define  MISC_UART_DMA_TXRDPTR_reg                                               0xB803921C
#define  MISC_UART_DMA_TXRDPTR_inst_addr                                         "0x000F"
#define  set_MISC_UART_DMA_TXRDPTR_reg(data)                                     (*((volatile unsigned int*)MISC_UART_DMA_TXRDPTR_reg)=data)
#define  get_MISC_UART_DMA_TXRDPTR_reg                                           (*((volatile unsigned int*)MISC_UART_DMA_TXRDPTR_reg))
#define  MISC_UART_DMA_TXRDPTR_tx_rdptr_shift                                    (0)
#define  MISC_UART_DMA_TXRDPTR_tx_rdptr_mask                                     (0x7FFFFFFF)
#define  MISC_UART_DMA_TXRDPTR_tx_rdptr(data)                                    (0x7FFFFFFF&(data))
#define  MISC_UART_DMA_TXRDPTR_get_tx_rdptr(data)                                (0x7FFFFFFF&(data))

#define  MISC_UART_DMA_TXTHD                                                     0x18039220
#define  MISC_UART_DMA_TXTHD_reg_addr                                            "0xB8039220"
#define  MISC_UART_DMA_TXTHD_reg                                                 0xB8039220
#define  MISC_UART_DMA_TXTHD_inst_addr                                           "0x0010"
#define  set_MISC_UART_DMA_TXTHD_reg(data)                                       (*((volatile unsigned int*)MISC_UART_DMA_TXTHD_reg)=data)
#define  get_MISC_UART_DMA_TXTHD_reg                                             (*((volatile unsigned int*)MISC_UART_DMA_TXTHD_reg))
#define  MISC_UART_DMA_TXTHD_tx_thd_shift                                        (0)
#define  MISC_UART_DMA_TXTHD_tx_thd_mask                                         (0xFFFFFFFF)
#define  MISC_UART_DMA_TXTHD_tx_thd(data)                                        (0xFFFFFFFF&(data))
#define  MISC_UART_DMA_TXTHD_get_tx_thd(data)                                    (0xFFFFFFFF&(data))

#define  MISC_UART_DMA_CTRL                                                      0x18039224
#define  MISC_UART_DMA_CTRL_reg_addr                                             "0xB8039224"
#define  MISC_UART_DMA_CTRL_reg                                                  0xB8039224
#define  MISC_UART_DMA_CTRL_inst_addr                                            "0x0011"
#define  set_MISC_UART_DMA_CTRL_reg(data)                                        (*((volatile unsigned int*)MISC_UART_DMA_CTRL_reg)=data)
#define  get_MISC_UART_DMA_CTRL_reg                                              (*((volatile unsigned int*)MISC_UART_DMA_CTRL_reg))
#define  MISC_UART_DMA_CTRL_gating_en_shift                                      (0)
#define  MISC_UART_DMA_CTRL_gating_en_mask                                       (0x00000001)
#define  MISC_UART_DMA_CTRL_gating_en(data)                                      (0x00000001&(data))
#define  MISC_UART_DMA_CTRL_get_gating_en(data)                                  (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MISC_UART register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dll:8;
    };
}misc_uart_u1rbr_thr_dll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dlh:8;
    };
}misc_uart_u1ier_dlh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  fifose:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  iid:4;
    };
}misc_uart_u1iir_fcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dlab:1;
        RBus_UInt32  brk:1;
        RBus_UInt32  eps:2;
        RBus_UInt32  pen:1;
        RBus_UInt32  stb:1;
        RBus_UInt32  wls:2;
    };
}misc_uart_u1lcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  loop:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  rts:1;
        RBus_UInt32  dtr:1;
    };
}misc_uart_u1mcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  rfe:1;
        RBus_UInt32  temt:1;
        RBus_UInt32  thre:1;
        RBus_UInt32  bi:1;
        RBus_UInt32  fe:1;
        RBus_UInt32  pe:1;
        RBus_UInt32  oe:1;
        RBus_UInt32  dr:1;
    };
}misc_uart_u1lsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dcd:1;
        RBus_UInt32  ri:1;
        RBus_UInt32  dsr:1;
        RBus_UInt32  cts:1;
        RBus_UInt32  ddcd:1;
        RBus_UInt32  teri:1;
        RBus_UInt32  ddsr:1;
        RBus_UInt32  dcts:1;
    };
}misc_uart_u1msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  scr:8;
    };
}misc_uart_u1scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dmaifen:1;
        RBus_UInt32  txempthr:6;
    };
}misc_uart_ur1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  tx_wrd_count:5;
    };
}misc_uart_ur1_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ur_length_err:1;
        RBus_UInt32  ur_tx_thd:1;
        RBus_UInt32  write_data:1;
    };
}misc_uart_dma_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  ur_length_err_en:1;
        RBus_UInt32  ur_tx_thd_en:1;
    };
}misc_uart_dma_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  tx_base:28;
        RBus_UInt32  res2:3;
    };
}misc_uart_dma_txbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  tx_limit:28;
        RBus_UInt32  res2:3;
    };
}misc_uart_dma_txlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  tx_wrptr:31;
    };
}misc_uart_dma_txwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  tx_rdptr:31;
    };
}misc_uart_dma_txrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_thd:32;
    };
}misc_uart_dma_txthd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  gating_en:1;
    };
}misc_uart_dma_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MISC_UART register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dll:8;
        RBus_UInt32  res1:24;
    };
}misc_uart_u1rbr_thr_dll_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlh:8;
        RBus_UInt32  res1:24;
    };
}misc_uart_u1ier_dlh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  iid:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  fifose:2;
        RBus_UInt32  res2:24;
    };
}misc_uart_u1iir_fcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wls:2;
        RBus_UInt32  stb:1;
        RBus_UInt32  pen:1;
        RBus_UInt32  eps:2;
        RBus_UInt32  brk:1;
        RBus_UInt32  dlab:1;
        RBus_UInt32  res1:24;
    };
}misc_uart_u1lcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dtr:1;
        RBus_UInt32  rts:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  loop:1;
        RBus_UInt32  res2:27;
    };
}misc_uart_u1mcr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dr:1;
        RBus_UInt32  oe:1;
        RBus_UInt32  pe:1;
        RBus_UInt32  fe:1;
        RBus_UInt32  bi:1;
        RBus_UInt32  thre:1;
        RBus_UInt32  temt:1;
        RBus_UInt32  rfe:1;
        RBus_UInt32  res1:24;
    };
}misc_uart_u1lsr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcts:1;
        RBus_UInt32  ddsr:1;
        RBus_UInt32  teri:1;
        RBus_UInt32  ddcd:1;
        RBus_UInt32  cts:1;
        RBus_UInt32  dsr:1;
        RBus_UInt32  ri:1;
        RBus_UInt32  dcd:1;
        RBus_UInt32  res1:24;
    };
}misc_uart_u1msr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scr:8;
        RBus_UInt32  res1:24;
    };
}misc_uart_u1scr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  txempthr:6;
        RBus_UInt32  dmaifen:1;
        RBus_UInt32  res1:25;
    };
}misc_uart_ur1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_wrd_count:5;
        RBus_UInt32  res1:27;
    };
}misc_uart_ur1_sts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  ur_tx_thd:1;
        RBus_UInt32  ur_length_err:1;
        RBus_UInt32  res1:29;
    };
}misc_uart_dma_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ur_tx_thd_en:1;
        RBus_UInt32  ur_length_err_en:1;
        RBus_UInt32  res1:30;
    };
}misc_uart_dma_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tx_base:28;
        RBus_UInt32  res2:1;
    };
}misc_uart_dma_txbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  tx_limit:28;
        RBus_UInt32  res2:1;
    };
}misc_uart_dma_txlimit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_wrptr:31;
        RBus_UInt32  res1:1;
    };
}misc_uart_dma_txwrptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_rdptr:31;
        RBus_UInt32  res1:1;
    };
}misc_uart_dma_txrdptr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tx_thd:32;
    };
}misc_uart_dma_txthd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gating_en:1;
        RBus_UInt32  res1:31;
    };
}misc_uart_dma_ctrl_RBUS;




#endif 


#endif 
